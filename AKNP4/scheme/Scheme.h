/* ����������� ���������� ���������� */
uspaint8 InternalBuf[56];

/* ����������� �������� ��� � ������*/
ssint iRM_5_ = {5,0}; /* n - N-����������� ������� ������� ���������� */ 
ssint iRM_2_ = {2,0}; /* n - N-����������� ������� ������� ���������� */ 
sschar bRM_1_ = {1,0}; /* type - ��� ������ ���-11 1- ��� ��1, 2- ��� ��2, >2 ��� */ 
ssint iRM_4_ = {4,0}; /* n - ����������� ������� �������� */ 
ssint iRM_6_ = {6,0}; /* n - N-����������� ������� x */ 
ssbool lRM_1_ = {1,0}; /*  */ 
ssfloat fRM_1_ = {1,0}; /* k - K�-����������� �������� */ 
ssfloat fRM_3_ = {3,0}; /* tau - T�-���������� �������, � */ 

uspaint8 SpaEEPROMBuf[180];

/* ����������� ���������� */
ssfloat var1;
ssfloat var2;
ssfloat var3;
ssfloat var4;
ssfloat var5;
ssfloat var6;
ssfloat var7;
ssbool var8;
ssbool var9;
ssbool var10;
ssbool var11;
ssbool var12;
ssbool var13;
ssint var14;
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

/* ���������� �������� */
psbool  array_m102_x_1[6] = {&R0DE36LS4,&R0DE37LS4,&R0DE38LS4,&R0DE39LS4,&var9,&var8};
psint  array_m88_x_1[4] = {&R0DE01LS4,&R0DE02LS4,&R0DE04LS4,&R0DE05LS4};
psbool  array_m64_x_1[2] = {&var30,&var25};
psbool  array_m63_x_1[2] = {&var30,&var31};
psbool  array_m74_x_1[5] = {&var17,&R0IE11LS4,&R0IE12LS4,&R0IE13LS4,&lRM_1_};

/* ���������� �������� */
_S_mod1  S_mod1_56_1 = {&var23,&fRM_1_,&fRM_3_,&var1,&internal1_m56_y0};
_S_pogrvh  S_pogrvh_116_1 = {&R0IN02FV4,&fEM_R0IN21FN4,&fEM_R0IN22FN4,&var2};
_S_pogrvh  S_pogrvh_118_1 = {&R0IN03FV4,&fEM_R0IN31FN4,&fEM_R0IN32FN4,&var3};
_S_pogrvh  S_pogrvh_114_1 = {&R0IN01FV4,&fEM_R0IN11FN4,&fEM_R0IN12FN4,&var4};
_S_ml  S_ml_9_1 = {&R0IN03FI4,&var3,&R0IS01FI0,&var5};
_S_ml  S_ml_8_1 = {&R0IN02FI4,&var2,&R0IS01FI0,&var6};
_S_ml  S_ml_7_1 = {&R0IN01FI4,&var4,&R0IS01FI0,&var7};
_S_noto  S_noto_104_1 = {&var10,&vainSBool};
_S_or2  S_or2_105_1 = {&R0DEB3LS4,&R0DEB4LS4,&var8};
_S_or2  S_or2_97_1 = {&R0DEB1LS4,&R0DEB2LS4,&var9};
_S_or3  S_or3_99_1 = {&var13,&var12,&var11,&var10};
_S_orn  S_orn_102_1 = {array_m102_x_1,&iRM_6_,&var11};
_S_and2  S_and2_90_1 = {&R0DE31LS4,&R0DE32LS4,&var12};
_S_diagndev  S_diagndev_88_1 = {array_m88_x_1,&iRM_4_,&var13,&var14};
_S_ocham  S_ocham_18_1 = {&var7,&var6,&var5,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX10RSS,&fEM_B0UX10RSS,&fEM_A0UX11RSS,&fEM_B0UX11RSS,&fEM_A0UX12RSS,&fEM_B0UX12RSS,&fEM_R7UX10RSS,&fEM_R7UY10RSS,&fEM_R7UX11RSS,&fEM_R7UY11RSS,&fEM_R7UX12RSS,&fEM_R7UY12RSS,&bRM_1_,&fEM_R0UH01RSS,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&fEM_R0UH21RSS,&fEM_R0UH22RSS,&fEM_R0UH23RSS,&var15,&var16,&var17,&var18,&var19,&var20,&var21,&internal1_m18_Nk};
_S_or2  S_or2_75_1 = {&R0EE04LZ1,&R0EE04LZ2,&var22};
_S_period  S_period_55_1 = {&var16,&var27,&iRM_5_,&fEM_R0UL01RSS,&fEM_R0UL02RSS,&fEM_R0UN03RSS,&var23,&internal1_m55_flst,&internal1_m55_chsr,&internal1_m55_chizm,&internal1_m55_sumtim,&internal1_m55_W1,&internal1_m55_W2,&internal1_m55_Wmin,&internal1_m55_Wmax,&internal1_m55_Wlast,&internal1_m55_y0,&internal1_m55_MyFirstEnterFlag};
_S_andn  S_andn_64_1 = {array_m64_x_1,&iRM_2_,&var24};
_S_bol  S_bol_61_1 = {&fEM_R0UL41RSS,&var1,&var25};
_S_andn  S_andn_63_1 = {array_m63_x_1,&iRM_2_,&var26};
_S_andn  S_andn_74_1 = {array_m74_x_1,&iRM_5_,&var27};
_S_bol  S_bol_43_1 = {&var16,&fEM_R0UL52RSS,&var28};
_S_bol  S_bol_48_1 = {&var16,&fEM_R0UL42RSS,&var29};
_S_bol  S_bol_60_1 = {&var16,&fEM_R0UN03RSS,&var30};
_S_bol  S_bol_59_1 = {&fEM_R0UL51RSS,&var1,&var31};
_S_react  S_react_57_1 = {&var1,&var32};
_S_bol  S_bol_39_1 = {&var16,&fEM_R0UR01RSS,&var33};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_75_1);
  diagndev(&S_diagndev_88_1);
  and2(&S_and2_90_1);
  or2(&S_or2_97_1);
  or2(&S_or2_105_1);
  orn(&S_orn_102_1);
  or3(&S_or3_99_1);
  noto(&S_noto_104_1);
  pogrvh(&S_pogrvh_114_1);
  pogrvh(&S_pogrvh_118_1);
  pogrvh(&S_pogrvh_116_1);
  ml(&S_ml_7_1);
  ml(&S_ml_8_1);
  ml(&S_ml_9_1);
  ocham(&S_ocham_18_1);
  bol(&S_bol_39_1);
  bol(&S_bol_60_1);
  bol(&S_bol_48_1);
  bol(&S_bol_43_1);
  andn(&S_andn_74_1);
  period(&S_period_55_1);
  mod1(&S_mod1_56_1);
  react(&S_react_57_1);
  bol(&S_bol_59_1);
  andn(&S_andn_63_1);
  bol(&S_bol_61_1);
  andn(&S_andn_64_1);
  setData(idR0IN02FS4,&var2);
  setData(idTestDiagnAKNP4,&var10);
  setData(idTTLaknp4,&var14);
  setData(idR0DE3DLS4,&var8);
  setData(idR0DE3CLS4,&var9);
  setData(idA1EE01LS4,&var27);
  setData(idR0VN78LZ2,&var26);
  setData(idR0VN74LZ2,&var28);
  setData(idA0VN71LS4,&var33);
  setData(idR0IE02LS4,&var22);
  setData(idR0IE01LS4,&var22);
  setData(idR0VN15RS4,&var21);
  setData(idR0VN33RS4,&var20);
  setData(idR0VN23RS4,&var19);
  setData(idR0VN13RS4,&var18);
  setData(idA0EE02LS4,&var17);
  setData(idR0IN03FS4,&var3);
  setData(idA1VN71LS4,&var33);
  setData(idR0VN04RS4,&var32);
  setData(idR0VN03RS4,&var15);
  setData(idR0IN01FS4,&var4);
  setData(idA0EE01LS4,&var27);
  setData(idR0VN78LZ1,&var26);
  setData(idR0VN65LS4,&var24);
  setData(idR0VN74LZ1,&var28);
  setData(idR0VN61LS4,&var29);
  setData(idR0VN01RS4,&var1);
  setData(idR0VN02RS4,&var16);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}
