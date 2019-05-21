/* Определение внутренних параметров */
uspaint8 InternalBuf[54];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssint iRM_5_ = {5,0}; /* n - N-размерность массива входных параметров */ 
ssint iRM_2_ = {2,0}; /* n - N-размерность массива входных параметров */ 
sschar bRM_1_ = {1,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssint iRM_4_ = {4,0}; /* n - размерность массива значений */ 
ssint iRM_6_ = {6,0}; /* n - N-размерность массива x */ 
ssbool lRM_1_ = {1,0}; /*  */ 

uspaint8 SpaEEPROMBuf[150];

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
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m104_x_1[6] = {&R0DE36LS4,&R0DE37LS4,&R0DE38LS4,&R0DE39LS4,&var5,&var4};
psint  array_m90_x_1[4] = {&R0DE01LS4,&R0DE02LS4,&R0DE04LS4,&R0DE05LS4};
psbool  array_m66_x_1[2] = {&var26,&var21};
psbool  array_m65_x_1[2] = {&var26,&var27};
psbool  array_m75_x_1[5] = {&var13,&R0IE11LS4,&R0IE12LS4,&R0IE13LS4,&lRM_1_};

/* Объявление структур */
_S_ml  S_ml_9_1 = {&R0IN03FI4,&R0IN03FS4,&R0IS01FI0,&var1};
_S_ml  S_ml_8_1 = {&R0IN02FI4,&R0IN02FS4,&R0IS01FI0,&var2};
_S_ml  S_ml_7_1 = {&R0IN01FI4,&R0IN01FS4,&R0IS01FI0,&var3};
_S_noto  S_noto_106_1 = {&var6,&vainSBool};
_S_or2  S_or2_107_1 = {&R0DEB3LS4,&R0DEB4LS4,&var4};
_S_or2  S_or2_99_1 = {&R0DEB1LS4,&R0DEB2LS4,&var5};
_S_or3  S_or3_101_1 = {&var9,&var8,&var7,&var6};
_S_orn  S_orn_104_1 = {array_m104_x_1,&iRM_6_,&var7};
_S_and2  S_and2_92_1 = {&R0DE31LS4,&R0DE32LS4,&var8};
_S_diagndev  S_diagndev_90_1 = {array_m90_x_1,&iRM_4_,&var9,&var10,&vainSFloat,&internal1_m90_sttlf};
_S_ocham  S_ocham_22_1 = {&var3,&var2,&var1,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX10RSS,&fEM_B0UX10RSS,&fEM_A0UX11RSS,&fEM_B0UX11RSS,&fEM_A0UX12RSS,&fEM_B0UX12RSS,&fEM_R7UX10RSS,&fEM_R7UY10RSS,&fEM_R7UX11RSS,&fEM_R7UY11RSS,&fEM_R7UX12RSS,&fEM_R7UY12RSS,&bRM_1_,&fEM_R0UH01RSS,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&fEM_R0UH21RSS,&fEM_R0UH22RSS,&fEM_R0UH23RSS,&var11,&var12,&var13,&var14,&var15,&var16,&var17,&internal1_m22_Nk};
_S_or2  S_or2_77_1 = {&R0EE04LZ1,&R0EE04LZ2,&var18};
_S_period  S_period_56_1 = {&var12,&var23,&iRM_5_,&fEM_R0UL01RSS,&fEM_R0UL02RSS,&fEM_R0UN03RSS,&var19,&internal1_m56_flst,&internal1_m56_chsr,&internal1_m56_chizm,&internal1_m56_sumtim,&internal1_m56_W1,&internal1_m56_W2,&internal1_m56_Wmin,&internal1_m56_Wmax,&internal1_m56_Wlast,&internal1_m56_y0,&internal1_m56_MyFirstEnterFlag};
_S_andn  S_andn_66_1 = {array_m66_x_1,&iRM_2_,&var20};
_S_bol  S_bol_63_1 = {&fEM_R0UL41RSS,&var19,&var21};
_S_andn  S_andn_65_1 = {array_m65_x_1,&iRM_2_,&var22};
_S_andn  S_andn_75_1 = {array_m75_x_1,&iRM_5_,&var23};
_S_bol  S_bol_46_1 = {&var12,&fEM_R0UL52RSS,&var24};
_S_bol  S_bol_51_1 = {&var12,&fEM_R0UL42RSS,&var25};
_S_bol  S_bol_62_1 = {&var12,&fEM_R0UN03RSS,&var26};
_S_bol  S_bol_61_1 = {&fEM_R0UL51RSS,&var19,&var27};
_S_react  S_react_57_1 = {&var19,&var28};
_S_bol  S_bol_42_1 = {&var12,&fEM_R0UR01RSS,&var29};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_77_1);
  diagndev(&S_diagndev_90_1);
  and2(&S_and2_92_1);
  or2(&S_or2_99_1);
  or2(&S_or2_107_1);
  ml(&S_ml_7_1);
  ml(&S_ml_8_1);
  ml(&S_ml_9_1);
  ocham(&S_ocham_22_1);
  orn(&S_orn_104_1);
  or3(&S_or3_101_1);
  noto(&S_noto_106_1);
  bol(&S_bol_42_1);
  bol(&S_bol_62_1);
  bol(&S_bol_51_1);
  bol(&S_bol_46_1);
  andn(&S_andn_75_1);
  period(&S_period_56_1);
  react(&S_react_57_1);
  bol(&S_bol_61_1);
  andn(&S_andn_65_1);
  bol(&S_bol_63_1);
  andn(&S_andn_66_1);
  setData(idTestDiagnAKNP4,&var6);
  setData(idTTLaknp4,&var10);
  setData(idR0DE3DLS4,&var4);
  setData(idR0DE3CLS4,&var5);
  setData(idA1EE01LS4,&var23);
  setData(idR0VN78LZ2,&var22);
  setData(idR0VN74LZ2,&var24);
  setData(idA0VN71LS4,&var29);
  setData(idR0IE02LS4,&var18);
  setData(idR0IE01LS4,&var18);
  setData(idR0VN15RS4,&var17);
  setData(idR0VN33RS4,&var16);
  setData(idR0VN23RS4,&var15);
  setData(idR0VN13RS4,&var14);
  setData(idA0EE02LS4,&var13);
  setData(idA1VN71LS4,&var29);
  setData(idR0VN04RS4,&var28);
  setData(idR0VN03RS4,&var11);
  setData(idA0EE01LS4,&var23);
  setData(idR0VN78LZ1,&var22);
  setData(idR0VN65LS4,&var20);
  setData(idR0VN74LZ1,&var24);
  setData(idR0VN61LS4,&var25);
  setData(idR0VN01RS4,&var19);
  setData(idR0VN02RS4,&var12);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}
