/* ����������� ���������� ���������� */
uspaint8 InternalBuf[129];

/* ����������� �������� ��� � ������*/
ssbool lRM_0_ = {0,0}; /* A-������� ������� ��������� � */ 
ssbool lRM_1_ = {1,0}; /* B-������� ������� ��������� � */ 
sslong dRM_0_ = {0,0}; /* lx ���� ���� */ 
sschar bRM_0_ = {0,0}; /* cx ���� �������� */ 
ssint iRM_0_ = {0,0}; /* ix ���� ����� */ 
ssint iRM_3_ = {3,0}; /* N-����� ������ */ 
ssint iRM_4_ = {4,0}; /* n - ����������� ������� */ 
ssint iRM_6_ = {6,0}; /* N-����� ������ */ 
ssint iRM_16_ = {16,0}; /* n - ����������� ������� ������� �������� */ 
ssint iRM_3276_ = {3276,0}; /* a */ 
ssint iRM_16000_ = {16000,0}; /* b */ 
ssfloat fRM_0_00001 = {0.00001,0}; /* X2 */ 
ssint iRM_200_ = {200,0}; /* tz - ������ ��������, 10-�� �� */ 
ssint iRM_7_ = {7,0}; /* n - N-����������� ������� x */ 
ssfloat fRM_0_002 = {0.002,0}; /* x - ������ ������� ���������� */ 
ssfloat fRM_0_005 = {0.005,0}; /* x - ������ ������� ���������� */ 
ssfloat fRM_0_007 = {0.007,0}; /* x - ������ ������� ���������� */ 
ssfloat fRM_0_01 = {0.01,0}; /* x - ������ ������� ���������� */ 
ssfloat fRM_0_015 = {0.015,0}; /* x - ������ ������� ���������� */ 
ssfloat fRM_0_02 = {0.02,0}; /* x - ������ ������� ���������� */ 
ssfloat fRM_1_7 = {1.7,0}; /* x - ������ ������� ���������� */ 
ssfloat fRM_10000_ = {10000,0}; /* tz - ����� �������� ��� */ 
ssfloat fRM_0_3 = {0.3,0}; /* tz - ����� �������� ��� */ 

uspaint8 SpaEEPROMBuf[105];

/* ����������� ���������� */
ssbool var1;
ssbool var2;
ssbool var3;
ssbool var4;
ssbool var5;
ssbool var6;
ssbool var7;
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
ssbool var20;
ssbool var21;
ssbool var22;
ssint var23;
ssbool var24;
ssbool var25;
ssbool var26;
ssbool var27;
ssbool var28;
ssbool var29;
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
ssbool var40;
ssbool var41;
ssbool var42;
ssbool var43;
ssbool var44;
ssbool var45;
ssbool var46;
ssbool var47;
ssbool var48;
ssbool var49;
ssbool var50;
ssbool var51;
ssbool var52;
ssbool var53;
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
ssbool var65;
ssbool var66;
ssbool var67;
ssbool var68;
ssbool var69;
ssbool var70;
ssbool var71;
ssbool var72;
ssbool var73;
ssbool var74;
ssbool var75;
ssbool var76;
ssbool var77;
ssbool var78;
ssbool var79;
ssbool var80;
ssbool var81;
ssbool var82;
ssbool var83;
ssbool var84;
ssbool var85;
ssbool var86;
ssbool var87;
ssbool var88;
ssbool var89;
ssbool var90;
ssbool var91;
ssbool var92;
ssbool var93;
ssbool var94;
ssbool var95;
ssbool var96;
ssbool var97;
ssbool var98;
ssbool var99;
ssfloat var100;
ssfloat var101;
ssbool var102;
ssfloat var103;
ssfloat var104;
ssbool var105;
ssbool var106;
ssbool var107;
ssbool var108;
ssbool var109;
ssbool var110;
ssfloat var111;
sslong var112;
sslong var113;
ssbool var114;
ssbool var115;
ssbool var116;
ssbool var117;
ssbool var118;
ssbool var119;
ssbool var120;
ssbool var121;
ssbool var122;
ssfloat var123;
ssbool var124;
ssbool var125;
ssfloat var126;
ssbool var127;
ssbool var128;
sschar var129;
ssbool var130;
sschar var131;
ssbool var132;
ssbool var133;
ssbool var134;
ssbool var135;
ssbool var136;
ssbool var137;
ssbool var138;
ssbool var139;
ssbool var140;
ssbool var141;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* ���������� �������� */
psint  array_m308_x_1[6] = {&R0DE04LZ1,&R0DE05LZ1,&R0DE06LZ1,&R0DE0ALZ1,&R0DE08LZ1,&R0DE07LZ1};
psfloat  array_m189_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psfloat  array_m292_x_1[4] = {&R0VN02RS1,&R0VN02RS2,&R0VN02RS3,&R0VN02RS4};
psbool  array_m292_diag_1[4] = {&var28,&var29,&var30,&var31};
psbool  array_m283_x_1[16] = {&var76,&var42,&var43,&var71,&var11,&var8,&var128,&var41,&var40,&var39,&var72,&var12,&var9,&var130,&var37,&var34};
psbool  array_m16_x_1[6] = {&var81,&var72,&var12,&var9,&var87,&var130};
psbool  array_m36_x_1[6] = {&var71,&var11,&var8,&var128,&var79,&var87};
psfloat  array_m2_x_1[4] = {&R0VN01RS1,&R0VN01RS2,&R0VN01RS3,&R0VN01RS4};
psbool  array_m2_diag_1[4] = {&var28,&var29,&var30,&var31};
psbool  array_m3_x_1[3] = {&var90,&var110,&var26};
psbool  array_m12_x_1[3] = {&var89,&var27,&var91};

/* ���������� �������� */
_S_schl24  S_schl24_224_1 = {&R7II74LZ1,&R7II75LZ1,&R7II76LZ1,&lRM_0_,&var1};
_S_schl24  S_schl24_197_1 = {&R7II71LZ1,&R7II73LZ1,&R7II72LZ1,&lRM_0_,&var2};
_S_or2  S_or2_229_1 = {&var37,&var34,&var3};
_S_or2  S_or2_279_1 = {&R0MD34LP1,&var14,&var4};
_S_zzfs  S_zzfs_210_1 = {&R0AD04LZ1,&fRM_0_3,&var5,&internal1_m210_tx,&internal1_m210_y0};
_S_noto  S_noto_218_1 = {&var5,&var6};
_S_and2  S_and2_228_1 = {&var6,&var3,&var7};
_S_inicn  S_inicn_206_1 = {&A3IS11LDU,&B3IS11LDU,&R0AD03LZ1,&A3IS22LDU,&B3IS22LDU,&R0AD05LZ1,&var37,&var36,&var5,&fEM_R0UL25RDU,&fEM_R0UL05RDU,&fEM_R0UL07RDU,&var8,&var9,&var10,&var11,&var12,&var13,&var14,&internal1_m206_TVuIs1,&internal1_m206_TVuIs2,&internal1_m206_TImVuIs,&internal1_m206_TNupIs1,&internal1_m206_TNupIs2,&internal1_m206_TImNupIs,&internal1_m206_TImAZ2UR,&internal1_m206_fef};
_S_zzfs  S_zzfs_110_1 = {&B1VP81LZZ,&fRM_10000_,&var15,&internal1_m110_tx,&internal1_m110_y0};
_S_zzfs  S_zzfs_107_1 = {&A1VP81LZZ,&fRM_10000_,&var16,&internal1_m107_tx,&internal1_m107_y0};
_S_zzfs  S_zzfs_135_1 = {&B0VP81LZZ,&fRM_10000_,&var17,&internal1_m135_tx,&internal1_m135_y0};
_S_zzfs  S_zzfs_134_1 = {&A0VP81LZZ,&fRM_10000_,&var18,&internal1_m134_tx,&internal1_m134_y0};
_S_or3  S_or3_316_1 = {&var22,&var21,&var20,&var19};
_S_or2  S_or2_318_1 = {&R0DEB3LZ1,&R0DEB4LZ1,&var20};
_S_or2  S_or2_312_1 = {&R0DEB1LZ1,&R0DEB2LZ1,&var21};
_S_diagndev  S_diagndev_308_1 = {array_m308_x_1,&iRM_6_,&var22,&var23,&vainSFloat};
_S_ma  S_ma_189_1 = {array_m189_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_and2  S_and2_127_1 = {&var133,&var109,&var24};
_S_and2  S_and2_138_1 = {&var132,&var108,&var25};
_S_or2  S_or2_103_1 = {&var139,&var137,&var26};
_S_or2  S_or2_108_1 = {&var134,&var135,&var27};
_S_and2  S_and2_81_1 = {&lRM_1_,&A0EE01LS1,&var28};
_S_and2  S_and2_83_1 = {&lRM_1_,&A0EE01LS2,&var29};
_S_and2  S_and2_85_1 = {&lRM_1_,&A0EE01LS3,&var30};
_S_and2  S_and2_87_1 = {&lRM_1_,&A0EE01LS4,&var31};
_S_and2  S_and2_183_1 = {&var125,&var97,&var32};
_S_and2  S_and2_184_1 = {&var124,&var97,&var33};
_S_or2  S_or2_226_1 = {&var1,&var88,&var34};
_S_or2  S_or2_215_1 = {&R0AD21LDU,&var5,&var35};
_S_and2  S_and2_214_1 = {&var34,&var35,&var36};
_S_or2  S_or2_207_1 = {&var88,&var2,&var37};
_S_schl24  S_schl24_298_1 = {&A0VN71LS2,&A0VN71LS1,&A0VN71LS4,&A0VN71LS3,&var38};
_S_and2  S_and2_285_1 = {&var55,&var77,&var39};
_S_and2  S_and2_287_1 = {&var62,&var77,&var40};
_S_and2  S_and2_288_1 = {&var98,&var77,&var41};
_S_and2  S_and2_286_1 = {&var66,&var77,&var42};
_S_and2  S_and2_284_1 = {&var48,&var77,&var43};
_S_and2  S_and2_268_1 = {&var46,&var45,&var44};
_S_or2  S_or2_270_1 = {&R0VN75LZ1,&var122,&var45};
_S_or2  S_or2_271_1 = {&R0VN77LZ1,&var121,&var46};
_S_or2  S_or2_256_1 = {&var44,&var52,&var47};
_S_or2  S_or2_262_1 = {&var49,&var44,&var48};
_S_and2  S_and2_263_1 = {&var117,&var53,&var49};
_S_or2  S_or2_273_1 = {&R0VN78LZ1,&var119,&var50};
_S_or2  S_or2_272_1 = {&R0VN76LZ1,&var120,&var51};
_S_and2  S_and2_269_1 = {&var51,&var50,&var52};
_S_schl24  S_schl24_267_1 = {&var51,&var50,&var46,&var45,&var53};
_S_and2  S_and2_265_1 = {&var77,&var53,&var54};
_S_or2  S_or2_264_1 = {&var52,&var49,&var55};
_S_and2  S_and2_260_1 = {&var55,&var77,&var56};
_S_or2  S_or2_236_1 = {&R0VN72LZ1,&var120,&var57};
_S_and2  S_and2_251_1 = {&var66,&var77,&var58};
_S_and2  S_and2_239_1 = {&var57,&var60,&var59};
_S_or2  S_or2_237_1 = {&R0VN74LZ1,&var119,&var60};
_S_and2  S_and2_252_1 = {&var62,&var77,&var61};
_S_or2  S_or2_249_1 = {&var59,&var65,&var62};
_S_or2  S_or2_255_1 = {&var67,&var59,&var63};
_S_and2  S_and2_243_1 = {&var69,&var77,&var64};
_S_and2  S_and2_248_1 = {&var118,&var69,&var65};
_S_or2  S_or2_247_1 = {&var67,&var65,&var66};
_S_and2  S_and2_238_1 = {&var68,&var70,&var67};
_S_or2  S_or2_235_1 = {&R0VN73LZ1,&var121,&var68};
_S_schl24  S_schl24_241_1 = {&var68,&var70,&var57,&var60,&var69};
_S_or2  S_or2_234_1 = {&R0VN71LZ1,&var122,&var70};
_S_or2  S_or2_156_1 = {&var102,&var140,&var71};
_S_or2  S_or2_158_1 = {&var107,&var105,&var72};
_S_or2  S_or2_296_1 = {&var138,&var136,&var73};
_S_or2  S_or2_35_1 = {&B2IS12LDU,&A2IS12LDU,&var74};
_S_and2  S_and2_259_1 = {&var77,&var48,&var75};
_S_and2  S_and2_289_1 = {&var99,&var77,&var76};
_S_and2  S_and2_21_1 = {&var96,&var92,&var77};
_S_or2  S_or2_25_1 = {&var115,&var114,&var78};
_S_and2  S_and2_31_1 = {&var80,&var77,&var79};
_S_or3  S_or3_30_1 = {&var48,&var66,&var95,&var80};
_S_and2  S_and2_19_1 = {&var77,&var82,&var81};
_S_or3  S_or3_18_1 = {&var62,&var55,&var94,&var82};
_S_and2  S_and2_6_1 = {&var29,&var31,&var83};
_S_or2  S_or2_11_1 = {&var116,&var83,&var84};
_S_or2  S_or2_10_1 = {&var86,&var116,&var85};
_S_and2  S_and2_5_1 = {&var28,&var30,&var86};
_S_zpfs  S_zpfs_227_1 = {&var7,&fEM_R0UL07RDU,&var87,&internal1_m227_tx,&internal1_m227_y0};
_S_noto  S_noto_205_1 = {&R6IS66LZ1,&var88};
_S_noto  S_noto_137_1 = {&var17,&var89};
_S_noto  S_noto_136_1 = {&var18,&var90};
_S_noto  S_noto_112_1 = {&var15,&var91};
_S_noto  S_noto_27_1 = {&var93,&var92};
_S_ovb1  S_ovb1_33_1 = {&var74,&iRM_200_,&var93,&internal1_m33_tx};
_S_noto  S_noto_15_1 = {&var84,&var94};
_S_noto  S_noto_14_1 = {&var85,&var95};
_S_noto  S_noto_24_1 = {&R0EE02LDU,&var96};
_S_bol  S_bol_179_1 = {&var126,&fRM_0_00001,&var97};
_S_noto  S_noto_290_1 = {&var84,&var98};
_S_noto  S_noto_291_1 = {&var85,&var99};
_S_scalzz  S_scalzz_148_1 = {&B0IT01IZ1,&iRM_3276_,&iRM_16000_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var100,&internal1_m148_y0};
_S_scalzz  S_scalzz_146_1 = {&A0IT01IZ1,&iRM_3276_,&iRM_16000_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var101,&internal1_m146_y0};
_S_geterr  S_geterr_150_1 = {&var101,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var102};
_S_scalzz  S_scalzz_92_1 = {&B2IP01IZ1,&iRM_3276_,&iRM_16000_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var103,&internal1_m92_y0};
_S_scalzz  S_scalzz_90_1 = {&A2IP01IZ1,&iRM_3276_,&iRM_16000_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var104,&internal1_m90_y0};
_S_drg  S_drg_159_1 = {&var100,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var105,&internal1_m159_y1};
_S_drg  S_drg_170_1 = {&var100,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var106,&internal1_m170_y1};
_S_geterr  S_geterr_152_1 = {&var100,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var107};
_S_noto  S_noto_139_1 = {&var134,&var108};
_S_noto  S_noto_126_1 = {&var139,&var109};
_S_noto  S_noto_111_1 = {&var16,&var110};
_S_srm  S_srm_292_1 = {array_m292_x_1,array_m292_diag_1,&iRM_4_,&iRM_3_,&var111,&vainSBool};
_S_rsu  S_rsu_282_1 = {&var4,&var113,&var112,&internal1_m282_q0};
_S_orni  S_orni_283_1 = {array_m283_x_1,&iRM_16_,&vainSBool,&var113};
_S_orn  S_orn_16_1 = {array_m16_x_1,&iRM_6_,&var114};
_S_orn  S_orn_36_1 = {array_m36_x_1,&iRM_6_,&var115};
_S_noto  S_noto_7_1 = {&var127,&var116};
_S_noto  S_noto_258_1 = {&var47,&var117};
_S_noto  S_noto_253_1 = {&var63,&var118};
_S_noto  S_noto_242_1 = {&A0EE01LS4,&var119};
_S_noto  S_noto_246_1 = {&A0EE01LS2,&var120};
_S_noto  S_noto_245_1 = {&A0EE01LS3,&var121};
_S_noto  S_noto_240_1 = {&A0EE01LS1,&var122};
_S_react  S_react_175_1 = {&var126,&var123};
_S_bol  S_bol_180_1 = {&fEM_R0UR04RZZ,&var126,&var124};
_S_bol  S_bol_178_1 = {&fEM_R0UR01RZZ,&var126,&var125};
_S_srm  S_srm_2_1 = {array_m2_x_1,array_m2_diag_1,&iRM_4_,&iRM_3_,&var126,&var127};
_S_ornc  S_ornc_3_1 = {array_m3_x_1,&iRM_3_,&var128,&var129};
_S_ornc  S_ornc_12_1 = {array_m12_x_1,&iRM_3_,&var130,&var131};
_S_tprg  S_tprg_128_1 = {&var103,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var132,&internal1_m128_y0};
_S_tprg  S_tprg_124_1 = {&var104,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var133,&internal1_m124_y0};
_S_geterr  S_geterr_101_1 = {&var103,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var134};
_S_drg  S_drg_106_1 = {&var103,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var135,&internal1_m106_y1};
_S_drg  S_drg_121_1 = {&var103,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var136,&internal1_m121_y1};
_S_drg  S_drg_94_1 = {&var104,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var137,&internal1_m94_y1};
_S_drg  S_drg_104_1 = {&var104,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var138,&internal1_m104_y1};
_S_geterr  S_geterr_98_1 = {&var104,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var139};
_S_drg  S_drg_157_1 = {&var101,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var140,&internal1_m157_y1};
_S_drg  S_drg_167_1 = {&var101,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var141,&internal1_m167_y1};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  noto(&S_noto_240_1);
  noto(&S_noto_245_1);
  noto(&S_noto_246_1);
  noto(&S_noto_242_1);
  scalzz(&S_scalzz_90_1);
  scalzz(&S_scalzz_92_1);
  scalzz(&S_scalzz_146_1);
  scalzz(&S_scalzz_148_1);
  noto(&S_noto_24_1);
  noto(&S_noto_205_1);
  or2(&S_or2_234_1);
  or2(&S_or2_235_1);
  and2(&S_and2_238_1);
  or2(&S_or2_237_1);
  or2(&S_or2_236_1);
  or2(&S_or2_272_1);
  or2(&S_or2_273_1);
  or2(&S_or2_271_1);
  or2(&S_or2_270_1);
  and2(&S_and2_268_1);
  schl24(&S_schl24_298_1);
  ma(&S_ma_189_1);
  or2(&S_or2_312_1);
  or2(&S_or2_318_1);
  zzfs(&S_zzfs_134_1);
  zzfs(&S_zzfs_135_1);
  zzfs(&S_zzfs_107_1);
  zzfs(&S_zzfs_110_1);
  zzfs(&S_zzfs_210_1);
  schl24(&S_schl24_197_1);
  schl24(&S_schl24_224_1);
  drg(&S_drg_167_1);
  drg(&S_drg_157_1);
  geterr(&S_geterr_98_1);
  drg(&S_drg_104_1);
  drg(&S_drg_94_1);
  drg(&S_drg_121_1);
  drg(&S_drg_106_1);
  geterr(&S_geterr_101_1);
  tprg(&S_tprg_124_1);
  tprg(&S_tprg_128_1);
  noto(&S_noto_111_1);
  noto(&S_noto_126_1);
  noto(&S_noto_139_1);
  geterr(&S_geterr_152_1);
  drg(&S_drg_170_1);
  drg(&S_drg_159_1);
  geterr(&S_geterr_150_1);
  noto(&S_noto_112_1);
  noto(&S_noto_136_1);
  noto(&S_noto_137_1);
  or2(&S_or2_35_1);
  or2(&S_or2_296_1);
  or2(&S_or2_158_1);
  or2(&S_or2_156_1);
  schl24(&S_schl24_241_1);
  and2(&S_and2_239_1);
  schl24(&S_schl24_267_1);
  and2(&S_and2_269_1);
  or2(&S_or2_256_1);
  or2(&S_or2_207_1);
  or2(&S_or2_215_1);
  or2(&S_or2_226_1);
  and2(&S_and2_87_1);
  and2(&S_and2_85_1);
  and2(&S_and2_83_1);
  and2(&S_and2_81_1);
  or2(&S_or2_108_1);
  or2(&S_or2_103_1);
  and2(&S_and2_138_1);
  and2(&S_and2_127_1);
  diagndev(&S_diagndev_308_1);
  or3(&S_or3_316_1);
  noto(&S_noto_218_1);
  or2(&S_or2_229_1);
  ornc(&S_ornc_12_1);
  ornc(&S_ornc_3_1);
  srm(&S_srm_2_1);
  bol(&S_bol_178_1);
  bol(&S_bol_180_1);
  react(&S_react_175_1);
  noto(&S_noto_258_1);
  noto(&S_noto_7_1);
  srm(&S_srm_292_1);
  bol(&S_bol_179_1);
  ovb1(&S_ovb1_33_1);
  noto(&S_noto_27_1);
  and2(&S_and2_5_1);
  or2(&S_or2_10_1);
  and2(&S_and2_6_1);
  and2(&S_and2_21_1);
  and2(&S_and2_243_1);
  or2(&S_or2_255_1);
  and2(&S_and2_265_1);
  and2(&S_and2_263_1);
  or2(&S_or2_262_1);
  and2(&S_and2_284_1);
  and2(&S_and2_214_1);
  and2(&S_and2_184_1);
  and2(&S_and2_183_1);
  inicn(&S_inicn_206_1);
  and2(&S_and2_228_1);
  or2(&S_or2_279_1);
  noto(&S_noto_253_1);
  noto(&S_noto_291_1);
  noto(&S_noto_14_1);
  zpfs(&S_zpfs_227_1);
  or2(&S_or2_11_1);
  and2(&S_and2_289_1);
  and2(&S_and2_259_1);
  and2(&S_and2_248_1);
  or2(&S_or2_249_1);
  and2(&S_and2_252_1);
  or2(&S_or2_264_1);
  and2(&S_and2_287_1);
  and2(&S_and2_285_1);
  noto(&S_noto_290_1);
  noto(&S_noto_15_1);
  or3(&S_or3_18_1);
  and2(&S_and2_19_1);
  or2(&S_or2_247_1);
  and2(&S_and2_251_1);
  and2(&S_and2_260_1);
  and2(&S_and2_286_1);
  and2(&S_and2_288_1);
  orn(&S_orn_16_1);
  orni(&S_orni_283_1);
  rsu(&S_rsu_282_1);
  or3(&S_or3_30_1);
  and2(&S_and2_31_1);
  orn(&S_orn_36_1);
  or2(&S_or2_25_1);
  setData(idR7II82LZ1,&var1);
  setData(idR7II81LZ1,&var2);
  setData(idR0VZ05U,&var113);
  setData(idTestDiagnBaz1,&var19);
  setData(idR0DE3DLZ1,&var20);
  setData(idR0DE3CLZ1,&var21);
  setData(idTTLBaz1,&var23);
  moveData(idR0EE04LZ1,idR0EE02LDU);
  moveData(idR0EE03LZ1,idR0EE02LDU);
  moveData(idR0EE02LZ1,idR0EE02LDU);
  moveData(idR0EE01LZ1,idR0EE02LDU);
  setData(idR0AD14LZ1,&var14);
  setData(idA3VZ13LZ1,&var10);
  setData(idA3VZ15LZ1,&var13);
  setData(idA1VN71LZ1,&var38);
  setData(idB0VT71LZ1,&var72);
  setData(idB0VT61LZ1,&var106);
  setData(idB0CT01IZ1,&var100);
  setData(idR0VP73LZ1,&var73);
  setData(idR0VN11RZ1,&var111);
  setData(idR0VZ05UZ1,&var112);
  setData(idB0VN81LZ1,&var56);
  setData(idA0VN81LZ1,&var75);
  setData(idB0VN71LZ1,&var61);
  setData(idA0VN71LZ1,&var58);
  setData(idB0VZ71LZ1,&var114);
  setData(idB0EE00LZ1,&var84);
  setData(idA0EE00LZ1,&var85);
  setData(idA0VZ71LZ1,&var115);
  setData(idA0EE03LZ1,&var30);
  setData(idA0EE02LZ1,&var29);
  setData(idA0EE04LZ1,&var31);
  setData(idA0EE01LZ1,&var28);
  setData(idR0VN80LZ1,&var54);
  setData(idR0VN70LZ1,&var64);
  setData(idR0VZ71LZ1,&var78);
  setData(idR0VR02RZ1,&var123);
  setData(idR0VN79LZ1,&var33);
  setData(idR0VN69LZ1,&var32);
  setData(idB3VZ11LZ1,&var12);
  setData(idA3VZ11LZ1,&var11);
  setData(idB3VZ31LZ1,&var9);
  setData(idA3VZ31LZ1,&var8);
  setData(idR0VN09RZ1,&var126);
  moveData(idR0VN68LZ1,idR0VN65LS4);
  moveData(idR0VN67LZ1,idR0VN65LS3);
  moveData(idR0VN66LZ1,idR0VN65LS2);
  moveData(idR0VN65LZ1,idR0VN65LS1);
  moveData(idR0VN64LZ1,idR0VN61LS4);
  moveData(idR0VN63LZ1,idR0VN61LS3);
  moveData(idR0VN62LZ1,idR0VN61LS2);
  moveData(idR0VN61LZ1,idR0VN61LS1);
  moveData(idR0VN08RZ1,idR0VN01RS4);
  moveData(idR0VN07RZ1,idR0VN01RS3);
  moveData(idR0VN06RZ1,idR0VN01RS2);
  moveData(idR0VN05RZ1,idR0VN01RS1);
  moveData(idR0VN04RZ1,idR0VN02RS4);
  moveData(idR0VN03RZ1,idR0VN02RS3);
  moveData(idR0VN02RZ1,idR0VN02RS2);
  moveData(idR0VN01RZ1,idR0VN02RS1);
  setData(idB0VP71LZ1,&var130);
  setData(idA0VP71LZ1,&var128);
  setData(idA0EP02IZ1,&var129);
  setData(idB0EP02IZ1,&var131);
  setData(idR0ET02LZ1,&var107);
  setData(idB0VP41LZ1,&var89);
  setData(idA0VP41LZ1,&var90);
  setData(idR0ET01LZ1,&var102);
  setData(idA2VP81LZ1,&var24);
  setData(idB2VP81LZ1,&var25);
  setData(idB2VP51LZ1,&var136);
  setData(idB2CP01RZ1,&var103);
  setData(idB2VP41LZ1,&var27);
  setData(idA2VP51LZ1,&var138);
  setData(idA2CP01RZ1,&var104);
  setData(idA2VP41LZ1,&var26);
  setData(idB1VP41LZ1,&var91);
  setData(idA1VP41LZ1,&var110);
  setData(idA0VT71LZ1,&var71);
  setData(idA0VT61LZ1,&var141);
  setData(idA0CT01IZ1,&var101);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}
