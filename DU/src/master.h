#ifndef DU_H
#define DU_H
// Подсистема DU:DU
static char SimulOn=0;
static short CodeSub=3;
static char SimulIP[]="192.168.1.17\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 11014
static char BUFFER[11014];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.50\0", 5432, "192.168.10.150\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define gray01	 BUFFER[0]	//(gray01) - в грее
#define idgray01	 1	//(gray01) - в грее
#define gray02	 BUFFER[5]	//(gray02) - в грее
#define idgray02	 2	//(gray02) - в грее
#define gray03	 BUFFER[10]	//(gray03) - в грее
#define idgray03	 3	//(gray03) - в грее
#define gray04	 BUFFER[15]	//(gray04) - в грее
#define idgray04	 4	//(gray04) - в грее
#define gray05	 BUFFER[20]	//(gray05) - в грее
#define idgray05	 5	//(gray05) - в грее
#define gray06	 BUFFER[25]	//(gray06) - в грее
#define idgray06	 6	//(gray06) - в грее
#define gray07	 BUFFER[30]	//(gray07) - в грее
#define idgray07	 7	//(gray07) - в грее
#define gray08	 BUFFER[35]	//(gray08) - в грее
#define idgray08	 8	//(gray08) - в грее
#define venc01	 BUFFER[40]	//(venc01) - посчитанный
#define idvenc01	 9	//(venc01) - посчитанный
#define venc02	 BUFFER[45]	//(venc02) - посчитанный
#define idvenc02	 10	//(venc02) - посчитанный
#define venc03	 BUFFER[50]	//(venc03) - посчитанный
#define idvenc03	 11	//(venc03) - посчитанный
#define venc04	 BUFFER[55]	//(venc04) - посчитанный
#define idvenc04	 12	//(venc04) - посчитанный
#define venc05	 BUFFER[60]	//(venc05) - посчитанный
#define idvenc05	 13	//(venc05) - посчитанный
#define venc06	 BUFFER[65]	//(venc06) - посчитанный
#define idvenc06	 14	//(venc06) - посчитанный
#define venc07	 BUFFER[70]	//(venc07) - посчитанный
#define idvenc07	 15	//(venc07) - посчитанный
#define venc08	 BUFFER[75]	//(venc08) - посчитанный
#define idvenc08	 16	//(venc08) - посчитанный
#define B3MD12LP1	 BUFFER[80]	//(B3MD12LP1) Переключатель «РАЗРЕШИТЬ» ИС2
#define idB3MD12LP1	 17	//(B3MD12LP1) Переключатель «РАЗРЕШИТЬ» ИС2
#define B3MD11LP1	 BUFFER[82]	//(B3MD11LP1) Кнопка «ПУСК ИС2»
#define idB3MD11LP1	 18	//(B3MD11LP1) Кнопка «ПУСК ИС2»
#define R0VL01RDU	 BUFFER[84]	//(R0VL01RDU) Индикация Время задержки
#define idR0VL01RDU	 19	//(R0VL01RDU) Индикация Время задержки
#define R0VZ71LZ2	 BUFFER[89]	//(R0VZ71LZ2) Обобщенный сигнал АЗ 2 канала
#define idR0VZ71LZ2	 20	//(R0VZ71LZ2) Обобщенный сигнал АЗ 2 канала
#define R0VZ71LZ1	 BUFFER[91]	//(R0VZ71LZ1) Обобщенный сигнал АЗ 1канала
#define idR0VZ71LZ1	 21	//(R0VZ71LZ1) Обобщенный сигнал АЗ 1канала
#define R0VZ71LDU	 BUFFER[93]	//(R0VZ71LDU) Обобщенный сигнал АЗ
#define idR0VZ71LDU	 22	//(R0VZ71LDU) Обобщенный сигнал АЗ
#define A2IS33LDU	 BUFFER[95]	//(A2IS33LDU) Клапан «Подъём РБ1» открыт (обесточен)
#define idA2IS33LDU	 23	//(A2IS33LDU) Клапан «Подъём РБ1» открыт (обесточен)
#define A3IS31LDU	 BUFFER[97]	//(A3IS31LDU) Клапан «СПУСК ИС1» открыт (обесточен)
#define idA3IS31LDU	 24	//(A3IS31LDU) Клапан «СПУСК ИС1» открыт (обесточен)
#define A3IS33LDU	 BUFFER[99]	//(A3IS33LDU) Клапан «ВЫСТРЕЛ ИС1» открыт (обесточен)
#define idA3IS33LDU	 25	//(A3IS33LDU) Клапан «ВЫСТРЕЛ ИС1» открыт (обесточен)
#define A3IS35LDU	 BUFFER[101]	//(A3IS35LDU) Клапан «ВПИС1» открыт (обесточен)
#define idA3IS35LDU	 26	//(A3IS35LDU) Клапан «ВПИС1» открыт (обесточен)
#define A4IS10LDU	 BUFFER[103]	//(A4IS10LDU) Клапан «Подъём НИ1» открыт (обесточен)
#define idA4IS10LDU	 27	//(A4IS10LDU) Клапан «Подъём НИ1» открыт (обесточен)
#define A1VN71LZ1	 BUFFER[105]	//(A1VN71LZ1) Блокировка автоматического подъёма ББ
#define idA1VN71LZ1	 28	//(A1VN71LZ1) Блокировка автоматического подъёма ББ
#define A1VN71LZ2	 BUFFER[107]	//(A1VN71LZ2) Блокировка автоматического подъёма ББ
#define idA1VN71LZ2	 29	//(A1VN71LZ2) Блокировка автоматического подъёма ББ
#define A1AB19LDU	 BUFFER[109]	//(A1AB19LDU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
#define idA1AB19LDU	 30	//(A1AB19LDU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
#define R0AD14LZ1	 BUFFER[111]	//(R0AD14LZ1) Имитация срабатывания АЗ от II УР
#define idR0AD14LZ1	 31	//(R0AD14LZ1) Имитация срабатывания АЗ от II УР
#define R0AD14LZ2	 BUFFER[113]	//(R0AD14LZ2) Имитация срабатывания АЗ от  II УР
#define idR0AD14LZ2	 32	//(R0AD14LZ2) Имитация срабатывания АЗ от  II УР
#define A3VZ13LZ2	 BUFFER[115]	//(A3VZ13LZ2) Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ2	 33	//(A3VZ13LZ2) Имитация срабатывания АЗ от ВУ ИС
#define A3VZ13LZ1	 BUFFER[117]	//(A3VZ13LZ1) Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ1	 34	//(A3VZ13LZ1) Имитация срабатывания АЗ от ВУ ИС
#define A3VZ15LZ1	 BUFFER[119]	//(A3VZ15LZ1) Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ1	 35	//(A3VZ15LZ1) Имитация срабатывания АЗ от НУП ИС
#define A3VZ15LZ2	 BUFFER[121]	//(A3VZ15LZ2) Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ2	 36	//(A3VZ15LZ2) Имитация срабатывания АЗ от НУП ИС
#define B2IS33LDU	 BUFFER[123]	//(B2IS33LDU) Клапан «Подъём РБ2» открыт (обесточен)
#define idB2IS33LDU	 37	//(B2IS33LDU) Клапан «Подъём РБ2» открыт (обесточен)
#define B3IS31LDU	 BUFFER[125]	//(B3IS31LDU) Клапан «СПУСК ИС2» открыт (обесточен)
#define idB3IS31LDU	 38	//(B3IS31LDU) Клапан «СПУСК ИС2» открыт (обесточен)
#define B1MD11LP1	 BUFFER[127]	//(B1MD11LP1) Кнопка «ПУСК ББ2»
#define idB1MD11LP1	 39	//(B1MD11LP1) Кнопка «ПУСК ББ2»
#define B1MD12LP1	 BUFFER[129]	//(B1MD12LP1) Переключатель «РАЗРЕШИТЬ» ББ2
#define idB1MD12LP1	 40	//(B1MD12LP1) Переключатель «РАЗРЕШИТЬ» ББ2
#define B2MD11LP1	 BUFFER[131]	//(B2MD11LP1) Кнопка «ПУСК РБ2»
#define idB2MD11LP1	 41	//(B2MD11LP1) Кнопка «ПУСК РБ2»
#define B2MD12LP1	 BUFFER[133]	//(B2MD12LP1) Переключатель «РАЗРЕШИТЬ» РБ2
#define idB2MD12LP1	 42	//(B2MD12LP1) Переключатель «РАЗРЕШИТЬ» РБ2
#define A2MD11LP1	 BUFFER[135]	//(A2MD11LP1) Кнопка «ПУСК РБ1»
#define idA2MD11LP1	 43	//(A2MD11LP1) Кнопка «ПУСК РБ1»
#define A2MD12LP1	 BUFFER[137]	//(A2MD12LP1) Переключатель «РАЗРЕШИТЬ» РБ1
#define idA2MD12LP1	 44	//(A2MD12LP1) Переключатель «РАЗРЕШИТЬ» РБ1
#define R0IS01LDU	 BUFFER[139]	//(R0IS01LDU) Признак работы с имитатором
#define idR0IS01LDU	 45	//(R0IS01LDU) Признак работы с имитатором
#define R0IS02LDU	 BUFFER[141]	//(R0IS02LDU) Разрешение ввода от имитатора
#define idR0IS02LDU	 46	//(R0IS02LDU) Разрешение ввода от имитатора
#define R0VP73LZ1	 BUFFER[143]	//(R0VP73LZ1) ПС давления для РУ
#define idR0VP73LZ1	 47	//(R0VP73LZ1) ПС давления для РУ
#define R0VP73LZ2	 BUFFER[145]	//(R0VP73LZ2) ПС давления для РУ
#define idR0VP73LZ2	 48	//(R0VP73LZ2) ПС давления для РУ
#define R0VP73LDU	 BUFFER[147]	//(R0VP73LDU) ПС давления для РУ
#define idR0VP73LDU	 49	//(R0VP73LDU) ПС давления для РУ
#define R0MD34LP1	 BUFFER[149]	//(R0MD34LP1) Кнопка «Квитировать»
#define idR0MD34LP1	 50	//(R0MD34LP1) Кнопка «Квитировать»
#define A0VT71LZ1	 BUFFER[151]	//(A0VT71LZ1) АС по температуре в АЗ1
#define idA0VT71LZ1	 51	//(A0VT71LZ1) АС по температуре в АЗ1
#define B0VT71LZ1	 BUFFER[153]	//(B0VT71LZ1) АС по температуре в АЗ2
#define idB0VT71LZ1	 52	//(B0VT71LZ1) АС по температуре в АЗ2
#define A0VT71LZ2	 BUFFER[155]	//(A0VT71LZ2) АС по температуре в АЗ1
#define idA0VT71LZ2	 53	//(A0VT71LZ2) АС по температуре в АЗ1
#define B0VT71LZ2	 BUFFER[157]	//(B0VT71LZ2) АС по температуре в АЗ2
#define idB0VT71LZ2	 54	//(B0VT71LZ2) АС по температуре в АЗ2
#define B2VS11LDU	 BUFFER[159]	//(B2VS11LDU) Движение РБ2 в сторону ВУ
#define idB2VS11LDU	 55	//(B2VS11LDU) Движение РБ2 в сторону ВУ
#define B2VS21LDU	 BUFFER[161]	//(B2VS21LDU) Движение РБ2 в сторону НУ
#define idB2VS21LDU	 56	//(B2VS21LDU) Движение РБ2 в сторону НУ
#define B2VS01IDU	 BUFFER[163]	//(B2VS01IDU) Готовность к управлению РБ2
#define idB2VS01IDU	 57	//(B2VS01IDU) Готовность к управлению РБ2
#define A7AS31LDU	 BUFFER[166]	//(A7AS31LDU) Клапан «Обдув АЗ1» открыт (обесточен)
#define idA7AS31LDU	 58	//(A7AS31LDU) Клапан «Обдув АЗ1» открыт (обесточен)
#define B7AS31LDU	 BUFFER[168]	//(B7AS31LDU) Клапан «Обдув АЗ2» открыт (обесточен)
#define idB7AS31LDU	 59	//(B7AS31LDU) Клапан «Обдув АЗ2» открыт (обесточен)
#define A7AZ03LDU	 BUFFER[170]	//(A7AZ03LDU) Несанкционированное включение обдува АЗ1
#define idA7AZ03LDU	 60	//(A7AZ03LDU) Несанкционированное включение обдува АЗ1
#define B7AZ03LDU	 BUFFER[172]	//(B7AZ03LDU) Несанкционированное включение обдува АЗ2
#define idB7AZ03LDU	 61	//(B7AZ03LDU) Несанкционированное включение обдува АЗ2
#define R3AD11LDU	 BUFFER[174]	//(R3AD11LDU) Гомогенные двери-2 открыть
#define idR3AD11LDU	 62	//(R3AD11LDU) Гомогенные двери-2 открыть
#define R3AD21LDU	 BUFFER[176]	//(R3AD21LDU) Гомогенные двери-2 закрыть
#define idR3AD21LDU	 63	//(R3AD21LDU) Гомогенные двери-2 закрыть
#define R3IS41LDU	 BUFFER[178]	//(R3IS41LDU) Приход на НУ гомогенных дверей-2
#define idR3IS41LDU	 64	//(R3IS41LDU) Приход на НУ гомогенных дверей-2
#define R3IS31LDU	 BUFFER[180]	//(R3IS31LDU) Приход на ВУ гомогенных дверей-2
#define idR3IS31LDU	 65	//(R3IS31LDU) Приход на ВУ гомогенных дверей-2
#define R3VS10LDU	 BUFFER[182]	//(R3VS10LDU) Движение дверей-1 к открыто
#define idR3VS10LDU	 66	//(R3VS10LDU) Движение дверей-1 к открыто
#define R0AB03LDU	 BUFFER[184]	//(R0AB03LDU) Нарушение времени срабатывания АЗ от ВУ ИС
#define idR0AB03LDU	 67	//(R0AB03LDU) Нарушение времени срабатывания АЗ от ВУ ИС
#define R0AB05LDU	 BUFFER[186]	//(R0AB05LDU) Нарушение времени срабатывания АЗ от НУП ИС
#define idR0AB05LDU	 68	//(R0AB05LDU) Нарушение времени срабатывания АЗ от НУП ИС
#define R0VN11RZ1	 BUFFER[188]	//(R0VN11RZ1) Средняя мощность по BAZ1
#define idR0VN11RZ1	 69	//(R0VN11RZ1) Средняя мощность по BAZ1
#define R0VN11RZ2	 BUFFER[193]	//(R0VN11RZ2) Средняя мощность по BAZ2
#define idR0VN11RZ2	 70	//(R0VN11RZ2) Средняя мощность по BAZ2
#define A2AB15LDU	 BUFFER[198]	//(A2AB15LDU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define idA2AB15LDU	 71	//(A2AB15LDU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define B2AB15LDU	 BUFFER[200]	//(B2AB15LDU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define idB2AB15LDU	 72	//(B2AB15LDU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define R0AD21LDU	 BUFFER[202]	//(R0AD21LDU) Подключить защиту от II УР
#define idR0AD21LDU	 73	//(R0AD21LDU) Подключить защиту от II УР
#define R0VX02LDU	 BUFFER[204]	//(R0VX02LDU) Импульс разрешен
#define idR0VX02LDU	 74	//(R0VX02LDU) Импульс разрешен
#define R0EE03LDU	 BUFFER[206]	//(R0EE03LDU) ВПИС ИС
#define idR0EE03LDU	 75	//(R0EE03LDU) ВПИС ИС
#define R0AB07LDU	 BUFFER[208]	//(R0AB07LDU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
#define idR0AB07LDU	 76	//(R0AB07LDU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
#define R0AD16LDU	 BUFFER[210]	//(R0AD16LDU) Контроль  I-II УР. РАД
#define idR0AD16LDU	 77	//(R0AD16LDU) Контроль  I-II УР. РАД
#define C2MD31LP1	 BUFFER[212]	//(C2MD31LP1) Кнопка «СБРОС РБ»
#define idC2MD31LP1	 78	//(C2MD31LP1) Кнопка «СБРОС РБ»
#define B6VS01IDU	 BUFFER[214]	//(B6VS01IDU) Готовность к управлению БЗ2
#define idB6VS01IDU	 79	//(B6VS01IDU) Готовность к управлению БЗ2
#define R3VS32IDU	 BUFFER[217]	//(R3VS32IDU) Готовность к управлению гомогенных дверей-2
#define idR3VS32IDU	 80	//(R3VS32IDU) Готовность к управлению гомогенных дверей-2
#define R3VS22LDU	 BUFFER[220]	//(R3VS22LDU) Движение дверей-2  к закрыто
#define idR3VS22LDU	 81	//(R3VS22LDU) Движение дверей-2  к закрыто
#define R3VS11LDU	 BUFFER[222]	//(R3VS11LDU) Движение дверей-2 к открыто
#define idR3VS11LDU	 82	//(R3VS11LDU) Движение дверей-2 к открыто
#define R3IS22LDU	 BUFFER[224]	//(R3IS22LDU) Приход на НУ гомогенных дверей
#define idR3IS22LDU	 83	//(R3IS22LDU) Приход на НУ гомогенных дверей
#define B3IS33LDU	 BUFFER[226]	//(B3IS33LDU) Клапан «ВЫСТРЕЛ ИС2» открыт (обесточен)
#define idB3IS33LDU	 84	//(B3IS33LDU) Клапан «ВЫСТРЕЛ ИС2» открыт (обесточен)
#define B3IS35LDU	 BUFFER[228]	//(B3IS35LDU) Клапан «ВПИС2» открыт (обесточен)
#define idB3IS35LDU	 85	//(B3IS35LDU) Клапан «ВПИС2» открыт (обесточен)
#define B4IS10LDU	 BUFFER[230]	//(B4IS10LDU) Клапан «Подъём НИ2» открыт (обесточен)
#define idB4IS10LDU	 86	//(B4IS10LDU) Клапан «Подъём НИ2» открыт (обесточен)
#define R6IS31LDU	 BUFFER[232]	//(R6IS31LDU) контроль задней двери ШС
#define idR6IS31LDU	 87	//(R6IS31LDU) контроль задней двери ШС
#define R6IS32LDU	 BUFFER[234]	//(R6IS32LDU) контроль передней двери ШС
#define idR6IS32LDU	 88	//(R6IS32LDU) контроль передней двери ШС
#define R6IS42LDU	 BUFFER[236]	//(R6IS42LDU) контроль передней двери ШЭП
#define idR6IS42LDU	 89	//(R6IS42LDU) контроль передней двери ШЭП
#define R6IS41LDU	 BUFFER[238]	//(R6IS41LDU) контроль задней двери ШЭП
#define idR6IS41LDU	 90	//(R6IS41LDU) контроль задней двери ШЭП
#define R6IS52LDU	 BUFFER[240]	//(R6IS52LDU) контроль передней двери ШПУ
#define idR6IS52LDU	 91	//(R6IS52LDU) контроль передней двери ШПУ
#define R6IS51LDU	 BUFFER[242]	//(R6IS51LDU) контроль задней двери ШПУ
#define idR6IS51LDU	 92	//(R6IS51LDU) контроль задней двери ШПУ
#define R3AD10LDU	 BUFFER[244]	//(R3AD10LDU) Гомогенные двери-1 открыть
#define idR3AD10LDU	 93	//(R3AD10LDU) Гомогенные двери-1 открыть
#define R3AD20LDU	 BUFFER[246]	//(R3AD20LDU) Гомогенные двери-1 закрыть
#define idR3AD20LDU	 94	//(R3AD20LDU) Гомогенные двери-1 закрыть
#define R3IS11LDU	 BUFFER[248]	//(R3IS11LDU) Приход на ВУ гомогенных дверей-1
#define idR3IS11LDU	 95	//(R3IS11LDU) Приход на ВУ гомогенных дверей-1
#define R3IS21LDU	 BUFFER[250]	//(R3IS21LDU) Приход на НУ гомогенных дверей-1
#define idR3IS21LDU	 96	//(R3IS21LDU) Приход на НУ гомогенных дверей-1
#define R3AZ03LDU	 BUFFER[252]	//(R3AZ03LDU) Несанкционированное перемещение гомогенных дверей
#define idR3AZ03LDU	 97	//(R3AZ03LDU) Несанкционированное перемещение гомогенных дверей
#define R3AB01LDU	 BUFFER[254]	//(R3AB01LDU) Блокировка движения гомогенных дверей - Превышение времени движения
#define idR3AB01LDU	 98	//(R3AB01LDU) Блокировка движения гомогенных дверей - Превышение времени движения
#define R3AB02LDU	 BUFFER[256]	//(R3AB02LDU) Блокировка гомогенных дверей - Нет перемещения
#define idR3AB02LDU	 99	//(R3AB02LDU) Блокировка гомогенных дверей - Нет перемещения
#define R3AB04LDU	 BUFFER[258]	//(R3AB04LDU) Блокировка гомогенных дверей -Ошибка в направлении  движения
#define idR3AB04LDU	 100	//(R3AB04LDU) Блокировка гомогенных дверей -Ошибка в направлении  движения
#define R3VS30IDU	 BUFFER[260]	//(R3VS30IDU) Готовность к управлению гомогенных дверей-1
#define idR3VS30IDU	 101	//(R3VS30IDU) Готовность к управлению гомогенных дверей-1
#define R3VS20LDU	 BUFFER[263]	//(R3VS20LDU) Движение дверей-1  к закрыто
#define idR3VS20LDU	 102	//(R3VS20LDU) Движение дверей-1  к закрыто
#define R3AZ13LDU	 BUFFER[265]	//(R3AZ13LDU) Несанкционированное перемещение гомогенных дверей-2
#define idR3AZ13LDU	 103	//(R3AZ13LDU) Несанкционированное перемещение гомогенных дверей-2
#define R3AB11LDU	 BUFFER[267]	//(R3AB11LDU) Блокировка движения гомогенных дверей-2 - Превышение времени движения
#define idR3AB11LDU	 104	//(R3AB11LDU) Блокировка движения гомогенных дверей-2 - Превышение времени движения
#define R3AB12LDU	 BUFFER[269]	//(R3AB12LDU) Блокировка гомогенных дверей-2 - Нет перемещения
#define idR3AB12LDU	 105	//(R3AB12LDU) Блокировка гомогенных дверей-2 - Нет перемещения
#define R3AB14LDU	 BUFFER[271]	//(R3AB14LDU) Блокировка гомогенных дверей-2 -Ошибка в направлении  движения
#define idR3AB14LDU	 106	//(R3AB14LDU) Блокировка гомогенных дверей-2 -Ошибка в направлении  движения
#define A2VS01IDU	 BUFFER[273]	//(A2VS01IDU) Готовность к управлению РБ1
#define idA2VS01IDU	 107	//(A2VS01IDU) Готовность к управлению РБ1
#define A4VS01IDU	 BUFFER[276]	//(A4VS01IDU) Готовность к управлению НИ1
#define idA4VS01IDU	 108	//(A4VS01IDU) Готовность к управлению НИ1
#define A4VS12LDU	 BUFFER[279]	//(A4VS12LDU) Движение НИ1 в сторону ВУ
#define idA4VS12LDU	 109	//(A4VS12LDU) Движение НИ1 в сторону ВУ
#define A4VS22LDU	 BUFFER[281]	//(A4VS22LDU) Движение НИ1 в сторону НУ
#define idA4VS22LDU	 110	//(A4VS22LDU) Движение НИ1 в сторону НУ
#define B4VS01IDU	 BUFFER[283]	//(B4VS01IDU) Готовность к управлению НИ2
#define idB4VS01IDU	 111	//(B4VS01IDU) Готовность к управлению НИ2
#define B4VS12LDU	 BUFFER[286]	//(B4VS12LDU) Движение НИ2 в сторону ВУ
#define idB4VS12LDU	 112	//(B4VS12LDU) Движение НИ2 в сторону ВУ
#define B4VS22LDU	 BUFFER[288]	//(B4VS22LDU) Движение НИ2 в сторону НУ
#define idB4VS22LDU	 113	//(B4VS22LDU) Движение НИ2 в сторону НУ
#define A5VS01IDU	 BUFFER[290]	//(A5VS01IDU) Готовность к управлению НЛ1
#define idA5VS01IDU	 114	//(A5VS01IDU) Готовность к управлению НЛ1
#define B5VS01IDU	 BUFFER[293]	//(B5VS01IDU) Готовность к управлению НЛ2
#define idB5VS01IDU	 115	//(B5VS01IDU) Готовность к управлению НЛ2
#define A6VS01IDU	 BUFFER[296]	//(A6VS01IDU) Готовность к управлению БЗ1
#define idA6VS01IDU	 116	//(A6VS01IDU) Готовность к управлению БЗ1
#define R4VS01IDU	 BUFFER[299]	//(R4VS01IDU) Готовность к управлению тележкой реактора
#define idR4VS01IDU	 117	//(R4VS01IDU) Готовность к управлению тележкой реактора
#define R5AD10LDU	 BUFFER[302]	//(R5AD10LDU) Открыть ворота отстойной зоны
#define idR5AD10LDU	 118	//(R5AD10LDU) Открыть ворота отстойной зоны
#define R5AD20LDU	 BUFFER[304]	//(R5AD20LDU) Закрыть ворота отстойной зоны
#define idR5AD20LDU	 119	//(R5AD20LDU) Закрыть ворота отстойной зоны
#define R5IS21LDU	 BUFFER[306]	//(R5IS21LDU) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	 120	//(R5IS21LDU) Приход на НУ ворот отстойной зоны
#define R5AZ03LDU	 BUFFER[308]	//(R5AZ03LDU) Несанкционированное перемещение ворот отстойной зоны
#define idR5AZ03LDU	 121	//(R5AZ03LDU) Несанкционированное перемещение ворот отстойной зоны
#define R5AB01LDU	 BUFFER[310]	//(R5AB01LDU) Блокировка движения ворот отстойной зоны - Превышение времени движения
#define idR5AB01LDU	 122	//(R5AB01LDU) Блокировка движения ворот отстойной зоны - Превышение времени движения
#define R5AB02LDU	 BUFFER[312]	//(R5AB02LDU) Блокировка ворот отстойной зоны - Нет перемещения
#define idR5AB02LDU	 123	//(R5AB02LDU) Блокировка ворот отстойной зоны - Нет перемещения
#define R5AB04LDU	 BUFFER[314]	//(R5AB04LDU) Блокировка ворот отстойной зоны -Ошибка в направлении  движения
#define idR5AB04LDU	 124	//(R5AB04LDU) Блокировка ворот отстойной зоны -Ошибка в направлении  движения
#define R5VS01IDU	 BUFFER[316]	//(R5VS01IDU) Готовность к управлению ворот отстойной зоны
#define idR5VS01IDU	 125	//(R5VS01IDU) Готовность к управлению ворот отстойной зоны
#define R2VS01IDU	 BUFFER[319]	//(R2VS01IDU) Готовность к управлению МДЗ2
#define idR2VS01IDU	 126	//(R2VS01IDU) Готовность к управлению МДЗ2
#define R1VS01IDU	 BUFFER[322]	//(R1VS01IDU) Готовность к управлению МДЗ1
#define idR1VS01IDU	 127	//(R1VS01IDU) Готовность к управлению МДЗ1
#define A9IS11LDU	 BUFFER[325]	//(A9IS11LDU) Приход на ВУ НИ ДС1
#define idA9IS11LDU	 128	//(A9IS11LDU) Приход на ВУ НИ ДС1
#define R0VL01IDU	 BUFFER[327]	//(R0VL01IDU) До импульса минут
#define idR0VL01IDU	 129	//(R0VL01IDU) До импульса минут
#define R0VL11IDU	 BUFFER[330]	//(R0VL11IDU) До импульса секунд
#define idR0VL11IDU	 130	//(R0VL11IDU) До импульса секунд
#define R0VL06RDU	 BUFFER[333]	//(R0VL06RDU) Индикация (Время задержки от ВУ РБ)
#define idR0VL06RDU	 131	//(R0VL06RDU) Индикация (Время задержки от ВУ РБ)
#define B3AD33LDU	 BUFFER[338]	//(B3AD33LDU) Клапан «ВЫСТРЕЛ ИС2» закрыть (обесточить)
#define idB3AD33LDU	 132	//(B3AD33LDU) Клапан «ВЫСТРЕЛ ИС2» закрыть (обесточить)
#define B3IS11LDU	 BUFFER[340]	//(B3IS11LDU) Приход на ВУ ИС2
#define idB3IS11LDU	 133	//(B3IS11LDU) Приход на ВУ ИС2
#define R0VL02RDU	 BUFFER[342]	//(R0VL02RDU) Индикация (Время задержки ИНИ)
#define idR0VL02RDU	 134	//(R0VL02RDU) Индикация (Время задержки ИНИ)
#define R8AD21LDU	 BUFFER[347]	//(R8AD21LDU) Запуск системы инициирования
#define idR8AD21LDU	 135	//(R8AD21LDU) Запуск системы инициирования
#define R0AD14LDU	 BUFFER[349]	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 136	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
#define R0VL04RDU	 BUFFER[351]	//(R0VL04RDU) Индикация (Время срабатывания верхней АС II УР)
#define idR0VL04RDU	 137	//(R0VL04RDU) Индикация (Время срабатывания верхней АС II УР)
#define R0AB04LDU	 BUFFER[356]	//(R0AB04LDU) Нарушение времени срабатывания верхней АС II УР
#define idR0AB04LDU	 138	//(R0AB04LDU) Нарушение времени срабатывания верхней АС II УР
#define R0AB06LDU	 BUFFER[358]	//(R0AB06LDU) Нарушение времени задержки от ВУ РБ
#define idR0AB06LDU	 139	//(R0AB06LDU) Нарушение времени задержки от ВУ РБ
#define R0AB02LDU	 BUFFER[360]	//(R0AB02LDU) Нарушение времени задержки ИНИ
#define idR0AB02LDU	 140	//(R0AB02LDU) Нарушение времени задержки ИНИ
#define R0AD13LDU	 BUFFER[362]	//(R0AD13LDU) Имитация прихода на ВУ ИС
#define idR0AD13LDU	 141	//(R0AD13LDU) Имитация прихода на ВУ ИС
#define R0VL03RDU	 BUFFER[364]	//(R0VL03RDU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define idR0VL03RDU	 142	//(R0VL03RDU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define R0AD15LDU	 BUFFER[369]	//(R0AD15LDU) Имитация ухода с НУП ИС
#define idR0AD15LDU	 143	//(R0AD15LDU) Имитация ухода с НУП ИС
#define R0VL05RDU	 BUFFER[371]	//(R0VL05RDU) Индикация (Время срабатывания АЗ от НУП ИС)
#define idR0VL05RDU	 144	//(R0VL05RDU) Индикация (Время срабатывания АЗ от НУП ИС)
#define R0VL21IDU	 BUFFER[376]	//(R0VL21IDU) Декатрон
#define idR0VL21IDU	 145	//(R0VL21IDU) Декатрон
#define R0VX03LDU	 BUFFER[379]	//(R0VX03LDU) Готовность 2 мин
#define idR0VX03LDU	 146	//(R0VX03LDU) Готовность 2 мин
#define R0VS21IDU	 BUFFER[381]	//(R0VS21IDU) Индикация ВИД ПРОВЕРКИ
#define idR0VS21IDU	 147	//(R0VS21IDU) Индикация ВИД ПРОВЕРКИ
#define A1VS01IDU	 BUFFER[384]	//(A1VS01IDU) Готовность к управлению ББ1
#define idA1VS01IDU	 148	//(A1VS01IDU) Готовность к управлению ББ1
#define B1VS01IDU	 BUFFER[387]	//(B1VS01IDU) Готовность к управлению ББ2
#define idB1VS01IDU	 149	//(B1VS01IDU) Готовность к управлению ББ2
#define A3VS01IDU	 BUFFER[390]	//(A3VS01IDU) Готовность к управлению ИС1
#define idA3VS01IDU	 150	//(A3VS01IDU) Готовность к управлению ИС1
#define B3VS01IDU	 BUFFER[393]	//(B3VS01IDU) Готовность к управлению ИС2
#define idB3VS01IDU	 151	//(B3VS01IDU) Готовность к управлению ИС2
#define A3MD12LP1	 BUFFER[396]	//(A3MD12LP1) Переключатель «РАЗРЕШИТЬ» ИС1
#define idA3MD12LP1	 152	//(A3MD12LP1) Переключатель «РАЗРЕШИТЬ» ИС1
#define A3MD11LP1	 BUFFER[398]	//(A3MD11LP1) Кнопка «ПУСК ИС1»
#define idA3MD11LP1	 153	//(A3MD11LP1) Кнопка «ПУСК ИС1»
#define R0MD33LP1	 BUFFER[400]	//(R0MD33LP1) Переключатель «РАЗРЕШИТЬ» МДЗ
#define idR0MD33LP1	 154	//(R0MD33LP1) Переключатель «РАЗРЕШИТЬ» МДЗ
#define A1MD12LP1	 BUFFER[402]	//(A1MD12LP1) Переключатель «РАЗРЕШИТЬ» ББ1
#define idA1MD12LP1	 155	//(A1MD12LP1) Переключатель «РАЗРЕШИТЬ» ББ1
#define A1MD11LP1	 BUFFER[404]	//(A1MD11LP1) Кнопка «ПУСК ББ1»
#define idA1MD11LP1	 156	//(A1MD11LP1) Кнопка «ПУСК ББ1»
#define R0MW14IP2	 BUFFER[406]	//(R0MW14IP2) Переключатель «Обдув»
#define idR0MW14IP2	 157	//(R0MW14IP2) Переключатель «Обдув»
#define A7AP31LDU	 BUFFER[409]	//(A7AP31LDU) Клапан «Обдув АЗ1» открыть (обесточить)
#define idA7AP31LDU	 158	//(A7AP31LDU) Клапан «Обдув АЗ1» открыть (обесточить)
#define B7AP31LDU	 BUFFER[411]	//(B7AP31LDU) Клапан «Обдув АЗ2» открыть (обесточить)
#define idB7AP31LDU	 159	//(B7AP31LDU) Клапан «Обдув АЗ2» открыть (обесточить)
#define R0MW12IP2	 BUFFER[413]	//(R0MW12IP2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define idR0MW12IP2	 160	//(R0MW12IP2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define R0MW17LP1	 BUFFER[416]	//(R0MW17LP1) Переключатель «АВТ/Р»
#define idR0MW17LP1	 161	//(R0MW17LP1) Переключатель «АВТ/Р»
#define R0VW13LDU	 BUFFER[418]	//(R0VW13LDU) Индикация выбора АЗ1 или АЗ1+АЗ2
#define idR0VW13LDU	 162	//(R0VW13LDU) Индикация выбора АЗ1 или АЗ1+АЗ2
#define R0VW23LDU	 BUFFER[420]	//(R0VW23LDU) Индикация выбора АЗ2 или АЗ1+АЗ2
#define idR0VW23LDU	 163	//(R0VW23LDU) Индикация выбора АЗ2 или АЗ1+АЗ2
#define R0VX08IDU	 BUFFER[422]	//(R0VX08IDU) Индикация Режим
#define idR0VX08IDU	 164	//(R0VX08IDU) Индикация Режим
#define R0VX09LDU	 BUFFER[425]	//(R0VX09LDU) Индикация регулятор мощности включен/отключен
#define idR0VX09LDU	 165	//(R0VX09LDU) Индикация регулятор мощности включен/отключен
#define R0VS17LDU	 BUFFER[427]	//(R0VS17LDU) Индикация выбора АВТОМАТ
#define idR0VS17LDU	 166	//(R0VS17LDU) Индикация выбора АВТОМАТ
#define R5VS12LDU	 BUFFER[429]	//(R5VS12LDU) Движение ворот к открыты
#define idR5VS12LDU	 167	//(R5VS12LDU) Движение ворот к открыты
#define R5VS22LDU	 BUFFER[431]	//(R5VS22LDU) Движение ворот к закрыты
#define idR5VS22LDU	 168	//(R5VS22LDU) Движение ворот к закрыты
#define A2VS32LDU	 BUFFER[433]	//(A2VS32LDU) Индикация  «СБРОС РБ1»
#define idA2VS32LDU	 169	//(A2VS32LDU) Индикация  «СБРОС РБ1»
#define B2VS32LDU	 BUFFER[435]	//(B2VS32LDU) Индикация  «СБРОС РБ2»
#define idB2VS32LDU	 170	//(B2VS32LDU) Индикация  «СБРОС РБ2»
#define A3VX01LDU	 BUFFER[437]	//(A3VX01LDU) Индикация Выстрел ИС1
#define idA3VX01LDU	 171	//(A3VX01LDU) Индикация Выстрел ИС1
#define A3IS11LDU	 BUFFER[439]	//(A3IS11LDU) Приход на ВУ ИС1
#define idA3IS11LDU	 172	//(A3IS11LDU) Приход на ВУ ИС1
#define B3VX01LDU	 BUFFER[441]	//(B3VX01LDU) Индикация Выстрел ИС2
#define idB3VX01LDU	 173	//(B3VX01LDU) Индикация Выстрел ИС2
#define R0VS18LDU	 BUFFER[443]	//(R0VS18LDU) Индикация  «Проверка» схем сброса
#define idR0VS18LDU	 174	//(R0VS18LDU) Индикация  «Проверка» схем сброса
#define A9IS21LDU	 BUFFER[445]	//(A9IS21LDU) Приход на НУ НИ ДС1
#define idA9IS21LDU	 175	//(A9IS21LDU) Приход на НУ НИ ДС1
#define B9IS11LDU	 BUFFER[447]	//(B9IS11LDU) Приход на ВУ НИ ДС2
#define idB9IS11LDU	 176	//(B9IS11LDU) Приход на ВУ НИ ДС2
#define B9IS21LDU	 BUFFER[449]	//(B9IS21LDU) Приход на НУ НИ ДС2
#define idB9IS21LDU	 177	//(B9IS21LDU) Приход на НУ НИ ДС2
#define B9AD10LDU	 BUFFER[451]	//(B9AD10LDU) Открыть клапан Подъем НИ ДС2
#define idB9AD10LDU	 178	//(B9AD10LDU) Открыть клапан Подъем НИ ДС2
#define A9AD10LDU	 BUFFER[453]	//(A9AD10LDU) Открыть клапан Подъем НИ ДС1
#define idA9AD10LDU	 179	//(A9AD10LDU) Открыть клапан Подъем НИ ДС1
#define A9AZ03LDU	 BUFFER[455]	//(A9AZ03LDU) Несанкционированное перемещение НИ ДС1
#define idA9AZ03LDU	 180	//(A9AZ03LDU) Несанкционированное перемещение НИ ДС1
#define A9AB01LDU	 BUFFER[457]	//(A9AB01LDU) Блокировка движения НИ ДС1 - Превышение времени движения
#define idA9AB01LDU	 181	//(A9AB01LDU) Блокировка движения НИ ДС1 - Превышение времени движения
#define A9AB02LDU	 BUFFER[459]	//(A9AB02LDU) Блокировка НИ ДС1 - Нет перемещения
#define idA9AB02LDU	 182	//(A9AB02LDU) Блокировка НИ ДС1 - Нет перемещения
#define B9AZ03LDU	 BUFFER[461]	//(B9AZ03LDU) Несанкционированное перемещение НИ ДС2
#define idB9AZ03LDU	 183	//(B9AZ03LDU) Несанкционированное перемещение НИ ДС2
#define B9AB01LDU	 BUFFER[463]	//(B9AB01LDU) Блокировка движения НИ ДС2 - Превышение времени движения
#define idB9AB01LDU	 184	//(B9AB01LDU) Блокировка движения НИ ДС2 - Превышение времени движения
#define B9AB02LDU	 BUFFER[465]	//(B9AB02LDU) Блокировка НИ ДС2 - Нет перемещения
#define idB9AB02LDU	 185	//(B9AB02LDU) Блокировка НИ ДС2 - Нет перемещения
#define R0AB01LDU	 BUFFER[467]	//(R0AB01LDU) Режим проверки разрешён
#define idR0AB01LDU	 186	//(R0AB01LDU) Режим проверки разрешён
#define A3IS22LDU	 BUFFER[469]	//(A3IS22LDU) Приход на НУП ИС1
#define idA3IS22LDU	 187	//(A3IS22LDU) Приход на НУП ИС1
#define B3IS22LDU	 BUFFER[471]	//(B3IS22LDU) Приход на НУП ИС2
#define idB3IS22LDU	 188	//(B3IS22LDU) Приход на НУП ИС2
#define A2AD33LDU	 BUFFER[473]	//(A2AD33LDU) Клапан «Подъем РБ1» открыть
#define idA2AD33LDU	 189	//(A2AD33LDU) Клапан «Подъем РБ1» открыть
#define B2AD33LDU	 BUFFER[475]	//(B2AD33LDU) Клапан «Подъем РБ2» открыть
#define idB2AD33LDU	 190	//(B2AD33LDU) Клапан «Подъем РБ2» открыть
#define A3AD33LDU	 BUFFER[477]	//(A3AD33LDU) Клапан «ВЫСТРЕЛ ИС1» открыть (обесточить)
#define idA3AD33LDU	 191	//(A3AD33LDU) Клапан «ВЫСТРЕЛ ИС1» открыть (обесточить)
#define A3AD34LDU	 BUFFER[479]	//(A3AD34LDU) Клапан ВПИС1  открыть (обесточить)
#define idA3AD34LDU	 192	//(A3AD34LDU) Клапан ВПИС1  открыть (обесточить)
#define A3AD31LDU	 BUFFER[481]	//(A3AD31LDU) Клапан «СПУСК ИС1» открыть (обесточить)
#define idA3AD31LDU	 193	//(A3AD31LDU) Клапан «СПУСК ИС1» открыть (обесточить)
#define B3AD34LDU	 BUFFER[483]	//(B3AD34LDU) Клапан «ВПИС ИС2»  открыть (обесточить)
#define idB3AD34LDU	 194	//(B3AD34LDU) Клапан «ВПИС ИС2»  открыть (обесточить)
#define B3AD31LDU	 BUFFER[485]	//(B3AD31LDU) Клапан «СПУСК ИС2» открыть (обесточить)
#define idB3AD31LDU	 195	//(B3AD31LDU) Клапан «СПУСК ИС2» открыть (обесточить)
#define A2IS11LDU	 BUFFER[487]	//(A2IS11LDU) Приход на ВУ РБ1-СТР
#define idA2IS11LDU	 196	//(A2IS11LDU) Приход на ВУ РБ1-СТР
#define B2IS11LDU	 BUFFER[489]	//(B2IS11LDU) Приход на ВУ РБ2-СТР
#define idB2IS11LDU	 197	//(B2IS11LDU) Приход на ВУ РБ2-СТР
#define B3CP02RDU	 BUFFER[491]	//(B3CP02RDU) Текущее давление ВЫСТРЕЛ ИС2
#define idB3CP02RDU	 198	//(B3CP02RDU) Текущее давление ВЫСТРЕЛ ИС2
#define B3VP52LDU	 BUFFER[496]	//(B3VP52LDU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define idB3VP52LDU	 199	//(B3VP52LDU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define B3VP82LDU	 BUFFER[498]	//(B3VP82LDU) Давление ВЫСТРЕЛ ИС2 в норме
#define idB3VP82LDU	 200	//(B3VP82LDU) Давление ВЫСТРЕЛ ИС2 в норме
#define A3VP82LDU	 BUFFER[500]	//(A3VP82LDU) Давление ВЫСТРЕЛ ИС1 в норме
#define idA3VP82LDU	 201	//(A3VP82LDU) Давление ВЫСТРЕЛ ИС1 в норме
#define A3IP02IDU	 BUFFER[502]	//(A3IP02IDU) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	 202	//(A3IP02IDU) Текущее давление ВЫСТРЕЛ ИС1
#define B3IP02IDU	 BUFFER[505]	//(B3IP02IDU) Текущее давление ВЫСТРЕЛ ИС2
#define idB3IP02IDU	 203	//(B3IP02IDU) Текущее давление ВЫСТРЕЛ ИС2
#define A0VE01LDU	 BUFFER[508]	//(A0VE01LDU) Напряжение в системы АЗ1 подано
#define idA0VE01LDU	 204	//(A0VE01LDU) Напряжение в системы АЗ1 подано
#define B0VE01LDU	 BUFFER[510]	//(B0VE01LDU) Напряжение в системы АЗ2 подано
#define idB0VE01LDU	 205	//(B0VE01LDU) Напряжение в системы АЗ2 подано
#define A0VP01LDU	 BUFFER[512]	//(A0VP01LDU) Давление в системы АЗ1 подано
#define idA0VP01LDU	 206	//(A0VP01LDU) Давление в системы АЗ1 подано
#define B0VP01LDU	 BUFFER[514]	//(B0VP01LDU) Давление в системы АЗ2 подано
#define idB0VP01LDU	 207	//(B0VP01LDU) Давление в системы АЗ2 подано
#define A0EE01LZ1	 BUFFER[516]	//(A0EE01LZ1) Исправность АКНП1
#define idA0EE01LZ1	 208	//(A0EE01LZ1) Исправность АКНП1
#define A0EE03LZ1	 BUFFER[518]	//(A0EE03LZ1) Исправность АКНП3
#define idA0EE03LZ1	 209	//(A0EE03LZ1) Исправность АКНП3
#define A0EE02LZ1	 BUFFER[520]	//(A0EE02LZ1) Исправность АКНП2
#define idA0EE02LZ1	 210	//(A0EE02LZ1) Исправность АКНП2
#define A0EE04LZ1	 BUFFER[522]	//(A0EE04LZ1) Исправность АКНП4
#define idA0EE04LZ1	 211	//(A0EE04LZ1) Исправность АКНП4
#define A0VN01LDU	 BUFFER[524]	//(A0VN01LDU) Каналы АЗ1 проверены
#define idA0VN01LDU	 212	//(A0VN01LDU) Каналы АЗ1 проверены
#define B0VN01LDU	 BUFFER[526]	//(B0VN01LDU) Каналы АЗ2 проверены
#define idB0VN01LDU	 213	//(B0VN01LDU) Каналы АЗ2 проверены
#define A0EE01LZ2	 BUFFER[528]	//(A0EE01LZ2) Исправность АКНП1
#define idA0EE01LZ2	 214	//(A0EE01LZ2) Исправность АКНП1
#define A0EE03LZ2	 BUFFER[530]	//(A0EE03LZ2) Исправность АКНП3
#define idA0EE03LZ2	 215	//(A0EE03LZ2) Исправность АКНП3
#define A0EE02LZ2	 BUFFER[532]	//(A0EE02LZ2) Исправность АКНП2
#define idA0EE02LZ2	 216	//(A0EE02LZ2) Исправность АКНП2
#define A0EE04LZ2	 BUFFER[534]	//(A0EE04LZ2) Исправность АКНП4
#define idA0EE04LZ2	 217	//(A0EE04LZ2) Исправность АКНП4
#define A0VP71LZ1	 BUFFER[536]	//(A0VP71LZ1) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ1	 218	//(A0VP71LZ1) АЗ по АС любого давления для АЗ1
#define A0VP71LZ2	 BUFFER[538]	//(A0VP71LZ2) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ2	 219	//(A0VP71LZ2) АЗ по АС любого давления для АЗ1
#define A1IC01UDU	 BUFFER[540]	//(A1IC01UDU) Координата штока ББ1 (дел.энк)
#define idA1IC01UDU	 220	//(A1IC01UDU) Координата штока ББ1 (дел.энк)
#define A1VC01RDU	 BUFFER[545]	//(A1VC01RDU) Координата ББ1, мм
#define idA1VC01RDU	 221	//(A1VC01RDU) Координата ББ1, мм
#define A1IS11LDU	 BUFFER[550]	//(A1IS11LDU) Приход на ВУ ББ1
#define idA1IS11LDU	 222	//(A1IS11LDU) Приход на ВУ ББ1
#define B1MC01LC1	 BUFFER[552]	//(B1MC01LC1) Настроить энкодер ББ2
#define idB1MC01LC1	 223	//(B1MC01LC1) Настроить энкодер ББ2
#define B1MC01LC2	 BUFFER[554]	//(B1MC01LC2) Настроить энкодер ББ2
#define idB1MC01LC2	 224	//(B1MC01LC2) Настроить энкодер ББ2
#define A1MC01LC1	 BUFFER[556]	//(A1MC01LC1) Настроить энкодер ББ1
#define idA1MC01LC1	 225	//(A1MC01LC1) Настроить энкодер ББ1
#define A1MC01LC2	 BUFFER[558]	//(A1MC01LC2) Настроить энкодер ББ1
#define idA1MC01LC2	 226	//(A1MC01LC2) Настроить энкодер ББ1
#define B2MC01LC1	 BUFFER[560]	//(B2MC01LC1) Настроить энкодер РБ2
#define idB2MC01LC1	 227	//(B2MC01LC1) Настроить энкодер РБ2
#define B2MC01LC2	 BUFFER[562]	//(B2MC01LC2) Настроить энкодер РБ2
#define idB2MC01LC2	 228	//(B2MC01LC2) Настроить энкодер РБ2
#define A2MC01LC1	 BUFFER[564]	//(A2MC01LC1) Настроить энкодер РБ1
#define idA2MC01LC1	 229	//(A2MC01LC1) Настроить энкодер РБ1
#define A2MC01LC2	 BUFFER[566]	//(A2MC01LC2) Настроить энкодер РБ1
#define idA2MC01LC2	 230	//(A2MC01LC2) Настроить энкодер РБ1
#define B3MC01LC1	 BUFFER[568]	//(B3MC01LC1) Настроить энкодер ИС2
#define idB3MC01LC1	 231	//(B3MC01LC1) Настроить энкодер ИС2
#define B3MC01LC2	 BUFFER[570]	//(B3MC01LC2) Настроить энкодер ИС2
#define idB3MC01LC2	 232	//(B3MC01LC2) Настроить энкодер ИС2
#define A3MC01LC1	 BUFFER[572]	//(A3MC01LC1) Настроить энкодер ИС1
#define idA3MC01LC1	 233	//(A3MC01LC1) Настроить энкодер ИС1
#define A3MC01LC2	 BUFFER[574]	//(A3MC01LC2) Настроить энкодер ИС1
#define idA3MC01LC2	 234	//(A3MC01LC2) Настроить энкодер ИС1
#define B8MC01LC1	 BUFFER[576]	//(B8MC01LC1) Настроить энкодер АЗ2
#define idB8MC01LC1	 235	//(B8MC01LC1) Настроить энкодер АЗ2
#define B8MC01LC2	 BUFFER[578]	//(B8MC01LC2) Настроить энкодер АЗ2
#define idB8MC01LC2	 236	//(B8MC01LC2) Настроить энкодер АЗ2
#define A8MC01LC1	 BUFFER[580]	//(A8MC01LC1) Настроить энкодер ДС2
#define idA8MC01LC1	 237	//(A8MC01LC1) Настроить энкодер ДС2
#define A8MC01LC2	 BUFFER[582]	//(A8MC01LC2) Настроить энкодер ДС2
#define idA8MC01LC2	 238	//(A8MC01LC2) Настроить энкодер ДС2
#define A3VP42LDU	 BUFFER[584]	//(A3VP42LDU) Давление ВЫСТРЕЛ ИС1 ниже АС
#define idA3VP42LDU	 239	//(A3VP42LDU) Давление ВЫСТРЕЛ ИС1 ниже АС
#define A3CP02RDU	 BUFFER[586]	//(A3CP02RDU) Текущее давление ВЫСТРЕЛ ИС1
#define idA3CP02RDU	 240	//(A3CP02RDU) Текущее давление ВЫСТРЕЛ ИС1
#define A3VP52LDU	 BUFFER[591]	//(A3VP52LDU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define idA3VP52LDU	 241	//(A3VP52LDU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define B3VP42LDU	 BUFFER[593]	//(B3VP42LDU) Давление ВЫСТРЕЛ ИС2 ниже АС
#define idB3VP42LDU	 242	//(B3VP42LDU) Давление ВЫСТРЕЛ ИС2 ниже АС
#define R1IE01LDU	 BUFFER[595]	//(R1IE01LDU) Исправность ИП МДЗ1
#define idR1IE01LDU	 243	//(R1IE01LDU) Исправность ИП МДЗ1
#define R2IE01LDU	 BUFFER[597]	//(R2IE01LDU) Исправность ИП МДЗ2
#define idR2IE01LDU	 244	//(R2IE01LDU) Исправность ИП МДЗ2
#define R6IS61LDU	 BUFFER[599]	//(R6IS61LDU) Исправность 3-х  фазной сети
#define idR6IS61LDU	 245	//(R6IS61LDU) Исправность 3-х  фазной сети
#define R6IS64LDU	 BUFFER[601]	//(R6IS64LDU) Исправность ВИП ССДИ-35 1канал
#define idR6IS64LDU	 246	//(R6IS64LDU) Исправность ВИП ССДИ-35 1канал
#define R6IS65LDU	 BUFFER[603]	//(R6IS65LDU) Исправность ВИП ССДИ-35 2канал
#define idR6IS65LDU	 247	//(R6IS65LDU) Исправность ВИП ССДИ-35 2канал
#define R6IS62LDU	 BUFFER[605]	//(R6IS62LDU) Исправность ВИП ССДИ-39 1канал
#define idR6IS62LDU	 248	//(R6IS62LDU) Исправность ВИП ССДИ-39 1канал
#define R6IS63LDU	 BUFFER[607]	//(R6IS63LDU) Исправность ВИП ССДИ-39 2канал
#define idR6IS63LDU	 249	//(R6IS63LDU) Исправность ВИП ССДИ-39 2канал
#define R6IS66LZ2	 BUFFER[609]	//(R6IS66LZ2) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZ2	 250	//(R6IS66LZ2) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZ1	 BUFFER[611]	//(R6IS67LZ1) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZ1	 251	//(R6IS67LZ1) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZ1	 BUFFER[613]	//(R6IS68LZ1) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZ1	 252	//(R6IS68LZ1) Исправность ВИП 4,0 (№7) ССДИ-2
#define A3VC01RDU	 BUFFER[615]	//(A3VC01RDU) Координата ИС1, мм
#define idA3VC01RDU	 253	//(A3VC01RDU) Координата ИС1, мм
#define A2VC01RDU	 BUFFER[620]	//(A2VC01RDU) Координата РБ1, мм
#define idA2VC01RDU	 254	//(A2VC01RDU) Координата РБ1, мм
#define B2VC01RDU	 BUFFER[625]	//(B2VC01RDU) Координата РБ2, мм
#define idB2VC01RDU	 255	//(B2VC01RDU) Координата РБ2, мм
#define B8VC01RDU	 BUFFER[630]	//(B8VC01RDU) Координата АЗ2, мм
#define idB8VC01RDU	 256	//(B8VC01RDU) Координата АЗ2, мм
#define A4VP82LDU	 BUFFER[635]	//(A4VP82LDU) Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	 257	//(A4VP82LDU) Давление ПОДЪЁМ НИ1 в норме
#define B4VP82LDU	 BUFFER[637]	//(B4VP82LDU) Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	 258	//(B4VP82LDU) Давление ПОДЪЁМ НИ2 в норме
#define A2VP82LDU	 BUFFER[639]	//(A2VP82LDU) Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	 259	//(A2VP82LDU) Давление ПОДЪЁМ РБ1 в норме
#define B2VP82LDU	 BUFFER[641]	//(B2VP82LDU) Давление ПОДЪЁМ РБ2 в норме
#define idB2VP82LDU	 260	//(B2VP82LDU) Давление ПОДЪЁМ РБ2 в норме
#define A3VP81LDU	 BUFFER[643]	//(A3VP81LDU) Давление СПУСК ИС1 в норме
#define idA3VP81LDU	 261	//(A3VP81LDU) Давление СПУСК ИС1 в норме
#define B3VP81LDU	 BUFFER[645]	//(B3VP81LDU) Давление СПУСК ИС2 в норме
#define idB3VP81LDU	 262	//(B3VP81LDU) Давление СПУСК ИС2 в норме
#define R6IS66LZ1	 BUFFER[647]	//(R6IS66LZ1) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZ1	 263	//(R6IS66LZ1) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZ2	 BUFFER[649]	//(R6IS67LZ2) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZ2	 264	//(R6IS67LZ2) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZ2	 BUFFER[651]	//(R6IS68LZ2) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZ2	 265	//(R6IS68LZ2) Исправность ВИП 4,0 (№7) ССДИ-2
#define B0VP71LZ1	 BUFFER[653]	//(B0VP71LZ1) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ1	 266	//(B0VP71LZ1) АЗ по АС любого давления для АЗ2
#define B0VP71LZ2	 BUFFER[655]	//(B0VP71LZ2) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ2	 267	//(B0VP71LZ2) АЗ по АС любого давления для АЗ2
#define A0VS11LDU	 BUFFER[657]	//(A0VS11LDU) АЗ1 готова к работе
#define idA0VS11LDU	 268	//(A0VS11LDU) АЗ1 готова к работе
#define B0VS11LDU	 BUFFER[659]	//(B0VS11LDU) АЗ2 готова к работе
#define idB0VS11LDU	 269	//(B0VS11LDU) АЗ2 готова к работе
#define A1IE01LDU	 BUFFER[661]	//(A1IE01LDU) Исправность БУШД ББ1
#define idA1IE01LDU	 270	//(A1IE01LDU) Исправность БУШД ББ1
#define A3IE01LDU	 BUFFER[663]	//(A3IE01LDU) Исправность БУШД ИС1
#define idA3IE01LDU	 271	//(A3IE01LDU) Исправность БУШД ИС1
#define A2IE01LDU	 BUFFER[665]	//(A2IE01LDU) Исправность БУШД РБ1
#define idA2IE01LDU	 272	//(A2IE01LDU) Исправность БУШД РБ1
#define A1IE02LDU	 BUFFER[667]	//(A1IE02LDU) Исправность ИП ББ1
#define idA1IE02LDU	 273	//(A1IE02LDU) Исправность ИП ББ1
#define A3IE02LDU	 BUFFER[669]	//(A3IE02LDU) Исправность ИП ИС1
#define idA3IE02LDU	 274	//(A3IE02LDU) Исправность ИП ИС1
#define A2IE02LDU	 BUFFER[671]	//(A2IE02LDU) Исправность ИП РБ1
#define idA2IE02LDU	 275	//(A2IE02LDU) Исправность ИП РБ1
#define B1IE01LDU	 BUFFER[673]	//(B1IE01LDU) Исправность БУШД ББ2
#define idB1IE01LDU	 276	//(B1IE01LDU) Исправность БУШД ББ2
#define B2IE01LDU	 BUFFER[675]	//(B2IE01LDU) Исправность БУШД РБ2
#define idB2IE01LDU	 277	//(B2IE01LDU) Исправность БУШД РБ2
#define B3IE01LDU	 BUFFER[677]	//(B3IE01LDU) Исправность БУШД ИС2
#define idB3IE01LDU	 278	//(B3IE01LDU) Исправность БУШД ИС2
#define B1IE02LDU	 BUFFER[679]	//(B1IE02LDU) Исправность ИП ББ2
#define idB1IE02LDU	 279	//(B1IE02LDU) Исправность ИП ББ2
#define B3IE02LDU	 BUFFER[681]	//(B3IE02LDU) Исправность ИП ИС2
#define idB3IE02LDU	 280	//(B3IE02LDU) Исправность ИП ИС2
#define B2IE02LDU	 BUFFER[683]	//(B2IE02LDU) Исправность ИП РБ2
#define idB2IE02LDU	 281	//(B2IE02LDU) Исправность ИП РБ2
#define R0IE02LDU	 BUFFER[685]	//(R0IE02LDU) Исправность ИП 24 В-1
#define idR0IE02LDU	 282	//(R0IE02LDU) Исправность ИП 24 В-1
#define R0IE01LDU	 BUFFER[687]	//(R0IE01LDU) Исправность ИП 24 В-2
#define idR0IE01LDU	 283	//(R0IE01LDU) Исправность ИП 24 В-2
#define A6IE01LDU	 BUFFER[689]	//(A6IE01LDU) Исправность ИП БЗ1
#define idA6IE01LDU	 284	//(A6IE01LDU) Исправность ИП БЗ1
#define B6IE01LDU	 BUFFER[691]	//(B6IE01LDU) Исправность ИП БЗ2
#define idB6IE01LDU	 285	//(B6IE01LDU) Исправность ИП БЗ2
#define A8IE01LDU	 BUFFER[693]	//(A8IE01LDU) Исправность ИП ДС2
#define idA8IE01LDU	 286	//(A8IE01LDU) Исправность ИП ДС2
#define B5IE01LDU	 BUFFER[695]	//(B5IE01LDU) Исправность ИП НЛ2
#define idB5IE01LDU	 287	//(B5IE01LDU) Исправность ИП НЛ2
#define A5IE02LDU	 BUFFER[697]	//(A5IE02LDU) Исправность ИП НЛ1
#define idA5IE02LDU	 288	//(A5IE02LDU) Исправность ИП НЛ1
#define B3MC01RP1	 BUFFER[699]	//(B3MC01RP1) Заданная координата положения ИС2 мм
#define idB3MC01RP1	 289	//(B3MC01RP1) Заданная координата положения ИС2 мм
#define B8MC01RP2	 BUFFER[704]	//(B8MC01RP2) Заданная координата АЗ2 мм
#define idB8MC01RP2	 290	//(B8MC01RP2) Заданная координата АЗ2 мм
#define R0AB09LDU	 BUFFER[709]	//(R0AB09LDU) Ошибка в заданной координате ББ1
#define idR0AB09LDU	 291	//(R0AB09LDU) Ошибка в заданной координате ББ1
#define R0AB10LDU	 BUFFER[711]	//(R0AB10LDU) Ошибка в заданной координате ББ2
#define idR0AB10LDU	 292	//(R0AB10LDU) Ошибка в заданной координате ББ2
#define R0AB11LDU	 BUFFER[713]	//(R0AB11LDU) Ошибка в заданной координате  ИС1
#define idR0AB11LDU	 293	//(R0AB11LDU) Ошибка в заданной координате  ИС1
#define R0AB12LDU	 BUFFER[715]	//(R0AB12LDU) Ошибка в заданной координате  ИС2
#define idR0AB12LDU	 294	//(R0AB12LDU) Ошибка в заданной координате  ИС2
#define R0AB13LDU	 BUFFER[717]	//(R0AB13LDU) Ошибка в заданной координате  АЗ2
#define idR0AB13LDU	 295	//(R0AB13LDU) Ошибка в заданной координате  АЗ2
#define A4ZAV	 BUFFER[719]	//(A4ZAV) 
#define idA4ZAV	 296	//(A4ZAV) 
#define A6ZAV	 BUFFER[721]	//(A6ZAV) 
#define idA6ZAV	 297	//(A6ZAV) 
#define R2ZAV	 BUFFER[723]	//(R2ZAV) 
#define idR2ZAV	 298	//(R2ZAV) 
#define A5ZAV	 BUFFER[725]	//(A5ZAV) 
#define idA5ZAV	 299	//(A5ZAV) 
#define B8ZAV	 BUFFER[727]	//(B8ZAV) 
#define idB8ZAV	 300	//(B8ZAV) 
#define A2ZAV	 BUFFER[729]	//(A2ZAV) Завершение РБ1,2
#define idA2ZAV	 301	//(A2ZAV) Завершение РБ1,2
#define A8ZAV	 BUFFER[731]	//(A8ZAV) 
#define idA8ZAV	 302	//(A8ZAV) 
#define A9ZAV	 BUFFER[733]	//(A9ZAV) Завершение НИ ДС1(2)
#define idA9ZAV	 303	//(A9ZAV) Завершение НИ ДС1(2)
#define R4ABL	 BUFFER[735]	//(R4ABL) Блокировка тележки -
#define idR4ABL	 304	//(R4ABL) Блокировка тележки -
#define A4UP	 BUFFER[737]	//(A4UP) 
#define idA4UP	 305	//(A4UP) 
#define A4DW	 BUFFER[739]	//(A4DW) 
#define idA4DW	 306	//(A4DW) 
#define R0AB14LDU	 BUFFER[741]	//(R0AB14LDU) Режим проверки не разрешён: ИС2 ниже 55 мм
#define idR0AB14LDU	 307	//(R0AB14LDU) Режим проверки не разрешён: ИС2 ниже 55 мм
#define R0AB15LDU	 BUFFER[743]	//(R0AB15LDU) Режим проверки не разрешён: ИС1 ниже 55 мм
#define idR0AB15LDU	 308	//(R0AB15LDU) Режим проверки не разрешён: ИС1 ниже 55 мм
#define A3IS12LDU	 BUFFER[745]	//(A3IS12LDU) Приход на ВУ штока ИС1
#define idA3IS12LDU	 309	//(A3IS12LDU) Приход на ВУ штока ИС1
#define B3IS12LDU	 BUFFER[747]	//(B3IS12LDU) Приход на ВУ штока ИС2
#define idB3IS12LDU	 310	//(B3IS12LDU) Приход на ВУ штока ИС2
#define R3IS12LDU	 BUFFER[749]	//(R3IS12LDU) Приход на ВУ гомогенных дверей
#define idR3IS12LDU	 311	//(R3IS12LDU) Приход на ВУ гомогенных дверей
#define R2AD20LDU	 BUFFER[751]	//(R2AD20LDU) Поднять МДЗ2
#define idR2AD20LDU	 312	//(R2AD20LDU) Поднять МДЗ2
#define R2AD10LDU	 BUFFER[753]	//(R2AD10LDU) Опустить МДЗ2 в зону облучения
#define idR2AD10LDU	 313	//(R2AD10LDU) Опустить МДЗ2 в зону облучения
#define B8VS01IDU	 BUFFER[755]	//(B8VS01IDU) Готовность к управлению АЗ2
#define idB8VS01IDU	 314	//(B8VS01IDU) Готовность к управлению АЗ2
#define A8VS01IDU	 BUFFER[758]	//(A8VS01IDU) Готовность к управлению ДС2
#define idA8VS01IDU	 315	//(A8VS01IDU) Готовность к управлению ДС2
#define A1IE03LDU	 BUFFER[761]	//(A1IE03LDU) Движение ББ1 вперед (от БУШД)
#define idA1IE03LDU	 316	//(A1IE03LDU) Движение ББ1 вперед (от БУШД)
#define A1IE04LDU	 BUFFER[763]	//(A1IE04LDU) Движение ББ1 назад (от БУШД)
#define idA1IE04LDU	 317	//(A1IE04LDU) Движение ББ1 назад (от БУШД)
#define A2IE03LDU	 BUFFER[765]	//(A2IE03LDU) Движение РБ1 вперед (от БУШД)
#define idA2IE03LDU	 318	//(A2IE03LDU) Движение РБ1 вперед (от БУШД)
#define A2IE04LDU	 BUFFER[767]	//(A2IE04LDU) Движение РБ1 назад (от БУШД)
#define idA2IE04LDU	 319	//(A2IE04LDU) Движение РБ1 назад (от БУШД)
#define A3IE03LDU	 BUFFER[769]	//(A3IE03LDU) Движение ИС1 вперед (от БУШД)
#define idA3IE03LDU	 320	//(A3IE03LDU) Движение ИС1 вперед (от БУШД)
#define A3IE04LDU	 BUFFER[771]	//(A3IE04LDU) Движение ИС1 назад (от БУШД)
#define idA3IE04LDU	 321	//(A3IE04LDU) Движение ИС1 назад (от БУШД)
#define B1IE03LDU	 BUFFER[773]	//(B1IE03LDU) Движение ББ2 вперед (от БУШД)
#define idB1IE03LDU	 322	//(B1IE03LDU) Движение ББ2 вперед (от БУШД)
#define B1IE04LDU	 BUFFER[775]	//(B1IE04LDU) Движение ББ2 назад (от БУШД)
#define idB1IE04LDU	 323	//(B1IE04LDU) Движение ББ2 назад (от БУШД)
#define B2IE03LDU	 BUFFER[777]	//(B2IE03LDU) Движение РБ2 вперед (от БУШД)
#define idB2IE03LDU	 324	//(B2IE03LDU) Движение РБ2 вперед (от БУШД)
#define B2IE04LDU	 BUFFER[779]	//(B2IE04LDU) Движение РБ2 назад (от БУШД)
#define idB2IE04LDU	 325	//(B2IE04LDU) Движение РБ2 назад (от БУШД)
#define B3IE03LDU	 BUFFER[781]	//(B3IE03LDU) Движение ИС2 вперед (от БУШД)
#define idB3IE03LDU	 326	//(B3IE03LDU) Движение ИС2 вперед (от БУШД)
#define B3IE04LDU	 BUFFER[783]	//(B3IE04LDU) Движение ИС2 назад (от БУШД)
#define idB3IE04LDU	 327	//(B3IE04LDU) Движение ИС2 назад (от БУШД)
#define R0VS11LDU	 BUFFER[785]	//(R0VS11LDU) РУ не готова к работе
#define idR0VS11LDU	 328	//(R0VS11LDU) РУ не готова к работе
#define B6AB05LDU	 BUFFER[787]	//(B6AB05LDU) Блокировка открытия БЗ2- АНИ не установлен
#define idB6AB05LDU	 329	//(B6AB05LDU) Блокировка открытия БЗ2- АНИ не установлен
#define R0AB08LDU	 BUFFER[789]	//(R0AB08LDU) Блокировка кнопки ПУСК - тележка не у образцов
#define idR0AB08LDU	 330	//(R0AB08LDU) Блокировка кнопки ПУСК - тележка не у образцов
#define A1MC01RP1	 BUFFER[791]	//(A1MC01RP1) Заданная координата положения ББ1 мм
#define idA1MC01RP1	 331	//(A1MC01RP1) Заданная координата положения ББ1 мм
#define B1MC01RP1	 BUFFER[796]	//(B1MC01RP1) Заданная координата положения ББ2  мм
#define idB1MC01RP1	 332	//(B1MC01RP1) Заданная координата положения ББ2  мм
#define A3MC01RP1	 BUFFER[801]	//(A3MC01RP1) Заданная координата положения ИС1 мм
#define idA3MC01RP1	 333	//(A3MC01RP1) Заданная координата положения ИС1 мм
#define R0CN94LDU	 BUFFER[806]	//(R0CN94LDU) Скорость изменения мощности
#define idR0CN94LDU	 334	//(R0CN94LDU) Скорость изменения мощности
#define R0CN95LDU	 BUFFER[811]	//(R0CN95LDU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
#define idR0CN95LDU	 335	//(R0CN95LDU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
#define A2IS12LZ1	 BUFFER[814]	//(A2IS12LZ1) Магнит РБ1 зацеплен (для БАЗ1)
#define idA2IS12LZ1	 336	//(A2IS12LZ1) Магнит РБ1 зацеплен (для БАЗ1)
#define B2IS12LZ1	 BUFFER[816]	//(B2IS12LZ1) Магнит РБ2 зацеплен (для БАЗ1)
#define idB2IS12LZ1	 337	//(B2IS12LZ1) Магнит РБ2 зацеплен (для БАЗ1)
#define A2IS12LZ2	 BUFFER[818]	//(A2IS12LZ2) Магнит РБ1 зацеплен (для БАЗ2)
#define idA2IS12LZ2	 338	//(A2IS12LZ2) Магнит РБ1 зацеплен (для БАЗ2)
#define B2IS12LZ2	 BUFFER[820]	//(B2IS12LZ2) Магнит РБ2 зацеплен (для БАЗ2)
#define idB2IS12LZ2	 339	//(B2IS12LZ2) Магнит РБ2 зацеплен (для БАЗ2)
#define R0AD03LZ1	 BUFFER[822]	//(R0AD03LZ1) Имитация прихода на ВУ ИС (БАЗ1)
#define idR0AD03LZ1	 340	//(R0AD03LZ1) Имитация прихода на ВУ ИС (БАЗ1)
#define R0AD03LZ2	 BUFFER[824]	//(R0AD03LZ2) Имитация прихода на ВУ ИС (БАЗ2)
#define idR0AD03LZ2	 341	//(R0AD03LZ2) Имитация прихода на ВУ ИС (БАЗ2)
#define R0AD04LZ1	 BUFFER[826]	//(R0AD04LZ1) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define idR0AD04LZ1	 342	//(R0AD04LZ1) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define R0AD04LZ2	 BUFFER[828]	//(R0AD04LZ2) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define idR0AD04LZ2	 343	//(R0AD04LZ2) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define R0AD05LZ1	 BUFFER[830]	//(R0AD05LZ1) Имитация ухода с НУП ИС  (БАЗ1)
#define idR0AD05LZ1	 344	//(R0AD05LZ1) Имитация ухода с НУП ИС  (БАЗ1)
#define R0AD05LZ2	 BUFFER[832]	//(R0AD05LZ2) Имитация ухода с НУП ИС  (БАЗ2)
#define idR0AD05LZ2	 345	//(R0AD05LZ2) Имитация ухода с НУП ИС  (БАЗ2)
#define B1IC01UDU	 BUFFER[834]	//(B1IC01UDU) Координата штока ББ2 (дел.энк)
#define idB1IC01UDU	 346	//(B1IC01UDU) Координата штока ББ2 (дел.энк)
#define B1VC01RDU	 BUFFER[839]	//(B1VC01RDU) Координата ББ2, мм
#define idB1VC01RDU	 347	//(B1VC01RDU) Координата ББ2, мм
#define B1IS11LDU	 BUFFER[844]	//(B1IS11LDU) Приход на ВУ ББ2
#define idB1IS11LDU	 348	//(B1IS11LDU) Приход на ВУ ББ2
#define A2IC01UDU	 BUFFER[846]	//(A2IC01UDU) Координата штока РБ1 (дел.энк)
#define idA2IC01UDU	 349	//(A2IC01UDU) Координата штока РБ1 (дел.энк)
#define B2IC01UDU	 BUFFER[851]	//(B2IC01UDU) Координата штока РБ2 (дел.энк)
#define idB2IC01UDU	 350	//(B2IC01UDU) Координата штока РБ2 (дел.энк)
#define A3IC01UDU	 BUFFER[856]	//(A3IC01UDU) Координата штока ИС1 (дел.энк)
#define idA3IC01UDU	 351	//(A3IC01UDU) Координата штока ИС1 (дел.энк)
#define B3IC01UDU	 BUFFER[861]	//(B3IC01UDU) Координата штока ИС2 (дел.энк)
#define idB3IC01UDU	 352	//(B3IC01UDU) Координата штока ИС2 (дел.энк)
#define B3VC01RDU	 BUFFER[866]	//(B3VC01RDU) Координата ИС2, мм
#define idB3VC01RDU	 353	//(B3VC01RDU) Координата ИС2, мм
#define A8IC01UDU	 BUFFER[871]	//(A8IC01UDU) Координата ДС2 (дел.энк)
#define idA8IC01UDU	 354	//(A8IC01UDU) Координата ДС2 (дел.энк)
#define A8VC01RDU	 BUFFER[876]	//(A8VC01RDU) Координата ДС2, мм
#define idA8VC01RDU	 355	//(A8VC01RDU) Координата ДС2, мм
#define B8IC01UDU	 BUFFER[881]	//(B8IC01UDU) Координата АЗ2 (дел.энк)
#define idB8IC01UDU	 356	//(B8IC01UDU) Координата АЗ2 (дел.энк)
#define A1ZAV	 BUFFER[886]	//(A1ZAV) 
#define idA1ZAV	 357	//(A1ZAV) 
#define A3ZAV	 BUFFER[888]	//(A3ZAV) 
#define idA3ZAV	 358	//(A3ZAV) 
#define B1AB19LDU	 BUFFER[890]	//(B1AB19LDU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
#define idB1AB19LDU	 359	//(B1AB19LDU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
#define R0VN09RZ2	 BUFFER[892]	//(R0VN09RZ2) Усредненный период разгона
#define idR0VN09RZ2	 360	//(R0VN09RZ2) Усредненный период разгона
#define R0VN09RZ1	 BUFFER[897]	//(R0VN09RZ1) Усредненный период разгона
#define idR0VN09RZ1	 361	//(R0VN09RZ1) Усредненный период разгона
#define R0AB16LDU	 BUFFER[902]	//(R0AB16LDU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
#define idR0AB16LDU	 362	//(R0AB16LDU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
#define R0AB17LDU	 BUFFER[904]	//(R0AB17LDU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
#define idR0AB17LDU	 363	//(R0AB17LDU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
#define R0AB18LDU	 BUFFER[906]	//(R0AB18LDU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
#define idR0AB18LDU	 364	//(R0AB18LDU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
#define A0CT01IZ1	 BUFFER[908]	//(A0CT01IZ1) Температура АЗ1-1
#define idA0CT01IZ1	 365	//(A0CT01IZ1) Температура АЗ1-1
#define B0CT01IZ1	 BUFFER[913]	//(B0CT01IZ1) Температура АЗ2-1
#define idB0CT01IZ1	 366	//(B0CT01IZ1) Температура АЗ2-1
#define A0CT01IZ2	 BUFFER[918]	//(A0CT01IZ2) Температура АЗ1-2
#define idA0CT01IZ2	 367	//(A0CT01IZ2) Температура АЗ1-2
#define B0CT01IZ2	 BUFFER[923]	//(B0CT01IZ2) Температура АЗ2-2
#define idB0CT01IZ2	 368	//(B0CT01IZ2) Температура АЗ2-2
#define A3MC01RDU	 BUFFER[928]	//(A3MC01RDU) Заданная координата положения ИС от регулятора мм
#define idA3MC01RDU	 369	//(A3MC01RDU) Заданная координата положения ИС от регулятора мм
#define A3MC02RDU	 BUFFER[933]	//(A3MC02RDU) Температурная корректировка координаты ИМ
#define idA3MC02RDU	 370	//(A3MC02RDU) Температурная корректировка координаты ИМ
#define R0CN91LDU	 BUFFER[938]	//(R0CN91LDU) Рассчётная реактивность от регулятора
#define idR0CN91LDU	 371	//(R0CN91LDU) Рассчётная реактивность от регулятора
#define A3MC03RDU	 BUFFER[943]	//(A3MC03RDU) Координата положения ИМ 0-й реактивности
#define idA3MC03RDU	 372	//(A3MC03RDU) Координата положения ИМ 0-й реактивности
#define A3AB15LDU	 BUFFER[948]	//(A3AB15LDU) Блокировка заполнения ресивера ИС1,2: работает регулятор мощности
#define idA3AB15LDU	 373	//(A3AB15LDU) Блокировка заполнения ресивера ИС1,2: работает регулятор мощности
#define R0AB20LDU	 BUFFER[950]	//(R0AB20LDU) Блокировка изменения положения ОР: работает  регулятор мощности
#define idR0AB20LDU	 374	//(R0AB20LDU) Блокировка изменения положения ОР: работает  регулятор мощности
#define R0CN92LDU	 BUFFER[952]	//(R0CN92LDU) Рассчётный коэффициент  опережения старта ИМ
#define idR0CN92LDU	 375	//(R0CN92LDU) Рассчётный коэффициент  опережения старта ИМ
#define R0VN11RDU	 BUFFER[957]	//(R0VN11RDU) Текущая мощность РУ
#define idR0VN11RDU	 376	//(R0VN11RDU) Текущая мощность РУ
#define R0VN12RDU	 BUFFER[962]	//(R0VN12RDU) Заданная мощность РУ
#define idR0VN12RDU	 377	//(R0VN12RDU) Заданная мощность РУ
#define R0AB19LDU	 BUFFER[967]	//(R0AB19LDU) Остановка регулирования мощности: Есть блокировки  ИС1,2
#define idR0AB19LDU	 378	//(R0AB19LDU) Остановка регулирования мощности: Есть блокировки  ИС1,2
#define R0CN93LDU	 BUFFER[969]	//(R0CN93LDU) время работы на мощности более 100Вт, сек
#define idR0CN93LDU	 379	//(R0CN93LDU) время работы на мощности более 100Вт, сек
#define R4IS11LDU	 BUFFER[974]	//(R4IS11LDU) Приход на ВУ тележки
#define idR4IS11LDU	 380	//(R4IS11LDU) Приход на ВУ тележки
#define A6AB06LDU	 BUFFER[976]	//(A6AB06LDU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
#define idA6AB06LDU	 381	//(A6AB06LDU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
#define A6AB07LDU	 BUFFER[978]	//(A6AB07LDU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
#define idA6AB07LDU	 382	//(A6AB07LDU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
#define A6AB08LDU	 BUFFER[980]	//(A6AB08LDU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
#define idA6AB08LDU	 383	//(A6AB08LDU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
#define A6AB09LDU	 BUFFER[982]	//(A6AB09LDU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
#define idA6AB09LDU	 384	//(A6AB09LDU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
#define B6AB06LDU	 BUFFER[984]	//(B6AB06LDU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
#define idB6AB06LDU	 385	//(B6AB06LDU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
#define B6AB07LDU	 BUFFER[986]	//(B6AB07LDU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
#define idB6AB07LDU	 386	//(B6AB07LDU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
#define B6AB08LDU	 BUFFER[988]	//(B6AB08LDU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
#define idB6AB08LDU	 387	//(B6AB08LDU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
#define B6AB09LDU	 BUFFER[990]	//(B6AB09LDU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
#define idB6AB09LDU	 388	//(B6AB09LDU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
#define A6AB05LDU	 BUFFER[992]	//(A6AB05LDU) Блокировка открытия БЗ1 - АНИ не установлен
#define idA6AB05LDU	 389	//(A6AB05LDU) Блокировка открытия БЗ1 - АНИ не установлен
#define B8VS12LDU	 BUFFER[994]	//(B8VS12LDU) Движение АЗ2 в сторону ВУ
#define idB8VS12LDU	 390	//(B8VS12LDU) Движение АЗ2 в сторону ВУ
#define B8CV01RDU	 BUFFER[996]	//(B8CV01RDU) Измеренная скорость перемещения АЗ2
#define idB8CV01RDU	 391	//(B8CV01RDU) Измеренная скорость перемещения АЗ2
#define B8AB06LDU	 BUFFER[1001]	//(B8AB06LDU) Блокировка движения АЗ2 нет перемещения АЗ2
#define idB8AB06LDU	 392	//(B8AB06LDU) Блокировка движения АЗ2 нет перемещения АЗ2
#define B8AB07LDU	 BUFFER[1003]	//(B8AB07LDU) Блокировка движения АЗ2: превышение заданной скорости
#define idB8AB07LDU	 393	//(B8AB07LDU) Блокировка движения АЗ2: превышение заданной скорости
#define B8AB05LDU	 BUFFER[1005]	//(B8AB05LDU) Блокировка движения АЗ2: скорость перемещения менее заданной
#define idB8AB05LDU	 394	//(B8AB05LDU) Блокировка движения АЗ2: скорость перемещения менее заданной
#define B8VS22LDU	 BUFFER[1007]	//(B8VS22LDU) Движение АЗ2 в сторону НУ
#define idB8VS22LDU	 395	//(B8VS22LDU) Движение АЗ2 в сторону НУ
#define B8AZ03LDU	 BUFFER[1009]	//(B8AZ03LDU) Несанкционированное перемещение АЗ2
#define idB8AZ03LDU	 396	//(B8AZ03LDU) Несанкционированное перемещение АЗ2
#define R0MD11LP1	 BUFFER[1011]	//(R0MD11LP1) Кнопка «ПУСК»
#define idR0MD11LP1	 397	//(R0MD11LP1) Кнопка «ПУСК»
#define B8AD10LDU	 BUFFER[1013]	//(B8AD10LDU) Перемещение АЗ2 вперед
#define idB8AD10LDU	 398	//(B8AD10LDU) Перемещение АЗ2 вперед
#define B8AD20LDU	 BUFFER[1015]	//(B8AD20LDU) Перемещение АЗ2 назад
#define idB8AD20LDU	 399	//(B8AD20LDU) Перемещение АЗ2 назад
#define B8IS12LDU	 BUFFER[1017]	//(B8IS12LDU) Приход на механический ВУ АЗ2
#define idB8IS12LDU	 400	//(B8IS12LDU) Приход на механический ВУ АЗ2
#define B8AB01LDU	 BUFFER[1019]	//(B8AB01LDU) Блокировка движения АЗ2 - Превышение времени движения
#define idB8AB01LDU	 401	//(B8AB01LDU) Блокировка движения АЗ2 - Превышение времени движения
#define B5IS21LDU	 BUFFER[1021]	//(B5IS21LDU) Приход на НУ НЛ2
#define idB5IS21LDU	 402	//(B5IS21LDU) Приход на НУ НЛ2
#define A5AZ03LDU	 BUFFER[1023]	//(A5AZ03LDU) Несанкционированное перемещение НЛ1
#define idA5AZ03LDU	 403	//(A5AZ03LDU) Несанкционированное перемещение НЛ1
#define A5AB01LDU	 BUFFER[1025]	//(A5AB01LDU) Блокировка движения НЛ1 - Превышение времени движения
#define idA5AB01LDU	 404	//(A5AB01LDU) Блокировка движения НЛ1 - Превышение времени движения
#define A5AB02LDU	 BUFFER[1027]	//(A5AB02LDU) Блокировка НЛ1 - Нет перемещения
#define idA5AB02LDU	 405	//(A5AB02LDU) Блокировка НЛ1 - Нет перемещения
#define B5AZ03LDU	 BUFFER[1029]	//(B5AZ03LDU) Несанкционированное перемещение НЛ2
#define idB5AZ03LDU	 406	//(B5AZ03LDU) Несанкционированное перемещение НЛ2
#define B5AB01LDU	 BUFFER[1031]	//(B5AB01LDU) Блокировка движения НЛ2 - Превышение времени движения
#define idB5AB01LDU	 407	//(B5AB01LDU) Блокировка движения НЛ2 - Превышение времени движения
#define B5AB02LDU	 BUFFER[1033]	//(B5AB02LDU) Блокировка НЛ2 - Нет перемещения
#define idB5AB02LDU	 408	//(B5AB02LDU) Блокировка НЛ2 - Нет перемещения
#define A4IS21LDU	 BUFFER[1035]	//(A4IS21LDU) Приход на НУ НИ1
#define idA4IS21LDU	 409	//(A4IS21LDU) Приход на НУ НИ1
#define B4IS21LDU	 BUFFER[1037]	//(B4IS21LDU) Приход на НУ НИ2
#define idB4IS21LDU	 410	//(B4IS21LDU) Приход на НУ НИ2
#define B4AD10LDU	 BUFFER[1039]	//(B4AD10LDU) Открыть клапан Подъем НИ2
#define idB4AD10LDU	 411	//(B4AD10LDU) Открыть клапан Подъем НИ2
#define A4AD10LDU	 BUFFER[1041]	//(A4AD10LDU) Открыть клапан Подъем НИ1
#define idA4AD10LDU	 412	//(A4AD10LDU) Открыть клапан Подъем НИ1
#define A4AZ03LDU	 BUFFER[1043]	//(A4AZ03LDU) Несанкционированное перемещение НИ1
#define idA4AZ03LDU	 413	//(A4AZ03LDU) Несанкционированное перемещение НИ1
#define A4AB01LDU	 BUFFER[1045]	//(A4AB01LDU) Блокировка движения НИ ДС1 - Превышение времени движения
#define idA4AB01LDU	 414	//(A4AB01LDU) Блокировка движения НИ ДС1 - Превышение времени движения
#define A4AB02LDU	 BUFFER[1047]	//(A4AB02LDU) Блокировка НИ1 - Нет перемещения
#define idA4AB02LDU	 415	//(A4AB02LDU) Блокировка НИ1 - Нет перемещения
#define B4AZ03LDU	 BUFFER[1049]	//(B4AZ03LDU) Несанкционированное перемещение НИ1
#define idB4AZ03LDU	 416	//(B4AZ03LDU) Несанкционированное перемещение НИ1
#define B4AB01LDU	 BUFFER[1051]	//(B4AB01LDU) Блокировка движения НИ2 - Превышение времени движения
#define idB4AB01LDU	 417	//(B4AB01LDU) Блокировка движения НИ2 - Превышение времени движения
#define B4AB02LDU	 BUFFER[1053]	//(B4AB02LDU) Блокировка НИ2 - Нет перемещения
#define idB4AB02LDU	 418	//(B4AB02LDU) Блокировка НИ2 - Нет перемещения
#define A5AB04LDU	 BUFFER[1055]	//(A5AB04LDU) Блокировка НЛ1 -Ошибка в направлении  движения
#define idA5AB04LDU	 419	//(A5AB04LDU) Блокировка НЛ1 -Ошибка в направлении  движения
#define B5AB04LDU	 BUFFER[1057]	//(B5AB04LDU) Блокировка НЛ2 -Ошибка в направлении  движения
#define idB5AB04LDU	 420	//(B5AB04LDU) Блокировка НЛ2 -Ошибка в направлении  движения
#define A1IS12LDU	 BUFFER[1059]	//(A1IS12LDU) Магнит ББ1 зацеплен
#define idA1IS12LDU	 421	//(A1IS12LDU) Магнит ББ1 зацеплен
#define A2IS12LDU	 BUFFER[1061]	//(A2IS12LDU) Магнит РБ1 зацеплен
#define idA2IS12LDU	 422	//(A2IS12LDU) Магнит РБ1 зацеплен
#define B1IS12LDU	 BUFFER[1063]	//(B1IS12LDU) Магнит ББ2 зацеплен
#define idB1IS12LDU	 423	//(B1IS12LDU) Магнит ББ2 зацеплен
#define B2IS12LDU	 BUFFER[1065]	//(B2IS12LDU) Магнит РБ2 зацеплен
#define idB2IS12LDU	 424	//(B2IS12LDU) Магнит РБ2 зацеплен
#define A8AB09LDU	 BUFFER[1067]	//(A8AB09LDU) Блокировка  - ДС2 по мощности от любого канала
#define idA8AB09LDU	 425	//(A8AB09LDU) Блокировка  - ДС2 по мощности от любого канала
#define A8AB10LDU	 BUFFER[1069]	//(A8AB10LDU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
#define idA8AB10LDU	 426	//(A8AB10LDU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
#define A8AB11LDU	 BUFFER[1071]	//(A8AB11LDU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
#define idA8AB11LDU	 427	//(A8AB11LDU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
#define A8AB12LDU	 BUFFER[1073]	//(A8AB12LDU) Блокировка движения ДС2 - НИ не в положении ВУ
#define idA8AB12LDU	 428	//(A8AB12LDU) Блокировка движения ДС2 - НИ не в положении ВУ
#define A8AB13LDU	 BUFFER[1075]	//(A8AB13LDU) Блокировка движения ДС2 - ОРР не в исходном состоянии
#define idA8AB13LDU	 429	//(A8AB13LDU) Блокировка движения ДС2 - ОРР не в исходном состоянии
#define A8AB14LDU	 BUFFER[1077]	//(A8AB14LDU) Блокировка движения ДС2 - Самоход любого механизма
#define idA8AB14LDU	 430	//(A8AB14LDU) Блокировка движения ДС2 - Самоход любого механизма
#define A8AB02LDU	 BUFFER[1079]	//(A8AB02LDU) Блокировка движения ДС2- АНИ не установлен
#define idA8AB02LDU	 431	//(A8AB02LDU) Блокировка движения ДС2- АНИ не установлен
#define A8AB01LDU	 BUFFER[1081]	//(A8AB01LDU) Блокировка ДС2 -Превышение времени перемещения
#define idA8AB01LDU	 432	//(A8AB01LDU) Блокировка ДС2 -Превышение времени перемещения
#define A2VS11LDU	 BUFFER[1083]	//(A2VS11LDU) Движение РБ1 в сторону ВУ
#define idA2VS11LDU	 433	//(A2VS11LDU) Движение РБ1 в сторону ВУ
#define A2CV01RDU	 BUFFER[1085]	//(A2CV01RDU) Измеренная скорость перемещения РБ1
#define idA2CV01RDU	 434	//(A2CV01RDU) Измеренная скорость перемещения РБ1
#define A2AB04LDU	 BUFFER[1090]	//(A2AB04LDU) Блокировка движения РБ1 нет перемещения  РБ1
#define idA2AB04LDU	 435	//(A2AB04LDU) Блокировка движения РБ1 нет перемещения  РБ1
#define A2AB02LDU	 BUFFER[1092]	//(A2AB02LDU) Блокировка движения РБ1: превышение заданной скорости
#define idA2AB02LDU	 436	//(A2AB02LDU) Блокировка движения РБ1: превышение заданной скорости
#define A2AB01LDU	 BUFFER[1094]	//(A2AB01LDU) Блокировка движения РБ1: скорость перемещения менее заданной
#define idA2AB01LDU	 437	//(A2AB01LDU) Блокировка движения РБ1: скорость перемещения менее заданной
#define A2VS21LDU	 BUFFER[1096]	//(A2VS21LDU) Движение РБ1 в сторону НУ
#define idA2VS21LDU	 438	//(A2VS21LDU) Движение РБ1 в сторону НУ
#define A2AZ03LDU	 BUFFER[1098]	//(A2AZ03LDU) Несанкционированное перемещение РБ1
#define idA2AZ03LDU	 439	//(A2AZ03LDU) Несанкционированное перемещение РБ1
#define A2AD11LDU	 BUFFER[1100]	//(A2AD11LDU) Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	 440	//(A2AD11LDU) Сигнал на перемещение РБ1 вверх
#define A2AD21LDU	 BUFFER[1102]	//(A2AD21LDU) Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	 441	//(A2AD21LDU) Сигнал на перемещение РБ1 вниз
#define A2AD02LDU	 BUFFER[1104]	//(A2AD02LDU) 0-й бит скорости РБ1
#define idA2AD02LDU	 442	//(A2AD02LDU) 0-й бит скорости РБ1
#define A2AD03LDU	 BUFFER[1106]	//(A2AD03LDU) 1-й бит скорости РБ1
#define idA2AD03LDU	 443	//(A2AD03LDU) 1-й бит скорости РБ1
#define A2AD04LDU	 BUFFER[1108]	//(A2AD04LDU) 2-й бит скорости РБ1
#define idA2AD04LDU	 444	//(A2AD04LDU) 2-й бит скорости РБ1
#define A2AD05LDU	 BUFFER[1110]	//(A2AD05LDU) паритет команды на РБ1
#define idA2AD05LDU	 445	//(A2AD05LDU) паритет команды на РБ1
#define A2AB07LDU	 BUFFER[1112]	//(A2AB07LDU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
#define idA2AB07LDU	 446	//(A2AB07LDU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
#define B8AB04LDU	 BUFFER[1114]	//(B8AB04LDU) Блокировка АЗ2 -Ошибка в направлении  движения
#define idB8AB04LDU	 447	//(B8AB04LDU) Блокировка АЗ2 -Ошибка в направлении  движения
#define B8AB08LDU	 BUFFER[1116]	//(B8AB08LDU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define idB8AB08LDU	 448	//(B8AB08LDU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define B8AB09LDU	 BUFFER[1118]	//(B8AB09LDU) Блокировка  - АЗ2 по мощности от любого канала
#define idB8AB09LDU	 449	//(B8AB09LDU) Блокировка  - АЗ2 по мощности от любого канала
#define B8AB10LDU	 BUFFER[1120]	//(B8AB10LDU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
#define idB8AB10LDU	 450	//(B8AB10LDU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
#define B8AB11LDU	 BUFFER[1122]	//(B8AB11LDU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
#define idB8AB11LDU	 451	//(B8AB11LDU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
#define B8AB12LDU	 BUFFER[1124]	//(B8AB12LDU) Блокировка движения АЗ2 - НИ не в положении ВУ
#define idB8AB12LDU	 452	//(B8AB12LDU) Блокировка движения АЗ2 - НИ не в положении ВУ
#define B8AB13LDU	 BUFFER[1126]	//(B8AB13LDU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
#define idB8AB13LDU	 453	//(B8AB13LDU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
#define B8AB14LDU	 BUFFER[1128]	//(B8AB14LDU) Блокировка движения АЗ2 - Самоход любого механизма
#define idB8AB14LDU	 454	//(B8AB14LDU) Блокировка движения АЗ2 - Самоход любого механизма
#define B8AB02LDU	 BUFFER[1130]	//(B8AB02LDU) Блокировка движения АЗ2- АНИ не установлен
#define idB8AB02LDU	 455	//(B8AB02LDU) Блокировка движения АЗ2- АНИ не установлен
#define A8VS12LDU	 BUFFER[1132]	//(A8VS12LDU) Движение ДС2 в сторону ВУ
#define idA8VS12LDU	 456	//(A8VS12LDU) Движение ДС2 в сторону ВУ
#define A8CV01RDU	 BUFFER[1134]	//(A8CV01RDU) Измеренная скорость перемещения ДС2
#define idA8CV01RDU	 457	//(A8CV01RDU) Измеренная скорость перемещения ДС2
#define A8AB06LDU	 BUFFER[1139]	//(A8AB06LDU) Блокировка движения ДС2 нет перемещения ДС2
#define idA8AB06LDU	 458	//(A8AB06LDU) Блокировка движения ДС2 нет перемещения ДС2
#define A8AB07LDU	 BUFFER[1141]	//(A8AB07LDU) Блокировка движения ДС2: превышение заданной скорости
#define idA8AB07LDU	 459	//(A8AB07LDU) Блокировка движения ДС2: превышение заданной скорости
#define A8AB05LDU	 BUFFER[1143]	//(A8AB05LDU) Блокировка движения ДС2: скорость перемещения менее заданной
#define idA8AB05LDU	 460	//(A8AB05LDU) Блокировка движения ДС2: скорость перемещения менее заданной
#define A8VS22LDU	 BUFFER[1145]	//(A8VS22LDU) Движение ДС2 в сторону НУ
#define idA8VS22LDU	 461	//(A8VS22LDU) Движение ДС2 в сторону НУ
#define A8AZ03LDU	 BUFFER[1147]	//(A8AZ03LDU) Несанкционированное перемещение ДС2
#define idA8AZ03LDU	 462	//(A8AZ03LDU) Несанкционированное перемещение ДС2
#define A8AD10LDU	 BUFFER[1149]	//(A8AD10LDU) Перемещение ДС2 вперед
#define idA8AD10LDU	 463	//(A8AD10LDU) Перемещение ДС2 вперед
#define A8AD20LDU	 BUFFER[1151]	//(A8AD20LDU) Перемещение ДС2 назад
#define idA8AD20LDU	 464	//(A8AD20LDU) Перемещение ДС2 назад
#define B8IS22LDU	 BUFFER[1153]	//(B8IS22LDU) Приход на механический НУ АЗ2
#define idB8IS22LDU	 465	//(B8IS22LDU) Приход на механический НУ АЗ2
#define A8IS12LDU	 BUFFER[1155]	//(A8IS12LDU) Приход на механический ВУ ДС2
#define idA8IS12LDU	 466	//(A8IS12LDU) Приход на механический ВУ ДС2
#define A8AB04LDU	 BUFFER[1157]	//(A8AB04LDU) Блокировка ДС2 -Ошибка в направлении  движения
#define idA8AB04LDU	 467	//(A8AB04LDU) Блокировка ДС2 -Ошибка в направлении  движения
#define A8IS22LDU	 BUFFER[1159]	//(A8IS22LDU) Приход на механический НУ ДС2
#define idA8IS22LDU	 468	//(A8IS22LDU) Приход на механический НУ ДС2
#define A8AB08LDU	 BUFFER[1161]	//(A8AB08LDU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define idA8AB08LDU	 469	//(A8AB08LDU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define B6IS21LDU	 BUFFER[1163]	//(B6IS21LDU) Приход на НУ БЗ2
#define idB6IS21LDU	 470	//(B6IS21LDU) Приход на НУ БЗ2
#define A6VS22LDU	 BUFFER[1165]	//(A6VS22LDU) Движение створок БЗ1  к «ЗАКРЫТА»
#define idA6VS22LDU	 471	//(A6VS22LDU) Движение створок БЗ1  к «ЗАКРЫТА»
#define A6VS12LDU	 BUFFER[1167]	//(A6VS12LDU) Движение створок БЗ1  к  «ОТКРЫТА»
#define idA6VS12LDU	 472	//(A6VS12LDU) Движение створок БЗ1  к  «ОТКРЫТА»
#define B6VS22LDU	 BUFFER[1169]	//(B6VS22LDU) Движение створок БЗ2  к «ЗАКРЫТА»
#define idB6VS22LDU	 473	//(B6VS22LDU) Движение створок БЗ2  к «ЗАКРЫТА»
#define B6VS12LDU	 BUFFER[1171]	//(B6VS12LDU) Движение створок БЗ2  к  «ОТКРЫТА»
#define idB6VS12LDU	 474	//(B6VS12LDU) Движение створок БЗ2  к  «ОТКРЫТА»
#define A6AD10LDU	 BUFFER[1173]	//(A6AD10LDU) Открыть БЗ1
#define idA6AD10LDU	 475	//(A6AD10LDU) Открыть БЗ1
#define A6AD20LDU	 BUFFER[1175]	//(A6AD20LDU) Закрыть БЗ1
#define idA6AD20LDU	 476	//(A6AD20LDU) Закрыть БЗ1
#define B6AD10LDU	 BUFFER[1177]	//(B6AD10LDU) Открыть БЗ2
#define idB6AD10LDU	 477	//(B6AD10LDU) Открыть БЗ2
#define B6AD20LDU	 BUFFER[1179]	//(B6AD20LDU) Закрыть БЗ2
#define idB6AD20LDU	 478	//(B6AD20LDU) Закрыть БЗ2
#define A6AZ03LDU	 BUFFER[1181]	//(A6AZ03LDU) Несанкционированное перемещение БЗ1
#define idA6AZ03LDU	 479	//(A6AZ03LDU) Несанкционированное перемещение БЗ1
#define A6AB01LDU	 BUFFER[1183]	//(A6AB01LDU) Блокировка движения БЗ1 - Превышение времени движения
#define idA6AB01LDU	 480	//(A6AB01LDU) Блокировка движения БЗ1 - Превышение времени движения
#define A6AB02LDU	 BUFFER[1185]	//(A6AB02LDU) Блокировка БЗ1 - Нет перемещения
#define idA6AB02LDU	 481	//(A6AB02LDU) Блокировка БЗ1 - Нет перемещения
#define B6AZ03LDU	 BUFFER[1187]	//(B6AZ03LDU) Несанкционированное перемещение БЗ2
#define idB6AZ03LDU	 482	//(B6AZ03LDU) Несанкционированное перемещение БЗ2
#define B6AB01LDU	 BUFFER[1189]	//(B6AB01LDU) Блокировка движения БЗ2 - Превышение времени движения
#define idB6AB01LDU	 483	//(B6AB01LDU) Блокировка движения БЗ2 - Превышение времени движения
#define B6AB02LDU	 BUFFER[1191]	//(B6AB02LDU) Блокировка БЗ2 - Нет перемещения
#define idB6AB02LDU	 484	//(B6AB02LDU) Блокировка БЗ2 - Нет перемещения
#define A6AB04LDU	 BUFFER[1193]	//(A6AB04LDU) Блокировка БЗ1 -Ошибка в направлении  движения
#define idA6AB04LDU	 485	//(A6AB04LDU) Блокировка БЗ1 -Ошибка в направлении  движения
#define B6AB04LDU	 BUFFER[1195]	//(B6AB04LDU) Блокировка БЗ2 -Ошибка в направлении  движения
#define idB6AB04LDU	 486	//(B6AB04LDU) Блокировка БЗ2 -Ошибка в направлении  движения
#define R4AB01LDU	 BUFFER[1197]	//(R4AB01LDU) Блокировка тележки - АНИ не установлен
#define idR4AB01LDU	 487	//(R4AB01LDU) Блокировка тележки - АНИ не установлен
#define R8IS11LDU	 BUFFER[1199]	//(R8IS11LDU) Аварийный НИ установлен
#define idR8IS11LDU	 488	//(R8IS11LDU) Аварийный НИ установлен
#define R6IS21LDU	 BUFFER[1201]	//(R6IS21LDU) Кран-балка в нерабочем положении
#define idR6IS21LDU	 489	//(R6IS21LDU) Кран-балка в нерабочем положении
#define A0VN71LZ2	 BUFFER[1203]	//(A0VN71LZ2) АЗ по АС мощности для АЗ1
#define idA0VN71LZ2	 490	//(A0VN71LZ2) АЗ по АС мощности для АЗ1
#define A0VN71LZ1	 BUFFER[1205]	//(A0VN71LZ1) АЗ по АС мощности для АЗ1
#define idA0VN71LZ1	 491	//(A0VN71LZ1) АЗ по АС мощности для АЗ1
#define R0MW15IP1	 BUFFER[1207]	//(R0MW15IP1) Переключатель «МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ»
#define idR0MW15IP1	 492	//(R0MW15IP1) Переключатель «МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ»
#define R0MW14IP1	 BUFFER[1210]	//(R0MW14IP1) Переключатель «ПРОГРАММЫ»
#define idR0MW14IP1	 493	//(R0MW14IP1) Переключатель «ПРОГРАММЫ»
#define R0MW12IP1	 BUFFER[1213]	//(R0MW12IP1) Переключатель «РЕЖИМ РАБОТЫ»
#define idR0MW12IP1	 494	//(R0MW12IP1) Переключатель «РЕЖИМ РАБОТЫ»
#define R0MW13IP1	 BUFFER[1216]	//(R0MW13IP1) Переключатель «ВЫБОР ЗОН»
#define idR0MW13IP1	 495	//(R0MW13IP1) Переключатель «ВЫБОР ЗОН»
#define R0MW16IP1	 BUFFER[1219]	//(R0MW16IP1) Переключатель «ВИД ПРОВЕРКИ»
#define idR0MW16IP1	 496	//(R0MW16IP1) Переключатель «ВИД ПРОВЕРКИ»
#define R0MW11IP1	 BUFFER[1222]	//(R0MW11IP1) Переключатель «ВЫСТРЕЛ»
#define idR0MW11IP1	 497	//(R0MW11IP1) Переключатель «ВЫСТРЕЛ»
#define R0MW11IP2	 BUFFER[1225]	//(R0MW11IP2) Переключатель «ПРОВЕРКА СХЕМ СБРОСА»
#define idR0MW11IP2	 498	//(R0MW11IP2) Переключатель «ПРОВЕРКА СХЕМ СБРОСА»
#define R0MW13LP2	 BUFFER[1228]	//(R0MW13LP2) Переключатель «СЕТЬ»
#define idR0MW13LP2	 499	//(R0MW13LP2) Переключатель «СЕТЬ»
#define R0MD32LP1	 BUFFER[1230]	//(R0MD32LP1) Кнопка «СПУСК»
#define idR0MD32LP1	 500	//(R0MD32LP1) Кнопка «СПУСК»
#define R0MD31LP1	 BUFFER[1232]	//(R0MD31LP1) Кнопка «СТОП»
#define idR0MD31LP1	 501	//(R0MD31LP1) Кнопка «СТОП»
#define A1IS21LDU	 BUFFER[1234]	//(A1IS21LDU) Приход на НУ ББ1
#define idA1IS21LDU	 502	//(A1IS21LDU) Приход на НУ ББ1
#define A2IS21LDU	 BUFFER[1236]	//(A2IS21LDU) Приход на НУ РБ1-СС
#define idA2IS21LDU	 503	//(A2IS21LDU) Приход на НУ РБ1-СС
#define A3IS21LDU	 BUFFER[1238]	//(A3IS21LDU) Приход на НУ ИС1
#define idA3IS21LDU	 504	//(A3IS21LDU) Приход на НУ ИС1
#define B1IS21LDU	 BUFFER[1240]	//(B1IS21LDU) Приход на НУ ББ2
#define idB1IS21LDU	 505	//(B1IS21LDU) Приход на НУ ББ2
#define B2IS21LDU	 BUFFER[1242]	//(B2IS21LDU) Приход на НУ РБ2-СС
#define idB2IS21LDU	 506	//(B2IS21LDU) Приход на НУ РБ2-СС
#define B3IS21LDU	 BUFFER[1244]	//(B3IS21LDU) Приход на НУ ИС2
#define idB3IS21LDU	 507	//(B3IS21LDU) Приход на НУ ИС2
#define R0ES01LDU	 BUFFER[1246]	//(R0ES01LDU) ОРР не в исходном состоянии
#define idR0ES01LDU	 508	//(R0ES01LDU) ОРР не в исходном состоянии
#define R4MD11LP2	 BUFFER[1248]	//(R4MD11LP2) Кнопка «ВПЕРЁД»  (тележки)
#define idR4MD11LP2	 509	//(R4MD11LP2) Кнопка «ВПЕРЁД»  (тележки)
#define R4MD31LP2	 BUFFER[1250]	//(R4MD31LP2) Кнопка «СТОП»  (тележки)
#define idR4MD31LP2	 510	//(R4MD31LP2) Кнопка «СТОП»  (тележки)
#define R4MD21LP2	 BUFFER[1252]	//(R4MD21LP2) Кнопка «НАЗАД»  (тележки)
#define idR4MD21LP2	 511	//(R4MD21LP2) Кнопка «НАЗАД»  (тележки)
#define A6IS11LDU	 BUFFER[1254]	//(A6IS11LDU) Приход на ВУ БЗ1
#define idA6IS11LDU	 512	//(A6IS11LDU) Приход на ВУ БЗ1
#define A6IS21LDU	 BUFFER[1256]	//(A6IS21LDU) Приход на НУ БЗ1
#define idA6IS21LDU	 513	//(A6IS21LDU) Приход на НУ БЗ1
#define B6IS11LDU	 BUFFER[1258]	//(B6IS11LDU) Приход на ВУ БЗ2
#define idB6IS11LDU	 514	//(B6IS11LDU) Приход на ВУ БЗ2
#define R4AB12LDU	 BUFFER[1260]	//(R4AB12LDU) Блокировка тележки - НИ не в положении ВУ
#define idR4AB12LDU	 515	//(R4AB12LDU) Блокировка тележки - НИ не в положении ВУ
#define A4IS11LDU	 BUFFER[1262]	//(A4IS11LDU) Приход на ВУ НИ1
#define idA4IS11LDU	 516	//(A4IS11LDU) Приход на ВУ НИ1
#define B4IS11LDU	 BUFFER[1264]	//(B4IS11LDU) Приход на ВУ НИ2
#define idB4IS11LDU	 517	//(B4IS11LDU) Приход на ВУ НИ2
#define R4AB13LDU	 BUFFER[1266]	//(R4AB13LDU) Блокировка тележки - НЛ не в положении ВУ
#define idR4AB13LDU	 518	//(R4AB13LDU) Блокировка тележки - НЛ не в положении ВУ
#define R4AB14LDU	 BUFFER[1268]	//(R4AB14LDU) Блокировка тележки - Кран - балка не в безопасном положении
#define idR4AB14LDU	 519	//(R4AB14LDU) Блокировка тележки - Кран - балка не в безопасном положении
#define R4AB15LDU	 BUFFER[1270]	//(R4AB15LDU) Блокировка тележки - ворота в пом. 0041 не в положении Открыто
#define idR4AB15LDU	 520	//(R4AB15LDU) Блокировка тележки - ворота в пом. 0041 не в положении Открыто
#define R5IS11LDU	 BUFFER[1272]	//(R5IS11LDU) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	 521	//(R5IS11LDU) Приход на ВУ ворот отстойной зоны
#define R4AB16LDU	 BUFFER[1274]	//(R4AB16LDU) Блокировка тележки - Гомогенные двери не в положении Закрыты
#define idR4AB16LDU	 522	//(R4AB16LDU) Блокировка тележки - Гомогенные двери не в положении Закрыты
#define R4AB17LDU	 BUFFER[1276]	//(R4AB17LDU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define idR4AB17LDU	 523	//(R4AB17LDU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define R4AB18LDU	 BUFFER[1278]	//(R4AB18LDU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define idR4AB18LDU	 524	//(R4AB18LDU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define R4AD10LDU	 BUFFER[1280]	//(R4AD10LDU) Перемещение тележки вперед
#define idR4AD10LDU	 525	//(R4AD10LDU) Перемещение тележки вперед
#define R4AD20LDU	 BUFFER[1282]	//(R4AD20LDU) Перемещение тележки назад
#define idR4AD20LDU	 526	//(R4AD20LDU) Перемещение тележки назад
#define A5VS22LDU	 BUFFER[1284]	//(A5VS22LDU) Движение НЛ1 в сторону НУ
#define idA5VS22LDU	 527	//(A5VS22LDU) Движение НЛ1 в сторону НУ
#define A5VS12LDU	 BUFFER[1286]	//(A5VS12LDU) Движение НЛ1 в сторону ВУ
#define idA5VS12LDU	 528	//(A5VS12LDU) Движение НЛ1 в сторону ВУ
#define B5VS22LDU	 BUFFER[1288]	//(B5VS22LDU) Движение НЛ2 в сторону НУ
#define idB5VS22LDU	 529	//(B5VS22LDU) Движение НЛ2 в сторону НУ
#define B5VS12LDU	 BUFFER[1290]	//(B5VS12LDU) Движение НЛ2 в сторону ВУ
#define idB5VS12LDU	 530	//(B5VS12LDU) Движение НЛ2 в сторону ВУ
#define B5AD10LDU	 BUFFER[1292]	//(B5AD10LDU) Поднять НЛ2
#define idB5AD10LDU	 531	//(B5AD10LDU) Поднять НЛ2
#define B5AD20LDU	 BUFFER[1294]	//(B5AD20LDU) Опустить НЛ2
#define idB5AD20LDU	 532	//(B5AD20LDU) Опустить НЛ2
#define A5AD10LDU	 BUFFER[1296]	//(A5AD10LDU) Поднять НЛ1
#define idA5AD10LDU	 533	//(A5AD10LDU) Поднять НЛ1
#define A5AD20LDU	 BUFFER[1298]	//(A5AD20LDU) Опустить НЛ1
#define idA5AD20LDU	 534	//(A5AD20LDU) Опустить НЛ1
#define A5IS11LDU	 BUFFER[1300]	//(A5IS11LDU) Приход на ВУ НЛ1
#define idA5IS11LDU	 535	//(A5IS11LDU) Приход на ВУ НЛ1
#define A5IS21LDU	 BUFFER[1302]	//(A5IS21LDU) Приход на НУ НЛ1
#define idA5IS21LDU	 536	//(A5IS21LDU) Приход на НУ НЛ1
#define B5IS11LDU	 BUFFER[1304]	//(B5IS11LDU) Приход на ВУ НЛ2
#define idB5IS11LDU	 537	//(B5IS11LDU) Приход на ВУ НЛ2
#define R0NE01LDU	 BUFFER[1306]	//(R0NE01LDU) Потеря связи с БАЗ1
#define idR0NE01LDU	 538	//(R0NE01LDU) Потеря связи с БАЗ1
#define R0NE02LDU	 BUFFER[1308]	//(R0NE02LDU) Потеря связи с БАЗ2
#define idR0NE02LDU	 539	//(R0NE02LDU) Потеря связи с БАЗ2
#define R4AB02LDU	 BUFFER[1310]	//(R4AB02LDU) Блокировка тележки - Потеря связи с БАЗ, ОПУ
#define idR4AB02LDU	 540	//(R4AB02LDU) Блокировка тележки - Потеря связи с БАЗ, ОПУ
#define R0NE08LDU	 BUFFER[1312]	//(R0NE08LDU) Потеря связи с ОПУ
#define idR0NE08LDU	 541	//(R0NE08LDU) Потеря связи с ОПУ
#define R4IS21LDU	 BUFFER[1314]	//(R4IS21LDU) Приход на НУ тележки
#define idR4IS21LDU	 542	//(R4IS21LDU) Приход на НУ тележки
#define R4IS22LDU	 BUFFER[1316]	//(R4IS22LDU) Приход на механический НУ тележки
#define idR4IS22LDU	 543	//(R4IS22LDU) Приход на механический НУ тележки
#define R4IS12LDU	 BUFFER[1318]	//(R4IS12LDU) Приход на механический ВУ тележки
#define idR4IS12LDU	 544	//(R4IS12LDU) Приход на механический ВУ тележки
#define R4VS22LDU	 BUFFER[1320]	//(R4VS22LDU) Движение реактора к «У ЗАЩИТЫ»
#define idR4VS22LDU	 545	//(R4VS22LDU) Движение реактора к «У ЗАЩИТЫ»
#define R4VS12LDU	 BUFFER[1322]	//(R4VS12LDU) Движение реактора  к «У ОБРАЗЦОВ»
#define idR4VS12LDU	 546	//(R4VS12LDU) Движение реактора  к «У ОБРАЗЦОВ»
#define R4AZ03LDU	 BUFFER[1324]	//(R4AZ03LDU) Несанкционированное перемещение тележки
#define idR4AZ03LDU	 547	//(R4AZ03LDU) Несанкционированное перемещение тележки
#define R4AB03LDU	 BUFFER[1326]	//(R4AB03LDU) Блокировка тележки - Самоход любого механизма
#define idR4AB03LDU	 548	//(R4AB03LDU) Блокировка тележки - Самоход любого механизма
#define R1IS21LDU	 BUFFER[1328]	//(R1IS21LDU) Приход на НУ МДЗ1
#define idR1IS21LDU	 549	//(R1IS21LDU) Приход на НУ МДЗ1
#define R2IS21LDU	 BUFFER[1330]	//(R2IS21LDU) Приход на НУ МДЗ2
#define idR2IS21LDU	 550	//(R2IS21LDU) Приход на НУ МДЗ2
#define R4AB04LDU	 BUFFER[1332]	//(R4AB04LDU) Блокировка тележки - Превышение времени движения
#define idR4AB04LDU	 551	//(R4AB04LDU) Блокировка тележки - Превышение времени движения
#define R4AB05LDU	 BUFFER[1334]	//(R4AB05LDU) Блокировка тележки - Нет перемещения тележки
#define idR4AB05LDU	 552	//(R4AB05LDU) Блокировка тележки - Нет перемещения тележки
#define R4AB06LDU	 BUFFER[1336]	//(R4AB06LDU) Блокировка тележки - Ошибка в  направлении перемещения
#define idR4AB06LDU	 553	//(R4AB06LDU) Блокировка тележки - Ошибка в  направлении перемещения
#define R4AB07LDU	 BUFFER[1338]	//(R4AB07LDU) Блокировка тележки - ОРР не в исходном состоянии
#define idR4AB07LDU	 554	//(R4AB07LDU) Блокировка тележки - ОРР не в исходном состоянии
#define R4AB08LDU	 BUFFER[1340]	//(R4AB08LDU) Блокировка тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define idR4AB08LDU	 555	//(R4AB08LDU) Блокировка тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define R4AB09LDU	 BUFFER[1342]	//(R4AB09LDU) Блокировка тележки - АЗ по мощности от любого канала
#define idR4AB09LDU	 556	//(R4AB09LDU) Блокировка тележки - АЗ по мощности от любого канала
#define B0VN71LZ1	 BUFFER[1344]	//(B0VN71LZ1) АЗ по АС мощности для АЗ2
#define idB0VN71LZ1	 557	//(B0VN71LZ1) АЗ по АС мощности для АЗ2
#define B0VN71LZ2	 BUFFER[1346]	//(B0VN71LZ2) АЗ по АС мощности для АЗ2
#define idB0VN71LZ2	 558	//(B0VN71LZ2) АЗ по АС мощности для АЗ2
#define R4AB10LDU	 BUFFER[1348]	//(R4AB10LDU) Блокировка тележки - не открыта биологическая защита
#define idR4AB10LDU	 559	//(R4AB10LDU) Блокировка тележки - не открыта биологическая защита
#define R4AB11LDU	 BUFFER[1350]	//(R4AB11LDU) Блокировка тележки - МДЗ1,2 не находятся на НУ
#define idR4AB11LDU	 560	//(R4AB11LDU) Блокировка тележки - МДЗ1,2 не находятся на НУ
#define A3AB01LDU	 BUFFER[1352]	//(A3AB01LDU) Блокировка движения ИС1: скорость перемещения менее заданной
#define idA3AB01LDU	 561	//(A3AB01LDU) Блокировка движения ИС1: скорость перемещения менее заданной
#define A3VS22LDU	 BUFFER[1354]	//(A3VS22LDU) Движение ИС1 в сторону НУ
#define idA3VS22LDU	 562	//(A3VS22LDU) Движение ИС1 в сторону НУ
#define A3AZ03LDU	 BUFFER[1356]	//(A3AZ03LDU) Несанкционированное перемещение ИС1
#define idA3AZ03LDU	 563	//(A3AZ03LDU) Несанкционированное перемещение ИС1
#define A3AD11LDU	 BUFFER[1358]	//(A3AD11LDU) Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	 564	//(A3AD11LDU) Сигнал на перемещение ИС1 вверх
#define A3AD21LDU	 BUFFER[1360]	//(A3AD21LDU) Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	 565	//(A3AD21LDU) Сигнал на перемещение ИС1 вниз
#define A3AD02LDU	 BUFFER[1362]	//(A3AD02LDU) 0-й бит скорости ИС1
#define idA3AD02LDU	 566	//(A3AD02LDU) 0-й бит скорости ИС1
#define A3AD03LDU	 BUFFER[1364]	//(A3AD03LDU) 1-й бит скорости ИС1
#define idA3AD03LDU	 567	//(A3AD03LDU) 1-й бит скорости ИС1
#define A3AD04LDU	 BUFFER[1366]	//(A3AD04LDU) 2-й бит скорости ИС1
#define idA3AD04LDU	 568	//(A3AD04LDU) 2-й бит скорости ИС1
#define A3AD05LDU	 BUFFER[1368]	//(A3AD05LDU) паритет команды на ИС1
#define idA3AD05LDU	 569	//(A3AD05LDU) паритет команды на ИС1
#define A3AD01LDU	 BUFFER[1370]	//(A3AD01LDU) Разрешение движения ИС1
#define idA3AD01LDU	 570	//(A3AD01LDU) Разрешение движения ИС1
#define A3CV02RDU	 BUFFER[1372]	//(A3CV02RDU) Заданная скорость перемещения ИС1
#define idA3CV02RDU	 571	//(A3CV02RDU) Заданная скорость перемещения ИС1
#define A3AB07LDU	 BUFFER[1377]	//(A3AB07LDU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
#define idA3AB07LDU	 572	//(A3AB07LDU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
#define A3AB08LDU	 BUFFER[1379]	//(A3AB08LDU) Блокировка подъёма ИС1 - реактор не на рабочем месте
#define idA3AB08LDU	 573	//(A3AB08LDU) Блокировка подъёма ИС1 - реактор не на рабочем месте
#define A3AB05LDU	 BUFFER[1381]	//(A3AB05LDU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
#define idA3AB05LDU	 574	//(A3AB05LDU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
#define A3AB06LDU	 BUFFER[1383]	//(A3AB06LDU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
#define idA3AB06LDU	 575	//(A3AB06LDU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
#define A3AB09LDU	 BUFFER[1385]	//(A3AB09LDU) Блокировка подъёма ИС1- АНИ не установлен
#define idA3AB09LDU	 576	//(A3AB09LDU) Блокировка подъёма ИС1- АНИ не установлен
#define A3AB10LDU	 BUFFER[1387]	//(A3AB10LDU) Блокировка подъёма ИС1- есть сигнал общего сброса
#define idA3AB10LDU	 577	//(A3AB10LDU) Блокировка подъёма ИС1- есть сигнал общего сброса
#define A3AB11LDU	 BUFFER[1389]	//(A3AB11LDU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
#define idA3AB11LDU	 578	//(A3AB11LDU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
#define A3AB12LDU	 BUFFER[1391]	//(A3AB12LDU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA3AB12LDU	 579	//(A3AB12LDU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A3AB13LDU	 BUFFER[1393]	//(A3AB13LDU) Блокировка подъёма ИС1- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define idA3AB13LDU	 580	//(A3AB13LDU) Блокировка подъёма ИС1- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define A3AB14LDU	 BUFFER[1395]	//(A3AB14LDU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
#define idA3AB14LDU	 581	//(A3AB14LDU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
#define A3AB16LDU	 BUFFER[1397]	//(A3AB16LDU) Блокировка перемещения ИС1: выполняется программа 200 с
#define idA3AB16LDU	 582	//(A3AB16LDU) Блокировка перемещения ИС1: выполняется программа 200 с
#define B1AD02LDU	 BUFFER[1399]	//(B1AD02LDU) 0-й бит скорости ББ2
#define idB1AD02LDU	 583	//(B1AD02LDU) 0-й бит скорости ББ2
#define B1AD03LDU	 BUFFER[1401]	//(B1AD03LDU) 1-й бит скорости ББ2
#define idB1AD03LDU	 584	//(B1AD03LDU) 1-й бит скорости ББ2
#define B1AD04LDU	 BUFFER[1403]	//(B1AD04LDU) 2-й бит скорости ББ2
#define idB1AD04LDU	 585	//(B1AD04LDU) 2-й бит скорости ББ2
#define B1AD05LDU	 BUFFER[1405]	//(B1AD05LDU) паритет команды на ББ2
#define idB1AD05LDU	 586	//(B1AD05LDU) паритет команды на ББ2
#define B1AD01LDU	 BUFFER[1407]	//(B1AD01LDU) Разрешение движения ББ2
#define idB1AD01LDU	 587	//(B1AD01LDU) Разрешение движения ББ2
#define B1CV02RDU	 BUFFER[1409]	//(B1CV02RDU) Заданная скорость перемещения ББ2
#define idB1CV02RDU	 588	//(B1CV02RDU) Заданная скорость перемещения ББ2
#define B1AB07LDU	 BUFFER[1414]	//(B1AB07LDU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
#define idB1AB07LDU	 589	//(B1AB07LDU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
#define B1AB08LDU	 BUFFER[1416]	//(B1AB08LDU) Блокировка подъёма ББ2 - реактор не на рабочем месте
#define idB1AB08LDU	 590	//(B1AB08LDU) Блокировка подъёма ББ2 - реактор не на рабочем месте
#define B1AB05LDU	 BUFFER[1418]	//(B1AB05LDU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
#define idB1AB05LDU	 591	//(B1AB05LDU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
#define B1AB06LDU	 BUFFER[1420]	//(B1AB06LDU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
#define idB1AB06LDU	 592	//(B1AB06LDU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
#define B1AB09LDU	 BUFFER[1422]	//(B1AB09LDU) Блокировка подъёма ББ2- АНИ не установлен
#define idB1AB09LDU	 593	//(B1AB09LDU) Блокировка подъёма ББ2- АНИ не установлен
#define B1AB10LDU	 BUFFER[1424]	//(B1AB10LDU) Блокировка подъёма ББ2- есть сигнал общего сброса
#define idB1AB10LDU	 594	//(B1AB10LDU) Блокировка подъёма ББ2- есть сигнал общего сброса
#define B1AB11LDU	 BUFFER[1426]	//(B1AB11LDU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
#define idB1AB11LDU	 595	//(B1AB11LDU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
#define B1AB12LDU	 BUFFER[1428]	//(B1AB12LDU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idB1AB12LDU	 596	//(B1AB12LDU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define B1AB13LDU	 BUFFER[1430]	//(B1AB13LDU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже значения заданного предупредительной уставкой
#define idB1AB13LDU	 597	//(B1AB13LDU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже значения заданного предупредительной уставкой
#define B1AB14LDU	 BUFFER[1432]	//(B1AB14LDU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
#define idB1AB14LDU	 598	//(B1AB14LDU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
#define B1AB16LDU	 BUFFER[1434]	//(B1AB16LDU) Блокировка перемещения ББ2: выполняется программа 200 с
#define idB1AB16LDU	 599	//(B1AB16LDU) Блокировка перемещения ББ2: выполняется программа 200 с
#define B1AB17LDU	 BUFFER[1436]	//(B1AB17LDU) Блокировка перемещения ББ2: выполняется программа 20 мин
#define idB1AB17LDU	 600	//(B1AB17LDU) Блокировка перемещения ББ2: выполняется программа 20 мин
#define B1AB18LDU	 BUFFER[1438]	//(B1AB18LDU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
#define idB1AB18LDU	 601	//(B1AB18LDU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
#define A3VS12LDU	 BUFFER[1440]	//(A3VS12LDU) Движение ИС1 в сторону ВУ
#define idA3VS12LDU	 602	//(A3VS12LDU) Движение ИС1 в сторону ВУ
#define A3CV01RDU	 BUFFER[1442]	//(A3CV01RDU) Измеренная скорость перемещения ИС1
#define idA3CV01RDU	 603	//(A3CV01RDU) Измеренная скорость перемещения ИС1
#define A3AB04LDU	 BUFFER[1447]	//(A3AB04LDU) Блокировка движения ИС1 нет перемещения  ИС1
#define idA3AB04LDU	 604	//(A3AB04LDU) Блокировка движения ИС1 нет перемещения  ИС1
#define A3AB02LDU	 BUFFER[1449]	//(A3AB02LDU) Блокировка движения ИС1: превышение заданной скорости
#define idA3AB02LDU	 605	//(A3AB02LDU) Блокировка движения ИС1: превышение заданной скорости
#define B3AB09LDU	 BUFFER[1451]	//(B3AB09LDU) Блокировка подъёма ИС2- АНИ не установлен
#define idB3AB09LDU	 606	//(B3AB09LDU) Блокировка подъёма ИС2- АНИ не установлен
#define B3AB10LDU	 BUFFER[1453]	//(B3AB10LDU) Блокировка подъёма ИС2- есть сигнал общего сброса
#define idB3AB10LDU	 607	//(B3AB10LDU) Блокировка подъёма ИС2- есть сигнал общего сброса
#define B3AB11LDU	 BUFFER[1455]	//(B3AB11LDU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
#define idB3AB11LDU	 608	//(B3AB11LDU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
#define B3AB12LDU	 BUFFER[1457]	//(B3AB12LDU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define idB3AB12LDU	 609	//(B3AB12LDU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define B3AB13LDU	 BUFFER[1459]	//(B3AB13LDU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define idB3AB13LDU	 610	//(B3AB13LDU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define B3AB14LDU	 BUFFER[1461]	//(B3AB14LDU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
#define idB3AB14LDU	 611	//(B3AB14LDU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
#define B3AB16LDU	 BUFFER[1463]	//(B3AB16LDU) Блокировка перемещения ИС2: выполняется программа 200 с
#define idB3AB16LDU	 612	//(B3AB16LDU) Блокировка перемещения ИС2: выполняется программа 200 с
#define B3AB17LDU	 BUFFER[1465]	//(B3AB17LDU) Блокировка перемещения ИС2: выполняется программа 20 мин
#define idB3AB17LDU	 613	//(B3AB17LDU) Блокировка перемещения ИС2: выполняется программа 20 мин
#define B3AB18LDU	 BUFFER[1467]	//(B3AB18LDU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
#define idB3AB18LDU	 614	//(B3AB18LDU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
#define B3AB19LDU	 BUFFER[1469]	//(B3AB19LDU) Блокировка пневматического подъема ИС2: режим статический
#define idB3AB19LDU	 615	//(B3AB19LDU) Блокировка пневматического подъема ИС2: режим статический
#define B3AB20LDU	 BUFFER[1471]	//(B3AB20LDU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
#define idB3AB20LDU	 616	//(B3AB20LDU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
#define C1MD31LP1	 BUFFER[1473]	//(C1MD31LP1) Кнопка «СБРОС ББ»
#define idC1MD31LP1	 617	//(C1MD31LP1) Кнопка «СБРОС ББ»
#define C1MD31LP2	 BUFFER[1475]	//(C1MD31LP2) Кнопка «СБРОС ББ»
#define idC1MD31LP2	 618	//(C1MD31LP2) Кнопка «СБРОС ББ»
#define A2AD31LDU	 BUFFER[1477]	//(A2AD31LDU) Клапан «Сброс РБ1» открыть (обесточить)
#define idA2AD31LDU	 619	//(A2AD31LDU) Клапан «Сброс РБ1» открыть (обесточить)
#define B2AD31LDU	 BUFFER[1479]	//(B2AD31LDU) Клапан «Сброс РБ2» открыть (обесточить)
#define idB2AD31LDU	 620	//(B2AD31LDU) Клапан «Сброс РБ2» открыть (обесточить)
#define A1AD31LDU	 BUFFER[1481]	//(A1AD31LDU) Клапан «Сброс ББ1» открыть (обесточить)
#define idA1AD31LDU	 621	//(A1AD31LDU) Клапан «Сброс ББ1» открыть (обесточить)
#define B1AD31LDU	 BUFFER[1483]	//(B1AD31LDU) Клапан «Сброс ББ2» открыть (обесточить)
#define idB1AD31LDU	 622	//(B1AD31LDU) Клапан «Сброс ББ2» открыть (обесточить)
#define A2AD32LDU	 BUFFER[1485]	//(A2AD32LDU) Обесточить ЭМ РБ1
#define idA2AD32LDU	 623	//(A2AD32LDU) Обесточить ЭМ РБ1
#define B2AD32LDU	 BUFFER[1487]	//(B2AD32LDU) Обесточить ЭМ РБ2
#define idB2AD32LDU	 624	//(B2AD32LDU) Обесточить ЭМ РБ2
#define A1AD32LDU	 BUFFER[1489]	//(A1AD32LDU) Обесточить ЭМ ББ1
#define idA1AD32LDU	 625	//(A1AD32LDU) Обесточить ЭМ ББ1
#define B1AD32LDU	 BUFFER[1491]	//(B1AD32LDU) Обесточить ЭМ ББ2
#define idB1AD32LDU	 626	//(B1AD32LDU) Обесточить ЭМ ББ2
#define R0MD11LP2	 BUFFER[1493]	//(R0MD11LP2) Кнопка Пуск проверки схем сброса
#define idR0MD11LP2	 627	//(R0MD11LP2) Кнопка Пуск проверки схем сброса
#define R0VX01LDU	 BUFFER[1495]	//(R0VX01LDU) ДО ИМПУЛЬСА
#define idR0VX01LDU	 628	//(R0VX01LDU) ДО ИМПУЛЬСА
#define A3AB17LDU	 BUFFER[1497]	//(A3AB17LDU) Блокировка перемещения ИС1: выполняется программа 20 мин
#define idA3AB17LDU	 629	//(A3AB17LDU) Блокировка перемещения ИС1: выполняется программа 20 мин
#define A3AB18LDU	 BUFFER[1499]	//(A3AB18LDU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
#define idA3AB18LDU	 630	//(A3AB18LDU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
#define A3AB19LDU	 BUFFER[1501]	//(A3AB19LDU) Блокировка пневматического подъема ИС1: режим статический
#define idA3AB19LDU	 631	//(A3AB19LDU) Блокировка пневматического подъема ИС1: режим статический
#define A3AB20LDU	 BUFFER[1503]	//(A3AB20LDU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
#define idA3AB20LDU	 632	//(A3AB20LDU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
#define B3VS12LDU	 BUFFER[1505]	//(B3VS12LDU) Движение ИС2 в сторону ВУ
#define idB3VS12LDU	 633	//(B3VS12LDU) Движение ИС2 в сторону ВУ
#define B3CV01RDU	 BUFFER[1507]	//(B3CV01RDU) Измеренная скорость перемещения ИС2
#define idB3CV01RDU	 634	//(B3CV01RDU) Измеренная скорость перемещения ИС2
#define B3AB04LDU	 BUFFER[1512]	//(B3AB04LDU) Блокировка движения ИС2 нет перемещения  ИС1
#define idB3AB04LDU	 635	//(B3AB04LDU) Блокировка движения ИС2 нет перемещения  ИС1
#define B3AB02LDU	 BUFFER[1514]	//(B3AB02LDU) Блокировка движения ИС2: превышение заданной скорости
#define idB3AB02LDU	 636	//(B3AB02LDU) Блокировка движения ИС2: превышение заданной скорости
#define B3AB01LDU	 BUFFER[1516]	//(B3AB01LDU) Блокировка движения ИС2: скорость перемещения менее заданной
#define idB3AB01LDU	 637	//(B3AB01LDU) Блокировка движения ИС2: скорость перемещения менее заданной
#define B3VS22LDU	 BUFFER[1518]	//(B3VS22LDU) Движение ИС2 в сторону НУ
#define idB3VS22LDU	 638	//(B3VS22LDU) Движение ИС2 в сторону НУ
#define B3AZ03LDU	 BUFFER[1520]	//(B3AZ03LDU) Несанкционированное перемещение ИС2
#define idB3AZ03LDU	 639	//(B3AZ03LDU) Несанкционированное перемещение ИС2
#define B3AD11LDU	 BUFFER[1522]	//(B3AD11LDU) Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	 640	//(B3AD11LDU) Сигнал на перемещение ИС2 вверх
#define B3AD21LDU	 BUFFER[1524]	//(B3AD21LDU) Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	 641	//(B3AD21LDU) Сигнал на перемещение ИС2 вниз
#define B3AD02LDU	 BUFFER[1526]	//(B3AD02LDU) 0-й бит скорости ИС2
#define idB3AD02LDU	 642	//(B3AD02LDU) 0-й бит скорости ИС2
#define B3AD03LDU	 BUFFER[1528]	//(B3AD03LDU) 1-й бит скорости ИС2
#define idB3AD03LDU	 643	//(B3AD03LDU) 1-й бит скорости ИС2
#define B3AD04LDU	 BUFFER[1530]	//(B3AD04LDU) 2-й бит скорости ИС2
#define idB3AD04LDU	 644	//(B3AD04LDU) 2-й бит скорости ИС2
#define B3AD05LDU	 BUFFER[1532]	//(B3AD05LDU) паритет команды на ИС2
#define idB3AD05LDU	 645	//(B3AD05LDU) паритет команды на ИС2
#define B3AD01LDU	 BUFFER[1534]	//(B3AD01LDU) Разрешение движения ИС2
#define idB3AD01LDU	 646	//(B3AD01LDU) Разрешение движения ИС2
#define B3CV02RDU	 BUFFER[1536]	//(B3CV02RDU) Заданная скорость перемещения ИС2
#define idB3CV02RDU	 647	//(B3CV02RDU) Заданная скорость перемещения ИС2
#define B3AB07LDU	 BUFFER[1541]	//(B3AB07LDU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
#define idB3AB07LDU	 648	//(B3AB07LDU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
#define B3AB08LDU	 BUFFER[1543]	//(B3AB08LDU) Блокировка подъёма ИС2 - реактор не на рабочем месте
#define idB3AB08LDU	 649	//(B3AB08LDU) Блокировка подъёма ИС2 - реактор не на рабочем месте
#define B3AB05LDU	 BUFFER[1545]	//(B3AB05LDU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
#define idB3AB05LDU	 650	//(B3AB05LDU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
#define B3AB06LDU	 BUFFER[1547]	//(B3AB06LDU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
#define idB3AB06LDU	 651	//(B3AB06LDU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
#define B2AD05LDU	 BUFFER[1549]	//(B2AD05LDU) паритет команды на РБ2
#define idB2AD05LDU	 652	//(B2AD05LDU) паритет команды на РБ2
#define B2AD01LDU	 BUFFER[1551]	//(B2AD01LDU) Разрешение движения РБ2
#define idB2AD01LDU	 653	//(B2AD01LDU) Разрешение движения РБ2
#define B2CV02RDU	 BUFFER[1553]	//(B2CV02RDU) Заданная скорость перемещения РБ2
#define idB2CV02RDU	 654	//(B2CV02RDU) Заданная скорость перемещения РБ2
#define B2AB07LDU	 BUFFER[1558]	//(B2AB07LDU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
#define idB2AB07LDU	 655	//(B2AB07LDU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
#define B2AB08LDU	 BUFFER[1560]	//(B2AB08LDU) Блокировка подъёма РБ2 - реактор не на рабочем месте
#define idB2AB08LDU	 656	//(B2AB08LDU) Блокировка подъёма РБ2 - реактор не на рабочем месте
#define B2AB05LDU	 BUFFER[1562]	//(B2AB05LDU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
#define idB2AB05LDU	 657	//(B2AB05LDU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
#define B2AB06LDU	 BUFFER[1564]	//(B2AB06LDU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
#define idB2AB06LDU	 658	//(B2AB06LDU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
#define B2AB09LDU	 BUFFER[1566]	//(B2AB09LDU) Блокировка подъёма РБ2- АНИ не установлен
#define idB2AB09LDU	 659	//(B2AB09LDU) Блокировка подъёма РБ2- АНИ не установлен
#define B2AB10LDU	 BUFFER[1568]	//(B2AB10LDU) Блокировка подъёма РБ2- есть сигнал общего сброса
#define idB2AB10LDU	 660	//(B2AB10LDU) Блокировка подъёма РБ2- есть сигнал общего сброса
#define B2AB11LDU	 BUFFER[1570]	//(B2AB11LDU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
#define idB2AB11LDU	 661	//(B2AB11LDU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
#define B2AB12LDU	 BUFFER[1572]	//(B2AB12LDU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define idB2AB12LDU	 662	//(B2AB12LDU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define B2AB13LDU	 BUFFER[1574]	//(B2AB13LDU) Блокировка подъёма РБ2- давление в пневмосистеме РБ ниже значения заданного предупредительной уставкой
#define idB2AB13LDU	 663	//(B2AB13LDU) Блокировка подъёма РБ2- давление в пневмосистеме РБ ниже значения заданного предупредительной уставкой
#define B2AB14LDU	 BUFFER[1576]	//(B2AB14LDU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
#define idB2AB14LDU	 664	//(B2AB14LDU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
#define B2AB16LDU	 BUFFER[1578]	//(B2AB16LDU) Блокировка перемещения РБ2: выполняется программа 200 с
#define idB2AB16LDU	 665	//(B2AB16LDU) Блокировка перемещения РБ2: выполняется программа 200 с
#define B2AB17LDU	 BUFFER[1580]	//(B2AB17LDU) Блокировка перемещения РБ2: выполняется программа 20 мин
#define idB2AB17LDU	 666	//(B2AB17LDU) Блокировка перемещения РБ2: выполняется программа 20 мин
#define R1AZ03LDU	 BUFFER[1582]	//(R1AZ03LDU) Несанкционированное перемещение МДЗ1
#define idR1AZ03LDU	 667	//(R1AZ03LDU) Несанкционированное перемещение МДЗ1
#define R1AB01LDU	 BUFFER[1584]	//(R1AB01LDU) Блокировка движения МДЗ1 - Превышение времени движения
#define idR1AB01LDU	 668	//(R1AB01LDU) Блокировка движения МДЗ1 - Превышение времени движения
#define R1AB02LDU	 BUFFER[1586]	//(R1AB02LDU) Блокировка МДЗ1 - Нет перемещения
#define idR1AB02LDU	 669	//(R1AB02LDU) Блокировка МДЗ1 - Нет перемещения
#define R2AZ03LDU	 BUFFER[1588]	//(R2AZ03LDU) Несанкционированное перемещение МДЗ2
#define idR2AZ03LDU	 670	//(R2AZ03LDU) Несанкционированное перемещение МДЗ2
#define R2AB01LDU	 BUFFER[1590]	//(R2AB01LDU) Блокировка движения МДЗ2 - Превышение времени движения
#define idR2AB01LDU	 671	//(R2AB01LDU) Блокировка движения МДЗ2 - Превышение времени движения
#define R2AB02LDU	 BUFFER[1592]	//(R2AB02LDU) Блокировка МДЗ2 - Нет перемещения
#define idR2AB02LDU	 672	//(R2AB02LDU) Блокировка МДЗ2 - Нет перемещения
#define R1AB04LDU	 BUFFER[1594]	//(R1AB04LDU) Блокировка МДЗ1 -Ошибка в направлении  движения
#define idR1AB04LDU	 673	//(R1AB04LDU) Блокировка МДЗ1 -Ошибка в направлении  движения
#define A2AB08LDU	 BUFFER[1596]	//(A2AB08LDU) Блокировка подъёма РБ1 - реактор не на рабочем месте
#define idA2AB08LDU	 674	//(A2AB08LDU) Блокировка подъёма РБ1 - реактор не на рабочем месте
#define A2AB05LDU	 BUFFER[1598]	//(A2AB05LDU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
#define idA2AB05LDU	 675	//(A2AB05LDU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
#define A2AB06LDU	 BUFFER[1600]	//(A2AB06LDU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
#define idA2AB06LDU	 676	//(A2AB06LDU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
#define A2AB09LDU	 BUFFER[1602]	//(A2AB09LDU) Блокировка подъёма РБ1- АНИ не установлен
#define idA2AB09LDU	 677	//(A2AB09LDU) Блокировка подъёма РБ1- АНИ не установлен
#define A2AB10LDU	 BUFFER[1604]	//(A2AB10LDU) Блокировка подъёма РБ1- есть сигнал общего сброса
#define idA2AB10LDU	 678	//(A2AB10LDU) Блокировка подъёма РБ1- есть сигнал общего сброса
#define A2AB11LDU	 BUFFER[1606]	//(A2AB11LDU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
#define idA2AB11LDU	 679	//(A2AB11LDU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
#define A2AB12LDU	 BUFFER[1608]	//(A2AB12LDU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA2AB12LDU	 680	//(A2AB12LDU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A2AB13LDU	 BUFFER[1610]	//(A2AB13LDU) Блокировка подъёма РБ1- давление в пневмосистеме РБ ниже значения заданного предупредительной уставкой
#define idA2AB13LDU	 681	//(A2AB13LDU) Блокировка подъёма РБ1- давление в пневмосистеме РБ ниже значения заданного предупредительной уставкой
#define A2AB14LDU	 BUFFER[1612]	//(A2AB14LDU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
#define idA2AB14LDU	 682	//(A2AB14LDU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
#define A2AB16LDU	 BUFFER[1614]	//(A2AB16LDU) Блокировка перемещения РБ1: выполняется программа 200 с
#define idA2AB16LDU	 683	//(A2AB16LDU) Блокировка перемещения РБ1: выполняется программа 200 с
#define A2AB17LDU	 BUFFER[1616]	//(A2AB17LDU) Блокировка перемещения РБ1: выполняется программа 20 мин
#define idA2AB17LDU	 684	//(A2AB17LDU) Блокировка перемещения РБ1: выполняется программа 20 мин
#define A2AD01LDU	 BUFFER[1618]	//(A2AD01LDU) Разрешение движения РБ1
#define idA2AD01LDU	 685	//(A2AD01LDU) Разрешение движения РБ1
#define A2CV02RDU	 BUFFER[1620]	//(A2CV02RDU) Заданная скорость перемещения РБ1
#define idA2CV02RDU	 686	//(A2CV02RDU) Заданная скорость перемещения РБ1
#define B2CV01RDU	 BUFFER[1625]	//(B2CV01RDU) Измеренная скорость перемещения РБ2
#define idB2CV01RDU	 687	//(B2CV01RDU) Измеренная скорость перемещения РБ2
#define B2AB04LDU	 BUFFER[1630]	//(B2AB04LDU) Блокировка движения РБ2 нет перемещения  РБ2
#define idB2AB04LDU	 688	//(B2AB04LDU) Блокировка движения РБ2 нет перемещения  РБ2
#define B2AB02LDU	 BUFFER[1632]	//(B2AB02LDU) Блокировка движения РБ2: превышение заданной скорости
#define idB2AB02LDU	 689	//(B2AB02LDU) Блокировка движения РБ2: превышение заданной скорости
#define B2AB01LDU	 BUFFER[1634]	//(B2AB01LDU) Блокировка движения РБ2: скорость перемещения менее заданной
#define idB2AB01LDU	 690	//(B2AB01LDU) Блокировка движения РБ2: скорость перемещения менее заданной
#define B2AZ03LDU	 BUFFER[1636]	//(B2AZ03LDU) Несанкционированное перемещение РБ2
#define idB2AZ03LDU	 691	//(B2AZ03LDU) Несанкционированное перемещение РБ2
#define B2AD11LDU	 BUFFER[1638]	//(B2AD11LDU) Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	 692	//(B2AD11LDU) Сигнал на перемещение РБ2 вверх
#define B2AD21LDU	 BUFFER[1640]	//(B2AD21LDU) Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	 693	//(B2AD21LDU) Сигнал на перемещение РБ2 вниз
#define B2AD02LDU	 BUFFER[1642]	//(B2AD02LDU) 0-й бит скорости РБ2
#define idB2AD02LDU	 694	//(B2AD02LDU) 0-й бит скорости РБ2
#define B2AD03LDU	 BUFFER[1644]	//(B2AD03LDU) 1-й бит скорости РБ2
#define idB2AD03LDU	 695	//(B2AD03LDU) 1-й бит скорости РБ2
#define B2AD04LDU	 BUFFER[1646]	//(B2AD04LDU) 2-й бит скорости РБ2
#define idB2AD04LDU	 696	//(B2AD04LDU) 2-й бит скорости РБ2
#define A1CV02RDU	 BUFFER[1648]	//(A1CV02RDU) Заданная скорость перемещения ББ1
#define idA1CV02RDU	 697	//(A1CV02RDU) Заданная скорость перемещения ББ1
#define A1AB07LDU	 BUFFER[1653]	//(A1AB07LDU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
#define idA1AB07LDU	 698	//(A1AB07LDU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
#define A1AB08LDU	 BUFFER[1655]	//(A1AB08LDU) Блокировка подъёма ББ1 - реактор не на рабочем месте
#define idA1AB08LDU	 699	//(A1AB08LDU) Блокировка подъёма ББ1 - реактор не на рабочем месте
#define A1AB05LDU	 BUFFER[1657]	//(A1AB05LDU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
#define idA1AB05LDU	 700	//(A1AB05LDU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
#define A1AB06LDU	 BUFFER[1659]	//(A1AB06LDU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
#define idA1AB06LDU	 701	//(A1AB06LDU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
#define A1AB09LDU	 BUFFER[1661]	//(A1AB09LDU) Блокировка подъёма ББ1- АНИ не установлен
#define idA1AB09LDU	 702	//(A1AB09LDU) Блокировка подъёма ББ1- АНИ не установлен
#define A1AB10LDU	 BUFFER[1663]	//(A1AB10LDU) Блокировка подъёма ББ1- есть сигнал общего сброса
#define idA1AB10LDU	 703	//(A1AB10LDU) Блокировка подъёма ББ1- есть сигнал общего сброса
#define A1AB11LDU	 BUFFER[1665]	//(A1AB11LDU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
#define idA1AB11LDU	 704	//(A1AB11LDU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
#define A1AB12LDU	 BUFFER[1667]	//(A1AB12LDU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA1AB12LDU	 705	//(A1AB12LDU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A1AB13LDU	 BUFFER[1669]	//(A1AB13LDU) Блокировка подъёма ББ1- давление в пневмосистеме ББ1 ниже значения заданного предупредительной уставкой
#define idA1AB13LDU	 706	//(A1AB13LDU) Блокировка подъёма ББ1- давление в пневмосистеме ББ1 ниже значения заданного предупредительной уставкой
#define A1AB14LDU	 BUFFER[1671]	//(A1AB14LDU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
#define idA1AB14LDU	 707	//(A1AB14LDU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
#define A1AB16LDU	 BUFFER[1673]	//(A1AB16LDU) Блокировка перемещения ББ1: выполняется программа 200 с
#define idA1AB16LDU	 708	//(A1AB16LDU) Блокировка перемещения ББ1: выполняется программа 200 с
#define A1AB17LDU	 BUFFER[1675]	//(A1AB17LDU) Блокировка перемещения ББ1: выполняется программа 20 мин
#define idA1AB17LDU	 709	//(A1AB17LDU) Блокировка перемещения ББ1: выполняется программа 20 мин
#define A1AB18LDU	 BUFFER[1677]	//(A1AB18LDU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
#define idA1AB18LDU	 710	//(A1AB18LDU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
#define B1VS12LDU	 BUFFER[1679]	//(B1VS12LDU) Движение ББ2 в сторону ВУ
#define idB1VS12LDU	 711	//(B1VS12LDU) Движение ББ2 в сторону ВУ
#define B1CV01RDU	 BUFFER[1681]	//(B1CV01RDU) Измеренная скорость перемещения ББ2
#define idB1CV01RDU	 712	//(B1CV01RDU) Измеренная скорость перемещения ББ2
#define B1AB04LDU	 BUFFER[1686]	//(B1AB04LDU) Блокировка движения ББ2 нет перемещения  ББ2
#define idB1AB04LDU	 713	//(B1AB04LDU) Блокировка движения ББ2 нет перемещения  ББ2
#define B1AB02LDU	 BUFFER[1688]	//(B1AB02LDU) Блокировка движения ББ2: превышение заданной скорости
#define idB1AB02LDU	 714	//(B1AB02LDU) Блокировка движения ББ2: превышение заданной скорости
#define B1AB01LDU	 BUFFER[1690]	//(B1AB01LDU) Блокировка движения ББ2: скорость перемещения менее заданной
#define idB1AB01LDU	 715	//(B1AB01LDU) Блокировка движения ББ2: скорость перемещения менее заданной
#define B1VS22LDU	 BUFFER[1692]	//(B1VS22LDU) Движение ББ2 в сторону НУ
#define idB1VS22LDU	 716	//(B1VS22LDU) Движение ББ2 в сторону НУ
#define B1AZ03LDU	 BUFFER[1694]	//(B1AZ03LDU) Сброс ББ2: Несанкционированное перемещение ББ2
#define idB1AZ03LDU	 717	//(B1AZ03LDU) Сброс ББ2: Несанкционированное перемещение ББ2
#define B1AD11LDU	 BUFFER[1696]	//(B1AD11LDU) Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	 718	//(B1AD11LDU) Сигнал на перемещение ББ2 вверх
#define B1AD21LDU	 BUFFER[1698]	//(B1AD21LDU) Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	 719	//(B1AD21LDU) Сигнал на перемещение ББ2 вниз
#define R2AB04LDU	 BUFFER[1700]	//(R2AB04LDU) Блокировка МДЗ2 -Ошибка в направлении  движения
#define idR2AB04LDU	 720	//(R2AB04LDU) Блокировка МДЗ2 -Ошибка в направлении  движения
#define R1AD10LDU	 BUFFER[1702]	//(R1AD10LDU) Опустить МДЗ1 в зону облучения
#define idR1AD10LDU	 721	//(R1AD10LDU) Опустить МДЗ1 в зону облучения
#define R1AD20LDU	 BUFFER[1704]	//(R1AD20LDU) Поднять МДЗ1
#define idR1AD20LDU	 722	//(R1AD20LDU) Поднять МДЗ1
#define R1IS11LDU	 BUFFER[1706]	//(R1IS11LDU) Приход на ВУ МДЗ1
#define idR1IS11LDU	 723	//(R1IS11LDU) Приход на ВУ МДЗ1
#define R1VS22LDU	 BUFFER[1708]	//(R1VS22LDU) Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	 724	//(R1VS22LDU) Движение МДЗ1 в сторону НУ
#define R2VS22LDU	 BUFFER[1710]	//(R2VS22LDU) Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	 725	//(R2VS22LDU) Движение МДЗ2 в сторону НУ
#define R2VS12LDU	 BUFFER[1712]	//(R2VS12LDU) Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	 726	//(R2VS12LDU) Движение МДЗ2 в сторону ВУ
#define R1VS12LDU	 BUFFER[1714]	//(R1VS12LDU) Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	 727	//(R1VS12LDU) Движение МДЗ1 в сторону ВУ
#define R2IS11LDU	 BUFFER[1716]	//(R2IS11LDU) Приход на ВУ МДЗ2
#define idR2IS11LDU	 728	//(R2IS11LDU) Приход на ВУ МДЗ2
#define A1VS12LDU	 BUFFER[1718]	//(A1VS12LDU) Движение ББ1 в сторону ВУ
#define idA1VS12LDU	 729	//(A1VS12LDU) Движение ББ1 в сторону ВУ
#define A1CV01RDU	 BUFFER[1720]	//(A1CV01RDU) Измеренная скорость перемещения ББ1
#define idA1CV01RDU	 730	//(A1CV01RDU) Измеренная скорость перемещения ББ1
#define A1AB04LDU	 BUFFER[1725]	//(A1AB04LDU) Блокировка движения ББ1 нет перемещения  ББ1
#define idA1AB04LDU	 731	//(A1AB04LDU) Блокировка движения ББ1 нет перемещения  ББ1
#define A1AB02LDU	 BUFFER[1727]	//(A1AB02LDU) Блокировка движения ББ1: превышение заданной скорости
#define idA1AB02LDU	 732	//(A1AB02LDU) Блокировка движения ББ1: превышение заданной скорости
#define A1AB01LDU	 BUFFER[1729]	//(A1AB01LDU) Блокировка движения ББ1: скорость перемещения менее заданной
#define idA1AB01LDU	 733	//(A1AB01LDU) Блокировка движения ББ1: скорость перемещения менее заданной
#define A1VS22LDU	 BUFFER[1731]	//(A1VS22LDU) Движение ББ1 в сторону НУ
#define idA1VS22LDU	 734	//(A1VS22LDU) Движение ББ1 в сторону НУ
#define A1AZ03LDU	 BUFFER[1733]	//(A1AZ03LDU) Сброс ББ1: Несанкционированное перемещение ББ1
#define idA1AZ03LDU	 735	//(A1AZ03LDU) Сброс ББ1: Несанкционированное перемещение ББ1
#define A1AD11LDU	 BUFFER[1735]	//(A1AD11LDU) Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	 736	//(A1AD11LDU) Сигнал на перемещение ББ1 вверх
#define A1AD21LDU	 BUFFER[1737]	//(A1AD21LDU) Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	 737	//(A1AD21LDU) Сигнал на перемещение ББ1 вниз
#define A1AD02LDU	 BUFFER[1739]	//(A1AD02LDU) 0-й бит скорости ББ1
#define idA1AD02LDU	 738	//(A1AD02LDU) 0-й бит скорости ББ1
#define A1AD03LDU	 BUFFER[1741]	//(A1AD03LDU) 1-й бит скорости ББ1
#define idA1AD03LDU	 739	//(A1AD03LDU) 1-й бит скорости ББ1
#define A1AD04LDU	 BUFFER[1743]	//(A1AD04LDU) 2-й бит скорости ББ1
#define idA1AD04LDU	 740	//(A1AD04LDU) 2-й бит скорости ББ1
#define A1AD05LDU	 BUFFER[1745]	//(A1AD05LDU) паритет команды на ББ1
#define idA1AD05LDU	 741	//(A1AD05LDU) паритет команды на ББ1
#define A1AD01LDU	 BUFFER[1747]	//(A1AD01LDU) Разрешение движения ББ1
#define idA1AD01LDU	 742	//(A1AD01LDU) Разрешение движения ББ1
#define fEM_A1UC03RDU	 BUFFER[1749]	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define idfEM_A1UC03RDU	 743	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define dEM_A1UC05UDU	 BUFFER[1754]	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC05UDU	 744	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define dEM_A1UC06UDU	 BUFFER[1759]	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC06UDU	 745	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define dEM_A2UC06UDU	 BUFFER[1764]	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC06UDU	 746	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define dEM_A2UC05UDU	 BUFFER[1769]	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC05UDU	 747	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define fEM_A2UC03RDU	 BUFFER[1774]	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define idfEM_A2UC03RDU	 748	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define dEM_A3UC06UDU	 BUFFER[1779]	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC06UDU	 749	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define dEM_A3UC05UDU	 BUFFER[1784]	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC05UDU	 750	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define fEM_A3UC03RDU	 BUFFER[1789]	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define idfEM_A3UC03RDU	 751	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define dEM_A8UC06UDU	 BUFFER[1794]	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define iddEM_A8UC06UDU	 752	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define fEM_A8UC03RDU	 BUFFER[1799]	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
#define idfEM_A8UC03RDU	 753	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
#define dEM_A8UC05UDU	 BUFFER[1804]	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define iddEM_A8UC05UDU	 754	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define fEM_R0UV81RDU	 BUFFER[1809]	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	 755	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	 BUFFER[1814]	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	 756	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	 BUFFER[1819]	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	 757	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	 BUFFER[1824]	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	 758	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define fEM_R0UV86RDU	 BUFFER[1829]	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	 759	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV85RDU	 BUFFER[1834]	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	 760	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV87RDU	 BUFFER[1839]	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	 761	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_A3UP03RDU	 BUFFER[1844]	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	 762	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	 BUFFER[1849]	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	 763	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP43RDU	 BUFFER[1854]	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define idfEM_A3UP43RDU	 764	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define fEM_A3UP44RDU	 BUFFER[1859]	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP44RDU	 765	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP53RDU	 BUFFER[1864]	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP53RDU	 766	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP85RDU	 BUFFER[1869]	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP85RDU	 767	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP88RDU	 BUFFER[1874]	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP88RDU	 768	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP86RDU	 BUFFER[1879]	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP86RDU	 769	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_B8UV01RDU	 BUFFER[1884]	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
#define idfEM_B8UV01RDU	 770	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
#define fEM_B8UV02RDU	 BUFFER[1889]	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
#define idfEM_B8UV02RDU	 771	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
#define fEM_B8UV03RDU	 BUFFER[1894]	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
#define idfEM_B8UV03RDU	 772	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
#define fEM_B8UL04RDU	 BUFFER[1899]	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
#define idfEM_B8UL04RDU	 773	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
#define iEM_A2UV03CDU	 BUFFER[1904]	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define idiEM_A2UV03CDU	 774	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define fEM_A2UV01RDU	 BUFFER[1907]	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define idfEM_A2UV01RDU	 775	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define fEM_A2UV02RDU	 BUFFER[1912]	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define idfEM_A2UV02RDU	 776	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define fEM_A1UV01RDU	 BUFFER[1917]	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define idfEM_A1UV01RDU	 777	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define fEM_A1UV02RDU	 BUFFER[1922]	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define idfEM_A1UV02RDU	 778	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define fEM_A1UC06RDU	 BUFFER[1927]	//(A1UC06RDU) Уставка определения самохода ББ  мм
#define idfEM_A1UC06RDU	 779	//(A1UC06RDU) Уставка определения самохода ББ  мм
#define fEM_A1UC05RDU	 BUFFER[1932]	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A1UC05RDU	 780	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A1UL04RDU	 BUFFER[1937]	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define idfEM_A1UL04RDU	 781	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define fEM_A3UV01RDU	 BUFFER[1942]	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
#define idfEM_A3UV01RDU	 782	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
#define fEM_A3UV02RDU	 BUFFER[1947]	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
#define idfEM_A3UV02RDU	 783	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
#define fEM_A3UC06RDU	 BUFFER[1952]	//(A3UC06RDU) Уставка определения самохода ИС1  мм
#define idfEM_A3UC06RDU	 784	//(A3UC06RDU) Уставка определения самохода ИС1  мм
#define fEM_A3UC05RDU	 BUFFER[1957]	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A3UC05RDU	 785	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define fEM_A3UL04RDU	 BUFFER[1962]	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define idfEM_A3UL04RDU	 786	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define fEM_A3UP54RDU	 BUFFER[1967]	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define idfEM_A3UP54RDU	 787	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define fEM_A3UP87RDU	 BUFFER[1972]	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP87RDU	 788	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_R0UL05RDU	 BUFFER[1977]	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
#define idfEM_R0UL05RDU	 789	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
#define fEM_R0UL20RDU	 BUFFER[1982]	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
#define idfEM_R0UL20RDU	 790	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
#define fEM_B8UV04RDU	 BUFFER[1987]	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
#define idfEM_B8UV04RDU	 791	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
#define fEM_B8UC06RDU	 BUFFER[1992]	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
#define idfEM_B8UC06RDU	 792	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
#define fEM_B8UC05RDU	 BUFFER[1997]	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
#define idfEM_B8UC05RDU	 793	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
#define fEM_A2UL05RDU	 BUFFER[2002]	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define idfEM_A2UL05RDU	 794	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define fEM_A2UL03RDU	 BUFFER[2007]	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL03RDU	 795	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A2UC06RDU	 BUFFER[2012]	//(A2UC06RDU) Уставка определения самохода РБ  мм
#define idfEM_A2UC06RDU	 796	//(A2UC06RDU) Уставка определения самохода РБ  мм
#define fEM_A2UC05RDU	 BUFFER[2017]	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A2UC05RDU	 797	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A2UL04RDU	 BUFFER[2022]	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define idfEM_A2UL04RDU	 798	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define fEM_A1UL03RDU	 BUFFER[2027]	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define idfEM_A1UL03RDU	 799	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define fEM_A1UL05RDU	 BUFFER[2032]	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define idfEM_A1UL05RDU	 800	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define fEM_A3UL03RDU	 BUFFER[2037]	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define idfEM_A3UL03RDU	 801	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define fEM_A3UL05RDU	 BUFFER[2042]	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define idfEM_A3UL05RDU	 802	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define fEM_A1UC08RDU	 BUFFER[2047]	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define idfEM_A1UC08RDU	 803	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define fEM_A3UC08RDU	 BUFFER[2052]	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define idfEM_A3UC08RDU	 804	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define fEM_A1UC07RDU	 BUFFER[2057]	//(A1UC07RDU) Зона возврата при наведении ББ мм
#define idfEM_A1UC07RDU	 805	//(A1UC07RDU) Зона возврата при наведении ББ мм
#define fEM_A1UL01RDU	 BUFFER[2062]	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A1UL01RDU	 806	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A3UC07RDU	 BUFFER[2067]	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define idfEM_A3UC07RDU	 807	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define fEM_A3UL01RDU	 BUFFER[2072]	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A3UL01RDU	 808	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A2UC08RDU	 BUFFER[2077]	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define idfEM_A2UC08RDU	 809	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define fEM_A2UC07RDU	 BUFFER[2082]	//(A2UC07RDU) Зона возврата при наведении РБ  мм
#define idfEM_A2UC07RDU	 810	//(A2UC07RDU) Зона возврата при наведении РБ  мм
#define fEM_A2UL01RDU	 BUFFER[2087]	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A2UL01RDU	 811	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_B8UC01RDU	 BUFFER[2092]	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
#define idfEM_B8UC01RDU	 812	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
#define fEM_B8UL07RDU	 BUFFER[2097]	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
#define idfEM_B8UL07RDU	 813	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
#define fEM_B8UC02RDU	 BUFFER[2102]	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
#define idfEM_B8UC02RDU	 814	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
#define fEM_B8UL01RDU	 BUFFER[2107]	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_B8UL01RDU	 815	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_B8UL05RDU	 BUFFER[2112]	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
#define idfEM_B8UL05RDU	 816	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
#define fEM_B8UL03RDU	 BUFFER[2117]	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
#define idfEM_B8UL03RDU	 817	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
#define fEM_B8UL06RDU	 BUFFER[2122]	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
#define idfEM_B8UL06RDU	 818	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
#define fEM_A9UZ03RDU	 BUFFER[2127]	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
#define idfEM_A9UZ03RDU	 819	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
#define fEM_A9UZ04RDU	 BUFFER[2132]	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
#define idfEM_A9UZ04RDU	 820	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
#define fEM_A9UZ05RDU	 BUFFER[2137]	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
#define idfEM_A9UZ05RDU	 821	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
#define fEM_R4UZ04RDU	 BUFFER[2142]	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define idfEM_R4UZ04RDU	 822	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define fEM_R4UZ03RDU	 BUFFER[2147]	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define idfEM_R4UZ03RDU	 823	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define fEM_R4UZ05RDU	 BUFFER[2152]	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define idfEM_R4UZ05RDU	 824	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define fEM_A5UZ03RDU	 BUFFER[2157]	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
#define idfEM_A5UZ03RDU	 825	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
#define fEM_A5UZ04RDU	 BUFFER[2162]	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
#define idfEM_A5UZ04RDU	 826	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
#define fEM_A5UZ05RDU	 BUFFER[2167]	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
#define idfEM_A5UZ05RDU	 827	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
#define fEM_A4UZ03RDU	 BUFFER[2172]	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
#define idfEM_A4UZ03RDU	 828	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
#define fEM_A4UZ04RDU	 BUFFER[2177]	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
#define idfEM_A4UZ04RDU	 829	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
#define fEM_A4UZ05RDU	 BUFFER[2182]	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
#define idfEM_A4UZ05RDU	 830	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
#define fEM_A6UZ03RDU	 BUFFER[2187]	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
#define idfEM_A6UZ03RDU	 831	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
#define fEM_A6UZ04RDU	 BUFFER[2192]	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
#define idfEM_A6UZ04RDU	 832	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
#define fEM_A6UZ05RDU	 BUFFER[2197]	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
#define idfEM_A6UZ05RDU	 833	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
#define fEM_R1UZ03RDU	 BUFFER[2202]	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define idfEM_R1UZ03RDU	 834	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define fEM_R1UZ04RDU	 BUFFER[2207]	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define idfEM_R1UZ04RDU	 835	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define fEM_R1UZ05RDU	 BUFFER[2212]	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define idfEM_R1UZ05RDU	 836	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define fEM_R5UL10RDU	 BUFFER[2217]	//(R5UL10RDU) Время полного хода ворот отстойной зоны сек
#define idfEM_R5UL10RDU	 837	//(R5UL10RDU) Время полного хода ворот отстойной зоны сек
#define fEM_R5UZ03RDU	 BUFFER[2222]	//(R5UZ03RDU) Время задержки блокировки ворот отстойной зоны по самоходу сек
#define idfEM_R5UZ03RDU	 838	//(R5UZ03RDU) Время задержки блокировки ворот отстойной зоны по самоходу сек
#define fEM_R5UZ04RDU	 BUFFER[2227]	//(R5UZ04RDU) Время задержки блокировки ворот отстойной зоны по недвижению сек
#define idfEM_R5UZ04RDU	 839	//(R5UZ04RDU) Время задержки блокировки ворот отстойной зоны по недвижению сек
#define fEM_R0UL04RDU	 BUFFER[2232]	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
#define idfEM_R0UL04RDU	 840	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
#define fEM_R0UL06RDU	 BUFFER[2237]	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
#define idfEM_R0UL06RDU	 841	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
#define fEM_R0UL03RDU	 BUFFER[2242]	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
#define idfEM_R0UL03RDU	 842	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
#define fEM_R0UL17RDU	 BUFFER[2247]	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
#define idfEM_R0UL17RDU	 843	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
#define fEM_R0UL19RDU	 BUFFER[2252]	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define idfEM_R0UL19RDU	 844	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define fEM_R0UL07RDU	 BUFFER[2257]	//(R0UL07RDU) Время срабатывания верхней АС II УР
#define idfEM_R0UL07RDU	 845	//(R0UL07RDU) Время срабатывания верхней АС II УР
#define fEM_R0UL18RDU	 BUFFER[2262]	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
#define idfEM_R0UL18RDU	 846	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
#define fEM_R0UL16RDU	 BUFFER[2267]	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
#define idfEM_R0UL16RDU	 847	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
#define fEM_R0UL02RDU	 BUFFER[2272]	//(R0UL02RDU) Время задержки  ИНИ
#define idfEM_R0UL02RDU	 848	//(R0UL02RDU) Время задержки  ИНИ
#define fEM_R3UZ03RDU	 BUFFER[2277]	//(R3UZ03RDU) Время задержки блокировки гомогеннных дверей по самоходу сек
#define idfEM_R3UZ03RDU	 849	//(R3UZ03RDU) Время задержки блокировки гомогеннных дверей по самоходу сек
#define fEM_R3UL10RDU	 BUFFER[2282]	//(R3UL10RDU) Время полного хода гомогенных дверей сек
#define idfEM_R3UL10RDU	 850	//(R3UL10RDU) Время полного хода гомогенных дверей сек
#define fEM_R3UZ04RDU	 BUFFER[2287]	//(R3UZ04RDU) Время задержки блокировки гомогенных дверей по недвижению сек
#define idfEM_R3UZ04RDU	 851	//(R3UZ04RDU) Время задержки блокировки гомогенных дверей по недвижению сек
#define fEM_R0UN08RDU	 BUFFER[2292]	//(R0UN08RDU) Ограничение 8 по мощности
#define idfEM_R0UN08RDU	 852	//(R0UN08RDU) Ограничение 8 по мощности
#define fEM_R0UN07RDU	 BUFFER[2297]	//(R0UN07RDU) Ограничение 7 по мощности
#define idfEM_R0UN07RDU	 853	//(R0UN07RDU) Ограничение 7 по мощности
#define fEM_R0UN06RDU	 BUFFER[2302]	//(R0UN06RDU) Ограничение 6 по мощности
#define idfEM_R0UN06RDU	 854	//(R0UN06RDU) Ограничение 6 по мощности
#define fEM_R0UN05RDU	 BUFFER[2307]	//(R0UN05RDU) Ограничение 5 по мощности
#define idfEM_R0UN05RDU	 855	//(R0UN05RDU) Ограничение 5 по мощности
#define fEM_R0UN04RDU	 BUFFER[2312]	//(R0UN04RDU) Ограничение 4 по мощности
#define idfEM_R0UN04RDU	 856	//(R0UN04RDU) Ограничение 4 по мощности
#define fEM_R0UN03RDU	 BUFFER[2317]	//(R0UN03RDU) Ограничение 3 по мощности
#define idfEM_R0UN03RDU	 857	//(R0UN03RDU) Ограничение 3 по мощности
#define fEM_R0UN02RDU	 BUFFER[2322]	//(R0UN02RDU) Ограничение 2 по мощности
#define idfEM_R0UN02RDU	 858	//(R0UN02RDU) Ограничение 2 по мощности
#define fEM_R0UN01RDU	 BUFFER[2327]	//(R0UN01RDU) Ограничение 1 по мощности
#define idfEM_R0UN01RDU	 859	//(R0UN01RDU) Ограничение 1 по мощности
#define fEM_A2UC82RDU	 BUFFER[2332]	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC82RDU	 860	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define fEM_A2UC83RDU	 BUFFER[2337]	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define idfEM_A2UC83RDU	 861	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define fEM_A1UC83RDU	 BUFFER[2342]	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define idfEM_A1UC83RDU	 862	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define fEM_A2UC81RDU	 BUFFER[2347]	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC81RDU	 863	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define fEM_A1UC81RDU	 BUFFER[2352]	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC81RDU	 864	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define fEM_A1UC82RDU	 BUFFER[2357]	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC82RDU	 865	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define fEM_A2UL83RDU	 BUFFER[2362]	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL83RDU	 866	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A3UC81RDU	 BUFFER[2367]	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define idfEM_A3UC81RDU	 867	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define fEM_A3UC82RDU	 BUFFER[2372]	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define idfEM_A3UC82RDU	 868	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define fEM_R0UN80RDU	 BUFFER[2377]	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define idfEM_R0UN80RDU	 869	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define fEM_A3UP34RDU	 BUFFER[2382]	//(A3UP34RDU) Время заполнения ресивера ИС (в 10 мс)
#define idfEM_A3UP34RDU	 870	//(A3UP34RDU) Время заполнения ресивера ИС (в 10 мс)
#define iEM_A2UV01IDU	 BUFFER[2387]	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV01IDU	 871	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define iEM_A2UV02IDU	 BUFFER[2390]	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV02IDU	 872	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define iEM_A1UV01IDU	 BUFFER[2393]	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV01IDU	 873	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define iEM_A1UV02IDU	 BUFFER[2396]	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV02IDU	 874	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define iEM_A1UV03IDU	 BUFFER[2399]	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define idiEM_A1UV03IDU	 875	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define iEM_A3UV01IDU	 BUFFER[2402]	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define idiEM_A3UV01IDU	 876	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define iEM_A3UV02IDU	 BUFFER[2405]	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define idiEM_A3UV02IDU	 877	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define lEM_R0MD01LC1	 BUFFER[2408]	//(R0MD01LC1) Ручное управление ОРР
#define idlEM_R0MD01LC1	 878	//(R0MD01LC1) Ручное управление ОРР
#define fEM_A3UC09RDU	 BUFFER[2410]	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC09RDU	 879	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define fEM_A2UC02RDU	 BUFFER[2415]	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define idfEM_A2UC02RDU	 880	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define fEM_A1UC02RDU	 BUFFER[2420]	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define idfEM_A1UC02RDU	 881	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define fEM_A3UC02RDU	 BUFFER[2425]	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define idfEM_A3UC02RDU	 882	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define fEM_R0UL21RDU	 BUFFER[2430]	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
#define idfEM_R0UL21RDU	 883	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
#define fEM_R0UN09RDU	 BUFFER[2435]	//(R0UN09RDU) Минимальный период при регулировании мощности
#define idfEM_R0UN09RDU	 884	//(R0UN09RDU) Минимальный период при регулировании мощности
#define fEM_R0UN11RDU	 BUFFER[2440]	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
#define idfEM_R0UN11RDU	 885	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
#define fEM_R0UN12RDU	 BUFFER[2445]	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
#define idfEM_R0UN12RDU	 886	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
#define fEM_R0UN13RDU	 BUFFER[2450]	//(R0UN13RDU) Минимальное изменение координаты, мм
#define idfEM_R0UN13RDU	 887	//(R0UN13RDU) Минимальное изменение координаты, мм
#define fEM_R0UN14RDU	 BUFFER[2455]	//(R0UN14RDU) Максимальная координата штока ИМ, мм
#define idfEM_R0UN14RDU	 888	//(R0UN14RDU) Максимальная координата штока ИМ, мм
#define fEM_R0UN16RDU	 BUFFER[2460]	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN16RDU	 889	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN17RDU	 BUFFER[2465]	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN17RDU	 890	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN18RDU	 BUFFER[2470]	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
#define idfEM_R0UN18RDU	 891	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
#define fEM_R0UN19RDU	 BUFFER[2475]	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define idfEM_R0UN19RDU	 892	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define fEM_R0UN70LDU	 BUFFER[2480]	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN70LDU	 893	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN71LDU	 BUFFER[2485]	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN71LDU	 894	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN72LDU	 BUFFER[2490]	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN72LDU	 895	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN73LDU	 BUFFER[2495]	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN73LDU	 896	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN74LDU	 BUFFER[2500]	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN74LDU	 897	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN75LDU	 BUFFER[2505]	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN75LDU	 898	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN80LDU	 BUFFER[2510]	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN80LDU	 899	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define fEM_R0UN81LDU	 BUFFER[2515]	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN81LDU	 900	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define fEM_R0UN82LDU	 BUFFER[2520]	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN82LDU	 901	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define fEM_R0UN83LDU	 BUFFER[2525]	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN83LDU	 902	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define fEM_R0UN84LDU	 BUFFER[2530]	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN84LDU	 903	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define fEM_R0UN85LDU	 BUFFER[2535]	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN85LDU	 904	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define fEM_R0UT20RDU	 BUFFER[2540]	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define idfEM_R0UT20RDU	 905	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define fEM_R0UN25RDU	 BUFFER[2545]	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
#define idfEM_R0UN25RDU	 906	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
#define fEM_R0UN15RDU	 BUFFER[2550]	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
#define idfEM_R0UN15RDU	 907	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
#define fEM_R0UN26RDU	 BUFFER[2555]	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
#define idfEM_R0UN26RDU	 908	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
#define fEM_R0UN27RDU	 BUFFER[2560]	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
#define idfEM_R0UN27RDU	 909	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
#define fEM_R0UN24RDU	 BUFFER[2565]	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN24RDU	 910	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
#define bFirstEnterFlag	 BUFFER[2570]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 911	//(bFirstEnterFlag) 
#define internal2_m191_y0	 BUFFER[2572]	//(internal2_m191_y0) y0
#define idinternal2_m191_y0	 912	//(internal2_m191_y0) y0
#define internal2_m189_y0	 BUFFER[2577]	//(internal2_m189_y0) y0
#define idinternal2_m189_y0	 913	//(internal2_m189_y0) y0
#define internal2_m219_y0	 BUFFER[2582]	//(internal2_m219_y0) state
#define idinternal2_m219_y0	 914	//(internal2_m219_y0) state
#define internal2_m214_y0	 BUFFER[2584]	//(internal2_m214_y0) state
#define idinternal2_m214_y0	 915	//(internal2_m214_y0) state
#define internal2_m203_y1	 BUFFER[2586]	//(internal2_m203_y1) y1 - внутренний параметр
#define idinternal2_m203_y1	 916	//(internal2_m203_y1) y1 - внутренний параметр
#define internal2_m209_y1	 BUFFER[2588]	//(internal2_m209_y1) y1 - внутренний параметр
#define idinternal2_m209_y1	 917	//(internal2_m209_y1) y1 - внутренний параметр
#define internal2_m193_y1	 BUFFER[2590]	//(internal2_m193_y1) y1 - внутренний параметр
#define idinternal2_m193_y1	 918	//(internal2_m193_y1) y1 - внутренний параметр
#define internal2_m200_y1	 BUFFER[2592]	//(internal2_m200_y1) y1 - внутренний параметр
#define idinternal2_m200_y1	 919	//(internal2_m200_y1) y1 - внутренний параметр
#define internal2_m17_Nk0	 BUFFER[2594]	//(internal2_m17_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m17_Nk0	 920	//(internal2_m17_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m17_SetFlag	 BUFFER[2599]	//(internal2_m17_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m17_SetFlag	 921	//(internal2_m17_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m108_Nk0	 BUFFER[2601]	//(internal2_m108_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m108_Nk0	 922	//(internal2_m108_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m108_SetFlag	 BUFFER[2606]	//(internal2_m108_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m108_SetFlag	 923	//(internal2_m108_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m112_Nk0	 BUFFER[2608]	//(internal2_m112_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m112_Nk0	 924	//(internal2_m112_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m112_SetFlag	 BUFFER[2613]	//(internal2_m112_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m112_SetFlag	 925	//(internal2_m112_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m75_Nk0	 BUFFER[2615]	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m75_Nk0	 926	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m75_SetFlag	 BUFFER[2620]	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m75_SetFlag	 927	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m77_Nk0	 BUFFER[2622]	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m77_Nk0	 928	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m77_SetFlag	 BUFFER[2627]	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m77_SetFlag	 929	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m45_Nk0	 BUFFER[2629]	//(internal2_m45_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m45_Nk0	 930	//(internal2_m45_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m45_SetFlag	 BUFFER[2634]	//(internal2_m45_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m45_SetFlag	 931	//(internal2_m45_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m53_Nk0	 BUFFER[2636]	//(internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m53_Nk0	 932	//(internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m53_SetFlag	 BUFFER[2641]	//(internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m53_SetFlag	 933	//(internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m15_Nk0	 BUFFER[2643]	//(internal2_m15_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m15_Nk0	 934	//(internal2_m15_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m15_SetFlag	 BUFFER[2648]	//(internal2_m15_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m15_SetFlag	 935	//(internal2_m15_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal1_m2122_tx	 BUFFER[2650]	//(internal1_m2122_tx) tx - время накопленное сек
#define idinternal1_m2122_tx	 936	//(internal1_m2122_tx) tx - время накопленное сек
#define internal1_m2122_y0	 BUFFER[2655]	//(internal1_m2122_y0) y0
#define idinternal1_m2122_y0	 937	//(internal1_m2122_y0) y0
#define internal1_m2125_tx	 BUFFER[2656]	//(internal1_m2125_tx) tx - время накопленное сек
#define idinternal1_m2125_tx	 938	//(internal1_m2125_tx) tx - время накопленное сек
#define internal1_m2125_y0	 BUFFER[2661]	//(internal1_m2125_y0) y0
#define idinternal1_m2125_y0	 939	//(internal1_m2125_y0) y0
#define internal1_m2124_tx	 BUFFER[2662]	//(internal1_m2124_tx) tx - время накопленное сек
#define idinternal1_m2124_tx	 940	//(internal1_m2124_tx) tx - время накопленное сек
#define internal1_m2124_y0	 BUFFER[2667]	//(internal1_m2124_y0) y0
#define idinternal1_m2124_y0	 941	//(internal1_m2124_y0) y0
#define internal1_m2161_tx	 BUFFER[2668]	//(internal1_m2161_tx) tx - внутренний параметр
#define idinternal1_m2161_tx	 942	//(internal1_m2161_tx) tx - внутренний параметр
#define internal1_m2159_tx	 BUFFER[2673]	//(internal1_m2159_tx) tx - время накопленное сек
#define idinternal1_m2159_tx	 943	//(internal1_m2159_tx) tx - время накопленное сек
#define internal1_m2159_y0	 BUFFER[2678]	//(internal1_m2159_y0) y0
#define idinternal1_m2159_y0	 944	//(internal1_m2159_y0) y0
#define internal1_m2164_q0	 BUFFER[2679]	//(internal1_m2164_q0) q0 - внутренний параметр
#define idinternal1_m2164_q0	 945	//(internal1_m2164_q0) q0 - внутренний параметр
#define internal1_m2131_q0	 BUFFER[2681]	//(internal1_m2131_q0) q0 - внутренний параметр
#define idinternal1_m2131_q0	 946	//(internal1_m2131_q0) q0 - внутренний параметр
#define internal1_m2139_tx	 BUFFER[2683]	//(internal1_m2139_tx) tx - внутренний параметр
#define idinternal1_m2139_tx	 947	//(internal1_m2139_tx) tx - внутренний параметр
#define internal1_m2137_q0	 BUFFER[2688]	//(internal1_m2137_q0) q0 - внутренний параметр
#define idinternal1_m2137_q0	 948	//(internal1_m2137_q0) q0 - внутренний параметр
#define internal1_m2007_tx	 BUFFER[2690]	//(internal1_m2007_tx) tx - время накопленное сек
#define idinternal1_m2007_tx	 949	//(internal1_m2007_tx) tx - время накопленное сек
#define internal1_m2007_y0	 BUFFER[2695]	//(internal1_m2007_y0) y0
#define idinternal1_m2007_y0	 950	//(internal1_m2007_y0) y0
#define internal1_m1999_tx	 BUFFER[2696]	//(internal1_m1999_tx) tx - время накопленное сек
#define idinternal1_m1999_tx	 951	//(internal1_m1999_tx) tx - время накопленное сек
#define internal1_m1999_y0	 BUFFER[2701]	//(internal1_m1999_y0) y0
#define idinternal1_m1999_y0	 952	//(internal1_m1999_y0) y0
#define internal1_m1664_tx	 BUFFER[2702]	//(internal1_m1664_tx) tx - время накопленное сек
#define idinternal1_m1664_tx	 953	//(internal1_m1664_tx) tx - время накопленное сек
#define internal1_m1664_y0	 BUFFER[2707]	//(internal1_m1664_y0) y0
#define idinternal1_m1664_y0	 954	//(internal1_m1664_y0) y0
#define internal1_m1663_tx	 BUFFER[2708]	//(internal1_m1663_tx) tx - время накопленное сек
#define idinternal1_m1663_tx	 955	//(internal1_m1663_tx) tx - время накопленное сек
#define internal1_m1663_y0	 BUFFER[2713]	//(internal1_m1663_y0) y0
#define idinternal1_m1663_y0	 956	//(internal1_m1663_y0) y0
#define internal1_m1703_q0	 BUFFER[2714]	//(internal1_m1703_q0) q0 - внутренний параметр
#define idinternal1_m1703_q0	 957	//(internal1_m1703_q0) q0 - внутренний параметр
#define internal1_m1701_q0	 BUFFER[2716]	//(internal1_m1701_q0) q0 - внутренний параметр
#define idinternal1_m1701_q0	 958	//(internal1_m1701_q0) q0 - внутренний параметр
#define internal1_m1700_q0	 BUFFER[2718]	//(internal1_m1700_q0) q0 - внутренний параметр
#define idinternal1_m1700_q0	 959	//(internal1_m1700_q0) q0 - внутренний параметр
#define internal1_m1728_q0	 BUFFER[2720]	//(internal1_m1728_q0) q0 - внутренний параметр
#define idinternal1_m1728_q0	 960	//(internal1_m1728_q0) q0 - внутренний параметр
#define internal1_m742_tx	 BUFFER[2722]	//(internal1_m742_tx) tx - время накопленное сек
#define idinternal1_m742_tx	 961	//(internal1_m742_tx) tx - время накопленное сек
#define internal1_m742_y0	 BUFFER[2727]	//(internal1_m742_y0) y0
#define idinternal1_m742_y0	 962	//(internal1_m742_y0) y0
#define internal1_m2013_tx	 BUFFER[2728]	//(internal1_m2013_tx) tx - внутренний параметр
#define idinternal1_m2013_tx	 963	//(internal1_m2013_tx) tx - внутренний параметр
#define internal1_m2003_tx	 BUFFER[2733]	//(internal1_m2003_tx) tx - внутренний параметр
#define idinternal1_m2003_tx	 964	//(internal1_m2003_tx) tx - внутренний параметр
#define internal1_m1993_tx	 BUFFER[2738]	//(internal1_m1993_tx) tx - внутренний параметр
#define idinternal1_m1993_tx	 965	//(internal1_m1993_tx) tx - внутренний параметр
#define internal1_m2006_q0	 BUFFER[2743]	//(internal1_m2006_q0) q0 - внутренний параметр
#define idinternal1_m2006_q0	 966	//(internal1_m2006_q0) q0 - внутренний параметр
#define internal1_m1998_q0	 BUFFER[2745]	//(internal1_m1998_q0) q0 - внутренний параметр
#define idinternal1_m1998_q0	 967	//(internal1_m1998_q0) q0 - внутренний параметр
#define internal1_m1969_tx	 BUFFER[2747]	//(internal1_m1969_tx) tx - внутренний параметр
#define idinternal1_m1969_tx	 968	//(internal1_m1969_tx) tx - внутренний параметр
#define internal1_m1980_tx	 BUFFER[2752]	//(internal1_m1980_tx) tx - внутренний параметр
#define idinternal1_m1980_tx	 969	//(internal1_m1980_tx) tx - внутренний параметр
#define internal1_m1965_tx	 BUFFER[2757]	//(internal1_m1965_tx) tx - внутренний параметр
#define idinternal1_m1965_tx	 970	//(internal1_m1965_tx) tx - внутренний параметр
#define internal1_m1972_q0	 BUFFER[2762]	//(internal1_m1972_q0) q0 - внутренний параметр
#define idinternal1_m1972_q0	 971	//(internal1_m1972_q0) q0 - внутренний параметр
#define internal1_m1984_q0	 BUFFER[2764]	//(internal1_m1984_q0) q0 - внутренний параметр
#define idinternal1_m1984_q0	 972	//(internal1_m1984_q0) q0 - внутренний параметр
#define internal1_m1943_tx	 BUFFER[2766]	//(internal1_m1943_tx) tx - внутренний параметр
#define idinternal1_m1943_tx	 973	//(internal1_m1943_tx) tx - внутренний параметр
#define internal1_m51_tx	 BUFFER[2771]	//(internal1_m51_tx) tx - внутренний параметр
#define idinternal1_m51_tx	 974	//(internal1_m51_tx) tx - внутренний параметр
#define internal1_m327_tx	 BUFFER[2776]	//(internal1_m327_tx) tx - внутренний параметр
#define idinternal1_m327_tx	 975	//(internal1_m327_tx) tx - внутренний параметр
#define internal1_m285_tx	 BUFFER[2781]	//(internal1_m285_tx) tx - внутренний параметр
#define idinternal1_m285_tx	 976	//(internal1_m285_tx) tx - внутренний параметр
#define internal1_m743_tx	 BUFFER[2786]	//(internal1_m743_tx) tx - внутренний параметр
#define idinternal1_m743_tx	 977	//(internal1_m743_tx) tx - внутренний параметр
#define internal1_m1419_tx	 BUFFER[2791]	//(internal1_m1419_tx) tx - внутренний параметр
#define idinternal1_m1419_tx	 978	//(internal1_m1419_tx) tx - внутренний параметр
#define internal1_m110_tx	 BUFFER[2796]	//(internal1_m110_tx) tx - внутренний параметр
#define idinternal1_m110_tx	 979	//(internal1_m110_tx) tx - внутренний параметр
#define internal1_m112_tx	 BUFFER[2801]	//(internal1_m112_tx) tx - внутренний параметр
#define idinternal1_m112_tx	 980	//(internal1_m112_tx) tx - внутренний параметр
#define internal1_m117_tx	 BUFFER[2806]	//(internal1_m117_tx) tx - внутренний параметр
#define idinternal1_m117_tx	 981	//(internal1_m117_tx) tx - внутренний параметр
#define internal1_m21_tx	 BUFFER[2811]	//(internal1_m21_tx) tx - внутренний параметр
#define idinternal1_m21_tx	 982	//(internal1_m21_tx) tx - внутренний параметр
#define internal1_m13_tx	 BUFFER[2816]	//(internal1_m13_tx) tx - внутренний параметр
#define idinternal1_m13_tx	 983	//(internal1_m13_tx) tx - внутренний параметр
#define internal1_m1951_tx	 BUFFER[2821]	//(internal1_m1951_tx) tx - внутренний параметр
#define idinternal1_m1951_tx	 984	//(internal1_m1951_tx) tx - внутренний параметр
#define internal1_m1938_tx	 BUFFER[2826]	//(internal1_m1938_tx) tx - внутренний параметр
#define idinternal1_m1938_tx	 985	//(internal1_m1938_tx) tx - внутренний параметр
#define internal1_m2036_tx	 BUFFER[2831]	//(internal1_m2036_tx) tx - внутренний параметр
#define idinternal1_m2036_tx	 986	//(internal1_m2036_tx) tx - внутренний параметр
#define internal1_m2039_tx	 BUFFER[2836]	//(internal1_m2039_tx) tx - внутренний параметр
#define idinternal1_m2039_tx	 987	//(internal1_m2039_tx) tx - внутренний параметр
#define internal1_m1865_tx	 BUFFER[2841]	//(internal1_m1865_tx) tx - внутренний параметр
#define idinternal1_m1865_tx	 988	//(internal1_m1865_tx) tx - внутренний параметр
#define internal1_m76_tx	 BUFFER[2846]	//(internal1_m76_tx) tx - внутренний параметр
#define idinternal1_m76_tx	 989	//(internal1_m76_tx) tx - внутренний параметр
#define internal1_m298_tx	 BUFFER[2851]	//(internal1_m298_tx) tx - время накопленное сек
#define idinternal1_m298_tx	 990	//(internal1_m298_tx) tx - время накопленное сек
#define internal1_m298_y0	 BUFFER[2856]	//(internal1_m298_y0) y0
#define idinternal1_m298_y0	 991	//(internal1_m298_y0) y0
#define internal1_m1859_tx	 BUFFER[2857]	//(internal1_m1859_tx) tx - время накопленное сек
#define idinternal1_m1859_tx	 992	//(internal1_m1859_tx) tx - время накопленное сек
#define internal1_m1859_y0	 BUFFER[2862]	//(internal1_m1859_y0) y0
#define idinternal1_m1859_y0	 993	//(internal1_m1859_y0) y0
#define internal1_m1857_tx	 BUFFER[2863]	//(internal1_m1857_tx) tx - время накопленное сек
#define idinternal1_m1857_tx	 994	//(internal1_m1857_tx) tx - время накопленное сек
#define internal1_m1857_y0	 BUFFER[2868]	//(internal1_m1857_y0) y0
#define idinternal1_m1857_y0	 995	//(internal1_m1857_y0) y0
#define internal1_m1846_tx	 BUFFER[2869]	//(internal1_m1846_tx) tx - время накопленное сек
#define idinternal1_m1846_tx	 996	//(internal1_m1846_tx) tx - время накопленное сек
#define internal1_m1846_y0	 BUFFER[2874]	//(internal1_m1846_y0) y0
#define idinternal1_m1846_y0	 997	//(internal1_m1846_y0) y0
#define internal1_m1866_q0	 BUFFER[2875]	//(internal1_m1866_q0) q0 - внутренний параметр
#define idinternal1_m1866_q0	 998	//(internal1_m1866_q0) q0 - внутренний параметр
#define internal1_m1439_q0	 BUFFER[2880]	//(internal1_m1439_q0) q0 - внутренний параметр
#define idinternal1_m1439_q0	 999	//(internal1_m1439_q0) q0 - внутренний параметр
#define internal1_m1476_q0	 BUFFER[2885]	//(internal1_m1476_q0) q0 - внутренний параметр
#define idinternal1_m1476_q0	 1000	//(internal1_m1476_q0) q0 - внутренний параметр
#define internal1_m1479_q0	 BUFFER[2890]	//(internal1_m1479_q0) q0 - внутренний параметр
#define idinternal1_m1479_q0	 1001	//(internal1_m1479_q0) q0 - внутренний параметр
#define internal1_m1905_q0	 BUFFER[2895]	//(internal1_m1905_q0) q0 - внутренний параметр
#define idinternal1_m1905_q0	 1002	//(internal1_m1905_q0) q0 - внутренний параметр
#define internal1_m1882_tx	 BUFFER[2900]	//(internal1_m1882_tx) tx - время накопленное сек
#define idinternal1_m1882_tx	 1003	//(internal1_m1882_tx) tx - время накопленное сек
#define internal1_m1882_y0	 BUFFER[2905]	//(internal1_m1882_y0) y0
#define idinternal1_m1882_y0	 1004	//(internal1_m1882_y0) y0
#define internal1_m1898_tx	 BUFFER[2906]	//(internal1_m1898_tx) tx - время накопленное сек
#define idinternal1_m1898_tx	 1005	//(internal1_m1898_tx) tx - время накопленное сек
#define internal1_m1898_y0	 BUFFER[2911]	//(internal1_m1898_y0) y0
#define idinternal1_m1898_y0	 1006	//(internal1_m1898_y0) y0
#define internal1_m1895_tx	 BUFFER[2912]	//(internal1_m1895_tx) tx - время накопленное сек
#define idinternal1_m1895_tx	 1007	//(internal1_m1895_tx) tx - время накопленное сек
#define internal1_m1895_y0	 BUFFER[2917]	//(internal1_m1895_y0) y0
#define idinternal1_m1895_y0	 1008	//(internal1_m1895_y0) y0
#define internal1_m2026_tx	 BUFFER[2918]	//(internal1_m2026_tx) tx - время накопленное сек
#define idinternal1_m2026_tx	 1009	//(internal1_m2026_tx) tx - время накопленное сек
#define internal1_m2026_y0	 BUFFER[2923]	//(internal1_m2026_y0) y0
#define idinternal1_m2026_y0	 1010	//(internal1_m2026_y0) y0
#define internal1_m2035_tx	 BUFFER[2924]	//(internal1_m2035_tx) tx - время накопленное сек
#define idinternal1_m2035_tx	 1011	//(internal1_m2035_tx) tx - время накопленное сек
#define internal1_m2035_y0	 BUFFER[2929]	//(internal1_m2035_y0) y0
#define idinternal1_m2035_y0	 1012	//(internal1_m2035_y0) y0
#define internal1_m1796_tx	 BUFFER[2930]	//(internal1_m1796_tx) tx - время накопленное сек
#define idinternal1_m1796_tx	 1013	//(internal1_m1796_tx) tx - время накопленное сек
#define internal1_m1796_y0	 BUFFER[2935]	//(internal1_m1796_y0) y0
#define idinternal1_m1796_y0	 1014	//(internal1_m1796_y0) y0
#define internal1_m1795_tx	 BUFFER[2936]	//(internal1_m1795_tx) tx - время накопленное сек
#define idinternal1_m1795_tx	 1015	//(internal1_m1795_tx) tx - время накопленное сек
#define internal1_m1795_y0	 BUFFER[2941]	//(internal1_m1795_y0) y0
#define idinternal1_m1795_y0	 1016	//(internal1_m1795_y0) y0
#define internal1_m1794_tx	 BUFFER[2942]	//(internal1_m1794_tx) tx - время накопленное сек
#define idinternal1_m1794_tx	 1017	//(internal1_m1794_tx) tx - время накопленное сек
#define internal1_m1794_y0	 BUFFER[2947]	//(internal1_m1794_y0) y0
#define idinternal1_m1794_y0	 1018	//(internal1_m1794_y0) y0
#define internal1_m1793_tx	 BUFFER[2948]	//(internal1_m1793_tx) tx - время накопленное сек
#define idinternal1_m1793_tx	 1019	//(internal1_m1793_tx) tx - время накопленное сек
#define internal1_m1793_y0	 BUFFER[2953]	//(internal1_m1793_y0) y0
#define idinternal1_m1793_y0	 1020	//(internal1_m1793_y0) y0
#define internal1_m1490_tx	 BUFFER[2954]	//(internal1_m1490_tx) tx - время накопленное сек
#define idinternal1_m1490_tx	 1021	//(internal1_m1490_tx) tx - время накопленное сек
#define internal1_m1490_y0	 BUFFER[2959]	//(internal1_m1490_y0) y0
#define idinternal1_m1490_y0	 1022	//(internal1_m1490_y0) y0
#define internal1_m1484_tx	 BUFFER[2960]	//(internal1_m1484_tx) tx - время накопленное сек
#define idinternal1_m1484_tx	 1023	//(internal1_m1484_tx) tx - время накопленное сек
#define internal1_m1484_y0	 BUFFER[2965]	//(internal1_m1484_y0) y0
#define idinternal1_m1484_y0	 1024	//(internal1_m1484_y0) y0
#define internal1_m1435_tx	 BUFFER[2966]	//(internal1_m1435_tx) tx - время накопленное сек
#define idinternal1_m1435_tx	 1025	//(internal1_m1435_tx) tx - время накопленное сек
#define internal1_m1435_y0	 BUFFER[2971]	//(internal1_m1435_y0) y0
#define idinternal1_m1435_y0	 1026	//(internal1_m1435_y0) y0
#define internal1_m826_tx	 BUFFER[2972]	//(internal1_m826_tx) tx - время накопленное сек
#define idinternal1_m826_tx	 1027	//(internal1_m826_tx) tx - время накопленное сек
#define internal1_m826_y0	 BUFFER[2977]	//(internal1_m826_y0) y0
#define idinternal1_m826_y0	 1028	//(internal1_m826_y0) y0
#define internal1_m825_tx	 BUFFER[2978]	//(internal1_m825_tx) tx - время накопленное сек
#define idinternal1_m825_tx	 1029	//(internal1_m825_tx) tx - время накопленное сек
#define internal1_m825_y0	 BUFFER[2983]	//(internal1_m825_y0) y0
#define idinternal1_m825_y0	 1030	//(internal1_m825_y0) y0
#define internal1_m832_tx	 BUFFER[2984]	//(internal1_m832_tx) tx - время накопленное сек
#define idinternal1_m832_tx	 1031	//(internal1_m832_tx) tx - время накопленное сек
#define internal1_m832_y0	 BUFFER[2989]	//(internal1_m832_y0) y0
#define idinternal1_m832_y0	 1032	//(internal1_m832_y0) y0
#define internal1_m182_tx	 BUFFER[2990]	//(internal1_m182_tx) tx - время накопленное сек
#define idinternal1_m182_tx	 1033	//(internal1_m182_tx) tx - время накопленное сек
#define internal1_m182_y0	 BUFFER[2995]	//(internal1_m182_y0) y0
#define idinternal1_m182_y0	 1034	//(internal1_m182_y0) y0
#define internal1_m187_tx	 BUFFER[2996]	//(internal1_m187_tx) tx - время накопленное сек
#define idinternal1_m187_tx	 1035	//(internal1_m187_tx) tx - время накопленное сек
#define internal1_m187_y0	 BUFFER[3001]	//(internal1_m187_y0) y0
#define idinternal1_m187_y0	 1036	//(internal1_m187_y0) y0
#define internal1_m193_tx	 BUFFER[3002]	//(internal1_m193_tx) tx - время накопленное сек
#define idinternal1_m193_tx	 1037	//(internal1_m193_tx) tx - время накопленное сек
#define internal1_m193_y0	 BUFFER[3007]	//(internal1_m193_y0) y0
#define idinternal1_m193_y0	 1038	//(internal1_m193_y0) y0
#define internal1_m519_tx	 BUFFER[3008]	//(internal1_m519_tx) tx - время накопленное сек
#define idinternal1_m519_tx	 1039	//(internal1_m519_tx) tx - время накопленное сек
#define internal1_m519_y0	 BUFFER[3013]	//(internal1_m519_y0) y0
#define idinternal1_m519_y0	 1040	//(internal1_m519_y0) y0
#define internal1_m2063_tx	 BUFFER[3014]	//(internal1_m2063_tx) tx - внутренний параметр
#define idinternal1_m2063_tx	 1041	//(internal1_m2063_tx) tx - внутренний параметр
#define internal1_m1173_tx	 BUFFER[3019]	//(internal1_m1173_tx) tx - внутренний параметр
#define idinternal1_m1173_tx	 1042	//(internal1_m1173_tx) tx - внутренний параметр
#define internal1_m1605_tx	 BUFFER[3024]	//(internal1_m1605_tx) tx - время накопленное сек
#define idinternal1_m1605_tx	 1043	//(internal1_m1605_tx) tx - время накопленное сек
#define internal1_m1605_y0	 BUFFER[3029]	//(internal1_m1605_y0) y0
#define idinternal1_m1605_y0	 1044	//(internal1_m1605_y0) y0
#define internal1_m1139_tx	 BUFFER[3030]	//(internal1_m1139_tx) tx - время накопленное сек
#define idinternal1_m1139_tx	 1045	//(internal1_m1139_tx) tx - время накопленное сек
#define internal1_m1139_y0	 BUFFER[3035]	//(internal1_m1139_y0) y0
#define idinternal1_m1139_y0	 1046	//(internal1_m1139_y0) y0
#define internal1_m1326_tx	 BUFFER[3036]	//(internal1_m1326_tx) tx - время накопленное сек
#define idinternal1_m1326_tx	 1047	//(internal1_m1326_tx) tx - время накопленное сек
#define internal1_m1326_y0	 BUFFER[3041]	//(internal1_m1326_y0) y0
#define idinternal1_m1326_y0	 1048	//(internal1_m1326_y0) y0
#define internal1_m926_tx	 BUFFER[3042]	//(internal1_m926_tx) tx - время накопленное сек
#define idinternal1_m926_tx	 1049	//(internal1_m926_tx) tx - время накопленное сек
#define internal1_m926_y0	 BUFFER[3047]	//(internal1_m926_y0) y0
#define idinternal1_m926_y0	 1050	//(internal1_m926_y0) y0
#define internal1_m1233_tx	 BUFFER[3048]	//(internal1_m1233_tx) tx - время накопленное сек
#define idinternal1_m1233_tx	 1051	//(internal1_m1233_tx) tx - время накопленное сек
#define internal1_m1233_y0	 BUFFER[3053]	//(internal1_m1233_y0) y0
#define idinternal1_m1233_y0	 1052	//(internal1_m1233_y0) y0
#define internal1_m1083_q0	 BUFFER[3054]	//(internal1_m1083_q0) q0 - внутренний параметр
#define idinternal1_m1083_q0	 1053	//(internal1_m1083_q0) q0 - внутренний параметр
#define internal1_m1081_q0	 BUFFER[3056]	//(internal1_m1081_q0) q0 - внутренний параметр
#define idinternal1_m1081_q0	 1054	//(internal1_m1081_q0) q0 - внутренний параметр
#define internal1_m1080_q0	 BUFFER[3058]	//(internal1_m1080_q0) q0 - внутренний параметр
#define idinternal1_m1080_q0	 1055	//(internal1_m1080_q0) q0 - внутренний параметр
#define internal1_m1078_q0	 BUFFER[3060]	//(internal1_m1078_q0) q0 - внутренний параметр
#define idinternal1_m1078_q0	 1056	//(internal1_m1078_q0) q0 - внутренний параметр
#define internal1_m1077_q0	 BUFFER[3062]	//(internal1_m1077_q0) q0 - внутренний параметр
#define idinternal1_m1077_q0	 1057	//(internal1_m1077_q0) q0 - внутренний параметр
#define internal1_m1075_q0	 BUFFER[3064]	//(internal1_m1075_q0) q0 - внутренний параметр
#define idinternal1_m1075_q0	 1058	//(internal1_m1075_q0) q0 - внутренний параметр
#define internal1_m1074_q0	 BUFFER[3066]	//(internal1_m1074_q0) q0 - внутренний параметр
#define idinternal1_m1074_q0	 1059	//(internal1_m1074_q0) q0 - внутренний параметр
#define internal1_m1072_q0	 BUFFER[3068]	//(internal1_m1072_q0) q0 - внутренний параметр
#define idinternal1_m1072_q0	 1060	//(internal1_m1072_q0) q0 - внутренний параметр
#define internal1_m1071_q0	 BUFFER[3070]	//(internal1_m1071_q0) q0 - внутренний параметр
#define idinternal1_m1071_q0	 1061	//(internal1_m1071_q0) q0 - внутренний параметр
#define internal1_m52_x0	 BUFFER[3072]	//(internal1_m52_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m52_x0	 1062	//(internal1_m52_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m991_q0	 BUFFER[3074]	//(internal1_m991_q0) q0 - внутренний параметр
#define idinternal1_m991_q0	 1063	//(internal1_m991_q0) q0 - внутренний параметр
#define internal1_m1427_x0	 BUFFER[3076]	//(internal1_m1427_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1427_x0	 1064	//(internal1_m1427_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1471_x0	 BUFFER[3078]	//(internal1_m1471_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1471_x0	 1065	//(internal1_m1471_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1467_x0	 BUFFER[3080]	//(internal1_m1467_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1467_x0	 1066	//(internal1_m1467_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1874_x0	 BUFFER[3082]	//(internal1_m1874_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1874_x0	 1067	//(internal1_m1874_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1839_x0	 BUFFER[3084]	//(internal1_m1839_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1839_x0	 1068	//(internal1_m1839_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1030_q0	 BUFFER[3086]	//(internal1_m1030_q0) q0 - внутренний параметр
#define idinternal1_m1030_q0	 1069	//(internal1_m1030_q0) q0 - внутренний параметр
#define internal1_m1042_q0	 BUFFER[3088]	//(internal1_m1042_q0) q0 - внутренний параметр
#define idinternal1_m1042_q0	 1070	//(internal1_m1042_q0) q0 - внутренний параметр
#define internal1_m1054_q0	 BUFFER[3090]	//(internal1_m1054_q0) q0 - внутренний параметр
#define idinternal1_m1054_q0	 1071	//(internal1_m1054_q0) q0 - внутренний параметр
#define internal1_m1063_q0	 BUFFER[3092]	//(internal1_m1063_q0) q0 - внутренний параметр
#define idinternal1_m1063_q0	 1072	//(internal1_m1063_q0) q0 - внутренний параметр
#define internal1_m1041_q0	 BUFFER[3094]	//(internal1_m1041_q0) q0 - внутренний параметр
#define idinternal1_m1041_q0	 1073	//(internal1_m1041_q0) q0 - внутренний параметр
#define internal1_m1056_q0	 BUFFER[3096]	//(internal1_m1056_q0) q0 - внутренний параметр
#define idinternal1_m1056_q0	 1074	//(internal1_m1056_q0) q0 - внутренний параметр
#define internal1_m1932_q0	 BUFFER[3098]	//(internal1_m1932_q0) q0 - внутренний параметр
#define idinternal1_m1932_q0	 1075	//(internal1_m1932_q0) q0 - внутренний параметр
#define internal1_m1931_q0	 BUFFER[3100]	//(internal1_m1931_q0) q0 - внутренний параметр
#define idinternal1_m1931_q0	 1076	//(internal1_m1931_q0) q0 - внутренний параметр
#define internal1_m315_Step	 BUFFER[3102]	//(internal1_m315_Step)  - текущий шаг программы
#define idinternal1_m315_Step	 1077	//(internal1_m315_Step)  - текущий шаг программы
#define internal1_m315_rz	 BUFFER[3105]	//(internal1_m315_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m315_rz	 1078	//(internal1_m315_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m315_TimS	 BUFFER[3115]	//(internal1_m315_TimS) Время от старта программы
#define idinternal1_m315_TimS	 1079	//(internal1_m315_TimS) Время от старта программы
#define internal1_m315_FinPr0	 BUFFER[3120]	//(internal1_m315_FinPr0) FinPr - конец программы
#define idinternal1_m315_FinPr0	 1080	//(internal1_m315_FinPr0) FinPr - конец программы
#define internal1_m315_ErrPr0	 BUFFER[3122]	//(internal1_m315_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m315_ErrPr0	 1081	//(internal1_m315_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m315_sbINI0	 BUFFER[3124]	//(internal1_m315_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m315_sbINI0	 1082	//(internal1_m315_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m315_sbVuIS0	 BUFFER[3126]	//(internal1_m315_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m315_sbVuIS0	 1083	//(internal1_m315_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m315_sb2UR0	 BUFFER[3128]	//(internal1_m315_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m315_sb2UR0	 1084	//(internal1_m315_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m315_sbNupIS0	 BUFFER[3130]	//(internal1_m315_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m315_sbNupIS0	 1085	//(internal1_m315_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m315_sbVuRB0	 BUFFER[3132]	//(internal1_m315_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m315_sbVuRB0	 1086	//(internal1_m315_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m315_MyFirstEnterFlag	 BUFFER[3134]	//(internal1_m315_MyFirstEnterFlag)  
#define idinternal1_m315_MyFirstEnterFlag	 1087	//(internal1_m315_MyFirstEnterFlag)  
#define internal1_m323_x0	 BUFFER[3136]	//(internal1_m323_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m323_x0	 1088	//(internal1_m323_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m284_TimS	 BUFFER[3141]	//(internal1_m284_TimS) Время старта
#define idinternal1_m284_TimS	 1089	//(internal1_m284_TimS) Время старта
#define internal1_m261_Step	 BUFFER[3146]	//(internal1_m261_Step)  - текущий шаг программы
#define idinternal1_m261_Step	 1090	//(internal1_m261_Step)  - текущий шаг программы
#define internal1_m261_rz	 BUFFER[3149]	//(internal1_m261_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m261_rz	 1091	//(internal1_m261_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m261_TimS	 BUFFER[3159]	//(internal1_m261_TimS) Время от старта программы
#define idinternal1_m261_TimS	 1092	//(internal1_m261_TimS) Время от старта программы
#define internal1_m261_FinPr0	 BUFFER[3164]	//(internal1_m261_FinPr0) FinPr - конец программы
#define idinternal1_m261_FinPr0	 1093	//(internal1_m261_FinPr0) FinPr - конец программы
#define internal1_m261_ErrPr0	 BUFFER[3166]	//(internal1_m261_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m261_ErrPr0	 1094	//(internal1_m261_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m261_sbINI0	 BUFFER[3168]	//(internal1_m261_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m261_sbINI0	 1095	//(internal1_m261_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m261_sbVuIS0	 BUFFER[3170]	//(internal1_m261_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m261_sbVuIS0	 1096	//(internal1_m261_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m261_sb2UR0	 BUFFER[3172]	//(internal1_m261_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m261_sb2UR0	 1097	//(internal1_m261_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m261_sbNupIS0	 BUFFER[3174]	//(internal1_m261_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m261_sbNupIS0	 1098	//(internal1_m261_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m261_sbVuRB0	 BUFFER[3176]	//(internal1_m261_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m261_sbVuRB0	 1099	//(internal1_m261_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m261_MyFirstEnterFlag	 BUFFER[3178]	//(internal1_m261_MyFirstEnterFlag)  
#define idinternal1_m261_MyFirstEnterFlag	 1100	//(internal1_m261_MyFirstEnterFlag)  
#define internal1_m1402_q0	 BUFFER[3180]	//(internal1_m1402_q0) q0 - внутренний параметр
#define idinternal1_m1402_q0	 1101	//(internal1_m1402_q0) q0 - внутренний параметр
#define internal1_m1403_Step	 BUFFER[3182]	//(internal1_m1403_Step)  - текущий шаг программы
#define idinternal1_m1403_Step	 1102	//(internal1_m1403_Step)  - текущий шаг программы
#define internal1_m1403_rz	 BUFFER[3185]	//(internal1_m1403_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m1403_rz	 1103	//(internal1_m1403_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m1403_TimS	 BUFFER[3191]	//(internal1_m1403_TimS) Время от старта программы
#define idinternal1_m1403_TimS	 1104	//(internal1_m1403_TimS) Время от старта программы
#define internal1_m1403_FinPr0	 BUFFER[3196]	//(internal1_m1403_FinPr0) FinPr - конец программы
#define idinternal1_m1403_FinPr0	 1105	//(internal1_m1403_FinPr0) FinPr - конец программы
#define internal1_m1403_ErrPr0	 BUFFER[3198]	//(internal1_m1403_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m1403_ErrPr0	 1106	//(internal1_m1403_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m1403_sbINI0	 BUFFER[3200]	//(internal1_m1403_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m1403_sbINI0	 1107	//(internal1_m1403_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m1403_sbVuIS0	 BUFFER[3202]	//(internal1_m1403_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m1403_sbVuIS0	 1108	//(internal1_m1403_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m1403_sb2UR0	 BUFFER[3204]	//(internal1_m1403_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m1403_sb2UR0	 1109	//(internal1_m1403_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m1403_sbNupIS0	 BUFFER[3206]	//(internal1_m1403_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m1403_sbNupIS0	 1110	//(internal1_m1403_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m1403_sbVuRB0	 BUFFER[3208]	//(internal1_m1403_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m1403_sbVuRB0	 1111	//(internal1_m1403_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m1403_MyFirstEnterFlag	 BUFFER[3210]	//(internal1_m1403_MyFirstEnterFlag)  
#define idinternal1_m1403_MyFirstEnterFlag	 1112	//(internal1_m1403_MyFirstEnterFlag)  
#define internal1_m1025_q0	 BUFFER[3212]	//(internal1_m1025_q0) q0 - внутренний параметр
#define idinternal1_m1025_q0	 1113	//(internal1_m1025_q0) q0 - внутренний параметр
#define internal1_m1022_q0	 BUFFER[3214]	//(internal1_m1022_q0) q0 - внутренний параметр
#define idinternal1_m1022_q0	 1114	//(internal1_m1022_q0) q0 - внутренний параметр
#define internal1_m1024_q0	 BUFFER[3216]	//(internal1_m1024_q0) q0 - внутренний параметр
#define idinternal1_m1024_q0	 1115	//(internal1_m1024_q0) q0 - внутренний параметр
#define internal1_m1019_q0	 BUFFER[3218]	//(internal1_m1019_q0) q0 - внутренний параметр
#define idinternal1_m1019_q0	 1116	//(internal1_m1019_q0) q0 - внутренний параметр
#define internal1_m744_q0	 BUFFER[3220]	//(internal1_m744_q0) q0 - внутренний параметр
#define idinternal1_m744_q0	 1117	//(internal1_m744_q0) q0 - внутренний параметр
#define internal1_m2096_DvUp0	 BUFFER[3222]	//(internal1_m2096_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2096_DvUp0	 1118	//(internal1_m2096_DvUp0) - есть команда на движение вперёд
#define internal1_m2096_DvDw0	 BUFFER[3223]	//(internal1_m2096_DvDw0) - есть команда на движение назад
#define idinternal1_m2096_DvDw0	 1119	//(internal1_m2096_DvDw0) - есть команда на движение назад
#define internal1_m2096_FDvUp0	 BUFFER[3224]	//(internal1_m2096_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2096_FDvUp0	 1120	//(internal1_m2096_FDvUp0) - есть команда на движение вперёд
#define internal1_m2096_FDvDw0	 BUFFER[3225]	//(internal1_m2096_FDvDw0) - есть команда на движение назад
#define idinternal1_m2096_FDvDw0	 1121	//(internal1_m2096_FDvDw0) - есть команда на движение назад
#define internal1_m2096_BlDv0	 BUFFER[3226]	//(internal1_m2096_BlDv0) - была блокировка
#define idinternal1_m2096_BlDv0	 1122	//(internal1_m2096_BlDv0) - была блокировка
#define internal1_m2096_Pkv0	 BUFFER[3227]	//(internal1_m2096_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2096_Pkv0	 1123	//(internal1_m2096_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2096_Pkav0	 BUFFER[3228]	//(internal1_m2096_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2096_Pkav0	 1124	//(internal1_m2096_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2096_Zkv0	 BUFFER[3229]	//(internal1_m2096_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2096_Zkv0	 1125	//(internal1_m2096_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2096_Zkav0	 BUFFER[3230]	//(internal1_m2096_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2096_Zkav0	 1126	//(internal1_m2096_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2096_txNm	 BUFFER[3231]	//(internal1_m2096_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2096_txNm	 1127	//(internal1_m2096_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2096_txSm	 BUFFER[3236]	//(internal1_m2096_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2096_txSm	 1128	//(internal1_m2096_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2096_txHr	 BUFFER[3241]	//(internal1_m2096_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2096_txHr	 1129	//(internal1_m2096_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2096_txLd	 BUFFER[3246]	//(internal1_m2096_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2096_txLd	 1130	//(internal1_m2096_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2096_fef	 BUFFER[3251]	//(internal1_m2096_fef) fef
#define idinternal1_m2096_fef	 1131	//(internal1_m2096_fef) fef
#define internal1_m2091_DvUp0	 BUFFER[3252]	//(internal1_m2091_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2091_DvUp0	 1132	//(internal1_m2091_DvUp0) - есть команда на движение вперёд
#define internal1_m2091_DvDw0	 BUFFER[3253]	//(internal1_m2091_DvDw0) - есть команда на движение назад
#define idinternal1_m2091_DvDw0	 1133	//(internal1_m2091_DvDw0) - есть команда на движение назад
#define internal1_m2091_FDvUp0	 BUFFER[3254]	//(internal1_m2091_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2091_FDvUp0	 1134	//(internal1_m2091_FDvUp0) - есть команда на движение вперёд
#define internal1_m2091_FDvDw0	 BUFFER[3255]	//(internal1_m2091_FDvDw0) - есть команда на движение назад
#define idinternal1_m2091_FDvDw0	 1135	//(internal1_m2091_FDvDw0) - есть команда на движение назад
#define internal1_m2091_BlDv0	 BUFFER[3256]	//(internal1_m2091_BlDv0) - была блокировка
#define idinternal1_m2091_BlDv0	 1136	//(internal1_m2091_BlDv0) - была блокировка
#define internal1_m2091_Pkv0	 BUFFER[3257]	//(internal1_m2091_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2091_Pkv0	 1137	//(internal1_m2091_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2091_Pkav0	 BUFFER[3258]	//(internal1_m2091_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2091_Pkav0	 1138	//(internal1_m2091_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2091_Zkv0	 BUFFER[3259]	//(internal1_m2091_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2091_Zkv0	 1139	//(internal1_m2091_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2091_Zkav0	 BUFFER[3260]	//(internal1_m2091_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2091_Zkav0	 1140	//(internal1_m2091_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2091_txNm	 BUFFER[3261]	//(internal1_m2091_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2091_txNm	 1141	//(internal1_m2091_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2091_txSm	 BUFFER[3266]	//(internal1_m2091_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2091_txSm	 1142	//(internal1_m2091_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2091_txHr	 BUFFER[3271]	//(internal1_m2091_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2091_txHr	 1143	//(internal1_m2091_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2091_txLd	 BUFFER[3276]	//(internal1_m2091_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2091_txLd	 1144	//(internal1_m2091_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2091_fef	 BUFFER[3281]	//(internal1_m2091_fef) fef
#define idinternal1_m2091_fef	 1145	//(internal1_m2091_fef) fef
#define internal1_m325_q0	 BUFFER[3282]	//(internal1_m325_q0) q0 - внутренний параметр
#define idinternal1_m325_q0	 1146	//(internal1_m325_q0) q0 - внутренний параметр
#define internal1_m321_q0	 BUFFER[3284]	//(internal1_m321_q0) q0 - внутренний параметр
#define idinternal1_m321_q0	 1147	//(internal1_m321_q0) q0 - внутренний параметр
#define internal1_m280_q0	 BUFFER[3286]	//(internal1_m280_q0) q0 - внутренний параметр
#define idinternal1_m280_q0	 1148	//(internal1_m280_q0) q0 - внутренний параметр
#define internal1_m279_x0	 BUFFER[3288]	//(internal1_m279_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m279_x0	 1149	//(internal1_m279_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1861_q0	 BUFFER[3293]	//(internal1_m1861_q0) q0 - внутренний параметр
#define idinternal1_m1861_q0	 1150	//(internal1_m1861_q0) q0 - внутренний параметр
#define internal1_m1849_q0	 BUFFER[3295]	//(internal1_m1849_q0) q0 - внутренний параметр
#define idinternal1_m1849_q0	 1151	//(internal1_m1849_q0) q0 - внутренний параметр
#define internal1_m1840_q0	 BUFFER[3297]	//(internal1_m1840_q0) q0 - внутренний параметр
#define idinternal1_m1840_q0	 1152	//(internal1_m1840_q0) q0 - внутренний параметр
#define internal1_m1915_q0	 BUFFER[3299]	//(internal1_m1915_q0) q0 - внутренний параметр
#define idinternal1_m1915_q0	 1153	//(internal1_m1915_q0) q0 - внутренний параметр
#define internal1_m1885_q0	 BUFFER[3301]	//(internal1_m1885_q0) q0 - внутренний параметр
#define idinternal1_m1885_q0	 1154	//(internal1_m1885_q0) q0 - внутренний параметр
#define internal1_m1875_q0	 BUFFER[3303]	//(internal1_m1875_q0) q0 - внутренний параметр
#define idinternal1_m1875_q0	 1155	//(internal1_m1875_q0) q0 - внутренний параметр
#define internal1_m1455_q0	 BUFFER[3305]	//(internal1_m1455_q0) q0 - внутренний параметр
#define idinternal1_m1455_q0	 1156	//(internal1_m1455_q0) q0 - внутренний параметр
#define internal1_m1442_x0	 BUFFER[3307]	//(internal1_m1442_x0) был приход сигнала x1
#define idinternal1_m1442_x0	 1157	//(internal1_m1442_x0) был приход сигнала x1
#define internal1_m1442_y0	 BUFFER[3309]	//(internal1_m1442_y0) интервал между сигналами х1 и х2
#define idinternal1_m1442_y0	 1158	//(internal1_m1442_y0) интервал между сигналами х1 и х2
#define internal1_m1438_q0	 BUFFER[3314]	//(internal1_m1438_q0) q0 - внутренний параметр
#define idinternal1_m1438_q0	 1159	//(internal1_m1438_q0) q0 - внутренний параметр
#define internal1_m1428_q0	 BUFFER[3316]	//(internal1_m1428_q0) q0 - внутренний параметр
#define idinternal1_m1428_q0	 1160	//(internal1_m1428_q0) q0 - внутренний параметр
#define internal1_m1487_q0	 BUFFER[3318]	//(internal1_m1487_q0) q0 - внутренний параметр
#define idinternal1_m1487_q0	 1161	//(internal1_m1487_q0) q0 - внутренний параметр
#define internal1_m1507_q0	 BUFFER[3320]	//(internal1_m1507_q0) q0 - внутренний параметр
#define idinternal1_m1507_q0	 1162	//(internal1_m1507_q0) q0 - внутренний параметр
#define internal1_m1473_q0	 BUFFER[3322]	//(internal1_m1473_q0) q0 - внутренний параметр
#define idinternal1_m1473_q0	 1163	//(internal1_m1473_q0) q0 - внутренний параметр
#define internal1_m1488_x0	 BUFFER[3324]	//(internal1_m1488_x0) был приход сигнала x1
#define idinternal1_m1488_x0	 1164	//(internal1_m1488_x0) был приход сигнала x1
#define internal1_m1488_y0	 BUFFER[3326]	//(internal1_m1488_y0) интервал между сигналами х1 и х2
#define idinternal1_m1488_y0	 1165	//(internal1_m1488_y0) интервал между сигналами х1 и х2
#define internal1_m1413_x0	 BUFFER[3331]	//(internal1_m1413_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1413_x0	 1166	//(internal1_m1413_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1493_q0	 BUFFER[3336]	//(internal1_m1493_q0) q0 - внутренний параметр
#define idinternal1_m1493_q0	 1167	//(internal1_m1493_q0) q0 - внутренний параметр
#define internal1_m26_q0	 BUFFER[3338]	//(internal1_m26_q0) q0 - внутренний параметр
#define idinternal1_m26_q0	 1168	//(internal1_m26_q0) q0 - внутренний параметр
#define internal1_m1508_q0	 BUFFER[3340]	//(internal1_m1508_q0) q0 - внутренний параметр
#define idinternal1_m1508_q0	 1169	//(internal1_m1508_q0) q0 - внутренний параметр
#define internal1_m632_q0	 BUFFER[3342]	//(internal1_m632_q0) q0 - внутренний параметр
#define idinternal1_m632_q0	 1170	//(internal1_m632_q0) q0 - внутренний параметр
#define internal1_m617_q0	 BUFFER[3344]	//(internal1_m617_q0) q0 - внутренний параметр
#define idinternal1_m617_q0	 1171	//(internal1_m617_q0) q0 - внутренний параметр
#define internal1_m643_q0	 BUFFER[3346]	//(internal1_m643_q0) q0 - внутренний параметр
#define idinternal1_m643_q0	 1172	//(internal1_m643_q0) q0 - внутренний параметр
#define internal1_m628_q0	 BUFFER[3348]	//(internal1_m628_q0) q0 - внутренний параметр
#define idinternal1_m628_q0	 1173	//(internal1_m628_q0) q0 - внутренний параметр
#define internal1_m612_q0	 BUFFER[3350]	//(internal1_m612_q0) q0 - внутренний параметр
#define idinternal1_m612_q0	 1174	//(internal1_m612_q0) q0 - внутренний параметр
#define internal1_m610_q0	 BUFFER[3352]	//(internal1_m610_q0) q0 - внутренний параметр
#define idinternal1_m610_q0	 1175	//(internal1_m610_q0) q0 - внутренний параметр
#define internal1_m598_q0	 BUFFER[3354]	//(internal1_m598_q0) q0 - внутренний параметр
#define idinternal1_m598_q0	 1176	//(internal1_m598_q0) q0 - внутренний параметр
#define internal1_m1405_q0	 BUFFER[3356]	//(internal1_m1405_q0) q0 - внутренний параметр
#define idinternal1_m1405_q0	 1177	//(internal1_m1405_q0) q0 - внутренний параметр
#define internal1_m608_q0	 BUFFER[3361]	//(internal1_m608_q0) q0 - внутренний параметр
#define idinternal1_m608_q0	 1178	//(internal1_m608_q0) q0 - внутренний параметр
#define internal1_m106_q0	 BUFFER[3363]	//(internal1_m106_q0) q0 - внутренний параметр
#define idinternal1_m106_q0	 1179	//(internal1_m106_q0) q0 - внутренний параметр
#define internal1_m1640_q0	 BUFFER[3365]	//(internal1_m1640_q0) q0 - внутренний параметр
#define idinternal1_m1640_q0	 1180	//(internal1_m1640_q0) q0 - внутренний параметр
#define internal1_m1639_q0	 BUFFER[3367]	//(internal1_m1639_q0) q0 - внутренний параметр
#define idinternal1_m1639_q0	 1181	//(internal1_m1639_q0) q0 - внутренний параметр
#define internal1_m1638_q0	 BUFFER[3369]	//(internal1_m1638_q0) q0 - внутренний параметр
#define idinternal1_m1638_q0	 1182	//(internal1_m1638_q0) q0 - внутренний параметр
#define internal1_m1637_q0	 BUFFER[3371]	//(internal1_m1637_q0) q0 - внутренний параметр
#define idinternal1_m1637_q0	 1183	//(internal1_m1637_q0) q0 - внутренний параметр
#define internal1_m1668_q0	 BUFFER[3373]	//(internal1_m1668_q0) q0 - внутренний параметр
#define idinternal1_m1668_q0	 1184	//(internal1_m1668_q0) q0 - внутренний параметр
#define internal1_m1667_q0	 BUFFER[3375]	//(internal1_m1667_q0) q0 - внутренний параметр
#define idinternal1_m1667_q0	 1185	//(internal1_m1667_q0) q0 - внутренний параметр
#define internal1_m1666_q0	 BUFFER[3377]	//(internal1_m1666_q0) q0 - внутренний параметр
#define idinternal1_m1666_q0	 1186	//(internal1_m1666_q0) q0 - внутренний параметр
#define internal1_m1665_q0	 BUFFER[3379]	//(internal1_m1665_q0) q0 - внутренний параметр
#define idinternal1_m1665_q0	 1187	//(internal1_m1665_q0) q0 - внутренний параметр
#define internal1_m1661_tx	 BUFFER[3381]	//(internal1_m1661_tx) tx - время накопленное сек
#define idinternal1_m1661_tx	 1188	//(internal1_m1661_tx) tx - время накопленное сек
#define internal1_m1661_y0	 BUFFER[3386]	//(internal1_m1661_y0) y0
#define idinternal1_m1661_y0	 1189	//(internal1_m1661_y0) y0
#define internal1_m1654_tx	 BUFFER[3387]	//(internal1_m1654_tx) tx - время накопленное сек
#define idinternal1_m1654_tx	 1190	//(internal1_m1654_tx) tx - время накопленное сек
#define internal1_m1654_y0	 BUFFER[3392]	//(internal1_m1654_y0) y0
#define idinternal1_m1654_y0	 1191	//(internal1_m1654_y0) y0
#define internal1_m1946_q0	 BUFFER[3393]	//(internal1_m1946_q0) q0 - внутренний параметр
#define idinternal1_m1946_q0	 1192	//(internal1_m1946_q0) q0 - внутренний параметр
#define internal1_m1726_q0	 BUFFER[3395]	//(internal1_m1726_q0) q0 - внутренний параметр
#define idinternal1_m1726_q0	 1193	//(internal1_m1726_q0) q0 - внутренний параметр
#define internal1_m1725_q0	 BUFFER[3397]	//(internal1_m1725_q0) q0 - внутренний параметр
#define idinternal1_m1725_q0	 1194	//(internal1_m1725_q0) q0 - внутренний параметр
#define internal1_m1723_q0	 BUFFER[3399]	//(internal1_m1723_q0) q0 - внутренний параметр
#define idinternal1_m1723_q0	 1195	//(internal1_m1723_q0) q0 - внутренний параметр
#define internal1_m1722_q0	 BUFFER[3401]	//(internal1_m1722_q0) q0 - внутренний параметр
#define idinternal1_m1722_q0	 1196	//(internal1_m1722_q0) q0 - внутренний параметр
#define internal1_m1720_q0	 BUFFER[3403]	//(internal1_m1720_q0) q0 - внутренний параметр
#define idinternal1_m1720_q0	 1197	//(internal1_m1720_q0) q0 - внутренний параметр
#define internal1_m1710_tx	 BUFFER[3405]	//(internal1_m1710_tx) tx - время накопленное сек
#define idinternal1_m1710_tx	 1198	//(internal1_m1710_tx) tx - время накопленное сек
#define internal1_m1710_y0	 BUFFER[3410]	//(internal1_m1710_y0) y0
#define idinternal1_m1710_y0	 1199	//(internal1_m1710_y0) y0
#define internal1_m1709_tx	 BUFFER[3411]	//(internal1_m1709_tx) tx - время накопленное сек
#define idinternal1_m1709_tx	 1200	//(internal1_m1709_tx) tx - время накопленное сек
#define internal1_m1709_y0	 BUFFER[3416]	//(internal1_m1709_y0) y0
#define idinternal1_m1709_y0	 1201	//(internal1_m1709_y0) y0
#define internal1_m1697_q0	 BUFFER[3417]	//(internal1_m1697_q0) q0 - внутренний параметр
#define idinternal1_m1697_q0	 1202	//(internal1_m1697_q0) q0 - внутренний параметр
#define internal1_m1707_q0	 BUFFER[3419]	//(internal1_m1707_q0) q0 - внутренний параметр
#define idinternal1_m1707_q0	 1203	//(internal1_m1707_q0) q0 - внутренний параметр
#define internal1_m1706_q0	 BUFFER[3421]	//(internal1_m1706_q0) q0 - внутренний параметр
#define idinternal1_m1706_q0	 1204	//(internal1_m1706_q0) q0 - внутренний параметр
#define internal1_m1704_q0	 BUFFER[3423]	//(internal1_m1704_q0) q0 - внутренний параметр
#define idinternal1_m1704_q0	 1205	//(internal1_m1704_q0) q0 - внутренний параметр
#define internal1_m1698_q0	 BUFFER[3425]	//(internal1_m1698_q0) q0 - внутренний параметр
#define idinternal1_m1698_q0	 1206	//(internal1_m1698_q0) q0 - внутренний параметр
#define internal1_m1688_q0	 BUFFER[3427]	//(internal1_m1688_q0) q0 - внутренний параметр
#define idinternal1_m1688_q0	 1207	//(internal1_m1688_q0) q0 - внутренний параметр
#define internal1_m1687_q0	 BUFFER[3429]	//(internal1_m1687_q0) q0 - внутренний параметр
#define idinternal1_m1687_q0	 1208	//(internal1_m1687_q0) q0 - внутренний параметр
#define internal1_m1683_q0	 BUFFER[3431]	//(internal1_m1683_q0) q0 - внутренний параметр
#define idinternal1_m1683_q0	 1209	//(internal1_m1683_q0) q0 - внутренний параметр
#define internal1_m1685_q0	 BUFFER[3433]	//(internal1_m1685_q0) q0 - внутренний параметр
#define idinternal1_m1685_q0	 1210	//(internal1_m1685_q0) q0 - внутренний параметр
#define internal1_m1682_q0	 BUFFER[3435]	//(internal1_m1682_q0) q0 - внутренний параметр
#define idinternal1_m1682_q0	 1211	//(internal1_m1682_q0) q0 - внутренний параметр
#define internal1_m1681_q0	 BUFFER[3437]	//(internal1_m1681_q0) q0 - внутренний параметр
#define idinternal1_m1681_q0	 1212	//(internal1_m1681_q0) q0 - внутренний параметр
#define internal1_m1677_q0	 BUFFER[3439]	//(internal1_m1677_q0) q0 - внутренний параметр
#define idinternal1_m1677_q0	 1213	//(internal1_m1677_q0) q0 - внутренний параметр
#define internal1_m1679_q0	 BUFFER[3441]	//(internal1_m1679_q0) q0 - внутренний параметр
#define idinternal1_m1679_q0	 1214	//(internal1_m1679_q0) q0 - внутренний параметр
#define internal1_m19_q0	 BUFFER[3443]	//(internal1_m19_q0) q0 - внутренний параметр
#define idinternal1_m19_q0	 1215	//(internal1_m19_q0) q0 - внутренний параметр
#define internal1_m1662_q0	 BUFFER[3445]	//(internal1_m1662_q0) q0 - внутренний параметр
#define idinternal1_m1662_q0	 1216	//(internal1_m1662_q0) q0 - внутренний параметр
#define internal1_m1660_q0	 BUFFER[3447]	//(internal1_m1660_q0) q0 - внутренний параметр
#define idinternal1_m1660_q0	 1217	//(internal1_m1660_q0) q0 - внутренний параметр
#define internal1_m1656_q0	 BUFFER[3449]	//(internal1_m1656_q0) q0 - внутренний параметр
#define idinternal1_m1656_q0	 1218	//(internal1_m1656_q0) q0 - внутренний параметр
#define internal1_m1658_q0	 BUFFER[3451]	//(internal1_m1658_q0) q0 - внутренний параметр
#define idinternal1_m1658_q0	 1219	//(internal1_m1658_q0) q0 - внутренний параметр
#define internal1_m1655_q0	 BUFFER[3453]	//(internal1_m1655_q0) q0 - внутренний параметр
#define idinternal1_m1655_q0	 1220	//(internal1_m1655_q0) q0 - внутренний параметр
#define internal1_m1653_q0	 BUFFER[3455]	//(internal1_m1653_q0) q0 - внутренний параметр
#define idinternal1_m1653_q0	 1221	//(internal1_m1653_q0) q0 - внутренний параметр
#define internal1_m2046_q0	 BUFFER[3457]	//(internal1_m2046_q0) q0 - внутренний параметр
#define idinternal1_m2046_q0	 1222	//(internal1_m2046_q0) q0 - внутренний параметр
#define internal1_m2042_q0	 BUFFER[3459]	//(internal1_m2042_q0) q0 - внутренний параметр
#define idinternal1_m2042_q0	 1223	//(internal1_m2042_q0) q0 - внутренний параметр
#define internal1_m2029_q0	 BUFFER[3461]	//(internal1_m2029_q0) q0 - внутренний параметр
#define idinternal1_m2029_q0	 1224	//(internal1_m2029_q0) q0 - внутренний параметр
#define internal1_m2021_q0	 BUFFER[3463]	//(internal1_m2021_q0) q0 - внутренний параметр
#define idinternal1_m2021_q0	 1225	//(internal1_m2021_q0) q0 - внутренний параметр
#define internal1_m1956_q0	 BUFFER[3465]	//(internal1_m1956_q0) q0 - внутренний параметр
#define idinternal1_m1956_q0	 1226	//(internal1_m1956_q0) q0 - внутренний параметр
#define internal1_m1649_q0	 BUFFER[3467]	//(internal1_m1649_q0) q0 - внутренний параметр
#define idinternal1_m1649_q0	 1227	//(internal1_m1649_q0) q0 - внутренний параметр
#define internal1_m1651_q0	 BUFFER[3469]	//(internal1_m1651_q0) q0 - внутренний параметр
#define idinternal1_m1651_q0	 1228	//(internal1_m1651_q0) q0 - внутренний параметр
#define internal1_m1636_q0	 BUFFER[3471]	//(internal1_m1636_q0) q0 - внутренний параметр
#define idinternal1_m1636_q0	 1229	//(internal1_m1636_q0) q0 - внутренний параметр
#define internal1_m1634_q0	 BUFFER[3473]	//(internal1_m1634_q0) q0 - внутренний параметр
#define idinternal1_m1634_q0	 1230	//(internal1_m1634_q0) q0 - внутренний параметр
#define internal1_m1633_q0	 BUFFER[3475]	//(internal1_m1633_q0) q0 - внутренний параметр
#define idinternal1_m1633_q0	 1231	//(internal1_m1633_q0) q0 - внутренний параметр
#define internal1_m1631_q0	 BUFFER[3477]	//(internal1_m1631_q0) q0 - внутренний параметр
#define idinternal1_m1631_q0	 1232	//(internal1_m1631_q0) q0 - внутренний параметр
#define internal1_m1630_q0	 BUFFER[3479]	//(internal1_m1630_q0) q0 - внутренний параметр
#define idinternal1_m1630_q0	 1233	//(internal1_m1630_q0) q0 - внутренний параметр
#define internal1_m1628_q0	 BUFFER[3481]	//(internal1_m1628_q0) q0 - внутренний параметр
#define idinternal1_m1628_q0	 1234	//(internal1_m1628_q0) q0 - внутренний параметр
#define internal1_m1627_q0	 BUFFER[3483]	//(internal1_m1627_q0) q0 - внутренний параметр
#define idinternal1_m1627_q0	 1235	//(internal1_m1627_q0) q0 - внутренний параметр
#define internal1_m1625_q0	 BUFFER[3485]	//(internal1_m1625_q0) q0 - внутренний параметр
#define idinternal1_m1625_q0	 1236	//(internal1_m1625_q0) q0 - внутренний параметр
#define internal1_m2068_DvUp0	 BUFFER[3487]	//(internal1_m2068_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2068_DvUp0	 1237	//(internal1_m2068_DvUp0) - есть команда на движение вперёд
#define internal1_m2068_DvDw0	 BUFFER[3488]	//(internal1_m2068_DvDw0) - есть команда на движение назад
#define idinternal1_m2068_DvDw0	 1238	//(internal1_m2068_DvDw0) - есть команда на движение назад
#define internal1_m2068_FDvUp0	 BUFFER[3489]	//(internal1_m2068_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2068_FDvUp0	 1239	//(internal1_m2068_FDvUp0) - есть команда на движение вперёд
#define internal1_m2068_FDvDw0	 BUFFER[3490]	//(internal1_m2068_FDvDw0) - есть команда на движение назад
#define idinternal1_m2068_FDvDw0	 1240	//(internal1_m2068_FDvDw0) - есть команда на движение назад
#define internal1_m2068_BlDv0	 BUFFER[3491]	//(internal1_m2068_BlDv0) - была блокировка
#define idinternal1_m2068_BlDv0	 1241	//(internal1_m2068_BlDv0) - была блокировка
#define internal1_m2068_Pkv0	 BUFFER[3492]	//(internal1_m2068_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2068_Pkv0	 1242	//(internal1_m2068_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2068_Pkav0	 BUFFER[3493]	//(internal1_m2068_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2068_Pkav0	 1243	//(internal1_m2068_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2068_Zkv0	 BUFFER[3494]	//(internal1_m2068_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2068_Zkv0	 1244	//(internal1_m2068_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2068_Zkav0	 BUFFER[3495]	//(internal1_m2068_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2068_Zkav0	 1245	//(internal1_m2068_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2068_txNm	 BUFFER[3496]	//(internal1_m2068_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2068_txNm	 1246	//(internal1_m2068_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2068_txSm	 BUFFER[3501]	//(internal1_m2068_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2068_txSm	 1247	//(internal1_m2068_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2068_txHr	 BUFFER[3506]	//(internal1_m2068_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2068_txHr	 1248	//(internal1_m2068_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2068_txLd	 BUFFER[3511]	//(internal1_m2068_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2068_txLd	 1249	//(internal1_m2068_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2068_fef	 BUFFER[3516]	//(internal1_m2068_fef) fef
#define idinternal1_m2068_fef	 1250	//(internal1_m2068_fef) fef
#define internal1_m2062_DvUp0	 BUFFER[3517]	//(internal1_m2062_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2062_DvUp0	 1251	//(internal1_m2062_DvUp0) - есть команда на движение вперёд
#define internal1_m2062_DvDw0	 BUFFER[3518]	//(internal1_m2062_DvDw0) - есть команда на движение назад
#define idinternal1_m2062_DvDw0	 1252	//(internal1_m2062_DvDw0) - есть команда на движение назад
#define internal1_m2062_FDvUp0	 BUFFER[3519]	//(internal1_m2062_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2062_FDvUp0	 1253	//(internal1_m2062_FDvUp0) - есть команда на движение вперёд
#define internal1_m2062_FDvDw0	 BUFFER[3520]	//(internal1_m2062_FDvDw0) - есть команда на движение назад
#define idinternal1_m2062_FDvDw0	 1254	//(internal1_m2062_FDvDw0) - есть команда на движение назад
#define internal1_m2062_BlDv0	 BUFFER[3521]	//(internal1_m2062_BlDv0) - была блокировка
#define idinternal1_m2062_BlDv0	 1255	//(internal1_m2062_BlDv0) - была блокировка
#define internal1_m2062_Pkv0	 BUFFER[3522]	//(internal1_m2062_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2062_Pkv0	 1256	//(internal1_m2062_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2062_Pkav0	 BUFFER[3523]	//(internal1_m2062_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2062_Pkav0	 1257	//(internal1_m2062_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2062_Zkv0	 BUFFER[3524]	//(internal1_m2062_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2062_Zkv0	 1258	//(internal1_m2062_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2062_Zkav0	 BUFFER[3525]	//(internal1_m2062_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2062_Zkav0	 1259	//(internal1_m2062_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2062_txNm	 BUFFER[3526]	//(internal1_m2062_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2062_txNm	 1260	//(internal1_m2062_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2062_txSm	 BUFFER[3531]	//(internal1_m2062_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2062_txSm	 1261	//(internal1_m2062_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2062_txHr	 BUFFER[3536]	//(internal1_m2062_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2062_txHr	 1262	//(internal1_m2062_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2062_txLd	 BUFFER[3541]	//(internal1_m2062_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2062_txLd	 1263	//(internal1_m2062_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2062_fef	 BUFFER[3546]	//(internal1_m2062_fef) fef
#define idinternal1_m2062_fef	 1264	//(internal1_m2062_fef) fef
#define internal1_m360_DvUp0	 BUFFER[3547]	//(internal1_m360_DvUp0) - есть команда на движение вперёд
#define idinternal1_m360_DvUp0	 1265	//(internal1_m360_DvUp0) - есть команда на движение вперёд
#define internal1_m360_DvDw0	 BUFFER[3548]	//(internal1_m360_DvDw0) - есть команда на движение назад
#define idinternal1_m360_DvDw0	 1266	//(internal1_m360_DvDw0) - есть команда на движение назад
#define internal1_m360_FDvUp0	 BUFFER[3549]	//(internal1_m360_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m360_FDvUp0	 1267	//(internal1_m360_FDvUp0) - есть команда на движение вперёд
#define internal1_m360_FDvDw0	 BUFFER[3550]	//(internal1_m360_FDvDw0) - есть команда на движение назад
#define idinternal1_m360_FDvDw0	 1268	//(internal1_m360_FDvDw0) - есть команда на движение назад
#define internal1_m360_BlDv0	 BUFFER[3551]	//(internal1_m360_BlDv0) - была блокировка
#define idinternal1_m360_BlDv0	 1269	//(internal1_m360_BlDv0) - была блокировка
#define internal1_m360_Pkv0	 BUFFER[3552]	//(internal1_m360_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m360_Pkv0	 1270	//(internal1_m360_Pkv0) Pkv - передний конечный выключатель
#define internal1_m360_Pkav0	 BUFFER[3553]	//(internal1_m360_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m360_Pkav0	 1271	//(internal1_m360_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m360_Zkv0	 BUFFER[3554]	//(internal1_m360_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m360_Zkv0	 1272	//(internal1_m360_Zkv0) Zkv - задний конечный выключатель
#define internal1_m360_Zkav0	 BUFFER[3555]	//(internal1_m360_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m360_Zkav0	 1273	//(internal1_m360_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m360_txNm	 BUFFER[3556]	//(internal1_m360_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m360_txNm	 1274	//(internal1_m360_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m360_txSm	 BUFFER[3561]	//(internal1_m360_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m360_txSm	 1275	//(internal1_m360_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m360_txHr	 BUFFER[3566]	//(internal1_m360_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m360_txHr	 1276	//(internal1_m360_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m360_txLd	 BUFFER[3571]	//(internal1_m360_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m360_txLd	 1277	//(internal1_m360_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m360_fef	 BUFFER[3576]	//(internal1_m360_fef) fef
#define idinternal1_m360_fef	 1278	//(internal1_m360_fef) fef
#define internal1_m1478_q0	 BUFFER[3577]	//(internal1_m1478_q0) q0 - внутренний параметр
#define idinternal1_m1478_q0	 1279	//(internal1_m1478_q0) q0 - внутренний параметр
#define internal1_m1482_x0	 BUFFER[3579]	//(internal1_m1482_x0) был приход сигнала x1
#define idinternal1_m1482_x0	 1280	//(internal1_m1482_x0) был приход сигнала x1
#define internal1_m1482_y0	 BUFFER[3581]	//(internal1_m1482_y0) интервал между сигналами х1 и х2
#define idinternal1_m1482_y0	 1281	//(internal1_m1482_y0) интервал между сигналами х1 и х2
#define internal1_m1897_x0	 BUFFER[3586]	//(internal1_m1897_x0) был приход сигнала x1
#define idinternal1_m1897_x0	 1282	//(internal1_m1897_x0) был приход сигнала x1
#define internal1_m1897_y0	 BUFFER[3588]	//(internal1_m1897_y0) интервал между сигналами х1 и х2
#define idinternal1_m1897_y0	 1283	//(internal1_m1897_y0) интервал между сигналами х1 и х2
#define internal1_m1858_x0	 BUFFER[3593]	//(internal1_m1858_x0) был приход сигнала x1
#define idinternal1_m1858_x0	 1284	//(internal1_m1858_x0) был приход сигнала x1
#define internal1_m1858_y0	 BUFFER[3595]	//(internal1_m1858_y0) интервал между сигналами х1 и х2
#define idinternal1_m1858_y0	 1285	//(internal1_m1858_y0) интервал между сигналами х1 и х2
#define internal1_m271_q0	 BUFFER[3600]	//(internal1_m271_q0) q0 - внутренний параметр
#define idinternal1_m271_q0	 1286	//(internal1_m271_q0) q0 - внутренний параметр
#define internal1_m999_q0	 BUFFER[3602]	//(internal1_m999_q0) q0 - внутренний параметр
#define idinternal1_m999_q0	 1287	//(internal1_m999_q0) q0 - внутренний параметр
#define internal1_m620_q0	 BUFFER[3604]	//(internal1_m620_q0) q0 - внутренний параметр
#define idinternal1_m620_q0	 1288	//(internal1_m620_q0) q0 - внутренний параметр
#define internal1_m1297_X0	 BUFFER[3606]	//(internal1_m1297_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1297_X0	 1289	//(internal1_m1297_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1297_t0	 BUFFER[3611]	//(internal1_m1297_t0) время нахождения в зоне возврата
#define idinternal1_m1297_t0	 1290	//(internal1_m1297_t0) время нахождения в зоне возврата
#define internal1_m1297_BLDv0	 BUFFER[3616]	//(internal1_m1297_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1297_BLDv0	 1291	//(internal1_m1297_BLDv0) BlDv - Блокировка движения
#define internal1_m1316_tx	 BUFFER[3617]	//(internal1_m1316_tx) tx - время накопленное сек
#define idinternal1_m1316_tx	 1292	//(internal1_m1316_tx) tx - время накопленное сек
#define internal1_m1316_y0	 BUFFER[3622]	//(internal1_m1316_y0) y0
#define idinternal1_m1316_y0	 1293	//(internal1_m1316_y0) y0
#define internal1_m1319_tx	 BUFFER[3623]	//(internal1_m1319_tx) tx - время накопленное сек
#define idinternal1_m1319_tx	 1294	//(internal1_m1319_tx) tx - время накопленное сек
#define internal1_m1319_y0	 BUFFER[3628]	//(internal1_m1319_y0) y0
#define idinternal1_m1319_y0	 1295	//(internal1_m1319_y0) y0
#define internal1_m1325_xptr	 BUFFER[3629]	//(internal1_m1325_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1325_xptr	 1296	//(internal1_m1325_xptr) указатель текущей позиции в массиве координат
#define internal1_m1325_x0	 BUFFER[3632]	//(internal1_m1325_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1325_x0	 1297	//(internal1_m1325_x0) x0 - массив мгновенных значений координат
#define internal1_m1325_tim0	 BUFFER[3932]	//(internal1_m1325_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1325_tim0	 1298	//(internal1_m1325_tim0) tim0 - массив значений времени цикла
#define internal1_m1325_mcount	 BUFFER[4232]	//(internal1_m1325_mcount) count - счетчик заполнения массива значений координат
#define idinternal1_m1325_mcount	 1299	//(internal1_m1325_mcount) count - счетчик заполнения массива значений координат
#define internal1_m1325_sumtim	 BUFFER[4235]	//(internal1_m1325_sumtim) sumtim - время в пути
#define idinternal1_m1325_sumtim	 1300	//(internal1_m1325_sumtim) sumtim - время в пути
#define internal1_m1325_sumtakt	 BUFFER[4240]	//(internal1_m1325_sumtakt) sumtim - время в пути
#define idinternal1_m1325_sumtakt	 1301	//(internal1_m1325_sumtakt) sumtim - время в пути
#define internal1_m1325_StSpeed	 BUFFER[4245]	//(internal1_m1325_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1325_StSpeed	 1302	//(internal1_m1325_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1325_Vz0	 BUFFER[4250]	//(internal1_m1325_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1325_Vz0	 1303	//(internal1_m1325_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1325_flRazg	 BUFFER[4255]	//(internal1_m1325_flRazg) признак разгона/торможения
#define idinternal1_m1325_flRazg	 1304	//(internal1_m1325_flRazg) признак разгона/торможения
#define internal1_m1325_DelSp	 BUFFER[4258]	//(internal1_m1325_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1325_DelSp	 1305	//(internal1_m1325_DelSp) DelSp - время переключения скоростей
#define internal1_m1325_z0	 BUFFER[4263]	//(internal1_m1325_z0) z0 - точка прекращения движения
#define idinternal1_m1325_z0	 1306	//(internal1_m1325_z0) z0 - точка прекращения движения
#define internal1_m1325_txZS	 BUFFER[4268]	//(internal1_m1325_txZS) txZS
#define idinternal1_m1325_txZS	 1307	//(internal1_m1325_txZS) txZS
#define internal1_m1325_tx	 BUFFER[4273]	//(internal1_m1325_tx) tx
#define idinternal1_m1325_tx	 1308	//(internal1_m1325_tx) tx
#define internal1_m1325_txd	 BUFFER[4278]	//(internal1_m1325_txd) txd
#define idinternal1_m1325_txd	 1309	//(internal1_m1325_txd) txd
#define internal1_m1325_txMBl	 BUFFER[4283]	//(internal1_m1325_txMBl) tx
#define idinternal1_m1325_txMBl	 1310	//(internal1_m1325_txMBl) tx
#define internal1_m1325_txBl	 BUFFER[4288]	//(internal1_m1325_txBl) tx
#define idinternal1_m1325_txBl	 1311	//(internal1_m1325_txBl) tx
#define internal1_m1325_Speed0	 BUFFER[4293]	//(internal1_m1325_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1325_Speed0	 1312	//(internal1_m1325_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1325_xz0	 BUFFER[4298]	//(internal1_m1325_xz0) xz0 - новое задание мм
#define idinternal1_m1325_xz0	 1313	//(internal1_m1325_xz0) xz0 - новое задание мм
#define internal1_m1325_tz0	 BUFFER[4303]	//(internal1_m1325_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1325_tz0	 1314	//(internal1_m1325_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1325_Shift0	 BUFFER[4308]	//(internal1_m1325_Shift0) Shift0 - признак самохода
#define idinternal1_m1325_Shift0	 1315	//(internal1_m1325_Shift0) Shift0 - признак самохода
#define internal1_m1325_ShCntlSp0	 BUFFER[4310]	//(internal1_m1325_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1325_ShCntlSp0	 1316	//(internal1_m1325_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1325_ShiftControl	 BUFFER[4312]	//(internal1_m1325_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1325_ShiftControl	 1317	//(internal1_m1325_ShiftControl) ShiftControl - признак самохода
#define internal1_m618_q0	 BUFFER[4314]	//(internal1_m618_q0) q0 - внутренний параметр
#define idinternal1_m618_q0	 1318	//(internal1_m618_q0) q0 - внутренний параметр
#define internal1_m892_X0	 BUFFER[4316]	//(internal1_m892_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m892_X0	 1319	//(internal1_m892_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m892_t0	 BUFFER[4321]	//(internal1_m892_t0) время нахождения в зоне возврата
#define idinternal1_m892_t0	 1320	//(internal1_m892_t0) время нахождения в зоне возврата
#define internal1_m892_BLDv0	 BUFFER[4326]	//(internal1_m892_BLDv0) BlDv - Блокировка движения
#define idinternal1_m892_BLDv0	 1321	//(internal1_m892_BLDv0) BlDv - Блокировка движения
#define internal1_m916_tx	 BUFFER[4327]	//(internal1_m916_tx) tx - время накопленное сек
#define idinternal1_m916_tx	 1322	//(internal1_m916_tx) tx - время накопленное сек
#define internal1_m916_y0	 BUFFER[4332]	//(internal1_m916_y0) y0
#define idinternal1_m916_y0	 1323	//(internal1_m916_y0) y0
#define internal1_m917_tx	 BUFFER[4333]	//(internal1_m917_tx) tx - время накопленное сек
#define idinternal1_m917_tx	 1324	//(internal1_m917_tx) tx - время накопленное сек
#define internal1_m917_y0	 BUFFER[4338]	//(internal1_m917_y0) y0
#define idinternal1_m917_y0	 1325	//(internal1_m917_y0) y0
#define internal1_m925_xptr	 BUFFER[4339]	//(internal1_m925_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m925_xptr	 1326	//(internal1_m925_xptr) указатель текущей позиции в массиве координат
#define internal1_m925_x0	 BUFFER[4342]	//(internal1_m925_x0) x0 - массив мгновенных значений координат
#define idinternal1_m925_x0	 1327	//(internal1_m925_x0) x0 - массив мгновенных значений координат
#define internal1_m925_tim0	 BUFFER[4642]	//(internal1_m925_tim0) tim0 - массив значений времени цикла
#define idinternal1_m925_tim0	 1328	//(internal1_m925_tim0) tim0 - массив значений времени цикла
#define internal1_m925_mcount	 BUFFER[4942]	//(internal1_m925_mcount) count - счетчик заполнения массива значений координат
#define idinternal1_m925_mcount	 1329	//(internal1_m925_mcount) count - счетчик заполнения массива значений координат
#define internal1_m925_sumtim	 BUFFER[4945]	//(internal1_m925_sumtim) sumtim - время в пути
#define idinternal1_m925_sumtim	 1330	//(internal1_m925_sumtim) sumtim - время в пути
#define internal1_m925_sumtakt	 BUFFER[4950]	//(internal1_m925_sumtakt) sumtim - время в пути
#define idinternal1_m925_sumtakt	 1331	//(internal1_m925_sumtakt) sumtim - время в пути
#define internal1_m925_StSpeed	 BUFFER[4955]	//(internal1_m925_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m925_StSpeed	 1332	//(internal1_m925_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m925_Vz0	 BUFFER[4960]	//(internal1_m925_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m925_Vz0	 1333	//(internal1_m925_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m925_flRazg	 BUFFER[4965]	//(internal1_m925_flRazg) признак разгона/торможения
#define idinternal1_m925_flRazg	 1334	//(internal1_m925_flRazg) признак разгона/торможения
#define internal1_m925_DelSp	 BUFFER[4968]	//(internal1_m925_DelSp) DelSp - время переключения скоростей
#define idinternal1_m925_DelSp	 1335	//(internal1_m925_DelSp) DelSp - время переключения скоростей
#define internal1_m925_z0	 BUFFER[4973]	//(internal1_m925_z0) z0 - точка прекращения движения
#define idinternal1_m925_z0	 1336	//(internal1_m925_z0) z0 - точка прекращения движения
#define internal1_m925_txZS	 BUFFER[4978]	//(internal1_m925_txZS) txZS
#define idinternal1_m925_txZS	 1337	//(internal1_m925_txZS) txZS
#define internal1_m925_tx	 BUFFER[4983]	//(internal1_m925_tx) tx
#define idinternal1_m925_tx	 1338	//(internal1_m925_tx) tx
#define internal1_m925_txd	 BUFFER[4988]	//(internal1_m925_txd) txd
#define idinternal1_m925_txd	 1339	//(internal1_m925_txd) txd
#define internal1_m925_txMBl	 BUFFER[4993]	//(internal1_m925_txMBl) tx
#define idinternal1_m925_txMBl	 1340	//(internal1_m925_txMBl) tx
#define internal1_m925_txBl	 BUFFER[4998]	//(internal1_m925_txBl) tx
#define idinternal1_m925_txBl	 1341	//(internal1_m925_txBl) tx
#define internal1_m925_Speed0	 BUFFER[5003]	//(internal1_m925_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m925_Speed0	 1342	//(internal1_m925_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m925_xz0	 BUFFER[5008]	//(internal1_m925_xz0) xz0 - новое задание мм
#define idinternal1_m925_xz0	 1343	//(internal1_m925_xz0) xz0 - новое задание мм
#define internal1_m925_tz0	 BUFFER[5013]	//(internal1_m925_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m925_tz0	 1344	//(internal1_m925_tz0) tz0 - время защиты от нового задания сек
#define internal1_m925_Shift0	 BUFFER[5018]	//(internal1_m925_Shift0) Shift0 - признак самохода
#define idinternal1_m925_Shift0	 1345	//(internal1_m925_Shift0) Shift0 - признак самохода
#define internal1_m925_ShCntlSp0	 BUFFER[5020]	//(internal1_m925_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m925_ShCntlSp0	 1346	//(internal1_m925_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m925_ShiftControl	 BUFFER[5022]	//(internal1_m925_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m925_ShiftControl	 1347	//(internal1_m925_ShiftControl) ShiftControl - признак самохода
#define internal1_m491_X0	 BUFFER[5024]	//(internal1_m491_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m491_X0	 1348	//(internal1_m491_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m491_t0	 BUFFER[5029]	//(internal1_m491_t0) время нахождения в зоне возврата
#define idinternal1_m491_t0	 1349	//(internal1_m491_t0) время нахождения в зоне возврата
#define internal1_m491_BLDv0	 BUFFER[5034]	//(internal1_m491_BLDv0) BlDv - Блокировка движения
#define idinternal1_m491_BLDv0	 1350	//(internal1_m491_BLDv0) BlDv - Блокировка движения
#define internal1_m511_tx	 BUFFER[5035]	//(internal1_m511_tx) tx - время накопленное сек
#define idinternal1_m511_tx	 1351	//(internal1_m511_tx) tx - время накопленное сек
#define internal1_m511_y0	 BUFFER[5040]	//(internal1_m511_y0) y0
#define idinternal1_m511_y0	 1352	//(internal1_m511_y0) y0
#define internal1_m514_tx	 BUFFER[5041]	//(internal1_m514_tx) tx - время накопленное сек
#define idinternal1_m514_tx	 1353	//(internal1_m514_tx) tx - время накопленное сек
#define internal1_m514_y0	 BUFFER[5046]	//(internal1_m514_y0) y0
#define idinternal1_m514_y0	 1354	//(internal1_m514_y0) y0
#define internal1_m518_xptr	 BUFFER[5047]	//(internal1_m518_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m518_xptr	 1355	//(internal1_m518_xptr) указатель текущей позиции в массиве координат
#define internal1_m518_x0	 BUFFER[5050]	//(internal1_m518_x0) x0 - массив мгновенных значений координат
#define idinternal1_m518_x0	 1356	//(internal1_m518_x0) x0 - массив мгновенных значений координат
#define internal1_m518_tim0	 BUFFER[5800]	//(internal1_m518_tim0) tim0 - массив значений времени цикла
#define idinternal1_m518_tim0	 1357	//(internal1_m518_tim0) tim0 - массив значений времени цикла
#define internal1_m518_mcount	 BUFFER[6550]	//(internal1_m518_mcount) count - счетчик заполнения массива значений координат
#define idinternal1_m518_mcount	 1358	//(internal1_m518_mcount) count - счетчик заполнения массива значений координат
#define internal1_m518_sumtim	 BUFFER[6553]	//(internal1_m518_sumtim) sumtim - время в пути
#define idinternal1_m518_sumtim	 1359	//(internal1_m518_sumtim) sumtim - время в пути
#define internal1_m518_sumtakt	 BUFFER[6558]	//(internal1_m518_sumtakt) sumtim - время в пути
#define idinternal1_m518_sumtakt	 1360	//(internal1_m518_sumtakt) sumtim - время в пути
#define internal1_m518_StSpeed	 BUFFER[6563]	//(internal1_m518_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m518_StSpeed	 1361	//(internal1_m518_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m518_Vz0	 BUFFER[6568]	//(internal1_m518_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m518_Vz0	 1362	//(internal1_m518_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m518_flRazg	 BUFFER[6573]	//(internal1_m518_flRazg) признак разгона/торможения
#define idinternal1_m518_flRazg	 1363	//(internal1_m518_flRazg) признак разгона/торможения
#define internal1_m518_DelSp	 BUFFER[6576]	//(internal1_m518_DelSp) DelSp - время переключения скоростей
#define idinternal1_m518_DelSp	 1364	//(internal1_m518_DelSp) DelSp - время переключения скоростей
#define internal1_m518_z0	 BUFFER[6581]	//(internal1_m518_z0) z0 - точка прекращения движения
#define idinternal1_m518_z0	 1365	//(internal1_m518_z0) z0 - точка прекращения движения
#define internal1_m518_txZS	 BUFFER[6586]	//(internal1_m518_txZS) txZS
#define idinternal1_m518_txZS	 1366	//(internal1_m518_txZS) txZS
#define internal1_m518_tx	 BUFFER[6591]	//(internal1_m518_tx) tx
#define idinternal1_m518_tx	 1367	//(internal1_m518_tx) tx
#define internal1_m518_txd	 BUFFER[6596]	//(internal1_m518_txd) txd
#define idinternal1_m518_txd	 1368	//(internal1_m518_txd) txd
#define internal1_m518_txMBl	 BUFFER[6601]	//(internal1_m518_txMBl) tx
#define idinternal1_m518_txMBl	 1369	//(internal1_m518_txMBl) tx
#define internal1_m518_txBl	 BUFFER[6606]	//(internal1_m518_txBl) tx
#define idinternal1_m518_txBl	 1370	//(internal1_m518_txBl) tx
#define internal1_m518_Speed0	 BUFFER[6611]	//(internal1_m518_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m518_Speed0	 1371	//(internal1_m518_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m518_xz0	 BUFFER[6616]	//(internal1_m518_xz0) xz0 - новое задание мм
#define idinternal1_m518_xz0	 1372	//(internal1_m518_xz0) xz0 - новое задание мм
#define internal1_m518_tz0	 BUFFER[6621]	//(internal1_m518_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m518_tz0	 1373	//(internal1_m518_tz0) tz0 - время защиты от нового задания сек
#define internal1_m518_Shift0	 BUFFER[6626]	//(internal1_m518_Shift0) Shift0 - признак самохода
#define idinternal1_m518_Shift0	 1374	//(internal1_m518_Shift0) Shift0 - признак самохода
#define internal1_m518_ShCntlSp0	 BUFFER[6628]	//(internal1_m518_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m518_ShCntlSp0	 1375	//(internal1_m518_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m518_ShiftControl	 BUFFER[6630]	//(internal1_m518_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m518_ShiftControl	 1376	//(internal1_m518_ShiftControl) ShiftControl - признак самохода
#define internal1_m615_q0	 BUFFER[6632]	//(internal1_m615_q0) q0 - внутренний параметр
#define idinternal1_m615_q0	 1377	//(internal1_m615_q0) q0 - внутренний параметр
#define internal1_m163_X0	 BUFFER[6634]	//(internal1_m163_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m163_X0	 1378	//(internal1_m163_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m163_t0	 BUFFER[6639]	//(internal1_m163_t0) время нахождения в зоне возврата
#define idinternal1_m163_t0	 1379	//(internal1_m163_t0) время нахождения в зоне возврата
#define internal1_m163_BLDv0	 BUFFER[6644]	//(internal1_m163_BLDv0) BlDv - Блокировка движения
#define idinternal1_m163_BLDv0	 1380	//(internal1_m163_BLDv0) BlDv - Блокировка движения
#define internal1_m192_xptr	 BUFFER[6645]	//(internal1_m192_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m192_xptr	 1381	//(internal1_m192_xptr) указатель текущей позиции в массиве координат
#define internal1_m192_x0	 BUFFER[6648]	//(internal1_m192_x0) x0 - массив мгновенных значений координат
#define idinternal1_m192_x0	 1382	//(internal1_m192_x0) x0 - массив мгновенных значений координат
#define internal1_m192_tim0	 BUFFER[7398]	//(internal1_m192_tim0) tim0 - массив значений времени цикла
#define idinternal1_m192_tim0	 1383	//(internal1_m192_tim0) tim0 - массив значений времени цикла
#define internal1_m192_mcount	 BUFFER[8148]	//(internal1_m192_mcount) count - счетчик заполнения массива значений координат
#define idinternal1_m192_mcount	 1384	//(internal1_m192_mcount) count - счетчик заполнения массива значений координат
#define internal1_m192_sumtim	 BUFFER[8151]	//(internal1_m192_sumtim) sumtim - время в пути
#define idinternal1_m192_sumtim	 1385	//(internal1_m192_sumtim) sumtim - время в пути
#define internal1_m192_sumtakt	 BUFFER[8156]	//(internal1_m192_sumtakt) sumtim - время в пути
#define idinternal1_m192_sumtakt	 1386	//(internal1_m192_sumtakt) sumtim - время в пути
#define internal1_m192_StSpeed	 BUFFER[8161]	//(internal1_m192_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m192_StSpeed	 1387	//(internal1_m192_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m192_Vz0	 BUFFER[8166]	//(internal1_m192_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m192_Vz0	 1388	//(internal1_m192_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m192_flRazg	 BUFFER[8171]	//(internal1_m192_flRazg) признак разгона/торможения
#define idinternal1_m192_flRazg	 1389	//(internal1_m192_flRazg) признак разгона/торможения
#define internal1_m192_DelSp	 BUFFER[8174]	//(internal1_m192_DelSp) DelSp - время переключения скоростей
#define idinternal1_m192_DelSp	 1390	//(internal1_m192_DelSp) DelSp - время переключения скоростей
#define internal1_m192_z0	 BUFFER[8179]	//(internal1_m192_z0) z0 - точка прекращения движения
#define idinternal1_m192_z0	 1391	//(internal1_m192_z0) z0 - точка прекращения движения
#define internal1_m192_txZS	 BUFFER[8184]	//(internal1_m192_txZS) txZS
#define idinternal1_m192_txZS	 1392	//(internal1_m192_txZS) txZS
#define internal1_m192_tx	 BUFFER[8189]	//(internal1_m192_tx) tx
#define idinternal1_m192_tx	 1393	//(internal1_m192_tx) tx
#define internal1_m192_txd	 BUFFER[8194]	//(internal1_m192_txd) txd
#define idinternal1_m192_txd	 1394	//(internal1_m192_txd) txd
#define internal1_m192_txMBl	 BUFFER[8199]	//(internal1_m192_txMBl) tx
#define idinternal1_m192_txMBl	 1395	//(internal1_m192_txMBl) tx
#define internal1_m192_txBl	 BUFFER[8204]	//(internal1_m192_txBl) tx
#define idinternal1_m192_txBl	 1396	//(internal1_m192_txBl) tx
#define internal1_m192_Speed0	 BUFFER[8209]	//(internal1_m192_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m192_Speed0	 1397	//(internal1_m192_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m192_xz0	 BUFFER[8214]	//(internal1_m192_xz0) xz0 - новое задание мм
#define idinternal1_m192_xz0	 1398	//(internal1_m192_xz0) xz0 - новое задание мм
#define internal1_m192_tz0	 BUFFER[8219]	//(internal1_m192_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m192_tz0	 1399	//(internal1_m192_tz0) tz0 - время защиты от нового задания сек
#define internal1_m192_Shift0	 BUFFER[8224]	//(internal1_m192_Shift0) Shift0 - признак самохода
#define idinternal1_m192_Shift0	 1400	//(internal1_m192_Shift0) Shift0 - признак самохода
#define internal1_m192_ShCntlSp0	 BUFFER[8226]	//(internal1_m192_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m192_ShCntlSp0	 1401	//(internal1_m192_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m192_ShiftControl	 BUFFER[8228]	//(internal1_m192_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m192_ShiftControl	 1402	//(internal1_m192_ShiftControl) ShiftControl - признак самохода
#define internal1_m641_q0	 BUFFER[8230]	//(internal1_m641_q0) q0 - внутренний параметр
#define idinternal1_m641_q0	 1403	//(internal1_m641_q0) q0 - внутренний параметр
#define internal1_m462_DvUp0	 BUFFER[8232]	//(internal1_m462_DvUp0) - есть команда на движение вперёд
#define idinternal1_m462_DvUp0	 1404	//(internal1_m462_DvUp0) - есть команда на движение вперёд
#define internal1_m462_DvDw0	 BUFFER[8233]	//(internal1_m462_DvDw0) - есть команда на движение назад
#define idinternal1_m462_DvDw0	 1405	//(internal1_m462_DvDw0) - есть команда на движение назад
#define internal1_m462_FDvUp0	 BUFFER[8234]	//(internal1_m462_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m462_FDvUp0	 1406	//(internal1_m462_FDvUp0) - есть команда на движение вперёд
#define internal1_m462_FDvDw0	 BUFFER[8235]	//(internal1_m462_FDvDw0) - есть команда на движение назад
#define idinternal1_m462_FDvDw0	 1407	//(internal1_m462_FDvDw0) - есть команда на движение назад
#define internal1_m462_BlDv0	 BUFFER[8236]	//(internal1_m462_BlDv0) - была блокировка
#define idinternal1_m462_BlDv0	 1408	//(internal1_m462_BlDv0) - была блокировка
#define internal1_m462_Pkv0	 BUFFER[8237]	//(internal1_m462_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m462_Pkv0	 1409	//(internal1_m462_Pkv0) Pkv - передний конечный выключатель
#define internal1_m462_Pkav0	 BUFFER[8238]	//(internal1_m462_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m462_Pkav0	 1410	//(internal1_m462_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m462_Zkv0	 BUFFER[8239]	//(internal1_m462_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m462_Zkv0	 1411	//(internal1_m462_Zkv0) Zkv - задний конечный выключатель
#define internal1_m462_Zkav0	 BUFFER[8240]	//(internal1_m462_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m462_Zkav0	 1412	//(internal1_m462_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m462_txNm	 BUFFER[8241]	//(internal1_m462_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m462_txNm	 1413	//(internal1_m462_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m462_txSm	 BUFFER[8246]	//(internal1_m462_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m462_txSm	 1414	//(internal1_m462_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m462_txHr	 BUFFER[8251]	//(internal1_m462_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m462_txHr	 1415	//(internal1_m462_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m462_txLd	 BUFFER[8256]	//(internal1_m462_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m462_txLd	 1416	//(internal1_m462_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m462_fef	 BUFFER[8261]	//(internal1_m462_fef) fef
#define idinternal1_m462_fef	 1417	//(internal1_m462_fef) fef
#define internal1_m456_DvUp0	 BUFFER[8262]	//(internal1_m456_DvUp0) - есть команда на движение вперёд
#define idinternal1_m456_DvUp0	 1418	//(internal1_m456_DvUp0) - есть команда на движение вперёд
#define internal1_m456_DvDw0	 BUFFER[8263]	//(internal1_m456_DvDw0) - есть команда на движение назад
#define idinternal1_m456_DvDw0	 1419	//(internal1_m456_DvDw0) - есть команда на движение назад
#define internal1_m456_FDvUp0	 BUFFER[8264]	//(internal1_m456_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m456_FDvUp0	 1420	//(internal1_m456_FDvUp0) - есть команда на движение вперёд
#define internal1_m456_FDvDw0	 BUFFER[8265]	//(internal1_m456_FDvDw0) - есть команда на движение назад
#define idinternal1_m456_FDvDw0	 1421	//(internal1_m456_FDvDw0) - есть команда на движение назад
#define internal1_m456_BlDv0	 BUFFER[8266]	//(internal1_m456_BlDv0) - была блокировка
#define idinternal1_m456_BlDv0	 1422	//(internal1_m456_BlDv0) - была блокировка
#define internal1_m456_Pkv0	 BUFFER[8267]	//(internal1_m456_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m456_Pkv0	 1423	//(internal1_m456_Pkv0) Pkv - передний конечный выключатель
#define internal1_m456_Pkav0	 BUFFER[8268]	//(internal1_m456_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m456_Pkav0	 1424	//(internal1_m456_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m456_Zkv0	 BUFFER[8269]	//(internal1_m456_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m456_Zkv0	 1425	//(internal1_m456_Zkv0) Zkv - задний конечный выключатель
#define internal1_m456_Zkav0	 BUFFER[8270]	//(internal1_m456_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m456_Zkav0	 1426	//(internal1_m456_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m456_txNm	 BUFFER[8271]	//(internal1_m456_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m456_txNm	 1427	//(internal1_m456_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m456_txSm	 BUFFER[8276]	//(internal1_m456_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m456_txSm	 1428	//(internal1_m456_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m456_txHr	 BUFFER[8281]	//(internal1_m456_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m456_txHr	 1429	//(internal1_m456_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m456_txLd	 BUFFER[8286]	//(internal1_m456_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m456_txLd	 1430	//(internal1_m456_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m456_fef	 BUFFER[8291]	//(internal1_m456_fef) fef
#define idinternal1_m456_fef	 1431	//(internal1_m456_fef) fef
#define internal1_m811_X0	 BUFFER[8292]	//(internal1_m811_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m811_X0	 1432	//(internal1_m811_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m811_t0	 BUFFER[8297]	//(internal1_m811_t0) время нахождения в зоне возврата
#define idinternal1_m811_t0	 1433	//(internal1_m811_t0) время нахождения в зоне возврата
#define internal1_m811_BLDv0	 BUFFER[8302]	//(internal1_m811_BLDv0) BlDv - Блокировка движения
#define idinternal1_m811_BLDv0	 1434	//(internal1_m811_BLDv0) BlDv - Блокировка движения
#define internal1_m831_xptr	 BUFFER[8303]	//(internal1_m831_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m831_xptr	 1435	//(internal1_m831_xptr) указатель текущей позиции в массиве координат
#define internal1_m831_x0	 BUFFER[8306]	//(internal1_m831_x0) x0 - массив мгновенных значений координат
#define idinternal1_m831_x0	 1436	//(internal1_m831_x0) x0 - массив мгновенных значений координат
#define internal1_m831_tim0	 BUFFER[8706]	//(internal1_m831_tim0) tim0 - массив значений времени цикла
#define idinternal1_m831_tim0	 1437	//(internal1_m831_tim0) tim0 - массив значений времени цикла
#define internal1_m831_mcount	 BUFFER[9106]	//(internal1_m831_mcount) count - счетчик заполнения массива значений координат
#define idinternal1_m831_mcount	 1438	//(internal1_m831_mcount) count - счетчик заполнения массива значений координат
#define internal1_m831_sumtim	 BUFFER[9109]	//(internal1_m831_sumtim) sumtim - время в пути
#define idinternal1_m831_sumtim	 1439	//(internal1_m831_sumtim) sumtim - время в пути
#define internal1_m831_sumtakt	 BUFFER[9114]	//(internal1_m831_sumtakt) sumtim - время в пути
#define idinternal1_m831_sumtakt	 1440	//(internal1_m831_sumtakt) sumtim - время в пути
#define internal1_m831_StSpeed	 BUFFER[9119]	//(internal1_m831_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m831_StSpeed	 1441	//(internal1_m831_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m831_Vz0	 BUFFER[9124]	//(internal1_m831_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m831_Vz0	 1442	//(internal1_m831_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m831_flRazg	 BUFFER[9129]	//(internal1_m831_flRazg) признак разгона/торможения
#define idinternal1_m831_flRazg	 1443	//(internal1_m831_flRazg) признак разгона/торможения
#define internal1_m831_DelSp	 BUFFER[9132]	//(internal1_m831_DelSp) DelSp - время переключения скоростей
#define idinternal1_m831_DelSp	 1444	//(internal1_m831_DelSp) DelSp - время переключения скоростей
#define internal1_m831_z0	 BUFFER[9137]	//(internal1_m831_z0) z0 - точка прекращения движения
#define idinternal1_m831_z0	 1445	//(internal1_m831_z0) z0 - точка прекращения движения
#define internal1_m831_txZS	 BUFFER[9142]	//(internal1_m831_txZS) txZS
#define idinternal1_m831_txZS	 1446	//(internal1_m831_txZS) txZS
#define internal1_m831_tx	 BUFFER[9147]	//(internal1_m831_tx) tx
#define idinternal1_m831_tx	 1447	//(internal1_m831_tx) tx
#define internal1_m831_txd	 BUFFER[9152]	//(internal1_m831_txd) txd
#define idinternal1_m831_txd	 1448	//(internal1_m831_txd) txd
#define internal1_m831_txMBl	 BUFFER[9157]	//(internal1_m831_txMBl) tx
#define idinternal1_m831_txMBl	 1449	//(internal1_m831_txMBl) tx
#define internal1_m831_txBl	 BUFFER[9162]	//(internal1_m831_txBl) tx
#define idinternal1_m831_txBl	 1450	//(internal1_m831_txBl) tx
#define internal1_m831_Speed0	 BUFFER[9167]	//(internal1_m831_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m831_Speed0	 1451	//(internal1_m831_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m831_xz0	 BUFFER[9172]	//(internal1_m831_xz0) xz0 - новое задание мм
#define idinternal1_m831_xz0	 1452	//(internal1_m831_xz0) xz0 - новое задание мм
#define internal1_m831_tz0	 BUFFER[9177]	//(internal1_m831_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m831_tz0	 1453	//(internal1_m831_tz0) tz0 - время защиты от нового задания сек
#define internal1_m831_Shift0	 BUFFER[9182]	//(internal1_m831_Shift0) Shift0 - признак самохода
#define idinternal1_m831_Shift0	 1454	//(internal1_m831_Shift0) Shift0 - признак самохода
#define internal1_m831_ShCntlSp0	 BUFFER[9184]	//(internal1_m831_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m831_ShCntlSp0	 1455	//(internal1_m831_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m831_ShiftControl	 BUFFER[9186]	//(internal1_m831_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m831_ShiftControl	 1456	//(internal1_m831_ShiftControl) ShiftControl - признак самохода
#define internal1_m1584_X0	 BUFFER[9188]	//(internal1_m1584_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1584_X0	 1457	//(internal1_m1584_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1584_t0	 BUFFER[9193]	//(internal1_m1584_t0) время нахождения в зоне возврата
#define idinternal1_m1584_t0	 1458	//(internal1_m1584_t0) время нахождения в зоне возврата
#define internal1_m1584_BLDv0	 BUFFER[9198]	//(internal1_m1584_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1584_BLDv0	 1459	//(internal1_m1584_BLDv0) BlDv - Блокировка движения
#define internal1_m1116_X0	 BUFFER[9199]	//(internal1_m1116_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1116_X0	 1460	//(internal1_m1116_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1116_t0	 BUFFER[9204]	//(internal1_m1116_t0) время нахождения в зоне возврата
#define idinternal1_m1116_t0	 1461	//(internal1_m1116_t0) время нахождения в зоне возврата
#define internal1_m1116_BLDv0	 BUFFER[9209]	//(internal1_m1116_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1116_BLDv0	 1462	//(internal1_m1116_BLDv0) BlDv - Блокировка движения
#define internal1_m613_q0	 BUFFER[9210]	//(internal1_m613_q0) q0 - внутренний параметр
#define idinternal1_m613_q0	 1463	//(internal1_m613_q0) q0 - внутренний параметр
#define internal1_m1199_X0	 BUFFER[9212]	//(internal1_m1199_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1199_X0	 1464	//(internal1_m1199_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1199_t0	 BUFFER[9217]	//(internal1_m1199_t0) время нахождения в зоне возврата
#define idinternal1_m1199_t0	 1465	//(internal1_m1199_t0) время нахождения в зоне возврата
#define internal1_m1199_BLDv0	 BUFFER[9222]	//(internal1_m1199_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1199_BLDv0	 1466	//(internal1_m1199_BLDv0) BlDv - Блокировка движения
#define internal1_m1219_tx	 BUFFER[9223]	//(internal1_m1219_tx) tx - время накопленное сек
#define idinternal1_m1219_tx	 1467	//(internal1_m1219_tx) tx - время накопленное сек
#define internal1_m1219_y0	 BUFFER[9228]	//(internal1_m1219_y0) y0
#define idinternal1_m1219_y0	 1468	//(internal1_m1219_y0) y0
#define internal1_m1227_tx	 BUFFER[9229]	//(internal1_m1227_tx) tx - время накопленное сек
#define idinternal1_m1227_tx	 1469	//(internal1_m1227_tx) tx - время накопленное сек
#define internal1_m1227_y0	 BUFFER[9234]	//(internal1_m1227_y0) y0
#define idinternal1_m1227_y0	 1470	//(internal1_m1227_y0) y0
#define internal1_m1232_xptr	 BUFFER[9235]	//(internal1_m1232_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1232_xptr	 1471	//(internal1_m1232_xptr) указатель текущей позиции в массиве координат
#define internal1_m1232_x0	 BUFFER[9238]	//(internal1_m1232_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1232_x0	 1472	//(internal1_m1232_x0) x0 - массив мгновенных значений координат
#define internal1_m1232_tim0	 BUFFER[9638]	//(internal1_m1232_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1232_tim0	 1473	//(internal1_m1232_tim0) tim0 - массив значений времени цикла
#define internal1_m1232_mcount	 BUFFER[10038]	//(internal1_m1232_mcount) count - счетчик заполнения массива значений координат
#define idinternal1_m1232_mcount	 1474	//(internal1_m1232_mcount) count - счетчик заполнения массива значений координат
#define internal1_m1232_sumtim	 BUFFER[10041]	//(internal1_m1232_sumtim) sumtim - время в пути
#define idinternal1_m1232_sumtim	 1475	//(internal1_m1232_sumtim) sumtim - время в пути
#define internal1_m1232_sumtakt	 BUFFER[10046]	//(internal1_m1232_sumtakt) sumtim - время в пути
#define idinternal1_m1232_sumtakt	 1476	//(internal1_m1232_sumtakt) sumtim - время в пути
#define internal1_m1232_StSpeed	 BUFFER[10051]	//(internal1_m1232_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1232_StSpeed	 1477	//(internal1_m1232_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1232_Vz0	 BUFFER[10056]	//(internal1_m1232_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1232_Vz0	 1478	//(internal1_m1232_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1232_flRazg	 BUFFER[10061]	//(internal1_m1232_flRazg) признак разгона/торможения
#define idinternal1_m1232_flRazg	 1479	//(internal1_m1232_flRazg) признак разгона/торможения
#define internal1_m1232_DelSp	 BUFFER[10064]	//(internal1_m1232_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1232_DelSp	 1480	//(internal1_m1232_DelSp) DelSp - время переключения скоростей
#define internal1_m1232_z0	 BUFFER[10069]	//(internal1_m1232_z0) z0 - точка прекращения движения
#define idinternal1_m1232_z0	 1481	//(internal1_m1232_z0) z0 - точка прекращения движения
#define internal1_m1232_txZS	 BUFFER[10074]	//(internal1_m1232_txZS) txZS
#define idinternal1_m1232_txZS	 1482	//(internal1_m1232_txZS) txZS
#define internal1_m1232_tx	 BUFFER[10079]	//(internal1_m1232_tx) tx
#define idinternal1_m1232_tx	 1483	//(internal1_m1232_tx) tx
#define internal1_m1232_txd	 BUFFER[10084]	//(internal1_m1232_txd) txd
#define idinternal1_m1232_txd	 1484	//(internal1_m1232_txd) txd
#define internal1_m1232_txMBl	 BUFFER[10089]	//(internal1_m1232_txMBl) tx
#define idinternal1_m1232_txMBl	 1485	//(internal1_m1232_txMBl) tx
#define internal1_m1232_txBl	 BUFFER[10094]	//(internal1_m1232_txBl) tx
#define idinternal1_m1232_txBl	 1486	//(internal1_m1232_txBl) tx
#define internal1_m1232_Speed0	 BUFFER[10099]	//(internal1_m1232_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1232_Speed0	 1487	//(internal1_m1232_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1232_xz0	 BUFFER[10104]	//(internal1_m1232_xz0) xz0 - новое задание мм
#define idinternal1_m1232_xz0	 1488	//(internal1_m1232_xz0) xz0 - новое задание мм
#define internal1_m1232_tz0	 BUFFER[10109]	//(internal1_m1232_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1232_tz0	 1489	//(internal1_m1232_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1232_Shift0	 BUFFER[10114]	//(internal1_m1232_Shift0) Shift0 - признак самохода
#define idinternal1_m1232_Shift0	 1490	//(internal1_m1232_Shift0) Shift0 - признак самохода
#define internal1_m1232_ShCntlSp0	 BUFFER[10116]	//(internal1_m1232_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1232_ShCntlSp0	 1491	//(internal1_m1232_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1232_ShiftControl	 BUFFER[10118]	//(internal1_m1232_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1232_ShiftControl	 1492	//(internal1_m1232_ShiftControl) ShiftControl - признак самохода
#define internal1_m633_q0	 BUFFER[10120]	//(internal1_m633_q0) q0 - внутренний параметр
#define idinternal1_m633_q0	 1493	//(internal1_m633_q0) q0 - внутренний параметр
#define internal1_m1597_tx	 BUFFER[10122]	//(internal1_m1597_tx) tx - время накопленное сек
#define idinternal1_m1597_tx	 1494	//(internal1_m1597_tx) tx - время накопленное сек
#define internal1_m1597_y0	 BUFFER[10127]	//(internal1_m1597_y0) y0
#define idinternal1_m1597_y0	 1495	//(internal1_m1597_y0) y0
#define internal1_m1601_tx	 BUFFER[10128]	//(internal1_m1601_tx) tx - время накопленное сек
#define idinternal1_m1601_tx	 1496	//(internal1_m1601_tx) tx - время накопленное сек
#define internal1_m1601_y0	 BUFFER[10133]	//(internal1_m1601_y0) y0
#define idinternal1_m1601_y0	 1497	//(internal1_m1601_y0) y0
#define internal1_m1587_DvUp0	 BUFFER[10134]	//(internal1_m1587_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1587_DvUp0	 1498	//(internal1_m1587_DvUp0) - есть команда на движение вперёд
#define internal1_m1587_DvDw0	 BUFFER[10135]	//(internal1_m1587_DvDw0) - есть команда на движение назад
#define idinternal1_m1587_DvDw0	 1499	//(internal1_m1587_DvDw0) - есть команда на движение назад
#define internal1_m1587_FDvUp0	 BUFFER[10136]	//(internal1_m1587_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1587_FDvUp0	 1500	//(internal1_m1587_FDvUp0) - есть команда на движение вперёд
#define internal1_m1587_FDvDw0	 BUFFER[10137]	//(internal1_m1587_FDvDw0) - есть команда на движение назад
#define idinternal1_m1587_FDvDw0	 1501	//(internal1_m1587_FDvDw0) - есть команда на движение назад
#define internal1_m1587_BlDv0	 BUFFER[10138]	//(internal1_m1587_BlDv0) - была блокировка
#define idinternal1_m1587_BlDv0	 1502	//(internal1_m1587_BlDv0) - была блокировка
#define internal1_m1587_Pkv0	 BUFFER[10139]	//(internal1_m1587_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1587_Pkv0	 1503	//(internal1_m1587_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1587_Pkav0	 BUFFER[10140]	//(internal1_m1587_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1587_Pkav0	 1504	//(internal1_m1587_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1587_Zkv0	 BUFFER[10141]	//(internal1_m1587_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1587_Zkv0	 1505	//(internal1_m1587_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1587_Zkav0	 BUFFER[10142]	//(internal1_m1587_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1587_Zkav0	 1506	//(internal1_m1587_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1587_txNm	 BUFFER[10143]	//(internal1_m1587_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1587_txNm	 1507	//(internal1_m1587_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1587_txSm	 BUFFER[10148]	//(internal1_m1587_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1587_txSm	 1508	//(internal1_m1587_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1587_txHr	 BUFFER[10153]	//(internal1_m1587_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1587_txHr	 1509	//(internal1_m1587_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1587_txLd	 BUFFER[10158]	//(internal1_m1587_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1587_txLd	 1510	//(internal1_m1587_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1587_fef	 BUFFER[10163]	//(internal1_m1587_fef) fef
#define idinternal1_m1587_fef	 1511	//(internal1_m1587_fef) fef
#define internal1_m1604_xptr	 BUFFER[10164]	//(internal1_m1604_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1604_xptr	 1512	//(internal1_m1604_xptr) указатель текущей позиции в массиве координат
#define internal1_m1604_x0	 BUFFER[10167]	//(internal1_m1604_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1604_x0	 1513	//(internal1_m1604_x0) x0 - массив мгновенных значений координат
#define internal1_m1604_tim0	 BUFFER[10267]	//(internal1_m1604_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1604_tim0	 1514	//(internal1_m1604_tim0) tim0 - массив значений времени цикла
#define internal1_m1604_mcount	 BUFFER[10367]	//(internal1_m1604_mcount) count - счетчик заполнения массива значений координат
#define idinternal1_m1604_mcount	 1515	//(internal1_m1604_mcount) count - счетчик заполнения массива значений координат
#define internal1_m1604_sumtim	 BUFFER[10370]	//(internal1_m1604_sumtim) sumtim - время в пути
#define idinternal1_m1604_sumtim	 1516	//(internal1_m1604_sumtim) sumtim - время в пути
#define internal1_m1604_sumtakt	 BUFFER[10375]	//(internal1_m1604_sumtakt) sumtim - время в пути
#define idinternal1_m1604_sumtakt	 1517	//(internal1_m1604_sumtakt) sumtim - время в пути
#define internal1_m1604_StSpeed	 BUFFER[10380]	//(internal1_m1604_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1604_StSpeed	 1518	//(internal1_m1604_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1604_Vz0	 BUFFER[10385]	//(internal1_m1604_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1604_Vz0	 1519	//(internal1_m1604_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1604_flRazg	 BUFFER[10390]	//(internal1_m1604_flRazg) признак разгона/торможения
#define idinternal1_m1604_flRazg	 1520	//(internal1_m1604_flRazg) признак разгона/торможения
#define internal1_m1604_DelSp	 BUFFER[10393]	//(internal1_m1604_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1604_DelSp	 1521	//(internal1_m1604_DelSp) DelSp - время переключения скоростей
#define internal1_m1604_z0	 BUFFER[10398]	//(internal1_m1604_z0) z0 - точка прекращения движения
#define idinternal1_m1604_z0	 1522	//(internal1_m1604_z0) z0 - точка прекращения движения
#define internal1_m1604_txZS	 BUFFER[10403]	//(internal1_m1604_txZS) txZS
#define idinternal1_m1604_txZS	 1523	//(internal1_m1604_txZS) txZS
#define internal1_m1604_tx	 BUFFER[10408]	//(internal1_m1604_tx) tx
#define idinternal1_m1604_tx	 1524	//(internal1_m1604_tx) tx
#define internal1_m1604_txd	 BUFFER[10413]	//(internal1_m1604_txd) txd
#define idinternal1_m1604_txd	 1525	//(internal1_m1604_txd) txd
#define internal1_m1604_txMBl	 BUFFER[10418]	//(internal1_m1604_txMBl) tx
#define idinternal1_m1604_txMBl	 1526	//(internal1_m1604_txMBl) tx
#define internal1_m1604_txBl	 BUFFER[10423]	//(internal1_m1604_txBl) tx
#define idinternal1_m1604_txBl	 1527	//(internal1_m1604_txBl) tx
#define internal1_m1604_Speed0	 BUFFER[10428]	//(internal1_m1604_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1604_Speed0	 1528	//(internal1_m1604_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1604_xz0	 BUFFER[10433]	//(internal1_m1604_xz0) xz0 - новое задание мм
#define idinternal1_m1604_xz0	 1529	//(internal1_m1604_xz0) xz0 - новое задание мм
#define internal1_m1604_tz0	 BUFFER[10438]	//(internal1_m1604_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1604_tz0	 1530	//(internal1_m1604_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1604_Shift0	 BUFFER[10443]	//(internal1_m1604_Shift0) Shift0 - признак самохода
#define idinternal1_m1604_Shift0	 1531	//(internal1_m1604_Shift0) Shift0 - признак самохода
#define internal1_m1604_ShCntlSp0	 BUFFER[10445]	//(internal1_m1604_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1604_ShCntlSp0	 1532	//(internal1_m1604_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1604_ShiftControl	 BUFFER[10447]	//(internal1_m1604_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1604_ShiftControl	 1533	//(internal1_m1604_ShiftControl) ShiftControl - признак самохода
#define internal1_m1130_tx	 BUFFER[10449]	//(internal1_m1130_tx) tx - время накопленное сек
#define idinternal1_m1130_tx	 1534	//(internal1_m1130_tx) tx - время накопленное сек
#define internal1_m1130_y0	 BUFFER[10454]	//(internal1_m1130_y0) y0
#define idinternal1_m1130_y0	 1535	//(internal1_m1130_y0) y0
#define internal1_m1133_tx	 BUFFER[10455]	//(internal1_m1133_tx) tx - время накопленное сек
#define idinternal1_m1133_tx	 1536	//(internal1_m1133_tx) tx - время накопленное сек
#define internal1_m1133_y0	 BUFFER[10460]	//(internal1_m1133_y0) y0
#define idinternal1_m1133_y0	 1537	//(internal1_m1133_y0) y0
#define internal1_m623_q0	 BUFFER[10461]	//(internal1_m623_q0) q0 - внутренний параметр
#define idinternal1_m623_q0	 1538	//(internal1_m623_q0) q0 - внутренний параметр
#define internal1_m588_q0	 BUFFER[10463]	//(internal1_m588_q0) q0 - внутренний параметр
#define idinternal1_m588_q0	 1539	//(internal1_m588_q0) q0 - внутренний параметр
#define internal1_m1120_DvUp0	 BUFFER[10465]	//(internal1_m1120_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1120_DvUp0	 1540	//(internal1_m1120_DvUp0) - есть команда на движение вперёд
#define internal1_m1120_DvDw0	 BUFFER[10466]	//(internal1_m1120_DvDw0) - есть команда на движение назад
#define idinternal1_m1120_DvDw0	 1541	//(internal1_m1120_DvDw0) - есть команда на движение назад
#define internal1_m1120_FDvUp0	 BUFFER[10467]	//(internal1_m1120_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1120_FDvUp0	 1542	//(internal1_m1120_FDvUp0) - есть команда на движение вперёд
#define internal1_m1120_FDvDw0	 BUFFER[10468]	//(internal1_m1120_FDvDw0) - есть команда на движение назад
#define idinternal1_m1120_FDvDw0	 1543	//(internal1_m1120_FDvDw0) - есть команда на движение назад
#define internal1_m1120_BlDv0	 BUFFER[10469]	//(internal1_m1120_BlDv0) - была блокировка
#define idinternal1_m1120_BlDv0	 1544	//(internal1_m1120_BlDv0) - была блокировка
#define internal1_m1120_Pkv0	 BUFFER[10470]	//(internal1_m1120_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1120_Pkv0	 1545	//(internal1_m1120_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1120_Pkav0	 BUFFER[10471]	//(internal1_m1120_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1120_Pkav0	 1546	//(internal1_m1120_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1120_Zkv0	 BUFFER[10472]	//(internal1_m1120_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1120_Zkv0	 1547	//(internal1_m1120_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1120_Zkav0	 BUFFER[10473]	//(internal1_m1120_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1120_Zkav0	 1548	//(internal1_m1120_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1120_txNm	 BUFFER[10474]	//(internal1_m1120_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1120_txNm	 1549	//(internal1_m1120_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1120_txSm	 BUFFER[10479]	//(internal1_m1120_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1120_txSm	 1550	//(internal1_m1120_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1120_txHr	 BUFFER[10484]	//(internal1_m1120_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1120_txHr	 1551	//(internal1_m1120_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1120_txLd	 BUFFER[10489]	//(internal1_m1120_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1120_txLd	 1552	//(internal1_m1120_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1120_fef	 BUFFER[10494]	//(internal1_m1120_fef) fef
#define idinternal1_m1120_fef	 1553	//(internal1_m1120_fef) fef
#define internal1_m1138_xptr	 BUFFER[10495]	//(internal1_m1138_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1138_xptr	 1554	//(internal1_m1138_xptr) указатель текущей позиции в массиве координат
#define internal1_m1138_x0	 BUFFER[10498]	//(internal1_m1138_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1138_x0	 1555	//(internal1_m1138_x0) x0 - массив мгновенных значений координат
#define internal1_m1138_tim0	 BUFFER[10598]	//(internal1_m1138_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1138_tim0	 1556	//(internal1_m1138_tim0) tim0 - массив значений времени цикла
#define internal1_m1138_mcount	 BUFFER[10698]	//(internal1_m1138_mcount) count - счетчик заполнения массива значений координат
#define idinternal1_m1138_mcount	 1557	//(internal1_m1138_mcount) count - счетчик заполнения массива значений координат
#define internal1_m1138_sumtim	 BUFFER[10701]	//(internal1_m1138_sumtim) sumtim - время в пути
#define idinternal1_m1138_sumtim	 1558	//(internal1_m1138_sumtim) sumtim - время в пути
#define internal1_m1138_sumtakt	 BUFFER[10706]	//(internal1_m1138_sumtakt) sumtim - время в пути
#define idinternal1_m1138_sumtakt	 1559	//(internal1_m1138_sumtakt) sumtim - время в пути
#define internal1_m1138_StSpeed	 BUFFER[10711]	//(internal1_m1138_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1138_StSpeed	 1560	//(internal1_m1138_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1138_Vz0	 BUFFER[10716]	//(internal1_m1138_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1138_Vz0	 1561	//(internal1_m1138_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1138_flRazg	 BUFFER[10721]	//(internal1_m1138_flRazg) признак разгона/торможения
#define idinternal1_m1138_flRazg	 1562	//(internal1_m1138_flRazg) признак разгона/торможения
#define internal1_m1138_DelSp	 BUFFER[10724]	//(internal1_m1138_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1138_DelSp	 1563	//(internal1_m1138_DelSp) DelSp - время переключения скоростей
#define internal1_m1138_z0	 BUFFER[10729]	//(internal1_m1138_z0) z0 - точка прекращения движения
#define idinternal1_m1138_z0	 1564	//(internal1_m1138_z0) z0 - точка прекращения движения
#define internal1_m1138_txZS	 BUFFER[10734]	//(internal1_m1138_txZS) txZS
#define idinternal1_m1138_txZS	 1565	//(internal1_m1138_txZS) txZS
#define internal1_m1138_tx	 BUFFER[10739]	//(internal1_m1138_tx) tx
#define idinternal1_m1138_tx	 1566	//(internal1_m1138_tx) tx
#define internal1_m1138_txd	 BUFFER[10744]	//(internal1_m1138_txd) txd
#define idinternal1_m1138_txd	 1567	//(internal1_m1138_txd) txd
#define internal1_m1138_txMBl	 BUFFER[10749]	//(internal1_m1138_txMBl) tx
#define idinternal1_m1138_txMBl	 1568	//(internal1_m1138_txMBl) tx
#define internal1_m1138_txBl	 BUFFER[10754]	//(internal1_m1138_txBl) tx
#define idinternal1_m1138_txBl	 1569	//(internal1_m1138_txBl) tx
#define internal1_m1138_Speed0	 BUFFER[10759]	//(internal1_m1138_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1138_Speed0	 1570	//(internal1_m1138_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1138_xz0	 BUFFER[10764]	//(internal1_m1138_xz0) xz0 - новое задание мм
#define idinternal1_m1138_xz0	 1571	//(internal1_m1138_xz0) xz0 - новое задание мм
#define internal1_m1138_tz0	 BUFFER[10769]	//(internal1_m1138_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1138_tz0	 1572	//(internal1_m1138_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1138_Shift0	 BUFFER[10774]	//(internal1_m1138_Shift0) Shift0 - признак самохода
#define idinternal1_m1138_Shift0	 1573	//(internal1_m1138_Shift0) Shift0 - признак самохода
#define internal1_m1138_ShCntlSp0	 BUFFER[10776]	//(internal1_m1138_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1138_ShCntlSp0	 1574	//(internal1_m1138_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1138_ShiftControl	 BUFFER[10778]	//(internal1_m1138_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1138_ShiftControl	 1575	//(internal1_m1138_ShiftControl) ShiftControl - признак самохода
#define internal1_m738_x0	 BUFFER[10780]	//(internal1_m738_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m738_x0	 1576	//(internal1_m738_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m708_x0	 BUFFER[10782]	//(internal1_m708_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m708_x0	 1577	//(internal1_m708_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m670_x0	 BUFFER[10784]	//(internal1_m670_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m670_x0	 1578	//(internal1_m670_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m765_q0	 BUFFER[10786]	//(internal1_m765_q0) q0 - внутренний параметр
#define idinternal1_m765_q0	 1579	//(internal1_m765_q0) q0 - внутренний параметр
#define internal1_m759_q0	 BUFFER[10788]	//(internal1_m759_q0) q0 - внутренний параметр
#define idinternal1_m759_q0	 1580	//(internal1_m759_q0) q0 - внутренний параметр
#define internal1_m726_q0	 BUFFER[10790]	//(internal1_m726_q0) q0 - внутренний параметр
#define idinternal1_m726_q0	 1581	//(internal1_m726_q0) q0 - внутренний параметр
#define internal1_m731_q0	 BUFFER[10792]	//(internal1_m731_q0) q0 - внутренний параметр
#define idinternal1_m731_q0	 1582	//(internal1_m731_q0) q0 - внутренний параметр
#define internal1_m739_q0	 BUFFER[10794]	//(internal1_m739_q0) q0 - внутренний параметр
#define idinternal1_m739_q0	 1583	//(internal1_m739_q0) q0 - внутренний параметр
#define internal1_m751_q0	 BUFFER[10796]	//(internal1_m751_q0) q0 - внутренний параметр
#define idinternal1_m751_q0	 1584	//(internal1_m751_q0) q0 - внутренний параметр
#define internal1_m729_q0	 BUFFER[10798]	//(internal1_m729_q0) q0 - внутренний параметр
#define idinternal1_m729_q0	 1585	//(internal1_m729_q0) q0 - внутренний параметр
#define internal1_m1175_DvUp0	 BUFFER[10800]	//(internal1_m1175_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1175_DvUp0	 1586	//(internal1_m1175_DvUp0) - есть команда на движение вперёд
#define internal1_m1175_DvDw0	 BUFFER[10801]	//(internal1_m1175_DvDw0) - есть команда на движение назад
#define idinternal1_m1175_DvDw0	 1587	//(internal1_m1175_DvDw0) - есть команда на движение назад
#define internal1_m1175_FDvUp0	 BUFFER[10802]	//(internal1_m1175_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1175_FDvUp0	 1588	//(internal1_m1175_FDvUp0) - есть команда на движение вперёд
#define internal1_m1175_FDvDw0	 BUFFER[10803]	//(internal1_m1175_FDvDw0) - есть команда на движение назад
#define idinternal1_m1175_FDvDw0	 1589	//(internal1_m1175_FDvDw0) - есть команда на движение назад
#define internal1_m1175_BlDv0	 BUFFER[10804]	//(internal1_m1175_BlDv0) - была блокировка
#define idinternal1_m1175_BlDv0	 1590	//(internal1_m1175_BlDv0) - была блокировка
#define internal1_m1175_Pkv0	 BUFFER[10805]	//(internal1_m1175_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1175_Pkv0	 1591	//(internal1_m1175_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1175_Pkav0	 BUFFER[10806]	//(internal1_m1175_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1175_Pkav0	 1592	//(internal1_m1175_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1175_Zkv0	 BUFFER[10807]	//(internal1_m1175_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1175_Zkv0	 1593	//(internal1_m1175_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1175_Zkav0	 BUFFER[10808]	//(internal1_m1175_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1175_Zkav0	 1594	//(internal1_m1175_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1175_txNm	 BUFFER[10809]	//(internal1_m1175_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1175_txNm	 1595	//(internal1_m1175_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1175_txSm	 BUFFER[10814]	//(internal1_m1175_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1175_txSm	 1596	//(internal1_m1175_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1175_txHr	 BUFFER[10819]	//(internal1_m1175_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1175_txHr	 1597	//(internal1_m1175_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1175_txLd	 BUFFER[10824]	//(internal1_m1175_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1175_txLd	 1598	//(internal1_m1175_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1175_fef	 BUFFER[10829]	//(internal1_m1175_fef) fef
#define idinternal1_m1175_fef	 1599	//(internal1_m1175_fef) fef
#define internal1_m1165_DvUp0	 BUFFER[10830]	//(internal1_m1165_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1165_DvUp0	 1600	//(internal1_m1165_DvUp0) - есть команда на движение вперёд
#define internal1_m1165_DvDw0	 BUFFER[10831]	//(internal1_m1165_DvDw0) - есть команда на движение назад
#define idinternal1_m1165_DvDw0	 1601	//(internal1_m1165_DvDw0) - есть команда на движение назад
#define internal1_m1165_FDvUp0	 BUFFER[10832]	//(internal1_m1165_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1165_FDvUp0	 1602	//(internal1_m1165_FDvUp0) - есть команда на движение вперёд
#define internal1_m1165_FDvDw0	 BUFFER[10833]	//(internal1_m1165_FDvDw0) - есть команда на движение назад
#define idinternal1_m1165_FDvDw0	 1603	//(internal1_m1165_FDvDw0) - есть команда на движение назад
#define internal1_m1165_BlDv0	 BUFFER[10834]	//(internal1_m1165_BlDv0) - была блокировка
#define idinternal1_m1165_BlDv0	 1604	//(internal1_m1165_BlDv0) - была блокировка
#define internal1_m1165_Pkv0	 BUFFER[10835]	//(internal1_m1165_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1165_Pkv0	 1605	//(internal1_m1165_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1165_Pkav0	 BUFFER[10836]	//(internal1_m1165_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1165_Pkav0	 1606	//(internal1_m1165_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1165_Zkv0	 BUFFER[10837]	//(internal1_m1165_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1165_Zkv0	 1607	//(internal1_m1165_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1165_Zkav0	 BUFFER[10838]	//(internal1_m1165_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1165_Zkav0	 1608	//(internal1_m1165_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1165_txNm	 BUFFER[10839]	//(internal1_m1165_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1165_txNm	 1609	//(internal1_m1165_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1165_txSm	 BUFFER[10844]	//(internal1_m1165_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1165_txSm	 1610	//(internal1_m1165_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1165_txHr	 BUFFER[10849]	//(internal1_m1165_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1165_txHr	 1611	//(internal1_m1165_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1165_txLd	 BUFFER[10854]	//(internal1_m1165_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1165_txLd	 1612	//(internal1_m1165_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1165_fef	 BUFFER[10859]	//(internal1_m1165_fef) fef
#define idinternal1_m1165_fef	 1613	//(internal1_m1165_fef) fef
#define internal1_m785_DvUp0	 BUFFER[10860]	//(internal1_m785_DvUp0) - есть команда на движение вперёд
#define idinternal1_m785_DvUp0	 1614	//(internal1_m785_DvUp0) - есть команда на движение вперёд
#define internal1_m785_DvDw0	 BUFFER[10861]	//(internal1_m785_DvDw0) - есть команда на движение назад
#define idinternal1_m785_DvDw0	 1615	//(internal1_m785_DvDw0) - есть команда на движение назад
#define internal1_m785_FDvUp0	 BUFFER[10862]	//(internal1_m785_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m785_FDvUp0	 1616	//(internal1_m785_FDvUp0) - есть команда на движение вперёд
#define internal1_m785_FDvDw0	 BUFFER[10863]	//(internal1_m785_FDvDw0) - есть команда на движение назад
#define idinternal1_m785_FDvDw0	 1617	//(internal1_m785_FDvDw0) - есть команда на движение назад
#define internal1_m785_BlDv0	 BUFFER[10864]	//(internal1_m785_BlDv0) - была блокировка
#define idinternal1_m785_BlDv0	 1618	//(internal1_m785_BlDv0) - была блокировка
#define internal1_m785_Pkv0	 BUFFER[10865]	//(internal1_m785_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m785_Pkv0	 1619	//(internal1_m785_Pkv0) Pkv - передний конечный выключатель
#define internal1_m785_Pkav0	 BUFFER[10866]	//(internal1_m785_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m785_Pkav0	 1620	//(internal1_m785_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m785_Zkv0	 BUFFER[10867]	//(internal1_m785_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m785_Zkv0	 1621	//(internal1_m785_Zkv0) Zkv - задний конечный выключатель
#define internal1_m785_Zkav0	 BUFFER[10868]	//(internal1_m785_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m785_Zkav0	 1622	//(internal1_m785_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m785_txNm	 BUFFER[10869]	//(internal1_m785_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m785_txNm	 1623	//(internal1_m785_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m785_txSm	 BUFFER[10874]	//(internal1_m785_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m785_txSm	 1624	//(internal1_m785_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m785_txHr	 BUFFER[10879]	//(internal1_m785_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m785_txHr	 1625	//(internal1_m785_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m785_txLd	 BUFFER[10884]	//(internal1_m785_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m785_txLd	 1626	//(internal1_m785_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m785_fef	 BUFFER[10889]	//(internal1_m785_fef) fef
#define idinternal1_m785_fef	 1627	//(internal1_m785_fef) fef
#define internal1_m781_DvUp0	 BUFFER[10890]	//(internal1_m781_DvUp0) - есть команда на движение вперёд
#define idinternal1_m781_DvUp0	 1628	//(internal1_m781_DvUp0) - есть команда на движение вперёд
#define internal1_m781_DvDw0	 BUFFER[10891]	//(internal1_m781_DvDw0) - есть команда на движение назад
#define idinternal1_m781_DvDw0	 1629	//(internal1_m781_DvDw0) - есть команда на движение назад
#define internal1_m781_FDvUp0	 BUFFER[10892]	//(internal1_m781_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m781_FDvUp0	 1630	//(internal1_m781_FDvUp0) - есть команда на движение вперёд
#define internal1_m781_FDvDw0	 BUFFER[10893]	//(internal1_m781_FDvDw0) - есть команда на движение назад
#define idinternal1_m781_FDvDw0	 1631	//(internal1_m781_FDvDw0) - есть команда на движение назад
#define internal1_m781_BlDv0	 BUFFER[10894]	//(internal1_m781_BlDv0) - была блокировка
#define idinternal1_m781_BlDv0	 1632	//(internal1_m781_BlDv0) - была блокировка
#define internal1_m781_Pkv0	 BUFFER[10895]	//(internal1_m781_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m781_Pkv0	 1633	//(internal1_m781_Pkv0) Pkv - передний конечный выключатель
#define internal1_m781_Pkav0	 BUFFER[10896]	//(internal1_m781_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m781_Pkav0	 1634	//(internal1_m781_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m781_Zkv0	 BUFFER[10897]	//(internal1_m781_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m781_Zkv0	 1635	//(internal1_m781_Zkv0) Zkv - задний конечный выключатель
#define internal1_m781_Zkav0	 BUFFER[10898]	//(internal1_m781_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m781_Zkav0	 1636	//(internal1_m781_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m781_txNm	 BUFFER[10899]	//(internal1_m781_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m781_txNm	 1637	//(internal1_m781_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m781_txSm	 BUFFER[10904]	//(internal1_m781_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m781_txSm	 1638	//(internal1_m781_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m781_txHr	 BUFFER[10909]	//(internal1_m781_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m781_txHr	 1639	//(internal1_m781_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m781_txLd	 BUFFER[10914]	//(internal1_m781_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m781_txLd	 1640	//(internal1_m781_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m781_fef	 BUFFER[10919]	//(internal1_m781_fef) fef
#define idinternal1_m781_fef	 1641	//(internal1_m781_fef) fef
#define internal1_m347_DvUp0	 BUFFER[10920]	//(internal1_m347_DvUp0) - есть команда на движение вперёд
#define idinternal1_m347_DvUp0	 1642	//(internal1_m347_DvUp0) - есть команда на движение вперёд
#define internal1_m347_DvDw0	 BUFFER[10921]	//(internal1_m347_DvDw0) - есть команда на движение назад
#define idinternal1_m347_DvDw0	 1643	//(internal1_m347_DvDw0) - есть команда на движение назад
#define internal1_m347_FDvUp0	 BUFFER[10922]	//(internal1_m347_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m347_FDvUp0	 1644	//(internal1_m347_FDvUp0) - есть команда на движение вперёд
#define internal1_m347_FDvDw0	 BUFFER[10923]	//(internal1_m347_FDvDw0) - есть команда на движение назад
#define idinternal1_m347_FDvDw0	 1645	//(internal1_m347_FDvDw0) - есть команда на движение назад
#define internal1_m347_BlDv0	 BUFFER[10924]	//(internal1_m347_BlDv0) - была блокировка
#define idinternal1_m347_BlDv0	 1646	//(internal1_m347_BlDv0) - была блокировка
#define internal1_m347_Pkv0	 BUFFER[10925]	//(internal1_m347_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m347_Pkv0	 1647	//(internal1_m347_Pkv0) Pkv - передний конечный выключатель
#define internal1_m347_Pkav0	 BUFFER[10926]	//(internal1_m347_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m347_Pkav0	 1648	//(internal1_m347_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m347_Zkv0	 BUFFER[10927]	//(internal1_m347_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m347_Zkv0	 1649	//(internal1_m347_Zkv0) Zkv - задний конечный выключатель
#define internal1_m347_Zkav0	 BUFFER[10928]	//(internal1_m347_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m347_Zkav0	 1650	//(internal1_m347_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m347_txNm	 BUFFER[10929]	//(internal1_m347_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m347_txNm	 1651	//(internal1_m347_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m347_txSm	 BUFFER[10934]	//(internal1_m347_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m347_txSm	 1652	//(internal1_m347_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m347_txHr	 BUFFER[10939]	//(internal1_m347_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m347_txHr	 1653	//(internal1_m347_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m347_txLd	 BUFFER[10944]	//(internal1_m347_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m347_txLd	 1654	//(internal1_m347_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m347_fef	 BUFFER[10949]	//(internal1_m347_fef) fef
#define idinternal1_m347_fef	 1655	//(internal1_m347_fef) fef
#define internal1_m391_DvUp0	 BUFFER[10950]	//(internal1_m391_DvUp0) - есть команда на движение вперёд
#define idinternal1_m391_DvUp0	 1656	//(internal1_m391_DvUp0) - есть команда на движение вперёд
#define internal1_m391_DvDw0	 BUFFER[10951]	//(internal1_m391_DvDw0) - есть команда на движение назад
#define idinternal1_m391_DvDw0	 1657	//(internal1_m391_DvDw0) - есть команда на движение назад
#define internal1_m391_FDvUp0	 BUFFER[10952]	//(internal1_m391_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m391_FDvUp0	 1658	//(internal1_m391_FDvUp0) - есть команда на движение вперёд
#define internal1_m391_FDvDw0	 BUFFER[10953]	//(internal1_m391_FDvDw0) - есть команда на движение назад
#define idinternal1_m391_FDvDw0	 1659	//(internal1_m391_FDvDw0) - есть команда на движение назад
#define internal1_m391_BlDv0	 BUFFER[10954]	//(internal1_m391_BlDv0) - была блокировка
#define idinternal1_m391_BlDv0	 1660	//(internal1_m391_BlDv0) - была блокировка
#define internal1_m391_Pkv0	 BUFFER[10955]	//(internal1_m391_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m391_Pkv0	 1661	//(internal1_m391_Pkv0) Pkv - передний конечный выключатель
#define internal1_m391_Pkav0	 BUFFER[10956]	//(internal1_m391_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m391_Pkav0	 1662	//(internal1_m391_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m391_Zkv0	 BUFFER[10957]	//(internal1_m391_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m391_Zkv0	 1663	//(internal1_m391_Zkv0) Zkv - задний конечный выключатель
#define internal1_m391_Zkav0	 BUFFER[10958]	//(internal1_m391_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m391_Zkav0	 1664	//(internal1_m391_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m391_txNm	 BUFFER[10959]	//(internal1_m391_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m391_txNm	 1665	//(internal1_m391_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m391_txSm	 BUFFER[10964]	//(internal1_m391_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m391_txSm	 1666	//(internal1_m391_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m391_txHr	 BUFFER[10969]	//(internal1_m391_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m391_txHr	 1667	//(internal1_m391_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m391_txLd	 BUFFER[10974]	//(internal1_m391_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m391_txLd	 1668	//(internal1_m391_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m391_fef	 BUFFER[10979]	//(internal1_m391_fef) fef
#define idinternal1_m391_fef	 1669	//(internal1_m391_fef) fef
#define internal1_m385_DvUp0	 BUFFER[10980]	//(internal1_m385_DvUp0) - есть команда на движение вперёд
#define idinternal1_m385_DvUp0	 1670	//(internal1_m385_DvUp0) - есть команда на движение вперёд
#define internal1_m385_DvDw0	 BUFFER[10981]	//(internal1_m385_DvDw0) - есть команда на движение назад
#define idinternal1_m385_DvDw0	 1671	//(internal1_m385_DvDw0) - есть команда на движение назад
#define internal1_m385_FDvUp0	 BUFFER[10982]	//(internal1_m385_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m385_FDvUp0	 1672	//(internal1_m385_FDvUp0) - есть команда на движение вперёд
#define internal1_m385_FDvDw0	 BUFFER[10983]	//(internal1_m385_FDvDw0) - есть команда на движение назад
#define idinternal1_m385_FDvDw0	 1673	//(internal1_m385_FDvDw0) - есть команда на движение назад
#define internal1_m385_BlDv0	 BUFFER[10984]	//(internal1_m385_BlDv0) - была блокировка
#define idinternal1_m385_BlDv0	 1674	//(internal1_m385_BlDv0) - была блокировка
#define internal1_m385_Pkv0	 BUFFER[10985]	//(internal1_m385_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m385_Pkv0	 1675	//(internal1_m385_Pkv0) Pkv - передний конечный выключатель
#define internal1_m385_Pkav0	 BUFFER[10986]	//(internal1_m385_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m385_Pkav0	 1676	//(internal1_m385_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m385_Zkv0	 BUFFER[10987]	//(internal1_m385_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m385_Zkv0	 1677	//(internal1_m385_Zkv0) Zkv - задний конечный выключатель
#define internal1_m385_Zkav0	 BUFFER[10988]	//(internal1_m385_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m385_Zkav0	 1678	//(internal1_m385_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m385_txNm	 BUFFER[10989]	//(internal1_m385_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m385_txNm	 1679	//(internal1_m385_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m385_txSm	 BUFFER[10994]	//(internal1_m385_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m385_txSm	 1680	//(internal1_m385_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m385_txHr	 BUFFER[10999]	//(internal1_m385_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m385_txHr	 1681	//(internal1_m385_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m385_txLd	 BUFFER[11004]	//(internal1_m385_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m385_txLd	 1682	//(internal1_m385_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m385_fef	 BUFFER[11009]	//(internal1_m385_fef) fef
#define idinternal1_m385_fef	 1683	//(internal1_m385_fef) fef
#define internal1_m735_q0	 BUFFER[11010]	//(internal1_m735_q0) q0 - внутренний параметр
#define idinternal1_m735_q0	 1684	//(internal1_m735_q0) q0 - внутренний параметр
#define internal1_m732_q0	 BUFFER[11012]	//(internal1_m732_q0) q0 - внутренний параметр
#define idinternal1_m732_q0	 1685	//(internal1_m732_q0) q0 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,4	,1	, &gray01},	//(gray01) - в грее
	{ 2	,4	,1	, &gray02},	//(gray02) - в грее
	{ 3	,4	,1	, &gray03},	//(gray03) - в грее
	{ 4	,4	,1	, &gray04},	//(gray04) - в грее
	{ 5	,4	,1	, &gray05},	//(gray05) - в грее
	{ 6	,4	,1	, &gray06},	//(gray06) - в грее
	{ 7	,4	,1	, &gray07},	//(gray07) - в грее
	{ 8	,4	,1	, &gray08},	//(gray08) - в грее
	{ 9	,5	,1	, &venc01},	//(venc01) - посчитанный
	{ 10	,5	,1	, &venc02},	//(venc02) - посчитанный
	{ 11	,5	,1	, &venc03},	//(venc03) - посчитанный
	{ 12	,5	,1	, &venc04},	//(venc04) - посчитанный
	{ 13	,5	,1	, &venc05},	//(venc05) - посчитанный
	{ 14	,5	,1	, &venc06},	//(venc06) - посчитанный
	{ 15	,5	,1	, &venc07},	//(venc07) - посчитанный
	{ 16	,5	,1	, &venc08},	//(venc08) - посчитанный
	{ 17	,1	,1	, &B3MD12LP1},	//(B3MD12LP1) Переключатель «РАЗРЕШИТЬ» ИС2
	{ 18	,1	,1	, &B3MD11LP1},	//(B3MD11LP1) Кнопка «ПУСК ИС2»
	{ 19	,8	,1	, &R0VL01RDU},	//(R0VL01RDU) Индикация Время задержки
	{ 20	,1	,1	, &R0VZ71LZ2},	//(R0VZ71LZ2) Обобщенный сигнал АЗ 2 канала
	{ 21	,1	,1	, &R0VZ71LZ1},	//(R0VZ71LZ1) Обобщенный сигнал АЗ 1канала
	{ 22	,1	,1	, &R0VZ71LDU},	//(R0VZ71LDU) Обобщенный сигнал АЗ
	{ 23	,1	,1	, &A2IS33LDU},	//(A2IS33LDU) Клапан «Подъём РБ1» открыт (обесточен)
	{ 24	,1	,1	, &A3IS31LDU},	//(A3IS31LDU) Клапан «СПУСК ИС1» открыт (обесточен)
	{ 25	,1	,1	, &A3IS33LDU},	//(A3IS33LDU) Клапан «ВЫСТРЕЛ ИС1» открыт (обесточен)
	{ 26	,1	,1	, &A3IS35LDU},	//(A3IS35LDU) Клапан «ВПИС1» открыт (обесточен)
	{ 27	,1	,1	, &A4IS10LDU},	//(A4IS10LDU) Клапан «Подъём НИ1» открыт (обесточен)
	{ 28	,1	,1	, &A1VN71LZ1},	//(A1VN71LZ1) Блокировка автоматического подъёма ББ
	{ 29	,1	,1	, &A1VN71LZ2},	//(A1VN71LZ2) Блокировка автоматического подъёма ББ
	{ 30	,1	,1	, &A1AB19LDU},	//(A1AB19LDU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
	{ 31	,1	,1	, &R0AD14LZ1},	//(R0AD14LZ1) Имитация срабатывания АЗ от II УР
	{ 32	,1	,1	, &R0AD14LZ2},	//(R0AD14LZ2) Имитация срабатывания АЗ от  II УР
	{ 33	,1	,1	, &A3VZ13LZ2},	//(A3VZ13LZ2) Имитация срабатывания АЗ от ВУ ИС
	{ 34	,1	,1	, &A3VZ13LZ1},	//(A3VZ13LZ1) Имитация срабатывания АЗ от ВУ ИС
	{ 35	,1	,1	, &A3VZ15LZ1},	//(A3VZ15LZ1) Имитация срабатывания АЗ от НУП ИС
	{ 36	,1	,1	, &A3VZ15LZ2},	//(A3VZ15LZ2) Имитация срабатывания АЗ от НУП ИС
	{ 37	,1	,1	, &B2IS33LDU},	//(B2IS33LDU) Клапан «Подъём РБ2» открыт (обесточен)
	{ 38	,1	,1	, &B3IS31LDU},	//(B3IS31LDU) Клапан «СПУСК ИС2» открыт (обесточен)
	{ 39	,1	,1	, &B1MD11LP1},	//(B1MD11LP1) Кнопка «ПУСК ББ2»
	{ 40	,1	,1	, &B1MD12LP1},	//(B1MD12LP1) Переключатель «РАЗРЕШИТЬ» ББ2
	{ 41	,1	,1	, &B2MD11LP1},	//(B2MD11LP1) Кнопка «ПУСК РБ2»
	{ 42	,1	,1	, &B2MD12LP1},	//(B2MD12LP1) Переключатель «РАЗРЕШИТЬ» РБ2
	{ 43	,1	,1	, &A2MD11LP1},	//(A2MD11LP1) Кнопка «ПУСК РБ1»
	{ 44	,1	,1	, &A2MD12LP1},	//(A2MD12LP1) Переключатель «РАЗРЕШИТЬ» РБ1
	{ 45	,1	,1	, &R0IS01LDU},	//(R0IS01LDU) Признак работы с имитатором
	{ 46	,1	,1	, &R0IS02LDU},	//(R0IS02LDU) Разрешение ввода от имитатора
	{ 47	,1	,1	, &R0VP73LZ1},	//(R0VP73LZ1) ПС давления для РУ
	{ 48	,1	,1	, &R0VP73LZ2},	//(R0VP73LZ2) ПС давления для РУ
	{ 49	,1	,1	, &R0VP73LDU},	//(R0VP73LDU) ПС давления для РУ
	{ 50	,1	,1	, &R0MD34LP1},	//(R0MD34LP1) Кнопка «Квитировать»
	{ 51	,1	,1	, &A0VT71LZ1},	//(A0VT71LZ1) АС по температуре в АЗ1
	{ 52	,1	,1	, &B0VT71LZ1},	//(B0VT71LZ1) АС по температуре в АЗ2
	{ 53	,1	,1	, &A0VT71LZ2},	//(A0VT71LZ2) АС по температуре в АЗ1
	{ 54	,1	,1	, &B0VT71LZ2},	//(B0VT71LZ2) АС по температуре в АЗ2
	{ 55	,1	,1	, &B2VS11LDU},	//(B2VS11LDU) Движение РБ2 в сторону ВУ
	{ 56	,1	,1	, &B2VS21LDU},	//(B2VS21LDU) Движение РБ2 в сторону НУ
	{ 57	,3	,1	, &B2VS01IDU},	//(B2VS01IDU) Готовность к управлению РБ2
	{ 58	,1	,1	, &A7AS31LDU},	//(A7AS31LDU) Клапан «Обдув АЗ1» открыт (обесточен)
	{ 59	,1	,1	, &B7AS31LDU},	//(B7AS31LDU) Клапан «Обдув АЗ2» открыт (обесточен)
	{ 60	,1	,1	, &A7AZ03LDU},	//(A7AZ03LDU) Несанкционированное включение обдува АЗ1
	{ 61	,1	,1	, &B7AZ03LDU},	//(B7AZ03LDU) Несанкционированное включение обдува АЗ2
	{ 62	,1	,1	, &R3AD11LDU},	//(R3AD11LDU) Гомогенные двери-2 открыть
	{ 63	,1	,1	, &R3AD21LDU},	//(R3AD21LDU) Гомогенные двери-2 закрыть
	{ 64	,1	,1	, &R3IS41LDU},	//(R3IS41LDU) Приход на НУ гомогенных дверей-2
	{ 65	,1	,1	, &R3IS31LDU},	//(R3IS31LDU) Приход на ВУ гомогенных дверей-2
	{ 66	,1	,1	, &R3VS10LDU},	//(R3VS10LDU) Движение дверей-1 к открыто
	{ 67	,1	,1	, &R0AB03LDU},	//(R0AB03LDU) Нарушение времени срабатывания АЗ от ВУ ИС
	{ 68	,1	,1	, &R0AB05LDU},	//(R0AB05LDU) Нарушение времени срабатывания АЗ от НУП ИС
	{ 69	,8	,1	, &R0VN11RZ1},	//(R0VN11RZ1) Средняя мощность по BAZ1
	{ 70	,8	,1	, &R0VN11RZ2},	//(R0VN11RZ2) Средняя мощность по BAZ2
	{ 71	,1	,1	, &A2AB15LDU},	//(A2AB15LDU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{ 72	,1	,1	, &B2AB15LDU},	//(B2AB15LDU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{ 73	,1	,1	, &R0AD21LDU},	//(R0AD21LDU) Подключить защиту от II УР
	{ 74	,1	,1	, &R0VX02LDU},	//(R0VX02LDU) Импульс разрешен
	{ 75	,1	,1	, &R0EE03LDU},	//(R0EE03LDU) ВПИС ИС
	{ 76	,1	,1	, &R0AB07LDU},	//(R0AB07LDU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
	{ 77	,1	,1	, &R0AD16LDU},	//(R0AD16LDU) Контроль  I-II УР. РАД
	{ 78	,1	,1	, &C2MD31LP1},	//(C2MD31LP1) Кнопка «СБРОС РБ»
	{ 79	,3	,1	, &B6VS01IDU},	//(B6VS01IDU) Готовность к управлению БЗ2
	{ 80	,3	,1	, &R3VS32IDU},	//(R3VS32IDU) Готовность к управлению гомогенных дверей-2
	{ 81	,1	,1	, &R3VS22LDU},	//(R3VS22LDU) Движение дверей-2  к закрыто
	{ 82	,1	,1	, &R3VS11LDU},	//(R3VS11LDU) Движение дверей-2 к открыто
	{ 83	,1	,1	, &R3IS22LDU},	//(R3IS22LDU) Приход на НУ гомогенных дверей
	{ 84	,1	,1	, &B3IS33LDU},	//(B3IS33LDU) Клапан «ВЫСТРЕЛ ИС2» открыт (обесточен)
	{ 85	,1	,1	, &B3IS35LDU},	//(B3IS35LDU) Клапан «ВПИС2» открыт (обесточен)
	{ 86	,1	,1	, &B4IS10LDU},	//(B4IS10LDU) Клапан «Подъём НИ2» открыт (обесточен)
	{ 87	,1	,1	, &R6IS31LDU},	//(R6IS31LDU) контроль задней двери ШС
	{ 88	,1	,1	, &R6IS32LDU},	//(R6IS32LDU) контроль передней двери ШС
	{ 89	,1	,1	, &R6IS42LDU},	//(R6IS42LDU) контроль передней двери ШЭП
	{ 90	,1	,1	, &R6IS41LDU},	//(R6IS41LDU) контроль задней двери ШЭП
	{ 91	,1	,1	, &R6IS52LDU},	//(R6IS52LDU) контроль передней двери ШПУ
	{ 92	,1	,1	, &R6IS51LDU},	//(R6IS51LDU) контроль задней двери ШПУ
	{ 93	,1	,1	, &R3AD10LDU},	//(R3AD10LDU) Гомогенные двери-1 открыть
	{ 94	,1	,1	, &R3AD20LDU},	//(R3AD20LDU) Гомогенные двери-1 закрыть
	{ 95	,1	,1	, &R3IS11LDU},	//(R3IS11LDU) Приход на ВУ гомогенных дверей-1
	{ 96	,1	,1	, &R3IS21LDU},	//(R3IS21LDU) Приход на НУ гомогенных дверей-1
	{ 97	,1	,1	, &R3AZ03LDU},	//(R3AZ03LDU) Несанкционированное перемещение гомогенных дверей
	{ 98	,1	,1	, &R3AB01LDU},	//(R3AB01LDU) Блокировка движения гомогенных дверей - Превышение времени движения
	{ 99	,1	,1	, &R3AB02LDU},	//(R3AB02LDU) Блокировка гомогенных дверей - Нет перемещения
	{ 100	,1	,1	, &R3AB04LDU},	//(R3AB04LDU) Блокировка гомогенных дверей -Ошибка в направлении  движения
	{ 101	,3	,1	, &R3VS30IDU},	//(R3VS30IDU) Готовность к управлению гомогенных дверей-1
	{ 102	,1	,1	, &R3VS20LDU},	//(R3VS20LDU) Движение дверей-1  к закрыто
	{ 103	,1	,1	, &R3AZ13LDU},	//(R3AZ13LDU) Несанкционированное перемещение гомогенных дверей-2
	{ 104	,1	,1	, &R3AB11LDU},	//(R3AB11LDU) Блокировка движения гомогенных дверей-2 - Превышение времени движения
	{ 105	,1	,1	, &R3AB12LDU},	//(R3AB12LDU) Блокировка гомогенных дверей-2 - Нет перемещения
	{ 106	,1	,1	, &R3AB14LDU},	//(R3AB14LDU) Блокировка гомогенных дверей-2 -Ошибка в направлении  движения
	{ 107	,3	,1	, &A2VS01IDU},	//(A2VS01IDU) Готовность к управлению РБ1
	{ 108	,3	,1	, &A4VS01IDU},	//(A4VS01IDU) Готовность к управлению НИ1
	{ 109	,1	,1	, &A4VS12LDU},	//(A4VS12LDU) Движение НИ1 в сторону ВУ
	{ 110	,1	,1	, &A4VS22LDU},	//(A4VS22LDU) Движение НИ1 в сторону НУ
	{ 111	,3	,1	, &B4VS01IDU},	//(B4VS01IDU) Готовность к управлению НИ2
	{ 112	,1	,1	, &B4VS12LDU},	//(B4VS12LDU) Движение НИ2 в сторону ВУ
	{ 113	,1	,1	, &B4VS22LDU},	//(B4VS22LDU) Движение НИ2 в сторону НУ
	{ 114	,3	,1	, &A5VS01IDU},	//(A5VS01IDU) Готовность к управлению НЛ1
	{ 115	,3	,1	, &B5VS01IDU},	//(B5VS01IDU) Готовность к управлению НЛ2
	{ 116	,3	,1	, &A6VS01IDU},	//(A6VS01IDU) Готовность к управлению БЗ1
	{ 117	,3	,1	, &R4VS01IDU},	//(R4VS01IDU) Готовность к управлению тележкой реактора
	{ 118	,1	,1	, &R5AD10LDU},	//(R5AD10LDU) Открыть ворота отстойной зоны
	{ 119	,1	,1	, &R5AD20LDU},	//(R5AD20LDU) Закрыть ворота отстойной зоны
	{ 120	,1	,1	, &R5IS21LDU},	//(R5IS21LDU) Приход на НУ ворот отстойной зоны
	{ 121	,1	,1	, &R5AZ03LDU},	//(R5AZ03LDU) Несанкционированное перемещение ворот отстойной зоны
	{ 122	,1	,1	, &R5AB01LDU},	//(R5AB01LDU) Блокировка движения ворот отстойной зоны - Превышение времени движения
	{ 123	,1	,1	, &R5AB02LDU},	//(R5AB02LDU) Блокировка ворот отстойной зоны - Нет перемещения
	{ 124	,1	,1	, &R5AB04LDU},	//(R5AB04LDU) Блокировка ворот отстойной зоны -Ошибка в направлении  движения
	{ 125	,3	,1	, &R5VS01IDU},	//(R5VS01IDU) Готовность к управлению ворот отстойной зоны
	{ 126	,3	,1	, &R2VS01IDU},	//(R2VS01IDU) Готовность к управлению МДЗ2
	{ 127	,3	,1	, &R1VS01IDU},	//(R1VS01IDU) Готовность к управлению МДЗ1
	{ 128	,1	,1	, &A9IS11LDU},	//(A9IS11LDU) Приход на ВУ НИ ДС1
	{ 129	,3	,1	, &R0VL01IDU},	//(R0VL01IDU) До импульса минут
	{ 130	,3	,1	, &R0VL11IDU},	//(R0VL11IDU) До импульса секунд
	{ 131	,8	,1	, &R0VL06RDU},	//(R0VL06RDU) Индикация (Время задержки от ВУ РБ)
	{ 132	,1	,1	, &B3AD33LDU},	//(B3AD33LDU) Клапан «ВЫСТРЕЛ ИС2» закрыть (обесточить)
	{ 133	,1	,1	, &B3IS11LDU},	//(B3IS11LDU) Приход на ВУ ИС2
	{ 134	,8	,1	, &R0VL02RDU},	//(R0VL02RDU) Индикация (Время задержки ИНИ)
	{ 135	,1	,1	, &R8AD21LDU},	//(R8AD21LDU) Запуск системы инициирования
	{ 136	,1	,1	, &R0AD14LDU},	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
	{ 137	,8	,1	, &R0VL04RDU},	//(R0VL04RDU) Индикация (Время срабатывания верхней АС II УР)
	{ 138	,1	,1	, &R0AB04LDU},	//(R0AB04LDU) Нарушение времени срабатывания верхней АС II УР
	{ 139	,1	,1	, &R0AB06LDU},	//(R0AB06LDU) Нарушение времени задержки от ВУ РБ
	{ 140	,1	,1	, &R0AB02LDU},	//(R0AB02LDU) Нарушение времени задержки ИНИ
	{ 141	,1	,1	, &R0AD13LDU},	//(R0AD13LDU) Имитация прихода на ВУ ИС
	{ 142	,8	,1	, &R0VL03RDU},	//(R0VL03RDU) Индикация (Время срабатывания АЗ от ВУ ИС)
	{ 143	,1	,1	, &R0AD15LDU},	//(R0AD15LDU) Имитация ухода с НУП ИС
	{ 144	,8	,1	, &R0VL05RDU},	//(R0VL05RDU) Индикация (Время срабатывания АЗ от НУП ИС)
	{ 145	,3	,1	, &R0VL21IDU},	//(R0VL21IDU) Декатрон
	{ 146	,1	,1	, &R0VX03LDU},	//(R0VX03LDU) Готовность 2 мин
	{ 147	,3	,1	, &R0VS21IDU},	//(R0VS21IDU) Индикация ВИД ПРОВЕРКИ
	{ 148	,3	,1	, &A1VS01IDU},	//(A1VS01IDU) Готовность к управлению ББ1
	{ 149	,3	,1	, &B1VS01IDU},	//(B1VS01IDU) Готовность к управлению ББ2
	{ 150	,3	,1	, &A3VS01IDU},	//(A3VS01IDU) Готовность к управлению ИС1
	{ 151	,3	,1	, &B3VS01IDU},	//(B3VS01IDU) Готовность к управлению ИС2
	{ 152	,1	,1	, &A3MD12LP1},	//(A3MD12LP1) Переключатель «РАЗРЕШИТЬ» ИС1
	{ 153	,1	,1	, &A3MD11LP1},	//(A3MD11LP1) Кнопка «ПУСК ИС1»
	{ 154	,1	,1	, &R0MD33LP1},	//(R0MD33LP1) Переключатель «РАЗРЕШИТЬ» МДЗ
	{ 155	,1	,1	, &A1MD12LP1},	//(A1MD12LP1) Переключатель «РАЗРЕШИТЬ» ББ1
	{ 156	,1	,1	, &A1MD11LP1},	//(A1MD11LP1) Кнопка «ПУСК ББ1»
	{ 157	,3	,1	, &R0MW14IP2},	//(R0MW14IP2) Переключатель «Обдув»
	{ 158	,1	,1	, &A7AP31LDU},	//(A7AP31LDU) Клапан «Обдув АЗ1» открыть (обесточить)
	{ 159	,1	,1	, &B7AP31LDU},	//(B7AP31LDU) Клапан «Обдув АЗ2» открыть (обесточить)
	{ 160	,3	,1	, &R0MW12IP2},	//(R0MW12IP2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
	{ 161	,1	,1	, &R0MW17LP1},	//(R0MW17LP1) Переключатель «АВТ/Р»
	{ 162	,1	,1	, &R0VW13LDU},	//(R0VW13LDU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{ 163	,1	,1	, &R0VW23LDU},	//(R0VW23LDU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{ 164	,3	,1	, &R0VX08IDU},	//(R0VX08IDU) Индикация Режим
	{ 165	,1	,1	, &R0VX09LDU},	//(R0VX09LDU) Индикация регулятор мощности включен/отключен
	{ 166	,1	,1	, &R0VS17LDU},	//(R0VS17LDU) Индикация выбора АВТОМАТ
	{ 167	,1	,1	, &R5VS12LDU},	//(R5VS12LDU) Движение ворот к открыты
	{ 168	,1	,1	, &R5VS22LDU},	//(R5VS22LDU) Движение ворот к закрыты
	{ 169	,1	,1	, &A2VS32LDU},	//(A2VS32LDU) Индикация  «СБРОС РБ1»
	{ 170	,1	,1	, &B2VS32LDU},	//(B2VS32LDU) Индикация  «СБРОС РБ2»
	{ 171	,1	,1	, &A3VX01LDU},	//(A3VX01LDU) Индикация Выстрел ИС1
	{ 172	,1	,1	, &A3IS11LDU},	//(A3IS11LDU) Приход на ВУ ИС1
	{ 173	,1	,1	, &B3VX01LDU},	//(B3VX01LDU) Индикация Выстрел ИС2
	{ 174	,1	,1	, &R0VS18LDU},	//(R0VS18LDU) Индикация  «Проверка» схем сброса
	{ 175	,1	,1	, &A9IS21LDU},	//(A9IS21LDU) Приход на НУ НИ ДС1
	{ 176	,1	,1	, &B9IS11LDU},	//(B9IS11LDU) Приход на ВУ НИ ДС2
	{ 177	,1	,1	, &B9IS21LDU},	//(B9IS21LDU) Приход на НУ НИ ДС2
	{ 178	,1	,1	, &B9AD10LDU},	//(B9AD10LDU) Открыть клапан Подъем НИ ДС2
	{ 179	,1	,1	, &A9AD10LDU},	//(A9AD10LDU) Открыть клапан Подъем НИ ДС1
	{ 180	,1	,1	, &A9AZ03LDU},	//(A9AZ03LDU) Несанкционированное перемещение НИ ДС1
	{ 181	,1	,1	, &A9AB01LDU},	//(A9AB01LDU) Блокировка движения НИ ДС1 - Превышение времени движения
	{ 182	,1	,1	, &A9AB02LDU},	//(A9AB02LDU) Блокировка НИ ДС1 - Нет перемещения
	{ 183	,1	,1	, &B9AZ03LDU},	//(B9AZ03LDU) Несанкционированное перемещение НИ ДС2
	{ 184	,1	,1	, &B9AB01LDU},	//(B9AB01LDU) Блокировка движения НИ ДС2 - Превышение времени движения
	{ 185	,1	,1	, &B9AB02LDU},	//(B9AB02LDU) Блокировка НИ ДС2 - Нет перемещения
	{ 186	,1	,1	, &R0AB01LDU},	//(R0AB01LDU) Режим проверки разрешён
	{ 187	,1	,1	, &A3IS22LDU},	//(A3IS22LDU) Приход на НУП ИС1
	{ 188	,1	,1	, &B3IS22LDU},	//(B3IS22LDU) Приход на НУП ИС2
	{ 189	,1	,1	, &A2AD33LDU},	//(A2AD33LDU) Клапан «Подъем РБ1» открыть
	{ 190	,1	,1	, &B2AD33LDU},	//(B2AD33LDU) Клапан «Подъем РБ2» открыть
	{ 191	,1	,1	, &A3AD33LDU},	//(A3AD33LDU) Клапан «ВЫСТРЕЛ ИС1» открыть (обесточить)
	{ 192	,1	,1	, &A3AD34LDU},	//(A3AD34LDU) Клапан ВПИС1  открыть (обесточить)
	{ 193	,1	,1	, &A3AD31LDU},	//(A3AD31LDU) Клапан «СПУСК ИС1» открыть (обесточить)
	{ 194	,1	,1	, &B3AD34LDU},	//(B3AD34LDU) Клапан «ВПИС ИС2»  открыть (обесточить)
	{ 195	,1	,1	, &B3AD31LDU},	//(B3AD31LDU) Клапан «СПУСК ИС2» открыть (обесточить)
	{ 196	,1	,1	, &A2IS11LDU},	//(A2IS11LDU) Приход на ВУ РБ1-СТР
	{ 197	,1	,1	, &B2IS11LDU},	//(B2IS11LDU) Приход на ВУ РБ2-СТР
	{ 198	,8	,1	, &B3CP02RDU},	//(B3CP02RDU) Текущее давление ВЫСТРЕЛ ИС2
	{ 199	,1	,1	, &B3VP52LDU},	//(B3VP52LDU) Давление ВЫСТРЕЛ ИС2 ниже ПС
	{ 200	,1	,1	, &B3VP82LDU},	//(B3VP82LDU) Давление ВЫСТРЕЛ ИС2 в норме
	{ 201	,1	,1	, &A3VP82LDU},	//(A3VP82LDU) Давление ВЫСТРЕЛ ИС1 в норме
	{ 202	,3	,1	, &A3IP02IDU},	//(A3IP02IDU) Текущее давление ВЫСТРЕЛ ИС1
	{ 203	,3	,1	, &B3IP02IDU},	//(B3IP02IDU) Текущее давление ВЫСТРЕЛ ИС2
	{ 204	,1	,1	, &A0VE01LDU},	//(A0VE01LDU) Напряжение в системы АЗ1 подано
	{ 205	,1	,1	, &B0VE01LDU},	//(B0VE01LDU) Напряжение в системы АЗ2 подано
	{ 206	,1	,1	, &A0VP01LDU},	//(A0VP01LDU) Давление в системы АЗ1 подано
	{ 207	,1	,1	, &B0VP01LDU},	//(B0VP01LDU) Давление в системы АЗ2 подано
	{ 208	,1	,1	, &A0EE01LZ1},	//(A0EE01LZ1) Исправность АКНП1
	{ 209	,1	,1	, &A0EE03LZ1},	//(A0EE03LZ1) Исправность АКНП3
	{ 210	,1	,1	, &A0EE02LZ1},	//(A0EE02LZ1) Исправность АКНП2
	{ 211	,1	,1	, &A0EE04LZ1},	//(A0EE04LZ1) Исправность АКНП4
	{ 212	,1	,1	, &A0VN01LDU},	//(A0VN01LDU) Каналы АЗ1 проверены
	{ 213	,1	,1	, &B0VN01LDU},	//(B0VN01LDU) Каналы АЗ2 проверены
	{ 214	,1	,1	, &A0EE01LZ2},	//(A0EE01LZ2) Исправность АКНП1
	{ 215	,1	,1	, &A0EE03LZ2},	//(A0EE03LZ2) Исправность АКНП3
	{ 216	,1	,1	, &A0EE02LZ2},	//(A0EE02LZ2) Исправность АКНП2
	{ 217	,1	,1	, &A0EE04LZ2},	//(A0EE04LZ2) Исправность АКНП4
	{ 218	,1	,1	, &A0VP71LZ1},	//(A0VP71LZ1) АЗ по АС любого давления для АЗ1
	{ 219	,1	,1	, &A0VP71LZ2},	//(A0VP71LZ2) АЗ по АС любого давления для АЗ1
	{ 220	,5	,1	, &A1IC01UDU},	//(A1IC01UDU) Координата штока ББ1 (дел.энк)
	{ 221	,8	,1	, &A1VC01RDU},	//(A1VC01RDU) Координата ББ1, мм
	{ 222	,1	,1	, &A1IS11LDU},	//(A1IS11LDU) Приход на ВУ ББ1
	{ 223	,1	,1	, &B1MC01LC1},	//(B1MC01LC1) Настроить энкодер ББ2
	{ 224	,1	,1	, &B1MC01LC2},	//(B1MC01LC2) Настроить энкодер ББ2
	{ 225	,1	,1	, &A1MC01LC1},	//(A1MC01LC1) Настроить энкодер ББ1
	{ 226	,1	,1	, &A1MC01LC2},	//(A1MC01LC2) Настроить энкодер ББ1
	{ 227	,1	,1	, &B2MC01LC1},	//(B2MC01LC1) Настроить энкодер РБ2
	{ 228	,1	,1	, &B2MC01LC2},	//(B2MC01LC2) Настроить энкодер РБ2
	{ 229	,1	,1	, &A2MC01LC1},	//(A2MC01LC1) Настроить энкодер РБ1
	{ 230	,1	,1	, &A2MC01LC2},	//(A2MC01LC2) Настроить энкодер РБ1
	{ 231	,1	,1	, &B3MC01LC1},	//(B3MC01LC1) Настроить энкодер ИС2
	{ 232	,1	,1	, &B3MC01LC2},	//(B3MC01LC2) Настроить энкодер ИС2
	{ 233	,1	,1	, &A3MC01LC1},	//(A3MC01LC1) Настроить энкодер ИС1
	{ 234	,1	,1	, &A3MC01LC2},	//(A3MC01LC2) Настроить энкодер ИС1
	{ 235	,1	,1	, &B8MC01LC1},	//(B8MC01LC1) Настроить энкодер АЗ2
	{ 236	,1	,1	, &B8MC01LC2},	//(B8MC01LC2) Настроить энкодер АЗ2
	{ 237	,1	,1	, &A8MC01LC1},	//(A8MC01LC1) Настроить энкодер ДС2
	{ 238	,1	,1	, &A8MC01LC2},	//(A8MC01LC2) Настроить энкодер ДС2
	{ 239	,1	,1	, &A3VP42LDU},	//(A3VP42LDU) Давление ВЫСТРЕЛ ИС1 ниже АС
	{ 240	,8	,1	, &A3CP02RDU},	//(A3CP02RDU) Текущее давление ВЫСТРЕЛ ИС1
	{ 241	,1	,1	, &A3VP52LDU},	//(A3VP52LDU) Давление ВЫСТРЕЛ ИС1 ниже ПС
	{ 242	,1	,1	, &B3VP42LDU},	//(B3VP42LDU) Давление ВЫСТРЕЛ ИС2 ниже АС
	{ 243	,1	,1	, &R1IE01LDU},	//(R1IE01LDU) Исправность ИП МДЗ1
	{ 244	,1	,1	, &R2IE01LDU},	//(R2IE01LDU) Исправность ИП МДЗ2
	{ 245	,1	,1	, &R6IS61LDU},	//(R6IS61LDU) Исправность 3-х  фазной сети
	{ 246	,1	,1	, &R6IS64LDU},	//(R6IS64LDU) Исправность ВИП ССДИ-35 1канал
	{ 247	,1	,1	, &R6IS65LDU},	//(R6IS65LDU) Исправность ВИП ССДИ-35 2канал
	{ 248	,1	,1	, &R6IS62LDU},	//(R6IS62LDU) Исправность ВИП ССДИ-39 1канал
	{ 249	,1	,1	, &R6IS63LDU},	//(R6IS63LDU) Исправность ВИП ССДИ-39 2канал
	{ 250	,1	,1	, &R6IS66LZ2},	//(R6IS66LZ2) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 251	,1	,1	, &R6IS67LZ1},	//(R6IS67LZ1) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 252	,1	,1	, &R6IS68LZ1},	//(R6IS68LZ1) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 253	,8	,1	, &A3VC01RDU},	//(A3VC01RDU) Координата ИС1, мм
	{ 254	,8	,1	, &A2VC01RDU},	//(A2VC01RDU) Координата РБ1, мм
	{ 255	,8	,1	, &B2VC01RDU},	//(B2VC01RDU) Координата РБ2, мм
	{ 256	,8	,1	, &B8VC01RDU},	//(B8VC01RDU) Координата АЗ2, мм
	{ 257	,1	,1	, &A4VP82LDU},	//(A4VP82LDU) Давление ПОДЪЁМ НИ1 в норме
	{ 258	,1	,1	, &B4VP82LDU},	//(B4VP82LDU) Давление ПОДЪЁМ НИ2 в норме
	{ 259	,1	,1	, &A2VP82LDU},	//(A2VP82LDU) Давление ПОДЪЁМ РБ1 в норме
	{ 260	,1	,1	, &B2VP82LDU},	//(B2VP82LDU) Давление ПОДЪЁМ РБ2 в норме
	{ 261	,1	,1	, &A3VP81LDU},	//(A3VP81LDU) Давление СПУСК ИС1 в норме
	{ 262	,1	,1	, &B3VP81LDU},	//(B3VP81LDU) Давление СПУСК ИС2 в норме
	{ 263	,1	,1	, &R6IS66LZ1},	//(R6IS66LZ1) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 264	,1	,1	, &R6IS67LZ2},	//(R6IS67LZ2) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 265	,1	,1	, &R6IS68LZ2},	//(R6IS68LZ2) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 266	,1	,1	, &B0VP71LZ1},	//(B0VP71LZ1) АЗ по АС любого давления для АЗ2
	{ 267	,1	,1	, &B0VP71LZ2},	//(B0VP71LZ2) АЗ по АС любого давления для АЗ2
	{ 268	,1	,1	, &A0VS11LDU},	//(A0VS11LDU) АЗ1 готова к работе
	{ 269	,1	,1	, &B0VS11LDU},	//(B0VS11LDU) АЗ2 готова к работе
	{ 270	,1	,1	, &A1IE01LDU},	//(A1IE01LDU) Исправность БУШД ББ1
	{ 271	,1	,1	, &A3IE01LDU},	//(A3IE01LDU) Исправность БУШД ИС1
	{ 272	,1	,1	, &A2IE01LDU},	//(A2IE01LDU) Исправность БУШД РБ1
	{ 273	,1	,1	, &A1IE02LDU},	//(A1IE02LDU) Исправность ИП ББ1
	{ 274	,1	,1	, &A3IE02LDU},	//(A3IE02LDU) Исправность ИП ИС1
	{ 275	,1	,1	, &A2IE02LDU},	//(A2IE02LDU) Исправность ИП РБ1
	{ 276	,1	,1	, &B1IE01LDU},	//(B1IE01LDU) Исправность БУШД ББ2
	{ 277	,1	,1	, &B2IE01LDU},	//(B2IE01LDU) Исправность БУШД РБ2
	{ 278	,1	,1	, &B3IE01LDU},	//(B3IE01LDU) Исправность БУШД ИС2
	{ 279	,1	,1	, &B1IE02LDU},	//(B1IE02LDU) Исправность ИП ББ2
	{ 280	,1	,1	, &B3IE02LDU},	//(B3IE02LDU) Исправность ИП ИС2
	{ 281	,1	,1	, &B2IE02LDU},	//(B2IE02LDU) Исправность ИП РБ2
	{ 282	,1	,1	, &R0IE02LDU},	//(R0IE02LDU) Исправность ИП 24 В-1
	{ 283	,1	,1	, &R0IE01LDU},	//(R0IE01LDU) Исправность ИП 24 В-2
	{ 284	,1	,1	, &A6IE01LDU},	//(A6IE01LDU) Исправность ИП БЗ1
	{ 285	,1	,1	, &B6IE01LDU},	//(B6IE01LDU) Исправность ИП БЗ2
	{ 286	,1	,1	, &A8IE01LDU},	//(A8IE01LDU) Исправность ИП ДС2
	{ 287	,1	,1	, &B5IE01LDU},	//(B5IE01LDU) Исправность ИП НЛ2
	{ 288	,1	,1	, &A5IE02LDU},	//(A5IE02LDU) Исправность ИП НЛ1
	{ 289	,8	,1	, &B3MC01RP1},	//(B3MC01RP1) Заданная координата положения ИС2 мм
	{ 290	,8	,1	, &B8MC01RP2},	//(B8MC01RP2) Заданная координата АЗ2 мм
	{ 291	,1	,1	, &R0AB09LDU},	//(R0AB09LDU) Ошибка в заданной координате ББ1
	{ 292	,1	,1	, &R0AB10LDU},	//(R0AB10LDU) Ошибка в заданной координате ББ2
	{ 293	,1	,1	, &R0AB11LDU},	//(R0AB11LDU) Ошибка в заданной координате  ИС1
	{ 294	,1	,1	, &R0AB12LDU},	//(R0AB12LDU) Ошибка в заданной координате  ИС2
	{ 295	,1	,1	, &R0AB13LDU},	//(R0AB13LDU) Ошибка в заданной координате  АЗ2
	{ 296	,1	,1	, &A4ZAV},	//(A4ZAV) 
	{ 297	,1	,1	, &A6ZAV},	//(A6ZAV) 
	{ 298	,1	,1	, &R2ZAV},	//(R2ZAV) 
	{ 299	,1	,1	, &A5ZAV},	//(A5ZAV) 
	{ 300	,1	,1	, &B8ZAV},	//(B8ZAV) 
	{ 301	,1	,1	, &A2ZAV},	//(A2ZAV) Завершение РБ1,2
	{ 302	,1	,1	, &A8ZAV},	//(A8ZAV) 
	{ 303	,1	,1	, &A9ZAV},	//(A9ZAV) Завершение НИ ДС1(2)
	{ 304	,1	,1	, &R4ABL},	//(R4ABL) Блокировка тележки -
	{ 305	,1	,1	, &A4UP},	//(A4UP) 
	{ 306	,1	,1	, &A4DW},	//(A4DW) 
	{ 307	,1	,1	, &R0AB14LDU},	//(R0AB14LDU) Режим проверки не разрешён: ИС2 ниже 55 мм
	{ 308	,1	,1	, &R0AB15LDU},	//(R0AB15LDU) Режим проверки не разрешён: ИС1 ниже 55 мм
	{ 309	,1	,1	, &A3IS12LDU},	//(A3IS12LDU) Приход на ВУ штока ИС1
	{ 310	,1	,1	, &B3IS12LDU},	//(B3IS12LDU) Приход на ВУ штока ИС2
	{ 311	,1	,1	, &R3IS12LDU},	//(R3IS12LDU) Приход на ВУ гомогенных дверей
	{ 312	,1	,1	, &R2AD20LDU},	//(R2AD20LDU) Поднять МДЗ2
	{ 313	,1	,1	, &R2AD10LDU},	//(R2AD10LDU) Опустить МДЗ2 в зону облучения
	{ 314	,3	,1	, &B8VS01IDU},	//(B8VS01IDU) Готовность к управлению АЗ2
	{ 315	,3	,1	, &A8VS01IDU},	//(A8VS01IDU) Готовность к управлению ДС2
	{ 316	,1	,1	, &A1IE03LDU},	//(A1IE03LDU) Движение ББ1 вперед (от БУШД)
	{ 317	,1	,1	, &A1IE04LDU},	//(A1IE04LDU) Движение ББ1 назад (от БУШД)
	{ 318	,1	,1	, &A2IE03LDU},	//(A2IE03LDU) Движение РБ1 вперед (от БУШД)
	{ 319	,1	,1	, &A2IE04LDU},	//(A2IE04LDU) Движение РБ1 назад (от БУШД)
	{ 320	,1	,1	, &A3IE03LDU},	//(A3IE03LDU) Движение ИС1 вперед (от БУШД)
	{ 321	,1	,1	, &A3IE04LDU},	//(A3IE04LDU) Движение ИС1 назад (от БУШД)
	{ 322	,1	,1	, &B1IE03LDU},	//(B1IE03LDU) Движение ББ2 вперед (от БУШД)
	{ 323	,1	,1	, &B1IE04LDU},	//(B1IE04LDU) Движение ББ2 назад (от БУШД)
	{ 324	,1	,1	, &B2IE03LDU},	//(B2IE03LDU) Движение РБ2 вперед (от БУШД)
	{ 325	,1	,1	, &B2IE04LDU},	//(B2IE04LDU) Движение РБ2 назад (от БУШД)
	{ 326	,1	,1	, &B3IE03LDU},	//(B3IE03LDU) Движение ИС2 вперед (от БУШД)
	{ 327	,1	,1	, &B3IE04LDU},	//(B3IE04LDU) Движение ИС2 назад (от БУШД)
	{ 328	,1	,1	, &R0VS11LDU},	//(R0VS11LDU) РУ не готова к работе
	{ 329	,1	,1	, &B6AB05LDU},	//(B6AB05LDU) Блокировка открытия БЗ2- АНИ не установлен
	{ 330	,1	,1	, &R0AB08LDU},	//(R0AB08LDU) Блокировка кнопки ПУСК - тележка не у образцов
	{ 331	,8	,1	, &A1MC01RP1},	//(A1MC01RP1) Заданная координата положения ББ1 мм
	{ 332	,8	,1	, &B1MC01RP1},	//(B1MC01RP1) Заданная координата положения ББ2  мм
	{ 333	,8	,1	, &A3MC01RP1},	//(A3MC01RP1) Заданная координата положения ИС1 мм
	{ 334	,8	,1	, &R0CN94LDU},	//(R0CN94LDU) Скорость изменения мощности
	{ 335	,3	,1	, &R0CN95LDU},	//(R0CN95LDU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
	{ 336	,1	,1	, &A2IS12LZ1},	//(A2IS12LZ1) Магнит РБ1 зацеплен (для БАЗ1)
	{ 337	,1	,1	, &B2IS12LZ1},	//(B2IS12LZ1) Магнит РБ2 зацеплен (для БАЗ1)
	{ 338	,1	,1	, &A2IS12LZ2},	//(A2IS12LZ2) Магнит РБ1 зацеплен (для БАЗ2)
	{ 339	,1	,1	, &B2IS12LZ2},	//(B2IS12LZ2) Магнит РБ2 зацеплен (для БАЗ2)
	{ 340	,1	,1	, &R0AD03LZ1},	//(R0AD03LZ1) Имитация прихода на ВУ ИС (БАЗ1)
	{ 341	,1	,1	, &R0AD03LZ2},	//(R0AD03LZ2) Имитация прихода на ВУ ИС (БАЗ2)
	{ 342	,1	,1	, &R0AD04LZ1},	//(R0AD04LZ1) Имитация срабатывания АС II УР. РАД (БАЗ1)
	{ 343	,1	,1	, &R0AD04LZ2},	//(R0AD04LZ2) Имитация срабатывания АС II УР. РАД (БАЗ2)
	{ 344	,1	,1	, &R0AD05LZ1},	//(R0AD05LZ1) Имитация ухода с НУП ИС  (БАЗ1)
	{ 345	,1	,1	, &R0AD05LZ2},	//(R0AD05LZ2) Имитация ухода с НУП ИС  (БАЗ2)
	{ 346	,5	,1	, &B1IC01UDU},	//(B1IC01UDU) Координата штока ББ2 (дел.энк)
	{ 347	,8	,1	, &B1VC01RDU},	//(B1VC01RDU) Координата ББ2, мм
	{ 348	,1	,1	, &B1IS11LDU},	//(B1IS11LDU) Приход на ВУ ББ2
	{ 349	,5	,1	, &A2IC01UDU},	//(A2IC01UDU) Координата штока РБ1 (дел.энк)
	{ 350	,5	,1	, &B2IC01UDU},	//(B2IC01UDU) Координата штока РБ2 (дел.энк)
	{ 351	,5	,1	, &A3IC01UDU},	//(A3IC01UDU) Координата штока ИС1 (дел.энк)
	{ 352	,5	,1	, &B3IC01UDU},	//(B3IC01UDU) Координата штока ИС2 (дел.энк)
	{ 353	,8	,1	, &B3VC01RDU},	//(B3VC01RDU) Координата ИС2, мм
	{ 354	,5	,1	, &A8IC01UDU},	//(A8IC01UDU) Координата ДС2 (дел.энк)
	{ 355	,8	,1	, &A8VC01RDU},	//(A8VC01RDU) Координата ДС2, мм
	{ 356	,5	,1	, &B8IC01UDU},	//(B8IC01UDU) Координата АЗ2 (дел.энк)
	{ 357	,1	,1	, &A1ZAV},	//(A1ZAV) 
	{ 358	,1	,1	, &A3ZAV},	//(A3ZAV) 
	{ 359	,1	,1	, &B1AB19LDU},	//(B1AB19LDU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
	{ 360	,8	,1	, &R0VN09RZ2},	//(R0VN09RZ2) Усредненный период разгона
	{ 361	,8	,1	, &R0VN09RZ1},	//(R0VN09RZ1) Усредненный период разгона
	{ 362	,1	,1	, &R0AB16LDU},	//(R0AB16LDU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
	{ 363	,1	,1	, &R0AB17LDU},	//(R0AB17LDU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
	{ 364	,1	,1	, &R0AB18LDU},	//(R0AB18LDU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
	{ 365	,8	,1	, &A0CT01IZ1},	//(A0CT01IZ1) Температура АЗ1-1
	{ 366	,8	,1	, &B0CT01IZ1},	//(B0CT01IZ1) Температура АЗ2-1
	{ 367	,8	,1	, &A0CT01IZ2},	//(A0CT01IZ2) Температура АЗ1-2
	{ 368	,8	,1	, &B0CT01IZ2},	//(B0CT01IZ2) Температура АЗ2-2
	{ 369	,8	,1	, &A3MC01RDU},	//(A3MC01RDU) Заданная координата положения ИС от регулятора мм
	{ 370	,8	,1	, &A3MC02RDU},	//(A3MC02RDU) Температурная корректировка координаты ИМ
	{ 371	,8	,1	, &R0CN91LDU},	//(R0CN91LDU) Рассчётная реактивность от регулятора
	{ 372	,8	,1	, &A3MC03RDU},	//(A3MC03RDU) Координата положения ИМ 0-й реактивности
	{ 373	,1	,1	, &A3AB15LDU},	//(A3AB15LDU) Блокировка заполнения ресивера ИС1,2: работает регулятор мощности
	{ 374	,1	,1	, &R0AB20LDU},	//(R0AB20LDU) Блокировка изменения положения ОР: работает  регулятор мощности
	{ 375	,8	,1	, &R0CN92LDU},	//(R0CN92LDU) Рассчётный коэффициент  опережения старта ИМ
	{ 376	,8	,1	, &R0VN11RDU},	//(R0VN11RDU) Текущая мощность РУ
	{ 377	,8	,1	, &R0VN12RDU},	//(R0VN12RDU) Заданная мощность РУ
	{ 378	,1	,1	, &R0AB19LDU},	//(R0AB19LDU) Остановка регулирования мощности: Есть блокировки  ИС1,2
	{ 379	,8	,1	, &R0CN93LDU},	//(R0CN93LDU) время работы на мощности более 100Вт, сек
	{ 380	,1	,1	, &R4IS11LDU},	//(R4IS11LDU) Приход на ВУ тележки
	{ 381	,1	,1	, &A6AB06LDU},	//(A6AB06LDU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
	{ 382	,1	,1	, &A6AB07LDU},	//(A6AB07LDU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
	{ 383	,1	,1	, &A6AB08LDU},	//(A6AB08LDU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
	{ 384	,1	,1	, &A6AB09LDU},	//(A6AB09LDU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
	{ 385	,1	,1	, &B6AB06LDU},	//(B6AB06LDU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
	{ 386	,1	,1	, &B6AB07LDU},	//(B6AB07LDU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
	{ 387	,1	,1	, &B6AB08LDU},	//(B6AB08LDU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
	{ 388	,1	,1	, &B6AB09LDU},	//(B6AB09LDU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
	{ 389	,1	,1	, &A6AB05LDU},	//(A6AB05LDU) Блокировка открытия БЗ1 - АНИ не установлен
	{ 390	,1	,1	, &B8VS12LDU},	//(B8VS12LDU) Движение АЗ2 в сторону ВУ
	{ 391	,8	,1	, &B8CV01RDU},	//(B8CV01RDU) Измеренная скорость перемещения АЗ2
	{ 392	,1	,1	, &B8AB06LDU},	//(B8AB06LDU) Блокировка движения АЗ2 нет перемещения АЗ2
	{ 393	,1	,1	, &B8AB07LDU},	//(B8AB07LDU) Блокировка движения АЗ2: превышение заданной скорости
	{ 394	,1	,1	, &B8AB05LDU},	//(B8AB05LDU) Блокировка движения АЗ2: скорость перемещения менее заданной
	{ 395	,1	,1	, &B8VS22LDU},	//(B8VS22LDU) Движение АЗ2 в сторону НУ
	{ 396	,1	,1	, &B8AZ03LDU},	//(B8AZ03LDU) Несанкционированное перемещение АЗ2
	{ 397	,1	,1	, &R0MD11LP1},	//(R0MD11LP1) Кнопка «ПУСК»
	{ 398	,1	,1	, &B8AD10LDU},	//(B8AD10LDU) Перемещение АЗ2 вперед
	{ 399	,1	,1	, &B8AD20LDU},	//(B8AD20LDU) Перемещение АЗ2 назад
	{ 400	,1	,1	, &B8IS12LDU},	//(B8IS12LDU) Приход на механический ВУ АЗ2
	{ 401	,1	,1	, &B8AB01LDU},	//(B8AB01LDU) Блокировка движения АЗ2 - Превышение времени движения
	{ 402	,1	,1	, &B5IS21LDU},	//(B5IS21LDU) Приход на НУ НЛ2
	{ 403	,1	,1	, &A5AZ03LDU},	//(A5AZ03LDU) Несанкционированное перемещение НЛ1
	{ 404	,1	,1	, &A5AB01LDU},	//(A5AB01LDU) Блокировка движения НЛ1 - Превышение времени движения
	{ 405	,1	,1	, &A5AB02LDU},	//(A5AB02LDU) Блокировка НЛ1 - Нет перемещения
	{ 406	,1	,1	, &B5AZ03LDU},	//(B5AZ03LDU) Несанкционированное перемещение НЛ2
	{ 407	,1	,1	, &B5AB01LDU},	//(B5AB01LDU) Блокировка движения НЛ2 - Превышение времени движения
	{ 408	,1	,1	, &B5AB02LDU},	//(B5AB02LDU) Блокировка НЛ2 - Нет перемещения
	{ 409	,1	,1	, &A4IS21LDU},	//(A4IS21LDU) Приход на НУ НИ1
	{ 410	,1	,1	, &B4IS21LDU},	//(B4IS21LDU) Приход на НУ НИ2
	{ 411	,1	,1	, &B4AD10LDU},	//(B4AD10LDU) Открыть клапан Подъем НИ2
	{ 412	,1	,1	, &A4AD10LDU},	//(A4AD10LDU) Открыть клапан Подъем НИ1
	{ 413	,1	,1	, &A4AZ03LDU},	//(A4AZ03LDU) Несанкционированное перемещение НИ1
	{ 414	,1	,1	, &A4AB01LDU},	//(A4AB01LDU) Блокировка движения НИ ДС1 - Превышение времени движения
	{ 415	,1	,1	, &A4AB02LDU},	//(A4AB02LDU) Блокировка НИ1 - Нет перемещения
	{ 416	,1	,1	, &B4AZ03LDU},	//(B4AZ03LDU) Несанкционированное перемещение НИ1
	{ 417	,1	,1	, &B4AB01LDU},	//(B4AB01LDU) Блокировка движения НИ2 - Превышение времени движения
	{ 418	,1	,1	, &B4AB02LDU},	//(B4AB02LDU) Блокировка НИ2 - Нет перемещения
	{ 419	,1	,1	, &A5AB04LDU},	//(A5AB04LDU) Блокировка НЛ1 -Ошибка в направлении  движения
	{ 420	,1	,1	, &B5AB04LDU},	//(B5AB04LDU) Блокировка НЛ2 -Ошибка в направлении  движения
	{ 421	,1	,1	, &A1IS12LDU},	//(A1IS12LDU) Магнит ББ1 зацеплен
	{ 422	,1	,1	, &A2IS12LDU},	//(A2IS12LDU) Магнит РБ1 зацеплен
	{ 423	,1	,1	, &B1IS12LDU},	//(B1IS12LDU) Магнит ББ2 зацеплен
	{ 424	,1	,1	, &B2IS12LDU},	//(B2IS12LDU) Магнит РБ2 зацеплен
	{ 425	,1	,1	, &A8AB09LDU},	//(A8AB09LDU) Блокировка  - ДС2 по мощности от любого канала
	{ 426	,1	,1	, &A8AB10LDU},	//(A8AB10LDU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
	{ 427	,1	,1	, &A8AB11LDU},	//(A8AB11LDU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
	{ 428	,1	,1	, &A8AB12LDU},	//(A8AB12LDU) Блокировка движения ДС2 - НИ не в положении ВУ
	{ 429	,1	,1	, &A8AB13LDU},	//(A8AB13LDU) Блокировка движения ДС2 - ОРР не в исходном состоянии
	{ 430	,1	,1	, &A8AB14LDU},	//(A8AB14LDU) Блокировка движения ДС2 - Самоход любого механизма
	{ 431	,1	,1	, &A8AB02LDU},	//(A8AB02LDU) Блокировка движения ДС2- АНИ не установлен
	{ 432	,1	,1	, &A8AB01LDU},	//(A8AB01LDU) Блокировка ДС2 -Превышение времени перемещения
	{ 433	,1	,1	, &A2VS11LDU},	//(A2VS11LDU) Движение РБ1 в сторону ВУ
	{ 434	,8	,1	, &A2CV01RDU},	//(A2CV01RDU) Измеренная скорость перемещения РБ1
	{ 435	,1	,1	, &A2AB04LDU},	//(A2AB04LDU) Блокировка движения РБ1 нет перемещения  РБ1
	{ 436	,1	,1	, &A2AB02LDU},	//(A2AB02LDU) Блокировка движения РБ1: превышение заданной скорости
	{ 437	,1	,1	, &A2AB01LDU},	//(A2AB01LDU) Блокировка движения РБ1: скорость перемещения менее заданной
	{ 438	,1	,1	, &A2VS21LDU},	//(A2VS21LDU) Движение РБ1 в сторону НУ
	{ 439	,1	,1	, &A2AZ03LDU},	//(A2AZ03LDU) Несанкционированное перемещение РБ1
	{ 440	,1	,1	, &A2AD11LDU},	//(A2AD11LDU) Сигнал на перемещение РБ1 вверх
	{ 441	,1	,1	, &A2AD21LDU},	//(A2AD21LDU) Сигнал на перемещение РБ1 вниз
	{ 442	,1	,1	, &A2AD02LDU},	//(A2AD02LDU) 0-й бит скорости РБ1
	{ 443	,1	,1	, &A2AD03LDU},	//(A2AD03LDU) 1-й бит скорости РБ1
	{ 444	,1	,1	, &A2AD04LDU},	//(A2AD04LDU) 2-й бит скорости РБ1
	{ 445	,1	,1	, &A2AD05LDU},	//(A2AD05LDU) паритет команды на РБ1
	{ 446	,1	,1	, &A2AB07LDU},	//(A2AB07LDU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
	{ 447	,1	,1	, &B8AB04LDU},	//(B8AB04LDU) Блокировка АЗ2 -Ошибка в направлении  движения
	{ 448	,1	,1	, &B8AB08LDU},	//(B8AB08LDU) Блокировка движения ДС2 Гомогенные двери не закрыты
	{ 449	,1	,1	, &B8AB09LDU},	//(B8AB09LDU) Блокировка  - АЗ2 по мощности от любого канала
	{ 450	,1	,1	, &B8AB10LDU},	//(B8AB10LDU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
	{ 451	,1	,1	, &B8AB11LDU},	//(B8AB11LDU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
	{ 452	,1	,1	, &B8AB12LDU},	//(B8AB12LDU) Блокировка движения АЗ2 - НИ не в положении ВУ
	{ 453	,1	,1	, &B8AB13LDU},	//(B8AB13LDU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
	{ 454	,1	,1	, &B8AB14LDU},	//(B8AB14LDU) Блокировка движения АЗ2 - Самоход любого механизма
	{ 455	,1	,1	, &B8AB02LDU},	//(B8AB02LDU) Блокировка движения АЗ2- АНИ не установлен
	{ 456	,1	,1	, &A8VS12LDU},	//(A8VS12LDU) Движение ДС2 в сторону ВУ
	{ 457	,8	,1	, &A8CV01RDU},	//(A8CV01RDU) Измеренная скорость перемещения ДС2
	{ 458	,1	,1	, &A8AB06LDU},	//(A8AB06LDU) Блокировка движения ДС2 нет перемещения ДС2
	{ 459	,1	,1	, &A8AB07LDU},	//(A8AB07LDU) Блокировка движения ДС2: превышение заданной скорости
	{ 460	,1	,1	, &A8AB05LDU},	//(A8AB05LDU) Блокировка движения ДС2: скорость перемещения менее заданной
	{ 461	,1	,1	, &A8VS22LDU},	//(A8VS22LDU) Движение ДС2 в сторону НУ
	{ 462	,1	,1	, &A8AZ03LDU},	//(A8AZ03LDU) Несанкционированное перемещение ДС2
	{ 463	,1	,1	, &A8AD10LDU},	//(A8AD10LDU) Перемещение ДС2 вперед
	{ 464	,1	,1	, &A8AD20LDU},	//(A8AD20LDU) Перемещение ДС2 назад
	{ 465	,1	,1	, &B8IS22LDU},	//(B8IS22LDU) Приход на механический НУ АЗ2
	{ 466	,1	,1	, &A8IS12LDU},	//(A8IS12LDU) Приход на механический ВУ ДС2
	{ 467	,1	,1	, &A8AB04LDU},	//(A8AB04LDU) Блокировка ДС2 -Ошибка в направлении  движения
	{ 468	,1	,1	, &A8IS22LDU},	//(A8IS22LDU) Приход на механический НУ ДС2
	{ 469	,1	,1	, &A8AB08LDU},	//(A8AB08LDU) Блокировка движения ДС2 Гомогенные двери не закрыты
	{ 470	,1	,1	, &B6IS21LDU},	//(B6IS21LDU) Приход на НУ БЗ2
	{ 471	,1	,1	, &A6VS22LDU},	//(A6VS22LDU) Движение створок БЗ1  к «ЗАКРЫТА»
	{ 472	,1	,1	, &A6VS12LDU},	//(A6VS12LDU) Движение створок БЗ1  к  «ОТКРЫТА»
	{ 473	,1	,1	, &B6VS22LDU},	//(B6VS22LDU) Движение створок БЗ2  к «ЗАКРЫТА»
	{ 474	,1	,1	, &B6VS12LDU},	//(B6VS12LDU) Движение створок БЗ2  к  «ОТКРЫТА»
	{ 475	,1	,1	, &A6AD10LDU},	//(A6AD10LDU) Открыть БЗ1
	{ 476	,1	,1	, &A6AD20LDU},	//(A6AD20LDU) Закрыть БЗ1
	{ 477	,1	,1	, &B6AD10LDU},	//(B6AD10LDU) Открыть БЗ2
	{ 478	,1	,1	, &B6AD20LDU},	//(B6AD20LDU) Закрыть БЗ2
	{ 479	,1	,1	, &A6AZ03LDU},	//(A6AZ03LDU) Несанкционированное перемещение БЗ1
	{ 480	,1	,1	, &A6AB01LDU},	//(A6AB01LDU) Блокировка движения БЗ1 - Превышение времени движения
	{ 481	,1	,1	, &A6AB02LDU},	//(A6AB02LDU) Блокировка БЗ1 - Нет перемещения
	{ 482	,1	,1	, &B6AZ03LDU},	//(B6AZ03LDU) Несанкционированное перемещение БЗ2
	{ 483	,1	,1	, &B6AB01LDU},	//(B6AB01LDU) Блокировка движения БЗ2 - Превышение времени движения
	{ 484	,1	,1	, &B6AB02LDU},	//(B6AB02LDU) Блокировка БЗ2 - Нет перемещения
	{ 485	,1	,1	, &A6AB04LDU},	//(A6AB04LDU) Блокировка БЗ1 -Ошибка в направлении  движения
	{ 486	,1	,1	, &B6AB04LDU},	//(B6AB04LDU) Блокировка БЗ2 -Ошибка в направлении  движения
	{ 487	,1	,1	, &R4AB01LDU},	//(R4AB01LDU) Блокировка тележки - АНИ не установлен
	{ 488	,1	,1	, &R8IS11LDU},	//(R8IS11LDU) Аварийный НИ установлен
	{ 489	,1	,1	, &R6IS21LDU},	//(R6IS21LDU) Кран-балка в нерабочем положении
	{ 490	,1	,1	, &A0VN71LZ2},	//(A0VN71LZ2) АЗ по АС мощности для АЗ1
	{ 491	,1	,1	, &A0VN71LZ1},	//(A0VN71LZ1) АЗ по АС мощности для АЗ1
	{ 492	,3	,1	, &R0MW15IP1},	//(R0MW15IP1) Переключатель «МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ»
	{ 493	,3	,1	, &R0MW14IP1},	//(R0MW14IP1) Переключатель «ПРОГРАММЫ»
	{ 494	,3	,1	, &R0MW12IP1},	//(R0MW12IP1) Переключатель «РЕЖИМ РАБОТЫ»
	{ 495	,3	,1	, &R0MW13IP1},	//(R0MW13IP1) Переключатель «ВЫБОР ЗОН»
	{ 496	,3	,1	, &R0MW16IP1},	//(R0MW16IP1) Переключатель «ВИД ПРОВЕРКИ»
	{ 497	,3	,1	, &R0MW11IP1},	//(R0MW11IP1) Переключатель «ВЫСТРЕЛ»
	{ 498	,3	,1	, &R0MW11IP2},	//(R0MW11IP2) Переключатель «ПРОВЕРКА СХЕМ СБРОСА»
	{ 499	,1	,1	, &R0MW13LP2},	//(R0MW13LP2) Переключатель «СЕТЬ»
	{ 500	,1	,1	, &R0MD32LP1},	//(R0MD32LP1) Кнопка «СПУСК»
	{ 501	,1	,1	, &R0MD31LP1},	//(R0MD31LP1) Кнопка «СТОП»
	{ 502	,1	,1	, &A1IS21LDU},	//(A1IS21LDU) Приход на НУ ББ1
	{ 503	,1	,1	, &A2IS21LDU},	//(A2IS21LDU) Приход на НУ РБ1-СС
	{ 504	,1	,1	, &A3IS21LDU},	//(A3IS21LDU) Приход на НУ ИС1
	{ 505	,1	,1	, &B1IS21LDU},	//(B1IS21LDU) Приход на НУ ББ2
	{ 506	,1	,1	, &B2IS21LDU},	//(B2IS21LDU) Приход на НУ РБ2-СС
	{ 507	,1	,1	, &B3IS21LDU},	//(B3IS21LDU) Приход на НУ ИС2
	{ 508	,1	,1	, &R0ES01LDU},	//(R0ES01LDU) ОРР не в исходном состоянии
	{ 509	,1	,1	, &R4MD11LP2},	//(R4MD11LP2) Кнопка «ВПЕРЁД»  (тележки)
	{ 510	,1	,1	, &R4MD31LP2},	//(R4MD31LP2) Кнопка «СТОП»  (тележки)
	{ 511	,1	,1	, &R4MD21LP2},	//(R4MD21LP2) Кнопка «НАЗАД»  (тележки)
	{ 512	,1	,1	, &A6IS11LDU},	//(A6IS11LDU) Приход на ВУ БЗ1
	{ 513	,1	,1	, &A6IS21LDU},	//(A6IS21LDU) Приход на НУ БЗ1
	{ 514	,1	,1	, &B6IS11LDU},	//(B6IS11LDU) Приход на ВУ БЗ2
	{ 515	,1	,1	, &R4AB12LDU},	//(R4AB12LDU) Блокировка тележки - НИ не в положении ВУ
	{ 516	,1	,1	, &A4IS11LDU},	//(A4IS11LDU) Приход на ВУ НИ1
	{ 517	,1	,1	, &B4IS11LDU},	//(B4IS11LDU) Приход на ВУ НИ2
	{ 518	,1	,1	, &R4AB13LDU},	//(R4AB13LDU) Блокировка тележки - НЛ не в положении ВУ
	{ 519	,1	,1	, &R4AB14LDU},	//(R4AB14LDU) Блокировка тележки - Кран - балка не в безопасном положении
	{ 520	,1	,1	, &R4AB15LDU},	//(R4AB15LDU) Блокировка тележки - ворота в пом. 0041 не в положении Открыто
	{ 521	,1	,1	, &R5IS11LDU},	//(R5IS11LDU) Приход на ВУ ворот отстойной зоны
	{ 522	,1	,1	, &R4AB16LDU},	//(R4AB16LDU) Блокировка тележки - Гомогенные двери не в положении Закрыты
	{ 523	,1	,1	, &R4AB17LDU},	//(R4AB17LDU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
	{ 524	,1	,1	, &R4AB18LDU},	//(R4AB18LDU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
	{ 525	,1	,1	, &R4AD10LDU},	//(R4AD10LDU) Перемещение тележки вперед
	{ 526	,1	,1	, &R4AD20LDU},	//(R4AD20LDU) Перемещение тележки назад
	{ 527	,1	,1	, &A5VS22LDU},	//(A5VS22LDU) Движение НЛ1 в сторону НУ
	{ 528	,1	,1	, &A5VS12LDU},	//(A5VS12LDU) Движение НЛ1 в сторону ВУ
	{ 529	,1	,1	, &B5VS22LDU},	//(B5VS22LDU) Движение НЛ2 в сторону НУ
	{ 530	,1	,1	, &B5VS12LDU},	//(B5VS12LDU) Движение НЛ2 в сторону ВУ
	{ 531	,1	,1	, &B5AD10LDU},	//(B5AD10LDU) Поднять НЛ2
	{ 532	,1	,1	, &B5AD20LDU},	//(B5AD20LDU) Опустить НЛ2
	{ 533	,1	,1	, &A5AD10LDU},	//(A5AD10LDU) Поднять НЛ1
	{ 534	,1	,1	, &A5AD20LDU},	//(A5AD20LDU) Опустить НЛ1
	{ 535	,1	,1	, &A5IS11LDU},	//(A5IS11LDU) Приход на ВУ НЛ1
	{ 536	,1	,1	, &A5IS21LDU},	//(A5IS21LDU) Приход на НУ НЛ1
	{ 537	,1	,1	, &B5IS11LDU},	//(B5IS11LDU) Приход на ВУ НЛ2
	{ 538	,1	,1	, &R0NE01LDU},	//(R0NE01LDU) Потеря связи с БАЗ1
	{ 539	,1	,1	, &R0NE02LDU},	//(R0NE02LDU) Потеря связи с БАЗ2
	{ 540	,1	,1	, &R4AB02LDU},	//(R4AB02LDU) Блокировка тележки - Потеря связи с БАЗ, ОПУ
	{ 541	,1	,1	, &R0NE08LDU},	//(R0NE08LDU) Потеря связи с ОПУ
	{ 542	,1	,1	, &R4IS21LDU},	//(R4IS21LDU) Приход на НУ тележки
	{ 543	,1	,1	, &R4IS22LDU},	//(R4IS22LDU) Приход на механический НУ тележки
	{ 544	,1	,1	, &R4IS12LDU},	//(R4IS12LDU) Приход на механический ВУ тележки
	{ 545	,1	,1	, &R4VS22LDU},	//(R4VS22LDU) Движение реактора к «У ЗАЩИТЫ»
	{ 546	,1	,1	, &R4VS12LDU},	//(R4VS12LDU) Движение реактора  к «У ОБРАЗЦОВ»
	{ 547	,1	,1	, &R4AZ03LDU},	//(R4AZ03LDU) Несанкционированное перемещение тележки
	{ 548	,1	,1	, &R4AB03LDU},	//(R4AB03LDU) Блокировка тележки - Самоход любого механизма
	{ 549	,1	,1	, &R1IS21LDU},	//(R1IS21LDU) Приход на НУ МДЗ1
	{ 550	,1	,1	, &R2IS21LDU},	//(R2IS21LDU) Приход на НУ МДЗ2
	{ 551	,1	,1	, &R4AB04LDU},	//(R4AB04LDU) Блокировка тележки - Превышение времени движения
	{ 552	,1	,1	, &R4AB05LDU},	//(R4AB05LDU) Блокировка тележки - Нет перемещения тележки
	{ 553	,1	,1	, &R4AB06LDU},	//(R4AB06LDU) Блокировка тележки - Ошибка в  направлении перемещения
	{ 554	,1	,1	, &R4AB07LDU},	//(R4AB07LDU) Блокировка тележки - ОРР не в исходном состоянии
	{ 555	,1	,1	, &R4AB08LDU},	//(R4AB08LDU) Блокировка тележки - А32 или ДС2 не на НУ(координата 1500 мм)
	{ 556	,1	,1	, &R4AB09LDU},	//(R4AB09LDU) Блокировка тележки - АЗ по мощности от любого канала
	{ 557	,1	,1	, &B0VN71LZ1},	//(B0VN71LZ1) АЗ по АС мощности для АЗ2
	{ 558	,1	,1	, &B0VN71LZ2},	//(B0VN71LZ2) АЗ по АС мощности для АЗ2
	{ 559	,1	,1	, &R4AB10LDU},	//(R4AB10LDU) Блокировка тележки - не открыта биологическая защита
	{ 560	,1	,1	, &R4AB11LDU},	//(R4AB11LDU) Блокировка тележки - МДЗ1,2 не находятся на НУ
	{ 561	,1	,1	, &A3AB01LDU},	//(A3AB01LDU) Блокировка движения ИС1: скорость перемещения менее заданной
	{ 562	,1	,1	, &A3VS22LDU},	//(A3VS22LDU) Движение ИС1 в сторону НУ
	{ 563	,1	,1	, &A3AZ03LDU},	//(A3AZ03LDU) Несанкционированное перемещение ИС1
	{ 564	,1	,1	, &A3AD11LDU},	//(A3AD11LDU) Сигнал на перемещение ИС1 вверх
	{ 565	,1	,1	, &A3AD21LDU},	//(A3AD21LDU) Сигнал на перемещение ИС1 вниз
	{ 566	,1	,1	, &A3AD02LDU},	//(A3AD02LDU) 0-й бит скорости ИС1
	{ 567	,1	,1	, &A3AD03LDU},	//(A3AD03LDU) 1-й бит скорости ИС1
	{ 568	,1	,1	, &A3AD04LDU},	//(A3AD04LDU) 2-й бит скорости ИС1
	{ 569	,1	,1	, &A3AD05LDU},	//(A3AD05LDU) паритет команды на ИС1
	{ 570	,1	,1	, &A3AD01LDU},	//(A3AD01LDU) Разрешение движения ИС1
	{ 571	,8	,1	, &A3CV02RDU},	//(A3CV02RDU) Заданная скорость перемещения ИС1
	{ 572	,1	,1	, &A3AB07LDU},	//(A3AB07LDU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
	{ 573	,1	,1	, &A3AB08LDU},	//(A3AB08LDU) Блокировка подъёма ИС1 - реактор не на рабочем месте
	{ 574	,1	,1	, &A3AB05LDU},	//(A3AB05LDU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
	{ 575	,1	,1	, &A3AB06LDU},	//(A3AB06LDU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
	{ 576	,1	,1	, &A3AB09LDU},	//(A3AB09LDU) Блокировка подъёма ИС1- АНИ не установлен
	{ 577	,1	,1	, &A3AB10LDU},	//(A3AB10LDU) Блокировка подъёма ИС1- есть сигнал общего сброса
	{ 578	,1	,1	, &A3AB11LDU},	//(A3AB11LDU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
	{ 579	,1	,1	, &A3AB12LDU},	//(A3AB12LDU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 580	,1	,1	, &A3AB13LDU},	//(A3AB13LDU) Блокировка подъёма ИС1- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
	{ 581	,1	,1	, &A3AB14LDU},	//(A3AB14LDU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
	{ 582	,1	,1	, &A3AB16LDU},	//(A3AB16LDU) Блокировка перемещения ИС1: выполняется программа 200 с
	{ 583	,1	,1	, &B1AD02LDU},	//(B1AD02LDU) 0-й бит скорости ББ2
	{ 584	,1	,1	, &B1AD03LDU},	//(B1AD03LDU) 1-й бит скорости ББ2
	{ 585	,1	,1	, &B1AD04LDU},	//(B1AD04LDU) 2-й бит скорости ББ2
	{ 586	,1	,1	, &B1AD05LDU},	//(B1AD05LDU) паритет команды на ББ2
	{ 587	,1	,1	, &B1AD01LDU},	//(B1AD01LDU) Разрешение движения ББ2
	{ 588	,8	,1	, &B1CV02RDU},	//(B1CV02RDU) Заданная скорость перемещения ББ2
	{ 589	,1	,1	, &B1AB07LDU},	//(B1AB07LDU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
	{ 590	,1	,1	, &B1AB08LDU},	//(B1AB08LDU) Блокировка подъёма ББ2 - реактор не на рабочем месте
	{ 591	,1	,1	, &B1AB05LDU},	//(B1AB05LDU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
	{ 592	,1	,1	, &B1AB06LDU},	//(B1AB06LDU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
	{ 593	,1	,1	, &B1AB09LDU},	//(B1AB09LDU) Блокировка подъёма ББ2- АНИ не установлен
	{ 594	,1	,1	, &B1AB10LDU},	//(B1AB10LDU) Блокировка подъёма ББ2- есть сигнал общего сброса
	{ 595	,1	,1	, &B1AB11LDU},	//(B1AB11LDU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
	{ 596	,1	,1	, &B1AB12LDU},	//(B1AB12LDU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 597	,1	,1	, &B1AB13LDU},	//(B1AB13LDU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже значения заданного предупредительной уставкой
	{ 598	,1	,1	, &B1AB14LDU},	//(B1AB14LDU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
	{ 599	,1	,1	, &B1AB16LDU},	//(B1AB16LDU) Блокировка перемещения ББ2: выполняется программа 200 с
	{ 600	,1	,1	, &B1AB17LDU},	//(B1AB17LDU) Блокировка перемещения ББ2: выполняется программа 20 мин
	{ 601	,1	,1	, &B1AB18LDU},	//(B1AB18LDU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
	{ 602	,1	,1	, &A3VS12LDU},	//(A3VS12LDU) Движение ИС1 в сторону ВУ
	{ 603	,8	,1	, &A3CV01RDU},	//(A3CV01RDU) Измеренная скорость перемещения ИС1
	{ 604	,1	,1	, &A3AB04LDU},	//(A3AB04LDU) Блокировка движения ИС1 нет перемещения  ИС1
	{ 605	,1	,1	, &A3AB02LDU},	//(A3AB02LDU) Блокировка движения ИС1: превышение заданной скорости
	{ 606	,1	,1	, &B3AB09LDU},	//(B3AB09LDU) Блокировка подъёма ИС2- АНИ не установлен
	{ 607	,1	,1	, &B3AB10LDU},	//(B3AB10LDU) Блокировка подъёма ИС2- есть сигнал общего сброса
	{ 608	,1	,1	, &B3AB11LDU},	//(B3AB11LDU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
	{ 609	,1	,1	, &B3AB12LDU},	//(B3AB12LDU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{ 610	,1	,1	, &B3AB13LDU},	//(B3AB13LDU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
	{ 611	,1	,1	, &B3AB14LDU},	//(B3AB14LDU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
	{ 612	,1	,1	, &B3AB16LDU},	//(B3AB16LDU) Блокировка перемещения ИС2: выполняется программа 200 с
	{ 613	,1	,1	, &B3AB17LDU},	//(B3AB17LDU) Блокировка перемещения ИС2: выполняется программа 20 мин
	{ 614	,1	,1	, &B3AB18LDU},	//(B3AB18LDU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
	{ 615	,1	,1	, &B3AB19LDU},	//(B3AB19LDU) Блокировка пневматического подъема ИС2: режим статический
	{ 616	,1	,1	, &B3AB20LDU},	//(B3AB20LDU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
	{ 617	,1	,1	, &C1MD31LP1},	//(C1MD31LP1) Кнопка «СБРОС ББ»
	{ 618	,1	,1	, &C1MD31LP2},	//(C1MD31LP2) Кнопка «СБРОС ББ»
	{ 619	,1	,1	, &A2AD31LDU},	//(A2AD31LDU) Клапан «Сброс РБ1» открыть (обесточить)
	{ 620	,1	,1	, &B2AD31LDU},	//(B2AD31LDU) Клапан «Сброс РБ2» открыть (обесточить)
	{ 621	,1	,1	, &A1AD31LDU},	//(A1AD31LDU) Клапан «Сброс ББ1» открыть (обесточить)
	{ 622	,1	,1	, &B1AD31LDU},	//(B1AD31LDU) Клапан «Сброс ББ2» открыть (обесточить)
	{ 623	,1	,1	, &A2AD32LDU},	//(A2AD32LDU) Обесточить ЭМ РБ1
	{ 624	,1	,1	, &B2AD32LDU},	//(B2AD32LDU) Обесточить ЭМ РБ2
	{ 625	,1	,1	, &A1AD32LDU},	//(A1AD32LDU) Обесточить ЭМ ББ1
	{ 626	,1	,1	, &B1AD32LDU},	//(B1AD32LDU) Обесточить ЭМ ББ2
	{ 627	,1	,1	, &R0MD11LP2},	//(R0MD11LP2) Кнопка Пуск проверки схем сброса
	{ 628	,1	,1	, &R0VX01LDU},	//(R0VX01LDU) ДО ИМПУЛЬСА
	{ 629	,1	,1	, &A3AB17LDU},	//(A3AB17LDU) Блокировка перемещения ИС1: выполняется программа 20 мин
	{ 630	,1	,1	, &A3AB18LDU},	//(A3AB18LDU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
	{ 631	,1	,1	, &A3AB19LDU},	//(A3AB19LDU) Блокировка пневматического подъема ИС1: режим статический
	{ 632	,1	,1	, &A3AB20LDU},	//(A3AB20LDU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
	{ 633	,1	,1	, &B3VS12LDU},	//(B3VS12LDU) Движение ИС2 в сторону ВУ
	{ 634	,8	,1	, &B3CV01RDU},	//(B3CV01RDU) Измеренная скорость перемещения ИС2
	{ 635	,1	,1	, &B3AB04LDU},	//(B3AB04LDU) Блокировка движения ИС2 нет перемещения  ИС1
	{ 636	,1	,1	, &B3AB02LDU},	//(B3AB02LDU) Блокировка движения ИС2: превышение заданной скорости
	{ 637	,1	,1	, &B3AB01LDU},	//(B3AB01LDU) Блокировка движения ИС2: скорость перемещения менее заданной
	{ 638	,1	,1	, &B3VS22LDU},	//(B3VS22LDU) Движение ИС2 в сторону НУ
	{ 639	,1	,1	, &B3AZ03LDU},	//(B3AZ03LDU) Несанкционированное перемещение ИС2
	{ 640	,1	,1	, &B3AD11LDU},	//(B3AD11LDU) Сигнал на перемещение ИС2 вверх
	{ 641	,1	,1	, &B3AD21LDU},	//(B3AD21LDU) Сигнал на перемещение ИС2 вниз
	{ 642	,1	,1	, &B3AD02LDU},	//(B3AD02LDU) 0-й бит скорости ИС2
	{ 643	,1	,1	, &B3AD03LDU},	//(B3AD03LDU) 1-й бит скорости ИС2
	{ 644	,1	,1	, &B3AD04LDU},	//(B3AD04LDU) 2-й бит скорости ИС2
	{ 645	,1	,1	, &B3AD05LDU},	//(B3AD05LDU) паритет команды на ИС2
	{ 646	,1	,1	, &B3AD01LDU},	//(B3AD01LDU) Разрешение движения ИС2
	{ 647	,8	,1	, &B3CV02RDU},	//(B3CV02RDU) Заданная скорость перемещения ИС2
	{ 648	,1	,1	, &B3AB07LDU},	//(B3AB07LDU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
	{ 649	,1	,1	, &B3AB08LDU},	//(B3AB08LDU) Блокировка подъёма ИС2 - реактор не на рабочем месте
	{ 650	,1	,1	, &B3AB05LDU},	//(B3AB05LDU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
	{ 651	,1	,1	, &B3AB06LDU},	//(B3AB06LDU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
	{ 652	,1	,1	, &B2AD05LDU},	//(B2AD05LDU) паритет команды на РБ2
	{ 653	,1	,1	, &B2AD01LDU},	//(B2AD01LDU) Разрешение движения РБ2
	{ 654	,8	,1	, &B2CV02RDU},	//(B2CV02RDU) Заданная скорость перемещения РБ2
	{ 655	,1	,1	, &B2AB07LDU},	//(B2AB07LDU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
	{ 656	,1	,1	, &B2AB08LDU},	//(B2AB08LDU) Блокировка подъёма РБ2 - реактор не на рабочем месте
	{ 657	,1	,1	, &B2AB05LDU},	//(B2AB05LDU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
	{ 658	,1	,1	, &B2AB06LDU},	//(B2AB06LDU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
	{ 659	,1	,1	, &B2AB09LDU},	//(B2AB09LDU) Блокировка подъёма РБ2- АНИ не установлен
	{ 660	,1	,1	, &B2AB10LDU},	//(B2AB10LDU) Блокировка подъёма РБ2- есть сигнал общего сброса
	{ 661	,1	,1	, &B2AB11LDU},	//(B2AB11LDU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
	{ 662	,1	,1	, &B2AB12LDU},	//(B2AB12LDU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{ 663	,1	,1	, &B2AB13LDU},	//(B2AB13LDU) Блокировка подъёма РБ2- давление в пневмосистеме РБ ниже значения заданного предупредительной уставкой
	{ 664	,1	,1	, &B2AB14LDU},	//(B2AB14LDU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
	{ 665	,1	,1	, &B2AB16LDU},	//(B2AB16LDU) Блокировка перемещения РБ2: выполняется программа 200 с
	{ 666	,1	,1	, &B2AB17LDU},	//(B2AB17LDU) Блокировка перемещения РБ2: выполняется программа 20 мин
	{ 667	,1	,1	, &R1AZ03LDU},	//(R1AZ03LDU) Несанкционированное перемещение МДЗ1
	{ 668	,1	,1	, &R1AB01LDU},	//(R1AB01LDU) Блокировка движения МДЗ1 - Превышение времени движения
	{ 669	,1	,1	, &R1AB02LDU},	//(R1AB02LDU) Блокировка МДЗ1 - Нет перемещения
	{ 670	,1	,1	, &R2AZ03LDU},	//(R2AZ03LDU) Несанкционированное перемещение МДЗ2
	{ 671	,1	,1	, &R2AB01LDU},	//(R2AB01LDU) Блокировка движения МДЗ2 - Превышение времени движения
	{ 672	,1	,1	, &R2AB02LDU},	//(R2AB02LDU) Блокировка МДЗ2 - Нет перемещения
	{ 673	,1	,1	, &R1AB04LDU},	//(R1AB04LDU) Блокировка МДЗ1 -Ошибка в направлении  движения
	{ 674	,1	,1	, &A2AB08LDU},	//(A2AB08LDU) Блокировка подъёма РБ1 - реактор не на рабочем месте
	{ 675	,1	,1	, &A2AB05LDU},	//(A2AB05LDU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
	{ 676	,1	,1	, &A2AB06LDU},	//(A2AB06LDU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
	{ 677	,1	,1	, &A2AB09LDU},	//(A2AB09LDU) Блокировка подъёма РБ1- АНИ не установлен
	{ 678	,1	,1	, &A2AB10LDU},	//(A2AB10LDU) Блокировка подъёма РБ1- есть сигнал общего сброса
	{ 679	,1	,1	, &A2AB11LDU},	//(A2AB11LDU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
	{ 680	,1	,1	, &A2AB12LDU},	//(A2AB12LDU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 681	,1	,1	, &A2AB13LDU},	//(A2AB13LDU) Блокировка подъёма РБ1- давление в пневмосистеме РБ ниже значения заданного предупредительной уставкой
	{ 682	,1	,1	, &A2AB14LDU},	//(A2AB14LDU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
	{ 683	,1	,1	, &A2AB16LDU},	//(A2AB16LDU) Блокировка перемещения РБ1: выполняется программа 200 с
	{ 684	,1	,1	, &A2AB17LDU},	//(A2AB17LDU) Блокировка перемещения РБ1: выполняется программа 20 мин
	{ 685	,1	,1	, &A2AD01LDU},	//(A2AD01LDU) Разрешение движения РБ1
	{ 686	,8	,1	, &A2CV02RDU},	//(A2CV02RDU) Заданная скорость перемещения РБ1
	{ 687	,8	,1	, &B2CV01RDU},	//(B2CV01RDU) Измеренная скорость перемещения РБ2
	{ 688	,1	,1	, &B2AB04LDU},	//(B2AB04LDU) Блокировка движения РБ2 нет перемещения  РБ2
	{ 689	,1	,1	, &B2AB02LDU},	//(B2AB02LDU) Блокировка движения РБ2: превышение заданной скорости
	{ 690	,1	,1	, &B2AB01LDU},	//(B2AB01LDU) Блокировка движения РБ2: скорость перемещения менее заданной
	{ 691	,1	,1	, &B2AZ03LDU},	//(B2AZ03LDU) Несанкционированное перемещение РБ2
	{ 692	,1	,1	, &B2AD11LDU},	//(B2AD11LDU) Сигнал на перемещение РБ2 вверх
	{ 693	,1	,1	, &B2AD21LDU},	//(B2AD21LDU) Сигнал на перемещение РБ2 вниз
	{ 694	,1	,1	, &B2AD02LDU},	//(B2AD02LDU) 0-й бит скорости РБ2
	{ 695	,1	,1	, &B2AD03LDU},	//(B2AD03LDU) 1-й бит скорости РБ2
	{ 696	,1	,1	, &B2AD04LDU},	//(B2AD04LDU) 2-й бит скорости РБ2
	{ 697	,8	,1	, &A1CV02RDU},	//(A1CV02RDU) Заданная скорость перемещения ББ1
	{ 698	,1	,1	, &A1AB07LDU},	//(A1AB07LDU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
	{ 699	,1	,1	, &A1AB08LDU},	//(A1AB08LDU) Блокировка подъёма ББ1 - реактор не на рабочем месте
	{ 700	,1	,1	, &A1AB05LDU},	//(A1AB05LDU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
	{ 701	,1	,1	, &A1AB06LDU},	//(A1AB06LDU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
	{ 702	,1	,1	, &A1AB09LDU},	//(A1AB09LDU) Блокировка подъёма ББ1- АНИ не установлен
	{ 703	,1	,1	, &A1AB10LDU},	//(A1AB10LDU) Блокировка подъёма ББ1- есть сигнал общего сброса
	{ 704	,1	,1	, &A1AB11LDU},	//(A1AB11LDU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
	{ 705	,1	,1	, &A1AB12LDU},	//(A1AB12LDU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 706	,1	,1	, &A1AB13LDU},	//(A1AB13LDU) Блокировка подъёма ББ1- давление в пневмосистеме ББ1 ниже значения заданного предупредительной уставкой
	{ 707	,1	,1	, &A1AB14LDU},	//(A1AB14LDU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
	{ 708	,1	,1	, &A1AB16LDU},	//(A1AB16LDU) Блокировка перемещения ББ1: выполняется программа 200 с
	{ 709	,1	,1	, &A1AB17LDU},	//(A1AB17LDU) Блокировка перемещения ББ1: выполняется программа 20 мин
	{ 710	,1	,1	, &A1AB18LDU},	//(A1AB18LDU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
	{ 711	,1	,1	, &B1VS12LDU},	//(B1VS12LDU) Движение ББ2 в сторону ВУ
	{ 712	,8	,1	, &B1CV01RDU},	//(B1CV01RDU) Измеренная скорость перемещения ББ2
	{ 713	,1	,1	, &B1AB04LDU},	//(B1AB04LDU) Блокировка движения ББ2 нет перемещения  ББ2
	{ 714	,1	,1	, &B1AB02LDU},	//(B1AB02LDU) Блокировка движения ББ2: превышение заданной скорости
	{ 715	,1	,1	, &B1AB01LDU},	//(B1AB01LDU) Блокировка движения ББ2: скорость перемещения менее заданной
	{ 716	,1	,1	, &B1VS22LDU},	//(B1VS22LDU) Движение ББ2 в сторону НУ
	{ 717	,1	,1	, &B1AZ03LDU},	//(B1AZ03LDU) Сброс ББ2: Несанкционированное перемещение ББ2
	{ 718	,1	,1	, &B1AD11LDU},	//(B1AD11LDU) Сигнал на перемещение ББ2 вверх
	{ 719	,1	,1	, &B1AD21LDU},	//(B1AD21LDU) Сигнал на перемещение ББ2 вниз
	{ 720	,1	,1	, &R2AB04LDU},	//(R2AB04LDU) Блокировка МДЗ2 -Ошибка в направлении  движения
	{ 721	,1	,1	, &R1AD10LDU},	//(R1AD10LDU) Опустить МДЗ1 в зону облучения
	{ 722	,1	,1	, &R1AD20LDU},	//(R1AD20LDU) Поднять МДЗ1
	{ 723	,1	,1	, &R1IS11LDU},	//(R1IS11LDU) Приход на ВУ МДЗ1
	{ 724	,1	,1	, &R1VS22LDU},	//(R1VS22LDU) Движение МДЗ1 в сторону НУ
	{ 725	,1	,1	, &R2VS22LDU},	//(R2VS22LDU) Движение МДЗ2 в сторону НУ
	{ 726	,1	,1	, &R2VS12LDU},	//(R2VS12LDU) Движение МДЗ2 в сторону ВУ
	{ 727	,1	,1	, &R1VS12LDU},	//(R1VS12LDU) Движение МДЗ1 в сторону ВУ
	{ 728	,1	,1	, &R2IS11LDU},	//(R2IS11LDU) Приход на ВУ МДЗ2
	{ 729	,1	,1	, &A1VS12LDU},	//(A1VS12LDU) Движение ББ1 в сторону ВУ
	{ 730	,8	,1	, &A1CV01RDU},	//(A1CV01RDU) Измеренная скорость перемещения ББ1
	{ 731	,1	,1	, &A1AB04LDU},	//(A1AB04LDU) Блокировка движения ББ1 нет перемещения  ББ1
	{ 732	,1	,1	, &A1AB02LDU},	//(A1AB02LDU) Блокировка движения ББ1: превышение заданной скорости
	{ 733	,1	,1	, &A1AB01LDU},	//(A1AB01LDU) Блокировка движения ББ1: скорость перемещения менее заданной
	{ 734	,1	,1	, &A1VS22LDU},	//(A1VS22LDU) Движение ББ1 в сторону НУ
	{ 735	,1	,1	, &A1AZ03LDU},	//(A1AZ03LDU) Сброс ББ1: Несанкционированное перемещение ББ1
	{ 736	,1	,1	, &A1AD11LDU},	//(A1AD11LDU) Сигнал на перемещение ББ1 вверх
	{ 737	,1	,1	, &A1AD21LDU},	//(A1AD21LDU) Сигнал на перемещение ББ1 вниз
	{ 738	,1	,1	, &A1AD02LDU},	//(A1AD02LDU) 0-й бит скорости ББ1
	{ 739	,1	,1	, &A1AD03LDU},	//(A1AD03LDU) 1-й бит скорости ББ1
	{ 740	,1	,1	, &A1AD04LDU},	//(A1AD04LDU) 2-й бит скорости ББ1
	{ 741	,1	,1	, &A1AD05LDU},	//(A1AD05LDU) паритет команды на ББ1
	{ 742	,1	,1	, &A1AD01LDU},	//(A1AD01LDU) Разрешение движения ББ1
	{ 743	,8	,1	, &fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
	{ 744	,5	,1	, &dEM_A1UC05UDU},	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
	{ 745	,5	,1	, &dEM_A1UC06UDU},	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
	{ 746	,5	,1	, &dEM_A2UC06UDU},	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
	{ 747	,5	,1	, &dEM_A2UC05UDU},	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
	{ 748	,8	,1	, &fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
	{ 749	,5	,1	, &dEM_A3UC06UDU},	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
	{ 750	,5	,1	, &dEM_A3UC05UDU},	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
	{ 751	,8	,1	, &fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
	{ 752	,5	,1	, &dEM_A8UC06UDU},	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
	{ 753	,8	,1	, &fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
	{ 754	,5	,1	, &dEM_A8UC05UDU},	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
	{ 755	,8	,1	, &fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{ 756	,8	,1	, &fEM_R0UV82RDU},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{ 757	,8	,1	, &fEM_R0UV83RDU},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{ 758	,8	,1	, &fEM_R0UV84RDU},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{ 759	,8	,1	, &fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 760	,8	,1	, &fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{ 761	,8	,1	, &fEM_R0UV87RDU},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 762	,8	,1	, &fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{ 763	,8	,1	, &fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{ 764	,8	,1	, &fEM_A3UP43RDU},	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
	{ 765	,8	,1	, &fEM_A3UP44RDU},	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
	{ 766	,8	,1	, &fEM_A3UP53RDU},	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
	{ 767	,8	,1	, &fEM_A3UP85RDU},	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 768	,8	,1	, &fEM_A3UP88RDU},	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 769	,8	,1	, &fEM_A3UP86RDU},	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 770	,8	,1	, &fEM_B8UV01RDU},	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
	{ 771	,8	,1	, &fEM_B8UV02RDU},	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
	{ 772	,8	,1	, &fEM_B8UV03RDU},	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
	{ 773	,8	,1	, &fEM_B8UL04RDU},	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
	{ 774	,3	,1	, &iEM_A2UV03CDU},	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
	{ 775	,8	,1	, &fEM_A2UV01RDU},	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
	{ 776	,8	,1	, &fEM_A2UV02RDU},	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
	{ 777	,8	,1	, &fEM_A1UV01RDU},	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
	{ 778	,8	,1	, &fEM_A1UV02RDU},	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
	{ 779	,8	,1	, &fEM_A1UC06RDU},	//(A1UC06RDU) Уставка определения самохода ББ  мм
	{ 780	,8	,1	, &fEM_A1UC05RDU},	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
	{ 781	,8	,1	, &fEM_A1UL04RDU},	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
	{ 782	,8	,1	, &fEM_A3UV01RDU},	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
	{ 783	,8	,1	, &fEM_A3UV02RDU},	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
	{ 784	,8	,1	, &fEM_A3UC06RDU},	//(A3UC06RDU) Уставка определения самохода ИС1  мм
	{ 785	,8	,1	, &fEM_A3UC05RDU},	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
	{ 786	,8	,1	, &fEM_A3UL04RDU},	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
	{ 787	,8	,1	, &fEM_A3UP54RDU},	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
	{ 788	,8	,1	, &fEM_A3UP87RDU},	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 789	,8	,1	, &fEM_R0UL05RDU},	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
	{ 790	,8	,1	, &fEM_R0UL20RDU},	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
	{ 791	,8	,1	, &fEM_B8UV04RDU},	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
	{ 792	,8	,1	, &fEM_B8UC06RDU},	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
	{ 793	,8	,1	, &fEM_B8UC05RDU},	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
	{ 794	,8	,1	, &fEM_A2UL05RDU},	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
	{ 795	,8	,1	, &fEM_A2UL03RDU},	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{ 796	,8	,1	, &fEM_A2UC06RDU},	//(A2UC06RDU) Уставка определения самохода РБ  мм
	{ 797	,8	,1	, &fEM_A2UC05RDU},	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
	{ 798	,8	,1	, &fEM_A2UL04RDU},	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
	{ 799	,8	,1	, &fEM_A1UL03RDU},	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
	{ 800	,8	,1	, &fEM_A1UL05RDU},	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
	{ 801	,8	,1	, &fEM_A3UL03RDU},	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
	{ 802	,8	,1	, &fEM_A3UL05RDU},	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
	{ 803	,8	,1	, &fEM_A1UC08RDU},	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
	{ 804	,8	,1	, &fEM_A3UC08RDU},	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
	{ 805	,8	,1	, &fEM_A1UC07RDU},	//(A1UC07RDU) Зона возврата при наведении ББ мм
	{ 806	,8	,1	, &fEM_A1UL01RDU},	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 807	,8	,1	, &fEM_A3UC07RDU},	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
	{ 808	,8	,1	, &fEM_A3UL01RDU},	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 809	,8	,1	, &fEM_A2UC08RDU},	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
	{ 810	,8	,1	, &fEM_A2UC07RDU},	//(A2UC07RDU) Зона возврата при наведении РБ  мм
	{ 811	,8	,1	, &fEM_A2UL01RDU},	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 812	,8	,1	, &fEM_B8UC01RDU},	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
	{ 813	,8	,1	, &fEM_B8UL07RDU},	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
	{ 814	,8	,1	, &fEM_B8UC02RDU},	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
	{ 815	,8	,1	, &fEM_B8UL01RDU},	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 816	,8	,1	, &fEM_B8UL05RDU},	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
	{ 817	,8	,1	, &fEM_B8UL03RDU},	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
	{ 818	,8	,1	, &fEM_B8UL06RDU},	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
	{ 819	,8	,1	, &fEM_A9UZ03RDU},	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
	{ 820	,8	,1	, &fEM_A9UZ04RDU},	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
	{ 821	,8	,1	, &fEM_A9UZ05RDU},	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
	{ 822	,8	,1	, &fEM_R4UZ04RDU},	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
	{ 823	,8	,1	, &fEM_R4UZ03RDU},	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
	{ 824	,8	,1	, &fEM_R4UZ05RDU},	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
	{ 825	,8	,1	, &fEM_A5UZ03RDU},	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
	{ 826	,8	,1	, &fEM_A5UZ04RDU},	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
	{ 827	,8	,1	, &fEM_A5UZ05RDU},	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
	{ 828	,8	,1	, &fEM_A4UZ03RDU},	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
	{ 829	,8	,1	, &fEM_A4UZ04RDU},	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
	{ 830	,8	,1	, &fEM_A4UZ05RDU},	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
	{ 831	,8	,1	, &fEM_A6UZ03RDU},	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
	{ 832	,8	,1	, &fEM_A6UZ04RDU},	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
	{ 833	,8	,1	, &fEM_A6UZ05RDU},	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
	{ 834	,8	,1	, &fEM_R1UZ03RDU},	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
	{ 835	,8	,1	, &fEM_R1UZ04RDU},	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
	{ 836	,8	,1	, &fEM_R1UZ05RDU},	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
	{ 837	,8	,1	, &fEM_R5UL10RDU},	//(R5UL10RDU) Время полного хода ворот отстойной зоны сек
	{ 838	,8	,1	, &fEM_R5UZ03RDU},	//(R5UZ03RDU) Время задержки блокировки ворот отстойной зоны по самоходу сек
	{ 839	,8	,1	, &fEM_R5UZ04RDU},	//(R5UZ04RDU) Время задержки блокировки ворот отстойной зоны по недвижению сек
	{ 840	,8	,1	, &fEM_R0UL04RDU},	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
	{ 841	,8	,1	, &fEM_R0UL06RDU},	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
	{ 842	,8	,1	, &fEM_R0UL03RDU},	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
	{ 843	,8	,1	, &fEM_R0UL17RDU},	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
	{ 844	,8	,1	, &fEM_R0UL19RDU},	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{ 845	,8	,1	, &fEM_R0UL07RDU},	//(R0UL07RDU) Время срабатывания верхней АС II УР
	{ 846	,8	,1	, &fEM_R0UL18RDU},	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
	{ 847	,8	,1	, &fEM_R0UL16RDU},	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
	{ 848	,8	,1	, &fEM_R0UL02RDU},	//(R0UL02RDU) Время задержки  ИНИ
	{ 849	,8	,1	, &fEM_R3UZ03RDU},	//(R3UZ03RDU) Время задержки блокировки гомогеннных дверей по самоходу сек
	{ 850	,8	,1	, &fEM_R3UL10RDU},	//(R3UL10RDU) Время полного хода гомогенных дверей сек
	{ 851	,8	,1	, &fEM_R3UZ04RDU},	//(R3UZ04RDU) Время задержки блокировки гомогенных дверей по недвижению сек
	{ 852	,8	,1	, &fEM_R0UN08RDU},	//(R0UN08RDU) Ограничение 8 по мощности
	{ 853	,8	,1	, &fEM_R0UN07RDU},	//(R0UN07RDU) Ограничение 7 по мощности
	{ 854	,8	,1	, &fEM_R0UN06RDU},	//(R0UN06RDU) Ограничение 6 по мощности
	{ 855	,8	,1	, &fEM_R0UN05RDU},	//(R0UN05RDU) Ограничение 5 по мощности
	{ 856	,8	,1	, &fEM_R0UN04RDU},	//(R0UN04RDU) Ограничение 4 по мощности
	{ 857	,8	,1	, &fEM_R0UN03RDU},	//(R0UN03RDU) Ограничение 3 по мощности
	{ 858	,8	,1	, &fEM_R0UN02RDU},	//(R0UN02RDU) Ограничение 2 по мощности
	{ 859	,8	,1	, &fEM_R0UN01RDU},	//(R0UN01RDU) Ограничение 1 по мощности
	{ 860	,8	,1	, &fEM_A2UC82RDU},	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
	{ 861	,8	,1	, &fEM_A2UC83RDU},	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
	{ 862	,8	,1	, &fEM_A1UC83RDU},	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
	{ 863	,8	,1	, &fEM_A2UC81RDU},	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
	{ 864	,8	,1	, &fEM_A1UC81RDU},	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
	{ 865	,8	,1	, &fEM_A1UC82RDU},	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
	{ 866	,8	,1	, &fEM_A2UL83RDU},	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{ 867	,8	,1	, &fEM_A3UC81RDU},	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
	{ 868	,8	,1	, &fEM_A3UC82RDU},	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
	{ 869	,8	,1	, &fEM_R0UN80RDU},	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
	{ 870	,8	,1	, &fEM_A3UP34RDU},	//(A3UP34RDU) Время заполнения ресивера ИС (в 10 мс)
	{ 871	,3	,1	, &iEM_A2UV01IDU},	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
	{ 872	,3	,1	, &iEM_A2UV02IDU},	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
	{ 873	,3	,1	, &iEM_A1UV01IDU},	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
	{ 874	,3	,1	, &iEM_A1UV02IDU},	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
	{ 875	,3	,1	, &iEM_A1UV03IDU},	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
	{ 876	,3	,1	, &iEM_A3UV01IDU},	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
	{ 877	,3	,1	, &iEM_A3UV02IDU},	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
	{ 878	,1	,1	, &lEM_R0MD01LC1},	//(R0MD01LC1) Ручное управление ОРР
	{ 879	,8	,1	, &fEM_A3UC09RDU},	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
	{ 880	,8	,1	, &fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
	{ 881	,8	,1	, &fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
	{ 882	,8	,1	, &fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
	{ 883	,8	,1	, &fEM_R0UL21RDU},	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
	{ 884	,8	,1	, &fEM_R0UN09RDU},	//(R0UN09RDU) Минимальный период при регулировании мощности
	{ 885	,8	,1	, &fEM_R0UN11RDU},	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
	{ 886	,8	,1	, &fEM_R0UN12RDU},	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
	{ 887	,8	,1	, &fEM_R0UN13RDU},	//(R0UN13RDU) Минимальное изменение координаты, мм
	{ 888	,8	,1	, &fEM_R0UN14RDU},	//(R0UN14RDU) Максимальная координата штока ИМ, мм
	{ 889	,8	,1	, &fEM_R0UN16RDU},	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
	{ 890	,8	,1	, &fEM_R0UN17RDU},	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
	{ 891	,8	,1	, &fEM_R0UN18RDU},	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
	{ 892	,8	,1	, &fEM_R0UN19RDU},	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
	{ 893	,8	,1	, &fEM_R0UN70LDU},	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
	{ 894	,8	,1	, &fEM_R0UN71LDU},	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
	{ 895	,8	,1	, &fEM_R0UN72LDU},	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
	{ 896	,8	,1	, &fEM_R0UN73LDU},	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
	{ 897	,8	,1	, &fEM_R0UN74LDU},	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
	{ 898	,8	,1	, &fEM_R0UN75LDU},	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
	{ 899	,8	,1	, &fEM_R0UN80LDU},	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
	{ 900	,8	,1	, &fEM_R0UN81LDU},	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
	{ 901	,8	,1	, &fEM_R0UN82LDU},	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
	{ 902	,8	,1	, &fEM_R0UN83LDU},	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
	{ 903	,8	,1	, &fEM_R0UN84LDU},	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
	{ 904	,8	,1	, &fEM_R0UN85LDU},	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
	{ 905	,8	,1	, &fEM_R0UT20RDU},	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
	{ 906	,8	,1	, &fEM_R0UN25RDU},	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
	{ 907	,8	,1	, &fEM_R0UN15RDU},	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
	{ 908	,8	,1	, &fEM_R0UN26RDU},	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
	{ 909	,8	,1	, &fEM_R0UN27RDU},	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
	{ 910	,8	,1	, &fEM_R0UN24RDU},	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 911	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 912	,8	,1	, &internal2_m191_y0},	//(internal2_m191_y0) y0
	{ 913	,8	,1	, &internal2_m189_y0},	//(internal2_m189_y0) y0
	{ 914	,1	,1	, &internal2_m219_y0},	//(internal2_m219_y0) state
	{ 915	,1	,1	, &internal2_m214_y0},	//(internal2_m214_y0) state
	{ 916	,1	,1	, &internal2_m203_y1},	//(internal2_m203_y1) y1 - внутренний параметр
	{ 917	,1	,1	, &internal2_m209_y1},	//(internal2_m209_y1) y1 - внутренний параметр
	{ 918	,1	,1	, &internal2_m193_y1},	//(internal2_m193_y1) y1 - внутренний параметр
	{ 919	,1	,1	, &internal2_m200_y1},	//(internal2_m200_y1) y1 - внутренний параметр
	{ 920	,5	,1	, &internal2_m17_Nk0},	//(internal2_m17_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 921	,1	,1	, &internal2_m17_SetFlag},	//(internal2_m17_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 922	,5	,1	, &internal2_m108_Nk0},	//(internal2_m108_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 923	,1	,1	, &internal2_m108_SetFlag},	//(internal2_m108_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 924	,5	,1	, &internal2_m112_Nk0},	//(internal2_m112_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 925	,1	,1	, &internal2_m112_SetFlag},	//(internal2_m112_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 926	,5	,1	, &internal2_m75_Nk0},	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 927	,1	,1	, &internal2_m75_SetFlag},	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 928	,5	,1	, &internal2_m77_Nk0},	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 929	,1	,1	, &internal2_m77_SetFlag},	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 930	,5	,1	, &internal2_m45_Nk0},	//(internal2_m45_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 931	,1	,1	, &internal2_m45_SetFlag},	//(internal2_m45_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 932	,5	,1	, &internal2_m53_Nk0},	//(internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 933	,1	,1	, &internal2_m53_SetFlag},	//(internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 934	,5	,1	, &internal2_m15_Nk0},	//(internal2_m15_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 935	,1	,1	, &internal2_m15_SetFlag},	//(internal2_m15_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 936	,8	,1	, &internal1_m2122_tx},	//(internal1_m2122_tx) tx - время накопленное сек
	{ 937	,18	,1	, &internal1_m2122_y0},	//(internal1_m2122_y0) y0
	{ 938	,8	,1	, &internal1_m2125_tx},	//(internal1_m2125_tx) tx - время накопленное сек
	{ 939	,18	,1	, &internal1_m2125_y0},	//(internal1_m2125_y0) y0
	{ 940	,8	,1	, &internal1_m2124_tx},	//(internal1_m2124_tx) tx - время накопленное сек
	{ 941	,18	,1	, &internal1_m2124_y0},	//(internal1_m2124_y0) y0
	{ 942	,8	,1	, &internal1_m2161_tx},	//(internal1_m2161_tx) tx - внутренний параметр
	{ 943	,8	,1	, &internal1_m2159_tx},	//(internal1_m2159_tx) tx - время накопленное сек
	{ 944	,18	,1	, &internal1_m2159_y0},	//(internal1_m2159_y0) y0
	{ 945	,1	,1	, &internal1_m2164_q0},	//(internal1_m2164_q0) q0 - внутренний параметр
	{ 946	,1	,1	, &internal1_m2131_q0},	//(internal1_m2131_q0) q0 - внутренний параметр
	{ 947	,8	,1	, &internal1_m2139_tx},	//(internal1_m2139_tx) tx - внутренний параметр
	{ 948	,1	,1	, &internal1_m2137_q0},	//(internal1_m2137_q0) q0 - внутренний параметр
	{ 949	,8	,1	, &internal1_m2007_tx},	//(internal1_m2007_tx) tx - время накопленное сек
	{ 950	,18	,1	, &internal1_m2007_y0},	//(internal1_m2007_y0) y0
	{ 951	,8	,1	, &internal1_m1999_tx},	//(internal1_m1999_tx) tx - время накопленное сек
	{ 952	,18	,1	, &internal1_m1999_y0},	//(internal1_m1999_y0) y0
	{ 953	,8	,1	, &internal1_m1664_tx},	//(internal1_m1664_tx) tx - время накопленное сек
	{ 954	,18	,1	, &internal1_m1664_y0},	//(internal1_m1664_y0) y0
	{ 955	,8	,1	, &internal1_m1663_tx},	//(internal1_m1663_tx) tx - время накопленное сек
	{ 956	,18	,1	, &internal1_m1663_y0},	//(internal1_m1663_y0) y0
	{ 957	,1	,1	, &internal1_m1703_q0},	//(internal1_m1703_q0) q0 - внутренний параметр
	{ 958	,1	,1	, &internal1_m1701_q0},	//(internal1_m1701_q0) q0 - внутренний параметр
	{ 959	,1	,1	, &internal1_m1700_q0},	//(internal1_m1700_q0) q0 - внутренний параметр
	{ 960	,1	,1	, &internal1_m1728_q0},	//(internal1_m1728_q0) q0 - внутренний параметр
	{ 961	,8	,1	, &internal1_m742_tx},	//(internal1_m742_tx) tx - время накопленное сек
	{ 962	,18	,1	, &internal1_m742_y0},	//(internal1_m742_y0) y0
	{ 963	,8	,1	, &internal1_m2013_tx},	//(internal1_m2013_tx) tx - внутренний параметр
	{ 964	,8	,1	, &internal1_m2003_tx},	//(internal1_m2003_tx) tx - внутренний параметр
	{ 965	,8	,1	, &internal1_m1993_tx},	//(internal1_m1993_tx) tx - внутренний параметр
	{ 966	,1	,1	, &internal1_m2006_q0},	//(internal1_m2006_q0) q0 - внутренний параметр
	{ 967	,1	,1	, &internal1_m1998_q0},	//(internal1_m1998_q0) q0 - внутренний параметр
	{ 968	,8	,1	, &internal1_m1969_tx},	//(internal1_m1969_tx) tx - внутренний параметр
	{ 969	,8	,1	, &internal1_m1980_tx},	//(internal1_m1980_tx) tx - внутренний параметр
	{ 970	,8	,1	, &internal1_m1965_tx},	//(internal1_m1965_tx) tx - внутренний параметр
	{ 971	,1	,1	, &internal1_m1972_q0},	//(internal1_m1972_q0) q0 - внутренний параметр
	{ 972	,1	,1	, &internal1_m1984_q0},	//(internal1_m1984_q0) q0 - внутренний параметр
	{ 973	,8	,1	, &internal1_m1943_tx},	//(internal1_m1943_tx) tx - внутренний параметр
	{ 974	,8	,1	, &internal1_m51_tx},	//(internal1_m51_tx) tx - внутренний параметр
	{ 975	,8	,1	, &internal1_m327_tx},	//(internal1_m327_tx) tx - внутренний параметр
	{ 976	,8	,1	, &internal1_m285_tx},	//(internal1_m285_tx) tx - внутренний параметр
	{ 977	,8	,1	, &internal1_m743_tx},	//(internal1_m743_tx) tx - внутренний параметр
	{ 978	,8	,1	, &internal1_m1419_tx},	//(internal1_m1419_tx) tx - внутренний параметр
	{ 979	,8	,1	, &internal1_m110_tx},	//(internal1_m110_tx) tx - внутренний параметр
	{ 980	,8	,1	, &internal1_m112_tx},	//(internal1_m112_tx) tx - внутренний параметр
	{ 981	,8	,1	, &internal1_m117_tx},	//(internal1_m117_tx) tx - внутренний параметр
	{ 982	,8	,1	, &internal1_m21_tx},	//(internal1_m21_tx) tx - внутренний параметр
	{ 983	,8	,1	, &internal1_m13_tx},	//(internal1_m13_tx) tx - внутренний параметр
	{ 984	,8	,1	, &internal1_m1951_tx},	//(internal1_m1951_tx) tx - внутренний параметр
	{ 985	,8	,1	, &internal1_m1938_tx},	//(internal1_m1938_tx) tx - внутренний параметр
	{ 986	,8	,1	, &internal1_m2036_tx},	//(internal1_m2036_tx) tx - внутренний параметр
	{ 987	,8	,1	, &internal1_m2039_tx},	//(internal1_m2039_tx) tx - внутренний параметр
	{ 988	,8	,1	, &internal1_m1865_tx},	//(internal1_m1865_tx) tx - внутренний параметр
	{ 989	,8	,1	, &internal1_m76_tx},	//(internal1_m76_tx) tx - внутренний параметр
	{ 990	,8	,1	, &internal1_m298_tx},	//(internal1_m298_tx) tx - время накопленное сек
	{ 991	,18	,1	, &internal1_m298_y0},	//(internal1_m298_y0) y0
	{ 992	,8	,1	, &internal1_m1859_tx},	//(internal1_m1859_tx) tx - время накопленное сек
	{ 993	,18	,1	, &internal1_m1859_y0},	//(internal1_m1859_y0) y0
	{ 994	,8	,1	, &internal1_m1857_tx},	//(internal1_m1857_tx) tx - время накопленное сек
	{ 995	,18	,1	, &internal1_m1857_y0},	//(internal1_m1857_y0) y0
	{ 996	,8	,1	, &internal1_m1846_tx},	//(internal1_m1846_tx) tx - время накопленное сек
	{ 997	,18	,1	, &internal1_m1846_y0},	//(internal1_m1846_y0) y0
	{ 998	,8	,1	, &internal1_m1866_q0},	//(internal1_m1866_q0) q0 - внутренний параметр
	{ 999	,8	,1	, &internal1_m1439_q0},	//(internal1_m1439_q0) q0 - внутренний параметр
	{ 1000	,8	,1	, &internal1_m1476_q0},	//(internal1_m1476_q0) q0 - внутренний параметр
	{ 1001	,8	,1	, &internal1_m1479_q0},	//(internal1_m1479_q0) q0 - внутренний параметр
	{ 1002	,8	,1	, &internal1_m1905_q0},	//(internal1_m1905_q0) q0 - внутренний параметр
	{ 1003	,8	,1	, &internal1_m1882_tx},	//(internal1_m1882_tx) tx - время накопленное сек
	{ 1004	,18	,1	, &internal1_m1882_y0},	//(internal1_m1882_y0) y0
	{ 1005	,8	,1	, &internal1_m1898_tx},	//(internal1_m1898_tx) tx - время накопленное сек
	{ 1006	,18	,1	, &internal1_m1898_y0},	//(internal1_m1898_y0) y0
	{ 1007	,8	,1	, &internal1_m1895_tx},	//(internal1_m1895_tx) tx - время накопленное сек
	{ 1008	,18	,1	, &internal1_m1895_y0},	//(internal1_m1895_y0) y0
	{ 1009	,8	,1	, &internal1_m2026_tx},	//(internal1_m2026_tx) tx - время накопленное сек
	{ 1010	,18	,1	, &internal1_m2026_y0},	//(internal1_m2026_y0) y0
	{ 1011	,8	,1	, &internal1_m2035_tx},	//(internal1_m2035_tx) tx - время накопленное сек
	{ 1012	,18	,1	, &internal1_m2035_y0},	//(internal1_m2035_y0) y0
	{ 1013	,8	,1	, &internal1_m1796_tx},	//(internal1_m1796_tx) tx - время накопленное сек
	{ 1014	,18	,1	, &internal1_m1796_y0},	//(internal1_m1796_y0) y0
	{ 1015	,8	,1	, &internal1_m1795_tx},	//(internal1_m1795_tx) tx - время накопленное сек
	{ 1016	,18	,1	, &internal1_m1795_y0},	//(internal1_m1795_y0) y0
	{ 1017	,8	,1	, &internal1_m1794_tx},	//(internal1_m1794_tx) tx - время накопленное сек
	{ 1018	,18	,1	, &internal1_m1794_y0},	//(internal1_m1794_y0) y0
	{ 1019	,8	,1	, &internal1_m1793_tx},	//(internal1_m1793_tx) tx - время накопленное сек
	{ 1020	,18	,1	, &internal1_m1793_y0},	//(internal1_m1793_y0) y0
	{ 1021	,8	,1	, &internal1_m1490_tx},	//(internal1_m1490_tx) tx - время накопленное сек
	{ 1022	,18	,1	, &internal1_m1490_y0},	//(internal1_m1490_y0) y0
	{ 1023	,8	,1	, &internal1_m1484_tx},	//(internal1_m1484_tx) tx - время накопленное сек
	{ 1024	,18	,1	, &internal1_m1484_y0},	//(internal1_m1484_y0) y0
	{ 1025	,8	,1	, &internal1_m1435_tx},	//(internal1_m1435_tx) tx - время накопленное сек
	{ 1026	,18	,1	, &internal1_m1435_y0},	//(internal1_m1435_y0) y0
	{ 1027	,8	,1	, &internal1_m826_tx},	//(internal1_m826_tx) tx - время накопленное сек
	{ 1028	,18	,1	, &internal1_m826_y0},	//(internal1_m826_y0) y0
	{ 1029	,8	,1	, &internal1_m825_tx},	//(internal1_m825_tx) tx - время накопленное сек
	{ 1030	,18	,1	, &internal1_m825_y0},	//(internal1_m825_y0) y0
	{ 1031	,8	,1	, &internal1_m832_tx},	//(internal1_m832_tx) tx - время накопленное сек
	{ 1032	,18	,1	, &internal1_m832_y0},	//(internal1_m832_y0) y0
	{ 1033	,8	,1	, &internal1_m182_tx},	//(internal1_m182_tx) tx - время накопленное сек
	{ 1034	,18	,1	, &internal1_m182_y0},	//(internal1_m182_y0) y0
	{ 1035	,8	,1	, &internal1_m187_tx},	//(internal1_m187_tx) tx - время накопленное сек
	{ 1036	,18	,1	, &internal1_m187_y0},	//(internal1_m187_y0) y0
	{ 1037	,8	,1	, &internal1_m193_tx},	//(internal1_m193_tx) tx - время накопленное сек
	{ 1038	,18	,1	, &internal1_m193_y0},	//(internal1_m193_y0) y0
	{ 1039	,8	,1	, &internal1_m519_tx},	//(internal1_m519_tx) tx - время накопленное сек
	{ 1040	,18	,1	, &internal1_m519_y0},	//(internal1_m519_y0) y0
	{ 1041	,8	,1	, &internal1_m2063_tx},	//(internal1_m2063_tx) tx - внутренний параметр
	{ 1042	,8	,1	, &internal1_m1173_tx},	//(internal1_m1173_tx) tx - внутренний параметр
	{ 1043	,8	,1	, &internal1_m1605_tx},	//(internal1_m1605_tx) tx - время накопленное сек
	{ 1044	,18	,1	, &internal1_m1605_y0},	//(internal1_m1605_y0) y0
	{ 1045	,8	,1	, &internal1_m1139_tx},	//(internal1_m1139_tx) tx - время накопленное сек
	{ 1046	,18	,1	, &internal1_m1139_y0},	//(internal1_m1139_y0) y0
	{ 1047	,8	,1	, &internal1_m1326_tx},	//(internal1_m1326_tx) tx - время накопленное сек
	{ 1048	,18	,1	, &internal1_m1326_y0},	//(internal1_m1326_y0) y0
	{ 1049	,8	,1	, &internal1_m926_tx},	//(internal1_m926_tx) tx - время накопленное сек
	{ 1050	,18	,1	, &internal1_m926_y0},	//(internal1_m926_y0) y0
	{ 1051	,8	,1	, &internal1_m1233_tx},	//(internal1_m1233_tx) tx - время накопленное сек
	{ 1052	,18	,1	, &internal1_m1233_y0},	//(internal1_m1233_y0) y0
	{ 1053	,1	,1	, &internal1_m1083_q0},	//(internal1_m1083_q0) q0 - внутренний параметр
	{ 1054	,1	,1	, &internal1_m1081_q0},	//(internal1_m1081_q0) q0 - внутренний параметр
	{ 1055	,1	,1	, &internal1_m1080_q0},	//(internal1_m1080_q0) q0 - внутренний параметр
	{ 1056	,1	,1	, &internal1_m1078_q0},	//(internal1_m1078_q0) q0 - внутренний параметр
	{ 1057	,1	,1	, &internal1_m1077_q0},	//(internal1_m1077_q0) q0 - внутренний параметр
	{ 1058	,1	,1	, &internal1_m1075_q0},	//(internal1_m1075_q0) q0 - внутренний параметр
	{ 1059	,1	,1	, &internal1_m1074_q0},	//(internal1_m1074_q0) q0 - внутренний параметр
	{ 1060	,1	,1	, &internal1_m1072_q0},	//(internal1_m1072_q0) q0 - внутренний параметр
	{ 1061	,1	,1	, &internal1_m1071_q0},	//(internal1_m1071_q0) q0 - внутренний параметр
	{ 1062	,1	,1	, &internal1_m52_x0},	//(internal1_m52_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1063	,1	,1	, &internal1_m991_q0},	//(internal1_m991_q0) q0 - внутренний параметр
	{ 1064	,1	,1	, &internal1_m1427_x0},	//(internal1_m1427_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1065	,1	,1	, &internal1_m1471_x0},	//(internal1_m1471_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1066	,1	,1	, &internal1_m1467_x0},	//(internal1_m1467_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1067	,1	,1	, &internal1_m1874_x0},	//(internal1_m1874_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1068	,1	,1	, &internal1_m1839_x0},	//(internal1_m1839_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1069	,1	,1	, &internal1_m1030_q0},	//(internal1_m1030_q0) q0 - внутренний параметр
	{ 1070	,1	,1	, &internal1_m1042_q0},	//(internal1_m1042_q0) q0 - внутренний параметр
	{ 1071	,1	,1	, &internal1_m1054_q0},	//(internal1_m1054_q0) q0 - внутренний параметр
	{ 1072	,1	,1	, &internal1_m1063_q0},	//(internal1_m1063_q0) q0 - внутренний параметр
	{ 1073	,1	,1	, &internal1_m1041_q0},	//(internal1_m1041_q0) q0 - внутренний параметр
	{ 1074	,1	,1	, &internal1_m1056_q0},	//(internal1_m1056_q0) q0 - внутренний параметр
	{ 1075	,1	,1	, &internal1_m1932_q0},	//(internal1_m1932_q0) q0 - внутренний параметр
	{ 1076	,1	,1	, &internal1_m1931_q0},	//(internal1_m1931_q0) q0 - внутренний параметр
	{ 1077	,3	,1	, &internal1_m315_Step},	//(internal1_m315_Step)  - текущий шаг программы
	{ 1078	,18	,10	, &internal1_m315_rz},	//(internal1_m315_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1079	,8	,1	, &internal1_m315_TimS},	//(internal1_m315_TimS) Время от старта программы
	{ 1080	,1	,1	, &internal1_m315_FinPr0},	//(internal1_m315_FinPr0) FinPr - конец программы
	{ 1081	,1	,1	, &internal1_m315_ErrPr0},	//(internal1_m315_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1082	,1	,1	, &internal1_m315_sbINI0},	//(internal1_m315_sbINI0) sbINI - запуск проверки ИНИ
	{ 1083	,1	,1	, &internal1_m315_sbVuIS0},	//(internal1_m315_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1084	,1	,1	, &internal1_m315_sb2UR0},	//(internal1_m315_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1085	,1	,1	, &internal1_m315_sbNupIS0},	//(internal1_m315_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1086	,1	,1	, &internal1_m315_sbVuRB0},	//(internal1_m315_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1087	,1	,1	, &internal1_m315_MyFirstEnterFlag},	//(internal1_m315_MyFirstEnterFlag)  
	{ 1088	,5	,1	, &internal1_m323_x0},	//(internal1_m323_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1089	,5	,1	, &internal1_m284_TimS},	//(internal1_m284_TimS) Время старта
	{ 1090	,3	,1	, &internal1_m261_Step},	//(internal1_m261_Step)  - текущий шаг программы
	{ 1091	,18	,10	, &internal1_m261_rz},	//(internal1_m261_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1092	,8	,1	, &internal1_m261_TimS},	//(internal1_m261_TimS) Время от старта программы
	{ 1093	,1	,1	, &internal1_m261_FinPr0},	//(internal1_m261_FinPr0) FinPr - конец программы
	{ 1094	,1	,1	, &internal1_m261_ErrPr0},	//(internal1_m261_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1095	,1	,1	, &internal1_m261_sbINI0},	//(internal1_m261_sbINI0) sbINI - запуск проверки ИНИ
	{ 1096	,1	,1	, &internal1_m261_sbVuIS0},	//(internal1_m261_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1097	,1	,1	, &internal1_m261_sb2UR0},	//(internal1_m261_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1098	,1	,1	, &internal1_m261_sbNupIS0},	//(internal1_m261_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1099	,1	,1	, &internal1_m261_sbVuRB0},	//(internal1_m261_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1100	,1	,1	, &internal1_m261_MyFirstEnterFlag},	//(internal1_m261_MyFirstEnterFlag)  
	{ 1101	,1	,1	, &internal1_m1402_q0},	//(internal1_m1402_q0) q0 - внутренний параметр
	{ 1102	,3	,1	, &internal1_m1403_Step},	//(internal1_m1403_Step)  - текущий шаг программы
	{ 1103	,18	,6	, &internal1_m1403_rz},	//(internal1_m1403_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1104	,8	,1	, &internal1_m1403_TimS},	//(internal1_m1403_TimS) Время от старта программы
	{ 1105	,1	,1	, &internal1_m1403_FinPr0},	//(internal1_m1403_FinPr0) FinPr - конец программы
	{ 1106	,1	,1	, &internal1_m1403_ErrPr0},	//(internal1_m1403_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1107	,1	,1	, &internal1_m1403_sbINI0},	//(internal1_m1403_sbINI0) sbINI - запуск проверки ИНИ
	{ 1108	,1	,1	, &internal1_m1403_sbVuIS0},	//(internal1_m1403_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1109	,1	,1	, &internal1_m1403_sb2UR0},	//(internal1_m1403_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1110	,1	,1	, &internal1_m1403_sbNupIS0},	//(internal1_m1403_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1111	,1	,1	, &internal1_m1403_sbVuRB0},	//(internal1_m1403_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1112	,1	,1	, &internal1_m1403_MyFirstEnterFlag},	//(internal1_m1403_MyFirstEnterFlag)  
	{ 1113	,1	,1	, &internal1_m1025_q0},	//(internal1_m1025_q0) q0 - внутренний параметр
	{ 1114	,1	,1	, &internal1_m1022_q0},	//(internal1_m1022_q0) q0 - внутренний параметр
	{ 1115	,1	,1	, &internal1_m1024_q0},	//(internal1_m1024_q0) q0 - внутренний параметр
	{ 1116	,1	,1	, &internal1_m1019_q0},	//(internal1_m1019_q0) q0 - внутренний параметр
	{ 1117	,1	,1	, &internal1_m744_q0},	//(internal1_m744_q0) q0 - внутренний параметр
	{ 1118	,18	,1	, &internal1_m2096_DvUp0},	//(internal1_m2096_DvUp0) - есть команда на движение вперёд
	{ 1119	,18	,1	, &internal1_m2096_DvDw0},	//(internal1_m2096_DvDw0) - есть команда на движение назад
	{ 1120	,18	,1	, &internal1_m2096_FDvUp0},	//(internal1_m2096_FDvUp0) - есть команда на движение вперёд
	{ 1121	,18	,1	, &internal1_m2096_FDvDw0},	//(internal1_m2096_FDvDw0) - есть команда на движение назад
	{ 1122	,18	,1	, &internal1_m2096_BlDv0},	//(internal1_m2096_BlDv0) - была блокировка
	{ 1123	,18	,1	, &internal1_m2096_Pkv0},	//(internal1_m2096_Pkv0) Pkv - передний конечный выключатель
	{ 1124	,18	,1	, &internal1_m2096_Pkav0},	//(internal1_m2096_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1125	,18	,1	, &internal1_m2096_Zkv0},	//(internal1_m2096_Zkv0) Zkv - задний конечный выключатель
	{ 1126	,18	,1	, &internal1_m2096_Zkav0},	//(internal1_m2096_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1127	,8	,1	, &internal1_m2096_txNm},	//(internal1_m2096_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1128	,8	,1	, &internal1_m2096_txSm},	//(internal1_m2096_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1129	,8	,1	, &internal1_m2096_txHr},	//(internal1_m2096_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1130	,8	,1	, &internal1_m2096_txLd},	//(internal1_m2096_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1131	,18	,1	, &internal1_m2096_fef},	//(internal1_m2096_fef) fef
	{ 1132	,18	,1	, &internal1_m2091_DvUp0},	//(internal1_m2091_DvUp0) - есть команда на движение вперёд
	{ 1133	,18	,1	, &internal1_m2091_DvDw0},	//(internal1_m2091_DvDw0) - есть команда на движение назад
	{ 1134	,18	,1	, &internal1_m2091_FDvUp0},	//(internal1_m2091_FDvUp0) - есть команда на движение вперёд
	{ 1135	,18	,1	, &internal1_m2091_FDvDw0},	//(internal1_m2091_FDvDw0) - есть команда на движение назад
	{ 1136	,18	,1	, &internal1_m2091_BlDv0},	//(internal1_m2091_BlDv0) - была блокировка
	{ 1137	,18	,1	, &internal1_m2091_Pkv0},	//(internal1_m2091_Pkv0) Pkv - передний конечный выключатель
	{ 1138	,18	,1	, &internal1_m2091_Pkav0},	//(internal1_m2091_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1139	,18	,1	, &internal1_m2091_Zkv0},	//(internal1_m2091_Zkv0) Zkv - задний конечный выключатель
	{ 1140	,18	,1	, &internal1_m2091_Zkav0},	//(internal1_m2091_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1141	,8	,1	, &internal1_m2091_txNm},	//(internal1_m2091_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1142	,8	,1	, &internal1_m2091_txSm},	//(internal1_m2091_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1143	,8	,1	, &internal1_m2091_txHr},	//(internal1_m2091_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1144	,8	,1	, &internal1_m2091_txLd},	//(internal1_m2091_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1145	,18	,1	, &internal1_m2091_fef},	//(internal1_m2091_fef) fef
	{ 1146	,1	,1	, &internal1_m325_q0},	//(internal1_m325_q0) q0 - внутренний параметр
	{ 1147	,1	,1	, &internal1_m321_q0},	//(internal1_m321_q0) q0 - внутренний параметр
	{ 1148	,1	,1	, &internal1_m280_q0},	//(internal1_m280_q0) q0 - внутренний параметр
	{ 1149	,5	,1	, &internal1_m279_x0},	//(internal1_m279_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1150	,1	,1	, &internal1_m1861_q0},	//(internal1_m1861_q0) q0 - внутренний параметр
	{ 1151	,1	,1	, &internal1_m1849_q0},	//(internal1_m1849_q0) q0 - внутренний параметр
	{ 1152	,1	,1	, &internal1_m1840_q0},	//(internal1_m1840_q0) q0 - внутренний параметр
	{ 1153	,1	,1	, &internal1_m1915_q0},	//(internal1_m1915_q0) q0 - внутренний параметр
	{ 1154	,1	,1	, &internal1_m1885_q0},	//(internal1_m1885_q0) q0 - внутренний параметр
	{ 1155	,1	,1	, &internal1_m1875_q0},	//(internal1_m1875_q0) q0 - внутренний параметр
	{ 1156	,1	,1	, &internal1_m1455_q0},	//(internal1_m1455_q0) q0 - внутренний параметр
	{ 1157	,1	,1	, &internal1_m1442_x0},	//(internal1_m1442_x0) был приход сигнала x1
	{ 1158	,8	,1	, &internal1_m1442_y0},	//(internal1_m1442_y0) интервал между сигналами х1 и х2
	{ 1159	,1	,1	, &internal1_m1438_q0},	//(internal1_m1438_q0) q0 - внутренний параметр
	{ 1160	,1	,1	, &internal1_m1428_q0},	//(internal1_m1428_q0) q0 - внутренний параметр
	{ 1161	,1	,1	, &internal1_m1487_q0},	//(internal1_m1487_q0) q0 - внутренний параметр
	{ 1162	,1	,1	, &internal1_m1507_q0},	//(internal1_m1507_q0) q0 - внутренний параметр
	{ 1163	,1	,1	, &internal1_m1473_q0},	//(internal1_m1473_q0) q0 - внутренний параметр
	{ 1164	,1	,1	, &internal1_m1488_x0},	//(internal1_m1488_x0) был приход сигнала x1
	{ 1165	,8	,1	, &internal1_m1488_y0},	//(internal1_m1488_y0) интервал между сигналами х1 и х2
	{ 1166	,5	,1	, &internal1_m1413_x0},	//(internal1_m1413_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1167	,1	,1	, &internal1_m1493_q0},	//(internal1_m1493_q0) q0 - внутренний параметр
	{ 1168	,1	,1	, &internal1_m26_q0},	//(internal1_m26_q0) q0 - внутренний параметр
	{ 1169	,1	,1	, &internal1_m1508_q0},	//(internal1_m1508_q0) q0 - внутренний параметр
	{ 1170	,1	,1	, &internal1_m632_q0},	//(internal1_m632_q0) q0 - внутренний параметр
	{ 1171	,1	,1	, &internal1_m617_q0},	//(internal1_m617_q0) q0 - внутренний параметр
	{ 1172	,1	,1	, &internal1_m643_q0},	//(internal1_m643_q0) q0 - внутренний параметр
	{ 1173	,1	,1	, &internal1_m628_q0},	//(internal1_m628_q0) q0 - внутренний параметр
	{ 1174	,1	,1	, &internal1_m612_q0},	//(internal1_m612_q0) q0 - внутренний параметр
	{ 1175	,1	,1	, &internal1_m610_q0},	//(internal1_m610_q0) q0 - внутренний параметр
	{ 1176	,1	,1	, &internal1_m598_q0},	//(internal1_m598_q0) q0 - внутренний параметр
	{ 1177	,5	,1	, &internal1_m1405_q0},	//(internal1_m1405_q0) q0 - внутренний параметр
	{ 1178	,1	,1	, &internal1_m608_q0},	//(internal1_m608_q0) q0 - внутренний параметр
	{ 1179	,1	,1	, &internal1_m106_q0},	//(internal1_m106_q0) q0 - внутренний параметр
	{ 1180	,1	,1	, &internal1_m1640_q0},	//(internal1_m1640_q0) q0 - внутренний параметр
	{ 1181	,1	,1	, &internal1_m1639_q0},	//(internal1_m1639_q0) q0 - внутренний параметр
	{ 1182	,1	,1	, &internal1_m1638_q0},	//(internal1_m1638_q0) q0 - внутренний параметр
	{ 1183	,1	,1	, &internal1_m1637_q0},	//(internal1_m1637_q0) q0 - внутренний параметр
	{ 1184	,1	,1	, &internal1_m1668_q0},	//(internal1_m1668_q0) q0 - внутренний параметр
	{ 1185	,1	,1	, &internal1_m1667_q0},	//(internal1_m1667_q0) q0 - внутренний параметр
	{ 1186	,1	,1	, &internal1_m1666_q0},	//(internal1_m1666_q0) q0 - внутренний параметр
	{ 1187	,1	,1	, &internal1_m1665_q0},	//(internal1_m1665_q0) q0 - внутренний параметр
	{ 1188	,8	,1	, &internal1_m1661_tx},	//(internal1_m1661_tx) tx - время накопленное сек
	{ 1189	,18	,1	, &internal1_m1661_y0},	//(internal1_m1661_y0) y0
	{ 1190	,8	,1	, &internal1_m1654_tx},	//(internal1_m1654_tx) tx - время накопленное сек
	{ 1191	,18	,1	, &internal1_m1654_y0},	//(internal1_m1654_y0) y0
	{ 1192	,1	,1	, &internal1_m1946_q0},	//(internal1_m1946_q0) q0 - внутренний параметр
	{ 1193	,1	,1	, &internal1_m1726_q0},	//(internal1_m1726_q0) q0 - внутренний параметр
	{ 1194	,1	,1	, &internal1_m1725_q0},	//(internal1_m1725_q0) q0 - внутренний параметр
	{ 1195	,1	,1	, &internal1_m1723_q0},	//(internal1_m1723_q0) q0 - внутренний параметр
	{ 1196	,1	,1	, &internal1_m1722_q0},	//(internal1_m1722_q0) q0 - внутренний параметр
	{ 1197	,1	,1	, &internal1_m1720_q0},	//(internal1_m1720_q0) q0 - внутренний параметр
	{ 1198	,8	,1	, &internal1_m1710_tx},	//(internal1_m1710_tx) tx - время накопленное сек
	{ 1199	,18	,1	, &internal1_m1710_y0},	//(internal1_m1710_y0) y0
	{ 1200	,8	,1	, &internal1_m1709_tx},	//(internal1_m1709_tx) tx - время накопленное сек
	{ 1201	,18	,1	, &internal1_m1709_y0},	//(internal1_m1709_y0) y0
	{ 1202	,1	,1	, &internal1_m1697_q0},	//(internal1_m1697_q0) q0 - внутренний параметр
	{ 1203	,1	,1	, &internal1_m1707_q0},	//(internal1_m1707_q0) q0 - внутренний параметр
	{ 1204	,1	,1	, &internal1_m1706_q0},	//(internal1_m1706_q0) q0 - внутренний параметр
	{ 1205	,1	,1	, &internal1_m1704_q0},	//(internal1_m1704_q0) q0 - внутренний параметр
	{ 1206	,1	,1	, &internal1_m1698_q0},	//(internal1_m1698_q0) q0 - внутренний параметр
	{ 1207	,1	,1	, &internal1_m1688_q0},	//(internal1_m1688_q0) q0 - внутренний параметр
	{ 1208	,1	,1	, &internal1_m1687_q0},	//(internal1_m1687_q0) q0 - внутренний параметр
	{ 1209	,1	,1	, &internal1_m1683_q0},	//(internal1_m1683_q0) q0 - внутренний параметр
	{ 1210	,1	,1	, &internal1_m1685_q0},	//(internal1_m1685_q0) q0 - внутренний параметр
	{ 1211	,1	,1	, &internal1_m1682_q0},	//(internal1_m1682_q0) q0 - внутренний параметр
	{ 1212	,1	,1	, &internal1_m1681_q0},	//(internal1_m1681_q0) q0 - внутренний параметр
	{ 1213	,1	,1	, &internal1_m1677_q0},	//(internal1_m1677_q0) q0 - внутренний параметр
	{ 1214	,1	,1	, &internal1_m1679_q0},	//(internal1_m1679_q0) q0 - внутренний параметр
	{ 1215	,1	,1	, &internal1_m19_q0},	//(internal1_m19_q0) q0 - внутренний параметр
	{ 1216	,1	,1	, &internal1_m1662_q0},	//(internal1_m1662_q0) q0 - внутренний параметр
	{ 1217	,1	,1	, &internal1_m1660_q0},	//(internal1_m1660_q0) q0 - внутренний параметр
	{ 1218	,1	,1	, &internal1_m1656_q0},	//(internal1_m1656_q0) q0 - внутренний параметр
	{ 1219	,1	,1	, &internal1_m1658_q0},	//(internal1_m1658_q0) q0 - внутренний параметр
	{ 1220	,1	,1	, &internal1_m1655_q0},	//(internal1_m1655_q0) q0 - внутренний параметр
	{ 1221	,1	,1	, &internal1_m1653_q0},	//(internal1_m1653_q0) q0 - внутренний параметр
	{ 1222	,1	,1	, &internal1_m2046_q0},	//(internal1_m2046_q0) q0 - внутренний параметр
	{ 1223	,1	,1	, &internal1_m2042_q0},	//(internal1_m2042_q0) q0 - внутренний параметр
	{ 1224	,1	,1	, &internal1_m2029_q0},	//(internal1_m2029_q0) q0 - внутренний параметр
	{ 1225	,1	,1	, &internal1_m2021_q0},	//(internal1_m2021_q0) q0 - внутренний параметр
	{ 1226	,1	,1	, &internal1_m1956_q0},	//(internal1_m1956_q0) q0 - внутренний параметр
	{ 1227	,1	,1	, &internal1_m1649_q0},	//(internal1_m1649_q0) q0 - внутренний параметр
	{ 1228	,1	,1	, &internal1_m1651_q0},	//(internal1_m1651_q0) q0 - внутренний параметр
	{ 1229	,1	,1	, &internal1_m1636_q0},	//(internal1_m1636_q0) q0 - внутренний параметр
	{ 1230	,1	,1	, &internal1_m1634_q0},	//(internal1_m1634_q0) q0 - внутренний параметр
	{ 1231	,1	,1	, &internal1_m1633_q0},	//(internal1_m1633_q0) q0 - внутренний параметр
	{ 1232	,1	,1	, &internal1_m1631_q0},	//(internal1_m1631_q0) q0 - внутренний параметр
	{ 1233	,1	,1	, &internal1_m1630_q0},	//(internal1_m1630_q0) q0 - внутренний параметр
	{ 1234	,1	,1	, &internal1_m1628_q0},	//(internal1_m1628_q0) q0 - внутренний параметр
	{ 1235	,1	,1	, &internal1_m1627_q0},	//(internal1_m1627_q0) q0 - внутренний параметр
	{ 1236	,1	,1	, &internal1_m1625_q0},	//(internal1_m1625_q0) q0 - внутренний параметр
	{ 1237	,18	,1	, &internal1_m2068_DvUp0},	//(internal1_m2068_DvUp0) - есть команда на движение вперёд
	{ 1238	,18	,1	, &internal1_m2068_DvDw0},	//(internal1_m2068_DvDw0) - есть команда на движение назад
	{ 1239	,18	,1	, &internal1_m2068_FDvUp0},	//(internal1_m2068_FDvUp0) - есть команда на движение вперёд
	{ 1240	,18	,1	, &internal1_m2068_FDvDw0},	//(internal1_m2068_FDvDw0) - есть команда на движение назад
	{ 1241	,18	,1	, &internal1_m2068_BlDv0},	//(internal1_m2068_BlDv0) - была блокировка
	{ 1242	,18	,1	, &internal1_m2068_Pkv0},	//(internal1_m2068_Pkv0) Pkv - передний конечный выключатель
	{ 1243	,18	,1	, &internal1_m2068_Pkav0},	//(internal1_m2068_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1244	,18	,1	, &internal1_m2068_Zkv0},	//(internal1_m2068_Zkv0) Zkv - задний конечный выключатель
	{ 1245	,18	,1	, &internal1_m2068_Zkav0},	//(internal1_m2068_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1246	,8	,1	, &internal1_m2068_txNm},	//(internal1_m2068_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1247	,8	,1	, &internal1_m2068_txSm},	//(internal1_m2068_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1248	,8	,1	, &internal1_m2068_txHr},	//(internal1_m2068_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1249	,8	,1	, &internal1_m2068_txLd},	//(internal1_m2068_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1250	,18	,1	, &internal1_m2068_fef},	//(internal1_m2068_fef) fef
	{ 1251	,18	,1	, &internal1_m2062_DvUp0},	//(internal1_m2062_DvUp0) - есть команда на движение вперёд
	{ 1252	,18	,1	, &internal1_m2062_DvDw0},	//(internal1_m2062_DvDw0) - есть команда на движение назад
	{ 1253	,18	,1	, &internal1_m2062_FDvUp0},	//(internal1_m2062_FDvUp0) - есть команда на движение вперёд
	{ 1254	,18	,1	, &internal1_m2062_FDvDw0},	//(internal1_m2062_FDvDw0) - есть команда на движение назад
	{ 1255	,18	,1	, &internal1_m2062_BlDv0},	//(internal1_m2062_BlDv0) - была блокировка
	{ 1256	,18	,1	, &internal1_m2062_Pkv0},	//(internal1_m2062_Pkv0) Pkv - передний конечный выключатель
	{ 1257	,18	,1	, &internal1_m2062_Pkav0},	//(internal1_m2062_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1258	,18	,1	, &internal1_m2062_Zkv0},	//(internal1_m2062_Zkv0) Zkv - задний конечный выключатель
	{ 1259	,18	,1	, &internal1_m2062_Zkav0},	//(internal1_m2062_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1260	,8	,1	, &internal1_m2062_txNm},	//(internal1_m2062_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1261	,8	,1	, &internal1_m2062_txSm},	//(internal1_m2062_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1262	,8	,1	, &internal1_m2062_txHr},	//(internal1_m2062_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1263	,8	,1	, &internal1_m2062_txLd},	//(internal1_m2062_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1264	,18	,1	, &internal1_m2062_fef},	//(internal1_m2062_fef) fef
	{ 1265	,18	,1	, &internal1_m360_DvUp0},	//(internal1_m360_DvUp0) - есть команда на движение вперёд
	{ 1266	,18	,1	, &internal1_m360_DvDw0},	//(internal1_m360_DvDw0) - есть команда на движение назад
	{ 1267	,18	,1	, &internal1_m360_FDvUp0},	//(internal1_m360_FDvUp0) - есть команда на движение вперёд
	{ 1268	,18	,1	, &internal1_m360_FDvDw0},	//(internal1_m360_FDvDw0) - есть команда на движение назад
	{ 1269	,18	,1	, &internal1_m360_BlDv0},	//(internal1_m360_BlDv0) - была блокировка
	{ 1270	,18	,1	, &internal1_m360_Pkv0},	//(internal1_m360_Pkv0) Pkv - передний конечный выключатель
	{ 1271	,18	,1	, &internal1_m360_Pkav0},	//(internal1_m360_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1272	,18	,1	, &internal1_m360_Zkv0},	//(internal1_m360_Zkv0) Zkv - задний конечный выключатель
	{ 1273	,18	,1	, &internal1_m360_Zkav0},	//(internal1_m360_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1274	,8	,1	, &internal1_m360_txNm},	//(internal1_m360_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1275	,8	,1	, &internal1_m360_txSm},	//(internal1_m360_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1276	,8	,1	, &internal1_m360_txHr},	//(internal1_m360_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1277	,8	,1	, &internal1_m360_txLd},	//(internal1_m360_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1278	,18	,1	, &internal1_m360_fef},	//(internal1_m360_fef) fef
	{ 1279	,1	,1	, &internal1_m1478_q0},	//(internal1_m1478_q0) q0 - внутренний параметр
	{ 1280	,1	,1	, &internal1_m1482_x0},	//(internal1_m1482_x0) был приход сигнала x1
	{ 1281	,8	,1	, &internal1_m1482_y0},	//(internal1_m1482_y0) интервал между сигналами х1 и х2
	{ 1282	,1	,1	, &internal1_m1897_x0},	//(internal1_m1897_x0) был приход сигнала x1
	{ 1283	,8	,1	, &internal1_m1897_y0},	//(internal1_m1897_y0) интервал между сигналами х1 и х2
	{ 1284	,1	,1	, &internal1_m1858_x0},	//(internal1_m1858_x0) был приход сигнала x1
	{ 1285	,8	,1	, &internal1_m1858_y0},	//(internal1_m1858_y0) интервал между сигналами х1 и х2
	{ 1286	,1	,1	, &internal1_m271_q0},	//(internal1_m271_q0) q0 - внутренний параметр
	{ 1287	,1	,1	, &internal1_m999_q0},	//(internal1_m999_q0) q0 - внутренний параметр
	{ 1288	,1	,1	, &internal1_m620_q0},	//(internal1_m620_q0) q0 - внутренний параметр
	{ 1289	,8	,1	, &internal1_m1297_X0},	//(internal1_m1297_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1290	,8	,1	, &internal1_m1297_t0},	//(internal1_m1297_t0) время нахождения в зоне возврата
	{ 1291	,18	,1	, &internal1_m1297_BLDv0},	//(internal1_m1297_BLDv0) BlDv - Блокировка движения
	{ 1292	,8	,1	, &internal1_m1316_tx},	//(internal1_m1316_tx) tx - время накопленное сек
	{ 1293	,18	,1	, &internal1_m1316_y0},	//(internal1_m1316_y0) y0
	{ 1294	,8	,1	, &internal1_m1319_tx},	//(internal1_m1319_tx) tx - время накопленное сек
	{ 1295	,18	,1	, &internal1_m1319_y0},	//(internal1_m1319_y0) y0
	{ 1296	,3	,1	, &internal1_m1325_xptr},	//(internal1_m1325_xptr) указатель текущей позиции в массиве координат
	{ 1297	,8	,60	, &internal1_m1325_x0},	//(internal1_m1325_x0) x0 - массив мгновенных значений координат
	{ 1298	,8	,60	, &internal1_m1325_tim0},	//(internal1_m1325_tim0) tim0 - массив значений времени цикла
	{ 1299	,3	,1	, &internal1_m1325_mcount},	//(internal1_m1325_mcount) count - счетчик заполнения массива значений координат
	{ 1300	,8	,1	, &internal1_m1325_sumtim},	//(internal1_m1325_sumtim) sumtim - время в пути
	{ 1301	,8	,1	, &internal1_m1325_sumtakt},	//(internal1_m1325_sumtakt) sumtim - время в пути
	{ 1302	,8	,1	, &internal1_m1325_StSpeed},	//(internal1_m1325_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1303	,8	,1	, &internal1_m1325_Vz0},	//(internal1_m1325_Vz0) Vz0 - предыдущая заданная скорость
	{ 1304	,3	,1	, &internal1_m1325_flRazg},	//(internal1_m1325_flRazg) признак разгона/торможения
	{ 1305	,8	,1	, &internal1_m1325_DelSp},	//(internal1_m1325_DelSp) DelSp - время переключения скоростей
	{ 1306	,8	,1	, &internal1_m1325_z0},	//(internal1_m1325_z0) z0 - точка прекращения движения
	{ 1307	,8	,1	, &internal1_m1325_txZS},	//(internal1_m1325_txZS) txZS
	{ 1308	,8	,1	, &internal1_m1325_tx},	//(internal1_m1325_tx) tx
	{ 1309	,8	,1	, &internal1_m1325_txd},	//(internal1_m1325_txd) txd
	{ 1310	,8	,1	, &internal1_m1325_txMBl},	//(internal1_m1325_txMBl) tx
	{ 1311	,8	,1	, &internal1_m1325_txBl},	//(internal1_m1325_txBl) tx
	{ 1312	,8	,1	, &internal1_m1325_Speed0},	//(internal1_m1325_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1313	,8	,1	, &internal1_m1325_xz0},	//(internal1_m1325_xz0) xz0 - новое задание мм
	{ 1314	,8	,1	, &internal1_m1325_tz0},	//(internal1_m1325_tz0) tz0 - время защиты от нового задания сек
	{ 1315	,1	,1	, &internal1_m1325_Shift0},	//(internal1_m1325_Shift0) Shift0 - признак самохода
	{ 1316	,1	,1	, &internal1_m1325_ShCntlSp0},	//(internal1_m1325_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1317	,1	,1	, &internal1_m1325_ShiftControl},	//(internal1_m1325_ShiftControl) ShiftControl - признак самохода
	{ 1318	,1	,1	, &internal1_m618_q0},	//(internal1_m618_q0) q0 - внутренний параметр
	{ 1319	,8	,1	, &internal1_m892_X0},	//(internal1_m892_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1320	,8	,1	, &internal1_m892_t0},	//(internal1_m892_t0) время нахождения в зоне возврата
	{ 1321	,18	,1	, &internal1_m892_BLDv0},	//(internal1_m892_BLDv0) BlDv - Блокировка движения
	{ 1322	,8	,1	, &internal1_m916_tx},	//(internal1_m916_tx) tx - время накопленное сек
	{ 1323	,18	,1	, &internal1_m916_y0},	//(internal1_m916_y0) y0
	{ 1324	,8	,1	, &internal1_m917_tx},	//(internal1_m917_tx) tx - время накопленное сек
	{ 1325	,18	,1	, &internal1_m917_y0},	//(internal1_m917_y0) y0
	{ 1326	,3	,1	, &internal1_m925_xptr},	//(internal1_m925_xptr) указатель текущей позиции в массиве координат
	{ 1327	,8	,60	, &internal1_m925_x0},	//(internal1_m925_x0) x0 - массив мгновенных значений координат
	{ 1328	,8	,60	, &internal1_m925_tim0},	//(internal1_m925_tim0) tim0 - массив значений времени цикла
	{ 1329	,3	,1	, &internal1_m925_mcount},	//(internal1_m925_mcount) count - счетчик заполнения массива значений координат
	{ 1330	,8	,1	, &internal1_m925_sumtim},	//(internal1_m925_sumtim) sumtim - время в пути
	{ 1331	,8	,1	, &internal1_m925_sumtakt},	//(internal1_m925_sumtakt) sumtim - время в пути
	{ 1332	,8	,1	, &internal1_m925_StSpeed},	//(internal1_m925_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1333	,8	,1	, &internal1_m925_Vz0},	//(internal1_m925_Vz0) Vz0 - предыдущая заданная скорость
	{ 1334	,3	,1	, &internal1_m925_flRazg},	//(internal1_m925_flRazg) признак разгона/торможения
	{ 1335	,8	,1	, &internal1_m925_DelSp},	//(internal1_m925_DelSp) DelSp - время переключения скоростей
	{ 1336	,8	,1	, &internal1_m925_z0},	//(internal1_m925_z0) z0 - точка прекращения движения
	{ 1337	,8	,1	, &internal1_m925_txZS},	//(internal1_m925_txZS) txZS
	{ 1338	,8	,1	, &internal1_m925_tx},	//(internal1_m925_tx) tx
	{ 1339	,8	,1	, &internal1_m925_txd},	//(internal1_m925_txd) txd
	{ 1340	,8	,1	, &internal1_m925_txMBl},	//(internal1_m925_txMBl) tx
	{ 1341	,8	,1	, &internal1_m925_txBl},	//(internal1_m925_txBl) tx
	{ 1342	,8	,1	, &internal1_m925_Speed0},	//(internal1_m925_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1343	,8	,1	, &internal1_m925_xz0},	//(internal1_m925_xz0) xz0 - новое задание мм
	{ 1344	,8	,1	, &internal1_m925_tz0},	//(internal1_m925_tz0) tz0 - время защиты от нового задания сек
	{ 1345	,1	,1	, &internal1_m925_Shift0},	//(internal1_m925_Shift0) Shift0 - признак самохода
	{ 1346	,1	,1	, &internal1_m925_ShCntlSp0},	//(internal1_m925_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1347	,1	,1	, &internal1_m925_ShiftControl},	//(internal1_m925_ShiftControl) ShiftControl - признак самохода
	{ 1348	,8	,1	, &internal1_m491_X0},	//(internal1_m491_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1349	,8	,1	, &internal1_m491_t0},	//(internal1_m491_t0) время нахождения в зоне возврата
	{ 1350	,18	,1	, &internal1_m491_BLDv0},	//(internal1_m491_BLDv0) BlDv - Блокировка движения
	{ 1351	,8	,1	, &internal1_m511_tx},	//(internal1_m511_tx) tx - время накопленное сек
	{ 1352	,18	,1	, &internal1_m511_y0},	//(internal1_m511_y0) y0
	{ 1353	,8	,1	, &internal1_m514_tx},	//(internal1_m514_tx) tx - время накопленное сек
	{ 1354	,18	,1	, &internal1_m514_y0},	//(internal1_m514_y0) y0
	{ 1355	,3	,1	, &internal1_m518_xptr},	//(internal1_m518_xptr) указатель текущей позиции в массиве координат
	{ 1356	,8	,150	, &internal1_m518_x0},	//(internal1_m518_x0) x0 - массив мгновенных значений координат
	{ 1357	,8	,150	, &internal1_m518_tim0},	//(internal1_m518_tim0) tim0 - массив значений времени цикла
	{ 1358	,3	,1	, &internal1_m518_mcount},	//(internal1_m518_mcount) count - счетчик заполнения массива значений координат
	{ 1359	,8	,1	, &internal1_m518_sumtim},	//(internal1_m518_sumtim) sumtim - время в пути
	{ 1360	,8	,1	, &internal1_m518_sumtakt},	//(internal1_m518_sumtakt) sumtim - время в пути
	{ 1361	,8	,1	, &internal1_m518_StSpeed},	//(internal1_m518_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1362	,8	,1	, &internal1_m518_Vz0},	//(internal1_m518_Vz0) Vz0 - предыдущая заданная скорость
	{ 1363	,3	,1	, &internal1_m518_flRazg},	//(internal1_m518_flRazg) признак разгона/торможения
	{ 1364	,8	,1	, &internal1_m518_DelSp},	//(internal1_m518_DelSp) DelSp - время переключения скоростей
	{ 1365	,8	,1	, &internal1_m518_z0},	//(internal1_m518_z0) z0 - точка прекращения движения
	{ 1366	,8	,1	, &internal1_m518_txZS},	//(internal1_m518_txZS) txZS
	{ 1367	,8	,1	, &internal1_m518_tx},	//(internal1_m518_tx) tx
	{ 1368	,8	,1	, &internal1_m518_txd},	//(internal1_m518_txd) txd
	{ 1369	,8	,1	, &internal1_m518_txMBl},	//(internal1_m518_txMBl) tx
	{ 1370	,8	,1	, &internal1_m518_txBl},	//(internal1_m518_txBl) tx
	{ 1371	,8	,1	, &internal1_m518_Speed0},	//(internal1_m518_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1372	,8	,1	, &internal1_m518_xz0},	//(internal1_m518_xz0) xz0 - новое задание мм
	{ 1373	,8	,1	, &internal1_m518_tz0},	//(internal1_m518_tz0) tz0 - время защиты от нового задания сек
	{ 1374	,1	,1	, &internal1_m518_Shift0},	//(internal1_m518_Shift0) Shift0 - признак самохода
	{ 1375	,1	,1	, &internal1_m518_ShCntlSp0},	//(internal1_m518_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1376	,1	,1	, &internal1_m518_ShiftControl},	//(internal1_m518_ShiftControl) ShiftControl - признак самохода
	{ 1377	,1	,1	, &internal1_m615_q0},	//(internal1_m615_q0) q0 - внутренний параметр
	{ 1378	,8	,1	, &internal1_m163_X0},	//(internal1_m163_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1379	,8	,1	, &internal1_m163_t0},	//(internal1_m163_t0) время нахождения в зоне возврата
	{ 1380	,18	,1	, &internal1_m163_BLDv0},	//(internal1_m163_BLDv0) BlDv - Блокировка движения
	{ 1381	,3	,1	, &internal1_m192_xptr},	//(internal1_m192_xptr) указатель текущей позиции в массиве координат
	{ 1382	,8	,150	, &internal1_m192_x0},	//(internal1_m192_x0) x0 - массив мгновенных значений координат
	{ 1383	,8	,150	, &internal1_m192_tim0},	//(internal1_m192_tim0) tim0 - массив значений времени цикла
	{ 1384	,3	,1	, &internal1_m192_mcount},	//(internal1_m192_mcount) count - счетчик заполнения массива значений координат
	{ 1385	,8	,1	, &internal1_m192_sumtim},	//(internal1_m192_sumtim) sumtim - время в пути
	{ 1386	,8	,1	, &internal1_m192_sumtakt},	//(internal1_m192_sumtakt) sumtim - время в пути
	{ 1387	,8	,1	, &internal1_m192_StSpeed},	//(internal1_m192_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1388	,8	,1	, &internal1_m192_Vz0},	//(internal1_m192_Vz0) Vz0 - предыдущая заданная скорость
	{ 1389	,3	,1	, &internal1_m192_flRazg},	//(internal1_m192_flRazg) признак разгона/торможения
	{ 1390	,8	,1	, &internal1_m192_DelSp},	//(internal1_m192_DelSp) DelSp - время переключения скоростей
	{ 1391	,8	,1	, &internal1_m192_z0},	//(internal1_m192_z0) z0 - точка прекращения движения
	{ 1392	,8	,1	, &internal1_m192_txZS},	//(internal1_m192_txZS) txZS
	{ 1393	,8	,1	, &internal1_m192_tx},	//(internal1_m192_tx) tx
	{ 1394	,8	,1	, &internal1_m192_txd},	//(internal1_m192_txd) txd
	{ 1395	,8	,1	, &internal1_m192_txMBl},	//(internal1_m192_txMBl) tx
	{ 1396	,8	,1	, &internal1_m192_txBl},	//(internal1_m192_txBl) tx
	{ 1397	,8	,1	, &internal1_m192_Speed0},	//(internal1_m192_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1398	,8	,1	, &internal1_m192_xz0},	//(internal1_m192_xz0) xz0 - новое задание мм
	{ 1399	,8	,1	, &internal1_m192_tz0},	//(internal1_m192_tz0) tz0 - время защиты от нового задания сек
	{ 1400	,1	,1	, &internal1_m192_Shift0},	//(internal1_m192_Shift0) Shift0 - признак самохода
	{ 1401	,1	,1	, &internal1_m192_ShCntlSp0},	//(internal1_m192_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1402	,1	,1	, &internal1_m192_ShiftControl},	//(internal1_m192_ShiftControl) ShiftControl - признак самохода
	{ 1403	,1	,1	, &internal1_m641_q0},	//(internal1_m641_q0) q0 - внутренний параметр
	{ 1404	,18	,1	, &internal1_m462_DvUp0},	//(internal1_m462_DvUp0) - есть команда на движение вперёд
	{ 1405	,18	,1	, &internal1_m462_DvDw0},	//(internal1_m462_DvDw0) - есть команда на движение назад
	{ 1406	,18	,1	, &internal1_m462_FDvUp0},	//(internal1_m462_FDvUp0) - есть команда на движение вперёд
	{ 1407	,18	,1	, &internal1_m462_FDvDw0},	//(internal1_m462_FDvDw0) - есть команда на движение назад
	{ 1408	,18	,1	, &internal1_m462_BlDv0},	//(internal1_m462_BlDv0) - была блокировка
	{ 1409	,18	,1	, &internal1_m462_Pkv0},	//(internal1_m462_Pkv0) Pkv - передний конечный выключатель
	{ 1410	,18	,1	, &internal1_m462_Pkav0},	//(internal1_m462_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1411	,18	,1	, &internal1_m462_Zkv0},	//(internal1_m462_Zkv0) Zkv - задний конечный выключатель
	{ 1412	,18	,1	, &internal1_m462_Zkav0},	//(internal1_m462_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1413	,8	,1	, &internal1_m462_txNm},	//(internal1_m462_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1414	,8	,1	, &internal1_m462_txSm},	//(internal1_m462_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1415	,8	,1	, &internal1_m462_txHr},	//(internal1_m462_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1416	,8	,1	, &internal1_m462_txLd},	//(internal1_m462_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1417	,18	,1	, &internal1_m462_fef},	//(internal1_m462_fef) fef
	{ 1418	,18	,1	, &internal1_m456_DvUp0},	//(internal1_m456_DvUp0) - есть команда на движение вперёд
	{ 1419	,18	,1	, &internal1_m456_DvDw0},	//(internal1_m456_DvDw0) - есть команда на движение назад
	{ 1420	,18	,1	, &internal1_m456_FDvUp0},	//(internal1_m456_FDvUp0) - есть команда на движение вперёд
	{ 1421	,18	,1	, &internal1_m456_FDvDw0},	//(internal1_m456_FDvDw0) - есть команда на движение назад
	{ 1422	,18	,1	, &internal1_m456_BlDv0},	//(internal1_m456_BlDv0) - была блокировка
	{ 1423	,18	,1	, &internal1_m456_Pkv0},	//(internal1_m456_Pkv0) Pkv - передний конечный выключатель
	{ 1424	,18	,1	, &internal1_m456_Pkav0},	//(internal1_m456_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1425	,18	,1	, &internal1_m456_Zkv0},	//(internal1_m456_Zkv0) Zkv - задний конечный выключатель
	{ 1426	,18	,1	, &internal1_m456_Zkav0},	//(internal1_m456_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1427	,8	,1	, &internal1_m456_txNm},	//(internal1_m456_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1428	,8	,1	, &internal1_m456_txSm},	//(internal1_m456_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1429	,8	,1	, &internal1_m456_txHr},	//(internal1_m456_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1430	,8	,1	, &internal1_m456_txLd},	//(internal1_m456_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1431	,18	,1	, &internal1_m456_fef},	//(internal1_m456_fef) fef
	{ 1432	,8	,1	, &internal1_m811_X0},	//(internal1_m811_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1433	,8	,1	, &internal1_m811_t0},	//(internal1_m811_t0) время нахождения в зоне возврата
	{ 1434	,18	,1	, &internal1_m811_BLDv0},	//(internal1_m811_BLDv0) BlDv - Блокировка движения
	{ 1435	,3	,1	, &internal1_m831_xptr},	//(internal1_m831_xptr) указатель текущей позиции в массиве координат
	{ 1436	,8	,80	, &internal1_m831_x0},	//(internal1_m831_x0) x0 - массив мгновенных значений координат
	{ 1437	,8	,80	, &internal1_m831_tim0},	//(internal1_m831_tim0) tim0 - массив значений времени цикла
	{ 1438	,3	,1	, &internal1_m831_mcount},	//(internal1_m831_mcount) count - счетчик заполнения массива значений координат
	{ 1439	,8	,1	, &internal1_m831_sumtim},	//(internal1_m831_sumtim) sumtim - время в пути
	{ 1440	,8	,1	, &internal1_m831_sumtakt},	//(internal1_m831_sumtakt) sumtim - время в пути
	{ 1441	,8	,1	, &internal1_m831_StSpeed},	//(internal1_m831_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1442	,8	,1	, &internal1_m831_Vz0},	//(internal1_m831_Vz0) Vz0 - предыдущая заданная скорость
	{ 1443	,3	,1	, &internal1_m831_flRazg},	//(internal1_m831_flRazg) признак разгона/торможения
	{ 1444	,8	,1	, &internal1_m831_DelSp},	//(internal1_m831_DelSp) DelSp - время переключения скоростей
	{ 1445	,8	,1	, &internal1_m831_z0},	//(internal1_m831_z0) z0 - точка прекращения движения
	{ 1446	,8	,1	, &internal1_m831_txZS},	//(internal1_m831_txZS) txZS
	{ 1447	,8	,1	, &internal1_m831_tx},	//(internal1_m831_tx) tx
	{ 1448	,8	,1	, &internal1_m831_txd},	//(internal1_m831_txd) txd
	{ 1449	,8	,1	, &internal1_m831_txMBl},	//(internal1_m831_txMBl) tx
	{ 1450	,8	,1	, &internal1_m831_txBl},	//(internal1_m831_txBl) tx
	{ 1451	,8	,1	, &internal1_m831_Speed0},	//(internal1_m831_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1452	,8	,1	, &internal1_m831_xz0},	//(internal1_m831_xz0) xz0 - новое задание мм
	{ 1453	,8	,1	, &internal1_m831_tz0},	//(internal1_m831_tz0) tz0 - время защиты от нового задания сек
	{ 1454	,1	,1	, &internal1_m831_Shift0},	//(internal1_m831_Shift0) Shift0 - признак самохода
	{ 1455	,1	,1	, &internal1_m831_ShCntlSp0},	//(internal1_m831_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1456	,1	,1	, &internal1_m831_ShiftControl},	//(internal1_m831_ShiftControl) ShiftControl - признак самохода
	{ 1457	,8	,1	, &internal1_m1584_X0},	//(internal1_m1584_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1458	,8	,1	, &internal1_m1584_t0},	//(internal1_m1584_t0) время нахождения в зоне возврата
	{ 1459	,18	,1	, &internal1_m1584_BLDv0},	//(internal1_m1584_BLDv0) BlDv - Блокировка движения
	{ 1460	,8	,1	, &internal1_m1116_X0},	//(internal1_m1116_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1461	,8	,1	, &internal1_m1116_t0},	//(internal1_m1116_t0) время нахождения в зоне возврата
	{ 1462	,18	,1	, &internal1_m1116_BLDv0},	//(internal1_m1116_BLDv0) BlDv - Блокировка движения
	{ 1463	,1	,1	, &internal1_m613_q0},	//(internal1_m613_q0) q0 - внутренний параметр
	{ 1464	,8	,1	, &internal1_m1199_X0},	//(internal1_m1199_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1465	,8	,1	, &internal1_m1199_t0},	//(internal1_m1199_t0) время нахождения в зоне возврата
	{ 1466	,18	,1	, &internal1_m1199_BLDv0},	//(internal1_m1199_BLDv0) BlDv - Блокировка движения
	{ 1467	,8	,1	, &internal1_m1219_tx},	//(internal1_m1219_tx) tx - время накопленное сек
	{ 1468	,18	,1	, &internal1_m1219_y0},	//(internal1_m1219_y0) y0
	{ 1469	,8	,1	, &internal1_m1227_tx},	//(internal1_m1227_tx) tx - время накопленное сек
	{ 1470	,18	,1	, &internal1_m1227_y0},	//(internal1_m1227_y0) y0
	{ 1471	,3	,1	, &internal1_m1232_xptr},	//(internal1_m1232_xptr) указатель текущей позиции в массиве координат
	{ 1472	,8	,80	, &internal1_m1232_x0},	//(internal1_m1232_x0) x0 - массив мгновенных значений координат
	{ 1473	,8	,80	, &internal1_m1232_tim0},	//(internal1_m1232_tim0) tim0 - массив значений времени цикла
	{ 1474	,3	,1	, &internal1_m1232_mcount},	//(internal1_m1232_mcount) count - счетчик заполнения массива значений координат
	{ 1475	,8	,1	, &internal1_m1232_sumtim},	//(internal1_m1232_sumtim) sumtim - время в пути
	{ 1476	,8	,1	, &internal1_m1232_sumtakt},	//(internal1_m1232_sumtakt) sumtim - время в пути
	{ 1477	,8	,1	, &internal1_m1232_StSpeed},	//(internal1_m1232_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1478	,8	,1	, &internal1_m1232_Vz0},	//(internal1_m1232_Vz0) Vz0 - предыдущая заданная скорость
	{ 1479	,3	,1	, &internal1_m1232_flRazg},	//(internal1_m1232_flRazg) признак разгона/торможения
	{ 1480	,8	,1	, &internal1_m1232_DelSp},	//(internal1_m1232_DelSp) DelSp - время переключения скоростей
	{ 1481	,8	,1	, &internal1_m1232_z0},	//(internal1_m1232_z0) z0 - точка прекращения движения
	{ 1482	,8	,1	, &internal1_m1232_txZS},	//(internal1_m1232_txZS) txZS
	{ 1483	,8	,1	, &internal1_m1232_tx},	//(internal1_m1232_tx) tx
	{ 1484	,8	,1	, &internal1_m1232_txd},	//(internal1_m1232_txd) txd
	{ 1485	,8	,1	, &internal1_m1232_txMBl},	//(internal1_m1232_txMBl) tx
	{ 1486	,8	,1	, &internal1_m1232_txBl},	//(internal1_m1232_txBl) tx
	{ 1487	,8	,1	, &internal1_m1232_Speed0},	//(internal1_m1232_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1488	,8	,1	, &internal1_m1232_xz0},	//(internal1_m1232_xz0) xz0 - новое задание мм
	{ 1489	,8	,1	, &internal1_m1232_tz0},	//(internal1_m1232_tz0) tz0 - время защиты от нового задания сек
	{ 1490	,1	,1	, &internal1_m1232_Shift0},	//(internal1_m1232_Shift0) Shift0 - признак самохода
	{ 1491	,1	,1	, &internal1_m1232_ShCntlSp0},	//(internal1_m1232_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1492	,1	,1	, &internal1_m1232_ShiftControl},	//(internal1_m1232_ShiftControl) ShiftControl - признак самохода
	{ 1493	,1	,1	, &internal1_m633_q0},	//(internal1_m633_q0) q0 - внутренний параметр
	{ 1494	,8	,1	, &internal1_m1597_tx},	//(internal1_m1597_tx) tx - время накопленное сек
	{ 1495	,18	,1	, &internal1_m1597_y0},	//(internal1_m1597_y0) y0
	{ 1496	,8	,1	, &internal1_m1601_tx},	//(internal1_m1601_tx) tx - время накопленное сек
	{ 1497	,18	,1	, &internal1_m1601_y0},	//(internal1_m1601_y0) y0
	{ 1498	,18	,1	, &internal1_m1587_DvUp0},	//(internal1_m1587_DvUp0) - есть команда на движение вперёд
	{ 1499	,18	,1	, &internal1_m1587_DvDw0},	//(internal1_m1587_DvDw0) - есть команда на движение назад
	{ 1500	,18	,1	, &internal1_m1587_FDvUp0},	//(internal1_m1587_FDvUp0) - есть команда на движение вперёд
	{ 1501	,18	,1	, &internal1_m1587_FDvDw0},	//(internal1_m1587_FDvDw0) - есть команда на движение назад
	{ 1502	,18	,1	, &internal1_m1587_BlDv0},	//(internal1_m1587_BlDv0) - была блокировка
	{ 1503	,18	,1	, &internal1_m1587_Pkv0},	//(internal1_m1587_Pkv0) Pkv - передний конечный выключатель
	{ 1504	,18	,1	, &internal1_m1587_Pkav0},	//(internal1_m1587_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1505	,18	,1	, &internal1_m1587_Zkv0},	//(internal1_m1587_Zkv0) Zkv - задний конечный выключатель
	{ 1506	,18	,1	, &internal1_m1587_Zkav0},	//(internal1_m1587_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1507	,8	,1	, &internal1_m1587_txNm},	//(internal1_m1587_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1508	,8	,1	, &internal1_m1587_txSm},	//(internal1_m1587_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1509	,8	,1	, &internal1_m1587_txHr},	//(internal1_m1587_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1510	,8	,1	, &internal1_m1587_txLd},	//(internal1_m1587_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1511	,18	,1	, &internal1_m1587_fef},	//(internal1_m1587_fef) fef
	{ 1512	,3	,1	, &internal1_m1604_xptr},	//(internal1_m1604_xptr) указатель текущей позиции в массиве координат
	{ 1513	,8	,20	, &internal1_m1604_x0},	//(internal1_m1604_x0) x0 - массив мгновенных значений координат
	{ 1514	,8	,20	, &internal1_m1604_tim0},	//(internal1_m1604_tim0) tim0 - массив значений времени цикла
	{ 1515	,3	,1	, &internal1_m1604_mcount},	//(internal1_m1604_mcount) count - счетчик заполнения массива значений координат
	{ 1516	,8	,1	, &internal1_m1604_sumtim},	//(internal1_m1604_sumtim) sumtim - время в пути
	{ 1517	,8	,1	, &internal1_m1604_sumtakt},	//(internal1_m1604_sumtakt) sumtim - время в пути
	{ 1518	,8	,1	, &internal1_m1604_StSpeed},	//(internal1_m1604_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1519	,8	,1	, &internal1_m1604_Vz0},	//(internal1_m1604_Vz0) Vz0 - предыдущая заданная скорость
	{ 1520	,3	,1	, &internal1_m1604_flRazg},	//(internal1_m1604_flRazg) признак разгона/торможения
	{ 1521	,8	,1	, &internal1_m1604_DelSp},	//(internal1_m1604_DelSp) DelSp - время переключения скоростей
	{ 1522	,8	,1	, &internal1_m1604_z0},	//(internal1_m1604_z0) z0 - точка прекращения движения
	{ 1523	,8	,1	, &internal1_m1604_txZS},	//(internal1_m1604_txZS) txZS
	{ 1524	,8	,1	, &internal1_m1604_tx},	//(internal1_m1604_tx) tx
	{ 1525	,8	,1	, &internal1_m1604_txd},	//(internal1_m1604_txd) txd
	{ 1526	,8	,1	, &internal1_m1604_txMBl},	//(internal1_m1604_txMBl) tx
	{ 1527	,8	,1	, &internal1_m1604_txBl},	//(internal1_m1604_txBl) tx
	{ 1528	,8	,1	, &internal1_m1604_Speed0},	//(internal1_m1604_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1529	,8	,1	, &internal1_m1604_xz0},	//(internal1_m1604_xz0) xz0 - новое задание мм
	{ 1530	,8	,1	, &internal1_m1604_tz0},	//(internal1_m1604_tz0) tz0 - время защиты от нового задания сек
	{ 1531	,1	,1	, &internal1_m1604_Shift0},	//(internal1_m1604_Shift0) Shift0 - признак самохода
	{ 1532	,1	,1	, &internal1_m1604_ShCntlSp0},	//(internal1_m1604_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1533	,1	,1	, &internal1_m1604_ShiftControl},	//(internal1_m1604_ShiftControl) ShiftControl - признак самохода
	{ 1534	,8	,1	, &internal1_m1130_tx},	//(internal1_m1130_tx) tx - время накопленное сек
	{ 1535	,18	,1	, &internal1_m1130_y0},	//(internal1_m1130_y0) y0
	{ 1536	,8	,1	, &internal1_m1133_tx},	//(internal1_m1133_tx) tx - время накопленное сек
	{ 1537	,18	,1	, &internal1_m1133_y0},	//(internal1_m1133_y0) y0
	{ 1538	,1	,1	, &internal1_m623_q0},	//(internal1_m623_q0) q0 - внутренний параметр
	{ 1539	,1	,1	, &internal1_m588_q0},	//(internal1_m588_q0) q0 - внутренний параметр
	{ 1540	,18	,1	, &internal1_m1120_DvUp0},	//(internal1_m1120_DvUp0) - есть команда на движение вперёд
	{ 1541	,18	,1	, &internal1_m1120_DvDw0},	//(internal1_m1120_DvDw0) - есть команда на движение назад
	{ 1542	,18	,1	, &internal1_m1120_FDvUp0},	//(internal1_m1120_FDvUp0) - есть команда на движение вперёд
	{ 1543	,18	,1	, &internal1_m1120_FDvDw0},	//(internal1_m1120_FDvDw0) - есть команда на движение назад
	{ 1544	,18	,1	, &internal1_m1120_BlDv0},	//(internal1_m1120_BlDv0) - была блокировка
	{ 1545	,18	,1	, &internal1_m1120_Pkv0},	//(internal1_m1120_Pkv0) Pkv - передний конечный выключатель
	{ 1546	,18	,1	, &internal1_m1120_Pkav0},	//(internal1_m1120_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1547	,18	,1	, &internal1_m1120_Zkv0},	//(internal1_m1120_Zkv0) Zkv - задний конечный выключатель
	{ 1548	,18	,1	, &internal1_m1120_Zkav0},	//(internal1_m1120_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1549	,8	,1	, &internal1_m1120_txNm},	//(internal1_m1120_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1550	,8	,1	, &internal1_m1120_txSm},	//(internal1_m1120_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1551	,8	,1	, &internal1_m1120_txHr},	//(internal1_m1120_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1552	,8	,1	, &internal1_m1120_txLd},	//(internal1_m1120_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1553	,18	,1	, &internal1_m1120_fef},	//(internal1_m1120_fef) fef
	{ 1554	,3	,1	, &internal1_m1138_xptr},	//(internal1_m1138_xptr) указатель текущей позиции в массиве координат
	{ 1555	,8	,20	, &internal1_m1138_x0},	//(internal1_m1138_x0) x0 - массив мгновенных значений координат
	{ 1556	,8	,20	, &internal1_m1138_tim0},	//(internal1_m1138_tim0) tim0 - массив значений времени цикла
	{ 1557	,3	,1	, &internal1_m1138_mcount},	//(internal1_m1138_mcount) count - счетчик заполнения массива значений координат
	{ 1558	,8	,1	, &internal1_m1138_sumtim},	//(internal1_m1138_sumtim) sumtim - время в пути
	{ 1559	,8	,1	, &internal1_m1138_sumtakt},	//(internal1_m1138_sumtakt) sumtim - время в пути
	{ 1560	,8	,1	, &internal1_m1138_StSpeed},	//(internal1_m1138_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1561	,8	,1	, &internal1_m1138_Vz0},	//(internal1_m1138_Vz0) Vz0 - предыдущая заданная скорость
	{ 1562	,3	,1	, &internal1_m1138_flRazg},	//(internal1_m1138_flRazg) признак разгона/торможения
	{ 1563	,8	,1	, &internal1_m1138_DelSp},	//(internal1_m1138_DelSp) DelSp - время переключения скоростей
	{ 1564	,8	,1	, &internal1_m1138_z0},	//(internal1_m1138_z0) z0 - точка прекращения движения
	{ 1565	,8	,1	, &internal1_m1138_txZS},	//(internal1_m1138_txZS) txZS
	{ 1566	,8	,1	, &internal1_m1138_tx},	//(internal1_m1138_tx) tx
	{ 1567	,8	,1	, &internal1_m1138_txd},	//(internal1_m1138_txd) txd
	{ 1568	,8	,1	, &internal1_m1138_txMBl},	//(internal1_m1138_txMBl) tx
	{ 1569	,8	,1	, &internal1_m1138_txBl},	//(internal1_m1138_txBl) tx
	{ 1570	,8	,1	, &internal1_m1138_Speed0},	//(internal1_m1138_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1571	,8	,1	, &internal1_m1138_xz0},	//(internal1_m1138_xz0) xz0 - новое задание мм
	{ 1572	,8	,1	, &internal1_m1138_tz0},	//(internal1_m1138_tz0) tz0 - время защиты от нового задания сек
	{ 1573	,1	,1	, &internal1_m1138_Shift0},	//(internal1_m1138_Shift0) Shift0 - признак самохода
	{ 1574	,1	,1	, &internal1_m1138_ShCntlSp0},	//(internal1_m1138_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1575	,1	,1	, &internal1_m1138_ShiftControl},	//(internal1_m1138_ShiftControl) ShiftControl - признак самохода
	{ 1576	,1	,1	, &internal1_m738_x0},	//(internal1_m738_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1577	,1	,1	, &internal1_m708_x0},	//(internal1_m708_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1578	,1	,1	, &internal1_m670_x0},	//(internal1_m670_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1579	,1	,1	, &internal1_m765_q0},	//(internal1_m765_q0) q0 - внутренний параметр
	{ 1580	,1	,1	, &internal1_m759_q0},	//(internal1_m759_q0) q0 - внутренний параметр
	{ 1581	,1	,1	, &internal1_m726_q0},	//(internal1_m726_q0) q0 - внутренний параметр
	{ 1582	,1	,1	, &internal1_m731_q0},	//(internal1_m731_q0) q0 - внутренний параметр
	{ 1583	,1	,1	, &internal1_m739_q0},	//(internal1_m739_q0) q0 - внутренний параметр
	{ 1584	,1	,1	, &internal1_m751_q0},	//(internal1_m751_q0) q0 - внутренний параметр
	{ 1585	,1	,1	, &internal1_m729_q0},	//(internal1_m729_q0) q0 - внутренний параметр
	{ 1586	,18	,1	, &internal1_m1175_DvUp0},	//(internal1_m1175_DvUp0) - есть команда на движение вперёд
	{ 1587	,18	,1	, &internal1_m1175_DvDw0},	//(internal1_m1175_DvDw0) - есть команда на движение назад
	{ 1588	,18	,1	, &internal1_m1175_FDvUp0},	//(internal1_m1175_FDvUp0) - есть команда на движение вперёд
	{ 1589	,18	,1	, &internal1_m1175_FDvDw0},	//(internal1_m1175_FDvDw0) - есть команда на движение назад
	{ 1590	,18	,1	, &internal1_m1175_BlDv0},	//(internal1_m1175_BlDv0) - была блокировка
	{ 1591	,18	,1	, &internal1_m1175_Pkv0},	//(internal1_m1175_Pkv0) Pkv - передний конечный выключатель
	{ 1592	,18	,1	, &internal1_m1175_Pkav0},	//(internal1_m1175_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1593	,18	,1	, &internal1_m1175_Zkv0},	//(internal1_m1175_Zkv0) Zkv - задний конечный выключатель
	{ 1594	,18	,1	, &internal1_m1175_Zkav0},	//(internal1_m1175_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1595	,8	,1	, &internal1_m1175_txNm},	//(internal1_m1175_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1596	,8	,1	, &internal1_m1175_txSm},	//(internal1_m1175_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1597	,8	,1	, &internal1_m1175_txHr},	//(internal1_m1175_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1598	,8	,1	, &internal1_m1175_txLd},	//(internal1_m1175_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1599	,18	,1	, &internal1_m1175_fef},	//(internal1_m1175_fef) fef
	{ 1600	,18	,1	, &internal1_m1165_DvUp0},	//(internal1_m1165_DvUp0) - есть команда на движение вперёд
	{ 1601	,18	,1	, &internal1_m1165_DvDw0},	//(internal1_m1165_DvDw0) - есть команда на движение назад
	{ 1602	,18	,1	, &internal1_m1165_FDvUp0},	//(internal1_m1165_FDvUp0) - есть команда на движение вперёд
	{ 1603	,18	,1	, &internal1_m1165_FDvDw0},	//(internal1_m1165_FDvDw0) - есть команда на движение назад
	{ 1604	,18	,1	, &internal1_m1165_BlDv0},	//(internal1_m1165_BlDv0) - была блокировка
	{ 1605	,18	,1	, &internal1_m1165_Pkv0},	//(internal1_m1165_Pkv0) Pkv - передний конечный выключатель
	{ 1606	,18	,1	, &internal1_m1165_Pkav0},	//(internal1_m1165_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1607	,18	,1	, &internal1_m1165_Zkv0},	//(internal1_m1165_Zkv0) Zkv - задний конечный выключатель
	{ 1608	,18	,1	, &internal1_m1165_Zkav0},	//(internal1_m1165_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1609	,8	,1	, &internal1_m1165_txNm},	//(internal1_m1165_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1610	,8	,1	, &internal1_m1165_txSm},	//(internal1_m1165_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1611	,8	,1	, &internal1_m1165_txHr},	//(internal1_m1165_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1612	,8	,1	, &internal1_m1165_txLd},	//(internal1_m1165_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1613	,18	,1	, &internal1_m1165_fef},	//(internal1_m1165_fef) fef
	{ 1614	,18	,1	, &internal1_m785_DvUp0},	//(internal1_m785_DvUp0) - есть команда на движение вперёд
	{ 1615	,18	,1	, &internal1_m785_DvDw0},	//(internal1_m785_DvDw0) - есть команда на движение назад
	{ 1616	,18	,1	, &internal1_m785_FDvUp0},	//(internal1_m785_FDvUp0) - есть команда на движение вперёд
	{ 1617	,18	,1	, &internal1_m785_FDvDw0},	//(internal1_m785_FDvDw0) - есть команда на движение назад
	{ 1618	,18	,1	, &internal1_m785_BlDv0},	//(internal1_m785_BlDv0) - была блокировка
	{ 1619	,18	,1	, &internal1_m785_Pkv0},	//(internal1_m785_Pkv0) Pkv - передний конечный выключатель
	{ 1620	,18	,1	, &internal1_m785_Pkav0},	//(internal1_m785_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1621	,18	,1	, &internal1_m785_Zkv0},	//(internal1_m785_Zkv0) Zkv - задний конечный выключатель
	{ 1622	,18	,1	, &internal1_m785_Zkav0},	//(internal1_m785_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1623	,8	,1	, &internal1_m785_txNm},	//(internal1_m785_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1624	,8	,1	, &internal1_m785_txSm},	//(internal1_m785_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1625	,8	,1	, &internal1_m785_txHr},	//(internal1_m785_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1626	,8	,1	, &internal1_m785_txLd},	//(internal1_m785_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1627	,18	,1	, &internal1_m785_fef},	//(internal1_m785_fef) fef
	{ 1628	,18	,1	, &internal1_m781_DvUp0},	//(internal1_m781_DvUp0) - есть команда на движение вперёд
	{ 1629	,18	,1	, &internal1_m781_DvDw0},	//(internal1_m781_DvDw0) - есть команда на движение назад
	{ 1630	,18	,1	, &internal1_m781_FDvUp0},	//(internal1_m781_FDvUp0) - есть команда на движение вперёд
	{ 1631	,18	,1	, &internal1_m781_FDvDw0},	//(internal1_m781_FDvDw0) - есть команда на движение назад
	{ 1632	,18	,1	, &internal1_m781_BlDv0},	//(internal1_m781_BlDv0) - была блокировка
	{ 1633	,18	,1	, &internal1_m781_Pkv0},	//(internal1_m781_Pkv0) Pkv - передний конечный выключатель
	{ 1634	,18	,1	, &internal1_m781_Pkav0},	//(internal1_m781_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1635	,18	,1	, &internal1_m781_Zkv0},	//(internal1_m781_Zkv0) Zkv - задний конечный выключатель
	{ 1636	,18	,1	, &internal1_m781_Zkav0},	//(internal1_m781_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1637	,8	,1	, &internal1_m781_txNm},	//(internal1_m781_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1638	,8	,1	, &internal1_m781_txSm},	//(internal1_m781_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1639	,8	,1	, &internal1_m781_txHr},	//(internal1_m781_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1640	,8	,1	, &internal1_m781_txLd},	//(internal1_m781_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1641	,18	,1	, &internal1_m781_fef},	//(internal1_m781_fef) fef
	{ 1642	,18	,1	, &internal1_m347_DvUp0},	//(internal1_m347_DvUp0) - есть команда на движение вперёд
	{ 1643	,18	,1	, &internal1_m347_DvDw0},	//(internal1_m347_DvDw0) - есть команда на движение назад
	{ 1644	,18	,1	, &internal1_m347_FDvUp0},	//(internal1_m347_FDvUp0) - есть команда на движение вперёд
	{ 1645	,18	,1	, &internal1_m347_FDvDw0},	//(internal1_m347_FDvDw0) - есть команда на движение назад
	{ 1646	,18	,1	, &internal1_m347_BlDv0},	//(internal1_m347_BlDv0) - была блокировка
	{ 1647	,18	,1	, &internal1_m347_Pkv0},	//(internal1_m347_Pkv0) Pkv - передний конечный выключатель
	{ 1648	,18	,1	, &internal1_m347_Pkav0},	//(internal1_m347_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1649	,18	,1	, &internal1_m347_Zkv0},	//(internal1_m347_Zkv0) Zkv - задний конечный выключатель
	{ 1650	,18	,1	, &internal1_m347_Zkav0},	//(internal1_m347_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1651	,8	,1	, &internal1_m347_txNm},	//(internal1_m347_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1652	,8	,1	, &internal1_m347_txSm},	//(internal1_m347_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1653	,8	,1	, &internal1_m347_txHr},	//(internal1_m347_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1654	,8	,1	, &internal1_m347_txLd},	//(internal1_m347_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1655	,18	,1	, &internal1_m347_fef},	//(internal1_m347_fef) fef
	{ 1656	,18	,1	, &internal1_m391_DvUp0},	//(internal1_m391_DvUp0) - есть команда на движение вперёд
	{ 1657	,18	,1	, &internal1_m391_DvDw0},	//(internal1_m391_DvDw0) - есть команда на движение назад
	{ 1658	,18	,1	, &internal1_m391_FDvUp0},	//(internal1_m391_FDvUp0) - есть команда на движение вперёд
	{ 1659	,18	,1	, &internal1_m391_FDvDw0},	//(internal1_m391_FDvDw0) - есть команда на движение назад
	{ 1660	,18	,1	, &internal1_m391_BlDv0},	//(internal1_m391_BlDv0) - была блокировка
	{ 1661	,18	,1	, &internal1_m391_Pkv0},	//(internal1_m391_Pkv0) Pkv - передний конечный выключатель
	{ 1662	,18	,1	, &internal1_m391_Pkav0},	//(internal1_m391_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1663	,18	,1	, &internal1_m391_Zkv0},	//(internal1_m391_Zkv0) Zkv - задний конечный выключатель
	{ 1664	,18	,1	, &internal1_m391_Zkav0},	//(internal1_m391_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1665	,8	,1	, &internal1_m391_txNm},	//(internal1_m391_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1666	,8	,1	, &internal1_m391_txSm},	//(internal1_m391_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1667	,8	,1	, &internal1_m391_txHr},	//(internal1_m391_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1668	,8	,1	, &internal1_m391_txLd},	//(internal1_m391_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1669	,18	,1	, &internal1_m391_fef},	//(internal1_m391_fef) fef
	{ 1670	,18	,1	, &internal1_m385_DvUp0},	//(internal1_m385_DvUp0) - есть команда на движение вперёд
	{ 1671	,18	,1	, &internal1_m385_DvDw0},	//(internal1_m385_DvDw0) - есть команда на движение назад
	{ 1672	,18	,1	, &internal1_m385_FDvUp0},	//(internal1_m385_FDvUp0) - есть команда на движение вперёд
	{ 1673	,18	,1	, &internal1_m385_FDvDw0},	//(internal1_m385_FDvDw0) - есть команда на движение назад
	{ 1674	,18	,1	, &internal1_m385_BlDv0},	//(internal1_m385_BlDv0) - была блокировка
	{ 1675	,18	,1	, &internal1_m385_Pkv0},	//(internal1_m385_Pkv0) Pkv - передний конечный выключатель
	{ 1676	,18	,1	, &internal1_m385_Pkav0},	//(internal1_m385_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1677	,18	,1	, &internal1_m385_Zkv0},	//(internal1_m385_Zkv0) Zkv - задний конечный выключатель
	{ 1678	,18	,1	, &internal1_m385_Zkav0},	//(internal1_m385_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1679	,8	,1	, &internal1_m385_txNm},	//(internal1_m385_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1680	,8	,1	, &internal1_m385_txSm},	//(internal1_m385_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1681	,8	,1	, &internal1_m385_txHr},	//(internal1_m385_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1682	,8	,1	, &internal1_m385_txLd},	//(internal1_m385_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1683	,18	,1	, &internal1_m385_fef},	//(internal1_m385_fef) fef
	{ 1684	,1	,1	, &internal1_m735_q0},	//(internal1_m735_q0) q0 - внутренний параметр
	{ 1685	,1	,1	, &internal1_m732_q0},	//(internal1_m732_q0) q0 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="du.bin\0";   // Имя файла для сохранения констант
#pragma pop
static short saveVariables[]={      // Id переменных для сохранения
743,744,745,746,747,748,749,750,751,752,753,754,755,756,757,758,759,760,761,762,763,764,765,766,767,768,769,770,771,772,773,774,775,776,777,778,779,780,781,782,783,784,785,786,787,788,789,790,791,792,793,794,795,796,797,798,799,800,801,802,803,804,805,806,807,808,809,810,811,812,813,814,815,816,817,818,819,820,821,822,823,824,825,826,827,828,829,830,831,832,833,834,835,836,837,838,839,840,841,842,843,844,845,846,847,848,849,850,851,852,853,854,855,856,857,858,859,860,861,862,863,864,865,866,867,868,869,870,871,872,873,874,875,876,877,878,879,880,881,882,883,884,885,886,887,888,889,890,891,892,893,894,895,896,897,898,899,900,901,902,903,904,905,906,907,908,909,910,-1,};
#pragma pack(push,1)
static ModbusRegister coil_DU[]={  // 
	{&R5VS12LDU,1,0},	//(R5VS12LDU) Движение ворот к открыты
	{&R0MW17LP1,1,1},	//(R0MW17LP1) Переключатель «АВТ/Р»
	{&A1MD11LP1,1,2},	//(A1MD11LP1) Кнопка «ПУСК ББ1»
	{&A1MD12LP1,1,3},	//(A1MD12LP1) Переключатель «РАЗРЕШИТЬ» ББ1
	{&R0MD33LP1,1,4},	//(R0MD33LP1) Переключатель «РАЗРЕШИТЬ» МДЗ
	{&A3MD11LP1,1,5},	//(A3MD11LP1) Кнопка «ПУСК ИС1»
	{&A3MD12LP1,1,6},	//(A3MD12LP1) Переключатель «РАЗРЕШИТЬ» ИС1
	{&B2IS11LDU,1,7},	//(B2IS11LDU) Приход на ВУ РБ2-СТР
	{&A2IS11LDU,1,8},	//(A2IS11LDU) Приход на ВУ РБ1-СТР
	{&B3IS22LDU,1,9},	//(B3IS22LDU) Приход на НУП ИС2
	{&A3IS22LDU,1,10},	//(A3IS22LDU) Приход на НУП ИС1
	{&B9IS11LDU,1,11},	//(B9IS11LDU) Приход на ВУ НИ ДС2
	{&A9IS11LDU,1,12},	//(A9IS11LDU) Приход на ВУ НИ ДС1
	{&B2IS33LDU,1,13},	//(B2IS33LDU) Клапан «Подъём РБ2» открыт (обесточен)
	{&A4IS10LDU,1,14},	//(A4IS10LDU) Клапан «Подъём НИ1» открыт (обесточен)
	{&A3IS35LDU,1,15},	//(A3IS35LDU) Клапан «ВПИС1» открыт (обесточен)
	{&A3IS33LDU,1,16},	//(A3IS33LDU) Клапан «ВЫСТРЕЛ ИС1» открыт (обесточен)
	{&A3IS31LDU,1,17},	//(A3IS31LDU) Клапан «СПУСК ИС1» открыт (обесточен)
	{&A2IS33LDU,1,18},	//(A2IS33LDU) Клапан «Подъём РБ1» открыт (обесточен)
	{&B3MD11LP1,1,19},	//(B3MD11LP1) Кнопка «ПУСК ИС2»
	{&B3MD12LP1,1,20},	//(B3MD12LP1) Переключатель «РАЗРЕШИТЬ» ИС2
	{&B7AS31LDU,1,21},	//(B7AS31LDU) Клапан «Обдув АЗ2» открыт (обесточен)
	{&A7AS31LDU,1,22},	//(A7AS31LDU) Клапан «Обдув АЗ1» открыт (обесточен)
	{&A3IS11LDU,1,23},	//(A3IS11LDU) Приход на ВУ ИС1
	{&B1MD11LP1,1,24},	//(B1MD11LP1) Кнопка «ПУСК ББ2»
	{&B1MD12LP1,1,25},	//(B1MD12LP1) Переключатель «РАЗРЕШИТЬ» ББ2
	{&B2MD11LP1,1,26},	//(B2MD11LP1) Кнопка «ПУСК РБ2»
	{&B2MD12LP1,1,27},	//(B2MD12LP1) Переключатель «РАЗРЕШИТЬ» РБ2
	{&A2MD11LP1,1,28},	//(A2MD11LP1) Кнопка «ПУСК РБ1»
	{&A2MD12LP1,1,29},	//(A2MD12LP1) Переключатель «РАЗРЕШИТЬ» РБ1
	{&R0MD34LP1,1,30},	//(R0MD34LP1) Кнопка «Квитировать»
	{&R0MD11LP2,1,31},	//(R0MD11LP2) Кнопка Пуск проверки схем сброса
	{&C1MD31LP2,1,32},	//(C1MD31LP2) Кнопка «СБРОС ББ»
	{&C1MD31LP1,1,33},	//(C1MD31LP1) Кнопка «СБРОС ББ»
	{&R5IS21LDU,1,34},	//(R5IS21LDU) Приход на НУ ворот отстойной зоны
	{&B3IS11LDU,1,35},	//(B3IS11LDU) Приход на ВУ ИС2
	{&B3MC01LC1,1,36},	//(B3MC01LC1) Настроить энкодер ИС2
	{&A2MC01LC2,1,37},	//(A2MC01LC2) Настроить энкодер РБ1
	{&A2MC01LC1,1,38},	//(A2MC01LC1) Настроить энкодер РБ1
	{&B2MC01LC2,1,39},	//(B2MC01LC2) Настроить энкодер РБ2
	{&B2MC01LC1,1,40},	//(B2MC01LC1) Настроить энкодер РБ2
	{&A1MC01LC2,1,41},	//(A1MC01LC2) Настроить энкодер ББ1
	{&A1MC01LC1,1,42},	//(A1MC01LC1) Настроить энкодер ББ1
	{&B1MC01LC2,1,43},	//(B1MC01LC2) Настроить энкодер ББ2
	{&B1MC01LC1,1,44},	//(B1MC01LC1) Настроить энкодер ББ2
	{&A1IS11LDU,1,45},	//(A1IS11LDU) Приход на ВУ ББ1
	{&B1IS11LDU,1,46},	//(B1IS11LDU) Приход на ВУ ББ2
	{&R6IS68LZ2,1,47},	//(R6IS68LZ2) Исправность ВИП 4,0 (№7) ССДИ-2
	{&R6IS67LZ2,1,48},	//(R6IS67LZ2) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{&R6IS66LZ1,1,49},	//(R6IS66LZ1) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{&R6IS68LZ1,1,50},	//(R6IS68LZ1) Исправность ВИП 4,0 (№7) ССДИ-2
	{&R6IS67LZ1,1,51},	//(R6IS67LZ1) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{&R6IS66LZ2,1,52},	//(R6IS66LZ2) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{&B3MC01LC2,1,53},	//(B3MC01LC2) Настроить энкодер ИС2
	{&A3MC01LC1,1,54},	//(A3MC01LC1) Настроить энкодер ИС1
	{&A3MC01LC2,1,55},	//(A3MC01LC2) Настроить энкодер ИС1
	{&B8MC01LC1,1,56},	//(B8MC01LC1) Настроить энкодер АЗ2
	{&B8MC01LC2,1,57},	//(B8MC01LC2) Настроить энкодер АЗ2
	{&A8MC01LC1,1,58},	//(A8MC01LC1) Настроить энкодер ДС2
	{&A8MC01LC2,1,59},	//(A8MC01LC2) Настроить энкодер ДС2
	{&C2MD31LP1,1,60},	//(C2MD31LP1) Кнопка «СБРОС РБ»
	{&R0EE03LDU,1,61},	//(R0EE03LDU) ВПИС ИС
	{&R3IS31LDU,1,62},	//(R3IS31LDU) Приход на ВУ гомогенных дверей-2
	{&R3IS41LDU,1,63},	//(R3IS41LDU) Приход на НУ гомогенных дверей-2
	{&R3IS21LDU,1,64},	//(R3IS21LDU) Приход на НУ гомогенных дверей-1
	{&R3IS11LDU,1,65},	//(R3IS11LDU) Приход на ВУ гомогенных дверей-1
	{&B4IS10LDU,1,66},	//(B4IS10LDU) Клапан «Подъём НИ2» открыт (обесточен)
	{&B3IS35LDU,1,67},	//(B3IS35LDU) Клапан «ВПИС2» открыт (обесточен)
	{&B3IS33LDU,1,68},	//(B3IS33LDU) Клапан «ВЫСТРЕЛ ИС2» открыт (обесточен)
	{&B3IS31LDU,1,69},	//(B3IS31LDU) Клапан «СПУСК ИС2» открыт (обесточен)
	{&B2IS12LDU,1,70},	//(B2IS12LDU) Магнит РБ2 зацеплен
	{&B1IS12LDU,1,71},	//(B1IS12LDU) Магнит ББ2 зацеплен
	{&A2IS12LDU,1,72},	//(A2IS12LDU) Магнит РБ1 зацеплен
	{&A1IS12LDU,1,73},	//(A1IS12LDU) Магнит ББ1 зацеплен
	{&B4IS21LDU,1,74},	//(B4IS21LDU) Приход на НУ НИ2
	{&A4IS21LDU,1,75},	//(A4IS21LDU) Приход на НУ НИ1
	{&B5IS21LDU,1,76},	//(B5IS21LDU) Приход на НУ НЛ2
	{&B5IS11LDU,1,77},	//(B5IS11LDU) Приход на ВУ НЛ2
	{&A5IS21LDU,1,78},	//(A5IS21LDU) Приход на НУ НЛ1
	{&A5IS11LDU,1,79},	//(A5IS11LDU) Приход на ВУ НЛ1
	{&B5VS12LDU,1,80},	//(B5VS12LDU) Движение НЛ2 в сторону ВУ
	{&B5VS22LDU,1,81},	//(B5VS22LDU) Движение НЛ2 в сторону НУ
	{&A5VS12LDU,1,82},	//(A5VS12LDU) Движение НЛ1 в сторону ВУ
	{&A5VS22LDU,1,83},	//(A5VS22LDU) Движение НЛ1 в сторону НУ
	{&R5IS11LDU,1,84},	//(R5IS11LDU) Приход на ВУ ворот отстойной зоны
	{&B8IS12LDU,1,85},	//(B8IS12LDU) Приход на механический ВУ АЗ2
	{&R0MD11LP1,1,86},	//(R0MD11LP1) Кнопка «ПУСК»
	{&R4IS11LDU,1,87},	//(R4IS11LDU) Приход на ВУ тележки
	{&B6VS12LDU,1,88},	//(B6VS12LDU) Движение створок БЗ2  к  «ОТКРЫТА»
	{&B6VS22LDU,1,89},	//(B6VS22LDU) Движение створок БЗ2  к «ЗАКРЫТА»
	{&A6VS12LDU,1,90},	//(A6VS12LDU) Движение створок БЗ1  к  «ОТКРЫТА»
	{&A6VS22LDU,1,91},	//(A6VS22LDU) Движение створок БЗ1  к «ЗАКРЫТА»
	{&B6IS21LDU,1,92},	//(B6IS21LDU) Приход на НУ БЗ2
	{&B6IS11LDU,1,93},	//(B6IS11LDU) Приход на ВУ БЗ2
	{&A6IS21LDU,1,94},	//(A6IS21LDU) Приход на НУ БЗ1
	{&A6IS11LDU,1,95},	//(A6IS11LDU) Приход на ВУ БЗ1
	{&R4MD21LP2,1,96},	//(R4MD21LP2) Кнопка «НАЗАД»  (тележки)
	{&R4MD31LP2,1,97},	//(R4MD31LP2) Кнопка «СТОП»  (тележки)
	{&R4MD11LP2,1,98},	//(R4MD11LP2) Кнопка «ВПЕРЁД»  (тележки)
	{&B3IS21LDU,1,99},	//(B3IS21LDU) Приход на НУ ИС2
	{&B2IS21LDU,1,100},	//(B2IS21LDU) Приход на НУ РБ2-СС
	{&B1IS21LDU,1,101},	//(B1IS21LDU) Приход на НУ ББ2
	{&A3IS21LDU,1,102},	//(A3IS21LDU) Приход на НУ ИС1
	{&A2IS21LDU,1,103},	//(A2IS21LDU) Приход на НУ РБ1-СС
	{&A1IS21LDU,1,104},	//(A1IS21LDU) Приход на НУ ББ1
	{&R0MD31LP1,1,105},	//(R0MD31LP1) Кнопка «СТОП»
	{&R0MD32LP1,1,106},	//(R0MD32LP1) Кнопка «СПУСК»
	{&R0MW13LP2,1,107},	//(R0MW13LP2) Переключатель «СЕТЬ»
	{&B4IS11LDU,1,108},	//(B4IS11LDU) Приход на ВУ НИ2
	{&A4IS11LDU,1,109},	//(A4IS11LDU) Приход на ВУ НИ1
	{&R2IS21LDU,1,110},	//(R2IS21LDU) Приход на НУ МДЗ2
	{&R1IS21LDU,1,111},	//(R1IS21LDU) Приход на НУ МДЗ1
	{&R8IS11LDU,1,112},	//(R8IS11LDU) Аварийный НИ установлен
	{&R0NE01LDU,1,113},	//(R0NE01LDU) Потеря связи с БАЗ1
	{&R0NE02LDU,1,114},	//(R0NE02LDU) Потеря связи с БАЗ2
	{&R0NE08LDU,1,115},	//(R0NE08LDU) Потеря связи с ОПУ
	{&R4IS21LDU,1,116},	//(R4IS21LDU) Приход на НУ тележки
	{&R4IS22LDU,1,117},	//(R4IS22LDU) Приход на механический НУ тележки
	{&R4IS12LDU,1,118},	//(R4IS12LDU) Приход на механический ВУ тележки
	{&R4VS22LDU,1,119},	//(R4VS22LDU) Движение реактора к «У ЗАЩИТЫ»
	{&R4VS12LDU,1,120},	//(R4VS12LDU) Движение реактора  к «У ОБРАЗЦОВ»
	{&R2IS11LDU,1,121},	//(R2IS11LDU) Приход на ВУ МДЗ2
	{&R1VS12LDU,1,122},	//(R1VS12LDU) Движение МДЗ1 в сторону ВУ
	{&B8IS22LDU,1,123},	//(B8IS22LDU) Приход на механический НУ АЗ2
	{&A8IS12LDU,1,124},	//(A8IS12LDU) Приход на механический ВУ ДС2
	{&A8IS22LDU,1,125},	//(A8IS22LDU) Приход на механический НУ ДС2
	{&R2VS12LDU,1,126},	//(R2VS12LDU) Движение МДЗ2 в сторону ВУ
	{&R2VS22LDU,1,127},	//(R2VS22LDU) Движение МДЗ2 в сторону НУ
	{&R1VS22LDU,1,128},	//(R1VS22LDU) Движение МДЗ1 в сторону НУ
	{&R1IS11LDU,1,129},	//(R1IS11LDU) Приход на ВУ МДЗ1
	{&lEM_R0MD01LC1,1,130},	//(R0MD01LC1) Ручное управление ОРР
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DU[]={  // 
	{&R0VS17LDU,1,0},	//(R0VS17LDU) Индикация выбора АВТОМАТ
	{&R0VX09LDU,1,1},	//(R0VX09LDU) Индикация регулятор мощности включен/отключен
	{&R0VW23LDU,1,2},	//(R0VW23LDU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,1,3},	//(R0VW13LDU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{&R0AB01LDU,1,4},	//(R0AB01LDU) Режим проверки разрешён
	{&B9AB02LDU,1,5},	//(B9AB02LDU) Блокировка НИ ДС2 - Нет перемещения
	{&B9AB01LDU,1,6},	//(B9AB01LDU) Блокировка движения НИ ДС2 - Превышение времени движения
	{&B9AZ03LDU,1,7},	//(B9AZ03LDU) Несанкционированное перемещение НИ ДС2
	{&A9AB02LDU,1,8},	//(A9AB02LDU) Блокировка НИ ДС1 - Нет перемещения
	{&A9AB01LDU,1,9},	//(A9AB01LDU) Блокировка движения НИ ДС1 - Превышение времени движения
	{&A9AZ03LDU,1,10},	//(A9AZ03LDU) Несанкционированное перемещение НИ ДС1
	{&R5AB04LDU,1,11},	//(R5AB04LDU) Блокировка ворот отстойной зоны -Ошибка в направлении  движения
	{&R5AB02LDU,1,12},	//(R5AB02LDU) Блокировка ворот отстойной зоны - Нет перемещения
	{&A1AB19LDU,1,13},	//(A1AB19LDU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
	{&R0VZ71LDU,1,14},	//(R0VZ71LDU) Обобщенный сигнал АЗ
	{&B7AZ03LDU,1,15},	//(B7AZ03LDU) Несанкционированное включение обдува АЗ2
	{&A7AZ03LDU,1,16},	//(A7AZ03LDU) Несанкционированное включение обдува АЗ1
	{&R5VS22LDU,1,17},	//(R5VS22LDU) Движение ворот к закрыты
	{&A2VS32LDU,1,18},	//(A2VS32LDU) Индикация  «СБРОС РБ1»
	{&B2VS32LDU,1,19},	//(B2VS32LDU) Индикация  «СБРОС РБ2»
	{&A3VX01LDU,1,20},	//(A3VX01LDU) Индикация Выстрел ИС1
	{&B3VX01LDU,1,21},	//(B3VX01LDU) Индикация Выстрел ИС2
	{&R0VS18LDU,1,22},	//(R0VS18LDU) Индикация  «Проверка» схем сброса
	{&R0VP73LDU,1,23},	//(R0VP73LDU) ПС давления для РУ
	{&B2VS11LDU,1,24},	//(B2VS11LDU) Движение РБ2 в сторону ВУ
	{&B2VS21LDU,1,25},	//(B2VS21LDU) Движение РБ2 в сторону НУ
	{&B1AD31LDU,1,26},	//(B1AD31LDU) Клапан «Сброс ББ2» открыть (обесточить)
	{&A1AD31LDU,1,27},	//(A1AD31LDU) Клапан «Сброс ББ1» открыть (обесточить)
	{&B2AD31LDU,1,28},	//(B2AD31LDU) Клапан «Сброс РБ2» открыть (обесточить)
	{&A2AD31LDU,1,29},	//(A2AD31LDU) Клапан «Сброс РБ1» открыть (обесточить)
	{&B3AB20LDU,1,30},	//(B3AB20LDU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
	{&B3AB19LDU,1,31},	//(B3AB19LDU) Блокировка пневматического подъема ИС2: режим статический
	{&B3AB18LDU,1,32},	//(B3AB18LDU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
	{&B3AB17LDU,1,33},	//(B3AB17LDU) Блокировка перемещения ИС2: выполняется программа 20 мин
	{&B3AB16LDU,1,34},	//(B3AB16LDU) Блокировка перемещения ИС2: выполняется программа 200 с
	{&B3AB14LDU,1,35},	//(B3AB14LDU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
	{&B3AB13LDU,1,36},	//(B3AB13LDU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
	{&B3AB12LDU,1,37},	//(B3AB12LDU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{&B3AB11LDU,1,38},	//(B3AB11LDU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
	{&B3AB10LDU,1,39},	//(B3AB10LDU) Блокировка подъёма ИС2- есть сигнал общего сброса
	{&B3AB09LDU,1,40},	//(B3AB09LDU) Блокировка подъёма ИС2- АНИ не установлен
	{&B3AB06LDU,1,41},	//(B3AB06LDU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
	{&B3AB05LDU,1,42},	//(B3AB05LDU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
	{&B3AB08LDU,1,43},	//(B3AB08LDU) Блокировка подъёма ИС2 - реактор не на рабочем месте
	{&B3AB07LDU,1,44},	//(B3AB07LDU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
	{&B3AZ03LDU,1,45},	//(B3AZ03LDU) Несанкционированное перемещение ИС2
	{&B3VS22LDU,1,46},	//(B3VS22LDU) Движение ИС2 в сторону НУ
	{&B3AB01LDU,1,47},	//(B3AB01LDU) Блокировка движения ИС2: скорость перемещения менее заданной
	{&B3AB02LDU,1,48},	//(B3AB02LDU) Блокировка движения ИС2: превышение заданной скорости
	{&B3AB04LDU,1,49},	//(B3AB04LDU) Блокировка движения ИС2 нет перемещения  ИС1
	{&B3VS12LDU,1,50},	//(B3VS12LDU) Движение ИС2 в сторону ВУ
	{&A3AB20LDU,1,51},	//(A3AB20LDU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
	{&A3AB19LDU,1,52},	//(A3AB19LDU) Блокировка пневматического подъема ИС1: режим статический
	{&R5AB01LDU,1,53},	//(R5AB01LDU) Блокировка движения ворот отстойной зоны - Превышение времени движения
	{&R5AZ03LDU,1,54},	//(R5AZ03LDU) Несанкционированное перемещение ворот отстойной зоны
	{&B4VS22LDU,1,55},	//(B4VS22LDU) Движение НИ2 в сторону НУ
	{&B4VS12LDU,1,56},	//(B4VS12LDU) Движение НИ2 в сторону ВУ
	{&A4VS22LDU,1,57},	//(A4VS22LDU) Движение НИ1 в сторону НУ
	{&A4VS12LDU,1,58},	//(A4VS12LDU) Движение НИ1 в сторону ВУ
	{&R0VX01LDU,1,59},	//(R0VX01LDU) ДО ИМПУЛЬСА
	{&R0AB04LDU,1,60},	//(R0AB04LDU) Нарушение времени срабатывания верхней АС II УР
	{&R0AB06LDU,1,61},	//(R0AB06LDU) Нарушение времени задержки от ВУ РБ
	{&R0AB02LDU,1,62},	//(R0AB02LDU) Нарушение времени задержки ИНИ
	{&R0VX03LDU,1,63},	//(R0VX03LDU) Готовность 2 мин
	{&R0AB19LDU,1,64},	//(R0AB19LDU) Остановка регулирования мощности: Есть блокировки  ИС1,2
	{&R0AB20LDU,1,65},	//(R0AB20LDU) Блокировка изменения положения ОР: работает  регулятор мощности
	{&A3AB15LDU,1,66},	//(A3AB15LDU) Блокировка заполнения ресивера ИС1,2: работает регулятор мощности
	{&R0AB18LDU,1,67},	//(R0AB18LDU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
	{&R0AB17LDU,1,68},	//(R0AB17LDU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
	{&R0AB16LDU,1,69},	//(R0AB16LDU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
	{&B1AB19LDU,1,70},	//(B1AB19LDU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
	{&B0VS11LDU,1,71},	//(B0VS11LDU) АЗ2 готова к работе
	{&A0VS11LDU,1,72},	//(A0VS11LDU) АЗ1 готова к работе
	{&B0VN01LDU,1,73},	//(B0VN01LDU) Каналы АЗ2 проверены
	{&A0VN01LDU,1,74},	//(A0VN01LDU) Каналы АЗ1 проверены
	{&B0VP01LDU,1,75},	//(B0VP01LDU) Давление в системы АЗ2 подано
	{&A0VP01LDU,1,76},	//(A0VP01LDU) Давление в системы АЗ1 подано
	{&A3VP42LDU,1,77},	//(A3VP42LDU) Давление ВЫСТРЕЛ ИС1 ниже АС
	{&A3VP52LDU,1,78},	//(A3VP52LDU) Давление ВЫСТРЕЛ ИС1 ниже ПС
	{&B3VP42LDU,1,79},	//(B3VP42LDU) Давление ВЫСТРЕЛ ИС2 ниже АС
	{&B3VP52LDU,1,80},	//(B3VP52LDU) Давление ВЫСТРЕЛ ИС2 ниже ПС
	{&B3VP82LDU,1,81},	//(B3VP82LDU) Давление ВЫСТРЕЛ ИС2 в норме
	{&A3VP82LDU,1,82},	//(A3VP82LDU) Давление ВЫСТРЕЛ ИС1 в норме
	{&A0VE01LDU,1,83},	//(A0VE01LDU) Напряжение в системы АЗ1 подано
	{&B0VE01LDU,1,84},	//(B0VE01LDU) Напряжение в системы АЗ2 подано
	{&R3IS22LDU,1,85},	//(R3IS22LDU) Приход на НУ гомогенных дверей
	{&R3VS11LDU,1,86},	//(R3VS11LDU) Движение дверей-2 к открыто
	{&R3VS22LDU,1,87},	//(R3VS22LDU) Движение дверей-2  к закрыто
	{&R0AB07LDU,1,88},	//(R0AB07LDU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
	{&R0VX02LDU,1,89},	//(R0VX02LDU) Импульс разрешен
	{&B2AB15LDU,1,90},	//(B2AB15LDU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{&A2AB15LDU,1,91},	//(A2AB15LDU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{&R0AB05LDU,1,92},	//(R0AB05LDU) Нарушение времени срабатывания АЗ от НУП ИС
	{&R0AB03LDU,1,93},	//(R0AB03LDU) Нарушение времени срабатывания АЗ от ВУ ИС
	{&R3VS10LDU,1,94},	//(R3VS10LDU) Движение дверей-1 к открыто
	{&R3AB14LDU,1,95},	//(R3AB14LDU) Блокировка гомогенных дверей-2 -Ошибка в направлении  движения
	{&R3AB12LDU,1,96},	//(R3AB12LDU) Блокировка гомогенных дверей-2 - Нет перемещения
	{&R3AB11LDU,1,97},	//(R3AB11LDU) Блокировка движения гомогенных дверей-2 - Превышение времени движения
	{&R3AZ13LDU,1,98},	//(R3AZ13LDU) Несанкционированное перемещение гомогенных дверей-2
	{&R3VS20LDU,1,99},	//(R3VS20LDU) Движение дверей-1  к закрыто
	{&R3AB04LDU,1,100},	//(R3AB04LDU) Блокировка гомогенных дверей -Ошибка в направлении  движения
	{&R3AB02LDU,1,101},	//(R3AB02LDU) Блокировка гомогенных дверей - Нет перемещения
	{&R3AB01LDU,1,102},	//(R3AB01LDU) Блокировка движения гомогенных дверей - Превышение времени движения
	{&R3AZ03LDU,1,103},	//(R3AZ03LDU) Несанкционированное перемещение гомогенных дверей
	{&A3ZAV,1,104},	//(A3ZAV)  Дискретный вход (Discrete Input)
	{&A1ZAV,1,105},	//(A1ZAV)  Дискретный вход (Discrete Input)
	{&B3IS12LDU,1,106},	//(B3IS12LDU) Приход на ВУ штока ИС2
	{&A3IS12LDU,1,107},	//(A3IS12LDU) Приход на ВУ штока ИС1
	{&R0AB15LDU,1,108},	//(R0AB15LDU) Режим проверки не разрешён: ИС1 ниже 55 мм
	{&R0AB14LDU,1,109},	//(R0AB14LDU) Режим проверки не разрешён: ИС2 ниже 55 мм
	{&A4DW,1,110},	//(A4DW)  Дискретный вход (Discrete Input)
	{&A4UP,1,111},	//(A4UP)  Дискретный вход (Discrete Input)
	{&R4ABL,1,112},	//(R4ABL) Блокировка тележки -
	{&A9ZAV,1,113},	//(A9ZAV) Завершение НИ ДС1(2)
	{&A8ZAV,1,114},	//(A8ZAV)  Дискретный вход (Discrete Input)
	{&A2ZAV,1,115},	//(A2ZAV) Завершение РБ1,2
	{&B8ZAV,1,116},	//(B8ZAV)  Дискретный вход (Discrete Input)
	{&A5ZAV,1,117},	//(A5ZAV)  Дискретный вход (Discrete Input)
	{&R2ZAV,1,118},	//(R2ZAV)  Дискретный вход (Discrete Input)
	{&A6ZAV,1,119},	//(A6ZAV)  Дискретный вход (Discrete Input)
	{&R3IS12LDU,1,120},	//(R3IS12LDU) Приход на ВУ гомогенных дверей
	{&R0VS11LDU,1,121},	//(R0VS11LDU) РУ не готова к работе
	{&B6AB05LDU,1,122},	//(B6AB05LDU) Блокировка открытия БЗ2- АНИ не установлен
	{&R0AB08LDU,1,123},	//(R0AB08LDU) Блокировка кнопки ПУСК - тележка не у образцов
	{&R0AB09LDU,1,124},	//(R0AB09LDU) Ошибка в заданной координате ББ1
	{&R0AB10LDU,1,125},	//(R0AB10LDU) Ошибка в заданной координате ББ2
	{&R0AB11LDU,1,126},	//(R0AB11LDU) Ошибка в заданной координате  ИС1
	{&R0AB12LDU,1,127},	//(R0AB12LDU) Ошибка в заданной координате  ИС2
	{&R0AB13LDU,1,128},	//(R0AB13LDU) Ошибка в заданной координате  АЗ2
	{&A4ZAV,1,129},	//(A4ZAV)  Дискретный вход (Discrete Input)
	{&B5AB04LDU,1,130},	//(B5AB04LDU) Блокировка НЛ2 -Ошибка в направлении  движения
	{&A5AB04LDU,1,131},	//(A5AB04LDU) Блокировка НЛ1 -Ошибка в направлении  движения
	{&B4AB02LDU,1,132},	//(B4AB02LDU) Блокировка НИ2 - Нет перемещения
	{&B4AB01LDU,1,133},	//(B4AB01LDU) Блокировка движения НИ2 - Превышение времени движения
	{&B4AZ03LDU,1,134},	//(B4AZ03LDU) Несанкционированное перемещение НИ1
	{&A4AB02LDU,1,135},	//(A4AB02LDU) Блокировка НИ1 - Нет перемещения
	{&A4AB01LDU,1,136},	//(A4AB01LDU) Блокировка движения НИ ДС1 - Превышение времени движения
	{&A4AZ03LDU,1,137},	//(A4AZ03LDU) Несанкционированное перемещение НИ1
	{&B5AB02LDU,1,138},	//(B5AB02LDU) Блокировка НЛ2 - Нет перемещения
	{&B5AB01LDU,1,139},	//(B5AB01LDU) Блокировка движения НЛ2 - Превышение времени движения
	{&B5AZ03LDU,1,140},	//(B5AZ03LDU) Несанкционированное перемещение НЛ2
	{&A5AB02LDU,1,141},	//(A5AB02LDU) Блокировка НЛ1 - Нет перемещения
	{&A5AB01LDU,1,142},	//(A5AB01LDU) Блокировка движения НЛ1 - Превышение времени движения
	{&A5AZ03LDU,1,143},	//(A5AZ03LDU) Несанкционированное перемещение НЛ1
	{&R4AB18LDU,1,144},	//(R4AB18LDU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
	{&R4AB17LDU,1,145},	//(R4AB17LDU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
	{&R4AB16LDU,1,146},	//(R4AB16LDU) Блокировка тележки - Гомогенные двери не в положении Закрыты
	{&A8AB07LDU,1,147},	//(A8AB07LDU) Блокировка движения ДС2: превышение заданной скорости
	{&A8AB06LDU,1,148},	//(A8AB06LDU) Блокировка движения ДС2 нет перемещения ДС2
	{&A8VS12LDU,1,149},	//(A8VS12LDU) Движение ДС2 в сторону ВУ
	{&B8AB02LDU,1,150},	//(B8AB02LDU) Блокировка движения АЗ2- АНИ не установлен
	{&B8AB14LDU,1,151},	//(B8AB14LDU) Блокировка движения АЗ2 - Самоход любого механизма
	{&B8AB13LDU,1,152},	//(B8AB13LDU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
	{&B8AB12LDU,1,153},	//(B8AB12LDU) Блокировка движения АЗ2 - НИ не в положении ВУ
	{&B8AB11LDU,1,154},	//(B8AB11LDU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
	{&B8AB10LDU,1,155},	//(B8AB10LDU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
	{&B8AB09LDU,1,156},	//(B8AB09LDU) Блокировка  - АЗ2 по мощности от любого канала
	{&B8AB08LDU,1,157},	//(B8AB08LDU) Блокировка движения ДС2 Гомогенные двери не закрыты
	{&B8AB04LDU,1,158},	//(B8AB04LDU) Блокировка АЗ2 -Ошибка в направлении  движения
	{&B8AB01LDU,1,159},	//(B8AB01LDU) Блокировка движения АЗ2 - Превышение времени движения
	{&A6AB06LDU,1,160},	//(A6AB06LDU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
	{&A6AB07LDU,1,161},	//(A6AB07LDU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
	{&A6AB08LDU,1,162},	//(A6AB08LDU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
	{&A6AB09LDU,1,163},	//(A6AB09LDU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
	{&B6AB06LDU,1,164},	//(B6AB06LDU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
	{&B6AB07LDU,1,165},	//(B6AB07LDU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
	{&B6AB08LDU,1,166},	//(B6AB08LDU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
	{&B6AB09LDU,1,167},	//(B6AB09LDU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
	{&A6AB05LDU,1,168},	//(A6AB05LDU) Блокировка открытия БЗ1 - АНИ не установлен
	{&B8VS12LDU,1,169},	//(B8VS12LDU) Движение АЗ2 в сторону ВУ
	{&B8AB06LDU,1,170},	//(B8AB06LDU) Блокировка движения АЗ2 нет перемещения АЗ2
	{&B8AB07LDU,1,171},	//(B8AB07LDU) Блокировка движения АЗ2: превышение заданной скорости
	{&B8AB05LDU,1,172},	//(B8AB05LDU) Блокировка движения АЗ2: скорость перемещения менее заданной
	{&B8VS22LDU,1,173},	//(B8VS22LDU) Движение АЗ2 в сторону НУ
	{&B8AZ03LDU,1,174},	//(B8AZ03LDU) Несанкционированное перемещение АЗ2
	{&B6AZ03LDU,1,175},	//(B6AZ03LDU) Несанкционированное перемещение БЗ2
	{&A6AB02LDU,1,176},	//(A6AB02LDU) Блокировка БЗ1 - Нет перемещения
	{&A6AB01LDU,1,177},	//(A6AB01LDU) Блокировка движения БЗ1 - Превышение времени движения
	{&A6AZ03LDU,1,178},	//(A6AZ03LDU) Несанкционированное перемещение БЗ1
	{&R0ES01LDU,1,179},	//(R0ES01LDU) ОРР не в исходном состоянии
	{&R4AB15LDU,1,180},	//(R4AB15LDU) Блокировка тележки - ворота в пом. 0041 не в положении Открыто
	{&R4AB14LDU,1,181},	//(R4AB14LDU) Блокировка тележки - Кран - балка не в безопасном положении
	{&R4AB13LDU,1,182},	//(R4AB13LDU) Блокировка тележки - НЛ не в положении ВУ
	{&R4AB12LDU,1,183},	//(R4AB12LDU) Блокировка тележки - НИ не в положении ВУ
	{&R4AB11LDU,1,184},	//(R4AB11LDU) Блокировка тележки - МДЗ1,2 не находятся на НУ
	{&R4AB10LDU,1,185},	//(R4AB10LDU) Блокировка тележки - не открыта биологическая защита
	{&R4AB09LDU,1,186},	//(R4AB09LDU) Блокировка тележки - АЗ по мощности от любого канала
	{&R4AB08LDU,1,187},	//(R4AB08LDU) Блокировка тележки - А32 или ДС2 не на НУ(координата 1500 мм)
	{&R4AB07LDU,1,188},	//(R4AB07LDU) Блокировка тележки - ОРР не в исходном состоянии
	{&R4AB06LDU,1,189},	//(R4AB06LDU) Блокировка тележки - Ошибка в  направлении перемещения
	{&R4AB05LDU,1,190},	//(R4AB05LDU) Блокировка тележки - Нет перемещения тележки
	{&R4AB04LDU,1,191},	//(R4AB04LDU) Блокировка тележки - Превышение времени движения
	{&B6AB01LDU,1,192},	//(B6AB01LDU) Блокировка движения БЗ2 - Превышение времени движения
	{&B6AB02LDU,1,193},	//(B6AB02LDU) Блокировка БЗ2 - Нет перемещения
	{&A6AB04LDU,1,194},	//(A6AB04LDU) Блокировка БЗ1 -Ошибка в направлении  движения
	{&B6AB04LDU,1,195},	//(B6AB04LDU) Блокировка БЗ2 -Ошибка в направлении  движения
	{&R4AB01LDU,1,196},	//(R4AB01LDU) Блокировка тележки - АНИ не установлен
	{&R4AB02LDU,1,197},	//(R4AB02LDU) Блокировка тележки - Потеря связи с БАЗ, ОПУ
	{&R4AZ03LDU,1,198},	//(R4AZ03LDU) Несанкционированное перемещение тележки
	{&R4AB03LDU,1,199},	//(R4AB03LDU) Блокировка тележки - Самоход любого механизма
	{&B1AB07LDU,1,200},	//(B1AB07LDU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
	{&B1AZ03LDU,1,201},	//(B1AZ03LDU) Сброс ББ2: Несанкционированное перемещение ББ2
	{&B1VS22LDU,1,202},	//(B1VS22LDU) Движение ББ2 в сторону НУ
	{&B1AB01LDU,1,203},	//(B1AB01LDU) Блокировка движения ББ2: скорость перемещения менее заданной
	{&B1AB02LDU,1,204},	//(B1AB02LDU) Блокировка движения ББ2: превышение заданной скорости
	{&B1AB04LDU,1,205},	//(B1AB04LDU) Блокировка движения ББ2 нет перемещения  ББ2
	{&B1VS12LDU,1,206},	//(B1VS12LDU) Движение ББ2 в сторону ВУ
	{&A1AB18LDU,1,207},	//(A1AB18LDU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
	{&A1AB17LDU,1,208},	//(A1AB17LDU) Блокировка перемещения ББ1: выполняется программа 20 мин
	{&A1AB16LDU,1,209},	//(A1AB16LDU) Блокировка перемещения ББ1: выполняется программа 200 с
	{&A1AB14LDU,1,210},	//(A1AB14LDU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
	{&A1AB13LDU,1,211},	//(A1AB13LDU) Блокировка подъёма ББ1- давление в пневмосистеме ББ1 ниже значения заданного предупредительной уставкой
	{&A1AB12LDU,1,212},	//(A1AB12LDU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&A1AB11LDU,1,213},	//(A1AB11LDU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
	{&A1AB10LDU,1,214},	//(A1AB10LDU) Блокировка подъёма ББ1- есть сигнал общего сброса
	{&A1AB09LDU,1,215},	//(A1AB09LDU) Блокировка подъёма ББ1- АНИ не установлен
	{&A1AB06LDU,1,216},	//(A1AB06LDU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
	{&A1AB05LDU,1,217},	//(A1AB05LDU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
	{&A1AB08LDU,1,218},	//(A1AB08LDU) Блокировка подъёма ББ1 - реактор не на рабочем месте
	{&A1AB07LDU,1,219},	//(A1AB07LDU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
	{&A1AZ03LDU,1,220},	//(A1AZ03LDU) Сброс ББ1: Несанкционированное перемещение ББ1
	{&A1VS22LDU,1,221},	//(A1VS22LDU) Движение ББ1 в сторону НУ
	{&A1AB01LDU,1,222},	//(A1AB01LDU) Блокировка движения ББ1: скорость перемещения менее заданной
	{&A1AB02LDU,1,223},	//(A1AB02LDU) Блокировка движения ББ1: превышение заданной скорости
	{&A1AB04LDU,1,224},	//(A1AB04LDU) Блокировка движения ББ1 нет перемещения  ББ1
	{&A1VS12LDU,1,225},	//(A1VS12LDU) Движение ББ1 в сторону ВУ
	{&A3AB18LDU,1,226},	//(A3AB18LDU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
	{&A3AB17LDU,1,227},	//(A3AB17LDU) Блокировка перемещения ИС1: выполняется программа 20 мин
	{&A3AB16LDU,1,228},	//(A3AB16LDU) Блокировка перемещения ИС1: выполняется программа 200 с
	{&A3AB14LDU,1,229},	//(A3AB14LDU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
	{&A3AB13LDU,1,230},	//(A3AB13LDU) Блокировка подъёма ИС1- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
	{&A3AB12LDU,1,231},	//(A3AB12LDU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&A3AB11LDU,1,232},	//(A3AB11LDU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
	{&A3AB10LDU,1,233},	//(A3AB10LDU) Блокировка подъёма ИС1- есть сигнал общего сброса
	{&A3AB09LDU,1,234},	//(A3AB09LDU) Блокировка подъёма ИС1- АНИ не установлен
	{&A3AB06LDU,1,235},	//(A3AB06LDU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
	{&A3AB05LDU,1,236},	//(A3AB05LDU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
	{&A3AB08LDU,1,237},	//(A3AB08LDU) Блокировка подъёма ИС1 - реактор не на рабочем месте
	{&A3AB07LDU,1,238},	//(A3AB07LDU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
	{&A3AZ03LDU,1,239},	//(A3AZ03LDU) Несанкционированное перемещение ИС1
	{&A3VS22LDU,1,240},	//(A3VS22LDU) Движение ИС1 в сторону НУ
	{&B1AB08LDU,1,241},	//(B1AB08LDU) Блокировка подъёма ББ2 - реактор не на рабочем месте
	{&B1AB05LDU,1,242},	//(B1AB05LDU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
	{&B1AB06LDU,1,243},	//(B1AB06LDU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
	{&B1AB09LDU,1,244},	//(B1AB09LDU) Блокировка подъёма ББ2- АНИ не установлен
	{&B1AB10LDU,1,245},	//(B1AB10LDU) Блокировка подъёма ББ2- есть сигнал общего сброса
	{&B1AB11LDU,1,246},	//(B1AB11LDU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
	{&B1AB12LDU,1,247},	//(B1AB12LDU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&B1AB13LDU,1,248},	//(B1AB13LDU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже значения заданного предупредительной уставкой
	{&B1AB14LDU,1,249},	//(B1AB14LDU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
	{&B1AB16LDU,1,250},	//(B1AB16LDU) Блокировка перемещения ББ2: выполняется программа 200 с
	{&B1AB17LDU,1,251},	//(B1AB17LDU) Блокировка перемещения ББ2: выполняется программа 20 мин
	{&B1AB18LDU,1,252},	//(B1AB18LDU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
	{&A3VS12LDU,1,253},	//(A3VS12LDU) Движение ИС1 в сторону ВУ
	{&A3AB04LDU,1,254},	//(A3AB04LDU) Блокировка движения ИС1 нет перемещения  ИС1
	{&A3AB02LDU,1,255},	//(A3AB02LDU) Блокировка движения ИС1: превышение заданной скорости
	{&A3AB01LDU,1,256},	//(A3AB01LDU) Блокировка движения ИС1: скорость перемещения менее заданной
	{&A2AB14LDU,1,257},	//(A2AB14LDU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
	{&A2AB13LDU,1,258},	//(A2AB13LDU) Блокировка подъёма РБ1- давление в пневмосистеме РБ ниже значения заданного предупредительной уставкой
	{&A2AB12LDU,1,259},	//(A2AB12LDU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&A2AB11LDU,1,260},	//(A2AB11LDU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
	{&A2AB10LDU,1,261},	//(A2AB10LDU) Блокировка подъёма РБ1- есть сигнал общего сброса
	{&A2AB09LDU,1,262},	//(A2AB09LDU) Блокировка подъёма РБ1- АНИ не установлен
	{&A2AB06LDU,1,263},	//(A2AB06LDU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
	{&A2AB05LDU,1,264},	//(A2AB05LDU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
	{&A2AB08LDU,1,265},	//(A2AB08LDU) Блокировка подъёма РБ1 - реактор не на рабочем месте
	{&A2AB07LDU,1,266},	//(A2AB07LDU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
	{&A2AZ03LDU,1,267},	//(A2AZ03LDU) Несанкционированное перемещение РБ1
	{&A2VS21LDU,1,268},	//(A2VS21LDU) Движение РБ1 в сторону НУ
	{&A2AB01LDU,1,269},	//(A2AB01LDU) Блокировка движения РБ1: скорость перемещения менее заданной
	{&A2AB02LDU,1,270},	//(A2AB02LDU) Блокировка движения РБ1: превышение заданной скорости
	{&A2AB04LDU,1,271},	//(A2AB04LDU) Блокировка движения РБ1 нет перемещения  РБ1
	{&A8AB05LDU,1,272},	//(A8AB05LDU) Блокировка движения ДС2: скорость перемещения менее заданной
	{&A8VS22LDU,1,273},	//(A8VS22LDU) Движение ДС2 в сторону НУ
	{&A8AZ03LDU,1,274},	//(A8AZ03LDU) Несанкционированное перемещение ДС2
	{&A8AB04LDU,1,275},	//(A8AB04LDU) Блокировка ДС2 -Ошибка в направлении  движения
	{&A8AB08LDU,1,276},	//(A8AB08LDU) Блокировка движения ДС2 Гомогенные двери не закрыты
	{&A8AB09LDU,1,277},	//(A8AB09LDU) Блокировка  - ДС2 по мощности от любого канала
	{&A8AB10LDU,1,278},	//(A8AB10LDU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
	{&A8AB11LDU,1,279},	//(A8AB11LDU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
	{&A8AB12LDU,1,280},	//(A8AB12LDU) Блокировка движения ДС2 - НИ не в положении ВУ
	{&A8AB13LDU,1,281},	//(A8AB13LDU) Блокировка движения ДС2 - ОРР не в исходном состоянии
	{&A8AB14LDU,1,282},	//(A8AB14LDU) Блокировка движения ДС2 - Самоход любого механизма
	{&A8AB02LDU,1,283},	//(A8AB02LDU) Блокировка движения ДС2- АНИ не установлен
	{&A8AB01LDU,1,284},	//(A8AB01LDU) Блокировка ДС2 -Превышение времени перемещения
	{&A2VS11LDU,1,285},	//(A2VS11LDU) Движение РБ1 в сторону ВУ
	{&R2AB04LDU,1,286},	//(R2AB04LDU) Блокировка МДЗ2 -Ошибка в направлении  движения
	{&R1AB04LDU,1,287},	//(R1AB04LDU) Блокировка МДЗ1 -Ошибка в направлении  движения
	{&R2AB02LDU,1,288},	//(R2AB02LDU) Блокировка МДЗ2 - Нет перемещения
	{&R2AB01LDU,1,289},	//(R2AB01LDU) Блокировка движения МДЗ2 - Превышение времени движения
	{&R2AZ03LDU,1,290},	//(R2AZ03LDU) Несанкционированное перемещение МДЗ2
	{&R1AB02LDU,1,291},	//(R1AB02LDU) Блокировка МДЗ1 - Нет перемещения
	{&R1AB01LDU,1,292},	//(R1AB01LDU) Блокировка движения МДЗ1 - Превышение времени движения
	{&R1AZ03LDU,1,293},	//(R1AZ03LDU) Несанкционированное перемещение МДЗ1
	{&B2AB17LDU,1,294},	//(B2AB17LDU) Блокировка перемещения РБ2: выполняется программа 20 мин
	{&B2AB16LDU,1,295},	//(B2AB16LDU) Блокировка перемещения РБ2: выполняется программа 200 с
	{&B2AB14LDU,1,296},	//(B2AB14LDU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
	{&B2AB13LDU,1,297},	//(B2AB13LDU) Блокировка подъёма РБ2- давление в пневмосистеме РБ ниже значения заданного предупредительной уставкой
	{&A2AB16LDU,1,298},	//(A2AB16LDU) Блокировка перемещения РБ1: выполняется программа 200 с
	{&A2AB17LDU,1,299},	//(A2AB17LDU) Блокировка перемещения РБ1: выполняется программа 20 мин
	{&B2AB04LDU,1,300},	//(B2AB04LDU) Блокировка движения РБ2 нет перемещения  РБ2
	{&B2AB02LDU,1,301},	//(B2AB02LDU) Блокировка движения РБ2: превышение заданной скорости
	{&B2AB01LDU,1,302},	//(B2AB01LDU) Блокировка движения РБ2: скорость перемещения менее заданной
	{&B2AZ03LDU,1,303},	//(B2AZ03LDU) Несанкционированное перемещение РБ2
	{&B2AB07LDU,1,304},	//(B2AB07LDU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
	{&B2AB08LDU,1,305},	//(B2AB08LDU) Блокировка подъёма РБ2 - реактор не на рабочем месте
	{&B2AB05LDU,1,306},	//(B2AB05LDU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
	{&B2AB06LDU,1,307},	//(B2AB06LDU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
	{&B2AB09LDU,1,308},	//(B2AB09LDU) Блокировка подъёма РБ2- АНИ не установлен
	{&B2AB10LDU,1,309},	//(B2AB10LDU) Блокировка подъёма РБ2- есть сигнал общего сброса
	{&B2AB11LDU,1,310},	//(B2AB11LDU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
	{&B2AB12LDU,1,311},	//(B2AB12LDU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DU[]={  // 
	{&R0VX08IDU,3,0},	//(R0VX08IDU) Индикация Режим
	{&R1VS01IDU,3,1},	//(R1VS01IDU) Готовность к управлению МДЗ1
	{&R2VS01IDU,3,2},	//(R2VS01IDU) Готовность к управлению МДЗ2
	{&R5VS01IDU,3,3},	//(R5VS01IDU) Готовность к управлению ворот отстойной зоны
	{&R0VL01RDU,8,4},	//(R0VL01RDU) Индикация Время задержки
	{&B2VS01IDU,3,6},	//(B2VS01IDU) Готовность к управлению РБ2
	{&B3CV02RDU,8,7},	//(B3CV02RDU) Заданная скорость перемещения ИС2
	{&B3CV01RDU,8,9},	//(B3CV01RDU) Измеренная скорость перемещения ИС2
	{&R4VS01IDU,3,11},	//(R4VS01IDU) Готовность к управлению тележкой реактора
	{&A6VS01IDU,3,12},	//(A6VS01IDU) Готовность к управлению БЗ1
	{&B5VS01IDU,3,13},	//(B5VS01IDU) Готовность к управлению НЛ2
	{&A5VS01IDU,3,14},	//(A5VS01IDU) Готовность к управлению НЛ1
	{&B4VS01IDU,3,15},	//(B4VS01IDU) Готовность к управлению НИ2
	{&A4VS01IDU,3,16},	//(A4VS01IDU) Готовность к управлению НИ1
	{&A2VS01IDU,3,17},	//(A2VS01IDU) Готовность к управлению РБ1
	{&B3VS01IDU,3,18},	//(B3VS01IDU) Готовность к управлению ИС2
	{&A3VS01IDU,3,19},	//(A3VS01IDU) Готовность к управлению ИС1
	{&R0VL01IDU,3,20},	//(R0VL01IDU) До импульса минут
	{&R0VL11IDU,3,21},	//(R0VL11IDU) До импульса секунд
	{&R0VL06RDU,8,22},	//(R0VL06RDU) Индикация (Время задержки от ВУ РБ)
	{&R0VL02RDU,8,24},	//(R0VL02RDU) Индикация (Время задержки ИНИ)
	{&R0VL04RDU,8,26},	//(R0VL04RDU) Индикация (Время срабатывания верхней АС II УР)
	{&R0VL03RDU,8,28},	//(R0VL03RDU) Индикация (Время срабатывания АЗ от ВУ ИС)
	{&R0VL05RDU,8,30},	//(R0VL05RDU) Индикация (Время срабатывания АЗ от НУП ИС)
	{&R0VL21IDU,3,32},	//(R0VL21IDU) Декатрон
	{&R0VS21IDU,3,33},	//(R0VS21IDU) Индикация ВИД ПРОВЕРКИ
	{&A1VS01IDU,3,34},	//(A1VS01IDU) Готовность к управлению ББ1
	{&B1VS01IDU,3,35},	//(B1VS01IDU) Готовность к управлению ББ2
	{&A1VC01RDU,8,36},	//(A1VC01RDU) Координата ББ1, мм
	{&A8VC01RDU,8,38},	//(A8VC01RDU) Координата ДС2, мм
	{&B3VC01RDU,8,40},	//(B3VC01RDU) Координата ИС2, мм
	{&B1VC01RDU,8,42},	//(B1VC01RDU) Координата ББ2, мм
	{&R0CN95LDU,3,44},	//(R0CN95LDU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
	{&R0CN94LDU,8,45},	//(R0CN94LDU) Скорость изменения мощности
	{&R0CN93LDU,8,47},	//(R0CN93LDU) время работы на мощности более 100Вт, сек
	{&R0VN12RDU,8,49},	//(R0VN12RDU) Заданная мощность РУ
	{&R0VN11RDU,8,51},	//(R0VN11RDU) Текущая мощность РУ
	{&R0CN92LDU,8,53},	//(R0CN92LDU) Рассчётный коэффициент  опережения старта ИМ
	{&A3MC03RDU,8,55},	//(A3MC03RDU) Координата положения ИМ 0-й реактивности
	{&R0CN91LDU,8,57},	//(R0CN91LDU) Рассчётная реактивность от регулятора
	{&A3MC02RDU,8,59},	//(A3MC02RDU) Температурная корректировка координаты ИМ
	{&A3MC01RDU,8,61},	//(A3MC01RDU) Заданная координата положения ИС от регулятора мм
	{&B8VC01RDU,8,63},	//(B8VC01RDU) Координата АЗ2, мм
	{&B2VC01RDU,8,65},	//(B2VC01RDU) Координата РБ2, мм
	{&A2VC01RDU,8,67},	//(A2VC01RDU) Координата РБ1, мм
	{&A3VC01RDU,8,69},	//(A3VC01RDU) Координата ИС1, мм
	{&A3CP02RDU,8,71},	//(A3CP02RDU) Текущее давление ВЫСТРЕЛ ИС1
	{&B3CP02RDU,8,73},	//(B3CP02RDU) Текущее давление ВЫСТРЕЛ ИС2
	{&R3VS32IDU,3,75},	//(R3VS32IDU) Готовность к управлению гомогенных дверей-2
	{&B6VS01IDU,3,76},	//(B6VS01IDU) Готовность к управлению БЗ2
	{&R3VS30IDU,3,77},	//(R3VS30IDU) Готовность к управлению гомогенных дверей-1
	{&B8VS01IDU,3,78},	//(B8VS01IDU) Готовность к управлению АЗ2
	{&A8VS01IDU,3,79},	//(A8VS01IDU) Готовность к управлению ДС2
	{&A8CV01RDU,8,80},	//(A8CV01RDU) Измеренная скорость перемещения ДС2
	{&B8CV01RDU,8,82},	//(B8CV01RDU) Измеренная скорость перемещения АЗ2
	{&B1CV02RDU,8,84},	//(B1CV02RDU) Заданная скорость перемещения ББ2
	{&B1CV01RDU,8,86},	//(B1CV01RDU) Измеренная скорость перемещения ББ2
	{&A1CV02RDU,8,88},	//(A1CV02RDU) Заданная скорость перемещения ББ1
	{&A1CV01RDU,8,90},	//(A1CV01RDU) Измеренная скорость перемещения ББ1
	{&A3CV02RDU,8,92},	//(A3CV02RDU) Заданная скорость перемещения ИС1
	{&A3CV01RDU,8,94},	//(A3CV01RDU) Измеренная скорость перемещения ИС1
	{&A2CV01RDU,8,96},	//(A2CV01RDU) Измеренная скорость перемещения РБ1
	{&A2CV02RDU,8,98},	//(A2CV02RDU) Заданная скорость перемещения РБ1
	{&B2CV01RDU,8,100},	//(B2CV01RDU) Измеренная скорость перемещения РБ2
	{&B2CV02RDU,8,102},	//(B2CV02RDU) Заданная скорость перемещения РБ2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DU[]={  // 
	{&R0MW12IP2,3,0},	//(R0MW12IP2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
	{&R0MW14IP2,3,1},	//(R0MW14IP2) Переключатель «Обдув»
	{&A1MC01RP1,8,2},	//(A1MC01RP1) Заданная координата положения ББ1 мм
	{&B1MC01RP1,8,4},	//(B1MC01RP1) Заданная координата положения ББ2  мм
	{&A3MC01RP1,8,6},	//(A3MC01RP1) Заданная координата положения ИС1 мм
	{&B3MC01RP1,8,8},	//(B3MC01RP1) Заданная координата положения ИС2 мм
	{&B8MC01RP2,8,10},	//(B8MC01RP2) Заданная координата АЗ2 мм
	{&R0MW11IP2,3,12},	//(R0MW11IP2) Переключатель «ПРОВЕРКА СХЕМ СБРОСА»
	{&R0MW11IP1,3,13},	//(R0MW11IP1) Переключатель «ВЫСТРЕЛ»
	{&R0MW16IP1,3,14},	//(R0MW16IP1) Переключатель «ВИД ПРОВЕРКИ»
	{&R0MW13IP1,3,15},	//(R0MW13IP1) Переключатель «ВЫБОР ЗОН»
	{&R0MW12IP1,3,16},	//(R0MW12IP1) Переключатель «РЕЖИМ РАБОТЫ»
	{&R0MW14IP1,3,17},	//(R0MW14IP1) Переключатель «ПРОГРАММЫ»
	{&R0MW15IP1,3,18},	//(R0MW15IP1) Переключатель «МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ»
	{&fEM_R0UL02RDU,8,19},	//(R0UL02RDU) Время задержки  ИНИ
	{&fEM_R3UZ03RDU,8,21},	//(R3UZ03RDU) Время задержки блокировки гомогеннных дверей по самоходу сек
	{&fEM_R3UL10RDU,8,23},	//(R3UL10RDU) Время полного хода гомогенных дверей сек
	{&fEM_R3UZ04RDU,8,25},	//(R3UZ04RDU) Время задержки блокировки гомогенных дверей по недвижению сек
	{&fEM_R0UN08RDU,8,27},	//(R0UN08RDU) Ограничение 8 по мощности
	{&fEM_R0UN07RDU,8,29},	//(R0UN07RDU) Ограничение 7 по мощности
	{&fEM_R0UN06RDU,8,31},	//(R0UN06RDU) Ограничение 6 по мощности
	{&fEM_R0UN05RDU,8,33},	//(R0UN05RDU) Ограничение 5 по мощности
	{&fEM_R0UN04RDU,8,35},	//(R0UN04RDU) Ограничение 4 по мощности
	{&fEM_R0UN03RDU,8,37},	//(R0UN03RDU) Ограничение 3 по мощности
	{&fEM_R0UN02RDU,8,39},	//(R0UN02RDU) Ограничение 2 по мощности
	{&fEM_R0UN01RDU,8,41},	//(R0UN01RDU) Ограничение 1 по мощности
	{&fEM_A2UC82RDU,8,43},	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
	{&fEM_A2UC83RDU,8,45},	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
	{&fEM_A1UC83RDU,8,47},	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
	{&fEM_A2UC81RDU,8,49},	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
	{&fEM_A1UC81RDU,8,51},	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
	{&fEM_A1UC82RDU,8,53},	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
	{&fEM_A2UL83RDU,8,55},	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{&fEM_A3UC81RDU,8,57},	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
	{&fEM_A3UC82RDU,8,59},	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
	{&fEM_A5UZ05RDU,8,61},	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
	{&fEM_A4UZ03RDU,8,63},	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
	{&fEM_A4UZ04RDU,8,65},	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
	{&fEM_A4UZ05RDU,8,67},	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
	{&fEM_A6UZ03RDU,8,69},	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
	{&fEM_A6UZ04RDU,8,71},	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
	{&fEM_A6UZ05RDU,8,73},	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
	{&fEM_R1UZ03RDU,8,75},	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
	{&fEM_R1UZ04RDU,8,77},	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
	{&fEM_R1UZ05RDU,8,79},	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
	{&fEM_R5UL10RDU,8,81},	//(R5UL10RDU) Время полного хода ворот отстойной зоны сек
	{&fEM_R5UZ03RDU,8,83},	//(R5UZ03RDU) Время задержки блокировки ворот отстойной зоны по самоходу сек
	{&fEM_R5UZ04RDU,8,85},	//(R5UZ04RDU) Время задержки блокировки ворот отстойной зоны по недвижению сек
	{&fEM_R0UL04RDU,8,87},	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
	{&fEM_R0UL06RDU,8,89},	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
	{&fEM_R0UL03RDU,8,91},	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
	{&fEM_R0UL17RDU,8,93},	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
	{&fEM_R0UL19RDU,8,95},	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{&fEM_R0UL07RDU,8,97},	//(R0UL07RDU) Время срабатывания верхней АС II УР
	{&fEM_R0UL18RDU,8,99},	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
	{&fEM_R0UL16RDU,8,101},	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
	{&fEM_R0UN17RDU,8,103},	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
	{&fEM_R0UN18RDU,8,105},	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
	{&fEM_R0UN19RDU,8,107},	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
	{&fEM_R0UN70LDU,8,109},	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_R0UN71LDU,8,111},	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_R0UN72LDU,8,113},	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_R0UN73LDU,8,115},	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_R0UN74LDU,8,117},	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_R0UN75LDU,8,119},	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_R0UN80LDU,8,121},	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
	{&fEM_R0UN81LDU,8,123},	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
	{&fEM_R0UN82LDU,8,125},	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
	{&fEM_R0UN83LDU,8,127},	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
	{&fEM_R0UN84LDU,8,129},	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
	{&fEM_R0UN85LDU,8,131},	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
	{&fEM_R0UT20RDU,8,133},	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
	{&fEM_R0UN25RDU,8,135},	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
	{&fEM_R0UN15RDU,8,137},	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
	{&fEM_R0UN26RDU,8,139},	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
	{&fEM_R0UN27RDU,8,141},	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
	{&fEM_R0UN24RDU,8,143},	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
	{&fEM_R0UN80RDU,8,145},	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
	{&fEM_A3UP34RDU,8,147},	//(A3UP34RDU) Время заполнения ресивера ИС (в 10 мс)
	{&iEM_A2UV01IDU,3,149},	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
	{&iEM_A2UV02IDU,3,150},	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
	{&iEM_A1UV01IDU,3,151},	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
	{&iEM_A1UV02IDU,3,152},	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
	{&iEM_A1UV03IDU,3,153},	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
	{&iEM_A3UV01IDU,3,154},	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
	{&iEM_A3UV02IDU,3,155},	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
	{&fEM_A3UC09RDU,8,156},	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
	{&fEM_A2UC02RDU,8,158},	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
	{&fEM_A1UC02RDU,8,160},	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
	{&fEM_A3UC02RDU,8,162},	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
	{&fEM_R0UL21RDU,8,164},	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
	{&fEM_R0UN09RDU,8,166},	//(R0UN09RDU) Минимальный период при регулировании мощности
	{&fEM_R0UN11RDU,8,168},	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
	{&fEM_R0UN12RDU,8,170},	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
	{&fEM_R0UN13RDU,8,172},	//(R0UN13RDU) Минимальное изменение координаты, мм
	{&fEM_R0UN14RDU,8,174},	//(R0UN14RDU) Максимальная координата штока ИМ, мм
	{&fEM_R0UN16RDU,8,176},	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
	{&fEM_A3UP43RDU,8,178},	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
	{&fEM_A3UP44RDU,8,180},	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
	{&fEM_A3UP53RDU,8,182},	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
	{&fEM_A3UP85RDU,8,184},	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{&fEM_A3UP88RDU,8,186},	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{&fEM_A3UP86RDU,8,188},	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{&fEM_B8UV01RDU,8,190},	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
	{&fEM_B8UV02RDU,8,192},	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
	{&fEM_B8UV03RDU,8,194},	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
	{&fEM_B8UL04RDU,8,196},	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
	{&iEM_A2UV03CDU,3,198},	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
	{&fEM_A2UV01RDU,8,199},	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
	{&fEM_A2UV02RDU,8,201},	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
	{&fEM_A1UV01RDU,8,203},	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
	{&fEM_A1UV02RDU,8,205},	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
	{&fEM_A1UC06RDU,8,207},	//(A1UC06RDU) Уставка определения самохода ББ  мм
	{&fEM_A1UC05RDU,8,209},	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
	{&fEM_A1UL04RDU,8,211},	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
	{&fEM_A3UV01RDU,8,213},	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
	{&fEM_A3UV02RDU,8,215},	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
	{&fEM_A3UC06RDU,8,217},	//(A3UC06RDU) Уставка определения самохода ИС1  мм
	{&fEM_A1UC03RDU,8,219},	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
	{&dEM_A1UC05UDU,5,221},	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
	{&dEM_A1UC06UDU,5,223},	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
	{&dEM_A2UC06UDU,5,225},	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
	{&dEM_A2UC05UDU,5,227},	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
	{&fEM_A2UC03RDU,8,229},	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
	{&dEM_A3UC06UDU,5,231},	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
	{&dEM_A3UC05UDU,5,233},	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
	{&fEM_A3UC03RDU,8,235},	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
	{&dEM_A8UC06UDU,5,237},	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
	{&fEM_A8UC03RDU,8,239},	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
	{&dEM_A8UC05UDU,5,241},	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
	{&fEM_R0UV81RDU,8,243},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{&fEM_R0UV82RDU,8,245},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{&fEM_R0UV83RDU,8,247},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{&fEM_R0UV84RDU,8,249},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{&fEM_R0UV86RDU,8,251},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UV85RDU,8,253},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UV87RDU,8,255},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{&fEM_A3UP03RDU,8,257},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{&fEM_A3UP04RDU,8,259},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{&fEM_A1UL01RDU,8,261},	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{&fEM_A3UC07RDU,8,263},	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
	{&fEM_A3UL01RDU,8,265},	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{&fEM_A2UC08RDU,8,267},	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
	{&fEM_A2UC07RDU,8,269},	//(A2UC07RDU) Зона возврата при наведении РБ  мм
	{&fEM_A2UL01RDU,8,271},	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{&fEM_B8UC01RDU,8,273},	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
	{&fEM_B8UL07RDU,8,275},	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
	{&fEM_B8UC02RDU,8,277},	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
	{&fEM_B8UL01RDU,8,279},	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{&fEM_B8UL05RDU,8,281},	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
	{&fEM_B8UL03RDU,8,283},	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
	{&fEM_B8UL06RDU,8,285},	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
	{&fEM_A9UZ03RDU,8,287},	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
	{&fEM_A9UZ04RDU,8,289},	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
	{&fEM_A9UZ05RDU,8,291},	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
	{&fEM_R4UZ04RDU,8,293},	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
	{&fEM_R4UZ03RDU,8,295},	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
	{&fEM_R4UZ05RDU,8,297},	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
	{&fEM_A5UZ03RDU,8,299},	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
	{&fEM_A5UZ04RDU,8,301},	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
	{&fEM_A3UC05RDU,8,303},	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
	{&fEM_A3UL04RDU,8,305},	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
	{&fEM_A3UP54RDU,8,307},	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
	{&fEM_A3UP87RDU,8,309},	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{&fEM_R0UL05RDU,8,311},	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
	{&fEM_R0UL20RDU,8,313},	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
	{&fEM_B8UV04RDU,8,315},	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
	{&fEM_B8UC06RDU,8,317},	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
	{&fEM_B8UC05RDU,8,319},	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
	{&fEM_A2UL05RDU,8,321},	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
	{&fEM_A2UL03RDU,8,323},	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{&fEM_A2UC06RDU,8,325},	//(A2UC06RDU) Уставка определения самохода РБ  мм
	{&fEM_A2UC05RDU,8,327},	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
	{&fEM_A2UL04RDU,8,329},	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
	{&fEM_A1UL03RDU,8,331},	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
	{&fEM_A1UL05RDU,8,333},	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
	{&fEM_A3UL03RDU,8,335},	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
	{&fEM_A3UL05RDU,8,337},	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
	{&fEM_A1UC08RDU,8,339},	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
	{&fEM_A3UC08RDU,8,341},	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
	{&fEM_A1UC07RDU,8,343},	//(A1UC07RDU) Зона возврата при наведении ББ мм
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_MDuBz1[]={  // 
	{&R0AD21LDU,1,0},	//(R0AD21LDU) Подключить защиту от II УР
	{&R0VW23LDU,1,1},	//(R0VW23LDU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,1,2},	//(R0VW13LDU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MDuBz1[]={  // 
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
static ModbusRegister ir_MDuBz1[]={  // 
	{&B0CT01IZ1,8,0},	//(B0CT01IZ1) Температура АЗ2-1
	{&R0VN11RZ1,8,2},	//(R0VN11RZ1) Средняя мощность по БАЗ1
	{&R0VN09RZ1,8,4},	//(R0VN09RZ1) Усредненный период разгона
	{&A0CT01IZ1,8,6},	//(A0CT01IZ1) Температура АЗ1-1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MDuBz1[]={  // 
	{NULL,0,0},
};
#pragma pop
static char MDuBz1_ip1[]={"192.168.10.52\0"};
static char MDuBz1_ip2[]={"192.168.10.152\0"};
#pragma pack(push,1)
static ModbusRegister coil_MDuBz2[]={  // 
	{&R0AD21LDU,1,0},	//(R0AD21LDU) Подключить защиту от II УР
	{&R0VW23LDU,1,1},	//(R0VW23LDU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,1,2},	//(R0VW13LDU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MDuBz2[]={  // 
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
static ModbusRegister ir_MDuBz2[]={  // 
	{&B0CT01IZ2,8,0},	//(B0CT01IZ2) Температура АЗ2-1
	{&R0VN11RZ2,8,2},	//(R0VN11RZ2) Средняя мощность по БАЗ1
	{&R0VN09RZ2,8,4},	//(R0VN09RZ2) Усредненный период разгона
	{&A0CT01IZ2,8,6},	//(A0CT01IZ2) Температура АЗ1-1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MDuBz2[]={  // 
	{NULL,0,0},
};
#pragma pop
static char MDuBz2_ip1[]={"192.168.10.54\0"};
static char MDuBz2_ip2[]={"192.168.10.154\0"};
#pragma pack(push,1)
static ModbusRegister coil_MDuS[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MDuS[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MDuS[]={  // 
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
static ModbusRegister hr_MDuS[]={  // 
	{NULL,0,0},
};
#pragma pop
static char MDuS_ip1[]={"192.168.10.60\0"};
static char MDuS_ip2[]={"192.168.10.60\0"};
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,502,&coil_DU[0],&di_DU[0],&ir_DU[0],&hr_DU[0],NULL,NULL,NULL,0},	 //Общий слэйв
	{1,503,&coil_MDuBz1[0],&di_MDuBz1[0],&ir_MDuBz1[0],&hr_MDuBz1[0],NULL,MDuBz1_ip1,MDuBz1_ip2,100},	 //Мастер ДУ в Баз1
	{1,504,&coil_MDuBz2[0],&di_MDuBz2[0],&ir_MDuBz2[0],&hr_MDuBz2[0],NULL,MDuBz2_ip1,MDuBz2_ip2,100},	 //Мастер ДУ в Баз2
	{1,505,&coil_MDuS[0],&di_MDuS[0],&ir_MDuS[0],&hr_MDuS[0],NULL,MDuS_ip1,MDuS_ip2,100},	 //Мастер ДУ в SCM

	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},};
#pragma pop
#include <fp8/drivers/vencf8l.h>
static char buf_VENCF[84];	//VENCF
static vencf8_inipar ini_VENCF={0xc2,0xff,0,0x6,0x04,};
#pragma pack(push,1)
static table_drv table_VENCF={0,0,&ini_VENCF,buf_VENCF,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VENCF[]={
	{&gray01,4,0},
	{&gray02,4,5},
	{&gray03,4,10},
	{&gray04,4,15},
	{&gray05,4,20},
	{&gray06,4,25},
	{&gray07,4,30},
	{&gray08,4,35},
	{&venc01,5,40},
	{&venc02,5,45},
	{&venc03,5,50},
	{&venc04,5,55},
	{&venc05,5,60},
	{&venc06,5,65},
	{&venc07,5,70},
	{&venc08,5,75},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3202[64];	//VDS32-02
static vds32r_inipar ini_VDS3202={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3202={0,0,&ini_VDS3202,buf_VDS3202,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3202[]={
	{&B9IS21LDU,1,50},
	{&B9IS11LDU,1,48},
	{&A9IS21LDU,1,46},
	{&R2IS11LDU,1,56},
	{&A3VZ15LZ1,1,36},
	{&B4IS11LDU,1,60},
	{&A3VZ13LZ1,1,34},
	{&R2IS21LDU,1,58},
	{&R1IS21LDU,1,54},
	{&R0AD14LZ1,1,38},
	{&A1VN71LZ1,1,40},
	{&B2IS11LDU,1,20},
	{&R0VZ71LZ1,1,42},
	{&B7AS31LDU,1,10},
	{&B3IS33LDU,1,2},
	{&B3IS35LDU,1,0},
	{&B8IS22LDU,1,30},
	{&B2IS12LDU,1,18},
	{&B1IS12LDU,1,12},
	{&B4IS10LDU,1,6},
	{&A9IS11LDU,1,44},
	{&R8IS11LDU,1,26},
	{&R1IS11LDU,1,52},
	{&B3IS21LDU,1,24},
	{&B2IS21LDU,1,22},
	{&B1IS11LDU,1,14},
	{&B1IS21LDU,1,16},
	{&B2IS33LDU,1,4},
	{&B8IS12LDU,1,28},
	{&B3IS31LDU,1,8},
	{&B4IS21LDU,1,62},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3203[64];	//VDS32-03
static vds32r_inipar ini_VDS3203={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3203={0,0,&ini_VDS3203,buf_VDS3203,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3203[]={
	{&R0VZ71LZ2,1,42},
	{&A2IS33LDU,1,4},
	{&A3IS31LDU,1,8},
	{&A3IS33LDU,1,2},
	{&A3IS35LDU,1,0},
	{&A4IS10LDU,1,6},
	{&B3VP81LDU,1,50},
	{&A3VP81LDU,1,44},
	{&B2VP82LDU,1,52},
	{&A2VP82LDU,1,46},
	{&B4VP82LDU,1,54},
	{&A4VP82LDU,1,48},
	{&A1IS11LDU,1,14},
	{&R0IS01LDU,1,56},
	{&A2IS11LDU,1,20},
	{&R0IS02LDU,1,58},
	{&A1VN71LZ2,1,40},
	{&A7AS31LDU,1,10},
	{&R0AD14LZ2,1,38},
	{&A3VZ13LZ2,1,34},
	{&A3VZ15LZ2,1,36},
	{&A2IS12LDU,1,18},
	{&A4IS21LDU,1,28},
	{&A1IS12LDU,1,12},
	{&A4IS11LDU,1,26},
	{&A1IS21LDU,1,16},
	{&A2IS21LDU,1,22},
	{&A3IS21LDU,1,24},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3204[64];	//VDS32-04
static vds32r_inipar ini_VDS3204={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3204={0,0,&ini_VDS3204,buf_VDS3204,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3204[]={
	{&A8IS22LDU,1,60},
	{&A8IS12LDU,1,58},
	{&R3AD10LDU,1,40},
	{&R3AD20LDU,1,44},
	{&R3IS11LDU,1,32},
	{&R3IS21LDU,1,34},
	{&R5AD10LDU,1,52},
	{&R5AD20LDU,1,54},
	{&R5IS21LDU,1,50},
	{&B3IS11LDU,1,4},
	{&B5IS21LDU,1,30},
	{&R4IS11LDU,1,8},
	{&A3IS11LDU,1,0},
	{&B6IS21LDU,1,26},
	{&R3IS31LDU,1,36},
	{&R3IS41LDU,1,38},
	{&R3AD21LDU,1,46},
	{&R3AD11LDU,1,42},
	{&R6IS21LDU,1,56},
	{&A6IS11LDU,1,16},
	{&A6IS21LDU,1,18},
	{&B6IS11LDU,1,24},
	{&R5IS11LDU,1,48},
	{&R4IS12LDU,1,10},
	{&R4IS22LDU,1,14},
	{&R4IS21LDU,1,12},
	{&B5IS11LDU,1,28},
	{&A5IS21LDU,1,22},
	{&A5IS11LDU,1,20},
	{&A3IS22LDU,1,2},
	{&B3IS22LDU,1,6},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3205[64];	//VDS32-05
static vds32r_inipar ini_VDS3205={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3205={0,0,&ini_VDS3205,buf_VDS3205,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3205[]={
	{&R6IS41LDU,1,52},
	{&R6IS42LDU,1,54},
	{&R6IS32LDU,1,50},
	{&R6IS31LDU,1,48},
	{&B2IE02LDU,1,32},
	{&B3IE02LDU,1,40},
	{&B1IE02LDU,1,24},
	{&A1IE01LDU,1,2},
	{&A3IE01LDU,1,18},
	{&A2IE01LDU,1,10},
	{&A1IE02LDU,1,0},
	{&A3IE02LDU,1,16},
	{&A2IE02LDU,1,8},
	{&B1IE01LDU,1,26},
	{&B2IE01LDU,1,34},
	{&B3IE01LDU,1,42},
	{&B2IE03LDU,1,36},
	{&B2IE04LDU,1,38},
	{&B3IE03LDU,1,44},
	{&B1IE04LDU,1,30},
	{&B3IE04LDU,1,46},
	{&B1IE03LDU,1,28},
	{&A3IE04LDU,1,22},
	{&A3IE03LDU,1,20},
	{&A2IE04LDU,1,14},
	{&A2IE03LDU,1,12},
	{&A1IE04LDU,1,6},
	{&A1IE03LDU,1,4},
	{&R6IS52LDU,1,58},
	{&R6IS51LDU,1,56},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS1607[38];	//FDS16-07
static fds16r_inipar ini_FDS1607={0x04,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1607={0,0,&ini_FDS1607,buf_FDS1607,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1607[]={
	{&B2AD01LDU,1,18},
	{&B2AD05LDU,1,26},
	{&A2AD05LDU,1,12},
	{&A2AD04LDU,1,10},
	{&A2AD03LDU,1,8},
	{&A2AD02LDU,1,6},
	{&A2AD21LDU,1,2},
	{&A2AD01LDU,1,4},
	{&B2AD04LDU,1,24},
	{&A2AD11LDU,1,0},
	{&A2IS12LZ2,1,28},
	{&B2IS12LZ2,1,30},
	{&B2AD03LDU,1,22},
	{&B2AD02LDU,1,20},
	{&B2AD21LDU,1,16},
	{&B2AD11LDU,1,14},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS1608[38];	//FDS16-08
static fds16r_inipar ini_FDS1608={0x04,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1608={0,0,&ini_FDS1608,buf_FDS1608,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1608[]={
	{&A1AD03LDU,1,8},
	{&A1AD02LDU,1,6},
	{&A1AD04LDU,1,10},
	{&A1AD05LDU,1,12},
	{&A1AD01LDU,1,4},
	{&A1AD21LDU,1,2},
	{&A1AD11LDU,1,0},
	{&B1AD21LDU,1,16},
	{&B1AD11LDU,1,14},
	{&B1AD04LDU,1,24},
	{&B1AD03LDU,1,22},
	{&B1AD02LDU,1,20},
	{&B1AD05LDU,1,26},
	{&B1AD01LDU,1,18},
	{&B2IS12LZ1,1,30},
	{&A2IS12LZ1,1,28},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS1609[38];	//FDS16-09
static fds16r_inipar ini_FDS1609={0x04,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1609={0,0,&ini_FDS1609,buf_FDS1609,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1609[]={
	{&B6AD20LDU,1,22},
	{&B6AD10LDU,1,20},
	{&A6AD20LDU,1,18},
	{&A6AD10LDU,1,16},
	{&A8AD20LDU,1,14},
	{&A8AD10LDU,1,12},
	{&B4AD10LDU,1,6},
	{&B3AD33LDU,1,2},
	{&B8AD20LDU,1,30},
	{&B8AD10LDU,1,28},
	{&B7AP31LDU,1,10},
	{&B2AD33LDU,1,4},
	{&R4AD10LDU,1,24},
	{&R4AD20LDU,1,26},
	{&B3AD34LDU,1,0},
	{&B3AD31LDU,1,8},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS1610[38];	//FDS16-10
static fds16r_inipar ini_FDS1610={0x04,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1610={0,0,&ini_FDS1610,buf_FDS1610,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1610[]={
	{&B5AD10LDU,1,24},
	{&B5AD20LDU,1,26},
	{&A5AD10LDU,1,20},
	{&A5AD20LDU,1,22},
	{&A4AD10LDU,1,6},
	{&R1AD10LDU,1,12},
	{&A7AP31LDU,1,10},
	{&R1AD20LDU,1,14},
	{&R2AD20LDU,1,18},
	{&A2AD33LDU,1,4},
	{&R2AD10LDU,1,16},
	{&A3AD33LDU,1,2},
	{&A3AD34LDU,1,0},
	{&A3AD31LDU,1,8},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS1611[38];	//FDS16-11
static fds16r_inipar ini_FDS1611={0x04,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1611={0,0,&ini_FDS1611,buf_FDS1611,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1611[]={
	{&B3AD11LDU,1,14},
	{&B9AD10LDU,1,30},
	{&A9AD10LDU,1,28},
	{&B3AD21LDU,1,16},
	{&B3AD02LDU,1,20},
	{&B3AD03LDU,1,22},
	{&B3AD04LDU,1,24},
	{&B3AD05LDU,1,26},
	{&B3AD01LDU,1,18},
	{&A3AD01LDU,1,4},
	{&A3AD05LDU,1,12},
	{&A3AD04LDU,1,10},
	{&A3AD11LDU,1,0},
	{&A3AD21LDU,1,2},
	{&A3AD03LDU,1,8},
	{&A3AD02LDU,1,6},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vas84r.h>
static char buf_VAS8412[26];	//VAS84-12
static vas84r_inipar ini_VAS8412={172,255,1,8,0xff,0,16,};
#pragma pack(push,1)
static table_drv table_VAS8412={0,0,&ini_VAS8412,buf_VAS8412,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VAS8412[]={
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3213[64];	//VDS32-13
static vds32r_inipar ini_VDS3213={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3213={0,0,&ini_VDS3213,buf_VDS3213,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3213[]={
	{&A8IE01LDU,1,6},
	{&B5VS12LDU,1,26},
	{&B5VS22LDU,1,28},
	{&A5VS12LDU,1,20},
	{&A5VS22LDU,1,22},
	{&B5IE01LDU,1,30},
	{&A5IE02LDU,1,24},
	{&B6IE01LDU,1,42},
	{&R4VS22LDU,1,4},
	{&R4VS12LDU,1,2},
	{&R1IE01LDU,1,12},
	{&R2IE01LDU,1,18},
	{&R6IS61LDU,1,0},
	{&R1VS12LDU,1,8},
	{&R2VS12LDU,1,14},
	{&R2VS22LDU,1,16},
	{&R1VS22LDU,1,10},
	{&R6IS64LDU,1,52},
	{&R6IS65LDU,1,54},
	{&R6IS62LDU,1,48},
	{&R0IE02LDU,1,44},
	{&R0IE01LDU,1,46},
	{&A6IE01LDU,1,36},
	{&B6VS12LDU,1,38},
	{&B6VS22LDU,1,40},
	{&A6VS12LDU,1,32},
	{&A6VS22LDU,1,34},
	{&R6IS63LDU,1,50},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS1615[38];	//FDS16-15
static fds16r_inipar ini_FDS1615={0x04,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1615={0,0,&ini_FDS1615,buf_FDS1615,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1615[]={
	{&R0AD05LZ1,1,20},
	{&R8AD21LDU,1,22},
	{&R0AD04LZ2,1,28},
	{&R0AD04LZ1,1,18},
	{&A2AD31LDU,1,6},
	{&B2AD31LDU,1,14},
	{&A1AD31LDU,1,2},
	{&B1AD31LDU,1,10},
	{&A2AD32LDU,1,4},
	{&B2AD32LDU,1,12},
	{&A1AD32LDU,1,0},
	{&R0AD16LDU,1,24},
	{&B1AD32LDU,1,8},
	{&R0AD03LZ2,1,26},
	{&R0AD03LZ1,1,16},
	{&R0AD05LZ2,1,30},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0x02,0x01,5,84,def_buf_VENCF,&table_VENCF}, //VENCF
	{0xc2,0x02,15,64,def_buf_VDS3202,&table_VDS3202}, //VDS32-02
	{0xc2,0x03,15,64,def_buf_VDS3203,&table_VDS3203}, //VDS32-03
	{0xc2,0x04,15,64,def_buf_VDS3204,&table_VDS3204}, //VDS32-04
	{0xc2,0x05,15,64,def_buf_VDS3205,&table_VDS3205}, //VDS32-05
	{0x04,0x07,20,38,def_buf_FDS1607,&table_FDS1607}, //FDS16-07
	{0x04,0x08,20,38,def_buf_FDS1608,&table_FDS1608}, //FDS16-08
	{0x04,0x09,20,38,def_buf_FDS1609,&table_FDS1609}, //FDS16-09
	{0x04,0x0a,20,38,def_buf_FDS1610,&table_FDS1610}, //FDS16-10
	{0x04,0x0b,20,38,def_buf_FDS1611,&table_FDS1611}, //FDS16-11
	{0xc6,0x0c,7,26,def_buf_VAS8412,&table_VAS8412}, //VAS84-12
	{0xc2,0x0d,15,64,def_buf_VDS3213,&table_VDS3213}, //VDS32-13
	{0x04,0x0f,20,38,def_buf_FDS1615,&table_FDS1615}, //FDS16-15
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
	setAsFloat(743,0.0000976563);
	setAsInt(744,1024200);
	setAsInt(745,-200);
	setAsInt(746,-200);
	setAsInt(747,1024200);
	setAsFloat(748,0.0000976563);
	setAsInt(749,-200);
	setAsInt(750,1689599);
	setAsFloat(751,0.00009765625);
	setAsInt(752,-200);
	setAsFloat(753,0.0009765625);
	setAsInt(754,1536200);
	setAsFloat(755,100);
	setAsFloat(756,200);
	setAsFloat(757,300);
	setAsFloat(758,400);
	setAsFloat(759,600);
	setAsFloat(760,500);
	setAsFloat(761,750);
	setAsFloat(762,2.5);
	setAsFloat(763,0);
	setAsFloat(764,0.46);
	setAsFloat(765,0.49);
	setAsFloat(766,0.52);
	setAsFloat(767,0.53);
	setAsFloat(768,0.67);
	setAsFloat(769,0.56);
	setAsFloat(770,4);
	setAsFloat(771,4);
	setAsFloat(772,10.91);
	setAsFloat(773,3);
	setAsShort(774,4);
	setAsFloat(775,0.15);
	setAsFloat(776,0.15);
	setAsFloat(777,0.4);
	setAsFloat(778,0.4);
	setAsFloat(779,0.03);
	setAsFloat(780,0.04);
	setAsFloat(781,3);
	setAsFloat(782,0.3);
	setAsFloat(783,0.3);
	setAsFloat(784,0.07);
	setAsFloat(785,0.04);
	setAsFloat(786,3);
	setAsFloat(787,0.55);
	setAsFloat(788,0.64);
	setAsFloat(789,0.180);
	setAsFloat(790,0.025);
	setAsFloat(791,0.1);
	setAsFloat(792,2);
	setAsFloat(793,0.3);
	setAsFloat(794,3);
	setAsFloat(795,1.50);
	setAsFloat(796,0.04);
	setAsFloat(797,0.05);
	setAsFloat(798,3);
	setAsFloat(799,1.50);
	setAsFloat(800,3);
	setAsFloat(801,1.50);
	setAsFloat(802,2);
	setAsFloat(803,0.004);
	setAsFloat(804,0.006);
	setAsFloat(805,0.006);
	setAsFloat(806,1.0);
	setAsFloat(807,0.01);
	setAsFloat(808,1);
	setAsFloat(809,0.008);
	setAsFloat(810,0.01);
	setAsFloat(811,1);
	setAsFloat(812,0.4);
	setAsFloat(813,120);
	setAsFloat(814,0.6);
	setAsFloat(815,1);
	setAsFloat(816,2);
	setAsFloat(817,1.50);
	setAsFloat(818,2.0);
	setAsFloat(819,1);
	setAsFloat(820,15);
	setAsFloat(821,0.50);
	setAsFloat(822,360);
	setAsFloat(823,1);
	setAsFloat(824,2);
	setAsFloat(825,1.0);
	setAsFloat(826,6.0);
	setAsFloat(827,0.50);
	setAsFloat(828,1.0);
	setAsFloat(829,16.0);
	setAsFloat(830,3.0);
	setAsFloat(831,1.0);
	setAsFloat(832,60.0);
	setAsFloat(833,0.50);
	setAsFloat(834,1.0);
	setAsFloat(835,20.0);
	setAsFloat(836,0.50);
	setAsFloat(837,50.0);
	setAsFloat(838,1.0);
	setAsFloat(839,0.50);
	setAsFloat(840,2.0);
	setAsFloat(841,2.0);
	setAsFloat(842,1.5);
	setAsFloat(843,0.06);
	setAsFloat(844,0.01);
	setAsFloat(845,0.045);
	setAsFloat(846,0.040);
	setAsFloat(847,0.007);
	setAsFloat(848,0.014);
	setAsFloat(849,1.0);
	setAsFloat(850,40.0);
	setAsFloat(851,0.50);
	setAsFloat(852,2000.0);
	setAsFloat(853,1500.0);
	setAsFloat(854,1000.0);
	setAsFloat(855,800.0);
	setAsFloat(856,500.0);
	setAsFloat(857,200.0);
	setAsFloat(858,100.0);
	setAsFloat(859,0.0);
	setAsFloat(860,100);
	setAsFloat(861,100);
	setAsFloat(862,110.0);
	setAsFloat(863,20);
	setAsFloat(864,30.0);
	setAsFloat(865,100.0);
	setAsFloat(866,1.50);
	setAsFloat(867,170);
	setAsFloat(868,170);
	setAsFloat(869,10);
	setAsFloat(870,10.0);
	setAsShort(871,1);
	setAsShort(872,4);
	setAsShort(873,1);
	setAsShort(874,4);
	setAsShort(875,4);
	setAsShort(876,4);
	setAsShort(877,4);
	setAsBool(878,0);
	setAsFloat(879,159.99);
	setAsFloat(880,0.002375);
	setAsFloat(881,0.000877);
	setAsFloat(882,0.001675);
	setAsFloat(883,2.5);
	setAsFloat(884,30);
	setAsFloat(885,30);
	setAsFloat(886,0.05);
	setAsFloat(887,0.05);
	setAsFloat(888,160.0);
	setAsFloat(889,-170.11);
	setAsFloat(890,76.25088);
	setAsFloat(891,0.271145);
	setAsFloat(892,24.93556615);
	setAsFloat(893,0.1268);
	setAsFloat(894,0.1567);
	setAsFloat(895,0.1858);
	setAsFloat(896,0.2066);
	setAsFloat(897,0.2646);
	setAsFloat(898,0.2995);
	setAsFloat(899,0.721275);
	setAsFloat(900,0.700575);
	setAsFloat(901,0.6681);
	setAsFloat(902,0.61515);
	setAsFloat(903,0.3885);
	setAsFloat(904,0.23325);
	setAsFloat(905,3600.0);
	setAsFloat(906,0.935);
	setAsFloat(907,0.1);
	setAsFloat(908,0.006792308);
	setAsFloat(909,0.000418877);
	setAsFloat(910,0.0015);
}
/* Определение внутренних параметров */
uspaint8 InternalBuf[8691];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssint iRM_8_ = {8,0}; /* N-число входов */ 
sslong dRM_16777215_ = {16777215,0}; /*  */ 
sschar bRM_1_ = {1,0}; /* FileN - номер файла ЭСППЗУ */ 
ssint iRM_0_ = {0,0}; /* FileOffs - смещение в файле ЭСППЗУ */ 
ssint iRM_1_ = {1,0}; /* х */ 
ssint iRM_4_ = {4,0}; /* p */ 
ssfloat fRM_0_0 = {0.0,0}; /* Стартовая координата ИС по умолчанию */ 
ssfloat fRM_1500_0 = {1500.0,0}; /* Стартовая координата АЗ2/ДС2 по умолчанию */ 
ssfloat fRM_100_0 = {100.0,0}; /* Стартовая координата ББ по умолчанию */ 
ssint iRM_2_ = {2,0}; /* p */ 
ssint iRM_3_ = {3,0}; /* p */ 
ssint iRM_11_ = {11,0}; /* p */ 
ssint iRM_5_ = {5,0}; /* p */ 
ssint iRM_6_ = {6,0}; /* p */ 
ssbool lRM_1_ = {1,0}; /* A-Граница участка насыщения А */ 
ssbool lRM_0_ = {0,0}; /* B-Граница участка насыщения В */ 
sslong dRM_0_ = {0,0}; /* lx вход лонг */ 
sschar bRM_0_ = {0,0}; /* cx вход байтовый */ 
ssint iRM_21_ = {21,0}; /* N-число входов */ 
ssint iRM_17_ = {17,0}; /* N-число входов */ 
ssint iRM_7_ = {7,0}; /* N-число входов */ 
ssint iRM_20_ = {20,0}; /* N-число входов */ 
ssint iRM_18_ = {18,0}; /* N-число входов */ 
ssint iRM_80_ = {80,0}; /* N-число входов */ 
ssint iRM_10_ = {10,0}; /* N-число входов */ 
ssint iRM_150_ = {150,0}; /* N-число входов */ 
ssint iRM_12_ = {12,0}; /* N-число входов */ 
ssint iRM_60_ = {60,0}; /* N-число входов */ 
ssint iRM_9_ = {9,0}; /* N-число входов */ 
ssint iRM_16_ = {16,0}; /* n - N-размерность массива x */ 
ssfloat fRM_0_ = {0,0}; /* x - массив входных параметров */ 
ssint iRM_819_ = {819,0}; /* a */ 
ssint iRM_4095_ = {4095,0}; /* b */ 
sschar bRM_2_ = {2,0}; /* type - тип проверки 1-ини,2-ву ис,3-2ур,4-нуп ис,5-ву рб, 6-конец */ 
sschar bRM_3_ = {3,0}; /* type - тип проверки 1-ини,2-ву ис,3-2ур,4-нуп ис,5-ву рб, 6-конец */ 
sschar bRM_4_ = {4,0}; /* type - тип проверки 1-ини,2-ву ис,3-2ур,4-нуп ис,5-ву рб, 6-конец */ 
sschar bRM_5_ = {5,0}; /* type - тип проверки 1-ини,2-ву ис,3-2ур,4-нуп ис,5-ву рб, 6-конец */ 
sschar bRM_6_ = {6,0}; /* type - тип проверки 1-ини,2-ву ис,3-2ур,4-нуп ис,5-ву рб, 6-конец */ 
ssfloat fRM_100_ = {100,0}; /* x - массив входных параметров */ 
ssfloat fRM_160_ = {160,0}; /* x - массив входных параметров */ 
ssfloat fRM_20_ = {20,0}; /* x - массив входных параметров */ 
ssfloat fRM_20_03 = {20.03,0}; /* X2 */ 
ssfloat fRM_20_0 = {20.0,0}; /* X2 */ 
ssint iRM_14_ = {14,0}; /* n - N-размерность массива x */ 
ssfloat fRM_2_0 = {2.0,0}; /* tz - время задержки */ 
ssfloat fRM_3_0 = {3.0,0}; /* tz - время задержки */ 
ssfloat fRM_2_5 = {2.5,0}; /* tz - время задержки */ 
ssfloat fRM_15_0 = {15.0,0}; /* tz - время задержки */ 
ssfloat fRM_0_002 = {0.002,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_005 = {0.005,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_007 = {0.007,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_01 = {0.01,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_015 = {0.015,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_02 = {0.02,0}; /* x - массив входных параметров */ 
ssfloat fRM_1_7 = {1.7,0}; /* x - массив входных параметров */ 
ssfloat fRM_10_0 = {10.0,0}; /* tz - время задержки */ 
ssfloat fRM_0_15 = {0.15,0}; /* tz - ширина импульса, sek */ 
ssfloat fRM_0_2 = {0.2,0}; /* tz - ширина импульса, sek */ 
ssfloat fRM_0_5 = {0.5,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_3_5 = {3.5,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_6_5 = {6.5,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_9_5 = {9.5,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_12_5 = {12.5,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_15_5 = {15.5,0}; /* Tpr - время завершения проверки сек от старта программы */ 
ssfloat fRM_30_0 = {30.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_50_0 = {50.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_70_0 = {70.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_90_0 = {90.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_110_0 = {110.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_130_0 = {130.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_150_0 = {150.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_170_0 = {170.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_200_0 = {200.0,0}; /* Tpr - время окончания проверки сек от старта программы */ 
ssfloat fRM_6_0 = {6.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_126_0 = {126.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_246_0 = {246.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_366_0 = {366.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_486_0 = {486.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_606_0 = {606.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_726_0 = {726.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_846_0 = {846.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_966_0 = {966.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_1200_0 = {1200.0,0}; /* Tpr - время завершения проверки сек от старта программы */ 
ssfloat fRM_2000_ = {2000,0}; /* Lt_bw - шкала координат выбора скорости движения назад(мм) */ 
ssfloat fRM_390_ = {390,0}; /* Kt - текущее, известное(контрольное) положение механизма, мм */ 
ssfloat fRM_390_0 = {390.0,0}; /* Kt - текущее, известное(контрольное) положение механизма, мм */ 
ssfloat fRM_1000_ = {1000,0}; /* Lt_fw - шкала координат выбора скорости движения вперёд(мм) */ 
ssfloat fRM_210_0 = {210.0,0}; /* Время задержки подъёма ОРР после сброса (сек) */ 
ssfloat fRM_100_0001 = {100.0001,0}; /* X2 */ 
ssfloat fRM_0_0001 = {0.0001,0}; /* X1 */ 
ssfloat fRM_160_0001 = {160.0001,0}; /* X2 */ 
ssfloat fRM_160_00001 = {160.00001,0}; /* X2 */ 
ssfloat fRM_389_99 = {389.99,0}; /* X1 */ 
ssfloat fRM_1500_0001 = {1500.0001,0}; /* X2 */ 
ssint iRM_47_ = {47,0}; /* n - N-размерность массива входных параметров */ 
ssfloat fRM_3_ = {3,0}; /* tz - время задержки сек */ 
ssfloat fRM_55_0 = {55.0,0}; /* X1 */ 
ssfloat fRM_1_0 = {1.0,0}; /* tz - ширина импульса, sek */ 

uspaint8 SpaEEPROMBuf[821];

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
ssfloat var29;
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
ssfloat var40;
ssbool var41;
ssfloat var42;
ssbool var43;
ssbool var44;
ssbool var45;
ssbool var46;
ssfloat var47;
ssfloat var48;
ssbool var49;
ssbool var50;
ssfloat var51;
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
ssfloat var62;
ssfloat var63;
ssfloat var64;
ssfloat var65;
ssbool var66;
ssfloat var67;
ssfloat var68;
ssint var69;
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
ssbool var145;
ssbool var146;
ssbool var147;
ssbool var148;
ssbool var149;
ssbool var150;
ssbool var151;
ssbool var152;
ssbool var153;
ssbool var154;
ssbool var155;
ssbool var156;
ssbool var157;
ssbool var158;
ssbool var159;
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
ssbool var170;
ssbool var171;
ssbool var172;
ssbool var173;
ssbool var174;
ssfloat var175;
ssbool var176;
ssbool var177;
ssbool var178;
ssfloat var179;
ssbool var180;
ssbool var181;
ssbool var182;
ssfloat var183;
ssbool var184;
ssbool var185;
ssbool var186;
ssfloat var187;
ssbool var188;
ssbool var189;
ssbool var190;
ssfloat var191;
ssbool var192;
ssbool var193;
ssbool var194;
ssbool var195;
ssbool var196;
ssbool var197;
ssbool var198;
ssbool var199;
ssbool var200;
ssbool var201;
ssbool var202;
ssbool var203;
ssbool var204;
ssbool var205;
ssbool var206;
ssbool var207;
ssbool var208;
ssbool var209;
ssbool var210;
ssbool var211;
ssbool var212;
ssbool var213;
ssbool var214;
ssbool var215;
ssbool var216;
ssbool var217;
ssbool var218;
ssbool var219;
ssbool var220;
ssbool var221;
ssbool var222;
ssbool var223;
ssbool var224;
ssbool var225;
ssbool var226;
ssbool var227;
ssbool var228;
ssbool var229;
ssbool var230;
ssbool var231;
ssbool var232;
ssbool var233;
ssbool var234;
ssbool var235;
ssbool var236;
ssbool var237;
ssbool var238;
ssbool var239;
ssbool var240;
ssbool var241;
ssbool var242;
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
ssbool var253;
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
ssbool var295;
ssbool var296;
ssfloat var297;
ssfloat var298;
ssbool var299;
ssfloat var300;
ssfloat var301;
ssbool var302;
ssfloat var303;
ssfloat var304;
ssfloat var305;
ssbool var306;
ssfloat var307;
ssfloat var308;
ssbool var309;
ssbool var310;
ssfloat var311;
ssfloat var312;
ssbool var313;
ssbool var314;
ssbool var315;
ssbool var316;
ssbool var317;
ssbool var318;
ssbool var319;
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
ssbool var332;
ssbool var333;
ssbool var334;
ssbool var335;
ssbool var336;
ssbool var337;
ssbool var338;
ssbool var339;
ssbool var340;
ssbool var341;
ssbool var342;
ssbool var343;
ssbool var344;
ssbool var345;
ssbool var346;
ssbool var347;
ssbool var348;
ssbool var349;
ssbool var350;
ssbool var351;
ssbool var352;
ssbool var353;
ssbool var354;
ssbool var355;
ssbool var356;
ssbool var357;
ssbool var358;
ssbool var359;
ssbool var360;
ssbool var361;
ssbool var362;
ssbool var363;
ssbool var364;
ssbool var365;
ssbool var366;
ssbool var367;
ssbool var368;
ssbool var369;
ssbool var370;
ssbool var371;
ssbool var372;
ssbool var373;
ssbool var374;
ssbool var375;
ssbool var376;
ssbool var377;
ssbool var378;
ssbool var379;
ssbool var380;
ssbool var381;
ssbool var382;
ssbool var383;
ssbool var384;
ssbool var385;
ssbool var386;
ssbool var387;
ssbool var388;
ssbool var389;
ssbool var390;
ssbool var391;
ssbool var392;
ssbool var393;
ssbool var394;
ssbool var395;
ssbool var396;
ssbool var397;
ssbool var398;
ssbool var399;
ssbool var400;
ssbool var401;
ssbool var402;
ssbool var403;
ssbool var404;
ssbool var405;
ssbool var406;
ssbool var407;
ssbool var408;
ssbool var409;
ssbool var410;
ssbool var411;
ssbool var412;
ssbool var413;
ssbool var414;
ssbool var415;
ssbool var416;
ssbool var417;
ssbool var418;
ssbool var419;
ssbool var420;
ssbool var421;
ssbool var422;
ssbool var423;
ssbool var424;
ssbool var425;
ssbool var426;
ssbool var427;
ssbool var428;
ssbool var429;
ssbool var430;
ssbool var431;
ssbool var432;
ssbool var433;
ssbool var434;
ssbool var435;
ssbool var436;
ssbool var437;
ssbool var438;
ssbool var439;
ssbool var440;
ssbool var441;
ssbool var442;
ssbool var443;
ssbool var444;
ssbool var445;
ssbool var446;
ssbool var447;
ssbool var448;
ssbool var449;
ssbool var450;
ssbool var451;
ssbool var452;
ssbool var453;
ssbool var454;
ssbool var455;
ssbool var456;
ssbool var457;
sslong var458;
ssbool var459;
ssbool var460;
ssbool var461;
ssbool var462;
ssbool var463;
ssbool var464;
ssbool var465;
ssbool var466;
ssbool var467;
ssbool var468;
ssbool var469;
ssbool var470;
ssbool var471;
ssbool var472;
ssbool var473;
ssbool var474;
ssbool var475;
ssbool var476;
ssbool var477;
ssbool var478;
ssbool var479;
ssbool var480;
ssbool var481;
ssbool var482;
ssbool var483;
ssbool var484;
ssbool var485;
ssbool var486;
ssbool var487;
ssbool var488;
ssbool var489;
ssbool var490;
ssbool var491;
ssbool var492;
ssbool var493;
ssbool var494;
ssbool var495;
ssbool var496;
ssbool var497;
ssbool var498;
ssbool var499;
ssbool var500;
ssbool var501;
ssbool var502;
ssbool var503;
ssbool var504;
ssbool var505;
ssbool var506;
ssbool var507;
ssbool var508;
ssbool var509;
ssbool var510;
ssbool var511;
ssbool var512;
ssbool var513;
ssbool var514;
ssbool var515;
ssbool var516;
ssbool var517;
ssbool var518;
ssbool var519;
ssbool var520;
ssbool var521;
ssbool var522;
ssbool var523;
ssbool var524;
ssbool var525;
ssbool var526;
ssbool var527;
ssbool var528;
ssbool var529;
ssbool var530;
ssbool var531;
ssbool var532;
ssbool var533;
ssbool var534;
ssbool var535;
ssbool var536;
ssbool var537;
ssbool var538;
ssbool var539;
ssbool var540;
ssbool var541;
ssbool var542;
ssbool var543;
ssbool var544;
ssbool var545;
ssbool var546;
ssbool var547;
ssbool var548;
ssbool var549;
ssbool var550;
ssbool var551;
ssbool var552;
ssbool var553;
ssbool var554;
ssbool var555;
ssbool var556;
ssbool var557;
ssbool var558;
ssbool var559;
ssbool var560;
ssbool var561;
ssbool var562;
ssbool var563;
ssbool var564;
ssbool var565;
ssbool var566;
ssbool var567;
ssbool var568;
ssbool var569;
ssbool var570;
ssbool var571;
ssbool var572;
ssbool var573;
ssbool var574;
ssbool var575;
ssbool var576;
ssbool var577;
ssbool var578;
ssbool var579;
ssbool var580;
ssbool var581;
ssbool var582;
ssbool var583;
ssbool var584;
ssbool var585;
ssbool var586;
ssbool var587;
ssbool var588;
ssbool var589;
ssbool var590;
ssbool var591;
ssbool var592;
ssbool var593;
ssbool var594;
ssbool var595;
ssbool var596;
ssbool var597;
ssbool var598;
ssbool var599;
ssbool var600;
ssbool var601;
ssbool var602;
ssbool var603;
ssbool var604;
ssbool var605;
ssbool var606;
ssbool var607;
ssbool var608;
ssbool var609;
ssbool var610;
ssbool var611;
ssbool var612;
ssbool var613;
ssbool var614;
ssbool var615;
ssbool var616;
ssbool var617;
ssbool var618;
ssbool var619;
ssbool var620;
ssbool var621;
ssbool var622;
ssbool var623;
ssbool var624;
ssbool var625;
ssbool var626;
ssbool var627;
ssbool var628;
ssbool var629;
ssbool var630;
ssbool var631;
ssbool var632;
ssbool var633;
ssbool var634;
ssbool var635;
ssbool var636;
ssbool var637;
ssbool var638;
ssbool var639;
ssbool var640;
ssbool var641;
ssbool var642;
ssbool var643;
ssbool var644;
ssbool var645;
ssbool var646;
ssbool var647;
ssbool var648;
ssbool var649;
ssbool var650;
ssbool var651;
ssbool var652;
ssbool var653;
ssbool var654;
ssbool var655;
ssbool var656;
ssbool var657;
ssbool var658;
ssbool var659;
ssbool var660;
ssbool var661;
ssbool var662;
ssbool var663;
ssbool var664;
ssbool var665;
ssbool var666;
ssbool var667;
ssbool var668;
ssbool var669;
ssbool var670;
ssbool var671;
ssbool var672;
ssbool var673;
ssbool var674;
ssbool var675;
ssbool var676;
ssbool var677;
ssbool var678;
ssbool var679;
ssbool var680;
ssbool var681;
ssbool var682;
ssbool var683;
ssbool var684;
ssbool var685;
ssbool var686;
ssbool var687;
ssbool var688;
ssbool var689;
ssbool var690;
ssbool var691;
ssbool var692;
ssbool var693;
ssbool var694;
ssbool var695;
ssbool var696;
ssbool var697;
ssbool var698;
ssbool var699;
ssbool var700;
ssbool var701;
ssbool var702;
ssbool var703;
ssbool var704;
ssbool var705;
ssbool var706;
ssbool var707;
ssbool var708;
ssbool var709;
ssbool var710;
ssbool var711;
ssbool var712;
ssbool var713;
ssbool var714;
ssbool var715;
ssbool var716;
ssbool var717;
ssbool var718;
ssbool var719;
ssbool var720;
ssbool var721;
ssbool var722;
ssbool var723;
ssbool var724;
ssbool var725;
ssbool var726;
ssbool var727;
ssbool var728;
ssbool var729;
ssbool var730;
ssbool var731;
ssbool var732;
ssbool var733;
ssbool var734;
ssbool var735;
ssbool var736;
ssbool var737;
ssbool var738;
ssbool var739;
ssbool var740;
ssbool var741;
ssbool var742;
ssbool var743;
ssbool var744;
ssbool var745;
ssbool var746;
ssbool var747;
ssbool var748;
ssbool var749;
ssbool var750;
ssbool var751;
ssbool var752;
ssbool var753;
ssbool var754;
ssbool var755;
ssbool var756;
ssbool var757;
ssbool var758;
ssbool var759;
ssbool var760;
ssbool var761;
ssbool var762;
ssbool var763;
ssbool var764;
ssbool var765;
ssbool var766;
ssbool var767;
ssbool var768;
ssbool var769;
ssbool var770;
ssbool var771;
ssbool var772;
ssbool var773;
ssbool var774;
ssbool var775;
ssbool var776;
ssbool var777;
ssbool var778;
ssbool var779;
ssbool var780;
ssbool var781;
ssbool var782;
ssbool var783;
ssbool var784;
ssbool var785;
ssbool var786;
ssbool var787;
ssbool var788;
ssbool var789;
ssbool var790;
ssbool var791;
ssbool var792;
ssbool var793;
ssbool var794;
ssbool var795;
ssbool var796;
ssbool var797;
ssbool var798;
ssbool var799;
ssbool var800;
ssbool var801;
ssbool var802;
ssbool var803;
ssbool var804;
ssbool var805;
ssbool var806;
ssbool var807;
ssbool var808;
ssbool var809;
ssbool var810;
ssbool var811;
ssbool var812;
ssbool var813;
ssbool var814;
ssbool var815;
ssbool var816;
ssbool var817;
ssbool var818;
ssbool var819;
ssbool var820;
ssbool var821;
ssbool var822;
ssbool var823;
ssbool var824;
ssbool var825;
ssbool var826;
ssbool var827;
ssbool var828;
ssbool var829;
ssbool var830;
ssbool var831;
ssbool var832;
ssbool var833;
ssbool var834;
ssbool var835;
ssbool var836;
ssbool var837;
ssbool var838;
ssbool var839;
ssbool var840;
ssbool var841;
ssbool var842;
ssbool var843;
ssbool var844;
ssbool var845;
ssbool var846;
ssbool var847;
ssbool var848;
ssbool var849;
ssbool var850;
ssbool var851;
ssbool var852;
ssbool var853;
ssbool var854;
ssbool var855;
ssbool var856;
ssbool var857;
ssbool var858;
ssbool var859;
ssbool var860;
ssbool var861;
ssbool var862;
ssbool var863;
ssbool var864;
ssbool var865;
ssbool var866;
ssbool var867;
ssbool var868;
ssbool var869;
ssbool var870;
ssbool var871;
ssbool var872;
ssbool var873;
ssbool var874;
ssbool var875;
ssbool var876;
ssbool var877;
ssbool var878;
ssbool var879;
ssbool var880;
ssbool var881;
ssbool var882;
ssbool var883;
ssbool var884;
ssbool var885;
ssfloat var886;
ssbool var887;
ssfloat var888;
ssbool var889;
ssfloat var890;
ssbool var891;
ssbool var892;
ssbool var893;
ssbool var894;
ssfloat var895;
ssfloat var896;
ssfloat var897;
ssfloat var898;
ssfloat var899;
ssfloat var900;
ssbool var901;
ssbool var902;
ssbool var903;
ssbool var904;
ssbool var905;
ssbool var906;
ssbool var907;
ssbool var908;
ssbool var909;
ssbool var910;
ssbool var911;
ssbool var912;
ssbool var913;
ssbool var914;
ssbool var915;
ssbool var916;
ssbool var917;
ssbool var918;
ssbool var919;
ssbool var920;
ssbool var921;
ssbool var922;
ssbool var923;
ssbool var924;
ssbool var925;
ssbool var926;
ssbool var927;
ssbool var928;
ssbool var929;
ssbool var930;
ssbool var931;
ssbool var932;
ssbool var933;
ssbool var934;
ssbool var935;
ssbool var936;
ssbool var937;
ssbool var938;
ssbool var939;
ssbool var940;
ssbool var941;
ssbool var942;
ssbool var943;
ssbool var944;
ssbool var945;
ssbool var946;
ssbool var947;
ssbool var948;
ssbool var949;
ssbool var950;
ssbool var951;
ssbool var952;
ssbool var953;
ssbool var954;
ssbool var955;
ssint var956;
ssint var957;
ssbool var958;
ssbool var959;
ssbool var960;
ssbool var961;
ssbool var962;
ssbool var963;
sslong var964;
ssbool var965;
ssbool var966;
ssbool var967;
ssint var968;
ssbool var969;
ssbool var970;
ssbool var971;
ssbool var972;
ssbool var973;
ssbool var974;
ssbool var975;
ssbool var976;
ssbool var977;
ssint var978;
ssint var979;
ssbool var980;
ssbool var981;
ssbool var982;
ssbool var983;
ssbool var984;
ssbool var985;
ssbool var986;
ssbool var987;
ssbool var988;
ssbool var989;
ssbool var990;
ssbool var991;
ssbool var992;
ssbool var993;
ssbool var994;
ssbool var995;
ssbool var996;
ssbool var997;
ssbool var998;
ssbool var999;
ssbool var1000;
ssbool var1001;
ssbool var1002;
ssbool var1003;
ssbool var1004;
ssbool var1005;
ssbool var1006;
ssbool var1007;
ssbool var1008;
ssbool var1009;
ssbool var1010;
ssbool var1011;
ssbool var1012;
ssbool var1013;
ssbool var1014;
ssbool var1015;
ssbool var1016;
ssbool var1017;
ssbool var1018;
ssbool var1019;
ssbool var1020;
ssbool var1021;
ssint var1022;
ssbool var1023;
ssbool var1024;
ssbool var1025;
ssbool var1026;
ssbool var1027;
ssbool var1028;
ssint var1029;
ssbool var1030;
ssbool var1031;
ssbool var1032;
sslong var1033;
ssbool var1034;
ssbool var1035;
ssbool var1036;
ssbool var1037;
ssbool var1038;
ssbool var1039;
ssbool var1040;
ssbool var1041;
ssbool var1042;
ssbool var1043;
ssbool var1044;
ssbool var1045;
ssbool var1046;
ssbool var1047;
ssbool var1048;
ssbool var1049;
ssbool var1050;
ssbool var1051;
ssfloat var1052;
ssbool var1053;
ssbool var1054;
ssbool var1055;
ssbool var1056;
ssbool var1057;
ssfloat var1058;
ssbool var1059;
ssbool var1060;
ssbool var1061;
ssbool var1062;
ssbool var1063;
ssbool var1064;
ssbool var1065;
ssbool var1066;
ssbool var1067;
ssbool var1068;
ssbool var1069;
ssbool var1070;
ssbool var1071;
ssint var1072;
ssbool var1073;
ssbool var1074;
ssbool var1075;
ssbool var1076;
ssbool var1077;
ssbool var1078;
ssbool var1079;
ssbool var1080;
ssbool var1081;
ssbool var1082;
ssbool var1083;
ssbool var1084;
ssbool var1085;
ssbool var1086;
ssbool var1087;
ssbool var1088;
ssbool var1089;
ssbool var1090;
ssbool var1091;
ssbool var1092;
ssbool var1093;
ssbool var1094;
ssbool var1095;
ssbool var1096;
ssbool var1097;
ssbool var1098;
ssfloat var1099;
ssbool var1100;
ssbool var1101;
ssbool var1102;
ssbool var1103;
ssbool var1104;
ssbool var1105;
ssbool var1106;
ssbool var1107;
ssbool var1108;
ssbool var1109;
ssbool var1110;
ssbool var1111;
ssbool var1112;
ssbool var1113;
ssbool var1114;
ssbool var1115;
ssbool var1116;
ssbool var1117;
ssbool var1118;
ssbool var1119;
ssbool var1120;
ssbool var1121;
ssbool var1122;
ssbool var1123;
ssbool var1124;
ssbool var1125;
ssbool var1126;
ssbool var1127;
ssbool var1128;
ssbool var1129;
ssbool var1130;
ssbool var1131;
ssbool var1132;
ssbool var1133;
ssbool var1134;
ssbool var1135;
ssbool var1136;
ssbool var1137;
ssbool var1138;
ssbool var1139;
ssbool var1140;
ssbool var1141;
ssbool var1142;
ssbool var1143;
ssbool var1144;
ssbool var1145;
ssbool var1146;
ssbool var1147;
ssbool var1148;
ssbool var1149;
ssbool var1150;
ssbool var1151;
ssbool var1152;
ssbool var1153;
ssbool var1154;
ssbool var1155;
ssbool var1156;
ssbool var1157;
ssbool var1158;
ssbool var1159;
ssbool var1160;
ssbool var1161;
ssbool var1162;
ssbool var1163;
ssbool var1164;
ssbool var1165;
ssbool var1166;
ssbool var1167;
ssbool var1168;
ssbool var1169;
ssbool var1170;
ssbool var1171;
ssbool var1172;
ssbool var1173;
ssbool var1174;
ssbool var1175;
ssbool var1176;
ssbool var1177;
ssbool var1178;
ssbool var1179;
ssbool var1180;
ssbool var1181;
ssbool var1182;
ssbool var1183;
ssbool var1184;
ssbool var1185;
ssbool var1186;
ssbool var1187;
ssbool var1188;
ssbool var1189;
ssbool var1190;
ssbool var1191;
ssbool var1192;
ssbool var1193;
ssbool var1194;
ssbool var1195;
ssbool var1196;
ssbool var1197;
ssbool var1198;
ssbool var1199;
ssbool var1200;
ssbool var1201;
ssbool var1202;
ssbool var1203;
ssbool var1204;
ssbool var1205;
ssbool var1206;
ssbool var1207;
ssbool var1208;
ssint var1209;
ssbool var1210;
sslong var1211;
ssbool var1212;
ssint var1213;
ssint var1214;
ssbool var1215;
ssfloat var1216;
ssfloat var1217;
ssfloat var1218;
ssbool var1219;
ssbool var1220;
ssbool var1221;
ssbool var1222;
ssbool var1223;
ssbool var1224;
ssbool var1225;
ssbool var1226;
ssbool var1227;
ssbool var1228;
ssbool var1229;
ssbool var1230;
ssbool var1231;
ssbool var1232;
ssbool var1233;
ssbool var1234;
ssint var1235;
ssbool var1236;
sschar var1237;
ssint var1238;
ssbool var1239;
ssfloat var1240;
ssbool var1241;
ssbool var1242;
ssbool var1243;
ssbool var1244;
ssbool var1245;
ssbool var1246;
ssbool var1247;
ssfloat var1248;
sschar var1249;
ssbool var1250;
ssbool var1251;
ssbool var1252;
ssbool var1253;
ssfloat var1254;
ssbool var1255;
ssbool var1256;
ssbool var1257;
ssbool var1258;
ssbool var1259;
ssbool var1260;
ssbool var1261;
ssbool var1262;
ssbool var1263;
ssbool var1264;
ssbool var1265;
ssbool var1266;
ssint var1267;
ssbool var1268;
sschar var1269;
ssint var1270;
ssbool var1271;
ssfloat var1272;
ssbool var1273;
ssbool var1274;
ssbool var1275;
ssbool var1276;
ssbool var1277;
ssbool var1278;
ssbool var1279;
ssfloat var1280;
sschar var1281;
ssbool var1282;
ssbool var1283;
ssbool var1284;
ssbool var1285;
ssfloat var1286;
ssbool var1287;
ssbool var1288;
ssbool var1289;
ssbool var1290;
ssbool var1291;
ssbool var1292;
ssbool var1293;
ssbool var1294;
ssbool var1295;
ssint var1296;
ssbool var1297;
sschar var1298;
ssint var1299;
ssbool var1300;
ssfloat var1301;
ssbool var1302;
ssbool var1303;
ssbool var1304;
ssbool var1305;
ssbool var1306;
ssbool var1307;
ssbool var1308;
ssfloat var1309;
sschar var1310;
ssbool var1311;
ssbool var1312;
ssbool var1313;
ssbool var1314;
ssfloat var1315;
ssbool var1316;
ssbool var1317;
ssbool var1318;
ssbool var1319;
ssbool var1320;
ssbool var1321;
ssbool var1322;
ssbool var1323;
ssbool var1324;
ssbool var1325;
ssbool var1326;
ssbool var1327;
ssbool var1328;
ssint var1329;
ssbool var1330;
sschar var1331;
ssint var1332;
ssbool var1333;
ssfloat var1334;
ssbool var1335;
ssbool var1336;
ssbool var1337;
ssbool var1338;
ssbool var1339;
ssbool var1340;
ssbool var1341;
ssfloat var1342;
sschar var1343;
ssbool var1344;
ssbool var1345;
ssfloat var1346;
ssbool var1347;
ssbool var1348;
ssbool var1349;
ssbool var1350;
ssbool var1351;
ssbool var1352;
ssbool var1353;
ssbool var1354;
ssbool var1355;
ssbool var1356;
ssbool var1357;
ssbool var1358;
ssint var1359;
ssbool var1360;
ssbool var1361;
ssbool var1362;
ssbool var1363;
ssbool var1364;
ssbool var1365;
ssbool var1366;
ssbool var1367;
ssint var1368;
ssbool var1369;
ssbool var1370;
ssbool var1371;
ssbool var1372;
ssbool var1373;
ssbool var1374;
ssbool var1375;
ssint var1376;
ssbool var1377;
sschar var1378;
ssint var1379;
ssbool var1380;
ssfloat var1381;
ssbool var1382;
ssbool var1383;
ssbool var1384;
ssbool var1385;
ssbool var1386;
ssbool var1387;
ssbool var1388;
ssfloat var1389;
sschar var1390;
ssbool var1391;
ssbool var1392;
ssfloat var1393;
ssbool var1394;
ssbool var1395;
ssbool var1396;
ssbool var1397;
ssbool var1398;
ssbool var1399;
ssbool var1400;
ssbool var1401;
sschar var1402;
ssbool var1403;
ssbool var1404;
ssbool var1405;
ssbool var1406;
ssbool var1407;
ssbool var1408;
ssbool var1409;
ssbool var1410;
ssbool var1411;
sschar var1412;
ssbool var1413;
ssbool var1414;
ssint var1415;
ssbool var1416;
sschar var1417;
ssbool var1418;
ssint var1419;
ssbool var1420;
ssbool var1421;
ssfloat var1422;
ssbool var1423;
ssbool var1424;
ssbool var1425;
ssbool var1426;
ssbool var1427;
ssbool var1428;
ssbool var1429;
ssfloat var1430;
sschar var1431;
ssbool var1432;
ssbool var1433;
ssbool var1434;
ssbool var1435;
ssfloat var1436;
ssbool var1437;
ssbool var1438;
ssbool var1439;
ssbool var1440;
ssbool var1441;
ssbool var1442;
ssbool var1443;
ssbool var1444;
ssbool var1445;
ssbool var1446;
ssbool var1447;
ssbool var1448;
ssfloat var1449;
ssbool var1450;
ssbool var1451;
ssbool var1452;
ssbool var1453;
ssbool var1454;
ssbool var1455;
ssbool var1456;
ssbool var1457;
ssbool var1458;
ssbool var1459;
ssbool var1460;
ssbool var1461;
ssbool var1462;
ssbool var1463;
ssbool var1464;
ssbool var1465;
ssfloat var1466;
ssbool var1467;
ssbool var1468;
ssbool var1469;
ssbool var1470;
ssbool var1471;
ssbool var1472;
ssbool var1473;
ssbool var1474;
ssbool var1475;
ssbool var1476;
ssbool var1477;
ssbool var1478;
ssbool var1479;
ssbool var1480;
ssbool var1481;
ssbool var1482;
ssbool var1483;
ssbool var1484;
ssbool var1485;
ssbool var1486;
ssbool var1487;
ssbool var1488;
ssbool var1489;
ssbool var1490;
ssbool var1491;
ssbool var1492;
ssbool var1493;
ssbool var1494;
ssbool var1495;
ssbool var1496;
ssbool var1497;
ssbool var1498;
ssbool var1499;
ssbool var1500;
ssbool var1501;
ssbool var1502;
ssbool var1503;
ssint var1504;
ssbool var1505;
ssbool var1506;
ssbool var1507;
ssbool var1508;
ssbool var1509;
ssbool var1510;
ssbool var1511;
ssbool var1512;
ssint var1513;
ssbool var1514;
ssbool var1515;
ssbool var1516;
ssbool var1517;
ssbool var1518;
ssbool var1519;
ssbool var1520;
ssbool var1521;
ssint var1522;
ssbool var1523;
ssbool var1524;
ssbool var1525;
ssbool var1526;
ssbool var1527;
ssbool var1528;
ssbool var1529;
ssbool var1530;
ssint var1531;
ssbool var1532;
ssbool var1533;
ssbool var1534;
ssbool var1535;
ssbool var1536;
ssbool var1537;
ssbool var1538;
ssbool var1539;
ssint var1540;
ssbool var1541;
ssbool var1542;
ssbool var1543;
ssbool var1544;
ssbool var1545;
ssbool var1546;
ssbool var1547;
ssbool var1548;
ssint var1549;
ssbool var1550;
ssbool var1551;
ssbool var1552;
ssbool var1553;
ssbool var1554;
ssbool var1555;
ssbool var1556;
ssbool var1557;
ssint var1558;
ssbool var1559;
ssbool var1560;
ssbool var1561;
ssbool var1562;
ssbool var1563;
ssbool var1564;
ssbool var1565;
ssbool var1566;
ssbool var1567;
ssbool var1568;
ssbool var1569;
ssbool var1570;
ssbool var1571;
ssbool var1572;
ssbool var1573;
ssbool var1574;
ssbool var1575;
ssbool var1576;
ssbool var1577;
ssbool var1578;
ssbool var1579;
ssbool var1580;
ssbool var1581;
ssbool var1582;
ssbool var1583;
ssbool var1584;
ssbool var1585;
ssfloat var1586;
ssbool var1587;
ssbool var1588;
ssbool var1589;
ssbool var1590;
ssbool var1591;
ssbool var1592;
ssbool var1593;
ssbool var1594;
ssbool var1595;
ssbool var1596;
ssbool var1597;
ssbool var1598;
ssbool var1599;
ssbool var1600;
ssbool var1601;
ssbool var1602;
ssbool var1603;
ssbool var1604;
ssbool var1605;
ssbool var1606;
ssbool var1607;
ssbool var1608;
ssbool var1609;
ssbool var1610;
ssbool var1611;
ssbool var1612;
ssbool var1613;
ssbool var1614;
ssbool var1615;
ssbool var1616;
ssbool var1617;
ssbool var1618;
ssbool var1619;
ssbool var1620;
ssbool var1621;
ssbool var1622;
ssbool var1623;
ssbool var1624;
ssfloat var1625;
ssfloat var1626;
ssbool var1627;
ssbool var1628;
ssbool var1629;
ssbool var1630;
ssbool var1631;
ssbool var1632;
ssbool var1633;
ssbool var1634;
ssbool var1635;
ssbool var1636;
ssbool var1637;
ssbool var1638;
ssbool var1639;
ssbool var1640;
ssbool var1641;
ssbool var1642;
ssbool var1643;
ssbool var1644;
ssbool var1645;
ssbool var1646;
ssbool var1647;
ssbool var1648;
ssbool var1649;
ssbool var1650;
ssbool var1651;
ssbool var1652;
ssbool var1653;
ssfloat var1654;
ssbool var1655;
ssbool var1656;
ssbool var1657;
ssfloat var1658;
ssbool var1659;
ssbool var1660;
ssbool var1661;
ssfloat var1662;
ssbool var1663;
ssbool var1664;
ssbool var1665;
ssfloat var1666;
ssbool var1667;
ssbool var1668;
ssbool var1669;
ssfloat var1670;
ssbool var1671;
ssbool var1672;
ssbool var1673;
ssfloat var1674;
ssbool var1675;
ssbool var1676;
ssbool var1677;
ssfloat var1678;
ssbool var1679;
ssbool var1680;
ssbool var1681;
ssbool var1682;
ssfloat var1683;
ssbool var1684;
ssbool var1685;
ssbool var1686;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m168_x_2[17] = {&R0IE02LDU,&R0IE01LDU,&A8IE01LDU,&B6IE01LDU,&R1IE01LDU,&R2IE01LDU,&A5IE02LDU,&B5IE01LDU,&A6IE01LDU,&R6IS62LDU,&R6IS63LDU,&R6IS64LDU,&R6IS65LDU,&R6IS61LDU,&var1589,&var1588,&var1587};
psbool  array_m148_x_2[6] = {&B3IE02LDU,&B1IE02LDU,&B2IE01LDU,&B1IE01LDU,&B3IE01LDU,&B2IE02LDU};
psbool  array_m132_x_2[6] = {&A1IE02LDU,&A2IE02LDU,&A1IE01LDU,&A2IE01LDU,&A3IE01LDU,&A3IE02LDU};
psbool  array_m250_x_2[6] = {&var1637,&var1629,&var1643,&B0VT71LZ1,&B0VT71LZ2,&var1584};
psbool  array_m236_x_2[6] = {&var1638,&var1631,&var1644,&A0VT71LZ1,&A0VT71LZ2,&var1584};
psbool  array_m259_x_2[6] = {&var1622,&B0VP71LZ1,&B0VP71LZ2,&var1592,&var1591,&var1590};
psbool  array_m238_x_2[6] = {&var1623,&A0VP71LZ1,&A0VP71LZ2,&var1595,&var1594,&var1593};
psbool  array_m123_x_2[8] = {&var1656,&var1685,&var1680,&var1676,&var1672,&var1668,&var1660,&var1664};
psbool  array_m587_x_1[6] = {&var696,&var1010,&var1461,&var971,&var1420,&var1004};
psbool  array_m586_x_1[6] = {&var696,&var1011,&var1461,&var971,&var1420,&var1003};
psfloat  array_m2140_a_1[6] = {&fEM_R0UN70LDU,&fEM_R0UN71LDU,&fEM_R0UN72LDU,&fEM_R0UN73LDU,&fEM_R0UN74LDU,&fEM_R0UN75LDU};
psfloat  array_m2140_b_1[6] = {&fEM_R0UN80LDU,&fEM_R0UN81LDU,&fEM_R0UN82LDU,&fEM_R0UN83LDU,&fEM_R0UN84LDU,&fEM_R0UN85LDU};
psfloat  array_m2153_x_1[4] = {&B0CT01IZ1,&A0CT01IZ1,&B0CT01IZ2,&A0CT01IZ2};
psfloat  array_m2175_x_1[2] = {&R0VN09RZ1,&R0VN09RZ2};
psbool  array_m2144_x_1[14] = {&var46,&var16,&var730,&var82,&var84,&var14,&var1583,&var1156,&var1154,&var1585,&var45,&var31,&var27,&var54};
psbool  array_m1_x_1[47] = {&var1112,&var269,&var196,&var808,&var357,&var1330,&var618,&R0MD34LP1,&var524,&R0MD34LP1,&var589,&R0MD34LP1,&var829,&R0MD34LP1,&var645,&R0MD34LP1,&var827,&var1357,&A2IS12LDU,&var262,&var1150,&var1032,&var1030,&var929,&var739,&R0MD34LP1,&var292,&var334,&var1194,&var1511,&var1020,&var465,&var456,&var405,&R0MD34LP1,&B3IS35LDU,&var165,&var1190,&var368,&var103,&var1562,&var1520,&var1547,&var850,&var1534,&R2IS21LDU,&var17};
psfloat  array_m1461_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psbool  array_m1414_x_1[5] = {&var465,&var464,&var463,&var462,&var461};
psbool  array_m547_x_1[14] = {&var643,&var649,&var650,&var641,&var642,&var832,&var833,&var811,&var810,&var639,&var637,&var645,&var638,&var76};
psfloat  array_m81_x_1[2] = {&R0VN11RZ2,&R0VN11RZ1};
psfloat  array_m83_x_1[8] = {&fEM_R0UN01RDU,&fEM_R0UN02RDU,&fEM_R0UN03RDU,&fEM_R0UN04RDU,&fEM_R0UN05RDU,&fEM_R0UN06RDU,&fEM_R0UN07RDU,&fEM_R0UN08RDU};
psfloat  array_m1065_x_1[2] = {&R0VN11RZ2,&R0VN11RZ1};
psfloat  array_m1195_x_1[8] = {&var1422,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m809_x_1[8] = {&var1381,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m891_x_1[8] = {&var1272,&var42,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m1296_x_1[8] = {&var1240,&var40,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m489_x_1[8] = {&var1301,&var187,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m158_x_1[8] = {&var1334,&var191,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m315_Tpr_1[10] = {&fRM_6_0,&fRM_126_0,&fRM_246_0,&fRM_366_0,&fRM_486_0,&fRM_606_0,&fRM_726_0,&fRM_846_0,&fRM_966_0,&fRM_1200_0};
pschar  array_m315_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m315_rz_1[10];
psbool  array_m319_x_1[5] = {&var959,&var960,&var961,&var962,&var963};
psbool  array_m257_x_1[7] = {&var730,&var78,&var938,&var935,&var84,&var82,&var80};
psfloat  array_m261_Tpr_1[10] = {&fRM_10_0,&fRM_30_0,&fRM_50_0,&fRM_70_0,&fRM_90_0,&fRM_110_0,&fRM_130_0,&fRM_150_0,&fRM_170_0,&fRM_200_0};
pschar  array_m261_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m261_rz_1[10];
psfloat  array_m1403_Tpr_1[6] = {&fRM_0_5,&fRM_3_5,&fRM_6_5,&fRM_9_5,&fRM_12_5,&fRM_15_5};
pschar  array_m1403_type_1[6] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_6_};
pschar  array_m1403_rz_1[6];
psbool  array_m276_x_1[5] = {&var981,&var982,&var983,&var984,&var985};
psbool  array_m1172_x_1[6] = {&var1128,&var713,&var1493,&var1136,&var1132,&var94};
psbool  array_m1160_x_1[5] = {&var1015,&var1071,&var1130,&var1134,&var931};
psfloat  array_m1444_x_1[16] = {&var297,&var307,&fRM_0_,&var303,&fRM_0_,&fRM_0_,&fRM_0_,&var300,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&var311};
psbool  array_m1754_x_1[17] = {&var379,&var380,&var386,&var381,&var377,&var378,&var868,&var382,&var383,&var1183,&var384,&var385,&var1175,&var1176,&var1185,&var88,&var89};
psbool  array_m1406_x_1[5] = {&var289,&var429,&var446,&var447,&var320};
psint  array_m295_x_1[3] = {&var957,&iRM_0_,&var979};
psint  array_m286_x_1[3] = {&var956,&iRM_0_,&var978};
psbool  array_m589_x_1[6] = {&var679,&var1460,&var1227,&var1227,&var52,&var912};
psbool  array_m1360_x_1[9] = {&var557,&var558,&var559,&var553,&var552,&var551,&var825,&var549,&var827};
psbool  array_m1295_x_1[3] = {&var39,&lRM_0_,&var743};
psfloat  array_m1297_Lt_fw_1[1] = {&fEM_A3UC81RDU};
psint  array_m1297_Vr_fw_1[1] = {&iEM_A3UV01IDU};
psfloat  array_m1297_Lt_bw_1[1] = {&fEM_A3UC82RDU};
psint  array_m1297_Vr_bw_1[1] = {&iEM_A3UV02IDU};
psfloat  array_m1325_x0_1[60];
psfloat  array_m1325_tim0_1[60];
psbool  array_m960_x_1[9] = {&var574,&var576,&var577,&var569,&var575,&var571,&var830,&var278,&var829};
psbool  array_m890_x_1[3] = {&var41,&lRM_0_,&var583};
psfloat  array_m892_Lt_fw_1[1] = {&fEM_A3UC81RDU};
psint  array_m892_Vr_fw_1[1] = {&iEM_A3UV01IDU};
psfloat  array_m892_Lt_bw_1[1] = {&fEM_A3UC82RDU};
psint  array_m892_Vr_bw_1[1] = {&iEM_A3UV02IDU};
psfloat  array_m925_x0_1[60];
psfloat  array_m925_tim0_1[60];
psbool  array_m488_x_1[3] = {&var654,&lRM_0_,&var655};
psfloat  array_m491_Lt_fw_1[2] = {&fEM_A1UC81RDU,&fEM_A1UC82RDU};
psint  array_m491_Vr_fw_1[2] = {&iEM_A1UV01IDU,&iEM_A1UV02IDU};
psfloat  array_m491_Lt_bw_1[1] = {&fEM_A1UC83RDU};
psint  array_m491_Vr_bw_1[1] = {&iEM_A1UV03IDU};
psfloat  array_m518_x0_1[150];
psfloat  array_m518_tim0_1[150];
psbool  array_m223_x_1[12] = {&var623,&var625,&var624,&var621,&var619,&var618,&var617,&var836,&var835,&var612,&var615,&var77};
psbool  array_m160_x_1[3] = {&var803,&lRM_0_,&var804};
psfloat  array_m163_Lt_fw_1[2] = {&fEM_A1UC81RDU,&fEM_A1UC82RDU};
psint  array_m163_Vr_fw_1[2] = {&iEM_A1UV01IDU,&iEM_A1UV02IDU};
psfloat  array_m163_Lt_bw_1[1] = {&fEM_A1UC83RDU};
psint  array_m163_Vr_bw_1[1] = {&iEM_A1UV03IDU};
psfloat  array_m192_x0_1[150];
psfloat  array_m192_tim0_1[150];
psbool  array_m864_x_1[10] = {&var587,&var588,&var594,&var595,&var593,&var591,&var590,&var838,&var837,&var589};
psbool  array_m808_x_1[3] = {&var605,&var606,&var607};
psfloat  array_m811_Lt_fw_1[2] = {&fEM_A2UC81RDU,&fEM_A2UC82RDU};
psint  array_m811_Vr_fw_1[2] = {&iEM_A2UV01IDU,&iEM_A2UV02IDU};
psfloat  array_m811_Lt_bw_1[1] = {&fEM_A2UC83RDU};
psint  array_m811_Vr_bw_1[1] = {&iEM_A2UV03CDU};
psfloat  array_m831_x0_1[80];
psfloat  array_m831_tim0_1[80];
psfloat  array_m1584_Lt_fw_1[1] = {&fRM_1000_};
psint  array_m1584_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1584_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1584_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1269_x_1[10] = {&var520,&var521,&var523,&var522,&var524,&var526,&var528,&var525,&var527,&var529};
psbool  array_m141_x_1[5] = {&A1IS21LDU,&A3IS21LDU,&A2IS21LDU,&var854,&var853};
psfloat  array_m1116_Lt_fw_1[1] = {&fRM_2000_};
psint  array_m1116_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1116_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1116_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1198_x_1[3] = {&var512,&var513,&var514};
psfloat  array_m1199_Lt_fw_1[2] = {&fEM_A2UC81RDU,&fEM_A2UC82RDU};
psint  array_m1199_Vr_fw_1[2] = {&iEM_A2UV01IDU,&iEM_A2UV02IDU};
psfloat  array_m1199_Lt_bw_1[1] = {&fEM_A2UC83RDU};
psint  array_m1199_Vr_bw_1[1] = {&iEM_A2UV03CDU};
psfloat  array_m1232_x0_1[80];
psfloat  array_m1232_tim0_1[80];
psfloat  array_m1604_x0_1[20];
psfloat  array_m1604_tim0_1[20];
psbool  array_m1088_x_1[8] = {&var740,&var737,&var738,&var739,&var736,&var735,&var734,&var733};
psbool  array_m590_x_1[18] = {&R0MD31LP1,&var419,&var755,&var421,&var753,&var515,&var658,&var604,&var633,&var653,&var579,&var539,&var812,&var212,&var211,&var503,&var110,&var43};
psfloat  array_m1138_x0_1[20];
psfloat  array_m1138_tim0_1[20];
psbool  array_m432_x_1[7] = {&var860,&var859,&var858,&var857,&var1564,&var849,&var242};
psbool  array_m414_x_1[7] = {&var862,&var1564,&var850,&var863,&var861,&var848,&var847};
psbool  array_m764_x_1[17] = {&var756,&var801,&var800,&var797,&var796,&var793,&var758,&var795,&var763,&var792,&var788,&var790,&var789,&var760,&var754,&var846,&var609};
psbool  array_m127_x_1[21] = {&var632,&var652,&var903,&var603,&var902,&var901,&var1498,&var1507,&var1525,&var1516,&var1552,&var1543,&var357,&var243,&var893,&var894,&var1197,&var1191,&var1362,&var1353,&var1534};

/* Объявление структур */
_S_or2  S_or2_262_2 = {&var1686,&var1627,&var1584};
_S_bol  S_bol_227_2 = {&fRM_0_5,&var1586,&var1585};
_S_fsumo  S_fsumo_226_2 = {&var1626,&var1625,&var1586};
_S_or2  S_or2_179_2 = {&R6IS66LZ2,&R6IS66LZ1,&var1587};
_S_or2  S_or2_178_2 = {&R6IS67LZ1,&R6IS67LZ2,&var1588};
_S_or2  S_or2_177_2 = {&R6IS68LZ1,&R6IS68LZ2,&var1589};
_S_noto  S_noto_255_2 = {&B3VP81LDU,&var1590};
_S_noto  S_noto_254_2 = {&B2VP82LDU,&var1591};
_S_noto  S_noto_253_2 = {&B4VP82LDU,&var1592};
_S_noto  S_noto_235_2 = {&A3VP81LDU,&var1593};
_S_noto  S_noto_234_2 = {&A2VP82LDU,&var1594};
_S_noto  S_noto_233_2 = {&A4VP82LDU,&var1595};
_S_schl24  S_schl24_147_2 = {&A0EE02LZ1,&A0EE03LZ1,&A0EE01LZ1,&A0EE04LZ1,&var1596};
_S_schl24  S_schl24_141_2 = {&A0EE03LZ2,&A0EE01LZ2,&A0EE02LZ2,&A0EE04LZ2,&var1597};
_S_or2  S_or2_202_2 = {&var1647,&var1648,&var1598};
_S_or2  S_or2_199_2 = {&var1650,&var1651,&var1599};
_S_and2  S_and2_217_2 = {&var1635,&var1646,&var1600};
_S_or2  S_or2_251_2 = {&var1642,&var1641,&var1601};
_S_and4  S_and4_157_2 = {&A0EE02LZ1,&A0EE04LZ1,&A0EE02LZ2,&A0EE04LZ2,&var1602};
_S_or3  S_or3_156_2 = {&var1602,&var718,&var1596,&var1603};
_S_and4  S_and4_134_2 = {&A0EE03LZ1,&A0EE01LZ1,&A0EE01LZ2,&A0EE03LZ2,&var1604};
_S_or3  S_or3_133_2 = {&var1604,&var1597,&var718,&var1605};
_S_and3  S_and3_110_2 = {&var1607,&var1681,&A8IS12LDU,&var1606};
_S_or2  S_or2_104_2 = {&A8MC01LC2,&A8MC01LC1,&var1607};
_S_or2  S_or2_103_2 = {&B8MC01LC2,&B8MC01LC1,&var1608};
_S_and3  S_and3_106_2 = {&var1681,&B8IS12LDU,&var1608,&var1609};
_S_and3  S_and3_79_2 = {&var1681,&B3IS11LDU,&var1611,&var1610};
_S_or2  S_or2_71_2 = {&B3MC01LC2,&B3MC01LC1,&var1611};
_S_or2  S_or2_74_2 = {&A3MC01LC2,&A3MC01LC1,&var1612};
_S_and3  S_and3_82_2 = {&var1681,&var1612,&A3IS11LDU,&var1613};
_S_or2  S_or2_44_2 = {&A2MC01LC2,&A2MC01LC1,&var1614};
_S_and3  S_and3_51_2 = {&var1681,&A2IS11LDU,&var1614,&var1615};
_S_or2  S_or2_13_2 = {&A1MC01LC2,&A1MC01LC1,&var1616};
_S_and3  S_and3_23_2 = {&var1616,&var1681,&A1IS11LDU,&var1617};
_S_or2  S_or2_43_2 = {&B2MC01LC1,&B2MC01LC2,&var1618};
_S_and3  S_and3_48_2 = {&var1681,&B2IS11LDU,&var1618,&var1619};
_S_or2  S_or2_11_2 = {&B1MC01LC2,&B1MC01LC1,&var1620};
_S_and3  S_and3_20_2 = {&var1681,&B1IS11LDU,&var1620,&var1621};
_S_and2  S_and2_258_2 = {&R0EE03LDU,&var1598,&var1622};
_S_and2  S_and2_237_2 = {&R0EE03LDU,&var1599,&var1623};
_S_and2  S_and2_223_2 = {&var1636,&var1645,&var1624};
_S_scalzz  S_scalzz_191_2 = {&B3IP02IDU,&iRM_819_,&iRM_4095_,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&var1625,&internal2_m191_y0};
_S_scalzz  S_scalzz_189_2 = {&A3IP02IDU,&iRM_819_,&iRM_4095_,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&var1626,&internal2_m189_y0};
_S_noto  S_noto_169_2 = {&var1628,&var1627};
_S_andn  S_andn_168_2 = {array_m168_x_2,&iRM_17_,&var1628};
_S_noto  S_noto_151_2 = {&var1630,&var1629};
_S_andn  S_andn_148_2 = {array_m148_x_2,&iRM_6_,&var1630};
_S_noto  S_noto_138_2 = {&var1632,&var1631};
_S_andn  S_andn_132_2 = {array_m132_x_2,&iRM_6_,&var1632};
_S_noto  S_noto_257_2 = {&var1641,&var1633};
_S_noto  S_noto_239_2 = {&var1642,&var1634};
_S_noto  S_noto_216_2 = {&var1650,&var1635};
_S_noto  S_noto_224_2 = {&var1647,&var1636};
_S_noto  S_noto_155_2 = {&var1603,&var1637};
_S_noto  S_noto_140_2 = {&var1605,&var1638};
_S_noto  S_noto_260_2 = {&var1643,&var1639};
_S_noto  S_noto_244_2 = {&var1644,&var1640};
_S_ornc  S_ornc_250_2 = {array_m250_x_2,&iRM_6_,&var1641,&vainSChar};
_S_ornc  S_ornc_236_2 = {array_m236_x_2,&iRM_6_,&var1642,&vainSChar};
_S_ornc  S_ornc_259_2 = {array_m259_x_2,&iRM_6_,&var1643,&vainSChar};
_S_ornc  S_ornc_238_2 = {array_m238_x_2,&iRM_6_,&var1644,&vainSChar};
_S_tprg  S_tprg_219_2 = {&var1625,&fEM_A3UP85RDU,&fEM_A3UP86RDU,&fEM_A3UP87RDU,&fEM_A3UP88RDU,&var1645,&internal2_m219_y0};
_S_tprg  S_tprg_214_2 = {&var1626,&fEM_A3UP85RDU,&fEM_A3UP86RDU,&fEM_A3UP87RDU,&fEM_A3UP88RDU,&var1646,&internal2_m214_y0};
_S_geterr  S_geterr_195_2 = {&var1625,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var1647};
_S_drg  S_drg_203_2 = {&var1625,&lRM_1_,&lRM_0_,&fEM_A3UP43RDU,&fEM_A3UP44RDU,&var1648,&internal2_m203_y1};
_S_drg  S_drg_209_2 = {&var1625,&lRM_1_,&lRM_0_,&fEM_A3UP53RDU,&fEM_A3UP54RDU,&var1649,&internal2_m209_y1};
_S_geterr  S_geterr_192_2 = {&var1626,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var1650};
_S_drg  S_drg_193_2 = {&var1626,&lRM_1_,&lRM_0_,&fEM_A3UP43RDU,&fEM_A3UP44RDU,&var1651,&internal2_m193_y1};
_S_drg  S_drg_200_2 = {&var1626,&lRM_1_,&lRM_0_,&fEM_A3UP53RDU,&fEM_A3UP54RDU,&var1652,&internal2_m200_y1};
_S_lkz  S_lkz_24_2 = {&iRM_1_,&var1617,&var1653};
_S_enctkb  S_enctkb_17_2 = {&var1653,&fRM_0_0,&A1IC01UDU,&dEM_A1UC06UDU,&dEM_A1UC05UDU,&fEM_A1UC03RDU,&fRM_100_0,&dRM_0_,&var1654,&var1655,&var1656,&internal2_m17_Nk0,&internal2_m17_SetFlag,&bFirstEnterFlag};
_S_lkz  S_lkz_107_2 = {&iRM_1_,&var1609,&var1657};
_S_enctkb  S_enctkb_108_2 = {&var1657,&fRM_390_,&B8IC01UDU,&dEM_A8UC06UDU,&dEM_A8UC05UDU,&fEM_A8UC03RDU,&fRM_1500_0,&dRM_0_,&var1658,&var1659,&var1660,&internal2_m108_Nk0,&internal2_m108_SetFlag,&bFirstEnterFlag};
_S_lkz  S_lkz_111_2 = {&iRM_1_,&var1606,&var1661};
_S_enctkb  S_enctkb_112_2 = {&var1661,&fRM_390_0,&A8IC01UDU,&dEM_A8UC06UDU,&dEM_A8UC05UDU,&fEM_A8UC03RDU,&fRM_1500_0,&dRM_0_,&var1662,&var1663,&var1664,&internal2_m112_Nk0,&internal2_m112_SetFlag,&bFirstEnterFlag};
_S_lkz  S_lkz_80_2 = {&iRM_1_,&var1610,&var1665};
_S_enctkb  S_enctkb_75_2 = {&var1665,&fRM_0_,&B3IC01UDU,&dEM_A3UC06UDU,&dEM_A3UC05UDU,&fEM_A3UC03RDU,&fRM_0_0,&dRM_0_,&var1666,&var1667,&var1668,&internal2_m75_Nk0,&internal2_m75_SetFlag,&bFirstEnterFlag};
_S_lkz  S_lkz_83_2 = {&iRM_1_,&var1613,&var1669};
_S_enctkb  S_enctkb_77_2 = {&var1669,&fRM_0_0,&A3IC01UDU,&dEM_A3UC06UDU,&dEM_A3UC05UDU,&fEM_A3UC03RDU,&fRM_0_0,&dRM_0_,&var1670,&var1671,&var1672,&internal2_m77_Nk0,&internal2_m77_SetFlag,&bFirstEnterFlag};
_S_lkz  S_lkz_49_2 = {&iRM_1_,&var1619,&var1673};
_S_enctkb  S_enctkb_45_2 = {&var1673,&fRM_0_0,&B2IC01UDU,&dEM_A2UC06UDU,&dEM_A2UC05UDU,&fEM_A2UC03RDU,&fRM_100_0,&dRM_0_,&var1674,&var1675,&var1676,&internal2_m45_Nk0,&internal2_m45_SetFlag,&bFirstEnterFlag};
_S_lkz  S_lkz_52_2 = {&iRM_1_,&var1615,&var1677};
_S_enctkb  S_enctkb_53_2 = {&var1677,&fRM_0_0,&A2IC01UDU,&dEM_A2UC06UDU,&dEM_A2UC05UDU,&fEM_A2UC03RDU,&fRM_100_0,&dRM_0_,&var1678,&var1679,&var1680,&internal2_m53_Nk0,&internal2_m53_SetFlag,&bFirstEnterFlag};
_S_equz_p  S_equz_p_19_2 = {&R0MW12IP1,&iRM_4_,&var1681};
_S_lkz  S_lkz_21_2 = {&iRM_1_,&var1621,&var1682};
_S_enctkb  S_enctkb_15_2 = {&var1682,&fRM_0_0,&B1IC01UDU,&dEM_A1UC06UDU,&dEM_A1UC05UDU,&fEM_A1UC03RDU,&fRM_100_0,&dRM_0_,&var1683,&var1684,&var1685,&internal2_m15_Nk0,&internal2_m15_SetFlag,&bFirstEnterFlag};
_S_ornc  S_ornc_123_2 = {array_m123_x_2,&iRM_8_,&var1686,&vainSChar};
_S_or2  S_or2_1073_1 = {&var910,&R0MD34LP1,&var1};
_S_or2  S_or2_1076_1 = {&var908,&R0MD34LP1,&var2};
_S_or2  S_or2_1079_1 = {&var906,&R0MD34LP1,&var3};
_S_or2  S_or2_1082_1 = {&var904,&R0MD34LP1,&var4};
_S_noto  S_noto_2132_1 = {&var1583,&var5};
_S_zzfs  S_zzfs_2122_1 = {&var23,&fRM_0_5,&var6,&internal1_m2122_tx,&internal1_m2122_y0};
_S_or2  S_or2_2155_1 = {&var223,&var912,&var7};
_S_andn  S_andn_587_1 = {array_m587_x_1,&iRM_6_,&var8};
_S_andn  S_andn_586_1 = {array_m586_x_1,&iRM_6_,&var9};
_S_or2  S_or2_2171_1 = {&var579,&var539,&var10};
_S_noto  S_noto_2117_1 = {&var938,&var11};
_S_noto  S_noto_2116_1 = {&var935,&var12};
_S_zpfs  S_zpfs_2125_1 = {&var11,&fRM_30_0,&var13,&internal1_m2125_tx,&internal1_m2125_y0};
_S_noto  S_noto_2130_1 = {&var13,&var14};
_S_zpfs  S_zpfs_2124_1 = {&var12,&fRM_30_0,&var15,&internal1_m2124_tx,&internal1_m2124_y0};
_S_noto  S_noto_2129_1 = {&var15,&var16};
_S_and3  S_and3_2119_1 = {&var61,&var36,&lRM_1_,&var17};
_S_and2  S_and2_909_1 = {&var1288,&var19,&var18};
_S_noto  S_noto_897_1 = {&var6,&var19};
_S_and2  S_and2_1311_1 = {&var1256,&var21,&var20};
_S_noto  S_noto_1308_1 = {&var6,&var21};
_S_or2  S_or2_2165_1 = {&var32,&var33,&var22};
_S_and2  S_and2_2121_1 = {&var24,&var17,&var23};
_S_abs_subf  S_abs_subf_2112_1 = {&var1670,&var62,&fEM_A3UC08RDU,&vainSFloat,&var24};
_S_and2  S_and2_2167_1 = {&var17,&var32,&var25};
_S_or4  S_or4_1962_1 = {&C2MD31LP1,&var711,&var823,&var25,&var26};
_S_noto  S_noto_2170_1 = {&var10,&var27};
_S_or2  S_or2_2146_1 = {&var53,&var66,&var28};
_S_inf  S_inf_2140_1 = {&var64,array_m2140_a_1,array_m2140_b_1,&iRM_6_,&var29,&vainSInt};
_S_or3  S_or3_2169_1 = {&var49,&var56,&var57,&var30};
_S_noto  S_noto_2168_1 = {&var30,&var31};
_S_noto  S_noto_2166_1 = {&var61,&var32};
_S_ovbs  S_ovbs_2161_1 = {&var35,&fRM_15_0,&var33,&internal1_m2161_tx};
_S_zpfs  S_zpfs_2159_1 = {&var36,&fRM_10_0,&var34,&internal1_m2159_tx,&internal1_m2159_y0};
_S_and2  S_and2_2160_1 = {&var34,&R0MW17LP1,&var35};
_S_rs  S_rs_2164_1 = {&var22,&R0MW17LP1,&var36,&vainSBool,&internal1_m2164_q0};
_S_rs  S_rs_2131_1 = {&var53,&var17,&var37,&vainSBool,&internal1_m2131_q0};
_S_and3  S_and3_2138_1 = {&var55,&var5,&var37,&var38};
_S_or3  S_or3_1294_1 = {&var675,&var154,&var6,&var39};
_S_ml  S_ml_1288_1 = {&var62,&var179,&var6,&var40};
_S_or3  S_or3_889_1 = {&var685,&var1127,&var6,&var41};
_S_ml  S_ml_883_1 = {&var62,&var183,&var6,&var42};
_S_and2  S_and2_2185_1 = {&var17,&var196,&var43};
_S_and2  S_and2_2032_1 = {&var17,&var347,&var44};
_S_noto  S_noto_2152_1 = {&var7,&var45};
_S_noto  S_noto_2136_1 = {&var1227,&var46};
_S_sr  S_sr_2153_1 = {array_m2153_x_1,&iRM_4_,&var47};
_S_sr  S_sr_2175_1 = {array_m2175_x_1,&iRM_2_,&var48};
_S_and2  S_and2_2189_1 = {&var50,&var17,&var49};
_S_abs_subf  S_abs_subf_2184_1 = {&B3MC01RP1,&A3MC01RP1,&fRM_0_01,&vainSFloat,&var50};
_S_fsumo  S_fsumo_79_1 = {&var888,&fEM_R0UN11RDU,&var51};
_S_or3  S_or3_124_1 = {&var240,&var808,&var28,&var52};
_S_ovbs  S_ovbs_2139_1 = {&var38,&fRM_1_0,&var53,&internal1_m2139_tx};
_S_noto  S_noto_2145_1 = {&var28,&var54};
_S_rs  S_rs_2137_1 = {&var53,&var1583,&var55,&vainSBool,&internal1_m2137_q0};
_S_and2  S_and2_2188_1 = {&var66,&var17,&var56};
_S_and2  S_and2_2187_1 = {&var58,&var17,&var57};
_S_bol  S_bol_2177_1 = {&fEM_R0UN09RDU,&var48,&var58};
_S_or2  S_or2_2033_1 = {&var351,&var17,&var59};
_S_or2  S_or2_2024_1 = {&var349,&var17,&var60};
_S_andn  S_andn_2144_1 = {array_m2144_x_1,&iRM_14_,&var61};
_S_irm  S_irm_2120_1 = {&var888,&var886,&B3MC01RP1,&var1670,&var48,&var47,&var17,&fEM_R0UN12RDU,&fEM_R0UN13RDU,&fEM_R0UN14RDU,&fEM_R0UT20RDU,&var29,&fEM_R0UN15RDU,&fEM_R0UN25RDU,&fEM_R0UN16RDU,&fEM_R0UN17RDU,&fEM_R0UN18RDU,&fEM_R0UN19RDU,&fEM_R0UN27RDU,&fEM_R0UN26RDU,&fEM_R0UN24RDU,&var62,&var63,&var64,&var65,&var66,&var67,&var68,&var69};
_S_noto  S_noto_2018_1 = {&var211,&var70};
_S_noto  S_noto_1990_1 = {&var212,&var71};
_S_and4  S_and4_2012_1 = {&var234,&var199,&var202,&var70,&var72};
_S_and4  S_and4_1992_1 = {&var233,&var204,&var202,&var71,&var73};
_S_zpfs  S_zpfs_2007_1 = {&var218,&fRM_210_0,&var74,&internal1_m2007_tx,&internal1_m2007_y0};
_S_zpfs  S_zpfs_1999_1 = {&var219,&fRM_210_0,&var75,&internal1_m1999_tx,&internal1_m1999_y0};
_S_and2  S_and2_551_1 = {&var1303,&var272,&var76};
_S_and2  S_and2_227_1 = {&var272,&var1336,&var77};
_S_noto  S_noto_1551_1 = {&var79,&var78};
_S_abs_subf  S_abs_subf_1543_1 = {&var1666,&var179,&fEM_A3UC07RDU,&vainSFloat,&var79};
_S_noto  S_noto_1532_1 = {&var81,&var80};
_S_abs_subf  S_abs_subf_1521_1 = {&var183,&var1670,&fEM_A3UC07RDU,&vainSFloat,&var81};
_S_noto  S_noto_1547_1 = {&var83,&var82};
_S_abs_subf  S_abs_subf_1541_1 = {&var187,&var1683,&fEM_A1UC07RDU,&vainSFloat,&var83};
_S_noto  S_noto_1527_1 = {&var85,&var84};
_S_abs_subf  S_abs_subf_1520_1 = {&var191,&var1654,&fEM_A1UC07RDU,&vainSFloat,&var85};
_S_bol  S_bol_1307_1 = {&var1666,&fEM_A3UC09RDU,&var86};
_S_bol  S_bol_905_1 = {&var1670,&fEM_A3UC09RDU,&var87};
_S_noto  S_noto_1766_1 = {&var92,&var88};
_S_noto  S_noto_1755_1 = {&var90,&var89};
_S_and3  S_and3_1748_1 = {&var817,&var91,&var1137,&var90};
_S_bol  S_bol_1740_1 = {&fRM_55_0,&var1666,&var91};
_S_and3  S_and3_1767_1 = {&var93,&var816,&var1137,&var92};
_S_bol  S_bol_1776_1 = {&fRM_55_0,&var1670,&var93};
_S_and4  S_and4_45_1 = {&var1574,&var815,&var997,&var1112,&var94};
_S_noto  S_noto_1221_1 = {&var868,&var95};
_S_and2  S_and2_1226_1 = {&var1403,&var868,&var96};
_S_and2  S_and2_1222_1 = {&var1403,&var95,&var97};
_S_noto  S_noto_1171_1 = {&var868,&var98};
_S_and2  S_and2_1176_1 = {&var868,&var1477,&var99};
_S_and2  S_and2_1168_1 = {&var1477,&var98,&var100};
_S_noto  S_noto_914_1 = {&var868,&var101};
_S_and2  S_and2_915_1 = {&var101,&var1259,&var102};
_S_and2  S_and2_911_1 = {&var1259,&var868,&var103};
_S_noto  S_noto_465_1 = {&var868,&var104};
_S_and2  S_and2_466_1 = {&var104,&var1352,&var105};
_S_and2  S_and2_467_1 = {&var1352,&var868,&var106};
_S_noto  S_noto_185_1 = {&var868,&var107};
_S_and2  S_and2_186_1 = {&var107,&var1322,&var108};
_S_and2  S_and2_189_1 = {&var868,&var1322,&var109};
_S_and2  S_and2_118_1 = {&var112,&var261,&var110};
_S_and2  S_and2_119_1 = {&var868,&var261,&var111};
_S_noto  S_noto_113_1 = {&var868,&var112};
_S_and2  S_and2_114_1 = {&var112,&var260,&var113};
_S_and2  S_and2_115_1 = {&var868,&var260,&var114};
_S_and3  S_and3_948_1 = {&var868,&var1137,&var114,&var115};
_S_or4  S_or4_2053_1 = {&var354,&var549,&var1123,&var1583,&var116};
_S_or4  S_or4_2051_1 = {&var278,&var1125,&var356,&var1583,&var117};
_S_and2  S_and2_1624_1 = {&var165,&var1141,&var118};
_S_and2  S_and2_1623_1 = {&var168,&var1141,&var119};
_S_and2  S_and2_1622_1 = {&var166,&var1141,&var120};
_S_and2  S_and2_1621_1 = {&var1141,&var169,&var121};
_S_and2  S_and2_1620_1 = {&var412,&var167,&var122};
_S_and2  S_and2_1619_1 = {&var412,&var170,&var123};
_S_and2  S_and2_1618_1 = {&var413,&var167,&var124};
_S_and2  S_and2_1617_1 = {&var413,&var170,&var125};
_S_and2  S_and2_1648_1 = {&var1101,&var1088,&var126};
_S_and2  S_and2_1647_1 = {&var165,&var1142,&var127};
_S_and2  S_and2_1646_1 = {&var1089,&var96,&var128};
_S_or2  S_or2_1659_1 = {&var130,&var165,&var129};
_S_zpfs  S_zpfs_1664_1 = {&var1146,&fRM_3_0,&var130,&internal1_m1664_tx,&internal1_m1664_y0};
_S_and2  S_and2_1645_1 = {&var1142,&var168,&var131};
_S_and2  S_and2_1644_1 = {&var1102,&var1090,&var132};
_S_and2  S_and2_1643_1 = {&var1142,&var166,&var133};
_S_or2  S_or2_1652_1 = {&var135,&var166,&var134};
_S_zpfs  S_zpfs_1663_1 = {&var1166,&fRM_3_0,&var135,&internal1_m1663_tx,&internal1_m1663_y0};
_S_and2  S_and2_1642_1 = {&var1091,&var96,&var136};
_S_and2  S_and2_1641_1 = {&var1142,&var169,&var137};
_S_and2  S_and2_1676_1 = {&var96,&var1092,&var138};
_S_and2  S_and2_1675_1 = {&var165,&var1140,&var139};
_S_and2  S_and2_1674_1 = {&var1093,&var99,&var140};
_S_and2  S_and2_1673_1 = {&var168,&var1140,&var141};
_S_and2  S_and2_1672_1 = {&var96,&var1094,&var142};
_S_and2  S_and2_1671_1 = {&var166,&var1140,&var143};
_S_and2  S_and2_1670_1 = {&var1095,&var99,&var144};
_S_and2  S_and2_1669_1 = {&var169,&var1140,&var145};
_S_and2  S_and2_1696_1 = {&var1137,&var165,&var146};
_S_and2  S_and2_1695_1 = {&var1137,&var168,&var147};
_S_and2  S_and2_1694_1 = {&var166,&var1137,&var148};
_S_and2  S_and2_1693_1 = {&var1137,&var169,&var149};
_S_rs  S_rs_1703_1 = {&var103,&var151,&var150,&vainSBool,&internal1_m1703_q0};
_S_and2  S_and2_1692_1 = {&var1138,&var165,&var151};
_S_and2  S_and2_1691_1 = {&var1138,&var168,&var152};
_S_or2  S_or2_1702_1 = {&var103,&var165,&var153};
_S_rs  S_rs_1701_1 = {&var153,&var152,&var154,&vainSBool,&internal1_m1701_q0};
_S_rs  S_rs_1700_1 = {&var103,&var156,&var155,&vainSBool,&internal1_m1700_q0};
_S_and2  S_and2_1690_1 = {&var166,&var1138,&var156};
_S_and2  S_and2_1689_1 = {&var1138,&var169,&var157};
_S_and2  S_and2_1719_1 = {&var167,&var1576,&var158};
_S_rs  S_rs_1728_1 = {&var106,&var158,&var159,&vainSBool,&internal1_m1728_q0};
_S_and2  S_and2_1718_1 = {&var1576,&var170,&var160};
_S_and2  S_and2_1717_1 = {&var165,&var1119,&var161};
_S_and2  S_and2_1716_1 = {&var1119,&var168,&var162};
_S_and2  S_and2_1715_1 = {&var166,&var1119,&var163};
_S_and2  S_and2_1714_1 = {&var1119,&var169,&var164};
_S_and2  S_and2_1730_1 = {&var817,&var167,&var165};
_S_and2  S_and2_1713_1 = {&var816,&var167,&var166};
_S_and2  S_and2_1732_1 = {&var111,&var1182,&var167};
_S_and2  S_and2_1729_1 = {&var170,&var817,&var168};
_S_and2  S_and2_1712_1 = {&var170,&var816,&var169};
_S_and2  S_and2_1731_1 = {&var114,&var1182,&var170};
_S_zpfs  S_zpfs_742_1 = {&var780,&fRM_3_,&var171,&internal1_m742_tx,&internal1_m742_y0};
_S_or4  S_or4_1563_1 = {&var397,&var398,&var399,&var401,&var172};
_S_or5  S_or5_1553_1 = {&var405,&var404,&var403,&var402,&var172,&var173};
_S_andn  S_andn_1_1 = {array_m1_x_1,&iRM_47_,&vainSBool};
_S_or2  S_or2_1534_1 = {&var176,&var177,&var174};
_S_ml  S_ml_1519_1 = {&fRM_1500_0,&B8MC01RP2,&var174,&var175};
_S_bol  S_bol_1530_1 = {&B8MC01RP2,&fRM_1500_0001,&var176};
_S_bol  S_bol_1536_1 = {&fRM_389_99,&B8MC01RP2,&var177};
_S_or2  S_or2_1549_1 = {&var180,&var181,&var178};
_S_ml  S_ml_1540_1 = {&fRM_0_0,&B3MC01RP1,&var178,&var179};
_S_bol  S_bol_1542_1 = {&B3MC01RP1,&fRM_160_00001,&var180};
_S_bol  S_bol_1550_1 = {&fRM_0_0001,&B3MC01RP1,&var181};
_S_or2  S_or2_1529_1 = {&var184,&var185,&var182};
_S_ml  S_ml_1518_1 = {&fRM_0_0,&A3MC01RP1,&var182,&var183};
_S_bol  S_bol_1524_1 = {&A3MC01RP1,&fRM_160_0001,&var184};
_S_bol  S_bol_1531_1 = {&fRM_0_0001,&A3MC01RP1,&var185};
_S_or2  S_or2_1546_1 = {&var188,&var189,&var186};
_S_ml  S_ml_1538_1 = {&fRM_100_0,&B1MC01RP1,&var186,&var187};
_S_bol  S_bol_1544_1 = {&B1MC01RP1,&fRM_100_0001,&var188};
_S_bol  S_bol_1552_1 = {&fRM_0_0001,&B1MC01RP1,&var189};
_S_or2  S_or2_1526_1 = {&var192,&var193,&var190};
_S_ml  S_ml_1516_1 = {&fRM_100_0,&A1MC01RP1,&var190,&var191};
_S_bol  S_bol_1523_1 = {&A1MC01RP1,&fRM_100_0001,&var192};
_S_bol  S_bol_1535_1 = {&fRM_0_0001,&A1MC01RP1,&var193};
_S_and2  S_and2_101_1 = {&R0MD11LP1,&R4IS12LDU,&var194};
_S_noto  S_noto_102_1 = {&R4IS12LDU,&var195};
_S_and2  S_and2_104_1 = {&R0MD11LP1,&var195,&var196};
_S_and2  S_and2_1979_1 = {&var198,&var201,&var197};
_S_or3  S_or3_1978_1 = {&var1144,&var340,&var26,&var198};
_S_or3  S_or3_2011_1 = {&var8,&var1146,&var939,&var199};
_S_ovbs  S_ovbs_2013_1 = {&var72,&fRM_2_0,&var200,&internal1_m2013_tx};
_S_noto  S_noto_2014_1 = {&var200,&var201};
_S_noto  S_noto_2004_1 = {&var203,&var202};
_S_ovbs  S_ovbs_2003_1 = {&var1009,&fRM_2_0,&var203,&internal1_m2003_tx};
_S_or3  S_or3_1991_1 = {&var9,&var940,&var1166,&var204};
_S_ovbs  S_ovbs_1993_1 = {&var73,&fRM_2_0,&var205,&internal1_m1993_tx};
_S_noto  S_noto_1994_1 = {&var205,&var206};
_S_and2  S_and2_1964_1 = {&var208,&var206,&var207};
_S_or3  S_or3_1963_1 = {&var26,&var1148,&var340,&var208};
_S_noto  S_noto_2009_1 = {&var216,&var209};
_S_and2  S_and2_2010_1 = {&var1112,&var209,&var210};
_S_and2  S_and2_2017_1 = {&var210,&var199,&var211};
_S_and2  S_and2_1997_1 = {&var213,&var204,&var212};
_S_and2  S_and2_2002_1 = {&var214,&var1112,&var213};
_S_noto  S_noto_2001_1 = {&var807,&var214};
_S_noto  S_noto_2016_1 = {&var218,&var215};
_S_or2  S_or2_2008_1 = {&var74,&var215,&var216};
_S_noto  S_noto_1996_1 = {&var219,&var217};
_S_rs  S_rs_2006_1 = {&var74,&var224,&var218,&vainSBool,&internal1_m2006_q0};
_S_rs  S_rs_1998_1 = {&var75,&var225,&var219,&vainSBool,&internal1_m1998_q0};
_S_and2  S_and2_1988_1 = {&var222,&var229,&var220};
_S_and2  S_and2_1976_1 = {&var222,&var226,&var221};
_S_noto  S_noto_1970_1 = {&var223,&var222};
_S_ovbs  S_ovbs_1969_1 = {&var26,&fRM_10_0,&var223,&internal1_m1969_tx};
_S_ovbs  S_ovbs_1980_1 = {&var197,&fRM_2_0,&var224,&internal1_m1980_tx};
_S_ovbs  S_ovbs_1965_1 = {&var207,&fRM_2_0,&var225,&internal1_m1965_tx};
_S_or2  S_or2_1975_1 = {&var262,&var873,&var226};
_S_or2  S_or2_1971_1 = {&var263,&var207,&var227};
_S_or2  S_or2_1983_1 = {&var263,&var197,&var228};
_S_or2  S_or2_1987_1 = {&var262,&var870,&var229};
_S_rs  S_rs_1972_1 = {&var221,&var227,&var230,&vainSBool,&internal1_m1972_q0};
_S_noto  S_noto_1985_1 = {&var232,&var231};
_S_rs  S_rs_1984_1 = {&var220,&var228,&var232,&vainSBool,&internal1_m1984_q0};
_S_noto  S_noto_1973_1 = {&var230,&var233};
_S_noto  S_noto_1981_1 = {&var224,&var234};
_S_noto  S_noto_1966_1 = {&var225,&var235};
_S_and2  S_and2_1960_1 = {&var238,&var346,&var236};
_S_and2  S_and2_1950_1 = {&var238,&var343,&var237};
_S_noto  S_noto_1944_1 = {&var239,&var238};
_S_ovbs  S_ovbs_1943_1 = {&var240,&fRM_3_0,&var239,&internal1_m1943_tx};
_S_or2  S_or2_1941_1 = {&C1MD31LP1,&C1MD31LP2,&var240};
_S_or2  S_or2_1474_1 = {&var1057,&var269,&var241};
_S_and2  S_and2_435_1 = {&var1548,&var1490,&var242};
_S_and2  S_and2_1829_1 = {&var1082,&B7AS31LDU,&var243};
_S_and2  S_and2_446_1 = {&var816,&var659,&var244};
_S_and2  S_and2_438_1 = {&var660,&var816,&var245};
_S_and2  S_and2_475_1 = {&var659,&var817,&var246};
_S_and2  S_and2_471_1 = {&var660,&var817,&var247};
_S_or2  S_or2_2084_1 = {&R3IS21LDU,&R3IS41LDU,&var248};
_S_or2  S_or2_2099_1 = {&R3IS31LDU,&R3IS11LDU,&var249};
_S_or4  S_or4_2092_1 = {&var1025,&var1023,&var1024,&var1026,&var250};
_S_or4  S_or4_2097_1 = {&var1018,&var1019,&var1016,&var1017,&var251};
_S_or2  S_or2_348_1 = {&var1561,&var787,&var252};
_S_or2  S_or2_344_1 = {&var1561,&var786,&var253};
_S_ovbs  S_ovbs_51_1 = {&var1573,&fRM_15_0,&var254,&internal1_m51_tx};
_S_ovbs  S_ovbs_327_1 = {&var1030,&fRM_0_02,&var255,&internal1_m327_tx};
_S_ovbs  S_ovbs_285_1 = {&var1032,&fRM_0_02,&var256,&internal1_m285_tx};
_S_ovbs  S_ovbs_743_1 = {&var171,&fRM_0_2,&var257,&internal1_m743_tx};
_S_ovbs  S_ovbs_1419_1 = {&R0MD31LP1,&fRM_10_0,&var258,&internal1_m1419_tx};
_S_ovbs  S_ovbs_110_1 = {&R0MD31LP1,&fRM_0_15,&var259,&internal1_m110_tx};
_S_ovbs  S_ovbs_112_1 = {&var196,&fRM_0_02,&var260,&internal1_m112_tx};
_S_ovbs  S_ovbs_117_1 = {&R0MD32LP1,&fRM_0_02,&var261,&internal1_m117_tx};
_S_ovbs  S_ovbs_21_1 = {&var1112,&fRM_3_0,&var262,&internal1_m21_tx};
_S_ovbs  S_ovbs_13_1 = {&var868,&fRM_3_0,&var263,&internal1_m13_tx};
_S_ovbs  S_ovbs_1951_1 = {&var240,&fRM_2_0,&var264,&internal1_m1951_tx};
_S_ovbs  S_ovbs_1938_1 = {&var240,&fRM_2_0,&var265,&internal1_m1938_tx};
_S_ovbs  S_ovbs_2036_1 = {&var1125,&fRM_2_0,&var266,&internal1_m2036_tx};
_S_ovbs  S_ovbs_2039_1 = {&var1123,&fRM_2_0,&var267,&internal1_m2039_tx};
_S_ovbs  S_ovbs_1865_1 = {&var280,&fRM_0_01,&var268,&internal1_m1865_tx};
_S_ovbs  S_ovbs_76_1 = {&R0MW13LP2,&fRM_10_0,&var269,&internal1_m76_tx};
_S_zpfs  S_zpfs_298_1 = {&var717,&fRM_10_0,&var270,&internal1_m298_tx,&internal1_m298_y0};
_S_or2  S_or2_1032_1 = {&var929,&var476,&var271};
_S_or2  S_or2_228_1 = {&A1VN71LZ1,&A1VN71LZ2,&var272};
_S_or2  S_or2_242_1 = {&var611,&var885,&var273};
_S_or5  S_or5_142_1 = {&B1IS21LDU,&B3IS21LDU,&B2IS21LDU,&var855,&var856,&var274};
_S_and2  S_and2_1029_1 = {&var1398,&var1000,&var275};
_S_or3  S_or3_987_1 = {&var562,&var568,&var567,&var276};
_S_or3  S_or3_1387_1 = {&var548,&var546,&var540,&var277};
_S_and2  S_and2_964_1 = {&var1156,&var914,&var278};
_S_and3  S_and3_1860_1 = {&var296,&var281,&var289,&var279};
_S_or2  S_or2_1864_1 = {&var283,&var282,&var280};
_S_or3  S_or3_1862_1 = {&var283,&var282,&var292,&var281};
_S_zpfs  S_zpfs_1859_1 = {&var285,&fEM_R0UL02RDU,&var282,&internal1_m1859_tx,&internal1_m1859_y0};
_S_zpfs  S_zpfs_1857_1 = {&var286,&fEM_R0UL02RDU,&var283,&internal1_m1857_tx,&internal1_m1857_y0};
_S_or2  S_or2_1851_1 = {&var286,&var285,&var284};
_S_or2  S_or2_1852_1 = {&var287,&var1047,&var285};
_S_or2  S_or2_1850_1 = {&var288,&var1047,&var286};
_S_and3  S_and3_1844_1 = {&var1108,&var841,&var817,&var287};
_S_and3  S_and3_1843_1 = {&var1109,&var816,&var841,&var288};
_S_or2  S_or2_1841_1 = {&var1047,&var1046,&var289};
_S_or3  S_or3_1848_1 = {&var294,&var1046,&var292,&var290};
_S_and2  S_and2_1856_1 = {&var1047,&var281,&var291};
_S_and2  S_and2_1847_1 = {&var1038,&var293,&var292};
_S_zpfs  S_zpfs_1846_1 = {&var1047,&fEM_R0UL04RDU,&var293,&internal1_m1846_tx,&internal1_m1846_y0};
_S_and2  S_and2_1834_1 = {&var1041,&var459,&var294};
_S_or3  S_or3_1835_1 = {&var981,&var465,&var959,&var295};
_S_abs_subf  S_abs_subf_1868_1 = {&fEM_R0UL02RDU,&var297,&fEM_R0UL16RDU,&vainSFloat,&var296};
_S_rsfn  S_rsfn_1866_1 = {&var456,&var298,&var297,&internal1_m1866_q0};
_S_lk  S_lk_1863_1 = {&var1218,&var281,&var298};
_S_abs_subf  S_abs_subf_1448_1 = {&fEM_R0UL05RDU,&var300,&fEM_R0UL18RDU,&vainSFloat,&var299};
_S_rsfn  S_rsfn_1439_1 = {&var456,&var301,&var300,&internal1_m1439_q0};
_S_lk  S_lk_1443_1 = {&var1052,&var443,&var301};
_S_abs_subf  S_abs_subf_1489_1 = {&fEM_R0UL07RDU,&var303,&fEM_R0UL20RDU,&vainSFloat,&var302};
_S_rsfn  S_rsfn_1476_1 = {&var456,&var304,&var303,&internal1_m1476_q0};
_S_lk  S_lk_1480_1 = {&var1058,&var433,&var304};
_S_ma  S_ma_1461_1 = {array_m1461_x_1,&R0MW12IP2,&iRM_7_,&var305};
_S_abs_subf  S_abs_subf_1494_1 = {&var305,&var307,&fEM_R0UL19RDU,&vainSFloat,&var306};
_S_rsfn  S_rsfn_1479_1 = {&var456,&var308,&var307,&internal1_m1479_q0};
_S_lk  S_lk_1483_1 = {&var1216,&var424,&var308};
_S_and3  S_and3_1910_1 = {&var310,&var313,&var320,&var309};
_S_abs_subf  S_abs_subf_1907_1 = {&var311,&fEM_R0UL03RDU,&fEM_R0UL17RDU,&vainSFloat,&var310};
_S_rsfn  S_rsfn_1905_1 = {&var456,&var312,&var311,&internal1_m1905_q0};
_S_lk  S_lk_1900_1 = {&var1217,&var313,&var312};
_S_or3  S_or3_1899_1 = {&var318,&var324,&var323,&var313};
_S_and4  S_and4_1904_1 = {&var323,&var1223,&var336,&var334,&var314};
_S_and4  S_and4_1902_1 = {&var324,&var1223,&var336,&var334,&var315};
_S_and2  S_and2_1894_1 = {&var1050,&var313,&var316};
_S_and2  S_and2_1880_1 = {&var459,&var1040,&var317};
_S_and2  S_and2_1883_1 = {&var321,&var1039,&var318};
_S_or3  S_or3_1884_1 = {&var318,&var317,&var1049,&var319};
_S_or2  S_or2_1876_1 = {&var1050,&var1049,&var320};
_S_zpfs  S_zpfs_1882_1 = {&var1050,&fEM_R0UL21RDU,&var321,&internal1_m1882_tx,&internal1_m1882_y0};
_S_or3  S_or3_1873_1 = {&var461,&var985,&var963,&var322};
_S_zpfs  S_zpfs_1898_1 = {&var326,&fEM_R0UL03RDU,&var323,&internal1_m1898_tx,&internal1_m1898_y0};
_S_zpfs  S_zpfs_1895_1 = {&var327,&fEM_R0UL03RDU,&var324,&internal1_m1895_tx,&internal1_m1895_y0};
_S_or2  S_or2_1890_1 = {&var327,&var326,&var325};
_S_or2  S_or2_1891_1 = {&var328,&var1050,&var326};
_S_or2  S_or2_1889_1 = {&var329,&var1050,&var327};
_S_and4  S_and4_1888_1 = {&var1110,&var817,&B2IS12LDU,&var330,&var328};
_S_and4  S_and4_1887_1 = {&var1111,&A2IS12LDU,&var816,&var330,&var329};
_S_and2  S_and2_1881_1 = {&var841,&var334,&var330};
_S_and3  S_and3_1919_1 = {&var817,&var947,&var333,&var331};
_S_and3  S_and3_1918_1 = {&var816,&var948,&var333,&var332};
_S_and4  S_and4_1917_1 = {&var913,&var707,&var709,&var334,&var333};
_S_and2  S_and2_1911_1 = {&var720,&var914,&var334};
_S_or2  S_or2_1913_1 = {&var1227,&var912,&var335};
_S_or3  S_or3_1922_1 = {&var339,&var338,&var341,&var336};
_S_and2  S_and2_1912_1 = {&var951,&A2IS12LDU,&var337};
_S_and2  S_and2_1916_1 = {&var852,&var337,&var338};
_S_and3  S_and3_1921_1 = {&var1222,&var342,&var337,&var339};
_S_or2  S_or2_1930_1 = {&lRM_0_,&var335,&var340};
_S_and2  S_and2_1927_1 = {&var867,&var342,&var341};
_S_and2  S_and2_1929_1 = {&var950,&B2IS12LDU,&var342};
_S_or2  S_or2_1949_1 = {&var872,&var262,&var343};
_S_or2  S_or2_1945_1 = {&var263,&var240,&var344};
_S_or2  S_or2_1955_1 = {&var240,&var263,&var345};
_S_or2  S_or2_1959_1 = {&var262,&var871,&var346};
_S_or2  S_or2_2020_1 = {&var715,&var1126,&var347};
_S_or2  S_or2_2025_1 = {&var914,&var1150,&var348};
_S_zpfs  S_zpfs_2026_1 = {&var348,&fRM_15_0,&var349,&internal1_m2026_tx,&internal1_m2026_y0};
_S_or2  S_or2_2028_1 = {&var714,&var1124,&var350};
_S_zpfs  S_zpfs_2035_1 = {&var352,&fRM_15_0,&var351,&internal1_m2035_tx,&internal1_m2035_y0};
_S_or2  S_or2_2034_1 = {&var914,&var1149,&var352};
_S_or2  S_or2_2045_1 = {&var1121,&var314,&var353};
_S_and2  S_and2_2052_1 = {&var267,&var1112,&var354};
_S_or2  S_or2_2048_1 = {&var315,&var1122,&var355};
_S_and2  S_and2_2050_1 = {&var1112,&var266,&var356};
_S_and2  S_and2_1828_1 = {&var1083,&A7AS31LDU,&var357};
_S_or3  S_or3_1801_1 = {&var362,&var366,&var364,&var358};
_S_or3  S_or3_1802_1 = {&var365,&var364,&var361,&var359};
_S_or2  S_or2_1815_1 = {&B0VT71LZ1,&B0VT71LZ2,&var360};
_S_and2  S_and2_1806_1 = {&var367,&var360,&var361};
_S_and2  S_and2_1800_1 = {&var367,&var363,&var362};
_S_or2  S_or2_1799_1 = {&A0VT71LZ1,&A0VT71LZ2,&var363};
_S_zpfs  S_zpfs_1796_1 = {&var1104,&fRM_2_5,&var364,&internal1_m1796_tx,&internal1_m1796_y0};
_S_zpfs  S_zpfs_1795_1 = {&var1105,&fRM_2_5,&var365,&internal1_m1795_tx,&internal1_m1795_y0};
_S_zpfs  S_zpfs_1794_1 = {&var1106,&fRM_2_5,&var366,&internal1_m1794_tx,&internal1_m1794_y0};
_S_zpfs  S_zpfs_1793_1 = {&var1107,&fRM_2_5,&var367,&internal1_m1793_tx,&internal1_m1793_y0};
_S_or2  S_or2_1824_1 = {&R0VP73LZ2,&R0VP73LZ1,&var368};
_S_and2  S_and2_1817_1 = {&var1123,&var1084,&var369};
_S_or2  S_or2_1814_1 = {&var372,&var369,&var370};
_S_or2  S_or2_1816_1 = {&var1121,&var1123,&var371};
_S_and2  S_and2_1813_1 = {&var1121,&var1074,&var372};
_S_and2  S_and2_1797_1 = {&var1125,&var1085,&var373};
_S_or2  S_or2_1798_1 = {&var376,&var373,&var374};
_S_or2  S_or2_1791_1 = {&var1122,&var1125,&var375};
_S_and2  S_and2_1790_1 = {&var1122,&var1075,&var376};
_S_or3  S_or3_1760_1 = {&var1179,&var1137,&var1138,&var377};
_S_or3  S_or3_1761_1 = {&var1177,&var1137,&var1138,&var378};
_S_or2  S_or2_1752_1 = {&var1172,&var1137,&var379};
_S_or2  S_or2_1753_1 = {&var1171,&var1137,&var380};
_S_or2  S_or2_1759_1 = {&var1181,&var1140,&var381};
_S_or4  S_or4_1757_1 = {&var1140,&var1178,&var1141,&var1142,&var382};
_S_or4  S_or4_1756_1 = {&var1140,&var1184,&var1141,&var1142,&var383};
_S_or2  S_or2_1750_1 = {&var1173,&var1142,&var384};
_S_or2  S_or2_1749_1 = {&var1174,&var1142,&var385};
_S_or2  S_or2_1758_1 = {&var1140,&var1180,&var386};
_S_or2  S_or2_1727_1 = {&var106,&var167,&var387};
_S_or2  S_or2_1724_1 = {&var165,&var109,&var388};
_S_or2  S_or2_1721_1 = {&var109,&var166,&var389};
_S_or2  S_or2_1708_1 = {&var1086,&var165,&var390};
_S_or2  S_or2_1705_1 = {&var166,&var1086,&var391};
_S_or2  S_or2_1699_1 = {&var103,&var166,&var392};
_S_or2  S_or2_1686_1 = {&var165,&var96,&var393};
_S_or2  S_or2_1684_1 = {&var165,&var99,&var394};
_S_or2  S_or2_1680_1 = {&var166,&var96,&var395};
_S_or2  S_or2_1678_1 = {&var99,&var166,&var396};
_S_and2  S_and2_1568_1 = {&var1441,&var1399,&var397};
_S_and2  S_and2_1567_1 = {&var1564,&var1399,&var398};
_S_and2  S_and2_1566_1 = {&var805,&var1399,&var399};
_S_or2  S_or2_1565_1 = {&B4IS11LDU,&A4IS11LDU,&var400};
_S_and2  S_and2_1564_1 = {&var400,&var1399,&var401};
_S_and2  S_and2_1557_1 = {&var1601,&var1399,&var402};
_S_and2  S_and2_1556_1 = {&R4IS12LDU,&var1399,&var403};
_S_and2  S_and2_1555_1 = {&var794,&var1399,&var404};
_S_and2  S_and2_1554_1 = {&var248,&var1399,&var405};
_S_or2  S_or2_1657_1 = {&var96,&var165,&var406};
_S_or2  S_or2_1650_1 = {&var96,&var166,&var407};
_S_or2  S_or2_1635_1 = {&var96,&var165,&var408};
_S_or2  S_or2_1632_1 = {&var96,&var166,&var409};
_S_or2  S_or2_1629_1 = {&var1190,&var167,&var410};
_S_or2  S_or2_1626_1 = {&var1190,&var167,&var411};
_S_or2  S_or2_1616_1 = {&var1577,&var1578,&var412};
_S_or2  S_or2_1615_1 = {&var1579,&var1577,&var413};
_S_or2  S_or2_2064_1 = {&var891,&R0MD34LP1,&var414};
_S_or3  S_or3_2070_1 = {&var1191,&var1193,&var1192,&var415};
_S_or3  S_or3_2061_1 = {&var1197,&var1199,&var1198,&var416};
_S_or2  S_or2_1603_1 = {&var1663,&var1399,&var417};
_S_or2  S_or2_1577_1 = {&var1442,&var1000,&var418};
_S_or5  S_or5_1123_1 = {&var1457,&var420,&var1468,&var1454,&var1455,&var419};
_S_or3  S_or3_1127_1 = {&var1462,&var1463,&var894,&var420};
_S_or5  S_or5_1591_1 = {&var173,&var422,&var1451,&var1443,&var1444,&var421};
_S_or3  S_or3_1594_1 = {&var893,&var1445,&var1446,&var422};
_S_and3  S_and3_1503_1 = {&var424,&var429,&var306,&var423};
_S_and2  S_and2_1506_1 = {&var425,&var1215,&var424};
_S_or3  S_or3_1505_1 = {&A3VZ13LZ2,&A3VZ13LZ1,&var428,&var425};
_S_zpfs  S_zpfs_1490_1 = {&var1215,&fRM_0_2,&var426,&internal1_m1490_tx,&internal1_m1490_y0};
_S_or3  S_or3_1492_1 = {&var1060,&var428,&var430,&var427};
_S_and2  S_and2_1491_1 = {&var1037,&var426,&var428};
_S_or2  S_or2_1481_1 = {&var1215,&var1060,&var429};
_S_and2  S_and2_1469_1 = {&var1042,&var459,&var430};
_S_or3  S_or3_1477_1 = {&var960,&var982,&var464,&var431};
_S_or3  S_or3_1499_1 = {&R0AD14LZ1,&R0AD14LZ2,&var435,&var432};
_S_and2  S_and2_1500_1 = {&var432,&var1057,&var433};
_S_zpfs  S_zpfs_1484_1 = {&var1057,&fEM_R0UL06RDU,&var434,&internal1_m1484_tx,&internal1_m1484_y0};
_S_and2  S_and2_1485_1 = {&var434,&var1036,&var435};
_S_or3  S_or3_1486_1 = {&var1055,&var435,&var438,&var436};
_S_or3  S_or3_1462_1 = {&var463,&var983,&var961,&var437};
_S_and2  S_and2_1464_1 = {&var1043,&var459,&var438};
_S_and3  S_and3_1502_1 = {&var302,&var433,&var446,&var439};
_S_zpfs  S_zpfs_1435_1 = {&var1054,&fEM_R0UL04RDU,&var440,&internal1_m1435_tx,&internal1_m1435_y0};
_S_and2  S_and2_1436_1 = {&var440,&var1035,&var441};
_S_and3  S_and3_1452_1 = {&var299,&var443,&var447,&var442};
_S_and2  S_and2_1446_1 = {&var444,&var1054,&var443};
_S_or3  S_or3_1445_1 = {&A3VZ15LZ1,&A3VZ15LZ2,&var441,&var444};
_S_or3  S_or3_1437_1 = {&var448,&var441,&var1053,&var445};
_S_or2  S_or2_1472_1 = {&var1057,&var1055,&var446};
_S_or2  S_or2_1433_1 = {&var1054,&var1053,&var447};
_S_and2  S_and2_1425_1 = {&var1044,&var459,&var448};
_S_or3  S_or3_1423_1 = {&var962,&var984,&var462,&var449};
_S_or2  S_or2_1398_1 = {&var1570,&var451,&var450};
_S_and2  S_and2_1397_1 = {&var452,&var1100,&var451};
_S_or2  S_or2_1396_1 = {&var865,&var814,&var452};
_S_or2  S_or2_1392_1 = {&var955,&var977,&var453};
_S_and2  S_and2_1390_1 = {&var1063,&var1064,&var454};
_S_and2  S_and2_1393_1 = {&var453,&var452,&var455};
_S_or5  S_or5_1394_1 = {&var256,&var255,&var454,&var455,&R0MD34LP1,&var456};
_S_orni  S_orni_1414_1 = {array_m1414_x_1,&iRM_5_,&var457,&var458};
_S_or5  S_or5_1416_1 = {&var1059,&var1034,&var456,&var965,&var258,&var459};
_S_and2  S_and2_1415_1 = {&var457,&var1210,&var460};
_S_or2  S_or2_1422_1 = {&var992,&var466,&var461};
_S_or2  S_or2_1418_1 = {&var991,&var467,&var462};
_S_or2  S_or2_1412_1 = {&var990,&var468,&var463};
_S_or2  S_or2_1410_1 = {&var989,&var469,&var464};
_S_or2  S_or2_1408_1 = {&var988,&var470,&var465};
_S_and2  S_and2_1421_1 = {&var1565,&var472,&var466};
_S_and2  S_and2_1417_1 = {&var1566,&var472,&var467};
_S_and2  S_and2_1411_1 = {&var1567,&var472,&var468};
_S_and2  S_and2_1409_1 = {&var1568,&var472,&var469};
_S_and2  S_and2_1407_1 = {&var1569,&var472,&var470};
_S_and2  S_and2_1401_1 = {&var1570,&var472,&var471};
_S_and2  S_and2_1395_1 = {&R0MD11LP2,&var868,&var472};
_S_and3  S_and3_1062_1 = {&var100,&var477,&var495,&var473};
_S_or2  S_or2_1026_1 = {&var1002,&var998,&var474};
_S_or2  S_or2_1053_1 = {&var998,&var932,&var475};
_S_and2  S_and2_1020_1 = {&var1408,&var999,&var476};
_S_and2  S_and2_1016_1 = {&var1227,&var497,&var477};
_S_or3  S_or3_1023_1 = {&var998,&var928,&var1001,&var478};
_S_and2  S_and2_1027_1 = {&var97,&var1227,&var479};
_S_and2  S_and2_1045_1 = {&var108,&var1227,&var480};
_S_and2  S_and2_1061_1 = {&var102,&var1227,&var481};
_S_and2  S_and2_1068_1 = {&var105,&var1227,&var482};
_S_and3  S_and3_1011_1 = {&var485,&var917,&var1227,&var483};
_S_and3  S_and3_1005_1 = {&var486,&var917,&var1227,&var484};
_S_and2  S_and2_1013_1 = {&var816,&var1226,&var485};
_S_and2  S_and2_1003_1 = {&var817,&var1226,&var486};
_S_and4  S_and4_1012_1 = {&var485,&var1227,&var925,&var915,&var487};
_S_and4  S_and4_1006_1 = {&var486,&var1227,&var925,&var915,&var488};
_S_and4  S_and4_1010_1 = {&var1227,&var485,&var493,&var916,&var489};
_S_and4  S_and4_1004_1 = {&var1227,&var486,&var493,&var916,&var490};
_S_and2  S_and2_997_1 = {&var926,&var1227,&var491};
_S_or4  S_or4_1000_1 = {&R0MD31LP1,&var1461,&var113,&var504,&var492};
_S_and3  S_and3_1046_1 = {&var927,&var926,&var925,&var493};
_S_and2  S_and2_1033_1 = {&var495,&var271,&var494};
_S_and2  S_and2_1036_1 = {&var924,&var493,&var495};
_S_or2  S_or2_1047_1 = {&var994,&var936,&var496};
_S_and2  S_and2_1055_1 = {&var498,&var496,&var497};
_S_or2  S_or2_1048_1 = {&var935,&var937,&var498};
_S_or2  S_or2_1049_1 = {&var934,&var935,&var499};
_S_or2  S_or2_1051_1 = {&var933,&var938,&var500};
_S_and2  S_and2_1052_1 = {&var499,&var500,&var501};
_S_or2  S_or2_1039_1 = {&var994,&var993,&var502};
_S_and2  S_and2_1040_1 = {&var502,&var930,&var503};
_S_and5  S_and5_993_1 = {&var505,&var1014,&var935,&var994,&var494,&var504};
_S_and2  S_and2_994_1 = {&var969,&var970,&var505};
_S_and2  S_and2_1238_1 = {&var1077,&var507,&var506};
_S_or2  S_or2_1234_1 = {&A2MD12LP1,&var508,&var507};
_S_and2  S_and2_1220_1 = {&A2MD11LP1,&var1096,&var508};
_S_or2  S_or2_1214_1 = {&var511,&B2MD12LP1,&var509};
_S_and2  S_and2_1218_1 = {&var509,&var1077,&var510};
_S_and2  S_and2_1208_1 = {&B2MD11LP1,&var1097,&var511};
_S_or2  S_or2_1202_1 = {&var693,&var1135,&var512};
_S_or3  S_or3_1197_1 = {&var1170,&var1165,&var678,&var513};
_S_or5  S_or5_1188_1 = {&var489,&var1147,&var1133,&var1169,&var911,&var514};
_S_or5  S_or5_1211_1 = {&var517,&var903,&var1438,&var1432,&var1433,&var515};
_S_or2  S_or2_1231_1 = {&var1679,&var1423,&var516};
_S_or3  S_or3_1284_1 = {&var1404,&var518,&var519,&var517};
_S_and2  S_and2_1278_1 = {&var1423,&var866,&var518};
_S_and2  S_and2_1277_1 = {&var813,&var1423,&var519};
_S_and3  S_and3_1276_1 = {&var274,&var852,&var534,&var520};
_S_and2  S_and2_1275_1 = {&R4IS12LDU,&var534,&var521};
_S_and3  S_and3_1271_1 = {&var840,&var887,&var534,&var522};
_S_and2  S_and2_1270_1 = {&var368,&var534,&var523};
_S_and2  S_and2_1258_1 = {&var1414,&var534,&var524};
_S_and2  S_and2_1245_1 = {&var1601,&var534,&var525};
_S_and2  S_and2_1260_1 = {&var808,&var534,&var526};
_S_and2  S_and2_1246_1 = {&var248,&var534,&var527};
_S_and2  S_and2_1261_1 = {&var530,&var534,&var528};
_S_and3  S_and3_1247_1 = {&var531,&var1413,&var534,&var529};
_S_or2  S_or2_1262_1 = {&var1406,&var1407,&var530};
_S_or2  S_or2_1249_1 = {&A4IS11LDU,&B4IS11LDU,&var531};
_S_and3  S_and3_1257_1 = {&var1140,&var114,&var868,&var532};
_S_and3  S_and3_1256_1 = {&var1142,&var114,&var868,&var533};
_S_or3  S_or3_1248_1 = {&var1424,&var533,&var532,&var534};
_S_and2  S_and2_1333_1 = {&var536,&var1077,&var535};
_S_or2  S_or2_1332_1 = {&var537,&B3MD12LP1,&var536};
_S_and2  S_and2_1321_1 = {&B3MD11LP1,&var1073,&var537};
_S_or2  S_or2_1324_1 = {&var1667,&var1241,&var538};
_S_or5  S_or5_1310_1 = {&var277,&var1251,&var1250,&var20,&var901,&var539};
_S_or5  S_or5_1384_1 = {&var547,&var1230,&var545,&var542,&var541,&var540};
_S_and2  S_and2_1372_1 = {&var1241,&var866,&var541};
_S_and2  S_and2_1371_1 = {&var1241,&var813,&var542};
_S_and2  S_and2_1382_1 = {&var882,&var1229,&var543};
_S_or2  S_or2_1376_1 = {&var543,&var883,&var544};
_S_and3  S_and3_1370_1 = {&var1087,&var544,&var555,&var545};
_S_and3  S_and3_1369_1 = {&var274,&var867,&var555,&var546};
_S_and2  S_and2_1380_1 = {&var1583,&var554,&var547};
_S_and2  S_and2_1368_1 = {&R4IS12LDU,&var555,&var548};
_S_and2  S_and2_1364_1 = {&var1154,&var914,&var549};
_S_or2  S_or2_1353_1 = {&var1232,&var1231,&var550};
_S_and2  S_and2_1352_1 = {&var550,&var555,&var551};
_S_and2  S_and2_1351_1 = {&var808,&var555,&var552};
_S_and2  S_and2_1349_1 = {&var1234,&var555,&var553};
_S_and3  S_and3_1348_1 = {&var1137,&var114,&var868,&var554};
_S_or2  S_or2_1340_1 = {&var1243,&var554,&var555};
_S_or2  S_or2_1341_1 = {&B4IS11LDU,&A4IS11LDU,&var556};
_S_and3  S_and3_1339_1 = {&var1233,&var556,&var555,&var557};
_S_and2  S_and2_1338_1 = {&var248,&var555,&var558};
_S_and2  S_and2_1337_1 = {&var1601,&var555,&var559};
_S_and2  S_and2_980_1 = {&var1583,&var115,&var560};
_S_and2  S_and2_982_1 = {&var880,&var1261,&var561};
_S_or5  S_or5_984_1 = {&var560,&var566,&var563,&var564,&var1262,&var562};
_S_and2  S_and2_971_1 = {&var813,&var1273,&var563};
_S_and2  S_and2_972_1 = {&var866,&var1273,&var564};
_S_or2  S_or2_976_1 = {&var881,&var561,&var565};
_S_and3  S_and3_970_1 = {&var1087,&var565,&var572,&var566};
_S_and3  S_and3_969_1 = {&var852,&var274,&var572,&var567};
_S_and2  S_and2_968_1 = {&R4IS12LDU,&var572,&var568};
_S_and2  S_and2_949_1 = {&var1266,&var572,&var569};
_S_or2  S_or2_953_1 = {&var1264,&var1263,&var570};
_S_and2  S_and2_952_1 = {&var570,&var572,&var571};
_S_or2  S_or2_941_1 = {&var1275,&var115,&var572};
_S_or2  S_or2_942_1 = {&B4IS11LDU,&A4IS11LDU,&var573};
_S_and3  S_and3_939_1 = {&var573,&var1265,&var572,&var574};
_S_and2  S_and2_951_1 = {&var808,&var572,&var575};
_S_and2  S_and2_938_1 = {&var248,&var572,&var576};
_S_and2  S_and2_937_1 = {&var1601,&var572,&var577};
_S_or2  S_or2_924_1 = {&var1273,&var1671,&var578};
_S_or5  S_or5_908_1 = {&var276,&var902,&var18,&var1282,&var1283,&var579};
_S_and2  S_and2_935_1 = {&var1077,&var581,&var580};
_S_or2  S_or2_932_1 = {&var582,&A3MD12LP1,&var581};
_S_and2  S_and2_921_1 = {&A3MD11LP1,&var1139,&var582};
_S_or3  S_or3_880_1 = {&var487,&var155,&var907,&var583};
_S_or3  S_or3_879_1 = {&var1371,&var586,&var585,&var584};
_S_and2  S_and2_872_1 = {&var1382,&var813,&var585};
_S_and2  S_and2_873_1 = {&var1382,&var866,&var586};
_S_and3  S_and3_871_1 = {&var1405,&var867,&var598,&var587};
_S_and2  S_and2_870_1 = {&R4IS12LDU,&var598,&var588};
_S_and2  S_and2_853_1 = {&var1375,&var598,&var589};
_S_and2  S_and2_855_1 = {&var808,&var598,&var590};
_S_and2  S_and2_856_1 = {&var592,&var598,&var591};
_S_or2  S_or2_857_1 = {&var1373,&var1372,&var592};
_S_and2  S_and2_840_1 = {&var1601,&var598,&var593};
_S_and3  S_and3_842_1 = {&var1374,&var599,&var598,&var594};
_S_and2  S_and2_841_1 = {&var248,&var598,&var595};
_S_and3  S_and3_852_1 = {&var1140,&var114,&var868,&var596};
_S_and3  S_and3_851_1 = {&var114,&var1142,&var868,&var597};
_S_or3  S_or3_843_1 = {&var1383,&var596,&var597,&var598};
_S_or2  S_or2_844_1 = {&B4IS11LDU,&A4IS11LDU,&var599};
_S_or2  S_or2_830_1 = {&var1675,&var1382,&var600};
_S_zpfs  S_zpfs_826_1 = {&var1396,&fRM_3_0,&var601,&internal1_m826_tx,&internal1_m826_y0};
_S_zpfs  S_zpfs_825_1 = {&var1397,&fRM_2_0,&var602,&internal1_m825_tx,&internal1_m825_y0};
_S_zpfs  S_zpfs_832_1 = {&var1394,&fEM_A2UL83RDU,&var603,&internal1_m832_tx,&internal1_m832_y0};
_S_or5  S_or5_820_1 = {&var584,&var603,&var1395,&var602,&var601,&var604};
_S_or2  S_or2_812_1 = {&var694,&var1131,&var605};
_S_or3  S_or3_807_1 = {&var1145,&var1168,&var673,&var606};
_S_or5  S_or5_800_1 = {&var490,&var1167,&var1143,&var1129,&var911,&var607};
_S_or4  S_or4_793_1 = {&var1518,&var1516,&var1517,&var1519,&var608};
_S_or2  S_or2_784_1 = {&var610,&var608,&var609};
_S_or4  S_or4_777_1 = {&var1527,&var1526,&var1525,&var1528,&var610};
_S_and2  S_and2_247_1 = {&var884,&var1321,&var611};
_S_and3  S_and3_235_1 = {&var852,&var274,&var1336,&var612};
_S_or3  S_or3_249_1 = {&var616,&var614,&var1324,&var613};
_S_and2  S_and2_238_1 = {&var1335,&var866,&var614};
_S_and3  S_and3_236_1 = {&var273,&var1087,&var1336,&var615};
_S_and2  S_and2_237_1 = {&var813,&var1335,&var616};
_S_and2  S_and2_234_1 = {&R4IS12LDU,&var1336,&var617};
_S_and2  S_and2_212_1 = {&var1328,&var1336,&var618};
_S_and2  S_and2_214_1 = {&var808,&var1336,&var619};
_S_or2  S_or2_216_1 = {&var1325,&var1326,&var620};
_S_and2  S_and2_215_1 = {&var620,&var1336,&var621};
_S_or2  S_or2_205_1 = {&B4IS11LDU,&A4IS11LDU,&var622};
_S_and3  S_and3_204_1 = {&var1327,&var622,&var1336,&var623};
_S_and2  S_and2_202_1 = {&var1601,&var1336,&var624};
_S_and2  S_and2_203_1 = {&var248,&var1336,&var625};
_S_and2  S_and2_179_1 = {&var1077,&var628,&var626};
_S_and2  S_and2_171_1 = {&A1MD11LP1,&var1120,&var627};
_S_or2  S_or2_177_1 = {&A1MD12LP1,&var627,&var628};
_S_or2  S_or2_191_1 = {&var1335,&var1655,&var629};
_S_zpfs  S_zpfs_182_1 = {&var1350,&fRM_2_0,&var630,&internal1_m182_tx,&internal1_m182_y0};
_S_zpfs  S_zpfs_187_1 = {&var1349,&fRM_2_0,&var631,&internal1_m187_tx,&internal1_m187_y0};
_S_zpfs  S_zpfs_193_1 = {&var1347,&fEM_A1UL03RDU,&var632,&internal1_m193_tx,&internal1_m193_y0};
_S_or5  S_or5_175_1 = {&var613,&var632,&var631,&var630,&var1348,&var633};
_S_orn  S_orn_547_1 = {array_m547_x_1,&iRM_14_,&var634};
_S_and2  S_and2_568_1 = {&var1291,&var879,&var635};
_S_or2  S_or2_563_1 = {&var878,&var635,&var636};
_S_and3  S_and3_556_1 = {&var867,&var1405,&var1303,&var637};
_S_and2  S_and2_555_1 = {&R4IS12LDU,&var1303,&var638};
_S_and3  S_and3_557_1 = {&var1087,&var1303,&var636,&var639};
_S_or2  S_or2_540_1 = {&var1293,&var1292,&var640};
_S_and2  S_and2_539_1 = {&var640,&var1303,&var641};
_S_and2  S_and2_538_1 = {&var1303,&var808,&var642};
_S_and3  S_and3_528_1 = {&var1294,&var644,&var1303,&var643};
_S_or2  S_or2_529_1 = {&B4IS11LDU,&A4IS11LDU,&var644};
_S_and2  S_and2_536_1 = {&var1303,&var1295,&var645};
_S_or2  S_or2_506_1 = {&B1MD12LP1,&var648,&var646};
_S_and2  S_and2_510_1 = {&var1077,&var646,&var647};
_S_and2  S_and2_499_1 = {&B1MD11LP1,&var1098,&var648};
_S_and2  S_and2_527_1 = {&var1303,&var248,&var649};
_S_and2  S_and2_526_1 = {&var1303,&var1601,&var650};
_S_or2  S_or2_517_1 = {&var1302,&var1684,&var651};
_S_zpfs  S_zpfs_519_1 = {&var1316,&fEM_A1UL03RDU,&var652,&internal1_m519_tx,&internal1_m519_y0};
_S_or5  S_or5_502_1 = {&var809,&var652,&var1317,&var1311,&var1312,&var653};
_S_or2  S_or2_490_1 = {&var1116,&var674,&var654};
_S_or3  S_or3_480_1 = {&var484,&var1115,&var909,&var655};
_S_or4  S_or4_470_1 = {&var1355,&var1353,&var1355,&var1354,&var656};
_S_or4  S_or4_452_1 = {&var1364,&var1362,&var1363,&var1365,&var657};
_S_or2  S_or2_459_1 = {&var657,&var656,&var658};
_S_and3  S_and3_443_1 = {&var661,&var1077,&R0MD33LP1,&var659};
_S_and3  S_and3_444_1 = {&var1077,&var662,&R0MD33LP1,&var660};
_S_or3  S_or3_436_1 = {&var159,&var918,&var905,&var661};
_S_or2  S_or2_437_1 = {&var1351,&var1114,&var662};
_S_or4  S_or4_363_1 = {&var1205,&var1203,&var1204,&var1206,&var663};
_S_or2  S_or2_745_1 = {&var1486,&var1487,&var664};
_S_and2  S_and2_317_1 = {&var954,&var1030,&var665};
_S_or2  S_or2_335_1 = {&B4IS21LDU,&A4IS21LDU,&var666};
_S_or2  S_or2_330_1 = {&A2IS21LDU,&B2IS21LDU,&var667};
_S_or2  S_or2_326_1 = {&var670,&var958,&var668};
_S_and3  S_and3_324_1 = {&var1031,&var1012,&var1013,&var669};
_S_or4  S_or4_322_1 = {&var943,&var52,&R0MD31LP1,&var953,&var670};
_S_and4  S_and4_318_1 = {&var865,&var728,&var113,&var820,&var671};
_S_or2  S_or2_313_1 = {&R0MD34LP1,&var953,&var672};
_S_and3  S_and3_597_1 = {&var695,&var1228,&B2IS12LDU,&var673};
_S_and2  S_and2_596_1 = {&var695,&var1260,&var674};
_S_and2  S_and2_595_1 = {&var695,&var1323,&var675};
_S_or2  S_or2_639_1 = {&A2IS12LDU,&B2IS12LDU,&var676};
_S_or2  S_or2_616_1 = {&var1458,&var1066,&var677};
_S_and3  S_and3_607_1 = {&A2IS12LDU,&var1228,&var696,&var678};
_S_and2  S_and2_638_1 = {&var680,&var1228,&var679};
_S_or2  S_or2_640_1 = {&var995,&var97,&var680};
_S_or2  S_or2_621_1 = {&var1458,&var1065,&var681};
_S_or2  S_or2_619_1 = {&var683,&var1458,&var682};
_S_and2  S_and2_631_1 = {&var1260,&var108,&var683};
_S_and2  S_and2_606_1 = {&var696,&var1260,&var684};
_S_and2  S_and2_605_1 = {&var696,&var1323,&var685};
_S_and2  S_and2_630_1 = {&var102,&var1323,&var686};
_S_and2  S_and2_646_1 = {&var105,&var1351,&var687};
_S_or2  S_or2_642_1 = {&var1458,&var1067,&var688};
_S_or2  S_or2_637_1 = {&var690,&var687,&var689};
_S_and2  S_and2_629_1 = {&var698,&var1320,&var690};
_S_and2  S_and2_635_1 = {&var698,&R0MD33LP1,&var691};
_S_or2  S_or2_585_1 = {&var876,&var877,&var692};
_S_and4  S_and4_604_1 = {&var876,&var696,&var1420,&A2IS12LDU,&var693};
_S_and4  S_and4_594_1 = {&var695,&var877,&var1420,&B2IS12LDU,&var694};
_S_and2  S_and2_593_1 = {&var817,&var1418,&var695};
_S_and2  S_and2_603_1 = {&var816,&var1418,&var696};
_S_or2  S_or2_634_1 = {&var996,&var97,&var697};
_S_and2  S_and2_627_1 = {&var697,&var1420,&var698};
_S_or2  S_or2_614_1 = {&var1458,&var1068,&var699};
_S_or2  S_or2_626_1 = {&var1398,&var1009,&var700};
_S_and2  S_and2_625_1 = {&var700,&var1442,&var701};
_S_or2  S_or2_611_1 = {&var1458,&var1069,&var702};
_S_and2  S_and2_624_1 = {&var1459,&var1408,&var703};
_S_or2  S_or2_609_1 = {&var1458,&var1070,&var704};
_S_and2  S_and2_622_1 = {&var100,&var1461,&var705};
_S_or2  S_or2_601_1 = {&var1078,&var1458,&var706};
_S_and2  S_and2_294_1 = {&var1151,&var709,&var707};
_S_and2  S_and2_283_1 = {&var709,&var941,&var708};
_S_or2  S_or2_277_1 = {&var955,&var977,&var709};
_S_and3  S_and3_273_1 = {&var1224,&var1012,&var1013,&var710};
_S_and3  S_and3_288_1 = {&var667,&var942,&var712,&var711};
_S_or2  S_or2_278_1 = {&var1224,&var1031,&var712};
_S_and2  S_and2_287_1 = {&var666,&var712,&var713};
_S_and2  S_and2_306_1 = {&var718,&var817,&var714};
_S_and2  S_and2_307_1 = {&var816,&var718,&var715};
_S_and2  S_and2_311_1 = {&var914,&var707,&var716};
_S_and2  S_and2_301_1 = {&var718,&var914,&var717};
_S_and2  S_and2_305_1 = {&var1112,&var719,&var718};
_S_or2  S_or2_302_1 = {&var720,&var665,&var719};
_S_or2  S_or2_303_1 = {&var721,&var665,&var720};
_S_and4  S_and4_304_1 = {&var1032,&var966,&var967,&var814,&var721};
_S_or2  S_or2_290_1 = {&var1032,&var1030,&var722};
_S_and2  S_and2_275_1 = {&var980,&var949,&var723};
_S_or2  S_or2_281_1 = {&var726,&var723,&var724};
_S_or2  S_or2_256_1 = {&R0MD34LP1,&var952,&var725};
_S_or4  S_or4_272_1 = {&var943,&R0MD31LP1,&var52,&var952,&var726};
_S_and3  S_and3_266_1 = {&var728,&var819,&var113,&var727};
_S_or2  S_or2_265_1 = {&var971,&var1182,&var728};
_S_and3  S_and3_268_1 = {&var972,&var974,&var973,&var729};
_S_or2  S_or2_258_1 = {&var731,&var729,&var730};
_S_and3  S_and3_252_1 = {&R0MD33LP1,&var976,&var975,&var731};
_S_or2  S_or2_1099_1 = {&B4IS11LDU,&A4IS11LDU,&var732};
_S_and2  S_and2_1102_1 = {&var1409,&var1456,&var733};
_S_and2  S_and2_1101_1 = {&var1409,&var1564,&var734};
_S_and2  S_and2_1100_1 = {&var1409,&var805,&var735};
_S_and2  S_and2_1098_1 = {&var1409,&var732,&var736};
_S_and2  S_and2_1091_1 = {&var1409,&R4IS12LDU,&var737};
_S_and2  S_and2_1090_1 = {&var794,&var1409,&var738};
_S_and2  S_and2_1089_1 = {&var1409,&var248,&var739};
_S_and2  S_and2_1092_1 = {&var1409,&var1601,&var740};
_S_and2  S_and2_1084_1 = {&var97,&var911,&var741};
_S_and2  S_and2_1085_1 = {&var108,&var909,&var742};
_S_or3  S_or3_1285_1 = {&var488,&var150,&var907,&var743};
_S_and2  S_and2_1086_1 = {&var102,&var907,&var744};
_S_and2  S_and2_1087_1 = {&var105,&var905,&var745};
_S_or2  S_or2_1069_1 = {&R0MD31LP1,&var747,&var746};
_S_and4  S_and4_1070_1 = {&var4,&var3,&var2,&var1,&var747};
_S_or2  S_or2_1137_1 = {&var1409,&var1659,&var748};
_S_or2  S_or2_1114_1 = {&var1459,&var999,&var749};
_S_or2  S_or2_1178_1 = {&var1500,&var1499,&var750};
_S_or2  S_or2_1164_1 = {&var1509,&var1508,&var751};
_S_or2  S_or2_1174_1 = {&var892,&R0MD34LP1,&var752};
_S_or2  S_or2_1151_1 = {&var750,&var1564,&var753};
_S_or2  S_or2_1149_1 = {&var755,&var753,&var754};
_S_or2  S_or2_1150_1 = {&var751,&var1564,&var755};
_S_or4  S_or4_346_1 = {&var1536,&var1535,&var1537,&var1534,&var756};
_S_or2  S_or2_662_1 = {&B5IS11LDU,&A5IS11LDU,&var757};
_S_and2  S_and2_661_1 = {&var762,&var757,&var758};
_S_or2  S_or2_660_1 = {&B6IS11LDU,&A6IS11LDU,&var759};
_S_and2  S_and2_659_1 = {&var762,&var759,&var760};
_S_or2  S_or2_658_1 = {&A4IS11LDU,&B4IS11LDU,&var761};
_S_or2  S_or2_649_1 = {&var764,&var765,&var762};
_S_and2  S_and2_657_1 = {&var762,&var761,&var763};
_S_and2  S_and2_652_1 = {&R4IS12LDU,&var775,&var764};
_S_and2  S_and2_648_1 = {&R4IS22LDU,&var768,&var765};
_S_and2  S_and2_767_1 = {&var1562,&var1480,&var766};
_S_and2  S_and2_763_1 = {&var1562,&var1481,&var767};
_S_and3  S_and3_757_1 = {&var1562,&R4IS22LDU,&var1487,&var768};
_S_or2  S_or2_766_1 = {&var1482,&var1476,&var769};
_S_or2  S_or2_760_1 = {&var1480,&var1482,&var770};
_S_or2  S_or2_756_1 = {&var1482,&var1481,&var771};
_S_and2  S_and2_737_1 = {&var1476,&var1562,&var772};
_S_or2  S_or2_728_1 = {&var1483,&var1484,&var773};
_S_or2  S_or2_725_1 = {&var1541,&var1483,&var774};
_S_and2  S_and2_723_1 = {&var1484,&var1563,&var775};
_S_and2  S_and2_722_1 = {&var1541,&var1563,&var776};
_S_and2  S_and2_749_1 = {&var100,&var1562,&var777};
_S_and2  S_and2_730_1 = {&var100,&var1493,&var778};
_S_and2  S_and2_747_1 = {&var1563,&var100,&var779};
_S_or2  S_or2_741_1 = {&var1563,&var1562,&var780};
_S_or3  S_or3_734_1 = {&R4MD11LP2,&var783,&var784,&var781};
_S_or4  S_or4_733_1 = {&var783,&R4MD21LP2,&var785,&var1472,&var782};
_S_or3  S_or3_724_1 = {&R4MD31LP2,&var772,&var776,&var783};
_S_or2  S_or2_753_1 = {&var1561,&var787,&var784};
_S_or2  S_or2_752_1 = {&var1561,&var786,&var785};
_S_and2  S_and2_671_1 = {&R4MD11LP2,&var1475,&var786};
_S_and3  S_and3_701_1 = {&var1474,&var1488,&R4MD21LP2,&var787};
_S_and2  S_and2_706_1 = {&R5IS11LDU,&var802,&var788};
_S_and3  S_and3_704_1 = {&var1112,&var248,&var802,&var789};
_S_and2  S_and2_705_1 = {&R6IS21LDU,&var802,&var790};
_S_or2  S_or2_703_1 = {&B8IS22LDU,&A8IS22LDU,&var791};
_S_and2  S_and2_702_1 = {&var791,&var802,&var792};
_S_and2  S_and2_689_1 = {&var802,&var794,&var793};
_S_or4  S_or4_690_1 = {&A0VN71LZ1,&B0VN71LZ1,&B0VN71LZ2,&A0VN71LZ2,&var794};
_S_and2  S_and2_687_1 = {&var799,&var802,&var795};
_S_and2  S_and2_678_1 = {&var805,&var802,&var796};
_S_and2  S_and2_677_1 = {&var1564,&var802,&var797};
_S_or3  S_or3_676_1 = {&R0NE01LDU,&R0NE02LDU,&R0NE08LDU,&var798};
_S_or2  S_or2_688_1 = {&R1IS21LDU,&R2IS21LDU,&var799};
_S_and2  S_and2_675_1 = {&var802,&var798,&var800};
_S_and2  S_and2_673_1 = {&var1542,&var802,&var801};
_S_or2  S_or2_664_1 = {&var1563,&var1562,&var802};
_S_or2  S_or2_161_1 = {&var1118,&var684,&var803};
_S_or3  S_or3_151_1 = {&var483,&var1117,&var909,&var804};
_S_or2  S_or2_144_1 = {&var1405,&var274,&var805};
_S_or3  S_or3_105_1 = {&var1076,&var260,&var261,&var806};
_S_or2  S_or2_2000_1 = {&var217,&var75,&var807};
_S_or2  S_or2_125_1 = {&R0VZ71LZ1,&R0VZ71LZ2,&var808};
_S_or3  S_or3_570_1 = {&var810,&var811,&var634,&var809};
_S_and2  S_and2_558_1 = {&var1302,&var813,&var810};
_S_and2  S_and2_559_1 = {&var1302,&var866,&var811};
_S_or2  S_or2_60_1 = {&var866,&var813,&var812};
_S_and2  S_and2_63_1 = {&var814,&var945,&var813};
_S_and2  S_and2_62_1 = {&var1571,&var946,&var814};
_S_or2  S_or2_48_1 = {&A4IS21LDU,&B4IS21LDU,&var815};
_S_or2  S_or2_35_1 = {&var1222,&var1219,&var816};
_S_or2  S_or2_39_1 = {&var1222,&var1221,&var817};
_S_or2  S_or2_20_1 = {&var1112,&var1061,&var818};
_S_or2  S_or2_8_1 = {&var1581,&var868,&var819};
_S_or2  S_or2_14_1 = {&var868,&var1582,&var820};
_S_and3  S_and3_992_1 = {&var110,&var1575,&var842,&var821};
_S_and3  S_and3_583_1 = {&var842,&var113,&var1575,&var822};
_S_and2  S_and2_1058_1 = {&var889,&var824,&var823};
_S_or2  S_or2_1064_1 = {&var1582,&var1581,&var824};
_S_and2  S_and2_1361_1 = {&var368,&var555,&var825};
_S_or2  S_or2_1363_1 = {&var1583,&var1581,&var826};
_S_and3  S_and3_1362_1 = {&var887,&var826,&var555,&var827};
_S_or2  S_or2_963_1 = {&var1583,&var1581,&var828};
_S_and3  S_and3_962_1 = {&var887,&var828,&var572,&var829};
_S_and2  S_and2_961_1 = {&var572,&var368,&var830};
_S_or2  S_or2_550_1 = {&var1583,&var1581,&var831};
_S_and3  S_and3_549_1 = {&var887,&var831,&var1303,&var832};
_S_and2  S_and2_548_1 = {&var368,&var1303,&var833};
_S_or2  S_or2_226_1 = {&var1583,&var1581,&var834};
_S_and3  S_and3_225_1 = {&var887,&var834,&var1336,&var835};
_S_and2  S_and2_224_1 = {&var1336,&var368,&var836};
_S_and3  S_and3_866_1 = {&var887,&var839,&var598,&var837};
_S_and2  S_and2_865_1 = {&var368,&var598,&var838};
_S_or2  S_or2_867_1 = {&var1583,&var1581,&var839};
_S_or2  S_or2_1272_1 = {&var1583,&var1581,&var840};
_S_or2  S_or2_6_1 = {&var1582,&var1581,&var841};
_S_or3  S_or3_5_1 = {&var1583,&var1582,&var1581,&var842};
_S_or2  S_or2_740_1 = {&var1483,&var1485,&var843};
_S_or2  S_or2_433_1 = {&var1564,&var849,&var844};
_S_or2  S_or2_416_1 = {&var1564,&var850,&var845};
_S_or4  S_or4_417_1 = {&var845,&var1492,&var1491,&var844,&var846};
_S_and2  S_and2_411_1 = {&var1556,&B8IS22LDU,&var847};
_S_and2  S_and2_410_1 = {&A8IS22LDU,&var1556,&var848};
_S_or3  S_or3_396_1 = {&var1546,&var1544,&var1545,&var849};
_S_or3  S_or3_381_1 = {&var1554,&var1553,&var1555,&var850};
_S_and2  S_and2_727_1 = {&var1563,&var1485,&var851};
_S_and2  S_and2_38_1 = {&var1219,&var1220,&var852};
_S_and2  S_and2_137_1 = {&var1495,&var1103,&var853};
_S_and2  S_and2_145_1 = {&var1497,&var1103,&var854};
_S_and2  S_and2_148_1 = {&var1494,&var1103,&var855};
_S_and2  S_and2_140_1 = {&var1103,&var1496,&var856};
_S_and2  S_and2_430_1 = {&var805,&var1548,&var857};
_S_and2  S_and2_429_1 = {&B8IS22LDU,&var1548,&var858};
_S_and2  S_and2_428_1 = {&A8IS22LDU,&var1548,&var859};
_S_and2  S_and2_427_1 = {&R5IS11LDU,&var1548,&var860};
_S_and2  S_and2_419_1 = {&var1490,&var1556,&var861};
_S_and2  S_and2_409_1 = {&R5IS11LDU,&var1556,&var862};
_S_and2  S_and2_412_1 = {&var805,&var1556,&var863};
_S_and2  S_and2_109_1 = {&var868,&var259,&var864};
_S_and2  S_and2_58_1 = {&var1572,&var946,&var865};
_S_and2  S_and2_59_1 = {&var865,&var944,&var866};
_S_and2  S_and2_42_1 = {&var1220,&var1221,&var867};
_S_and2  S_and2_11_1 = {&var1580,&var1212,&var868};
_S_and2  S_and2_31_1 = {&var1136,&var99,&var869};
_S_and2  S_and2_30_1 = {&var1005,&var1112,&var870};
_S_and2  S_and2_29_1 = {&var1006,&var1112,&var871};
_S_and2  S_and2_28_1 = {&var1007,&var1112,&var872};
_S_and2  S_and2_27_1 = {&var1008,&var1112,&var873};
_S_and2  S_and2_755_1 = {&var1479,&var1487,&var874};
_S_and2  S_and2_736_1 = {&var1486,&var1563,&var875};
_S_bol  S_bol_584_1 = {&var1678,&fRM_20_0,&var876};
_S_bol  S_bol_578_1 = {&var1674,&fRM_20_0,&var877};
_S_bol  S_bol_569_1 = {&var1674,&fRM_20_03,&var878};
_S_bol  S_bol_567_1 = {&var1678,&fRM_20_03,&var879};
_S_bol  S_bol_981_1 = {&var1674,&fRM_20_03,&var880};
_S_bol  S_bol_983_1 = {&var1678,&fRM_20_03,&var881};
_S_bol  S_bol_1381_1 = {&var1678,&fRM_20_03,&var882};
_S_bol  S_bol_1383_1 = {&var1674,&fRM_20_03,&var883};
_S_bol  S_bol_246_1 = {&var1674,&fRM_20_03,&var884};
_S_bol  S_bol_248_1 = {&var1678,&fRM_20_03,&var885};
_S_sr  S_sr_81_1 = {array_m81_x_1,&iRM_2_,&var886};
_S_bol  S_bol_80_1 = {&var886,&var51,&var887};
_S_ma  S_ma_83_1 = {array_m83_x_1,&R0MW15IP1,&iRM_8_,&var888};
_S_bol  S_bol_1059_1 = {&var890,&fEM_R0UN80RDU,&var889};
_S_sr  S_sr_1065_1 = {array_m1065_x_1,&iRM_2_,&var890};
_S_ovbs  S_ovbs_2063_1 = {&lRM_1_,&fEM_A9UZ04RDU,&var891,&internal1_m2063_tx};
_S_ovbs  S_ovbs_1173_1 = {&lRM_1_,&fEM_A4UZ04RDU,&var892,&internal1_m1173_tx};
_S_zpfs  S_zpfs_1605_1 = {&var1450,&fEM_B8UL03RDU,&var893,&internal1_m1605_tx,&internal1_m1605_y0};
_S_zpfs  S_zpfs_1139_1 = {&var1467,&fEM_B8UL03RDU,&var894,&internal1_m1139_tx,&internal1_m1139_y0};
_S_ma  S_ma_1195_1 = {array_m1195_x_1,&var1419,&iRM_8_,&var895};
_S_ma  S_ma_809_1 = {array_m809_x_1,&var1379,&iRM_8_,&var896};
_S_ma  S_ma_891_1 = {array_m891_x_1,&var1270,&iRM_8_,&var897};
_S_ma  S_ma_1296_1 = {array_m1296_x_1,&var1238,&iRM_8_,&var898};
_S_ma  S_ma_489_1 = {array_m489_x_1,&var1299,&iRM_8_,&var899};
_S_ma  S_ma_158_1 = {array_m158_x_1,&var1332,&iRM_8_,&var900};
_S_zpfs  S_zpfs_1326_1 = {&var1255,&fEM_A3UL03RDU,&var901,&internal1_m1326_tx,&internal1_m1326_y0};
_S_zpfs  S_zpfs_926_1 = {&var1287,&fEM_A3UL03RDU,&var902,&internal1_m926_tx,&internal1_m926_y0};
_S_zpfs  S_zpfs_1233_1 = {&var1437,&fEM_A2UL03RDU,&var903,&internal1_m1233_tx,&internal1_m1233_y0};
_S_rs  S_rs_1083_1 = {&var746,&var745,&var904,&vainSBool,&internal1_m1083_q0};
_S_rs  S_rs_1081_1 = {&var4,&var912,&var905,&vainSBool,&internal1_m1081_q0};
_S_rs  S_rs_1080_1 = {&var746,&var744,&var906,&vainSBool,&internal1_m1080_q0};
_S_rs  S_rs_1078_1 = {&var3,&var912,&var907,&vainSBool,&internal1_m1078_q0};
_S_rs  S_rs_1077_1 = {&var746,&var742,&var908,&vainSBool,&internal1_m1077_q0};
_S_rs  S_rs_1075_1 = {&var2,&var912,&var909,&vainSBool,&internal1_m1075_q0};
_S_rs  S_rs_1074_1 = {&var746,&var741,&var910,&vainSBool,&internal1_m1074_q0};
_S_rs  S_rs_1072_1 = {&var1,&var912,&var911,&vainSBool,&internal1_m1072_q0};
_S_rs  S_rs_1071_1 = {&var746,&var52,&var912,&vainSBool,&internal1_m1071_q0};
_S_noto  S_noto_1914_1 = {&var335,&var913};
_S_swtakt  S_swtakt_52_1 = {&var254,&var914,&internal1_m52_x0};
_S_noto  S_noto_1057_1 = {&var926,&var915};
_S_noto  S_noto_1031_1 = {&var924,&var916};
_S_noto  S_noto_1043_1 = {&var925,&var917};
_S_rs  S_rs_991_1 = {&var927,&var491,&var918,&vainSBool,&internal1_m991_q0};
_S_swtakt  S_swtakt_1427_1 = {&var449,&var919,&internal1_m1427_x0};
_S_swtakt  S_swtakt_1471_1 = {&var437,&var920,&internal1_m1471_x0};
_S_swtakt  S_swtakt_1467_1 = {&var431,&var921,&internal1_m1467_x0};
_S_swtakt  S_swtakt_1874_1 = {&var322,&var922,&internal1_m1874_x0};
_S_swtakt  S_swtakt_1839_1 = {&var295,&var923,&internal1_m1839_x0};
_S_rs  S_rs_1030_1 = {&var998,&var479,&var924,&vainSBool,&internal1_m1030_q0};
_S_rs  S_rs_1042_1 = {&var998,&var480,&var925,&vainSBool,&internal1_m1042_q0};
_S_rs  S_rs_1054_1 = {&var998,&var481,&var926,&vainSBool,&internal1_m1054_q0};
_S_rs  S_rs_1063_1 = {&var998,&var482,&var927,&vainSBool,&internal1_m1063_q0};
_S_noto  S_noto_1017_1 = {&var497,&var928};
_S_noto  S_noto_1044_1 = {&var497,&var929};
_S_noto  S_noto_1050_1 = {&var501,&var930};
_S_rs  S_rs_1041_1 = {&var475,&var477,&var931,&vainSBool,&internal1_m1041_q0};
_S_rs  S_rs_1056_1 = {&var998,&var473,&var932,&vainSBool,&internal1_m1056_q0};
_S_bol  S_bol_1038_1 = {&var1658,&var175,&var933};
_S_bol  S_bol_1037_1 = {&var1662,&var175,&var934};
_S_noto  S_noto_998_1 = {&var993,&var935};
_S_bol  S_bol_1035_1 = {&var175,&var1658,&var936};
_S_bol  S_bol_1034_1 = {&var175,&var1662,&var937};
_S_noto  S_noto_1021_1 = {&var994,&var938};
_S_rs  S_rs_1932_1 = {&var340,&var331,&var939,&vainSBool,&internal1_m1932_q0};
_S_rs  S_rs_1931_1 = {&var340,&var332,&var940,&vainSBool,&internal1_m1931_q0};
_S_noto  S_noto_312_1 = {&var716,&var941};
_S_noto  S_noto_296_1 = {&var709,&var942};
_S_noto  S_noto_267_1 = {&var728,&var943};
_S_noto  S_noto_56_1 = {&var955,&var944};
_S_noto  S_noto_67_1 = {&var977,&var945};
_S_noto  S_noto_66_1 = {&var912,&var946};
_S_noto  S_noto_1926_1 = {&B2IS11LDU,&var947};
_S_noto  S_noto_1924_1 = {&A2IS11LDU,&var948};
_S_noto  S_noto_274_1 = {&var113,&var949};
_S_noto  S_noto_1933_1 = {&B2IS11LDU,&var950};
_S_noto  S_noto_1908_1 = {&A2IS11LDU,&var951};
_S_noto  S_noto_262_1 = {&var814,&var952};
_S_noto  S_noto_316_1 = {&var865,&var953};
_S_bolz  S_bolz_320_1 = {&iRM_2_,&var956,&var954};
_S_provsbr  S_provsbr_315_1 = {&var1030,&var672,&var1045,&var1062,&var1056,&var1051,&var1048,&var1046,&var1060,&var1055,&var1053,&var1049,&iRM_10_,array_m315_Tpr_1,array_m315_type_1,&var955,&var956,&var957,&var958,&var959,&var960,&var961,&var962,&var963,&internal1_m315_Step,array_m315_rz_1,&internal1_m315_TimS,&internal1_m315_FinPr0,&internal1_m315_ErrPr0,&internal1_m315_sbINI0,&internal1_m315_sbVuIS0,&internal1_m315_sb2UR0,&internal1_m315_sbNupIS0,&internal1_m315_sbVuRB0,&internal1_m315_MyFirstEnterFlag};
_S_orni  S_orni_319_1 = {array_m319_x_1,&iRM_5_,&vainSBool,&var964};
_S_cntch  S_cntch_323_1 = {&var964,&var965,&internal1_m323_x0};
_S_bolz  S_bolz_300_1 = {&iRM_20_,&var979,&var966};
_S_equz_p  S_equz_p_299_1 = {&var978,&iRM_0_,&var967};
_S_decatron  S_decatron_284_1 = {&var708,&var968,&internal1_m284_TimS};
_S_noto  S_noto_995_1 = {&R2IS21LDU,&var969};
_S_noto  S_noto_989_1 = {&R1IS21LDU,&var970};
_S_andn  S_andn_257_1 = {array_m257_x_1,&iRM_7_,&var971};
_S_noto  S_noto_259_1 = {&R0MD33LP1,&var972};
_S_noto  S_noto_269_1 = {&R2IS21LDU,&var973};
_S_noto  S_noto_263_1 = {&R1IS21LDU,&var974};
_S_noto  S_noto_254_1 = {&R1IS11LDU,&var975};
_S_noto  S_noto_251_1 = {&R2IS11LDU,&var976};
_S_provsbr  S_provsbr_261_1 = {&var1032,&var725,&var1045,&var1062,&var1056,&var1051,&var1048,&var1046,&var1060,&var1055,&var1053,&var1049,&iRM_10_,array_m261_Tpr_1,array_m261_type_1,&var977,&var978,&var979,&var980,&var981,&var982,&var983,&var984,&var985,&internal1_m261_Step,array_m261_rz_1,&internal1_m261_TimS,&internal1_m261_FinPr0,&internal1_m261_ErrPr0,&internal1_m261_sbINI0,&internal1_m261_sbVuIS0,&internal1_m261_sb2UR0,&internal1_m261_sbNupIS0,&internal1_m261_sbVuRB0,&internal1_m261_MyFirstEnterFlag};
_S_rs  S_rs_1402_1 = {&var987,&var471,&var986,&vainSBool,&internal1_m1402_q0};
_S_provsbr  S_provsbr_1403_1 = {&var986,&R0MD34LP1,&var1045,&var1062,&var1056,&var1051,&var1048,&var1046,&var1060,&var1055,&var1053,&var1049,&iRM_6_,array_m1403_Tpr_1,array_m1403_type_1,&var987,&vainSInt,&vainSInt,&vainSBool,&var988,&var989,&var990,&var991,&var992,&internal1_m1403_Step,array_m1403_rz_1,&internal1_m1403_TimS,&internal1_m1403_FinPr0,&internal1_m1403_ErrPr0,&internal1_m1403_sbINI0,&internal1_m1403_sbVuIS0,&internal1_m1403_sb2UR0,&internal1_m1403_sbNupIS0,&internal1_m1403_sbVuRB0,&internal1_m1403_MyFirstEnterFlag};
_S_abs_subf  S_abs_subf_1001_1 = {&var175,&var1662,&fEM_B8UC01RDU,&vainSFloat,&var993};
_S_abs_subf  S_abs_subf_1014_1 = {&var1658,&var175,&fEM_B8UC01RDU,&vainSFloat,&var994};
_S_noto  S_noto_645_1 = {&var676,&var995};
_S_noto  S_noto_591_1 = {&var692,&var996};
_S_noto  S_noto_49_1 = {&var171,&var997};
_S_noto  S_noto_1018_1 = {&var1227,&var998};
_S_rs  S_rs_1025_1 = {&var474,&var275,&var999,&vainSBool,&internal1_m1025_q0};
_S_rs  S_rs_1022_1 = {&var478,&var473,&var1000,&vainSBool,&internal1_m1022_q0};
_S_rs  S_rs_1024_1 = {&var998,&var275,&var1001,&vainSBool,&internal1_m1024_q0};
_S_rs  S_rs_1019_1 = {&var998,&var476,&var1002,&vainSBool,&internal1_m1019_q0};
_S_noto  S_noto_580_1 = {&A2IS21LDU,&var1003};
_S_noto  S_noto_582_1 = {&B2IS21LDU,&var1004};
_S_noto  S_noto_25_1 = {&B2IS21LDU,&var1005};
_S_noto  S_noto_24_1 = {&B1IS21LDU,&var1006};
_S_noto  S_noto_23_1 = {&A1IS21LDU,&var1007};
_S_noto  S_noto_22_1 = {&A2IS21LDU,&var1008};
_S_newstage  S_newstage_592_1 = {&var205,&var200,&A2IS12LDU,&B2IS12LDU,&var1009};
_S_noto  S_noto_581_1 = {&B2IS12LDU,&var1010};
_S_noto  S_noto_579_1 = {&A2IS12LDU,&var1011};
_S_noto  S_noto_328_1 = {&var667,&var1012};
_S_noto  S_noto_332_1 = {&var666,&var1013};
_S_noto  S_noto_988_1 = {&var805,&var1014};
_S_rs  S_rs_744_1 = {&var664,&var257,&var1015,&vainSBool,&internal1_m744_q0};
_S_samhd  S_samhd_2096_1 = {&R0MD34LP1,&var251,&var251,&R3AD11LDU,&R3AD21LDU,&R3AD11LDU,&R3AD21LDU,&R3IS31LDU,&R3IS31LDU,&R3IS41LDU,&R3IS41LDU,&bRM_0_,&fEM_R3UZ04RDU,&fEM_R3UZ03RDU,&fEM_R3UL10RDU,&var1016,&var1017,&var1018,&var1019,&vainSBool,&vainSBool,&var1020,&var1021,&var1022,&vainSBool,&vainSBool,&bFirstEnterFlag,&internal1_m2096_DvUp0,&internal1_m2096_DvDw0,&internal1_m2096_FDvUp0,&internal1_m2096_FDvDw0,&internal1_m2096_BlDv0,&internal1_m2096_Pkv0,&internal1_m2096_Pkav0,&internal1_m2096_Zkv0,&internal1_m2096_Zkav0,&internal1_m2096_txNm,&internal1_m2096_txSm,&internal1_m2096_txHr,&internal1_m2096_txLd,&internal1_m2096_fef};
_S_samhd  S_samhd_2091_1 = {&R0MD34LP1,&var250,&var250,&R3AD10LDU,&R3AD20LDU,&R3AD10LDU,&R3AD20LDU,&R3IS11LDU,&R3IS11LDU,&R3IS21LDU,&R3IS21LDU,&bRM_0_,&fEM_R3UZ04RDU,&fEM_R3UZ03RDU,&fEM_R3UL10RDU,&var1023,&var1024,&var1025,&var1026,&vainSBool,&vainSBool,&var1027,&var1028,&var1029,&vainSBool,&vainSBool,&bFirstEnterFlag,&internal1_m2091_DvUp0,&internal1_m2091_DvDw0,&internal1_m2091_FDvUp0,&internal1_m2091_FDvDw0,&internal1_m2091_BlDv0,&internal1_m2091_Pkv0,&internal1_m2091_Pkav0,&internal1_m2091_Zkv0,&internal1_m2091_Zkav0,&internal1_m2091_txNm,&internal1_m2091_txSm,&internal1_m2091_txHr,&internal1_m2091_txLd,&internal1_m2091_fef};
_S_rs  S_rs_325_1 = {&var668,&var669,&var1030,&vainSBool,&internal1_m325_q0};
_S_rs  S_rs_321_1 = {&var670,&var671,&var1031,&vainSBool,&internal1_m321_q0};
_S_rs  S_rs_280_1 = {&var724,&var710,&var1032,&vainSBool,&internal1_m280_q0};
_S_orni  S_orni_276_1 = {array_m276_x_1,&iRM_5_,&vainSBool,&var1033};
_S_cntch  S_cntch_279_1 = {&var1033,&var1034,&internal1_m279_x0};
_S_noto  S_noto_1441_1 = {&var1053,&var1035};
_S_noto  S_noto_1496_1 = {&var1055,&var1036};
_S_noto  S_noto_1498_1 = {&var1060,&var1037};
_S_noto  S_noto_1855_1 = {&var1046,&var1038};
_S_noto  S_noto_1893_1 = {&var1049,&var1039};
_S_noto  S_noto_1870_1 = {&var922,&var1040};
_S_noto  S_noto_1833_1 = {&var923,&var1041};
_S_noto  S_noto_1468_1 = {&var921,&var1042};
_S_noto  S_noto_1463_1 = {&var920,&var1043};
_S_noto  S_noto_1424_1 = {&var919,&var1044};
_S_rs  S_rs_1861_1 = {&var456,&var279,&var1045,&vainSBool,&internal1_m1861_q0};
_S_rs  S_rs_1849_1 = {&var294,&var291,&var1046,&vainSBool,&internal1_m1849_q0};
_S_rs  S_rs_1840_1 = {&var290,&var923,&var1047,&vainSBool,&internal1_m1840_q0};
_S_rs  S_rs_1915_1 = {&var456,&var309,&var1048,&vainSBool,&internal1_m1915_q0};
_S_rs  S_rs_1885_1 = {&var317,&var316,&var1049,&vainSBool,&internal1_m1885_q0};
_S_rs  S_rs_1875_1 = {&var319,&var922,&var1050,&vainSBool,&internal1_m1875_q0};
_S_rs  S_rs_1455_1 = {&var456,&var442,&var1051,&vainSBool,&internal1_m1455_q0};
_S_kvf  S_kvf_1442_1 = {&var1054,&var443,&fRM_0_0,&var1052,&vainSInt,&vainSInt,&internal1_m1442_x0,&internal1_m1442_y0,&bFirstEnterFlag};
_S_rs  S_rs_1438_1 = {&var448,&var443,&var1053,&vainSBool,&internal1_m1438_q0};
_S_rs  S_rs_1428_1 = {&var445,&var919,&var1054,&vainSBool,&internal1_m1428_q0};
_S_rs  S_rs_1487_1 = {&var438,&var433,&var1055,&vainSBool,&internal1_m1487_q0};
_S_rs  S_rs_1507_1 = {&var456,&var439,&var1056,&vainSBool,&internal1_m1507_q0};
_S_rs  S_rs_1473_1 = {&var436,&var920,&var1057,&vainSBool,&internal1_m1473_q0};
_S_kvf  S_kvf_1488_1 = {&var1057,&var433,&fRM_0_0,&var1058,&vainSInt,&vainSInt,&internal1_m1488_x0,&internal1_m1488_y0,&bFirstEnterFlag};
_S_cntch  S_cntch_1413_1 = {&var458,&var1059,&internal1_m1413_x0};
_S_rs  S_rs_1493_1 = {&var430,&var424,&var1060,&vainSBool,&internal1_m1493_q0};
_S_rs  S_rs_26_1 = {&var1112,&var869,&var1061,&vainSBool,&internal1_m26_q0};
_S_rs  S_rs_1508_1 = {&var456,&var423,&var1062,&vainSBool,&internal1_m1508_q0};
_S_noto  S_noto_1391_1 = {&var452,&var1063};
_S_noto  S_noto_1389_1 = {&var868,&var1064};
_S_rs  S_rs_632_1 = {&var1458,&var679,&var1065,&vainSBool,&internal1_m632_q0};
_S_rs  S_rs_617_1 = {&var1458,&var686,&var1066,&vainSBool,&internal1_m617_q0};
_S_rs  S_rs_643_1 = {&var1458,&var687,&var1067,&vainSBool,&internal1_m643_q0};
_S_rs  S_rs_628_1 = {&var1458,&var698,&var1068,&vainSBool,&internal1_m628_q0};
_S_rs  S_rs_612_1 = {&var1458,&var701,&var1069,&vainSBool,&internal1_m612_q0};
_S_rs  S_rs_610_1 = {&var1458,&var703,&var1070,&vainSBool,&internal1_m610_q0};
_S_rs  S_rs_598_1 = {&var706,&var1461,&var1071,&vainSBool,&internal1_m598_q0};
_S_rsun  S_rsun_1405_1 = {&var456,&var1211,&vainSLong,&var1072,&internal1_m1405_q0};
_S_noto  S_noto_1327_1 = {&B3MD12LP1,&var1073};
_S_noto  S_noto_1809_1 = {&B3IS11LDU,&var1074};
_S_noto  S_noto_1783_1 = {&A3IS11LDU,&var1075};
_S_noto  S_noto_108_1 = {&var868,&var1076};
_S_noto  S_noto_107_1 = {&var1081,&var1077};
_S_rs  S_rs_608_1 = {&var1458,&var705,&var1078,&vainSBool,&internal1_m608_q0};
_S_orni  S_orni_1172_1 = {array_m1172_x_1,&iRM_6_,&var1079,&vainSLong};
_S_orni  S_orni_1160_1 = {array_m1160_x_1,&iRM_5_,&var1080,&vainSLong};
_S_rs  S_rs_106_1 = {&var806,&var864,&var1081,&vainSBool,&internal1_m106_q0};
_S_noto  S_noto_1812_1 = {&var359,&var1082};
_S_noto  S_noto_1811_1 = {&var358,&var1083};
_S_noto  S_noto_1823_1 = {&B3IS22LDU,&var1084};
_S_noto  S_noto_1804_1 = {&A3IS22LDU,&var1085};
_S_newstage  S_newstage_1807_1 = {&var375,&var371,&var374,&var370,&var1086};
_S_noto  S_noto_1751_1 = {&var1182,&var1087};
_S_rs  S_rs_1640_1 = {&var96,&var127,&var1088,&vainSBool,&internal1_m1640_q0};
_S_rs  S_rs_1639_1 = {&var129,&var131,&var1089,&vainSBool,&internal1_m1639_q0};
_S_rs  S_rs_1638_1 = {&var96,&var133,&var1090,&vainSBool,&internal1_m1638_q0};
_S_rs  S_rs_1637_1 = {&var134,&var137,&var1091,&vainSBool,&internal1_m1637_q0};
_S_rs  S_rs_1668_1 = {&var99,&var139,&var1092,&vainSBool,&internal1_m1668_q0};
_S_rs  S_rs_1667_1 = {&var393,&var141,&var1093,&vainSBool,&internal1_m1667_q0};
_S_rs  S_rs_1666_1 = {&var99,&var143,&var1094,&vainSBool,&internal1_m1666_q0};
_S_rs  S_rs_1665_1 = {&var395,&var145,&var1095,&vainSBool,&internal1_m1665_q0};
_S_noto  S_noto_1225_1 = {&A2MD12LP1,&var1096};
_S_noto  S_noto_1209_1 = {&B2MD12LP1,&var1097};
_S_noto  S_noto_504_1 = {&B1MD12LP1,&var1098};
_S_ma  S_ma_1444_1 = {array_m1444_x_1,&var1072,&iRM_16_,&var1099};
_S_noto  S_noto_1399_1 = {&var720,&var1100};
_S_zpfs  S_zpfs_1661_1 = {&var1144,&fRM_2_0,&var1101,&internal1_m1661_tx,&internal1_m1661_y0};
_S_zpfs  S_zpfs_1654_1 = {&var1148,&fRM_2_0,&var1102,&internal1_m1654_tx,&internal1_m1654_y0};
_S_noto  S_noto_135_1 = {&var868,&var1103};
_S_equz_p  S_equz_p_1789_1 = {&R0MW14IP2,&iRM_5_,&var1104};
_S_equz_p  S_equz_p_1788_1 = {&R0MW14IP2,&iRM_4_,&var1105};
_S_equz_p  S_equz_p_1787_1 = {&R0MW14IP2,&iRM_3_,&var1106};
_S_equz_p  S_equz_p_1785_1 = {&R0MW14IP2,&iRM_1_,&vainSBool};
_S_equz_p  S_equz_p_1786_1 = {&R0MW14IP2,&iRM_2_,&var1107};
_S_noto  S_noto_1842_1 = {&B3IS11LDU,&var1108};
_S_noto  S_noto_1837_1 = {&A3IS11LDU,&var1109};
_S_noto  S_noto_1879_1 = {&B2IS11LDU,&var1110};
_S_noto  S_noto_1886_1 = {&A2IS11LDU,&var1111};
_S_noto  S_noto_12_1 = {&var1580,&var1112};
_S_rs  S_rs_1946_1 = {&var237,&var344,&var1113,&vainSBool,&internal1_m1946_q0};
_S_rs  S_rs_1726_1 = {&var387,&var160,&var1114,&vainSBool,&internal1_m1726_q0};
_S_rs  S_rs_1725_1 = {&var109,&var161,&var1115,&vainSBool,&internal1_m1725_q0};
_S_rs  S_rs_1723_1 = {&var388,&var162,&var1116,&vainSBool,&internal1_m1723_q0};
_S_rs  S_rs_1722_1 = {&var109,&var163,&var1117,&vainSBool,&internal1_m1722_q0};
_S_rs  S_rs_1720_1 = {&var389,&var164,&var1118,&vainSBool,&internal1_m1720_q0};
_S_equz_p  S_equz_p_98_1 = {&R0MW16IP1,&iRM_10_,&var1119};
_S_noto  S_noto_173_1 = {&A1MD12LP1,&var1120};
_S_zpfs  S_zpfs_1710_1 = {&var1124,&fEM_A3UP34RDU,&var1121,&internal1_m1710_tx,&internal1_m1710_y0};
_S_zpfs  S_zpfs_1709_1 = {&var1126,&fEM_A3UP34RDU,&var1122,&internal1_m1709_tx,&internal1_m1709_y0};
_S_rs  S_rs_1697_1 = {&var1086,&var146,&var1123,&vainSBool,&internal1_m1697_q0};
_S_rs  S_rs_1707_1 = {&var390,&var147,&var1124,&vainSBool,&internal1_m1707_q0};
_S_rs  S_rs_1706_1 = {&var1086,&var148,&var1125,&vainSBool,&internal1_m1706_q0};
_S_rs  S_rs_1704_1 = {&var391,&var149,&var1126,&vainSBool,&internal1_m1704_q0};
_S_rs  S_rs_1698_1 = {&var392,&var157,&var1127,&vainSBool,&internal1_m1698_q0};
_S_rs  S_rs_1688_1 = {&var99,&var138,&var1128,&vainSBool,&internal1_m1688_q0};
_S_rs  S_rs_1687_1 = {&var96,&var139,&var1129,&vainSBool,&internal1_m1687_q0};
_S_rs  S_rs_1683_1 = {&var394,&var141,&var1130,&vainSBool,&internal1_m1683_q0};
_S_rs  S_rs_1685_1 = {&var393,&var140,&var1131,&vainSBool,&internal1_m1685_q0};
_S_rs  S_rs_1682_1 = {&var99,&var142,&var1132,&vainSBool,&internal1_m1682_q0};
_S_rs  S_rs_1681_1 = {&var96,&var143,&var1133,&vainSBool,&internal1_m1681_q0};
_S_rs  S_rs_1677_1 = {&var396,&var145,&var1134,&vainSBool,&internal1_m1677_q0};
_S_rs  S_rs_1679_1 = {&var395,&var144,&var1135,&vainSBool,&internal1_m1679_q0};
_S_rs  S_rs_19_1 = {&var818,&var263,&var1136,&vainSBool,&internal1_m19_q0};
_S_equz_p  S_equz_p_97_1 = {&R0MW16IP1,&iRM_9_,&var1137};
_S_equz_p  S_equz_p_96_1 = {&R0MW16IP1,&iRM_8_,&var1138};
_S_noto  S_noto_927_1 = {&A3MD12LP1,&var1139};
_S_equz_p  S_equz_p_95_1 = {&R0MW16IP1,&iRM_7_,&var1140};
_S_equz_p  S_equz_p_94_1 = {&R0MW16IP1,&iRM_6_,&var1141};
_S_equz_p  S_equz_p_93_1 = {&R0MW16IP1,&iRM_5_,&var1142};
_S_rs  S_rs_1662_1 = {&var96,&var126,&var1143,&vainSBool,&internal1_m1662_q0};
_S_rs  S_rs_1660_1 = {&var1101,&var127,&var1144,&vainSBool,&internal1_m1660_q0};
_S_rs  S_rs_1656_1 = {&var406,&var131,&var1145,&vainSBool,&internal1_m1656_q0};
_S_rs  S_rs_1658_1 = {&var129,&var128,&var1146,&vainSBool,&internal1_m1658_q0};
_S_rs  S_rs_1655_1 = {&var96,&var132,&var1147,&vainSBool,&internal1_m1655_q0};
_S_rs  S_rs_1653_1 = {&var1102,&var133,&var1148,&vainSBool,&internal1_m1653_q0};
_S_rs  S_rs_2046_1 = {&var116,&var353,&var1149,&vainSBool,&internal1_m2046_q0};
_S_rs  S_rs_2042_1 = {&var117,&var355,&var1150,&vainSBool,&internal1_m2042_q0};
_S_equz_p  S_equz_p_289_1 = {&var968,&iRM_0_,&var1151};
_S_noto  S_noto_2047_1 = {&var1149,&var1152};
_S_noto  S_noto_2040_1 = {&var267,&var1153};
_S_noto  S_noto_2030_1 = {&var1155,&var1154};
_S_rs  S_rs_2029_1 = {&var59,&var350,&var1155,&vainSBool,&internal1_m2029_q0};
_S_noto  S_noto_2022_1 = {&var1157,&var1156};
_S_rs  S_rs_2021_1 = {&var60,&var347,&var1157,&vainSBool,&internal1_m2021_q0};
_S_noto  S_noto_2043_1 = {&var1150,&var1158};
_S_noto  S_noto_2037_1 = {&var266,&var1159};
_S_noto  S_noto_1957_1 = {&var1161,&var1160};
_S_rs  S_rs_1956_1 = {&var236,&var345,&var1161,&vainSBool,&internal1_m1956_q0};
_S_noto  S_noto_1947_1 = {&var1113,&var1162};
_S_noto  S_noto_1952_1 = {&var264,&var1163};
_S_noto  S_noto_1942_1 = {&var265,&var1164};
_S_rs  S_rs_1649_1 = {&var407,&var137,&var1165,&vainSBool,&internal1_m1649_q0};
_S_rs  S_rs_1651_1 = {&var134,&var136,&var1166,&vainSBool,&internal1_m1651_q0};
_S_rs  S_rs_1636_1 = {&var96,&var118,&var1167,&vainSBool,&internal1_m1636_q0};
_S_rs  S_rs_1634_1 = {&var408,&var119,&var1168,&vainSBool,&internal1_m1634_q0};
_S_rs  S_rs_1633_1 = {&var96,&var120,&var1169,&vainSBool,&internal1_m1633_q0};
_S_rs  S_rs_1631_1 = {&var409,&var121,&var1170,&vainSBool,&internal1_m1631_q0};
_S_noto  S_noto_1746_1 = {&B3IS22LDU,&var1171};
_S_noto  S_noto_1745_1 = {&A3IS22LDU,&var1172};
_S_noto  S_noto_1744_1 = {&B2IS12LDU,&var1173};
_S_noto  S_noto_1743_1 = {&A2IS12LDU,&var1174};
_S_noto  S_noto_1742_1 = {&B1IS12LDU,&var1175};
_S_noto  S_noto_1741_1 = {&A1IS12LDU,&var1176};
_S_noto  S_noto_1771_1 = {&B3IS21LDU,&var1177};
_S_noto  S_noto_1765_1 = {&B2IS21LDU,&var1178};
_S_noto  S_noto_1770_1 = {&A3IS21LDU,&var1179};
_S_noto  S_noto_1768_1 = {&B4IS21LDU,&var1180};
_S_noto  S_noto_1769_1 = {&A4IS21LDU,&var1181};
_S_andn  S_andn_1754_1 = {array_m1754_x_1,&iRM_17_,&var1182};
_S_noto  S_noto_1763_1 = {&B1IS21LDU,&var1183};
_S_noto  S_noto_1764_1 = {&A2IS21LDU,&var1184};
_S_noto  S_noto_1762_1 = {&A1IS21LDU,&var1185};
_S_rs  S_rs_1630_1 = {&var1190,&var122,&var1186,&vainSBool,&internal1_m1630_q0};
_S_rs  S_rs_1628_1 = {&var410,&var123,&var1187,&vainSBool,&internal1_m1628_q0};
_S_rs  S_rs_1627_1 = {&var1190,&var124,&var1188,&vainSBool,&internal1_m1627_q0};
_S_rs  S_rs_1625_1 = {&var411,&var125,&var1189,&vainSBool,&internal1_m1625_q0};
_S_newstage  S_newstage_2066_1 = {&var1202,&var1196,&var1201,&var1195,&var1190};
_S_samhd  S_samhd_2068_1 = {&var414,&var415,&var415,&var1187,&var1186,&var1187,&var1186,&B9IS11LDU,&B9IS11LDU,&B9IS21LDU,&B9IS21LDU,&bRM_1_,&fEM_A9UZ05RDU,&fEM_A9UZ03RDU,&fEM_A9UZ04RDU,&var1191,&var1192,&vainSBool,&var1193,&var1194,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1195,&var1196,&bFirstEnterFlag,&internal1_m2068_DvUp0,&internal1_m2068_DvDw0,&internal1_m2068_FDvUp0,&internal1_m2068_FDvDw0,&internal1_m2068_BlDv0,&internal1_m2068_Pkv0,&internal1_m2068_Pkav0,&internal1_m2068_Zkv0,&internal1_m2068_Zkav0,&internal1_m2068_txNm,&internal1_m2068_txSm,&internal1_m2068_txHr,&internal1_m2068_txLd,&internal1_m2068_fef};
_S_samhd  S_samhd_2062_1 = {&var414,&var416,&var416,&var1189,&var1188,&var1189,&var1188,&A9IS11LDU,&A9IS11LDU,&A9IS21LDU,&A9IS21LDU,&bRM_1_,&fEM_A9UZ05RDU,&fEM_A9UZ03RDU,&fEM_A9UZ04RDU,&var1197,&var1198,&vainSBool,&var1199,&var1200,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1201,&var1202,&bFirstEnterFlag,&internal1_m2062_DvUp0,&internal1_m2062_DvDw0,&internal1_m2062_FDvUp0,&internal1_m2062_FDvDw0,&internal1_m2062_BlDv0,&internal1_m2062_Pkv0,&internal1_m2062_Pkav0,&internal1_m2062_Zkv0,&internal1_m2062_Zkav0,&internal1_m2062_txNm,&internal1_m2062_txSm,&internal1_m2062_txHr,&internal1_m2062_txLd,&internal1_m2062_fef};
_S_samhd  S_samhd_360_1 = {&R0MD34LP1,&var663,&var663,&R5AD10LDU,&R5AD20LDU,&R5AD10LDU,&R5AD20LDU,&R5IS11LDU,&R5IS11LDU,&R5IS21LDU,&R5IS21LDU,&bRM_0_,&fEM_R5UZ04RDU,&fEM_R5UZ03RDU,&fEM_R5UL10RDU,&var1203,&var1204,&var1205,&var1206,&vainSBool,&vainSBool,&var1207,&var1208,&var1209,&vainSBool,&vainSBool,&bFirstEnterFlag,&internal1_m360_DvUp0,&internal1_m360_DvDw0,&internal1_m360_FDvUp0,&internal1_m360_FDvDw0,&internal1_m360_BlDv0,&internal1_m360_Pkv0,&internal1_m360_Pkav0,&internal1_m360_Zkv0,&internal1_m360_Zkav0,&internal1_m360_txNm,&internal1_m360_txSm,&internal1_m360_txHr,&internal1_m360_txLd,&internal1_m360_fef};
_S_orni  S_orni_1406_1 = {array_m1406_x_1,&iRM_5_,&var1210,&var1211};
_S_noto  S_noto_77_1 = {&var269,&var1212};
_S_maz  S_maz_295_1 = {array_m295_x_1,&R0MW12IP1,&iRM_3_,&var1213};
_S_maz  S_maz_286_1 = {array_m286_x_1,&R0MW12IP1,&iRM_3_,&var1214};
_S_rs  S_rs_1478_1 = {&var427,&var921,&var1215,&vainSBool,&internal1_m1478_q0};
_S_kvf  S_kvf_1482_1 = {&var1215,&var424,&fRM_0_0,&var1216,&vainSInt,&vainSInt,&internal1_m1482_x0,&internal1_m1482_y0,&bFirstEnterFlag};
_S_kvf  S_kvf_1897_1 = {&var325,&var313,&fRM_0_0,&var1217,&vainSInt,&vainSInt,&internal1_m1897_x0,&internal1_m1897_y0,&bFirstEnterFlag};
_S_kvf  S_kvf_1858_1 = {&var284,&var281,&fRM_0_0,&var1218,&vainSInt,&vainSInt,&internal1_m1858_x0,&internal1_m1858_y0,&bFirstEnterFlag};
_S_equz_p  S_equz_p_37_1 = {&R0MW13IP1,&iRM_1_,&var1219};
_S_noto  S_noto_34_1 = {&var1222,&var1220};
_S_equz_p  S_equz_p_41_1 = {&R0MW13IP1,&iRM_2_,&var1221};
_S_equz_p  S_equz_p_32_1 = {&R0MW13IP1,&iRM_3_,&var1222};
_S_noto  S_noto_1901_1 = {&var1050,&var1223};
_S_rs  S_rs_271_1 = {&var726,&var727,&var1224,&vainSBool,&internal1_m271_q0};
_S_orn  S_orn_589_1 = {array_m589_x_1,&iRM_6_,&var1225};
_S_noto  S_noto_1008_1 = {&lEM_R0MD01LC1,&var1226};
_S_rs  S_rs_999_1 = {&var492,&var821,&var1227,&vainSBool,&internal1_m999_q0};
_S_rs  S_rs_620_1 = {&var681,&var683,&var1228,&vainSBool,&internal1_m620_q0};
_S_noto  S_noto_1386_1 = {&var867,&var1229};
_S_orn  S_orn_1360_1 = {array_m1360_x_1,&iRM_9_,&var1230};
_S_noto  S_noto_1359_1 = {&var1398,&var1231};
_S_noto  S_noto_1358_1 = {&var1408,&var1232};
_S_noto  S_noto_1342_1 = {&var868,&var1233};
_S_noto  S_noto_1350_1 = {&R8IS11LDU,&var1234};
_S_charint  S_charint_1286_1 = {&var1237,&var1235};
_S_ornc  S_ornc_1295_1 = {array_m1295_x_1,&iRM_3_,&var1236,&var1237};
_S_fsumz  S_fsumz_1287_1 = {&var1235,&iRM_1_,&var1238};
_S_cnshd  S_cnshd_1297_1 = {&R0MD34LP1,&var1666,&var898,&var179,&var1236,&var539,&var535,&iRM_1_,array_m1297_Lt_fw_1,array_m1297_Vr_fw_1,&iRM_1_,array_m1297_Lt_bw_1,array_m1297_Vr_bw_1,&fEM_A3UC08RDU,&fEM_A3UC07RDU,&fEM_A3UL01RDU,&fEM_A3UC02RDU,&var1239,&vainSBool,&var1240,&var1241,&var1242,&var1243,&var1244,&var1245,&var1246,&var1247,&var1248,&var1249,&internal1_m1297_X0,&internal1_m1297_t0,&internal1_m1297_BLDv0};
_S_zpfs  S_zpfs_1316_1 = {&var1258,&fRM_2_0,&var1250,&internal1_m1316_tx,&internal1_m1316_y0};
_S_zpfs  S_zpfs_1319_1 = {&var1257,&fRM_3_0,&var1251,&internal1_m1319_tx,&internal1_m1319_y0};
_S_fnapb  S_fnapb_1325_1 = {&var1666,&var898,&var538,&R0MD34LP1,&var1241,&var1248,&fEM_B8UV04RDU,&fEM_A3UV01RDU,&fEM_A3UV02RDU,&fEM_A3UC06RDU,&fEM_A3UC05RDU,&iRM_60_,&fEM_A3UL04RDU,&fEM_A3UL05RDU,&fEM_A3UL03RDU,&var1252,&var1253,&var1254,&var1255,&var1256,&var1257,&var1258,&vainSFloat,&internal1_m1325_xptr,array_m1325_x0_1,array_m1325_tim0_1,&internal1_m1325_mcount,&internal1_m1325_sumtim,&internal1_m1325_sumtakt,&internal1_m1325_StSpeed,&internal1_m1325_Vz0,&internal1_m1325_flRazg,&internal1_m1325_DelSp,&internal1_m1325_z0,&internal1_m1325_txZS,&internal1_m1325_tx,&internal1_m1325_txd,&internal1_m1325_txMBl,&internal1_m1325_txBl,&internal1_m1325_Speed0,&internal1_m1325_xz0,&internal1_m1325_tz0,&internal1_m1325_Shift0,&internal1_m1325_ShCntlSp0,&internal1_m1325_ShiftControl,&bFirstEnterFlag};
_S_newstage  S_newstage_904_1 = {&var1268,&var1236,&var1271,&var1239,&var1259};
_S_rs  S_rs_618_1 = {&var682,&var686,&var1260,&vainSBool,&internal1_m618_q0};
_S_noto  S_noto_986_1 = {&var852,&var1261};
_S_orn  S_orn_960_1 = {array_m960_x_1,&iRM_9_,&var1262};
_S_noto  S_noto_959_1 = {&var1398,&var1263};
_S_noto  S_noto_958_1 = {&var1408,&var1264};
_S_noto  S_noto_940_1 = {&var868,&var1265};
_S_noto  S_noto_950_1 = {&R8IS11LDU,&var1266};
_S_charint  S_charint_881_1 = {&var1269,&var1267};
_S_ornc  S_ornc_890_1 = {array_m890_x_1,&iRM_3_,&var1268,&var1269};
_S_fsumz  S_fsumz_882_1 = {&var1267,&iRM_1_,&var1270};
_S_cnshd  S_cnshd_892_1 = {&R0MD34LP1,&var1670,&var897,&var183,&var1268,&var579,&var580,&iRM_1_,array_m892_Lt_fw_1,array_m892_Vr_fw_1,&iRM_1_,array_m892_Lt_bw_1,array_m892_Vr_bw_1,&fEM_A3UC08RDU,&fEM_A3UC07RDU,&fEM_A3UL01RDU,&fEM_A3UC02RDU,&var1271,&vainSBool,&var1272,&var1273,&var1274,&var1275,&var1276,&var1277,&var1278,&var1279,&var1280,&var1281,&internal1_m892_X0,&internal1_m892_t0,&internal1_m892_BLDv0};
_S_zpfs  S_zpfs_916_1 = {&var1290,&fRM_2_0,&var1282,&internal1_m916_tx,&internal1_m916_y0};
_S_zpfs  S_zpfs_917_1 = {&var1289,&fRM_3_0,&var1283,&internal1_m917_tx,&internal1_m917_y0};
_S_fnapb  S_fnapb_925_1 = {&var1670,&var897,&var578,&R0MD34LP1,&var1273,&var1280,&fEM_B8UV04RDU,&fEM_A3UV01RDU,&fEM_A3UV02RDU,&fEM_A3UC06RDU,&fEM_A3UC05RDU,&iRM_60_,&fEM_A3UL04RDU,&fEM_A3UL05RDU,&fEM_A3UL03RDU,&var1284,&var1285,&var1286,&var1287,&var1288,&var1289,&var1290,&vainSFloat,&internal1_m925_xptr,array_m925_x0_1,array_m925_tim0_1,&internal1_m925_mcount,&internal1_m925_sumtim,&internal1_m925_sumtakt,&internal1_m925_StSpeed,&internal1_m925_Vz0,&internal1_m925_flRazg,&internal1_m925_DelSp,&internal1_m925_z0,&internal1_m925_txZS,&internal1_m925_tx,&internal1_m925_txd,&internal1_m925_txMBl,&internal1_m925_txBl,&internal1_m925_Speed0,&internal1_m925_xz0,&internal1_m925_tz0,&internal1_m925_Shift0,&internal1_m925_ShCntlSp0,&internal1_m925_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_571_1 = {&var867,&var1291};
_S_noto  S_noto_546_1 = {&var1398,&var1292};
_S_noto  S_noto_545_1 = {&var1408,&var1293};
_S_noto  S_noto_530_1 = {&var868,&var1294};
_S_noto  S_noto_537_1 = {&R8IS11LDU,&var1295};
_S_charint  S_charint_482_1 = {&var1298,&var1296};
_S_ornc  S_ornc_488_1 = {array_m488_x_1,&iRM_3_,&var1297,&var1298};
_S_fsumz  S_fsumz_483_1 = {&var1296,&iRM_1_,&var1299};
_S_cnshd  S_cnshd_491_1 = {&R0MD34LP1,&var1683,&var899,&var187,&var1297,&var653,&var647,&iRM_2_,array_m491_Lt_fw_1,array_m491_Vr_fw_1,&iRM_1_,array_m491_Lt_bw_1,array_m491_Vr_bw_1,&fEM_A1UC08RDU,&fEM_A1UC07RDU,&fEM_A1UL01RDU,&fEM_A1UC02RDU,&var1300,&vainSBool,&var1301,&var1302,&var1303,&var1304,&var1305,&var1306,&var1307,&var1308,&var1309,&var1310,&internal1_m491_X0,&internal1_m491_t0,&internal1_m491_BLDv0};
_S_zpfs  S_zpfs_511_1 = {&var1319,&fRM_2_0,&var1311,&internal1_m511_tx,&internal1_m511_y0};
_S_zpfs  S_zpfs_514_1 = {&var1318,&fRM_3_0,&var1312,&internal1_m514_tx,&internal1_m514_y0};
_S_fnapb  S_fnapb_518_1 = {&var1683,&var899,&var651,&R0MD34LP1,&var1302,&var1309,&fEM_B8UV04RDU,&fEM_A1UV01RDU,&fEM_A1UV02RDU,&fEM_A1UC06RDU,&fEM_A1UC05RDU,&iRM_150_,&fEM_A1UL04RDU,&fEM_A1UL05RDU,&fEM_A1UL03RDU,&var1313,&var1314,&var1315,&var1316,&var1317,&var1318,&var1319,&vainSFloat,&internal1_m518_xptr,array_m518_x0_1,array_m518_tim0_1,&internal1_m518_mcount,&internal1_m518_sumtim,&internal1_m518_sumtakt,&internal1_m518_StSpeed,&internal1_m518_Vz0,&internal1_m518_flRazg,&internal1_m518_DelSp,&internal1_m518_z0,&internal1_m518_txZS,&internal1_m518_tx,&internal1_m518_txd,&internal1_m518_txMBl,&internal1_m518_txBl,&internal1_m518_Speed0,&internal1_m518_xz0,&internal1_m518_tz0,&internal1_m518_Shift0,&internal1_m518_ShCntlSp0,&internal1_m518_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_636_1 = {&R0MD33LP1,&var1320};
_S_noto  S_noto_250_1 = {&var852,&var1321};
_S_newstage  S_newstage_200_1 = {&var1330,&var1297,&var1333,&var1300,&var1322};
_S_rs  S_rs_615_1 = {&var677,&var689,&var1323,&vainSBool,&internal1_m615_q0};
_S_orn  S_orn_223_1 = {array_m223_x_1,&iRM_12_,&var1324};
_S_noto  S_noto_222_1 = {&var1398,&var1325};
_S_noto  S_noto_221_1 = {&var1408,&var1326};
_S_noto  S_noto_206_1 = {&var868,&var1327};
_S_noto  S_noto_213_1 = {&R8IS11LDU,&var1328};
_S_charint  S_charint_152_1 = {&var1331,&var1329};
_S_ornc  S_ornc_160_1 = {array_m160_x_1,&iRM_3_,&var1330,&var1331};
_S_fsumz  S_fsumz_153_1 = {&var1329,&iRM_1_,&var1332};
_S_cnshd  S_cnshd_163_1 = {&R0MD34LP1,&var1654,&var900,&var191,&var1330,&var633,&var626,&iRM_2_,array_m163_Lt_fw_1,array_m163_Vr_fw_1,&iRM_1_,array_m163_Lt_bw_1,array_m163_Vr_bw_1,&fEM_A1UC08RDU,&fEM_A1UC07RDU,&fEM_A1UL01RDU,&fEM_A1UC02RDU,&var1333,&vainSBool,&var1334,&var1335,&var1336,&var1337,&var1338,&var1339,&var1340,&var1341,&var1342,&var1343,&internal1_m163_X0,&internal1_m163_t0,&internal1_m163_BLDv0};
_S_fnapb  S_fnapb_192_1 = {&var1654,&var900,&var629,&R0MD34LP1,&var1335,&var1342,&fEM_B8UV04RDU,&fEM_A1UV01RDU,&fEM_A1UV02RDU,&fEM_A1UC06RDU,&fEM_A1UC05RDU,&iRM_150_,&fEM_A1UL04RDU,&fEM_A1UL05RDU,&fEM_A1UL03RDU,&var1344,&var1345,&var1346,&var1347,&var1348,&var1349,&var1350,&vainSFloat,&internal1_m192_xptr,array_m192_x0_1,array_m192_tim0_1,&internal1_m192_mcount,&internal1_m192_sumtim,&internal1_m192_sumtakt,&internal1_m192_StSpeed,&internal1_m192_Vz0,&internal1_m192_flRazg,&internal1_m192_DelSp,&internal1_m192_z0,&internal1_m192_txZS,&internal1_m192_tx,&internal1_m192_txd,&internal1_m192_txMBl,&internal1_m192_txBl,&internal1_m192_Speed0,&internal1_m192_xz0,&internal1_m192_tz0,&internal1_m192_Shift0,&internal1_m192_ShCntlSp0,&internal1_m192_ShiftControl,&bFirstEnterFlag};
_S_rs  S_rs_641_1 = {&var688,&var691,&var1351,&vainSBool,&internal1_m641_q0};
_S_newstage  S_newstage_458_1 = {&var1370,&var1361,&var1369,&var1360,&var1352};
_S_samhd  S_samhd_462_1 = {&R0MD34LP1,&var656,&var656,&var247,&var246,&R2VS12LDU,&R2VS22LDU,&R2IS11LDU,&R2IS11LDU,&R2IS21LDU,&R2IS21LDU,&bRM_0_,&fEM_R1UZ05RDU,&fEM_R1UZ03RDU,&fEM_R1UZ04RDU,&var1353,&var1354,&var1355,&var1356,&var1357,&var1358,&vainSBool,&vainSBool,&var1359,&var1360,&var1361,&bFirstEnterFlag,&internal1_m462_DvUp0,&internal1_m462_DvDw0,&internal1_m462_FDvUp0,&internal1_m462_FDvDw0,&internal1_m462_BlDv0,&internal1_m462_Pkv0,&internal1_m462_Pkav0,&internal1_m462_Zkv0,&internal1_m462_Zkav0,&internal1_m462_txNm,&internal1_m462_txSm,&internal1_m462_txHr,&internal1_m462_txLd,&internal1_m462_fef};
_S_samhd  S_samhd_456_1 = {&R0MD34LP1,&var657,&var657,&var245,&var244,&R1VS12LDU,&R1VS22LDU,&R1IS11LDU,&R1IS11LDU,&R1IS21LDU,&R1IS21LDU,&bRM_0_,&fEM_R1UZ05RDU,&fEM_R1UZ03RDU,&fEM_R1UZ04RDU,&var1362,&var1363,&var1364,&var1365,&var1366,&var1367,&vainSBool,&vainSBool,&var1368,&var1369,&var1370,&bFirstEnterFlag,&internal1_m456_DvUp0,&internal1_m456_DvDw0,&internal1_m456_FDvUp0,&internal1_m456_FDvDw0,&internal1_m456_BlDv0,&internal1_m456_Pkv0,&internal1_m456_Pkav0,&internal1_m456_Zkv0,&internal1_m456_Zkav0,&internal1_m456_txNm,&internal1_m456_txSm,&internal1_m456_txHr,&internal1_m456_txLd,&internal1_m456_fef};
_S_orn  S_orn_864_1 = {array_m864_x_1,&iRM_10_,&var1371};
_S_noto  S_noto_863_1 = {&var1398,&var1372};
_S_noto  S_noto_862_1 = {&var1408,&var1373};
_S_noto  S_noto_845_1 = {&var868,&var1374};
_S_noto  S_noto_854_1 = {&R8IS11LDU,&var1375};
_S_charint  S_charint_801_1 = {&var1378,&var1376};
_S_ornc  S_ornc_808_1 = {array_m808_x_1,&iRM_3_,&var1377,&var1378};
_S_fsumz  S_fsumz_802_1 = {&var1376,&iRM_1_,&var1379};
_S_cnshd  S_cnshd_811_1 = {&R0MD34LP1,&var1674,&var896,&var896,&var1377,&var604,&var510,&iRM_2_,array_m811_Lt_fw_1,array_m811_Vr_fw_1,&iRM_1_,array_m811_Lt_bw_1,array_m811_Vr_bw_1,&fEM_A2UC08RDU,&fEM_A2UC07RDU,&fEM_A2UL01RDU,&fEM_A2UC02RDU,&var1380,&vainSBool,&var1381,&var1382,&var1383,&var1384,&var1385,&var1386,&var1387,&var1388,&var1389,&var1390,&internal1_m811_X0,&internal1_m811_t0,&internal1_m811_BLDv0};
_S_fnapb  S_fnapb_831_1 = {&var1674,&var896,&var600,&R0MD34LP1,&var1382,&var1389,&fEM_B8UV04RDU,&fEM_A2UV01RDU,&fEM_A2UV02RDU,&fEM_A2UC06RDU,&fEM_A2UC05RDU,&iRM_80_,&fEM_A2UL04RDU,&fEM_A2UL05RDU,&fEM_A2UL83RDU,&var1391,&var1392,&var1393,&var1394,&var1395,&var1396,&var1397,&vainSFloat,&internal1_m831_xptr,array_m831_x0_1,array_m831_tim0_1,&internal1_m831_mcount,&internal1_m831_sumtim,&internal1_m831_sumtakt,&internal1_m831_StSpeed,&internal1_m831_Vz0,&internal1_m831_flRazg,&internal1_m831_DelSp,&internal1_m831_z0,&internal1_m831_txZS,&internal1_m831_tx,&internal1_m831_txd,&internal1_m831_txMBl,&internal1_m831_txBl,&internal1_m831_Speed0,&internal1_m831_xz0,&internal1_m831_tz0,&internal1_m831_Shift0,&internal1_m831_ShCntlSp0,&internal1_m831_ShiftControl,&bFirstEnterFlag};
_S_cnshd  S_cnshd_1584_1 = {&R0MD34LP1,&var1662,&var175,&var175,&var418,&var421,&lRM_1_,&iRM_1_,array_m1584_Lt_fw_1,array_m1584_Vr_fw_1,&iRM_1_,array_m1584_Lt_bw_1,array_m1584_Vr_bw_1,&fEM_B8UC01RDU,&fEM_B8UC02RDU,&fEM_B8UL01RDU,&fRM_0_0,&var1398,&vainSBool,&vainSFloat,&var1399,&var1400,&var1401,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1402,&internal1_m1584_X0,&internal1_m1584_t0,&internal1_m1584_BLDv0};
_S_newstage  S_newstage_1239_1 = {&var1416,&var1377,&var1421,&var1380,&var1403};
_S_orn  S_orn_1269_1 = {array_m1269_x_1,&iRM_10_,&var1404};
_S_orn  S_orn_141_1 = {array_m141_x_1,&iRM_5_,&var1405};
_S_noto  S_noto_1268_1 = {&var1398,&var1406};
_S_noto  S_noto_1267_1 = {&var1408,&var1407};
_S_cnshd  S_cnshd_1116_1 = {&R0MD34LP1,&var1658,&var175,&var175,&var749,&var419,&lRM_1_,&iRM_1_,array_m1116_Lt_fw_1,array_m1116_Vr_fw_1,&iRM_1_,array_m1116_Lt_bw_1,array_m1116_Vr_bw_1,&fEM_B8UC01RDU,&fEM_B8UC02RDU,&fEM_B8UL01RDU,&fRM_0_0,&var1408,&vainSBool,&vainSFloat,&var1409,&var1410,&var1411,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1412,&internal1_m1116_X0,&internal1_m1116_t0,&internal1_m1116_BLDv0};
_S_noto  S_noto_1250_1 = {&var868,&var1413};
_S_noto  S_noto_1259_1 = {&R8IS11LDU,&var1414};
_S_charint  S_charint_1189_1 = {&var1417,&var1415};
_S_ornc  S_ornc_1198_1 = {array_m1198_x_1,&iRM_3_,&var1416,&var1417};
_S_noto  S_noto_600_1 = {&lEM_R0MD01LC1,&var1418};
_S_fsumz  S_fsumz_1190_1 = {&var1415,&iRM_1_,&var1419};
_S_rs  S_rs_613_1 = {&var699,&var701,&var1420,&vainSBool,&internal1_m613_q0};
_S_cnshd  S_cnshd_1199_1 = {&R0MD34LP1,&var1678,&var895,&var895,&var1416,&var515,&var506,&iRM_2_,array_m1199_Lt_fw_1,array_m1199_Vr_fw_1,&iRM_1_,array_m1199_Lt_bw_1,array_m1199_Vr_bw_1,&fEM_A2UC08RDU,&fEM_A2UC07RDU,&fEM_A2UL01RDU,&fEM_A2UC02RDU,&var1421,&vainSBool,&var1422,&var1423,&var1424,&var1425,&var1426,&var1427,&var1428,&var1429,&var1430,&var1431,&internal1_m1199_X0,&internal1_m1199_t0,&internal1_m1199_BLDv0};
_S_zpfs  S_zpfs_1219_1 = {&var1440,&fRM_2_0,&var1432,&internal1_m1219_tx,&internal1_m1219_y0};
_S_zpfs  S_zpfs_1227_1 = {&var1439,&fRM_3_0,&var1433,&internal1_m1227_tx,&internal1_m1227_y0};
_S_fnapb  S_fnapb_1232_1 = {&var1678,&var895,&var516,&R0MD34LP1,&var1423,&var1430,&fEM_B8UV04RDU,&fEM_A2UV01RDU,&fEM_A2UV02RDU,&fEM_A2UC06RDU,&fEM_A2UC05RDU,&iRM_80_,&fEM_A2UL04RDU,&fEM_A2UL05RDU,&fEM_A2UL03RDU,&var1434,&var1435,&var1436,&var1437,&var1438,&var1439,&var1440,&vainSFloat,&internal1_m1232_xptr,array_m1232_x0_1,array_m1232_tim0_1,&internal1_m1232_mcount,&internal1_m1232_sumtim,&internal1_m1232_sumtakt,&internal1_m1232_StSpeed,&internal1_m1232_Vz0,&internal1_m1232_flRazg,&internal1_m1232_DelSp,&internal1_m1232_z0,&internal1_m1232_txZS,&internal1_m1232_tx,&internal1_m1232_txd,&internal1_m1232_txMBl,&internal1_m1232_txBl,&internal1_m1232_Speed0,&internal1_m1232_xz0,&internal1_m1232_tz0,&internal1_m1232_Shift0,&internal1_m1232_ShCntlSp0,&internal1_m1232_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_1569_1 = {&R8IS11LDU,&var1441};
_S_rs  S_rs_633_1 = {&var702,&var703,&var1442,&vainSBool,&internal1_m633_q0};
_S_zpfs  S_zpfs_1597_1 = {&var1453,&fRM_2_0,&var1443,&internal1_m1597_tx,&internal1_m1597_y0};
_S_zpfs  S_zpfs_1601_1 = {&var1452,&fRM_3_0,&var1444,&internal1_m1601_tx,&internal1_m1601_y0};
_S_samhd  S_samhd_1587_1 = {&R0MD34LP1,&var421,&var421,&var1400,&var1401,&var1447,&var1448,&A8IS12LDU,&A8IS12LDU,&A8IS22LDU,&A8IS22LDU,&bRM_3_,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&fEM_B8UL07RDU,&vainSBool,&vainSBool,&var1445,&var1446,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,&bFirstEnterFlag,&internal1_m1587_DvUp0,&internal1_m1587_DvDw0,&internal1_m1587_FDvUp0,&internal1_m1587_FDvDw0,&internal1_m1587_BlDv0,&internal1_m1587_Pkv0,&internal1_m1587_Pkav0,&internal1_m1587_Zkv0,&internal1_m1587_Zkav0,&internal1_m1587_txNm,&internal1_m1587_txSm,&internal1_m1587_txHr,&internal1_m1587_txLd,&internal1_m1587_fef};
_S_fnapb  S_fnapb_1604_1 = {&var1662,&var175,&var417,&R0MD34LP1,&var1399,&fEM_B8UV03RDU,&fEM_B8UV04RDU,&fEM_B8UV01RDU,&fEM_B8UV02RDU,&fEM_B8UC06RDU,&fEM_B8UC05RDU,&iRM_20_,&fEM_B8UL04RDU,&fEM_B8UL06RDU,&fEM_B8UL03RDU,&var1447,&var1448,&var1449,&var1450,&var1451,&var1452,&var1453,&vainSFloat,&internal1_m1604_xptr,array_m1604_x0_1,array_m1604_tim0_1,&internal1_m1604_mcount,&internal1_m1604_sumtim,&internal1_m1604_sumtakt,&internal1_m1604_StSpeed,&internal1_m1604_Vz0,&internal1_m1604_flRazg,&internal1_m1604_DelSp,&internal1_m1604_z0,&internal1_m1604_txZS,&internal1_m1604_tx,&internal1_m1604_txd,&internal1_m1604_txMBl,&internal1_m1604_txBl,&internal1_m1604_Speed0,&internal1_m1604_xz0,&internal1_m1604_tz0,&internal1_m1604_Shift0,&internal1_m1604_ShCntlSp0,&internal1_m1604_ShiftControl,&bFirstEnterFlag};
_S_zpfs  S_zpfs_1130_1 = {&var1470,&fRM_2_0,&var1454,&internal1_m1130_tx,&internal1_m1130_y0};
_S_zpfs  S_zpfs_1133_1 = {&var1469,&fRM_3_0,&var1455,&internal1_m1133_tx,&internal1_m1133_y0};
_S_noto  S_noto_1103_1 = {&R8IS11LDU,&var1456};
_S_orn  S_orn_1088_1 = {array_m1088_x_1,&iRM_8_,&var1457};
_S_noto  S_noto_602_1 = {&var1461,&var1458};
_S_rs  S_rs_623_1 = {&var704,&var705,&var1459,&vainSBool,&internal1_m623_q0};
_S_orn  S_orn_590_1 = {array_m590_x_1,&iRM_18_,&var1460};
_S_rs  S_rs_588_1 = {&var1225,&var822,&var1461,&vainSBool,&internal1_m588_q0};
_S_samhd  S_samhd_1120_1 = {&R0MD34LP1,&var419,&var419,&var1410,&var1411,&var1464,&var1465,&B8IS12LDU,&B8IS12LDU,&B8IS22LDU,&B8IS22LDU,&bRM_3_,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&fEM_B8UL07RDU,&vainSBool,&vainSBool,&var1462,&var1463,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,&bFirstEnterFlag,&internal1_m1120_DvUp0,&internal1_m1120_DvDw0,&internal1_m1120_FDvUp0,&internal1_m1120_FDvDw0,&internal1_m1120_BlDv0,&internal1_m1120_Pkv0,&internal1_m1120_Pkav0,&internal1_m1120_Zkv0,&internal1_m1120_Zkav0,&internal1_m1120_txNm,&internal1_m1120_txSm,&internal1_m1120_txHr,&internal1_m1120_txLd,&internal1_m1120_fef};
_S_fnapb  S_fnapb_1138_1 = {&var1658,&var175,&var748,&R0MD34LP1,&var1409,&fEM_B8UV03RDU,&fEM_B8UV04RDU,&fEM_B8UV01RDU,&fEM_B8UV02RDU,&fEM_B8UC06RDU,&fEM_B8UC05RDU,&iRM_20_,&fEM_B8UL04RDU,&fEM_B8UL06RDU,&fEM_B8UL03RDU,&var1464,&var1465,&var1466,&var1467,&var1468,&var1469,&var1470,&vainSFloat,&internal1_m1138_xptr,array_m1138_x0_1,array_m1138_tim0_1,&internal1_m1138_mcount,&internal1_m1138_sumtim,&internal1_m1138_sumtakt,&internal1_m1138_StSpeed,&internal1_m1138_Vz0,&internal1_m1138_flRazg,&internal1_m1138_DelSp,&internal1_m1138_z0,&internal1_m1138_txZS,&internal1_m1138_tx,&internal1_m1138_txd,&internal1_m1138_txMBl,&internal1_m1138_txBl,&internal1_m1138_Speed0,&internal1_m1138_xz0,&internal1_m1138_tz0,&internal1_m1138_Shift0,&internal1_m1138_ShCntlSp0,&internal1_m1138_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_717_1 = {&A5IS21LDU,&var1471};
_S_vmemb  S_vmemb_738_1 = {&var1473,&var1472,&internal1_m738_x0};
_S_noto  S_noto_746_1 = {&R4IS12LDU,&var1473};
_S_vmemb  S_vmemb_708_1 = {&var1471,&var1474,&internal1_m708_x0};
_S_vmemb  S_vmemb_670_1 = {&var1489,&var1475,&internal1_m670_x0};
_S_newstage  S_newstage_783_1 = {&var1533,&var1524,&var1532,&var1523,&var1476};
_S_newstage  S_newstage_1170_1 = {&var1515,&var1506,&var1514,&var1505,&var1477};
_S_newstage  S_newstage_388_1 = {&var1560,&var1551,&var1559,&var1550,&var1478};
_S_noto  S_noto_758_1 = {&R4IS22LDU,&var1479};
_S_rs  S_rs_765_1 = {&var769,&var1478,&var1480,&vainSBool,&internal1_m765_q0};
_S_rs  S_rs_759_1 = {&var770,&var874,&var1481,&vainSBool,&internal1_m759_q0};
_S_noto  S_noto_750_1 = {&var1562,&var1482};
_S_noto  S_noto_748_1 = {&var1563,&var1483};
_S_rs  S_rs_726_1 = {&var774,&var1478,&var1484,&vainSBool,&internal1_m726_q0};
_S_rs  S_rs_731_1 = {&var773,&var1476,&var1485,&vainSBool,&internal1_m731_q0};
_S_rs  S_rs_739_1 = {&var843,&var779,&var1486,&vainSBool,&internal1_m739_q0};
_S_rs  S_rs_751_1 = {&var771,&var777,&var1487,&vainSBool,&internal1_m751_q0};
_S_noto  S_noto_707_1 = {&R4IS22LDU,&var1488};
_S_noto  S_noto_663_1 = {&R4IS12LDU,&var1489};
_S_noto  S_noto_418_1 = {&R8IS11LDU,&var1490};
_S_orn  S_orn_432_1 = {array_m432_x_1,&iRM_7_,&var1491};
_S_orn  S_orn_414_1 = {array_m414_x_1,&iRM_7_,&var1492};
_S_rs  S_rs_729_1 = {&var778,&var783,&var1493,&vainSBool,&internal1_m729_q0};
_S_noto  S_noto_149_1 = {&B2IS12LDU,&var1494};
_S_noto  S_noto_138_1 = {&A2IS12LDU,&var1495};
_S_noto  S_noto_139_1 = {&B1IS12LDU,&var1496};
_S_noto  S_noto_147_1 = {&A1IS12LDU,&var1497};
_S_samhd  S_samhd_1175_1 = {&var752,&var753,&var753,&var1080,&var1079,&var1080,&var1079,&B4IS11LDU,&B4IS11LDU,&B4IS21LDU,&B4IS21LDU,&bRM_1_,&fEM_A4UZ05RDU,&fEM_A4UZ03RDU,&fEM_A4UZ04RDU,&var1498,&var1499,&vainSBool,&var1500,&var1501,&vainSBool,&var1502,&var1503,&var1504,&var1505,&var1506,&bFirstEnterFlag,&internal1_m1175_DvUp0,&internal1_m1175_DvDw0,&internal1_m1175_FDvUp0,&internal1_m1175_FDvDw0,&internal1_m1175_BlDv0,&internal1_m1175_Pkv0,&internal1_m1175_Pkav0,&internal1_m1175_Zkv0,&internal1_m1175_Zkav0,&internal1_m1175_txNm,&internal1_m1175_txSm,&internal1_m1175_txHr,&internal1_m1175_txLd,&internal1_m1175_fef};
_S_samhd  S_samhd_1165_1 = {&var752,&var755,&var755,&var1080,&var1079,&var1080,&var1079,&A4IS11LDU,&A4IS11LDU,&A4IS21LDU,&A4IS21LDU,&bRM_1_,&fEM_A4UZ05RDU,&fEM_A4UZ03RDU,&fEM_A4UZ04RDU,&var1507,&var1508,&vainSBool,&var1509,&var1510,&vainSBool,&var1511,&var1512,&var1513,&var1514,&var1515,&bFirstEnterFlag,&internal1_m1165_DvUp0,&internal1_m1165_DvDw0,&internal1_m1165_FDvUp0,&internal1_m1165_FDvDw0,&internal1_m1165_BlDv0,&internal1_m1165_Pkv0,&internal1_m1165_Pkav0,&internal1_m1165_Zkv0,&internal1_m1165_Zkav0,&internal1_m1165_txNm,&internal1_m1165_txSm,&internal1_m1165_txHr,&internal1_m1165_txLd,&internal1_m1165_fef};
_S_samhd  S_samhd_785_1 = {&R0MD34LP1,&var608,&var608,&var875,&var766,&B5VS12LDU,&B5VS22LDU,&B5IS11LDU,&B5IS11LDU,&B5IS21LDU,&B5IS21LDU,&bRM_0_,&fEM_A5UZ05RDU,&fEM_A5UZ03RDU,&fEM_A5UZ04RDU,&var1516,&var1517,&var1518,&var1519,&var1520,&var1521,&vainSBool,&vainSBool,&var1522,&var1523,&var1524,&bFirstEnterFlag,&internal1_m785_DvUp0,&internal1_m785_DvDw0,&internal1_m785_FDvUp0,&internal1_m785_FDvDw0,&internal1_m785_BlDv0,&internal1_m785_Pkv0,&internal1_m785_Pkav0,&internal1_m785_Zkv0,&internal1_m785_Zkav0,&internal1_m785_txNm,&internal1_m785_txSm,&internal1_m785_txHr,&internal1_m785_txLd,&internal1_m785_fef};
_S_samhd  S_samhd_781_1 = {&R0MD34LP1,&var610,&var610,&var875,&var766,&A5VS12LDU,&A5VS22LDU,&A5IS11LDU,&A5IS11LDU,&A5IS21LDU,&A5IS21LDU,&bRM_0_,&fEM_A5UZ05RDU,&fEM_A5UZ03RDU,&fEM_A5UZ04RDU,&var1525,&var1526,&var1527,&var1528,&var1529,&var1530,&vainSBool,&vainSBool,&var1531,&var1532,&var1533,&bFirstEnterFlag,&internal1_m781_DvUp0,&internal1_m781_DvDw0,&internal1_m781_FDvUp0,&internal1_m781_FDvDw0,&internal1_m781_BlDv0,&internal1_m781_Pkv0,&internal1_m781_Pkav0,&internal1_m781_Zkv0,&internal1_m781_Zkav0,&internal1_m781_txNm,&internal1_m781_txSm,&internal1_m781_txHr,&internal1_m781_txLd,&internal1_m781_fef};
_S_samhd  S_samhd_347_1 = {&R0MD34LP1,&var253,&var252,&var775,&var768,&R4VS12LDU,&R4VS22LDU,&R4IS11LDU,&R4IS12LDU,&R4IS21LDU,&R4IS22LDU,&bRM_0_,&fEM_R4UZ05RDU,&fEM_R4UZ03RDU,&fEM_R4UZ04RDU,&var1534,&var1535,&var1536,&var1537,&var1538,&var1539,&vainSBool,&vainSBool,&var1540,&var1541,&vainSBool,&bFirstEnterFlag,&internal1_m347_DvUp0,&internal1_m347_DvDw0,&internal1_m347_FDvUp0,&internal1_m347_FDvDw0,&internal1_m347_BlDv0,&internal1_m347_Pkv0,&internal1_m347_Pkav0,&internal1_m347_Zkv0,&internal1_m347_Zkav0,&internal1_m347_txNm,&internal1_m347_txSm,&internal1_m347_txHr,&internal1_m347_txLd,&internal1_m347_fef};
_S_noto  S_noto_674_1 = {&R8IS11LDU,&var1542};
_S_samhd  S_samhd_391_1 = {&R0MD34LP1,&var1491,&var844,&var851,&var767,&B6VS12LDU,&B6VS22LDU,&B6IS11LDU,&B6IS11LDU,&B6IS21LDU,&B6IS21LDU,&bRM_0_,&fEM_A6UZ05RDU,&fEM_A6UZ03RDU,&fEM_A6UZ04RDU,&var1543,&var1544,&var1545,&var1546,&var1547,&var1548,&vainSBool,&vainSBool,&var1549,&var1550,&var1551,&bFirstEnterFlag,&internal1_m391_DvUp0,&internal1_m391_DvDw0,&internal1_m391_FDvUp0,&internal1_m391_FDvDw0,&internal1_m391_BlDv0,&internal1_m391_Pkv0,&internal1_m391_Pkav0,&internal1_m391_Zkv0,&internal1_m391_Zkav0,&internal1_m391_txNm,&internal1_m391_txSm,&internal1_m391_txHr,&internal1_m391_txLd,&internal1_m391_fef};
_S_samhd  S_samhd_385_1 = {&R0MD34LP1,&var1492,&var845,&var851,&var767,&A6VS12LDU,&A6VS22LDU,&A6IS11LDU,&A6IS11LDU,&A6IS21LDU,&A6IS21LDU,&bRM_0_,&fEM_A6UZ05RDU,&fEM_A6UZ03RDU,&fEM_A6UZ04RDU,&var1552,&var1553,&var1554,&var1555,&var1556,&var1557,&vainSBool,&vainSBool,&var1558,&var1559,&var1560,&bFirstEnterFlag,&internal1_m385_DvUp0,&internal1_m385_DvDw0,&internal1_m385_FDvUp0,&internal1_m385_FDvDw0,&internal1_m385_BlDv0,&internal1_m385_Pkv0,&internal1_m385_Pkav0,&internal1_m385_Zkv0,&internal1_m385_Zkav0,&internal1_m385_txNm,&internal1_m385_txSm,&internal1_m385_txHr,&internal1_m385_txLd,&internal1_m385_fef};
_S_orn  S_orn_764_1 = {array_m764_x_1,&iRM_17_,&var1561};
_S_rs  S_rs_735_1 = {&var781,&R4MD21LP2,&var1562,&vainSBool,&internal1_m735_q0};
_S_rs  S_rs_732_1 = {&var782,&R4MD11LP2,&var1563,&vainSBool,&internal1_m732_q0};
_S_orni  S_orni_127_1 = {array_m127_x_1,&iRM_21_,&var1564,&vainSLong};
_S_equz_p  S_equz_p_74_1 = {&R0MW11IP2,&iRM_6_,&var1565};
_S_equz_p  S_equz_p_72_1 = {&R0MW11IP2,&iRM_5_,&var1566};
_S_equz_p  S_equz_p_70_1 = {&R0MW11IP2,&iRM_4_,&var1567};
_S_equz_p  S_equz_p_69_1 = {&R0MW11IP2,&iRM_3_,&var1568};
_S_equz_p  S_equz_p_68_1 = {&R0MW11IP2,&iRM_2_,&var1569};
_S_equz_p  S_equz_p_65_1 = {&R0MW11IP2,&iRM_1_,&var1570};
_S_equz_p  S_equz_p_61_1 = {&R0MW14IP1,&iRM_3_,&var1571};
_S_equz_p  S_equz_p_55_1 = {&R0MW14IP1,&iRM_1_,&vainSBool};
_S_equz_p  S_equz_p_57_1 = {&R0MW14IP1,&iRM_2_,&var1572};
_S_equz_p  S_equz_p_50_1 = {&R0MW11IP1,&iRM_3_,&var1573};
_S_equz_p  S_equz_p_43_1 = {&R0MW11IP1,&iRM_1_,&var1574};
_S_equz_p  S_equz_p_46_1 = {&R0MW11IP1,&iRM_2_,&var1575};
_S_equz_p  S_equz_p_99_1 = {&R0MW16IP1,&iRM_11_,&var1576};
_S_equz_p  S_equz_p_92_1 = {&R0MW16IP1,&iRM_4_,&var1577};
_S_equz_p  S_equz_p_91_1 = {&R0MW16IP1,&iRM_3_,&var1578};
_S_equz_p  S_equz_p_90_1 = {&R0MW16IP1,&iRM_2_,&var1579};
_S_equz_p  S_equz_p_10_1 = {&R0MW12IP1,&iRM_4_,&var1580};
_S_equz_p  S_equz_p_7_1 = {&R0MW12IP1,&iRM_3_,&var1581};
_S_equz_p  S_equz_p_2_1 = {&R0MW12IP1,&iRM_1_,&var1582};
_S_equz_p  S_equz_p_4_1 = {&R0MW12IP1,&iRM_2_,&var1583};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  equz_p(&S_equz_p_19_2);
  andn(&S_andn_132_2);
  noto(&S_noto_138_2);
  andn(&S_andn_148_2);
  noto(&S_noto_151_2);
  scalzz(&S_scalzz_189_2);
  scalzz(&S_scalzz_191_2);
  or2(&S_or2_11_2);
  or2(&S_or2_43_2);
  or2(&S_or2_13_2);
  or2(&S_or2_44_2);
  or2(&S_or2_74_2);
  or2(&S_or2_71_2);
  and3(&S_and3_79_2);
  or2(&S_or2_103_2);
  or2(&S_or2_104_2);
  and3(&S_and3_110_2);
  and4(&S_and4_134_2);
  and4(&S_and4_157_2);
  schl24(&S_schl24_141_2);
  schl24(&S_schl24_147_2);
  noto(&S_noto_233_2);
  noto(&S_noto_234_2);
  noto(&S_noto_235_2);
  noto(&S_noto_253_2);
  noto(&S_noto_254_2);
  noto(&S_noto_255_2);
  or2(&S_or2_177_2);
  or2(&S_or2_178_2);
  or2(&S_or2_179_2);
  fsumo(&S_fsumo_226_2);
  bol(&S_bol_227_2);
  lkz(&S_lkz_80_2);
  lkz(&S_lkz_111_2);
  drg(&S_drg_200_2);
  drg(&S_drg_193_2);
  geterr(&S_geterr_192_2);
  drg(&S_drg_209_2);
  drg(&S_drg_203_2);
  geterr(&S_geterr_195_2);
  tprg(&S_tprg_214_2);
  tprg(&S_tprg_219_2);
  noto(&S_noto_224_2);
  noto(&S_noto_216_2);
  andn(&S_andn_168_2);
  noto(&S_noto_169_2);
  and2(&S_and2_223_2);
  and3(&S_and3_20_2);
  and3(&S_and3_48_2);
  and3(&S_and3_23_2);
  and3(&S_and3_51_2);
  and3(&S_and3_82_2);
  and3(&S_and3_106_2);
  or3(&S_or3_133_2);
  or3(&S_or3_156_2);
  and2(&S_and2_217_2);
  or2(&S_or2_199_2);
  or2(&S_or2_202_2);
  lkz(&S_lkz_21_2);
  lkz(&S_lkz_52_2);
  lkz(&S_lkz_49_2);
  lkz(&S_lkz_83_2);
  enctkb(&S_enctkb_75_2);
  enctkb(&S_enctkb_112_2);
  lkz(&S_lkz_107_2);
  lkz(&S_lkz_24_2);
  noto(&S_noto_140_2);
  noto(&S_noto_155_2);
  and2(&S_and2_237_2);
  and2(&S_and2_258_2);
  enctkb(&S_enctkb_15_2);
  enctkb(&S_enctkb_53_2);
  enctkb(&S_enctkb_45_2);
  enctkb(&S_enctkb_77_2);
  enctkb(&S_enctkb_108_2);
  enctkb(&S_enctkb_17_2);
  ornc(&S_ornc_238_2);
  ornc(&S_ornc_259_2);
  noto(&S_noto_244_2);
  noto(&S_noto_260_2);
  ornc(&S_ornc_123_2);
  or2(&S_or2_262_2);
  ornc(&S_ornc_236_2);
  ornc(&S_ornc_250_2);
  noto(&S_noto_239_2);
  noto(&S_noto_257_2);
  or2(&S_or2_251_2);
  setData(idB8VC01RDU,&var1658);
  setData(idB2VC01RDU,&var1674);
  setData(idA2VC01RDU,&var1678);
  setData(idA3VC01RDU,&var1670);
  setData(idB0VS11LDU,&var1633);
  setData(idA0VS11LDU,&var1634);
  setData(idB0VN01LDU,&var1602);
  setData(idA0VN01LDU,&var1604);
  setData(idB0VP01LDU,&var1639);
  setData(idA0VP01LDU,&var1640);
  setData(idB0VE01LDU,&var1630);
  setData(idA0VE01LDU,&var1632);
  setData(idA3VP82LDU,&var1600);
  setData(idB3VP82LDU,&var1624);
  setData(idB3VP52LDU,&var1649);
  setData(idB3CP02RDU,&var1625);
  setData(idB3VP42LDU,&var1598);
  setData(idA3VP52LDU,&var1652);
  setData(idA3CP02RDU,&var1626);
  setData(idA3VP42LDU,&var1599);
  setData(idA1VC01RDU,&var1654);
  setData(idA8VC01RDU,&var1662);
  setData(idB3VC01RDU,&var1666);
  setData(idB1VC01RDU,&var1683);
  equz_p(&S_equz_p_4_1);
  equz_p(&S_equz_p_2_1);
  equz_p(&S_equz_p_7_1);
  equz_p(&S_equz_p_10_1);
  equz_p(&S_equz_p_90_1);
  equz_p(&S_equz_p_91_1);
  equz_p(&S_equz_p_92_1);
  equz_p(&S_equz_p_99_1);
  equz_p(&S_equz_p_46_1);
  equz_p(&S_equz_p_43_1);
  equz_p(&S_equz_p_50_1);
  equz_p(&S_equz_p_57_1);
  equz_p(&S_equz_p_55_1);
  equz_p(&S_equz_p_61_1);
  equz_p(&S_equz_p_65_1);
  equz_p(&S_equz_p_68_1);
  equz_p(&S_equz_p_69_1);
  equz_p(&S_equz_p_70_1);
  equz_p(&S_equz_p_72_1);
  equz_p(&S_equz_p_74_1);
  noto(&S_noto_139_1);
  noto(&S_noto_138_1);
  noto(&S_noto_149_1);
  noto(&S_noto_663_1);
  noto(&S_noto_707_1);
  noto(&S_noto_748_1);
  noto(&S_noto_758_1);
  vmemb(&S_vmemb_670_1);
  noto(&S_noto_746_1);
  vmemb(&S_vmemb_738_1);
  noto(&S_noto_717_1);
  noto(&S_noto_1103_1);
  noto(&S_noto_1569_1);
  noto(&S_noto_1259_1);
  noto(&S_noto_854_1);
  noto(&S_noto_213_1);
  noto(&S_noto_537_1);
  noto(&S_noto_950_1);
  rs(&S_rs_618_1);
  noto(&S_noto_1350_1);
  equz_p(&S_equz_p_32_1);
  equz_p(&S_equz_p_41_1);
  noto(&S_noto_34_1);
  equz_p(&S_equz_p_37_1);
  rs(&S_rs_1478_1);
  noto(&S_noto_1764_1);
  noto(&S_noto_1763_1);
  noto(&S_noto_1769_1);
  noto(&S_noto_1765_1);
  noto(&S_noto_1771_1);
  noto(&S_noto_1742_1);
  noto(&S_noto_1743_1);
  noto(&S_noto_1744_1);
  noto(&S_noto_1745_1);
  noto(&S_noto_1746_1);
  noto(&S_noto_2043_1);
  noto(&S_noto_2047_1);
  equz_p(&S_equz_p_93_1);
  equz_p(&S_equz_p_94_1);
  equz_p(&S_equz_p_95_1);
  noto(&S_noto_927_1);
  equz_p(&S_equz_p_96_1);
  equz_p(&S_equz_p_97_1);
  noto(&S_noto_173_1);
  equz_p(&S_equz_p_98_1);
  noto(&S_noto_12_1);
  noto(&S_noto_1842_1);
  equz_p(&S_equz_p_1786_1);
  equz_p(&S_equz_p_1785_1);
  equz_p(&S_equz_p_1787_1);
  equz_p(&S_equz_p_1788_1);
  equz_p(&S_equz_p_1789_1);
  noto(&S_noto_1751_1);
  noto(&S_noto_1804_1);
  noto(&S_noto_1823_1);
  rs(&S_rs_608_1);
  noto(&S_noto_1783_1);
  noto(&S_noto_1809_1);
  noto(&S_noto_1327_1);
  rsun(&S_rsun_1405_1);
  rs(&S_rs_610_1);
  rs(&S_rs_612_1);
  rs(&S_rs_628_1);
  rs(&S_rs_643_1);
  rs(&S_rs_617_1);
  rs(&S_rs_632_1);
  rs(&S_rs_26_1);
  rs(&S_rs_1473_1);
  rs(&S_rs_1428_1);
  rs(&S_rs_1875_1);
  noto(&S_noto_1424_1);
  noto(&S_noto_1463_1);
  noto(&S_noto_1468_1);
  noto(&S_noto_1833_1);
  noto(&S_noto_1870_1);
  noto(&S_noto_1893_1);
  noto(&S_noto_1855_1);
  noto(&S_noto_579_1);
  newstage(&S_newstage_592_1);
  noto(&S_noto_22_1);
  noto(&S_noto_23_1);
  noto(&S_noto_24_1);
  noto(&S_noto_25_1);
  noto(&S_noto_582_1);
  noto(&S_noto_580_1);
  noto(&S_noto_49_1);
  noto(&S_noto_251_1);
  noto(&S_noto_254_1);
  noto(&S_noto_263_1);
  noto(&S_noto_269_1);
  noto(&S_noto_259_1);
  noto(&S_noto_989_1);
  noto(&S_noto_995_1);
  noto(&S_noto_1924_1);
  noto(&S_noto_1926_1);
  rs(&S_rs_1072_1);
  rs(&S_rs_1075_1);
  rs(&S_rs_1078_1);
  rs(&S_rs_1081_1);
  ovbs(&S_ovbs_1173_1);
  ovbs(&S_ovbs_2063_1);
  sr(&S_sr_1065_1);
  bol(&S_bol_1059_1);
  ma(&S_ma_83_1);
  sr(&S_sr_81_1);
  bol(&S_bol_248_1);
  bol(&S_bol_246_1);
  bol(&S_bol_1383_1);
  bol(&S_bol_1381_1);
  bol(&S_bol_983_1);
  bol(&S_bol_981_1);
  bol(&S_bol_567_1);
  bol(&S_bol_569_1);
  bol(&S_bol_578_1);
  bol(&S_bol_584_1);
  and2(&S_and2_736_1);
  and2(&S_and2_755_1);
  and2(&S_and2_27_1);
  and2(&S_and2_28_1);
  and2(&S_and2_29_1);
  and2(&S_and2_30_1);
  and2(&S_and2_42_1);
  and2(&S_and2_38_1);
  and2(&S_and2_727_1);
  or4(&S_or4_417_1);
  or2(&S_or2_740_1);
  or3(&S_or3_5_1);
  or2(&S_or2_6_1);
  or2(&S_or2_1272_1);
  or2(&S_or2_867_1);
  or2(&S_or2_226_1);
  or2(&S_or2_550_1);
  or2(&S_or2_963_1);
  or2(&S_or2_1363_1);
  or2(&S_or2_1064_1);
  and2(&S_and2_1058_1);
  or2(&S_or2_20_1);
  or2(&S_or2_39_1);
  or2(&S_or2_35_1);
  or2(&S_or2_48_1);
  or2(&S_or2_125_1);
  or2(&S_or2_688_1);
  or3(&S_or3_676_1);
  or4(&S_or4_690_1);
  or2(&S_or2_703_1);
  and2(&S_and2_671_1);
  or3(&S_or3_724_1);
  or3(&S_or3_734_1);
  and2(&S_and2_747_1);
  and2(&S_and2_723_1);
  or2(&S_or2_728_1);
  and2(&S_and2_652_1);
  or2(&S_or2_658_1);
  or2(&S_or2_660_1);
  or2(&S_or2_662_1);
  or2(&S_or2_1149_1);
  or2(&S_or2_1174_1);
  and4(&S_and4_1070_1);
  or2(&S_or2_1069_1);
  and2(&S_and2_1084_1);
  or2(&S_or2_1099_1);
  and3(&S_and3_252_1);
  and3(&S_and3_268_1);
  or2(&S_or2_601_1);
  or2(&S_or2_609_1);
  or2(&S_or2_611_1);
  or2(&S_or2_614_1);
  or2(&S_or2_585_1);
  and2(&S_and2_635_1);
  or2(&S_or2_642_1);
  and2(&S_and2_606_1);
  or2(&S_or2_621_1);
  or2(&S_or2_616_1);
  or2(&S_or2_639_1);
  and2(&S_and2_596_1);
  or2(&S_or2_330_1);
  or2(&S_or2_335_1);
  or2(&S_or2_745_1);
  or2(&S_or2_459_1);
  or2(&S_or2_517_1);
  and2(&S_and2_526_1);
  and2(&S_and2_536_1);
  or2(&S_or2_529_1);
  and2(&S_and2_538_1);
  and2(&S_and2_555_1);
  or2(&S_or2_191_1);
  and2(&S_and2_171_1);
  and2(&S_and2_202_1);
  or2(&S_or2_205_1);
  and2(&S_and2_214_1);
  and2(&S_and2_212_1);
  and2(&S_and2_234_1);
  or2(&S_or2_784_1);
  or2(&S_or2_830_1);
  or2(&S_or2_844_1);
  and2(&S_and2_921_1);
  or2(&S_or2_932_1);
  or2(&S_or2_924_1);
  or2(&S_or2_942_1);
  or2(&S_or2_1341_1);
  or2(&S_or2_1324_1);
  and2(&S_and2_1321_1);
  or2(&S_or2_1332_1);
  or2(&S_or2_1249_1);
  or2(&S_or2_1231_1);
  and2(&S_and2_994_1);
  and2(&S_and2_1425_1);
  zpfs(&S_zpfs_1435_1);
  and2(&S_and2_1464_1);
  zpfs(&S_zpfs_1484_1);
  and2(&S_and2_1469_1);
  zpfs(&S_zpfs_1490_1);
  and2(&S_and2_1506_1);
  or2(&S_or2_2064_1);
  or2(&S_or2_1615_1);
  or2(&S_or2_1616_1);
  or2(&S_or2_1565_1);
  or2(&S_or2_1749_1);
  or2(&S_or2_1750_1);
  or4(&S_or4_1756_1);
  or4(&S_or4_1757_1);
  or2(&S_or2_1759_1);
  or2(&S_or2_1753_1);
  or2(&S_or2_1752_1);
  or3(&S_or3_1761_1);
  and2(&S_and2_1817_1);
  or2(&S_or2_1824_1);
  zpfs(&S_zpfs_1793_1);
  zpfs(&S_zpfs_1794_1);
  zpfs(&S_zpfs_1795_1);
  zpfs(&S_zpfs_1796_1);
  or2(&S_or2_1799_1);
  and2(&S_and2_1800_1);
  or2(&S_or2_1815_1);
  or3(&S_or3_1801_1);
  or2(&S_or2_1876_1);
  ma(&S_ma_1461_1);
  zpfs(&S_zpfs_1846_1);
  and2(&S_and2_1847_1);
  or2(&S_or2_1841_1);
  and3(&S_and3_1844_1);
  or2(&S_or2_1852_1);
  or2(&S_or2_228_1);
  ovbs(&S_ovbs_76_1);
  ovbs(&S_ovbs_21_1);
  ovbs(&S_ovbs_117_1);
  ovbs(&S_ovbs_110_1);
  ovbs(&S_ovbs_1419_1);
  ovbs(&S_ovbs_743_1);
  ovbs(&S_ovbs_285_1);
  ovbs(&S_ovbs_327_1);
  ovbs(&S_ovbs_51_1);
  or2(&S_or2_2099_1);
  or2(&S_or2_2084_1);
  or2(&S_or2_1474_1);
  or2(&S_or2_1941_1);
  ovbs(&S_ovbs_1943_1);
  noto(&S_noto_1944_1);
  or2(&S_or2_1987_1);
  or2(&S_or2_1975_1);
  noto(&S_noto_1994_1);
  ovbs(&S_ovbs_2003_1);
  noto(&S_noto_2004_1);
  noto(&S_noto_2014_1);
  noto(&S_noto_102_1);
  and2(&S_and2_101_1);
  bol(&S_bol_1552_1);
  bol(&S_bol_1544_1);
  or2(&S_or2_1546_1);
  bol(&S_bol_1531_1);
  bol(&S_bol_1524_1);
  or2(&S_or2_1529_1);
  bol(&S_bol_1550_1);
  bol(&S_bol_1542_1);
  or2(&S_or2_1549_1);
  bol(&S_bol_1536_1);
  bol(&S_bol_1530_1);
  or2(&S_or2_1534_1);
  and4(&S_and4_45_1);
  bol(&S_bol_1776_1);
  and3(&S_and3_1767_1);
  bol(&S_bol_1740_1);
  and3(&S_and3_1748_1);
  noto(&S_noto_1755_1);
  noto(&S_noto_1766_1);
  abs_subf(&S_abs_subf_1541_1);
  noto(&S_noto_1547_1);
  and2(&S_and2_227_1);
  and2(&S_and2_551_1);
  and2(&S_and2_2188_1);
  rs(&S_rs_2137_1);
  sr(&S_sr_2175_1);
  sr(&S_sr_2153_1);
  rs(&S_rs_2131_1);
  zpfs(&S_zpfs_2159_1);
  or2(&S_or2_2146_1);
  abs_subf(&S_abs_subf_2112_1);
  and2(&S_and2_2121_1);
  noto(&S_noto_1308_1);
  noto(&S_noto_897_1);
  zzfs(&S_zzfs_2122_1);
  noto(&S_noto_2132_1);
  or2(&S_or2_1082_1);
  rs(&S_rs_735_1);
  noto(&S_noto_674_1);
  noto(&S_noto_147_1);
  rs(&S_rs_729_1);
  noto(&S_noto_418_1);
  rs(&S_rs_739_1);
  noto(&S_noto_750_1);
  vmemb(&S_vmemb_708_1);
  rs(&S_rs_623_1);
  rs(&S_rs_633_1);
  rs(&S_rs_613_1);
  noto(&S_noto_600_1);
  rs(&S_rs_641_1);
  noto(&S_noto_250_1);
  noto(&S_noto_636_1);
  noto(&S_noto_571_1);
  noto(&S_noto_986_1);
  noto(&S_noto_1386_1);
  noto(&S_noto_1008_1);
  noto(&S_noto_1901_1);
  kvf(&S_kvf_1482_1);
  noto(&S_noto_77_1);
  samhd(&S_samhd_360_1);
  samhd(&S_samhd_2062_1);
  samhd(&S_samhd_2068_1);
  newstage(&S_newstage_2066_1);
  noto(&S_noto_1762_1);
  noto(&S_noto_1768_1);
  noto(&S_noto_1770_1);
  noto(&S_noto_1741_1);
  noto(&S_noto_1886_1);
  noto(&S_noto_1879_1);
  noto(&S_noto_1837_1);
  noto(&S_noto_504_1);
  noto(&S_noto_1209_1);
  noto(&S_noto_1225_1);
  noto(&S_noto_1811_1);
  rs(&S_rs_1493_1);
  kvf(&S_kvf_1488_1);
  rs(&S_rs_1487_1);
  noto(&S_noto_1498_1);
  noto(&S_noto_1496_1);
  samhd(&S_samhd_2091_1);
  samhd(&S_samhd_2096_1);
  rs(&S_rs_744_1);
  noto(&S_noto_332_1);
  noto(&S_noto_328_1);
  noto(&S_noto_581_1);
  noto(&S_noto_591_1);
  noto(&S_noto_645_1);
  noto(&S_noto_1908_1);
  noto(&S_noto_1933_1);
  swtakt(&S_swtakt_52_1);
  rs(&S_rs_1074_1);
  and2(&S_and2_11_1);
  and2(&S_and2_109_1);
  and2(&S_and2_224_1);
  and2(&S_and2_548_1);
  or2(&S_or2_14_1);
  or2(&S_or2_8_1);
  or2(&S_or2_161_1);
  or2(&S_or2_664_1);
  and2(&S_and2_673_1);
  and2(&S_and2_675_1);
  and2(&S_and2_687_1);
  and2(&S_and2_689_1);
  and2(&S_and2_702_1);
  and2(&S_and2_705_1);
  and3(&S_and3_704_1);
  and2(&S_and2_706_1);
  and3(&S_and3_701_1);
  or2(&S_or2_741_1);
  and2(&S_and2_730_1);
  and2(&S_and2_749_1);
  or2(&S_or2_756_1);
  or2(&S_or2_760_1);
  and3(&S_and3_757_1);
  and2(&S_and2_763_1);
  and2(&S_and2_767_1);
  and2(&S_and2_648_1);
  or2(&S_or2_649_1);
  and2(&S_and2_659_1);
  and2(&S_and2_661_1);
  or2(&S_or2_258_1);
  and3(&S_and3_273_1);
  or2(&S_or2_634_1);
  and2(&S_and2_603_1);
  and2(&S_and2_593_1);
  and4(&S_and4_594_1);
  and4(&S_and4_604_1);
  and2(&S_and2_629_1);
  or2(&S_or2_637_1);
  or2(&S_or2_640_1);
  and3(&S_and3_324_1);
  or4(&S_or4_363_1);
  and2(&S_and2_527_1);
  and2(&S_and2_499_1);
  or2(&S_or2_506_1);
  and2(&S_and2_568_1);
  or2(&S_or2_177_1);
  and2(&S_and2_203_1);
  and2(&S_and2_247_1);
  and2(&S_and2_982_1);
  and2(&S_and2_1382_1);
  and2(&S_and2_1208_1);
  or2(&S_or2_1214_1);
  and2(&S_and2_1220_1);
  or2(&S_or2_1234_1);
  and2(&S_and2_1003_1);
  and2(&S_and2_1013_1);
  and2(&S_and2_1395_1);
  and2(&S_and2_1401_1);
  and2(&S_and2_1407_1);
  and2(&S_and2_1409_1);
  and2(&S_and2_1411_1);
  and2(&S_and2_1417_1);
  and2(&S_and2_1421_1);
  or2(&S_or2_1472_1);
  and2(&S_and2_1436_1);
  and2(&S_and2_1485_1);
  or3(&S_or3_1499_1);
  or2(&S_or2_1481_1);
  and2(&S_and2_1491_1);
  or3(&S_or3_1492_1);
  or3(&S_or3_1505_1);
  or3(&S_or3_2061_1);
  or3(&S_or3_2070_1);
  or2(&S_or2_1758_1);
  or3(&S_or3_1760_1);
  and2(&S_and2_1806_1);
  or3(&S_or3_1802_1);
  and2(&S_and2_1828_1);
  or2(&S_or2_2034_1);
  zpfs(&S_zpfs_2035_1);
  or2(&S_or2_2025_1);
  or2(&S_or2_1959_1);
  or2(&S_or2_1949_1);
  and2(&S_and2_1929_1);
  and2(&S_and2_1927_1);
  and2(&S_and2_1912_1);
  and2(&S_and2_1911_1);
  and2(&S_and2_1881_1);
  and4(&S_and4_1887_1);
  and4(&S_and4_1888_1);
  or2(&S_or2_1889_1);
  or2(&S_or2_1891_1);
  or2(&S_or2_1890_1);
  zpfs(&S_zpfs_1895_1);
  zpfs(&S_zpfs_1898_1);
  zpfs(&S_zpfs_1882_1);
  and2(&S_and2_1883_1);
  or3(&S_or3_1899_1);
  lk(&S_lk_1483_1);
  rsfn(&S_rsfn_1479_1);
  abs_subf(&S_abs_subf_1494_1);
  lk(&S_lk_1480_1);
  rsfn(&S_rsfn_1476_1);
  abs_subf(&S_abs_subf_1489_1);
  and3(&S_and3_1843_1);
  or2(&S_or2_1850_1);
  or2(&S_or2_1851_1);
  zpfs(&S_zpfs_1857_1);
  zpfs(&S_zpfs_1859_1);
  or3(&S_or3_1862_1);
  or2(&S_or2_1864_1);
  or2(&S_or2_242_1);
  ovbs(&S_ovbs_1865_1);
  ovbs(&S_ovbs_1938_1);
  ovbs(&S_ovbs_1951_1);
  ovbs(&S_ovbs_13_1);
  or4(&S_or4_2097_1);
  or4(&S_or4_2092_1);
  and2(&S_and2_1950_1);
  and2(&S_and2_1960_1);
  and2(&S_and2_104_1);
  bol(&S_bol_1535_1);
  bol(&S_bol_1523_1);
  or2(&S_or2_1526_1);
  ml(&S_ml_1538_1);
  ml(&S_ml_1518_1);
  ml(&S_ml_1540_1);
  ml(&S_ml_1519_1);
  zpfs(&S_zpfs_742_1);
  and2(&S_and2_115_1);
  noto(&S_noto_113_1);
  and2(&S_and2_119_1);
  and2(&S_and2_118_1);
  noto(&S_noto_185_1);
  noto(&S_noto_465_1);
  noto(&S_noto_914_1);
  noto(&S_noto_1171_1);
  noto(&S_noto_1221_1);
  bol(&S_bol_905_1);
  bol(&S_bol_1307_1);
  abs_subf(&S_abs_subf_1521_1);
  noto(&S_noto_1532_1);
  abs_subf(&S_abs_subf_1543_1);
  noto(&S_noto_1551_1);
  or2(&S_or2_2033_1);
  bol(&S_bol_2177_1);
  and2(&S_and2_2187_1);
  noto(&S_noto_2145_1);
  or3(&S_or3_124_1);
  fsumo(&S_fsumo_79_1);
  abs_subf(&S_abs_subf_2184_1);
  and2(&S_and2_2189_1);
  and2(&S_and2_2185_1);
  and3(&S_and3_2138_1);
  and2(&S_and2_2160_1);
  ovbs(&S_ovbs_2161_1);
  or3(&S_or3_2169_1);
  inf(&S_inf_2140_1);
  or2(&S_or2_1073_1);
  samhd(&S_samhd_385_1);
  samhd(&S_samhd_391_1);
  samhd(&S_samhd_781_1);
  samhd(&S_samhd_785_1);
  rs(&S_rs_751_1);
  rs(&S_rs_759_1);
  newstage(&S_newstage_388_1);
  newstage(&S_newstage_783_1);
  noto(&S_noto_1250_1);
  noto(&S_noto_845_1);
  noto(&S_noto_206_1);
  rs(&S_rs_615_1);
  noto(&S_noto_530_1);
  noto(&S_noto_940_1);
  noto(&S_noto_1342_1);
  kvf(&S_kvf_1858_1);
  kvf(&S_kvf_1897_1);
  andn(&S_andn_1754_1);
  noto(&S_noto_1942_1);
  noto(&S_noto_1952_1);
  rs(&S_rs_19_1);
  noto(&S_noto_135_1);
  noto(&S_noto_1812_1);
  noto(&S_noto_108_1);
  noto(&S_noto_1389_1);
  abs_subf(&S_abs_subf_1014_1);
  abs_subf(&S_abs_subf_1001_1);
  noto(&S_noto_1021_1);
  bol(&S_bol_1034_1);
  bol(&S_bol_1035_1);
  noto(&S_noto_998_1);
  bol(&S_bol_1037_1);
  bol(&S_bol_1038_1);
  rs(&S_rs_1071_1);
  bol(&S_bol_80_1);
  and2(&S_and2_409_1);
  and2(&S_and2_419_1);
  and2(&S_and2_427_1);
  and2(&S_and2_428_1);
  and2(&S_and2_429_1);
  and2(&S_and2_140_1);
  and2(&S_and2_148_1);
  and2(&S_and2_145_1);
  and2(&S_and2_137_1);
  or3(&S_or3_381_1);
  or3(&S_or3_396_1);
  and2(&S_and2_410_1);
  and2(&S_and2_411_1);
  and3(&S_and3_225_1);
  and3(&S_and3_549_1);
  and3(&S_and3_992_1);
  or3(&S_or3_105_1);
  and2(&S_and2_737_1);
  or2(&S_or2_766_1);
  and2(&S_and2_657_1);
  and2(&S_and2_627_1);
  and2(&S_and2_605_1);
  and2(&S_and2_595_1);
  and3(&S_and3_528_1);
  or2(&S_or2_563_1);
  and3(&S_and3_204_1);
  and3(&S_and3_236_1);
  or4(&S_or4_777_1);
  or4(&S_or4_793_1);
  and3(&S_and3_851_1);
  and3(&S_and3_852_1);
  or2(&S_or2_976_1);
  and3(&S_and3_1348_1);
  and2(&S_and2_1380_1);
  or2(&S_or2_1376_1);
  and3(&S_and3_1256_1);
  and3(&S_and3_1257_1);
  or2(&S_or2_1039_1);
  or2(&S_or2_1051_1);
  or2(&S_or2_1049_1);
  or2(&S_or2_1048_1);
  or2(&S_or2_1047_1);
  or3(&S_or3_1445_1);
  and2(&S_and2_1446_1);
  and3(&S_and3_1502_1);
  or3(&S_or3_1486_1);
  and2(&S_and2_1500_1);
  and3(&S_and3_1503_1);
  zpfs(&S_zpfs_2026_1);
  or2(&S_or2_1955_1);
  or2(&S_or2_1945_1);
  and3(&S_and3_1921_1);
  and2(&S_and2_1916_1);
  or3(&S_or3_1922_1);
  and2(&S_and2_1894_1);
  and4(&S_and4_1902_1);
  and4(&S_and4_1904_1);
  lk(&S_lk_1900_1);
  rsfn(&S_rsfn_1905_1);
  abs_subf(&S_abs_subf_1907_1);
  and3(&S_and3_1910_1);
  lk(&S_lk_1863_1);
  rsfn(&S_rsfn_1866_1);
  abs_subf(&S_abs_subf_1868_1);
  and2(&S_and2_1856_1);
  and3(&S_and3_1860_1);
  or5(&S_or5_142_1);
  ovbs(&S_ovbs_112_1);
  and2(&S_and2_1829_1);
  and2(&S_and2_435_1);
  ml(&S_ml_1516_1);
  and2(&S_and2_1731_1);
  and2(&S_and2_1712_1);
  and2(&S_and2_1729_1);
  and2(&S_and2_1732_1);
  and2(&S_and2_1713_1);
  and2(&S_and2_1730_1);
  and2(&S_and2_1714_1);
  and2(&S_and2_1715_1);
  and2(&S_and2_1716_1);
  and2(&S_and2_1717_1);
  and2(&S_and2_1718_1);
  and2(&S_and2_1719_1);
  and2(&S_and2_1689_1);
  and2(&S_and2_1690_1);
  and2(&S_and2_1691_1);
  and2(&S_and2_1692_1);
  and2(&S_and2_1693_1);
  and2(&S_and2_1694_1);
  and2(&S_and2_1695_1);
  and2(&S_and2_1696_1);
  and2(&S_and2_1669_1);
  and2(&S_and2_1671_1);
  and2(&S_and2_1673_1);
  and2(&S_and2_1675_1);
  and2(&S_and2_1641_1);
  and2(&S_and2_1643_1);
  and2(&S_and2_1645_1);
  or2(&S_or2_1659_1);
  and2(&S_and2_1647_1);
  and2(&S_and2_1617_1);
  and2(&S_and2_1618_1);
  and2(&S_and2_1619_1);
  and2(&S_and2_1620_1);
  and2(&S_and2_1621_1);
  and2(&S_and2_1622_1);
  and2(&S_and2_1623_1);
  and2(&S_and2_1624_1);
  and3(&S_and3_948_1);
  and2(&S_and2_114_1);
  abs_subf(&S_abs_subf_1520_1);
  noto(&S_noto_1527_1);
  irm(&S_irm_2120_1);
  or2(&S_or2_2024_1);
  ovbs(&S_ovbs_2139_1);
  ml(&S_ml_883_1);
  or3(&S_or3_889_1);
  ml(&S_ml_1288_1);
  or3(&S_or3_1294_1);
  noto(&S_noto_2168_1);
  noto(&S_noto_2116_1);
  noto(&S_noto_2117_1);
  rs(&S_rs_731_1);
  rs(&S_rs_765_1);
  orn(&S_orn_141_1);
  ornc(&S_ornc_890_1);
  charint(&S_charint_881_1);
  rs(&S_rs_1627_1);
  rs(&S_rs_1630_1);
  rs(&S_rs_1956_1);
  noto(&S_noto_1957_1);
  rs(&S_rs_1653_1);
  rs(&S_rs_1660_1);
  rs(&S_rs_1704_1);
  rs(&S_rs_1706_1);
  rs(&S_rs_1697_1);
  zpfs(&S_zpfs_1709_1);
  rs(&S_rs_1723_1);
  rs(&S_rs_1726_1);
  rs(&S_rs_1946_1);
  zpfs(&S_zpfs_1654_1);
  zpfs(&S_zpfs_1661_1);
  rs(&S_rs_1665_1);
  rs(&S_rs_1667_1);
  rs(&S_rs_1637_1);
  rs(&S_rs_1639_1);
  rs(&S_rs_106_1);
  noto(&S_noto_107_1);
  rs(&S_rs_1508_1);
  rs(&S_rs_1507_1);
  rs(&S_rs_1438_1);
  kvf(&S_kvf_1442_1);
  rs(&S_rs_1915_1);
  rs(&S_rs_1861_1);
  noto(&S_noto_1441_1);
  andn(&S_andn_257_1);
  noto(&S_noto_274_1);
  noto(&S_noto_66_1);
  and2(&S_and2_58_1);
  and3(&S_and3_583_1);
  and2(&S_and2_62_1);
  or2(&S_or2_144_1);
  and2(&S_and2_678_1);
  or2(&S_or2_265_1);
  and3(&S_and3_266_1);
  and4(&S_and4_318_1);
  or2(&S_or2_437_1);
  and3(&S_and3_444_1);
  or2(&S_or2_490_1);
  and2(&S_and2_510_1);
  and3(&S_and3_557_1);
  and3(&S_and3_556_1);
  and2(&S_and2_179_1);
  and3(&S_and3_235_1);
  or3(&S_or3_843_1);
  and2(&S_and2_841_1);
  and3(&S_and3_842_1);
  and2(&S_and2_840_1);
  and2(&S_and2_855_1);
  and2(&S_and2_853_1);
  and2(&S_and2_870_1);
  and3(&S_and3_871_1);
  and2(&S_and2_935_1);
  or2(&S_or2_941_1);
  and2(&S_and2_949_1);
  and2(&S_and2_968_1);
  and3(&S_and3_969_1);
  and3(&S_and3_970_1);
  and2(&S_and2_980_1);
  or2(&S_or2_1340_1);
  and2(&S_and2_1349_1);
  and2(&S_and2_1351_1);
  and2(&S_and2_1368_1);
  and3(&S_and3_1369_1);
  and3(&S_and3_1370_1);
  and2(&S_and2_1333_1);
  or3(&S_or3_1248_1);
  and3(&S_and3_1247_1);
  and2(&S_and2_1246_1);
  and2(&S_and2_1260_1);
  and2(&S_and2_1245_1);
  and2(&S_and2_1258_1);
  and2(&S_and2_1270_1);
  and3(&S_and3_1271_1);
  and2(&S_and2_1275_1);
  and3(&S_and3_1276_1);
  and2(&S_and2_1218_1);
  and2(&S_and2_1238_1);
  and2(&S_and2_1052_1);
  and2(&S_and2_1055_1);
  or2(&S_or2_1396_1);
  or2(&S_or2_1433_1);
  or3(&S_or3_1437_1);
  or2(&S_or2_1626_1);
  or2(&S_or2_1629_1);
  or2(&S_or2_1705_1);
  or2(&S_or2_1708_1);
  and2(&S_and2_1790_1);
  or2(&S_or2_1791_1);
  and2(&S_and2_1797_1);
  or2(&S_or2_2048_1);
  lk(&S_lk_1443_1);
  rsfn(&S_rsfn_1439_1);
  abs_subf(&S_abs_subf_1448_1);
  ovbs(&S_ovbs_2039_1);
  ovbs(&S_ovbs_2036_1);
  and2(&S_and2_471_1);
  and2(&S_and2_438_1);
  zpfs(&S_zpfs_2124_1);
  zpfs(&S_zpfs_2125_1);
  rs(&S_rs_588_1);
  noto(&S_noto_602_1);
  fsumz(&S_fsumz_882_1);
  orni(&S_orni_1406_1);
  rs(&S_rs_1625_1);
  rs(&S_rs_1628_1);
  noto(&S_noto_1947_1);
  noto(&S_noto_2037_1);
  noto(&S_noto_2040_1);
  rs(&S_rs_1707_1);
  zpfs(&S_zpfs_1710_1);
  ma(&S_ma_1444_1);
  rs(&S_rs_598_1);
  noto(&S_noto_1391_1);
  rs(&S_rs_321_1);
  noto(&S_noto_988_1);
  noto(&S_noto_316_1);
  noto(&S_noto_262_1);
  noto(&S_noto_267_1);
  noto(&S_noto_1050_1);
  noto(&S_noto_1044_1);
  noto(&S_noto_1017_1);
  ma(&S_ma_891_1);
  and2(&S_and2_412_1);
  and2(&S_and2_430_1);
  and2(&S_and2_865_1);
  and3(&S_and3_866_1);
  and2(&S_and2_961_1);
  and3(&S_and3_962_1);
  and3(&S_and3_1362_1);
  and2(&S_and2_1361_1);
  or4(&S_or4_272_1);
  or2(&S_or2_256_1);
  or2(&S_or2_278_1);
  and2(&S_and2_622_1);
  or2(&S_or2_313_1);
  or4(&S_or4_322_1);
  and2(&S_and2_937_1);
  and2(&S_and2_938_1);
  and2(&S_and2_951_1);
  and3(&S_and3_939_1);
  and2(&S_and2_1337_1);
  and2(&S_and2_1338_1);
  and3(&S_and3_1339_1);
  and5(&S_and5_993_1);
  and2(&S_and2_1040_1);
  or4(&S_or4_1000_1);
  and2(&S_and2_1390_1);
  and3(&S_and3_1452_1);
  or2(&S_or2_1798_1);
  and2(&S_and2_1813_1);
  or2(&S_or2_1816_1);
  or2(&S_or2_1814_1);
  and2(&S_and2_2050_1);
  and2(&S_and2_2052_1);
  or2(&S_or2_2045_1);
  noto(&S_noto_2129_1);
  noto(&S_noto_2130_1);
  andn(&S_andn_586_1);
  andn(&S_andn_587_1);
  fnapb(&S_fnapb_925_1);
  zpfs(&S_zpfs_917_1);
  zpfs(&S_zpfs_916_1);
  rs(&S_rs_999_1);
  rs(&S_rs_271_1);
  newstage(&S_newstage_1807_1);
  rs(&S_rs_1455_1);
  noto(&S_noto_1018_1);
  provsbr(&S_provsbr_1403_1);
  rs(&S_rs_1402_1);
  provsbr(&S_provsbr_261_1);
  equz_p(&S_equz_p_299_1);
  bolz(&S_bolz_300_1);
  provsbr(&S_provsbr_315_1);
  bolz(&S_bolz_320_1);
  noto(&S_noto_67_1);
  noto(&S_noto_56_1);
  zpfs(&S_zpfs_926_1);
  and2(&S_and2_59_1);
  and2(&S_and2_63_1);
  or2(&S_or2_60_1);
  and2(&S_and2_559_1);
  and2(&S_and2_558_1);
  and2(&S_and2_275_1);
  and4(&S_and4_304_1);
  and2(&S_and2_287_1);
  or2(&S_or2_277_1);
  and2(&S_and2_283_1);
  or2(&S_or2_326_1);
  and2(&S_and2_317_1);
  and2(&S_and2_237_1);
  and2(&S_and2_238_1);
  and2(&S_and2_873_1);
  and2(&S_and2_872_1);
  and2(&S_and2_972_1);
  and2(&S_and2_971_1);
  and2(&S_and2_1371_1);
  and2(&S_and2_1372_1);
  and2(&S_and2_1277_1);
  and2(&S_and2_1278_1);
  and3(&S_and3_1005_1);
  and3(&S_and3_1011_1);
  and2(&S_and2_1027_1);
  and2(&S_and2_1016_1);
  and3(&S_and3_1062_1);
  or2(&S_or2_1408_1);
  or2(&S_or2_1410_1);
  or2(&S_or2_1412_1);
  or2(&S_or2_1418_1);
  or2(&S_or2_1422_1);
  orni(&S_orni_1414_1);
  or2(&S_or2_1392_1);
  or3(&S_or3_1423_1);
  or3(&S_or3_1462_1);
  or3(&S_or3_1477_1);
  or2(&S_or2_1913_1);
  or3(&S_or3_1873_1);
  or3(&S_or3_1835_1);
  noto(&S_noto_2136_1);
  and2(&S_and2_909_1);
  maz(&S_maz_286_1);
  maz(&S_maz_295_1);
  orni(&S_orni_1172_1);
  cntch(&S_cntch_1413_1);
  orni(&S_orni_276_1);
  rs(&S_rs_325_1);
  rs(&S_rs_1022_1);
  decatron(&S_decatron_284_1);
  orni(&S_orni_319_1);
  noto(&S_noto_296_1);
  rs(&S_rs_1056_1);
  rs(&S_rs_1030_1);
  swtakt(&S_swtakt_1839_1);
  swtakt(&S_swtakt_1874_1);
  swtakt(&S_swtakt_1467_1);
  swtakt(&S_swtakt_1471_1);
  swtakt(&S_swtakt_1427_1);
  noto(&S_noto_1031_1);
  noto(&S_noto_1914_1);
  or3(&S_or3_151_1);
  or2(&S_or2_281_1);
  or2(&S_or2_290_1);
  or2(&S_or2_303_1);
  or2(&S_or2_302_1);
  and2(&S_and2_305_1);
  and2(&S_and2_301_1);
  and2(&S_and2_307_1);
  and2(&S_and2_306_1);
  and3(&S_and3_288_1);
  or3(&S_or3_480_1);
  or2(&S_or2_1053_1);
  and2(&S_and2_1415_1);
  and2(&S_and2_1393_1);
  or2(&S_or2_1577_1);
  or2(&S_or2_2028_1);
  or2(&S_or2_2020_1);
  or2(&S_or2_1930_1);
  zpfs(&S_zpfs_298_1);
  and2(&S_and2_2032_1);
  cnshd(&S_cnshd_1584_1);
  noto(&S_noto_863_1);
  ornc(&S_ornc_160_1);
  charint(&S_charint_152_1);
  noto(&S_noto_222_1);
  ornc(&S_ornc_488_1);
  charint(&S_charint_482_1);
  noto(&S_noto_546_1);
  noto(&S_noto_959_1);
  noto(&S_noto_1359_1);
  rs(&S_rs_2021_1);
  noto(&S_noto_2022_1);
  rs(&S_rs_2029_1);
  noto(&S_noto_2030_1);
  equz_p(&S_equz_p_289_1);
  noto(&S_noto_1399_1);
  cntch(&S_cntch_279_1);
  rs(&S_rs_280_1);
  cntch(&S_cntch_323_1);
  rs(&S_rs_1931_1);
  rs(&S_rs_1932_1);
  rs(&S_rs_1041_1);
  and2(&S_and2_294_1);
  or2(&S_or2_626_1);
  and2(&S_and2_1364_1);
  or5(&S_or5_1416_1);
  or5(&S_or5_1394_1);
  and2(&S_and2_1397_1);
  or2(&S_or2_1398_1);
  or2(&S_or2_1603_1);
  and2(&S_and2_1554_1);
  and2(&S_and2_1555_1);
  and2(&S_and2_1556_1);
  and2(&S_and2_1557_1);
  and2(&S_and2_1564_1);
  and2(&S_and2_1566_1);
  and2(&S_and2_1568_1);
  and4(&S_and4_1917_1);
  and3(&S_and3_1918_1);
  and3(&S_and3_1919_1);
  and2(&S_and2_1880_1);
  and2(&S_and2_1834_1);
  or3(&S_or3_1848_1);
  and2(&S_and2_964_1);
  and2(&S_and2_1029_1);
  or4(&S_or4_2051_1);
  or4(&S_or4_2053_1);
  fnapb(&S_fnapb_1604_1);
  samhd(&S_samhd_1587_1);
  zpfs(&S_zpfs_1601_1);
  zpfs(&S_zpfs_1597_1);
  noto(&S_noto_1268_1);
  fsumz(&S_fsumz_153_1);
  fsumz(&S_fsumz_483_1);
  rs(&S_rs_2042_1);
  rs(&S_rs_2046_1);
  orni(&S_orni_1160_1);
  rs(&S_rs_1885_1);
  rs(&S_rs_1840_1);
  rs(&S_rs_1849_1);
  rs(&S_rs_1024_1);
  rs(&S_rs_1025_1);
  ma(&S_ma_158_1);
  ma(&S_ma_489_1);
  zpfs(&S_zpfs_1605_1);
  or2(&S_or2_1114_1);
  and2(&S_and2_311_1);
  and2(&S_and2_625_1);
  or3(&S_or3_1023_1);
  or3(&S_or3_1594_1);
  or3(&S_or3_1884_1);
  samhd(&S_samhd_1165_1);
  samhd(&S_samhd_1175_1);
  newstage(&S_newstage_1170_1);
  cnshd(&S_cnshd_1116_1);
  noto(&S_noto_1267_1);
  noto(&S_noto_862_1);
  fnapb(&S_fnapb_192_1);
  noto(&S_noto_221_1);
  fnapb(&S_fnapb_518_1);
  zpfs(&S_zpfs_514_1);
  zpfs(&S_zpfs_511_1);
  noto(&S_noto_545_1);
  noto(&S_noto_958_1);
  noto(&S_noto_1358_1);
  noto(&S_noto_312_1);
  or2(&S_or2_1164_1);
  or2(&S_or2_1178_1);
  or2(&S_or2_1137_1);
  and2(&S_and2_1092_1);
  and2(&S_and2_1089_1);
  and2(&S_and2_1090_1);
  and2(&S_and2_1091_1);
  and2(&S_and2_1098_1);
  and2(&S_and2_1100_1);
  and2(&S_and2_1102_1);
  and2(&S_and2_624_1);
  zpfs(&S_zpfs_519_1);
  or2(&S_or2_540_1);
  zpfs(&S_zpfs_193_1);
  zpfs(&S_zpfs_187_1);
  zpfs(&S_zpfs_182_1);
  or2(&S_or2_216_1);
  or2(&S_or2_857_1);
  and2(&S_and2_856_1);
  or2(&S_or2_953_1);
  or2(&S_or2_1353_1);
  or2(&S_or2_1262_1);
  and2(&S_and2_1261_1);
  and2(&S_and2_1020_1);
  or2(&S_or2_1032_1);
  and2(&S_and2_1168_1);
  and2(&S_and2_1176_1);
  fnapb(&S_fnapb_1138_1);
  samhd(&S_samhd_1120_1);
  zpfs(&S_zpfs_1133_1);
  zpfs(&S_zpfs_1130_1);
  orn(&S_orn_1269_1);
  orn(&S_orn_864_1);
  rs(&S_rs_1666_1);
  rs(&S_rs_1668_1);
  rs(&S_rs_1019_1);
  zpfs(&S_zpfs_1139_1);
  and2(&S_and2_31_1);
  and2(&S_and2_539_1);
  orn(&S_orn_547_1);
  and2(&S_and2_215_1);
  or3(&S_or3_879_1);
  and2(&S_and2_952_1);
  and2(&S_and2_1352_1);
  or3(&S_or3_1284_1);
  and2(&S_and2_1033_1);
  or2(&S_or2_1026_1);
  or3(&S_or3_1127_1);
  or2(&S_or2_1678_1);
  or2(&S_or2_1684_1);
  and2(&S_and2_1670_1);
  and2(&S_and2_1674_1);
  orn(&S_orn_223_1);
  orn(&S_orn_960_1);
  orn(&S_orn_1360_1);
  rs(&S_rs_1679_1);
  rs(&S_rs_1677_1);
  rs(&S_rs_1685_1);
  rs(&S_rs_1683_1);
  or3(&S_or3_570_1);
  or5(&S_or5_502_1);
  or3(&S_or3_249_1);
  or2(&S_or2_812_1);
  or5(&S_or5_984_1);
  or5(&S_or5_1384_1);
  or2(&S_or2_1202_1);
  or3(&S_or3_1387_1);
  or3(&S_or3_987_1);
  cnshd(&S_cnshd_491_1);
  or5(&S_or5_175_1);
  or5(&S_or5_908_1);
  cnshd(&S_cnshd_163_1);
  newstage(&S_newstage_200_1);
  cnshd(&S_cnshd_892_1);
  and2(&S_and2_189_1);
  and2(&S_and2_186_1);
  rs(&S_rs_1722_1);
  rs(&S_rs_1725_1);
  and2(&S_and2_1085_1);
  and2(&S_and2_631_1);
  or2(&S_or2_619_1);
  and2(&S_and2_1045_1);
  or2(&S_or2_1721_1);
  or2(&S_or2_1724_1);
  rs(&S_rs_620_1);
  rs(&S_rs_1720_1);
  rs(&S_rs_1042_1);
  noto(&S_noto_1043_1);
  rs(&S_rs_1077_1);
  and2(&S_and2_638_1);
  and3(&S_and3_607_1);
  and3(&S_and3_597_1);
  or3(&S_or3_807_1);
  or3(&S_or3_1197_1);
  and4(&S_and4_1006_1);
  and4(&S_and4_1012_1);
  or2(&S_or2_1076_1);
  or3(&S_or3_1285_1);
  ornc(&S_ornc_1295_1);
  charint(&S_charint_1286_1);
  fsumz(&S_fsumz_1287_1);
  ma(&S_ma_1296_1);
  fnapb(&S_fnapb_1325_1);
  zpfs(&S_zpfs_1319_1);
  zpfs(&S_zpfs_1316_1);
  zpfs(&S_zpfs_1326_1);
  and2(&S_and2_1311_1);
  or5(&S_or5_1310_1);
  or2(&S_or2_2171_1);
  cnshd(&S_cnshd_1297_1);
  noto(&S_noto_2170_1);
  newstage(&S_newstage_904_1);
  and2(&S_and2_911_1);
  and2(&S_and2_915_1);
  andn(&S_andn_2144_1);
  noto(&S_noto_2166_1);
  and2(&S_and2_2167_1);
  or2(&S_or2_2165_1);
  and3(&S_and3_2119_1);
  and2(&S_and2_1086_1);
  and2(&S_and2_630_1);
  and2(&S_and2_1061_1);
  or2(&S_or2_1699_1);
  rs(&S_rs_1700_1);
  or2(&S_or2_1702_1);
  rs(&S_rs_1703_1);
  rs(&S_rs_2164_1);
  or4(&S_or4_1962_1);
  rs(&S_rs_1698_1);
  rs(&S_rs_1054_1);
  noto(&S_noto_1057_1);
  rs(&S_rs_1080_1);
  or3(&S_or3_880_1);
  and3(&S_and3_1046_1);
  and2(&S_and2_997_1);
  and4(&S_and4_1004_1);
  and4(&S_and4_1010_1);
  ovbs(&S_ovbs_1969_1);
  noto(&S_noto_1970_1);
  and2(&S_and2_1976_1);
  and2(&S_and2_1988_1);
  or3(&S_or3_1963_1);
  and2(&S_and2_1964_1);
  or3(&S_or3_1978_1);
  and2(&S_and2_1979_1);
  rs(&S_rs_1701_1);
  or2(&S_or2_2155_1);
  or2(&S_or2_1079_1);
  rs(&S_rs_991_1);
  or3(&S_or3_436_1);
  and3(&S_and3_443_1);
  or5(&S_or5_800_1);
  or5(&S_or5_1188_1);
  and2(&S_and2_1036_1);
  and2(&S_and2_475_1);
  and2(&S_and2_446_1);
  or2(&S_or2_1983_1);
  or2(&S_or2_1971_1);
  ovbs(&S_ovbs_1965_1);
  ovbs(&S_ovbs_1980_1);
  rs(&S_rs_1998_1);
  rs(&S_rs_2006_1);
  noto(&S_noto_1996_1);
  noto(&S_noto_2016_1);
  zpfs(&S_zpfs_1999_1);
  zpfs(&S_zpfs_2007_1);
  noto(&S_noto_2152_1);
  ornc(&S_ornc_1198_1);
  charint(&S_charint_1189_1);
  ornc(&S_ornc_808_1);
  charint(&S_charint_801_1);
  samhd(&S_samhd_456_1);
  samhd(&S_samhd_462_1);
  newstage(&S_newstage_458_1);
  or2(&S_or2_2000_1);
  or4(&S_or4_452_1);
  or4(&S_or4_470_1);
  noto(&S_noto_1966_1);
  noto(&S_noto_1981_1);
  rs(&S_rs_1984_1);
  noto(&S_noto_1985_1);
  rs(&S_rs_1972_1);
  or2(&S_or2_2008_1);
  noto(&S_noto_2001_1);
  and2(&S_and2_2002_1);
  noto(&S_noto_2009_1);
  and2(&S_and2_467_1);
  and2(&S_and2_466_1);
  fsumz(&S_fsumz_1190_1);
  fsumz(&S_fsumz_802_1);
  ma(&S_ma_809_1);
  ma(&S_ma_1195_1);
  and2(&S_and2_1087_1);
  and2(&S_and2_646_1);
  and2(&S_and2_1068_1);
  or2(&S_or2_1727_1);
  noto(&S_noto_1973_1);
  and2(&S_and2_2010_1);
  rs(&S_rs_1728_1);
  fnapb(&S_fnapb_1232_1);
  zpfs(&S_zpfs_1227_1);
  zpfs(&S_zpfs_1219_1);
  fnapb(&S_fnapb_831_1);
  rs(&S_rs_1063_1);
  rs(&S_rs_1083_1);
  zpfs(&S_zpfs_1233_1);
  zpfs(&S_zpfs_832_1);
  zpfs(&S_zpfs_825_1);
  zpfs(&S_zpfs_826_1);
  or5(&S_or5_1211_1);
  orni(&S_orni_127_1);
  orn(&S_orn_414_1);
  orn(&S_orn_432_1);
  cnshd(&S_cnshd_1199_1);
  or2(&S_or2_416_1);
  or2(&S_or2_433_1);
  and2(&S_and2_677_1);
  or2(&S_or2_1150_1);
  or2(&S_or2_1151_1);
  and2(&S_and2_1101_1);
  or5(&S_or5_820_1);
  and2(&S_and2_1567_1);
  or4(&S_or4_1563_1);
  orn(&S_orn_764_1);
  orn(&S_orn_1088_1);
  cnshd(&S_cnshd_811_1);
  or2(&S_or2_752_1);
  or2(&S_or2_753_1);
  or4(&S_or4_733_1);
  or5(&S_or5_1123_1);
  or2(&S_or2_344_1);
  or2(&S_or2_348_1);
  or5(&S_or5_1553_1);
  rs(&S_rs_732_1);
  samhd(&S_samhd_347_1);
  newstage(&S_newstage_1239_1);
  and2(&S_and2_722_1);
  or2(&S_or2_725_1);
  or4(&S_or4_346_1);
  or5(&S_or5_1591_1);
  andn(&S_andn_1_1);
  and2(&S_and2_1222_1);
  and2(&S_and2_1226_1);
  rs(&S_rs_726_1);
  rs(&S_rs_1633_1);
  rs(&S_rs_1636_1);
  rs(&S_rs_1681_1);
  rs(&S_rs_1687_1);
  rs(&S_rs_1638_1);
  rs(&S_rs_1640_1);
  or2(&S_or2_1632_1);
  or2(&S_or2_1635_1);
  or2(&S_or2_1650_1);
  or2(&S_or2_1657_1);
  or2(&S_or2_1680_1);
  or2(&S_or2_1686_1);
  and2(&S_and2_1672_1);
  and2(&S_and2_1676_1);
  and2(&S_and2_1642_1);
  and2(&S_and2_1644_1);
  and2(&S_and2_1646_1);
  and2(&S_and2_1648_1);
  rs(&S_rs_1631_1);
  rs(&S_rs_1634_1);
  rs(&S_rs_1651_1);
  rs(&S_rs_1649_1);
  rs(&S_rs_1655_1);
  rs(&S_rs_1658_1);
  rs(&S_rs_1656_1);
  rs(&S_rs_1662_1);
  rs(&S_rs_1682_1);
  rs(&S_rs_1688_1);
  or3(&S_or3_1991_1);
  or3(&S_or3_2011_1);
  zpfs(&S_zpfs_1663_1);
  or2(&S_or2_1652_1);
  zpfs(&S_zpfs_1664_1);
  and2(&S_and2_1997_1);
  and2(&S_and2_2017_1);
  noto(&S_noto_1990_1);
  noto(&S_noto_2018_1);
  orn(&S_orn_590_1);
  orn(&S_orn_589_1);
  and4(&S_and4_1992_1);
  and4(&S_and4_2012_1);
  ovbs(&S_ovbs_1993_1);
  ovbs(&S_ovbs_2013_1);
  setData(idR0AD05LZ2,&var1054);
  setData(idR0AD05LZ1,&var1054);
  setData(idR0AD04LZ2,&var241);
  setData(idR0AD04LZ1,&var241);
  setData(idR0AD03LZ2,&var1215);
  setData(idR0AD03LZ1,&var1215);
  moveData(idB2IS12LZ2,idB2IS12LDU);
  moveData(idA2IS12LZ2,idA2IS12LDU);
  moveData(idB2IS12LZ1,idB2IS12LDU);
  moveData(idA2IS12LZ1,idA2IS12LDU);
  setData(idR0CN95LDU,&var69);
  setData(idR0CN94LDU,&var68);
  setData(idR0CN93LDU,&var67);
  setData(idR0AB19LDU,&var25);
  setData(idR0VN12RDU,&var888);
  setData(idR0VN11RDU,&var886);
  setData(idR0CN92LDU,&var29);
  setData(idR0AB20LDU,&var43);
  setData(idA3AB15LDU,&var44);
  setData(idA3MC03RDU,&var65);
  setData(idR0CN91LDU,&var64);
  setData(idA3MC02RDU,&var63);
  setData(idA3MC01RDU,&var62);
  setData(idR0AB18LDU,&var49);
  setData(idR0AB17LDU,&var56);
  setData(idR0AB16LDU,&var57);
  setData(idB1AB19LDU,&var76);
  setData(idA3ZAV,&var1259);
  setData(idA1ZAV,&var1322);
  setData(idB3IS12LDU,&var86);
  setData(idA3IS12LDU,&var87);
  setData(idR0AB15LDU,&var92);
  setData(idR0AB14LDU,&var90);
  setData(idA4DW,&var1079);
  setData(idA4UP,&var1080);
  setData(idR4ABL,&var1561);
  setData(idA9ZAV,&var1190);
  setData(idA8ZAV,&var1398);
  setData(idA2ZAV,&var1403);
  setData(idB8ZAV,&var1408);
  setData(idA5ZAV,&var1476);
  setData(idR2ZAV,&var1352);
  setData(idA6ZAV,&var1478);
  setData(idA4ZAV,&var1477);
  setData(idR0AB13LDU,&var174);
  setData(idR0AB12LDU,&var178);
  setData(idR0AB11LDU,&var182);
  setData(idR0AB10LDU,&var186);
  setData(idR0AB09LDU,&var190);
  setData(idR0AB08LDU,&var194);
  setData(idB6AB05LDU,&var242);
  setData(idR0VS11LDU,&var1601);
  setData(idA8VS01IDU,&var1402);
  setData(idB8VS01IDU,&var1412);
  setData(idR2AD10LDU,&var1357);
  setData(idR2AD20LDU,&var1358);
  setData(idR3IS12LDU,&var249);
  setData(idR3IS22LDU,&var248);
  setData(idR3VS11LDU,&var1020);
  setData(idR3VS22LDU,&var1021);
  setData(idR3VS32IDU,&var1022);
  setData(idB6VS01IDU,&var1549);
  setData(idR0AD16LDU,&var269);
  setData(idR0AB07LDU,&var503);
  setData(idR0VX02LDU,&var720);
  setData(idR0AD21LDU,&var718);
  setData(idB2AB15LDU,&var211);
  setData(idA2AB15LDU,&var212);
  setData(idR0AB05LDU,&var1051);
  setData(idR0AB03LDU,&var1062);
  setData(idR3VS10LDU,&var1027);
  setData(idR3AB14LDU,&var1018);
  setData(idR3AB12LDU,&var1017);
  setData(idR3AB11LDU,&var1019);
  setData(idR3AZ13LDU,&var1016);
  setData(idR3VS20LDU,&var1028);
  setData(idR3VS30IDU,&var1029);
  setData(idR3AB04LDU,&var1025);
  setData(idR3AB02LDU,&var1024);
  setData(idR3AB01LDU,&var1026);
  setData(idR3AZ03LDU,&var1023);
  setData(idA1AB19LDU,&var77);
  setData(idR0VZ71LDU,&var808);
  setData(idR0VL01RDU,&var1099);
  setData(idB7AZ03LDU,&var243);
  setData(idA7AZ03LDU,&var357);
  setData(idB2VS01IDU,&var1390);
  setData(idB2VS21LDU,&var1392);
  setData(idB2VS11LDU,&var1391);
  setData(idR0VP73LDU,&var368);
  setData(idR0VS18LDU,&var460);
  setData(idB3VX01LDU,&var314);
  setData(idA3VX01LDU,&var315);
  setData(idB2VS32LDU,&var224);
  setData(idA2VS32LDU,&var225);
  setData(idR5VS22LDU,&var1208);
  setData(idR0VS17LDU,&var450);
  setData(idR0VX09LDU,&var17);
  moveData(idR0VX08IDU,idR0MW12IP1);
  setData(idR0VW23LDU,&var817);
  setData(idR0VW13LDU,&var816);
  setData(idB7AP31LDU,&var1082);
  setData(idA7AP31LDU,&var1083);
  setData(idB3AD31LDU,&var1153);
  setData(idB3AD34LDU,&var1154);
  setData(idA3AD31LDU,&var1159);
  setData(idA3AD34LDU,&var1156);
  setData(idA3AD33LDU,&var1158);
  setData(idB2AD33LDU,&var201);
  setData(idA2AD33LDU,&var206);
  setData(idR0AB01LDU,&var1182);
  setData(idB9AB02LDU,&var1192);
  setData(idB9AB01LDU,&var1193);
  setData(idB9AZ03LDU,&var1191);
  setData(idA9AB02LDU,&var1198);
  setData(idA9AB01LDU,&var1199);
  setData(idA9AZ03LDU,&var1197);
  setData(idA9AD10LDU,&var1200);
  setData(idB9AD10LDU,&var1194);
  setData(idR1VS01IDU,&var1368);
  setData(idR2VS01IDU,&var1359);
  setData(idR5VS01IDU,&var1209);
  setData(idR5AB04LDU,&var1205);
  setData(idR5AB02LDU,&var1204);
  setData(idR5AB01LDU,&var1206);
  setData(idR5AZ03LDU,&var1203);
  setData(idR4VS01IDU,&var1540);
  setData(idA6VS01IDU,&var1558);
  setData(idB5VS01IDU,&var1522);
  setData(idA5VS01IDU,&var1531);
  setData(idB4VS22LDU,&var1503);
  setData(idB4VS12LDU,&var1502);
  setData(idB4VS01IDU,&var1504);
  setData(idA4VS22LDU,&var1512);
  setData(idA4VS12LDU,&var1511);
  setData(idA4VS01IDU,&var1513);
  setData(idA2VS01IDU,&var1431);
  setData(idB3VS01IDU,&var1249);
  setData(idA3VS01IDU,&var1281);
  setData(idB1VS01IDU,&var1310);
  setData(idA1VS01IDU,&var1343);
  setData(idR0VS21IDU,&var1072);
  setData(idR0VX03LDU,&var665);
  setData(idR0VL21IDU,&var968);
  setData(idR0VL05RDU,&var300);
  setData(idR0AD15LDU,&var1054);
  setData(idR0VL03RDU,&var307);
  setData(idR0AD13LDU,&var1215);
  setData(idR0AB02LDU,&var1045);
  setData(idR0AB06LDU,&var1048);
  setData(idR0AB04LDU,&var1056);
  setData(idR0VL04RDU,&var303);
  setData(idR0AD14LDU,&var241);
  setData(idR8AD21LDU,&var268);
  setData(idR0VL02RDU,&var297);
  setData(idB3AD33LDU,&var1152);
  setData(idR0VL06RDU,&var311);
  setData(idR0VL11IDU,&var1213);
  setData(idR0VL01IDU,&var1214);
  setData(idR0VX01LDU,&var722);
  setData(idB1AD32LDU,&var1160);
  setData(idA1AD32LDU,&var1162);
  setData(idB2AD32LDU,&var231);
  setData(idA2AD32LDU,&var233);
  setData(idB1AD31LDU,&var1163);
  setData(idA1AD31LDU,&var1164);
  setData(idB2AD31LDU,&var234);
  setData(idA2AD31LDU,&var235);
  setData(idB3AB20LDU,&var549);
  setData(idB3AB19LDU,&var547);
  setData(idB3AB18LDU,&var545);
  setData(idB3AB17LDU,&var541);
  setData(idB3AB16LDU,&var542);
  setData(idB3AB14LDU,&var827);
  setData(idB3AB13LDU,&var825);
  setData(idB3AB12LDU,&var546);
  setData(idB3AB11LDU,&var551);
  setData(idB3AB10LDU,&var552);
  setData(idB3AB09LDU,&var553);
  setData(idB3AB06LDU,&var557);
  setData(idB3AB05LDU,&var559);
  setData(idB3AB08LDU,&var548);
  setData(idB3AB07LDU,&var558);
  setData(idB3CV02RDU,&var1248);
  setData(idB3AD01LDU,&var1241);
  setData(idB3AD05LDU,&var1247);
  setData(idB3AD04LDU,&var1246);
  setData(idB3AD03LDU,&var1245);
  setData(idB3AD02LDU,&var1244);
  setData(idB3AD21LDU,&var1242);
  setData(idB3AD11LDU,&var1243);
  setData(idB3AZ03LDU,&var901);
  setData(idB3VS22LDU,&var1252);
  setData(idB3AB01LDU,&var1250);
  setData(idB3AB02LDU,&var1251);
  setData(idB3AB04LDU,&var1256);
  setData(idB3CV01RDU,&var1254);
  setData(idB3VS12LDU,&var1253);
  setData(idA3AB20LDU,&var278);
  setData(idA3AB19LDU,&var560);
  setData(idA3AB18LDU,&var566);
  setData(idA3AB17LDU,&var564);
  setData(idA3AB16LDU,&var563);
  setData(idA3AB14LDU,&var829);
  setData(idA3AB13LDU,&var830);
  setData(idA3AB12LDU,&var567);
  setData(idA3AB11LDU,&var571);
  setData(idA3AB10LDU,&var575);
  setData(idA3AB09LDU,&var569);
  setData(idA3AB06LDU,&var574);
  setData(idA3AB05LDU,&var577);
  setData(idA3AB08LDU,&var568);
  setData(idA3AB07LDU,&var576);
  setData(idA3CV02RDU,&var1280);
  setData(idA3AD01LDU,&var1273);
  setData(idA3AD05LDU,&var1279);
  setData(idA3AD04LDU,&var1278);
  setData(idA3AD03LDU,&var1277);
  setData(idA3AD02LDU,&var1276);
  setData(idA3AD21LDU,&var1274);
  setData(idA3AD11LDU,&var1275);
  setData(idA3AZ03LDU,&var902);
  setData(idA3VS22LDU,&var1284);
  setData(idA3AB01LDU,&var1282);
  setData(idA3AB02LDU,&var1283);
  setData(idA3AB04LDU,&var1288);
  setData(idA3CV01RDU,&var1286);
  setData(idA3VS12LDU,&var1285);
  setData(idB1AB18LDU,&var639);
  setData(idB1AB17LDU,&var811);
  setData(idB1AB16LDU,&var810);
  setData(idB1AB14LDU,&var832);
  setData(idB1AB13LDU,&var833);
  setData(idB1AB12LDU,&var637);
  setData(idB1AB11LDU,&var641);
  setData(idB1AB10LDU,&var642);
  setData(idB1AB09LDU,&var645);
  setData(idB1AB06LDU,&var643);
  setData(idB1AB05LDU,&var650);
  setData(idB1AB08LDU,&var638);
  setData(idB1AB07LDU,&var649);
  setData(idB1CV02RDU,&var1309);
  setData(idB1AD01LDU,&var1302);
  setData(idB1AD05LDU,&var1308);
  setData(idB1AD04LDU,&var1307);
  setData(idB1AD03LDU,&var1306);
  setData(idB1AD02LDU,&var1305);
  setData(idB1AD21LDU,&var1304);
  setData(idB1AD11LDU,&var1303);
  setData(idB1AZ03LDU,&var652);
  setData(idB1VS22LDU,&var1314);
  setData(idB1AB01LDU,&var1311);
  setData(idB1AB02LDU,&var1312);
  setData(idB1AB04LDU,&var1317);
  setData(idB1CV01RDU,&var1315);
  setData(idB1VS12LDU,&var1313);
  setData(idA1AB18LDU,&var615);
  setData(idA1AB17LDU,&var614);
  setData(idA1AB16LDU,&var616);
  setData(idA1AB14LDU,&var835);
  setData(idA1AB13LDU,&var836);
  setData(idA1AB12LDU,&var612);
  setData(idA1AB11LDU,&var621);
  setData(idA1AB10LDU,&var619);
  setData(idA1AB09LDU,&var618);
  setData(idA1AB06LDU,&var623);
  setData(idA1AB05LDU,&var624);
  setData(idA1AB08LDU,&var617);
  setData(idA1AB07LDU,&var625);
  setData(idA1CV02RDU,&var1342);
  setData(idA1AD01LDU,&var1335);
  setData(idA1AD05LDU,&var1341);
  setData(idA1AD04LDU,&var1340);
  setData(idA1AD03LDU,&var1339);
  setData(idA1AD02LDU,&var1338);
  setData(idA1AD21LDU,&var1337);
  setData(idA1AD11LDU,&var1336);
  setData(idA1AZ03LDU,&var632);
  setData(idA1VS22LDU,&var1345);
  setData(idA1AB01LDU,&var630);
  setData(idA1AB02LDU,&var631);
  setData(idA1AB04LDU,&var1348);
  setData(idA1CV01RDU,&var1346);
  setData(idA1VS12LDU,&var1344);
  setData(idR1AD20LDU,&var1367);
  setData(idR1AD10LDU,&var1366);
  setData(idR2AB04LDU,&var1355);
  setData(idR1AB04LDU,&var1364);
  setData(idR2AB02LDU,&var1354);
  setData(idR2AB01LDU,&var1356);
  setData(idR2AZ03LDU,&var1353);
  setData(idR1AB02LDU,&var1363);
  setData(idR1AB01LDU,&var1365);
  setData(idR1AZ03LDU,&var1362);
  setData(idB2AB17LDU,&var586);
  setData(idB2AB16LDU,&var585);
  setData(idB2AB14LDU,&var837);
  setData(idB2AB13LDU,&var838);
  setData(idB2AB12LDU,&var587);
  setData(idB2AB11LDU,&var591);
  setData(idB2AB10LDU,&var590);
  setData(idB2AB09LDU,&var589);
  setData(idB2AB06LDU,&var594);
  setData(idB2AB05LDU,&var593);
  setData(idB2AB08LDU,&var588);
  setData(idB2AB07LDU,&var595);
  setData(idB2CV02RDU,&var1389);
  setData(idB2AD01LDU,&var1382);
  setData(idB2AD05LDU,&var1388);
  setData(idB2AD04LDU,&var1387);
  setData(idB2AD03LDU,&var1386);
  setData(idB2AD02LDU,&var1385);
  setData(idB2AD21LDU,&var1384);
  setData(idB2AD11LDU,&var1383);
  setData(idB2AZ03LDU,&var603);
  setData(idB2AB01LDU,&var602);
  setData(idB2AB02LDU,&var601);
  setData(idB2AB04LDU,&var1395);
  setData(idB2CV01RDU,&var1393);
  setData(idA2CV02RDU,&var1430);
  setData(idA2AD01LDU,&var1423);
  setData(idA2AB17LDU,&var518);
  setData(idA2AB16LDU,&var519);
  setData(idA2AB14LDU,&var522);
  setData(idA2AB13LDU,&var523);
  setData(idA2AB12LDU,&var520);
  setData(idA2AB11LDU,&var528);
  setData(idA2AB10LDU,&var526);
  setData(idA2AB09LDU,&var524);
  setData(idA2AB06LDU,&var529);
  setData(idA2AB05LDU,&var525);
  setData(idA2AB08LDU,&var521);
  setData(idA2AB07LDU,&var527);
  setData(idA2AD05LDU,&var1429);
  setData(idA2AD04LDU,&var1428);
  setData(idA2AD03LDU,&var1427);
  setData(idA2AD02LDU,&var1426);
  setData(idA2AD21LDU,&var1425);
  setData(idA2AD11LDU,&var1424);
  setData(idA2AZ03LDU,&var903);
  setData(idA2VS21LDU,&var1435);
  setData(idA2AB01LDU,&var1432);
  setData(idA2AB02LDU,&var1433);
  setData(idA2AB04LDU,&var1438);
  setData(idA2CV01RDU,&var1436);
  setData(idA2VS11LDU,&var1434);
  setData(idA8AB01LDU,&var1446);
  setData(idA8AB02LDU,&var397);
  setData(idA8AB14LDU,&var398);
  setData(idA8AB13LDU,&var399);
  setData(idA8AB12LDU,&var401);
  setData(idA8AB11LDU,&var402);
  setData(idA8AB10LDU,&var403);
  setData(idA8AB09LDU,&var404);
  setData(idA8AB08LDU,&var405);
  setData(idA8AB04LDU,&var1445);
  setData(idA8AD20LDU,&var1401);
  setData(idA8AD10LDU,&var1400);
  setData(idA8AZ03LDU,&var893);
  setData(idA8VS22LDU,&var1448);
  setData(idA8AB05LDU,&var1443);
  setData(idA8AB07LDU,&var1444);
  setData(idA8AB06LDU,&var1451);
  setData(idA8CV01RDU,&var1449);
  setData(idA8VS12LDU,&var1447);
  setData(idB8AB02LDU,&var733);
  setData(idB8AB14LDU,&var734);
  setData(idB8AB13LDU,&var735);
  setData(idB8AB12LDU,&var736);
  setData(idB8AB11LDU,&var740);
  setData(idB8AB10LDU,&var737);
  setData(idB8AB09LDU,&var738);
  setData(idB8AB08LDU,&var739);
  setData(idB8AB04LDU,&var1462);
  setData(idB8AB01LDU,&var1463);
  setData(idB8AD20LDU,&var1411);
  setData(idB8AD10LDU,&var1410);
  setData(idB8AZ03LDU,&var894);
  setData(idB8VS22LDU,&var1465);
  setData(idB8AB05LDU,&var1454);
  setData(idB8AB07LDU,&var1455);
  setData(idB8AB06LDU,&var1468);
  setData(idB8CV01RDU,&var1466);
  setData(idB8VS12LDU,&var1464);
  setData(idA6AB05LDU,&var861);
  setData(idB6AB09LDU,&var860);
  setData(idB6AB08LDU,&var859);
  setData(idB6AB07LDU,&var858);
  setData(idB6AB06LDU,&var857);
  setData(idA6AB09LDU,&var862);
  setData(idA6AB08LDU,&var848);
  setData(idA6AB07LDU,&var847);
  setData(idA6AB06LDU,&var863);
  setData(idB5AB04LDU,&var1518);
  setData(idA5AB04LDU,&var1527);
  setData(idB4AB02LDU,&var1499);
  setData(idB4AB01LDU,&var1500);
  setData(idB4AZ03LDU,&var1498);
  setData(idA4AB02LDU,&var1508);
  setData(idA4AB01LDU,&var1509);
  setData(idA4AZ03LDU,&var1507);
  setData(idA4AD10LDU,&var1510);
  setData(idB4AD10LDU,&var1501);
  setData(idB5AB02LDU,&var1517);
  setData(idB5AB01LDU,&var1519);
  setData(idB5AZ03LDU,&var1516);
  setData(idA5AB02LDU,&var1526);
  setData(idA5AB01LDU,&var1528);
  setData(idA5AZ03LDU,&var1525);
  setData(idA5AD20LDU,&var1530);
  setData(idA5AD10LDU,&var1529);
  setData(idB5AD20LDU,&var1521);
  setData(idB5AD10LDU,&var1520);
  setData(idR4AD20LDU,&var1539);
  setData(idR4AD10LDU,&var1538);
  setData(idR4AB18LDU,&var787);
  setData(idR4AB17LDU,&var786);
  setData(idR4AB16LDU,&var789);
  setData(idR4AB15LDU,&var788);
  setData(idR4AB14LDU,&var790);
  setData(idR4AB13LDU,&var758);
  setData(idR4AB12LDU,&var763);
  setData(idR4AB11LDU,&var795);
  setData(idR4AB10LDU,&var760);
  setData(idR4AB09LDU,&var793);
  setData(idR4AB08LDU,&var792);
  setData(idR4AB07LDU,&var796);
  setData(idR4AB06LDU,&var1536);
  setData(idR4AB05LDU,&var1535);
  setData(idR4AB04LDU,&var1537);
  setData(idR4AB03LDU,&var797);
  setData(idR4AZ03LDU,&var1534);
  setData(idR4AB02LDU,&var800);
  setData(idR4AB01LDU,&var801);
  setData(idB6AB04LDU,&var1545);
  setData(idA6AB04LDU,&var1554);
  setData(idB6AB02LDU,&var1544);
  setData(idB6AB01LDU,&var1546);
  setData(idB6AZ03LDU,&var1543);
  setData(idA6AB02LDU,&var1553);
  setData(idA6AB01LDU,&var1555);
  setData(idA6AZ03LDU,&var1552);
  setData(idB6AD20LDU,&var1548);
  setData(idB6AD10LDU,&var1547);
  setData(idA6AD20LDU,&var1557);
  setData(idA6AD10LDU,&var1556);
  setData(idR0ES01LDU,&var805);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
  for( i=0;i<10;i++ )
    array_m315_rz_1[i] = &(&internal1_m315_rz)[i];
  for( i=0;i<10;i++ )
    array_m261_rz_1[i] = &(&internal1_m261_rz)[i];
  for( i=0;i<6;i++ )
    array_m1403_rz_1[i] = &(&internal1_m1403_rz)[i];
  for( i=0;i<60;i++ )
    array_m1325_x0_1[i] = &(&internal1_m1325_x0)[i];
  for( i=0;i<60;i++ )
    array_m1325_tim0_1[i] = &(&internal1_m1325_tim0)[i];
  for( i=0;i<60;i++ )
    array_m925_x0_1[i] = &(&internal1_m925_x0)[i];
  for( i=0;i<60;i++ )
    array_m925_tim0_1[i] = &(&internal1_m925_tim0)[i];
  for( i=0;i<150;i++ )
    array_m518_x0_1[i] = &(&internal1_m518_x0)[i];
  for( i=0;i<150;i++ )
    array_m518_tim0_1[i] = &(&internal1_m518_tim0)[i];
  for( i=0;i<150;i++ )
    array_m192_x0_1[i] = &(&internal1_m192_x0)[i];
  for( i=0;i<150;i++ )
    array_m192_tim0_1[i] = &(&internal1_m192_tim0)[i];
  for( i=0;i<80;i++ )
    array_m831_x0_1[i] = &(&internal1_m831_x0)[i];
  for( i=0;i<80;i++ )
    array_m831_tim0_1[i] = &(&internal1_m831_tim0)[i];
  for( i=0;i<80;i++ )
    array_m1232_x0_1[i] = &(&internal1_m1232_x0)[i];
  for( i=0;i<80;i++ )
    array_m1232_tim0_1[i] = &(&internal1_m1232_tim0)[i];
  for( i=0;i<20;i++ )
    array_m1604_x0_1[i] = &(&internal1_m1604_x0)[i];
  for( i=0;i<20;i++ )
    array_m1604_tim0_1[i] = &(&internal1_m1604_tim0)[i];
  for( i=0;i<20;i++ )
    array_m1138_x0_1[i] = &(&internal1_m1138_x0)[i];
  for( i=0;i<20;i++ )
    array_m1138_tim0_1[i] = &(&internal1_m1138_tim0)[i];
}

#endif
