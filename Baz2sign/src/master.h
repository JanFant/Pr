#ifndef BAZ2SIGN_H
#define BAZ2SIGN_H
// Подсистема Baz2sign:Baz2sign
static char SimulOn=0;
static short CodeSub=13;
static char SimulIP[]="192.168.10.247\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 312
static char BUFFER[312];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.54\0", 5432, "192.168.10.154\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define A0IT02IZ2	 BUFFER[0]	//(K01VASR)- Температура АЗ1-2
#define idA0IT02IZ2	 1	//(K01VASR)- Температура АЗ1-2
#define A2IP01IZ2	 BUFFER[3]	//(K02VASR)- Текущее давление СБРОС РБ1
#define idA2IP01IZ2	 2	//(K02VASR)- Текущее давление СБРОС РБ1
#define B0IT02IZ2	 BUFFER[6]	//(K03VASR)- Температура АЗ2-2
#define idB0IT02IZ2	 3	//(K03VASR)- Температура АЗ2-2
#define B2IP01IZ2	 BUFFER[9]	//(K04VASR)- Текущее давление СБРОС РБ2
#define idB2IP01IZ2	 4	//(K04VASR)- Текущее давление СБРОС РБ2
#define s04_K05VASR	 BUFFER[12]	//(K05VASR)- 
#define ids04_K05VASR	 5	//(K05VASR)- 
#define s04_K06VASR	 BUFFER[15]	//(K06VASR)- 
#define ids04_K06VASR	 6	//(K06VASR)- 
#define s04_K07VASR	 BUFFER[18]	//(K07VASR)- 
#define ids04_K07VASR	 7	//(K07VASR)- 
#define s04_K08VASR	 BUFFER[21]	//(K08VASR)- 
#define ids04_K08VASR	 8	//(K08VASR)- 
#define R0VN71LZ2	 BUFFER[24]	//(s05_K01VDSR)- АС по мощности канал 1
#define idR0VN71LZ2	 9	//(s05_K01VDSR)- АС по мощности канал 1
#define R0VN75LZ2	 BUFFER[26]	//(s05_K02VDSR)- АС по периоду разгона канал  1
#define idR0VN75LZ2	 10	//(s05_K02VDSR)- АС по периоду разгона канал  1
#define A1EE01LS1	 BUFFER[28]	//(s05_K03VDSR)- Исправность АКНП канал 1
#define idA1EE01LS1	 11	//(s05_K03VDSR)- Исправность АКНП канал 1
#define A1VN71LS1	 BUFFER[30]	//(s05_K04VDSR)- Блокировка автоматического подъёма ББ канал 1
#define idA1VN71LS1	 12	//(s05_K04VDSR)- Блокировка автоматического подъёма ББ канал 1
#define A3IS11LZ2	 BUFFER[32]	//(s05_K05VDSR)- Приход на ВУ ИС1
#define idA3IS11LZ2	 13	//(s05_K05VDSR)- Приход на ВУ ИС1
#define A3IS22LZ2	 BUFFER[34]	//(s05_K06VDSR)- Приход на НУП ИС1
#define idA3IS22LZ2	 14	//(s05_K06VDSR)- Приход на НУП ИС1
#define R0AD03LZ2	 BUFFER[36]	//(s05_K07VDSR)- Имитация прихода на ВУ ИС
#define idR0AD03LZ2	 15	//(s05_K07VDSR)- Имитация прихода на ВУ ИС
#define R0AD04LZ2	 BUFFER[38]	//(s05_K08VDSR)- Имитация срабатывания верхней АС  II УР
#define idR0AD04LZ2	 16	//(s05_K08VDSR)- Имитация срабатывания верхней АС  II УР
#define R0AD05LZ2	 BUFFER[40]	//(s05_K09VDSR)- Имитация ухода с НУП ИС
#define idR0AD05LZ2	 17	//(s05_K09VDSR)- Имитация ухода с НУП ИС
#define A2IS12LZ2	 BUFFER[42]	//(s05_K10VDSR)- Магнит РБ1 зацеплен (для БАЗ2)
#define idA2IS12LZ2	 18	//(s05_K10VDSR)- Магнит РБ1 зацеплен (для БАЗ2)
#define B2IS12LZ2	 BUFFER[44]	//(s05_K11VDSR)- Магнит РБ2 зацеплен (для БАЗ2)
#define idB2IS12LZ2	 19	//(s05_K11VDSR)- Магнит РБ2 зацеплен (для БАЗ2)
#define s05_K12VDSR	 BUFFER[46]	//(s05_K12VDSR)- 
#define ids05_K12VDSR	 20	//(s05_K12VDSR)- 
#define s05_K13VDSR	 BUFFER[48]	//(s05_K13VDSR)- 
#define ids05_K13VDSR	 21	//(s05_K13VDSR)- 
#define s05_K14VDSR	 BUFFER[50]	//(s05_K14VDSR)- 
#define ids05_K14VDSR	 22	//(s05_K14VDSR)- 
#define s05_K15VDSR	 BUFFER[52]	//(s05_K15VDSR)- 
#define ids05_K15VDSR	 23	//(s05_K15VDSR)- 
#define s05_K16VDSR	 BUFFER[54]	//(s05_K16VDSR)- 
#define ids05_K16VDSR	 24	//(s05_K16VDSR)- 
#define s05_K17VDSR	 BUFFER[56]	//(s05_K17VDSR)- 
#define ids05_K17VDSR	 25	//(s05_K17VDSR)- 
#define s05_K18VDSR	 BUFFER[58]	//(s05_K18VDSR)- 
#define ids05_K18VDSR	 26	//(s05_K18VDSR)- 
#define s05_K19VDSR	 BUFFER[60]	//(s05_K19VDSR)- 
#define ids05_K19VDSR	 27	//(s05_K19VDSR)- 
#define s05_K20VDSR	 BUFFER[62]	//(s05_K20VDSR)- 
#define ids05_K20VDSR	 28	//(s05_K20VDSR)- 
#define s05_K21VDSR	 BUFFER[64]	//(s05_K21VDSR)- 
#define ids05_K21VDSR	 29	//(s05_K21VDSR)- 
#define s05_K22VDSR	 BUFFER[66]	//(s05_K22VDSR)- 
#define ids05_K22VDSR	 30	//(s05_K22VDSR)- 
#define s05_K23VDSR	 BUFFER[68]	//(s05_K23VDSR)- 
#define ids05_K23VDSR	 31	//(s05_K23VDSR)- 
#define s05_K24VDSR	 BUFFER[70]	//(s05_K24VDSR)- 
#define ids05_K24VDSR	 32	//(s05_K24VDSR)- 
#define s05_K25VDSR	 BUFFER[72]	//(s05_K25VDSR)- 
#define ids05_K25VDSR	 33	//(s05_K25VDSR)- 
#define s05_K26VDSR	 BUFFER[74]	//(s05_K26VDSR)- 
#define ids05_K26VDSR	 34	//(s05_K26VDSR)- 
#define s05_K27VDSR	 BUFFER[76]	//(s05_K27VDSR)- 
#define ids05_K27VDSR	 35	//(s05_K27VDSR)- 
#define s05_K28VDSR	 BUFFER[78]	//(s05_K28VDSR)- 
#define ids05_K28VDSR	 36	//(s05_K28VDSR)- 
#define s05_K29VDSR	 BUFFER[80]	//(s05_K29VDSR)- 
#define ids05_K29VDSR	 37	//(s05_K29VDSR)- 
#define s05_K30VDSR	 BUFFER[82]	//(s05_K30VDSR)- 
#define ids05_K30VDSR	 38	//(s05_K30VDSR)- 
#define s05_K31VDSR	 BUFFER[84]	//(s05_K31VDSR)- 
#define ids05_K31VDSR	 39	//(s05_K31VDSR)- 
#define s05_K32VDSR	 BUFFER[86]	//(s05_K32VDSR)- 
#define ids05_K32VDSR	 40	//(s05_K32VDSR)- 
#define R0VN72LZ2	 BUFFER[88]	//(s06_K01VDSR)- АС по мощности канал 2
#define idR0VN72LZ2	 41	//(s06_K01VDSR)- АС по мощности канал 2
#define R0VN76LZ2	 BUFFER[90]	//(s06_K02VDSR)- АС по периоду разгона канал  2
#define idR0VN76LZ2	 42	//(s06_K02VDSR)- АС по периоду разгона канал  2
#define A1EE01LS2	 BUFFER[92]	//(s06_K03VDSR)- Исправность АКНП  канал 2
#define idA1EE01LS2	 43	//(s06_K03VDSR)- Исправность АКНП  канал 2
#define A1VN71LS2	 BUFFER[94]	//(s06_K04VDSR)- Блокировка автоматического подъёма ББ канал 2
#define idA1VN71LS2	 44	//(s06_K04VDSR)- Блокировка автоматического подъёма ББ канал 2
#define B3IS11LZ2	 BUFFER[96]	//(s06_K05VDSR)- Приход на ВУ ИС2
#define idB3IS11LZ2	 45	//(s06_K05VDSR)- Приход на ВУ ИС2
#define B3IS22LZ2	 BUFFER[98]	//(s06_K06VDSR)- Приход на НУП ИС2
#define idB3IS22LZ2	 46	//(s06_K06VDSR)- Приход на НУП ИС2
#define s06_K07VDSR	 BUFFER[100]	//(s06_K07VDSR)- 
#define ids06_K07VDSR	 47	//(s06_K07VDSR)- 
#define s06_K08VDSR	 BUFFER[102]	//(s06_K08VDSR)- 
#define ids06_K08VDSR	 48	//(s06_K08VDSR)- 
#define s06_K09VDSR	 BUFFER[104]	//(s06_K09VDSR)- 
#define ids06_K09VDSR	 49	//(s06_K09VDSR)- 
#define s06_K10VDSR	 BUFFER[106]	//(s06_K10VDSR)- 
#define ids06_K10VDSR	 50	//(s06_K10VDSR)- 
#define s06_K11VDSR	 BUFFER[108]	//(s06_K11VDSR)- 
#define ids06_K11VDSR	 51	//(s06_K11VDSR)- 
#define s06_K12VDSR	 BUFFER[110]	//(s06_K12VDSR)- 
#define ids06_K12VDSR	 52	//(s06_K12VDSR)- 
#define s06_K13VDSR	 BUFFER[112]	//(s06_K13VDSR)- 
#define ids06_K13VDSR	 53	//(s06_K13VDSR)- 
#define s06_K14VDSR	 BUFFER[114]	//(s06_K14VDSR)- 
#define ids06_K14VDSR	 54	//(s06_K14VDSR)- 
#define s06_K15VDSR	 BUFFER[116]	//(s06_K15VDSR)- 
#define ids06_K15VDSR	 55	//(s06_K15VDSR)- 
#define s06_K16VDSR	 BUFFER[118]	//(s06_K16VDSR)- 
#define ids06_K16VDSR	 56	//(s06_K16VDSR)- 
#define s06_K17VDSR	 BUFFER[120]	//(s06_K17VDSR)- 
#define ids06_K17VDSR	 57	//(s06_K17VDSR)- 
#define s06_K18VDSR	 BUFFER[122]	//(s06_K18VDSR)- 
#define ids06_K18VDSR	 58	//(s06_K18VDSR)- 
#define s06_K19VDSR	 BUFFER[124]	//(s06_K19VDSR)- 
#define ids06_K19VDSR	 59	//(s06_K19VDSR)- 
#define s06_K20VDSR	 BUFFER[126]	//(s06_K20VDSR)- 
#define ids06_K20VDSR	 60	//(s06_K20VDSR)- 
#define s06_K21VDSR	 BUFFER[128]	//(s06_K21VDSR)- 
#define ids06_K21VDSR	 61	//(s06_K21VDSR)- 
#define s06_K22VDSR	 BUFFER[130]	//(s06_K22VDSR)- 
#define ids06_K22VDSR	 62	//(s06_K22VDSR)- 
#define s06_K23VDSR	 BUFFER[132]	//(s06_K23VDSR)- 
#define ids06_K23VDSR	 63	//(s06_K23VDSR)- 
#define s06_K24VDSR	 BUFFER[134]	//(s06_K24VDSR)- 
#define ids06_K24VDSR	 64	//(s06_K24VDSR)- 
#define s06_K25VDSR	 BUFFER[136]	//(s06_K25VDSR)- 
#define ids06_K25VDSR	 65	//(s06_K25VDSR)- 
#define s06_K26VDSR	 BUFFER[138]	//(s06_K26VDSR)- 
#define ids06_K26VDSR	 66	//(s06_K26VDSR)- 
#define s06_K27VDSR	 BUFFER[140]	//(s06_K27VDSR)- 
#define ids06_K27VDSR	 67	//(s06_K27VDSR)- 
#define s06_K28VDSR	 BUFFER[142]	//(s06_K28VDSR)- 
#define ids06_K28VDSR	 68	//(s06_K28VDSR)- 
#define s06_K29VDSR	 BUFFER[144]	//(s06_K29VDSR)- 
#define ids06_K29VDSR	 69	//(s06_K29VDSR)- 
#define s06_K30VDSR	 BUFFER[146]	//(s06_K30VDSR)- 
#define ids06_K30VDSR	 70	//(s06_K30VDSR)- 
#define s06_K31VDSR	 BUFFER[148]	//(s06_K31VDSR)- 
#define ids06_K31VDSR	 71	//(s06_K31VDSR)- 
#define s06_K32VDSR	 BUFFER[150]	//(s06_K32VDSR)- 
#define ids06_K32VDSR	 72	//(s06_K32VDSR)- 
#define R0VN74LZ2	 BUFFER[152]	//(s07_K01VDSR)- АС по мощности канал 4
#define idR0VN74LZ2	 73	//(s07_K01VDSR)- АС по мощности канал 4
#define R0VN78LZ2	 BUFFER[154]	//(s07_K02VDSR)- АС по периоду разгона канал  4
#define idR0VN78LZ2	 74	//(s07_K02VDSR)- АС по периоду разгона канал  4
#define A1EE01LS4	 BUFFER[156]	//(s07_K03VDSR)- Исправность АКНП канал 4
#define idA1EE01LS4	 75	//(s07_K03VDSR)- Исправность АКНП канал 4
#define A1VN71LS4	 BUFFER[158]	//(s07_K04VDSR)- Блокировка автоматического подъёма ББ канал 4
#define idA1VN71LS4	 76	//(s07_K04VDSR)- Блокировка автоматического подъёма ББ канал 4
#define R6IS66LZ2	 BUFFER[160]	//(s07_K05VDSR)- Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZ2	 77	//(s07_K05VDSR)- Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZ2	 BUFFER[162]	//(s07_K06VDSR)- Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZ2	 78	//(s07_K06VDSR)- Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZ2	 BUFFER[164]	//(s07_K07VDSR)- Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZ2	 79	//(s07_K07VDSR)- Исправность ВИП 4,0 (№7) ССДИ-2
#define s07_K08VDSR	 BUFFER[166]	//(s07_K08VDSR)- 
#define ids07_K08VDSR	 80	//(s07_K08VDSR)- 
#define s07_K09VDSR	 BUFFER[168]	//(s07_K09VDSR)- 
#define ids07_K09VDSR	 81	//(s07_K09VDSR)- 
#define s07_K10VDSR	 BUFFER[170]	//(s07_K10VDSR)- 
#define ids07_K10VDSR	 82	//(s07_K10VDSR)- 
#define s07_K11VDSR	 BUFFER[172]	//(s07_K11VDSR)- 
#define ids07_K11VDSR	 83	//(s07_K11VDSR)- 
#define s07_K12VDSR	 BUFFER[174]	//(s07_K12VDSR)- 
#define ids07_K12VDSR	 84	//(s07_K12VDSR)- 
#define s07_K13VDSR	 BUFFER[176]	//(s07_K13VDSR)- 
#define ids07_K13VDSR	 85	//(s07_K13VDSR)- 
#define s07_K14VDSR	 BUFFER[178]	//(s07_K14VDSR)- 
#define ids07_K14VDSR	 86	//(s07_K14VDSR)- 
#define s07_K15VDSR	 BUFFER[180]	//(s07_K15VDSR)- 
#define ids07_K15VDSR	 87	//(s07_K15VDSR)- 
#define s07_K16VDSR	 BUFFER[182]	//(s07_K16VDSR)- 
#define ids07_K16VDSR	 88	//(s07_K16VDSR)- 
#define s07_K17VDSR	 BUFFER[184]	//(s07_K17VDSR)- 
#define ids07_K17VDSR	 89	//(s07_K17VDSR)- 
#define s07_K18VDSR	 BUFFER[186]	//(s07_K18VDSR)- 
#define ids07_K18VDSR	 90	//(s07_K18VDSR)- 
#define s07_K19VDSR	 BUFFER[188]	//(s07_K19VDSR)- 
#define ids07_K19VDSR	 91	//(s07_K19VDSR)- 
#define s07_K20VDSR	 BUFFER[190]	//(s07_K20VDSR)- 
#define ids07_K20VDSR	 92	//(s07_K20VDSR)- 
#define s07_K21VDSR	 BUFFER[192]	//(s07_K21VDSR)- 
#define ids07_K21VDSR	 93	//(s07_K21VDSR)- 
#define s07_K22VDSR	 BUFFER[194]	//(s07_K22VDSR)- 
#define ids07_K22VDSR	 94	//(s07_K22VDSR)- 
#define s07_K23VDSR	 BUFFER[196]	//(s07_K23VDSR)- 
#define ids07_K23VDSR	 95	//(s07_K23VDSR)- 
#define s07_K24VDSR	 BUFFER[198]	//(s07_K24VDSR)- 
#define ids07_K24VDSR	 96	//(s07_K24VDSR)- 
#define s07_K25VDSR	 BUFFER[200]	//(s07_K25VDSR)- 
#define ids07_K25VDSR	 97	//(s07_K25VDSR)- 
#define s07_K26VDSR	 BUFFER[202]	//(s07_K26VDSR)- 
#define ids07_K26VDSR	 98	//(s07_K26VDSR)- 
#define s07_K27VDSR	 BUFFER[204]	//(s07_K27VDSR)- 
#define ids07_K27VDSR	 99	//(s07_K27VDSR)- 
#define s07_K28VDSR	 BUFFER[206]	//(s07_K28VDSR)- 
#define ids07_K28VDSR	 100	//(s07_K28VDSR)- 
#define s07_K29VDSR	 BUFFER[208]	//(s07_K29VDSR)- 
#define ids07_K29VDSR	 101	//(s07_K29VDSR)- 
#define s07_K30VDSR	 BUFFER[210]	//(s07_K30VDSR)- 
#define ids07_K30VDSR	 102	//(s07_K30VDSR)- 
#define s07_K31VDSR	 BUFFER[212]	//(s07_K31VDSR)- 
#define ids07_K31VDSR	 103	//(s07_K31VDSR)- 
#define s07_K32VDSR	 BUFFER[214]	//(s07_K32VDSR)- 
#define ids07_K32VDSR	 104	//(s07_K32VDSR)- 
#define R0VN73LZ2	 BUFFER[216]	//(s08_K01VDSR)- АС по мощности канал 3
#define idR0VN73LZ2	 105	//(s08_K01VDSR)- АС по мощности канал 3
#define R0VN77LZ2	 BUFFER[218]	//(s08_K02VDSR)- АС по периоду разгона канал  3
#define idR0VN77LZ2	 106	//(s08_K02VDSR)- АС по периоду разгона канал  3
#define A1EE01LS3	 BUFFER[220]	//(s08_K03VDSR)- Исправность АКНП канал 3
#define idA1EE01LS3	 107	//(s08_K03VDSR)- Исправность АКНП канал 3
#define A1VN71LS3	 BUFFER[222]	//(s08_K04VDSR)- Блокировка автоматического подъёма ББ канал 3
#define idA1VN71LS3	 108	//(s08_K04VDSR)- Блокировка автоматического подъёма ББ канал 3
#define R7II71LZ2	 BUFFER[224]	//(s08_K05VDSR)- Сработала АС IУР (датчик 1)
#define idR7II71LZ2	 109	//(s08_K05VDSR)- Сработала АС IУР (датчик 1)
#define R7II72LZ2	 BUFFER[226]	//(s08_K06VDSR)- Сработала АС IУР (датчик 2)
#define idR7II72LZ2	 110	//(s08_K06VDSR)- Сработала АС IУР (датчик 2)
#define R7II73LZ2	 BUFFER[228]	//(s08_K07VDSR)- Сработала АС IIУР
#define idR7II73LZ2	 111	//(s08_K07VDSR)- Сработала АС IIУР
#define s08_K08VDSR	 BUFFER[230]	//(s08_K08VDSR)- 
#define ids08_K08VDSR	 112	//(s08_K08VDSR)- 
#define A0VP81LZ2	 BUFFER[232]	//(s08_K09VDSR)- Давление  АЗ1 в норме
#define idA0VP81LZ2	 113	//(s08_K09VDSR)- Давление  АЗ1 в норме
#define A1VP81LZ2	 BUFFER[234]	//(s08_K10VDSR)- Давление СБРОС ББ1 в норме
#define idA1VP81LZ2	 114	//(s08_K10VDSR)- Давление СБРОС ББ1 в норме
#define R0VP81LZ2	 BUFFER[236]	//(s08_K11VDSR)- Давление  в СИСТЕМЕ -1 в норме
#define idR0VP81LZ2	 115	//(s08_K11VDSR)- Давление  в СИСТЕМЕ -1 в норме
#define B0VP81LZ2	 BUFFER[238]	//(s08_K12VDSR)- Давление АЗ2 в норме
#define idB0VP81LZ2	 116	//(s08_K12VDSR)- Давление АЗ2 в норме
#define B1VP81LZ2	 BUFFER[240]	//(s08_K13VDSR)- Давление СБРОС ББ2 в норме
#define idB1VP81LZ2	 117	//(s08_K13VDSR)- Давление СБРОС ББ2 в норме
#define R0VP82LZ2	 BUFFER[242]	//(s08_K14VDSR)- Давление  в СИСТЕМЕ - 2 в норме
#define idR0VP82LZ2	 118	//(s08_K14VDSR)- Давление  в СИСТЕМЕ - 2 в норме
#define s08_K15VDSR	 BUFFER[244]	//(s08_K15VDSR)-
#define ids08_K15VDSR	 119	//(s08_K15VDSR)-
#define s08_K16VDSR	 BUFFER[246]	//(s08_K16VDSR)-
#define ids08_K16VDSR	 120	//(s08_K16VDSR)-
#define s08_K17VDSR	 BUFFER[248]	//(s08_K17VDSR)-
#define ids08_K17VDSR	 121	//(s08_K17VDSR)-
#define s08_K18VDSR	 BUFFER[250]	//(s08_K18VDSR)-
#define ids08_K18VDSR	 122	//(s08_K18VDSR)-
#define s08_K19VDSR	 BUFFER[252]	//(s08_K19VDSR)-
#define ids08_K19VDSR	 123	//(s08_K19VDSR)-
#define s08_K20VDSR	 BUFFER[254]	//(s08_K20VDSR)-
#define ids08_K20VDSR	 124	//(s08_K20VDSR)-
#define s08_K21VDSR	 BUFFER[256]	//(s08_K21VDSR)-
#define ids08_K21VDSR	 125	//(s08_K21VDSR)-
#define s08_K22VDSR	 BUFFER[258]	//(s08_K22VDSR)-
#define ids08_K22VDSR	 126	//(s08_K22VDSR)-
#define s08_K23VDSR	 BUFFER[260]	//(s08_K23VDSR)-
#define ids08_K23VDSR	 127	//(s08_K23VDSR)-
#define s08_K24VDSR	 BUFFER[262]	//(s08_K24VDSR)-
#define ids08_K24VDSR	 128	//(s08_K24VDSR)-
#define s08_K25VDSR	 BUFFER[264]	//(s08_K25VDSR)-
#define ids08_K25VDSR	 129	//(s08_K25VDSR)-
#define s08_K26VDSR	 BUFFER[266]	//(s08_K26VDSR)-
#define ids08_K26VDSR	 130	//(s08_K26VDSR)-
#define s08_K27VDSR	 BUFFER[268]	//(s08_K27VDSR)-
#define ids08_K27VDSR	 131	//(s08_K27VDSR)-
#define s08_K28VDSR	 BUFFER[270]	//(s08_K28VDSR)-
#define ids08_K28VDSR	 132	//(s08_K28VDSR)-
#define s08_K29VDSR	 BUFFER[272]	//(s08_K29VDSR)-
#define ids08_K29VDSR	 133	//(s08_K29VDSR)-
#define s08_K30VDSR	 BUFFER[274]	//(s08_K30VDSR)-
#define ids08_K30VDSR	 134	//(s08_K30VDSR)-
#define s08_K31VDSR	 BUFFER[276]	//(s08_K31VDSR)-
#define ids08_K31VDSR	 135	//(s08_K31VDSR)-
#define s08_K32VDSR	 BUFFER[278]	//(s08_K32VDSR)-
#define ids08_K32VDSR	 136	//(s08_K32VDSR)-
#define A3VZ13LZ2	 BUFFER[280]	//(s10_K01FDSR)- Имитация АЗ от ВУ ИС
#define idA3VZ13LZ2	 137	//(s10_K01FDSR)- Имитация АЗ от ВУ ИС
#define A3VZ15LZ2	 BUFFER[282]	//(s10_K02FDSR)- Имитация АЗ от НУП ИС
#define idA3VZ15LZ2	 138	//(s10_K02FDSR)- Имитация АЗ от НУП ИС
#define R0AD14LZ2	 BUFFER[284]	//(s10_K03FDSR)- Имитация АЗ от IIУР
#define idR0AD14LZ2	 139	//(s10_K03FDSR)- Имитация АЗ от IIУР
#define A1VN71LZ2	 BUFFER[286]	//(s10_K04FDSR)- Блокировка автоматического подъёма ББ
#define idA1VN71LZ2	 140	//(s10_K04FDSR)- Блокировка автоматического подъёма ББ
#define R0VZ71LZ2	 BUFFER[288]	//(s10_K05FDSR)- Обобщенный сигнал АЗ2 канала
#define idR0VZ71LZ2	 141	//(s10_K05FDSR)- Обобщенный сигнал АЗ2 канала
#define OEBB1Z2	 BUFFER[290]	//(s10_K06FDSR)- Обесточивание ЭМ ББ1 и ЭПК ББ1
#define idOEBB1Z2	 142	//(s10_K06FDSR)- Обесточивание ЭМ ББ1 и ЭПК ББ1
#define OEBB2Z2	 BUFFER[292]	//(s10_K07FDSR)- Обесточивание ЭМ ББ2 и ЭПК ББ2
#define idOEBB2Z2	 143	//(s10_K07FDSR)- Обесточивание ЭМ ББ2 и ЭПК ББ2
#define OERB1Z2	 BUFFER[294]	//(s10_K08FDSR)- Обесточивание ЭМ РБ1 и ЭПК РБ1
#define idOERB1Z2	 144	//(s10_K08FDSR)- Обесточивание ЭМ РБ1 и ЭПК РБ1
#define OERB2Z2	 BUFFER[296]	//(s10_K09FDSR)- Обесточивание ЭМ РБ2 и ЭПК РБ2
#define idOERB2Z2	 145	//(s10_K09FDSR)- Обесточивание ЭМ РБ2 и ЭПК РБ2
#define B3IS11LDU	 BUFFER[298]	//(s10_K10FDSR)- Приход на ВУ ИС2 для ДУ
#define idB3IS11LDU	 146	//(s10_K10FDSR)- Приход на ВУ ИС2 для ДУ
#define B3IS22LDU	 BUFFER[300]	//(s10_K11FDSR)- Приход на НУП ИС2 для ДУ
#define idB3IS22LDU	 147	//(s10_K11FDSR)- Приход на НУП ИС2 для ДУ
#define B3IS11LZ1	 BUFFER[302]	//(s10_K12FDSR)- Приход на ВУ ИС2 для УСБ1
#define idB3IS11LZ1	 148	//(s10_K12FDSR)- Приход на ВУ ИС2 для УСБ1
#define B3IS22LZ1	 BUFFER[304]	//(s10_K13FDSR)- Приход на НУП ИС2 для УСБ1
#define idB3IS22LZ1	 149	//(s10_K13FDSR)- Приход на НУП ИС2 для УСБ1
#define B0VP81LZ1	 BUFFER[306]	//(s10_K14FDSR)- Давление  АЗ2 в норме для УСБ1
#define idB0VP81LZ1	 150	//(s10_K14FDSR)- Давление  АЗ2 в норме для УСБ1
#define B1VP81LZ1	 BUFFER[308]	//(s10_K15FDSR)- Давление СБРОС ББ2 в норме для УСБ1
#define idB1VP81LZ1	 151	//(s10_K15FDSR)- Давление СБРОС ББ2 в норме для УСБ1
#define s10_K16FDSR	 BUFFER[310]	//(s10_K16FDSR)- 
#define ids10_K16FDSR	 152	//(s10_K16FDSR)- 
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,3	,1	, &A0IT02IZ2},	//(K01VASR)- Температура АЗ1-2
	{ 2	,3	,1	, &A2IP01IZ2},	//(K02VASR)- Текущее давление СБРОС РБ1
	{ 3	,3	,1	, &B0IT02IZ2},	//(K03VASR)- Температура АЗ2-2
	{ 4	,3	,1	, &B2IP01IZ2},	//(K04VASR)- Текущее давление СБРОС РБ2
	{ 5	,3	,1	, &s04_K05VASR},	//(K05VASR)- 
	{ 6	,3	,1	, &s04_K06VASR},	//(K06VASR)- 
	{ 7	,3	,1	, &s04_K07VASR},	//(K07VASR)- 
	{ 8	,3	,1	, &s04_K08VASR},	//(K08VASR)- 
	{ 9	,1	,1	, &R0VN71LZ2},	//(s05_K01VDSR)- АС по мощности канал 1
	{ 10	,1	,1	, &R0VN75LZ2},	//(s05_K02VDSR)- АС по периоду разгона канал  1
	{ 11	,1	,1	, &A1EE01LS1},	//(s05_K03VDSR)- Исправность АКНП канал 1
	{ 12	,1	,1	, &A1VN71LS1},	//(s05_K04VDSR)- Блокировка автоматического подъёма ББ канал 1
	{ 13	,1	,1	, &A3IS11LZ2},	//(s05_K05VDSR)- Приход на ВУ ИС1
	{ 14	,1	,1	, &A3IS22LZ2},	//(s05_K06VDSR)- Приход на НУП ИС1
	{ 15	,1	,1	, &R0AD03LZ2},	//(s05_K07VDSR)- Имитация прихода на ВУ ИС
	{ 16	,1	,1	, &R0AD04LZ2},	//(s05_K08VDSR)- Имитация срабатывания верхней АС  II УР
	{ 17	,1	,1	, &R0AD05LZ2},	//(s05_K09VDSR)- Имитация ухода с НУП ИС
	{ 18	,1	,1	, &A2IS12LZ2},	//(s05_K10VDSR)- Магнит РБ1 зацеплен (для БАЗ2)
	{ 19	,1	,1	, &B2IS12LZ2},	//(s05_K11VDSR)- Магнит РБ2 зацеплен (для БАЗ2)
	{ 20	,1	,1	, &s05_K12VDSR},	//(s05_K12VDSR)- 
	{ 21	,1	,1	, &s05_K13VDSR},	//(s05_K13VDSR)- 
	{ 22	,1	,1	, &s05_K14VDSR},	//(s05_K14VDSR)- 
	{ 23	,1	,1	, &s05_K15VDSR},	//(s05_K15VDSR)- 
	{ 24	,1	,1	, &s05_K16VDSR},	//(s05_K16VDSR)- 
	{ 25	,1	,1	, &s05_K17VDSR},	//(s05_K17VDSR)- 
	{ 26	,1	,1	, &s05_K18VDSR},	//(s05_K18VDSR)- 
	{ 27	,1	,1	, &s05_K19VDSR},	//(s05_K19VDSR)- 
	{ 28	,1	,1	, &s05_K20VDSR},	//(s05_K20VDSR)- 
	{ 29	,1	,1	, &s05_K21VDSR},	//(s05_K21VDSR)- 
	{ 30	,1	,1	, &s05_K22VDSR},	//(s05_K22VDSR)- 
	{ 31	,1	,1	, &s05_K23VDSR},	//(s05_K23VDSR)- 
	{ 32	,1	,1	, &s05_K24VDSR},	//(s05_K24VDSR)- 
	{ 33	,1	,1	, &s05_K25VDSR},	//(s05_K25VDSR)- 
	{ 34	,1	,1	, &s05_K26VDSR},	//(s05_K26VDSR)- 
	{ 35	,1	,1	, &s05_K27VDSR},	//(s05_K27VDSR)- 
	{ 36	,1	,1	, &s05_K28VDSR},	//(s05_K28VDSR)- 
	{ 37	,1	,1	, &s05_K29VDSR},	//(s05_K29VDSR)- 
	{ 38	,1	,1	, &s05_K30VDSR},	//(s05_K30VDSR)- 
	{ 39	,1	,1	, &s05_K31VDSR},	//(s05_K31VDSR)- 
	{ 40	,1	,1	, &s05_K32VDSR},	//(s05_K32VDSR)- 
	{ 41	,1	,1	, &R0VN72LZ2},	//(s06_K01VDSR)- АС по мощности канал 2
	{ 42	,1	,1	, &R0VN76LZ2},	//(s06_K02VDSR)- АС по периоду разгона канал  2
	{ 43	,1	,1	, &A1EE01LS2},	//(s06_K03VDSR)- Исправность АКНП  канал 2
	{ 44	,1	,1	, &A1VN71LS2},	//(s06_K04VDSR)- Блокировка автоматического подъёма ББ канал 2
	{ 45	,1	,1	, &B3IS11LZ2},	//(s06_K05VDSR)- Приход на ВУ ИС2
	{ 46	,1	,1	, &B3IS22LZ2},	//(s06_K06VDSR)- Приход на НУП ИС2
	{ 47	,1	,1	, &s06_K07VDSR},	//(s06_K07VDSR)- 
	{ 48	,1	,1	, &s06_K08VDSR},	//(s06_K08VDSR)- 
	{ 49	,1	,1	, &s06_K09VDSR},	//(s06_K09VDSR)- 
	{ 50	,1	,1	, &s06_K10VDSR},	//(s06_K10VDSR)- 
	{ 51	,1	,1	, &s06_K11VDSR},	//(s06_K11VDSR)- 
	{ 52	,1	,1	, &s06_K12VDSR},	//(s06_K12VDSR)- 
	{ 53	,1	,1	, &s06_K13VDSR},	//(s06_K13VDSR)- 
	{ 54	,1	,1	, &s06_K14VDSR},	//(s06_K14VDSR)- 
	{ 55	,1	,1	, &s06_K15VDSR},	//(s06_K15VDSR)- 
	{ 56	,1	,1	, &s06_K16VDSR},	//(s06_K16VDSR)- 
	{ 57	,1	,1	, &s06_K17VDSR},	//(s06_K17VDSR)- 
	{ 58	,1	,1	, &s06_K18VDSR},	//(s06_K18VDSR)- 
	{ 59	,1	,1	, &s06_K19VDSR},	//(s06_K19VDSR)- 
	{ 60	,1	,1	, &s06_K20VDSR},	//(s06_K20VDSR)- 
	{ 61	,1	,1	, &s06_K21VDSR},	//(s06_K21VDSR)- 
	{ 62	,1	,1	, &s06_K22VDSR},	//(s06_K22VDSR)- 
	{ 63	,1	,1	, &s06_K23VDSR},	//(s06_K23VDSR)- 
	{ 64	,1	,1	, &s06_K24VDSR},	//(s06_K24VDSR)- 
	{ 65	,1	,1	, &s06_K25VDSR},	//(s06_K25VDSR)- 
	{ 66	,1	,1	, &s06_K26VDSR},	//(s06_K26VDSR)- 
	{ 67	,1	,1	, &s06_K27VDSR},	//(s06_K27VDSR)- 
	{ 68	,1	,1	, &s06_K28VDSR},	//(s06_K28VDSR)- 
	{ 69	,1	,1	, &s06_K29VDSR},	//(s06_K29VDSR)- 
	{ 70	,1	,1	, &s06_K30VDSR},	//(s06_K30VDSR)- 
	{ 71	,1	,1	, &s06_K31VDSR},	//(s06_K31VDSR)- 
	{ 72	,1	,1	, &s06_K32VDSR},	//(s06_K32VDSR)- 
	{ 73	,1	,1	, &R0VN74LZ2},	//(s07_K01VDSR)- АС по мощности канал 4
	{ 74	,1	,1	, &R0VN78LZ2},	//(s07_K02VDSR)- АС по периоду разгона канал  4
	{ 75	,1	,1	, &A1EE01LS4},	//(s07_K03VDSR)- Исправность АКНП канал 4
	{ 76	,1	,1	, &A1VN71LS4},	//(s07_K04VDSR)- Блокировка автоматического подъёма ББ канал 4
	{ 77	,1	,1	, &R6IS66LZ2},	//(s07_K05VDSR)- Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 78	,1	,1	, &R6IS67LZ2},	//(s07_K06VDSR)- Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 79	,1	,1	, &R6IS68LZ2},	//(s07_K07VDSR)- Исправность ВИП 4,0 (№7) ССДИ-2
	{ 80	,1	,1	, &s07_K08VDSR},	//(s07_K08VDSR)- 
	{ 81	,1	,1	, &s07_K09VDSR},	//(s07_K09VDSR)- 
	{ 82	,1	,1	, &s07_K10VDSR},	//(s07_K10VDSR)- 
	{ 83	,1	,1	, &s07_K11VDSR},	//(s07_K11VDSR)- 
	{ 84	,1	,1	, &s07_K12VDSR},	//(s07_K12VDSR)- 
	{ 85	,1	,1	, &s07_K13VDSR},	//(s07_K13VDSR)- 
	{ 86	,1	,1	, &s07_K14VDSR},	//(s07_K14VDSR)- 
	{ 87	,1	,1	, &s07_K15VDSR},	//(s07_K15VDSR)- 
	{ 88	,1	,1	, &s07_K16VDSR},	//(s07_K16VDSR)- 
	{ 89	,1	,1	, &s07_K17VDSR},	//(s07_K17VDSR)- 
	{ 90	,1	,1	, &s07_K18VDSR},	//(s07_K18VDSR)- 
	{ 91	,1	,1	, &s07_K19VDSR},	//(s07_K19VDSR)- 
	{ 92	,1	,1	, &s07_K20VDSR},	//(s07_K20VDSR)- 
	{ 93	,1	,1	, &s07_K21VDSR},	//(s07_K21VDSR)- 
	{ 94	,1	,1	, &s07_K22VDSR},	//(s07_K22VDSR)- 
	{ 95	,1	,1	, &s07_K23VDSR},	//(s07_K23VDSR)- 
	{ 96	,1	,1	, &s07_K24VDSR},	//(s07_K24VDSR)- 
	{ 97	,1	,1	, &s07_K25VDSR},	//(s07_K25VDSR)- 
	{ 98	,1	,1	, &s07_K26VDSR},	//(s07_K26VDSR)- 
	{ 99	,1	,1	, &s07_K27VDSR},	//(s07_K27VDSR)- 
	{ 100	,1	,1	, &s07_K28VDSR},	//(s07_K28VDSR)- 
	{ 101	,1	,1	, &s07_K29VDSR},	//(s07_K29VDSR)- 
	{ 102	,1	,1	, &s07_K30VDSR},	//(s07_K30VDSR)- 
	{ 103	,1	,1	, &s07_K31VDSR},	//(s07_K31VDSR)- 
	{ 104	,1	,1	, &s07_K32VDSR},	//(s07_K32VDSR)- 
	{ 105	,1	,1	, &R0VN73LZ2},	//(s08_K01VDSR)- АС по мощности канал 3
	{ 106	,1	,1	, &R0VN77LZ2},	//(s08_K02VDSR)- АС по периоду разгона канал  3
	{ 107	,1	,1	, &A1EE01LS3},	//(s08_K03VDSR)- Исправность АКНП канал 3
	{ 108	,1	,1	, &A1VN71LS3},	//(s08_K04VDSR)- Блокировка автоматического подъёма ББ канал 3
	{ 109	,1	,1	, &R7II71LZ2},	//(s08_K05VDSR)- Сработала АС IУР (датчик 1)
	{ 110	,1	,1	, &R7II72LZ2},	//(s08_K06VDSR)- Сработала АС IУР (датчик 2)
	{ 111	,1	,1	, &R7II73LZ2},	//(s08_K07VDSR)- Сработала АС IIУР
	{ 112	,1	,1	, &s08_K08VDSR},	//(s08_K08VDSR)- 
	{ 113	,1	,1	, &A0VP81LZ2},	//(s08_K09VDSR)- Давление  АЗ1 в норме
	{ 114	,1	,1	, &A1VP81LZ2},	//(s08_K10VDSR)- Давление СБРОС ББ1 в норме
	{ 115	,1	,1	, &R0VP81LZ2},	//(s08_K11VDSR)- Давление  в СИСТЕМЕ -1 в норме
	{ 116	,1	,1	, &B0VP81LZ2},	//(s08_K12VDSR)- Давление АЗ2 в норме
	{ 117	,1	,1	, &B1VP81LZ2},	//(s08_K13VDSR)- Давление СБРОС ББ2 в норме
	{ 118	,1	,1	, &R0VP82LZ2},	//(s08_K14VDSR)- Давление  в СИСТЕМЕ - 2 в норме
	{ 119	,1	,1	, &s08_K15VDSR},	//(s08_K15VDSR)-
	{ 120	,1	,1	, &s08_K16VDSR},	//(s08_K16VDSR)-
	{ 121	,1	,1	, &s08_K17VDSR},	//(s08_K17VDSR)-
	{ 122	,1	,1	, &s08_K18VDSR},	//(s08_K18VDSR)-
	{ 123	,1	,1	, &s08_K19VDSR},	//(s08_K19VDSR)-
	{ 124	,1	,1	, &s08_K20VDSR},	//(s08_K20VDSR)-
	{ 125	,1	,1	, &s08_K21VDSR},	//(s08_K21VDSR)-
	{ 126	,1	,1	, &s08_K22VDSR},	//(s08_K22VDSR)-
	{ 127	,1	,1	, &s08_K23VDSR},	//(s08_K23VDSR)-
	{ 128	,1	,1	, &s08_K24VDSR},	//(s08_K24VDSR)-
	{ 129	,1	,1	, &s08_K25VDSR},	//(s08_K25VDSR)-
	{ 130	,1	,1	, &s08_K26VDSR},	//(s08_K26VDSR)-
	{ 131	,1	,1	, &s08_K27VDSR},	//(s08_K27VDSR)-
	{ 132	,1	,1	, &s08_K28VDSR},	//(s08_K28VDSR)-
	{ 133	,1	,1	, &s08_K29VDSR},	//(s08_K29VDSR)-
	{ 134	,1	,1	, &s08_K30VDSR},	//(s08_K30VDSR)-
	{ 135	,1	,1	, &s08_K31VDSR},	//(s08_K31VDSR)-
	{ 136	,1	,1	, &s08_K32VDSR},	//(s08_K32VDSR)-
	{ 137	,1	,1	, &A3VZ13LZ2},	//(s10_K01FDSR)- Имитация АЗ от ВУ ИС
	{ 138	,1	,1	, &A3VZ15LZ2},	//(s10_K02FDSR)- Имитация АЗ от НУП ИС
	{ 139	,1	,1	, &R0AD14LZ2},	//(s10_K03FDSR)- Имитация АЗ от IIУР
	{ 140	,1	,1	, &A1VN71LZ2},	//(s10_K04FDSR)- Блокировка автоматического подъёма ББ
	{ 141	,1	,1	, &R0VZ71LZ2},	//(s10_K05FDSR)- Обобщенный сигнал АЗ2 канала
	{ 142	,1	,1	, &OEBB1Z2},	//(s10_K06FDSR)- Обесточивание ЭМ ББ1 и ЭПК ББ1
	{ 143	,1	,1	, &OEBB2Z2},	//(s10_K07FDSR)- Обесточивание ЭМ ББ2 и ЭПК ББ2
	{ 144	,1	,1	, &OERB1Z2},	//(s10_K08FDSR)- Обесточивание ЭМ РБ1 и ЭПК РБ1
	{ 145	,1	,1	, &OERB2Z2},	//(s10_K09FDSR)- Обесточивание ЭМ РБ2 и ЭПК РБ2
	{ 146	,1	,1	, &B3IS11LDU},	//(s10_K10FDSR)- Приход на ВУ ИС2 для ДУ
	{ 147	,1	,1	, &B3IS22LDU},	//(s10_K11FDSR)- Приход на НУП ИС2 для ДУ
	{ 148	,1	,1	, &B3IS11LZ1},	//(s10_K12FDSR)- Приход на ВУ ИС2 для УСБ1
	{ 149	,1	,1	, &B3IS22LZ1},	//(s10_K13FDSR)- Приход на НУП ИС2 для УСБ1
	{ 150	,1	,1	, &B0VP81LZ1},	//(s10_K14FDSR)- Давление  АЗ2 в норме для УСБ1
	{ 151	,1	,1	, &B1VP81LZ1},	//(s10_K15FDSR)- Давление СБРОС ББ2 в норме для УСБ1
	{ 152	,1	,1	, &s10_K16FDSR},	//(s10_K16FDSR)- 
	{-1,0,NULL},
};
static char NameSaveFile[]="Baz2sign.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_Baz2sign[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_Baz2sign[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_Baz2sign[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_Baz2sign[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_Baz2sign[0],&di_Baz2sign[0],&ir_Baz2sign[0],&hr_Baz2sign[0],NULL,NULL,NULL,0},	 //Общий слэйв

	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},};
#pragma pop
#include <fp8/drivers/vas84r.h>
static char buf_VAS84_04[28];	//VAS84_04
static vas84r_inipar ini_VAS84_04={172,255,1,8,0xff,0,16,};
#pragma pack(push,1)
static table_drv table_VAS84_04={0,0,&ini_VAS84_04,buf_VAS84_04,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VAS84_04[]={
	{&A0IT02IZ2,3,0},
	{&A2IP01IZ2,3,3},
	{&B0IT02IZ2,3,6},
	{&B2IP01IZ2,3,9},
	{&s04_K05VASR,3,12},
	{&s04_K06VASR,3,15},
	{&s04_K07VASR,3,18},
	{&s04_K08VASR,3,21},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS32_05[66];	//VDS32_05
static vds32r_inipar ini_VDS32_05={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS32_05={0,0,&ini_VDS32_05,buf_VDS32_05,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32_05[]={
	{&R0VN71LZ2,1,0},
	{&R0VN75LZ2,1,2},
	{&A1EE01LS1,1,4},
	{&A1VN71LS1,1,6},
	{&A3IS11LZ2,1,8},
	{&A3IS22LZ2,1,10},
	{&R0AD03LZ2,1,12},
	{&R0AD04LZ2,1,14},
	{&R0AD05LZ2,1,16},
	{&A2IS12LZ2,1,18},
	{&B2IS12LZ2,1,20},
	{&s05_K12VDSR,1,22},
	{&s05_K13VDSR,1,24},
	{&s05_K14VDSR,1,26},
	{&s05_K15VDSR,1,28},
	{&s05_K16VDSR,1,30},
	{&s05_K17VDSR,1,32},
	{&s05_K18VDSR,1,34},
	{&s05_K19VDSR,1,36},
	{&s05_K20VDSR,1,38},
	{&s05_K21VDSR,1,40},
	{&s05_K22VDSR,1,42},
	{&s05_K23VDSR,1,44},
	{&s05_K24VDSR,1,46},
	{&s05_K25VDSR,1,48},
	{&s05_K26VDSR,1,50},
	{&s05_K27VDSR,1,52},
	{&s05_K28VDSR,1,54},
	{&s05_K29VDSR,1,56},
	{&s05_K30VDSR,1,58},
	{&s05_K31VDSR,1,60},
	{&s05_K32VDSR,1,62},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS32_06[66];	//VDS32_06
static vds32r_inipar ini_VDS32_06={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS32_06={0,0,&ini_VDS32_06,buf_VDS32_06,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32_06[]={
	{&R0VN72LZ2,1,0},
	{&R0VN76LZ2,1,2},
	{&A1EE01LS2,1,4},
	{&A1VN71LS2,1,6},
	{&B3IS11LZ2,1,8},
	{&B3IS22LZ2,1,10},
	{&s06_K07VDSR,1,12},
	{&s06_K08VDSR,1,14},
	{&s06_K09VDSR,1,16},
	{&s06_K10VDSR,1,18},
	{&s06_K11VDSR,1,20},
	{&s06_K12VDSR,1,22},
	{&s06_K13VDSR,1,24},
	{&s06_K14VDSR,1,26},
	{&s06_K15VDSR,1,28},
	{&s06_K16VDSR,1,30},
	{&s06_K17VDSR,1,32},
	{&s06_K18VDSR,1,34},
	{&s06_K19VDSR,1,36},
	{&s06_K20VDSR,1,38},
	{&s06_K21VDSR,1,40},
	{&s06_K22VDSR,1,42},
	{&s06_K23VDSR,1,44},
	{&s06_K24VDSR,1,46},
	{&s06_K25VDSR,1,48},
	{&s06_K26VDSR,1,50},
	{&s06_K27VDSR,1,52},
	{&s06_K28VDSR,1,54},
	{&s06_K29VDSR,1,56},
	{&s06_K30VDSR,1,58},
	{&s06_K31VDSR,1,60},
	{&s06_K32VDSR,1,62},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS32_07[66];	//VDS32_07
static vds32r_inipar ini_VDS32_07={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS32_07={0,0,&ini_VDS32_07,buf_VDS32_07,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32_07[]={
	{&R0VN74LZ2,1,0},
	{&R0VN78LZ2,1,2},
	{&A1EE01LS4,1,4},
	{&A1VN71LS4,1,6},
	{&R6IS66LZ2,1,8},
	{&R6IS67LZ2,1,10},
	{&R6IS68LZ2,1,12},
	{&s07_K08VDSR,1,14},
	{&s07_K09VDSR,1,16},
	{&s07_K10VDSR,1,18},
	{&s07_K11VDSR,1,20},
	{&s07_K12VDSR,1,22},
	{&s07_K13VDSR,1,24},
	{&s07_K14VDSR,1,26},
	{&s07_K15VDSR,1,28},
	{&s07_K16VDSR,1,30},
	{&s07_K17VDSR,1,32},
	{&s07_K18VDSR,1,34},
	{&s07_K19VDSR,1,36},
	{&s07_K20VDSR,1,38},
	{&s07_K21VDSR,1,40},
	{&s07_K22VDSR,1,42},
	{&s07_K23VDSR,1,44},
	{&s07_K24VDSR,1,46},
	{&s07_K25VDSR,1,48},
	{&s07_K26VDSR,1,50},
	{&s07_K27VDSR,1,52},
	{&s07_K28VDSR,1,54},
	{&s07_K29VDSR,1,56},
	{&s07_K30VDSR,1,58},
	{&s07_K31VDSR,1,60},
	{&s07_K32VDSR,1,62},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS32_08[66];	//VDS32_08
static vds32r_inipar ini_VDS32_08={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS32_08={0,0,&ini_VDS32_08,buf_VDS32_08,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32_08[]={
	{&R0VN73LZ2,1,0},
	{&R0VN77LZ2,1,2},
	{&A1EE01LS3,1,4},
	{&A1VN71LS3,1,6},
	{&R7II71LZ2,1,8},
	{&R7II72LZ2,1,10},
	{&R7II73LZ2,1,12},
	{&s08_K08VDSR,1,14},
	{&A0VP81LZ2,1,16},
	{&A1VP81LZ2,1,18},
	{&R0VP81LZ2,1,20},
	{&B0VP81LZ2,1,22},
	{&B1VP81LZ2,1,24},
	{&R0VP82LZ2,1,26},
	{&s08_K15VDSR,1,28},
	{&s08_K16VDSR,1,30},
	{&s08_K17VDSR,1,32},
	{&s08_K18VDSR,1,34},
	{&s08_K19VDSR,1,36},
	{&s08_K20VDSR,1,38},
	{&s08_K21VDSR,1,40},
	{&s08_K22VDSR,1,42},
	{&s08_K23VDSR,1,44},
	{&s08_K24VDSR,1,46},
	{&s08_K25VDSR,1,48},
	{&s08_K26VDSR,1,50},
	{&s08_K27VDSR,1,52},
	{&s08_K28VDSR,1,54},
	{&s08_K29VDSR,1,56},
	{&s08_K30VDSR,1,58},
	{&s08_K31VDSR,1,60},
	{&s08_K32VDSR,1,62},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS16_10[40];	//FDS16_10
static fds16r_inipar ini_FDS16_10={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS16_10={0,0,&ini_FDS16_10,buf_FDS16_10,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS16_10[]={
	{&A3VZ13LZ2,1,0},
	{&A3VZ15LZ2,1,2},
	{&R0AD14LZ2,1,4},
	{&A1VN71LZ2,1,6},
	{&R0VZ71LZ2,1,8},
	{&OEBB1Z2,1,10},
	{&OEBB2Z2,1,12},
	{&OERB1Z2,1,14},
	{&OERB2Z2,1,16},
	{&B3IS11LDU,1,18},
	{&B3IS22LDU,1,20},
	{&B3IS11LZ1,1,22},
	{&B3IS22LZ1,1,24},
	{&B0VP81LZ1,1,26},
	{&B1VP81LZ1,1,28},
	{&s10_K16FDSR,1,30},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0xc6,0x04,7,28,def_buf_VAS84_04,&table_VAS84_04}, //VAS84_04
	{0xc2,0x05,15,66,def_buf_VDS32_05,&table_VDS32_05}, //VDS32_05
	{0xc2,0x06,15,66,def_buf_VDS32_06,&table_VDS32_06}, //VDS32_06
	{0xc2,0x07,15,66,def_buf_VDS32_07,&table_VDS32_07}, //VDS32_07
	{0xc2,0x08,15,66,def_buf_VDS32_08,&table_VDS32_08}, //VDS32_08
	{0x96,0x0a,20,40,def_buf_FDS16_10,&table_FDS16_10}, //FDS16_10
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
}
void Scheme(void)
{
}
#endif
