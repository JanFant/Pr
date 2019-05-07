/* Определение внутренних параметров */
uspaint8 InternalBuf[41];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssint iRM_5_ = {5,0}; /* n - N-размерность массива входных параметров */ 
ssint iRM_2_ = {2,0}; /* n - N-размерность массива входных параметров */ 
sschar bRM_1_ = {1,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssint iRM_4_ = {4,0}; /* n - размерность массива значений */ 
ssint iRM_6_ = {6,0}; /* n - N-размерность массива x */ 
ssbool lRM_1_ = {1,0}; /*  */ 

uspaint8 SpaEEPROMBuf[148];

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
ssint var10;
ssfloat var11;
ssfloat var12;
ssbool var13;
ssfloat var14;
ssfloat var15;
ssfloat var16;
ssint var17;
ssbool var18;
ssfloat var19;
ssbool var20;
ssbool var21;
ssbool var22;
ssbool var23;
ssbool var24;
ssbool var25;
ssbool var26;
ssbool var27;
ssfloat var28;
ssbool var29;
ssfloat var30;
ssfloat var31;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m104_x_1[6] = {&var5,&var4,&R0DE36LS3,&R0DE37LS3,&R0DE38LS3,&R0DE39LS3};
psint  array_m90_x_1[4] = {&R0DE01LS3,&R0DE02LS3,&R0DE04LS3,&R0DE05LS3};
psbool  array_m66_x_1[2] = {&var26,&var21};
psbool  array_m65_x_1[2] = {&var26,&var27};
psbool  array_m74_x_1[5] = {&var13,&R0IE11LS3,&R0IE12LS3,&R0IE13LS3,&lRM_1_};

/* Объявление структур */
_S_ml  S_ml_8_1 = {&R0IN03FI3,&R0IN03FS3,&R0IS01FI0,&var1};
_S_ml  S_ml_7_1 = {&R0IN02FI3,&R0IN02FS3,&R0IS01FI0,&var2};
_S_ml  S_ml_6_1 = {&R0IN01FI3,&R0IN01FS3,&R0IS01FI0,&var3};
_S_noto  S_noto_105_1 = {&var6,&vainSBool};
_S_or2  S_or2_107_1 = {&R0DEB3LS3,&R0DEB4LS3,&var4};
_S_or2  S_or2_99_1 = {&R0DEB1LS3,&R0DEB2LS3,&var5};
_S_or3  S_or3_101_1 = {&var9,&var8,&var7,&var6};
_S_orn  S_orn_104_1 = {array_m104_x_1,&iRM_6_,&var7};
_S_and2  S_and2_92_1 = {&R0DE31LS3,&R0DE32LS3,&var8};
_S_diagndev  S_diagndev_90_1 = {array_m90_x_1,&iRM_4_,&var9,&var10};
_S_ocham  S_ocham_22_1 = {&var3,&var2,&var1,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX07RSS,&fEM_B0UX07RSS,&fEM_A0UX08RSS,&fEM_B0UX08RSS,&fEM_A0UX09RSS,&fEM_B0UX09RSS,&fEM_R7UX07RSS,&fEM_R7UY07RSS,&fEM_R7UX08RSS,&fEM_R7UY08RSS,&fEM_R7UX09RSS,&fEM_R7UY09RSS,&bRM_1_,&fEM_R0UH01RSS,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&fEM_R0UH21RSS,&fEM_R0UH22RSS,&fEM_R0UH23RSS,&var11,&var12,&var13,&var14,&var15,&var16,&var17,&internal1_m22_Nk};
_S_or2  S_or2_78_1 = {&R0EE03LZ1,&R0EE03LZ2,&var18};
_S_period  S_period_56_1 = {&var12,&var23,&iRM_5_,&var30,&var31,&fEM_R0UN03RSS,&var19,&internal1_m56_flst,&internal1_m56_chsr,&internal1_m56_chizm,&internal1_m56_chpass,&internal1_m56_sumtim,&internal1_m56_W1,&internal1_m56_W2,&internal1_m56_Period0,&internal1_m56_MyFirstEnterFlag};
_S_andn  S_andn_66_1 = {array_m66_x_1,&iRM_2_,&var20};
_S_bol  S_bol_63_1 = {&fEM_R0UL41RSS,&var19,&var21};
_S_andn  S_andn_65_1 = {array_m65_x_1,&iRM_2_,&var22};
_S_andn  S_andn_74_1 = {array_m74_x_1,&iRM_5_,&var23};
_S_bol  S_bol_46_1 = {&var12,&fEM_R0UL52RSS,&var24};
_S_bol  S_bol_51_1 = {&var12,&fEM_R0UL42RSS,&var25};
_S_bol  S_bol_62_1 = {&var12,&fEM_R0UN03RSS,&var26};
_S_bol  S_bol_61_1 = {&fEM_R0UL51RSS,&var19,&var27};
_S_react  S_react_57_1 = {&var19,&var28};
_S_bol  S_bol_41_1 = {&var12,&fEM_R0UR01RSS,&var29};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_78_1);
  diagndev(&S_diagndev_90_1);
  and2(&S_and2_92_1);
  or2(&S_or2_99_1);
  or2(&S_or2_107_1);
  ml(&S_ml_6_1);
  ml(&S_ml_7_1);
  ml(&S_ml_8_1);
  ocham(&S_ocham_22_1);
  orn(&S_orn_104_1);
  or3(&S_or3_101_1);
  noto(&S_noto_105_1);
  bol(&S_bol_41_1);
  bol(&S_bol_62_1);
  bol(&S_bol_51_1);
  bol(&S_bol_46_1);
  andn(&S_andn_74_1);
  setData(&var30,&iEM_R0UL01ISS);
  setData(&var31,&dEM_R0UL02USS);
  period(&S_period_56_1);
  react(&S_react_57_1);
  bol(&S_bol_61_1);
  andn(&S_andn_65_1);
  bol(&S_bol_63_1);
  andn(&S_andn_66_1);
  setData(idTestDiagnAKNP3,&var6);
  setData(idTTLaknp3,&var10);
  setData(idR0DE3DLS3,&var4);
  setData(idR0DE3CLS3,&var5);
  setData(idA1EE01LS3,&var23);
  setData(idR0VN77LZ2,&var22);
  setData(idR0VN73LZ2,&var24);
  setData(idA0VN71LS3,&var29);
  setData(idR0IE02LS3,&var18);
  setData(idR0IE01LS3,&var18);
  setData(idR0VN15RS3,&var17);
  setData(idR0VN33RS3,&var16);
  setData(idR0VN23RS3,&var15);
  setData(idR0VN13RS3,&var14);
  setData(idA0EE02LS3,&var13);
  setData(idA1VN71LS3,&var29);
  setData(idR0VN04RS3,&var28);
  setData(idR0VN03RS3,&var11);
  setData(idA0EE01LS3,&var23);
  setData(idR0VN77LZ1,&var22);
  setData(idR0VN65LS3,&var20);
  setData(idR0VN73LZ1,&var24);
  setData(idR0VN61LS3,&var25);
  setData(idR0VN01RS3,&var19);
  setData(idR0VN02RS3,&var12);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}
