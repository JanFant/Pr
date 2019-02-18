/* Определение внутренних параметров */
uspaint8 InternalBuf[112];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssint iRM_5_ = {5,0}; /* n - N-размерность массива входных параметров */ 
ssint iRM_2_ = {2,0}; /* n - N-размерность массива входных параметров */ 
sschar bRM_1_ = {1,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssfloat fRM_2_0 = {2.0,0}; /* Kpr1 - коэфф. преобразования частота->нейтр/с СНМ-11 */ 
ssint iRM_4_ = {4,0}; /* n - размерность массива значений */ 
ssint iRM_6_ = {6,0}; /* n - N-размерность массива x */ 

uspaint8 SpaEEPROMBuf[128];

/* Определение переменных */
ssbool var1;
ssbool var2;
ssbool var3;
ssbool var4;
ssbool var5;
ssbool var6;
ssint var7;
ssfloat var8;
ssfloat var9;
ssbool var10;
ssfloat var11;
ssfloat var12;
ssfloat var13;
ssint var14;
ssbool var15;
ssfloat var16;
ssbool var17;
ssbool var18;
ssbool var19;
ssbool var20;
ssbool var21;
ssbool var22;
ssbool var23;
ssbool var24;
ssfloat var25;
ssbool var26;
ssfloat var27;
ssfloat var28;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m94_x_1[6] = {&var2,&var1,&R0DE36LS3,&R0DE37LS3,&R0DE38LS3,&R0DE39LS3};
psint  array_m80_x_1[4] = {&R0DE01LS3,&R0DE02LS3,&R0DE04LS3,&R0DE05LS3};
psfloat  array_m45_tst_1[5];
psfloat  array_m45_trz_1[5];
psfloat  array_m45_N1_1[5];
psfloat  array_m45_N2_1[5];
psbool  array_m55_x_1[2] = {&var23,&var18};
psbool  array_m54_x_1[2] = {&var23,&var24};
psbool  array_m63_x_1[5] = {&var10,&R0IE11LS3,&R0IE12LS3,&R0IE13LS3,&A0EE03LS3};

/* Объявление структур */
_S_or2  S_or2_96_1 = {&R0DEB3LS3,&R0DEB4LS3,&var1};
_S_or2  S_or2_89_1 = {&R0DEB1LS3,&R0DEB2LS3,&var2};
_S_or3  S_or3_91_1 = {&var6,&var5,&var4,&var3};
_S_orn  S_orn_94_1 = {array_m94_x_1,&iRM_6_,&var4};
_S_and2  S_and2_82_1 = {&R0DE31LS3,&R0DE32LS3,&var5};
_S_diagndev  S_diagndev_80_1 = {array_m80_x_1,&iRM_4_,&var6,&var7};
_S_ocham  S_ocham_17_1 = {&R0IN01FS3,&R0IN02FS3,&R0IN03FS3,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX07RSS,&fEM_B0UX07RSS,&fEM_A0UX08RSS,&fEM_B0UX08RSS,&fEM_A0UX09RSS,&fEM_B0UX09RSS,&fEM_R7UX07RSS,&fEM_R7UY07RSS,&fEM_R7UX08RSS,&fEM_R7UY08RSS,&fEM_R7UX09RSS,&fEM_R7UY09RSS,&bRM_1_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&var8,&var9,&var10,&var11,&var12,&var13,&var14,&internal1_m17_Nk};
_S_or2  S_or2_67_1 = {&R0EE03LZ1,&R0EE03LZ2,&var15};
_S_period  S_period_45_1 = {&var9,&var20,&iRM_5_,&var27,&var28,&fEM_R0UN03RSS,&var16,array_m45_tst_1,array_m45_trz_1,array_m45_N1_1,array_m45_N2_1,&internal1_m45_Period0,&internal1_m45_MyFirstEnterFlag};
_S_andn  S_andn_55_1 = {array_m55_x_1,&iRM_2_,&var17};
_S_bol  S_bol_52_1 = {&fEM_R0UL41RSS,&var16,&var18};
_S_andn  S_andn_54_1 = {array_m54_x_1,&iRM_2_,&var19};
_S_andn  S_andn_63_1 = {array_m63_x_1,&iRM_5_,&var20};
_S_bol  S_bol_35_1 = {&var9,&fEM_R0UL52RSS,&var21};
_S_bol  S_bol_40_1 = {&var9,&fEM_R0UL42RSS,&var22};
_S_bol  S_bol_51_1 = {&var9,&fEM_R0UN03RSS,&var23};
_S_bol  S_bol_50_1 = {&fEM_R0UL51RSS,&var16,&var24};
_S_react  S_react_46_1 = {&var16,&var25};
_S_bol  S_bol_31_1 = {&var9,&fEM_R0UR01RSS,&var26};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_67_1);
  diagndev(&S_diagndev_80_1);
  and2(&S_and2_82_1);
  or2(&S_or2_89_1);
  or2(&S_or2_96_1);
  ocham(&S_ocham_17_1);
  orn(&S_orn_94_1);
  or3(&S_or3_91_1);
  bol(&S_bol_31_1);
  bol(&S_bol_51_1);
  bol(&S_bol_40_1);
  bol(&S_bol_35_1);
  andn(&S_andn_63_1);
  setData(&var27,&iEM_R0UL01ISS);
  setData(&var28,&dEM_R0UL02USS);
  period(&S_period_45_1);
  react(&S_react_46_1);
  bol(&S_bol_50_1);
  andn(&S_andn_54_1);
  bol(&S_bol_52_1);
  andn(&S_andn_55_1);
  setData(idTestDiagnAKNP3,&var3);
  setData(idTTLaknp3,&var7);
  setData(idR0DE3DLS3,&var1);
  setData(idR0DE3CLS3,&var2);
  setData(idA1EE01LS3,&var20);
  setData(idR0VN77LZ2,&var19);
  setData(idR0VN73LZ2,&var21);
  setData(idA0VN71LS3,&var26);
  setData(idR0IE02LS3,&var15);
  setData(idR0IE01LS3,&var15);
  setData(idR0VN15RS3,&var14);
  setData(idR0VN33RS3,&var13);
  setData(idR0VN23RS3,&var12);
  setData(idR0VN13RS3,&var11);
  setData(idA0EE02LS3,&var10);
  setData(idA1VN71LS3,&var26);
  setData(idR0VN04RS3,&var25);
  setData(idR0VN03RS3,&var8);
  setData(idA0EE01LS3,&var20);
  setData(idR0VN77LZ1,&var19);
  setData(idR0VN65LS3,&var17);
  setData(idR0VN73LZ1,&var21);
  setData(idR0VN61LS3,&var22);
  setData(idR0VN01RS3,&var16);
  setData(idR0VN02RS3,&var9);

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
