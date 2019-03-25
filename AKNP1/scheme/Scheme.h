/* Определение внутренних параметров */
uspaint8 InternalBuf[112];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssint iRM_5_ = {5,0}; /* n - N-размерность массива x */ 
ssfloat fRM_2_0 = {2.0,0}; /* Kpr1 - коэфф. преобразования частота->нейтр/с СНМ-11 */ 
sschar bRM_2_ = {2,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssint iRM_4_ = {4,0}; /* n - размерность массива значений */ 
ssint iRM_2_ = {2,0}; /* n - N-размерность массива x */ 
ssint iRM_1_ = {1,0}; /* x2 - второе слагаемое */ 

uspaint8 SpaEEPROMBuf[132];

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
ssbool var13;
ssbool var14;
ssfloat var15;
ssfloat var16;
ssbool var17;
ssfloat var18;
ssfloat var19;
ssfloat var20;
ssint var21;
ssbool var22;
ssfloat var23;
ssbool var24;
ssbool var25;
ssbool var26;
ssbool var27;
ssbool var28;
ssfloat var29;
ssbool var30;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m67_x_1[5] = {&var1,&var17,&R0IE13LS1,&R0IE12LS1,&R0IE11LS1};
psfloat  array_m9_x_1[2] = {&R0IN03FS1,&R0IN03FI1};
psfloat  array_m8_x_1[2] = {&R0IN02FS1,&R0IN02FI1};
psfloat  array_m7_x_1[2] = {&R0IN01FS1,&R0IN01FI1};
psbool  array_m98_x_1[5] = {&var7,&var6,&R0DE37LS1,&R0DE38LS1,&R0DE39LS1};
psint  array_m88_x_1[4] = {&R0DE01LS1,&R0DE02LS1,&R0DE04LS1,&R0DE05LS1};
psfloat  array_m53_tst_1[5];
psfloat  array_m53_trz_1[5];
psfloat  array_m53_N1_1[5];
psfloat  array_m53_N2_1[5];

/* Объявление структур */
_S_noto  S_noto_102_1 = {&var9,&var1};
_S_andn  S_andn_67_1 = {array_m67_x_1,&iRM_5_,&vainSBool};
_S_ma  S_ma_9_1 = {array_m9_x_1,&var5,&iRM_2_,&var2};
_S_ma  S_ma_8_1 = {array_m8_x_1,&var5,&iRM_2_,&var3};
_S_ma  S_ma_7_1 = {array_m7_x_1,&var5,&iRM_2_,&var4};
_S_fsumz  S_fsumz_2_1 = {&R0IS01FI0,&iRM_1_,&var5};
_S_or2  S_or2_103_1 = {&R0DEB3LS1,&R0DEB4LS1,&var6};
_S_or2  S_or2_96_1 = {&R0DEB1LS1,&R0DEB2LS1,&var7};
_S_orn  S_orn_98_1 = {array_m98_x_1,&iRM_5_,&var8};
_S_or3  S_or3_101_1 = {&var11,&var10,&var8,&var9};
_S_and2  S_and2_90_1 = {&R0DE31LS1,&R0DE32LS1,&var10};
_S_diagndev  S_diagndev_88_1 = {array_m88_x_1,&iRM_4_,&var11,&var12};
_S_and2  S_and2_66_1 = {&var27,&var24,&var13};
_S_and2  S_and2_65_1 = {&var28,&var27,&var14};
_S_ocham  S_ocham_20_1 = {&var4,&var3,&var2,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX01RSS,&fEM_B0UX01RSS,&fEM_A0UX02RSS,&fEM_B0UX02RSS,&fEM_A0UX03RSS,&fEM_B0UX03RSS,&fEM_R7UX01RSS,&fEM_R7UY01RSS,&fEM_R7UX02RSS,&fEM_R7UY02RSS,&fEM_R7UX03RSS,&fEM_R7UY03RSS,&bRM_2_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&var15,&var16,&var17,&var18,&var19,&var20,&var21,&internal1_m20_Nk};
_S_or2  S_or2_76_1 = {&R0EE01LZ1,&R0EE01LZ2,&var22};
_S_period  S_period_53_1 = {&var16,&lEM_EE01LS1,&iRM_5_,&fEM_R0UL01RSS,&fEM_R0UL02RSS,&fEM_R0UN03RSS,&var23,array_m53_tst_1,array_m53_trz_1,array_m53_N1_1,array_m53_N2_1,&internal1_m53_Period0,&internal1_m53_MyFirstEnterFlag};
_S_bol  S_bol_59_1 = {&fEM_R0UL41RSS,&var23,&var24};
_S_bol  S_bol_42_1 = {&var16,&fEM_R0UL52RSS,&var25};
_S_bol  S_bol_37_1 = {&var16,&fEM_R0UL42RSS,&var26};
_S_bol  S_bol_58_1 = {&var16,&fEM_R0UN03RSS,&var27};
_S_bol  S_bol_57_1 = {&fEM_R0UL51RSS,&var23,&var28};
_S_react  S_react_54_1 = {&var23,&var29};
_S_bol  S_bol_47_1 = {&var16,&fEM_R0UR01RSS,&var30};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_76_1);
  diagndev(&S_diagndev_88_1);
  and2(&S_and2_90_1);
  or2(&S_or2_96_1);
  or2(&S_or2_103_1);
  fsumz(&S_fsumz_2_1);
  ma(&S_ma_7_1);
  ma(&S_ma_8_1);
  ma(&S_ma_9_1);
  ocham(&S_ocham_20_1);
  orn(&S_orn_98_1);
  bol(&S_bol_47_1);
  bol(&S_bol_58_1);
  bol(&S_bol_37_1);
  bol(&S_bol_42_1);
  period(&S_period_53_1);
  or3(&S_or3_101_1);
  noto(&S_noto_102_1);
  react(&S_react_54_1);
  bol(&S_bol_57_1);
  bol(&S_bol_59_1);
  and2(&S_and2_65_1);
  and2(&S_and2_66_1);
  andn(&S_andn_67_1);
  setData(idTestDiagnAKNP1,&var9);
  setData(idR0DE3DLS1,&var6);
  setData(idR0DE3CLS1,&var7);
  setData(idTTLaknp1,&var12);
  setData(idA1VN71LS1,&var30);
  setData(idA1EE01LS1,&lEM_EE01LS1);
  setData(idR0VN75LZ2,&var14);
  setData(idR0VN71LZ2,&var25);
  setData(idR0IE02LS1,&var22);
  setData(idR0IE01LS1,&var22);
  setData(idR0VN15RS1,&var21);
  setData(idR0VN33RS1,&var20);
  setData(idR0VN23RS1,&var19);
  setData(idR0VN13RS1,&var18);
  setData(idA0EE02LS1,&var17);
  setData(idA0VN71LS1,&var30);
  setData(idR0VN04RS1,&var29);
  setData(idR0VN03RS1,&var15);
  setData(idA0EE01LS1,&lEM_EE01LS1);
  setData(idR0VN75LZ1,&var14);
  setData(idR0VN65LS1,&var13);
  setData(idR0VN71LZ1,&var25);
  setData(idR0VN61LS1,&var26);
  setData(idR0VN01RS1,&var23);
  setData(idR0VN02RS1,&var16);

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
