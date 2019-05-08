/* Определение внутренних параметров */
uspaint8 InternalBuf[46];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssint iRM_5_ = {5,0}; /* n - N-размерность массива входных параметров */ 
ssint iRM_2_ = {2,0}; /* n - N-размерность массива входных параметров */ 
sschar bRM_2_ = {2,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssint iRM_4_ = {4,0}; /* n - размерность массива значений */ 
ssbool lRM_1_ = {1,0}; /*  */ 
ssfloat fRM_1_0 = {1.0,0}; /* k - Kф-коэффициент усиления */ 

uspaint8 SpaEEPROMBuf[150];

/* Определение переменных */
ssfloat var1;
ssfloat var2;
ssfloat var3;
ssfloat var4;
ssbool var5;
ssbool var6;
ssbool var7;
ssbool var8;
ssbool var9;
ssbool var10;
ssint var11;
ssfloat var12;
ssfloat var13;
ssbool var14;
ssfloat var15;
ssfloat var16;
ssfloat var17;
ssint var18;
ssbool var19;
ssfloat var20;
ssbool var21;
ssbool var22;
ssbool var23;
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
psbool  array_m105_x_1[5] = {&var6,&var5,&R0DE37LS2,&R0DE38LS2,&R0DE39LS2};
psint  array_m91_x_1[4] = {&R0DE01LS2,&R0DE02LS2,&R0DE04LS2,&R0DE05LS2};
psbool  array_m67_x_1[2] = {&var27,&var22};
psbool  array_m66_x_1[2] = {&var27,&var28};
psbool  array_m75_x_1[5] = {&var14,&R0IE11LS2,&R0IE12LS2,&R0IE13LS2,&lRM_1_};

/* Объявление структур */
_S_mod1  S_mod1_58_1 = {&var20,&fRM_1_0,&fEM_R0UL02RSS,&var1,&internal1_m58_y0};
_S_ml  S_ml_8_1 = {&R0IN03FI2,&R0IN03FS2,&R0IS01FI0,&var2};
_S_ml  S_ml_7_1 = {&R0IN02FI2,&R0IN02FS2,&R0IS01FI0,&var3};
_S_ml  S_ml_6_1 = {&R0IN01FI2,&R0IN01FS2,&R0IS01FI0,&var4};
_S_noto  S_noto_102_1 = {&var7,&vainSBool};
_S_or2  S_or2_108_1 = {&R0DEB3LS2,&R0DEB4LS2,&var5};
_S_or2  S_or2_99_1 = {&R0DEB1LS2,&R0DEB2LS2,&var6};
_S_or3  S_or3_101_1 = {&var10,&var9,&var8,&var7};
_S_orn  S_orn_105_1 = {array_m105_x_1,&iRM_5_,&var8};
_S_and2  S_and2_93_1 = {&R0DE31LS2,&R0DE32LS2,&var9};
_S_diagndev  S_diagndev_91_1 = {array_m91_x_1,&iRM_4_,&var10,&var11};
_S_ocham  S_ocham_20_1 = {&var4,&var3,&var2,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX04RSS,&fEM_B0UX04RSS,&fEM_A0UX05RSS,&fEM_B0UX05RSS,&fEM_A0UX06RSS,&fEM_B0UX06RSS,&fEM_R7UX04RSS,&fEM_R7UY04RSS,&fEM_R7UX05RSS,&fEM_R7UY05RSS,&fEM_R7UX06RSS,&fEM_R7UY06RSS,&bRM_2_,&fEM_R0UH01RSS,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&fEM_R0UH21RSS,&fEM_R0UH22RSS,&fEM_R0UH23RSS,&var12,&var13,&var14,&var15,&var16,&var17,&var18,&internal1_m20_Nk};
_S_or2  S_or2_78_1 = {&R0EE02LZ1,&R0EE02LZ2,&var19};
_S_period  S_period_57_1 = {&var13,&var24,&iRM_5_,&fEM_R0UL01RSS,&fEM_R0UN03RSS,&var20,&internal1_m57_flst,&internal1_m57_chsr,&internal1_m57_chizm,&internal1_m57_chpass,&internal1_m57_sumtim,&internal1_m57_W1,&internal1_m57_W2,&internal1_m57_Period0,&internal1_m57_MyFirstEnterFlag};
_S_andn  S_andn_67_1 = {array_m67_x_1,&iRM_2_,&var21};
_S_bol  S_bol_64_1 = {&fEM_R0UL41RSS,&var1,&var22};
_S_andn  S_andn_66_1 = {array_m66_x_1,&iRM_2_,&var23};
_S_andn  S_andn_75_1 = {array_m75_x_1,&iRM_5_,&var24};
_S_bol  S_bol_45_1 = {&var13,&fEM_R0UL52RSS,&var25};
_S_bol  S_bol_51_1 = {&var13,&fEM_R0UL42RSS,&var26};
_S_bol  S_bol_63_1 = {&var13,&fEM_R0UN03RSS,&var27};
_S_bol  S_bol_62_1 = {&fEM_R0UL51RSS,&var1,&var28};
_S_react  S_react_59_1 = {&var1,&var29};
_S_bol  S_bol_41_1 = {&var13,&fEM_R0UR01RSS,&var30};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_78_1);
  diagndev(&S_diagndev_91_1);
  and2(&S_and2_93_1);
  or2(&S_or2_99_1);
  or2(&S_or2_108_1);
  ml(&S_ml_6_1);
  ml(&S_ml_7_1);
  ml(&S_ml_8_1);
  ocham(&S_ocham_20_1);
  orn(&S_orn_105_1);
  or3(&S_or3_101_1);
  noto(&S_noto_102_1);
  bol(&S_bol_41_1);
  bol(&S_bol_63_1);
  bol(&S_bol_51_1);
  bol(&S_bol_45_1);
  andn(&S_andn_75_1);
  period(&S_period_57_1);
  mod1(&S_mod1_58_1);
  react(&S_react_59_1);
  bol(&S_bol_62_1);
  andn(&S_andn_66_1);
  bol(&S_bol_64_1);
  andn(&S_andn_67_1);
  setData(idTestDiagnAKNP2,&var7);
  setData(idR0DE3DLS2,&var5);
  setData(idR0DE3CLS2,&var6);
  setData(idTTLaknp2,&var11);
  setData(idA0VN71LS2,&var30);
  setData(idA1EE01LS2,&var24);
  setData(idR0VN76LZ2,&var23);
  setData(idR0VN72LZ2,&var25);
  setData(idR0IE02LS2,&var19);
  setData(idR0IE01LS2,&var19);
  setData(idR0VN15RS2,&var18);
  setData(idR0VN33RS2,&var17);
  setData(idR0VN23RS2,&var16);
  setData(idR0VN13RS2,&var15);
  setData(idA0EE02LS2,&var14);
  setData(idA1VN71LS2,&var30);
  setData(idR0VN04RS2,&var29);
  setData(idR0VN03RS2,&var12);
  setData(idA0EE01LS2,&var24);
  setData(idR0VN76LZ1,&var23);
  setData(idR0VN65LS2,&var21);
  setData(idR0VN72LZ1,&var25);
  setData(idR0VN61LS2,&var26);
  setData(idR0VN01RS2,&var1);
  setData(idR0VN02RS2,&var13);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}
