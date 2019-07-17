/* Определение внутренних параметров */
uspaint8 InternalBuf[51];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssint iRM_5_ = {5,0}; /* n - N-размерность массива входных параметров */ 
ssint iRM_2_ = {2,0}; /* n - N-размерность массива входных параметров */ 
sschar bRM_1_ = {1,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssint iRM_4_ = {4,0}; /* n - размерность массива значений */ 
ssint iRM_6_ = {6,0}; /* n - N-размерность массива x */ 
ssbool lRM_1_ = {1,0}; /*  */ 

uspaint8 SpaEEPROMBuf[180];

/* Определение переменных */
ssfloat var1;
ssfloat var2;
ssfloat var3;
ssfloat var4;
ssfloat var5;
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
ssbool var30;
ssfloat var31;
ssbool var32;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m101_x_1[6] = {&R0DE36LS4,&R0DE37LS4,&R0DE38LS4,&R0DE39LS4,&var8,&var7};
psint  array_m87_x_1[4] = {&R0DE01LS4,&R0DE02LS4,&R0DE04LS4,&R0DE05LS4};
psbool  array_m63_x_1[2] = {&var29,&var24};
psbool  array_m62_x_1[2] = {&var29,&var30};
psbool  array_m73_x_1[5] = {&var16,&R0IE11LS4,&R0IE12LS4,&R0IE13LS4,&lRM_1_};

/* Объявление структур */
_S_pogrvh  S_pogrvh_115_1 = {&R0IN02FV4,&fEM_R0IN21FN4,&fEM_R0IN22FN4,&var1};
_S_pogrvh  S_pogrvh_117_1 = {&R0IN03FV4,&fEM_R0IN31FN4,&fEM_R0IN32FN4,&var2};
_S_pogrvh  S_pogrvh_113_1 = {&R0IN01FV4,&fEM_R0IN11FN4,&fEM_R0IN12FN4,&var3};
_S_ml  S_ml_9_1 = {&R0IN03FI4,&var2,&R0IS01FI0,&var4};
_S_ml  S_ml_8_1 = {&R0IN02FI4,&var1,&R0IS01FI0,&var5};
_S_ml  S_ml_7_1 = {&R0IN01FI4,&var3,&R0IS01FI0,&var6};
_S_noto  S_noto_103_1 = {&var9,&vainSBool};
_S_or2  S_or2_104_1 = {&R0DEB3LS4,&R0DEB4LS4,&var7};
_S_or2  S_or2_96_1 = {&R0DEB1LS4,&R0DEB2LS4,&var8};
_S_or3  S_or3_98_1 = {&var12,&var11,&var10,&var9};
_S_orn  S_orn_101_1 = {array_m101_x_1,&iRM_6_,&var10};
_S_and2  S_and2_89_1 = {&R0DE31LS4,&R0DE32LS4,&var11};
_S_diagndev  S_diagndev_87_1 = {array_m87_x_1,&iRM_4_,&var12,&var13};
_S_ocham  S_ocham_18_1 = {&var6,&var5,&var4,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX10RSS,&fEM_B0UX10RSS,&fEM_A0UX11RSS,&fEM_B0UX11RSS,&fEM_A0UX12RSS,&fEM_B0UX12RSS,&fEM_R7UX10RSS,&fEM_R7UY10RSS,&fEM_R7UX11RSS,&fEM_R7UY11RSS,&fEM_R7UX12RSS,&fEM_R7UY12RSS,&bRM_1_,&fEM_R0UH01RSS,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&fEM_R0UH21RSS,&fEM_R0UH22RSS,&fEM_R0UH23RSS,&var14,&var15,&var16,&var17,&var18,&var19,&var20,&internal1_m18_Nk};
_S_or2  S_or2_74_1 = {&R0EE04LZ1,&R0EE04LZ2,&var21};
_S_period  S_period_56_1 = {&var15,&var26,&iRM_5_,&fEM_R0UL01RSS,&fEM_R0UL02RSS,&fEM_R0UN03RSS,&var22,&internal1_m56_flst,&internal1_m56_chsr,&internal1_m56_chizm,&internal1_m56_sumtim,&internal1_m56_W1,&internal1_m56_W2,&internal1_m56_Wmin,&internal1_m56_Wmax,&internal1_m56_Wlast,&internal1_m56_y0,&internal1_m56_MyFirstEnterFlag};
_S_andn  S_andn_63_1 = {array_m63_x_1,&iRM_2_,&var23};
_S_bol  S_bol_60_1 = {&fEM_R0UL41RSS,&var22,&var24};
_S_andn  S_andn_62_1 = {array_m62_x_1,&iRM_2_,&var25};
_S_andn  S_andn_73_1 = {array_m73_x_1,&iRM_5_,&var26};
_S_bol  S_bol_43_1 = {&var15,&fEM_R0UL52RSS,&var27};
_S_bol  S_bol_48_1 = {&var15,&fEM_R0UL42RSS,&var28};
_S_bol  S_bol_59_1 = {&var15,&fEM_R0UN03RSS,&var29};
_S_bol  S_bol_58_1 = {&fEM_R0UL51RSS,&var22,&var30};
_S_react  S_react_53_1 = {&var22,&var31};
_S_bol  S_bol_39_1 = {&var15,&fEM_R0UR01RSS,&var32};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_74_1);
  diagndev(&S_diagndev_87_1);
  and2(&S_and2_89_1);
  or2(&S_or2_96_1);
  or2(&S_or2_104_1);
  orn(&S_orn_101_1);
  or3(&S_or3_98_1);
  noto(&S_noto_103_1);
  pogrvh(&S_pogrvh_113_1);
  pogrvh(&S_pogrvh_117_1);
  pogrvh(&S_pogrvh_115_1);
  ml(&S_ml_7_1);
  ml(&S_ml_8_1);
  ml(&S_ml_9_1);
  ocham(&S_ocham_18_1);
  bol(&S_bol_39_1);
  bol(&S_bol_59_1);
  bol(&S_bol_48_1);
  bol(&S_bol_43_1);
  andn(&S_andn_73_1);
  period(&S_period_56_1);
  react(&S_react_53_1);
  bol(&S_bol_58_1);
  andn(&S_andn_62_1);
  bol(&S_bol_60_1);
  andn(&S_andn_63_1);
  setData(idR0IN02FS4,&var1);
  setData(idTestDiagnAKNP4,&var9);
  setData(idTTLaknp4,&var13);
  setData(idR0DE3DLS4,&var7);
  setData(idR0DE3CLS4,&var8);
  setData(idA1EE01LS4,&var26);
  setData(idR0VN78LZ2,&var25);
  setData(idR0VN74LZ2,&var27);
  setData(idA0VN71LS4,&var32);
  setData(idR0IE02LS4,&var21);
  setData(idR0IE01LS4,&var21);
  setData(idR0VN15RS4,&var20);
  setData(idR0VN33RS4,&var19);
  setData(idR0VN23RS4,&var18);
  setData(idR0VN13RS4,&var17);
  setData(idA0EE02LS4,&var16);
  setData(idR0IN03FS4,&var2);
  setData(idA1VN71LS4,&var32);
  setData(idR0VN04RS4,&var31);
  setData(idR0VN03RS4,&var14);
  setData(idR0IN01FS4,&var3);
  setData(idA0EE01LS4,&var26);
  setData(idR0VN78LZ1,&var25);
  setData(idR0VN65LS4,&var23);
  setData(idR0VN74LZ1,&var27);
  setData(idR0VN61LS4,&var28);
  setData(idR0VN01RS4,&var22);
  setData(idR0VN02RS4,&var15);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}
