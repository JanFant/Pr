/* Определение внутренних параметров */
uspaint8 InternalBuf[54];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssint iRM_5_ = {5,0}; /* n - N-размерность массива x */ 
sschar bRM_2_ = {2,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssint iRM_4_ = {4,0}; /* n - размерность массива значений */ 
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
ssbool var13;
ssint var14;
ssfloat var15;
ssbool var16;
ssbool var17;
ssfloat var18;
ssfloat var19;
ssbool var20;
ssfloat var21;
ssfloat var22;
ssfloat var23;
ssint var24;
ssbool var25;
ssfloat var26;
ssbool var27;
ssbool var28;
ssbool var29;
ssbool var30;
ssbool var31;
ssfloat var32;
ssbool var33;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m70_x_1[5] = {&lRM_1_,&var20,&R0IE13LS1,&R0IE12LS1,&R0IE11LS1};
psbool  array_m98_x_1[5] = {&var9,&var8,&R0DE37LS1,&R0DE38LS1,&R0DE39LS1};
psint  array_m87_x_1[4] = {&R0DE01LS1,&R0DE02LS1,&R0DE04LS1,&R0DE05LS1};

/* Объявление структур */
_S_pogrvh  S_pogrvh_117_1 = {&R0IN03FV1,&fEM_R0IN31FN1,&fEM_R0IN32FN1,&var1};
_S_pogrvh  S_pogrvh_115_1 = {&R0IN02FV1,&fEM_R0IN21FN1,&fEM_R0IN22FN1,&var2};
_S_pogrvh  S_pogrvh_113_1 = {&R0IN01FV1,&fEM_R0IN11FN1,&fEM_R0IN12FN1,&var3};
_S_ml  S_ml_9_1 = {&R0IN03FI1,&var1,&R0IS01FI0,&var4};
_S_ml  S_ml_8_1 = {&R0IN02FI1,&var2,&R0IS01FI0,&var5};
_S_ml  S_ml_7_1 = {&R0IN01FI1,&var3,&R0IS01FI0,&var6};
_S_noto  S_noto_102_1 = {&var11,&vainSBool};
_S_andn  S_andn_70_1 = {array_m70_x_1,&iRM_5_,&var7};
_S_or2  S_or2_103_1 = {&R0DEB3LS1,&R0DEB4LS1,&var8};
_S_or2  S_or2_96_1 = {&R0DEB1LS1,&R0DEB2LS1,&var9};
_S_orn  S_orn_98_1 = {array_m98_x_1,&iRM_5_,&var10};
_S_or3  S_or3_101_1 = {&var13,&var12,&var10,&var11};
_S_and2  S_and2_89_1 = {&R0DE31LS1,&R0DE32LS1,&var12};
_S_diagndev  S_diagndev_87_1 = {array_m87_x_1,&iRM_4_,&var13,&var14,&var15,&internal1_m87_sttlf};
_S_and2  S_and2_66_1 = {&var30,&var27,&var16};
_S_and2  S_and2_65_1 = {&var31,&var30,&var17};
_S_ocham  S_ocham_17_1 = {&var6,&var5,&var4,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX01RSS,&fEM_B0UX01RSS,&fEM_A0UX02RSS,&fEM_B0UX02RSS,&fEM_A0UX03RSS,&fEM_B0UX03RSS,&fEM_R7UX01RSS,&fEM_R7UY01RSS,&fEM_R7UX02RSS,&fEM_R7UY02RSS,&fEM_R7UX03RSS,&fEM_R7UY03RSS,&bRM_2_,&fEM_R0UH01RSS,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&fEM_R0UH21RSS,&fEM_R0UH22RSS,&fEM_R0UH23RSS,&var18,&var19,&var20,&var21,&var22,&var23,&var24,&internal1_m17_Nk};
_S_or2  S_or2_75_1 = {&R0EE01LZ1,&R0EE01LZ2,&var25};
_S_period  S_period_55_1 = {&var19,&var7,&iRM_5_,&fEM_R0UL01RSS,&fEM_R0UL02RSS,&fEM_R0UN03RSS,&var26,&internal1_m55_flst,&internal1_m55_chsr,&internal1_m55_chizm,&internal1_m55_sumtim,&internal1_m55_W1,&internal1_m55_W2,&internal1_m55_Wmin,&internal1_m55_Wmax,&internal1_m55_Wlast,&internal1_m55_y0,&internal1_m55_MyFirstEnterFlag};
_S_bol  S_bol_59_1 = {&fEM_R0UL41RSS,&var26,&var27};
_S_bol  S_bol_42_1 = {&var19,&fEM_R0UL52RSS,&var28};
_S_bol  S_bol_37_1 = {&var19,&fEM_R0UL42RSS,&var29};
_S_bol  S_bol_58_1 = {&var19,&fEM_R0UN03RSS,&var30};
_S_bol  S_bol_57_1 = {&fEM_R0UL51RSS,&var26,&var31};
_S_react  S_react_56_1 = {&var26,&var32};
_S_bol  S_bol_47_1 = {&var19,&fEM_R0UR01RSS,&var33};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_75_1);
  diagndev(&S_diagndev_87_1);
  and2(&S_and2_89_1);
  or2(&S_or2_96_1);
  or2(&S_or2_103_1);
  orn(&S_orn_98_1);
  pogrvh(&S_pogrvh_113_1);
  pogrvh(&S_pogrvh_115_1);
  pogrvh(&S_pogrvh_117_1);
  or3(&S_or3_101_1);
  noto(&S_noto_102_1);
  ml(&S_ml_7_1);
  ml(&S_ml_8_1);
  ml(&S_ml_9_1);
  ocham(&S_ocham_17_1);
  andn(&S_andn_70_1);
  bol(&S_bol_47_1);
  bol(&S_bol_58_1);
  bol(&S_bol_37_1);
  bol(&S_bol_42_1);
  period(&S_period_55_1);
  react(&S_react_56_1);
  bol(&S_bol_57_1);
  bol(&S_bol_59_1);
  and2(&S_and2_65_1);
  and2(&S_and2_66_1);
  setData(idttlAknp1,&var15);
  setData(idR0IN02FS1,&var2);
  setData(idR0IN03FS1,&var1);
  setData(idR0IN01FS1,&var3);
  setData(idTestDiagnAKNP1,&var11);
  setData(idR0DE3DLS1,&var8);
  setData(idR0DE3CLS1,&var9);
  setData(idTTLa1,&var14);
  setData(idA1VN71LS1,&var33);
  setData(idA1EE01LS1,&var7);
  setData(idR0VN75LZ2,&var17);
  setData(idR0VN71LZ2,&var28);
  setData(idR0IE02LS1,&var25);
  setData(idR0IE01LS1,&var25);
  setData(idR0VN15RS1,&var24);
  setData(idR0VN33RS1,&var23);
  setData(idR0VN23RS1,&var22);
  setData(idR0VN13RS1,&var21);
  setData(idA0EE02LS1,&var20);
  setData(idA0VN71LS1,&var33);
  setData(idR0VN04RS1,&var32);
  setData(idR0VN03RS1,&var18);
  setData(idA0EE01LS1,&var7);
  setData(idR0VN75LZ1,&var17);
  setData(idR0VN65LS1,&var16);
  setData(idR0VN71LZ1,&var28);
  setData(idR0VN61LS1,&var29);
  setData(idR0VN01RS1,&var26);
  setData(idR0VN02RS1,&var19);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}
