/* Определение внутренних параметров */
uspaint8 InternalBuf[54];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssint iRM_5_ = {5,0}; /* n - N-размерность массива входных параметров */ 
ssint iRM_2_ = {2,0}; /* n - N-размерность массива входных параметров */ 
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
psbool  array_m101_x_1[5] = {&var8,&var7,&R0DE37LS2,&R0DE38LS2,&R0DE39LS2};
psint  array_m87_x_1[4] = {&R0DE01LS2,&R0DE02LS2,&R0DE04LS2,&R0DE05LS2};
psbool  array_m63_x_1[2] = {&var29,&var24};
psbool  array_m62_x_1[2] = {&var29,&var30};
psbool  array_m71_x_1[5] = {&var16,&R0IE11LS2,&R0IE12LS2,&R0IE13LS2,&lRM_1_};

/* Объявление структур */
_S_pogrvh  S_pogrvh_116_1 = {&R0IN03FV2,&fEM_R0IN31FN2,&fEM_R0IN32FN2,&var1};
_S_pogrvh  S_pogrvh_114_1 = {&R0IN02FV2,&fEM_R0IN21FN2,&fEM_R0IN22FN2,&var2};
_S_pogrvh  S_pogrvh_112_1 = {&R0IN01FV2,&fEM_R0IN11FN2,&fEM_R0IN12FN2,&var3};
_S_ml  S_ml_8_1 = {&R0IN03FI2,&var1,&R0IS01FI0,&var4};
_S_ml  S_ml_7_1 = {&R0IN02FI2,&var2,&R0IS01FI0,&var5};
_S_ml  S_ml_6_1 = {&R0IN01FI2,&var3,&R0IS01FI0,&var6};
_S_noto  S_noto_98_1 = {&var9,&vainSBool};
_S_or2  S_or2_104_1 = {&R0DEB3LS2,&R0DEB4LS2,&var7};
_S_or2  S_or2_95_1 = {&R0DEB1LS2,&R0DEB2LS2,&var8};
_S_or3  S_or3_97_1 = {&var12,&var11,&var10,&var9};
_S_orn  S_orn_101_1 = {array_m101_x_1,&iRM_5_,&var10};
_S_and2  S_and2_89_1 = {&R0DE31LS2,&R0DE32LS2,&var11};
_S_diagndev  S_diagndev_87_1 = {array_m87_x_1,&iRM_4_,&var12,&var13,&vainSFloat,&internal1_m87_sttlf};
_S_ocham  S_ocham_17_1 = {&var6,&var5,&var4,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX04RSS,&fEM_B0UX04RSS,&fEM_A0UX05RSS,&fEM_B0UX05RSS,&fEM_A0UX06RSS,&fEM_B0UX06RSS,&fEM_R7UX04RSS,&fEM_R7UY04RSS,&fEM_R7UX05RSS,&fEM_R7UY05RSS,&fEM_R7UX06RSS,&fEM_R7UY06RSS,&bRM_2_,&fEM_R0UH01RSS,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&fEM_R0UH21RSS,&fEM_R0UH22RSS,&fEM_R0UH23RSS,&var14,&var15,&var16,&var17,&var18,&var19,&var20,&internal1_m17_Nk};
_S_or2  S_or2_74_1 = {&R0EE02LZ1,&R0EE02LZ2,&var21};
_S_period  S_period_54_1 = {&var15,&var26,&iRM_5_,&fEM_R0UL01RSS,&fEM_R0UL02RSS,&fEM_R0UN03RSS,&var22,&internal1_m54_flst,&internal1_m54_chsr,&internal1_m54_chizm,&internal1_m54_sumtim,&internal1_m54_W1,&internal1_m54_W2,&internal1_m54_Wmin,&internal1_m54_Wmax,&internal1_m54_Wlast,&internal1_m54_y0,&internal1_m54_MyFirstEnterFlag};
_S_andn  S_andn_63_1 = {array_m63_x_1,&iRM_2_,&var23};
_S_bol  S_bol_60_1 = {&fEM_R0UL41RSS,&var22,&var24};
_S_andn  S_andn_62_1 = {array_m62_x_1,&iRM_2_,&var25};
_S_andn  S_andn_71_1 = {array_m71_x_1,&iRM_5_,&var26};
_S_bol  S_bol_42_1 = {&var15,&fEM_R0UL52RSS,&var27};
_S_bol  S_bol_48_1 = {&var15,&fEM_R0UL42RSS,&var28};
_S_bol  S_bol_59_1 = {&var15,&fEM_R0UN03RSS,&var29};
_S_bol  S_bol_58_1 = {&fEM_R0UL51RSS,&var22,&var30};
_S_react  S_react_55_1 = {&var22,&var31};
_S_bol  S_bol_38_1 = {&var15,&fEM_R0UR01RSS,&var32};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_74_1);
  diagndev(&S_diagndev_87_1);
  and2(&S_and2_89_1);
  or2(&S_or2_95_1);
  or2(&S_or2_104_1);
  orn(&S_orn_101_1);
  or3(&S_or3_97_1);
  noto(&S_noto_98_1);
  pogrvh(&S_pogrvh_112_1);
  pogrvh(&S_pogrvh_114_1);
  pogrvh(&S_pogrvh_116_1);
  ml(&S_ml_6_1);
  ml(&S_ml_7_1);
  ml(&S_ml_8_1);
  ocham(&S_ocham_17_1);
  bol(&S_bol_38_1);
  bol(&S_bol_59_1);
  bol(&S_bol_48_1);
  bol(&S_bol_42_1);
  andn(&S_andn_71_1);
  period(&S_period_54_1);
  react(&S_react_55_1);
  bol(&S_bol_58_1);
  andn(&S_andn_62_1);
  bol(&S_bol_60_1);
  andn(&S_andn_63_1);
  setData(idR0IN02FS2,&var2);
  setData(idR0IN03FS2,&var1);
  setData(idR0IN01FS2,&var3);
  setData(idTestDiagnAKNP2,&var9);
  setData(idR0DE3DLS2,&var7);
  setData(idR0DE3CLS2,&var8);
  setData(idTTLaknp2,&var13);
  setData(idA0VN71LS2,&var32);
  setData(idA1EE01LS2,&var26);
  setData(idR0VN76LZ2,&var25);
  setData(idR0VN72LZ2,&var27);
  setData(idR0IE02LS2,&var21);
  setData(idR0IE01LS2,&var21);
  setData(idR0VN15RS2,&var20);
  setData(idR0VN33RS2,&var19);
  setData(idR0VN23RS2,&var18);
  setData(idR0VN13RS2,&var17);
  setData(idA0EE02LS2,&var16);
  setData(idA1VN71LS2,&var32);
  setData(idR0VN04RS2,&var31);
  setData(idR0VN03RS2,&var14);
  setData(idA0EE01LS2,&var26);
  setData(idR0VN76LZ1,&var25);
  setData(idR0VN65LS2,&var23);
  setData(idR0VN72LZ1,&var27);
  setData(idR0VN61LS2,&var28);
  setData(idR0VN01RS2,&var22);
  setData(idR0VN02RS2,&var15);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}
