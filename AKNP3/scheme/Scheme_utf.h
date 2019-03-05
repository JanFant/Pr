/* Определение внутренних параметров */
uspaint8 InternalBuf[112];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssint iRM_5_ = {5,0}; /* n - N-размерность массива входных параметров */ 
ssint iRM_2_ = {2,0}; /* n - N-размерность массива входных параметров */ 
sschar bRM_1_ = {1,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssfloat fRM_2_0 = {2.0,0}; /* Kpr1 - коэфф. преобразования частота->нейтр/с СНМ-11 */ 
ssint iRM_4_ = {4,0}; /* n - размерность массива значений */ 
ssint iRM_6_ = {6,0}; /* n - N-размерность массива x */ 
ssint iRM_1_ = {1,0}; /* x2 - второе слагаемое */ 

uspaint8 SpaEEPROMBuf[128];

/* Определение переменных */
ssbool var1;
ssfloat var2;
ssfloat var3;
ssfloat var4;
ssint var5;
ssbool var6;
ssbool var7;
ssbool var8;
ssbool var9;
ssbool var10;
ssbool var11;
ssint var12;
ssfloat var13;
ssfloat var14;
ssbool var15;
ssfloat var16;
ssfloat var17;
ssfloat var18;
ssint var19;
ssbool var20;
ssfloat var21;
ssbool var22;
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
psfloat  array_m9_x_1[2] = {&R0IN03FS3,&R0IN03FI3};
psfloat  array_m8_x_1[2] = {&R0IN02FS3,&R0IN02FI3};
psfloat  array_m7_x_1[2] = {&R0IN01FS3,&R0IN01FI3};
psbool  array_m101_x_1[6] = {&var7,&var6,&R0DE36LS3,&R0DE37LS3,&R0DE38LS3,&R0DE39LS3};
psint  array_m87_x_1[4] = {&R0DE01LS3,&R0DE02LS3,&R0DE04LS3,&R0DE05LS3};
psfloat  array_m53_tst_1[5];
psfloat  array_m53_trz_1[5];
psfloat  array_m53_N1_1[5];
psfloat  array_m53_N2_1[5];
psbool  array_m63_x_1[2] = {&var28,&var23};
psbool  array_m62_x_1[2] = {&var28,&var29};
psbool  array_m73_x_1[5] = {&var15,&R0IE11LS3,&R0IE12LS3,&R0IE13LS3,&var1};

/* Объявление структур */
_S_noto  S_noto_102_1 = {&var8,&var1};
_S_ma  S_ma_9_1 = {array_m9_x_1,&var5,&iRM_2_,&var2};
_S_ma  S_ma_8_1 = {array_m8_x_1,&var5,&iRM_2_,&var3};
_S_ma  S_ma_7_1 = {array_m7_x_1,&var5,&iRM_2_,&var4};
_S_fsumz  S_fsumz_2_1 = {&R0IS01FI0,&iRM_1_,&var5};
_S_or2  S_or2_104_1 = {&R0DEB3LS3,&R0DEB4LS3,&var6};
_S_or2  S_or2_96_1 = {&R0DEB1LS3,&R0DEB2LS3,&var7};
_S_or3  S_or3_98_1 = {&var11,&var10,&var9,&var8};
_S_orn  S_orn_101_1 = {array_m101_x_1,&iRM_6_,&var9};
_S_and2  S_and2_89_1 = {&R0DE31LS3,&R0DE32LS3,&var10};
_S_diagndev  S_diagndev_87_1 = {array_m87_x_1,&iRM_4_,&var11,&var12};
_S_ocham  S_ocham_23_1 = {&var4,&var3,&var2,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX07RSS,&fEM_B0UX07RSS,&fEM_A0UX08RSS,&fEM_B0UX08RSS,&fEM_A0UX09RSS,&fEM_B0UX09RSS,&fEM_R7UX07RSS,&fEM_R7UY07RSS,&fEM_R7UX08RSS,&fEM_R7UY08RSS,&fEM_R7UX09RSS,&fEM_R7UY09RSS,&bRM_1_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&var13,&var14,&var15,&var16,&var17,&var18,&var19,&internal1_m23_Nk};
_S_or2  S_or2_75_1 = {&R0EE03LZ1,&R0EE03LZ2,&var20};
_S_period  S_period_53_1 = {&var14,&var25,&iRM_5_,&var32,&var33,&fEM_R0UN03RSS,&var21,array_m53_tst_1,array_m53_trz_1,array_m53_N1_1,array_m53_N2_1,&internal1_m53_Period0,&internal1_m53_MyFirstEnterFlag};
_S_andn  S_andn_63_1 = {array_m63_x_1,&iRM_2_,&var22};
_S_bol  S_bol_60_1 = {&fEM_R0UL41RSS,&var21,&var23};
_S_andn  S_andn_62_1 = {array_m62_x_1,&iRM_2_,&var24};
_S_andn  S_andn_73_1 = {array_m73_x_1,&iRM_5_,&var25};
_S_bol  S_bol_43_1 = {&var14,&fEM_R0UL52RSS,&var26};
_S_bol  S_bol_48_1 = {&var14,&fEM_R0UL42RSS,&var27};
_S_bol  S_bol_59_1 = {&var14,&fEM_R0UN03RSS,&var28};
_S_bol  S_bol_58_1 = {&fEM_R0UL51RSS,&var21,&var29};
_S_react  S_react_54_1 = {&var21,&var30};
_S_bol  S_bol_39_1 = {&var14,&fEM_R0UR01RSS,&var31};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_75_1);
  diagndev(&S_diagndev_87_1);
  and2(&S_and2_89_1);
  or2(&S_or2_96_1);
  or2(&S_or2_104_1);
  fsumz(&S_fsumz_2_1);
  ma(&S_ma_7_1);
  ma(&S_ma_8_1);
  ma(&S_ma_9_1);
  ocham(&S_ocham_23_1);
  orn(&S_orn_101_1);
  or3(&S_or3_98_1);
  noto(&S_noto_102_1);
  bol(&S_bol_39_1);
  bol(&S_bol_59_1);
  bol(&S_bol_48_1);
  bol(&S_bol_43_1);
  andn(&S_andn_73_1);
  setData(&var32,&iEM_R0UL01ISS);
  setData(&var33,&dEM_R0UL02USS);
  period(&S_period_53_1);
  react(&S_react_54_1);
  bol(&S_bol_58_1);
  andn(&S_andn_62_1);
  bol(&S_bol_60_1);
  andn(&S_andn_63_1);
  setData(idTestDiagnAKNP3,&var8);
  setData(idTTLaknp3,&var12);
  setData(idR0DE3DLS3,&var6);
  setData(idR0DE3CLS3,&var7);
  setData(idA1EE01LS3,&var25);
  setData(idR0VN77LZ2,&var24);
  setData(idR0VN73LZ2,&var26);
  setData(idA0VN71LS3,&var31);
  setData(idR0IE02LS3,&var20);
  setData(idR0IE01LS3,&var20);
  setData(idR0VN15RS3,&var19);
  setData(idR0VN33RS3,&var18);
  setData(idR0VN23RS3,&var17);
  setData(idR0VN13RS3,&var16);
  setData(idA0EE02LS3,&var15);
  setData(idA1VN71LS3,&var31);
  setData(idR0VN04RS3,&var30);
  setData(idR0VN03RS3,&var13);
  setData(idA0EE01LS3,&var25);
  setData(idR0VN77LZ1,&var24);
  setData(idR0VN65LS3,&var22);
  setData(idR0VN73LZ1,&var26);
  setData(idR0VN61LS3,&var27);
  setData(idR0VN01RS3,&var21);
  setData(idR0VN02RS3,&var14);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
  for( i=0;i<5;i++ )
    array_m53_tst_1[i] = &(&internal1_m53_tst)[i];
  for( i=0;i<5;i++ )
    array_m53_trz_1[i] = &(&internal1_m53_trz)[i];
  for( i=0;i<5;i++ )
    array_m53_N1_1[i] = &(&internal1_m53_N1)[i];
  for( i=0;i<5;i++ )
    array_m53_N2_1[i] = &(&internal1_m53_N2)[i];
}
