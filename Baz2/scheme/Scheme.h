/* ����������� ���������� ���������� */
uspaint8 InternalBuf[150];

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
ssfloat fRM_10_ = {10,0}; /* tz - ����� �������� ��� */ 
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
ssbool var23;
ssbool var24;
ssbool var25;
ssbool var26;
ssbool var27;
ssbool var28;
ssbool var29;
ssbool var30;
ssbool var31;
ssint var32;
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
ssbool var100;
ssbool var101;
ssbool var102;
ssfloat var103;
ssfloat var104;
ssbool var105;
ssfloat var106;
ssfloat var107;
ssbool var108;
ssbool var109;
ssbool var110;
ssbool var111;
ssbool var112;
ssbool var113;
ssfloat var114;
sslong var115;
sslong var116;
ssbool var117;
ssbool var118;
ssbool var119;
ssbool var120;
ssbool var121;
ssbool var122;
ssbool var123;
ssbool var124;
ssbool var125;
ssfloat var126;
ssbool var127;
ssbool var128;
ssfloat var129;
ssbool var130;
ssbool var131;
sschar var132;
ssbool var133;
sschar var134;
ssbool var135;
ssbool var136;
ssbool var137;
ssbool var138;
ssbool var139;
ssbool var140;
ssbool var141;
ssbool var142;
ssbool var143;
ssbool var144;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* ���������� �������� */
psint  array_m307_x_1[6] = {&R0DE04LZ2,&R0DE05LZ2,&R0DE06LZ2,&R0DE0ALZ2,&R0DE08LZ2,&R0DE07LZ2};
psfloat  array_m189_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psfloat  array_m291_x_1[4] = {&R0VN02RS1,&R0VN02RS2,&R0VN02RS3,&R0VN02RS4};
psbool  array_m291_diag_1[4] = {&var33,&var34,&var35,&var36};
psbool  array_m282_x_1[16] = {&var76,&var41,&var42,&var87,&var12,&var9,&var131,&var43,&var46,&var47,&var85,&var13,&var10,&var133,&var19,&var16};
psbool  array_m16_x_1[6] = {&var80,&var85,&var13,&var10,&var20,&var133};
psbool  array_m36_x_1[6] = {&var87,&var9,&var12,&var131,&var78,&var20};
psfloat  array_m2_x_1[4] = {&R0VN01RS1,&R0VN01RS2,&R0VN01RS3,&R0VN01RS4};
psbool  array_m2_diag_1[4] = {&var33,&var34,&var35,&var36};
psbool  array_m3_x_1[3] = {&var93,&var113,&var37};
psbool  array_m12_x_1[3] = {&var92,&var40,&var94};

/* ���������� �������� */
_S_schl24  S_schl24_223_1 = {&R7II74LZ2,&R7II75LZ2,&R7II76LZ2,&lRM_0_,&var1};
_S_schl24  S_schl24_197_1 = {&R7II71LZ2,&R7II72LZ2,&R7II73LZ2,&lRM_0_,&var2};
_S_or2  S_or2_228_1 = {&var16,&var19,&var3};
_S_zzfs  S_zzfs_213_1 = {&var15,&fRM_0_3,&var4,&internal1_m213_tx,&internal1_m213_y0};
_S_or2  S_or2_279_1 = {&R0MD34LP1,&var4,&var5};
_S_zzfs  S_zzfs_209_1 = {&R0AD04LZ2,&fRM_0_3,&var6,&internal1_m209_tx,&internal1_m209_y0};
_S_noto  S_noto_222_1 = {&var6,&var7};
_S_and2  S_and2_227_1 = {&var7,&var3,&var8};
_S_inicn  S_inicn_204_1 = {&A3IS11LDU,&B3IS11LDU,&R0AD03LZ2,&A3IS22LDU,&B3IS22LDU,&R0AD05LZ2,&var19,&var18,&var6,&fEM_R0UL25RDU,&fEM_R0UL05RDU,&fEM_R0UL07RDU,&var9,&var10,&var11,&var12,&var13,&var14,&var15,&internal1_m204_TVuIs1,&internal1_m204_TVuIs2,&internal1_m204_TImVuIs,&internal1_m204_TNupIs1,&internal1_m204_TNupIs2,&internal1_m204_TImNupIs,&internal1_m204_TImAZ2UR,&internal1_m204_fef};
_S_or2  S_or2_217_1 = {&var1,&var21,&var16};
_S_or2  S_or2_215_1 = {&R0AD21LDU,&var6,&var17};
_S_and2  S_and2_214_1 = {&var16,&var17,&var18};
_S_or2  S_or2_205_1 = {&var21,&var2,&var19};
_S_zpfs  S_zpfs_226_1 = {&var8,&fEM_R0UL07RDU,&var20,&internal1_m226_tx,&internal1_m226_y0};
_S_noto  S_noto_206_1 = {&R6IS66LZ2,&var21};
_S_zzfs  S_zzfs_111_1 = {&B1VP81LZZ,&fRM_10000_,&var22,&internal1_m111_tx,&internal1_m111_y0};
_S_zzfs  S_zzfs_110_1 = {&A1VP81LZZ,&fRM_10000_,&var23,&internal1_m110_tx,&internal1_m110_y0};
_S_zzfs  S_zzfs_99_1 = {&var37,&fRM_10_,&var24,&internal1_m99_tx,&internal1_m99_y0};
_S_zzfs  S_zzfs_112_1 = {&var40,&fRM_10_,&var25,&internal1_m112_tx,&internal1_m112_y0};
_S_zzfs  S_zzfs_140_1 = {&B0VP81LZZ,&fRM_10000_,&var26,&internal1_m140_tx,&internal1_m140_y0};
_S_zzfs  S_zzfs_139_1 = {&A0VP81LZZ,&fRM_10000_,&var27,&internal1_m139_tx,&internal1_m139_y0};
_S_or3  S_or3_313_1 = {&var31,&var30,&var29,&var28};
_S_or2  S_or2_317_1 = {&R0DEB3LZ2,&R0DEB4LZ2,&var29};
_S_or2  S_or2_311_1 = {&R0DEB1LZ2,&R0DEB2LZ2,&var30};
_S_diagndev  S_diagndev_307_1 = {array_m307_x_1,&iRM_6_,&var31,&var32,&vainSFloat};
_S_ma  S_ma_189_1 = {array_m189_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_and2  S_and2_81_1 = {&lRM_1_,&A1EE01LS1,&var33};
_S_and2  S_and2_83_1 = {&lRM_1_,&A1EE01LS2,&var34};
_S_and2  S_and2_85_1 = {&lRM_1_,&A1EE01LS3,&var35};
_S_and2  S_and2_87_1 = {&lRM_1_,&A1EE01LS4,&var36};
_S_or2  S_or2_105_1 = {&var142,&var140,&var37};
_S_and2  S_and2_136_1 = {&var135,&var111,&var38};
_S_and2  S_and2_129_1 = {&var112,&var136,&var39};
_S_or2  S_or2_108_1 = {&var137,&var138,&var40};
_S_and2  S_and2_285_1 = {&var63,&var89,&var41};
_S_and2  S_and2_283_1 = {&var51,&var89,&var42};
_S_and2  S_and2_287_1 = {&var101,&var89,&var43};
_S_schl24  S_schl24_297_1 = {&A1VN71LS2,&A1VN71LS1,&A1VN71LS4,&A1VN71LS3,&var44};
_S_or2  S_or2_295_1 = {&var139,&var141,&var45};
_S_and2  S_and2_286_1 = {&var64,&var89,&var46};
_S_and2  S_and2_284_1 = {&var52,&var89,&var47};
_S_and2  S_and2_258_1 = {&var89,&var51,&var48};
_S_or2  S_or2_255_1 = {&var61,&var59,&var49};
_S_and2  S_and2_264_1 = {&var60,&var89,&var50};
_S_or2  S_or2_261_1 = {&var53,&var61,&var51};
_S_or2  S_or2_263_1 = {&var53,&var59,&var52};
_S_and2  S_and2_262_1 = {&var60,&var120,&var53};
_S_and2  S_and2_259_1 = {&var89,&var52,&var54};
_S_or2  S_or2_271_1 = {&R0VN76LZ2,&var123,&var55};
_S_or2  S_or2_272_1 = {&R0VN78LZ2,&var122,&var56};
_S_or2  S_or2_269_1 = {&R0VN75LZ2,&var125,&var57};
_S_or2  S_or2_270_1 = {&R0VN77LZ2,&var124,&var58};
_S_and2  S_and2_268_1 = {&var55,&var56,&var59};
_S_schl24  S_schl24_266_1 = {&var57,&var58,&var55,&var56,&var60};
_S_and2  S_and2_267_1 = {&var57,&var58,&var61};
_S_or2  S_or2_254_1 = {&var71,&var75,&var62};
_S_or2  S_or2_246_1 = {&var66,&var75,&var63};
_S_or2  S_or2_248_1 = {&var66,&var71,&var64};
_S_and2  S_and2_242_1 = {&var72,&var89,&var65};
_S_and2  S_and2_247_1 = {&var72,&var121,&var66};
_S_and2  S_and2_250_1 = {&var63,&var89,&var67};
_S_and2  S_and2_251_1 = {&var89,&var64,&var68};
_S_or2  S_or2_235_1 = {&R0VN72LZ2,&var123,&var69};
_S_or2  S_or2_236_1 = {&R0VN74LZ2,&var122,&var70};
_S_and2  S_and2_238_1 = {&var70,&var69,&var71};
_S_schl24  S_schl24_240_1 = {&var74,&var73,&var69,&var70,&var72};
_S_or2  S_or2_233_1 = {&R0VN71LZ2,&var125,&var73};
_S_or2  S_or2_234_1 = {&R0VN73LZ2,&var124,&var74};
_S_and2  S_and2_237_1 = {&var74,&var73,&var75};
_S_and2  S_and2_288_1 = {&var102,&var89,&var76};
_S_or3  S_or3_29_1 = {&var98,&var63,&var51,&var77};
_S_and2  S_and2_30_1 = {&var77,&var89,&var78};
_S_or2  S_or2_25_1 = {&var117,&var118,&var79};
_S_and2  S_and2_19_1 = {&var81,&var89,&var80};
_S_or3  S_or3_18_1 = {&var64,&var52,&var97,&var81};
_S_and2  S_and2_6_1 = {&var34,&var36,&var82};
_S_or2  S_or2_11_1 = {&var119,&var82,&var83};
_S_or2  S_or2_10_1 = {&var88,&var119,&var84};
_S_or2  S_or2_158_1 = {&var108,&var110,&var85};
_S_or2  S_or2_35_1 = {&B2IS12LDU,&A2IS12LDU,&var86};
_S_or2  S_or2_156_1 = {&var143,&var105,&var87};
_S_and2  S_and2_5_1 = {&var35,&var33,&var88};
_S_and2  S_and2_22_1 = {&var99,&var95,&var89};
_S_and2  S_and2_186_1 = {&var100,&var127,&var90};
_S_and2  S_and2_185_1 = {&var128,&var100,&var91};
_S_noto  S_noto_142_1 = {&var26,&var92};
_S_noto  S_noto_141_1 = {&var27,&var93};
_S_noto  S_noto_116_1 = {&var22,&var94};
_S_noto  S_noto_27_1 = {&var96,&var95};
_S_ovb1  S_ovb1_32_1 = {&var86,&iRM_200_,&var96,&internal1_m32_tx};
_S_noto  S_noto_14_1 = {&var83,&var97};
_S_noto  S_noto_13_1 = {&var84,&var98};
_S_noto  S_noto_24_1 = {&R0EE02LDU,&var99};
_S_bol  S_bol_181_1 = {&var129,&fRM_0_00001,&var100};
_S_noto  S_noto_289_1 = {&var83,&var101};
_S_noto  S_noto_290_1 = {&var84,&var102};
_S_scalzz  S_scalzz_150_1 = {&B0IT02IZ2,&iRM_3276_,&iRM_16000_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var103,&internal1_m150_y0};
_S_scalzz  S_scalzz_148_1 = {&A0IT02IZ2,&iRM_3276_,&iRM_16000_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var104,&internal1_m148_y0};
_S_geterr  S_geterr_152_1 = {&var104,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var105};
_S_scalzz  S_scalzz_92_1 = {&B2IP01IZ2,&iRM_3276_,&iRM_16000_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var106,&internal1_m92_y0};
_S_scalzz  S_scalzz_90_1 = {&A2IP01IZ2,&iRM_3276_,&iRM_16000_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var107,&internal1_m90_y0};
_S_drg  S_drg_161_1 = {&var103,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var108,&internal1_m161_y1};
_S_drg  S_drg_172_1 = {&var103,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var109,&internal1_m172_y1};
_S_geterr  S_geterr_154_1 = {&var103,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var110};
_S_noto  S_noto_137_1 = {&var137,&var111};
_S_noto  S_noto_128_1 = {&var142,&var112};
_S_noto  S_noto_115_1 = {&var23,&var113};
_S_srm  S_srm_291_1 = {array_m291_x_1,array_m291_diag_1,&iRM_4_,&iRM_3_,&var114,&vainSBool};
_S_rsu  S_rsu_281_1 = {&var5,&var116,&var115,&internal1_m281_q0};
_S_orni  S_orni_282_1 = {array_m282_x_1,&iRM_16_,&vainSBool,&var116};
_S_orn  S_orn_16_1 = {array_m16_x_1,&iRM_6_,&var117};
_S_orn  S_orn_36_1 = {array_m36_x_1,&iRM_6_,&var118};
_S_noto  S_noto_7_1 = {&var130,&var119};
_S_noto  S_noto_257_1 = {&var49,&var120};
_S_noto  S_noto_252_1 = {&var62,&var121};
_S_noto  S_noto_241_1 = {&A1EE01LS4,&var122};
_S_noto  S_noto_245_1 = {&A1EE01LS2,&var123};
_S_noto  S_noto_244_1 = {&A1EE01LS3,&var124};
_S_noto  S_noto_239_1 = {&A1EE01LS1,&var125};
_S_react  S_react_177_1 = {&var129,&var126};
_S_bol  S_bol_182_1 = {&fEM_R0UR04RZZ,&var129,&var127};
_S_bol  S_bol_180_1 = {&fEM_R0UR01RZZ,&var129,&var128};
_S_srm  S_srm_2_1 = {array_m2_x_1,array_m2_diag_1,&iRM_4_,&iRM_3_,&var129,&var130};
_S_ornc  S_ornc_3_1 = {array_m3_x_1,&iRM_3_,&var131,&var132};
_S_ornc  S_ornc_12_1 = {array_m12_x_1,&iRM_3_,&var133,&var134};
_S_tprg  S_tprg_130_1 = {&var106,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var135,&internal1_m130_y0};
_S_tprg  S_tprg_124_1 = {&var107,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var136,&internal1_m124_y0};
_S_geterr  S_geterr_100_1 = {&var106,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var137};
_S_drg  S_drg_101_1 = {&var106,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var138,&internal1_m101_y1};
_S_drg  S_drg_120_1 = {&var106,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var139,&internal1_m120_y1};
_S_drg  S_drg_94_1 = {&var107,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var140,&internal1_m94_y1};
_S_drg  S_drg_106_1 = {&var107,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var141,&internal1_m106_y1};
_S_geterr  S_geterr_96_1 = {&var107,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var142};
_S_drg  S_drg_160_1 = {&var104,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var143,&internal1_m160_y1};
_S_drg  S_drg_168_1 = {&var104,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var144,&internal1_m168_y1};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  noto(&S_noto_239_1);
  noto(&S_noto_244_1);
  noto(&S_noto_245_1);
  noto(&S_noto_241_1);
  scalzz(&S_scalzz_90_1);
  scalzz(&S_scalzz_92_1);
  scalzz(&S_scalzz_148_1);
  scalzz(&S_scalzz_150_1);
  or2(&S_or2_234_1);
  or2(&S_or2_233_1);
  or2(&S_or2_236_1);
  or2(&S_or2_235_1);
  or2(&S_or2_270_1);
  or2(&S_or2_269_1);
  or2(&S_or2_272_1);
  or2(&S_or2_271_1);
  schl24(&S_schl24_297_1);
  ma(&S_ma_189_1);
  diagndev(&S_diagndev_307_1);
  or2(&S_or2_311_1);
  or2(&S_or2_317_1);
  or3(&S_or3_313_1);
  zzfs(&S_zzfs_139_1);
  zzfs(&S_zzfs_140_1);
  zzfs(&S_zzfs_110_1);
  zzfs(&S_zzfs_111_1);
  noto(&S_noto_206_1);
  zzfs(&S_zzfs_209_1);
  schl24(&S_schl24_197_1);
  schl24(&S_schl24_223_1);
  drg(&S_drg_168_1);
  drg(&S_drg_160_1);
  geterr(&S_geterr_96_1);
  drg(&S_drg_106_1);
  drg(&S_drg_94_1);
  drg(&S_drg_120_1);
  drg(&S_drg_101_1);
  geterr(&S_geterr_100_1);
  tprg(&S_tprg_124_1);
  tprg(&S_tprg_130_1);
  noto(&S_noto_115_1);
  noto(&S_noto_128_1);
  noto(&S_noto_137_1);
  geterr(&S_geterr_154_1);
  drg(&S_drg_172_1);
  drg(&S_drg_161_1);
  geterr(&S_geterr_152_1);
  noto(&S_noto_24_1);
  noto(&S_noto_116_1);
  noto(&S_noto_141_1);
  noto(&S_noto_142_1);
  or2(&S_or2_156_1);
  or2(&S_or2_35_1);
  or2(&S_or2_158_1);
  and2(&S_and2_237_1);
  schl24(&S_schl24_240_1);
  and2(&S_and2_238_1);
  or2(&S_or2_254_1);
  and2(&S_and2_267_1);
  schl24(&S_schl24_266_1);
  and2(&S_and2_268_1);
  or2(&S_or2_255_1);
  or2(&S_or2_295_1);
  or2(&S_or2_108_1);
  and2(&S_and2_129_1);
  and2(&S_and2_136_1);
  or2(&S_or2_105_1);
  and2(&S_and2_87_1);
  and2(&S_and2_85_1);
  and2(&S_and2_83_1);
  and2(&S_and2_81_1);
  zzfs(&S_zzfs_112_1);
  zzfs(&S_zzfs_99_1);
  or2(&S_or2_205_1);
  or2(&S_or2_215_1);
  or2(&S_or2_217_1);
  noto(&S_noto_222_1);
  or2(&S_or2_228_1);
  ornc(&S_ornc_12_1);
  ornc(&S_ornc_3_1);
  srm(&S_srm_2_1);
  bol(&S_bol_180_1);
  bol(&S_bol_182_1);
  react(&S_react_177_1);
  noto(&S_noto_252_1);
  noto(&S_noto_257_1);
  noto(&S_noto_7_1);
  srm(&S_srm_291_1);
  bol(&S_bol_181_1);
  ovb1(&S_ovb1_32_1);
  noto(&S_noto_27_1);
  and2(&S_and2_185_1);
  and2(&S_and2_186_1);
  and2(&S_and2_22_1);
  and2(&S_and2_5_1);
  or2(&S_or2_10_1);
  and2(&S_and2_6_1);
  and2(&S_and2_247_1);
  and2(&S_and2_242_1);
  or2(&S_or2_248_1);
  or2(&S_or2_246_1);
  and2(&S_and2_262_1);
  or2(&S_or2_263_1);
  or2(&S_or2_261_1);
  and2(&S_and2_264_1);
  and2(&S_and2_258_1);
  and2(&S_and2_284_1);
  and2(&S_and2_286_1);
  and2(&S_and2_283_1);
  and2(&S_and2_285_1);
  and2(&S_and2_214_1);
  inicn(&S_inicn_204_1);
  and2(&S_and2_227_1);
  zzfs(&S_zzfs_213_1);
  noto(&S_noto_290_1);
  noto(&S_noto_13_1);
  or2(&S_or2_11_1);
  or3(&S_or3_29_1);
  and2(&S_and2_288_1);
  and2(&S_and2_251_1);
  and2(&S_and2_250_1);
  and2(&S_and2_259_1);
  zpfs(&S_zpfs_226_1);
  or2(&S_or2_279_1);
  noto(&S_noto_289_1);
  noto(&S_noto_14_1);
  or3(&S_or3_18_1);
  and2(&S_and2_19_1);
  and2(&S_and2_30_1);
  and2(&S_and2_287_1);
  orn(&S_orn_36_1);
  orn(&S_orn_16_1);
  orni(&S_orni_282_1);
  rsu(&S_rsu_281_1);
  or2(&S_or2_25_1);
  setData(idR0AD14LZ2,&var15);
  setData(idA3VZ13LZ2,&var11);
  setData(idA3VZ15LZ2,&var14);
  setData(idB3VZ11LZ2,&var13);
  setData(idA3VZ11LZ2,&var12);
  setData(idB3VZ31LZ2,&var10);
  setData(idA3VZ31LZ2,&var9);
  setData(idR0VZ05U,&var116);
  setData(idTestDiagnBaz2,&var28);
  setData(idR0DE3DLZ2,&var29);
  setData(idR0DE3CLZ2,&var30);
  setData(idTTLBaz2,&var32);
  moveData(idR0EE04LZ2,idR0EE02LDU);
  moveData(idR0EE03LZ2,idR0EE02LDU);
  moveData(idR0EE02LZ2,idR0EE02LDU);
  moveData(idR0EE01LZ2,idR0EE02LDU);
  setData(idA1VN71LZ2,&var44);
  setData(idB0VT71LZ2,&var85);
  setData(idB0VT61LZ2,&var109);
  setData(idB0CT01IZ2,&var103);
  setData(idR0VP73LZ2,&var45);
  setData(idR0VN11RZ2,&var114);
  setData(idR0VZ05UZ2,&var115);
  setData(idB0VN81LZ2,&var54);
  setData(idA0VN81LZ2,&var48);
  setData(idB0VN71LZ2,&var68);
  setData(idA0VN71LZ2,&var67);
  setData(idB0VZ71LZ2,&var117);
  setData(idB0EE00LZ2,&var83);
  setData(idA0EE00LZ2,&var84);
  setData(idA0VZ71LZ2,&var118);
  setData(idA0EE03LZ2,&var35);
  setData(idA0EE02LZ2,&var34);
  setData(idA0EE04LZ2,&var36);
  setData(idA0EE01LZ2,&var33);
  setData(idR0VN80LZ2,&var50);
  setData(idR0VN70LZ2,&var65);
  setData(idR0VZ71LZ2,&var79);
  setData(idR0VR02RZ2,&var126);
  setData(idR0VN79LZ2,&var90);
  setData(idR0VN69LZ2,&var91);
  setData(idR0VN09RZ2,&var129);
  moveData(idR0VN68LZ2,idR0VN65LS4);
  moveData(idR0VN67LZ2,idR0VN65LS3);
  moveData(idR0VN66LZ2,idR0VN65LS2);
  moveData(idR0VN65LZ2,idR0VN65LS1);
  moveData(idR0VN64LZ2,idR0VN61LS4);
  moveData(idR0VN63LZ2,idR0VN61LS3);
  moveData(idR0VN62LZ2,idR0VN61LS2);
  moveData(idR0VN61LZ2,idR0VN61LS1);
  moveData(idR0VN08RZ2,idR0VN01RS4);
  moveData(idR0VN07RZ2,idR0VN01RS3);
  moveData(idR0VN06RZ2,idR0VN01RS2);
  moveData(idR0VN05RZ2,idR0VN01RS1);
  moveData(idR0VN04RZ2,idR0VN02RS4);
  moveData(idR0VN03RZ2,idR0VN02RS3);
  moveData(idR0VN02RZ2,idR0VN02RS2);
  moveData(idR0VN01RZ2,idR0VN02RS1);
  setData(idB0VP71LZ2,&var133);
  setData(idA0VP71LZ2,&var131);
  setData(idA0EP02IZ2,&var132);
  setData(idB0EP02IZ2,&var134);
  setData(idR0ET02LZ2,&var110);
  setData(idB0VP41LZ2,&var92);
  setData(idA0VP41LZ2,&var93);
  setData(idR0ET01LZ2,&var105);
  setData(idA2VP81LZ2,&var39);
  setData(idB2VP81LZ2,&var38);
  setData(idB2VP51LZ2,&var139);
  setData(idB2CP01RZ2,&var106);
  setData(idB2VP41LZ2,&var25);
  setData(idA2VP51LZ2,&var141);
  setData(idA2CP01RZ2,&var107);
  setData(idA2VP41LZ2,&var24);
  setData(idB1VP41LZ2,&var94);
  setData(idA1VP41LZ2,&var113);
  setData(idA0VT71LZ2,&var87);
  setData(idA0VT61LZ2,&var144);
  setData(idA0CT01IZ2,&var104);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}
