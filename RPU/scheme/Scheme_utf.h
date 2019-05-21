/* Определение внутренних параметров */
uspaint8 InternalBuf[40];

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

uspaint8 SpaEEPROMBuf[135];

/* Определение переменных */
ssfloat var1;
ssfloat var2;
ssfloat var3;
ssfloat var4;
ssfloat var5;
ssbool var6;
ssbool var7;
ssbool var8;
ssbool var9;
ssbool var10;
ssbool var11;
ssbool var12;
ssbool var13;
ssbool var14;
ssint var15;
ssfloat var16;
ssfloat var17;
ssbool var18;
ssfloat var19;
ssfloat var20;
ssfloat var21;
ssint var22;
ssbool var23;
ssbool var24;
ssbool var25;
ssbool var26;
ssbool var27;
ssbool var28;
ssbool var29;
ssbool var30;
ssbool var31;
ssbool var32;
sschar var33;
ssbool var34;
sschar var35;
ssbool var36;
ssbool var37;
ssbool var38;
ssbool var39;
ssbool var40;
ssfloat var41;
ssfloat var42;
sschar var43;
ssbool var44;
ssbool var45;
sschar var46;
ssbool var47;
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
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m158_x_1[6] = {&var9,&var10,&R0DE36LRP,&R0DE37LRP,&R0DE38LRP,&R0DE39LRP};
psint  array_m140_x_1[6] = {&R0DE01LRP,&R0DE02LRP,&R0DE03LRP,&R0DE08LRP,&R0DE06LRP,&R0DE07LRP};

/* Объявление структур */
_S_ml  S_ml_58_1 = {&R0IN07RIP,&R0IN07RRP,&R0IS01FI0,&var1};
_S_ml  S_ml_49_1 = {&R0IN06RIP,&R0IN06RRP,&R0IS01FI0,&var2};
_S_ml  S_ml_8_1 = {&R0IN03RIP,&R0IN03RRP,&R0IS01FI0,&var3};
_S_ml  S_ml_7_1 = {&R0IN02RIP,&R0IN02RRP,&R0IS01FI0,&var4};
_S_ml  S_ml_6_1 = {&R0IN01RIP,&R0IN01RRP,&R0IS01FI0,&var5};
_S_or4  S_or4_73_1 = {&var49,&var23,&var31,&var32,&var6};
_S_noto  S_noto_159_1 = {&var11,&var7};
_S_and5  S_and5_43_1 = {&var7,&R0IE11LRP,&R0IE12LRP,&R0IE13LRP,&var18,&var8};
_S_or2  S_or2_153_1 = {&R0DEB1LRP,&R0DEB2LRP,&var9};
_S_or2  S_or2_160_1 = {&R0DEB3LRP,&R0DEB4LRP,&var10};
_S_or3  S_or3_157_1 = {&var14,&var13,&var12,&var11};
_S_orn  S_orn_158_1 = {array_m158_x_1,&iRM_6_,&var12};
_S_and2  S_and2_142_1 = {&R0DE31LRP,&R0DE32LRP,&var13};
_S_diagndev  S_diagndev_140_1 = {array_m140_x_1,&iRM_6_,&var14,&var15,&vainSFloat,&internal1_m140_sttlf};
_S_ocham  S_ocham_21_1 = {&var5,&var4,&var3,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX13RSS,&fEM_B0UX03RSS,&fEM_A0UX14RSS,&fEM_B0UX04RSS,&fEM_A0UX15RSS,&fEM_B0UX05RSS,&fEM_R7UX13RSS,&fEM_R7UY13RSS,&fEM_R7UX14RSS,&fEM_R7UY14RSS,&fEM_R7UX15RSS,&fEM_R7UY15RSS,&bRM_1_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&vainSFloat,&vainSFloat,&vainSFloat,&var16,&var17,&var18,&var19,&var20,&var21,&var22,&internal1_m21_Nk};
_S_or2  S_or2_68_1 = {&A6IS11LRP,&B6IS11LRP,&vainSBool};
_S_or2  S_or2_96_1 = {&var56,&var57,&var23};
_S_or4  S_or4_48_1 = {&var30,&var28,&var29,&var26,&var24};
_S_or2  S_or2_101_1 = {&var55,&var44,&var25};
_S_or2  S_or2_127_1 = {&var27,&var25,&var26};
_S_or2  S_or2_97_1 = {&var54,&var47,&var27};
_S_and3  S_and3_44_1 = {&var8,&var40,&var34,&var28};
_S_and3  S_and3_52_1 = {&var38,&R0IE14LRP,&var50,&var29};
_S_and3  S_and3_51_1 = {&R0IE15LRP,&var38,&var51,&var30};
_S_and3  S_and3_61_1 = {&R0IE14LRP,&var38,&var53,&var31};
_S_and3  S_and3_60_1 = {&var52,&R0IE15LRP,&var38,&var32};
_S_geterr  S_geterr_57_1 = {&var2,&dRM_0_,&iRM_0_,&bRM_0_,&var33,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_noto  S_noto_81_1 = {&var39,&var34};
_S_geterr  S_geterr_56_1 = {&var1,&dRM_0_,&iRM_0_,&bRM_0_,&var35,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_zzfs  S_zzfs_72_1 = {&var37,&fEM_Z7UE20RRP,&var36,&internal1_m72_tx,&internal1_m72_y0};
_S_or3  S_or3_71_1 = {&A6IS11LRP,&B6IS11LRP,&R0EE02LDU,&var37};
_S_noto  S_noto_69_1 = {&var36,&var38};
_S_zzfs  S_zzfs_80_1 = {&R0EE02LDU,&fEM_Z7UE20RRP,&var39,&internal1_m80_tx,&internal1_m80_y0};
_S_bol  S_bol_42_1 = {&var17,&fEM_R0UL52RSS,&var40};
_S_scalzz  S_scalzz_88_1 = {&B0IT03IRP,&iRM_3276_,&iRM_16383_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var41,&internal1_m88_y0};
_S_scalzz  S_scalzz_86_1 = {&A0IT03IRP,&iRM_3276_,&iRM_16383_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var42,&internal1_m86_y0};
_S_geterr  S_geterr_90_1 = {&var42,&dRM_0_,&iRM_0_,&bRM_0_,&var43,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_102_1 = {&var41,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var44,&internal1_m102_y1};
_S_drg  S_drg_117_1 = {&var41,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var45,&internal1_m117_y1};
_S_geterr  S_geterr_92_1 = {&var41,&dRM_0_,&iRM_0_,&bRM_0_,&var46,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_100_1 = {&var42,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var47,&internal1_m100_y1};
_S_drg  S_drg_115_1 = {&var42,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var48,&internal1_m115_y1};
_S_noto  S_noto_77_1 = {&var8,&var49};
_S_bol  S_bol_62_1 = {&var1,&fEM_R0UR01RRP,&var50};
_S_bol  S_bol_50_1 = {&var2,&fEM_R0UR01RRP,&var51};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  scalzz(&S_scalzz_86_1);
  scalzz(&S_scalzz_88_1);
  or2(&S_or2_68_1);
  diagndev(&S_diagndev_140_1);
  and2(&S_and2_142_1);
  or2(&S_or2_160_1);
  or2(&S_or2_153_1);
  ml(&S_ml_6_1);
  ml(&S_ml_7_1);
  ml(&S_ml_8_1);
  ml(&S_ml_49_1);
  ml(&S_ml_58_1);
  bol(&S_bol_50_1);
  bol(&S_bol_62_1);
  drg(&S_drg_115_1);
  drg(&S_drg_100_1);
  geterr(&S_geterr_92_1);
  drg(&S_drg_117_1);
  drg(&S_drg_102_1);
  geterr(&S_geterr_90_1);
  zzfs(&S_zzfs_80_1);
  or3(&S_or3_71_1);
  zzfs(&S_zzfs_72_1);
  geterr(&S_geterr_56_1);
  noto(&S_noto_81_1);
  geterr(&S_geterr_57_1);
  setData(&var54,&var43);
  or2(&S_or2_97_1);
  setData(&var55,&var46);
  or2(&S_or2_101_1);
  setData(&var56,&var43);
  setData(&var57,&var46);
  or2(&S_or2_96_1);
  ocham(&S_ocham_21_1);
  orn(&S_orn_158_1);
  or3(&S_or3_157_1);
  noto(&S_noto_159_1);
  bol(&S_bol_42_1);
  noto(&S_noto_69_1);
  setData(&var52,&var35);
  and3(&S_and3_60_1);
  setData(&var53,&var33);
  and3(&S_and3_61_1);
  and3(&S_and3_51_1);
  and3(&S_and3_52_1);
  or2(&S_or2_127_1);
  and5(&S_and5_43_1);
  noto(&S_noto_77_1);
  and3(&S_and3_44_1);
  or4(&S_or4_48_1);
  or4(&S_or4_73_1);
  moveData(idB1VS21LRP,idB1IS21LRP);
  moveData(idA1VS21LRP,idA1IS21LRP);
  setData(idTTLrpu,&var15);
  setData(idTestDiagnRPU,&var11);
  setData(idR0DE3DLRP,&var10);
  setData(idR0DE3CLRP,&var9);
  moveData(idB7MZ31LRP,idC1MZ31LRP);
  moveData(idA7MZ31LRP,idC1MZ31LRP);
  moveData(idB3VS21LRP,idB3IS21LRP);
  moveData(idA3VS21LRP,idA3IS21LRP);
  moveData(idB2VS21LRP,idB2IS21LRP);
  moveData(idA2VS21LRP,idA2IS21LRP);
  setData(idR7VE70LRP,&var6);
  setData(idR0VN13RRP,&var19);
  setData(idR0VN71LRP,&var40);
  setData(idA1VT71LRP,&var26);
  setData(idR0IE04LRP,&var36);
  setData(idR0IE03LRP,&var36);
  setData(idA0EE01LRP,&var8);
  setData(idB0VT71LRP,&var25);
  setData(idB0VT61LRP,&var45);
  setData(idB0CT01IRP,&var41);
  setData(idR0ET02LRP,&var46);
  setData(idR0ET01LRP,&var43);
  setData(idA0VT71LRP,&var27);
  setData(idA0VT61LRP,&var48);
  setData(idA0CT01IRP,&var42);
  setData(idR7VN71LRP,&var24);
  setData(idR0IE02LRP,&var39);
  setData(idR0IE01LRP,&var39);
  setData(idR0VN15RRP,&var22);
  setData(idR0VN33RRP,&var21);
  setData(idR0VN23RRP,&var20);
  setData(idA0EE02LRP,&var18);
  setData(idR0VN03RRP,&var16);
  setData(idR0VN02RRP,&var17);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}
