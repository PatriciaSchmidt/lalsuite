/*----------------------------------------------------------------------- 
 * 
 * File Name: FindChirpChisq.h
 *
 * Author: Anderson, W. G., and Brown, D. A.
 * 
 * Revision: $Id$
 * 
 *-----------------------------------------------------------------------
 */

#if 0
<lalVerbatim file="FindChirpChisqHV">
Author: Anderson, W. G., and Brown, D. A.
$Id$
</lalVerbatim> 

<lalLaTeX>
\section{Header \texttt{FindChirpChisq.h}}
\label{s:FindChirpChisq.h}

Provides prototypes and functions to perform a $\chi^2$ veto on binary
inspiral chirps using data generated by the \texttt{FindChirpFilter()}
function.

\subsection*{Synopsis}

\begin{verbatim}
#include <lal/FindChirpChisq.h>
\end{verbatim}

\input{FindChirpChisqHDoc}
</lalLaTeX>
#endif

#ifndef _FINDCHIRPCHISQH_H
#define _FINDCHIRPCHISQH_H

#include <lal/LALDatatypes.h>

#ifdef  __cplusplus
extern "C" {
#pragma }
#endif


NRCSID (SPFINDCHIRPCHISQH, "$Id$");

#if 0
<lalLaTeX> 
\subsection*{Error codes} 
</lalLaTeX>
#endif
/* <lalErrTable> */
#define FINDCHIRPCHISQH_ENULL 1
#define FINDCHIRPCHISQH_ENNUL 2
#define FINDCHIRPCHISQH_ENUMZ 3
#define FINDCHIRPCHISQH_ECHIZ 4
#define FINDCHIRPCHISQH_EALOC 5
#define FINDCHIRPCHISQH_EUAPX 6
#define FINDCHIRPCHISQH_EIAPX 7
#define FINDCHIRPCHISQH_MSGENULL "Null pointer"
#define FINDCHIRPCHISQH_MSGENNUL "Non-null pointer"
#define FINDCHIRPCHISQH_MSGENUMZ "Number of points is zero or negative"
#define FINDCHIRPCHISQH_MSGECHIZ "Number of chisq bins is zero or negative"
#define FINDCHIRPCHISQH_MSGEALOC "Memory allocation error"
#define FINDCHIRPCHISQH_MSGEMTCH "Invalid template bank match"
#define FINDCHIRPCHISQH_MSGEUAPX "Unknown waveform approximant"
#define FINDCHIRPCHISQH_MSGEIAPX "Incorrect waveform approximant"
/* </lalErrTable> */

#if 0
<lalLaTeX>
\subsection*{Types}
</lalLaTeX>
#endif


/* --- structure for storing input to the chisq veto --------------------- */
/* <lalVerbatim file="FindChirpChisqHFindChirpChisqInput"> */
typedef struct
tagFindChirpChisqInput
{
  COMPLEX8Vector               *qtildeVec;
  COMPLEX8Vector               *qVec;
}
FindChirpChisqInput;
/* </lalVerbatim> */
#if 0
<lalLaTeX>
\subsubsection*{Structure \texttt{FindChirpChisqInput}}
\idx[Type]{FindChirpChisqInput}

\input{FindChirpChisqHFindChirpChisqInput}

\noindent This structure contains the input to the $\chi^2$ veto function.
The quantities should be populated by \texttt{FindChirpFilter()} on entry.
The fields are:

\begin{description}
\item[\texttt{COMPLEX8Vector *qtildeVec}] A vector containing the frequncy
domain quantity $\tilde{q}_k$ as defined in \texttt{FindChirpFilter()}.

\item[\texttt{COMPLEX8Vector *qVec}] A vector containing the time
domain quantity $q_j$ as defined in \texttt{FindChirpFilter()}.
\end{description}
</lalLaTeX>
#endif

/* --- parameter structure for the chisq veto ---------------------------- */
/* <lalVerbatim file="FindChirpChisqHFindChirpChisqParams"> */
typedef struct
tagFindChirpChisqParams
{
  REAL4                         norm;
  REAL4                         a1;
  REAL4                         b1;
  REAL4                         b2;
#if 0
  REAL4                         bankMatch;
#endif
  UINT4Vector                  *chisqBinVec;
  UINT4Vector                  *chisqBinVecBCV;
  ComplexFFTPlan               *plan;
  COMPLEX8Vector               *qtildeBinVec;
  COMPLEX8Vector               *qtildeBinVecBCV;
  COMPLEX8Vector              **qBinVecPtr;
  COMPLEX8Vector              **qBinVecPtrBCV;
  Approximant                   approximant;
}
FindChirpChisqParams;
/* </lalVerbatim> */
#if 0
<lalLaTeX>
\subsubsection*{Structure \texttt{FindChirpChisqParams}}
\idx[Type]{FindChirpChisqParams}

\input{FindChirpChisqHFindChirpChisqParams}

\noindent This structure contains the parameters used by the $\chi^2$ veto
function \texttt{FindChirpChisqVeto()}.  It is created and destroyed by the
\texttt{FindChirpChisqVetoInit()} and \texttt{FindChirpChisqVetoFinalize()}
functions. The fields are:

\begin{description}
\item[\texttt{REAL4 norm}] The normalization factor for the SP templates.
Equals $4 \Delta t / (N segNorm)$.

\item[\texttt{REAL4 a1}] BCV-template normalization parameter.

\item[\texttt{REAL4 b1}] BCV-template normalization parameter.

\item[\texttt{REAL4 b2}] BCV-template normalization parameter.

\item[\texttt{REAL4 bankMatch}] Template bank match...

\item[\texttt{UINT4Vector *chisqBinVec}] A vector containing the boundaries
of the bins for the chi-squared veto for the stationary phase chirps, or the
boundaries of the bins for the first sum of the chi-squared veto for the 
BCV templates.

\item[\texttt{UINT4Vector *chisqBinVecBCV}] A vector containing the boundaries
of the bins for the second part of the chi-squared statistic, for the BCV 
templates.

\item[\texttt{ComplexFFTPlan *plan}] The FFTW plan used by the inverse DFT.

\item[\texttt{COMPLEX8Vector *qtildeBinVec}] ...

\item[\texttt{COMPLEX8Vector *qtildeBinVecBCV}] ...

\item[\texttt{COMPLEX8Vector **qBinVecPtr}] Pointer to an array of pointers.
Corresponds to $q^{(1)}_l(t_j)$, which is the contribution of the $l$-th 
frequency 
bin to the signal-to-noise ratio at the time $t_j$ (up to the appropriate
normalization). It is used for both the stationary phase chirps and the
BCV templates.

\item[\texttt{COMPLEX8Vector **qBinVecPtrBCV}] Pointer to an array of pointers.
Corresponds to $q^{(2)}_l(t_j)$, which is the contribution of the $l$-th 
frequency 
bin to the signal-to-noise ratio at the time $t_j$ (up to the appropriate
normalization). It is used only for the BCV templates.

\end{description}
</lalLaTeX>
#endif

#if 0
<lalLaTeX>
\vfill{\footnotesize\input{FindChirpChisqHV}}
</lalLaTeX> 
#endif

#if 0
<lalLaTeX>
\newpage\input{FindChirpChisqC}
</lalLaTeX>
#endif

void
LALFindChirpChisqVetoInit (
    LALStatus                  *status,
    FindChirpChisqParams       *params,
    UINT4                       numChisqBins,
    UINT4                       numPoints
    );

void
LALFindChirpChisqVetoFinalize (
    LALStatus                  *status,
    FindChirpChisqParams       *params,
    UINT4                       numChisqBins
    );

void
LALFindChirpChisqVeto (
    LALStatus                  *status,
    REAL4Vector                *chisqVec,
    FindChirpChisqInput        *input,
    FindChirpChisqParams       *params
    );

void
LALFindChirpBCVChisqVeto (
    LALStatus                  *status,
    REAL4Vector                *chisqVec,
    FindChirpChisqInput        *input,
    FindChirpChisqInput        *inputBCV,
    FindChirpChisqParams       *params
    );


#ifdef  __cplusplus
#pragma {
}
#endif

#endif /* _FINDCHIRPCHISQH_H */
