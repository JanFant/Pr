/* Определение внутренних параметров */
uspaint8 InternalBuf[112];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssint iRM_5_ = {5,0}; /* n - N-размерность массива x */ 
ssfloat fRM_2_0 = {2.0,0}; /* Kpr1 - коэфф. преобразования частота->нейтр/с СНМ-11 */ 
sschar bRM_2_ = {2,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssint iRM_4_ = {4,0}; /* n - размерность массива значений */ 

uspaint8 SpaEEPROMBuf[132];

/* Определение переменных */
ssfloat var1;
ssfloat var2;
ssfloat var3;
ssbool var4;
ssbool var5;
ssbool var6;
ssbool var7;
ssbool var8;
ssbool var9;
ssbool var10;
ssint var11;
ssbool var12;
ssbool var13;
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
ssfloat var28;
ssbool var29;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m66_x_1[5] = {&var4,&var16,&R0IE13LS1,&R0IE12LS1,&R0IE11LS1};
psbool  array_m97_x_1[5] = {&var6,&var5,&R0DE37LS1,&R0DE38LS1,&R0DE39LS1};
psint  array_m87_x_1[4] = {&R0DE01LS1,&R0DE02LS1,&R0DE04LS1,&R0DE05LS1};
psfloat  array_m52_tst_1[5];
psfloat  array_m52_trz_1[5];
psfloat  array_m52_N1_1[5];
psfloat  array_m52_N2_1[5];

/* Объявление структур */
_S_ml  S_ml_8_1 = {&R0IN03FI1,&R0IN03FS1,&R0IS01FI0,&var1};
_S_ml  S_ml_7_1 = {&R0IN02FI1,&R0IN02FS1,&R0IS01FI0,&var2};
_S_ml  S_ml_6_1 = {&R0IN01FI1,&R0IN01FS1,&R0IS01FI0,&var3};
_S_noto  S_noto_101_1 = {&var8,&var4};
_S_andn  S_andn_66_1 = {array_m66_x_1,&iRM_5_,&vainSBool};
_S_or2  S_or2_102_1 = {&R0DEB3LS1,&R0DEB4LS1,&var5};
_S_or2  S_or2_95_1 = {&R0DEB1LS1,&R0DEB2LS1,&var6};
_S_orn  S_orn_97_1 = {array_m97_x_1,&iRM_5_,&var7};
_S_or3  S_or3_100_1 = {&var10,&var9,&var7,&var8};
_S_and2  S_and2_89_1 = {&R0DE31LS1,&R0DE32LS1,&var9};
_S_diagndev  S_diagndev_87_1 = {array_m87_x_1,&iRM_4_,&var10,&var11};
_S_and2  S_and2_65_1 = {&var26,&var23,&var12};
_S_and2  S_and2_64_1 = {&var27,&var26,&var13};
_S_ocham  S_ocham_20_1 = {&var3,&var2,&var1,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX01RSS,&fEM_B0UX01RSS,&fEM_A0UX02RSS,&fEM_B0UX02RSS,&fEM_A0UX03RSS,&fEM_B0UX03RSS,&fEM_R7UX01RSS,&fEM_R7UY01RSS,&fEM_R7UX02RSS,&fEM_R7UY02RSS,&fEM_R7UX03RSS,&fEM_R7UY03RSS,&bRM_2_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&var14,&var15,&var16,&var17,&var18,&var19,&var20,&internal1_m20_Nk};
_S_or2  S_or2_75_1 = {&R0EE01LZ1,&R0EE01LZ2,&var21};
_S_period  S_period_52_1 = {&var15,&lEM_EE01LS1,&iRM_5_,&fEM_R0UL01RSS,&fEM_R0UL02RSS,&fEM_R0UN03RSS,&var22,array_m52_tst_1,array_m52_trz_1,array_m52_N1_1,array_m52_N2_1,&internal1_m52_Period0,&internal1_m52_MyFirstEnterFlag};
_S_bol  S_bol_58_1 = {&fEM_R0UL41RSS,&var22,&var23};
_S_bol  S_bol_41_1 = {&var15,&fEM_R0UL52RSS,&var24};
_S_bol  S_bol_36_1 = {&var15,&fEM_R0UL42RSS,&var25};
_S_bol  S_bol_57_1 = {&var15,&fEM_R0UN03RSS,&var26};
_S_bol  S_bol_56_1 = {&fEM_R0UL51RSS,&var22,&var27};
_S_react  S_react_53_1 = {&var22,&var28};
_S_bol  S_bol_46_1 = {&var15,&fEM_R0UR01RSS,&var29};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_75_1);
  diagndev(&S_diagndev_87_1);
  and2(&S_and2_89_1);
  or2(&S_or2_95_1);
  or2(&S_or2_102_1);
  ml(&S_ml_6_1);
  ml(&S_ml_7_1);
  ml(&S_ml_8_1);
  ocham(&S_ocham_20_1);
  orn(&S_orn_97_1);
  bol(&S_bol_46_1);
  bol(&S_bol_57_1);
  bol(&S_bol_36_1);
  bol(&S_bol_41_1);
  period(&S_period_52_1);
  or3(&S_or3_100_1);
  noto(&S_noto_101_1);
  react(&S_react_53_1);
  bol(&S_bol_56_1);
  bol(&S_bol_58_1);
  and2(&S_and2_64_1);
  and2(&S_and2_65_1);
  andn(&S_andn_66_1);
  setData(idTestDiagnAKNP1,&var8);
  setData(idR0DE3DLS1,&var5);
  setData(idR0DE3CLS1,&var6);
  setData(idTTLaknp1,&var11);
  setData(idA1VN71LS1,&var29);
  setData(idA1EE01LS1,&lEM_EE01LS1);
  setData(idR0VN75LZ2,&var13);
  setData(idR0VN71LZ2,&var24);
  setData(idR0IE02LS1,&var21);
  setData(idR0IE01LS1,&var21);
  setData(idR0VN15RS1,&var20);
  setData(idR0VN33RS1,&var19);
  setData(idR0VN23RS1,&var18);
  setData(idR0VN13RS1,&var17);
  setData(idA0EE02LS1,&var16);
  setData(idA0VN71LS1,&var29);
  setData(idR0VN04RS1,&var28);
  setData(idR0VN03RS1,&var14);
  setData(idA0EE01LS1,&lEM_EE01LS1);
  setData(idR0VN75LZ1,&var13);
  setData(idR0VN65LS1,&var12);
  setData(idR0VN71LZ1,&var24);
  setData(idR0VN61LS1,&var25);
  setData(idR0VN01RS1,&var22);
  setData(idR0VN02RS1,&var15);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
  for( i=0;i<5;i++ )
    array_m52_tst_1[i] = &(&internal1_m52_tst)[i];
  for( i=0;i<5;i++ )
    array_m52_trz_1[i] = &(&internal1_m52_trz)[i];
  for( i=0;i<5;i++ )
    array_m52_N1_1[i] = &(&internal1_m52_N1)[i];
  for( i=0;i<5;i++ )
    array_m52_N2_1[i] = &(&internal1_m52_N2)[i];
}
