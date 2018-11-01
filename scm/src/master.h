#ifndef SCM_H
#define SCM_H
// Подсистема scm:SCM
static char SimulOn=0;
static short CodeSub=1;
static char SimulIP[]="192.168.1.17\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 3613
static char BUFFER[3613];
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
#define R0VN78LZ2	 BUFFER[142]	//(R0VN78LZ2) АС по периоду разгона канал 4 на БАЗ2
#define idR0VN78LZ2	 62	//(R0VN78LZ2) АС по периоду разгона канал 4 на БАЗ2
#define B3IS22LDU	 BUFFER[144]	//(B3IS22LDU) Приход на НУП ИС2
#define idB3IS22LDU	 63	//(B3IS22LDU) Приход на НУП ИС2
#define B3IS11LZ2	 BUFFER[146]	//(B3IS11LZ2) Приход на ВУ ИС2
#define idB3IS11LZ2	 64	//(B3IS11LZ2) Приход на ВУ ИС2
#define B3IS11LZ1	 BUFFER[148]	//(B3IS11LZ1) Приход на ВУ ИС2
#define idB3IS11LZ1	 65	//(B3IS11LZ1) Приход на ВУ ИС2
#define A3IS22LZ2	 BUFFER[150]	//(A3IS22LZ2) Приход на НУП ИС1
#define idA3IS22LZ2	 66	//(A3IS22LZ2) Приход на НУП ИС1
#define A3IS22LZ1	 BUFFER[152]	//(A3IS22LZ1) Приход на НУП ИС1
#define idA3IS22LZ1	 67	//(A3IS22LZ1) Приход на НУП ИС1
#define A3IS11LZ2	 BUFFER[154]	//(A3IS11LZ2) Приход на ВУ ИС1
#define idA3IS11LZ2	 68	//(A3IS11LZ2) Приход на ВУ ИС1
#define A3IS11LZ1	 BUFFER[156]	//(A3IS11LZ1) Приход на ВУ ИС1
#define idA3IS11LZ1	 69	//(A3IS11LZ1) Приход на ВУ ИС1
#define A3IS22LDU	 BUFFER[158]	//(A3IS22LDU) Приход на НУП ИС1
#define idA3IS22LDU	 70	//(A3IS22LDU) Приход на НУП ИС1
#define B3IS11LDU	 BUFFER[160]	//(B3IS11LDU) Приход на ВУ ИС2
#define idB3IS11LDU	 71	//(B3IS11LDU) Приход на ВУ ИС2
#define A3IS11LDU	 BUFFER[162]	//(A3IS11LDU) Приход на ВУ ИС1
#define idA3IS11LDU	 72	//(A3IS11LDU) Приход на ВУ ИС1
#define A3IP02IDU	 BUFFER[164]	//(A3IP02IDU) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	 73	//(A3IP02IDU) Текущее давление ВЫСТРЕЛ ИС1
#define B3VP81LDU	 BUFFER[167]	//(B3VP81LDU) Давление СПУСК ИС2 в норме
#define idB3VP81LDU	 74	//(B3VP81LDU) Давление СПУСК ИС2 в норме
#define A3VP81LDU	 BUFFER[169]	//(A3VP81LDU) Давление СПУСК ИС1 в норме
#define idA3VP81LDU	 75	//(A3VP81LDU) Давление СПУСК ИС1 в норме
#define B3IS33LDU	 BUFFER[171]	//(B3IS33LDU) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define idB3IS33LDU	 76	//(B3IS33LDU) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define B3IC01UDU	 BUFFER[173]	//(B3IC01UDU) Координата штока ИС2
#define idB3IC01UDU	 77	//(B3IC01UDU) Координата штока ИС2
#define B3IS31LDU	 BUFFER[178]	//(B3IS31LDU) Клапан (СПУСК ИС2)  открыт (обесточен)
#define idB3IS31LDU	 78	//(B3IS31LDU) Клапан (СПУСК ИС2)  открыт (обесточен)
#define B3IP02IDU	 BUFFER[180]	//(B3IP02IDU) Текущее давление ВЫСТРЕЛ  ИС2
#define idB3IP02IDU	 79	//(B3IP02IDU) Текущее давление ВЫСТРЕЛ  ИС2
#define A3IS33LDU	 BUFFER[183]	//(A3IS33LDU) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
#define idA3IS33LDU	 80	//(A3IS33LDU) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
#define A3IC01UDU	 BUFFER[185]	//(A3IC01UDU) Координата штока ИС1
#define idA3IC01UDU	 81	//(A3IC01UDU) Координата штока ИС1
#define A3IS31LDU	 BUFFER[190]	//(A3IS31LDU) Клапан (СПУСК ИС1)  открыт (обесточен)
#define idA3IS31LDU	 82	//(A3IS31LDU) Клапан (СПУСК ИС1)  открыт (обесточен)
#define A2VP82LDU	 BUFFER[192]	//(A2VP82LDU) Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	 83	//(A2VP82LDU) Давление ПОДЪЁМ РБ1 в норме
#define B2IS11LIM	 BUFFER[194]	//(B2IS11LIM) Магнит РБ2 обесточен
#define idB2IS11LIM	 84	//(B2IS11LIM) Магнит РБ2 обесточен
#define A2IS32LIM	 BUFFER[196]	//(A2IS32LIM) Клапан cброса РБ1 открыт(обесточен)
#define idA2IS32LIM	 85	//(A2IS32LIM) Клапан cброса РБ1 открыт(обесточен)
#define A2IS11LIM	 BUFFER[198]	//(A2IS11LIM) Магнит РБ1 обесточен
#define idA2IS11LIM	 86	//(A2IS11LIM) Магнит РБ1 обесточен
#define B1IS32LIM	 BUFFER[200]	//(B1IS32LIM) Клапан cброса ББ2 открыт(обесточен)
#define idB1IS32LIM	 87	//(B1IS32LIM) Клапан cброса ББ2 открыт(обесточен)
#define B1IS11LIM	 BUFFER[202]	//(B1IS11LIM) Магнит ББ2 обесточен
#define idB1IS11LIM	 88	//(B1IS11LIM) Магнит ББ2 обесточен
#define A1IS32LIM	 BUFFER[204]	//(A1IS32LIM) Клапан cброса ББ1 открыт(обесточен)
#define idA1IS32LIM	 89	//(A1IS32LIM) Клапан cброса ББ1 открыт(обесточен)
#define A1IS11LIM	 BUFFER[206]	//(A1IS11LIM) Магнит ББ1 обесточен
#define idA1IS11LIM	 90	//(A1IS11LIM) Магнит ББ1 обесточен
#define A3AD34LDU	 BUFFER[208]	//(A3AD34LDU) Клапан (ВПИС ИС1) открыть (обесточить)
#define idA3AD34LDU	 91	//(A3AD34LDU) Клапан (ВПИС ИС1) открыть (обесточить)
#define R0IS02LDU	 BUFFER[210]	//(R0IS02LDU) Разрешение ввода от имитатора
#define idR0IS02LDU	 92	//(R0IS02LDU) Разрешение ввода от имитатора
#define R0EE04LZ2	 BUFFER[212]	//(R0EE04LZ2) Питание  АКНП4  отключить
#define idR0EE04LZ2	 93	//(R0EE04LZ2) Питание  АКНП4  отключить
#define R0EE03LZ2	 BUFFER[214]	//(R0EE03LZ2) Питание  АКНП3  отключить
#define idR0EE03LZ2	 94	//(R0EE03LZ2) Питание  АКНП3  отключить
#define R0EE02LZ2	 BUFFER[216]	//(R0EE02LZ2) Питание  АКНП  отключить
#define idR0EE02LZ2	 95	//(R0EE02LZ2) Питание  АКНП  отключить
#define R0EE04LZ1	 BUFFER[218]	//(R0EE04LZ1) Питание  АКНП4  отключить
#define idR0EE04LZ1	 96	//(R0EE04LZ1) Питание  АКНП4  отключить
#define R0EE03LZ1	 BUFFER[220]	//(R0EE03LZ1) Питание  АКНП3  отключить
#define idR0EE03LZ1	 97	//(R0EE03LZ1) Питание  АКНП3  отключить
#define R0EE02LZ1	 BUFFER[222]	//(R0EE02LZ1) Питание  АКНП  отключить
#define idR0EE02LZ1	 98	//(R0EE02LZ1) Питание  АКНП  отключить
#define R0EE01LZ2	 BUFFER[224]	//(R0EE01LZ2) Питание  АКНП1  отключить
#define idR0EE01LZ2	 99	//(R0EE01LZ2) Питание  АКНП1  отключить
#define R0EE01LZ1	 BUFFER[226]	//(R0EE01LZ1) Питание  АКНП1  отключить
#define idR0EE01LZ1	 100	//(R0EE01LZ1) Питание  АКНП1  отключить
#define R5AD20LDU	 BUFFER[228]	//(R5AD20LDU) Закрыть ворота отстойной зоны
#define idR5AD20LDU	 101	//(R5AD20LDU) Закрыть ворота отстойной зоны
#define R3AD21LDU	 BUFFER[230]	//(R3AD21LDU) Гомогенные двери-2 закрыть
#define idR3AD21LDU	 102	//(R3AD21LDU) Гомогенные двери-2 закрыть
#define R3AD11LDU	 BUFFER[232]	//(R3AD11LDU) Гомогенные двери-2 открыть
#define idR3AD11LDU	 103	//(R3AD11LDU) Гомогенные двери-2 открыть
#define B0SN07RIM	 BUFFER[234]	//(B0SN07RIM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
#define idB0SN07RIM	 104	//(B0SN07RIM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
#define B0SN06RIM	 BUFFER[239]	//(B0SN06RIM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
#define idB0SN06RIM	 105	//(B0SN06RIM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
#define B0SN05RIM	 BUFFER[244]	//(B0SN05RIM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
#define idB0SN05RIM	 106	//(B0SN05RIM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
#define B0SN04RIM	 BUFFER[249]	//(B0SN04RIM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
#define idB0SN04RIM	 107	//(B0SN04RIM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
#define B0SN03RIM	 BUFFER[254]	//(B0SN03RIM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
#define idB0SN03RIM	 108	//(B0SN03RIM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
#define B0SN02RIM	 BUFFER[259]	//(B0SN02RIM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
#define idB0SN02RIM	 109	//(B0SN02RIM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
#define B7AP31LDU	 BUFFER[264]	//(B7AP31LDU) Клапан (Обдув АЗ2) открыть (обесточить)
#define idB7AP31LDU	 110	//(B7AP31LDU) Клапан (Обдув АЗ2) открыть (обесточить)
#define A7AP31LDU	 BUFFER[266]	//(A7AP31LDU) Клапан (Обдув АЗ1) открыть (обесточить)
#define idA7AP31LDU	 111	//(A7AP31LDU) Клапан (Обдув АЗ1) открыть (обесточить)
#define A0SN07RIM	 BUFFER[268]	//(A0SN07RIM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
#define idA0SN07RIM	 112	//(A0SN07RIM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
#define A0SN06RIM	 BUFFER[273]	//(A0SN06RIM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
#define idA0SN06RIM	 113	//(A0SN06RIM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
#define A0SN05RIM	 BUFFER[278]	//(A0SN05RIM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
#define idA0SN05RIM	 114	//(A0SN05RIM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
#define A0SN04RIM	 BUFFER[283]	//(A0SN04RIM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
#define idA0SN04RIM	 115	//(A0SN04RIM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
#define A0SN03RIM	 BUFFER[288]	//(A0SN03RIM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
#define idA0SN03RIM	 116	//(A0SN03RIM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
#define A0SN02RIM	 BUFFER[293]	//(A0SN02RIM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
#define idA0SN02RIM	 117	//(A0SN02RIM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
#define A1VP81LZ2	 BUFFER[298]	//(A1VP81LZ2) Давление СБРОС ББ1 в норме
#define idA1VP81LZ2	 118	//(A1VP81LZ2) Давление СБРОС ББ1 в норме
#define A1VP81LZ1	 BUFFER[300]	//(A1VP81LZ1) Давление СБРОС ББ1 в норме
#define idA1VP81LZ1	 119	//(A1VP81LZ1) Давление СБРОС ББ1 в норме
#define B1VP81LZ1	 BUFFER[302]	//(B1VP81LZ1) Давление СБРОС ББ2 в норме
#define idB1VP81LZ1	 120	//(B1VP81LZ1) Давление СБРОС ББ2 в норме
#define B1VP81LZ2	 BUFFER[304]	//(B1VP81LZ2) Давление СБРОС ББ2 в норме
#define idB1VP81LZ2	 121	//(B1VP81LZ2) Давление СБРОС ББ2 в норме
#define B2IS33LDU	 BUFFER[306]	//(B2IS33LDU) Клапан (Подъём РБ2)  открыт (обесточен)
#define idB2IS33LDU	 122	//(B2IS33LDU) Клапан (Подъём РБ2)  открыт (обесточен)
#define A0VN01RIM	 BUFFER[308]	//(A0VN01RIM) Период разгона  AЗ1
#define idA0VN01RIM	 123	//(A0VN01RIM) Период разгона  AЗ1
#define B2IS32LIM	 BUFFER[313]	//(B2IS32LIM) Клапан cброса РБ2 открыт(обесточен)
#define idB2IS32LIM	 124	//(B2IS32LIM) Клапан cброса РБ2 открыт(обесточен)
#define A8IS12LDU	 BUFFER[315]	//(A8IS12LDU) Приход на механический ВУ ДС2
#define idA8IS12LDU	 125	//(A8IS12LDU) Приход на механический ВУ ДС2
#define A8IS22LDU	 BUFFER[317]	//(A8IS22LDU) Приход на механический НУ ДС2
#define idA8IS22LDU	 126	//(A8IS22LDU) Приход на механический НУ ДС2
#define B8IS12LDU	 BUFFER[319]	//(B8IS12LDU) Приход на механический ВУ АЗ2
#define idB8IS12LDU	 127	//(B8IS12LDU) Приход на механический ВУ АЗ2
#define B8IS22LDU	 BUFFER[321]	//(B8IS22LDU) Приход на механический НУ АЗ2
#define idB8IS22LDU	 128	//(B8IS22LDU) Приход на механический НУ АЗ2
#define R4IS12LDU	 BUFFER[323]	//(R4IS12LDU) Приход на механический ВУ тележки
#define idR4IS12LDU	 129	//(R4IS12LDU) Приход на механический ВУ тележки
#define R4IS22LDU	 BUFFER[325]	//(R4IS22LDU) Приход на механический НУ тележки
#define idR4IS22LDU	 130	//(R4IS22LDU) Приход на механический НУ тележки
#define R4IS21LDU	 BUFFER[327]	//(R4IS21LDU) Приход на НУ тележки
#define idR4IS21LDU	 131	//(R4IS21LDU) Приход на НУ тележки
#define R4IS11LDU	 BUFFER[329]	//(R4IS11LDU) Приход на ВУ тележки
#define idR4IS11LDU	 132	//(R4IS11LDU) Приход на ВУ тележки
#define B4VP82LDU	 BUFFER[331]	//(B4VP82LDU) Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	 133	//(B4VP82LDU) Давление ПОДЪЁМ НИ2 в норме
#define A4VP82LDU	 BUFFER[333]	//(A4VP82LDU) Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	 134	//(A4VP82LDU) Давление ПОДЪЁМ НИ1 в норме
#define R3IS41LDU	 BUFFER[335]	//(R3IS41LDU) Приход на НУ гомогенных дверей-2
#define idR3IS41LDU	 135	//(R3IS41LDU) Приход на НУ гомогенных дверей-2
#define R3IS31LDU	 BUFFER[337]	//(R3IS31LDU) Приход на ВУ гомогенных дверей-2
#define idR3IS31LDU	 136	//(R3IS31LDU) Приход на ВУ гомогенных дверей-2
#define R2IS21LDU	 BUFFER[339]	//(R2IS21LDU) Приход на НУ МДЗ2
#define idR2IS21LDU	 137	//(R2IS21LDU) Приход на НУ МДЗ2
#define R2IS11LDU	 BUFFER[341]	//(R2IS11LDU) Приход на ВУ МДЗ2
#define idR2IS11LDU	 138	//(R2IS11LDU) Приход на ВУ МДЗ2
#define R1IS21LDU	 BUFFER[343]	//(R1IS21LDU) Приход на НУ МДЗ1
#define idR1IS21LDU	 139	//(R1IS21LDU) Приход на НУ МДЗ1
#define R1IS11LDU	 BUFFER[345]	//(R1IS11LDU) Приход на ВУ МДЗ1
#define idR1IS11LDU	 140	//(R1IS11LDU) Приход на ВУ МДЗ1
#define B4IS21LDU	 BUFFER[347]	//(B4IS21LDU) Приход на НУ НИ2
#define idB4IS21LDU	 141	//(B4IS21LDU) Приход на НУ НИ2
#define B4IS11LDU	 BUFFER[349]	//(B4IS11LDU) Приход на ВУ НИ2
#define idB4IS11LDU	 142	//(B4IS11LDU) Приход на ВУ НИ2
#define R8IS11LDU	 BUFFER[351]	//(R8IS11LDU) Аварийный НИ установлен
#define idR8IS11LDU	 143	//(R8IS11LDU) Аварийный НИ установлен
#define A4IS21LDU	 BUFFER[353]	//(A4IS21LDU) Приход на НУ НИ1
#define idA4IS21LDU	 144	//(A4IS21LDU) Приход на НУ НИ1
#define A4IS11LDU	 BUFFER[355]	//(A4IS11LDU) Приход на ВУ НИ1
#define idA4IS11LDU	 145	//(A4IS11LDU) Приход на ВУ НИ1
#define R3AD20LDU	 BUFFER[357]	//(R3AD20LDU) Гомогенные двери-1 закрыть
#define idR3AD20LDU	 146	//(R3AD20LDU) Гомогенные двери-1 закрыть
#define R3AD10LDU	 BUFFER[359]	//(R3AD10LDU) Гомогенные двери-1 открыть
#define idR3AD10LDU	 147	//(R3AD10LDU) Гомогенные двери-1 открыть
#define R5AD10LDU	 BUFFER[361]	//(R5AD10LDU) Открыть ворота отстойной зоны
#define idR5AD10LDU	 148	//(R5AD10LDU) Открыть ворота отстойной зоны
#define B4IS10LDU	 BUFFER[363]	//(B4IS10LDU) Клапан (Подъём НИ2) открыт (обесточен)
#define idB4IS10LDU	 149	//(B4IS10LDU) Клапан (Подъём НИ2) открыт (обесточен)
#define A4IS10LDU	 BUFFER[365]	//(A4IS10LDU) Клапан (Подъём НИ1) открыт (обесточен)
#define idA4IS10LDU	 150	//(A4IS10LDU) Клапан (Подъём НИ1) открыт (обесточен)
#define B1IE04LDU	 BUFFER[367]	//(B1IE04LDU) Движение ББ2 назад (от БУШД)
#define idB1IE04LDU	 151	//(B1IE04LDU) Движение ББ2 назад (от БУШД)
#define B1IE03LDU	 BUFFER[369]	//(B1IE03LDU) Движение ББ2 вперед (от БУШД)
#define idB1IE03LDU	 152	//(B1IE03LDU) Движение ББ2 вперед (от БУШД)
#define A1IE04LDU	 BUFFER[371]	//(A1IE04LDU) Движение ББ1 назад (от БУШД)
#define idA1IE04LDU	 153	//(A1IE04LDU) Движение ББ1 назад (от БУШД)
#define A1IE03LDU	 BUFFER[373]	//(A1IE03LDU) Движение ББ1 вперед (от БУШД)
#define idA1IE03LDU	 154	//(A1IE03LDU) Движение ББ1 вперед (от БУШД)
#define B1IS12LDU	 BUFFER[375]	//(B1IS12LDU) Магнит ББ2 зацеплен
#define idB1IS12LDU	 155	//(B1IS12LDU) Магнит ББ2 зацеплен
#define B1IS11LDU	 BUFFER[377]	//(B1IS11LDU) Приход на ВУ ББ2
#define idB1IS11LDU	 156	//(B1IS11LDU) Приход на ВУ ББ2
#define B1IS21LDU	 BUFFER[379]	//(B1IS21LDU) Приход на НУ ББ2
#define idB1IS21LDU	 157	//(B1IS21LDU) Приход на НУ ББ2
#define B1IC01UDU	 BUFFER[381]	//(B1IC01UDU) Координата штока ББ2
#define idB1IC01UDU	 158	//(B1IC01UDU) Координата штока ББ2
#define A1IC01UDU	 BUFFER[386]	//(A1IC01UDU) Координата штока ББ1
#define idA1IC01UDU	 159	//(A1IC01UDU) Координата штока ББ1
#define A1IS12LDU	 BUFFER[391]	//(A1IS12LDU) Магнит ББ1 зацеплен
#define idA1IS12LDU	 160	//(A1IS12LDU) Магнит ББ1 зацеплен
#define A1IS11LDU	 BUFFER[393]	//(A1IS11LDU) Приход на ВУ ББ1
#define idA1IS11LDU	 161	//(A1IS11LDU) Приход на ВУ ББ1
#define A1IS21LDU	 BUFFER[395]	//(A1IS21LDU) Приход на НУ ББ1
#define idA1IS21LDU	 162	//(A1IS21LDU) Приход на НУ ББ1
#define B6IS21LDU	 BUFFER[397]	//(B6IS21LDU) Приход на НУ БЗ2
#define idB6IS21LDU	 163	//(B6IS21LDU) Приход на НУ БЗ2
#define B6IS11LDU	 BUFFER[399]	//(B6IS11LDU) Приход на ВУ БЗ2
#define idB6IS11LDU	 164	//(B6IS11LDU) Приход на ВУ БЗ2
#define A6IS21LDU	 BUFFER[401]	//(A6IS21LDU) Приход на НУ БЗ1
#define idA6IS21LDU	 165	//(A6IS21LDU) Приход на НУ БЗ1
#define A6IS11LDU	 BUFFER[403]	//(A6IS11LDU) Приход на ВУ БЗ1
#define idA6IS11LDU	 166	//(A6IS11LDU) Приход на ВУ БЗ1
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
#define B3AD21LDU	 BUFFER[446]	//(B3AD21LDU) Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	 186	//(B3AD21LDU) Сигнал на перемещение ИС2 вниз
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
#define R2AD10LDU	 BUFFER[503]	//(R2AD10LDU) Опустить МДЗ2 в зону облучения
#define idR2AD10LDU	 207	//(R2AD10LDU) Опустить МДЗ2 в зону облучения
#define A2AD04LDU	 BUFFER[505]	//(A2AD04LDU) 2-й бит скорости РБ1
#define idA2AD04LDU	 208	//(A2AD04LDU) 2-й бит скорости РБ1
#define A2AD03LDU	 BUFFER[507]	//(A2AD03LDU) 1-й бит скорости РБ1
#define idA2AD03LDU	 209	//(A2AD03LDU) 1-й бит скорости РБ1
#define A2AD02LDU	 BUFFER[509]	//(A2AD02LDU) 0-й бит скорости РБ1
#define idA2AD02LDU	 210	//(A2AD02LDU) 0-й бит скорости РБ1
#define A2AD01LDU	 BUFFER[511]	//(A2AD01LDU) Разрешение движения РБ1
#define idA2AD01LDU	 211	//(A2AD01LDU) Разрешение движения РБ1
#define A2AD21LDU	 BUFFER[513]	//(A2AD21LDU) Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	 212	//(A2AD21LDU) Сигнал на перемещение РБ1 вниз
#define A2AD11LDU	 BUFFER[515]	//(A2AD11LDU) Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	 213	//(A2AD11LDU) Сигнал на перемещение РБ1 вверх
#define B1AD05LDU	 BUFFER[517]	//(B1AD05LDU) паритет команды на ББ2
#define idB1AD05LDU	 214	//(B1AD05LDU) паритет команды на ББ2
#define B1AD04LDU	 BUFFER[519]	//(B1AD04LDU) 2-й бит скорости ББ2
#define idB1AD04LDU	 215	//(B1AD04LDU) 2-й бит скорости ББ2
#define B1AD03LDU	 BUFFER[521]	//(B1AD03LDU) 1-й бит скорости ББ2
#define idB1AD03LDU	 216	//(B1AD03LDU) 1-й бит скорости ББ2
#define B1AD02LDU	 BUFFER[523]	//(B1AD02LDU) 0-й бит скорости  ББ2
#define idB1AD02LDU	 217	//(B1AD02LDU) 0-й бит скорости  ББ2
#define B1AD01LDU	 BUFFER[525]	//(B1AD01LDU) Разрешение движения ББ2
#define idB1AD01LDU	 218	//(B1AD01LDU) Разрешение движения ББ2
#define B1AD21LDU	 BUFFER[527]	//(B1AD21LDU) Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	 219	//(B1AD21LDU) Сигнал на перемещение ББ2 вниз
#define B1AD11LDU	 BUFFER[529]	//(B1AD11LDU) Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	 220	//(B1AD11LDU) Сигнал на перемещение ББ2 вверх
#define A1AD05LDU	 BUFFER[531]	//(A1AD05LDU) паритет команды на ББ1
#define idA1AD05LDU	 221	//(A1AD05LDU) паритет команды на ББ1
#define A1AD04LDU	 BUFFER[533]	//(A1AD04LDU) 2-й бит скорости ББ1
#define idA1AD04LDU	 222	//(A1AD04LDU) 2-й бит скорости ББ1
#define A1AD03LDU	 BUFFER[535]	//(A1AD03LDU) 1-й бит скорости ББ1
#define idA1AD03LDU	 223	//(A1AD03LDU) 1-й бит скорости ББ1
#define A1AD02LDU	 BUFFER[537]	//(A1AD02LDU) 0-й бит скорости ББ1
#define idA1AD02LDU	 224	//(A1AD02LDU) 0-й бит скорости ББ1
#define A1AD01LDU	 BUFFER[539]	//(A1AD01LDU) Разрешение движения ББ1
#define idA1AD01LDU	 225	//(A1AD01LDU) Разрешение движения ББ1
#define A1AD21LDU	 BUFFER[541]	//(A1AD21LDU) Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	 226	//(A1AD21LDU) Сигнал на перемещение ББ1 вниз
#define A1AD11LDU	 BUFFER[543]	//(A1AD11LDU) Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	 227	//(A1AD11LDU) Сигнал на перемещение ББ1 вверх
#define A0SR01RIM	 BUFFER[545]	//(A0SR01RIM) Текущая реактивность AЗ1
#define idA0SR01RIM	 228	//(A0SR01RIM) Текущая реактивность AЗ1
#define B3AD11LDU	 BUFFER[550]	//(B3AD11LDU) Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	 229	//(B3AD11LDU) Сигнал на перемещение ИС2 вверх
#define A3AD33LDU	 BUFFER[552]	//(A3AD33LDU) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
#define idA3AD33LDU	 230	//(A3AD33LDU) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
#define A3AD05LDU	 BUFFER[554]	//(A3AD05LDU) паритет команды на ИС1
#define idA3AD05LDU	 231	//(A3AD05LDU) паритет команды на ИС1
#define A3AD04LDU	 BUFFER[556]	//(A3AD04LDU) 2-й бит скорости ИС1
#define idA3AD04LDU	 232	//(A3AD04LDU) 2-й бит скорости ИС1
#define A3AD03LDU	 BUFFER[558]	//(A3AD03LDU) 1-й бит скорости ИС1
#define idA3AD03LDU	 233	//(A3AD03LDU) 1-й бит скорости ИС1
#define A3AD02LDU	 BUFFER[560]	//(A3AD02LDU) 0-й бит скорости ИС1
#define idA3AD02LDU	 234	//(A3AD02LDU) 0-й бит скорости ИС1
#define A3AD01LDU	 BUFFER[562]	//(A3AD01LDU) Разрешение движения ИС1
#define idA3AD01LDU	 235	//(A3AD01LDU) Разрешение движения ИС1
#define A3AD21LDU	 BUFFER[564]	//(A3AD21LDU) Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	 236	//(A3AD21LDU) Сигнал на перемещение ИС1 вниз
#define A3AD11LDU	 BUFFER[566]	//(A3AD11LDU) Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	 237	//(A3AD11LDU) Сигнал на перемещение ИС1 вверх
#define B2AD33LDU	 BUFFER[568]	//(B2AD33LDU) Клапан (Подъем РБ2) закрыть (обесточить)
#define idB2AD33LDU	 238	//(B2AD33LDU) Клапан (Подъем РБ2) закрыть (обесточить)
#define B2AD05LDU	 BUFFER[570]	//(B2AD05LDU) паритет команды на РБ2
#define idB2AD05LDU	 239	//(B2AD05LDU) паритет команды на РБ2
#define B2AD04LDU	 BUFFER[572]	//(B2AD04LDU) 2-й бит скорости РБ2
#define idB2AD04LDU	 240	//(B2AD04LDU) 2-й бит скорости РБ2
#define B2AD03LDU	 BUFFER[574]	//(B2AD03LDU) 1-й бит скорости РБ2
#define idB2AD03LDU	 241	//(B2AD03LDU) 1-й бит скорости РБ2
#define B2AD02LDU	 BUFFER[576]	//(B2AD02LDU) 0-й бит скорости РБ2
#define idB2AD02LDU	 242	//(B2AD02LDU) 0-й бит скорости РБ2
#define B2AD01LDU	 BUFFER[578]	//(B2AD01LDU) Разрешение движения РБ2
#define idB2AD01LDU	 243	//(B2AD01LDU) Разрешение движения РБ2
#define B2AD21LDU	 BUFFER[580]	//(B2AD21LDU) Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	 244	//(B2AD21LDU) Сигнал на перемещение РБ2 вниз
#define B2AD11LDU	 BUFFER[582]	//(B2AD11LDU) Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	 245	//(B2AD11LDU) Сигнал на перемещение РБ2 вверх
#define A2AD33LDU	 BUFFER[584]	//(A2AD33LDU) Клапан (Подъем РБ1) закрыть (обесточить)
#define idA2AD33LDU	 246	//(A2AD33LDU) Клапан (Подъем РБ1) закрыть (обесточить)
#define A2MV01RC1	 BUFFER[586]	//(A2MV01RC1) Заданная скорость движения ББ1 от ИС
#define idA2MV01RC1	 247	//(A2MV01RC1) Заданная скорость движения ББ1 от ИС
#define A2MC01RC1	 BUFFER[591]	//(A2MC01RC1) Заданная координата РБ1 от ИС
#define idA2MC01RC1	 248	//(A2MC01RC1) Заданная координата РБ1 от ИС
#define A2AD05LDU	 BUFFER[596]	//(A2AD05LDU) паритет команды на РБ1
#define idA2AD05LDU	 249	//(A2AD05LDU) паритет команды на РБ1
#define A0VN71LS3	 BUFFER[598]	//(A0VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ1
#define idA0VN71LS3	 250	//(A0VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ1
#define R0VN15RS3	 BUFFER[600]	//(R0VN15RS3) Номер ведущей камеры канал 3
#define idR0VN15RS3	 251	//(R0VN15RS3) Номер ведущей камеры канал 3
#define A1VN71LS3	 BUFFER[603]	//(A1VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ2
#define idA1VN71LS3	 252	//(A1VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ2
#define R0VN73LZ1	 BUFFER[605]	//(R0VN73LZ1) АС по мощности канал 3 на БАЗ1
#define idR0VN73LZ1	 253	//(R0VN73LZ1) АС по мощности канал 3 на БАЗ1
#define R0VN61LS3	 BUFFER[607]	//(R0VN61LS3) ПС по мощности канал 3
#define idR0VN61LS3	 254	//(R0VN61LS3) ПС по мощности канал 3
#define R0VN02RS3	 BUFFER[609]	//(R0VN02RS3) Уровень мощности канал 3
#define idR0VN02RS3	 255	//(R0VN02RS3) Уровень мощности канал 3
#define R0IE11LS2	 BUFFER[614]	//(R0IE11LS2) Исправность ВИП 1,6 (№11) СНМ11 2канала
#define idR0IE11LS2	 256	//(R0IE11LS2) Исправность ВИП 1,6 (№11) СНМ11 2канала
#define R0IE13LS2	 BUFFER[616]	//(R0IE13LS2) Исправность ВИП 0,5 (№13) КНК53М 2канала
#define idR0IE13LS2	 257	//(R0IE13LS2) Исправность ВИП 0,5 (№13) КНК53М 2канала
#define R0IE12LS2	 BUFFER[618]	//(R0IE12LS2) Исправность ВИП 0,5 (№12) КНК15-1 2канала
#define idR0IE12LS2	 258	//(R0IE12LS2) Исправность ВИП 0,5 (№12) КНК15-1 2канала
#define A1EE01LS2	 BUFFER[620]	//(A1EE01LS2) Исправность АКНП канал 2 на БАЗ2
#define idA1EE01LS2	 259	//(A1EE01LS2) Исправность АКНП канал 2 на БАЗ2
#define R0VN76LZ2	 BUFFER[622]	//(R0VN76LZ2) АС по периоду разгона канал 2  на БАЗ2
#define idR0VN76LZ2	 260	//(R0VN76LZ2) АС по периоду разгона канал 2  на БАЗ2
#define A0EE01LS2	 BUFFER[624]	//(A0EE01LS2) Исправность АКНП канал 2 на БАЗ1
#define idA0EE01LS2	 261	//(A0EE01LS2) Исправность АКНП канал 2 на БАЗ1
#define R0VN76LZ1	 BUFFER[626]	//(R0VN76LZ1) АС по периоду разгона канал 2  на БАЗ1
#define idR0VN76LZ1	 262	//(R0VN76LZ1) АС по периоду разгона канал 2  на БАЗ1
#define R0VN65LS2	 BUFFER[628]	//(R0VN65LS2) ПС по периоду разгона канал 2
#define idR0VN65LS2	 263	//(R0VN65LS2) ПС по периоду разгона канал 2
#define R0VN01RS2	 BUFFER[630]	//(R0VN01RS2) Период разгона канал 2
#define idR0VN01RS2	 264	//(R0VN01RS2) Период разгона канал 2
#define A0VN71LS2	 BUFFER[635]	//(A0VN71LS2) Блокировка автоматического подъёма ББ канал 2 на БАЗ1
#define idA0VN71LS2	 265	//(A0VN71LS2) Блокировка автоматического подъёма ББ канал 2 на БАЗ1
#define R0VN72LZ2	 BUFFER[637]	//(R0VN72LZ2) АС по мощности канал 2 на БАЗ2
#define idR0VN72LZ2	 266	//(R0VN72LZ2) АС по мощности канал 2 на БАЗ2
#define R0VN15RS2	 BUFFER[639]	//(R0VN15RS2) Номер ведущей камеры канал 2
#define idR0VN15RS2	 267	//(R0VN15RS2) Номер ведущей камеры канал 2
#define A1VN71LS2	 BUFFER[642]	//(A1VN71LS2) Блокировка автоматического подъёма ББ канал 2 на БАЗ2
#define idA1VN71LS2	 268	//(A1VN71LS2) Блокировка автоматического подъёма ББ канал 2 на БАЗ2
#define R0VN72LZ1	 BUFFER[644]	//(R0VN72LZ1) АС по мощности канал 2 на БАЗ1
#define idR0VN72LZ1	 269	//(R0VN72LZ1) АС по мощности канал 2 на БАЗ1
#define A0EE01LS4	 BUFFER[646]	//(A0EE01LS4) Исправность АКНП канал 4 на БАЗ1
#define idA0EE01LS4	 270	//(A0EE01LS4) Исправность АКНП канал 4 на БАЗ1
#define R0VN78LZ1	 BUFFER[648]	//(R0VN78LZ1) АС по периоду разгона канал 4 на БАЗ1
#define idR0VN78LZ1	 271	//(R0VN78LZ1) АС по периоду разгона канал 4 на БАЗ1
#define R0VN65LS4	 BUFFER[650]	//(R0VN65LS4) ПС по периоду разгона канал 4
#define idR0VN65LS4	 272	//(R0VN65LS4) ПС по периоду разгона канал 4
#define R0VN01RS4	 BUFFER[652]	//(R0VN01RS4) Период разгона канал 4
#define idR0VN01RS4	 273	//(R0VN01RS4) Период разгона канал 4
#define R0VN74LZ2	 BUFFER[657]	//(R0VN74LZ2) АС по мощности канал 4 на БАЗ2
#define idR0VN74LZ2	 274	//(R0VN74LZ2) АС по мощности канал 4 на БАЗ2
#define A0VN71LS4	 BUFFER[659]	//(A0VN71LS4) Блокировка автоматического  подъёма ББ канал 4 на БАЗ1
#define idA0VN71LS4	 275	//(A0VN71LS4) Блокировка автоматического  подъёма ББ канал 4 на БАЗ1
#define R0VN15RS4	 BUFFER[661]	//(R0VN15RS4) Номер ведущей камеры канал 4
#define idR0VN15RS4	 276	//(R0VN15RS4) Номер ведущей камеры канал 4
#define A1VN71LS4	 BUFFER[664]	//(A1VN71LS4) Блокировка автоматического  подъёма ББ канал 4 на БАЗ2
#define idA1VN71LS4	 277	//(A1VN71LS4) Блокировка автоматического  подъёма ББ канал 4 на БАЗ2
#define R0VN74LZ1	 BUFFER[666]	//(R0VN74LZ1) АС по мощности канал 4 на БАЗ1
#define idR0VN74LZ1	 278	//(R0VN74LZ1) АС по мощности канал 4 на БАЗ1
#define R0VN61LS4	 BUFFER[668]	//(R0VN61LS4) ПС по мощности канал 4
#define idR0VN61LS4	 279	//(R0VN61LS4) ПС по мощности канал 4
#define R0VN02RS4	 BUFFER[670]	//(R0VN02RS4) Уровень мощности канал 4
#define idR0VN02RS4	 280	//(R0VN02RS4) Уровень мощности канал 4
#define R0IE11LS3	 BUFFER[675]	//(R0IE11LS3) Исправность ВИП 1,6 (№14) СНМ11 3канала
#define idR0IE11LS3	 281	//(R0IE11LS3) Исправность ВИП 1,6 (№14) СНМ11 3канала
#define R0IE13LS3	 BUFFER[677]	//(R0IE13LS3) Исправность ВИП 0,5 (№16) КНК53М 3канала
#define idR0IE13LS3	 282	//(R0IE13LS3) Исправность ВИП 0,5 (№16) КНК53М 3канала
#define R0IE12LS3	 BUFFER[679]	//(R0IE12LS3) Исправность ВИП 0,5 (№15) КНК15-1 3канала
#define idR0IE12LS3	 283	//(R0IE12LS3) Исправность ВИП 0,5 (№15) КНК15-1 3канала
#define A1EE01LS3	 BUFFER[681]	//(A1EE01LS3) Исправность АКНП канал 3 на БАЗ2
#define idA1EE01LS3	 284	//(A1EE01LS3) Исправность АКНП канал 3 на БАЗ2
#define R0VN77LZ2	 BUFFER[683]	//(R0VN77LZ2) АС по периоду разгона канал 3 на БАЗ2
#define idR0VN77LZ2	 285	//(R0VN77LZ2) АС по периоду разгона канал 3 на БАЗ2
#define A0EE01LS3	 BUFFER[685]	//(A0EE01LS3) Исправность АКНП канал 3 на БАЗ1
#define idA0EE01LS3	 286	//(A0EE01LS3) Исправность АКНП канал 3 на БАЗ1
#define R0VN77LZ1	 BUFFER[687]	//(R0VN77LZ1) АС по периоду разгона канал 3 на БАЗ1
#define idR0VN77LZ1	 287	//(R0VN77LZ1) АС по периоду разгона канал 3 на БАЗ1
#define R0VN65LS3	 BUFFER[689]	//(R0VN65LS3) ПС по периоду разгона канал 3
#define idR0VN65LS3	 288	//(R0VN65LS3) ПС по периоду разгона канал 3
#define R0VN01RS3	 BUFFER[691]	//(R0VN01RS3) Период разгона канал 3
#define idR0VN01RS3	 289	//(R0VN01RS3) Период разгона канал 3
#define R0VN73LZ2	 BUFFER[696]	//(R0VN73LZ2) АС по мощности канал 3 на БАЗ2
#define idR0VN73LZ2	 290	//(R0VN73LZ2) АС по мощности канал 3 на БАЗ2
#define R7II73LZ2	 BUFFER[698]	//(R7II73LZ2) Сработала АС IIУР
#define idR7II73LZ2	 291	//(R7II73LZ2) Сработала АС IIУР
#define R7II71LZ2	 BUFFER[700]	//(R7II71LZ2) Сработала АС IУР (датчик 1)
#define idR7II71LZ2	 292	//(R7II71LZ2) Сработала АС IУР (датчик 1)
#define R7II72LZ2	 BUFFER[702]	//(R7II72LZ2) Сработала АС IУР (датчик 2)
#define idR7II72LZ2	 293	//(R7II72LZ2) Сработала АС IУР (датчик 2)
#define R0AD16LDU	 BUFFER[704]	//(R0AD16LDU) Контроль  I-II УР. РАД
#define idR0AD16LDU	 294	//(R0AD16LDU) Контроль  I-II УР. РАД
#define R7II72LZ1	 BUFFER[706]	//(R7II72LZ1) Сработала АС IУР (датчик 2)
#define idR7II72LZ1	 295	//(R7II72LZ1) Сработала АС IУР (датчик 2)
#define R7II71LZ1	 BUFFER[708]	//(R7II71LZ1) Сработала АС IУР (датчик 1)
#define idR7II71LZ1	 296	//(R7II71LZ1) Сработала АС IУР (датчик 1)
#define R7II73LZ1	 BUFFER[710]	//(R7II73LZ1) Сработала АС IIУР
#define idR7II73LZ1	 297	//(R7II73LZ1) Сработала АС IIУР
#define R0SR01RIM	 BUFFER[712]	//(R0SR01RIM) Текущая реактивность PУ
#define idR0SR01RIM	 298	//(R0SR01RIM) Текущая реактивность PУ
#define R0ST01RIM	 BUFFER[717]	//(R0ST01RIM) Текущий период разгона РУ
#define idR0ST01RIM	 299	//(R0ST01RIM) Текущий период разгона РУ
#define A4AD10LDU	 BUFFER[722]	//(A4AD10LDU) Открыть клапан (Подъем НИ1)
#define idA4AD10LDU	 300	//(A4AD10LDU) Открыть клапан (Подъем НИ1)
#define B4AD10LDU	 BUFFER[724]	//(B4AD10LDU) Открыть клапан (Подъем НИ2)
#define idB4AD10LDU	 301	//(B4AD10LDU) Открыть клапан (Подъем НИ2)
#define A9AD10LDU	 BUFFER[726]	//(A9AD10LDU) Открыть клапан (Подъем НИ ДС1)
#define idA9AD10LDU	 302	//(A9AD10LDU) Открыть клапан (Подъем НИ ДС1)
#define B9AD10LDU	 BUFFER[728]	//(B9AD10LDU) Открыть клапан (Подъем НИ ДС2)
#define idB9AD10LDU	 303	//(B9AD10LDU) Открыть клапан (Подъем НИ ДС2)
#define R0MW13LP2	 BUFFER[730]	//(R0MW13LP2) Переключатель «СЕТЬ»
#define idR0MW13LP2	 304	//(R0MW13LP2) Переключатель «СЕТЬ»
#define B3AD31LDU	 BUFFER[732]	//(B3AD31LDU) Клапан (СПУСК ИС2) открыть (обесточить)
#define idB3AD31LDU	 305	//(B3AD31LDU) Клапан (СПУСК ИС2) открыть (обесточить)
#define B2AD32LDU	 BUFFER[734]	//(B2AD32LDU) Обесточить ЭМ РБ2
#define idB2AD32LDU	 306	//(B2AD32LDU) Обесточить ЭМ РБ2
#define B2AD31LDU	 BUFFER[736]	//(B2AD31LDU) Клапан (Сброс РБ2) открыть (обесточить)
#define idB2AD31LDU	 307	//(B2AD31LDU) Клапан (Сброс РБ2) открыть (обесточить)
#define B1AD32LDU	 BUFFER[738]	//(B1AD32LDU) Обесточить ЭМ ББ2
#define idB1AD32LDU	 308	//(B1AD32LDU) Обесточить ЭМ ББ2
#define B1AD31LDU	 BUFFER[740]	//(B1AD31LDU) Клапан (Сброс ББ2) открыть (обесточить)
#define idB1AD31LDU	 309	//(B1AD31LDU) Клапан (Сброс ББ2) открыть (обесточить)
#define A3AD31LDU	 BUFFER[742]	//(A3AD31LDU) Клапан (СПУСК ИС1) открыть (обесточить)
#define idA3AD31LDU	 310	//(A3AD31LDU) Клапан (СПУСК ИС1) открыть (обесточить)
#define C1MD31LP1	 BUFFER[744]	//(C1MD31LP1) Кнопка «СБРОС ББ»  на ОПУ1
#define idC1MD31LP1	 311	//(C1MD31LP1) Кнопка «СБРОС ББ»  на ОПУ1
#define R0VN61LS2	 BUFFER[746]	//(R0VN61LS2) ПС по мощности канал 2
#define idR0VN61LS2	 312	//(R0VN61LS2) ПС по мощности канал 2
#define R0VN02RS2	 BUFFER[748]	//(R0VN02RS2) Уровень мощности канал 2
#define idR0VN02RS2	 313	//(R0VN02RS2) Уровень мощности канал 2
#define R0IE13LS1	 BUFFER[753]	//(R0IE13LS1) Исправность ВИП 0,5 (№10) КНК53М 1канала
#define idR0IE13LS1	 314	//(R0IE13LS1) Исправность ВИП 0,5 (№10) КНК53М 1канала
#define R0IE12LS1	 BUFFER[755]	//(R0IE12LS1) Исправность ВИП 0,5 (№9) КНК15-1 1канала
#define idR0IE12LS1	 315	//(R0IE12LS1) Исправность ВИП 0,5 (№9) КНК15-1 1канала
#define R0IE11LS1	 BUFFER[757]	//(R0IE11LS1) Исправность ВИП 1,6 (№8) СНМ11 1канала
#define idR0IE11LS1	 316	//(R0IE11LS1) Исправность ВИП 1,6 (№8) СНМ11 1канала
#define A1EE01LS1	 BUFFER[759]	//(A1EE01LS1) Исправность АКНП на БАЗ2
#define idA1EE01LS1	 317	//(A1EE01LS1) Исправность АКНП на БАЗ2
#define R0VN75LZ2	 BUFFER[761]	//(R0VN75LZ2) АС по периоду разгонана БАЗ2
#define idR0VN75LZ2	 318	//(R0VN75LZ2) АС по периоду разгонана БАЗ2
#define A0EE01LS1	 BUFFER[763]	//(A0EE01LS1) Исправность АКНП канал1 на БАЗ1
#define idA0EE01LS1	 319	//(A0EE01LS1) Исправность АКНП канал1 на БАЗ1
#define R0VN75LZ1	 BUFFER[765]	//(R0VN75LZ1) АС по периоду разгонана БАЗ1
#define idR0VN75LZ1	 320	//(R0VN75LZ1) АС по периоду разгонана БАЗ1
#define R0VN65LS1	 BUFFER[767]	//(R0VN65LS1) ПС по периоду разгона канал1
#define idR0VN65LS1	 321	//(R0VN65LS1) ПС по периоду разгона канал1
#define R0VN01RS1	 BUFFER[769]	//(R0VN01RS1) Период разгона канал1
#define idR0VN01RS1	 322	//(R0VN01RS1) Период разгона канал1
#define A1VN71LS1	 BUFFER[774]	//(A1VN71LS1) Блокировка автоматического  подъёма ББ канал 1 на БАЗ2
#define idA1VN71LS1	 323	//(A1VN71LS1) Блокировка автоматического  подъёма ББ канал 1 на БАЗ2
#define R0VN71LZ2	 BUFFER[776]	//(R0VN71LZ2) АС по мощности канал 1  на БАЗ2
#define idR0VN71LZ2	 324	//(R0VN71LZ2) АС по мощности канал 1  на БАЗ2
#define R0VN15RS1	 BUFFER[778]	//(R0VN15RS1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
#define idR0VN15RS1	 325	//(R0VN15RS1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
#define A0VN71LS1	 BUFFER[781]	//(A0VN71LS1) Блокировка автоматического  подъёма ББ канал 1 на БАЗ1
#define idA0VN71LS1	 326	//(A0VN71LS1) Блокировка автоматического  подъёма ББ канал 1 на БАЗ1
#define R0VN71LZ1	 BUFFER[783]	//(R0VN71LZ1) АС по мощности канал1 на БАЗ1
#define idR0VN71LZ1	 327	//(R0VN71LZ1) АС по мощности канал1 на БАЗ1
#define R0VN61LS1	 BUFFER[785]	//(R0VN61LS1) ПС по мощности канал1
#define idR0VN61LS1	 328	//(R0VN61LS1) ПС по мощности канал1
#define R0VN02RS1	 BUFFER[787]	//(R0VN02RS1) Уровень мощности канал1
#define idR0VN02RS1	 329	//(R0VN02RS1) Уровень мощности канал1
#define B3IS35LDU	 BUFFER[792]	//(B3IS35LDU) Клапан «ВПИС2» открыт(обесточен)
#define idB3IS35LDU	 330	//(B3IS35LDU) Клапан «ВПИС2» открыт(обесточен)
#define B3AD34LDU	 BUFFER[794]	//(B3AD34LDU) Клапан (ВПИС2) открыть (обесточить)
#define idB3AD34LDU	 331	//(B3AD34LDU) Клапан (ВПИС2) открыть (обесточить)
#define A3IS35LDU	 BUFFER[796]	//(A3IS35LDU) Клапан (ВПИС1) открыт(обесточен)
#define idA3IS35LDU	 332	//(A3IS35LDU) Клапан (ВПИС1) открыт(обесточен)
#define fEM_R0UL01RIM	 BUFFER[798]	//(R0UL01RIM) Среднее время генерации нейтронов
#define idfEM_R0UL01RIM	 333	//(R0UL01RIM) Среднее время генерации нейтронов
#define fEM_R0UN02RIM	 BUFFER[803]	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define idfEM_R0UN02RIM	 334	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define fEM_A1UR01RIM	 BUFFER[808]	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR01RIM	 335	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define fEM_A1UR00RIM	 BUFFER[813]	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR00RIM	 336	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define fEM_A3UR00RIM	 BUFFER[818]	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR00RIM	 337	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define fEM_A3UR01RIM	 BUFFER[823]	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR01RIM	 338	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define fEM_R0UT01RIM	 BUFFER[828]	//(R0UT01RIM) Температурный коэффициент (долл)
#define idfEM_R0UT01RIM	 339	//(R0UT01RIM) Температурный коэффициент (долл)
#define fEM_R0UT02RIM	 BUFFER[833]	//(R0UT02RIM) Масса топлива в АЗ
#define idfEM_R0UT02RIM	 340	//(R0UT02RIM) Масса топлива в АЗ
#define fEM_R0UT04RIM	 BUFFER[838]	//(R0UT04RIM) Удельная теплоёмкость топлива
#define idfEM_R0UT04RIM	 341	//(R0UT04RIM) Удельная теплоёмкость топлива
#define fEM_R0UT03RIM	 BUFFER[843]	//(R0UT03RIM) Нормальная температура АЗ град
#define idfEM_R0UT03RIM	 342	//(R0UT03RIM) Нормальная температура АЗ град
#define fEM_R0UT05RIM	 BUFFER[848]	//(R0UT05RIM) Энергия деления ядра
#define idfEM_R0UT05RIM	 343	//(R0UT05RIM) Энергия деления ядра
#define fEM_R0UT06RIM	 BUFFER[853]	//(R0UT06RIM) Конвекционное сопротивление при обдуве
#define idfEM_R0UT06RIM	 344	//(R0UT06RIM) Конвекционное сопротивление при обдуве
#define fEM_A1UC02RDU	 BUFFER[858]	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define idfEM_A1UC02RDU	 345	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define fEM_A1UC04RIM	 BUFFER[863]	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define idfEM_A1UC04RIM	 346	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define fEM_A1UC05RIM	 BUFFER[868]	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define idfEM_A1UC05RIM	 347	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define fEM_A1UC06RIM	 BUFFER[873]	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define idfEM_A1UC06RIM	 348	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define fEM_A2UC06RIM	 BUFFER[878]	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define idfEM_A2UC06RIM	 349	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define fEM_A2UC05RIM	 BUFFER[883]	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define idfEM_A2UC05RIM	 350	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define fEM_A2UC04RIM	 BUFFER[888]	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define idfEM_A2UC04RIM	 351	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define fEM_A2UC02RDU	 BUFFER[893]	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define idfEM_A2UC02RDU	 352	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define fEM_A3UC06RIM	 BUFFER[898]	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define idfEM_A3UC06RIM	 353	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define fEM_A3UC05RIM	 BUFFER[903]	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC05RIM	 354	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define fEM_A3UC04RIM	 BUFFER[908]	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define idfEM_A3UC04RIM	 355	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define fEM_A3UC02RDU	 BUFFER[913]	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define idfEM_A3UC02RDU	 356	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define fEM_R4UV80RDU	 BUFFER[918]	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
#define idfEM_R4UV80RDU	 357	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
#define fEM_R4UC10RIM	 BUFFER[923]	//(R4UC10RIM) Координата верхних механических упоров тележки мм
#define idfEM_R4UC10RIM	 358	//(R4UC10RIM) Координата верхних механических упоров тележки мм
#define fEM_R4UC20RIM	 BUFFER[928]	//(R4UC20RIM) Координата нижних механических упоров тележки мм
#define idfEM_R4UC20RIM	 359	//(R4UC20RIM) Координата нижних механических упоров тележки мм
#define fEM_B8UC21RIM	 BUFFER[933]	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define idfEM_B8UC21RIM	 360	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define fEM_B8UC20RIM	 BUFFER[938]	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define idfEM_B8UC20RIM	 361	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define fEM_B8UC11RIM	 BUFFER[943]	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define idfEM_B8UC11RIM	 362	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define fEM_B8UC10RIM	 BUFFER[948]	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define idfEM_B8UC10RIM	 363	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define fEM_B8UV80RDU	 BUFFER[953]	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define idfEM_B8UV80RDU	 364	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define fEM_A8UV80RDU	 BUFFER[958]	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define idfEM_A8UV80RDU	 365	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define fEM_A8UC10RIM	 BUFFER[963]	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define idfEM_A8UC10RIM	 366	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define fEM_A8UC11RIM	 BUFFER[968]	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define idfEM_A8UC11RIM	 367	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define fEM_A8UC20RIM	 BUFFER[973]	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define idfEM_A8UC20RIM	 368	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define fEM_A8UC21RIM	 BUFFER[978]	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define idfEM_A8UC21RIM	 369	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define fEM_A6UC10RIM	 BUFFER[983]	//(A6UC10RIM) Время полного хода БЗ (сек)
#define idfEM_A6UC10RIM	 370	//(A6UC10RIM) Время полного хода БЗ (сек)
#define fEM_R1UC10RIM	 BUFFER[988]	//(R1UC10RIM) Время полного хода МДЗ сек
#define idfEM_R1UC10RIM	 371	//(R1UC10RIM) Время полного хода МДЗ сек
#define fEM_A5UC10RIM	 BUFFER[993]	//(A5UC10RIM) Время полного хода НЛ сек
#define idfEM_A5UC10RIM	 372	//(A5UC10RIM) Время полного хода НЛ сек
#define fEM_A0UN01RIM	 BUFFER[998]	//(A0UN01RIM) Мощность источника нейтронов ИНИ
#define idfEM_A0UN01RIM	 373	//(A0UN01RIM) Мощность источника нейтронов ИНИ
#define fEM_R4UC22RIM	 BUFFER[1003]	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define idfEM_R4UC22RIM	 374	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define fEM_R4UC23RIM	 BUFFER[1008]	//(R4UC23RIM) Y-координата АЗ1 см
#define idfEM_R4UC23RIM	 375	//(R4UC23RIM) Y-координата АЗ1 см
#define fEM_A1UG01RDU	 BUFFER[1013]	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define idfEM_A1UG01RDU	 376	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define fEM_A2UG01RDU	 BUFFER[1018]	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
#define idfEM_A2UG01RDU	 377	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
#define fEM_A3UG01RDU	 BUFFER[1023]	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
#define idfEM_A3UG01RDU	 378	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
#define fEM_R7UC10RIM	 BUFFER[1028]	//(R7UC10RIM) X-координата КНК53М R7IN13 см
#define idfEM_R7UC10RIM	 379	//(R7UC10RIM) X-координата КНК53М R7IN13 см
#define fEM_R7UC19RIM	 BUFFER[1033]	//(R7UC19RIM) Y-координата СНМ-11 (11) см
#define idfEM_R7UC19RIM	 380	//(R7UC19RIM) Y-координата СНМ-11 (11) см
#define fEM_R7UI02RIM	 BUFFER[1038]	//(R7UI02RIM) Коэффициент усиления уровня радиации
#define idfEM_R7UI02RIM	 381	//(R7UI02RIM) Коэффициент усиления уровня радиации
#define fEM_R7UL01RIM	 BUFFER[1043]	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define idfEM_R7UL01RIM	 382	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define fEM_A2UR00RIM	 BUFFER[1048]	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define idfEM_A2UR00RIM	 383	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define fEM_A2UR01RIM	 BUFFER[1053]	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define idfEM_A2UR01RIM	 384	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define fEM_A0UN02RIM	 BUFFER[1058]	//(A0UN02RIM) Мощность источника нейтронов с АНИ
#define idfEM_A0UN02RIM	 385	//(A0UN02RIM) Мощность источника нейтронов с АНИ
#define fEM_R0UR30RIM	 BUFFER[1063]	//(R0UR30RIM) Реактивность вносимая образцами (долл)
#define idfEM_R0UR30RIM	 386	//(R0UR30RIM) Реактивность вносимая образцами (долл)
#define fEM_R0UR01RIM	 BUFFER[1068]	//(R0UR01RIM) Стартовая отрицательная реактивность
#define idfEM_R0UR01RIM	 387	//(R0UR01RIM) Стартовая отрицательная реактивность
#define fEM_R0UT02RDU	 BUFFER[1073]	//(R0UT02RDU) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RDU	 388	//(R0UT02RDU) Верхний предел шкалы датчика температуры
#define fEM_R0UT01RDU	 BUFFER[1078]	//(R0UT01RDU) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RDU	 389	//(R0UT01RDU) Нижний предел шкалы датчика температуры
#define fEM_A1UC03RDU	 BUFFER[1083]	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define idfEM_A1UC03RDU	 390	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define fEM_A2UP03RDU	 BUFFER[1088]	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP03RDU	 391	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UP04RDU	 BUFFER[1093]	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP04RDU	 392	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UC03RDU	 BUFFER[1098]	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define idfEM_A2UC03RDU	 393	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define fEM_A3UP03RDU	 BUFFER[1103]	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	 394	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	 BUFFER[1108]	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	 395	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UC03RDU	 BUFFER[1113]	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define idfEM_A3UC03RDU	 396	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define fEM_R7UI74RIM	 BUFFER[1118]	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define idfEM_R7UI74RIM	 397	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define fEM_A8UC03RDU	 BUFFER[1123]	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define idfEM_A8UC03RDU	 398	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define fEM_R0UV87RDU	 BUFFER[1128]	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	 399	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV81RDU	 BUFFER[1133]	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	 400	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	 BUFFER[1138]	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	 401	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	 BUFFER[1143]	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	 402	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	 BUFFER[1148]	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	 403	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define fEM_R0UV85RDU	 BUFFER[1153]	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	 404	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV86RDU	 BUFFER[1158]	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	 405	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_A8UC08RDU	 BUFFER[1163]	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define idfEM_A8UC08RDU	 406	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define fEM_B8UC08RDU	 BUFFER[1168]	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define idfEM_B8UC08RDU	 407	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define fEM_R4UC08RDU	 BUFFER[1173]	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define idfEM_R4UC08RDU	 408	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define fEM_A0UX00RSS	 BUFFER[1178]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 409	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_R7UX01RSS	 BUFFER[1183]	//(R7UX01RSS) X-координата камеры R7IN11
#define idfEM_R7UX01RSS	 410	//(R7UX01RSS) X-координата камеры R7IN11
#define fEM_R7UX02RSS	 BUFFER[1188]	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define idfEM_R7UX02RSS	 411	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define fEM_R7UX04RSS	 BUFFER[1193]	//(R7UX04RSS) X-координата камеры R7IN21 (см)
#define idfEM_R7UX04RSS	 412	//(R7UX04RSS) X-координата камеры R7IN21 (см)
#define fEM_R7UX05RSS	 BUFFER[1198]	//(R7UX05RSS) X-координата камеры R7IN22 (см)
#define idfEM_R7UX05RSS	 413	//(R7UX05RSS) X-координата камеры R7IN22 (см)
#define fEM_R7UX06RSS	 BUFFER[1203]	//(R7UX06RSS) X-координата камеры R7IN23 (см)
#define idfEM_R7UX06RSS	 414	//(R7UX06RSS) X-координата камеры R7IN23 (см)
#define fEM_R7UX07RSS	 BUFFER[1208]	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define idfEM_R7UX07RSS	 415	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define fEM_R7UX08RSS	 BUFFER[1213]	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define idfEM_R7UX08RSS	 416	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define fEM_R7UX09RSS	 BUFFER[1218]	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define idfEM_R7UX09RSS	 417	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define fEM_R7UY01RSS	 BUFFER[1223]	//(R7UY01RSS) Y-координата камеры R7IN11
#define idfEM_R7UY01RSS	 418	//(R7UY01RSS) Y-координата камеры R7IN11
#define fEM_R7UY02RSS	 BUFFER[1228]	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define idfEM_R7UY02RSS	 419	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define fEM_R7UY04RSS	 BUFFER[1233]	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
#define idfEM_R7UY04RSS	 420	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
#define fEM_R7UY05RSS	 BUFFER[1238]	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
#define idfEM_R7UY05RSS	 421	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
#define fEM_R7UY06RSS	 BUFFER[1243]	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
#define idfEM_R7UY06RSS	 422	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
#define fEM_R7UY07RSS	 BUFFER[1248]	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define idfEM_R7UY07RSS	 423	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define fEM_R7UY08RSS	 BUFFER[1253]	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define idfEM_R7UY08RSS	 424	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define fEM_R7UY09RSS	 BUFFER[1258]	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define idfEM_R7UY09RSS	 425	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define fEM_R7UX10RSS	 BUFFER[1263]	//(R7UX10RSS) X-координата камеры R7IN41
#define idfEM_R7UX10RSS	 426	//(R7UX10RSS) X-координата камеры R7IN41
#define fEM_R7UX11RSS	 BUFFER[1268]	//(R7UX11RSS) X-координата камеры R7IN42
#define idfEM_R7UX11RSS	 427	//(R7UX11RSS) X-координата камеры R7IN42
#define fEM_R7UX12RSS	 BUFFER[1273]	//(R7UX12RSS) X-координата камеры R7IN43
#define idfEM_R7UX12RSS	 428	//(R7UX12RSS) X-координата камеры R7IN43
#define fEM_R7UY10RSS	 BUFFER[1278]	//(R7UY10RSS) Y-координата камеры R7IN41
#define idfEM_R7UY10RSS	 429	//(R7UY10RSS) Y-координата камеры R7IN41
#define fEM_R7UY11RSS	 BUFFER[1283]	//(R7UY11RSS) Y-координата камеры R7IN42
#define idfEM_R7UY11RSS	 430	//(R7UY11RSS) Y-координата камеры R7IN42
#define fEM_R7UY12RSS	 BUFFER[1288]	//(R7UY12RSS) Y-координата камеры R7IN43
#define idfEM_R7UY12RSS	 431	//(R7UY12RSS) Y-координата камеры R7IN43
#define fEM_A0UX01RSS	 BUFFER[1293]	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define idfEM_A0UX01RSS	 432	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define fEM_A0UX02RSS	 BUFFER[1298]	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define idfEM_A0UX02RSS	 433	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define fEM_A0UX03RSS	 BUFFER[1303]	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define idfEM_A0UX03RSS	 434	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define fEM_A0UX04RSS	 BUFFER[1308]	//(A0UX04RSS) Первый коэффициент калибровки камеры4
#define idfEM_A0UX04RSS	 435	//(A0UX04RSS) Первый коэффициент калибровки камеры4
#define fEM_A0UX05RSS	 BUFFER[1313]	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
#define idfEM_A0UX05RSS	 436	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
#define fEM_A0UX06RSS	 BUFFER[1318]	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
#define idfEM_A0UX06RSS	 437	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
#define fEM_A0UX07RSS	 BUFFER[1323]	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define idfEM_A0UX07RSS	 438	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define fEM_A0UX08RSS	 BUFFER[1328]	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define idfEM_A0UX08RSS	 439	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define fEM_A0UX09RSS	 BUFFER[1333]	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define idfEM_A0UX09RSS	 440	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define fEM_A0UX10RSS	 BUFFER[1338]	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define idfEM_A0UX10RSS	 441	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define fEM_A0UX11RSS	 BUFFER[1343]	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define idfEM_A0UX11RSS	 442	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define fEM_A0UX12RSS	 BUFFER[1348]	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define idfEM_A0UX12RSS	 443	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define fEM_B0UX01RSS	 BUFFER[1353]	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define idfEM_B0UX01RSS	 444	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define fEM_B0UX02RSS	 BUFFER[1358]	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define idfEM_B0UX02RSS	 445	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define fEM_B0UX03RSS	 BUFFER[1363]	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define idfEM_B0UX03RSS	 446	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define fEM_B0UX04RSS	 BUFFER[1368]	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
#define idfEM_B0UX04RSS	 447	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
#define fEM_B0UX05RSS	 BUFFER[1373]	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define idfEM_B0UX05RSS	 448	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define fEM_B0UX06RSS	 BUFFER[1378]	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
#define idfEM_B0UX06RSS	 449	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
#define fEM_B0UX07RSS	 BUFFER[1383]	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define idfEM_B0UX07RSS	 450	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define fEM_B0UX08RSS	 BUFFER[1388]	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define idfEM_B0UX08RSS	 451	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define fEM_B0UX09RSS	 BUFFER[1393]	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define idfEM_B0UX09RSS	 452	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define fEM_B0UX10RSS	 BUFFER[1398]	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define idfEM_B0UX10RSS	 453	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define fEM_B0UX11RSS	 BUFFER[1403]	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define idfEM_B0UX11RSS	 454	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define fEM_B0UX12RSS	 BUFFER[1408]	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define idfEM_B0UX12RSS	 455	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define fEM_R0UH02RSS	 BUFFER[1413]	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define idfEM_R0UH02RSS	 456	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define fEM_R0UH03RSS	 BUFFER[1418]	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define idfEM_R0UH03RSS	 457	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define fEM_R4US80RDU	 BUFFER[1423]	//(R4US80RDU) Тормозной путь тележки (мм)
#define idfEM_R4US80RDU	 458	//(R4US80RDU) Тормозной путь тележки (мм)
#define fEM_R7UI71RIM	 BUFFER[1428]	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define idfEM_R7UI71RIM	 459	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define fEM_R7UI72RIM	 BUFFER[1433]	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
#define idfEM_R7UI72RIM	 460	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
#define fEM_R7UI73RIM	 BUFFER[1438]	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define idfEM_R7UI73RIM	 461	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define fEM_A1UP01RIM	 BUFFER[1443]	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define idfEM_A1UP01RIM	 462	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define fEM_A2UP01RIM	 BUFFER[1448]	//(A2UP01RIM) Текущее давление на сброс РБ
#define idfEM_A2UP01RIM	 463	//(A2UP01RIM) Текущее давление на сброс РБ
#define fEM_A0UP02RIM	 BUFFER[1453]	//(A0UP02RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP02RIM	 464	//(A0UP02RIM) Текущее давление в АЗ1,2
#define fEM_A3UP01RIM	 BUFFER[1458]	//(A3UP01RIM) Текущее давление на СПУСК ИС
#define idfEM_A3UP01RIM	 465	//(A3UP01RIM) Текущее давление на СПУСК ИС
#define fEM_A1UP82RIM	 BUFFER[1463]	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define idfEM_A1UP82RIM	 466	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define fEM_R0UP85RIM	 BUFFER[1468]	//(R0UP85RIM) Нижняя граница давления  в СИСТЕМЕ (МПа)
#define idfEM_R0UP85RIM	 467	//(R0UP85RIM) Нижняя граница давления  в СИСТЕМЕ (МПа)
#define fEM_R0UP88RIM	 BUFFER[1473]	//(R0UP88RIM) Верхняя граница давления  в СИСТЕМЕ (МПа)
#define idfEM_R0UP88RIM	 468	//(R0UP88RIM) Верхняя граница давления  в СИСТЕМЕ (МПа)
#define fEM_A3UP02RDU	 BUFFER[1478]	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define idfEM_A3UP02RDU	 469	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define fEM_A1UV02RIM	 BUFFER[1483]	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define idfEM_A1UV02RIM	 470	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define fEM_A3UV02RIM	 BUFFER[1488]	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define idfEM_A3UV02RIM	 471	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define fEM_A2UV02RIM	 BUFFER[1493]	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define idfEM_A2UV02RIM	 472	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define fEM_B8US80RDU	 BUFFER[1498]	//(B8US80RDU) Тормозной путь АЗ2 (мм)
#define idfEM_B8US80RDU	 473	//(B8US80RDU) Тормозной путь АЗ2 (мм)
#define fEM_A8US80RDU	 BUFFER[1503]	//(A8US80RDU) Тормозной путь ДС2 (мм)
#define idfEM_A8US80RDU	 474	//(A8US80RDU) Тормозной путь ДС2 (мм)
#define fEM_A6US80RDU	 BUFFER[1508]	//(A6US80RDU) Тормозной путь БЗ (мм)
#define idfEM_A6US80RDU	 475	//(A6US80RDU) Тормозной путь БЗ (мм)
#define fEM_A1US07RDU	 BUFFER[1513]	//(A1US07RDU) Постоянная времени масляного демпфера ББ
#define idfEM_A1US07RDU	 476	//(A1US07RDU) Постоянная времени масляного демпфера ББ
#define fEM_A2US07RDU	 BUFFER[1518]	//(A2US07RDU) Постоянная времени масляного демпфера РБ
#define idfEM_A2US07RDU	 477	//(A2US07RDU) Постоянная времени масляного демпфера РБ
#define fEM_A3US07RDU	 BUFFER[1523]	//(A3US07RDU) Постоянная времени масляного демпфера ИС
#define idfEM_A3US07RDU	 478	//(A3US07RDU) Постоянная времени масляного демпфера ИС
#define fEM_R7UI75RIM	 BUFFER[1528]	//(R7UI75RIM) Множитель к уровню радиации
#define idfEM_R7UI75RIM	 479	//(R7UI75RIM) Множитель к уровню радиации
#define fEM_R0UH21RSS	 BUFFER[1533]	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define idfEM_R0UH21RSS	 480	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define fEM_R0UH22RSS	 BUFFER[1538]	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define idfEM_R0UH22RSS	 481	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define fEM_R0UH23RSS	 BUFFER[1543]	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define idfEM_R0UH23RSS	 482	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define fEM_R0UR01RSS	 BUFFER[1548]	//(R0UR01RSS) Уровень по мощности РУ блокировки автоматического подъёма ББ
#define idfEM_R0UR01RSS	 483	//(R0UR01RSS) Уровень по мощности РУ блокировки автоматического подъёма ББ
#define fEM_R0UL52RSS	 BUFFER[1553]	//(R0UL52RSS) Уровень АС по мощности
#define idfEM_R0UL52RSS	 484	//(R0UL52RSS) Уровень АС по мощности
#define fEM_R0UL41RSS	 BUFFER[1558]	//(R0UL41RSS) Уровень ПС по периоду разгона
#define idfEM_R0UL41RSS	 485	//(R0UL41RSS) Уровень ПС по периоду разгона
#define fEM_R0UL51RSS	 BUFFER[1563]	//(R0UL51RSS) Уровень АС по периоду разгона
#define idfEM_R0UL51RSS	 486	//(R0UL51RSS) Уровень АС по периоду разгона
#define fEM_R0UL42RSS	 BUFFER[1568]	//(R0UL42RSS) Уровень ПС по мощности
#define idfEM_R0UL42RSS	 487	//(R0UL42RSS) Уровень ПС по мощности
#define fEM_R0UH05RSS	 BUFFER[1573]	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	 488	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_R0UN03RSS	 BUFFER[1578]	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN03RSS	 489	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define fEM_A4UL10RIM	 BUFFER[1583]	//(A4UL10RIM) Время полного перемещения НИ сек
#define idfEM_A4UL10RIM	 490	//(A4UL10RIM) Время полного перемещения НИ сек
#define fEM_A9UL10RIM	 BUFFER[1588]	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define idfEM_A9UL10RIM	 491	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define fEM_R3UL10RIM	 BUFFER[1593]	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define idfEM_R3UL10RIM	 492	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define fEM_R5UL10RIM	 BUFFER[1598]	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define idfEM_R5UL10RIM	 493	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define fEM_R6UL10RIM	 BUFFER[1603]	//(R6UL10RIM) Время полного хода кран-балки сек
#define idfEM_R6UL10RIM	 494	//(R6UL10RIM) Время полного хода кран-балки сек
#define lEM_C1AD31LRP	 BUFFER[1608]	//(C1AD31LRP) Общий сброс от РПУ
#define idlEM_C1AD31LRP	 495	//(C1AD31LRP) Общий сброс от РПУ
#define lEM_R0IE01LRP	 BUFFER[1610]	//(R0IE01LRP) Отключение питание детекторов
#define idlEM_R0IE01LRP	 496	//(R0IE01LRP) Отключение питание детекторов
#define lEM_R0IE02LRP	 BUFFER[1612]	//(R0IE02LRP) Отключить питание ПР, ПУ
#define idlEM_R0IE02LRP	 497	//(R0IE02LRP) Отключить питание ПР, ПУ
#define fEM_A0UP03RIM	 BUFFER[1614]	//(A0UP03RIM) Текущее давление в системе
#define idfEM_A0UP03RIM	 498	//(A0UP03RIM) Текущее давление в системе
#define fEM_A2UP02RIM	 BUFFER[1619]	//(A2UP02RIM) Текущее давление на подъём РБ
#define idfEM_A2UP02RIM	 499	//(A2UP02RIM) Текущее давление на подъём РБ
#define fEM_A2UP03RIM	 BUFFER[1624]	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define idfEM_A2UP03RIM	 500	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define fEM_A0UP01RIM	 BUFFER[1629]	//(A0UP01RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP01RIM	 501	//(A0UP01RIM) Текущее давление в АЗ1,2
#define fEM_A3UP02RIM	 BUFFER[1634]	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define idfEM_A3UP02RIM	 502	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define fEM_A4UP01RIM	 BUFFER[1639]	//(A4UP01RIM) Текущее давление на подъём НИ
#define idfEM_A4UP01RIM	 503	//(A4UP01RIM) Текущее давление на подъём НИ
#define fEM_A4UP02RIM	 BUFFER[1644]	//(A4UP02RIM) Нижняя граница давления на подъём НИ
#define idfEM_A4UP02RIM	 504	//(A4UP02RIM) Нижняя граница давления на подъём НИ
#define fEM_R7UI76RIM	 BUFFER[1649]	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define idfEM_R7UI76RIM	 505	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define fEM_R7UI77RIM	 BUFFER[1654]	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define idfEM_R7UI77RIM	 506	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define iEM_TERBB1	 BUFFER[1659]	//(TERBB1) Неисправности  ББ1
#define idiEM_TERBB1	 507	//(TERBB1) Неисправности  ББ1
#define fEM_A1MC02RC1	 BUFFER[1662]	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
#define idfEM_A1MC02RC1	 508	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
#define fEM_A1MV02RC1	 BUFFER[1667]	//(A1MV02RC1) Заданная скорость движения штока ББ1 от ИС
#define idfEM_A1MV02RC1	 509	//(A1MV02RC1) Заданная скорость движения штока ББ1 от ИС
#define iEM_TERBB2	 BUFFER[1672]	//(TERBB2) Неисправности  ББ2
#define idiEM_TERBB2	 510	//(TERBB2) Неисправности  ББ2
#define fEM_B1MC02RC1	 BUFFER[1675]	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
#define idfEM_B1MC02RC1	 511	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
#define fEM_B1MV02RC1	 BUFFER[1680]	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define idfEM_B1MV02RC1	 512	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define iEM_TERRB2	 BUFFER[1685]	//(TERRB2) Неисправности  РБ2
#define idiEM_TERRB2	 513	//(TERRB2) Неисправности  РБ2
#define fEM_B2MC02RC1	 BUFFER[1688]	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
#define idfEM_B2MC02RC1	 514	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
#define fEM_B2MV02RC1	 BUFFER[1693]	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define idfEM_B2MV02RC1	 515	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define iEM_TERRB1	 BUFFER[1698]	//(TERRB1) Неисправности  РБ1
#define idiEM_TERRB1	 516	//(TERRB1) Неисправности  РБ1
#define fEM_A2MC02RC1	 BUFFER[1701]	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
#define idfEM_A2MC02RC1	 517	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
#define fEM_A2MV02RC1	 BUFFER[1706]	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define idfEM_A2MV02RC1	 518	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define iEM_TERIS2	 BUFFER[1711]	//(TERIS2) Неисправности  ИС2
#define idiEM_TERIS2	 519	//(TERIS2) Неисправности  ИС2
#define fEM_B3MC02RC1	 BUFFER[1714]	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
#define idfEM_B3MC02RC1	 520	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
#define fEM_B3MV02RC1	 BUFFER[1719]	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define idfEM_B3MV02RC1	 521	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define iEM_TERIS1	 BUFFER[1724]	//(TERIS1) Неисправности  ИС1
#define idiEM_TERIS1	 522	//(TERIS1) Неисправности  ИС1
#define fEM_A3MC02RC1	 BUFFER[1727]	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
#define idfEM_A3MC02RC1	 523	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
#define fEM_A3MV02RC1	 BUFFER[1732]	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define idfEM_A3MV02RC1	 524	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define iEM_TERAZ1	 BUFFER[1737]	//(TERAZ1) Неисправности АЗ1
#define idiEM_TERAZ1	 525	//(TERAZ1) Неисправности АЗ1
#define iEM_TERAZ2	 BUFFER[1740]	//(TERAZ2) Неисправности АЗ2
#define idiEM_TERAZ2	 526	//(TERAZ2) Неисправности АЗ2
#define iEM_TERA1IE04LDU	 BUFFER[1743]	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define idiEM_TERA1IE04LDU	 527	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define iEM_TERA1IE03LDU	 BUFFER[1746]	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define idiEM_TERA1IE03LDU	 528	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define fEM_A1MC01RC1	 BUFFER[1749]	//(A1MC01RC1) Заданная координата  ББ1 от ИС
#define idfEM_A1MC01RC1	 529	//(A1MC01RC1) Заданная координата  ББ1 от ИС
#define iEM_TERB1IE03LDU	 BUFFER[1754]	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define idiEM_TERB1IE03LDU	 530	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define iEM_TERB1IE04LDU	 BUFFER[1757]	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define idiEM_TERB1IE04LDU	 531	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define fEM_B1MC01RC1	 BUFFER[1760]	//(B1MC01RC1) Заданная координата ББ2 от ИС
#define idfEM_B1MC01RC1	 532	//(B1MC01RC1) Заданная координата ББ2 от ИС
#define fEM_B1MV01RC1	 BUFFER[1765]	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define idfEM_B1MV01RC1	 533	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define fEM_B2MC01RC1	 BUFFER[1770]	//(B2MC01RC1) Заданная координата РБ2 от ИС
#define idfEM_B2MC01RC1	 534	//(B2MC01RC1) Заданная координата РБ2 от ИС
#define fEM_B2MV01RC1	 BUFFER[1775]	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define idfEM_B2MV01RC1	 535	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define fEM_A3MC01RC1	 BUFFER[1780]	//(A3MC01RC1) Заданная координата ИС1 от ИС
#define idfEM_A3MC01RC1	 536	//(A3MC01RC1) Заданная координата ИС1 от ИС
#define fEM_A3MV01RC1	 BUFFER[1785]	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define idfEM_A3MV01RC1	 537	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define fEM_B3MC01RC1	 BUFFER[1790]	//(B3MC01RC1) Заданная координата ИС2 от ИС
#define idfEM_B3MC01RC1	 538	//(B3MC01RC1) Заданная координата ИС2 от ИС
#define fEM_B3MV01RC1	 BUFFER[1795]	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define idfEM_B3MV01RC1	 539	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define iEM_TERA7MS31DIM	 BUFFER[1800]	//(TERA7MS31DIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define idiEM_TERA7MS31DIM	 540	//(TERA7MS31DIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define iEM_TERA2SS21LIM	 BUFFER[1803]	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define idiEM_TERA2SS21LIM	 541	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define iEM_TERA2SS12LIM	 BUFFER[1806]	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define idiEM_TERA2SS12LIM	 542	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define iEM_TERR6SS21LIM	 BUFFER[1809]	//(TERR6SS21LIM) Искажение: Приход на НУ кран-балки
#define idiEM_TERR6SS21LIM	 543	//(TERR6SS21LIM) Искажение: Приход на НУ кран-балки
#define iEM_TERA2VP82LIM	 BUFFER[1812]	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define idiEM_TERA2VP82LIM	 544	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define iEM_TERA2SS11LIM	 BUFFER[1815]	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define idiEM_TERA2SS11LIM	 545	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define iEM_TERB3SS21LIM	 BUFFER[1818]	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define idiEM_TERB3SS21LIM	 546	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define iEM_TERA0MT01RIM	 BUFFER[1821]	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define idiEM_TERA0MT01RIM	 547	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define iEM_TERB0MT01RIM	 BUFFER[1824]	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define idiEM_TERB0MT01RIM	 548	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define iEM_TERA2SP01RIM	 BUFFER[1827]	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define idiEM_TERA2SP01RIM	 549	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define iEM_TERB2SP01RIM	 BUFFER[1830]	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define idiEM_TERB2SP01RIM	 550	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define iEM_TERB3SP02RIM	 BUFFER[1833]	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define idiEM_TERB3SP02RIM	 551	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define iEM_TERA3SC01RIM	 BUFFER[1836]	//(TERA3SC01RIM) Искажение: Координата штока ИС1
#define idiEM_TERA3SC01RIM	 552	//(TERA3SC01RIM) Искажение: Координата штока ИС1
#define iEM_TERA3VP81LIM	 BUFFER[1839]	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define idiEM_TERA3VP81LIM	 553	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define iEM_TERA2SC01RIM	 BUFFER[1842]	//(TERA2SC01RIM) Искажение: Координата штока РБ1
#define idiEM_TERA2SC01RIM	 554	//(TERA2SC01RIM) Искажение: Координата штока РБ1
#define iEM_TERA2SS33LIM	 BUFFER[1845]	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define idiEM_TERA2SS33LIM	 555	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define iEM_TERA3SS21LIM	 BUFFER[1848]	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define idiEM_TERA3SS21LIM	 556	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define iEM_TERA3SS33LIM	 BUFFER[1851]	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define idiEM_TERA3SS33LIM	 557	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define iEM_TERA3SS31LIM	 BUFFER[1854]	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define idiEM_TERA3SS31LIM	 558	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define iEM_TERB3SS31LIM	 BUFFER[1857]	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define idiEM_TERB3SS31LIM	 559	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define iEM_TERB3SS33LIM	 BUFFER[1860]	//(TERB3SS33LIM) скажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define idiEM_TERB3SS33LIM	 560	//(TERB3SS33LIM) скажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define iEM_TERB3SC01RIM	 BUFFER[1863]	//(TERB3SC01RIM) Искажение: Координата штока ИС2
#define idiEM_TERB3SC01RIM	 561	//(TERB3SC01RIM) Искажение: Координата штока ИС2
#define iEM_TERA3SS11LIM	 BUFFER[1866]	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define idiEM_TERA3SS11LIM	 562	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define iEM_TERB3SS11LIM	 BUFFER[1869]	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define idiEM_TERB3SS11LIM	 563	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define iEM_TERR6IS64LIM	 BUFFER[1872]	//(TERR6IS64LIM) Исправность ВИП ССДИ-35 1канал
#define idiEM_TERR6IS64LIM	 564	//(TERR6IS64LIM) Исправность ВИП ССДИ-35 1канал
#define iEM_TERB3SS22LIM	 BUFFER[1875]	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define idiEM_TERB3SS22LIM	 565	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define iEM_TERA3SS22LIM	 BUFFER[1878]	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define idiEM_TERA3SS22LIM	 566	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define iEM_TERA3SP02RIM	 BUFFER[1881]	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define idiEM_TERA3SP02RIM	 567	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define iEM_TERR6IS62LIM	 BUFFER[1884]	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39 1канал
#define idiEM_TERR6IS62LIM	 568	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39 1канал
#define iEM_TERR6IS66LIM	 BUFFER[1887]	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idiEM_TERR6IS66LIM	 569	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define iEM_TERR6IS67LIM	 BUFFER[1890]	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idiEM_TERR6IS67LIM	 570	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
#define iEM_TERA0VP81LIM	 BUFFER[1893]	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define idiEM_TERA0VP81LIM	 571	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define iEM_TERB0VP81LIM	 BUFFER[1896]	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define idiEM_TERB0VP81LIM	 572	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define iEM_TERR0VP81LIM	 BUFFER[1899]	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ в норме
#define idiEM_TERR0VP81LIM	 573	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ в норме
#define iEM_TERR0VP82LIM	 BUFFER[1902]	//(TERR0VP82LIM) Искажение: Давление  в СИСТЕМЕ-2 в норме
#define idiEM_TERR0VP82LIM	 574	//(TERR0VP82LIM) Искажение: Давление  в СИСТЕМЕ-2 в норме
#define iEM_TERR6IS68LIM	 BUFFER[1905]	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
#define idiEM_TERR6IS68LIM	 575	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
#define iEM_TERR7SI74RIM	 BUFFER[1908]	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define idiEM_TERR7SI74RIM	 576	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define iEM_TERA5SS21LIM	 BUFFER[1911]	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define idiEM_TERA5SS21LIM	 577	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define iEM_TERB5SS11LIM	 BUFFER[1914]	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define idiEM_TERB5SS11LIM	 578	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define iEM_TERA5SS11LIM	 BUFFER[1917]	//(TERA5SS11LIM) Искажение: Приход на ВУ НЛ1
#define idiEM_TERA5SS11LIM	 579	//(TERA5SS11LIM) Искажение: Приход на ВУ НЛ1
#define iEM_TERA9SS11LIM	 BUFFER[1920]	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define idiEM_TERA9SS11LIM	 580	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define iEM_TERB2SS11LIM	 BUFFER[1923]	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define idiEM_TERB2SS11LIM	 581	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define iEM_TERB2SS12LIM	 BUFFER[1926]	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define idiEM_TERB2SS12LIM	 582	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define iEM_TERB2SS21LIM	 BUFFER[1929]	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define idiEM_TERB2SS21LIM	 583	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define iEM_TERR3SS11LIM	 BUFFER[1932]	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define idiEM_TERR3SS11LIM	 584	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define iEM_TERB2SC01RIM	 BUFFER[1935]	//(TERB2SC01RIM) Искажение: Координата штока РБ2
#define idiEM_TERB2SC01RIM	 585	//(TERB2SC01RIM) Искажение: Координата штока РБ2
#define iEM_TERR3SS21LIM	 BUFFER[1938]	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define idiEM_TERR3SS21LIM	 586	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define iEM_TERR5SS11LIM	 BUFFER[1941]	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define idiEM_TERR5SS11LIM	 587	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define iEM_TERR3SS12LIM	 BUFFER[1944]	//(TERR3SS12LIM) Искажение: Приход на ВУ гомогенных дверей-2
#define idiEM_TERR3SS12LIM	 588	//(TERR3SS12LIM) Искажение: Приход на ВУ гомогенных дверей-2
#define iEM_TERR3SS22LIM	 BUFFER[1947]	//(TERR3SS22LIM) Искажение: Приход на НУ гомогенных дверей-2
#define idiEM_TERR3SS22LIM	 589	//(TERR3SS22LIM) Искажение: Приход на НУ гомогенных дверей-2
#define iEM_TERA4SS11LIM	 BUFFER[1950]	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define idiEM_TERA4SS11LIM	 590	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define iEM_TERR1SS11LIM	 BUFFER[1953]	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define idiEM_TERR1SS11LIM	 591	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define iEM_TERR1SS21LIM	 BUFFER[1956]	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define idiEM_TERR1SS21LIM	 592	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define iEM_TERR2SS11LIM	 BUFFER[1959]	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define idiEM_TERR2SS11LIM	 593	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define iEM_TERR2SS21LIM	 BUFFER[1962]	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define idiEM_TERR2SS21LIM	 594	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define iEM_TERA4VP82LIM	 BUFFER[1965]	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define idiEM_TERA4VP82LIM	 595	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define iEM_TERB4SS21LIM	 BUFFER[1968]	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define idiEM_TERB4SS21LIM	 596	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define iEM_TERR5SS21LIM	 BUFFER[1971]	//(TERR5SS21LIM) Искажение: Приход на НУ РБ2
#define idiEM_TERR5SS21LIM	 597	//(TERR5SS21LIM) Искажение: Приход на НУ РБ2
#define iEM_TERB6SS21LIM	 BUFFER[1974]	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define idiEM_TERB6SS21LIM	 598	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define iEM_TERB4SS11LIM	 BUFFER[1977]	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define idiEM_TERB4SS11LIM	 599	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define iEM_TERA4SS21LIM	 BUFFER[1980]	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define idiEM_TERA4SS21LIM	 600	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define iEM_TERA6MS11LIM	 BUFFER[1983]	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define idiEM_TERA6MS11LIM	 601	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define iEM_TERA6SS21LIM	 BUFFER[1986]	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define idiEM_TERA6SS21LIM	 602	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define iEM_TERB6SS11LIM	 BUFFER[1989]	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define idiEM_TERB6SS11LIM	 603	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define iEM_TERR4SS11LIM	 BUFFER[1992]	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define idiEM_TERR4SS11LIM	 604	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define iEM_TERR4MS21LIM	 BUFFER[1995]	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
#define idiEM_TERR4MS21LIM	 605	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
#define iEM_TERR4SS12LIM	 BUFFER[1998]	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define idiEM_TERR4SS12LIM	 606	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define iEM_TERR4SS22LIM	 BUFFER[2001]	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define idiEM_TERR4SS22LIM	 607	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define iEM_TERR8SS11LIM	 BUFFER[2004]	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define idiEM_TERR8SS11LIM	 608	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define iEM_TERB8SC01RIM	 BUFFER[2007]	//(TERB8SC01RIM) Искажение: Координата АЗ2
#define idiEM_TERB8SC01RIM	 609	//(TERB8SC01RIM) Искажение: Координата АЗ2
#define iEM_TERA8SC01RIM	 BUFFER[2010]	//(TERA8SC01RIM) Искажение: Координата ДС2
#define idiEM_TERA8SC01RIM	 610	//(TERA8SC01RIM) Искажение: Координата ДС2
#define iEM_TERB8SS12LIM	 BUFFER[2013]	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define idiEM_TERB8SS12LIM	 611	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define iEM_TERA8SS12LIM	 BUFFER[2016]	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define idiEM_TERA8SS12LIM	 612	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define iEM_TERB8SS22LIM	 BUFFER[2019]	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define idiEM_TERB8SS22LIM	 613	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define iEM_TERA8SS22LIM	 BUFFER[2022]	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define idiEM_TERA8SS22LIM	 614	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define iEM_TERA9SS21LIM	 BUFFER[2025]	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define idiEM_TERA9SS21LIM	 615	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define iEM_TERB9SS21LIM	 BUFFER[2028]	//(TERB9SS21LIM) Искажение: Приход на НУ РБ2
#define idiEM_TERB9SS21LIM	 616	//(TERB9SS21LIM) Искажение: Приход на НУ РБ2
#define iEM_TERB9SS11LIM	 BUFFER[2031]	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define idiEM_TERB9SS11LIM	 617	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define iEM_TERB5SS21LIM	 BUFFER[2034]	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define idiEM_TERB5SS21LIM	 618	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define iEM_TERA1SS21LIM	 BUFFER[2037]	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define idiEM_TERA1SS21LIM	 619	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define iEM_TERA1SS11LIM	 BUFFER[2040]	//(TERA1SS11LIM) Искажение: Приход на НУ РБ2
#define idiEM_TERA1SS11LIM	 620	//(TERA1SS11LIM) Искажение: Приход на НУ РБ2
#define iEM_TERA1SC01RIM	 BUFFER[2043]	//(TERA1SC01RIM) Искажение: Координата штока ББ1
#define idiEM_TERA1SC01RIM	 621	//(TERA1SC01RIM) Искажение: Координата штока ББ1
#define iEM_TERA1SS12LIM	 BUFFER[2046]	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define idiEM_TERA1SS12LIM	 622	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define iEM_TERB1SS21LIM	 BUFFER[2049]	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define idiEM_TERB1SS21LIM	 623	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define iEM_TERB1SS11LIM	 BUFFER[2052]	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define idiEM_TERB1SS11LIM	 624	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define iEM_TERB1MC01RIM	 BUFFER[2055]	//(TERB1MC01RIM) Искажение: Координата штока ББ2
#define idiEM_TERB1MC01RIM	 625	//(TERB1MC01RIM) Искажение: Координата штока ББ2
#define iEM_TERB1SS12LIM	 BUFFER[2058]	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define idiEM_TERB1SS12LIM	 626	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define iEM_TERR0IE43LIM	 BUFFER[2061]	//(TERR0IE43LIM) Исправность ВИП 0,5 (№19) КНК53М 4канала
#define idiEM_TERR0IE43LIM	 627	//(TERR0IE43LIM) Исправность ВИП 0,5 (№19) КНК53М 4канала
#define iEM_TERR0IE41LIM	 BUFFER[2064]	//(TERR0IE41LIM) Исправность ВИП 1,6 (№17) СНМ11 4канала
#define idiEM_TERR0IE41LIM	 628	//(TERR0IE41LIM) Исправность ВИП 1,6 (№17) СНМ11 4канала
#define lEM_A0EE06LC1	 BUFFER[2067]	//(A0EE06LC1) Исправность АКНП4 от диагностики контроллера (От ИС)
#define idlEM_A0EE06LC1	 629	//(A0EE06LC1) Исправность АКНП4 от диагностики контроллера (От ИС)
#define iEM_TERR0IE33LIM	 BUFFER[2069]	//(TERR0IE33LIM) Искажение:Исправность ВИП 0,5 (№16) КНК53М 3канала
#define idiEM_TERR0IE33LIM	 630	//(TERR0IE33LIM) Искажение:Исправность ВИП 0,5 (№16) КНК53М 3канала
#define iEM_TERR0IE31LIM	 BUFFER[2072]	//(TERR0IE31LIM) Искажение: Исправность ВИП 1,6 (№14) СНМ11 3канала
#define idiEM_TERR0IE31LIM	 631	//(TERR0IE31LIM) Искажение: Исправность ВИП 1,6 (№14) СНМ11 3канала
#define lEM_A0EE05LC1	 BUFFER[2075]	//(A0EE05LC1) Исправность АКНП3 от диагностики контроллера (От ИС)
#define idlEM_A0EE05LC1	 632	//(A0EE05LC1) Исправность АКНП3 от диагностики контроллера (От ИС)
#define iEM_TERR0IE11LIM	 BUFFER[2077]	//(TERR0IE11LIM) Искажение: Исправность ВИП 1,6 (№8) СНМ11 1канала
#define idiEM_TERR0IE11LIM	 633	//(TERR0IE11LIM) Искажение: Исправность ВИП 1,6 (№8) СНМ11 1канала
#define iEM_TERR0IE13LIM	 BUFFER[2080]	//(TERR0IE13LIM) Искажение: Исправность ВИП 0,5 (№10) КНК53М 1канала
#define idiEM_TERR0IE13LIM	 634	//(TERR0IE13LIM) Искажение: Исправность ВИП 0,5 (№10) КНК53М 1канала
#define lEM_A0EE03LC1	 BUFFER[2083]	//(A0EE03LC1) Исправность АКНП1 от диагностики контроллера (От ИС)
#define idlEM_A0EE03LC1	 635	//(A0EE03LC1) Исправность АКНП1 от диагностики контроллера (От ИС)
#define iEM_TERR0IE23LIM	 BUFFER[2085]	//(TERR0IE23LIM) Искажение: Исправность ВИП 0,5 (№13) КНК53М 2канала
#define idiEM_TERR0IE23LIM	 636	//(TERR0IE23LIM) Искажение: Исправность ВИП 0,5 (№13) КНК53М 2канала
#define iEM_TERR0IE21LIM	 BUFFER[2088]	//(TERR0IE21LIM) Искажение: Исправность ВИП 1,6 (№11) СНМ11 2канала
#define idiEM_TERR0IE21LIM	 637	//(TERR0IE21LIM) Искажение: Исправность ВИП 1,6 (№11) СНМ11 2канала
#define lEM_A0EE04LC1	 BUFFER[2091]	//(A0EE04LC1) Исправность АКНП2 от диагностики контроллера (От ИС)
#define idlEM_A0EE04LC1	 638	//(A0EE04LC1) Исправность АКНП2 от диагностики контроллера (От ИС)
#define iEM_TERTLG	 BUFFER[2093]	//(TERTLG) Неисправности  тележки от ИС
#define idiEM_TERTLG	 639	//(TERTLG) Неисправности  тележки от ИС
#define fEM_R4MC01RC1	 BUFFER[2096]	//(R4MC01RC1) Заданная координата тележки от ИС
#define idfEM_R4MC01RC1	 640	//(R4MC01RC1) Заданная координата тележки от ИС
#define fEM_R4MV01RC1	 BUFFER[2101]	//(R4MV01RC1) Заданная скорость тележки от ИС
#define idfEM_R4MV01RC1	 641	//(R4MV01RC1) Заданная скорость тележки от ИС
#define iEM_TERMAZ2	 BUFFER[2106]	//(TERMAZ2) Неисправности АЗ2 от ИС
#define idiEM_TERMAZ2	 642	//(TERMAZ2) Неисправности АЗ2 от ИС
#define fEM_B8MC01RC1	 BUFFER[2109]	//(B8MC01RC1) аданная координата АЗ2 от ИС
#define idfEM_B8MC01RC1	 643	//(B8MC01RC1) аданная координата АЗ2 от ИС
#define fEM_B8MV01RC1	 BUFFER[2114]	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
#define idfEM_B8MV01RC1	 644	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
#define iEM_TERDS2	 BUFFER[2119]	//(TERDS2) Неисправности ДС2 от ИС
#define idiEM_TERDS2	 645	//(TERDS2) Неисправности ДС2 от ИС
#define fEM_A8MC01RC1	 BUFFER[2122]	//(A8MC01RC1) Заданная координата ДС2 от ИС
#define idfEM_A8MC01RC1	 646	//(A8MC01RC1) Заданная координата ДС2 от ИС
#define fEM_A8MV01RC1	 BUFFER[2127]	//(A8MV01RC1) Заданная скорость ДС2 от ИС
#define idfEM_A8MV01RC1	 647	//(A8MV01RC1) Заданная скорость ДС2 от ИС
#define iEM_TERBZ1	 BUFFER[2132]	//(TERBZ1) Неисправности БЗ1
#define idiEM_TERBZ1	 648	//(TERBZ1) Неисправности БЗ1
#define fEM_A6MC01RC1	 BUFFER[2135]	//(A6MC01RC1) Заданная координата БЗ1 от ИС
#define idfEM_A6MC01RC1	 649	//(A6MC01RC1) Заданная координата БЗ1 от ИС
#define fEM_A6MV01RC1	 BUFFER[2140]	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
#define idfEM_A6MV01RC1	 650	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
#define iEM_TERBZ2	 BUFFER[2145]	//(TERBZ2) Неисправности БЗ2
#define idiEM_TERBZ2	 651	//(TERBZ2) Неисправности БЗ2
#define fEM_B6MC01RC1	 BUFFER[2148]	//(B6MC01RC1) Заданная координата БЗ2 от ИС
#define idfEM_B6MC01RC1	 652	//(B6MC01RC1) Заданная координата БЗ2 от ИС
#define fEM_B6MV01RC1	 BUFFER[2153]	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
#define idfEM_B6MV01RC1	 653	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
#define iEM_TERR3AD10LDU	 BUFFER[2158]	//(TERR3AD10LDU) Искажение: Гомогенные двери-1 открыть
#define idiEM_TERR3AD10LDU	 654	//(TERR3AD10LDU) Искажение: Гомогенные двери-1 открыть
#define iEM_TERR3AD20LDU	 BUFFER[2161]	//(TERR3AD20LDU) Искажение: Гомогенные двери-1 закрыть
#define idiEM_TERR3AD20LDU	 655	//(TERR3AD20LDU) Искажение: Гомогенные двери-1 закрыть
#define iEM_TERR3AD11LDU	 BUFFER[2164]	//(TERR3AD11LDU) Искажение: Гомогенные двери-2 открыть
#define idiEM_TERR3AD11LDU	 656	//(TERR3AD11LDU) Искажение: Гомогенные двери-2 открыть
#define iEM_TERR3AD21LDU	 BUFFER[2167]	//(TERR3AD21LDU) Искажение: Гомогенные двери-2 закрыть
#define idiEM_TERR3AD21LDU	 657	//(TERR3AD21LDU) Искажение: Гомогенные двери-2 закрыть
#define iEM_TERR5AD10LDU	 BUFFER[2170]	//(TERR5AD10LDU) Искажение: Открыть ворота отстойной зоны
#define idiEM_TERR5AD10LDU	 658	//(TERR5AD10LDU) Искажение: Открыть ворота отстойной зоны
#define iEM_TERR5AD20LDU	 BUFFER[2173]	//(TERR5AD20LDU) Искажение: Закрыть ворота отстойной зоны
#define idiEM_TERR5AD20LDU	 659	//(TERR5AD20LDU) Искажение: Закрыть ворота отстойной зоны
#define lEM_R3AD10LC1	 BUFFER[2176]	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define idlEM_R3AD10LC1	 660	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define lEM_R3AD20LC1	 BUFFER[2178]	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define idlEM_R3AD20LC1	 661	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define lEM_R3AD11LC1	 BUFFER[2180]	//(R3AD11LC1) Гомогенные двери-2 открыть от ИС
#define idlEM_R3AD11LC1	 662	//(R3AD11LC1) Гомогенные двери-2 открыть от ИС
#define lEM_R3AD21LC1	 BUFFER[2182]	//(R3AD21LC1) Гомогенные двери-2 закрыть от ИС
#define idlEM_R3AD21LC1	 663	//(R3AD21LC1) Гомогенные двери-2 закрыть от ИС
#define lEM_R6AD10LC1	 BUFFER[2184]	//(R6AD10LC1) Выкатить кран-балку от ИС
#define idlEM_R6AD10LC1	 664	//(R6AD10LC1) Выкатить кран-балку от ИС
#define lEM_R5AD10LC1	 BUFFER[2186]	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define idlEM_R5AD10LC1	 665	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define lEM_R5AD20LC1	 BUFFER[2188]	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define idlEM_R5AD20LC1	 666	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define iEM_TERMDZ2	 BUFFER[2190]	//(TERMDZ2) Неисправности МДЗ2
#define idiEM_TERMDZ2	 667	//(TERMDZ2) Неисправности МДЗ2
#define fEM_R2MC01RC1	 BUFFER[2193]	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
#define idfEM_R2MC01RC1	 668	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
#define fEM_R2MV01RC1	 BUFFER[2198]	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define idfEM_R2MV01RC1	 669	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define iEM_TERMDZ1	 BUFFER[2203]	//(TERMDZ1) Неисправности МДЗ1
#define idiEM_TERMDZ1	 670	//(TERMDZ1) Неисправности МДЗ1
#define fEM_R1MC01RC1	 BUFFER[2206]	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
#define idfEM_R1MC01RC1	 671	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
#define fEM_R1MV01RC1	 BUFFER[2211]	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define idfEM_R1MV01RC1	 672	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define iEM_TERNL1	 BUFFER[2216]	//(TERNL1) Неисправности НЛ1
#define idiEM_TERNL1	 673	//(TERNL1) Неисправности НЛ1
#define fEM_A5MC01RC1	 BUFFER[2219]	//(A5MC01RC1) Заданная координата НЛ1 от ИС
#define idfEM_A5MC01RC1	 674	//(A5MC01RC1) Заданная координата НЛ1 от ИС
#define fEM_A5MV01RC1	 BUFFER[2224]	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
#define idfEM_A5MV01RC1	 675	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
#define iEM_TERNL2	 BUFFER[2229]	//(TERNL2) Неисправности НЛ2
#define idiEM_TERNL2	 676	//(TERNL2) Неисправности НЛ2
#define fEM_B5MC01RC1	 BUFFER[2232]	//(B5MC01RC1) Заданная координата НЛ2 от ИС
#define idfEM_B5MC01RC1	 677	//(B5MC01RC1) Заданная координата НЛ2 от ИС
#define fEM_B5MV01RC1	 BUFFER[2237]	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
#define idfEM_B5MV01RC1	 678	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
#define lEM_R8AD10LC1	 BUFFER[2242]	//(R8AD10LC1) Установить аварийный НИ от ИС
#define idlEM_R8AD10LC1	 679	//(R8AD10LC1) Установить аварийный НИ от ИС
#define fEM_A1UC08RIM	 BUFFER[2244]	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define idfEM_A1UC08RIM	 680	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define fEM_A2UC08RIM	 BUFFER[2249]	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
#define idfEM_A2UC08RIM	 681	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
#define fEM_A3UC08RIM	 BUFFER[2254]	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define idfEM_A3UC08RIM	 682	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define fEM_R0UL01RSS	 BUFFER[2259]	//(R0UL01RSS) Шаг (мс) измерения периода
#define idfEM_R0UL01RSS	 683	//(R0UL01RSS) Шаг (мс) измерения периода
#define fEM_R0UL03RSS	 BUFFER[2264]	//(R0UL03RSS) Предельное время ожидания роста потока (сек)
#define idfEM_R0UL03RSS	 684	//(R0UL03RSS) Предельное время ожидания роста потока (сек)
#define iEM_TERB2SS33LIM	 BUFFER[2269]	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define idiEM_TERB2SS33LIM	 685	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define iEM_TERA1VP81LIM	 BUFFER[2272]	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define idiEM_TERA1VP81LIM	 686	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define iEM_TERB1VP81LIM	 BUFFER[2275]	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define idiEM_TERB1VP81LIM	 687	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define bFirstEnterFlag	 BUFFER[2278]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 688	//(bFirstEnterFlag) 
#define internal1_m515_Out10	 BUFFER[2280]	//(internal1_m515_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m515_Out10	 689	//(internal1_m515_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m533_Out10	 BUFFER[2282]	//(internal1_m533_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m533_Out10	 690	//(internal1_m533_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m383_Out10	 BUFFER[2284]	//(internal1_m383_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m383_Out10	 691	//(internal1_m383_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m472_q0	 BUFFER[2286]	//(internal1_m472_q0) q0 - внутренний параметр
#define idinternal1_m472_q0	 692	//(internal1_m472_q0) q0 - внутренний параметр
#define internal1_m473_q0	 BUFFER[2288]	//(internal1_m473_q0) q0 - внутренний параметр
#define idinternal1_m473_q0	 693	//(internal1_m473_q0) q0 - внутренний параметр
#define internal1_m446_q0	 BUFFER[2290]	//(internal1_m446_q0) q0 - внутренний параметр
#define idinternal1_m446_q0	 694	//(internal1_m446_q0) q0 - внутренний параметр
#define internal1_m447_q0	 BUFFER[2292]	//(internal1_m447_q0) q0 - внутренний параметр
#define idinternal1_m447_q0	 695	//(internal1_m447_q0) q0 - внутренний параметр
#define internal1_m448_q0	 BUFFER[2294]	//(internal1_m448_q0) q0 - внутренний параметр
#define idinternal1_m448_q0	 696	//(internal1_m448_q0) q0 - внутренний параметр
#define internal1_m449_q0	 BUFFER[2296]	//(internal1_m449_q0) q0 - внутренний параметр
#define idinternal1_m449_q0	 697	//(internal1_m449_q0) q0 - внутренний параметр
#define internal1_m629_tx	 BUFFER[2298]	//(internal1_m629_tx) tx - время накопленное сек
#define idinternal1_m629_tx	 698	//(internal1_m629_tx) tx - время накопленное сек
#define internal1_m629_y0	 BUFFER[2303]	//(internal1_m629_y0) y0
#define idinternal1_m629_y0	 699	//(internal1_m629_y0) y0
#define internal1_m617_tx	 BUFFER[2304]	//(internal1_m617_tx) tx - время накопленное сек
#define idinternal1_m617_tx	 700	//(internal1_m617_tx) tx - время накопленное сек
#define internal1_m617_y0	 BUFFER[2309]	//(internal1_m617_y0) y0
#define idinternal1_m617_y0	 701	//(internal1_m617_y0) y0
#define internal1_m475_Out10	 BUFFER[2310]	//(internal1_m475_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m475_Out10	 702	//(internal1_m475_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m453_Out10	 BUFFER[2312]	//(internal1_m453_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m453_Out10	 703	//(internal1_m453_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m452_Out10	 BUFFER[2314]	//(internal1_m452_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m452_Out10	 704	//(internal1_m452_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m451_Out10	 BUFFER[2316]	//(internal1_m451_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m451_Out10	 705	//(internal1_m451_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m450_Out10	 BUFFER[2318]	//(internal1_m450_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m450_Out10	 706	//(internal1_m450_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m474_Out10	 BUFFER[2320]	//(internal1_m474_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m474_Out10	 707	//(internal1_m474_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m607_tx	 BUFFER[2322]	//(internal1_m607_tx) tx - время накопленное сек
#define idinternal1_m607_tx	 708	//(internal1_m607_tx) tx - время накопленное сек
#define internal1_m607_y0	 BUFFER[2327]	//(internal1_m607_y0) y0
#define idinternal1_m607_y0	 709	//(internal1_m607_y0) y0
#define internal1_m605_tx	 BUFFER[2328]	//(internal1_m605_tx) tx - время накопленное сек
#define idinternal1_m605_tx	 710	//(internal1_m605_tx) tx - время накопленное сек
#define internal1_m605_y0	 BUFFER[2333]	//(internal1_m605_y0) y0
#define idinternal1_m605_y0	 711	//(internal1_m605_y0) y0
#define internal1_m190_Out10	 BUFFER[2334]	//(internal1_m190_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m190_Out10	 712	//(internal1_m190_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m207_Out10	 BUFFER[2336]	//(internal1_m207_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m207_Out10	 713	//(internal1_m207_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m39_Out10	 BUFFER[2338]	//(internal1_m39_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m39_Out10	 714	//(internal1_m39_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m54_Out10	 BUFFER[2340]	//(internal1_m54_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m54_Out10	 715	//(internal1_m54_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1196_Out10	 BUFFER[2342]	//(internal1_m1196_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1196_Out10	 716	//(internal1_m1196_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1193_Out10	 BUFFER[2344]	//(internal1_m1193_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1193_Out10	 717	//(internal1_m1193_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1192_Out10	 BUFFER[2346]	//(internal1_m1192_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1192_Out10	 718	//(internal1_m1192_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1195_Xtek0	 BUFFER[2348]	//(internal1_m1195_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m1195_Xtek0	 719	//(internal1_m1195_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m1181_Xtek0	 BUFFER[2353]	//(internal1_m1181_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m1181_Xtek0	 720	//(internal1_m1181_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m1182_Out10	 BUFFER[2358]	//(internal1_m1182_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1182_Out10	 721	//(internal1_m1182_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1179_Out10	 BUFFER[2360]	//(internal1_m1179_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1179_Out10	 722	//(internal1_m1179_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1178_Out10	 BUFFER[2362]	//(internal1_m1178_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1178_Out10	 723	//(internal1_m1178_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m905_Out10	 BUFFER[2364]	//(internal1_m905_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m905_Out10	 724	//(internal1_m905_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m926_Out10	 BUFFER[2366]	//(internal1_m926_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m926_Out10	 725	//(internal1_m926_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m925_Out10	 BUFFER[2368]	//(internal1_m925_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m925_Out10	 726	//(internal1_m925_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m924_Out10	 BUFFER[2370]	//(internal1_m924_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m924_Out10	 727	//(internal1_m924_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1090_Out10	 BUFFER[2372]	//(internal1_m1090_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1090_Out10	 728	//(internal1_m1090_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1092_Out10	 BUFFER[2374]	//(internal1_m1092_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1092_Out10	 729	//(internal1_m1092_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1089_Out10	 BUFFER[2376]	//(internal1_m1089_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1089_Out10	 730	//(internal1_m1089_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1091_Out10	 BUFFER[2378]	//(internal1_m1091_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1091_Out10	 731	//(internal1_m1091_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1069_Out10	 BUFFER[2380]	//(internal1_m1069_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1069_Out10	 732	//(internal1_m1069_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1070_Out10	 BUFFER[2382]	//(internal1_m1070_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1070_Out10	 733	//(internal1_m1070_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1068_Out10	 BUFFER[2384]	//(internal1_m1068_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1068_Out10	 734	//(internal1_m1068_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1067_Out10	 BUFFER[2386]	//(internal1_m1067_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1067_Out10	 735	//(internal1_m1067_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m902_Out10	 BUFFER[2388]	//(internal1_m902_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m902_Out10	 736	//(internal1_m902_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m901_Out10	 BUFFER[2390]	//(internal1_m901_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m901_Out10	 737	//(internal1_m901_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m881_Out10	 BUFFER[2392]	//(internal1_m881_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m881_Out10	 738	//(internal1_m881_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m885_Out10	 BUFFER[2394]	//(internal1_m885_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m885_Out10	 739	//(internal1_m885_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m884_Out10	 BUFFER[2396]	//(internal1_m884_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m884_Out10	 740	//(internal1_m884_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m883_Out10	 BUFFER[2398]	//(internal1_m883_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m883_Out10	 741	//(internal1_m883_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m882_Out10	 BUFFER[2400]	//(internal1_m882_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m882_Out10	 742	//(internal1_m882_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m903_Out10	 BUFFER[2402]	//(internal1_m903_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m903_Out10	 743	//(internal1_m903_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m922_Out10	 BUFFER[2404]	//(internal1_m922_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m922_Out10	 744	//(internal1_m922_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1071_Out10	 BUFFER[2406]	//(internal1_m1071_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1071_Out10	 745	//(internal1_m1071_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m923_Out10	 BUFFER[2408]	//(internal1_m923_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m923_Out10	 746	//(internal1_m923_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m921_Out10	 BUFFER[2410]	//(internal1_m921_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m921_Out10	 747	//(internal1_m921_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m904_Out10	 BUFFER[2412]	//(internal1_m904_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m904_Out10	 748	//(internal1_m904_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m920_Out10	 BUFFER[2414]	//(internal1_m920_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m920_Out10	 749	//(internal1_m920_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m900_Out10	 BUFFER[2416]	//(internal1_m900_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m900_Out10	 750	//(internal1_m900_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m880_Out10	 BUFFER[2418]	//(internal1_m880_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m880_Out10	 751	//(internal1_m880_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m532_Out10	 BUFFER[2420]	//(internal1_m532_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m532_Out10	 752	//(internal1_m532_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m393_Xtek0	 BUFFER[2422]	//(internal1_m393_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m393_Xtek0	 753	//(internal1_m393_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m384_Out10	 BUFFER[2427]	//(internal1_m384_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m384_Out10	 754	//(internal1_m384_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m386_Out10	 BUFFER[2429]	//(internal1_m386_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m386_Out10	 755	//(internal1_m386_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m385_Out10	 BUFFER[2431]	//(internal1_m385_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m385_Out10	 756	//(internal1_m385_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1104_Out10	 BUFFER[2433]	//(internal1_m1104_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1104_Out10	 757	//(internal1_m1104_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1105_Out10	 BUFFER[2435]	//(internal1_m1105_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1105_Out10	 758	//(internal1_m1105_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1103_Out10	 BUFFER[2437]	//(internal1_m1103_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1103_Out10	 759	//(internal1_m1103_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m941_Out10	 BUFFER[2439]	//(internal1_m941_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m941_Out10	 760	//(internal1_m941_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1106_Out10	 BUFFER[2441]	//(internal1_m1106_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1106_Out10	 761	//(internal1_m1106_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m939_Out10	 BUFFER[2443]	//(internal1_m939_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m939_Out10	 762	//(internal1_m939_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m938_Out10	 BUFFER[2445]	//(internal1_m938_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m938_Out10	 763	//(internal1_m938_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m940_Out10	 BUFFER[2447]	//(internal1_m940_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m940_Out10	 764	//(internal1_m940_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m555_Out10	 BUFFER[2449]	//(internal1_m555_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m555_Out10	 765	//(internal1_m555_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m553_Out10	 BUFFER[2451]	//(internal1_m553_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m553_Out10	 766	//(internal1_m553_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m552_Out10	 BUFFER[2453]	//(internal1_m552_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m552_Out10	 767	//(internal1_m552_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m554_Out10	 BUFFER[2455]	//(internal1_m554_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m554_Out10	 768	//(internal1_m554_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1086_Xtek0	 BUFFER[2457]	//(internal1_m1086_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m1086_Xtek0	 769	//(internal1_m1086_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m1088_Xtek0	 BUFFER[2462]	//(internal1_m1088_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m1088_Xtek0	 770	//(internal1_m1088_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m662_Out10	 BUFFER[2467]	//(internal1_m662_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m662_Out10	 771	//(internal1_m662_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m657_Out10	 BUFFER[2469]	//(internal1_m657_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m657_Out10	 772	//(internal1_m657_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m648_Out10	 BUFFER[2471]	//(internal1_m648_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m648_Out10	 773	//(internal1_m648_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m656_Out10	 BUFFER[2473]	//(internal1_m656_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m656_Out10	 774	//(internal1_m656_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m647_Out10	 BUFFER[2475]	//(internal1_m647_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m647_Out10	 775	//(internal1_m647_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m315_Out10	 BUFFER[2477]	//(internal1_m315_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m315_Out10	 776	//(internal1_m315_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m314_Out10	 BUFFER[2479]	//(internal1_m314_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m314_Out10	 777	//(internal1_m314_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m295_Out10	 BUFFER[2481]	//(internal1_m295_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m295_Out10	 778	//(internal1_m295_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m294_Out10	 BUFFER[2483]	//(internal1_m294_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m294_Out10	 779	//(internal1_m294_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m556_Out10	 BUFFER[2485]	//(internal1_m556_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m556_Out10	 780	//(internal1_m556_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m330_Out10	 BUFFER[2487]	//(internal1_m330_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m330_Out10	 781	//(internal1_m330_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m312_Xtek0	 BUFFER[2489]	//(internal1_m312_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m312_Xtek0	 782	//(internal1_m312_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m329_Out10	 BUFFER[2494]	//(internal1_m329_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m329_Out10	 783	//(internal1_m329_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m327_Out10	 BUFFER[2496]	//(internal1_m327_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m327_Out10	 784	//(internal1_m327_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m303_Xtek0	 BUFFER[2498]	//(internal1_m303_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m303_Xtek0	 785	//(internal1_m303_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m328_Out10	 BUFFER[2503]	//(internal1_m328_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m328_Out10	 786	//(internal1_m328_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m293_Out10	 BUFFER[2505]	//(internal1_m293_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m293_Out10	 787	//(internal1_m293_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m313_Out10	 BUFFER[2507]	//(internal1_m313_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m313_Out10	 788	//(internal1_m313_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m405_Out10	 BUFFER[2509]	//(internal1_m405_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m405_Out10	 789	//(internal1_m405_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m406_Xtek0	 BUFFER[2511]	//(internal1_m406_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m406_Xtek0	 790	//(internal1_m406_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m404_Out10	 BUFFER[2516]	//(internal1_m404_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m404_Out10	 791	//(internal1_m404_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m403_Out10	 BUFFER[2518]	//(internal1_m403_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m403_Out10	 792	//(internal1_m403_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m402_Out10	 BUFFER[2520]	//(internal1_m402_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m402_Out10	 793	//(internal1_m402_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m886_Out10	 BUFFER[2522]	//(internal1_m886_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m886_Out10	 794	//(internal1_m886_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m136_Out10	 BUFFER[2524]	//(internal1_m136_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m136_Out10	 795	//(internal1_m136_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m135_Out10	 BUFFER[2526]	//(internal1_m135_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m135_Out10	 796	//(internal1_m135_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1060_Out10	 BUFFER[2528]	//(internal1_m1060_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1060_Out10	 797	//(internal1_m1060_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1050_Out10	 BUFFER[2530]	//(internal1_m1050_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1050_Out10	 798	//(internal1_m1050_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1039_tst	 BUFFER[2532]	//(internal1_m1039_tst) - массив времени фиксации стартовой мощности
#define idinternal1_m1039_tst	 799	//(internal1_m1039_tst) - массив времени фиксации стартовой мощности
#define internal1_m1039_trz	 BUFFER[2542]	//(internal1_m1039_trz) - массив времени фиксации очередного периода
#define idinternal1_m1039_trz	 800	//(internal1_m1039_trz) - массив времени фиксации очередного периода
#define internal1_m1039_N1	 BUFFER[2552]	//(internal1_m1039_N1) - массив значения мощности в начале замера
#define idinternal1_m1039_N1	 801	//(internal1_m1039_N1) - массив значения мощности в начале замера
#define internal1_m1039_N2	 BUFFER[2562]	//(internal1_m1039_N2) - массив значения мощности в конце замера
#define idinternal1_m1039_N2	 802	//(internal1_m1039_N2) - массив значения мощности в конце замера
#define internal1_m1039_Period0	 BUFFER[2572]	//(internal1_m1039_Period0) Per - Период разгона РУ
#define idinternal1_m1039_Period0	 803	//(internal1_m1039_Period0) Per - Период разгона РУ
#define internal1_m1039_MyFirstEnterFlag	 BUFFER[2577]	//(internal1_m1039_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m1039_MyFirstEnterFlag	 804	//(internal1_m1039_MyFirstEnterFlag)  FirstEnterFlag
#define internal1_m1005_Nk	 BUFFER[2579]	//(internal1_m1005_Nk) Nk - ведущая камера
#define idinternal1_m1005_Nk	 805	//(internal1_m1005_Nk) Nk - ведущая камера
#define internal1_m1000_Out10	 BUFFER[2582]	//(internal1_m1000_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1000_Out10	 806	//(internal1_m1000_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m992_Out10	 BUFFER[2584]	//(internal1_m992_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m992_Out10	 807	//(internal1_m992_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m981_tst	 BUFFER[2586]	//(internal1_m981_tst) - массив времени фиксации стартовой мощности
#define idinternal1_m981_tst	 808	//(internal1_m981_tst) - массив времени фиксации стартовой мощности
#define internal1_m981_trz	 BUFFER[2596]	//(internal1_m981_trz) - массив времени фиксации очередного периода
#define idinternal1_m981_trz	 809	//(internal1_m981_trz) - массив времени фиксации очередного периода
#define internal1_m981_N1	 BUFFER[2606]	//(internal1_m981_N1) - массив значения мощности в начале замера
#define idinternal1_m981_N1	 810	//(internal1_m981_N1) - массив значения мощности в начале замера
#define internal1_m981_N2	 BUFFER[2616]	//(internal1_m981_N2) - массив значения мощности в конце замера
#define idinternal1_m981_N2	 811	//(internal1_m981_N2) - массив значения мощности в конце замера
#define internal1_m981_Period0	 BUFFER[2626]	//(internal1_m981_Period0) Per - Период разгона РУ
#define idinternal1_m981_Period0	 812	//(internal1_m981_Period0) Per - Период разгона РУ
#define internal1_m981_MyFirstEnterFlag	 BUFFER[2631]	//(internal1_m981_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m981_MyFirstEnterFlag	 813	//(internal1_m981_MyFirstEnterFlag)  FirstEnterFlag
#define internal1_m951_Nk	 BUFFER[2633]	//(internal1_m951_Nk) Nk - ведущая камера
#define idinternal1_m951_Nk	 814	//(internal1_m951_Nk) Nk - ведущая камера
#define internal1_m869_Out10	 BUFFER[2636]	//(internal1_m869_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m869_Out10	 815	//(internal1_m869_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m859_Out10	 BUFFER[2638]	//(internal1_m859_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m859_Out10	 816	//(internal1_m859_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m850_tst	 BUFFER[2640]	//(internal1_m850_tst) - массив времени фиксации стартовой мощности
#define idinternal1_m850_tst	 817	//(internal1_m850_tst) - массив времени фиксации стартовой мощности
#define internal1_m850_trz	 BUFFER[2650]	//(internal1_m850_trz) - массив времени фиксации очередного периода
#define idinternal1_m850_trz	 818	//(internal1_m850_trz) - массив времени фиксации очередного периода
#define internal1_m850_N1	 BUFFER[2660]	//(internal1_m850_N1) - массив значения мощности в начале замера
#define idinternal1_m850_N1	 819	//(internal1_m850_N1) - массив значения мощности в начале замера
#define internal1_m850_N2	 BUFFER[2670]	//(internal1_m850_N2) - массив значения мощности в конце замера
#define idinternal1_m850_N2	 820	//(internal1_m850_N2) - массив значения мощности в конце замера
#define internal1_m850_Period0	 BUFFER[2680]	//(internal1_m850_Period0) Per - Период разгона РУ
#define idinternal1_m850_Period0	 821	//(internal1_m850_Period0) Per - Период разгона РУ
#define internal1_m850_MyFirstEnterFlag	 BUFFER[2685]	//(internal1_m850_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m850_MyFirstEnterFlag	 822	//(internal1_m850_MyFirstEnterFlag)  FirstEnterFlag
#define internal1_m816_Nk	 BUFFER[2687]	//(internal1_m816_Nk) Nk - ведущая камера
#define idinternal1_m816_Nk	 823	//(internal1_m816_Nk) Nk - ведущая камера
#define internal1_m803_Out10	 BUFFER[2690]	//(internal1_m803_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m803_Out10	 824	//(internal1_m803_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m792_Out10	 BUFFER[2692]	//(internal1_m792_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m792_Out10	 825	//(internal1_m792_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m795_tst	 BUFFER[2694]	//(internal1_m795_tst) - массив времени фиксации стартовой мощности
#define idinternal1_m795_tst	 826	//(internal1_m795_tst) - массив времени фиксации стартовой мощности
#define internal1_m795_trz	 BUFFER[2704]	//(internal1_m795_trz) - массив времени фиксации очередного периода
#define idinternal1_m795_trz	 827	//(internal1_m795_trz) - массив времени фиксации очередного периода
#define internal1_m795_N1	 BUFFER[2714]	//(internal1_m795_N1) - массив значения мощности в начале замера
#define idinternal1_m795_N1	 828	//(internal1_m795_N1) - массив значения мощности в начале замера
#define internal1_m795_N2	 BUFFER[2724]	//(internal1_m795_N2) - массив значения мощности в конце замера
#define idinternal1_m795_N2	 829	//(internal1_m795_N2) - массив значения мощности в конце замера
#define internal1_m795_Period0	 BUFFER[2734]	//(internal1_m795_Period0) Per - Период разгона РУ
#define idinternal1_m795_Period0	 830	//(internal1_m795_Period0) Per - Период разгона РУ
#define internal1_m795_MyFirstEnterFlag	 BUFFER[2739]	//(internal1_m795_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m795_MyFirstEnterFlag	 831	//(internal1_m795_MyFirstEnterFlag)  FirstEnterFlag
#define internal1_m758_Nk	 BUFFER[2741]	//(internal1_m758_Nk) Nk - ведущая камера
#define idinternal1_m758_Nk	 832	//(internal1_m758_Nk) Nk - ведущая камера
#define internal1_m179_tx	 BUFFER[2744]	//(internal1_m179_tx) tx - внутренний параметр
#define idinternal1_m179_tx	 833	//(internal1_m179_tx) tx - внутренний параметр
#define internal1_m24_tx	 BUFFER[2747]	//(internal1_m24_tx) tx - внутренний параметр
#define idinternal1_m24_tx	 834	//(internal1_m24_tx) tx - внутренний параметр
#define internal1_m461_X0	 BUFFER[2750]	//(internal1_m461_X0)  - координата механизма
#define idinternal1_m461_X0	 835	//(internal1_m461_X0)  - координата механизма
#define internal1_m461_V0	 BUFFER[2755]	//(internal1_m461_V0)  - скорость механизма
#define idinternal1_m461_V0	 836	//(internal1_m461_V0)  - скорость механизма
#define internal1_m461_Pav0	 BUFFER[2760]	//(internal1_m461_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m461_Pav0	 837	//(internal1_m461_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m461_Zav0	 BUFFER[2762]	//(internal1_m461_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m461_Zav0	 838	//(internal1_m461_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m461_Pv0	 BUFFER[2764]	//(internal1_m461_Pv0)  - Пер. выключатель механизма
#define idinternal1_m461_Pv0	 839	//(internal1_m461_Pv0)  - Пер. выключатель механизма
#define internal1_m461_Zv0	 BUFFER[2766]	//(internal1_m461_Zv0)  - Зад. выключатель механизма
#define idinternal1_m461_Zv0	 840	//(internal1_m461_Zv0)  - Зад. выключатель механизма
#define internal1_m461_RA00	 BUFFER[2768]	//(internal1_m461_RA00)  - последнее задание вперед
#define idinternal1_m461_RA00	 841	//(internal1_m461_RA00)  - последнее задание вперед
#define internal1_m461_RA10	 BUFFER[2770]	//(internal1_m461_RA10)  - последнее задание назад
#define idinternal1_m461_RA10	 842	//(internal1_m461_RA10)  - последнее задание назад
#define internal1_m461_MyFirstEnterFlag	 BUFFER[2772]	//(internal1_m461_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m461_MyFirstEnterFlag	 843	//(internal1_m461_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m482_X0	 BUFFER[2774]	//(internal1_m482_X0)  - координата механизма
#define idinternal1_m482_X0	 844	//(internal1_m482_X0)  - координата механизма
#define internal1_m482_V0	 BUFFER[2779]	//(internal1_m482_V0)  - скорость механизма
#define idinternal1_m482_V0	 845	//(internal1_m482_V0)  - скорость механизма
#define internal1_m482_Pav0	 BUFFER[2784]	//(internal1_m482_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m482_Pav0	 846	//(internal1_m482_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m482_Zav0	 BUFFER[2786]	//(internal1_m482_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m482_Zav0	 847	//(internal1_m482_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m482_Pv0	 BUFFER[2788]	//(internal1_m482_Pv0)  - Пер. выключатель механизма
#define idinternal1_m482_Pv0	 848	//(internal1_m482_Pv0)  - Пер. выключатель механизма
#define internal1_m482_Zv0	 BUFFER[2790]	//(internal1_m482_Zv0)  - Зад. выключатель механизма
#define idinternal1_m482_Zv0	 849	//(internal1_m482_Zv0)  - Зад. выключатель механизма
#define internal1_m482_RA00	 BUFFER[2792]	//(internal1_m482_RA00)  - последнее задание вперед
#define idinternal1_m482_RA00	 850	//(internal1_m482_RA00)  - последнее задание вперед
#define internal1_m482_RA10	 BUFFER[2794]	//(internal1_m482_RA10)  - последнее задание назад
#define idinternal1_m482_RA10	 851	//(internal1_m482_RA10)  - последнее задание назад
#define internal1_m482_MyFirstEnterFlag	 BUFFER[2796]	//(internal1_m482_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m482_MyFirstEnterFlag	 852	//(internal1_m482_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m480_X0	 BUFFER[2798]	//(internal1_m480_X0)  - координата механизма
#define idinternal1_m480_X0	 853	//(internal1_m480_X0)  - координата механизма
#define internal1_m480_V0	 BUFFER[2803]	//(internal1_m480_V0)  - скорость механизма
#define idinternal1_m480_V0	 854	//(internal1_m480_V0)  - скорость механизма
#define internal1_m480_Pav0	 BUFFER[2808]	//(internal1_m480_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m480_Pav0	 855	//(internal1_m480_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m480_Zav0	 BUFFER[2810]	//(internal1_m480_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m480_Zav0	 856	//(internal1_m480_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m480_Pv0	 BUFFER[2812]	//(internal1_m480_Pv0)  - Пер. выключатель механизма
#define idinternal1_m480_Pv0	 857	//(internal1_m480_Pv0)  - Пер. выключатель механизма
#define internal1_m480_Zv0	 BUFFER[2814]	//(internal1_m480_Zv0)  - Зад. выключатель механизма
#define idinternal1_m480_Zv0	 858	//(internal1_m480_Zv0)  - Зад. выключатель механизма
#define internal1_m480_RA00	 BUFFER[2816]	//(internal1_m480_RA00)  - последнее задание вперед
#define idinternal1_m480_RA00	 859	//(internal1_m480_RA00)  - последнее задание вперед
#define internal1_m480_RA10	 BUFFER[2818]	//(internal1_m480_RA10)  - последнее задание назад
#define idinternal1_m480_RA10	 860	//(internal1_m480_RA10)  - последнее задание назад
#define internal1_m480_MyFirstEnterFlag	 BUFFER[2820]	//(internal1_m480_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m480_MyFirstEnterFlag	 861	//(internal1_m480_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m456_X0	 BUFFER[2822]	//(internal1_m456_X0)  - координата механизма
#define idinternal1_m456_X0	 862	//(internal1_m456_X0)  - координата механизма
#define internal1_m456_V0	 BUFFER[2827]	//(internal1_m456_V0)  - скорость механизма
#define idinternal1_m456_V0	 863	//(internal1_m456_V0)  - скорость механизма
#define internal1_m456_Pav0	 BUFFER[2832]	//(internal1_m456_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m456_Pav0	 864	//(internal1_m456_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m456_Zav0	 BUFFER[2834]	//(internal1_m456_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m456_Zav0	 865	//(internal1_m456_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m456_Pv0	 BUFFER[2836]	//(internal1_m456_Pv0)  - Пер. выключатель механизма
#define idinternal1_m456_Pv0	 866	//(internal1_m456_Pv0)  - Пер. выключатель механизма
#define internal1_m456_Zv0	 BUFFER[2838]	//(internal1_m456_Zv0)  - Зад. выключатель механизма
#define idinternal1_m456_Zv0	 867	//(internal1_m456_Zv0)  - Зад. выключатель механизма
#define internal1_m456_RA00	 BUFFER[2840]	//(internal1_m456_RA00)  - последнее задание вперед
#define idinternal1_m456_RA00	 868	//(internal1_m456_RA00)  - последнее задание вперед
#define internal1_m456_RA10	 BUFFER[2842]	//(internal1_m456_RA10)  - последнее задание назад
#define idinternal1_m456_RA10	 869	//(internal1_m456_RA10)  - последнее задание назад
#define internal1_m456_MyFirstEnterFlag	 BUFFER[2844]	//(internal1_m456_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m456_MyFirstEnterFlag	 870	//(internal1_m456_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m609_X0	 BUFFER[2846]	//(internal1_m609_X0)  - координата механизма
#define idinternal1_m609_X0	 871	//(internal1_m609_X0)  - координата механизма
#define internal1_m609_V0	 BUFFER[2851]	//(internal1_m609_V0)  - скорость механизма
#define idinternal1_m609_V0	 872	//(internal1_m609_V0)  - скорость механизма
#define internal1_m609_Pav0	 BUFFER[2856]	//(internal1_m609_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m609_Pav0	 873	//(internal1_m609_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m609_Zav0	 BUFFER[2858]	//(internal1_m609_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m609_Zav0	 874	//(internal1_m609_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m609_Pv0	 BUFFER[2860]	//(internal1_m609_Pv0)  - Пер. выключатель механизма
#define idinternal1_m609_Pv0	 875	//(internal1_m609_Pv0)  - Пер. выключатель механизма
#define internal1_m609_Zv0	 BUFFER[2862]	//(internal1_m609_Zv0)  - Зад. выключатель механизма
#define idinternal1_m609_Zv0	 876	//(internal1_m609_Zv0)  - Зад. выключатель механизма
#define internal1_m609_RA00	 BUFFER[2864]	//(internal1_m609_RA00)  - последнее задание вперед
#define idinternal1_m609_RA00	 877	//(internal1_m609_RA00)  - последнее задание вперед
#define internal1_m609_RA10	 BUFFER[2866]	//(internal1_m609_RA10)  - последнее задание назад
#define idinternal1_m609_RA10	 878	//(internal1_m609_RA10)  - последнее задание назад
#define internal1_m609_MyFirstEnterFlag	 BUFFER[2868]	//(internal1_m609_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m609_MyFirstEnterFlag	 879	//(internal1_m609_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m608_X0	 BUFFER[2870]	//(internal1_m608_X0)  - координата механизма
#define idinternal1_m608_X0	 880	//(internal1_m608_X0)  - координата механизма
#define internal1_m608_V0	 BUFFER[2875]	//(internal1_m608_V0)  - скорость механизма
#define idinternal1_m608_V0	 881	//(internal1_m608_V0)  - скорость механизма
#define internal1_m608_Pav0	 BUFFER[2880]	//(internal1_m608_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m608_Pav0	 882	//(internal1_m608_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m608_Zav0	 BUFFER[2882]	//(internal1_m608_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m608_Zav0	 883	//(internal1_m608_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m608_Pv0	 BUFFER[2884]	//(internal1_m608_Pv0)  - Пер. выключатель механизма
#define idinternal1_m608_Pv0	 884	//(internal1_m608_Pv0)  - Пер. выключатель механизма
#define internal1_m608_Zv0	 BUFFER[2886]	//(internal1_m608_Zv0)  - Зад. выключатель механизма
#define idinternal1_m608_Zv0	 885	//(internal1_m608_Zv0)  - Зад. выключатель механизма
#define internal1_m608_RA00	 BUFFER[2888]	//(internal1_m608_RA00)  - последнее задание вперед
#define idinternal1_m608_RA00	 886	//(internal1_m608_RA00)  - последнее задание вперед
#define internal1_m608_RA10	 BUFFER[2890]	//(internal1_m608_RA10)  - последнее задание назад
#define idinternal1_m608_RA10	 887	//(internal1_m608_RA10)  - последнее задание назад
#define internal1_m608_MyFirstEnterFlag	 BUFFER[2892]	//(internal1_m608_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m608_MyFirstEnterFlag	 888	//(internal1_m608_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m599_X0	 BUFFER[2894]	//(internal1_m599_X0)  - координата механизма
#define idinternal1_m599_X0	 889	//(internal1_m599_X0)  - координата механизма
#define internal1_m599_V0	 BUFFER[2899]	//(internal1_m599_V0)  - скорость механизма
#define idinternal1_m599_V0	 890	//(internal1_m599_V0)  - скорость механизма
#define internal1_m599_Pav0	 BUFFER[2904]	//(internal1_m599_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m599_Pav0	 891	//(internal1_m599_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m599_Zav0	 BUFFER[2906]	//(internal1_m599_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m599_Zav0	 892	//(internal1_m599_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m599_Pv0	 BUFFER[2908]	//(internal1_m599_Pv0)  - Пер. выключатель механизма
#define idinternal1_m599_Pv0	 893	//(internal1_m599_Pv0)  - Пер. выключатель механизма
#define internal1_m599_Zv0	 BUFFER[2910]	//(internal1_m599_Zv0)  - Зад. выключатель механизма
#define idinternal1_m599_Zv0	 894	//(internal1_m599_Zv0)  - Зад. выключатель механизма
#define internal1_m599_RA00	 BUFFER[2912]	//(internal1_m599_RA00)  - последнее задание вперед
#define idinternal1_m599_RA00	 895	//(internal1_m599_RA00)  - последнее задание вперед
#define internal1_m599_RA10	 BUFFER[2914]	//(internal1_m599_RA10)  - последнее задание назад
#define idinternal1_m599_RA10	 896	//(internal1_m599_RA10)  - последнее задание назад
#define internal1_m599_MyFirstEnterFlag	 BUFFER[2916]	//(internal1_m599_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m599_MyFirstEnterFlag	 897	//(internal1_m599_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m598_X0	 BUFFER[2918]	//(internal1_m598_X0)  - координата механизма
#define idinternal1_m598_X0	 898	//(internal1_m598_X0)  - координата механизма
#define internal1_m598_V0	 BUFFER[2923]	//(internal1_m598_V0)  - скорость механизма
#define idinternal1_m598_V0	 899	//(internal1_m598_V0)  - скорость механизма
#define internal1_m598_Pav0	 BUFFER[2928]	//(internal1_m598_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m598_Pav0	 900	//(internal1_m598_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m598_Zav0	 BUFFER[2930]	//(internal1_m598_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m598_Zav0	 901	//(internal1_m598_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m598_Pv0	 BUFFER[2932]	//(internal1_m598_Pv0)  - Пер. выключатель механизма
#define idinternal1_m598_Pv0	 902	//(internal1_m598_Pv0)  - Пер. выключатель механизма
#define internal1_m598_Zv0	 BUFFER[2934]	//(internal1_m598_Zv0)  - Зад. выключатель механизма
#define idinternal1_m598_Zv0	 903	//(internal1_m598_Zv0)  - Зад. выключатель механизма
#define internal1_m598_RA00	 BUFFER[2936]	//(internal1_m598_RA00)  - последнее задание вперед
#define idinternal1_m598_RA00	 904	//(internal1_m598_RA00)  - последнее задание вперед
#define internal1_m598_RA10	 BUFFER[2938]	//(internal1_m598_RA10)  - последнее задание назад
#define idinternal1_m598_RA10	 905	//(internal1_m598_RA10)  - последнее задание назад
#define internal1_m598_MyFirstEnterFlag	 BUFFER[2940]	//(internal1_m598_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m598_MyFirstEnterFlag	 906	//(internal1_m598_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m637_y0	 BUFFER[2942]	//(internal1_m637_y0) y0 - внутренний параметр
#define idinternal1_m637_y0	 907	//(internal1_m637_y0) y0 - внутренний параметр
#define internal1_m752_Chim0	 BUFFER[2947]	//(internal1_m752_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m752_Chim0	 908	//(internal1_m752_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m744_Chim0	 BUFFER[2952]	//(internal1_m744_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m744_Chim0	 909	//(internal1_m744_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m737_Chim0	 BUFFER[2957]	//(internal1_m737_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m737_Chim0	 910	//(internal1_m737_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m729_Chim0	 BUFFER[2962]	//(internal1_m729_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m729_Chim0	 911	//(internal1_m729_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m721_Chim0	 BUFFER[2967]	//(internal1_m721_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m721_Chim0	 912	//(internal1_m721_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m714_Chim0	 BUFFER[2972]	//(internal1_m714_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m714_Chim0	 913	//(internal1_m714_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m706_Chim0	 BUFFER[2977]	//(internal1_m706_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m706_Chim0	 914	//(internal1_m706_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m698_Chim0	 BUFFER[2982]	//(internal1_m698_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m698_Chim0	 915	//(internal1_m698_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m691_Chim0	 BUFFER[2987]	//(internal1_m691_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m691_Chim0	 916	//(internal1_m691_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m683_Chim0	 BUFFER[2992]	//(internal1_m683_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m683_Chim0	 917	//(internal1_m683_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m675_Chim0	 BUFFER[2997]	//(internal1_m675_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m675_Chim0	 918	//(internal1_m675_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m668_Chim0	 BUFFER[3002]	//(internal1_m668_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m668_Chim0	 919	//(internal1_m668_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m587_X0	 BUFFER[3007]	//(internal1_m587_X0)  - координата механизма
#define idinternal1_m587_X0	 920	//(internal1_m587_X0)  - координата механизма
#define internal1_m587_V0	 BUFFER[3012]	//(internal1_m587_V0)  - скорость механизма
#define idinternal1_m587_V0	 921	//(internal1_m587_V0)  - скорость механизма
#define internal1_m587_Pav0	 BUFFER[3017]	//(internal1_m587_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m587_Pav0	 922	//(internal1_m587_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m587_Zav0	 BUFFER[3019]	//(internal1_m587_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m587_Zav0	 923	//(internal1_m587_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m587_Pv0	 BUFFER[3021]	//(internal1_m587_Pv0)  - Пер. выключатель механизма
#define idinternal1_m587_Pv0	 924	//(internal1_m587_Pv0)  - Пер. выключатель механизма
#define internal1_m587_Zv0	 BUFFER[3023]	//(internal1_m587_Zv0)  - Зад. выключатель механизма
#define idinternal1_m587_Zv0	 925	//(internal1_m587_Zv0)  - Зад. выключатель механизма
#define internal1_m587_RA00	 BUFFER[3025]	//(internal1_m587_RA00)  - последнее задание вперед
#define idinternal1_m587_RA00	 926	//(internal1_m587_RA00)  - последнее задание вперед
#define internal1_m587_RA10	 BUFFER[3027]	//(internal1_m587_RA10)  - последнее задание назад
#define idinternal1_m587_RA10	 927	//(internal1_m587_RA10)  - последнее задание назад
#define internal1_m587_MyFirstEnterFlag	 BUFFER[3029]	//(internal1_m587_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m587_MyFirstEnterFlag	 928	//(internal1_m587_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m574_X0	 BUFFER[3031]	//(internal1_m574_X0)  - координата механизма
#define idinternal1_m574_X0	 929	//(internal1_m574_X0)  - координата механизма
#define internal1_m574_V0	 BUFFER[3036]	//(internal1_m574_V0)  - скорость механизма
#define idinternal1_m574_V0	 930	//(internal1_m574_V0)  - скорость механизма
#define internal1_m574_Pav0	 BUFFER[3041]	//(internal1_m574_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m574_Pav0	 931	//(internal1_m574_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m574_Zav0	 BUFFER[3043]	//(internal1_m574_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m574_Zav0	 932	//(internal1_m574_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m574_Pv0	 BUFFER[3045]	//(internal1_m574_Pv0)  - Пер. выключатель механизма
#define idinternal1_m574_Pv0	 933	//(internal1_m574_Pv0)  - Пер. выключатель механизма
#define internal1_m574_Zv0	 BUFFER[3047]	//(internal1_m574_Zv0)  - Зад. выключатель механизма
#define idinternal1_m574_Zv0	 934	//(internal1_m574_Zv0)  - Зад. выключатель механизма
#define internal1_m574_RA00	 BUFFER[3049]	//(internal1_m574_RA00)  - последнее задание вперед
#define idinternal1_m574_RA00	 935	//(internal1_m574_RA00)  - последнее задание вперед
#define internal1_m574_RA10	 BUFFER[3051]	//(internal1_m574_RA10)  - последнее задание назад
#define idinternal1_m574_RA10	 936	//(internal1_m574_RA10)  - последнее задание назад
#define internal1_m574_MyFirstEnterFlag	 BUFFER[3053]	//(internal1_m574_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m574_MyFirstEnterFlag	 937	//(internal1_m574_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m433_X0	 BUFFER[3055]	//(internal1_m433_X0)  - координата механизма
#define idinternal1_m433_X0	 938	//(internal1_m433_X0)  - координата механизма
#define internal1_m433_V0	 BUFFER[3060]	//(internal1_m433_V0)  - скорость механизма
#define idinternal1_m433_V0	 939	//(internal1_m433_V0)  - скорость механизма
#define internal1_m433_Pav0	 BUFFER[3065]	//(internal1_m433_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m433_Pav0	 940	//(internal1_m433_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m433_Zav0	 BUFFER[3067]	//(internal1_m433_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m433_Zav0	 941	//(internal1_m433_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m433_Pv0	 BUFFER[3069]	//(internal1_m433_Pv0)  - Пер. выключатель механизма
#define idinternal1_m433_Pv0	 942	//(internal1_m433_Pv0)  - Пер. выключатель механизма
#define internal1_m433_Zv0	 BUFFER[3071]	//(internal1_m433_Zv0)  - Зад. выключатель механизма
#define idinternal1_m433_Zv0	 943	//(internal1_m433_Zv0)  - Зад. выключатель механизма
#define internal1_m433_RA00	 BUFFER[3073]	//(internal1_m433_RA00)  - последнее задание вперед
#define idinternal1_m433_RA00	 944	//(internal1_m433_RA00)  - последнее задание вперед
#define internal1_m433_RA10	 BUFFER[3075]	//(internal1_m433_RA10)  - последнее задание назад
#define idinternal1_m433_RA10	 945	//(internal1_m433_RA10)  - последнее задание назад
#define internal1_m433_MyFirstEnterFlag	 BUFFER[3077]	//(internal1_m433_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m433_MyFirstEnterFlag	 946	//(internal1_m433_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m420_X0	 BUFFER[3079]	//(internal1_m420_X0)  - координата механизма
#define idinternal1_m420_X0	 947	//(internal1_m420_X0)  - координата механизма
#define internal1_m420_V0	 BUFFER[3084]	//(internal1_m420_V0)  - скорость механизма
#define idinternal1_m420_V0	 948	//(internal1_m420_V0)  - скорость механизма
#define internal1_m420_Pav0	 BUFFER[3089]	//(internal1_m420_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m420_Pav0	 949	//(internal1_m420_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m420_Zav0	 BUFFER[3091]	//(internal1_m420_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m420_Zav0	 950	//(internal1_m420_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m420_Pv0	 BUFFER[3093]	//(internal1_m420_Pv0)  - Пер. выключатель механизма
#define idinternal1_m420_Pv0	 951	//(internal1_m420_Pv0)  - Пер. выключатель механизма
#define internal1_m420_Zv0	 BUFFER[3095]	//(internal1_m420_Zv0)  - Зад. выключатель механизма
#define idinternal1_m420_Zv0	 952	//(internal1_m420_Zv0)  - Зад. выключатель механизма
#define internal1_m420_RA00	 BUFFER[3097]	//(internal1_m420_RA00)  - последнее задание вперед
#define idinternal1_m420_RA00	 953	//(internal1_m420_RA00)  - последнее задание вперед
#define internal1_m420_RA10	 BUFFER[3099]	//(internal1_m420_RA10)  - последнее задание назад
#define idinternal1_m420_RA10	 954	//(internal1_m420_RA10)  - последнее задание назад
#define internal1_m420_MyFirstEnterFlag	 BUFFER[3101]	//(internal1_m420_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m420_MyFirstEnterFlag	 955	//(internal1_m420_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m492_X0	 BUFFER[3103]	//(internal1_m492_X0)  - координата механизма
#define idinternal1_m492_X0	 956	//(internal1_m492_X0)  - координата механизма
#define internal1_m492_V0	 BUFFER[3108]	//(internal1_m492_V0)  - скорость механизма
#define idinternal1_m492_V0	 957	//(internal1_m492_V0)  - скорость механизма
#define internal1_m492_Pav0	 BUFFER[3113]	//(internal1_m492_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m492_Pav0	 958	//(internal1_m492_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m492_Zav0	 BUFFER[3115]	//(internal1_m492_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m492_Zav0	 959	//(internal1_m492_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m492_Pv0	 BUFFER[3117]	//(internal1_m492_Pv0)  - Пер. выключатель механизма
#define idinternal1_m492_Pv0	 960	//(internal1_m492_Pv0)  - Пер. выключатель механизма
#define internal1_m492_Zv0	 BUFFER[3119]	//(internal1_m492_Zv0)  - Зад. выключатель механизма
#define idinternal1_m492_Zv0	 961	//(internal1_m492_Zv0)  - Зад. выключатель механизма
#define internal1_m492_RA00	 BUFFER[3121]	//(internal1_m492_RA00)  - последнее задание вперед
#define idinternal1_m492_RA00	 962	//(internal1_m492_RA00)  - последнее задание вперед
#define internal1_m492_RA10	 BUFFER[3123]	//(internal1_m492_RA10)  - последнее задание назад
#define idinternal1_m492_RA10	 963	//(internal1_m492_RA10)  - последнее задание назад
#define internal1_m492_MyFirstEnterFlag	 BUFFER[3125]	//(internal1_m492_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m492_MyFirstEnterFlag	 964	//(internal1_m492_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m373_X0	 BUFFER[3127]	//(internal1_m373_X0)  - координата механизма
#define idinternal1_m373_X0	 965	//(internal1_m373_X0)  - координата механизма
#define internal1_m373_V0	 BUFFER[3132]	//(internal1_m373_V0)  - скорость механизма
#define idinternal1_m373_V0	 966	//(internal1_m373_V0)  - скорость механизма
#define internal1_m373_Pav0	 BUFFER[3137]	//(internal1_m373_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m373_Pav0	 967	//(internal1_m373_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m373_Zav0	 BUFFER[3139]	//(internal1_m373_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m373_Zav0	 968	//(internal1_m373_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m373_Pv0	 BUFFER[3141]	//(internal1_m373_Pv0)  - Пер. выключатель механизма
#define idinternal1_m373_Pv0	 969	//(internal1_m373_Pv0)  - Пер. выключатель механизма
#define internal1_m373_Zv0	 BUFFER[3143]	//(internal1_m373_Zv0)  - Зад. выключатель механизма
#define idinternal1_m373_Zv0	 970	//(internal1_m373_Zv0)  - Зад. выключатель механизма
#define internal1_m373_RA00	 BUFFER[3145]	//(internal1_m373_RA00)  - последнее задание вперед
#define idinternal1_m373_RA00	 971	//(internal1_m373_RA00)  - последнее задание вперед
#define internal1_m373_RA10	 BUFFER[3147]	//(internal1_m373_RA10)  - последнее задание назад
#define idinternal1_m373_RA10	 972	//(internal1_m373_RA10)  - последнее задание назад
#define internal1_m373_MyFirstEnterFlag	 BUFFER[3149]	//(internal1_m373_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m373_MyFirstEnterFlag	 973	//(internal1_m373_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m359_X0	 BUFFER[3151]	//(internal1_m359_X0)  - координата механизма
#define idinternal1_m359_X0	 974	//(internal1_m359_X0)  - координата механизма
#define internal1_m359_V0	 BUFFER[3156]	//(internal1_m359_V0)  - скорость механизма
#define idinternal1_m359_V0	 975	//(internal1_m359_V0)  - скорость механизма
#define internal1_m359_Pav0	 BUFFER[3161]	//(internal1_m359_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m359_Pav0	 976	//(internal1_m359_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m359_Zav0	 BUFFER[3163]	//(internal1_m359_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m359_Zav0	 977	//(internal1_m359_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m359_Pv0	 BUFFER[3165]	//(internal1_m359_Pv0)  - Пер. выключатель механизма
#define idinternal1_m359_Pv0	 978	//(internal1_m359_Pv0)  - Пер. выключатель механизма
#define internal1_m359_Zv0	 BUFFER[3167]	//(internal1_m359_Zv0)  - Зад. выключатель механизма
#define idinternal1_m359_Zv0	 979	//(internal1_m359_Zv0)  - Зад. выключатель механизма
#define internal1_m359_RA00	 BUFFER[3169]	//(internal1_m359_RA00)  - последнее задание вперед
#define idinternal1_m359_RA00	 980	//(internal1_m359_RA00)  - последнее задание вперед
#define internal1_m359_RA10	 BUFFER[3171]	//(internal1_m359_RA10)  - последнее задание назад
#define idinternal1_m359_RA10	 981	//(internal1_m359_RA10)  - последнее задание назад
#define internal1_m359_MyFirstEnterFlag	 BUFFER[3173]	//(internal1_m359_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m359_MyFirstEnterFlag	 982	//(internal1_m359_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m344_X0	 BUFFER[3175]	//(internal1_m344_X0)  - координата механизма
#define idinternal1_m344_X0	 983	//(internal1_m344_X0)  - координата механизма
#define internal1_m344_V0	 BUFFER[3180]	//(internal1_m344_V0)  - скорость механизма
#define idinternal1_m344_V0	 984	//(internal1_m344_V0)  - скорость механизма
#define internal1_m344_Pav0	 BUFFER[3185]	//(internal1_m344_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m344_Pav0	 985	//(internal1_m344_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m344_Zav0	 BUFFER[3187]	//(internal1_m344_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m344_Zav0	 986	//(internal1_m344_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m344_Pv0	 BUFFER[3189]	//(internal1_m344_Pv0)  - Пер. выключатель механизма
#define idinternal1_m344_Pv0	 987	//(internal1_m344_Pv0)  - Пер. выключатель механизма
#define internal1_m344_Zv0	 BUFFER[3191]	//(internal1_m344_Zv0)  - Зад. выключатель механизма
#define idinternal1_m344_Zv0	 988	//(internal1_m344_Zv0)  - Зад. выключатель механизма
#define internal1_m344_RA00	 BUFFER[3193]	//(internal1_m344_RA00)  - последнее задание вперед
#define idinternal1_m344_RA00	 989	//(internal1_m344_RA00)  - последнее задание вперед
#define internal1_m344_RA10	 BUFFER[3195]	//(internal1_m344_RA10)  - последнее задание назад
#define idinternal1_m344_RA10	 990	//(internal1_m344_RA10)  - последнее задание назад
#define internal1_m344_MyFirstEnterFlag	 BUFFER[3197]	//(internal1_m344_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m344_MyFirstEnterFlag	 991	//(internal1_m344_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m1119_X0	 BUFFER[3199]	//(internal1_m1119_X0)  - координата механизма
#define idinternal1_m1119_X0	 992	//(internal1_m1119_X0)  - координата механизма
#define internal1_m1119_V0	 BUFFER[3204]	//(internal1_m1119_V0)  - скорость механизма
#define idinternal1_m1119_V0	 993	//(internal1_m1119_V0)  - скорость механизма
#define internal1_m1119_Pav0	 BUFFER[3209]	//(internal1_m1119_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m1119_Pav0	 994	//(internal1_m1119_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m1119_Zav0	 BUFFER[3211]	//(internal1_m1119_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m1119_Zav0	 995	//(internal1_m1119_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m1119_Pv0	 BUFFER[3213]	//(internal1_m1119_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1119_Pv0	 996	//(internal1_m1119_Pv0)  - Пер. выключатель механизма
#define internal1_m1119_Zv0	 BUFFER[3215]	//(internal1_m1119_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1119_Zv0	 997	//(internal1_m1119_Zv0)  - Зад. выключатель механизма
#define internal1_m1119_RA00	 BUFFER[3217]	//(internal1_m1119_RA00)  - последнее задание вперед
#define idinternal1_m1119_RA00	 998	//(internal1_m1119_RA00)  - последнее задание вперед
#define internal1_m1119_RA10	 BUFFER[3219]	//(internal1_m1119_RA10)  - последнее задание назад
#define idinternal1_m1119_RA10	 999	//(internal1_m1119_RA10)  - последнее задание назад
#define internal1_m1119_MyFirstEnterFlag	 BUFFER[3221]	//(internal1_m1119_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1119_MyFirstEnterFlag	 1000	//(internal1_m1119_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m166_C1	 BUFFER[3223]	//(internal1_m166_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m166_C1	 1001	//(internal1_m166_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m166_C2	 BUFFER[3228]	//(internal1_m166_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m166_C2	 1002	//(internal1_m166_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m166_C3	 BUFFER[3233]	//(internal1_m166_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m166_C3	 1003	//(internal1_m166_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m166_C4	 BUFFER[3238]	//(internal1_m166_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m166_C4	 1004	//(internal1_m166_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m166_C5	 BUFFER[3243]	//(internal1_m166_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m166_C5	 1005	//(internal1_m166_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m166_C6	 BUFFER[3248]	//(internal1_m166_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m166_C6	 1006	//(internal1_m166_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m166_N0	 BUFFER[3253]	//(internal1_m166_N0) N0 - пред. концентрация нейтронов
#define idinternal1_m166_N0	 1007	//(internal1_m166_N0) N0 - пред. концентрация нейтронов
#define internal1_m166_N20	 BUFFER[3258]	//(internal1_m166_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m166_N20	 1008	//(internal1_m166_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m166_R0	 BUFFER[3263]	//(internal1_m166_R0) R0 - пред. реактивность
#define idinternal1_m166_R0	 1009	//(internal1_m166_R0) R0 - пред. реактивность
#define internal1_m166_T0	 BUFFER[3268]	//(internal1_m166_T0) T0 - пред. температура
#define idinternal1_m166_T0	 1010	//(internal1_m166_T0) T0 - пред. температура
#define internal1_m166_C0	 BUFFER[3273]	//(internal1_m166_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define idinternal1_m166_C0	 1011	//(internal1_m166_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define internal1_m166_ImpINI0	 BUFFER[3303]	//(internal1_m166_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m166_ImpINI0	 1012	//(internal1_m166_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m166_MyFirstEnterFlag	 BUFFER[3305]	//(internal1_m166_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m166_MyFirstEnterFlag	 1013	//(internal1_m166_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m274_X0	 BUFFER[3307]	//(internal1_m274_X0) X0 - координата ОРР
#define idinternal1_m274_X0	 1014	//(internal1_m274_X0) X0 - координата ОРР
#define internal1_m274_Sh0	 BUFFER[3312]	//(internal1_m274_Sh0) Sh0 - координата штока ОРР
#define idinternal1_m274_Sh0	 1015	//(internal1_m274_Sh0) Sh0 - координата штока ОРР
#define internal1_m274_RV0	 BUFFER[3317]	//(internal1_m274_RV0) V0 - текущая скорость ОРР
#define idinternal1_m274_RV0	 1016	//(internal1_m274_RV0) V0 - текущая скорость ОРР
#define internal1_m274_ShV0	 BUFFER[3322]	//(internal1_m274_ShV0) V0 - текущая скорость штока ОРР
#define idinternal1_m274_ShV0	 1017	//(internal1_m274_ShV0) V0 - текущая скорость штока ОРР
#define internal1_m274_Ppv0	 BUFFER[3327]	//(internal1_m274_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m274_Ppv0	 1018	//(internal1_m274_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m274_Pav0	 BUFFER[3329]	//(internal1_m274_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m274_Pav0	 1019	//(internal1_m274_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m274_Zav0	 BUFFER[3331]	//(internal1_m274_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m274_Zav0	 1020	//(internal1_m274_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m274_RA00	 BUFFER[3333]	//(internal1_m274_RA00) RA00 - последнее задание вперед
#define idinternal1_m274_RA00	 1021	//(internal1_m274_RA00) RA00 - последнее задание вперед
#define internal1_m274_RA10	 BUFFER[3335]	//(internal1_m274_RA10) RA10 - последнее задание назад
#define idinternal1_m274_RA10	 1022	//(internal1_m274_RA10) RA10 - последнее задание назад
#define internal1_m274_RA50	 BUFFER[3337]	//(internal1_m274_RA50) Ra50 - последнее задание скорости
#define idinternal1_m274_RA50	 1023	//(internal1_m274_RA50) Ra50 - последнее задание скорости
#define internal1_m274_fls	 BUFFER[3338]	//(internal1_m274_fls)  fls - флаг одношагового режима
#define idinternal1_m274_fls	 1024	//(internal1_m274_fls)  fls - флаг одношагового режима
#define internal1_m274_flp	 BUFFER[3340]	//(internal1_m274_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m274_flp	 1025	//(internal1_m274_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m274_MyFirstEnterFlag	 BUFFER[3342]	//(internal1_m274_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m274_MyFirstEnterFlag	 1026	//(internal1_m274_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m120_X0	 BUFFER[3344]	//(internal1_m120_X0) X0 - координата ОРР
#define idinternal1_m120_X0	 1027	//(internal1_m120_X0) X0 - координата ОРР
#define internal1_m120_Sh0	 BUFFER[3349]	//(internal1_m120_Sh0) Sh0 - координата штока ОРР
#define idinternal1_m120_Sh0	 1028	//(internal1_m120_Sh0) Sh0 - координата штока ОРР
#define internal1_m120_RV0	 BUFFER[3354]	//(internal1_m120_RV0) V0 - текущая скорость ОРР
#define idinternal1_m120_RV0	 1029	//(internal1_m120_RV0) V0 - текущая скорость ОРР
#define internal1_m120_ShV0	 BUFFER[3359]	//(internal1_m120_ShV0) V0 - текущая скорость штока ОРР
#define idinternal1_m120_ShV0	 1030	//(internal1_m120_ShV0) V0 - текущая скорость штока ОРР
#define internal1_m120_Ppv0	 BUFFER[3364]	//(internal1_m120_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m120_Ppv0	 1031	//(internal1_m120_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m120_Pav0	 BUFFER[3366]	//(internal1_m120_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m120_Pav0	 1032	//(internal1_m120_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m120_Zav0	 BUFFER[3368]	//(internal1_m120_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m120_Zav0	 1033	//(internal1_m120_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m120_RA00	 BUFFER[3370]	//(internal1_m120_RA00) RA00 - последнее задание вперед
#define idinternal1_m120_RA00	 1034	//(internal1_m120_RA00) RA00 - последнее задание вперед
#define internal1_m120_RA10	 BUFFER[3372]	//(internal1_m120_RA10) RA10 - последнее задание назад
#define idinternal1_m120_RA10	 1035	//(internal1_m120_RA10) RA10 - последнее задание назад
#define internal1_m120_RA50	 BUFFER[3374]	//(internal1_m120_RA50) Ra50 - последнее задание скорости
#define idinternal1_m120_RA50	 1036	//(internal1_m120_RA50) Ra50 - последнее задание скорости
#define internal1_m120_fls	 BUFFER[3375]	//(internal1_m120_fls)  fls - флаг одношагового режима
#define idinternal1_m120_fls	 1037	//(internal1_m120_fls)  fls - флаг одношагового режима
#define internal1_m120_flp	 BUFFER[3377]	//(internal1_m120_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m120_flp	 1038	//(internal1_m120_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m120_MyFirstEnterFlag	 BUFFER[3379]	//(internal1_m120_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m120_MyFirstEnterFlag	 1039	//(internal1_m120_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m247_X0	 BUFFER[3381]	//(internal1_m247_X0) X0 - координата ОРР
#define idinternal1_m247_X0	 1040	//(internal1_m247_X0) X0 - координата ОРР
#define internal1_m247_Sh0	 BUFFER[3386]	//(internal1_m247_Sh0) Sh0 - координата штока ОРР
#define idinternal1_m247_Sh0	 1041	//(internal1_m247_Sh0) Sh0 - координата штока ОРР
#define internal1_m247_RV0	 BUFFER[3391]	//(internal1_m247_RV0) V0 - текущая скорость ОРР
#define idinternal1_m247_RV0	 1042	//(internal1_m247_RV0) V0 - текущая скорость ОРР
#define internal1_m247_ShV0	 BUFFER[3396]	//(internal1_m247_ShV0) V0 - текущая скорость штока ОРР
#define idinternal1_m247_ShV0	 1043	//(internal1_m247_ShV0) V0 - текущая скорость штока ОРР
#define internal1_m247_Ppv0	 BUFFER[3401]	//(internal1_m247_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m247_Ppv0	 1044	//(internal1_m247_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m247_Pav0	 BUFFER[3403]	//(internal1_m247_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m247_Pav0	 1045	//(internal1_m247_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m247_Zav0	 BUFFER[3405]	//(internal1_m247_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m247_Zav0	 1046	//(internal1_m247_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m247_RA00	 BUFFER[3407]	//(internal1_m247_RA00) RA00 - последнее задание вперед
#define idinternal1_m247_RA00	 1047	//(internal1_m247_RA00) RA00 - последнее задание вперед
#define internal1_m247_RA10	 BUFFER[3409]	//(internal1_m247_RA10) RA10 - последнее задание назад
#define idinternal1_m247_RA10	 1048	//(internal1_m247_RA10) RA10 - последнее задание назад
#define internal1_m247_RA50	 BUFFER[3411]	//(internal1_m247_RA50) Ra50 - последнее задание скорости
#define idinternal1_m247_RA50	 1049	//(internal1_m247_RA50) Ra50 - последнее задание скорости
#define internal1_m247_fls	 BUFFER[3412]	//(internal1_m247_fls)  fls - флаг одношагового режима
#define idinternal1_m247_fls	 1050	//(internal1_m247_fls)  fls - флаг одношагового режима
#define internal1_m247_flp	 BUFFER[3414]	//(internal1_m247_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m247_flp	 1051	//(internal1_m247_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m247_MyFirstEnterFlag	 BUFFER[3416]	//(internal1_m247_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m247_MyFirstEnterFlag	 1052	//(internal1_m247_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m90_X0	 BUFFER[3418]	//(internal1_m90_X0) X0 - координата ОРР
#define idinternal1_m90_X0	 1053	//(internal1_m90_X0) X0 - координата ОРР
#define internal1_m90_Sh0	 BUFFER[3423]	//(internal1_m90_Sh0) Sh0 - координата штока ОРР
#define idinternal1_m90_Sh0	 1054	//(internal1_m90_Sh0) Sh0 - координата штока ОРР
#define internal1_m90_RV0	 BUFFER[3428]	//(internal1_m90_RV0) V0 - текущая скорость ОРР
#define idinternal1_m90_RV0	 1055	//(internal1_m90_RV0) V0 - текущая скорость ОРР
#define internal1_m90_ShV0	 BUFFER[3433]	//(internal1_m90_ShV0) V0 - текущая скорость штока ОРР
#define idinternal1_m90_ShV0	 1056	//(internal1_m90_ShV0) V0 - текущая скорость штока ОРР
#define internal1_m90_Ppv0	 BUFFER[3438]	//(internal1_m90_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m90_Ppv0	 1057	//(internal1_m90_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m90_Pav0	 BUFFER[3440]	//(internal1_m90_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m90_Pav0	 1058	//(internal1_m90_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m90_Zav0	 BUFFER[3442]	//(internal1_m90_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m90_Zav0	 1059	//(internal1_m90_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m90_RA00	 BUFFER[3444]	//(internal1_m90_RA00) RA00 - последнее задание вперед
#define idinternal1_m90_RA00	 1060	//(internal1_m90_RA00) RA00 - последнее задание вперед
#define internal1_m90_RA10	 BUFFER[3446]	//(internal1_m90_RA10) RA10 - последнее задание назад
#define idinternal1_m90_RA10	 1061	//(internal1_m90_RA10) RA10 - последнее задание назад
#define internal1_m90_RA50	 BUFFER[3448]	//(internal1_m90_RA50) Ra50 - последнее задание скорости
#define idinternal1_m90_RA50	 1062	//(internal1_m90_RA50) Ra50 - последнее задание скорости
#define internal1_m90_fls	 BUFFER[3449]	//(internal1_m90_fls)  fls - флаг одношагового режима
#define idinternal1_m90_fls	 1063	//(internal1_m90_fls)  fls - флаг одношагового режима
#define internal1_m90_flp	 BUFFER[3451]	//(internal1_m90_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m90_flp	 1064	//(internal1_m90_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m90_MyFirstEnterFlag	 BUFFER[3453]	//(internal1_m90_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m90_MyFirstEnterFlag	 1065	//(internal1_m90_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m211_X0	 BUFFER[3455]	//(internal1_m211_X0) X0 - координата ОРР
#define idinternal1_m211_X0	 1066	//(internal1_m211_X0) X0 - координата ОРР
#define internal1_m211_Sh0	 BUFFER[3460]	//(internal1_m211_Sh0) Sh0 - координата штока ОРР
#define idinternal1_m211_Sh0	 1067	//(internal1_m211_Sh0) Sh0 - координата штока ОРР
#define internal1_m211_RV0	 BUFFER[3465]	//(internal1_m211_RV0) V0 - текущая скорость ОРР
#define idinternal1_m211_RV0	 1068	//(internal1_m211_RV0) V0 - текущая скорость ОРР
#define internal1_m211_ShV0	 BUFFER[3470]	//(internal1_m211_ShV0) V0 - текущая скорость штока ОРР
#define idinternal1_m211_ShV0	 1069	//(internal1_m211_ShV0) V0 - текущая скорость штока ОРР
#define internal1_m211_Ppv0	 BUFFER[3475]	//(internal1_m211_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m211_Ppv0	 1070	//(internal1_m211_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m211_Pav0	 BUFFER[3477]	//(internal1_m211_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m211_Pav0	 1071	//(internal1_m211_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m211_Zav0	 BUFFER[3479]	//(internal1_m211_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m211_Zav0	 1072	//(internal1_m211_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m211_RA00	 BUFFER[3481]	//(internal1_m211_RA00) RA00 - последнее задание вперед
#define idinternal1_m211_RA00	 1073	//(internal1_m211_RA00) RA00 - последнее задание вперед
#define internal1_m211_RA10	 BUFFER[3483]	//(internal1_m211_RA10) RA10 - последнее задание назад
#define idinternal1_m211_RA10	 1074	//(internal1_m211_RA10) RA10 - последнее задание назад
#define internal1_m211_RA50	 BUFFER[3485]	//(internal1_m211_RA50) Ra50 - последнее задание скорости
#define idinternal1_m211_RA50	 1075	//(internal1_m211_RA50) Ra50 - последнее задание скорости
#define internal1_m211_fls	 BUFFER[3486]	//(internal1_m211_fls)  fls - флаг одношагового режима
#define idinternal1_m211_fls	 1076	//(internal1_m211_fls)  fls - флаг одношагового режима
#define internal1_m211_flp	 BUFFER[3488]	//(internal1_m211_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m211_flp	 1077	//(internal1_m211_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m211_MyFirstEnterFlag	 BUFFER[3490]	//(internal1_m211_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m211_MyFirstEnterFlag	 1078	//(internal1_m211_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m58_X0	 BUFFER[3492]	//(internal1_m58_X0) X0 - координата ОРР
#define idinternal1_m58_X0	 1079	//(internal1_m58_X0) X0 - координата ОРР
#define internal1_m58_Sh0	 BUFFER[3497]	//(internal1_m58_Sh0) Sh0 - координата штока ОРР
#define idinternal1_m58_Sh0	 1080	//(internal1_m58_Sh0) Sh0 - координата штока ОРР
#define internal1_m58_RV0	 BUFFER[3502]	//(internal1_m58_RV0) V0 - текущая скорость ОРР
#define idinternal1_m58_RV0	 1081	//(internal1_m58_RV0) V0 - текущая скорость ОРР
#define internal1_m58_ShV0	 BUFFER[3507]	//(internal1_m58_ShV0) V0 - текущая скорость штока ОРР
#define idinternal1_m58_ShV0	 1082	//(internal1_m58_ShV0) V0 - текущая скорость штока ОРР
#define internal1_m58_Ppv0	 BUFFER[3512]	//(internal1_m58_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m58_Ppv0	 1083	//(internal1_m58_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m58_Pav0	 BUFFER[3514]	//(internal1_m58_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m58_Pav0	 1084	//(internal1_m58_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m58_Zav0	 BUFFER[3516]	//(internal1_m58_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m58_Zav0	 1085	//(internal1_m58_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m58_RA00	 BUFFER[3518]	//(internal1_m58_RA00) RA00 - последнее задание вперед
#define idinternal1_m58_RA00	 1086	//(internal1_m58_RA00) RA00 - последнее задание вперед
#define internal1_m58_RA10	 BUFFER[3520]	//(internal1_m58_RA10) RA10 - последнее задание назад
#define idinternal1_m58_RA10	 1087	//(internal1_m58_RA10) RA10 - последнее задание назад
#define internal1_m58_RA50	 BUFFER[3522]	//(internal1_m58_RA50) Ra50 - последнее задание скорости
#define idinternal1_m58_RA50	 1088	//(internal1_m58_RA50) Ra50 - последнее задание скорости
#define internal1_m58_fls	 BUFFER[3523]	//(internal1_m58_fls)  fls - флаг одношагового режима
#define idinternal1_m58_fls	 1089	//(internal1_m58_fls)  fls - флаг одношагового режима
#define internal1_m58_flp	 BUFFER[3525]	//(internal1_m58_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m58_flp	 1090	//(internal1_m58_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m58_MyFirstEnterFlag	 BUFFER[3527]	//(internal1_m58_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m58_MyFirstEnterFlag	 1091	//(internal1_m58_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m13_C1	 BUFFER[3529]	//(internal1_m13_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m13_C1	 1092	//(internal1_m13_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m13_C2	 BUFFER[3534]	//(internal1_m13_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m13_C2	 1093	//(internal1_m13_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m13_C3	 BUFFER[3539]	//(internal1_m13_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m13_C3	 1094	//(internal1_m13_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m13_C4	 BUFFER[3544]	//(internal1_m13_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m13_C4	 1095	//(internal1_m13_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m13_C5	 BUFFER[3549]	//(internal1_m13_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m13_C5	 1096	//(internal1_m13_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m13_C6	 BUFFER[3554]	//(internal1_m13_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m13_C6	 1097	//(internal1_m13_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m13_N0	 BUFFER[3559]	//(internal1_m13_N0) N0 - пред. концентрация нейтронов
#define idinternal1_m13_N0	 1098	//(internal1_m13_N0) N0 - пред. концентрация нейтронов
#define internal1_m13_N20	 BUFFER[3564]	//(internal1_m13_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m13_N20	 1099	//(internal1_m13_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m13_R0	 BUFFER[3569]	//(internal1_m13_R0) R0 - пред. реактивность
#define idinternal1_m13_R0	 1100	//(internal1_m13_R0) R0 - пред. реактивность
#define internal1_m13_T0	 BUFFER[3574]	//(internal1_m13_T0) T0 - пред. температура
#define idinternal1_m13_T0	 1101	//(internal1_m13_T0) T0 - пред. температура
#define internal1_m13_C0	 BUFFER[3579]	//(internal1_m13_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define idinternal1_m13_C0	 1102	//(internal1_m13_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define internal1_m13_ImpINI0	 BUFFER[3609]	//(internal1_m13_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m13_ImpINI0	 1103	//(internal1_m13_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m13_MyFirstEnterFlag	 BUFFER[3611]	//(internal1_m13_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m13_MyFirstEnterFlag	 1104	//(internal1_m13_MyFirstEnterFlag) MyFirstEnterFlag
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
	{ 62	,1	,1	, &R0VN78LZ2},	//(R0VN78LZ2) АС по периоду разгона канал 4 на БАЗ2
	{ 63	,1	,1	, &B3IS22LDU},	//(B3IS22LDU) Приход на НУП ИС2
	{ 64	,1	,1	, &B3IS11LZ2},	//(B3IS11LZ2) Приход на ВУ ИС2
	{ 65	,1	,1	, &B3IS11LZ1},	//(B3IS11LZ1) Приход на ВУ ИС2
	{ 66	,1	,1	, &A3IS22LZ2},	//(A3IS22LZ2) Приход на НУП ИС1
	{ 67	,1	,1	, &A3IS22LZ1},	//(A3IS22LZ1) Приход на НУП ИС1
	{ 68	,1	,1	, &A3IS11LZ2},	//(A3IS11LZ2) Приход на ВУ ИС1
	{ 69	,1	,1	, &A3IS11LZ1},	//(A3IS11LZ1) Приход на ВУ ИС1
	{ 70	,1	,1	, &A3IS22LDU},	//(A3IS22LDU) Приход на НУП ИС1
	{ 71	,1	,1	, &B3IS11LDU},	//(B3IS11LDU) Приход на ВУ ИС2
	{ 72	,1	,1	, &A3IS11LDU},	//(A3IS11LDU) Приход на ВУ ИС1
	{ 73	,3	,1	, &A3IP02IDU},	//(A3IP02IDU) Текущее давление ВЫСТРЕЛ ИС1
	{ 74	,1	,1	, &B3VP81LDU},	//(B3VP81LDU) Давление СПУСК ИС2 в норме
	{ 75	,1	,1	, &A3VP81LDU},	//(A3VP81LDU) Давление СПУСК ИС1 в норме
	{ 76	,1	,1	, &B3IS33LDU},	//(B3IS33LDU) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{ 77	,5	,1	, &B3IC01UDU},	//(B3IC01UDU) Координата штока ИС2
	{ 78	,1	,1	, &B3IS31LDU},	//(B3IS31LDU) Клапан (СПУСК ИС2)  открыт (обесточен)
	{ 79	,3	,1	, &B3IP02IDU},	//(B3IP02IDU) Текущее давление ВЫСТРЕЛ  ИС2
	{ 80	,1	,1	, &A3IS33LDU},	//(A3IS33LDU) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
	{ 81	,5	,1	, &A3IC01UDU},	//(A3IC01UDU) Координата штока ИС1
	{ 82	,1	,1	, &A3IS31LDU},	//(A3IS31LDU) Клапан (СПУСК ИС1)  открыт (обесточен)
	{ 83	,1	,1	, &A2VP82LDU},	//(A2VP82LDU) Давление ПОДЪЁМ РБ1 в норме
	{ 84	,1	,1	, &B2IS11LIM},	//(B2IS11LIM) Магнит РБ2 обесточен
	{ 85	,1	,1	, &A2IS32LIM},	//(A2IS32LIM) Клапан cброса РБ1 открыт(обесточен)
	{ 86	,1	,1	, &A2IS11LIM},	//(A2IS11LIM) Магнит РБ1 обесточен
	{ 87	,1	,1	, &B1IS32LIM},	//(B1IS32LIM) Клапан cброса ББ2 открыт(обесточен)
	{ 88	,1	,1	, &B1IS11LIM},	//(B1IS11LIM) Магнит ББ2 обесточен
	{ 89	,1	,1	, &A1IS32LIM},	//(A1IS32LIM) Клапан cброса ББ1 открыт(обесточен)
	{ 90	,1	,1	, &A1IS11LIM},	//(A1IS11LIM) Магнит ББ1 обесточен
	{ 91	,1	,1	, &A3AD34LDU},	//(A3AD34LDU) Клапан (ВПИС ИС1) открыть (обесточить)
	{ 92	,1	,1	, &R0IS02LDU},	//(R0IS02LDU) Разрешение ввода от имитатора
	{ 93	,1	,1	, &R0EE04LZ2},	//(R0EE04LZ2) Питание  АКНП4  отключить
	{ 94	,1	,1	, &R0EE03LZ2},	//(R0EE03LZ2) Питание  АКНП3  отключить
	{ 95	,1	,1	, &R0EE02LZ2},	//(R0EE02LZ2) Питание  АКНП  отключить
	{ 96	,1	,1	, &R0EE04LZ1},	//(R0EE04LZ1) Питание  АКНП4  отключить
	{ 97	,1	,1	, &R0EE03LZ1},	//(R0EE03LZ1) Питание  АКНП3  отключить
	{ 98	,1	,1	, &R0EE02LZ1},	//(R0EE02LZ1) Питание  АКНП  отключить
	{ 99	,1	,1	, &R0EE01LZ2},	//(R0EE01LZ2) Питание  АКНП1  отключить
	{ 100	,1	,1	, &R0EE01LZ1},	//(R0EE01LZ1) Питание  АКНП1  отключить
	{ 101	,1	,1	, &R5AD20LDU},	//(R5AD20LDU) Закрыть ворота отстойной зоны
	{ 102	,1	,1	, &R3AD21LDU},	//(R3AD21LDU) Гомогенные двери-2 закрыть
	{ 103	,1	,1	, &R3AD11LDU},	//(R3AD11LDU) Гомогенные двери-2 открыть
	{ 104	,8	,1	, &B0SN07RIM},	//(B0SN07RIM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
	{ 105	,8	,1	, &B0SN06RIM},	//(B0SN06RIM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
	{ 106	,8	,1	, &B0SN05RIM},	//(B0SN05RIM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
	{ 107	,8	,1	, &B0SN04RIM},	//(B0SN04RIM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
	{ 108	,8	,1	, &B0SN03RIM},	//(B0SN03RIM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
	{ 109	,8	,1	, &B0SN02RIM},	//(B0SN02RIM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
	{ 110	,1	,1	, &B7AP31LDU},	//(B7AP31LDU) Клапан (Обдув АЗ2) открыть (обесточить)
	{ 111	,1	,1	, &A7AP31LDU},	//(A7AP31LDU) Клапан (Обдув АЗ1) открыть (обесточить)
	{ 112	,8	,1	, &A0SN07RIM},	//(A0SN07RIM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
	{ 113	,8	,1	, &A0SN06RIM},	//(A0SN06RIM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
	{ 114	,8	,1	, &A0SN05RIM},	//(A0SN05RIM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
	{ 115	,8	,1	, &A0SN04RIM},	//(A0SN04RIM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
	{ 116	,8	,1	, &A0SN03RIM},	//(A0SN03RIM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
	{ 117	,8	,1	, &A0SN02RIM},	//(A0SN02RIM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
	{ 118	,1	,1	, &A1VP81LZ2},	//(A1VP81LZ2) Давление СБРОС ББ1 в норме
	{ 119	,1	,1	, &A1VP81LZ1},	//(A1VP81LZ1) Давление СБРОС ББ1 в норме
	{ 120	,1	,1	, &B1VP81LZ1},	//(B1VP81LZ1) Давление СБРОС ББ2 в норме
	{ 121	,1	,1	, &B1VP81LZ2},	//(B1VP81LZ2) Давление СБРОС ББ2 в норме
	{ 122	,1	,1	, &B2IS33LDU},	//(B2IS33LDU) Клапан (Подъём РБ2)  открыт (обесточен)
	{ 123	,8	,1	, &A0VN01RIM},	//(A0VN01RIM) Период разгона  AЗ1
	{ 124	,1	,1	, &B2IS32LIM},	//(B2IS32LIM) Клапан cброса РБ2 открыт(обесточен)
	{ 125	,1	,1	, &A8IS12LDU},	//(A8IS12LDU) Приход на механический ВУ ДС2
	{ 126	,1	,1	, &A8IS22LDU},	//(A8IS22LDU) Приход на механический НУ ДС2
	{ 127	,1	,1	, &B8IS12LDU},	//(B8IS12LDU) Приход на механический ВУ АЗ2
	{ 128	,1	,1	, &B8IS22LDU},	//(B8IS22LDU) Приход на механический НУ АЗ2
	{ 129	,1	,1	, &R4IS12LDU},	//(R4IS12LDU) Приход на механический ВУ тележки
	{ 130	,1	,1	, &R4IS22LDU},	//(R4IS22LDU) Приход на механический НУ тележки
	{ 131	,1	,1	, &R4IS21LDU},	//(R4IS21LDU) Приход на НУ тележки
	{ 132	,1	,1	, &R4IS11LDU},	//(R4IS11LDU) Приход на ВУ тележки
	{ 133	,1	,1	, &B4VP82LDU},	//(B4VP82LDU) Давление ПОДЪЁМ НИ2 в норме
	{ 134	,1	,1	, &A4VP82LDU},	//(A4VP82LDU) Давление ПОДЪЁМ НИ1 в норме
	{ 135	,1	,1	, &R3IS41LDU},	//(R3IS41LDU) Приход на НУ гомогенных дверей-2
	{ 136	,1	,1	, &R3IS31LDU},	//(R3IS31LDU) Приход на ВУ гомогенных дверей-2
	{ 137	,1	,1	, &R2IS21LDU},	//(R2IS21LDU) Приход на НУ МДЗ2
	{ 138	,1	,1	, &R2IS11LDU},	//(R2IS11LDU) Приход на ВУ МДЗ2
	{ 139	,1	,1	, &R1IS21LDU},	//(R1IS21LDU) Приход на НУ МДЗ1
	{ 140	,1	,1	, &R1IS11LDU},	//(R1IS11LDU) Приход на ВУ МДЗ1
	{ 141	,1	,1	, &B4IS21LDU},	//(B4IS21LDU) Приход на НУ НИ2
	{ 142	,1	,1	, &B4IS11LDU},	//(B4IS11LDU) Приход на ВУ НИ2
	{ 143	,1	,1	, &R8IS11LDU},	//(R8IS11LDU) Аварийный НИ установлен
	{ 144	,1	,1	, &A4IS21LDU},	//(A4IS21LDU) Приход на НУ НИ1
	{ 145	,1	,1	, &A4IS11LDU},	//(A4IS11LDU) Приход на ВУ НИ1
	{ 146	,1	,1	, &R3AD20LDU},	//(R3AD20LDU) Гомогенные двери-1 закрыть
	{ 147	,1	,1	, &R3AD10LDU},	//(R3AD10LDU) Гомогенные двери-1 открыть
	{ 148	,1	,1	, &R5AD10LDU},	//(R5AD10LDU) Открыть ворота отстойной зоны
	{ 149	,1	,1	, &B4IS10LDU},	//(B4IS10LDU) Клапан (Подъём НИ2) открыт (обесточен)
	{ 150	,1	,1	, &A4IS10LDU},	//(A4IS10LDU) Клапан (Подъём НИ1) открыт (обесточен)
	{ 151	,1	,1	, &B1IE04LDU},	//(B1IE04LDU) Движение ББ2 назад (от БУШД)
	{ 152	,1	,1	, &B1IE03LDU},	//(B1IE03LDU) Движение ББ2 вперед (от БУШД)
	{ 153	,1	,1	, &A1IE04LDU},	//(A1IE04LDU) Движение ББ1 назад (от БУШД)
	{ 154	,1	,1	, &A1IE03LDU},	//(A1IE03LDU) Движение ББ1 вперед (от БУШД)
	{ 155	,1	,1	, &B1IS12LDU},	//(B1IS12LDU) Магнит ББ2 зацеплен
	{ 156	,1	,1	, &B1IS11LDU},	//(B1IS11LDU) Приход на ВУ ББ2
	{ 157	,1	,1	, &B1IS21LDU},	//(B1IS21LDU) Приход на НУ ББ2
	{ 158	,5	,1	, &B1IC01UDU},	//(B1IC01UDU) Координата штока ББ2
	{ 159	,5	,1	, &A1IC01UDU},	//(A1IC01UDU) Координата штока ББ1
	{ 160	,1	,1	, &A1IS12LDU},	//(A1IS12LDU) Магнит ББ1 зацеплен
	{ 161	,1	,1	, &A1IS11LDU},	//(A1IS11LDU) Приход на ВУ ББ1
	{ 162	,1	,1	, &A1IS21LDU},	//(A1IS21LDU) Приход на НУ ББ1
	{ 163	,1	,1	, &B6IS21LDU},	//(B6IS21LDU) Приход на НУ БЗ2
	{ 164	,1	,1	, &B6IS11LDU},	//(B6IS11LDU) Приход на ВУ БЗ2
	{ 165	,1	,1	, &A6IS21LDU},	//(A6IS21LDU) Приход на НУ БЗ1
	{ 166	,1	,1	, &A6IS11LDU},	//(A6IS11LDU) Приход на ВУ БЗ1
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
	{ 186	,1	,1	, &B3AD21LDU},	//(B3AD21LDU) Сигнал на перемещение ИС2 вниз
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
	{ 207	,1	,1	, &R2AD10LDU},	//(R2AD10LDU) Опустить МДЗ2 в зону облучения
	{ 208	,1	,1	, &A2AD04LDU},	//(A2AD04LDU) 2-й бит скорости РБ1
	{ 209	,1	,1	, &A2AD03LDU},	//(A2AD03LDU) 1-й бит скорости РБ1
	{ 210	,1	,1	, &A2AD02LDU},	//(A2AD02LDU) 0-й бит скорости РБ1
	{ 211	,1	,1	, &A2AD01LDU},	//(A2AD01LDU) Разрешение движения РБ1
	{ 212	,1	,1	, &A2AD21LDU},	//(A2AD21LDU) Сигнал на перемещение РБ1 вниз
	{ 213	,1	,1	, &A2AD11LDU},	//(A2AD11LDU) Сигнал на перемещение РБ1 вверх
	{ 214	,1	,1	, &B1AD05LDU},	//(B1AD05LDU) паритет команды на ББ2
	{ 215	,1	,1	, &B1AD04LDU},	//(B1AD04LDU) 2-й бит скорости ББ2
	{ 216	,1	,1	, &B1AD03LDU},	//(B1AD03LDU) 1-й бит скорости ББ2
	{ 217	,1	,1	, &B1AD02LDU},	//(B1AD02LDU) 0-й бит скорости  ББ2
	{ 218	,1	,1	, &B1AD01LDU},	//(B1AD01LDU) Разрешение движения ББ2
	{ 219	,1	,1	, &B1AD21LDU},	//(B1AD21LDU) Сигнал на перемещение ББ2 вниз
	{ 220	,1	,1	, &B1AD11LDU},	//(B1AD11LDU) Сигнал на перемещение ББ2 вверх
	{ 221	,1	,1	, &A1AD05LDU},	//(A1AD05LDU) паритет команды на ББ1
	{ 222	,1	,1	, &A1AD04LDU},	//(A1AD04LDU) 2-й бит скорости ББ1
	{ 223	,1	,1	, &A1AD03LDU},	//(A1AD03LDU) 1-й бит скорости ББ1
	{ 224	,1	,1	, &A1AD02LDU},	//(A1AD02LDU) 0-й бит скорости ББ1
	{ 225	,1	,1	, &A1AD01LDU},	//(A1AD01LDU) Разрешение движения ББ1
	{ 226	,1	,1	, &A1AD21LDU},	//(A1AD21LDU) Сигнал на перемещение ББ1 вниз
	{ 227	,1	,1	, &A1AD11LDU},	//(A1AD11LDU) Сигнал на перемещение ББ1 вверх
	{ 228	,8	,1	, &A0SR01RIM},	//(A0SR01RIM) Текущая реактивность AЗ1
	{ 229	,1	,1	, &B3AD11LDU},	//(B3AD11LDU) Сигнал на перемещение ИС2 вверх
	{ 230	,1	,1	, &A3AD33LDU},	//(A3AD33LDU) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
	{ 231	,1	,1	, &A3AD05LDU},	//(A3AD05LDU) паритет команды на ИС1
	{ 232	,1	,1	, &A3AD04LDU},	//(A3AD04LDU) 2-й бит скорости ИС1
	{ 233	,1	,1	, &A3AD03LDU},	//(A3AD03LDU) 1-й бит скорости ИС1
	{ 234	,1	,1	, &A3AD02LDU},	//(A3AD02LDU) 0-й бит скорости ИС1
	{ 235	,1	,1	, &A3AD01LDU},	//(A3AD01LDU) Разрешение движения ИС1
	{ 236	,1	,1	, &A3AD21LDU},	//(A3AD21LDU) Сигнал на перемещение ИС1 вниз
	{ 237	,1	,1	, &A3AD11LDU},	//(A3AD11LDU) Сигнал на перемещение ИС1 вверх
	{ 238	,1	,1	, &B2AD33LDU},	//(B2AD33LDU) Клапан (Подъем РБ2) закрыть (обесточить)
	{ 239	,1	,1	, &B2AD05LDU},	//(B2AD05LDU) паритет команды на РБ2
	{ 240	,1	,1	, &B2AD04LDU},	//(B2AD04LDU) 2-й бит скорости РБ2
	{ 241	,1	,1	, &B2AD03LDU},	//(B2AD03LDU) 1-й бит скорости РБ2
	{ 242	,1	,1	, &B2AD02LDU},	//(B2AD02LDU) 0-й бит скорости РБ2
	{ 243	,1	,1	, &B2AD01LDU},	//(B2AD01LDU) Разрешение движения РБ2
	{ 244	,1	,1	, &B2AD21LDU},	//(B2AD21LDU) Сигнал на перемещение РБ2 вниз
	{ 245	,1	,1	, &B2AD11LDU},	//(B2AD11LDU) Сигнал на перемещение РБ2 вверх
	{ 246	,1	,1	, &A2AD33LDU},	//(A2AD33LDU) Клапан (Подъем РБ1) закрыть (обесточить)
	{ 247	,8	,1	, &A2MV01RC1},	//(A2MV01RC1) Заданная скорость движения ББ1 от ИС
	{ 248	,8	,1	, &A2MC01RC1},	//(A2MC01RC1) Заданная координата РБ1 от ИС
	{ 249	,1	,1	, &A2AD05LDU},	//(A2AD05LDU) паритет команды на РБ1
	{ 250	,1	,1	, &A0VN71LS3},	//(A0VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ1
	{ 251	,3	,1	, &R0VN15RS3},	//(R0VN15RS3) Номер ведущей камеры канал 3
	{ 252	,1	,1	, &A1VN71LS3},	//(A1VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ2
	{ 253	,1	,1	, &R0VN73LZ1},	//(R0VN73LZ1) АС по мощности канал 3 на БАЗ1
	{ 254	,1	,1	, &R0VN61LS3},	//(R0VN61LS3) ПС по мощности канал 3
	{ 255	,8	,1	, &R0VN02RS3},	//(R0VN02RS3) Уровень мощности канал 3
	{ 256	,1	,1	, &R0IE11LS2},	//(R0IE11LS2) Исправность ВИП 1,6 (№11) СНМ11 2канала
	{ 257	,1	,1	, &R0IE13LS2},	//(R0IE13LS2) Исправность ВИП 0,5 (№13) КНК53М 2канала
	{ 258	,1	,1	, &R0IE12LS2},	//(R0IE12LS2) Исправность ВИП 0,5 (№12) КНК15-1 2канала
	{ 259	,1	,1	, &A1EE01LS2},	//(A1EE01LS2) Исправность АКНП канал 2 на БАЗ2
	{ 260	,1	,1	, &R0VN76LZ2},	//(R0VN76LZ2) АС по периоду разгона канал 2  на БАЗ2
	{ 261	,1	,1	, &A0EE01LS2},	//(A0EE01LS2) Исправность АКНП канал 2 на БАЗ1
	{ 262	,1	,1	, &R0VN76LZ1},	//(R0VN76LZ1) АС по периоду разгона канал 2  на БАЗ1
	{ 263	,1	,1	, &R0VN65LS2},	//(R0VN65LS2) ПС по периоду разгона канал 2
	{ 264	,8	,1	, &R0VN01RS2},	//(R0VN01RS2) Период разгона канал 2
	{ 265	,1	,1	, &A0VN71LS2},	//(A0VN71LS2) Блокировка автоматического подъёма ББ канал 2 на БАЗ1
	{ 266	,1	,1	, &R0VN72LZ2},	//(R0VN72LZ2) АС по мощности канал 2 на БАЗ2
	{ 267	,3	,1	, &R0VN15RS2},	//(R0VN15RS2) Номер ведущей камеры канал 2
	{ 268	,1	,1	, &A1VN71LS2},	//(A1VN71LS2) Блокировка автоматического подъёма ББ канал 2 на БАЗ2
	{ 269	,1	,1	, &R0VN72LZ1},	//(R0VN72LZ1) АС по мощности канал 2 на БАЗ1
	{ 270	,1	,1	, &A0EE01LS4},	//(A0EE01LS4) Исправность АКНП канал 4 на БАЗ1
	{ 271	,1	,1	, &R0VN78LZ1},	//(R0VN78LZ1) АС по периоду разгона канал 4 на БАЗ1
	{ 272	,1	,1	, &R0VN65LS4},	//(R0VN65LS4) ПС по периоду разгона канал 4
	{ 273	,8	,1	, &R0VN01RS4},	//(R0VN01RS4) Период разгона канал 4
	{ 274	,1	,1	, &R0VN74LZ2},	//(R0VN74LZ2) АС по мощности канал 4 на БАЗ2
	{ 275	,1	,1	, &A0VN71LS4},	//(A0VN71LS4) Блокировка автоматического  подъёма ББ канал 4 на БАЗ1
	{ 276	,3	,1	, &R0VN15RS4},	//(R0VN15RS4) Номер ведущей камеры канал 4
	{ 277	,1	,1	, &A1VN71LS4},	//(A1VN71LS4) Блокировка автоматического  подъёма ББ канал 4 на БАЗ2
	{ 278	,1	,1	, &R0VN74LZ1},	//(R0VN74LZ1) АС по мощности канал 4 на БАЗ1
	{ 279	,1	,1	, &R0VN61LS4},	//(R0VN61LS4) ПС по мощности канал 4
	{ 280	,8	,1	, &R0VN02RS4},	//(R0VN02RS4) Уровень мощности канал 4
	{ 281	,1	,1	, &R0IE11LS3},	//(R0IE11LS3) Исправность ВИП 1,6 (№14) СНМ11 3канала
	{ 282	,1	,1	, &R0IE13LS3},	//(R0IE13LS3) Исправность ВИП 0,5 (№16) КНК53М 3канала
	{ 283	,1	,1	, &R0IE12LS3},	//(R0IE12LS3) Исправность ВИП 0,5 (№15) КНК15-1 3канала
	{ 284	,1	,1	, &A1EE01LS3},	//(A1EE01LS3) Исправность АКНП канал 3 на БАЗ2
	{ 285	,1	,1	, &R0VN77LZ2},	//(R0VN77LZ2) АС по периоду разгона канал 3 на БАЗ2
	{ 286	,1	,1	, &A0EE01LS3},	//(A0EE01LS3) Исправность АКНП канал 3 на БАЗ1
	{ 287	,1	,1	, &R0VN77LZ1},	//(R0VN77LZ1) АС по периоду разгона канал 3 на БАЗ1
	{ 288	,1	,1	, &R0VN65LS3},	//(R0VN65LS3) ПС по периоду разгона канал 3
	{ 289	,8	,1	, &R0VN01RS3},	//(R0VN01RS3) Период разгона канал 3
	{ 290	,1	,1	, &R0VN73LZ2},	//(R0VN73LZ2) АС по мощности канал 3 на БАЗ2
	{ 291	,1	,1	, &R7II73LZ2},	//(R7II73LZ2) Сработала АС IIУР
	{ 292	,1	,1	, &R7II71LZ2},	//(R7II71LZ2) Сработала АС IУР (датчик 1)
	{ 293	,1	,1	, &R7II72LZ2},	//(R7II72LZ2) Сработала АС IУР (датчик 2)
	{ 294	,1	,1	, &R0AD16LDU},	//(R0AD16LDU) Контроль  I-II УР. РАД
	{ 295	,1	,1	, &R7II72LZ1},	//(R7II72LZ1) Сработала АС IУР (датчик 2)
	{ 296	,1	,1	, &R7II71LZ1},	//(R7II71LZ1) Сработала АС IУР (датчик 1)
	{ 297	,1	,1	, &R7II73LZ1},	//(R7II73LZ1) Сработала АС IIУР
	{ 298	,8	,1	, &R0SR01RIM},	//(R0SR01RIM) Текущая реактивность PУ
	{ 299	,8	,1	, &R0ST01RIM},	//(R0ST01RIM) Текущий период разгона РУ
	{ 300	,1	,1	, &A4AD10LDU},	//(A4AD10LDU) Открыть клапан (Подъем НИ1)
	{ 301	,1	,1	, &B4AD10LDU},	//(B4AD10LDU) Открыть клапан (Подъем НИ2)
	{ 302	,1	,1	, &A9AD10LDU},	//(A9AD10LDU) Открыть клапан (Подъем НИ ДС1)
	{ 303	,1	,1	, &B9AD10LDU},	//(B9AD10LDU) Открыть клапан (Подъем НИ ДС2)
	{ 304	,1	,1	, &R0MW13LP2},	//(R0MW13LP2) Переключатель «СЕТЬ»
	{ 305	,1	,1	, &B3AD31LDU},	//(B3AD31LDU) Клапан (СПУСК ИС2) открыть (обесточить)
	{ 306	,1	,1	, &B2AD32LDU},	//(B2AD32LDU) Обесточить ЭМ РБ2
	{ 307	,1	,1	, &B2AD31LDU},	//(B2AD31LDU) Клапан (Сброс РБ2) открыть (обесточить)
	{ 308	,1	,1	, &B1AD32LDU},	//(B1AD32LDU) Обесточить ЭМ ББ2
	{ 309	,1	,1	, &B1AD31LDU},	//(B1AD31LDU) Клапан (Сброс ББ2) открыть (обесточить)
	{ 310	,1	,1	, &A3AD31LDU},	//(A3AD31LDU) Клапан (СПУСК ИС1) открыть (обесточить)
	{ 311	,1	,1	, &C1MD31LP1},	//(C1MD31LP1) Кнопка «СБРОС ББ»  на ОПУ1
	{ 312	,1	,1	, &R0VN61LS2},	//(R0VN61LS2) ПС по мощности канал 2
	{ 313	,8	,1	, &R0VN02RS2},	//(R0VN02RS2) Уровень мощности канал 2
	{ 314	,1	,1	, &R0IE13LS1},	//(R0IE13LS1) Исправность ВИП 0,5 (№10) КНК53М 1канала
	{ 315	,1	,1	, &R0IE12LS1},	//(R0IE12LS1) Исправность ВИП 0,5 (№9) КНК15-1 1канала
	{ 316	,1	,1	, &R0IE11LS1},	//(R0IE11LS1) Исправность ВИП 1,6 (№8) СНМ11 1канала
	{ 317	,1	,1	, &A1EE01LS1},	//(A1EE01LS1) Исправность АКНП на БАЗ2
	{ 318	,1	,1	, &R0VN75LZ2},	//(R0VN75LZ2) АС по периоду разгонана БАЗ2
	{ 319	,1	,1	, &A0EE01LS1},	//(A0EE01LS1) Исправность АКНП канал1 на БАЗ1
	{ 320	,1	,1	, &R0VN75LZ1},	//(R0VN75LZ1) АС по периоду разгонана БАЗ1
	{ 321	,1	,1	, &R0VN65LS1},	//(R0VN65LS1) ПС по периоду разгона канал1
	{ 322	,8	,1	, &R0VN01RS1},	//(R0VN01RS1) Период разгона канал1
	{ 323	,1	,1	, &A1VN71LS1},	//(A1VN71LS1) Блокировка автоматического  подъёма ББ канал 1 на БАЗ2
	{ 324	,1	,1	, &R0VN71LZ2},	//(R0VN71LZ2) АС по мощности канал 1  на БАЗ2
	{ 325	,3	,1	, &R0VN15RS1},	//(R0VN15RS1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
	{ 326	,1	,1	, &A0VN71LS1},	//(A0VN71LS1) Блокировка автоматического  подъёма ББ канал 1 на БАЗ1
	{ 327	,1	,1	, &R0VN71LZ1},	//(R0VN71LZ1) АС по мощности канал1 на БАЗ1
	{ 328	,1	,1	, &R0VN61LS1},	//(R0VN61LS1) ПС по мощности канал1
	{ 329	,8	,1	, &R0VN02RS1},	//(R0VN02RS1) Уровень мощности канал1
	{ 330	,1	,1	, &B3IS35LDU},	//(B3IS35LDU) Клапан «ВПИС2» открыт(обесточен)
	{ 331	,1	,1	, &B3AD34LDU},	//(B3AD34LDU) Клапан (ВПИС2) открыть (обесточить)
	{ 332	,1	,1	, &A3IS35LDU},	//(A3IS35LDU) Клапан (ВПИС1) открыт(обесточен)
	{ 333	,8	,1	, &fEM_R0UL01RIM},	//(R0UL01RIM) Среднее время генерации нейтронов
	{ 334	,8	,1	, &fEM_R0UN02RIM},	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{ 335	,8	,1	, &fEM_A1UR01RIM},	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{ 336	,8	,1	, &fEM_A1UR00RIM},	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{ 337	,8	,1	, &fEM_A3UR00RIM},	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{ 338	,8	,1	, &fEM_A3UR01RIM},	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{ 339	,8	,1	, &fEM_R0UT01RIM},	//(R0UT01RIM) Температурный коэффициент (долл)
	{ 340	,8	,1	, &fEM_R0UT02RIM},	//(R0UT02RIM) Масса топлива в АЗ
	{ 341	,8	,1	, &fEM_R0UT04RIM},	//(R0UT04RIM) Удельная теплоёмкость топлива
	{ 342	,8	,1	, &fEM_R0UT03RIM},	//(R0UT03RIM) Нормальная температура АЗ град
	{ 343	,8	,1	, &fEM_R0UT05RIM},	//(R0UT05RIM) Энергия деления ядра
	{ 344	,8	,1	, &fEM_R0UT06RIM},	//(R0UT06RIM) Конвекционное сопротивление при обдуве
	{ 345	,8	,1	, &fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
	{ 346	,8	,1	, &fEM_A1UC04RIM},	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
	{ 347	,8	,1	, &fEM_A1UC05RIM},	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
	{ 348	,8	,1	, &fEM_A1UC06RIM},	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
	{ 349	,8	,1	, &fEM_A2UC06RIM},	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
	{ 350	,8	,1	, &fEM_A2UC05RIM},	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
	{ 351	,8	,1	, &fEM_A2UC04RIM},	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
	{ 352	,8	,1	, &fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
	{ 353	,8	,1	, &fEM_A3UC06RIM},	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
	{ 354	,8	,1	, &fEM_A3UC05RIM},	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
	{ 355	,8	,1	, &fEM_A3UC04RIM},	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
	{ 356	,8	,1	, &fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
	{ 357	,8	,1	, &fEM_R4UV80RDU},	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
	{ 358	,8	,1	, &fEM_R4UC10RIM},	//(R4UC10RIM) Координата верхних механических упоров тележки мм
	{ 359	,8	,1	, &fEM_R4UC20RIM},	//(R4UC20RIM) Координата нижних механических упоров тележки мм
	{ 360	,8	,1	, &fEM_B8UC21RIM},	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
	{ 361	,8	,1	, &fEM_B8UC20RIM},	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
	{ 362	,8	,1	, &fEM_B8UC11RIM},	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
	{ 363	,8	,1	, &fEM_B8UC10RIM},	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
	{ 364	,8	,1	, &fEM_B8UV80RDU},	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
	{ 365	,8	,1	, &fEM_A8UV80RDU},	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
	{ 366	,8	,1	, &fEM_A8UC10RIM},	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
	{ 367	,8	,1	, &fEM_A8UC11RIM},	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
	{ 368	,8	,1	, &fEM_A8UC20RIM},	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
	{ 369	,8	,1	, &fEM_A8UC21RIM},	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
	{ 370	,8	,1	, &fEM_A6UC10RIM},	//(A6UC10RIM) Время полного хода БЗ (сек)
	{ 371	,8	,1	, &fEM_R1UC10RIM},	//(R1UC10RIM) Время полного хода МДЗ сек
	{ 372	,8	,1	, &fEM_A5UC10RIM},	//(A5UC10RIM) Время полного хода НЛ сек
	{ 373	,8	,1	, &fEM_A0UN01RIM},	//(A0UN01RIM) Мощность источника нейтронов ИНИ
	{ 374	,8	,1	, &fEM_R4UC22RIM},	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
	{ 375	,8	,1	, &fEM_R4UC23RIM},	//(R4UC23RIM) Y-координата АЗ1 см
	{ 376	,8	,1	, &fEM_A1UG01RDU},	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
	{ 377	,8	,1	, &fEM_A2UG01RDU},	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
	{ 378	,8	,1	, &fEM_A3UG01RDU},	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
	{ 379	,8	,1	, &fEM_R7UC10RIM},	//(R7UC10RIM) X-координата КНК53М R7IN13 см
	{ 380	,8	,1	, &fEM_R7UC19RIM},	//(R7UC19RIM) Y-координата СНМ-11 (11) см
	{ 381	,8	,1	, &fEM_R7UI02RIM},	//(R7UI02RIM) Коэффициент усиления уровня радиации
	{ 382	,8	,1	, &fEM_R7UL01RIM},	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
	{ 383	,8	,1	, &fEM_A2UR00RIM},	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
	{ 384	,8	,1	, &fEM_A2UR01RIM},	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
	{ 385	,8	,1	, &fEM_A0UN02RIM},	//(A0UN02RIM) Мощность источника нейтронов с АНИ
	{ 386	,8	,1	, &fEM_R0UR30RIM},	//(R0UR30RIM) Реактивность вносимая образцами (долл)
	{ 387	,8	,1	, &fEM_R0UR01RIM},	//(R0UR01RIM) Стартовая отрицательная реактивность
	{ 388	,8	,1	, &fEM_R0UT02RDU},	//(R0UT02RDU) Верхний предел шкалы датчика температуры
	{ 389	,8	,1	, &fEM_R0UT01RDU},	//(R0UT01RDU) Нижний предел шкалы датчика температуры
	{ 390	,8	,1	, &fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
	{ 391	,8	,1	, &fEM_A2UP03RDU},	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
	{ 392	,8	,1	, &fEM_A2UP04RDU},	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
	{ 393	,8	,1	, &fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
	{ 394	,8	,1	, &fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{ 395	,8	,1	, &fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{ 396	,8	,1	, &fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
	{ 397	,8	,1	, &fEM_R7UI74RIM},	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
	{ 398	,8	,1	, &fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
	{ 399	,8	,1	, &fEM_R0UV87RDU},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 400	,8	,1	, &fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{ 401	,8	,1	, &fEM_R0UV82RDU},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{ 402	,8	,1	, &fEM_R0UV83RDU},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{ 403	,8	,1	, &fEM_R0UV84RDU},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{ 404	,8	,1	, &fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{ 405	,8	,1	, &fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 406	,8	,1	, &fEM_A8UC08RDU},	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
	{ 407	,8	,1	, &fEM_B8UC08RDU},	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
	{ 408	,8	,1	, &fEM_R4UC08RDU},	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
	{ 409	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 410	,8	,1	, &fEM_R7UX01RSS},	//(R7UX01RSS) X-координата камеры R7IN11
	{ 411	,8	,1	, &fEM_R7UX02RSS},	//(R7UX02RSS) X-координата камеры R7IN12 (см)
	{ 412	,8	,1	, &fEM_R7UX04RSS},	//(R7UX04RSS) X-координата камеры R7IN21 (см)
	{ 413	,8	,1	, &fEM_R7UX05RSS},	//(R7UX05RSS) X-координата камеры R7IN22 (см)
	{ 414	,8	,1	, &fEM_R7UX06RSS},	//(R7UX06RSS) X-координата камеры R7IN23 (см)
	{ 415	,8	,1	, &fEM_R7UX07RSS},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{ 416	,8	,1	, &fEM_R7UX08RSS},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{ 417	,8	,1	, &fEM_R7UX09RSS},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{ 418	,8	,1	, &fEM_R7UY01RSS},	//(R7UY01RSS) Y-координата камеры R7IN11
	{ 419	,8	,1	, &fEM_R7UY02RSS},	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
	{ 420	,8	,1	, &fEM_R7UY04RSS},	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
	{ 421	,8	,1	, &fEM_R7UY05RSS},	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
	{ 422	,8	,1	, &fEM_R7UY06RSS},	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
	{ 423	,8	,1	, &fEM_R7UY07RSS},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{ 424	,8	,1	, &fEM_R7UY08RSS},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{ 425	,8	,1	, &fEM_R7UY09RSS},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{ 426	,8	,1	, &fEM_R7UX10RSS},	//(R7UX10RSS) X-координата камеры R7IN41
	{ 427	,8	,1	, &fEM_R7UX11RSS},	//(R7UX11RSS) X-координата камеры R7IN42
	{ 428	,8	,1	, &fEM_R7UX12RSS},	//(R7UX12RSS) X-координата камеры R7IN43
	{ 429	,8	,1	, &fEM_R7UY10RSS},	//(R7UY10RSS) Y-координата камеры R7IN41
	{ 430	,8	,1	, &fEM_R7UY11RSS},	//(R7UY11RSS) Y-координата камеры R7IN42
	{ 431	,8	,1	, &fEM_R7UY12RSS},	//(R7UY12RSS) Y-координата камеры R7IN43
	{ 432	,8	,1	, &fEM_A0UX01RSS},	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
	{ 433	,8	,1	, &fEM_A0UX02RSS},	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
	{ 434	,8	,1	, &fEM_A0UX03RSS},	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
	{ 435	,8	,1	, &fEM_A0UX04RSS},	//(A0UX04RSS) Первый коэффициент калибровки камеры4
	{ 436	,8	,1	, &fEM_A0UX05RSS},	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
	{ 437	,8	,1	, &fEM_A0UX06RSS},	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
	{ 438	,8	,1	, &fEM_A0UX07RSS},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{ 439	,8	,1	, &fEM_A0UX08RSS},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{ 440	,8	,1	, &fEM_A0UX09RSS},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{ 441	,8	,1	, &fEM_A0UX10RSS},	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
	{ 442	,8	,1	, &fEM_A0UX11RSS},	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
	{ 443	,8	,1	, &fEM_A0UX12RSS},	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
	{ 444	,8	,1	, &fEM_B0UX01RSS},	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
	{ 445	,8	,1	, &fEM_B0UX02RSS},	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
	{ 446	,8	,1	, &fEM_B0UX03RSS},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{ 447	,8	,1	, &fEM_B0UX04RSS},	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
	{ 448	,8	,1	, &fEM_B0UX05RSS},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{ 449	,8	,1	, &fEM_B0UX06RSS},	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
	{ 450	,8	,1	, &fEM_B0UX07RSS},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{ 451	,8	,1	, &fEM_B0UX08RSS},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{ 452	,8	,1	, &fEM_B0UX09RSS},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{ 453	,8	,1	, &fEM_B0UX10RSS},	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
	{ 454	,8	,1	, &fEM_B0UX11RSS},	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
	{ 455	,8	,1	, &fEM_B0UX12RSS},	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
	{ 456	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
	{ 457	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
	{ 458	,8	,1	, &fEM_R4US80RDU},	//(R4US80RDU) Тормозной путь тележки (мм)
	{ 459	,8	,1	, &fEM_R7UI71RIM},	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{ 460	,8	,1	, &fEM_R7UI72RIM},	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
	{ 461	,8	,1	, &fEM_R7UI73RIM},	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
	{ 462	,8	,1	, &fEM_A1UP01RIM},	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
	{ 463	,8	,1	, &fEM_A2UP01RIM},	//(A2UP01RIM) Текущее давление на сброс РБ
	{ 464	,8	,1	, &fEM_A0UP02RIM},	//(A0UP02RIM) Текущее давление в АЗ1,2
	{ 465	,8	,1	, &fEM_A3UP01RIM},	//(A3UP01RIM) Текущее давление на СПУСК ИС
	{ 466	,8	,1	, &fEM_A1UP82RIM},	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{ 467	,8	,1	, &fEM_R0UP85RIM},	//(R0UP85RIM) Нижняя граница давления  в СИСТЕМЕ (МПа)
	{ 468	,8	,1	, &fEM_R0UP88RIM},	//(R0UP88RIM) Верхняя граница давления  в СИСТЕМЕ (МПа)
	{ 469	,8	,1	, &fEM_A3UP02RDU},	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
	{ 470	,8	,1	, &fEM_A1UV02RIM},	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{ 471	,8	,1	, &fEM_A3UV02RIM},	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{ 472	,8	,1	, &fEM_A2UV02RIM},	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{ 473	,8	,1	, &fEM_B8US80RDU},	//(B8US80RDU) Тормозной путь АЗ2 (мм)
	{ 474	,8	,1	, &fEM_A8US80RDU},	//(A8US80RDU) Тормозной путь ДС2 (мм)
	{ 475	,8	,1	, &fEM_A6US80RDU},	//(A6US80RDU) Тормозной путь БЗ (мм)
	{ 476	,8	,1	, &fEM_A1US07RDU},	//(A1US07RDU) Постоянная времени масляного демпфера ББ
	{ 477	,8	,1	, &fEM_A2US07RDU},	//(A2US07RDU) Постоянная времени масляного демпфера РБ
	{ 478	,8	,1	, &fEM_A3US07RDU},	//(A3US07RDU) Постоянная времени масляного демпфера ИС
	{ 479	,8	,1	, &fEM_R7UI75RIM},	//(R7UI75RIM) Множитель к уровню радиации
	{ 480	,8	,1	, &fEM_R0UH21RSS},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{ 481	,8	,1	, &fEM_R0UH22RSS},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{ 482	,8	,1	, &fEM_R0UH23RSS},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{ 483	,8	,1	, &fEM_R0UR01RSS},	//(R0UR01RSS) Уровень по мощности РУ блокировки автоматического подъёма ББ
	{ 484	,8	,1	, &fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	{ 485	,8	,1	, &fEM_R0UL41RSS},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{ 486	,8	,1	, &fEM_R0UL51RSS},	//(R0UL51RSS) Уровень АС по периоду разгона
	{ 487	,8	,1	, &fEM_R0UL42RSS},	//(R0UL42RSS) Уровень ПС по мощности
	{ 488	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 489	,8	,1	, &fEM_R0UN03RSS},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 490	,8	,1	, &fEM_A4UL10RIM},	//(A4UL10RIM) Время полного перемещения НИ сек
	{ 491	,8	,1	, &fEM_A9UL10RIM},	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
	{ 492	,8	,1	, &fEM_R3UL10RIM},	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
	{ 493	,8	,1	, &fEM_R5UL10RIM},	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
	{ 494	,8	,1	, &fEM_R6UL10RIM},	//(R6UL10RIM) Время полного хода кран-балки сек
	{ 495	,1	,1	, &lEM_C1AD31LRP},	//(C1AD31LRP) Общий сброс от РПУ
	{ 496	,1	,1	, &lEM_R0IE01LRP},	//(R0IE01LRP) Отключение питание детекторов
	{ 497	,1	,1	, &lEM_R0IE02LRP},	//(R0IE02LRP) Отключить питание ПР, ПУ
	{ 498	,8	,1	, &fEM_A0UP03RIM},	//(A0UP03RIM) Текущее давление в системе
	{ 499	,8	,1	, &fEM_A2UP02RIM},	//(A2UP02RIM) Текущее давление на подъём РБ
	{ 500	,8	,1	, &fEM_A2UP03RIM},	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
	{ 501	,8	,1	, &fEM_A0UP01RIM},	//(A0UP01RIM) Текущее давление в АЗ1,2
	{ 502	,8	,1	, &fEM_A3UP02RIM},	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
	{ 503	,8	,1	, &fEM_A4UP01RIM},	//(A4UP01RIM) Текущее давление на подъём НИ
	{ 504	,8	,1	, &fEM_A4UP02RIM},	//(A4UP02RIM) Нижняя граница давления на подъём НИ
	{ 505	,8	,1	, &fEM_R7UI76RIM},	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{ 506	,8	,1	, &fEM_R7UI77RIM},	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{ 507	,3	,1	, &iEM_TERBB1},	//(TERBB1) Неисправности  ББ1
	{ 508	,8	,1	, &fEM_A1MC02RC1},	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
	{ 509	,8	,1	, &fEM_A1MV02RC1},	//(A1MV02RC1) Заданная скорость движения штока ББ1 от ИС
	{ 510	,3	,1	, &iEM_TERBB2},	//(TERBB2) Неисправности  ББ2
	{ 511	,8	,1	, &fEM_B1MC02RC1},	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
	{ 512	,8	,1	, &fEM_B1MV02RC1},	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
	{ 513	,3	,1	, &iEM_TERRB2},	//(TERRB2) Неисправности  РБ2
	{ 514	,8	,1	, &fEM_B2MC02RC1},	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
	{ 515	,8	,1	, &fEM_B2MV02RC1},	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
	{ 516	,3	,1	, &iEM_TERRB1},	//(TERRB1) Неисправности  РБ1
	{ 517	,8	,1	, &fEM_A2MC02RC1},	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
	{ 518	,8	,1	, &fEM_A2MV02RC1},	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
	{ 519	,3	,1	, &iEM_TERIS2},	//(TERIS2) Неисправности  ИС2
	{ 520	,8	,1	, &fEM_B3MC02RC1},	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
	{ 521	,8	,1	, &fEM_B3MV02RC1},	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
	{ 522	,3	,1	, &iEM_TERIS1},	//(TERIS1) Неисправности  ИС1
	{ 523	,8	,1	, &fEM_A3MC02RC1},	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
	{ 524	,8	,1	, &fEM_A3MV02RC1},	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
	{ 525	,3	,1	, &iEM_TERAZ1},	//(TERAZ1) Неисправности АЗ1
	{ 526	,3	,1	, &iEM_TERAZ2},	//(TERAZ2) Неисправности АЗ2
	{ 527	,3	,1	, &iEM_TERA1IE04LDU},	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
	{ 528	,3	,1	, &iEM_TERA1IE03LDU},	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
	{ 529	,8	,1	, &fEM_A1MC01RC1},	//(A1MC01RC1) Заданная координата  ББ1 от ИС
	{ 530	,3	,1	, &iEM_TERB1IE03LDU},	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
	{ 531	,3	,1	, &iEM_TERB1IE04LDU},	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
	{ 532	,8	,1	, &fEM_B1MC01RC1},	//(B1MC01RC1) Заданная координата ББ2 от ИС
	{ 533	,8	,1	, &fEM_B1MV01RC1},	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
	{ 534	,8	,1	, &fEM_B2MC01RC1},	//(B2MC01RC1) Заданная координата РБ2 от ИС
	{ 535	,8	,1	, &fEM_B2MV01RC1},	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
	{ 536	,8	,1	, &fEM_A3MC01RC1},	//(A3MC01RC1) Заданная координата ИС1 от ИС
	{ 537	,8	,1	, &fEM_A3MV01RC1},	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
	{ 538	,8	,1	, &fEM_B3MC01RC1},	//(B3MC01RC1) Заданная координата ИС2 от ИС
	{ 539	,8	,1	, &fEM_B3MV01RC1},	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
	{ 540	,3	,1	, &iEM_TERA7MS31DIM},	//(TERA7MS31DIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{ 541	,3	,1	, &iEM_TERA2SS21LIM},	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
	{ 542	,3	,1	, &iEM_TERA2SS12LIM},	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
	{ 543	,3	,1	, &iEM_TERR6SS21LIM},	//(TERR6SS21LIM) Искажение: Приход на НУ кран-балки
	{ 544	,3	,1	, &iEM_TERA2VP82LIM},	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
	{ 545	,3	,1	, &iEM_TERA2SS11LIM},	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
	{ 546	,3	,1	, &iEM_TERB3SS21LIM},	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
	{ 547	,3	,1	, &iEM_TERA0MT01RIM},	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
	{ 548	,3	,1	, &iEM_TERB0MT01RIM},	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
	{ 549	,3	,1	, &iEM_TERA2SP01RIM},	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
	{ 550	,3	,1	, &iEM_TERB2SP01RIM},	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
	{ 551	,3	,1	, &iEM_TERB3SP02RIM},	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{ 552	,3	,1	, &iEM_TERA3SC01RIM},	//(TERA3SC01RIM) Искажение: Координата штока ИС1
	{ 553	,3	,1	, &iEM_TERA3VP81LIM},	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
	{ 554	,3	,1	, &iEM_TERA2SC01RIM},	//(TERA2SC01RIM) Искажение: Координата штока РБ1
	{ 555	,3	,1	, &iEM_TERA2SS33LIM},	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{ 556	,3	,1	, &iEM_TERA3SS21LIM},	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
	{ 557	,3	,1	, &iEM_TERA3SS33LIM},	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{ 558	,3	,1	, &iEM_TERA3SS31LIM},	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{ 559	,3	,1	, &iEM_TERB3SS31LIM},	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{ 560	,3	,1	, &iEM_TERB3SS33LIM},	//(TERB3SS33LIM) скажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{ 561	,3	,1	, &iEM_TERB3SC01RIM},	//(TERB3SC01RIM) Искажение: Координата штока ИС2
	{ 562	,3	,1	, &iEM_TERA3SS11LIM},	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
	{ 563	,3	,1	, &iEM_TERB3SS11LIM},	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
	{ 564	,3	,1	, &iEM_TERR6IS64LIM},	//(TERR6IS64LIM) Исправность ВИП ССДИ-35 1канал
	{ 565	,3	,1	, &iEM_TERB3SS22LIM},	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
	{ 566	,3	,1	, &iEM_TERA3SS22LIM},	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
	{ 567	,3	,1	, &iEM_TERA3SP02RIM},	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{ 568	,3	,1	, &iEM_TERR6IS62LIM},	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39 1канал
	{ 569	,3	,1	, &iEM_TERR6IS66LIM},	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 570	,3	,1	, &iEM_TERR6IS67LIM},	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 571	,3	,1	, &iEM_TERA0VP81LIM},	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
	{ 572	,3	,1	, &iEM_TERB0VP81LIM},	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
	{ 573	,3	,1	, &iEM_TERR0VP81LIM},	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ в норме
	{ 574	,3	,1	, &iEM_TERR0VP82LIM},	//(TERR0VP82LIM) Искажение: Давление  в СИСТЕМЕ-2 в норме
	{ 575	,3	,1	, &iEM_TERR6IS68LIM},	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
	{ 576	,3	,1	, &iEM_TERR7SI74RIM},	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
	{ 577	,3	,1	, &iEM_TERA5SS21LIM},	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
	{ 578	,3	,1	, &iEM_TERB5SS11LIM},	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
	{ 579	,3	,1	, &iEM_TERA5SS11LIM},	//(TERA5SS11LIM) Искажение: Приход на ВУ НЛ1
	{ 580	,3	,1	, &iEM_TERA9SS11LIM},	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
	{ 581	,3	,1	, &iEM_TERB2SS11LIM},	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
	{ 582	,3	,1	, &iEM_TERB2SS12LIM},	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
	{ 583	,3	,1	, &iEM_TERB2SS21LIM},	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
	{ 584	,3	,1	, &iEM_TERR3SS11LIM},	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
	{ 585	,3	,1	, &iEM_TERB2SC01RIM},	//(TERB2SC01RIM) Искажение: Координата штока РБ2
	{ 586	,3	,1	, &iEM_TERR3SS21LIM},	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
	{ 587	,3	,1	, &iEM_TERR5SS11LIM},	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
	{ 588	,3	,1	, &iEM_TERR3SS12LIM},	//(TERR3SS12LIM) Искажение: Приход на ВУ гомогенных дверей-2
	{ 589	,3	,1	, &iEM_TERR3SS22LIM},	//(TERR3SS22LIM) Искажение: Приход на НУ гомогенных дверей-2
	{ 590	,3	,1	, &iEM_TERA4SS11LIM},	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
	{ 591	,3	,1	, &iEM_TERR1SS11LIM},	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
	{ 592	,3	,1	, &iEM_TERR1SS21LIM},	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
	{ 593	,3	,1	, &iEM_TERR2SS11LIM},	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
	{ 594	,3	,1	, &iEM_TERR2SS21LIM},	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
	{ 595	,3	,1	, &iEM_TERA4VP82LIM},	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
	{ 596	,3	,1	, &iEM_TERB4SS21LIM},	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
	{ 597	,3	,1	, &iEM_TERR5SS21LIM},	//(TERR5SS21LIM) Искажение: Приход на НУ РБ2
	{ 598	,3	,1	, &iEM_TERB6SS21LIM},	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
	{ 599	,3	,1	, &iEM_TERB4SS11LIM},	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
	{ 600	,3	,1	, &iEM_TERA4SS21LIM},	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
	{ 601	,3	,1	, &iEM_TERA6MS11LIM},	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
	{ 602	,3	,1	, &iEM_TERA6SS21LIM},	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
	{ 603	,3	,1	, &iEM_TERB6SS11LIM},	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
	{ 604	,3	,1	, &iEM_TERR4SS11LIM},	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
	{ 605	,3	,1	, &iEM_TERR4MS21LIM},	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
	{ 606	,3	,1	, &iEM_TERR4SS12LIM},	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
	{ 607	,3	,1	, &iEM_TERR4SS22LIM},	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
	{ 608	,3	,1	, &iEM_TERR8SS11LIM},	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
	{ 609	,3	,1	, &iEM_TERB8SC01RIM},	//(TERB8SC01RIM) Искажение: Координата АЗ2
	{ 610	,3	,1	, &iEM_TERA8SC01RIM},	//(TERA8SC01RIM) Искажение: Координата ДС2
	{ 611	,3	,1	, &iEM_TERB8SS12LIM},	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
	{ 612	,3	,1	, &iEM_TERA8SS12LIM},	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
	{ 613	,3	,1	, &iEM_TERB8SS22LIM},	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
	{ 614	,3	,1	, &iEM_TERA8SS22LIM},	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
	{ 615	,3	,1	, &iEM_TERA9SS21LIM},	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
	{ 616	,3	,1	, &iEM_TERB9SS21LIM},	//(TERB9SS21LIM) Искажение: Приход на НУ РБ2
	{ 617	,3	,1	, &iEM_TERB9SS11LIM},	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
	{ 618	,3	,1	, &iEM_TERB5SS21LIM},	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
	{ 619	,3	,1	, &iEM_TERA1SS21LIM},	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
	{ 620	,3	,1	, &iEM_TERA1SS11LIM},	//(TERA1SS11LIM) Искажение: Приход на НУ РБ2
	{ 621	,3	,1	, &iEM_TERA1SC01RIM},	//(TERA1SC01RIM) Искажение: Координата штока ББ1
	{ 622	,3	,1	, &iEM_TERA1SS12LIM},	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
	{ 623	,3	,1	, &iEM_TERB1SS21LIM},	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
	{ 624	,3	,1	, &iEM_TERB1SS11LIM},	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
	{ 625	,3	,1	, &iEM_TERB1MC01RIM},	//(TERB1MC01RIM) Искажение: Координата штока ББ2
	{ 626	,3	,1	, &iEM_TERB1SS12LIM},	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
	{ 627	,3	,1	, &iEM_TERR0IE43LIM},	//(TERR0IE43LIM) Исправность ВИП 0,5 (№19) КНК53М 4канала
	{ 628	,3	,1	, &iEM_TERR0IE41LIM},	//(TERR0IE41LIM) Исправность ВИП 1,6 (№17) СНМ11 4канала
	{ 629	,1	,1	, &lEM_A0EE06LC1},	//(A0EE06LC1) Исправность АКНП4 от диагностики контроллера (От ИС)
	{ 630	,3	,1	, &iEM_TERR0IE33LIM},	//(TERR0IE33LIM) Искажение:Исправность ВИП 0,5 (№16) КНК53М 3канала
	{ 631	,3	,1	, &iEM_TERR0IE31LIM},	//(TERR0IE31LIM) Искажение: Исправность ВИП 1,6 (№14) СНМ11 3канала
	{ 632	,1	,1	, &lEM_A0EE05LC1},	//(A0EE05LC1) Исправность АКНП3 от диагностики контроллера (От ИС)
	{ 633	,3	,1	, &iEM_TERR0IE11LIM},	//(TERR0IE11LIM) Искажение: Исправность ВИП 1,6 (№8) СНМ11 1канала
	{ 634	,3	,1	, &iEM_TERR0IE13LIM},	//(TERR0IE13LIM) Искажение: Исправность ВИП 0,5 (№10) КНК53М 1канала
	{ 635	,1	,1	, &lEM_A0EE03LC1},	//(A0EE03LC1) Исправность АКНП1 от диагностики контроллера (От ИС)
	{ 636	,3	,1	, &iEM_TERR0IE23LIM},	//(TERR0IE23LIM) Искажение: Исправность ВИП 0,5 (№13) КНК53М 2канала
	{ 637	,3	,1	, &iEM_TERR0IE21LIM},	//(TERR0IE21LIM) Искажение: Исправность ВИП 1,6 (№11) СНМ11 2канала
	{ 638	,1	,1	, &lEM_A0EE04LC1},	//(A0EE04LC1) Исправность АКНП2 от диагностики контроллера (От ИС)
	{ 639	,3	,1	, &iEM_TERTLG},	//(TERTLG) Неисправности  тележки от ИС
	{ 640	,8	,1	, &fEM_R4MC01RC1},	//(R4MC01RC1) Заданная координата тележки от ИС
	{ 641	,8	,1	, &fEM_R4MV01RC1},	//(R4MV01RC1) Заданная скорость тележки от ИС
	{ 642	,3	,1	, &iEM_TERMAZ2},	//(TERMAZ2) Неисправности АЗ2 от ИС
	{ 643	,8	,1	, &fEM_B8MC01RC1},	//(B8MC01RC1) аданная координата АЗ2 от ИС
	{ 644	,8	,1	, &fEM_B8MV01RC1},	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
	{ 645	,3	,1	, &iEM_TERDS2},	//(TERDS2) Неисправности ДС2 от ИС
	{ 646	,8	,1	, &fEM_A8MC01RC1},	//(A8MC01RC1) Заданная координата ДС2 от ИС
	{ 647	,8	,1	, &fEM_A8MV01RC1},	//(A8MV01RC1) Заданная скорость ДС2 от ИС
	{ 648	,3	,1	, &iEM_TERBZ1},	//(TERBZ1) Неисправности БЗ1
	{ 649	,8	,1	, &fEM_A6MC01RC1},	//(A6MC01RC1) Заданная координата БЗ1 от ИС
	{ 650	,8	,1	, &fEM_A6MV01RC1},	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
	{ 651	,3	,1	, &iEM_TERBZ2},	//(TERBZ2) Неисправности БЗ2
	{ 652	,8	,1	, &fEM_B6MC01RC1},	//(B6MC01RC1) Заданная координата БЗ2 от ИС
	{ 653	,8	,1	, &fEM_B6MV01RC1},	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
	{ 654	,3	,1	, &iEM_TERR3AD10LDU},	//(TERR3AD10LDU) Искажение: Гомогенные двери-1 открыть
	{ 655	,3	,1	, &iEM_TERR3AD20LDU},	//(TERR3AD20LDU) Искажение: Гомогенные двери-1 закрыть
	{ 656	,3	,1	, &iEM_TERR3AD11LDU},	//(TERR3AD11LDU) Искажение: Гомогенные двери-2 открыть
	{ 657	,3	,1	, &iEM_TERR3AD21LDU},	//(TERR3AD21LDU) Искажение: Гомогенные двери-2 закрыть
	{ 658	,3	,1	, &iEM_TERR5AD10LDU},	//(TERR5AD10LDU) Искажение: Открыть ворота отстойной зоны
	{ 659	,3	,1	, &iEM_TERR5AD20LDU},	//(TERR5AD20LDU) Искажение: Закрыть ворота отстойной зоны
	{ 660	,1	,1	, &lEM_R3AD10LC1},	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
	{ 661	,1	,1	, &lEM_R3AD20LC1},	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
	{ 662	,1	,1	, &lEM_R3AD11LC1},	//(R3AD11LC1) Гомогенные двери-2 открыть от ИС
	{ 663	,1	,1	, &lEM_R3AD21LC1},	//(R3AD21LC1) Гомогенные двери-2 закрыть от ИС
	{ 664	,1	,1	, &lEM_R6AD10LC1},	//(R6AD10LC1) Выкатить кран-балку от ИС
	{ 665	,1	,1	, &lEM_R5AD10LC1},	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
	{ 666	,1	,1	, &lEM_R5AD20LC1},	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
	{ 667	,3	,1	, &iEM_TERMDZ2},	//(TERMDZ2) Неисправности МДЗ2
	{ 668	,8	,1	, &fEM_R2MC01RC1},	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
	{ 669	,8	,1	, &fEM_R2MV01RC1},	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
	{ 670	,3	,1	, &iEM_TERMDZ1},	//(TERMDZ1) Неисправности МДЗ1
	{ 671	,8	,1	, &fEM_R1MC01RC1},	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
	{ 672	,8	,1	, &fEM_R1MV01RC1},	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
	{ 673	,3	,1	, &iEM_TERNL1},	//(TERNL1) Неисправности НЛ1
	{ 674	,8	,1	, &fEM_A5MC01RC1},	//(A5MC01RC1) Заданная координата НЛ1 от ИС
	{ 675	,8	,1	, &fEM_A5MV01RC1},	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
	{ 676	,3	,1	, &iEM_TERNL2},	//(TERNL2) Неисправности НЛ2
	{ 677	,8	,1	, &fEM_B5MC01RC1},	//(B5MC01RC1) Заданная координата НЛ2 от ИС
	{ 678	,8	,1	, &fEM_B5MV01RC1},	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
	{ 679	,1	,1	, &lEM_R8AD10LC1},	//(R8AD10LC1) Установить аварийный НИ от ИС
	{ 680	,8	,1	, &fEM_A1UC08RIM},	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
	{ 681	,8	,1	, &fEM_A2UC08RIM},	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
	{ 682	,8	,1	, &fEM_A3UC08RIM},	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
	{ 683	,8	,1	, &fEM_R0UL01RSS},	//(R0UL01RSS) Шаг (мс) измерения периода
	{ 684	,8	,1	, &fEM_R0UL03RSS},	//(R0UL03RSS) Предельное время ожидания роста потока (сек)
	{ 685	,3	,1	, &iEM_TERB2SS33LIM},	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{ 686	,3	,1	, &iEM_TERA1VP81LIM},	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
	{ 687	,3	,1	, &iEM_TERB1VP81LIM},	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
	{ 688	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 689	,1	,1	, &internal1_m515_Out10},	//(internal1_m515_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 690	,1	,1	, &internal1_m533_Out10},	//(internal1_m533_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 691	,1	,1	, &internal1_m383_Out10},	//(internal1_m383_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 692	,1	,1	, &internal1_m472_q0},	//(internal1_m472_q0) q0 - внутренний параметр
	{ 693	,1	,1	, &internal1_m473_q0},	//(internal1_m473_q0) q0 - внутренний параметр
	{ 694	,1	,1	, &internal1_m446_q0},	//(internal1_m446_q0) q0 - внутренний параметр
	{ 695	,1	,1	, &internal1_m447_q0},	//(internal1_m447_q0) q0 - внутренний параметр
	{ 696	,1	,1	, &internal1_m448_q0},	//(internal1_m448_q0) q0 - внутренний параметр
	{ 697	,1	,1	, &internal1_m449_q0},	//(internal1_m449_q0) q0 - внутренний параметр
	{ 698	,8	,1	, &internal1_m629_tx},	//(internal1_m629_tx) tx - время накопленное сек
	{ 699	,18	,1	, &internal1_m629_y0},	//(internal1_m629_y0) y0
	{ 700	,8	,1	, &internal1_m617_tx},	//(internal1_m617_tx) tx - время накопленное сек
	{ 701	,18	,1	, &internal1_m617_y0},	//(internal1_m617_y0) y0
	{ 702	,1	,1	, &internal1_m475_Out10},	//(internal1_m475_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 703	,1	,1	, &internal1_m453_Out10},	//(internal1_m453_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 704	,1	,1	, &internal1_m452_Out10},	//(internal1_m452_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 705	,1	,1	, &internal1_m451_Out10},	//(internal1_m451_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 706	,1	,1	, &internal1_m450_Out10},	//(internal1_m450_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 707	,1	,1	, &internal1_m474_Out10},	//(internal1_m474_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 708	,8	,1	, &internal1_m607_tx},	//(internal1_m607_tx) tx - время накопленное сек
	{ 709	,18	,1	, &internal1_m607_y0},	//(internal1_m607_y0) y0
	{ 710	,8	,1	, &internal1_m605_tx},	//(internal1_m605_tx) tx - время накопленное сек
	{ 711	,18	,1	, &internal1_m605_y0},	//(internal1_m605_y0) y0
	{ 712	,1	,1	, &internal1_m190_Out10},	//(internal1_m190_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 713	,1	,1	, &internal1_m207_Out10},	//(internal1_m207_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 714	,1	,1	, &internal1_m39_Out10},	//(internal1_m39_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 715	,1	,1	, &internal1_m54_Out10},	//(internal1_m54_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 716	,1	,1	, &internal1_m1196_Out10},	//(internal1_m1196_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 717	,1	,1	, &internal1_m1193_Out10},	//(internal1_m1193_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 718	,1	,1	, &internal1_m1192_Out10},	//(internal1_m1192_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 719	,8	,1	, &internal1_m1195_Xtek0},	//(internal1_m1195_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 720	,8	,1	, &internal1_m1181_Xtek0},	//(internal1_m1181_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 721	,1	,1	, &internal1_m1182_Out10},	//(internal1_m1182_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 722	,1	,1	, &internal1_m1179_Out10},	//(internal1_m1179_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 723	,1	,1	, &internal1_m1178_Out10},	//(internal1_m1178_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 724	,1	,1	, &internal1_m905_Out10},	//(internal1_m905_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 725	,1	,1	, &internal1_m926_Out10},	//(internal1_m926_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 726	,1	,1	, &internal1_m925_Out10},	//(internal1_m925_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 727	,1	,1	, &internal1_m924_Out10},	//(internal1_m924_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 728	,1	,1	, &internal1_m1090_Out10},	//(internal1_m1090_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 729	,1	,1	, &internal1_m1092_Out10},	//(internal1_m1092_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 730	,1	,1	, &internal1_m1089_Out10},	//(internal1_m1089_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 731	,1	,1	, &internal1_m1091_Out10},	//(internal1_m1091_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 732	,1	,1	, &internal1_m1069_Out10},	//(internal1_m1069_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 733	,1	,1	, &internal1_m1070_Out10},	//(internal1_m1070_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 734	,1	,1	, &internal1_m1068_Out10},	//(internal1_m1068_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 735	,1	,1	, &internal1_m1067_Out10},	//(internal1_m1067_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 736	,1	,1	, &internal1_m902_Out10},	//(internal1_m902_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 737	,1	,1	, &internal1_m901_Out10},	//(internal1_m901_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 738	,1	,1	, &internal1_m881_Out10},	//(internal1_m881_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 739	,1	,1	, &internal1_m885_Out10},	//(internal1_m885_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 740	,1	,1	, &internal1_m884_Out10},	//(internal1_m884_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 741	,1	,1	, &internal1_m883_Out10},	//(internal1_m883_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 742	,1	,1	, &internal1_m882_Out10},	//(internal1_m882_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 743	,1	,1	, &internal1_m903_Out10},	//(internal1_m903_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 744	,1	,1	, &internal1_m922_Out10},	//(internal1_m922_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 745	,1	,1	, &internal1_m1071_Out10},	//(internal1_m1071_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 746	,1	,1	, &internal1_m923_Out10},	//(internal1_m923_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 747	,1	,1	, &internal1_m921_Out10},	//(internal1_m921_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 748	,1	,1	, &internal1_m904_Out10},	//(internal1_m904_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 749	,1	,1	, &internal1_m920_Out10},	//(internal1_m920_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 750	,1	,1	, &internal1_m900_Out10},	//(internal1_m900_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 751	,1	,1	, &internal1_m880_Out10},	//(internal1_m880_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 752	,1	,1	, &internal1_m532_Out10},	//(internal1_m532_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 753	,8	,1	, &internal1_m393_Xtek0},	//(internal1_m393_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 754	,1	,1	, &internal1_m384_Out10},	//(internal1_m384_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 755	,1	,1	, &internal1_m386_Out10},	//(internal1_m386_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 756	,1	,1	, &internal1_m385_Out10},	//(internal1_m385_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 757	,1	,1	, &internal1_m1104_Out10},	//(internal1_m1104_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 758	,1	,1	, &internal1_m1105_Out10},	//(internal1_m1105_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 759	,1	,1	, &internal1_m1103_Out10},	//(internal1_m1103_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 760	,1	,1	, &internal1_m941_Out10},	//(internal1_m941_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 761	,1	,1	, &internal1_m1106_Out10},	//(internal1_m1106_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 762	,1	,1	, &internal1_m939_Out10},	//(internal1_m939_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 763	,1	,1	, &internal1_m938_Out10},	//(internal1_m938_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 764	,1	,1	, &internal1_m940_Out10},	//(internal1_m940_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 765	,1	,1	, &internal1_m555_Out10},	//(internal1_m555_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 766	,1	,1	, &internal1_m553_Out10},	//(internal1_m553_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 767	,1	,1	, &internal1_m552_Out10},	//(internal1_m552_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 768	,1	,1	, &internal1_m554_Out10},	//(internal1_m554_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 769	,8	,1	, &internal1_m1086_Xtek0},	//(internal1_m1086_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 770	,8	,1	, &internal1_m1088_Xtek0},	//(internal1_m1088_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 771	,1	,1	, &internal1_m662_Out10},	//(internal1_m662_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 772	,1	,1	, &internal1_m657_Out10},	//(internal1_m657_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 773	,1	,1	, &internal1_m648_Out10},	//(internal1_m648_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 774	,1	,1	, &internal1_m656_Out10},	//(internal1_m656_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 775	,1	,1	, &internal1_m647_Out10},	//(internal1_m647_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 776	,1	,1	, &internal1_m315_Out10},	//(internal1_m315_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 777	,1	,1	, &internal1_m314_Out10},	//(internal1_m314_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 778	,1	,1	, &internal1_m295_Out10},	//(internal1_m295_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 779	,1	,1	, &internal1_m294_Out10},	//(internal1_m294_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 780	,1	,1	, &internal1_m556_Out10},	//(internal1_m556_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 781	,1	,1	, &internal1_m330_Out10},	//(internal1_m330_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 782	,8	,1	, &internal1_m312_Xtek0},	//(internal1_m312_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 783	,1	,1	, &internal1_m329_Out10},	//(internal1_m329_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 784	,1	,1	, &internal1_m327_Out10},	//(internal1_m327_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 785	,8	,1	, &internal1_m303_Xtek0},	//(internal1_m303_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 786	,1	,1	, &internal1_m328_Out10},	//(internal1_m328_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 787	,1	,1	, &internal1_m293_Out10},	//(internal1_m293_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 788	,1	,1	, &internal1_m313_Out10},	//(internal1_m313_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 789	,1	,1	, &internal1_m405_Out10},	//(internal1_m405_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 790	,8	,1	, &internal1_m406_Xtek0},	//(internal1_m406_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 791	,1	,1	, &internal1_m404_Out10},	//(internal1_m404_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 792	,1	,1	, &internal1_m403_Out10},	//(internal1_m403_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 793	,1	,1	, &internal1_m402_Out10},	//(internal1_m402_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 794	,1	,1	, &internal1_m886_Out10},	//(internal1_m886_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 795	,1	,1	, &internal1_m136_Out10},	//(internal1_m136_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 796	,1	,1	, &internal1_m135_Out10},	//(internal1_m135_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 797	,1	,1	, &internal1_m1060_Out10},	//(internal1_m1060_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 798	,1	,1	, &internal1_m1050_Out10},	//(internal1_m1050_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 799	,8	,2	, &internal1_m1039_tst},	//(internal1_m1039_tst) - массив времени фиксации стартовой мощности
	{ 800	,8	,2	, &internal1_m1039_trz},	//(internal1_m1039_trz) - массив времени фиксации очередного периода
	{ 801	,8	,2	, &internal1_m1039_N1},	//(internal1_m1039_N1) - массив значения мощности в начале замера
	{ 802	,8	,2	, &internal1_m1039_N2},	//(internal1_m1039_N2) - массив значения мощности в конце замера
	{ 803	,8	,1	, &internal1_m1039_Period0},	//(internal1_m1039_Period0) Per - Период разгона РУ
	{ 804	,1	,1	, &internal1_m1039_MyFirstEnterFlag},	//(internal1_m1039_MyFirstEnterFlag)  FirstEnterFlag
	{ 805	,3	,1	, &internal1_m1005_Nk},	//(internal1_m1005_Nk) Nk - ведущая камера
	{ 806	,1	,1	, &internal1_m1000_Out10},	//(internal1_m1000_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 807	,1	,1	, &internal1_m992_Out10},	//(internal1_m992_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 808	,8	,2	, &internal1_m981_tst},	//(internal1_m981_tst) - массив времени фиксации стартовой мощности
	{ 809	,8	,2	, &internal1_m981_trz},	//(internal1_m981_trz) - массив времени фиксации очередного периода
	{ 810	,8	,2	, &internal1_m981_N1},	//(internal1_m981_N1) - массив значения мощности в начале замера
	{ 811	,8	,2	, &internal1_m981_N2},	//(internal1_m981_N2) - массив значения мощности в конце замера
	{ 812	,8	,1	, &internal1_m981_Period0},	//(internal1_m981_Period0) Per - Период разгона РУ
	{ 813	,1	,1	, &internal1_m981_MyFirstEnterFlag},	//(internal1_m981_MyFirstEnterFlag)  FirstEnterFlag
	{ 814	,3	,1	, &internal1_m951_Nk},	//(internal1_m951_Nk) Nk - ведущая камера
	{ 815	,1	,1	, &internal1_m869_Out10},	//(internal1_m869_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 816	,1	,1	, &internal1_m859_Out10},	//(internal1_m859_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 817	,8	,2	, &internal1_m850_tst},	//(internal1_m850_tst) - массив времени фиксации стартовой мощности
	{ 818	,8	,2	, &internal1_m850_trz},	//(internal1_m850_trz) - массив времени фиксации очередного периода
	{ 819	,8	,2	, &internal1_m850_N1},	//(internal1_m850_N1) - массив значения мощности в начале замера
	{ 820	,8	,2	, &internal1_m850_N2},	//(internal1_m850_N2) - массив значения мощности в конце замера
	{ 821	,8	,1	, &internal1_m850_Period0},	//(internal1_m850_Period0) Per - Период разгона РУ
	{ 822	,1	,1	, &internal1_m850_MyFirstEnterFlag},	//(internal1_m850_MyFirstEnterFlag)  FirstEnterFlag
	{ 823	,3	,1	, &internal1_m816_Nk},	//(internal1_m816_Nk) Nk - ведущая камера
	{ 824	,1	,1	, &internal1_m803_Out10},	//(internal1_m803_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 825	,1	,1	, &internal1_m792_Out10},	//(internal1_m792_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 826	,8	,2	, &internal1_m795_tst},	//(internal1_m795_tst) - массив времени фиксации стартовой мощности
	{ 827	,8	,2	, &internal1_m795_trz},	//(internal1_m795_trz) - массив времени фиксации очередного периода
	{ 828	,8	,2	, &internal1_m795_N1},	//(internal1_m795_N1) - массив значения мощности в начале замера
	{ 829	,8	,2	, &internal1_m795_N2},	//(internal1_m795_N2) - массив значения мощности в конце замера
	{ 830	,8	,1	, &internal1_m795_Period0},	//(internal1_m795_Period0) Per - Период разгона РУ
	{ 831	,1	,1	, &internal1_m795_MyFirstEnterFlag},	//(internal1_m795_MyFirstEnterFlag)  FirstEnterFlag
	{ 832	,3	,1	, &internal1_m758_Nk},	//(internal1_m758_Nk) Nk - ведущая камера
	{ 833	,3	,1	, &internal1_m179_tx},	//(internal1_m179_tx) tx - внутренний параметр
	{ 834	,3	,1	, &internal1_m24_tx},	//(internal1_m24_tx) tx - внутренний параметр
	{ 835	,8	,1	, &internal1_m461_X0},	//(internal1_m461_X0)  - координата механизма
	{ 836	,8	,1	, &internal1_m461_V0},	//(internal1_m461_V0)  - скорость механизма
	{ 837	,1	,1	, &internal1_m461_Pav0},	//(internal1_m461_Pav0)  - Пер.аварийный выключатель механизма
	{ 838	,1	,1	, &internal1_m461_Zav0},	//(internal1_m461_Zav0)  - Зад.аварийный выключатель механизма
	{ 839	,1	,1	, &internal1_m461_Pv0},	//(internal1_m461_Pv0)  - Пер. выключатель механизма
	{ 840	,1	,1	, &internal1_m461_Zv0},	//(internal1_m461_Zv0)  - Зад. выключатель механизма
	{ 841	,1	,1	, &internal1_m461_RA00},	//(internal1_m461_RA00)  - последнее задание вперед
	{ 842	,1	,1	, &internal1_m461_RA10},	//(internal1_m461_RA10)  - последнее задание назад
	{ 843	,1	,1	, &internal1_m461_MyFirstEnterFlag},	//(internal1_m461_MyFirstEnterFlag) MyFirstEnterFlag
	{ 844	,8	,1	, &internal1_m482_X0},	//(internal1_m482_X0)  - координата механизма
	{ 845	,8	,1	, &internal1_m482_V0},	//(internal1_m482_V0)  - скорость механизма
	{ 846	,1	,1	, &internal1_m482_Pav0},	//(internal1_m482_Pav0)  - Пер.аварийный выключатель механизма
	{ 847	,1	,1	, &internal1_m482_Zav0},	//(internal1_m482_Zav0)  - Зад.аварийный выключатель механизма
	{ 848	,1	,1	, &internal1_m482_Pv0},	//(internal1_m482_Pv0)  - Пер. выключатель механизма
	{ 849	,1	,1	, &internal1_m482_Zv0},	//(internal1_m482_Zv0)  - Зад. выключатель механизма
	{ 850	,1	,1	, &internal1_m482_RA00},	//(internal1_m482_RA00)  - последнее задание вперед
	{ 851	,1	,1	, &internal1_m482_RA10},	//(internal1_m482_RA10)  - последнее задание назад
	{ 852	,1	,1	, &internal1_m482_MyFirstEnterFlag},	//(internal1_m482_MyFirstEnterFlag) MyFirstEnterFlag
	{ 853	,8	,1	, &internal1_m480_X0},	//(internal1_m480_X0)  - координата механизма
	{ 854	,8	,1	, &internal1_m480_V0},	//(internal1_m480_V0)  - скорость механизма
	{ 855	,1	,1	, &internal1_m480_Pav0},	//(internal1_m480_Pav0)  - Пер.аварийный выключатель механизма
	{ 856	,1	,1	, &internal1_m480_Zav0},	//(internal1_m480_Zav0)  - Зад.аварийный выключатель механизма
	{ 857	,1	,1	, &internal1_m480_Pv0},	//(internal1_m480_Pv0)  - Пер. выключатель механизма
	{ 858	,1	,1	, &internal1_m480_Zv0},	//(internal1_m480_Zv0)  - Зад. выключатель механизма
	{ 859	,1	,1	, &internal1_m480_RA00},	//(internal1_m480_RA00)  - последнее задание вперед
	{ 860	,1	,1	, &internal1_m480_RA10},	//(internal1_m480_RA10)  - последнее задание назад
	{ 861	,1	,1	, &internal1_m480_MyFirstEnterFlag},	//(internal1_m480_MyFirstEnterFlag) MyFirstEnterFlag
	{ 862	,8	,1	, &internal1_m456_X0},	//(internal1_m456_X0)  - координата механизма
	{ 863	,8	,1	, &internal1_m456_V0},	//(internal1_m456_V0)  - скорость механизма
	{ 864	,1	,1	, &internal1_m456_Pav0},	//(internal1_m456_Pav0)  - Пер.аварийный выключатель механизма
	{ 865	,1	,1	, &internal1_m456_Zav0},	//(internal1_m456_Zav0)  - Зад.аварийный выключатель механизма
	{ 866	,1	,1	, &internal1_m456_Pv0},	//(internal1_m456_Pv0)  - Пер. выключатель механизма
	{ 867	,1	,1	, &internal1_m456_Zv0},	//(internal1_m456_Zv0)  - Зад. выключатель механизма
	{ 868	,1	,1	, &internal1_m456_RA00},	//(internal1_m456_RA00)  - последнее задание вперед
	{ 869	,1	,1	, &internal1_m456_RA10},	//(internal1_m456_RA10)  - последнее задание назад
	{ 870	,1	,1	, &internal1_m456_MyFirstEnterFlag},	//(internal1_m456_MyFirstEnterFlag) MyFirstEnterFlag
	{ 871	,8	,1	, &internal1_m609_X0},	//(internal1_m609_X0)  - координата механизма
	{ 872	,8	,1	, &internal1_m609_V0},	//(internal1_m609_V0)  - скорость механизма
	{ 873	,1	,1	, &internal1_m609_Pav0},	//(internal1_m609_Pav0)  - Пер.аварийный выключатель механизма
	{ 874	,1	,1	, &internal1_m609_Zav0},	//(internal1_m609_Zav0)  - Зад.аварийный выключатель механизма
	{ 875	,1	,1	, &internal1_m609_Pv0},	//(internal1_m609_Pv0)  - Пер. выключатель механизма
	{ 876	,1	,1	, &internal1_m609_Zv0},	//(internal1_m609_Zv0)  - Зад. выключатель механизма
	{ 877	,1	,1	, &internal1_m609_RA00},	//(internal1_m609_RA00)  - последнее задание вперед
	{ 878	,1	,1	, &internal1_m609_RA10},	//(internal1_m609_RA10)  - последнее задание назад
	{ 879	,1	,1	, &internal1_m609_MyFirstEnterFlag},	//(internal1_m609_MyFirstEnterFlag) MyFirstEnterFlag
	{ 880	,8	,1	, &internal1_m608_X0},	//(internal1_m608_X0)  - координата механизма
	{ 881	,8	,1	, &internal1_m608_V0},	//(internal1_m608_V0)  - скорость механизма
	{ 882	,1	,1	, &internal1_m608_Pav0},	//(internal1_m608_Pav0)  - Пер.аварийный выключатель механизма
	{ 883	,1	,1	, &internal1_m608_Zav0},	//(internal1_m608_Zav0)  - Зад.аварийный выключатель механизма
	{ 884	,1	,1	, &internal1_m608_Pv0},	//(internal1_m608_Pv0)  - Пер. выключатель механизма
	{ 885	,1	,1	, &internal1_m608_Zv0},	//(internal1_m608_Zv0)  - Зад. выключатель механизма
	{ 886	,1	,1	, &internal1_m608_RA00},	//(internal1_m608_RA00)  - последнее задание вперед
	{ 887	,1	,1	, &internal1_m608_RA10},	//(internal1_m608_RA10)  - последнее задание назад
	{ 888	,1	,1	, &internal1_m608_MyFirstEnterFlag},	//(internal1_m608_MyFirstEnterFlag) MyFirstEnterFlag
	{ 889	,8	,1	, &internal1_m599_X0},	//(internal1_m599_X0)  - координата механизма
	{ 890	,8	,1	, &internal1_m599_V0},	//(internal1_m599_V0)  - скорость механизма
	{ 891	,1	,1	, &internal1_m599_Pav0},	//(internal1_m599_Pav0)  - Пер.аварийный выключатель механизма
	{ 892	,1	,1	, &internal1_m599_Zav0},	//(internal1_m599_Zav0)  - Зад.аварийный выключатель механизма
	{ 893	,1	,1	, &internal1_m599_Pv0},	//(internal1_m599_Pv0)  - Пер. выключатель механизма
	{ 894	,1	,1	, &internal1_m599_Zv0},	//(internal1_m599_Zv0)  - Зад. выключатель механизма
	{ 895	,1	,1	, &internal1_m599_RA00},	//(internal1_m599_RA00)  - последнее задание вперед
	{ 896	,1	,1	, &internal1_m599_RA10},	//(internal1_m599_RA10)  - последнее задание назад
	{ 897	,1	,1	, &internal1_m599_MyFirstEnterFlag},	//(internal1_m599_MyFirstEnterFlag) MyFirstEnterFlag
	{ 898	,8	,1	, &internal1_m598_X0},	//(internal1_m598_X0)  - координата механизма
	{ 899	,8	,1	, &internal1_m598_V0},	//(internal1_m598_V0)  - скорость механизма
	{ 900	,1	,1	, &internal1_m598_Pav0},	//(internal1_m598_Pav0)  - Пер.аварийный выключатель механизма
	{ 901	,1	,1	, &internal1_m598_Zav0},	//(internal1_m598_Zav0)  - Зад.аварийный выключатель механизма
	{ 902	,1	,1	, &internal1_m598_Pv0},	//(internal1_m598_Pv0)  - Пер. выключатель механизма
	{ 903	,1	,1	, &internal1_m598_Zv0},	//(internal1_m598_Zv0)  - Зад. выключатель механизма
	{ 904	,1	,1	, &internal1_m598_RA00},	//(internal1_m598_RA00)  - последнее задание вперед
	{ 905	,1	,1	, &internal1_m598_RA10},	//(internal1_m598_RA10)  - последнее задание назад
	{ 906	,1	,1	, &internal1_m598_MyFirstEnterFlag},	//(internal1_m598_MyFirstEnterFlag) MyFirstEnterFlag
	{ 907	,8	,1	, &internal1_m637_y0},	//(internal1_m637_y0) y0 - внутренний параметр
	{ 908	,8	,1	, &internal1_m752_Chim0},	//(internal1_m752_Chim0) измеренная частота импульсов камеры Гц
	{ 909	,8	,1	, &internal1_m744_Chim0},	//(internal1_m744_Chim0) измеренная частота импульсов камеры Гц
	{ 910	,8	,1	, &internal1_m737_Chim0},	//(internal1_m737_Chim0) измеренная частота импульсов камеры Гц
	{ 911	,8	,1	, &internal1_m729_Chim0},	//(internal1_m729_Chim0) измеренная частота импульсов камеры Гц
	{ 912	,8	,1	, &internal1_m721_Chim0},	//(internal1_m721_Chim0) измеренная частота импульсов камеры Гц
	{ 913	,8	,1	, &internal1_m714_Chim0},	//(internal1_m714_Chim0) измеренная частота импульсов камеры Гц
	{ 914	,8	,1	, &internal1_m706_Chim0},	//(internal1_m706_Chim0) измеренная частота импульсов камеры Гц
	{ 915	,8	,1	, &internal1_m698_Chim0},	//(internal1_m698_Chim0) измеренная частота импульсов камеры Гц
	{ 916	,8	,1	, &internal1_m691_Chim0},	//(internal1_m691_Chim0) измеренная частота импульсов камеры Гц
	{ 917	,8	,1	, &internal1_m683_Chim0},	//(internal1_m683_Chim0) измеренная частота импульсов камеры Гц
	{ 918	,8	,1	, &internal1_m675_Chim0},	//(internal1_m675_Chim0) измеренная частота импульсов камеры Гц
	{ 919	,8	,1	, &internal1_m668_Chim0},	//(internal1_m668_Chim0) измеренная частота импульсов камеры Гц
	{ 920	,8	,1	, &internal1_m587_X0},	//(internal1_m587_X0)  - координата механизма
	{ 921	,8	,1	, &internal1_m587_V0},	//(internal1_m587_V0)  - скорость механизма
	{ 922	,1	,1	, &internal1_m587_Pav0},	//(internal1_m587_Pav0)  - Пер.аварийный выключатель механизма
	{ 923	,1	,1	, &internal1_m587_Zav0},	//(internal1_m587_Zav0)  - Зад.аварийный выключатель механизма
	{ 924	,1	,1	, &internal1_m587_Pv0},	//(internal1_m587_Pv0)  - Пер. выключатель механизма
	{ 925	,1	,1	, &internal1_m587_Zv0},	//(internal1_m587_Zv0)  - Зад. выключатель механизма
	{ 926	,1	,1	, &internal1_m587_RA00},	//(internal1_m587_RA00)  - последнее задание вперед
	{ 927	,1	,1	, &internal1_m587_RA10},	//(internal1_m587_RA10)  - последнее задание назад
	{ 928	,1	,1	, &internal1_m587_MyFirstEnterFlag},	//(internal1_m587_MyFirstEnterFlag) MyFirstEnterFlag
	{ 929	,8	,1	, &internal1_m574_X0},	//(internal1_m574_X0)  - координата механизма
	{ 930	,8	,1	, &internal1_m574_V0},	//(internal1_m574_V0)  - скорость механизма
	{ 931	,1	,1	, &internal1_m574_Pav0},	//(internal1_m574_Pav0)  - Пер.аварийный выключатель механизма
	{ 932	,1	,1	, &internal1_m574_Zav0},	//(internal1_m574_Zav0)  - Зад.аварийный выключатель механизма
	{ 933	,1	,1	, &internal1_m574_Pv0},	//(internal1_m574_Pv0)  - Пер. выключатель механизма
	{ 934	,1	,1	, &internal1_m574_Zv0},	//(internal1_m574_Zv0)  - Зад. выключатель механизма
	{ 935	,1	,1	, &internal1_m574_RA00},	//(internal1_m574_RA00)  - последнее задание вперед
	{ 936	,1	,1	, &internal1_m574_RA10},	//(internal1_m574_RA10)  - последнее задание назад
	{ 937	,1	,1	, &internal1_m574_MyFirstEnterFlag},	//(internal1_m574_MyFirstEnterFlag) MyFirstEnterFlag
	{ 938	,8	,1	, &internal1_m433_X0},	//(internal1_m433_X0)  - координата механизма
	{ 939	,8	,1	, &internal1_m433_V0},	//(internal1_m433_V0)  - скорость механизма
	{ 940	,1	,1	, &internal1_m433_Pav0},	//(internal1_m433_Pav0)  - Пер.аварийный выключатель механизма
	{ 941	,1	,1	, &internal1_m433_Zav0},	//(internal1_m433_Zav0)  - Зад.аварийный выключатель механизма
	{ 942	,1	,1	, &internal1_m433_Pv0},	//(internal1_m433_Pv0)  - Пер. выключатель механизма
	{ 943	,1	,1	, &internal1_m433_Zv0},	//(internal1_m433_Zv0)  - Зад. выключатель механизма
	{ 944	,1	,1	, &internal1_m433_RA00},	//(internal1_m433_RA00)  - последнее задание вперед
	{ 945	,1	,1	, &internal1_m433_RA10},	//(internal1_m433_RA10)  - последнее задание назад
	{ 946	,1	,1	, &internal1_m433_MyFirstEnterFlag},	//(internal1_m433_MyFirstEnterFlag) MyFirstEnterFlag
	{ 947	,8	,1	, &internal1_m420_X0},	//(internal1_m420_X0)  - координата механизма
	{ 948	,8	,1	, &internal1_m420_V0},	//(internal1_m420_V0)  - скорость механизма
	{ 949	,1	,1	, &internal1_m420_Pav0},	//(internal1_m420_Pav0)  - Пер.аварийный выключатель механизма
	{ 950	,1	,1	, &internal1_m420_Zav0},	//(internal1_m420_Zav0)  - Зад.аварийный выключатель механизма
	{ 951	,1	,1	, &internal1_m420_Pv0},	//(internal1_m420_Pv0)  - Пер. выключатель механизма
	{ 952	,1	,1	, &internal1_m420_Zv0},	//(internal1_m420_Zv0)  - Зад. выключатель механизма
	{ 953	,1	,1	, &internal1_m420_RA00},	//(internal1_m420_RA00)  - последнее задание вперед
	{ 954	,1	,1	, &internal1_m420_RA10},	//(internal1_m420_RA10)  - последнее задание назад
	{ 955	,1	,1	, &internal1_m420_MyFirstEnterFlag},	//(internal1_m420_MyFirstEnterFlag) MyFirstEnterFlag
	{ 956	,8	,1	, &internal1_m492_X0},	//(internal1_m492_X0)  - координата механизма
	{ 957	,8	,1	, &internal1_m492_V0},	//(internal1_m492_V0)  - скорость механизма
	{ 958	,1	,1	, &internal1_m492_Pav0},	//(internal1_m492_Pav0)  - Пер.аварийный выключатель механизма
	{ 959	,1	,1	, &internal1_m492_Zav0},	//(internal1_m492_Zav0)  - Зад.аварийный выключатель механизма
	{ 960	,1	,1	, &internal1_m492_Pv0},	//(internal1_m492_Pv0)  - Пер. выключатель механизма
	{ 961	,1	,1	, &internal1_m492_Zv0},	//(internal1_m492_Zv0)  - Зад. выключатель механизма
	{ 962	,1	,1	, &internal1_m492_RA00},	//(internal1_m492_RA00)  - последнее задание вперед
	{ 963	,1	,1	, &internal1_m492_RA10},	//(internal1_m492_RA10)  - последнее задание назад
	{ 964	,1	,1	, &internal1_m492_MyFirstEnterFlag},	//(internal1_m492_MyFirstEnterFlag) MyFirstEnterFlag
	{ 965	,8	,1	, &internal1_m373_X0},	//(internal1_m373_X0)  - координата механизма
	{ 966	,8	,1	, &internal1_m373_V0},	//(internal1_m373_V0)  - скорость механизма
	{ 967	,1	,1	, &internal1_m373_Pav0},	//(internal1_m373_Pav0)  - Пер.аварийный выключатель механизма
	{ 968	,1	,1	, &internal1_m373_Zav0},	//(internal1_m373_Zav0)  - Зад.аварийный выключатель механизма
	{ 969	,1	,1	, &internal1_m373_Pv0},	//(internal1_m373_Pv0)  - Пер. выключатель механизма
	{ 970	,1	,1	, &internal1_m373_Zv0},	//(internal1_m373_Zv0)  - Зад. выключатель механизма
	{ 971	,1	,1	, &internal1_m373_RA00},	//(internal1_m373_RA00)  - последнее задание вперед
	{ 972	,1	,1	, &internal1_m373_RA10},	//(internal1_m373_RA10)  - последнее задание назад
	{ 973	,1	,1	, &internal1_m373_MyFirstEnterFlag},	//(internal1_m373_MyFirstEnterFlag) MyFirstEnterFlag
	{ 974	,8	,1	, &internal1_m359_X0},	//(internal1_m359_X0)  - координата механизма
	{ 975	,8	,1	, &internal1_m359_V0},	//(internal1_m359_V0)  - скорость механизма
	{ 976	,1	,1	, &internal1_m359_Pav0},	//(internal1_m359_Pav0)  - Пер.аварийный выключатель механизма
	{ 977	,1	,1	, &internal1_m359_Zav0},	//(internal1_m359_Zav0)  - Зад.аварийный выключатель механизма
	{ 978	,1	,1	, &internal1_m359_Pv0},	//(internal1_m359_Pv0)  - Пер. выключатель механизма
	{ 979	,1	,1	, &internal1_m359_Zv0},	//(internal1_m359_Zv0)  - Зад. выключатель механизма
	{ 980	,1	,1	, &internal1_m359_RA00},	//(internal1_m359_RA00)  - последнее задание вперед
	{ 981	,1	,1	, &internal1_m359_RA10},	//(internal1_m359_RA10)  - последнее задание назад
	{ 982	,1	,1	, &internal1_m359_MyFirstEnterFlag},	//(internal1_m359_MyFirstEnterFlag) MyFirstEnterFlag
	{ 983	,8	,1	, &internal1_m344_X0},	//(internal1_m344_X0)  - координата механизма
	{ 984	,8	,1	, &internal1_m344_V0},	//(internal1_m344_V0)  - скорость механизма
	{ 985	,1	,1	, &internal1_m344_Pav0},	//(internal1_m344_Pav0)  - Пер.аварийный выключатель механизма
	{ 986	,1	,1	, &internal1_m344_Zav0},	//(internal1_m344_Zav0)  - Зад.аварийный выключатель механизма
	{ 987	,1	,1	, &internal1_m344_Pv0},	//(internal1_m344_Pv0)  - Пер. выключатель механизма
	{ 988	,1	,1	, &internal1_m344_Zv0},	//(internal1_m344_Zv0)  - Зад. выключатель механизма
	{ 989	,1	,1	, &internal1_m344_RA00},	//(internal1_m344_RA00)  - последнее задание вперед
	{ 990	,1	,1	, &internal1_m344_RA10},	//(internal1_m344_RA10)  - последнее задание назад
	{ 991	,1	,1	, &internal1_m344_MyFirstEnterFlag},	//(internal1_m344_MyFirstEnterFlag) MyFirstEnterFlag
	{ 992	,8	,1	, &internal1_m1119_X0},	//(internal1_m1119_X0)  - координата механизма
	{ 993	,8	,1	, &internal1_m1119_V0},	//(internal1_m1119_V0)  - скорость механизма
	{ 994	,1	,1	, &internal1_m1119_Pav0},	//(internal1_m1119_Pav0)  - Пер.аварийный выключатель механизма
	{ 995	,1	,1	, &internal1_m1119_Zav0},	//(internal1_m1119_Zav0)  - Зад.аварийный выключатель механизма
	{ 996	,1	,1	, &internal1_m1119_Pv0},	//(internal1_m1119_Pv0)  - Пер. выключатель механизма
	{ 997	,1	,1	, &internal1_m1119_Zv0},	//(internal1_m1119_Zv0)  - Зад. выключатель механизма
	{ 998	,1	,1	, &internal1_m1119_RA00},	//(internal1_m1119_RA00)  - последнее задание вперед
	{ 999	,1	,1	, &internal1_m1119_RA10},	//(internal1_m1119_RA10)  - последнее задание назад
	{ 1000	,1	,1	, &internal1_m1119_MyFirstEnterFlag},	//(internal1_m1119_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1001	,8	,1	, &internal1_m166_C1},	//(internal1_m166_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	{ 1002	,8	,1	, &internal1_m166_C2},	//(internal1_m166_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	{ 1003	,8	,1	, &internal1_m166_C3},	//(internal1_m166_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	{ 1004	,8	,1	, &internal1_m166_C4},	//(internal1_m166_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	{ 1005	,8	,1	, &internal1_m166_C5},	//(internal1_m166_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	{ 1006	,8	,1	, &internal1_m166_C6},	//(internal1_m166_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	{ 1007	,8	,1	, &internal1_m166_N0},	//(internal1_m166_N0) N0 - пред. концентрация нейтронов
	{ 1008	,8	,1	, &internal1_m166_N20},	//(internal1_m166_N20) N20 - пред. концентрация нейтронов второй АЗ
	{ 1009	,8	,1	, &internal1_m166_R0},	//(internal1_m166_R0) R0 - пред. реактивность
	{ 1010	,8	,1	, &internal1_m166_T0},	//(internal1_m166_T0) T0 - пред. температура
	{ 1011	,8	,6	, &internal1_m166_C0},	//(internal1_m166_C0) *C0 - пред. концентрация запаздывающих нейтронов
	{ 1012	,1	,1	, &internal1_m166_ImpINI0},	//(internal1_m166_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	{ 1013	,1	,1	, &internal1_m166_MyFirstEnterFlag},	//(internal1_m166_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1014	,8	,1	, &internal1_m274_X0},	//(internal1_m274_X0) X0 - координата ОРР
	{ 1015	,8	,1	, &internal1_m274_Sh0},	//(internal1_m274_Sh0) Sh0 - координата штока ОРР
	{ 1016	,8	,1	, &internal1_m274_RV0},	//(internal1_m274_RV0) V0 - текущая скорость ОРР
	{ 1017	,8	,1	, &internal1_m274_ShV0},	//(internal1_m274_ShV0) V0 - текущая скорость штока ОРР
	{ 1018	,1	,1	, &internal1_m274_Ppv0},	//(internal1_m274_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 1019	,1	,1	, &internal1_m274_Pav0},	//(internal1_m274_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 1020	,1	,1	, &internal1_m274_Zav0},	//(internal1_m274_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 1021	,1	,1	, &internal1_m274_RA00},	//(internal1_m274_RA00) RA00 - последнее задание вперед
	{ 1022	,1	,1	, &internal1_m274_RA10},	//(internal1_m274_RA10) RA10 - последнее задание назад
	{ 1023	,18	,1	, &internal1_m274_RA50},	//(internal1_m274_RA50) Ra50 - последнее задание скорости
	{ 1024	,1	,1	, &internal1_m274_fls},	//(internal1_m274_fls)  fls - флаг одношагового режима
	{ 1025	,1	,1	, &internal1_m274_flp},	//(internal1_m274_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1026	,1	,1	, &internal1_m274_MyFirstEnterFlag},	//(internal1_m274_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1027	,8	,1	, &internal1_m120_X0},	//(internal1_m120_X0) X0 - координата ОРР
	{ 1028	,8	,1	, &internal1_m120_Sh0},	//(internal1_m120_Sh0) Sh0 - координата штока ОРР
	{ 1029	,8	,1	, &internal1_m120_RV0},	//(internal1_m120_RV0) V0 - текущая скорость ОРР
	{ 1030	,8	,1	, &internal1_m120_ShV0},	//(internal1_m120_ShV0) V0 - текущая скорость штока ОРР
	{ 1031	,1	,1	, &internal1_m120_Ppv0},	//(internal1_m120_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 1032	,1	,1	, &internal1_m120_Pav0},	//(internal1_m120_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 1033	,1	,1	, &internal1_m120_Zav0},	//(internal1_m120_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 1034	,1	,1	, &internal1_m120_RA00},	//(internal1_m120_RA00) RA00 - последнее задание вперед
	{ 1035	,1	,1	, &internal1_m120_RA10},	//(internal1_m120_RA10) RA10 - последнее задание назад
	{ 1036	,18	,1	, &internal1_m120_RA50},	//(internal1_m120_RA50) Ra50 - последнее задание скорости
	{ 1037	,1	,1	, &internal1_m120_fls},	//(internal1_m120_fls)  fls - флаг одношагового режима
	{ 1038	,1	,1	, &internal1_m120_flp},	//(internal1_m120_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1039	,1	,1	, &internal1_m120_MyFirstEnterFlag},	//(internal1_m120_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1040	,8	,1	, &internal1_m247_X0},	//(internal1_m247_X0) X0 - координата ОРР
	{ 1041	,8	,1	, &internal1_m247_Sh0},	//(internal1_m247_Sh0) Sh0 - координата штока ОРР
	{ 1042	,8	,1	, &internal1_m247_RV0},	//(internal1_m247_RV0) V0 - текущая скорость ОРР
	{ 1043	,8	,1	, &internal1_m247_ShV0},	//(internal1_m247_ShV0) V0 - текущая скорость штока ОРР
	{ 1044	,1	,1	, &internal1_m247_Ppv0},	//(internal1_m247_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 1045	,1	,1	, &internal1_m247_Pav0},	//(internal1_m247_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 1046	,1	,1	, &internal1_m247_Zav0},	//(internal1_m247_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 1047	,1	,1	, &internal1_m247_RA00},	//(internal1_m247_RA00) RA00 - последнее задание вперед
	{ 1048	,1	,1	, &internal1_m247_RA10},	//(internal1_m247_RA10) RA10 - последнее задание назад
	{ 1049	,18	,1	, &internal1_m247_RA50},	//(internal1_m247_RA50) Ra50 - последнее задание скорости
	{ 1050	,1	,1	, &internal1_m247_fls},	//(internal1_m247_fls)  fls - флаг одношагового режима
	{ 1051	,1	,1	, &internal1_m247_flp},	//(internal1_m247_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1052	,1	,1	, &internal1_m247_MyFirstEnterFlag},	//(internal1_m247_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1053	,8	,1	, &internal1_m90_X0},	//(internal1_m90_X0) X0 - координата ОРР
	{ 1054	,8	,1	, &internal1_m90_Sh0},	//(internal1_m90_Sh0) Sh0 - координата штока ОРР
	{ 1055	,8	,1	, &internal1_m90_RV0},	//(internal1_m90_RV0) V0 - текущая скорость ОРР
	{ 1056	,8	,1	, &internal1_m90_ShV0},	//(internal1_m90_ShV0) V0 - текущая скорость штока ОРР
	{ 1057	,1	,1	, &internal1_m90_Ppv0},	//(internal1_m90_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 1058	,1	,1	, &internal1_m90_Pav0},	//(internal1_m90_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 1059	,1	,1	, &internal1_m90_Zav0},	//(internal1_m90_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 1060	,1	,1	, &internal1_m90_RA00},	//(internal1_m90_RA00) RA00 - последнее задание вперед
	{ 1061	,1	,1	, &internal1_m90_RA10},	//(internal1_m90_RA10) RA10 - последнее задание назад
	{ 1062	,18	,1	, &internal1_m90_RA50},	//(internal1_m90_RA50) Ra50 - последнее задание скорости
	{ 1063	,1	,1	, &internal1_m90_fls},	//(internal1_m90_fls)  fls - флаг одношагового режима
	{ 1064	,1	,1	, &internal1_m90_flp},	//(internal1_m90_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1065	,1	,1	, &internal1_m90_MyFirstEnterFlag},	//(internal1_m90_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1066	,8	,1	, &internal1_m211_X0},	//(internal1_m211_X0) X0 - координата ОРР
	{ 1067	,8	,1	, &internal1_m211_Sh0},	//(internal1_m211_Sh0) Sh0 - координата штока ОРР
	{ 1068	,8	,1	, &internal1_m211_RV0},	//(internal1_m211_RV0) V0 - текущая скорость ОРР
	{ 1069	,8	,1	, &internal1_m211_ShV0},	//(internal1_m211_ShV0) V0 - текущая скорость штока ОРР
	{ 1070	,1	,1	, &internal1_m211_Ppv0},	//(internal1_m211_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 1071	,1	,1	, &internal1_m211_Pav0},	//(internal1_m211_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 1072	,1	,1	, &internal1_m211_Zav0},	//(internal1_m211_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 1073	,1	,1	, &internal1_m211_RA00},	//(internal1_m211_RA00) RA00 - последнее задание вперед
	{ 1074	,1	,1	, &internal1_m211_RA10},	//(internal1_m211_RA10) RA10 - последнее задание назад
	{ 1075	,18	,1	, &internal1_m211_RA50},	//(internal1_m211_RA50) Ra50 - последнее задание скорости
	{ 1076	,1	,1	, &internal1_m211_fls},	//(internal1_m211_fls)  fls - флаг одношагового режима
	{ 1077	,1	,1	, &internal1_m211_flp},	//(internal1_m211_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1078	,1	,1	, &internal1_m211_MyFirstEnterFlag},	//(internal1_m211_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1079	,8	,1	, &internal1_m58_X0},	//(internal1_m58_X0) X0 - координата ОРР
	{ 1080	,8	,1	, &internal1_m58_Sh0},	//(internal1_m58_Sh0) Sh0 - координата штока ОРР
	{ 1081	,8	,1	, &internal1_m58_RV0},	//(internal1_m58_RV0) V0 - текущая скорость ОРР
	{ 1082	,8	,1	, &internal1_m58_ShV0},	//(internal1_m58_ShV0) V0 - текущая скорость штока ОРР
	{ 1083	,1	,1	, &internal1_m58_Ppv0},	//(internal1_m58_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 1084	,1	,1	, &internal1_m58_Pav0},	//(internal1_m58_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 1085	,1	,1	, &internal1_m58_Zav0},	//(internal1_m58_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 1086	,1	,1	, &internal1_m58_RA00},	//(internal1_m58_RA00) RA00 - последнее задание вперед
	{ 1087	,1	,1	, &internal1_m58_RA10},	//(internal1_m58_RA10) RA10 - последнее задание назад
	{ 1088	,18	,1	, &internal1_m58_RA50},	//(internal1_m58_RA50) Ra50 - последнее задание скорости
	{ 1089	,1	,1	, &internal1_m58_fls},	//(internal1_m58_fls)  fls - флаг одношагового режима
	{ 1090	,1	,1	, &internal1_m58_flp},	//(internal1_m58_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1091	,1	,1	, &internal1_m58_MyFirstEnterFlag},	//(internal1_m58_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1092	,8	,1	, &internal1_m13_C1},	//(internal1_m13_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	{ 1093	,8	,1	, &internal1_m13_C2},	//(internal1_m13_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	{ 1094	,8	,1	, &internal1_m13_C3},	//(internal1_m13_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	{ 1095	,8	,1	, &internal1_m13_C4},	//(internal1_m13_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	{ 1096	,8	,1	, &internal1_m13_C5},	//(internal1_m13_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	{ 1097	,8	,1	, &internal1_m13_C6},	//(internal1_m13_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	{ 1098	,8	,1	, &internal1_m13_N0},	//(internal1_m13_N0) N0 - пред. концентрация нейтронов
	{ 1099	,8	,1	, &internal1_m13_N20},	//(internal1_m13_N20) N20 - пред. концентрация нейтронов второй АЗ
	{ 1100	,8	,1	, &internal1_m13_R0},	//(internal1_m13_R0) R0 - пред. реактивность
	{ 1101	,8	,1	, &internal1_m13_T0},	//(internal1_m13_T0) T0 - пред. температура
	{ 1102	,8	,6	, &internal1_m13_C0},	//(internal1_m13_C0) *C0 - пред. концентрация запаздывающих нейтронов
	{ 1103	,1	,1	, &internal1_m13_ImpINI0},	//(internal1_m13_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	{ 1104	,1	,1	, &internal1_m13_MyFirstEnterFlag},	//(internal1_m13_MyFirstEnterFlag) MyFirstEnterFlag
	{-1,0,NULL},
};
static char NameSaveFile[]="scm.bin\0";   // Имя файла для сохранения констант
#pragma pop
static short saveVariables[]={      // Id переменных для сохранения
333,334,335,336,337,338,339,340,341,342,343,344,345,346,347,348,349,350,351,352,353,354,355,356,357,358,359,360,361,362,363,364,365,366,367,368,369,370,371,372,373,374,375,376,377,378,379,380,381,382,383,384,385,386,387,388,389,390,391,392,393,394,395,396,397,398,399,400,401,402,403,404,405,406,407,408,409,410,411,412,413,414,415,416,417,418,419,420,421,422,423,424,425,426,427,428,429,430,431,432,433,434,435,436,437,438,439,440,441,442,443,444,445,446,447,448,449,450,451,452,453,454,455,456,457,458,459,460,461,462,463,464,465,466,467,468,469,470,471,472,473,474,475,476,477,478,479,480,481,482,483,484,485,486,487,488,489,490,491,492,493,494,495,496,497,498,499,500,501,502,503,504,505,506,507,508,509,510,511,512,513,514,515,516,517,518,519,520,521,522,523,524,525,526,527,528,529,530,531,532,533,534,535,536,537,538,539,540,541,542,543,544,545,546,547,548,549,550,551,552,553,554,555,556,557,558,559,560,561,562,563,564,565,566,567,568,569,570,571,572,573,574,575,576,577,578,579,580,581,582,583,584,585,586,587,588,589,590,591,592,593,594,595,596,597,598,599,600,601,602,603,604,605,606,607,608,609,610,611,612,613,614,615,616,617,618,619,620,621,622,623,624,625,626,627,628,629,630,631,632,633,634,635,636,637,638,639,640,641,642,643,644,645,646,647,648,649,650,651,652,653,654,655,656,657,658,659,660,661,662,663,664,665,666,667,668,669,670,671,672,673,674,675,676,677,678,679,680,681,682,683,684,685,686,687,-1,};
#pragma pack(push,1)
static ModbusRegister coil_SCM[]={  // 
	{&R0AD14LDU,1,0},	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
	{&C2MD31LP1,1,1},	//(C2MD31LP1) Кнопка «СБРОС РБ»
	{&C1MD31LP2,1,2},	//(C1MD31LP2) Кнопка «СБРОС ББ»  на ОПУ2
	{&C1MD31LP1,1,3},	//(C1MD31LP1) Кнопка «СБРОС ББ»  на ОПУ1
	{&R0MW13LP2,1,4},	//(R0MW13LP2) Переключатель «СЕТЬ»
	{&lEM_R5AD10LC1,1,5},	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
	{&lEM_R6AD10LC1,1,6},	//(R6AD10LC1) Выкатить кран-балку от ИС
	{&lEM_R3AD21LC1,1,7},	//(R3AD21LC1) Гомогенные двери-2 закрыть от ИС
	{&lEM_R3AD11LC1,1,8},	//(R3AD11LC1) Гомогенные двери-2 открыть от ИС
	{&lEM_R3AD20LC1,1,9},	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
	{&lEM_R3AD10LC1,1,10},	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
	{&lEM_R8AD10LC1,1,11},	//(R8AD10LC1) Установить аварийный НИ от ИС
	{&lEM_R5AD20LC1,1,12},	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
	{&lEM_A0EE04LC1,1,13},	//(A0EE04LC1) Исправность АКНП2 от диагностики контроллера (От ИС)
	{&lEM_A0EE03LC1,1,14},	//(A0EE03LC1) Исправность АКНП1 от диагностики контроллера (От ИС)
	{&lEM_A0EE05LC1,1,15},	//(A0EE05LC1) Исправность АКНП3 от диагностики контроллера (От ИС)
	{&lEM_A0EE06LC1,1,16},	//(A0EE06LC1) Исправность АКНП4 от диагностики контроллера (От ИС)
	{&lEM_R0IE02LRP,1,17},	//(R0IE02LRP) Отключить питание ПР, ПУ
	{&lEM_R0IE01LRP,1,18},	//(R0IE01LRP) Отключение питание детекторов
	{&lEM_C1AD31LRP,1,19},	//(C1AD31LRP) Общий сброс от РПУ
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SCM[]={  // 
	{&R0IE11LS3,1,0},	//(R0IE11LS3) Исправность ВИП 1,6 (№14) СНМ11 3канала
	{&R0IE12LS4,1,1},	//(R0IE12LS4) Исправность ВИП 0,5 (№18) КНК15-1 4канала
	{&R0IE13LS4,1,2},	//(R0IE13LS4) Исправность ВИП 0,5 (№19) КНК53М 4канала
	{&R0IE11LS4,1,3},	//(R0IE11LS4) Исправность ВИП 1,6 (№17) СНМ11 4канала
	{&A1IS11LIM,1,4},	//(A1IS11LIM) Магнит ББ1 обесточен
	{&A1IS32LIM,1,5},	//(A1IS32LIM) Клапан cброса ББ1 открыт(обесточен)
	{&B1IS11LIM,1,6},	//(B1IS11LIM) Магнит ББ2 обесточен
	{&B1IS32LIM,1,7},	//(B1IS32LIM) Клапан cброса ББ2 открыт(обесточен)
	{&A2IS11LIM,1,8},	//(A2IS11LIM) Магнит РБ1 обесточен
	{&A2IS32LIM,1,9},	//(A2IS32LIM) Клапан cброса РБ1 открыт(обесточен)
	{&B2IS11LIM,1,10},	//(B2IS11LIM) Магнит РБ2 обесточен
	{&B2IS32LIM,1,11},	//(B2IS32LIM) Клапан cброса РБ2 открыт(обесточен)
	{&R0IE11LS1,1,12},	//(R0IE11LS1) Исправность ВИП 1,6 (№8) СНМ11 1канала
	{&R0IE12LS1,1,13},	//(R0IE12LS1) Исправность ВИП 0,5 (№9) КНК15-1 1канала
	{&R0IE13LS1,1,14},	//(R0IE13LS1) Исправность ВИП 0,5 (№10) КНК53М 1канала
	{&R0IE12LS2,1,15},	//(R0IE12LS2) Исправность ВИП 0,5 (№12) КНК15-1 2канала
	{&R0IE13LS2,1,16},	//(R0IE13LS2) Исправность ВИП 0,5 (№13) КНК53М 2канала
	{&R0IE11LS2,1,17},	//(R0IE11LS2) Исправность ВИП 1,6 (№11) СНМ11 2канала
	{&R0IE12LS3,1,18},	//(R0IE12LS3) Исправность ВИП 0,5 (№15) КНК15-1 3канала
	{&R0IE13LS3,1,19},	//(R0IE13LS3) Исправность ВИП 0,5 (№16) КНК53М 3канала
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
	{&A2MC01RC1,8,0},	//(A2MC01RC1) Заданная координата РБ1 от ИС
	{&A2MV01RC1,8,2},	//(A2MV01RC1) Заданная скорость движения ББ1 от ИС
	{&iEM_TERR7SI74RIM,3,4},	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
	{&iEM_TERR6IS68LIM,3,5},	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
	{&iEM_TERR0VP82LIM,3,6},	//(TERR0VP82LIM) Искажение: Давление  в СИСТЕМЕ-2 в норме
	{&iEM_TERR0VP81LIM,3,7},	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ в норме
	{&iEM_TERB0VP81LIM,3,8},	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
	{&iEM_TERA0VP81LIM,3,9},	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
	{&iEM_TERR6IS67LIM,3,10},	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
	{&iEM_TERR6IS66LIM,3,11},	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{&iEM_TERR6IS62LIM,3,12},	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39 1канал
	{&iEM_TERA3SP02RIM,3,13},	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{&iEM_TERA3SS22LIM,3,14},	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
	{&iEM_TERB3SS22LIM,3,15},	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
	{&iEM_TERR6IS64LIM,3,16},	//(TERR6IS64LIM) Исправность ВИП ССДИ-35 1канал
	{&iEM_TERB3SS11LIM,3,17},	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
	{&iEM_TERA3SS11LIM,3,18},	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
	{&iEM_TERB3SC01RIM,3,19},	//(TERB3SC01RIM) Искажение: Координата штока ИС2
	{&iEM_TERB3SS33LIM,3,20},	//(TERB3SS33LIM) скажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{&iEM_TERB3SS31LIM,3,21},	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{&iEM_TERA3SS31LIM,3,22},	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{&iEM_TERA3SS33LIM,3,23},	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{&iEM_TERA3SS21LIM,3,24},	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
	{&iEM_TERA2SS33LIM,3,25},	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{&iEM_TERB6SS21LIM,3,26},	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
	{&iEM_TERR5SS21LIM,3,27},	//(TERR5SS21LIM) Искажение: Приход на НУ РБ2
	{&iEM_TERB4SS21LIM,3,28},	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
	{&iEM_TERA4VP82LIM,3,29},	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
	{&iEM_TERR2SS21LIM,3,30},	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
	{&iEM_TERR2SS11LIM,3,31},	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
	{&iEM_TERR1SS21LIM,3,32},	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
	{&iEM_TERR1SS11LIM,3,33},	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
	{&iEM_TERA4SS11LIM,3,34},	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
	{&iEM_TERR3SS22LIM,3,35},	//(TERR3SS22LIM) Искажение: Приход на НУ гомогенных дверей-2
	{&iEM_TERR3SS12LIM,3,36},	//(TERR3SS12LIM) Искажение: Приход на ВУ гомогенных дверей-2
	{&iEM_TERR5SS11LIM,3,37},	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
	{&iEM_TERR3SS21LIM,3,38},	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
	{&iEM_TERB2SC01RIM,3,39},	//(TERB2SC01RIM) Искажение: Координата штока РБ2
	{&iEM_TERR3SS11LIM,3,40},	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
	{&iEM_TERB2SS21LIM,3,41},	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
	{&iEM_TERB2SS12LIM,3,42},	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
	{&iEM_TERB2SS11LIM,3,43},	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
	{&iEM_TERA9SS11LIM,3,44},	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
	{&iEM_TERA5SS11LIM,3,45},	//(TERA5SS11LIM) Искажение: Приход на ВУ НЛ1
	{&iEM_TERB5SS11LIM,3,46},	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
	{&iEM_TERA5SS21LIM,3,47},	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
	{&fEM_B1MC01RC1,8,48},	//(B1MC01RC1) Заданная координата ББ2 от ИС
	{&iEM_TERB1IE04LDU,3,50},	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
	{&iEM_TERB1IE03LDU,3,51},	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
	{&fEM_A1MC01RC1,8,52},	//(A1MC01RC1) Заданная координата  ББ1 от ИС
	{&iEM_TERA1IE03LDU,3,54},	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
	{&iEM_TERA1IE04LDU,3,55},	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
	{&iEM_TERAZ2,3,56},	//(TERAZ2) Неисправности АЗ2
	{&iEM_TERAZ1,3,57},	//(TERAZ1) Неисправности АЗ1
	{&fEM_A3MV02RC1,8,58},	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
	{&fEM_A3MC02RC1,8,60},	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
	{&iEM_TERIS1,3,62},	//(TERIS1) Неисправности  ИС1
	{&fEM_B3MV02RC1,8,63},	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
	{&fEM_B3MC02RC1,8,65},	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
	{&iEM_TERIS2,3,67},	//(TERIS2) Неисправности  ИС2
	{&fEM_A2MV02RC1,8,68},	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
	{&fEM_A2MC02RC1,8,70},	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
	{&iEM_TERRB1,3,72},	//(TERRB1) Неисправности  РБ1
	{&fEM_B2MV02RC1,8,73},	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
	{&fEM_B2MC02RC1,8,75},	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
	{&iEM_TERRB2,3,77},	//(TERRB2) Неисправности  РБ2
	{&fEM_B1MV02RC1,8,78},	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
	{&fEM_B1MC02RC1,8,80},	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
	{&iEM_TERA2SC01RIM,3,82},	//(TERA2SC01RIM) Искажение: Координата штока РБ1
	{&iEM_TERA3VP81LIM,3,83},	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
	{&iEM_TERA3SC01RIM,3,84},	//(TERA3SC01RIM) Искажение: Координата штока ИС1
	{&iEM_TERB3SP02RIM,3,85},	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{&iEM_TERB2SP01RIM,3,86},	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
	{&iEM_TERA2SP01RIM,3,87},	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
	{&iEM_TERB0MT01RIM,3,88},	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
	{&iEM_TERA0MT01RIM,3,89},	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
	{&iEM_TERB3SS21LIM,3,90},	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
	{&iEM_TERA2SS11LIM,3,91},	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
	{&iEM_TERA2VP82LIM,3,92},	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
	{&iEM_TERR6SS21LIM,3,93},	//(TERR6SS21LIM) Искажение: Приход на НУ кран-балки
	{&iEM_TERA2SS12LIM,3,94},	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
	{&iEM_TERA2SS21LIM,3,95},	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
	{&iEM_TERA7MS31DIM,3,96},	//(TERA7MS31DIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{&fEM_B3MV01RC1,8,97},	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
	{&fEM_B3MC01RC1,8,99},	//(B3MC01RC1) Заданная координата ИС2 от ИС
	{&fEM_A3MV01RC1,8,101},	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
	{&fEM_A3MC01RC1,8,103},	//(A3MC01RC1) Заданная координата ИС1 от ИС
	{&fEM_B2MV01RC1,8,105},	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
	{&fEM_B2MC01RC1,8,107},	//(B2MC01RC1) Заданная координата РБ2 от ИС
	{&fEM_B1MV01RC1,8,109},	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
	{&iEM_TERR5AD20LDU,3,111},	//(TERR5AD20LDU) Искажение: Закрыть ворота отстойной зоны
	{&iEM_TERR5AD10LDU,3,112},	//(TERR5AD10LDU) Искажение: Открыть ворота отстойной зоны
	{&iEM_TERR3AD21LDU,3,113},	//(TERR3AD21LDU) Искажение: Гомогенные двери-2 закрыть
	{&iEM_TERR3AD11LDU,3,114},	//(TERR3AD11LDU) Искажение: Гомогенные двери-2 открыть
	{&iEM_TERR3AD20LDU,3,115},	//(TERR3AD20LDU) Искажение: Гомогенные двери-1 закрыть
	{&iEM_TERR3AD10LDU,3,116},	//(TERR3AD10LDU) Искажение: Гомогенные двери-1 открыть
	{&fEM_B6MV01RC1,8,117},	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
	{&fEM_B6MC01RC1,8,119},	//(B6MC01RC1) Заданная координата БЗ2 от ИС
	{&iEM_TERBZ2,3,121},	//(TERBZ2) Неисправности БЗ2
	{&fEM_A6MV01RC1,8,122},	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
	{&fEM_A6MC01RC1,8,124},	//(A6MC01RC1) Заданная координата БЗ1 от ИС
	{&iEM_TERBZ1,3,126},	//(TERBZ1) Неисправности БЗ1
	{&fEM_A8MV01RC1,8,127},	//(A8MV01RC1) Заданная скорость ДС2 от ИС
	{&fEM_A8MC01RC1,8,129},	//(A8MC01RC1) Заданная координата ДС2 от ИС
	{&iEM_TERDS2,3,131},	//(TERDS2) Неисправности ДС2 от ИС
	{&fEM_B8MV01RC1,8,132},	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
	{&iEM_TERB1VP81LIM,3,134},	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
	{&iEM_TERA1VP81LIM,3,135},	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
	{&iEM_TERB2SS33LIM,3,136},	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{&fEM_R0UL03RSS,8,137},	//(R0UL03RSS) Предельное время ожидания роста потока (сек)
	{&fEM_R0UL01RSS,8,139},	//(R0UL01RSS) Шаг (мс) измерения периода
	{&fEM_A3UC08RIM,8,141},	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
	{&fEM_A2UC08RIM,8,143},	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
	{&fEM_A1UC08RIM,8,145},	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
	{&fEM_B5MV01RC1,8,147},	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
	{&fEM_B5MC01RC1,8,149},	//(B5MC01RC1) Заданная координата НЛ2 от ИС
	{&iEM_TERNL2,3,151},	//(TERNL2) Неисправности НЛ2
	{&fEM_A5MV01RC1,8,152},	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
	{&fEM_A5MC01RC1,8,154},	//(A5MC01RC1) Заданная координата НЛ1 от ИС
	{&iEM_TERNL1,3,156},	//(TERNL1) Неисправности НЛ1
	{&fEM_R1MV01RC1,8,157},	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
	{&fEM_R1MC01RC1,8,159},	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
	{&iEM_TERMDZ1,3,161},	//(TERMDZ1) Неисправности МДЗ1
	{&fEM_R2MV01RC1,8,162},	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
	{&fEM_R2MC01RC1,8,164},	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
	{&iEM_TERMDZ2,3,166},	//(TERMDZ2) Неисправности МДЗ2
	{&iEM_TERA1SS11LIM,3,167},	//(TERA1SS11LIM) Искажение: Приход на НУ РБ2
	{&iEM_TERA1SS21LIM,3,168},	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
	{&iEM_TERB5SS21LIM,3,169},	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
	{&iEM_TERB9SS11LIM,3,170},	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
	{&iEM_TERB9SS21LIM,3,171},	//(TERB9SS21LIM) Искажение: Приход на НУ РБ2
	{&iEM_TERA9SS21LIM,3,172},	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
	{&iEM_TERA8SS22LIM,3,173},	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
	{&iEM_TERB8SS22LIM,3,174},	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
	{&iEM_TERA8SS12LIM,3,175},	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
	{&iEM_TERB8SS12LIM,3,176},	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
	{&iEM_TERA8SC01RIM,3,177},	//(TERA8SC01RIM) Искажение: Координата ДС2
	{&iEM_TERB8SC01RIM,3,178},	//(TERB8SC01RIM) Искажение: Координата АЗ2
	{&iEM_TERR8SS11LIM,3,179},	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
	{&iEM_TERR4SS22LIM,3,180},	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
	{&iEM_TERR4SS12LIM,3,181},	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
	{&iEM_TERR4MS21LIM,3,182},	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
	{&iEM_TERR4SS11LIM,3,183},	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
	{&iEM_TERB6SS11LIM,3,184},	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
	{&iEM_TERA6SS21LIM,3,185},	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
	{&iEM_TERA6MS11LIM,3,186},	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
	{&iEM_TERA4SS21LIM,3,187},	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
	{&iEM_TERB4SS11LIM,3,188},	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
	{&fEM_B8MC01RC1,8,189},	//(B8MC01RC1) аданная координата АЗ2 от ИС
	{&iEM_TERMAZ2,3,191},	//(TERMAZ2) Неисправности АЗ2 от ИС
	{&fEM_R4MV01RC1,8,192},	//(R4MV01RC1) Заданная скорость тележки от ИС
	{&fEM_R4MC01RC1,8,194},	//(R4MC01RC1) Заданная координата тележки от ИС
	{&iEM_TERTLG,3,196},	//(TERTLG) Неисправности  тележки от ИС
	{&iEM_TERR0IE21LIM,3,197},	//(TERR0IE21LIM) Искажение: Исправность ВИП 1,6 (№11) СНМ11 2канала
	{&iEM_TERR0IE23LIM,3,198},	//(TERR0IE23LIM) Искажение: Исправность ВИП 0,5 (№13) КНК53М 2канала
	{&iEM_TERR0IE13LIM,3,199},	//(TERR0IE13LIM) Искажение: Исправность ВИП 0,5 (№10) КНК53М 1канала
	{&iEM_TERR0IE11LIM,3,200},	//(TERR0IE11LIM) Искажение: Исправность ВИП 1,6 (№8) СНМ11 1канала
	{&iEM_TERR0IE31LIM,3,201},	//(TERR0IE31LIM) Искажение: Исправность ВИП 1,6 (№14) СНМ11 3канала
	{&iEM_TERR0IE33LIM,3,202},	//(TERR0IE33LIM) Искажение:Исправность ВИП 0,5 (№16) КНК53М 3канала
	{&iEM_TERR0IE41LIM,3,203},	//(TERR0IE41LIM) Исправность ВИП 1,6 (№17) СНМ11 4канала
	{&iEM_TERR0IE43LIM,3,204},	//(TERR0IE43LIM) Исправность ВИП 0,5 (№19) КНК53М 4канала
	{&iEM_TERB1SS12LIM,3,205},	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
	{&iEM_TERB1MC01RIM,3,206},	//(TERB1MC01RIM) Искажение: Координата штока ББ2
	{&iEM_TERB1SS11LIM,3,207},	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
	{&iEM_TERB1SS21LIM,3,208},	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
	{&iEM_TERA1SS12LIM,3,209},	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
	{&iEM_TERA1SC01RIM,3,210},	//(TERA1SC01RIM) Искажение: Координата штока ББ1
	{&fEM_R0UV87RDU,8,211},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{&fEM_A8UC03RDU,8,213},	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
	{&fEM_R7UI74RIM,8,215},	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
	{&fEM_A3UC03RDU,8,217},	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
	{&fEM_A3UP04RDU,8,219},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{&fEM_A3UP03RDU,8,221},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{&fEM_A2UC03RDU,8,223},	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
	{&fEM_A2UP04RDU,8,225},	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
	{&fEM_A2UP03RDU,8,227},	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
	{&fEM_A1UC03RDU,8,229},	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
	{&fEM_R0UT01RDU,8,231},	//(R0UT01RDU) Нижний предел шкалы датчика температуры
	{&fEM_R0UT02RDU,8,233},	//(R0UT02RDU) Верхний предел шкалы датчика температуры
	{&fEM_R0UR01RIM,8,235},	//(R0UR01RIM) Стартовая отрицательная реактивность
	{&fEM_R0UR30RIM,8,237},	//(R0UR30RIM) Реактивность вносимая образцами (долл)
	{&fEM_A0UN02RIM,8,239},	//(A0UN02RIM) Мощность источника нейтронов с АНИ
	{&fEM_A2UR01RIM,8,241},	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
	{&fEM_A2UR00RIM,8,243},	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
	{&fEM_R7UL01RIM,8,245},	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
	{&fEM_R7UI02RIM,8,247},	//(R7UI02RIM) Коэффициент усиления уровня радиации
	{&fEM_R7UC19RIM,8,249},	//(R7UC19RIM) Y-координата СНМ-11 (11) см
	{&fEM_R7UC10RIM,8,251},	//(R7UC10RIM) X-координата КНК53М R7IN13 см
	{&fEM_A3UG01RDU,8,253},	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
	{&fEM_R7UY05RSS,8,255},	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
	{&fEM_R7UY04RSS,8,257},	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
	{&fEM_R7UY02RSS,8,259},	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
	{&fEM_R7UY01RSS,8,261},	//(R7UY01RSS) Y-координата камеры R7IN11
	{&fEM_R7UX09RSS,8,263},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{&fEM_R7UX08RSS,8,265},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{&fEM_R7UX07RSS,8,267},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{&fEM_R7UX06RSS,8,269},	//(R7UX06RSS) X-координата камеры R7IN23 (см)
	{&fEM_R7UX05RSS,8,271},	//(R7UX05RSS) X-координата камеры R7IN22 (см)
	{&fEM_R7UX04RSS,8,273},	//(R7UX04RSS) X-координата камеры R7IN21 (см)
	{&fEM_R7UX02RSS,8,275},	//(R7UX02RSS) X-координата камеры R7IN12 (см)
	{&fEM_R7UX01RSS,8,277},	//(R7UX01RSS) X-координата камеры R7IN11
	{&fEM_A0UX00RSS,8,279},	//(A0UX00RSS) Эффективный радиус АЗ
	{&fEM_R4UC08RDU,8,281},	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
	{&fEM_B8UC08RDU,8,283},	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
	{&fEM_A8UC08RDU,8,285},	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
	{&fEM_R0UV86RDU,8,287},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UV85RDU,8,289},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UV84RDU,8,291},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{&fEM_R0UV83RDU,8,293},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{&fEM_R0UV82RDU,8,295},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{&fEM_R0UV81RDU,8,297},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{&fEM_A3UC05RIM,8,299},	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
	{&fEM_A3UC06RIM,8,301},	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
	{&fEM_A2UC02RDU,8,303},	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
	{&fEM_A2UC04RIM,8,305},	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
	{&fEM_A2UC05RIM,8,307},	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
	{&fEM_A2UC06RIM,8,309},	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
	{&fEM_A1UC06RIM,8,311},	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
	{&fEM_A1UC05RIM,8,313},	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
	{&fEM_A1UC04RIM,8,315},	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
	{&fEM_A1UC02RDU,8,317},	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
	{&fEM_R0UT06RIM,8,319},	//(R0UT06RIM) Конвекционное сопротивление при обдуве
	{&fEM_R0UT05RIM,8,321},	//(R0UT05RIM) Энергия деления ядра
	{&fEM_R0UT03RIM,8,323},	//(R0UT03RIM) Нормальная температура АЗ град
	{&fEM_R0UT04RIM,8,325},	//(R0UT04RIM) Удельная теплоёмкость топлива
	{&fEM_R0UT02RIM,8,327},	//(R0UT02RIM) Масса топлива в АЗ
	{&fEM_R0UT01RIM,8,329},	//(R0UT01RIM) Температурный коэффициент (долл)
	{&fEM_A3UR01RIM,8,331},	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{&fEM_A3UR00RIM,8,333},	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{&fEM_A1UR00RIM,8,335},	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{&fEM_A1UR01RIM,8,337},	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{&fEM_R0UN02RIM,8,339},	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{&fEM_R0UL01RIM,8,341},	//(R0UL01RIM) Среднее время генерации нейтронов
	{&fEM_A2UG01RDU,8,343},	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
	{&fEM_A1UG01RDU,8,345},	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
	{&fEM_R4UC23RIM,8,347},	//(R4UC23RIM) Y-координата АЗ1 см
	{&fEM_R4UC22RIM,8,349},	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
	{&fEM_A0UN01RIM,8,351},	//(A0UN01RIM) Мощность источника нейтронов ИНИ
	{&fEM_A5UC10RIM,8,353},	//(A5UC10RIM) Время полного хода НЛ сек
	{&fEM_R1UC10RIM,8,355},	//(R1UC10RIM) Время полного хода МДЗ сек
	{&fEM_A6UC10RIM,8,357},	//(A6UC10RIM) Время полного хода БЗ (сек)
	{&fEM_A8UC21RIM,8,359},	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
	{&fEM_A8UC20RIM,8,361},	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
	{&fEM_A8UC11RIM,8,363},	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
	{&fEM_A8UC10RIM,8,365},	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
	{&fEM_A8UV80RDU,8,367},	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
	{&fEM_B8UV80RDU,8,369},	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
	{&fEM_B8UC10RIM,8,371},	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
	{&fEM_B8UC11RIM,8,373},	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
	{&fEM_B8UC20RIM,8,375},	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
	{&fEM_B8UC21RIM,8,377},	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
	{&fEM_R4UC20RIM,8,379},	//(R4UC20RIM) Координата нижних механических упоров тележки мм
	{&fEM_R4UC10RIM,8,381},	//(R4UC10RIM) Координата верхних механических упоров тележки мм
	{&fEM_R4UV80RDU,8,383},	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
	{&fEM_A3UC02RDU,8,385},	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
	{&fEM_A3UC04RIM,8,387},	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
	{&fEM_R0UH05RSS,8,389},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_R0UL42RSS,8,391},	//(R0UL42RSS) Уровень ПС по мощности
	{&fEM_R0UL51RSS,8,393},	//(R0UL51RSS) Уровень АС по периоду разгона
	{&fEM_R0UL41RSS,8,395},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{&fEM_R0UL52RSS,8,397},	//(R0UL52RSS) Уровень АС по мощности
	{&fEM_R0UR01RSS,8,399},	//(R0UR01RSS) Уровень по мощности РУ блокировки автоматического подъёма ББ
	{&fEM_R0UH23RSS,8,401},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{&fEM_R0UH22RSS,8,403},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{&fEM_R0UH21RSS,8,405},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{&fEM_R7UI75RIM,8,407},	//(R7UI75RIM) Множитель к уровню радиации
	{&fEM_A3US07RDU,8,409},	//(A3US07RDU) Постоянная времени масляного демпфера ИС
	{&fEM_A2US07RDU,8,411},	//(A2US07RDU) Постоянная времени масляного демпфера РБ
	{&fEM_A1US07RDU,8,413},	//(A1US07RDU) Постоянная времени масляного демпфера ББ
	{&fEM_A6US80RDU,8,415},	//(A6US80RDU) Тормозной путь БЗ (мм)
	{&fEM_A8US80RDU,8,417},	//(A8US80RDU) Тормозной путь ДС2 (мм)
	{&fEM_B8US80RDU,8,419},	//(B8US80RDU) Тормозной путь АЗ2 (мм)
	{&fEM_A2UV02RIM,8,421},	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{&fEM_A3UV02RIM,8,423},	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{&fEM_A1UV02RIM,8,425},	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{&fEM_A3UP02RDU,8,427},	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
	{&fEM_R0UP88RIM,8,429},	//(R0UP88RIM) Верхняя граница давления  в СИСТЕМЕ (МПа)
	{&fEM_R0UP85RIM,8,431},	//(R0UP85RIM) Нижняя граница давления  в СИСТЕМЕ (МПа)
	{&iEM_TERBB2,3,433},	//(TERBB2) Неисправности  ББ2
	{&fEM_A1MV02RC1,8,434},	//(A1MV02RC1) Заданная скорость движения штока ББ1 от ИС
	{&fEM_A1MC02RC1,8,436},	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
	{&iEM_TERBB1,3,438},	//(TERBB1) Неисправности  ББ1
	{&fEM_R7UI77RIM,8,439},	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{&fEM_R7UI76RIM,8,441},	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{&fEM_A4UP02RIM,8,443},	//(A4UP02RIM) Нижняя граница давления на подъём НИ
	{&fEM_A4UP01RIM,8,445},	//(A4UP01RIM) Текущее давление на подъём НИ
	{&fEM_A3UP02RIM,8,447},	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
	{&fEM_A0UP01RIM,8,449},	//(A0UP01RIM) Текущее давление в АЗ1,2
	{&fEM_A2UP03RIM,8,451},	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
	{&fEM_A2UP02RIM,8,453},	//(A2UP02RIM) Текущее давление на подъём РБ
	{&fEM_A0UP03RIM,8,455},	//(A0UP03RIM) Текущее давление в системе
	{&fEM_R6UL10RIM,8,457},	//(R6UL10RIM) Время полного хода кран-балки сек
	{&fEM_R5UL10RIM,8,459},	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
	{&fEM_R3UL10RIM,8,461},	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
	{&fEM_A9UL10RIM,8,463},	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
	{&fEM_A4UL10RIM,8,465},	//(A4UL10RIM) Время полного перемещения НИ сек
	{&fEM_R0UN03RSS,8,467},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{&fEM_A0UX12RSS,8,469},	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
	{&fEM_A0UX11RSS,8,471},	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
	{&fEM_A0UX10RSS,8,473},	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
	{&fEM_A0UX09RSS,8,475},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{&fEM_A0UX08RSS,8,477},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{&fEM_A0UX07RSS,8,479},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{&fEM_A0UX06RSS,8,481},	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
	{&fEM_A0UX05RSS,8,483},	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
	{&fEM_A0UX04RSS,8,485},	//(A0UX04RSS) Первый коэффициент калибровки камеры4
	{&fEM_A0UX03RSS,8,487},	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
	{&fEM_A0UX02RSS,8,489},	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
	{&fEM_A0UX01RSS,8,491},	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
	{&fEM_R7UY12RSS,8,493},	//(R7UY12RSS) Y-координата камеры R7IN43
	{&fEM_R7UY11RSS,8,495},	//(R7UY11RSS) Y-координата камеры R7IN42
	{&fEM_R7UY10RSS,8,497},	//(R7UY10RSS) Y-координата камеры R7IN41
	{&fEM_R7UX12RSS,8,499},	//(R7UX12RSS) X-координата камеры R7IN43
	{&fEM_R7UX11RSS,8,501},	//(R7UX11RSS) X-координата камеры R7IN42
	{&fEM_R7UX10RSS,8,503},	//(R7UX10RSS) X-координата камеры R7IN41
	{&fEM_R7UY09RSS,8,505},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{&fEM_R7UY08RSS,8,507},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{&fEM_R7UY07RSS,8,509},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{&fEM_R7UY06RSS,8,511},	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
	{&fEM_A1UP82RIM,8,513},	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{&fEM_A3UP01RIM,8,515},	//(A3UP01RIM) Текущее давление на СПУСК ИС
	{&fEM_A0UP02RIM,8,517},	//(A0UP02RIM) Текущее давление в АЗ1,2
	{&fEM_A2UP01RIM,8,519},	//(A2UP01RIM) Текущее давление на сброс РБ
	{&fEM_A1UP01RIM,8,521},	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
	{&fEM_R7UI73RIM,8,523},	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
	{&fEM_R7UI72RIM,8,525},	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
	{&fEM_R7UI71RIM,8,527},	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{&fEM_R4US80RDU,8,529},	//(R4US80RDU) Тормозной путь тележки (мм)
	{&fEM_R0UH03RSS,8,531},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
	{&fEM_R0UH02RSS,8,533},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
	{&fEM_B0UX12RSS,8,535},	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
	{&fEM_B0UX11RSS,8,537},	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
	{&fEM_B0UX10RSS,8,539},	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
	{&fEM_B0UX09RSS,8,541},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{&fEM_B0UX08RSS,8,543},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{&fEM_B0UX07RSS,8,545},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{&fEM_B0UX06RSS,8,547},	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
	{&fEM_B0UX05RSS,8,549},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{&fEM_B0UX04RSS,8,551},	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
	{&fEM_B0UX03RSS,8,553},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{&fEM_B0UX02RSS,8,555},	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
	{&fEM_B0UX01RSS,8,557},	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
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
	{&B3IP02IDU,3,4},	//(B3IP02IDU) Текущее давление ВЫСТРЕЛ  ИС2
	{&B3IC01UDU,5,5},	//(B3IC01UDU) Координата штока ИС2
	{&A3IP02IDU,3,7},	//(A3IP02IDU) Текущее давление ВЫСТРЕЛ ИС1
	{&A8IC01UDU,5,8},	//(A8IC01UDU) Координата ДС2
	{&B8IC01UDU,5,10},	//(B8IC01UDU) Координата АЗ2
	{&B2IC01UDU,5,12},	//(B2IC01UDU) Координата штока РБ2
	{&A1IC01UDU,5,14},	//(A1IC01UDU) Координата штока ББ1
	{&B1IC01UDU,5,16},	//(B1IC01UDU) Координата штока ББ2
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
	{&R0VP82LZ1,1,62},
	{&R0VN73LZ1,1,38},
	{&A0EE01LS1,1,4},
	{&A0VN71LS3,1,44},
	{&R0VN75LZ1,1,2},
	{&A3IS22LZ1,1,10},
	{&A0VN71LS1,1,6},
	{&R6IS66LZ1,1,32},
	{&R0VN71LZ1,1,0},
	{&R6IS67LZ1,1,34},
	{&R6IS68LZ1,1,36},
	{&A3IS11LZ1,1,8},
	{&R0VP81LZ1,1,56},
	{&A0VN71LS4,1,30},
	{&A0VP81LZ1,1,52},
	{&A1VP81LZ1,1,54},
	{&R0VN77LZ1,1,40},
	{&A0EE01LS3,1,42},
	{&R7II73LZ1,1,50},
	{&R0VN78LZ1,1,26},
	{&A0EE01LS4,1,28},
	{&R0VN72LZ1,1,12},
	{&R7II71LZ1,1,46},
	{&A0VN71LS2,1,18},
	{&R0VN74LZ1,1,24},
	{&R7II72LZ1,1,48},
	{&R0VN76LZ1,1,14},
	{&A0EE01LS2,1,16},
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
	{&A1EE01LS3,1,42},
	{&R0VN73LZ2,1,38},
	{&R7II73LZ2,1,50},
	{&R0VN77LZ2,1,40},
	{&A1EE01LS1,1,4},
	{&R0VN75LZ2,1,2},
	{&A1EE01LS2,1,16},
	{&R7II71LZ2,1,46},
	{&A1VN71LS3,1,44},
	{&R0VN76LZ2,1,14},
	{&R0VN74LZ2,1,24},
	{&A1VN71LS2,1,18},
	{&R0VN72LZ2,1,12},
	{&R0VN71LZ2,1,0},
	{&A1VN71LS1,1,6},
	{&R7II72LZ2,1,48},
	{&A1VN71LS4,1,30},
	{&R0VP82LZ2,1,62},
	{&A1EE01LS4,1,28},
	{&R0VN78LZ2,1,26},
	{&B3IS11LZ2,1,20},
	{&B1VP81LZ2,1,60},
	{&B3IS22LZ2,1,22},
	{&B0VP81LZ2,1,58},
	{&R0VP81LZ2,1,56},
	{&R6IS68LZ2,1,36},
	{&R6IS67LZ2,1,34},
	{&R6IS66LZ2,1,32},
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
	{&B1IS12LDU,1,12},
	{&A4IS11LDU,1,30},
	{&A4IS21LDU,1,32},
	{&R8IS11LDU,1,26},
	{&R1IS11LDU,1,42},
	{&R1IS21LDU,1,44},
	{&R2IS11LDU,1,46},
	{&R2IS21LDU,1,48},
	{&B3IS21LDU,1,24},
	{&B7AS31LDU,1,10},
	{&B2IS12LDU,1,18},
	{&B2IS11LDU,1,20},
	{&B2IS21LDU,1,22},
	{&B9IS21LDU,1,40},
	{&B9IS11LDU,1,38},
	{&A9IS21LDU,1,36},
	{&A9IS11LDU,1,34},
	{&A7AS31LDU,1,60},
	{&A1IS12LDU,1,62},
	{&B1IS21LDU,1,16},
	{&B1IS11LDU,1,14},
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
	{&B5IS11LDU,1,62},
	{&A5IS21LDU,1,56},
	{&A5IS11LDU,1,54},
	{&A6IS21LDU,1,52},
	{&B4IS11LDU,1,12},
	{&B4IS21LDU,1,14},
	{&A3IS21LDU,1,10},
	{&A2IS12LDU,1,4},
	{&A2IS11LDU,1,6},
	{&A2IS21LDU,1,8},
	{&B6IS11LDU,1,58},
	{&A4VP82LDU,1,24},
	{&B4VP82LDU,1,30},
	{&R4IS11LDU,1,42},
	{&R4IS21LDU,1,46},
	{&R4IS22LDU,1,48},
	{&R4IS12LDU,1,44},
	{&B8IS12LDU,1,16},
	{&R0IS02LDU,1,32},
	{&A2VP82LDU,1,22},
	{&A3VP81LDU,1,20},
	{&B3VP81LDU,1,26},
	{&A1IS11LDU,1,0},
	{&A1IS21LDU,1,2},
	{&B6IS21LDU,1,60},
	{&B2VP82LDU,1,28},
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
	{&B8IS22LDU,1,32},
	{&A8IS22LDU,1,30},
	{&A8IS12LDU,1,28},
	{&R3IS41LDU,1,8},
	{&R3AD11LDU,1,12},
	{&R3AD21LDU,1,16},
	{&R5AD20LDU,1,24},
	{&R5AD10LDU,1,22},
	{&R3IS31LDU,1,6},
	{&R3AD20LDU,1,14},
	{&R6IS21LDU,1,26},
	{&R3AD10LDU,1,10},
	{&R5IS21LDU,1,20},
	{&R5IS11LDU,1,18},
	{&R3IS21LDU,1,4},
	{&R3IS11LDU,1,2},
	{&B5IS21LDU,1,0},
	{&A6IS11LDU,1,34},
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
	{&B5AD20LDU,1,48},
	{&B7AP31LDU,1,60},
	{&A7AP31LDU,1,32},
	{&B5AD10LDU,1,46},
	{&A5AD20LDU,1,44},
	{&A5AD10LDU,1,42},
	{&A3AD33LDU,1,24},
	{&R2AD20LDU,1,40},
	{&R1AD10LDU,1,34},
	{&B3AD33LDU,1,52},
	{&A3AD34LDU,1,22},
	{&A8AD10LDU,1,62},
	{&R2AD10LDU,1,38},
	{&B2AD33LDU,1,54},
	{&R1AD20LDU,1,36},
	{&A3AD31LDU,1,30},
	{&B3AD31LDU,1,58},
	{&B3AD34LDU,1,50},
	{&A2AD33LDU,1,26},
	{&A4AD10LDU,1,28},
	{&B4AD10LDU,1,56},
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
	{&B8AD20LDU,1,16},
	{&B6AD20LDU,1,8},
	{&B8AD10LDU,1,14},
	{&R4AD20LDU,1,12},
	{&R4AD10LDU,1,10},
	{&B3AD05LDU,1,44},
	{&B3AD04LDU,1,42},
	{&B3AD03LDU,1,40},
	{&B3AD02LDU,1,38},
	{&B3AD01LDU,1,36},
	{&B3AD21LDU,1,34},
	{&B9AD10LDU,1,48},
	{&A9AD10LDU,1,46},
	{&A3AD11LDU,1,18},
	{&A1AD04LDU,1,60},
	{&A1AD03LDU,1,58},
	{&A1AD02LDU,1,56},
	{&A1AD01LDU,1,54},
	{&A1AD21LDU,1,52},
	{&A1AD11LDU,1,50},
	{&A3AD21LDU,1,20},
	{&B3AD11LDU,1,32},
	{&A3AD05LDU,1,30},
	{&A3AD04LDU,1,28},
	{&A3AD03LDU,1,26},
	{&A3AD02LDU,1,24},
	{&A3AD01LDU,1,22},
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
	{&B2AD03LDU,1,38},
	{&B2AD02LDU,1,36},
	{&A1AD31LDU,1,46},
	{&B2AD01LDU,1,34},
	{&B2AD04LDU,1,40},
	{&B2AD05LDU,1,42},
	{&B1AD21LDU,1,4},
	{&A1AD05LDU,1,0},
	{&B1AD11LDU,1,2},
	{&R8AD21LDU,1,60},
	{&A2AD04LDU,1,26},
	{&A2AD03LDU,1,24},
	{&A2AD02LDU,1,22},
	{&A2AD01LDU,1,20},
	{&A2AD21LDU,1,18},
	{&A2AD11LDU,1,16},
	{&R0AD16LDU,1,62},
	{&A2AD32LDU,1,48},
	{&B1AD05LDU,1,14},
	{&B1AD04LDU,1,12},
	{&B1AD03LDU,1,10},
	{&A2AD31LDU,1,50},
	{&A2AD05LDU,1,28},
	{&B1AD02LDU,1,8},
	{&B1AD01LDU,1,6},
	{&B2AD11LDU,1,30},
	{&A1AD32LDU,1,44},
	{&B2AD21LDU,1,32},
	{&B2AD32LDU,1,56},
	{&B2AD31LDU,1,58},
	{&B1AD32LDU,1,52},
	{&B1AD31LDU,1,54},
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
	setAsFloat(333,0.015);
	setAsFloat(334,0.0069);
	setAsFloat(335,0.21);
	setAsFloat(336,0);
	setAsFloat(337,0);
	setAsFloat(338,0.0096);
	setAsFloat(339,0.0026);
	setAsFloat(340,106);
	setAsFloat(341,135.227);
	setAsFloat(342,25);
	setAsFloat(343,320.435466);
	setAsFloat(344,0.0055);
	setAsFloat(345,0.000877);
	setAsFloat(346,200);
	setAsFloat(347,100);
	setAsFloat(348,0);
	setAsFloat(349,0);
	setAsFloat(350,100);
	setAsFloat(351,80);
	setAsFloat(352,0.002375);
	setAsFloat(353,0);
	setAsFloat(354,165);
	setAsFloat(355,200);
	setAsFloat(356,0.001667);
	setAsFloat(357,40);
	setAsFloat(358,15630.0);
	setAsFloat(359,1374);
	setAsFloat(360,0);
	setAsFloat(361,390.0);
	setAsFloat(362,2000.0);
	setAsFloat(363,1500.0);
	setAsFloat(364,10.91);
	setAsFloat(365,10.91);
	setAsFloat(366,1500.0);
	setAsFloat(367,2000);
	setAsFloat(368,390.0);
	setAsFloat(369,0);
	setAsFloat(370,55.0);
	setAsFloat(371,15.0);
	setAsFloat(372,5.0);
	setAsFloat(373,1E12);
	setAsFloat(374,43.6);
	setAsFloat(375,506.5);
	setAsFloat(376,20.0);
	setAsFloat(377,20.0);
	setAsFloat(378,20.0);
	setAsFloat(379,1269.0);
	setAsFloat(380,256.0);
	setAsFloat(381,1.0);
	setAsFloat(382,2.0);
	setAsFloat(383,0);
	setAsFloat(384,0.026);
	setAsFloat(385,0.08);
	setAsFloat(386,0.0);
	setAsFloat(387,27.108);
	setAsFloat(388,600);
	setAsFloat(389,0);
	setAsFloat(390,0.00009765625);
	setAsFloat(391,1.6);
	setAsFloat(392,0);
	setAsFloat(393,0.00009765625);
	setAsFloat(394,2.5);
	setAsFloat(395,0);
	setAsFloat(396,0.00009765625);
	setAsFloat(397,10000.0);
	setAsFloat(398,0.0009765625);
	setAsFloat(399,750);
	setAsFloat(400,100);
	setAsFloat(401,200);
	setAsFloat(402,300);
	setAsFloat(403,400);
	setAsFloat(404,500);
	setAsFloat(405,600);
	setAsFloat(406,0.50);
	setAsFloat(407,0.50);
	setAsFloat(408,0.50);
	setAsFloat(409,11.0);
	setAsFloat(410,1585.0);
	setAsFloat(411,1796.0);
	setAsFloat(412,1555.0);
	setAsFloat(413,1269.0);
	setAsFloat(414,1269.0);
	setAsFloat(415,1585.0);
	setAsFloat(416,1796.0);
	setAsFloat(417,1269.0);
	setAsFloat(418,248.0);
	setAsFloat(419,284.5);
	setAsFloat(420,248.0);
	setAsFloat(421,271.6);
	setAsFloat(422,287.2);
	setAsFloat(423,594.0);
	setAsFloat(424,559.0);
	setAsFloat(425,588.0);
	setAsFloat(426,1555.0);
	setAsFloat(427,1281.2);
	setAsFloat(428,1269.0);
	setAsFloat(429,594.0);
	setAsFloat(430,597.2);
	setAsFloat(431,556.8);
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
	setAsFloat(442,1.0);
	setAsFloat(443,1.0);
	setAsFloat(444,0);
	setAsFloat(445,0);
	setAsFloat(446,0);
	setAsFloat(447,0);
	setAsFloat(448,0.0);
	setAsFloat(449,0);
	setAsFloat(450,0.0);
	setAsFloat(451,0);
	setAsFloat(452,0.0);
	setAsFloat(453,0.0);
	setAsFloat(454,0.0);
	setAsFloat(455,0.0);
	setAsFloat(456,3703.704);
	setAsFloat(457,62500.0);
	setAsFloat(458,20);
	setAsFloat(459,10000);
	setAsFloat(460,10000);
	setAsFloat(461,5000);
	setAsFloat(462,0.76);
	setAsFloat(463,0.245);
	setAsFloat(464,2.9);
	setAsFloat(465,0.13);
	setAsFloat(466,0.73);
	setAsFloat(467,3.04);
	setAsFloat(468,14.7);
	setAsFloat(469,0.41);
	setAsFloat(470,9807.0);
	setAsFloat(471,22975.0);
	setAsFloat(472,12750.0);
	setAsFloat(473,20);
	setAsFloat(474,20);
	setAsFloat(475,0);
	setAsFloat(476,5.0);
	setAsFloat(477,5.0);
	setAsFloat(478,5.0);
	setAsFloat(479,100.0);
	setAsFloat(480,4000);
	setAsFloat(481,100000);
	setAsFloat(482,1000000);
	setAsFloat(483,10.0);
	setAsFloat(484,5100);
	setAsFloat(485,20);
	setAsFloat(486,13.0);
	setAsFloat(487,5000);
	setAsFloat(488,32000.0);
	setAsFloat(489,0.00001);
	setAsFloat(490,5.0);
	setAsFloat(491,15.0);
	setAsFloat(492,15.0);
	setAsFloat(493,20.0);
	setAsFloat(494,10.0);
	setAsBool(495,0);
	setAsBool(496,0);
	setAsBool(497,0);
	setAsFloat(498,5.88);
	setAsFloat(499,0.45);
	setAsFloat(500,0.39);
	setAsFloat(501,2.74);
	setAsFloat(502,0.07);
	setAsFloat(503,0.275);
	setAsFloat(504,0.245);
	setAsFloat(505,0.045);
	setAsFloat(506,0.05);
	setAsShort(507,0);
	setAsFloat(508,0);
	setAsFloat(509,0);
	setAsShort(510,0);
	setAsFloat(511,0);
	setAsFloat(512,0);
	setAsShort(513,0);
	setAsFloat(514,0);
	setAsFloat(515,0);
	setAsShort(516,0);
	setAsFloat(517,0);
	setAsFloat(518,0);
	setAsShort(519,0);
	setAsFloat(520,0);
	setAsFloat(521,0);
	setAsShort(522,0);
	setAsFloat(523,0);
	setAsFloat(524,0);
	setAsShort(525,0);
	setAsShort(526,0);
	setAsShort(527,0);
	setAsShort(528,0);
	setAsFloat(529,0);
	setAsShort(530,0);
	setAsShort(531,0);
	setAsFloat(532,0);
	setAsFloat(533,0);
	setAsFloat(534,0);
	setAsFloat(535,0);
	setAsFloat(536,0);
	setAsFloat(537,0);
	setAsFloat(538,0);
	setAsFloat(539,0);
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
	setAsShort(624,0);
	setAsShort(625,0);
	setAsShort(626,0);
	setAsShort(627,0);
	setAsShort(628,0);
	setAsBool(629,1);
	setAsShort(630,0);
	setAsShort(631,0);
	setAsBool(632,1);
	setAsShort(633,0);
	setAsShort(634,0);
	setAsBool(635,1);
	setAsShort(636,0);
	setAsShort(637,0);
	setAsBool(638,1);
	setAsShort(639,0);
	setAsFloat(640,0);
	setAsFloat(641,0);
	setAsShort(642,0);
	setAsFloat(643,0);
	setAsFloat(644,0);
	setAsShort(645,0);
	setAsFloat(646,0);
	setAsFloat(647,0);
	setAsShort(648,0);
	setAsFloat(649,0);
	setAsFloat(650,0);
	setAsShort(651,0);
	setAsFloat(652,0);
	setAsFloat(653,0);
	setAsShort(654,0);
	setAsShort(655,0);
	setAsShort(656,0);
	setAsShort(657,0);
	setAsShort(658,0);
	setAsShort(659,0);
	setAsBool(660,0);
	setAsBool(661,0);
	setAsBool(662,0);
	setAsBool(663,0);
	setAsBool(664,0);
	setAsBool(665,1);
	setAsBool(666,0);
	setAsShort(667,0);
	setAsFloat(668,0);
	setAsFloat(669,0);
	setAsShort(670,0);
	setAsFloat(671,0);
	setAsFloat(672,0);
	setAsShort(673,0);
	setAsFloat(674,0);
	setAsFloat(675,0);
	setAsShort(676,0);
	setAsFloat(677,0);
	setAsFloat(678,0);
	setAsBool(679,1);
	setAsFloat(680,0.01);
	setAsFloat(681,0.01);
	setAsFloat(682,0.01);
	setAsFloat(683,0.5);
	setAsFloat(684,100.0);
	setAsShort(685,0);
	setAsShort(686,0);
	setAsShort(687,0);
}
void Scheme(void)
{
}
#endif
