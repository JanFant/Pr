/* Определение внутренних параметров */
uspaint8 InternalBuf[112];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssint iRM_5_ = {5,0}; /* n - N-размерность массива x */ 
ssfloat fRM_2_0 = {2.0,0}; /* Kpr1 - коэфф. преобразования частота->нейтр/с СНМ-11 */ 
sschar bRM_2_ = {2,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssint iRM_4_ = {4,0}; /* n - размерность массива значений */ 

uspaint8 SpaEEPROMBuf[130];

/* Определение переменных */
ssbool var1;
ssbool var2;
ssbool var3;
ssbool var4;
ssbool var5;
ssbool var6;
ssint var7;
ssbool var8;
ssbool var9;
ssbool var10;
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
ssfloat var25;
ssbool var26;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m90_x_1[5] = {&var2,&var1,&R0DE37LS1,&R0DE38LS1,&R0DE39LS1};
psint  array_m80_x_1[4] = {&R0DE01LS1,&R0DE02LS1,&R0DE04LS1,&R0DE05LS1};
psfloat  array_m45_tst_1[5];
psfloat  array_m45_trz_1[5];
psfloat  array_m45_N1_1[5];
psfloat  array_m45_N2_1[5];

/* Объявление структур */
_S_or2  S_or2_94_1 = {&R0DEB3LS1,&R0DEB4LS1,&var1};
_S_or2  S_or2_88_1 = {&R0DEB1LS1,&R0DEB2LS1,&var2};
_S_orn  S_orn_90_1 = {array_m90_x_1,&iRM_5_,&var3};
_S_or3  S_or3_93_1 = {&var6,&var5,&var3,&var4};
_S_and2  S_and2_82_1 = {&R0DE31LS1,&R0DE32LS1,&var5};
_S_diagndev  S_diagndev_80_1 = {array_m80_x_1,&iRM_4_,&var6,&var7};
_S_and5  S_and5_62_1 = {&var13,&R0IE13LS1,&A0EE03LS1,&R0IE11LS1,&R0IE12LS1,&var8};
_S_and2  S_and2_58_1 = {&var23,&var20,&var9};
_S_and2  S_and2_57_1 = {&var24,&var23,&var10};
_S_ocham  S_ocham_15_1 = {&R0IN03FS1,&R0IN02FS1,&R0IN01FS1,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX01RSS,&fEM_B0UX01RSS,&fEM_A0UX02RSS,&fEM_B0UX02RSS,&fEM_A0UX03RSS,&fEM_B0UX03RSS,&fEM_R7UX01RSS,&fEM_R7UY01RSS,&fEM_R7UX02RSS,&fEM_R7UY02RSS,&fEM_R7UX03RSS,&fEM_R7UY03RSS,&bRM_2_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&var11,&var12,&var13,&var14,&var15,&var16,&var17,&internal1_m15_Nk};
_S_or2  S_or2_68_1 = {&R0EE01LZ1,&R0EE01LZ2,&var18};
_S_period  S_period_45_1 = {&var12,&var8,&iRM_5_,&fEM_R0UL01RSS,&fEM_R0UL02RSS,&fEM_R0UN03RSS,&var19,array_m45_tst_1,array_m45_trz_1,array_m45_N1_1,array_m45_N2_1,&internal1_m45_Period0,&internal1_m45_MyFirstEnterFlag};
_S_bol  S_bol_51_1 = {&fEM_R0UL41RSS,&var19,&var20};
_S_bol  S_bol_36_1 = {&var12,&fEM_R0UL52RSS,&var21};
_S_bol  S_bol_31_1 = {&var12,&fEM_R0UL42RSS,&var22};
_S_bol  S_bol_50_1 = {&var12,&fEM_R0UN03RSS,&var23};
_S_bol  S_bol_49_1 = {&fEM_R0UL51RSS,&var19,&var24};
_S_react  S_react_46_1 = {&var19,&var25};
_S_bol  S_bol_39_1 = {&var12,&fEM_R0UR01RSS,&var26};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_68_1);
  ocham(&S_ocham_15_1);
  and5(&S_and5_62_1);
  diagndev(&S_diagndev_80_1);
  and2(&S_and2_82_1);
  or2(&S_or2_88_1);
  or2(&S_or2_94_1);
  bol(&S_bol_39_1);
  bol(&S_bol_50_1);
  bol(&S_bol_31_1);
  bol(&S_bol_36_1);
  period(&S_period_45_1);
  orn(&S_orn_90_1);
  react(&S_react_46_1);
  bol(&S_bol_49_1);
  bol(&S_bol_51_1);
  and2(&S_and2_57_1);
  and2(&S_and2_58_1);
  or3(&S_or3_93_1);
  setData(idTestDiagnAKNP1,&var4);
  setData(idR0DE3DLS1,&var1);
  setData(idR0DE3CLS1,&var2);
  setData(idTTLaknp1,&var7);
  setData(idA1VN71LS1,&var26);
  setData(idA1EE01LS1,&var8);
  setData(idR0VN75LZ2,&var10);
  setData(idR0VN71LZ2,&var21);
  setData(idR0IE02LS1,&var18);
  setData(idR0IE01LS1,&var18);
  setData(idR0VN15RS1,&var17);
  setData(idR0VN33RS1,&var16);
  setData(idR0VN23RS1,&var15);
  setData(idR0VN13RS1,&var14);
  setData(idA0EE02LS1,&var13);
  setData(idA0VN71LS1,&var26);
  setData(idR0VN04RS1,&var25);
  setData(idR0VN03RS1,&var11);
  setData(idA0EE01LS1,&var8);
  setData(idR0VN75LZ1,&var10);
  setData(idR0VN65LS1,&var9);
  setData(idR0VN71LZ1,&var21);
  setData(idR0VN61LS1,&var22);
  setData(idR0VN01RS1,&var19);
  setData(idR0VN02RS1,&var12);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
  for( i=0;i<5;i++ )
    array_m45_tst_1[i] = &(&internal1_m45_tst)[i];
  for( i=0;i<5;i++ )
    array_m45_trz_1[i] = &(&internal1_m45_trz)[i];
  for( i=0;i<5;i++ )
    array_m45_N1_1[i] = &(&internal1_m45_N1)[i];
  for( i=0;i<5;i++ )
    array_m45_N2_1[i] = &(&internal1_m45_N2)[i];
}
