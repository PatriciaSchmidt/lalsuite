REAL8 tmp1=x->data[0]*x->data[0];
REAL8 tmp2=x->data[1]*x->data[1];
REAL8 tmp3=x->data[2]*x->data[2];
REAL8 tmp4=tmp1+tmp2+tmp3;
REAL8 tmp9=s1Vec->data[1]+s2Vec->data[1];
REAL8 tmp7=s1Vec->data[0]+s2Vec->data[0];
REAL8 tmp8=tmp7*tmp7;
REAL8 tmp10=tmp9*tmp9;
REAL8 tmp11=s1Vec->data[2]+s2Vec->data[2];
REAL8 tmp12=tmp11*tmp11;
REAL8 tmp13=tmp10+tmp12+tmp8;
REAL8 tmp15=1./sqrt(tmp13);
REAL8 tmp16=tmp15*tmp9;
REAL8 tmp17=0.1+tmp16;
REAL8 tmp20=tmp15*tmp7;
REAL8 tmp21=0.1+tmp20;
REAL8 tmp18=1/tmp13;
REAL8 tmp19=tmp12*tmp18;
REAL8 tmp22=tmp21*tmp21;
REAL8 tmp23=tmp17*tmp17;
REAL8 tmp24=tmp19+tmp22+tmp23;
REAL8 tmp25=1./sqrt(tmp24);
REAL8 tmp26=1./sqrt(tmp4);
REAL8 tmp5=(1.0/(tmp4*tmp4));
REAL8 tmp53=1/tmp4;
REAL8 tmp56=coeffs->KK*eta;
REAL8 tmp57=-1.+tmp56;
REAL8 tmp45=pow(tmp4,-2.5);
REAL8 tmp72=tmp13*tmp13;
REAL8 tmp51=(1.0/sqrt(tmp4*tmp4*tmp4));
REAL8 tmp58=(1.0/(tmp57*tmp57));
REAL8 tmp59=1.*tmp58;
REAL8 tmp60=1.*tmp13*tmp53;
REAL8 tmp61=1/tmp57;
REAL8 tmp62=2.*tmp26*tmp61;
REAL8 tmp63=tmp59+tmp60+tmp62;
REAL8 tmp98=(1.0/sqrt(tmp13*tmp13*tmp13));
REAL8 tmp99=-(tmp8*tmp98);
REAL8 tmp100=tmp15+tmp99;
REAL8 tmp96=(1.0/(tmp13*tmp13));
REAL8 tmp97=-2.*tmp12*tmp7*tmp96;
REAL8 tmp101=2.*tmp100*tmp21;
REAL8 tmp102=-2.*tmp17*tmp7*tmp9*tmp98;
REAL8 tmp103=tmp101+tmp102+tmp97;
REAL8 tmp104=(1.0/sqrt(tmp24*tmp24*tmp24));
REAL8 tmp64=1.*tmp21*tmp25*tmp26*x->data[0];
REAL8 tmp65=1.*tmp17*tmp25*tmp26*x->data[1];
REAL8 tmp66=1.*tmp11*tmp15*tmp25*tmp26*x->data[2];
REAL8 tmp67=tmp64+tmp65+tmp66;
REAL8 tmp86=-1.+m1PlusEtaKK;
REAL8 tmp71=c1k5*tmp13;
REAL8 tmp73=c2k5*tmp72;
REAL8 tmp74=c0k5+tmp71+tmp73;
REAL8 tmp75=1.*tmp45*tmp74;
REAL8 tmp76=c1k4*tmp13;
REAL8 tmp77=c2k4*tmp72;
REAL8 tmp78=c0k4+tmp76+tmp77;
REAL8 tmp79=1.*tmp5*tmp78;
REAL8 tmp80=c1k3*tmp13;
REAL8 tmp81=c0k3+tmp80;
REAL8 tmp82=1.*tmp51*tmp81;
REAL8 tmp83=c1k2*tmp13;
REAL8 tmp84=c0k2+tmp83;
REAL8 tmp85=1.*tmp53*tmp84;
REAL8 tmp87=coeffs->KK*tmp86;
REAL8 tmp88=coeffs->KK+tmp87;
REAL8 tmp89=-2.*m1PlusEtaKK*tmp26*tmp88;
REAL8 tmp90=1.*tmp26;
REAL8 tmp91=log(tmp90);
REAL8 tmp92=1.*coeffs->k5l*tmp45*tmp91;
REAL8 tmp93=1.+tmp75+tmp79+tmp82+tmp85+tmp89+tmp92;
REAL8 tmp68=tmp67*tmp67;
REAL8 tmp69=-tmp68;
REAL8 tmp70=1.+tmp69;
REAL8 tmp112=coeffs->KK*eta*tmp86;
REAL8 tmp113=log(tmp93);
REAL8 tmp114=eta*tmp113;
REAL8 tmp115=1.+tmp112+tmp114;
REAL8 tmp40=tmp1+tmp10+tmp12+tmp2+tmp3+tmp8;
REAL8 tmp14=sqrt(tmp13);
REAL8 tmp120=tmp40*tmp40;
REAL8 tmp121=-(tmp115*tmp13*tmp4*tmp63*tmp70);
REAL8 tmp122=tmp120+tmp121;
REAL8 tmp27=-(tmp17*tmp25*tmp26*x->data[0]);
REAL8 tmp28=1.*tmp21*tmp25*tmp26*x->data[1];
REAL8 tmp29=tmp27+tmp28;
REAL8 tmp30=p->data[2]*tmp29;
REAL8 tmp31=1.*tmp11*tmp15*tmp25*tmp26*x->data[0];
REAL8 tmp32=-(tmp21*tmp25*tmp26*x->data[2]);
REAL8 tmp33=tmp31+tmp32;
REAL8 tmp34=p->data[1]*tmp33;
REAL8 tmp35=-(tmp11*tmp15*tmp25*tmp26*x->data[1]);
REAL8 tmp36=1.*tmp17*tmp25*tmp26*x->data[2];
REAL8 tmp37=tmp35+tmp36;
REAL8 tmp38=p->data[0]*tmp37;
REAL8 tmp39=tmp30+tmp34+tmp38;
REAL8 tmp144=1/tmp122;
REAL8 tmp148=tmp13*tmp68;
REAL8 tmp149=tmp1+tmp148+tmp2+tmp3;
REAL8 tmp150=1/tmp149;
REAL8 tmp125=0.5*tmp103*tmp104*tmp17*tmp26*x->data[0];
REAL8 tmp126=1.*tmp25*tmp26*tmp7*tmp9*tmp98*x->data[0];
REAL8 tmp127=-0.5*tmp103*tmp104*tmp21*tmp26*x->data[1];
REAL8 tmp128=1.*tmp100*tmp25*tmp26*x->data[1];
REAL8 tmp129=tmp125+tmp126+tmp127+tmp128;
REAL8 tmp131=0.5*tmp103*tmp104*tmp11*tmp15*tmp26*x->data[1];
REAL8 tmp132=1.*tmp11*tmp25*tmp26*tmp7*tmp98*x->data[1];
REAL8 tmp133=-0.5*tmp103*tmp104*tmp17*tmp26*x->data[2];
REAL8 tmp134=-(tmp25*tmp26*tmp7*tmp9*tmp98*x->data[2]);
REAL8 tmp135=tmp131+tmp132+tmp133+tmp134;
REAL8 tmp137=-0.5*tmp103*tmp104*tmp11*tmp15*tmp26*x->data[0];
REAL8 tmp138=-(tmp11*tmp25*tmp26*tmp7*tmp98*x->data[0]);
REAL8 tmp139=0.5*tmp103*tmp104*tmp21*tmp26*x->data[2];
REAL8 tmp140=-(tmp100*tmp25*tmp26*x->data[2]);
REAL8 tmp141=tmp137+tmp138+tmp139+tmp140;
REAL8 tmp154=1/tmp70;
REAL8 tmp105=-0.5*tmp103*tmp104*tmp21*tmp26*x->data[0];
REAL8 tmp106=1.*tmp100*tmp25*tmp26*x->data[0];
REAL8 tmp107=-0.5*tmp103*tmp104*tmp17*tmp26*x->data[1];
REAL8 tmp108=-(tmp25*tmp26*tmp7*tmp9*tmp98*x->data[1]);
REAL8 tmp109=-0.5*tmp103*tmp104*tmp11*tmp15*tmp26*x->data[2];
REAL8 tmp110=-(tmp11*tmp25*tmp26*tmp7*tmp98*x->data[2]);
REAL8 tmp111=tmp105+tmp106+tmp107+tmp108+tmp109+tmp110;
REAL8 tmp168=tmp26*tmp29*x->data[1];
REAL8 tmp169=-(tmp26*tmp33*x->data[2]);
REAL8 tmp170=tmp168+tmp169;
REAL8 tmp171=p->data[0]*tmp170;
REAL8 tmp172=tmp26*tmp33*x->data[0];
REAL8 tmp173=-(tmp26*tmp37*x->data[1]);
REAL8 tmp174=tmp172+tmp173;
REAL8 tmp175=p->data[2]*tmp174;
REAL8 tmp176=-(tmp26*tmp29*x->data[0]);
REAL8 tmp177=tmp26*tmp37*x->data[2];
REAL8 tmp178=tmp176+tmp177;
REAL8 tmp179=p->data[1]*tmp178;
REAL8 tmp180=tmp171+tmp175+tmp179;
REAL8 tmp186=tmp180*tmp180;
REAL8 tmp42=2.*c1k5*tmp7;
REAL8 tmp43=4.*c2k5*tmp13*tmp7;
REAL8 tmp44=tmp42+tmp43;
REAL8 tmp46=1.*tmp44*tmp45;
REAL8 tmp47=2.*c1k4*tmp7;
REAL8 tmp48=4.*c2k4*tmp13*tmp7;
REAL8 tmp49=tmp47+tmp48;
REAL8 tmp50=1.*tmp49*tmp5;
REAL8 tmp52=2.*c1k3*tmp51*tmp7;
REAL8 tmp54=2.*c1k2*tmp53*tmp7;
REAL8 tmp55=tmp46+tmp50+tmp52+tmp54;
REAL8 tmp94=1/tmp93;
REAL8 tmp190=p->data[0]*tmp26*x->data[0];
REAL8 tmp191=p->data[1]*tmp26*x->data[1];
REAL8 tmp192=p->data[2]*tmp26*x->data[2];
REAL8 tmp193=tmp190+tmp191+tmp192;
REAL8 tmp194=tmp193*tmp193;
REAL8 tmp182=2.*tmp111*tmp13*tmp67;
REAL8 tmp183=2.*tmp68*tmp7;
REAL8 tmp184=tmp182+tmp183;
REAL8 tmp185=(1.0/(tmp149*tmp149));
REAL8 tmp195=-3.*eta;
REAL8 tmp196=26.+tmp195;
REAL8 tmp197=2.*eta*tmp196*tmp51;
REAL8 tmp198=6.*eta*tmp53;
REAL8 tmp199=1.+tmp197+tmp198;
REAL8 tmp200=log(tmp199);
REAL8 tmp201=1.+tmp200;
REAL8 tmp41=4.*tmp40*tmp7;
REAL8 tmp95=-(eta*tmp13*tmp4*tmp55*tmp63*tmp70*tmp94);
REAL8 tmp116=2.*tmp111*tmp115*tmp13*tmp4*tmp63*tmp67;
REAL8 tmp117=-2.*tmp115*tmp13*tmp7*tmp70;
REAL8 tmp118=-2.*tmp115*tmp4*tmp63*tmp7*tmp70;
REAL8 tmp119=tmp116+tmp117+tmp118+tmp41+tmp95;
REAL8 tmp123=(1.0/(tmp122*tmp122));
REAL8 tmp130=p->data[2]*tmp129;
REAL8 tmp136=p->data[0]*tmp135;
REAL8 tmp142=p->data[1]*tmp141;
REAL8 tmp143=tmp130+tmp136+tmp142;
REAL8 tmp205=tmp39*tmp39;
REAL8 tmp188=(1.0/(tmp70*tmp70));
REAL8 tmp147=1/tmp63;
REAL8 tmp151=1/tmp115;
REAL8 tmp152=tmp122*tmp147*tmp150*tmp151*tmp53;
REAL8 tmp211=4.+tmp195;
REAL8 tmp212=(tmp193*tmp193*tmp193*tmp193);
REAL8 tmp213=2.*eta*tmp211*tmp212*tmp53;
REAL8 tmp214=tmp150*tmp154*tmp186*tmp4;
REAL8 tmp215=tmp115*tmp150*tmp194*tmp201*tmp4*tmp63;
REAL8 tmp216=tmp144*tmp149*tmp154*tmp205*tmp4;
REAL8 tmp217=1.+tmp213+tmp214+tmp215+tmp216;
REAL8 tmp231=sqrt(tmp4*tmp4*tmp4);
REAL8 tmp233=1/mass1;
REAL8 tmp234=mass2*s1Vec->data[1]*tmp233;
REAL8 tmp235=1/mass2;
REAL8 tmp236=mass1*s2Vec->data[1]*tmp235;
REAL8 tmp237=tmp234+tmp236;
REAL8 tmp230=sqrt(tmp4);
REAL8 tmp155=-(tmp129*tmp26*x->data[0]);
REAL8 tmp156=tmp135*tmp26*x->data[2];
REAL8 tmp157=tmp155+tmp156;
REAL8 tmp158=p->data[1]*tmp157;
REAL8 tmp159=-(tmp135*tmp26*x->data[1]);
REAL8 tmp160=tmp141*tmp26*x->data[0];
REAL8 tmp161=tmp159+tmp160;
REAL8 tmp162=p->data[2]*tmp161;
REAL8 tmp163=tmp129*tmp26*x->data[1];
REAL8 tmp164=-(tmp141*tmp26*x->data[2]);
REAL8 tmp165=tmp163+tmp164;
REAL8 tmp166=p->data[0]*tmp165;
REAL8 tmp167=tmp158+tmp162+tmp166;
REAL8 tmp181=2.*tmp150*tmp154*tmp167*tmp180*tmp4;
REAL8 tmp187=-(tmp154*tmp184*tmp185*tmp186*tmp4);
REAL8 tmp189=2.*tmp111*tmp150*tmp186*tmp188*tmp4*tmp67;
REAL8 tmp202=eta*tmp150*tmp194*tmp201*tmp4*tmp55*tmp63*tmp94;
REAL8 tmp203=-(tmp115*tmp184*tmp185*tmp194*tmp201*tmp4*tmp63);
REAL8 tmp204=2.*tmp115*tmp150*tmp194*tmp201*tmp7;
REAL8 tmp206=-(tmp119*tmp123*tmp149*tmp154*tmp205*tmp4);
REAL8 tmp207=2.*tmp143*tmp144*tmp149*tmp154*tmp39*tmp4;
REAL8 tmp208=tmp144*tmp154*tmp184*tmp205*tmp4;
REAL8 tmp209=2.*tmp111*tmp144*tmp149*tmp188*tmp205*tmp4*tmp67;
REAL8 tmp210=tmp181+tmp187+tmp189+tmp202+tmp203+tmp204+tmp206+tmp207+tmp208+tmp209;
REAL8 tmp248=(tmp4*tmp4*tmp4);
REAL8 tmp249=tmp63*tmp63;
REAL8 tmp250=tmp201*tmp201;
REAL8 tmp252=eta*eta;
REAL8 tmp254=tmp115*tmp115;
REAL8 tmp256=tmp4*tmp4;
REAL8 tmp262=-16.*eta;
REAL8 tmp263=21.*tmp252;
REAL8 tmp264=tmp262+tmp263;
REAL8 tmp268=0.+tmp214+tmp215+tmp216;
REAL8 tmp270=-47.*eta;
REAL8 tmp271=54.*tmp252;
REAL8 tmp272=tmp230*tmp264*tmp268;
REAL8 tmp273=tmp270+tmp271+tmp272;
REAL8 tmp247=(eta*eta*eta);
REAL8 tmp253=1./(tmp149*tmp149*tmp149);
REAL8 tmp286=-6.*eta;
REAL8 tmp287=39.*tmp252;
REAL8 tmp288=tmp286+tmp287;
REAL8 tmp291=16.*eta;
REAL8 tmp292=147.*tmp252;
REAL8 tmp293=tmp230*tmp268*tmp288;
REAL8 tmp294=tmp291+tmp292+tmp293;
REAL8 tmp303=mass2*s1Vec->data[2]*tmp233;
REAL8 tmp304=mass1*s2Vec->data[2]*tmp235;
REAL8 tmp305=tmp303+tmp304;
REAL8 tmp251=-720.*tmp115*tmp185*tmp212*tmp247*tmp248*tmp249*tmp250*tmp55*tmp94;
REAL8 tmp255=720.*tmp184*tmp212*tmp248*tmp249*tmp250*tmp252*tmp253*tmp254;
REAL8 tmp257=-1440.*tmp185*tmp212*tmp250*tmp252*tmp254*tmp256*tmp63*tmp7;
REAL8 tmp258=103.*eta;
REAL8 tmp259=-60.*tmp252;
REAL8 tmp260=tmp258+tmp259;
REAL8 tmp261=2.*tmp210*tmp230*tmp260;
REAL8 tmp265=6.*tmp115*tmp150*tmp194*tmp201*tmp210*tmp256*tmp264*tmp63;
REAL8 tmp266=3.*eta;
REAL8 tmp267=23.+tmp266;
REAL8 tmp269=2.*eta*tmp210*tmp267*tmp268*tmp4;
REAL8 tmp274=6.*eta*tmp150*tmp194*tmp201*tmp231*tmp273*tmp55*tmp63*tmp94;
REAL8 tmp275=-6.*tmp115*tmp184*tmp185*tmp194*tmp201*tmp231*tmp273*tmp63;
REAL8 tmp276=12.*tmp115*tmp150*tmp194*tmp201*tmp230*tmp273*tmp7;
REAL8 tmp277=tmp251+tmp255+tmp257+tmp261+tmp265+tmp269+tmp274+tmp275+tmp276;
REAL8 tmp279=1620.*tmp115*tmp185*tmp212*tmp247*tmp248*tmp249*tmp250*tmp55*tmp94;
REAL8 tmp280=-1620.*tmp184*tmp212*tmp248*tmp249*tmp250*tmp252*tmp253*tmp254;
REAL8 tmp281=3240.*tmp185*tmp212*tmp250*tmp252*tmp254*tmp256*tmp63*tmp7;
REAL8 tmp282=-109.*eta;
REAL8 tmp283=51.*tmp252;
REAL8 tmp284=tmp282+tmp283;
REAL8 tmp285=4.*tmp210*tmp230*tmp284;
REAL8 tmp289=-6.*tmp115*tmp150*tmp194*tmp201*tmp210*tmp256*tmp288*tmp63;
REAL8 tmp290=-90.*eta*tmp210*tmp268*tmp4;
REAL8 tmp295=-6.*eta*tmp150*tmp194*tmp201*tmp231*tmp294*tmp55*tmp63*tmp94;
REAL8 tmp296=6.*tmp115*tmp184*tmp185*tmp194*tmp201*tmp231*tmp294*tmp63;
REAL8 tmp297=-12.*tmp115*tmp150*tmp194*tmp201*tmp230*tmp294*tmp7;
REAL8 tmp298=tmp279+tmp280+tmp281+tmp285+tmp289+tmp290+tmp295+tmp296+tmp297;
REAL8 tmp323=mass2*s1Vec->data[0]*tmp233;
REAL8 tmp324=mass1*s2Vec->data[0]*tmp235;
REAL8 tmp325=tmp323+tmp324;
REAL8 tmp345=tmp268*tmp268;
REAL8 tmp340=27.*eta;
REAL8 tmp341=-353.+tmp340;
REAL8 tmp342=2.*eta*tmp341;
REAL8 tmp343=-360.*tmp185*tmp212*tmp248*tmp249*tmp250*tmp252*tmp254;
REAL8 tmp344=2.*tmp230*tmp260*tmp268;
REAL8 tmp346=eta*tmp267*tmp345*tmp4;
REAL8 tmp347=6.*tmp115*tmp150*tmp194*tmp201*tmp231*tmp273*tmp63;
REAL8 tmp348=tmp342+tmp343+tmp344+tmp346+tmp347;
REAL8 tmp351=8.+tmp266;
REAL8 tmp352=-112.*eta*tmp351;
REAL8 tmp353=810.*tmp185*tmp212*tmp248*tmp249*tmp250*tmp252*tmp254;
REAL8 tmp354=4.*tmp230*tmp268*tmp284;
REAL8 tmp355=-45.*eta*tmp345*tmp4;
REAL8 tmp356=-6.*tmp115*tmp150*tmp194*tmp201*tmp231*tmp294*tmp63;
REAL8 tmp357=tmp352+tmp353+tmp354+tmp355+tmp356;
REAL8 tmp361=coeffs->d1v2*eta*tmp51*tmp7;
REAL8 tmp362=-8.*tmp7;
REAL8 tmp363=14.*tmp325;
REAL8 tmp364=-36.*tmp115*tmp150*tmp194*tmp201*tmp231*tmp63*tmp7;
REAL8 tmp365=-30.*tmp115*tmp150*tmp194*tmp201*tmp231*tmp325*tmp63;
REAL8 tmp366=3.*tmp230*tmp268*tmp7;
REAL8 tmp367=4.*tmp230*tmp268*tmp325;
REAL8 tmp368=tmp362+tmp363+tmp364+tmp365+tmp366+tmp367;
REAL8 tmp369=0.08333333333333333*eta*tmp26*tmp368;
REAL8 tmp370=-0.013888888888888888*tmp325*tmp348*tmp53;
REAL8 tmp371=0.006944444444444444*tmp357*tmp53*tmp7;
REAL8 tmp372=tmp323+tmp324+tmp361+tmp369+tmp370+tmp371;
REAL8 tmp375=coeffs->d1v2*eta*tmp51*tmp9;
REAL8 tmp376=-8.*tmp9;
REAL8 tmp377=14.*tmp237;
REAL8 tmp378=-36.*tmp115*tmp150*tmp194*tmp201*tmp231*tmp63*tmp9;
REAL8 tmp379=-30.*tmp115*tmp150*tmp194*tmp201*tmp231*tmp237*tmp63;
REAL8 tmp380=3.*tmp230*tmp268*tmp9;
REAL8 tmp381=4.*tmp230*tmp237*tmp268;
REAL8 tmp382=tmp376+tmp377+tmp378+tmp379+tmp380+tmp381;
REAL8 tmp383=0.08333333333333333*eta*tmp26*tmp382;
REAL8 tmp384=-0.013888888888888888*tmp237*tmp348*tmp53;
REAL8 tmp385=0.006944444444444444*tmp357*tmp53*tmp9;
REAL8 tmp386=tmp234+tmp236+tmp375+tmp383+tmp384+tmp385;
REAL8 tmp389=coeffs->d1v2*eta*tmp11*tmp51;
REAL8 tmp390=-8.*tmp11;
REAL8 tmp391=14.*tmp305;
REAL8 tmp392=-36.*tmp11*tmp115*tmp150*tmp194*tmp201*tmp231*tmp63;
REAL8 tmp393=-30.*tmp115*tmp150*tmp194*tmp201*tmp231*tmp305*tmp63;
REAL8 tmp394=3.*tmp11*tmp230*tmp268;
REAL8 tmp395=4.*tmp230*tmp268*tmp305;
REAL8 tmp396=tmp390+tmp391+tmp392+tmp393+tmp394+tmp395;
REAL8 tmp397=0.08333333333333333*eta*tmp26*tmp396;
REAL8 tmp398=-0.013888888888888888*tmp305*tmp348*tmp53;
REAL8 tmp399=0.006944444444444444*tmp11*tmp357*tmp53;
REAL8 tmp400=tmp303+tmp304+tmp389+tmp397+tmp398+tmp399;
REAL8 tmp405=sqrt(tmp149);
REAL8 tmp232=-36.*eta*tmp150*tmp194*tmp201*tmp231*tmp55*tmp63*tmp9*tmp94;
REAL8 tmp238=-30.*eta*tmp150*tmp194*tmp201*tmp231*tmp237*tmp55*tmp63*tmp94;
REAL8 tmp239=36.*tmp115*tmp184*tmp185*tmp194*tmp201*tmp231*tmp63*tmp9;
REAL8 tmp240=30.*tmp115*tmp184*tmp185*tmp194*tmp201*tmp231*tmp237*tmp63;
REAL8 tmp241=-72.*tmp115*tmp150*tmp194*tmp201*tmp230*tmp7*tmp9;
REAL8 tmp242=-60.*tmp115*tmp150*tmp194*tmp201*tmp230*tmp237*tmp7;
REAL8 tmp243=3.*tmp210*tmp230*tmp9;
REAL8 tmp244=4.*tmp210*tmp230*tmp237;
REAL8 tmp245=tmp232+tmp238+tmp239+tmp240+tmp241+tmp242+tmp243+tmp244;
REAL8 tmp246=0.08333333333333333*eta*tmp245*tmp26;
REAL8 tmp278=-0.013888888888888888*tmp237*tmp277*tmp53;
REAL8 tmp299=0.006944444444444444*tmp298*tmp53*tmp9;
REAL8 tmp300=tmp246+tmp278+tmp299;
REAL8 tmp301=1.*tmp17*tmp25*tmp300;
REAL8 tmp302=-36.*eta*tmp11*tmp150*tmp194*tmp201*tmp231*tmp55*tmp63*tmp94;
REAL8 tmp306=-30.*eta*tmp150*tmp194*tmp201*tmp231*tmp305*tmp55*tmp63*tmp94;
REAL8 tmp307=36.*tmp11*tmp115*tmp184*tmp185*tmp194*tmp201*tmp231*tmp63;
REAL8 tmp308=30.*tmp115*tmp184*tmp185*tmp194*tmp201*tmp231*tmp305*tmp63;
REAL8 tmp309=-72.*tmp11*tmp115*tmp150*tmp194*tmp201*tmp230*tmp7;
REAL8 tmp310=-60.*tmp115*tmp150*tmp194*tmp201*tmp230*tmp305*tmp7;
REAL8 tmp311=3.*tmp11*tmp210*tmp230;
REAL8 tmp312=4.*tmp210*tmp230*tmp305;
REAL8 tmp313=tmp302+tmp306+tmp307+tmp308+tmp309+tmp310+tmp311+tmp312;
REAL8 tmp314=0.08333333333333333*eta*tmp26*tmp313;
REAL8 tmp315=-0.013888888888888888*tmp277*tmp305*tmp53;
REAL8 tmp316=0.006944444444444444*tmp11*tmp298*tmp53;
REAL8 tmp317=tmp314+tmp315+tmp316;
REAL8 tmp318=1.*tmp11*tmp15*tmp25*tmp317;
REAL8 tmp319=mass2*tmp233;
REAL8 tmp320=coeffs->d1v2*eta*tmp51;
REAL8 tmp321=14.*mass2*tmp233;
REAL8 tmp322=-36.*eta*tmp150*tmp194*tmp201*tmp231*tmp55*tmp63*tmp7*tmp94;
REAL8 tmp326=-30.*eta*tmp150*tmp194*tmp201*tmp231*tmp325*tmp55*tmp63*tmp94;
REAL8 tmp327=36.*tmp115*tmp184*tmp185*tmp194*tmp201*tmp231*tmp63*tmp7;
REAL8 tmp328=30.*tmp115*tmp184*tmp185*tmp194*tmp201*tmp231*tmp325*tmp63;
REAL8 tmp329=-72.*tmp115*tmp150*tmp194*tmp201*tmp230*tmp8;
REAL8 tmp330=-60.*tmp115*tmp150*tmp194*tmp201*tmp230*tmp325*tmp7;
REAL8 tmp331=-36.*tmp115*tmp150*tmp194*tmp201*tmp231*tmp63;
REAL8 tmp332=-30.*mass2*tmp115*tmp150*tmp194*tmp201*tmp231*tmp233*tmp63;
REAL8 tmp333=3.*tmp210*tmp230*tmp7;
REAL8 tmp334=4.*tmp210*tmp230*tmp325;
REAL8 tmp335=3.*tmp230*tmp268;
REAL8 tmp336=4.*mass2*tmp230*tmp233*tmp268;
REAL8 tmp337=-8.+tmp321+tmp322+tmp326+tmp327+tmp328+tmp329+tmp330+tmp331+tmp332+tmp333+tmp334+tmp335+tmp336;
REAL8 tmp338=0.08333333333333333*eta*tmp26*tmp337;
REAL8 tmp339=-0.013888888888888888*tmp277*tmp325*tmp53;
REAL8 tmp349=-0.013888888888888888*mass2*tmp233*tmp348*tmp53;
REAL8 tmp350=0.006944444444444444*tmp298*tmp53*tmp7;
REAL8 tmp358=0.006944444444444444*tmp357*tmp53;
REAL8 tmp359=tmp319+tmp320+tmp338+tmp339+tmp349+tmp350+tmp358;
REAL8 tmp360=1.*tmp21*tmp25*tmp359;
REAL8 tmp373=-0.5*tmp103*tmp104*tmp21*tmp372;
REAL8 tmp374=1.*tmp100*tmp25*tmp372;
REAL8 tmp387=-0.5*tmp103*tmp104*tmp17*tmp386;
REAL8 tmp388=-(tmp25*tmp386*tmp7*tmp9*tmp98);
REAL8 tmp401=-0.5*tmp103*tmp104*tmp11*tmp15*tmp400;
REAL8 tmp402=-(tmp11*tmp25*tmp400*tmp7*tmp98);
REAL8 tmp403=tmp301+tmp318+tmp360+tmp373+tmp374+tmp387+tmp388+tmp401+tmp402;
REAL8 tmp416=1.*tmp21*tmp25*tmp372;
REAL8 tmp417=1.*tmp17*tmp25*tmp386;
REAL8 tmp418=1.*tmp11*tmp15*tmp25*tmp400;
REAL8 tmp419=tmp416+tmp417+tmp418;
REAL8 tmp406=tmp115*tmp4*tmp63;
REAL8 tmp407=sqrt(tmp406);
REAL8 tmp408=-tmp407;
REAL8 tmp409=tmp115*tmp144*tmp149*tmp4*tmp63;
REAL8 tmp410=sqrt(tmp409);
REAL8 tmp411=tmp405*tmp410;
REAL8 tmp412=tmp408+tmp411;
REAL8 tmp413=1.+tmp214+tmp215+tmp216;
REAL8 tmp414=1./sqrt(tmp413);
REAL8 tmp426=1./sqrt(tmp149);
REAL8 tmp429=1./sqrt(tmp406);
REAL8 tmp435=1./sqrt(tmp409);
REAL8 tmp461=sqrt(tmp413);
REAL8 tmp451=tmp26*tmp372*x->data[0];
REAL8 tmp452=tmp26*tmp386*x->data[1];
REAL8 tmp453=tmp26*tmp400*x->data[2];
REAL8 tmp454=tmp451+tmp452+tmp453;
REAL8 tmp458=sqrt(tmp13*tmp13*tmp13);
REAL8 tmp459=(1.0/sqrt(tmp149*tmp149*tmp149));
REAL8 tmp422=(1.0/sqrt(tmp413*tmp413*tmp413));
REAL8 tmp462=1.+tmp461;
REAL8 tmp464=tmp149*tmp149;
REAL8 tmp465=-(tmp115*tmp144*tmp205*tmp256*tmp464*tmp63);
REAL8 tmp466=tmp186*tmp4;
REAL8 tmp467=1.+tmp214+tmp215+tmp216+tmp461;
REAL8 tmp468=-(tmp149*tmp467*tmp70);
REAL8 tmp469=tmp466+tmp468;
REAL8 tmp470=tmp115*tmp4*tmp469*tmp63;
REAL8 tmp471=tmp465+tmp470;
REAL8 tmp472=tmp454*tmp471;
REAL8 tmp473=tmp115*tmp201*tmp4*tmp63;
REAL8 tmp474=sqrt(tmp473);
REAL8 tmp475=tmp37*tmp372;
REAL8 tmp476=tmp33*tmp386;
REAL8 tmp477=tmp29*tmp400;
REAL8 tmp478=tmp475+tmp476+tmp477;
REAL8 tmp479=-(tmp230*tmp39*tmp405*tmp410*tmp478);
REAL8 tmp480=tmp170*tmp372;
REAL8 tmp481=tmp178*tmp386;
REAL8 tmp482=tmp174*tmp400;
REAL8 tmp483=tmp480+tmp481+tmp482;
REAL8 tmp484=tmp180*tmp230*tmp407*tmp483;
REAL8 tmp485=tmp479+tmp484;
REAL8 tmp486=-(tmp193*tmp407*tmp474*tmp485);
REAL8 tmp487=tmp472+tmp486;
REAL8 tmp489=1/tmp462;
REAL8 tmp430=eta*tmp4*tmp55*tmp63*tmp94;
REAL8 tmp431=2.*tmp115*tmp7;
REAL8 tmp432=tmp430+tmp431;
REAL8 tmp436=-(tmp115*tmp119*tmp123*tmp149*tmp4*tmp63);
REAL8 tmp437=eta*tmp144*tmp149*tmp4*tmp55*tmp63*tmp94;
REAL8 tmp438=tmp115*tmp144*tmp184*tmp4*tmp63;
REAL8 tmp439=2.*tmp115*tmp144*tmp149*tmp7;
REAL8 tmp440=tmp436+tmp437+tmp438+tmp439;
REAL8 tmp447=tmp26*tmp300*x->data[1];
REAL8 tmp448=tmp26*tmp317*x->data[2];
REAL8 tmp449=tmp26*tmp359*x->data[0];
REAL8 tmp450=tmp447+tmp448+tmp449;
REAL8 tmp554=coeffs->k5l*tmp91;
REAL8 tmp555=c0k5+tmp554+tmp71+tmp73;
REAL8 tmp527=tmp300*tmp33;
REAL8 tmp528=tmp29*tmp317;
REAL8 tmp529=tmp359*tmp37;
REAL8 tmp530=tmp135*tmp372;
REAL8 tmp531=tmp141*tmp386;
REAL8 tmp532=tmp129*tmp400;
REAL8 tmp533=tmp527+tmp528+tmp529+tmp530+tmp531+tmp532;
REAL8 tmp538=tmp178*tmp300;
REAL8 tmp539=tmp174*tmp317;
REAL8 tmp540=tmp170*tmp359;
REAL8 tmp541=tmp165*tmp372;
REAL8 tmp542=tmp157*tmp386;
REAL8 tmp543=tmp161*tmp400;
REAL8 tmp544=tmp538+tmp539+tmp540+tmp541+tmp542+tmp543;
REAL8 tmp522=1./sqrt(tmp473);
REAL8 tmp523=eta*tmp201*tmp4*tmp55*tmp63*tmp94;
REAL8 tmp524=2.*tmp115*tmp201*tmp7;
REAL8 tmp525=tmp523+tmp524;
REAL8 tmp510=0.5*tmp210*tmp414;
REAL8 tmp511=tmp181+tmp187+tmp189+tmp202+tmp203+tmp204+tmp206+tmp207+tmp208+tmp209+tmp510;
REAL8 tmp605=tmp180*tmp193*tmp230*tmp454*tmp474;
REAL8 tmp606=-(tmp115*tmp194*tmp201*tmp4*tmp483*tmp63);
REAL8 tmp607=tmp149*tmp467*tmp483;
REAL8 tmp608=tmp605+tmp606+tmp607;
REAL8 tmp460=1/tmp413;
REAL8 tmp552=2.*tmp122*tmp14;
REAL8 tmp553=4.*tmp230*tmp40;
REAL8 tmp556=1.*tmp45*tmp555;
REAL8 tmp557=1.+tmp556+tmp79+tmp82+tmp85+tmp89;
REAL8 tmp558=1/tmp557;
REAL8 tmp559=-2.*m1PlusEtaKK*tmp88;
REAL8 tmp560=2.*tmp84;
REAL8 tmp561=3.*tmp81;
REAL8 tmp562=4.*tmp78;
REAL8 tmp563=5.*tmp26*tmp555;
REAL8 tmp564=tmp562+tmp563;
REAL8 tmp565=1.*tmp26*tmp564;
REAL8 tmp566=tmp561+tmp565;
REAL8 tmp567=1.*tmp26*tmp566;
REAL8 tmp568=tmp560+tmp567;
REAL8 tmp569=1.*tmp26*tmp568;
REAL8 tmp570=tmp559+tmp569;
REAL8 tmp571=-(eta*tmp558*tmp570*tmp63);
REAL8 tmp572=2.*tmp115*tmp230*tmp63;
REAL8 tmp573=1.*tmp61;
REAL8 tmp574=1.*tmp13*tmp26;
REAL8 tmp575=tmp573+tmp574;
REAL8 tmp576=-2.*tmp115*tmp575;
REAL8 tmp577=tmp571+tmp572+tmp576;
REAL8 tmp578=-(tmp13*tmp577*tmp70);
REAL8 tmp579=tmp553+tmp578;
REAL8 tmp580=-2.*tmp14*tmp230*tmp579;
REAL8 tmp581=tmp552+tmp580;
REAL8 tmp463=(1.0/(tmp462*tmp462));
REAL8 tmp614=-(tmp180*tmp39*tmp4*tmp405*tmp407*tmp410*tmp478);
REAL8 tmp615=tmp115*tmp144*tmp205*tmp256*tmp464*tmp483*tmp63;
REAL8 tmp616=tmp115*tmp4*tmp608*tmp63*tmp70;
REAL8 tmp617=tmp614+tmp615+tmp616;
REAL8 tmp491=1./(tmp122*tmp122*tmp122);
REAL8 tmp494=pow(tmp149,-2.5);
REAL8 tmp499=(1.0/sqrt(tmp406*tmp406*tmp406));
REAL8 tmp501=(1.0/sqrt(tmp409*tmp409*tmp409));
REAL8 tmp665=tmp150*tmp230;
REAL8 tmp666=-tmp522;
REAL8 tmp667=tmp665+tmp666;
REAL8 tmp654=-(tmp115*tmp4*tmp63);
REAL8 tmp655=tmp1+tmp10+tmp12+tmp2+tmp3+tmp654+tmp8;
REAL8 tmp675=-4.*tmp115*tmp231*tmp63;
REAL8 tmp676=tmp40*tmp577;
REAL8 tmp677=tmp675+tmp676;
REAL8 tmp678=0.5*tmp144*tmp147*tmp151*tmp40*tmp53*tmp677;
REAL8 tmp679=tmp665+tmp678;
REAL8 tmp656=2.*tmp461;
REAL8 tmp657=1.+tmp656;
REAL8 tmp223=(1.0/(tmp115*tmp115));
REAL8 tmp658=-(tmp13*tmp144*tmp230*tmp39*tmp40*tmp407*tmp410*tmp426*tmp454*tmp655*tmp657*tmp67*tmp70);
REAL8 tmp659=tmp201*tmp249*tmp254*tmp256;
REAL8 tmp660=1./sqrt(tmp659);
REAL8 tmp661=-2.*tmp115*tmp4*tmp63;
REAL8 tmp662=tmp474*tmp577;
REAL8 tmp663=tmp661+tmp662;
REAL8 tmp664=-0.5*tmp230*tmp39*tmp405*tmp410*tmp462*tmp483*tmp660*tmp663;
REAL8 tmp668=tmp180*tmp230*tmp407*tmp478*tmp667;
REAL8 tmp669=-(tmp13*tmp150*tmp193*tmp67*tmp70);
REAL8 tmp670=tmp180*tmp230*tmp667;
REAL8 tmp671=-(tmp13*tmp150*tmp67);
REAL8 tmp672=tmp13*tmp144*tmp150*tmp40*tmp655*tmp67;
REAL8 tmp673=tmp671+tmp672;
REAL8 tmp674=tmp193*tmp673*tmp70;
REAL8 tmp680=-(tmp180*tmp230*tmp679);
REAL8 tmp681=tmp670+tmp674+tmp680;
REAL8 tmp682=tmp461*tmp681;
REAL8 tmp683=tmp669+tmp682;
REAL8 tmp684=tmp407*tmp478*tmp683;
REAL8 tmp685=tmp230*tmp39*tmp405*tmp410*tmp483*tmp657*tmp679;
REAL8 tmp686=tmp668+tmp684+tmp685;
REAL8 tmp687=tmp407*tmp686;
REAL8 tmp688=tmp664+tmp687;
REAL8 tmp689=tmp474*tmp688;
REAL8 tmp690=tmp658+tmp689;
REAL8 tmp692=1/tmp467;
REAL8 tmp226=(1.0/(tmp63*tmp63));
REAL8 tmp622=2.*eta*tmp230*tmp55*tmp63*tmp94;
REAL8 tmp623=-2.*eta*tmp55*tmp575*tmp94;
REAL8 tmp624=4.*c1k2*tmp7;
REAL8 tmp625=6.*c1k3*tmp7;
REAL8 tmp626=4.*tmp49;
REAL8 tmp627=5.*tmp26*tmp44;
REAL8 tmp628=tmp626+tmp627;
REAL8 tmp629=1.*tmp26*tmp628;
REAL8 tmp630=tmp625+tmp629;
REAL8 tmp631=1.*tmp26*tmp630;
REAL8 tmp632=tmp624+tmp631;
REAL8 tmp633=-(eta*tmp26*tmp558*tmp63*tmp632);
REAL8 tmp634=(1.0/(tmp557*tmp557));
REAL8 tmp635=eta*tmp55*tmp570*tmp63*tmp634;
REAL8 tmp636=-2.*eta*tmp53*tmp558*tmp570*tmp7;
REAL8 tmp637=0.+tmp622+tmp623+tmp633+tmp635+tmp636;
REAL8 tmp701=2.*tmp7;
REAL8 tmp702=-(eta*tmp4*tmp55*tmp63*tmp94);
REAL8 tmp703=-2.*tmp115*tmp7;
REAL8 tmp704=tmp701+tmp702+tmp703;
REAL8 tmp736=-(tmp184*tmp185*tmp230);
REAL8 tmp737=(1.0/sqrt(tmp473*tmp473*tmp473));
REAL8 tmp738=0.5*tmp525*tmp737;
REAL8 tmp739=tmp736+tmp738;
REAL8 tmp759=-4.*eta*tmp231*tmp55*tmp63*tmp94;
REAL8 tmp760=tmp40*tmp637;
REAL8 tmp761=-8.*tmp115*tmp230*tmp7;
REAL8 tmp762=2.*tmp577*tmp7;
REAL8 tmp763=tmp759+tmp760+tmp761+tmp762;
REAL8 tmp764=0.5*tmp144*tmp147*tmp151*tmp40*tmp53*tmp763;
REAL8 tmp765=-0.5*tmp119*tmp123*tmp147*tmp151*tmp40*tmp53*tmp677;
REAL8 tmp766=-0.5*eta*tmp144*tmp147*tmp223*tmp40*tmp53*tmp55*tmp677*tmp94;
REAL8 tmp767=-(tmp144*tmp151*tmp226*tmp40*tmp5*tmp677*tmp7);
REAL8 tmp768=1.*tmp144*tmp147*tmp151*tmp53*tmp677*tmp7;
REAL8 tmp769=tmp736+tmp764+tmp765+tmp766+tmp767+tmp768;
REAL8 tmp153=1./sqrt(tmp152);
REAL8 tmp221=sqrt(tmp217);
REAL8 ds100000=(1.*eta*(2.*tmp14*tmp143*tmp144*tmp4-2.*tmp119*tmp123*tmp14*tmp39*tmp4+2.*tmp14*tmp144*tmp230*tmp403+tmp144*tmp154*tmp230*tmp39*tmp403*tmp405*tmp412*tmp414-2.*tmp119*tmp123*tmp14*tmp230*tmp419+tmp143*tmp144*tmp154*tmp230*tmp405*tmp412*tmp414*tmp419-tmp119*tmp123*tmp154*tmp230*tmp39*tmp405*tmp412*tmp414*tmp419-0.5*tmp144*tmp154*tmp210*tmp230*tmp39*tmp405*tmp412*tmp419*tmp422+0.5*tmp144*tmp154*tmp184*tmp230*tmp39*tmp412*tmp414*tmp419*tmp426+tmp144*tmp154*tmp230*tmp39*tmp405*tmp414*tmp419*(0.5*tmp184*tmp410*tmp426-0.5*tmp429*tmp432+0.5*tmp405*tmp435*tmp440)+2.*coeffs->dheffSSv2*eta*s1Vec->data[0]*tmp5-0.5*(2.*tmp359*tmp372+2.*tmp300*tmp386+2.*tmp317*tmp400-6.*tmp450*tmp454)*tmp51-0.25*tmp123*tmp154*tmp210*tmp429*tmp435*tmp459*tmp460*tmp463*tmp474*tmp581*tmp617-0.25*tmp123*tmp154*tmp210*tmp422*tmp429*tmp435*tmp459*tmp474*tmp489*tmp581*tmp617-tmp119*tmp154*tmp414*tmp429*tmp435*tmp459*tmp474*tmp489*tmp491*tmp581*tmp617-0.75*tmp123*tmp154*tmp184*tmp414*tmp429*tmp435*tmp474*tmp489*tmp494*tmp581*tmp617-0.25*tmp123*tmp154*tmp414*tmp432*tmp435*tmp459*tmp474*tmp489*tmp499*tmp581*tmp617-0.25*tmp123*tmp154*tmp414*tmp429*tmp440*tmp459*tmp474*tmp489*tmp501*tmp581*tmp617+0.25*tmp123*tmp154*tmp414*tmp429*tmp435*tmp459*tmp489*tmp522*tmp525*tmp581*tmp617-2.*tmp111*tmp115*tmp123*tmp231*tmp414*tmp429*tmp435*tmp458*tmp459*tmp487*tmp489*tmp63+2.*tmp111*tmp144*tmp188*tmp230*tmp39*tmp405*tmp412*tmp414*tmp419*tmp67+1.*tmp111*tmp123*tmp188*tmp414*tmp429*tmp435*tmp459*tmp474*tmp489*tmp581*tmp617*tmp67+1.*tmp115*tmp123*tmp210*tmp231*tmp429*tmp435*tmp458*tmp459*tmp460*tmp463*tmp487*tmp63*tmp67+1.*tmp115*tmp123*tmp210*tmp231*tmp422*tmp429*tmp435*tmp458*tmp459*tmp487*tmp489*tmp63*tmp67+4.*tmp115*tmp119*tmp231*tmp414*tmp429*tmp435*tmp458*tmp459*tmp487*tmp489*tmp491*tmp63*tmp67+3.*tmp115*tmp123*tmp184*tmp231*tmp414*tmp429*tmp435*tmp458*tmp487*tmp489*tmp494*tmp63*tmp67+1.*tmp115*tmp123*tmp231*tmp414*tmp432*tmp435*tmp458*tmp459*tmp487*tmp489*tmp499*tmp63*tmp67+1.*tmp115*tmp123*tmp231*tmp414*tmp429*tmp440*tmp458*tmp459*tmp487*tmp489*tmp501*tmp63*tmp67-tmp147*tmp151*tmp154*tmp184*tmp185*tmp410*tmp53*tmp690*tmp692+0.5*tmp147*tmp150*tmp151*tmp154*tmp435*tmp440*tmp53*tmp690*tmp692+2.*tmp111*tmp147*tmp150*tmp151*tmp188*tmp410*tmp53*tmp67*tmp690*tmp692+2.*tmp144*tmp15*tmp39*tmp4*tmp7+2.*tmp144*tmp15*tmp230*tmp419*tmp7-4.*tmp115*tmp123*tmp230*tmp414*tmp429*tmp435*tmp458*tmp459*tmp487*tmp489*tmp67*tmp7-6.*tmp115*tmp123*tmp14*tmp231*tmp414*tmp429*tmp435*tmp459*tmp487*tmp489*tmp63*tmp67*tmp7-2.*tmp150*tmp151*tmp154*tmp226*tmp410*tmp5*tmp690*tmp692*tmp7+0.5*tmp123*tmp154*tmp414*tmp429*tmp435*tmp459*tmp474*tmp489*tmp617*(2.*tmp119*tmp14+2.*tmp122*tmp15*tmp7-2.*tmp15*tmp230*tmp579*tmp7-2.*tmp14*tmp230*(2.*tmp111*tmp13*tmp577*tmp67+8.*tmp230*tmp7-tmp13*tmp637*tmp70-2.*tmp577*tmp7*tmp70))-2.*eta*tmp123*tmp231*tmp414*tmp429*tmp435*tmp458*tmp459*tmp487*tmp489*tmp55*tmp63*tmp67*tmp94-eta*tmp147*tmp150*tmp154*tmp223*tmp410*tmp53*tmp55*tmp690*tmp692*tmp94-2.*tmp115*tmp123*tmp231*tmp414*tmp429*tmp435*tmp458*tmp459*tmp489*tmp63*tmp67*(tmp450*tmp471-0.5*tmp193*tmp429*tmp432*tmp474*tmp485-0.5*tmp193*tmp407*tmp485*tmp522*tmp525-tmp193*tmp407*tmp474*(-(tmp143*tmp230*tmp405*tmp410*tmp478)-0.5*tmp184*tmp230*tmp39*tmp410*tmp426*tmp478-0.5*tmp230*tmp39*tmp405*tmp435*tmp440*tmp478+tmp167*tmp230*tmp407*tmp483+0.5*tmp180*tmp230*tmp429*tmp432*tmp483-tmp230*tmp39*tmp405*tmp410*tmp533+tmp180*tmp230*tmp407*tmp544)+tmp454*(-2.*tmp115*tmp144*tmp149*tmp184*tmp205*tmp256*tmp63+tmp115*tmp119*tmp123*tmp205*tmp256*tmp464*tmp63-2.*tmp115*tmp143*tmp144*tmp256*tmp39*tmp464*tmp63-2.*tmp115*tmp144*tmp205*tmp4*tmp464*tmp7+2.*tmp115*tmp469*tmp7+tmp115*tmp4*tmp63*(2.*tmp167*tmp180*tmp4+2.*tmp111*tmp149*tmp467*tmp67-tmp184*tmp467*tmp70-tmp149*tmp511*tmp70)-eta*tmp144*tmp205*tmp256*tmp464*tmp55*tmp63*tmp94+eta*tmp4*tmp469*tmp55*tmp63*tmp94))+0.5*tmp123*tmp154*tmp414*tmp429*tmp435*tmp459*tmp474*tmp489*tmp581*(-(tmp143*tmp180*tmp4*tmp405*tmp407*tmp410*tmp478)-tmp167*tmp39*tmp4*tmp405*tmp407*tmp410*tmp478-0.5*tmp180*tmp184*tmp39*tmp4*tmp407*tmp410*tmp426*tmp478-0.5*tmp180*tmp39*tmp4*tmp405*tmp410*tmp429*tmp432*tmp478-0.5*tmp180*tmp39*tmp4*tmp405*tmp407*tmp435*tmp440*tmp478-tmp180*tmp39*tmp4*tmp405*tmp407*tmp410*tmp533+2.*tmp115*tmp144*tmp149*tmp184*tmp205*tmp256*tmp483*tmp63-tmp115*tmp119*tmp123*tmp205*tmp256*tmp464*tmp483*tmp63+2.*tmp115*tmp143*tmp144*tmp256*tmp39*tmp464*tmp483*tmp63+tmp115*tmp144*tmp205*tmp256*tmp464*tmp544*tmp63-2.*tmp111*tmp115*tmp4*tmp608*tmp63*tmp67+2.*tmp115*tmp144*tmp205*tmp4*tmp464*tmp483*tmp7+2.*tmp115*tmp608*tmp7*tmp70+eta*tmp144*tmp205*tmp256*tmp464*tmp483*tmp55*tmp63*tmp94+eta*tmp4*tmp55*tmp608*tmp63*tmp70*tmp94+tmp115*tmp4*tmp63*tmp70*(tmp180*tmp193*tmp230*tmp450*tmp474+tmp167*tmp193*tmp230*tmp454*tmp474+tmp184*tmp467*tmp483+tmp149*tmp483*tmp511+0.5*tmp180*tmp193*tmp230*tmp454*tmp522*tmp525+tmp149*tmp467*tmp544-tmp115*tmp194*tmp201*tmp4*tmp544*tmp63-2.*tmp115*tmp194*tmp201*tmp483*tmp7-eta*tmp194*tmp201*tmp4*tmp483*tmp55*tmp63*tmp94))-0.5*tmp221*(tmp119*tmp147*tmp150*tmp151*tmp53-tmp122*tmp147*tmp151*tmp184*tmp185*tmp53-2.*tmp122*tmp150*tmp151*tmp226*tmp5*tmp7-eta*tmp122*tmp147*tmp150*tmp223*tmp53*tmp55*tmp94)*(1.0/sqrt(tmp152*tmp152*tmp152))-tmp147*tmp150*tmp151*tmp154*tmp410*tmp511*tmp53*tmp690*(1.0/(tmp467*tmp467))+tmp147*tmp150*tmp151*tmp154*tmp410*tmp53*tmp692*(2.*tmp111*tmp13*tmp144*tmp230*tmp39*tmp40*tmp407*tmp410*tmp426*tmp454*tmp655*tmp657*tmp68+0.5*tmp522*tmp525*tmp688-tmp111*tmp13*tmp144*tmp230*tmp39*tmp40*tmp407*tmp410*tmp426*tmp454*tmp655*tmp657*tmp70-tmp13*tmp144*tmp210*tmp230*tmp39*tmp40*tmp407*tmp410*tmp414*tmp426*tmp454*tmp655*tmp67*tmp70-tmp13*tmp144*tmp230*tmp39*tmp40*tmp407*tmp410*tmp426*tmp450*tmp655*tmp657*tmp67*tmp70-tmp13*tmp143*tmp144*tmp230*tmp40*tmp407*tmp410*tmp426*tmp454*tmp655*tmp657*tmp67*tmp70+tmp119*tmp123*tmp13*tmp230*tmp39*tmp40*tmp407*tmp410*tmp426*tmp454*tmp655*tmp657*tmp67*tmp70-0.5*tmp13*tmp144*tmp230*tmp39*tmp40*tmp410*tmp426*tmp429*tmp432*tmp454*tmp655*tmp657*tmp67*tmp70-0.5*tmp13*tmp144*tmp230*tmp39*tmp40*tmp407*tmp426*tmp435*tmp440*tmp454*tmp655*tmp657*tmp67*tmp70+0.5*tmp13*tmp144*tmp184*tmp230*tmp39*tmp40*tmp407*tmp410*tmp454*tmp459*tmp655*tmp657*tmp67*tmp70-2.*tmp13*tmp144*tmp230*tmp39*tmp407*tmp410*tmp426*tmp454*tmp655*tmp657*tmp67*tmp7*tmp70-2.*tmp144*tmp230*tmp39*tmp40*tmp407*tmp410*tmp426*tmp454*tmp655*tmp657*tmp67*tmp7*tmp70-tmp13*tmp144*tmp230*tmp39*tmp40*tmp407*tmp410*tmp426*tmp454*tmp657*tmp67*tmp70*tmp704+tmp474*(-0.25*tmp210*tmp230*tmp39*tmp405*tmp410*tmp414*tmp483*tmp660*tmp663-0.5*tmp143*tmp230*tmp405*tmp410*tmp462*tmp483*tmp660*tmp663-0.25*tmp184*tmp230*tmp39*tmp410*tmp426*tmp462*tmp483*tmp660*tmp663-0.25*tmp230*tmp39*tmp405*tmp435*tmp440*tmp462*tmp483*tmp660*tmp663-0.5*tmp230*tmp39*tmp405*tmp410*tmp462*tmp544*tmp660*tmp663+0.5*tmp429*tmp432*tmp686+tmp407*(tmp167*tmp230*tmp407*tmp478*tmp667+0.5*tmp180*tmp230*tmp429*tmp432*tmp478*tmp667+tmp180*tmp230*tmp407*tmp533*tmp667+1.*tmp210*tmp230*tmp39*tmp405*tmp410*tmp414*tmp483*tmp679+tmp143*tmp230*tmp405*tmp410*tmp483*tmp657*tmp679+0.5*tmp184*tmp230*tmp39*tmp410*tmp426*tmp483*tmp657*tmp679+0.5*tmp230*tmp39*tmp405*tmp435*tmp440*tmp483*tmp657*tmp679+tmp230*tmp39*tmp405*tmp410*tmp544*tmp657*tmp679+0.5*tmp429*tmp432*tmp478*tmp683+tmp407*tmp533*tmp683+tmp180*tmp230*tmp407*tmp478*tmp739+tmp230*tmp39*tmp405*tmp410*tmp483*tmp657*tmp769+tmp407*tmp478*(2.*tmp111*tmp13*tmp150*tmp193*tmp68+0.5*tmp210*tmp414*tmp681-tmp111*tmp13*tmp150*tmp193*tmp70+tmp13*tmp184*tmp185*tmp193*tmp67*tmp70-2.*tmp150*tmp193*tmp67*tmp7*tmp70+tmp461*(tmp167*tmp230*tmp667-2.*tmp111*tmp193*tmp67*tmp673-tmp167*tmp230*tmp679+tmp193*tmp70*(-(tmp111*tmp13*tmp150)+tmp111*tmp13*tmp144*tmp150*tmp40*tmp655+tmp13*tmp184*tmp185*tmp67-tmp119*tmp123*tmp13*tmp150*tmp40*tmp655*tmp67-tmp13*tmp144*tmp184*tmp185*tmp40*tmp655*tmp67-2.*tmp150*tmp67*tmp7+2.*tmp13*tmp144*tmp150*tmp655*tmp67*tmp7+2.*tmp144*tmp150*tmp40*tmp655*tmp67*tmp7+tmp13*tmp144*tmp150*tmp40*tmp67*tmp704)+tmp180*tmp230*tmp739-tmp180*tmp230*tmp769)))-0.5*tmp230*tmp39*tmp405*tmp410*tmp462*tmp483*tmp660*(0.5*tmp522*tmp525*tmp577+tmp474*tmp637-4.*tmp115*tmp7-2.*eta*tmp4*tmp55*tmp63*tmp94)+0.25*tmp230*tmp39*tmp405*tmp410*tmp462*tmp483*tmp663*(4.*tmp201*tmp254*tmp4*tmp63*tmp7+2.*eta*tmp115*tmp201*tmp249*tmp256*tmp55*tmp94)*(1.0/sqrt(tmp659*tmp659*tmp659))))+(0.5*tmp153*tmp210)/sqrt(tmp217)))/sqrt(1.+2.*eta*(-1.+tmp153*tmp221+2.*tmp14*tmp144*tmp39*tmp4+2.*tmp14*tmp144*tmp230*tmp419+tmp144*tmp154*tmp230*tmp39*tmp405*tmp412*tmp414*tmp419+0.5*tmp123*tmp154*tmp414*tmp429*tmp435*tmp459*tmp474*tmp489*tmp581*tmp617-2.*tmp115*tmp123*tmp231*tmp414*tmp429*tmp435*tmp458*tmp459*tmp487*tmp489*tmp63*tmp67+tmp147*tmp150*tmp151*tmp154*tmp410*tmp53*tmp690*tmp692+coeffs->dheffSSv2*eta*tmp5*(s1Vec->data[0]*s1Vec->data[0]+s1Vec->data[1]*s1Vec->data[1]+s1Vec->data[2]*s1Vec->data[2]+s2Vec->data[0]*s2Vec->data[0]+s2Vec->data[1]*s2Vec->data[1]+s2Vec->data[2]*s2Vec->data[2])-0.5*tmp51*(tmp372*tmp372+tmp386*tmp386+tmp400*tmp400-3.*(tmp454*tmp454))));