/* Определение внутренних параметров */
uspaint8 InternalBuf[47];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssbool lRM_0_ = {0,0}; /* A-Граница участка насыщения А */ 
ssbool lRM_1_ = {1,0}; /* B-Граница участка насыщения В */ 
sslong dRM_0_ = {0,0}; /* lx вход лонг */ 
sschar bRM_0_ = {0,0}; /* cx вход байтовый */ 
ssint iRM_0_ = {0,0}; /* ix вход целый */ 
ssint iRM_3200_ = {3200,0}; /* a */ 
ssint iRM_16000_ = {16000,0}; /* b */ 
sschar bRM_1_ = {1,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssfloat fRM_2_0 = {2.0,0}; /* Kpr1 - коэфф. преобразования частота->нейтр/с СНМ-11 */ 
ssint iRM_6_ = {6,0}; /* n - размерность массива значений */ 
ssfloat fRM_0_ = {0,0}; /*  */ 
ssfloat fRM_0_6 = {0.6,0}; /*  */ 
ssfloat fRM_1_2 = {1.2,0}; /* d */ 

uspaint8 SpaEEPROMBuf[200];

/* Определение переменных */
ssfloat var1;
ssfloat var2;
ssfloat var3;
ssfloat var4;
ssfloat var5;
ssfloat var6;
ssfloat var7;
ssfloat var8;
ssfloat var9;
ssfloat var10;
ssfloat var11;
ssfloat var12;
ssbool var13;
ssbool var14;
ssbool var15;
ssbool var16;
ssbool var17;
ssbool var18;
ssbool var19;
ssbool var20;
ssbool var21;
ssint var22;
ssfloat var23;
ssfloat var24;
ssbool var25;
ssfloat var26;
ssfloat var27;
ssfloat var28;
ssint var29;
ssbool var30;
ssbool var31;
ssbool var32;
ssbool var33;
ssbool var34;
ssbool var35;
ssbool var36;
ssbool var37;
ssbool var38;
ssbool var39;
sschar var40;
ssbool var41;
sschar var42;
ssbool var43;
ssbool var44;
ssbool var45;
ssbool var46;
ssbool var47;
ssfloat var48;
ssfloat var49;
sschar var50;
ssbool var51;
ssbool var52;
sschar var53;
ssbool var54;
ssbool var55;
ssbool var56;
ssbool var57;
ssbool var58;
ssbool var59;
ssbool var60;
ssbool var61;
ssbool var62;
ssbool var63;
ssbool var64;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m156_x_1[6] = {&var16,&var17,&R0DE36LRP,&R0DE37LRP,&R0DE38LRP,&R0DE39LRP};
psint  array_m138_x_1[6] = {&R0DE01LRP,&R0DE02LRP,&R0DE03LRP,&R0DE08LRP,&R0DE06LRP,&R0DE07LRP};

/* Объявление структур */
_S_scalzz  S_scalzz_189_1 = {&VMETRP12,&iRM_3200_,&iRM_16000_,&fRM_0_,&fRM_1_2,&var1,&internal1_m189_y0};
_S_scalzz  S_scalzz_188_1 = {&VMETRP06,&iRM_3200_,&iRM_16000_,&fRM_0_,&fRM_0_6,&var2,&internal1_m188_y0};
_S_pogrvh  S_pogrvh_183_1 = {&R0IN07VRP,&fEM_R0IN71NRP,&fEM_R0IN72NRP,&var3};
_S_pogrvh  S_pogrvh_175_1 = {&R0IN06VRP,&fEM_R0IN61NRP,&fEM_R0IN62NRP,&var4};
_S_pogrvh  S_pogrvh_173_1 = {&R0IN03VRP,&fEM_R0IN31NRP,&fEM_R0IN32NRP,&var5};
_S_pogrvh  S_pogrvh_171_1 = {&R0IN02VRP,&fEM_R0IN21NRP,&fEM_R0IN22NRP,&var6};
_S_pogrvh  S_pogrvh_169_1 = {&R0IN01VRP,&fEM_R0IN11NRP,&fEM_R0IN12NRP,&var7};
_S_ml  S_ml_57_1 = {&R0IN07RIP,&var3,&R0IS01FI0,&var8};
_S_ml  S_ml_49_1 = {&R0IN06RIP,&var4,&R0IS01FI0,&var9};
_S_ml  S_ml_8_1 = {&R0IN03RIP,&var5,&R0IS01FI0,&var10};
_S_ml  S_ml_7_1 = {&R0IN02RIP,&var6,&R0IS01FI0,&var11};
_S_ml  S_ml_6_1 = {&R0IN01RIP,&var7,&R0IS01FI0,&var12};
_S_or4  S_or4_71_1 = {&var56,&var30,&var38,&var39,&var13};
_S_noto  S_noto_157_1 = {&var18,&var14};
_S_and5  S_and5_43_1 = {&var14,&R0IE11LRP,&R0IE12LRP,&R0IE13LRP,&var25,&var15};
_S_or2  S_or2_151_1 = {&R0DEB1LRP,&R0DEB2LRP,&var16};
_S_or2  S_or2_158_1 = {&R0DEB3LRP,&R0DEB4LRP,&var17};
_S_or3  S_or3_155_1 = {&var21,&var20,&var19,&var18};
_S_orn  S_orn_156_1 = {array_m156_x_1,&iRM_6_,&var19};
_S_and2  S_and2_140_1 = {&R0DE31LRP,&R0DE32LRP,&var20};
_S_diagndev  S_diagndev_138_1 = {array_m138_x_1,&iRM_6_,&var21,&var22,&vainSFloat};
_S_ocham  S_ocham_18_1 = {&var12,&var11,&var10,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX13RSS,&fEM_B0UX03RSS,&fEM_A0UX14RSS,&fEM_B0UX04RSS,&fEM_A0UX15RSS,&fEM_B0UX05RSS,&fEM_R7UX13RSS,&fEM_R7UY13RSS,&fEM_R7UX14RSS,&fEM_R7UY14RSS,&fEM_R7UX15RSS,&fEM_R7UY15RSS,&bRM_1_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&fEM_R0UH21RSS,&fEM_R0UH22RSS,&fEM_R0UH23RSS,&var23,&var24,&var25,&var26,&var27,&var28,&var29,&internal1_m18_Nk};
_S_or2  S_or2_66_1 = {&A6IS11LRP,&B6IS11LRP,&vainSBool};
_S_or2  S_or2_94_1 = {&var63,&var64,&var30};
_S_or4  S_or4_48_1 = {&var37,&var35,&var36,&var33,&var31};
_S_or2  S_or2_99_1 = {&var62,&var51,&var32};
_S_or2  S_or2_121_1 = {&var34,&var32,&var33};
_S_or2  S_or2_95_1 = {&var61,&var54,&var34};
_S_and3  S_and3_44_1 = {&var15,&var47,&var41,&var35};
_S_and3  S_and3_52_1 = {&var45,&R0IE14LRP,&var57,&var36};
_S_and3  S_and3_51_1 = {&R0IE15LRP,&var45,&var58,&var37};
_S_and3  S_and3_60_1 = {&R0IE14LRP,&var45,&var60,&var38};
_S_and3  S_and3_59_1 = {&var59,&R0IE15LRP,&var45,&var39};
_S_geterr  S_geterr_56_1 = {&var9,&dRM_0_,&iRM_0_,&bRM_0_,&var40,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_noto  S_noto_79_1 = {&var46,&var41};
_S_geterr  S_geterr_55_1 = {&var8,&dRM_0_,&iRM_0_,&bRM_0_,&var42,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_zzfs  S_zzfs_70_1 = {&var44,&fEM_Z7UE20RRP,&var43,&internal1_m70_tx,&internal1_m70_y0};
_S_or3  S_or3_69_1 = {&A6IS11LRP,&B6IS11LRP,&R0EE02LDU,&var44};
_S_noto  S_noto_67_1 = {&var43,&var45};
_S_zzfs  S_zzfs_78_1 = {&R0EE02LDU,&fEM_Z7UE20RRP,&var46,&internal1_m78_tx,&internal1_m78_y0};
_S_bol  S_bol_41_1 = {&var24,&fEM_R0UL52RSS,&var47};
_S_scalzz  S_scalzz_86_1 = {&B0IT03IRP,&iRM_3200_,&iRM_16000_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var48,&internal1_m86_y0};
_S_scalzz  S_scalzz_84_1 = {&A0IT03IRP,&iRM_3200_,&iRM_16000_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var49,&internal1_m84_y0};
_S_geterr  S_geterr_88_1 = {&var49,&dRM_0_,&iRM_0_,&bRM_0_,&var50,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_100_1 = {&var48,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var51,&internal1_m100_y1};
_S_drg  S_drg_115_1 = {&var48,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var52,&internal1_m115_y1};
_S_geterr  S_geterr_90_1 = {&var48,&dRM_0_,&iRM_0_,&bRM_0_,&var53,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_98_1 = {&var49,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var54,&internal1_m98_y1};
_S_drg  S_drg_113_1 = {&var49,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var55,&internal1_m113_y1};
_S_noto  S_noto_75_1 = {&var15,&var56};
_S_bol  S_bol_61_1 = {&var8,&fEM_R0UR01RRP,&var57};
_S_bol  S_bol_50_1 = {&var9,&fEM_R0UR01RRP,&var58};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  scalzz(&S_scalzz_84_1);
  scalzz(&S_scalzz_86_1);
  or2(&S_or2_66_1);
  diagndev(&S_diagndev_138_1);
  and2(&S_and2_140_1);
  or2(&S_or2_158_1);
  or2(&S_or2_151_1);
  scalzz(&S_scalzz_189_1);
  drg(&S_drg_113_1);
  drg(&S_drg_98_1);
  geterr(&S_geterr_90_1);
  drg(&S_drg_115_1);
  drg(&S_drg_100_1);
  geterr(&S_geterr_88_1);
  zzfs(&S_zzfs_78_1);
  or3(&S_or3_69_1);
  zzfs(&S_zzfs_70_1);
  noto(&S_noto_79_1);
  setData(&var61,&var50);
  or2(&S_or2_95_1);
  setData(&var62,&var53);
  or2(&S_or2_99_1);
  setData(&var63,&var50);
  setData(&var64,&var53);
  or2(&S_or2_94_1);
  orn(&S_orn_156_1);
  or3(&S_or3_155_1);
  noto(&S_noto_157_1);
  pogrvh(&S_pogrvh_169_1);
  pogrvh(&S_pogrvh_171_1);
  pogrvh(&S_pogrvh_173_1);
  pogrvh(&S_pogrvh_175_1);
  pogrvh(&S_pogrvh_183_1);
  scalzz(&S_scalzz_188_1);
  noto(&S_noto_67_1);
  or2(&S_or2_121_1);
  ml(&S_ml_6_1);
  ml(&S_ml_7_1);
  ml(&S_ml_8_1);
  ml(&S_ml_49_1);
  ml(&S_ml_57_1);
  bol(&S_bol_50_1);
  bol(&S_bol_61_1);
  geterr(&S_geterr_55_1);
  geterr(&S_geterr_56_1);
  setData(&var59,&var42);
  and3(&S_and3_59_1);
  setData(&var60,&var40);
  and3(&S_and3_60_1);
  and3(&S_and3_51_1);
  and3(&S_and3_52_1);
  ocham(&S_ocham_18_1);
  and5(&S_and5_43_1);
  noto(&S_noto_75_1);
  bol(&S_bol_41_1);
  and3(&S_and3_44_1);
  or4(&S_or4_48_1);
  or4(&S_or4_71_1);
  setData(idMETRP12,&var1);
  setData(idMETRP06,&var2);
  moveData(idB1VS21LRP,idB1IS21LRP);
  moveData(idA1VS21LRP,idA1IS21LRP);
  setData(idTTLrpu,&var22);
  setData(idTestDiagnRPU,&var18);
  setData(idR0DE3DLRP,&var17);
  setData(idR0DE3CLRP,&var16);
  moveData(idB7MZ31LRP,idC1MZ31LRP);
  moveData(idA7MZ31LRP,idC1MZ31LRP);
  moveData(idB3VS21LRP,idB3IS21LRP);
  moveData(idA3VS21LRP,idA3IS21LRP);
  moveData(idB2VS21LRP,idB2IS21LRP);
  moveData(idA2VS21LRP,idA2IS21LRP);
  setData(idR7VE70LRP,&var13);
  setData(idR0VN13RRP,&var26);
  setData(idR0VN71LRP,&var47);
  setData(idA1VT71LRP,&var33);
  setData(idR0IE04LRP,&var43);
  setData(idR0IE03LRP,&var43);
  setData(idA0EE01LRP,&var15);
  setData(idB0VT71LRP,&var32);
  setData(idB0VT61LRP,&var52);
  setData(idB0CT01IRP,&var48);
  setData(idR0ET02LRP,&var53);
  setData(idR0ET01LRP,&var50);
  setData(idA0VT71LRP,&var34);
  setData(idA0VT61LRP,&var55);
  setData(idA0CT01IRP,&var49);
  setData(idR0IN07RRP,&var3);
  setData(idR7VN71LRP,&var31);
  setData(idR0IN06RRP,&var4);
  setData(idR0IE02LRP,&var46);
  setData(idR0IE01LRP,&var46);
  setData(idR0VN15RRP,&var29);
  setData(idR0VN33RRP,&var28);
  setData(idR0VN23RRP,&var27);
  setData(idA0EE02LRP,&var25);
  setData(idR0IN03RRP,&var5);
  setData(idR0VN03RRP,&var23);
  setData(idR0IN02RRP,&var6);
  setData(idR0IN01RRP,&var7);
  setData(idR0VN02RRP,&var24);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}
