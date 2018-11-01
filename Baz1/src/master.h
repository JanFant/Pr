#ifndef BAZ1_H
#define BAZ1_H
// Подсистема Baz1:Baz1
static char SimulOn=0;
static short CodeSub=5;
static char SimulIP[]="192.168.1.17\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 596
static char BUFFER[596];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.52\0", 5432, "192.168.10.152\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0EE02LDU	 BUFFER[0]	//(R0EE02LDU) Питание  АКНП  отключить
#define idR0EE02LDU	 1	//(R0EE02LDU) Питание  АКНП  отключить
#define R0VZ05UZ1	 BUFFER[2]	//(R0VZ05UZ1) Индикатор причины сброса
#define idR0VZ05UZ1	 2	//(R0VZ05UZ1) Индикатор причины сброса
#define R0VN11RZ1	 BUFFER[7]	//(R0VN11RZ1) Средняя мощность по БАЗ1
#define idR0VN11RZ1	 3	//(R0VN11RZ1) Средняя мощность по БАЗ1
#define R0VP73LZ1	 BUFFER[12]	//(R0VP73LZ1) ПС давления для РУ
#define idR0VP73LZ1	 4	//(R0VP73LZ1) ПС давления для РУ
#define B0CT01IZ1	 BUFFER[14]	//(B0CT01IZ1) Температура АЗ2-1
#define idB0CT01IZ1	 5	//(B0CT01IZ1) Температура АЗ2-1
#define B0VT61LZ1	 BUFFER[19]	//(B0VT61LZ1) ПС по температуре в АЗ2
#define idB0VT61LZ1	 6	//(B0VT61LZ1) ПС по температуре в АЗ2
#define B0VT71LZ1	 BUFFER[21]	//(B0VT71LZ1) АС по температуре в АЗ2
#define idB0VT71LZ1	 7	//(B0VT71LZ1) АС по температуре в АЗ2
#define A0VN71LS1	 BUFFER[23]	//(A0VN71LS1) Блокировка автоматического подъёма ББ канал 1
#define idA0VN71LS1	 8	//(A0VN71LS1) Блокировка автоматического подъёма ББ канал 1
#define A0VN71LS2	 BUFFER[25]	//(A0VN71LS2) Блокировка автоматического подъёма ББ канал 2
#define idA0VN71LS2	 9	//(A0VN71LS2) Блокировка автоматического подъёма ББ канал 2
#define A0VN71LS3	 BUFFER[27]	//(A0VN71LS3) Блокировка автоматического подъёма ББ канал 3
#define idA0VN71LS3	 10	//(A0VN71LS3) Блокировка автоматического подъёма ББ канал 3
#define A0VN71LS4	 BUFFER[29]	//(A0VN71LS4) Блокировка автоматического подъёма ББ канал 4
#define idA0VN71LS4	 11	//(A0VN71LS4) Блокировка автоматического подъёма ББ канал 4
#define A1VN71LZ1	 BUFFER[31]	//(A1VN71LZ1) Блокировка автоматического подъёма ББ
#define idA1VN71LZ1	 12	//(A1VN71LZ1) Блокировка автоматического подъёма ББ
#define A3VZ15LZ1	 BUFFER[33]	//(A3VZ15LZ1) Имитация АЗ от НУП ИС
#define idA3VZ15LZ1	 13	//(A3VZ15LZ1) Имитация АЗ от НУП ИС
#define A3VZ13LZ1	 BUFFER[35]	//(A3VZ13LZ1) Имитация АЗ от ВУ ИС
#define idA3VZ13LZ1	 14	//(A3VZ13LZ1) Имитация АЗ от ВУ ИС
#define R0VW13LDU	 BUFFER[37]	//(R0VW13LDU) Индикация выбора АЗ1 или АЗ1+АЗ2
#define idR0VW13LDU	 15	//(R0VW13LDU) Индикация выбора АЗ1 или АЗ1+АЗ2
#define R0VW23LDU	 BUFFER[39]	//(R0VW23LDU) Индикация выбора АЗ2 или АЗ1+АЗ2
#define idR0VW23LDU	 16	//(R0VW23LDU) Индикация выбора АЗ2 или АЗ1+АЗ2
#define R7II73LZ1	 BUFFER[41]	//(R7II73LZ1) Сработала АС II УР РАД
#define idR7II73LZ1	 17	//(R7II73LZ1) Сработала АС II УР РАД
#define R7II71LZ1	 BUFFER[43]	//(R7II71LZ1) Сработала АС IУР РАД (датчик 1)
#define idR7II71LZ1	 18	//(R7II71LZ1) Сработала АС IУР РАД (датчик 1)
#define R7II72LZ1	 BUFFER[45]	//(R7II72LZ1) Сработала АС IУР РАД  (датчик 2)
#define idR7II72LZ1	 19	//(R7II72LZ1) Сработала АС IУР РАД  (датчик 2)
#define R0AD14LZ1	 BUFFER[47]	//(R0AD14LZ1) Имитация АЗ от IIУР
#define idR0AD14LZ1	 20	//(R0AD14LZ1) Имитация АЗ от IIУР
#define A0EE01LS1	 BUFFER[49]	//(A0EE01LS1) Исправность АКНП канал 1
#define idA0EE01LS1	 21	//(A0EE01LS1) Исправность АКНП канал 1
#define A0EE01LS4	 BUFFER[51]	//(A0EE01LS4) Исправность АКНП канал 4
#define idA0EE01LS4	 22	//(A0EE01LS4) Исправность АКНП канал 4
#define A0EE01LS3	 BUFFER[53]	//(A0EE01LS3) Исправность АКНП канал 3
#define idA0EE01LS3	 23	//(A0EE01LS3) Исправность АКНП канал 3
#define A0EE01LZ1	 BUFFER[55]	//(A0EE01LZ1) Исправность АКНП1
#define idA0EE01LZ1	 24	//(A0EE01LZ1) Исправность АКНП1
#define A0EE04LZ1	 BUFFER[57]	//(A0EE04LZ1) Исправность АКНП4
#define idA0EE04LZ1	 25	//(A0EE04LZ1) Исправность АКНП4
#define A0EE02LZ1	 BUFFER[59]	//(A0EE02LZ1) Исправность АКНП2
#define idA0EE02LZ1	 26	//(A0EE02LZ1) Исправность АКНП2
#define A0EE03LZ1	 BUFFER[61]	//(A0EE03LZ1) Исправность АКНП3
#define idA0EE03LZ1	 27	//(A0EE03LZ1) Исправность АКНП3
#define A0EE01LS2	 BUFFER[63]	//(A0EE01LS2) Исправность АКНП  канал 2
#define idA0EE01LS2	 28	//(A0EE01LS2) Исправность АКНП  канал 2
#define A0EE05LZ1	 BUFFER[65]	//(A0EE05LZ1) Исправность сети АКНП1
#define idA0EE05LZ1	 29	//(A0EE05LZ1) Исправность сети АКНП1
#define A0EE06LZ1	 BUFFER[67]	//(A0EE06LZ1) Исправность сети АКНП2
#define idA0EE06LZ1	 30	//(A0EE06LZ1) Исправность сети АКНП2
#define A0EE07LZ1	 BUFFER[69]	//(A0EE07LZ1) Исправность сети АКНП3
#define idA0EE07LZ1	 31	//(A0EE07LZ1) Исправность сети АКНП3
#define A0EE08LZ1	 BUFFER[71]	//(A0EE08LZ1) Исправность сети АКНП4
#define idA0EE08LZ1	 32	//(A0EE08LZ1) Исправность сети АКНП4
#define A0VZ71LZ1	 BUFFER[73]	//(A0VZ71LZ1) Обобщенный сигнал АС по АЗ1
#define idA0VZ71LZ1	 33	//(A0VZ71LZ1) Обобщенный сигнал АС по АЗ1
#define A0EE00LZ1	 BUFFER[75]	//(A0EE00LZ1) Исправность АКНП АЗ1
#define idA0EE00LZ1	 34	//(A0EE00LZ1) Исправность АКНП АЗ1
#define B0EE00LZ1	 BUFFER[77]	//(B0EE00LZ1) Исправность АКНП АЗ2
#define idB0EE00LZ1	 35	//(B0EE00LZ1) Исправность АКНП АЗ2
#define B0VZ71LZ1	 BUFFER[79]	//(B0VZ71LZ1) Обобщенный сигнал АС по АЗ2
#define idB0VZ71LZ1	 36	//(B0VZ71LZ1) Обобщенный сигнал АС по АЗ2
#define A0VN71LZ1	 BUFFER[81]	//(A0VN71LZ1) АЗ по АС мощности  АЗ1
#define idA0VN71LZ1	 37	//(A0VN71LZ1) АЗ по АС мощности  АЗ1
#define B0VN71LZ1	 BUFFER[83]	//(B0VN71LZ1) АЗ по АС мощности  АЗ2
#define idB0VN71LZ1	 38	//(B0VN71LZ1) АЗ по АС мощности  АЗ2
#define A0VN81LZ1	 BUFFER[85]	//(A0VN81LZ1) АЗ по АС периода разгона АЗ1
#define idA0VN81LZ1	 39	//(A0VN81LZ1) АЗ по АС периода разгона АЗ1
#define B0VN81LZ1	 BUFFER[87]	//(B0VN81LZ1) АЗ по АС периода разгона АЗ2
#define idB0VN81LZ1	 40	//(B0VN81LZ1) АЗ по АС периода разгона АЗ2
#define R0EE02LZ1	 BUFFER[89]	//(R0EE02LZ1) Питание  АКНП2  отключить
#define idR0EE02LZ1	 41	//(R0EE02LZ1) Питание  АКНП2  отключить
#define R0EE03LZ1	 BUFFER[91]	//(R0EE03LZ1) Питание  АКНП3  отключить
#define idR0EE03LZ1	 42	//(R0EE03LZ1) Питание  АКНП3  отключить
#define R0EE04LZ1	 BUFFER[93]	//(R0EE04LZ1) Питание  АКНП4  отключить
#define idR0EE04LZ1	 43	//(R0EE04LZ1) Питание  АКНП4  отключить
#define R0AD15LZ1	 BUFFER[95]	//(R0AD15LZ1) Имитация АЗ от 1УР (датчик1)
#define idR0AD15LZ1	 44	//(R0AD15LZ1) Имитация АЗ от 1УР (датчик1)
#define R0AD16LZ1	 BUFFER[97]	//(R0AD16LZ1) Имитация АЗ от 1УР (датчик2)
#define idR0AD16LZ1	 45	//(R0AD16LZ1) Имитация АЗ от 1УР (датчик2)
#define R0MW12IP2	 BUFFER[99]	//(R0MW12IP2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define idR0MW12IP2	 46	//(R0MW12IP2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define R0AD13LDU	 BUFFER[102]	//(R0AD13LDU) Имитация прихода на ВУ ИС
#define idR0AD13LDU	 47	//(R0AD13LDU) Имитация прихода на ВУ ИС
#define R0AD15LDU	 BUFFER[104]	//(R0AD15LDU) Имитация ухода с НУП ИС
#define idR0AD15LDU	 48	//(R0AD15LDU) Имитация ухода с НУП ИС
#define A2IS12LDU	 BUFFER[106]	//(A2IS12LDU) Магнит РБ1 зацеплен
#define idA2IS12LDU	 49	//(A2IS12LDU) Магнит РБ1 зацеплен
#define B2IS12LDU	 BUFFER[108]	//(B2IS12LDU) Магнит РБ2 зацеплен
#define idB2IS12LDU	 50	//(B2IS12LDU) Магнит РБ2 зацеплен
#define A3IS11LDU	 BUFFER[110]	//(A3IS11LDU) Приход на ВУ ИС1 для ДУ
#define idA3IS11LDU	 51	//(A3IS11LDU) Приход на ВУ ИС1 для ДУ
#define A3IS22LDU	 BUFFER[112]	//(A3IS22LDU) Приход на НУП ИС1 для ДУ
#define idA3IS22LDU	 52	//(A3IS22LDU) Приход на НУП ИС1 для ДУ
#define A3IS11LZ2	 BUFFER[114]	//(A3IS11LZ2) Приход на ВУ ИС1 для УСБ2
#define idA3IS11LZ2	 53	//(A3IS11LZ2) Приход на ВУ ИС1 для УСБ2
#define A3IS22LZ2	 BUFFER[116]	//(A3IS22LZ2) Приход на НУП ИС1 для УСБ2
#define idA3IS22LZ2	 54	//(A3IS22LZ2) Приход на НУП ИС1 для УСБ2
#define A0VP81LZ2	 BUFFER[118]	//(A0VP81LZ2) Давление  АЗ1 в норме для УСБ2
#define idA0VP81LZ2	 55	//(A0VP81LZ2) Давление  АЗ1 в норме для УСБ2
#define A1VP81LZ2	 BUFFER[120]	//(A1VP81LZ2) Давление СБРОС ББ1 в норме для УСБ2
#define idA1VP81LZ2	 56	//(A1VP81LZ2) Давление СБРОС ББ1 в норме для УСБ2
#define OEBB1Z1	 BUFFER[122]	//(OEBB1Z1) Обесточивание ЭМ ББ1 и ЭПК ББ1
#define idOEBB1Z1	 57	//(OEBB1Z1) Обесточивание ЭМ ББ1 и ЭПК ББ1
#define OEBB2Z1	 BUFFER[124]	//(OEBB2Z1) Обесточивание ЭМ ББ2 и ЭПК ББ2
#define idOEBB2Z1	 58	//(OEBB2Z1) Обесточивание ЭМ ББ2 и ЭПК ББ2
#define OERB2Z1	 BUFFER[126]	//(OERB2Z1) Обесточивание ЭМ РБ2 и ЭПК РБ2
#define idOERB2Z1	 59	//(OERB2Z1) Обесточивание ЭМ РБ2 и ЭПК РБ2
#define OERB1Z1	 BUFFER[128]	//(OERB1Z1) Обесточивание ЭМ РБ1 и ЭПК РБ1
#define idOERB1Z1	 60	//(OERB1Z1) Обесточивание ЭМ РБ1 и ЭПК РБ1
#define R0AD21LDU	 BUFFER[130]	//(R0AD21LDU) Подключить защиту от II УР
#define idR0AD21LDU	 61	//(R0AD21LDU) Подключить защиту от II УР
#define R0AD14LDU	 BUFFER[132]	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 62	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
#define R0MD34LP1	 BUFFER[134]	//(R0MD34LP1) Кнопка (Квитировать)
#define idR0MD34LP1	 63	//(R0MD34LP1) Кнопка (Квитировать)
#define R0AD04LZ1	 BUFFER[136]	//(R0AD04LZ1) Имитация срабатывания верхней АС II УР
#define idR0AD04LZ1	 64	//(R0AD04LZ1) Имитация срабатывания верхней АС II УР
#define R0AD16LDU	 BUFFER[138]	//(R0AD16LDU) Имитация срабатывания верхней АС I УР
#define idR0AD16LDU	 65	//(R0AD16LDU) Имитация срабатывания верхней АС I УР
#define R0EE01LZ1	 BUFFER[140]	//(R0EE01LZ1) Питание  АКНП1  отключить
#define idR0EE01LZ1	 66	//(R0EE01LZ1) Питание  АКНП1  отключить
#define A2IS12LZ1	 BUFFER[142]	//(A2IS12LZ1) Магнит РБ1 зацеплен
#define idA2IS12LZ1	 67	//(A2IS12LZ1) Магнит РБ1 зацеплен
#define B2IS12LZ1	 BUFFER[144]	//(B2IS12LZ1) Магнит РБ2 зацеплен
#define idB2IS12LZ1	 68	//(B2IS12LZ1) Магнит РБ2 зацеплен
#define R6IS66LZ1	 BUFFER[146]	//(R6IS66LZ1) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZ1	 69	//(R6IS66LZ1) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZ1	 BUFFER[148]	//(R6IS67LZ1) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZ1	 70	//(R6IS67LZ1) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZ1	 BUFFER[150]	//(R6IS68LZ1) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZ1	 71	//(R6IS68LZ1) Исправность ВИП 4,0 (№7) ССДИ-2
#define R0VN71LZ1	 BUFFER[152]	//(R0VN71LZ1) АС по мощности канал 1
#define idR0VN71LZ1	 72	//(R0VN71LZ1) АС по мощности канал 1
#define R0VN75LZ1	 BUFFER[154]	//(R0VN75LZ1) АС по периоду разгона канал 1
#define idR0VN75LZ1	 73	//(R0VN75LZ1) АС по периоду разгона канал 1
#define R0VN72LZ1	 BUFFER[156]	//(R0VN72LZ1) АС по мощности канал 2
#define idR0VN72LZ1	 74	//(R0VN72LZ1) АС по мощности канал 2
#define R0VN76LZ1	 BUFFER[158]	//(R0VN76LZ1) АС по периоду разгона канал  2
#define idR0VN76LZ1	 75	//(R0VN76LZ1) АС по периоду разгона канал  2
#define R0VN73LZ1	 BUFFER[160]	//(R0VN73LZ1) АС по мощности канал 3
#define idR0VN73LZ1	 76	//(R0VN73LZ1) АС по мощности канал 3
#define R0VN77LZ1	 BUFFER[162]	//(R0VN77LZ1) АС по периоду разгона канал  3
#define idR0VN77LZ1	 77	//(R0VN77LZ1) АС по периоду разгона канал  3
#define R0VN74LZ1	 BUFFER[164]	//(R0VN74LZ1) АС по мощности канал 4
#define idR0VN74LZ1	 78	//(R0VN74LZ1) АС по мощности канал 4
#define R0VN78LZ1	 BUFFER[166]	//(R0VN78LZ1) АС по периоду разгона канал  4
#define idR0VN78LZ1	 79	//(R0VN78LZ1) АС по периоду разгона канал  4
#define R0VP82LZ1	 BUFFER[168]	//(R0VP82LZ1) Давление  в СИСТЕМЕ - 2 в норме
#define idR0VP82LZ1	 80	//(R0VP82LZ1) Давление  в СИСТЕМЕ - 2 в норме
#define A0VP41LZ1	 BUFFER[170]	//(A0VP41LZ1) Давление АЗ1 ниже АС
#define idA0VP41LZ1	 81	//(A0VP41LZ1) Давление АЗ1 ниже АС
#define B0VP41LZ1	 BUFFER[172]	//(B0VP41LZ1) Давление АЗ2 ниже АС
#define idB0VP41LZ1	 82	//(B0VP41LZ1) Давление АЗ2 ниже АС
#define B0VP81LZ1	 BUFFER[174]	//(B0VP81LZ1) Давление АЗ2 в норме
#define idB0VP81LZ1	 83	//(B0VP81LZ1) Давление АЗ2 в норме
#define A0VP81LZ1	 BUFFER[176]	//(A0VP81LZ1) Давление  АЗ1 в норме
#define idA0VP81LZ1	 84	//(A0VP81LZ1) Давление  АЗ1 в норме
#define R0VP41LZ1	 BUFFER[178]	//(R0VP41LZ1) АС по давлению в СИСТЕМЕ
#define idR0VP41LZ1	 85	//(R0VP41LZ1) АС по давлению в СИСТЕМЕ
#define R0VP81LZ1	 BUFFER[180]	//(R0VP81LZ1) Давление  в СИСТЕМЕ -1 в норме
#define idR0VP81LZ1	 86	//(R0VP81LZ1) Давление  в СИСТЕМЕ -1 в норме
#define R0ET02LZ1	 BUFFER[182]	//(R0ET02LZ1) Признак наличия неисправности по температуре АЗ2
#define idR0ET02LZ1	 87	//(R0ET02LZ1) Признак наличия неисправности по температуре АЗ2
#define B0EP02IZ1	 BUFFER[184]	//(B0EP02IZ1) Индикатор -Давление  АЗ2 ниже АС
#define idB0EP02IZ1	 88	//(B0EP02IZ1) Индикатор -Давление  АЗ2 ниже АС
#define A0EP02IZ1	 BUFFER[187]	//(A0EP02IZ1) Индикатор -Давление  АЗ1 ниже АС
#define idA0EP02IZ1	 89	//(A0EP02IZ1) Индикатор -Давление  АЗ1 ниже АС
#define A0VP71LZ1	 BUFFER[190]	//(A0VP71LZ1) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ1	 90	//(A0VP71LZ1) АЗ по АС любого давления для АЗ1
#define B0VP71LZ1	 BUFFER[192]	//(B0VP71LZ1) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ1	 91	//(B0VP71LZ1) АЗ по АС любого давления для АЗ2
#define R0VN02RS1	 BUFFER[194]	//(R0VN02RS1) Уровень мощности канал 1
#define idR0VN02RS1	 92	//(R0VN02RS1) Уровень мощности канал 1
#define R0VN02RS2	 BUFFER[199]	//(R0VN02RS2) Уровень мощности канал 2
#define idR0VN02RS2	 93	//(R0VN02RS2) Уровень мощности канал 2
#define R0VN02RS3	 BUFFER[204]	//(R0VN02RS3) Уровень мощности канал 3
#define idR0VN02RS3	 94	//(R0VN02RS3) Уровень мощности канал 3
#define R0VN02RS4	 BUFFER[209]	//(R0VN02RS4) Уровень мощности канал 4
#define idR0VN02RS4	 95	//(R0VN02RS4) Уровень мощности канал 4
#define R0VN01RS1	 BUFFER[214]	//(R0VN01RS1) Период разгона канал 1
#define idR0VN01RS1	 96	//(R0VN01RS1) Период разгона канал 1
#define R0VN01RS2	 BUFFER[219]	//(R0VN01RS2) Период разгона канал 2
#define idR0VN01RS2	 97	//(R0VN01RS2) Период разгона канал 2
#define R0VN01RS3	 BUFFER[224]	//(R0VN01RS3) Период разгона канал 3
#define idR0VN01RS3	 98	//(R0VN01RS3) Период разгона канал 3
#define R0VN01RS4	 BUFFER[229]	//(R0VN01RS4) Период разгона канал 4
#define idR0VN01RS4	 99	//(R0VN01RS4) Период разгона канал 4
#define R0VN61LS1	 BUFFER[234]	//(R0VN61LS1) ПС по мощности канал 1
#define idR0VN61LS1	 100	//(R0VN61LS1) ПС по мощности канал 1
#define A0IT01IZ1	 BUFFER[236]	//(A0IT01IZ1) Температура АЗ1-1
#define idA0IT01IZ1	 101	//(A0IT01IZ1) Температура АЗ1-1
#define A0CT01IZ1	 BUFFER[239]	//(A0CT01IZ1) Температура АЗ1-1
#define idA0CT01IZ1	 102	//(A0CT01IZ1) Температура АЗ1-1
#define A0VT61LZ1	 BUFFER[244]	//(A0VT61LZ1) ПС по температуре в АЗ1
#define idA0VT61LZ1	 103	//(A0VT61LZ1) ПС по температуре в АЗ1
#define A0VT71LZ1	 BUFFER[246]	//(A0VT71LZ1) АС по температуре в АЗ1
#define idA0VT71LZ1	 104	//(A0VT71LZ1) АС по температуре в АЗ1
#define A1VP41LZ1	 BUFFER[248]	//(A1VP41LZ1) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ1	 105	//(A1VP41LZ1) Давление СБРОС ББ1 ниже АС
#define B1VP41LZ1	 BUFFER[250]	//(B1VP41LZ1) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ1	 106	//(B1VP41LZ1) Давление СБРОС ББ2 ниже АС
#define B1VP81LZ1	 BUFFER[252]	//(B1VP81LZ1) Давление СБРОС ББ2 в норме
#define idB1VP81LZ1	 107	//(B1VP81LZ1) Давление СБРОС ББ2 в норме
#define A1VP81LZ1	 BUFFER[254]	//(A1VP81LZ1) Давление СБРОС ББ1 в норме
#define idA1VP81LZ1	 108	//(A1VP81LZ1) Давление СБРОС ББ1 в норме
#define A2VP41LZ1	 BUFFER[256]	//(A2VP41LZ1) Давление СБРОС РБ1 ниже АС
#define idA2VP41LZ1	 109	//(A2VP41LZ1) Давление СБРОС РБ1 ниже АС
#define A2CP01RZ1	 BUFFER[258]	//(A2CP01RZ1) Текущее давление СБРОС РБ1
#define idA2CP01RZ1	 110	//(A2CP01RZ1) Текущее давление СБРОС РБ1
#define A2VP51LZ1	 BUFFER[263]	//(A2VP51LZ1) Давление СБРОС РБ1 ниже ПС
#define idA2VP51LZ1	 111	//(A2VP51LZ1) Давление СБРОС РБ1 ниже ПС
#define B2VP41LZ1	 BUFFER[265]	//(B2VP41LZ1) Давление СБРОС РБ2 ниже АС
#define idB2VP41LZ1	 112	//(B2VP41LZ1) Давление СБРОС РБ2 ниже АС
#define B2CP01RZ1	 BUFFER[267]	//(B2CP01RZ1) Текущее давление СБРОС РБ2
#define idB2CP01RZ1	 113	//(B2CP01RZ1) Текущее давление СБРОС РБ2
#define B2VP51LZ1	 BUFFER[272]	//(B2VP51LZ1) Давление СБРОС РБ2 ниже ПС
#define idB2VP51LZ1	 114	//(B2VP51LZ1) Давление СБРОС РБ2 ниже ПС
#define B2VP81LZ1	 BUFFER[274]	//(B2VP81LZ1) Давление СБРОС РБ2 в норме
#define idB2VP81LZ1	 115	//(B2VP81LZ1) Давление СБРОС РБ2 в норме
#define A2VP81LZ1	 BUFFER[276]	//(A2VP81LZ1) Давление СБРОС РБ1 в норме
#define idA2VP81LZ1	 116	//(A2VP81LZ1) Давление СБРОС РБ1 в норме
#define A2IP01IZ1	 BUFFER[278]	//(A2IP01IZ1) Текущее давление СБРОС РБ1
#define idA2IP01IZ1	 117	//(A2IP01IZ1) Текущее давление СБРОС РБ1
#define B2IP01IZ1	 BUFFER[281]	//(B2IP01IZ1) Текущее давление СБРОС РБ2
#define idB2IP01IZ1	 118	//(B2IP01IZ1) Текущее давление СБРОС РБ2
#define R0ET01LZ1	 BUFFER[284]	//(R0ET01LZ1) Признак наличия неисправности по температуре  АЗ1
#define idR0ET01LZ1	 119	//(R0ET01LZ1) Признак наличия неисправности по температуре  АЗ1
#define B0IT01IZ1	 BUFFER[286]	//(B0IT01IZ1) Температура АЗ2-1
#define idB0IT01IZ1	 120	//(B0IT01IZ1) Температура АЗ2-1
#define R0VN66LZ1	 BUFFER[289]	//(R0VN66LZ1) ПС по периоду разгона канал 2
#define idR0VN66LZ1	 121	//(R0VN66LZ1) ПС по периоду разгона канал 2
#define R0VN67LZ1	 BUFFER[291]	//(R0VN67LZ1) ПС по периоду разгона канал 3
#define idR0VN67LZ1	 122	//(R0VN67LZ1) ПС по периоду разгона канал 3
#define R0VN68LZ1	 BUFFER[293]	//(R0VN68LZ1) ПС по периоду разгона канал 4
#define idR0VN68LZ1	 123	//(R0VN68LZ1) ПС по периоду разгона канал 4
#define R0VN09RZ1	 BUFFER[295]	//(R0VN09RZ1) Усредненный период разгона
#define idR0VN09RZ1	 124	//(R0VN09RZ1) Усредненный период разгона
#define A3IS11LZ1	 BUFFER[300]	//(A3IS11LZ1) Приход на ВУ ИС1
#define idA3IS11LZ1	 125	//(A3IS11LZ1) Приход на ВУ ИС1
#define A3IS22LZ1	 BUFFER[302]	//(A3IS22LZ1) Приход на НУП ИС1
#define idA3IS22LZ1	 126	//(A3IS22LZ1) Приход на НУП ИС1
#define R0AD03LZ1	 BUFFER[304]	//(R0AD03LZ1) Имитация прихода на ВУ ИС
#define idR0AD03LZ1	 127	//(R0AD03LZ1) Имитация прихода на ВУ ИС
#define B3IS11LZ1	 BUFFER[306]	//(B3IS11LZ1) Приход на ВУ ИС2
#define idB3IS11LZ1	 128	//(B3IS11LZ1) Приход на ВУ ИС2
#define A3VZ31LZ1	 BUFFER[308]	//(A3VZ31LZ1) АЗ от ВУ ИС1
#define idA3VZ31LZ1	 129	//(A3VZ31LZ1) АЗ от ВУ ИС1
#define B3VZ31LZ1	 BUFFER[310]	//(B3VZ31LZ1) АЗ от ВУ ИС2
#define idB3VZ31LZ1	 130	//(B3VZ31LZ1) АЗ от ВУ ИС2
#define R0AD05LZ1	 BUFFER[312]	//(R0AD05LZ1) Имитация ухода с НУП ИС
#define idR0AD05LZ1	 131	//(R0AD05LZ1) Имитация ухода с НУП ИС
#define A3VZ11LZ1	 BUFFER[314]	//(A3VZ11LZ1) АЗ от НУП ИС1
#define idA3VZ11LZ1	 132	//(A3VZ11LZ1) АЗ от НУП ИС1
#define B3VZ11LZ1	 BUFFER[316]	//(B3VZ11LZ1) АЗ от НУП ИС2
#define idB3VZ11LZ1	 133	//(B3VZ11LZ1) АЗ от НУП ИС2
#define B3IS22LZ1	 BUFFER[318]	//(B3IS22LZ1) Приход на НУП ИС2
#define idB3IS22LZ1	 134	//(B3IS22LZ1) Приход на НУП ИС2
#define R0VN69LZ1	 BUFFER[320]	//(R0VN69LZ1) ПС по усредненному периоду
#define idR0VN69LZ1	 135	//(R0VN69LZ1) ПС по усредненному периоду
#define R0VN79LZ1	 BUFFER[322]	//(R0VN79LZ1) АС по усредненному периоду
#define idR0VN79LZ1	 136	//(R0VN79LZ1) АС по усредненному периоду
#define R0VR02RZ1	 BUFFER[324]	//(R0VR02RZ1) Усредненная реактивность
#define idR0VR02RZ1	 137	//(R0VR02RZ1) Усредненная реактивность
#define R0VZ71LZ1	 BUFFER[329]	//(R0VZ71LZ1) Обобщенный сигнал АЗ 1 канала
#define idR0VZ71LZ1	 138	//(R0VZ71LZ1) Обобщенный сигнал АЗ 1 канала
#define R0VN70LZ1	 BUFFER[331]	//(R0VN70LZ1) АЗ по АС мощности РУ
#define idR0VN70LZ1	 139	//(R0VN70LZ1) АЗ по АС мощности РУ
#define R0VN80LZ1	 BUFFER[333]	//(R0VN80LZ1) АЗ по АС периода разгона РУ
#define idR0VN80LZ1	 140	//(R0VN80LZ1) АЗ по АС периода разгона РУ
#define R0VN61LS2	 BUFFER[335]	//(R0VN61LS2) ПС по мощности канал 2
#define idR0VN61LS2	 141	//(R0VN61LS2) ПС по мощности канал 2
#define R0VN61LS3	 BUFFER[337]	//(R0VN61LS3) ПС по мощности канал 3
#define idR0VN61LS3	 142	//(R0VN61LS3) ПС по мощности канал 3
#define R0VN61LS4	 BUFFER[339]	//(R0VN61LS4) ПС по мощности канал 4
#define idR0VN61LS4	 143	//(R0VN61LS4) ПС по мощности канал 4
#define R0VN65LS1	 BUFFER[341]	//(R0VN65LS1) ПС по периоду разгона канал 1
#define idR0VN65LS1	 144	//(R0VN65LS1) ПС по периоду разгона канал 1
#define R0VN65LS2	 BUFFER[343]	//(R0VN65LS2) ПС по периоду разгона  канал 2
#define idR0VN65LS2	 145	//(R0VN65LS2) ПС по периоду разгона  канал 2
#define R0VN65LS3	 BUFFER[345]	//(R0VN65LS3) ПС по периоду разгона канал 3
#define idR0VN65LS3	 146	//(R0VN65LS3) ПС по периоду разгона канал 3
#define R0VN65LS4	 BUFFER[347]	//(R0VN65LS4) ПС по периоду разгона канал 4
#define idR0VN65LS4	 147	//(R0VN65LS4) ПС по периоду разгона канал 4
#define R0VN01RZ1	 BUFFER[349]	//(R0VN01RZ1) Уровень мощности по каналу 1
#define idR0VN01RZ1	 148	//(R0VN01RZ1) Уровень мощности по каналу 1
#define R0VN02RZ1	 BUFFER[354]	//(R0VN02RZ1) Уровень мощности по каналу 2
#define idR0VN02RZ1	 149	//(R0VN02RZ1) Уровень мощности по каналу 2
#define R0VN03RZ1	 BUFFER[359]	//(R0VN03RZ1) Уровень мощности по каналу 3
#define idR0VN03RZ1	 150	//(R0VN03RZ1) Уровень мощности по каналу 3
#define R0VN04RZ1	 BUFFER[364]	//(R0VN04RZ1) Уровень мощности по каналу 4
#define idR0VN04RZ1	 151	//(R0VN04RZ1) Уровень мощности по каналу 4
#define R0VN05RZ1	 BUFFER[369]	//(R0VN05RZ1) Период разгона по каналу 1
#define idR0VN05RZ1	 152	//(R0VN05RZ1) Период разгона по каналу 1
#define R0VN06RZ1	 BUFFER[374]	//(R0VN06RZ1) Период разгона по каналу 2
#define idR0VN06RZ1	 153	//(R0VN06RZ1) Период разгона по каналу 2
#define R0VN07RZ1	 BUFFER[379]	//(R0VN07RZ1) Период разгона по каналу 3
#define idR0VN07RZ1	 154	//(R0VN07RZ1) Период разгона по каналу 3
#define R0VN08RZ1	 BUFFER[384]	//(R0VN08RZ1) Период разгона по каналу 4
#define idR0VN08RZ1	 155	//(R0VN08RZ1) Период разгона по каналу 4
#define R0VN61LZ1	 BUFFER[389]	//(R0VN61LZ1) ПС по мощности канал 1
#define idR0VN61LZ1	 156	//(R0VN61LZ1) ПС по мощности канал 1
#define R0VN62LZ1	 BUFFER[391]	//(R0VN62LZ1) ПС по мощности канал 2
#define idR0VN62LZ1	 157	//(R0VN62LZ1) ПС по мощности канал 2
#define R0VN63LZ1	 BUFFER[393]	//(R0VN63LZ1) ПС по мощности канал 3
#define idR0VN63LZ1	 158	//(R0VN63LZ1) ПС по мощности канал 3
#define R0VN64LZ1	 BUFFER[395]	//(R0VN64LZ1) ПС по мощности канал 4
#define idR0VN64LZ1	 159	//(R0VN64LZ1) ПС по мощности канал 4
#define R0VN65LZ1	 BUFFER[397]	//(R0VN65LZ1) ПС по периоду разгона канал 1
#define idR0VN65LZ1	 160	//(R0VN65LZ1) ПС по периоду разгона канал 1
#define fEM_R0UT02RZZ	 BUFFER[399]	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RZZ	 161	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define fEM_R0UT01RZZ	 BUFFER[404]	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RZZ	 162	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define fEM_A2UP03RZZ	 BUFFER[409]	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define idfEM_A2UP03RZZ	 163	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define fEM_A2UP04RZZ	 BUFFER[414]	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define idfEM_A2UP04RZZ	 164	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define fEM_R0UT72RZZ	 BUFFER[419]	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define idfEM_R0UT72RZZ	 165	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define fEM_R0UT71RZZ	 BUFFER[424]	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define idfEM_R0UT71RZZ	 166	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define fEM_R0UT62RZZ	 BUFFER[429]	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define idfEM_R0UT62RZZ	 167	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define fEM_R0UT61RZZ	 BUFFER[434]	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define idfEM_R0UT61RZZ	 168	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define fEM_A2UP41RZZ	 BUFFER[439]	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define idfEM_A2UP41RZZ	 169	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define fEM_A2UP42RZZ	 BUFFER[444]	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define idfEM_A2UP42RZZ	 170	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define fEM_A2UP51RZZ	 BUFFER[449]	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define idfEM_A2UP51RZZ	 171	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define fEM_A2UP81RZZ	 BUFFER[454]	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP81RZZ	 172	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP84RZZ	 BUFFER[459]	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP84RZZ	 173	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP82RZZ	 BUFFER[464]	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP82RZZ	 174	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP52RZZ	 BUFFER[469]	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define idfEM_A2UP52RZZ	 175	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define fEM_A2UP83RZZ	 BUFFER[474]	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP83RZZ	 176	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_R0UR01RZZ	 BUFFER[479]	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define idfEM_R0UR01RZZ	 177	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define fEM_R0UR04RZZ	 BUFFER[484]	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define idfEM_R0UR04RZZ	 178	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define fEM_A1UL12RZZ	 BUFFER[489]	//(A1UL12RZZ) Время задержки АЗ от НУ ИС(сек)
#define idfEM_A1UL12RZZ	 179	//(A1UL12RZZ) Время задержки АЗ от НУ ИС(сек)
#define fEM_A1UL11RZZ	 BUFFER[494]	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
#define idfEM_A1UL11RZZ	 180	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
#define fEM_R7UI73RZZ	 BUFFER[499]	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
#define idfEM_R7UI73RZZ	 181	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
#define bFirstEnterFlag	 BUFFER[504]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 182	//(bFirstEnterFlag) 
#define internal1_m253_tx	 BUFFER[506]	//(internal1_m253_tx) tx - время накопленное сек
#define idinternal1_m253_tx	 183	//(internal1_m253_tx) tx - время накопленное сек
#define internal1_m253_y0	 BUFFER[511]	//(internal1_m253_y0) y0
#define idinternal1_m253_y0	 184	//(internal1_m253_y0) y0
#define internal1_m261_tx	 BUFFER[512]	//(internal1_m261_tx) tx - время накопленное сек
#define idinternal1_m261_tx	 185	//(internal1_m261_tx) tx - время накопленное сек
#define internal1_m261_y0	 BUFFER[517]	//(internal1_m261_y0) y0
#define idinternal1_m261_y0	 186	//(internal1_m261_y0) y0
#define internal1_m324_tx	 BUFFER[518]	//(internal1_m324_tx) tx - время накопленное сек
#define idinternal1_m324_tx	 187	//(internal1_m324_tx) tx - время накопленное сек
#define internal1_m324_y0	 BUFFER[523]	//(internal1_m324_y0) y0
#define idinternal1_m324_y0	 188	//(internal1_m324_y0) y0
#define internal1_m220_tx	 BUFFER[524]	//(internal1_m220_tx) tx - время накопленное сек
#define idinternal1_m220_tx	 189	//(internal1_m220_tx) tx - время накопленное сек
#define internal1_m220_y0	 BUFFER[529]	//(internal1_m220_y0) y0
#define idinternal1_m220_y0	 190	//(internal1_m220_y0) y0
#define internal1_m219_tx	 BUFFER[530]	//(internal1_m219_tx) tx - время накопленное сек
#define idinternal1_m219_tx	 191	//(internal1_m219_tx) tx - время накопленное сек
#define internal1_m219_y0	 BUFFER[535]	//(internal1_m219_y0) y0
#define idinternal1_m219_y0	 192	//(internal1_m219_y0) y0
#define internal1_m217_tx	 BUFFER[536]	//(internal1_m217_tx) tx - время накопленное сек
#define idinternal1_m217_tx	 193	//(internal1_m217_tx) tx - время накопленное сек
#define internal1_m217_y0	 BUFFER[541]	//(internal1_m217_y0) y0
#define idinternal1_m217_y0	 194	//(internal1_m217_y0) y0
#define internal1_m215_tx	 BUFFER[542]	//(internal1_m215_tx) tx - время накопленное сек
#define idinternal1_m215_tx	 195	//(internal1_m215_tx) tx - время накопленное сек
#define internal1_m215_y0	 BUFFER[547]	//(internal1_m215_y0) y0
#define idinternal1_m215_y0	 196	//(internal1_m215_y0) y0
#define internal1_m33_tx	 BUFFER[548]	//(internal1_m33_tx) tx - внутренний параметр
#define idinternal1_m33_tx	 197	//(internal1_m33_tx) tx - внутренний параметр
#define internal1_m150_y0	 BUFFER[551]	//(internal1_m150_y0) y0
#define idinternal1_m150_y0	 198	//(internal1_m150_y0) y0
#define internal1_m148_y0	 BUFFER[556]	//(internal1_m148_y0) y0
#define idinternal1_m148_y0	 199	//(internal1_m148_y0) y0
#define internal1_m97_y0	 BUFFER[561]	//(internal1_m97_y0) y0
#define idinternal1_m97_y0	 200	//(internal1_m97_y0) y0
#define internal1_m95_y0	 BUFFER[566]	//(internal1_m95_y0) y0
#define idinternal1_m95_y0	 201	//(internal1_m95_y0) y0
#define internal1_m161_y1	 BUFFER[571]	//(internal1_m161_y1) y1 - внутренний параметр
#define idinternal1_m161_y1	 202	//(internal1_m161_y1) y1 - внутренний параметр
#define internal1_m172_y1	 BUFFER[573]	//(internal1_m172_y1) y1 - внутренний параметр
#define idinternal1_m172_y1	 203	//(internal1_m172_y1) y1 - внутренний параметр
#define internal1_m317_q0	 BUFFER[575]	//(internal1_m317_q0) q0 - внутренний параметр
#define idinternal1_m317_q0	 204	//(internal1_m317_q0) q0 - внутренний параметр
#define internal1_m137_y0	 BUFFER[580]	//(internal1_m137_y0) state
#define idinternal1_m137_y0	 205	//(internal1_m137_y0) state
#define internal1_m130_y0	 BUFFER[582]	//(internal1_m130_y0) state
#define idinternal1_m130_y0	 206	//(internal1_m130_y0) state
#define internal1_m109_y1	 BUFFER[584]	//(internal1_m109_y1) y1 - внутренний параметр
#define idinternal1_m109_y1	 207	//(internal1_m109_y1) y1 - внутренний параметр
#define internal1_m123_y1	 BUFFER[586]	//(internal1_m123_y1) y1 - внутренний параметр
#define idinternal1_m123_y1	 208	//(internal1_m123_y1) y1 - внутренний параметр
#define internal1_m102_y1	 BUFFER[588]	//(internal1_m102_y1) y1 - внутренний параметр
#define idinternal1_m102_y1	 209	//(internal1_m102_y1) y1 - внутренний параметр
#define internal1_m112_y1	 BUFFER[590]	//(internal1_m112_y1) y1 - внутренний параметр
#define idinternal1_m112_y1	 210	//(internal1_m112_y1) y1 - внутренний параметр
#define internal1_m158_y1	 BUFFER[592]	//(internal1_m158_y1) y1 - внутренний параметр
#define idinternal1_m158_y1	 211	//(internal1_m158_y1) y1 - внутренний параметр
#define internal1_m170_y1	 BUFFER[594]	//(internal1_m170_y1) y1 - внутренний параметр
#define idinternal1_m170_y1	 212	//(internal1_m170_y1) y1 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &R0EE02LDU},	//(R0EE02LDU) Питание  АКНП  отключить
	{ 2	,5	,1	, &R0VZ05UZ1},	//(R0VZ05UZ1) Индикатор причины сброса
	{ 3	,8	,1	, &R0VN11RZ1},	//(R0VN11RZ1) Средняя мощность по БАЗ1
	{ 4	,1	,1	, &R0VP73LZ1},	//(R0VP73LZ1) ПС давления для РУ
	{ 5	,8	,1	, &B0CT01IZ1},	//(B0CT01IZ1) Температура АЗ2-1
	{ 6	,1	,1	, &B0VT61LZ1},	//(B0VT61LZ1) ПС по температуре в АЗ2
	{ 7	,1	,1	, &B0VT71LZ1},	//(B0VT71LZ1) АС по температуре в АЗ2
	{ 8	,1	,1	, &A0VN71LS1},	//(A0VN71LS1) Блокировка автоматического подъёма ББ канал 1
	{ 9	,1	,1	, &A0VN71LS2},	//(A0VN71LS2) Блокировка автоматического подъёма ББ канал 2
	{ 10	,1	,1	, &A0VN71LS3},	//(A0VN71LS3) Блокировка автоматического подъёма ББ канал 3
	{ 11	,1	,1	, &A0VN71LS4},	//(A0VN71LS4) Блокировка автоматического подъёма ББ канал 4
	{ 12	,1	,1	, &A1VN71LZ1},	//(A1VN71LZ1) Блокировка автоматического подъёма ББ
	{ 13	,1	,1	, &A3VZ15LZ1},	//(A3VZ15LZ1) Имитация АЗ от НУП ИС
	{ 14	,1	,1	, &A3VZ13LZ1},	//(A3VZ13LZ1) Имитация АЗ от ВУ ИС
	{ 15	,1	,1	, &R0VW13LDU},	//(R0VW13LDU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{ 16	,1	,1	, &R0VW23LDU},	//(R0VW23LDU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{ 17	,1	,1	, &R7II73LZ1},	//(R7II73LZ1) Сработала АС II УР РАД
	{ 18	,1	,1	, &R7II71LZ1},	//(R7II71LZ1) Сработала АС IУР РАД (датчик 1)
	{ 19	,1	,1	, &R7II72LZ1},	//(R7II72LZ1) Сработала АС IУР РАД  (датчик 2)
	{ 20	,1	,1	, &R0AD14LZ1},	//(R0AD14LZ1) Имитация АЗ от IIУР
	{ 21	,1	,1	, &A0EE01LS1},	//(A0EE01LS1) Исправность АКНП канал 1
	{ 22	,1	,1	, &A0EE01LS4},	//(A0EE01LS4) Исправность АКНП канал 4
	{ 23	,1	,1	, &A0EE01LS3},	//(A0EE01LS3) Исправность АКНП канал 3
	{ 24	,1	,1	, &A0EE01LZ1},	//(A0EE01LZ1) Исправность АКНП1
	{ 25	,1	,1	, &A0EE04LZ1},	//(A0EE04LZ1) Исправность АКНП4
	{ 26	,1	,1	, &A0EE02LZ1},	//(A0EE02LZ1) Исправность АКНП2
	{ 27	,1	,1	, &A0EE03LZ1},	//(A0EE03LZ1) Исправность АКНП3
	{ 28	,1	,1	, &A0EE01LS2},	//(A0EE01LS2) Исправность АКНП  канал 2
	{ 29	,1	,1	, &A0EE05LZ1},	//(A0EE05LZ1) Исправность сети АКНП1
	{ 30	,1	,1	, &A0EE06LZ1},	//(A0EE06LZ1) Исправность сети АКНП2
	{ 31	,1	,1	, &A0EE07LZ1},	//(A0EE07LZ1) Исправность сети АКНП3
	{ 32	,1	,1	, &A0EE08LZ1},	//(A0EE08LZ1) Исправность сети АКНП4
	{ 33	,1	,1	, &A0VZ71LZ1},	//(A0VZ71LZ1) Обобщенный сигнал АС по АЗ1
	{ 34	,1	,1	, &A0EE00LZ1},	//(A0EE00LZ1) Исправность АКНП АЗ1
	{ 35	,1	,1	, &B0EE00LZ1},	//(B0EE00LZ1) Исправность АКНП АЗ2
	{ 36	,1	,1	, &B0VZ71LZ1},	//(B0VZ71LZ1) Обобщенный сигнал АС по АЗ2
	{ 37	,1	,1	, &A0VN71LZ1},	//(A0VN71LZ1) АЗ по АС мощности  АЗ1
	{ 38	,1	,1	, &B0VN71LZ1},	//(B0VN71LZ1) АЗ по АС мощности  АЗ2
	{ 39	,1	,1	, &A0VN81LZ1},	//(A0VN81LZ1) АЗ по АС периода разгона АЗ1
	{ 40	,1	,1	, &B0VN81LZ1},	//(B0VN81LZ1) АЗ по АС периода разгона АЗ2
	{ 41	,1	,1	, &R0EE02LZ1},	//(R0EE02LZ1) Питание  АКНП2  отключить
	{ 42	,1	,1	, &R0EE03LZ1},	//(R0EE03LZ1) Питание  АКНП3  отключить
	{ 43	,1	,1	, &R0EE04LZ1},	//(R0EE04LZ1) Питание  АКНП4  отключить
	{ 44	,1	,1	, &R0AD15LZ1},	//(R0AD15LZ1) Имитация АЗ от 1УР (датчик1)
	{ 45	,1	,1	, &R0AD16LZ1},	//(R0AD16LZ1) Имитация АЗ от 1УР (датчик2)
	{ 46	,3	,1	, &R0MW12IP2},	//(R0MW12IP2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
	{ 47	,1	,1	, &R0AD13LDU},	//(R0AD13LDU) Имитация прихода на ВУ ИС
	{ 48	,1	,1	, &R0AD15LDU},	//(R0AD15LDU) Имитация ухода с НУП ИС
	{ 49	,1	,1	, &A2IS12LDU},	//(A2IS12LDU) Магнит РБ1 зацеплен
	{ 50	,1	,1	, &B2IS12LDU},	//(B2IS12LDU) Магнит РБ2 зацеплен
	{ 51	,1	,1	, &A3IS11LDU},	//(A3IS11LDU) Приход на ВУ ИС1 для ДУ
	{ 52	,1	,1	, &A3IS22LDU},	//(A3IS22LDU) Приход на НУП ИС1 для ДУ
	{ 53	,1	,1	, &A3IS11LZ2},	//(A3IS11LZ2) Приход на ВУ ИС1 для УСБ2
	{ 54	,1	,1	, &A3IS22LZ2},	//(A3IS22LZ2) Приход на НУП ИС1 для УСБ2
	{ 55	,1	,1	, &A0VP81LZ2},	//(A0VP81LZ2) Давление  АЗ1 в норме для УСБ2
	{ 56	,1	,1	, &A1VP81LZ2},	//(A1VP81LZ2) Давление СБРОС ББ1 в норме для УСБ2
	{ 57	,1	,1	, &OEBB1Z1},	//(OEBB1Z1) Обесточивание ЭМ ББ1 и ЭПК ББ1
	{ 58	,1	,1	, &OEBB2Z1},	//(OEBB2Z1) Обесточивание ЭМ ББ2 и ЭПК ББ2
	{ 59	,1	,1	, &OERB2Z1},	//(OERB2Z1) Обесточивание ЭМ РБ2 и ЭПК РБ2
	{ 60	,1	,1	, &OERB1Z1},	//(OERB1Z1) Обесточивание ЭМ РБ1 и ЭПК РБ1
	{ 61	,1	,1	, &R0AD21LDU},	//(R0AD21LDU) Подключить защиту от II УР
	{ 62	,1	,1	, &R0AD14LDU},	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
	{ 63	,1	,1	, &R0MD34LP1},	//(R0MD34LP1) Кнопка (Квитировать)
	{ 64	,1	,1	, &R0AD04LZ1},	//(R0AD04LZ1) Имитация срабатывания верхней АС II УР
	{ 65	,1	,1	, &R0AD16LDU},	//(R0AD16LDU) Имитация срабатывания верхней АС I УР
	{ 66	,1	,1	, &R0EE01LZ1},	//(R0EE01LZ1) Питание  АКНП1  отключить
	{ 67	,1	,1	, &A2IS12LZ1},	//(A2IS12LZ1) Магнит РБ1 зацеплен
	{ 68	,1	,1	, &B2IS12LZ1},	//(B2IS12LZ1) Магнит РБ2 зацеплен
	{ 69	,1	,1	, &R6IS66LZ1},	//(R6IS66LZ1) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 70	,1	,1	, &R6IS67LZ1},	//(R6IS67LZ1) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 71	,1	,1	, &R6IS68LZ1},	//(R6IS68LZ1) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 72	,1	,1	, &R0VN71LZ1},	//(R0VN71LZ1) АС по мощности канал 1
	{ 73	,1	,1	, &R0VN75LZ1},	//(R0VN75LZ1) АС по периоду разгона канал 1
	{ 74	,1	,1	, &R0VN72LZ1},	//(R0VN72LZ1) АС по мощности канал 2
	{ 75	,1	,1	, &R0VN76LZ1},	//(R0VN76LZ1) АС по периоду разгона канал  2
	{ 76	,1	,1	, &R0VN73LZ1},	//(R0VN73LZ1) АС по мощности канал 3
	{ 77	,1	,1	, &R0VN77LZ1},	//(R0VN77LZ1) АС по периоду разгона канал  3
	{ 78	,1	,1	, &R0VN74LZ1},	//(R0VN74LZ1) АС по мощности канал 4
	{ 79	,1	,1	, &R0VN78LZ1},	//(R0VN78LZ1) АС по периоду разгона канал  4
	{ 80	,1	,1	, &R0VP82LZ1},	//(R0VP82LZ1) Давление  в СИСТЕМЕ - 2 в норме
	{ 81	,1	,1	, &A0VP41LZ1},	//(A0VP41LZ1) Давление АЗ1 ниже АС
	{ 82	,1	,1	, &B0VP41LZ1},	//(B0VP41LZ1) Давление АЗ2 ниже АС
	{ 83	,1	,1	, &B0VP81LZ1},	//(B0VP81LZ1) Давление АЗ2 в норме
	{ 84	,1	,1	, &A0VP81LZ1},	//(A0VP81LZ1) Давление  АЗ1 в норме
	{ 85	,1	,1	, &R0VP41LZ1},	//(R0VP41LZ1) АС по давлению в СИСТЕМЕ
	{ 86	,1	,1	, &R0VP81LZ1},	//(R0VP81LZ1) Давление  в СИСТЕМЕ -1 в норме
	{ 87	,1	,1	, &R0ET02LZ1},	//(R0ET02LZ1) Признак наличия неисправности по температуре АЗ2
	{ 88	,3	,1	, &B0EP02IZ1},	//(B0EP02IZ1) Индикатор -Давление  АЗ2 ниже АС
	{ 89	,3	,1	, &A0EP02IZ1},	//(A0EP02IZ1) Индикатор -Давление  АЗ1 ниже АС
	{ 90	,1	,1	, &A0VP71LZ1},	//(A0VP71LZ1) АЗ по АС любого давления для АЗ1
	{ 91	,1	,1	, &B0VP71LZ1},	//(B0VP71LZ1) АЗ по АС любого давления для АЗ2
	{ 92	,8	,1	, &R0VN02RS1},	//(R0VN02RS1) Уровень мощности канал 1
	{ 93	,8	,1	, &R0VN02RS2},	//(R0VN02RS2) Уровень мощности канал 2
	{ 94	,8	,1	, &R0VN02RS3},	//(R0VN02RS3) Уровень мощности канал 3
	{ 95	,8	,1	, &R0VN02RS4},	//(R0VN02RS4) Уровень мощности канал 4
	{ 96	,8	,1	, &R0VN01RS1},	//(R0VN01RS1) Период разгона канал 1
	{ 97	,8	,1	, &R0VN01RS2},	//(R0VN01RS2) Период разгона канал 2
	{ 98	,8	,1	, &R0VN01RS3},	//(R0VN01RS3) Период разгона канал 3
	{ 99	,8	,1	, &R0VN01RS4},	//(R0VN01RS4) Период разгона канал 4
	{ 100	,1	,1	, &R0VN61LS1},	//(R0VN61LS1) ПС по мощности канал 1
	{ 101	,3	,1	, &A0IT01IZ1},	//(A0IT01IZ1) Температура АЗ1-1
	{ 102	,8	,1	, &A0CT01IZ1},	//(A0CT01IZ1) Температура АЗ1-1
	{ 103	,1	,1	, &A0VT61LZ1},	//(A0VT61LZ1) ПС по температуре в АЗ1
	{ 104	,1	,1	, &A0VT71LZ1},	//(A0VT71LZ1) АС по температуре в АЗ1
	{ 105	,1	,1	, &A1VP41LZ1},	//(A1VP41LZ1) Давление СБРОС ББ1 ниже АС
	{ 106	,1	,1	, &B1VP41LZ1},	//(B1VP41LZ1) Давление СБРОС ББ2 ниже АС
	{ 107	,1	,1	, &B1VP81LZ1},	//(B1VP81LZ1) Давление СБРОС ББ2 в норме
	{ 108	,1	,1	, &A1VP81LZ1},	//(A1VP81LZ1) Давление СБРОС ББ1 в норме
	{ 109	,1	,1	, &A2VP41LZ1},	//(A2VP41LZ1) Давление СБРОС РБ1 ниже АС
	{ 110	,8	,1	, &A2CP01RZ1},	//(A2CP01RZ1) Текущее давление СБРОС РБ1
	{ 111	,1	,1	, &A2VP51LZ1},	//(A2VP51LZ1) Давление СБРОС РБ1 ниже ПС
	{ 112	,1	,1	, &B2VP41LZ1},	//(B2VP41LZ1) Давление СБРОС РБ2 ниже АС
	{ 113	,8	,1	, &B2CP01RZ1},	//(B2CP01RZ1) Текущее давление СБРОС РБ2
	{ 114	,1	,1	, &B2VP51LZ1},	//(B2VP51LZ1) Давление СБРОС РБ2 ниже ПС
	{ 115	,1	,1	, &B2VP81LZ1},	//(B2VP81LZ1) Давление СБРОС РБ2 в норме
	{ 116	,1	,1	, &A2VP81LZ1},	//(A2VP81LZ1) Давление СБРОС РБ1 в норме
	{ 117	,3	,1	, &A2IP01IZ1},	//(A2IP01IZ1) Текущее давление СБРОС РБ1
	{ 118	,3	,1	, &B2IP01IZ1},	//(B2IP01IZ1) Текущее давление СБРОС РБ2
	{ 119	,1	,1	, &R0ET01LZ1},	//(R0ET01LZ1) Признак наличия неисправности по температуре  АЗ1
	{ 120	,3	,1	, &B0IT01IZ1},	//(B0IT01IZ1) Температура АЗ2-1
	{ 121	,1	,1	, &R0VN66LZ1},	//(R0VN66LZ1) ПС по периоду разгона канал 2
	{ 122	,1	,1	, &R0VN67LZ1},	//(R0VN67LZ1) ПС по периоду разгона канал 3
	{ 123	,1	,1	, &R0VN68LZ1},	//(R0VN68LZ1) ПС по периоду разгона канал 4
	{ 124	,8	,1	, &R0VN09RZ1},	//(R0VN09RZ1) Усредненный период разгона
	{ 125	,1	,1	, &A3IS11LZ1},	//(A3IS11LZ1) Приход на ВУ ИС1
	{ 126	,1	,1	, &A3IS22LZ1},	//(A3IS22LZ1) Приход на НУП ИС1
	{ 127	,1	,1	, &R0AD03LZ1},	//(R0AD03LZ1) Имитация прихода на ВУ ИС
	{ 128	,1	,1	, &B3IS11LZ1},	//(B3IS11LZ1) Приход на ВУ ИС2
	{ 129	,1	,1	, &A3VZ31LZ1},	//(A3VZ31LZ1) АЗ от ВУ ИС1
	{ 130	,1	,1	, &B3VZ31LZ1},	//(B3VZ31LZ1) АЗ от ВУ ИС2
	{ 131	,1	,1	, &R0AD05LZ1},	//(R0AD05LZ1) Имитация ухода с НУП ИС
	{ 132	,1	,1	, &A3VZ11LZ1},	//(A3VZ11LZ1) АЗ от НУП ИС1
	{ 133	,1	,1	, &B3VZ11LZ1},	//(B3VZ11LZ1) АЗ от НУП ИС2
	{ 134	,1	,1	, &B3IS22LZ1},	//(B3IS22LZ1) Приход на НУП ИС2
	{ 135	,1	,1	, &R0VN69LZ1},	//(R0VN69LZ1) ПС по усредненному периоду
	{ 136	,1	,1	, &R0VN79LZ1},	//(R0VN79LZ1) АС по усредненному периоду
	{ 137	,8	,1	, &R0VR02RZ1},	//(R0VR02RZ1) Усредненная реактивность
	{ 138	,1	,1	, &R0VZ71LZ1},	//(R0VZ71LZ1) Обобщенный сигнал АЗ 1 канала
	{ 139	,1	,1	, &R0VN70LZ1},	//(R0VN70LZ1) АЗ по АС мощности РУ
	{ 140	,1	,1	, &R0VN80LZ1},	//(R0VN80LZ1) АЗ по АС периода разгона РУ
	{ 141	,1	,1	, &R0VN61LS2},	//(R0VN61LS2) ПС по мощности канал 2
	{ 142	,1	,1	, &R0VN61LS3},	//(R0VN61LS3) ПС по мощности канал 3
	{ 143	,1	,1	, &R0VN61LS4},	//(R0VN61LS4) ПС по мощности канал 4
	{ 144	,1	,1	, &R0VN65LS1},	//(R0VN65LS1) ПС по периоду разгона канал 1
	{ 145	,1	,1	, &R0VN65LS2},	//(R0VN65LS2) ПС по периоду разгона  канал 2
	{ 146	,1	,1	, &R0VN65LS3},	//(R0VN65LS3) ПС по периоду разгона канал 3
	{ 147	,1	,1	, &R0VN65LS4},	//(R0VN65LS4) ПС по периоду разгона канал 4
	{ 148	,8	,1	, &R0VN01RZ1},	//(R0VN01RZ1) Уровень мощности по каналу 1
	{ 149	,8	,1	, &R0VN02RZ1},	//(R0VN02RZ1) Уровень мощности по каналу 2
	{ 150	,8	,1	, &R0VN03RZ1},	//(R0VN03RZ1) Уровень мощности по каналу 3
	{ 151	,8	,1	, &R0VN04RZ1},	//(R0VN04RZ1) Уровень мощности по каналу 4
	{ 152	,8	,1	, &R0VN05RZ1},	//(R0VN05RZ1) Период разгона по каналу 1
	{ 153	,8	,1	, &R0VN06RZ1},	//(R0VN06RZ1) Период разгона по каналу 2
	{ 154	,8	,1	, &R0VN07RZ1},	//(R0VN07RZ1) Период разгона по каналу 3
	{ 155	,8	,1	, &R0VN08RZ1},	//(R0VN08RZ1) Период разгона по каналу 4
	{ 156	,1	,1	, &R0VN61LZ1},	//(R0VN61LZ1) ПС по мощности канал 1
	{ 157	,1	,1	, &R0VN62LZ1},	//(R0VN62LZ1) ПС по мощности канал 2
	{ 158	,1	,1	, &R0VN63LZ1},	//(R0VN63LZ1) ПС по мощности канал 3
	{ 159	,1	,1	, &R0VN64LZ1},	//(R0VN64LZ1) ПС по мощности канал 4
	{ 160	,1	,1	, &R0VN65LZ1},	//(R0VN65LZ1) ПС по периоду разгона канал 1
	{ 161	,8	,1	, &fEM_R0UT02RZZ},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{ 162	,8	,1	, &fEM_R0UT01RZZ},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{ 163	,8	,1	, &fEM_A2UP03RZZ},	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
	{ 164	,8	,1	, &fEM_A2UP04RZZ},	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
	{ 165	,8	,1	, &fEM_R0UT72RZZ},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{ 166	,8	,1	, &fEM_R0UT71RZZ},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{ 167	,8	,1	, &fEM_R0UT62RZZ},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{ 168	,8	,1	, &fEM_R0UT61RZZ},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{ 169	,8	,1	, &fEM_A2UP41RZZ},	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
	{ 170	,8	,1	, &fEM_A2UP42RZZ},	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
	{ 171	,8	,1	, &fEM_A2UP51RZZ},	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
	{ 172	,8	,1	, &fEM_A2UP81RZZ},	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{ 173	,8	,1	, &fEM_A2UP84RZZ},	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{ 174	,8	,1	, &fEM_A2UP82RZZ},	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
	{ 175	,8	,1	, &fEM_A2UP52RZZ},	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
	{ 176	,8	,1	, &fEM_A2UP83RZZ},	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
	{ 177	,8	,1	, &fEM_R0UR01RZZ},	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
	{ 178	,8	,1	, &fEM_R0UR04RZZ},	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
	{ 179	,8	,1	, &fEM_A1UL12RZZ},	//(A1UL12RZZ) Время задержки АЗ от НУ ИС(сек)
	{ 180	,8	,1	, &fEM_A1UL11RZZ},	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
	{ 181	,8	,1	, &fEM_R7UI73RZZ},	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
	{ 182	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 183	,8	,1	, &internal1_m253_tx},	//(internal1_m253_tx) tx - время накопленное сек
	{ 184	,18	,1	, &internal1_m253_y0},	//(internal1_m253_y0) y0
	{ 185	,8	,1	, &internal1_m261_tx},	//(internal1_m261_tx) tx - время накопленное сек
	{ 186	,18	,1	, &internal1_m261_y0},	//(internal1_m261_y0) y0
	{ 187	,8	,1	, &internal1_m324_tx},	//(internal1_m324_tx) tx - время накопленное сек
	{ 188	,18	,1	, &internal1_m324_y0},	//(internal1_m324_y0) y0
	{ 189	,8	,1	, &internal1_m220_tx},	//(internal1_m220_tx) tx - время накопленное сек
	{ 190	,18	,1	, &internal1_m220_y0},	//(internal1_m220_y0) y0
	{ 191	,8	,1	, &internal1_m219_tx},	//(internal1_m219_tx) tx - время накопленное сек
	{ 192	,18	,1	, &internal1_m219_y0},	//(internal1_m219_y0) y0
	{ 193	,8	,1	, &internal1_m217_tx},	//(internal1_m217_tx) tx - время накопленное сек
	{ 194	,18	,1	, &internal1_m217_y0},	//(internal1_m217_y0) y0
	{ 195	,8	,1	, &internal1_m215_tx},	//(internal1_m215_tx) tx - время накопленное сек
	{ 196	,18	,1	, &internal1_m215_y0},	//(internal1_m215_y0) y0
	{ 197	,3	,1	, &internal1_m33_tx},	//(internal1_m33_tx) tx - внутренний параметр
	{ 198	,8	,1	, &internal1_m150_y0},	//(internal1_m150_y0) y0
	{ 199	,8	,1	, &internal1_m148_y0},	//(internal1_m148_y0) y0
	{ 200	,8	,1	, &internal1_m97_y0},	//(internal1_m97_y0) y0
	{ 201	,8	,1	, &internal1_m95_y0},	//(internal1_m95_y0) y0
	{ 202	,1	,1	, &internal1_m161_y1},	//(internal1_m161_y1) y1 - внутренний параметр
	{ 203	,1	,1	, &internal1_m172_y1},	//(internal1_m172_y1) y1 - внутренний параметр
	{ 204	,5	,1	, &internal1_m317_q0},	//(internal1_m317_q0) q0 - внутренний параметр
	{ 205	,1	,1	, &internal1_m137_y0},	//(internal1_m137_y0) state
	{ 206	,1	,1	, &internal1_m130_y0},	//(internal1_m130_y0) state
	{ 207	,1	,1	, &internal1_m109_y1},	//(internal1_m109_y1) y1 - внутренний параметр
	{ 208	,1	,1	, &internal1_m123_y1},	//(internal1_m123_y1) y1 - внутренний параметр
	{ 209	,1	,1	, &internal1_m102_y1},	//(internal1_m102_y1) y1 - внутренний параметр
	{ 210	,1	,1	, &internal1_m112_y1},	//(internal1_m112_y1) y1 - внутренний параметр
	{ 211	,1	,1	, &internal1_m158_y1},	//(internal1_m158_y1) y1 - внутренний параметр
	{ 212	,1	,1	, &internal1_m170_y1},	//(internal1_m170_y1) y1 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="baz1.bin\0";   // Имя файла для сохранения констант
#pragma pop
static short saveVariables[]={      // Id переменных для сохранения
161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,-1,};
#pragma pack(push,1)
static ModbusRegister coil_Baz1[]={  // 
	{&R0EE02LDU,1,0},	//(R0EE02LDU) Питание  АКНП  отключить
	{&A0EE08LZ1,1,1},	//(A0EE08LZ1) Исправность сети АКНП4
	{&A0EE07LZ1,1,2},	//(A0EE07LZ1) Исправность сети АКНП3
	{&A0EE06LZ1,1,3},	//(A0EE06LZ1) Исправность сети АКНП2
	{&A0EE05LZ1,1,4},	//(A0EE05LZ1) Исправность сети АКНП1
	{&R0VN78LZ1,1,5},	//(R0VN78LZ1) АС по периоду разгона канал  4
	{&R0VN74LZ1,1,6},	//(R0VN74LZ1) АС по мощности канал 4
	{&R0VN77LZ1,1,7},	//(R0VN77LZ1) АС по периоду разгона канал  3
	{&R0VN73LZ1,1,8},	//(R0VN73LZ1) АС по мощности канал 3
	{&R0VN76LZ1,1,9},	//(R0VN76LZ1) АС по периоду разгона канал  2
	{&R0VN72LZ1,1,10},	//(R0VN72LZ1) АС по мощности канал 2
	{&R0VN75LZ1,1,11},	//(R0VN75LZ1) АС по периоду разгона канал 1
	{&R0VN71LZ1,1,12},	//(R0VN71LZ1) АС по мощности канал 1
	{&R0AD16LDU,1,13},	//(R0AD16LDU) Имитация срабатывания верхней АС I УР
	{&R0MD34LP1,1,14},	//(R0MD34LP1) Кнопка (Квитировать)
	{&R7II72LZ1,1,15},	//(R7II72LZ1) Сработала АС IУР РАД  (датчик 2)
	{&R7II71LZ1,1,16},	//(R7II71LZ1) Сработала АС IУР РАД (датчик 1)
	{&R7II73LZ1,1,17},	//(R7II73LZ1) Сработала АС II УР РАД
	{&R0VW23LDU,1,18},	//(R0VW23LDU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,1,19},	//(R0VW13LDU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_Baz1[]={  // 
	{&B0VN81LZ1,1,0},	//(B0VN81LZ1) АЗ по АС периода разгона АЗ2
	{&A0VN81LZ1,1,1},	//(A0VN81LZ1) АЗ по АС периода разгона АЗ1
	{&B0VN71LZ1,1,2},	//(B0VN71LZ1) АЗ по АС мощности  АЗ2
	{&A0VN71LZ1,1,3},	//(A0VN71LZ1) АЗ по АС мощности  АЗ1
	{&B0VZ71LZ1,1,4},	//(B0VZ71LZ1) Обобщенный сигнал АС по АЗ2
	{&B0EE00LZ1,1,5},	//(B0EE00LZ1) Исправность АКНП АЗ2
	{&A0EE00LZ1,1,6},	//(A0EE00LZ1) Исправность АКНП АЗ1
	{&A0VZ71LZ1,1,7},	//(A0VZ71LZ1) Обобщенный сигнал АС по АЗ1
	{&A0EE03LZ1,1,8},	//(A0EE03LZ1) Исправность АКНП3
	{&A0EE02LZ1,1,9},	//(A0EE02LZ1) Исправность АКНП2
	{&A0EE04LZ1,1,10},	//(A0EE04LZ1) Исправность АКНП4
	{&A0EE01LZ1,1,11},	//(A0EE01LZ1) Исправность АКНП1
	{&R0VN80LZ1,1,12},	//(R0VN80LZ1) АЗ по АС периода разгона РУ
	{&R0VN70LZ1,1,13},	//(R0VN70LZ1) АЗ по АС мощности РУ
	{&R0VZ71LZ1,1,14},	//(R0VZ71LZ1) Обобщенный сигнал АЗ 1 канала
	{&R0AD16LZ1,1,15},	//(R0AD16LZ1) Имитация АЗ от 1УР (датчик2)
	{&R0AD15LZ1,1,16},	//(R0AD15LZ1) Имитация АЗ от 1УР (датчик1)
	{&B0VT71LZ1,1,17},	//(B0VT71LZ1) АС по температуре в АЗ2
	{&B0VT61LZ1,1,18},	//(B0VT61LZ1) ПС по температуре в АЗ2
	{&R0VP73LZ1,1,19},	//(R0VP73LZ1) ПС давления для РУ
	{&B0VP71LZ1,1,20},	//(B0VP71LZ1) АЗ по АС любого давления для АЗ2
	{&A0VP71LZ1,1,21},	//(A0VP71LZ1) АЗ по АС любого давления для АЗ1
	{&R0ET02LZ1,1,22},	//(R0ET02LZ1) Признак наличия неисправности по температуре АЗ2
	{&R0VP41LZ1,1,23},	//(R0VP41LZ1) АС по давлению в СИСТЕМЕ
	{&B0VP41LZ1,1,24},	//(B0VP41LZ1) Давление АЗ2 ниже АС
	{&A0VP41LZ1,1,25},	//(A0VP41LZ1) Давление АЗ1 ниже АС
	{&R0ET01LZ1,1,26},	//(R0ET01LZ1) Признак наличия неисправности по температуре  АЗ1
	{&A2VP81LZ1,1,27},	//(A2VP81LZ1) Давление СБРОС РБ1 в норме
	{&B2VP81LZ1,1,28},	//(B2VP81LZ1) Давление СБРОС РБ2 в норме
	{&B2VP51LZ1,1,29},	//(B2VP51LZ1) Давление СБРОС РБ2 ниже ПС
	{&B2VP41LZ1,1,30},	//(B2VP41LZ1) Давление СБРОС РБ2 ниже АС
	{&A2VP51LZ1,1,31},	//(A2VP51LZ1) Давление СБРОС РБ1 ниже ПС
	{&A2VP41LZ1,1,32},	//(A2VP41LZ1) Давление СБРОС РБ1 ниже АС
	{&B1VP41LZ1,1,33},	//(B1VP41LZ1) Давление СБРОС ББ2 ниже АС
	{&A1VP41LZ1,1,34},	//(A1VP41LZ1) Давление СБРОС ББ1 ниже АС
	{&A0VT71LZ1,1,35},	//(A0VT71LZ1) АС по температуре в АЗ1
	{&A0VT61LZ1,1,36},	//(A0VT61LZ1) ПС по температуре в АЗ1
	{&R0VN79LZ1,1,37},	//(R0VN79LZ1) АС по усредненному периоду
	{&R0VN69LZ1,1,38},	//(R0VN69LZ1) ПС по усредненному периоду
	{&B3VZ11LZ1,1,39},	//(B3VZ11LZ1) АЗ от НУП ИС2
	{&A3VZ11LZ1,1,40},	//(A3VZ11LZ1) АЗ от НУП ИС1
	{&B3VZ31LZ1,1,41},	//(B3VZ31LZ1) АЗ от ВУ ИС2
	{&A3VZ31LZ1,1,42},	//(A3VZ31LZ1) АЗ от ВУ ИС1
	{&R0VN68LZ1,1,43},	//(R0VN68LZ1) ПС по периоду разгона канал 4
	{&R0VN67LZ1,1,44},	//(R0VN67LZ1) ПС по периоду разгона канал 3
	{&R0VN66LZ1,1,45},	//(R0VN66LZ1) ПС по периоду разгона канал 2
	{&R0VN65LZ1,1,46},	//(R0VN65LZ1) ПС по периоду разгона канал 1
	{&R0VN64LZ1,1,47},	//(R0VN64LZ1) ПС по мощности канал 4
	{&R0VN63LZ1,1,48},	//(R0VN63LZ1) ПС по мощности канал 3
	{&R0VN62LZ1,1,49},	//(R0VN62LZ1) ПС по мощности канал 2
	{&R0VN61LZ1,1,50},	//(R0VN61LZ1) ПС по мощности канал 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_Baz1[]={  // 
	{&R0VZ05UZ1,5,0},	//(R0VZ05UZ1) Индикатор причины сброса
	{&R0VR02RZ1,8,2},	//(R0VR02RZ1) Усредненная реактивность
	{&B0CT01IZ1,8,4},	//(B0CT01IZ1) Температура АЗ2-1
	{&R0VN11RZ1,8,6},	//(R0VN11RZ1) Средняя мощность по БАЗ1
	{&A0EP02IZ1,3,8},	//(A0EP02IZ1) Индикатор -Давление  АЗ1 ниже АС
	{&B0EP02IZ1,3,9},	//(B0EP02IZ1) Индикатор -Давление  АЗ2 ниже АС
	{&B2CP01RZ1,8,10},	//(B2CP01RZ1) Текущее давление СБРОС РБ2
	{&A2CP01RZ1,8,12},	//(A2CP01RZ1) Текущее давление СБРОС РБ1
	{&A0CT01IZ1,8,14},	//(A0CT01IZ1) Температура АЗ1-1
	{&R0VN09RZ1,8,16},	//(R0VN09RZ1) Усредненный период разгона
	{&R0VN08RZ1,8,18},	//(R0VN08RZ1) Период разгона по каналу 4
	{&R0VN07RZ1,8,20},	//(R0VN07RZ1) Период разгона по каналу 3
	{&R0VN06RZ1,8,22},	//(R0VN06RZ1) Период разгона по каналу 2
	{&R0VN05RZ1,8,24},	//(R0VN05RZ1) Период разгона по каналу 1
	{&R0VN04RZ1,8,26},	//(R0VN04RZ1) Уровень мощности по каналу 4
	{&R0VN03RZ1,8,28},	//(R0VN03RZ1) Уровень мощности по каналу 3
	{&R0VN02RZ1,8,30},	//(R0VN02RZ1) Уровень мощности по каналу 2
	{&R0VN01RZ1,8,32},	//(R0VN01RZ1) Уровень мощности по каналу 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_Baz1[]={  // 
	{&R0MW12IP2,3,0},	//(R0MW12IP2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
	{&fEM_R7UI73RZZ,8,1},	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
	{&fEM_A1UL11RZZ,8,3},	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
	{&fEM_A1UL12RZZ,8,5},	//(A1UL12RZZ) Время задержки АЗ от НУ ИС(сек)
	{&fEM_R0UR04RZZ,8,7},	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
	{&fEM_R0UR01RZZ,8,9},	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
	{&fEM_A2UP83RZZ,8,11},	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
	{&fEM_A2UP52RZZ,8,13},	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
	{&fEM_A2UP82RZZ,8,15},	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
	{&fEM_A2UP84RZZ,8,17},	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{&fEM_A2UP81RZZ,8,19},	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{&fEM_A2UP51RZZ,8,21},	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
	{&fEM_A2UP42RZZ,8,23},	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
	{&fEM_A2UP41RZZ,8,25},	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
	{&fEM_R0UT61RZZ,8,27},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{&fEM_R0UT62RZZ,8,29},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{&fEM_R0UT71RZZ,8,31},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{&fEM_R0UT72RZZ,8,33},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{&fEM_A2UP04RZZ,8,35},	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
	{&fEM_A2UP03RZZ,8,37},	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
	{&fEM_R0UT01RZZ,8,39},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{&fEM_R0UT02RZZ,8,41},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SBz1DU[]={  // 
	{&R0AD21LDU,1,0},	//(R0AD21LDU) Подключить защиту от II УР
	{&R0VW23LDU,1,1},	//(R0VW23LDU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,1,2},	//(R0VW13LDU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SBz1DU[]={  // 
	{&B0VT71LZ1,1,0},	//(B0VT71LZ1) АС по температуре в АЗ2
	{&R0VP73LZ1,1,1},	//(R0VP73LZ1) ПС давления для РУ
	{&B0VN71LZ1,1,2},	//(B0VN71LZ1) АЗ по АС мощности  АЗ2
	{&A0VN71LZ1,1,3},	//(A0VN71LZ1) АЗ по АС мощности  АЗ1
	{&A0EE03LZ1,1,4},	//(A0EE03LZ1) Исправность АКНП3
	{&A0EE02LZ1,1,5},	//(A0EE02LZ1) Исправность АКНП2
	{&A0EE04LZ1,1,6},	//(A0EE04LZ1) Исправность АКНП4
	{&A0EE01LZ1,1,7},	//(A0EE01LZ1) Исправность АКНП1
	{&B0VP71LZ1,1,8},	//(B0VP71LZ1) АЗ по АС любого давления для АЗ2
	{&A0VP71LZ1,1,9},	//(A0VP71LZ1) АЗ по АС любого давления для АЗ1
	{&A0VT71LZ1,1,10},	//(A0VT71LZ1) АС по температуре в АЗ1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SBz1DU[]={  // 
	{&B0CT01IZ1,8,0},	//(B0CT01IZ1) Температура АЗ2-1
	{&R0VN11RZ1,8,2},	//(R0VN11RZ1) Средняя мощность по БАЗ1
	{&R0VN09RZ1,8,4},	//(R0VN09RZ1) Усредненный период разгона
	{&A0CT01IZ1,8,6},	//(A0CT01IZ1) Температура АЗ1-1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SBz1DU[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_MBz1S[]={  // 
	{&R0EE04LZ1,1,0},	//(R0EE04LZ1) Питание  АКНП4  отключить
	{&R0EE03LZ1,1,1},	//(R0EE03LZ1) Питание  АКНП3  отключить
	{&R0EE02LZ1,1,2},	//(R0EE02LZ1) Питание  АКНП  отключить
	{&R0EE01LZ1,1,3},	//(R0EE01LZ1) Питание  АКНП1  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MBz1S[]={  // 
	{&R0VN65LS4,1,0},	//(R0VN65LS4) ПС по периоду разгона канал 4
	{&R0VN61LS4,1,1},	//(R0VN61LS4) ПС по мощности канал 4
	{&R0VN65LS3,1,2},	//(R0VN65LS3) ПС по периоду разгона канал 3
	{&R0VN61LS3,1,3},	//(R0VN61LS3) ПС по мощности канал 3
	{&R0VN65LS2,1,4},	//(R0VN65LS2) ПС по периоду разгона канал 2
	{&R0VN61LS2,1,5},	//(R0VN61LS2) ПС по мощности канал 2
	{&R0VN65LS1,1,6},	//(R0VN65LS1) ПС по периоду разгона канал1
	{&R0VN61LS1,1,7},	//(R0VN61LS1) ПС по мощности канал1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz1S[]={  // 
	{&B2IP01IZ1,3,0},	//(B2IP01IZ1) Текущее давление СБРОС РБ2
	{&A2IP01IZ1,3,1},	//(A2IP01IZ1) Текущее давление СБРОС РБ1
	{&B0IT01IZ1,3,2},	//(B0IT01IZ1) Температура АЗ2-1
	{&A0IT01IZ1,3,3},	//(A0IT01IZ1) Температура АЗ1-1
	{&R0VN01RS4,8,4},	//(R0VN01RS4) Период разгона канал 4
	{&R0VN02RS4,8,6},	//(R0VN02RS4) Уровень мощности канал 4
	{&R0VN01RS3,8,8},	//(R0VN01RS3) Период разгона канал 3
	{&R0VN02RS3,8,10},	//(R0VN02RS3) Уровень мощности канал 3
	{&R0VN01RS2,8,12},	//(R0VN01RS2) Период разгона канал 2
	{&R0VN02RS2,8,14},	//(R0VN02RS2) Уровень мощности канал 2
	{&R0VN01RS1,8,16},	//(R0VN01RS1) Период разгона канал1
	{&R0VN02RS1,8,18},	//(R0VN02RS1) Уровень мощности канал1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MBz1S[]={  // 
	{NULL,0,0},
};
#pragma pop
static char MBz1S_ip1[]={"192.168.10.60\0"};
static char MBz1S_ip2[]={"192.168.10.60\0"};
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,502,&coil_Baz1[0],&di_Baz1[0],&ir_Baz1[0],&hr_Baz1[0],NULL,NULL,NULL,0},	 //Общий слэйв
	{0,503,&coil_SBz1DU[0],&di_SBz1DU[0],&ir_SBz1DU[0],&hr_SBz1DU[0],NULL,NULL,NULL,0},	 //Слэйв для DU
	{1,503,&coil_MBz1S[0],&di_MBz1S[0],&ir_MBz1S[0],&hr_MBz1S[0],NULL,MBz1S_ip1,MBz1S_ip2,100},	 //Мастер Баз1 в SCM

	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},};
#pragma pop
#include <fp8/drivers/vas84r.h>
static char buf_VAS84[26];	//VAS84
static vas84r_inipar ini_VAS84={172,255,1,8,0xff,0,16,};
#pragma pack(push,1)
static table_drv table_VAS84={0,0,&ini_VAS84,buf_VAS84,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VAS84[]={
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS321[64];	//VDS32
static vds32r_inipar ini_VDS321={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS321={0,0,&ini_VDS321,buf_VDS321,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS321[]={
	{&B2IS12LZ1,1,20},
	{&R0AD05LZ1,1,16},
	{&A0EE01LS1,1,4},
	{&A0VN71LS1,1,6},
	{&R0VN71LZ1,1,0},
	{&R0VN75LZ1,1,2},
	{&A2IS12LZ1,1,18},
	{&R0AD03LZ1,1,12},
	{&A3IS22LZ1,1,10},
	{&A3IS11LZ1,1,8},
	{&R0AD04LZ1,1,14},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS322[64];	//VDS32
static vds32r_inipar ini_VDS322={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS322={0,0,&ini_VDS322,buf_VDS322,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS322[]={
	{&A0EE01LS2,1,4},
	{&B3IS11LZ1,1,8},
	{&B3IS22LZ1,1,10},
	{&R0VN72LZ1,1,0},
	{&R0VN76LZ1,1,2},
	{&A0VN71LS2,1,6},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS323[64];	//VDS32
static vds32r_inipar ini_VDS323={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS323={0,0,&ini_VDS323,buf_VDS323,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS323[]={
	{&R6IS66LZ1,1,8},
	{&R6IS67LZ1,1,10},
	{&R6IS68LZ1,1,12},
	{&A0VN71LS4,1,6},
	{&A0EE01LS4,1,4},
	{&R0VN74LZ1,1,0},
	{&R0VN78LZ1,1,2},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS324[64];	//VDS32
static vds32r_inipar ini_VDS324={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS324={0,0,&ini_VDS324,buf_VDS324,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS324[]={
	{&R0VN77LZ1,1,2},
	{&R0VN73LZ1,1,0},
	{&B0VP81LZ1,1,22},
	{&A0VP81LZ1,1,16},
	{&R0VP81LZ1,1,20},
	{&R7II73LZ1,1,12},
	{&A0VN71LS3,1,6},
	{&R7II71LZ1,1,8},
	{&R7II72LZ1,1,10},
	{&A0EE01LS3,1,4},
	{&A1VP81LZ1,1,18},
	{&B1VP81LZ1,1,24},
	{&R0VP82LZ1,1,26},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS16[38];	//FDS16
static fds16r_inipar ini_FDS16={0x04,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS16={0,0,&ini_FDS16,buf_FDS16,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS16[]={
	{&R0AD14LZ1,1,4},
	{&A3VZ13LZ1,1,0},
	{&A3VZ15LZ1,1,2},
	{&A1VN71LZ1,1,6},
	{&A3IS11LDU,1,18},
	{&R0VZ71LZ1,1,8},
	{&A3IS22LDU,1,20},
	{&A3IS11LZ2,1,22},
	{&OERB1Z1,1,14},
	{&OERB2Z1,1,16},
	{&OEBB2Z1,1,12},
	{&OEBB1Z1,1,10},
	{&A1VP81LZ2,1,28},
	{&A0VP81LZ2,1,26},
	{&A3IS22LZ2,1,24},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0xc6,0x04,7,26,def_buf_VAS84,&table_VAS84}, //VAS84
	{0xc2,0x05,15,64,def_buf_VDS321,&table_VDS321}, //VDS32
	{0xc2,0x06,15,64,def_buf_VDS322,&table_VDS322}, //VDS32
	{0xc2,0x07,15,64,def_buf_VDS323,&table_VDS323}, //VDS32
	{0xc2,0x08,15,64,def_buf_VDS324,&table_VDS324}, //VDS32
	{0x04,0x0a,20,38,def_buf_FDS16,&table_FDS16}, //FDS16
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
	setAsFloat(161,600);
	setAsFloat(162,0);
	setAsFloat(163,1.6);
	setAsFloat(164,0);
	setAsFloat(165,150);
	setAsFloat(166,200);
	setAsFloat(167,90);
	setAsFloat(168,100);
	setAsFloat(169,0.1);
	setAsFloat(170,0.13);
	setAsFloat(171,0.16);
	setAsFloat(172,0.17);
	setAsFloat(173,0.31);
	setAsFloat(174,0.2);
	setAsFloat(175,0.19);
	setAsFloat(176,0.28);
	setAsFloat(177,15);
	setAsFloat(178,10);
	setAsFloat(179,0.180);
	setAsFloat(180,0.020);
	setAsFloat(181,0.045);
}
/* Определение внутренних параметров */
uspaint8 InternalBuf[99];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssbool lRM_0_ = {0,0}; /* A-Граница участка насыщения А */ 
ssbool lRM_1_ = {1,0}; /* B-Граница участка насыщения В */ 
sslong dRM_0_ = {0,0}; /* lx вход лонг */ 
sschar bRM_0_ = {0,0}; /* cx вход байтовый */ 
ssint iRM_0_ = {0,0}; /* ix вход целый */ 
ssint iRM_4_ = {4,0}; /* N-число входов */ 
ssint iRM_3_ = {3,0}; /* mk - минимальное количество корректных данных */ 
ssint iRM_6_ = {6,0}; /* N-число входов */ 
ssint iRM_17_ = {17,0}; /* n - размерность массива входных сигналов */ 
ssint iRM_819_ = {819,0}; /* a */ 
ssint iRM_4095_ = {4095,0}; /* b */ 
ssfloat fRM_0_00001 = {0.00001,0}; /* X2 */ 
ssint iRM_200_ = {200,0}; /* tz - ширина импульса, 10-ки мс */ 
ssfloat fRM_0_2 = {0.2,0}; /* tz - время задержки сек */ 
ssfloat fRM_1_0 = {1.0,0}; /* tz - время задержки сек */ 
ssint iRM_7_ = {7,0}; /* n - N-размерность массива x */ 
ssfloat fRM_0_002 = {0.002,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_005 = {0.005,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_007 = {0.007,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_01 = {0.01,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_015 = {0.015,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_02 = {0.02,0}; /* x - массив входных параметров */ 
ssfloat fRM_1_7 = {1.7,0}; /* x - массив входных параметров */ 

uspaint8 SpaEEPROMBuf[105];

/* Определение переменных */
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
ssbool var100;
ssbool var101;
ssbool var102;
ssbool var103;
ssbool var104;
ssbool var105;
ssbool var106;
ssbool var107;
ssbool var108;
ssbool var109;
ssbool var110;
ssbool var111;
ssbool var112;
ssbool var113;
ssbool var114;
ssbool var115;
ssbool var116;
ssbool var117;
ssbool var118;
ssbool var119;
ssbool var120;
ssbool var121;
ssbool var122;
ssbool var123;
ssbool var124;
ssbool var125;
ssbool var126;
ssbool var127;
ssfloat var128;
ssfloat var129;
ssbool var130;
ssfloat var131;
ssfloat var132;
ssbool var133;
ssbool var134;
ssbool var135;
ssbool var136;
ssbool var137;
ssbool var138;
ssfloat var139;
sslong var140;
sslong var141;
ssbool var142;
ssbool var143;
ssbool var144;
ssbool var145;
ssbool var146;
ssbool var147;
ssbool var148;
ssbool var149;
ssbool var150;
ssfloat var151;
ssbool var152;
ssbool var153;
ssfloat var154;
ssbool var155;
ssbool var156;
sschar var157;
ssbool var158;
sschar var159;
ssbool var160;
ssbool var161;
ssbool var162;
ssbool var163;
ssbool var164;
ssbool var165;
ssbool var166;
ssbool var167;
ssbool var168;
ssbool var169;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psfloat  array_m195_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psfloat  array_m340_x_1[4] = {&R0VN02RS1,&R0VN02RS2,&R0VN02RS3,&R0VN02RS4};
psbool  array_m340_diag_1[4] = {&var21,&var22,&var23,&var24};
psbool  array_m319_x_1[17] = {&var83,&var49,&var50,&var78,&var33,&var36,&var156,&var48,&var44,&var43,&var79,&var37,&var39,&var158,&var47,&var46,&var45};
psbool  array_m16_x_1[6] = {&var88,&var79,&var37,&var39,&var97,&var158};
psbool  array_m36_x_1[6] = {&var78,&var33,&var36,&var156,&var86,&var97};
psfloat  array_m2_x_1[4] = {&R0VN01RS1,&R0VN01RS2,&R0VN01RS3,&R0VN01RS4};
psbool  array_m2_diag_1[4] = {&var21,&var22,&var23,&var24};
psbool  array_m3_x_1[4] = {&var108,&var109,&var19,&var138};
psbool  array_m12_x_1[4] = {&var107,&var109,&var110,&var20};

/* Объявление структур */
_S_ma  S_ma_195_1 = {array_m195_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_and3  S_and3_241_1 = {&var4,&var14,&var13,&var1};
_S_and3  S_and3_238_1 = {&var14,&var4,&var125,&var2};
_S_and3  S_and3_237_1 = {&var13,&var4,&var124,&var3};
_S_noto  S_noto_229_1 = {&R0AD03LZ1,&var4};
_S_and3  S_and3_235_1 = {&var7,&var10,&var9,&var5};
_S_and3  S_and3_231_1 = {&var7,&var9,&var127,&var6};
_S_noto  S_noto_223_1 = {&R0AD05LZ1,&var7};
_S_and3  S_and3_230_1 = {&var7,&var10,&var126,&var8};
_S_and2  S_and2_224_1 = {&var101,&R0VW23LDU,&var9};
_S_and2  S_and2_222_1 = {&var102,&R0VW13LDU,&var10};
_S_and3  S_and3_216_1 = {&var102,&var101,&R0AD05LZ1,&var11};
_S_and3  S_and3_221_1 = {&var100,&var99,&R0AD03LZ1,&var12};
_S_and2  S_and2_225_1 = {&var100,&R0VW13LDU,&var13};
_S_and2  S_and2_226_1 = {&R0VW23LDU,&var99,&var14};
_S_and2  S_and2_260_1 = {&var123,&var31,&var15};
_S_zzfs  S_zzfs_253_1 = {&R0AD14LDU,&fRM_1_0,&var16,&internal1_m253_tx,&internal1_m253_y0};
_S_and2  S_and2_133_1 = {&var161,&var137,&var17};
_S_and2  S_and2_140_1 = {&var160,&var136,&var18};
_S_or2  S_or2_111_1 = {&var167,&var165,&var19};
_S_or2  S_or2_117_1 = {&var162,&var163,&var20};
_S_and2  S_and2_82_1 = {&A0EE05LZ1,&A0EE01LS1,&var21};
_S_and2  S_and2_84_1 = {&A0EE06LZ1,&A0EE01LS2,&var22};
_S_and2  S_and2_86_1 = {&A0EE07LZ1,&A0EE01LS3,&var23};
_S_and2  S_and2_88_1 = {&A0EE08LZ1,&A0EE01LS4,&var24};
_S_and2  S_and2_185_1 = {&var153,&var118,&var25};
_S_and2  S_and2_186_1 = {&var152,&var118,&var26};
_S_or2  S_or2_264_1 = {&var104,&R7II73LZ1,&var27};
_S_or2  S_or2_266_1 = {&R0AD21LDU,&R0AD14LDU,&var28};
_S_and2  S_and2_265_1 = {&var28,&var27,&var29};
_S_or2  S_or2_258_1 = {&R7II71LZ1,&var103,&var30};
_S_or3  S_or3_259_1 = {&var32,&var30,&var29,&var31};
_S_or2  S_or2_252_1 = {&var105,&R7II72LZ1,&var32};
_S_or2  S_or2_239_1 = {&var8,&var5,&var33};
_S_or2  S_or2_208_1 = {&A3IS22LZ1,&R0AD05LZ1,&var34};
_S_or2  S_or2_210_1 = {&B3IS22LZ1,&R0AD05LZ1,&var35};
_S_or2  S_or2_242_1 = {&var3,&var1,&var36};
_S_or2  S_or2_243_1 = {&var2,&var1,&var37};
_S_or2  S_or2_211_1 = {&var122,&R0AD03LZ1,&var38};
_S_or2  S_or2_240_1 = {&var6,&var5,&var39};
_S_or2  S_or2_213_1 = {&var121,&R0AD03LZ1,&var40};
_S_schl24  S_schl24_342_1 = {&A0VN71LS2,&A0VN71LS1,&A0VN71LS4,&A0VN71LS3,&var41};
_S_and2  S_and2_332_1 = {&var117,&var116,&var42};
_S_and2  S_and2_321_1 = {&var62,&var84,&var43};
_S_and2  S_and2_323_1 = {&var69,&var84,&var44};
_S_and2  S_and2_329_1 = {&var29,&var98,&var45};
_S_and2  S_and2_328_1 = {&var30,&var98,&var46};
_S_and2  S_and2_327_1 = {&var32,&var98,&var47};
_S_and2  S_and2_325_1 = {&var119,&var84,&var48};
_S_and2  S_and2_322_1 = {&var73,&var84,&var49};
_S_and2  S_and2_320_1 = {&var55,&var84,&var50};
_S_and2  S_and2_306_1 = {&var53,&var52,&var51};
_S_or2  S_or2_308_1 = {&R0VN75LZ1,&var150,&var52};
_S_or2  S_or2_309_1 = {&R0VN77LZ1,&var149,&var53};
_S_or2  S_or2_294_1 = {&var51,&var59,&var54};
_S_or2  S_or2_300_1 = {&var56,&var51,&var55};
_S_and2  S_and2_301_1 = {&var145,&var60,&var56};
_S_or2  S_or2_311_1 = {&R0VN78LZ1,&var147,&var57};
_S_or2  S_or2_310_1 = {&R0VN76LZ1,&var148,&var58};
_S_and2  S_and2_307_1 = {&var58,&var57,&var59};
_S_schl24  S_schl24_305_1 = {&var58,&var57,&var53,&var52,&var60};
_S_and2  S_and2_303_1 = {&var84,&var60,&var61};
_S_or2  S_or2_302_1 = {&var59,&var56,&var62};
_S_and2  S_and2_298_1 = {&var62,&var84,&var63};
_S_or2  S_or2_274_1 = {&R0VN72LZ1,&var148,&var64};
_S_and2  S_and2_289_1 = {&var73,&var84,&var65};
_S_and2  S_and2_277_1 = {&var64,&var67,&var66};
_S_or2  S_or2_275_1 = {&R0VN74LZ1,&var147,&var67};
_S_and2  S_and2_290_1 = {&var69,&var84,&var68};
_S_or2  S_or2_287_1 = {&var66,&var72,&var69};
_S_or2  S_or2_293_1 = {&var74,&var66,&var70};
_S_and2  S_and2_281_1 = {&var76,&var84,&var71};
_S_and2  S_and2_286_1 = {&var146,&var76,&var72};
_S_or2  S_or2_285_1 = {&var74,&var72,&var73};
_S_and2  S_and2_276_1 = {&var75,&var77,&var74};
_S_or2  S_or2_273_1 = {&R0VN73LZ1,&var149,&var75};
_S_schl24  S_schl24_279_1 = {&var75,&var77,&var64,&var67,&var76};
_S_or2  S_or2_272_1 = {&R0VN71LZ1,&var150,&var77};
_S_or2  S_or2_157_1 = {&var130,&var168,&var78};
_S_or2  S_or2_159_1 = {&var135,&var133,&var79};
_S_or2  S_or2_352_1 = {&var166,&var164,&var80};
_S_or2  S_or2_35_1 = {&A2IS12LZ1,&B2IS12LZ1,&var81};
_S_and2  S_and2_297_1 = {&var84,&var55,&var82};
_S_and2  S_and2_326_1 = {&var120,&var84,&var83};
_S_and2  S_and2_21_1 = {&var115,&var111,&var84};
_S_or2  S_or2_25_1 = {&var143,&var142,&var85};
_S_and2  S_and2_31_1 = {&var87,&var84,&var86};
_S_or3  S_or3_30_1 = {&var55,&var73,&var114,&var87};
_S_and2  S_and2_19_1 = {&var84,&var89,&var88};
_S_or3  S_or3_18_1 = {&var69,&var62,&var113,&var89};
_S_and2  S_and2_6_1 = {&var22,&var24,&var90};
_S_or2  S_or2_11_1 = {&var144,&var90,&var91};
_S_or2  S_or2_10_1 = {&var93,&var144,&var92};
_S_and2  S_and2_5_1 = {&var21,&var23,&var93};
_S_and2  S_and2_197_1 = {&R0AD14LDU,&R7II72LZ1,&var94};
_S_and2  S_and2_192_1 = {&R0AD14LDU,&R7II71LZ1,&var95};
_S_and2  S_and2_189_1 = {&R0AD14LDU,&R7II73LZ1,&var96};
_S_zpfs  S_zpfs_261_1 = {&var15,&fEM_R7UI73RZZ,&var97,&internal1_m261_tx,&internal1_m261_y0};
_S_zpfs  S_zpfs_324_1 = {&var42,&fRM_0_2,&var98,&internal1_m324_tx,&internal1_m324_y0};
_S_zpfs  S_zpfs_220_1 = {&var40,&fEM_A1UL11RZZ,&var99,&internal1_m220_tx,&internal1_m220_y0};
_S_zpfs  S_zpfs_219_1 = {&var38,&fEM_A1UL11RZZ,&var100,&internal1_m219_tx,&internal1_m219_y0};
_S_zpfs  S_zpfs_217_1 = {&var35,&fEM_A1UL12RZZ,&var101,&internal1_m217_tx,&internal1_m217_y0};
_S_zpfs  S_zpfs_215_1 = {&var34,&fEM_A1UL12RZZ,&var102,&internal1_m215_tx,&internal1_m215_y0};
_S_noto  S_noto_257_1 = {&R6IS67LZ1,&var103};
_S_noto  S_noto_263_1 = {&R6IS68LZ1,&var104};
_S_noto  S_noto_246_1 = {&R6IS66LZ1,&var105};
_S_and2  S_and2_101_1 = {&R0VP81LZ1,&R0VP82LZ1,&var106};
_S_noto  S_noto_136_1 = {&B0VP81LZ1,&var107};
_S_noto  S_noto_135_1 = {&A0VP81LZ1,&var108};
_S_noto  S_noto_104_1 = {&var106,&var109};
_S_noto  S_noto_100_1 = {&B1VP81LZ1,&var110};
_S_noto  S_noto_27_1 = {&var112,&var111};
_S_ovb1  S_ovb1_33_1 = {&var81,&iRM_200_,&var112,&internal1_m33_tx};
_S_noto  S_noto_14_1 = {&var91,&var113};
_S_noto  S_noto_13_1 = {&var92,&var114};
_S_noto  S_noto_24_1 = {&R0EE02LDU,&var115};
_S_noto  S_noto_334_1 = {&R0AD16LDU,&var116};
_S_noto  S_noto_333_1 = {&R0AD04LZ1,&var117};
_S_bol  S_bol_181_1 = {&var154,&fRM_0_00001,&var118};
_S_noto  S_noto_330_1 = {&var91,&var119};
_S_noto  S_noto_331_1 = {&var92,&var120};
_S_noto  S_noto_207_1 = {&B3IS11LZ1,&var121};
_S_noto  S_noto_206_1 = {&A3IS11LZ1,&var122};
_S_noto  S_noto_254_1 = {&var16,&var123};
_S_noto  S_noto_233_1 = {&R0VW23LDU,&var124};
_S_noto  S_noto_232_1 = {&R0VW13LDU,&var125};
_S_noto  S_noto_228_1 = {&R0VW23LDU,&var126};
_S_noto  S_noto_227_1 = {&R0VW13LDU,&var127};
_S_scalzz  S_scalzz_150_1 = {&B0IT01IZ1,&iRM_819_,&iRM_4095_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var128,&internal1_m150_y0};
_S_scalzz  S_scalzz_148_1 = {&A0IT01IZ1,&iRM_819_,&iRM_4095_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var129,&internal1_m148_y0};
_S_geterr  S_geterr_152_1 = {&var129,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var130};
_S_scalzz  S_scalzz_97_1 = {&B2IP01IZ1,&iRM_819_,&iRM_4095_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var131,&internal1_m97_y0};
_S_scalzz  S_scalzz_95_1 = {&A2IP01IZ1,&iRM_819_,&iRM_4095_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var132,&internal1_m95_y0};
_S_drg  S_drg_161_1 = {&var128,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var133,&internal1_m161_y1};
_S_drg  S_drg_172_1 = {&var128,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var134,&internal1_m172_y1};
_S_geterr  S_geterr_154_1 = {&var128,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var135};
_S_noto  S_noto_141_1 = {&var162,&var136};
_S_noto  S_noto_132_1 = {&var167,&var137};
_S_noto  S_noto_99_1 = {&A1VP81LZ1,&var138};
_S_srm  S_srm_340_1 = {array_m340_x_1,array_m340_diag_1,&iRM_4_,&iRM_3_,&var139,&vainSBool};
_S_rsu  S_rsu_317_1 = {&R0MD34LP1,&var141,&var140,&internal1_m317_q0};
_S_orni  S_orni_319_1 = {array_m319_x_1,&iRM_17_,&vainSBool,&var141};
_S_orn  S_orn_16_1 = {array_m16_x_1,&iRM_6_,&var142};
_S_orn  S_orn_36_1 = {array_m36_x_1,&iRM_6_,&var143};
_S_noto  S_noto_7_1 = {&var155,&var144};
_S_noto  S_noto_296_1 = {&var54,&var145};
_S_noto  S_noto_291_1 = {&var70,&var146};
_S_noto  S_noto_280_1 = {&A0EE01LS4,&var147};
_S_noto  S_noto_284_1 = {&A0EE01LS2,&var148};
_S_noto  S_noto_283_1 = {&A0EE01LS3,&var149};
_S_noto  S_noto_278_1 = {&A0EE01LS1,&var150};
_S_react  S_react_177_1 = {&var154,&var151};
_S_bol  S_bol_182_1 = {&fEM_R0UR04RZZ,&var154,&var152};
_S_bol  S_bol_180_1 = {&fEM_R0UR01RZZ,&var154,&var153};
_S_srm  S_srm_2_1 = {array_m2_x_1,array_m2_diag_1,&iRM_4_,&iRM_3_,&var154,&var155};
_S_ornc  S_ornc_3_1 = {array_m3_x_1,&iRM_4_,&var156,&var157};
_S_ornc  S_ornc_12_1 = {array_m12_x_1,&iRM_4_,&var158,&var159};
_S_tprg  S_tprg_137_1 = {&var131,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var160,&internal1_m137_y0};
_S_tprg  S_tprg_130_1 = {&var132,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var161,&internal1_m130_y0};
_S_geterr  S_geterr_108_1 = {&var131,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var162};
_S_drg  S_drg_109_1 = {&var131,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var163,&internal1_m109_y1};
_S_drg  S_drg_123_1 = {&var131,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var164,&internal1_m123_y1};
_S_drg  S_drg_102_1 = {&var132,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var165,&internal1_m102_y1};
_S_drg  S_drg_112_1 = {&var132,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var166,&internal1_m112_y1};
_S_geterr  S_geterr_105_1 = {&var132,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var167};
_S_drg  S_drg_158_1 = {&var129,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var168,&internal1_m158_y1};
_S_drg  S_drg_170_1 = {&var129,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var169,&internal1_m170_y1};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  noto(&S_noto_278_1);
  noto(&S_noto_283_1);
  noto(&S_noto_284_1);
  noto(&S_noto_280_1);
  noto(&S_noto_99_1);
  scalzz(&S_scalzz_95_1);
  scalzz(&S_scalzz_97_1);
  scalzz(&S_scalzz_148_1);
  scalzz(&S_scalzz_150_1);
  noto(&S_noto_228_1);
  noto(&S_noto_232_1);
  noto(&S_noto_233_1);
  noto(&S_noto_206_1);
  noto(&S_noto_207_1);
  noto(&S_noto_24_1);
  noto(&S_noto_100_1);
  noto(&S_noto_135_1);
  noto(&S_noto_136_1);
  and2(&S_and2_101_1);
  noto(&S_noto_246_1);
  noto(&S_noto_263_1);
  noto(&S_noto_257_1);
  and2(&S_and2_189_1);
  and2(&S_and2_192_1);
  and2(&S_and2_197_1);
  or2(&S_or2_35_1);
  or2(&S_or2_272_1);
  or2(&S_or2_273_1);
  and2(&S_and2_276_1);
  or2(&S_or2_275_1);
  or2(&S_or2_274_1);
  or2(&S_or2_310_1);
  or2(&S_or2_311_1);
  or2(&S_or2_309_1);
  or2(&S_or2_308_1);
  and2(&S_and2_306_1);
  schl24(&S_schl24_342_1);
  or2(&S_or2_213_1);
  or2(&S_or2_211_1);
  or2(&S_or2_210_1);
  or2(&S_or2_208_1);
  or2(&S_or2_252_1);
  or2(&S_or2_258_1);
  or2(&S_or2_266_1);
  or2(&S_or2_264_1);
  and2(&S_and2_88_1);
  and2(&S_and2_86_1);
  and2(&S_and2_84_1);
  and2(&S_and2_82_1);
  zzfs(&S_zzfs_253_1);
  noto(&S_noto_223_1);
  noto(&S_noto_229_1);
  ma(&S_ma_195_1);
  drg(&S_drg_170_1);
  drg(&S_drg_158_1);
  geterr(&S_geterr_105_1);
  drg(&S_drg_112_1);
  drg(&S_drg_102_1);
  drg(&S_drg_123_1);
  drg(&S_drg_109_1);
  geterr(&S_geterr_108_1);
  tprg(&S_tprg_130_1);
  tprg(&S_tprg_137_1);
  srm(&S_srm_2_1);
  bol(&S_bol_180_1);
  bol(&S_bol_182_1);
  react(&S_react_177_1);
  noto(&S_noto_7_1);
  srm(&S_srm_340_1);
  noto(&S_noto_132_1);
  noto(&S_noto_141_1);
  geterr(&S_geterr_154_1);
  drg(&S_drg_172_1);
  drg(&S_drg_161_1);
  geterr(&S_geterr_152_1);
  noto(&S_noto_227_1);
  noto(&S_noto_254_1);
  bol(&S_bol_181_1);
  noto(&S_noto_333_1);
  noto(&S_noto_334_1);
  ovb1(&S_ovb1_33_1);
  noto(&S_noto_27_1);
  noto(&S_noto_104_1);
  zpfs(&S_zpfs_215_1);
  zpfs(&S_zpfs_217_1);
  zpfs(&S_zpfs_219_1);
  zpfs(&S_zpfs_220_1);
  and2(&S_and2_5_1);
  or2(&S_or2_10_1);
  and2(&S_and2_6_1);
  and2(&S_and2_21_1);
  or2(&S_or2_352_1);
  or2(&S_or2_159_1);
  or2(&S_or2_157_1);
  schl24(&S_schl24_279_1);
  and2(&S_and2_281_1);
  and2(&S_and2_277_1);
  schl24(&S_schl24_305_1);
  and2(&S_and2_307_1);
  or2(&S_or2_294_1);
  and2(&S_and2_332_1);
  and2(&S_and2_265_1);
  and2(&S_and2_186_1);
  and2(&S_and2_185_1);
  or2(&S_or2_117_1);
  or2(&S_or2_111_1);
  and2(&S_and2_140_1);
  and2(&S_and2_133_1);
  and2(&S_and2_226_1);
  and2(&S_and2_225_1);
  and3(&S_and3_221_1);
  and3(&S_and3_216_1);
  and2(&S_and2_222_1);
  and2(&S_and2_224_1);
  and3(&S_and3_230_1);
  and3(&S_and3_231_1);
  and3(&S_and3_235_1);
  and3(&S_and3_237_1);
  and3(&S_and3_238_1);
  and3(&S_and3_241_1);
  ornc(&S_ornc_12_1);
  ornc(&S_ornc_3_1);
  noto(&S_noto_296_1);
  noto(&S_noto_331_1);
  noto(&S_noto_13_1);
  zpfs(&S_zpfs_324_1);
  or2(&S_or2_11_1);
  and2(&S_and2_326_1);
  or2(&S_or2_293_1);
  and2(&S_and2_303_1);
  and2(&S_and2_301_1);
  or2(&S_or2_300_1);
  and2(&S_and2_320_1);
  and2(&S_and2_327_1);
  and2(&S_and2_328_1);
  and2(&S_and2_329_1);
  or2(&S_or2_240_1);
  or2(&S_or2_243_1);
  or2(&S_or2_242_1);
  or2(&S_or2_239_1);
  or3(&S_or3_259_1);
  and2(&S_and2_260_1);
  noto(&S_noto_291_1);
  noto(&S_noto_330_1);
  noto(&S_noto_14_1);
  zpfs(&S_zpfs_261_1);
  and2(&S_and2_297_1);
  and2(&S_and2_286_1);
  or2(&S_or2_287_1);
  and2(&S_and2_290_1);
  or2(&S_or2_302_1);
  and2(&S_and2_325_1);
  and2(&S_and2_323_1);
  and2(&S_and2_321_1);
  or3(&S_or3_18_1);
  and2(&S_and2_19_1);
  or2(&S_or2_285_1);
  and2(&S_and2_289_1);
  and2(&S_and2_298_1);
  and2(&S_and2_322_1);
  orn(&S_orn_16_1);
  orni(&S_orni_319_1);
  rsu(&S_rsu_317_1);
  or3(&S_or3_30_1);
  and2(&S_and2_31_1);
  orn(&S_orn_36_1);
  or2(&S_or2_25_1);
  setData(idR0AD16LZ1,&var94);
  setData(idR0AD15LZ1,&var95);
  moveData(idR0EE04LZ1,idR0EE02LDU);
  moveData(idR0EE03LZ1,idR0EE02LDU);
  moveData(idR0EE02LZ1,idR0EE02LDU);
  moveData(idR0EE01LZ1,idR0EE02LDU);
  setData(idR0AD14LZ1,&var96);
  setData(idA3VZ13LZ1,&var12);
  setData(idA3VZ15LZ1,&var11);
  setData(idA1VN71LZ1,&var41);
  setData(idB0VT71LZ1,&var79);
  setData(idB0VT61LZ1,&var134);
  setData(idB0CT01IZ1,&var128);
  setData(idR0VP73LZ1,&var80);
  setData(idR0VN11RZ1,&var139);
  setData(idR0VZ05UZ1,&var140);
  setData(idB0VN81LZ1,&var63);
  setData(idA0VN81LZ1,&var82);
  setData(idB0VN71LZ1,&var68);
  setData(idA0VN71LZ1,&var65);
  setData(idB0VZ71LZ1,&var142);
  setData(idB0EE00LZ1,&var91);
  setData(idA0EE00LZ1,&var92);
  setData(idA0VZ71LZ1,&var143);
  setData(idA0EE03LZ1,&var23);
  setData(idA0EE02LZ1,&var22);
  setData(idA0EE04LZ1,&var24);
  setData(idA0EE01LZ1,&var21);
  setData(idR0VN80LZ1,&var61);
  setData(idR0VN70LZ1,&var71);
  setData(idR0VZ71LZ1,&var85);
  setData(idR0VR02RZ1,&var151);
  setData(idR0VN79LZ1,&var26);
  setData(idR0VN69LZ1,&var25);
  setData(idB3VZ11LZ1,&var39);
  setData(idA3VZ11LZ1,&var33);
  setData(idB3VZ31LZ1,&var37);
  setData(idA3VZ31LZ1,&var36);
  setData(idR0VN09RZ1,&var154);
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
  setData(idB0VP71LZ1,&var158);
  setData(idA0VP71LZ1,&var156);
  setData(idA0EP02IZ1,&var157);
  setData(idB0EP02IZ1,&var159);
  setData(idR0ET02LZ1,&var135);
  setData(idR0VP41LZ1,&var109);
  setData(idB0VP41LZ1,&var107);
  setData(idA0VP41LZ1,&var108);
  setData(idR0ET01LZ1,&var130);
  setData(idA2VP81LZ1,&var17);
  setData(idB2VP81LZ1,&var18);
  setData(idB2VP51LZ1,&var164);
  setData(idB2CP01RZ1,&var131);
  setData(idB2VP41LZ1,&var20);
  setData(idA2VP51LZ1,&var166);
  setData(idA2CP01RZ1,&var132);
  setData(idA2VP41LZ1,&var19);
  setData(idB1VP41LZ1,&var110);
  setData(idA1VP41LZ1,&var138);
  setData(idA0VT71LZ1,&var78);
  setData(idA0VT61LZ1,&var169);
  setData(idA0CT01IZ1,&var129);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}

#endif
