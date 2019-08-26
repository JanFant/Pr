/* Определение внутренних параметров */
uspaint8 InternalBuf[51];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssint iRM_5_ = {5,0}; /* n - N-размерность массива входных параметров */ 
ssint iRM_2_ = {2,0}; /* n - N-размерность массива входных параметров */ 
sschar bRM_1_ = {1,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssint iRM_4_ = {4,0}; /* n - размерность массива значений */ 
ssint iRM_6_ = {6,0}; /* n - N-размерность массива x */ 
ssbool lRM_1_ = {1,0}; /*  */ 
ssfloat fRM_1_ = {1,0}; /* k - Kф-коэффициент усиления */ 
ssfloat fRM_3_ = {3,0}; /* tau - Tф-постоянная времени, с */ 

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
psbool  array_m101_x_1[6] = {&var8,&var7,&R0DE36LS3,&R0DE37LS3,&R0DE38LS3,&R0DE39LS3};
psint  array_m87_x_1[4] = {&R0DE01LS3,&R0DE02LS3,&R0DE04LS3,&R0DE05LS3};
psbool  array_m63_x_1[2] = {&var29,&var24};
psbool  array_m62_x_1[2] = {&var29,&var30};
psbool  array_m73_x_1[5] = {&var16,&R0IE11LS3,&R0IE12LS3,&R0IE13LS3,&lRM_1_};

/* Объявление структур */
_S_pogrvh  S_pogrvh_117_1 = {&R0IN03FV3,&fEM_R0IN31FN3,&fEM_R0IN32FN3,&var1};
_S_pogrvh  S_pogrvh_115_1 = {&R0IN02FV3,&fEM_R0IN21FN3,&fEM_R0IN22FN3,&var2};
_S_pogrvh  S_pogrvh_113_1 = {&R0IN01FV3,&fEM_R0IN11FN3,&fEM_R0IN12FN3,&var3};
_S_ml  S_ml_8_1 = {&R0IN03FI3,&var1,&R0IS01FI0,&var4};
_S_ml  S_ml_7_1 = {&R0IN02FI3,&var2,&R0IS01FI0,&var5};
_S_ml  S_ml_6_1 = {&R0IN01FI3,&var3,&R0IS01FI0,&var6};
_S_noto  S_noto_102_1 = {&var9,&vainSBool};
_S_or2  S_or2_104_1 = {&R0DEB3LS3,&R0DEB4LS3,&var7};
_S_or2  S_or2_96_1 = {&R0DEB1LS3,&R0DEB2LS3,&var8};
_S_or3  S_or3_98_1 = {&var12,&var11,&var10,&var9};
_S_orn  S_orn_101_1 = {array_m101_x_1,&iRM_6_,&var10};
_S_and2  S_and2_89_1 = {&R0DE31LS3,&R0DE32LS3,&var11};
_S_diagndev  S_diagndev_87_1 = {array_m87_x_1,&iRM_4_,&var12,&var13,&vainSFloat};
_S_ocham  S_ocham_19_1 = {&var6,&var5,&var4,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX07RSS,&fEM_B0UX07RSS,&fEM_A0UX08RSS,&fEM_B0UX08RSS,&fEM_A0UX09RSS,&fEM_B0UX09RSS,&fEM_R7UX07RSS,&fEM_R7UY07RSS,&fEM_R7UX08RSS,&fEM_R7UY08RSS,&fEM_R7UX09RSS,&fEM_R7UY09RSS,&bRM_1_,&fEM_R0UH01RSS,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&fEM_R0UH21RSS,&fEM_R0UH22RSS,&fEM_R0UH23RSS,&var14,&var15,&var16,&var17,&var18,&var19,&var20,&internal1_m19_Nk};
_S_or2  S_or2_75_1 = {&R0EE03LZ1,&R0EE03LZ2,&var21};
_S_period  S_period_55_1 = {&var15,&var26,&iRM_5_,&fEM_R0UL01RSS,&fEM_R0UL02RSS,&fEM_R0UN03RSS,&var22,&internal1_m55_flst,&internal1_m55_chsr,&internal1_m55_chizm,&internal1_m55_sumtim,&internal1_m55_W1,&internal1_m55_W2,&internal1_m55_Wmin,&internal1_m55_Wmax,&internal1_m55_Wlast,&internal1_m55_y0,&internal1_m55_MyFirstEnterFlag};
_S_andn  S_andn_63_1 = {array_m63_x_1,&iRM_2_,&var23};
_S_bol  S_bol_60_1 = {&fEM_R0UL41RSS,&var22,&var24};
_S_andn  S_andn_62_1 = {array_m62_x_1,&iRM_2_,&var25};
_S_andn  S_andn_73_1 = {array_m73_x_1,&iRM_5_,&var26};
_S_bol  S_bol_43_1 = {&var15,&fEM_R0UL52RSS,&var27};
_S_bol  S_bol_48_1 = {&var15,&fEM_R0UL42RSS,&var28};
_S_bol  S_bol_59_1 = {&var15,&fEM_R0UN03RSS,&var29};
_S_bol  S_bol_58_1 = {&fEM_R0UL51RSS,&var22,&var30};
_S_react  S_react_56_1 = {&var22,&var31};
_S_bol  S_bol_38_1 = {&var15,&fEM_R0UR01RSS,&var32};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_75_1);
  diagndev(&S_diagndev_87_1);
  and2(&S_and2_89_1);
  or2(&S_or2_96_1);
  or2(&S_or2_104_1);
  orn(&S_orn_101_1);
  or3(&S_or3_98_1);
  noto(&S_noto_102_1);
  pogrvh(&S_pogrvh_113_1);
  pogrvh(&S_pogrvh_115_1);
  pogrvh(&S_pogrvh_117_1);
  ml(&S_ml_6_1);
  ml(&S_ml_7_1);
  ml(&S_ml_8_1);
  ocham(&S_ocham_19_1);
  bol(&S_bol_38_1);
  bol(&S_bol_59_1);
  bol(&S_bol_48_1);
  bol(&S_bol_43_1);
  andn(&S_andn_73_1);
  period(&S_period_55_1);
  react(&S_react_56_1);
  bol(&S_bol_58_1);
  andn(&S_andn_62_1);
  bol(&S_bol_60_1);
  andn(&S_andn_63_1);
  setData(idR0IN02FS3,&var2);
  setData(idR0IN03FS3,&var1);
  setData(idR0IN01FS3,&var3);
  setData(idTestDiagnAKNP3,&var9);
  setData(idTTLaknp3,&var13);
  setData(idR0DE3DLS3,&var7);
  setData(idR0DE3CLS3,&var8);
  setData(idA1EE01LS3,&var26);
  setData(idR0VN77LZ2,&var25);
  setData(idR0VN73LZ2,&var27);
  setData(idA0VN71LS3,&var32);
  setData(idR0IE02LS3,&var21);
  setData(idR0IE01LS3,&var21);
  setData(idR0VN15RS3,&var20);
  setData(idR0VN33RS3,&var19);
  setData(idR0VN23RS3,&var18);
  setData(idR0VN13RS3,&var17);
  setData(idA0EE02LS3,&var16);
  setData(idA1VN71LS3,&var32);
  setData(idR0VN04RS3,&var31);
  setData(idR0VN03RS3,&var14);
  setData(idA0EE01LS3,&var26);
  setData(idR0VN77LZ1,&var25);
  setData(idR0VN65LS3,&var23);
  setData(idR0VN73LZ1,&var27);
  setData(idR0VN61LS3,&var28);
  setData(idR0VN01RS3,&var22);
  setData(idR0VN02RS3,&var15);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}
