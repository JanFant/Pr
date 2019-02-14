/* Определение внутренних параметров */
uspaint8 InternalBuf[112];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssint iRM_5_ = {5,0}; /* n - N-размерность массива x */ 
ssfloat fRM_2_0 = {2.0,0}; /* Kpr1 - коэфф. преобразования частота->нейтр/с СНМ-11 */ 
sschar bRM_2_ = {2,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssint iRM_4_ = {4,0}; /* n - размерность массива значений */ 
ssint iRM_8_ = {8,0}; /*  */ 

uspaint8 SpaEEPROMBuf[130];

/* Определение переменных */
ssbool var1;
ssbool var2;
ssbool var3;
ssbool var4;
ssint var5;
ssbool var6;
ssbool var7;
ssbool var8;
ssfloat var9;
ssfloat var10;
ssbool var11;
ssfloat var12;
ssfloat var13;
ssfloat var14;
ssint var15;
ssbool var16;
ssfloat var17;
ssbool var18;
ssbool var19;
ssbool var20;
ssbool var21;
ssbool var22;
ssfloat var23;
ssbool var24;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m88_x_1[8] = {&R0DE3CLS1,&R0DE36LS1,&R0DE37LS1,&R0DE38LS1,&R0DE39LS1,&R0DE3ALS1,&R0DE3BLS1,&R0DE3DLS1};
psint  array_m78_x_1[4] = {&R0DE01LS1,&R0DE02LS1,&R0DE04LS1,&R0DE05LS1};
psfloat  array_m45_tst_1[5];
psfloat  array_m45_trz_1[5];
psfloat  array_m45_N1_1[5];
psfloat  array_m45_N2_1[5];

/* Объявление структур */
_S_orn  S_orn_88_1 = {array_m88_x_1,&iRM_8_,&var1};
_S_or3  S_or3_83_1 = {&var4,&var3,&var1,&var2};
_S_and2  S_and2_80_1 = {&R0DE31LS1,&R0DE32LS1,&var3};
_S_diagndev  S_diagndev_78_1 = {array_m78_x_1,&iRM_4_,&var4,&var5};
_S_and5  S_and5_61_1 = {&var11,&R0IE13LS1,&A0EE03LS1,&R0IE11LS1,&R0IE12LS1,&var6};
_S_and2  S_and2_58_1 = {&var21,&var18,&var7};
_S_and2  S_and2_57_1 = {&var22,&var21,&var8};
_S_ocham  S_ocham_13_1 = {&R0IN03FS1,&R0IN02FS1,&R0IN01FS1,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX01RSS,&fEM_B0UX01RSS,&fEM_A0UX02RSS,&fEM_B0UX02RSS,&fEM_A0UX03RSS,&fEM_B0UX03RSS,&fEM_R7UX01RSS,&fEM_R7UY01RSS,&fEM_R7UX02RSS,&fEM_R7UY02RSS,&fEM_R7UX03RSS,&fEM_R7UY03RSS,&bRM_2_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&var9,&var10,&var11,&var12,&var13,&var14,&var15,&internal1_m13_Nk};
_S_or2  S_or2_68_1 = {&R0EE01LZ1,&R0EE01LZ2,&var16};
_S_period  S_period_45_1 = {&var10,&var6,&iRM_5_,&fEM_R0UL01RSS,&fEM_R0UL02RSS,&fEM_R0UN03RSS,&var17,array_m45_tst_1,array_m45_trz_1,array_m45_N1_1,array_m45_N2_1,&internal1_m45_Period0,&internal1_m45_MyFirstEnterFlag};
_S_bol  S_bol_51_1 = {&fEM_R0UL41RSS,&var17,&var18};
_S_bol  S_bol_36_1 = {&var10,&fEM_R0UL52RSS,&var19};
_S_bol  S_bol_31_1 = {&var10,&fEM_R0UL42RSS,&var20};
_S_bol  S_bol_50_1 = {&var10,&fEM_R0UN03RSS,&var21};
_S_bol  S_bol_49_1 = {&fEM_R0UL51RSS,&var17,&var22};
_S_react  S_react_46_1 = {&var17,&var23};
_S_bol  S_bol_39_1 = {&var10,&fEM_R0UR01RSS,&var24};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_68_1);
  ocham(&S_ocham_13_1);
  and5(&S_and5_61_1);
  diagndev(&S_diagndev_78_1);
  and2(&S_and2_80_1);
  orn(&S_orn_88_1);
  bol(&S_bol_39_1);
  bol(&S_bol_50_1);
  bol(&S_bol_31_1);
  bol(&S_bol_36_1);
  period(&S_period_45_1);
  or3(&S_or3_83_1);
  react(&S_react_46_1);
  bol(&S_bol_49_1);
  bol(&S_bol_51_1);
  and2(&S_and2_57_1);
  and2(&S_and2_58_1);
  setData(idTestDiagnAKNP1,&var2);
  setData(idTTLaknp1,&var5);
  setData(idA1VN71LS1,&var24);
  setData(idA1EE01LS1,&var6);
  setData(idR0VN75LZ2,&var8);
  setData(idR0VN71LZ2,&var19);
  setData(idR0IE02LS1,&var16);
  setData(idR0IE01LS1,&var16);
  setData(idR0VN15RS1,&var15);
  setData(idR0VN33RS1,&var14);
  setData(idR0VN23RS1,&var13);
  setData(idR0VN13RS1,&var12);
  setData(idA0EE02LS1,&var11);
  setData(idA0VN71LS1,&var24);
  setData(idR0VN04RS1,&var23);
  setData(idR0VN03RS1,&var9);
  setData(idA0EE01LS1,&var6);
  setData(idR0VN75LZ1,&var8);
  setData(idR0VN65LS1,&var7);
  setData(idR0VN71LZ1,&var19);
  setData(idR0VN61LS1,&var20);
  setData(idR0VN01RS1,&var17);
  setData(idR0VN02RS1,&var10);

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
