#ifndef BAZ2_H
#define BAZ2_H
// Подсистема Baz2:Baz2
static char SimulOn=0;
static short CodeSub=7;
static char SimulIP[]="192.168.1.17\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 596
static char BUFFER[596];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.54\0", 5432, "192.168.10.154\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0VN11RZ2	 BUFFER[0]	//(R0VN11RZ2) Средняя мощность по БАЗ1
#define idR0VN11RZ2	 1	//(R0VN11RZ2) Средняя мощность по БАЗ1
#define R0VP73LZ2	 BUFFER[5]	//(R0VP73LZ2) ПС давления для РУ
#define idR0VP73LZ2	 2	//(R0VP73LZ2) ПС давления для РУ
#define B0CT01IZ2	 BUFFER[7]	//(B0CT01IZ2) Температура АЗ2-1
#define idB0CT01IZ2	 3	//(B0CT01IZ2) Температура АЗ2-1
#define B0VT61LZ2	 BUFFER[12]	//(B0VT61LZ2) ПС по температуре в АЗ2
#define idB0VT61LZ2	 4	//(B0VT61LZ2) ПС по температуре в АЗ2
#define B0VT71LZ2	 BUFFER[14]	//(B0VT71LZ2) АС по температуре в АЗ2
#define idB0VT71LZ2	 5	//(B0VT71LZ2) АС по температуре в АЗ2
#define A1VN71LS1	 BUFFER[16]	//(A1VN71LS1) Блокировка автоматического подъёма ББ канал 1
#define idA1VN71LS1	 6	//(A1VN71LS1) Блокировка автоматического подъёма ББ канал 1
#define A1VN71LS2	 BUFFER[18]	//(A1VN71LS2) Блокировка автоматического подъёма ББ канал 2
#define idA1VN71LS2	 7	//(A1VN71LS2) Блокировка автоматического подъёма ББ канал 2
#define A1VN71LS3	 BUFFER[20]	//(A1VN71LS3) Блокировка автоматического подъёма ББ канал 3
#define idA1VN71LS3	 8	//(A1VN71LS3) Блокировка автоматического подъёма ББ канал 3
#define A1VN71LS4	 BUFFER[22]	//(A1VN71LS4) Блокировка автоматического подъёма ББ канал 4
#define idA1VN71LS4	 9	//(A1VN71LS4) Блокировка автоматического подъёма ББ канал 4
#define A1VN71LZ2	 BUFFER[24]	//(A1VN71LZ2) Блокировка автоматического подъёма ББ
#define idA1VN71LZ2	 10	//(A1VN71LZ2) Блокировка автоматического подъёма ББ
#define A3VZ15LZ2	 BUFFER[26]	//(A3VZ15LZ2) Имитация АЗ от НУП ИС
#define idA3VZ15LZ2	 11	//(A3VZ15LZ2) Имитация АЗ от НУП ИС
#define A3VZ13LZ2	 BUFFER[28]	//(A3VZ13LZ2) Имитация АЗ от ВУ ИС
#define idA3VZ13LZ2	 12	//(A3VZ13LZ2) Имитация АЗ от ВУ ИС
#define R0VW13LDU	 BUFFER[30]	//(R0VW13LDU) Индикация выбора АЗ1 или АЗ1+АЗ2
#define idR0VW13LDU	 13	//(R0VW13LDU) Индикация выбора АЗ1 или АЗ1+АЗ2
#define R0VW23LDU	 BUFFER[32]	//(R0VW23LDU) Индикация выбора АЗ2 или АЗ1+АЗ2
#define idR0VW23LDU	 14	//(R0VW23LDU) Индикация выбора АЗ2 или АЗ1+АЗ2
#define R7II73LZ2	 BUFFER[34]	//(R7II73LZ2) Сработала АС II УР РАД
#define idR7II73LZ2	 15	//(R7II73LZ2) Сработала АС II УР РАД
#define R7II71LZ2	 BUFFER[36]	//(R7II71LZ2) Сработала АС IУР РАД (датчик 1)
#define idR7II71LZ2	 16	//(R7II71LZ2) Сработала АС IУР РАД (датчик 1)
#define R7II72LZ2	 BUFFER[38]	//(R7II72LZ2) Сработала АС IУР РАД (датчик 2)
#define idR7II72LZ2	 17	//(R7II72LZ2) Сработала АС IУР РАД (датчик 2)
#define R0AD21LDU	 BUFFER[40]	//(R0AD21LDU) Подключить защиту от II УР
#define idR0AD21LDU	 18	//(R0AD21LDU) Подключить защиту от II УР
#define R0MD34LP1	 BUFFER[42]	//(R0MD34LP1) Кнопка Квитировать
#define idR0MD34LP1	 19	//(R0MD34LP1) Кнопка Квитировать
#define R0AD14LDU	 BUFFER[44]	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 20	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
#define A1EE01LS3	 BUFFER[46]	//(A1EE01LS3) Исправность АКНП канал 3
#define idA1EE01LS3	 21	//(A1EE01LS3) Исправность АКНП канал 3
#define A0EE01LZ2	 BUFFER[48]	//(A0EE01LZ2) Исправность АКНП1
#define idA0EE01LZ2	 22	//(A0EE01LZ2) Исправность АКНП1
#define A0EE04LZ2	 BUFFER[50]	//(A0EE04LZ2) Исправность АКНП4
#define idA0EE04LZ2	 23	//(A0EE04LZ2) Исправность АКНП4
#define A0EE02LZ2	 BUFFER[52]	//(A0EE02LZ2) Исправность АКНП2
#define idA0EE02LZ2	 24	//(A0EE02LZ2) Исправность АКНП2
#define A0EE03LZ2	 BUFFER[54]	//(A0EE03LZ2) Исправность АКНП3
#define idA0EE03LZ2	 25	//(A0EE03LZ2) Исправность АКНП3
#define A1EE01LS2	 BUFFER[56]	//(A1EE01LS2) Исправность АКНП  канал 2
#define idA1EE01LS2	 26	//(A1EE01LS2) Исправность АКНП  канал 2
#define A0EE05LZ2	 BUFFER[58]	//(A0EE05LZ2) Исправность сети АКНП1
#define idA0EE05LZ2	 27	//(A0EE05LZ2) Исправность сети АКНП1
#define A0EE06LZ2	 BUFFER[60]	//(A0EE06LZ2) Исправность сети АКНП2
#define idA0EE06LZ2	 28	//(A0EE06LZ2) Исправность сети АКНП2
#define A0EE07LZ2	 BUFFER[62]	//(A0EE07LZ2) Исправность сети АКНП3
#define idA0EE07LZ2	 29	//(A0EE07LZ2) Исправность сети АКНП3
#define A0EE08LZ2	 BUFFER[64]	//(A0EE08LZ2) Исправность сети АКНП4
#define idA0EE08LZ2	 30	//(A0EE08LZ2) Исправность сети АКНП4
#define A0VZ71LZ2	 BUFFER[66]	//(A0VZ71LZ2) Обобщенный сигнал АС по АЗ1
#define idA0VZ71LZ2	 31	//(A0VZ71LZ2) Обобщенный сигнал АС по АЗ1
#define A0EE00LZ2	 BUFFER[68]	//(A0EE00LZ2) Исправность АКНП АЗ1
#define idA0EE00LZ2	 32	//(A0EE00LZ2) Исправность АКНП АЗ1
#define B0EE00LZ2	 BUFFER[70]	//(B0EE00LZ2) Исправность АКНП АЗ2
#define idB0EE00LZ2	 33	//(B0EE00LZ2) Исправность АКНП АЗ2
#define B0VZ71LZ2	 BUFFER[72]	//(B0VZ71LZ2) Обобщенный сигнал АС по АЗ2
#define idB0VZ71LZ2	 34	//(B0VZ71LZ2) Обобщенный сигнал АС по АЗ2
#define A0VN71LZ2	 BUFFER[74]	//(A0VN71LZ2) АЗ по АС мощности  АЗ1
#define idA0VN71LZ2	 35	//(A0VN71LZ2) АЗ по АС мощности  АЗ1
#define B0VN71LZ2	 BUFFER[76]	//(B0VN71LZ2) АЗ по АС мощности  АЗ2
#define idB0VN71LZ2	 36	//(B0VN71LZ2) АЗ по АС мощности  АЗ2
#define A0VN81LZ2	 BUFFER[78]	//(A0VN81LZ2) АЗ по АС периода разгона АЗ1
#define idA0VN81LZ2	 37	//(A0VN81LZ2) АЗ по АС периода разгона АЗ1
#define B0VN81LZ2	 BUFFER[80]	//(B0VN81LZ2) АЗ по АС периода разгона АЗ2
#define idB0VN81LZ2	 38	//(B0VN81LZ2) АЗ по АС периода разгона АЗ2
#define R0EE02LDU	 BUFFER[82]	//(R0EE02LDU) Питание  АКНП  отключить
#define idR0EE02LDU	 39	//(R0EE02LDU) Питание  АКНП  отключить
#define R0VZ05UZ2	 BUFFER[84]	//(R0VZ05UZ2) Индикатор причины сброса
#define idR0VZ05UZ2	 40	//(R0VZ05UZ2) Индикатор причины сброса
#define R0EE03LZ2	 BUFFER[89]	//(R0EE03LZ2) Питание  АКНП3  отключить
#define idR0EE03LZ2	 41	//(R0EE03LZ2) Питание  АКНП3  отключить
#define R0EE04LZ2	 BUFFER[91]	//(R0EE04LZ2) Питание  АКНП4  отключить
#define idR0EE04LZ2	 42	//(R0EE04LZ2) Питание  АКНП4  отключить
#define R0AD14LZ2	 BUFFER[93]	//(R0AD14LZ2) Имитация АЗ от IIУР
#define idR0AD14LZ2	 43	//(R0AD14LZ2) Имитация АЗ от IIУР
#define R0AD15LZ2	 BUFFER[95]	//(R0AD15LZ2) Имитация АЗ от 1УР (датчик1)
#define idR0AD15LZ2	 44	//(R0AD15LZ2) Имитация АЗ от 1УР (датчик1)
#define R0AD16LZ2	 BUFFER[97]	//(R0AD16LZ2) Имитация АЗ от 1УР (датчик2)
#define idR0AD16LZ2	 45	//(R0AD16LZ2) Имитация АЗ от 1УР (датчик2)
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
#define OEBB1Z2	 BUFFER[110]	//(OEBB1Z2) Обесточивание ЭМ ББ1 и ЭПК ББ1
#define idOEBB1Z2	 51	//(OEBB1Z2) Обесточивание ЭМ ББ1 и ЭПК ББ1
#define OEBB2Z2	 BUFFER[112]	//(OEBB2Z2) Обесточивание ЭМ ББ2 и ЭПК ББ2
#define idOEBB2Z2	 52	//(OEBB2Z2) Обесточивание ЭМ ББ2 и ЭПК ББ2
#define OERB1Z2	 BUFFER[114]	//(OERB1Z2) Обесточивание ЭМ РБ1 и ЭПК РБ1
#define idOERB1Z2	 53	//(OERB1Z2) Обесточивание ЭМ РБ1 и ЭПК РБ1
#define OERB2Z2	 BUFFER[116]	//(OERB2Z2) Обесточивание ЭМ РБ2 и ЭПК РБ2
#define idOERB2Z2	 54	//(OERB2Z2) Обесточивание ЭМ РБ2 и ЭПК РБ2
#define B3IS11LDU	 BUFFER[118]	//(B3IS11LDU) Приход на ВУ ИС2 для ДУ
#define idB3IS11LDU	 55	//(B3IS11LDU) Приход на ВУ ИС2 для ДУ
#define B3IS22LDU	 BUFFER[120]	//(B3IS22LDU) Приход на НУП ИС2 для ДУ
#define idB3IS22LDU	 56	//(B3IS22LDU) Приход на НУП ИС2 для ДУ
#define B3IS11LZ1	 BUFFER[122]	//(B3IS11LZ1) Приход на ВУ ИС2 для УСБ1
#define idB3IS11LZ1	 57	//(B3IS11LZ1) Приход на ВУ ИС2 для УСБ1
#define B0VP81LZ1	 BUFFER[124]	//(B0VP81LZ1) Давление  АЗ2 в норме для УСБ1
#define idB0VP81LZ1	 58	//(B0VP81LZ1) Давление  АЗ2 в норме для УСБ1
#define B3IS22LZ1	 BUFFER[126]	//(B3IS22LZ1) Приход на НУП ИС2 для УСБ1
#define idB3IS22LZ1	 59	//(B3IS22LZ1) Приход на НУП ИС2 для УСБ1
#define B1VP81LZ1	 BUFFER[128]	//(B1VP81LZ1) Давление СБРОС ББ2 в норме для УСБ1
#define idB1VP81LZ1	 60	//(B1VP81LZ1) Давление СБРОС ББ2 в норме для УСБ1
#define R0AD16LDU	 BUFFER[130]	//(R0AD16LDU) Имитация срабатывания верхней АС I УР
#define idR0AD16LDU	 61	//(R0AD16LDU) Имитация срабатывания верхней АС I УР
#define A2IS12LZ2	 BUFFER[132]	//(A2IS12LZ2) Магнит РБ1 зацеплен
#define idA2IS12LZ2	 62	//(A2IS12LZ2) Магнит РБ1 зацеплен
#define B2IS12LZ2	 BUFFER[134]	//(B2IS12LZ2) Магнит РБ2 зацеплен
#define idB2IS12LZ2	 63	//(B2IS12LZ2) Магнит РБ2 зацеплен
#define R6IS66LZ2	 BUFFER[136]	//(R6IS66LZ2) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZ2	 64	//(R6IS66LZ2) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZ2	 BUFFER[138]	//(R6IS67LZ2) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZ2	 65	//(R6IS67LZ2) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZ2	 BUFFER[140]	//(R6IS68LZ2) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZ2	 66	//(R6IS68LZ2) Исправность ВИП 4,0 (№7) ССДИ-2
#define R0VN71LZ2	 BUFFER[142]	//(R0VN71LZ2) АС по мощности канал 1
#define idR0VN71LZ2	 67	//(R0VN71LZ2) АС по мощности канал 1
#define R0VN75LZ2	 BUFFER[144]	//(R0VN75LZ2) АС по периоду разгона канал 1
#define idR0VN75LZ2	 68	//(R0VN75LZ2) АС по периоду разгона канал 1
#define R0VN72LZ2	 BUFFER[146]	//(R0VN72LZ2) АС по мощности канал 2
#define idR0VN72LZ2	 69	//(R0VN72LZ2) АС по мощности канал 2
#define R0VN76LZ2	 BUFFER[148]	//(R0VN76LZ2) АС по периоду разгона канал  2
#define idR0VN76LZ2	 70	//(R0VN76LZ2) АС по периоду разгона канал  2
#define R0VN73LZ2	 BUFFER[150]	//(R0VN73LZ2) АС по мощности канал 3
#define idR0VN73LZ2	 71	//(R0VN73LZ2) АС по мощности канал 3
#define R0VN74LZ2	 BUFFER[152]	//(R0VN74LZ2) АС по мощности канал 4
#define idR0VN74LZ2	 72	//(R0VN74LZ2) АС по мощности канал 4
#define R0VN77LZ2	 BUFFER[154]	//(R0VN77LZ2) АС по периоду разгона канал  3
#define idR0VN77LZ2	 73	//(R0VN77LZ2) АС по периоду разгона канал  3
#define R0VN78LZ2	 BUFFER[156]	//(R0VN78LZ2) АС по периоду разгона канал  4
#define idR0VN78LZ2	 74	//(R0VN78LZ2) АС по периоду разгона канал  4
#define R0VP41LZ2	 BUFFER[158]	//(R0VP41LZ2) АС по давлению в СИСТЕМЕ
#define idR0VP41LZ2	 75	//(R0VP41LZ2) АС по давлению в СИСТЕМЕ
#define R0VP81LZ2	 BUFFER[160]	//(R0VP81LZ2) Давление  в СИСТЕМЕ -1 в норме
#define idR0VP81LZ2	 76	//(R0VP81LZ2) Давление  в СИСТЕМЕ -1 в норме
#define R0VP82LZ2	 BUFFER[162]	//(R0VP82LZ2) Давление  в СИСТЕМЕ - 2 в норме
#define idR0VP82LZ2	 77	//(R0VP82LZ2) Давление  в СИСТЕМЕ - 2 в норме
#define R0AD04LZ2	 BUFFER[164]	//(R0AD04LZ2) Имитация срабатывания верхней АС II УР
#define idR0AD04LZ2	 78	//(R0AD04LZ2) Имитация срабатывания верхней АС II УР
#define R0EE01LZ2	 BUFFER[166]	//(R0EE01LZ2) Питание  АКНП1  отключить
#define idR0EE01LZ2	 79	//(R0EE01LZ2) Питание  АКНП1  отключить
#define R0EE02LZ2	 BUFFER[168]	//(R0EE02LZ2) Питание  АКНП2  отключить
#define idR0EE02LZ2	 80	//(R0EE02LZ2) Питание  АКНП2  отключить
#define A0VP41LZ2	 BUFFER[170]	//(A0VP41LZ2) Давление АЗ1 ниже АС
#define idA0VP41LZ2	 81	//(A0VP41LZ2) Давление АЗ1 ниже АС
#define B0VP41LZ2	 BUFFER[172]	//(B0VP41LZ2) Давление АЗ2 ниже АС
#define idB0VP41LZ2	 82	//(B0VP41LZ2) Давление АЗ2 ниже АС
#define B0VP81LZ2	 BUFFER[174]	//(B0VP81LZ2) Давление АЗ2 в норме
#define idB0VP81LZ2	 83	//(B0VP81LZ2) Давление АЗ2 в норме
#define A0VP81LZ2	 BUFFER[176]	//(A0VP81LZ2) Давление  АЗ1 в норме
#define idA0VP81LZ2	 84	//(A0VP81LZ2) Давление  АЗ1 в норме
#define R0ET02LZ2	 BUFFER[178]	//(R0ET02LZ2) Признак наличия неисправности по температуре АЗ2
#define idR0ET02LZ2	 85	//(R0ET02LZ2) Признак наличия неисправности по температуре АЗ2
#define B0EP02IZ2	 BUFFER[180]	//(B0EP02IZ2) Индикатор -Давление  АЗ2 ниже АС
#define idB0EP02IZ2	 86	//(B0EP02IZ2) Индикатор -Давление  АЗ2 ниже АС
#define A0EP02IZ2	 BUFFER[183]	//(A0EP02IZ2) Индикатор -Давление  АЗ1 ниже АС
#define idA0EP02IZ2	 87	//(A0EP02IZ2) Индикатор -Давление  АЗ1 ниже АС
#define A0VP71LZ2	 BUFFER[186]	//(A0VP71LZ2) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ2	 88	//(A0VP71LZ2) АЗ по АС любого давления для АЗ1
#define B0VP71LZ2	 BUFFER[188]	//(B0VP71LZ2) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ2	 89	//(B0VP71LZ2) АЗ по АС любого давления для АЗ2
#define R0VN02RS1	 BUFFER[190]	//(R0VN02RS1) Уровень мощности канал 1
#define idR0VN02RS1	 90	//(R0VN02RS1) Уровень мощности канал 1
#define R0VN02RS2	 BUFFER[195]	//(R0VN02RS2) Уровень мощности канал 2
#define idR0VN02RS2	 91	//(R0VN02RS2) Уровень мощности канал 2
#define R0VN02RS3	 BUFFER[200]	//(R0VN02RS3) Уровень мощности канал 3
#define idR0VN02RS3	 92	//(R0VN02RS3) Уровень мощности канал 3
#define R0VN02RS4	 BUFFER[205]	//(R0VN02RS4) Уровень мощности канал 4
#define idR0VN02RS4	 93	//(R0VN02RS4) Уровень мощности канал 4
#define R0VN01RS1	 BUFFER[210]	//(R0VN01RS1) Период разгона канал 1
#define idR0VN01RS1	 94	//(R0VN01RS1) Период разгона канал 1
#define R0VN01RS2	 BUFFER[215]	//(R0VN01RS2) Период разгона канал 2
#define idR0VN01RS2	 95	//(R0VN01RS2) Период разгона канал 2
#define R0VN01RS3	 BUFFER[220]	//(R0VN01RS3) Период разгона канал 3
#define idR0VN01RS3	 96	//(R0VN01RS3) Период разгона канал 3
#define R0VN01RS4	 BUFFER[225]	//(R0VN01RS4) Период разгона канал 4
#define idR0VN01RS4	 97	//(R0VN01RS4) Период разгона канал 4
#define R0VN61LS1	 BUFFER[230]	//(R0VN61LS1) ПС по мощности канал 1
#define idR0VN61LS1	 98	//(R0VN61LS1) ПС по мощности канал 1
#define R0VN61LS2	 BUFFER[232]	//(R0VN61LS2) ПС по мощности канал 2
#define idR0VN61LS2	 99	//(R0VN61LS2) ПС по мощности канал 2
#define R0VN61LS3	 BUFFER[234]	//(R0VN61LS3) ПС по мощности канал 3
#define idR0VN61LS3	 100	//(R0VN61LS3) ПС по мощности канал 3
#define A0IT02IZ2	 BUFFER[236]	//(A0IT02IZ2) Температура АЗ1-2
#define idA0IT02IZ2	 101	//(A0IT02IZ2) Температура АЗ1-2
#define A0CT01IZ2	 BUFFER[239]	//(A0CT01IZ2) Температура АЗ1-1
#define idA0CT01IZ2	 102	//(A0CT01IZ2) Температура АЗ1-1
#define A0VT61LZ2	 BUFFER[244]	//(A0VT61LZ2) ПС по температуре в АЗ1
#define idA0VT61LZ2	 103	//(A0VT61LZ2) ПС по температуре в АЗ1
#define A0VT71LZ2	 BUFFER[246]	//(A0VT71LZ2) АС по температуре в АЗ1
#define idA0VT71LZ2	 104	//(A0VT71LZ2) АС по температуре в АЗ1
#define A1VP41LZ2	 BUFFER[248]	//(A1VP41LZ2) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ2	 105	//(A1VP41LZ2) Давление СБРОС ББ1 ниже АС
#define B1VP41LZ2	 BUFFER[250]	//(B1VP41LZ2) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ2	 106	//(B1VP41LZ2) Давление СБРОС ББ2 ниже АС
#define B1VP81LZ2	 BUFFER[252]	//(B1VP81LZ2) Давление СБРОС ББ2 в норме
#define idB1VP81LZ2	 107	//(B1VP81LZ2) Давление СБРОС ББ2 в норме
#define A1VP81LZ2	 BUFFER[254]	//(A1VP81LZ2) Давление СБРОС ББ1 в норме
#define idA1VP81LZ2	 108	//(A1VP81LZ2) Давление СБРОС ББ1 в норме
#define A2VP41LZ2	 BUFFER[256]	//(A2VP41LZ2) Давление СБРОС РБ1 ниже АС
#define idA2VP41LZ2	 109	//(A2VP41LZ2) Давление СБРОС РБ1 ниже АС
#define A2CP01RZ2	 BUFFER[258]	//(A2CP01RZ2) Текущее давление СБРОС РБ1
#define idA2CP01RZ2	 110	//(A2CP01RZ2) Текущее давление СБРОС РБ1
#define A2VP51LZ2	 BUFFER[263]	//(A2VP51LZ2) Давление СБРОС РБ1 ниже ПС
#define idA2VP51LZ2	 111	//(A2VP51LZ2) Давление СБРОС РБ1 ниже ПС
#define B2VP41LZ2	 BUFFER[265]	//(B2VP41LZ2) Давление СБРОС РБ2 ниже АС
#define idB2VP41LZ2	 112	//(B2VP41LZ2) Давление СБРОС РБ2 ниже АС
#define B2CP01RZ2	 BUFFER[267]	//(B2CP01RZ2) Текущее давление СБРОС РБ2
#define idB2CP01RZ2	 113	//(B2CP01RZ2) Текущее давление СБРОС РБ2
#define B2VP51LZ2	 BUFFER[272]	//(B2VP51LZ2) Давление СБРОС РБ2 ниже ПС
#define idB2VP51LZ2	 114	//(B2VP51LZ2) Давление СБРОС РБ2 ниже ПС
#define B2VP81LZ2	 BUFFER[274]	//(B2VP81LZ2) Давление СБРОС РБ2 в норме
#define idB2VP81LZ2	 115	//(B2VP81LZ2) Давление СБРОС РБ2 в норме
#define A2VP81LZ2	 BUFFER[276]	//(A2VP81LZ2) Давление СБРОС РБ1 в норме
#define idA2VP81LZ2	 116	//(A2VP81LZ2) Давление СБРОС РБ1 в норме
#define A2IP01IZ2	 BUFFER[278]	//(A2IP01IZ2) Текущее давление СБРОС РБ1
#define idA2IP01IZ2	 117	//(A2IP01IZ2) Текущее давление СБРОС РБ1
#define B2IP01IZ2	 BUFFER[281]	//(B2IP01IZ2) Текущее давление СБРОС РБ2
#define idB2IP01IZ2	 118	//(B2IP01IZ2) Текущее давление СБРОС РБ2
#define R0ET01LZ2	 BUFFER[284]	//(R0ET01LZ2) Признак наличия неисправности по температуре  АЗ1
#define idR0ET01LZ2	 119	//(R0ET01LZ2) Признак наличия неисправности по температуре  АЗ1
#define B0IT02IZ2	 BUFFER[286]	//(B0IT02IZ2) Температура АЗ2-2
#define idB0IT02IZ2	 120	//(B0IT02IZ2) Температура АЗ2-2
#define R0VN68LZ2	 BUFFER[289]	//(R0VN68LZ2) ПС по периоду разгона канал 4
#define idR0VN68LZ2	 121	//(R0VN68LZ2) ПС по периоду разгона канал 4
#define R0VN09RZ2	 BUFFER[291]	//(R0VN09RZ2) Усредненный период разгона
#define idR0VN09RZ2	 122	//(R0VN09RZ2) Усредненный период разгона
#define A3IS11LZ2	 BUFFER[296]	//(A3IS11LZ2) Приход на ВУ ИС1
#define idA3IS11LZ2	 123	//(A3IS11LZ2) Приход на ВУ ИС1
#define A3IS22LZ2	 BUFFER[298]	//(A3IS22LZ2) Приход на НУП ИС1
#define idA3IS22LZ2	 124	//(A3IS22LZ2) Приход на НУП ИС1
#define R0AD03LZ2	 BUFFER[300]	//(R0AD03LZ2) Имитация прихода на ВУ ИС
#define idR0AD03LZ2	 125	//(R0AD03LZ2) Имитация прихода на ВУ ИС
#define B3IS11LZ2	 BUFFER[302]	//(B3IS11LZ2) Приход на ВУ ИС2
#define idB3IS11LZ2	 126	//(B3IS11LZ2) Приход на ВУ ИС2
#define A3VZ31LZ2	 BUFFER[304]	//(A3VZ31LZ2) АЗ от ВУ ИС1
#define idA3VZ31LZ2	 127	//(A3VZ31LZ2) АЗ от ВУ ИС1
#define B3VZ31LZ2	 BUFFER[306]	//(B3VZ31LZ2) АЗ от ВУ ИС2
#define idB3VZ31LZ2	 128	//(B3VZ31LZ2) АЗ от ВУ ИС2
#define R0AD05LZ2	 BUFFER[308]	//(R0AD05LZ2) Имитация ухода с НУП ИС
#define idR0AD05LZ2	 129	//(R0AD05LZ2) Имитация ухода с НУП ИС
#define A3VZ11LZ2	 BUFFER[310]	//(A3VZ11LZ2) АЗ от НУП ИС1
#define idA3VZ11LZ2	 130	//(A3VZ11LZ2) АЗ от НУП ИС1
#define B3VZ11LZ2	 BUFFER[312]	//(B3VZ11LZ2) АЗ от НУП ИС2
#define idB3VZ11LZ2	 131	//(B3VZ11LZ2) АЗ от НУП ИС2
#define B3IS22LZ2	 BUFFER[314]	//(B3IS22LZ2) Приход на НУП ИС2
#define idB3IS22LZ2	 132	//(B3IS22LZ2) Приход на НУП ИС2
#define R0VN69LZ2	 BUFFER[316]	//(R0VN69LZ2) ПС по усредненному периоду
#define idR0VN69LZ2	 133	//(R0VN69LZ2) ПС по усредненному периоду
#define R0VN79LZ2	 BUFFER[318]	//(R0VN79LZ2) АС по усредненному периоду
#define idR0VN79LZ2	 134	//(R0VN79LZ2) АС по усредненному периоду
#define R0VR02RZ2	 BUFFER[320]	//(R0VR02RZ2) Усредненная реактивность
#define idR0VR02RZ2	 135	//(R0VR02RZ2) Усредненная реактивность
#define R0VZ71LZ2	 BUFFER[325]	//(R0VZ71LZ2) Обобщенный сигнал АЗ 2 канала
#define idR0VZ71LZ2	 136	//(R0VZ71LZ2) Обобщенный сигнал АЗ 2 канала
#define R0VN70LZ2	 BUFFER[327]	//(R0VN70LZ2) АЗ по АС мощности РУ
#define idR0VN70LZ2	 137	//(R0VN70LZ2) АЗ по АС мощности РУ
#define R0VN80LZ2	 BUFFER[329]	//(R0VN80LZ2) АЗ по АС периода разгона РУ
#define idR0VN80LZ2	 138	//(R0VN80LZ2) АЗ по АС периода разгона РУ
#define A1EE01LS1	 BUFFER[331]	//(A1EE01LS1) Исправность АКНП канал 1
#define idA1EE01LS1	 139	//(A1EE01LS1) Исправность АКНП канал 1
#define A1EE01LS4	 BUFFER[333]	//(A1EE01LS4) Исправность АКНП канал 4
#define idA1EE01LS4	 140	//(A1EE01LS4) Исправность АКНП канал 4
#define R0VN61LS4	 BUFFER[335]	//(R0VN61LS4) ПС по мощности канал 4
#define idR0VN61LS4	 141	//(R0VN61LS4) ПС по мощности канал 4
#define R0VN65LS1	 BUFFER[337]	//(R0VN65LS1) ПС по периоду разгона канал 1
#define idR0VN65LS1	 142	//(R0VN65LS1) ПС по периоду разгона канал 1
#define R0VN65LS2	 BUFFER[339]	//(R0VN65LS2) ПС по периоду разгона  канал 2
#define idR0VN65LS2	 143	//(R0VN65LS2) ПС по периоду разгона  канал 2
#define R0VN65LS3	 BUFFER[341]	//(R0VN65LS3) ПС по периоду разгона канал 3
#define idR0VN65LS3	 144	//(R0VN65LS3) ПС по периоду разгона канал 3
#define R0VN65LS4	 BUFFER[343]	//(R0VN65LS4) ПС по периоду разгона канал 4
#define idR0VN65LS4	 145	//(R0VN65LS4) ПС по периоду разгона канал 4
#define R0VN01RZ2	 BUFFER[345]	//(R0VN01RZ2) Уровень мощности по каналу 1
#define idR0VN01RZ2	 146	//(R0VN01RZ2) Уровень мощности по каналу 1
#define R0VN02RZ2	 BUFFER[350]	//(R0VN02RZ2) Уровень мощности по каналу 2
#define idR0VN02RZ2	 147	//(R0VN02RZ2) Уровень мощности по каналу 2
#define R0VN03RZ2	 BUFFER[355]	//(R0VN03RZ2) Уровень мощности по каналу 3
#define idR0VN03RZ2	 148	//(R0VN03RZ2) Уровень мощности по каналу 3
#define R0VN04RZ2	 BUFFER[360]	//(R0VN04RZ2) Уровень мощности по каналу 4
#define idR0VN04RZ2	 149	//(R0VN04RZ2) Уровень мощности по каналу 4
#define R0VN05RZ2	 BUFFER[365]	//(R0VN05RZ2) Период разгона по каналу 1
#define idR0VN05RZ2	 150	//(R0VN05RZ2) Период разгона по каналу 1
#define R0VN06RZ2	 BUFFER[370]	//(R0VN06RZ2) Период разгона по каналу 2
#define idR0VN06RZ2	 151	//(R0VN06RZ2) Период разгона по каналу 2
#define R0VN07RZ2	 BUFFER[375]	//(R0VN07RZ2) Период разгона по каналу 3
#define idR0VN07RZ2	 152	//(R0VN07RZ2) Период разгона по каналу 3
#define R0VN08RZ2	 BUFFER[380]	//(R0VN08RZ2) Период разгона по каналу 4
#define idR0VN08RZ2	 153	//(R0VN08RZ2) Период разгона по каналу 4
#define R0VN61LZ2	 BUFFER[385]	//(R0VN61LZ2) ПС по мощности канал 1
#define idR0VN61LZ2	 154	//(R0VN61LZ2) ПС по мощности канал 1
#define R0VN62LZ2	 BUFFER[387]	//(R0VN62LZ2) ПС по мощности канал 2
#define idR0VN62LZ2	 155	//(R0VN62LZ2) ПС по мощности канал 2
#define R0VN63LZ2	 BUFFER[389]	//(R0VN63LZ2) ПС по мощности канал 3
#define idR0VN63LZ2	 156	//(R0VN63LZ2) ПС по мощности канал 3
#define R0VN64LZ2	 BUFFER[391]	//(R0VN64LZ2) ПС по мощности канал 4
#define idR0VN64LZ2	 157	//(R0VN64LZ2) ПС по мощности канал 4
#define R0VN65LZ2	 BUFFER[393]	//(R0VN65LZ2) ПС по периоду разгона канал 1
#define idR0VN65LZ2	 158	//(R0VN65LZ2) ПС по периоду разгона канал 1
#define R0VN66LZ2	 BUFFER[395]	//(R0VN66LZ2) ПС по периоду разгона канал 2
#define idR0VN66LZ2	 159	//(R0VN66LZ2) ПС по периоду разгона канал 2
#define R0VN67LZ2	 BUFFER[397]	//(R0VN67LZ2) ПС по периоду разгона канал 3
#define idR0VN67LZ2	 160	//(R0VN67LZ2) ПС по периоду разгона канал 3
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
#define fEM_A1UL11RZZ	 BUFFER[494]	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС
#define idfEM_A1UL11RZZ	 180	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС
#define fEM_R7UI73RZZ	 BUFFER[499]	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
#define idfEM_R7UI73RZZ	 181	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
#define bFirstEnterFlag	 BUFFER[504]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 182	//(bFirstEnterFlag) 
#define internal1_m254_tx	 BUFFER[506]	//(internal1_m254_tx) tx - время накопленное сек
#define idinternal1_m254_tx	 183	//(internal1_m254_tx) tx - время накопленное сек
#define internal1_m254_y0	 BUFFER[511]	//(internal1_m254_y0) y0
#define idinternal1_m254_y0	 184	//(internal1_m254_y0) y0
#define internal1_m325_tx	 BUFFER[512]	//(internal1_m325_tx) tx - время накопленное сек
#define idinternal1_m325_tx	 185	//(internal1_m325_tx) tx - время накопленное сек
#define internal1_m325_y0	 BUFFER[517]	//(internal1_m325_y0) y0
#define idinternal1_m325_y0	 186	//(internal1_m325_y0) y0
#define internal1_m221_tx	 BUFFER[518]	//(internal1_m221_tx) tx - время накопленное сек
#define idinternal1_m221_tx	 187	//(internal1_m221_tx) tx - время накопленное сек
#define internal1_m221_y0	 BUFFER[523]	//(internal1_m221_y0) y0
#define idinternal1_m221_y0	 188	//(internal1_m221_y0) y0
#define internal1_m219_tx	 BUFFER[524]	//(internal1_m219_tx) tx - время накопленное сек
#define idinternal1_m219_tx	 189	//(internal1_m219_tx) tx - время накопленное сек
#define internal1_m219_y0	 BUFFER[529]	//(internal1_m219_y0) y0
#define idinternal1_m219_y0	 190	//(internal1_m219_y0) y0
#define internal1_m262_tx	 BUFFER[530]	//(internal1_m262_tx) tx - время накопленное сек
#define idinternal1_m262_tx	 191	//(internal1_m262_tx) tx - время накопленное сек
#define internal1_m262_y0	 BUFFER[535]	//(internal1_m262_y0) y0
#define idinternal1_m262_y0	 192	//(internal1_m262_y0) y0
#define internal1_m218_tx	 BUFFER[536]	//(internal1_m218_tx) tx - время накопленное сек
#define idinternal1_m218_tx	 193	//(internal1_m218_tx) tx - время накопленное сек
#define internal1_m218_y0	 BUFFER[541]	//(internal1_m218_y0) y0
#define idinternal1_m218_y0	 194	//(internal1_m218_y0) y0
#define internal1_m216_tx	 BUFFER[542]	//(internal1_m216_tx) tx - время накопленное сек
#define idinternal1_m216_tx	 195	//(internal1_m216_tx) tx - время накопленное сек
#define internal1_m216_y0	 BUFFER[547]	//(internal1_m216_y0) y0
#define idinternal1_m216_y0	 196	//(internal1_m216_y0) y0
#define internal1_m29_tx	 BUFFER[548]	//(internal1_m29_tx) tx - внутренний параметр
#define idinternal1_m29_tx	 197	//(internal1_m29_tx) tx - внутренний параметр
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
#define internal1_m318_q0	 BUFFER[575]	//(internal1_m318_q0) q0 - внутренний параметр
#define idinternal1_m318_q0	 204	//(internal1_m318_q0) q0 - внутренний параметр
#define internal1_m137_y0	 BUFFER[580]	//(internal1_m137_y0) state
#define idinternal1_m137_y0	 205	//(internal1_m137_y0) state
#define internal1_m130_y0	 BUFFER[582]	//(internal1_m130_y0) state
#define idinternal1_m130_y0	 206	//(internal1_m130_y0) state
#define internal1_m113_y1	 BUFFER[584]	//(internal1_m113_y1) y1 - внутренний параметр
#define idinternal1_m113_y1	 207	//(internal1_m113_y1) y1 - внутренний параметр
#define internal1_m123_y1	 BUFFER[586]	//(internal1_m123_y1) y1 - внутренний параметр
#define idinternal1_m123_y1	 208	//(internal1_m123_y1) y1 - внутренний параметр
#define internal1_m102_y1	 BUFFER[588]	//(internal1_m102_y1) y1 - внутренний параметр
#define idinternal1_m102_y1	 209	//(internal1_m102_y1) y1 - внутренний параметр
#define internal1_m111_y1	 BUFFER[590]	//(internal1_m111_y1) y1 - внутренний параметр
#define idinternal1_m111_y1	 210	//(internal1_m111_y1) y1 - внутренний параметр
#define internal1_m159_y1	 BUFFER[592]	//(internal1_m159_y1) y1 - внутренний параметр
#define idinternal1_m159_y1	 211	//(internal1_m159_y1) y1 - внутренний параметр
#define internal1_m169_y1	 BUFFER[594]	//(internal1_m169_y1) y1 - внутренний параметр
#define idinternal1_m169_y1	 212	//(internal1_m169_y1) y1 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,8	,1	, &R0VN11RZ2},	//(R0VN11RZ2) Средняя мощность по БАЗ1
	{ 2	,1	,1	, &R0VP73LZ2},	//(R0VP73LZ2) ПС давления для РУ
	{ 3	,8	,1	, &B0CT01IZ2},	//(B0CT01IZ2) Температура АЗ2-1
	{ 4	,1	,1	, &B0VT61LZ2},	//(B0VT61LZ2) ПС по температуре в АЗ2
	{ 5	,1	,1	, &B0VT71LZ2},	//(B0VT71LZ2) АС по температуре в АЗ2
	{ 6	,1	,1	, &A1VN71LS1},	//(A1VN71LS1) Блокировка автоматического подъёма ББ канал 1
	{ 7	,1	,1	, &A1VN71LS2},	//(A1VN71LS2) Блокировка автоматического подъёма ББ канал 2
	{ 8	,1	,1	, &A1VN71LS3},	//(A1VN71LS3) Блокировка автоматического подъёма ББ канал 3
	{ 9	,1	,1	, &A1VN71LS4},	//(A1VN71LS4) Блокировка автоматического подъёма ББ канал 4
	{ 10	,1	,1	, &A1VN71LZ2},	//(A1VN71LZ2) Блокировка автоматического подъёма ББ
	{ 11	,1	,1	, &A3VZ15LZ2},	//(A3VZ15LZ2) Имитация АЗ от НУП ИС
	{ 12	,1	,1	, &A3VZ13LZ2},	//(A3VZ13LZ2) Имитация АЗ от ВУ ИС
	{ 13	,1	,1	, &R0VW13LDU},	//(R0VW13LDU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{ 14	,1	,1	, &R0VW23LDU},	//(R0VW23LDU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{ 15	,1	,1	, &R7II73LZ2},	//(R7II73LZ2) Сработала АС II УР РАД
	{ 16	,1	,1	, &R7II71LZ2},	//(R7II71LZ2) Сработала АС IУР РАД (датчик 1)
	{ 17	,1	,1	, &R7II72LZ2},	//(R7II72LZ2) Сработала АС IУР РАД (датчик 2)
	{ 18	,1	,1	, &R0AD21LDU},	//(R0AD21LDU) Подключить защиту от II УР
	{ 19	,1	,1	, &R0MD34LP1},	//(R0MD34LP1) Кнопка Квитировать
	{ 20	,1	,1	, &R0AD14LDU},	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
	{ 21	,1	,1	, &A1EE01LS3},	//(A1EE01LS3) Исправность АКНП канал 3
	{ 22	,1	,1	, &A0EE01LZ2},	//(A0EE01LZ2) Исправность АКНП1
	{ 23	,1	,1	, &A0EE04LZ2},	//(A0EE04LZ2) Исправность АКНП4
	{ 24	,1	,1	, &A0EE02LZ2},	//(A0EE02LZ2) Исправность АКНП2
	{ 25	,1	,1	, &A0EE03LZ2},	//(A0EE03LZ2) Исправность АКНП3
	{ 26	,1	,1	, &A1EE01LS2},	//(A1EE01LS2) Исправность АКНП  канал 2
	{ 27	,1	,1	, &A0EE05LZ2},	//(A0EE05LZ2) Исправность сети АКНП1
	{ 28	,1	,1	, &A0EE06LZ2},	//(A0EE06LZ2) Исправность сети АКНП2
	{ 29	,1	,1	, &A0EE07LZ2},	//(A0EE07LZ2) Исправность сети АКНП3
	{ 30	,1	,1	, &A0EE08LZ2},	//(A0EE08LZ2) Исправность сети АКНП4
	{ 31	,1	,1	, &A0VZ71LZ2},	//(A0VZ71LZ2) Обобщенный сигнал АС по АЗ1
	{ 32	,1	,1	, &A0EE00LZ2},	//(A0EE00LZ2) Исправность АКНП АЗ1
	{ 33	,1	,1	, &B0EE00LZ2},	//(B0EE00LZ2) Исправность АКНП АЗ2
	{ 34	,1	,1	, &B0VZ71LZ2},	//(B0VZ71LZ2) Обобщенный сигнал АС по АЗ2
	{ 35	,1	,1	, &A0VN71LZ2},	//(A0VN71LZ2) АЗ по АС мощности  АЗ1
	{ 36	,1	,1	, &B0VN71LZ2},	//(B0VN71LZ2) АЗ по АС мощности  АЗ2
	{ 37	,1	,1	, &A0VN81LZ2},	//(A0VN81LZ2) АЗ по АС периода разгона АЗ1
	{ 38	,1	,1	, &B0VN81LZ2},	//(B0VN81LZ2) АЗ по АС периода разгона АЗ2
	{ 39	,1	,1	, &R0EE02LDU},	//(R0EE02LDU) Питание  АКНП  отключить
	{ 40	,5	,1	, &R0VZ05UZ2},	//(R0VZ05UZ2) Индикатор причины сброса
	{ 41	,1	,1	, &R0EE03LZ2},	//(R0EE03LZ2) Питание  АКНП3  отключить
	{ 42	,1	,1	, &R0EE04LZ2},	//(R0EE04LZ2) Питание  АКНП4  отключить
	{ 43	,1	,1	, &R0AD14LZ2},	//(R0AD14LZ2) Имитация АЗ от IIУР
	{ 44	,1	,1	, &R0AD15LZ2},	//(R0AD15LZ2) Имитация АЗ от 1УР (датчик1)
	{ 45	,1	,1	, &R0AD16LZ2},	//(R0AD16LZ2) Имитация АЗ от 1УР (датчик2)
	{ 46	,3	,1	, &R0MW12IP2},	//(R0MW12IP2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
	{ 47	,1	,1	, &R0AD13LDU},	//(R0AD13LDU) Имитация прихода на ВУ ИС
	{ 48	,1	,1	, &R0AD15LDU},	//(R0AD15LDU) Имитация ухода с НУП ИС
	{ 49	,1	,1	, &A2IS12LDU},	//(A2IS12LDU) Магнит РБ1 зацеплен
	{ 50	,1	,1	, &B2IS12LDU},	//(B2IS12LDU) Магнит РБ2 зацеплен
	{ 51	,1	,1	, &OEBB1Z2},	//(OEBB1Z2) Обесточивание ЭМ ББ1 и ЭПК ББ1
	{ 52	,1	,1	, &OEBB2Z2},	//(OEBB2Z2) Обесточивание ЭМ ББ2 и ЭПК ББ2
	{ 53	,1	,1	, &OERB1Z2},	//(OERB1Z2) Обесточивание ЭМ РБ1 и ЭПК РБ1
	{ 54	,1	,1	, &OERB2Z2},	//(OERB2Z2) Обесточивание ЭМ РБ2 и ЭПК РБ2
	{ 55	,1	,1	, &B3IS11LDU},	//(B3IS11LDU) Приход на ВУ ИС2 для ДУ
	{ 56	,1	,1	, &B3IS22LDU},	//(B3IS22LDU) Приход на НУП ИС2 для ДУ
	{ 57	,1	,1	, &B3IS11LZ1},	//(B3IS11LZ1) Приход на ВУ ИС2 для УСБ1
	{ 58	,1	,1	, &B0VP81LZ1},	//(B0VP81LZ1) Давление  АЗ2 в норме для УСБ1
	{ 59	,1	,1	, &B3IS22LZ1},	//(B3IS22LZ1) Приход на НУП ИС2 для УСБ1
	{ 60	,1	,1	, &B1VP81LZ1},	//(B1VP81LZ1) Давление СБРОС ББ2 в норме для УСБ1
	{ 61	,1	,1	, &R0AD16LDU},	//(R0AD16LDU) Имитация срабатывания верхней АС I УР
	{ 62	,1	,1	, &A2IS12LZ2},	//(A2IS12LZ2) Магнит РБ1 зацеплен
	{ 63	,1	,1	, &B2IS12LZ2},	//(B2IS12LZ2) Магнит РБ2 зацеплен
	{ 64	,1	,1	, &R6IS66LZ2},	//(R6IS66LZ2) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 65	,1	,1	, &R6IS67LZ2},	//(R6IS67LZ2) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 66	,1	,1	, &R6IS68LZ2},	//(R6IS68LZ2) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 67	,1	,1	, &R0VN71LZ2},	//(R0VN71LZ2) АС по мощности канал 1
	{ 68	,1	,1	, &R0VN75LZ2},	//(R0VN75LZ2) АС по периоду разгона канал 1
	{ 69	,1	,1	, &R0VN72LZ2},	//(R0VN72LZ2) АС по мощности канал 2
	{ 70	,1	,1	, &R0VN76LZ2},	//(R0VN76LZ2) АС по периоду разгона канал  2
	{ 71	,1	,1	, &R0VN73LZ2},	//(R0VN73LZ2) АС по мощности канал 3
	{ 72	,1	,1	, &R0VN74LZ2},	//(R0VN74LZ2) АС по мощности канал 4
	{ 73	,1	,1	, &R0VN77LZ2},	//(R0VN77LZ2) АС по периоду разгона канал  3
	{ 74	,1	,1	, &R0VN78LZ2},	//(R0VN78LZ2) АС по периоду разгона канал  4
	{ 75	,1	,1	, &R0VP41LZ2},	//(R0VP41LZ2) АС по давлению в СИСТЕМЕ
	{ 76	,1	,1	, &R0VP81LZ2},	//(R0VP81LZ2) Давление  в СИСТЕМЕ -1 в норме
	{ 77	,1	,1	, &R0VP82LZ2},	//(R0VP82LZ2) Давление  в СИСТЕМЕ - 2 в норме
	{ 78	,1	,1	, &R0AD04LZ2},	//(R0AD04LZ2) Имитация срабатывания верхней АС II УР
	{ 79	,1	,1	, &R0EE01LZ2},	//(R0EE01LZ2) Питание  АКНП1  отключить
	{ 80	,1	,1	, &R0EE02LZ2},	//(R0EE02LZ2) Питание  АКНП2  отключить
	{ 81	,1	,1	, &A0VP41LZ2},	//(A0VP41LZ2) Давление АЗ1 ниже АС
	{ 82	,1	,1	, &B0VP41LZ2},	//(B0VP41LZ2) Давление АЗ2 ниже АС
	{ 83	,1	,1	, &B0VP81LZ2},	//(B0VP81LZ2) Давление АЗ2 в норме
	{ 84	,1	,1	, &A0VP81LZ2},	//(A0VP81LZ2) Давление  АЗ1 в норме
	{ 85	,1	,1	, &R0ET02LZ2},	//(R0ET02LZ2) Признак наличия неисправности по температуре АЗ2
	{ 86	,3	,1	, &B0EP02IZ2},	//(B0EP02IZ2) Индикатор -Давление  АЗ2 ниже АС
	{ 87	,3	,1	, &A0EP02IZ2},	//(A0EP02IZ2) Индикатор -Давление  АЗ1 ниже АС
	{ 88	,1	,1	, &A0VP71LZ2},	//(A0VP71LZ2) АЗ по АС любого давления для АЗ1
	{ 89	,1	,1	, &B0VP71LZ2},	//(B0VP71LZ2) АЗ по АС любого давления для АЗ2
	{ 90	,8	,1	, &R0VN02RS1},	//(R0VN02RS1) Уровень мощности канал 1
	{ 91	,8	,1	, &R0VN02RS2},	//(R0VN02RS2) Уровень мощности канал 2
	{ 92	,8	,1	, &R0VN02RS3},	//(R0VN02RS3) Уровень мощности канал 3
	{ 93	,8	,1	, &R0VN02RS4},	//(R0VN02RS4) Уровень мощности канал 4
	{ 94	,8	,1	, &R0VN01RS1},	//(R0VN01RS1) Период разгона канал 1
	{ 95	,8	,1	, &R0VN01RS2},	//(R0VN01RS2) Период разгона канал 2
	{ 96	,8	,1	, &R0VN01RS3},	//(R0VN01RS3) Период разгона канал 3
	{ 97	,8	,1	, &R0VN01RS4},	//(R0VN01RS4) Период разгона канал 4
	{ 98	,1	,1	, &R0VN61LS1},	//(R0VN61LS1) ПС по мощности канал 1
	{ 99	,1	,1	, &R0VN61LS2},	//(R0VN61LS2) ПС по мощности канал 2
	{ 100	,1	,1	, &R0VN61LS3},	//(R0VN61LS3) ПС по мощности канал 3
	{ 101	,3	,1	, &A0IT02IZ2},	//(A0IT02IZ2) Температура АЗ1-2
	{ 102	,8	,1	, &A0CT01IZ2},	//(A0CT01IZ2) Температура АЗ1-1
	{ 103	,1	,1	, &A0VT61LZ2},	//(A0VT61LZ2) ПС по температуре в АЗ1
	{ 104	,1	,1	, &A0VT71LZ2},	//(A0VT71LZ2) АС по температуре в АЗ1
	{ 105	,1	,1	, &A1VP41LZ2},	//(A1VP41LZ2) Давление СБРОС ББ1 ниже АС
	{ 106	,1	,1	, &B1VP41LZ2},	//(B1VP41LZ2) Давление СБРОС ББ2 ниже АС
	{ 107	,1	,1	, &B1VP81LZ2},	//(B1VP81LZ2) Давление СБРОС ББ2 в норме
	{ 108	,1	,1	, &A1VP81LZ2},	//(A1VP81LZ2) Давление СБРОС ББ1 в норме
	{ 109	,1	,1	, &A2VP41LZ2},	//(A2VP41LZ2) Давление СБРОС РБ1 ниже АС
	{ 110	,8	,1	, &A2CP01RZ2},	//(A2CP01RZ2) Текущее давление СБРОС РБ1
	{ 111	,1	,1	, &A2VP51LZ2},	//(A2VP51LZ2) Давление СБРОС РБ1 ниже ПС
	{ 112	,1	,1	, &B2VP41LZ2},	//(B2VP41LZ2) Давление СБРОС РБ2 ниже АС
	{ 113	,8	,1	, &B2CP01RZ2},	//(B2CP01RZ2) Текущее давление СБРОС РБ2
	{ 114	,1	,1	, &B2VP51LZ2},	//(B2VP51LZ2) Давление СБРОС РБ2 ниже ПС
	{ 115	,1	,1	, &B2VP81LZ2},	//(B2VP81LZ2) Давление СБРОС РБ2 в норме
	{ 116	,1	,1	, &A2VP81LZ2},	//(A2VP81LZ2) Давление СБРОС РБ1 в норме
	{ 117	,3	,1	, &A2IP01IZ2},	//(A2IP01IZ2) Текущее давление СБРОС РБ1
	{ 118	,3	,1	, &B2IP01IZ2},	//(B2IP01IZ2) Текущее давление СБРОС РБ2
	{ 119	,1	,1	, &R0ET01LZ2},	//(R0ET01LZ2) Признак наличия неисправности по температуре  АЗ1
	{ 120	,3	,1	, &B0IT02IZ2},	//(B0IT02IZ2) Температура АЗ2-2
	{ 121	,1	,1	, &R0VN68LZ2},	//(R0VN68LZ2) ПС по периоду разгона канал 4
	{ 122	,8	,1	, &R0VN09RZ2},	//(R0VN09RZ2) Усредненный период разгона
	{ 123	,1	,1	, &A3IS11LZ2},	//(A3IS11LZ2) Приход на ВУ ИС1
	{ 124	,1	,1	, &A3IS22LZ2},	//(A3IS22LZ2) Приход на НУП ИС1
	{ 125	,1	,1	, &R0AD03LZ2},	//(R0AD03LZ2) Имитация прихода на ВУ ИС
	{ 126	,1	,1	, &B3IS11LZ2},	//(B3IS11LZ2) Приход на ВУ ИС2
	{ 127	,1	,1	, &A3VZ31LZ2},	//(A3VZ31LZ2) АЗ от ВУ ИС1
	{ 128	,1	,1	, &B3VZ31LZ2},	//(B3VZ31LZ2) АЗ от ВУ ИС2
	{ 129	,1	,1	, &R0AD05LZ2},	//(R0AD05LZ2) Имитация ухода с НУП ИС
	{ 130	,1	,1	, &A3VZ11LZ2},	//(A3VZ11LZ2) АЗ от НУП ИС1
	{ 131	,1	,1	, &B3VZ11LZ2},	//(B3VZ11LZ2) АЗ от НУП ИС2
	{ 132	,1	,1	, &B3IS22LZ2},	//(B3IS22LZ2) Приход на НУП ИС2
	{ 133	,1	,1	, &R0VN69LZ2},	//(R0VN69LZ2) ПС по усредненному периоду
	{ 134	,1	,1	, &R0VN79LZ2},	//(R0VN79LZ2) АС по усредненному периоду
	{ 135	,8	,1	, &R0VR02RZ2},	//(R0VR02RZ2) Усредненная реактивность
	{ 136	,1	,1	, &R0VZ71LZ2},	//(R0VZ71LZ2) Обобщенный сигнал АЗ 2 канала
	{ 137	,1	,1	, &R0VN70LZ2},	//(R0VN70LZ2) АЗ по АС мощности РУ
	{ 138	,1	,1	, &R0VN80LZ2},	//(R0VN80LZ2) АЗ по АС периода разгона РУ
	{ 139	,1	,1	, &A1EE01LS1},	//(A1EE01LS1) Исправность АКНП канал 1
	{ 140	,1	,1	, &A1EE01LS4},	//(A1EE01LS4) Исправность АКНП канал 4
	{ 141	,1	,1	, &R0VN61LS4},	//(R0VN61LS4) ПС по мощности канал 4
	{ 142	,1	,1	, &R0VN65LS1},	//(R0VN65LS1) ПС по периоду разгона канал 1
	{ 143	,1	,1	, &R0VN65LS2},	//(R0VN65LS2) ПС по периоду разгона  канал 2
	{ 144	,1	,1	, &R0VN65LS3},	//(R0VN65LS3) ПС по периоду разгона канал 3
	{ 145	,1	,1	, &R0VN65LS4},	//(R0VN65LS4) ПС по периоду разгона канал 4
	{ 146	,8	,1	, &R0VN01RZ2},	//(R0VN01RZ2) Уровень мощности по каналу 1
	{ 147	,8	,1	, &R0VN02RZ2},	//(R0VN02RZ2) Уровень мощности по каналу 2
	{ 148	,8	,1	, &R0VN03RZ2},	//(R0VN03RZ2) Уровень мощности по каналу 3
	{ 149	,8	,1	, &R0VN04RZ2},	//(R0VN04RZ2) Уровень мощности по каналу 4
	{ 150	,8	,1	, &R0VN05RZ2},	//(R0VN05RZ2) Период разгона по каналу 1
	{ 151	,8	,1	, &R0VN06RZ2},	//(R0VN06RZ2) Период разгона по каналу 2
	{ 152	,8	,1	, &R0VN07RZ2},	//(R0VN07RZ2) Период разгона по каналу 3
	{ 153	,8	,1	, &R0VN08RZ2},	//(R0VN08RZ2) Период разгона по каналу 4
	{ 154	,1	,1	, &R0VN61LZ2},	//(R0VN61LZ2) ПС по мощности канал 1
	{ 155	,1	,1	, &R0VN62LZ2},	//(R0VN62LZ2) ПС по мощности канал 2
	{ 156	,1	,1	, &R0VN63LZ2},	//(R0VN63LZ2) ПС по мощности канал 3
	{ 157	,1	,1	, &R0VN64LZ2},	//(R0VN64LZ2) ПС по мощности канал 4
	{ 158	,1	,1	, &R0VN65LZ2},	//(R0VN65LZ2) ПС по периоду разгона канал 1
	{ 159	,1	,1	, &R0VN66LZ2},	//(R0VN66LZ2) ПС по периоду разгона канал 2
	{ 160	,1	,1	, &R0VN67LZ2},	//(R0VN67LZ2) ПС по периоду разгона канал 3
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
	{ 180	,8	,1	, &fEM_A1UL11RZZ},	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС
	{ 181	,8	,1	, &fEM_R7UI73RZZ},	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
	{ 182	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 183	,8	,1	, &internal1_m254_tx},	//(internal1_m254_tx) tx - время накопленное сек
	{ 184	,18	,1	, &internal1_m254_y0},	//(internal1_m254_y0) y0
	{ 185	,8	,1	, &internal1_m325_tx},	//(internal1_m325_tx) tx - время накопленное сек
	{ 186	,18	,1	, &internal1_m325_y0},	//(internal1_m325_y0) y0
	{ 187	,8	,1	, &internal1_m221_tx},	//(internal1_m221_tx) tx - время накопленное сек
	{ 188	,18	,1	, &internal1_m221_y0},	//(internal1_m221_y0) y0
	{ 189	,8	,1	, &internal1_m219_tx},	//(internal1_m219_tx) tx - время накопленное сек
	{ 190	,18	,1	, &internal1_m219_y0},	//(internal1_m219_y0) y0
	{ 191	,8	,1	, &internal1_m262_tx},	//(internal1_m262_tx) tx - время накопленное сек
	{ 192	,18	,1	, &internal1_m262_y0},	//(internal1_m262_y0) y0
	{ 193	,8	,1	, &internal1_m218_tx},	//(internal1_m218_tx) tx - время накопленное сек
	{ 194	,18	,1	, &internal1_m218_y0},	//(internal1_m218_y0) y0
	{ 195	,8	,1	, &internal1_m216_tx},	//(internal1_m216_tx) tx - время накопленное сек
	{ 196	,18	,1	, &internal1_m216_y0},	//(internal1_m216_y0) y0
	{ 197	,3	,1	, &internal1_m29_tx},	//(internal1_m29_tx) tx - внутренний параметр
	{ 198	,8	,1	, &internal1_m150_y0},	//(internal1_m150_y0) y0
	{ 199	,8	,1	, &internal1_m148_y0},	//(internal1_m148_y0) y0
	{ 200	,8	,1	, &internal1_m97_y0},	//(internal1_m97_y0) y0
	{ 201	,8	,1	, &internal1_m95_y0},	//(internal1_m95_y0) y0
	{ 202	,1	,1	, &internal1_m161_y1},	//(internal1_m161_y1) y1 - внутренний параметр
	{ 203	,1	,1	, &internal1_m172_y1},	//(internal1_m172_y1) y1 - внутренний параметр
	{ 204	,5	,1	, &internal1_m318_q0},	//(internal1_m318_q0) q0 - внутренний параметр
	{ 205	,1	,1	, &internal1_m137_y0},	//(internal1_m137_y0) state
	{ 206	,1	,1	, &internal1_m130_y0},	//(internal1_m130_y0) state
	{ 207	,1	,1	, &internal1_m113_y1},	//(internal1_m113_y1) y1 - внутренний параметр
	{ 208	,1	,1	, &internal1_m123_y1},	//(internal1_m123_y1) y1 - внутренний параметр
	{ 209	,1	,1	, &internal1_m102_y1},	//(internal1_m102_y1) y1 - внутренний параметр
	{ 210	,1	,1	, &internal1_m111_y1},	//(internal1_m111_y1) y1 - внутренний параметр
	{ 211	,1	,1	, &internal1_m159_y1},	//(internal1_m159_y1) y1 - внутренний параметр
	{ 212	,1	,1	, &internal1_m169_y1},	//(internal1_m169_y1) y1 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="baz2.bin\0";   // Имя файла для сохранения констант
#pragma pop
static short saveVariables[]={      // Id переменных для сохранения
161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,-1,};
#pragma pack(push,1)
static ModbusRegister coil_Baz2[]={  // 
	{&R0EE02LDU,1,0},	//(R0EE02LDU) Питание  АКНП  отключить
	{&A0EE08LZ2,1,1},	//(A0EE08LZ2) Исправность сети АКНП4
	{&A0EE07LZ2,1,2},	//(A0EE07LZ2) Исправность сети АКНП3
	{&A0EE06LZ2,1,3},	//(A0EE06LZ2) Исправность сети АКНП2
	{&A0EE05LZ2,1,4},	//(A0EE05LZ2) Исправность сети АКНП1
	{&R0VN78LZ2,1,5},	//(R0VN78LZ2) АС по периоду разгона канал  4
	{&R0VN77LZ2,1,6},	//(R0VN77LZ2) АС по периоду разгона канал  3
	{&R0VN74LZ2,1,7},	//(R0VN74LZ2) АС по мощности канал 4
	{&R0VN73LZ2,1,8},	//(R0VN73LZ2) АС по мощности канал 3
	{&R0VN76LZ2,1,9},	//(R0VN76LZ2) АС по периоду разгона канал  2
	{&R0VN72LZ2,1,10},	//(R0VN72LZ2) АС по мощности канал 2
	{&R0VN75LZ2,1,11},	//(R0VN75LZ2) АС по периоду разгона канал 1
	{&R0VN71LZ2,1,12},	//(R0VN71LZ2) АС по мощности канал 1
	{&R0AD16LDU,1,13},	//(R0AD16LDU) Имитация срабатывания верхней АС I УР
	{&R0MD34LP1,1,14},	//(R0MD34LP1) Кнопка Квитировать
	{&R7II72LZ2,1,15},	//(R7II72LZ2) Сработала АС IУР РАД (датчик 2)
	{&R7II71LZ2,1,16},	//(R7II71LZ2) Сработала АС IУР РАД (датчик 1)
	{&R7II73LZ2,1,17},	//(R7II73LZ2) Сработала АС II УР РАД
	{&R0VW23LDU,1,18},	//(R0VW23LDU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,1,19},	//(R0VW13LDU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_Baz2[]={  // 
	{&B0VN81LZ2,1,0},	//(B0VN81LZ2) АЗ по АС периода разгона АЗ2
	{&A0VN81LZ2,1,1},	//(A0VN81LZ2) АЗ по АС периода разгона АЗ1
	{&B0VN71LZ2,1,2},	//(B0VN71LZ2) АЗ по АС мощности  АЗ2
	{&A0VN71LZ2,1,3},	//(A0VN71LZ2) АЗ по АС мощности  АЗ1
	{&B0VZ71LZ2,1,4},	//(B0VZ71LZ2) Обобщенный сигнал АС по АЗ2
	{&B0EE00LZ2,1,5},	//(B0EE00LZ2) Исправность АКНП АЗ2
	{&A0EE00LZ2,1,6},	//(A0EE00LZ2) Исправность АКНП АЗ1
	{&A0VZ71LZ2,1,7},	//(A0VZ71LZ2) Обобщенный сигнал АС по АЗ1
	{&A0EE03LZ2,1,8},	//(A0EE03LZ2) Исправность АКНП3
	{&A0EE02LZ2,1,9},	//(A0EE02LZ2) Исправность АКНП2
	{&A0EE04LZ2,1,10},	//(A0EE04LZ2) Исправность АКНП4
	{&A0EE01LZ2,1,11},	//(A0EE01LZ2) Исправность АКНП1
	{&R0VN80LZ2,1,12},	//(R0VN80LZ2) АЗ по АС периода разгона РУ
	{&R0VN70LZ2,1,13},	//(R0VN70LZ2) АЗ по АС мощности РУ
	{&R0VZ71LZ2,1,14},	//(R0VZ71LZ2) Обобщенный сигнал АЗ 2 канала
	{&R0AD16LZ2,1,15},	//(R0AD16LZ2) Имитация АЗ от 1УР (датчик2)
	{&R0AD15LZ2,1,16},	//(R0AD15LZ2) Имитация АЗ от 1УР (датчик1)
	{&R0VP41LZ2,1,17},	//(R0VP41LZ2) АС по давлению в СИСТЕМЕ
	{&B0VT71LZ2,1,18},	//(B0VT71LZ2) АС по температуре в АЗ2
	{&B0VT61LZ2,1,19},	//(B0VT61LZ2) ПС по температуре в АЗ2
	{&R0VP73LZ2,1,20},	//(R0VP73LZ2) ПС давления для РУ
	{&B0VP71LZ2,1,21},	//(B0VP71LZ2) АЗ по АС любого давления для АЗ2
	{&A0VP71LZ2,1,22},	//(A0VP71LZ2) АЗ по АС любого давления для АЗ1
	{&R0ET02LZ2,1,23},	//(R0ET02LZ2) Признак наличия неисправности по температуре АЗ2
	{&B0VP41LZ2,1,24},	//(B0VP41LZ2) Давление АЗ2 ниже АС
	{&A0VP41LZ2,1,25},	//(A0VP41LZ2) Давление АЗ1 ниже АС
	{&R0ET01LZ2,1,26},	//(R0ET01LZ2) Признак наличия неисправности по температуре  АЗ1
	{&A2VP81LZ2,1,27},	//(A2VP81LZ2) Давление СБРОС РБ1 в норме
	{&B2VP81LZ2,1,28},	//(B2VP81LZ2) Давление СБРОС РБ2 в норме
	{&B2VP51LZ2,1,29},	//(B2VP51LZ2) Давление СБРОС РБ2 ниже ПС
	{&B2VP41LZ2,1,30},	//(B2VP41LZ2) Давление СБРОС РБ2 ниже АС
	{&A2VP51LZ2,1,31},	//(A2VP51LZ2) Давление СБРОС РБ1 ниже ПС
	{&A2VP41LZ2,1,32},	//(A2VP41LZ2) Давление СБРОС РБ1 ниже АС
	{&B1VP41LZ2,1,33},	//(B1VP41LZ2) Давление СБРОС ББ2 ниже АС
	{&A1VP41LZ2,1,34},	//(A1VP41LZ2) Давление СБРОС ББ1 ниже АС
	{&A0VT71LZ2,1,35},	//(A0VT71LZ2) АС по температуре в АЗ1
	{&A0VT61LZ2,1,36},	//(A0VT61LZ2) ПС по температуре в АЗ1
	{&R0VN79LZ2,1,37},	//(R0VN79LZ2) АС по усредненному периоду
	{&R0VN69LZ2,1,38},	//(R0VN69LZ2) ПС по усредненному периоду
	{&B3VZ11LZ2,1,39},	//(B3VZ11LZ2) АЗ от НУП ИС2
	{&A3VZ11LZ2,1,40},	//(A3VZ11LZ2) АЗ от НУП ИС1
	{&B3VZ31LZ2,1,41},	//(B3VZ31LZ2) АЗ от ВУ ИС2
	{&A3VZ31LZ2,1,42},	//(A3VZ31LZ2) АЗ от ВУ ИС1
	{&R0VN68LZ2,1,43},	//(R0VN68LZ2) ПС по периоду разгона канал 4
	{&R0VN67LZ2,1,44},	//(R0VN67LZ2) ПС по периоду разгона канал 3
	{&R0VN66LZ2,1,45},	//(R0VN66LZ2) ПС по периоду разгона канал 2
	{&R0VN65LZ2,1,46},	//(R0VN65LZ2) ПС по периоду разгона канал 1
	{&R0VN64LZ2,1,47},	//(R0VN64LZ2) ПС по мощности канал 4
	{&R0VN63LZ2,1,48},	//(R0VN63LZ2) ПС по мощности канал 3
	{&R0VN62LZ2,1,49},	//(R0VN62LZ2) ПС по мощности канал 2
	{&R0VN61LZ2,1,50},	//(R0VN61LZ2) ПС по мощности канал 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_Baz2[]={  // 
	{&R0VN11RZ2,8,0},	//(R0VN11RZ2) Средняя мощность по БАЗ1
	{&R0VZ05UZ2,5,2},	//(R0VZ05UZ2) Индикатор причины сброса
	{&B0CT01IZ2,8,4},	//(B0CT01IZ2) Температура АЗ2-1
	{&R0VN01RZ2,8,6},	//(R0VN01RZ2) Уровень мощности по каналу 1
	{&A0EP02IZ2,3,8},	//(A0EP02IZ2) Индикатор -Давление  АЗ1 ниже АС
	{&B0EP02IZ2,3,9},	//(B0EP02IZ2) Индикатор -Давление  АЗ2 ниже АС
	{&B2CP01RZ2,8,10},	//(B2CP01RZ2) Текущее давление СБРОС РБ2
	{&A2CP01RZ2,8,12},	//(A2CP01RZ2) Текущее давление СБРОС РБ1
	{&A0CT01IZ2,8,14},	//(A0CT01IZ2) Температура АЗ1-1
	{&R0VR02RZ2,8,16},	//(R0VR02RZ2) Усредненная реактивность
	{&R0VN09RZ2,8,18},	//(R0VN09RZ2) Усредненный период разгона
	{&R0VN08RZ2,8,20},	//(R0VN08RZ2) Период разгона по каналу 4
	{&R0VN07RZ2,8,22},	//(R0VN07RZ2) Период разгона по каналу 3
	{&R0VN06RZ2,8,24},	//(R0VN06RZ2) Период разгона по каналу 2
	{&R0VN05RZ2,8,26},	//(R0VN05RZ2) Период разгона по каналу 1
	{&R0VN04RZ2,8,28},	//(R0VN04RZ2) Уровень мощности по каналу 4
	{&R0VN03RZ2,8,30},	//(R0VN03RZ2) Уровень мощности по каналу 3
	{&R0VN02RZ2,8,32},	//(R0VN02RZ2) Уровень мощности по каналу 2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_Baz2[]={  // 
	{&R0MW12IP2,3,0},	//(R0MW12IP2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
	{&fEM_R7UI73RZZ,8,1},	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
	{&fEM_A1UL11RZZ,8,3},	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС
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
static ModbusRegister coil_SBz2DU[]={  // 
	{&R0AD21LDU,1,0},	//(R0AD21LDU) Подключить защиту от II УР
	{&R0VW23LDU,1,1},	//(R0VW23LDU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,1,2},	//(R0VW13LDU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SBz2DU[]={  // 
	{&B0VT71LZ2,1,0},	//(B0VT71LZ2) АС по температуре в АЗ2
	{&R0VP73LZ2,1,1},	//(R0VP73LZ2) ПС давления для РУ
	{&B0VN71LZ2,1,2},	//(B0VN71LZ2) АЗ по АС мощности  АЗ2
	{&A0VN71LZ2,1,3},	//(A0VN71LZ2) АЗ по АС мощности  АЗ1
	{&A0EE03LZ2,1,4},	//(A0EE03LZ2) Исправность АКНП3
	{&A0EE02LZ2,1,5},	//(A0EE02LZ2) Исправность АКНП2
	{&A0EE04LZ2,1,6},	//(A0EE04LZ2) Исправность АКНП4
	{&A0EE01LZ2,1,7},	//(A0EE01LZ2) Исправность АКНП1
	{&B0VP71LZ2,1,8},	//(B0VP71LZ2) АЗ по АС любого давления для АЗ2
	{&A0VP71LZ2,1,9},	//(A0VP71LZ2) АЗ по АС любого давления для АЗ1
	{&A0VT71LZ2,1,10},	//(A0VT71LZ2) АС по температуре в АЗ1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SBz2DU[]={  // 
	{&B0CT01IZ2,8,0},	//(B0CT01IZ2) Температура АЗ2-1
	{&R0VN11RZ2,8,2},	//(R0VN11RZ2) Средняя мощность по БАЗ1
	{&R0VN09RZ2,8,4},	//(R0VN09RZ2) Усредненный период разгона
	{&A0CT01IZ2,8,6},	//(A0CT01IZ2) Температура АЗ1-1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SBz2DU[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_MBz2S[]={  // 
	{&R0EE04LZ2,1,0},	//(R0EE04LZ2) Питание  АКНП4  отключить
	{&R0EE03LZ2,1,1},	//(R0EE03LZ2) Питание  АКНП3  отключить
	{&R0EE02LZ2,1,2},	//(R0EE02LZ2) Питание  АКНП  отключить
	{&R0EE01LZ2,1,3},	//(R0EE01LZ2) Питание  АКНП1  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MBz2S[]={  // 
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
static ModbusRegister ir_MBz2S[]={  // 
	{&B2IP01IZ2,3,0},	//(B2IP01IZ2) Текущее давление СБРОС РБ2
	{&A2IP01IZ2,3,1},	//(A2IP01IZ2) Текущее давление СБРОС РБ1
	{&B0IT02IZ2,3,2},	//(B0IT02IZ2) Температура АЗ2-2
	{&A0IT02IZ2,3,3},	//(A0IT02IZ2) Температура АЗ1-2
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
static ModbusRegister hr_MBz2S[]={  // 
	{NULL,0,0},
};
#pragma pop
static char MBz2S_ip1[]={"192.168.10.60\0"};
static char MBz2S_ip2[]={"192.168.10.60\0"};
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,502,&coil_Baz2[0],&di_Baz2[0],&ir_Baz2[0],&hr_Baz2[0],NULL,NULL,NULL,0},	 //Общий слэйв
	{0,504,&coil_SBz2DU[0],&di_SBz2DU[0],&ir_SBz2DU[0],&hr_SBz2DU[0],NULL,NULL,NULL,0},	 //Слэйв для DU
	{1,504,&coil_MBz2S[0],&di_MBz2S[0],&ir_MBz2S[0],&hr_MBz2S[0],NULL,MBz2S_ip1,MBz2S_ip2,100},	 //Мастер Баз2 в SCM

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
	{&A1EE01LS1,1,4},
	{&R0VN75LZ2,1,2},
	{&R0AD04LZ2,1,14},
	{&R0AD05LZ2,1,16},
	{&R0VN71LZ2,1,0},
	{&B2IS12LZ2,1,20},
	{&R0AD03LZ2,1,12},
	{&A3IS22LZ2,1,10},
	{&A3IS11LZ2,1,8},
	{&A2IS12LZ2,1,18},
	{&A1VN71LS1,1,6},
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
	{&A1VN71LS2,1,6},
	{&R0VN72LZ2,1,0},
	{&R0VN76LZ2,1,2},
	{&B3IS22LZ2,1,10},
	{&B3IS11LZ2,1,8},
	{&A1EE01LS2,1,4},
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
	{&R6IS68LZ2,1,12},
	{&A1EE01LS4,1,4},
	{&R0VN74LZ2,1,0},
	{&R0VN78LZ2,1,2},
	{&R6IS67LZ2,1,10},
	{&R6IS66LZ2,1,8},
	{&A1VN71LS4,1,6},
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
	{&R0VN73LZ2,1,0},
	{&R0VN77LZ2,1,2},
	{&B1VP81LZ2,1,24},
	{&A1VP81LZ2,1,18},
	{&A1VN71LS3,1,6},
	{&R0VP81LZ2,1,20},
	{&R0VP82LZ2,1,26},
	{&R7II73LZ2,1,12},
	{&R7II71LZ2,1,8},
	{&R7II72LZ2,1,10},
	{&A0VP81LZ2,1,16},
	{&B0VP81LZ2,1,22},
	{&A1EE01LS3,1,4},
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
	{&A1VN71LZ2,1,6},
	{&A3VZ15LZ2,1,2},
	{&A3VZ13LZ2,1,0},
	{&B1VP81LZ1,1,28},
	{&B3IS22LZ1,1,24},
	{&B0VP81LZ1,1,26},
	{&B3IS11LZ1,1,22},
	{&B3IS22LDU,1,20},
	{&B3IS11LDU,1,18},
	{&OERB2Z2,1,16},
	{&OERB1Z2,1,14},
	{&OEBB2Z2,1,12},
	{&OEBB1Z2,1,10},
	{&R0AD14LZ2,1,4},
	{&R0VZ71LZ2,1,8},
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
void Scheme(void)
{
}
#endif
