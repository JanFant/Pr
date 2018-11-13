#ifndef SCM_H
#define SCM_H
// Подсистема scm:SCM
static char SimulOn=0;
static short CodeSub=1;
static char SimulIP[]="192.168.1.17\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 3605
static char BUFFER[3605];
#define B0VP81LZ2	 BUFFER[0]	//(B0VP81LZ2) Давление  АЗ2  в норме
#define idB0VP81LZ2	 1	//(B0VP81LZ2) Давление  АЗ2  в норме
#define B0VP81LZ1	 BUFFER[2]	//(B0VP81LZ1) Давление  АЗ2  в норме
#define idB0VP81LZ1	 2	//(B0VP81LZ1) Давление  АЗ2  в норме
#define A0VP81LZ2	 BUFFER[4]	//(A0VP81LZ2) Давление  АЗ1  в норме
#define idA0VP81LZ2	 3	//(A0VP81LZ2) Давление  АЗ1  в норме
#define A0VP81LZ1	 BUFFER[6]	//(A0VP81LZ1) Давление  АЗ1  в норме
#define idA0VP81LZ1	 4	//(A0VP81LZ1) Давление  АЗ1  в норме
#define R0VP81LZ2	 BUFFER[8]	//(R0VP81LZ2) Давление  в СИСТЕМЕ-1  в норме
#define idR0VP81LZ2	 5	//(R0VP81LZ2) Давление  в СИСТЕМЕ-1  в норме
#define R0VP81LZ1	 BUFFER[10]	//(R0VP81LZ1) Давление  в СИСТЕМЕ - 1 в норме
#define idR0VP81LZ1	 6	//(R0VP81LZ1) Давление  в СИСТЕМЕ - 1 в норме
#define B8IC01UDU	 BUFFER[12]	//(B8IC01UDU) Координата АЗ2
#define idB8IC01UDU	 7	//(B8IC01UDU) Координата АЗ2
#define A8IC01UDU	 BUFFER[17]	//(A8IC01UDU) Координата ДС2
#define idA8IC01UDU	 8	//(A8IC01UDU) Координата ДС2
#define R6IS68LZ2	 BUFFER[22]	//(R6IS68LZ2) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZ2	 9	//(R6IS68LZ2) Исправность ВИП 4,0 (№7) ССДИ-2
#define R6IS68LZ1	 BUFFER[24]	//(R6IS68LZ1) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZ1	 10	//(R6IS68LZ1) Исправность ВИП 4,0 (№7) ССДИ-2
#define R6IS67LZ2	 BUFFER[26]	//(R6IS67LZ2) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZ2	 11	//(R6IS67LZ2) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS67LZ1	 BUFFER[28]	//(R6IS67LZ1) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZ1	 12	//(R6IS67LZ1) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS66LZ2	 BUFFER[30]	//(R6IS66LZ2) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZ2	 13	//(R6IS66LZ2) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS66LZ1	 BUFFER[32]	//(R6IS66LZ1) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZ1	 14	//(R6IS66LZ1) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS65LDU	 BUFFER[34]	//(R6IS65LDU) Исправность ВИП ССДИ-35 2канал
#define idR6IS65LDU	 15	//(R6IS65LDU) Исправность ВИП ССДИ-35 2канал
#define R6IS64LDU	 BUFFER[36]	//(R6IS64LDU) Исправность ВИП ССДИ-35 1канал
#define idR6IS64LDU	 16	//(R6IS64LDU) Исправность ВИП ССДИ-35 1канал
#define R6IS63LDU	 BUFFER[38]	//(R6IS63LDU) Исправность ВИП ССДИ-39 2канал
#define idR6IS63LDU	 17	//(R6IS63LDU) Исправность ВИП ССДИ-39 2канал
#define R6IS62LDU	 BUFFER[40]	//(R6IS62LDU) Исправность ВИП ССДИ-39 1канал
#define idR6IS62LDU	 18	//(R6IS62LDU) Исправность ВИП ССДИ-39 1канал
#define B3IS22LZ2	 BUFFER[42]	//(B3IS22LZ2) Приход на НУП ИС2
#define idB3IS22LZ2	 19	//(B3IS22LZ2) Приход на НУП ИС2
#define B3IS22LZ1	 BUFFER[44]	//(B3IS22LZ1) Приход на НУП ИС2
#define idB3IS22LZ1	 20	//(B3IS22LZ1) Приход на НУП ИС2
#define R5IS21LDU	 BUFFER[46]	//(R5IS21LDU) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	 21	//(R5IS21LDU) Приход на НУ ворот отстойной зоны
#define R5IS11LDU	 BUFFER[48]	//(R5IS11LDU) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	 22	//(R5IS11LDU) Приход на ВУ ворот отстойной зоны
#define R3IS21LDU	 BUFFER[50]	//(R3IS21LDU) Приход на НУ гомогенных дверей-1
#define idR3IS21LDU	 23	//(R3IS21LDU) Приход на НУ гомогенных дверей-1
#define R3IS11LDU	 BUFFER[52]	//(R3IS11LDU) Приход на ВУ гомогенных дверей-1
#define idR3IS11LDU	 24	//(R3IS11LDU) Приход на ВУ гомогенных дверей-1
#define B2VP82LDU	 BUFFER[54]	//(B2VP82LDU) Давление ПОДЪЁМ РБ2 в норме
#define idB2VP82LDU	 25	//(B2VP82LDU) Давление ПОДЪЁМ РБ2 в норме
#define B2IP01IZ2	 BUFFER[56]	//(B2IP01IZ2) Текущее давление СБРОС РБ2
#define idB2IP01IZ2	 26	//(B2IP01IZ2) Текущее давление СБРОС РБ2
#define B2IP01IZ1	 BUFFER[59]	//(B2IP01IZ1) Текущее давление СБРОС РБ2
#define idB2IP01IZ1	 27	//(B2IP01IZ1) Текущее давление СБРОС РБ2
#define B2IC01UDU	 BUFFER[62]	//(B2IC01UDU) Координата штока РБ2
#define idB2IC01UDU	 28	//(B2IC01UDU) Координата штока РБ2
#define B2IS12LDU	 BUFFER[67]	//(B2IS12LDU) Магнит РБ2 зацеплен
#define idB2IS12LDU	 29	//(B2IS12LDU) Магнит РБ2 зацеплен
#define B2IS11LDU	 BUFFER[69]	//(B2IS11LDU) Приход на ВУ РБ2
#define idB2IS11LDU	 30	//(B2IS11LDU) Приход на ВУ РБ2
#define B2IS21LDU	 BUFFER[71]	//(B2IS21LDU) Приход на НУ РБ2
#define idB2IS21LDU	 31	//(B2IS21LDU) Приход на НУ РБ2
#define B9IS21LDU	 BUFFER[73]	//(B9IS21LDU) Приход на НУ НИ ДС2
#define idB9IS21LDU	 32	//(B9IS21LDU) Приход на НУ НИ ДС2
#define B9IS11LDU	 BUFFER[75]	//(B9IS11LDU) Приход на ВУ НИ ДС2
#define idB9IS11LDU	 33	//(B9IS11LDU) Приход на ВУ НИ ДС2
#define A9IS21LDU	 BUFFER[77]	//(A9IS21LDU) Приход на НУ НИ ДС1
#define idA9IS21LDU	 34	//(A9IS21LDU) Приход на НУ НИ ДС1
#define A9IS11LDU	 BUFFER[79]	//(A9IS11LDU) Приход на ВУ НИ ДС1
#define idA9IS11LDU	 35	//(A9IS11LDU) Приход на ВУ НИ ДС1
#define B5IS21LDU	 BUFFER[81]	//(B5IS21LDU) Приход на НУ НЛ2
#define idB5IS21LDU	 36	//(B5IS21LDU) Приход на НУ НЛ2
#define B5IS11LDU	 BUFFER[83]	//(B5IS11LDU) Приход на ВУ НЛ2
#define idB5IS11LDU	 37	//(B5IS11LDU) Приход на ВУ НЛ2
#define A5IS21LDU	 BUFFER[85]	//(A5IS21LDU) Приход на НУ НЛ1
#define idA5IS21LDU	 38	//(A5IS21LDU) Приход на НУ НЛ1
#define A5IS11LDU	 BUFFER[87]	//(A5IS11LDU) Приход на ВУ НЛ1
#define idA5IS11LDU	 39	//(A5IS11LDU) Приход на ВУ НЛ1
#define R0VP82LZ2	 BUFFER[89]	//(R0VP82LZ2) Давление  в СИСТЕМЕ-2 в норме
#define idR0VP82LZ2	 40	//(R0VP82LZ2) Давление  в СИСТЕМЕ-2 в норме
#define R0VP82LZ1	 BUFFER[91]	//(R0VP82LZ1) Давление  в СИСТЕМЕ-2 в норме
#define idR0VP82LZ1	 41	//(R0VP82LZ1) Давление  в СИСТЕМЕ-2 в норме
#define A2IP01IZ2	 BUFFER[93]	//(A2IP01IZ2) Текущее давление СБРОС РБ1
#define idA2IP01IZ2	 42	//(A2IP01IZ2) Текущее давление СБРОС РБ1
#define A2IP01IZ1	 BUFFER[96]	//(A2IP01IZ1) Текущее давление СБРОС РБ1
#define idA2IP01IZ1	 43	//(A2IP01IZ1) Текущее давление СБРОС РБ1
#define B3IS21LDU	 BUFFER[99]	//(B3IS21LDU) Приход на НУ ИС2
#define idB3IS21LDU	 44	//(B3IS21LDU) Приход на НУ ИС2
#define A3IS21LDU	 BUFFER[101]	//(A3IS21LDU) Приход на НУ ИС1
#define idA3IS21LDU	 45	//(A3IS21LDU) Приход на НУ ИС1
#define A2IS33LDU	 BUFFER[103]	//(A2IS33LDU) Клапан (Подъём РБ1)  открыт (обесточен)
#define idA2IS33LDU	 46	//(A2IS33LDU) Клапан (Подъём РБ1)  открыт (обесточен)
#define A2IC01UDU	 BUFFER[105]	//(A2IC01UDU) Координата штока РБ1
#define idA2IC01UDU	 47	//(A2IC01UDU) Координата штока РБ1
#define A2IS12LDU	 BUFFER[110]	//(A2IS12LDU) Магнит РБ1 зацеплен
#define idA2IS12LDU	 48	//(A2IS12LDU) Магнит РБ1 зацеплен
#define A2IS11LDU	 BUFFER[112]	//(A2IS11LDU) Приход на ВУ РБ1
#define idA2IS11LDU	 49	//(A2IS11LDU) Приход на ВУ РБ1
#define A2IS21LDU	 BUFFER[114]	//(A2IS21LDU) Приход на НУ РБ1
#define idA2IS21LDU	 50	//(A2IS21LDU) Приход на НУ РБ1
#define B0IT02IZ2	 BUFFER[116]	//(B0IT02IZ2) Температура АЗ2-2
#define idB0IT02IZ2	 51	//(B0IT02IZ2) Температура АЗ2-2
#define B0IT01IZ1	 BUFFER[119]	//(B0IT01IZ1) Температура АЗ2-1
#define idB0IT01IZ1	 52	//(B0IT01IZ1) Температура АЗ2-1
#define A0IT02IZ2	 BUFFER[122]	//(A0IT02IZ2) Температура АЗ1-2
#define idA0IT02IZ2	 53	//(A0IT02IZ2) Температура АЗ1-2
#define A0IT01IZ1	 BUFFER[125]	//(A0IT01IZ1) Температура АЗ1-1
#define idA0IT01IZ1	 54	//(A0IT01IZ1) Температура АЗ1-1
#define R6IS21LDU	 BUFFER[128]	//(R6IS21LDU) Кран-балка в нерабочем положении
#define idR6IS21LDU	 55	//(R6IS21LDU) Кран-балка в нерабочем положении
#define B7AS31LDU	 BUFFER[130]	//(B7AS31LDU) Клапан (Обдув АЗ2) открыт (обесточен)
#define idB7AS31LDU	 56	//(B7AS31LDU) Клапан (Обдув АЗ2) открыт (обесточен)
#define A7AS31LDU	 BUFFER[132]	//(A7AS31LDU) Клапан (Обдув АЗ1) открыт (обесточен)
#define idA7AS31LDU	 57	//(A7AS31LDU) Клапан (Обдув АЗ1) открыт (обесточен)
#define R0IE11LS4	 BUFFER[134]	//(R0IE11LS4) Исправность ВИП 1,6 (№17) СНМ11 4канала
#define idR0IE11LS4	 58	//(R0IE11LS4) Исправность ВИП 1,6 (№17) СНМ11 4канала
#define R0IE13LS4	 BUFFER[136]	//(R0IE13LS4) Исправность ВИП 0,5 (№19) КНК53М 4канала
#define idR0IE13LS4	 59	//(R0IE13LS4) Исправность ВИП 0,5 (№19) КНК53М 4канала
#define R0IE12LS4	 BUFFER[138]	//(R0IE12LS4) Исправность ВИП 0,5 (№18) КНК15-1 4канала
#define idR0IE12LS4	 60	//(R0IE12LS4) Исправность ВИП 0,5 (№18) КНК15-1 4канала
#define A1EE01LS4	 BUFFER[140]	//(A1EE01LS4) Исправность АКНП канал 4 на БАЗ2
#define idA1EE01LS4	 61	//(A1EE01LS4) Исправность АКНП канал 4 на БАЗ2
#define B3IS22LDU	 BUFFER[142]	//(B3IS22LDU) Приход на НУП ИС2
#define idB3IS22LDU	 62	//(B3IS22LDU) Приход на НУП ИС2
#define B3IS11LZ2	 BUFFER[144]	//(B3IS11LZ2) Приход на ВУ ИС2
#define idB3IS11LZ2	 63	//(B3IS11LZ2) Приход на ВУ ИС2
#define B3IS11LZ1	 BUFFER[146]	//(B3IS11LZ1) Приход на ВУ ИС2
#define idB3IS11LZ1	 64	//(B3IS11LZ1) Приход на ВУ ИС2
#define A3IS22LZ2	 BUFFER[148]	//(A3IS22LZ2) Приход на НУП ИС1
#define idA3IS22LZ2	 65	//(A3IS22LZ2) Приход на НУП ИС1
#define A3IS22LZ1	 BUFFER[150]	//(A3IS22LZ1) Приход на НУП ИС1
#define idA3IS22LZ1	 66	//(A3IS22LZ1) Приход на НУП ИС1
#define A3IS11LZ2	 BUFFER[152]	//(A3IS11LZ2) Приход на ВУ ИС1
#define idA3IS11LZ2	 67	//(A3IS11LZ2) Приход на ВУ ИС1
#define A3IS11LZ1	 BUFFER[154]	//(A3IS11LZ1) Приход на ВУ ИС1
#define idA3IS11LZ1	 68	//(A3IS11LZ1) Приход на ВУ ИС1
#define A3IS22LDU	 BUFFER[156]	//(A3IS22LDU) Приход на НУП ИС1
#define idA3IS22LDU	 69	//(A3IS22LDU) Приход на НУП ИС1
#define B3IS11LDU	 BUFFER[158]	//(B3IS11LDU) Приход на ВУ ИС2
#define idB3IS11LDU	 70	//(B3IS11LDU) Приход на ВУ ИС2
#define A3IS11LDU	 BUFFER[160]	//(A3IS11LDU) Приход на ВУ ИС1
#define idA3IS11LDU	 71	//(A3IS11LDU) Приход на ВУ ИС1
#define A3IP02IDU	 BUFFER[162]	//(A3IP02IDU) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	 72	//(A3IP02IDU) Текущее давление ВЫСТРЕЛ ИС1
#define B3VP81LDU	 BUFFER[165]	//(B3VP81LDU) Давление СПУСК ИС2 в норме
#define idB3VP81LDU	 73	//(B3VP81LDU) Давление СПУСК ИС2 в норме
#define A3VP81LDU	 BUFFER[167]	//(A3VP81LDU) Давление СПУСК ИС1 в норме
#define idA3VP81LDU	 74	//(A3VP81LDU) Давление СПУСК ИС1 в норме
#define B3IS33LDU	 BUFFER[169]	//(B3IS33LDU) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define idB3IS33LDU	 75	//(B3IS33LDU) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define B3IC01UDU	 BUFFER[171]	//(B3IC01UDU) Координата штока ИС2
#define idB3IC01UDU	 76	//(B3IC01UDU) Координата штока ИС2
#define B3IS31LDU	 BUFFER[176]	//(B3IS31LDU) Клапан (СПУСК ИС2)  открыт (обесточен)
#define idB3IS31LDU	 77	//(B3IS31LDU) Клапан (СПУСК ИС2)  открыт (обесточен)
#define B3IP02IDU	 BUFFER[178]	//(B3IP02IDU) Текущее давление ВЫСТРЕЛ  ИС2
#define idB3IP02IDU	 78	//(B3IP02IDU) Текущее давление ВЫСТРЕЛ  ИС2
#define A3IS33LDU	 BUFFER[181]	//(A3IS33LDU) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
#define idA3IS33LDU	 79	//(A3IS33LDU) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
#define A3IC01UDU	 BUFFER[183]	//(A3IC01UDU) Координата штока ИС1
#define idA3IC01UDU	 80	//(A3IC01UDU) Координата штока ИС1
#define A3IS31LDU	 BUFFER[188]	//(A3IS31LDU) Клапан (СПУСК ИС1)  открыт (обесточен)
#define idA3IS31LDU	 81	//(A3IS31LDU) Клапан (СПУСК ИС1)  открыт (обесточен)
#define A2VP82LDU	 BUFFER[190]	//(A2VP82LDU) Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	 82	//(A2VP82LDU) Давление ПОДЪЁМ РБ1 в норме
#define B2IS11LIM	 BUFFER[192]	//(B2IS11LIM) Магнит РБ2 обесточен
#define idB2IS11LIM	 83	//(B2IS11LIM) Магнит РБ2 обесточен
#define A2IS32LIM	 BUFFER[194]	//(A2IS32LIM) Клапан cброса РБ1 открыт(обесточен)
#define idA2IS32LIM	 84	//(A2IS32LIM) Клапан cброса РБ1 открыт(обесточен)
#define A2IS11LIM	 BUFFER[196]	//(A2IS11LIM) Магнит РБ1 обесточен
#define idA2IS11LIM	 85	//(A2IS11LIM) Магнит РБ1 обесточен
#define B1IS32LIM	 BUFFER[198]	//(B1IS32LIM) Клапан cброса ББ2 открыт(обесточен)
#define idB1IS32LIM	 86	//(B1IS32LIM) Клапан cброса ББ2 открыт(обесточен)
#define B1IS11LIM	 BUFFER[200]	//(B1IS11LIM) Магнит ББ2 обесточен
#define idB1IS11LIM	 87	//(B1IS11LIM) Магнит ББ2 обесточен
#define A1IS32LIM	 BUFFER[202]	//(A1IS32LIM) Клапан cброса ББ1 открыт(обесточен)
#define idA1IS32LIM	 88	//(A1IS32LIM) Клапан cброса ББ1 открыт(обесточен)
#define A1IS11LIM	 BUFFER[204]	//(A1IS11LIM) Магнит ББ1 обесточен
#define idA1IS11LIM	 89	//(A1IS11LIM) Магнит ББ1 обесточен
#define A3AD34LDU	 BUFFER[206]	//(A3AD34LDU) Клапан (ВПИС ИС1) открыть (обесточить)
#define idA3AD34LDU	 90	//(A3AD34LDU) Клапан (ВПИС ИС1) открыть (обесточить)
#define R0IS02LDU	 BUFFER[208]	//(R0IS02LDU) Разрешение ввода от имитатора
#define idR0IS02LDU	 91	//(R0IS02LDU) Разрешение ввода от имитатора
#define R0EE04LZ2	 BUFFER[210]	//(R0EE04LZ2) Питание  АКНП4  отключить
#define idR0EE04LZ2	 92	//(R0EE04LZ2) Питание  АКНП4  отключить
#define R0EE03LZ2	 BUFFER[212]	//(R0EE03LZ2) Питание  АКНП3  отключить
#define idR0EE03LZ2	 93	//(R0EE03LZ2) Питание  АКНП3  отключить
#define R0EE02LZ2	 BUFFER[214]	//(R0EE02LZ2) Питание  АКНП  отключить
#define idR0EE02LZ2	 94	//(R0EE02LZ2) Питание  АКНП  отключить
#define R0EE04LZ1	 BUFFER[216]	//(R0EE04LZ1) Питание  АКНП4  отключить
#define idR0EE04LZ1	 95	//(R0EE04LZ1) Питание  АКНП4  отключить
#define R0EE03LZ1	 BUFFER[218]	//(R0EE03LZ1) Питание  АКНП3  отключить
#define idR0EE03LZ1	 96	//(R0EE03LZ1) Питание  АКНП3  отключить
#define R0EE02LZ1	 BUFFER[220]	//(R0EE02LZ1) Питание  АКНП  отключить
#define idR0EE02LZ1	 97	//(R0EE02LZ1) Питание  АКНП  отключить
#define R0EE01LZ2	 BUFFER[222]	//(R0EE01LZ2) Питание  АКНП1  отключить
#define idR0EE01LZ2	 98	//(R0EE01LZ2) Питание  АКНП1  отключить
#define R0EE01LZ1	 BUFFER[224]	//(R0EE01LZ1) Питание  АКНП1  отключить
#define idR0EE01LZ1	 99	//(R0EE01LZ1) Питание  АКНП1  отключить
#define R5AD20LDU	 BUFFER[226]	//(R5AD20LDU) Закрыть ворота отстойной зоны
#define idR5AD20LDU	 100	//(R5AD20LDU) Закрыть ворота отстойной зоны
#define R3AD21LDU	 BUFFER[228]	//(R3AD21LDU) Гомогенные двери-2 закрыть
#define idR3AD21LDU	 101	//(R3AD21LDU) Гомогенные двери-2 закрыть
#define R3AD11LDU	 BUFFER[230]	//(R3AD11LDU) Гомогенные двери-2 открыть
#define idR3AD11LDU	 102	//(R3AD11LDU) Гомогенные двери-2 открыть
#define B0SN07RIM	 BUFFER[232]	//(B0SN07RIM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
#define idB0SN07RIM	 103	//(B0SN07RIM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
#define B0SN06RIM	 BUFFER[237]	//(B0SN06RIM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
#define idB0SN06RIM	 104	//(B0SN06RIM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
#define B0SN05RIM	 BUFFER[242]	//(B0SN05RIM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
#define idB0SN05RIM	 105	//(B0SN05RIM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
#define B0SN04RIM	 BUFFER[247]	//(B0SN04RIM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
#define idB0SN04RIM	 106	//(B0SN04RIM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
#define B0SN03RIM	 BUFFER[252]	//(B0SN03RIM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
#define idB0SN03RIM	 107	//(B0SN03RIM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
#define B0SN02RIM	 BUFFER[257]	//(B0SN02RIM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
#define idB0SN02RIM	 108	//(B0SN02RIM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
#define B7AP31LDU	 BUFFER[262]	//(B7AP31LDU) Клапан (Обдув АЗ2) открыть (обесточить)
#define idB7AP31LDU	 109	//(B7AP31LDU) Клапан (Обдув АЗ2) открыть (обесточить)
#define A7AP31LDU	 BUFFER[264]	//(A7AP31LDU) Клапан (Обдув АЗ1) открыть (обесточить)
#define idA7AP31LDU	 110	//(A7AP31LDU) Клапан (Обдув АЗ1) открыть (обесточить)
#define A0SN07RIM	 BUFFER[266]	//(A0SN07RIM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
#define idA0SN07RIM	 111	//(A0SN07RIM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
#define A0SN06RIM	 BUFFER[271]	//(A0SN06RIM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
#define idA0SN06RIM	 112	//(A0SN06RIM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
#define A0SN05RIM	 BUFFER[276]	//(A0SN05RIM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
#define idA0SN05RIM	 113	//(A0SN05RIM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
#define A0SN04RIM	 BUFFER[281]	//(A0SN04RIM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
#define idA0SN04RIM	 114	//(A0SN04RIM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
#define A0SN03RIM	 BUFFER[286]	//(A0SN03RIM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
#define idA0SN03RIM	 115	//(A0SN03RIM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
#define A0SN02RIM	 BUFFER[291]	//(A0SN02RIM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
#define idA0SN02RIM	 116	//(A0SN02RIM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
#define A1VP81LZ2	 BUFFER[296]	//(A1VP81LZ2) Давление СБРОС ББ1 в норме
#define idA1VP81LZ2	 117	//(A1VP81LZ2) Давление СБРОС ББ1 в норме
#define A1VP81LZ1	 BUFFER[298]	//(A1VP81LZ1) Давление СБРОС ББ1 в норме
#define idA1VP81LZ1	 118	//(A1VP81LZ1) Давление СБРОС ББ1 в норме
#define B1VP81LZ1	 BUFFER[300]	//(B1VP81LZ1) Давление СБРОС ББ2 в норме
#define idB1VP81LZ1	 119	//(B1VP81LZ1) Давление СБРОС ББ2 в норме
#define B1VP81LZ2	 BUFFER[302]	//(B1VP81LZ2) Давление СБРОС ББ2 в норме
#define idB1VP81LZ2	 120	//(B1VP81LZ2) Давление СБРОС ББ2 в норме
#define B2IS33LDU	 BUFFER[304]	//(B2IS33LDU) Клапан (Подъём РБ2)  открыт (обесточен)
#define idB2IS33LDU	 121	//(B2IS33LDU) Клапан (Подъём РБ2)  открыт (обесточен)
#define A0VN01RIM	 BUFFER[306]	//(A0VN01RIM) Период разгона  AЗ1
#define idA0VN01RIM	 122	//(A0VN01RIM) Период разгона  AЗ1
#define B2IS32LIM	 BUFFER[311]	//(B2IS32LIM) Клапан cброса РБ2 открыт(обесточен)
#define idB2IS32LIM	 123	//(B2IS32LIM) Клапан cброса РБ2 открыт(обесточен)
#define A8IS12LDU	 BUFFER[313]	//(A8IS12LDU) Приход на механический ВУ ДС2
#define idA8IS12LDU	 124	//(A8IS12LDU) Приход на механический ВУ ДС2
#define A8IS22LDU	 BUFFER[315]	//(A8IS22LDU) Приход на механический НУ ДС2
#define idA8IS22LDU	 125	//(A8IS22LDU) Приход на механический НУ ДС2
#define B8IS12LDU	 BUFFER[317]	//(B8IS12LDU) Приход на механический ВУ АЗ2
#define idB8IS12LDU	 126	//(B8IS12LDU) Приход на механический ВУ АЗ2
#define B8IS22LDU	 BUFFER[319]	//(B8IS22LDU) Приход на механический НУ АЗ2
#define idB8IS22LDU	 127	//(B8IS22LDU) Приход на механический НУ АЗ2
#define R4IS12LDU	 BUFFER[321]	//(R4IS12LDU) Приход на механический ВУ тележки
#define idR4IS12LDU	 128	//(R4IS12LDU) Приход на механический ВУ тележки
#define R4IS22LDU	 BUFFER[323]	//(R4IS22LDU) Приход на механический НУ тележки
#define idR4IS22LDU	 129	//(R4IS22LDU) Приход на механический НУ тележки
#define R4IS21LDU	 BUFFER[325]	//(R4IS21LDU) Приход на НУ тележки
#define idR4IS21LDU	 130	//(R4IS21LDU) Приход на НУ тележки
#define R4IS11LDU	 BUFFER[327]	//(R4IS11LDU) Приход на ВУ тележки
#define idR4IS11LDU	 131	//(R4IS11LDU) Приход на ВУ тележки
#define B4VP82LDU	 BUFFER[329]	//(B4VP82LDU) Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	 132	//(B4VP82LDU) Давление ПОДЪЁМ НИ2 в норме
#define A4VP82LDU	 BUFFER[331]	//(A4VP82LDU) Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	 133	//(A4VP82LDU) Давление ПОДЪЁМ НИ1 в норме
#define R3IS41LDU	 BUFFER[333]	//(R3IS41LDU) Приход на НУ гомогенных дверей-2
#define idR3IS41LDU	 134	//(R3IS41LDU) Приход на НУ гомогенных дверей-2
#define R3IS31LDU	 BUFFER[335]	//(R3IS31LDU) Приход на ВУ гомогенных дверей-2
#define idR3IS31LDU	 135	//(R3IS31LDU) Приход на ВУ гомогенных дверей-2
#define R2IS21LDU	 BUFFER[337]	//(R2IS21LDU) Приход на НУ МДЗ2
#define idR2IS21LDU	 136	//(R2IS21LDU) Приход на НУ МДЗ2
#define R2IS11LDU	 BUFFER[339]	//(R2IS11LDU) Приход на ВУ МДЗ2
#define idR2IS11LDU	 137	//(R2IS11LDU) Приход на ВУ МДЗ2
#define R1IS21LDU	 BUFFER[341]	//(R1IS21LDU) Приход на НУ МДЗ1
#define idR1IS21LDU	 138	//(R1IS21LDU) Приход на НУ МДЗ1
#define R1IS11LDU	 BUFFER[343]	//(R1IS11LDU) Приход на ВУ МДЗ1
#define idR1IS11LDU	 139	//(R1IS11LDU) Приход на ВУ МДЗ1
#define B4IS21LDU	 BUFFER[345]	//(B4IS21LDU) Приход на НУ НИ2
#define idB4IS21LDU	 140	//(B4IS21LDU) Приход на НУ НИ2
#define B4IS11LDU	 BUFFER[347]	//(B4IS11LDU) Приход на ВУ НИ2
#define idB4IS11LDU	 141	//(B4IS11LDU) Приход на ВУ НИ2
#define R8IS11LDU	 BUFFER[349]	//(R8IS11LDU) Аварийный НИ установлен
#define idR8IS11LDU	 142	//(R8IS11LDU) Аварийный НИ установлен
#define A4IS21LDU	 BUFFER[351]	//(A4IS21LDU) Приход на НУ НИ1
#define idA4IS21LDU	 143	//(A4IS21LDU) Приход на НУ НИ1
#define A4IS11LDU	 BUFFER[353]	//(A4IS11LDU) Приход на ВУ НИ1
#define idA4IS11LDU	 144	//(A4IS11LDU) Приход на ВУ НИ1
#define R3AD20LDU	 BUFFER[355]	//(R3AD20LDU) Гомогенные двери-1 закрыть
#define idR3AD20LDU	 145	//(R3AD20LDU) Гомогенные двери-1 закрыть
#define R3AD10LDU	 BUFFER[357]	//(R3AD10LDU) Гомогенные двери-1 открыть
#define idR3AD10LDU	 146	//(R3AD10LDU) Гомогенные двери-1 открыть
#define R5AD10LDU	 BUFFER[359]	//(R5AD10LDU) Открыть ворота отстойной зоны
#define idR5AD10LDU	 147	//(R5AD10LDU) Открыть ворота отстойной зоны
#define B4IS10LDU	 BUFFER[361]	//(B4IS10LDU) Клапан (Подъём НИ2) открыт (обесточен)
#define idB4IS10LDU	 148	//(B4IS10LDU) Клапан (Подъём НИ2) открыт (обесточен)
#define A4IS10LDU	 BUFFER[363]	//(A4IS10LDU) Клапан (Подъём НИ1) открыт (обесточен)
#define idA4IS10LDU	 149	//(A4IS10LDU) Клапан (Подъём НИ1) открыт (обесточен)
#define B1IE04LDU	 BUFFER[365]	//(B1IE04LDU) Движение ББ2 назад (от БУШД)
#define idB1IE04LDU	 150	//(B1IE04LDU) Движение ББ2 назад (от БУШД)
#define B1IE03LDU	 BUFFER[367]	//(B1IE03LDU) Движение ББ2 вперед (от БУШД)
#define idB1IE03LDU	 151	//(B1IE03LDU) Движение ББ2 вперед (от БУШД)
#define A1IE04LDU	 BUFFER[369]	//(A1IE04LDU) Движение ББ1 назад (от БУШД)
#define idA1IE04LDU	 152	//(A1IE04LDU) Движение ББ1 назад (от БУШД)
#define A1IE03LDU	 BUFFER[371]	//(A1IE03LDU) Движение ББ1 вперед (от БУШД)
#define idA1IE03LDU	 153	//(A1IE03LDU) Движение ББ1 вперед (от БУШД)
#define B1IS12LDU	 BUFFER[373]	//(B1IS12LDU) Магнит ББ2 зацеплен
#define idB1IS12LDU	 154	//(B1IS12LDU) Магнит ББ2 зацеплен
#define B1IS11LDU	 BUFFER[375]	//(B1IS11LDU) Приход на ВУ ББ2
#define idB1IS11LDU	 155	//(B1IS11LDU) Приход на ВУ ББ2
#define B1IS21LDU	 BUFFER[377]	//(B1IS21LDU) Приход на НУ ББ2
#define idB1IS21LDU	 156	//(B1IS21LDU) Приход на НУ ББ2
#define B1IC01UDU	 BUFFER[379]	//(B1IC01UDU) Координата штока ББ2
#define idB1IC01UDU	 157	//(B1IC01UDU) Координата штока ББ2
#define A1IC01UDU	 BUFFER[384]	//(A1IC01UDU) Координата штока ББ1
#define idA1IC01UDU	 158	//(A1IC01UDU) Координата штока ББ1
#define A1IS12LDU	 BUFFER[389]	//(A1IS12LDU) Магнит ББ1 зацеплен
#define idA1IS12LDU	 159	//(A1IS12LDU) Магнит ББ1 зацеплен
#define A1IS11LDU	 BUFFER[391]	//(A1IS11LDU) Приход на ВУ ББ1
#define idA1IS11LDU	 160	//(A1IS11LDU) Приход на ВУ ББ1
#define A1IS21LDU	 BUFFER[393]	//(A1IS21LDU) Приход на НУ ББ1
#define idA1IS21LDU	 161	//(A1IS21LDU) Приход на НУ ББ1
#define B6IS21LDU	 BUFFER[395]	//(B6IS21LDU) Приход на НУ БЗ2
#define idB6IS21LDU	 162	//(B6IS21LDU) Приход на НУ БЗ2
#define B6IS11LDU	 BUFFER[397]	//(B6IS11LDU) Приход на ВУ БЗ2
#define idB6IS11LDU	 163	//(B6IS11LDU) Приход на ВУ БЗ2
#define A6IS21LDU	 BUFFER[399]	//(A6IS21LDU) Приход на НУ БЗ1
#define idA6IS21LDU	 164	//(A6IS21LDU) Приход на НУ БЗ1
#define A6IS11LDU	 BUFFER[401]	//(A6IS11LDU) Приход на ВУ БЗ1
#define idA6IS11LDU	 165	//(A6IS11LDU) Приход на ВУ БЗ1
#define R2AD10LDU	 BUFFER[403]	//(R2AD10LDU) Опустить МДЗ2 в зону облучения
#define idR2AD10LDU	 166	//(R2AD10LDU) Опустить МДЗ2 в зону облучения
#define R1AD20LDU	 BUFFER[405]	//(R1AD20LDU) Поднять МДЗ1
#define idR1AD20LDU	 167	//(R1AD20LDU) Поднять МДЗ1
#define R1AD10LDU	 BUFFER[407]	//(R1AD10LDU) Опустить МДЗ1 в зону облучения
#define idR1AD10LDU	 168	//(R1AD10LDU) Опустить МДЗ1 в зону облучения
#define B6AD20LDU	 BUFFER[409]	//(B6AD20LDU) Закрыть БЗ2
#define idB6AD20LDU	 169	//(B6AD20LDU) Закрыть БЗ2
#define B6AD10LDU	 BUFFER[411]	//(B6AD10LDU) Открыть БЗ2
#define idB6AD10LDU	 170	//(B6AD10LDU) Открыть БЗ2
#define A6AD20LDU	 BUFFER[413]	//(A6AD20LDU) Закрыть БЗ1
#define idA6AD20LDU	 171	//(A6AD20LDU) Закрыть БЗ1
#define A6AD10LDU	 BUFFER[415]	//(A6AD10LDU) Открыть БЗ1
#define idA6AD10LDU	 172	//(A6AD10LDU) Открыть БЗ1
#define A8AD20LDU	 BUFFER[417]	//(A8AD20LDU) Перемещение ДС2 назад
#define idA8AD20LDU	 173	//(A8AD20LDU) Перемещение ДС2 назад
#define A8AD10LDU	 BUFFER[419]	//(A8AD10LDU) Перемещение ДС2 вперед
#define idA8AD10LDU	 174	//(A8AD10LDU) Перемещение ДС2 вперед
#define B8AD20LDU	 BUFFER[421]	//(B8AD20LDU) Перемещение АЗ2 назад
#define idB8AD20LDU	 175	//(B8AD20LDU) Перемещение АЗ2 назад
#define B8AD10LDU	 BUFFER[423]	//(B8AD10LDU) Перемещение АЗ2 вперед
#define idB8AD10LDU	 176	//(B8AD10LDU) Перемещение АЗ2 вперед
#define R4AD20LDU	 BUFFER[425]	//(R4AD20LDU) Перемещение тележки назад
#define idR4AD20LDU	 177	//(R4AD20LDU) Перемещение тележки назад
#define R4AD10LDU	 BUFFER[427]	//(R4AD10LDU) Перемещение тележки вперед
#define idR4AD10LDU	 178	//(R4AD10LDU) Перемещение тележки вперед
#define B0SR01RIM	 BUFFER[429]	//(B0SR01RIM) Текущая реактивность AЗ2
#define idB0SR01RIM	 179	//(B0SR01RIM) Текущая реактивность AЗ2
#define B3AD33LDU	 BUFFER[434]	//(B3AD33LDU) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define idB3AD33LDU	 180	//(B3AD33LDU) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define B3AD05LDU	 BUFFER[436]	//(B3AD05LDU) паритет команды на ИС2
#define idB3AD05LDU	 181	//(B3AD05LDU) паритет команды на ИС2
#define B3AD04LDU	 BUFFER[438]	//(B3AD04LDU) 2-й бит скорости ИС2
#define idB3AD04LDU	 182	//(B3AD04LDU) 2-й бит скорости ИС2
#define B3AD03LDU	 BUFFER[440]	//(B3AD03LDU) 1-й бит скорости ИС2
#define idB3AD03LDU	 183	//(B3AD03LDU) 1-й бит скорости ИС2
#define B3AD02LDU	 BUFFER[442]	//(B3AD02LDU) 0-й бит скорости ИС2
#define idB3AD02LDU	 184	//(B3AD02LDU) 0-й бит скорости ИС2
#define B3AD01LDU	 BUFFER[444]	//(B3AD01LDU) Разрешение движения ИС2
#define idB3AD01LDU	 185	//(B3AD01LDU) Разрешение движения ИС2
#define C1MD31LP1	 BUFFER[446]	//(C1MD31LP1) Кнопка «СБРОС ББ»  на ОПУ1
#define idC1MD31LP1	 186	//(C1MD31LP1) Кнопка «СБРОС ББ»  на ОПУ1
#define C1MD31LP2	 BUFFER[448]	//(C1MD31LP2) Кнопка «СБРОС ББ»  на ОПУ2
#define idC1MD31LP2	 187	//(C1MD31LP2) Кнопка «СБРОС ББ»  на ОПУ2
#define A1AD31LDU	 BUFFER[450]	//(A1AD31LDU) Клапан (Сброс ББ1) открыть (обесточить)
#define idA1AD31LDU	 188	//(A1AD31LDU) Клапан (Сброс ББ1) открыть (обесточить)
#define A1AD32LDU	 BUFFER[452]	//(A1AD32LDU) Обесточить ЭМ ББ1
#define idA1AD32LDU	 189	//(A1AD32LDU) Обесточить ЭМ ББ1
#define A2AD31LDU	 BUFFER[454]	//(A2AD31LDU) Клапан (Сброс РБ1) открыть (обесточить)
#define idA2AD31LDU	 190	//(A2AD31LDU) Клапан (Сброс РБ1) открыть (обесточить)
#define C2MD31LP1	 BUFFER[456]	//(C2MD31LP1) Кнопка «СБРОС РБ»
#define idC2MD31LP1	 191	//(C2MD31LP1) Кнопка «СБРОС РБ»
#define A2AD32LDU	 BUFFER[458]	//(A2AD32LDU) Обесточить ЭМ РБ1
#define idA2AD32LDU	 192	//(A2AD32LDU) Обесточить ЭМ РБ1
#define R0VZ71LZ2	 BUFFER[460]	//(R0VZ71LZ2) Обобщенный сигнал по АЗ  2 канала
#define idR0VZ71LZ2	 193	//(R0VZ71LZ2) Обобщенный сигнал по АЗ  2 канала
#define R0VZ71LZ1	 BUFFER[462]	//(R0VZ71LZ1) Обобщенный сигнал по АЗ  1 канала
#define idR0VZ71LZ1	 194	//(R0VZ71LZ1) Обобщенный сигнал по АЗ  1 канала
#define R8AD21LDU	 BUFFER[464]	//(R8AD21LDU) Запуск системы инициирования
#define idR8AD21LDU	 195	//(R8AD21LDU) Запуск системы инициирования
#define R0AD14LDU	 BUFFER[466]	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 196	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
#define R0SR02RIM	 BUFFER[468]	//(R0SR02RIM) Текущая мощность РУ (ватт)
#define idR0SR02RIM	 197	//(R0SR02RIM) Текущая мощность РУ (ватт)
#define R0CR02RIM	 BUFFER[473]	//(R0CR02RIM) Коэффициент 11 связи АЗ1,2
#define idR0CR02RIM	 198	//(R0CR02RIM) Коэффициент 11 связи АЗ1,2
#define R0CR01RIM	 BUFFER[478]	//(R0CR01RIM) Коэффициент 12 связи АЗ1,2
#define idR0CR01RIM	 199	//(R0CR01RIM) Коэффициент 12 связи АЗ1,2
#define B0SN08RIM	 BUFFER[483]	//(B0SN08RIM) Поток нейтронов AЗ2(нейтр/с)
#define idB0SN08RIM	 200	//(B0SN08RIM) Поток нейтронов AЗ2(нейтр/с)
#define A0SN08RIM	 BUFFER[488]	//(A0SN08RIM) Поток нейтронов AЗ1(нейтр/с)
#define idA0SN08RIM	 201	//(A0SN08RIM) Поток нейтронов AЗ1(нейтр/с)
#define B5AD20LDU	 BUFFER[493]	//(B5AD20LDU) Опустить НЛ2
#define idB5AD20LDU	 202	//(B5AD20LDU) Опустить НЛ2
#define B5AD10LDU	 BUFFER[495]	//(B5AD10LDU) Поднять НЛ2
#define idB5AD10LDU	 203	//(B5AD10LDU) Поднять НЛ2
#define A5AD20LDU	 BUFFER[497]	//(A5AD20LDU) Опустить НЛ1
#define idA5AD20LDU	 204	//(A5AD20LDU) Опустить НЛ1
#define A5AD10LDU	 BUFFER[499]	//(A5AD10LDU) Поднять НЛ1
#define idA5AD10LDU	 205	//(A5AD10LDU) Поднять НЛ1
#define R2AD20LDU	 BUFFER[501]	//(R2AD20LDU) Поднять МДЗ2
#define idR2AD20LDU	 206	//(R2AD20LDU) Поднять МДЗ2
#define A2AD03LDU	 BUFFER[503]	//(A2AD03LDU) 1-й бит скорости РБ1
#define idA2AD03LDU	 207	//(A2AD03LDU) 1-й бит скорости РБ1
#define A2AD02LDU	 BUFFER[505]	//(A2AD02LDU) 0-й бит скорости РБ1
#define idA2AD02LDU	 208	//(A2AD02LDU) 0-й бит скорости РБ1
#define A2AD01LDU	 BUFFER[507]	//(A2AD01LDU) Разрешение движения РБ1
#define idA2AD01LDU	 209	//(A2AD01LDU) Разрешение движения РБ1
#define A2AD21LDU	 BUFFER[509]	//(A2AD21LDU) Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	 210	//(A2AD21LDU) Сигнал на перемещение РБ1 вниз
#define A2AD11LDU	 BUFFER[511]	//(A2AD11LDU) Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	 211	//(A2AD11LDU) Сигнал на перемещение РБ1 вверх
#define B1AD05LDU	 BUFFER[513]	//(B1AD05LDU) паритет команды на ББ2
#define idB1AD05LDU	 212	//(B1AD05LDU) паритет команды на ББ2
#define B1AD04LDU	 BUFFER[515]	//(B1AD04LDU) 2-й бит скорости ББ2
#define idB1AD04LDU	 213	//(B1AD04LDU) 2-й бит скорости ББ2
#define B1AD03LDU	 BUFFER[517]	//(B1AD03LDU) 1-й бит скорости ББ2
#define idB1AD03LDU	 214	//(B1AD03LDU) 1-й бит скорости ББ2
#define B1AD02LDU	 BUFFER[519]	//(B1AD02LDU) 0-й бит скорости  ББ2
#define idB1AD02LDU	 215	//(B1AD02LDU) 0-й бит скорости  ББ2
#define B1AD01LDU	 BUFFER[521]	//(B1AD01LDU) Разрешение движения ББ2
#define idB1AD01LDU	 216	//(B1AD01LDU) Разрешение движения ББ2
#define B1AD21LDU	 BUFFER[523]	//(B1AD21LDU) Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	 217	//(B1AD21LDU) Сигнал на перемещение ББ2 вниз
#define B1AD11LDU	 BUFFER[525]	//(B1AD11LDU) Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	 218	//(B1AD11LDU) Сигнал на перемещение ББ2 вверх
#define A1AD05LDU	 BUFFER[527]	//(A1AD05LDU) паритет команды на ББ1
#define idA1AD05LDU	 219	//(A1AD05LDU) паритет команды на ББ1
#define A1AD04LDU	 BUFFER[529]	//(A1AD04LDU) 2-й бит скорости ББ1
#define idA1AD04LDU	 220	//(A1AD04LDU) 2-й бит скорости ББ1
#define A1AD03LDU	 BUFFER[531]	//(A1AD03LDU) 1-й бит скорости ББ1
#define idA1AD03LDU	 221	//(A1AD03LDU) 1-й бит скорости ББ1
#define A1AD02LDU	 BUFFER[533]	//(A1AD02LDU) 0-й бит скорости ББ1
#define idA1AD02LDU	 222	//(A1AD02LDU) 0-й бит скорости ББ1
#define A1AD01LDU	 BUFFER[535]	//(A1AD01LDU) Разрешение движения ББ1
#define idA1AD01LDU	 223	//(A1AD01LDU) Разрешение движения ББ1
#define A1AD21LDU	 BUFFER[537]	//(A1AD21LDU) Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	 224	//(A1AD21LDU) Сигнал на перемещение ББ1 вниз
#define A1AD11LDU	 BUFFER[539]	//(A1AD11LDU) Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	 225	//(A1AD11LDU) Сигнал на перемещение ББ1 вверх
#define A0SR01RIM	 BUFFER[541]	//(A0SR01RIM) Текущая реактивность AЗ1
#define idA0SR01RIM	 226	//(A0SR01RIM) Текущая реактивность AЗ1
#define B3AD21LDU	 BUFFER[546]	//(B3AD21LDU) Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	 227	//(B3AD21LDU) Сигнал на перемещение ИС2 вниз
#define B3AD11LDU	 BUFFER[548]	//(B3AD11LDU) Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	 228	//(B3AD11LDU) Сигнал на перемещение ИС2 вверх
#define A3AD33LDU	 BUFFER[550]	//(A3AD33LDU) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
#define idA3AD33LDU	 229	//(A3AD33LDU) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
#define A3AD05LDU	 BUFFER[552]	//(A3AD05LDU) паритет команды на ИС1
#define idA3AD05LDU	 230	//(A3AD05LDU) паритет команды на ИС1
#define A3AD04LDU	 BUFFER[554]	//(A3AD04LDU) 2-й бит скорости ИС1
#define idA3AD04LDU	 231	//(A3AD04LDU) 2-й бит скорости ИС1
#define A3AD03LDU	 BUFFER[556]	//(A3AD03LDU) 1-й бит скорости ИС1
#define idA3AD03LDU	 232	//(A3AD03LDU) 1-й бит скорости ИС1
#define A3AD02LDU	 BUFFER[558]	//(A3AD02LDU) 0-й бит скорости ИС1
#define idA3AD02LDU	 233	//(A3AD02LDU) 0-й бит скорости ИС1
#define A3AD01LDU	 BUFFER[560]	//(A3AD01LDU) Разрешение движения ИС1
#define idA3AD01LDU	 234	//(A3AD01LDU) Разрешение движения ИС1
#define A3AD21LDU	 BUFFER[562]	//(A3AD21LDU) Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	 235	//(A3AD21LDU) Сигнал на перемещение ИС1 вниз
#define A3AD11LDU	 BUFFER[564]	//(A3AD11LDU) Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	 236	//(A3AD11LDU) Сигнал на перемещение ИС1 вверх
#define B2AD33LDU	 BUFFER[566]	//(B2AD33LDU) Клапан (Подъем РБ2) закрыть (обесточить)
#define idB2AD33LDU	 237	//(B2AD33LDU) Клапан (Подъем РБ2) закрыть (обесточить)
#define B2AD05LDU	 BUFFER[568]	//(B2AD05LDU) паритет команды на РБ2
#define idB2AD05LDU	 238	//(B2AD05LDU) паритет команды на РБ2
#define B2AD04LDU	 BUFFER[570]	//(B2AD04LDU) 2-й бит скорости РБ2
#define idB2AD04LDU	 239	//(B2AD04LDU) 2-й бит скорости РБ2
#define B2AD03LDU	 BUFFER[572]	//(B2AD03LDU) 1-й бит скорости РБ2
#define idB2AD03LDU	 240	//(B2AD03LDU) 1-й бит скорости РБ2
#define B2AD02LDU	 BUFFER[574]	//(B2AD02LDU) 0-й бит скорости РБ2
#define idB2AD02LDU	 241	//(B2AD02LDU) 0-й бит скорости РБ2
#define B2AD01LDU	 BUFFER[576]	//(B2AD01LDU) Разрешение движения РБ2
#define idB2AD01LDU	 242	//(B2AD01LDU) Разрешение движения РБ2
#define B2AD21LDU	 BUFFER[578]	//(B2AD21LDU) Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	 243	//(B2AD21LDU) Сигнал на перемещение РБ2 вниз
#define B2AD11LDU	 BUFFER[580]	//(B2AD11LDU) Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	 244	//(B2AD11LDU) Сигнал на перемещение РБ2 вверх
#define A2AD33LDU	 BUFFER[582]	//(A2AD33LDU) Клапан (Подъем РБ1) закрыть (обесточить)
#define idA2AD33LDU	 245	//(A2AD33LDU) Клапан (Подъем РБ1) закрыть (обесточить)
#define A2AD05LDU	 BUFFER[584]	//(A2AD05LDU) паритет команды на РБ1
#define idA2AD05LDU	 246	//(A2AD05LDU) паритет команды на РБ1
#define A2AD04LDU	 BUFFER[586]	//(A2AD04LDU) 2-й бит скорости РБ1
#define idA2AD04LDU	 247	//(A2AD04LDU) 2-й бит скорости РБ1
#define R0VN73LZ2	 BUFFER[588]	//(R0VN73LZ2) АС по мощности канал 3 на БАЗ2
#define idR0VN73LZ2	 248	//(R0VN73LZ2) АС по мощности канал 3 на БАЗ2
#define A0VN71LS3	 BUFFER[590]	//(A0VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ1
#define idA0VN71LS3	 249	//(A0VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ1
#define R0VN15RS3	 BUFFER[592]	//(R0VN15RS3) Номер ведущей камеры канал 3
#define idR0VN15RS3	 250	//(R0VN15RS3) Номер ведущей камеры канал 3
#define A1VN71LS3	 BUFFER[595]	//(A1VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ2
#define idA1VN71LS3	 251	//(A1VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ2
#define R0VN73LZ1	 BUFFER[597]	//(R0VN73LZ1) АС по мощности канал 3 на БАЗ1
#define idR0VN73LZ1	 252	//(R0VN73LZ1) АС по мощности канал 3 на БАЗ1
#define R0VN61LS3	 BUFFER[599]	//(R0VN61LS3) ПС по мощности канал 3
#define idR0VN61LS3	 253	//(R0VN61LS3) ПС по мощности канал 3
#define R0VN02RS3	 BUFFER[601]	//(R0VN02RS3) Уровень мощности канал 3
#define idR0VN02RS3	 254	//(R0VN02RS3) Уровень мощности канал 3
#define R0IE11LS2	 BUFFER[606]	//(R0IE11LS2) Исправность ВИП 1,6 (№11) СНМ11 2канала
#define idR0IE11LS2	 255	//(R0IE11LS2) Исправность ВИП 1,6 (№11) СНМ11 2канала
#define R0IE13LS2	 BUFFER[608]	//(R0IE13LS2) Исправность ВИП 0,5 (№13) КНК53М 2канала
#define idR0IE13LS2	 256	//(R0IE13LS2) Исправность ВИП 0,5 (№13) КНК53М 2канала
#define R0IE12LS2	 BUFFER[610]	//(R0IE12LS2) Исправность ВИП 0,5 (№12) КНК15-1 2канала
#define idR0IE12LS2	 257	//(R0IE12LS2) Исправность ВИП 0,5 (№12) КНК15-1 2канала
#define A1EE01LS2	 BUFFER[612]	//(A1EE01LS2) Исправность АКНП канал 2 на БАЗ2
#define idA1EE01LS2	 258	//(A1EE01LS2) Исправность АКНП канал 2 на БАЗ2
#define R0VN76LZ2	 BUFFER[614]	//(R0VN76LZ2) АС по периоду разгона канал 2  на БАЗ2
#define idR0VN76LZ2	 259	//(R0VN76LZ2) АС по периоду разгона канал 2  на БАЗ2
#define A0EE01LS2	 BUFFER[616]	//(A0EE01LS2) Исправность АКНП канал 2 на БАЗ1
#define idA0EE01LS2	 260	//(A0EE01LS2) Исправность АКНП канал 2 на БАЗ1
#define R0VN76LZ1	 BUFFER[618]	//(R0VN76LZ1) АС по периоду разгона канал 2  на БАЗ1
#define idR0VN76LZ1	 261	//(R0VN76LZ1) АС по периоду разгона канал 2  на БАЗ1
#define R0VN65LS2	 BUFFER[620]	//(R0VN65LS2) ПС по периоду разгона канал 2
#define idR0VN65LS2	 262	//(R0VN65LS2) ПС по периоду разгона канал 2
#define R0VN01RS2	 BUFFER[622]	//(R0VN01RS2) Период разгона канал 2
#define idR0VN01RS2	 263	//(R0VN01RS2) Период разгона канал 2
#define A0VN71LS2	 BUFFER[627]	//(A0VN71LS2) Блокировка автоматического подъёма ББ канал 2 на БАЗ1
#define idA0VN71LS2	 264	//(A0VN71LS2) Блокировка автоматического подъёма ББ канал 2 на БАЗ1
#define R0VN72LZ2	 BUFFER[629]	//(R0VN72LZ2) АС по мощности канал 2 на БАЗ2
#define idR0VN72LZ2	 265	//(R0VN72LZ2) АС по мощности канал 2 на БАЗ2
#define R0VN15RS2	 BUFFER[631]	//(R0VN15RS2) Номер ведущей камеры канал 2
#define idR0VN15RS2	 266	//(R0VN15RS2) Номер ведущей камеры канал 2
#define A1VN71LS2	 BUFFER[634]	//(A1VN71LS2) Блокировка автоматического подъёма ББ канал 2 на БАЗ2
#define idA1VN71LS2	 267	//(A1VN71LS2) Блокировка автоматического подъёма ББ канал 2 на БАЗ2
#define R0VN78LZ2	 BUFFER[636]	//(R0VN78LZ2) АС по периоду разгона канал 4 на БАЗ2
#define idR0VN78LZ2	 268	//(R0VN78LZ2) АС по периоду разгона канал 4 на БАЗ2
#define A0EE01LS4	 BUFFER[638]	//(A0EE01LS4) Исправность АКНП канал 4 на БАЗ1
#define idA0EE01LS4	 269	//(A0EE01LS4) Исправность АКНП канал 4 на БАЗ1
#define R0VN78LZ1	 BUFFER[640]	//(R0VN78LZ1) АС по периоду разгона канал 4 на БАЗ1
#define idR0VN78LZ1	 270	//(R0VN78LZ1) АС по периоду разгона канал 4 на БАЗ1
#define R0VN65LS4	 BUFFER[642]	//(R0VN65LS4) ПС по периоду разгона канал 4
#define idR0VN65LS4	 271	//(R0VN65LS4) ПС по периоду разгона канал 4
#define R0VN01RS4	 BUFFER[644]	//(R0VN01RS4) Период разгона канал 4
#define idR0VN01RS4	 272	//(R0VN01RS4) Период разгона канал 4
#define R0VN74LZ2	 BUFFER[649]	//(R0VN74LZ2) АС по мощности канал 4 на БАЗ2
#define idR0VN74LZ2	 273	//(R0VN74LZ2) АС по мощности канал 4 на БАЗ2
#define A0VN71LS4	 BUFFER[651]	//(A0VN71LS4) Блокировка автоматического  подъёма ББ канал 4 на БАЗ1
#define idA0VN71LS4	 274	//(A0VN71LS4) Блокировка автоматического  подъёма ББ канал 4 на БАЗ1
#define R0VN15RS4	 BUFFER[653]	//(R0VN15RS4) Номер ведущей камеры канал 4
#define idR0VN15RS4	 275	//(R0VN15RS4) Номер ведущей камеры канал 4
#define A1VN71LS4	 BUFFER[656]	//(A1VN71LS4) Блокировка автоматического  подъёма ББ канал 4 на БАЗ2
#define idA1VN71LS4	 276	//(A1VN71LS4) Блокировка автоматического  подъёма ББ канал 4 на БАЗ2
#define R0VN74LZ1	 BUFFER[658]	//(R0VN74LZ1) АС по мощности канал 4 на БАЗ1
#define idR0VN74LZ1	 277	//(R0VN74LZ1) АС по мощности канал 4 на БАЗ1
#define R0VN61LS4	 BUFFER[660]	//(R0VN61LS4) ПС по мощности канал 4
#define idR0VN61LS4	 278	//(R0VN61LS4) ПС по мощности канал 4
#define R0VN02RS4	 BUFFER[662]	//(R0VN02RS4) Уровень мощности канал 4
#define idR0VN02RS4	 279	//(R0VN02RS4) Уровень мощности канал 4
#define R0IE11LS3	 BUFFER[667]	//(R0IE11LS3) Исправность ВИП 1,6 (№14) СНМ11 3канала
#define idR0IE11LS3	 280	//(R0IE11LS3) Исправность ВИП 1,6 (№14) СНМ11 3канала
#define R0IE13LS3	 BUFFER[669]	//(R0IE13LS3) Исправность ВИП 0,5 (№16) КНК53М 3канала
#define idR0IE13LS3	 281	//(R0IE13LS3) Исправность ВИП 0,5 (№16) КНК53М 3канала
#define R0IE12LS3	 BUFFER[671]	//(R0IE12LS3) Исправность ВИП 0,5 (№15) КНК15-1 3канала
#define idR0IE12LS3	 282	//(R0IE12LS3) Исправность ВИП 0,5 (№15) КНК15-1 3канала
#define A1EE01LS3	 BUFFER[673]	//(A1EE01LS3) Исправность АКНП канал 3 на БАЗ2
#define idA1EE01LS3	 283	//(A1EE01LS3) Исправность АКНП канал 3 на БАЗ2
#define R0VN77LZ2	 BUFFER[675]	//(R0VN77LZ2) АС по периоду разгона канал 3 на БАЗ2
#define idR0VN77LZ2	 284	//(R0VN77LZ2) АС по периоду разгона канал 3 на БАЗ2
#define A0EE01LS3	 BUFFER[677]	//(A0EE01LS3) Исправность АКНП канал 3 на БАЗ1
#define idA0EE01LS3	 285	//(A0EE01LS3) Исправность АКНП канал 3 на БАЗ1
#define R0VN77LZ1	 BUFFER[679]	//(R0VN77LZ1) АС по периоду разгона канал 3 на БАЗ1
#define idR0VN77LZ1	 286	//(R0VN77LZ1) АС по периоду разгона канал 3 на БАЗ1
#define R0VN65LS3	 BUFFER[681]	//(R0VN65LS3) ПС по периоду разгона канал 3
#define idR0VN65LS3	 287	//(R0VN65LS3) ПС по периоду разгона канал 3
#define R0VN01RS3	 BUFFER[683]	//(R0VN01RS3) Период разгона канал 3
#define idR0VN01RS3	 288	//(R0VN01RS3) Период разгона канал 3
#define A3IS35LDU	 BUFFER[688]	//(A3IS35LDU) Клапан (ВПИС1) открыт(обесточен)
#define idA3IS35LDU	 289	//(A3IS35LDU) Клапан (ВПИС1) открыт(обесточен)
#define R7II73LZ2	 BUFFER[690]	//(R7II73LZ2) Сработала АС IIУР
#define idR7II73LZ2	 290	//(R7II73LZ2) Сработала АС IIУР
#define R7II71LZ2	 BUFFER[692]	//(R7II71LZ2) Сработала АС IУР (датчик 1)
#define idR7II71LZ2	 291	//(R7II71LZ2) Сработала АС IУР (датчик 1)
#define R7II72LZ2	 BUFFER[694]	//(R7II72LZ2) Сработала АС IУР (датчик 2)
#define idR7II72LZ2	 292	//(R7II72LZ2) Сработала АС IУР (датчик 2)
#define R0AD16LDU	 BUFFER[696]	//(R0AD16LDU) Контроль  I-II УР. РАД
#define idR0AD16LDU	 293	//(R0AD16LDU) Контроль  I-II УР. РАД
#define R7II72LZ1	 BUFFER[698]	//(R7II72LZ1) Сработала АС IУР (датчик 2)
#define idR7II72LZ1	 294	//(R7II72LZ1) Сработала АС IУР (датчик 2)
#define R7II71LZ1	 BUFFER[700]	//(R7II71LZ1) Сработала АС IУР (датчик 1)
#define idR7II71LZ1	 295	//(R7II71LZ1) Сработала АС IУР (датчик 1)
#define R7II73LZ1	 BUFFER[702]	//(R7II73LZ1) Сработала АС IIУР
#define idR7II73LZ1	 296	//(R7II73LZ1) Сработала АС IIУР
#define R0SR01RIM	 BUFFER[704]	//(R0SR01RIM) Текущая реактивность PУ
#define idR0SR01RIM	 297	//(R0SR01RIM) Текущая реактивность PУ
#define R0ST01RIM	 BUFFER[709]	//(R0ST01RIM) Текущий период разгона РУ
#define idR0ST01RIM	 298	//(R0ST01RIM) Текущий период разгона РУ
#define A4AD10LDU	 BUFFER[714]	//(A4AD10LDU) Открыть клапан (Подъем НИ1)
#define idA4AD10LDU	 299	//(A4AD10LDU) Открыть клапан (Подъем НИ1)
#define B4AD10LDU	 BUFFER[716]	//(B4AD10LDU) Открыть клапан (Подъем НИ2)
#define idB4AD10LDU	 300	//(B4AD10LDU) Открыть клапан (Подъем НИ2)
#define A9AD10LDU	 BUFFER[718]	//(A9AD10LDU) Открыть клапан (Подъем НИ ДС1)
#define idA9AD10LDU	 301	//(A9AD10LDU) Открыть клапан (Подъем НИ ДС1)
#define B9AD10LDU	 BUFFER[720]	//(B9AD10LDU) Открыть клапан (Подъем НИ ДС2)
#define idB9AD10LDU	 302	//(B9AD10LDU) Открыть клапан (Подъем НИ ДС2)
#define R0MW13LP2	 BUFFER[722]	//(R0MW13LP2) Переключатель «СЕТЬ»
#define idR0MW13LP2	 303	//(R0MW13LP2) Переключатель «СЕТЬ»
#define B3AD31LDU	 BUFFER[724]	//(B3AD31LDU) Клапан (СПУСК ИС2) открыть (обесточить)
#define idB3AD31LDU	 304	//(B3AD31LDU) Клапан (СПУСК ИС2) открыть (обесточить)
#define B2AD32LDU	 BUFFER[726]	//(B2AD32LDU) Обесточить ЭМ РБ2
#define idB2AD32LDU	 305	//(B2AD32LDU) Обесточить ЭМ РБ2
#define B2AD31LDU	 BUFFER[728]	//(B2AD31LDU) Клапан (Сброс РБ2) открыть (обесточить)
#define idB2AD31LDU	 306	//(B2AD31LDU) Клапан (Сброс РБ2) открыть (обесточить)
#define B1AD32LDU	 BUFFER[730]	//(B1AD32LDU) Обесточить ЭМ ББ2
#define idB1AD32LDU	 307	//(B1AD32LDU) Обесточить ЭМ ББ2
#define B1AD31LDU	 BUFFER[732]	//(B1AD31LDU) Клапан (Сброс ББ2) открыть (обесточить)
#define idB1AD31LDU	 308	//(B1AD31LDU) Клапан (Сброс ББ2) открыть (обесточить)
#define A3AD31LDU	 BUFFER[734]	//(A3AD31LDU) Клапан (СПУСК ИС1) открыть (обесточить)
#define idA3AD31LDU	 309	//(A3AD31LDU) Клапан (СПУСК ИС1) открыть (обесточить)
#define R0VN72LZ1	 BUFFER[736]	//(R0VN72LZ1) АС по мощности канал 2 на БАЗ1
#define idR0VN72LZ1	 310	//(R0VN72LZ1) АС по мощности канал 2 на БАЗ1
#define R0VN61LS2	 BUFFER[738]	//(R0VN61LS2) ПС по мощности канал 2
#define idR0VN61LS2	 311	//(R0VN61LS2) ПС по мощности канал 2
#define R0VN02RS2	 BUFFER[740]	//(R0VN02RS2) Уровень мощности канал 2
#define idR0VN02RS2	 312	//(R0VN02RS2) Уровень мощности канал 2
#define R0IE13LS1	 BUFFER[745]	//(R0IE13LS1) Исправность ВИП 0,5 (№10) КНК53М 1канала
#define idR0IE13LS1	 313	//(R0IE13LS1) Исправность ВИП 0,5 (№10) КНК53М 1канала
#define R0IE12LS1	 BUFFER[747]	//(R0IE12LS1) Исправность ВИП 0,5 (№9) КНК15-1 1канала
#define idR0IE12LS1	 314	//(R0IE12LS1) Исправность ВИП 0,5 (№9) КНК15-1 1канала
#define R0IE11LS1	 BUFFER[749]	//(R0IE11LS1) Исправность ВИП 1,6 (№8) СНМ11 1канала
#define idR0IE11LS1	 315	//(R0IE11LS1) Исправность ВИП 1,6 (№8) СНМ11 1канала
#define A1EE01LS1	 BUFFER[751]	//(A1EE01LS1) Исправность АКНП на БАЗ2
#define idA1EE01LS1	 316	//(A1EE01LS1) Исправность АКНП на БАЗ2
#define R0VN75LZ2	 BUFFER[753]	//(R0VN75LZ2) АС по периоду разгонана БАЗ2
#define idR0VN75LZ2	 317	//(R0VN75LZ2) АС по периоду разгонана БАЗ2
#define A0EE01LS1	 BUFFER[755]	//(A0EE01LS1) Исправность АКНП канал1 на БАЗ1
#define idA0EE01LS1	 318	//(A0EE01LS1) Исправность АКНП канал1 на БАЗ1
#define R0VN75LZ1	 BUFFER[757]	//(R0VN75LZ1) АС по периоду разгонана БАЗ1
#define idR0VN75LZ1	 319	//(R0VN75LZ1) АС по периоду разгонана БАЗ1
#define R0VN65LS1	 BUFFER[759]	//(R0VN65LS1) ПС по периоду разгона канал1
#define idR0VN65LS1	 320	//(R0VN65LS1) ПС по периоду разгона канал1
#define R0VN01RS1	 BUFFER[761]	//(R0VN01RS1) Период разгона канал1
#define idR0VN01RS1	 321	//(R0VN01RS1) Период разгона канал1
#define A1VN71LS1	 BUFFER[766]	//(A1VN71LS1) Блокировка автоматического  подъёма ББ канал 1 на БАЗ2
#define idA1VN71LS1	 322	//(A1VN71LS1) Блокировка автоматического  подъёма ББ канал 1 на БАЗ2
#define R0VN71LZ2	 BUFFER[768]	//(R0VN71LZ2) АС по мощности канал 1  на БАЗ2
#define idR0VN71LZ2	 323	//(R0VN71LZ2) АС по мощности канал 1  на БАЗ2
#define R0VN15RS1	 BUFFER[770]	//(R0VN15RS1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
#define idR0VN15RS1	 324	//(R0VN15RS1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
#define A0VN71LS1	 BUFFER[773]	//(A0VN71LS1) Блокировка автоматического  подъёма ББ канал 1 на БАЗ1
#define idA0VN71LS1	 325	//(A0VN71LS1) Блокировка автоматического  подъёма ББ канал 1 на БАЗ1
#define R0VN71LZ1	 BUFFER[775]	//(R0VN71LZ1) АС по мощности канал1 на БАЗ1
#define idR0VN71LZ1	 326	//(R0VN71LZ1) АС по мощности канал1 на БАЗ1
#define R0VN61LS1	 BUFFER[777]	//(R0VN61LS1) ПС по мощности канал1
#define idR0VN61LS1	 327	//(R0VN61LS1) ПС по мощности канал1
#define R0VN02RS1	 BUFFER[779]	//(R0VN02RS1) Уровень мощности канал1
#define idR0VN02RS1	 328	//(R0VN02RS1) Уровень мощности канал1
#define B3IS35LDU	 BUFFER[784]	//(B3IS35LDU) Клапан «ВПИС2» открыт(обесточен)
#define idB3IS35LDU	 329	//(B3IS35LDU) Клапан «ВПИС2» открыт(обесточен)
#define B3AD34LDU	 BUFFER[786]	//(B3AD34LDU) Клапан (ВПИС2) открыть (обесточить)
#define idB3AD34LDU	 330	//(B3AD34LDU) Клапан (ВПИС2) открыть (обесточить)
#define fEM_R0UL01RIM	 BUFFER[788]	//(R0UL01RIM) Среднее время генерации нейтронов
#define idfEM_R0UL01RIM	 331	//(R0UL01RIM) Среднее время генерации нейтронов
#define fEM_R0UN02RIM	 BUFFER[793]	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define idfEM_R0UN02RIM	 332	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define fEM_A1UR01RIM	 BUFFER[798]	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR01RIM	 333	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define fEM_A1UR00RIM	 BUFFER[803]	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR00RIM	 334	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define fEM_A3UR00RIM	 BUFFER[808]	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR00RIM	 335	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define fEM_A3UR01RIM	 BUFFER[813]	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR01RIM	 336	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define fEM_R0UT01RIM	 BUFFER[818]	//(R0UT01RIM) Температурный коэффициент (долл)
#define idfEM_R0UT01RIM	 337	//(R0UT01RIM) Температурный коэффициент (долл)
#define fEM_R0UT02RIM	 BUFFER[823]	//(R0UT02RIM) Масса топлива в АЗ
#define idfEM_R0UT02RIM	 338	//(R0UT02RIM) Масса топлива в АЗ
#define fEM_R0UT04RIM	 BUFFER[828]	//(R0UT04RIM) Удельная теплоёмкость топлива
#define idfEM_R0UT04RIM	 339	//(R0UT04RIM) Удельная теплоёмкость топлива
#define fEM_R0UT03RIM	 BUFFER[833]	//(R0UT03RIM) Нормальная температура АЗ град
#define idfEM_R0UT03RIM	 340	//(R0UT03RIM) Нормальная температура АЗ град
#define fEM_R0UT05RIM	 BUFFER[838]	//(R0UT05RIM) Энергия деления ядра
#define idfEM_R0UT05RIM	 341	//(R0UT05RIM) Энергия деления ядра
#define fEM_R0UT06RIM	 BUFFER[843]	//(R0UT06RIM) Конвекционное сопротивление при обдуве
#define idfEM_R0UT06RIM	 342	//(R0UT06RIM) Конвекционное сопротивление при обдуве
#define fEM_A1UC02RDU	 BUFFER[848]	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define idfEM_A1UC02RDU	 343	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define fEM_A1UC04RIM	 BUFFER[853]	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define idfEM_A1UC04RIM	 344	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define fEM_A1UC05RIM	 BUFFER[858]	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define idfEM_A1UC05RIM	 345	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define fEM_A1UC06RIM	 BUFFER[863]	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define idfEM_A1UC06RIM	 346	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define fEM_A2UC06RIM	 BUFFER[868]	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define idfEM_A2UC06RIM	 347	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define fEM_A2UC05RIM	 BUFFER[873]	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define idfEM_A2UC05RIM	 348	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define fEM_A2UC04RIM	 BUFFER[878]	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define idfEM_A2UC04RIM	 349	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define fEM_A2UC02RDU	 BUFFER[883]	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define idfEM_A2UC02RDU	 350	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define fEM_A3UC06RIM	 BUFFER[888]	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define idfEM_A3UC06RIM	 351	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define fEM_A3UC05RIM	 BUFFER[893]	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC05RIM	 352	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define fEM_A3UC04RIM	 BUFFER[898]	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define idfEM_A3UC04RIM	 353	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define fEM_A3UC02RDU	 BUFFER[903]	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define idfEM_A3UC02RDU	 354	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define fEM_R4UV80RDU	 BUFFER[908]	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
#define idfEM_R4UV80RDU	 355	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
#define fEM_R4UC10RIM	 BUFFER[913]	//(R4UC10RIM) Координата верхних механических упоров тележки мм
#define idfEM_R4UC10RIM	 356	//(R4UC10RIM) Координата верхних механических упоров тележки мм
#define fEM_R4UC20RIM	 BUFFER[918]	//(R4UC20RIM) Координата нижних механических упоров тележки мм
#define idfEM_R4UC20RIM	 357	//(R4UC20RIM) Координата нижних механических упоров тележки мм
#define fEM_B8UC21RIM	 BUFFER[923]	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define idfEM_B8UC21RIM	 358	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define fEM_B8UC20RIM	 BUFFER[928]	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define idfEM_B8UC20RIM	 359	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define fEM_B8UC11RIM	 BUFFER[933]	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define idfEM_B8UC11RIM	 360	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define fEM_B8UC10RIM	 BUFFER[938]	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define idfEM_B8UC10RIM	 361	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define fEM_B8UV80RDU	 BUFFER[943]	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define idfEM_B8UV80RDU	 362	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define fEM_A8UV80RDU	 BUFFER[948]	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define idfEM_A8UV80RDU	 363	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define fEM_A8UC10RIM	 BUFFER[953]	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define idfEM_A8UC10RIM	 364	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define fEM_A8UC11RIM	 BUFFER[958]	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define idfEM_A8UC11RIM	 365	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define fEM_A8UC20RIM	 BUFFER[963]	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define idfEM_A8UC20RIM	 366	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define fEM_A8UC21RIM	 BUFFER[968]	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define idfEM_A8UC21RIM	 367	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define fEM_A6UC10RIM	 BUFFER[973]	//(A6UC10RIM) Время полного хода БЗ (сек)
#define idfEM_A6UC10RIM	 368	//(A6UC10RIM) Время полного хода БЗ (сек)
#define fEM_R1UC10RIM	 BUFFER[978]	//(R1UC10RIM) Время полного хода МДЗ сек
#define idfEM_R1UC10RIM	 369	//(R1UC10RIM) Время полного хода МДЗ сек
#define fEM_A5UC10RIM	 BUFFER[983]	//(A5UC10RIM) Время полного хода НЛ сек
#define idfEM_A5UC10RIM	 370	//(A5UC10RIM) Время полного хода НЛ сек
#define fEM_A0UN01RIM	 BUFFER[988]	//(A0UN01RIM) Мощность источника нейтронов ИНИ
#define idfEM_A0UN01RIM	 371	//(A0UN01RIM) Мощность источника нейтронов ИНИ
#define fEM_R4UC22RIM	 BUFFER[993]	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define idfEM_R4UC22RIM	 372	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define fEM_R4UC23RIM	 BUFFER[998]	//(R4UC23RIM) Y-координата АЗ1 см
#define idfEM_R4UC23RIM	 373	//(R4UC23RIM) Y-координата АЗ1 см
#define fEM_A1UG01RDU	 BUFFER[1003]	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define idfEM_A1UG01RDU	 374	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define fEM_A2UG01RDU	 BUFFER[1008]	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
#define idfEM_A2UG01RDU	 375	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
#define fEM_A3UG01RDU	 BUFFER[1013]	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
#define idfEM_A3UG01RDU	 376	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
#define fEM_R7UC10RIM	 BUFFER[1018]	//(R7UC10RIM) X-координата КНК53М R7IN13 см
#define idfEM_R7UC10RIM	 377	//(R7UC10RIM) X-координата КНК53М R7IN13 см
#define fEM_R7UC19RIM	 BUFFER[1023]	//(R7UC19RIM) Y-координата СНМ-11 (11) см
#define idfEM_R7UC19RIM	 378	//(R7UC19RIM) Y-координата СНМ-11 (11) см
#define fEM_R7UI02RIM	 BUFFER[1028]	//(R7UI02RIM) Коэффициент усиления уровня радиации
#define idfEM_R7UI02RIM	 379	//(R7UI02RIM) Коэффициент усиления уровня радиации
#define fEM_R7UL01RIM	 BUFFER[1033]	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define idfEM_R7UL01RIM	 380	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define fEM_A2UR00RIM	 BUFFER[1038]	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define idfEM_A2UR00RIM	 381	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define fEM_A2UR01RIM	 BUFFER[1043]	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define idfEM_A2UR01RIM	 382	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define fEM_A0UN02RIM	 BUFFER[1048]	//(A0UN02RIM) Мощность источника нейтронов с АНИ
#define idfEM_A0UN02RIM	 383	//(A0UN02RIM) Мощность источника нейтронов с АНИ
#define fEM_R0UR30RIM	 BUFFER[1053]	//(R0UR30RIM) Реактивность вносимая образцами (долл)
#define idfEM_R0UR30RIM	 384	//(R0UR30RIM) Реактивность вносимая образцами (долл)
#define fEM_R0UR01RIM	 BUFFER[1058]	//(R0UR01RIM) Стартовая отрицательная реактивность
#define idfEM_R0UR01RIM	 385	//(R0UR01RIM) Стартовая отрицательная реактивность
#define fEM_R0UT02RDU	 BUFFER[1063]	//(R0UT02RDU) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RDU	 386	//(R0UT02RDU) Верхний предел шкалы датчика температуры
#define fEM_R0UT01RDU	 BUFFER[1068]	//(R0UT01RDU) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RDU	 387	//(R0UT01RDU) Нижний предел шкалы датчика температуры
#define fEM_A1UC03RDU	 BUFFER[1073]	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define idfEM_A1UC03RDU	 388	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define fEM_A2UP03RDU	 BUFFER[1078]	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP03RDU	 389	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UP04RDU	 BUFFER[1083]	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP04RDU	 390	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UC03RDU	 BUFFER[1088]	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define idfEM_A2UC03RDU	 391	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define fEM_A3UP03RDU	 BUFFER[1093]	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	 392	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	 BUFFER[1098]	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	 393	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UC03RDU	 BUFFER[1103]	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define idfEM_A3UC03RDU	 394	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define fEM_R7UI74RIM	 BUFFER[1108]	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define idfEM_R7UI74RIM	 395	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define fEM_A8UC03RDU	 BUFFER[1113]	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define idfEM_A8UC03RDU	 396	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define fEM_R0UV87RDU	 BUFFER[1118]	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	 397	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV81RDU	 BUFFER[1123]	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	 398	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	 BUFFER[1128]	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	 399	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	 BUFFER[1133]	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	 400	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	 BUFFER[1138]	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	 401	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define fEM_R0UV85RDU	 BUFFER[1143]	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	 402	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV86RDU	 BUFFER[1148]	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	 403	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_A8UC08RDU	 BUFFER[1153]	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define idfEM_A8UC08RDU	 404	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define fEM_B8UC08RDU	 BUFFER[1158]	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define idfEM_B8UC08RDU	 405	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define fEM_R4UC08RDU	 BUFFER[1163]	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define idfEM_R4UC08RDU	 406	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define fEM_A0UX00RSS	 BUFFER[1168]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 407	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_R7UX01RSS	 BUFFER[1173]	//(R7UX01RSS) X-координата камеры R7IN11
#define idfEM_R7UX01RSS	 408	//(R7UX01RSS) X-координата камеры R7IN11
#define fEM_R7UX02RSS	 BUFFER[1178]	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define idfEM_R7UX02RSS	 409	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define fEM_R7UX04RSS	 BUFFER[1183]	//(R7UX04RSS) X-координата камеры R7IN21 (см)
#define idfEM_R7UX04RSS	 410	//(R7UX04RSS) X-координата камеры R7IN21 (см)
#define fEM_R7UX05RSS	 BUFFER[1188]	//(R7UX05RSS) X-координата камеры R7IN22 (см)
#define idfEM_R7UX05RSS	 411	//(R7UX05RSS) X-координата камеры R7IN22 (см)
#define fEM_R7UX06RSS	 BUFFER[1193]	//(R7UX06RSS) X-координата камеры R7IN23 (см)
#define idfEM_R7UX06RSS	 412	//(R7UX06RSS) X-координата камеры R7IN23 (см)
#define fEM_R7UX07RSS	 BUFFER[1198]	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define idfEM_R7UX07RSS	 413	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define fEM_R7UX08RSS	 BUFFER[1203]	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define idfEM_R7UX08RSS	 414	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define fEM_R7UX09RSS	 BUFFER[1208]	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define idfEM_R7UX09RSS	 415	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define fEM_R7UY01RSS	 BUFFER[1213]	//(R7UY01RSS) Y-координата камеры R7IN11
#define idfEM_R7UY01RSS	 416	//(R7UY01RSS) Y-координата камеры R7IN11
#define fEM_R7UY02RSS	 BUFFER[1218]	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define idfEM_R7UY02RSS	 417	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define fEM_R7UY04RSS	 BUFFER[1223]	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
#define idfEM_R7UY04RSS	 418	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
#define fEM_R7UY05RSS	 BUFFER[1228]	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
#define idfEM_R7UY05RSS	 419	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
#define fEM_R7UY06RSS	 BUFFER[1233]	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
#define idfEM_R7UY06RSS	 420	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
#define fEM_R7UY07RSS	 BUFFER[1238]	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define idfEM_R7UY07RSS	 421	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define fEM_R7UY08RSS	 BUFFER[1243]	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define idfEM_R7UY08RSS	 422	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define fEM_R7UY09RSS	 BUFFER[1248]	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define idfEM_R7UY09RSS	 423	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define fEM_R7UX10RSS	 BUFFER[1253]	//(R7UX10RSS) X-координата камеры R7IN41
#define idfEM_R7UX10RSS	 424	//(R7UX10RSS) X-координата камеры R7IN41
#define fEM_R7UX11RSS	 BUFFER[1258]	//(R7UX11RSS) X-координата камеры R7IN42
#define idfEM_R7UX11RSS	 425	//(R7UX11RSS) X-координата камеры R7IN42
#define fEM_R7UX12RSS	 BUFFER[1263]	//(R7UX12RSS) X-координата камеры R7IN43
#define idfEM_R7UX12RSS	 426	//(R7UX12RSS) X-координата камеры R7IN43
#define fEM_R7UY10RSS	 BUFFER[1268]	//(R7UY10RSS) Y-координата камеры R7IN41
#define idfEM_R7UY10RSS	 427	//(R7UY10RSS) Y-координата камеры R7IN41
#define fEM_R7UY11RSS	 BUFFER[1273]	//(R7UY11RSS) Y-координата камеры R7IN42
#define idfEM_R7UY11RSS	 428	//(R7UY11RSS) Y-координата камеры R7IN42
#define fEM_R7UY12RSS	 BUFFER[1278]	//(R7UY12RSS) Y-координата камеры R7IN43
#define idfEM_R7UY12RSS	 429	//(R7UY12RSS) Y-координата камеры R7IN43
#define fEM_A0UX01RSS	 BUFFER[1283]	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define idfEM_A0UX01RSS	 430	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define fEM_A0UX02RSS	 BUFFER[1288]	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define idfEM_A0UX02RSS	 431	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define fEM_A0UX03RSS	 BUFFER[1293]	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define idfEM_A0UX03RSS	 432	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define fEM_A0UX04RSS	 BUFFER[1298]	//(A0UX04RSS) Первый коэффициент калибровки камеры4
#define idfEM_A0UX04RSS	 433	//(A0UX04RSS) Первый коэффициент калибровки камеры4
#define fEM_A0UX05RSS	 BUFFER[1303]	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
#define idfEM_A0UX05RSS	 434	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
#define fEM_A0UX06RSS	 BUFFER[1308]	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
#define idfEM_A0UX06RSS	 435	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
#define fEM_A0UX07RSS	 BUFFER[1313]	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define idfEM_A0UX07RSS	 436	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define fEM_A0UX08RSS	 BUFFER[1318]	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define idfEM_A0UX08RSS	 437	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define fEM_A0UX09RSS	 BUFFER[1323]	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define idfEM_A0UX09RSS	 438	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define fEM_A0UX10RSS	 BUFFER[1328]	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define idfEM_A0UX10RSS	 439	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define fEM_A0UX11RSS	 BUFFER[1333]	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define idfEM_A0UX11RSS	 440	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define fEM_A0UX12RSS	 BUFFER[1338]	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define idfEM_A0UX12RSS	 441	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define fEM_B0UX01RSS	 BUFFER[1343]	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define idfEM_B0UX01RSS	 442	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define fEM_B0UX02RSS	 BUFFER[1348]	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define idfEM_B0UX02RSS	 443	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define fEM_B0UX03RSS	 BUFFER[1353]	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define idfEM_B0UX03RSS	 444	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define fEM_B0UX04RSS	 BUFFER[1358]	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
#define idfEM_B0UX04RSS	 445	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
#define fEM_B0UX05RSS	 BUFFER[1363]	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define idfEM_B0UX05RSS	 446	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define fEM_B0UX06RSS	 BUFFER[1368]	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
#define idfEM_B0UX06RSS	 447	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
#define fEM_B0UX07RSS	 BUFFER[1373]	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define idfEM_B0UX07RSS	 448	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define fEM_B0UX08RSS	 BUFFER[1378]	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define idfEM_B0UX08RSS	 449	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define fEM_B0UX09RSS	 BUFFER[1383]	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define idfEM_B0UX09RSS	 450	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define fEM_B0UX10RSS	 BUFFER[1388]	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define idfEM_B0UX10RSS	 451	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define fEM_B0UX11RSS	 BUFFER[1393]	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define idfEM_B0UX11RSS	 452	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define fEM_B0UX12RSS	 BUFFER[1398]	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define idfEM_B0UX12RSS	 453	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define fEM_R0UH02RSS	 BUFFER[1403]	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define idfEM_R0UH02RSS	 454	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define fEM_R0UH03RSS	 BUFFER[1408]	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define idfEM_R0UH03RSS	 455	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define fEM_R4US80RDU	 BUFFER[1413]	//(R4US80RDU) Тормозной путь тележки (мм)
#define idfEM_R4US80RDU	 456	//(R4US80RDU) Тормозной путь тележки (мм)
#define fEM_R7UI71RIM	 BUFFER[1418]	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define idfEM_R7UI71RIM	 457	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define fEM_R7UI72RIM	 BUFFER[1423]	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
#define idfEM_R7UI72RIM	 458	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
#define fEM_R7UI73RIM	 BUFFER[1428]	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define idfEM_R7UI73RIM	 459	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define fEM_A1UP01RIM	 BUFFER[1433]	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define idfEM_A1UP01RIM	 460	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define fEM_A2UP01RIM	 BUFFER[1438]	//(A2UP01RIM) Текущее давление на сброс РБ
#define idfEM_A2UP01RIM	 461	//(A2UP01RIM) Текущее давление на сброс РБ
#define fEM_A0UP02RIM	 BUFFER[1443]	//(A0UP02RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP02RIM	 462	//(A0UP02RIM) Текущее давление в АЗ1,2
#define fEM_A3UP01RIM	 BUFFER[1448]	//(A3UP01RIM) Текущее давление на СПУСК ИС
#define idfEM_A3UP01RIM	 463	//(A3UP01RIM) Текущее давление на СПУСК ИС
#define fEM_A1UP82RIM	 BUFFER[1453]	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define idfEM_A1UP82RIM	 464	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define fEM_R0UP85RIM	 BUFFER[1458]	//(R0UP85RIM) Нижняя граница давления  в СИСТЕМЕ (МПа)
#define idfEM_R0UP85RIM	 465	//(R0UP85RIM) Нижняя граница давления  в СИСТЕМЕ (МПа)
#define fEM_R0UP88RIM	 BUFFER[1463]	//(R0UP88RIM) Верхняя граница давления  в СИСТЕМЕ (МПа)
#define idfEM_R0UP88RIM	 466	//(R0UP88RIM) Верхняя граница давления  в СИСТЕМЕ (МПа)
#define fEM_A3UP02RDU	 BUFFER[1468]	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define idfEM_A3UP02RDU	 467	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define fEM_A1UV02RIM	 BUFFER[1473]	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define idfEM_A1UV02RIM	 468	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define fEM_A3UV02RIM	 BUFFER[1478]	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define idfEM_A3UV02RIM	 469	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define fEM_A2UV02RIM	 BUFFER[1483]	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define idfEM_A2UV02RIM	 470	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define fEM_B8US80RDU	 BUFFER[1488]	//(B8US80RDU) Тормозной путь АЗ2 (мм)
#define idfEM_B8US80RDU	 471	//(B8US80RDU) Тормозной путь АЗ2 (мм)
#define fEM_A8US80RDU	 BUFFER[1493]	//(A8US80RDU) Тормозной путь ДС2 (мм)
#define idfEM_A8US80RDU	 472	//(A8US80RDU) Тормозной путь ДС2 (мм)
#define fEM_A6US80RDU	 BUFFER[1498]	//(A6US80RDU) Тормозной путь БЗ (мм)
#define idfEM_A6US80RDU	 473	//(A6US80RDU) Тормозной путь БЗ (мм)
#define fEM_A1US07RDU	 BUFFER[1503]	//(A1US07RDU) Постоянная времени масляного демпфера ББ
#define idfEM_A1US07RDU	 474	//(A1US07RDU) Постоянная времени масляного демпфера ББ
#define fEM_A2US07RDU	 BUFFER[1508]	//(A2US07RDU) Постоянная времени масляного демпфера РБ
#define idfEM_A2US07RDU	 475	//(A2US07RDU) Постоянная времени масляного демпфера РБ
#define fEM_A3US07RDU	 BUFFER[1513]	//(A3US07RDU) Постоянная времени масляного демпфера ИС
#define idfEM_A3US07RDU	 476	//(A3US07RDU) Постоянная времени масляного демпфера ИС
#define fEM_R7UI75RIM	 BUFFER[1518]	//(R7UI75RIM) Множитель к уровню радиации
#define idfEM_R7UI75RIM	 477	//(R7UI75RIM) Множитель к уровню радиации
#define fEM_R0UH21RSS	 BUFFER[1523]	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define idfEM_R0UH21RSS	 478	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define fEM_R0UH22RSS	 BUFFER[1528]	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define idfEM_R0UH22RSS	 479	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define fEM_R0UH23RSS	 BUFFER[1533]	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define idfEM_R0UH23RSS	 480	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define fEM_R0UR01RSS	 BUFFER[1538]	//(R0UR01RSS) Уровень по мощности РУ блокировки автоматического подъёма ББ
#define idfEM_R0UR01RSS	 481	//(R0UR01RSS) Уровень по мощности РУ блокировки автоматического подъёма ББ
#define fEM_R0UL52RSS	 BUFFER[1543]	//(R0UL52RSS) Уровень АС по мощности
#define idfEM_R0UL52RSS	 482	//(R0UL52RSS) Уровень АС по мощности
#define fEM_R0UL41RSS	 BUFFER[1548]	//(R0UL41RSS) Уровень ПС по периоду разгона
#define idfEM_R0UL41RSS	 483	//(R0UL41RSS) Уровень ПС по периоду разгона
#define fEM_R0UL51RSS	 BUFFER[1553]	//(R0UL51RSS) Уровень АС по периоду разгона
#define idfEM_R0UL51RSS	 484	//(R0UL51RSS) Уровень АС по периоду разгона
#define fEM_R0UL42RSS	 BUFFER[1558]	//(R0UL42RSS) Уровень ПС по мощности
#define idfEM_R0UL42RSS	 485	//(R0UL42RSS) Уровень ПС по мощности
#define fEM_R0UH05RSS	 BUFFER[1563]	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	 486	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_R0UN03RSS	 BUFFER[1568]	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN03RSS	 487	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define fEM_A4UL10RIM	 BUFFER[1573]	//(A4UL10RIM) Время полного перемещения НИ сек
#define idfEM_A4UL10RIM	 488	//(A4UL10RIM) Время полного перемещения НИ сек
#define fEM_A9UL10RIM	 BUFFER[1578]	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define idfEM_A9UL10RIM	 489	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define fEM_R3UL10RIM	 BUFFER[1583]	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define idfEM_R3UL10RIM	 490	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define fEM_R5UL10RIM	 BUFFER[1588]	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define idfEM_R5UL10RIM	 491	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define fEM_R6UL10RIM	 BUFFER[1593]	//(R6UL10RIM) Время полного хода кран-балки сек
#define idfEM_R6UL10RIM	 492	//(R6UL10RIM) Время полного хода кран-балки сек
#define lEM_C1AD31LRP	 BUFFER[1598]	//(C1AD31LRP) Общий сброс от РПУ
#define idlEM_C1AD31LRP	 493	//(C1AD31LRP) Общий сброс от РПУ
#define lEM_R0IE01LRP	 BUFFER[1600]	//(R0IE01LRP) Отключение питание детекторов
#define idlEM_R0IE01LRP	 494	//(R0IE01LRP) Отключение питание детекторов
#define lEM_R0IE02LRP	 BUFFER[1602]	//(R0IE02LRP) Отключить питание ПР, ПУ
#define idlEM_R0IE02LRP	 495	//(R0IE02LRP) Отключить питание ПР, ПУ
#define fEM_A0UP03RIM	 BUFFER[1604]	//(A0UP03RIM) Текущее давление в системе
#define idfEM_A0UP03RIM	 496	//(A0UP03RIM) Текущее давление в системе
#define fEM_A2UP02RIM	 BUFFER[1609]	//(A2UP02RIM) Текущее давление на подъём РБ
#define idfEM_A2UP02RIM	 497	//(A2UP02RIM) Текущее давление на подъём РБ
#define fEM_A2UP03RIM	 BUFFER[1614]	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define idfEM_A2UP03RIM	 498	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define fEM_A0UP01RIM	 BUFFER[1619]	//(A0UP01RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP01RIM	 499	//(A0UP01RIM) Текущее давление в АЗ1,2
#define fEM_A3UP02RIM	 BUFFER[1624]	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define idfEM_A3UP02RIM	 500	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define fEM_A4UP01RIM	 BUFFER[1629]	//(A4UP01RIM) Текущее давление на подъём НИ
#define idfEM_A4UP01RIM	 501	//(A4UP01RIM) Текущее давление на подъём НИ
#define fEM_A4UP02RIM	 BUFFER[1634]	//(A4UP02RIM) Нижняя граница давления на подъём НИ
#define idfEM_A4UP02RIM	 502	//(A4UP02RIM) Нижняя граница давления на подъём НИ
#define fEM_R7UI76RIM	 BUFFER[1639]	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define idfEM_R7UI76RIM	 503	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define fEM_R7UI77RIM	 BUFFER[1644]	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define idfEM_R7UI77RIM	 504	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define iEM_TERBB1	 BUFFER[1649]	//(TERBB1) Неисправности  ББ1
#define idiEM_TERBB1	 505	//(TERBB1) Неисправности  ББ1
#define fEM_A1MC02RC1	 BUFFER[1652]	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
#define idfEM_A1MC02RC1	 506	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
#define fEM_A1MV02RC1	 BUFFER[1657]	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
#define idfEM_A1MV02RC1	 507	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
#define iEM_TERBB2	 BUFFER[1662]	//(TERBB2) Неисправности  ББ2
#define idiEM_TERBB2	 508	//(TERBB2) Неисправности  ББ2
#define fEM_B1MC02RC1	 BUFFER[1665]	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
#define idfEM_B1MC02RC1	 509	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
#define fEM_B1MV02RC1	 BUFFER[1670]	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define idfEM_B1MV02RC1	 510	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define iEM_TERRB2	 BUFFER[1675]	//(TERRB2) Неисправности  РБ2
#define idiEM_TERRB2	 511	//(TERRB2) Неисправности  РБ2
#define fEM_B2MC02RC1	 BUFFER[1678]	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
#define idfEM_B2MC02RC1	 512	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
#define fEM_B2MV02RC1	 BUFFER[1683]	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define idfEM_B2MV02RC1	 513	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define iEM_TERRB1	 BUFFER[1688]	//(TERRB1) Неисправности  РБ1
#define idiEM_TERRB1	 514	//(TERRB1) Неисправности  РБ1
#define fEM_A2MC02RC1	 BUFFER[1691]	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
#define idfEM_A2MC02RC1	 515	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
#define fEM_A2MV02RC1	 BUFFER[1696]	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define idfEM_A2MV02RC1	 516	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define iEM_TERIS2	 BUFFER[1701]	//(TERIS2) Неисправности  ИС2
#define idiEM_TERIS2	 517	//(TERIS2) Неисправности  ИС2
#define fEM_B3MC02RC1	 BUFFER[1704]	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
#define idfEM_B3MC02RC1	 518	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
#define fEM_B3MV02RC1	 BUFFER[1709]	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define idfEM_B3MV02RC1	 519	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define iEM_TERIS1	 BUFFER[1714]	//(TERIS1) Неисправности  ИС1
#define idiEM_TERIS1	 520	//(TERIS1) Неисправности  ИС1
#define fEM_A3MC02RC1	 BUFFER[1717]	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
#define idfEM_A3MC02RC1	 521	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
#define fEM_A3MV02RC1	 BUFFER[1722]	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define idfEM_A3MV02RC1	 522	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define iEM_TERA1IE04LDU	 BUFFER[1727]	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define idiEM_TERA1IE04LDU	 523	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define iEM_TERA1IE03LDU	 BUFFER[1730]	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define idiEM_TERA1IE03LDU	 524	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define fEM_A1MC01RC1	 BUFFER[1733]	//(A1MC01RC1) Заданная координата  ББ1 от ИС
#define idfEM_A1MC01RC1	 525	//(A1MC01RC1) Заданная координата  ББ1 от ИС
#define iEM_TERB1IE03LDU	 BUFFER[1738]	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define idiEM_TERB1IE03LDU	 526	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define iEM_TERB1IE04LDU	 BUFFER[1741]	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define idiEM_TERB1IE04LDU	 527	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define fEM_B1MC01RC1	 BUFFER[1744]	//(B1MC01RC1) Заданная координата ББ2 от ИС
#define idfEM_B1MC01RC1	 528	//(B1MC01RC1) Заданная координата ББ2 от ИС
#define fEM_B1MV01RC1	 BUFFER[1749]	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define idfEM_B1MV01RC1	 529	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define fEM_B2MC01RC1	 BUFFER[1754]	//(B2MC01RC1) Заданная координата РБ2 от ИС
#define idfEM_B2MC01RC1	 530	//(B2MC01RC1) Заданная координата РБ2 от ИС
#define fEM_B2MV01RC1	 BUFFER[1759]	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define idfEM_B2MV01RC1	 531	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define fEM_A3MC01RC1	 BUFFER[1764]	//(A3MC01RC1) Заданная координата ИС1 от ИС
#define idfEM_A3MC01RC1	 532	//(A3MC01RC1) Заданная координата ИС1 от ИС
#define fEM_A3MV01RC1	 BUFFER[1769]	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define idfEM_A3MV01RC1	 533	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define fEM_B3MC01RC1	 BUFFER[1774]	//(B3MC01RC1) Заданная координата ИС2 от ИС
#define idfEM_B3MC01RC1	 534	//(B3MC01RC1) Заданная координата ИС2 от ИС
#define fEM_B3MV01RC1	 BUFFER[1779]	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define idfEM_B3MV01RC1	 535	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define iEM_TERA2SS21LIM	 BUFFER[1784]	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define idiEM_TERA2SS21LIM	 536	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define iEM_TERA2SS12LIM	 BUFFER[1787]	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define idiEM_TERA2SS12LIM	 537	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define iEM_TERR6SS21LIM	 BUFFER[1790]	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
#define idiEM_TERR6SS21LIM	 538	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
#define iEM_TERA2VP82LIM	 BUFFER[1793]	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define idiEM_TERA2VP82LIM	 539	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define iEM_TERA2SS11LIM	 BUFFER[1796]	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define idiEM_TERA2SS11LIM	 540	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define iEM_TERB3SS21LIM	 BUFFER[1799]	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define idiEM_TERB3SS21LIM	 541	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define iEM_TERA0MT01RIM	 BUFFER[1802]	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define idiEM_TERA0MT01RIM	 542	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define iEM_TERB0MT01RIM	 BUFFER[1805]	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define idiEM_TERB0MT01RIM	 543	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define iEM_TERA2SP01RIM	 BUFFER[1808]	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define idiEM_TERA2SP01RIM	 544	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define iEM_TERB2SP01RIM	 BUFFER[1811]	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define idiEM_TERB2SP01RIM	 545	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define iEM_TERB3SP02RIM	 BUFFER[1814]	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define idiEM_TERB3SP02RIM	 546	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define iEM_TERA3SC01RIM	 BUFFER[1817]	//(TERA3SC01RIM) Искажение: Координата штока ИС1
#define idiEM_TERA3SC01RIM	 547	//(TERA3SC01RIM) Искажение: Координата штока ИС1
#define iEM_TERA3VP81LIM	 BUFFER[1820]	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define idiEM_TERA3VP81LIM	 548	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define iEM_TERA2SC01RIM	 BUFFER[1823]	//(TERA2SC01RIM) Искажение: Координата штока РБ1
#define idiEM_TERA2SC01RIM	 549	//(TERA2SC01RIM) Искажение: Координата штока РБ1
#define iEM_TERA2SS33LIM	 BUFFER[1826]	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define idiEM_TERA2SS33LIM	 550	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define iEM_TERA3SS21LIM	 BUFFER[1829]	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define idiEM_TERA3SS21LIM	 551	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define iEM_TERA3SS33LIM	 BUFFER[1832]	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define idiEM_TERA3SS33LIM	 552	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define iEM_TERA3SS31LIM	 BUFFER[1835]	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define idiEM_TERA3SS31LIM	 553	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define iEM_TERB3SS31LIM	 BUFFER[1838]	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define idiEM_TERB3SS31LIM	 554	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define iEM_TERB3SS33LIM	 BUFFER[1841]	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define idiEM_TERB3SS33LIM	 555	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define iEM_TERB3SC01RIM	 BUFFER[1844]	//(TERB3SC01RIM) Искажение: Координата штока ИС2
#define idiEM_TERB3SC01RIM	 556	//(TERB3SC01RIM) Искажение: Координата штока ИС2
#define iEM_TERA3SS11LIM	 BUFFER[1847]	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define idiEM_TERA3SS11LIM	 557	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define iEM_TERB3SS11LIM	 BUFFER[1850]	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define idiEM_TERB3SS11LIM	 558	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define iEM_TERR6IS64LIM	 BUFFER[1853]	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
#define idiEM_TERR6IS64LIM	 559	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
#define iEM_TERB3SS22LIM	 BUFFER[1856]	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define idiEM_TERB3SS22LIM	 560	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define iEM_TERA3SS22LIM	 BUFFER[1859]	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define idiEM_TERA3SS22LIM	 561	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define iEM_TERA3SP02RIM	 BUFFER[1862]	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define idiEM_TERA3SP02RIM	 562	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define iEM_TERR6IS62LIM	 BUFFER[1865]	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
#define idiEM_TERR6IS62LIM	 563	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
#define iEM_TERR6IS66LIM	 BUFFER[1868]	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idiEM_TERR6IS66LIM	 564	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define iEM_TERR6IS67LIM	 BUFFER[1871]	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idiEM_TERR6IS67LIM	 565	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
#define iEM_TERA0VP81LIM	 BUFFER[1874]	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define idiEM_TERA0VP81LIM	 566	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define iEM_TERB0VP81LIM	 BUFFER[1877]	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define idiEM_TERB0VP81LIM	 567	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define iEM_TERR0VP81LIM	 BUFFER[1880]	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
#define idiEM_TERR0VP81LIM	 568	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
#define iEM_TERR0VP82LIM	 BUFFER[1883]	//(TERR0VP82LIM) Искажение: Давление  в СИСТЕМЕ-2 в норме
#define idiEM_TERR0VP82LIM	 569	//(TERR0VP82LIM) Искажение: Давление  в СИСТЕМЕ-2 в норме
#define iEM_TERR6IS68LIM	 BUFFER[1886]	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
#define idiEM_TERR6IS68LIM	 570	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
#define iEM_TERR7SI74RIM	 BUFFER[1889]	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define idiEM_TERR7SI74RIM	 571	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define iEM_TERA5SS21LIM	 BUFFER[1892]	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define idiEM_TERA5SS21LIM	 572	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define iEM_TERB5SS11LIM	 BUFFER[1895]	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define idiEM_TERB5SS11LIM	 573	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define iEM_TERA5SS11LIM	 BUFFER[1898]	//(TERA5SS11LIM) Искажение: Приход на ВУ НЛ1
#define idiEM_TERA5SS11LIM	 574	//(TERA5SS11LIM) Искажение: Приход на ВУ НЛ1
#define iEM_TERA9SS11LIM	 BUFFER[1901]	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define idiEM_TERA9SS11LIM	 575	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define iEM_TERB2SS11LIM	 BUFFER[1904]	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define idiEM_TERB2SS11LIM	 576	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define iEM_TERB2SS12LIM	 BUFFER[1907]	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define idiEM_TERB2SS12LIM	 577	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define iEM_TERB2SS21LIM	 BUFFER[1910]	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define idiEM_TERB2SS21LIM	 578	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define iEM_TERR3SS11LIM	 BUFFER[1913]	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define idiEM_TERR3SS11LIM	 579	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define iEM_TERB2SC01RIM	 BUFFER[1916]	//(TERB2SC01RIM) Искажение: Координата штока РБ2
#define idiEM_TERB2SC01RIM	 580	//(TERB2SC01RIM) Искажение: Координата штока РБ2
#define iEM_TERR3SS21LIM	 BUFFER[1919]	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define idiEM_TERR3SS21LIM	 581	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define iEM_TERR5SS11LIM	 BUFFER[1922]	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define idiEM_TERR5SS11LIM	 582	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define iEM_TERR3SS12LIM	 BUFFER[1925]	//(TERR3SS12LIM) Искажение: Приход на ВУ гомогенных дверей-2
#define idiEM_TERR3SS12LIM	 583	//(TERR3SS12LIM) Искажение: Приход на ВУ гомогенных дверей-2
#define iEM_TERR3SS22LIM	 BUFFER[1928]	//(TERR3SS22LIM) Искажение: Приход на НУ гомогенных дверей-2
#define idiEM_TERR3SS22LIM	 584	//(TERR3SS22LIM) Искажение: Приход на НУ гомогенных дверей-2
#define iEM_TERA4SS11LIM	 BUFFER[1931]	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define idiEM_TERA4SS11LIM	 585	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define iEM_TERR1SS11LIM	 BUFFER[1934]	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define idiEM_TERR1SS11LIM	 586	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define iEM_TERR1SS21LIM	 BUFFER[1937]	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define idiEM_TERR1SS21LIM	 587	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define iEM_TERR2SS11LIM	 BUFFER[1940]	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define idiEM_TERR2SS11LIM	 588	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define iEM_TERR2SS21LIM	 BUFFER[1943]	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define idiEM_TERR2SS21LIM	 589	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define iEM_TERA4VP82LIM	 BUFFER[1946]	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define idiEM_TERA4VP82LIM	 590	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define iEM_TERB4SS21LIM	 BUFFER[1949]	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define idiEM_TERB4SS21LIM	 591	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define iEM_TERR5SS21LIM	 BUFFER[1952]	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
#define idiEM_TERR5SS21LIM	 592	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
#define iEM_TERB6SS21LIM	 BUFFER[1955]	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define idiEM_TERB6SS21LIM	 593	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define iEM_TERB4SS11LIM	 BUFFER[1958]	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define idiEM_TERB4SS11LIM	 594	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define iEM_TERA4SS21LIM	 BUFFER[1961]	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define idiEM_TERA4SS21LIM	 595	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define iEM_TERA6MS11LIM	 BUFFER[1964]	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define idiEM_TERA6MS11LIM	 596	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define iEM_TERA6SS21LIM	 BUFFER[1967]	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define idiEM_TERA6SS21LIM	 597	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define iEM_TERB6SS11LIM	 BUFFER[1970]	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define idiEM_TERB6SS11LIM	 598	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define iEM_TERR4SS11LIM	 BUFFER[1973]	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define idiEM_TERR4SS11LIM	 599	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define iEM_TERR4MS21LIM	 BUFFER[1976]	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
#define idiEM_TERR4MS21LIM	 600	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
#define iEM_TERR4SS12LIM	 BUFFER[1979]	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define idiEM_TERR4SS12LIM	 601	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define iEM_TERR4SS22LIM	 BUFFER[1982]	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define idiEM_TERR4SS22LIM	 602	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define iEM_TERR8SS11LIM	 BUFFER[1985]	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define idiEM_TERR8SS11LIM	 603	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define iEM_TERB8SC01RIM	 BUFFER[1988]	//(TERB8SC01RIM) Искажение: Координата АЗ2
#define idiEM_TERB8SC01RIM	 604	//(TERB8SC01RIM) Искажение: Координата АЗ2
#define iEM_TERA8SC01RIM	 BUFFER[1991]	//(TERA8SC01RIM) Искажение: Координата ДС2
#define idiEM_TERA8SC01RIM	 605	//(TERA8SC01RIM) Искажение: Координата ДС2
#define iEM_TERB8SS12LIM	 BUFFER[1994]	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define idiEM_TERB8SS12LIM	 606	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define iEM_TERA8SS12LIM	 BUFFER[1997]	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define idiEM_TERA8SS12LIM	 607	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define iEM_TERB8SS22LIM	 BUFFER[2000]	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define idiEM_TERB8SS22LIM	 608	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define iEM_TERA8SS22LIM	 BUFFER[2003]	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define idiEM_TERA8SS22LIM	 609	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define iEM_TERA9SS21LIM	 BUFFER[2006]	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define idiEM_TERA9SS21LIM	 610	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define iEM_TERB9SS21LIM	 BUFFER[2009]	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
#define idiEM_TERB9SS21LIM	 611	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
#define iEM_TERB9SS11LIM	 BUFFER[2012]	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define idiEM_TERB9SS11LIM	 612	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define iEM_TERB5SS21LIM	 BUFFER[2015]	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define idiEM_TERB5SS21LIM	 613	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define iEM_TERA1SS21LIM	 BUFFER[2018]	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define idiEM_TERA1SS21LIM	 614	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define iEM_TERA1SS11LIM	 BUFFER[2021]	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
#define idiEM_TERA1SS11LIM	 615	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
#define iEM_TERA1SC01RIM	 BUFFER[2024]	//(TERA1SC01RIM) Искажение: Координата штока ББ1
#define idiEM_TERA1SC01RIM	 616	//(TERA1SC01RIM) Искажение: Координата штока ББ1
#define iEM_TERA1SS12LIM	 BUFFER[2027]	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define idiEM_TERA1SS12LIM	 617	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define iEM_TERB1SS21LIM	 BUFFER[2030]	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define idiEM_TERB1SS21LIM	 618	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define iEM_TERB1SS11LIM	 BUFFER[2033]	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define idiEM_TERB1SS11LIM	 619	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define iEM_TERB1MC01RIM	 BUFFER[2036]	//(TERB1MC01RIM) Искажение: Координата штока ББ2
#define idiEM_TERB1MC01RIM	 620	//(TERB1MC01RIM) Искажение: Координата штока ББ2
#define iEM_TERB1SS12LIM	 BUFFER[2039]	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define idiEM_TERB1SS12LIM	 621	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define iEM_TERR0IE43LIM	 BUFFER[2042]	//(TERR0IE43LIM) Исправность ВИП 0,5 4канала
#define idiEM_TERR0IE43LIM	 622	//(TERR0IE43LIM) Исправность ВИП 0,5 4канала
#define iEM_TERR0IE41LIM	 BUFFER[2045]	//(TERR0IE41LIM) Исправность ВИП 1,6 (№17) СНМ11 4канала
#define idiEM_TERR0IE41LIM	 623	//(TERR0IE41LIM) Исправность ВИП 1,6 (№17) СНМ11 4канала
#define lEM_A0EE06LC1	 BUFFER[2048]	//(A0EE06LC1) Исправность АКНП4 от диагностики контроллера (От ИС)
#define idlEM_A0EE06LC1	 624	//(A0EE06LC1) Исправность АКНП4 от диагностики контроллера (От ИС)
#define iEM_TERR0IE33LIM	 BUFFER[2050]	//(TERR0IE33LIM) Искажение:Исправность ВИП 0,5  3канала
#define idiEM_TERR0IE33LIM	 625	//(TERR0IE33LIM) Искажение:Исправность ВИП 0,5  3канала
#define iEM_TERR0IE31LIM	 BUFFER[2053]	//(TERR0IE31LIM) Искажение: Исправность ВИП 1,6 (№14) СНМ11 3канала
#define idiEM_TERR0IE31LIM	 626	//(TERR0IE31LIM) Искажение: Исправность ВИП 1,6 (№14) СНМ11 3канала
#define lEM_A0EE05LC1	 BUFFER[2056]	//(A0EE05LC1) Исправность АКНП3 от диагностики контроллера (От ИС)
#define idlEM_A0EE05LC1	 627	//(A0EE05LC1) Исправность АКНП3 от диагностики контроллера (От ИС)
#define iEM_TERR0IE11LIM	 BUFFER[2058]	//(TERR0IE11LIM) Искажение: Исправность ВИП 1,6 (№8) СНМ11 1канала
#define idiEM_TERR0IE11LIM	 628	//(TERR0IE11LIM) Искажение: Исправность ВИП 1,6 (№8) СНМ11 1канала
#define iEM_TERR0IE13LIM	 BUFFER[2061]	//(TERR0IE13LIM) Искажение: Исправность ВИП 0,5  1канала
#define idiEM_TERR0IE13LIM	 629	//(TERR0IE13LIM) Искажение: Исправность ВИП 0,5  1канала
#define lEM_A0EE03LC1	 BUFFER[2064]	//(A0EE03LC1) Исправность АКНП1 от диагностики контроллера (От ИС)
#define idlEM_A0EE03LC1	 630	//(A0EE03LC1) Исправность АКНП1 от диагностики контроллера (От ИС)
#define iEM_TERR0IE23LIM	 BUFFER[2066]	//(TERR0IE23LIM) Искажение: Исправность ВИП 0,5 (№13) КНК53М 2канала
#define idiEM_TERR0IE23LIM	 631	//(TERR0IE23LIM) Искажение: Исправность ВИП 0,5 (№13) КНК53М 2канала
#define iEM_TERR0IE21LIM	 BUFFER[2069]	//(TERR0IE21LIM) Искажение: Исправность ВИП 1,6 (№11) СНМ11 2канала
#define idiEM_TERR0IE21LIM	 632	//(TERR0IE21LIM) Искажение: Исправность ВИП 1,6 (№11) СНМ11 2канала
#define lEM_A0EE04LC1	 BUFFER[2072]	//(A0EE04LC1) Исправность АКНП2 от диагностики контроллера (От ИС)
#define idlEM_A0EE04LC1	 633	//(A0EE04LC1) Исправность АКНП2 от диагностики контроллера (От ИС)
#define iEM_TERTLG	 BUFFER[2074]	//(TERTLG) Неисправности  тележки от ИС
#define idiEM_TERTLG	 634	//(TERTLG) Неисправности  тележки от ИС
#define fEM_R4MC01RC1	 BUFFER[2077]	//(R4MC01RC1) Заданная координата тележки от ИС
#define idfEM_R4MC01RC1	 635	//(R4MC01RC1) Заданная координата тележки от ИС
#define fEM_R4MV01RC1	 BUFFER[2082]	//(R4MV01RC1) Заданная скорость тележки от ИС
#define idfEM_R4MV01RC1	 636	//(R4MV01RC1) Заданная скорость тележки от ИС
#define iEM_TERMAZ2	 BUFFER[2087]	//(TERMAZ2) Неисправности АЗ2 от ИС
#define idiEM_TERMAZ2	 637	//(TERMAZ2) Неисправности АЗ2 от ИС
#define fEM_B8MC01RC1	 BUFFER[2090]	//(B8MC01RC1) аданная координата АЗ2 от ИС
#define idfEM_B8MC01RC1	 638	//(B8MC01RC1) аданная координата АЗ2 от ИС
#define fEM_B8MV01RC1	 BUFFER[2095]	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
#define idfEM_B8MV01RC1	 639	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
#define iEM_TERDS2	 BUFFER[2100]	//(TERDS2) Неисправности ДС2 от ИС
#define idiEM_TERDS2	 640	//(TERDS2) Неисправности ДС2 от ИС
#define fEM_A8MC01RC1	 BUFFER[2103]	//(A8MC01RC1) Заданная координата ДС2 от ИС
#define idfEM_A8MC01RC1	 641	//(A8MC01RC1) Заданная координата ДС2 от ИС
#define fEM_A8MV01RC1	 BUFFER[2108]	//(A8MV01RC1) Заданная скорость ДС2 от ИС
#define idfEM_A8MV01RC1	 642	//(A8MV01RC1) Заданная скорость ДС2 от ИС
#define iEM_TERBZ1	 BUFFER[2113]	//(TERBZ1) Неисправности БЗ1
#define idiEM_TERBZ1	 643	//(TERBZ1) Неисправности БЗ1
#define fEM_A6MC01RC1	 BUFFER[2116]	//(A6MC01RC1) Заданная координата БЗ1 от ИС
#define idfEM_A6MC01RC1	 644	//(A6MC01RC1) Заданная координата БЗ1 от ИС
#define fEM_A6MV01RC1	 BUFFER[2121]	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
#define idfEM_A6MV01RC1	 645	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
#define iEM_TERBZ2	 BUFFER[2126]	//(TERBZ2) Неисправности БЗ2
#define idiEM_TERBZ2	 646	//(TERBZ2) Неисправности БЗ2
#define fEM_B6MC01RC1	 BUFFER[2129]	//(B6MC01RC1) Заданная координата БЗ2 от ИС
#define idfEM_B6MC01RC1	 647	//(B6MC01RC1) Заданная координата БЗ2 от ИС
#define fEM_B6MV01RC1	 BUFFER[2134]	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
#define idfEM_B6MV01RC1	 648	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
#define iEM_TERR3AD10LDU	 BUFFER[2139]	//(TERR3AD10LDU) Искажение: Гомогенные двери-1 открыть
#define idiEM_TERR3AD10LDU	 649	//(TERR3AD10LDU) Искажение: Гомогенные двери-1 открыть
#define iEM_TERR3AD20LDU	 BUFFER[2142]	//(TERR3AD20LDU) Искажение: Гомогенные двери-1 закрыть
#define idiEM_TERR3AD20LDU	 650	//(TERR3AD20LDU) Искажение: Гомогенные двери-1 закрыть
#define iEM_TERR3AD11LDU	 BUFFER[2145]	//(TERR3AD11LDU) Искажение: Гомогенные двери-2 открыть
#define idiEM_TERR3AD11LDU	 651	//(TERR3AD11LDU) Искажение: Гомогенные двери-2 открыть
#define iEM_TERR3AD21LDU	 BUFFER[2148]	//(TERR3AD21LDU) Искажение: Гомогенные двери-2 закрыть
#define idiEM_TERR3AD21LDU	 652	//(TERR3AD21LDU) Искажение: Гомогенные двери-2 закрыть
#define iEM_TERR5AD10LDU	 BUFFER[2151]	//(TERR5AD10LDU) Искажение: Открыть ворота отстойной зоны
#define idiEM_TERR5AD10LDU	 653	//(TERR5AD10LDU) Искажение: Открыть ворота отстойной зоны
#define iEM_TERR5AD20LDU	 BUFFER[2154]	//(TERR5AD20LDU) Искажение: Закрыть ворота отстойной зоны
#define idiEM_TERR5AD20LDU	 654	//(TERR5AD20LDU) Искажение: Закрыть ворота отстойной зоны
#define lEM_R3AD10LC1	 BUFFER[2157]	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define idlEM_R3AD10LC1	 655	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define lEM_R3AD20LC1	 BUFFER[2159]	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define idlEM_R3AD20LC1	 656	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define lEM_R3AD11LC1	 BUFFER[2161]	//(R3AD11LC1) Гомогенные двери-2 открыть от ИС
#define idlEM_R3AD11LC1	 657	//(R3AD11LC1) Гомогенные двери-2 открыть от ИС
#define lEM_R3AD21LC1	 BUFFER[2163]	//(R3AD21LC1) Гомогенные двери-2 закрыть от ИС
#define idlEM_R3AD21LC1	 658	//(R3AD21LC1) Гомогенные двери-2 закрыть от ИС
#define lEM_R6AD10LC1	 BUFFER[2165]	//(R6AD10LC1) Выкатить кран-балку от ИС
#define idlEM_R6AD10LC1	 659	//(R6AD10LC1) Выкатить кран-балку от ИС
#define lEM_R5AD10LC1	 BUFFER[2167]	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define idlEM_R5AD10LC1	 660	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define lEM_R5AD20LC1	 BUFFER[2169]	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define idlEM_R5AD20LC1	 661	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define iEM_TERMDZ2	 BUFFER[2171]	//(TERMDZ2) Неисправности МДЗ2
#define idiEM_TERMDZ2	 662	//(TERMDZ2) Неисправности МДЗ2
#define fEM_R2MC01RC1	 BUFFER[2174]	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
#define idfEM_R2MC01RC1	 663	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
#define fEM_R2MV01RC1	 BUFFER[2179]	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define idfEM_R2MV01RC1	 664	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define iEM_TERMDZ1	 BUFFER[2184]	//(TERMDZ1) Неисправности МДЗ1
#define idiEM_TERMDZ1	 665	//(TERMDZ1) Неисправности МДЗ1
#define fEM_R1MC01RC1	 BUFFER[2187]	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
#define idfEM_R1MC01RC1	 666	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
#define fEM_R1MV01RC1	 BUFFER[2192]	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define idfEM_R1MV01RC1	 667	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define iEM_TERNL1	 BUFFER[2197]	//(TERNL1) Неисправности НЛ1
#define idiEM_TERNL1	 668	//(TERNL1) Неисправности НЛ1
#define fEM_A5MC01RC1	 BUFFER[2200]	//(A5MC01RC1) Заданная координата НЛ1 от ИС
#define idfEM_A5MC01RC1	 669	//(A5MC01RC1) Заданная координата НЛ1 от ИС
#define fEM_A5MV01RC1	 BUFFER[2205]	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
#define idfEM_A5MV01RC1	 670	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
#define iEM_TERNL2	 BUFFER[2210]	//(TERNL2) Неисправности НЛ2
#define idiEM_TERNL2	 671	//(TERNL2) Неисправности НЛ2
#define fEM_B5MC01RC1	 BUFFER[2213]	//(B5MC01RC1) Заданная координата НЛ2 от ИС
#define idfEM_B5MC01RC1	 672	//(B5MC01RC1) Заданная координата НЛ2 от ИС
#define fEM_B5MV01RC1	 BUFFER[2218]	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
#define idfEM_B5MV01RC1	 673	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
#define lEM_R8AD10LC1	 BUFFER[2223]	//(R8AD10LC1) Установить аварийный НИ от ИС
#define idlEM_R8AD10LC1	 674	//(R8AD10LC1) Установить аварийный НИ от ИС
#define fEM_A1UC08RIM	 BUFFER[2225]	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define idfEM_A1UC08RIM	 675	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define fEM_A2UC08RIM	 BUFFER[2230]	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
#define idfEM_A2UC08RIM	 676	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
#define fEM_A3UC08RIM	 BUFFER[2235]	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define idfEM_A3UC08RIM	 677	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define fEM_R0UL01RSS	 BUFFER[2240]	//(R0UL01RSS) Шаг (мс) измерения периода
#define idfEM_R0UL01RSS	 678	//(R0UL01RSS) Шаг (мс) измерения периода
#define fEM_R0UL03RSS	 BUFFER[2245]	//(R0UL03RSS) Предельное время ожидания роста потока (сек)
#define idfEM_R0UL03RSS	 679	//(R0UL03RSS) Предельное время ожидания роста потока (сек)
#define iEM_TERB2SS33LIM	 BUFFER[2250]	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define idiEM_TERB2SS33LIM	 680	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define iEM_TERA1VP81LIM	 BUFFER[2253]	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define idiEM_TERA1VP81LIM	 681	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define iEM_TERB1VP81LIM	 BUFFER[2256]	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define idiEM_TERB1VP81LIM	 682	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define fEM_A0UT03RSP	 BUFFER[2259]	//(A0UT03RSP) Стартовая  температура АЗ1 град
#define idfEM_A0UT03RSP	 683	//(A0UT03RSP) Стартовая  температура АЗ1 град
#define fEM_A0UR01RSP	 BUFFER[2264]	//(A0UR01RSP) Стартовая  реактивность АЗ1
#define idfEM_A0UR01RSP	 684	//(A0UR01RSP) Стартовая  реактивность АЗ1
#define fEM_A0UR02RSP	 BUFFER[2269]	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
#define idfEM_A0UR02RSP	 685	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
#define fEM_B0UT03RSP	 BUFFER[2274]	//(B0UT03RSP) Стартовая  температура АЗ2 град
#define idfEM_B0UT03RSP	 686	//(B0UT03RSP) Стартовая  температура АЗ2 град
#define fEM_A1MC01RSP	 BUFFER[2279]	//(A1MC01RSP) Стартовая координата  ББ1
#define idfEM_A1MC01RSP	 687	//(A1MC01RSP) Стартовая координата  ББ1
#define fEM_A1MC02RSP	 BUFFER[2284]	//(A1MC02RSP) Стартовая координата штока ББ1
#define idfEM_A1MC02RSP	 688	//(A1MC02RSP) Стартовая координата штока ББ1
#define fEM_A1MV01RSP	 BUFFER[2289]	//(A1MV01RSP) Стартовая скорость движения  ББ1
#define idfEM_A1MV01RSP	 689	//(A1MV01RSP) Стартовая скорость движения  ББ1
#define fEM_A1MV02RSP	 BUFFER[2294]	//(A1MV02RSP) Стартовая скорость движения  ББ1
#define idfEM_A1MV02RSP	 690	//(A1MV02RSP) Стартовая скорость движения  ББ1
#define fEM_B1MC01RSP	 BUFFER[2299]	//(B1MC01RSP) Стартовая координата  ББ2
#define idfEM_B1MC01RSP	 691	//(B1MC01RSP) Стартовая координата  ББ2
#define fEM_B1MV01RSP	 BUFFER[2304]	//(B1MV01RSP) Стартовая скорость движения  ББ2
#define idfEM_B1MV01RSP	 692	//(B1MV01RSP) Стартовая скорость движения  ББ2
#define fEM_B1MC02RSP	 BUFFER[2309]	//(B1MC02RSP) Стартовая координата штока ББ2
#define idfEM_B1MC02RSP	 693	//(B1MC02RSP) Стартовая координата штока ББ2
#define fEM_B1MV02RSP	 BUFFER[2314]	//(B1MV02RSP) Стартовая скорость движения  ББ2
#define idfEM_B1MV02RSP	 694	//(B1MV02RSP) Стартовая скорость движения  ББ2
#define fEM_A2MC01RC1	 BUFFER[2319]	//(A2MC01RC1) Заданная координата РБ1 от ИС
#define idfEM_A2MC01RC1	 695	//(A2MC01RC1) Заданная координата РБ1 от ИС
#define fEM_A2MV01RC1	 BUFFER[2324]	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
#define idfEM_A2MV01RC1	 696	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
#define fEM_A2MC01RSP	 BUFFER[2329]	//(A2MC01RSP) Стартовая координата  РБ1
#define idfEM_A2MC01RSP	 697	//(A2MC01RSP) Стартовая координата  РБ1
#define fEM_A2MV01RSP	 BUFFER[2334]	//(A2MV01RSP) Стартовая скорость движения  РБ1
#define idfEM_A2MV01RSP	 698	//(A2MV01RSP) Стартовая скорость движения  РБ1
#define fEM_A2MC02RSP	 BUFFER[2339]	//(A2MC02RSP) Стартовая координата штока РБ1
#define idfEM_A2MC02RSP	 699	//(A2MC02RSP) Стартовая координата штока РБ1
#define fEM_A2MV02RSP	 BUFFER[2344]	//(A2MV02RSP) Стартовая скорость движения  РБ1
#define idfEM_A2MV02RSP	 700	//(A2MV02RSP) Стартовая скорость движения  РБ1
#define fEM_B2MC01RSP	 BUFFER[2349]	//(B2MC01RSP) Стартовая координата  РБ2
#define idfEM_B2MC01RSP	 701	//(B2MC01RSP) Стартовая координата  РБ2
#define fEM_B2MV01RSP	 BUFFER[2354]	//(B2MV01RSP) Стартовая скорость движения  РБ2
#define idfEM_B2MV01RSP	 702	//(B2MV01RSP) Стартовая скорость движения  РБ2
#define fEM_B2MC02RSP	 BUFFER[2359]	//(B2MC02RSP) Стартовая координата штока РБ2
#define idfEM_B2MC02RSP	 703	//(B2MC02RSP) Стартовая координата штока РБ2
#define fEM_B2MV02RSP	 BUFFER[2364]	//(B2MV02RSP) Стартовая скорость движения  РБ2
#define idfEM_B2MV02RSP	 704	//(B2MV02RSP) Стартовая скорость движения  РБ2
#define fEM_A3MC01RSP	 BUFFER[2369]	//(A3MC01RSP) Стартовая координата  ИС1
#define idfEM_A3MC01RSP	 705	//(A3MC01RSP) Стартовая координата  ИС1
#define fEM_A3MV01RSP	 BUFFER[2374]	//(A3MV01RSP) Стартовая скорость движения  ИС1
#define idfEM_A3MV01RSP	 706	//(A3MV01RSP) Стартовая скорость движения  ИС1
#define fEM_A3MC02RSP	 BUFFER[2379]	//(A3MC02RSP) Стартовая координата штока ИС1
#define idfEM_A3MC02RSP	 707	//(A3MC02RSP) Стартовая координата штока ИС1
#define fEM_A3MV02RSP	 BUFFER[2384]	//(A3MV02RSP) Стартовая скорость движения  ИС1
#define idfEM_A3MV02RSP	 708	//(A3MV02RSP) Стартовая скорость движения  ИС1
#define fEM_B3MC01RSP	 BUFFER[2389]	//(B3MC01RSP) Стартовая координата  ИС2
#define idfEM_B3MC01RSP	 709	//(B3MC01RSP) Стартовая координата  ИС2
#define fEM_B3MV01RSP	 BUFFER[2394]	//(B3MV01RSP) Стартовая скорость движения  ИС2
#define idfEM_B3MV01RSP	 710	//(B3MV01RSP) Стартовая скорость движения  ИС2
#define fEM_B3MC02RSP	 BUFFER[2399]	//(B3MC02RSP) Стартовая координата штока ИС2
#define idfEM_B3MC02RSP	 711	//(B3MC02RSP) Стартовая координата штока ИС2
#define fEM_B3MV02RSP	 BUFFER[2404]	//(B3MV02RSP) Стартовая скорость движения  ИС2
#define idfEM_B3MV02RSP	 712	//(B3MV02RSP) Стартовая скорость движения  ИС2
#define fEM_B8MC01RSP	 BUFFER[2409]	//(B8MC01RSP) Стартовая координата АЗ2
#define idfEM_B8MC01RSP	 713	//(B8MC01RSP) Стартовая координата АЗ2
#define fEM_B8MV01RSP	 BUFFER[2414]	//(B8MV01RSP) Стартовая скорость АЗ2
#define idfEM_B8MV01RSP	 714	//(B8MV01RSP) Стартовая скорость АЗ2
#define fEM_A8MC01RSP	 BUFFER[2419]	//(A8MC01RSP) Стартовая координата ДС2
#define idfEM_A8MC01RSP	 715	//(A8MC01RSP) Стартовая координата ДС2
#define fEM_A8MV01RSP	 BUFFER[2424]	//(A8MV01RSP) Стартовая скорость ДС2
#define idfEM_A8MV01RSP	 716	//(A8MV01RSP) Стартовая скорость ДС2
#define fEM_A6MC01RSP	 BUFFER[2429]	//(A6MC01RSP) Стартовая координата БЗ1
#define idfEM_A6MC01RSP	 717	//(A6MC01RSP) Стартовая координата БЗ1
#define fEM_A6MV01RSP	 BUFFER[2434]	//(A6MV01RSP) Стартовая скорость БЗ1
#define idfEM_A6MV01RSP	 718	//(A6MV01RSP) Стартовая скорость БЗ1
#define fEM_B6MC01RSP	 BUFFER[2439]	//(B6MC01RSP) Стартовая координата БЗ2
#define idfEM_B6MC01RSP	 719	//(B6MC01RSP) Стартовая координата БЗ2
#define fEM_B6MV01RSP	 BUFFER[2444]	//(B6MV01RSP) Стартовая скорость БЗ2
#define idfEM_B6MV01RSP	 720	//(B6MV01RSP) Стартовая скорость БЗ2
#define fEM_R3UC01RSP	 BUFFER[2449]	//(R3UC01RSP) Стартовая координата Гомогенных дверей - 1
#define idfEM_R3UC01RSP	 721	//(R3UC01RSP) Стартовая координата Гомогенных дверей - 1
#define fEM_R3UV01RSP	 BUFFER[2454]	//(R3UV01RSP) Стартовая скорость Гомогенных дверей-1
#define idfEM_R3UV01RSP	 722	//(R3UV01RSP) Стартовая скорость Гомогенных дверей-1
#define fEM_R3UC02RSP	 BUFFER[2459]	//(R3UC02RSP) Стартовая координата Гомогенных дверей - 2
#define idfEM_R3UC02RSP	 723	//(R3UC02RSP) Стартовая координата Гомогенных дверей - 2
#define fEM_R3UV02RSP	 BUFFER[2464]	//(R3UV02RSP) Стартовая скорость Гомогенных дверей-2
#define idfEM_R3UV02RSP	 724	//(R3UV02RSP) Стартовая скорость Гомогенных дверей-2
#define fEM_R5UC01RSP	 BUFFER[2469]	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
#define idfEM_R5UC01RSP	 725	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
#define fEM_R5UV01RSP	 BUFFER[2474]	//(R5UV01RSP) Стартовая скорость Ворот отстойной зоны
#define idfEM_R5UV01RSP	 726	//(R5UV01RSP) Стартовая скорость Ворот отстойной зоны
#define fEM_R6UC01RSP	 BUFFER[2479]	//(R6UC01RSP) Стартовая координата Кран-балки
#define idfEM_R6UC01RSP	 727	//(R6UC01RSP) Стартовая координата Кран-балки
#define fEM_R6UV01RSP	 BUFFER[2484]	//(R6UV01RSP) Стартовая скорость Кран-балки
#define idfEM_R6UV01RSP	 728	//(R6UV01RSP) Стартовая скорость Кран-балки
#define fEM_R2MC01RSP	 BUFFER[2489]	//(R2MC01RSP) Стартовая координата МДЗ2
#define idfEM_R2MC01RSP	 729	//(R2MC01RSP) Стартовая координата МДЗ2
#define fEM_R2MV01RSP	 BUFFER[2494]	//(R2MV01RSP) Стартовая скорость МДЗ2
#define idfEM_R2MV01RSP	 730	//(R2MV01RSP) Стартовая скорость МДЗ2
#define fEM_R1MC01RSP	 BUFFER[2499]	//(R1MC01RSP) Стартовая координата МДЗ1
#define idfEM_R1MC01RSP	 731	//(R1MC01RSP) Стартовая координата МДЗ1
#define fEM_R1MV01RSP	 BUFFER[2504]	//(R1MV01RSP) Стартовая скорость МДЗ1
#define idfEM_R1MV01RSP	 732	//(R1MV01RSP) Стартовая скорость МДЗ1
#define fEM_A5MC01RSP	 BUFFER[2509]	//(A5MC01RSP) Стартовая координата НЛ1
#define idfEM_A5MC01RSP	 733	//(A5MC01RSP) Стартовая координата НЛ1
#define fEM_A5MV01RSP	 BUFFER[2514]	//(A5MV01RSP) Стартовая скорость НЛ1
#define idfEM_A5MV01RSP	 734	//(A5MV01RSP) Стартовая скорость НЛ1
#define fEM_B5MC01RSP	 BUFFER[2519]	//(B5MC01RSP) Стартовая координата НЛ2
#define idfEM_B5MC01RSP	 735	//(B5MC01RSP) Стартовая координата НЛ2
#define fEM_B5MV01RSP	 BUFFER[2524]	//(B5MV01RSP) Стартовая скорость НЛ2
#define idfEM_B5MV01RSP	 736	//(B5MV01RSP) Стартовая скорость НЛ2
#define fEM_A9MC01RSP	 BUFFER[2529]	//(A9MC01RSP) Стартовая координата НИ ДС1
#define idfEM_A9MC01RSP	 737	//(A9MC01RSP) Стартовая координата НИ ДС1
#define fEM_A9MV01RSP	 BUFFER[2534]	//(A9MV01RSP) Стартовая скорость НИ ДС1
#define idfEM_A9MV01RSP	 738	//(A9MV01RSP) Стартовая скорость НИ ДС1
#define fEM_B9MC01RSP	 BUFFER[2539]	//(B9MC01RSP) Стартовая координата НИ ДС2
#define idfEM_B9MC01RSP	 739	//(B9MC01RSP) Стартовая координата НИ ДС2
#define fEM_B9MV01RSP	 BUFFER[2544]	//(B9MV01RSP) Стартовая скорость НИ ДС2
#define idfEM_B9MV01RSP	 740	//(B9MV01RSP) Стартовая скорость НИ ДС2
#define fEM_A4MC01RSP	 BUFFER[2549]	//(A4MC01RSP) Стартовая координата НИ1
#define idfEM_A4MC01RSP	 741	//(A4MC01RSP) Стартовая координата НИ1
#define fEM_A4MV01RSP	 BUFFER[2554]	//(A4MV01RSP) Стартовая скорость НИ1
#define idfEM_A4MV01RSP	 742	//(A4MV01RSP) Стартовая скорость НИ1
#define fEM_B4MC01RSP	 BUFFER[2559]	//(B4MC01RSP) Стартовая координата НИ2
#define idfEM_B4MC01RSP	 743	//(B4MC01RSP) Стартовая координата НИ2
#define fEM_B4MV01RSP	 BUFFER[2564]	//(B4MV01RSP) Стартовая скорость НИ2
#define idfEM_B4MV01RSP	 744	//(B4MV01RSP) Стартовая скорость НИ2
#define fEM_R4MC01RSP	 BUFFER[2569]	//(R4MC01RSP) Стартовая координата тележки
#define idfEM_R4MC01RSP	 745	//(R4MC01RSP) Стартовая координата тележки
#define fEM_R4MV01RSP	 BUFFER[2574]	//(R4MV01RSP) Стартовая скорость тележки
#define idfEM_R4MV01RSP	 746	//(R4MV01RSP) Стартовая скорость тележки
#define fEM_A1MV01RC1	 BUFFER[2579]	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
#define idfEM_A1MV01RC1	 747	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
#define iEM_TERB7MS31LIM	 BUFFER[2584]	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
#define idiEM_TERB7MS31LIM	 748	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
#define iEM_TERA7MS31LIM	 BUFFER[2587]	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define idiEM_TERA7MS31LIM	 749	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define bFirstEnterFlag	 BUFFER[2590]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 750	//(bFirstEnterFlag) 
#define internal1_m563_Out10	 BUFFER[2592]	//(internal1_m563_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m563_Out10	 751	//(internal1_m563_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m582_Out10	 BUFFER[2594]	//(internal1_m582_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m582_Out10	 752	//(internal1_m582_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m417_Out10	 BUFFER[2596]	//(internal1_m417_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m417_Out10	 753	//(internal1_m417_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m514_q0	 BUFFER[2598]	//(internal1_m514_q0) q0 - внутренний параметр
#define idinternal1_m514_q0	 754	//(internal1_m514_q0) q0 - внутренний параметр
#define internal1_m515_q0	 BUFFER[2600]	//(internal1_m515_q0) q0 - внутренний параметр
#define idinternal1_m515_q0	 755	//(internal1_m515_q0) q0 - внутренний параметр
#define internal1_m484_q0	 BUFFER[2602]	//(internal1_m484_q0) q0 - внутренний параметр
#define idinternal1_m484_q0	 756	//(internal1_m484_q0) q0 - внутренний параметр
#define internal1_m485_q0	 BUFFER[2604]	//(internal1_m485_q0) q0 - внутренний параметр
#define idinternal1_m485_q0	 757	//(internal1_m485_q0) q0 - внутренний параметр
#define internal1_m486_q0	 BUFFER[2606]	//(internal1_m486_q0) q0 - внутренний параметр
#define idinternal1_m486_q0	 758	//(internal1_m486_q0) q0 - внутренний параметр
#define internal1_m487_q0	 BUFFER[2608]	//(internal1_m487_q0) q0 - внутренний параметр
#define idinternal1_m487_q0	 759	//(internal1_m487_q0) q0 - внутренний параметр
#define internal1_m689_tx	 BUFFER[2610]	//(internal1_m689_tx) tx - время накопленное сек
#define idinternal1_m689_tx	 760	//(internal1_m689_tx) tx - время накопленное сек
#define internal1_m689_y0	 BUFFER[2615]	//(internal1_m689_y0) y0
#define idinternal1_m689_y0	 761	//(internal1_m689_y0) y0
#define internal1_m677_tx	 BUFFER[2616]	//(internal1_m677_tx) tx - время накопленное сек
#define idinternal1_m677_tx	 762	//(internal1_m677_tx) tx - время накопленное сек
#define internal1_m677_y0	 BUFFER[2621]	//(internal1_m677_y0) y0
#define idinternal1_m677_y0	 763	//(internal1_m677_y0) y0
#define internal1_m517_Out10	 BUFFER[2622]	//(internal1_m517_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m517_Out10	 764	//(internal1_m517_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m491_Out10	 BUFFER[2624]	//(internal1_m491_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m491_Out10	 765	//(internal1_m491_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m490_Out10	 BUFFER[2626]	//(internal1_m490_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m490_Out10	 766	//(internal1_m490_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m489_Out10	 BUFFER[2628]	//(internal1_m489_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m489_Out10	 767	//(internal1_m489_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m488_Out10	 BUFFER[2630]	//(internal1_m488_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m488_Out10	 768	//(internal1_m488_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m516_Out10	 BUFFER[2632]	//(internal1_m516_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m516_Out10	 769	//(internal1_m516_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m663_tx	 BUFFER[2634]	//(internal1_m663_tx) tx - время накопленное сек
#define idinternal1_m663_tx	 770	//(internal1_m663_tx) tx - время накопленное сек
#define internal1_m663_y0	 BUFFER[2639]	//(internal1_m663_y0) y0
#define idinternal1_m663_y0	 771	//(internal1_m663_y0) y0
#define internal1_m661_tx	 BUFFER[2640]	//(internal1_m661_tx) tx - время накопленное сек
#define idinternal1_m661_tx	 772	//(internal1_m661_tx) tx - время накопленное сек
#define internal1_m661_y0	 BUFFER[2645]	//(internal1_m661_y0) y0
#define idinternal1_m661_y0	 773	//(internal1_m661_y0) y0
#define internal1_m206_Out10	 BUFFER[2646]	//(internal1_m206_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m206_Out10	 774	//(internal1_m206_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m223_Out10	 BUFFER[2648]	//(internal1_m223_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m223_Out10	 775	//(internal1_m223_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m41_Out10	 BUFFER[2650]	//(internal1_m41_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m41_Out10	 776	//(internal1_m41_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m56_Out10	 BUFFER[2652]	//(internal1_m56_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m56_Out10	 777	//(internal1_m56_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1258_Out10	 BUFFER[2654]	//(internal1_m1258_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1258_Out10	 778	//(internal1_m1258_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1255_Out10	 BUFFER[2656]	//(internal1_m1255_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1255_Out10	 779	//(internal1_m1255_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1254_Out10	 BUFFER[2658]	//(internal1_m1254_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1254_Out10	 780	//(internal1_m1254_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1257_Xtek0	 BUFFER[2660]	//(internal1_m1257_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m1257_Xtek0	 781	//(internal1_m1257_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m1243_Xtek0	 BUFFER[2665]	//(internal1_m1243_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m1243_Xtek0	 782	//(internal1_m1243_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m1244_Out10	 BUFFER[2670]	//(internal1_m1244_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1244_Out10	 783	//(internal1_m1244_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1241_Out10	 BUFFER[2672]	//(internal1_m1241_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1241_Out10	 784	//(internal1_m1241_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1240_Out10	 BUFFER[2674]	//(internal1_m1240_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1240_Out10	 785	//(internal1_m1240_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m965_Out10	 BUFFER[2676]	//(internal1_m965_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m965_Out10	 786	//(internal1_m965_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m986_Out10	 BUFFER[2678]	//(internal1_m986_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m986_Out10	 787	//(internal1_m986_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m985_Out10	 BUFFER[2680]	//(internal1_m985_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m985_Out10	 788	//(internal1_m985_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m984_Out10	 BUFFER[2682]	//(internal1_m984_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m984_Out10	 789	//(internal1_m984_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1150_Out10	 BUFFER[2684]	//(internal1_m1150_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1150_Out10	 790	//(internal1_m1150_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1152_Out10	 BUFFER[2686]	//(internal1_m1152_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1152_Out10	 791	//(internal1_m1152_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1149_Out10	 BUFFER[2688]	//(internal1_m1149_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1149_Out10	 792	//(internal1_m1149_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1151_Out10	 BUFFER[2690]	//(internal1_m1151_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1151_Out10	 793	//(internal1_m1151_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1129_Out10	 BUFFER[2692]	//(internal1_m1129_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1129_Out10	 794	//(internal1_m1129_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1130_Out10	 BUFFER[2694]	//(internal1_m1130_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1130_Out10	 795	//(internal1_m1130_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1128_Out10	 BUFFER[2696]	//(internal1_m1128_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1128_Out10	 796	//(internal1_m1128_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1127_Out10	 BUFFER[2698]	//(internal1_m1127_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1127_Out10	 797	//(internal1_m1127_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m962_Out10	 BUFFER[2700]	//(internal1_m962_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m962_Out10	 798	//(internal1_m962_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m961_Out10	 BUFFER[2702]	//(internal1_m961_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m961_Out10	 799	//(internal1_m961_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m941_Out10	 BUFFER[2704]	//(internal1_m941_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m941_Out10	 800	//(internal1_m941_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m945_Out10	 BUFFER[2706]	//(internal1_m945_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m945_Out10	 801	//(internal1_m945_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m944_Out10	 BUFFER[2708]	//(internal1_m944_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m944_Out10	 802	//(internal1_m944_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m943_Out10	 BUFFER[2710]	//(internal1_m943_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m943_Out10	 803	//(internal1_m943_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m942_Out10	 BUFFER[2712]	//(internal1_m942_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m942_Out10	 804	//(internal1_m942_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m963_Out10	 BUFFER[2714]	//(internal1_m963_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m963_Out10	 805	//(internal1_m963_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m982_Out10	 BUFFER[2716]	//(internal1_m982_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m982_Out10	 806	//(internal1_m982_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1131_Out10	 BUFFER[2718]	//(internal1_m1131_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1131_Out10	 807	//(internal1_m1131_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m983_Out10	 BUFFER[2720]	//(internal1_m983_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m983_Out10	 808	//(internal1_m983_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m981_Out10	 BUFFER[2722]	//(internal1_m981_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m981_Out10	 809	//(internal1_m981_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m964_Out10	 BUFFER[2724]	//(internal1_m964_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m964_Out10	 810	//(internal1_m964_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m980_Out10	 BUFFER[2726]	//(internal1_m980_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m980_Out10	 811	//(internal1_m980_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m960_Out10	 BUFFER[2728]	//(internal1_m960_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m960_Out10	 812	//(internal1_m960_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m940_Out10	 BUFFER[2730]	//(internal1_m940_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m940_Out10	 813	//(internal1_m940_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m580_Out10	 BUFFER[2732]	//(internal1_m580_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m580_Out10	 814	//(internal1_m580_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m427_Xtek0	 BUFFER[2734]	//(internal1_m427_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m427_Xtek0	 815	//(internal1_m427_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m418_Out10	 BUFFER[2739]	//(internal1_m418_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m418_Out10	 816	//(internal1_m418_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m420_Out10	 BUFFER[2741]	//(internal1_m420_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m420_Out10	 817	//(internal1_m420_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m419_Out10	 BUFFER[2743]	//(internal1_m419_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m419_Out10	 818	//(internal1_m419_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1164_Out10	 BUFFER[2745]	//(internal1_m1164_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1164_Out10	 819	//(internal1_m1164_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1165_Out10	 BUFFER[2747]	//(internal1_m1165_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1165_Out10	 820	//(internal1_m1165_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1163_Out10	 BUFFER[2749]	//(internal1_m1163_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1163_Out10	 821	//(internal1_m1163_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1001_Out10	 BUFFER[2751]	//(internal1_m1001_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1001_Out10	 822	//(internal1_m1001_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1166_Out10	 BUFFER[2753]	//(internal1_m1166_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1166_Out10	 823	//(internal1_m1166_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m999_Out10	 BUFFER[2755]	//(internal1_m999_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m999_Out10	 824	//(internal1_m999_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m998_Out10	 BUFFER[2757]	//(internal1_m998_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m998_Out10	 825	//(internal1_m998_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1000_Out10	 BUFFER[2759]	//(internal1_m1000_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1000_Out10	 826	//(internal1_m1000_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m603_Out10	 BUFFER[2761]	//(internal1_m603_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m603_Out10	 827	//(internal1_m603_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m601_Out10	 BUFFER[2763]	//(internal1_m601_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m601_Out10	 828	//(internal1_m601_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m600_Out10	 BUFFER[2765]	//(internal1_m600_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m600_Out10	 829	//(internal1_m600_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m602_Out10	 BUFFER[2767]	//(internal1_m602_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m602_Out10	 830	//(internal1_m602_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1146_Xtek0	 BUFFER[2769]	//(internal1_m1146_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m1146_Xtek0	 831	//(internal1_m1146_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m1148_Xtek0	 BUFFER[2774]	//(internal1_m1148_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m1148_Xtek0	 832	//(internal1_m1148_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m722_Out10	 BUFFER[2779]	//(internal1_m722_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m722_Out10	 833	//(internal1_m722_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m717_Out10	 BUFFER[2781]	//(internal1_m717_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m717_Out10	 834	//(internal1_m717_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m708_Out10	 BUFFER[2783]	//(internal1_m708_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m708_Out10	 835	//(internal1_m708_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m716_Out10	 BUFFER[2785]	//(internal1_m716_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m716_Out10	 836	//(internal1_m716_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m707_Out10	 BUFFER[2787]	//(internal1_m707_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m707_Out10	 837	//(internal1_m707_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m343_Out10	 BUFFER[2789]	//(internal1_m343_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m343_Out10	 838	//(internal1_m343_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m342_Out10	 BUFFER[2791]	//(internal1_m342_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m342_Out10	 839	//(internal1_m342_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m323_Out10	 BUFFER[2793]	//(internal1_m323_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m323_Out10	 840	//(internal1_m323_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m322_Out10	 BUFFER[2795]	//(internal1_m322_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m322_Out10	 841	//(internal1_m322_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m604_Out10	 BUFFER[2797]	//(internal1_m604_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m604_Out10	 842	//(internal1_m604_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m358_Out10	 BUFFER[2799]	//(internal1_m358_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m358_Out10	 843	//(internal1_m358_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m340_Xtek0	 BUFFER[2801]	//(internal1_m340_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m340_Xtek0	 844	//(internal1_m340_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m357_Out10	 BUFFER[2806]	//(internal1_m357_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m357_Out10	 845	//(internal1_m357_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m355_Out10	 BUFFER[2808]	//(internal1_m355_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m355_Out10	 846	//(internal1_m355_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m330_Xtek0	 BUFFER[2810]	//(internal1_m330_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m330_Xtek0	 847	//(internal1_m330_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m356_Out10	 BUFFER[2815]	//(internal1_m356_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m356_Out10	 848	//(internal1_m356_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m321_Out10	 BUFFER[2817]	//(internal1_m321_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m321_Out10	 849	//(internal1_m321_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m341_Out10	 BUFFER[2819]	//(internal1_m341_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m341_Out10	 850	//(internal1_m341_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m439_Out10	 BUFFER[2821]	//(internal1_m439_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m439_Out10	 851	//(internal1_m439_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m440_Xtek0	 BUFFER[2823]	//(internal1_m440_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m440_Xtek0	 852	//(internal1_m440_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m438_Out10	 BUFFER[2828]	//(internal1_m438_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m438_Out10	 853	//(internal1_m438_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m437_Out10	 BUFFER[2830]	//(internal1_m437_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m437_Out10	 854	//(internal1_m437_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m436_Out10	 BUFFER[2832]	//(internal1_m436_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m436_Out10	 855	//(internal1_m436_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m946_Out10	 BUFFER[2834]	//(internal1_m946_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m946_Out10	 856	//(internal1_m946_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m150_Out10	 BUFFER[2836]	//(internal1_m150_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m150_Out10	 857	//(internal1_m150_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m149_Out10	 BUFFER[2838]	//(internal1_m149_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m149_Out10	 858	//(internal1_m149_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1119_Out10	 BUFFER[2840]	//(internal1_m1119_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1119_Out10	 859	//(internal1_m1119_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1110_Out10	 BUFFER[2842]	//(internal1_m1110_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1110_Out10	 860	//(internal1_m1110_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1099_tst	 BUFFER[2844]	//(internal1_m1099_tst) - массив времени фиксации стартовой мощности
#define idinternal1_m1099_tst	 861	//(internal1_m1099_tst) - массив времени фиксации стартовой мощности
#define internal1_m1099_trz	 BUFFER[2854]	//(internal1_m1099_trz) - массив времени фиксации очередного периода
#define idinternal1_m1099_trz	 862	//(internal1_m1099_trz) - массив времени фиксации очередного периода
#define internal1_m1099_N1	 BUFFER[2864]	//(internal1_m1099_N1) - массив значения мощности в начале замера
#define idinternal1_m1099_N1	 863	//(internal1_m1099_N1) - массив значения мощности в начале замера
#define internal1_m1099_N2	 BUFFER[2874]	//(internal1_m1099_N2) - массив значения мощности в конце замера
#define idinternal1_m1099_N2	 864	//(internal1_m1099_N2) - массив значения мощности в конце замера
#define internal1_m1099_Period0	 BUFFER[2884]	//(internal1_m1099_Period0) Per - Период разгона РУ
#define idinternal1_m1099_Period0	 865	//(internal1_m1099_Period0) Per - Период разгона РУ
#define internal1_m1099_MyFirstEnterFlag	 BUFFER[2889]	//(internal1_m1099_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m1099_MyFirstEnterFlag	 866	//(internal1_m1099_MyFirstEnterFlag)  FirstEnterFlag
#define internal1_m1065_Nk	 BUFFER[2891]	//(internal1_m1065_Nk) Nk - ведущая камера
#define idinternal1_m1065_Nk	 867	//(internal1_m1065_Nk) Nk - ведущая камера
#define internal1_m1060_Out10	 BUFFER[2894]	//(internal1_m1060_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1060_Out10	 868	//(internal1_m1060_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1052_Out10	 BUFFER[2896]	//(internal1_m1052_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1052_Out10	 869	//(internal1_m1052_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1041_tst	 BUFFER[2898]	//(internal1_m1041_tst) - массив времени фиксации стартовой мощности
#define idinternal1_m1041_tst	 870	//(internal1_m1041_tst) - массив времени фиксации стартовой мощности
#define internal1_m1041_trz	 BUFFER[2908]	//(internal1_m1041_trz) - массив времени фиксации очередного периода
#define idinternal1_m1041_trz	 871	//(internal1_m1041_trz) - массив времени фиксации очередного периода
#define internal1_m1041_N1	 BUFFER[2918]	//(internal1_m1041_N1) - массив значения мощности в начале замера
#define idinternal1_m1041_N1	 872	//(internal1_m1041_N1) - массив значения мощности в начале замера
#define internal1_m1041_N2	 BUFFER[2928]	//(internal1_m1041_N2) - массив значения мощности в конце замера
#define idinternal1_m1041_N2	 873	//(internal1_m1041_N2) - массив значения мощности в конце замера
#define internal1_m1041_Period0	 BUFFER[2938]	//(internal1_m1041_Period0) Per - Период разгона РУ
#define idinternal1_m1041_Period0	 874	//(internal1_m1041_Period0) Per - Период разгона РУ
#define internal1_m1041_MyFirstEnterFlag	 BUFFER[2943]	//(internal1_m1041_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m1041_MyFirstEnterFlag	 875	//(internal1_m1041_MyFirstEnterFlag)  FirstEnterFlag
#define internal1_m1011_Nk	 BUFFER[2945]	//(internal1_m1011_Nk) Nk - ведущая камера
#define idinternal1_m1011_Nk	 876	//(internal1_m1011_Nk) Nk - ведущая камера
#define internal1_m929_Out10	 BUFFER[2948]	//(internal1_m929_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m929_Out10	 877	//(internal1_m929_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m919_Out10	 BUFFER[2950]	//(internal1_m919_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m919_Out10	 878	//(internal1_m919_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m910_tst	 BUFFER[2952]	//(internal1_m910_tst) - массив времени фиксации стартовой мощности
#define idinternal1_m910_tst	 879	//(internal1_m910_tst) - массив времени фиксации стартовой мощности
#define internal1_m910_trz	 BUFFER[2962]	//(internal1_m910_trz) - массив времени фиксации очередного периода
#define idinternal1_m910_trz	 880	//(internal1_m910_trz) - массив времени фиксации очередного периода
#define internal1_m910_N1	 BUFFER[2972]	//(internal1_m910_N1) - массив значения мощности в начале замера
#define idinternal1_m910_N1	 881	//(internal1_m910_N1) - массив значения мощности в начале замера
#define internal1_m910_N2	 BUFFER[2982]	//(internal1_m910_N2) - массив значения мощности в конце замера
#define idinternal1_m910_N2	 882	//(internal1_m910_N2) - массив значения мощности в конце замера
#define internal1_m910_Period0	 BUFFER[2992]	//(internal1_m910_Period0) Per - Период разгона РУ
#define idinternal1_m910_Period0	 883	//(internal1_m910_Period0) Per - Период разгона РУ
#define internal1_m910_MyFirstEnterFlag	 BUFFER[2997]	//(internal1_m910_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m910_MyFirstEnterFlag	 884	//(internal1_m910_MyFirstEnterFlag)  FirstEnterFlag
#define internal1_m876_Nk	 BUFFER[2999]	//(internal1_m876_Nk) Nk - ведущая камера
#define idinternal1_m876_Nk	 885	//(internal1_m876_Nk) Nk - ведущая камера
#define internal1_m863_Out10	 BUFFER[3002]	//(internal1_m863_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m863_Out10	 886	//(internal1_m863_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m852_Out10	 BUFFER[3004]	//(internal1_m852_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m852_Out10	 887	//(internal1_m852_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m855_tst	 BUFFER[3006]	//(internal1_m855_tst) - массив времени фиксации стартовой мощности
#define idinternal1_m855_tst	 888	//(internal1_m855_tst) - массив времени фиксации стартовой мощности
#define internal1_m855_trz	 BUFFER[3016]	//(internal1_m855_trz) - массив времени фиксации очередного периода
#define idinternal1_m855_trz	 889	//(internal1_m855_trz) - массив времени фиксации очередного периода
#define internal1_m855_N1	 BUFFER[3026]	//(internal1_m855_N1) - массив значения мощности в начале замера
#define idinternal1_m855_N1	 890	//(internal1_m855_N1) - массив значения мощности в начале замера
#define internal1_m855_N2	 BUFFER[3036]	//(internal1_m855_N2) - массив значения мощности в конце замера
#define idinternal1_m855_N2	 891	//(internal1_m855_N2) - массив значения мощности в конце замера
#define internal1_m855_Period0	 BUFFER[3046]	//(internal1_m855_Period0) Per - Период разгона РУ
#define idinternal1_m855_Period0	 892	//(internal1_m855_Period0) Per - Период разгона РУ
#define internal1_m855_MyFirstEnterFlag	 BUFFER[3051]	//(internal1_m855_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m855_MyFirstEnterFlag	 893	//(internal1_m855_MyFirstEnterFlag)  FirstEnterFlag
#define internal1_m818_Nk	 BUFFER[3053]	//(internal1_m818_Nk) Nk - ведущая камера
#define idinternal1_m818_Nk	 894	//(internal1_m818_Nk) Nk - ведущая камера
#define internal1_m195_tx	 BUFFER[3056]	//(internal1_m195_tx) tx - внутренний параметр
#define idinternal1_m195_tx	 895	//(internal1_m195_tx) tx - внутренний параметр
#define internal1_m25_tx	 BUFFER[3059]	//(internal1_m25_tx) tx - внутренний параметр
#define idinternal1_m25_tx	 896	//(internal1_m25_tx) tx - внутренний параметр
#define internal1_m499_Pav0	 BUFFER[3062]	//(internal1_m499_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m499_Pav0	 897	//(internal1_m499_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m499_Zav0	 BUFFER[3064]	//(internal1_m499_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m499_Zav0	 898	//(internal1_m499_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m499_Pv0	 BUFFER[3066]	//(internal1_m499_Pv0)  - Пер. выключатель механизма
#define idinternal1_m499_Pv0	 899	//(internal1_m499_Pv0)  - Пер. выключатель механизма
#define internal1_m499_Zv0	 BUFFER[3068]	//(internal1_m499_Zv0)  - Зад. выключатель механизма
#define idinternal1_m499_Zv0	 900	//(internal1_m499_Zv0)  - Зад. выключатель механизма
#define internal1_m499_RA00	 BUFFER[3070]	//(internal1_m499_RA00)  - последнее задание вперед
#define idinternal1_m499_RA00	 901	//(internal1_m499_RA00)  - последнее задание вперед
#define internal1_m499_RA10	 BUFFER[3072]	//(internal1_m499_RA10)  - последнее задание назад
#define idinternal1_m499_RA10	 902	//(internal1_m499_RA10)  - последнее задание назад
#define internal1_m499_MyFirstEnterFlag	 BUFFER[3074]	//(internal1_m499_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m499_MyFirstEnterFlag	 903	//(internal1_m499_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m526_Pav0	 BUFFER[3076]	//(internal1_m526_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m526_Pav0	 904	//(internal1_m526_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m526_Zav0	 BUFFER[3078]	//(internal1_m526_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m526_Zav0	 905	//(internal1_m526_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m526_Pv0	 BUFFER[3080]	//(internal1_m526_Pv0)  - Пер. выключатель механизма
#define idinternal1_m526_Pv0	 906	//(internal1_m526_Pv0)  - Пер. выключатель механизма
#define internal1_m526_Zv0	 BUFFER[3082]	//(internal1_m526_Zv0)  - Зад. выключатель механизма
#define idinternal1_m526_Zv0	 907	//(internal1_m526_Zv0)  - Зад. выключатель механизма
#define internal1_m526_RA00	 BUFFER[3084]	//(internal1_m526_RA00)  - последнее задание вперед
#define idinternal1_m526_RA00	 908	//(internal1_m526_RA00)  - последнее задание вперед
#define internal1_m526_RA10	 BUFFER[3086]	//(internal1_m526_RA10)  - последнее задание назад
#define idinternal1_m526_RA10	 909	//(internal1_m526_RA10)  - последнее задание назад
#define internal1_m526_MyFirstEnterFlag	 BUFFER[3088]	//(internal1_m526_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m526_MyFirstEnterFlag	 910	//(internal1_m526_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m522_Pav0	 BUFFER[3090]	//(internal1_m522_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m522_Pav0	 911	//(internal1_m522_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m522_Zav0	 BUFFER[3092]	//(internal1_m522_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m522_Zav0	 912	//(internal1_m522_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m522_Pv0	 BUFFER[3094]	//(internal1_m522_Pv0)  - Пер. выключатель механизма
#define idinternal1_m522_Pv0	 913	//(internal1_m522_Pv0)  - Пер. выключатель механизма
#define internal1_m522_Zv0	 BUFFER[3096]	//(internal1_m522_Zv0)  - Зад. выключатель механизма
#define idinternal1_m522_Zv0	 914	//(internal1_m522_Zv0)  - Зад. выключатель механизма
#define internal1_m522_RA00	 BUFFER[3098]	//(internal1_m522_RA00)  - последнее задание вперед
#define idinternal1_m522_RA00	 915	//(internal1_m522_RA00)  - последнее задание вперед
#define internal1_m522_RA10	 BUFFER[3100]	//(internal1_m522_RA10)  - последнее задание назад
#define idinternal1_m522_RA10	 916	//(internal1_m522_RA10)  - последнее задание назад
#define internal1_m522_MyFirstEnterFlag	 BUFFER[3102]	//(internal1_m522_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m522_MyFirstEnterFlag	 917	//(internal1_m522_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m494_Pav0	 BUFFER[3104]	//(internal1_m494_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m494_Pav0	 918	//(internal1_m494_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m494_Zav0	 BUFFER[3106]	//(internal1_m494_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m494_Zav0	 919	//(internal1_m494_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m494_Pv0	 BUFFER[3108]	//(internal1_m494_Pv0)  - Пер. выключатель механизма
#define idinternal1_m494_Pv0	 920	//(internal1_m494_Pv0)  - Пер. выключатель механизма
#define internal1_m494_Zv0	 BUFFER[3110]	//(internal1_m494_Zv0)  - Зад. выключатель механизма
#define idinternal1_m494_Zv0	 921	//(internal1_m494_Zv0)  - Зад. выключатель механизма
#define internal1_m494_RA00	 BUFFER[3112]	//(internal1_m494_RA00)  - последнее задание вперед
#define idinternal1_m494_RA00	 922	//(internal1_m494_RA00)  - последнее задание вперед
#define internal1_m494_RA10	 BUFFER[3114]	//(internal1_m494_RA10)  - последнее задание назад
#define idinternal1_m494_RA10	 923	//(internal1_m494_RA10)  - последнее задание назад
#define internal1_m494_MyFirstEnterFlag	 BUFFER[3116]	//(internal1_m494_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m494_MyFirstEnterFlag	 924	//(internal1_m494_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m666_Pav0	 BUFFER[3118]	//(internal1_m666_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m666_Pav0	 925	//(internal1_m666_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m666_Zav0	 BUFFER[3120]	//(internal1_m666_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m666_Zav0	 926	//(internal1_m666_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m666_Pv0	 BUFFER[3122]	//(internal1_m666_Pv0)  - Пер. выключатель механизма
#define idinternal1_m666_Pv0	 927	//(internal1_m666_Pv0)  - Пер. выключатель механизма
#define internal1_m666_Zv0	 BUFFER[3124]	//(internal1_m666_Zv0)  - Зад. выключатель механизма
#define idinternal1_m666_Zv0	 928	//(internal1_m666_Zv0)  - Зад. выключатель механизма
#define internal1_m666_RA00	 BUFFER[3126]	//(internal1_m666_RA00)  - последнее задание вперед
#define idinternal1_m666_RA00	 929	//(internal1_m666_RA00)  - последнее задание вперед
#define internal1_m666_RA10	 BUFFER[3128]	//(internal1_m666_RA10)  - последнее задание назад
#define idinternal1_m666_RA10	 930	//(internal1_m666_RA10)  - последнее задание назад
#define internal1_m666_MyFirstEnterFlag	 BUFFER[3130]	//(internal1_m666_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m666_MyFirstEnterFlag	 931	//(internal1_m666_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m665_Pav0	 BUFFER[3132]	//(internal1_m665_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m665_Pav0	 932	//(internal1_m665_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m665_Zav0	 BUFFER[3134]	//(internal1_m665_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m665_Zav0	 933	//(internal1_m665_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m665_Pv0	 BUFFER[3136]	//(internal1_m665_Pv0)  - Пер. выключатель механизма
#define idinternal1_m665_Pv0	 934	//(internal1_m665_Pv0)  - Пер. выключатель механизма
#define internal1_m665_Zv0	 BUFFER[3138]	//(internal1_m665_Zv0)  - Зад. выключатель механизма
#define idinternal1_m665_Zv0	 935	//(internal1_m665_Zv0)  - Зад. выключатель механизма
#define internal1_m665_RA00	 BUFFER[3140]	//(internal1_m665_RA00)  - последнее задание вперед
#define idinternal1_m665_RA00	 936	//(internal1_m665_RA00)  - последнее задание вперед
#define internal1_m665_RA10	 BUFFER[3142]	//(internal1_m665_RA10)  - последнее задание назад
#define idinternal1_m665_RA10	 937	//(internal1_m665_RA10)  - последнее задание назад
#define internal1_m665_MyFirstEnterFlag	 BUFFER[3144]	//(internal1_m665_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m665_MyFirstEnterFlag	 938	//(internal1_m665_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m651_Pav0	 BUFFER[3146]	//(internal1_m651_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m651_Pav0	 939	//(internal1_m651_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m651_Zav0	 BUFFER[3148]	//(internal1_m651_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m651_Zav0	 940	//(internal1_m651_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m651_Pv0	 BUFFER[3150]	//(internal1_m651_Pv0)  - Пер. выключатель механизма
#define idinternal1_m651_Pv0	 941	//(internal1_m651_Pv0)  - Пер. выключатель механизма
#define internal1_m651_Zv0	 BUFFER[3152]	//(internal1_m651_Zv0)  - Зад. выключатель механизма
#define idinternal1_m651_Zv0	 942	//(internal1_m651_Zv0)  - Зад. выключатель механизма
#define internal1_m651_RA00	 BUFFER[3154]	//(internal1_m651_RA00)  - последнее задание вперед
#define idinternal1_m651_RA00	 943	//(internal1_m651_RA00)  - последнее задание вперед
#define internal1_m651_RA10	 BUFFER[3156]	//(internal1_m651_RA10)  - последнее задание назад
#define idinternal1_m651_RA10	 944	//(internal1_m651_RA10)  - последнее задание назад
#define internal1_m651_MyFirstEnterFlag	 BUFFER[3158]	//(internal1_m651_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m651_MyFirstEnterFlag	 945	//(internal1_m651_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m650_Pav0	 BUFFER[3160]	//(internal1_m650_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m650_Pav0	 946	//(internal1_m650_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m650_Zav0	 BUFFER[3162]	//(internal1_m650_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m650_Zav0	 947	//(internal1_m650_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m650_Pv0	 BUFFER[3164]	//(internal1_m650_Pv0)  - Пер. выключатель механизма
#define idinternal1_m650_Pv0	 948	//(internal1_m650_Pv0)  - Пер. выключатель механизма
#define internal1_m650_Zv0	 BUFFER[3166]	//(internal1_m650_Zv0)  - Зад. выключатель механизма
#define idinternal1_m650_Zv0	 949	//(internal1_m650_Zv0)  - Зад. выключатель механизма
#define internal1_m650_RA00	 BUFFER[3168]	//(internal1_m650_RA00)  - последнее задание вперед
#define idinternal1_m650_RA00	 950	//(internal1_m650_RA00)  - последнее задание вперед
#define internal1_m650_RA10	 BUFFER[3170]	//(internal1_m650_RA10)  - последнее задание назад
#define idinternal1_m650_RA10	 951	//(internal1_m650_RA10)  - последнее задание назад
#define internal1_m650_MyFirstEnterFlag	 BUFFER[3172]	//(internal1_m650_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m650_MyFirstEnterFlag	 952	//(internal1_m650_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m697_y0	 BUFFER[3174]	//(internal1_m697_y0) y0 - внутренний параметр
#define idinternal1_m697_y0	 953	//(internal1_m697_y0) y0 - внутренний параметр
#define internal1_m812_Chim0	 BUFFER[3179]	//(internal1_m812_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m812_Chim0	 954	//(internal1_m812_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m804_Chim0	 BUFFER[3184]	//(internal1_m804_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m804_Chim0	 955	//(internal1_m804_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m797_Chim0	 BUFFER[3189]	//(internal1_m797_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m797_Chim0	 956	//(internal1_m797_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m789_Chim0	 BUFFER[3194]	//(internal1_m789_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m789_Chim0	 957	//(internal1_m789_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m781_Chim0	 BUFFER[3199]	//(internal1_m781_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m781_Chim0	 958	//(internal1_m781_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m774_Chim0	 BUFFER[3204]	//(internal1_m774_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m774_Chim0	 959	//(internal1_m774_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m766_Chim0	 BUFFER[3209]	//(internal1_m766_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m766_Chim0	 960	//(internal1_m766_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m758_Chim0	 BUFFER[3214]	//(internal1_m758_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m758_Chim0	 961	//(internal1_m758_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m751_Chim0	 BUFFER[3219]	//(internal1_m751_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m751_Chim0	 962	//(internal1_m751_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m743_Chim0	 BUFFER[3224]	//(internal1_m743_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m743_Chim0	 963	//(internal1_m743_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m735_Chim0	 BUFFER[3229]	//(internal1_m735_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m735_Chim0	 964	//(internal1_m735_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m728_Chim0	 BUFFER[3234]	//(internal1_m728_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m728_Chim0	 965	//(internal1_m728_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m637_Pav0	 BUFFER[3239]	//(internal1_m637_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m637_Pav0	 966	//(internal1_m637_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m637_Zav0	 BUFFER[3241]	//(internal1_m637_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m637_Zav0	 967	//(internal1_m637_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m637_Pv0	 BUFFER[3243]	//(internal1_m637_Pv0)  - Пер. выключатель механизма
#define idinternal1_m637_Pv0	 968	//(internal1_m637_Pv0)  - Пер. выключатель механизма
#define internal1_m637_Zv0	 BUFFER[3245]	//(internal1_m637_Zv0)  - Зад. выключатель механизма
#define idinternal1_m637_Zv0	 969	//(internal1_m637_Zv0)  - Зад. выключатель механизма
#define internal1_m637_RA00	 BUFFER[3247]	//(internal1_m637_RA00)  - последнее задание вперед
#define idinternal1_m637_RA00	 970	//(internal1_m637_RA00)  - последнее задание вперед
#define internal1_m637_RA10	 BUFFER[3249]	//(internal1_m637_RA10)  - последнее задание назад
#define idinternal1_m637_RA10	 971	//(internal1_m637_RA10)  - последнее задание назад
#define internal1_m637_MyFirstEnterFlag	 BUFFER[3251]	//(internal1_m637_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m637_MyFirstEnterFlag	 972	//(internal1_m637_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m622_Pav0	 BUFFER[3253]	//(internal1_m622_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m622_Pav0	 973	//(internal1_m622_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m622_Zav0	 BUFFER[3255]	//(internal1_m622_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m622_Zav0	 974	//(internal1_m622_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m622_Pv0	 BUFFER[3257]	//(internal1_m622_Pv0)  - Пер. выключатель механизма
#define idinternal1_m622_Pv0	 975	//(internal1_m622_Pv0)  - Пер. выключатель механизма
#define internal1_m622_Zv0	 BUFFER[3259]	//(internal1_m622_Zv0)  - Зад. выключатель механизма
#define idinternal1_m622_Zv0	 976	//(internal1_m622_Zv0)  - Зад. выключатель механизма
#define internal1_m622_RA00	 BUFFER[3261]	//(internal1_m622_RA00)  - последнее задание вперед
#define idinternal1_m622_RA00	 977	//(internal1_m622_RA00)  - последнее задание вперед
#define internal1_m622_RA10	 BUFFER[3263]	//(internal1_m622_RA10)  - последнее задание назад
#define idinternal1_m622_RA10	 978	//(internal1_m622_RA10)  - последнее задание назад
#define internal1_m622_MyFirstEnterFlag	 BUFFER[3265]	//(internal1_m622_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m622_MyFirstEnterFlag	 979	//(internal1_m622_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m469_Pav0	 BUFFER[3267]	//(internal1_m469_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m469_Pav0	 980	//(internal1_m469_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m469_Zav0	 BUFFER[3269]	//(internal1_m469_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m469_Zav0	 981	//(internal1_m469_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m469_Pv0	 BUFFER[3271]	//(internal1_m469_Pv0)  - Пер. выключатель механизма
#define idinternal1_m469_Pv0	 982	//(internal1_m469_Pv0)  - Пер. выключатель механизма
#define internal1_m469_Zv0	 BUFFER[3273]	//(internal1_m469_Zv0)  - Зад. выключатель механизма
#define idinternal1_m469_Zv0	 983	//(internal1_m469_Zv0)  - Зад. выключатель механизма
#define internal1_m469_RA00	 BUFFER[3275]	//(internal1_m469_RA00)  - последнее задание вперед
#define idinternal1_m469_RA00	 984	//(internal1_m469_RA00)  - последнее задание вперед
#define internal1_m469_RA10	 BUFFER[3277]	//(internal1_m469_RA10)  - последнее задание назад
#define idinternal1_m469_RA10	 985	//(internal1_m469_RA10)  - последнее задание назад
#define internal1_m469_MyFirstEnterFlag	 BUFFER[3279]	//(internal1_m469_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m469_MyFirstEnterFlag	 986	//(internal1_m469_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m454_Pav0	 BUFFER[3281]	//(internal1_m454_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m454_Pav0	 987	//(internal1_m454_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m454_Zav0	 BUFFER[3283]	//(internal1_m454_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m454_Zav0	 988	//(internal1_m454_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m454_Pv0	 BUFFER[3285]	//(internal1_m454_Pv0)  - Пер. выключатель механизма
#define idinternal1_m454_Pv0	 989	//(internal1_m454_Pv0)  - Пер. выключатель механизма
#define internal1_m454_Zv0	 BUFFER[3287]	//(internal1_m454_Zv0)  - Зад. выключатель механизма
#define idinternal1_m454_Zv0	 990	//(internal1_m454_Zv0)  - Зад. выключатель механизма
#define internal1_m454_RA00	 BUFFER[3289]	//(internal1_m454_RA00)  - последнее задание вперед
#define idinternal1_m454_RA00	 991	//(internal1_m454_RA00)  - последнее задание вперед
#define internal1_m454_RA10	 BUFFER[3291]	//(internal1_m454_RA10)  - последнее задание назад
#define idinternal1_m454_RA10	 992	//(internal1_m454_RA10)  - последнее задание назад
#define internal1_m454_MyFirstEnterFlag	 BUFFER[3293]	//(internal1_m454_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m454_MyFirstEnterFlag	 993	//(internal1_m454_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m538_Pav0	 BUFFER[3295]	//(internal1_m538_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m538_Pav0	 994	//(internal1_m538_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m538_Zav0	 BUFFER[3297]	//(internal1_m538_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m538_Zav0	 995	//(internal1_m538_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m538_Pv0	 BUFFER[3299]	//(internal1_m538_Pv0)  - Пер. выключатель механизма
#define idinternal1_m538_Pv0	 996	//(internal1_m538_Pv0)  - Пер. выключатель механизма
#define internal1_m538_Zv0	 BUFFER[3301]	//(internal1_m538_Zv0)  - Зад. выключатель механизма
#define idinternal1_m538_Zv0	 997	//(internal1_m538_Zv0)  - Зад. выключатель механизма
#define internal1_m538_RA00	 BUFFER[3303]	//(internal1_m538_RA00)  - последнее задание вперед
#define idinternal1_m538_RA00	 998	//(internal1_m538_RA00)  - последнее задание вперед
#define internal1_m538_RA10	 BUFFER[3305]	//(internal1_m538_RA10)  - последнее задание назад
#define idinternal1_m538_RA10	 999	//(internal1_m538_RA10)  - последнее задание назад
#define internal1_m538_MyFirstEnterFlag	 BUFFER[3307]	//(internal1_m538_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m538_MyFirstEnterFlag	 1000	//(internal1_m538_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m405_Pav0	 BUFFER[3309]	//(internal1_m405_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m405_Pav0	 1001	//(internal1_m405_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m405_Zav0	 BUFFER[3311]	//(internal1_m405_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m405_Zav0	 1002	//(internal1_m405_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m405_Pv0	 BUFFER[3313]	//(internal1_m405_Pv0)  - Пер. выключатель механизма
#define idinternal1_m405_Pv0	 1003	//(internal1_m405_Pv0)  - Пер. выключатель механизма
#define internal1_m405_Zv0	 BUFFER[3315]	//(internal1_m405_Zv0)  - Зад. выключатель механизма
#define idinternal1_m405_Zv0	 1004	//(internal1_m405_Zv0)  - Зад. выключатель механизма
#define internal1_m405_RA00	 BUFFER[3317]	//(internal1_m405_RA00)  - последнее задание вперед
#define idinternal1_m405_RA00	 1005	//(internal1_m405_RA00)  - последнее задание вперед
#define internal1_m405_RA10	 BUFFER[3319]	//(internal1_m405_RA10)  - последнее задание назад
#define idinternal1_m405_RA10	 1006	//(internal1_m405_RA10)  - последнее задание назад
#define internal1_m405_MyFirstEnterFlag	 BUFFER[3321]	//(internal1_m405_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m405_MyFirstEnterFlag	 1007	//(internal1_m405_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m389_Pav0	 BUFFER[3323]	//(internal1_m389_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m389_Pav0	 1008	//(internal1_m389_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m389_Zav0	 BUFFER[3325]	//(internal1_m389_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m389_Zav0	 1009	//(internal1_m389_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m389_Pv0	 BUFFER[3327]	//(internal1_m389_Pv0)  - Пер. выключатель механизма
#define idinternal1_m389_Pv0	 1010	//(internal1_m389_Pv0)  - Пер. выключатель механизма
#define internal1_m389_Zv0	 BUFFER[3329]	//(internal1_m389_Zv0)  - Зад. выключатель механизма
#define idinternal1_m389_Zv0	 1011	//(internal1_m389_Zv0)  - Зад. выключатель механизма
#define internal1_m389_RA00	 BUFFER[3331]	//(internal1_m389_RA00)  - последнее задание вперед
#define idinternal1_m389_RA00	 1012	//(internal1_m389_RA00)  - последнее задание вперед
#define internal1_m389_RA10	 BUFFER[3333]	//(internal1_m389_RA10)  - последнее задание назад
#define idinternal1_m389_RA10	 1013	//(internal1_m389_RA10)  - последнее задание назад
#define internal1_m389_MyFirstEnterFlag	 BUFFER[3335]	//(internal1_m389_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m389_MyFirstEnterFlag	 1014	//(internal1_m389_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m372_Pav0	 BUFFER[3337]	//(internal1_m372_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m372_Pav0	 1015	//(internal1_m372_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m372_Zav0	 BUFFER[3339]	//(internal1_m372_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m372_Zav0	 1016	//(internal1_m372_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m372_Pv0	 BUFFER[3341]	//(internal1_m372_Pv0)  - Пер. выключатель механизма
#define idinternal1_m372_Pv0	 1017	//(internal1_m372_Pv0)  - Пер. выключатель механизма
#define internal1_m372_Zv0	 BUFFER[3343]	//(internal1_m372_Zv0)  - Зад. выключатель механизма
#define idinternal1_m372_Zv0	 1018	//(internal1_m372_Zv0)  - Зад. выключатель механизма
#define internal1_m372_RA00	 BUFFER[3345]	//(internal1_m372_RA00)  - последнее задание вперед
#define idinternal1_m372_RA00	 1019	//(internal1_m372_RA00)  - последнее задание вперед
#define internal1_m372_RA10	 BUFFER[3347]	//(internal1_m372_RA10)  - последнее задание назад
#define idinternal1_m372_RA10	 1020	//(internal1_m372_RA10)  - последнее задание назад
#define internal1_m372_MyFirstEnterFlag	 BUFFER[3349]	//(internal1_m372_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m372_MyFirstEnterFlag	 1021	//(internal1_m372_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m1179_Pav0	 BUFFER[3351]	//(internal1_m1179_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m1179_Pav0	 1022	//(internal1_m1179_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m1179_Zav0	 BUFFER[3353]	//(internal1_m1179_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m1179_Zav0	 1023	//(internal1_m1179_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m1179_Pv0	 BUFFER[3355]	//(internal1_m1179_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1179_Pv0	 1024	//(internal1_m1179_Pv0)  - Пер. выключатель механизма
#define internal1_m1179_Zv0	 BUFFER[3357]	//(internal1_m1179_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1179_Zv0	 1025	//(internal1_m1179_Zv0)  - Зад. выключатель механизма
#define internal1_m1179_RA00	 BUFFER[3359]	//(internal1_m1179_RA00)  - последнее задание вперед
#define idinternal1_m1179_RA00	 1026	//(internal1_m1179_RA00)  - последнее задание вперед
#define internal1_m1179_RA10	 BUFFER[3361]	//(internal1_m1179_RA10)  - последнее задание назад
#define idinternal1_m1179_RA10	 1027	//(internal1_m1179_RA10)  - последнее задание назад
#define internal1_m1179_MyFirstEnterFlag	 BUFFER[3363]	//(internal1_m1179_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1179_MyFirstEnterFlag	 1028	//(internal1_m1179_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m180_C1	 BUFFER[3365]	//(internal1_m180_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m180_C1	 1029	//(internal1_m180_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m180_C2	 BUFFER[3370]	//(internal1_m180_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m180_C2	 1030	//(internal1_m180_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m180_C3	 BUFFER[3375]	//(internal1_m180_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m180_C3	 1031	//(internal1_m180_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m180_C4	 BUFFER[3380]	//(internal1_m180_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m180_C4	 1032	//(internal1_m180_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m180_C5	 BUFFER[3385]	//(internal1_m180_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m180_C5	 1033	//(internal1_m180_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m180_C6	 BUFFER[3390]	//(internal1_m180_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m180_C6	 1034	//(internal1_m180_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m180_N20	 BUFFER[3395]	//(internal1_m180_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m180_N20	 1035	//(internal1_m180_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m180_C0	 BUFFER[3400]	//(internal1_m180_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define idinternal1_m180_C0	 1036	//(internal1_m180_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define internal1_m180_ImpINI0	 BUFFER[3430]	//(internal1_m180_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m180_ImpINI0	 1037	//(internal1_m180_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m180_MyFirstEnterFlag	 BUFFER[3432]	//(internal1_m180_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m180_MyFirstEnterFlag	 1038	//(internal1_m180_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m298_Ppv0	 BUFFER[3434]	//(internal1_m298_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m298_Ppv0	 1039	//(internal1_m298_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m298_Pav0	 BUFFER[3436]	//(internal1_m298_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m298_Pav0	 1040	//(internal1_m298_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m298_Zav0	 BUFFER[3438]	//(internal1_m298_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m298_Zav0	 1041	//(internal1_m298_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m298_RA00	 BUFFER[3440]	//(internal1_m298_RA00) RA00 - последнее задание вперед
#define idinternal1_m298_RA00	 1042	//(internal1_m298_RA00) RA00 - последнее задание вперед
#define internal1_m298_RA10	 BUFFER[3442]	//(internal1_m298_RA10) RA10 - последнее задание назад
#define idinternal1_m298_RA10	 1043	//(internal1_m298_RA10) RA10 - последнее задание назад
#define internal1_m298_RA50	 BUFFER[3444]	//(internal1_m298_RA50) Ra50 - последнее задание скорости
#define idinternal1_m298_RA50	 1044	//(internal1_m298_RA50) Ra50 - последнее задание скорости
#define internal1_m298_fls	 BUFFER[3445]	//(internal1_m298_fls)  fls - флаг одношагового режима
#define idinternal1_m298_fls	 1045	//(internal1_m298_fls)  fls - флаг одношагового режима
#define internal1_m298_flp	 BUFFER[3447]	//(internal1_m298_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m298_flp	 1046	//(internal1_m298_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m298_MyFirstEnterFlag	 BUFFER[3449]	//(internal1_m298_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m298_MyFirstEnterFlag	 1047	//(internal1_m298_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m131_Ppv0	 BUFFER[3451]	//(internal1_m131_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m131_Ppv0	 1048	//(internal1_m131_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m131_Pav0	 BUFFER[3453]	//(internal1_m131_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m131_Pav0	 1049	//(internal1_m131_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m131_Zav0	 BUFFER[3455]	//(internal1_m131_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m131_Zav0	 1050	//(internal1_m131_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m131_RA00	 BUFFER[3457]	//(internal1_m131_RA00) RA00 - последнее задание вперед
#define idinternal1_m131_RA00	 1051	//(internal1_m131_RA00) RA00 - последнее задание вперед
#define internal1_m131_RA10	 BUFFER[3459]	//(internal1_m131_RA10) RA10 - последнее задание назад
#define idinternal1_m131_RA10	 1052	//(internal1_m131_RA10) RA10 - последнее задание назад
#define internal1_m131_RA50	 BUFFER[3461]	//(internal1_m131_RA50) Ra50 - последнее задание скорости
#define idinternal1_m131_RA50	 1053	//(internal1_m131_RA50) Ra50 - последнее задание скорости
#define internal1_m131_fls	 BUFFER[3462]	//(internal1_m131_fls)  fls - флаг одношагового режима
#define idinternal1_m131_fls	 1054	//(internal1_m131_fls)  fls - флаг одношагового режима
#define internal1_m131_flp	 BUFFER[3464]	//(internal1_m131_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m131_flp	 1055	//(internal1_m131_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m131_MyFirstEnterFlag	 BUFFER[3466]	//(internal1_m131_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m131_MyFirstEnterFlag	 1056	//(internal1_m131_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m265_Ppv0	 BUFFER[3468]	//(internal1_m265_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m265_Ppv0	 1057	//(internal1_m265_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m265_Pav0	 BUFFER[3470]	//(internal1_m265_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m265_Pav0	 1058	//(internal1_m265_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m265_Zav0	 BUFFER[3472]	//(internal1_m265_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m265_Zav0	 1059	//(internal1_m265_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m265_RA00	 BUFFER[3474]	//(internal1_m265_RA00) RA00 - последнее задание вперед
#define idinternal1_m265_RA00	 1060	//(internal1_m265_RA00) RA00 - последнее задание вперед
#define internal1_m265_RA10	 BUFFER[3476]	//(internal1_m265_RA10) RA10 - последнее задание назад
#define idinternal1_m265_RA10	 1061	//(internal1_m265_RA10) RA10 - последнее задание назад
#define internal1_m265_RA50	 BUFFER[3478]	//(internal1_m265_RA50) Ra50 - последнее задание скорости
#define idinternal1_m265_RA50	 1062	//(internal1_m265_RA50) Ra50 - последнее задание скорости
#define internal1_m265_fls	 BUFFER[3479]	//(internal1_m265_fls)  fls - флаг одношагового режима
#define idinternal1_m265_fls	 1063	//(internal1_m265_fls)  fls - флаг одношагового режима
#define internal1_m265_flp	 BUFFER[3481]	//(internal1_m265_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m265_flp	 1064	//(internal1_m265_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m265_MyFirstEnterFlag	 BUFFER[3483]	//(internal1_m265_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m265_MyFirstEnterFlag	 1065	//(internal1_m265_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m99_Ppv0	 BUFFER[3485]	//(internal1_m99_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m99_Ppv0	 1066	//(internal1_m99_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m99_Pav0	 BUFFER[3487]	//(internal1_m99_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m99_Pav0	 1067	//(internal1_m99_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m99_Zav0	 BUFFER[3489]	//(internal1_m99_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m99_Zav0	 1068	//(internal1_m99_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m99_RA00	 BUFFER[3491]	//(internal1_m99_RA00) RA00 - последнее задание вперед
#define idinternal1_m99_RA00	 1069	//(internal1_m99_RA00) RA00 - последнее задание вперед
#define internal1_m99_RA10	 BUFFER[3493]	//(internal1_m99_RA10) RA10 - последнее задание назад
#define idinternal1_m99_RA10	 1070	//(internal1_m99_RA10) RA10 - последнее задание назад
#define internal1_m99_RA50	 BUFFER[3495]	//(internal1_m99_RA50) Ra50 - последнее задание скорости
#define idinternal1_m99_RA50	 1071	//(internal1_m99_RA50) Ra50 - последнее задание скорости
#define internal1_m99_fls	 BUFFER[3496]	//(internal1_m99_fls)  fls - флаг одношагового режима
#define idinternal1_m99_fls	 1072	//(internal1_m99_fls)  fls - флаг одношагового режима
#define internal1_m99_flp	 BUFFER[3498]	//(internal1_m99_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m99_flp	 1073	//(internal1_m99_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m99_MyFirstEnterFlag	 BUFFER[3500]	//(internal1_m99_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m99_MyFirstEnterFlag	 1074	//(internal1_m99_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m227_Ppv0	 BUFFER[3502]	//(internal1_m227_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m227_Ppv0	 1075	//(internal1_m227_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m227_Pav0	 BUFFER[3504]	//(internal1_m227_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m227_Pav0	 1076	//(internal1_m227_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m227_Zav0	 BUFFER[3506]	//(internal1_m227_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m227_Zav0	 1077	//(internal1_m227_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m227_RA00	 BUFFER[3508]	//(internal1_m227_RA00) RA00 - последнее задание вперед
#define idinternal1_m227_RA00	 1078	//(internal1_m227_RA00) RA00 - последнее задание вперед
#define internal1_m227_RA10	 BUFFER[3510]	//(internal1_m227_RA10) RA10 - последнее задание назад
#define idinternal1_m227_RA10	 1079	//(internal1_m227_RA10) RA10 - последнее задание назад
#define internal1_m227_RA50	 BUFFER[3512]	//(internal1_m227_RA50) Ra50 - последнее задание скорости
#define idinternal1_m227_RA50	 1080	//(internal1_m227_RA50) Ra50 - последнее задание скорости
#define internal1_m227_fls	 BUFFER[3513]	//(internal1_m227_fls)  fls - флаг одношагового режима
#define idinternal1_m227_fls	 1081	//(internal1_m227_fls)  fls - флаг одношагового режима
#define internal1_m227_flp	 BUFFER[3515]	//(internal1_m227_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m227_flp	 1082	//(internal1_m227_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m227_MyFirstEnterFlag	 BUFFER[3517]	//(internal1_m227_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m227_MyFirstEnterFlag	 1083	//(internal1_m227_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m60_Ppv0	 BUFFER[3519]	//(internal1_m60_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m60_Ppv0	 1084	//(internal1_m60_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m60_Pav0	 BUFFER[3521]	//(internal1_m60_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m60_Pav0	 1085	//(internal1_m60_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m60_Zav0	 BUFFER[3523]	//(internal1_m60_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m60_Zav0	 1086	//(internal1_m60_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m60_RA00	 BUFFER[3525]	//(internal1_m60_RA00) RA00 - последнее задание вперед
#define idinternal1_m60_RA00	 1087	//(internal1_m60_RA00) RA00 - последнее задание вперед
#define internal1_m60_RA10	 BUFFER[3527]	//(internal1_m60_RA10) RA10 - последнее задание назад
#define idinternal1_m60_RA10	 1088	//(internal1_m60_RA10) RA10 - последнее задание назад
#define internal1_m60_RA50	 BUFFER[3529]	//(internal1_m60_RA50) Ra50 - последнее задание скорости
#define idinternal1_m60_RA50	 1089	//(internal1_m60_RA50) Ra50 - последнее задание скорости
#define internal1_m60_fls	 BUFFER[3530]	//(internal1_m60_fls)  fls - флаг одношагового режима
#define idinternal1_m60_fls	 1090	//(internal1_m60_fls)  fls - флаг одношагового режима
#define internal1_m60_flp	 BUFFER[3532]	//(internal1_m60_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m60_flp	 1091	//(internal1_m60_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m60_MyFirstEnterFlag	 BUFFER[3534]	//(internal1_m60_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m60_MyFirstEnterFlag	 1092	//(internal1_m60_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m14_C1	 BUFFER[3536]	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m14_C1	 1093	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m14_C2	 BUFFER[3541]	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m14_C2	 1094	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m14_C3	 BUFFER[3546]	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m14_C3	 1095	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m14_C4	 BUFFER[3551]	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m14_C4	 1096	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m14_C5	 BUFFER[3556]	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m14_C5	 1097	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m14_C6	 BUFFER[3561]	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m14_C6	 1098	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m14_N20	 BUFFER[3566]	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m14_N20	 1099	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m14_C0	 BUFFER[3571]	//(internal1_m14_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define idinternal1_m14_C0	 1100	//(internal1_m14_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define internal1_m14_ImpINI0	 BUFFER[3601]	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m14_ImpINI0	 1101	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m14_MyFirstEnterFlag	 BUFFER[3603]	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m14_MyFirstEnterFlag	 1102	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &B0VP81LZ2},	//(B0VP81LZ2) Давление  АЗ2  в норме
	{ 2	,1	,1	, &B0VP81LZ1},	//(B0VP81LZ1) Давление  АЗ2  в норме
	{ 3	,1	,1	, &A0VP81LZ2},	//(A0VP81LZ2) Давление  АЗ1  в норме
	{ 4	,1	,1	, &A0VP81LZ1},	//(A0VP81LZ1) Давление  АЗ1  в норме
	{ 5	,1	,1	, &R0VP81LZ2},	//(R0VP81LZ2) Давление  в СИСТЕМЕ-1  в норме
	{ 6	,1	,1	, &R0VP81LZ1},	//(R0VP81LZ1) Давление  в СИСТЕМЕ - 1 в норме
	{ 7	,5	,1	, &B8IC01UDU},	//(B8IC01UDU) Координата АЗ2
	{ 8	,5	,1	, &A8IC01UDU},	//(A8IC01UDU) Координата ДС2
	{ 9	,1	,1	, &R6IS68LZ2},	//(R6IS68LZ2) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 10	,1	,1	, &R6IS68LZ1},	//(R6IS68LZ1) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 11	,1	,1	, &R6IS67LZ2},	//(R6IS67LZ2) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 12	,1	,1	, &R6IS67LZ1},	//(R6IS67LZ1) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 13	,1	,1	, &R6IS66LZ2},	//(R6IS66LZ2) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 14	,1	,1	, &R6IS66LZ1},	//(R6IS66LZ1) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 15	,1	,1	, &R6IS65LDU},	//(R6IS65LDU) Исправность ВИП ССДИ-35 2канал
	{ 16	,1	,1	, &R6IS64LDU},	//(R6IS64LDU) Исправность ВИП ССДИ-35 1канал
	{ 17	,1	,1	, &R6IS63LDU},	//(R6IS63LDU) Исправность ВИП ССДИ-39 2канал
	{ 18	,1	,1	, &R6IS62LDU},	//(R6IS62LDU) Исправность ВИП ССДИ-39 1канал
	{ 19	,1	,1	, &B3IS22LZ2},	//(B3IS22LZ2) Приход на НУП ИС2
	{ 20	,1	,1	, &B3IS22LZ1},	//(B3IS22LZ1) Приход на НУП ИС2
	{ 21	,1	,1	, &R5IS21LDU},	//(R5IS21LDU) Приход на НУ ворот отстойной зоны
	{ 22	,1	,1	, &R5IS11LDU},	//(R5IS11LDU) Приход на ВУ ворот отстойной зоны
	{ 23	,1	,1	, &R3IS21LDU},	//(R3IS21LDU) Приход на НУ гомогенных дверей-1
	{ 24	,1	,1	, &R3IS11LDU},	//(R3IS11LDU) Приход на ВУ гомогенных дверей-1
	{ 25	,1	,1	, &B2VP82LDU},	//(B2VP82LDU) Давление ПОДЪЁМ РБ2 в норме
	{ 26	,3	,1	, &B2IP01IZ2},	//(B2IP01IZ2) Текущее давление СБРОС РБ2
	{ 27	,3	,1	, &B2IP01IZ1},	//(B2IP01IZ1) Текущее давление СБРОС РБ2
	{ 28	,5	,1	, &B2IC01UDU},	//(B2IC01UDU) Координата штока РБ2
	{ 29	,1	,1	, &B2IS12LDU},	//(B2IS12LDU) Магнит РБ2 зацеплен
	{ 30	,1	,1	, &B2IS11LDU},	//(B2IS11LDU) Приход на ВУ РБ2
	{ 31	,1	,1	, &B2IS21LDU},	//(B2IS21LDU) Приход на НУ РБ2
	{ 32	,1	,1	, &B9IS21LDU},	//(B9IS21LDU) Приход на НУ НИ ДС2
	{ 33	,1	,1	, &B9IS11LDU},	//(B9IS11LDU) Приход на ВУ НИ ДС2
	{ 34	,1	,1	, &A9IS21LDU},	//(A9IS21LDU) Приход на НУ НИ ДС1
	{ 35	,1	,1	, &A9IS11LDU},	//(A9IS11LDU) Приход на ВУ НИ ДС1
	{ 36	,1	,1	, &B5IS21LDU},	//(B5IS21LDU) Приход на НУ НЛ2
	{ 37	,1	,1	, &B5IS11LDU},	//(B5IS11LDU) Приход на ВУ НЛ2
	{ 38	,1	,1	, &A5IS21LDU},	//(A5IS21LDU) Приход на НУ НЛ1
	{ 39	,1	,1	, &A5IS11LDU},	//(A5IS11LDU) Приход на ВУ НЛ1
	{ 40	,1	,1	, &R0VP82LZ2},	//(R0VP82LZ2) Давление  в СИСТЕМЕ-2 в норме
	{ 41	,1	,1	, &R0VP82LZ1},	//(R0VP82LZ1) Давление  в СИСТЕМЕ-2 в норме
	{ 42	,3	,1	, &A2IP01IZ2},	//(A2IP01IZ2) Текущее давление СБРОС РБ1
	{ 43	,3	,1	, &A2IP01IZ1},	//(A2IP01IZ1) Текущее давление СБРОС РБ1
	{ 44	,1	,1	, &B3IS21LDU},	//(B3IS21LDU) Приход на НУ ИС2
	{ 45	,1	,1	, &A3IS21LDU},	//(A3IS21LDU) Приход на НУ ИС1
	{ 46	,1	,1	, &A2IS33LDU},	//(A2IS33LDU) Клапан (Подъём РБ1)  открыт (обесточен)
	{ 47	,5	,1	, &A2IC01UDU},	//(A2IC01UDU) Координата штока РБ1
	{ 48	,1	,1	, &A2IS12LDU},	//(A2IS12LDU) Магнит РБ1 зацеплен
	{ 49	,1	,1	, &A2IS11LDU},	//(A2IS11LDU) Приход на ВУ РБ1
	{ 50	,1	,1	, &A2IS21LDU},	//(A2IS21LDU) Приход на НУ РБ1
	{ 51	,3	,1	, &B0IT02IZ2},	//(B0IT02IZ2) Температура АЗ2-2
	{ 52	,3	,1	, &B0IT01IZ1},	//(B0IT01IZ1) Температура АЗ2-1
	{ 53	,3	,1	, &A0IT02IZ2},	//(A0IT02IZ2) Температура АЗ1-2
	{ 54	,3	,1	, &A0IT01IZ1},	//(A0IT01IZ1) Температура АЗ1-1
	{ 55	,1	,1	, &R6IS21LDU},	//(R6IS21LDU) Кран-балка в нерабочем положении
	{ 56	,1	,1	, &B7AS31LDU},	//(B7AS31LDU) Клапан (Обдув АЗ2) открыт (обесточен)
	{ 57	,1	,1	, &A7AS31LDU},	//(A7AS31LDU) Клапан (Обдув АЗ1) открыт (обесточен)
	{ 58	,1	,1	, &R0IE11LS4},	//(R0IE11LS4) Исправность ВИП 1,6 (№17) СНМ11 4канала
	{ 59	,1	,1	, &R0IE13LS4},	//(R0IE13LS4) Исправность ВИП 0,5 (№19) КНК53М 4канала
	{ 60	,1	,1	, &R0IE12LS4},	//(R0IE12LS4) Исправность ВИП 0,5 (№18) КНК15-1 4канала
	{ 61	,1	,1	, &A1EE01LS4},	//(A1EE01LS4) Исправность АКНП канал 4 на БАЗ2
	{ 62	,1	,1	, &B3IS22LDU},	//(B3IS22LDU) Приход на НУП ИС2
	{ 63	,1	,1	, &B3IS11LZ2},	//(B3IS11LZ2) Приход на ВУ ИС2
	{ 64	,1	,1	, &B3IS11LZ1},	//(B3IS11LZ1) Приход на ВУ ИС2
	{ 65	,1	,1	, &A3IS22LZ2},	//(A3IS22LZ2) Приход на НУП ИС1
	{ 66	,1	,1	, &A3IS22LZ1},	//(A3IS22LZ1) Приход на НУП ИС1
	{ 67	,1	,1	, &A3IS11LZ2},	//(A3IS11LZ2) Приход на ВУ ИС1
	{ 68	,1	,1	, &A3IS11LZ1},	//(A3IS11LZ1) Приход на ВУ ИС1
	{ 69	,1	,1	, &A3IS22LDU},	//(A3IS22LDU) Приход на НУП ИС1
	{ 70	,1	,1	, &B3IS11LDU},	//(B3IS11LDU) Приход на ВУ ИС2
	{ 71	,1	,1	, &A3IS11LDU},	//(A3IS11LDU) Приход на ВУ ИС1
	{ 72	,3	,1	, &A3IP02IDU},	//(A3IP02IDU) Текущее давление ВЫСТРЕЛ ИС1
	{ 73	,1	,1	, &B3VP81LDU},	//(B3VP81LDU) Давление СПУСК ИС2 в норме
	{ 74	,1	,1	, &A3VP81LDU},	//(A3VP81LDU) Давление СПУСК ИС1 в норме
	{ 75	,1	,1	, &B3IS33LDU},	//(B3IS33LDU) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{ 76	,5	,1	, &B3IC01UDU},	//(B3IC01UDU) Координата штока ИС2
	{ 77	,1	,1	, &B3IS31LDU},	//(B3IS31LDU) Клапан (СПУСК ИС2)  открыт (обесточен)
	{ 78	,3	,1	, &B3IP02IDU},	//(B3IP02IDU) Текущее давление ВЫСТРЕЛ  ИС2
	{ 79	,1	,1	, &A3IS33LDU},	//(A3IS33LDU) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
	{ 80	,5	,1	, &A3IC01UDU},	//(A3IC01UDU) Координата штока ИС1
	{ 81	,1	,1	, &A3IS31LDU},	//(A3IS31LDU) Клапан (СПУСК ИС1)  открыт (обесточен)
	{ 82	,1	,1	, &A2VP82LDU},	//(A2VP82LDU) Давление ПОДЪЁМ РБ1 в норме
	{ 83	,1	,1	, &B2IS11LIM},	//(B2IS11LIM) Магнит РБ2 обесточен
	{ 84	,1	,1	, &A2IS32LIM},	//(A2IS32LIM) Клапан cброса РБ1 открыт(обесточен)
	{ 85	,1	,1	, &A2IS11LIM},	//(A2IS11LIM) Магнит РБ1 обесточен
	{ 86	,1	,1	, &B1IS32LIM},	//(B1IS32LIM) Клапан cброса ББ2 открыт(обесточен)
	{ 87	,1	,1	, &B1IS11LIM},	//(B1IS11LIM) Магнит ББ2 обесточен
	{ 88	,1	,1	, &A1IS32LIM},	//(A1IS32LIM) Клапан cброса ББ1 открыт(обесточен)
	{ 89	,1	,1	, &A1IS11LIM},	//(A1IS11LIM) Магнит ББ1 обесточен
	{ 90	,1	,1	, &A3AD34LDU},	//(A3AD34LDU) Клапан (ВПИС ИС1) открыть (обесточить)
	{ 91	,1	,1	, &R0IS02LDU},	//(R0IS02LDU) Разрешение ввода от имитатора
	{ 92	,1	,1	, &R0EE04LZ2},	//(R0EE04LZ2) Питание  АКНП4  отключить
	{ 93	,1	,1	, &R0EE03LZ2},	//(R0EE03LZ2) Питание  АКНП3  отключить
	{ 94	,1	,1	, &R0EE02LZ2},	//(R0EE02LZ2) Питание  АКНП  отключить
	{ 95	,1	,1	, &R0EE04LZ1},	//(R0EE04LZ1) Питание  АКНП4  отключить
	{ 96	,1	,1	, &R0EE03LZ1},	//(R0EE03LZ1) Питание  АКНП3  отключить
	{ 97	,1	,1	, &R0EE02LZ1},	//(R0EE02LZ1) Питание  АКНП  отключить
	{ 98	,1	,1	, &R0EE01LZ2},	//(R0EE01LZ2) Питание  АКНП1  отключить
	{ 99	,1	,1	, &R0EE01LZ1},	//(R0EE01LZ1) Питание  АКНП1  отключить
	{ 100	,1	,1	, &R5AD20LDU},	//(R5AD20LDU) Закрыть ворота отстойной зоны
	{ 101	,1	,1	, &R3AD21LDU},	//(R3AD21LDU) Гомогенные двери-2 закрыть
	{ 102	,1	,1	, &R3AD11LDU},	//(R3AD11LDU) Гомогенные двери-2 открыть
	{ 103	,8	,1	, &B0SN07RIM},	//(B0SN07RIM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
	{ 104	,8	,1	, &B0SN06RIM},	//(B0SN06RIM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
	{ 105	,8	,1	, &B0SN05RIM},	//(B0SN05RIM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
	{ 106	,8	,1	, &B0SN04RIM},	//(B0SN04RIM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
	{ 107	,8	,1	, &B0SN03RIM},	//(B0SN03RIM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
	{ 108	,8	,1	, &B0SN02RIM},	//(B0SN02RIM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
	{ 109	,1	,1	, &B7AP31LDU},	//(B7AP31LDU) Клапан (Обдув АЗ2) открыть (обесточить)
	{ 110	,1	,1	, &A7AP31LDU},	//(A7AP31LDU) Клапан (Обдув АЗ1) открыть (обесточить)
	{ 111	,8	,1	, &A0SN07RIM},	//(A0SN07RIM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
	{ 112	,8	,1	, &A0SN06RIM},	//(A0SN06RIM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
	{ 113	,8	,1	, &A0SN05RIM},	//(A0SN05RIM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
	{ 114	,8	,1	, &A0SN04RIM},	//(A0SN04RIM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
	{ 115	,8	,1	, &A0SN03RIM},	//(A0SN03RIM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
	{ 116	,8	,1	, &A0SN02RIM},	//(A0SN02RIM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
	{ 117	,1	,1	, &A1VP81LZ2},	//(A1VP81LZ2) Давление СБРОС ББ1 в норме
	{ 118	,1	,1	, &A1VP81LZ1},	//(A1VP81LZ1) Давление СБРОС ББ1 в норме
	{ 119	,1	,1	, &B1VP81LZ1},	//(B1VP81LZ1) Давление СБРОС ББ2 в норме
	{ 120	,1	,1	, &B1VP81LZ2},	//(B1VP81LZ2) Давление СБРОС ББ2 в норме
	{ 121	,1	,1	, &B2IS33LDU},	//(B2IS33LDU) Клапан (Подъём РБ2)  открыт (обесточен)
	{ 122	,8	,1	, &A0VN01RIM},	//(A0VN01RIM) Период разгона  AЗ1
	{ 123	,1	,1	, &B2IS32LIM},	//(B2IS32LIM) Клапан cброса РБ2 открыт(обесточен)
	{ 124	,1	,1	, &A8IS12LDU},	//(A8IS12LDU) Приход на механический ВУ ДС2
	{ 125	,1	,1	, &A8IS22LDU},	//(A8IS22LDU) Приход на механический НУ ДС2
	{ 126	,1	,1	, &B8IS12LDU},	//(B8IS12LDU) Приход на механический ВУ АЗ2
	{ 127	,1	,1	, &B8IS22LDU},	//(B8IS22LDU) Приход на механический НУ АЗ2
	{ 128	,1	,1	, &R4IS12LDU},	//(R4IS12LDU) Приход на механический ВУ тележки
	{ 129	,1	,1	, &R4IS22LDU},	//(R4IS22LDU) Приход на механический НУ тележки
	{ 130	,1	,1	, &R4IS21LDU},	//(R4IS21LDU) Приход на НУ тележки
	{ 131	,1	,1	, &R4IS11LDU},	//(R4IS11LDU) Приход на ВУ тележки
	{ 132	,1	,1	, &B4VP82LDU},	//(B4VP82LDU) Давление ПОДЪЁМ НИ2 в норме
	{ 133	,1	,1	, &A4VP82LDU},	//(A4VP82LDU) Давление ПОДЪЁМ НИ1 в норме
	{ 134	,1	,1	, &R3IS41LDU},	//(R3IS41LDU) Приход на НУ гомогенных дверей-2
	{ 135	,1	,1	, &R3IS31LDU},	//(R3IS31LDU) Приход на ВУ гомогенных дверей-2
	{ 136	,1	,1	, &R2IS21LDU},	//(R2IS21LDU) Приход на НУ МДЗ2
	{ 137	,1	,1	, &R2IS11LDU},	//(R2IS11LDU) Приход на ВУ МДЗ2
	{ 138	,1	,1	, &R1IS21LDU},	//(R1IS21LDU) Приход на НУ МДЗ1
	{ 139	,1	,1	, &R1IS11LDU},	//(R1IS11LDU) Приход на ВУ МДЗ1
	{ 140	,1	,1	, &B4IS21LDU},	//(B4IS21LDU) Приход на НУ НИ2
	{ 141	,1	,1	, &B4IS11LDU},	//(B4IS11LDU) Приход на ВУ НИ2
	{ 142	,1	,1	, &R8IS11LDU},	//(R8IS11LDU) Аварийный НИ установлен
	{ 143	,1	,1	, &A4IS21LDU},	//(A4IS21LDU) Приход на НУ НИ1
	{ 144	,1	,1	, &A4IS11LDU},	//(A4IS11LDU) Приход на ВУ НИ1
	{ 145	,1	,1	, &R3AD20LDU},	//(R3AD20LDU) Гомогенные двери-1 закрыть
	{ 146	,1	,1	, &R3AD10LDU},	//(R3AD10LDU) Гомогенные двери-1 открыть
	{ 147	,1	,1	, &R5AD10LDU},	//(R5AD10LDU) Открыть ворота отстойной зоны
	{ 148	,1	,1	, &B4IS10LDU},	//(B4IS10LDU) Клапан (Подъём НИ2) открыт (обесточен)
	{ 149	,1	,1	, &A4IS10LDU},	//(A4IS10LDU) Клапан (Подъём НИ1) открыт (обесточен)
	{ 150	,1	,1	, &B1IE04LDU},	//(B1IE04LDU) Движение ББ2 назад (от БУШД)
	{ 151	,1	,1	, &B1IE03LDU},	//(B1IE03LDU) Движение ББ2 вперед (от БУШД)
	{ 152	,1	,1	, &A1IE04LDU},	//(A1IE04LDU) Движение ББ1 назад (от БУШД)
	{ 153	,1	,1	, &A1IE03LDU},	//(A1IE03LDU) Движение ББ1 вперед (от БУШД)
	{ 154	,1	,1	, &B1IS12LDU},	//(B1IS12LDU) Магнит ББ2 зацеплен
	{ 155	,1	,1	, &B1IS11LDU},	//(B1IS11LDU) Приход на ВУ ББ2
	{ 156	,1	,1	, &B1IS21LDU},	//(B1IS21LDU) Приход на НУ ББ2
	{ 157	,5	,1	, &B1IC01UDU},	//(B1IC01UDU) Координата штока ББ2
	{ 158	,5	,1	, &A1IC01UDU},	//(A1IC01UDU) Координата штока ББ1
	{ 159	,1	,1	, &A1IS12LDU},	//(A1IS12LDU) Магнит ББ1 зацеплен
	{ 160	,1	,1	, &A1IS11LDU},	//(A1IS11LDU) Приход на ВУ ББ1
	{ 161	,1	,1	, &A1IS21LDU},	//(A1IS21LDU) Приход на НУ ББ1
	{ 162	,1	,1	, &B6IS21LDU},	//(B6IS21LDU) Приход на НУ БЗ2
	{ 163	,1	,1	, &B6IS11LDU},	//(B6IS11LDU) Приход на ВУ БЗ2
	{ 164	,1	,1	, &A6IS21LDU},	//(A6IS21LDU) Приход на НУ БЗ1
	{ 165	,1	,1	, &A6IS11LDU},	//(A6IS11LDU) Приход на ВУ БЗ1
	{ 166	,1	,1	, &R2AD10LDU},	//(R2AD10LDU) Опустить МДЗ2 в зону облучения
	{ 167	,1	,1	, &R1AD20LDU},	//(R1AD20LDU) Поднять МДЗ1
	{ 168	,1	,1	, &R1AD10LDU},	//(R1AD10LDU) Опустить МДЗ1 в зону облучения
	{ 169	,1	,1	, &B6AD20LDU},	//(B6AD20LDU) Закрыть БЗ2
	{ 170	,1	,1	, &B6AD10LDU},	//(B6AD10LDU) Открыть БЗ2
	{ 171	,1	,1	, &A6AD20LDU},	//(A6AD20LDU) Закрыть БЗ1
	{ 172	,1	,1	, &A6AD10LDU},	//(A6AD10LDU) Открыть БЗ1
	{ 173	,1	,1	, &A8AD20LDU},	//(A8AD20LDU) Перемещение ДС2 назад
	{ 174	,1	,1	, &A8AD10LDU},	//(A8AD10LDU) Перемещение ДС2 вперед
	{ 175	,1	,1	, &B8AD20LDU},	//(B8AD20LDU) Перемещение АЗ2 назад
	{ 176	,1	,1	, &B8AD10LDU},	//(B8AD10LDU) Перемещение АЗ2 вперед
	{ 177	,1	,1	, &R4AD20LDU},	//(R4AD20LDU) Перемещение тележки назад
	{ 178	,1	,1	, &R4AD10LDU},	//(R4AD10LDU) Перемещение тележки вперед
	{ 179	,8	,1	, &B0SR01RIM},	//(B0SR01RIM) Текущая реактивность AЗ2
	{ 180	,1	,1	, &B3AD33LDU},	//(B3AD33LDU) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
	{ 181	,1	,1	, &B3AD05LDU},	//(B3AD05LDU) паритет команды на ИС2
	{ 182	,1	,1	, &B3AD04LDU},	//(B3AD04LDU) 2-й бит скорости ИС2
	{ 183	,1	,1	, &B3AD03LDU},	//(B3AD03LDU) 1-й бит скорости ИС2
	{ 184	,1	,1	, &B3AD02LDU},	//(B3AD02LDU) 0-й бит скорости ИС2
	{ 185	,1	,1	, &B3AD01LDU},	//(B3AD01LDU) Разрешение движения ИС2
	{ 186	,1	,1	, &C1MD31LP1},	//(C1MD31LP1) Кнопка «СБРОС ББ»  на ОПУ1
	{ 187	,1	,1	, &C1MD31LP2},	//(C1MD31LP2) Кнопка «СБРОС ББ»  на ОПУ2
	{ 188	,1	,1	, &A1AD31LDU},	//(A1AD31LDU) Клапан (Сброс ББ1) открыть (обесточить)
	{ 189	,1	,1	, &A1AD32LDU},	//(A1AD32LDU) Обесточить ЭМ ББ1
	{ 190	,1	,1	, &A2AD31LDU},	//(A2AD31LDU) Клапан (Сброс РБ1) открыть (обесточить)
	{ 191	,1	,1	, &C2MD31LP1},	//(C2MD31LP1) Кнопка «СБРОС РБ»
	{ 192	,1	,1	, &A2AD32LDU},	//(A2AD32LDU) Обесточить ЭМ РБ1
	{ 193	,1	,1	, &R0VZ71LZ2},	//(R0VZ71LZ2) Обобщенный сигнал по АЗ  2 канала
	{ 194	,1	,1	, &R0VZ71LZ1},	//(R0VZ71LZ1) Обобщенный сигнал по АЗ  1 канала
	{ 195	,1	,1	, &R8AD21LDU},	//(R8AD21LDU) Запуск системы инициирования
	{ 196	,1	,1	, &R0AD14LDU},	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
	{ 197	,8	,1	, &R0SR02RIM},	//(R0SR02RIM) Текущая мощность РУ (ватт)
	{ 198	,8	,1	, &R0CR02RIM},	//(R0CR02RIM) Коэффициент 11 связи АЗ1,2
	{ 199	,8	,1	, &R0CR01RIM},	//(R0CR01RIM) Коэффициент 12 связи АЗ1,2
	{ 200	,8	,1	, &B0SN08RIM},	//(B0SN08RIM) Поток нейтронов AЗ2(нейтр/с)
	{ 201	,8	,1	, &A0SN08RIM},	//(A0SN08RIM) Поток нейтронов AЗ1(нейтр/с)
	{ 202	,1	,1	, &B5AD20LDU},	//(B5AD20LDU) Опустить НЛ2
	{ 203	,1	,1	, &B5AD10LDU},	//(B5AD10LDU) Поднять НЛ2
	{ 204	,1	,1	, &A5AD20LDU},	//(A5AD20LDU) Опустить НЛ1
	{ 205	,1	,1	, &A5AD10LDU},	//(A5AD10LDU) Поднять НЛ1
	{ 206	,1	,1	, &R2AD20LDU},	//(R2AD20LDU) Поднять МДЗ2
	{ 207	,1	,1	, &A2AD03LDU},	//(A2AD03LDU) 1-й бит скорости РБ1
	{ 208	,1	,1	, &A2AD02LDU},	//(A2AD02LDU) 0-й бит скорости РБ1
	{ 209	,1	,1	, &A2AD01LDU},	//(A2AD01LDU) Разрешение движения РБ1
	{ 210	,1	,1	, &A2AD21LDU},	//(A2AD21LDU) Сигнал на перемещение РБ1 вниз
	{ 211	,1	,1	, &A2AD11LDU},	//(A2AD11LDU) Сигнал на перемещение РБ1 вверх
	{ 212	,1	,1	, &B1AD05LDU},	//(B1AD05LDU) паритет команды на ББ2
	{ 213	,1	,1	, &B1AD04LDU},	//(B1AD04LDU) 2-й бит скорости ББ2
	{ 214	,1	,1	, &B1AD03LDU},	//(B1AD03LDU) 1-й бит скорости ББ2
	{ 215	,1	,1	, &B1AD02LDU},	//(B1AD02LDU) 0-й бит скорости  ББ2
	{ 216	,1	,1	, &B1AD01LDU},	//(B1AD01LDU) Разрешение движения ББ2
	{ 217	,1	,1	, &B1AD21LDU},	//(B1AD21LDU) Сигнал на перемещение ББ2 вниз
	{ 218	,1	,1	, &B1AD11LDU},	//(B1AD11LDU) Сигнал на перемещение ББ2 вверх
	{ 219	,1	,1	, &A1AD05LDU},	//(A1AD05LDU) паритет команды на ББ1
	{ 220	,1	,1	, &A1AD04LDU},	//(A1AD04LDU) 2-й бит скорости ББ1
	{ 221	,1	,1	, &A1AD03LDU},	//(A1AD03LDU) 1-й бит скорости ББ1
	{ 222	,1	,1	, &A1AD02LDU},	//(A1AD02LDU) 0-й бит скорости ББ1
	{ 223	,1	,1	, &A1AD01LDU},	//(A1AD01LDU) Разрешение движения ББ1
	{ 224	,1	,1	, &A1AD21LDU},	//(A1AD21LDU) Сигнал на перемещение ББ1 вниз
	{ 225	,1	,1	, &A1AD11LDU},	//(A1AD11LDU) Сигнал на перемещение ББ1 вверх
	{ 226	,8	,1	, &A0SR01RIM},	//(A0SR01RIM) Текущая реактивность AЗ1
	{ 227	,1	,1	, &B3AD21LDU},	//(B3AD21LDU) Сигнал на перемещение ИС2 вниз
	{ 228	,1	,1	, &B3AD11LDU},	//(B3AD11LDU) Сигнал на перемещение ИС2 вверх
	{ 229	,1	,1	, &A3AD33LDU},	//(A3AD33LDU) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
	{ 230	,1	,1	, &A3AD05LDU},	//(A3AD05LDU) паритет команды на ИС1
	{ 231	,1	,1	, &A3AD04LDU},	//(A3AD04LDU) 2-й бит скорости ИС1
	{ 232	,1	,1	, &A3AD03LDU},	//(A3AD03LDU) 1-й бит скорости ИС1
	{ 233	,1	,1	, &A3AD02LDU},	//(A3AD02LDU) 0-й бит скорости ИС1
	{ 234	,1	,1	, &A3AD01LDU},	//(A3AD01LDU) Разрешение движения ИС1
	{ 235	,1	,1	, &A3AD21LDU},	//(A3AD21LDU) Сигнал на перемещение ИС1 вниз
	{ 236	,1	,1	, &A3AD11LDU},	//(A3AD11LDU) Сигнал на перемещение ИС1 вверх
	{ 237	,1	,1	, &B2AD33LDU},	//(B2AD33LDU) Клапан (Подъем РБ2) закрыть (обесточить)
	{ 238	,1	,1	, &B2AD05LDU},	//(B2AD05LDU) паритет команды на РБ2
	{ 239	,1	,1	, &B2AD04LDU},	//(B2AD04LDU) 2-й бит скорости РБ2
	{ 240	,1	,1	, &B2AD03LDU},	//(B2AD03LDU) 1-й бит скорости РБ2
	{ 241	,1	,1	, &B2AD02LDU},	//(B2AD02LDU) 0-й бит скорости РБ2
	{ 242	,1	,1	, &B2AD01LDU},	//(B2AD01LDU) Разрешение движения РБ2
	{ 243	,1	,1	, &B2AD21LDU},	//(B2AD21LDU) Сигнал на перемещение РБ2 вниз
	{ 244	,1	,1	, &B2AD11LDU},	//(B2AD11LDU) Сигнал на перемещение РБ2 вверх
	{ 245	,1	,1	, &A2AD33LDU},	//(A2AD33LDU) Клапан (Подъем РБ1) закрыть (обесточить)
	{ 246	,1	,1	, &A2AD05LDU},	//(A2AD05LDU) паритет команды на РБ1
	{ 247	,1	,1	, &A2AD04LDU},	//(A2AD04LDU) 2-й бит скорости РБ1
	{ 248	,1	,1	, &R0VN73LZ2},	//(R0VN73LZ2) АС по мощности канал 3 на БАЗ2
	{ 249	,1	,1	, &A0VN71LS3},	//(A0VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ1
	{ 250	,3	,1	, &R0VN15RS3},	//(R0VN15RS3) Номер ведущей камеры канал 3
	{ 251	,1	,1	, &A1VN71LS3},	//(A1VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ2
	{ 252	,1	,1	, &R0VN73LZ1},	//(R0VN73LZ1) АС по мощности канал 3 на БАЗ1
	{ 253	,1	,1	, &R0VN61LS3},	//(R0VN61LS3) ПС по мощности канал 3
	{ 254	,8	,1	, &R0VN02RS3},	//(R0VN02RS3) Уровень мощности канал 3
	{ 255	,1	,1	, &R0IE11LS2},	//(R0IE11LS2) Исправность ВИП 1,6 (№11) СНМ11 2канала
	{ 256	,1	,1	, &R0IE13LS2},	//(R0IE13LS2) Исправность ВИП 0,5 (№13) КНК53М 2канала
	{ 257	,1	,1	, &R0IE12LS2},	//(R0IE12LS2) Исправность ВИП 0,5 (№12) КНК15-1 2канала
	{ 258	,1	,1	, &A1EE01LS2},	//(A1EE01LS2) Исправность АКНП канал 2 на БАЗ2
	{ 259	,1	,1	, &R0VN76LZ2},	//(R0VN76LZ2) АС по периоду разгона канал 2  на БАЗ2
	{ 260	,1	,1	, &A0EE01LS2},	//(A0EE01LS2) Исправность АКНП канал 2 на БАЗ1
	{ 261	,1	,1	, &R0VN76LZ1},	//(R0VN76LZ1) АС по периоду разгона канал 2  на БАЗ1
	{ 262	,1	,1	, &R0VN65LS2},	//(R0VN65LS2) ПС по периоду разгона канал 2
	{ 263	,8	,1	, &R0VN01RS2},	//(R0VN01RS2) Период разгона канал 2
	{ 264	,1	,1	, &A0VN71LS2},	//(A0VN71LS2) Блокировка автоматического подъёма ББ канал 2 на БАЗ1
	{ 265	,1	,1	, &R0VN72LZ2},	//(R0VN72LZ2) АС по мощности канал 2 на БАЗ2
	{ 266	,3	,1	, &R0VN15RS2},	//(R0VN15RS2) Номер ведущей камеры канал 2
	{ 267	,1	,1	, &A1VN71LS2},	//(A1VN71LS2) Блокировка автоматического подъёма ББ канал 2 на БАЗ2
	{ 268	,1	,1	, &R0VN78LZ2},	//(R0VN78LZ2) АС по периоду разгона канал 4 на БАЗ2
	{ 269	,1	,1	, &A0EE01LS4},	//(A0EE01LS4) Исправность АКНП канал 4 на БАЗ1
	{ 270	,1	,1	, &R0VN78LZ1},	//(R0VN78LZ1) АС по периоду разгона канал 4 на БАЗ1
	{ 271	,1	,1	, &R0VN65LS4},	//(R0VN65LS4) ПС по периоду разгона канал 4
	{ 272	,8	,1	, &R0VN01RS4},	//(R0VN01RS4) Период разгона канал 4
	{ 273	,1	,1	, &R0VN74LZ2},	//(R0VN74LZ2) АС по мощности канал 4 на БАЗ2
	{ 274	,1	,1	, &A0VN71LS4},	//(A0VN71LS4) Блокировка автоматического  подъёма ББ канал 4 на БАЗ1
	{ 275	,3	,1	, &R0VN15RS4},	//(R0VN15RS4) Номер ведущей камеры канал 4
	{ 276	,1	,1	, &A1VN71LS4},	//(A1VN71LS4) Блокировка автоматического  подъёма ББ канал 4 на БАЗ2
	{ 277	,1	,1	, &R0VN74LZ1},	//(R0VN74LZ1) АС по мощности канал 4 на БАЗ1
	{ 278	,1	,1	, &R0VN61LS4},	//(R0VN61LS4) ПС по мощности канал 4
	{ 279	,8	,1	, &R0VN02RS4},	//(R0VN02RS4) Уровень мощности канал 4
	{ 280	,1	,1	, &R0IE11LS3},	//(R0IE11LS3) Исправность ВИП 1,6 (№14) СНМ11 3канала
	{ 281	,1	,1	, &R0IE13LS3},	//(R0IE13LS3) Исправность ВИП 0,5 (№16) КНК53М 3канала
	{ 282	,1	,1	, &R0IE12LS3},	//(R0IE12LS3) Исправность ВИП 0,5 (№15) КНК15-1 3канала
	{ 283	,1	,1	, &A1EE01LS3},	//(A1EE01LS3) Исправность АКНП канал 3 на БАЗ2
	{ 284	,1	,1	, &R0VN77LZ2},	//(R0VN77LZ2) АС по периоду разгона канал 3 на БАЗ2
	{ 285	,1	,1	, &A0EE01LS3},	//(A0EE01LS3) Исправность АКНП канал 3 на БАЗ1
	{ 286	,1	,1	, &R0VN77LZ1},	//(R0VN77LZ1) АС по периоду разгона канал 3 на БАЗ1
	{ 287	,1	,1	, &R0VN65LS3},	//(R0VN65LS3) ПС по периоду разгона канал 3
	{ 288	,8	,1	, &R0VN01RS3},	//(R0VN01RS3) Период разгона канал 3
	{ 289	,1	,1	, &A3IS35LDU},	//(A3IS35LDU) Клапан (ВПИС1) открыт(обесточен)
	{ 290	,1	,1	, &R7II73LZ2},	//(R7II73LZ2) Сработала АС IIУР
	{ 291	,1	,1	, &R7II71LZ2},	//(R7II71LZ2) Сработала АС IУР (датчик 1)
	{ 292	,1	,1	, &R7II72LZ2},	//(R7II72LZ2) Сработала АС IУР (датчик 2)
	{ 293	,1	,1	, &R0AD16LDU},	//(R0AD16LDU) Контроль  I-II УР. РАД
	{ 294	,1	,1	, &R7II72LZ1},	//(R7II72LZ1) Сработала АС IУР (датчик 2)
	{ 295	,1	,1	, &R7II71LZ1},	//(R7II71LZ1) Сработала АС IУР (датчик 1)
	{ 296	,1	,1	, &R7II73LZ1},	//(R7II73LZ1) Сработала АС IIУР
	{ 297	,8	,1	, &R0SR01RIM},	//(R0SR01RIM) Текущая реактивность PУ
	{ 298	,8	,1	, &R0ST01RIM},	//(R0ST01RIM) Текущий период разгона РУ
	{ 299	,1	,1	, &A4AD10LDU},	//(A4AD10LDU) Открыть клапан (Подъем НИ1)
	{ 300	,1	,1	, &B4AD10LDU},	//(B4AD10LDU) Открыть клапан (Подъем НИ2)
	{ 301	,1	,1	, &A9AD10LDU},	//(A9AD10LDU) Открыть клапан (Подъем НИ ДС1)
	{ 302	,1	,1	, &B9AD10LDU},	//(B9AD10LDU) Открыть клапан (Подъем НИ ДС2)
	{ 303	,1	,1	, &R0MW13LP2},	//(R0MW13LP2) Переключатель «СЕТЬ»
	{ 304	,1	,1	, &B3AD31LDU},	//(B3AD31LDU) Клапан (СПУСК ИС2) открыть (обесточить)
	{ 305	,1	,1	, &B2AD32LDU},	//(B2AD32LDU) Обесточить ЭМ РБ2
	{ 306	,1	,1	, &B2AD31LDU},	//(B2AD31LDU) Клапан (Сброс РБ2) открыть (обесточить)
	{ 307	,1	,1	, &B1AD32LDU},	//(B1AD32LDU) Обесточить ЭМ ББ2
	{ 308	,1	,1	, &B1AD31LDU},	//(B1AD31LDU) Клапан (Сброс ББ2) открыть (обесточить)
	{ 309	,1	,1	, &A3AD31LDU},	//(A3AD31LDU) Клапан (СПУСК ИС1) открыть (обесточить)
	{ 310	,1	,1	, &R0VN72LZ1},	//(R0VN72LZ1) АС по мощности канал 2 на БАЗ1
	{ 311	,1	,1	, &R0VN61LS2},	//(R0VN61LS2) ПС по мощности канал 2
	{ 312	,8	,1	, &R0VN02RS2},	//(R0VN02RS2) Уровень мощности канал 2
	{ 313	,1	,1	, &R0IE13LS1},	//(R0IE13LS1) Исправность ВИП 0,5 (№10) КНК53М 1канала
	{ 314	,1	,1	, &R0IE12LS1},	//(R0IE12LS1) Исправность ВИП 0,5 (№9) КНК15-1 1канала
	{ 315	,1	,1	, &R0IE11LS1},	//(R0IE11LS1) Исправность ВИП 1,6 (№8) СНМ11 1канала
	{ 316	,1	,1	, &A1EE01LS1},	//(A1EE01LS1) Исправность АКНП на БАЗ2
	{ 317	,1	,1	, &R0VN75LZ2},	//(R0VN75LZ2) АС по периоду разгонана БАЗ2
	{ 318	,1	,1	, &A0EE01LS1},	//(A0EE01LS1) Исправность АКНП канал1 на БАЗ1
	{ 319	,1	,1	, &R0VN75LZ1},	//(R0VN75LZ1) АС по периоду разгонана БАЗ1
	{ 320	,1	,1	, &R0VN65LS1},	//(R0VN65LS1) ПС по периоду разгона канал1
	{ 321	,8	,1	, &R0VN01RS1},	//(R0VN01RS1) Период разгона канал1
	{ 322	,1	,1	, &A1VN71LS1},	//(A1VN71LS1) Блокировка автоматического  подъёма ББ канал 1 на БАЗ2
	{ 323	,1	,1	, &R0VN71LZ2},	//(R0VN71LZ2) АС по мощности канал 1  на БАЗ2
	{ 324	,3	,1	, &R0VN15RS1},	//(R0VN15RS1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
	{ 325	,1	,1	, &A0VN71LS1},	//(A0VN71LS1) Блокировка автоматического  подъёма ББ канал 1 на БАЗ1
	{ 326	,1	,1	, &R0VN71LZ1},	//(R0VN71LZ1) АС по мощности канал1 на БАЗ1
	{ 327	,1	,1	, &R0VN61LS1},	//(R0VN61LS1) ПС по мощности канал1
	{ 328	,8	,1	, &R0VN02RS1},	//(R0VN02RS1) Уровень мощности канал1
	{ 329	,1	,1	, &B3IS35LDU},	//(B3IS35LDU) Клапан «ВПИС2» открыт(обесточен)
	{ 330	,1	,1	, &B3AD34LDU},	//(B3AD34LDU) Клапан (ВПИС2) открыть (обесточить)
	{ 331	,8	,1	, &fEM_R0UL01RIM},	//(R0UL01RIM) Среднее время генерации нейтронов
	{ 332	,8	,1	, &fEM_R0UN02RIM},	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{ 333	,8	,1	, &fEM_A1UR01RIM},	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{ 334	,8	,1	, &fEM_A1UR00RIM},	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{ 335	,8	,1	, &fEM_A3UR00RIM},	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{ 336	,8	,1	, &fEM_A3UR01RIM},	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{ 337	,8	,1	, &fEM_R0UT01RIM},	//(R0UT01RIM) Температурный коэффициент (долл)
	{ 338	,8	,1	, &fEM_R0UT02RIM},	//(R0UT02RIM) Масса топлива в АЗ
	{ 339	,8	,1	, &fEM_R0UT04RIM},	//(R0UT04RIM) Удельная теплоёмкость топлива
	{ 340	,8	,1	, &fEM_R0UT03RIM},	//(R0UT03RIM) Нормальная температура АЗ град
	{ 341	,8	,1	, &fEM_R0UT05RIM},	//(R0UT05RIM) Энергия деления ядра
	{ 342	,8	,1	, &fEM_R0UT06RIM},	//(R0UT06RIM) Конвекционное сопротивление при обдуве
	{ 343	,8	,1	, &fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
	{ 344	,8	,1	, &fEM_A1UC04RIM},	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
	{ 345	,8	,1	, &fEM_A1UC05RIM},	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
	{ 346	,8	,1	, &fEM_A1UC06RIM},	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
	{ 347	,8	,1	, &fEM_A2UC06RIM},	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
	{ 348	,8	,1	, &fEM_A2UC05RIM},	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
	{ 349	,8	,1	, &fEM_A2UC04RIM},	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
	{ 350	,8	,1	, &fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
	{ 351	,8	,1	, &fEM_A3UC06RIM},	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
	{ 352	,8	,1	, &fEM_A3UC05RIM},	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
	{ 353	,8	,1	, &fEM_A3UC04RIM},	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
	{ 354	,8	,1	, &fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
	{ 355	,8	,1	, &fEM_R4UV80RDU},	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
	{ 356	,8	,1	, &fEM_R4UC10RIM},	//(R4UC10RIM) Координата верхних механических упоров тележки мм
	{ 357	,8	,1	, &fEM_R4UC20RIM},	//(R4UC20RIM) Координата нижних механических упоров тележки мм
	{ 358	,8	,1	, &fEM_B8UC21RIM},	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
	{ 359	,8	,1	, &fEM_B8UC20RIM},	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
	{ 360	,8	,1	, &fEM_B8UC11RIM},	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
	{ 361	,8	,1	, &fEM_B8UC10RIM},	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
	{ 362	,8	,1	, &fEM_B8UV80RDU},	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
	{ 363	,8	,1	, &fEM_A8UV80RDU},	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
	{ 364	,8	,1	, &fEM_A8UC10RIM},	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
	{ 365	,8	,1	, &fEM_A8UC11RIM},	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
	{ 366	,8	,1	, &fEM_A8UC20RIM},	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
	{ 367	,8	,1	, &fEM_A8UC21RIM},	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
	{ 368	,8	,1	, &fEM_A6UC10RIM},	//(A6UC10RIM) Время полного хода БЗ (сек)
	{ 369	,8	,1	, &fEM_R1UC10RIM},	//(R1UC10RIM) Время полного хода МДЗ сек
	{ 370	,8	,1	, &fEM_A5UC10RIM},	//(A5UC10RIM) Время полного хода НЛ сек
	{ 371	,8	,1	, &fEM_A0UN01RIM},	//(A0UN01RIM) Мощность источника нейтронов ИНИ
	{ 372	,8	,1	, &fEM_R4UC22RIM},	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
	{ 373	,8	,1	, &fEM_R4UC23RIM},	//(R4UC23RIM) Y-координата АЗ1 см
	{ 374	,8	,1	, &fEM_A1UG01RDU},	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
	{ 375	,8	,1	, &fEM_A2UG01RDU},	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
	{ 376	,8	,1	, &fEM_A3UG01RDU},	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
	{ 377	,8	,1	, &fEM_R7UC10RIM},	//(R7UC10RIM) X-координата КНК53М R7IN13 см
	{ 378	,8	,1	, &fEM_R7UC19RIM},	//(R7UC19RIM) Y-координата СНМ-11 (11) см
	{ 379	,8	,1	, &fEM_R7UI02RIM},	//(R7UI02RIM) Коэффициент усиления уровня радиации
	{ 380	,8	,1	, &fEM_R7UL01RIM},	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
	{ 381	,8	,1	, &fEM_A2UR00RIM},	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
	{ 382	,8	,1	, &fEM_A2UR01RIM},	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
	{ 383	,8	,1	, &fEM_A0UN02RIM},	//(A0UN02RIM) Мощность источника нейтронов с АНИ
	{ 384	,8	,1	, &fEM_R0UR30RIM},	//(R0UR30RIM) Реактивность вносимая образцами (долл)
	{ 385	,8	,1	, &fEM_R0UR01RIM},	//(R0UR01RIM) Стартовая отрицательная реактивность
	{ 386	,8	,1	, &fEM_R0UT02RDU},	//(R0UT02RDU) Верхний предел шкалы датчика температуры
	{ 387	,8	,1	, &fEM_R0UT01RDU},	//(R0UT01RDU) Нижний предел шкалы датчика температуры
	{ 388	,8	,1	, &fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
	{ 389	,8	,1	, &fEM_A2UP03RDU},	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
	{ 390	,8	,1	, &fEM_A2UP04RDU},	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
	{ 391	,8	,1	, &fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
	{ 392	,8	,1	, &fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{ 393	,8	,1	, &fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{ 394	,8	,1	, &fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
	{ 395	,8	,1	, &fEM_R7UI74RIM},	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
	{ 396	,8	,1	, &fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
	{ 397	,8	,1	, &fEM_R0UV87RDU},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 398	,8	,1	, &fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{ 399	,8	,1	, &fEM_R0UV82RDU},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{ 400	,8	,1	, &fEM_R0UV83RDU},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{ 401	,8	,1	, &fEM_R0UV84RDU},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{ 402	,8	,1	, &fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{ 403	,8	,1	, &fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 404	,8	,1	, &fEM_A8UC08RDU},	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
	{ 405	,8	,1	, &fEM_B8UC08RDU},	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
	{ 406	,8	,1	, &fEM_R4UC08RDU},	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
	{ 407	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 408	,8	,1	, &fEM_R7UX01RSS},	//(R7UX01RSS) X-координата камеры R7IN11
	{ 409	,8	,1	, &fEM_R7UX02RSS},	//(R7UX02RSS) X-координата камеры R7IN12 (см)
	{ 410	,8	,1	, &fEM_R7UX04RSS},	//(R7UX04RSS) X-координата камеры R7IN21 (см)
	{ 411	,8	,1	, &fEM_R7UX05RSS},	//(R7UX05RSS) X-координата камеры R7IN22 (см)
	{ 412	,8	,1	, &fEM_R7UX06RSS},	//(R7UX06RSS) X-координата камеры R7IN23 (см)
	{ 413	,8	,1	, &fEM_R7UX07RSS},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{ 414	,8	,1	, &fEM_R7UX08RSS},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{ 415	,8	,1	, &fEM_R7UX09RSS},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{ 416	,8	,1	, &fEM_R7UY01RSS},	//(R7UY01RSS) Y-координата камеры R7IN11
	{ 417	,8	,1	, &fEM_R7UY02RSS},	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
	{ 418	,8	,1	, &fEM_R7UY04RSS},	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
	{ 419	,8	,1	, &fEM_R7UY05RSS},	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
	{ 420	,8	,1	, &fEM_R7UY06RSS},	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
	{ 421	,8	,1	, &fEM_R7UY07RSS},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{ 422	,8	,1	, &fEM_R7UY08RSS},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{ 423	,8	,1	, &fEM_R7UY09RSS},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{ 424	,8	,1	, &fEM_R7UX10RSS},	//(R7UX10RSS) X-координата камеры R7IN41
	{ 425	,8	,1	, &fEM_R7UX11RSS},	//(R7UX11RSS) X-координата камеры R7IN42
	{ 426	,8	,1	, &fEM_R7UX12RSS},	//(R7UX12RSS) X-координата камеры R7IN43
	{ 427	,8	,1	, &fEM_R7UY10RSS},	//(R7UY10RSS) Y-координата камеры R7IN41
	{ 428	,8	,1	, &fEM_R7UY11RSS},	//(R7UY11RSS) Y-координата камеры R7IN42
	{ 429	,8	,1	, &fEM_R7UY12RSS},	//(R7UY12RSS) Y-координата камеры R7IN43
	{ 430	,8	,1	, &fEM_A0UX01RSS},	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
	{ 431	,8	,1	, &fEM_A0UX02RSS},	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
	{ 432	,8	,1	, &fEM_A0UX03RSS},	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
	{ 433	,8	,1	, &fEM_A0UX04RSS},	//(A0UX04RSS) Первый коэффициент калибровки камеры4
	{ 434	,8	,1	, &fEM_A0UX05RSS},	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
	{ 435	,8	,1	, &fEM_A0UX06RSS},	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
	{ 436	,8	,1	, &fEM_A0UX07RSS},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{ 437	,8	,1	, &fEM_A0UX08RSS},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{ 438	,8	,1	, &fEM_A0UX09RSS},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{ 439	,8	,1	, &fEM_A0UX10RSS},	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
	{ 440	,8	,1	, &fEM_A0UX11RSS},	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
	{ 441	,8	,1	, &fEM_A0UX12RSS},	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
	{ 442	,8	,1	, &fEM_B0UX01RSS},	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
	{ 443	,8	,1	, &fEM_B0UX02RSS},	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
	{ 444	,8	,1	, &fEM_B0UX03RSS},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{ 445	,8	,1	, &fEM_B0UX04RSS},	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
	{ 446	,8	,1	, &fEM_B0UX05RSS},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{ 447	,8	,1	, &fEM_B0UX06RSS},	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
	{ 448	,8	,1	, &fEM_B0UX07RSS},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{ 449	,8	,1	, &fEM_B0UX08RSS},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{ 450	,8	,1	, &fEM_B0UX09RSS},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{ 451	,8	,1	, &fEM_B0UX10RSS},	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
	{ 452	,8	,1	, &fEM_B0UX11RSS},	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
	{ 453	,8	,1	, &fEM_B0UX12RSS},	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
	{ 454	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
	{ 455	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
	{ 456	,8	,1	, &fEM_R4US80RDU},	//(R4US80RDU) Тормозной путь тележки (мм)
	{ 457	,8	,1	, &fEM_R7UI71RIM},	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{ 458	,8	,1	, &fEM_R7UI72RIM},	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
	{ 459	,8	,1	, &fEM_R7UI73RIM},	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
	{ 460	,8	,1	, &fEM_A1UP01RIM},	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
	{ 461	,8	,1	, &fEM_A2UP01RIM},	//(A2UP01RIM) Текущее давление на сброс РБ
	{ 462	,8	,1	, &fEM_A0UP02RIM},	//(A0UP02RIM) Текущее давление в АЗ1,2
	{ 463	,8	,1	, &fEM_A3UP01RIM},	//(A3UP01RIM) Текущее давление на СПУСК ИС
	{ 464	,8	,1	, &fEM_A1UP82RIM},	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{ 465	,8	,1	, &fEM_R0UP85RIM},	//(R0UP85RIM) Нижняя граница давления  в СИСТЕМЕ (МПа)
	{ 466	,8	,1	, &fEM_R0UP88RIM},	//(R0UP88RIM) Верхняя граница давления  в СИСТЕМЕ (МПа)
	{ 467	,8	,1	, &fEM_A3UP02RDU},	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
	{ 468	,8	,1	, &fEM_A1UV02RIM},	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{ 469	,8	,1	, &fEM_A3UV02RIM},	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{ 470	,8	,1	, &fEM_A2UV02RIM},	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{ 471	,8	,1	, &fEM_B8US80RDU},	//(B8US80RDU) Тормозной путь АЗ2 (мм)
	{ 472	,8	,1	, &fEM_A8US80RDU},	//(A8US80RDU) Тормозной путь ДС2 (мм)
	{ 473	,8	,1	, &fEM_A6US80RDU},	//(A6US80RDU) Тормозной путь БЗ (мм)
	{ 474	,8	,1	, &fEM_A1US07RDU},	//(A1US07RDU) Постоянная времени масляного демпфера ББ
	{ 475	,8	,1	, &fEM_A2US07RDU},	//(A2US07RDU) Постоянная времени масляного демпфера РБ
	{ 476	,8	,1	, &fEM_A3US07RDU},	//(A3US07RDU) Постоянная времени масляного демпфера ИС
	{ 477	,8	,1	, &fEM_R7UI75RIM},	//(R7UI75RIM) Множитель к уровню радиации
	{ 478	,8	,1	, &fEM_R0UH21RSS},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{ 479	,8	,1	, &fEM_R0UH22RSS},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{ 480	,8	,1	, &fEM_R0UH23RSS},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{ 481	,8	,1	, &fEM_R0UR01RSS},	//(R0UR01RSS) Уровень по мощности РУ блокировки автоматического подъёма ББ
	{ 482	,8	,1	, &fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	{ 483	,8	,1	, &fEM_R0UL41RSS},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{ 484	,8	,1	, &fEM_R0UL51RSS},	//(R0UL51RSS) Уровень АС по периоду разгона
	{ 485	,8	,1	, &fEM_R0UL42RSS},	//(R0UL42RSS) Уровень ПС по мощности
	{ 486	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 487	,8	,1	, &fEM_R0UN03RSS},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 488	,8	,1	, &fEM_A4UL10RIM},	//(A4UL10RIM) Время полного перемещения НИ сек
	{ 489	,8	,1	, &fEM_A9UL10RIM},	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
	{ 490	,8	,1	, &fEM_R3UL10RIM},	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
	{ 491	,8	,1	, &fEM_R5UL10RIM},	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
	{ 492	,8	,1	, &fEM_R6UL10RIM},	//(R6UL10RIM) Время полного хода кран-балки сек
	{ 493	,1	,1	, &lEM_C1AD31LRP},	//(C1AD31LRP) Общий сброс от РПУ
	{ 494	,1	,1	, &lEM_R0IE01LRP},	//(R0IE01LRP) Отключение питание детекторов
	{ 495	,1	,1	, &lEM_R0IE02LRP},	//(R0IE02LRP) Отключить питание ПР, ПУ
	{ 496	,8	,1	, &fEM_A0UP03RIM},	//(A0UP03RIM) Текущее давление в системе
	{ 497	,8	,1	, &fEM_A2UP02RIM},	//(A2UP02RIM) Текущее давление на подъём РБ
	{ 498	,8	,1	, &fEM_A2UP03RIM},	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
	{ 499	,8	,1	, &fEM_A0UP01RIM},	//(A0UP01RIM) Текущее давление в АЗ1,2
	{ 500	,8	,1	, &fEM_A3UP02RIM},	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
	{ 501	,8	,1	, &fEM_A4UP01RIM},	//(A4UP01RIM) Текущее давление на подъём НИ
	{ 502	,8	,1	, &fEM_A4UP02RIM},	//(A4UP02RIM) Нижняя граница давления на подъём НИ
	{ 503	,8	,1	, &fEM_R7UI76RIM},	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{ 504	,8	,1	, &fEM_R7UI77RIM},	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{ 505	,3	,1	, &iEM_TERBB1},	//(TERBB1) Неисправности  ББ1
	{ 506	,8	,1	, &fEM_A1MC02RC1},	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
	{ 507	,8	,1	, &fEM_A1MV02RC1},	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
	{ 508	,3	,1	, &iEM_TERBB2},	//(TERBB2) Неисправности  ББ2
	{ 509	,8	,1	, &fEM_B1MC02RC1},	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
	{ 510	,8	,1	, &fEM_B1MV02RC1},	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
	{ 511	,3	,1	, &iEM_TERRB2},	//(TERRB2) Неисправности  РБ2
	{ 512	,8	,1	, &fEM_B2MC02RC1},	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
	{ 513	,8	,1	, &fEM_B2MV02RC1},	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
	{ 514	,3	,1	, &iEM_TERRB1},	//(TERRB1) Неисправности  РБ1
	{ 515	,8	,1	, &fEM_A2MC02RC1},	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
	{ 516	,8	,1	, &fEM_A2MV02RC1},	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
	{ 517	,3	,1	, &iEM_TERIS2},	//(TERIS2) Неисправности  ИС2
	{ 518	,8	,1	, &fEM_B3MC02RC1},	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
	{ 519	,8	,1	, &fEM_B3MV02RC1},	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
	{ 520	,3	,1	, &iEM_TERIS1},	//(TERIS1) Неисправности  ИС1
	{ 521	,8	,1	, &fEM_A3MC02RC1},	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
	{ 522	,8	,1	, &fEM_A3MV02RC1},	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
	{ 523	,3	,1	, &iEM_TERA1IE04LDU},	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
	{ 524	,3	,1	, &iEM_TERA1IE03LDU},	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
	{ 525	,8	,1	, &fEM_A1MC01RC1},	//(A1MC01RC1) Заданная координата  ББ1 от ИС
	{ 526	,3	,1	, &iEM_TERB1IE03LDU},	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
	{ 527	,3	,1	, &iEM_TERB1IE04LDU},	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
	{ 528	,8	,1	, &fEM_B1MC01RC1},	//(B1MC01RC1) Заданная координата ББ2 от ИС
	{ 529	,8	,1	, &fEM_B1MV01RC1},	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
	{ 530	,8	,1	, &fEM_B2MC01RC1},	//(B2MC01RC1) Заданная координата РБ2 от ИС
	{ 531	,8	,1	, &fEM_B2MV01RC1},	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
	{ 532	,8	,1	, &fEM_A3MC01RC1},	//(A3MC01RC1) Заданная координата ИС1 от ИС
	{ 533	,8	,1	, &fEM_A3MV01RC1},	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
	{ 534	,8	,1	, &fEM_B3MC01RC1},	//(B3MC01RC1) Заданная координата ИС2 от ИС
	{ 535	,8	,1	, &fEM_B3MV01RC1},	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
	{ 536	,3	,1	, &iEM_TERA2SS21LIM},	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
	{ 537	,3	,1	, &iEM_TERA2SS12LIM},	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
	{ 538	,3	,1	, &iEM_TERR6SS21LIM},	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
	{ 539	,3	,1	, &iEM_TERA2VP82LIM},	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
	{ 540	,3	,1	, &iEM_TERA2SS11LIM},	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
	{ 541	,3	,1	, &iEM_TERB3SS21LIM},	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
	{ 542	,3	,1	, &iEM_TERA0MT01RIM},	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
	{ 543	,3	,1	, &iEM_TERB0MT01RIM},	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
	{ 544	,3	,1	, &iEM_TERA2SP01RIM},	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
	{ 545	,3	,1	, &iEM_TERB2SP01RIM},	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
	{ 546	,3	,1	, &iEM_TERB3SP02RIM},	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{ 547	,3	,1	, &iEM_TERA3SC01RIM},	//(TERA3SC01RIM) Искажение: Координата штока ИС1
	{ 548	,3	,1	, &iEM_TERA3VP81LIM},	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
	{ 549	,3	,1	, &iEM_TERA2SC01RIM},	//(TERA2SC01RIM) Искажение: Координата штока РБ1
	{ 550	,3	,1	, &iEM_TERA2SS33LIM},	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{ 551	,3	,1	, &iEM_TERA3SS21LIM},	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
	{ 552	,3	,1	, &iEM_TERA3SS33LIM},	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{ 553	,3	,1	, &iEM_TERA3SS31LIM},	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{ 554	,3	,1	, &iEM_TERB3SS31LIM},	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{ 555	,3	,1	, &iEM_TERB3SS33LIM},	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{ 556	,3	,1	, &iEM_TERB3SC01RIM},	//(TERB3SC01RIM) Искажение: Координата штока ИС2
	{ 557	,3	,1	, &iEM_TERA3SS11LIM},	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
	{ 558	,3	,1	, &iEM_TERB3SS11LIM},	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
	{ 559	,3	,1	, &iEM_TERR6IS64LIM},	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
	{ 560	,3	,1	, &iEM_TERB3SS22LIM},	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
	{ 561	,3	,1	, &iEM_TERA3SS22LIM},	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
	{ 562	,3	,1	, &iEM_TERA3SP02RIM},	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{ 563	,3	,1	, &iEM_TERR6IS62LIM},	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
	{ 564	,3	,1	, &iEM_TERR6IS66LIM},	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 565	,3	,1	, &iEM_TERR6IS67LIM},	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 566	,3	,1	, &iEM_TERA0VP81LIM},	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
	{ 567	,3	,1	, &iEM_TERB0VP81LIM},	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
	{ 568	,3	,1	, &iEM_TERR0VP81LIM},	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	{ 569	,3	,1	, &iEM_TERR0VP82LIM},	//(TERR0VP82LIM) Искажение: Давление  в СИСТЕМЕ-2 в норме
	{ 570	,3	,1	, &iEM_TERR6IS68LIM},	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
	{ 571	,3	,1	, &iEM_TERR7SI74RIM},	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
	{ 572	,3	,1	, &iEM_TERA5SS21LIM},	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
	{ 573	,3	,1	, &iEM_TERB5SS11LIM},	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
	{ 574	,3	,1	, &iEM_TERA5SS11LIM},	//(TERA5SS11LIM) Искажение: Приход на ВУ НЛ1
	{ 575	,3	,1	, &iEM_TERA9SS11LIM},	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
	{ 576	,3	,1	, &iEM_TERB2SS11LIM},	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
	{ 577	,3	,1	, &iEM_TERB2SS12LIM},	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
	{ 578	,3	,1	, &iEM_TERB2SS21LIM},	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
	{ 579	,3	,1	, &iEM_TERR3SS11LIM},	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
	{ 580	,3	,1	, &iEM_TERB2SC01RIM},	//(TERB2SC01RIM) Искажение: Координата штока РБ2
	{ 581	,3	,1	, &iEM_TERR3SS21LIM},	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
	{ 582	,3	,1	, &iEM_TERR5SS11LIM},	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
	{ 583	,3	,1	, &iEM_TERR3SS12LIM},	//(TERR3SS12LIM) Искажение: Приход на ВУ гомогенных дверей-2
	{ 584	,3	,1	, &iEM_TERR3SS22LIM},	//(TERR3SS22LIM) Искажение: Приход на НУ гомогенных дверей-2
	{ 585	,3	,1	, &iEM_TERA4SS11LIM},	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
	{ 586	,3	,1	, &iEM_TERR1SS11LIM},	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
	{ 587	,3	,1	, &iEM_TERR1SS21LIM},	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
	{ 588	,3	,1	, &iEM_TERR2SS11LIM},	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
	{ 589	,3	,1	, &iEM_TERR2SS21LIM},	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
	{ 590	,3	,1	, &iEM_TERA4VP82LIM},	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
	{ 591	,3	,1	, &iEM_TERB4SS21LIM},	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
	{ 592	,3	,1	, &iEM_TERR5SS21LIM},	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
	{ 593	,3	,1	, &iEM_TERB6SS21LIM},	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
	{ 594	,3	,1	, &iEM_TERB4SS11LIM},	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
	{ 595	,3	,1	, &iEM_TERA4SS21LIM},	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
	{ 596	,3	,1	, &iEM_TERA6MS11LIM},	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
	{ 597	,3	,1	, &iEM_TERA6SS21LIM},	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
	{ 598	,3	,1	, &iEM_TERB6SS11LIM},	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
	{ 599	,3	,1	, &iEM_TERR4SS11LIM},	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
	{ 600	,3	,1	, &iEM_TERR4MS21LIM},	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
	{ 601	,3	,1	, &iEM_TERR4SS12LIM},	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
	{ 602	,3	,1	, &iEM_TERR4SS22LIM},	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
	{ 603	,3	,1	, &iEM_TERR8SS11LIM},	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
	{ 604	,3	,1	, &iEM_TERB8SC01RIM},	//(TERB8SC01RIM) Искажение: Координата АЗ2
	{ 605	,3	,1	, &iEM_TERA8SC01RIM},	//(TERA8SC01RIM) Искажение: Координата ДС2
	{ 606	,3	,1	, &iEM_TERB8SS12LIM},	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
	{ 607	,3	,1	, &iEM_TERA8SS12LIM},	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
	{ 608	,3	,1	, &iEM_TERB8SS22LIM},	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
	{ 609	,3	,1	, &iEM_TERA8SS22LIM},	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
	{ 610	,3	,1	, &iEM_TERA9SS21LIM},	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
	{ 611	,3	,1	, &iEM_TERB9SS21LIM},	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
	{ 612	,3	,1	, &iEM_TERB9SS11LIM},	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
	{ 613	,3	,1	, &iEM_TERB5SS21LIM},	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
	{ 614	,3	,1	, &iEM_TERA1SS21LIM},	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
	{ 615	,3	,1	, &iEM_TERA1SS11LIM},	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
	{ 616	,3	,1	, &iEM_TERA1SC01RIM},	//(TERA1SC01RIM) Искажение: Координата штока ББ1
	{ 617	,3	,1	, &iEM_TERA1SS12LIM},	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
	{ 618	,3	,1	, &iEM_TERB1SS21LIM},	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
	{ 619	,3	,1	, &iEM_TERB1SS11LIM},	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
	{ 620	,3	,1	, &iEM_TERB1MC01RIM},	//(TERB1MC01RIM) Искажение: Координата штока ББ2
	{ 621	,3	,1	, &iEM_TERB1SS12LIM},	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
	{ 622	,3	,1	, &iEM_TERR0IE43LIM},	//(TERR0IE43LIM) Исправность ВИП 0,5 4канала
	{ 623	,3	,1	, &iEM_TERR0IE41LIM},	//(TERR0IE41LIM) Исправность ВИП 1,6 (№17) СНМ11 4канала
	{ 624	,1	,1	, &lEM_A0EE06LC1},	//(A0EE06LC1) Исправность АКНП4 от диагностики контроллера (От ИС)
	{ 625	,3	,1	, &iEM_TERR0IE33LIM},	//(TERR0IE33LIM) Искажение:Исправность ВИП 0,5  3канала
	{ 626	,3	,1	, &iEM_TERR0IE31LIM},	//(TERR0IE31LIM) Искажение: Исправность ВИП 1,6 (№14) СНМ11 3канала
	{ 627	,1	,1	, &lEM_A0EE05LC1},	//(A0EE05LC1) Исправность АКНП3 от диагностики контроллера (От ИС)
	{ 628	,3	,1	, &iEM_TERR0IE11LIM},	//(TERR0IE11LIM) Искажение: Исправность ВИП 1,6 (№8) СНМ11 1канала
	{ 629	,3	,1	, &iEM_TERR0IE13LIM},	//(TERR0IE13LIM) Искажение: Исправность ВИП 0,5  1канала
	{ 630	,1	,1	, &lEM_A0EE03LC1},	//(A0EE03LC1) Исправность АКНП1 от диагностики контроллера (От ИС)
	{ 631	,3	,1	, &iEM_TERR0IE23LIM},	//(TERR0IE23LIM) Искажение: Исправность ВИП 0,5 (№13) КНК53М 2канала
	{ 632	,3	,1	, &iEM_TERR0IE21LIM},	//(TERR0IE21LIM) Искажение: Исправность ВИП 1,6 (№11) СНМ11 2канала
	{ 633	,1	,1	, &lEM_A0EE04LC1},	//(A0EE04LC1) Исправность АКНП2 от диагностики контроллера (От ИС)
	{ 634	,3	,1	, &iEM_TERTLG},	//(TERTLG) Неисправности  тележки от ИС
	{ 635	,8	,1	, &fEM_R4MC01RC1},	//(R4MC01RC1) Заданная координата тележки от ИС
	{ 636	,8	,1	, &fEM_R4MV01RC1},	//(R4MV01RC1) Заданная скорость тележки от ИС
	{ 637	,3	,1	, &iEM_TERMAZ2},	//(TERMAZ2) Неисправности АЗ2 от ИС
	{ 638	,8	,1	, &fEM_B8MC01RC1},	//(B8MC01RC1) аданная координата АЗ2 от ИС
	{ 639	,8	,1	, &fEM_B8MV01RC1},	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
	{ 640	,3	,1	, &iEM_TERDS2},	//(TERDS2) Неисправности ДС2 от ИС
	{ 641	,8	,1	, &fEM_A8MC01RC1},	//(A8MC01RC1) Заданная координата ДС2 от ИС
	{ 642	,8	,1	, &fEM_A8MV01RC1},	//(A8MV01RC1) Заданная скорость ДС2 от ИС
	{ 643	,3	,1	, &iEM_TERBZ1},	//(TERBZ1) Неисправности БЗ1
	{ 644	,8	,1	, &fEM_A6MC01RC1},	//(A6MC01RC1) Заданная координата БЗ1 от ИС
	{ 645	,8	,1	, &fEM_A6MV01RC1},	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
	{ 646	,3	,1	, &iEM_TERBZ2},	//(TERBZ2) Неисправности БЗ2
	{ 647	,8	,1	, &fEM_B6MC01RC1},	//(B6MC01RC1) Заданная координата БЗ2 от ИС
	{ 648	,8	,1	, &fEM_B6MV01RC1},	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
	{ 649	,3	,1	, &iEM_TERR3AD10LDU},	//(TERR3AD10LDU) Искажение: Гомогенные двери-1 открыть
	{ 650	,3	,1	, &iEM_TERR3AD20LDU},	//(TERR3AD20LDU) Искажение: Гомогенные двери-1 закрыть
	{ 651	,3	,1	, &iEM_TERR3AD11LDU},	//(TERR3AD11LDU) Искажение: Гомогенные двери-2 открыть
	{ 652	,3	,1	, &iEM_TERR3AD21LDU},	//(TERR3AD21LDU) Искажение: Гомогенные двери-2 закрыть
	{ 653	,3	,1	, &iEM_TERR5AD10LDU},	//(TERR5AD10LDU) Искажение: Открыть ворота отстойной зоны
	{ 654	,3	,1	, &iEM_TERR5AD20LDU},	//(TERR5AD20LDU) Искажение: Закрыть ворота отстойной зоны
	{ 655	,1	,1	, &lEM_R3AD10LC1},	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
	{ 656	,1	,1	, &lEM_R3AD20LC1},	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
	{ 657	,1	,1	, &lEM_R3AD11LC1},	//(R3AD11LC1) Гомогенные двери-2 открыть от ИС
	{ 658	,1	,1	, &lEM_R3AD21LC1},	//(R3AD21LC1) Гомогенные двери-2 закрыть от ИС
	{ 659	,1	,1	, &lEM_R6AD10LC1},	//(R6AD10LC1) Выкатить кран-балку от ИС
	{ 660	,1	,1	, &lEM_R5AD10LC1},	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
	{ 661	,1	,1	, &lEM_R5AD20LC1},	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
	{ 662	,3	,1	, &iEM_TERMDZ2},	//(TERMDZ2) Неисправности МДЗ2
	{ 663	,8	,1	, &fEM_R2MC01RC1},	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
	{ 664	,8	,1	, &fEM_R2MV01RC1},	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
	{ 665	,3	,1	, &iEM_TERMDZ1},	//(TERMDZ1) Неисправности МДЗ1
	{ 666	,8	,1	, &fEM_R1MC01RC1},	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
	{ 667	,8	,1	, &fEM_R1MV01RC1},	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
	{ 668	,3	,1	, &iEM_TERNL1},	//(TERNL1) Неисправности НЛ1
	{ 669	,8	,1	, &fEM_A5MC01RC1},	//(A5MC01RC1) Заданная координата НЛ1 от ИС
	{ 670	,8	,1	, &fEM_A5MV01RC1},	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
	{ 671	,3	,1	, &iEM_TERNL2},	//(TERNL2) Неисправности НЛ2
	{ 672	,8	,1	, &fEM_B5MC01RC1},	//(B5MC01RC1) Заданная координата НЛ2 от ИС
	{ 673	,8	,1	, &fEM_B5MV01RC1},	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
	{ 674	,1	,1	, &lEM_R8AD10LC1},	//(R8AD10LC1) Установить аварийный НИ от ИС
	{ 675	,8	,1	, &fEM_A1UC08RIM},	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
	{ 676	,8	,1	, &fEM_A2UC08RIM},	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
	{ 677	,8	,1	, &fEM_A3UC08RIM},	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
	{ 678	,8	,1	, &fEM_R0UL01RSS},	//(R0UL01RSS) Шаг (мс) измерения периода
	{ 679	,8	,1	, &fEM_R0UL03RSS},	//(R0UL03RSS) Предельное время ожидания роста потока (сек)
	{ 680	,3	,1	, &iEM_TERB2SS33LIM},	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{ 681	,3	,1	, &iEM_TERA1VP81LIM},	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
	{ 682	,3	,1	, &iEM_TERB1VP81LIM},	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
	{ 683	,8	,1	, &fEM_A0UT03RSP},	//(A0UT03RSP) Стартовая  температура АЗ1 град
	{ 684	,8	,1	, &fEM_A0UR01RSP},	//(A0UR01RSP) Стартовая  реактивность АЗ1
	{ 685	,8	,1	, &fEM_A0UR02RSP},	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
	{ 686	,8	,1	, &fEM_B0UT03RSP},	//(B0UT03RSP) Стартовая  температура АЗ2 град
	{ 687	,8	,1	, &fEM_A1MC01RSP},	//(A1MC01RSP) Стартовая координата  ББ1
	{ 688	,8	,1	, &fEM_A1MC02RSP},	//(A1MC02RSP) Стартовая координата штока ББ1
	{ 689	,8	,1	, &fEM_A1MV01RSP},	//(A1MV01RSP) Стартовая скорость движения  ББ1
	{ 690	,8	,1	, &fEM_A1MV02RSP},	//(A1MV02RSP) Стартовая скорость движения  ББ1
	{ 691	,8	,1	, &fEM_B1MC01RSP},	//(B1MC01RSP) Стартовая координата  ББ2
	{ 692	,8	,1	, &fEM_B1MV01RSP},	//(B1MV01RSP) Стартовая скорость движения  ББ2
	{ 693	,8	,1	, &fEM_B1MC02RSP},	//(B1MC02RSP) Стартовая координата штока ББ2
	{ 694	,8	,1	, &fEM_B1MV02RSP},	//(B1MV02RSP) Стартовая скорость движения  ББ2
	{ 695	,8	,1	, &fEM_A2MC01RC1},	//(A2MC01RC1) Заданная координата РБ1 от ИС
	{ 696	,8	,1	, &fEM_A2MV01RC1},	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
	{ 697	,8	,1	, &fEM_A2MC01RSP},	//(A2MC01RSP) Стартовая координата  РБ1
	{ 698	,8	,1	, &fEM_A2MV01RSP},	//(A2MV01RSP) Стартовая скорость движения  РБ1
	{ 699	,8	,1	, &fEM_A2MC02RSP},	//(A2MC02RSP) Стартовая координата штока РБ1
	{ 700	,8	,1	, &fEM_A2MV02RSP},	//(A2MV02RSP) Стартовая скорость движения  РБ1
	{ 701	,8	,1	, &fEM_B2MC01RSP},	//(B2MC01RSP) Стартовая координата  РБ2
	{ 702	,8	,1	, &fEM_B2MV01RSP},	//(B2MV01RSP) Стартовая скорость движения  РБ2
	{ 703	,8	,1	, &fEM_B2MC02RSP},	//(B2MC02RSP) Стартовая координата штока РБ2
	{ 704	,8	,1	, &fEM_B2MV02RSP},	//(B2MV02RSP) Стартовая скорость движения  РБ2
	{ 705	,8	,1	, &fEM_A3MC01RSP},	//(A3MC01RSP) Стартовая координата  ИС1
	{ 706	,8	,1	, &fEM_A3MV01RSP},	//(A3MV01RSP) Стартовая скорость движения  ИС1
	{ 707	,8	,1	, &fEM_A3MC02RSP},	//(A3MC02RSP) Стартовая координата штока ИС1
	{ 708	,8	,1	, &fEM_A3MV02RSP},	//(A3MV02RSP) Стартовая скорость движения  ИС1
	{ 709	,8	,1	, &fEM_B3MC01RSP},	//(B3MC01RSP) Стартовая координата  ИС2
	{ 710	,8	,1	, &fEM_B3MV01RSP},	//(B3MV01RSP) Стартовая скорость движения  ИС2
	{ 711	,8	,1	, &fEM_B3MC02RSP},	//(B3MC02RSP) Стартовая координата штока ИС2
	{ 712	,8	,1	, &fEM_B3MV02RSP},	//(B3MV02RSP) Стартовая скорость движения  ИС2
	{ 713	,8	,1	, &fEM_B8MC01RSP},	//(B8MC01RSP) Стартовая координата АЗ2
	{ 714	,8	,1	, &fEM_B8MV01RSP},	//(B8MV01RSP) Стартовая скорость АЗ2
	{ 715	,8	,1	, &fEM_A8MC01RSP},	//(A8MC01RSP) Стартовая координата ДС2
	{ 716	,8	,1	, &fEM_A8MV01RSP},	//(A8MV01RSP) Стартовая скорость ДС2
	{ 717	,8	,1	, &fEM_A6MC01RSP},	//(A6MC01RSP) Стартовая координата БЗ1
	{ 718	,8	,1	, &fEM_A6MV01RSP},	//(A6MV01RSP) Стартовая скорость БЗ1
	{ 719	,8	,1	, &fEM_B6MC01RSP},	//(B6MC01RSP) Стартовая координата БЗ2
	{ 720	,8	,1	, &fEM_B6MV01RSP},	//(B6MV01RSP) Стартовая скорость БЗ2
	{ 721	,8	,1	, &fEM_R3UC01RSP},	//(R3UC01RSP) Стартовая координата Гомогенных дверей - 1
	{ 722	,8	,1	, &fEM_R3UV01RSP},	//(R3UV01RSP) Стартовая скорость Гомогенных дверей-1
	{ 723	,8	,1	, &fEM_R3UC02RSP},	//(R3UC02RSP) Стартовая координата Гомогенных дверей - 2
	{ 724	,8	,1	, &fEM_R3UV02RSP},	//(R3UV02RSP) Стартовая скорость Гомогенных дверей-2
	{ 725	,8	,1	, &fEM_R5UC01RSP},	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
	{ 726	,8	,1	, &fEM_R5UV01RSP},	//(R5UV01RSP) Стартовая скорость Ворот отстойной зоны
	{ 727	,8	,1	, &fEM_R6UC01RSP},	//(R6UC01RSP) Стартовая координата Кран-балки
	{ 728	,8	,1	, &fEM_R6UV01RSP},	//(R6UV01RSP) Стартовая скорость Кран-балки
	{ 729	,8	,1	, &fEM_R2MC01RSP},	//(R2MC01RSP) Стартовая координата МДЗ2
	{ 730	,8	,1	, &fEM_R2MV01RSP},	//(R2MV01RSP) Стартовая скорость МДЗ2
	{ 731	,8	,1	, &fEM_R1MC01RSP},	//(R1MC01RSP) Стартовая координата МДЗ1
	{ 732	,8	,1	, &fEM_R1MV01RSP},	//(R1MV01RSP) Стартовая скорость МДЗ1
	{ 733	,8	,1	, &fEM_A5MC01RSP},	//(A5MC01RSP) Стартовая координата НЛ1
	{ 734	,8	,1	, &fEM_A5MV01RSP},	//(A5MV01RSP) Стартовая скорость НЛ1
	{ 735	,8	,1	, &fEM_B5MC01RSP},	//(B5MC01RSP) Стартовая координата НЛ2
	{ 736	,8	,1	, &fEM_B5MV01RSP},	//(B5MV01RSP) Стартовая скорость НЛ2
	{ 737	,8	,1	, &fEM_A9MC01RSP},	//(A9MC01RSP) Стартовая координата НИ ДС1
	{ 738	,8	,1	, &fEM_A9MV01RSP},	//(A9MV01RSP) Стартовая скорость НИ ДС1
	{ 739	,8	,1	, &fEM_B9MC01RSP},	//(B9MC01RSP) Стартовая координата НИ ДС2
	{ 740	,8	,1	, &fEM_B9MV01RSP},	//(B9MV01RSP) Стартовая скорость НИ ДС2
	{ 741	,8	,1	, &fEM_A4MC01RSP},	//(A4MC01RSP) Стартовая координата НИ1
	{ 742	,8	,1	, &fEM_A4MV01RSP},	//(A4MV01RSP) Стартовая скорость НИ1
	{ 743	,8	,1	, &fEM_B4MC01RSP},	//(B4MC01RSP) Стартовая координата НИ2
	{ 744	,8	,1	, &fEM_B4MV01RSP},	//(B4MV01RSP) Стартовая скорость НИ2
	{ 745	,8	,1	, &fEM_R4MC01RSP},	//(R4MC01RSP) Стартовая координата тележки
	{ 746	,8	,1	, &fEM_R4MV01RSP},	//(R4MV01RSP) Стартовая скорость тележки
	{ 747	,8	,1	, &fEM_A1MV01RC1},	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
	{ 748	,3	,1	, &iEM_TERB7MS31LIM},	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	{ 749	,3	,1	, &iEM_TERA7MS31LIM},	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{ 750	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 751	,1	,1	, &internal1_m563_Out10},	//(internal1_m563_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 752	,1	,1	, &internal1_m582_Out10},	//(internal1_m582_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 753	,1	,1	, &internal1_m417_Out10},	//(internal1_m417_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 754	,1	,1	, &internal1_m514_q0},	//(internal1_m514_q0) q0 - внутренний параметр
	{ 755	,1	,1	, &internal1_m515_q0},	//(internal1_m515_q0) q0 - внутренний параметр
	{ 756	,1	,1	, &internal1_m484_q0},	//(internal1_m484_q0) q0 - внутренний параметр
	{ 757	,1	,1	, &internal1_m485_q0},	//(internal1_m485_q0) q0 - внутренний параметр
	{ 758	,1	,1	, &internal1_m486_q0},	//(internal1_m486_q0) q0 - внутренний параметр
	{ 759	,1	,1	, &internal1_m487_q0},	//(internal1_m487_q0) q0 - внутренний параметр
	{ 760	,8	,1	, &internal1_m689_tx},	//(internal1_m689_tx) tx - время накопленное сек
	{ 761	,18	,1	, &internal1_m689_y0},	//(internal1_m689_y0) y0
	{ 762	,8	,1	, &internal1_m677_tx},	//(internal1_m677_tx) tx - время накопленное сек
	{ 763	,18	,1	, &internal1_m677_y0},	//(internal1_m677_y0) y0
	{ 764	,1	,1	, &internal1_m517_Out10},	//(internal1_m517_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 765	,1	,1	, &internal1_m491_Out10},	//(internal1_m491_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 766	,1	,1	, &internal1_m490_Out10},	//(internal1_m490_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 767	,1	,1	, &internal1_m489_Out10},	//(internal1_m489_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 768	,1	,1	, &internal1_m488_Out10},	//(internal1_m488_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 769	,1	,1	, &internal1_m516_Out10},	//(internal1_m516_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 770	,8	,1	, &internal1_m663_tx},	//(internal1_m663_tx) tx - время накопленное сек
	{ 771	,18	,1	, &internal1_m663_y0},	//(internal1_m663_y0) y0
	{ 772	,8	,1	, &internal1_m661_tx},	//(internal1_m661_tx) tx - время накопленное сек
	{ 773	,18	,1	, &internal1_m661_y0},	//(internal1_m661_y0) y0
	{ 774	,1	,1	, &internal1_m206_Out10},	//(internal1_m206_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 775	,1	,1	, &internal1_m223_Out10},	//(internal1_m223_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 776	,1	,1	, &internal1_m41_Out10},	//(internal1_m41_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 777	,1	,1	, &internal1_m56_Out10},	//(internal1_m56_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 778	,1	,1	, &internal1_m1258_Out10},	//(internal1_m1258_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 779	,1	,1	, &internal1_m1255_Out10},	//(internal1_m1255_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 780	,1	,1	, &internal1_m1254_Out10},	//(internal1_m1254_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 781	,8	,1	, &internal1_m1257_Xtek0},	//(internal1_m1257_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 782	,8	,1	, &internal1_m1243_Xtek0},	//(internal1_m1243_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 783	,1	,1	, &internal1_m1244_Out10},	//(internal1_m1244_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 784	,1	,1	, &internal1_m1241_Out10},	//(internal1_m1241_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 785	,1	,1	, &internal1_m1240_Out10},	//(internal1_m1240_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 786	,1	,1	, &internal1_m965_Out10},	//(internal1_m965_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 787	,1	,1	, &internal1_m986_Out10},	//(internal1_m986_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 788	,1	,1	, &internal1_m985_Out10},	//(internal1_m985_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 789	,1	,1	, &internal1_m984_Out10},	//(internal1_m984_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 790	,1	,1	, &internal1_m1150_Out10},	//(internal1_m1150_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 791	,1	,1	, &internal1_m1152_Out10},	//(internal1_m1152_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 792	,1	,1	, &internal1_m1149_Out10},	//(internal1_m1149_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 793	,1	,1	, &internal1_m1151_Out10},	//(internal1_m1151_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 794	,1	,1	, &internal1_m1129_Out10},	//(internal1_m1129_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 795	,1	,1	, &internal1_m1130_Out10},	//(internal1_m1130_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 796	,1	,1	, &internal1_m1128_Out10},	//(internal1_m1128_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 797	,1	,1	, &internal1_m1127_Out10},	//(internal1_m1127_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 798	,1	,1	, &internal1_m962_Out10},	//(internal1_m962_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 799	,1	,1	, &internal1_m961_Out10},	//(internal1_m961_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 800	,1	,1	, &internal1_m941_Out10},	//(internal1_m941_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 801	,1	,1	, &internal1_m945_Out10},	//(internal1_m945_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 802	,1	,1	, &internal1_m944_Out10},	//(internal1_m944_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 803	,1	,1	, &internal1_m943_Out10},	//(internal1_m943_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 804	,1	,1	, &internal1_m942_Out10},	//(internal1_m942_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 805	,1	,1	, &internal1_m963_Out10},	//(internal1_m963_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 806	,1	,1	, &internal1_m982_Out10},	//(internal1_m982_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 807	,1	,1	, &internal1_m1131_Out10},	//(internal1_m1131_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 808	,1	,1	, &internal1_m983_Out10},	//(internal1_m983_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 809	,1	,1	, &internal1_m981_Out10},	//(internal1_m981_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 810	,1	,1	, &internal1_m964_Out10},	//(internal1_m964_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 811	,1	,1	, &internal1_m980_Out10},	//(internal1_m980_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 812	,1	,1	, &internal1_m960_Out10},	//(internal1_m960_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 813	,1	,1	, &internal1_m940_Out10},	//(internal1_m940_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 814	,1	,1	, &internal1_m580_Out10},	//(internal1_m580_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 815	,8	,1	, &internal1_m427_Xtek0},	//(internal1_m427_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 816	,1	,1	, &internal1_m418_Out10},	//(internal1_m418_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 817	,1	,1	, &internal1_m420_Out10},	//(internal1_m420_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 818	,1	,1	, &internal1_m419_Out10},	//(internal1_m419_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 819	,1	,1	, &internal1_m1164_Out10},	//(internal1_m1164_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 820	,1	,1	, &internal1_m1165_Out10},	//(internal1_m1165_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 821	,1	,1	, &internal1_m1163_Out10},	//(internal1_m1163_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 822	,1	,1	, &internal1_m1001_Out10},	//(internal1_m1001_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 823	,1	,1	, &internal1_m1166_Out10},	//(internal1_m1166_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 824	,1	,1	, &internal1_m999_Out10},	//(internal1_m999_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 825	,1	,1	, &internal1_m998_Out10},	//(internal1_m998_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 826	,1	,1	, &internal1_m1000_Out10},	//(internal1_m1000_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 827	,1	,1	, &internal1_m603_Out10},	//(internal1_m603_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 828	,1	,1	, &internal1_m601_Out10},	//(internal1_m601_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 829	,1	,1	, &internal1_m600_Out10},	//(internal1_m600_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 830	,1	,1	, &internal1_m602_Out10},	//(internal1_m602_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 831	,8	,1	, &internal1_m1146_Xtek0},	//(internal1_m1146_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 832	,8	,1	, &internal1_m1148_Xtek0},	//(internal1_m1148_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 833	,1	,1	, &internal1_m722_Out10},	//(internal1_m722_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 834	,1	,1	, &internal1_m717_Out10},	//(internal1_m717_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 835	,1	,1	, &internal1_m708_Out10},	//(internal1_m708_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 836	,1	,1	, &internal1_m716_Out10},	//(internal1_m716_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 837	,1	,1	, &internal1_m707_Out10},	//(internal1_m707_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 838	,1	,1	, &internal1_m343_Out10},	//(internal1_m343_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 839	,1	,1	, &internal1_m342_Out10},	//(internal1_m342_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 840	,1	,1	, &internal1_m323_Out10},	//(internal1_m323_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 841	,1	,1	, &internal1_m322_Out10},	//(internal1_m322_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 842	,1	,1	, &internal1_m604_Out10},	//(internal1_m604_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 843	,1	,1	, &internal1_m358_Out10},	//(internal1_m358_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 844	,8	,1	, &internal1_m340_Xtek0},	//(internal1_m340_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 845	,1	,1	, &internal1_m357_Out10},	//(internal1_m357_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 846	,1	,1	, &internal1_m355_Out10},	//(internal1_m355_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 847	,8	,1	, &internal1_m330_Xtek0},	//(internal1_m330_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 848	,1	,1	, &internal1_m356_Out10},	//(internal1_m356_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 849	,1	,1	, &internal1_m321_Out10},	//(internal1_m321_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 850	,1	,1	, &internal1_m341_Out10},	//(internal1_m341_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 851	,1	,1	, &internal1_m439_Out10},	//(internal1_m439_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 852	,8	,1	, &internal1_m440_Xtek0},	//(internal1_m440_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 853	,1	,1	, &internal1_m438_Out10},	//(internal1_m438_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 854	,1	,1	, &internal1_m437_Out10},	//(internal1_m437_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 855	,1	,1	, &internal1_m436_Out10},	//(internal1_m436_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 856	,1	,1	, &internal1_m946_Out10},	//(internal1_m946_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 857	,1	,1	, &internal1_m150_Out10},	//(internal1_m150_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 858	,1	,1	, &internal1_m149_Out10},	//(internal1_m149_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 859	,1	,1	, &internal1_m1119_Out10},	//(internal1_m1119_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 860	,1	,1	, &internal1_m1110_Out10},	//(internal1_m1110_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 861	,8	,2	, &internal1_m1099_tst},	//(internal1_m1099_tst) - массив времени фиксации стартовой мощности
	{ 862	,8	,2	, &internal1_m1099_trz},	//(internal1_m1099_trz) - массив времени фиксации очередного периода
	{ 863	,8	,2	, &internal1_m1099_N1},	//(internal1_m1099_N1) - массив значения мощности в начале замера
	{ 864	,8	,2	, &internal1_m1099_N2},	//(internal1_m1099_N2) - массив значения мощности в конце замера
	{ 865	,8	,1	, &internal1_m1099_Period0},	//(internal1_m1099_Period0) Per - Период разгона РУ
	{ 866	,1	,1	, &internal1_m1099_MyFirstEnterFlag},	//(internal1_m1099_MyFirstEnterFlag)  FirstEnterFlag
	{ 867	,3	,1	, &internal1_m1065_Nk},	//(internal1_m1065_Nk) Nk - ведущая камера
	{ 868	,1	,1	, &internal1_m1060_Out10},	//(internal1_m1060_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 869	,1	,1	, &internal1_m1052_Out10},	//(internal1_m1052_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 870	,8	,2	, &internal1_m1041_tst},	//(internal1_m1041_tst) - массив времени фиксации стартовой мощности
	{ 871	,8	,2	, &internal1_m1041_trz},	//(internal1_m1041_trz) - массив времени фиксации очередного периода
	{ 872	,8	,2	, &internal1_m1041_N1},	//(internal1_m1041_N1) - массив значения мощности в начале замера
	{ 873	,8	,2	, &internal1_m1041_N2},	//(internal1_m1041_N2) - массив значения мощности в конце замера
	{ 874	,8	,1	, &internal1_m1041_Period0},	//(internal1_m1041_Period0) Per - Период разгона РУ
	{ 875	,1	,1	, &internal1_m1041_MyFirstEnterFlag},	//(internal1_m1041_MyFirstEnterFlag)  FirstEnterFlag
	{ 876	,3	,1	, &internal1_m1011_Nk},	//(internal1_m1011_Nk) Nk - ведущая камера
	{ 877	,1	,1	, &internal1_m929_Out10},	//(internal1_m929_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 878	,1	,1	, &internal1_m919_Out10},	//(internal1_m919_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 879	,8	,2	, &internal1_m910_tst},	//(internal1_m910_tst) - массив времени фиксации стартовой мощности
	{ 880	,8	,2	, &internal1_m910_trz},	//(internal1_m910_trz) - массив времени фиксации очередного периода
	{ 881	,8	,2	, &internal1_m910_N1},	//(internal1_m910_N1) - массив значения мощности в начале замера
	{ 882	,8	,2	, &internal1_m910_N2},	//(internal1_m910_N2) - массив значения мощности в конце замера
	{ 883	,8	,1	, &internal1_m910_Period0},	//(internal1_m910_Period0) Per - Период разгона РУ
	{ 884	,1	,1	, &internal1_m910_MyFirstEnterFlag},	//(internal1_m910_MyFirstEnterFlag)  FirstEnterFlag
	{ 885	,3	,1	, &internal1_m876_Nk},	//(internal1_m876_Nk) Nk - ведущая камера
	{ 886	,1	,1	, &internal1_m863_Out10},	//(internal1_m863_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 887	,1	,1	, &internal1_m852_Out10},	//(internal1_m852_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 888	,8	,2	, &internal1_m855_tst},	//(internal1_m855_tst) - массив времени фиксации стартовой мощности
	{ 889	,8	,2	, &internal1_m855_trz},	//(internal1_m855_trz) - массив времени фиксации очередного периода
	{ 890	,8	,2	, &internal1_m855_N1},	//(internal1_m855_N1) - массив значения мощности в начале замера
	{ 891	,8	,2	, &internal1_m855_N2},	//(internal1_m855_N2) - массив значения мощности в конце замера
	{ 892	,8	,1	, &internal1_m855_Period0},	//(internal1_m855_Period0) Per - Период разгона РУ
	{ 893	,1	,1	, &internal1_m855_MyFirstEnterFlag},	//(internal1_m855_MyFirstEnterFlag)  FirstEnterFlag
	{ 894	,3	,1	, &internal1_m818_Nk},	//(internal1_m818_Nk) Nk - ведущая камера
	{ 895	,3	,1	, &internal1_m195_tx},	//(internal1_m195_tx) tx - внутренний параметр
	{ 896	,3	,1	, &internal1_m25_tx},	//(internal1_m25_tx) tx - внутренний параметр
	{ 897	,1	,1	, &internal1_m499_Pav0},	//(internal1_m499_Pav0)  - Пер.аварийный выключатель механизма
	{ 898	,1	,1	, &internal1_m499_Zav0},	//(internal1_m499_Zav0)  - Зад.аварийный выключатель механизма
	{ 899	,1	,1	, &internal1_m499_Pv0},	//(internal1_m499_Pv0)  - Пер. выключатель механизма
	{ 900	,1	,1	, &internal1_m499_Zv0},	//(internal1_m499_Zv0)  - Зад. выключатель механизма
	{ 901	,1	,1	, &internal1_m499_RA00},	//(internal1_m499_RA00)  - последнее задание вперед
	{ 902	,1	,1	, &internal1_m499_RA10},	//(internal1_m499_RA10)  - последнее задание назад
	{ 903	,1	,1	, &internal1_m499_MyFirstEnterFlag},	//(internal1_m499_MyFirstEnterFlag) MyFirstEnterFlag
	{ 904	,1	,1	, &internal1_m526_Pav0},	//(internal1_m526_Pav0)  - Пер.аварийный выключатель механизма
	{ 905	,1	,1	, &internal1_m526_Zav0},	//(internal1_m526_Zav0)  - Зад.аварийный выключатель механизма
	{ 906	,1	,1	, &internal1_m526_Pv0},	//(internal1_m526_Pv0)  - Пер. выключатель механизма
	{ 907	,1	,1	, &internal1_m526_Zv0},	//(internal1_m526_Zv0)  - Зад. выключатель механизма
	{ 908	,1	,1	, &internal1_m526_RA00},	//(internal1_m526_RA00)  - последнее задание вперед
	{ 909	,1	,1	, &internal1_m526_RA10},	//(internal1_m526_RA10)  - последнее задание назад
	{ 910	,1	,1	, &internal1_m526_MyFirstEnterFlag},	//(internal1_m526_MyFirstEnterFlag) MyFirstEnterFlag
	{ 911	,1	,1	, &internal1_m522_Pav0},	//(internal1_m522_Pav0)  - Пер.аварийный выключатель механизма
	{ 912	,1	,1	, &internal1_m522_Zav0},	//(internal1_m522_Zav0)  - Зад.аварийный выключатель механизма
	{ 913	,1	,1	, &internal1_m522_Pv0},	//(internal1_m522_Pv0)  - Пер. выключатель механизма
	{ 914	,1	,1	, &internal1_m522_Zv0},	//(internal1_m522_Zv0)  - Зад. выключатель механизма
	{ 915	,1	,1	, &internal1_m522_RA00},	//(internal1_m522_RA00)  - последнее задание вперед
	{ 916	,1	,1	, &internal1_m522_RA10},	//(internal1_m522_RA10)  - последнее задание назад
	{ 917	,1	,1	, &internal1_m522_MyFirstEnterFlag},	//(internal1_m522_MyFirstEnterFlag) MyFirstEnterFlag
	{ 918	,1	,1	, &internal1_m494_Pav0},	//(internal1_m494_Pav0)  - Пер.аварийный выключатель механизма
	{ 919	,1	,1	, &internal1_m494_Zav0},	//(internal1_m494_Zav0)  - Зад.аварийный выключатель механизма
	{ 920	,1	,1	, &internal1_m494_Pv0},	//(internal1_m494_Pv0)  - Пер. выключатель механизма
	{ 921	,1	,1	, &internal1_m494_Zv0},	//(internal1_m494_Zv0)  - Зад. выключатель механизма
	{ 922	,1	,1	, &internal1_m494_RA00},	//(internal1_m494_RA00)  - последнее задание вперед
	{ 923	,1	,1	, &internal1_m494_RA10},	//(internal1_m494_RA10)  - последнее задание назад
	{ 924	,1	,1	, &internal1_m494_MyFirstEnterFlag},	//(internal1_m494_MyFirstEnterFlag) MyFirstEnterFlag
	{ 925	,1	,1	, &internal1_m666_Pav0},	//(internal1_m666_Pav0)  - Пер.аварийный выключатель механизма
	{ 926	,1	,1	, &internal1_m666_Zav0},	//(internal1_m666_Zav0)  - Зад.аварийный выключатель механизма
	{ 927	,1	,1	, &internal1_m666_Pv0},	//(internal1_m666_Pv0)  - Пер. выключатель механизма
	{ 928	,1	,1	, &internal1_m666_Zv0},	//(internal1_m666_Zv0)  - Зад. выключатель механизма
	{ 929	,1	,1	, &internal1_m666_RA00},	//(internal1_m666_RA00)  - последнее задание вперед
	{ 930	,1	,1	, &internal1_m666_RA10},	//(internal1_m666_RA10)  - последнее задание назад
	{ 931	,1	,1	, &internal1_m666_MyFirstEnterFlag},	//(internal1_m666_MyFirstEnterFlag) MyFirstEnterFlag
	{ 932	,1	,1	, &internal1_m665_Pav0},	//(internal1_m665_Pav0)  - Пер.аварийный выключатель механизма
	{ 933	,1	,1	, &internal1_m665_Zav0},	//(internal1_m665_Zav0)  - Зад.аварийный выключатель механизма
	{ 934	,1	,1	, &internal1_m665_Pv0},	//(internal1_m665_Pv0)  - Пер. выключатель механизма
	{ 935	,1	,1	, &internal1_m665_Zv0},	//(internal1_m665_Zv0)  - Зад. выключатель механизма
	{ 936	,1	,1	, &internal1_m665_RA00},	//(internal1_m665_RA00)  - последнее задание вперед
	{ 937	,1	,1	, &internal1_m665_RA10},	//(internal1_m665_RA10)  - последнее задание назад
	{ 938	,1	,1	, &internal1_m665_MyFirstEnterFlag},	//(internal1_m665_MyFirstEnterFlag) MyFirstEnterFlag
	{ 939	,1	,1	, &internal1_m651_Pav0},	//(internal1_m651_Pav0)  - Пер.аварийный выключатель механизма
	{ 940	,1	,1	, &internal1_m651_Zav0},	//(internal1_m651_Zav0)  - Зад.аварийный выключатель механизма
	{ 941	,1	,1	, &internal1_m651_Pv0},	//(internal1_m651_Pv0)  - Пер. выключатель механизма
	{ 942	,1	,1	, &internal1_m651_Zv0},	//(internal1_m651_Zv0)  - Зад. выключатель механизма
	{ 943	,1	,1	, &internal1_m651_RA00},	//(internal1_m651_RA00)  - последнее задание вперед
	{ 944	,1	,1	, &internal1_m651_RA10},	//(internal1_m651_RA10)  - последнее задание назад
	{ 945	,1	,1	, &internal1_m651_MyFirstEnterFlag},	//(internal1_m651_MyFirstEnterFlag) MyFirstEnterFlag
	{ 946	,1	,1	, &internal1_m650_Pav0},	//(internal1_m650_Pav0)  - Пер.аварийный выключатель механизма
	{ 947	,1	,1	, &internal1_m650_Zav0},	//(internal1_m650_Zav0)  - Зад.аварийный выключатель механизма
	{ 948	,1	,1	, &internal1_m650_Pv0},	//(internal1_m650_Pv0)  - Пер. выключатель механизма
	{ 949	,1	,1	, &internal1_m650_Zv0},	//(internal1_m650_Zv0)  - Зад. выключатель механизма
	{ 950	,1	,1	, &internal1_m650_RA00},	//(internal1_m650_RA00)  - последнее задание вперед
	{ 951	,1	,1	, &internal1_m650_RA10},	//(internal1_m650_RA10)  - последнее задание назад
	{ 952	,1	,1	, &internal1_m650_MyFirstEnterFlag},	//(internal1_m650_MyFirstEnterFlag) MyFirstEnterFlag
	{ 953	,8	,1	, &internal1_m697_y0},	//(internal1_m697_y0) y0 - внутренний параметр
	{ 954	,8	,1	, &internal1_m812_Chim0},	//(internal1_m812_Chim0) измеренная частота импульсов камеры Гц
	{ 955	,8	,1	, &internal1_m804_Chim0},	//(internal1_m804_Chim0) измеренная частота импульсов камеры Гц
	{ 956	,8	,1	, &internal1_m797_Chim0},	//(internal1_m797_Chim0) измеренная частота импульсов камеры Гц
	{ 957	,8	,1	, &internal1_m789_Chim0},	//(internal1_m789_Chim0) измеренная частота импульсов камеры Гц
	{ 958	,8	,1	, &internal1_m781_Chim0},	//(internal1_m781_Chim0) измеренная частота импульсов камеры Гц
	{ 959	,8	,1	, &internal1_m774_Chim0},	//(internal1_m774_Chim0) измеренная частота импульсов камеры Гц
	{ 960	,8	,1	, &internal1_m766_Chim0},	//(internal1_m766_Chim0) измеренная частота импульсов камеры Гц
	{ 961	,8	,1	, &internal1_m758_Chim0},	//(internal1_m758_Chim0) измеренная частота импульсов камеры Гц
	{ 962	,8	,1	, &internal1_m751_Chim0},	//(internal1_m751_Chim0) измеренная частота импульсов камеры Гц
	{ 963	,8	,1	, &internal1_m743_Chim0},	//(internal1_m743_Chim0) измеренная частота импульсов камеры Гц
	{ 964	,8	,1	, &internal1_m735_Chim0},	//(internal1_m735_Chim0) измеренная частота импульсов камеры Гц
	{ 965	,8	,1	, &internal1_m728_Chim0},	//(internal1_m728_Chim0) измеренная частота импульсов камеры Гц
	{ 966	,1	,1	, &internal1_m637_Pav0},	//(internal1_m637_Pav0)  - Пер.аварийный выключатель механизма
	{ 967	,1	,1	, &internal1_m637_Zav0},	//(internal1_m637_Zav0)  - Зад.аварийный выключатель механизма
	{ 968	,1	,1	, &internal1_m637_Pv0},	//(internal1_m637_Pv0)  - Пер. выключатель механизма
	{ 969	,1	,1	, &internal1_m637_Zv0},	//(internal1_m637_Zv0)  - Зад. выключатель механизма
	{ 970	,1	,1	, &internal1_m637_RA00},	//(internal1_m637_RA00)  - последнее задание вперед
	{ 971	,1	,1	, &internal1_m637_RA10},	//(internal1_m637_RA10)  - последнее задание назад
	{ 972	,1	,1	, &internal1_m637_MyFirstEnterFlag},	//(internal1_m637_MyFirstEnterFlag) MyFirstEnterFlag
	{ 973	,1	,1	, &internal1_m622_Pav0},	//(internal1_m622_Pav0)  - Пер.аварийный выключатель механизма
	{ 974	,1	,1	, &internal1_m622_Zav0},	//(internal1_m622_Zav0)  - Зад.аварийный выключатель механизма
	{ 975	,1	,1	, &internal1_m622_Pv0},	//(internal1_m622_Pv0)  - Пер. выключатель механизма
	{ 976	,1	,1	, &internal1_m622_Zv0},	//(internal1_m622_Zv0)  - Зад. выключатель механизма
	{ 977	,1	,1	, &internal1_m622_RA00},	//(internal1_m622_RA00)  - последнее задание вперед
	{ 978	,1	,1	, &internal1_m622_RA10},	//(internal1_m622_RA10)  - последнее задание назад
	{ 979	,1	,1	, &internal1_m622_MyFirstEnterFlag},	//(internal1_m622_MyFirstEnterFlag) MyFirstEnterFlag
	{ 980	,1	,1	, &internal1_m469_Pav0},	//(internal1_m469_Pav0)  - Пер.аварийный выключатель механизма
	{ 981	,1	,1	, &internal1_m469_Zav0},	//(internal1_m469_Zav0)  - Зад.аварийный выключатель механизма
	{ 982	,1	,1	, &internal1_m469_Pv0},	//(internal1_m469_Pv0)  - Пер. выключатель механизма
	{ 983	,1	,1	, &internal1_m469_Zv0},	//(internal1_m469_Zv0)  - Зад. выключатель механизма
	{ 984	,1	,1	, &internal1_m469_RA00},	//(internal1_m469_RA00)  - последнее задание вперед
	{ 985	,1	,1	, &internal1_m469_RA10},	//(internal1_m469_RA10)  - последнее задание назад
	{ 986	,1	,1	, &internal1_m469_MyFirstEnterFlag},	//(internal1_m469_MyFirstEnterFlag) MyFirstEnterFlag
	{ 987	,1	,1	, &internal1_m454_Pav0},	//(internal1_m454_Pav0)  - Пер.аварийный выключатель механизма
	{ 988	,1	,1	, &internal1_m454_Zav0},	//(internal1_m454_Zav0)  - Зад.аварийный выключатель механизма
	{ 989	,1	,1	, &internal1_m454_Pv0},	//(internal1_m454_Pv0)  - Пер. выключатель механизма
	{ 990	,1	,1	, &internal1_m454_Zv0},	//(internal1_m454_Zv0)  - Зад. выключатель механизма
	{ 991	,1	,1	, &internal1_m454_RA00},	//(internal1_m454_RA00)  - последнее задание вперед
	{ 992	,1	,1	, &internal1_m454_RA10},	//(internal1_m454_RA10)  - последнее задание назад
	{ 993	,1	,1	, &internal1_m454_MyFirstEnterFlag},	//(internal1_m454_MyFirstEnterFlag) MyFirstEnterFlag
	{ 994	,1	,1	, &internal1_m538_Pav0},	//(internal1_m538_Pav0)  - Пер.аварийный выключатель механизма
	{ 995	,1	,1	, &internal1_m538_Zav0},	//(internal1_m538_Zav0)  - Зад.аварийный выключатель механизма
	{ 996	,1	,1	, &internal1_m538_Pv0},	//(internal1_m538_Pv0)  - Пер. выключатель механизма
	{ 997	,1	,1	, &internal1_m538_Zv0},	//(internal1_m538_Zv0)  - Зад. выключатель механизма
	{ 998	,1	,1	, &internal1_m538_RA00},	//(internal1_m538_RA00)  - последнее задание вперед
	{ 999	,1	,1	, &internal1_m538_RA10},	//(internal1_m538_RA10)  - последнее задание назад
	{ 1000	,1	,1	, &internal1_m538_MyFirstEnterFlag},	//(internal1_m538_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1001	,1	,1	, &internal1_m405_Pav0},	//(internal1_m405_Pav0)  - Пер.аварийный выключатель механизма
	{ 1002	,1	,1	, &internal1_m405_Zav0},	//(internal1_m405_Zav0)  - Зад.аварийный выключатель механизма
	{ 1003	,1	,1	, &internal1_m405_Pv0},	//(internal1_m405_Pv0)  - Пер. выключатель механизма
	{ 1004	,1	,1	, &internal1_m405_Zv0},	//(internal1_m405_Zv0)  - Зад. выключатель механизма
	{ 1005	,1	,1	, &internal1_m405_RA00},	//(internal1_m405_RA00)  - последнее задание вперед
	{ 1006	,1	,1	, &internal1_m405_RA10},	//(internal1_m405_RA10)  - последнее задание назад
	{ 1007	,1	,1	, &internal1_m405_MyFirstEnterFlag},	//(internal1_m405_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1008	,1	,1	, &internal1_m389_Pav0},	//(internal1_m389_Pav0)  - Пер.аварийный выключатель механизма
	{ 1009	,1	,1	, &internal1_m389_Zav0},	//(internal1_m389_Zav0)  - Зад.аварийный выключатель механизма
	{ 1010	,1	,1	, &internal1_m389_Pv0},	//(internal1_m389_Pv0)  - Пер. выключатель механизма
	{ 1011	,1	,1	, &internal1_m389_Zv0},	//(internal1_m389_Zv0)  - Зад. выключатель механизма
	{ 1012	,1	,1	, &internal1_m389_RA00},	//(internal1_m389_RA00)  - последнее задание вперед
	{ 1013	,1	,1	, &internal1_m389_RA10},	//(internal1_m389_RA10)  - последнее задание назад
	{ 1014	,1	,1	, &internal1_m389_MyFirstEnterFlag},	//(internal1_m389_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1015	,1	,1	, &internal1_m372_Pav0},	//(internal1_m372_Pav0)  - Пер.аварийный выключатель механизма
	{ 1016	,1	,1	, &internal1_m372_Zav0},	//(internal1_m372_Zav0)  - Зад.аварийный выключатель механизма
	{ 1017	,1	,1	, &internal1_m372_Pv0},	//(internal1_m372_Pv0)  - Пер. выключатель механизма
	{ 1018	,1	,1	, &internal1_m372_Zv0},	//(internal1_m372_Zv0)  - Зад. выключатель механизма
	{ 1019	,1	,1	, &internal1_m372_RA00},	//(internal1_m372_RA00)  - последнее задание вперед
	{ 1020	,1	,1	, &internal1_m372_RA10},	//(internal1_m372_RA10)  - последнее задание назад
	{ 1021	,1	,1	, &internal1_m372_MyFirstEnterFlag},	//(internal1_m372_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1022	,1	,1	, &internal1_m1179_Pav0},	//(internal1_m1179_Pav0)  - Пер.аварийный выключатель механизма
	{ 1023	,1	,1	, &internal1_m1179_Zav0},	//(internal1_m1179_Zav0)  - Зад.аварийный выключатель механизма
	{ 1024	,1	,1	, &internal1_m1179_Pv0},	//(internal1_m1179_Pv0)  - Пер. выключатель механизма
	{ 1025	,1	,1	, &internal1_m1179_Zv0},	//(internal1_m1179_Zv0)  - Зад. выключатель механизма
	{ 1026	,1	,1	, &internal1_m1179_RA00},	//(internal1_m1179_RA00)  - последнее задание вперед
	{ 1027	,1	,1	, &internal1_m1179_RA10},	//(internal1_m1179_RA10)  - последнее задание назад
	{ 1028	,1	,1	, &internal1_m1179_MyFirstEnterFlag},	//(internal1_m1179_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1029	,8	,1	, &internal1_m180_C1},	//(internal1_m180_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	{ 1030	,8	,1	, &internal1_m180_C2},	//(internal1_m180_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	{ 1031	,8	,1	, &internal1_m180_C3},	//(internal1_m180_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	{ 1032	,8	,1	, &internal1_m180_C4},	//(internal1_m180_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	{ 1033	,8	,1	, &internal1_m180_C5},	//(internal1_m180_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	{ 1034	,8	,1	, &internal1_m180_C6},	//(internal1_m180_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	{ 1035	,8	,1	, &internal1_m180_N20},	//(internal1_m180_N20) N20 - пред. концентрация нейтронов второй АЗ
	{ 1036	,8	,6	, &internal1_m180_C0},	//(internal1_m180_C0) *C0 - пред. концентрация запаздывающих нейтронов
	{ 1037	,1	,1	, &internal1_m180_ImpINI0},	//(internal1_m180_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	{ 1038	,1	,1	, &internal1_m180_MyFirstEnterFlag},	//(internal1_m180_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1039	,1	,1	, &internal1_m298_Ppv0},	//(internal1_m298_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 1040	,1	,1	, &internal1_m298_Pav0},	//(internal1_m298_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 1041	,1	,1	, &internal1_m298_Zav0},	//(internal1_m298_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 1042	,1	,1	, &internal1_m298_RA00},	//(internal1_m298_RA00) RA00 - последнее задание вперед
	{ 1043	,1	,1	, &internal1_m298_RA10},	//(internal1_m298_RA10) RA10 - последнее задание назад
	{ 1044	,18	,1	, &internal1_m298_RA50},	//(internal1_m298_RA50) Ra50 - последнее задание скорости
	{ 1045	,1	,1	, &internal1_m298_fls},	//(internal1_m298_fls)  fls - флаг одношагового режима
	{ 1046	,1	,1	, &internal1_m298_flp},	//(internal1_m298_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1047	,1	,1	, &internal1_m298_MyFirstEnterFlag},	//(internal1_m298_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1048	,1	,1	, &internal1_m131_Ppv0},	//(internal1_m131_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 1049	,1	,1	, &internal1_m131_Pav0},	//(internal1_m131_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 1050	,1	,1	, &internal1_m131_Zav0},	//(internal1_m131_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 1051	,1	,1	, &internal1_m131_RA00},	//(internal1_m131_RA00) RA00 - последнее задание вперед
	{ 1052	,1	,1	, &internal1_m131_RA10},	//(internal1_m131_RA10) RA10 - последнее задание назад
	{ 1053	,18	,1	, &internal1_m131_RA50},	//(internal1_m131_RA50) Ra50 - последнее задание скорости
	{ 1054	,1	,1	, &internal1_m131_fls},	//(internal1_m131_fls)  fls - флаг одношагового режима
	{ 1055	,1	,1	, &internal1_m131_flp},	//(internal1_m131_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1056	,1	,1	, &internal1_m131_MyFirstEnterFlag},	//(internal1_m131_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1057	,1	,1	, &internal1_m265_Ppv0},	//(internal1_m265_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 1058	,1	,1	, &internal1_m265_Pav0},	//(internal1_m265_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 1059	,1	,1	, &internal1_m265_Zav0},	//(internal1_m265_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 1060	,1	,1	, &internal1_m265_RA00},	//(internal1_m265_RA00) RA00 - последнее задание вперед
	{ 1061	,1	,1	, &internal1_m265_RA10},	//(internal1_m265_RA10) RA10 - последнее задание назад
	{ 1062	,18	,1	, &internal1_m265_RA50},	//(internal1_m265_RA50) Ra50 - последнее задание скорости
	{ 1063	,1	,1	, &internal1_m265_fls},	//(internal1_m265_fls)  fls - флаг одношагового режима
	{ 1064	,1	,1	, &internal1_m265_flp},	//(internal1_m265_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1065	,1	,1	, &internal1_m265_MyFirstEnterFlag},	//(internal1_m265_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1066	,1	,1	, &internal1_m99_Ppv0},	//(internal1_m99_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 1067	,1	,1	, &internal1_m99_Pav0},	//(internal1_m99_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 1068	,1	,1	, &internal1_m99_Zav0},	//(internal1_m99_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 1069	,1	,1	, &internal1_m99_RA00},	//(internal1_m99_RA00) RA00 - последнее задание вперед
	{ 1070	,1	,1	, &internal1_m99_RA10},	//(internal1_m99_RA10) RA10 - последнее задание назад
	{ 1071	,18	,1	, &internal1_m99_RA50},	//(internal1_m99_RA50) Ra50 - последнее задание скорости
	{ 1072	,1	,1	, &internal1_m99_fls},	//(internal1_m99_fls)  fls - флаг одношагового режима
	{ 1073	,1	,1	, &internal1_m99_flp},	//(internal1_m99_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1074	,1	,1	, &internal1_m99_MyFirstEnterFlag},	//(internal1_m99_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1075	,1	,1	, &internal1_m227_Ppv0},	//(internal1_m227_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 1076	,1	,1	, &internal1_m227_Pav0},	//(internal1_m227_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 1077	,1	,1	, &internal1_m227_Zav0},	//(internal1_m227_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 1078	,1	,1	, &internal1_m227_RA00},	//(internal1_m227_RA00) RA00 - последнее задание вперед
	{ 1079	,1	,1	, &internal1_m227_RA10},	//(internal1_m227_RA10) RA10 - последнее задание назад
	{ 1080	,18	,1	, &internal1_m227_RA50},	//(internal1_m227_RA50) Ra50 - последнее задание скорости
	{ 1081	,1	,1	, &internal1_m227_fls},	//(internal1_m227_fls)  fls - флаг одношагового режима
	{ 1082	,1	,1	, &internal1_m227_flp},	//(internal1_m227_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1083	,1	,1	, &internal1_m227_MyFirstEnterFlag},	//(internal1_m227_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1084	,1	,1	, &internal1_m60_Ppv0},	//(internal1_m60_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 1085	,1	,1	, &internal1_m60_Pav0},	//(internal1_m60_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 1086	,1	,1	, &internal1_m60_Zav0},	//(internal1_m60_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 1087	,1	,1	, &internal1_m60_RA00},	//(internal1_m60_RA00) RA00 - последнее задание вперед
	{ 1088	,1	,1	, &internal1_m60_RA10},	//(internal1_m60_RA10) RA10 - последнее задание назад
	{ 1089	,18	,1	, &internal1_m60_RA50},	//(internal1_m60_RA50) Ra50 - последнее задание скорости
	{ 1090	,1	,1	, &internal1_m60_fls},	//(internal1_m60_fls)  fls - флаг одношагового режима
	{ 1091	,1	,1	, &internal1_m60_flp},	//(internal1_m60_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1092	,1	,1	, &internal1_m60_MyFirstEnterFlag},	//(internal1_m60_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1093	,8	,1	, &internal1_m14_C1},	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	{ 1094	,8	,1	, &internal1_m14_C2},	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	{ 1095	,8	,1	, &internal1_m14_C3},	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	{ 1096	,8	,1	, &internal1_m14_C4},	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	{ 1097	,8	,1	, &internal1_m14_C5},	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	{ 1098	,8	,1	, &internal1_m14_C6},	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	{ 1099	,8	,1	, &internal1_m14_N20},	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
	{ 1100	,8	,6	, &internal1_m14_C0},	//(internal1_m14_C0) *C0 - пред. концентрация запаздывающих нейтронов
	{ 1101	,1	,1	, &internal1_m14_ImpINI0},	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	{ 1102	,1	,1	, &internal1_m14_MyFirstEnterFlag},	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
	{-1,0,NULL},
};
static char NameSaveFile[]="scm.bin\0";   // Имя файла для сохранения констант
#pragma pop
static short saveVariables[]={      // Id переменных для сохранения
331,332,333,334,335,336,337,338,339,340,341,342,343,344,345,346,347,348,349,350,351,352,353,354,355,356,357,358,359,360,361,362,363,364,365,366,367,368,369,370,371,372,373,374,375,376,377,378,379,380,381,382,383,384,385,386,387,388,389,390,391,392,393,394,395,396,397,398,399,400,401,402,403,404,405,406,407,408,409,410,411,412,413,414,415,416,417,418,419,420,421,422,423,424,425,426,427,428,429,430,431,432,433,434,435,436,437,438,439,440,441,442,443,444,445,446,447,448,449,450,451,452,453,454,455,456,457,458,459,460,461,462,463,464,465,466,467,468,469,470,471,472,473,474,475,476,477,478,479,480,481,482,483,484,485,486,487,488,489,490,491,492,493,494,495,496,497,498,499,500,501,502,503,504,505,506,507,508,509,510,511,512,513,514,515,516,517,518,519,520,521,522,523,524,525,526,527,528,529,530,531,532,533,534,535,536,537,538,539,540,541,542,543,544,545,546,547,548,549,550,551,552,553,554,555,556,557,558,559,560,561,562,563,564,565,566,567,568,569,570,571,572,573,574,575,576,577,578,579,580,581,582,583,584,585,586,587,588,589,590,591,592,593,594,595,596,597,598,599,600,601,602,603,604,605,606,607,608,609,610,611,612,613,614,615,616,617,618,619,620,621,622,623,624,625,626,627,628,629,630,631,632,633,634,635,636,637,638,639,640,641,642,643,644,645,646,647,648,649,650,651,652,653,654,655,656,657,658,659,660,661,662,663,664,665,666,667,668,669,670,671,672,673,674,675,676,677,678,679,680,681,682,683,684,685,686,687,688,689,690,691,692,693,694,695,696,697,698,699,700,701,702,703,704,705,706,707,708,709,710,711,712,713,714,715,716,717,718,719,720,721,722,723,724,725,726,727,728,729,730,731,732,733,734,735,736,737,738,739,740,741,742,743,744,745,746,747,748,749,-1,};
#pragma pack(push,1)
static ModbusRegister coil_SCM[]={  // 
	{&R0AD14LDU,1,0},	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
	{&C2MD31LP1,1,1},	//(C2MD31LP1) Кнопка «СБРОС РБ»
	{&C1MD31LP2,1,2},	//(C1MD31LP2) Кнопка «СБРОС ББ»  на ОПУ2
	{&C1MD31LP1,1,3},	//(C1MD31LP1) Кнопка «СБРОС ББ»  на ОПУ1
	{&R0MW13LP2,1,4},	//(R0MW13LP2) Переключатель «СЕТЬ»
	{&lEM_C1AD31LRP,1,5},	//(C1AD31LRP) Общий сброс от РПУ
	{&lEM_R0IE01LRP,1,6},	//(R0IE01LRP) Отключение питание детекторов
	{&lEM_R0IE02LRP,1,7},	//(R0IE02LRP) Отключить питание ПР, ПУ
	{&lEM_A0EE06LC1,1,8},	//(A0EE06LC1) Исправность АКНП4 от диагностики контроллера (От ИС)
	{&lEM_A0EE05LC1,1,9},	//(A0EE05LC1) Исправность АКНП3 от диагностики контроллера (От ИС)
	{&lEM_A0EE03LC1,1,10},	//(A0EE03LC1) Исправность АКНП1 от диагностики контроллера (От ИС)
	{&lEM_A0EE04LC1,1,11},	//(A0EE04LC1) Исправность АКНП2 от диагностики контроллера (От ИС)
	{&lEM_R3AD10LC1,1,12},	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
	{&lEM_R3AD20LC1,1,13},	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
	{&lEM_R3AD11LC1,1,14},	//(R3AD11LC1) Гомогенные двери-2 открыть от ИС
	{&lEM_R3AD21LC1,1,15},	//(R3AD21LC1) Гомогенные двери-2 закрыть от ИС
	{&lEM_R6AD10LC1,1,16},	//(R6AD10LC1) Выкатить кран-балку от ИС
	{&lEM_R5AD10LC1,1,17},	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
	{&lEM_R5AD20LC1,1,18},	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
	{&lEM_R8AD10LC1,1,19},	//(R8AD10LC1) Установить аварийный НИ от ИС
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SCM[]={  // 
	{&R0IE12LS4,1,0},	//(R0IE12LS4) Исправность ВИП 0,5 (№18) КНК15-1 4канала
	{&R0IE13LS4,1,1},	//(R0IE13LS4) Исправность ВИП 0,5 (№19) КНК53М 4канала
	{&R0IE11LS4,1,2},	//(R0IE11LS4) Исправность ВИП 1,6 (№17) СНМ11 4канала
	{&A1IS11LIM,1,3},	//(A1IS11LIM) Магнит ББ1 обесточен
	{&A1IS32LIM,1,4},	//(A1IS32LIM) Клапан cброса ББ1 открыт(обесточен)
	{&B1IS11LIM,1,5},	//(B1IS11LIM) Магнит ББ2 обесточен
	{&B1IS32LIM,1,6},	//(B1IS32LIM) Клапан cброса ББ2 открыт(обесточен)
	{&A2IS11LIM,1,7},	//(A2IS11LIM) Магнит РБ1 обесточен
	{&A2IS32LIM,1,8},	//(A2IS32LIM) Клапан cброса РБ1 открыт(обесточен)
	{&B2IS11LIM,1,9},	//(B2IS11LIM) Магнит РБ2 обесточен
	{&B2IS32LIM,1,10},	//(B2IS32LIM) Клапан cброса РБ2 открыт(обесточен)
	{&R0IE11LS1,1,11},	//(R0IE11LS1) Исправность ВИП 1,6 (№8) СНМ11 1канала
	{&R0IE12LS1,1,12},	//(R0IE12LS1) Исправность ВИП 0,5 (№9) КНК15-1 1канала
	{&R0IE13LS1,1,13},	//(R0IE13LS1) Исправность ВИП 0,5 (№10) КНК53М 1канала
	{&R0IE12LS2,1,14},	//(R0IE12LS2) Исправность ВИП 0,5 (№12) КНК15-1 2канала
	{&R0IE13LS2,1,15},	//(R0IE13LS2) Исправность ВИП 0,5 (№13) КНК53М 2канала
	{&R0IE11LS2,1,16},	//(R0IE11LS2) Исправность ВИП 1,6 (№11) СНМ11 2канала
	{&R0IE12LS3,1,17},	//(R0IE12LS3) Исправность ВИП 0,5 (№15) КНК15-1 3канала
	{&R0IE13LS3,1,18},	//(R0IE13LS3) Исправность ВИП 0,5 (№16) КНК53М 3канала
	{&R0IE11LS3,1,19},	//(R0IE11LS3) Исправность ВИП 1,6 (№14) СНМ11 3канала
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SCM[]={  // 
	{&R0VN15RS4,3,0},	//(R0VN15RS4) Номер ведущей камеры канал 4
	{&A0VN01RIM,8,1},	//(A0VN01RIM) Период разгона  AЗ1
	{&A0SN02RIM,8,3},	//(A0SN02RIM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
	{&A0SN03RIM,8,5},	//(A0SN03RIM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
	{&A0SN04RIM,8,7},	//(A0SN04RIM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
	{&A0SN05RIM,8,9},	//(A0SN05RIM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
	{&A0SN06RIM,8,11},	//(A0SN06RIM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
	{&A0SN07RIM,8,13},	//(A0SN07RIM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
	{&B0SN02RIM,8,15},	//(B0SN02RIM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
	{&B0SN03RIM,8,17},	//(B0SN03RIM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
	{&B0SN04RIM,8,19},	//(B0SN04RIM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
	{&B0SN05RIM,8,21},	//(B0SN05RIM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
	{&B0SN06RIM,8,23},	//(B0SN06RIM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
	{&B0SN07RIM,8,25},	//(B0SN07RIM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
	{&A0SR01RIM,8,27},	//(A0SR01RIM) Текущая реактивность AЗ1
	{&B0SR01RIM,8,29},	//(B0SR01RIM) Текущая реактивность AЗ2
	{&A0SN08RIM,8,31},	//(A0SN08RIM) Поток нейтронов AЗ1(нейтр/с)
	{&B0SN08RIM,8,33},	//(B0SN08RIM) Поток нейтронов AЗ2(нейтр/с)
	{&R0CR01RIM,8,35},	//(R0CR01RIM) Коэффициент 12 связи АЗ1,2
	{&R0CR02RIM,8,37},	//(R0CR02RIM) Коэффициент 11 связи АЗ1,2
	{&R0SR02RIM,8,39},	//(R0SR02RIM) Текущая мощность РУ (ватт)
	{&R0ST01RIM,8,41},	//(R0ST01RIM) Текущий период разгона РУ
	{&R0SR01RIM,8,43},	//(R0SR01RIM) Текущая реактивность PУ
	{&R0VN15RS1,3,45},	//(R0VN15RS1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
	{&R0VN15RS2,3,46},	//(R0VN15RS2) Номер ведущей камеры канал 2
	{&R0VN15RS3,3,47},	//(R0VN15RS3) Номер ведущей камеры канал 3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SCM[]={  // 
	{&fEM_R0UL01RIM,8,0},	//(R0UL01RIM) Среднее время генерации нейтронов
	{&fEM_R0UN02RIM,8,2},	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{&fEM_A1UR01RIM,8,4},	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{&fEM_A1UR00RIM,8,6},	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{&fEM_A3UR00RIM,8,8},	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{&fEM_A3UR01RIM,8,10},	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{&fEM_R0UT01RIM,8,12},	//(R0UT01RIM) Температурный коэффициент (долл)
	{&fEM_R0UT02RIM,8,14},	//(R0UT02RIM) Масса топлива в АЗ
	{&fEM_R0UT04RIM,8,16},	//(R0UT04RIM) Удельная теплоёмкость топлива
	{&fEM_R0UT03RIM,8,18},	//(R0UT03RIM) Нормальная температура АЗ град
	{&fEM_R0UT05RIM,8,20},	//(R0UT05RIM) Энергия деления ядра
	{&fEM_R0UT06RIM,8,22},	//(R0UT06RIM) Конвекционное сопротивление при обдуве
	{&fEM_A1UC02RDU,8,24},	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
	{&fEM_A1UC04RIM,8,26},	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
	{&fEM_A1UC05RIM,8,28},	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
	{&fEM_A1UC06RIM,8,30},	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
	{&fEM_A2UC06RIM,8,32},	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
	{&fEM_A2UC05RIM,8,34},	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
	{&fEM_A2UC04RIM,8,36},	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
	{&fEM_A2UC02RDU,8,38},	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
	{&fEM_A3UC06RIM,8,40},	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
	{&fEM_A3UC05RIM,8,42},	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
	{&fEM_A3UC04RIM,8,44},	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
	{&fEM_A3UC02RDU,8,46},	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
	{&fEM_R4UV80RDU,8,48},	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
	{&fEM_R4UC10RIM,8,50},	//(R4UC10RIM) Координата верхних механических упоров тележки мм
	{&fEM_R4UC20RIM,8,52},	//(R4UC20RIM) Координата нижних механических упоров тележки мм
	{&fEM_B8UC21RIM,8,54},	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
	{&fEM_B8UC20RIM,8,56},	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
	{&fEM_B8UC11RIM,8,58},	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
	{&fEM_B8UC10RIM,8,60},	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
	{&fEM_B8UV80RDU,8,62},	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
	{&fEM_A8UV80RDU,8,64},	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
	{&fEM_A8UC10RIM,8,66},	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
	{&fEM_A8UC11RIM,8,68},	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
	{&fEM_A8UC20RIM,8,70},	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
	{&fEM_A8UC21RIM,8,72},	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
	{&fEM_A6UC10RIM,8,74},	//(A6UC10RIM) Время полного хода БЗ (сек)
	{&fEM_R1UC10RIM,8,76},	//(R1UC10RIM) Время полного хода МДЗ сек
	{&fEM_A5UC10RIM,8,78},	//(A5UC10RIM) Время полного хода НЛ сек
	{&fEM_A0UN01RIM,8,80},	//(A0UN01RIM) Мощность источника нейтронов ИНИ
	{&fEM_R4UC22RIM,8,82},	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
	{&fEM_R4UC23RIM,8,84},	//(R4UC23RIM) Y-координата АЗ1 см
	{&fEM_A1UG01RDU,8,86},	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
	{&fEM_A2UG01RDU,8,88},	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
	{&fEM_A3UG01RDU,8,90},	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
	{&fEM_R7UC10RIM,8,92},	//(R7UC10RIM) X-координата КНК53М R7IN13 см
	{&fEM_R7UC19RIM,8,94},	//(R7UC19RIM) Y-координата СНМ-11 (11) см
	{&fEM_R7UI02RIM,8,96},	//(R7UI02RIM) Коэффициент усиления уровня радиации
	{&fEM_R7UL01RIM,8,98},	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
	{&fEM_A2UR00RIM,8,100},	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
	{&fEM_A2UR01RIM,8,102},	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
	{&fEM_A0UN02RIM,8,104},	//(A0UN02RIM) Мощность источника нейтронов с АНИ
	{&fEM_R0UR30RIM,8,106},	//(R0UR30RIM) Реактивность вносимая образцами (долл)
	{&fEM_R0UR01RIM,8,108},	//(R0UR01RIM) Стартовая отрицательная реактивность
	{&fEM_R0UT02RDU,8,110},	//(R0UT02RDU) Верхний предел шкалы датчика температуры
	{&fEM_R0UT01RDU,8,112},	//(R0UT01RDU) Нижний предел шкалы датчика температуры
	{&fEM_A1UC03RDU,8,114},	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
	{&fEM_A2UP03RDU,8,116},	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
	{&fEM_A2UP04RDU,8,118},	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
	{&fEM_A2UC03RDU,8,120},	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
	{&fEM_A3UP03RDU,8,122},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{&fEM_A3UP04RDU,8,124},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{&fEM_A3UC03RDU,8,126},	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
	{&fEM_R7UI74RIM,8,128},	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
	{&fEM_A8UC03RDU,8,130},	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
	{&fEM_R0UV87RDU,8,132},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UV81RDU,8,134},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{&fEM_R0UV82RDU,8,136},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{&fEM_R0UV83RDU,8,138},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{&fEM_R0UV84RDU,8,140},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{&fEM_R0UV85RDU,8,142},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UV86RDU,8,144},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{&fEM_A8UC08RDU,8,146},	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
	{&fEM_B8UC08RDU,8,148},	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
	{&fEM_R4UC08RDU,8,150},	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
	{&fEM_A0UX00RSS,8,152},	//(A0UX00RSS) Эффективный радиус АЗ
	{&fEM_R7UX01RSS,8,154},	//(R7UX01RSS) X-координата камеры R7IN11
	{&fEM_R7UX02RSS,8,156},	//(R7UX02RSS) X-координата камеры R7IN12 (см)
	{&fEM_R7UX04RSS,8,158},	//(R7UX04RSS) X-координата камеры R7IN21 (см)
	{&fEM_R7UX05RSS,8,160},	//(R7UX05RSS) X-координата камеры R7IN22 (см)
	{&fEM_R7UX06RSS,8,162},	//(R7UX06RSS) X-координата камеры R7IN23 (см)
	{&fEM_R7UX07RSS,8,164},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{&fEM_R7UX08RSS,8,166},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{&fEM_R7UX09RSS,8,168},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{&fEM_R7UY01RSS,8,170},	//(R7UY01RSS) Y-координата камеры R7IN11
	{&fEM_R7UY02RSS,8,172},	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
	{&fEM_R7UY04RSS,8,174},	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
	{&fEM_R7UY05RSS,8,176},	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
	{&fEM_R7UY06RSS,8,178},	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
	{&fEM_R7UY07RSS,8,180},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{&fEM_R7UY08RSS,8,182},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{&fEM_R7UY09RSS,8,184},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{&fEM_R7UX10RSS,8,186},	//(R7UX10RSS) X-координата камеры R7IN41
	{&fEM_R7UX11RSS,8,188},	//(R7UX11RSS) X-координата камеры R7IN42
	{&fEM_R7UX12RSS,8,190},	//(R7UX12RSS) X-координата камеры R7IN43
	{&fEM_R7UY10RSS,8,192},	//(R7UY10RSS) Y-координата камеры R7IN41
	{&fEM_R7UY11RSS,8,194},	//(R7UY11RSS) Y-координата камеры R7IN42
	{&fEM_R7UY12RSS,8,196},	//(R7UY12RSS) Y-координата камеры R7IN43
	{&fEM_A0UX01RSS,8,198},	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
	{&fEM_A0UX02RSS,8,200},	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
	{&fEM_A0UX03RSS,8,202},	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
	{&fEM_A0UX04RSS,8,204},	//(A0UX04RSS) Первый коэффициент калибровки камеры4
	{&fEM_A0UX05RSS,8,206},	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
	{&fEM_A0UX06RSS,8,208},	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
	{&fEM_A0UX07RSS,8,210},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{&fEM_A0UX08RSS,8,212},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{&fEM_A0UX09RSS,8,214},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{&fEM_A0UX10RSS,8,216},	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
	{&fEM_A0UX11RSS,8,218},	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
	{&fEM_A0UX12RSS,8,220},	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
	{&fEM_B0UX01RSS,8,222},	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
	{&fEM_B0UX02RSS,8,224},	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
	{&fEM_B0UX03RSS,8,226},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{&fEM_B0UX04RSS,8,228},	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
	{&fEM_B0UX05RSS,8,230},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{&fEM_B0UX06RSS,8,232},	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
	{&fEM_B0UX07RSS,8,234},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{&fEM_B0UX08RSS,8,236},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{&fEM_B0UX09RSS,8,238},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{&fEM_B0UX10RSS,8,240},	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
	{&fEM_B0UX11RSS,8,242},	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
	{&fEM_B0UX12RSS,8,244},	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
	{&fEM_R0UH02RSS,8,246},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
	{&fEM_R0UH03RSS,8,248},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
	{&fEM_R4US80RDU,8,250},	//(R4US80RDU) Тормозной путь тележки (мм)
	{&fEM_R7UI71RIM,8,252},	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{&fEM_R7UI72RIM,8,254},	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
	{&fEM_R7UI73RIM,8,256},	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
	{&fEM_A1UP01RIM,8,258},	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
	{&fEM_A2UP01RIM,8,260},	//(A2UP01RIM) Текущее давление на сброс РБ
	{&fEM_A0UP02RIM,8,262},	//(A0UP02RIM) Текущее давление в АЗ1,2
	{&fEM_A3UP01RIM,8,264},	//(A3UP01RIM) Текущее давление на СПУСК ИС
	{&fEM_A1UP82RIM,8,266},	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{&fEM_R0UP85RIM,8,268},	//(R0UP85RIM) Нижняя граница давления  в СИСТЕМЕ (МПа)
	{&fEM_R0UP88RIM,8,270},	//(R0UP88RIM) Верхняя граница давления  в СИСТЕМЕ (МПа)
	{&fEM_A3UP02RDU,8,272},	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
	{&fEM_A1UV02RIM,8,274},	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{&fEM_A3UV02RIM,8,276},	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{&fEM_A2UV02RIM,8,278},	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{&fEM_B8US80RDU,8,280},	//(B8US80RDU) Тормозной путь АЗ2 (мм)
	{&fEM_A8US80RDU,8,282},	//(A8US80RDU) Тормозной путь ДС2 (мм)
	{&fEM_A6US80RDU,8,284},	//(A6US80RDU) Тормозной путь БЗ (мм)
	{&fEM_A1US07RDU,8,286},	//(A1US07RDU) Постоянная времени масляного демпфера ББ
	{&fEM_A2US07RDU,8,288},	//(A2US07RDU) Постоянная времени масляного демпфера РБ
	{&fEM_A3US07RDU,8,290},	//(A3US07RDU) Постоянная времени масляного демпфера ИС
	{&fEM_R7UI75RIM,8,292},	//(R7UI75RIM) Множитель к уровню радиации
	{&fEM_R0UH21RSS,8,294},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{&fEM_R0UH22RSS,8,296},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{&fEM_R0UH23RSS,8,298},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{&fEM_R0UR01RSS,8,300},	//(R0UR01RSS) Уровень по мощности РУ блокировки автоматического подъёма ББ
	{&fEM_R0UL52RSS,8,302},	//(R0UL52RSS) Уровень АС по мощности
	{&fEM_R0UL41RSS,8,304},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{&fEM_R0UL51RSS,8,306},	//(R0UL51RSS) Уровень АС по периоду разгона
	{&fEM_R0UL42RSS,8,308},	//(R0UL42RSS) Уровень ПС по мощности
	{&fEM_R0UH05RSS,8,310},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_R0UN03RSS,8,312},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{&fEM_A4UL10RIM,8,314},	//(A4UL10RIM) Время полного перемещения НИ сек
	{&fEM_A9UL10RIM,8,316},	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
	{&fEM_R3UL10RIM,8,318},	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
	{&fEM_R5UL10RIM,8,320},	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
	{&fEM_R6UL10RIM,8,322},	//(R6UL10RIM) Время полного хода кран-балки сек
	{&fEM_A0UP03RIM,8,324},	//(A0UP03RIM) Текущее давление в системе
	{&fEM_A2UP02RIM,8,326},	//(A2UP02RIM) Текущее давление на подъём РБ
	{&fEM_A2UP03RIM,8,328},	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
	{&fEM_A0UP01RIM,8,330},	//(A0UP01RIM) Текущее давление в АЗ1,2
	{&fEM_A3UP02RIM,8,332},	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
	{&fEM_A4UP01RIM,8,334},	//(A4UP01RIM) Текущее давление на подъём НИ
	{&fEM_A4UP02RIM,8,336},	//(A4UP02RIM) Нижняя граница давления на подъём НИ
	{&fEM_R7UI76RIM,8,338},	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{&fEM_R7UI77RIM,8,340},	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{&iEM_TERBB1,3,342},	//(TERBB1) Неисправности  ББ1
	{&fEM_A1MC02RC1,8,343},	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
	{&fEM_A1MV02RC1,8,345},	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
	{&iEM_TERBB2,3,347},	//(TERBB2) Неисправности  ББ2
	{&fEM_B1MC02RC1,8,348},	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
	{&fEM_B1MV02RC1,8,350},	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
	{&iEM_TERRB2,3,352},	//(TERRB2) Неисправности  РБ2
	{&fEM_B2MC02RC1,8,353},	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
	{&fEM_B2MV02RC1,8,355},	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
	{&iEM_TERRB1,3,357},	//(TERRB1) Неисправности  РБ1
	{&fEM_A2MC02RC1,8,358},	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
	{&fEM_A2MV02RC1,8,360},	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
	{&iEM_TERIS2,3,362},	//(TERIS2) Неисправности  ИС2
	{&fEM_B3MC02RC1,8,363},	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
	{&fEM_B3MV02RC1,8,365},	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
	{&iEM_TERIS1,3,367},	//(TERIS1) Неисправности  ИС1
	{&fEM_A3MC02RC1,8,368},	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
	{&fEM_A3MV02RC1,8,370},	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
	{&iEM_TERA1IE04LDU,3,372},	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
	{&iEM_TERA1IE03LDU,3,373},	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
	{&fEM_A1MC01RC1,8,374},	//(A1MC01RC1) Заданная координата  ББ1 от ИС
	{&iEM_TERB1IE03LDU,3,376},	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
	{&iEM_TERB1IE04LDU,3,377},	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
	{&fEM_B1MC01RC1,8,378},	//(B1MC01RC1) Заданная координата ББ2 от ИС
	{&fEM_B1MV01RC1,8,380},	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
	{&fEM_B2MC01RC1,8,382},	//(B2MC01RC1) Заданная координата РБ2 от ИС
	{&fEM_B2MV01RC1,8,384},	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
	{&fEM_A3MC01RC1,8,386},	//(A3MC01RC1) Заданная координата ИС1 от ИС
	{&fEM_A3MV01RC1,8,388},	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
	{&fEM_B3MC01RC1,8,390},	//(B3MC01RC1) Заданная координата ИС2 от ИС
	{&fEM_B3MV01RC1,8,392},	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
	{&iEM_TERA2SS21LIM,3,394},	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
	{&iEM_TERA2SS12LIM,3,395},	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
	{&iEM_TERR6SS21LIM,3,396},	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
	{&iEM_TERA2VP82LIM,3,397},	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
	{&iEM_TERA2SS11LIM,3,398},	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
	{&iEM_TERB3SS21LIM,3,399},	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
	{&iEM_TERA0MT01RIM,3,400},	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
	{&iEM_TERB0MT01RIM,3,401},	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
	{&iEM_TERA2SP01RIM,3,402},	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
	{&iEM_TERB2SP01RIM,3,403},	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
	{&iEM_TERB3SP02RIM,3,404},	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{&iEM_TERA3SC01RIM,3,405},	//(TERA3SC01RIM) Искажение: Координата штока ИС1
	{&iEM_TERA3VP81LIM,3,406},	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
	{&iEM_TERA2SC01RIM,3,407},	//(TERA2SC01RIM) Искажение: Координата штока РБ1
	{&iEM_TERA2SS33LIM,3,408},	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{&iEM_TERA3SS21LIM,3,409},	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
	{&iEM_TERA3SS33LIM,3,410},	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{&iEM_TERA3SS31LIM,3,411},	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{&iEM_TERB3SS31LIM,3,412},	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{&iEM_TERB3SS33LIM,3,413},	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{&iEM_TERB3SC01RIM,3,414},	//(TERB3SC01RIM) Искажение: Координата штока ИС2
	{&iEM_TERA3SS11LIM,3,415},	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
	{&iEM_TERB3SS11LIM,3,416},	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
	{&iEM_TERR6IS64LIM,3,417},	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
	{&iEM_TERB3SS22LIM,3,418},	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
	{&iEM_TERA3SS22LIM,3,419},	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
	{&iEM_TERA3SP02RIM,3,420},	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{&iEM_TERR6IS62LIM,3,421},	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
	{&iEM_TERR6IS66LIM,3,422},	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{&iEM_TERR6IS67LIM,3,423},	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
	{&iEM_TERA0VP81LIM,3,424},	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
	{&iEM_TERB0VP81LIM,3,425},	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
	{&iEM_TERR0VP81LIM,3,426},	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	{&iEM_TERR0VP82LIM,3,427},	//(TERR0VP82LIM) Искажение: Давление  в СИСТЕМЕ-2 в норме
	{&iEM_TERR6IS68LIM,3,428},	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
	{&iEM_TERR7SI74RIM,3,429},	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
	{&iEM_TERA5SS21LIM,3,430},	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
	{&iEM_TERB5SS11LIM,3,431},	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
	{&iEM_TERA5SS11LIM,3,432},	//(TERA5SS11LIM) Искажение: Приход на ВУ НЛ1
	{&iEM_TERA9SS11LIM,3,433},	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
	{&iEM_TERB2SS11LIM,3,434},	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
	{&iEM_TERB2SS12LIM,3,435},	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
	{&iEM_TERB2SS21LIM,3,436},	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
	{&iEM_TERR3SS11LIM,3,437},	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
	{&iEM_TERB2SC01RIM,3,438},	//(TERB2SC01RIM) Искажение: Координата штока РБ2
	{&iEM_TERR3SS21LIM,3,439},	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
	{&iEM_TERR5SS11LIM,3,440},	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
	{&iEM_TERR3SS12LIM,3,441},	//(TERR3SS12LIM) Искажение: Приход на ВУ гомогенных дверей-2
	{&iEM_TERR3SS22LIM,3,442},	//(TERR3SS22LIM) Искажение: Приход на НУ гомогенных дверей-2
	{&iEM_TERA4SS11LIM,3,443},	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
	{&iEM_TERR1SS11LIM,3,444},	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
	{&iEM_TERR1SS21LIM,3,445},	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
	{&iEM_TERR2SS11LIM,3,446},	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
	{&iEM_TERR2SS21LIM,3,447},	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
	{&iEM_TERA4VP82LIM,3,448},	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
	{&iEM_TERB4SS21LIM,3,449},	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
	{&iEM_TERR5SS21LIM,3,450},	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
	{&iEM_TERB6SS21LIM,3,451},	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
	{&iEM_TERB4SS11LIM,3,452},	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
	{&iEM_TERA4SS21LIM,3,453},	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
	{&iEM_TERA6MS11LIM,3,454},	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
	{&iEM_TERA6SS21LIM,3,455},	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
	{&iEM_TERB6SS11LIM,3,456},	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
	{&iEM_TERR4SS11LIM,3,457},	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
	{&iEM_TERR4MS21LIM,3,458},	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
	{&iEM_TERR4SS12LIM,3,459},	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
	{&iEM_TERR4SS22LIM,3,460},	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
	{&iEM_TERR8SS11LIM,3,461},	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
	{&iEM_TERB8SC01RIM,3,462},	//(TERB8SC01RIM) Искажение: Координата АЗ2
	{&iEM_TERA8SC01RIM,3,463},	//(TERA8SC01RIM) Искажение: Координата ДС2
	{&iEM_TERB8SS12LIM,3,464},	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
	{&iEM_TERA8SS12LIM,3,465},	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
	{&iEM_TERB8SS22LIM,3,466},	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
	{&iEM_TERA8SS22LIM,3,467},	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
	{&iEM_TERA9SS21LIM,3,468},	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
	{&iEM_TERB9SS21LIM,3,469},	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
	{&iEM_TERB9SS11LIM,3,470},	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
	{&iEM_TERB5SS21LIM,3,471},	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
	{&iEM_TERA1SS21LIM,3,472},	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
	{&iEM_TERA1SS11LIM,3,473},	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
	{&iEM_TERA1SC01RIM,3,474},	//(TERA1SC01RIM) Искажение: Координата штока ББ1
	{&iEM_TERA1SS12LIM,3,475},	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
	{&iEM_TERB1SS21LIM,3,476},	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
	{&iEM_TERB1SS11LIM,3,477},	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
	{&iEM_TERB1MC01RIM,3,478},	//(TERB1MC01RIM) Искажение: Координата штока ББ2
	{&iEM_TERB1SS12LIM,3,479},	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
	{&iEM_TERR0IE43LIM,3,480},	//(TERR0IE43LIM) Исправность ВИП 0,5 4канала
	{&iEM_TERR0IE41LIM,3,481},	//(TERR0IE41LIM) Исправность ВИП 1,6 (№17) СНМ11 4канала
	{&iEM_TERR0IE33LIM,3,482},	//(TERR0IE33LIM) Искажение:Исправность ВИП 0,5  3канала
	{&iEM_TERR0IE31LIM,3,483},	//(TERR0IE31LIM) Искажение: Исправность ВИП 1,6 (№14) СНМ11 3канала
	{&iEM_TERR0IE11LIM,3,484},	//(TERR0IE11LIM) Искажение: Исправность ВИП 1,6 (№8) СНМ11 1канала
	{&iEM_TERR0IE13LIM,3,485},	//(TERR0IE13LIM) Искажение: Исправность ВИП 0,5  1канала
	{&iEM_TERR0IE23LIM,3,486},	//(TERR0IE23LIM) Искажение: Исправность ВИП 0,5 (№13) КНК53М 2канала
	{&iEM_TERR0IE21LIM,3,487},	//(TERR0IE21LIM) Искажение: Исправность ВИП 1,6 (№11) СНМ11 2канала
	{&iEM_TERTLG,3,488},	//(TERTLG) Неисправности  тележки от ИС
	{&fEM_R4MC01RC1,8,489},	//(R4MC01RC1) Заданная координата тележки от ИС
	{&fEM_R4MV01RC1,8,491},	//(R4MV01RC1) Заданная скорость тележки от ИС
	{&iEM_TERMAZ2,3,493},	//(TERMAZ2) Неисправности АЗ2 от ИС
	{&fEM_B8MC01RC1,8,494},	//(B8MC01RC1) аданная координата АЗ2 от ИС
	{&fEM_B8MV01RC1,8,496},	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
	{&iEM_TERDS2,3,498},	//(TERDS2) Неисправности ДС2 от ИС
	{&fEM_A8MC01RC1,8,499},	//(A8MC01RC1) Заданная координата ДС2 от ИС
	{&fEM_A8MV01RC1,8,501},	//(A8MV01RC1) Заданная скорость ДС2 от ИС
	{&iEM_TERBZ1,3,503},	//(TERBZ1) Неисправности БЗ1
	{&fEM_A6MC01RC1,8,504},	//(A6MC01RC1) Заданная координата БЗ1 от ИС
	{&fEM_A6MV01RC1,8,506},	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
	{&iEM_TERBZ2,3,508},	//(TERBZ2) Неисправности БЗ2
	{&fEM_B6MC01RC1,8,509},	//(B6MC01RC1) Заданная координата БЗ2 от ИС
	{&fEM_B6MV01RC1,8,511},	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
	{&iEM_TERR3AD10LDU,3,513},	//(TERR3AD10LDU) Искажение: Гомогенные двери-1 открыть
	{&iEM_TERR3AD20LDU,3,514},	//(TERR3AD20LDU) Искажение: Гомогенные двери-1 закрыть
	{&iEM_TERR3AD11LDU,3,515},	//(TERR3AD11LDU) Искажение: Гомогенные двери-2 открыть
	{&iEM_TERR3AD21LDU,3,516},	//(TERR3AD21LDU) Искажение: Гомогенные двери-2 закрыть
	{&iEM_TERR5AD10LDU,3,517},	//(TERR5AD10LDU) Искажение: Открыть ворота отстойной зоны
	{&iEM_TERR5AD20LDU,3,518},	//(TERR5AD20LDU) Искажение: Закрыть ворота отстойной зоны
	{&iEM_TERMDZ2,3,519},	//(TERMDZ2) Неисправности МДЗ2
	{&fEM_R2MC01RC1,8,520},	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
	{&fEM_R2MV01RC1,8,522},	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
	{&iEM_TERMDZ1,3,524},	//(TERMDZ1) Неисправности МДЗ1
	{&fEM_R1MC01RC1,8,525},	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
	{&fEM_R1MV01RC1,8,527},	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
	{&iEM_TERNL1,3,529},	//(TERNL1) Неисправности НЛ1
	{&fEM_A5MC01RC1,8,530},	//(A5MC01RC1) Заданная координата НЛ1 от ИС
	{&fEM_A5MV01RC1,8,532},	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
	{&iEM_TERNL2,3,534},	//(TERNL2) Неисправности НЛ2
	{&fEM_B5MC01RC1,8,535},	//(B5MC01RC1) Заданная координата НЛ2 от ИС
	{&fEM_B5MV01RC1,8,537},	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
	{&fEM_A1UC08RIM,8,539},	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
	{&fEM_A2UC08RIM,8,541},	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
	{&fEM_A3UC08RIM,8,543},	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
	{&fEM_R0UL01RSS,8,545},	//(R0UL01RSS) Шаг (мс) измерения периода
	{&fEM_R0UL03RSS,8,547},	//(R0UL03RSS) Предельное время ожидания роста потока (сек)
	{&iEM_TERB2SS33LIM,3,549},	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{&iEM_TERA1VP81LIM,3,550},	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
	{&iEM_TERB1VP81LIM,3,551},	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
	{&fEM_A0UT03RSP,8,552},	//(A0UT03RSP) Стартовая  температура АЗ1 град
	{&fEM_A0UR01RSP,8,554},	//(A0UR01RSP) Стартовая  реактивность АЗ1
	{&fEM_A0UR02RSP,8,556},	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
	{&fEM_B0UT03RSP,8,558},	//(B0UT03RSP) Стартовая  температура АЗ2 град
	{&fEM_A1MC01RSP,8,560},	//(A1MC01RSP) Стартовая координата  ББ1
	{&fEM_A1MC02RSP,8,562},	//(A1MC02RSP) Стартовая координата штока ББ1
	{&fEM_A1MV01RSP,8,564},	//(A1MV01RSP) Стартовая скорость движения  ББ1
	{&fEM_A1MV02RSP,8,566},	//(A1MV02RSP) Стартовая скорость движения  ББ1
	{&fEM_B1MC01RSP,8,568},	//(B1MC01RSP) Стартовая координата  ББ2
	{&fEM_B1MV01RSP,8,570},	//(B1MV01RSP) Стартовая скорость движения  ББ2
	{&fEM_B1MC02RSP,8,572},	//(B1MC02RSP) Стартовая координата штока ББ2
	{&fEM_B1MV02RSP,8,574},	//(B1MV02RSP) Стартовая скорость движения  ББ2
	{&fEM_A2MC01RC1,8,576},	//(A2MC01RC1) Заданная координата РБ1 от ИС
	{&fEM_A2MV01RC1,8,578},	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
	{&fEM_A2MC01RSP,8,580},	//(A2MC01RSP) Стартовая координата  РБ1
	{&fEM_A2MV01RSP,8,582},	//(A2MV01RSP) Стартовая скорость движения  РБ1
	{&fEM_A2MC02RSP,8,584},	//(A2MC02RSP) Стартовая координата штока РБ1
	{&fEM_A2MV02RSP,8,586},	//(A2MV02RSP) Стартовая скорость движения  РБ1
	{&fEM_B2MC01RSP,8,588},	//(B2MC01RSP) Стартовая координата  РБ2
	{&fEM_B2MV01RSP,8,590},	//(B2MV01RSP) Стартовая скорость движения  РБ2
	{&fEM_B2MC02RSP,8,592},	//(B2MC02RSP) Стартовая координата штока РБ2
	{&fEM_B2MV02RSP,8,594},	//(B2MV02RSP) Стартовая скорость движения  РБ2
	{&fEM_A3MC01RSP,8,596},	//(A3MC01RSP) Стартовая координата  ИС1
	{&fEM_A3MV01RSP,8,598},	//(A3MV01RSP) Стартовая скорость движения  ИС1
	{&fEM_A3MC02RSP,8,600},	//(A3MC02RSP) Стартовая координата штока ИС1
	{&fEM_A3MV02RSP,8,602},	//(A3MV02RSP) Стартовая скорость движения  ИС1
	{&fEM_B3MC01RSP,8,604},	//(B3MC01RSP) Стартовая координата  ИС2
	{&fEM_B3MV01RSP,8,606},	//(B3MV01RSP) Стартовая скорость движения  ИС2
	{&fEM_B3MC02RSP,8,608},	//(B3MC02RSP) Стартовая координата штока ИС2
	{&fEM_B3MV02RSP,8,610},	//(B3MV02RSP) Стартовая скорость движения  ИС2
	{&fEM_B8MC01RSP,8,612},	//(B8MC01RSP) Стартовая координата АЗ2
	{&fEM_B8MV01RSP,8,614},	//(B8MV01RSP) Стартовая скорость АЗ2
	{&fEM_A8MC01RSP,8,616},	//(A8MC01RSP) Стартовая координата ДС2
	{&fEM_A8MV01RSP,8,618},	//(A8MV01RSP) Стартовая скорость ДС2
	{&fEM_A6MC01RSP,8,620},	//(A6MC01RSP) Стартовая координата БЗ1
	{&fEM_A6MV01RSP,8,622},	//(A6MV01RSP) Стартовая скорость БЗ1
	{&fEM_B6MC01RSP,8,624},	//(B6MC01RSP) Стартовая координата БЗ2
	{&fEM_B6MV01RSP,8,626},	//(B6MV01RSP) Стартовая скорость БЗ2
	{&fEM_R3UC01RSP,8,628},	//(R3UC01RSP) Стартовая координата Гомогенных дверей - 1
	{&fEM_R3UV01RSP,8,630},	//(R3UV01RSP) Стартовая скорость Гомогенных дверей-1
	{&fEM_R3UC02RSP,8,632},	//(R3UC02RSP) Стартовая координата Гомогенных дверей - 2
	{&fEM_R3UV02RSP,8,634},	//(R3UV02RSP) Стартовая скорость Гомогенных дверей-2
	{&fEM_R5UC01RSP,8,636},	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
	{&fEM_R5UV01RSP,8,638},	//(R5UV01RSP) Стартовая скорость Ворот отстойной зоны
	{&fEM_R6UC01RSP,8,640},	//(R6UC01RSP) Стартовая координата Кран-балки
	{&fEM_R6UV01RSP,8,642},	//(R6UV01RSP) Стартовая скорость Кран-балки
	{&fEM_R2MC01RSP,8,644},	//(R2MC01RSP) Стартовая координата МДЗ2
	{&fEM_R2MV01RSP,8,646},	//(R2MV01RSP) Стартовая скорость МДЗ2
	{&fEM_R1MC01RSP,8,648},	//(R1MC01RSP) Стартовая координата МДЗ1
	{&fEM_R1MV01RSP,8,650},	//(R1MV01RSP) Стартовая скорость МДЗ1
	{&fEM_A5MC01RSP,8,652},	//(A5MC01RSP) Стартовая координата НЛ1
	{&fEM_A5MV01RSP,8,654},	//(A5MV01RSP) Стартовая скорость НЛ1
	{&fEM_B5MC01RSP,8,656},	//(B5MC01RSP) Стартовая координата НЛ2
	{&fEM_B5MV01RSP,8,658},	//(B5MV01RSP) Стартовая скорость НЛ2
	{&fEM_A9MC01RSP,8,660},	//(A9MC01RSP) Стартовая координата НИ ДС1
	{&fEM_A9MV01RSP,8,662},	//(A9MV01RSP) Стартовая скорость НИ ДС1
	{&fEM_B9MC01RSP,8,664},	//(B9MC01RSP) Стартовая координата НИ ДС2
	{&fEM_B9MV01RSP,8,666},	//(B9MV01RSP) Стартовая скорость НИ ДС2
	{&fEM_A4MC01RSP,8,668},	//(A4MC01RSP) Стартовая координата НИ1
	{&fEM_A4MV01RSP,8,670},	//(A4MV01RSP) Стартовая скорость НИ1
	{&fEM_B4MC01RSP,8,672},	//(B4MC01RSP) Стартовая координата НИ2
	{&fEM_B4MV01RSP,8,674},	//(B4MV01RSP) Стартовая скорость НИ2
	{&fEM_R4MC01RSP,8,676},	//(R4MC01RSP) Стартовая координата тележки
	{&fEM_R4MV01RSP,8,678},	//(R4MV01RSP) Стартовая скорость тележки
	{&fEM_A1MV01RC1,8,680},	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
	{&iEM_TERB7MS31LIM,3,682},	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	{&iEM_TERA7MS31LIM,3,683},	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SBz1[]={  // 
	{&R0EE04LZ1,1,0},	//(R0EE04LZ1) Питание  АКНП4  отключить
	{&R0EE03LZ1,1,1},	//(R0EE03LZ1) Питание  АКНП3  отключить
	{&R0EE02LZ1,1,2},	//(R0EE02LZ1) Питание  АКНП  отключить
	{&R0EE01LZ1,1,3},	//(R0EE01LZ1) Питание  АКНП1  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SBz1[]={  // 
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
static ModbusRegister ir_SBz1[]={  // 
	{&R0VN01RS4,8,0},	//(R0VN01RS4) Период разгона канал 4
	{&R0VN02RS4,8,2},	//(R0VN02RS4) Уровень мощности канал 4
	{&R0VN01RS3,8,4},	//(R0VN01RS3) Период разгона канал 3
	{&R0VN02RS3,8,6},	//(R0VN02RS3) Уровень мощности канал 3
	{&R0VN01RS2,8,8},	//(R0VN01RS2) Период разгона канал 2
	{&R0VN02RS2,8,10},	//(R0VN02RS2) Уровень мощности канал 2
	{&R0VN01RS1,8,12},	//(R0VN01RS1) Период разгона канал1
	{&R0VN02RS1,8,14},	//(R0VN02RS1) Уровень мощности канал1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SBz1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SBz2[]={  // 
	{&R0EE04LZ2,1,0},	//(R0EE04LZ2) Питание  АКНП4  отключить
	{&R0EE03LZ2,1,1},	//(R0EE03LZ2) Питание  АКНП3  отключить
	{&R0EE02LZ2,1,2},	//(R0EE02LZ2) Питание  АКНП  отключить
	{&R0EE01LZ2,1,3},	//(R0EE01LZ2) Питание  АКНП1  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SBz2[]={  // 
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
static ModbusRegister ir_SBz2[]={  // 
	{&R0VN01RS4,8,0},	//(R0VN01RS4) Период разгона канал 4
	{&R0VN02RS4,8,2},	//(R0VN02RS4) Уровень мощности канал 4
	{&R0VN01RS3,8,4},	//(R0VN01RS3) Период разгона канал 3
	{&R0VN02RS3,8,6},	//(R0VN02RS3) Уровень мощности канал 3
	{&R0VN01RS2,8,8},	//(R0VN01RS2) Период разгона канал 2
	{&R0VN02RS2,8,10},	//(R0VN02RS2) Уровень мощности канал 2
	{&R0VN01RS1,8,12},	//(R0VN01RS1) Период разгона канал1
	{&R0VN02RS1,8,14},	//(R0VN02RS1) Уровень мощности канал1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SBz2[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SDu[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SDu[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SDu[]={  // 
	{&A2IC01UDU,5,0},	//(A2IC01UDU) Координата штока РБ1
	{&A3IC01UDU,5,2},	//(A3IC01UDU) Координата штока ИС1
	{&B3IC01UDU,5,4},	//(B3IC01UDU) Координата штока ИС2
	{&A8IC01UDU,5,6},	//(A8IC01UDU) Координата ДС2
	{&B8IC01UDU,5,8},	//(B8IC01UDU) Координата АЗ2
	{&B2IC01UDU,5,10},	//(B2IC01UDU) Координата штока РБ2
	{&A1IC01UDU,5,12},	//(A1IC01UDU) Координата штока ББ1
	{&B1IC01UDU,5,14},	//(B1IC01UDU) Координата штока ББ2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SDu[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,502,&coil_SCM[0],&di_SCM[0],&ir_SCM[0],&hr_SCM[0],NULL,NULL,NULL,0},	 //Общий слэйв
	{0,503,&coil_SBz1[0],&di_SBz1[0],&ir_SBz1[0],&hr_SBz1[0],NULL,NULL,NULL,0},	 //Cлэйв Baz1
	{0,504,&coil_SBz2[0],&di_SBz2[0],&ir_SBz2[0],&hr_SBz2[0],NULL,NULL,NULL,0},	 //Cлэйв Baz2
	{0,505,&coil_SDu[0],&di_SDu[0],&ir_SDu[0],&hr_SDu[0],NULL,NULL,NULL,0},	 //Cлэйв DU

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
	{&B2IP01IZ2,3,21},
	{&B2IP01IZ1,3,9},
	{&B0IT02IZ2,3,18},
	{&B0IT01IZ1,3,6},
	{&A0IT02IZ2,3,12},
	{&A3IP02IDU,3,24},
	{&B3IP02IDU,3,27},
	{&A0IT01IZ1,3,0},
	{&A2IP01IZ1,3,3},
	{&A2IP01IZ2,3,15},
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
	{&A0VN71LS1,1,6},
	{&R0VN75LZ1,1,2},
	{&R0VN72LZ1,1,12},
	{&A0EE01LS1,1,4},
	{&A0VN71LS2,1,18},
	{&R0VN73LZ1,1,38},
	{&R6IS67LZ1,1,34},
	{&R0VN76LZ1,1,14},
	{&A0EE01LS4,1,28},
	{&R0VN78LZ1,1,26},
	{&R6IS68LZ1,1,36},
	{&R0VP82LZ1,1,62},
	{&A0VN71LS4,1,30},
	{&A0EE01LS2,1,16},
	{&R0VN74LZ1,1,24},
	{&R6IS66LZ1,1,32},
	{&A3IS22LZ1,1,10},
	{&A3IS11LZ1,1,8},
	{&A0VN71LS3,1,44},
	{&A0EE01LS3,1,42},
	{&R0VN77LZ1,1,40},
	{&R0VP81LZ1,1,56},
	{&A0VP81LZ1,1,52},
	{&A1VP81LZ1,1,54},
	{&R7II72LZ1,1,48},
	{&R7II71LZ1,1,46},
	{&R7II73LZ1,1,50},
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
	{&A1EE01LS2,1,16},
	{&R0VN73LZ2,1,38},
	{&A1VN71LS1,1,6},
	{&R0VN71LZ2,1,0},
	{&A1VN71LS3,1,44},
	{&R0VN75LZ2,1,2},
	{&A1EE01LS1,1,4},
	{&R0VN76LZ2,1,14},
	{&R0VN72LZ2,1,12},
	{&A1VN71LS2,1,18},
	{&R0VN78LZ2,1,26},
	{&R0VN74LZ2,1,24},
	{&A1VN71LS4,1,30},
	{&A1EE01LS3,1,42},
	{&R0VN77LZ2,1,40},
	{&R7II73LZ2,1,50},
	{&R7II71LZ2,1,46},
	{&R7II72LZ2,1,48},
	{&B0VP81LZ2,1,58},
	{&R0VP81LZ2,1,56},
	{&R6IS68LZ2,1,36},
	{&R6IS67LZ2,1,34},
	{&R6IS66LZ2,1,32},
	{&B3IS22LZ2,1,22},
	{&R0VP82LZ2,1,62},
	{&B1VP81LZ2,1,60},
	{&A1EE01LS4,1,28},
	{&B3IS11LZ2,1,20},
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
	{&B2IS12LDU,1,18},
	{&B2IS11LDU,1,20},
	{&B2IS21LDU,1,22},
	{&A4IS21LDU,1,32},
	{&A4IS11LDU,1,30},
	{&A7AS31LDU,1,60},
	{&B7AS31LDU,1,10},
	{&B9IS21LDU,1,40},
	{&B9IS11LDU,1,38},
	{&A9IS21LDU,1,36},
	{&A9IS11LDU,1,34},
	{&B3IS21LDU,1,24},
	{&B1IS12LDU,1,12},
	{&R8IS11LDU,1,26},
	{&B1IS11LDU,1,14},
	{&B1IS21LDU,1,16},
	{&A1IS12LDU,1,62},
	{&R1IS11LDU,1,42},
	{&R1IS21LDU,1,44},
	{&R2IS11LDU,1,46},
	{&R2IS21LDU,1,48},
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
	{&B2VP82LDU,1,28},
	{&A1IS11LDU,1,0},
	{&A1IS21LDU,1,2},
	{&B6IS21LDU,1,60},
	{&B6IS11LDU,1,58},
	{&A6IS21LDU,1,52},
	{&B5IS11LDU,1,62},
	{&B4VP82LDU,1,30},
	{&R4IS11LDU,1,42},
	{&R4IS21LDU,1,46},
	{&R4IS22LDU,1,48},
	{&R4IS12LDU,1,44},
	{&B8IS12LDU,1,16},
	{&A4VP82LDU,1,24},
	{&B4IS21LDU,1,14},
	{&B4IS11LDU,1,12},
	{&R0IS02LDU,1,32},
	{&A2VP82LDU,1,22},
	{&A3VP81LDU,1,20},
	{&B3VP81LDU,1,26},
	{&A2IS21LDU,1,8},
	{&A2IS11LDU,1,6},
	{&A2IS12LDU,1,4},
	{&A3IS21LDU,1,10},
	{&A5IS11LDU,1,54},
	{&A5IS21LDU,1,56},
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
	{&R3IS31LDU,1,6},
	{&R3IS41LDU,1,8},
	{&B8IS22LDU,1,32},
	{&A8IS22LDU,1,30},
	{&A8IS12LDU,1,28},
	{&R3AD11LDU,1,12},
	{&R3AD21LDU,1,16},
	{&R5AD20LDU,1,24},
	{&R6IS21LDU,1,26},
	{&B5IS21LDU,1,0},
	{&R3IS11LDU,1,2},
	{&R3IS21LDU,1,4},
	{&R5IS11LDU,1,18},
	{&R5IS21LDU,1,20},
	{&A6IS11LDU,1,34},
	{&R5AD10LDU,1,22},
	{&R3AD10LDU,1,10},
	{&R3AD20LDU,1,14},
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
	{&R6IS65LDU,1,62},
	{&R6IS64LDU,1,60},
	{&R6IS63LDU,1,58},
	{&R6IS62LDU,1,56},
	{NULL,0,0},
};
#pragma pop
#include "drivers/emul8enc.h"
static char buf_em8enc120[40];	//em8enc(0x120)
static em8encpti_inimod ini_em8enc120={0x340,0x4,};
#pragma pack(push,1)
static table_drv table_em8enc120={0,0,&ini_em8enc120,buf_em8enc120,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_em8enc120[]={
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
	{&A4AD10LDU,1,28},
	{&B4AD10LDU,1,56},
	{&B3AD31LDU,1,58},
	{&A3AD31LDU,1,30},
	{&B3AD34LDU,1,50},
	{&A8AD10LDU,1,62},
	{&B3AD33LDU,1,52},
	{&A3AD33LDU,1,24},
	{&R2AD20LDU,1,40},
	{&A5AD10LDU,1,42},
	{&A5AD20LDU,1,44},
	{&B5AD10LDU,1,46},
	{&B2AD33LDU,1,54},
	{&B5AD20LDU,1,48},
	{&A3AD34LDU,1,22},
	{&R1AD10LDU,1,34},
	{&R1AD20LDU,1,36},
	{&R2AD10LDU,1,38},
	{&A7AP31LDU,1,32},
	{&A2AD33LDU,1,26},
	{&B7AP31LDU,1,60},
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
	{&B8AD20LDU,1,16},
	{&B8AD10LDU,1,14},
	{&R4AD20LDU,1,12},
	{&R4AD10LDU,1,10},
	{&B3AD05LDU,1,44},
	{&B3AD04LDU,1,42},
	{&B3AD03LDU,1,40},
	{&B3AD02LDU,1,38},
	{&B3AD01LDU,1,36},
	{&B9AD10LDU,1,48},
	{&A9AD10LDU,1,46},
	{&B6AD20LDU,1,8},
	{&B6AD10LDU,1,6},
	{&A6AD20LDU,1,4},
	{&A3AD11LDU,1,18},
	{&A3AD21LDU,1,20},
	{&A3AD01LDU,1,22},
	{&A3AD02LDU,1,24},
	{&A3AD03LDU,1,26},
	{&A3AD04LDU,1,28},
	{&A3AD05LDU,1,30},
	{&B3AD11LDU,1,32},
	{&B3AD21LDU,1,34},
	{&A1AD11LDU,1,50},
	{&A1AD21LDU,1,52},
	{&A1AD01LDU,1,54},
	{&A1AD02LDU,1,56},
	{&A1AD03LDU,1,58},
	{&A1AD04LDU,1,60},
	{&A6AD10LDU,1,2},
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
	{&B1AD31LDU,1,54},
	{&B1AD32LDU,1,52},
	{&B2AD31LDU,1,58},
	{&B2AD32LDU,1,56},
	{&A1AD31LDU,1,46},
	{&A2AD04LDU,1,26},
	{&A2AD05LDU,1,28},
	{&B2AD11LDU,1,30},
	{&B2AD21LDU,1,32},
	{&B2AD01LDU,1,34},
	{&B2AD02LDU,1,36},
	{&B2AD03LDU,1,38},
	{&B2AD04LDU,1,40},
	{&B2AD05LDU,1,42},
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
	{&R0AD16LDU,1,62},
	{&R8AD21LDU,1,60},
	{&A2AD32LDU,1,48},
	{&A2AD31LDU,1,50},
	{&A1AD32LDU,1,44},
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
	{0x05,0x120,2,40,def_buf_em8enc120,&table_em8enc120}, //em8enc(0x120)
	{0x03,0x340,1,66,def_buf_VDS32F07,&table_VDS32F07}, //vds32f2(0x340)
	{0x03,0x360,1,66,def_buf_VDS32F10,&table_VDS32F10}, //vds32f2(0x360)
	{0x03,0x310,1,66,def_buf_VDS32F11,&table_VDS32F11}, //vds32f2(0x310)
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
	setAsFloat(331,0.015);
	setAsFloat(332,0.0069);
	setAsFloat(333,0.21);
	setAsFloat(334,0);
	setAsFloat(335,0);
	setAsFloat(336,0.0096);
	setAsFloat(337,0.0026);
	setAsFloat(338,106);
	setAsFloat(339,135.227);
	setAsFloat(340,25);
	setAsFloat(341,320.435466);
	setAsFloat(342,0.0055);
	setAsFloat(343,0.000877);
	setAsFloat(344,200);
	setAsFloat(345,100);
	setAsFloat(346,0);
	setAsFloat(347,0);
	setAsFloat(348,100);
	setAsFloat(349,80);
	setAsFloat(350,0.002375);
	setAsFloat(351,0);
	setAsFloat(352,165);
	setAsFloat(353,200);
	setAsFloat(354,0.001667);
	setAsFloat(355,40);
	setAsFloat(356,15630.0);
	setAsFloat(357,1374);
	setAsFloat(358,0);
	setAsFloat(359,390.0);
	setAsFloat(360,2000.0);
	setAsFloat(361,1500.0);
	setAsFloat(362,10.91);
	setAsFloat(363,10.91);
	setAsFloat(364,1500.0);
	setAsFloat(365,2000);
	setAsFloat(366,390.0);
	setAsFloat(367,0);
	setAsFloat(368,55.0);
	setAsFloat(369,15.0);
	setAsFloat(370,5.0);
	setAsFloat(371,1E12);
	setAsFloat(372,43.6);
	setAsFloat(373,506.5);
	setAsFloat(374,20.0);
	setAsFloat(375,20.0);
	setAsFloat(376,20.0);
	setAsFloat(377,1269.0);
	setAsFloat(378,256.0);
	setAsFloat(379,1.0);
	setAsFloat(380,2.0);
	setAsFloat(381,0);
	setAsFloat(382,0.026);
	setAsFloat(383,0.08);
	setAsFloat(384,0.0);
	setAsFloat(385,27.108);
	setAsFloat(386,600);
	setAsFloat(387,0);
	setAsFloat(388,0.00009765625);
	setAsFloat(389,1.6);
	setAsFloat(390,0);
	setAsFloat(391,0.00009765625);
	setAsFloat(392,2.5);
	setAsFloat(393,0);
	setAsFloat(394,0.00009765625);
	setAsFloat(395,10000.0);
	setAsFloat(396,0.0009765625);
	setAsFloat(397,750);
	setAsFloat(398,100);
	setAsFloat(399,200);
	setAsFloat(400,300);
	setAsFloat(401,400);
	setAsFloat(402,500);
	setAsFloat(403,600);
	setAsFloat(404,0.50);
	setAsFloat(405,0.50);
	setAsFloat(406,0.50);
	setAsFloat(407,11.0);
	setAsFloat(408,1585.0);
	setAsFloat(409,1796.0);
	setAsFloat(410,1555.0);
	setAsFloat(411,1269.0);
	setAsFloat(412,1269.0);
	setAsFloat(413,1585.0);
	setAsFloat(414,1796.0);
	setAsFloat(415,1269.0);
	setAsFloat(416,248.0);
	setAsFloat(417,284.5);
	setAsFloat(418,248.0);
	setAsFloat(419,271.6);
	setAsFloat(420,287.2);
	setAsFloat(421,594.0);
	setAsFloat(422,559.0);
	setAsFloat(423,588.0);
	setAsFloat(424,1555.0);
	setAsFloat(425,1281.2);
	setAsFloat(426,1269.0);
	setAsFloat(427,594.0);
	setAsFloat(428,597.2);
	setAsFloat(429,556.8);
	setAsFloat(430,1.0);
	setAsFloat(431,1.0);
	setAsFloat(432,1.0);
	setAsFloat(433,1.0);
	setAsFloat(434,1.0);
	setAsFloat(435,1.0);
	setAsFloat(436,1.0);
	setAsFloat(437,1.0);
	setAsFloat(438,1.0);
	setAsFloat(439,1.0);
	setAsFloat(440,1.0);
	setAsFloat(441,1.0);
	setAsFloat(442,0);
	setAsFloat(443,0);
	setAsFloat(444,0);
	setAsFloat(445,0);
	setAsFloat(446,0.0);
	setAsFloat(447,0);
	setAsFloat(448,0.0);
	setAsFloat(449,0);
	setAsFloat(450,0.0);
	setAsFloat(451,0.0);
	setAsFloat(452,0.0);
	setAsFloat(453,0.0);
	setAsFloat(454,3703.704);
	setAsFloat(455,62500.0);
	setAsFloat(456,20);
	setAsFloat(457,10000);
	setAsFloat(458,10000);
	setAsFloat(459,5000);
	setAsFloat(460,0.76);
	setAsFloat(461,0.245);
	setAsFloat(462,2.9);
	setAsFloat(463,0.13);
	setAsFloat(464,0.73);
	setAsFloat(465,3.04);
	setAsFloat(466,14.7);
	setAsFloat(467,0.41);
	setAsFloat(468,9807.0);
	setAsFloat(469,22975.0);
	setAsFloat(470,12750.0);
	setAsFloat(471,20);
	setAsFloat(472,20);
	setAsFloat(473,0);
	setAsFloat(474,5.0);
	setAsFloat(475,5.0);
	setAsFloat(476,5.0);
	setAsFloat(477,100.0);
	setAsFloat(478,4000);
	setAsFloat(479,100000);
	setAsFloat(480,1000000);
	setAsFloat(481,10.0);
	setAsFloat(482,5100);
	setAsFloat(483,20);
	setAsFloat(484,13.0);
	setAsFloat(485,5000);
	setAsFloat(486,32000.0);
	setAsFloat(487,0.00001);
	setAsFloat(488,5.0);
	setAsFloat(489,15.0);
	setAsFloat(490,15.0);
	setAsFloat(491,20.0);
	setAsFloat(492,10.0);
	setAsBool(493,0);
	setAsBool(494,0);
	setAsBool(495,0);
	setAsFloat(496,5.88);
	setAsFloat(497,0.45);
	setAsFloat(498,0.39);
	setAsFloat(499,2.74);
	setAsFloat(500,0.07);
	setAsFloat(501,0.275);
	setAsFloat(502,0.245);
	setAsFloat(503,0.045);
	setAsFloat(504,0.05);
	setAsShort(505,0);
	setAsFloat(506,0);
	setAsFloat(507,0);
	setAsShort(508,0);
	setAsFloat(509,0);
	setAsFloat(510,0);
	setAsShort(511,0);
	setAsFloat(512,0);
	setAsFloat(513,0);
	setAsShort(514,0);
	setAsFloat(515,0);
	setAsFloat(516,0);
	setAsShort(517,0);
	setAsFloat(518,0);
	setAsFloat(519,0);
	setAsShort(520,0);
	setAsFloat(521,0);
	setAsFloat(522,0);
	setAsShort(523,0);
	setAsShort(524,0);
	setAsFloat(525,0);
	setAsShort(526,0);
	setAsShort(527,0);
	setAsFloat(528,0);
	setAsFloat(529,0);
	setAsFloat(530,0);
	setAsFloat(531,0);
	setAsFloat(532,0);
	setAsFloat(533,0);
	setAsFloat(534,0);
	setAsFloat(535,0);
	setAsShort(536,0);
	setAsShort(537,0);
	setAsShort(538,0);
	setAsShort(539,0);
	setAsShort(540,0);
	setAsShort(541,0);
	setAsShort(542,0);
	setAsShort(543,0);
	setAsShort(544,0);
	setAsShort(545,0);
	setAsShort(546,0);
	setAsShort(547,0);
	setAsShort(548,0);
	setAsShort(549,0);
	setAsShort(550,0);
	setAsShort(551,0);
	setAsShort(552,0);
	setAsShort(553,0);
	setAsShort(554,0);
	setAsShort(555,0);
	setAsShort(556,0);
	setAsShort(557,0);
	setAsShort(558,0);
	setAsShort(559,0);
	setAsShort(560,0);
	setAsShort(561,0);
	setAsShort(562,0);
	setAsShort(563,0);
	setAsShort(564,0);
	setAsShort(565,0);
	setAsShort(566,0);
	setAsShort(567,0);
	setAsShort(568,0);
	setAsShort(569,0);
	setAsShort(570,0);
	setAsShort(571,0);
	setAsShort(572,0);
	setAsShort(573,0);
	setAsShort(574,0);
	setAsShort(575,0);
	setAsShort(576,0);
	setAsShort(577,0);
	setAsShort(578,0);
	setAsShort(579,0);
	setAsShort(580,0);
	setAsShort(581,0);
	setAsShort(582,0);
	setAsShort(583,0);
	setAsShort(584,0);
	setAsShort(585,0);
	setAsShort(586,0);
	setAsShort(587,0);
	setAsShort(588,0);
	setAsShort(589,0);
	setAsShort(590,0);
	setAsShort(591,0);
	setAsShort(592,0);
	setAsShort(593,0);
	setAsShort(594,0);
	setAsShort(595,0);
	setAsShort(596,0);
	setAsShort(597,0);
	setAsShort(598,0);
	setAsShort(599,0);
	setAsShort(600,0);
	setAsShort(601,0);
	setAsShort(602,0);
	setAsShort(603,0);
	setAsShort(604,0);
	setAsShort(605,0);
	setAsShort(606,0);
	setAsShort(607,0);
	setAsShort(608,0);
	setAsShort(609,0);
	setAsShort(610,0);
	setAsShort(611,0);
	setAsShort(612,0);
	setAsShort(613,0);
	setAsShort(614,0);
	setAsShort(615,0);
	setAsShort(616,0);
	setAsShort(617,0);
	setAsShort(618,0);
	setAsShort(619,0);
	setAsShort(620,0);
	setAsShort(621,0);
	setAsShort(622,0);
	setAsShort(623,0);
	setAsBool(624,1);
	setAsShort(625,0);
	setAsShort(626,0);
	setAsBool(627,1);
	setAsShort(628,0);
	setAsShort(629,0);
	setAsBool(630,1);
	setAsShort(631,0);
	setAsShort(632,0);
	setAsBool(633,1);
	setAsShort(634,0);
	setAsFloat(635,0);
	setAsFloat(636,0);
	setAsShort(637,0);
	setAsFloat(638,0);
	setAsFloat(639,0);
	setAsShort(640,0);
	setAsFloat(641,0);
	setAsFloat(642,0);
	setAsShort(643,0);
	setAsFloat(644,0);
	setAsFloat(645,0);
	setAsShort(646,0);
	setAsFloat(647,0);
	setAsFloat(648,0);
	setAsShort(649,0);
	setAsShort(650,0);
	setAsShort(651,0);
	setAsShort(652,0);
	setAsShort(653,0);
	setAsShort(654,0);
	setAsBool(655,0);
	setAsBool(656,0);
	setAsBool(657,0);
	setAsBool(658,0);
	setAsBool(659,0);
	setAsBool(660,1);
	setAsBool(661,0);
	setAsShort(662,0);
	setAsFloat(663,0);
	setAsFloat(664,0);
	setAsShort(665,0);
	setAsFloat(666,0);
	setAsFloat(667,0);
	setAsShort(668,0);
	setAsFloat(669,0);
	setAsFloat(670,0);
	setAsShort(671,0);
	setAsFloat(672,0);
	setAsFloat(673,0);
	setAsBool(674,1);
	setAsFloat(675,0.01);
	setAsFloat(676,0.01);
	setAsFloat(677,0.01);
	setAsFloat(678,0.5);
	setAsFloat(679,100.0);
	setAsShort(680,0);
	setAsShort(681,0);
	setAsShort(682,0);
	setAsFloat(683,25);
	setAsFloat(684,-0.18505518);
	setAsFloat(685,0.0);
	setAsFloat(686,25);
	setAsFloat(687,0);
	setAsFloat(688,0);
	setAsFloat(689,0);
	setAsFloat(690,0);
	setAsFloat(691,0);
	setAsFloat(692,0);
	setAsFloat(693,0);
	setAsFloat(694,0);
	setAsFloat(695,0);
	setAsFloat(696,0);
	setAsFloat(697,0);
	setAsFloat(698,0);
	setAsFloat(699,0);
	setAsFloat(700,0);
	setAsFloat(701,0);
	setAsFloat(702,0);
	setAsFloat(703,0);
	setAsFloat(704,0);
	setAsFloat(705,0);
	setAsFloat(706,0);
	setAsFloat(707,0);
	setAsFloat(708,0);
	setAsFloat(709,0);
	setAsFloat(710,0);
	setAsFloat(711,0);
	setAsFloat(712,0);
	setAsFloat(713,1500);
	setAsFloat(714,0);
	setAsFloat(715,1500);
	setAsFloat(716,0);
	setAsFloat(717,0);
	setAsFloat(718,0);
	setAsFloat(719,0);
	setAsFloat(720,0);
	setAsFloat(721,0);
	setAsFloat(722,0);
	setAsFloat(723,0);
	setAsFloat(724,0);
	setAsFloat(725,4000.0);
	setAsFloat(726,0);
	setAsFloat(727,0);
	setAsFloat(728,0);
	setAsFloat(729,0);
	setAsFloat(730,0);
	setAsFloat(731,0);
	setAsFloat(732,0);
	setAsFloat(733,0);
	setAsFloat(734,0);
	setAsFloat(735,0);
	setAsFloat(736,0);
	setAsFloat(737,15.0);
	setAsFloat(738,0);
	setAsFloat(739,15.0);
	setAsFloat(740,0);
	setAsFloat(741,5.0);
	setAsFloat(742,0);
	setAsFloat(743,5.0);
	setAsFloat(744,0);
	setAsFloat(745,1374);
	setAsFloat(746,0);
	setAsFloat(747,0);
	setAsShort(748,0);
	setAsShort(749,0);
}
/* Определение внутренних параметров */
uspaint8 InternalBuf[1025];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssbool lRM_1_ = {1,0}; /* Флаг наличия магнита на штоке ОРР */ 
ssfloat fRM_0_ = {0,0}; /* Заглушка давления на подъём ББ1 */ 
ssfloat fRM_1_ = {1,0}; /* *Vm - массив скоростей движения (шагов в секунду) */ 
ssbool lRM_0_ = {0,0}; /* Флаг наличия магнита на штоке ОРР */ 
ssfloat fRM_1_0 = {1.0,0}; /* Номинальная скорость БЗ (град/с) */ 
ssfloat fRM_180_0 = {180.0,0}; /* Координата верхнего путевого выключателя БЗ град */ 
ssfloat fRM_0_0 = {0.0,0}; /* Координата нижних упоров БЗ град */ 
ssfloat fRM_n50_ = {-50,0}; /* Координата нижнего путевого выключателя БЗ град */ 
ssfloat fRM_2000_0 = {2000.0,0}; /* Координата верхнего путевого выключателя МДЗ мм */ 
ssfloat fRM_n150_ = {-150,0}; /* Координата нижнего путевого выключателя МДЗ мм */ 
ssfloat fRM_1500_0 = {1500.0,0}; /* Координата верхнего механического выключателя НЛ мм */ 
ssint iRM_7_ = {7,0}; /* N */ 
ssfloat fRM_390_ = {390,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
ssfloat fRM_420_ = {420,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
ssfloat fRM_513_ = {513,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
ssfloat fRM_767_ = {767,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
ssfloat fRM_900_ = {900,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
ssfloat fRM_1200_ = {1200,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
ssfloat fRM_1500_ = {1500,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
ssfloat fRM_3_546 = {3.546,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_2_7 = {2.7,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_2_ = {2,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_88884 = {0.88884,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_6221739 = {0.6221739,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_35555072 = {0.35555072,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_2666666667 = {0.2666666667,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssint iRM_5_ = {5,0}; /* N */ 
ssfloat fRM_600_ = {600,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
ssfloat fRM_0_5 = {0.5,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_2 = {0.2,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_088884 = {0.088884,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_066666667 = {0.066666667,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_02173913 = {0.02173913,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_002453 = {0.002453,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_00184 = {0.00184,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_10 = {0.10,0}; /* Зона срабатывания КВ БЗ(мм) */ 
ssfloat fRM_0_50 = {0.50,0}; /* Зона срабатывания КВ МДЗ (мм) */ 
ssint iRM_2_ = {2,0}; /* n - N-размерность массива x */ 
ssint iRM_3_ = {3,0}; /* N-число входов */ 
ssint iRM_4_ = {4,0}; /* N-число входов */ 
ssint iRM_0_ = {0,0}; /* Ter - Неисправности механизма */ 
ssfloat fRM_100000_ = {100000,0}; /* KPv - координата пер. выключателя механизма мм */ 
ssfloat fRM_n100_ = {-100,0}; /* KZv - координата зад. выключателя механизма мм */ 
ssfloat fRM_20_ = {20,0}; /* Tp - Тормозной путь мм */ 
sschar bRM_2_ = {2,0}; /* type - тип камеры */ 
ssfloat fRM_2_0 = {2.0,0}; /* Коэфф. преобразования частота->нейтр/с  СНМ11 */ 
sschar bRM_4_ = {4,0}; /* type - тип камеры */ 
sschar bRM_5_ = {5,0}; /* type - тип камеры */ 
sschar bRM_1_ = {1,0}; /* type - тип камеры */ 
ssint iRM_500_ = {500,0}; /* tz - ширина импульса, 10-ки мс */ 
ssint iRM_18_ = {18,0}; /* n - размер массива значений параметров датчиков нейтронного потока */ 
char sRM_1[] = "A3SS11LIM"; /* agr - наименование сигнала */ 
ssfloat fRM_3_ = {3,0}; /* m1 - величина отклонения второго сигнала от входного */ 
ssint iRM_719_ = {719,0}; /* min - минимальное возможное значение выходного сигнала */ 
ssint iRM_4195_ = {4195,0}; /* max - максимальное возможное значение выходного сигнала */ 
ssfloat fRM_819_ = {819,0}; /* c   - мин. значение кода ФАС */ 
ssfloat fRM_4095_ = {4095,0}; /* d - макс.  значение кода ФАС */ 
ssfloat fRM_200_ = {200,0}; /* maxs1 - макc. значение второго сигнала */ 
ssfloat fRM_0_0015 = {0.0015,0}; /* m1 - величина отклонения второго сигнала от входного */ 
ssfloat fRM_0_001 = {0.001,0}; /* ampl - амплетуда синусоидального отклонения */ 
ssfloat fRM_0_1 = {0.1,0}; /* k - коэффициент усиления */ 
ssint iRM_16_ = {16,0}; /* n - N-размерность массива входных параметров */ 

uspaint8 SpaEEPROMBuf[1802];

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
ssfloat var27;
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
sslong var59;
ssfloat var60;
sslong var61;
ssfloat var62;
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
ssint var97;
ssint var98;
ssfloat var99;
ssfloat var100;
sslong var101;
ssfloat var102;
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
ssfloat var114;
ssbool var115;
ssbool var116;
ssbool var117;
ssbool var118;
ssbool var119;
ssbool var120;
ssbool var121;
ssbool var122;
sslong var123;
ssfloat var124;
sslong var125;
ssfloat var126;
ssbool var127;
ssbool var128;
ssbool var129;
ssbool var130;
ssbool var131;
ssbool var132;
ssbool var133;
ssbool var134;
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
ssint var145;
ssfloat var146;
ssbool var147;
ssbool var148;
ssint var149;
ssfloat var150;
ssbool var151;
sslong var152;
ssfloat var153;
ssbool var154;
ssbool var155;
sslong var156;
ssfloat var157;
ssbool var158;
ssint var159;
ssint var160;
ssbool var161;
ssbool var162;
ssbool var163;
sslong var164;
ssfloat var165;
ssbool var166;
ssbool var167;
ssbool var168;
ssfloat var169;
ssfloat var170;
ssfloat var171;
ssint var172;
ssint var173;
ssfloat var174;
ssfloat var175;
ssfloat var176;
ssint var177;
ssbool var178;
ssbool var179;
ssint var180;
ssfloat var181;
ssfloat var182;
ssfloat var183;
ssbool var184;
ssbool var185;
ssbool var186;
ssbool var187;
ssfloat var188;
ssbool var189;
ssbool var190;
ssbool var191;
ssbool var192;
ssbool var193;
ssfloat var194;
ssbool var195;
ssint var196;
ssbool var197;
ssbool var198;
ssbool var199;
ssbool var200;
ssfloat var201;
ssbool var202;
ssbool var203;
ssbool var204;
ssbool var205;
ssbool var206;
ssfloat var207;
ssbool var208;
ssint var209;
ssbool var210;
ssbool var211;
ssbool var212;
ssbool var213;
ssfloat var214;
ssbool var215;
ssbool var216;
ssbool var217;
ssbool var218;
ssbool var219;
ssfloat var220;
ssbool var221;
ssint var222;
ssbool var223;
ssbool var224;
ssbool var225;
ssbool var226;
ssfloat var227;
ssbool var228;
ssbool var229;
ssbool var230;
ssbool var231;
ssbool var232;
ssfloat var233;
ssbool var234;
ssint var235;
ssbool var236;
ssbool var237;
ssbool var238;
ssbool var239;
ssfloat var240;
ssbool var241;
ssfloat var242;
ssbool var243;
ssbool var244;
ssbool var245;
ssbool var246;
ssbool var247;
ssbool var248;
ssbool var249;
ssbool var250;
ssbool var251;
ssbool var252;
ssfloat var253;
ssbool var254;
ssbool var255;
ssbool var256;
ssbool var257;
ssbool var258;
ssbool var259;
ssbool var260;
ssbool var261;
ssbool var262;
ssbool var263;
ssbool var264;
ssbool var265;
ssbool var266;
ssbool var267;
ssbool var268;
ssbool var269;
ssbool var270;
ssbool var271;
ssbool var272;
ssbool var273;
ssbool var274;
ssbool var275;
ssbool var276;
ssbool var277;
ssbool var278;
ssbool var279;
ssbool var280;
ssbool var281;
ssbool var282;
ssbool var283;
ssbool var284;
ssbool var285;
ssbool var286;
ssbool var287;
ssbool var288;
ssbool var289;
ssbool var290;
ssbool var291;
ssbool var292;
ssbool var293;
ssbool var294;
ssfloat var295;
ssfloat var296;
ssfloat var297;
ssfloat var298;
ssfloat var299;
ssfloat var300;
ssfloat var301;
ssfloat var302;
ssfloat var303;
ssbool var304;
ssbool var305;
ssbool var306;
ssfloat var307;
ssfloat var308;
ssfloat var309;
ssfloat var310;
ssfloat var311;
ssfloat var312;
ssfloat var313;
ssfloat var314;
ssfloat var315;
ssfloat var316;
ssfloat var317;
ssfloat var318;
ssfloat var319;
ssbool var320;
ssbool var321;
ssbool var322;
ssbool var323;
ssbool var324;
ssbool var325;
ssbool var326;
ssbool var327;
ssbool var328;
ssbool var329;
ssbool var330;
ssbool var331;
ssfloat var332;
ssbool var333;
ssbool var334;
ssfloat var335;
ssbool var336;
ssbool var337;
ssbool var338;
ssbool var339;
ssbool var340;
ssbool var341;
ssfloat var342;
ssfloat var343;
ssfloat var344;
ssfloat var345;
ssbool var346;
ssfloat var347;
ssfloat var348;
ssfloat var349;
ssfloat var350;
ssbool var351;
ssbool var352;
ssbool var353;
ssbool var354;
ssbool var355;
ssfloat var356;
ssfloat var357;
ssbool var358;
ssbool var359;
ssbool var360;
ssbool var361;
ssbool var362;
ssfloat var363;
ssfloat var364;
ssbool var365;
ssbool var366;
ssbool var367;
ssbool var368;
ssbool var369;
ssbool var370;
ssfloat var371;
ssfloat var372;
ssbool var373;
ssbool var374;
ssbool var375;
ssbool var376;
ssbool var377;
ssbool var378;
ssfloat var379;
ssfloat var380;
ssbool var381;
ssbool var382;
ssbool var383;
ssbool var384;
ssbool var385;
ssfloat var386;
ssfloat var387;
ssbool var388;
ssbool var389;
ssbool var390;
ssbool var391;
ssbool var392;
ssfloat var393;
ssfloat var394;
ssfloat var395;
ssfloat var396;
ssbool var397;
ssfloat var398;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m363_x_1[16] = {&var397,&var346,&var392,&var263,&var257,&var336,&var334,&var330,&var329,&var341,&var382,&var377,&var368,&var358,&var352,&R0MW13LP2};
psfloat  array_m1099_tst_1[2];
psfloat  array_m1099_trz_1[2];
psfloat  array_m1099_N1_1[2];
psfloat  array_m1099_N2_1[2];
psfloat  array_m1041_tst_1[2];
psfloat  array_m1041_trz_1[2];
psfloat  array_m1041_N1_1[2];
psfloat  array_m1041_N2_1[2];
psfloat  array_m910_tst_1[2];
psfloat  array_m910_trz_1[2];
psfloat  array_m910_N1_1[2];
psfloat  array_m910_N2_1[2];
psfloat  array_m855_tst_1[2];
psfloat  array_m855_trz_1[2];
psfloat  array_m855_N1_1[2];
psfloat  array_m855_N2_1[2];
psbool  array_m1191_x_1[2] = {&lEM_R0IE02LRP,&lEM_R0IE01LRP};
psbool  array_m1188_x_1[2] = {&var238,&R0MW13LP2};
psbool  array_m1209_x_1[2] = {&var246,&R0MW13LP2};
psbool  array_m1204_x_1[2] = {&var248,&R0MW13LP2};
psbool  array_m1198_x_1[2] = {&var250,&R0MW13LP2};
psbool  array_m679_x_1[2] = {&var19,&var305};
psbool  array_m676_x_1[2] = {&var19,&var306};
psbool  array_m685_x_1[3] = {&lEM_C1AD31LRP,&R0VZ71LZ1,&R0VZ71LZ2};
psbool  array_m1193_x_1[2] = {&var276,&R0MW13LP2};
psbool  array_m290_x_1[2] = {&var293,&B3AD31LDU};
psbool  array_m255_x_1[3] = {&B2AD31LDU,&var279,&var293};
psbool  array_m256_x_1[3] = {&B2AD32LDU,&var279,&var293};
psbool  array_m216_x_1[4] = {&B1AD32LDU,&var282,&var281,&var293};
psbool  array_m215_x_1[4] = {&var282,&B1AD31LDU,&var281,&var293};
psbool  array_m121_x_1[2] = {&A3AD31LDU,&var293};
psbool  array_m48_x_1[4] = {&A1AD32LDU,&var287,&var286,&var293};
psbool  array_m47_x_1[4] = {&var287,&A1AD31LDU,&var286,&var293};
psbool  array_m87_x_1[3] = {&A2AD31LDU,&var291,&var293};
psbool  array_m88_x_1[3] = {&A2AD32LDU,&var291,&var293};
psbool  array_m692_x_1[2] = {&var304,&var18};
psfloat  array_m7_a_1[5] = {&fRM_390_,&fRM_600_,&fRM_900_,&fRM_1200_,&fRM_1500_};
psfloat  array_m7_b_1[5] = {&fRM_0_5,&fRM_0_2,&fRM_0_088884,&fRM_0_066666667,&fRM_0_02173913};
psfloat  array_m9_a_1[7] = {&fRM_390_,&fRM_420_,&fRM_513_,&fRM_767_,&fRM_900_,&fRM_1200_,&fRM_1500_};
psfloat  array_m9_b_1[7] = {&fRM_3_546,&fRM_2_7,&fRM_2_,&fRM_0_88884,&fRM_0_6221739,&fRM_0_35555072,&fRM_0_2666666667};
psfloat  array_m180_C0_1[6];
psfloat  array_m298_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m131_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m265_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m99_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m227_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m60_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m14_C0_1[6];

/* Объявление структур */
_S_twobool  S_twobool_563_1 = {&var26,&iEM_TERA1VP81LIM,&var1,&var2,&internal1_m563_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_582_1 = {&var26,&iEM_TERB1VP81LIM,&var3,&var4,&internal1_m582_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_417_1 = {&var368,&iEM_TERB2SS33LIM,&var5,&vainSBool,&internal1_m417_Out10,&bFirstEnterFlag};
_S_noto  S_noto_520_1 = {&var259,&var6};
_S_noto  S_noto_521_1 = {&var258,&var7};
_S_noto  S_noto_493_1 = {&var260,&var8};
_S_noto  S_noto_495_1 = {&var261,&var9};
_S_noto  S_noto_498_1 = {&var254,&var10};
_S_noto  S_noto_500_1 = {&var255,&var11};
_S_rs  S_rs_514_1 = {&var7,&lEM_R5AD10LC1,&var12,&vainSBool,&internal1_m514_q0};
_S_rs  S_rs_515_1 = {&var6,&lEM_R5AD20LC1,&var13,&vainSBool,&internal1_m515_q0};
_S_rs  S_rs_484_1 = {&var8,&lEM_R3AD10LC1,&var14,&vainSBool,&internal1_m484_q0};
_S_rs  S_rs_485_1 = {&var9,&lEM_R3AD20LC1,&var15,&vainSBool,&internal1_m485_q0};
_S_rs  S_rs_486_1 = {&var10,&lEM_R3AD11LC1,&var16,&vainSBool,&internal1_m486_q0};
_S_rs  S_rs_487_1 = {&var11,&lEM_R3AD21LC1,&var17,&vainSBool,&internal1_m487_q0};
_S_andn  S_andn_363_1 = {array_m363_x_1,&iRM_16_,&vainSBool};
_S_zpfs  S_zpfs_689_1 = {&R0AD14LDU,&fEM_R7UI76RIM,&var18,&internal1_m689_tx,&internal1_m689_y0};
_S_zpfs  S_zpfs_677_1 = {&R0AD16LDU,&fEM_R7UI77RIM,&var19,&internal1_m677_tx,&internal1_m677_y0};
_S_bol  S_bol_1231_1 = {&fEM_A4UP01RIM,&fEM_A4UP02RIM,&var20};
_S_bol  S_bol_1233_1 = {&fEM_A3UP01RIM,&fEM_A3UP02RIM,&var21};
_S_bol  S_bol_1226_1 = {&fEM_A0UP02RIM,&fEM_A0UP01RIM,&var22};
_S_bol  S_bol_1220_1 = {&fEM_A2UP02RIM,&fEM_A2UP03RIM,&var23};
_S_bol  S_bol_1228_1 = {&fEM_A0UP03RIM,&fEM_R0UP85RIM,&var24};
_S_bol  S_bol_1222_1 = {&fEM_R0UP88RIM,&fEM_A0UP03RIM,&var25};
_S_bol  S_bol_1219_1 = {&fEM_A1UP01RIM,&fEM_A1UP82RIM,&var26};
_S_ampl  S_ampl_380_1 = {&var295,&fRM_0_1,&var27};
_S_or2  S_or2_1211_1 = {&R0EE04LZ1,&R0EE04LZ2,&var28};
_S_or2  S_or2_1206_1 = {&R0EE03LZ1,&R0EE03LZ2,&var29};
_S_or2  S_or2_1200_1 = {&R0EE02LZ1,&R0EE02LZ2,&var30};
_S_or2  S_or2_1195_1 = {&R0EE01LZ1,&R0EE01LZ2,&var31};
_S_twobool  S_twobool_517_1 = {&var13,&iEM_TERR5AD20LDU,&var32,&vainSBool,&internal1_m517_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_491_1 = {&var17,&iEM_TERR3AD21LDU,&var33,&vainSBool,&internal1_m491_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_490_1 = {&var16,&iEM_TERR3AD11LDU,&var34,&vainSBool,&internal1_m490_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_489_1 = {&var15,&iEM_TERR3AD20LDU,&var35,&vainSBool,&internal1_m489_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_488_1 = {&var14,&iEM_TERR3AD10LDU,&var36,&vainSBool,&internal1_m488_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_516_1 = {&var12,&iEM_TERR5AD10LDU,&var37,&vainSBool,&internal1_m516_Out10,&bFirstEnterFlag};
_S_and5  S_and5_1115_1 = {&var195,&var186,&var187,&var185,&lEM_A0EE06LC1,&var38};
_S_and2  S_and2_1109_1 = {&var190,&var189,&var39};
_S_and2  S_and2_1108_1 = {&var190,&var191,&var40};
_S_and5  S_and5_927_1 = {&var221,&var211,&var212,&var213,&lEM_A0EE04LC1,&var41};
_S_and2  S_and2_921_1 = {&var216,&var215,&var42};
_S_and2  S_and2_920_1 = {&var216,&var217,&var43};
_S_and2  S_and2_1051_1 = {&var203,&var202,&var44};
_S_and2  S_and2_1050_1 = {&var204,&var203,&var45};
_S_and5  S_and5_1058_1 = {&var208,&var199,&var198,&var200,&lEM_A0EE05LC1,&var46};
_S_and5  S_and5_868_1 = {&var234,&var225,&var224,&var226,&lEM_A0EE03LC1,&var47};
_S_and2  S_and2_866_1 = {&var229,&var228,&var48};
_S_and2  S_and2_865_1 = {&var229,&var230,&var49};
_S_zpfs  S_zpfs_663_1 = {&var262,&fRM_1_0,&var50,&internal1_m663_tx,&internal1_m663_y0};
_S_zpfs  S_zpfs_661_1 = {&var265,&fRM_0_5,&var51,&internal1_m661_tx,&internal1_m661_y0};
_S_twobool  S_twobool_206_1 = {&B1AD21LDU,&iEM_TERB1IE04LDU,&var52,&vainSBool,&internal1_m206_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_223_1 = {&B1AD11LDU,&iEM_TERB1IE03LDU,&var53,&vainSBool,&internal1_m223_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_41_1 = {&A1AD21LDU,&iEM_TERA1IE04LDU,&var54,&vainSBool,&internal1_m41_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_56_1 = {&A1AD11LDU,&iEM_TERA1IE03LDU,&var55,&vainSBool,&internal1_m56_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1258_1 = {&var385,&iEM_TERB1SS12LIM,&var56,&vainSBool,&internal1_m1258_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1255_1 = {&var381,&iEM_TERB1SS11LIM,&var57,&vainSBool,&internal1_m1255_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1254_1 = {&var382,&iEM_TERB1SS21LIM,&var58,&vainSBool,&internal1_m1254_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_1257_1 = {&var60,&fEM_A1UC03RDU,&fRM_0_,&iRM_0_,&var59,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m1257_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_1252_1 = {&var298,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB1MC01RIM,&var60,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_1243_1 = {&var62,&fEM_A1UC03RDU,&fRM_0_,&iRM_0_,&var61,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m1243_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_1238_1 = {&var299,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA1SC01RIM,&var62,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_1244_1 = {&var392,&iEM_TERA1SS12LIM,&var63,&vainSBool,&internal1_m1244_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1241_1 = {&var389,&iEM_TERA1SS11LIM,&var64,&vainSBool,&internal1_m1241_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1240_1 = {&var390,&iEM_TERA1SS21LIM,&var65,&vainSBool,&internal1_m1240_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_965_1 = {&var329,&iEM_TERB6SS21LIM,&var66,&vainSBool,&internal1_m965_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_986_1 = {&var328,&iEM_TERB6SS11LIM,&var67,&vainSBool,&internal1_m986_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_985_1 = {&var331,&iEM_TERA6SS21LIM,&var68,&vainSBool,&internal1_m985_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_984_1 = {&var330,&iEM_TERA6MS11LIM,&var69,&vainSBool,&internal1_m984_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1150_1 = {&var334,&iEM_TERA8SS12LIM,&var70,&vainSBool,&internal1_m1150_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1152_1 = {&var333,&iEM_TERA8SS22LIM,&var71,&vainSBool,&internal1_m1152_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1149_1 = {&var337,&iEM_TERB8SS12LIM,&var72,&vainSBool,&internal1_m1149_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1151_1 = {&var336,&iEM_TERB8SS22LIM,&var73,&vainSBool,&internal1_m1151_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1129_1 = {&var338,&iEM_TERR4SS12LIM,&var74,&vainSBool,&internal1_m1129_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1130_1 = {&var339,&iEM_TERR4SS22LIM,&var75,&vainSBool,&internal1_m1130_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1128_1 = {&var341,&iEM_TERR4MS21LIM,&var76,&vainSBool,&internal1_m1128_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1127_1 = {&var340,&iEM_TERR4SS11LIM,&var77,&vainSBool,&internal1_m1127_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_962_1 = {&var20,&iEM_TERA4VP82LIM,&var78,&var79,&internal1_m962_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_961_1 = {&var255,&iEM_TERR3SS22LIM,&var80,&vainSBool,&internal1_m961_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_941_1 = {&var254,&iEM_TERR3SS12LIM,&var81,&vainSBool,&internal1_m941_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_945_1 = {&var325,&iEM_TERR2SS21LIM,&var82,&vainSBool,&internal1_m945_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_944_1 = {&var324,&iEM_TERR2SS11LIM,&var83,&vainSBool,&internal1_m944_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_943_1 = {&var327,&iEM_TERR1SS21LIM,&var84,&vainSBool,&internal1_m943_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_942_1 = {&var326,&iEM_TERR1SS11LIM,&var85,&vainSBool,&internal1_m942_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_963_1 = {&var267,&iEM_TERB4SS21LIM,&var86,&vainSBool,&internal1_m963_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_982_1 = {&var266,&iEM_TERB4SS11LIM,&var87,&vainSBool,&internal1_m982_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1131_1 = {&lEM_R8AD10LC1,&iEM_TERR8SS11LIM,&var88,&vainSBool,&internal1_m1131_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_983_1 = {&var264,&iEM_TERA4SS21LIM,&var89,&vainSBool,&internal1_m983_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_981_1 = {&var263,&iEM_TERA4SS11LIM,&var90,&vainSBool,&internal1_m981_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_964_1 = {&var259,&iEM_TERR5SS21LIM,&var91,&vainSBool,&internal1_m964_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_980_1 = {&var258,&iEM_TERR5SS11LIM,&var92,&vainSBool,&internal1_m980_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_960_1 = {&var261,&iEM_TERR3SS21LIM,&var93,&vainSBool,&internal1_m960_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_940_1 = {&var260,&iEM_TERR3SS11LIM,&var94,&vainSBool,&internal1_m940_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_580_1 = {&var23,&iEM_TERA2VP82LIM,&var95,&var96,&internal1_m580_Out10,&bFirstEnterFlag};
_S_toao  S_toao_581_1 = {&var100,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var97,&bFirstEnterFlag};
_S_toao  S_toao_587_1 = {&var99,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var98,&bFirstEnterFlag};
_S_to3val  S_to3val_578_1 = {&var170,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A2UP03RDU,&fEM_A2UP03RDU,&iEM_TERB2SP01RIM,&var99,&vainSFloat,&var100,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_427_1 = {&var102,&fEM_A2UC03RDU,&fRM_0_,&iRM_0_,&var101,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m427_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_421_1 = {&var297,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB2SC01RIM,&var102,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_418_1 = {&var370,&iEM_TERB2SS12LIM,&var103,&vainSBool,&internal1_m418_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_420_1 = {&var365,&iEM_TERB2SS11LIM,&var104,&vainSBool,&internal1_m420_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_419_1 = {&var366,&iEM_TERB2SS21LIM,&var105,&vainSBool,&internal1_m419_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1164_1 = {&var273,&iEM_TERB9SS21LIM,&var106,&vainSBool,&internal1_m1164_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1165_1 = {&var272,&iEM_TERB9SS11LIM,&var107,&vainSBool,&internal1_m1165_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1163_1 = {&var270,&iEM_TERA9SS21LIM,&var108,&vainSBool,&internal1_m1163_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1001_1 = {&var269,&iEM_TERA9SS11LIM,&var109,&vainSBool,&internal1_m1001_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1166_1 = {&var321,&iEM_TERB5SS21LIM,&var110,&vainSBool,&internal1_m1166_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_999_1 = {&var320,&iEM_TERB5SS11LIM,&var111,&vainSBool,&internal1_m999_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_998_1 = {&var323,&iEM_TERA5SS21LIM,&var112,&vainSBool,&internal1_m998_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1000_1 = {&var322,&iEM_TERA5SS11LIM,&var113,&vainSBool,&internal1_m1000_Out10,&bFirstEnterFlag};
_S_ampl  S_ampl_702_1 = {&var303,&fEM_R7UI75RIM,&var114};
_S_to3val  S_to3val_703_1 = {&var114,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R7UI74RIM,&fEM_R7UI74RIM,&iEM_TERR7SI74RIM,&vainSFloat,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_603_1 = {&var24,&iEM_TERR0VP82LIM,&var115,&var116,&internal1_m603_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_601_1 = {&var22,&iEM_TERB0VP81LIM,&var117,&var118,&internal1_m601_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_600_1 = {&var22,&iEM_TERA0VP81LIM,&var119,&var120,&internal1_m600_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_602_1 = {&var25,&iEM_TERR0VP81LIM,&var121,&var122,&internal1_m602_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_1146_1 = {&var124,&fEM_A8UC03RDU,&fRM_0_,&iRM_0_,&var123,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m1146_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_1138_1 = {&var335,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB8SC01RIM,&var124,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_1148_1 = {&var126,&fEM_A8UC03RDU,&fRM_0_,&iRM_0_,&var125,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m1148_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_1140_1 = {&var332,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA8SC01RIM,&var126,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_722_1 = {&R0MW13LP2,&iEM_TERR6IS68LIM,&var127,&var128,&internal1_m722_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_717_1 = {&R0MW13LP2,&iEM_TERR6IS67LIM,&var129,&var130,&internal1_m717_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_708_1 = {&R0MW13LP2,&iEM_TERR6IS66LIM,&var131,&var132,&internal1_m708_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_716_1 = {&R0MW13LP2,&iEM_TERR6IS64LIM,&var133,&var134,&internal1_m716_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_707_1 = {&R0MW13LP2,&iEM_TERR6IS62LIM,&var135,&var136,&internal1_m707_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_343_1 = {&var351,&iEM_TERB3SS22LIM,&var137,&var138,&internal1_m343_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_342_1 = {&var358,&iEM_TERA3SS22LIM,&var139,&var140,&internal1_m342_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_323_1 = {&var352,&iEM_TERB3SS11LIM,&var141,&var142,&internal1_m323_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_322_1 = {&var359,&iEM_TERA3SS11LIM,&var143,&var144,&internal1_m322_Out10,&bFirstEnterFlag};
_S_toao  S_toao_557_1 = {&var146,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var145,&bFirstEnterFlag};
_S_to3val  S_to3val_551_1 = {&var242,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A3UP03RDU,&fEM_A3UP03RDU,&iEM_TERA3SP02RIM,&vainSFloat,&var146,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_604_1 = {&var21,&iEM_TERA3VP81LIM,&var147,&var148,&internal1_m604_Out10,&bFirstEnterFlag};
_S_toao  S_toao_561_1 = {&var150,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var149,&bFirstEnterFlag};
_S_to3val  S_to3val_554_1 = {&var240,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A3UP03RDU,&fEM_A3UP03RDU,&iEM_TERB3SP02RIM,&vainSFloat,&var150,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_358_1 = {&var355,&iEM_TERB3SS33LIM,&var151,&vainSBool,&internal1_m358_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_340_1 = {&var153,&fEM_A3UC03RDU,&fRM_0_,&iRM_0_,&var152,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m340_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_339_1 = {&var350,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB3SC01RIM,&var153,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_357_1 = {&var354,&iEM_TERB3SS31LIM,&var154,&vainSBool,&internal1_m357_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_355_1 = {&var362,&iEM_TERA3SS33LIM,&var155,&vainSBool,&internal1_m355_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_330_1 = {&var157,&fEM_A3UC03RDU,&fRM_0_,&iRM_0_,&var156,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m330_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_325_1 = {&var357,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA3SC01RIM,&var157,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_356_1 = {&var361,&iEM_TERA3SS31LIM,&var158,&vainSBool,&internal1_m356_Out10,&bFirstEnterFlag};
_S_toao  S_toao_586_1 = {&var171,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var159,&bFirstEnterFlag};
_S_toao  S_toao_585_1 = {&var169,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var160,&bFirstEnterFlag};
_S_twobool  S_twobool_321_1 = {&var353,&iEM_TERB3SS21LIM,&var161,&vainSBool,&internal1_m321_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_341_1 = {&var360,&iEM_TERA3SS21LIM,&var162,&vainSBool,&internal1_m341_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_439_1 = {&var376,&iEM_TERA2SS33LIM,&var163,&vainSBool,&internal1_m439_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_440_1 = {&var165,&fEM_A2UC03RDU,&fRM_0_,&iRM_0_,&var164,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m440_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_435_1 = {&var296,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA2SC01RIM,&var165,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_438_1 = {&var378,&iEM_TERA2SS12LIM,&var166,&vainSBool,&internal1_m438_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_437_1 = {&var373,&iEM_TERA2SS11LIM,&var167,&vainSBool,&internal1_m437_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_436_1 = {&var374,&iEM_TERA2SS21LIM,&var168,&vainSBool,&internal1_m436_Out10,&bFirstEnterFlag};
_S_to3val  S_to3val_577_1 = {&fEM_A2UP01RIM,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A2UP03RDU,&fEM_A2UP03RDU,&iEM_TERA2SP01RIM,&var169,&var170,&var171,&bFirstEnterFlag};
_S_toao  S_toao_163_1 = {&var176,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&vainSInt,&bFirstEnterFlag};
_S_toao  S_toao_162_1 = {&var175,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var172,&bFirstEnterFlag};
_S_toao  S_toao_161_1 = {&var174,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var173,&bFirstEnterFlag};
_S_to3val  S_to3val_156_1 = {&var345,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R0UT02RDU,&fEM_R0UT02RDU,&iEM_TERB0MT01RIM,&var174,&var175,&var176,&bFirstEnterFlag};
_S_toao  S_toao_166_1 = {&var183,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&vainSInt,&bFirstEnterFlag};
_S_toao  S_toao_165_1 = {&var182,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var177,&bFirstEnterFlag};
_S_twobool  S_twobool_946_1 = {&var257,&iEM_TERR6SS21LIM,&var178,&vainSBool,&internal1_m946_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_150_1 = {&var346,&iEM_TERB7MS31LIM,&var179,&vainSBool,&internal1_m150_Out10,&bFirstEnterFlag};
_S_toao  S_toao_164_1 = {&var181,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var180,&bFirstEnterFlag};
_S_to3val  S_to3val_158_1 = {&var396,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R0UT02RDU,&fEM_R0UT02RDU,&iEM_TERA0MT01RIM,&var181,&var182,&var183,&bFirstEnterFlag};
_S_twobool  S_twobool_149_1 = {&var397,&iEM_TERA7MS31LIM,&var184,&vainSBool,&internal1_m149_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1119_1 = {&var245,&iEM_TERR0IE41LIM,&var185,&vainSBool,&internal1_m1119_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1110_1 = {&var245,&iEM_TERR0IE43LIM,&var186,&var187,&internal1_m1110_Out10,&bFirstEnterFlag};
_S_period  S_period_1099_1 = {&var194,&var38,&iRM_2_,&fEM_R0UL01RSS,&fEM_R0UL03RSS,&fEM_R0UN03RSS,&var188,array_m1099_tst_1,array_m1099_trz_1,array_m1099_N1_1,array_m1099_N2_1,&internal1_m1099_Period0,&internal1_m1099_MyFirstEnterFlag};
_S_bol  S_bol_1104_1 = {&fEM_R0UL41RSS,&var188,&var189};
_S_bol  S_bol_1103_1 = {&var194,&fEM_R0UN03RSS,&var190};
_S_bol  S_bol_1102_1 = {&fEM_R0UL51RSS,&var188,&var191};
_S_bol  S_bol_1090_1 = {&var194,&fEM_R0UL52RSS,&var192};
_S_bol  S_bol_1094_1 = {&var194,&fEM_R0UL42RSS,&var193};
_S_ocham  S_ocham_1065_1 = {&var309,&var308,&var307,&var27,&var318,&fEM_R4UC23RIM,&fEM_A0UX00RSS,&fEM_A0UX10RSS,&fEM_B0UX10RSS,&fEM_A0UX11RSS,&fEM_B0UX11RSS,&fEM_A0UX12RSS,&fEM_B0UX12RSS,&fEM_R7UX10RSS,&fEM_R7UY10RSS,&fEM_R7UX11RSS,&fEM_R7UY11RSS,&fEM_R7UX12RSS,&fEM_R7UY12RSS,&bRM_1_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&vainSFloat,&var194,&var195,&vainSFloat,&vainSFloat,&vainSFloat,&var196,&internal1_m1065_Nk};
_S_bol  S_bol_1084_1 = {&var194,&fEM_R0UR01RSS,&var197};
_S_twobool  S_twobool_1060_1 = {&var247,&iEM_TERR0IE31LIM,&var198,&vainSBool,&internal1_m1060_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1052_1 = {&var247,&iEM_TERR0IE33LIM,&var199,&var200,&internal1_m1052_Out10,&bFirstEnterFlag};
_S_period  S_period_1041_1 = {&var207,&var46,&iRM_2_,&fEM_R0UL01RSS,&fEM_R0UL03RSS,&fEM_R0UN03RSS,&var201,array_m1041_tst_1,array_m1041_trz_1,array_m1041_N1_1,array_m1041_N2_1,&internal1_m1041_Period0,&internal1_m1041_MyFirstEnterFlag};
_S_bol  S_bol_1046_1 = {&fEM_R0UL41RSS,&var201,&var202};
_S_bol  S_bol_1045_1 = {&var207,&fEM_R0UN03RSS,&var203};
_S_bol  S_bol_1044_1 = {&fEM_R0UL51RSS,&var201,&var204};
_S_bol  S_bol_1033_1 = {&var207,&fEM_R0UL52RSS,&var205};
_S_bol  S_bol_1036_1 = {&var207,&fEM_R0UL42RSS,&var206};
_S_ocham  S_ocham_1011_1 = {&var312,&var311,&var310,&var27,&var318,&fEM_R4UC23RIM,&fEM_A0UX00RSS,&fEM_A0UX07RSS,&fEM_B0UX07RSS,&fEM_A0UX08RSS,&fEM_B0UX08RSS,&fEM_A0UX09RSS,&fEM_B0UX09RSS,&fEM_R7UX07RSS,&fEM_R7UY07RSS,&fEM_R7UX08RSS,&fEM_R7UY08RSS,&fEM_R7UX09RSS,&fEM_R7UY09RSS,&bRM_1_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&vainSFloat,&var207,&var208,&vainSFloat,&vainSFloat,&vainSFloat,&var209,&internal1_m1011_Nk};
_S_bol  S_bol_1019_1 = {&var207,&fEM_R0UR01RSS,&var210};
_S_twobool  S_twobool_929_1 = {&var249,&iEM_TERR0IE21LIM,&vainSBool,&var211,&internal1_m929_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_919_1 = {&var249,&iEM_TERR0IE23LIM,&var212,&var213,&internal1_m919_Out10,&bFirstEnterFlag};
_S_period  S_period_910_1 = {&var220,&var41,&iRM_2_,&fEM_R0UL01RSS,&fEM_R0UL03RSS,&fEM_R0UN03RSS,&var214,array_m910_tst_1,array_m910_trz_1,array_m910_N1_1,array_m910_N2_1,&internal1_m910_Period0,&internal1_m910_MyFirstEnterFlag};
_S_bol  S_bol_917_1 = {&fEM_R0UL41RSS,&var214,&var215};
_S_bol  S_bol_916_1 = {&var220,&fEM_R0UN03RSS,&var216};
_S_bol  S_bol_915_1 = {&fEM_R0UL51RSS,&var214,&var217};
_S_bol  S_bol_900_1 = {&var220,&fEM_R0UL52RSS,&var218};
_S_bol  S_bol_904_1 = {&var220,&fEM_R0UL42RSS,&var219};
_S_ocham  S_ocham_876_1 = {&var315,&var314,&var313,&var27,&var318,&fEM_R4UC23RIM,&fEM_A0UX00RSS,&fEM_A0UX04RSS,&fEM_B0UX04RSS,&fEM_A0UX05RSS,&fEM_B0UX05RSS,&fEM_A0UX06RSS,&fEM_B0UX06RSS,&fEM_R7UX04RSS,&fEM_R7UY04RSS,&fEM_R7UX05RSS,&fEM_R7UY05RSS,&fEM_R7UX06RSS,&fEM_R7UY06RSS,&bRM_2_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&vainSFloat,&var220,&var221,&vainSFloat,&vainSFloat,&vainSFloat,&var222,&internal1_m876_Nk};
_S_bol  S_bol_898_1 = {&var220,&fEM_R0UR01RSS,&var223};
_S_twobool  S_twobool_863_1 = {&var275,&iEM_TERR0IE13LIM,&var224,&var225,&internal1_m863_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_852_1 = {&var275,&iEM_TERR0IE11LIM,&var226,&vainSBool,&internal1_m852_Out10,&bFirstEnterFlag};
_S_period  S_period_855_1 = {&var233,&var47,&iRM_2_,&fEM_R0UL01RSS,&fEM_R0UL03RSS,&fEM_R0UN03RSS,&var227,array_m855_tst_1,array_m855_trz_1,array_m855_N1_1,array_m855_N2_1,&internal1_m855_Period0,&internal1_m855_MyFirstEnterFlag};
_S_bol  S_bol_860_1 = {&fEM_R0UL41RSS,&var227,&var228};
_S_bol  S_bol_859_1 = {&var233,&fEM_R0UN03RSS,&var229};
_S_bol  S_bol_858_1 = {&fEM_R0UL51RSS,&var227,&var230};
_S_bol  S_bol_843_1 = {&var233,&fEM_R0UL52RSS,&var231};
_S_bol  S_bol_847_1 = {&var233,&fEM_R0UL42RSS,&var232};
_S_ocham  S_ocham_818_1 = {&var319,&var317,&var316,&var27,&var318,&fEM_R4UC23RIM,&fEM_A0UX00RSS,&fEM_A0UX01RSS,&fEM_B0UX01RSS,&fEM_A0UX02RSS,&fEM_B0UX02RSS,&fEM_A0UX03RSS,&fEM_B0UX03RSS,&fEM_R7UX01RSS,&fEM_R7UY01RSS,&fEM_R7UX02RSS,&fEM_R7UY02RSS,&fEM_R7UC10RIM,&fEM_R7UC19RIM,&bRM_2_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&vainSFloat,&var233,&var234,&vainSFloat,&vainSFloat,&vainSFloat,&var235,&internal1_m818_Nk};
_S_bol  S_bol_838_1 = {&var233,&fEM_R0UR01RSS,&var236};
_S_orn  S_orn_1191_1 = {array_m1191_x_1,&iRM_2_,&var237};
_S_andn  S_andn_1188_1 = {array_m1188_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_1190_1 = {&var237,&var238};
_S_noto  S_noto_549_1 = {&B3AD34LDU,&var239};
_S_lk  S_lk_553_1 = {&fEM_A3UP02RDU,&var239,&var240};
_S_noto  S_noto_547_1 = {&A3AD34LDU,&var241};
_S_lk  S_lk_552_1 = {&fEM_A3UP02RDU,&var241,&var242};
_S_ovb1  S_ovb1_195_1 = {&R8AD21LDU,&iRM_500_,&var243,&internal1_m195_tx};
_S_ovb1  S_ovb1_25_1 = {&R8AD21LDU,&iRM_500_,&var244,&internal1_m25_tx};
_S_andn  S_andn_1209_1 = {array_m1209_x_1,&iRM_2_,&var245};
_S_noto  S_noto_1212_1 = {&var28,&var246};
_S_andn  S_andn_1204_1 = {array_m1204_x_1,&iRM_2_,&var247};
_S_noto  S_noto_1207_1 = {&var29,&var248};
_S_andn  S_andn_1198_1 = {array_m1198_x_1,&iRM_2_,&var249};
_S_noto  S_noto_1201_1 = {&var30,&var250};
_S_orn  S_orn_679_1 = {array_m679_x_1,&iRM_2_,&var251};
_S_orn  S_orn_676_1 = {array_m676_x_1,&iRM_2_,&var252};
_S_react  S_react_198_1 = {&var347,&var253};
_S_asmot  S_asmot_499_1 = {&var16,&var17,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_20_,&iRM_0_,&fEM_R3UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R3UC02RSP,&fEM_R3UV02RSP,&vainSFloat,&var254,&var255,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m499_Pav0,&internal1_m499_Zav0,&internal1_m499_Pv0,&internal1_m499_Zv0,&internal1_m499_RA00,&internal1_m499_RA10,&internal1_m499_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_518_1 = {&lEM_R6AD10LC1,&var256};
_S_asmot  S_asmot_526_1 = {&var256,&lEM_R6AD10LC1,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R6UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R6UC01RSP,&fEM_R6UV01RSP,&vainSFloat,&var257,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m526_Pav0,&internal1_m526_Zav0,&internal1_m526_Pv0,&internal1_m526_Zv0,&internal1_m526_RA00,&internal1_m526_RA10,&internal1_m526_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_522_1 = {&var12,&var13,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R5UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R5UC01RSP,&fEM_R5UV01RSP,&vainSFloat,&var258,&var259,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m522_Pav0,&internal1_m522_Zav0,&internal1_m522_Pv0,&internal1_m522_Zv0,&internal1_m522_RA00,&internal1_m522_RA10,&internal1_m522_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_494_1 = {&var14,&var15,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R3UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R3UC01RSP,&fEM_R3UV01RSP,&vainSFloat,&var260,&var261,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m494_Pav0,&internal1_m494_Zav0,&internal1_m494_Pv0,&internal1_m494_Zv0,&internal1_m494_RA00,&internal1_m494_RA10,&internal1_m494_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_662_1 = {&A4AD10LDU,&var262};
_S_asmot  S_asmot_666_1 = {&var262,&A4AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_20_,&iRM_0_,&fEM_A4UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_A4MC01RSP,&fEM_A4MV01RSP,&vainSFloat,&var263,&var264,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m666_Pav0,&internal1_m666_Zav0,&internal1_m666_Pv0,&internal1_m666_Zv0,&internal1_m666_RA00,&internal1_m666_RA10,&internal1_m666_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_660_1 = {&B4AD10LDU,&var265};
_S_asmot  S_asmot_665_1 = {&var265,&B4AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_A4UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_B4MC01RSP,&fEM_B4MV01RSP,&vainSFloat,&var266,&var267,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m665_Pav0,&internal1_m665_Zav0,&internal1_m665_Pv0,&internal1_m665_Zv0,&internal1_m665_RA00,&internal1_m665_RA10,&internal1_m665_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_649_1 = {&A9AD10LDU,&var268};
_S_asmot  S_asmot_651_1 = {&var268,&A9AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_20_,&iRM_0_,&fEM_A9UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_A9MC01RSP,&fEM_A9MV01RSP,&vainSFloat,&var269,&var270,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m651_Pav0,&internal1_m651_Zav0,&internal1_m651_Pv0,&internal1_m651_Zv0,&internal1_m651_RA00,&internal1_m651_RA10,&internal1_m651_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_648_1 = {&B9AD10LDU,&var271};
_S_asmot  S_asmot_650_1 = {&var271,&B9AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_A9UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_B9MC01RSP,&fEM_B9MV01RSP,&vainSFloat,&var272,&var273,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m650_Pav0,&internal1_m650_Zav0,&internal1_m650_Pv0,&internal1_m650_Zv0,&internal1_m650_RA00,&internal1_m650_RA10,&internal1_m650_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orn  S_orn_685_1 = {array_m685_x_1,&iRM_3_,&var274};
_S_andn  S_andn_1193_1 = {array_m1193_x_1,&iRM_2_,&var275};
_S_noto  S_noto_1196_1 = {&var31,&var276};
_S_andn  S_andn_290_1 = {array_m290_x_1,&iRM_2_,&var277};
_S_andn  S_andn_255_1 = {array_m255_x_1,&iRM_3_,&var278};
_S_noto  S_noto_254_1 = {&C2MD31LP1,&var279};
_S_andn  S_andn_256_1 = {array_m256_x_1,&iRM_3_,&var280};
_S_noto  S_noto_214_1 = {&C1MD31LP2,&var281};
_S_noto  S_noto_213_1 = {&C1MD31LP1,&var282};
_S_andn  S_andn_216_1 = {array_m216_x_1,&iRM_4_,&var283};
_S_andn  S_andn_215_1 = {array_m215_x_1,&iRM_4_,&var284};
_S_andn  S_andn_121_1 = {array_m121_x_1,&iRM_2_,&var285};
_S_noto  S_noto_46_1 = {&C1MD31LP2,&var286};
_S_noto  S_noto_45_1 = {&C1MD31LP1,&var287};
_S_andn  S_andn_48_1 = {array_m48_x_1,&iRM_4_,&var288};
_S_andn  S_andn_47_1 = {array_m47_x_1,&iRM_4_,&var289};
_S_andn  S_andn_87_1 = {array_m87_x_1,&iRM_3_,&var290};
_S_noto  S_noto_86_1 = {&C2MD31LP1,&var291};
_S_andn  S_andn_88_1 = {array_m88_x_1,&iRM_3_,&var292};
_S_noto  S_noto_684_1 = {&var274,&var293};
_S_orn  S_orn_692_1 = {array_m692_x_1,&iRM_2_,&var294};
_S_fsubo  S_fsubo_379_1 = {&fEM_R4UC23RIM,&var335,&var295};
_S_fsubo  S_fsubo_115_1 = {&fEM_A2UC05RIM,&var372,&var296};
_S_fsubo  S_fsubo_283_1 = {&fEM_A2UC05RIM,&var364,&var297};
_S_fsubo  S_fsubo_242_1 = {&fEM_A1UC05RIM,&var380,&var298};
_S_fsubo  S_fsubo_74_1 = {&fEM_A1UC05RIM,&var387,&var299};
_S_fsubo  S_fsubo_8_1 = {&var301,&fEM_R0UR01RIM,&var300};
_S_inf  S_inf_7_1 = {&var335,array_m7_a_1,array_m7_b_1,&iRM_5_,&var301,&vainSInt};
_S_inf  S_inf_9_1 = {&var335,array_m9_a_1,array_m9_b_1,&iRM_7_,&var302,&vainSInt};
_S_mod1  S_mod1_697_1 = {&var348,&fEM_R7UI02RIM,&fEM_R7UL01RIM,&var303,&internal1_m697_y0};
_S_bol  S_bol_691_1 = {&var348,&fEM_R7UI73RIM,&var304};
_S_bol  S_bol_681_1 = {&var348,&fEM_R7UI72RIM,&var305};
_S_bol  S_bol_675_1 = {&var348,&fEM_R7UI71RIM,&var306};
_S_vchs  S_vchs_812_1 = {&var394,&var343,&var318,&fEM_R4UC23RIM,&var27,&fEM_R7UX12RSS,&fEM_R7UY12RSS,&bRM_5_,&fEM_A0UX12RSS,&fEM_B0UX12RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var307,&internal1_m812_Chim0};
_S_vchs  S_vchs_804_1 = {&var394,&var343,&var318,&fEM_R4UC23RIM,&var27,&fEM_R7UX11RSS,&fEM_R7UY11RSS,&bRM_4_,&fEM_A0UX11RSS,&fEM_B0UX11RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var308,&internal1_m804_Chim0};
_S_vchs  S_vchs_797_1 = {&var394,&var343,&var318,&fEM_R4UC23RIM,&var27,&fEM_R7UX10RSS,&fEM_R7UY10RSS,&bRM_1_,&fEM_A0UX10RSS,&fEM_B0UX10RSS,&fRM_2_0,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var309,&internal1_m797_Chim0};
_S_vchs  S_vchs_789_1 = {&var394,&var343,&var318,&fEM_R4UC23RIM,&var27,&fEM_R7UX09RSS,&fEM_R7UY09RSS,&bRM_5_,&fEM_A0UX09RSS,&fEM_B0UX09RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var310,&internal1_m789_Chim0};
_S_vchs  S_vchs_781_1 = {&var394,&var343,&var318,&fEM_R4UC23RIM,&var27,&fEM_R7UX08RSS,&fEM_R7UY08RSS,&bRM_4_,&fEM_A0UX08RSS,&fEM_B0UX08RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var311,&internal1_m781_Chim0};
_S_vchs  S_vchs_774_1 = {&var394,&var343,&var318,&fEM_R4UC23RIM,&var27,&fEM_R7UX07RSS,&fEM_R7UY07RSS,&bRM_1_,&fEM_A0UX07RSS,&fEM_B0UX07RSS,&fRM_2_0,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var312,&internal1_m774_Chim0};
_S_vchs  S_vchs_766_1 = {&var394,&var343,&var318,&fEM_R4UC23RIM,&var27,&fEM_R7UX06RSS,&fEM_R7UY06RSS,&bRM_5_,&fEM_A0UX06RSS,&fEM_B0UX06RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var313,&internal1_m766_Chim0};
_S_vchs  S_vchs_758_1 = {&var394,&var343,&var318,&fEM_R4UC23RIM,&var27,&fEM_R7UX05RSS,&fEM_R7UY05RSS,&bRM_4_,&fEM_A0UX05RSS,&fEM_B0UX05RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var314,&internal1_m758_Chim0};
_S_vchs  S_vchs_751_1 = {&var394,&var343,&var318,&fEM_R4UC23RIM,&var27,&fEM_R7UX04RSS,&fEM_R7UY04RSS,&bRM_2_,&fEM_A0UX04RSS,&fEM_B0UX04RSS,&fRM_2_0,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var315,&internal1_m751_Chim0};
_S_vchs  S_vchs_743_1 = {&var394,&var343,&var318,&fEM_R4UC23RIM,&var27,&fEM_R7UC10RIM,&fEM_R7UC19RIM,&bRM_5_,&fEM_A0UX03RSS,&fEM_B0UX03RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var316,&internal1_m743_Chim0};
_S_vchs  S_vchs_735_1 = {&var394,&var343,&var318,&fEM_R4UC23RIM,&var27,&fEM_R7UX02RSS,&fEM_R7UY02RSS,&bRM_4_,&fEM_A0UX02RSS,&fEM_B0UX02RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var317,&internal1_m735_Chim0};
_S_fsumo  S_fsumo_1184_1 = {&fEM_R4UC10RIM,&fEM_R4UC22RIM,&var318};
_S_vchs  S_vchs_728_1 = {&var394,&var343,&var318,&fEM_R4UC23RIM,&var27,&fEM_R7UX01RSS,&fEM_R7UY01RSS,&bRM_2_,&fEM_A0UX01RSS,&fEM_B0UX01RSS,&fRM_2_0,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var319,&internal1_m728_Chim0};
_S_asmot  S_asmot_637_1 = {&B5AD10LDU,&B5AD20LDU,&fEM_B5MC01RC1,&fEM_B5MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERNL2,&fEM_A5UC10RIM,&fRM_0_0,&fRM_1500_0,&fRM_n50_,&fRM_0_10,&fEM_B5MC01RSP,&fEM_B5MV01RSP,&vainSFloat,&var320,&var321,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m637_Pav0,&internal1_m637_Zav0,&internal1_m637_Pv0,&internal1_m637_Zv0,&internal1_m637_RA00,&internal1_m637_RA10,&internal1_m637_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_622_1 = {&A5AD10LDU,&A5AD20LDU,&fEM_A5MC01RC1,&fEM_A5MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERNL1,&fEM_A5UC10RIM,&fRM_0_0,&fRM_1500_0,&fRM_n50_,&fRM_0_10,&fEM_A5MC01RSP,&fEM_A5MV01RSP,&vainSFloat,&var322,&var323,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m622_Pav0,&internal1_m622_Zav0,&internal1_m622_Pv0,&internal1_m622_Zv0,&internal1_m622_RA00,&internal1_m622_RA10,&internal1_m622_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_469_1 = {&R2AD10LDU,&R2AD20LDU,&fEM_R2MC01RC1,&fEM_R2MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERMDZ2,&fEM_R1UC10RIM,&fRM_0_0,&fRM_2000_0,&fRM_n150_,&fRM_0_50,&fEM_R2MC01RSP,&fEM_R2MV01RSP,&vainSFloat,&var324,&var325,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m469_Pav0,&internal1_m469_Zav0,&internal1_m469_Pv0,&internal1_m469_Zv0,&internal1_m469_RA00,&internal1_m469_RA10,&internal1_m469_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_454_1 = {&R1AD10LDU,&R1AD20LDU,&fEM_R1MC01RC1,&fEM_R1MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERMDZ1,&fEM_R1UC10RIM,&fRM_0_0,&fRM_2000_0,&fRM_n150_,&fRM_0_50,&fEM_R1MC01RSP,&fEM_R1MV01RSP,&vainSFloat,&var326,&var327,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m454_Pav0,&internal1_m454_Zav0,&internal1_m454_Pv0,&internal1_m454_Zv0,&internal1_m454_RA00,&internal1_m454_RA10,&internal1_m454_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_538_1 = {&B6AD10LDU,&B6AD20LDU,&fEM_B6MC01RC1,&fEM_B6MV01RC1,&fRM_1_0,&fEM_A6US80RDU,&iEM_TERBZ2,&fEM_A6UC10RIM,&fRM_0_0,&fRM_180_0,&fRM_n50_,&fRM_0_10,&fEM_B6MC01RSP,&fEM_B6MV01RSP,&vainSFloat,&var328,&var329,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m538_Pav0,&internal1_m538_Zav0,&internal1_m538_Pv0,&internal1_m538_Zv0,&internal1_m538_RA00,&internal1_m538_RA10,&internal1_m538_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_405_1 = {&A6AD10LDU,&A6AD20LDU,&fEM_A6MC01RC1,&fEM_A6MV01RC1,&fRM_1_0,&fEM_A6US80RDU,&iEM_TERBZ1,&fEM_A6UC10RIM,&fRM_0_0,&fRM_180_0,&fRM_n50_,&fRM_0_10,&fEM_A6MC01RSP,&fEM_A6MV01RSP,&vainSFloat,&var330,&var331,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m405_Pav0,&internal1_m405_Zav0,&internal1_m405_Pv0,&internal1_m405_Zv0,&internal1_m405_RA00,&internal1_m405_RA10,&internal1_m405_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_389_1 = {&A8AD20LDU,&A8AD10LDU,&fEM_A8MC01RC1,&fEM_A8MV01RC1,&fEM_A8UV80RDU,&fEM_A8US80RDU,&iEM_TERDS2,&fEM_A8UC10RIM,&fEM_A8UC20RIM,&fEM_A8UC11RIM,&fEM_A8UC21RIM,&fEM_A8UC08RDU,&fEM_A8MC01RSP,&fEM_A8MV01RSP,&var332,&var333,&var334,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m389_Pav0,&internal1_m389_Zav0,&internal1_m389_Pv0,&internal1_m389_Zv0,&internal1_m389_RA00,&internal1_m389_RA10,&internal1_m389_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_372_1 = {&B8AD20LDU,&B8AD10LDU,&fEM_B8MC01RC1,&fEM_B8MV01RC1,&fEM_B8UV80RDU,&fEM_B8US80RDU,&iEM_TERMAZ2,&fEM_B8UC10RIM,&fEM_B8UC20RIM,&fEM_B8UC11RIM,&fEM_B8UC21RIM,&fEM_B8UC08RDU,&fEM_B8MC01RSP,&fEM_B8MV01RSP,&var335,&var336,&var337,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m372_Pav0,&internal1_m372_Zav0,&internal1_m372_Pv0,&internal1_m372_Zv0,&internal1_m372_RA00,&internal1_m372_RA10,&internal1_m372_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_1179_1 = {&R4AD10LDU,&R4AD20LDU,&fEM_R4MC01RC1,&fEM_R4MV01RC1,&fEM_R4UV80RDU,&fEM_R4US80RDU,&iEM_TERTLG,&fEM_R4UC10RIM,&fEM_R4UC20RIM,&fEM_R4UC10RIM,&fEM_R4UC20RIM,&fEM_R4UC08RDU,&fEM_R4MC01RSP,&fEM_R4MV01RSP,&vainSFloat,&var338,&var339,&var340,&var341,&vainSFloat,&vainSBool,&vainSBool,&internal1_m1179_Pav0,&internal1_m1179_Zav0,&internal1_m1179_Pv0,&internal1_m1179_Zv0,&internal1_m1179_RA00,&internal1_m1179_RA10,&internal1_m1179_MyFirstEnterFlag,&bFirstEnterFlag};
_S_azbars  S_azbars_180_1 = {&var379,&var363,&var349,&var393,&fEM_R0UR30RIM,&B7AP31LDU,&var266,&lEM_R8AD10LC1,&var243,&fEM_R0UL01RIM,&fEM_R0UN02RIM,&fEM_R0UT01RIM,&fEM_R0UT02RIM,&fEM_R0UT04RIM,&fEM_R0UT05RIM,&fEM_R0UH05RSS,&fEM_A0UN02RIM,&fEM_A0UN01RIM,&fEM_A1UR00RIM,&fEM_A1UR01RIM,&fEM_A2UR00RIM,&fEM_A2UR01RIM,&fEM_A3UR00RIM,&fEM_A3UR01RIM,&var300,&var302,&fEM_R0UT03RIM,&fEM_R0UT06RIM,&fEM_A0UR02RSP,&fEM_A0UR01RSP,&fEM_B0UT03RSP,&var342,&var343,&var344,&var345,&var346,&var347,&var348,&internal1_m180_C1,&internal1_m180_C2,&internal1_m180_C3,&internal1_m180_C4,&internal1_m180_C5,&internal1_m180_C6,&internal1_m180_N20,array_m180_C0_1,&internal1_m180_ImpINI0,&internal1_m180_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_298_1 = {&B3AD11LDU,&B3AD21LDU,&B3AD02LDU,&B3AD01LDU,&B3AD03LDU,&B3AD04LDU,&B3AD05LDU,&var277,&B3AD33LDU,&lRM_1_,&fEM_B3MC01RC1,&fEM_B3MC02RC1,&fEM_B3MV01RC1,&fEM_B3MV02RC1,&lRM_0_,array_m298_Vr_1,&fEM_A3UC02RDU,&var240,&fEM_A3UP01RIM,&fEM_A3UG01RDU,&fEM_A3US07RDU,&fEM_A3UV02RIM,&iEM_TERIS2,&fEM_A3UC04RIM,&fEM_A3UC05RIM,&fEM_A3UC06RIM,&fEM_A3UC08RIM,&fEM_B3MC01RSP,&fEM_B3MC02RSP,&fEM_B3MV01RSP,&fEM_B3MV02RSP,&var349,&var350,&var351,&var352,&var353,&vainSFloat,&vainSFloat,&var354,&var355,&vainSBool,&vainSBool,&internal1_m298_Ppv0,&internal1_m298_Pav0,&internal1_m298_Zav0,&internal1_m298_RA00,&internal1_m298_RA10,&internal1_m298_RA50,&internal1_m298_fls,&internal1_m298_flp,&internal1_m298_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_131_1 = {&A3AD11LDU,&A3AD21LDU,&A3AD02LDU,&A3AD01LDU,&A3AD03LDU,&A3AD04LDU,&A3AD05LDU,&var285,&A3AD33LDU,&lRM_1_,&fEM_A3MC01RC1,&fEM_A3MC02RC1,&fEM_A3MV01RC1,&fEM_A3MV02RC1,&lRM_0_,array_m131_Vr_1,&fEM_A3UC02RDU,&var242,&fEM_A3UP01RIM,&fEM_A3UG01RDU,&fEM_A3US07RDU,&fEM_A3UV02RIM,&iEM_TERIS1,&fEM_A3UC04RIM,&fEM_A3UC05RIM,&fEM_A3UC06RIM,&fEM_A3UC08RIM,&fEM_A3MC01RSP,&fEM_A3MC02RSP,&fEM_A3MV01RSP,&fEM_A3MV02RSP,&var356,&var357,&var358,&var359,&var360,&vainSFloat,&vainSFloat,&var361,&var362,&vainSBool,&vainSBool,&internal1_m131_Ppv0,&internal1_m131_Pav0,&internal1_m131_Zav0,&internal1_m131_RA00,&internal1_m131_RA10,&internal1_m131_RA50,&internal1_m131_fls,&internal1_m131_flp,&internal1_m131_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_265_1 = {&B2AD11LDU,&B2AD21LDU,&B2AD02LDU,&B2AD01LDU,&B2AD03LDU,&B2AD04LDU,&B2AD05LDU,&var278,&B2AD33LDU,&var280,&fEM_B2MC01RC1,&fEM_B2MC02RC1,&fEM_B2MV01RC1,&fEM_B2MV02RC1,&lRM_1_,array_m265_Vr_1,&fEM_A2UC02RDU,&fEM_A2UP02RIM,&fEM_A2UP01RIM,&fEM_A2UG01RDU,&fEM_A2US07RDU,&fEM_A2UV02RIM,&iEM_TERRB2,&fEM_A2UC04RIM,&fEM_A2UC05RIM,&fEM_A2UC06RIM,&fEM_A2UC08RIM,&fEM_B2MC01RSP,&fEM_B2MC02RSP,&fEM_B2MV01RSP,&fEM_B2MV02RSP,&var363,&var364,&vainSBool,&var365,&var366,&vainSFloat,&vainSFloat,&var367,&var368,&var369,&var370,&internal1_m265_Ppv0,&internal1_m265_Pav0,&internal1_m265_Zav0,&internal1_m265_RA00,&internal1_m265_RA10,&internal1_m265_RA50,&internal1_m265_fls,&internal1_m265_flp,&internal1_m265_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_99_1 = {&A2AD11LDU,&A2AD21LDU,&A2AD02LDU,&A2AD01LDU,&A2AD03LDU,&A2AD04LDU,&A2AD05LDU,&var290,&A2AD33LDU,&var292,&fEM_A2MC01RC1,&fEM_A2MC02RC1,&fEM_A2MV01RC1,&fEM_A2MV02RC1,&lRM_1_,array_m99_Vr_1,&fEM_A2UC02RDU,&fEM_A2UP02RIM,&fEM_A2UP01RIM,&fEM_A2UG01RDU,&fEM_A2US07RDU,&fEM_A2UV02RIM,&iEM_TERRB1,&fEM_A2UC04RIM,&fEM_A2UC05RIM,&fEM_A2UC06RIM,&fEM_A2UC08RIM,&fEM_A2MC01RSP,&fEM_A2MC02RSP,&fEM_A2MV01RSP,&fEM_A2MV02RSP,&var371,&var372,&vainSBool,&var373,&var374,&vainSFloat,&vainSFloat,&var375,&var376,&var377,&var378,&internal1_m99_Ppv0,&internal1_m99_Pav0,&internal1_m99_Zav0,&internal1_m99_RA00,&internal1_m99_RA10,&internal1_m99_RA50,&internal1_m99_fls,&internal1_m99_flp,&internal1_m99_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_227_1 = {&B1AD11LDU,&B1AD21LDU,&B1AD02LDU,&B1AD01LDU,&B1AD03LDU,&B1AD04LDU,&B1AD05LDU,&var284,&lRM_1_,&var283,&fEM_B1MC01RC1,&fEM_B1MC02RC1,&fEM_B1MV01RC1,&fEM_B1MV02RC1,&lRM_1_,array_m227_Vr_1,&fEM_A1UC02RDU,&fRM_0_,&fEM_A1UP01RIM,&fEM_A1UG01RDU,&fEM_A1US07RDU,&fEM_A1UV02RIM,&iEM_TERBB2,&fEM_A1UC04RIM,&fEM_A1UC05RIM,&fEM_A1UC06RIM,&fEM_A1UC08RIM,&fEM_B1MC01RSP,&fEM_B1MC02RSP,&fEM_B1MV01RSP,&fEM_B1MV02RSP,&var379,&var380,&vainSBool,&var381,&var382,&vainSFloat,&vainSFloat,&var383,&vainSBool,&var384,&var385,&internal1_m227_Ppv0,&internal1_m227_Pav0,&internal1_m227_Zav0,&internal1_m227_RA00,&internal1_m227_RA10,&internal1_m227_RA50,&internal1_m227_fls,&internal1_m227_flp,&internal1_m227_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_60_1 = {&A1AD11LDU,&A1AD21LDU,&A1AD02LDU,&A1AD01LDU,&A1AD03LDU,&A1AD04LDU,&A1AD05LDU,&var289,&lRM_1_,&var288,&fEM_A1MC01RC1,&fEM_A1MC02RC1,&fEM_A1MV01RC1,&fEM_A1MV02RC1,&lRM_1_,array_m60_Vr_1,&fEM_A1UC02RDU,&fRM_0_,&fEM_A1UP01RIM,&fEM_A1UG01RDU,&fEM_A1US07RDU,&fEM_A1UV02RIM,&iEM_TERBB1,&fEM_A1UC04RIM,&fEM_A1UC05RIM,&fEM_A1UC06RIM,&fEM_A1UC08RIM,&fEM_A1MC01RSP,&fEM_A1MC02RSP,&fEM_A1MV01RSP,&fEM_A1MV02RSP,&var386,&var387,&var388,&var389,&var390,&vainSFloat,&vainSFloat,&vainSBool,&vainSBool,&var391,&var392,&internal1_m60_Ppv0,&internal1_m60_Pav0,&internal1_m60_Zav0,&internal1_m60_RA00,&internal1_m60_RA10,&internal1_m60_RA50,&internal1_m60_fls,&internal1_m60_flp,&internal1_m60_MyFirstEnterFlag,&bFirstEnterFlag};
_S_azbars  S_azbars_14_1 = {&var386,&var371,&var356,&var342,&fEM_R0UR30RIM,&A7AP31LDU,&var263,&lEM_R8AD10LC1,&var244,&fEM_R0UL01RIM,&fEM_R0UN02RIM,&fEM_R0UT01RIM,&fEM_R0UT02RIM,&fEM_R0UT04RIM,&fEM_R0UT05RIM,&fEM_R0UH05RSS,&fEM_A0UN02RIM,&fEM_A0UN01RIM,&fEM_A1UR00RIM,&fEM_A1UR01RIM,&fEM_A2UR00RIM,&fEM_A2UR01RIM,&fEM_A3UR00RIM,&fEM_A3UR01RIM,&var300,&var302,&fEM_R0UT03RIM,&fEM_R0UT06RIM,&fEM_A0UR02RSP,&fEM_A0UR01RSP,&fEM_A0UT03RSP,&var393,&var394,&var395,&var396,&var397,&var398,&vainSFloat,&internal1_m14_C1,&internal1_m14_C2,&internal1_m14_C3,&internal1_m14_C4,&internal1_m14_C5,&internal1_m14_C6,&internal1_m14_N20,array_m14_C0_1,&internal1_m14_ImpINI0,&internal1_m14_MyFirstEnterFlag,&bFirstEnterFlag};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  noto(&S_noto_86_1);
  noto(&S_noto_254_1);
  noto(&S_noto_648_1);
  noto(&S_noto_649_1);
  ovb1(&S_ovb1_25_1);
  ovb1(&S_ovb1_195_1);
  noto(&S_noto_549_1);
  bol(&S_bol_1219_1);
  bol(&S_bol_1222_1);
  bol(&S_bol_1228_1);
  bol(&S_bol_1220_1);
  bol(&S_bol_1226_1);
  bol(&S_bol_1233_1);
  bol(&S_bol_1231_1);
  zpfs(&S_zpfs_677_1);
  zpfs(&S_zpfs_689_1);
  noto(&S_noto_500_1);
  noto(&S_noto_498_1);
  noto(&S_noto_495_1);
  noto(&S_noto_493_1);
  noto(&S_noto_521_1);
  noto(&S_noto_520_1);
  asmot(&S_asmot_1179_1);
  asmot(&S_asmot_372_1);
  asmot(&S_asmot_389_1);
  asmot(&S_asmot_405_1);
  asmot(&S_asmot_538_1);
  asmot(&S_asmot_454_1);
  asmot(&S_asmot_469_1);
  asmot(&S_asmot_622_1);
  asmot(&S_asmot_637_1);
  fsumo(&S_fsumo_1184_1);
  inf(&S_inf_9_1);
  inf(&S_inf_7_1);
  fsubo(&S_fsubo_8_1);
  fsubo(&S_fsubo_379_1);
  noto(&S_noto_45_1);
  noto(&S_noto_46_1);
  noto(&S_noto_213_1);
  noto(&S_noto_214_1);
  orn(&S_orn_685_1);
  asmot(&S_asmot_650_1);
  asmot(&S_asmot_651_1);
  noto(&S_noto_660_1);
  noto(&S_noto_662_1);
  noto(&S_noto_518_1);
  noto(&S_noto_547_1);
  lk(&S_lk_553_1);
  orn(&S_orn_1191_1);
  to3val(&S_to3val_577_1);
  toao(&S_toao_585_1);
  toao(&S_toao_586_1);
  to3val(&S_to3val_554_1);
  toao(&S_toao_561_1);
  twobool(&S_twobool_604_1);
  twobool(&S_twobool_707_1);
  twobool(&S_twobool_716_1);
  twobool(&S_twobool_708_1);
  twobool(&S_twobool_717_1);
  twobool(&S_twobool_722_1);
  to3val(&S_to3val_1140_1);
  ktoenc(&S_ktoenc_1148_1);
  to3val(&S_to3val_1138_1);
  ktoenc(&S_ktoenc_1146_1);
  twobool(&S_twobool_602_1);
  twobool(&S_twobool_600_1);
  twobool(&S_twobool_601_1);
  twobool(&S_twobool_603_1);
  twobool(&S_twobool_1000_1);
  twobool(&S_twobool_998_1);
  twobool(&S_twobool_999_1);
  twobool(&S_twobool_1166_1);
  twobool(&S_twobool_1001_1);
  twobool(&S_twobool_1163_1);
  twobool(&S_twobool_1165_1);
  twobool(&S_twobool_1164_1);
  to3val(&S_to3val_578_1);
  toao(&S_toao_587_1);
  toao(&S_toao_581_1);
  twobool(&S_twobool_580_1);
  twobool(&S_twobool_940_1);
  twobool(&S_twobool_960_1);
  twobool(&S_twobool_980_1);
  twobool(&S_twobool_964_1);
  twobool(&S_twobool_1131_1);
  twobool(&S_twobool_942_1);
  twobool(&S_twobool_943_1);
  twobool(&S_twobool_944_1);
  twobool(&S_twobool_945_1);
  twobool(&S_twobool_941_1);
  twobool(&S_twobool_961_1);
  twobool(&S_twobool_962_1);
  twobool(&S_twobool_1127_1);
  twobool(&S_twobool_1128_1);
  twobool(&S_twobool_1130_1);
  twobool(&S_twobool_1129_1);
  twobool(&S_twobool_1151_1);
  twobool(&S_twobool_1149_1);
  twobool(&S_twobool_1152_1);
  twobool(&S_twobool_1150_1);
  twobool(&S_twobool_984_1);
  twobool(&S_twobool_985_1);
  twobool(&S_twobool_986_1);
  twobool(&S_twobool_965_1);
  twobool(&S_twobool_56_1);
  twobool(&S_twobool_41_1);
  twobool(&S_twobool_223_1);
  twobool(&S_twobool_206_1);
  zpfs(&S_zpfs_661_1);
  zpfs(&S_zpfs_663_1);
  or2(&S_or2_1195_1);
  or2(&S_or2_1200_1);
  or2(&S_or2_1206_1);
  or2(&S_or2_1211_1);
  ampl(&S_ampl_380_1);
  rs(&S_rs_487_1);
  rs(&S_rs_486_1);
  rs(&S_rs_485_1);
  rs(&S_rs_484_1);
  rs(&S_rs_515_1);
  rs(&S_rs_514_1);
  twobool(&S_twobool_582_1);
  twobool(&S_twobool_563_1);
  noto(&S_noto_684_1);
  andn(&S_andn_88_1);
  andn(&S_andn_87_1);
  andn(&S_andn_47_1);
  andn(&S_andn_48_1);
  andn(&S_andn_121_1);
  andn(&S_andn_215_1);
  andn(&S_andn_216_1);
  andn(&S_andn_256_1);
  andn(&S_andn_255_1);
  andn(&S_andn_290_1);
  noto(&S_noto_1196_1);
  andn(&S_andn_1193_1);
  asmot(&S_asmot_665_1);
  asmot(&S_asmot_666_1);
  asmot(&S_asmot_494_1);
  asmot(&S_asmot_522_1);
  asmot(&S_asmot_526_1);
  asmot(&S_asmot_499_1);
  noto(&S_noto_1201_1);
  andn(&S_andn_1198_1);
  noto(&S_noto_1207_1);
  andn(&S_andn_1204_1);
  noto(&S_noto_1212_1);
  andn(&S_andn_1209_1);
  lk(&S_lk_552_1);
  noto(&S_noto_1190_1);
  andn(&S_andn_1188_1);
  twobool(&S_twobool_852_1);
  twobool(&S_twobool_863_1);
  twobool(&S_twobool_919_1);
  twobool(&S_twobool_929_1);
  twobool(&S_twobool_1052_1);
  twobool(&S_twobool_1060_1);
  twobool(&S_twobool_1110_1);
  twobool(&S_twobool_1119_1);
  twobool(&S_twobool_946_1);
  to3val(&S_to3val_551_1);
  toao(&S_toao_557_1);
  twobool(&S_twobool_981_1);
  twobool(&S_twobool_983_1);
  twobool(&S_twobool_982_1);
  twobool(&S_twobool_963_1);
  twobool(&S_twobool_516_1);
  twobool(&S_twobool_488_1);
  twobool(&S_twobool_489_1);
  twobool(&S_twobool_490_1);
  twobool(&S_twobool_491_1);
  twobool(&S_twobool_517_1);
  orrsim(&S_orrsim_60_1);
  orrsim(&S_orrsim_227_1);
  orrsim(&S_orrsim_99_1);
  orrsim(&S_orrsim_265_1);
  orrsim(&S_orrsim_131_1);
  orrsim(&S_orrsim_298_1);
  azbars(&S_azbars_180_1);
  bol(&S_bol_675_1);
  bol(&S_bol_681_1);
  bol(&S_bol_691_1);
  mod1(&S_mod1_697_1);
  fsubo(&S_fsubo_74_1);
  fsubo(&S_fsubo_242_1);
  fsubo(&S_fsubo_283_1);
  fsubo(&S_fsubo_115_1);
  orn(&S_orn_692_1);
  react(&S_react_198_1);
  orn(&S_orn_676_1);
  orn(&S_orn_679_1);
  twobool(&S_twobool_150_1);
  to3val(&S_to3val_156_1);
  toao(&S_toao_161_1);
  toao(&S_toao_162_1);
  toao(&S_toao_163_1);
  twobool(&S_twobool_436_1);
  twobool(&S_twobool_437_1);
  twobool(&S_twobool_438_1);
  to3val(&S_to3val_435_1);
  ktoenc(&S_ktoenc_440_1);
  twobool(&S_twobool_439_1);
  twobool(&S_twobool_341_1);
  twobool(&S_twobool_321_1);
  twobool(&S_twobool_356_1);
  to3val(&S_to3val_325_1);
  ktoenc(&S_ktoenc_330_1);
  twobool(&S_twobool_355_1);
  twobool(&S_twobool_357_1);
  to3val(&S_to3val_339_1);
  ktoenc(&S_ktoenc_340_1);
  twobool(&S_twobool_358_1);
  twobool(&S_twobool_322_1);
  twobool(&S_twobool_323_1);
  twobool(&S_twobool_342_1);
  twobool(&S_twobool_343_1);
  ampl(&S_ampl_702_1);
  twobool(&S_twobool_419_1);
  twobool(&S_twobool_420_1);
  twobool(&S_twobool_418_1);
  to3val(&S_to3val_421_1);
  ktoenc(&S_ktoenc_427_1);
  twobool(&S_twobool_1240_1);
  twobool(&S_twobool_1241_1);
  twobool(&S_twobool_1244_1);
  to3val(&S_to3val_1238_1);
  ktoenc(&S_ktoenc_1243_1);
  to3val(&S_to3val_1252_1);
  ktoenc(&S_ktoenc_1257_1);
  twobool(&S_twobool_1254_1);
  twobool(&S_twobool_1255_1);
  twobool(&S_twobool_1258_1);
  twobool(&S_twobool_417_1);
  azbars(&S_azbars_14_1);
  vchs(&S_vchs_728_1);
  vchs(&S_vchs_735_1);
  vchs(&S_vchs_743_1);
  vchs(&S_vchs_751_1);
  vchs(&S_vchs_758_1);
  vchs(&S_vchs_766_1);
  vchs(&S_vchs_774_1);
  vchs(&S_vchs_781_1);
  vchs(&S_vchs_789_1);
  vchs(&S_vchs_797_1);
  vchs(&S_vchs_804_1);
  vchs(&S_vchs_812_1);
  ocham(&S_ocham_818_1);
  bol(&S_bol_847_1);
  bol(&S_bol_843_1);
  bol(&S_bol_859_1);
  ocham(&S_ocham_876_1);
  bol(&S_bol_904_1);
  bol(&S_bol_900_1);
  bol(&S_bol_916_1);
  ocham(&S_ocham_1011_1);
  bol(&S_bol_1036_1);
  bol(&S_bol_1033_1);
  bol(&S_bol_1045_1);
  ocham(&S_ocham_1065_1);
  bol(&S_bol_1094_1);
  bol(&S_bol_1090_1);
  bol(&S_bol_1103_1);
  twobool(&S_twobool_149_1);
  to3val(&S_to3val_158_1);
  toao(&S_toao_164_1);
  toao(&S_toao_165_1);
  toao(&S_toao_166_1);
  to3val(&S_to3val_703_1);
  and5(&S_and5_868_1);
  and5(&S_and5_1058_1);
  and5(&S_and5_927_1);
  and5(&S_and5_1115_1);
  andn(&S_andn_363_1);
  bol(&S_bol_838_1);
  period(&S_period_855_1);
  bol(&S_bol_898_1);
  period(&S_period_910_1);
  bol(&S_bol_1019_1);
  period(&S_period_1041_1);
  bol(&S_bol_1084_1);
  period(&S_period_1099_1);
  bol(&S_bol_858_1);
  bol(&S_bol_860_1);
  bol(&S_bol_915_1);
  bol(&S_bol_917_1);
  bol(&S_bol_1044_1);
  bol(&S_bol_1046_1);
  bol(&S_bol_1102_1);
  bol(&S_bol_1104_1);
  and2(&S_and2_865_1);
  and2(&S_and2_866_1);
  and2(&S_and2_1050_1);
  and2(&S_and2_1051_1);
  and2(&S_and2_920_1);
  and2(&S_and2_921_1);
  and2(&S_and2_1108_1);
  and2(&S_and2_1109_1);
  setData(idA1VP81LZ2,&var1);
  setData(idA1VP81LZ1,&var2);
  setData(idB1VP81LZ1,&var3);
  setData(idB1VP81LZ2,&var4);
  setData(idB2IS33LDU,&var5);
  setData(idA0VN01RIM,&var398);
  setData(idB2IS32LIM,&var367);
  setData(idB2IS11LIM,&var369);
  setData(idA2IS32LIM,&var375);
  setData(idA2IS11LIM,&var377);
  setData(idB1IS32LIM,&var383);
  setData(idB1IS11LIM,&var384);
  setData(idA1IS32LIM,&var388);
  setData(idA1IS11LIM,&var391);
  setData(idR0IS02LDU,&lEM_R0IE02LRP);
  setData(idR5AD20LDU,&var32);
  setData(idR3AD21LDU,&var33);
  setData(idR3AD11LDU,&var34);
  setData(idR3AD20LDU,&var35);
  setData(idR3AD10LDU,&var36);
  setData(idR5AD10LDU,&var37);
  setData(idB4IS10LDU,&var51);
  setData(idA4IS10LDU,&var50);
  setData(idB1IE04LDU,&var52);
  setData(idB1IE03LDU,&var53);
  setData(idA1IE04LDU,&var54);
  setData(idA1IE03LDU,&var55);
  setData(idB1IS12LDU,&var56);
  setData(idB1IS11LDU,&var57);
  setData(idB1IS21LDU,&var58);
  setData(idB1IC01UDU,&var59);
  setData(idA1IC01UDU,&var61);
  setData(idA1IS12LDU,&var63);
  setData(idA1IS11LDU,&var64);
  setData(idA1IS21LDU,&var65);
  setData(idB6IS21LDU,&var66);
  setData(idB6IS11LDU,&var67);
  setData(idA6IS21LDU,&var68);
  setData(idA6IS11LDU,&var69);
  setData(idA8IS12LDU,&var70);
  setData(idA8IS22LDU,&var71);
  setData(idB8IS12LDU,&var72);
  setData(idB8IS22LDU,&var73);
  setData(idR4IS12LDU,&var74);
  setData(idR4IS22LDU,&var75);
  setData(idR4IS21LDU,&var76);
  setData(idR4IS11LDU,&var77);
  setData(idB4VP82LDU,&var79);
  setData(idA4VP82LDU,&var78);
  setData(idR3IS41LDU,&var80);
  setData(idR3IS31LDU,&var81);
  setData(idR2IS21LDU,&var82);
  setData(idR2IS11LDU,&var83);
  setData(idR1IS21LDU,&var84);
  setData(idR1IS11LDU,&var85);
  setData(idB4IS21LDU,&var86);
  setData(idB4IS11LDU,&var87);
  setData(idR8IS11LDU,&var88);
  setData(idA4IS21LDU,&var89);
  setData(idA4IS11LDU,&var90);
  setData(idR5IS21LDU,&var91);
  setData(idR5IS11LDU,&var92);
  setData(idR3IS21LDU,&var93);
  setData(idR3IS11LDU,&var94);
  setData(idB2VP82LDU,&var95);
  setData(idB2IP01IZ2,&var97);
  setData(idB2IP01IZ1,&var98);
  setData(idB2IC01UDU,&var101);
  setData(idB2IS12LDU,&var103);
  setData(idB2IS11LDU,&var104);
  setData(idB2IS21LDU,&var105);
  setData(idB9IS21LDU,&var106);
  setData(idB9IS11LDU,&var107);
  setData(idA9IS21LDU,&var108);
  setData(idA9IS11LDU,&var109);
  setData(idB5IS21LDU,&var110);
  setData(idB5IS11LDU,&var111);
  setData(idA5IS21LDU,&var112);
  setData(idA5IS11LDU,&var113);
  setData(idR0VP82LZ2,&var116);
  setData(idR0VP82LZ1,&var115);
  setData(idB0VP81LZ2,&var118);
  setData(idB0VP81LZ1,&var117);
  setData(idA0VP81LZ2,&var120);
  setData(idA0VP81LZ1,&var119);
  setData(idR0VP81LZ2,&var122);
  setData(idR0VP81LZ1,&var121);
  setData(idB8IC01UDU,&var123);
  setData(idA8IC01UDU,&var125);
  setData(idR6IS68LZ2,&var128);
  setData(idR6IS68LZ1,&var127);
  setData(idR6IS67LZ2,&var130);
  setData(idR6IS67LZ1,&var129);
  setData(idR6IS66LZ2,&var132);
  setData(idR6IS66LZ1,&var131);
  setData(idR6IS65LDU,&var134);
  setData(idR6IS64LDU,&var133);
  setData(idR6IS63LDU,&var136);
  setData(idR6IS62LDU,&var135);
  setData(idB3IS22LZ2,&var138);
  setData(idB3IS22LZ1,&var137);
  setData(idB3IS22LDU,&var137);
  setData(idB3IS11LZ2,&var142);
  setData(idB3IS11LZ1,&var141);
  setData(idA3IS22LZ2,&var140);
  setData(idA3IS22LZ1,&var139);
  setData(idA3IS11LZ2,&var144);
  setData(idA3IS11LZ1,&var143);
  setData(idA3IS22LDU,&var139);
  setData(idB3IS11LDU,&var141);
  setData(idA3IS11LDU,&var143);
  setData(idA3IP02IDU,&var145);
  setData(idB3VP81LDU,&var148);
  setData(idA3VP81LDU,&var147);
  setData(idB3IS33LDU,&var151);
  setData(idB3IC01UDU,&var152);
  setData(idB3IS31LDU,&var154);
  setData(idB3IP02IDU,&var149);
  setData(idA3IS33LDU,&var155);
  setData(idA3IC01UDU,&var156);
  setData(idA3IS31LDU,&var158);
  setData(idA2VP82LDU,&var96);
  setData(idA2IP01IZ2,&var159);
  setData(idA2IP01IZ1,&var160);
  setData(idB3IS21LDU,&var161);
  setData(idA3IS21LDU,&var162);
  setData(idA2IS33LDU,&var163);
  setData(idA2IC01UDU,&var164);
  setData(idA2IS12LDU,&var166);
  setData(idA2IS11LDU,&var167);
  setData(idA2IS21LDU,&var168);
  setData(idB0IT02IZ2,&var172);
  setData(idB0IT01IZ1,&var173);
  setData(idA0IT02IZ2,&var177);
  setData(idA0IT01IZ1,&var180);
  setData(idR6IS21LDU,&var178);
  setData(idB7AS31LDU,&var179);
  setData(idA7AS31LDU,&var184);
  setData(idR0IE11LS4,&var185);
  setData(idR0IE13LS4,&var187);
  setData(idR0IE12LS4,&var186);
  setData(idA1EE01LS4,&var38);
  setData(idR0VN78LZ2,&var40);
  setData(idA0EE01LS4,&var38);
  setData(idR0VN78LZ1,&var40);
  setData(idR0VN65LS4,&var39);
  setData(idR0VN01RS4,&var188);
  setData(idR0VN74LZ2,&var192);
  setData(idA0VN71LS4,&var197);
  setData(idR0VN15RS4,&var196);
  setData(idA1VN71LS4,&var197);
  setData(idR0VN74LZ1,&var192);
  setData(idR0VN61LS4,&var193);
  setData(idR0VN02RS4,&var194);
  setData(idR0IE11LS3,&var198);
  setData(idR0IE13LS3,&var200);
  setData(idR0IE12LS3,&var199);
  setData(idA1EE01LS3,&var46);
  setData(idR0VN77LZ2,&var45);
  setData(idA0EE01LS3,&var46);
  setData(idR0VN77LZ1,&var45);
  setData(idR0VN65LS3,&var44);
  setData(idR0VN01RS3,&var201);
  setData(idR0VN73LZ2,&var205);
  setData(idA0VN71LS3,&var210);
  setData(idR0VN15RS3,&var209);
  setData(idA1VN71LS3,&var210);
  setData(idR0VN73LZ1,&var205);
  setData(idR0VN61LS3,&var206);
  setData(idR0VN02RS3,&var207);
  setData(idR0IE11LS2,&var211);
  setData(idR0IE13LS2,&var213);
  setData(idR0IE12LS2,&var212);
  setData(idA1EE01LS2,&var41);
  setData(idR0VN76LZ2,&var43);
  setData(idA0EE01LS2,&var41);
  setData(idR0VN76LZ1,&var43);
  setData(idR0VN65LS2,&var42);
  setData(idR0VN01RS2,&var214);
  setData(idA0VN71LS2,&var223);
  setData(idR0VN72LZ2,&var218);
  setData(idR0VN15RS2,&var222);
  setData(idA1VN71LS2,&var223);
  setData(idR0VN72LZ1,&var218);
  setData(idR0VN61LS2,&var219);
  setData(idR0VN02RS2,&var220);
  setData(idR0IE13LS1,&var224);
  setData(idR0IE12LS1,&var225);
  setData(idR0IE11LS1,&var226);
  setData(idA1EE01LS1,&var47);
  setData(idR0VN75LZ2,&var49);
  setData(idA0EE01LS1,&var47);
  setData(idR0VN75LZ1,&var49);
  setData(idR0VN65LS1,&var48);
  setData(idR0VN01RS1,&var227);
  setData(idA1VN71LS1,&var236);
  setData(idR0VN71LZ2,&var231);
  setData(idR0VN15RS1,&var235);
  setData(idA0VN71LS1,&var236);
  setData(idR0VN71LZ1,&var231);
  setData(idR0VN61LS1,&var232);
  setData(idR0VN02RS1,&var233);
  setData(idB3IS35LDU,&var239);
  setData(idA3IS35LDU,&var241);
  setData(idR7II73LZ2,&var294);
  setData(idR7II71LZ2,&var252);
  setData(idR7II72LZ2,&var251);
  setData(idR7II72LZ1,&var251);
  setData(idR7II71LZ1,&var252);
  setData(idR7II73LZ1,&var294);
  setData(idR0SR01RIM,&var253);
  setData(idR0ST01RIM,&var347);
  setData(idR0SR02RIM,&var348);
  setData(idR0CR02RIM,&var300);
  setData(idR0CR01RIM,&var302);
  setData(idB0SN08RIM,&var343);
  setData(idA0SN08RIM,&var394);
  setData(idB0SR01RIM,&var344);
  setData(idA0SR01RIM,&var395);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
  for( i=0;i<2;i++ )
    array_m1099_tst_1[i] = &(&internal1_m1099_tst)[i];
  for( i=0;i<2;i++ )
    array_m1099_trz_1[i] = &(&internal1_m1099_trz)[i];
  for( i=0;i<2;i++ )
    array_m1099_N1_1[i] = &(&internal1_m1099_N1)[i];
  for( i=0;i<2;i++ )
    array_m1099_N2_1[i] = &(&internal1_m1099_N2)[i];
  for( i=0;i<2;i++ )
    array_m1041_tst_1[i] = &(&internal1_m1041_tst)[i];
  for( i=0;i<2;i++ )
    array_m1041_trz_1[i] = &(&internal1_m1041_trz)[i];
  for( i=0;i<2;i++ )
    array_m1041_N1_1[i] = &(&internal1_m1041_N1)[i];
  for( i=0;i<2;i++ )
    array_m1041_N2_1[i] = &(&internal1_m1041_N2)[i];
  for( i=0;i<2;i++ )
    array_m910_tst_1[i] = &(&internal1_m910_tst)[i];
  for( i=0;i<2;i++ )
    array_m910_trz_1[i] = &(&internal1_m910_trz)[i];
  for( i=0;i<2;i++ )
    array_m910_N1_1[i] = &(&internal1_m910_N1)[i];
  for( i=0;i<2;i++ )
    array_m910_N2_1[i] = &(&internal1_m910_N2)[i];
  for( i=0;i<2;i++ )
    array_m855_tst_1[i] = &(&internal1_m855_tst)[i];
  for( i=0;i<2;i++ )
    array_m855_trz_1[i] = &(&internal1_m855_trz)[i];
  for( i=0;i<2;i++ )
    array_m855_N1_1[i] = &(&internal1_m855_N1)[i];
  for( i=0;i<2;i++ )
    array_m855_N2_1[i] = &(&internal1_m855_N2)[i];
  for( i=0;i<6;i++ )
    array_m180_C0_1[i] = &(&internal1_m180_C0)[i];
  for( i=0;i<6;i++ )
    array_m14_C0_1[i] = &(&internal1_m14_C0)[i];
}

#endif
