#ifndef BAZ1_H
#define BAZ1_H
// Подсистема Baz1:Baz1
static char SimulOn=0;
static short CodeSub=4;
static char SimulIP[]="192.168.10.201\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 615
static char BUFFER[615];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.52\0", 5432, "192.168.10.152\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define B0VT71LZ1	 BUFFER[0]	//(B0VT71LZ1) АС по температуре в АЗ2
#define idB0VT71LZ1	 1	//(B0VT71LZ1) АС по температуре в АЗ2
#define A0VN71LS1	 BUFFER[2]	//(A0VN71LS1) Блокировка автоматического подъёма ББ канал 1
#define idA0VN71LS1	 2	//(A0VN71LS1) Блокировка автоматического подъёма ББ канал 1
#define A0VN71LS2	 BUFFER[4]	//(A0VN71LS2) Блокировка автоматического подъёма ББ канал 2
#define idA0VN71LS2	 3	//(A0VN71LS2) Блокировка автоматического подъёма ББ канал 2
#define A0VN71LS3	 BUFFER[6]	//(A0VN71LS3) Блокировка автоматического подъёма ББ канал 3
#define idA0VN71LS3	 4	//(A0VN71LS3) Блокировка автоматического подъёма ББ канал 3
#define A0VN71LS4	 BUFFER[8]	//(A0VN71LS4) Блокировка автоматического подъёма ББ канал 4
#define idA0VN71LS4	 5	//(A0VN71LS4) Блокировка автоматического подъёма ББ канал 4
#define A1VN71LZ1	 BUFFER[10]	//(A1VN71LZ1) Блокировка автоматического подъёма ББ
#define idA1VN71LZ1	 6	//(A1VN71LZ1) Блокировка автоматического подъёма ББ
#define A3VZ15LZ1	 BUFFER[12]	//(A3VZ15LZ1) Имитация АЗ от НУП ИС
#define idA3VZ15LZ1	 7	//(A3VZ15LZ1) Имитация АЗ от НУП ИС
#define A3VZ13LZ1	 BUFFER[14]	//(A3VZ13LZ1) Имитация АЗ от ВУ ИС
#define idA3VZ13LZ1	 8	//(A3VZ13LZ1) Имитация АЗ от ВУ ИС
#define R0VW13LDU	 BUFFER[16]	//(R0VW13LDU) Индикация выбора АЗ1 или АЗ1+АЗ2
#define idR0VW13LDU	 9	//(R0VW13LDU) Индикация выбора АЗ1 или АЗ1+АЗ2
#define R0VW23LDU	 BUFFER[18]	//(R0VW23LDU) Индикация выбора АЗ2 или АЗ1+АЗ2
#define idR0VW23LDU	 10	//(R0VW23LDU) Индикация выбора АЗ2 или АЗ1+АЗ2
#define R7II73LZ1	 BUFFER[20]	//(R7II73LZ1) Сработала АС II УР РАД
#define idR7II73LZ1	 11	//(R7II73LZ1) Сработала АС II УР РАД
#define R7II71LZ1	 BUFFER[22]	//(R7II71LZ1) Сработала АС IУР РАД (датчик 1)
#define idR7II71LZ1	 12	//(R7II71LZ1) Сработала АС IУР РАД (датчик 1)
#define R7II72LZ1	 BUFFER[24]	//(R7II72LZ1) Сработала АС IУР РАД  (датчик 2)
#define idR7II72LZ1	 13	//(R7II72LZ1) Сработала АС IУР РАД  (датчик 2)
#define R0AD14LZ1	 BUFFER[26]	//(R0AD14LZ1) Имитация АЗ от IIУР
#define idR0AD14LZ1	 14	//(R0AD14LZ1) Имитация АЗ от IIУР
#define R0AD21LDU	 BUFFER[28]	//(R0AD21LDU) Подключить защиту от II УР
#define idR0AD21LDU	 15	//(R0AD21LDU) Подключить защиту от II УР
#define R0AD14LDU	 BUFFER[30]	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 16	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
#define R0MD34LP1	 BUFFER[32]	//(R0MD34LP1) Кнопка (Квитировать)
#define idR0MD34LP1	 17	//(R0MD34LP1) Кнопка (Квитировать)
#define R0AD04LZ1	 BUFFER[34]	//(R0AD04LZ1) Имитация срабатывания верхней АС II УР
#define idR0AD04LZ1	 18	//(R0AD04LZ1) Имитация срабатывания верхней АС II УР
#define R0AD16LDU	 BUFFER[36]	//(R0AD16LDU) Имитация срабатывания верхней АС I УР
#define idR0AD16LDU	 19	//(R0AD16LDU) Имитация срабатывания верхней АС I УР
#define R0EE01LZ1	 BUFFER[38]	//(R0EE01LZ1) Питание  АКНП1  отключить
#define idR0EE01LZ1	 20	//(R0EE01LZ1) Питание  АКНП1  отключить
#define A0EE02LZ1	 BUFFER[40]	//(A0EE02LZ1) Исправность АКНП2
#define idA0EE02LZ1	 21	//(A0EE02LZ1) Исправность АКНП2
#define A0EE03LZ1	 BUFFER[42]	//(A0EE03LZ1) Исправность АКНП3
#define idA0EE03LZ1	 22	//(A0EE03LZ1) Исправность АКНП3
#define A0EE01LS2	 BUFFER[44]	//(A0EE01LS2) Исправность АКНП  канал 2
#define idA0EE01LS2	 23	//(A0EE01LS2) Исправность АКНП  канал 2
#define A0EE05LZ1	 BUFFER[46]	//(A0EE05LZ1) Исправность сети АКНП1
#define idA0EE05LZ1	 24	//(A0EE05LZ1) Исправность сети АКНП1
#define A0EE06LZ1	 BUFFER[48]	//(A0EE06LZ1) Исправность сети АКНП2
#define idA0EE06LZ1	 25	//(A0EE06LZ1) Исправность сети АКНП2
#define A0EE07LZ1	 BUFFER[50]	//(A0EE07LZ1) Исправность сети АКНП3
#define idA0EE07LZ1	 26	//(A0EE07LZ1) Исправность сети АКНП3
#define A0EE08LZ1	 BUFFER[52]	//(A0EE08LZ1) Исправность сети АКНП4
#define idA0EE08LZ1	 27	//(A0EE08LZ1) Исправность сети АКНП4
#define A0VZ71LZ1	 BUFFER[54]	//(A0VZ71LZ1) Обобщенный сигнал АС по АЗ1
#define idA0VZ71LZ1	 28	//(A0VZ71LZ1) Обобщенный сигнал АС по АЗ1
#define A0EE00LZ1	 BUFFER[56]	//(A0EE00LZ1) Исправность АКНП АЗ1
#define idA0EE00LZ1	 29	//(A0EE00LZ1) Исправность АКНП АЗ1
#define B0EE00LZ1	 BUFFER[58]	//(B0EE00LZ1) Исправность АКНП АЗ2
#define idB0EE00LZ1	 30	//(B0EE00LZ1) Исправность АКНП АЗ2
#define B0VZ71LZ1	 BUFFER[60]	//(B0VZ71LZ1) Обобщенный сигнал АС по АЗ2
#define idB0VZ71LZ1	 31	//(B0VZ71LZ1) Обобщенный сигнал АС по АЗ2
#define A0VN71LZ1	 BUFFER[62]	//(A0VN71LZ1) АЗ по АС мощности  АЗ1
#define idA0VN71LZ1	 32	//(A0VN71LZ1) АЗ по АС мощности  АЗ1
#define B0VN71LZ1	 BUFFER[64]	//(B0VN71LZ1) АЗ по АС мощности  АЗ2
#define idB0VN71LZ1	 33	//(B0VN71LZ1) АЗ по АС мощности  АЗ2
#define A0VN81LZ1	 BUFFER[66]	//(A0VN81LZ1) АЗ по АС периода разгона АЗ1
#define idA0VN81LZ1	 34	//(A0VN81LZ1) АЗ по АС периода разгона АЗ1
#define B0VN81LZ1	 BUFFER[68]	//(B0VN81LZ1) АЗ по АС периода разгона АЗ2
#define idB0VN81LZ1	 35	//(B0VN81LZ1) АЗ по АС периода разгона АЗ2
#define R0EE02LDU	 BUFFER[70]	//(R0EE02LDU) Питание  АКНП  отключить
#define idR0EE02LDU	 36	//(R0EE02LDU) Питание  АКНП  отключить
#define R0VZ05UZ1	 BUFFER[72]	//(R0VZ05UZ1) Индикатор причины сброса
#define idR0VZ05UZ1	 37	//(R0VZ05UZ1) Индикатор причины сброса
#define R0VN11RZ1	 BUFFER[77]	//(R0VN11RZ1) Средняя мощность по БАЗ1
#define idR0VN11RZ1	 38	//(R0VN11RZ1) Средняя мощность по БАЗ1
#define R0VP73LZ1	 BUFFER[82]	//(R0VP73LZ1) ПС давления для РУ
#define idR0VP73LZ1	 39	//(R0VP73LZ1) ПС давления для РУ
#define B0CT01IZ1	 BUFFER[84]	//(B0CT01IZ1) Температура АЗ2-1
#define idB0CT01IZ1	 40	//(B0CT01IZ1) Температура АЗ2-1
#define B0VT61LZ1	 BUFFER[89]	//(B0VT61LZ1) ПС по температуре в АЗ2
#define idB0VT61LZ1	 41	//(B0VT61LZ1) ПС по температуре в АЗ2
#define R0DE06LZ1	 BUFFER[91]	//(R0DE06LZ1) диагностика модуля Баз1 на 6 месте
#define idR0DE06LZ1	 42	//(R0DE06LZ1) диагностика модуля Баз1 на 6 месте
#define R0DE08LZ1	 BUFFER[94]	//(R0DE08LZ1) диагностика модуля Баз1 на 8 месте
#define idR0DE08LZ1	 43	//(R0DE08LZ1) диагностика модуля Баз1 на 8 месте
#define R0DE07LZ1	 BUFFER[97]	//(R0DE07LZ1) диагностика модуля Баз1 на 7 месте
#define idR0DE07LZ1	 44	//(R0DE07LZ1) диагностика модуля Баз1 на 7 месте
#define R0DE0ALZ1	 BUFFER[100]	//(R0DE0ALZ1) диагностика модуля Баз1 на 10 месте
#define idR0DE0ALZ1	 45	//(R0DE0ALZ1) диагностика модуля Баз1 на 10 месте
#define TTLBaz1	 BUFFER[103]	//(TTLBaz1) ttl
#define idTTLBaz1	 46	//(TTLBaz1) ttl
#define R0DE31LZ1	 BUFFER[106]	//(R0DE31LZ1) диагностика шкафа Баз1 сеть 1
#define idR0DE31LZ1	 47	//(R0DE31LZ1) диагностика шкафа Баз1 сеть 1
#define R0DE32LZ1	 BUFFER[108]	//(R0DE32LZ1) диагностика шкафа Баз1 сеть 2
#define idR0DE32LZ1	 48	//(R0DE32LZ1) диагностика шкафа Баз1 сеть 2
#define R0DE34LZ1	 BUFFER[110]	//(R0DE34LZ1) диагностика шкафа Баз1 температура меньше 43
#define idR0DE34LZ1	 49	//(R0DE34LZ1) диагностика шкафа Баз1 температура меньше 43
#define R0DE33LZ1	 BUFFER[112]	//(R0DE33LZ1) диагностика шкафа Баз1 двери
#define idR0DE33LZ1	 50	//(R0DE33LZ1) диагностика шкафа Баз1 двери
#define R0DE36LZ1	 BUFFER[114]	//(R0DE36LZ1) диагностика шкафа Баз1 МП15-3.1 место 1
#define idR0DE36LZ1	 51	//(R0DE36LZ1) диагностика шкафа Баз1 МП15-3.1 место 1
#define R0DE37LZ1	 BUFFER[116]	//(R0DE37LZ1) диагностика шкафа Баз1 МП15-3.1 место 2
#define idR0DE37LZ1	 52	//(R0DE37LZ1) диагностика шкафа Баз1 МП15-3.1 место 2
#define R0DE35LZ1	 BUFFER[118]	//(R0DE35LZ1) диагностика шкафа Баз1 температура больше 53
#define idR0DE35LZ1	 53	//(R0DE35LZ1) диагностика шкафа Баз1 температура больше 53
#define R0DE39LZ1	 BUFFER[120]	//(R0DE39LZ1) диагностика шкафа Баз1 МП24-2 место 4
#define idR0DE39LZ1	 54	//(R0DE39LZ1) диагностика шкафа Баз1 МП24-2 место 4
#define R0DE38LZ1	 BUFFER[122]	//(R0DE38LZ1) диагностика шкафа Баз1 МП15-3 место 3
#define idR0DE38LZ1	 55	//(R0DE38LZ1) диагностика шкафа Баз1 МП15-3 место 3
#define R0DEB1LZ1	 BUFFER[124]	//(R0DEB1LZ1) диагностика шкафа Баз1 БП5 место 5
#define idR0DEB1LZ1	 56	//(R0DEB1LZ1) диагностика шкафа Баз1 БП5 место 5
#define R0DEB2LZ1	 BUFFER[126]	//(R0DEB2LZ1) диагностика шкафа Баз1 БП24Д место 5
#define idR0DEB2LZ1	 57	//(R0DEB2LZ1) диагностика шкафа Баз1 БП24Д место 5
#define R0DEB4LZ1	 BUFFER[128]	//(R0DEB4LZ1) диагностика шкафа Баз1 БП24Д место 6
#define idR0DEB4LZ1	 58	//(R0DEB4LZ1) диагностика шкафа Баз1 БП24Д место 6
#define R0DEB3LZ1	 BUFFER[130]	//(R0DEB3LZ1) диагностика шкафа Баз1 БП5 место 6
#define idR0DEB3LZ1	 59	//(R0DEB3LZ1) диагностика шкафа Баз1 БП5 место 6
#define R0DE3CLZ1	 BUFFER[132]	//(R0DE3CLZ1) диагностика шкафа Баз1 БП5/24Д место 5
#define idR0DE3CLZ1	 60	//(R0DE3CLZ1) диагностика шкафа Баз1 БП5/24Д место 5
#define R0DE3DLZ1	 BUFFER[134]	//(R0DE3DLZ1) диагностика шкафа Баз1 БП5/24Д место 6
#define idR0DE3DLZ1	 61	//(R0DE3DLZ1) диагностика шкафа Баз1 БП5/24Д место 6
#define TestDiagnBaz1	 BUFFER[136]	//(TestDiagnBaz1) Неисправность от диагностики
#define idTestDiagnBaz1	 62	//(TestDiagnBaz1) Неисправность от диагностики
#define R6IS66LZZ	 BUFFER[138]	//(R6IS66LZZ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 63	//(R6IS66LZZ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	 BUFFER[140]	//(R6IS67LZZ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 64	//(R6IS67LZZ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	 BUFFER[142]	//(R6IS68LZZ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 65	//(R6IS68LZZ) Исправность ВИП 4,0 (№7) ССДИ-2
#define R0VN71LZ1	 BUFFER[144]	//(R0VN71LZ1) АС по мощности канал 1
#define idR0VN71LZ1	 66	//(R0VN71LZ1) АС по мощности канал 1
#define R0VN75LZ1	 BUFFER[146]	//(R0VN75LZ1) АС по периоду разгона канал 1
#define idR0VN75LZ1	 67	//(R0VN75LZ1) АС по периоду разгона канал 1
#define R0VN72LZ1	 BUFFER[148]	//(R0VN72LZ1) АС по мощности канал 2
#define idR0VN72LZ1	 68	//(R0VN72LZ1) АС по мощности канал 2
#define R0VN76LZ1	 BUFFER[150]	//(R0VN76LZ1) АС по периоду разгона канал  2
#define idR0VN76LZ1	 69	//(R0VN76LZ1) АС по периоду разгона канал  2
#define R0VN73LZ1	 BUFFER[152]	//(R0VN73LZ1) АС по мощности канал 3
#define idR0VN73LZ1	 70	//(R0VN73LZ1) АС по мощности канал 3
#define R0VN77LZ1	 BUFFER[154]	//(R0VN77LZ1) АС по периоду разгона канал  3
#define idR0VN77LZ1	 71	//(R0VN77LZ1) АС по периоду разгона канал  3
#define R0VN74LZ1	 BUFFER[156]	//(R0VN74LZ1) АС по мощности канал 4
#define idR0VN74LZ1	 72	//(R0VN74LZ1) АС по мощности канал 4
#define R0VN78LZ1	 BUFFER[158]	//(R0VN78LZ1) АС по периоду разгона канал  4
#define idR0VN78LZ1	 73	//(R0VN78LZ1) АС по периоду разгона канал  4
#define R0EE02LZ1	 BUFFER[160]	//(R0EE02LZ1) Питание  АКНП2  отключить
#define idR0EE02LZ1	 74	//(R0EE02LZ1) Питание  АКНП2  отключить
#define R0EE03LZ1	 BUFFER[162]	//(R0EE03LZ1) Питание  АКНП3  отключить
#define idR0EE03LZ1	 75	//(R0EE03LZ1) Питание  АКНП3  отключить
#define R0EE04LZ1	 BUFFER[164]	//(R0EE04LZ1) Питание  АКНП4  отключить
#define idR0EE04LZ1	 76	//(R0EE04LZ1) Питание  АКНП4  отключить
#define R0AD15LZ1	 BUFFER[166]	//(R0AD15LZ1) Имитация АЗ от 1УР (датчик1)
#define idR0AD15LZ1	 77	//(R0AD15LZ1) Имитация АЗ от 1УР (датчик1)
#define R0AD16LZ1	 BUFFER[168]	//(R0AD16LZ1) Имитация АЗ от 1УР (датчик2)
#define idR0AD16LZ1	 78	//(R0AD16LZ1) Имитация АЗ от 1УР (датчик2)
#define R0MW12IP2	 BUFFER[170]	//(R0MW12IP2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define idR0MW12IP2	 79	//(R0MW12IP2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define A2IS12LDU	 BUFFER[173]	//(A2IS12LDU) Магнит РБ1 зацеплен
#define idA2IS12LDU	 80	//(A2IS12LDU) Магнит РБ1 зацеплен
#define B2IS12LDU	 BUFFER[175]	//(B2IS12LDU) Магнит РБ2 зацеплен
#define idB2IS12LDU	 81	//(B2IS12LDU) Магнит РБ2 зацеплен
#define R0DE04LZ1	 BUFFER[177]	//(R0DE04LZ1) диагностика модуля Баз1 на 4 месте
#define idR0DE04LZ1	 82	//(R0DE04LZ1) диагностика модуля Баз1 на 4 месте
#define R0DE05LZ1	 BUFFER[180]	//(R0DE05LZ1) диагностика модуля Баз1 на 5 месте
#define idR0DE05LZ1	 83	//(R0DE05LZ1) диагностика модуля Баз1 на 5 месте
#define B0VP41LZ1	 BUFFER[183]	//(B0VP41LZ1) Давление АЗ2 ниже АС
#define idB0VP41LZ1	 84	//(B0VP41LZ1) Давление АЗ2 ниже АС
#define B0VP81LZZ	 BUFFER[185]	//(B0VP81LZZ) Давление АЗ2 в норме
#define idB0VP81LZZ	 85	//(B0VP81LZZ) Давление АЗ2 в норме
#define A0VP81LZZ	 BUFFER[187]	//(A0VP81LZZ) Давление  АЗ1 в норме
#define idA0VP81LZZ	 86	//(A0VP81LZZ) Давление  АЗ1 в норме
#define R0ET02LZ1	 BUFFER[189]	//(R0ET02LZ1) Признак наличия неисправности по температуре АЗ2
#define idR0ET02LZ1	 87	//(R0ET02LZ1) Признак наличия неисправности по температуре АЗ2
#define B0EP02IZ1	 BUFFER[191]	//(B0EP02IZ1) Индикатор -Давление  АЗ2 ниже АС
#define idB0EP02IZ1	 88	//(B0EP02IZ1) Индикатор -Давление  АЗ2 ниже АС
#define A0EP02IZ1	 BUFFER[194]	//(A0EP02IZ1) Индикатор -Давление  АЗ1 ниже АС
#define idA0EP02IZ1	 89	//(A0EP02IZ1) Индикатор -Давление  АЗ1 ниже АС
#define A0VP71LZ1	 BUFFER[197]	//(A0VP71LZ1) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ1	 90	//(A0VP71LZ1) АЗ по АС любого давления для АЗ1
#define B0VP71LZ1	 BUFFER[199]	//(B0VP71LZ1) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ1	 91	//(B0VP71LZ1) АЗ по АС любого давления для АЗ2
#define R0VN02RS1	 BUFFER[201]	//(R0VN02RS1) Уровень мощности канал 1
#define idR0VN02RS1	 92	//(R0VN02RS1) Уровень мощности канал 1
#define R0VN02RS2	 BUFFER[206]	//(R0VN02RS2) Уровень мощности канал 2
#define idR0VN02RS2	 93	//(R0VN02RS2) Уровень мощности канал 2
#define R0VN02RS3	 BUFFER[211]	//(R0VN02RS3) Уровень мощности канал 3
#define idR0VN02RS3	 94	//(R0VN02RS3) Уровень мощности канал 3
#define R0VN02RS4	 BUFFER[216]	//(R0VN02RS4) Уровень мощности канал 4
#define idR0VN02RS4	 95	//(R0VN02RS4) Уровень мощности канал 4
#define R0VN01RS1	 BUFFER[221]	//(R0VN01RS1) Период разгона канал 1
#define idR0VN01RS1	 96	//(R0VN01RS1) Период разгона канал 1
#define R0VN01RS2	 BUFFER[226]	//(R0VN01RS2) Период разгона канал 2
#define idR0VN01RS2	 97	//(R0VN01RS2) Период разгона канал 2
#define R0VN01RS3	 BUFFER[231]	//(R0VN01RS3) Период разгона канал 3
#define idR0VN01RS3	 98	//(R0VN01RS3) Период разгона канал 3
#define R0VN01RS4	 BUFFER[236]	//(R0VN01RS4) Период разгона канал 4
#define idR0VN01RS4	 99	//(R0VN01RS4) Период разгона канал 4
#define R0VN61LS1	 BUFFER[241]	//(R0VN61LS1) ПС по мощности канал 1
#define idR0VN61LS1	 100	//(R0VN61LS1) ПС по мощности канал 1
#define R0VN61LS2	 BUFFER[243]	//(R0VN61LS2) ПС по мощности канал 2
#define idR0VN61LS2	 101	//(R0VN61LS2) ПС по мощности канал 2
#define R0VN61LS3	 BUFFER[245]	//(R0VN61LS3) ПС по мощности канал 3
#define idR0VN61LS3	 102	//(R0VN61LS3) ПС по мощности канал 3
#define R0VN61LS4	 BUFFER[247]	//(R0VN61LS4) ПС по мощности канал 4
#define idR0VN61LS4	 103	//(R0VN61LS4) ПС по мощности канал 4
#define A0IT01IZ1	 BUFFER[249]	//(A0IT01IZ1) Температура АЗ1-1
#define idA0IT01IZ1	 104	//(A0IT01IZ1) Температура АЗ1-1
#define A0CT01IZ1	 BUFFER[252]	//(A0CT01IZ1) Температура АЗ1-1
#define idA0CT01IZ1	 105	//(A0CT01IZ1) Температура АЗ1-1
#define A0VT61LZ1	 BUFFER[257]	//(A0VT61LZ1) ПС по температуре в АЗ1
#define idA0VT61LZ1	 106	//(A0VT61LZ1) ПС по температуре в АЗ1
#define A0VT71LZ1	 BUFFER[259]	//(A0VT71LZ1) АС по температуре в АЗ1
#define idA0VT71LZ1	 107	//(A0VT71LZ1) АС по температуре в АЗ1
#define A1VP41LZ1	 BUFFER[261]	//(A1VP41LZ1) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ1	 108	//(A1VP41LZ1) Давление СБРОС ББ1 ниже АС
#define B1VP41LZ1	 BUFFER[263]	//(B1VP41LZ1) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ1	 109	//(B1VP41LZ1) Давление СБРОС ББ2 ниже АС
#define B1VP81LZZ	 BUFFER[265]	//(B1VP81LZZ) Давление СБРОС ББ2 в норме
#define idB1VP81LZZ	 110	//(B1VP81LZZ) Давление СБРОС ББ2 в норме
#define A1VP81LZZ	 BUFFER[267]	//(A1VP81LZZ) Давление СБРОС ББ1 в норме
#define idA1VP81LZZ	 111	//(A1VP81LZZ) Давление СБРОС ББ1 в норме
#define A2VP41LZ1	 BUFFER[269]	//(A2VP41LZ1) Давление СБРОС РБ1 ниже АС
#define idA2VP41LZ1	 112	//(A2VP41LZ1) Давление СБРОС РБ1 ниже АС
#define A2CP01RZ1	 BUFFER[271]	//(A2CP01RZ1) Текущее давление СБРОС РБ1
#define idA2CP01RZ1	 113	//(A2CP01RZ1) Текущее давление СБРОС РБ1
#define A2VP51LZ1	 BUFFER[276]	//(A2VP51LZ1) Давление СБРОС РБ1 ниже ПС
#define idA2VP51LZ1	 114	//(A2VP51LZ1) Давление СБРОС РБ1 ниже ПС
#define B2VP41LZ1	 BUFFER[278]	//(B2VP41LZ1) Давление СБРОС РБ2 ниже АС
#define idB2VP41LZ1	 115	//(B2VP41LZ1) Давление СБРОС РБ2 ниже АС
#define B2CP01RZ1	 BUFFER[280]	//(B2CP01RZ1) Текущее давление СБРОС РБ2
#define idB2CP01RZ1	 116	//(B2CP01RZ1) Текущее давление СБРОС РБ2
#define B2VP51LZ1	 BUFFER[285]	//(B2VP51LZ1) Давление СБРОС РБ2 ниже ПС
#define idB2VP51LZ1	 117	//(B2VP51LZ1) Давление СБРОС РБ2 ниже ПС
#define B2VP81LZ1	 BUFFER[287]	//(B2VP81LZ1) Давление СБРОС РБ2 в норме
#define idB2VP81LZ1	 118	//(B2VP81LZ1) Давление СБРОС РБ2 в норме
#define A2VP81LZ1	 BUFFER[289]	//(A2VP81LZ1) Давление СБРОС РБ1 в норме
#define idA2VP81LZ1	 119	//(A2VP81LZ1) Давление СБРОС РБ1 в норме
#define A2IP01IZ1	 BUFFER[291]	//(A2IP01IZ1) Текущее давление СБРОС РБ1
#define idA2IP01IZ1	 120	//(A2IP01IZ1) Текущее давление СБРОС РБ1
#define B2IP01IZ1	 BUFFER[294]	//(B2IP01IZ1) Текущее давление СБРОС РБ2
#define idB2IP01IZ1	 121	//(B2IP01IZ1) Текущее давление СБРОС РБ2
#define R0ET01LZ1	 BUFFER[297]	//(R0ET01LZ1) Признак наличия неисправности по температуре  АЗ1
#define idR0ET01LZ1	 122	//(R0ET01LZ1) Признак наличия неисправности по температуре  АЗ1
#define B0IT01IZ1	 BUFFER[299]	//(B0IT01IZ1) Температура АЗ2-1
#define idB0IT01IZ1	 123	//(B0IT01IZ1) Температура АЗ2-1
#define A0VP41LZ1	 BUFFER[302]	//(A0VP41LZ1) Давление АЗ1 ниже АС
#define idA0VP41LZ1	 124	//(A0VP41LZ1) Давление АЗ1 ниже АС
#define A3IS11LDU	 BUFFER[304]	//(A3IS11LDU) Приход на ВУ ИС1
#define idA3IS11LDU	 125	//(A3IS11LDU) Приход на ВУ ИС1
#define A3IS22LDU	 BUFFER[306]	//(A3IS22LDU) Приход на НУП ИС1
#define idA3IS22LDU	 126	//(A3IS22LDU) Приход на НУП ИС1
#define R0AD03LZ1	 BUFFER[308]	//(R0AD03LZ1) Имитация прихода на ВУ ИС
#define idR0AD03LZ1	 127	//(R0AD03LZ1) Имитация прихода на ВУ ИС
#define B3IS11LDU	 BUFFER[310]	//(B3IS11LDU) Приход на ВУ ИС2
#define idB3IS11LDU	 128	//(B3IS11LDU) Приход на ВУ ИС2
#define A3VZ31LZ1	 BUFFER[312]	//(A3VZ31LZ1) АЗ от ВУ ИС1
#define idA3VZ31LZ1	 129	//(A3VZ31LZ1) АЗ от ВУ ИС1
#define B3VZ31LZ1	 BUFFER[314]	//(B3VZ31LZ1) АЗ от ВУ ИС2
#define idB3VZ31LZ1	 130	//(B3VZ31LZ1) АЗ от ВУ ИС2
#define R0AD05LZ1	 BUFFER[316]	//(R0AD05LZ1) Имитация ухода с НУП ИС
#define idR0AD05LZ1	 131	//(R0AD05LZ1) Имитация ухода с НУП ИС
#define A3VZ11LZ1	 BUFFER[318]	//(A3VZ11LZ1) АЗ от НУП ИС1
#define idA3VZ11LZ1	 132	//(A3VZ11LZ1) АЗ от НУП ИС1
#define B3VZ11LZ1	 BUFFER[320]	//(B3VZ11LZ1) АЗ от НУП ИС2
#define idB3VZ11LZ1	 133	//(B3VZ11LZ1) АЗ от НУП ИС2
#define B3IS22LDU	 BUFFER[322]	//(B3IS22LDU) Приход на НУП ИС2
#define idB3IS22LDU	 134	//(B3IS22LDU) Приход на НУП ИС2
#define R0VN69LZ1	 BUFFER[324]	//(R0VN69LZ1) ПС по усредненному периоду
#define idR0VN69LZ1	 135	//(R0VN69LZ1) ПС по усредненному периоду
#define R0VN79LZ1	 BUFFER[326]	//(R0VN79LZ1) АС по усредненному периоду
#define idR0VN79LZ1	 136	//(R0VN79LZ1) АС по усредненному периоду
#define R0VR02RZ1	 BUFFER[328]	//(R0VR02RZ1) Усредненная реактивность
#define idR0VR02RZ1	 137	//(R0VR02RZ1) Усредненная реактивность
#define R0VZ71LZ1	 BUFFER[333]	//(R0VZ71LZ1) Обобщенный сигнал АЗ 1 канала
#define idR0VZ71LZ1	 138	//(R0VZ71LZ1) Обобщенный сигнал АЗ 1 канала
#define R0VN70LZ1	 BUFFER[335]	//(R0VN70LZ1) АЗ по АС мощности РУ
#define idR0VN70LZ1	 139	//(R0VN70LZ1) АЗ по АС мощности РУ
#define R0VN80LZ1	 BUFFER[337]	//(R0VN80LZ1) АЗ по АС периода разгона РУ
#define idR0VN80LZ1	 140	//(R0VN80LZ1) АЗ по АС периода разгона РУ
#define A0EE01LS1	 BUFFER[339]	//(A0EE01LS1) Исправность АКНП канал 1
#define idA0EE01LS1	 141	//(A0EE01LS1) Исправность АКНП канал 1
#define A0EE01LS4	 BUFFER[341]	//(A0EE01LS4) Исправность АКНП канал 4
#define idA0EE01LS4	 142	//(A0EE01LS4) Исправность АКНП канал 4
#define A0EE01LS3	 BUFFER[343]	//(A0EE01LS3) Исправность АКНП канал 3
#define idA0EE01LS3	 143	//(A0EE01LS3) Исправность АКНП канал 3
#define A0EE01LZ1	 BUFFER[345]	//(A0EE01LZ1) Исправность АКНП1
#define idA0EE01LZ1	 144	//(A0EE01LZ1) Исправность АКНП1
#define A0EE04LZ1	 BUFFER[347]	//(A0EE04LZ1) Исправность АКНП4
#define idA0EE04LZ1	 145	//(A0EE04LZ1) Исправность АКНП4
#define R0VN65LS1	 BUFFER[349]	//(R0VN65LS1) ПС по периоду разгона канал 1
#define idR0VN65LS1	 146	//(R0VN65LS1) ПС по периоду разгона канал 1
#define R0VN65LS2	 BUFFER[351]	//(R0VN65LS2) ПС по периоду разгона  канал 2
#define idR0VN65LS2	 147	//(R0VN65LS2) ПС по периоду разгона  канал 2
#define R0VN65LS3	 BUFFER[353]	//(R0VN65LS3) ПС по периоду разгона канал 3
#define idR0VN65LS3	 148	//(R0VN65LS3) ПС по периоду разгона канал 3
#define R0VN65LS4	 BUFFER[355]	//(R0VN65LS4) ПС по периоду разгона канал 4
#define idR0VN65LS4	 149	//(R0VN65LS4) ПС по периоду разгона канал 4
#define R0VN01RZ1	 BUFFER[357]	//(R0VN01RZ1) Уровень мощности по каналу 1
#define idR0VN01RZ1	 150	//(R0VN01RZ1) Уровень мощности по каналу 1
#define R0VN02RZ1	 BUFFER[362]	//(R0VN02RZ1) Уровень мощности по каналу 2
#define idR0VN02RZ1	 151	//(R0VN02RZ1) Уровень мощности по каналу 2
#define R0VN03RZ1	 BUFFER[367]	//(R0VN03RZ1) Уровень мощности по каналу 3
#define idR0VN03RZ1	 152	//(R0VN03RZ1) Уровень мощности по каналу 3
#define R0VN04RZ1	 BUFFER[372]	//(R0VN04RZ1) Уровень мощности по каналу 4
#define idR0VN04RZ1	 153	//(R0VN04RZ1) Уровень мощности по каналу 4
#define R0VN05RZ1	 BUFFER[377]	//(R0VN05RZ1) Период разгона по каналу 1
#define idR0VN05RZ1	 154	//(R0VN05RZ1) Период разгона по каналу 1
#define R0VN06RZ1	 BUFFER[382]	//(R0VN06RZ1) Период разгона по каналу 2
#define idR0VN06RZ1	 155	//(R0VN06RZ1) Период разгона по каналу 2
#define R0VN07RZ1	 BUFFER[387]	//(R0VN07RZ1) Период разгона по каналу 3
#define idR0VN07RZ1	 156	//(R0VN07RZ1) Период разгона по каналу 3
#define R0VN08RZ1	 BUFFER[392]	//(R0VN08RZ1) Период разгона по каналу 4
#define idR0VN08RZ1	 157	//(R0VN08RZ1) Период разгона по каналу 4
#define R0VN61LZ1	 BUFFER[397]	//(R0VN61LZ1) ПС по мощности канал 1
#define idR0VN61LZ1	 158	//(R0VN61LZ1) ПС по мощности канал 1
#define R0VN62LZ1	 BUFFER[399]	//(R0VN62LZ1) ПС по мощности канал 2
#define idR0VN62LZ1	 159	//(R0VN62LZ1) ПС по мощности канал 2
#define R0VN63LZ1	 BUFFER[401]	//(R0VN63LZ1) ПС по мощности канал 3
#define idR0VN63LZ1	 160	//(R0VN63LZ1) ПС по мощности канал 3
#define R0VN64LZ1	 BUFFER[403]	//(R0VN64LZ1) ПС по мощности канал 4
#define idR0VN64LZ1	 161	//(R0VN64LZ1) ПС по мощности канал 4
#define R0VN65LZ1	 BUFFER[405]	//(R0VN65LZ1) ПС по периоду разгона канал 1
#define idR0VN65LZ1	 162	//(R0VN65LZ1) ПС по периоду разгона канал 1
#define R0VN66LZ1	 BUFFER[407]	//(R0VN66LZ1) ПС по периоду разгона канал 2
#define idR0VN66LZ1	 163	//(R0VN66LZ1) ПС по периоду разгона канал 2
#define R0VN67LZ1	 BUFFER[409]	//(R0VN67LZ1) ПС по периоду разгона канал 3
#define idR0VN67LZ1	 164	//(R0VN67LZ1) ПС по периоду разгона канал 3
#define R0VN68LZ1	 BUFFER[411]	//(R0VN68LZ1) ПС по периоду разгона канал 4
#define idR0VN68LZ1	 165	//(R0VN68LZ1) ПС по периоду разгона канал 4
#define R0VN09RZ1	 BUFFER[413]	//(R0VN09RZ1) Усредненный период разгона
#define idR0VN09RZ1	 166	//(R0VN09RZ1) Усредненный период разгона
#define fEM_R0UT02RZZ	 BUFFER[418]	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RZZ	 167	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define fEM_R0UT01RZZ	 BUFFER[423]	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RZZ	 168	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define fEM_A2UP03RZZ	 BUFFER[428]	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define idfEM_A2UP03RZZ	 169	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define fEM_A2UP04RZZ	 BUFFER[433]	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define idfEM_A2UP04RZZ	 170	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define fEM_R0UT72RZZ	 BUFFER[438]	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define idfEM_R0UT72RZZ	 171	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define fEM_R0UT71RZZ	 BUFFER[443]	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define idfEM_R0UT71RZZ	 172	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define fEM_R0UT62RZZ	 BUFFER[448]	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define idfEM_R0UT62RZZ	 173	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define fEM_R0UT61RZZ	 BUFFER[453]	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define idfEM_R0UT61RZZ	 174	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define fEM_A2UP41RZZ	 BUFFER[458]	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define idfEM_A2UP41RZZ	 175	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define fEM_A2UP42RZZ	 BUFFER[463]	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define idfEM_A2UP42RZZ	 176	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define fEM_A2UP51RZZ	 BUFFER[468]	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define idfEM_A2UP51RZZ	 177	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define fEM_A2UP81RZZ	 BUFFER[473]	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP81RZZ	 178	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP84RZZ	 BUFFER[478]	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP84RZZ	 179	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP82RZZ	 BUFFER[483]	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP82RZZ	 180	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP52RZZ	 BUFFER[488]	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define idfEM_A2UP52RZZ	 181	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define fEM_A2UP83RZZ	 BUFFER[493]	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP83RZZ	 182	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_R0UR01RZZ	 BUFFER[498]	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define idfEM_R0UR01RZZ	 183	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define fEM_R0UR04RZZ	 BUFFER[503]	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define idfEM_R0UR04RZZ	 184	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define fEM_A1UL12RZZ	 BUFFER[508]	//(A1UL12RZZ) Время задержки АЗ от НУ ИС(сек)
#define idfEM_A1UL12RZZ	 185	//(A1UL12RZZ) Время задержки АЗ от НУ ИС(сек)
#define fEM_A1UL11RZZ	 BUFFER[513]	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
#define idfEM_A1UL11RZZ	 186	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
#define fEM_R7UI73RZZ	 BUFFER[518]	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
#define idfEM_R7UI73RZZ	 187	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
#define bFirstEnterFlag	 BUFFER[523]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 188	//(bFirstEnterFlag) 
#define internal1_m244_tx	 BUFFER[525]	//(internal1_m244_tx) tx - время накопленное сек
#define idinternal1_m244_tx	 189	//(internal1_m244_tx) tx - время накопленное сек
#define internal1_m244_y0	 BUFFER[530]	//(internal1_m244_y0) y0
#define idinternal1_m244_y0	 190	//(internal1_m244_y0) y0
#define internal1_m252_tx	 BUFFER[531]	//(internal1_m252_tx) tx - время накопленное сек
#define idinternal1_m252_tx	 191	//(internal1_m252_tx) tx - время накопленное сек
#define internal1_m252_y0	 BUFFER[536]	//(internal1_m252_y0) y0
#define idinternal1_m252_y0	 192	//(internal1_m252_y0) y0
#define internal1_m315_tx	 BUFFER[537]	//(internal1_m315_tx) tx - время накопленное сек
#define idinternal1_m315_tx	 193	//(internal1_m315_tx) tx - время накопленное сек
#define internal1_m315_y0	 BUFFER[542]	//(internal1_m315_y0) y0
#define idinternal1_m315_y0	 194	//(internal1_m315_y0) y0
#define internal1_m211_tx	 BUFFER[543]	//(internal1_m211_tx) tx - время накопленное сек
#define idinternal1_m211_tx	 195	//(internal1_m211_tx) tx - время накопленное сек
#define internal1_m211_y0	 BUFFER[548]	//(internal1_m211_y0) y0
#define idinternal1_m211_y0	 196	//(internal1_m211_y0) y0
#define internal1_m210_tx	 BUFFER[549]	//(internal1_m210_tx) tx - время накопленное сек
#define idinternal1_m210_tx	 197	//(internal1_m210_tx) tx - время накопленное сек
#define internal1_m210_y0	 BUFFER[554]	//(internal1_m210_y0) y0
#define idinternal1_m210_y0	 198	//(internal1_m210_y0) y0
#define internal1_m208_tx	 BUFFER[555]	//(internal1_m208_tx) tx - время накопленное сек
#define idinternal1_m208_tx	 199	//(internal1_m208_tx) tx - время накопленное сек
#define internal1_m208_y0	 BUFFER[560]	//(internal1_m208_y0) y0
#define idinternal1_m208_y0	 200	//(internal1_m208_y0) y0
#define internal1_m206_tx	 BUFFER[561]	//(internal1_m206_tx) tx - время накопленное сек
#define idinternal1_m206_tx	 201	//(internal1_m206_tx) tx - время накопленное сек
#define internal1_m206_y0	 BUFFER[566]	//(internal1_m206_y0) y0
#define idinternal1_m206_y0	 202	//(internal1_m206_y0) y0
#define internal1_m33_tx	 BUFFER[567]	//(internal1_m33_tx) tx - внутренний параметр
#define idinternal1_m33_tx	 203	//(internal1_m33_tx) tx - внутренний параметр
#define internal1_m143_y0	 BUFFER[570]	//(internal1_m143_y0) y0
#define idinternal1_m143_y0	 204	//(internal1_m143_y0) y0
#define internal1_m141_y0	 BUFFER[575]	//(internal1_m141_y0) y0
#define idinternal1_m141_y0	 205	//(internal1_m141_y0) y0
#define internal1_m93_y0	 BUFFER[580]	//(internal1_m93_y0) y0
#define idinternal1_m93_y0	 206	//(internal1_m93_y0) y0
#define internal1_m91_y0	 BUFFER[585]	//(internal1_m91_y0) y0
#define idinternal1_m91_y0	 207	//(internal1_m91_y0) y0
#define internal1_m154_y1	 BUFFER[590]	//(internal1_m154_y1) y1 - внутренний параметр
#define idinternal1_m154_y1	 208	//(internal1_m154_y1) y1 - внутренний параметр
#define internal1_m165_y1	 BUFFER[592]	//(internal1_m165_y1) y1 - внутренний параметр
#define idinternal1_m165_y1	 209	//(internal1_m165_y1) y1 - внутренний параметр
#define internal1_m308_q0	 BUFFER[594]	//(internal1_m308_q0) q0 - внутренний параметр
#define idinternal1_m308_q0	 210	//(internal1_m308_q0) q0 - внутренний параметр
#define internal1_m130_y0	 BUFFER[599]	//(internal1_m130_y0) state
#define idinternal1_m130_y0	 211	//(internal1_m130_y0) state
#define internal1_m123_y0	 BUFFER[601]	//(internal1_m123_y0) state
#define idinternal1_m123_y0	 212	//(internal1_m123_y0) state
#define internal1_m107_y1	 BUFFER[603]	//(internal1_m107_y1) y1 - внутренний параметр
#define idinternal1_m107_y1	 213	//(internal1_m107_y1) y1 - внутренний параметр
#define internal1_m116_y1	 BUFFER[605]	//(internal1_m116_y1) y1 - внутренний параметр
#define idinternal1_m116_y1	 214	//(internal1_m116_y1) y1 - внутренний параметр
#define internal1_m97_y1	 BUFFER[607]	//(internal1_m97_y1) y1 - внутренний параметр
#define idinternal1_m97_y1	 215	//(internal1_m97_y1) y1 - внутренний параметр
#define internal1_m105_y1	 BUFFER[609]	//(internal1_m105_y1) y1 - внутренний параметр
#define idinternal1_m105_y1	 216	//(internal1_m105_y1) y1 - внутренний параметр
#define internal1_m152_y1	 BUFFER[611]	//(internal1_m152_y1) y1 - внутренний параметр
#define idinternal1_m152_y1	 217	//(internal1_m152_y1) y1 - внутренний параметр
#define internal1_m162_y1	 BUFFER[613]	//(internal1_m162_y1) y1 - внутренний параметр
#define idinternal1_m162_y1	 218	//(internal1_m162_y1) y1 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &B0VT71LZ1},	//(B0VT71LZ1) АС по температуре в АЗ2
	{ 2	,1	,1	, &A0VN71LS1},	//(A0VN71LS1) Блокировка автоматического подъёма ББ канал 1
	{ 3	,1	,1	, &A0VN71LS2},	//(A0VN71LS2) Блокировка автоматического подъёма ББ канал 2
	{ 4	,1	,1	, &A0VN71LS3},	//(A0VN71LS3) Блокировка автоматического подъёма ББ канал 3
	{ 5	,1	,1	, &A0VN71LS4},	//(A0VN71LS4) Блокировка автоматического подъёма ББ канал 4
	{ 6	,1	,1	, &A1VN71LZ1},	//(A1VN71LZ1) Блокировка автоматического подъёма ББ
	{ 7	,1	,1	, &A3VZ15LZ1},	//(A3VZ15LZ1) Имитация АЗ от НУП ИС
	{ 8	,1	,1	, &A3VZ13LZ1},	//(A3VZ13LZ1) Имитация АЗ от ВУ ИС
	{ 9	,1	,1	, &R0VW13LDU},	//(R0VW13LDU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{ 10	,1	,1	, &R0VW23LDU},	//(R0VW23LDU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{ 11	,1	,1	, &R7II73LZ1},	//(R7II73LZ1) Сработала АС II УР РАД
	{ 12	,1	,1	, &R7II71LZ1},	//(R7II71LZ1) Сработала АС IУР РАД (датчик 1)
	{ 13	,1	,1	, &R7II72LZ1},	//(R7II72LZ1) Сработала АС IУР РАД  (датчик 2)
	{ 14	,1	,1	, &R0AD14LZ1},	//(R0AD14LZ1) Имитация АЗ от IIУР
	{ 15	,1	,1	, &R0AD21LDU},	//(R0AD21LDU) Подключить защиту от II УР
	{ 16	,1	,1	, &R0AD14LDU},	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
	{ 17	,1	,1	, &R0MD34LP1},	//(R0MD34LP1) Кнопка (Квитировать)
	{ 18	,1	,1	, &R0AD04LZ1},	//(R0AD04LZ1) Имитация срабатывания верхней АС II УР
	{ 19	,1	,1	, &R0AD16LDU},	//(R0AD16LDU) Имитация срабатывания верхней АС I УР
	{ 20	,1	,1	, &R0EE01LZ1},	//(R0EE01LZ1) Питание  АКНП1  отключить
	{ 21	,1	,1	, &A0EE02LZ1},	//(A0EE02LZ1) Исправность АКНП2
	{ 22	,1	,1	, &A0EE03LZ1},	//(A0EE03LZ1) Исправность АКНП3
	{ 23	,1	,1	, &A0EE01LS2},	//(A0EE01LS2) Исправность АКНП  канал 2
	{ 24	,1	,1	, &A0EE05LZ1},	//(A0EE05LZ1) Исправность сети АКНП1
	{ 25	,1	,1	, &A0EE06LZ1},	//(A0EE06LZ1) Исправность сети АКНП2
	{ 26	,1	,1	, &A0EE07LZ1},	//(A0EE07LZ1) Исправность сети АКНП3
	{ 27	,1	,1	, &A0EE08LZ1},	//(A0EE08LZ1) Исправность сети АКНП4
	{ 28	,1	,1	, &A0VZ71LZ1},	//(A0VZ71LZ1) Обобщенный сигнал АС по АЗ1
	{ 29	,1	,1	, &A0EE00LZ1},	//(A0EE00LZ1) Исправность АКНП АЗ1
	{ 30	,1	,1	, &B0EE00LZ1},	//(B0EE00LZ1) Исправность АКНП АЗ2
	{ 31	,1	,1	, &B0VZ71LZ1},	//(B0VZ71LZ1) Обобщенный сигнал АС по АЗ2
	{ 32	,1	,1	, &A0VN71LZ1},	//(A0VN71LZ1) АЗ по АС мощности  АЗ1
	{ 33	,1	,1	, &B0VN71LZ1},	//(B0VN71LZ1) АЗ по АС мощности  АЗ2
	{ 34	,1	,1	, &A0VN81LZ1},	//(A0VN81LZ1) АЗ по АС периода разгона АЗ1
	{ 35	,1	,1	, &B0VN81LZ1},	//(B0VN81LZ1) АЗ по АС периода разгона АЗ2
	{ 36	,1	,1	, &R0EE02LDU},	//(R0EE02LDU) Питание  АКНП  отключить
	{ 37	,5	,1	, &R0VZ05UZ1},	//(R0VZ05UZ1) Индикатор причины сброса
	{ 38	,8	,1	, &R0VN11RZ1},	//(R0VN11RZ1) Средняя мощность по БАЗ1
	{ 39	,1	,1	, &R0VP73LZ1},	//(R0VP73LZ1) ПС давления для РУ
	{ 40	,8	,1	, &B0CT01IZ1},	//(B0CT01IZ1) Температура АЗ2-1
	{ 41	,1	,1	, &B0VT61LZ1},	//(B0VT61LZ1) ПС по температуре в АЗ2
	{ 42	,3	,1	, &R0DE06LZ1},	//(R0DE06LZ1) диагностика модуля Баз1 на 6 месте
	{ 43	,3	,1	, &R0DE08LZ1},	//(R0DE08LZ1) диагностика модуля Баз1 на 8 месте
	{ 44	,3	,1	, &R0DE07LZ1},	//(R0DE07LZ1) диагностика модуля Баз1 на 7 месте
	{ 45	,3	,1	, &R0DE0ALZ1},	//(R0DE0ALZ1) диагностика модуля Баз1 на 10 месте
	{ 46	,3	,1	, &TTLBaz1},	//(TTLBaz1) ttl
	{ 47	,1	,1	, &R0DE31LZ1},	//(R0DE31LZ1) диагностика шкафа Баз1 сеть 1
	{ 48	,1	,1	, &R0DE32LZ1},	//(R0DE32LZ1) диагностика шкафа Баз1 сеть 2
	{ 49	,1	,1	, &R0DE34LZ1},	//(R0DE34LZ1) диагностика шкафа Баз1 температура меньше 43
	{ 50	,1	,1	, &R0DE33LZ1},	//(R0DE33LZ1) диагностика шкафа Баз1 двери
	{ 51	,1	,1	, &R0DE36LZ1},	//(R0DE36LZ1) диагностика шкафа Баз1 МП15-3.1 место 1
	{ 52	,1	,1	, &R0DE37LZ1},	//(R0DE37LZ1) диагностика шкафа Баз1 МП15-3.1 место 2
	{ 53	,1	,1	, &R0DE35LZ1},	//(R0DE35LZ1) диагностика шкафа Баз1 температура больше 53
	{ 54	,1	,1	, &R0DE39LZ1},	//(R0DE39LZ1) диагностика шкафа Баз1 МП24-2 место 4
	{ 55	,1	,1	, &R0DE38LZ1},	//(R0DE38LZ1) диагностика шкафа Баз1 МП15-3 место 3
	{ 56	,1	,1	, &R0DEB1LZ1},	//(R0DEB1LZ1) диагностика шкафа Баз1 БП5 место 5
	{ 57	,1	,1	, &R0DEB2LZ1},	//(R0DEB2LZ1) диагностика шкафа Баз1 БП24Д место 5
	{ 58	,1	,1	, &R0DEB4LZ1},	//(R0DEB4LZ1) диагностика шкафа Баз1 БП24Д место 6
	{ 59	,1	,1	, &R0DEB3LZ1},	//(R0DEB3LZ1) диагностика шкафа Баз1 БП5 место 6
	{ 60	,1	,1	, &R0DE3CLZ1},	//(R0DE3CLZ1) диагностика шкафа Баз1 БП5/24Д место 5
	{ 61	,1	,1	, &R0DE3DLZ1},	//(R0DE3DLZ1) диагностика шкафа Баз1 БП5/24Д место 6
	{ 62	,1	,1	, &TestDiagnBaz1},	//(TestDiagnBaz1) Неисправность от диагностики
	{ 63	,1	,1	, &R6IS66LZZ},	//(R6IS66LZZ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 64	,1	,1	, &R6IS67LZZ},	//(R6IS67LZZ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 65	,1	,1	, &R6IS68LZZ},	//(R6IS68LZZ) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 66	,1	,1	, &R0VN71LZ1},	//(R0VN71LZ1) АС по мощности канал 1
	{ 67	,1	,1	, &R0VN75LZ1},	//(R0VN75LZ1) АС по периоду разгона канал 1
	{ 68	,1	,1	, &R0VN72LZ1},	//(R0VN72LZ1) АС по мощности канал 2
	{ 69	,1	,1	, &R0VN76LZ1},	//(R0VN76LZ1) АС по периоду разгона канал  2
	{ 70	,1	,1	, &R0VN73LZ1},	//(R0VN73LZ1) АС по мощности канал 3
	{ 71	,1	,1	, &R0VN77LZ1},	//(R0VN77LZ1) АС по периоду разгона канал  3
	{ 72	,1	,1	, &R0VN74LZ1},	//(R0VN74LZ1) АС по мощности канал 4
	{ 73	,1	,1	, &R0VN78LZ1},	//(R0VN78LZ1) АС по периоду разгона канал  4
	{ 74	,1	,1	, &R0EE02LZ1},	//(R0EE02LZ1) Питание  АКНП2  отключить
	{ 75	,1	,1	, &R0EE03LZ1},	//(R0EE03LZ1) Питание  АКНП3  отключить
	{ 76	,1	,1	, &R0EE04LZ1},	//(R0EE04LZ1) Питание  АКНП4  отключить
	{ 77	,1	,1	, &R0AD15LZ1},	//(R0AD15LZ1) Имитация АЗ от 1УР (датчик1)
	{ 78	,1	,1	, &R0AD16LZ1},	//(R0AD16LZ1) Имитация АЗ от 1УР (датчик2)
	{ 79	,3	,1	, &R0MW12IP2},	//(R0MW12IP2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
	{ 80	,1	,1	, &A2IS12LDU},	//(A2IS12LDU) Магнит РБ1 зацеплен
	{ 81	,1	,1	, &B2IS12LDU},	//(B2IS12LDU) Магнит РБ2 зацеплен
	{ 82	,3	,1	, &R0DE04LZ1},	//(R0DE04LZ1) диагностика модуля Баз1 на 4 месте
	{ 83	,3	,1	, &R0DE05LZ1},	//(R0DE05LZ1) диагностика модуля Баз1 на 5 месте
	{ 84	,1	,1	, &B0VP41LZ1},	//(B0VP41LZ1) Давление АЗ2 ниже АС
	{ 85	,1	,1	, &B0VP81LZZ},	//(B0VP81LZZ) Давление АЗ2 в норме
	{ 86	,1	,1	, &A0VP81LZZ},	//(A0VP81LZZ) Давление  АЗ1 в норме
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
	{ 101	,1	,1	, &R0VN61LS2},	//(R0VN61LS2) ПС по мощности канал 2
	{ 102	,1	,1	, &R0VN61LS3},	//(R0VN61LS3) ПС по мощности канал 3
	{ 103	,1	,1	, &R0VN61LS4},	//(R0VN61LS4) ПС по мощности канал 4
	{ 104	,3	,1	, &A0IT01IZ1},	//(A0IT01IZ1) Температура АЗ1-1
	{ 105	,8	,1	, &A0CT01IZ1},	//(A0CT01IZ1) Температура АЗ1-1
	{ 106	,1	,1	, &A0VT61LZ1},	//(A0VT61LZ1) ПС по температуре в АЗ1
	{ 107	,1	,1	, &A0VT71LZ1},	//(A0VT71LZ1) АС по температуре в АЗ1
	{ 108	,1	,1	, &A1VP41LZ1},	//(A1VP41LZ1) Давление СБРОС ББ1 ниже АС
	{ 109	,1	,1	, &B1VP41LZ1},	//(B1VP41LZ1) Давление СБРОС ББ2 ниже АС
	{ 110	,1	,1	, &B1VP81LZZ},	//(B1VP81LZZ) Давление СБРОС ББ2 в норме
	{ 111	,1	,1	, &A1VP81LZZ},	//(A1VP81LZZ) Давление СБРОС ББ1 в норме
	{ 112	,1	,1	, &A2VP41LZ1},	//(A2VP41LZ1) Давление СБРОС РБ1 ниже АС
	{ 113	,8	,1	, &A2CP01RZ1},	//(A2CP01RZ1) Текущее давление СБРОС РБ1
	{ 114	,1	,1	, &A2VP51LZ1},	//(A2VP51LZ1) Давление СБРОС РБ1 ниже ПС
	{ 115	,1	,1	, &B2VP41LZ1},	//(B2VP41LZ1) Давление СБРОС РБ2 ниже АС
	{ 116	,8	,1	, &B2CP01RZ1},	//(B2CP01RZ1) Текущее давление СБРОС РБ2
	{ 117	,1	,1	, &B2VP51LZ1},	//(B2VP51LZ1) Давление СБРОС РБ2 ниже ПС
	{ 118	,1	,1	, &B2VP81LZ1},	//(B2VP81LZ1) Давление СБРОС РБ2 в норме
	{ 119	,1	,1	, &A2VP81LZ1},	//(A2VP81LZ1) Давление СБРОС РБ1 в норме
	{ 120	,3	,1	, &A2IP01IZ1},	//(A2IP01IZ1) Текущее давление СБРОС РБ1
	{ 121	,3	,1	, &B2IP01IZ1},	//(B2IP01IZ1) Текущее давление СБРОС РБ2
	{ 122	,1	,1	, &R0ET01LZ1},	//(R0ET01LZ1) Признак наличия неисправности по температуре  АЗ1
	{ 123	,3	,1	, &B0IT01IZ1},	//(B0IT01IZ1) Температура АЗ2-1
	{ 124	,1	,1	, &A0VP41LZ1},	//(A0VP41LZ1) Давление АЗ1 ниже АС
	{ 125	,1	,1	, &A3IS11LDU},	//(A3IS11LDU) Приход на ВУ ИС1
	{ 126	,1	,1	, &A3IS22LDU},	//(A3IS22LDU) Приход на НУП ИС1
	{ 127	,1	,1	, &R0AD03LZ1},	//(R0AD03LZ1) Имитация прихода на ВУ ИС
	{ 128	,1	,1	, &B3IS11LDU},	//(B3IS11LDU) Приход на ВУ ИС2
	{ 129	,1	,1	, &A3VZ31LZ1},	//(A3VZ31LZ1) АЗ от ВУ ИС1
	{ 130	,1	,1	, &B3VZ31LZ1},	//(B3VZ31LZ1) АЗ от ВУ ИС2
	{ 131	,1	,1	, &R0AD05LZ1},	//(R0AD05LZ1) Имитация ухода с НУП ИС
	{ 132	,1	,1	, &A3VZ11LZ1},	//(A3VZ11LZ1) АЗ от НУП ИС1
	{ 133	,1	,1	, &B3VZ11LZ1},	//(B3VZ11LZ1) АЗ от НУП ИС2
	{ 134	,1	,1	, &B3IS22LDU},	//(B3IS22LDU) Приход на НУП ИС2
	{ 135	,1	,1	, &R0VN69LZ1},	//(R0VN69LZ1) ПС по усредненному периоду
	{ 136	,1	,1	, &R0VN79LZ1},	//(R0VN79LZ1) АС по усредненному периоду
	{ 137	,8	,1	, &R0VR02RZ1},	//(R0VR02RZ1) Усредненная реактивность
	{ 138	,1	,1	, &R0VZ71LZ1},	//(R0VZ71LZ1) Обобщенный сигнал АЗ 1 канала
	{ 139	,1	,1	, &R0VN70LZ1},	//(R0VN70LZ1) АЗ по АС мощности РУ
	{ 140	,1	,1	, &R0VN80LZ1},	//(R0VN80LZ1) АЗ по АС периода разгона РУ
	{ 141	,1	,1	, &A0EE01LS1},	//(A0EE01LS1) Исправность АКНП канал 1
	{ 142	,1	,1	, &A0EE01LS4},	//(A0EE01LS4) Исправность АКНП канал 4
	{ 143	,1	,1	, &A0EE01LS3},	//(A0EE01LS3) Исправность АКНП канал 3
	{ 144	,1	,1	, &A0EE01LZ1},	//(A0EE01LZ1) Исправность АКНП1
	{ 145	,1	,1	, &A0EE04LZ1},	//(A0EE04LZ1) Исправность АКНП4
	{ 146	,1	,1	, &R0VN65LS1},	//(R0VN65LS1) ПС по периоду разгона канал 1
	{ 147	,1	,1	, &R0VN65LS2},	//(R0VN65LS2) ПС по периоду разгона  канал 2
	{ 148	,1	,1	, &R0VN65LS3},	//(R0VN65LS3) ПС по периоду разгона канал 3
	{ 149	,1	,1	, &R0VN65LS4},	//(R0VN65LS4) ПС по периоду разгона канал 4
	{ 150	,8	,1	, &R0VN01RZ1},	//(R0VN01RZ1) Уровень мощности по каналу 1
	{ 151	,8	,1	, &R0VN02RZ1},	//(R0VN02RZ1) Уровень мощности по каналу 2
	{ 152	,8	,1	, &R0VN03RZ1},	//(R0VN03RZ1) Уровень мощности по каналу 3
	{ 153	,8	,1	, &R0VN04RZ1},	//(R0VN04RZ1) Уровень мощности по каналу 4
	{ 154	,8	,1	, &R0VN05RZ1},	//(R0VN05RZ1) Период разгона по каналу 1
	{ 155	,8	,1	, &R0VN06RZ1},	//(R0VN06RZ1) Период разгона по каналу 2
	{ 156	,8	,1	, &R0VN07RZ1},	//(R0VN07RZ1) Период разгона по каналу 3
	{ 157	,8	,1	, &R0VN08RZ1},	//(R0VN08RZ1) Период разгона по каналу 4
	{ 158	,1	,1	, &R0VN61LZ1},	//(R0VN61LZ1) ПС по мощности канал 1
	{ 159	,1	,1	, &R0VN62LZ1},	//(R0VN62LZ1) ПС по мощности канал 2
	{ 160	,1	,1	, &R0VN63LZ1},	//(R0VN63LZ1) ПС по мощности канал 3
	{ 161	,1	,1	, &R0VN64LZ1},	//(R0VN64LZ1) ПС по мощности канал 4
	{ 162	,1	,1	, &R0VN65LZ1},	//(R0VN65LZ1) ПС по периоду разгона канал 1
	{ 163	,1	,1	, &R0VN66LZ1},	//(R0VN66LZ1) ПС по периоду разгона канал 2
	{ 164	,1	,1	, &R0VN67LZ1},	//(R0VN67LZ1) ПС по периоду разгона канал 3
	{ 165	,1	,1	, &R0VN68LZ1},	//(R0VN68LZ1) ПС по периоду разгона канал 4
	{ 166	,8	,1	, &R0VN09RZ1},	//(R0VN09RZ1) Усредненный период разгона
	{ 167	,8	,1	, &fEM_R0UT02RZZ},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{ 168	,8	,1	, &fEM_R0UT01RZZ},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{ 169	,8	,1	, &fEM_A2UP03RZZ},	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
	{ 170	,8	,1	, &fEM_A2UP04RZZ},	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
	{ 171	,8	,1	, &fEM_R0UT72RZZ},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{ 172	,8	,1	, &fEM_R0UT71RZZ},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{ 173	,8	,1	, &fEM_R0UT62RZZ},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{ 174	,8	,1	, &fEM_R0UT61RZZ},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{ 175	,8	,1	, &fEM_A2UP41RZZ},	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
	{ 176	,8	,1	, &fEM_A2UP42RZZ},	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
	{ 177	,8	,1	, &fEM_A2UP51RZZ},	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
	{ 178	,8	,1	, &fEM_A2UP81RZZ},	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{ 179	,8	,1	, &fEM_A2UP84RZZ},	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{ 180	,8	,1	, &fEM_A2UP82RZZ},	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
	{ 181	,8	,1	, &fEM_A2UP52RZZ},	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
	{ 182	,8	,1	, &fEM_A2UP83RZZ},	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
	{ 183	,8	,1	, &fEM_R0UR01RZZ},	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
	{ 184	,8	,1	, &fEM_R0UR04RZZ},	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
	{ 185	,8	,1	, &fEM_A1UL12RZZ},	//(A1UL12RZZ) Время задержки АЗ от НУ ИС(сек)
	{ 186	,8	,1	, &fEM_A1UL11RZZ},	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
	{ 187	,8	,1	, &fEM_R7UI73RZZ},	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
	{ 188	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 189	,8	,1	, &internal1_m244_tx},	//(internal1_m244_tx) tx - время накопленное сек
	{ 190	,18	,1	, &internal1_m244_y0},	//(internal1_m244_y0) y0
	{ 191	,8	,1	, &internal1_m252_tx},	//(internal1_m252_tx) tx - время накопленное сек
	{ 192	,18	,1	, &internal1_m252_y0},	//(internal1_m252_y0) y0
	{ 193	,8	,1	, &internal1_m315_tx},	//(internal1_m315_tx) tx - время накопленное сек
	{ 194	,18	,1	, &internal1_m315_y0},	//(internal1_m315_y0) y0
	{ 195	,8	,1	, &internal1_m211_tx},	//(internal1_m211_tx) tx - время накопленное сек
	{ 196	,18	,1	, &internal1_m211_y0},	//(internal1_m211_y0) y0
	{ 197	,8	,1	, &internal1_m210_tx},	//(internal1_m210_tx) tx - время накопленное сек
	{ 198	,18	,1	, &internal1_m210_y0},	//(internal1_m210_y0) y0
	{ 199	,8	,1	, &internal1_m208_tx},	//(internal1_m208_tx) tx - время накопленное сек
	{ 200	,18	,1	, &internal1_m208_y0},	//(internal1_m208_y0) y0
	{ 201	,8	,1	, &internal1_m206_tx},	//(internal1_m206_tx) tx - время накопленное сек
	{ 202	,18	,1	, &internal1_m206_y0},	//(internal1_m206_y0) y0
	{ 203	,3	,1	, &internal1_m33_tx},	//(internal1_m33_tx) tx - внутренний параметр
	{ 204	,8	,1	, &internal1_m143_y0},	//(internal1_m143_y0) y0
	{ 205	,8	,1	, &internal1_m141_y0},	//(internal1_m141_y0) y0
	{ 206	,8	,1	, &internal1_m93_y0},	//(internal1_m93_y0) y0
	{ 207	,8	,1	, &internal1_m91_y0},	//(internal1_m91_y0) y0
	{ 208	,1	,1	, &internal1_m154_y1},	//(internal1_m154_y1) y1 - внутренний параметр
	{ 209	,1	,1	, &internal1_m165_y1},	//(internal1_m165_y1) y1 - внутренний параметр
	{ 210	,5	,1	, &internal1_m308_q0},	//(internal1_m308_q0) q0 - внутренний параметр
	{ 211	,1	,1	, &internal1_m130_y0},	//(internal1_m130_y0) state
	{ 212	,1	,1	, &internal1_m123_y0},	//(internal1_m123_y0) state
	{ 213	,1	,1	, &internal1_m107_y1},	//(internal1_m107_y1) y1 - внутренний параметр
	{ 214	,1	,1	, &internal1_m116_y1},	//(internal1_m116_y1) y1 - внутренний параметр
	{ 215	,1	,1	, &internal1_m97_y1},	//(internal1_m97_y1) y1 - внутренний параметр
	{ 216	,1	,1	, &internal1_m105_y1},	//(internal1_m105_y1) y1 - внутренний параметр
	{ 217	,1	,1	, &internal1_m152_y1},	//(internal1_m152_y1) y1 - внутренний параметр
	{ 218	,1	,1	, &internal1_m162_y1},	//(internal1_m162_y1) y1 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="baz1.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{167,"fEM_R0UT02RZZ\0"}, 
{168,"fEM_R0UT01RZZ\0"}, 
{169,"fEM_A2UP03RZZ\0"}, 
{170,"fEM_A2UP04RZZ\0"}, 
{171,"fEM_R0UT72RZZ\0"}, 
{172,"fEM_R0UT71RZZ\0"}, 
{173,"fEM_R0UT62RZZ\0"}, 
{174,"fEM_R0UT61RZZ\0"}, 
{175,"fEM_A2UP41RZZ\0"}, 
{176,"fEM_A2UP42RZZ\0"}, 
{177,"fEM_A2UP51RZZ\0"}, 
{178,"fEM_A2UP81RZZ\0"}, 
{179,"fEM_A2UP84RZZ\0"}, 
{180,"fEM_A2UP82RZZ\0"}, 
{181,"fEM_A2UP52RZZ\0"}, 
{182,"fEM_A2UP83RZZ\0"}, 
{183,"fEM_R0UR01RZZ\0"}, 
{184,"fEM_R0UR04RZZ\0"}, 
{185,"fEM_A1UL12RZZ\0"}, 
{186,"fEM_A1UL11RZZ\0"}, 
{187,"fEM_R7UI73RZZ\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_Baz1[]={  // 
	{&R0EE02LDU,1,0},	//(R0EE02LDU) Питание  АКНП  отключить
	{&A0EE08LZ1,1,1},	//(A0EE08LZ1) Исправность сети АКНП4
	{&A0EE07LZ1,1,2},	//(A0EE07LZ1) Исправность сети АКНП3
	{&A0EE06LZ1,1,3},	//(A0EE06LZ1) Исправность сети АКНП2
	{&A0EE05LZ1,1,4},	//(A0EE05LZ1) Исправность сети АКНП1
	{&R0VN70LZ1,1,5},	//(R0VN70LZ1) АЗ по АС мощности РУ
	{&R0VN78LZ1,1,6},	//(R0VN78LZ1) АС по периоду разгона канал  4
	{&R0VN74LZ1,1,7},	//(R0VN74LZ1) АС по мощности канал 4
	{&R0VN77LZ1,1,8},	//(R0VN77LZ1) АС по периоду разгона канал  3
	{&R0VN73LZ1,1,9},	//(R0VN73LZ1) АС по мощности канал 3
	{&R0VN76LZ1,1,10},	//(R0VN76LZ1) АС по периоду разгона канал  2
	{&R0VN72LZ1,1,11},	//(R0VN72LZ1) АС по мощности канал 2
	{&R0VN75LZ1,1,12},	//(R0VN75LZ1) АС по периоду разгона канал 1
	{&R0VN71LZ1,1,13},	//(R0VN71LZ1) АС по мощности канал 1
	{&R0AD16LDU,1,14},	//(R0AD16LDU) Имитация срабатывания верхней АС I УР
	{&R0MD34LP1,1,15},	//(R0MD34LP1) Кнопка (Квитировать)
	{&R0AD14LDU,1,16},	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
	{&R7II72LZ1,1,17},	//(R7II72LZ1) Сработала АС IУР РАД  (датчик 2)
	{&R7II71LZ1,1,18},	//(R7II71LZ1) Сработала АС IУР РАД (датчик 1)
	{&R7II73LZ1,1,19},	//(R7II73LZ1) Сработала АС II УР РАД
	{&R0VW23LDU,1,20},	//(R0VW23LDU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,1,21},	//(R0VW13LDU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{&R0VZ71LZ1,1,22},	//(R0VZ71LZ1) Обобщенный сигнал АЗ 1 канала
	{&R0VN64LZ1,1,23},	//(R0VN64LZ1) ПС по мощности канал 4
	{&R0VN63LZ1,1,24},	//(R0VN63LZ1) ПС по мощности канал 3
	{&R0VN62LZ1,1,25},	//(R0VN62LZ1) ПС по мощности канал 2
	{&R0VN61LZ1,1,26},	//(R0VN61LZ1) ПС по мощности канал 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_Baz1[]={  // 
	{&R0VP73LZ1,1,0},	//(R0VP73LZ1) ПС давления для РУ
	{&B0VN81LZ1,1,1},	//(B0VN81LZ1) АЗ по АС периода разгона АЗ2
	{&A0VN81LZ1,1,2},	//(A0VN81LZ1) АЗ по АС периода разгона АЗ1
	{&B0VN71LZ1,1,3},	//(B0VN71LZ1) АЗ по АС мощности  АЗ2
	{&A0VN71LZ1,1,4},	//(A0VN71LZ1) АЗ по АС мощности  АЗ1
	{&B0VZ71LZ1,1,5},	//(B0VZ71LZ1) Обобщенный сигнал АС по АЗ2
	{&B0EE00LZ1,1,6},	//(B0EE00LZ1) Исправность АКНП АЗ2
	{&A0EE00LZ1,1,7},	//(A0EE00LZ1) Исправность АКНП АЗ1
	{&A0VZ71LZ1,1,8},	//(A0VZ71LZ1) Обобщенный сигнал АС по АЗ1
	{&A0EE03LZ1,1,9},	//(A0EE03LZ1) Исправность АКНП3
	{&A0EE02LZ1,1,10},	//(A0EE02LZ1) Исправность АКНП2
	{&A0EE04LZ1,1,11},	//(A0EE04LZ1) Исправность АКНП4
	{&A0EE01LZ1,1,12},	//(A0EE01LZ1) Исправность АКНП1
	{&R0VN80LZ1,1,13},	//(R0VN80LZ1) АЗ по АС периода разгона РУ
	{&TestDiagnBaz1,1,14},	//(TestDiagnBaz1) Неисправность от диагностики
	{&R0AD16LZ1,1,15},	//(R0AD16LZ1) Имитация АЗ от 1УР (датчик2)
	{&R0AD15LZ1,1,16},	//(R0AD15LZ1) Имитация АЗ от 1УР (датчик1)
	{&B0VT71LZ1,1,17},	//(B0VT71LZ1) АС по температуре в АЗ2
	{&B0VT61LZ1,1,18},	//(B0VT61LZ1) ПС по температуре в АЗ2
	{&B0VP71LZ1,1,19},	//(B0VP71LZ1) АЗ по АС любого давления для АЗ2
	{&A0VP71LZ1,1,20},	//(A0VP71LZ1) АЗ по АС любого давления для АЗ1
	{&R0ET02LZ1,1,21},	//(R0ET02LZ1) Признак наличия неисправности по температуре АЗ2
	{&B0VP41LZ1,1,22},	//(B0VP41LZ1) Давление АЗ2 ниже АС
	{&A0VP41LZ1,1,23},	//(A0VP41LZ1) Давление АЗ1 ниже АС
	{&R0ET01LZ1,1,24},	//(R0ET01LZ1) Признак наличия неисправности по температуре  АЗ1
	{&A2VP81LZ1,1,25},	//(A2VP81LZ1) Давление СБРОС РБ1 в норме
	{&B2VP81LZ1,1,26},	//(B2VP81LZ1) Давление СБРОС РБ2 в норме
	{&B2VP51LZ1,1,27},	//(B2VP51LZ1) Давление СБРОС РБ2 ниже ПС
	{&B2VP41LZ1,1,28},	//(B2VP41LZ1) Давление СБРОС РБ2 ниже АС
	{&A2VP51LZ1,1,29},	//(A2VP51LZ1) Давление СБРОС РБ1 ниже ПС
	{&A2VP41LZ1,1,30},	//(A2VP41LZ1) Давление СБРОС РБ1 ниже АС
	{&B1VP41LZ1,1,31},	//(B1VP41LZ1) Давление СБРОС ББ2 ниже АС
	{&A1VP41LZ1,1,32},	//(A1VP41LZ1) Давление СБРОС ББ1 ниже АС
	{&A0VT71LZ1,1,33},	//(A0VT71LZ1) АС по температуре в АЗ1
	{&A0VT61LZ1,1,34},	//(A0VT61LZ1) ПС по температуре в АЗ1
	{&R0VN79LZ1,1,35},	//(R0VN79LZ1) АС по усредненному периоду
	{&R0VN69LZ1,1,36},	//(R0VN69LZ1) ПС по усредненному периоду
	{&B3VZ11LZ1,1,37},	//(B3VZ11LZ1) АЗ от НУП ИС2
	{&A3VZ11LZ1,1,38},	//(A3VZ11LZ1) АЗ от НУП ИС1
	{&B3VZ31LZ1,1,39},	//(B3VZ31LZ1) АЗ от ВУ ИС2
	{&A3VZ31LZ1,1,40},	//(A3VZ31LZ1) АЗ от ВУ ИС1
	{&R0VN68LZ1,1,41},	//(R0VN68LZ1) ПС по периоду разгона канал 4
	{&R0VN67LZ1,1,42},	//(R0VN67LZ1) ПС по периоду разгона канал 3
	{&R0VN66LZ1,1,43},	//(R0VN66LZ1) ПС по периоду разгона канал 2
	{&R0VN65LZ1,1,44},	//(R0VN65LZ1) ПС по периоду разгона канал 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_Baz1[]={  // 
	{&B0CT01IZ1,8,0},	//(B0CT01IZ1) Температура АЗ2-1
	{&R0VN11RZ1,8,2},	//(R0VN11RZ1) Средняя мощность по БАЗ1
	{&R0VZ05UZ1,5,4},	//(R0VZ05UZ1) Индикатор причины сброса
	{&TTLBaz1,3,6},	//(TTLBaz1) ttl
	{&R0VN02RZ1,8,7},	//(R0VN02RZ1) Уровень мощности по каналу 2
	{&R0VN01RZ1,8,9},	//(R0VN01RZ1) Уровень мощности по каналу 1
	{&A0EP02IZ1,3,11},	//(A0EP02IZ1) Индикатор -Давление  АЗ1 ниже АС
	{&B0EP02IZ1,3,12},	//(B0EP02IZ1) Индикатор -Давление  АЗ2 ниже АС
	{&B2CP01RZ1,8,13},	//(B2CP01RZ1) Текущее давление СБРОС РБ2
	{&A2CP01RZ1,8,15},	//(A2CP01RZ1) Текущее давление СБРОС РБ1
	{&A0CT01IZ1,8,17},	//(A0CT01IZ1) Температура АЗ1-1
	{&R0VR02RZ1,8,19},	//(R0VR02RZ1) Усредненная реактивность
	{&R0VN09RZ1,8,21},	//(R0VN09RZ1) Усредненный период разгона
	{&R0VN08RZ1,8,23},	//(R0VN08RZ1) Период разгона по каналу 4
	{&R0VN07RZ1,8,25},	//(R0VN07RZ1) Период разгона по каналу 3
	{&R0VN06RZ1,8,27},	//(R0VN06RZ1) Период разгона по каналу 2
	{&R0VN05RZ1,8,29},	//(R0VN05RZ1) Период разгона по каналу 1
	{&R0VN04RZ1,8,31},	//(R0VN04RZ1) Уровень мощности по каналу 4
	{&R0VN03RZ1,8,33},	//(R0VN03RZ1) Уровень мощности по каналу 3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_Baz1[]={  // 
	{&R0MW12IP2,3,0},	//(R0MW12IP2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
	{&fEM_R0UT02RZZ,8,1},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{&fEM_R0UT01RZZ,8,3},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{&fEM_A2UP03RZZ,8,5},	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
	{&fEM_A2UP04RZZ,8,7},	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
	{&fEM_R0UT72RZZ,8,9},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{&fEM_R0UT71RZZ,8,11},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{&fEM_R0UT62RZZ,8,13},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{&fEM_R0UT61RZZ,8,15},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{&fEM_A2UP41RZZ,8,17},	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
	{&fEM_A2UP42RZZ,8,19},	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
	{&fEM_A2UP51RZZ,8,21},	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
	{&fEM_A2UP81RZZ,8,23},	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{&fEM_A2UP84RZZ,8,25},	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{&fEM_A2UP82RZZ,8,27},	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
	{&fEM_A2UP52RZZ,8,29},	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
	{&fEM_A2UP83RZZ,8,31},	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
	{&fEM_R0UR01RZZ,8,33},	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
	{&fEM_R0UR04RZZ,8,35},	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
	{&fEM_A1UL12RZZ,8,37},	//(A1UL12RZZ) Время задержки АЗ от НУ ИС(сек)
	{&fEM_A1UL11RZZ,8,39},	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
	{&fEM_R7UI73RZZ,8,41},	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
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
	{&R0EE01LZ1,1,0},	//(R0EE01LZ1) Питание  АКНП1  отключить
	{&R0EE02LZ1,1,1},	//(R0EE02LZ1) Питание  АКНП  отключить
	{&R0EE03LZ1,1,2},	//(R0EE03LZ1) Питание  АКНП3  отключить
	{&R0EE04LZ1,1,3},	//(R0EE04LZ1) Питание  АКНП4  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MBz1S[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz1S[]={  // 
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
static ModbusRegister coil_DiagnBaz1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DiagnBaz1[]={  // 
	{&R0DE3DLZ1,1,0},	//(R0DE3DLZ1) диагностика шкафа Баз1 БП5/24Д место 6
	{&R0DE3CLZ1,1,1},	//(R0DE3CLZ1) диагностика шкафа Баз1 БП5/24Д место 5
	{&R0DEB3LZ1,1,2},	//(R0DEB3LZ1) диагностика шкафа Баз1 БП5 место 6
	{&R0DEB4LZ1,1,3},	//(R0DEB4LZ1) диагностика шкафа Баз1 БП24Д место 6
	{&R0DEB2LZ1,1,4},	//(R0DEB2LZ1) диагностика шкафа Баз1 БП24Д место 5
	{&R0DEB1LZ1,1,5},	//(R0DEB1LZ1) диагностика шкафа Баз1 БП5 место 5
	{&R0DE38LZ1,1,6},	//(R0DE38LZ1) диагностика шкафа Баз1 МП15-3 место 3
	{&R0DE39LZ1,1,7},	//(R0DE39LZ1) диагностика шкафа Баз1 МП24-2 место 4
	{&R0DE35LZ1,1,8},	//(R0DE35LZ1) диагностика шкафа Баз1 температура больше 53
	{&R0DE37LZ1,1,9},	//(R0DE37LZ1) диагностика шкафа Баз1 МП15-3.1 место 2
	{&R0DE36LZ1,1,10},	//(R0DE36LZ1) диагностика шкафа Баз1 МП15-3.1 место 1
	{&R0DE33LZ1,1,11},	//(R0DE33LZ1) диагностика шкафа Баз1 двери
	{&R0DE34LZ1,1,12},	//(R0DE34LZ1) диагностика шкафа Баз1 температура меньше 43
	{&R0DE32LZ1,1,13},	//(R0DE32LZ1) диагностика шкафа Баз1 сеть 2
	{&R0DE31LZ1,1,14},	//(R0DE31LZ1) диагностика шкафа Баз1 сеть 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DiagnBaz1[]={  // 
	{&R0DE0ALZ1,3,0},	//(R0DE0ALZ1) диагностика модуля Баз1 на 10 месте
	{&R0DE07LZ1,3,1},	//(R0DE07LZ1) диагностика модуля Баз1 на 7 месте
	{&R0DE08LZ1,3,2},	//(R0DE08LZ1) диагностика модуля Баз1 на 8 месте
	{&R0DE06LZ1,3,3},	//(R0DE06LZ1) диагностика модуля Баз1 на 6 месте
	{&R0DE05LZ1,3,4},	//(R0DE05LZ1) диагностика модуля Баз1 на 5 месте
	{&R0DE04LZ1,3,5},	//(R0DE04LZ1) диагностика модуля Баз1 на 4 месте
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DiagnBaz1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_Baz1[0],&di_Baz1[0],&ir_Baz1[0],&hr_Baz1[0],NULL,NULL,NULL,0},	 //Общий слэйв
	{0,5003,&coil_SBz1DU[0],&di_SBz1DU[0],&ir_SBz1DU[0],&hr_SBz1DU[0],NULL,NULL,NULL,0},	 //Слэйв для DU
	{1,5004,&coil_MBz1S[0],&di_MBz1S[0],&ir_MBz1S[0],&hr_MBz1S[0],NULL,MBz1S_ip1,MBz1S_ip2,100},	 //Мастер Баз1 в SCM
	{0,5005,&coil_DiagnBaz1[0],&di_DiagnBaz1[0],&ir_DiagnBaz1[0],&hr_DiagnBaz1[0],NULL,NULL,NULL,0},	 //Диагностика корзины Baz1

	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},};
#pragma pop
#include <fp8/drivers/vas84r.h>
static char buf_VAS84[28];	//VAS84
static vas84r_inipar ini_VAS84={0xc6,255,1,8,0xff,0,16,};
#pragma pack(push,1)
static table_drv table_VAS84={0,0,&ini_VAS84,buf_VAS84,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VAS84[]={
	{&R0DE04LZ1,3,26},
	{&A0IT01IZ1,3,0},
	{&B0IT01IZ1,3,6},
	{&B2IP01IZ1,3,9},
	{&A2IP01IZ1,3,3},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS321[66];	//VDS32
static vds32r_inipar ini_VDS321={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS321={0,0,&ini_VDS321,buf_VDS321,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS321[]={
	{&A3IS11LDU,1,8},
	{&A3IS22LDU,1,10},
	{&R0AD03LZ1,1,12},
	{&A0VN71LS1,1,6},
	{&R0AD05LZ1,1,16},
	{&B2IS12LDU,1,20},
	{&A0EE01LS1,1,4},
	{&R0AD04LZ1,1,14},
	{&R0VN75LZ1,1,2},
	{&R0VN71LZ1,1,0},
	{&A2IS12LDU,1,18},
	{&R0DE05LZ1,3,64},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS322[66];	//VDS32
static vds32r_inipar ini_VDS322={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS322={0,0,&ini_VDS322,buf_VDS322,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS322[]={
	{&A0EE01LS2,1,4},
	{&R0VN72LZ1,1,0},
	{&R0VN76LZ1,1,2},
	{&A0VN71LS2,1,6},
	{&B3IS22LDU,1,22},
	{&B3IS11LDU,1,8},
	{&R0DE06LZ1,3,64},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS323[66];	//VDS32
static vds32r_inipar ini_VDS323={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS323={0,0,&ini_VDS323,buf_VDS323,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS323[]={
	{&R0VN74LZ1,1,0},
	{&A0EE01LS4,1,4},
	{&R6IS68LZZ,1,12},
	{&R0DE07LZ1,3,64},
	{&R6IS67LZZ,1,10},
	{&R6IS66LZZ,1,8},
	{&A0VN71LS4,1,6},
	{&R0VN78LZ1,1,2},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS324[66];	//VDS32
static vds32r_inipar ini_VDS324={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS324={0,0,&ini_VDS324,buf_VDS324,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS324[]={
	{&R0DE08LZ1,3,64},
	{&A0VN71LS3,1,6},
	{&B1VP81LZZ,1,24},
	{&A1VP81LZZ,1,18},
	{&R0VN77LZ1,1,2},
	{&R7II73LZ1,1,12},
	{&R7II71LZ1,1,8},
	{&R7II72LZ1,1,10},
	{&R0VN73LZ1,1,0},
	{&A0VP81LZZ,1,16},
	{&B0VP81LZZ,1,22},
	{&A0EE01LS3,1,4},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS16[40];	//FDS16
static fds16r_inipar ini_FDS16={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS16={0,0,&ini_FDS16,buf_FDS16,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS16[]={
	{&R0VZ71LZ1,1,8},
	{&R0AD14LZ1,1,4},
	{&R0DE0ALZ1,3,38},
	{&A1VN71LZ1,1,6},
	{&A3VZ15LZ1,1,2},
	{&A3VZ13LZ1,1,0},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/sbkfp7.h>
static char buf_SBKFP[26];	//SBKFP
static sbk_inipar ini_SBKFP={0xcc,0xff,8,8,};
#pragma pack(push,1)
static table_drv table_SBKFP={0,0,&ini_SBKFP,buf_SBKFP,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_SBKFP[]={
	{&R0DEB3LZ1,1,22},
	{&R0DEB4LZ1,1,24},
	{&R0DEB2LZ1,1,20},
	{&R0DEB1LZ1,1,18},
	{&R0DE38LZ1,1,14},
	{&R0DE33LZ1,1,4},
	{&R0DE34LZ1,1,6},
	{&R0DE32LZ1,1,2},
	{&R0DE31LZ1,1,0},
	{&R0DE36LZ1,1,10},
	{&R0DE39LZ1,1,16},
	{&R0DE35LZ1,1,8},
	{&R0DE37LZ1,1,12},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0xc6,0x04,7,28,def_buf_VAS84,&table_VAS84}, //VAS84
	{0xc2,0x05,15,66,def_buf_VDS321,&table_VDS321}, //VDS32
	{0xc2,0x06,15,66,def_buf_VDS322,&table_VDS322}, //VDS32
	{0xc2,0x07,15,66,def_buf_VDS323,&table_VDS323}, //VDS32
	{0xc2,0x08,15,66,def_buf_VDS324,&table_VDS324}, //VDS32
	{0x96,0x0a,20,40,def_buf_FDS16,&table_FDS16}, //FDS16
	{0xcc,0x20,4,26,def_buf_SBKFP,&table_SBKFP}, //SBKFP
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
	setAsFloat(167,600);
	setAsFloat(168,0);
	setAsFloat(169,1.6);
	setAsFloat(170,0);
	setAsFloat(171,150);
	setAsFloat(172,200);
	setAsFloat(173,90);
	setAsFloat(174,100);
	setAsFloat(175,0.1);
	setAsFloat(176,0.13);
	setAsFloat(177,0.16);
	setAsFloat(178,0.17);
	setAsFloat(179,0.31);
	setAsFloat(180,0.2);
	setAsFloat(181,0.19);
	setAsFloat(182,0.28);
	setAsFloat(183,15);
	setAsFloat(184,10);
	setAsFloat(185,0.180);
	setAsFloat(186,0.020);
	setAsFloat(187,0.045);
}
uspaint8 InternalBuf[99];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssbool lRM_0_ = {0,0}; /* A-Граница участка насыщения А */ 
ssbool lRM_1_ = {1,0}; /* B-Граница участка насыщения В */ 
sslong dRM_0_ = {0,0}; /* lx вход лонг */ 
sschar bRM_0_ = {0,0}; /* cx вход байтовый */ 
ssint iRM_0_ = {0,0}; /* ix вход целый */ 
ssint iRM_3_ = {3,0}; /* N-число входов */ 
ssint iRM_4_ = {4,0}; /* n - размерность массива */ 
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
ssint var7;
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
ssbool var128;
ssbool var129;
ssbool var130;
ssbool var131;
ssbool var132;
ssfloat var133;
ssfloat var134;
ssbool var135;
ssfloat var136;
ssfloat var137;
ssbool var138;
ssbool var139;
ssbool var140;
ssbool var141;
ssbool var142;
ssbool var143;
ssfloat var144;
sslong var145;
sslong var146;
ssbool var147;
ssbool var148;
ssbool var149;
ssbool var150;
ssbool var151;
ssbool var152;
ssbool var153;
ssbool var154;
ssbool var155;
ssfloat var156;
ssbool var157;
ssbool var158;
ssfloat var159;
ssbool var160;
ssbool var161;
sschar var162;
ssbool var163;
sschar var164;
ssbool var165;
ssbool var166;
ssbool var167;
ssbool var168;
ssbool var169;
ssbool var170;
ssbool var171;
ssbool var172;
ssbool var173;
ssbool var174;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m360_x_1[6] = {&var4,&var3,&R0DE36LZ1,&R0DE37LZ1,&R0DE38LZ1,&R0DE39LZ1};
psint  array_m347_x_1[6] = {&R0DE04LZ1,&R0DE05LZ1,&R0DE06LZ1,&R0DE0ALZ1,&R0DE08LZ1,&R0DE07LZ1};
psfloat  array_m188_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psfloat  array_m330_x_1[4] = {&R0VN02RS1,&R0VN02RS2,&R0VN02RS3,&R0VN02RS4};
psbool  array_m330_diag_1[4] = {&var28,&var29,&var30,&var31};
psbool  array_m310_x_1[17] = {&var90,&var56,&var57,&var85,&var40,&var43,&var161,&var55,&var51,&var50,&var86,&var46,&var44,&var163,&var54,&var53,&var52};
psbool  array_m16_x_1[6] = {&var95,&var86,&var44,&var46,&var104,&var163};
psbool  array_m36_x_1[6] = {&var85,&var40,&var43,&var161,&var93,&var104};
psfloat  array_m2_x_1[4] = {&R0VN01RS1,&R0VN01RS2,&R0VN01RS3,&R0VN01RS4};
psbool  array_m2_diag_1[4] = {&var28,&var29,&var30,&var31};
psbool  array_m3_x_1[3] = {&var114,&var143,&var26};
psbool  array_m12_x_1[3] = {&var113,&var27,&var115};

/* Объявление структур */
_S_or3  S_or3_361_1 = {&var6,&var5,&var2,&var1};
_S_orn  S_orn_360_1 = {array_m360_x_1,&iRM_6_,&var2};
_S_or2  S_or2_365_1 = {&R0DEB3LZ1,&R0DEB4LZ1,&var3};
_S_or2  S_or2_358_1 = {&R0DEB1LZ1,&R0DEB2LZ1,&var4};
_S_and2  S_and2_349_1 = {&R0DE31LZ1,&R0DE32LZ1,&var5};
_S_diagndev  S_diagndev_347_1 = {array_m347_x_1,&iRM_6_,&var6,&var7};
_S_ma  S_ma_188_1 = {array_m188_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_and3  S_and3_232_1 = {&var11,&var21,&var20,&var8};
_S_and3  S_and3_229_1 = {&var21,&var11,&var130,&var9};
_S_and3  S_and3_228_1 = {&var20,&var11,&var129,&var10};
_S_noto  S_noto_220_1 = {&R0AD03LZ1,&var11};
_S_and3  S_and3_226_1 = {&var14,&var17,&var16,&var12};
_S_and3  S_and3_222_1 = {&var14,&var16,&var132,&var13};
_S_noto  S_noto_214_1 = {&R0AD05LZ1,&var14};
_S_and3  S_and3_221_1 = {&var14,&var17,&var131,&var15};
_S_and2  S_and2_215_1 = {&var108,&R0VW23LDU,&var16};
_S_and2  S_and2_213_1 = {&var109,&R0VW13LDU,&var17};
_S_and3  S_and3_207_1 = {&var109,&var108,&R0AD05LZ1,&var18};
_S_and3  S_and3_212_1 = {&var107,&var106,&R0AD03LZ1,&var19};
_S_and2  S_and2_216_1 = {&var107,&R0VW13LDU,&var20};
_S_and2  S_and2_217_1 = {&R0VW23LDU,&var106,&var21};
_S_and2  S_and2_251_1 = {&var128,&var38,&var22};
_S_zzfs  S_zzfs_244_1 = {&R0AD14LDU,&fRM_1_0,&var23,&internal1_m244_tx,&internal1_m244_y0};
_S_and2  S_and2_126_1 = {&var166,&var142,&var24};
_S_and2  S_and2_133_1 = {&var165,&var141,&var25};
_S_or2  S_or2_104_1 = {&var172,&var170,&var26};
_S_or2  S_or2_110_1 = {&var167,&var168,&var27};
_S_and2  S_and2_80_1 = {&A0EE05LZ1,&A0EE01LS1,&var28};
_S_and2  S_and2_82_1 = {&A0EE06LZ1,&A0EE01LS2,&var29};
_S_and2  S_and2_84_1 = {&A0EE07LZ1,&A0EE01LS3,&var30};
_S_and2  S_and2_86_1 = {&A0EE08LZ1,&A0EE01LS4,&var31};
_S_and2  S_and2_178_1 = {&var158,&var123,&var32};
_S_and2  S_and2_179_1 = {&var157,&var123,&var33};
_S_or2  S_or2_255_1 = {&var111,&R7II73LZ1,&var34};
_S_or2  S_or2_257_1 = {&R0AD21LDU,&R0AD14LDU,&var35};
_S_and2  S_and2_256_1 = {&var35,&var34,&var36};
_S_or2  S_or2_249_1 = {&R7II71LZ1,&var110,&var37};
_S_or3  S_or3_250_1 = {&var39,&var37,&var36,&var38};
_S_or2  S_or2_243_1 = {&var112,&R7II72LZ1,&var39};
_S_or2  S_or2_230_1 = {&var15,&var12,&var40};
_S_or2  S_or2_199_1 = {&A3IS22LDU,&R0AD05LZ1,&var41};
_S_or2  S_or2_201_1 = {&B3IS22LDU,&R0AD05LZ1,&var42};
_S_or2  S_or2_233_1 = {&var10,&var8,&var43};
_S_or2  S_or2_234_1 = {&var9,&var8,&var44};
_S_or2  S_or2_202_1 = {&var127,&R0AD03LZ1,&var45};
_S_or2  S_or2_231_1 = {&var13,&var12,&var46};
_S_or2  S_or2_204_1 = {&var126,&R0AD03LZ1,&var47};
_S_schl24  S_schl24_332_1 = {&A0VN71LS2,&A0VN71LS1,&A0VN71LS4,&A0VN71LS3,&var48};
_S_and2  S_and2_323_1 = {&var122,&var121,&var49};
_S_and2  S_and2_312_1 = {&var69,&var91,&var50};
_S_and2  S_and2_314_1 = {&var76,&var91,&var51};
_S_and2  S_and2_320_1 = {&var36,&var105,&var52};
_S_and2  S_and2_319_1 = {&var37,&var105,&var53};
_S_and2  S_and2_318_1 = {&var39,&var105,&var54};
_S_and2  S_and2_316_1 = {&var124,&var91,&var55};
_S_and2  S_and2_313_1 = {&var80,&var91,&var56};
_S_and2  S_and2_311_1 = {&var62,&var91,&var57};
_S_and2  S_and2_297_1 = {&var60,&var59,&var58};
_S_or2  S_or2_299_1 = {&R0VN75LZ1,&var155,&var59};
_S_or2  S_or2_300_1 = {&R0VN77LZ1,&var154,&var60};
_S_or2  S_or2_285_1 = {&var58,&var66,&var61};
_S_or2  S_or2_291_1 = {&var63,&var58,&var62};
_S_and2  S_and2_292_1 = {&var150,&var67,&var63};
_S_or2  S_or2_302_1 = {&R0VN78LZ1,&var152,&var64};
_S_or2  S_or2_301_1 = {&R0VN76LZ1,&var153,&var65};
_S_and2  S_and2_298_1 = {&var65,&var64,&var66};
_S_schl24  S_schl24_296_1 = {&var65,&var64,&var60,&var59,&var67};
_S_and2  S_and2_294_1 = {&var91,&var67,&var68};
_S_or2  S_or2_293_1 = {&var66,&var63,&var69};
_S_and2  S_and2_289_1 = {&var69,&var91,&var70};
_S_or2  S_or2_265_1 = {&R0VN72LZ1,&var153,&var71};
_S_and2  S_and2_280_1 = {&var80,&var91,&var72};
_S_and2  S_and2_268_1 = {&var71,&var74,&var73};
_S_or2  S_or2_266_1 = {&R0VN74LZ1,&var152,&var74};
_S_and2  S_and2_281_1 = {&var76,&var91,&var75};
_S_or2  S_or2_278_1 = {&var73,&var79,&var76};
_S_or2  S_or2_284_1 = {&var81,&var73,&var77};
_S_and2  S_and2_272_1 = {&var83,&var91,&var78};
_S_and2  S_and2_277_1 = {&var151,&var83,&var79};
_S_or2  S_or2_276_1 = {&var81,&var79,&var80};
_S_and2  S_and2_267_1 = {&var82,&var84,&var81};
_S_or2  S_or2_264_1 = {&R0VN73LZ1,&var154,&var82};
_S_schl24  S_schl24_270_1 = {&var82,&var84,&var71,&var74,&var83};
_S_or2  S_or2_263_1 = {&R0VN71LZ1,&var155,&var84};
_S_or2  S_or2_151_1 = {&var135,&var173,&var85};
_S_or2  S_or2_153_1 = {&var140,&var138,&var86};
_S_or2  S_or2_336_1 = {&var171,&var169,&var87};
_S_or2  S_or2_35_1 = {&B2IS12LDU,&A2IS12LDU,&var88};
_S_and2  S_and2_288_1 = {&var91,&var62,&var89};
_S_and2  S_and2_317_1 = {&var125,&var91,&var90};
_S_and2  S_and2_21_1 = {&var120,&var116,&var91};
_S_or2  S_or2_25_1 = {&var148,&var147,&var92};
_S_and2  S_and2_31_1 = {&var94,&var91,&var93};
_S_or3  S_or3_30_1 = {&var62,&var80,&var119,&var94};
_S_and2  S_and2_19_1 = {&var91,&var96,&var95};
_S_or3  S_or3_18_1 = {&var76,&var69,&var118,&var96};
_S_and2  S_and2_6_1 = {&var29,&var31,&var97};
_S_or2  S_or2_10_1 = {&var149,&var97,&var98};
_S_or2  S_or2_9_1 = {&var100,&var149,&var99};
_S_and2  S_and2_5_1 = {&var28,&var30,&var100};
_S_and2  S_and2_189_1 = {&R0AD14LDU,&R7II72LZ1,&var101};
_S_and2  S_and2_185_1 = {&R0AD14LDU,&R7II71LZ1,&var102};
_S_and2  S_and2_182_1 = {&R0AD14LDU,&R7II73LZ1,&var103};
_S_zpfs  S_zpfs_252_1 = {&var22,&fEM_R7UI73RZZ,&var104,&internal1_m252_tx,&internal1_m252_y0};
_S_zpfs  S_zpfs_315_1 = {&var49,&fRM_0_2,&var105,&internal1_m315_tx,&internal1_m315_y0};
_S_zpfs  S_zpfs_211_1 = {&var47,&fEM_A1UL11RZZ,&var106,&internal1_m211_tx,&internal1_m211_y0};
_S_zpfs  S_zpfs_210_1 = {&var45,&fEM_A1UL11RZZ,&var107,&internal1_m210_tx,&internal1_m210_y0};
_S_zpfs  S_zpfs_208_1 = {&var42,&fEM_A1UL12RZZ,&var108,&internal1_m208_tx,&internal1_m208_y0};
_S_zpfs  S_zpfs_206_1 = {&var41,&fEM_A1UL12RZZ,&var109,&internal1_m206_tx,&internal1_m206_y0};
_S_noto  S_noto_248_1 = {&R6IS67LZZ,&var110};
_S_noto  S_noto_254_1 = {&R6IS68LZZ,&var111};
_S_noto  S_noto_237_1 = {&R6IS66LZZ,&var112};
_S_noto  S_noto_129_1 = {&B0VP81LZZ,&var113};
_S_noto  S_noto_128_1 = {&A0VP81LZZ,&var114};
_S_noto  S_noto_96_1 = {&B1VP81LZZ,&var115};
_S_noto  S_noto_27_1 = {&var117,&var116};
_S_ovb1  S_ovb1_33_1 = {&var88,&iRM_200_,&var117,&internal1_m33_tx};
_S_noto  S_noto_15_1 = {&var98,&var118};
_S_noto  S_noto_14_1 = {&var99,&var119};
_S_noto  S_noto_24_1 = {&R0EE02LDU,&var120};
_S_noto  S_noto_325_1 = {&R0AD16LDU,&var121};
_S_noto  S_noto_324_1 = {&R0AD04LZ1,&var122};
_S_bol  S_bol_174_1 = {&var159,&fRM_0_00001,&var123};
_S_noto  S_noto_321_1 = {&var98,&var124};
_S_noto  S_noto_322_1 = {&var99,&var125};
_S_noto  S_noto_198_1 = {&B3IS11LDU,&var126};
_S_noto  S_noto_197_1 = {&A3IS11LDU,&var127};
_S_noto  S_noto_245_1 = {&var23,&var128};
_S_noto  S_noto_224_1 = {&R0VW23LDU,&var129};
_S_noto  S_noto_223_1 = {&R0VW13LDU,&var130};
_S_noto  S_noto_219_1 = {&R0VW23LDU,&var131};
_S_noto  S_noto_218_1 = {&R0VW13LDU,&var132};
_S_scalzz  S_scalzz_143_1 = {&B0IT01IZ1,&iRM_819_,&iRM_4095_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var133,&internal1_m143_y0};
_S_scalzz  S_scalzz_141_1 = {&A0IT01IZ1,&iRM_819_,&iRM_4095_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var134,&internal1_m141_y0};
_S_geterr  S_geterr_145_1 = {&var134,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var135};
_S_scalzz  S_scalzz_93_1 = {&B2IP01IZ1,&iRM_819_,&iRM_4095_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var136,&internal1_m93_y0};
_S_scalzz  S_scalzz_91_1 = {&A2IP01IZ1,&iRM_819_,&iRM_4095_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var137,&internal1_m91_y0};
_S_drg  S_drg_154_1 = {&var133,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var138,&internal1_m154_y1};
_S_drg  S_drg_165_1 = {&var133,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var139,&internal1_m165_y1};
_S_geterr  S_geterr_147_1 = {&var133,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var140};
_S_noto  S_noto_134_1 = {&var167,&var141};
_S_noto  S_noto_125_1 = {&var172,&var142};
_S_noto  S_noto_95_1 = {&A1VP81LZZ,&var143};
_S_srm  S_srm_330_1 = {array_m330_x_1,array_m330_diag_1,&iRM_4_,&iRM_3_,&var144,&vainSBool};
_S_rsu  S_rsu_308_1 = {&R0MD34LP1,&var146,&var145,&internal1_m308_q0};
_S_orni  S_orni_310_1 = {array_m310_x_1,&iRM_17_,&vainSBool,&var146};
_S_orn  S_orn_16_1 = {array_m16_x_1,&iRM_6_,&var147};
_S_orn  S_orn_36_1 = {array_m36_x_1,&iRM_6_,&var148};
_S_noto  S_noto_7_1 = {&var160,&var149};
_S_noto  S_noto_287_1 = {&var61,&var150};
_S_noto  S_noto_282_1 = {&var77,&var151};
_S_noto  S_noto_271_1 = {&A0EE01LS4,&var152};
_S_noto  S_noto_275_1 = {&A0EE01LS2,&var153};
_S_noto  S_noto_274_1 = {&A0EE01LS3,&var154};
_S_noto  S_noto_269_1 = {&A0EE01LS1,&var155};
_S_react  S_react_170_1 = {&var159,&var156};
_S_bol  S_bol_175_1 = {&fEM_R0UR04RZZ,&var159,&var157};
_S_bol  S_bol_173_1 = {&fEM_R0UR01RZZ,&var159,&var158};
_S_srm  S_srm_2_1 = {array_m2_x_1,array_m2_diag_1,&iRM_4_,&iRM_3_,&var159,&var160};
_S_ornc  S_ornc_3_1 = {array_m3_x_1,&iRM_3_,&var161,&var162};
_S_ornc  S_ornc_12_1 = {array_m12_x_1,&iRM_3_,&var163,&var164};
_S_tprg  S_tprg_130_1 = {&var136,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var165,&internal1_m130_y0};
_S_tprg  S_tprg_123_1 = {&var137,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var166,&internal1_m123_y0};
_S_geterr  S_geterr_102_1 = {&var136,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var167};
_S_drg  S_drg_107_1 = {&var136,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var168,&internal1_m107_y1};
_S_drg  S_drg_116_1 = {&var136,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var169,&internal1_m116_y1};
_S_drg  S_drg_97_1 = {&var137,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var170,&internal1_m97_y1};
_S_drg  S_drg_105_1 = {&var137,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var171,&internal1_m105_y1};
_S_geterr  S_geterr_99_1 = {&var137,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var172};
_S_drg  S_drg_152_1 = {&var134,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var173,&internal1_m152_y1};
_S_drg  S_drg_162_1 = {&var134,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var174,&internal1_m162_y1};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  noto(&S_noto_269_1);
  noto(&S_noto_274_1);
  noto(&S_noto_275_1);
  noto(&S_noto_271_1);
  noto(&S_noto_95_1);
  scalzz(&S_scalzz_91_1);
  scalzz(&S_scalzz_93_1);
  scalzz(&S_scalzz_141_1);
  scalzz(&S_scalzz_143_1);
  noto(&S_noto_219_1);
  noto(&S_noto_223_1);
  noto(&S_noto_224_1);
  noto(&S_noto_197_1);
  noto(&S_noto_198_1);
  noto(&S_noto_24_1);
  noto(&S_noto_96_1);
  noto(&S_noto_128_1);
  noto(&S_noto_129_1);
  noto(&S_noto_237_1);
  noto(&S_noto_254_1);
  noto(&S_noto_248_1);
  and2(&S_and2_182_1);
  and2(&S_and2_185_1);
  and2(&S_and2_189_1);
  or2(&S_or2_263_1);
  or2(&S_or2_264_1);
  and2(&S_and2_267_1);
  or2(&S_or2_266_1);
  or2(&S_or2_265_1);
  or2(&S_or2_301_1);
  or2(&S_or2_302_1);
  or2(&S_or2_300_1);
  or2(&S_or2_299_1);
  and2(&S_and2_297_1);
  schl24(&S_schl24_332_1);
  or2(&S_or2_204_1);
  or2(&S_or2_202_1);
  or2(&S_or2_201_1);
  or2(&S_or2_199_1);
  or2(&S_or2_243_1);
  or2(&S_or2_249_1);
  or2(&S_or2_257_1);
  or2(&S_or2_255_1);
  and2(&S_and2_86_1);
  and2(&S_and2_84_1);
  and2(&S_and2_82_1);
  and2(&S_and2_80_1);
  zzfs(&S_zzfs_244_1);
  noto(&S_noto_214_1);
  noto(&S_noto_220_1);
  ma(&S_ma_188_1);
  and2(&S_and2_349_1);
  or2(&S_or2_358_1);
  or2(&S_or2_365_1);
  orn(&S_orn_360_1);
  drg(&S_drg_162_1);
  drg(&S_drg_152_1);
  geterr(&S_geterr_99_1);
  drg(&S_drg_105_1);
  drg(&S_drg_97_1);
  drg(&S_drg_116_1);
  drg(&S_drg_107_1);
  geterr(&S_geterr_102_1);
  tprg(&S_tprg_123_1);
  tprg(&S_tprg_130_1);
  srm(&S_srm_2_1);
  bol(&S_bol_173_1);
  bol(&S_bol_175_1);
  react(&S_react_170_1);
  noto(&S_noto_7_1);
  srm(&S_srm_330_1);
  noto(&S_noto_125_1);
  noto(&S_noto_134_1);
  geterr(&S_geterr_147_1);
  drg(&S_drg_165_1);
  drg(&S_drg_154_1);
  geterr(&S_geterr_145_1);
  noto(&S_noto_218_1);
  noto(&S_noto_245_1);
  bol(&S_bol_174_1);
  noto(&S_noto_324_1);
  noto(&S_noto_325_1);
  zpfs(&S_zpfs_206_1);
  zpfs(&S_zpfs_208_1);
  zpfs(&S_zpfs_210_1);
  zpfs(&S_zpfs_211_1);
  and2(&S_and2_5_1);
  or2(&S_or2_9_1);
  and2(&S_and2_6_1);
  or2(&S_or2_35_1);
  or2(&S_or2_336_1);
  or2(&S_or2_153_1);
  or2(&S_or2_151_1);
  schl24(&S_schl24_270_1);
  and2(&S_and2_268_1);
  schl24(&S_schl24_296_1);
  and2(&S_and2_298_1);
  or2(&S_or2_285_1);
  and2(&S_and2_323_1);
  and2(&S_and2_256_1);
  and2(&S_and2_179_1);
  and2(&S_and2_178_1);
  or2(&S_or2_110_1);
  or2(&S_or2_104_1);
  and2(&S_and2_133_1);
  and2(&S_and2_126_1);
  and2(&S_and2_217_1);
  and2(&S_and2_216_1);
  and3(&S_and3_212_1);
  and3(&S_and3_207_1);
  and2(&S_and2_213_1);
  and2(&S_and2_215_1);
  and3(&S_and3_221_1);
  and3(&S_and3_222_1);
  and3(&S_and3_226_1);
  and3(&S_and3_228_1);
  and3(&S_and3_229_1);
  and3(&S_and3_232_1);
  diagndev(&S_diagndev_347_1);
  or3(&S_or3_361_1);
  ornc(&S_ornc_12_1);
  ornc(&S_ornc_3_1);
  noto(&S_noto_287_1);
  noto(&S_noto_322_1);
  noto(&S_noto_14_1);
  ovb1(&S_ovb1_33_1);
  noto(&S_noto_27_1);
  zpfs(&S_zpfs_315_1);
  or2(&S_or2_10_1);
  and2(&S_and2_21_1);
  and2(&S_and2_317_1);
  and2(&S_and2_272_1);
  or2(&S_or2_284_1);
  and2(&S_and2_294_1);
  and2(&S_and2_292_1);
  or2(&S_or2_291_1);
  and2(&S_and2_311_1);
  and2(&S_and2_318_1);
  and2(&S_and2_319_1);
  and2(&S_and2_320_1);
  or2(&S_or2_231_1);
  or2(&S_or2_234_1);
  or2(&S_or2_233_1);
  or2(&S_or2_230_1);
  or3(&S_or3_250_1);
  and2(&S_and2_251_1);
  noto(&S_noto_282_1);
  noto(&S_noto_321_1);
  noto(&S_noto_15_1);
  zpfs(&S_zpfs_252_1);
  and2(&S_and2_288_1);
  and2(&S_and2_277_1);
  or2(&S_or2_278_1);
  and2(&S_and2_281_1);
  or2(&S_or2_293_1);
  and2(&S_and2_316_1);
  and2(&S_and2_314_1);
  and2(&S_and2_312_1);
  or3(&S_or3_18_1);
  and2(&S_and2_19_1);
  or2(&S_or2_276_1);
  and2(&S_and2_280_1);
  and2(&S_and2_289_1);
  and2(&S_and2_313_1);
  orn(&S_orn_16_1);
  orni(&S_orni_310_1);
  rsu(&S_rsu_308_1);
  or3(&S_or3_30_1);
  and2(&S_and2_31_1);
  orn(&S_orn_36_1);
  or2(&S_or2_25_1);
  setData(idTestDiagnBaz1,&var1);
  setData(idR0DE3DLZ1,&var3);
  setData(idR0DE3CLZ1,&var4);
  setData(idTTLBaz1,&var7);
  setData(idR0AD16LZ1,&var101);
  setData(idR0AD15LZ1,&var102);
  moveData(idR0EE04LZ1,idR0EE02LDU);
  moveData(idR0EE03LZ1,idR0EE02LDU);
  moveData(idR0EE02LZ1,idR0EE02LDU);
  moveData(idR0EE01LZ1,idR0EE02LDU);
  setData(idR0AD14LZ1,&var103);
  setData(idA3VZ13LZ1,&var19);
  setData(idA3VZ15LZ1,&var18);
  setData(idA1VN71LZ1,&var48);
  setData(idB0VT71LZ1,&var86);
  setData(idB0VT61LZ1,&var139);
  setData(idB0CT01IZ1,&var133);
  setData(idR0VP73LZ1,&var87);
  setData(idR0VN11RZ1,&var144);
  setData(idR0VZ05UZ1,&var145);
  setData(idB0VN81LZ1,&var70);
  setData(idA0VN81LZ1,&var89);
  setData(idB0VN71LZ1,&var75);
  setData(idA0VN71LZ1,&var72);
  setData(idB0VZ71LZ1,&var147);
  setData(idB0EE00LZ1,&var98);
  setData(idA0EE00LZ1,&var99);
  setData(idA0VZ71LZ1,&var148);
  setData(idA0EE03LZ1,&var30);
  setData(idA0EE02LZ1,&var29);
  setData(idA0EE04LZ1,&var31);
  setData(idA0EE01LZ1,&var28);
  setData(idR0VN80LZ1,&var68);
  setData(idR0VN70LZ1,&var78);
  setData(idR0VZ71LZ1,&var92);
  setData(idR0VR02RZ1,&var156);
  setData(idR0VN79LZ1,&var33);
  setData(idR0VN69LZ1,&var32);
  setData(idB3VZ11LZ1,&var46);
  setData(idA3VZ11LZ1,&var40);
  setData(idB3VZ31LZ1,&var44);
  setData(idA3VZ31LZ1,&var43);
  setData(idR0VN09RZ1,&var159);
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
  setData(idB0VP71LZ1,&var163);
  setData(idA0VP71LZ1,&var161);
  setData(idA0EP02IZ1,&var162);
  setData(idB0EP02IZ1,&var164);
  setData(idR0ET02LZ1,&var140);
  setData(idB0VP41LZ1,&var113);
  setData(idA0VP41LZ1,&var114);
  setData(idR0ET01LZ1,&var135);
  setData(idA2VP81LZ1,&var24);
  setData(idB2VP81LZ1,&var25);
  setData(idB2VP51LZ1,&var169);
  setData(idB2CP01RZ1,&var136);
  setData(idB2VP41LZ1,&var27);
  setData(idA2VP51LZ1,&var171);
  setData(idA2CP01RZ1,&var137);
  setData(idA2VP41LZ1,&var26);
  setData(idB1VP41LZ1,&var115);
  setData(idA1VP41LZ1,&var143);
  setData(idA0VT71LZ1,&var85);
  setData(idA0VT61LZ1,&var174);
  setData(idA0CT01IZ1,&var134);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}

#endif
