/* ����������� ���������� ���������� */
uspaint8 InternalBuf[112];

/* ����������� �������� ��� � ������*/
ssint iRM_5_ = {5,0}; /* n - N-����������� ������� ������� ���������� */ 
ssint iRM_2_ = {2,0}; /* n - N-����������� ������� ������� ���������� */ 
ssfloat fRM_2_0 = {2.0,0}; /* Kpr1 - �����. �������������� �������->�����/� ���-11 */ 
sschar bRM_1_ = {1,0}; /* type - ��� ������ ���-11 1- ��� ��1, 2- ��� ��2, >2 ��� */ 
ssint iRM_4_ = {4,0}; /* n - ����������� ������� �������� */ 
ssint iRM_6_ = {6,0}; /* n - N-����������� ������� x */ 

uspaint8 SpaEEPROMBuf[130];

/* ����������� ���������� */
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

/* ���������� �������� */
psbool  array_m101_x_1[6] = {&R0DE36LS4,&R0DE37LS4,&R0DE38LS4,&R0DE39LS4,&var6,&var5};
psint  array_m87_x_1[4] = {&R0DE01LS4,&R0DE02LS4,&R0DE04LS4,&R0DE05LS4};
psfloat  array_m52_tst_1[5];
psfloat  array_m52_trz_1[5];
psfloat  array_m52_N1_1[5];
psfloat  array_m52_N2_1[5];
psbool  array_m62_x_1[2] = {&var26,&var22};
psbool  array_m61_x_1[2] = {&var26,&var27};
psbool  array_m70_x_1[5] = {&var14,&R0IE11LS4,&R0IE12LS4,&R0IE13LS4,&var4};

/* ���������� �������� */
_S_ml  S_ml_9_1 = {&R0IN03FI4,&R0IN03FS4,&R0IS01FI0,&var1};
_S_ml  S_ml_8_1 = {&R0IN02FI4,&R0IN02FS4,&R0IS01FI0,&var2};
_S_ml  S_ml_7_1 = {&R0IN01FI4,&R0IN01FS4,&R0IS01FI0,&var3};
_S_noto  S_noto_103_1 = {&var7,&var4};
_S_or2  S_or2_104_1 = {&R0DEB3LS4,&R0DEB4LS4,&var5};
_S_or2  S_or2_96_1 = {&R0DEB1LS4,&R0DEB2LS4,&var6};
_S_or3  S_or3_98_1 = {&var10,&var9,&var8,&var7};
_S_orn  S_orn_101_1 = {array_m101_x_1,&iRM_6_,&var8};
_S_and2  S_and2_89_1 = {&R0DE31LS4,&R0DE32LS4,&var9};
_S_diagndev  S_diagndev_87_1 = {array_m87_x_1,&iRM_4_,&var10,&var11};
_S_ocham  S_ocham_20_1 = {&var3,&var2,&var1,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX10RSS,&fEM_B0UX10RSS,&fEM_A0UX11RSS,&fEM_B0UX11RSS,&fEM_A0UX12RSS,&fEM_B0UX12RSS,&fEM_R7UX10RSS,&fEM_R7UY10RSS,&fEM_R7UX11RSS,&fEM_R7UY11RSS,&fEM_R7UX12RSS,&fEM_R7UY12RSS,&bRM_1_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&var12,&var13,&var14,&var15,&var16,&var17,&var18,&internal1_m20_Nk};
_S_or2  S_or2_73_1 = {&R0EE04LZ1,&R0EE04LZ2,&var19};
_S_period  S_period_52_1 = {&var13,&lEM_EE01LS4,&iRM_5_,&var30,&var31,&fEM_R0UN03RSS,&var20,array_m52_tst_1,array_m52_trz_1,array_m52_N1_1,array_m52_N2_1,&internal1_m52_Period0,&internal1_m52_MyFirstEnterFlag};
_S_andn  S_andn_62_1 = {array_m62_x_1,&iRM_2_,&var21};
_S_bol  S_bol_59_1 = {&fEM_R0UL41RSS,&var20,&var22};
_S_andn  S_andn_61_1 = {array_m61_x_1,&iRM_2_,&var23};
_S_andn  S_andn_70_1 = {array_m70_x_1,&iRM_5_,&vainSBool};
_S_bol  S_bol_42_1 = {&var13,&fEM_R0UL52RSS,&var24};
_S_bol  S_bol_47_1 = {&var13,&fEM_R0UL42RSS,&var25};
_S_bol  S_bol_58_1 = {&var13,&fEM_R0UN03RSS,&var26};
_S_bol  S_bol_57_1 = {&fEM_R0UL51RSS,&var20,&var27};
_S_react  S_react_53_1 = {&var20,&var28};
_S_bol  S_bol_38_1 = {&var13,&fEM_R0UR01RSS,&var29};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_73_1);
  diagndev(&S_diagndev_87_1);
  and2(&S_and2_89_1);
  or2(&S_or2_96_1);
  or2(&S_or2_104_1);
  ml(&S_ml_7_1);
  ml(&S_ml_8_1);
  ml(&S_ml_9_1);
  ocham(&S_ocham_20_1);
  orn(&S_orn_101_1);
  or3(&S_or3_98_1);
  noto(&S_noto_103_1);
  bol(&S_bol_38_1);
  bol(&S_bol_58_1);
  bol(&S_bol_47_1);
  bol(&S_bol_42_1);
  andn(&S_andn_70_1);
  setData(&var30,&iEM_R0UL01ISS);
  setData(&var31,&dEM_R0UL02USS);
  period(&S_period_52_1);
  react(&S_react_53_1);
  bol(&S_bol_57_1);
  andn(&S_andn_61_1);
  bol(&S_bol_59_1);
  andn(&S_andn_62_1);
  setData(idTestDiagnAKNP4,&var7);
  setData(idTTLaknp4,&var11);
  setData(idR0DE3DLS4,&var5);
  setData(idR0DE3CLS4,&var6);
  setData(idA1EE01LS4,&lEM_EE01LS4);
  setData(idR0VN78LZ2,&var23);
  setData(idR0VN74LZ2,&var24);
  setData(idA0VN71LS4,&var29);
  setData(idR0IE02LS4,&var19);
  setData(idR0IE01LS4,&var19);
  setData(idR0VN15RS4,&var18);
  setData(idR0VN33RS4,&var17);
  setData(idR0VN23RS4,&var16);
  setData(idR0VN13RS4,&var15);
  setData(idA0EE02LS4,&var14);
  setData(idA1VN71LS4,&var29);
  setData(idR0VN04RS4,&var28);
  setData(idR0VN03RS4,&var12);
  setData(idA0EE01LS4,&lEM_EE01LS4);
  setData(idR0VN78LZ1,&var23);
  setData(idR0VN65LS4,&var21);
  setData(idR0VN74LZ1,&var24);
  setData(idR0VN61LS4,&var25);
  setData(idR0VN01RS4,&var20);
  setData(idR0VN02RS4,&var13);

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
