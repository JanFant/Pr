#ifndef RPUSIGN_H
#define RPUSIGN_H
// Подсистема RPUsign:RPUsign
static char SimulOn=1;
static short CodeSub=18;
static char SimulIP[]="192.168.10.247\0";
static int SimulPort=5555;
static int StepCycle=5;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 176
static char BUFFER[176];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.31\0", 5432, "192.168.10.131\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0IN01RRP	 BUFFER[0]	//(01_K01VCHS) Частота СНМ-11 Гц (канал 5)
#define idR0IN01RRP	 1	//(01_K01VCHS) Частота СНМ-11 Гц (канал 5)
#define R0IN02RRP	 BUFFER[5]	//(01_K02VCHS) Частота КНК15-1 Гц (канал 5)
#define idR0IN02RRP	 2	//(01_K02VCHS) Частота КНК15-1 Гц (канал 5)
#define R0IN03RRP	 BUFFER[10]	//(02_K01VCHS) Частота КНК53М Гц (канал 5)
#define idR0IN03RRP	 3	//(02_K01VCHS) Частота КНК53М Гц (канал 5)
#define RPUsign_VCHSK4	 BUFFER[15]	//(02_K02VCHS)
#define idRPUsign_VCHSK4	 4	//(02_K02VCHS)
#define R0IN06RRP	 BUFFER[20]	//(03_K01VCHS) Частота СНМ-11 Гц (канал 6)
#define idR0IN06RRP	 5	//(03_K01VCHS) Частота СНМ-11 Гц (канал 6)
#define R0IN07RRP	 BUFFER[25]	//(03_K02VCHS) Частота СНМ-11 Гц (канал 7)
#define idR0IN07RRP	 6	//(03_K02VCHS) Частота СНМ-11 Гц (канал 7)
#define A0IT03IRP	 BUFFER[30]	//(06_K01VASR) Температура АЗ1-3
#define idA0IT03IRP	 7	//(06_K01VASR) Температура АЗ1-3
#define B0IT03IRP	 BUFFER[33]	//(06_K02VASR) Температура АЗ2-3
#define idB0IT03IRP	 8	//(06_K02VASR) Температура АЗ2-3
#define s06_K03VASR	 BUFFER[36]	//(06_K03VASR)
#define ids06_K03VASR	 9	//(06_K03VASR)
#define s06_K04VASR	 BUFFER[39]	//(06_K04VASR)
#define ids06_K04VASR	 10	//(06_K04VASR)
#define s06_K05VASR	 BUFFER[42]	//(06_K05VASR)
#define ids06_K05VASR	 11	//(06_K05VASR)
#define s06_K06VASR	 BUFFER[45]	//(06_K06VASR)
#define ids06_K06VASR	 12	//(06_K06VASR)
#define s06_K07VASR	 BUFFER[48]	//(06_K07VASR)
#define ids06_K07VASR	 13	//(06_K07VASR)
#define s06_K08VASR	 BUFFER[51]	//(06_K08VASR)
#define ids06_K08VASR	 14	//(06_K08VASR)
#define R0IE14LRP	 BUFFER[54]	//(07_K01VDSR) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
#define idR0IE14LRP	 15	//(07_K01VDSR) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
#define R0IE15LRP	 BUFFER[56]	//(07_K02VDSR) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
#define idR0IE15LRP	 16	//(07_K02VDSR) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
#define R0IE11LRP	 BUFFER[58]	//(07_K03VDSR) Исправность ВИП 1,6 (№20) СНМ11 5 канала
#define idR0IE11LRP	 17	//(07_K03VDSR) Исправность ВИП 1,6 (№20) СНМ11 5 канала
#define R0IE12LRP	 BUFFER[60]	//(07_K04VDSR) Исправность ВИП 0,5 -5к (№21)
#define idR0IE12LRP	 18	//(07_K04VDSR) Исправность ВИП 0,5 -5к (№21)
#define R0IE13LRP	 BUFFER[62]	//(07_K05VDSR) Исправность ВИП 0,5 -5к (№22)
#define idR0IE13LRP	 19	//(07_K05VDSR) Исправность ВИП 0,5 -5к (№22)
#define C1MD31LRP	 BUFFER[64]	//(07_K06VDSR) Кнопка ОБЩИЙ СБРОС  на РПУ
#define idC1MD31LRP	 20	//(07_K06VDSR) Кнопка ОБЩИЙ СБРОС  на РПУ
#define C1MZ31LRP	 BUFFER[66]	//(07_K07VDSR) Кнопка ОБДУВ  на РПУ
#define idC1MZ31LRP	 21	//(07_K07VDSR) Кнопка ОБДУВ  на РПУ
#define A3IS21LRP	 BUFFER[68]	//(07_K08VDSR) Приход на НУ ИС1
#define idA3IS21LRP	 22	//(07_K08VDSR) Приход на НУ ИС1
#define B3IS21LRP	 BUFFER[70]	//(07_K09VDSR) Приход на НУ ИС2
#define idB3IS21LRP	 23	//(07_K09VDSR) Приход на НУ ИС2
#define A1IS21LRP	 BUFFER[72]	//(07_K10VDSR) Приход на НУ ББ1
#define idA1IS21LRP	 24	//(07_K10VDSR) Приход на НУ ББ1
#define B1IS21LRP	 BUFFER[74]	//(07_K11VDSR) Приход на НУ ББ2
#define idB1IS21LRP	 25	//(07_K11VDSR) Приход на НУ ББ2
#define A2IS21LRP	 BUFFER[76]	//(07_K12VDSR) Приход на НУ РБ1-CC
#define idA2IS21LRP	 26	//(07_K12VDSR) Приход на НУ РБ1-CC
#define B2IS21LRP	 BUFFER[78]	//(07_K13VDSR) Приход на НУ РБ2-CC
#define idB2IS21LRP	 27	//(07_K13VDSR) Приход на НУ РБ2-CC
#define A6IS11LRP	 BUFFER[80]	//(07_K14VDSR) Приход на ВУ БЗ1
#define idA6IS11LRP	 28	//(07_K14VDSR) Приход на ВУ БЗ1
#define B6IS11LRP	 BUFFER[82]	//(07_K15VDSR) Приход на ВУ БЗ2
#define idB6IS11LRP	 29	//(07_K15VDSR) Приход на ВУ БЗ2
#define s07_VDS32R16	 BUFFER[84]	//(07_VDS32R16)
#define ids07_VDS32R16	 30	//(07_VDS32R16)
#define s07_VDS32R17	 BUFFER[86]	//(07_VDS32R17)
#define ids07_VDS32R17	 31	//(07_VDS32R17)
#define s07_VDS32R18	 BUFFER[88]	//(07_VDS32R18)
#define ids07_VDS32R18	 32	//(07_VDS32R18)
#define s07_VDS32R19	 BUFFER[90]	//(07_VDS32R19)
#define ids07_VDS32R19	 33	//(07_VDS32R19)
#define s07_VDS32R20	 BUFFER[92]	//(07_VDS32R20)
#define ids07_VDS32R20	 34	//(07_VDS32R20)
#define s07_VDS32R21	 BUFFER[94]	//(07_VDS32R21)
#define ids07_VDS32R21	 35	//(07_VDS32R21)
#define s07_VDS32R22	 BUFFER[96]	//(07_VDS32R22)
#define ids07_VDS32R22	 36	//(07_VDS32R22)
#define s07_VDS32R23	 BUFFER[98]	//(07_VDS32R23)
#define ids07_VDS32R23	 37	//(07_VDS32R23)
#define s07_VDS32R24	 BUFFER[100]	//(07_VDS32R24)
#define ids07_VDS32R24	 38	//(07_VDS32R24)
#define s07_VDS32R25	 BUFFER[102]	//(07_VDS32R25)
#define ids07_VDS32R25	 39	//(07_VDS32R25)
#define s07_VDS32R26	 BUFFER[104]	//(07_VDS32R26)
#define ids07_VDS32R26	 40	//(07_VDS32R26)
#define s07_VDS32R27	 BUFFER[106]	//(07_VDS32R27)
#define ids07_VDS32R27	 41	//(07_VDS32R27)
#define s07_VDS32R28	 BUFFER[108]	//(07_VDS32R28)
#define ids07_VDS32R28	 42	//(07_VDS32R28)
#define s07_VDS32R29	 BUFFER[110]	//(07_VDS32R29)
#define ids07_VDS32R29	 43	//(07_VDS32R29)
#define s07_VDS32R30	 BUFFER[112]	//(07_VDS32R30)
#define ids07_VDS32R30	 44	//(07_VDS32R30)
#define s07_VDS32R31	 BUFFER[114]	//(07_VDS32R31)
#define ids07_VDS32R31	 45	//(07_VDS32R31)
#define s07_VDS32R32	 BUFFER[116]	//(07_VDS32R32)
#define ids07_VDS32R32	 46	//(07_VDS32R32)
#define A1VS21LRP	 BUFFER[118]	//(08_K01FDSR) Индикация НУ ББ1
#define idA1VS21LRP	 47	//(08_K01FDSR) Индикация НУ ББ1
#define B1VS21LRP	 BUFFER[120]	//(08_K02FDSR) Индикация НУ ББ2
#define idB1VS21LRP	 48	//(08_K02FDSR) Индикация НУ ББ2
#define A2VS21LRP	 BUFFER[122]	//(08_K03FDSR) Индикация НУ РБ1-СС
#define idA2VS21LRP	 49	//(08_K03FDSR) Индикация НУ РБ1-СС
#define B2VS21LRP	 BUFFER[124]	//(08_K04FDSR) Индикация НУ РБ2-СС
#define idB2VS21LRP	 50	//(08_K04FDSR) Индикация НУ РБ2-СС
#define A3VS21LRP	 BUFFER[126]	//(08_K05FDSR) Индикация НУ ИС1
#define idA3VS21LRP	 51	//(08_K05FDSR) Индикация НУ ИС1
#define B3VS21LRP	 BUFFER[128]	//(08_K06FDSR) Индикация НУ ИС2
#define idB3VS21LRP	 52	//(08_K06FDSR) Индикация НУ ИС2
#define R0IE02LRP	 BUFFER[130]	//(08_K07FDSR) Отключить питание ПУ, ПР 5К
#define idR0IE02LRP	 53	//(08_K07FDSR) Отключить питание ПУ, ПР 5К
#define R0IE01LRP	 BUFFER[132]	//(08_K08FDSR) Отключить питание детекторов 5К
#define idR0IE01LRP	 54	//(08_K08FDSR) Отключить питание детекторов 5К
#define R0IE03LRP	 BUFFER[134]	//(08_K09FDSR) Отключить питание детекторов 6К (БЗ-1), 7 К (БЗ-2)
#define idR0IE03LRP	 55	//(08_K09FDSR) Отключить питание детекторов 6К (БЗ-1), 7 К (БЗ-2)
#define R0IE04LRP	 BUFFER[136]	//(08_K10FDSR) Отключить питание ПУ, ПР 6К (БЗ-1), 7 К (БЗ-2)
#define idR0IE04LRP	 56	//(08_K10FDSR) Отключить питание ПУ, ПР 6К (БЗ-1), 7 К (БЗ-2)
#define A1VT71LRP	 BUFFER[138]	//(08_K11FDSR) АС по температуре (Подсветка кнопки «СБРОС» (Светодиод))
#define idA1VT71LRP	 57	//(08_K11FDSR) АС по температуре (Подсветка кнопки «СБРОС» (Светодиод))
#define R0VN71LRP	 BUFFER[140]	//(08_K12FDSR) АС по мощности канал 5 (Подсветка кнопки «ОБДУВ» (Светодиод))
#define idR0VN71LRP	 58	//(08_K12FDSR) АС по мощности канал 5 (Подсветка кнопки «ОБДУВ» (Светодиод))
#define s08_K13FDSR	 BUFFER[142]	//(08_K13FDSR)
#define ids08_K13FDSR	 59	//(08_K13FDSR)
#define s08_K14FDSR	 BUFFER[144]	//(08_K14FDSR)
#define ids08_K14FDSR	 60	//(08_K14FDSR)
#define A1VN71LRP	 BUFFER[146]	//(08_K15FDSR) Сигнал тревоги на диспетчера
#define idA1VN71LRP	 61	//(08_K15FDSR) Сигнал тревоги на диспетчера
#define s08_K16FDSR	 BUFFER[148]	//(08_K16FDSR)
#define ids08_K16FDSR	 62	//(08_K16FDSR)
#define POWER1	 BUFFER[150]	//(POWER1 )
#define idPOWER1	 63	//(POWER1 )
#define POWER2	 BUFFER[152]	//(POWER2 )
#define idPOWER2	 64	//(POWER2 )
#define DOOR	 BUFFER[154]	//(DOOR   )
#define idDOOR	 65	//(DOOR   )
#define T43	 BUFFER[156]	//(T43    )
#define idT43	 66	//(T43    )
#define T53	 BUFFER[158]	//(T53    )
#define idT53	 67	//(T53    )
#define BP124	 BUFFER[160]	//(BP124  )
#define idBP124	 68	//(BP124  )
#define BP15	 BUFFER[162]	//(BP15   )
#define idBP15	 69	//(BP15   )
#define BP224	 BUFFER[164]	//(BP224  )
#define idBP224	 70	//(BP224  )
#define BP25	 BUFFER[166]	//(BP25   )
#define idBP25	 71	//(BP25   )
#define MPBP124	 BUFFER[168]	//(MPBP124)
#define idMPBP124	 72	//(MPBP124)
#define MPBP15	 BUFFER[170]	//(MPBP15 )
#define idMPBP15	 73	//(MPBP15 )
#define MPBP224	 BUFFER[172]	//(MPBP224)
#define idMPBP224	 74	//(MPBP224)
#define MPBP25	 BUFFER[174]	//(MPBP25 )
#define idMPBP25	 75	//(MPBP25 )
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,8	,1	, &R0IN01RRP},	//(01_K01VCHS) Частота СНМ-11 Гц (канал 5)
	{ 2	,8	,1	, &R0IN02RRP},	//(01_K02VCHS) Частота КНК15-1 Гц (канал 5)
	{ 3	,8	,1	, &R0IN03RRP},	//(02_K01VCHS) Частота КНК53М Гц (канал 5)
	{ 4	,8	,1	, &RPUsign_VCHSK4},	//(02_K02VCHS)
	{ 5	,8	,1	, &R0IN06RRP},	//(03_K01VCHS) Частота СНМ-11 Гц (канал 6)
	{ 6	,8	,1	, &R0IN07RRP},	//(03_K02VCHS) Частота СНМ-11 Гц (канал 7)
	{ 7	,3	,1	, &A0IT03IRP},	//(06_K01VASR) Температура АЗ1-3
	{ 8	,3	,1	, &B0IT03IRP},	//(06_K02VASR) Температура АЗ2-3
	{ 9	,3	,1	, &s06_K03VASR},	//(06_K03VASR)
	{ 10	,3	,1	, &s06_K04VASR},	//(06_K04VASR)
	{ 11	,3	,1	, &s06_K05VASR},	//(06_K05VASR)
	{ 12	,3	,1	, &s06_K06VASR},	//(06_K06VASR)
	{ 13	,3	,1	, &s06_K07VASR},	//(06_K07VASR)
	{ 14	,3	,1	, &s06_K08VASR},	//(06_K08VASR)
	{ 15	,1	,1	, &R0IE14LRP},	//(07_K01VDSR) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
	{ 16	,1	,1	, &R0IE15LRP},	//(07_K02VDSR) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
	{ 17	,1	,1	, &R0IE11LRP},	//(07_K03VDSR) Исправность ВИП 1,6 (№20) СНМ11 5 канала
	{ 18	,1	,1	, &R0IE12LRP},	//(07_K04VDSR) Исправность ВИП 0,5 -5к (№21)
	{ 19	,1	,1	, &R0IE13LRP},	//(07_K05VDSR) Исправность ВИП 0,5 -5к (№22)
	{ 20	,1	,1	, &C1MD31LRP},	//(07_K06VDSR) Кнопка ОБЩИЙ СБРОС  на РПУ
	{ 21	,1	,1	, &C1MZ31LRP},	//(07_K07VDSR) Кнопка ОБДУВ  на РПУ
	{ 22	,1	,1	, &A3IS21LRP},	//(07_K08VDSR) Приход на НУ ИС1
	{ 23	,1	,1	, &B3IS21LRP},	//(07_K09VDSR) Приход на НУ ИС2
	{ 24	,1	,1	, &A1IS21LRP},	//(07_K10VDSR) Приход на НУ ББ1
	{ 25	,1	,1	, &B1IS21LRP},	//(07_K11VDSR) Приход на НУ ББ2
	{ 26	,1	,1	, &A2IS21LRP},	//(07_K12VDSR) Приход на НУ РБ1-CC
	{ 27	,1	,1	, &B2IS21LRP},	//(07_K13VDSR) Приход на НУ РБ2-CC
	{ 28	,1	,1	, &A6IS11LRP},	//(07_K14VDSR) Приход на ВУ БЗ1
	{ 29	,1	,1	, &B6IS11LRP},	//(07_K15VDSR) Приход на ВУ БЗ2
	{ 30	,1	,1	, &s07_VDS32R16},	//(07_VDS32R16)
	{ 31	,1	,1	, &s07_VDS32R17},	//(07_VDS32R17)
	{ 32	,1	,1	, &s07_VDS32R18},	//(07_VDS32R18)
	{ 33	,1	,1	, &s07_VDS32R19},	//(07_VDS32R19)
	{ 34	,1	,1	, &s07_VDS32R20},	//(07_VDS32R20)
	{ 35	,1	,1	, &s07_VDS32R21},	//(07_VDS32R21)
	{ 36	,1	,1	, &s07_VDS32R22},	//(07_VDS32R22)
	{ 37	,1	,1	, &s07_VDS32R23},	//(07_VDS32R23)
	{ 38	,1	,1	, &s07_VDS32R24},	//(07_VDS32R24)
	{ 39	,1	,1	, &s07_VDS32R25},	//(07_VDS32R25)
	{ 40	,1	,1	, &s07_VDS32R26},	//(07_VDS32R26)
	{ 41	,1	,1	, &s07_VDS32R27},	//(07_VDS32R27)
	{ 42	,1	,1	, &s07_VDS32R28},	//(07_VDS32R28)
	{ 43	,1	,1	, &s07_VDS32R29},	//(07_VDS32R29)
	{ 44	,1	,1	, &s07_VDS32R30},	//(07_VDS32R30)
	{ 45	,1	,1	, &s07_VDS32R31},	//(07_VDS32R31)
	{ 46	,1	,1	, &s07_VDS32R32},	//(07_VDS32R32)
	{ 47	,1	,1	, &A1VS21LRP},	//(08_K01FDSR) Индикация НУ ББ1
	{ 48	,1	,1	, &B1VS21LRP},	//(08_K02FDSR) Индикация НУ ББ2
	{ 49	,1	,1	, &A2VS21LRP},	//(08_K03FDSR) Индикация НУ РБ1-СС
	{ 50	,1	,1	, &B2VS21LRP},	//(08_K04FDSR) Индикация НУ РБ2-СС
	{ 51	,1	,1	, &A3VS21LRP},	//(08_K05FDSR) Индикация НУ ИС1
	{ 52	,1	,1	, &B3VS21LRP},	//(08_K06FDSR) Индикация НУ ИС2
	{ 53	,1	,1	, &R0IE02LRP},	//(08_K07FDSR) Отключить питание ПУ, ПР 5К
	{ 54	,1	,1	, &R0IE01LRP},	//(08_K08FDSR) Отключить питание детекторов 5К
	{ 55	,1	,1	, &R0IE03LRP},	//(08_K09FDSR) Отключить питание детекторов 6К (БЗ-1), 7 К (БЗ-2)
	{ 56	,1	,1	, &R0IE04LRP},	//(08_K10FDSR) Отключить питание ПУ, ПР 6К (БЗ-1), 7 К (БЗ-2)
	{ 57	,1	,1	, &A1VT71LRP},	//(08_K11FDSR) АС по температуре (Подсветка кнопки «СБРОС» (Светодиод))
	{ 58	,1	,1	, &R0VN71LRP},	//(08_K12FDSR) АС по мощности канал 5 (Подсветка кнопки «ОБДУВ» (Светодиод))
	{ 59	,1	,1	, &s08_K13FDSR},	//(08_K13FDSR)
	{ 60	,1	,1	, &s08_K14FDSR},	//(08_K14FDSR)
	{ 61	,1	,1	, &A1VN71LRP},	//(08_K15FDSR) Сигнал тревоги на диспетчера
	{ 62	,1	,1	, &s08_K16FDSR},	//(08_K16FDSR)
	{ 63	,1	,1	, &POWER1},	//(POWER1 )
	{ 64	,1	,1	, &POWER2},	//(POWER2 )
	{ 65	,1	,1	, &DOOR},	//(DOOR   )
	{ 66	,1	,1	, &T43},	//(T43    )
	{ 67	,1	,1	, &T53},	//(T53    )
	{ 68	,1	,1	, &BP124},	//(BP124  )
	{ 69	,1	,1	, &BP15},	//(BP15   )
	{ 70	,1	,1	, &BP224},	//(BP224  )
	{ 71	,1	,1	, &BP25},	//(BP25   )
	{ 72	,1	,1	, &MPBP124},	//(MPBP124)
	{ 73	,1	,1	, &MPBP15},	//(MPBP15 )
	{ 74	,1	,1	, &MPBP224},	//(MPBP224)
	{ 75	,1	,1	, &MPBP25},	//(MPBP25 )
	{-1,0,NULL},
};
static char NameSaveFile[]="RPUsign.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_RPUsign[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_RPUsign[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_RPUsign[]={  // 
	{&R0IN01RRP,8,0},	//(R0IN01RRP) R0IN01RRP
	{&R0IN02RRP,8,2},	//(R0IN02RRP) R0IN02RRP
	{&R0IN03RRP,8,4},	//(R0IN03RRP) R0IN03RRP
	{&RPUsign_VCHSK4,8,6},	//(RPUsign_VCHSK4) RPUsign_VCHSK4
	{&R0IN06RRP,8,8},	//(R0IN06RRP) R0IN06RRP
	{&R0IN07RRP,8,10},	//(R0IN07RRP) R0IN07RRP
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_RPUsign[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_RPUsign[0],&di_RPUsign[0],&ir_RPUsign[0],&hr_RPUsign[0],NULL,NULL,NULL,0},	 //Пустые сигналы RPUsign

	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},};
#pragma pop
#include <fp8/drivers/vchs2.h>
static char buf_VCHS01[58];	//VCHS01
static vchs_inipar ini_VCHS01={172,255,1,8,0xff,0,0x1,0x1,0,0,1000000,1000000,};
#pragma pack(push,1)
static table_drv table_VCHS01={0,0,&ini_VCHS01,buf_VCHS01,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS01[]={
	{&R0IN01RRP,8,0},
	{&R0IN02RRP,8,5},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vchs2.h>
static char buf_VCHS02[58];	//VCHS02
static vchs_inipar ini_VCHS02={172,255,1,8,0xff,0,0x1,0x1,0,0,1000000,1000000,};
#pragma pack(push,1)
static table_drv table_VCHS02={0,0,&ini_VCHS02,buf_VCHS02,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS02[]={
	{&R0IN03RRP,8,0},
	{&RPUsign_VCHSK4,8,5},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vchs2.h>
static char buf_VCHS03[58];	//VCHS03
static vchs_inipar ini_VCHS03={172,255,1,8,0xff,0,0x1,0x1,0,0,1000000,1000000,};
#pragma pack(push,1)
static table_drv table_VCHS03={0,0,&ini_VCHS03,buf_VCHS03,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS03[]={
	{&R0IN06RRP,8,0},
	{&R0IN07RRP,8,5},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vas84r.h>
static char buf_VAS84[28];	//VAS84
static vas84r_inipar ini_VAS84={172,255,1,8,0xff,0,16,};
#pragma pack(push,1)
static table_drv table_VAS84={0,0,&ini_VAS84,buf_VAS84,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VAS84[]={
	{&A0IT03IRP,3,0},
	{&B0IT03IRP,3,3},
	{&s06_K03VASR,3,6},
	{&s06_K04VASR,3,9},
	{&s06_K05VASR,3,12},
	{&s06_K06VASR,3,15},
	{&s06_K07VASR,3,18},
	{&s06_K08VASR,3,21},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS32[66];	//VDS32
static vds32r_inipar ini_VDS32={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS32={0,0,&ini_VDS32,buf_VDS32,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32[]={
	{&R0IE14LRP,1,0},
	{&R0IE15LRP,1,2},
	{&R0IE11LRP,1,4},
	{&R0IE12LRP,1,6},
	{&R0IE13LRP,1,8},
	{&C1MD31LRP,1,10},
	{&C1MZ31LRP,1,12},
	{&A3IS21LRP,1,14},
	{&B3IS21LRP,1,16},
	{&A1IS21LRP,1,18},
	{&B1IS21LRP,1,20},
	{&A2IS21LRP,1,22},
	{&B2IS21LRP,1,24},
	{&A6IS11LRP,1,26},
	{&B6IS11LRP,1,28},
	{&s07_VDS32R16,1,30},
	{&s07_VDS32R17,1,32},
	{&s07_VDS32R18,1,34},
	{&s07_VDS32R19,1,36},
	{&s07_VDS32R20,1,38},
	{&s07_VDS32R21,1,40},
	{&s07_VDS32R22,1,42},
	{&s07_VDS32R23,1,44},
	{&s07_VDS32R24,1,46},
	{&s07_VDS32R25,1,48},
	{&s07_VDS32R26,1,50},
	{&s07_VDS32R27,1,52},
	{&s07_VDS32R28,1,54},
	{&s07_VDS32R29,1,56},
	{&s07_VDS32R30,1,58},
	{&s07_VDS32R31,1,60},
	{&s07_VDS32R32,1,62},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS16[40];	//FDS16
static fds16r_inipar ini_FDS16={0x04,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS16={0,0,&ini_FDS16,buf_FDS16,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS16[]={
	{&A1VS21LRP,1,0},
	{&B1VS21LRP,1,2},
	{&A2VS21LRP,1,4},
	{&B2VS21LRP,1,6},
	{&A3VS21LRP,1,8},
	{&B3VS21LRP,1,10},
	{&R0IE02LRP,1,12},
	{&R0IE01LRP,1,14},
	{&R0IE03LRP,1,16},
	{&R0IE04LRP,1,18},
	{&A1VT71LRP,1,20},
	{&R0VN71LRP,1,22},
	{&s08_K13FDSR,1,24},
	{&s08_K14FDSR,1,26},
	{&A1VN71LRP,1,28},
	{&s08_K16FDSR,1,30},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/sbkfp7.h>
static char buf_SBKFP[26];	//SBKFP
static sbk_inipar ini_SBKFP={0xc2,0xff,8,8,};
#pragma pack(push,1)
static table_drv table_SBKFP={0,0,&ini_SBKFP,buf_SBKFP,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_SBKFP[]={
	{&POWER1,1,0},
	{&POWER2,1,2},
	{&DOOR,1,4},
	{&T43,1,6},
	{&T53,1,8},
	{&BP124,1,10},
	{&BP15,1,12},
	{&BP224,1,14},
	{&BP25,1,16},
	{&MPBP124,1,18},
	{&MPBP15,1,20},
	{&MPBP224,1,22},
	{&MPBP25,1,24},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0xc4,0x01,12,58,def_buf_VCHS01,&table_VCHS01}, //VCHS01
	{0xc4,0x02,12,58,def_buf_VCHS02,&table_VCHS02}, //VCHS02
	{0xc4,0x03,12,58,def_buf_VCHS03,&table_VCHS03}, //VCHS03
	{0xc6,0x06,7,28,def_buf_VAS84,&table_VAS84}, //VAS84
	{0xc2,0x07,15,66,def_buf_VDS32,&table_VDS32}, //VDS32
	{0x04,0x08,20,40,def_buf_FDS16,&table_FDS16}, //FDS16
	{0x01,0x20,4,26,def_buf_SBKFP,&table_SBKFP}, //SBKFP
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
}

// Р’СЃС‚Р°РІРєР° Рє VCHS
void init_dataVchs(vchs_data *vch_data) {
    int i;
    for (i = 0; i < 2; i++) {
        vch_data->takt[i] = 0.5;
        vch_data->cykl[i] = 0.5;
        vch_data->cyklS[i] = 0.5;
        vch_data->perm[i] = 0;
        vch_data->fvch[i] = 0;
        vch_data->tempI[i] = 0;
    }
}

void VCHS_post(vchs_data *vch_data) {
    float fslow = 0, ffast = 0, zer = 0.0;
    int i;
    for (i = 0; i < 2; i++) {
        if (vch_data->perm[i] <= 0) {
                if(vch_data->SVCHS[i] == 1){
                    if( vch_data->cyklS[i] == 10)
                        vch_data->cyklS[i] = 1.0;
                    else
                        vch_data->cyklS[i] = 0.01;
                    vch_data->SVCHS[i] = 0;
                    vch_data->takt[i] = 0;                    
                    vch_data->cykl[i] = vch_data->cyklS[i]; 
                    continue;
                }    
                ffast = vch_data->tempI[i] / vch_data->takt[i];
                vch_data->fvch[i] = ffast;
                vch_data->takt[i] = 0;
                if(ffast < 1.0 )
                    vch_data->cyklS[i] = 10;
                    else   
                    vch_data->cyklS[i] = 1 / ((ffast / 64000) + 1);

                vch_data->cykl[i] = vch_data->cyklS[i]; 
        }
    }
    for (i = 0; i < 2; i++)
        if (fpcomp(&vch_data->cykl[i], &zer) > 0) {
            vch_data->takt[i] += takt;
            vch_data->cykl[i] -= takt;
            vch_data->perm[i] = fpcomp(&vch_data->cykl[i], &zer);
        }
    vch_data->K01VCHS.f = vch_data->fvch[0];
    vch_data->K02VCHS.f = vch_data->fvch[1];

}

void Scheme(void)
{
}
#endif
