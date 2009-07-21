

# This script coalesces segment and segment_summary table at LHO and LLO segment database machine
# At LHO, this script only coalesces H1, H2 segments
# At LLO, this script only coalesces L1 segments

import sys
import os
import time
import socket
#import ConfigParser


try:
  import DB2
except:
  pass

try:
  from glue import gpstime
  from glue import segments
except ImportError:
  e = "Error, unable to import modules from glue. Check that glue is correctly installed and in your PYTHONPATH."
  raise ImportError, e

#================================================================================
__author__ = "Ping Wei <piwei@physics.syr.edu>"
__date__ = "$Date$"[7:-2]
__version__ ="$Revision$"[11:-2]
__src__ = "$Source$"
#================================================================================



#================================================================================
#
#                                    Main
#
#================================================================================
def coalesce_seg(database, start_time, end_time):
  ret = 0

  try:
    st = int(start_time)
    et = int(end_time)
    db = str(database.strip())
    #-------------------------------------------------------------------
    # Set up environment and get needed values
    #-------------------------------------------------------------------
    # Set up connection to the database
    try:
       dbconn = DB2.connect(dsn=db, uid='', pwd='', autoCommit=True)
       curs = dbconn.cursor()
    except Exception, e:
       ret = str(e)
   

    # create a new process_id
    sql = "select hex(GENERATE_UNIQUE()) from sysibm.sysdummy1"
    curs.execute(sql)
    hex_procid = curs.fetchone()[0]
    process_id = 'x' + '\'' + hex_procid + '\''

    # determine the local creator_db
    sql = "SELECT DEFAULT FROM SYSCAT.COLUMNS WHERE "
    sql += "TABNAME = 'PROCESS' AND COLNAME = 'CREATOR_DB'"
    curs.execute(sql)
    creator_db = int(curs.fetchone()[0])


    # get current_time for later use
    current_time = gpstime.GpsSecondsFromPyUTC(time.time())

  
    # prepare values for the new row to be inserted into the process table
    program = sys.argv[0].replace('./','')
    node = socket.gethostname()
    username = os.getlogin()
    unix_procid = os.getpid()
    proc_start_time = current_time
    end_time = None
    jobid = 0
    domain = 'coalesce_local'


    # insert new row into process table
    sql = "INSERT INTO process "
    sql += "(program, is_online, node, username, unix_procid, start_time, jobid, domain, process_id, creator_db) "
    sql += "VALUES ('%s', 0, '%s', '%s', %d, %d, %d, '%s',%s, %d)" % (program, node, username, unix_procid, proc_start_time, jobid, domain, process_id, creator_db)
    curs.execute(sql)

    # get the BLOB process_id for later reference
    sql = "SELECT BLOB(process_id) from process where hex(process_id)='%s' " % hex_procid
    curs.execute(sql)
    blob_procid = curs.fetchone()[0]


    #========================================================================
    #
    #                                Main
    #
    #========================================================================
    # Algorithm:
    # 1. Find distinct version 1 segment type from segment_summary table witnin start_time, end_time range 
    # 2. Find segments and intervals to coalesce
    # 3. Coalesce segments and intervals
    # 4. Insert coaleseced segments back in to the database
    # 5. Delete uncoalesced segments and intervals from the database


    # 1. From process_ids , find distinct segment type with in process table start_time range
    sql  = "SELECT distinct(hex(segment_summary.segment_def_id)) FROM segment_summary, segment_definer "
    sql += "WHERE segment_summary.segment_def_id=segment_definer.segment_def_id "
    sql += "AND segment_summary.segment_def_cdb=segment_definer.creator_db "
    sql += "AND segment_definer.version=1 "
    sql += "AND segment_summary.start_time between %d and %d " % (st,et)
    curs.execute(sql)
    def_ids = curs.fetchall()
    #print >> sys.stdout, ("%s" % def_ids)

    # loop in the segment types to fetch, coalesce, insert and delete
    for d in def_ids:
      # get the BLOB segment_def_id for later use 
      sql = "SELECT BLOB(segment_def_id), ifos, name " 
      sql += "FROM segment_definer " 
      sql += "WHERE hex(segment_def_id) = '%s' " % d[0]

      curs.execute(sql)
      result = curs.fetchone()
      blob_defid = result[0]
      ifos = result[1].strip() 
      name = result[2]

      # 2. Find segments and intervals to coalesce
      # get the segment start_time, end_time to coalesce, and according primary key to delete
      try:
        curs.execute("drop view seg_view")
      except:
        pass
      sql = "CREATE view seg_view (st,et,seg_id) AS "
      sql += "SELECT start_time,end_time, segment_id from segment "
      sql += "WHERE hex(segment_def_id) = '%s' " % d[0]
      sql += "AND start_time between %d and %d " % (st, et)
      print >> sys.stdout, ("Selecting segments to coalesce for %s %s ... " % (ifos, name))
      curs.execute(sql)
  
      curs.execute("SELECT st,et from seg_view")
      seg_bf_cos = curs.fetchall()   # get the segments to coalesce

      # get the summary start_time, end_time to coalesce, and according primary key to delete
      try:
        curs.execute("drop view sum_view")
      except:
        pass
      sql = "CREATE view sum_view (st,et,sum_id) AS "
      sql += "SELECT start_time,end_time, segment_sum_id from segment_summary "
      sql += "WHERE hex(segment_def_id) = '%s' " % d[0]
      sql += "AND start_time between %d and %d " % (st, et)
      curs.execute(sql)

      curs.execute("select st,et from sum_view")
      sum_bf_cos = curs.fetchall()   # get the summarys to coalesce

      # 3. Coalesce segments and intervals
      print >> sys.stdout, "Coalescing segments ... "
      segs = segments.segmentlist([]) 
      sums = segments.segmentlist([]) 
      for bf in seg_bf_cos:
        seg = segments.segment(int(bf[0]), int(bf[1]))
        segs.append(seg) 
      for bf in sum_bf_cos:
        sum = segments.segment(int(bf[0]), int(bf[1]))
        sums.append(sum) 

      segs.coalesce()
      sums.coalesce()


      # 4. Insert coaleseced segments back in to the database
      # insert coalesced segs into segment table
      insert_list = []
      for s in segs:
        # generate unique id for insertion
        curs.execute("VALUES BLOB(GENERATE_UNIQUE())")
        prim_id = curs.fetchone()[0]
        # generate a list of values to insert using executemany()
        insert_list.append((prim_id, creator_db, s[0], s[1], blob_defid, creator_db, blob_procid))

      sql = "INSERT INTO segment "
      sql += "(segment_id, creator_db, start_time, end_time, segment_def_id, segment_def_cdb, process_id) "
      sql += "VALUES (?,?,?,?,?,?,?) "
      print >> sys.stdout, "Inserting coalesced segments back in ... "
      curs.executemany(sql, insert_list)

      # insert coalesced sums into segment_summary table
      insert_list = []
      for s in sums:
        # generate unique id for insertion
        curs.execute("VALUES BLOB(GENERATE_UNIQUE())")
        prim_id = curs.fetchone()[0]
        # generate a list of values to insert using executemany()
        insert_list.append((prim_id, creator_db, s[0], s[1], blob_defid, creator_db, blob_procid))
      sql = "INSERT INTO segment_summary "
      sql += "(segment_sum_id, creator_db, start_time, end_time, segment_def_id, segment_def_cdb, process_id) "
      sql += "VALUES (?,?,?,?,?,?,?) "
      curs.executemany(sql, insert_list)

      # 5. Delete uncoalesced segments and intervals from the database
      print >> sys.stdout, "Deleting un-coalseced segments ... "
      print >> sys.stdout 
      sql = "DELETE FROM segment "
      sql += "WHERE segment_id in (select seg_id from seg_view) "
      sql += "AND process_id != %s " % process_id
      curs.execute(sql)

      sql = "DELETE FROM segment_summary "
      sql += "WHERE segment_sum_id in (select sum_id from sum_view) "
      sql += "AND process_id != %s " % process_id
      curs.execute(sql)

    # update end_time in process table
    sql = "update process set end_time=%d where hex(process_id)='%s' " % (current_time,hex_procid)
    curs.execute(sql)


  except Exception,e:
    ret = str(e)
    print >> sys.stdout, ("%s" % ret)

  curs.execute("drop table tmp_co_seg")
  curs.execute("drop table tmp_co_sum")
  curs.close()


  return ret
