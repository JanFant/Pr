/* ����������� ���������� ���������� */
uspaint8 InternalBuf[112];

/* ����������� �������� ��� � ������*/
ssint iRM_5_ = {5,0}; /* n - N-����������� ������� x */ 
ssfloat fRM_2_0 = {2.0,0}; /* Kpr1 - �����. �������������� �������->�����/� ���-11 */ 
sschar bRM_2_ = {2,0}; /* type - ��� ������ ���-11 1- ��� ��1, 2- ��� ��2, >2 ��� */ 
ssint iRM_4_ = {4,0}; /* n - ����������� ������� �������� */ 
ssint iRM_2_ = {2,0}; /* n - N-����������� ������� x */ 
ssint iRM_1_ = {1,0}; /* x2 - ������ ��������� */ 
ssfloat fRM_0_0009765625 = {0.0009765625,0}; /*  */ 

uspaint8 SpaEEPROMBuf[132];

/* ����������� ���������� */
ssfloat var1;
ssbool var2;
ssfloat var3;
ssfloat var4;
ssfloat var5;
ssint var6;
ssbool var7;
ssbool var8;
ssbool var9;
ssbool var10;
ssbool var11;
ssbool var12;
ssint var13;
ssbool var14;
ssbool var15;
ssfloat var16;
ssfloat var17;
ssbool var18;
ssfloat var19;
ssfloat var20;
ssfloat var21;
ssint var22;
ssbool var23;
ssfloat var24;
ssbool var25;
ssbool var26;
ssbool var27;
ssbool var28;
ssbool var29;
ssfloat var30;
ssbool var31;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* ���������� �������� */
psbool  array_m72_x_1[5] = {&var2,&var18,&R0IE13LS1,&R0IE12LS1,&R0IE11LS1};
psfloat  array_m9_x_1[2] = {&R0IN03FS1,&R0IN03FI1};
psfloat  array_m8_x_1[2] = {&R0IN02FS1,&R0IN02FI1};
psfloat  array_m7_x_1[2] = {&R0IN01FS1,&R0IN01FI1};
psbool  array_m100_x_1[5] = {&var8,&var7,&R0DE37LS1,&R0DE38LS1,&R0DE39LS1};
psint  array_m90_x_1[4] = {&R0DE01LS1,&R0DE02LS1,&R0DE04LS1,&R0DE05LS1};
psfloat  array_m55_tst_1[5];
psfloat  array_m55_trz_1[5];
psfloat  array_m55_N1_1[5];
psfloat  array_m55_N2_1[5];

/* ���������� �������� */
_S_ampll  S_ampll_46_1 = {&B8IC01UDU,&fRM_0_0009765625,&var1};
_S_noto  S_noto_104_1 = {&var10,&var2};
_S_andn  S_andn_72_1 = {array_m72_x_1,&iRM_5_,&vainSBool};
_S_ma  S_ma_9_1 = {array_m9_x_1,&var6,&iRM_2_,&var3};
_S_ma  S_ma_8_1 = {array_m8_x_1,&var6,&iRM_2_,&var4};
_S_ma  S_ma_7_1 = {array_m7_x_1,&var6,&iRM_2_,&var5};
_S_fsumz  S_fsumz_2_1 = {&R0IS01FI0,&iRM_1_,&var6};
_S_or2  S_or2_105_1 = {&R0DEB3LS1,&R0DEB4LS1,&var7};
_S_or2  S_or2_98_1 = {&R0DEB1LS1,&R0DEB2LS1,&var8};
_S_orn  S_orn_100_1 = {array_m100_x_1,&iRM_5_,&var9};
_S_or3  S_or3_103_1 = {&var12,&var11,&var9,&var10};
_S_and2  S_and2_92_1 = {&R0DE31LS1,&R0DE32LS1,&var11};
_S_diagndev  S_diagndev_90_1 = {array_m90_x_1,&iRM_4_,&var12,&var13};
_S_and2  S_and2_68_1 = {&var28,&var25,&var14};
_S_and2  S_and2_67_1 = {&var29,&var28,&var15};
_S_ocham  S_ocham_20_1 = {&var5,&var4,&var3,&var1,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX01RSS,&fEM_B0UX01RSS,&fEM_A0UX02RSS,&fEM_B0UX02RSS,&fEM_A0UX03RSS,&fEM_B0UX03RSS,&fEM_R7UX01RSS,&fEM_R7UY01RSS,&fEM_R7UX02RSS,&fEM_R7UY02RSS,&fEM_R7UX03RSS,&fEM_R7UY03RSS,&bRM_2_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&var16,&var17,&var18,&var19,&var20,&var21,&var22,&internal1_m20_Nk};
_S_or2  S_or2_78_1 = {&R0EE01LZ1,&R0EE01LZ2,&var23};
_S_period  S_period_55_1 = {&var17,&lEM_EE01LS1,&iRM_5_,&fEM_R0UL01RSS,&fEM_R0UL02RSS,&fEM_R0UN03RSS,&var24,array_m55_tst_1,array_m55_trz_1,array_m55_N1_1,array_m55_N2_1,&internal1_m55_Period0,&internal1_m55_MyFirstEnterFlag};
_S_bol  S_bol_61_1 = {&fEM_R0UL41RSS,&var24,&var25};
_S_bol  S_bol_44_1 = {&var17,&fEM_R0UL52RSS,&var26};
_S_bol  S_bol_38_1 = {&var17,&fEM_R0UL42RSS,&var27};
_S_bol  S_bol_60_1 = {&var17,&fEM_R0UN03RSS,&var28};
_S_bol  S_bol_59_1 = {&fEM_R0UL51RSS,&var24,&var29};
_S_react  S_react_56_1 = {&var24,&var30};
_S_bol  S_bol_49_1 = {&var17,&fEM_R0UR01RSS,&var31};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_78_1);
  diagndev(&S_diagndev_90_1);
  and2(&S_and2_92_1);
  or2(&S_or2_98_1);
  or2(&S_or2_105_1);
  fsumz(&S_fsumz_2_1);
  ma(&S_ma_7_1);
  ma(&S_ma_8_1);
  ma(&S_ma_9_1);
  ampll(&S_ampll_46_1);
  ocham(&S_ocham_20_1);
  orn(&S_orn_100_1);
  bol(&S_bol_49_1);
  bol(&S_bol_60_1);
  bol(&S_bol_38_1);
  bol(&S_bol_44_1);
  period(&S_period_55_1);
  or3(&S_or3_103_1);
  noto(&S_noto_104_1);
  react(&S_react_56_1);
  bol(&S_bol_59_1);
  bol(&S_bol_61_1);
  and2(&S_and2_67_1);
  and2(&S_and2_68_1);
  andn(&S_andn_72_1);
  setData(idTestDiagnAKNP1,&var10);
  setData(idR0DE3DLS1,&var7);
  setData(idR0DE3CLS1,&var8);
  setData(idTTLaknp1,&var13);
  setData(idA1VN71LS1,&var31);
  setData(idA1EE01LS1,&lEM_EE01LS1);
  setData(idR0VN75LZ2,&var15);
  setData(idR0VN71LZ2,&var26);
  setData(idR0IE02LS1,&var23);
  setData(idR0IE01LS1,&var23);
  setData(idR0VN15RS1,&var22);
  setData(idR0VN33RS1,&var21);
  setData(idR0VN23RS1,&var20);
  setData(idR0VN13RS1,&var19);
  setData(idA0EE02LS1,&var18);
  setData(idA0VN71LS1,&var31);
  setData(idR0VN04RS1,&var30);
  setData(idR0VN03RS1,&var16);
  setData(idA0EE01LS1,&lEM_EE01LS1);
  setData(idR0VN75LZ1,&var15);
  setData(idR0VN65LS1,&var14);
  setData(idR0VN71LZ1,&var26);
  setData(idR0VN61LS1,&var27);
  setData(idR0VN01RS1,&var24);
  setData(idR0VN02RS1,&var17);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
  for( i=0;i<5;i++ )
    array_m55_tst_1[i] = &(&internal1_m55_tst)[i];
  for( i=0;i<5;i++ )
    array_m55_trz_1[i] = &(&internal1_m55_trz)[i];
  for( i=0;i<5;i++ )
    array_m55_N1_1[i] = &(&internal1_m55_N1)[i];
  for( i=0;i<5;i++ )
    array_m55_N2_1[i] = &(&internal1_m55_N2)[i];
}
