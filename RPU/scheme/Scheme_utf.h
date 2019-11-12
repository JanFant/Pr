/* Определение внутренних параметров */
uspaint8 InternalBuf[183];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssbool lRM_0_ = {0,0}; /* A-Граница участка насыщения А */ 
ssbool lRM_1_ = {1,0}; /* B-Граница участка насыщения В */ 
sslong dRM_0_ = {0,0}; /* lx вход лонг */ 
sschar bRM_0_ = {0,0}; /* cx вход байтовый */ 
ssint iRM_0_ = {0,0}; /* ix вход целый */ 
ssint iRM_3200_ = {3200,0}; /* a */ 
ssint iRM_16000_ = {16000,0}; /* b */ 
sschar bRM_1_ = {1,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssfloat fRM_2_0 = {2.0,0}; /* Kpr1 - коэфф. преобразования частота->нейтр/с СНМ-11 */ 
ssint iRM_6_ = {6,0}; /* n - размерность массива значений */ 
ssfloat fRM_0_ = {0,0}; /* c */ 
ssfloat fRM_0_6 = {0.6,0}; /* d */ 
ssfloat fRM_1_2 = {1.2,0}; /* d */ 
ssint iRM_10_ = {10,0}; /* n - размерность массива мгновенных значений */ 

uspaint8 SpaEEPROMBuf[218];

/* Определение переменных */
ssfloat var1;
ssfloat var2;
ssfloat var3;
ssfloat var4;
ssfloat var5;
ssfloat var6;
ssfloat var7;
ssfloat var8;
ssfloat var9;
ssbool var10;
ssbool var11;
ssbool var12;
ssbool var13;
ssbool var14;
ssbool var15;
ssbool var16;
ssbool var17;
ssint var18;
ssfloat var19;
ssfloat var20;
ssbool var21;
ssfloat var22;
ssfloat var23;
ssfloat var24;
ssint var25;
ssbool var26;
ssbool var27;
ssbool var28;
ssbool var29;
ssbool var30;
ssbool var31;
ssbool var32;
ssbool var33;
ssbool var34;
ssbool var35;
sschar var36;
ssbool var37;
sschar var38;
ssbool var39;
ssbool var40;
ssbool var41;
ssbool var42;
ssbool var43;
ssfloat var44;
ssfloat var45;
sschar var46;
ssbool var47;
ssbool var48;
sschar var49;
ssbool var50;
ssbool var51;
ssbool var52;
ssbool var53;
ssbool var54;
ssbool var55;
ssbool var56;
ssbool var57;
ssbool var58;
ssbool var59;
ssbool var60;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psfloat  array_m178_x0_1[10];
psfloat  array_m177_x0_1[10];
psbool  array_m145_x_1[6] = {&var12,&var13,&R0DE36LRP,&R0DE37LRP,&R0DE38LRP,&R0DE39LRP};
psint  array_m127_x_1[6] = {&R0DE01LRP,&R0DE02LRP,&R0DE03LRP,&R0DE08LRP,&R0DE06LRP,&R0DE07LRP};

/* Объявление структур */
_S_ffiltr  S_ffiltr_178_1 = {&R0IN03VRP,&fEM_R7UY42RSS,&fEM_R7UY32RSS,&fEM_R7UY22RSS,&iEM_R7UY12RSS,&iRM_10_,&var1,&internal1_m178_xptr,&internal1_m178_stepc,array_m178_x0_1,&internal1_m178_flst,&internal1_m178_SumS,&bFirstEnterFlag};
_S_ffiltr  S_ffiltr_177_1 = {&R0IN02VRP,&fEM_R7UY42RSS,&fEM_R7UY32RSS,&fEM_R7UY22RSS,&iEM_R7UY12RSS,&iRM_10_,&var2,&internal1_m177_xptr,&internal1_m177_stepc,array_m177_x0_1,&internal1_m177_flst,&internal1_m177_SumS,&bFirstEnterFlag};
_S_scalzz  S_scalzz_193_1 = {&VMETRP12,&iRM_3200_,&iRM_16000_,&fRM_0_,&fRM_1_2,&var3,&internal1_m193_y0};
_S_scalzz  S_scalzz_192_1 = {&VMETRP06,&iRM_3200_,&iRM_16000_,&fRM_0_,&fRM_0_6,&var4,&internal1_m192_y0};
_S_pogrvh  S_pogrvh_179_1 = {&R0IN07VRP,&fEM_R0IN71NRP,&fEM_R0IN72NRP,&var5};
_S_pogrvh  S_pogrvh_165_1 = {&R0IN06VRP,&fEM_R0IN61NRP,&fEM_R0IN62NRP,&var6};
_S_pogrvh  S_pogrvh_163_1 = {&R0IN03VRP,&fEM_R0IN31NRP,&fEM_R0IN32NRP,&var7};
_S_pogrvh  S_pogrvh_161_1 = {&R0IN02VRP,&fEM_R0IN21NRP,&fEM_R0IN22NRP,&var8};
_S_pogrvh  S_pogrvh_159_1 = {&R0IN01VRP,&fEM_R0IN11NRP,&fEM_R0IN12NRP,&var9};
_S_or4  S_or4_60_1 = {&var52,&var26,&var34,&var35,&var10};
_S_noto  S_noto_146_1 = {&var14,&vainSBool};
_S_and5  S_and5_36_1 = {&lRM_1_,&R0IE11LRP,&R0IE12LRP,&R0IE13LRP,&var21,&var11};
_S_or2  S_or2_140_1 = {&R0DEB1LRP,&R0DEB2LRP,&var12};
_S_or2  S_or2_147_1 = {&R0DEB3LRP,&R0DEB4LRP,&var13};
_S_or3  S_or3_144_1 = {&var17,&var16,&var15,&var14};
_S_orn  S_orn_145_1 = {array_m145_x_1,&iRM_6_,&var15};
_S_and2  S_and2_129_1 = {&R0DE31LRP,&R0DE32LRP,&var16};
_S_diagndev  S_diagndev_127_1 = {array_m127_x_1,&iRM_6_,&var17,&var18,&vainSFloat};
_S_ocham  S_ocham_11_1 = {&var9,&var8,&var7,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX13RSS,&fEM_B0UX03RSS,&fEM_A0UX14RSS,&fEM_B0UX04RSS,&fEM_A0UX15RSS,&fEM_B0UX05RSS,&fEM_R7UX13RSS,&fEM_R7UY13RSS,&fEM_R7UX14RSS,&fEM_R7UY14RSS,&fEM_R7UX15RSS,&fEM_R7UY15RSS,&bRM_1_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&fEM_R0UH21RSS,&fEM_R0UH22RSS,&fEM_R0UH23RSS,&var19,&var20,&var21,&var22,&var23,&var24,&var25,&internal1_m11_Nk};
_S_or2  S_or2_55_1 = {&A6IS11LRP,&B6IS11LRP,&vainSBool};
_S_or2  S_or2_83_1 = {&var59,&var60,&var26};
_S_or4  S_or4_41_1 = {&var33,&var31,&var32,&var29,&var27};
_S_or2  S_or2_88_1 = {&var58,&var47,&var28};
_S_or2  S_or2_114_1 = {&var30,&var28,&var29};
_S_or2  S_or2_84_1 = {&var57,&var50,&var30};
_S_and3  S_and3_37_1 = {&var11,&var43,&var37,&var31};
_S_and3  S_and3_44_1 = {&var41,&R0IE14LRP,&var53,&var32};
_S_and3  S_and3_43_1 = {&R0IE15LRP,&var41,&var54,&var33};
_S_and3  S_and3_50_1 = {&R0IE14LRP,&var41,&var56,&var34};
_S_and3  S_and3_49_1 = {&var55,&R0IE15LRP,&var41,&var35};
_S_geterr  S_geterr_47_1 = {&var6,&dRM_0_,&iRM_0_,&bRM_0_,&var36,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_noto  S_noto_68_1 = {&var42,&var37};
_S_geterr  S_geterr_46_1 = {&var5,&dRM_0_,&iRM_0_,&bRM_0_,&var38,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_zzfs  S_zzfs_59_1 = {&var40,&fEM_Z7UE20RRP,&var39,&internal1_m59_tx,&internal1_m59_y0};
_S_or3  S_or3_58_1 = {&A6IS11LRP,&B6IS11LRP,&R0EE02LDU,&var40};
_S_noto  S_noto_56_1 = {&var39,&var41};
_S_zzfs  S_zzfs_67_1 = {&R0EE02LDU,&fEM_Z7UE20RRP,&var42,&internal1_m67_tx,&internal1_m67_y0};
_S_bol  S_bol_34_1 = {&var20,&fEM_R0UL52RSS,&var43};
_S_scalzz  S_scalzz_75_1 = {&B0IT03IRP,&iRM_3200_,&iRM_16000_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var44,&internal1_m75_y0};
_S_scalzz  S_scalzz_73_1 = {&A0IT03IRP,&iRM_3200_,&iRM_16000_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var45,&internal1_m73_y0};
_S_geterr  S_geterr_77_1 = {&var45,&dRM_0_,&iRM_0_,&bRM_0_,&var46,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_89_1 = {&var44,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var47,&internal1_m89_y1};
_S_drg  S_drg_104_1 = {&var44,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var48,&internal1_m104_y1};
_S_geterr  S_geterr_79_1 = {&var44,&dRM_0_,&iRM_0_,&bRM_0_,&var49,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_87_1 = {&var45,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var50,&internal1_m87_y1};
_S_drg  S_drg_102_1 = {&var45,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var51,&internal1_m102_y1};
_S_noto  S_noto_64_1 = {&var11,&var52};
_S_bol  S_bol_51_1 = {&var5,&fEM_R0UR01RRP,&var53};
_S_bol  S_bol_42_1 = {&var6,&fEM_R0UR01RRP,&var54};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  scalzz(&S_scalzz_73_1);
  scalzz(&S_scalzz_75_1);
  or2(&S_or2_55_1);
  diagndev(&S_diagndev_127_1);
  and2(&S_and2_129_1);
  or2(&S_or2_147_1);
  or2(&S_or2_140_1);
  scalzz(&S_scalzz_193_1);
  ffiltr(&S_ffiltr_178_1);
  drg(&S_drg_102_1);
  drg(&S_drg_87_1);
  geterr(&S_geterr_79_1);
  drg(&S_drg_104_1);
  drg(&S_drg_89_1);
  geterr(&S_geterr_77_1);
  zzfs(&S_zzfs_67_1);
  or3(&S_or3_58_1);
  zzfs(&S_zzfs_59_1);
  noto(&S_noto_68_1);
  setData(&var57,&var46);
  or2(&S_or2_84_1);
  setData(&var58,&var49);
  or2(&S_or2_88_1);
  setData(&var59,&var46);
  setData(&var60,&var49);
  or2(&S_or2_83_1);
  orn(&S_orn_145_1);
  or3(&S_or3_144_1);
  noto(&S_noto_146_1);
  pogrvh(&S_pogrvh_159_1);
  pogrvh(&S_pogrvh_161_1);
  pogrvh(&S_pogrvh_163_1);
  pogrvh(&S_pogrvh_165_1);
  pogrvh(&S_pogrvh_179_1);
  scalzz(&S_scalzz_192_1);
  ffiltr(&S_ffiltr_177_1);
  bol(&S_bol_42_1);
  bol(&S_bol_51_1);
  noto(&S_noto_56_1);
  geterr(&S_geterr_46_1);
  geterr(&S_geterr_47_1);
  setData(&var55,&var38);
  and3(&S_and3_49_1);
  setData(&var56,&var36);
  and3(&S_and3_50_1);
  and3(&S_and3_43_1);
  and3(&S_and3_44_1);
  or2(&S_or2_114_1);
  ocham(&S_ocham_11_1);
  and5(&S_and5_36_1);
  noto(&S_noto_64_1);
  bol(&S_bol_34_1);
  and3(&S_and3_37_1);
  or4(&S_or4_41_1);
  or4(&S_or4_60_1);
  setData(idMETRP12,&var3);
  setData(idMETRP06,&var4);
  moveData(idB1VS21LRP,idB1IS21LRP);
  moveData(idA1VS21LRP,idA1IS21LRP);
  setData(idTTLrpu,&var18);
  setData(idTestDiagnRPU,&var14);
  setData(idR0DE3DLRP,&var13);
  setData(idR0DE3CLRP,&var12);
  moveData(idB7MZ31LRP,idC1MZ31LRP);
  moveData(idA7MZ31LRP,idC1MZ31LRP);
  moveData(idB3VS21LRP,idB3IS21LRP);
  moveData(idA3VS21LRP,idA3IS21LRP);
  moveData(idB2VS21LRP,idB2IS21LRP);
  moveData(idA2VS21LRP,idA2IS21LRP);
  setData(idR7VE70LRP,&var10);
  setData(idR0VN13RRP,&var22);
  setData(idR0VN71LRP,&var43);
  setData(idA1VT71LRP,&var29);
  setData(idR0IE04LRP,&var39);
  setData(idR0IE03LRP,&var39);
  setData(idA0EE01LRP,&var11);
  setData(idB0VT71LRP,&var28);
  setData(idB0VT61LRP,&var48);
  setData(idB0CT01IRP,&var44);
  setData(idR0ET02LRP,&var49);
  setData(idR0ET01LRP,&var46);
  setData(idA0VT71LRP,&var30);
  setData(idA0VT61LRP,&var51);
  setData(idA0CT01IRP,&var45);
  setData(idR0IN07RRP,&var5);
  setData(idR7VN71LRP,&var27);
  setData(idR0IN06RRP,&var6);
  setData(idR0IE02LRP,&var42);
  setData(idR0IE01LRP,&var42);
  setData(idR0VN15RRP,&var25);
  setData(idR0VN33RRP,&var24);
  setData(idR0VN23RRP,&var23);
  setData(idA0EE02LRP,&var21);
  setData(idR0IN03RRP,&var1);
  setData(idR0VN03RRP,&var19);
  setData(idR0IN02RRP,&var2);
  setData(idR0IN01RRP,&var9);
  setData(idR0VN02RRP,&var20);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
  for( i=0;i<10;i++ )
    array_m178_x0_1[i] = &(&internal1_m178_x0)[i];
  for( i=0;i<10;i++ )
    array_m177_x0_1[i] = &(&internal1_m177_x0)[i];
}
