#ifndef DUSIGN_H
#define DUSIGN_H
// Подсистема DUsign:DUsign
static char SimulOn=0;
static short CodeSub=11;
static char SimulIP[]="192.168.10.247\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 632
static char BUFFER[632];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.50\0", 5432, "192.168.10.150\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0IC00LDU	 BUFFER[0]	//(01_K01VDSR)- +Di0
#define idR0IC00LDU	 1	//(01_K01VDSR)- +Di0
#define R0IC01LDU	 BUFFER[2]	//(01_K02VDSR)- +Di1
#define idR0IC01LDU	 2	//(01_K02VDSR)- +Di1
#define R0IC02LDU	 BUFFER[4]	//(01_K03VDSR)- +Di2
#define idR0IC02LDU	 3	//(01_K03VDSR)- +Di2
#define R0IC03LDU	 BUFFER[6]	//(01_K04VDSR)- +Di3
#define idR0IC03LDU	 4	//(01_K04VDSR)- +Di3
#define R0IC04LDU	 BUFFER[8]	//(01_K05VDSR)- +Di4
#define idR0IC04LDU	 5	//(01_K05VDSR)- +Di4
#define R0IC05LDU	 BUFFER[10]	//(01_K06VDSR)- +Di5
#define idR0IC05LDU	 6	//(01_K06VDSR)- +Di5
#define R0IC06LDU	 BUFFER[12]	//(01_K07VDSR)- +Di6
#define idR0IC06LDU	 7	//(01_K07VDSR)- +Di6
#define R0IC07LDU	 BUFFER[14]	//(01_K08VDSR)- +Di7
#define idR0IC07LDU	 8	//(01_K08VDSR)- +Di7
#define R0IC08LDU	 BUFFER[16]	//(01_K09VDSR)- +Di8
#define idR0IC08LDU	 9	//(01_K09VDSR)- +Di8
#define R0IC09LDU	 BUFFER[18]	//(01_K10VDSR)- +Di9
#define idR0IC09LDU	 10	//(01_K10VDSR)- +Di9
#define R0IC10LDU	 BUFFER[20]	//(01_K11VDSR)- +Di10
#define idR0IC10LDU	 11	//(01_K11VDSR)- +Di10
#define R0IC11LDU	 BUFFER[22]	//(01_K12VDSR)- +Di11
#define idR0IC11LDU	 12	//(01_K12VDSR)- +Di11
#define R0IC12LDU	 BUFFER[24]	//(01_K13VDSR)- +Di12
#define idR0IC12LDU	 13	//(01_K13VDSR)- +Di12
#define R0IC13LDU	 BUFFER[26]	//(01_K14VDSR)- +Di13
#define idR0IC13LDU	 14	//(01_K14VDSR)- +Di13
#define R0IC14LDU	 BUFFER[28]	//(01_K15VDSR)- +Di14
#define idR0IC14LDU	 15	//(01_K15VDSR)- +Di14
#define R0IC15LDU	 BUFFER[30]	//(01_K16VDSR)- +Di15
#define idR0IC15LDU	 16	//(01_K16VDSR)- +Di15
#define R0IC16LDU	 BUFFER[32]	//(01_K17VDSR)- +Di16
#define idR0IC16LDU	 17	//(01_K17VDSR)- +Di16
#define R0IC17LDU	 BUFFER[34]	//(01_K18VDSR)- +Di17
#define idR0IC17LDU	 18	//(01_K18VDSR)- +Di17
#define R0IC18LDU	 BUFFER[36]	//(01_K19VDSR)- +Di18
#define idR0IC18LDU	 19	//(01_K19VDSR)- +Di18
#define R0IC19LDU	 BUFFER[38]	//(01_K20VDSR)- +Di19
#define idR0IC19LDU	 20	//(01_K20VDSR)- +Di19
#define R0IC20LDU	 BUFFER[40]	//(01_K21VDSR)- +Di20
#define idR0IC20LDU	 21	//(01_K21VDSR)- +Di20
#define R0IC21LDU	 BUFFER[42]	//(01_K22VDSR)- +Di21
#define idR0IC21LDU	 22	//(01_K22VDSR)- +Di21
#define R0IC22LDU	 BUFFER[44]	//(01_K23VDSR)- +Di22
#define idR0IC22LDU	 23	//(01_K23VDSR)- +Di22
#define R0IC23LDU	 BUFFER[46]	//(01_K24VDSR)- +Di23
#define idR0IC23LDU	 24	//(01_K24VDSR)- +Di23
#define R0IC24LDU	 BUFFER[48]	//(01_K25VDSR)- +Di24
#define idR0IC24LDU	 25	//(01_K25VDSR)- +Di24
#define R0IC25LDU	 BUFFER[50]	//(01_K26VDSR)- +Di25
#define idR0IC25LDU	 26	//(01_K26VDSR)- +Di25
#define R0IC26LDU	 BUFFER[52]	//(01_K27VDSR)- +Di26
#define idR0IC26LDU	 27	//(01_K27VDSR)- +Di26
#define R0IC27LDU	 BUFFER[54]	//(01_K28VDSR)- +Di27
#define idR0IC27LDU	 28	//(01_K28VDSR)- +Di27
#define R0IC28LDU	 BUFFER[56]	//(01_K29VDSR)- +Di28
#define idR0IC28LDU	 29	//(01_K29VDSR)- +Di28
#define R0IC29LDU	 BUFFER[58]	//(01_K30VDSR)- +Di29
#define idR0IC29LDU	 30	//(01_K30VDSR)- +Di29
#define R0IC30LDU	 BUFFER[60]	//(01_K31VDSR)- +Di30
#define idR0IC30LDU	 31	//(01_K31VDSR)- +Di30
#define R0IC31LDU	 BUFFER[62]	//(01_K32VDSR)- +Di31
#define idR0IC31LDU	 32	//(01_K32VDSR)- +Di31
#define B3IS35LDU	 BUFFER[64]	//(02_K01VDSR)- Клапан «ВПИС2» открыт (обесточен)
#define idB3IS35LDU	 33	//(02_K01VDSR)- Клапан «ВПИС2» открыт (обесточен)
#define B3IS33LDU	 BUFFER[66]	//(02_K02VDSR)- Клапан «ВЫСТРЕЛ ИС2» открыт (обесточен)
#define idB3IS33LDU	 34	//(02_K02VDSR)- Клапан «ВЫСТРЕЛ ИС2» открыт (обесточен)
#define B2IS33LDU	 BUFFER[68]	//(02_K03VDSR)- Клапан «Подъём РБ2» открыт (обесточен)
#define idB2IS33LDU	 35	//(02_K03VDSR)- Клапан «Подъём РБ2» открыт (обесточен)
#define B4IS10LDU	 BUFFER[70]	//(02_K04VDSR)- Клапан «Подъём НИ2» открыт (обесточен)
#define idB4IS10LDU	 36	//(02_K04VDSR)- Клапан «Подъём НИ2» открыт (обесточен)
#define B3IS31LDU	 BUFFER[72]	//(02_K05VDSR)- Клапан «СПУСК ИС2» открыт (обесточен)
#define idB3IS31LDU	 37	//(02_K05VDSR)- Клапан «СПУСК ИС2» открыт (обесточен)
#define B7AS31LDU	 BUFFER[74]	//(02_K06VDSR)- Клапан «Обдув АЗ2» открыт (обесточен)
#define idB7AS31LDU	 38	//(02_K06VDSR)- Клапан «Обдув АЗ2» открыт (обесточен)
#define B1IS12LDU	 BUFFER[76]	//(02_K07VDSR)- Магнит ББ2 зацеплен
#define idB1IS12LDU	 39	//(02_K07VDSR)- Магнит ББ2 зацеплен
#define B1IS11LDU	 BUFFER[78]	//(02_K08VDSR)- Приход на ВУ ББ2
#define idB1IS11LDU	 40	//(02_K08VDSR)- Приход на ВУ ББ2
#define B1IS21LDU	 BUFFER[80]	//(02_K09VDSR)- Приход на НУ ББ2
#define idB1IS21LDU	 41	//(02_K09VDSR)- Приход на НУ ББ2
#define B2IS12LDU	 BUFFER[82]	//(02_K10VDSR)- Магнит РБ2 зацеплен
#define idB2IS12LDU	 42	//(02_K10VDSR)- Магнит РБ2 зацеплен
#define B2IS11LDU	 BUFFER[84]	//(02_K11VDSR)- Приход на ВУ РБ2-СТР
#define idB2IS11LDU	 43	//(02_K11VDSR)- Приход на ВУ РБ2-СТР
#define B2IS21LDU	 BUFFER[86]	//(02_K12VDSR)- Приход на НУ РБ2-СС
#define idB2IS21LDU	 44	//(02_K12VDSR)- Приход на НУ РБ2-СС
#define B3IS21LDU	 BUFFER[88]	//(02_K13VDSR)- Приход на НУ ИС2
#define idB3IS21LDU	 45	//(02_K13VDSR)- Приход на НУ ИС2
#define R8IS11LDU	 BUFFER[90]	//(02_K14VDSR)- Аварийный НИ установлен
#define idR8IS11LDU	 46	//(02_K14VDSR)- Аварийный НИ установлен
#define B8IS12LDU	 BUFFER[92]	//(02_K15VDSR)- Приход на механический ВУ АЗ2
#define idB8IS12LDU	 47	//(02_K15VDSR)- Приход на механический ВУ АЗ2
#define B8IS22LDU	 BUFFER[94]	//(02_K16VDSR)- Приход на механический НУ АЗ2
#define idB8IS22LDU	 48	//(02_K16VDSR)- Приход на механический НУ АЗ2
#define s02_K17VDSR	 BUFFER[96]	//(02_K17VDSR)- 
#define ids02_K17VDSR	 49	//(02_K17VDSR)- 
#define A3VZ13LZ1	 BUFFER[98]	//(02_K18VDSR)- Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ1	 50	//(02_K18VDSR)- Имитация срабатывания АЗ от ВУ ИС
#define A3VZ15LZ1	 BUFFER[100]	//(02_K19VDSR)- Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ1	 51	//(02_K19VDSR)- Имитация срабатывания АЗ от НУП ИС
#define R0AD14LZ1	 BUFFER[102]	//(02_K20VDSR)- Имитация срабатывания АЗ от II УР
#define idR0AD14LZ1	 52	//(02_K20VDSR)- Имитация срабатывания АЗ от II УР
#define A1VN71LZ1	 BUFFER[104]	//(02_K21VDSR)- Блокировка автоматического подъёма ББ
#define idA1VN71LZ1	 53	//(02_K21VDSR)- Блокировка автоматического подъёма ББ
#define R0VZ71LZ1	 BUFFER[106]	//(02_K22VDSR)- Обобщенный сигнал АЗ 1канала
#define idR0VZ71LZ1	 54	//(02_K22VDSR)- Обобщенный сигнал АЗ 1канала
#define A9IS11LDU	 BUFFER[108]	//(02_K23VDSR)- Приход на ВУ НИ ДС1
#define idA9IS11LDU	 55	//(02_K23VDSR)- Приход на ВУ НИ ДС1
#define A9IS21LDU	 BUFFER[110]	//(02_K24VDSR)- Приход на НУ НИ ДС1
#define idA9IS21LDU	 56	//(02_K24VDSR)- Приход на НУ НИ ДС1
#define B9IS11LDU	 BUFFER[112]	//(02_K25VDSR)- Приход на ВУ НИ ДС2
#define idB9IS11LDU	 57	//(02_K25VDSR)- Приход на ВУ НИ ДС2
#define B9IS21LDU	 BUFFER[114]	//(02_K26VDSR)- Приход на НУ НИ ДС2
#define idB9IS21LDU	 58	//(02_K26VDSR)- Приход на НУ НИ ДС2
#define R1IS11LDU	 BUFFER[116]	//(02_K27VDSR)- Приход на ВУ МДЗ1
#define idR1IS11LDU	 59	//(02_K27VDSR)- Приход на ВУ МДЗ1
#define R1IS21LDU	 BUFFER[118]	//(02_K28VDSR)- Приход на НУ МДЗ1
#define idR1IS21LDU	 60	//(02_K28VDSR)- Приход на НУ МДЗ1
#define R2IS11LDU	 BUFFER[120]	//(02_K29VDSR)- Приход на ВУ МДЗ2
#define idR2IS11LDU	 61	//(02_K29VDSR)- Приход на ВУ МДЗ2
#define R2IS21LDU	 BUFFER[122]	//(02_K30VDSR)- Приход на НУ МДЗ2
#define idR2IS21LDU	 62	//(02_K30VDSR)- Приход на НУ МДЗ2
#define B4IS11LDU	 BUFFER[124]	//(02_K31VDSR)- Приход на ВУ НИ2
#define idB4IS11LDU	 63	//(02_K31VDSR)- Приход на ВУ НИ2
#define B4IS21LDU	 BUFFER[126]	//(02_K32VDSR)- Приход на НУ НИ2
#define idB4IS21LDU	 64	//(02_K32VDSR)- Приход на НУ НИ2
#define A3IS35LDU	 BUFFER[128]	//(03_K01VDSR)- Клапан «ВПИС1» открыт (обесточен)
#define idA3IS35LDU	 65	//(03_K01VDSR)- Клапан «ВПИС1» открыт (обесточен)
#define A3IS33LDU	 BUFFER[130]	//(03_K02VDSR)- Клапан «ВЫСТРЕЛ ИС1» открыт (обесточен)
#define idA3IS33LDU	 66	//(03_K02VDSR)- Клапан «ВЫСТРЕЛ ИС1» открыт (обесточен)
#define A2IS33LDU	 BUFFER[132]	//(03_K03VDSR)- Клапан «Подъём РБ1» открыт (обесточен)
#define idA2IS33LDU	 67	//(03_K03VDSR)- Клапан «Подъём РБ1» открыт (обесточен)
#define A4IS10LDU	 BUFFER[134]	//(03_K04VDSR)- Клапан «Подъём НИ1» открыт (обесточен)
#define idA4IS10LDU	 68	//(03_K04VDSR)- Клапан «Подъём НИ1» открыт (обесточен)
#define A3IS31LDU	 BUFFER[136]	//(03_K05VDSR)- Клапан «СПУСК ИС1» открыт (обесточен)
#define idA3IS31LDU	 69	//(03_K05VDSR)- Клапан «СПУСК ИС1» открыт (обесточен)
#define A7AS31LDU	 BUFFER[138]	//(03_K06VDSR)- Клапан «Обдув АЗ1» открыт (обесточен)
#define idA7AS31LDU	 70	//(03_K06VDSR)- Клапан «Обдув АЗ1» открыт (обесточен)
#define A1IS12LDU	 BUFFER[140]	//(03_K07VDSR)- Магнит ББ1 зацеплен
#define idA1IS12LDU	 71	//(03_K07VDSR)- Магнит ББ1 зацеплен
#define A1IS11LDU	 BUFFER[142]	//(03_K08VDSR)- Приход на ВУ ББ1
#define idA1IS11LDU	 72	//(03_K08VDSR)- Приход на ВУ ББ1
#define A1IS21LDU	 BUFFER[144]	//(03_K09VDSR)- Приход на НУ ББ1
#define idA1IS21LDU	 73	//(03_K09VDSR)- Приход на НУ ББ1
#define A2IS12LDU	 BUFFER[146]	//(03_K10VDSR)- Магнит РБ1 зацеплен
#define idA2IS12LDU	 74	//(03_K10VDSR)- Магнит РБ1 зацеплен
#define A2IS11LDU	 BUFFER[148]	//(03_K11VDSR)- Приход на ВУ РБ1-СТР
#define idA2IS11LDU	 75	//(03_K11VDSR)- Приход на ВУ РБ1-СТР
#define A2IS21LDU	 BUFFER[150]	//(03_K12VDSR)- Приход на НУ РБ1-СС
#define idA2IS21LDU	 76	//(03_K12VDSR)- Приход на НУ РБ1-СС
#define A3IS21LDU	 BUFFER[152]	//(03_K13VDSR)- Приход на НУ ИС1
#define idA3IS21LDU	 77	//(03_K13VDSR)- Приход на НУ ИС1
#define A4IS11LDU	 BUFFER[154]	//(03_K14VDSR)- Приход на ВУ НИ1
#define idA4IS11LDU	 78	//(03_K14VDSR)- Приход на ВУ НИ1
#define A4IS21LDU	 BUFFER[156]	//(03_K15VDSR)- Приход на НУ НИ1
#define idA4IS21LDU	 79	//(03_K15VDSR)- Приход на НУ НИ1
#define s03_K16VDSR	 BUFFER[158]	//(03_K16VDSR)-
#define ids03_K16VDSR	 80	//(03_K16VDSR)-
#define s03_K17VDSR	 BUFFER[160]	//(03_K17VDSR)-
#define ids03_K17VDSR	 81	//(03_K17VDSR)-
#define A3VZ13LZ2	 BUFFER[162]	//(03_K18VDSR)- Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ2	 82	//(03_K18VDSR)- Имитация срабатывания АЗ от ВУ ИС
#define A3VZ15LZ2	 BUFFER[164]	//(03_K19VDSR)- Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ2	 83	//(03_K19VDSR)- Имитация срабатывания АЗ от НУП ИС
#define R0AD14LZ2	 BUFFER[166]	//(03_K20VDSR)- Имитация срабатывания АЗ от  II УР
#define idR0AD14LZ2	 84	//(03_K20VDSR)- Имитация срабатывания АЗ от  II УР
#define A1VN71LZ2	 BUFFER[168]	//(03_K21VDSR)- Блокировка автоматического подъёма ББ
#define idA1VN71LZ2	 85	//(03_K21VDSR)- Блокировка автоматического подъёма ББ
#define R0VZ71LZ2	 BUFFER[170]	//(03_K22VDSR)- Обобщенный сигнал АЗ 2 канала
#define idR0VZ71LZ2	 86	//(03_K22VDSR)- Обобщенный сигнал АЗ 2 канала
#define A3VP81LDU	 BUFFER[172]	//(03_K23VDSR)- Давление СПУСК ИС1 в норме
#define idA3VP81LDU	 87	//(03_K23VDSR)- Давление СПУСК ИС1 в норме
#define A2VP82LDU	 BUFFER[174]	//(03_K24VDSR)- Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	 88	//(03_K24VDSR)- Давление ПОДЪЁМ РБ1 в норме
#define A4VP82LDU	 BUFFER[176]	//(03_K25VDSR)- Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	 89	//(03_K25VDSR)- Давление ПОДЪЁМ НИ1 в норме
#define B3VP81LDU	 BUFFER[178]	//(03_K26VDSR)- Давление СПУСК ИС2 в норме
#define idB3VP81LDU	 90	//(03_K26VDSR)- Давление СПУСК ИС2 в норме
#define B2VP82LDU	 BUFFER[180]	//(03_K27VDSR)- Давление ПОДЪЁМ РБ2 в норме
#define idB2VP82LDU	 91	//(03_K27VDSR)- Давление ПОДЪЁМ РБ2 в норме
#define B4VP82LDU	 BUFFER[182]	//(03_K28VDSR)- Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	 92	//(03_K28VDSR)- Давление ПОДЪЁМ НИ2 в норме
#define R0IS01LDU	 BUFFER[184]	//(03_K29VDSR)- Признак работы с имитатором
#define idR0IS01LDU	 93	//(03_K29VDSR)- Признак работы с имитатором
#define R0IS02LDU	 BUFFER[186]	//(03_K30VDSR)- Разрешение ввода от имитатора
#define idR0IS02LDU	 94	//(03_K30VDSR)- Разрешение ввода от имитатора
#define s03_K31VDSR	 BUFFER[188]	//(03_K31VDSR)-
#define ids03_K31VDSR	 95	//(03_K31VDSR)-
#define s03_K32VDSR	 BUFFER[190]	//(03_K32VDSR)-
#define ids03_K32VDSR	 96	//(03_K32VDSR)-
#define A3IS11LDU	 BUFFER[192]	//(04_K01VDSR)- Приход на ВУ ИС1
#define idA3IS11LDU	 97	//(04_K01VDSR)- Приход на ВУ ИС1
#define A3IS22LDU	 BUFFER[194]	//(04_K02VDSR)- Приход на НУП ИС1
#define idA3IS22LDU	 98	//(04_K02VDSR)- Приход на НУП ИС1
#define B3IS11LDU	 BUFFER[196]	//(04_K03VDSR)- Приход на ВУ ИС2
#define idB3IS11LDU	 99	//(04_K03VDSR)- Приход на ВУ ИС2
#define B3IS22LDU	 BUFFER[198]	//(04_K04VDSR)- Приход на НУП ИС2
#define idB3IS22LDU	 100	//(04_K04VDSR)- Приход на НУП ИС2
#define R4IS11LDU	 BUFFER[200]	//(04_K05VDSR)- Приход на ВУ тележки
#define idR4IS11LDU	 101	//(04_K05VDSR)- Приход на ВУ тележки
#define R4IS12LDU	 BUFFER[202]	//(04_K06VDSR)- Приход на механический ВУ тележки
#define idR4IS12LDU	 102	//(04_K06VDSR)- Приход на механический ВУ тележки
#define R4IS21LDU	 BUFFER[204]	//(04_K07VDSR)- Приход на НУ тележки
#define idR4IS21LDU	 103	//(04_K07VDSR)- Приход на НУ тележки
#define R4IS22LDU	 BUFFER[206]	//(04_K08VDSR)- Приход на механический НУ тележки
#define idR4IS22LDU	 104	//(04_K08VDSR)- Приход на механический НУ тележки
#define A6IS11LDU	 BUFFER[208]	//(04_K09VDSR)- Приход на ВУ БЗ1
#define idA6IS11LDU	 105	//(04_K09VDSR)- Приход на ВУ БЗ1
#define A6IS21LDU	 BUFFER[210]	//(04_K10VDSR)- Приход на НУ БЗ1
#define idA6IS21LDU	 106	//(04_K10VDSR)- Приход на НУ БЗ1
#define A5IS11LDU	 BUFFER[212]	//(04_K11VDSR)- Приход на ВУ НЛ1
#define idA5IS11LDU	 107	//(04_K11VDSR)- Приход на ВУ НЛ1
#define A5IS21LDU	 BUFFER[214]	//(04_K12VDSR)- Приход на НУ НЛ1
#define idA5IS21LDU	 108	//(04_K12VDSR)- Приход на НУ НЛ1
#define B6IS11LDU	 BUFFER[216]	//(04_K13VDSR)- Приход на ВУ БЗ2
#define idB6IS11LDU	 109	//(04_K13VDSR)- Приход на ВУ БЗ2
#define B6IS21LDU	 BUFFER[218]	//(04_K14VDSR)- Приход на НУ БЗ2
#define idB6IS21LDU	 110	//(04_K14VDSR)- Приход на НУ БЗ2
#define B5IS11LDU	 BUFFER[220]	//(04_K15VDSR)- Приход на ВУ НЛ2
#define idB5IS11LDU	 111	//(04_K15VDSR)- Приход на ВУ НЛ2
#define B5IS21LDU	 BUFFER[222]	//(04_K16VDSR)- Приход на НУ НЛ2
#define idB5IS21LDU	 112	//(04_K16VDSR)- Приход на НУ НЛ2
#define R3IS11LDU	 BUFFER[224]	//(04_K17VDSR)- Приход на ВУ гомогенных дверей-1
#define idR3IS11LDU	 113	//(04_K17VDSR)- Приход на ВУ гомогенных дверей-1
#define R3IS21LDU	 BUFFER[226]	//(04_K18VDSR)- Приход на НУ гомогенных дверей-1
#define idR3IS21LDU	 114	//(04_K18VDSR)- Приход на НУ гомогенных дверей-1
#define R3IS31LDU	 BUFFER[228]	//(04_K19VDSR)- Приход на ВУ гомогенных дверей-2
#define idR3IS31LDU	 115	//(04_K19VDSR)- Приход на ВУ гомогенных дверей-2
#define R3IS41LDU	 BUFFER[230]	//(04_K20VDSR)- Приход на НУ гомогенных дверей-2
#define idR3IS41LDU	 116	//(04_K20VDSR)- Приход на НУ гомогенных дверей-2
#define R3AD10LDU	 BUFFER[232]	//(04_K21VDSR)- Гомогенные двери-1 открыть
#define idR3AD10LDU	 117	//(04_K21VDSR)- Гомогенные двери-1 открыть
#define R3AD11LDU	 BUFFER[234]	//(04_K22VDSR)- Гомогенные двери-2 открыть
#define idR3AD11LDU	 118	//(04_K22VDSR)- Гомогенные двери-2 открыть
#define R3AD20LDU	 BUFFER[236]	//(04_K23VDSR)- Гомогенные двери-1 закрыть
#define idR3AD20LDU	 119	//(04_K23VDSR)- Гомогенные двери-1 закрыть
#define R3AD21LDU	 BUFFER[238]	//(04_K24VDSR)- Гомогенные двери-2 закрыть
#define idR3AD21LDU	 120	//(04_K24VDSR)- Гомогенные двери-2 закрыть
#define R5IS11LDU	 BUFFER[240]	//(04_K25VDSR)- Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	 121	//(04_K25VDSR)- Приход на ВУ ворот отстойной зоны
#define R5IS21LDU	 BUFFER[242]	//(04_K26VDSR)- Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	 122	//(04_K26VDSR)- Приход на НУ ворот отстойной зоны
#define R5AD10LDU	 BUFFER[244]	//(04_K27VDSR)- Открыть ворота отстойной зоны
#define idR5AD10LDU	 123	//(04_K27VDSR)- Открыть ворота отстойной зоны
#define R5AD20LDU	 BUFFER[246]	//(04_K28VDSR)- Закрыть ворота отстойной зоны
#define idR5AD20LDU	 124	//(04_K28VDSR)- Закрыть ворота отстойной зоны
#define R6IS21LDU	 BUFFER[248]	//(04_K29VDSR)- Кран-балка в нерабочем положении
#define idR6IS21LDU	 125	//(04_K29VDSR)- Кран-балка в нерабочем положении
#define A8IS12LDU	 BUFFER[250]	//(04_K30VDSR)- Приход на механический ВУ ДС2
#define idA8IS12LDU	 126	//(04_K30VDSR)- Приход на механический ВУ ДС2
#define A8IS22LDU	 BUFFER[252]	//(04_K31VDSR)- Приход на механический НУ ДС2
#define idA8IS22LDU	 127	//(04_K31VDSR)- Приход на механический НУ ДС2
#define s04_K32VDSR	 BUFFER[254]	//(04_K32VDSR)-
#define ids04_K32VDSR	 128	//(04_K32VDSR)-
#define A1IE02LDU	 BUFFER[256]	//(05_K01VDSR)- Исправность ИП ББ1
#define idA1IE02LDU	 129	//(05_K01VDSR)- Исправность ИП ББ1
#define A1IE01LDU	 BUFFER[258]	//(05_K02VDSR)- Исправность БУШД ББ1
#define idA1IE01LDU	 130	//(05_K02VDSR)- Исправность БУШД ББ1
#define A1IE03LDU	 BUFFER[260]	//(05_K03VDSR)- Движение ББ1 вперед (от БУШД)
#define idA1IE03LDU	 131	//(05_K03VDSR)- Движение ББ1 вперед (от БУШД)
#define A1IE04LDU	 BUFFER[262]	//(05_K04VDSR)- Движение ББ1 назад (от БУШД)
#define idA1IE04LDU	 132	//(05_K04VDSR)- Движение ББ1 назад (от БУШД)
#define A2IE02LDU	 BUFFER[264]	//(05_K05VDSR)- Исправность ИП РБ1
#define idA2IE02LDU	 133	//(05_K05VDSR)- Исправность ИП РБ1
#define A2IE01LDU	 BUFFER[266]	//(05_K06VDSR)- Исправность БУШД РБ1
#define idA2IE01LDU	 134	//(05_K06VDSR)- Исправность БУШД РБ1
#define A2IE03LDU	 BUFFER[268]	//(05_K07VDSR)- Движение РБ1 вперед (от БУШД)
#define idA2IE03LDU	 135	//(05_K07VDSR)- Движение РБ1 вперед (от БУШД)
#define A2IE04LDU	 BUFFER[270]	//(05_K08VDSR)- Движение РБ1 назад (от БУШД)
#define idA2IE04LDU	 136	//(05_K08VDSR)- Движение РБ1 назад (от БУШД)
#define A3IE02LDU	 BUFFER[272]	//(05_K09VDSR)- Исправность ИП ИС1
#define idA3IE02LDU	 137	//(05_K09VDSR)- Исправность ИП ИС1
#define A3IE01LDU	 BUFFER[274]	//(05_K10VDSR)- Исправность БУШД ИС1
#define idA3IE01LDU	 138	//(05_K10VDSR)- Исправность БУШД ИС1
#define A3IE03LDU	 BUFFER[276]	//(05_K11VDSR)- Движение ИС1 вперед (от БУШД)
#define idA3IE03LDU	 139	//(05_K11VDSR)- Движение ИС1 вперед (от БУШД)
#define A3IE04LDU	 BUFFER[278]	//(05_K12VDSR)- Движение ИС1 назад (от БУШД)
#define idA3IE04LDU	 140	//(05_K12VDSR)- Движение ИС1 назад (от БУШД)
#define B1IE02LDU	 BUFFER[280]	//(05_K13VDSR)- Исправность ИП ББ2
#define idB1IE02LDU	 141	//(05_K13VDSR)- Исправность ИП ББ2
#define B1IE01LDU	 BUFFER[282]	//(05_K14VDSR)- Исправность БУШД ББ2
#define idB1IE01LDU	 142	//(05_K14VDSR)- Исправность БУШД ББ2
#define B1IE03LDU	 BUFFER[284]	//(05_K15VDSR)- Движение ББ2 вперед (от БУШД)
#define idB1IE03LDU	 143	//(05_K15VDSR)- Движение ББ2 вперед (от БУШД)
#define B1IE04LDU	 BUFFER[286]	//(05_K16VDSR)- Движение ББ2 назад (от БУШД)
#define idB1IE04LDU	 144	//(05_K16VDSR)- Движение ББ2 назад (от БУШД)
#define B2IE02LDU	 BUFFER[288]	//(05_K17VDSR)- Исправность ИП РБ2
#define idB2IE02LDU	 145	//(05_K17VDSR)- Исправность ИП РБ2
#define B2IE01LDU	 BUFFER[290]	//(05_K18VDSR)- Исправность БУШД РБ2
#define idB2IE01LDU	 146	//(05_K18VDSR)- Исправность БУШД РБ2
#define B2IE03LDU	 BUFFER[292]	//(05_K19VDSR)- Движение РБ2 вперед (от БУШД)
#define idB2IE03LDU	 147	//(05_K19VDSR)- Движение РБ2 вперед (от БУШД)
#define B2IE04LDU	 BUFFER[294]	//(05_K20VDSR)- Движение РБ2 назад (от БУШД)
#define idB2IE04LDU	 148	//(05_K20VDSR)- Движение РБ2 назад (от БУШД)
#define B3IE02LDU	 BUFFER[296]	//(05_K21VDSR)- Исправность ИП ИС2
#define idB3IE02LDU	 149	//(05_K21VDSR)- Исправность ИП ИС2
#define B3IE01LDU	 BUFFER[298]	//(05_K22VDSR)- Исправность БУШД ИС2
#define idB3IE01LDU	 150	//(05_K22VDSR)- Исправность БУШД ИС2
#define B3IE03LDU	 BUFFER[300]	//(05_K23VDSR)- Движение ИС2 вперед (от БУШД)
#define idB3IE03LDU	 151	//(05_K23VDSR)- Движение ИС2 вперед (от БУШД)
#define B3IE04LDU	 BUFFER[302]	//(05_K24VDSR)- Движение ИС2 назад (от БУШД)
#define idB3IE04LDU	 152	//(05_K24VDSR)- Движение ИС2 назад (от БУШД)
#define R6IS31LDU	 BUFFER[304]	//(05_K25VDSR)- контроль задней двери ШС
#define idR6IS31LDU	 153	//(05_K25VDSR)- контроль задней двери ШС
#define R6IS32LDU	 BUFFER[306]	//(05_K26VDSR)- контроль передней двери ШС
#define idR6IS32LDU	 154	//(05_K26VDSR)- контроль передней двери ШС
#define R6IS41LDU	 BUFFER[308]	//(05_K27VDSR)- контроль задней двери ШЭП
#define idR6IS41LDU	 155	//(05_K27VDSR)- контроль задней двери ШЭП
#define R6IS42LDU	 BUFFER[310]	//(05_K28VDSR)- контроль передней двери ШЭП
#define idR6IS42LDU	 156	//(05_K28VDSR)- контроль передней двери ШЭП
#define R6IS51LDU	 BUFFER[312]	//(05_K29VDSR)- контроль задней двери ШПУ
#define idR6IS51LDU	 157	//(05_K29VDSR)- контроль задней двери ШПУ
#define R6IS52LDU	 BUFFER[314]	//(05_K30VDSR)- контроль передней двери ШПУ
#define idR6IS52LDU	 158	//(05_K30VDSR)- контроль передней двери ШПУ
#define s05_K31VDSR	 BUFFER[316]	//(05_K31VDSR)-
#define ids05_K31VDSR	 159	//(05_K31VDSR)-
#define s05_K32VDSR	 BUFFER[318]	//(05_K32VDSR)-
#define ids05_K32VDSR	 160	//(05_K32VDSR)-
#define A1IC01LDU	 BUFFER[320]	//(06_K01FDSR)- BUS1_ББ1, у ТИБ BUS1 ББ1
#define idA1IC01LDU	 161	//(06_K01FDSR)- BUS1_ББ1, у ТИБ BUS1 ББ1
#define B1IC01LDU	 BUFFER[322]	//(06_K02FDSR)- BUS2_ББ2
#define idB1IC01LDU	 162	//(06_K02FDSR)- BUS2_ББ2
#define A2IC01LDU	 BUFFER[324]	//(06_K03FDSR)- BUS3_РБ1
#define idA2IC01LDU	 163	//(06_K03FDSR)- BUS3_РБ1
#define B2IC01LDU	 BUFFER[326]	//(06_K04FDSR)- BUS4_РБ2
#define idB2IC01LDU	 164	//(06_K04FDSR)- BUS4_РБ2
#define A3IC01LDU	 BUFFER[328]	//(06_K05FDSR)- BUS5_ИС1
#define idA3IC01LDU	 165	//(06_K05FDSR)- BUS5_ИС1
#define B3IC01LDU	 BUFFER[330]	//(06_K06FDSR)- BUS6_ИС2
#define idB3IC01LDU	 166	//(06_K06FDSR)- BUS6_ИС2
#define B8IC01LDU	 BUFFER[332]	//(06_K07FDSR)- BUS7_АЗ2
#define idB8IC01LDU	 167	//(06_K07FDSR)- BUS7_АЗ2
#define A8IC01LDU	 BUFFER[334]	//(06_K08FDSR)- BUS8_ДС2
#define idA8IC01LDU	 168	//(06_K08FDSR)- BUS8_ДС2
#define R0IC41LDU	 BUFFER[336]	//(06_K09FDSR)- LUTCH у ТИБ Latch
#define idR0IC41LDU	 169	//(06_K09FDSR)- LUTCH у ТИБ Latch
#define s06_K10FDSR	 BUFFER[338]	//(06_K10FDSR)-
#define ids06_K10FDSR	 170	//(06_K10FDSR)-
#define s06_K11FDSR	 BUFFER[340]	//(06_K11FDSR)-
#define ids06_K11FDSR	 171	//(06_K11FDSR)-
#define s06_K12FDSR	 BUFFER[342]	//(06_K12FDSR)-
#define ids06_K12FDSR	 172	//(06_K12FDSR)-
#define s06_K13FDSR	 BUFFER[344]	//(06_K13FDSR)-
#define ids06_K13FDSR	 173	//(06_K13FDSR)-
#define s06_K14FDSR	 BUFFER[346]	//(06_K14FDSR)-
#define ids06_K14FDSR	 174	//(06_K14FDSR)-
#define s06_K15FDSR	 BUFFER[348]	//(06_K15FDSR)-
#define ids06_K15FDSR	 175	//(06_K15FDSR)-
#define s06_K16FDSR	 BUFFER[350]	//(06_K16FDSR)-
#define ids06_K16FDSR	 176	//(06_K16FDSR)-
#define A2AD11LDU	 BUFFER[352]	//(07_K01FDSR)- Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	 177	//(07_K01FDSR)- Сигнал на перемещение РБ1 вверх
#define A2AD21LDU	 BUFFER[354]	//(07_K02FDSR)- Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	 178	//(07_K02FDSR)- Сигнал на перемещение РБ1 вниз
#define A2AD01LDU	 BUFFER[356]	//(07_K03FDSR)- Разрешение движения РБ1
#define idA2AD01LDU	 179	//(07_K03FDSR)- Разрешение движения РБ1
#define A2AD02LDU	 BUFFER[358]	//(07_K04FDSR)- 0-й бит скорости РБ1
#define idA2AD02LDU	 180	//(07_K04FDSR)- 0-й бит скорости РБ1
#define A2AD03LDU	 BUFFER[360]	//(07_K05FDSR)- 1-й бит скорости РБ1
#define idA2AD03LDU	 181	//(07_K05FDSR)- 1-й бит скорости РБ1
#define A2AD04LDU	 BUFFER[362]	//(07_K06FDSR)- 2-й бит скорости РБ1
#define idA2AD04LDU	 182	//(07_K06FDSR)- 2-й бит скорости РБ1
#define A2AD05LDU	 BUFFER[364]	//(07_K07FDSR)- паритет команды на РБ1
#define idA2AD05LDU	 183	//(07_K07FDSR)- паритет команды на РБ1
#define B2AD11LDU	 BUFFER[366]	//(07_K08FDSR)- Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	 184	//(07_K08FDSR)- Сигнал на перемещение РБ2 вверх
#define B2AD21LDU	 BUFFER[368]	//(07_K09FDSR)- Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	 185	//(07_K09FDSR)- Сигнал на перемещение РБ2 вниз
#define B2AD01LDU	 BUFFER[370]	//(07_K10FDSR)- Разрешение движения РБ2
#define idB2AD01LDU	 186	//(07_K10FDSR)- Разрешение движения РБ2
#define B2AD02LDU	 BUFFER[372]	//(07_K11FDSR)- 0-й бит скорости РБ2
#define idB2AD02LDU	 187	//(07_K11FDSR)- 0-й бит скорости РБ2
#define B2AD03LDU	 BUFFER[374]	//(07_K12FDSR)- 1-й бит скорости РБ2
#define idB2AD03LDU	 188	//(07_K12FDSR)- 1-й бит скорости РБ2
#define B2AD04LDU	 BUFFER[376]	//(07_K13FDSR)- 2-й бит скорости РБ2
#define idB2AD04LDU	 189	//(07_K13FDSR)- 2-й бит скорости РБ2
#define B2AD05LDU	 BUFFER[378]	//(07_K14FDSR)- паритет команды на РБ2
#define idB2AD05LDU	 190	//(07_K14FDSR)- паритет команды на РБ2
#define A2IS12LZ2	 BUFFER[380]	//(07_K15FDSR)- (сигнал не подтвержден) Магнит РБ1 зацеплен (для БАЗ2)
#define idA2IS12LZ2	 191	//(07_K15FDSR)- (сигнал не подтвержден) Магнит РБ1 зацеплен (для БАЗ2)
#define B2IS12LZ2	 BUFFER[382]	//(07_K16FDSR)- (сигнал не подтвержден) Магнит РБ2 зацеплен (для БАЗ2)
#define idB2IS12LZ2	 192	//(07_K16FDSR)- (сигнал не подтвержден) Магнит РБ2 зацеплен (для БАЗ2)
#define A1AD11LDU	 BUFFER[384]	//(08_K01FDSR)- Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	 193	//(08_K01FDSR)- Сигнал на перемещение ББ1 вверх
#define A1AD21LDU	 BUFFER[386]	//(08_K02FDSR)- Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	 194	//(08_K02FDSR)- Сигнал на перемещение ББ1 вниз
#define A1AD01LDU	 BUFFER[388]	//(08_K03FDSR)- Разрешение движения ББ1
#define idA1AD01LDU	 195	//(08_K03FDSR)- Разрешение движения ББ1
#define A1AD02LDU	 BUFFER[390]	//(08_K04FDSR)- 0-й бит скорости ББ1
#define idA1AD02LDU	 196	//(08_K04FDSR)- 0-й бит скорости ББ1
#define A1AD03LDU	 BUFFER[392]	//(08_K05FDSR)- 1-й бит скорости ББ1
#define idA1AD03LDU	 197	//(08_K05FDSR)- 1-й бит скорости ББ1
#define A1AD04LDU	 BUFFER[394]	//(08_K06FDSR)- 2-й бит скорости ББ1
#define idA1AD04LDU	 198	//(08_K06FDSR)- 2-й бит скорости ББ1
#define A1AD05LDU	 BUFFER[396]	//(08_K07FDSR)- паритет команды на ББ1
#define idA1AD05LDU	 199	//(08_K07FDSR)- паритет команды на ББ1
#define B1AD11LDU	 BUFFER[398]	//(08_K08FDSR)- Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	 200	//(08_K08FDSR)- Сигнал на перемещение ББ2 вверх
#define B1AD21LDU	 BUFFER[400]	//(08_K09FDSR)- Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	 201	//(08_K09FDSR)- Сигнал на перемещение ББ2 вниз
#define B1AD01LDU	 BUFFER[402]	//(08_K10FDSR)- Разрешение движения ББ2
#define idB1AD01LDU	 202	//(08_K10FDSR)- Разрешение движения ББ2
#define B1AD02LDU	 BUFFER[404]	//(08_K11FDSR)- 0-й бит скорости ББ2
#define idB1AD02LDU	 203	//(08_K11FDSR)- 0-й бит скорости ББ2
#define B1AD03LDU	 BUFFER[406]	//(08_K12FDSR)- 1-й бит скорости ББ2
#define idB1AD03LDU	 204	//(08_K12FDSR)- 1-й бит скорости ББ2
#define B1AD04LDU	 BUFFER[408]	//(08_K13FDSR)- 2-й бит скорости ББ2
#define idB1AD04LDU	 205	//(08_K13FDSR)- 2-й бит скорости ББ2
#define B1AD05LDU	 BUFFER[410]	//(08_K14FDSR)- паритет команды на ББ2
#define idB1AD05LDU	 206	//(08_K14FDSR)- паритет команды на ББ2
#define A2IS12LZ1	 BUFFER[412]	//(08_K15FDSR)- (сигнал не подтвержден) Магнит РБ1 зацеплен (для БАЗ1)
#define idA2IS12LZ1	 207	//(08_K15FDSR)- (сигнал не подтвержден) Магнит РБ1 зацеплен (для БАЗ1)
#define B2IS12LZ1	 BUFFER[414]	//(08_K16FDSR)- (сигнал не подтвержден) Магнит РБ2 зацеплен (для БАЗ1)
#define idB2IS12LZ1	 208	//(08_K16FDSR)- (сигнал не подтвержден) Магнит РБ2 зацеплен (для БАЗ1)
#define B3AD34LDU	 BUFFER[416]	//(09_K01FDSR)- Клапан  ВПИС ИС2   открыть (обесточить)
#define idB3AD34LDU	 209	//(09_K01FDSR)- Клапан  ВПИС ИС2   открыть (обесточить)
#define B3AD33LDU	 BUFFER[418]	//(09_K02FDSR)- Клапан «ВЫСТРЕЛ ИС2» закрыть (обесточить)
#define idB3AD33LDU	 210	//(09_K02FDSR)- Клапан «ВЫСТРЕЛ ИС2» закрыть (обесточить)
#define B2AD33LDU	 BUFFER[420]	//(09_K03FDSR)- Клапан «Подъем РБ2» открыть
#define idB2AD33LDU	 211	//(09_K03FDSR)- Клапан «Подъем РБ2» открыть
#define B4AD10LDU	 BUFFER[422]	//(09_K04FDSR)- Открыть клапан  Подъем НИ2 
#define idB4AD10LDU	 212	//(09_K04FDSR)- Открыть клапан  Подъем НИ2 
#define B3AD31LDU	 BUFFER[424]	//(09_K05FDSR)- Клапан «СПУСК ИС2» открыть (обесточить)
#define idB3AD31LDU	 213	//(09_K05FDSR)- Клапан «СПУСК ИС2» открыть (обесточить)
#define B7AP31LDU	 BUFFER[426]	//(09_K06FDSR)- Клапан «Обдув АЗ2» открыть (обесточить)
#define idB7AP31LDU	 214	//(09_K06FDSR)- Клапан «Обдув АЗ2» открыть (обесточить)
#define A8AD10LDU	 BUFFER[428]	//(09_K07FDSR)- Перемещение ДС2 вперед
#define idA8AD10LDU	 215	//(09_K07FDSR)- Перемещение ДС2 вперед
#define A8AD20LDU	 BUFFER[430]	//(09_K08FDSR)- Перемещение ДС2 назад
#define idA8AD20LDU	 216	//(09_K08FDSR)- Перемещение ДС2 назад
#define A6AD10LDU	 BUFFER[432]	//(09_K09FDSR)- Открыть БЗ1
#define idA6AD10LDU	 217	//(09_K09FDSR)- Открыть БЗ1
#define A6AD20LDU	 BUFFER[434]	//(09_K10FDSR)- Закрыть БЗ1
#define idA6AD20LDU	 218	//(09_K10FDSR)- Закрыть БЗ1
#define B6AD10LDU	 BUFFER[436]	//(09_K11FDSR)- Открыть БЗ2
#define idB6AD10LDU	 219	//(09_K11FDSR)- Открыть БЗ2
#define B6AD20LDU	 BUFFER[438]	//(09_K12FDSR)- Закрыть БЗ2
#define idB6AD20LDU	 220	//(09_K12FDSR)- Закрыть БЗ2
#define R4AD10LDU	 BUFFER[440]	//(09_K13FDSR)- Перемещение тележки вперед
#define idR4AD10LDU	 221	//(09_K13FDSR)- Перемещение тележки вперед
#define R4AD20LDU	 BUFFER[442]	//(09_K14FDSR)- Перемещение тележки назад
#define idR4AD20LDU	 222	//(09_K14FDSR)- Перемещение тележки назад
#define B8AD10LDU	 BUFFER[444]	//(09_K15FDSR)- Перемещение АЗ2 вперед
#define idB8AD10LDU	 223	//(09_K15FDSR)- Перемещение АЗ2 вперед
#define B8AD20LDU	 BUFFER[446]	//(09_K16FDSR)- Перемещение АЗ2 назад
#define idB8AD20LDU	 224	//(09_K16FDSR)- Перемещение АЗ2 назад
#define A3AD34LDU	 BUFFER[448]	//(10_K01FDSR)- Клапан  ВПИС1   открыть (обесточить)
#define idA3AD34LDU	 225	//(10_K01FDSR)- Клапан  ВПИС1   открыть (обесточить)
#define A3AD33LDU	 BUFFER[450]	//(10_K02FDSR)- Клапан «ВЫСТРЕЛ ИС1» открыть (обесточить)
#define idA3AD33LDU	 226	//(10_K02FDSR)- Клапан «ВЫСТРЕЛ ИС1» открыть (обесточить)
#define A2AD33LDU	 BUFFER[452]	//(10_K03FDSR)- Клапан «Подъем РБ1» открыть
#define idA2AD33LDU	 227	//(10_K03FDSR)- Клапан «Подъем РБ1» открыть
#define A4AD10LDU	 BUFFER[454]	//(10_K04FDSR)- Открыть клапан  Подъем НИ1 
#define idA4AD10LDU	 228	//(10_K04FDSR)- Открыть клапан  Подъем НИ1 
#define A3AD31LDU	 BUFFER[456]	//(10_K05FDSR)- Клапан «СПУСК ИС1» открыть (обесточить)
#define idA3AD31LDU	 229	//(10_K05FDSR)- Клапан «СПУСК ИС1» открыть (обесточить)
#define A7AP31LDU	 BUFFER[458]	//(10_K06FDSR)- Клапан «Обдув АЗ1» открыть (обесточить)
#define idA7AP31LDU	 230	//(10_K06FDSR)- Клапан «Обдув АЗ1» открыть (обесточить)
#define R1AD10LDU	 BUFFER[460]	//(10_K07FDSR)- Опустить МДЗ1 в зону облучения
#define idR1AD10LDU	 231	//(10_K07FDSR)- Опустить МДЗ1 в зону облучения
#define R1AD20LDU	 BUFFER[462]	//(10_K08FDSR)- Поднять МДЗ1
#define idR1AD20LDU	 232	//(10_K08FDSR)- Поднять МДЗ1
#define R2AD10LDU	 BUFFER[464]	//(10_K09FDSR)- Опустить МДЗ2 в зону облучения
#define idR2AD10LDU	 233	//(10_K09FDSR)- Опустить МДЗ2 в зону облучения
#define R2AD20LDU	 BUFFER[466]	//(10_K10FDSR)- Поднять МДЗ2
#define idR2AD20LDU	 234	//(10_K10FDSR)- Поднять МДЗ2
#define A5AD10LDU	 BUFFER[468]	//(10_K11FDSR)- Поднять НЛ1
#define idA5AD10LDU	 235	//(10_K11FDSR)- Поднять НЛ1
#define A5AD20LDU	 BUFFER[470]	//(10_K12FDSR)- Опустить НЛ1
#define idA5AD20LDU	 236	//(10_K12FDSR)- Опустить НЛ1
#define B5AD10LDU	 BUFFER[472]	//(10_K13FDSR)- Поднять НЛ2
#define idB5AD10LDU	 237	//(10_K13FDSR)- Поднять НЛ2
#define B5AD20LDU	 BUFFER[474]	//(10_K14FDSR)- Опустить НЛ2
#define idB5AD20LDU	 238	//(10_K14FDSR)- Опустить НЛ2
#define s10_K15FDSR	 BUFFER[476]	//(10_K15FDSR)-
#define ids10_K15FDSR	 239	//(10_K15FDSR)-
#define s10_K16FDSR	 BUFFER[478]	//(10_K16FDSR)-
#define ids10_K16FDSR	 240	//(10_K16FDSR)-
#define A3AD11LDU	 BUFFER[480]	//(11_K01FDSR)- Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	 241	//(11_K01FDSR)- Сигнал на перемещение ИС1 вверх
#define A3AD21LDU	 BUFFER[482]	//(11_K02FDSR)- Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	 242	//(11_K02FDSR)- Сигнал на перемещение ИС1 вниз
#define A3AD01LDU	 BUFFER[484]	//(11_K03FDSR)- Разрешение движения ИС1
#define idA3AD01LDU	 243	//(11_K03FDSR)- Разрешение движения ИС1
#define A3AD02LDU	 BUFFER[486]	//(11_K04FDSR)- 0-й бит скорости ИС1
#define idA3AD02LDU	 244	//(11_K04FDSR)- 0-й бит скорости ИС1
#define A3AD03LDU	 BUFFER[488]	//(11_K05FDSR)- 1-й бит скорости ИС1
#define idA3AD03LDU	 245	//(11_K05FDSR)- 1-й бит скорости ИС1
#define A3AD04LDU	 BUFFER[490]	//(11_K06FDSR)- 2-й бит скорости ИС1
#define idA3AD04LDU	 246	//(11_K06FDSR)- 2-й бит скорости ИС1
#define A3AD05LDU	 BUFFER[492]	//(11_K07FDSR)- паритет команды на ИС1
#define idA3AD05LDU	 247	//(11_K07FDSR)- паритет команды на ИС1
#define B3AD11LDU	 BUFFER[494]	//(11_K08FDSR)- Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	 248	//(11_K08FDSR)- Сигнал на перемещение ИС2 вверх
#define B3AD21LDU	 BUFFER[496]	//(11_K09FDSR)- Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	 249	//(11_K09FDSR)- Сигнал на перемещение ИС2 вниз
#define B3AD01LDU	 BUFFER[498]	//(11_K10FDSR)- Разрешение движения ИС2
#define idB3AD01LDU	 250	//(11_K10FDSR)- Разрешение движения ИС2
#define B3AD02LDU	 BUFFER[500]	//(11_K11FDSR)- 0-й бит скорости ИС2
#define idB3AD02LDU	 251	//(11_K11FDSR)- 0-й бит скорости ИС2
#define B3AD03LDU	 BUFFER[502]	//(11_K12FDSR)- 1-й бит скорости ИС2
#define idB3AD03LDU	 252	//(11_K12FDSR)- 1-й бит скорости ИС2
#define B3AD04LDU	 BUFFER[504]	//(11_K13FDSR)- 2-й бит скорости ИС2
#define idB3AD04LDU	 253	//(11_K13FDSR)- 2-й бит скорости ИС2
#define B3AD05LDU	 BUFFER[506]	//(11_K14FDSR)- паритет команды на ИС2
#define idB3AD05LDU	 254	//(11_K14FDSR)- паритет команды на ИС2
#define A9AD10LDU	 BUFFER[508]	//(11_K15FDSR)- Открыть клапан  Подъем НИ ДС1 
#define idA9AD10LDU	 255	//(11_K15FDSR)- Открыть клапан  Подъем НИ ДС1 
#define B9AD10LDU	 BUFFER[510]	//(11_K16FDSR)- Открыть клапан  Подъем НИ ДС2 
#define idB9AD10LDU	 256	//(11_K16FDSR)- Открыть клапан  Подъем НИ ДС2 
#define A3IP02IDU	 BUFFER[512]	//(12_K01VASR)- Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	 257	//(12_K01VASR)- Текущее давление ВЫСТРЕЛ ИС1
#define B3IP02IDU	 BUFFER[515]	//(12_K02VASR)- Текущее давление ВЫСТРЕЛ ИС2
#define idB3IP02IDU	 258	//(12_K02VASR)- Текущее давление ВЫСТРЕЛ ИС2
#define s12_K03VASR	 BUFFER[518]	//(12_K03VASR)-
#define ids12_K03VASR	 259	//(12_K03VASR)-
#define s12_K04VASR	 BUFFER[521]	//(12_K04VASR)-
#define ids12_K04VASR	 260	//(12_K04VASR)-
#define s12_K05VASR	 BUFFER[524]	//(12_K05VASR)-
#define ids12_K05VASR	 261	//(12_K05VASR)-
#define s12_K06VASR	 BUFFER[527]	//(12_K06VASR)-
#define ids12_K06VASR	 262	//(12_K06VASR)-
#define s12_K07VASR	 BUFFER[530]	//(12_K07VASR)-
#define ids12_K07VASR	 263	//(12_K07VASR)-
#define s12_K08VASR	 BUFFER[533]	//(12_K08VASR)-
#define ids12_K08VASR	 264	//(12_K08VASR)-
#define R6IS61LDU	 BUFFER[536]	//(13_K01VDSR)- Исправность 3-х  фазной сети
#define idR6IS61LDU	 265	//(13_K01VDSR)- Исправность 3-х  фазной сети
#define R4VS12LDU	 BUFFER[538]	//(13_K02VDSR)- Движение реактора  к «У ОБРАЗЦОВ»
#define idR4VS12LDU	 266	//(13_K02VDSR)- Движение реактора  к «У ОБРАЗЦОВ»
#define R4VS22LDU	 BUFFER[540]	//(13_K03VDSR)- Движение реактора к «У ЗАЩИТЫ»
#define idR4VS22LDU	 267	//(13_K03VDSR)- Движение реактора к «У ЗАЩИТЫ»
#define A8IE01LDU	 BUFFER[542]	//(13_K04VDSR)- Исправность ИП ДС2
#define idA8IE01LDU	 268	//(13_K04VDSR)- Исправность ИП ДС2
#define R1VS12LDU	 BUFFER[544]	//(13_K05VDSR)- Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	 269	//(13_K05VDSR)- Движение МДЗ1 в сторону ВУ
#define R1VS22LDU	 BUFFER[546]	//(13_K06VDSR)- Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	 270	//(13_K06VDSR)- Движение МДЗ1 в сторону НУ
#define R1IE01LDU	 BUFFER[548]	//(13_K07VDSR)- Исправность ИП МДЗ1
#define idR1IE01LDU	 271	//(13_K07VDSR)- Исправность ИП МДЗ1
#define R2VS12LDU	 BUFFER[550]	//(13_K08VDSR)- Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	 272	//(13_K08VDSR)- Движение МДЗ2 в сторону ВУ
#define R2VS22LDU	 BUFFER[552]	//(13_K09VDSR)- Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	 273	//(13_K09VDSR)- Движение МДЗ2 в сторону НУ
#define R2IE01LDU	 BUFFER[554]	//(13_K10VDSR)- Исправность ИП МДЗ2
#define idR2IE01LDU	 274	//(13_K10VDSR)- Исправность ИП МДЗ2
#define A5VS12LDU	 BUFFER[556]	//(13_K11VDSR)- Движение НЛ1 в сторону ВУ
#define idA5VS12LDU	 275	//(13_K11VDSR)- Движение НЛ1 в сторону ВУ
#define A5VS22LDU	 BUFFER[558]	//(13_K12VDSR)- Движение НЛ1 в сторону НУ
#define idA5VS22LDU	 276	//(13_K12VDSR)- Движение НЛ1 в сторону НУ
#define A5IE02LDU	 BUFFER[560]	//(13_K13VDSR)- Исправность ИП НЛ1
#define idA5IE02LDU	 277	//(13_K13VDSR)- Исправность ИП НЛ1
#define B5VS12LDU	 BUFFER[562]	//(13_K14VDSR)- Движение НЛ2 в сторону ВУ
#define idB5VS12LDU	 278	//(13_K14VDSR)- Движение НЛ2 в сторону ВУ
#define B5VS22LDU	 BUFFER[564]	//(13_K15VDSR)- Движение НЛ2 в сторону НУ
#define idB5VS22LDU	 279	//(13_K15VDSR)- Движение НЛ2 в сторону НУ
#define B5IE01LDU	 BUFFER[566]	//(13_K16VDSR)- Исправность ИП НЛ2
#define idB5IE01LDU	 280	//(13_K16VDSR)- Исправность ИП НЛ2
#define A6VS12LDU	 BUFFER[568]	//(13_K17VDSR)- Движение створок БЗ1  к  «ОТКРЫТА»
#define idA6VS12LDU	 281	//(13_K17VDSR)- Движение створок БЗ1  к  «ОТКРЫТА»
#define A6VS22LDU	 BUFFER[570]	//(13_K18VDSR)- Движение створок БЗ1  к «ЗАКРЫТА»
#define idA6VS22LDU	 282	//(13_K18VDSR)- Движение створок БЗ1  к «ЗАКРЫТА»
#define A6IE01LDU	 BUFFER[572]	//(13_K19VDSR)- Исправность ИП БЗ1
#define idA6IE01LDU	 283	//(13_K19VDSR)- Исправность ИП БЗ1
#define B6VS12LDU	 BUFFER[574]	//(13_K20VDSR)- Движение створок БЗ2  к  «ОТКРЫТА»
#define idB6VS12LDU	 284	//(13_K20VDSR)- Движение створок БЗ2  к  «ОТКРЫТА»
#define B6VS22LDU	 BUFFER[576]	//(13_K21VDSR)- Движение створок БЗ2  к «ЗАКРЫТА»
#define idB6VS22LDU	 285	//(13_K21VDSR)- Движение створок БЗ2  к «ЗАКРЫТА»
#define B6IE01LDU	 BUFFER[578]	//(13_K22VDSR)- Исправность ИП БЗ2
#define idB6IE01LDU	 286	//(13_K22VDSR)- Исправность ИП БЗ2
#define R0IE02LDU	 BUFFER[580]	//(13_K23VDSR)- Исправность ИП 24 В-1
#define idR0IE02LDU	 287	//(13_K23VDSR)- Исправность ИП 24 В-1
#define R0IE01LDU	 BUFFER[582]	//(13_K24VDSR)- Исправность ИП 24 В-2
#define idR0IE01LDU	 288	//(13_K24VDSR)- Исправность ИП 24 В-2
#define R6IS62LDU	 BUFFER[584]	//(13_K25VDSR)- Исправность ВИП ССДИ-39 1канал
#define idR6IS62LDU	 289	//(13_K25VDSR)- Исправность ВИП ССДИ-39 1канал
#define R6IS63LDU	 BUFFER[586]	//(13_K26VDSR)- Исправность ВИП ССДИ-39 2канал
#define idR6IS63LDU	 290	//(13_K26VDSR)- Исправность ВИП ССДИ-39 2канал
#define R6IS64LDU	 BUFFER[588]	//(13_K27VDSR)- Исправность ВИП ССДИ-35 1канал
#define idR6IS64LDU	 291	//(13_K27VDSR)- Исправность ВИП ССДИ-35 1канал
#define R6IS65LDU	 BUFFER[590]	//(13_K28VDSR)- Исправность ВИП ССДИ-35 2канал
#define idR6IS65LDU	 292	//(13_K28VDSR)- Исправность ВИП ССДИ-35 2канал
#define s13_K29VDSR	 BUFFER[592]	//(13_K29VDSR)-
#define ids13_K29VDSR	 293	//(13_K29VDSR)-
#define s13_K30VDSR	 BUFFER[594]	//(13_K30VDSR)-
#define ids13_K30VDSR	 294	//(13_K30VDSR)-
#define s13_K31VDSR	 BUFFER[596]	//(13_K31VDSR)-
#define ids13_K31VDSR	 295	//(13_K31VDSR)-
#define s13_K32VDSR	 BUFFER[598]	//(13_K32VDSR)-
#define ids13_K32VDSR	 296	//(13_K32VDSR)-
#define A1AD32LDU	 BUFFER[600]	//(15_K01FDSR)- Обесточить ЭМ ББ1
#define idA1AD32LDU	 297	//(15_K01FDSR)- Обесточить ЭМ ББ1
#define A1AD31LDU	 BUFFER[602]	//(15_K02FDSR)- Клапан «Сброс ББ1» открыть (обесточить)
#define idA1AD31LDU	 298	//(15_K02FDSR)- Клапан «Сброс ББ1» открыть (обесточить)
#define A2AD32LDU	 BUFFER[604]	//(15_K03FDSR)- Обесточить ЭМ РБ1
#define idA2AD32LDU	 299	//(15_K03FDSR)- Обесточить ЭМ РБ1
#define A2AD31LDU	 BUFFER[606]	//(15_K04FDSR)- Клапан «Сброс РБ1» открыть (обесточить)
#define idA2AD31LDU	 300	//(15_K04FDSR)- Клапан «Сброс РБ1» открыть (обесточить)
#define B1AD32LDU	 BUFFER[608]	//(15_K05FDSR)- Обесточить ЭМ ББ2
#define idB1AD32LDU	 301	//(15_K05FDSR)- Обесточить ЭМ ББ2
#define B1AD31LDU	 BUFFER[610]	//(15_K06FDSR)- Клапан «Сброс ББ2» открыть (обесточить)
#define idB1AD31LDU	 302	//(15_K06FDSR)- Клапан «Сброс ББ2» открыть (обесточить)
#define B2AD32LDU	 BUFFER[612]	//(15_K07FDSR)- Обесточить ЭМ РБ2
#define idB2AD32LDU	 303	//(15_K07FDSR)- Обесточить ЭМ РБ2
#define B2AD31LDU	 BUFFER[614]	//(15_K08FDSR)- Клапан «Сброс РБ2» открыть (обесточить)
#define idB2AD31LDU	 304	//(15_K08FDSR)- Клапан «Сброс РБ2» открыть (обесточить)
#define R0AD03LZ1	 BUFFER[616]	//(15_K09FDSR)- (сигнал не подтвержден) Имитация прихода на ВУ ИС (БАЗ1)
#define idR0AD03LZ1	 305	//(15_K09FDSR)- (сигнал не подтвержден) Имитация прихода на ВУ ИС (БАЗ1)
#define R0AD04LZ1	 BUFFER[618]	//(15_K10FDSR)- (сигнал не подтвержден) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define idR0AD04LZ1	 306	//(15_K10FDSR)- (сигнал не подтвержден) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define R0AD05LZ1	 BUFFER[620]	//(15_K11FDSR)- (сигнал не подтвержден) Имитация ухода с НУП ИС  (БАЗ1)
#define idR0AD05LZ1	 307	//(15_K11FDSR)- (сигнал не подтвержден) Имитация ухода с НУП ИС  (БАЗ1)
#define R8AD21LDU	 BUFFER[622]	//(15_K12FDSR)- Запуск системы инициирования
#define idR8AD21LDU	 308	//(15_K12FDSR)- Запуск системы инициирования
#define R0AD16LDU	 BUFFER[624]	//(15_K13FDSR)- Контроль  I-II УР. РАД
#define idR0AD16LDU	 309	//(15_K13FDSR)- Контроль  I-II УР. РАД
#define R0AD03LZ2	 BUFFER[626]	//(15_K14FDSR)- (сигнал не подтвержден) Имитация прихода на ВУ ИС (БАЗ2)
#define idR0AD03LZ2	 310	//(15_K14FDSR)- (сигнал не подтвержден) Имитация прихода на ВУ ИС (БАЗ2)
#define R0AD04LZ2	 BUFFER[628]	//(15_K15FDSR)- (сигнал не подтвержден) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define idR0AD04LZ2	 311	//(15_K15FDSR)- (сигнал не подтвержден) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define R0AD05LZ2	 BUFFER[630]	//(15_K16FDSR)- (сигнал не подтвержден) Имитация ухода с НУП ИС  (БАЗ2)
#define idR0AD05LZ2	 312	//(15_K16FDSR)- (сигнал не подтвержден) Имитация ухода с НУП ИС  (БАЗ2)
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &R0IC00LDU},	//(01_K01VDSR)- +Di0
	{ 2	,1	,1	, &R0IC01LDU},	//(01_K02VDSR)- +Di1
	{ 3	,1	,1	, &R0IC02LDU},	//(01_K03VDSR)- +Di2
	{ 4	,1	,1	, &R0IC03LDU},	//(01_K04VDSR)- +Di3
	{ 5	,1	,1	, &R0IC04LDU},	//(01_K05VDSR)- +Di4
	{ 6	,1	,1	, &R0IC05LDU},	//(01_K06VDSR)- +Di5
	{ 7	,1	,1	, &R0IC06LDU},	//(01_K07VDSR)- +Di6
	{ 8	,1	,1	, &R0IC07LDU},	//(01_K08VDSR)- +Di7
	{ 9	,1	,1	, &R0IC08LDU},	//(01_K09VDSR)- +Di8
	{ 10	,1	,1	, &R0IC09LDU},	//(01_K10VDSR)- +Di9
	{ 11	,1	,1	, &R0IC10LDU},	//(01_K11VDSR)- +Di10
	{ 12	,1	,1	, &R0IC11LDU},	//(01_K12VDSR)- +Di11
	{ 13	,1	,1	, &R0IC12LDU},	//(01_K13VDSR)- +Di12
	{ 14	,1	,1	, &R0IC13LDU},	//(01_K14VDSR)- +Di13
	{ 15	,1	,1	, &R0IC14LDU},	//(01_K15VDSR)- +Di14
	{ 16	,1	,1	, &R0IC15LDU},	//(01_K16VDSR)- +Di15
	{ 17	,1	,1	, &R0IC16LDU},	//(01_K17VDSR)- +Di16
	{ 18	,1	,1	, &R0IC17LDU},	//(01_K18VDSR)- +Di17
	{ 19	,1	,1	, &R0IC18LDU},	//(01_K19VDSR)- +Di18
	{ 20	,1	,1	, &R0IC19LDU},	//(01_K20VDSR)- +Di19
	{ 21	,1	,1	, &R0IC20LDU},	//(01_K21VDSR)- +Di20
	{ 22	,1	,1	, &R0IC21LDU},	//(01_K22VDSR)- +Di21
	{ 23	,1	,1	, &R0IC22LDU},	//(01_K23VDSR)- +Di22
	{ 24	,1	,1	, &R0IC23LDU},	//(01_K24VDSR)- +Di23
	{ 25	,1	,1	, &R0IC24LDU},	//(01_K25VDSR)- +Di24
	{ 26	,1	,1	, &R0IC25LDU},	//(01_K26VDSR)- +Di25
	{ 27	,1	,1	, &R0IC26LDU},	//(01_K27VDSR)- +Di26
	{ 28	,1	,1	, &R0IC27LDU},	//(01_K28VDSR)- +Di27
	{ 29	,1	,1	, &R0IC28LDU},	//(01_K29VDSR)- +Di28
	{ 30	,1	,1	, &R0IC29LDU},	//(01_K30VDSR)- +Di29
	{ 31	,1	,1	, &R0IC30LDU},	//(01_K31VDSR)- +Di30
	{ 32	,1	,1	, &R0IC31LDU},	//(01_K32VDSR)- +Di31
	{ 33	,1	,1	, &B3IS35LDU},	//(02_K01VDSR)- Клапан «ВПИС2» открыт (обесточен)
	{ 34	,1	,1	, &B3IS33LDU},	//(02_K02VDSR)- Клапан «ВЫСТРЕЛ ИС2» открыт (обесточен)
	{ 35	,1	,1	, &B2IS33LDU},	//(02_K03VDSR)- Клапан «Подъём РБ2» открыт (обесточен)
	{ 36	,1	,1	, &B4IS10LDU},	//(02_K04VDSR)- Клапан «Подъём НИ2» открыт (обесточен)
	{ 37	,1	,1	, &B3IS31LDU},	//(02_K05VDSR)- Клапан «СПУСК ИС2» открыт (обесточен)
	{ 38	,1	,1	, &B7AS31LDU},	//(02_K06VDSR)- Клапан «Обдув АЗ2» открыт (обесточен)
	{ 39	,1	,1	, &B1IS12LDU},	//(02_K07VDSR)- Магнит ББ2 зацеплен
	{ 40	,1	,1	, &B1IS11LDU},	//(02_K08VDSR)- Приход на ВУ ББ2
	{ 41	,1	,1	, &B1IS21LDU},	//(02_K09VDSR)- Приход на НУ ББ2
	{ 42	,1	,1	, &B2IS12LDU},	//(02_K10VDSR)- Магнит РБ2 зацеплен
	{ 43	,1	,1	, &B2IS11LDU},	//(02_K11VDSR)- Приход на ВУ РБ2-СТР
	{ 44	,1	,1	, &B2IS21LDU},	//(02_K12VDSR)- Приход на НУ РБ2-СС
	{ 45	,1	,1	, &B3IS21LDU},	//(02_K13VDSR)- Приход на НУ ИС2
	{ 46	,1	,1	, &R8IS11LDU},	//(02_K14VDSR)- Аварийный НИ установлен
	{ 47	,1	,1	, &B8IS12LDU},	//(02_K15VDSR)- Приход на механический ВУ АЗ2
	{ 48	,1	,1	, &B8IS22LDU},	//(02_K16VDSR)- Приход на механический НУ АЗ2
	{ 49	,1	,1	, &s02_K17VDSR},	//(02_K17VDSR)- 
	{ 50	,1	,1	, &A3VZ13LZ1},	//(02_K18VDSR)- Имитация срабатывания АЗ от ВУ ИС
	{ 51	,1	,1	, &A3VZ15LZ1},	//(02_K19VDSR)- Имитация срабатывания АЗ от НУП ИС
	{ 52	,1	,1	, &R0AD14LZ1},	//(02_K20VDSR)- Имитация срабатывания АЗ от II УР
	{ 53	,1	,1	, &A1VN71LZ1},	//(02_K21VDSR)- Блокировка автоматического подъёма ББ
	{ 54	,1	,1	, &R0VZ71LZ1},	//(02_K22VDSR)- Обобщенный сигнал АЗ 1канала
	{ 55	,1	,1	, &A9IS11LDU},	//(02_K23VDSR)- Приход на ВУ НИ ДС1
	{ 56	,1	,1	, &A9IS21LDU},	//(02_K24VDSR)- Приход на НУ НИ ДС1
	{ 57	,1	,1	, &B9IS11LDU},	//(02_K25VDSR)- Приход на ВУ НИ ДС2
	{ 58	,1	,1	, &B9IS21LDU},	//(02_K26VDSR)- Приход на НУ НИ ДС2
	{ 59	,1	,1	, &R1IS11LDU},	//(02_K27VDSR)- Приход на ВУ МДЗ1
	{ 60	,1	,1	, &R1IS21LDU},	//(02_K28VDSR)- Приход на НУ МДЗ1
	{ 61	,1	,1	, &R2IS11LDU},	//(02_K29VDSR)- Приход на ВУ МДЗ2
	{ 62	,1	,1	, &R2IS21LDU},	//(02_K30VDSR)- Приход на НУ МДЗ2
	{ 63	,1	,1	, &B4IS11LDU},	//(02_K31VDSR)- Приход на ВУ НИ2
	{ 64	,1	,1	, &B4IS21LDU},	//(02_K32VDSR)- Приход на НУ НИ2
	{ 65	,1	,1	, &A3IS35LDU},	//(03_K01VDSR)- Клапан «ВПИС1» открыт (обесточен)
	{ 66	,1	,1	, &A3IS33LDU},	//(03_K02VDSR)- Клапан «ВЫСТРЕЛ ИС1» открыт (обесточен)
	{ 67	,1	,1	, &A2IS33LDU},	//(03_K03VDSR)- Клапан «Подъём РБ1» открыт (обесточен)
	{ 68	,1	,1	, &A4IS10LDU},	//(03_K04VDSR)- Клапан «Подъём НИ1» открыт (обесточен)
	{ 69	,1	,1	, &A3IS31LDU},	//(03_K05VDSR)- Клапан «СПУСК ИС1» открыт (обесточен)
	{ 70	,1	,1	, &A7AS31LDU},	//(03_K06VDSR)- Клапан «Обдув АЗ1» открыт (обесточен)
	{ 71	,1	,1	, &A1IS12LDU},	//(03_K07VDSR)- Магнит ББ1 зацеплен
	{ 72	,1	,1	, &A1IS11LDU},	//(03_K08VDSR)- Приход на ВУ ББ1
	{ 73	,1	,1	, &A1IS21LDU},	//(03_K09VDSR)- Приход на НУ ББ1
	{ 74	,1	,1	, &A2IS12LDU},	//(03_K10VDSR)- Магнит РБ1 зацеплен
	{ 75	,1	,1	, &A2IS11LDU},	//(03_K11VDSR)- Приход на ВУ РБ1-СТР
	{ 76	,1	,1	, &A2IS21LDU},	//(03_K12VDSR)- Приход на НУ РБ1-СС
	{ 77	,1	,1	, &A3IS21LDU},	//(03_K13VDSR)- Приход на НУ ИС1
	{ 78	,1	,1	, &A4IS11LDU},	//(03_K14VDSR)- Приход на ВУ НИ1
	{ 79	,1	,1	, &A4IS21LDU},	//(03_K15VDSR)- Приход на НУ НИ1
	{ 80	,1	,1	, &s03_K16VDSR},	//(03_K16VDSR)-
	{ 81	,1	,1	, &s03_K17VDSR},	//(03_K17VDSR)-
	{ 82	,1	,1	, &A3VZ13LZ2},	//(03_K18VDSR)- Имитация срабатывания АЗ от ВУ ИС
	{ 83	,1	,1	, &A3VZ15LZ2},	//(03_K19VDSR)- Имитация срабатывания АЗ от НУП ИС
	{ 84	,1	,1	, &R0AD14LZ2},	//(03_K20VDSR)- Имитация срабатывания АЗ от  II УР
	{ 85	,1	,1	, &A1VN71LZ2},	//(03_K21VDSR)- Блокировка автоматического подъёма ББ
	{ 86	,1	,1	, &R0VZ71LZ2},	//(03_K22VDSR)- Обобщенный сигнал АЗ 2 канала
	{ 87	,1	,1	, &A3VP81LDU},	//(03_K23VDSR)- Давление СПУСК ИС1 в норме
	{ 88	,1	,1	, &A2VP82LDU},	//(03_K24VDSR)- Давление ПОДЪЁМ РБ1 в норме
	{ 89	,1	,1	, &A4VP82LDU},	//(03_K25VDSR)- Давление ПОДЪЁМ НИ1 в норме
	{ 90	,1	,1	, &B3VP81LDU},	//(03_K26VDSR)- Давление СПУСК ИС2 в норме
	{ 91	,1	,1	, &B2VP82LDU},	//(03_K27VDSR)- Давление ПОДЪЁМ РБ2 в норме
	{ 92	,1	,1	, &B4VP82LDU},	//(03_K28VDSR)- Давление ПОДЪЁМ НИ2 в норме
	{ 93	,1	,1	, &R0IS01LDU},	//(03_K29VDSR)- Признак работы с имитатором
	{ 94	,1	,1	, &R0IS02LDU},	//(03_K30VDSR)- Разрешение ввода от имитатора
	{ 95	,1	,1	, &s03_K31VDSR},	//(03_K31VDSR)-
	{ 96	,1	,1	, &s03_K32VDSR},	//(03_K32VDSR)-
	{ 97	,1	,1	, &A3IS11LDU},	//(04_K01VDSR)- Приход на ВУ ИС1
	{ 98	,1	,1	, &A3IS22LDU},	//(04_K02VDSR)- Приход на НУП ИС1
	{ 99	,1	,1	, &B3IS11LDU},	//(04_K03VDSR)- Приход на ВУ ИС2
	{ 100	,1	,1	, &B3IS22LDU},	//(04_K04VDSR)- Приход на НУП ИС2
	{ 101	,1	,1	, &R4IS11LDU},	//(04_K05VDSR)- Приход на ВУ тележки
	{ 102	,1	,1	, &R4IS12LDU},	//(04_K06VDSR)- Приход на механический ВУ тележки
	{ 103	,1	,1	, &R4IS21LDU},	//(04_K07VDSR)- Приход на НУ тележки
	{ 104	,1	,1	, &R4IS22LDU},	//(04_K08VDSR)- Приход на механический НУ тележки
	{ 105	,1	,1	, &A6IS11LDU},	//(04_K09VDSR)- Приход на ВУ БЗ1
	{ 106	,1	,1	, &A6IS21LDU},	//(04_K10VDSR)- Приход на НУ БЗ1
	{ 107	,1	,1	, &A5IS11LDU},	//(04_K11VDSR)- Приход на ВУ НЛ1
	{ 108	,1	,1	, &A5IS21LDU},	//(04_K12VDSR)- Приход на НУ НЛ1
	{ 109	,1	,1	, &B6IS11LDU},	//(04_K13VDSR)- Приход на ВУ БЗ2
	{ 110	,1	,1	, &B6IS21LDU},	//(04_K14VDSR)- Приход на НУ БЗ2
	{ 111	,1	,1	, &B5IS11LDU},	//(04_K15VDSR)- Приход на ВУ НЛ2
	{ 112	,1	,1	, &B5IS21LDU},	//(04_K16VDSR)- Приход на НУ НЛ2
	{ 113	,1	,1	, &R3IS11LDU},	//(04_K17VDSR)- Приход на ВУ гомогенных дверей-1
	{ 114	,1	,1	, &R3IS21LDU},	//(04_K18VDSR)- Приход на НУ гомогенных дверей-1
	{ 115	,1	,1	, &R3IS31LDU},	//(04_K19VDSR)- Приход на ВУ гомогенных дверей-2
	{ 116	,1	,1	, &R3IS41LDU},	//(04_K20VDSR)- Приход на НУ гомогенных дверей-2
	{ 117	,1	,1	, &R3AD10LDU},	//(04_K21VDSR)- Гомогенные двери-1 открыть
	{ 118	,1	,1	, &R3AD11LDU},	//(04_K22VDSR)- Гомогенные двери-2 открыть
	{ 119	,1	,1	, &R3AD20LDU},	//(04_K23VDSR)- Гомогенные двери-1 закрыть
	{ 120	,1	,1	, &R3AD21LDU},	//(04_K24VDSR)- Гомогенные двери-2 закрыть
	{ 121	,1	,1	, &R5IS11LDU},	//(04_K25VDSR)- Приход на ВУ ворот отстойной зоны
	{ 122	,1	,1	, &R5IS21LDU},	//(04_K26VDSR)- Приход на НУ ворот отстойной зоны
	{ 123	,1	,1	, &R5AD10LDU},	//(04_K27VDSR)- Открыть ворота отстойной зоны
	{ 124	,1	,1	, &R5AD20LDU},	//(04_K28VDSR)- Закрыть ворота отстойной зоны
	{ 125	,1	,1	, &R6IS21LDU},	//(04_K29VDSR)- Кран-балка в нерабочем положении
	{ 126	,1	,1	, &A8IS12LDU},	//(04_K30VDSR)- Приход на механический ВУ ДС2
	{ 127	,1	,1	, &A8IS22LDU},	//(04_K31VDSR)- Приход на механический НУ ДС2
	{ 128	,1	,1	, &s04_K32VDSR},	//(04_K32VDSR)-
	{ 129	,1	,1	, &A1IE02LDU},	//(05_K01VDSR)- Исправность ИП ББ1
	{ 130	,1	,1	, &A1IE01LDU},	//(05_K02VDSR)- Исправность БУШД ББ1
	{ 131	,1	,1	, &A1IE03LDU},	//(05_K03VDSR)- Движение ББ1 вперед (от БУШД)
	{ 132	,1	,1	, &A1IE04LDU},	//(05_K04VDSR)- Движение ББ1 назад (от БУШД)
	{ 133	,1	,1	, &A2IE02LDU},	//(05_K05VDSR)- Исправность ИП РБ1
	{ 134	,1	,1	, &A2IE01LDU},	//(05_K06VDSR)- Исправность БУШД РБ1
	{ 135	,1	,1	, &A2IE03LDU},	//(05_K07VDSR)- Движение РБ1 вперед (от БУШД)
	{ 136	,1	,1	, &A2IE04LDU},	//(05_K08VDSR)- Движение РБ1 назад (от БУШД)
	{ 137	,1	,1	, &A3IE02LDU},	//(05_K09VDSR)- Исправность ИП ИС1
	{ 138	,1	,1	, &A3IE01LDU},	//(05_K10VDSR)- Исправность БУШД ИС1
	{ 139	,1	,1	, &A3IE03LDU},	//(05_K11VDSR)- Движение ИС1 вперед (от БУШД)
	{ 140	,1	,1	, &A3IE04LDU},	//(05_K12VDSR)- Движение ИС1 назад (от БУШД)
	{ 141	,1	,1	, &B1IE02LDU},	//(05_K13VDSR)- Исправность ИП ББ2
	{ 142	,1	,1	, &B1IE01LDU},	//(05_K14VDSR)- Исправность БУШД ББ2
	{ 143	,1	,1	, &B1IE03LDU},	//(05_K15VDSR)- Движение ББ2 вперед (от БУШД)
	{ 144	,1	,1	, &B1IE04LDU},	//(05_K16VDSR)- Движение ББ2 назад (от БУШД)
	{ 145	,1	,1	, &B2IE02LDU},	//(05_K17VDSR)- Исправность ИП РБ2
	{ 146	,1	,1	, &B2IE01LDU},	//(05_K18VDSR)- Исправность БУШД РБ2
	{ 147	,1	,1	, &B2IE03LDU},	//(05_K19VDSR)- Движение РБ2 вперед (от БУШД)
	{ 148	,1	,1	, &B2IE04LDU},	//(05_K20VDSR)- Движение РБ2 назад (от БУШД)
	{ 149	,1	,1	, &B3IE02LDU},	//(05_K21VDSR)- Исправность ИП ИС2
	{ 150	,1	,1	, &B3IE01LDU},	//(05_K22VDSR)- Исправность БУШД ИС2
	{ 151	,1	,1	, &B3IE03LDU},	//(05_K23VDSR)- Движение ИС2 вперед (от БУШД)
	{ 152	,1	,1	, &B3IE04LDU},	//(05_K24VDSR)- Движение ИС2 назад (от БУШД)
	{ 153	,1	,1	, &R6IS31LDU},	//(05_K25VDSR)- контроль задней двери ШС
	{ 154	,1	,1	, &R6IS32LDU},	//(05_K26VDSR)- контроль передней двери ШС
	{ 155	,1	,1	, &R6IS41LDU},	//(05_K27VDSR)- контроль задней двери ШЭП
	{ 156	,1	,1	, &R6IS42LDU},	//(05_K28VDSR)- контроль передней двери ШЭП
	{ 157	,1	,1	, &R6IS51LDU},	//(05_K29VDSR)- контроль задней двери ШПУ
	{ 158	,1	,1	, &R6IS52LDU},	//(05_K30VDSR)- контроль передней двери ШПУ
	{ 159	,1	,1	, &s05_K31VDSR},	//(05_K31VDSR)-
	{ 160	,1	,1	, &s05_K32VDSR},	//(05_K32VDSR)-
	{ 161	,1	,1	, &A1IC01LDU},	//(06_K01FDSR)- BUS1_ББ1, у ТИБ BUS1 ББ1
	{ 162	,1	,1	, &B1IC01LDU},	//(06_K02FDSR)- BUS2_ББ2
	{ 163	,1	,1	, &A2IC01LDU},	//(06_K03FDSR)- BUS3_РБ1
	{ 164	,1	,1	, &B2IC01LDU},	//(06_K04FDSR)- BUS4_РБ2
	{ 165	,1	,1	, &A3IC01LDU},	//(06_K05FDSR)- BUS5_ИС1
	{ 166	,1	,1	, &B3IC01LDU},	//(06_K06FDSR)- BUS6_ИС2
	{ 167	,1	,1	, &B8IC01LDU},	//(06_K07FDSR)- BUS7_АЗ2
	{ 168	,1	,1	, &A8IC01LDU},	//(06_K08FDSR)- BUS8_ДС2
	{ 169	,1	,1	, &R0IC41LDU},	//(06_K09FDSR)- LUTCH у ТИБ Latch
	{ 170	,1	,1	, &s06_K10FDSR},	//(06_K10FDSR)-
	{ 171	,1	,1	, &s06_K11FDSR},	//(06_K11FDSR)-
	{ 172	,1	,1	, &s06_K12FDSR},	//(06_K12FDSR)-
	{ 173	,1	,1	, &s06_K13FDSR},	//(06_K13FDSR)-
	{ 174	,1	,1	, &s06_K14FDSR},	//(06_K14FDSR)-
	{ 175	,1	,1	, &s06_K15FDSR},	//(06_K15FDSR)-
	{ 176	,1	,1	, &s06_K16FDSR},	//(06_K16FDSR)-
	{ 177	,1	,1	, &A2AD11LDU},	//(07_K01FDSR)- Сигнал на перемещение РБ1 вверх
	{ 178	,1	,1	, &A2AD21LDU},	//(07_K02FDSR)- Сигнал на перемещение РБ1 вниз
	{ 179	,1	,1	, &A2AD01LDU},	//(07_K03FDSR)- Разрешение движения РБ1
	{ 180	,1	,1	, &A2AD02LDU},	//(07_K04FDSR)- 0-й бит скорости РБ1
	{ 181	,1	,1	, &A2AD03LDU},	//(07_K05FDSR)- 1-й бит скорости РБ1
	{ 182	,1	,1	, &A2AD04LDU},	//(07_K06FDSR)- 2-й бит скорости РБ1
	{ 183	,1	,1	, &A2AD05LDU},	//(07_K07FDSR)- паритет команды на РБ1
	{ 184	,1	,1	, &B2AD11LDU},	//(07_K08FDSR)- Сигнал на перемещение РБ2 вверх
	{ 185	,1	,1	, &B2AD21LDU},	//(07_K09FDSR)- Сигнал на перемещение РБ2 вниз
	{ 186	,1	,1	, &B2AD01LDU},	//(07_K10FDSR)- Разрешение движения РБ2
	{ 187	,1	,1	, &B2AD02LDU},	//(07_K11FDSR)- 0-й бит скорости РБ2
	{ 188	,1	,1	, &B2AD03LDU},	//(07_K12FDSR)- 1-й бит скорости РБ2
	{ 189	,1	,1	, &B2AD04LDU},	//(07_K13FDSR)- 2-й бит скорости РБ2
	{ 190	,1	,1	, &B2AD05LDU},	//(07_K14FDSR)- паритет команды на РБ2
	{ 191	,1	,1	, &A2IS12LZ2},	//(07_K15FDSR)- (сигнал не подтвержден) Магнит РБ1 зацеплен (для БАЗ2)
	{ 192	,1	,1	, &B2IS12LZ2},	//(07_K16FDSR)- (сигнал не подтвержден) Магнит РБ2 зацеплен (для БАЗ2)
	{ 193	,1	,1	, &A1AD11LDU},	//(08_K01FDSR)- Сигнал на перемещение ББ1 вверх
	{ 194	,1	,1	, &A1AD21LDU},	//(08_K02FDSR)- Сигнал на перемещение ББ1 вниз
	{ 195	,1	,1	, &A1AD01LDU},	//(08_K03FDSR)- Разрешение движения ББ1
	{ 196	,1	,1	, &A1AD02LDU},	//(08_K04FDSR)- 0-й бит скорости ББ1
	{ 197	,1	,1	, &A1AD03LDU},	//(08_K05FDSR)- 1-й бит скорости ББ1
	{ 198	,1	,1	, &A1AD04LDU},	//(08_K06FDSR)- 2-й бит скорости ББ1
	{ 199	,1	,1	, &A1AD05LDU},	//(08_K07FDSR)- паритет команды на ББ1
	{ 200	,1	,1	, &B1AD11LDU},	//(08_K08FDSR)- Сигнал на перемещение ББ2 вверх
	{ 201	,1	,1	, &B1AD21LDU},	//(08_K09FDSR)- Сигнал на перемещение ББ2 вниз
	{ 202	,1	,1	, &B1AD01LDU},	//(08_K10FDSR)- Разрешение движения ББ2
	{ 203	,1	,1	, &B1AD02LDU},	//(08_K11FDSR)- 0-й бит скорости ББ2
	{ 204	,1	,1	, &B1AD03LDU},	//(08_K12FDSR)- 1-й бит скорости ББ2
	{ 205	,1	,1	, &B1AD04LDU},	//(08_K13FDSR)- 2-й бит скорости ББ2
	{ 206	,1	,1	, &B1AD05LDU},	//(08_K14FDSR)- паритет команды на ББ2
	{ 207	,1	,1	, &A2IS12LZ1},	//(08_K15FDSR)- (сигнал не подтвержден) Магнит РБ1 зацеплен (для БАЗ1)
	{ 208	,1	,1	, &B2IS12LZ1},	//(08_K16FDSR)- (сигнал не подтвержден) Магнит РБ2 зацеплен (для БАЗ1)
	{ 209	,1	,1	, &B3AD34LDU},	//(09_K01FDSR)- Клапан  ВПИС ИС2   открыть (обесточить)
	{ 210	,1	,1	, &B3AD33LDU},	//(09_K02FDSR)- Клапан «ВЫСТРЕЛ ИС2» закрыть (обесточить)
	{ 211	,1	,1	, &B2AD33LDU},	//(09_K03FDSR)- Клапан «Подъем РБ2» открыть
	{ 212	,1	,1	, &B4AD10LDU},	//(09_K04FDSR)- Открыть клапан  Подъем НИ2 
	{ 213	,1	,1	, &B3AD31LDU},	//(09_K05FDSR)- Клапан «СПУСК ИС2» открыть (обесточить)
	{ 214	,1	,1	, &B7AP31LDU},	//(09_K06FDSR)- Клапан «Обдув АЗ2» открыть (обесточить)
	{ 215	,1	,1	, &A8AD10LDU},	//(09_K07FDSR)- Перемещение ДС2 вперед
	{ 216	,1	,1	, &A8AD20LDU},	//(09_K08FDSR)- Перемещение ДС2 назад
	{ 217	,1	,1	, &A6AD10LDU},	//(09_K09FDSR)- Открыть БЗ1
	{ 218	,1	,1	, &A6AD20LDU},	//(09_K10FDSR)- Закрыть БЗ1
	{ 219	,1	,1	, &B6AD10LDU},	//(09_K11FDSR)- Открыть БЗ2
	{ 220	,1	,1	, &B6AD20LDU},	//(09_K12FDSR)- Закрыть БЗ2
	{ 221	,1	,1	, &R4AD10LDU},	//(09_K13FDSR)- Перемещение тележки вперед
	{ 222	,1	,1	, &R4AD20LDU},	//(09_K14FDSR)- Перемещение тележки назад
	{ 223	,1	,1	, &B8AD10LDU},	//(09_K15FDSR)- Перемещение АЗ2 вперед
	{ 224	,1	,1	, &B8AD20LDU},	//(09_K16FDSR)- Перемещение АЗ2 назад
	{ 225	,1	,1	, &A3AD34LDU},	//(10_K01FDSR)- Клапан  ВПИС1   открыть (обесточить)
	{ 226	,1	,1	, &A3AD33LDU},	//(10_K02FDSR)- Клапан «ВЫСТРЕЛ ИС1» открыть (обесточить)
	{ 227	,1	,1	, &A2AD33LDU},	//(10_K03FDSR)- Клапан «Подъем РБ1» открыть
	{ 228	,1	,1	, &A4AD10LDU},	//(10_K04FDSR)- Открыть клапан  Подъем НИ1 
	{ 229	,1	,1	, &A3AD31LDU},	//(10_K05FDSR)- Клапан «СПУСК ИС1» открыть (обесточить)
	{ 230	,1	,1	, &A7AP31LDU},	//(10_K06FDSR)- Клапан «Обдув АЗ1» открыть (обесточить)
	{ 231	,1	,1	, &R1AD10LDU},	//(10_K07FDSR)- Опустить МДЗ1 в зону облучения
	{ 232	,1	,1	, &R1AD20LDU},	//(10_K08FDSR)- Поднять МДЗ1
	{ 233	,1	,1	, &R2AD10LDU},	//(10_K09FDSR)- Опустить МДЗ2 в зону облучения
	{ 234	,1	,1	, &R2AD20LDU},	//(10_K10FDSR)- Поднять МДЗ2
	{ 235	,1	,1	, &A5AD10LDU},	//(10_K11FDSR)- Поднять НЛ1
	{ 236	,1	,1	, &A5AD20LDU},	//(10_K12FDSR)- Опустить НЛ1
	{ 237	,1	,1	, &B5AD10LDU},	//(10_K13FDSR)- Поднять НЛ2
	{ 238	,1	,1	, &B5AD20LDU},	//(10_K14FDSR)- Опустить НЛ2
	{ 239	,1	,1	, &s10_K15FDSR},	//(10_K15FDSR)-
	{ 240	,1	,1	, &s10_K16FDSR},	//(10_K16FDSR)-
	{ 241	,1	,1	, &A3AD11LDU},	//(11_K01FDSR)- Сигнал на перемещение ИС1 вверх
	{ 242	,1	,1	, &A3AD21LDU},	//(11_K02FDSR)- Сигнал на перемещение ИС1 вниз
	{ 243	,1	,1	, &A3AD01LDU},	//(11_K03FDSR)- Разрешение движения ИС1
	{ 244	,1	,1	, &A3AD02LDU},	//(11_K04FDSR)- 0-й бит скорости ИС1
	{ 245	,1	,1	, &A3AD03LDU},	//(11_K05FDSR)- 1-й бит скорости ИС1
	{ 246	,1	,1	, &A3AD04LDU},	//(11_K06FDSR)- 2-й бит скорости ИС1
	{ 247	,1	,1	, &A3AD05LDU},	//(11_K07FDSR)- паритет команды на ИС1
	{ 248	,1	,1	, &B3AD11LDU},	//(11_K08FDSR)- Сигнал на перемещение ИС2 вверх
	{ 249	,1	,1	, &B3AD21LDU},	//(11_K09FDSR)- Сигнал на перемещение ИС2 вниз
	{ 250	,1	,1	, &B3AD01LDU},	//(11_K10FDSR)- Разрешение движения ИС2
	{ 251	,1	,1	, &B3AD02LDU},	//(11_K11FDSR)- 0-й бит скорости ИС2
	{ 252	,1	,1	, &B3AD03LDU},	//(11_K12FDSR)- 1-й бит скорости ИС2
	{ 253	,1	,1	, &B3AD04LDU},	//(11_K13FDSR)- 2-й бит скорости ИС2
	{ 254	,1	,1	, &B3AD05LDU},	//(11_K14FDSR)- паритет команды на ИС2
	{ 255	,1	,1	, &A9AD10LDU},	//(11_K15FDSR)- Открыть клапан  Подъем НИ ДС1 
	{ 256	,1	,1	, &B9AD10LDU},	//(11_K16FDSR)- Открыть клапан  Подъем НИ ДС2 
	{ 257	,3	,1	, &A3IP02IDU},	//(12_K01VASR)- Текущее давление ВЫСТРЕЛ ИС1
	{ 258	,3	,1	, &B3IP02IDU},	//(12_K02VASR)- Текущее давление ВЫСТРЕЛ ИС2
	{ 259	,3	,1	, &s12_K03VASR},	//(12_K03VASR)-
	{ 260	,3	,1	, &s12_K04VASR},	//(12_K04VASR)-
	{ 261	,3	,1	, &s12_K05VASR},	//(12_K05VASR)-
	{ 262	,3	,1	, &s12_K06VASR},	//(12_K06VASR)-
	{ 263	,3	,1	, &s12_K07VASR},	//(12_K07VASR)-
	{ 264	,3	,1	, &s12_K08VASR},	//(12_K08VASR)-
	{ 265	,1	,1	, &R6IS61LDU},	//(13_K01VDSR)- Исправность 3-х  фазной сети
	{ 266	,1	,1	, &R4VS12LDU},	//(13_K02VDSR)- Движение реактора  к «У ОБРАЗЦОВ»
	{ 267	,1	,1	, &R4VS22LDU},	//(13_K03VDSR)- Движение реактора к «У ЗАЩИТЫ»
	{ 268	,1	,1	, &A8IE01LDU},	//(13_K04VDSR)- Исправность ИП ДС2
	{ 269	,1	,1	, &R1VS12LDU},	//(13_K05VDSR)- Движение МДЗ1 в сторону ВУ
	{ 270	,1	,1	, &R1VS22LDU},	//(13_K06VDSR)- Движение МДЗ1 в сторону НУ
	{ 271	,1	,1	, &R1IE01LDU},	//(13_K07VDSR)- Исправность ИП МДЗ1
	{ 272	,1	,1	, &R2VS12LDU},	//(13_K08VDSR)- Движение МДЗ2 в сторону ВУ
	{ 273	,1	,1	, &R2VS22LDU},	//(13_K09VDSR)- Движение МДЗ2 в сторону НУ
	{ 274	,1	,1	, &R2IE01LDU},	//(13_K10VDSR)- Исправность ИП МДЗ2
	{ 275	,1	,1	, &A5VS12LDU},	//(13_K11VDSR)- Движение НЛ1 в сторону ВУ
	{ 276	,1	,1	, &A5VS22LDU},	//(13_K12VDSR)- Движение НЛ1 в сторону НУ
	{ 277	,1	,1	, &A5IE02LDU},	//(13_K13VDSR)- Исправность ИП НЛ1
	{ 278	,1	,1	, &B5VS12LDU},	//(13_K14VDSR)- Движение НЛ2 в сторону ВУ
	{ 279	,1	,1	, &B5VS22LDU},	//(13_K15VDSR)- Движение НЛ2 в сторону НУ
	{ 280	,1	,1	, &B5IE01LDU},	//(13_K16VDSR)- Исправность ИП НЛ2
	{ 281	,1	,1	, &A6VS12LDU},	//(13_K17VDSR)- Движение створок БЗ1  к  «ОТКРЫТА»
	{ 282	,1	,1	, &A6VS22LDU},	//(13_K18VDSR)- Движение створок БЗ1  к «ЗАКРЫТА»
	{ 283	,1	,1	, &A6IE01LDU},	//(13_K19VDSR)- Исправность ИП БЗ1
	{ 284	,1	,1	, &B6VS12LDU},	//(13_K20VDSR)- Движение створок БЗ2  к  «ОТКРЫТА»
	{ 285	,1	,1	, &B6VS22LDU},	//(13_K21VDSR)- Движение створок БЗ2  к «ЗАКРЫТА»
	{ 286	,1	,1	, &B6IE01LDU},	//(13_K22VDSR)- Исправность ИП БЗ2
	{ 287	,1	,1	, &R0IE02LDU},	//(13_K23VDSR)- Исправность ИП 24 В-1
	{ 288	,1	,1	, &R0IE01LDU},	//(13_K24VDSR)- Исправность ИП 24 В-2
	{ 289	,1	,1	, &R6IS62LDU},	//(13_K25VDSR)- Исправность ВИП ССДИ-39 1канал
	{ 290	,1	,1	, &R6IS63LDU},	//(13_K26VDSR)- Исправность ВИП ССДИ-39 2канал
	{ 291	,1	,1	, &R6IS64LDU},	//(13_K27VDSR)- Исправность ВИП ССДИ-35 1канал
	{ 292	,1	,1	, &R6IS65LDU},	//(13_K28VDSR)- Исправность ВИП ССДИ-35 2канал
	{ 293	,1	,1	, &s13_K29VDSR},	//(13_K29VDSR)-
	{ 294	,1	,1	, &s13_K30VDSR},	//(13_K30VDSR)-
	{ 295	,1	,1	, &s13_K31VDSR},	//(13_K31VDSR)-
	{ 296	,1	,1	, &s13_K32VDSR},	//(13_K32VDSR)-
	{ 297	,1	,1	, &A1AD32LDU},	//(15_K01FDSR)- Обесточить ЭМ ББ1
	{ 298	,1	,1	, &A1AD31LDU},	//(15_K02FDSR)- Клапан «Сброс ББ1» открыть (обесточить)
	{ 299	,1	,1	, &A2AD32LDU},	//(15_K03FDSR)- Обесточить ЭМ РБ1
	{ 300	,1	,1	, &A2AD31LDU},	//(15_K04FDSR)- Клапан «Сброс РБ1» открыть (обесточить)
	{ 301	,1	,1	, &B1AD32LDU},	//(15_K05FDSR)- Обесточить ЭМ ББ2
	{ 302	,1	,1	, &B1AD31LDU},	//(15_K06FDSR)- Клапан «Сброс ББ2» открыть (обесточить)
	{ 303	,1	,1	, &B2AD32LDU},	//(15_K07FDSR)- Обесточить ЭМ РБ2
	{ 304	,1	,1	, &B2AD31LDU},	//(15_K08FDSR)- Клапан «Сброс РБ2» открыть (обесточить)
	{ 305	,1	,1	, &R0AD03LZ1},	//(15_K09FDSR)- (сигнал не подтвержден) Имитация прихода на ВУ ИС (БАЗ1)
	{ 306	,1	,1	, &R0AD04LZ1},	//(15_K10FDSR)- (сигнал не подтвержден) Имитация срабатывания АС II УР. РАД (БАЗ1)
	{ 307	,1	,1	, &R0AD05LZ1},	//(15_K11FDSR)- (сигнал не подтвержден) Имитация ухода с НУП ИС  (БАЗ1)
	{ 308	,1	,1	, &R8AD21LDU},	//(15_K12FDSR)- Запуск системы инициирования
	{ 309	,1	,1	, &R0AD16LDU},	//(15_K13FDSR)- Контроль  I-II УР. РАД
	{ 310	,1	,1	, &R0AD03LZ2},	//(15_K14FDSR)- (сигнал не подтвержден) Имитация прихода на ВУ ИС (БАЗ2)
	{ 311	,1	,1	, &R0AD04LZ2},	//(15_K15FDSR)- (сигнал не подтвержден) Имитация срабатывания АС II УР. РАД (БАЗ2)
	{ 312	,1	,1	, &R0AD05LZ2},	//(15_K16FDSR)- (сигнал не подтвержден) Имитация ухода с НУП ИС  (БАЗ2)
	{-1,0,NULL},
};
static char NameSaveFile[]="savecnst.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_msDUsign[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_msDUsign[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_msDUsign[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_msDUsign[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_msDUsign[0],&di_msDUsign[0],&ir_msDUsign[0],&hr_msDUsign[0],NULL,NULL,NULL,0},	 //DUsign-ModBus

	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3201[66];	//VDS32-01
static vds32r_inipar ini_VDS3201={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3201={0,0,&ini_VDS3201,buf_VDS3201,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3201[]={
	{&R0IC00LDU,1,0},
	{&R0IC01LDU,1,2},
	{&R0IC02LDU,1,4},
	{&R0IC03LDU,1,6},
	{&R0IC04LDU,1,8},
	{&R0IC05LDU,1,10},
	{&R0IC06LDU,1,12},
	{&R0IC07LDU,1,14},
	{&R0IC08LDU,1,16},
	{&R0IC09LDU,1,18},
	{&R0IC10LDU,1,20},
	{&R0IC11LDU,1,22},
	{&R0IC12LDU,1,24},
	{&R0IC13LDU,1,26},
	{&R0IC14LDU,1,28},
	{&R0IC15LDU,1,30},
	{&R0IC16LDU,1,32},
	{&R0IC17LDU,1,34},
	{&R0IC18LDU,1,36},
	{&R0IC19LDU,1,38},
	{&R0IC20LDU,1,40},
	{&R0IC21LDU,1,42},
	{&R0IC22LDU,1,44},
	{&R0IC23LDU,1,46},
	{&R0IC24LDU,1,48},
	{&R0IC25LDU,1,50},
	{&R0IC26LDU,1,52},
	{&R0IC27LDU,1,54},
	{&R0IC28LDU,1,56},
	{&R0IC29LDU,1,58},
	{&R0IC30LDU,1,60},
	{&R0IC31LDU,1,62},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3202[66];	//VDS32-02
static vds32r_inipar ini_VDS3202={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3202={0,0,&ini_VDS3202,buf_VDS3202,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3202[]={
	{&B3IS35LDU,1,0},
	{&B3IS33LDU,1,2},
	{&B2IS33LDU,1,4},
	{&B4IS10LDU,1,6},
	{&B3IS31LDU,1,8},
	{&B7AS31LDU,1,10},
	{&B1IS12LDU,1,12},
	{&B1IS11LDU,1,14},
	{&B1IS21LDU,1,16},
	{&B2IS12LDU,1,18},
	{&B2IS11LDU,1,20},
	{&B2IS21LDU,1,22},
	{&B3IS21LDU,1,24},
	{&R8IS11LDU,1,26},
	{&B8IS12LDU,1,28},
	{&B8IS22LDU,1,30},
	{&s02_K17VDSR,1,32},
	{&A3VZ13LZ1,1,34},
	{&A3VZ15LZ1,1,36},
	{&R0AD14LZ1,1,38},
	{&A1VN71LZ1,1,40},
	{&R0VZ71LZ1,1,42},
	{&A9IS11LDU,1,44},
	{&A9IS21LDU,1,46},
	{&B9IS11LDU,1,48},
	{&B9IS21LDU,1,50},
	{&R1IS11LDU,1,52},
	{&R1IS21LDU,1,54},
	{&R2IS11LDU,1,56},
	{&R2IS21LDU,1,58},
	{&B4IS11LDU,1,60},
	{&B4IS21LDU,1,62},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3203[66];	//VDS32-03
static vds32r_inipar ini_VDS3203={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3203={0,0,&ini_VDS3203,buf_VDS3203,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3203[]={
	{&A3IS35LDU,1,0},
	{&A3IS33LDU,1,2},
	{&A2IS33LDU,1,4},
	{&A4IS10LDU,1,6},
	{&A3IS31LDU,1,8},
	{&A7AS31LDU,1,10},
	{&A1IS12LDU,1,12},
	{&A1IS11LDU,1,14},
	{&A1IS21LDU,1,16},
	{&A2IS12LDU,1,18},
	{&A2IS11LDU,1,20},
	{&A2IS21LDU,1,22},
	{&A3IS21LDU,1,24},
	{&A4IS11LDU,1,26},
	{&A4IS21LDU,1,28},
	{&s03_K16VDSR,1,30},
	{&s03_K17VDSR,1,32},
	{&A3VZ13LZ2,1,34},
	{&A3VZ15LZ2,1,36},
	{&R0AD14LZ2,1,38},
	{&A1VN71LZ2,1,40},
	{&R0VZ71LZ2,1,42},
	{&A3VP81LDU,1,44},
	{&A2VP82LDU,1,46},
	{&A4VP82LDU,1,48},
	{&B3VP81LDU,1,50},
	{&B2VP82LDU,1,52},
	{&B4VP82LDU,1,54},
	{&R0IS01LDU,1,56},
	{&R0IS02LDU,1,58},
	{&s03_K31VDSR,1,60},
	{&s03_K32VDSR,1,62},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3204[66];	//VDS32-04
static vds32r_inipar ini_VDS3204={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3204={0,0,&ini_VDS3204,buf_VDS3204,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3204[]={
	{&A3IS11LDU,1,0},
	{&A3IS22LDU,1,2},
	{&B3IS11LDU,1,4},
	{&B3IS22LDU,1,6},
	{&R4IS11LDU,1,8},
	{&R4IS12LDU,1,10},
	{&R4IS21LDU,1,12},
	{&R4IS22LDU,1,14},
	{&A6IS11LDU,1,16},
	{&A6IS21LDU,1,18},
	{&A5IS11LDU,1,20},
	{&A5IS21LDU,1,22},
	{&B6IS11LDU,1,24},
	{&B6IS21LDU,1,26},
	{&B5IS11LDU,1,28},
	{&B5IS21LDU,1,30},
	{&R3IS11LDU,1,32},
	{&R3IS21LDU,1,34},
	{&R3IS31LDU,1,36},
	{&R3IS41LDU,1,38},
	{&R3AD10LDU,1,40},
	{&R3AD11LDU,1,42},
	{&R3AD20LDU,1,44},
	{&R3AD21LDU,1,46},
	{&R5IS11LDU,1,48},
	{&R5IS21LDU,1,50},
	{&R5AD10LDU,1,52},
	{&R5AD20LDU,1,54},
	{&R6IS21LDU,1,56},
	{&A8IS12LDU,1,58},
	{&A8IS22LDU,1,60},
	{&s04_K32VDSR,1,62},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3205[66];	//VDS32-05
static vds32r_inipar ini_VDS3205={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3205={0,0,&ini_VDS3205,buf_VDS3205,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3205[]={
	{&A1IE02LDU,1,0},
	{&A1IE01LDU,1,2},
	{&A1IE03LDU,1,4},
	{&A1IE04LDU,1,6},
	{&A2IE02LDU,1,8},
	{&A2IE01LDU,1,10},
	{&A2IE03LDU,1,12},
	{&A2IE04LDU,1,14},
	{&A3IE02LDU,1,16},
	{&A3IE01LDU,1,18},
	{&A3IE03LDU,1,20},
	{&A3IE04LDU,1,22},
	{&B1IE02LDU,1,24},
	{&B1IE01LDU,1,26},
	{&B1IE03LDU,1,28},
	{&B1IE04LDU,1,30},
	{&B2IE02LDU,1,32},
	{&B2IE01LDU,1,34},
	{&B2IE03LDU,1,36},
	{&B2IE04LDU,1,38},
	{&B3IE02LDU,1,40},
	{&B3IE01LDU,1,42},
	{&B3IE03LDU,1,44},
	{&B3IE04LDU,1,46},
	{&R6IS31LDU,1,48},
	{&R6IS32LDU,1,50},
	{&R6IS41LDU,1,52},
	{&R6IS42LDU,1,54},
	{&R6IS51LDU,1,56},
	{&R6IS52LDU,1,58},
	{&s05_K31VDSR,1,60},
	{&s05_K32VDSR,1,62},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS1606[40];	//FDS16-06
static fds16r_inipar ini_FDS1606={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1606={0,0,&ini_FDS1606,buf_FDS1606,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1606[]={
	{&A1IC01LDU,1,0},
	{&B1IC01LDU,1,2},
	{&A2IC01LDU,1,4},
	{&B2IC01LDU,1,6},
	{&A3IC01LDU,1,8},
	{&B3IC01LDU,1,10},
	{&B8IC01LDU,1,12},
	{&A8IC01LDU,1,14},
	{&R0IC41LDU,1,16},
	{&s06_K10FDSR,1,18},
	{&s06_K11FDSR,1,20},
	{&s06_K12FDSR,1,22},
	{&s06_K13FDSR,1,24},
	{&s06_K14FDSR,1,26},
	{&s06_K15FDSR,1,28},
	{&s06_K16FDSR,1,30},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS1607[40];	//FDS16-07
static fds16r_inipar ini_FDS1607={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1607={0,0,&ini_FDS1607,buf_FDS1607,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1607[]={
	{&A2AD11LDU,1,0},
	{&A2AD21LDU,1,2},
	{&A2AD01LDU,1,4},
	{&A2AD02LDU,1,6},
	{&A2AD03LDU,1,8},
	{&A2AD04LDU,1,10},
	{&A2AD05LDU,1,12},
	{&B2AD11LDU,1,14},
	{&B2AD21LDU,1,16},
	{&B2AD01LDU,1,18},
	{&B2AD02LDU,1,20},
	{&B2AD03LDU,1,22},
	{&B2AD04LDU,1,24},
	{&B2AD05LDU,1,26},
	{&A2IS12LZ2,1,28},
	{&B2IS12LZ2,1,30},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS1608[40];	//FDS16-08
static fds16r_inipar ini_FDS1608={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1608={0,0,&ini_FDS1608,buf_FDS1608,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1608[]={
	{&A1AD11LDU,1,0},
	{&A1AD21LDU,1,2},
	{&A1AD01LDU,1,4},
	{&A1AD02LDU,1,6},
	{&A1AD03LDU,1,8},
	{&A1AD04LDU,1,10},
	{&A1AD05LDU,1,12},
	{&B1AD11LDU,1,14},
	{&B1AD21LDU,1,16},
	{&B1AD01LDU,1,18},
	{&B1AD02LDU,1,20},
	{&B1AD03LDU,1,22},
	{&B1AD04LDU,1,24},
	{&B1AD05LDU,1,26},
	{&A2IS12LZ1,1,28},
	{&B2IS12LZ1,1,30},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS1609[40];	//FDS16-09
static fds16r_inipar ini_FDS1609={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1609={0,0,&ini_FDS1609,buf_FDS1609,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1609[]={
	{&B3AD34LDU,1,0},
	{&B3AD33LDU,1,2},
	{&B2AD33LDU,1,4},
	{&B4AD10LDU,1,6},
	{&B3AD31LDU,1,8},
	{&B7AP31LDU,1,10},
	{&A8AD10LDU,1,12},
	{&A8AD20LDU,1,14},
	{&A6AD10LDU,1,16},
	{&A6AD20LDU,1,18},
	{&B6AD10LDU,1,20},
	{&B6AD20LDU,1,22},
	{&R4AD10LDU,1,24},
	{&R4AD20LDU,1,26},
	{&B8AD10LDU,1,28},
	{&B8AD20LDU,1,30},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS1610[40];	//FDS16-10
static fds16r_inipar ini_FDS1610={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1610={0,0,&ini_FDS1610,buf_FDS1610,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1610[]={
	{&A3AD34LDU,1,0},
	{&A3AD33LDU,1,2},
	{&A2AD33LDU,1,4},
	{&A4AD10LDU,1,6},
	{&A3AD31LDU,1,8},
	{&A7AP31LDU,1,10},
	{&R1AD10LDU,1,12},
	{&R1AD20LDU,1,14},
	{&R2AD10LDU,1,16},
	{&R2AD20LDU,1,18},
	{&A5AD10LDU,1,20},
	{&A5AD20LDU,1,22},
	{&B5AD10LDU,1,24},
	{&B5AD20LDU,1,26},
	{&s10_K15FDSR,1,28},
	{&s10_K16FDSR,1,30},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS1611[40];	//FDS16-11
static fds16r_inipar ini_FDS1611={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1611={0,0,&ini_FDS1611,buf_FDS1611,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1611[]={
	{&A3AD11LDU,1,0},
	{&A3AD21LDU,1,2},
	{&A3AD01LDU,1,4},
	{&A3AD02LDU,1,6},
	{&A3AD03LDU,1,8},
	{&A3AD04LDU,1,10},
	{&A3AD05LDU,1,12},
	{&B3AD11LDU,1,14},
	{&B3AD21LDU,1,16},
	{&B3AD01LDU,1,18},
	{&B3AD02LDU,1,20},
	{&B3AD03LDU,1,22},
	{&B3AD04LDU,1,24},
	{&B3AD05LDU,1,26},
	{&A9AD10LDU,1,28},
	{&B9AD10LDU,1,30},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vas84r.h>
static char buf_VAS8412[28];	//VAS84-12
static vas84r_inipar ini_VAS8412={0xc6,255,1,8,0xff,0,16,};
#pragma pack(push,1)
static table_drv table_VAS8412={0,0,&ini_VAS8412,buf_VAS8412,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VAS8412[]={
	{&A3IP02IDU,3,0},
	{&B3IP02IDU,3,3},
	{&s12_K03VASR,3,6},
	{&s12_K04VASR,3,9},
	{&s12_K05VASR,3,12},
	{&s12_K06VASR,3,15},
	{&s12_K07VASR,3,18},
	{&s12_K08VASR,3,21},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3213[66];	//VDS32-13
static vds32r_inipar ini_VDS3213={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3213={0,0,&ini_VDS3213,buf_VDS3213,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3213[]={
	{&R6IS61LDU,1,0},
	{&R4VS12LDU,1,2},
	{&R4VS22LDU,1,4},
	{&A8IE01LDU,1,6},
	{&R1VS12LDU,1,8},
	{&R1VS22LDU,1,10},
	{&R1IE01LDU,1,12},
	{&R2VS12LDU,1,14},
	{&R2VS22LDU,1,16},
	{&R2IE01LDU,1,18},
	{&A5VS12LDU,1,20},
	{&A5VS22LDU,1,22},
	{&A5IE02LDU,1,24},
	{&B5VS12LDU,1,26},
	{&B5VS22LDU,1,28},
	{&B5IE01LDU,1,30},
	{&A6VS12LDU,1,32},
	{&A6VS22LDU,1,34},
	{&A6IE01LDU,1,36},
	{&B6VS12LDU,1,38},
	{&B6VS22LDU,1,40},
	{&B6IE01LDU,1,42},
	{&R0IE02LDU,1,44},
	{&R0IE01LDU,1,46},
	{&R6IS62LDU,1,48},
	{&R6IS63LDU,1,50},
	{&R6IS64LDU,1,52},
	{&R6IS65LDU,1,54},
	{&s13_K29VDSR,1,56},
	{&s13_K30VDSR,1,58},
	{&s13_K31VDSR,1,60},
	{&s13_K32VDSR,1,62},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS1615[40];	//FDS16-15
static fds16r_inipar ini_FDS1615={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1615={0,0,&ini_FDS1615,buf_FDS1615,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1615[]={
	{&A1AD32LDU,1,0},
	{&A1AD31LDU,1,2},
	{&A2AD32LDU,1,4},
	{&A2AD31LDU,1,6},
	{&B1AD32LDU,1,8},
	{&B1AD31LDU,1,10},
	{&B2AD32LDU,1,12},
	{&B2AD31LDU,1,14},
	{&R0AD03LZ1,1,16},
	{&R0AD04LZ1,1,18},
	{&R0AD05LZ1,1,20},
	{&R8AD21LDU,1,22},
	{&R0AD16LDU,1,24},
	{&R0AD03LZ2,1,26},
	{&R0AD04LZ2,1,28},
	{&R0AD05LZ2,1,30},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0xc2,0x01,15,66,def_buf_VDS3201,&table_VDS3201}, //VDS32-01
	{0xc2,0x02,15,66,def_buf_VDS3202,&table_VDS3202}, //VDS32-02
	{0xc2,0x03,15,66,def_buf_VDS3203,&table_VDS3203}, //VDS32-03
	{0xc2,0x04,15,66,def_buf_VDS3204,&table_VDS3204}, //VDS32-04
	{0xc2,0x05,15,66,def_buf_VDS3205,&table_VDS3205}, //VDS32-05
	{0x96,0x06,20,40,def_buf_FDS1606,&table_FDS1606}, //FDS16-06
	{0x96,0x07,20,40,def_buf_FDS1607,&table_FDS1607}, //FDS16-07
	{0x96,0x08,20,40,def_buf_FDS1608,&table_FDS1608}, //FDS16-08
	{0x96,0x09,20,40,def_buf_FDS1609,&table_FDS1609}, //FDS16-09
	{0x96,0x0a,20,40,def_buf_FDS1610,&table_FDS1610}, //FDS16-10
	{0x96,0x0b,20,40,def_buf_FDS1611,&table_FDS1611}, //FDS16-11
	{0xc6,0x0c,7,28,def_buf_VAS8412,&table_VAS8412}, //VAS84-12
	{0xc2,0x0d,15,66,def_buf_VDS3213,&table_VDS3213}, //VDS32-13
	{0x96,0x0f,20,40,def_buf_FDS1615,&table_FDS1615}, //FDS16-15
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
}
void Scheme(void)
{
}
#endif
