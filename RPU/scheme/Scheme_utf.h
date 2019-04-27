/* Определение внутренних параметров */
uspaint8 InternalBuf[37];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssbool lRM_0_ = {0,0}; /* A-Граница участка насыщения А */ 
ssbool lRM_1_ = {1,0}; /* B-Граница участка насыщения В */ 
sslong dRM_0_ = {0,0}; /* lx вход лонг */ 
sschar bRM_0_ = {0,0}; /* cx вход байтовый */ 
ssint iRM_0_ = {0,0}; /* ix вход целый */ 
ssint iRM_3276_ = {3276,0}; /* a */ 
ssint iRM_16383_ = {16383,0}; /* b */ 
sschar bRM_1_ = {1,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssfloat fRM_2_0 = {2.0,0}; /* Kpr1 - коэфф. преобразования частота->нейтр/с СНМ-11 */ 
ssint iRM_6_ = {6,0}; /* n - размерность массива значений */ 
ssint iRM_2_ = {2,0}; /* n - N-размерность массива x */ 
ssint iRM_1_ = {1,0}; /* x2 - второе слагаемое */ 
ssfloat fRM_0_0009765625 = {0.0009765625,0}; /*  */ 

uspaint8 SpaEEPROMBuf[135];

/* Определение переменных */
ssfloat var1;
ssbool var2;
ssbool var3;
ssbool var4;
ssfloat var5;
ssfloat var6;
ssfloat var7;
ssfloat var8;
ssfloat var9;
ssint var10;
ssbool var11;
ssbool var12;
ssbool var13;
ssbool var14;
ssbool var15;
ssbool var16;
ssint var17;
ssfloat var18;
ssfloat var19;
ssbool var20;
ssfloat var21;
ssfloat var22;
ssfloat var23;
ssint var24;
ssbool var25;
ssbool var26;
ssbool var27;
ssbool var28;
ssbool var29;
ssbool var30;
ssbool var31;
ssbool var32;
ssbool var33;
ssbool var34;
sschar var35;
ssbool var36;
sschar var37;
ssbool var38;
ssbool var39;
ssbool var40;
ssbool var41;
ssbool var42;
ssfloat var43;
ssfloat var44;
sschar var45;
ssbool var46;
ssbool var47;
sschar var48;
ssbool var49;
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
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psfloat  array_m61_x_1[2] = {&R0IN07RRP,&R0IN07RIP};
psfloat  array_m52_x_1[2] = {&R0IN06RRP,&R0IN06RIP};
psfloat  array_m9_x_1[2] = {&R0IN03RRP,&R0IN03RIP};
psfloat  array_m8_x_1[2] = {&R0IN02RRP,&R0IN02RIP};
psfloat  array_m7_x_1[2] = {&R0IN01RRP,&R0IN01RIP};
psbool  array_m161_x_1[6] = {&var11,&var12,&R0DE36LRP,&R0DE37LRP,&R0DE38LRP,&R0DE39LRP};
psint  array_m143_x_1[6] = {&R0DE01LRP,&R0DE02LRP,&R0DE03LRP,&R0DE08LRP,&R0DE06LRP,&R0DE07LRP};

/* Объявление структур */
_S_ampll  S_ampll_31_1 = {&B8IC01UDU,&fRM_0_0009765625,&var1};
_S_or4  S_or4_76_1 = {&var51,&var25,&var33,&var34,&var2};
_S_noto  S_noto_162_1 = {&var13,&var3};
_S_and5  S_and5_46_1 = {&var3,&R0IE11LRP,&R0IE12LRP,&R0IE13LRP,&var20,&var4};
_S_ma  S_ma_61_1 = {array_m61_x_1,&var10,&iRM_2_,&var5};
_S_ma  S_ma_52_1 = {array_m52_x_1,&var10,&iRM_2_,&var6};
_S_ma  S_ma_9_1 = {array_m9_x_1,&var10,&iRM_2_,&var7};
_S_ma  S_ma_8_1 = {array_m8_x_1,&var10,&iRM_2_,&var8};
_S_ma  S_ma_7_1 = {array_m7_x_1,&var10,&iRM_2_,&var9};
_S_fsumz  S_fsumz_2_1 = {&R0IS01FI0,&iRM_1_,&var10};
_S_or2  S_or2_156_1 = {&R0DEB1LRP,&R0DEB2LRP,&var11};
_S_or2  S_or2_163_1 = {&R0DEB3LRP,&R0DEB4LRP,&var12};
_S_or3  S_or3_160_1 = {&var16,&var15,&var14,&var13};
_S_orn  S_orn_161_1 = {array_m161_x_1,&iRM_6_,&var14};
_S_and2  S_and2_145_1 = {&R0DE31LRP,&R0DE32LRP,&var15};
_S_diagndev  S_diagndev_143_1 = {array_m143_x_1,&iRM_6_,&var16,&var17};
_S_ocham  S_ocham_22_1 = {&var9,&var8,&var7,&var1,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX13RSS,&fEM_B0UX03RSS,&fEM_A0UX14RSS,&fEM_B0UX04RSS,&fEM_A0UX15RSS,&fEM_B0UX05RSS,&fEM_R7UX13RSS,&fEM_R7UY13RSS,&fEM_R7UX14RSS,&fEM_R7UY14RSS,&fEM_R7UX15RSS,&fEM_R7UY15RSS,&bRM_1_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&var18,&var19,&var20,&var21,&var22,&var23,&var24,&internal1_m22_Nk};
_S_or2  S_or2_71_1 = {&A6IS11LRP,&B6IS11LRP,&vainSBool};
_S_or2  S_or2_99_1 = {&var58,&var59,&var25};
_S_or4  S_or4_51_1 = {&var32,&var30,&var31,&var28,&var26};
_S_or2  S_or2_104_1 = {&var57,&var46,&var27};
_S_or2  S_or2_126_1 = {&var29,&var27,&var28};
_S_or2  S_or2_100_1 = {&var56,&var49,&var29};
_S_and3  S_and3_47_1 = {&var4,&var42,&var36,&var30};
_S_and3  S_and3_55_1 = {&var40,&R0IE14LRP,&var52,&var31};
_S_and3  S_and3_54_1 = {&R0IE15LRP,&var40,&var53,&var32};
_S_and3  S_and3_64_1 = {&R0IE14LRP,&var40,&var55,&var33};
_S_and3  S_and3_63_1 = {&var54,&R0IE15LRP,&var40,&var34};
_S_geterr  S_geterr_60_1 = {&var6,&dRM_0_,&iRM_0_,&bRM_0_,&var35,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_noto  S_noto_84_1 = {&var41,&var36};
_S_geterr  S_geterr_59_1 = {&var5,&dRM_0_,&iRM_0_,&bRM_0_,&var37,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_zzfs  S_zzfs_75_1 = {&var39,&fEM_Z7UE20RRP,&var38,&internal1_m75_tx,&internal1_m75_y0};
_S_or3  S_or3_74_1 = {&A6IS11LRP,&B6IS11LRP,&R0EE02LDU,&var39};
_S_noto  S_noto_72_1 = {&var38,&var40};
_S_zzfs  S_zzfs_83_1 = {&R0EE02LDU,&fEM_Z7UE20RRP,&var41,&internal1_m83_tx,&internal1_m83_y0};
_S_bol  S_bol_45_1 = {&var19,&fEM_R0UL52RSS,&var42};
_S_scalzz  S_scalzz_91_1 = {&B0IT03IRP,&iRM_3276_,&iRM_16383_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var43,&internal1_m91_y0};
_S_scalzz  S_scalzz_89_1 = {&A0IT03IRP,&iRM_3276_,&iRM_16383_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var44,&internal1_m89_y0};
_S_geterr  S_geterr_93_1 = {&var44,&dRM_0_,&iRM_0_,&bRM_0_,&var45,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_105_1 = {&var43,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var46,&internal1_m105_y1};
_S_drg  S_drg_120_1 = {&var43,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var47,&internal1_m120_y1};
_S_geterr  S_geterr_95_1 = {&var43,&dRM_0_,&iRM_0_,&bRM_0_,&var48,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_103_1 = {&var44,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var49,&internal1_m103_y1};
_S_drg  S_drg_118_1 = {&var44,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var50,&internal1_m118_y1};
_S_noto  S_noto_80_1 = {&var4,&var51};
_S_bol  S_bol_65_1 = {&var5,&fEM_R0UR01RRP,&var52};
_S_bol  S_bol_53_1 = {&var6,&fEM_R0UR01RRP,&var53};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  scalzz(&S_scalzz_89_1);
  scalzz(&S_scalzz_91_1);
  or2(&S_or2_71_1);
  diagndev(&S_diagndev_143_1);
  and2(&S_and2_145_1);
  or2(&S_or2_163_1);
  or2(&S_or2_156_1);
  fsumz(&S_fsumz_2_1);
  ma(&S_ma_7_1);
  ma(&S_ma_8_1);
  ma(&S_ma_9_1);
  ma(&S_ma_61_1);
  bol(&S_bol_65_1);
  drg(&S_drg_118_1);
  drg(&S_drg_103_1);
  geterr(&S_geterr_95_1);
  drg(&S_drg_120_1);
  drg(&S_drg_105_1);
  geterr(&S_geterr_93_1);
  zzfs(&S_zzfs_83_1);
  or3(&S_or3_74_1);
  zzfs(&S_zzfs_75_1);
  geterr(&S_geterr_59_1);
  noto(&S_noto_84_1);
  setData(&var56,&var45);
  or2(&S_or2_100_1);
  setData(&var57,&var48);
  or2(&S_or2_104_1);
  setData(&var58,&var45);
  setData(&var59,&var48);
  or2(&S_or2_99_1);
  orn(&S_orn_161_1);
  or3(&S_or3_160_1);
  ma(&S_ma_52_1);
  noto(&S_noto_162_1);
  ampll(&S_ampll_31_1);
  bol(&S_bol_53_1);
  noto(&S_noto_72_1);
  geterr(&S_geterr_60_1);
  setData(&var54,&var37);
  and3(&S_and3_63_1);
  setData(&var55,&var35);
  and3(&S_and3_64_1);
  and3(&S_and3_54_1);
  and3(&S_and3_55_1);
  or2(&S_or2_126_1);
  ocham(&S_ocham_22_1);
  and5(&S_and5_46_1);
  noto(&S_noto_80_1);
  bol(&S_bol_45_1);
  and3(&S_and3_47_1);
  or4(&S_or4_51_1);
  or4(&S_or4_76_1);
  moveData(idB1VS21LRP,idB1IS21LRP);
  moveData(idA1VS21LRP,idA1IS21LRP);
  setData(idTTLrpu,&var17);
  setData(idTestDiagnRPU,&var13);
  setData(idR0DE3DLRP,&var12);
  setData(idR0DE3CLRP,&var11);
  moveData(idB7MZ31LRP,idC1MZ31LRP);
  moveData(idA7MZ31LRP,idC1MZ31LRP);
  moveData(idB3VS21LRP,idB3IS21LRP);
  moveData(idA3VS21LRP,idA3IS21LRP);
  moveData(idB2VS21LRP,idB2IS21LRP);
  moveData(idA2VS21LRP,idA2IS21LRP);
  setData(idR7VE70LRP,&var2);
  setData(idR0VN13RRP,&var21);
  setData(idR0VN71LRP,&var42);
  setData(idA1VT71LRP,&var28);
  setData(idR0IE04LRP,&var38);
  setData(idR0IE03LRP,&var38);
  setData(idA0EE01LRP,&var4);
  setData(idB0VT71LRP,&var27);
  setData(idB0VT61LRP,&var47);
  setData(idB0CT01IRP,&var43);
  setData(idR0ET02LRP,&var48);
  setData(idR0ET01LRP,&var45);
  setData(idA0VT71LRP,&var29);
  setData(idA0VT61LRP,&var50);
  setData(idA0CT01IRP,&var44);
  setData(idR7VN71LRP,&var26);
  setData(idR0IE02LRP,&var41);
  setData(idR0IE01LRP,&var41);
  setData(idR0VN15RRP,&var24);
  setData(idR0VN33RRP,&var23);
  setData(idR0VN23RRP,&var22);
  setData(idA0EE02LRP,&var20);
  setData(idR0VN03RRP,&var18);
  setData(idR0VN02RRP,&var19);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}
