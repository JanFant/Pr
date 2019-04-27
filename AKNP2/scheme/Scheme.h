/* Определение внутренних параметров */
uspaint8 InternalBuf[112];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssint iRM_5_ = {5,0}; /* n - N-размерность массива входных параметров */ 
ssint iRM_2_ = {2,0}; /* n - N-размерность массива входных параметров */ 
ssfloat fRM_2_0 = {2.0,0}; /* Kpr1 - коэфф. преобразования частота->нейтр/с СНМ-11 */ 
sschar bRM_2_ = {2,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssint iRM_4_ = {4,0}; /* n - размерность массива значений */ 
ssint iRM_1_ = {1,0}; /* x2 - второе слагаемое */ 
ssfloat fRM_0_0009765625 = {0.0009765625,0}; /*  */ 

uspaint8 SpaEEPROMBuf[130];

/* Определение переменных */
ssfloat var1;
ssbool var2;
ssfloat var3;
ssfloat var4;
ssfloat var5;
ssint var6;
ssbool var7;
ssbool var8;
ssbool var9;
ssbool var10;
ssbool var11;
ssbool var12;
ssint var13;
ssfloat var14;
ssfloat var15;
ssbool var16;
ssfloat var17;
ssfloat var18;
ssfloat var19;
ssint var20;
ssbool var21;
ssfloat var22;
ssbool var23;
ssbool var24;
ssbool var25;
ssbool var26;
ssbool var27;
ssbool var28;
ssbool var29;
ssfloat var30;
ssbool var31;
ssfloat var32;
ssfloat var33;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psfloat  array_m9_x_1[2] = {&R0IN03FS2,&R0IN03FI2};
psfloat  array_m8_x_1[2] = {&R0IN02FS2,&R0IN02FI2};
psfloat  array_m7_x_1[2] = {&R0IN01FS2,&R0IN01FI2};
psbool  array_m104_x_1[5] = {&var8,&var7,&R0DE37LS2,&R0DE38LS2,&R0DE39LS2};
psint  array_m90_x_1[4] = {&R0DE01LS2,&R0DE02LS2,&R0DE04LS2,&R0DE05LS2};
psfloat  array_m55_tst_1[5];
psfloat  array_m55_trz_1[5];
psfloat  array_m55_N1_1[5];
psfloat  array_m55_N2_1[5];
psbool  array_m65_x_1[2] = {&var28,&var24};
psbool  array_m64_x_1[2] = {&var28,&var29};
psbool  array_m75_x_1[5] = {&var16,&R0IE11LS2,&R0IE12LS2,&R0IE13LS2,&var2};

/* Объявление структур */
_S_ampll  S_ampll_42_1 = {&B8IC01UDU,&fRM_0_0009765625,&var1};
_S_noto  S_noto_101_1 = {&var9,&var2};
_S_ma  S_ma_9_1 = {array_m9_x_1,&var6,&iRM_2_,&var3};
_S_ma  S_ma_8_1 = {array_m8_x_1,&var6,&iRM_2_,&var4};
_S_ma  S_ma_7_1 = {array_m7_x_1,&var6,&iRM_2_,&var5};
_S_fsumz  S_fsumz_2_1 = {&R0IS01FI0,&iRM_1_,&var6};
_S_or2  S_or2_106_1 = {&R0DEB3LS2,&R0DEB4LS2,&var7};
_S_or2  S_or2_98_1 = {&R0DEB1LS2,&R0DEB2LS2,&var8};
_S_or3  S_or3_100_1 = {&var12,&var11,&var10,&var9};
_S_orn  S_orn_104_1 = {array_m104_x_1,&iRM_5_,&var10};
_S_and2  S_and2_92_1 = {&R0DE31LS2,&R0DE32LS2,&var11};
_S_diagndev  S_diagndev_90_1 = {array_m90_x_1,&iRM_4_,&var12,&var13};
_S_ocham  S_ocham_22_1 = {&var5,&var4,&var3,&var1,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX04RSS,&fEM_B0UX04RSS,&fEM_A0UX05RSS,&fEM_B0UX05RSS,&fEM_A0UX06RSS,&fEM_B0UX06RSS,&fEM_R7UX04RSS,&fEM_R7UY04RSS,&fEM_R7UX05RSS,&fEM_R7UY05RSS,&fEM_R7UX06RSS,&fEM_R7UY06RSS,&bRM_2_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&var14,&var15,&var16,&var17,&var18,&var19,&var20,&internal1_m22_Nk};
_S_or2  S_or2_76_1 = {&R0EE02LZ1,&R0EE02LZ2,&var21};
_S_period  S_period_55_1 = {&var15,&lEM_EE01LS2,&iRM_5_,&var32,&var33,&fEM_R0UN03RSS,&var22,array_m55_tst_1,array_m55_trz_1,array_m55_N1_1,array_m55_N2_1,&internal1_m55_Period0,&internal1_m55_MyFirstEnterFlag};
_S_andn  S_andn_65_1 = {array_m65_x_1,&iRM_2_,&var23};
_S_bol  S_bol_62_1 = {&fEM_R0UL41RSS,&var22,&var24};
_S_andn  S_andn_64_1 = {array_m64_x_1,&iRM_2_,&var25};
_S_andn  S_andn_75_1 = {array_m75_x_1,&iRM_5_,&vainSBool};
_S_bol  S_bol_44_1 = {&var15,&fEM_R0UL52RSS,&var26};
_S_bol  S_bol_50_1 = {&var15,&fEM_R0UL42RSS,&var27};
_S_bol  S_bol_61_1 = {&var15,&fEM_R0UN03RSS,&var28};
_S_bol  S_bol_60_1 = {&fEM_R0UL51RSS,&var22,&var29};
_S_react  S_react_56_1 = {&var22,&var30};
_S_bol  S_bol_40_1 = {&var15,&fEM_R0UR01RSS,&var31};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_76_1);
  diagndev(&S_diagndev_90_1);
  and2(&S_and2_92_1);
  or2(&S_or2_98_1);
  or2(&S_or2_106_1);
  fsumz(&S_fsumz_2_1);
  ma(&S_ma_7_1);
  ma(&S_ma_8_1);
  ma(&S_ma_9_1);
  ampll(&S_ampll_42_1);
  ocham(&S_ocham_22_1);
  orn(&S_orn_104_1);
  or3(&S_or3_100_1);
  noto(&S_noto_101_1);
  bol(&S_bol_40_1);
  bol(&S_bol_61_1);
  bol(&S_bol_50_1);
  bol(&S_bol_44_1);
  andn(&S_andn_75_1);
  setData(&var32,&iEM_R0UL01ISS);
  setData(&var33,&dEM_R0UL02USS);
  period(&S_period_55_1);
  react(&S_react_56_1);
  bol(&S_bol_60_1);
  andn(&S_andn_64_1);
  bol(&S_bol_62_1);
  andn(&S_andn_65_1);
  setData(idTestDiagnAKNP2,&var9);
  setData(idR0DE3DLS2,&var7);
  setData(idR0DE3CLS2,&var8);
  setData(idTTLaknp2,&var13);
  setData(idA0VN71LS2,&var31);
  setData(idA1EE01LS2,&lEM_EE01LS2);
  setData(idR0VN76LZ2,&var25);
  setData(idR0VN72LZ2,&var26);
  setData(idR0IE02LS2,&var21);
  setData(idR0IE01LS2,&var21);
  setData(idR0VN15RS2,&var20);
  setData(idR0VN33RS2,&var19);
  setData(idR0VN23RS2,&var18);
  setData(idR0VN13RS2,&var17);
  setData(idA0EE02LS2,&var16);
  setData(idA1VN71LS2,&var31);
  setData(idR0VN04RS2,&var30);
  setData(idR0VN03RS2,&var14);
  setData(idA0EE01LS2,&lEM_EE01LS2);
  setData(idR0VN76LZ1,&var25);
  setData(idR0VN65LS2,&var23);
  setData(idR0VN72LZ1,&var26);
  setData(idR0VN61LS2,&var27);
  setData(idR0VN01RS2,&var22);
  setData(idR0VN02RS2,&var15);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
  for( i=0;i<5;i++ )
    array_m55_tst_1[i] = &(&internal1_m55_tst)[i];
  for( i=0;i<5;i++ )
    array_m55_trz_1[i] = &(&internal1_m55_trz)[i];
  for( i=0;i<5;i++ )
    array_m55_N1_1[i] = &(&internal1_m55_N1)[i];
  for( i=0;i<5;i++ )
    array_m55_N2_1[i] = &(&internal1_m55_N2)[i];
}
