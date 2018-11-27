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
#define AO1632001	 BUFFER[0]	//(A0IT01IZ1) Температура АЗ1-1
#define idAO1632001	 1	//(A0IT01IZ1) Температура АЗ1-1
#define AO1632002	 BUFFER[3]	//(A2IP01IZ1) Текущее давление СБРОС РБ1
#define idAO1632002	 2	//(A2IP01IZ1) Текущее давление СБРОС РБ1
#define AO1632003	 BUFFER[6]	//(B0IT01IZ1) Температура АЗ2-1
#define idAO1632003	 3	//(B0IT01IZ1) Температура АЗ2-1
#define AO1632004	 BUFFER[9]	//(B2IP01IZ1) Текущее давление СБРОС РБ2
#define idAO1632004	 4	//(B2IP01IZ1) Текущее давление СБРОС РБ2
#define AO1632005	 BUFFER[12]	//(A0IT02IZ2) Температура АЗ1-2
#define idAO1632005	 5	//(A0IT02IZ2) Температура АЗ1-2
#define AO1632006	 BUFFER[15]	//(A2IP01IZ2) Текущее давление СБРОС РБ1
#define idAO1632006	 6	//(A2IP01IZ2) Текущее давление СБРОС РБ1
#define AO1632007	 BUFFER[18]	//(B0IT02IZ2) Температура АЗ2-2
#define idAO1632007	 7	//(B0IT02IZ2) Температура АЗ2-2
#define AO1632008	 BUFFER[21]	//(B2IP01IZ2) Текущее давление СБРОС РБ2
#define idAO1632008	 8	//(B2IP01IZ2) Текущее давление СБРОС РБ2
#define AO1632009	 BUFFER[24]	//(A3IP02IDU) Текущее давление ВЫСТРЕЛ ИС1
#define idAO1632009	 9	//(A3IP02IDU) Текущее давление ВЫСТРЕЛ ИС1
#define AO1632010	 BUFFER[27]	//(B3IP02IDU) Текущее давление ВЫСТРЕЛ ИС2
#define idAO1632010	 10	//(B3IP02IDU) Текущее давление ВЫСТРЕЛ ИС2
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
#define DO3210001	 BUFFER[48]	//(R0VN71LZ1) АС по мощности канал 1
#define idDO3210001	 17	//(R0VN71LZ1) АС по мощности канал 1
#define DO3210002	 BUFFER[50]	//(R0VN75LZ1) АС по периоду разгона канал  1
#define idDO3210002	 18	//(R0VN75LZ1) АС по периоду разгона канал  1
#define DO3210003	 BUFFER[52]	//(A0EE01LS1) Исправность АКНП канал 1 
#define idDO3210003	 19	//(A0EE01LS1) Исправность АКНП канал 1 
#define DO3210004	 BUFFER[54]	//(A0VN71LS1) Блокировка автоматического подъёма ББ канал 1
#define idDO3210004	 20	//(A0VN71LS1) Блокировка автоматического подъёма ББ канал 1
#define DO3210005	 BUFFER[56]	//(A3IS11LZ1) Приход на ВУ ИС1
#define idDO3210005	 21	//(A3IS11LZ1) Приход на ВУ ИС1
#define DO3210006	 BUFFER[58]	//(A3IS22LZ1) Приход на НУП ИС1
#define idDO3210006	 22	//(A3IS22LZ1) Приход на НУП ИС1
#define DO3210007	 BUFFER[60]	//(R0VN72LZ1) АС по мощности канал 2
#define idDO3210007	 23	//(R0VN72LZ1) АС по мощности канал 2
#define DO3210008	 BUFFER[62]	//(R0VN76LZ1) АС по периоду разгона канал  2
#define idDO3210008	 24	//(R0VN76LZ1) АС по периоду разгона канал  2
#define DO3210009	 BUFFER[64]	//(A0EE01LS2) Исправность АКНП  канал 2
#define idDO3210009	 25	//(A0EE01LS2) Исправность АКНП  канал 2
#define DO3210010	 BUFFER[66]	//(A0VN71LS2) Блокировка автоматического подъёма ББ канал 2
#define idDO3210010	 26	//(A0VN71LS2) Блокировка автоматического подъёма ББ канал 2
#define DO3210011	 BUFFER[68]	//(B3IS11LZ1) Приход на ВУ ИС2
#define idDO3210011	 27	//(B3IS11LZ1) Приход на ВУ ИС2
#define DO3210012	 BUFFER[70]	//(B3IS22LZ1) Приход на НУП ИС2
#define idDO3210012	 28	//(B3IS22LZ1) Приход на НУП ИС2
#define DO3210013	 BUFFER[72]	//(R0VN74LZ1) АС по мощности канал 4
#define idDO3210013	 29	//(R0VN74LZ1) АС по мощности канал 4
#define DO3210014	 BUFFER[74]	//(R0VN78LZ1) АС по периоду разгона канал  4
#define idDO3210014	 30	//(R0VN78LZ1) АС по периоду разгона канал  4
#define DO3210015	 BUFFER[76]	//(A0EE01LS4) Исправность АКНП канал 4
#define idDO3210015	 31	//(A0EE01LS4) Исправность АКНП канал 4
#define DO3210016	 BUFFER[78]	//(A0VN71LS4) Блокировка автоматического подъёма ББ канал 4
#define idDO3210016	 32	//(A0VN71LS4) Блокировка автоматического подъёма ББ канал 4
#define DO3210017	 BUFFER[80]	//(R6IS66LZ1) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idDO3210017	 33	//(R6IS66LZ1) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define DO3210018	 BUFFER[82]	//(R6IS67LZ1) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idDO3210018	 34	//(R6IS67LZ1) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define DO3210019	 BUFFER[84]	//(R6IS68LZ1) Исправность ВИП 4,0 (№7) ССДИ-2
#define idDO3210019	 35	//(R6IS68LZ1) Исправность ВИП 4,0 (№7) ССДИ-2
#define DO3210020	 BUFFER[86]	//(R0VN73LZ1) АС по мощности канал 3
#define idDO3210020	 36	//(R0VN73LZ1) АС по мощности канал 3
#define DO3210021	 BUFFER[88]	//(R0VN77LZ1) АС по периоду разгона канал  3
#define idDO3210021	 37	//(R0VN77LZ1) АС по периоду разгона канал  3
#define DO3210022	 BUFFER[90]	//(A0EE01LS3) Исправность АКНП канал 3
#define idDO3210022	 38	//(A0EE01LS3) Исправность АКНП канал 3
#define DO3210023	 BUFFER[92]	//(A0VN71LS3) Блокировка автоматического подъёма ББ канал 3
#define idDO3210023	 39	//(A0VN71LS3) Блокировка автоматического подъёма ББ канал 3
#define DO3210024	 BUFFER[94]	//(R7II71LZ1) Сработала АС IУР РАД (датчик 1)
#define idDO3210024	 40	//(R7II71LZ1) Сработала АС IУР РАД (датчик 1)
#define DO3210025	 BUFFER[96]	//(R7II72LZ1) Сработала АС IУР РАД  (датчик 2)
#define idDO3210025	 41	//(R7II72LZ1) Сработала АС IУР РАД  (датчик 2)
#define DO3210026	 BUFFER[98]	//(R7II73LZ1) Сработала АС II УР РАД
#define idDO3210026	 42	//(R7II73LZ1) Сработала АС II УР РАД
#define DO3210027	 BUFFER[100]	//(A0VP81LZ1) Давление  АЗ1 в норме
#define idDO3210027	 43	//(A0VP81LZ1) Давление  АЗ1 в норме
#define DO3210028	 BUFFER[102]	//(A1VP81LZ1) Давление СБРОС ББ1 в норме
#define idDO3210028	 44	//(A1VP81LZ1) Давление СБРОС ББ1 в норме
#define DO3210029	 BUFFER[104]	//(R0VP81LZ1) Давление  в СИСТЕМЕ -1 в норме
#define idDO3210029	 45	//(R0VP81LZ1) Давление  в СИСТЕМЕ -1 в норме
#define DO3210030	 BUFFER[106]	//(B0VP81LZ1) Давление АЗ2 в норме
#define idDO3210030	 46	//(B0VP81LZ1) Давление АЗ2 в норме
#define DO3210031	 BUFFER[108]	//(B1VP81LZ1) Давление СБРОС ББ2 в норме
#define idDO3210031	 47	//(B1VP81LZ1) Давление СБРОС ББ2 в норме
#define DO3210032	 BUFFER[110]	//(R0VP82LZ1) Давление  в СИСТЕМЕ - 2 в норме
#define idDO3210032	 48	//(R0VP82LZ1) Давление  в СИСТЕМЕ - 2 в норме
#define DO3211001	 BUFFER[112]	//(R0VN71LZ2) АС по мощности канал 1
#define idDO3211001	 49	//(R0VN71LZ2) АС по мощности канал 1
#define DO3211002	 BUFFER[114]	//(R0VN75LZ2) АС по периоду разгона канал  1
#define idDO3211002	 50	//(R0VN75LZ2) АС по периоду разгона канал  1
#define DO3211003	 BUFFER[116]	//(A1EE01LS1) Исправность АКНП канал 1
#define idDO3211003	 51	//(A1EE01LS1) Исправность АКНП канал 1
#define DO3211004	 BUFFER[118]	//(A1VN71LS1) Блокировка автоматического подъёма ББ канал 1
#define idDO3211004	 52	//(A1VN71LS1) Блокировка автоматического подъёма ББ канал 1
#define DO3211005	 BUFFER[120]	//(A3IS11LZ2) Приход на ВУ ИС1
#define idDO3211005	 53	//(A3IS11LZ2) Приход на ВУ ИС1
#define DO3211006	 BUFFER[122]	//(A3IS22LZ2) Приход на НУП ИС1
#define idDO3211006	 54	//(A3IS22LZ2) Приход на НУП ИС1
#define DO3211007	 BUFFER[124]	//(R0VN72LZ2) АС по мощности канал 2
#define idDO3211007	 55	//(R0VN72LZ2) АС по мощности канал 2
#define DO3211008	 BUFFER[126]	//(R0VN76LZ2) АС по периоду разгона канал  2
#define idDO3211008	 56	//(R0VN76LZ2) АС по периоду разгона канал  2
#define DO3211009	 BUFFER[128]	//(A1EE01LS2) Исправность АКНП  канал 2
#define idDO3211009	 57	//(A1EE01LS2) Исправность АКНП  канал 2
#define DO3211010	 BUFFER[130]	//(A1VN71LS2) Блокировка автоматического подъёма ББ канал 2
#define idDO3211010	 58	//(A1VN71LS2) Блокировка автоматического подъёма ББ канал 2
#define DO3211011	 BUFFER[132]	//(B3IS11LZ2) Приход на ВУ ИС2
#define idDO3211011	 59	//(B3IS11LZ2) Приход на ВУ ИС2
#define DO3211012	 BUFFER[134]	//(B3IS22LZ2) Приход на НУП ИС2
#define idDO3211012	 60	//(B3IS22LZ2) Приход на НУП ИС2
#define DO3211013	 BUFFER[136]	//(R0VN74LZ2) АС по мощности канал 4
#define idDO3211013	 61	//(R0VN74LZ2) АС по мощности канал 4
#define DO3211014	 BUFFER[138]	//(R0VN78LZ2) АС по периоду разгона канал  4
#define idDO3211014	 62	//(R0VN78LZ2) АС по периоду разгона канал  4
#define DO3211015	 BUFFER[140]	//(A1EE01LS4) Исправность АКНП канал 4
#define idDO3211015	 63	//(A1EE01LS4) Исправность АКНП канал 4
#define DO3211016	 BUFFER[142]	//(A1VN71LS4) Блокировка автоматического подъёма ББ канал 4
#define idDO3211016	 64	//(A1VN71LS4) Блокировка автоматического подъёма ББ канал 4
#define DO3211017	 BUFFER[144]	//(R6IS66LZ2) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idDO3211017	 65	//(R6IS66LZ2) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define DO3211018	 BUFFER[146]	//(R6IS67LZ2) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idDO3211018	 66	//(R6IS67LZ2) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define DO3211019	 BUFFER[148]	//(R6IS68LZ2) Исправность ВИП 4,0 (№7) ССДИ-2
#define idDO3211019	 67	//(R6IS68LZ2) Исправность ВИП 4,0 (№7) ССДИ-2
#define DO3211020	 BUFFER[150]	//(R0VN73LZ2) АС по мощности канал 3
#define idDO3211020	 68	//(R0VN73LZ2) АС по мощности канал 3
#define DO3211021	 BUFFER[152]	//(R0VN77LZ2) АС по периоду разгона канал  3
#define idDO3211021	 69	//(R0VN77LZ2) АС по периоду разгона канал  3
#define DO3211022	 BUFFER[154]	//(A1EE01LS3) Исправность АКНП канал 3
#define idDO3211022	 70	//(A1EE01LS3) Исправность АКНП канал 3
#define DO3211023	 BUFFER[156]	//(A1VN71LS3) Блокировка автоматического подъёма ББ канал 3
#define idDO3211023	 71	//(A1VN71LS3) Блокировка автоматического подъёма ББ канал 3
#define DO3211024	 BUFFER[158]	//(R7II71LZ2) Сработала АС IУР (датчик 1)
#define idDO3211024	 72	//(R7II71LZ2) Сработала АС IУР (датчик 1)
#define DO3211025	 BUFFER[160]	//(R7II72LZ2) Сработала АС IУР (датчик 2)
#define idDO3211025	 73	//(R7II72LZ2) Сработала АС IУР (датчик 2)
#define DO3211026	 BUFFER[162]	//(R7II73LZ2) Сработала АС IIУР
#define idDO3211026	 74	//(R7II73LZ2) Сработала АС IIУР
#define DO3211027	 BUFFER[164]	//(A0VP81LZ2) Давление  АЗ1 в норме
#define idDO3211027	 75	//(A0VP81LZ2) Давление  АЗ1 в норме
#define DO3211028	 BUFFER[166]	//(A1VP81LZ2) Давление СБРОС ББ1 в норме
#define idDO3211028	 76	//(A1VP81LZ2) Давление СБРОС ББ1 в норме
#define DO3211029	 BUFFER[168]	//(R0VP81LZ2) Давление  в СИСТЕМЕ -1 в норме
#define idDO3211029	 77	//(R0VP81LZ2) Давление  в СИСТЕМЕ -1 в норме
#define DO3211030	 BUFFER[170]	//(B0VP81LZ2) Давление АЗ2 в норме
#define idDO3211030	 78	//(B0VP81LZ2) Давление АЗ2 в норме
#define DO3211031	 BUFFER[172]	//(B1VP81LZ2) Давление СБРОС ББ2 в норме
#define idDO3211031	 79	//(B1VP81LZ2) Давление СБРОС ББ2 в норме
#define DO3211032	 BUFFER[174]	//(R0VP82LZ2) Давление  в СИСТЕМЕ - 2 в норме
#define idDO3211032	 80	//(R0VP82LZ2) Давление  в СИСТЕМЕ - 2 в норме
#define DO3213001	 BUFFER[176]	//(B3IS35LDU) Клапан «ВПИС2» открыт (обесточен) 
#define idDO3213001	 81	//(B3IS35LDU) Клапан «ВПИС2» открыт (обесточен) 
#define DO3213002	 BUFFER[178]	//(B3IS33LDU) Клапан «ВЫСТРЕЛ ИС2» открыт (обесточен) 
#define idDO3213002	 82	//(B3IS33LDU) Клапан «ВЫСТРЕЛ ИС2» открыт (обесточен) 
#define DO3213003	 BUFFER[180]	//(B2IS33LDU) Клапан «Подъём РБ2» открыт (обесточен) 
#define idDO3213003	 83	//(B2IS33LDU) Клапан «Подъём РБ2» открыт (обесточен) 
#define DO3213004	 BUFFER[182]	//(B4IS10LDU) Клапан «Подъём НИ2» открыт (обесточен) 
#define idDO3213004	 84	//(B4IS10LDU) Клапан «Подъём НИ2» открыт (обесточен) 
#define DO3213005	 BUFFER[184]	//(B3IS31LDU) Клапан «СПУСК ИС2» открыт (обесточен) 
#define idDO3213005	 85	//(B3IS31LDU) Клапан «СПУСК ИС2» открыт (обесточен) 
#define DO3213006	 BUFFER[186]	//(B7AS31LDU) Клапан «Обдув АЗ2» открыт (обесточен) 
#define idDO3213006	 86	//(B7AS31LDU) Клапан «Обдув АЗ2» открыт (обесточен) 
#define DO3213007	 BUFFER[188]	//(B1IS12LDU) Магнит ББ2 зацеплен 
#define idDO3213007	 87	//(B1IS12LDU) Магнит ББ2 зацеплен 
#define DO3213008	 BUFFER[190]	//(B1IS11LDU) Приход на ВУ ББ2 
#define idDO3213008	 88	//(B1IS11LDU) Приход на ВУ ББ2 
#define DO3213009	 BUFFER[192]	//(B1IS21LDU) Приход на НУ ББ2 
#define idDO3213009	 89	//(B1IS21LDU) Приход на НУ ББ2 
#define DO3213010	 BUFFER[194]	//(B2IS12LDU) Магнит РБ2 зацеплен 
#define idDO3213010	 90	//(B2IS12LDU) Магнит РБ2 зацеплен 
#define DO3213011	 BUFFER[196]	//(B2IS11LDU) Приход на ВУ РБ2-СТР 
#define idDO3213011	 91	//(B2IS11LDU) Приход на ВУ РБ2-СТР 
#define DO3213012	 BUFFER[198]	//(B2IS21LDU) Приход на НУ РБ2-СС 
#define idDO3213012	 92	//(B2IS21LDU) Приход на НУ РБ2-СС 
#define DO3213013	 BUFFER[200]	//(B3IS21LDU) Приход на НУ ИС2 
#define idDO3213013	 93	//(B3IS21LDU) Приход на НУ ИС2 
#define DO3213014	 BUFFER[202]	//(R8IS11LDU) Аварийный НИ установлен 
#define idDO3213014	 94	//(R8IS11LDU) Аварийный НИ установлен 
#define DO3213015	 BUFFER[204]	//!!!(DO3213015) Не занятые значения
#define idDO3213015	 95	//!!!(DO3213015) Не занятые значения
#define DO3213016	 BUFFER[206]	//(A4IS11LDU) Приход на ВУ НИ1 
#define idDO3213016	 96	//(A4IS11LDU) Приход на ВУ НИ1 
#define DO3213017	 BUFFER[208]	//(A4IS21LDU) Приход на НУ НИ1 
#define idDO3213017	 97	//(A4IS21LDU) Приход на НУ НИ1 
#define DO3213018	 BUFFER[210]	//(A9IS11LDU) Приход на ВУ НИ ДС1
#define idDO3213018	 98	//(A9IS11LDU) Приход на ВУ НИ ДС1
#define DO3213019	 BUFFER[212]	//(A9IS21LDU) Приход на НУ НИ ДС1
#define idDO3213019	 99	//(A9IS21LDU) Приход на НУ НИ ДС1
#define DO3213020	 BUFFER[214]	//(B9IS11LDU) Приход на ВУ НИ ДС2
#define idDO3213020	 100	//(B9IS11LDU) Приход на ВУ НИ ДС2
#define DO3213021	 BUFFER[216]	//(B9IS21LDU) Приход на НУ НИ ДС2
#define idDO3213021	 101	//(B9IS21LDU) Приход на НУ НИ ДС2
#define DO3213022	 BUFFER[218]	//(R1IS11LDU) Приход на ВУ МДЗ1
#define idDO3213022	 102	//(R1IS11LDU) Приход на ВУ МДЗ1
#define DO3213023	 BUFFER[220]	//(R1IS21LDU) Приход на НУ МДЗ1
#define idDO3213023	 103	//(R1IS21LDU) Приход на НУ МДЗ1
#define DO3213024	 BUFFER[222]	//(R2IS11LDU) Приход на ВУ МДЗ2
#define idDO3213024	 104	//(R2IS11LDU) Приход на ВУ МДЗ2
#define DO3213025	 BUFFER[224]	//(R2IS21LDU) Приход на НУ МДЗ2
#define idDO3213025	 105	//(R2IS21LDU) Приход на НУ МДЗ2
#define DO3213026	 BUFFER[226]	//(A3IS35LDU) Клапан «ВПИС1» открыт (обесточен)
#define idDO3213026	 106	//(A3IS35LDU) Клапан «ВПИС1» открыт (обесточен)
#define DO3213027	 BUFFER[228]	//(A3IS33LDU) Клапан «ВЫСТРЕЛ ИС1» открыт (обесточен)
#define idDO3213027	 107	//(A3IS33LDU) Клапан «ВЫСТРЕЛ ИС1» открыт (обесточен)
#define DO3213028	 BUFFER[230]	//(A2IS33LDU) Клапан «Подъём РБ1» открыт (обесточен)
#define idDO3213028	 108	//(A2IS33LDU) Клапан «Подъём РБ1» открыт (обесточен)
#define DO3213029	 BUFFER[232]	//(A4IS10LDU) Клапан «Подъём НИ1» открыт (обесточен)
#define idDO3213029	 109	//(A4IS10LDU) Клапан «Подъём НИ1» открыт (обесточен)
#define DO3213030	 BUFFER[234]	//(A3IS31LDU) Клапан «СПУСК ИС1» открыт (обесточен)
#define idDO3213030	 110	//(A3IS31LDU) Клапан «СПУСК ИС1» открыт (обесточен)
#define DO3213031	 BUFFER[236]	//(A7AS31LDU) Клапан «Обдув АЗ1» открыт (обесточен)
#define idDO3213031	 111	//(A7AS31LDU) Клапан «Обдув АЗ1» открыт (обесточен)
#define DO3213032	 BUFFER[238]	//(A1IS12LDU) Магнит ББ1 зацеплен
#define idDO3213032	 112	//(A1IS12LDU) Магнит ББ1 зацеплен
#define DO3214001	 BUFFER[240]	//(A1IS11LDU) Приход на ВУ ББ1
#define idDO3214001	 113	//(A1IS11LDU) Приход на ВУ ББ1
#define DO3214002	 BUFFER[242]	//(A1IS21LDU) Приход на НУ ББ1
#define idDO3214002	 114	//(A1IS21LDU) Приход на НУ ББ1
#define DO3214003	 BUFFER[244]	//(A2IS12LDU) Магнит РБ1 зацеплен
#define idDO3214003	 115	//(A2IS12LDU) Магнит РБ1 зацеплен
#define DO3214004	 BUFFER[246]	//(A2IS11LDU) Приход на ВУ РБ1-СТР
#define idDO3214004	 116	//(A2IS11LDU) Приход на ВУ РБ1-СТР
#define DO3214005	 BUFFER[248]	//(A2IS21LDU) Приход на НУ РБ1-СС
#define idDO3214005	 117	//(A2IS21LDU) Приход на НУ РБ1-СС
#define DO3214006	 BUFFER[250]	//(A3IS21LDU) Приход на НУ ИС1
#define idDO3214006	 118	//(A3IS21LDU) Приход на НУ ИС1
#define DO3214007	 BUFFER[252]	//(B4IS11LDU) Приход на ВУ НИ2
#define idDO3214007	 119	//(B4IS11LDU) Приход на ВУ НИ2
#define DO3214008	 BUFFER[254]	//(B4IS21LDU) Приход на НУ НИ2
#define idDO3214008	 120	//(B4IS21LDU) Приход на НУ НИ2
#define DO3214009	 BUFFER[256]	//(B8IS12LDU) Приход на механический ВУ АЗ2
#define idDO3214009	 121	//(B8IS12LDU) Приход на механический ВУ АЗ2
#define DO3214010	 BUFFER[258]	//()
#define idDO3214010	 122	//()
#define DO3214011	 BUFFER[260]	//(A3VP81LDU) Давление СПУСК ИС1 в норме
#define idDO3214011	 123	//(A3VP81LDU) Давление СПУСК ИС1 в норме
#define DO3214012	 BUFFER[262]	//(A2VP82LDU) Давление ПОДЪЁМ РБ1 в норме
#define idDO3214012	 124	//(A2VP82LDU) Давление ПОДЪЁМ РБ1 в норме
#define DO3214013	 BUFFER[264]	//(A4VP82LDU) Давление ПОДЪЁМ НИ1 в норме
#define idDO3214013	 125	//(A4VP82LDU) Давление ПОДЪЁМ НИ1 в норме
#define DO3214014	 BUFFER[266]	//(B3VP81LDU) Давление СПУСК ИС2 в норме
#define idDO3214014	 126	//(B3VP81LDU) Давление СПУСК ИС2 в норме
#define DO3214015	 BUFFER[268]	//(B2VP82LDU) Давление ПОДЪЁМ РБ2 в норме
#define idDO3214015	 127	//(B2VP82LDU) Давление ПОДЪЁМ РБ2 в норме
#define DO3214016	 BUFFER[270]	//(B4VP82LDU) Давление ПОДЪЁМ НИ2 в норме
#define idDO3214016	 128	//(B4VP82LDU) Давление ПОДЪЁМ НИ2 в норме
#define DO3214017	 BUFFER[272]	//(R0IS02LDU) Разрешение ввода от имитатора
#define idDO3214017	 129	//(R0IS02LDU) Разрешение ввода от имитатора
#define DO3214018	 BUFFER[274]	//(A3IS11LDU) Приход на ВУ ИС1
#define idDO3214018	 130	//(A3IS11LDU) Приход на ВУ ИС1
#define DO3214019	 BUFFER[276]	//(A3IS22LDU) Приход на НУП ИС1
#define idDO3214019	 131	//(A3IS22LDU) Приход на НУП ИС1
#define DO3214020	 BUFFER[278]	//(B3IS11LDU) Приход на ВУ ИС2
#define idDO3214020	 132	//(B3IS11LDU) Приход на ВУ ИС2
#define DO3214021	 BUFFER[280]	//(B3IS22LDU) Приход на НУП ИС2
#define idDO3214021	 133	//(B3IS22LDU) Приход на НУП ИС2
#define DO3214022	 BUFFER[282]	//(R4IS11LDU) Приход на ВУ тележки
#define idDO3214022	 134	//(R4IS11LDU) Приход на ВУ тележки
#define DO3214023	 BUFFER[284]	//(R4IS12LDU) Приход на механический ВУ тележки
#define idDO3214023	 135	//(R4IS12LDU) Приход на механический ВУ тележки
#define DO3214024	 BUFFER[286]	//(R4IS21LDU) Приход на НУ тележки
#define idDO3214024	 136	//(R4IS21LDU) Приход на НУ тележки
#define DO3214025	 BUFFER[288]	//(R4IS22LDU) Приход на механический НУ тележки
#define idDO3214025	 137	//(R4IS22LDU) Приход на механический НУ тележки
#define DO3214026	 BUFFER[290]	//()
#define idDO3214026	 138	//()
#define DO3214027	 BUFFER[292]	//(A6IS21LDU) Приход на НУ БЗ1
#define idDO3214027	 139	//(A6IS21LDU) Приход на НУ БЗ1
#define DO3214028	 BUFFER[294]	//(A5IS11LDU) Приход на ВУ НЛ1
#define idDO3214028	 140	//(A5IS11LDU) Приход на ВУ НЛ1
#define DO3214029	 BUFFER[296]	//(A5IS21LDU) Приход на НУ НЛ1
#define idDO3214029	 141	//(A5IS21LDU) Приход на НУ НЛ1
#define DO3214030	 BUFFER[298]	//(B6IS11LDU) Приход на ВУ БЗ2
#define idDO3214030	 142	//(B6IS11LDU) Приход на ВУ БЗ2
#define DO3214031	 BUFFER[300]	//(B6IS21LDU) Приход на НУ БЗ2
#define idDO3214031	 143	//(B6IS21LDU) Приход на НУ БЗ2
#define DO3214032	 BUFFER[302]	//(B5IS11LDU) Приход на ВУ НЛ2
#define idDO3214032	 144	//(B5IS11LDU) Приход на ВУ НЛ2
#define DO3215001	 BUFFER[304]	//(B5IS21LDU) Приход на НУ НЛ2
#define idDO3215001	 145	//(B5IS21LDU) Приход на НУ НЛ2
#define DO3215002	 BUFFER[306]	//(R3IS11LDU) Приход на ВУ гомогенных дверей-1
#define idDO3215002	 146	//(R3IS11LDU) Приход на ВУ гомогенных дверей-1
#define DO3215003	 BUFFER[308]	//(R3IS21LDU) Приход на НУ гомогенных дверей-1
#define idDO3215003	 147	//(R3IS21LDU) Приход на НУ гомогенных дверей-1
#define DO3215004	 BUFFER[310]	//(R3IS31LDU) Приход на ВУ гомогенных дверей-2
#define idDO3215004	 148	//(R3IS31LDU) Приход на ВУ гомогенных дверей-2
#define DO3215005	 BUFFER[312]	//(R3IS41LDU) Приход на НУ гомогенных дверей-2
#define idDO3215005	 149	//(R3IS41LDU) Приход на НУ гомогенных дверей-2
#define DO3215006	 BUFFER[314]	//(R3AD10LDU) Гомогенные двери-1 открыть
#define idDO3215006	 150	//(R3AD10LDU) Гомогенные двери-1 открыть
#define DO3215007	 BUFFER[316]	//(R3AD11LDU) Гомогенные двери-2 открыть
#define idDO3215007	 151	//(R3AD11LDU) Гомогенные двери-2 открыть
#define DO3215008	 BUFFER[318]	//(R3AD20LDU) Гомогенные двери-1 закрыть
#define idDO3215008	 152	//(R3AD20LDU) Гомогенные двери-1 закрыть
#define DO3215009	 BUFFER[320]	//(R3AD21LDU) Гомогенные двери-2 закрыть
#define idDO3215009	 153	//(R3AD21LDU) Гомогенные двери-2 закрыть
#define DO3215010	 BUFFER[322]	//(R5IS11LDU) Приход на ВУ ворот отстойной зоны
#define idDO3215010	 154	//(R5IS11LDU) Приход на ВУ ворот отстойной зоны
#define DO3215011	 BUFFER[324]	//(R5IS21LDU) Приход на НУ ворот отстойной зоны
#define idDO3215011	 155	//(R5IS21LDU) Приход на НУ ворот отстойной зоны
#define DO3215012	 BUFFER[326]	//(R5AD10LDU) Открыть ворота отстойной зоны
#define idDO3215012	 156	//(R5AD10LDU) Открыть ворота отстойной зоны
#define DO3215013	 BUFFER[328]	//(R5AD20LDU) Закрыть ворота отстойной зоны
#define idDO3215013	 157	//(R5AD20LDU) Закрыть ворота отстойной зоны
#define DO3215014	 BUFFER[330]	//(R6IS21LDU) Кран-балка в нерабочем положении
#define idDO3215014	 158	//(R6IS21LDU) Кран-балка в нерабочем положении
#define DO3215015	 BUFFER[332]	//(A8IS12LDU) Приход на механический ВУ ДС2
#define idDO3215015	 159	//(A8IS12LDU) Приход на механический ВУ ДС2
#define DO3215016	 BUFFER[334]	//(A8IS22LDU) Приход на механический НУ ДС2
#define idDO3215016	 160	//(A8IS22LDU) Приход на механический НУ ДС2
#define DO3215017	 BUFFER[336]	//(B8IS22LDU) Приход на механический НУ АЗ2
#define idDO3215017	 161	//(B8IS22LDU) Приход на механический НУ АЗ2
#define DO3215018	 BUFFER[338]	//(A6IS11LDU) Приход на ВУ БЗ1
#define idDO3215018	 162	//(A6IS11LDU) Приход на ВУ БЗ1
#define DO3215019	 BUFFER[340]	//(A2IE02LDU) Исправность ИП РБ1
#define idDO3215019	 163	//(A2IE02LDU) Исправность ИП РБ1
#define DO3215020	 BUFFER[342]	//(A2IE01LDU) Исправность БУШД РБ1
#define idDO3215020	 164	//(A2IE01LDU) Исправность БУШД РБ1
#define DO3215021	 BUFFER[344]	//(A2IE03LDU) Движение РБ1 вперед (от БУШД)
#define idDO3215021	 165	//(A2IE03LDU) Движение РБ1 вперед (от БУШД)
#define DO3215022	 BUFFER[346]	//(A2IE04LDU) Движение РБ1 назад (от БУШД)
#define idDO3215022	 166	//(A2IE04LDU) Движение РБ1 назад (от БУШД)
#define DO3215023	 BUFFER[348]	//(A3IE02LDU) Исправность ИП ИС1
#define idDO3215023	 167	//(A3IE02LDU) Исправность ИП ИС1
#define DO3215024	 BUFFER[350]	//(A3IE01LDU) Исправность БУШД ИС1
#define idDO3215024	 168	//(A3IE01LDU) Исправность БУШД ИС1
#define DO3215025	 BUFFER[352]	//(A3IE03LDU) Движение ИС1 вперед (от БУШД)
#define idDO3215025	 169	//(A3IE03LDU) Движение ИС1 вперед (от БУШД)
#define DO3215026	 BUFFER[354]	//(A3IE04LDU) Движение ИС1 назад (от БУШД)
#define idDO3215026	 170	//(A3IE04LDU) Движение ИС1 назад (от БУШД)
#define DO3215027	 BUFFER[356]	//(B1IE02LDU) Исправность ИП ББ2
#define idDO3215027	 171	//(B1IE02LDU) Исправность ИП ББ2
#define DO3215028	 BUFFER[358]	//(B1IE01LDU) Исправность БУШД ББ2
#define idDO3215028	 172	//(B1IE01LDU) Исправность БУШД ББ2
#define DO3215029	 BUFFER[360]	//(B2IE02LDU) Исправность ИП РБ2
#define idDO3215029	 173	//(B2IE02LDU) Исправность ИП РБ2
#define DO3215030	 BUFFER[362]	//(B2IE01LDU) Исправность БУШД РБ2
#define idDO3215030	 174	//(B2IE01LDU) Исправность БУШД РБ2
#define DO3215031	 BUFFER[364]	//(B2IE03LDU) Движение РБ2 вперед (от БУШД)
#define idDO3215031	 175	//(B2IE03LDU) Движение РБ2 вперед (от БУШД)
#define DO3215032	 BUFFER[366]	//(B2IE04LDU) Движение РБ2 назад (от БУШД)
#define idDO3215032	 176	//(B2IE04LDU) Движение РБ2 назад (от БУШД)
#define DO3216001	 BUFFER[368]	//(B3IE02LDU) Исправность ИП ИС2
#define idDO3216001	 177	//(B3IE02LDU) Исправность ИП ИС2
#define DO3216002	 BUFFER[370]	//(B3IE01LDU) Исправность БУШД ИС2
#define idDO3216002	 178	//(B3IE01LDU) Исправность БУШД ИС2
#define DO3216003	 BUFFER[372]	//(B3IE03LDU) Движение ИС2 вперед (от БУШД)
#define idDO3216003	 179	//(B3IE03LDU) Движение ИС2 вперед (от БУШД)
#define DO3216004	 BUFFER[374]	//(B3IE04LDU) Движение ИС2 назад (от БУШД)
#define idDO3216004	 180	//(B3IE04LDU) Движение ИС2 назад (от БУШД)
#define DO3216005	 BUFFER[376]	//(R6IS61LDU) Исправность 3-х  фазной сети
#define idDO3216005	 181	//(R6IS61LDU) Исправность 3-х  фазной сети
#define DO3216006	 BUFFER[378]	//(R4VS12LDU) Движение реактора  к «У ОБРАЗЦОВ»
#define idDO3216006	 182	//(R4VS12LDU) Движение реактора  к «У ОБРАЗЦОВ»
#define DO3216007	 BUFFER[380]	//(R4VS22LDU) Движение реактора к «У ЗАЩИТЫ»
#define idDO3216007	 183	//(R4VS22LDU) Движение реактора к «У ЗАЩИТЫ»
#define DO3216008	 BUFFER[382]	//(A8IE01LDU) Исправность ИП ДС2
#define idDO3216008	 184	//(A8IE01LDU) Исправность ИП ДС2
#define DO3216009	 BUFFER[384]	//(R1VS12LDU) Движение МДЗ1 в сторону ВУ
#define idDO3216009	 185	//(R1VS12LDU) Движение МДЗ1 в сторону ВУ
#define DO3216010	 BUFFER[386]	//(R1VS22LDU) Движение МДЗ1 в сторону НУ
#define idDO3216010	 186	//(R1VS22LDU) Движение МДЗ1 в сторону НУ
#define DO3216011	 BUFFER[388]	//(R1IE01LDU) Исправность ИП МДЗ1
#define idDO3216011	 187	//(R1IE01LDU) Исправность ИП МДЗ1
#define DO3216012	 BUFFER[390]	//(R2VS12LDU) Движение МДЗ2 в сторону ВУ
#define idDO3216012	 188	//(R2VS12LDU) Движение МДЗ2 в сторону ВУ
#define DO3216013	 BUFFER[392]	//(R2VS22LDU) Движение МДЗ2 в сторону НУ
#define idDO3216013	 189	//(R2VS22LDU) Движение МДЗ2 в сторону НУ
#define DO3216014	 BUFFER[394]	//(R2IE01LDU) Исправность ИП МДЗ2
#define idDO3216014	 190	//(R2IE01LDU) Исправность ИП МДЗ2
#define DO3216015	 BUFFER[396]	//(A5VS12LDU) Движение НЛ1 в сторону ВУ
#define idDO3216015	 191	//(A5VS12LDU) Движение НЛ1 в сторону ВУ
#define DO3216016	 BUFFER[398]	//(A5VS22LDU) Движение НЛ1 в сторону НУ
#define idDO3216016	 192	//(A5VS22LDU) Движение НЛ1 в сторону НУ
#define DO3216017	 BUFFER[400]	//(A5IE02LDU) Исправность ИП НЛ1
#define idDO3216017	 193	//(A5IE02LDU) Исправность ИП НЛ1
#define DO3216018	 BUFFER[402]	//(B5VS12LDU) Движение НЛ2 в сторону ВУ
#define idDO3216018	 194	//(B5VS12LDU) Движение НЛ2 в сторону ВУ
#define DO3216019	 BUFFER[404]	//(B5VS22LDU) Движение НЛ2 в сторону НУ
#define idDO3216019	 195	//(B5VS22LDU) Движение НЛ2 в сторону НУ
#define DO3216020	 BUFFER[406]	//(B5IE01LDU) Исправность ИП НЛ2
#define idDO3216020	 196	//(B5IE01LDU) Исправность ИП НЛ2
#define DO3216021	 BUFFER[408]	//(A6VS12LDU) Движение створок БЗ1  к  «ОТКРЫТА»
#define idDO3216021	 197	//(A6VS12LDU) Движение створок БЗ1  к  «ОТКРЫТА»
#define DO3216022	 BUFFER[410]	//(A6VS22LDU) Движение створок БЗ1  к «ЗАКРЫТА»
#define idDO3216022	 198	//(A6VS22LDU) Движение створок БЗ1  к «ЗАКРЫТА»
#define DO3216023	 BUFFER[412]	//(A6IE01LDU) Исправность ИП БЗ1
#define idDO3216023	 199	//(A6IE01LDU) Исправность ИП БЗ1
#define DO3216024	 BUFFER[414]	//(B6VS12LDU) Движение створок БЗ2  к  «ОТКРЫТА»
#define idDO3216024	 200	//(B6VS12LDU) Движение створок БЗ2  к  «ОТКРЫТА»
#define DO3216025	 BUFFER[416]	//(B6VS22LDU) Движение створок БЗ2  к «ЗАКРЫТА»
#define idDO3216025	 201	//(B6VS22LDU) Движение створок БЗ2  к «ЗАКРЫТА»
#define DO3216026	 BUFFER[418]	//(B6IE01LDU) Исправность ИП БЗ2
#define idDO3216026	 202	//(B6IE01LDU) Исправность ИП БЗ2
#define DO3216027	 BUFFER[420]	//(R0IE02LDU) Исправность ИП 24 В-1
#define idDO3216027	 203	//(R0IE02LDU) Исправность ИП 24 В-1
#define DO3216028	 BUFFER[422]	//(R0IE01LDU) Исправность ИП 24 В-2
#define idDO3216028	 204	//(R0IE01LDU) Исправность ИП 24 В-2
#define DO3216029	 BUFFER[424]	//(R6IS62LDU) Исправность ВИП ССДИ-39 1канал
#define idDO3216029	 205	//(R6IS62LDU) Исправность ВИП ССДИ-39 1канал
#define DO3216030	 BUFFER[426]	//(R6IS63LDU) Исправность ВИП ССДИ-39 2канал
#define idDO3216030	 206	//(R6IS63LDU) Исправность ВИП ССДИ-39 2канал
#define DO3216031	 BUFFER[428]	//(R6IS64LDU) Исправность ВИП ССДИ-35 1канал
#define idDO3216031	 207	//(R6IS64LDU) Исправность ВИП ССДИ-35 1канал
#define DO3216032	 BUFFER[430]	//(R6IS65LDU) Исправность ВИП ССДИ-35 2канал
#define idDO3216032	 208	//(R6IS65LDU) Исправность ВИП ССДИ-35 2канал
#define DO3212001	 BUFFER[432]	//!!!(DO3212001) ENCODER?
#define idDO3212001	 209	//!!!(DO3212001) ENCODER?
#define DO3212002	 BUFFER[434]	//!!!(DO3212002) ENCODER?
#define idDO3212002	 210	//!!!(DO3212002) ENCODER?
#define DO3212003	 BUFFER[436]	//!!!(DO3212003) ENCODER?
#define idDO3212003	 211	//!!!(DO3212003) ENCODER?
#define DO3212004	 BUFFER[438]	//!!!(DO3212004) ENCODER?
#define idDO3212004	 212	//!!!(DO3212004) ENCODER?
#define DO3212005	 BUFFER[440]	//!!!(DO3212005) ENCODER?
#define idDO3212005	 213	//!!!(DO3212005) ENCODER?
#define DO3212006	 BUFFER[442]	//!!!(DO3212006) ENCODER?
#define idDO3212006	 214	//!!!(DO3212006) ENCODER?
#define DO3212007	 BUFFER[444]	//!!!(DO3212007) ENCODER?
#define idDO3212007	 215	//!!!(DO3212007) ENCODER?
#define DO3212008	 BUFFER[446]	//!!!(DO3212008) ENCODER?
#define idDO3212008	 216	//!!!(DO3212008) ENCODER?
#define DO3212009	 BUFFER[448]	//!!!(DO3212009) ENCODER?
#define idDO3212009	 217	//!!!(DO3212009) ENCODER?
#define DO3212010	 BUFFER[450]	//!!!(DO3212010) ENCODER?
#define idDO3212010	 218	//!!!(DO3212010) ENCODER?
#define DO3212011	 BUFFER[452]	//!!!(DO3212011) ENCODER?
#define idDO3212011	 219	//!!!(DO3212011) ENCODER?
#define DO3212012	 BUFFER[454]	//!!!(DO3212012) ENCODER?
#define idDO3212012	 220	//!!!(DO3212012) ENCODER?
#define DO3212013	 BUFFER[456]	//!!!(DO3212013) ENCODER?
#define idDO3212013	 221	//!!!(DO3212013) ENCODER?
#define DO3212014	 BUFFER[458]	//!!!(DO3212014) ENCODER?
#define idDO3212014	 222	//!!!(DO3212014) ENCODER?
#define DO3212015	 BUFFER[460]	//!!!(DO3212015) ENCODER?
#define idDO3212015	 223	//!!!(DO3212015) ENCODER?
#define DO3212016	 BUFFER[462]	//!!!(DO3212016) ENCODER?
#define idDO3212016	 224	//!!!(DO3212016) ENCODER?
#define DO3212017	 BUFFER[464]	//!!!(DO3212017) ENCODER?
#define idDO3212017	 225	//!!!(DO3212017) ENCODER?
#define DO3212018	 BUFFER[466]	//!!!(DO3212018) ENCODER?
#define idDO3212018	 226	//!!!(DO3212018) ENCODER?
#define DO3212019	 BUFFER[468]	//!!!(DO3212019) ENCODER?
#define idDO3212019	 227	//!!!(DO3212019) ENCODER?
#define DO3212020	 BUFFER[470]	//!!!(DO3212020) ENCODER?
#define idDO3212020	 228	//!!!(DO3212020) ENCODER?
#define DO3212021	 BUFFER[472]	//!!!(DO3212021) ENCODER?
#define idDO3212021	 229	//!!!(DO3212021) ENCODER?
#define DO3212022	 BUFFER[474]	//!!!(DO3212022) ENCODER?
#define idDO3212022	 230	//!!!(DO3212022) ENCODER?
#define DO3212023	 BUFFER[476]	//!!!(DO3212023) ENCODER?
#define idDO3212023	 231	//!!!(DO3212023) ENCODER?
#define DO3212024	 BUFFER[478]	//!!!(DO3212024) ENCODER?
#define idDO3212024	 232	//!!!(DO3212024) ENCODER?
#define DO3212025	 BUFFER[480]	//!!!(DO3212025) ENCODER?
#define idDO3212025	 233	//!!!(DO3212025) ENCODER?
#define DO3212026	 BUFFER[482]	//!!!(DO3212026) ENCODER?
#define idDO3212026	 234	//!!!(DO3212026) ENCODER?
#define DO3212027	 BUFFER[484]	//!!!(DO3212027) ENCODER?
#define idDO3212027	 235	//!!!(DO3212027) ENCODER?
#define DO3212028	 BUFFER[486]	//!!!(DO3212028) ENCODER?
#define idDO3212028	 236	//!!!(DO3212028) ENCODER?
#define DO3212029	 BUFFER[488]	//!!!(DO3212029) ENCODER?
#define idDO3212029	 237	//!!!(DO3212029) ENCODER?
#define DO3212030	 BUFFER[490]	//!!!(DO3212030) ENCODER?
#define idDO3212030	 238	//!!!(DO3212030) ENCODER?
#define DO3212031	 BUFFER[492]	//!!!(DO3212031) ENCODER?
#define idDO3212031	 239	//!!!(DO3212031) ENCODER?
#define DO3212032	 BUFFER[494]	//!!!(DO3212032) ENCODER?
#define idDO3212032	 240	//!!!(DO3212032) ENCODER?
#define VDSR34001	 BUFFER[496]	//(A1IC01LDU) BUS1_ББ1
#define idVDSR34001	 241	//(A1IC01LDU) BUS1_ББ1
#define VDSR34002	 BUFFER[498]	//(B1IC01LDU) BUS2_ББ2
#define idVDSR34002	 242	//(B1IC01LDU) BUS2_ББ2
#define VDSR34003	 BUFFER[500]	//(A2IC01LDU) BUS3_РБ1
#define idVDSR34003	 243	//(A2IC01LDU) BUS3_РБ1
#define VDSR34004	 BUFFER[502]	//(B2IC01LDU) BUS4_РБ2
#define idVDSR34004	 244	//(B2IC01LDU) BUS4_РБ2
#define VDSR34005	 BUFFER[504]	//(A3IC01LDU) BUS5_ИС1
#define idVDSR34005	 245	//(A3IC01LDU) BUS5_ИС1
#define VDSR34006	 BUFFER[506]	//(B3IC01LDU) BUS6_ИС2
#define idVDSR34006	 246	//(B3IC01LDU) BUS6_ИС2
#define VDSR34007	 BUFFER[508]	//(B8IC01LDU) BUS7_АЗ2
#define idVDSR34007	 247	//(B8IC01LDU) BUS7_АЗ2
#define VDSR34008	 BUFFER[510]	//(A8IC01LDU) BUS8_ДС2
#define idVDSR34008	 248	//(A8IC01LDU) BUS8_ДС2
#define VDSR34009	 BUFFER[512]	//(R0IC41LDU) LUTCH
#define idVDSR34009	 249	//(R0IC41LDU) LUTCH
#define VDSR34010	 BUFFER[514]	//(R0IC42LDU) Вход запрета
#define idVDSR34010	 250	//(R0IC42LDU) Вход запрета
#define VDSR34011	 BUFFER[516]	//(R0IC43LDU) Выход запрета
#define idVDSR34011	 251	//(R0IC43LDU) Выход запрета
#define VDSR34012	 BUFFER[518]	//(A3AD34LDU) Клапан ВПИС1  открыть (обесточить)
#define idVDSR34012	 252	//(A3AD34LDU) Клапан ВПИС1  открыть (обесточить)
#define VDSR34013	 BUFFER[520]	//(A3AD33LDU) Клапан «ВЫСТРЕЛ ИС1» открыть (обесточить)
#define idVDSR34013	 253	//(A3AD33LDU) Клапан «ВЫСТРЕЛ ИС1» открыть (обесточить)
#define VDSR34014	 BUFFER[522]	//(A2AD33LDU) Клапан «Подъем РБ1» открыть
#define idVDSR34014	 254	//(A2AD33LDU) Клапан «Подъем РБ1» открыть
#define VDSR34015	 BUFFER[524]	//(A4AD10LDU) Открыть клапан Подъем НИ1
#define idVDSR34015	 255	//(A4AD10LDU) Открыть клапан Подъем НИ1
#define VDSR34016	 BUFFER[526]	//(A3AD31LDU) Клапан «СПУСК ИС1» открыть (обесточить)
#define idVDSR34016	 256	//(A3AD31LDU) Клапан «СПУСК ИС1» открыть (обесточить)
#define VDSR34017	 BUFFER[528]	//(A7AP31LDU) Клапан «Обдув АЗ1» открыть (обесточить)
#define idVDSR34017	 257	//(A7AP31LDU) Клапан «Обдув АЗ1» открыть (обесточить)
#define VDSR34018	 BUFFER[530]	//(R1AD10LDU) Опустить МДЗ1 в зону облучения
#define idVDSR34018	 258	//(R1AD10LDU) Опустить МДЗ1 в зону облучения
#define VDSR34019	 BUFFER[532]	//(R1AD20LDU) Поднять МДЗ1
#define idVDSR34019	 259	//(R1AD20LDU) Поднять МДЗ1
#define VDSR34020	 BUFFER[534]	//(R2AD10LDU) Опустить МДЗ2 в зону облучения
#define idVDSR34020	 260	//(R2AD10LDU) Опустить МДЗ2 в зону облучения
#define VDSR34021	 BUFFER[536]	//(R2AD20LDU) Поднять МДЗ2
#define idVDSR34021	 261	//(R2AD20LDU) Поднять МДЗ2
#define VDSR34022	 BUFFER[538]	//(A5AD10LDU) Поднять НЛ1
#define idVDSR34022	 262	//(A5AD10LDU) Поднять НЛ1
#define VDSR34023	 BUFFER[540]	//(A5AD20LDU) Опустить НЛ1
#define idVDSR34023	 263	//(A5AD20LDU) Опустить НЛ1
#define VDSR34024	 BUFFER[542]	//(B5AD10LDU) Поднять НЛ2
#define idVDSR34024	 264	//(B5AD10LDU) Поднять НЛ2
#define VDSR34025	 BUFFER[544]	//(B5AD20LDU) Опустить НЛ2
#define idVDSR34025	 265	//(B5AD20LDU) Опустить НЛ2
#define VDSR34026	 BUFFER[546]	//(B3AD34LDU) Клапан ВПИС ИС2  открыть (обесточить)
#define idVDSR34026	 266	//(B3AD34LDU) Клапан ВПИС ИС2  открыть (обесточить)
#define VDSR34027	 BUFFER[548]	//(B3AD33LDU) Клапан «ВЫСТРЕЛ ИС2» закрыть (обесточить)
#define idVDSR34027	 267	//(B3AD33LDU) Клапан «ВЫСТРЕЛ ИС2» закрыть (обесточить)
#define VDSR34028	 BUFFER[550]	//(B2AD33LDU) Клапан «Подъем РБ2» открыть
#define idVDSR34028	 268	//(B2AD33LDU) Клапан «Подъем РБ2» открыть
#define VDSR34029	 BUFFER[552]	//(B4AD10LDU) Открыть клапан Подъем НИ2
#define idVDSR34029	 269	//(B4AD10LDU) Открыть клапан Подъем НИ2
#define VDSR34030	 BUFFER[554]	//(B3AD31LDU) Клапан «СПУСК ИС2» открыть (обесточить)
#define idVDSR34030	 270	//(B3AD31LDU) Клапан «СПУСК ИС2» открыть (обесточить)
#define VDSR34031	 BUFFER[556]	//(B7AP31LDU) Клапан «Обдув АЗ2» открыть (обесточить)
#define idVDSR34031	 271	//(B7AP31LDU) Клапан «Обдув АЗ2» открыть (обесточить)
#define VDSR34032	 BUFFER[558]	//(A8AD10LDU) Перемещение ДС2 вперед
#define idVDSR34032	 272	//(A8AD10LDU) Перемещение ДС2 вперед
#define VDSR36001	 BUFFER[560]	//(A8AD20LDU) Перемещение ДС2 назад
#define idVDSR36001	 273	//(A8AD20LDU) Перемещение ДС2 назад
#define VDSR36002	 BUFFER[562]	//(A6AD10LDU) Открыть БЗ1
#define idVDSR36002	 274	//(A6AD10LDU) Открыть БЗ1
#define VDSR36003	 BUFFER[564]	//(A6AD20LDU) Закрыть БЗ1
#define idVDSR36003	 275	//(A6AD20LDU) Закрыть БЗ1
#define VDSR36004	 BUFFER[566]	//(B6AD10LDU) Открыть БЗ2
#define idVDSR36004	 276	//(B6AD10LDU) Открыть БЗ2
#define VDSR36005	 BUFFER[568]	//(B6AD20LDU) Закрыть БЗ2
#define idVDSR36005	 277	//(B6AD20LDU) Закрыть БЗ2
#define VDSR36006	 BUFFER[570]	//(R4AD10LDU) Перемещение тележки вперед
#define idVDSR36006	 278	//(R4AD10LDU) Перемещение тележки вперед
#define VDSR36007	 BUFFER[572]	//(R4AD20LDU) Перемещение тележки назад
#define idVDSR36007	 279	//(R4AD20LDU) Перемещение тележки назад
#define VDSR36008	 BUFFER[574]	//(B8AD10LDU) Перемещение АЗ2 вперед
#define idVDSR36008	 280	//(B8AD10LDU) Перемещение АЗ2 вперед
#define VDSR36009	 BUFFER[576]	//(B8AD20LDU) Перемещение АЗ2 назад
#define idVDSR36009	 281	//(B8AD20LDU) Перемещение АЗ2 назад
#define VDSR36010	 BUFFER[578]	//(A3AD11LDU) Сигнал на перемещение ИС1 вверх
#define idVDSR36010	 282	//(A3AD11LDU) Сигнал на перемещение ИС1 вверх
#define VDSR36011	 BUFFER[580]	//(A3AD21LDU) Сигнал на перемещение ИС1 вниз
#define idVDSR36011	 283	//(A3AD21LDU) Сигнал на перемещение ИС1 вниз
#define VDSR36012	 BUFFER[582]	//(A3AD01LDU) Разрешение движения ИС1
#define idVDSR36012	 284	//(A3AD01LDU) Разрешение движения ИС1
#define VDSR36013	 BUFFER[584]	//(A3AD02LDU) 0-й бит скорости ИС1
#define idVDSR36013	 285	//(A3AD02LDU) 0-й бит скорости ИС1
#define VDSR36014	 BUFFER[586]	//(A3AD03LDU) 1-й бит скорости ИС1
#define idVDSR36014	 286	//(A3AD03LDU) 1-й бит скорости ИС1
#define VDSR36015	 BUFFER[588]	//(A3AD04LDU) 2-й бит скорости ИС1
#define idVDSR36015	 287	//(A3AD04LDU) 2-й бит скорости ИС1
#define VDSR36016	 BUFFER[590]	//(A3AD05LDU) паритет команды на ИС1
#define idVDSR36016	 288	//(A3AD05LDU) паритет команды на ИС1
#define VDSR36017	 BUFFER[592]	//(B3AD11LDU) Сигнал на перемещение ИС2 вверх
#define idVDSR36017	 289	//(B3AD11LDU) Сигнал на перемещение ИС2 вверх
#define VDSR36018	 BUFFER[594]	//(B3AD21LDU) Сигнал на перемещение ИС2 вниз
#define idVDSR36018	 290	//(B3AD21LDU) Сигнал на перемещение ИС2 вниз
#define VDSR36019	 BUFFER[596]	//(B3AD01LDU) Разрешение движения ИС2
#define idVDSR36019	 291	//(B3AD01LDU) Разрешение движения ИС2
#define VDSR36020	 BUFFER[598]	//(B3AD02LDU) 0-й бит скорости ИС2
#define idVDSR36020	 292	//(B3AD02LDU) 0-й бит скорости ИС2
#define VDSR36021	 BUFFER[600]	//(B3AD03LDU) 1-й бит скорости ИС2
#define idVDSR36021	 293	//(B3AD03LDU) 1-й бит скорости ИС2
#define VDSR36022	 BUFFER[602]	//(B3AD04LDU) 2-й бит скорости ИС2
#define idVDSR36022	 294	//(B3AD04LDU) 2-й бит скорости ИС2
#define VDSR36023	 BUFFER[604]	//(B3AD05LDU) паритет команды на ИС2
#define idVDSR36023	 295	//(B3AD05LDU) паритет команды на ИС2
#define VDSR36024	 BUFFER[606]	//(A9AD10LDU) Открыть клапан Подъем НИ ДС1
#define idVDSR36024	 296	//(A9AD10LDU) Открыть клапан Подъем НИ ДС1
#define VDSR36025	 BUFFER[608]	//(B9AD10LDU) Открыть клапан Подъем НИ ДС2
#define idVDSR36025	 297	//(B9AD10LDU) Открыть клапан Подъем НИ ДС2
#define VDSR36026	 BUFFER[610]	//(A1AD11LDU) Сигнал на перемещение ББ1 вверх
#define idVDSR36026	 298	//(A1AD11LDU) Сигнал на перемещение ББ1 вверх
#define VDSR36027	 BUFFER[612]	//(A1AD21LDU) Сигнал на перемещение ББ1 вниз
#define idVDSR36027	 299	//(A1AD21LDU) Сигнал на перемещение ББ1 вниз
#define VDSR36028	 BUFFER[614]	//(A1AD01LDU) Разрешение движения ББ1
#define idVDSR36028	 300	//(A1AD01LDU) Разрешение движения ББ1
#define VDSR36029	 BUFFER[616]	//(A1AD02LDU) 0-й бит скорости ББ1
#define idVDSR36029	 301	//(A1AD02LDU) 0-й бит скорости ББ1
#define VDSR36030	 BUFFER[618]	//(A1AD03LDU) 1-й бит скорости ББ1
#define idVDSR36030	 302	//(A1AD03LDU) 1-й бит скорости ББ1
#define VDSR36031	 BUFFER[620]	//(A1AD04LDU) 2-й бит скорости ББ1
#define idVDSR36031	 303	//(A1AD04LDU) 2-й бит скорости ББ1
#define VDSR36032	 BUFFER[622]	//!!!(DO3211032) не занята
#define idVDSR36032	 304	//!!!(DO3211032) не занята
#define VDSR31001	 BUFFER[624]	//(A1AD05LDU) паритет команды на ББ1
#define idVDSR31001	 305	//(A1AD05LDU) паритет команды на ББ1
#define VDSR31002	 BUFFER[626]	//(B1AD11LDU) Сигнал на перемещение ББ2 вверх
#define idVDSR31002	 306	//(B1AD11LDU) Сигнал на перемещение ББ2 вверх
#define VDSR31003	 BUFFER[628]	//(B1AD21LDU) Сигнал на перемещение ББ2 вниз
#define idVDSR31003	 307	//(B1AD21LDU) Сигнал на перемещение ББ2 вниз
#define VDSR31004	 BUFFER[630]	//(B1AD01LDU) Разрешение движения ББ2
#define idVDSR31004	 308	//(B1AD01LDU) Разрешение движения ББ2
#define VDSR31005	 BUFFER[632]	//(B1AD02LDU) 0-й бит скорости ББ2
#define idVDSR31005	 309	//(B1AD02LDU) 0-й бит скорости ББ2
#define VDSR31006	 BUFFER[634]	//(B1AD03LDU) 1-й бит скорости ББ2
#define idVDSR31006	 310	//(B1AD03LDU) 1-й бит скорости ББ2
#define VDSR31007	 BUFFER[636]	//(B1AD04LDU) 2-й бит скорости ББ2
#define idVDSR31007	 311	//(B1AD04LDU) 2-й бит скорости ББ2
#define VDSR31008	 BUFFER[638]	//(B1AD05LDU) паритет команды на ББ2
#define idVDSR31008	 312	//(B1AD05LDU) паритет команды на ББ2
#define VDSR31009	 BUFFER[640]	//(A2AD11LDU) Сигнал на перемещение РБ1 вверх
#define idVDSR31009	 313	//(A2AD11LDU) Сигнал на перемещение РБ1 вверх
#define VDSR31010	 BUFFER[642]	//(A2AD21LDU) Сигнал на перемещение РБ1 вниз
#define idVDSR31010	 314	//(A2AD21LDU) Сигнал на перемещение РБ1 вниз
#define VDSR31011	 BUFFER[644]	//(A2AD01LDU) Разрешение движения РБ1
#define idVDSR31011	 315	//(A2AD01LDU) Разрешение движения РБ1
#define VDSR31012	 BUFFER[646]	//(A2AD02LDU) 0-й бит скорости РБ1
#define idVDSR31012	 316	//(A2AD02LDU) 0-й бит скорости РБ1
#define VDSR31013	 BUFFER[648]	//(A2AD03LDU) 1-й бит скорости РБ1
#define idVDSR31013	 317	//(A2AD03LDU) 1-й бит скорости РБ1
#define VDSR31014	 BUFFER[650]	//(A2AD04LDU) 2-й бит скорости РБ1
#define idVDSR31014	 318	//(A2AD04LDU) 2-й бит скорости РБ1
#define VDSR31015	 BUFFER[652]	//(A2AD05LDU) паритет команды на РБ1
#define idVDSR31015	 319	//(A2AD05LDU) паритет команды на РБ1
#define VDSR31016	 BUFFER[654]	//(B2AD11LDU) Сигнал на перемещение РБ2 вверх
#define idVDSR31016	 320	//(B2AD11LDU) Сигнал на перемещение РБ2 вверх
#define VDSR31017	 BUFFER[656]	//(B2AD21LDU) Сигнал на перемещение РБ2 вниз
#define idVDSR31017	 321	//(B2AD21LDU) Сигнал на перемещение РБ2 вниз
#define VDSR31018	 BUFFER[658]	//(B2AD01LDU) Разрешение движения РБ2
#define idVDSR31018	 322	//(B2AD01LDU) Разрешение движения РБ2
#define VDSR31019	 BUFFER[660]	//(B2AD02LDU) 0-й бит скорости РБ2
#define idVDSR31019	 323	//(B2AD02LDU) 0-й бит скорости РБ2
#define VDSR31020	 BUFFER[662]	//(B2AD03LDU) 1-й бит скорости РБ2
#define idVDSR31020	 324	//(B2AD03LDU) 1-й бит скорости РБ2
#define VDSR31021	 BUFFER[664]	//(B2AD04LDU) 2-й бит скорости РБ2
#define idVDSR31021	 325	//(B2AD04LDU) 2-й бит скорости РБ2
#define VDSR31022	 BUFFER[666]	//(B2AD05LDU) паритет команды на РБ2
#define idVDSR31022	 326	//(B2AD05LDU) паритет команды на РБ2
#define VDSR31023	 BUFFER[668]	//(A1AD32LDU) Обесточить ЭМ ББ1
#define idVDSR31023	 327	//(A1AD32LDU) Обесточить ЭМ ББ1
#define VDSR31024	 BUFFER[670]	//(A1AD31LDU) Клапан «Сброс ББ1» открыть (обесточить)
#define idVDSR31024	 328	//(A1AD31LDU) Клапан «Сброс ББ1» открыть (обесточить)
#define VDSR31025	 BUFFER[672]	//(A2AD32LDU) Обесточить ЭМ РБ1
#define idVDSR31025	 329	//(A2AD32LDU) Обесточить ЭМ РБ1
#define VDSR31026	 BUFFER[674]	//(A2AD31LDU) Клапан «Сброс РБ1» открыть (обесточить)
#define idVDSR31026	 330	//(A2AD31LDU) Клапан «Сброс РБ1» открыть (обесточить)
#define VDSR31027	 BUFFER[676]	//(B1AD32LDU) Обесточить ЭМ ББ2
#define idVDSR31027	 331	//(B1AD32LDU) Обесточить ЭМ ББ2
#define VDSR31028	 BUFFER[678]	//(B1AD31LDU) Клапан «Сброс ББ2» открыть (обесточить)
#define idVDSR31028	 332	//(B1AD31LDU) Клапан «Сброс ББ2» открыть (обесточить)
#define VDSR31029	 BUFFER[680]	//(B2AD32LDU) Обесточить ЭМ РБ2
#define idVDSR31029	 333	//(B2AD32LDU) Обесточить ЭМ РБ2
#define VDSR31030	 BUFFER[682]	//(B2AD31LDU) Клапан «Сброс РБ2» открыть (обесточить)
#define idVDSR31030	 334	//(B2AD31LDU) Клапан «Сброс РБ2» открыть (обесточить)
#define VDSR31031	 BUFFER[684]	//(R8AD21LDU) Запуск системы инициирования
#define idVDSR31031	 335	//(R8AD21LDU) Запуск системы инициирования
#define VDSR31032	 BUFFER[686]	//(R0AD16LDU) Контроль  I-II УР. РАД
#define idVDSR31032	 336	//(R0AD16LDU) Контроль  I-II УР. РАД
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,3	,1	, &AO1632001},	//(A0IT01IZ1) Температура АЗ1-1
	{ 2	,3	,1	, &AO1632002},	//(A2IP01IZ1) Текущее давление СБРОС РБ1
	{ 3	,3	,1	, &AO1632003},	//(B0IT01IZ1) Температура АЗ2-1
	{ 4	,3	,1	, &AO1632004},	//(B2IP01IZ1) Текущее давление СБРОС РБ2
	{ 5	,3	,1	, &AO1632005},	//(A0IT02IZ2) Температура АЗ1-2
	{ 6	,3	,1	, &AO1632006},	//(A2IP01IZ2) Текущее давление СБРОС РБ1
	{ 7	,3	,1	, &AO1632007},	//(B0IT02IZ2) Температура АЗ2-2
	{ 8	,3	,1	, &AO1632008},	//(B2IP01IZ2) Текущее давление СБРОС РБ2
	{ 9	,3	,1	, &AO1632009},	//(A3IP02IDU) Текущее давление ВЫСТРЕЛ ИС1
	{ 10	,3	,1	, &AO1632010},	//(B3IP02IDU) Текущее давление ВЫСТРЕЛ ИС2
	{ 11	,3	,1	, &AO1632011},	//!!!(AO1632011) Не занятые значения
	{ 12	,3	,1	, &AO1632012},	//!!!(AO1632012) Не занятые значения
	{ 13	,3	,1	, &AO1632013},	//!!!(AO1632013) Не занятые значения
	{ 14	,3	,1	, &AO1632014},	//!!!(AO1632014) Не занятые значения
	{ 15	,3	,1	, &AO1632015},	//!!!(AO1632015) Не занятые значения
	{ 16	,3	,1	, &AO1632016},	//!!!(AO1632016) Не занятые значения
	{ 17	,1	,1	, &DO3210001},	//(R0VN71LZ1) АС по мощности канал 1
	{ 18	,1	,1	, &DO3210002},	//(R0VN75LZ1) АС по периоду разгона канал  1
	{ 19	,1	,1	, &DO3210003},	//(A0EE01LS1) Исправность АКНП канал 1 
	{ 20	,1	,1	, &DO3210004},	//(A0VN71LS1) Блокировка автоматического подъёма ББ канал 1
	{ 21	,1	,1	, &DO3210005},	//(A3IS11LZ1) Приход на ВУ ИС1
	{ 22	,1	,1	, &DO3210006},	//(A3IS22LZ1) Приход на НУП ИС1
	{ 23	,1	,1	, &DO3210007},	//(R0VN72LZ1) АС по мощности канал 2
	{ 24	,1	,1	, &DO3210008},	//(R0VN76LZ1) АС по периоду разгона канал  2
	{ 25	,1	,1	, &DO3210009},	//(A0EE01LS2) Исправность АКНП  канал 2
	{ 26	,1	,1	, &DO3210010},	//(A0VN71LS2) Блокировка автоматического подъёма ББ канал 2
	{ 27	,1	,1	, &DO3210011},	//(B3IS11LZ1) Приход на ВУ ИС2
	{ 28	,1	,1	, &DO3210012},	//(B3IS22LZ1) Приход на НУП ИС2
	{ 29	,1	,1	, &DO3210013},	//(R0VN74LZ1) АС по мощности канал 4
	{ 30	,1	,1	, &DO3210014},	//(R0VN78LZ1) АС по периоду разгона канал  4
	{ 31	,1	,1	, &DO3210015},	//(A0EE01LS4) Исправность АКНП канал 4
	{ 32	,1	,1	, &DO3210016},	//(A0VN71LS4) Блокировка автоматического подъёма ББ канал 4
	{ 33	,1	,1	, &DO3210017},	//(R6IS66LZ1) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 34	,1	,1	, &DO3210018},	//(R6IS67LZ1) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 35	,1	,1	, &DO3210019},	//(R6IS68LZ1) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 36	,1	,1	, &DO3210020},	//(R0VN73LZ1) АС по мощности канал 3
	{ 37	,1	,1	, &DO3210021},	//(R0VN77LZ1) АС по периоду разгона канал  3
	{ 38	,1	,1	, &DO3210022},	//(A0EE01LS3) Исправность АКНП канал 3
	{ 39	,1	,1	, &DO3210023},	//(A0VN71LS3) Блокировка автоматического подъёма ББ канал 3
	{ 40	,1	,1	, &DO3210024},	//(R7II71LZ1) Сработала АС IУР РАД (датчик 1)
	{ 41	,1	,1	, &DO3210025},	//(R7II72LZ1) Сработала АС IУР РАД  (датчик 2)
	{ 42	,1	,1	, &DO3210026},	//(R7II73LZ1) Сработала АС II УР РАД
	{ 43	,1	,1	, &DO3210027},	//(A0VP81LZ1) Давление  АЗ1 в норме
	{ 44	,1	,1	, &DO3210028},	//(A1VP81LZ1) Давление СБРОС ББ1 в норме
	{ 45	,1	,1	, &DO3210029},	//(R0VP81LZ1) Давление  в СИСТЕМЕ -1 в норме
	{ 46	,1	,1	, &DO3210030},	//(B0VP81LZ1) Давление АЗ2 в норме
	{ 47	,1	,1	, &DO3210031},	//(B1VP81LZ1) Давление СБРОС ББ2 в норме
	{ 48	,1	,1	, &DO3210032},	//(R0VP82LZ1) Давление  в СИСТЕМЕ - 2 в норме
	{ 49	,1	,1	, &DO3211001},	//(R0VN71LZ2) АС по мощности канал 1
	{ 50	,1	,1	, &DO3211002},	//(R0VN75LZ2) АС по периоду разгона канал  1
	{ 51	,1	,1	, &DO3211003},	//(A1EE01LS1) Исправность АКНП канал 1
	{ 52	,1	,1	, &DO3211004},	//(A1VN71LS1) Блокировка автоматического подъёма ББ канал 1
	{ 53	,1	,1	, &DO3211005},	//(A3IS11LZ2) Приход на ВУ ИС1
	{ 54	,1	,1	, &DO3211006},	//(A3IS22LZ2) Приход на НУП ИС1
	{ 55	,1	,1	, &DO3211007},	//(R0VN72LZ2) АС по мощности канал 2
	{ 56	,1	,1	, &DO3211008},	//(R0VN76LZ2) АС по периоду разгона канал  2
	{ 57	,1	,1	, &DO3211009},	//(A1EE01LS2) Исправность АКНП  канал 2
	{ 58	,1	,1	, &DO3211010},	//(A1VN71LS2) Блокировка автоматического подъёма ББ канал 2
	{ 59	,1	,1	, &DO3211011},	//(B3IS11LZ2) Приход на ВУ ИС2
	{ 60	,1	,1	, &DO3211012},	//(B3IS22LZ2) Приход на НУП ИС2
	{ 61	,1	,1	, &DO3211013},	//(R0VN74LZ2) АС по мощности канал 4
	{ 62	,1	,1	, &DO3211014},	//(R0VN78LZ2) АС по периоду разгона канал  4
	{ 63	,1	,1	, &DO3211015},	//(A1EE01LS4) Исправность АКНП канал 4
	{ 64	,1	,1	, &DO3211016},	//(A1VN71LS4) Блокировка автоматического подъёма ББ канал 4
	{ 65	,1	,1	, &DO3211017},	//(R6IS66LZ2) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 66	,1	,1	, &DO3211018},	//(R6IS67LZ2) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 67	,1	,1	, &DO3211019},	//(R6IS68LZ2) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 68	,1	,1	, &DO3211020},	//(R0VN73LZ2) АС по мощности канал 3
	{ 69	,1	,1	, &DO3211021},	//(R0VN77LZ2) АС по периоду разгона канал  3
	{ 70	,1	,1	, &DO3211022},	//(A1EE01LS3) Исправность АКНП канал 3
	{ 71	,1	,1	, &DO3211023},	//(A1VN71LS3) Блокировка автоматического подъёма ББ канал 3
	{ 72	,1	,1	, &DO3211024},	//(R7II71LZ2) Сработала АС IУР (датчик 1)
	{ 73	,1	,1	, &DO3211025},	//(R7II72LZ2) Сработала АС IУР (датчик 2)
	{ 74	,1	,1	, &DO3211026},	//(R7II73LZ2) Сработала АС IIУР
	{ 75	,1	,1	, &DO3211027},	//(A0VP81LZ2) Давление  АЗ1 в норме
	{ 76	,1	,1	, &DO3211028},	//(A1VP81LZ2) Давление СБРОС ББ1 в норме
	{ 77	,1	,1	, &DO3211029},	//(R0VP81LZ2) Давление  в СИСТЕМЕ -1 в норме
	{ 78	,1	,1	, &DO3211030},	//(B0VP81LZ2) Давление АЗ2 в норме
	{ 79	,1	,1	, &DO3211031},	//(B1VP81LZ2) Давление СБРОС ББ2 в норме
	{ 80	,1	,1	, &DO3211032},	//(R0VP82LZ2) Давление  в СИСТЕМЕ - 2 в норме
	{ 81	,1	,1	, &DO3213001},	//(B3IS35LDU) Клапан «ВПИС2» открыт (обесточен) 
	{ 82	,1	,1	, &DO3213002},	//(B3IS33LDU) Клапан «ВЫСТРЕЛ ИС2» открыт (обесточен) 
	{ 83	,1	,1	, &DO3213003},	//(B2IS33LDU) Клапан «Подъём РБ2» открыт (обесточен) 
	{ 84	,1	,1	, &DO3213004},	//(B4IS10LDU) Клапан «Подъём НИ2» открыт (обесточен) 
	{ 85	,1	,1	, &DO3213005},	//(B3IS31LDU) Клапан «СПУСК ИС2» открыт (обесточен) 
	{ 86	,1	,1	, &DO3213006},	//(B7AS31LDU) Клапан «Обдув АЗ2» открыт (обесточен) 
	{ 87	,1	,1	, &DO3213007},	//(B1IS12LDU) Магнит ББ2 зацеплен 
	{ 88	,1	,1	, &DO3213008},	//(B1IS11LDU) Приход на ВУ ББ2 
	{ 89	,1	,1	, &DO3213009},	//(B1IS21LDU) Приход на НУ ББ2 
	{ 90	,1	,1	, &DO3213010},	//(B2IS12LDU) Магнит РБ2 зацеплен 
	{ 91	,1	,1	, &DO3213011},	//(B2IS11LDU) Приход на ВУ РБ2-СТР 
	{ 92	,1	,1	, &DO3213012},	//(B2IS21LDU) Приход на НУ РБ2-СС 
	{ 93	,1	,1	, &DO3213013},	//(B3IS21LDU) Приход на НУ ИС2 
	{ 94	,1	,1	, &DO3213014},	//(R8IS11LDU) Аварийный НИ установлен 
	{ 95	,1	,1	, &DO3213015},	//!!!(DO3213015) Не занятые значения
	{ 96	,1	,1	, &DO3213016},	//(A4IS11LDU) Приход на ВУ НИ1 
	{ 97	,1	,1	, &DO3213017},	//(A4IS21LDU) Приход на НУ НИ1 
	{ 98	,1	,1	, &DO3213018},	//(A9IS11LDU) Приход на ВУ НИ ДС1
	{ 99	,1	,1	, &DO3213019},	//(A9IS21LDU) Приход на НУ НИ ДС1
	{ 100	,1	,1	, &DO3213020},	//(B9IS11LDU) Приход на ВУ НИ ДС2
	{ 101	,1	,1	, &DO3213021},	//(B9IS21LDU) Приход на НУ НИ ДС2
	{ 102	,1	,1	, &DO3213022},	//(R1IS11LDU) Приход на ВУ МДЗ1
	{ 103	,1	,1	, &DO3213023},	//(R1IS21LDU) Приход на НУ МДЗ1
	{ 104	,1	,1	, &DO3213024},	//(R2IS11LDU) Приход на ВУ МДЗ2
	{ 105	,1	,1	, &DO3213025},	//(R2IS21LDU) Приход на НУ МДЗ2
	{ 106	,1	,1	, &DO3213026},	//(A3IS35LDU) Клапан «ВПИС1» открыт (обесточен)
	{ 107	,1	,1	, &DO3213027},	//(A3IS33LDU) Клапан «ВЫСТРЕЛ ИС1» открыт (обесточен)
	{ 108	,1	,1	, &DO3213028},	//(A2IS33LDU) Клапан «Подъём РБ1» открыт (обесточен)
	{ 109	,1	,1	, &DO3213029},	//(A4IS10LDU) Клапан «Подъём НИ1» открыт (обесточен)
	{ 110	,1	,1	, &DO3213030},	//(A3IS31LDU) Клапан «СПУСК ИС1» открыт (обесточен)
	{ 111	,1	,1	, &DO3213031},	//(A7AS31LDU) Клапан «Обдув АЗ1» открыт (обесточен)
	{ 112	,1	,1	, &DO3213032},	//(A1IS12LDU) Магнит ББ1 зацеплен
	{ 113	,1	,1	, &DO3214001},	//(A1IS11LDU) Приход на ВУ ББ1
	{ 114	,1	,1	, &DO3214002},	//(A1IS21LDU) Приход на НУ ББ1
	{ 115	,1	,1	, &DO3214003},	//(A2IS12LDU) Магнит РБ1 зацеплен
	{ 116	,1	,1	, &DO3214004},	//(A2IS11LDU) Приход на ВУ РБ1-СТР
	{ 117	,1	,1	, &DO3214005},	//(A2IS21LDU) Приход на НУ РБ1-СС
	{ 118	,1	,1	, &DO3214006},	//(A3IS21LDU) Приход на НУ ИС1
	{ 119	,1	,1	, &DO3214007},	//(B4IS11LDU) Приход на ВУ НИ2
	{ 120	,1	,1	, &DO3214008},	//(B4IS21LDU) Приход на НУ НИ2
	{ 121	,1	,1	, &DO3214009},	//(B8IS12LDU) Приход на механический ВУ АЗ2
	{ 122	,1	,1	, &DO3214010},	//()
	{ 123	,1	,1	, &DO3214011},	//(A3VP81LDU) Давление СПУСК ИС1 в норме
	{ 124	,1	,1	, &DO3214012},	//(A2VP82LDU) Давление ПОДЪЁМ РБ1 в норме
	{ 125	,1	,1	, &DO3214013},	//(A4VP82LDU) Давление ПОДЪЁМ НИ1 в норме
	{ 126	,1	,1	, &DO3214014},	//(B3VP81LDU) Давление СПУСК ИС2 в норме
	{ 127	,1	,1	, &DO3214015},	//(B2VP82LDU) Давление ПОДЪЁМ РБ2 в норме
	{ 128	,1	,1	, &DO3214016},	//(B4VP82LDU) Давление ПОДЪЁМ НИ2 в норме
	{ 129	,1	,1	, &DO3214017},	//(R0IS02LDU) Разрешение ввода от имитатора
	{ 130	,1	,1	, &DO3214018},	//(A3IS11LDU) Приход на ВУ ИС1
	{ 131	,1	,1	, &DO3214019},	//(A3IS22LDU) Приход на НУП ИС1
	{ 132	,1	,1	, &DO3214020},	//(B3IS11LDU) Приход на ВУ ИС2
	{ 133	,1	,1	, &DO3214021},	//(B3IS22LDU) Приход на НУП ИС2
	{ 134	,1	,1	, &DO3214022},	//(R4IS11LDU) Приход на ВУ тележки
	{ 135	,1	,1	, &DO3214023},	//(R4IS12LDU) Приход на механический ВУ тележки
	{ 136	,1	,1	, &DO3214024},	//(R4IS21LDU) Приход на НУ тележки
	{ 137	,1	,1	, &DO3214025},	//(R4IS22LDU) Приход на механический НУ тележки
	{ 138	,1	,1	, &DO3214026},	//()
	{ 139	,1	,1	, &DO3214027},	//(A6IS21LDU) Приход на НУ БЗ1
	{ 140	,1	,1	, &DO3214028},	//(A5IS11LDU) Приход на ВУ НЛ1
	{ 141	,1	,1	, &DO3214029},	//(A5IS21LDU) Приход на НУ НЛ1
	{ 142	,1	,1	, &DO3214030},	//(B6IS11LDU) Приход на ВУ БЗ2
	{ 143	,1	,1	, &DO3214031},	//(B6IS21LDU) Приход на НУ БЗ2
	{ 144	,1	,1	, &DO3214032},	//(B5IS11LDU) Приход на ВУ НЛ2
	{ 145	,1	,1	, &DO3215001},	//(B5IS21LDU) Приход на НУ НЛ2
	{ 146	,1	,1	, &DO3215002},	//(R3IS11LDU) Приход на ВУ гомогенных дверей-1
	{ 147	,1	,1	, &DO3215003},	//(R3IS21LDU) Приход на НУ гомогенных дверей-1
	{ 148	,1	,1	, &DO3215004},	//(R3IS31LDU) Приход на ВУ гомогенных дверей-2
	{ 149	,1	,1	, &DO3215005},	//(R3IS41LDU) Приход на НУ гомогенных дверей-2
	{ 150	,1	,1	, &DO3215006},	//(R3AD10LDU) Гомогенные двери-1 открыть
	{ 151	,1	,1	, &DO3215007},	//(R3AD11LDU) Гомогенные двери-2 открыть
	{ 152	,1	,1	, &DO3215008},	//(R3AD20LDU) Гомогенные двери-1 закрыть
	{ 153	,1	,1	, &DO3215009},	//(R3AD21LDU) Гомогенные двери-2 закрыть
	{ 154	,1	,1	, &DO3215010},	//(R5IS11LDU) Приход на ВУ ворот отстойной зоны
	{ 155	,1	,1	, &DO3215011},	//(R5IS21LDU) Приход на НУ ворот отстойной зоны
	{ 156	,1	,1	, &DO3215012},	//(R5AD10LDU) Открыть ворота отстойной зоны
	{ 157	,1	,1	, &DO3215013},	//(R5AD20LDU) Закрыть ворота отстойной зоны
	{ 158	,1	,1	, &DO3215014},	//(R6IS21LDU) Кран-балка в нерабочем положении
	{ 159	,1	,1	, &DO3215015},	//(A8IS12LDU) Приход на механический ВУ ДС2
	{ 160	,1	,1	, &DO3215016},	//(A8IS22LDU) Приход на механический НУ ДС2
	{ 161	,1	,1	, &DO3215017},	//(B8IS22LDU) Приход на механический НУ АЗ2
	{ 162	,1	,1	, &DO3215018},	//(A6IS11LDU) Приход на ВУ БЗ1
	{ 163	,1	,1	, &DO3215019},	//(A2IE02LDU) Исправность ИП РБ1
	{ 164	,1	,1	, &DO3215020},	//(A2IE01LDU) Исправность БУШД РБ1
	{ 165	,1	,1	, &DO3215021},	//(A2IE03LDU) Движение РБ1 вперед (от БУШД)
	{ 166	,1	,1	, &DO3215022},	//(A2IE04LDU) Движение РБ1 назад (от БУШД)
	{ 167	,1	,1	, &DO3215023},	//(A3IE02LDU) Исправность ИП ИС1
	{ 168	,1	,1	, &DO3215024},	//(A3IE01LDU) Исправность БУШД ИС1
	{ 169	,1	,1	, &DO3215025},	//(A3IE03LDU) Движение ИС1 вперед (от БУШД)
	{ 170	,1	,1	, &DO3215026},	//(A3IE04LDU) Движение ИС1 назад (от БУШД)
	{ 171	,1	,1	, &DO3215027},	//(B1IE02LDU) Исправность ИП ББ2
	{ 172	,1	,1	, &DO3215028},	//(B1IE01LDU) Исправность БУШД ББ2
	{ 173	,1	,1	, &DO3215029},	//(B2IE02LDU) Исправность ИП РБ2
	{ 174	,1	,1	, &DO3215030},	//(B2IE01LDU) Исправность БУШД РБ2
	{ 175	,1	,1	, &DO3215031},	//(B2IE03LDU) Движение РБ2 вперед (от БУШД)
	{ 176	,1	,1	, &DO3215032},	//(B2IE04LDU) Движение РБ2 назад (от БУШД)
	{ 177	,1	,1	, &DO3216001},	//(B3IE02LDU) Исправность ИП ИС2
	{ 178	,1	,1	, &DO3216002},	//(B3IE01LDU) Исправность БУШД ИС2
	{ 179	,1	,1	, &DO3216003},	//(B3IE03LDU) Движение ИС2 вперед (от БУШД)
	{ 180	,1	,1	, &DO3216004},	//(B3IE04LDU) Движение ИС2 назад (от БУШД)
	{ 181	,1	,1	, &DO3216005},	//(R6IS61LDU) Исправность 3-х  фазной сети
	{ 182	,1	,1	, &DO3216006},	//(R4VS12LDU) Движение реактора  к «У ОБРАЗЦОВ»
	{ 183	,1	,1	, &DO3216007},	//(R4VS22LDU) Движение реактора к «У ЗАЩИТЫ»
	{ 184	,1	,1	, &DO3216008},	//(A8IE01LDU) Исправность ИП ДС2
	{ 185	,1	,1	, &DO3216009},	//(R1VS12LDU) Движение МДЗ1 в сторону ВУ
	{ 186	,1	,1	, &DO3216010},	//(R1VS22LDU) Движение МДЗ1 в сторону НУ
	{ 187	,1	,1	, &DO3216011},	//(R1IE01LDU) Исправность ИП МДЗ1
	{ 188	,1	,1	, &DO3216012},	//(R2VS12LDU) Движение МДЗ2 в сторону ВУ
	{ 189	,1	,1	, &DO3216013},	//(R2VS22LDU) Движение МДЗ2 в сторону НУ
	{ 190	,1	,1	, &DO3216014},	//(R2IE01LDU) Исправность ИП МДЗ2
	{ 191	,1	,1	, &DO3216015},	//(A5VS12LDU) Движение НЛ1 в сторону ВУ
	{ 192	,1	,1	, &DO3216016},	//(A5VS22LDU) Движение НЛ1 в сторону НУ
	{ 193	,1	,1	, &DO3216017},	//(A5IE02LDU) Исправность ИП НЛ1
	{ 194	,1	,1	, &DO3216018},	//(B5VS12LDU) Движение НЛ2 в сторону ВУ
	{ 195	,1	,1	, &DO3216019},	//(B5VS22LDU) Движение НЛ2 в сторону НУ
	{ 196	,1	,1	, &DO3216020},	//(B5IE01LDU) Исправность ИП НЛ2
	{ 197	,1	,1	, &DO3216021},	//(A6VS12LDU) Движение створок БЗ1  к  «ОТКРЫТА»
	{ 198	,1	,1	, &DO3216022},	//(A6VS22LDU) Движение створок БЗ1  к «ЗАКРЫТА»
	{ 199	,1	,1	, &DO3216023},	//(A6IE01LDU) Исправность ИП БЗ1
	{ 200	,1	,1	, &DO3216024},	//(B6VS12LDU) Движение створок БЗ2  к  «ОТКРЫТА»
	{ 201	,1	,1	, &DO3216025},	//(B6VS22LDU) Движение створок БЗ2  к «ЗАКРЫТА»
	{ 202	,1	,1	, &DO3216026},	//(B6IE01LDU) Исправность ИП БЗ2
	{ 203	,1	,1	, &DO3216027},	//(R0IE02LDU) Исправность ИП 24 В-1
	{ 204	,1	,1	, &DO3216028},	//(R0IE01LDU) Исправность ИП 24 В-2
	{ 205	,1	,1	, &DO3216029},	//(R6IS62LDU) Исправность ВИП ССДИ-39 1канал
	{ 206	,1	,1	, &DO3216030},	//(R6IS63LDU) Исправность ВИП ССДИ-39 2канал
	{ 207	,1	,1	, &DO3216031},	//(R6IS64LDU) Исправность ВИП ССДИ-35 1канал
	{ 208	,1	,1	, &DO3216032},	//(R6IS65LDU) Исправность ВИП ССДИ-35 2канал
	{ 209	,1	,1	, &DO3212001},	//!!!(DO3212001) ENCODER?
	{ 210	,1	,1	, &DO3212002},	//!!!(DO3212002) ENCODER?
	{ 211	,1	,1	, &DO3212003},	//!!!(DO3212003) ENCODER?
	{ 212	,1	,1	, &DO3212004},	//!!!(DO3212004) ENCODER?
	{ 213	,1	,1	, &DO3212005},	//!!!(DO3212005) ENCODER?
	{ 214	,1	,1	, &DO3212006},	//!!!(DO3212006) ENCODER?
	{ 215	,1	,1	, &DO3212007},	//!!!(DO3212007) ENCODER?
	{ 216	,1	,1	, &DO3212008},	//!!!(DO3212008) ENCODER?
	{ 217	,1	,1	, &DO3212009},	//!!!(DO3212009) ENCODER?
	{ 218	,1	,1	, &DO3212010},	//!!!(DO3212010) ENCODER?
	{ 219	,1	,1	, &DO3212011},	//!!!(DO3212011) ENCODER?
	{ 220	,1	,1	, &DO3212012},	//!!!(DO3212012) ENCODER?
	{ 221	,1	,1	, &DO3212013},	//!!!(DO3212013) ENCODER?
	{ 222	,1	,1	, &DO3212014},	//!!!(DO3212014) ENCODER?
	{ 223	,1	,1	, &DO3212015},	//!!!(DO3212015) ENCODER?
	{ 224	,1	,1	, &DO3212016},	//!!!(DO3212016) ENCODER?
	{ 225	,1	,1	, &DO3212017},	//!!!(DO3212017) ENCODER?
	{ 226	,1	,1	, &DO3212018},	//!!!(DO3212018) ENCODER?
	{ 227	,1	,1	, &DO3212019},	//!!!(DO3212019) ENCODER?
	{ 228	,1	,1	, &DO3212020},	//!!!(DO3212020) ENCODER?
	{ 229	,1	,1	, &DO3212021},	//!!!(DO3212021) ENCODER?
	{ 230	,1	,1	, &DO3212022},	//!!!(DO3212022) ENCODER?
	{ 231	,1	,1	, &DO3212023},	//!!!(DO3212023) ENCODER?
	{ 232	,1	,1	, &DO3212024},	//!!!(DO3212024) ENCODER?
	{ 233	,1	,1	, &DO3212025},	//!!!(DO3212025) ENCODER?
	{ 234	,1	,1	, &DO3212026},	//!!!(DO3212026) ENCODER?
	{ 235	,1	,1	, &DO3212027},	//!!!(DO3212027) ENCODER?
	{ 236	,1	,1	, &DO3212028},	//!!!(DO3212028) ENCODER?
	{ 237	,1	,1	, &DO3212029},	//!!!(DO3212029) ENCODER?
	{ 238	,1	,1	, &DO3212030},	//!!!(DO3212030) ENCODER?
	{ 239	,1	,1	, &DO3212031},	//!!!(DO3212031) ENCODER?
	{ 240	,1	,1	, &DO3212032},	//!!!(DO3212032) ENCODER?
	{ 241	,1	,1	, &VDSR34001},	//(A1IC01LDU) BUS1_ББ1
	{ 242	,1	,1	, &VDSR34002},	//(B1IC01LDU) BUS2_ББ2
	{ 243	,1	,1	, &VDSR34003},	//(A2IC01LDU) BUS3_РБ1
	{ 244	,1	,1	, &VDSR34004},	//(B2IC01LDU) BUS4_РБ2
	{ 245	,1	,1	, &VDSR34005},	//(A3IC01LDU) BUS5_ИС1
	{ 246	,1	,1	, &VDSR34006},	//(B3IC01LDU) BUS6_ИС2
	{ 247	,1	,1	, &VDSR34007},	//(B8IC01LDU) BUS7_АЗ2
	{ 248	,1	,1	, &VDSR34008},	//(A8IC01LDU) BUS8_ДС2
	{ 249	,1	,1	, &VDSR34009},	//(R0IC41LDU) LUTCH
	{ 250	,1	,1	, &VDSR34010},	//(R0IC42LDU) Вход запрета
	{ 251	,1	,1	, &VDSR34011},	//(R0IC43LDU) Выход запрета
	{ 252	,1	,1	, &VDSR34012},	//(A3AD34LDU) Клапан ВПИС1  открыть (обесточить)
	{ 253	,1	,1	, &VDSR34013},	//(A3AD33LDU) Клапан «ВЫСТРЕЛ ИС1» открыть (обесточить)
	{ 254	,1	,1	, &VDSR34014},	//(A2AD33LDU) Клапан «Подъем РБ1» открыть
	{ 255	,1	,1	, &VDSR34015},	//(A4AD10LDU) Открыть клапан Подъем НИ1
	{ 256	,1	,1	, &VDSR34016},	//(A3AD31LDU) Клапан «СПУСК ИС1» открыть (обесточить)
	{ 257	,1	,1	, &VDSR34017},	//(A7AP31LDU) Клапан «Обдув АЗ1» открыть (обесточить)
	{ 258	,1	,1	, &VDSR34018},	//(R1AD10LDU) Опустить МДЗ1 в зону облучения
	{ 259	,1	,1	, &VDSR34019},	//(R1AD20LDU) Поднять МДЗ1
	{ 260	,1	,1	, &VDSR34020},	//(R2AD10LDU) Опустить МДЗ2 в зону облучения
	{ 261	,1	,1	, &VDSR34021},	//(R2AD20LDU) Поднять МДЗ2
	{ 262	,1	,1	, &VDSR34022},	//(A5AD10LDU) Поднять НЛ1
	{ 263	,1	,1	, &VDSR34023},	//(A5AD20LDU) Опустить НЛ1
	{ 264	,1	,1	, &VDSR34024},	//(B5AD10LDU) Поднять НЛ2
	{ 265	,1	,1	, &VDSR34025},	//(B5AD20LDU) Опустить НЛ2
	{ 266	,1	,1	, &VDSR34026},	//(B3AD34LDU) Клапан ВПИС ИС2  открыть (обесточить)
	{ 267	,1	,1	, &VDSR34027},	//(B3AD33LDU) Клапан «ВЫСТРЕЛ ИС2» закрыть (обесточить)
	{ 268	,1	,1	, &VDSR34028},	//(B2AD33LDU) Клапан «Подъем РБ2» открыть
	{ 269	,1	,1	, &VDSR34029},	//(B4AD10LDU) Открыть клапан Подъем НИ2
	{ 270	,1	,1	, &VDSR34030},	//(B3AD31LDU) Клапан «СПУСК ИС2» открыть (обесточить)
	{ 271	,1	,1	, &VDSR34031},	//(B7AP31LDU) Клапан «Обдув АЗ2» открыть (обесточить)
	{ 272	,1	,1	, &VDSR34032},	//(A8AD10LDU) Перемещение ДС2 вперед
	{ 273	,1	,1	, &VDSR36001},	//(A8AD20LDU) Перемещение ДС2 назад
	{ 274	,1	,1	, &VDSR36002},	//(A6AD10LDU) Открыть БЗ1
	{ 275	,1	,1	, &VDSR36003},	//(A6AD20LDU) Закрыть БЗ1
	{ 276	,1	,1	, &VDSR36004},	//(B6AD10LDU) Открыть БЗ2
	{ 277	,1	,1	, &VDSR36005},	//(B6AD20LDU) Закрыть БЗ2
	{ 278	,1	,1	, &VDSR36006},	//(R4AD10LDU) Перемещение тележки вперед
	{ 279	,1	,1	, &VDSR36007},	//(R4AD20LDU) Перемещение тележки назад
	{ 280	,1	,1	, &VDSR36008},	//(B8AD10LDU) Перемещение АЗ2 вперед
	{ 281	,1	,1	, &VDSR36009},	//(B8AD20LDU) Перемещение АЗ2 назад
	{ 282	,1	,1	, &VDSR36010},	//(A3AD11LDU) Сигнал на перемещение ИС1 вверх
	{ 283	,1	,1	, &VDSR36011},	//(A3AD21LDU) Сигнал на перемещение ИС1 вниз
	{ 284	,1	,1	, &VDSR36012},	//(A3AD01LDU) Разрешение движения ИС1
	{ 285	,1	,1	, &VDSR36013},	//(A3AD02LDU) 0-й бит скорости ИС1
	{ 286	,1	,1	, &VDSR36014},	//(A3AD03LDU) 1-й бит скорости ИС1
	{ 287	,1	,1	, &VDSR36015},	//(A3AD04LDU) 2-й бит скорости ИС1
	{ 288	,1	,1	, &VDSR36016},	//(A3AD05LDU) паритет команды на ИС1
	{ 289	,1	,1	, &VDSR36017},	//(B3AD11LDU) Сигнал на перемещение ИС2 вверх
	{ 290	,1	,1	, &VDSR36018},	//(B3AD21LDU) Сигнал на перемещение ИС2 вниз
	{ 291	,1	,1	, &VDSR36019},	//(B3AD01LDU) Разрешение движения ИС2
	{ 292	,1	,1	, &VDSR36020},	//(B3AD02LDU) 0-й бит скорости ИС2
	{ 293	,1	,1	, &VDSR36021},	//(B3AD03LDU) 1-й бит скорости ИС2
	{ 294	,1	,1	, &VDSR36022},	//(B3AD04LDU) 2-й бит скорости ИС2
	{ 295	,1	,1	, &VDSR36023},	//(B3AD05LDU) паритет команды на ИС2
	{ 296	,1	,1	, &VDSR36024},	//(A9AD10LDU) Открыть клапан Подъем НИ ДС1
	{ 297	,1	,1	, &VDSR36025},	//(B9AD10LDU) Открыть клапан Подъем НИ ДС2
	{ 298	,1	,1	, &VDSR36026},	//(A1AD11LDU) Сигнал на перемещение ББ1 вверх
	{ 299	,1	,1	, &VDSR36027},	//(A1AD21LDU) Сигнал на перемещение ББ1 вниз
	{ 300	,1	,1	, &VDSR36028},	//(A1AD01LDU) Разрешение движения ББ1
	{ 301	,1	,1	, &VDSR36029},	//(A1AD02LDU) 0-й бит скорости ББ1
	{ 302	,1	,1	, &VDSR36030},	//(A1AD03LDU) 1-й бит скорости ББ1
	{ 303	,1	,1	, &VDSR36031},	//(A1AD04LDU) 2-й бит скорости ББ1
	{ 304	,1	,1	, &VDSR36032},	//!!!(DO3211032) не занята
	{ 305	,1	,1	, &VDSR31001},	//(A1AD05LDU) паритет команды на ББ1
	{ 306	,1	,1	, &VDSR31002},	//(B1AD11LDU) Сигнал на перемещение ББ2 вверх
	{ 307	,1	,1	, &VDSR31003},	//(B1AD21LDU) Сигнал на перемещение ББ2 вниз
	{ 308	,1	,1	, &VDSR31004},	//(B1AD01LDU) Разрешение движения ББ2
	{ 309	,1	,1	, &VDSR31005},	//(B1AD02LDU) 0-й бит скорости ББ2
	{ 310	,1	,1	, &VDSR31006},	//(B1AD03LDU) 1-й бит скорости ББ2
	{ 311	,1	,1	, &VDSR31007},	//(B1AD04LDU) 2-й бит скорости ББ2
	{ 312	,1	,1	, &VDSR31008},	//(B1AD05LDU) паритет команды на ББ2
	{ 313	,1	,1	, &VDSR31009},	//(A2AD11LDU) Сигнал на перемещение РБ1 вверх
	{ 314	,1	,1	, &VDSR31010},	//(A2AD21LDU) Сигнал на перемещение РБ1 вниз
	{ 315	,1	,1	, &VDSR31011},	//(A2AD01LDU) Разрешение движения РБ1
	{ 316	,1	,1	, &VDSR31012},	//(A2AD02LDU) 0-й бит скорости РБ1
	{ 317	,1	,1	, &VDSR31013},	//(A2AD03LDU) 1-й бит скорости РБ1
	{ 318	,1	,1	, &VDSR31014},	//(A2AD04LDU) 2-й бит скорости РБ1
	{ 319	,1	,1	, &VDSR31015},	//(A2AD05LDU) паритет команды на РБ1
	{ 320	,1	,1	, &VDSR31016},	//(B2AD11LDU) Сигнал на перемещение РБ2 вверх
	{ 321	,1	,1	, &VDSR31017},	//(B2AD21LDU) Сигнал на перемещение РБ2 вниз
	{ 322	,1	,1	, &VDSR31018},	//(B2AD01LDU) Разрешение движения РБ2
	{ 323	,1	,1	, &VDSR31019},	//(B2AD02LDU) 0-й бит скорости РБ2
	{ 324	,1	,1	, &VDSR31020},	//(B2AD03LDU) 1-й бит скорости РБ2
	{ 325	,1	,1	, &VDSR31021},	//(B2AD04LDU) 2-й бит скорости РБ2
	{ 326	,1	,1	, &VDSR31022},	//(B2AD05LDU) паритет команды на РБ2
	{ 327	,1	,1	, &VDSR31023},	//(A1AD32LDU) Обесточить ЭМ ББ1
	{ 328	,1	,1	, &VDSR31024},	//(A1AD31LDU) Клапан «Сброс ББ1» открыть (обесточить)
	{ 329	,1	,1	, &VDSR31025},	//(A2AD32LDU) Обесточить ЭМ РБ1
	{ 330	,1	,1	, &VDSR31026},	//(A2AD31LDU) Клапан «Сброс РБ1» открыть (обесточить)
	{ 331	,1	,1	, &VDSR31027},	//(B1AD32LDU) Обесточить ЭМ ББ2
	{ 332	,1	,1	, &VDSR31028},	//(B1AD31LDU) Клапан «Сброс ББ2» открыть (обесточить)
	{ 333	,1	,1	, &VDSR31029},	//(B2AD32LDU) Обесточить ЭМ РБ2
	{ 334	,1	,1	, &VDSR31030},	//(B2AD31LDU) Клапан «Сброс РБ2» открыть (обесточить)
	{ 335	,1	,1	, &VDSR31031},	//(R8AD21LDU) Запуск системы инициирования
	{ 336	,1	,1	, &VDSR31032},	//(R0AD16LDU) Контроль  I-II УР. РАД
	{-1,0,NULL},
};
static char NameSaveFile[]="savecnst.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{0,NULL}
};
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
	{0,502,&coil_msptiSig[0],&di_msptiSig[0],&ir_msptiSig[0],&hr_msptiSig[0],NULL,NULL,NULL,0},	 //Пустые сигналы PTI

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
	{&AO1632001,3,0},
	{&AO1632002,3,6},
	{&AO1632003,3,3},
	{&AO1632004,3,9},
	{&AO1632005,3,12},
	{&AO1632006,3,18},
	{&AO1632007,3,15},
	{&AO1632008,3,21},
	{&AO1632009,3,24},
	{&AO1632010,3,27},
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
	{&DO3210001,1,0},
	{&DO3210002,1,2},
	{&DO3210003,1,4},
	{&DO3210004,1,6},
	{&DO3210005,1,8},
	{&DO3210006,1,10},
	{&DO3210007,1,12},
	{&DO3210008,1,14},
	{&DO3210009,1,16},
	{&DO3210010,1,18},
	{&DO3210011,1,20},
	{&DO3210012,1,22},
	{&DO3210013,1,24},
	{&DO3210014,1,26},
	{&DO3210015,1,28},
	{&DO3210016,1,30},
	{&DO3210017,1,32},
	{&DO3210018,1,34},
	{&DO3210019,1,36},
	{&DO3210020,1,38},
	{&DO3210021,1,40},
	{&DO3210022,1,42},
	{&DO3210023,1,44},
	{&DO3210024,1,46},
	{&DO3210025,1,48},
	{&DO3210026,1,50},
	{&DO3210027,1,52},
	{&DO3210028,1,54},
	{&DO3210029,1,56},
	{&DO3210030,1,58},
	{&DO3210031,1,60},
	{&DO3210032,1,62},
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
	{&DO3211001,1,0},
	{&DO3211002,1,2},
	{&DO3211003,1,4},
	{&DO3211004,1,6},
	{&DO3211005,1,8},
	{&DO3211006,1,10},
	{&DO3211007,1,12},
	{&DO3211008,1,14},
	{&DO3211009,1,16},
	{&DO3211010,1,18},
	{&DO3211011,1,20},
	{&DO3211012,1,22},
	{&DO3211013,1,24},
	{&DO3211014,1,26},
	{&DO3211015,1,28},
	{&DO3211016,1,30},
	{&DO3211017,1,32},
	{&DO3211018,1,34},
	{&DO3211019,1,36},
	{&DO3211020,1,38},
	{&DO3211021,1,40},
	{&DO3211022,1,42},
	{&DO3211023,1,44},
	{&DO3211024,1,46},
	{&DO3211025,1,48},
	{&DO3211026,1,50},
	{&DO3211027,1,52},
	{&DO3211028,1,54},
	{&DO3211029,1,56},
	{&DO3211030,1,58},
	{&DO3211031,1,60},
	{&DO3211032,1,62},
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
	{&DO3213001,1,0},
	{&DO3213002,1,2},
	{&DO3213003,1,4},
	{&DO3213004,1,6},
	{&DO3213005,1,8},
	{&DO3213006,1,10},
	{&DO3213007,1,12},
	{&DO3213008,1,14},
	{&DO3213009,1,16},
	{&DO3213010,1,18},
	{&DO3213011,1,20},
	{&DO3213012,1,22},
	{&DO3213013,1,24},
	{&DO3213014,1,26},
	{&DO3213015,1,28},
	{&DO3213016,1,30},
	{&DO3213017,1,32},
	{&DO3213018,1,34},
	{&DO3213019,1,36},
	{&DO3213020,1,38},
	{&DO3213021,1,40},
	{&DO3213022,1,42},
	{&DO3213023,1,44},
	{&DO3213024,1,46},
	{&DO3213025,1,48},
	{&DO3213026,1,50},
	{&DO3213027,1,52},
	{&DO3213028,1,54},
	{&DO3213029,1,56},
	{&DO3213030,1,58},
	{&DO3213031,1,60},
	{&DO3213032,1,62},
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
	{&DO3214001,1,0},
	{&DO3214002,1,2},
	{&DO3214003,1,4},
	{&DO3214004,1,6},
	{&DO3214005,1,8},
	{&DO3214006,1,10},
	{&DO3214007,1,12},
	{&DO3214008,1,14},
	{&DO3214009,1,16},
	{&DO3214010,1,18},
	{&DO3214011,1,20},
	{&DO3214012,1,22},
	{&DO3214013,1,24},
	{&DO3214014,1,26},
	{&DO3214015,1,28},
	{&DO3214016,1,30},
	{&DO3214017,1,32},
	{&DO3214018,1,34},
	{&DO3214019,1,36},
	{&DO3214020,1,38},
	{&DO3214021,1,40},
	{&DO3214022,1,42},
	{&DO3214023,1,44},
	{&DO3214024,1,46},
	{&DO3214025,1,48},
	{&DO3214026,1,50},
	{&DO3214027,1,52},
	{&DO3214028,1,54},
	{&DO3214029,1,56},
	{&DO3214030,1,58},
	{&DO3214031,1,60},
	{&DO3214032,1,62},
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
	{&DO3215001,1,0},
	{&DO3215002,1,2},
	{&DO3215003,1,4},
	{&DO3215004,1,6},
	{&DO3215005,1,8},
	{&DO3215006,1,10},
	{&DO3215007,1,12},
	{&DO3215008,1,14},
	{&DO3215009,1,16},
	{&DO3215010,1,18},
	{&DO3215011,1,20},
	{&DO3215012,1,22},
	{&DO3215013,1,24},
	{&DO3215014,1,26},
	{&DO3215015,1,28},
	{&DO3215016,1,30},
	{&DO3215017,1,32},
	{&DO3215018,1,34},
	{&DO3215019,1,36},
	{&DO3215020,1,38},
	{&DO3215021,1,40},
	{&DO3215022,1,42},
	{&DO3215023,1,44},
	{&DO3215024,1,46},
	{&DO3215025,1,48},
	{&DO3215026,1,50},
	{&DO3215027,1,52},
	{&DO3215028,1,54},
	{&DO3215029,1,56},
	{&DO3215030,1,58},
	{&DO3215031,1,60},
	{&DO3215032,1,62},
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
	{&DO3216001,1,0},
	{&DO3216002,1,2},
	{&DO3216003,1,4},
	{&DO3216004,1,6},
	{&DO3216005,1,8},
	{&DO3216006,1,10},
	{&DO3216007,1,12},
	{&DO3216008,1,14},
	{&DO3216009,1,16},
	{&DO3216010,1,18},
	{&DO3216011,1,20},
	{&DO3216012,1,22},
	{&DO3216013,1,24},
	{&DO3216014,1,26},
	{&DO3216015,1,28},
	{&DO3216016,1,30},
	{&DO3216017,1,32},
	{&DO3216018,1,34},
	{&DO3216019,1,36},
	{&DO3216020,1,38},
	{&DO3216021,1,40},
	{&DO3216022,1,42},
	{&DO3216023,1,44},
	{&DO3216024,1,46},
	{&DO3216025,1,48},
	{&DO3216026,1,50},
	{&DO3216027,1,52},
	{&DO3216028,1,54},
	{&DO3216029,1,56},
	{&DO3216030,1,58},
	{&DO3216031,1,60},
	{&DO3216032,1,62},
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
	{&DO3212001,1,0},
	{&DO3212002,1,2},
	{&DO3212003,1,4},
	{&DO3212004,1,6},
	{&DO3212005,1,8},
	{&DO3212006,1,10},
	{&DO3212007,1,12},
	{&DO3212008,1,14},
	{&DO3212009,1,16},
	{&DO3212010,1,18},
	{&DO3212011,1,20},
	{&DO3212012,1,22},
	{&DO3212013,1,24},
	{&DO3212014,1,26},
	{&DO3212015,1,28},
	{&DO3212016,1,30},
	{&DO3212017,1,32},
	{&DO3212018,1,34},
	{&DO3212019,1,36},
	{&DO3212020,1,38},
	{&DO3212021,1,40},
	{&DO3212022,1,42},
	{&DO3212023,1,44},
	{&DO3212024,1,46},
	{&DO3212025,1,48},
	{&DO3212026,1,50},
	{&DO3212027,1,52},
	{&DO3212028,1,54},
	{&DO3212029,1,56},
	{&DO3212030,1,58},
	{&DO3212031,1,60},
	{&DO3212032,1,62},
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
	{&VDSR34001,1,0},
	{&VDSR34002,1,2},
	{&VDSR34003,1,4},
	{&VDSR34004,1,6},
	{&VDSR34005,1,8},
	{&VDSR34006,1,10},
	{&VDSR34007,1,12},
	{&VDSR34008,1,14},
	{&VDSR34009,1,16},
	{&VDSR34010,1,18},
	{&VDSR34011,1,20},
	{&VDSR34012,1,22},
	{&VDSR34013,1,24},
	{&VDSR34014,1,26},
	{&VDSR34015,1,28},
	{&VDSR34016,1,30},
	{&VDSR34017,1,32},
	{&VDSR34018,1,34},
	{&VDSR34019,1,36},
	{&VDSR34020,1,38},
	{&VDSR34021,1,40},
	{&VDSR34022,1,42},
	{&VDSR34023,1,44},
	{&VDSR34024,1,46},
	{&VDSR34025,1,48},
	{&VDSR34026,1,50},
	{&VDSR34027,1,52},
	{&VDSR34028,1,54},
	{&VDSR34029,1,56},
	{&VDSR34030,1,58},
	{&VDSR34031,1,60},
	{&VDSR34032,1,62},
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
	{&VDSR36001,1,0},
	{&VDSR36002,1,2},
	{&VDSR36003,1,4},
	{&VDSR36004,1,6},
	{&VDSR36005,1,8},
	{&VDSR36006,1,10},
	{&VDSR36007,1,12},
	{&VDSR36008,1,14},
	{&VDSR36009,1,16},
	{&VDSR36010,1,18},
	{&VDSR36011,1,20},
	{&VDSR36012,1,22},
	{&VDSR36013,1,24},
	{&VDSR36014,1,26},
	{&VDSR36015,1,28},
	{&VDSR36016,1,30},
	{&VDSR36017,1,32},
	{&VDSR36018,1,34},
	{&VDSR36019,1,36},
	{&VDSR36020,1,38},
	{&VDSR36021,1,40},
	{&VDSR36022,1,42},
	{&VDSR36023,1,44},
	{&VDSR36024,1,46},
	{&VDSR36025,1,48},
	{&VDSR36026,1,50},
	{&VDSR36027,1,52},
	{&VDSR36028,1,54},
	{&VDSR36029,1,56},
	{&VDSR36030,1,58},
	{&VDSR36031,1,60},
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
	{&VDSR31001,1,0},
	{&VDSR31002,1,2},
	{&VDSR31003,1,4},
	{&VDSR31004,1,6},
	{&VDSR31005,1,8},
	{&VDSR31006,1,10},
	{&VDSR31007,1,12},
	{&VDSR31008,1,14},
	{&VDSR31009,1,16},
	{&VDSR31010,1,18},
	{&VDSR31011,1,20},
	{&VDSR31012,1,22},
	{&VDSR31013,1,24},
	{&VDSR31014,1,26},
	{&VDSR31015,1,28},
	{&VDSR31016,1,30},
	{&VDSR31017,1,32},
	{&VDSR31018,1,34},
	{&VDSR31019,1,36},
	{&VDSR31020,1,38},
	{&VDSR31021,1,40},
	{&VDSR31022,1,42},
	{&VDSR31023,1,44},
	{&VDSR31024,1,46},
	{&VDSR31025,1,48},
	{&VDSR31026,1,50},
	{&VDSR31027,1,52},
	{&VDSR31028,1,54},
	{&VDSR31029,1,56},
	{&VDSR31030,1,58},
	{&VDSR31031,1,60},
	{&VDSR31032,1,62},
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
