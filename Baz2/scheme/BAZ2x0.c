#include "baz2.h"
/* Определение внутренних параметров */
#define bFirstEnterFlag (*((psbool)(InternalBuf+0x0)))
#define internal1_m245_tx (*((psfloat)(InternalBuf+0x2))) /*tx - время накопленное сек*/
#define internal1_m245_y0 (*((pschar)(InternalBuf+0x7))) /*y0*/
#define internal1_m316_tx (*((psfloat)(InternalBuf+0x9))) /*tx - время накопленное сек*/
#define internal1_m316_y0 (*((pschar)(InternalBuf+0xE))) /*y0*/
#define internal1_m213_tx (*((psfloat)(InternalBuf+0x10))) /*tx - время накопленное сек*/
#define internal1_m213_y0 (*((pschar)(InternalBuf+0x15))) /*y0*/
#define internal1_m211_tx (*((psfloat)(InternalBuf+0x17))) /*tx - время накопленное сек*/
#define internal1_m211_y0 (*((pschar)(InternalBuf+0x1C))) /*y0*/
#define internal1_m253_tx (*((psfloat)(InternalBuf+0x1E))) /*tx - время накопленное сек*/
#define internal1_m253_y0 (*((pschar)(InternalBuf+0x23))) /*y0*/
#define internal1_m209_tx (*((psfloat)(InternalBuf+0x25))) /*tx - время накопленное сек*/
#define internal1_m209_y0 (*((pschar)(InternalBuf+0x2A))) /*y0*/
#define internal1_m207_tx (*((psfloat)(InternalBuf+0x2C))) /*tx - время накопленное сек*/
#define internal1_m207_y0 (*((pschar)(InternalBuf+0x31))) /*y0*/
#define internal1_m33_tx (*((psint)(InternalBuf+0x33))) /*tx - внутренний параметр*/
#define internal1_m144_y0 (*((psfloat)(InternalBuf+0x36))) /*y0*/
#define internal1_m142_y0 (*((psfloat)(InternalBuf+0x3B))) /*y0*/
#define internal1_m94_y0 (*((psfloat)(InternalBuf+0x40))) /*y0*/
#define internal1_m92_y0 (*((psfloat)(InternalBuf+0x45))) /*y0*/
#define internal1_m155_y1 (*((psbool)(InternalBuf+0x4A))) /*y1 - внутренний параметр*/
#define internal1_m166_y1 (*((psbool)(InternalBuf+0x4C))) /*y1 - внутренний параметр*/
#define internal1_m309_q0 (*((pslong)(InternalBuf+0x4E))) /*q0 - внутренний параметр*/
#define internal1_m130_y0 (*((psbool)(InternalBuf+0x53))) /*state*/
#define internal1_m124_y0 (*((psbool)(InternalBuf+0x55))) /*state*/
#define internal1_m107_y1 (*((psbool)(InternalBuf+0x57))) /*y1 - внутренний параметр*/
#define internal1_m118_y1 (*((psbool)(InternalBuf+0x59))) /*y1 - внутренний параметр*/
#define internal1_m98_y1 (*((psbool)(InternalBuf+0x5B))) /*y1 - внутренний параметр*/
#define internal1_m105_y1 (*((psbool)(InternalBuf+0x5D))) /*y1 - внутренний параметр*/
#define internal1_m154_y1 (*((psbool)(InternalBuf+0x5F))) /*y1 - внутренний параметр*/
#define internal1_m163_y1 (*((psbool)(InternalBuf+0x61))) /*y1 - внутренний параметр*/
int InternalBufSize = 99;
uspaint8 InternalBuf[99];

/* Определение констант ПЗУ и ЭСППЗУ*/
struct      sbool  lRM_0_ = {    0,0}; /* A-Граница участка насыщения А */ 
struct      sbool  lRM_1_ = {    1,0}; /* B-Граница участка насыщения В */ 
struct      slong  dRM_0_ = {    0,0}; /* lx вход лонг */ 
struct      schar  bRM_0_ = {    0,0}; /* cx вход байтовый */ 
struct       sint  iRM_0_ = {    0,0}; /* ix вход целый */ 
struct       sint  iRM_3_ = {    3,0}; /* N-число входов */ 
struct       sint  iRM_4_ = {    4,0}; /* n - размерность массива */ 
struct       sint  iRM_6_ = {    6,0}; /* N-число входов */ 
struct       sint  iRM_17_ = {   17,0}; /* n - размерность массива входных сигналов */ 
struct       sint  iRM_819_ = {  819,0}; /* a */ 
struct       sint  iRM_4095_ = { 4095,0}; /* b */ 
struct     sfloat  fRM_0_00001 = {0.00001,0}; /* X2 */ 
struct       sint  iRM_200_ = {  200,0}; /* tz - ширина импульса, 10-ки мс */ 
struct     sfloat  fRM_0_2 = {  0.2,0}; /* tz - время задержки сек */ 
struct     sfloat  fRM_1_0 = {  1.0,0}; /* tz - время задержки сек */ 
struct       sint  iRM_7_ = {    7,0}; /* n - N-размерность массива x */ 
struct     sfloat  fRM_0_002 = {0.002,0}; /* x - массив входных параметров */ 
struct     sfloat  fRM_0_005 = {0.005,0}; /* x - массив входных параметров */ 
struct     sfloat  fRM_0_007 = {0.007,0}; /* x - массив входных параметров */ 
struct     sfloat  fRM_0_01 = { 0.01,0}; /* x - массив входных параметров */ 
struct     sfloat  fRM_0_015 = {0.015,0}; /* x - массив входных параметров */ 
struct     sfloat  fRM_0_02 = { 0.02,0}; /* x - массив входных параметров */ 
struct     sfloat  fRM_1_7 = {  1.7,0}; /* x - массив входных параметров */ 
#define fEM_R0UT02RZZ  (*((psfloat)(SpaEEPROMBuf+0x0)))
#define fEM_R0UT01RZZ  (*((psfloat)(SpaEEPROMBuf+0x5)))
#define fEM_A2UP03RZZ  (*((psfloat)(SpaEEPROMBuf+0xA)))
#define fEM_A2UP04RZZ  (*((psfloat)(SpaEEPROMBuf+0xF)))
#define fEM_R0UT72RZZ  (*((psfloat)(SpaEEPROMBuf+0x14)))
#define fEM_R0UT71RZZ  (*((psfloat)(SpaEEPROMBuf+0x19)))
#define fEM_R0UT62RZZ  (*((psfloat)(SpaEEPROMBuf+0x1E)))
#define fEM_R0UT61RZZ  (*((psfloat)(SpaEEPROMBuf+0x23)))
#define fEM_A2UP41RZZ  (*((psfloat)(SpaEEPROMBuf+0x28)))
#define fEM_A2UP42RZZ  (*((psfloat)(SpaEEPROMBuf+0x2D)))
#define fEM_A2UP51RZZ  (*((psfloat)(SpaEEPROMBuf+0x32)))
#define fEM_A2UP81RZZ  (*((psfloat)(SpaEEPROMBuf+0x37)))
#define fEM_A2UP84RZZ  (*((psfloat)(SpaEEPROMBuf+0x3C)))
#define fEM_A2UP82RZZ  (*((psfloat)(SpaEEPROMBuf+0x41)))
#define fEM_A2UP52RZZ  (*((psfloat)(SpaEEPROMBuf+0x46)))
#define fEM_A2UP83RZZ  (*((psfloat)(SpaEEPROMBuf+0x4B)))
#define fEM_R0UR01RZZ  (*((psfloat)(SpaEEPROMBuf+0x50)))
#define fEM_R0UR04RZZ  (*((psfloat)(SpaEEPROMBuf+0x55)))
#define fEM_A1UL12RZZ  (*((psfloat)(SpaEEPROMBuf+0x5A)))
#define fEM_A1UL11RZZ  (*((psfloat)(SpaEEPROMBuf+0x5F)))
#define fEM_R7UI73RZZ  (*((psfloat)(SpaEEPROMBuf+0x64)))

int SpaEEPROMBufSize = 105;
uspaint8 SpaEEPROMBuf[105];

/* Определение переменных */
struct sbool  var1;
struct sbool  var2;
struct sbool  var3;
struct sbool  var4;
struct sbool  var5;
struct sbool  var6;
struct sbool  var7;
struct sbool  var8;
struct sbool  var9;
struct sbool  var10;
struct sbool  var11;
struct sbool  var12;
struct sbool  var13;
struct sbool  var14;
struct sbool  var15;
struct sbool  var16;
struct sbool  var17;
struct sbool  var18;
struct sbool  var19;
struct sbool  var20;
struct sbool  var21;
struct sbool  var22;
struct sbool  var23;
struct sbool  var24;
struct sbool  var25;
struct sbool  var26;
struct sbool  var27;
struct sbool  var28;
struct sbool  var29;
struct sbool  var30;
struct sbool  var31;
struct sbool  var32;
struct sbool  var33;
struct sbool  var34;
struct sbool  var35;
struct sbool  var36;
struct sbool  var37;
struct sbool  var38;
struct sbool  var39;
struct sbool  var40;
struct sbool  var41;
struct sbool  var42;
struct sbool  var43;
struct sbool  var44;
struct sbool  var45;
struct sbool  var46;
struct sbool  var47;
struct sbool  var48;
struct sbool  var49;
struct sbool  var50;
struct sbool  var51;
struct sbool  var52;
struct sbool  var53;
struct sbool  var54;
struct sbool  var55;
struct sbool  var56;
struct sbool  var57;
struct sbool  var58;
struct sbool  var59;
struct sbool  var60;
struct sbool  var61;
struct sbool  var62;
struct sbool  var63;
struct sbool  var64;
struct sbool  var65;
struct sbool  var66;
struct sbool  var67;
struct sbool  var68;
struct sbool  var69;
struct sbool  var70;
struct sbool  var71;
struct sbool  var72;
struct sbool  var73;
struct sbool  var74;
struct sbool  var75;
struct sbool  var76;
struct sbool  var77;
struct sbool  var78;
struct sbool  var79;
struct sbool  var80;
struct sbool  var81;
struct sbool  var82;
struct sbool  var83;
struct sbool  var84;
struct sbool  var85;
struct sbool  var86;
struct sbool  var87;
struct sbool  var88;
struct sbool  var89;
struct sbool  var90;
struct sbool  var91;
struct sbool  var92;
struct sbool  var93;
struct sbool  var94;
struct sbool  var95;
struct sbool  var96;
struct sbool  var97;
struct sbool  var98;
struct sbool  var99;
struct sbool  var100;
struct sbool  var101;
struct sbool  var102;
struct sbool  var103;
struct sbool  var104;
struct sbool  var105;
struct sbool  var106;
struct sbool  var107;
struct sbool  var108;
struct sbool  var109;
struct sbool  var110;
struct sbool  var111;
struct sbool  var112;
struct sbool  var113;
struct sbool  var114;
struct sbool  var115;
struct sbool  var116;
struct sbool  var117;
struct sbool  var118;
struct sbool  var119;
struct sbool  var120;
struct sbool  var121;
struct sbool  var122;
struct sbool  var123;
struct sbool  var124;
struct sbool  var125;
struct sfloat  var126;
struct sfloat  var127;
struct sbool  var128;
struct sfloat  var129;
struct sfloat  var130;
struct sbool  var131;
struct sbool  var132;
struct sbool  var133;
struct sbool  var134;
struct sbool  var135;
struct sbool  var136;
struct sfloat  var137;
struct slong  var138;
struct slong  var139;
struct sbool  var140;
struct sbool  var141;
struct sbool  var142;
struct sbool  var143;
struct sbool  var144;
struct sbool  var145;
struct sbool  var146;
struct sbool  var147;
struct sbool  var148;
struct sfloat  var149;
struct sbool  var150;
struct sbool  var151;
struct sfloat  var152;
struct sbool  var153;
struct sbool  var154;
struct schar  var155;
struct sbool  var156;
struct schar  var157;
struct sbool  var158;
struct sbool  var159;
struct sbool  var160;
struct sbool  var161;
struct sbool  var162;
struct sbool  var163;
struct sbool  var164;
struct sbool  var165;
struct sbool  var166;
struct sbool  var167;
struct slong  vainSLong;
struct sfloat  vainSFloat;
struct sint  vainSInt;
struct sbool  vainSBool;
struct schar  vainSChar;
char  vainSText[] = "";

/* Объявление массивов */
psfloat  array_m185_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psfloat  array_m331_x_1[4] = {&signal_R0VN02RS1,&signal_R0VN02RS2,&signal_R0VN02RS3,&signal_R0VN02RS4};
psbool  array_m331_diag_1[4] = {&var5,&var6,&var7,&var8};
psbool  array_m311_x_1[17] = {&var76,&var37,&var38,&var87,&var19,&var30,&var154,&var39,&var46,&var47,&var85,&var23,&var29,&var156,&var43,&var44,&var45};
psbool  array_m16_x_1[6] = {&var80,&var85,&var29,&var23,&var98,&var156};
psbool  array_m36_x_1[6] = {&var87,&var19,&var30,&var154,&var78,&var98};
psfloat  array_m2_x_1[4] = {&signal_R0VN01RS1,&signal_R0VN01RS2,&signal_R0VN01RS3,&signal_R0VN01RS4};
psbool  array_m2_diag_1[4] = {&var5,&var6,&var7,&var8};
psbool  array_m3_x_1[3] = {&var105,&var136,&var9};
psbool  array_m12_x_1[3] = {&var104,&var12,&var106};

/* описания структур для ф-ий */

/* код алгоблоков */
/* Объявление структур */
_S_ma far S_ma_185_1 = {array_m185_x_1,&signal_R0MW12IP2,&iRM_7_,&vainSFloat};
_S_and3 far S_and3_208_1 = {&var100,&var99,&signal_R0AD05LZ2,&var1};
_S_and3 far S_and3_212_1 = {&var97,&var96,&signal_R0AD03LZ2,&var2};
_S_and2 far S_and2_252_1 = {&var28,&var121,&var3};
_S_zzfs far S_zzfs_245_1 = {&signal_R0AD04LZ2,&fRM_1_0,&var4,&internal1_m245_tx,&internal1_m245_y0};
_S_and2 far S_and2_81_1 = {&signal_A0EE05LZ2,&signal_A1EE01LS1,&var5};
_S_and2 far S_and2_83_1 = {&signal_A0EE06LZ2,&signal_A1EE01LS2,&var6};
_S_and2 far S_and2_85_1 = {&signal_A0EE07LZ2,&signal_A1EE01LS3,&var7};
_S_and2 far S_and2_87_1 = {&signal_A0EE08LZ2,&signal_A1EE01LS4,&var8};
_S_or2 far S_or2_104_1 = {&var165,&var163,&var9};
_S_and2 far S_and2_134_1 = {&var158,&var134,&var10};
_S_and2 far S_and2_127_1 = {&var135,&var159,&var11};
_S_or2 far S_or2_111_1 = {&var160,&var161,&var12};
_S_or2 far S_or2_200_1 = {&signal_A3IS22LDU,&signal_R0AD05LZ2,&var13};
_S_or2 far S_or2_202_1 = {&signal_B3IS22LDU,&signal_R0AD05LZ2,&var14};
_S_or2 far S_or2_203_1 = {&signal_R0AD03LZ2,&var120,&var15};
_S_or2 far S_or2_205_1 = {&var119,&signal_R0AD03LZ2,&var16};
_S_and2 far S_and2_214_1 = {&var100,&signal_R0VW13LDU,&var17};
_S_and2 far S_and2_216_1 = {&var99,&signal_R0VW23LDU,&var18};
_S_or2 far S_or2_229_1 = {&var20,&var21,&var19};
_S_and3 far S_and3_230_1 = {&var115,&var18,&var17,&var20};
_S_and3 far S_and3_225_1 = {&var17,&var124,&var115,&var21};
_S_and3 far S_and3_226_1 = {&var18,&var125,&var115,&var22};
_S_or2 far S_or2_231_1 = {&var22,&var20,&var23};
_S_or2 far S_or2_244_1 = {&signal_R7II72LZ2,&var101,&var24};
_S_or2 far S_or2_250_1 = {&var102,&signal_R7II71LZ2,&var25};
_S_or2 far S_or2_256_1 = {&var103,&signal_R7II73LZ2,&var26};
_S_or2 far S_or2_258_1 = {&signal_R0AD21LDU,&signal_R0AD04LZ2,&var27};
_S_or3 far S_or3_251_1 = {&var34,&var25,&var24,&var28};
_S_or2 far S_or2_234_1 = {&var33,&var31,&var29};
_S_or2 far S_or2_232_1 = {&var32,&var33,&var30};
_S_and3 far S_and3_228_1 = {&var123,&var35,&var114,&var31};
_S_and3 far S_and3_227_1 = {&var36,&var122,&var114,&var32};
_S_and3 far S_and3_233_1 = {&var114,&var35,&var36,&var33};
_S_and2 far S_and2_257_1 = {&var27,&var26,&var34};
_S_and2 far S_and2_219_1 = {&var96,&signal_R0VW23LDU,&var35};
_S_and2 far S_and2_217_1 = {&var97,&signal_R0VW13LDU,&var36};
_S_and2 far S_and2_314_1 = {&var63,&var89,&var37};
_S_and2 far S_and2_312_1 = {&var51,&var89,&var38};
_S_and2 far S_and2_317_1 = {&var117,&var89,&var39};
_S_schl24 far S_schl24_333_1 = {&signal_A1VN71LS2,&signal_A1VN71LS1,&signal_A1VN71LS4,&signal_A1VN71LS3,&var40};
_S_or2 far S_or2_337_1 = {&var164,&var162,&var41};
_S_and2 far S_and2_324_1 = {&var113,&var112,&var42};
_S_and2 far S_and2_319_1 = {&var24,&var95,&var43};
_S_and2 far S_and2_320_1 = {&var25,&var95,&var44};
_S_and2 far S_and2_321_1 = {&var34,&var95,&var45};
_S_and2 far S_and2_315_1 = {&var64,&var89,&var46};
_S_and2 far S_and2_313_1 = {&var52,&var89,&var47};
_S_and2 far S_and2_289_1 = {&var89,&var51,&var48};
_S_or2 far S_or2_286_1 = {&var61,&var59,&var49};
_S_and2 far S_and2_295_1 = {&var60,&var89,&var50};
_S_or2 far S_or2_292_1 = {&var53,&var61,&var51};
_S_or2 far S_or2_294_1 = {&var53,&var59,&var52};
_S_and2 far S_and2_293_1 = {&var60,&var143,&var53};
_S_and2 far S_and2_290_1 = {&var89,&var52,&var54};
_S_or2 far S_or2_302_1 = {&signal_R0VN76LZ2,&var146,&var55};
_S_or2 far S_or2_303_1 = {&signal_R0VN78LZ2,&var145,&var56};
_S_or2 far S_or2_300_1 = {&signal_R0VN75LZ2,&var148,&var57};
_S_or2 far S_or2_301_1 = {&signal_R0VN77LZ2,&var147,&var58};
_S_and2 far S_and2_299_1 = {&var55,&var56,&var59};
_S_schl24 far S_schl24_297_1 = {&var57,&var58,&var55,&var56,&var60};
_S_and2 far S_and2_298_1 = {&var57,&var58,&var61};
_S_or2 far S_or2_285_1 = {&var71,&var75,&var62};
_S_or2 far S_or2_277_1 = {&var66,&var75,&var63};
_S_or2 far S_or2_279_1 = {&var66,&var71,&var64};
_S_and2 far S_and2_273_1 = {&var72,&var89,&var65};
_S_and2 far S_and2_278_1 = {&var72,&var144,&var66};
_S_and2 far S_and2_281_1 = {&var63,&var89,&var67};
_S_and2 far S_and2_282_1 = {&var89,&var64,&var68};
_S_or2 far S_or2_266_1 = {&signal_R0VN72LZ2,&var146,&var69};
_S_or2 far S_or2_267_1 = {&signal_R0VN74LZ2,&var145,&var70};
_S_and2 far S_and2_269_1 = {&var70,&var69,&var71};
_S_schl24 far S_schl24_271_1 = {&var74,&var73,&var69,&var70,&var72};
_S_or2 far S_or2_264_1 = {&signal_R0VN71LZ2,&var148,&var73};
_S_or2 far S_or2_265_1 = {&signal_R0VN73LZ2,&var147,&var74};
_S_and2 far S_and2_268_1 = {&var74,&var73,&var75};
_S_and2 far S_and2_318_1 = {&var118,&var89,&var76};
_S_or3 far S_or3_30_1 = {&var110,&var63,&var51,&var77};
_S_and2 far S_and2_31_1 = {&var77,&var89,&var78};
_S_or2 far S_or2_25_1 = {&var140,&var141,&var79};
_S_and2 far S_and2_19_1 = {&var81,&var89,&var80};
_S_or3 far S_or3_18_1 = {&var64,&var52,&var109,&var81};
_S_and2 far S_and2_6_1 = {&var6,&var8,&var82};
_S_or2 far S_or2_11_1 = {&var142,&var82,&var83};
_S_or2 far S_or2_10_1 = {&var88,&var142,&var84};
_S_or2 far S_or2_152_1 = {&var131,&var133,&var85};
_S_or2 far S_or2_35_1 = {&signal_B2IS12LDU,&signal_A2IS12LDU,&var86};
_S_or2 far S_or2_150_1 = {&var166,&var128,&var87};
_S_and2 far S_and2_5_1 = {&var7,&var5,&var88};
_S_and2 far S_and2_22_1 = {&var111,&var107,&var89};
_S_and2 far S_and2_180_1 = {&var116,&var150,&var90};
_S_and2 far S_and2_179_1 = {&var151,&var116,&var91};
_S_and2 far S_and2_188_1 = {&signal_R0AD04LZ2,&signal_R7II72LZ2,&var92};
_S_and2 far S_and2_186_1 = {&signal_R0AD04LZ2,&signal_R7II71LZ2,&var93};
_S_and2 far S_and2_182_1 = {&signal_R0AD04LZ2,&signal_R7II73LZ2,&var94};
_S_zpfs far S_zpfs_316_1 = {&var42,&fRM_0_2,&var95,&internal1_m316_tx,&internal1_m316_y0};
_S_zpfs far S_zpfs_213_1 = {&var16,&fEM_A1UL11RZZ,&var96,&internal1_m213_tx,&internal1_m213_y0};
_S_zpfs far S_zpfs_211_1 = {&var15,&fEM_A1UL11RZZ,&var97,&internal1_m211_tx,&internal1_m211_y0};
_S_zpfs far S_zpfs_253_1 = {&var3,&fEM_R7UI73RZZ,&var98,&internal1_m253_tx,&internal1_m253_y0};
_S_zpfs far S_zpfs_209_1 = {&var14,&fEM_A1UL12RZZ,&var99,&internal1_m209_tx,&internal1_m209_y0};
_S_zpfs far S_zpfs_207_1 = {&var13,&fEM_A1UL12RZZ,&var100,&internal1_m207_tx,&internal1_m207_y0};
_S_noto far S_noto_237_1 = {&signal_R6IS66LZZ,&var101};
_S_noto far S_noto_249_1 = {&signal_R6IS67LZZ,&var102};
_S_noto far S_noto_255_1 = {&signal_R6IS68LZZ,&var103};
_S_noto far S_noto_129_1 = {&signal_B0VP81LZZ,&var104};
_S_noto far S_noto_128_1 = {&signal_A0VP81LZZ,&var105};
_S_noto far S_noto_97_1 = {&signal_B1VP81LZZ,&var106};
_S_noto far S_noto_27_1 = {&var108,&var107};
_S_ovb1 far S_ovb1_33_1 = {&var86,&iRM_200_,&var108,&internal1_m33_tx};
_S_noto far S_noto_14_1 = {&var83,&var109};
_S_noto far S_noto_13_1 = {&var84,&var110};
_S_noto far S_noto_24_1 = {&signal_R0AD21LDU,&var111};
_S_noto far S_noto_326_1 = {&signal_R0AD16LDU,&var112};
_S_noto far S_noto_325_1 = {&signal_R0AD14LDU,&var113};
_S_noto far S_noto_218_1 = {&signal_R0AD03LZ2,&var114};
_S_noto far S_noto_215_1 = {&signal_R0AD05LZ2,&var115};
_S_bol far S_bol_175_1 = {&var152,&fRM_0_00001,&var116};
_S_noto far S_noto_322_1 = {&var83,&var117};
_S_noto far S_noto_323_1 = {&var84,&var118};
_S_noto far S_noto_199_1 = {&signal_B3IS11LDU,&var119};
_S_noto far S_noto_198_1 = {&signal_A3IS11LDU,&var120};
_S_noto far S_noto_246_1 = {&var4,&var121};
_S_noto far S_noto_223_1 = {&signal_R0VW23LDU,&var122};
_S_noto far S_noto_222_1 = {&signal_R0VW13LDU,&var123};
_S_noto far S_noto_221_1 = {&signal_R0VW23LDU,&var124};
_S_noto far S_noto_220_1 = {&signal_R0VW13LDU,&var125};
_S_scalzz far S_scalzz_144_1 = {&signal_B0IT02IZ2,&iRM_819_,&iRM_4095_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var126,&internal1_m144_y0};
_S_scalzz far S_scalzz_142_1 = {&signal_A0IT02IZ2,&iRM_819_,&iRM_4095_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var127,&internal1_m142_y0};
_S_geterr far S_geterr_146_1 = {&var127,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var128};
_S_scalzz far S_scalzz_94_1 = {&signal_B2IP01IZ2,&iRM_819_,&iRM_4095_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var129,&internal1_m94_y0};
_S_scalzz far S_scalzz_92_1 = {&signal_A2IP01IZ2,&iRM_819_,&iRM_4095_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var130,&internal1_m92_y0};
_S_drg far S_drg_155_1 = {&var126,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var131,&internal1_m155_y1};
_S_drg far S_drg_166_1 = {&var126,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var132,&internal1_m166_y1};
_S_geterr far S_geterr_148_1 = {&var126,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var133};
_S_noto far S_noto_135_1 = {&var160,&var134};
_S_noto far S_noto_126_1 = {&var165,&var135};
_S_noto far S_noto_96_1 = {&signal_A1VP81LZZ,&var136};
_S_srm far S_srm_331_1 = {array_m331_x_1,array_m331_diag_1,&iRM_4_,&iRM_3_,&var137,&vainSBool};
_S_rsu far S_rsu_309_1 = {&signal_R0MD34LP1,&var139,&var138,&internal1_m309_q0};
_S_orni far S_orni_311_1 = {array_m311_x_1,&iRM_17_,&vainSBool,&var139};
_S_orn far S_orn_16_1 = {array_m16_x_1,&iRM_6_,&var140};
_S_orn far S_orn_36_1 = {array_m36_x_1,&iRM_6_,&var141};
_S_noto far S_noto_7_1 = {&var153,&var142};
_S_noto far S_noto_288_1 = {&var49,&var143};
_S_noto far S_noto_283_1 = {&var62,&var144};
_S_noto far S_noto_272_1 = {&signal_A1EE01LS4,&var145};
_S_noto far S_noto_276_1 = {&signal_A1EE01LS2,&var146};
_S_noto far S_noto_275_1 = {&signal_A1EE01LS3,&var147};
_S_noto far S_noto_270_1 = {&signal_A1EE01LS1,&var148};
_S_react far S_react_171_1 = {&var152,&var149};
_S_bol far S_bol_176_1 = {&fEM_R0UR04RZZ,&var152,&var150};
_S_bol far S_bol_174_1 = {&fEM_R0UR01RZZ,&var152,&var151};
_S_srm far S_srm_2_1 = {array_m2_x_1,array_m2_diag_1,&iRM_4_,&iRM_3_,&var152,&var153};
_S_ornc far S_ornc_3_1 = {array_m3_x_1,&iRM_3_,&var154,&var155};
_S_ornc far S_ornc_12_1 = {array_m12_x_1,&iRM_3_,&var156,&var157};
_S_tprg far S_tprg_130_1 = {&var129,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var158,&internal1_m130_y0};
_S_tprg far S_tprg_124_1 = {&var130,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var159,&internal1_m124_y0};
_S_geterr far S_geterr_103_1 = {&var129,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var160};
_S_drg far S_drg_107_1 = {&var129,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var161,&internal1_m107_y1};
_S_drg far S_drg_118_1 = {&var129,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var162,&internal1_m118_y1};
_S_drg far S_drg_98_1 = {&var130,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var163,&internal1_m98_y1};
_S_drg far S_drg_105_1 = {&var130,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var164,&internal1_m105_y1};
_S_geterr far S_geterr_100_1 = {&var130,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var165};
_S_drg far S_drg_154_1 = {&var127,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var166,&internal1_m154_y1};
_S_drg far S_drg_163_1 = {&var127,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var167,&internal1_m163_y1};

