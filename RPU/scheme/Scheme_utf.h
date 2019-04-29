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
ssfloat fRM_0_0009765625 = {0.0009765625,0}; /* k - коэффициент усиления */ 

uspaint8 SpaEEPROMBuf[135];

/* Определение переменных */
ssbool var1;
ssbool var2;
ssbool var3;
ssfloat var4;
ssfloat var5;
ssfloat var6;
ssfloat var7;
ssfloat var8;
ssint var9;
ssbool var10;
ssbool var11;
ssbool var12;
ssbool var13;
ssbool var14;
ssbool var15;
ssint var16;
ssfloat var17;
ssfloat var18;
ssbool var19;
ssfloat var20;
ssfloat var21;
ssfloat var22;
ssint var23;
ssbool var24;
ssbool var25;
ssbool var26;
ssbool var27;
ssbool var28;
ssbool var29;
ssbool var30;
ssbool var31;
ssbool var32;
ssbool var33;
sschar var34;
ssbool var35;
sschar var36;
ssbool var37;
ssbool var38;
ssbool var39;
ssbool var40;
ssbool var41;
ssfloat var42;
ssfloat var43;
sschar var44;
ssbool var45;
ssbool var46;
sschar var47;
ssbool var48;
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
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psfloat  array_m59_x_1[2] = {&R0IN07RRP,&R0IN07RIP};
psfloat  array_m50_x_1[2] = {&R0IN06RRP,&R0IN06RIP};
psfloat  array_m9_x_1[2] = {&R0IN03RRP,&R0IN03RIP};
psfloat  array_m8_x_1[2] = {&R0IN02RRP,&R0IN02RIP};
psfloat  array_m7_x_1[2] = {&R0IN01RRP,&R0IN01RIP};
psbool  array_m159_x_1[6] = {&var10,&var11,&R0DE36LRP,&R0DE37LRP,&R0DE38LRP,&R0DE39LRP};
psint  array_m141_x_1[6] = {&R0DE01LRP,&R0DE02LRP,&R0DE03LRP,&R0DE08LRP,&R0DE06LRP,&R0DE07LRP};

/* Объявление структур */
_S_or4  S_or4_74_1 = {&var50,&var24,&var32,&var33,&var1};
_S_noto  S_noto_160_1 = {&var12,&var2};
_S_and5  S_and5_44_1 = {&var2,&R0IE11LRP,&R0IE12LRP,&R0IE13LRP,&var19,&var3};
_S_ma  S_ma_59_1 = {array_m59_x_1,&var9,&iRM_2_,&var4};
_S_ma  S_ma_50_1 = {array_m50_x_1,&var9,&iRM_2_,&var5};
_S_ma  S_ma_9_1 = {array_m9_x_1,&var9,&iRM_2_,&var6};
_S_ma  S_ma_8_1 = {array_m8_x_1,&var9,&iRM_2_,&var7};
_S_ma  S_ma_7_1 = {array_m7_x_1,&var9,&iRM_2_,&var8};
_S_fsumz  S_fsumz_2_1 = {&R0IS01FI0,&iRM_1_,&var9};
_S_or2  S_or2_154_1 = {&R0DEB1LRP,&R0DEB2LRP,&var10};
_S_or2  S_or2_161_1 = {&R0DEB3LRP,&R0DEB4LRP,&var11};
_S_or3  S_or3_158_1 = {&var15,&var14,&var13,&var12};
_S_orn  S_orn_159_1 = {array_m159_x_1,&iRM_6_,&var13};
_S_and2  S_and2_143_1 = {&R0DE31LRP,&R0DE32LRP,&var14};
_S_diagndev  S_diagndev_141_1 = {array_m141_x_1,&iRM_6_,&var15,&var16};
_S_ocham  S_ocham_22_1 = {&var8,&var7,&var6,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX13RSS,&fEM_B0UX03RSS,&fEM_A0UX14RSS,&fEM_B0UX04RSS,&fEM_A0UX15RSS,&fEM_B0UX05RSS,&fEM_R7UX13RSS,&fEM_R7UY13RSS,&fEM_R7UX14RSS,&fEM_R7UY14RSS,&fEM_R7UX15RSS,&fEM_R7UY15RSS,&bRM_1_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&var17,&var18,&var19,&var20,&var21,&var22,&var23,&internal1_m22_Nk};
_S_or2  S_or2_69_1 = {&A6IS11LRP,&B6IS11LRP,&vainSBool};
_S_or2  S_or2_97_1 = {&var57,&var58,&var24};
_S_or4  S_or4_49_1 = {&var31,&var29,&var30,&var27,&var25};
_S_or2  S_or2_102_1 = {&var56,&var45,&var26};
_S_or2  S_or2_126_1 = {&var28,&var26,&var27};
_S_or2  S_or2_98_1 = {&var55,&var48,&var28};
_S_and3  S_and3_45_1 = {&var3,&var41,&var35,&var29};
_S_and3  S_and3_53_1 = {&var39,&R0IE14LRP,&var51,&var30};
_S_and3  S_and3_52_1 = {&R0IE15LRP,&var39,&var52,&var31};
_S_and3  S_and3_62_1 = {&R0IE14LRP,&var39,&var54,&var32};
_S_and3  S_and3_61_1 = {&var53,&R0IE15LRP,&var39,&var33};
_S_geterr  S_geterr_58_1 = {&var5,&dRM_0_,&iRM_0_,&bRM_0_,&var34,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_noto  S_noto_82_1 = {&var40,&var35};
_S_geterr  S_geterr_57_1 = {&var4,&dRM_0_,&iRM_0_,&bRM_0_,&var36,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_zzfs  S_zzfs_73_1 = {&var38,&fEM_Z7UE20RRP,&var37,&internal1_m73_tx,&internal1_m73_y0};
_S_or3  S_or3_72_1 = {&A6IS11LRP,&B6IS11LRP,&R0EE02LDU,&var38};
_S_noto  S_noto_70_1 = {&var37,&var39};
_S_zzfs  S_zzfs_81_1 = {&R0EE02LDU,&fEM_Z7UE20RRP,&var40,&internal1_m81_tx,&internal1_m81_y0};
_S_bol  S_bol_43_1 = {&var18,&fEM_R0UL52RSS,&var41};
_S_scalzz  S_scalzz_89_1 = {&B0IT03IRP,&iRM_3276_,&iRM_16383_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var42,&internal1_m89_y0};
_S_scalzz  S_scalzz_87_1 = {&A0IT03IRP,&iRM_3276_,&iRM_16383_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var43,&internal1_m87_y0};
_S_geterr  S_geterr_91_1 = {&var43,&dRM_0_,&iRM_0_,&bRM_0_,&var44,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_103_1 = {&var42,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var45,&internal1_m103_y1};
_S_drg  S_drg_118_1 = {&var42,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var46,&internal1_m118_y1};
_S_geterr  S_geterr_93_1 = {&var42,&dRM_0_,&iRM_0_,&bRM_0_,&var47,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_101_1 = {&var43,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var48,&internal1_m101_y1};
_S_drg  S_drg_115_1 = {&var43,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var49,&internal1_m115_y1};
_S_noto  S_noto_78_1 = {&var3,&var50};
_S_bol  S_bol_63_1 = {&var4,&fEM_R0UR01RRP,&var51};
_S_bol  S_bol_51_1 = {&var5,&fEM_R0UR01RRP,&var52};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  scalzz(&S_scalzz_87_1);
  scalzz(&S_scalzz_89_1);
  or2(&S_or2_69_1);
  diagndev(&S_diagndev_141_1);
  and2(&S_and2_143_1);
  or2(&S_or2_161_1);
  or2(&S_or2_154_1);
  fsumz(&S_fsumz_2_1);
  ma(&S_ma_7_1);
  ma(&S_ma_8_1);
  ma(&S_ma_9_1);
  ma(&S_ma_59_1);
  bol(&S_bol_63_1);
  drg(&S_drg_115_1);
  drg(&S_drg_101_1);
  geterr(&S_geterr_93_1);
  drg(&S_drg_118_1);
  drg(&S_drg_103_1);
  geterr(&S_geterr_91_1);
  zzfs(&S_zzfs_81_1);
  or3(&S_or3_72_1);
  zzfs(&S_zzfs_73_1);
  geterr(&S_geterr_57_1);
  noto(&S_noto_82_1);
  setData(&var55,&var44);
  or2(&S_or2_98_1);
  setData(&var56,&var47);
  or2(&S_or2_102_1);
  setData(&var57,&var44);
  setData(&var58,&var47);
  or2(&S_or2_97_1);
  ocham(&S_ocham_22_1);
  orn(&S_orn_159_1);
  or3(&S_or3_158_1);
  ma(&S_ma_50_1);
  noto(&S_noto_160_1);
  bol(&S_bol_51_1);
  bol(&S_bol_43_1);
  noto(&S_noto_70_1);
  geterr(&S_geterr_58_1);
  setData(&var53,&var36);
  and3(&S_and3_61_1);
  setData(&var54,&var34);
  and3(&S_and3_62_1);
  and3(&S_and3_52_1);
  and3(&S_and3_53_1);
  or2(&S_or2_126_1);
  and5(&S_and5_44_1);
  noto(&S_noto_78_1);
  and3(&S_and3_45_1);
  or4(&S_or4_49_1);
  or4(&S_or4_74_1);
  moveData(idB1VS21LRP,idB1IS21LRP);
  moveData(idA1VS21LRP,idA1IS21LRP);
  setData(idTTLrpu,&var16);
  setData(idTestDiagnRPU,&var12);
  setData(idR0DE3DLRP,&var11);
  setData(idR0DE3CLRP,&var10);
  moveData(idB7MZ31LRP,idC1MZ31LRP);
  moveData(idA7MZ31LRP,idC1MZ31LRP);
  moveData(idB3VS21LRP,idB3IS21LRP);
  moveData(idA3VS21LRP,idA3IS21LRP);
  moveData(idB2VS21LRP,idB2IS21LRP);
  moveData(idA2VS21LRP,idA2IS21LRP);
  setData(idR7VE70LRP,&var1);
  setData(idR0VN13RRP,&var20);
  setData(idR0VN71LRP,&var41);
  setData(idA1VT71LRP,&var27);
  setData(idR0IE04LRP,&var37);
  setData(idR0IE03LRP,&var37);
  setData(idA0EE01LRP,&var3);
  setData(idB0VT71LRP,&var26);
  setData(idB0VT61LRP,&var46);
  setData(idB0CT01IRP,&var42);
  setData(idR0ET02LRP,&var47);
  setData(idR0ET01LRP,&var44);
  setData(idA0VT71LRP,&var28);
  setData(idA0VT61LRP,&var49);
  setData(idA0CT01IRP,&var43);
  setData(idR7VN71LRP,&var25);
  setData(idR0IE02LRP,&var40);
  setData(idR0IE01LRP,&var40);
  setData(idR0VN15RRP,&var23);
  setData(idR0VN33RRP,&var22);
  setData(idR0VN23RRP,&var21);
  setData(idA0EE02LRP,&var19);
  setData(idR0VN03RRP,&var17);
  setData(idR0VN02RRP,&var18);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}
