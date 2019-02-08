/* Определение внутренних параметров */
uspaint8 InternalBuf[37];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssbool lRM_0_ = {0,0}; /* A-Граница участка насыщения А */ 
ssbool lRM_1_ = {1,0}; /* B-Граница участка насыщения В */ 
sslong dRM_0_ = {0,0}; /* lx вход лонг */ 
sschar bRM_0_ = {0,0}; /* cx вход байтовый */ 
ssint iRM_0_ = {0,0}; /* ix вход целый */ 
ssint iRM_819_ = {819,0}; /* a */ 
ssint iRM_4095_ = {4095,0}; /* b */ 
sschar bRM_1_ = {1,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssfloat fRM_2_0 = {2.0,0}; /* Kpr1 - коэфф. преобразования частота->нейтр/с СНМ-11 */ 
ssint iRM_6_ = {6,0}; /*  */ 
ssint iRM_8_ = {8,0}; /*  */ 

uspaint8 SpaEEPROMBuf[135];

/* Определение переменных */
ssbool var1;
ssbool var2;
ssbool var3;
ssbool var4;
ssfloat var5;
ssfloat var6;
ssbool var7;
ssfloat var8;
ssfloat var9;
ssfloat var10;
ssint var11;
ssbool var12;
ssbool var13;
ssbool var14;
ssbool var15;
ssbool var16;
ssbool var17;
ssbool var18;
ssbool var19;
ssbool var20;
ssbool var21;
ssbool var22;
ssbool var23;
sschar var24;
ssbool var25;
sschar var26;
ssbool var27;
ssbool var28;
ssbool var29;
ssbool var30;
ssbool var31;
ssfloat var32;
ssfloat var33;
sschar var34;
ssbool var35;
ssbool var36;
sschar var37;
ssbool var38;
ssbool var39;
ssbool var40;
ssbool var41;
ssbool var42;
ssbool var43;
ssbool var44;
ssbool var45;
ssbool var46;
ssbool var47;
ssbool var48;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m145_x_1[8] = {&R0DE36LRP,&R0DE39LRP,&R0DE3CLRP,&R0DE37LRP,&R0DE3DLRP,&R0DE38LRP,&R0DE3BLRP,&R0DE3ALRP};
psint  array_m134_x_1[6] = {&R0DE01LRP,&R0DE02LRP,&R0DE03LRP,&R0DE08LRP,&R0DE06LRP,&R0DE07LRP};

/* Объявление структур */
_S_and3  S_and3_138_1 = {&var4,&var3,&var2,&var1};
_S_orn  S_orn_145_1 = {array_m145_x_1,&iRM_8_,&var2};
_S_and2  S_and2_133_1 = {&R0DE31LRP,&R0DE32LRP,&var3};
_S_diagndev  S_diagndev_134_1 = {array_m134_x_1,&iRM_6_,&var4};
_S_ocham  S_ocham_16_1 = {&R0IN01RRP,&R0IN02RRP,&R0IN03RRP,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX13RSS,&fEM_B0UX03RSS,&fEM_A0UX14RSS,&fEM_B0UX04RSS,&fEM_A0UX15RSS,&fEM_B0UX05RSS,&fEM_R7UX13RSS,&fEM_R7UY13RSS,&fEM_R7UX14RSS,&fEM_R7UY14RSS,&fEM_R7UX15RSS,&fEM_R7UY15RSS,&bRM_1_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&var5,&var6,&var7,&var8,&var9,&var10,&var11,&internal1_m16_Nk};
_S_or2  S_or2_57_1 = {&A6IS11LRP,&B6IS11LRP,&vainSBool};
_S_or5  S_or5_62_1 = {&var22,&var23,&A0EE03LRP,&var13,&var40,&var12};
_S_or2  S_or2_84_1 = {&var47,&var48,&var13};
_S_or4  S_or4_42_1 = {&var21,&var18,&var20,&var16,&var14};
_S_or2  S_or2_89_1 = {&var46,&var35,&var15};
_S_or2  S_or2_105_1 = {&var17,&var15,&var16};
_S_or2  S_or2_85_1 = {&var45,&var38,&var17};
_S_and3  S_and3_37_1 = {&var19,&var31,&var25,&var18};
_S_and4  S_and4_36_1 = {&R0IE11LRP,&var7,&R0IE12LRP,&R0IE13LRP,&var19};
_S_and3  S_and3_45_1 = {&var29,&R0IE14LRP,&var41,&var20};
_S_and3  S_and3_44_1 = {&R0IE15LRP,&var29,&var42,&var21};
_S_and3  S_and3_52_1 = {&R0IE14LRP,&var29,&var44,&var22};
_S_and3  S_and3_51_1 = {&var43,&R0IE15LRP,&var29,&var23};
_S_geterr  S_geterr_48_1 = {&R0IN06RRP,&dRM_0_,&iRM_0_,&bRM_0_,&var24,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_noto  S_noto_71_1 = {&var30,&var25};
_S_geterr  S_geterr_47_1 = {&R0IN07RRP,&dRM_0_,&iRM_0_,&bRM_0_,&var26,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_zzfs  S_zzfs_61_1 = {&var28,&fEM_Z7UE20RRP,&var27,&internal1_m61_tx,&internal1_m61_y0};
_S_or3  S_or3_60_1 = {&A6IS11LRP,&B6IS11LRP,&R0EE02LDU,&var28};
_S_noto  S_noto_58_1 = {&var27,&var29};
_S_zzfs  S_zzfs_70_1 = {&R0EE02LDU,&fEM_Z7UE20RRP,&var30,&internal1_m70_tx,&internal1_m70_y0};
_S_bol  S_bol_35_1 = {&var6,&fEM_R0UL52RSS,&var31};
_S_scalzz  S_scalzz_78_1 = {&B0IT03IRP,&iRM_819_,&iRM_4095_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var32,&internal1_m78_y0};
_S_scalzz  S_scalzz_76_1 = {&A0IT03IRP,&iRM_819_,&iRM_4095_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var33,&internal1_m76_y0};
_S_geterr  S_geterr_80_1 = {&var33,&dRM_0_,&iRM_0_,&bRM_0_,&var34,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_90_1 = {&var32,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var35,&internal1_m90_y1};
_S_drg  S_drg_101_1 = {&var32,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var36,&internal1_m101_y1};
_S_geterr  S_geterr_82_1 = {&var32,&dRM_0_,&iRM_0_,&bRM_0_,&var37,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_88_1 = {&var33,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var38,&internal1_m88_y1};
_S_drg  S_drg_99_1 = {&var33,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var39,&internal1_m99_y1};
_S_noto  S_noto_67_1 = {&var19,&var40};
_S_bol  S_bol_53_1 = {&R0IN07RRP,&fEM_R0UR01RRP,&var41};
_S_bol  S_bol_43_1 = {&R0IN06RRP,&fEM_R0UR01RRP,&var42};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  scalzz(&S_scalzz_76_1);
  scalzz(&S_scalzz_78_1);
  geterr(&S_geterr_47_1);
  geterr(&S_geterr_48_1);
  or2(&S_or2_57_1);
  ocham(&S_ocham_16_1);
  diagndev(&S_diagndev_134_1);
  and2(&S_and2_133_1);
  orn(&S_orn_145_1);
  and3(&S_and3_138_1);
  bol(&S_bol_43_1);
  bol(&S_bol_53_1);
  drg(&S_drg_99_1);
  drg(&S_drg_88_1);
  geterr(&S_geterr_82_1);
  drg(&S_drg_101_1);
  drg(&S_drg_90_1);
  geterr(&S_geterr_80_1);
  bol(&S_bol_35_1);
  zzfs(&S_zzfs_70_1);
  or3(&S_or3_60_1);
  zzfs(&S_zzfs_61_1);
  noto(&S_noto_71_1);
  and4(&S_and4_36_1);
  and3(&S_and3_37_1);
  setData(&var45,&var34);
  or2(&S_or2_85_1);
  setData(&var46,&var37);
  or2(&S_or2_89_1);
  setData(&var47,&var34);
  setData(&var48,&var37);
  or2(&S_or2_84_1);
  noto(&S_noto_67_1);
  noto(&S_noto_58_1);
  setData(&var43,&var26);
  and3(&S_and3_51_1);
  setData(&var44,&var24);
  and3(&S_and3_52_1);
  and3(&S_and3_44_1);
  and3(&S_and3_45_1);
  or2(&S_or2_105_1);
  or4(&S_or4_42_1);
  or5(&S_or5_62_1);
  setData(idTestDiagn4,&var1);
  setData(idTestDiagn3,&var2);
  setData(idTestDiagn2,&var3);
  setData(idTestDiagn1,&var4);
  moveData(idB7MZ31LRP,idC1MZ31LRP);
  moveData(idA7MZ31LRP,idC1MZ31LRP);
  moveData(idB3VS21LRP,idB3IS21LRP);
  moveData(idA3VS21LRP,idA3IS21LRP);
  moveData(idB2VS21LRP,idB2IS21LRP);
  moveData(idA2VS21LRP,idA2IS21LRP);
  moveData(idB1VS21LRP,idB1IS21LRP);
  moveData(idA1VS21LRP,idA1IS21LRP);
  setData(idR7VE70LRP,&var12);
  setData(idR0VN13RRP,&var8);
  setData(idR0VN71LRP,&var31);
  setData(idA1VT71LRP,&var16);
  setData(idR0IE04LRP,&var27);
  setData(idR0IE03LRP,&var27);
  setData(idA0EE01LRP,&var19);
  setData(idB0VT71LRP,&var15);
  setData(idB0VT61LRP,&var36);
  setData(idB0CT01IRP,&var32);
  setData(idR0ET02LRP,&var37);
  setData(idR0ET01LRP,&var34);
  setData(idA0VT71LRP,&var17);
  setData(idA0VT61LRP,&var39);
  setData(idA0CT01IRP,&var33);
  setData(idR7VN71LRP,&var14);
  setData(idR0IE02LRP,&var30);
  setData(idR0IE01LRP,&var30);
  setData(idR0VN15RRP,&var11);
  setData(idR0VN33RRP,&var10);
  setData(idR0VN23RRP,&var9);
  setData(idA0EE02LRP,&var7);
  setData(idR0VN03RRP,&var5);
  setData(idR0VN02RRP,&var6);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}
