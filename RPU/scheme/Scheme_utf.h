/* Определение внутренних параметров */
uspaint8 InternalBuf[37];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssbool lRM_0_ = {0,0}; /* A-Граница участка насыщения А */ 
ssbool lRM_1_ = {1,0}; /* B-Граница участка насыщения В */ 
sslong dRM_0_ = {0,0}; /* lx вход лонг */ 
sschar bRM_0_ = {0,0}; /* cx вход байтовый */ 
ssint iRM_0_ = {0,0}; /* ix вход целый */ 
ssint iRM_819_ = {819,0}; /* a */ 
ssint iRM_4095_ = {4095,0}; /* b */ 
sschar bRM_1_ = {1,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssfloat fRM_2_0 = {2.0,0}; /* Kpr1 - коэфф. преобразования частота->нейтр/с СНМ-11 */ 

uspaint8 SpaEEPROMBuf[135];

/* Определение переменных */
ssfloat var1;
ssfloat var2;
ssbool var3;
ssfloat var4;
ssfloat var5;
ssfloat var6;
ssint var7;
ssbool var8;
ssbool var9;
ssbool var10;
ssbool var11;
ssbool var12;
ssbool var13;
ssbool var14;
ssbool var15;
ssbool var16;
ssbool var17;
ssbool var18;
ssbool var19;
sschar var20;
ssbool var21;
sschar var22;
ssbool var23;
ssbool var24;
ssbool var25;
ssbool var26;
ssbool var27;
ssbool var28;
ssfloat var29;
ssfloat var30;
sschar var31;
ssbool var32;
ssbool var33;
sschar var34;
ssbool var35;
ssbool var36;
ssbool var37;
ssbool var38;
ssbool var39;
ssbool var40;
ssbool var41;
ssbool var42;
ssbool var43;
ssbool var44;
ssbool var45;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */

/* Объявление структур */
_S_ocham  S_ocham_16_1 = {&R0IN01RRP,&R0IN02RRP,&R0IN03RRP,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX13RSS,&fEM_B0UX03RSS,&fEM_A0UX14RSS,&fEM_B0UX04RSS,&fEM_A0UX15RSS,&fEM_B0UX05RSS,&fEM_R7UX13RSS,&fEM_R7UY13RSS,&fEM_R7UX14RSS,&fEM_R7UY14RSS,&fEM_R7UX15RSS,&fEM_R7UY15RSS,&bRM_1_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&var1,&var2,&var3,&var4,&var5,&var6,&var7,&internal1_m16_Nk};
_S_or2  S_or2_57_1 = {&A6IS11LRP,&B6IS11LRP,&vainSBool};
_S_or5  S_or5_62_1 = {&var18,&var19,&A0EE03LRP,&var9,&var37,&var8};
_S_or2  S_or2_86_1 = {&var44,&var45,&var9};
_S_or4  S_or4_42_1 = {&var17,&var14,&var16,&var12,&var10};
_S_or2  S_or2_91_1 = {&var43,&var32,&var11};
_S_or2  S_or2_107_1 = {&var13,&var11,&var12};
_S_or2  S_or2_87_1 = {&var42,&var35,&var13};
_S_and3  S_and3_37_1 = {&var15,&var28,&var21,&var14};
_S_and4  S_and4_36_1 = {&R0IE11LRP,&var3,&R0IE12LRP,&R0IE13LRP,&var15};
_S_and3  S_and3_45_1 = {&var25,&R0IE14LRP,&var38,&var16};
_S_and3  S_and3_44_1 = {&R0IE15LRP,&var25,&var39,&var17};
_S_and3  S_and3_52_1 = {&R0IE14LRP,&var25,&var41,&var18};
_S_and3  S_and3_51_1 = {&var40,&R0IE15LRP,&var25,&var19};
_S_geterr  S_geterr_48_1 = {&R0IN06RRP,&dRM_0_,&iRM_0_,&bRM_0_,&var20,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_noto  S_noto_72_1 = {&var26,&var21};
_S_geterr  S_geterr_47_1 = {&R0IN07RRP,&dRM_0_,&iRM_0_,&bRM_0_,&var22,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_zzfs  S_zzfs_61_1 = {&var24,&fEM_Z7UE20RRP,&var23,&internal1_m61_tx,&internal1_m61_y0};
_S_or3  S_or3_60_1 = {&A6IS11LRP,&B6IS11LRP,&var27,&var24};
_S_noto  S_noto_58_1 = {&var23,&var25};
_S_zzfs  S_zzfs_71_1 = {&var27,&fEM_Z7UE20RRP,&var26,&internal1_m71_tx,&internal1_m71_y0};
_S_or2  S_or2_70_1 = {&R0EE05LZ1,&R0EE05LZ2,&var27};
_S_bol  S_bol_35_1 = {&var2,&fEM_R0UL52RSS,&var28};
_S_scalzz  S_scalzz_80_1 = {&B0IT03IRP,&iRM_819_,&iRM_4095_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var29,&internal1_m80_y0};
_S_scalzz  S_scalzz_78_1 = {&A0IT03IRP,&iRM_819_,&iRM_4095_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var30,&internal1_m78_y0};
_S_geterr  S_geterr_82_1 = {&var30,&dRM_0_,&iRM_0_,&bRM_0_,&var31,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_92_1 = {&var29,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var32,&internal1_m92_y1};
_S_drg  S_drg_103_1 = {&var29,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var33,&internal1_m103_y1};
_S_geterr  S_geterr_84_1 = {&var29,&dRM_0_,&iRM_0_,&bRM_0_,&var34,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_90_1 = {&var30,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var35,&internal1_m90_y1};
_S_drg  S_drg_101_1 = {&var30,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var36,&internal1_m101_y1};
_S_noto  S_noto_67_1 = {&var15,&var37};
_S_bol  S_bol_53_1 = {&R0IN07RRP,&fEM_R0UR01RRP,&var38};
_S_bol  S_bol_43_1 = {&R0IN06RRP,&fEM_R0UR01RRP,&var39};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  scalzz(&S_scalzz_78_1);
  scalzz(&S_scalzz_80_1);
  geterr(&S_geterr_47_1);
  geterr(&S_geterr_48_1);
  or2(&S_or2_57_1);
  ocham(&S_ocham_16_1);
  bol(&S_bol_43_1);
  bol(&S_bol_53_1);
  drg(&S_drg_101_1);
  drg(&S_drg_90_1);
  geterr(&S_geterr_84_1);
  drg(&S_drg_103_1);
  drg(&S_drg_92_1);
  geterr(&S_geterr_82_1);
  bol(&S_bol_35_1);
  or2(&S_or2_70_1);
  zzfs(&S_zzfs_71_1);
  or3(&S_or3_60_1);
  zzfs(&S_zzfs_61_1);
  noto(&S_noto_72_1);
  and4(&S_and4_36_1);
  and3(&S_and3_37_1);
  setData(&var42,&var31);
  or2(&S_or2_87_1);
  setData(&var43,&var34);
  or2(&S_or2_91_1);
  setData(&var44,&var31);
  setData(&var45,&var34);
  or2(&S_or2_86_1);
  noto(&S_noto_67_1);
  noto(&S_noto_58_1);
  setData(&var40,&var22);
  and3(&S_and3_51_1);
  setData(&var41,&var20);
  and3(&S_and3_52_1);
  and3(&S_and3_44_1);
  and3(&S_and3_45_1);
  or2(&S_or2_107_1);
  or4(&S_or4_42_1);
  or5(&S_or5_62_1);
  moveData(idB7MZ31LRP,idC1MZ31LRP);
  moveData(idA7MZ31LRP,idC1MZ31LRP);
  moveData(idB3VS21LRP,idB3IS21LRP);
  moveData(idA3VS21LRP,idA3IS21LRP);
  moveData(idB2VS21LRP,idB2IS21LRP);
  moveData(idA2VS21LRP,idA2IS21LRP);
  moveData(idB1VS21LRP,idB1IS21LRP);
  moveData(idA1VS21LRP,idA1IS21LRP);
  setData(idR7VE70LRP,&var8);
  setData(idR0VN13RRP,&var4);
  setData(idR0VN71LRP,&var28);
  setData(idA1VT71LRP,&var12);
  setData(idR0IE04LRP,&var23);
  setData(idR0IE03LRP,&var23);
  setData(idA0EE01LRP,&var15);
  setData(idB0VT71LRP,&var11);
  setData(idB0VT61LRP,&var33);
  setData(idB0CT01IRP,&var29);
  setData(idR0ET02LRP,&var34);
  setData(idR0ET01LRP,&var31);
  setData(idA0VT71LRP,&var13);
  setData(idA0VT61LRP,&var36);
  setData(idA0CT01IRP,&var30);
  setData(idR7VN71LRP,&var10);
  setData(idR0IE02LRP,&var26);
  setData(idR0IE01LRP,&var26);
  setData(idR0VN15RRP,&var7);
  setData(idR0VN33RRP,&var6);
  setData(idR0VN23RRP,&var5);
  setData(idA0EE02LRP,&var3);
  setData(idR0VN03RRP,&var1);
  setData(idR0VN02RRP,&var2);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}
