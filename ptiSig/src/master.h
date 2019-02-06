#ifndef PTISIG_H
#define PTISIG_H
// Подсистема ptiSig:ptiSig
static char SimulOn=0;
static short CodeSub=10;
static char SimulIP[]="192.168.1.17\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 688
static char BUFFER[688];
#define A0IT01IZ1	 BUFFER[0]	//(AO1632001) Температура АЗ1-1
#define idA0IT01IZ1	 1	//(AO1632001) Температура АЗ1-1
#define A2IP01IZ1	 BUFFER[3]	//(AO1632002) Текущее давление СБРОС РБ1
#define idA2IP01IZ1	 2	//(AO1632002) Текущее давление СБРОС РБ1
#define B0IT01IZ1	 BUFFER[6]	//(AO1632003) Температура АЗ2-1
#define idB0IT01IZ1	 3	//(AO1632003) Температура АЗ2-1
#define B2IP01IZ1	 BUFFER[9]	//(AO1632004) Текущее давление СБРОС РБ2
#define idB2IP01IZ1	 4	//(AO1632004) Текущее давление СБРОС РБ2
#define A0IT02IZ2	 BUFFER[12]	//(AO1632005) Температура АЗ1-2
#define idA0IT02IZ2	 5	//(AO1632005) Температура АЗ1-2
#define A2IP01IZ2	 BUFFER[15]	//(AO1632006) Текущее давление СБРОС РБ1
#define idA2IP01IZ2	 6	//(AO1632006) Текущее давление СБРОС РБ1
#define B0IT02IZ2	 BUFFER[18]	//(AO1632007) Температура АЗ2-2
#define idB0IT02IZ2	 7	//(AO1632007) Температура АЗ2-2
#define B2IP01IZ2	 BUFFER[21]	//(AO1632008) Текущее давление СБРОС РБ2
#define idB2IP01IZ2	 8	//(AO1632008) Текущее давление СБРОС РБ2
#define A3IP02IDU	 BUFFER[24]	//(AO1632009) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	 9	//(AO1632009) Текущее давление ВЫСТРЕЛ ИС1
#define B3IP02IDU	 BUFFER[27]	//(AO1632010) Текущее давление ВЫСТРЕЛ ИС2
#define idB3IP02IDU	 10	//(AO1632010) Текущее давление ВЫСТРЕЛ ИС2
#define AO1632011	 BUFFER[30]	//!!!(AO1632011) Не занятые значения
#define idAO1632011	 11	//!!!(AO1632011) Не занятые значения
#define AO1632012	 BUFFER[33]	//!!!(AO1632012) Не занятые значения
#define idAO1632012	 12	//!!!(AO1632012) Не занятые значения
#define AO1632013	 BUFFER[36]	//!!!(AO1632013) Не занятые значения
#define idAO1632013	 13	//!!!(AO1632013) Не занятые значения
#define AO1632014	 BUFFER[39]	//!!!(AO1632014) Не занятые значения
#define idAO1632014	 14	//!!!(AO1632014) Не занятые значения
#define AO1632015	 BUFFER[42]	//!!!(AO1632015) Не занятые значения
#define idAO1632015	 15	//!!!(AO1632015) Не занятые значения
#define AO1632016	 BUFFER[45]	//!!!(AO1632016) Не занятые значения
#define idAO1632016	 16	//!!!(AO1632016) Не занятые значения
#define R0VN71LZ1	 BUFFER[48]	//(DO3210001) АС по мощности канал 1
#define idR0VN71LZ1	 17	//(DO3210001) АС по мощности канал 1
#define R0VN75LZ1	 BUFFER[50]	//(DO3210002) АС по периоду разгона канал  1
#define idR0VN75LZ1	 18	//(DO3210002) АС по периоду разгона канал  1
#define A0EE01LS1	 BUFFER[52]	//(DO3210003) Исправность АКНП канал 1 
#define idA0EE01LS1	 19	//(DO3210003) Исправность АКНП канал 1 
#define A0VN71LS1	 BUFFER[54]	//(DO3210004) Блокировка автоматического подъёма ББ канал 1
#define idA0VN71LS1	 20	//(DO3210004) Блокировка автоматического подъёма ББ канал 1
#define A3IS11LZ1	 BUFFER[56]	//(DO3210005) Приход на ВУ ИС1
#define idA3IS11LZ1	 21	//(DO3210005) Приход на ВУ ИС1
#define A3IS22LZ1	 BUFFER[58]	//(DO3210006) Приход на НУП ИС1
#define idA3IS22LZ1	 22	//(DO3210006) Приход на НУП ИС1
#define R0VN72LZ1	 BUFFER[60]	//(DO3210007) АС по мощности канал 2
#define idR0VN72LZ1	 23	//(DO3210007) АС по мощности канал 2
#define R0VN76LZ1	 BUFFER[62]	//(DO3210008) АС по периоду разгона канал  2
#define idR0VN76LZ1	 24	//(DO3210008) АС по периоду разгона канал  2
#define A0EE01LS2	 BUFFER[64]	//(DO3210009) Исправность АКНП  канал 2
#define idA0EE01LS2	 25	//(DO3210009) Исправность АКНП  канал 2
#define A0VN71LS2	 BUFFER[66]	//(DO3210010) Блокировка автоматического подъёма ББ канал 2
#define idA0VN71LS2	 26	//(DO3210010) Блокировка автоматического подъёма ББ канал 2
#define B3IS11LZ1	 BUFFER[68]	//(DO3210011) Приход на ВУ ИС2
#define idB3IS11LZ1	 27	//(DO3210011) Приход на ВУ ИС2
#define B3IS22LZ1	 BUFFER[70]	//(DO3210012) Приход на НУП ИС2
#define idB3IS22LZ1	 28	//(DO3210012) Приход на НУП ИС2
#define R0VN74LZ1	 BUFFER[72]	//(DO3210013) АС по мощности канал 4
#define idR0VN74LZ1	 29	//(DO3210013) АС по мощности канал 4
#define R0VN78LZ1	 BUFFER[74]	//(DO3210014) АС по периоду разгона канал  4
#define idR0VN78LZ1	 30	//(DO3210014) АС по периоду разгона канал  4
#define A0EE01LS4	 BUFFER[76]	//(DO3210015) Исправность АКНП канал 4
#define idA0EE01LS4	 31	//(DO3210015) Исправность АКНП канал 4
#define A0VN71LS4	 BUFFER[78]	//(DO3210016) Блокировка автоматического подъёма ББ канал 4
#define idA0VN71LS4	 32	//(DO3210016) Блокировка автоматического подъёма ББ канал 4
#define R6IS66LZ1	 BUFFER[80]	//(DO3210017) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZ1	 33	//(DO3210017) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZ1	 BUFFER[82]	//(DO3210018) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZ1	 34	//(DO3210018) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZ1	 BUFFER[84]	//(DO3210019) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZ1	 35	//(DO3210019) Исправность ВИП 4,0 (№7) ССДИ-2
#define R0VN73LZ1	 BUFFER[86]	//(DO3210020) АС по мощности канал 3
#define idR0VN73LZ1	 36	//(DO3210020) АС по мощности канал 3
#define R0VN77LZ1	 BUFFER[88]	//(DO3210021) АС по периоду разгона канал  3
#define idR0VN77LZ1	 37	//(DO3210021) АС по периоду разгона канал  3
#define A0EE01LS3	 BUFFER[90]	//(DO3210022) Исправность АКНП канал 3
#define idA0EE01LS3	 38	//(DO3210022) Исправность АКНП канал 3
#define A0VN71LS3	 BUFFER[92]	//(DO3210023) Блокировка автоматического подъёма ББ канал 3
#define idA0VN71LS3	 39	//(DO3210023) Блокировка автоматического подъёма ББ канал 3
#define R7II71LZ1	 BUFFER[94]	//(DO3210024) Сработала АС IУР РАД (датчик 1)
#define idR7II71LZ1	 40	//(DO3210024) Сработала АС IУР РАД (датчик 1)
#define R7II72LZ1	 BUFFER[96]	//(DO3210025) Сработала АС IУР РАД  (датчик 2)
#define idR7II72LZ1	 41	//(DO3210025) Сработала АС IУР РАД  (датчик 2)
#define R7II73LZ1	 BUFFER[98]	//(DO3210026) Сработала АС II УР РАД
#define idR7II73LZ1	 42	//(DO3210026) Сработала АС II УР РАД
#define A0VP81LZ1	 BUFFER[100]	//(DO3210027) Давление  АЗ1 в норме
#define idA0VP81LZ1	 43	//(DO3210027) Давление  АЗ1 в норме
#define A1VP81LZ1	 BUFFER[102]	//(DO3210028) Давление СБРОС ББ1 в норме
#define idA1VP81LZ1	 44	//(DO3210028) Давление СБРОС ББ1 в норме
#define R0VP81LZ1	 BUFFER[104]	//(DO3210029) Давление  в СИСТЕМЕ -1 в норме
#define idR0VP81LZ1	 45	//(DO3210029) Давление  в СИСТЕМЕ -1 в норме
#define B0VP81LZ1	 BUFFER[106]	//(DO3210030) Давление АЗ2 в норме
#define idB0VP81LZ1	 46	//(DO3210030) Давление АЗ2 в норме
#define B1VP81LZ1	 BUFFER[108]	//(DO3210031) Давление СБРОС ББ2 в норме
#define idB1VP81LZ1	 47	//(DO3210031) Давление СБРОС ББ2 в норме
#define R0VP82LZ1	 BUFFER[110]	//(DO3210032) Давление  в СИСТЕМЕ - 2 в норме
#define idR0VP82LZ1	 48	//(DO3210032) Давление  в СИСТЕМЕ - 2 в норме
#define R0VN71LZ2	 BUFFER[112]	//(DO3211001) АС по мощности канал 1
#define idR0VN71LZ2	 49	//(DO3211001) АС по мощности канал 1
#define R0VN75LZ2	 BUFFER[114]	//(DO3211002) АС по периоду разгона канал  1
#define idR0VN75LZ2	 50	//(DO3211002) АС по периоду разгона канал  1
#define A1EE01LS1	 BUFFER[116]	//(DO3211003) Исправность АКНП канал 1
#define idA1EE01LS1	 51	//(DO3211003) Исправность АКНП канал 1
#define A1VN71LS1	 BUFFER[118]	//(DO3211004) Блокировка автоматического подъёма ББ канал 1
#define idA1VN71LS1	 52	//(DO3211004) Блокировка автоматического подъёма ББ канал 1
#define A3IS11LZ2	 BUFFER[120]	//(DO3211005) Приход на ВУ ИС1
#define idA3IS11LZ2	 53	//(DO3211005) Приход на ВУ ИС1
#define A3IS22LZ2	 BUFFER[122]	//(DO3211006) Приход на НУП ИС1
#define idA3IS22LZ2	 54	//(DO3211006) Приход на НУП ИС1
#define R0VN72LZ2	 BUFFER[124]	//(DO3211007) АС по мощности канал 2
#define idR0VN72LZ2	 55	//(DO3211007) АС по мощности канал 2
#define R0VN76LZ2	 BUFFER[126]	//(DO3211008) АС по периоду разгона канал  2
#define idR0VN76LZ2	 56	//(DO3211008) АС по периоду разгона канал  2
#define A1EE01LS2	 BUFFER[128]	//(DO3211009) Исправность АКНП  канал 2
#define idA1EE01LS2	 57	//(DO3211009) Исправность АКНП  канал 2
#define A1VN71LS2	 BUFFER[130]	//(DO3211010) Блокировка автоматического подъёма ББ канал 2
#define idA1VN71LS2	 58	//(DO3211010) Блокировка автоматического подъёма ББ канал 2
#define B3IS11LZ2	 BUFFER[132]	//(DO3211011) Приход на ВУ ИС2
#define idB3IS11LZ2	 59	//(DO3211011) Приход на ВУ ИС2
#define B3IS22LZ2	 BUFFER[134]	//(DO3211012) Приход на НУП ИС2
#define idB3IS22LZ2	 60	//(DO3211012) Приход на НУП ИС2
#define R0VN74LZ2	 BUFFER[136]	//(DO3211013) АС по мощности канал 4
#define idR0VN74LZ2	 61	//(DO3211013) АС по мощности канал 4
#define R0VN78LZ2	 BUFFER[138]	//(DO3211014) АС по периоду разгона канал  4
#define idR0VN78LZ2	 62	//(DO3211014) АС по периоду разгона канал  4
#define A1EE01LS4	 BUFFER[140]	//(DO3211015) Исправность АКНП канал 4
#define idA1EE01LS4	 63	//(DO3211015) Исправность АКНП канал 4
#define A1VN71LS4	 BUFFER[142]	//(DO3211016) Блокировка автоматического подъёма ББ канал 4
#define idA1VN71LS4	 64	//(DO3211016) Блокировка автоматического подъёма ББ канал 4
#define R6IS66LZ2	 BUFFER[144]	//(DO3211017) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZ2	 65	//(DO3211017) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZ2	 BUFFER[146]	//(DO3211018) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZ2	 66	//(DO3211018) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZ2	 BUFFER[148]	//(DO3211019) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZ2	 67	//(DO3211019) Исправность ВИП 4,0 (№7) ССДИ-2
#define R0VN73LZ2	 BUFFER[150]	//(DO3211020) АС по мощности канал 3
#define idR0VN73LZ2	 68	//(DO3211020) АС по мощности канал 3
#define R0VN77LZ2	 BUFFER[152]	//(DO3211021) АС по периоду разгона канал  3
#define idR0VN77LZ2	 69	//(DO3211021) АС по периоду разгона канал  3
#define A1EE01LS3	 BUFFER[154]	//(DO3211022) Исправность АКНП канал 3
#define idA1EE01LS3	 70	//(DO3211022) Исправность АКНП канал 3
#define A1VN71LS3	 BUFFER[156]	//(DO3211023) Блокировка автоматического подъёма ББ канал 3
#define idA1VN71LS3	 71	//(DO3211023) Блокировка автоматического подъёма ББ канал 3
#define R7II71LZ2	 BUFFER[158]	//(DO3211024) Сработала АС IУР (датчик 1)
#define idR7II71LZ2	 72	//(DO3211024) Сработала АС IУР (датчик 1)
#define R7II72LZ2	 BUFFER[160]	//(DO3211025) Сработала АС IУР (датчик 2)
#define idR7II72LZ2	 73	//(DO3211025) Сработала АС IУР (датчик 2)
#define R7II73LZ2	 BUFFER[162]	//(DO3211026) Сработала АС IIУР
#define idR7II73LZ2	 74	//(DO3211026) Сработала АС IIУР
#define A0VP81LZ2	 BUFFER[164]	//(DO3211027) Давление  АЗ1 в норме
#define idA0VP81LZ2	 75	//(DO3211027) Давление  АЗ1 в норме
#define A1VP81LZ2	 BUFFER[166]	//(DO3211028) Давление СБРОС ББ1 в норме
#define idA1VP81LZ2	 76	//(DO3211028) Давление СБРОС ББ1 в норме
#define R0VP81LZ2	 BUFFER[168]	//(DO3211029) Давление  в СИСТЕМЕ -1 в норме
#define idR0VP81LZ2	 77	//(DO3211029) Давление  в СИСТЕМЕ -1 в норме
#define B0VP81LZ2	 BUFFER[170]	//(DO3211030) Давление АЗ2 в норме
#define idB0VP81LZ2	 78	//(DO3211030) Давление АЗ2 в норме
#define B1VP81LZ2	 BUFFER[172]	//(DO3211031) Давление СБРОС ББ2 в норме
#define idB1VP81LZ2	 79	//(DO3211031) Давление СБРОС ББ2 в норме
#define R0VP82LZ2	 BUFFER[174]	//(DO3211032) Давление  в СИСТЕМЕ - 2 в норме
#define idR0VP82LZ2	 80	//(DO3211032) Давление  в СИСТЕМЕ - 2 в норме
#define B3IS35LDU	 BUFFER[176]	//(DO3213001) Клапан «ВПИС2» открыт (обесточен) 
#define idB3IS35LDU	 81	//(DO3213001) Клапан «ВПИС2» открыт (обесточен) 
#define B3IS33LDU	 BUFFER[178]	//(DO3213002) Клапан «ВЫСТРЕЛ ИС2» открыт (обесточен) 
#define idB3IS33LDU	 82	//(DO3213002) Клапан «ВЫСТРЕЛ ИС2» открыт (обесточен) 
#define B2IS33LDU	 BUFFER[180]	//(DO3213003) Клапан «Подъём РБ2» открыт (обесточен) 
#define idB2IS33LDU	 83	//(DO3213003) Клапан «Подъём РБ2» открыт (обесточен) 
#define B4IS10LDU	 BUFFER[182]	//(DO3213004) Клапан «Подъём НИ2» открыт (обесточен) 
#define idB4IS10LDU	 84	//(DO3213004) Клапан «Подъём НИ2» открыт (обесточен) 
#define B3IS31LDU	 BUFFER[184]	//(DO3213005) Клапан «СПУСК ИС2» открыт (обесточен) 
#define idB3IS31LDU	 85	//(DO3213005) Клапан «СПУСК ИС2» открыт (обесточен) 
#define B7AS31LDU	 BUFFER[186]	//(DO3213006) Клапан «Обдув АЗ2» открыт (обесточен) 
#define idB7AS31LDU	 86	//(DO3213006) Клапан «Обдув АЗ2» открыт (обесточен) 
#define B1IS12LDU	 BUFFER[188]	//(DO3213007) Магнит ББ2 зацеплен 
#define idB1IS12LDU	 87	//(DO3213007) Магнит ББ2 зацеплен 
#define B1IS11LDU	 BUFFER[190]	//(DO3213008) Приход на ВУ ББ2 
#define idB1IS11LDU	 88	//(DO3213008) Приход на ВУ ББ2 
#define B1IS21LDU	 BUFFER[192]	//(DO3213009) Приход на НУ ББ2 
#define idB1IS21LDU	 89	//(DO3213009) Приход на НУ ББ2 
#define B2IS12LDU	 BUFFER[194]	//(DO3213010) Магнит РБ2 зацеплен 
#define idB2IS12LDU	 90	//(DO3213010) Магнит РБ2 зацеплен 
#define B2IS11LDU	 BUFFER[196]	//(DO3213011) Приход на ВУ РБ2-СТР 
#define idB2IS11LDU	 91	//(DO3213011) Приход на ВУ РБ2-СТР 
#define B2IS21LDU	 BUFFER[198]	//(DO3213012) Приход на НУ РБ2-СС 
#define idB2IS21LDU	 92	//(DO3213012) Приход на НУ РБ2-СС 
#define B3IS21LDU	 BUFFER[200]	//(DO3213013) Приход на НУ ИС2 
#define idB3IS21LDU	 93	//(DO3213013) Приход на НУ ИС2 
#define R8IS11LDU	 BUFFER[202]	//(DO3213014) Аварийный НИ установлен 
#define idR8IS11LDU	 94	//(DO3213014) Аварийный НИ установлен 
#define DO3213015	 BUFFER[204]	//(DO3213015) Не занятые значения
#define idDO3213015	 95	//(DO3213015) Не занятые значения
#define A4IS11LDU	 BUFFER[206]	//(DO3213016) Приход на ВУ НИ1 
#define idA4IS11LDU	 96	//(DO3213016) Приход на ВУ НИ1 
#define A4IS21LDU	 BUFFER[208]	//(DO3213017) Приход на НУ НИ1 
#define idA4IS21LDU	 97	//(DO3213017) Приход на НУ НИ1 
#define A9IS11LDU	 BUFFER[210]	//(DO3213018) Приход на ВУ НИ ДС1
#define idA9IS11LDU	 98	//(DO3213018) Приход на ВУ НИ ДС1
#define A9IS21LDU	 BUFFER[212]	//(DO3213019) Приход на НУ НИ ДС1
#define idA9IS21LDU	 99	//(DO3213019) Приход на НУ НИ ДС1
#define B9IS11LDU	 BUFFER[214]	//(DO3213020) Приход на ВУ НИ ДС2
#define idB9IS11LDU	 100	//(DO3213020) Приход на ВУ НИ ДС2
#define B9IS21LDU	 BUFFER[216]	//(DO3213021) Приход на НУ НИ ДС2
#define idB9IS21LDU	 101	//(DO3213021) Приход на НУ НИ ДС2
#define R1IS11LDU	 BUFFER[218]	//(DO3213022) Приход на ВУ МДЗ1
#define idR1IS11LDU	 102	//(DO3213022) Приход на ВУ МДЗ1
#define R1IS21LDU	 BUFFER[220]	//(DO3213023) Приход на НУ МДЗ1
#define idR1IS21LDU	 103	//(DO3213023) Приход на НУ МДЗ1
#define R2IS11LDU	 BUFFER[222]	//(DO3213024) Приход на ВУ МДЗ2
#define idR2IS11LDU	 104	//(DO3213024) Приход на ВУ МДЗ2
#define R2IS21LDU	 BUFFER[224]	//(DO3213025) Приход на НУ МДЗ2
#define idR2IS21LDU	 105	//(DO3213025) Приход на НУ МДЗ2
#define A3IS35LDU	 BUFFER[226]	//(DO3213026) Клапан «ВПИС1» открыт (обесточен)
#define idA3IS35LDU	 106	//(DO3213026) Клапан «ВПИС1» открыт (обесточен)
#define A3IS33LDU	 BUFFER[228]	//(DO3213027) Клапан «ВЫСТРЕЛ ИС1» открыт (обесточен)
#define idA3IS33LDU	 107	//(DO3213027) Клапан «ВЫСТРЕЛ ИС1» открыт (обесточен)
#define A2IS33LDU	 BUFFER[230]	//(DO3213028) Клапан «Подъём РБ1» открыт (обесточен)
#define idA2IS33LDU	 108	//(DO3213028) Клапан «Подъём РБ1» открыт (обесточен)
#define A4IS10LDU	 BUFFER[232]	//(DO3213029) Клапан «Подъём НИ1» открыт (обесточен)
#define idA4IS10LDU	 109	//(DO3213029) Клапан «Подъём НИ1» открыт (обесточен)
#define A3IS31LDU	 BUFFER[234]	//(DO3213030) Клапан «СПУСК ИС1» открыт (обесточен)
#define idA3IS31LDU	 110	//(DO3213030) Клапан «СПУСК ИС1» открыт (обесточен)
#define A7AS31LDU	 BUFFER[236]	//(DO3213031) Клапан «Обдув АЗ1» открыт (обесточен)
#define idA7AS31LDU	 111	//(DO3213031) Клапан «Обдув АЗ1» открыт (обесточен)
#define A1IS12LDU	 BUFFER[238]	//(DO3213032) Магнит ББ1 зацеплен
#define idA1IS12LDU	 112	//(DO3213032) Магнит ББ1 зацеплен
#define A1IS11LDU	 BUFFER[240]	//(DO3214001) Приход на ВУ ББ1
#define idA1IS11LDU	 113	//(DO3214001) Приход на ВУ ББ1
#define A1IS21LDU	 BUFFER[242]	//(DO3214002) Приход на НУ ББ1
#define idA1IS21LDU	 114	//(DO3214002) Приход на НУ ББ1
#define A2IS12LDU	 BUFFER[244]	//(DO3214003) Магнит РБ1 зацеплен
#define idA2IS12LDU	 115	//(DO3214003) Магнит РБ1 зацеплен
#define A2IS11LDU	 BUFFER[246]	//(DO3214004) Приход на ВУ РБ1-СТР
#define idA2IS11LDU	 116	//(DO3214004) Приход на ВУ РБ1-СТР
#define A2IS21LDU	 BUFFER[248]	//(DO3214005) Приход на НУ РБ1-СС
#define idA2IS21LDU	 117	//(DO3214005) Приход на НУ РБ1-СС
#define A3IS21LDU	 BUFFER[250]	//(DO3214006) Приход на НУ ИС1
#define idA3IS21LDU	 118	//(DO3214006) Приход на НУ ИС1
#define B4IS11LDU	 BUFFER[252]	//(DO3214007) Приход на ВУ НИ2
#define idB4IS11LDU	 119	//(DO3214007) Приход на ВУ НИ2
#define B4IS21LDU	 BUFFER[254]	//(DO3214008) Приход на НУ НИ2
#define idB4IS21LDU	 120	//(DO3214008) Приход на НУ НИ2
#define B8IS12LDU	 BUFFER[256]	//(DO3214009) Приход на механический ВУ АЗ2
#define idB8IS12LDU	 121	//(DO3214009) Приход на механический ВУ АЗ2
#define DO3214010	 BUFFER[258]	//(DO3214010)
#define idDO3214010	 122	//(DO3214010)
#define A3VP81LDU	 BUFFER[260]	//(DO3214011) Давление СПУСК ИС1 в норме
#define idA3VP81LDU	 123	//(DO3214011) Давление СПУСК ИС1 в норме
#define A2VP82LDU	 BUFFER[262]	//(DO3214012) Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	 124	//(DO3214012) Давление ПОДЪЁМ РБ1 в норме
#define A4VP82LDU	 BUFFER[264]	//(DO3214013) Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	 125	//(DO3214013) Давление ПОДЪЁМ НИ1 в норме
#define B3VP81LDU	 BUFFER[266]	//(DO3214014) Давление СПУСК ИС2 в норме
#define idB3VP81LDU	 126	//(DO3214014) Давление СПУСК ИС2 в норме
#define B2VP82LDU	 BUFFER[268]	//(DO3214015) Давление ПОДЪЁМ РБ2 в норме
#define idB2VP82LDU	 127	//(DO3214015) Давление ПОДЪЁМ РБ2 в норме
#define B4VP82LDU	 BUFFER[270]	//(DO3214016) Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	 128	//(DO3214016) Давление ПОДЪЁМ НИ2 в норме
#define R0IS02LDU	 BUFFER[272]	//(DO3214017) Разрешение ввода от имитатора
#define idR0IS02LDU	 129	//(DO3214017) Разрешение ввода от имитатора
#define A3IS11LDU	 BUFFER[274]	//(DO3214018) Приход на ВУ ИС1
#define idA3IS11LDU	 130	//(DO3214018) Приход на ВУ ИС1
#define A3IS22LDU	 BUFFER[276]	//(DO3214019) Приход на НУП ИС1
#define idA3IS22LDU	 131	//(DO3214019) Приход на НУП ИС1
#define B3IS11LDU	 BUFFER[278]	//(DO3214020) Приход на ВУ ИС2
#define idB3IS11LDU	 132	//(DO3214020) Приход на ВУ ИС2
#define B3IS22LDU	 BUFFER[280]	//(DO3214021) Приход на НУП ИС2
#define idB3IS22LDU	 133	//(DO3214021) Приход на НУП ИС2
#define R4IS11LDU	 BUFFER[282]	//(DO3214022) Приход на ВУ тележки
#define idR4IS11LDU	 134	//(DO3214022) Приход на ВУ тележки
#define R4IS12LDU	 BUFFER[284]	//(DO3214023) Приход на механический ВУ тележки
#define idR4IS12LDU	 135	//(DO3214023) Приход на механический ВУ тележки
#define R4IS21LDU	 BUFFER[286]	//(DO3214024) Приход на НУ тележки
#define idR4IS21LDU	 136	//(DO3214024) Приход на НУ тележки
#define R4IS22LDU	 BUFFER[288]	//(DO3214025) Приход на механический НУ тележки
#define idR4IS22LDU	 137	//(DO3214025) Приход на механический НУ тележки
#define DO3214026	 BUFFER[290]	//(DO3214026)
#define idDO3214026	 138	//(DO3214026)
#define A6IS21LDU	 BUFFER[292]	//(DO3214027) Приход на НУ БЗ1
#define idA6IS21LDU	 139	//(DO3214027) Приход на НУ БЗ1
#define A5IS11LDU	 BUFFER[294]	//(DO3214028) Приход на ВУ НЛ1
#define idA5IS11LDU	 140	//(DO3214028) Приход на ВУ НЛ1
#define A5IS21LDU	 BUFFER[296]	//(DO3214029) Приход на НУ НЛ1
#define idA5IS21LDU	 141	//(DO3214029) Приход на НУ НЛ1
#define B6IS11LDU	 BUFFER[298]	//(DO3214030) Приход на ВУ БЗ2
#define idB6IS11LDU	 142	//(DO3214030) Приход на ВУ БЗ2
#define B6IS21LDU	 BUFFER[300]	//(DO3214031) Приход на НУ БЗ2
#define idB6IS21LDU	 143	//(DO3214031) Приход на НУ БЗ2
#define B5IS11LDU	 BUFFER[302]	//(DO3214032) Приход на ВУ НЛ2
#define idB5IS11LDU	 144	//(DO3214032) Приход на ВУ НЛ2
#define B5IS21LDU	 BUFFER[304]	//(DO3215001) Приход на НУ НЛ2
#define idB5IS21LDU	 145	//(DO3215001) Приход на НУ НЛ2
#define R3IS11LDU	 BUFFER[306]	//(DO3215002) Приход на ВУ гомогенных дверей-1
#define idR3IS11LDU	 146	//(DO3215002) Приход на ВУ гомогенных дверей-1
#define R3IS21LDU	 BUFFER[308]	//(DO3215003) Приход на НУ гомогенных дверей-1
#define idR3IS21LDU	 147	//(DO3215003) Приход на НУ гомогенных дверей-1
#define R3IS31LDU	 BUFFER[310]	//(DO3215004) Приход на ВУ гомогенных дверей-2
#define idR3IS31LDU	 148	//(DO3215004) Приход на ВУ гомогенных дверей-2
#define R3IS41LDU	 BUFFER[312]	//(DO3215005) Приход на НУ гомогенных дверей-2
#define idR3IS41LDU	 149	//(DO3215005) Приход на НУ гомогенных дверей-2
#define R3AD10LDU	 BUFFER[314]	//(DO3215006) Гомогенные двери-1 открыть
#define idR3AD10LDU	 150	//(DO3215006) Гомогенные двери-1 открыть
#define R3AD11LDU	 BUFFER[316]	//(DO3215007) Гомогенные двери-2 открыть
#define idR3AD11LDU	 151	//(DO3215007) Гомогенные двери-2 открыть
#define R3AD20LDU	 BUFFER[318]	//(DO3215008) Гомогенные двери-1 закрыть
#define idR3AD20LDU	 152	//(DO3215008) Гомогенные двери-1 закрыть
#define R3AD21LDU	 BUFFER[320]	//(DO3215009) Гомогенные двери-2 закрыть
#define idR3AD21LDU	 153	//(DO3215009) Гомогенные двери-2 закрыть
#define R5IS11LDU	 BUFFER[322]	//(DO3215010) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	 154	//(DO3215010) Приход на ВУ ворот отстойной зоны
#define R5IS21LDU	 BUFFER[324]	//(DO3215011) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	 155	//(DO3215011) Приход на НУ ворот отстойной зоны
#define R5AD10LDU	 BUFFER[326]	//(DO3215012) Открыть ворота отстойной зоны
#define idR5AD10LDU	 156	//(DO3215012) Открыть ворота отстойной зоны
#define R5AD20LDU	 BUFFER[328]	//(DO3215013) Закрыть ворота отстойной зоны
#define idR5AD20LDU	 157	//(DO3215013) Закрыть ворота отстойной зоны
#define R6IS21LDU	 BUFFER[330]	//(DO3215014) Кран-балка в нерабочем положении
#define idR6IS21LDU	 158	//(DO3215014) Кран-балка в нерабочем положении
#define A8IS12LDU	 BUFFER[332]	//(DO3215015) Приход на механический ВУ ДС2
#define idA8IS12LDU	 159	//(DO3215015) Приход на механический ВУ ДС2
#define A8IS22LDU	 BUFFER[334]	//(DO3215016) Приход на механический НУ ДС2
#define idA8IS22LDU	 160	//(DO3215016) Приход на механический НУ ДС2
#define B8IS22LDU	 BUFFER[336]	//(DO3215017) Приход на механический НУ АЗ2
#define idB8IS22LDU	 161	//(DO3215017) Приход на механический НУ АЗ2
#define A6IS11LDU	 BUFFER[338]	//(DO3215018) Приход на ВУ БЗ1
#define idA6IS11LDU	 162	//(DO3215018) Приход на ВУ БЗ1
#define A2IE02LDU	 BUFFER[340]	//(DO3215019) Исправность ИП РБ1
#define idA2IE02LDU	 163	//(DO3215019) Исправность ИП РБ1
#define A2IE01LDU	 BUFFER[342]	//(DO3215020) Исправность БУШД РБ1
#define idA2IE01LDU	 164	//(DO3215020) Исправность БУШД РБ1
#define A2IE03LDU	 BUFFER[344]	//(DO3215021) Движение РБ1 вперед (от БУШД)
#define idA2IE03LDU	 165	//(DO3215021) Движение РБ1 вперед (от БУШД)
#define A2IE04LDU	 BUFFER[346]	//(DO3215022) Движение РБ1 назад (от БУШД)
#define idA2IE04LDU	 166	//(DO3215022) Движение РБ1 назад (от БУШД)
#define A3IE02LDU	 BUFFER[348]	//(DO3215023) Исправность ИП ИС1
#define idA3IE02LDU	 167	//(DO3215023) Исправность ИП ИС1
#define A3IE01LDU	 BUFFER[350]	//(DO3215024) Исправность БУШД ИС1
#define idA3IE01LDU	 168	//(DO3215024) Исправность БУШД ИС1
#define A3IE03LDU	 BUFFER[352]	//(DO3215025) Движение ИС1 вперед (от БУШД)
#define idA3IE03LDU	 169	//(DO3215025) Движение ИС1 вперед (от БУШД)
#define A3IE04LDU	 BUFFER[354]	//(DO3215026) Движение ИС1 назад (от БУШД)
#define idA3IE04LDU	 170	//(DO3215026) Движение ИС1 назад (от БУШД)
#define B1IE02LDU	 BUFFER[356]	//(DO3215027) Исправность ИП ББ2
#define idB1IE02LDU	 171	//(DO3215027) Исправность ИП ББ2
#define B1IE01LDU	 BUFFER[358]	//(DO3215028) Исправность БУШД ББ2
#define idB1IE01LDU	 172	//(DO3215028) Исправность БУШД ББ2
#define B2IE02LDU	 BUFFER[360]	//(DO3215029) Исправность ИП РБ2
#define idB2IE02LDU	 173	//(DO3215029) Исправность ИП РБ2
#define B2IE01LDU	 BUFFER[362]	//(DO3215030) Исправность БУШД РБ2
#define idB2IE01LDU	 174	//(DO3215030) Исправность БУШД РБ2
#define B2IE03LDU	 BUFFER[364]	//(DO3215031) Движение РБ2 вперед (от БУШД)
#define idB2IE03LDU	 175	//(DO3215031) Движение РБ2 вперед (от БУШД)
#define B2IE04LDU	 BUFFER[366]	//(DO3215032) Движение РБ2 назад (от БУШД)
#define idB2IE04LDU	 176	//(DO3215032) Движение РБ2 назад (от БУШД)
#define B3IE02LDU	 BUFFER[368]	//(DO3216001) Исправность ИП ИС2
#define idB3IE02LDU	 177	//(DO3216001) Исправность ИП ИС2
#define B3IE01LDU	 BUFFER[370]	//(DO3216002) Исправность БУШД ИС2
#define idB3IE01LDU	 178	//(DO3216002) Исправность БУШД ИС2
#define B3IE03LDU	 BUFFER[372]	//(DO3216003) Движение ИС2 вперед (от БУШД)
#define idB3IE03LDU	 179	//(DO3216003) Движение ИС2 вперед (от БУШД)
#define B3IE04LDU	 BUFFER[374]	//(DO3216004) Движение ИС2 назад (от БУШД)
#define idB3IE04LDU	 180	//(DO3216004) Движение ИС2 назад (от БУШД)
#define R6IS61LDU	 BUFFER[376]	//(DO3216005) Исправность 3-х  фазной сети
#define idR6IS61LDU	 181	//(DO3216005) Исправность 3-х  фазной сети
#define R4VS12LDU	 BUFFER[378]	//(DO3216006) Движение реактора  к «У ОБРАЗЦОВ»
#define idR4VS12LDU	 182	//(DO3216006) Движение реактора  к «У ОБРАЗЦОВ»
#define R4VS22LDU	 BUFFER[380]	//(DO3216007) Движение реактора к «У ЗАЩИТЫ»
#define idR4VS22LDU	 183	//(DO3216007) Движение реактора к «У ЗАЩИТЫ»
#define A8IE01LDU	 BUFFER[382]	//(DO3216008) Исправность ИП ДС2
#define idA8IE01LDU	 184	//(DO3216008) Исправность ИП ДС2
#define R1VS12LDU	 BUFFER[384]	//(DO3216009) Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	 185	//(DO3216009) Движение МДЗ1 в сторону ВУ
#define R1VS22LDU	 BUFFER[386]	//(DO3216010) Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	 186	//(DO3216010) Движение МДЗ1 в сторону НУ
#define R1IE01LDU	 BUFFER[388]	//(DO3216011) Исправность ИП МДЗ1
#define idR1IE01LDU	 187	//(DO3216011) Исправность ИП МДЗ1
#define R2VS12LDU	 BUFFER[390]	//(DO3216012) Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	 188	//(DO3216012) Движение МДЗ2 в сторону ВУ
#define R2VS22LDU	 BUFFER[392]	//(DO3216013) Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	 189	//(DO3216013) Движение МДЗ2 в сторону НУ
#define R2IE01LDU	 BUFFER[394]	//(DO3216014) Исправность ИП МДЗ2
#define idR2IE01LDU	 190	//(DO3216014) Исправность ИП МДЗ2
#define A5VS12LDU	 BUFFER[396]	//(DO3216015) Движение НЛ1 в сторону ВУ
#define idA5VS12LDU	 191	//(DO3216015) Движение НЛ1 в сторону ВУ
#define A5VS22LDU	 BUFFER[398]	//(DO3216016) Движение НЛ1 в сторону НУ
#define idA5VS22LDU	 192	//(DO3216016) Движение НЛ1 в сторону НУ
#define A5IE02LDU	 BUFFER[400]	//(DO3216017) Исправность ИП НЛ1
#define idA5IE02LDU	 193	//(DO3216017) Исправность ИП НЛ1
#define B5VS12LDU	 BUFFER[402]	//(DO3216018) Движение НЛ2 в сторону ВУ
#define idB5VS12LDU	 194	//(DO3216018) Движение НЛ2 в сторону ВУ
#define B5VS22LDU	 BUFFER[404]	//(DO3216019) Движение НЛ2 в сторону НУ
#define idB5VS22LDU	 195	//(DO3216019) Движение НЛ2 в сторону НУ
#define B5IE01LDU	 BUFFER[406]	//(DO3216020) Исправность ИП НЛ2
#define idB5IE01LDU	 196	//(DO3216020) Исправность ИП НЛ2
#define A6VS12LDU	 BUFFER[408]	//(DO3216021) Движение створок БЗ1  к  «ОТКРЫТА»
#define idA6VS12LDU	 197	//(DO3216021) Движение створок БЗ1  к  «ОТКРЫТА»
#define A6VS22LDU	 BUFFER[410]	//(DO3216022) Движение створок БЗ1  к «ЗАКРЫТА»
#define idA6VS22LDU	 198	//(DO3216022) Движение створок БЗ1  к «ЗАКРЫТА»
#define A6IE01LDU	 BUFFER[412]	//(DO3216023) Исправность ИП БЗ1
#define idA6IE01LDU	 199	//(DO3216023) Исправность ИП БЗ1
#define B6VS12LDU	 BUFFER[414]	//(DO3216024) Движение створок БЗ2  к  «ОТКРЫТА»
#define idB6VS12LDU	 200	//(DO3216024) Движение створок БЗ2  к  «ОТКРЫТА»
#define B6VS22LDU	 BUFFER[416]	//(DO3216025) Движение створок БЗ2  к «ЗАКРЫТА»
#define idB6VS22LDU	 201	//(DO3216025) Движение створок БЗ2  к «ЗАКРЫТА»
#define B6IE01LDU	 BUFFER[418]	//(DO3216026) Исправность ИП БЗ2
#define idB6IE01LDU	 202	//(DO3216026) Исправность ИП БЗ2
#define R0IE02LDU	 BUFFER[420]	//(DO3216027) Исправность ИП 24 В-1
#define idR0IE02LDU	 203	//(DO3216027) Исправность ИП 24 В-1
#define R0IE01LDU	 BUFFER[422]	//(DO3216028) Исправность ИП 24 В-2
#define idR0IE01LDU	 204	//(DO3216028) Исправность ИП 24 В-2
#define R6IS62LDU	 BUFFER[424]	//(DO3216029) Исправность ВИП ССДИ-39 1канал
#define idR6IS62LDU	 205	//(DO3216029) Исправность ВИП ССДИ-39 1канал
#define R6IS63LDU	 BUFFER[426]	//(DO3216030) Исправность ВИП ССДИ-39 2канал
#define idR6IS63LDU	 206	//(DO3216030) Исправность ВИП ССДИ-39 2канал
#define R6IS64LDU	 BUFFER[428]	//(DO3216031) Исправность ВИП ССДИ-35 1канал
#define idR6IS64LDU	 207	//(DO3216031) Исправность ВИП ССДИ-35 1канал
#define R6IS65LDU	 BUFFER[430]	//(DO3216032) Исправность ВИП ССДИ-35 2канал
#define idR6IS65LDU	 208	//(DO3216032) Исправность ВИП ССДИ-35 2канал
#define R0IC00LDU	 BUFFER[432]	//!!!(DO3212001) ENCODER?
#define idR0IC00LDU	 209	//!!!(DO3212001) ENCODER?
#define R0IC01LDU	 BUFFER[434]	//!!!(DO3212002) ENCODER?
#define idR0IC01LDU	 210	//!!!(DO3212002) ENCODER?
#define R0IC02LDU	 BUFFER[436]	//!!!(DO3212003) ENCODER?
#define idR0IC02LDU	 211	//!!!(DO3212003) ENCODER?
#define R0IC03LDU	 BUFFER[438]	//!!!(DO3212004) ENCODER?
#define idR0IC03LDU	 212	//!!!(DO3212004) ENCODER?
#define R0IC04LDU	 BUFFER[440]	//!!!(DO3212005) ENCODER?
#define idR0IC04LDU	 213	//!!!(DO3212005) ENCODER?
#define R0IC05LDU	 BUFFER[442]	//!!!(DO3212006) ENCODER?
#define idR0IC05LDU	 214	//!!!(DO3212006) ENCODER?
#define R0IC06LDU	 BUFFER[444]	//!!!(DO3212007) ENCODER?
#define idR0IC06LDU	 215	//!!!(DO3212007) ENCODER?
#define R0IC07LDU	 BUFFER[446]	//!!!(DO3212008) ENCODER?
#define idR0IC07LDU	 216	//!!!(DO3212008) ENCODER?
#define R0IC08LDU	 BUFFER[448]	//!!!(DO3212009) ENCODER?
#define idR0IC08LDU	 217	//!!!(DO3212009) ENCODER?
#define R0IC09LDU	 BUFFER[450]	//!!!(DO3212010) ENCODER?
#define idR0IC09LDU	 218	//!!!(DO3212010) ENCODER?
#define R0IC10LDU	 BUFFER[452]	//!!!(DO3212011) ENCODER?
#define idR0IC10LDU	 219	//!!!(DO3212011) ENCODER?
#define R0IC11LDU	 BUFFER[454]	//!!!(DO3212012) ENCODER?
#define idR0IC11LDU	 220	//!!!(DO3212012) ENCODER?
#define R0IC12LDU	 BUFFER[456]	//!!!(DO3212013) ENCODER?
#define idR0IC12LDU	 221	//!!!(DO3212013) ENCODER?
#define R0IC13LDU	 BUFFER[458]	//!!!(DO3212014) ENCODER?
#define idR0IC13LDU	 222	//!!!(DO3212014) ENCODER?
#define R0IC14LDU	 BUFFER[460]	//!!!(DO3212015) ENCODER?
#define idR0IC14LDU	 223	//!!!(DO3212015) ENCODER?
#define R0IC15LDU	 BUFFER[462]	//!!!(DO3212016) ENCODER?
#define idR0IC15LDU	 224	//!!!(DO3212016) ENCODER?
#define R0IC16LDU	 BUFFER[464]	//!!!(DO3212017) ENCODER?
#define idR0IC16LDU	 225	//!!!(DO3212017) ENCODER?
#define R0IC17LDU	 BUFFER[466]	//!!!(DO3212018) ENCODER?
#define idR0IC17LDU	 226	//!!!(DO3212018) ENCODER?
#define R0IC18LDU	 BUFFER[468]	//!!!(DO3212019) ENCODER?
#define idR0IC18LDU	 227	//!!!(DO3212019) ENCODER?
#define R0IC19LDU	 BUFFER[470]	//!!!(DO3212020) ENCODER?
#define idR0IC19LDU	 228	//!!!(DO3212020) ENCODER?
#define R0IC20LDU	 BUFFER[472]	//!!!(DO3212021) ENCODER?
#define idR0IC20LDU	 229	//!!!(DO3212021) ENCODER?
#define R0IC21LDU	 BUFFER[474]	//!!!(DO3212022) ENCODER?
#define idR0IC21LDU	 230	//!!!(DO3212022) ENCODER?
#define R0IC22LDU	 BUFFER[476]	//!!!(DO3212023) ENCODER?
#define idR0IC22LDU	 231	//!!!(DO3212023) ENCODER?
#define R0IC23LDU	 BUFFER[478]	//!!!(DO3212024) ENCODER?
#define idR0IC23LDU	 232	//!!!(DO3212024) ENCODER?
#define R0IC24LDU	 BUFFER[480]	//!!!(DO3212025) ENCODER?
#define idR0IC24LDU	 233	//!!!(DO3212025) ENCODER?
#define R0IC25LDU	 BUFFER[482]	//!!!(DO3212026) ENCODER?
#define idR0IC25LDU	 234	//!!!(DO3212026) ENCODER?
#define R0IC26LDU	 BUFFER[484]	//!!!(DO3212027) ENCODER?
#define idR0IC26LDU	 235	//!!!(DO3212027) ENCODER?
#define R0IC27LDU	 BUFFER[486]	//!!!(DO3212028) ENCODER?
#define idR0IC27LDU	 236	//!!!(DO3212028) ENCODER?
#define R0IC28LDU	 BUFFER[488]	//!!!(DO3212029) ENCODER?
#define idR0IC28LDU	 237	//!!!(DO3212029) ENCODER?
#define R0IC29LDU	 BUFFER[490]	//!!!(DO3212030) ENCODER?
#define idR0IC29LDU	 238	//!!!(DO3212030) ENCODER?
#define R0IC30LDU	 BUFFER[492]	//!!!(DO3212031) ENCODER?
#define idR0IC30LDU	 239	//!!!(DO3212031) ENCODER?
#define R0IC31LDU	 BUFFER[494]	//!!!(DO3212032) ENCODER?
#define idR0IC31LDU	 240	//!!!(DO3212032) ENCODER?
#define A1IC01LDU	 BUFFER[496]	//(VDSR34001) BUS1_ББ1
#define idA1IC01LDU	 241	//(VDSR34001) BUS1_ББ1
#define B1IC01LDU	 BUFFER[498]	//(VDSR34002) BUS2_ББ2
#define idB1IC01LDU	 242	//(VDSR34002) BUS2_ББ2
#define A2IC01LDU	 BUFFER[500]	//(VDSR34003) BUS3_РБ1
#define idA2IC01LDU	 243	//(VDSR34003) BUS3_РБ1
#define B2IC01LDU	 BUFFER[502]	//(VDSR34004) BUS4_РБ2
#define idB2IC01LDU	 244	//(VDSR34004) BUS4_РБ2
#define A3IC01LDU	 BUFFER[504]	//(VDSR34005) BUS5_ИС1
#define idA3IC01LDU	 245	//(VDSR34005) BUS5_ИС1
#define B3IC01LDU	 BUFFER[506]	//(VDSR34006) BUS6_ИС2
#define idB3IC01LDU	 246	//(VDSR34006) BUS6_ИС2
#define B8IC01LDU	 BUFFER[508]	//(VDSR34007) BUS7_АЗ2
#define idB8IC01LDU	 247	//(VDSR34007) BUS7_АЗ2
#define A8IC01LDU	 BUFFER[510]	//(VDSR34008) BUS8_ДС2
#define idA8IC01LDU	 248	//(VDSR34008) BUS8_ДС2
#define R0IC41LDU	 BUFFER[512]	//(VDSR34009) LUTCH
#define idR0IC41LDU	 249	//(VDSR34009) LUTCH
#define R0IC42LDU	 BUFFER[514]	//(VDSR34010) Вход запрета
#define idR0IC42LDU	 250	//(VDSR34010) Вход запрета
#define R0IC43LDU	 BUFFER[516]	//(VDSR34011) Выход запрета
#define idR0IC43LDU	 251	//(VDSR34011) Выход запрета
#define A3AD34LDU	 BUFFER[518]	//(VDSR34012) Клапан ВПИС1  открыть (обесточить)
#define idA3AD34LDU	 252	//(VDSR34012) Клапан ВПИС1  открыть (обесточить)
#define A3AD33LDU	 BUFFER[520]	//(VDSR34013) Клапан «ВЫСТРЕЛ ИС1» открыть (обесточить)
#define idA3AD33LDU	 253	//(VDSR34013) Клапан «ВЫСТРЕЛ ИС1» открыть (обесточить)
#define A2AD33LDU	 BUFFER[522]	//(VDSR34014) Клапан «Подъем РБ1» открыть
#define idA2AD33LDU	 254	//(VDSR34014) Клапан «Подъем РБ1» открыть
#define A4AD10LDU	 BUFFER[524]	//(VDSR34015) Открыть клапан Подъем НИ1
#define idA4AD10LDU	 255	//(VDSR34015) Открыть клапан Подъем НИ1
#define A3AD31LDU	 BUFFER[526]	//(VDSR34016) Клапан «СПУСК ИС1» открыть (обесточить)
#define idA3AD31LDU	 256	//(VDSR34016) Клапан «СПУСК ИС1» открыть (обесточить)
#define A7AP31LDU	 BUFFER[528]	//(VDSR34017) Клапан «Обдув АЗ1» открыть (обесточить)
#define idA7AP31LDU	 257	//(VDSR34017) Клапан «Обдув АЗ1» открыть (обесточить)
#define R1AD10LDU	 BUFFER[530]	//(VDSR34018) Опустить МДЗ1 в зону облучения
#define idR1AD10LDU	 258	//(VDSR34018) Опустить МДЗ1 в зону облучения
#define R1AD20LDU	 BUFFER[532]	//(VDSR34019) Поднять МДЗ1
#define idR1AD20LDU	 259	//(VDSR34019) Поднять МДЗ1
#define R2AD10LDU	 BUFFER[534]	//(VDSR34020) Опустить МДЗ2 в зону облучения
#define idR2AD10LDU	 260	//(VDSR34020) Опустить МДЗ2 в зону облучения
#define R2AD20LDU	 BUFFER[536]	//(VDSR34021) Поднять МДЗ2
#define idR2AD20LDU	 261	//(VDSR34021) Поднять МДЗ2
#define A5AD10LDU	 BUFFER[538]	//(VDSR34022) Поднять НЛ1
#define idA5AD10LDU	 262	//(VDSR34022) Поднять НЛ1
#define A5AD20LDU	 BUFFER[540]	//(VDSR34023) Опустить НЛ1
#define idA5AD20LDU	 263	//(VDSR34023) Опустить НЛ1
#define B5AD10LDU	 BUFFER[542]	//(VDSR34024) Поднять НЛ2
#define idB5AD10LDU	 264	//(VDSR34024) Поднять НЛ2
#define B5AD20LDU	 BUFFER[544]	//(VDSR34025) Опустить НЛ2
#define idB5AD20LDU	 265	//(VDSR34025) Опустить НЛ2
#define B3AD34LDU	 BUFFER[546]	//(VDSR34026) Клапан ВПИС ИС2  открыть (обесточить)
#define idB3AD34LDU	 266	//(VDSR34026) Клапан ВПИС ИС2  открыть (обесточить)
#define B3AD33LDU	 BUFFER[548]	//(VDSR34027) Клапан «ВЫСТРЕЛ ИС2» закрыть (обесточить)
#define idB3AD33LDU	 267	//(VDSR34027) Клапан «ВЫСТРЕЛ ИС2» закрыть (обесточить)
#define B2AD33LDU	 BUFFER[550]	//(VDSR34028) Клапан «Подъем РБ2» открыть
#define idB2AD33LDU	 268	//(VDSR34028) Клапан «Подъем РБ2» открыть
#define B4AD10LDU	 BUFFER[552]	//(VDSR34029) Открыть клапан Подъем НИ2
#define idB4AD10LDU	 269	//(VDSR34029) Открыть клапан Подъем НИ2
#define B3AD31LDU	 BUFFER[554]	//(VDSR34030) Клапан «СПУСК ИС2» открыть (обесточить)
#define idB3AD31LDU	 270	//(VDSR34030) Клапан «СПУСК ИС2» открыть (обесточить)
#define B7AP31LDU	 BUFFER[556]	//(VDSR34031) Клапан «Обдув АЗ2» открыть (обесточить)
#define idB7AP31LDU	 271	//(VDSR34031) Клапан «Обдув АЗ2» открыть (обесточить)
#define A8AD10LDU	 BUFFER[558]	//(VDSR34032) Перемещение ДС2 вперед
#define idA8AD10LDU	 272	//(VDSR34032) Перемещение ДС2 вперед
#define A8AD20LDU	 BUFFER[560]	//(A8AD20LDU) Перемещение ДС2 назад
#define idA8AD20LDU	 273	//(A8AD20LDU) Перемещение ДС2 назад
#define A6AD10LDU	 BUFFER[562]	//(A6AD10LDU) Открыть БЗ1
#define idA6AD10LDU	 274	//(A6AD10LDU) Открыть БЗ1
#define A6AD20LDU	 BUFFER[564]	//(A6AD20LDU) Закрыть БЗ1
#define idA6AD20LDU	 275	//(A6AD20LDU) Закрыть БЗ1
#define B6AD10LDU	 BUFFER[566]	//(B6AD10LDU) Открыть БЗ2
#define idB6AD10LDU	 276	//(B6AD10LDU) Открыть БЗ2
#define B6AD20LDU	 BUFFER[568]	//(B6AD20LDU) Закрыть БЗ2
#define idB6AD20LDU	 277	//(B6AD20LDU) Закрыть БЗ2
#define R4AD10LDU	 BUFFER[570]	//(R4AD10LDU) Перемещение тележки вперед
#define idR4AD10LDU	 278	//(R4AD10LDU) Перемещение тележки вперед
#define R4AD20LDU	 BUFFER[572]	//(R4AD20LDU) Перемещение тележки назад
#define idR4AD20LDU	 279	//(R4AD20LDU) Перемещение тележки назад
#define B8AD10LDU	 BUFFER[574]	//(B8AD10LDU) Перемещение АЗ2 вперед
#define idB8AD10LDU	 280	//(B8AD10LDU) Перемещение АЗ2 вперед
#define B8AD20LDU	 BUFFER[576]	//(B8AD20LDU) Перемещение АЗ2 назад
#define idB8AD20LDU	 281	//(B8AD20LDU) Перемещение АЗ2 назад
#define A3AD11LDU	 BUFFER[578]	//(A3AD11LDU) Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	 282	//(A3AD11LDU) Сигнал на перемещение ИС1 вверх
#define A3AD21LDU	 BUFFER[580]	//(A3AD21LDU) Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	 283	//(A3AD21LDU) Сигнал на перемещение ИС1 вниз
#define A3AD01LDU	 BUFFER[582]	//(A3AD01LDU) Разрешение движения ИС1
#define idA3AD01LDU	 284	//(A3AD01LDU) Разрешение движения ИС1
#define A3AD02LDU	 BUFFER[584]	//(A3AD02LDU) 0-й бит скорости ИС1
#define idA3AD02LDU	 285	//(A3AD02LDU) 0-й бит скорости ИС1
#define A3AD03LDU	 BUFFER[586]	//(A3AD03LDU) 1-й бит скорости ИС1
#define idA3AD03LDU	 286	//(A3AD03LDU) 1-й бит скорости ИС1
#define A3AD04LDU	 BUFFER[588]	//(A3AD04LDU) 2-й бит скорости ИС1
#define idA3AD04LDU	 287	//(A3AD04LDU) 2-й бит скорости ИС1
#define A3AD05LDU	 BUFFER[590]	//(A3AD05LDU) паритет команды на ИС1
#define idA3AD05LDU	 288	//(A3AD05LDU) паритет команды на ИС1
#define B3AD11LDU	 BUFFER[592]	//(B3AD11LDU) Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	 289	//(B3AD11LDU) Сигнал на перемещение ИС2 вверх
#define B3AD21LDU	 BUFFER[594]	//(B3AD21LDU) Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	 290	//(B3AD21LDU) Сигнал на перемещение ИС2 вниз
#define B3AD01LDU	 BUFFER[596]	//(B3AD01LDU) Разрешение движения ИС2
#define idB3AD01LDU	 291	//(B3AD01LDU) Разрешение движения ИС2
#define B3AD02LDU	 BUFFER[598]	//(B3AD02LDU) 0-й бит скорости ИС2
#define idB3AD02LDU	 292	//(B3AD02LDU) 0-й бит скорости ИС2
#define B3AD03LDU	 BUFFER[600]	//(B3AD03LDU) 1-й бит скорости ИС2
#define idB3AD03LDU	 293	//(B3AD03LDU) 1-й бит скорости ИС2
#define B3AD04LDU	 BUFFER[602]	//(B3AD04LDU) 2-й бит скорости ИС2
#define idB3AD04LDU	 294	//(B3AD04LDU) 2-й бит скорости ИС2
#define B3AD05LDU	 BUFFER[604]	//(B3AD05LDU) паритет команды на ИС2
#define idB3AD05LDU	 295	//(B3AD05LDU) паритет команды на ИС2
#define A9AD10LDU	 BUFFER[606]	//(A9AD10LDU) Открыть клапан Подъем НИ ДС1
#define idA9AD10LDU	 296	//(A9AD10LDU) Открыть клапан Подъем НИ ДС1
#define B9AD10LDU	 BUFFER[608]	//(B9AD10LDU) Открыть клапан Подъем НИ ДС2
#define idB9AD10LDU	 297	//(B9AD10LDU) Открыть клапан Подъем НИ ДС2
#define A1AD11LDU	 BUFFER[610]	//(A1AD11LDU) Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	 298	//(A1AD11LDU) Сигнал на перемещение ББ1 вверх
#define A1AD21LDU	 BUFFER[612]	//(A1AD21LDU) Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	 299	//(A1AD21LDU) Сигнал на перемещение ББ1 вниз
#define A1AD01LDU	 BUFFER[614]	//(A1AD01LDU) Разрешение движения ББ1
#define idA1AD01LDU	 300	//(A1AD01LDU) Разрешение движения ББ1
#define A1AD02LDU	 BUFFER[616]	//(A1AD02LDU) 0-й бит скорости ББ1
#define idA1AD02LDU	 301	//(A1AD02LDU) 0-й бит скорости ББ1
#define A1AD03LDU	 BUFFER[618]	//(A1AD03LDU) 1-й бит скорости ББ1
#define idA1AD03LDU	 302	//(A1AD03LDU) 1-й бит скорости ББ1
#define A1AD04LDU	 BUFFER[620]	//(A1AD04LDU) 2-й бит скорости ББ1
#define idA1AD04LDU	 303	//(A1AD04LDU) 2-й бит скорости ББ1
#define VDSR36032	 BUFFER[622]	//!!!(DO3211032) не занята
#define idVDSR36032	 304	//!!!(DO3211032) не занята
#define A1AD05LDU	 BUFFER[624]	//(VDSR31001) паритет команды на ББ1
#define idA1AD05LDU	 305	//(VDSR31001) паритет команды на ББ1
#define B1AD11LDU	 BUFFER[626]	//(VDSR31002) Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	 306	//(VDSR31002) Сигнал на перемещение ББ2 вверх
#define B1AD21LDU	 BUFFER[628]	//(VDSR31003) Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	 307	//(VDSR31003) Сигнал на перемещение ББ2 вниз
#define B1AD01LDU	 BUFFER[630]	//(VDSR31004) Разрешение движения ББ2
#define idB1AD01LDU	 308	//(VDSR31004) Разрешение движения ББ2
#define B1AD02LDU	 BUFFER[632]	//(VDSR31005) 0-й бит скорости ББ2
#define idB1AD02LDU	 309	//(VDSR31005) 0-й бит скорости ББ2
#define B1AD03LDU	 BUFFER[634]	//(VDSR31006) 1-й бит скорости ББ2
#define idB1AD03LDU	 310	//(VDSR31006) 1-й бит скорости ББ2
#define B1AD04LDU	 BUFFER[636]	//(VDSR31007) 2-й бит скорости ББ2
#define idB1AD04LDU	 311	//(VDSR31007) 2-й бит скорости ББ2
#define B1AD05LDU	 BUFFER[638]	//(VDSR31008) паритет команды на ББ2
#define idB1AD05LDU	 312	//(VDSR31008) паритет команды на ББ2
#define A2AD11LDU	 BUFFER[640]	//(VDSR31009) Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	 313	//(VDSR31009) Сигнал на перемещение РБ1 вверх
#define A2AD21LDU	 BUFFER[642]	//(VDSR31010) Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	 314	//(VDSR31010) Сигнал на перемещение РБ1 вниз
#define A2AD01LDU	 BUFFER[644]	//(VDSR31011) Разрешение движения РБ1
#define idA2AD01LDU	 315	//(VDSR31011) Разрешение движения РБ1
#define A2AD02LDU	 BUFFER[646]	//(VDSR31012) 0-й бит скорости РБ1
#define idA2AD02LDU	 316	//(VDSR31012) 0-й бит скорости РБ1
#define A2AD03LDU	 BUFFER[648]	//(VDSR31013) 1-й бит скорости РБ1
#define idA2AD03LDU	 317	//(VDSR31013) 1-й бит скорости РБ1
#define A2AD04LDU	 BUFFER[650]	//(VDSR31014) 2-й бит скорости РБ1
#define idA2AD04LDU	 318	//(VDSR31014) 2-й бит скорости РБ1
#define A2AD05LDU	 BUFFER[652]	//(VDSR31015) паритет команды на РБ1
#define idA2AD05LDU	 319	//(VDSR31015) паритет команды на РБ1
#define B2AD11LDU	 BUFFER[654]	//(VDSR31016) Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	 320	//(VDSR31016) Сигнал на перемещение РБ2 вверх
#define B2AD21LDU	 BUFFER[656]	//(VDSR31017) Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	 321	//(VDSR31017) Сигнал на перемещение РБ2 вниз
#define B2AD01LDU	 BUFFER[658]	//(VDSR31018) Разрешение движения РБ2
#define idB2AD01LDU	 322	//(VDSR31018) Разрешение движения РБ2
#define B2AD02LDU	 BUFFER[660]	//(VDSR31019) 0-й бит скорости РБ2
#define idB2AD02LDU	 323	//(VDSR31019) 0-й бит скорости РБ2
#define B2AD03LDU	 BUFFER[662]	//(VDSR31020) 1-й бит скорости РБ2
#define idB2AD03LDU	 324	//(VDSR31020) 1-й бит скорости РБ2
#define B2AD04LDU	 BUFFER[664]	//(VDSR31021) 2-й бит скорости РБ2
#define idB2AD04LDU	 325	//(VDSR31021) 2-й бит скорости РБ2
#define B2AD05LDU	 BUFFER[666]	//(VDSR31022) паритет команды на РБ2
#define idB2AD05LDU	 326	//(VDSR31022) паритет команды на РБ2
#define A1AD32LDU	 BUFFER[668]	//(VDSR31023) Обесточить ЭМ ББ1
#define idA1AD32LDU	 327	//(VDSR31023) Обесточить ЭМ ББ1
#define A1AD31LDU	 BUFFER[670]	//(VDSR31024) Клапан «Сброс ББ1» открыть (обесточить)
#define idA1AD31LDU	 328	//(VDSR31024) Клапан «Сброс ББ1» открыть (обесточить)
#define A2AD32LDU	 BUFFER[672]	//(VDSR31025) Обесточить ЭМ РБ1
#define idA2AD32LDU	 329	//(VDSR31025) Обесточить ЭМ РБ1
#define A2AD31LDU	 BUFFER[674]	//(VDSR31026) Клапан «Сброс РБ1» открыть (обесточить)
#define idA2AD31LDU	 330	//(VDSR31026) Клапан «Сброс РБ1» открыть (обесточить)
#define B1AD32LDU	 BUFFER[676]	//(VDSR31027) Обесточить ЭМ ББ2
#define idB1AD32LDU	 331	//(VDSR31027) Обесточить ЭМ ББ2
#define B1AD31LDU	 BUFFER[678]	//(VDSR31028) Клапан «Сброс ББ2» открыть (обесточить)
#define idB1AD31LDU	 332	//(VDSR31028) Клапан «Сброс ББ2» открыть (обесточить)
#define B2AD32LDU	 BUFFER[680]	//(VDSR31029) Обесточить ЭМ РБ2
#define idB2AD32LDU	 333	//(VDSR31029) Обесточить ЭМ РБ2
#define B2AD31LDU	 BUFFER[682]	//(VDSR31030) Клапан «Сброс РБ2» открыть (обесточить)
#define idB2AD31LDU	 334	//(VDSR31030) Клапан «Сброс РБ2» открыть (обесточить)
#define R8AD21LDU	 BUFFER[684]	//(VDSR31031) Запуск системы инициирования
#define idR8AD21LDU	 335	//(VDSR31031) Запуск системы инициирования
#define R0AD16LDU	 BUFFER[686]	//(VDSR31032) Контроль  I-II УР. РАД
#define idR0AD16LDU	 336	//(VDSR31032) Контроль  I-II УР. РАД
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,3	,1	, &A0IT01IZ1},	//(AO1632001) Температура АЗ1-1
	{ 2	,3	,1	, &A2IP01IZ1},	//(AO1632002) Текущее давление СБРОС РБ1
	{ 3	,3	,1	, &B0IT01IZ1},	//(AO1632003) Температура АЗ2-1
	{ 4	,3	,1	, &B2IP01IZ1},	//(AO1632004) Текущее давление СБРОС РБ2
	{ 5	,3	,1	, &A0IT02IZ2},	//(AO1632005) Температура АЗ1-2
	{ 6	,3	,1	, &A2IP01IZ2},	//(AO1632006) Текущее давление СБРОС РБ1
	{ 7	,3	,1	, &B0IT02IZ2},	//(AO1632007) Температура АЗ2-2
	{ 8	,3	,1	, &B2IP01IZ2},	//(AO1632008) Текущее давление СБРОС РБ2
	{ 9	,3	,1	, &A3IP02IDU},	//(AO1632009) Текущее давление ВЫСТРЕЛ ИС1
	{ 10	,3	,1	, &B3IP02IDU},	//(AO1632010) Текущее давление ВЫСТРЕЛ ИС2
	{ 11	,3	,1	, &AO1632011},	//!!!(AO1632011) Не занятые значения
	{ 12	,3	,1	, &AO1632012},	//!!!(AO1632012) Не занятые значения
	{ 13	,3	,1	, &AO1632013},	//!!!(AO1632013) Не занятые значения
	{ 14	,3	,1	, &AO1632014},	//!!!(AO1632014) Не занятые значения
	{ 15	,3	,1	, &AO1632015},	//!!!(AO1632015) Не занятые значения
	{ 16	,3	,1	, &AO1632016},	//!!!(AO1632016) Не занятые значения
	{ 17	,1	,1	, &R0VN71LZ1},	//(DO3210001) АС по мощности канал 1
	{ 18	,1	,1	, &R0VN75LZ1},	//(DO3210002) АС по периоду разгона канал  1
	{ 19	,1	,1	, &A0EE01LS1},	//(DO3210003) Исправность АКНП канал 1 
	{ 20	,1	,1	, &A0VN71LS1},	//(DO3210004) Блокировка автоматического подъёма ББ канал 1
	{ 21	,1	,1	, &A3IS11LZ1},	//(DO3210005) Приход на ВУ ИС1
	{ 22	,1	,1	, &A3IS22LZ1},	//(DO3210006) Приход на НУП ИС1
	{ 23	,1	,1	, &R0VN72LZ1},	//(DO3210007) АС по мощности канал 2
	{ 24	,1	,1	, &R0VN76LZ1},	//(DO3210008) АС по периоду разгона канал  2
	{ 25	,1	,1	, &A0EE01LS2},	//(DO3210009) Исправность АКНП  канал 2
	{ 26	,1	,1	, &A0VN71LS2},	//(DO3210010) Блокировка автоматического подъёма ББ канал 2
	{ 27	,1	,1	, &B3IS11LZ1},	//(DO3210011) Приход на ВУ ИС2
	{ 28	,1	,1	, &B3IS22LZ1},	//(DO3210012) Приход на НУП ИС2
	{ 29	,1	,1	, &R0VN74LZ1},	//(DO3210013) АС по мощности канал 4
	{ 30	,1	,1	, &R0VN78LZ1},	//(DO3210014) АС по периоду разгона канал  4
	{ 31	,1	,1	, &A0EE01LS4},	//(DO3210015) Исправность АКНП канал 4
	{ 32	,1	,1	, &A0VN71LS4},	//(DO3210016) Блокировка автоматического подъёма ББ канал 4
	{ 33	,1	,1	, &R6IS66LZ1},	//(DO3210017) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 34	,1	,1	, &R6IS67LZ1},	//(DO3210018) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 35	,1	,1	, &R6IS68LZ1},	//(DO3210019) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 36	,1	,1	, &R0VN73LZ1},	//(DO3210020) АС по мощности канал 3
	{ 37	,1	,1	, &R0VN77LZ1},	//(DO3210021) АС по периоду разгона канал  3
	{ 38	,1	,1	, &A0EE01LS3},	//(DO3210022) Исправность АКНП канал 3
	{ 39	,1	,1	, &A0VN71LS3},	//(DO3210023) Блокировка автоматического подъёма ББ канал 3
	{ 40	,1	,1	, &R7II71LZ1},	//(DO3210024) Сработала АС IУР РАД (датчик 1)
	{ 41	,1	,1	, &R7II72LZ1},	//(DO3210025) Сработала АС IУР РАД  (датчик 2)
	{ 42	,1	,1	, &R7II73LZ1},	//(DO3210026) Сработала АС II УР РАД
	{ 43	,1	,1	, &A0VP81LZ1},	//(DO3210027) Давление  АЗ1 в норме
	{ 44	,1	,1	, &A1VP81LZ1},	//(DO3210028) Давление СБРОС ББ1 в норме
	{ 45	,1	,1	, &R0VP81LZ1},	//(DO3210029) Давление  в СИСТЕМЕ -1 в норме
	{ 46	,1	,1	, &B0VP81LZ1},	//(DO3210030) Давление АЗ2 в норме
	{ 47	,1	,1	, &B1VP81LZ1},	//(DO3210031) Давление СБРОС ББ2 в норме
	{ 48	,1	,1	, &R0VP82LZ1},	//(DO3210032) Давление  в СИСТЕМЕ - 2 в норме
	{ 49	,1	,1	, &R0VN71LZ2},	//(DO3211001) АС по мощности канал 1
	{ 50	,1	,1	, &R0VN75LZ2},	//(DO3211002) АС по периоду разгона канал  1
	{ 51	,1	,1	, &A1EE01LS1},	//(DO3211003) Исправность АКНП канал 1
	{ 52	,1	,1	, &A1VN71LS1},	//(DO3211004) Блокировка автоматического подъёма ББ канал 1
	{ 53	,1	,1	, &A3IS11LZ2},	//(DO3211005) Приход на ВУ ИС1
	{ 54	,1	,1	, &A3IS22LZ2},	//(DO3211006) Приход на НУП ИС1
	{ 55	,1	,1	, &R0VN72LZ2},	//(DO3211007) АС по мощности канал 2
	{ 56	,1	,1	, &R0VN76LZ2},	//(DO3211008) АС по периоду разгона канал  2
	{ 57	,1	,1	, &A1EE01LS2},	//(DO3211009) Исправность АКНП  канал 2
	{ 58	,1	,1	, &A1VN71LS2},	//(DO3211010) Блокировка автоматического подъёма ББ канал 2
	{ 59	,1	,1	, &B3IS11LZ2},	//(DO3211011) Приход на ВУ ИС2
	{ 60	,1	,1	, &B3IS22LZ2},	//(DO3211012) Приход на НУП ИС2
	{ 61	,1	,1	, &R0VN74LZ2},	//(DO3211013) АС по мощности канал 4
	{ 62	,1	,1	, &R0VN78LZ2},	//(DO3211014) АС по периоду разгона канал  4
	{ 63	,1	,1	, &A1EE01LS4},	//(DO3211015) Исправность АКНП канал 4
	{ 64	,1	,1	, &A1VN71LS4},	//(DO3211016) Блокировка автоматического подъёма ББ канал 4
	{ 65	,1	,1	, &R6IS66LZ2},	//(DO3211017) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 66	,1	,1	, &R6IS67LZ2},	//(DO3211018) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 67	,1	,1	, &R6IS68LZ2},	//(DO3211019) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 68	,1	,1	, &R0VN73LZ2},	//(DO3211020) АС по мощности канал 3
	{ 69	,1	,1	, &R0VN77LZ2},	//(DO3211021) АС по периоду разгона канал  3
	{ 70	,1	,1	, &A1EE01LS3},	//(DO3211022) Исправность АКНП канал 3
	{ 71	,1	,1	, &A1VN71LS3},	//(DO3211023) Блокировка автоматического подъёма ББ канал 3
	{ 72	,1	,1	, &R7II71LZ2},	//(DO3211024) Сработала АС IУР (датчик 1)
	{ 73	,1	,1	, &R7II72LZ2},	//(DO3211025) Сработала АС IУР (датчик 2)
	{ 74	,1	,1	, &R7II73LZ2},	//(DO3211026) Сработала АС IIУР
	{ 75	,1	,1	, &A0VP81LZ2},	//(DO3211027) Давление  АЗ1 в норме
	{ 76	,1	,1	, &A1VP81LZ2},	//(DO3211028) Давление СБРОС ББ1 в норме
	{ 77	,1	,1	, &R0VP81LZ2},	//(DO3211029) Давление  в СИСТЕМЕ -1 в норме
	{ 78	,1	,1	, &B0VP81LZ2},	//(DO3211030) Давление АЗ2 в норме
	{ 79	,1	,1	, &B1VP81LZ2},	//(DO3211031) Давление СБРОС ББ2 в норме
	{ 80	,1	,1	, &R0VP82LZ2},	//(DO3211032) Давление  в СИСТЕМЕ - 2 в норме
	{ 81	,1	,1	, &B3IS35LDU},	//(DO3213001) Клапан «ВПИС2» открыт (обесточен) 
	{ 82	,1	,1	, &B3IS33LDU},	//(DO3213002) Клапан «ВЫСТРЕЛ ИС2» открыт (обесточен) 
	{ 83	,1	,1	, &B2IS33LDU},	//(DO3213003) Клапан «Подъём РБ2» открыт (обесточен) 
	{ 84	,1	,1	, &B4IS10LDU},	//(DO3213004) Клапан «Подъём НИ2» открыт (обесточен) 
	{ 85	,1	,1	, &B3IS31LDU},	//(DO3213005) Клапан «СПУСК ИС2» открыт (обесточен) 
	{ 86	,1	,1	, &B7AS31LDU},	//(DO3213006) Клапан «Обдув АЗ2» открыт (обесточен) 
	{ 87	,1	,1	, &B1IS12LDU},	//(DO3213007) Магнит ББ2 зацеплен 
	{ 88	,1	,1	, &B1IS11LDU},	//(DO3213008) Приход на ВУ ББ2 
	{ 89	,1	,1	, &B1IS21LDU},	//(DO3213009) Приход на НУ ББ2 
	{ 90	,1	,1	, &B2IS12LDU},	//(DO3213010) Магнит РБ2 зацеплен 
	{ 91	,1	,1	, &B2IS11LDU},	//(DO3213011) Приход на ВУ РБ2-СТР 
	{ 92	,1	,1	, &B2IS21LDU},	//(DO3213012) Приход на НУ РБ2-СС 
	{ 93	,1	,1	, &B3IS21LDU},	//(DO3213013) Приход на НУ ИС2 
	{ 94	,1	,1	, &R8IS11LDU},	//(DO3213014) Аварийный НИ установлен 
	{ 95	,1	,1	, &DO3213015},	//(DO3213015) Не занятые значения
	{ 96	,1	,1	, &A4IS11LDU},	//(DO3213016) Приход на ВУ НИ1 
	{ 97	,1	,1	, &A4IS21LDU},	//(DO3213017) Приход на НУ НИ1 
	{ 98	,1	,1	, &A9IS11LDU},	//(DO3213018) Приход на ВУ НИ ДС1
	{ 99	,1	,1	, &A9IS21LDU},	//(DO3213019) Приход на НУ НИ ДС1
	{ 100	,1	,1	, &B9IS11LDU},	//(DO3213020) Приход на ВУ НИ ДС2
	{ 101	,1	,1	, &B9IS21LDU},	//(DO3213021) Приход на НУ НИ ДС2
	{ 102	,1	,1	, &R1IS11LDU},	//(DO3213022) Приход на ВУ МДЗ1
	{ 103	,1	,1	, &R1IS21LDU},	//(DO3213023) Приход на НУ МДЗ1
	{ 104	,1	,1	, &R2IS11LDU},	//(DO3213024) Приход на ВУ МДЗ2
	{ 105	,1	,1	, &R2IS21LDU},	//(DO3213025) Приход на НУ МДЗ2
	{ 106	,1	,1	, &A3IS35LDU},	//(DO3213026) Клапан «ВПИС1» открыт (обесточен)
	{ 107	,1	,1	, &A3IS33LDU},	//(DO3213027) Клапан «ВЫСТРЕЛ ИС1» открыт (обесточен)
	{ 108	,1	,1	, &A2IS33LDU},	//(DO3213028) Клапан «Подъём РБ1» открыт (обесточен)
	{ 109	,1	,1	, &A4IS10LDU},	//(DO3213029) Клапан «Подъём НИ1» открыт (обесточен)
	{ 110	,1	,1	, &A3IS31LDU},	//(DO3213030) Клапан «СПУСК ИС1» открыт (обесточен)
	{ 111	,1	,1	, &A7AS31LDU},	//(DO3213031) Клапан «Обдув АЗ1» открыт (обесточен)
	{ 112	,1	,1	, &A1IS12LDU},	//(DO3213032) Магнит ББ1 зацеплен
	{ 113	,1	,1	, &A1IS11LDU},	//(DO3214001) Приход на ВУ ББ1
	{ 114	,1	,1	, &A1IS21LDU},	//(DO3214002) Приход на НУ ББ1
	{ 115	,1	,1	, &A2IS12LDU},	//(DO3214003) Магнит РБ1 зацеплен
	{ 116	,1	,1	, &A2IS11LDU},	//(DO3214004) Приход на ВУ РБ1-СТР
	{ 117	,1	,1	, &A2IS21LDU},	//(DO3214005) Приход на НУ РБ1-СС
	{ 118	,1	,1	, &A3IS21LDU},	//(DO3214006) Приход на НУ ИС1
	{ 119	,1	,1	, &B4IS11LDU},	//(DO3214007) Приход на ВУ НИ2
	{ 120	,1	,1	, &B4IS21LDU},	//(DO3214008) Приход на НУ НИ2
	{ 121	,1	,1	, &B8IS12LDU},	//(DO3214009) Приход на механический ВУ АЗ2
	{ 122	,1	,1	, &DO3214010},	//(DO3214010)
	{ 123	,1	,1	, &A3VP81LDU},	//(DO3214011) Давление СПУСК ИС1 в норме
	{ 124	,1	,1	, &A2VP82LDU},	//(DO3214012) Давление ПОДЪЁМ РБ1 в норме
	{ 125	,1	,1	, &A4VP82LDU},	//(DO3214013) Давление ПОДЪЁМ НИ1 в норме
	{ 126	,1	,1	, &B3VP81LDU},	//(DO3214014) Давление СПУСК ИС2 в норме
	{ 127	,1	,1	, &B2VP82LDU},	//(DO3214015) Давление ПОДЪЁМ РБ2 в норме
	{ 128	,1	,1	, &B4VP82LDU},	//(DO3214016) Давление ПОДЪЁМ НИ2 в норме
	{ 129	,1	,1	, &R0IS02LDU},	//(DO3214017) Разрешение ввода от имитатора
	{ 130	,1	,1	, &A3IS11LDU},	//(DO3214018) Приход на ВУ ИС1
	{ 131	,1	,1	, &A3IS22LDU},	//(DO3214019) Приход на НУП ИС1
	{ 132	,1	,1	, &B3IS11LDU},	//(DO3214020) Приход на ВУ ИС2
	{ 133	,1	,1	, &B3IS22LDU},	//(DO3214021) Приход на НУП ИС2
	{ 134	,1	,1	, &R4IS11LDU},	//(DO3214022) Приход на ВУ тележки
	{ 135	,1	,1	, &R4IS12LDU},	//(DO3214023) Приход на механический ВУ тележки
	{ 136	,1	,1	, &R4IS21LDU},	//(DO3214024) Приход на НУ тележки
	{ 137	,1	,1	, &R4IS22LDU},	//(DO3214025) Приход на механический НУ тележки
	{ 138	,1	,1	, &DO3214026},	//(DO3214026)
	{ 139	,1	,1	, &A6IS21LDU},	//(DO3214027) Приход на НУ БЗ1
	{ 140	,1	,1	, &A5IS11LDU},	//(DO3214028) Приход на ВУ НЛ1
	{ 141	,1	,1	, &A5IS21LDU},	//(DO3214029) Приход на НУ НЛ1
	{ 142	,1	,1	, &B6IS11LDU},	//(DO3214030) Приход на ВУ БЗ2
	{ 143	,1	,1	, &B6IS21LDU},	//(DO3214031) Приход на НУ БЗ2
	{ 144	,1	,1	, &B5IS11LDU},	//(DO3214032) Приход на ВУ НЛ2
	{ 145	,1	,1	, &B5IS21LDU},	//(DO3215001) Приход на НУ НЛ2
	{ 146	,1	,1	, &R3IS11LDU},	//(DO3215002) Приход на ВУ гомогенных дверей-1
	{ 147	,1	,1	, &R3IS21LDU},	//(DO3215003) Приход на НУ гомогенных дверей-1
	{ 148	,1	,1	, &R3IS31LDU},	//(DO3215004) Приход на ВУ гомогенных дверей-2
	{ 149	,1	,1	, &R3IS41LDU},	//(DO3215005) Приход на НУ гомогенных дверей-2
	{ 150	,1	,1	, &R3AD10LDU},	//(DO3215006) Гомогенные двери-1 открыть
	{ 151	,1	,1	, &R3AD11LDU},	//(DO3215007) Гомогенные двери-2 открыть
	{ 152	,1	,1	, &R3AD20LDU},	//(DO3215008) Гомогенные двери-1 закрыть
	{ 153	,1	,1	, &R3AD21LDU},	//(DO3215009) Гомогенные двери-2 закрыть
	{ 154	,1	,1	, &R5IS11LDU},	//(DO3215010) Приход на ВУ ворот отстойной зоны
	{ 155	,1	,1	, &R5IS21LDU},	//(DO3215011) Приход на НУ ворот отстойной зоны
	{ 156	,1	,1	, &R5AD10LDU},	//(DO3215012) Открыть ворота отстойной зоны
	{ 157	,1	,1	, &R5AD20LDU},	//(DO3215013) Закрыть ворота отстойной зоны
	{ 158	,1	,1	, &R6IS21LDU},	//(DO3215014) Кран-балка в нерабочем положении
	{ 159	,1	,1	, &A8IS12LDU},	//(DO3215015) Приход на механический ВУ ДС2
	{ 160	,1	,1	, &A8IS22LDU},	//(DO3215016) Приход на механический НУ ДС2
	{ 161	,1	,1	, &B8IS22LDU},	//(DO3215017) Приход на механический НУ АЗ2
	{ 162	,1	,1	, &A6IS11LDU},	//(DO3215018) Приход на ВУ БЗ1
	{ 163	,1	,1	, &A2IE02LDU},	//(DO3215019) Исправность ИП РБ1
	{ 164	,1	,1	, &A2IE01LDU},	//(DO3215020) Исправность БУШД РБ1
	{ 165	,1	,1	, &A2IE03LDU},	//(DO3215021) Движение РБ1 вперед (от БУШД)
	{ 166	,1	,1	, &A2IE04LDU},	//(DO3215022) Движение РБ1 назад (от БУШД)
	{ 167	,1	,1	, &A3IE02LDU},	//(DO3215023) Исправность ИП ИС1
	{ 168	,1	,1	, &A3IE01LDU},	//(DO3215024) Исправность БУШД ИС1
	{ 169	,1	,1	, &A3IE03LDU},	//(DO3215025) Движение ИС1 вперед (от БУШД)
	{ 170	,1	,1	, &A3IE04LDU},	//(DO3215026) Движение ИС1 назад (от БУШД)
	{ 171	,1	,1	, &B1IE02LDU},	//(DO3215027) Исправность ИП ББ2
	{ 172	,1	,1	, &B1IE01LDU},	//(DO3215028) Исправность БУШД ББ2
	{ 173	,1	,1	, &B2IE02LDU},	//(DO3215029) Исправность ИП РБ2
	{ 174	,1	,1	, &B2IE01LDU},	//(DO3215030) Исправность БУШД РБ2
	{ 175	,1	,1	, &B2IE03LDU},	//(DO3215031) Движение РБ2 вперед (от БУШД)
	{ 176	,1	,1	, &B2IE04LDU},	//(DO3215032) Движение РБ2 назад (от БУШД)
	{ 177	,1	,1	, &B3IE02LDU},	//(DO3216001) Исправность ИП ИС2
	{ 178	,1	,1	, &B3IE01LDU},	//(DO3216002) Исправность БУШД ИС2
	{ 179	,1	,1	, &B3IE03LDU},	//(DO3216003) Движение ИС2 вперед (от БУШД)
	{ 180	,1	,1	, &B3IE04LDU},	//(DO3216004) Движение ИС2 назад (от БУШД)
	{ 181	,1	,1	, &R6IS61LDU},	//(DO3216005) Исправность 3-х  фазной сети
	{ 182	,1	,1	, &R4VS12LDU},	//(DO3216006) Движение реактора  к «У ОБРАЗЦОВ»
	{ 183	,1	,1	, &R4VS22LDU},	//(DO3216007) Движение реактора к «У ЗАЩИТЫ»
	{ 184	,1	,1	, &A8IE01LDU},	//(DO3216008) Исправность ИП ДС2
	{ 185	,1	,1	, &R1VS12LDU},	//(DO3216009) Движение МДЗ1 в сторону ВУ
	{ 186	,1	,1	, &R1VS22LDU},	//(DO3216010) Движение МДЗ1 в сторону НУ
	{ 187	,1	,1	, &R1IE01LDU},	//(DO3216011) Исправность ИП МДЗ1
	{ 188	,1	,1	, &R2VS12LDU},	//(DO3216012) Движение МДЗ2 в сторону ВУ
	{ 189	,1	,1	, &R2VS22LDU},	//(DO3216013) Движение МДЗ2 в сторону НУ
	{ 190	,1	,1	, &R2IE01LDU},	//(DO3216014) Исправность ИП МДЗ2
	{ 191	,1	,1	, &A5VS12LDU},	//(DO3216015) Движение НЛ1 в сторону ВУ
	{ 192	,1	,1	, &A5VS22LDU},	//(DO3216016) Движение НЛ1 в сторону НУ
	{ 193	,1	,1	, &A5IE02LDU},	//(DO3216017) Исправность ИП НЛ1
	{ 194	,1	,1	, &B5VS12LDU},	//(DO3216018) Движение НЛ2 в сторону ВУ
	{ 195	,1	,1	, &B5VS22LDU},	//(DO3216019) Движение НЛ2 в сторону НУ
	{ 196	,1	,1	, &B5IE01LDU},	//(DO3216020) Исправность ИП НЛ2
	{ 197	,1	,1	, &A6VS12LDU},	//(DO3216021) Движение створок БЗ1  к  «ОТКРЫТА»
	{ 198	,1	,1	, &A6VS22LDU},	//(DO3216022) Движение створок БЗ1  к «ЗАКРЫТА»
	{ 199	,1	,1	, &A6IE01LDU},	//(DO3216023) Исправность ИП БЗ1
	{ 200	,1	,1	, &B6VS12LDU},	//(DO3216024) Движение створок БЗ2  к  «ОТКРЫТА»
	{ 201	,1	,1	, &B6VS22LDU},	//(DO3216025) Движение створок БЗ2  к «ЗАКРЫТА»
	{ 202	,1	,1	, &B6IE01LDU},	//(DO3216026) Исправность ИП БЗ2
	{ 203	,1	,1	, &R0IE02LDU},	//(DO3216027) Исправность ИП 24 В-1
	{ 204	,1	,1	, &R0IE01LDU},	//(DO3216028) Исправность ИП 24 В-2
	{ 205	,1	,1	, &R6IS62LDU},	//(DO3216029) Исправность ВИП ССДИ-39 1канал
	{ 206	,1	,1	, &R6IS63LDU},	//(DO3216030) Исправность ВИП ССДИ-39 2канал
	{ 207	,1	,1	, &R6IS64LDU},	//(DO3216031) Исправность ВИП ССДИ-35 1канал
	{ 208	,1	,1	, &R6IS65LDU},	//(DO3216032) Исправность ВИП ССДИ-35 2канал
	{ 209	,1	,1	, &R0IC00LDU},	//!!!(DO3212001) ENCODER?
	{ 210	,1	,1	, &R0IC01LDU},	//!!!(DO3212002) ENCODER?
	{ 211	,1	,1	, &R0IC02LDU},	//!!!(DO3212003) ENCODER?
	{ 212	,1	,1	, &R0IC03LDU},	//!!!(DO3212004) ENCODER?
	{ 213	,1	,1	, &R0IC04LDU},	//!!!(DO3212005) ENCODER?
	{ 214	,1	,1	, &R0IC05LDU},	//!!!(DO3212006) ENCODER?
	{ 215	,1	,1	, &R0IC06LDU},	//!!!(DO3212007) ENCODER?
	{ 216	,1	,1	, &R0IC07LDU},	//!!!(DO3212008) ENCODER?
	{ 217	,1	,1	, &R0IC08LDU},	//!!!(DO3212009) ENCODER?
	{ 218	,1	,1	, &R0IC09LDU},	//!!!(DO3212010) ENCODER?
	{ 219	,1	,1	, &R0IC10LDU},	//!!!(DO3212011) ENCODER?
	{ 220	,1	,1	, &R0IC11LDU},	//!!!(DO3212012) ENCODER?
	{ 221	,1	,1	, &R0IC12LDU},	//!!!(DO3212013) ENCODER?
	{ 222	,1	,1	, &R0IC13LDU},	//!!!(DO3212014) ENCODER?
	{ 223	,1	,1	, &R0IC14LDU},	//!!!(DO3212015) ENCODER?
	{ 224	,1	,1	, &R0IC15LDU},	//!!!(DO3212016) ENCODER?
	{ 225	,1	,1	, &R0IC16LDU},	//!!!(DO3212017) ENCODER?
	{ 226	,1	,1	, &R0IC17LDU},	//!!!(DO3212018) ENCODER?
	{ 227	,1	,1	, &R0IC18LDU},	//!!!(DO3212019) ENCODER?
	{ 228	,1	,1	, &R0IC19LDU},	//!!!(DO3212020) ENCODER?
	{ 229	,1	,1	, &R0IC20LDU},	//!!!(DO3212021) ENCODER?
	{ 230	,1	,1	, &R0IC21LDU},	//!!!(DO3212022) ENCODER?
	{ 231	,1	,1	, &R0IC22LDU},	//!!!(DO3212023) ENCODER?
	{ 232	,1	,1	, &R0IC23LDU},	//!!!(DO3212024) ENCODER?
	{ 233	,1	,1	, &R0IC24LDU},	//!!!(DO3212025) ENCODER?
	{ 234	,1	,1	, &R0IC25LDU},	//!!!(DO3212026) ENCODER?
	{ 235	,1	,1	, &R0IC26LDU},	//!!!(DO3212027) ENCODER?
	{ 236	,1	,1	, &R0IC27LDU},	//!!!(DO3212028) ENCODER?
	{ 237	,1	,1	, &R0IC28LDU},	//!!!(DO3212029) ENCODER?
	{ 238	,1	,1	, &R0IC29LDU},	//!!!(DO3212030) ENCODER?
	{ 239	,1	,1	, &R0IC30LDU},	//!!!(DO3212031) ENCODER?
	{ 240	,1	,1	, &R0IC31LDU},	//!!!(DO3212032) ENCODER?
	{ 241	,1	,1	, &A1IC01LDU},	//(VDSR34001) BUS1_ББ1
	{ 242	,1	,1	, &B1IC01LDU},	//(VDSR34002) BUS2_ББ2
	{ 243	,1	,1	, &A2IC01LDU},	//(VDSR34003) BUS3_РБ1
	{ 244	,1	,1	, &B2IC01LDU},	//(VDSR34004) BUS4_РБ2
	{ 245	,1	,1	, &A3IC01LDU},	//(VDSR34005) BUS5_ИС1
	{ 246	,1	,1	, &B3IC01LDU},	//(VDSR34006) BUS6_ИС2
	{ 247	,1	,1	, &B8IC01LDU},	//(VDSR34007) BUS7_АЗ2
	{ 248	,1	,1	, &A8IC01LDU},	//(VDSR34008) BUS8_ДС2
	{ 249	,1	,1	, &R0IC41LDU},	//(VDSR34009) LUTCH
	{ 250	,1	,1	, &R0IC42LDU},	//(VDSR34010) Вход запрета
	{ 251	,1	,1	, &R0IC43LDU},	//(VDSR34011) Выход запрета
	{ 252	,1	,1	, &A3AD34LDU},	//(VDSR34012) Клапан ВПИС1  открыть (обесточить)
	{ 253	,1	,1	, &A3AD33LDU},	//(VDSR34013) Клапан «ВЫСТРЕЛ ИС1» открыть (обесточить)
	{ 254	,1	,1	, &A2AD33LDU},	//(VDSR34014) Клапан «Подъем РБ1» открыть
	{ 255	,1	,1	, &A4AD10LDU},	//(VDSR34015) Открыть клапан Подъем НИ1
	{ 256	,1	,1	, &A3AD31LDU},	//(VDSR34016) Клапан «СПУСК ИС1» открыть (обесточить)
	{ 257	,1	,1	, &A7AP31LDU},	//(VDSR34017) Клапан «Обдув АЗ1» открыть (обесточить)
	{ 258	,1	,1	, &R1AD10LDU},	//(VDSR34018) Опустить МДЗ1 в зону облучения
	{ 259	,1	,1	, &R1AD20LDU},	//(VDSR34019) Поднять МДЗ1
	{ 260	,1	,1	, &R2AD10LDU},	//(VDSR34020) Опустить МДЗ2 в зону облучения
	{ 261	,1	,1	, &R2AD20LDU},	//(VDSR34021) Поднять МДЗ2
	{ 262	,1	,1	, &A5AD10LDU},	//(VDSR34022) Поднять НЛ1
	{ 263	,1	,1	, &A5AD20LDU},	//(VDSR34023) Опустить НЛ1
	{ 264	,1	,1	, &B5AD10LDU},	//(VDSR34024) Поднять НЛ2
	{ 265	,1	,1	, &B5AD20LDU},	//(VDSR34025) Опустить НЛ2
	{ 266	,1	,1	, &B3AD34LDU},	//(VDSR34026) Клапан ВПИС ИС2  открыть (обесточить)
	{ 267	,1	,1	, &B3AD33LDU},	//(VDSR34027) Клапан «ВЫСТРЕЛ ИС2» закрыть (обесточить)
	{ 268	,1	,1	, &B2AD33LDU},	//(VDSR34028) Клапан «Подъем РБ2» открыть
	{ 269	,1	,1	, &B4AD10LDU},	//(VDSR34029) Открыть клапан Подъем НИ2
	{ 270	,1	,1	, &B3AD31LDU},	//(VDSR34030) Клапан «СПУСК ИС2» открыть (обесточить)
	{ 271	,1	,1	, &B7AP31LDU},	//(VDSR34031) Клапан «Обдув АЗ2» открыть (обесточить)
	{ 272	,1	,1	, &A8AD10LDU},	//(VDSR34032) Перемещение ДС2 вперед
	{ 273	,1	,1	, &A8AD20LDU},	//(A8AD20LDU) Перемещение ДС2 назад
	{ 274	,1	,1	, &A6AD10LDU},	//(A6AD10LDU) Открыть БЗ1
	{ 275	,1	,1	, &A6AD20LDU},	//(A6AD20LDU) Закрыть БЗ1
	{ 276	,1	,1	, &B6AD10LDU},	//(B6AD10LDU) Открыть БЗ2
	{ 277	,1	,1	, &B6AD20LDU},	//(B6AD20LDU) Закрыть БЗ2
	{ 278	,1	,1	, &R4AD10LDU},	//(R4AD10LDU) Перемещение тележки вперед
	{ 279	,1	,1	, &R4AD20LDU},	//(R4AD20LDU) Перемещение тележки назад
	{ 280	,1	,1	, &B8AD10LDU},	//(B8AD10LDU) Перемещение АЗ2 вперед
	{ 281	,1	,1	, &B8AD20LDU},	//(B8AD20LDU) Перемещение АЗ2 назад
	{ 282	,1	,1	, &A3AD11LDU},	//(A3AD11LDU) Сигнал на перемещение ИС1 вверх
	{ 283	,1	,1	, &A3AD21LDU},	//(A3AD21LDU) Сигнал на перемещение ИС1 вниз
	{ 284	,1	,1	, &A3AD01LDU},	//(A3AD01LDU) Разрешение движения ИС1
	{ 285	,1	,1	, &A3AD02LDU},	//(A3AD02LDU) 0-й бит скорости ИС1
	{ 286	,1	,1	, &A3AD03LDU},	//(A3AD03LDU) 1-й бит скорости ИС1
	{ 287	,1	,1	, &A3AD04LDU},	//(A3AD04LDU) 2-й бит скорости ИС1
	{ 288	,1	,1	, &A3AD05LDU},	//(A3AD05LDU) паритет команды на ИС1
	{ 289	,1	,1	, &B3AD11LDU},	//(B3AD11LDU) Сигнал на перемещение ИС2 вверх
	{ 290	,1	,1	, &B3AD21LDU},	//(B3AD21LDU) Сигнал на перемещение ИС2 вниз
	{ 291	,1	,1	, &B3AD01LDU},	//(B3AD01LDU) Разрешение движения ИС2
	{ 292	,1	,1	, &B3AD02LDU},	//(B3AD02LDU) 0-й бит скорости ИС2
	{ 293	,1	,1	, &B3AD03LDU},	//(B3AD03LDU) 1-й бит скорости ИС2
	{ 294	,1	,1	, &B3AD04LDU},	//(B3AD04LDU) 2-й бит скорости ИС2
	{ 295	,1	,1	, &B3AD05LDU},	//(B3AD05LDU) паритет команды на ИС2
	{ 296	,1	,1	, &A9AD10LDU},	//(A9AD10LDU) Открыть клапан Подъем НИ ДС1
	{ 297	,1	,1	, &B9AD10LDU},	//(B9AD10LDU) Открыть клапан Подъем НИ ДС2
	{ 298	,1	,1	, &A1AD11LDU},	//(A1AD11LDU) Сигнал на перемещение ББ1 вверх
	{ 299	,1	,1	, &A1AD21LDU},	//(A1AD21LDU) Сигнал на перемещение ББ1 вниз
	{ 300	,1	,1	, &A1AD01LDU},	//(A1AD01LDU) Разрешение движения ББ1
	{ 301	,1	,1	, &A1AD02LDU},	//(A1AD02LDU) 0-й бит скорости ББ1
	{ 302	,1	,1	, &A1AD03LDU},	//(A1AD03LDU) 1-й бит скорости ББ1
	{ 303	,1	,1	, &A1AD04LDU},	//(A1AD04LDU) 2-й бит скорости ББ1
	{ 304	,1	,1	, &VDSR36032},	//!!!(DO3211032) не занята
	{ 305	,1	,1	, &A1AD05LDU},	//(VDSR31001) паритет команды на ББ1
	{ 306	,1	,1	, &B1AD11LDU},	//(VDSR31002) Сигнал на перемещение ББ2 вверх
	{ 307	,1	,1	, &B1AD21LDU},	//(VDSR31003) Сигнал на перемещение ББ2 вниз
	{ 308	,1	,1	, &B1AD01LDU},	//(VDSR31004) Разрешение движения ББ2
	{ 309	,1	,1	, &B1AD02LDU},	//(VDSR31005) 0-й бит скорости ББ2
	{ 310	,1	,1	, &B1AD03LDU},	//(VDSR31006) 1-й бит скорости ББ2
	{ 311	,1	,1	, &B1AD04LDU},	//(VDSR31007) 2-й бит скорости ББ2
	{ 312	,1	,1	, &B1AD05LDU},	//(VDSR31008) паритет команды на ББ2
	{ 313	,1	,1	, &A2AD11LDU},	//(VDSR31009) Сигнал на перемещение РБ1 вверх
	{ 314	,1	,1	, &A2AD21LDU},	//(VDSR31010) Сигнал на перемещение РБ1 вниз
	{ 315	,1	,1	, &A2AD01LDU},	//(VDSR31011) Разрешение движения РБ1
	{ 316	,1	,1	, &A2AD02LDU},	//(VDSR31012) 0-й бит скорости РБ1
	{ 317	,1	,1	, &A2AD03LDU},	//(VDSR31013) 1-й бит скорости РБ1
	{ 318	,1	,1	, &A2AD04LDU},	//(VDSR31014) 2-й бит скорости РБ1
	{ 319	,1	,1	, &A2AD05LDU},	//(VDSR31015) паритет команды на РБ1
	{ 320	,1	,1	, &B2AD11LDU},	//(VDSR31016) Сигнал на перемещение РБ2 вверх
	{ 321	,1	,1	, &B2AD21LDU},	//(VDSR31017) Сигнал на перемещение РБ2 вниз
	{ 322	,1	,1	, &B2AD01LDU},	//(VDSR31018) Разрешение движения РБ2
	{ 323	,1	,1	, &B2AD02LDU},	//(VDSR31019) 0-й бит скорости РБ2
	{ 324	,1	,1	, &B2AD03LDU},	//(VDSR31020) 1-й бит скорости РБ2
	{ 325	,1	,1	, &B2AD04LDU},	//(VDSR31021) 2-й бит скорости РБ2
	{ 326	,1	,1	, &B2AD05LDU},	//(VDSR31022) паритет команды на РБ2
	{ 327	,1	,1	, &A1AD32LDU},	//(VDSR31023) Обесточить ЭМ ББ1
	{ 328	,1	,1	, &A1AD31LDU},	//(VDSR31024) Клапан «Сброс ББ1» открыть (обесточить)
	{ 329	,1	,1	, &A2AD32LDU},	//(VDSR31025) Обесточить ЭМ РБ1
	{ 330	,1	,1	, &A2AD31LDU},	//(VDSR31026) Клапан «Сброс РБ1» открыть (обесточить)
	{ 331	,1	,1	, &B1AD32LDU},	//(VDSR31027) Обесточить ЭМ ББ2
	{ 332	,1	,1	, &B1AD31LDU},	//(VDSR31028) Клапан «Сброс ББ2» открыть (обесточить)
	{ 333	,1	,1	, &B2AD32LDU},	//(VDSR31029) Обесточить ЭМ РБ2
	{ 334	,1	,1	, &B2AD31LDU},	//(VDSR31030) Клапан «Сброс РБ2» открыть (обесточить)
	{ 335	,1	,1	, &R8AD21LDU},	//(VDSR31031) Запуск системы инициирования
	{ 336	,1	,1	, &R0AD16LDU},	//(VDSR31032) Контроль  I-II УР. РАД
	{-1,0,NULL},
};
static char NameSaveFile[]="savecnst.bin\0";   // Имя файла для сохранения констант
#pragma pop
static short saveVariables[]={      // Id переменных для сохранения
-1,};
#pragma pack(push,1)
static ModbusRegister coil_msptiSig[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_msptiSig[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_msptiSig[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_msptiSig[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_msptiSig[0],&di_msptiSig[0],&ir_msptiSig[0],&hr_msptiSig[0],NULL,NULL,NULL,0},	 //Пустые сигналы PTI

	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},};
#pragma pop
#include "drivers/ao16.h"
static char buf_AO1601[127];	//AO16
static ao16_inimod ini_AO1601={0xffff,120,0x43,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_AO1601={0,0,&ini_AO1601,buf_AO1601,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_AO1601[]={
	{&A0IT01IZ1,3,0},
	{&A2IP01IZ1,3,6},
	{&B0IT01IZ1,3,3},
	{&B2IP01IZ1,3,9},
	{&A0IT02IZ2,3,12},
	{&A2IP01IZ2,3,18},
	{&B0IT02IZ2,3,15},
	{&B2IP01IZ2,3,21},
	{&A3IP02IDU,3,24},
	{&B3IP02IDU,3,27},
	{&AO1632011,3,30},
	{&AO1632012,3,33},
	{&AO1632013,3,36},
	{&AO1632014,3,38},
	{&AO1632015,3,41},
	{&AO1632016,3,44},
	{NULL,0,0},
};
#pragma pop
#include "drivers/do32_pti.h"
static char buf_DO32_5F01[137];	//do32_5f(0x100)
static do32_pti_inipar ini_DO32_5F01={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F01={0,0,&ini_DO32_5F01,buf_DO32_5F01,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F01[]={
	{&R0VN71LZ1,1,0},
	{&R0VN75LZ1,1,2},
	{&A0EE01LS1,1,4},
	{&A0VN71LS1,1,6},
	{&A3IS11LZ1,1,8},
	{&A3IS22LZ1,1,10},
	{&R0VN72LZ1,1,12},
	{&R0VN76LZ1,1,14},
	{&A0EE01LS2,1,16},
	{&A0VN71LS2,1,18},
	{&B3IS11LZ1,1,20},
	{&B3IS22LZ1,1,22},
	{&R0VN74LZ1,1,24},
	{&R0VN78LZ1,1,26},
	{&A0EE01LS4,1,28},
	{&A0VN71LS4,1,30},
	{&R6IS66LZ1,1,32},
	{&R6IS67LZ1,1,34},
	{&R6IS68LZ1,1,36},
	{&R0VN73LZ1,1,38},
	{&R0VN77LZ1,1,40},
	{&A0EE01LS3,1,42},
	{&A0VN71LS3,1,44},
	{&R7II71LZ1,1,46},
	{&R7II72LZ1,1,48},
	{&R7II73LZ1,1,50},
	{&A0VP81LZ1,1,52},
	{&A1VP81LZ1,1,54},
	{&R0VP81LZ1,1,56},
	{&B0VP81LZ1,1,58},
	{&B1VP81LZ1,1,60},
	{&R0VP82LZ1,1,62},
	{NULL,0,0},
};
#pragma pop
#include "drivers/do32_pti.h"
static char buf_DO32_5F02[137];	//do32_5f(0x110)
static do32_pti_inipar ini_DO32_5F02={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F02={0,0,&ini_DO32_5F02,buf_DO32_5F02,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F02[]={
	{&R0VN71LZ2,1,0},
	{&R0VN75LZ2,1,2},
	{&A1EE01LS1,1,4},
	{&A1VN71LS1,1,6},
	{&A3IS11LZ2,1,8},
	{&A3IS22LZ2,1,10},
	{&R0VN72LZ2,1,12},
	{&R0VN76LZ2,1,14},
	{&A1EE01LS2,1,16},
	{&A1VN71LS2,1,18},
	{&B3IS11LZ2,1,20},
	{&B3IS22LZ2,1,22},
	{&R0VN74LZ2,1,24},
	{&R0VN78LZ2,1,26},
	{&A1EE01LS4,1,28},
	{&A1VN71LS4,1,30},
	{&R6IS66LZ2,1,32},
	{&R6IS67LZ2,1,34},
	{&R6IS68LZ2,1,36},
	{&R0VN73LZ2,1,38},
	{&R0VN77LZ2,1,40},
	{&A1EE01LS3,1,42},
	{&A1VN71LS3,1,44},
	{&R7II71LZ2,1,46},
	{&R7II72LZ2,1,48},
	{&R7II73LZ2,1,50},
	{&A0VP81LZ2,1,52},
	{&A1VP81LZ2,1,54},
	{&R0VP81LZ2,1,56},
	{&B0VP81LZ2,1,58},
	{&B1VP81LZ2,1,60},
	{&R0VP82LZ2,1,62},
	{NULL,0,0},
};
#pragma pop
#include "drivers/do32_pti.h"
static char buf_DO32_5F08[137];	//do32_5f(0x130)
static do32_pti_inipar ini_DO32_5F08={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F08={0,0,&ini_DO32_5F08,buf_DO32_5F08,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F08[]={
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
	{&DO3213015,1,28},
	{&A4IS11LDU,1,30},
	{&A4IS21LDU,1,32},
	{&A9IS11LDU,1,34},
	{&A9IS21LDU,1,36},
	{&B9IS11LDU,1,38},
	{&B9IS21LDU,1,40},
	{&R1IS11LDU,1,42},
	{&R1IS21LDU,1,44},
	{&R2IS11LDU,1,46},
	{&R2IS21LDU,1,48},
	{&A3IS35LDU,1,50},
	{&A3IS33LDU,1,52},
	{&A2IS33LDU,1,54},
	{&A4IS10LDU,1,56},
	{&A3IS31LDU,1,58},
	{&A7AS31LDU,1,60},
	{&A1IS12LDU,1,62},
	{NULL,0,0},
};
#pragma pop
#include "drivers/do32_pti.h"
static char buf_DO32_5F09[137];	//do32_5f(0x140)
static do32_pti_inipar ini_DO32_5F09={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F09={0,0,&ini_DO32_5F09,buf_DO32_5F09,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F09[]={
	{&A1IS11LDU,1,0},
	{&A1IS21LDU,1,2},
	{&A2IS12LDU,1,4},
	{&A2IS11LDU,1,6},
	{&A2IS21LDU,1,8},
	{&A3IS21LDU,1,10},
	{&B4IS11LDU,1,12},
	{&B4IS21LDU,1,14},
	{&B8IS12LDU,1,16},
	{&DO3214010,1,18},
	{&A3VP81LDU,1,20},
	{&A2VP82LDU,1,22},
	{&A4VP82LDU,1,24},
	{&B3VP81LDU,1,26},
	{&B2VP82LDU,1,28},
	{&B4VP82LDU,1,30},
	{&R0IS02LDU,1,32},
	{&A3IS11LDU,1,34},
	{&A3IS22LDU,1,36},
	{&B3IS11LDU,1,38},
	{&B3IS22LDU,1,40},
	{&R4IS11LDU,1,42},
	{&R4IS12LDU,1,44},
	{&R4IS21LDU,1,46},
	{&R4IS22LDU,1,48},
	{&DO3214026,1,50},
	{&A6IS21LDU,1,52},
	{&A5IS11LDU,1,54},
	{&A5IS21LDU,1,56},
	{&B6IS11LDU,1,58},
	{&B6IS21LDU,1,60},
	{&B5IS11LDU,1,62},
	{NULL,0,0},
};
#pragma pop
#include "drivers/do32_pti.h"
static char buf_DO32_5F05[137];	//do32_5f(0x150)
static do32_pti_inipar ini_DO32_5F05={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F05={0,0,&ini_DO32_5F05,buf_DO32_5F05,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F05[]={
	{&B5IS21LDU,1,0},
	{&R3IS11LDU,1,2},
	{&R3IS21LDU,1,4},
	{&R3IS31LDU,1,6},
	{&R3IS41LDU,1,8},
	{&R3AD10LDU,1,10},
	{&R3AD11LDU,1,12},
	{&R3AD20LDU,1,14},
	{&R3AD21LDU,1,16},
	{&R5IS11LDU,1,18},
	{&R5IS21LDU,1,20},
	{&R5AD10LDU,1,22},
	{&R5AD20LDU,1,24},
	{&R6IS21LDU,1,26},
	{&A8IS12LDU,1,28},
	{&A8IS22LDU,1,30},
	{&B8IS22LDU,1,32},
	{&A6IS11LDU,1,34},
	{&A2IE02LDU,1,36},
	{&A2IE01LDU,1,38},
	{&A2IE03LDU,1,40},
	{&A2IE04LDU,1,42},
	{&A3IE02LDU,1,44},
	{&A3IE01LDU,1,46},
	{&A3IE03LDU,1,48},
	{&A3IE04LDU,1,50},
	{&B1IE02LDU,1,52},
	{&B1IE01LDU,1,54},
	{&B2IE02LDU,1,56},
	{&B2IE01LDU,1,58},
	{&B2IE03LDU,1,60},
	{&B2IE04LDU,1,62},
	{NULL,0,0},
};
#pragma pop
#include "drivers/do32_pti.h"
static char buf_DO32_5F06[137];	//do32_5f(0x160)
static do32_pti_inipar ini_DO32_5F06={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F06={0,0,&ini_DO32_5F06,buf_DO32_5F06,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F06[]={
	{&B3IE02LDU,1,0},
	{&B3IE01LDU,1,2},
	{&B3IE03LDU,1,4},
	{&B3IE04LDU,1,6},
	{&R6IS61LDU,1,8},
	{&R4VS12LDU,1,10},
	{&R4VS22LDU,1,12},
	{&A8IE01LDU,1,14},
	{&R1VS12LDU,1,16},
	{&R1VS22LDU,1,18},
	{&R1IE01LDU,1,20},
	{&R2VS12LDU,1,22},
	{&R2VS22LDU,1,24},
	{&R2IE01LDU,1,26},
	{&A5VS12LDU,1,28},
	{&A5VS22LDU,1,30},
	{&A5IE02LDU,1,32},
	{&B5VS12LDU,1,34},
	{&B5VS22LDU,1,36},
	{&B5IE01LDU,1,38},
	{&A6VS12LDU,1,40},
	{&A6VS22LDU,1,42},
	{&A6IE01LDU,1,44},
	{&B6VS12LDU,1,46},
	{&B6VS22LDU,1,48},
	{&B6IE01LDU,1,50},
	{&R0IE02LDU,1,52},
	{&R0IE01LDU,1,54},
	{&R6IS62LDU,1,56},
	{&R6IS63LDU,1,58},
	{&R6IS64LDU,1,60},
	{&R6IS65LDU,1,62},
	{NULL,0,0},
};
#pragma pop
#include "drivers/do32_pti.h"
static char buf_DO32_5F04[137];	//do32_5f(0x120)
static do32_pti_inipar ini_DO32_5F04={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F04={0,0,&ini_DO32_5F04,buf_DO32_5F04,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F04[]={
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
#include "drivers/vds32_pti.h"
static char buf_VDS32F07[66];	//vds32f2(0x340)
static vds32pti_inimod ini_VDS32F07={0,};
#pragma pack(push,1)
static table_drv table_VDS32F07={0,0,&ini_VDS32F07,buf_VDS32F07,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32F07[]={
	{&A1IC01LDU,1,0},
	{&B1IC01LDU,1,2},
	{&A2IC01LDU,1,4},
	{&B2IC01LDU,1,6},
	{&A3IC01LDU,1,8},
	{&B3IC01LDU,1,10},
	{&B8IC01LDU,1,12},
	{&A8IC01LDU,1,14},
	{&R0IC41LDU,1,16},
	{&R0IC42LDU,1,18},
	{&R0IC43LDU,1,20},
	{&A3AD34LDU,1,22},
	{&A3AD33LDU,1,24},
	{&A2AD33LDU,1,26},
	{&A4AD10LDU,1,28},
	{&A3AD31LDU,1,30},
	{&A7AP31LDU,1,32},
	{&R1AD10LDU,1,34},
	{&R1AD20LDU,1,36},
	{&R2AD10LDU,1,38},
	{&R2AD20LDU,1,40},
	{&A5AD10LDU,1,42},
	{&A5AD20LDU,1,44},
	{&B5AD10LDU,1,46},
	{&B5AD20LDU,1,48},
	{&B3AD34LDU,1,50},
	{&B3AD33LDU,1,52},
	{&B2AD33LDU,1,54},
	{&B4AD10LDU,1,56},
	{&B3AD31LDU,1,58},
	{&B7AP31LDU,1,60},
	{&A8AD10LDU,1,62},
	{NULL,0,0},
};
#pragma pop
#include "drivers/vds32_pti.h"
static char buf_VDS32F10[66];	//vds32f2(0x360)
static vds32pti_inimod ini_VDS32F10={0,};
#pragma pack(push,1)
static table_drv table_VDS32F10={0,0,&ini_VDS32F10,buf_VDS32F10,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32F10[]={
	{&A8AD20LDU,1,0},
	{&A6AD10LDU,1,2},
	{&A6AD20LDU,1,4},
	{&B6AD10LDU,1,6},
	{&B6AD20LDU,1,8},
	{&R4AD10LDU,1,10},
	{&R4AD20LDU,1,12},
	{&B8AD10LDU,1,14},
	{&B8AD20LDU,1,16},
	{&A3AD11LDU,1,18},
	{&A3AD21LDU,1,20},
	{&A3AD01LDU,1,22},
	{&A3AD02LDU,1,24},
	{&A3AD03LDU,1,26},
	{&A3AD04LDU,1,28},
	{&A3AD05LDU,1,30},
	{&B3AD11LDU,1,32},
	{&B3AD21LDU,1,34},
	{&B3AD01LDU,1,36},
	{&B3AD02LDU,1,38},
	{&B3AD03LDU,1,40},
	{&B3AD04LDU,1,42},
	{&B3AD05LDU,1,44},
	{&A9AD10LDU,1,46},
	{&B9AD10LDU,1,48},
	{&A1AD11LDU,1,50},
	{&A1AD21LDU,1,52},
	{&A1AD01LDU,1,54},
	{&A1AD02LDU,1,56},
	{&A1AD03LDU,1,58},
	{&A1AD04LDU,1,60},
	{&VDSR36032,1,62},
	{NULL,0,0},
};
#pragma pop
#include "drivers/vds32_pti.h"
static char buf_VDS32F11[66];	//vds32f2(0x310)
static vds32pti_inimod ini_VDS32F11={0,};
#pragma pack(push,1)
static table_drv table_VDS32F11={0,0,&ini_VDS32F11,buf_VDS32F11,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32F11[]={
	{&A1AD05LDU,1,0},
	{&B1AD11LDU,1,2},
	{&B1AD21LDU,1,4},
	{&B1AD01LDU,1,6},
	{&B1AD02LDU,1,8},
	{&B1AD03LDU,1,10},
	{&B1AD04LDU,1,12},
	{&B1AD05LDU,1,14},
	{&A2AD11LDU,1,16},
	{&A2AD21LDU,1,18},
	{&A2AD01LDU,1,20},
	{&A2AD02LDU,1,22},
	{&A2AD03LDU,1,24},
	{&A2AD04LDU,1,26},
	{&A2AD05LDU,1,28},
	{&B2AD11LDU,1,30},
	{&B2AD21LDU,1,32},
	{&B2AD01LDU,1,34},
	{&B2AD02LDU,1,36},
	{&B2AD03LDU,1,38},
	{&B2AD04LDU,1,40},
	{&B2AD05LDU,1,42},
	{&A1AD32LDU,1,44},
	{&A1AD31LDU,1,46},
	{&A2AD32LDU,1,48},
	{&A2AD31LDU,1,50},
	{&B1AD32LDU,1,52},
	{&B1AD31LDU,1,54},
	{&B2AD32LDU,1,56},
	{&B2AD31LDU,1,58},
	{&R8AD21LDU,1,60},
	{&R0AD16LDU,1,62},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0x04,0x320,20,127,def_buf_AO1601,&table_AO1601}, //AO16
	{0x02,0x100,1,137,def_buf_DO32_5F01,&table_DO32_5F01}, //do32_5f(0x100)
	{0x02,0x110,1,137,def_buf_DO32_5F02,&table_DO32_5F02}, //do32_5f(0x110)
	{0x02,0x130,1,137,def_buf_DO32_5F08,&table_DO32_5F08}, //do32_5f(0x130)
	{0x02,0x140,1,137,def_buf_DO32_5F09,&table_DO32_5F09}, //do32_5f(0x140)
	{0x02,0x150,1,137,def_buf_DO32_5F05,&table_DO32_5F05}, //do32_5f(0x150)
	{0x02,0x160,1,137,def_buf_DO32_5F06,&table_DO32_5F06}, //do32_5f(0x160)
	{0x02,0x120,1,137,def_buf_DO32_5F04,&table_DO32_5F04}, //do32_5f(0x120)
	{0x03,0x340,1,66,def_buf_VDS32F07,&table_VDS32F07}, //vds32f2(0x340)
	{0x03,0x360,1,66,def_buf_VDS32F10,&table_VDS32F10}, //vds32f2(0x360)
	{0x03,0x310,1,66,def_buf_VDS32F11,&table_VDS32F11}, //vds32f2(0x310)
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
}
void Scheme(void)
{
}
#endif
