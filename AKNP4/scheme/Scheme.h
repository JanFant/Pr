/* Определение внутренних параметров */
uspaint8 InternalBuf[112];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssint iRM_5_ = {5,0}; /* n - N-размерность массива входных параметров */ 
ssint iRM_2_ = {2,0}; /* n - N-размерность массива входных параметров */ 
ssfloat fRM_2_0 = {2.0,0}; /* Kpr1 - коэфф. преобразования частота->нейтр/с СНМ-11 */ 
sschar bRM_1_ = {1,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssint iRM_4_ = {4,0}; /* n - размерность массива значений */ 
ssint iRM_6_ = {6,0}; /* n - N-размерность массива x */ 
ssint iRM_1_ = {1,0}; /* x2 - второе слагаемое */ 
ssfloat fRM_0_0009765625 = {0.0009765625,0}; /*  */ 

uspaint8 SpaEEPROMBuf[130];

/* Определение переменных */
ssfloat var1;
ssbool var2;
ssfloat var3;
ssfloat var4;
ssint var5;
ssfloat var6;
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
psfloat  array_m9_x_1[2] = {&R0IN03FS4,&R0IN03FI4};
psfloat  array_m8_x_1[2] = {&R0IN02FS4,&R0IN02FI4};
psfloat  array_m7_x_1[2] = {&R0IN01FS4,&R0IN01FI4};
psbool  array_m104_x_1[6] = {&R0DE36LS4,&R0DE37LS4,&R0DE38LS4,&R0DE39LS4,&var8,&var7};
psint  array_m90_x_1[4] = {&R0DE01LS4,&R0DE02LS4,&R0DE04LS4,&R0DE05LS4};
psfloat  array_m55_tst_1[5];
psfloat  array_m55_trz_1[5];
psfloat  array_m55_N1_1[5];
psfloat  array_m55_N2_1[5];
psbool  array_m65_x_1[2] = {&var28,&var24};
psbool  array_m64_x_1[2] = {&var28,&var29};
psbool  array_m75_x_1[5] = {&var16,&R0IE11LS4,&R0IE12LS4,&R0IE13LS4,&var2};

/* Объявление структур */
_S_ampll  S_ampll_32_1 = {&B8IC01UDU,&fRM_0_0009765625,&var1};
_S_noto  S_noto_106_1 = {&var9,&var2};
_S_ma  S_ma_9_1 = {array_m9_x_1,&var5,&iRM_2_,&var3};
_S_ma  S_ma_8_1 = {array_m8_x_1,&var5,&iRM_2_,&var4};
_S_fsumz  S_fsumz_2_1 = {&R0IS01FI0,&iRM_1_,&var5};
_S_ma  S_ma_7_1 = {array_m7_x_1,&var5,&iRM_2_,&var6};
_S_or2  S_or2_107_1 = {&R0DEB3LS4,&R0DEB4LS4,&var7};
_S_or2  S_or2_99_1 = {&R0DEB1LS4,&R0DEB2LS4,&var8};
_S_or3  S_or3_101_1 = {&var12,&var11,&var10,&var9};
_S_orn  S_orn_104_1 = {array_m104_x_1,&iRM_6_,&var10};
_S_and2  S_and2_92_1 = {&R0DE31LS4,&R0DE32LS4,&var11};
_S_diagndev  S_diagndev_90_1 = {array_m90_x_1,&iRM_4_,&var12,&var13};
_S_ocham  S_ocham_22_1 = {&var6,&var4,&var3,&var1,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX10RSS,&fEM_B0UX10RSS,&fEM_A0UX11RSS,&fEM_B0UX11RSS,&fEM_A0UX12RSS,&fEM_B0UX12RSS,&fEM_R7UX10RSS,&fEM_R7UY10RSS,&fEM_R7UX11RSS,&fEM_R7UY11RSS,&fEM_R7UX12RSS,&fEM_R7UY12RSS,&bRM_1_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&var14,&var15,&var16,&var17,&var18,&var19,&var20,&internal1_m22_Nk};
_S_or2  S_or2_76_1 = {&R0EE04LZ1,&R0EE04LZ2,&var21};
_S_period  S_period_55_1 = {&var15,&lEM_EE01LS4,&iRM_5_,&var32,&var33,&fEM_R0UN03RSS,&var22,array_m55_tst_1,array_m55_trz_1,array_m55_N1_1,array_m55_N2_1,&internal1_m55_Period0,&internal1_m55_MyFirstEnterFlag};
_S_andn  S_andn_65_1 = {array_m65_x_1,&iRM_2_,&var23};
_S_bol  S_bol_62_1 = {&fEM_R0UL41RSS,&var22,&var24};
_S_andn  S_andn_64_1 = {array_m64_x_1,&iRM_2_,&var25};
_S_andn  S_andn_75_1 = {array_m75_x_1,&iRM_5_,&vainSBool};
_S_bol  S_bol_45_1 = {&var15,&fEM_R0UL52RSS,&var26};
_S_bol  S_bol_50_1 = {&var15,&fEM_R0UL42RSS,&var27};
_S_bol  S_bol_61_1 = {&var15,&fEM_R0UN03RSS,&var28};
_S_bol  S_bol_60_1 = {&fEM_R0UL51RSS,&var22,&var29};
_S_react  S_react_56_1 = {&var22,&var30};
_S_bol  S_bol_41_1 = {&var15,&fEM_R0UR01RSS,&var31};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_76_1);
  diagndev(&S_diagndev_90_1);
  and2(&S_and2_92_1);
  or2(&S_or2_99_1);
  or2(&S_or2_107_1);
  fsumz(&S_fsumz_2_1);
  ma(&S_ma_8_1);
  ma(&S_ma_9_1);
  ampll(&S_ampll_32_1);
  orn(&S_orn_104_1);
  or3(&S_or3_101_1);
  ma(&S_ma_7_1);
  noto(&S_noto_106_1);
  ocham(&S_ocham_22_1);
  bol(&S_bol_41_1);
  bol(&S_bol_61_1);
  bol(&S_bol_50_1);
  bol(&S_bol_45_1);
  andn(&S_andn_75_1);
  setData(&var32,&iEM_R0UL01ISS);
  setData(&var33,&dEM_R0UL02USS);
  period(&S_period_55_1);
  react(&S_react_56_1);
  bol(&S_bol_60_1);
  andn(&S_andn_64_1);
  bol(&S_bol_62_1);
  andn(&S_andn_65_1);
  setData(idTestDiagnAKNP4,&var9);
  setData(idTTLaknp4,&var13);
  setData(idR0DE3DLS4,&var7);
  setData(idR0DE3CLS4,&var8);
  setData(idA1EE01LS4,&lEM_EE01LS4);
  setData(idR0VN78LZ2,&var25);
  setData(idR0VN74LZ2,&var26);
  setData(idA0VN71LS4,&var31);
  setData(idR0IE02LS4,&var21);
  setData(idR0IE01LS4,&var21);
  setData(idR0VN15RS4,&var20);
  setData(idR0VN33RS4,&var19);
  setData(idR0VN23RS4,&var18);
  setData(idR0VN13RS4,&var17);
  setData(idA0EE02LS4,&var16);
  setData(idA1VN71LS4,&var31);
  setData(idR0VN04RS4,&var30);
  setData(idR0VN03RS4,&var14);
  setData(idA0EE01LS4,&lEM_EE01LS4);
  setData(idR0VN78LZ1,&var25);
  setData(idR0VN65LS4,&var23);
  setData(idR0VN74LZ1,&var26);
  setData(idR0VN61LS4,&var27);
  setData(idR0VN01RS4,&var22);
  setData(idR0VN02RS4,&var15);

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
