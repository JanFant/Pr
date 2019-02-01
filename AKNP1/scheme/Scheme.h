/* Определение внутренних параметров */
uspaint8 InternalBuf[112];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssint iRM_5_ = {5,0}; /* n - N-размерность массива x */ 
ssfloat fRM_2_0 = {2.0,0}; /* Kpr1 - коэфф. преобразования частота->нейтр/с СНМ-11 */ 
sschar bRM_2_ = {2,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 

uspaint8 SpaEEPROMBuf[130];

/* Определение переменных */
ssbool var1;
ssbool var2;
ssbool var3;
ssfloat var4;
ssfloat var5;
ssbool var6;
ssfloat var7;
ssfloat var8;
ssfloat var9;
ssint var10;
ssbool var11;
ssfloat var12;
ssbool var13;
ssbool var14;
ssbool var15;
ssbool var16;
ssbool var17;
ssfloat var18;
ssbool var19;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psfloat  array_m45_tst_1[5];
psfloat  array_m45_trz_1[5];
psfloat  array_m45_N1_1[5];
psfloat  array_m45_N2_1[5];

/* Объявление структур */
_S_and5  S_and5_62_1 = {&var6,&R0IE13LS1,&A0EE03LS1,&R0IE11LS1,&R0IE12LS1,&var1};
_S_and2  S_and2_58_1 = {&var16,&var13,&var2};
_S_and2  S_and2_57_1 = {&var17,&var16,&var3};
_S_ocham  S_ocham_13_1 = {&R0IN03FS1,&R0IN02FS1,&R0IN01FS1,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX01RSS,&fEM_B0UX01RSS,&fEM_A0UX02RSS,&fEM_B0UX02RSS,&fEM_A0UX03RSS,&fEM_B0UX03RSS,&fEM_R7UX01RSS,&fEM_R7UY01RSS,&fEM_R7UX02RSS,&fEM_R7UY02RSS,&fEM_R7UX03RSS,&fEM_R7UY03RSS,&bRM_2_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&var4,&var5,&var6,&var7,&var8,&var9,&var10,&internal1_m13_Nk};
_S_or2  S_or2_68_1 = {&R0EE01LZ1,&R0EE01LZ2,&var11};
_S_period  S_period_45_1 = {&var5,&var1,&iRM_5_,&fEM_R0UL01RSS,&fEM_R0UL02RSS,&fEM_R0UN03RSS,&var12,array_m45_tst_1,array_m45_trz_1,array_m45_N1_1,array_m45_N2_1,&internal1_m45_Period0,&internal1_m45_MyFirstEnterFlag};
_S_bol  S_bol_51_1 = {&fEM_R0UL41RSS,&var12,&var13};
_S_bol  S_bol_36_1 = {&var5,&fEM_R0UL52RSS,&var14};
_S_bol  S_bol_31_1 = {&var5,&fEM_R0UL42RSS,&var15};
_S_bol  S_bol_50_1 = {&var5,&fEM_R0UN03RSS,&var16};
_S_bol  S_bol_49_1 = {&fEM_R0UL51RSS,&var12,&var17};
_S_react  S_react_46_1 = {&var12,&var18};
_S_bol  S_bol_39_1 = {&var5,&fEM_R0UR01RSS,&var19};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_68_1);
  ocham(&S_ocham_13_1);
  and5(&S_and5_62_1);
  bol(&S_bol_39_1);
  bol(&S_bol_50_1);
  bol(&S_bol_31_1);
  bol(&S_bol_36_1);
  period(&S_period_45_1);
  react(&S_react_46_1);
  bol(&S_bol_49_1);
  bol(&S_bol_51_1);
  and2(&S_and2_57_1);
  and2(&S_and2_58_1);
  setData(idA1VN71LS1,&var19);
  setData(idA1EE01LS1,&var1);
  setData(idR0VN75LZ2,&var3);
  setData(idR0VN71LZ2,&var14);
  setData(idR0IE02LS1,&var11);
  setData(idR0IE01LS1,&var11);
  setData(idR0VN15RS1,&var10);
  setData(idR0VN33RS1,&var9);
  setData(idR0VN23RS1,&var8);
  setData(idR0VN13RS1,&var7);
  setData(idA0EE02LS1,&var6);
  setData(idA0VN71LS1,&var19);
  setData(idR0VN04RS1,&var18);
  setData(idR0VN03RS1,&var4);
  setData(idA0EE01LS1,&var1);
  setData(idR0VN75LZ1,&var3);
  setData(idR0VN65LS1,&var2);
  setData(idR0VN71LZ1,&var14);
  setData(idR0VN61LS1,&var15);
  setData(idR0VN01RS1,&var12);
  setData(idR0VN02RS1,&var5);

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
