#ifndef DU_H
#define DU_H
// Подсистема DU:DU
static char SimulOn=0;
static short CodeSub=2;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 10818
static char BUFFER[10818];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.50\0", 5432, "192.168.10.150\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define A3VZ15LZ1	 BUFFER[0]	//(vds32:02 - K19VDSR, - ) Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ1	 1	//(vds32:02 - K19VDSR, - ) Имитация срабатывания АЗ от НУП ИС
#define A3VZ15LZ2	 BUFFER[2]	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ2	 2	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define B2IS33LDU	 BUFFER[4]	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
#define idB2IS33LDU	 3	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
#define B3IS31LDU	 BUFFER[6]	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
#define idB3IS31LDU	 4	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
#define B3IS33LDU	 BUFFER[8]	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
#define idB3IS33LDU	 5	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
#define B3IS35LDU	 BUFFER[10]	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
#define idB3IS35LDU	 6	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
#define B4IS10LDU	 BUFFER[12]	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
#define idB4IS10LDU	 7	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
#define R6IS31LDU	 BUFFER[14]	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
#define idR6IS31LDU	 8	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
#define R6IS32LDU	 BUFFER[16]	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
#define idR6IS32LDU	 9	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
#define R6IS42LDU	 BUFFER[18]	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
#define idR6IS42LDU	 10	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
#define R6IS41LDU	 BUFFER[20]	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
#define idR6IS41LDU	 11	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
#define R6IS52LDU	 BUFFER[22]	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
#define idR6IS52LDU	 12	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
#define R6IS51LDU	 BUFFER[24]	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
#define idR6IS51LDU	 13	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
#define R3IS11LDU	 BUFFER[26]	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
#define idR3IS11LDU	 14	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
#define R3IS21LDU	 BUFFER[28]	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
#define idR3IS21LDU	 15	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
#define R0AB03LDU	 BUFFER[30]	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
#define idR0AB03LDU	 16	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
#define R0AB05LDU	 BUFFER[32]	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
#define idR0AB05LDU	 17	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
#define R0VN11RZ1	 BUFFER[34]	//( - , MDuBz1) Средняя мощность по BAZ1
#define idR0VN11RZ1	 18	//( - , MDuBz1) Средняя мощность по BAZ1
#define R0VN11RZ2	 BUFFER[39]	//( - , MDuBz2) Средняя мощность по BAZ2
#define idR0VN11RZ2	 19	//( - , MDuBz2) Средняя мощность по BAZ2
#define A2AB15LDU	 BUFFER[44]	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define idA2AB15LDU	 20	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define B2AB15LDU	 BUFFER[46]	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define idB2AB15LDU	 21	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define R0AD21LDU	 BUFFER[48]	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
#define idR0AD21LDU	 22	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
#define B2VS01IDU	 BUFFER[50]	//( - , DU) Готовность к управлению РБ2
#define idB2VS01IDU	 23	//( - , DU) Готовность к управлению РБ2
#define A7AS31LDU	 BUFFER[53]	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
#define idA7AS31LDU	 24	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
#define B7AS31LDU	 BUFFER[55]	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
#define idB7AS31LDU	 25	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
#define A7AZ03LDU	 BUFFER[57]	//( - , DU) Несанкционированное включение обдува АЗ1
#define idA7AZ03LDU	 26	//( - , DU) Несанкционированное включение обдува АЗ1
#define B7AZ03LDU	 BUFFER[59]	//( - , DU) Несанкционированное включение обдува АЗ2
#define idB7AZ03LDU	 27	//( - , DU) Несанкционированное включение обдува АЗ2
#define B3MD12LP1	 BUFFER[61]	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
#define idB3MD12LP1	 28	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
#define B3MD11LP1	 BUFFER[63]	//( - , DU) Кнопка ПУСК ИС2
#define idB3MD11LP1	 29	//( - , DU) Кнопка ПУСК ИС2
#define R0VL01RDU	 BUFFER[65]	//( - , DU) Индикация Время задержки
#define idR0VL01RDU	 30	//( - , DU) Индикация Время задержки
#define R0VZ71LZ2	 BUFFER[70]	//(vds32:03 - K22VDSR, - ) Обобщенный сигнал АЗ 2 канала
#define idR0VZ71LZ2	 31	//(vds32:03 - K22VDSR, - ) Обобщенный сигнал АЗ 2 канала
#define R0VZ71LZ1	 BUFFER[72]	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
#define idR0VZ71LZ1	 32	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
#define R0VZ71LDU	 BUFFER[74]	//( - , DU) Обобщенный сигнал АЗ
#define idR0VZ71LDU	 33	//( - , DU) Обобщенный сигнал АЗ
#define A2IS33LDU	 BUFFER[76]	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
#define idA2IS33LDU	 34	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
#define A3IS31LDU	 BUFFER[78]	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
#define idA3IS31LDU	 35	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
#define A3IS33LDU	 BUFFER[80]	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
#define idA3IS33LDU	 36	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
#define A3IS35LDU	 BUFFER[82]	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
#define idA3IS35LDU	 37	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
#define A4IS10LDU	 BUFFER[84]	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
#define idA4IS10LDU	 38	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
#define A1VN71LZ1	 BUFFER[86]	//(vds32:02 - K21VDSR, - ) Блокировка автоматического подъёма ББ
#define idA1VN71LZ1	 39	//(vds32:02 - K21VDSR, - ) Блокировка автоматического подъёма ББ
#define A1VN71LZ2	 BUFFER[88]	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define idA1VN71LZ2	 40	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define A1AB19LDU	 BUFFER[90]	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
#define idA1AB19LDU	 41	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
#define R0AD14LZ1	 BUFFER[92]	//(vds32:02 - K20VDSR, - ) Имитация срабатывания АЗ от II УР
#define idR0AD14LZ1	 42	//(vds32:02 - K20VDSR, - ) Имитация срабатывания АЗ от II УР
#define R0AD14LZ2	 BUFFER[94]	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
#define idR0AD14LZ2	 43	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
#define A3VZ13LZ2	 BUFFER[96]	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ2	 44	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define A3VZ13LZ1	 BUFFER[98]	//(vds32:02 - K18VDSR, - ) Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ1	 45	//(vds32:02 - K18VDSR, - ) Имитация срабатывания АЗ от ВУ ИС
#define B6AB05LDU	 BUFFER[100]	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
#define idB6AB05LDU	 46	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
#define R0AB08LDU	 BUFFER[102]	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
#define idR0AB08LDU	 47	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
#define A1MC01RP1	 BUFFER[104]	//( - , DU) Заданная координата положения ББ1 мм
#define idA1MC01RP1	 48	//( - , DU) Заданная координата положения ББ1 мм
#define B1MC01RP1	 BUFFER[109]	//( - , DU) Заданная координата положения ББ2  мм
#define idB1MC01RP1	 49	//( - , DU) Заданная координата положения ББ2  мм
#define A3MC01RP1	 BUFFER[114]	//( - , DU) Заданная координата положения ИС1 мм
#define idA3MC01RP1	 50	//( - , DU) Заданная координата положения ИС1 мм
#define B3MC01RP1	 BUFFER[119]	//( - , DU) Заданная координата положения ИС2 мм
#define idB3MC01RP1	 51	//( - , DU) Заданная координата положения ИС2 мм
#define B8MC01RP2	 BUFFER[124]	//( - , DU) Заданная координата АЗ2 мм
#define idB8MC01RP2	 52	//( - , DU) Заданная координата АЗ2 мм
#define R0AB09LDU	 BUFFER[129]	//( - , DU) Ошибка в заданной координате ББ1
#define idR0AB09LDU	 53	//( - , DU) Ошибка в заданной координате ББ1
#define R0AB10LDU	 BUFFER[131]	//( - , DU) Ошибка в заданной координате ББ2
#define idR0AB10LDU	 54	//( - , DU) Ошибка в заданной координате ББ2
#define R0AB11LDU	 BUFFER[133]	//( - , DU) Ошибка в заданной координате  ИС1
#define idR0AB11LDU	 55	//( - , DU) Ошибка в заданной координате  ИС1
#define R0AB12LDU	 BUFFER[135]	//( - , DU) Ошибка в заданной координате  ИС2
#define idR0AB12LDU	 56	//( - , DU) Ошибка в заданной координате  ИС2
#define R0AB13LDU	 BUFFER[137]	//( - , DU) Ошибка в заданной координате  АЗ2
#define idR0AB13LDU	 57	//( - , DU) Ошибка в заданной координате  АЗ2
#define A4ZAV	 BUFFER[139]	//( - , DU) 
#define idA4ZAV	 58	//( - , DU) 
#define A6ZAV	 BUFFER[141]	//( - , DU) 
#define idA6ZAV	 59	//( - , DU) 
#define R2ZAV	 BUFFER[143]	//( - , DU) 
#define idR2ZAV	 60	//( - , DU) 
#define A5ZAV	 BUFFER[145]	//( - , DU) 
#define idA5ZAV	 61	//( - , DU) 
#define B8ZAV	 BUFFER[147]	//( - , DU) 
#define idB8ZAV	 62	//( - , DU) 
#define A2ZAV	 BUFFER[149]	//( - , DU) Завершение РБ1,2
#define idA2ZAV	 63	//( - , DU) Завершение РБ1,2
#define A8ZAV	 BUFFER[151]	//( - , DU) 
#define idA8ZAV	 64	//( - , DU) 
#define A9ZAV	 BUFFER[153]	//( - , DU) Завершение НИ ДС1(2)
#define idA9ZAV	 65	//( - , DU) Завершение НИ ДС1(2)
#define R4ABL	 BUFFER[155]	//( - , DU) Блокировка тележки -
#define idR4ABL	 66	//( - , DU) Блокировка тележки -
#define A4UP	 BUFFER[157]	//( - , DU) 
#define idA4UP	 67	//( - , DU) 
#define A4DW	 BUFFER[159]	//( - , DU) 
#define idA4DW	 68	//( - , DU) 
#define R0VX02LDU	 BUFFER[161]	//( - , DU) Импульс разрешен
#define idR0VX02LDU	 69	//( - , DU) Импульс разрешен
#define R0EE03LDU	 BUFFER[163]	//( - , DU) ВПИС ИС
#define idR0EE03LDU	 70	//( - , DU) ВПИС ИС
#define R0AB07LDU	 BUFFER[165]	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
#define idR0AB07LDU	 71	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
#define R0AD16LDU	 BUFFER[167]	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
#define idR0AD16LDU	 72	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
#define C2MD31LP1	 BUFFER[169]	//( - , DU) Кнопка СБРОС РБ
#define idC2MD31LP1	 73	//( - , DU) Кнопка СБРОС РБ
#define B6VS01IDU	 BUFFER[171]	//( - , DU) Готовность к управлению БЗ2
#define idB6VS01IDU	 74	//( - , DU) Готовность к управлению БЗ2
#define R2AD20LDU	 BUFFER[174]	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
#define idR2AD20LDU	 75	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
#define R2AD10LDU	 BUFFER[176]	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
#define idR2AD10LDU	 76	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
#define B8VS01IDU	 BUFFER[178]	//( - , DU) Готовность к управлению АЗ2
#define idB8VS01IDU	 77	//( - , DU) Готовность к управлению АЗ2
#define A8VS01IDU	 BUFFER[181]	//( - , DU) Готовность к управлению ДС2
#define idA8VS01IDU	 78	//( - , DU) Готовность к управлению ДС2
#define A1IE03LDU	 BUFFER[184]	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
#define idA1IE03LDU	 79	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
#define A1IE04LDU	 BUFFER[186]	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
#define idA1IE04LDU	 80	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
#define A2IE03LDU	 BUFFER[188]	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
#define idA2IE03LDU	 81	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
#define A2IE04LDU	 BUFFER[190]	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
#define idA2IE04LDU	 82	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
#define A3IE03LDU	 BUFFER[192]	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
#define idA3IE03LDU	 83	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
#define A3IE04LDU	 BUFFER[194]	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
#define idA3IE04LDU	 84	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
#define B1IE03LDU	 BUFFER[196]	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
#define idB1IE03LDU	 85	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
#define B1IE04LDU	 BUFFER[198]	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
#define idB1IE04LDU	 86	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
#define B2IE03LDU	 BUFFER[200]	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
#define idB2IE03LDU	 87	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
#define B2IE04LDU	 BUFFER[202]	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
#define idB2IE04LDU	 88	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
#define B3IE03LDU	 BUFFER[204]	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
#define idB3IE03LDU	 89	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
#define B3IE04LDU	 BUFFER[206]	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
#define idB3IE04LDU	 90	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
#define R0VS11LDU	 BUFFER[208]	//( - , DU) РУ не готова к работе
#define idR0VS11LDU	 91	//( - , DU) РУ не готова к работе
#define B5VS01IDU	 BUFFER[210]	//( - , DU) Готовность к управлению НЛ2
#define idB5VS01IDU	 92	//( - , DU) Готовность к управлению НЛ2
#define A6VS01IDU	 BUFFER[213]	//( - , DU) Готовность к управлению БЗ1
#define idA6VS01IDU	 93	//( - , DU) Готовность к управлению БЗ1
#define R4VS01IDU	 BUFFER[216]	//( - , DU) Готовность к управлению тележкой реактора
#define idR4VS01IDU	 94	//( - , DU) Готовность к управлению тележкой реактора
#define R2VS01IDU	 BUFFER[219]	//( - , DU) Готовность к управлению МДЗ2
#define idR2VS01IDU	 95	//( - , DU) Готовность к управлению МДЗ2
#define R1VS01IDU	 BUFFER[222]	//( - , DU) Готовность к управлению МДЗ1
#define idR1VS01IDU	 96	//( - , DU) Готовность к управлению МДЗ1
#define A9IS11LDU	 BUFFER[225]	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
#define idA9IS11LDU	 97	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
#define A9IS21LDU	 BUFFER[227]	//(vds32:02 - K24VDSR, - ) Приход на НУ НИ ДС1
#define idA9IS21LDU	 98	//(vds32:02 - K24VDSR, - ) Приход на НУ НИ ДС1
#define B9IS11LDU	 BUFFER[229]	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
#define idB9IS11LDU	 99	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
#define B9IS21LDU	 BUFFER[231]	//(vds32:02 - K26VDSR, - ) Приход на НУ НИ ДС2
#define idB9IS21LDU	 100	//(vds32:02 - K26VDSR, - ) Приход на НУ НИ ДС2
#define B9AD10LDU	 BUFFER[233]	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
#define idB9AD10LDU	 101	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
#define A9AD10LDU	 BUFFER[235]	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
#define idA9AD10LDU	 102	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
#define A9AZ03LDU	 BUFFER[237]	//( - , DU) Несанкционированное перемещение НИ ДС1
#define idA9AZ03LDU	 103	//( - , DU) Несанкционированное перемещение НИ ДС1
#define A9AB01LDU	 BUFFER[239]	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
#define idA9AB01LDU	 104	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
#define A9AB02LDU	 BUFFER[241]	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
#define idA9AB02LDU	 105	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
#define B9AZ03LDU	 BUFFER[243]	//( - , DU) Несанкционированное перемещение НИ ДС2
#define idB9AZ03LDU	 106	//( - , DU) Несанкционированное перемещение НИ ДС2
#define B9AB01LDU	 BUFFER[245]	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
#define idB9AB01LDU	 107	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
#define B9AB02LDU	 BUFFER[247]	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
#define idB9AB02LDU	 108	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
#define R0AB01LDU	 BUFFER[249]	//( - , DU) Режим проверки разрешён
#define idR0AB01LDU	 109	//( - , DU) Режим проверки разрешён
#define A3IS22LDU	 BUFFER[251]	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
#define idA3IS22LDU	 110	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
#define B3IS22LDU	 BUFFER[253]	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
#define idB3IS22LDU	 111	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
#define A2AD33LDU	 BUFFER[255]	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
#define idA2AD33LDU	 112	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
#define B2AD33LDU	 BUFFER[257]	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
#define idB2AD33LDU	 113	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
#define R8AD21LDU	 BUFFER[259]	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
#define idR8AD21LDU	 114	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
#define R0AD14LDU	 BUFFER[261]	//( - , DU) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 115	//( - , DU) Имитация срабатывания верхней АС II УР
#define R0VL04RDU	 BUFFER[263]	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
#define idR0VL04RDU	 116	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
#define R0AB04LDU	 BUFFER[268]	//( - , DU) Нарушение времени срабатывания верхней АС II УР
#define idR0AB04LDU	 117	//( - , DU) Нарушение времени срабатывания верхней АС II УР
#define R0AB06LDU	 BUFFER[270]	//( - , DU) Нарушение времени задержки от ВУ РБ
#define idR0AB06LDU	 118	//( - , DU) Нарушение времени задержки от ВУ РБ
#define R0AB02LDU	 BUFFER[272]	//( - , DU) Нарушение времени задержки ИНИ
#define idR0AB02LDU	 119	//( - , DU) Нарушение времени задержки ИНИ
#define R0VL03RDU	 BUFFER[274]	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define idR0VL03RDU	 120	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define R0VL05RDU	 BUFFER[279]	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
#define idR0VL05RDU	 121	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
#define R0VL21IDU	 BUFFER[284]	//( - , DU) Декатрон
#define idR0VL21IDU	 122	//( - , DU) Декатрон
#define R0VX03LDU	 BUFFER[287]	//( - , DU) Готовность 2 мин
#define idR0VX03LDU	 123	//( - , DU) Готовность 2 мин
#define R0VS21IDU	 BUFFER[289]	//( - , DU) Индикация ВИД ПРОВЕРКИ
#define idR0VS21IDU	 124	//( - , DU) Индикация ВИД ПРОВЕРКИ
#define A1VS01IDU	 BUFFER[292]	//( - , DU) Готовность к управлению ББ1
#define idA1VS01IDU	 125	//( - , DU) Готовность к управлению ББ1
#define B1VS01IDU	 BUFFER[295]	//( - , DU) Готовность к управлению ББ2
#define idB1VS01IDU	 126	//( - , DU) Готовность к управлению ББ2
#define A3VS01IDU	 BUFFER[298]	//( - , DU) Готовность к управлению ИС1
#define idA3VS01IDU	 127	//( - , DU) Готовность к управлению ИС1
#define B3VS01IDU	 BUFFER[301]	//( - , DU) Готовность к управлению ИС2
#define idB3VS01IDU	 128	//( - , DU) Готовность к управлению ИС2
#define A2VS01IDU	 BUFFER[304]	//( - , DU) Готовность к управлению РБ1
#define idA2VS01IDU	 129	//( - , DU) Готовность к управлению РБ1
#define A4VS01IDU	 BUFFER[307]	//( - , DU) Готовность к управлению НИ1
#define idA4VS01IDU	 130	//( - , DU) Готовность к управлению НИ1
#define A4VS12LDU	 BUFFER[310]	//( - , DU) Движение НИ1 в сторону ВУ
#define idA4VS12LDU	 131	//( - , DU) Движение НИ1 в сторону ВУ
#define A4VS22LDU	 BUFFER[312]	//( - , DU) Движение НИ1 в сторону НУ
#define idA4VS22LDU	 132	//( - , DU) Движение НИ1 в сторону НУ
#define B4VS01IDU	 BUFFER[314]	//( - , DU) Готовность к управлению НИ2
#define idB4VS01IDU	 133	//( - , DU) Готовность к управлению НИ2
#define B4VS12LDU	 BUFFER[317]	//( - , DU) Движение НИ2 в сторону ВУ
#define idB4VS12LDU	 134	//( - , DU) Движение НИ2 в сторону ВУ
#define B4VS22LDU	 BUFFER[319]	//( - , DU) Движение НИ2 в сторону НУ
#define idB4VS22LDU	 135	//( - , DU) Движение НИ2 в сторону НУ
#define A5VS01IDU	 BUFFER[321]	//( - , DU) Готовность к управлению НЛ1
#define idA5VS01IDU	 136	//( - , DU) Готовность к управлению НЛ1
#define B2VS32LDU	 BUFFER[324]	//( - , DU) Индикация  СБРОС РБ2
#define idB2VS32LDU	 137	//( - , DU) Индикация  СБРОС РБ2
#define A3VX01LDU	 BUFFER[326]	//( - , DU) Индикация Выстрел ИС1
#define idA3VX01LDU	 138	//( - , DU) Индикация Выстрел ИС1
#define A3IS11LDU	 BUFFER[328]	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
#define idA3IS11LDU	 139	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
#define B3VX01LDU	 BUFFER[330]	//( - , DU) Индикация Выстрел ИС2
#define idB3VX01LDU	 140	//( - , DU) Индикация Выстрел ИС2
#define R0VS18LDU	 BUFFER[332]	//( - , DU) Индикация  Проверка схем сброса
#define idR0VS18LDU	 141	//( - , DU) Индикация  Проверка схем сброса
#define B1MD11LP1	 BUFFER[334]	//( - , DU) Кнопка ПУСК ББ2
#define idB1MD11LP1	 142	//( - , DU) Кнопка ПУСК ББ2
#define B1MD12LP1	 BUFFER[336]	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
#define idB1MD12LP1	 143	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
#define B2MD11LP1	 BUFFER[338]	//( - , DU) Кнопка ПУСК РБ2
#define idB2MD11LP1	 144	//( - , DU) Кнопка ПУСК РБ2
#define B2MD12LP1	 BUFFER[340]	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
#define idB2MD12LP1	 145	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
#define A2MD11LP1	 BUFFER[342]	//( - , DU) Кнопка ПУСК РБ1
#define idA2MD11LP1	 146	//( - , DU) Кнопка ПУСК РБ1
#define A2MD12LP1	 BUFFER[344]	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
#define idA2MD12LP1	 147	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
#define R0IS01LDU	 BUFFER[346]	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
#define idR0IS01LDU	 148	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
#define R0IS02LDU	 BUFFER[348]	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
#define idR0IS02LDU	 149	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
#define R0VP73LZ1	 BUFFER[350]	//( - , MDuBz1) ПС давления для РУ
#define idR0VP73LZ1	 150	//( - , MDuBz1) ПС давления для РУ
#define R0VP73LZ2	 BUFFER[352]	//( - , MDuBz2) ПС давления для РУ
#define idR0VP73LZ2	 151	//( - , MDuBz2) ПС давления для РУ
#define R0VP73LDU	 BUFFER[354]	//( - , DU) ПС давления для РУ
#define idR0VP73LDU	 152	//( - , DU) ПС давления для РУ
#define R0MD34LP1	 BUFFER[356]	//( - , DU) Кнопка КВИТИРОВАТЬ
#define idR0MD34LP1	 153	//( - , DU) Кнопка КВИТИРОВАТЬ
#define A0VT71LZ1	 BUFFER[358]	//( - , MDuBz1) АС по температуре в АЗ1
#define idA0VT71LZ1	 154	//( - , MDuBz1) АС по температуре в АЗ1
#define B0VT71LZ1	 BUFFER[360]	//( - , MDuBz1) АС по температуре в АЗ2
#define idB0VT71LZ1	 155	//( - , MDuBz1) АС по температуре в АЗ2
#define A0VT71LZ2	 BUFFER[362]	//( - , MDuBz2) АС по температуре в АЗ1
#define idA0VT71LZ2	 156	//( - , MDuBz2) АС по температуре в АЗ1
#define B0VT71LZ2	 BUFFER[364]	//( - , MDuBz2) АС по температуре в АЗ2
#define idB0VT71LZ2	 157	//( - , MDuBz2) АС по температуре в АЗ2
#define B2VS11LDU	 BUFFER[366]	//( - , DU) Движение РБ2 в сторону ВУ
#define idB2VS11LDU	 158	//( - , DU) Движение РБ2 в сторону ВУ
#define B2VS21LDU	 BUFFER[368]	//( - , DU) Движение РБ2 в сторону НУ
#define idB2VS21LDU	 159	//( - , DU) Движение РБ2 в сторону НУ
#define A3AD33LDU	 BUFFER[370]	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
#define idA3AD33LDU	 160	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
#define A3AD34LDU	 BUFFER[372]	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
#define idA3AD34LDU	 161	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
#define A3AD31LDU	 BUFFER[374]	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
#define idA3AD31LDU	 162	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
#define B3AD34LDU	 BUFFER[376]	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
#define idB3AD34LDU	 163	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
#define B3AD31LDU	 BUFFER[378]	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
#define idB3AD31LDU	 164	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
#define A2IS11LDU	 BUFFER[380]	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
#define idA2IS11LDU	 165	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
#define B2IS11LDU	 BUFFER[382]	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
#define idB2IS11LDU	 166	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
#define A3MD12LP1	 BUFFER[384]	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
#define idA3MD12LP1	 167	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
#define A3MD11LP1	 BUFFER[386]	//( - , DU) Кнопка ПУСК ИС1
#define idA3MD11LP1	 168	//( - , DU) Кнопка ПУСК ИС1
#define R0MD33LP1	 BUFFER[388]	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
#define idR0MD33LP1	 169	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
#define A1MD12LP1	 BUFFER[390]	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
#define idA1MD12LP1	 170	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
#define A1MD11LP1	 BUFFER[392]	//( - , DU) Кнопка ПУСК ББ1
#define idA1MD11LP1	 171	//( - , DU) Кнопка ПУСК ББ1
#define R0MW14IP2	 BUFFER[394]	//( - , DU) Переключатель ОБДУВ
#define idR0MW14IP2	 172	//( - , DU) Переключатель ОБДУВ
#define A7AP31LDU	 BUFFER[397]	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
#define idA7AP31LDU	 173	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
#define B7AP31LDU	 BUFFER[399]	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
#define idB7AP31LDU	 174	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
#define R0MW12IP2	 BUFFER[401]	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define idR0MW12IP2	 175	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define R0MW17LP1	 BUFFER[404]	//( - , DU) Переключатель АВТ/Р
#define idR0MW17LP1	 176	//( - , DU) Переключатель АВТ/Р
#define R0VW13LDU	 BUFFER[406]	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
#define idR0VW13LDU	 177	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
#define R0VW23LDU	 BUFFER[408]	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
#define idR0VW23LDU	 178	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
#define R0VX08IDU	 BUFFER[410]	//( - , DU) Индикация Режим
#define idR0VX08IDU	 179	//( - , DU) Индикация Режим
#define R0VX09LDU	 BUFFER[413]	//( - , DU) Индикация регулятор мощности включен/отключен
#define idR0VX09LDU	 180	//( - , DU) Индикация регулятор мощности включен/отключен
#define R0VS17LDU	 BUFFER[415]	//( - , DU) Индикация выбора АВТОМАТ
#define idR0VS17LDU	 181	//( - , DU) Индикация выбора АВТОМАТ
#define A2VS32LDU	 BUFFER[417]	//( - , DU) Индикация  СБРОС РБ1
#define idA2VS32LDU	 182	//( - , DU) Индикация  СБРОС РБ1
#define A8MC01LC1	 BUFFER[419]	//( - , DU) Настроить энкодер ДС2
#define idA8MC01LC1	 183	//( - , DU) Настроить энкодер ДС2
#define A8MC01LC2	 BUFFER[421]	//( - , DU) Настроить энкодер ДС2
#define idA8MC01LC2	 184	//( - , DU) Настроить энкодер ДС2
#define A3VP42LDU	 BUFFER[423]	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
#define idA3VP42LDU	 185	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
#define A3CP02RDU	 BUFFER[425]	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
#define idA3CP02RDU	 186	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
#define A3VP52LDU	 BUFFER[430]	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define idA3VP52LDU	 187	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define B3VP42LDU	 BUFFER[432]	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
#define idB3VP42LDU	 188	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
#define B3CP02RDU	 BUFFER[434]	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
#define idB3CP02RDU	 189	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
#define B3VP52LDU	 BUFFER[439]	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define idB3VP52LDU	 190	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define B3VP82LDU	 BUFFER[441]	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
#define idB3VP82LDU	 191	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
#define A3VP82LDU	 BUFFER[443]	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
#define idA3VP82LDU	 192	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
#define A3IP02IDU	 BUFFER[445]	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	 193	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
#define B3IP02IDU	 BUFFER[448]	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
#define idB3IP02IDU	 194	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
#define A0VE01LDU	 BUFFER[451]	//( - , DU) Напряжение в системы АЗ1 подано
#define idA0VE01LDU	 195	//( - , DU) Напряжение в системы АЗ1 подано
#define B0VE01LDU	 BUFFER[453]	//( - , DU) Напряжение в системы АЗ2 подано
#define idB0VE01LDU	 196	//( - , DU) Напряжение в системы АЗ2 подано
#define A0VP01LDU	 BUFFER[455]	//( - , DU) Давление в системы АЗ1 подано
#define idA0VP01LDU	 197	//( - , DU) Давление в системы АЗ1 подано
#define B0VP01LDU	 BUFFER[457]	//( - , DU) Давление в системы АЗ2 подано
#define idB0VP01LDU	 198	//( - , DU) Давление в системы АЗ2 подано
#define A0EE01LZ1	 BUFFER[459]	//( - , MDuBz1) Исправность АКНП1
#define idA0EE01LZ1	 199	//( - , MDuBz1) Исправность АКНП1
#define A0EE03LZ1	 BUFFER[461]	//( - , MDuBz1) Исправность АКНП3
#define idA0EE03LZ1	 200	//( - , MDuBz1) Исправность АКНП3
#define A0EE02LZ1	 BUFFER[463]	//( - , MDuBz1) Исправность АКНП2
#define idA0EE02LZ1	 201	//( - , MDuBz1) Исправность АКНП2
#define A0EE04LZ1	 BUFFER[465]	//( - , MDuBz1) Исправность АКНП4
#define idA0EE04LZ1	 202	//( - , MDuBz1) Исправность АКНП4
#define A0VN01LDU	 BUFFER[467]	//( - , DU) Каналы АЗ1 проверены
#define idA0VN01LDU	 203	//( - , DU) Каналы АЗ1 проверены
#define B0VN01LDU	 BUFFER[469]	//( - , DU) Каналы АЗ2 проверены
#define idB0VN01LDU	 204	//( - , DU) Каналы АЗ2 проверены
#define A3IC01UDU	 BUFFER[471]	//( - , MDuS) Координата штока ИС1 (дел.энк)
#define idA3IC01UDU	 205	//( - , MDuS) Координата штока ИС1 (дел.энк)
#define B3IC01UDU	 BUFFER[476]	//( - , MDuS) Координата штока ИС2 (дел.энк)
#define idB3IC01UDU	 206	//( - , MDuS) Координата штока ИС2 (дел.энк)
#define B3VC01RDU	 BUFFER[481]	//( - , DU) Координата ИС2, мм
#define idB3VC01RDU	 207	//( - , DU) Координата ИС2, мм
#define A8IC01UDU	 BUFFER[486]	//( - , MDuS) Координата ДС2 (дел.энк)
#define idA8IC01UDU	 208	//( - , MDuS) Координата ДС2 (дел.энк)
#define A8VC01RDU	 BUFFER[491]	//( - , DU) Координата ДС2, мм
#define idA8VC01RDU	 209	//( - , DU) Координата ДС2, мм
#define B8IC01UDU	 BUFFER[496]	//( - , MDuS) Координата АЗ2 (дел.энк)
#define idB8IC01UDU	 210	//( - , MDuS) Координата АЗ2 (дел.энк)
#define A1IC01UDU	 BUFFER[501]	//( - , MDuS) Координата штока ББ1 (дел.энк)
#define idA1IC01UDU	 211	//( - , MDuS) Координата штока ББ1 (дел.энк)
#define A1VC01RDU	 BUFFER[506]	//( - , DU) Координата ББ1, мм
#define idA1VC01RDU	 212	//( - , DU) Координата ББ1, мм
#define A1IS11LDU	 BUFFER[511]	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
#define idA1IS11LDU	 213	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
#define B1MC01LC1	 BUFFER[513]	//( - , DU) Настроить энкодер ББ2
#define idB1MC01LC1	 214	//( - , DU) Настроить энкодер ББ2
#define B1MC01LC2	 BUFFER[515]	//( - , DU) Настроить энкодер ББ2
#define idB1MC01LC2	 215	//( - , DU) Настроить энкодер ББ2
#define A1MC01LC1	 BUFFER[517]	//( - , DU) Настроить энкодер ББ1
#define idA1MC01LC1	 216	//( - , DU) Настроить энкодер ББ1
#define A1MC01LC2	 BUFFER[519]	//( - , DU) Настроить энкодер ББ1
#define idA1MC01LC2	 217	//( - , DU) Настроить энкодер ББ1
#define B2MC01LC1	 BUFFER[521]	//( - , DU) Настроить энкодер РБ2
#define idB2MC01LC1	 218	//( - , DU) Настроить энкодер РБ2
#define B2MC01LC2	 BUFFER[523]	//( - , DU) Настроить энкодер РБ2
#define idB2MC01LC2	 219	//( - , DU) Настроить энкодер РБ2
#define A2MC01LC1	 BUFFER[525]	//( - , DU) Настроить энкодер РБ1
#define idA2MC01LC1	 220	//( - , DU) Настроить энкодер РБ1
#define A2MC01LC2	 BUFFER[527]	//( - , DU) Настроить энкодер РБ1
#define idA2MC01LC2	 221	//( - , DU) Настроить энкодер РБ1
#define B3MC01LC1	 BUFFER[529]	//( - , DU) Настроить энкодер ИС2
#define idB3MC01LC1	 222	//( - , DU) Настроить энкодер ИС2
#define B3MC01LC2	 BUFFER[531]	//( - , DU) Настроить энкодер ИС2
#define idB3MC01LC2	 223	//( - , DU) Настроить энкодер ИС2
#define A3MC01LC1	 BUFFER[533]	//( - , DU) Настроить энкодер ИС1
#define idA3MC01LC1	 224	//( - , DU) Настроить энкодер ИС1
#define A3MC01LC2	 BUFFER[535]	//( - , DU) Настроить энкодер ИС1
#define idA3MC01LC2	 225	//( - , DU) Настроить энкодер ИС1
#define B8MC01LC1	 BUFFER[537]	//( - , DU) Настроить энкодер АЗ2
#define idB8MC01LC1	 226	//( - , DU) Настроить энкодер АЗ2
#define B8MC01LC2	 BUFFER[539]	//( - , DU) Настроить энкодер АЗ2
#define idB8MC01LC2	 227	//( - , DU) Настроить энкодер АЗ2
#define R0IE01LDU	 BUFFER[541]	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
#define idR0IE01LDU	 228	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
#define A6IE01LDU	 BUFFER[543]	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
#define idA6IE01LDU	 229	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
#define B6IE01LDU	 BUFFER[545]	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
#define idB6IE01LDU	 230	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
#define A8IE01LDU	 BUFFER[547]	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
#define idA8IE01LDU	 231	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
#define B5IE01LDU	 BUFFER[549]	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
#define idB5IE01LDU	 232	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
#define A5IE02LDU	 BUFFER[551]	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
#define idA5IE02LDU	 233	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
#define R1IE01LDU	 BUFFER[553]	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
#define idR1IE01LDU	 234	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
#define R2IE01LDU	 BUFFER[555]	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
#define idR2IE01LDU	 235	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
#define R6IS61LDU	 BUFFER[557]	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
#define idR6IS61LDU	 236	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
#define R6IS66LZZ	 BUFFER[559]	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 237	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	 BUFFER[561]	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 238	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	 BUFFER[563]	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 239	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define A3VC01RDU	 BUFFER[565]	//( - , DU) Координата ИС1, мм
#define idA3VC01RDU	 240	//( - , DU) Координата ИС1, мм
#define A2VC01RDU	 BUFFER[570]	//( - , DU) Координата РБ1, мм
#define idA2VC01RDU	 241	//( - , DU) Координата РБ1, мм
#define B2VC01RDU	 BUFFER[575]	//( - , DU) Координата РБ2, мм
#define idB2VC01RDU	 242	//( - , DU) Координата РБ2, мм
#define B8VC01RDU	 BUFFER[580]	//( - , DU) Координата АЗ2, мм
#define idB8VC01RDU	 243	//( - , DU) Координата АЗ2, мм
#define A4VP82LDU	 BUFFER[585]	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	 244	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define B4VP82LDU	 BUFFER[587]	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	 245	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define A2VP82LDU	 BUFFER[589]	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	 246	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define B2VP82LDU	 BUFFER[591]	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define idB2VP82LDU	 247	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define A3VP81LDU	 BUFFER[593]	//( - , - ) Давление СПУСК ИС1 в норме
#define idA3VP81LDU	 248	//( - , - ) Давление СПУСК ИС1 в норме
#define B3VP81LDU	 BUFFER[595]	//( - , - ) Давление СПУСК ИС2 в норме
#define idB3VP81LDU	 249	//( - , - ) Давление СПУСК ИС2 в норме
#define R0EE02LDU	 BUFFER[597]	//( - , DU) Питание  АКНП  отключить
#define idR0EE02LDU	 250	//( - , DU) Питание  АКНП  отключить
#define A0EE01LZ2	 BUFFER[599]	//( - , MDuBz2) Исправность АКНП1
#define idA0EE01LZ2	 251	//( - , MDuBz2) Исправность АКНП1
#define A0EE03LZ2	 BUFFER[601]	//( - , MDuBz2) Исправность АКНП3
#define idA0EE03LZ2	 252	//( - , MDuBz2) Исправность АКНП3
#define A0EE02LZ2	 BUFFER[603]	//( - , MDuBz2) Исправность АКНП2
#define idA0EE02LZ2	 253	//( - , MDuBz2) Исправность АКНП2
#define A0EE04LZ2	 BUFFER[605]	//( - , MDuBz2) Исправность АКНП4
#define idA0EE04LZ2	 254	//( - , MDuBz2) Исправность АКНП4
#define A0VP71LZ1	 BUFFER[607]	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ1	 255	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
#define A0VP71LZ2	 BUFFER[609]	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ2	 256	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
#define B0VP71LZ1	 BUFFER[611]	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ1	 257	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
#define B0VP71LZ2	 BUFFER[613]	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ2	 258	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
#define A0VS11LDU	 BUFFER[615]	//( - , DU) АЗ1 готова к работе
#define idA0VS11LDU	 259	//( - , DU) АЗ1 готова к работе
#define B0VS11LDU	 BUFFER[617]	//( - , DU) АЗ2 готова к работе
#define idB0VS11LDU	 260	//( - , DU) АЗ2 готова к работе
#define A1IE01LDU	 BUFFER[619]	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
#define idA1IE01LDU	 261	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
#define A3IE01LDU	 BUFFER[621]	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
#define idA3IE01LDU	 262	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
#define A2IE01LDU	 BUFFER[623]	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
#define idA2IE01LDU	 263	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
#define A1IE02LDU	 BUFFER[625]	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
#define idA1IE02LDU	 264	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
#define A3IE02LDU	 BUFFER[627]	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
#define idA3IE02LDU	 265	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
#define A2IE02LDU	 BUFFER[629]	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
#define idA2IE02LDU	 266	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
#define B1IE01LDU	 BUFFER[631]	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
#define idB1IE01LDU	 267	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
#define B2IE01LDU	 BUFFER[633]	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
#define idB2IE01LDU	 268	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
#define B3IE01LDU	 BUFFER[635]	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
#define idB3IE01LDU	 269	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
#define B1IE02LDU	 BUFFER[637]	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
#define idB1IE02LDU	 270	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
#define B3IE02LDU	 BUFFER[639]	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
#define idB3IE02LDU	 271	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
#define B2IE02LDU	 BUFFER[641]	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
#define idB2IE02LDU	 272	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
#define R0IE02LDU	 BUFFER[643]	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
#define idR0IE02LDU	 273	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
#define R0VN11RDU	 BUFFER[645]	//( - , DU) Текущая мощность РУ
#define idR0VN11RDU	 274	//( - , DU) Текущая мощность РУ
#define R0VN12RDU	 BUFFER[650]	//( - , DU) Заданная мощность РУ
#define idR0VN12RDU	 275	//( - , DU) Заданная мощность РУ
#define R0AB19LDU	 BUFFER[655]	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
#define idR0AB19LDU	 276	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
#define R0CN93LDU	 BUFFER[657]	//( - , DU) время работы на мощности более 100Вт, сек
#define idR0CN93LDU	 277	//( - , DU) время работы на мощности более 100Вт, сек
#define R0CN94LDU	 BUFFER[662]	//( - , DU) Скорость изменения мощности
#define idR0CN94LDU	 278	//( - , DU) Скорость изменения мощности
#define R0CN95LDU	 BUFFER[667]	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
#define idR0CN95LDU	 279	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
#define R0AD03LZ1	 BUFFER[670]	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
#define idR0AD03LZ1	 280	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
#define R0AD03LZ2	 BUFFER[672]	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
#define idR0AD03LZ2	 281	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
#define R0AD04LZ1	 BUFFER[674]	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define idR0AD04LZ1	 282	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define R0AD04LZ2	 BUFFER[676]	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define idR0AD04LZ2	 283	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define R0AD05LZ1	 BUFFER[678]	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
#define idR0AD05LZ1	 284	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
#define R0AD05LZ2	 BUFFER[680]	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
#define idR0AD05LZ2	 285	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
#define B8IS12LDU	 BUFFER[682]	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
#define idB8IS12LDU	 286	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
#define B8IS21LDU	 BUFFER[684]	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
#define idB8IS21LDU	 287	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
#define A1VP41LZ1	 BUFFER[686]	//( - , DU) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ1	 288	//( - , DU) Давление СБРОС ББ1 ниже АС
#define A1VP41LZ2	 BUFFER[688]	//( - , DU) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ2	 289	//( - , DU) Давление СБРОС ББ1 ниже АС
#define R0VL22LDU	 BUFFER[690]	//( - , DU) Конец программы 200сек
#define idR0VL22LDU	 290	//( - , DU) Конец программы 200сек
#define R0VL23LDU	 BUFFER[692]	//( - , DU) Конец программы 20мин
#define idR0VL23LDU	 291	//( - , DU) Конец программы 20мин
#define B1VP41LZ1	 BUFFER[694]	//( - , DU) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ1	 292	//( - , DU) Давление СБРОС ББ2 ниже АС
#define B1VP41LZ2	 BUFFER[696]	//( - , DU) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ2	 293	//( - , DU) Давление СБРОС ББ2 ниже АС
#define A3AB19LDU	 BUFFER[698]	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
#define idA3AB19LDU	 294	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
#define B3AB19LDU	 BUFFER[700]	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
#define idB3AB19LDU	 295	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
#define R0AB14LDU	 BUFFER[702]	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
#define idR0AB14LDU	 296	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
#define R0AB15LDU	 BUFFER[704]	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
#define idR0AB15LDU	 297	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
#define A3IS12LDU	 BUFFER[706]	//( - , DU) Приход на ВУ штока ИС1
#define idA3IS12LDU	 298	//( - , DU) Приход на ВУ штока ИС1
#define B3IS12LDU	 BUFFER[708]	//( - , DU) Приход на ВУ штока ИС2
#define idB3IS12LDU	 299	//( - , DU) Приход на ВУ штока ИС2
#define A1ZAV	 BUFFER[710]	//( - , DU) 
#define idA1ZAV	 300	//( - , DU) 
#define A3ZAV	 BUFFER[712]	//( - , DU) 
#define idA3ZAV	 301	//( - , DU) 
#define B1AB19LDU	 BUFFER[714]	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
#define idB1AB19LDU	 302	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
#define R0VN09RZ2	 BUFFER[716]	//( - , MDuBz2) Усредненный период разгона
#define idR0VN09RZ2	 303	//( - , MDuBz2) Усредненный период разгона
#define R0VN09RZ1	 BUFFER[721]	//( - , MDuBz1) Усредненный период разгона
#define idR0VN09RZ1	 304	//( - , MDuBz1) Усредненный период разгона
#define R0AB16LDU	 BUFFER[726]	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
#define idR0AB16LDU	 305	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
#define R0AB17LDU	 BUFFER[728]	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
#define idR0AB17LDU	 306	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
#define R0AB18LDU	 BUFFER[730]	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
#define idR0AB18LDU	 307	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
#define A0CT01IZ1	 BUFFER[732]	//( - , MDuBz1) Температура АЗ1-1
#define idA0CT01IZ1	 308	//( - , MDuBz1) Температура АЗ1-1
#define B0CT01IZ1	 BUFFER[737]	//( - , MDuBz1) Температура АЗ2-1
#define idB0CT01IZ1	 309	//( - , MDuBz1) Температура АЗ2-1
#define A0CT01IZ2	 BUFFER[742]	//( - , MDuBz2) Температура АЗ1-2
#define idA0CT01IZ2	 310	//( - , MDuBz2) Температура АЗ1-2
#define B0CT01IZ2	 BUFFER[747]	//( - , MDuBz2) Температура АЗ2-2
#define idB0CT01IZ2	 311	//( - , MDuBz2) Температура АЗ2-2
#define A3MC01RDU	 BUFFER[752]	//( - , DU) Заданная координата положения ИС от регулятора мм
#define idA3MC01RDU	 312	//( - , DU) Заданная координата положения ИС от регулятора мм
#define A3MC02RDU	 BUFFER[757]	//( - , DU) Температурная корректировка координаты ИМ
#define idA3MC02RDU	 313	//( - , DU) Температурная корректировка координаты ИМ
#define R0CN91LDU	 BUFFER[762]	//( - , DU) Рассчётная реактивность от регулятора
#define idR0CN91LDU	 314	//( - , DU) Рассчётная реактивность от регулятора
#define A3MC03RDU	 BUFFER[767]	//( - , DU) Координата положения ИМ 0-й реактивности
#define idA3MC03RDU	 315	//( - , DU) Координата положения ИМ 0-й реактивности
#define A3AB15LDU	 BUFFER[772]	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
#define idA3AB15LDU	 316	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
#define R0AB20LDU	 BUFFER[774]	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
#define idR0AB20LDU	 317	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
#define R0CN92LDU	 BUFFER[776]	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
#define idR0CN92LDU	 318	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
#define R0DE0FLDU	 BUFFER[781]	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
#define idR0DE0FLDU	 319	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
#define R0DE31LDU	 BUFFER[784]	//(sbk:20 - S01SBK, DiagnDU) диагностика шкафа ДУ сеть 1
#define idR0DE31LDU	 320	//(sbk:20 - S01SBK, DiagnDU) диагностика шкафа ДУ сеть 1
#define TTLDU	 BUFFER[786]	//( - , DU) ttl
#define idTTLDU	 321	//( - , DU) ttl
#define R0DE32LDU	 BUFFER[789]	//(sbk:20 - S02SBK, DiagnDU) диагностика шкафа ДУ сеть 2
#define idR0DE32LDU	 322	//(sbk:20 - S02SBK, DiagnDU) диагностика шкафа ДУ сеть 2
#define R0DE33LDU	 BUFFER[791]	//(sbk:20 - S03SBK, DiagnDU) диагностика шкафа ДУ двери
#define idR0DE33LDU	 323	//(sbk:20 - S03SBK, DiagnDU) диагностика шкафа ДУ двери
#define R0DE34LDU	 BUFFER[793]	//(sbk:20 - S04SBK, DiagnDU) диагностика шкафа ДУ температура меньше 43
#define idR0DE34LDU	 324	//(sbk:20 - S04SBK, DiagnDU) диагностика шкафа ДУ температура меньше 43
#define R0DE35LDU	 BUFFER[795]	//(sbk:20 - S05SBK, DiagnDU) диагностика шкафа ДУ температура больше 53
#define idR0DE35LDU	 325	//(sbk:20 - S05SBK, DiagnDU) диагностика шкафа ДУ температура больше 53
#define R0DE36LDU	 BUFFER[797]	//(sbk:20 - S06SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 1
#define idR0DE36LDU	 326	//(sbk:20 - S06SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 1
#define R0DE37LDU	 BUFFER[799]	//(sbk:20 - S07SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 2
#define idR0DE37LDU	 327	//(sbk:20 - S07SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 2
#define R0DE38LDU	 BUFFER[801]	//(sbk:20 - S08SBK, DiagnDU) диагностика шкафа ДУ МП15-3 место 3
#define idR0DE38LDU	 328	//(sbk:20 - S08SBK, DiagnDU) диагностика шкафа ДУ МП15-3 место 3
#define R0DE39LDU	 BUFFER[803]	//(sbk:20 - S09SBK, DiagnDU) диагностика шкафа ДУ МП24-2 место 4
#define idR0DE39LDU	 329	//(sbk:20 - S09SBK, DiagnDU) диагностика шкафа ДУ МП24-2 место 4
#define R0DEB3LDU	 BUFFER[805]	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
#define idR0DEB3LDU	 330	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
#define R0DEB2LDU	 BUFFER[807]	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
#define idR0DEB2LDU	 331	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
#define R0DEB1LDU	 BUFFER[809]	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
#define idR0DEB1LDU	 332	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
#define R0DEB4LDU	 BUFFER[811]	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
#define idR0DEB4LDU	 333	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
#define R0DE3DLDU	 BUFFER[813]	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
#define idR0DE3DLDU	 334	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
#define R0DE3CLDU	 BUFFER[815]	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
#define idR0DE3CLDU	 335	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
#define TestDiagnDU	 BUFFER[817]	//( - , DU) Неисправность от
#define idTestDiagnDU	 336	//( - , DU) Неисправность от
#define B1IC01UDU	 BUFFER[819]	//( - , MDuS) Координата штока ББ2 (дел.энк)
#define idB1IC01UDU	 337	//( - , MDuS) Координата штока ББ2 (дел.энк)
#define B1VC01RDU	 BUFFER[824]	//( - , DU) Координата ББ2, мм
#define idB1VC01RDU	 338	//( - , DU) Координата ББ2, мм
#define B1IS11LDU	 BUFFER[829]	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
#define idB1IS11LDU	 339	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
#define A2IC01UDU	 BUFFER[831]	//( - , MDuS) Координата штока РБ1 (дел.энк)
#define idA2IC01UDU	 340	//( - , MDuS) Координата штока РБ1 (дел.энк)
#define B2IC01UDU	 BUFFER[836]	//( - , MDuS) Координата штока РБ2 (дел.энк)
#define idB2IC01UDU	 341	//( - , MDuS) Координата штока РБ2 (дел.энк)
#define A3EE03LDU	 BUFFER[841]	//( - , DU) ВПИС ИС1
#define idA3EE03LDU	 342	//( - , DU) ВПИС ИС1
#define B3EE03LDU	 BUFFER[843]	//( - , DU) ВПИС ИС2
#define idB3EE03LDU	 343	//( - , DU) ВПИС ИС2
#define B3AB15LDU	 BUFFER[845]	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
#define idB3AB15LDU	 344	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
#define R5IS21LDU	 BUFFER[847]	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	 345	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
#define R5VS22LDU	 BUFFER[849]	//( - , DU) Движение ворот отстойной зоны к закрыты
#define idR5VS22LDU	 346	//( - , DU) Движение ворот отстойной зоны к закрыты
#define R5VS12LDU	 BUFFER[851]	//( - , DU) Движение ворот отстойной зоны к открыты
#define idR5VS12LDU	 347	//( - , DU) Движение ворот отстойной зоны к открыты
#define R5VS01IDU	 BUFFER[853]	//( - , DU) Готовность к управлению ворот отстойной зоны
#define idR5VS01IDU	 348	//( - , DU) Готовность к управлению ворот отстойной зоны
#define R3VS22LDU	 BUFFER[856]	//( - , DU) Движение гомогенных дверей к закрыты
#define idR3VS22LDU	 349	//( - , DU) Движение гомогенных дверей к закрыты
#define R3VS12LDU	 BUFFER[858]	//( - , DU) Движение гомогенных дверей к открыты
#define idR3VS12LDU	 350	//( - , DU) Движение гомогенных дверей к открыты
#define R3VS01IDU	 BUFFER[860]	//( - , DU) Готовность к управлению гомогенных дверей
#define idR3VS01IDU	 351	//( - , DU) Готовность к управлению гомогенных дверей
#define A3AB13LDU	 BUFFER[863]	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
#define idA3AB13LDU	 352	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
#define B3AB13LDU	 BUFFER[865]	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define idB3AB13LDU	 353	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define R0DE02LDU	 BUFFER[867]	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
#define idR0DE02LDU	 354	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
#define R0DE03LDU	 BUFFER[870]	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
#define idR0DE03LDU	 355	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
#define R0DE04LDU	 BUFFER[873]	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
#define idR0DE04LDU	 356	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
#define R0DE08LDU	 BUFFER[876]	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
#define idR0DE08LDU	 357	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
#define R0DE05LDU	 BUFFER[879]	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
#define idR0DE05LDU	 358	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
#define R0DE09LDU	 BUFFER[882]	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
#define idR0DE09LDU	 359	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
#define R0DE0ALDU	 BUFFER[885]	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
#define idR0DE0ALDU	 360	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
#define R0DE07LDU	 BUFFER[888]	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
#define idR0DE07LDU	 361	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
#define R0DE0CLDU	 BUFFER[891]	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
#define idR0DE0CLDU	 362	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
#define R0DE0BLDU	 BUFFER[894]	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
#define idR0DE0BLDU	 363	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
#define R0DE0DLDU	 BUFFER[897]	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
#define idR0DE0DLDU	 364	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
#define R4IS11LDU	 BUFFER[900]	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
#define idR4IS11LDU	 365	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
#define A6AB06LDU	 BUFFER[902]	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
#define idA6AB06LDU	 366	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
#define A6AB07LDU	 BUFFER[904]	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
#define idA6AB07LDU	 367	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
#define A6AB08LDU	 BUFFER[906]	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
#define idA6AB08LDU	 368	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
#define A6AB09LDU	 BUFFER[908]	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
#define idA6AB09LDU	 369	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
#define B6AB06LDU	 BUFFER[910]	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
#define idB6AB06LDU	 370	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
#define B6AB07LDU	 BUFFER[912]	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
#define idB6AB07LDU	 371	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
#define B6AB08LDU	 BUFFER[914]	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
#define idB6AB08LDU	 372	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
#define B6AB09LDU	 BUFFER[916]	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
#define idB6AB09LDU	 373	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
#define A6AB05LDU	 BUFFER[918]	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
#define idA6AB05LDU	 374	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
#define B8VS12LDU	 BUFFER[920]	//( - , DU) Движение АЗ2 в сторону ВУ
#define idB8VS12LDU	 375	//( - , DU) Движение АЗ2 в сторону ВУ
#define B8CV01RDU	 BUFFER[922]	//( - , DU) Измеренная скорость перемещения АЗ2
#define idB8CV01RDU	 376	//( - , DU) Измеренная скорость перемещения АЗ2
#define B8AB06LDU	 BUFFER[927]	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
#define idB8AB06LDU	 377	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
#define B8AB07LDU	 BUFFER[929]	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
#define idB8AB07LDU	 378	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
#define B8AB05LDU	 BUFFER[931]	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
#define idB8AB05LDU	 379	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
#define B8VS22LDU	 BUFFER[933]	//( - , DU) Движение АЗ2 в сторону НУ
#define idB8VS22LDU	 380	//( - , DU) Движение АЗ2 в сторону НУ
#define B8AZ03LDU	 BUFFER[935]	//( - , DU) Несанкционированное перемещение АЗ2
#define idB8AZ03LDU	 381	//( - , DU) Несанкционированное перемещение АЗ2
#define R0MD11LP1	 BUFFER[937]	//( - , DU) Кнопка ПУСК
#define idR0MD11LP1	 382	//( - , DU) Кнопка ПУСК
#define B8AD10LDU	 BUFFER[939]	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
#define idB8AD10LDU	 383	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
#define B8AD20LDU	 BUFFER[941]	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
#define idB8AD20LDU	 384	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
#define B8IS11LDU	 BUFFER[943]	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
#define idB8IS11LDU	 385	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
#define B8AB01LDU	 BUFFER[945]	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
#define idB8AB01LDU	 386	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
#define B5IS21LDU	 BUFFER[947]	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
#define idB5IS21LDU	 387	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
#define A5AZ03LDU	 BUFFER[949]	//( - , DU) Несанкционированное перемещение НЛ1
#define idA5AZ03LDU	 388	//( - , DU) Несанкционированное перемещение НЛ1
#define A5AB01LDU	 BUFFER[951]	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
#define idA5AB01LDU	 389	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
#define A5AB02LDU	 BUFFER[953]	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
#define idA5AB02LDU	 390	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
#define B5AZ03LDU	 BUFFER[955]	//( - , DU) Несанкционированное перемещение НЛ2
#define idB5AZ03LDU	 391	//( - , DU) Несанкционированное перемещение НЛ2
#define B5AB01LDU	 BUFFER[957]	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
#define idB5AB01LDU	 392	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
#define B5AB02LDU	 BUFFER[959]	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
#define idB5AB02LDU	 393	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
#define A4IS21LDU	 BUFFER[961]	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
#define idA4IS21LDU	 394	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
#define B4IS21LDU	 BUFFER[963]	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
#define idB4IS21LDU	 395	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
#define B4AD10LDU	 BUFFER[965]	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
#define idB4AD10LDU	 396	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
#define A4AD10LDU	 BUFFER[967]	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
#define idA4AD10LDU	 397	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
#define A4AZ03LDU	 BUFFER[969]	//( - , DU) Несанкционированное перемещение НИ1
#define idA4AZ03LDU	 398	//( - , DU) Несанкционированное перемещение НИ1
#define A4AB01LDU	 BUFFER[971]	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
#define idA4AB01LDU	 399	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
#define A4AB02LDU	 BUFFER[973]	//( - , DU) Блокировка движения НИ1 - Нет перемещения
#define idA4AB02LDU	 400	//( - , DU) Блокировка движения НИ1 - Нет перемещения
#define B4AZ03LDU	 BUFFER[975]	//( - , DU) Несанкционированное перемещение НИ2
#define idB4AZ03LDU	 401	//( - , DU) Несанкционированное перемещение НИ2
#define B4AB01LDU	 BUFFER[977]	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
#define idB4AB01LDU	 402	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
#define B4AB02LDU	 BUFFER[979]	//( - , DU) Блокировка движения НИ2 - Нет перемещения
#define idB4AB02LDU	 403	//( - , DU) Блокировка движения НИ2 - Нет перемещения
#define A5AB04LDU	 BUFFER[981]	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
#define idA5AB04LDU	 404	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
#define B5AB04LDU	 BUFFER[983]	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
#define idB5AB04LDU	 405	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
#define A1IS12LDU	 BUFFER[985]	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
#define idA1IS12LDU	 406	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
#define A2IS12LDU	 BUFFER[987]	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
#define idA2IS12LDU	 407	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
#define B1IS12LDU	 BUFFER[989]	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
#define idB1IS12LDU	 408	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
#define B2IS12LDU	 BUFFER[991]	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
#define idB2IS12LDU	 409	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
#define A8AB09LDU	 BUFFER[993]	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
#define idA8AB09LDU	 410	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
#define A8AB10LDU	 BUFFER[995]	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
#define idA8AB10LDU	 411	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
#define A8AB11LDU	 BUFFER[997]	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
#define idA8AB11LDU	 412	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
#define A8AB12LDU	 BUFFER[999]	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
#define idA8AB12LDU	 413	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
#define A8AB13LDU	 BUFFER[1001]	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
#define idA8AB13LDU	 414	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
#define A8AB14LDU	 BUFFER[1003]	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
#define idA8AB14LDU	 415	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
#define A8AB02LDU	 BUFFER[1005]	//( - , DU) Блокировка движения ДС2- АНИ не установлен
#define idA8AB02LDU	 416	//( - , DU) Блокировка движения ДС2- АНИ не установлен
#define A8AB01LDU	 BUFFER[1007]	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
#define idA8AB01LDU	 417	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
#define A2VS11LDU	 BUFFER[1009]	//( - , DU) Движение РБ1 в сторону ВУ
#define idA2VS11LDU	 418	//( - , DU) Движение РБ1 в сторону ВУ
#define A2CV01RDU	 BUFFER[1011]	//( - , DU) Измеренная скорость перемещения РБ1
#define idA2CV01RDU	 419	//( - , DU) Измеренная скорость перемещения РБ1
#define A2AB04LDU	 BUFFER[1016]	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
#define idA2AB04LDU	 420	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
#define A2AB02LDU	 BUFFER[1018]	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
#define idA2AB02LDU	 421	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
#define A2AB01LDU	 BUFFER[1020]	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
#define idA2AB01LDU	 422	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
#define A2VS21LDU	 BUFFER[1022]	//( - , DU) Движение РБ1 в сторону НУ
#define idA2VS21LDU	 423	//( - , DU) Движение РБ1 в сторону НУ
#define A2AZ03LDU	 BUFFER[1024]	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
#define idA2AZ03LDU	 424	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
#define A2AD11LDU	 BUFFER[1026]	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	 425	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
#define A2AD21LDU	 BUFFER[1028]	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	 426	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
#define A2AD02LDU	 BUFFER[1030]	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
#define idA2AD02LDU	 427	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
#define A2AD03LDU	 BUFFER[1032]	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
#define idA2AD03LDU	 428	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
#define A2AD04LDU	 BUFFER[1034]	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
#define idA2AD04LDU	 429	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
#define A2AD05LDU	 BUFFER[1036]	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
#define idA2AD05LDU	 430	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
#define A2AB07LDU	 BUFFER[1038]	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
#define idA2AB07LDU	 431	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
#define A2AB08LDU	 BUFFER[1040]	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
#define idA2AB08LDU	 432	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
#define B8AB04LDU	 BUFFER[1042]	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
#define idB8AB04LDU	 433	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
#define B8AB08LDU	 BUFFER[1044]	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
#define idB8AB08LDU	 434	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
#define B8AB09LDU	 BUFFER[1046]	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
#define idB8AB09LDU	 435	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
#define B8AB10LDU	 BUFFER[1048]	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
#define idB8AB10LDU	 436	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
#define B8AB11LDU	 BUFFER[1050]	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
#define idB8AB11LDU	 437	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
#define B8AB12LDU	 BUFFER[1052]	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
#define idB8AB12LDU	 438	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
#define B8AB13LDU	 BUFFER[1054]	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
#define idB8AB13LDU	 439	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
#define B8AB14LDU	 BUFFER[1056]	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
#define idB8AB14LDU	 440	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
#define B8AB02LDU	 BUFFER[1058]	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
#define idB8AB02LDU	 441	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
#define A8VS12LDU	 BUFFER[1060]	//( - , DU) Движение ДС2 в сторону ВУ
#define idA8VS12LDU	 442	//( - , DU) Движение ДС2 в сторону ВУ
#define A8CV01RDU	 BUFFER[1062]	//( - , DU) Измеренная скорость перемещения ДС2
#define idA8CV01RDU	 443	//( - , DU) Измеренная скорость перемещения ДС2
#define A8AB06LDU	 BUFFER[1067]	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
#define idA8AB06LDU	 444	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
#define A8AB07LDU	 BUFFER[1069]	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
#define idA8AB07LDU	 445	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
#define A8AB05LDU	 BUFFER[1071]	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
#define idA8AB05LDU	 446	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
#define A8VS22LDU	 BUFFER[1073]	//( - , DU) Движение ДС2 в сторону НУ
#define idA8VS22LDU	 447	//( - , DU) Движение ДС2 в сторону НУ
#define A8AZ03LDU	 BUFFER[1075]	//( - , DU) Несанкционированное перемещение ДС2
#define idA8AZ03LDU	 448	//( - , DU) Несанкционированное перемещение ДС2
#define A8AD10LDU	 BUFFER[1077]	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
#define idA8AD10LDU	 449	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
#define A8AD20LDU	 BUFFER[1079]	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
#define idA8AD20LDU	 450	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
#define B8IS22LDU	 BUFFER[1081]	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
#define idB8IS22LDU	 451	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
#define A8IS12LDU	 BUFFER[1083]	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
#define idA8IS12LDU	 452	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
#define A8AB04LDU	 BUFFER[1085]	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
#define idA8AB04LDU	 453	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
#define A8IS22LDU	 BUFFER[1087]	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
#define idA8IS22LDU	 454	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
#define A8AB08LDU	 BUFFER[1089]	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define idA8AB08LDU	 455	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define B6IS21LDU	 BUFFER[1091]	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
#define idB6IS21LDU	 456	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
#define A6VS22LDU	 BUFFER[1093]	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
#define idA6VS22LDU	 457	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
#define A6VS12LDU	 BUFFER[1095]	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
#define idA6VS12LDU	 458	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
#define B6VS22LDU	 BUFFER[1097]	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
#define idB6VS22LDU	 459	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
#define B6VS12LDU	 BUFFER[1099]	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
#define idB6VS12LDU	 460	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
#define A6AD10LDU	 BUFFER[1101]	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
#define idA6AD10LDU	 461	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
#define A6AD20LDU	 BUFFER[1103]	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
#define idA6AD20LDU	 462	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
#define B6AD10LDU	 BUFFER[1105]	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
#define idB6AD10LDU	 463	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
#define B6AD20LDU	 BUFFER[1107]	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
#define idB6AD20LDU	 464	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
#define A6AZ03LDU	 BUFFER[1109]	//( - , DU) Несанкционированное перемещение БЗ1
#define idA6AZ03LDU	 465	//( - , DU) Несанкционированное перемещение БЗ1
#define A6AB01LDU	 BUFFER[1111]	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
#define idA6AB01LDU	 466	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
#define A6AB02LDU	 BUFFER[1113]	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
#define idA6AB02LDU	 467	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
#define B6AZ03LDU	 BUFFER[1115]	//( - , DU) Несанкционированное перемещение БЗ2
#define idB6AZ03LDU	 468	//( - , DU) Несанкционированное перемещение БЗ2
#define B6AB01LDU	 BUFFER[1117]	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
#define idB6AB01LDU	 469	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
#define B6AB02LDU	 BUFFER[1119]	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
#define idB6AB02LDU	 470	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
#define A6AB04LDU	 BUFFER[1121]	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
#define idA6AB04LDU	 471	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
#define B6AB04LDU	 BUFFER[1123]	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
#define idB6AB04LDU	 472	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
#define R4AB01LDU	 BUFFER[1125]	//( - , DU) Блокировка движения тележки - АНИ не установлен
#define idR4AB01LDU	 473	//( - , DU) Блокировка движения тележки - АНИ не установлен
#define R8IS11LDU	 BUFFER[1127]	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
#define idR8IS11LDU	 474	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
#define R6IS21LDU	 BUFFER[1129]	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
#define idR6IS21LDU	 475	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
#define A0VN71LZ2	 BUFFER[1131]	//( - , MDuBz2) АЗ по АС мощности для АЗ1
#define idA0VN71LZ2	 476	//( - , MDuBz2) АЗ по АС мощности для АЗ1
#define A0VN71LZ1	 BUFFER[1133]	//( - , MDuBz1) АЗ по АС мощности для АЗ1
#define idA0VN71LZ1	 477	//( - , MDuBz1) АЗ по АС мощности для АЗ1
#define R0MW15IP1	 BUFFER[1135]	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
#define idR0MW15IP1	 478	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
#define R0MW14IP1	 BUFFER[1138]	//( - , DU) Переключатель ПРОГРАММЫ
#define idR0MW14IP1	 479	//( - , DU) Переключатель ПРОГРАММЫ
#define R0MW12IP1	 BUFFER[1141]	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
#define idR0MW12IP1	 480	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
#define R0MW13IP1	 BUFFER[1144]	//( - , DU) Переключатель ВЫБОР ЗОН
#define idR0MW13IP1	 481	//( - , DU) Переключатель ВЫБОР ЗОН
#define R0MW16IP1	 BUFFER[1147]	//( - , DU) Переключатель ВИД ПРОВЕРКИ
#define idR0MW16IP1	 482	//( - , DU) Переключатель ВИД ПРОВЕРКИ
#define R0MW11IP1	 BUFFER[1150]	//( - , DU) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	 483	//( - , DU) Переключатель ВЫСТРЕЛ
#define R0MW11IP2	 BUFFER[1153]	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
#define idR0MW11IP2	 484	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
#define R0MW13LP2	 BUFFER[1156]	//( - , DU) Переключатель СЕТЬ
#define idR0MW13LP2	 485	//( - , DU) Переключатель СЕТЬ
#define R0MD32LP1	 BUFFER[1158]	//( - , DU) Кнопка СПУСК
#define idR0MD32LP1	 486	//( - , DU) Кнопка СПУСК
#define R0MD31LP1	 BUFFER[1160]	//( - , DU) Кнопка СТОП
#define idR0MD31LP1	 487	//( - , DU) Кнопка СТОП
#define A1IS21LDU	 BUFFER[1162]	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
#define idA1IS21LDU	 488	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
#define A2IS21LDU	 BUFFER[1164]	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
#define idA2IS21LDU	 489	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
#define A3IS21LDU	 BUFFER[1166]	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
#define idA3IS21LDU	 490	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
#define B1IS21LDU	 BUFFER[1168]	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
#define idB1IS21LDU	 491	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
#define B2IS21LDU	 BUFFER[1170]	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
#define idB2IS21LDU	 492	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
#define B3IS21LDU	 BUFFER[1172]	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
#define idB3IS21LDU	 493	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
#define R0ES01LDU	 BUFFER[1174]	//( - , DU) ОРР не в исходном состоянии
#define idR0ES01LDU	 494	//( - , DU) ОРР не в исходном состоянии
#define R4MD11LP2	 BUFFER[1176]	//( - , DU) Кнопка ВПЕРЁД  (тележки)
#define idR4MD11LP2	 495	//( - , DU) Кнопка ВПЕРЁД  (тележки)
#define R4MD31LP2	 BUFFER[1178]	//( - , DU) Кнопка СТОП  (тележки)
#define idR4MD31LP2	 496	//( - , DU) Кнопка СТОП  (тележки)
#define R4MD21LP2	 BUFFER[1180]	//( - , DU) Кнопка НАЗАД  (тележки)
#define idR4MD21LP2	 497	//( - , DU) Кнопка НАЗАД  (тележки)
#define A6IS11LDU	 BUFFER[1182]	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
#define idA6IS11LDU	 498	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
#define A6IS21LDU	 BUFFER[1184]	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
#define idA6IS21LDU	 499	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
#define B6IS11LDU	 BUFFER[1186]	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
#define idB6IS11LDU	 500	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
#define R4AB12LDU	 BUFFER[1188]	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
#define idR4AB12LDU	 501	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
#define A4IS11LDU	 BUFFER[1190]	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
#define idA4IS11LDU	 502	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
#define B4IS11LDU	 BUFFER[1192]	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
#define idB4IS11LDU	 503	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
#define R4AB13LDU	 BUFFER[1194]	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
#define idR4AB13LDU	 504	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
#define R4AB14LDU	 BUFFER[1196]	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
#define idR4AB14LDU	 505	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
#define R4AB15LDU	 BUFFER[1198]	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
#define idR4AB15LDU	 506	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
#define R5IS11LDU	 BUFFER[1200]	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	 507	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
#define R4AB16LDU	 BUFFER[1202]	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
#define idR4AB16LDU	 508	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
#define R4AB17LDU	 BUFFER[1204]	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define idR4AB17LDU	 509	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define R4AB18LDU	 BUFFER[1206]	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define idR4AB18LDU	 510	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define R4AD10LDU	 BUFFER[1208]	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
#define idR4AD10LDU	 511	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
#define R4AD20LDU	 BUFFER[1210]	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
#define idR4AD20LDU	 512	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
#define A5VS22LDU	 BUFFER[1212]	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
#define idA5VS22LDU	 513	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
#define A5VS12LDU	 BUFFER[1214]	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
#define idA5VS12LDU	 514	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
#define B5VS22LDU	 BUFFER[1216]	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
#define idB5VS22LDU	 515	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
#define B5VS12LDU	 BUFFER[1218]	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
#define idB5VS12LDU	 516	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
#define B5AD10LDU	 BUFFER[1220]	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
#define idB5AD10LDU	 517	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
#define B5AD20LDU	 BUFFER[1222]	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
#define idB5AD20LDU	 518	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
#define A5AD10LDU	 BUFFER[1224]	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
#define idA5AD10LDU	 519	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
#define A5AD20LDU	 BUFFER[1226]	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
#define idA5AD20LDU	 520	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
#define A5IS11LDU	 BUFFER[1228]	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
#define idA5IS11LDU	 521	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
#define A5IS21LDU	 BUFFER[1230]	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
#define idA5IS21LDU	 522	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
#define B5IS11LDU	 BUFFER[1232]	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
#define idB5IS11LDU	 523	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
#define R0NE01LDU	 BUFFER[1234]	//( - , DU) Потеря связи с БАЗ1
#define idR0NE01LDU	 524	//( - , DU) Потеря связи с БАЗ1
#define R0NE02LDU	 BUFFER[1236]	//( - , DU) Потеря связи с БАЗ2
#define idR0NE02LDU	 525	//( - , DU) Потеря связи с БАЗ2
#define R4AB02LDU	 BUFFER[1238]	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
#define idR4AB02LDU	 526	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
#define R0NE08LDU	 BUFFER[1240]	//( - , DU) Потеря связи с ОПУ
#define idR0NE08LDU	 527	//( - , DU) Потеря связи с ОПУ
#define R4IS21LDU	 BUFFER[1242]	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
#define idR4IS21LDU	 528	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
#define R4IS22LDU	 BUFFER[1244]	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
#define idR4IS22LDU	 529	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
#define R4IS12LDU	 BUFFER[1246]	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
#define idR4IS12LDU	 530	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
#define R4VS22LDU	 BUFFER[1248]	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
#define idR4VS22LDU	 531	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
#define R4VS12LDU	 BUFFER[1250]	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
#define idR4VS12LDU	 532	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
#define R4AZ03LDU	 BUFFER[1252]	//( - , DU) Несанкционированное перемещение тележки
#define idR4AZ03LDU	 533	//( - , DU) Несанкционированное перемещение тележки
#define R4AB03LDU	 BUFFER[1254]	//( - , DU) Блокировка движения тележки - Самоход любого механизма
#define idR4AB03LDU	 534	//( - , DU) Блокировка движения тележки - Самоход любого механизма
#define R1IS21LDU	 BUFFER[1256]	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
#define idR1IS21LDU	 535	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
#define R2IS21LDU	 BUFFER[1258]	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
#define idR2IS21LDU	 536	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
#define R4AB04LDU	 BUFFER[1260]	//( - , DU) Блокировка движения тележки - Превышение времени движения
#define idR4AB04LDU	 537	//( - , DU) Блокировка движения тележки - Превышение времени движения
#define R4AB05LDU	 BUFFER[1262]	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
#define idR4AB05LDU	 538	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
#define R4AB06LDU	 BUFFER[1264]	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
#define idR4AB06LDU	 539	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
#define R4AB07LDU	 BUFFER[1266]	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
#define idR4AB07LDU	 540	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
#define R4AB08LDU	 BUFFER[1268]	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define idR4AB08LDU	 541	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define R4AB09LDU	 BUFFER[1270]	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
#define idR4AB09LDU	 542	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
#define B0VN71LZ1	 BUFFER[1272]	//( - , MDuBz1) АЗ по АС мощности для АЗ2
#define idB0VN71LZ1	 543	//( - , MDuBz1) АЗ по АС мощности для АЗ2
#define B0VN71LZ2	 BUFFER[1274]	//( - , MDuBz2) АЗ по АС мощности для АЗ2
#define idB0VN71LZ2	 544	//( - , MDuBz2) АЗ по АС мощности для АЗ2
#define R4AB10LDU	 BUFFER[1276]	//( - , DU) Блокировка тележки - не открыта биологическая защита
#define idR4AB10LDU	 545	//( - , DU) Блокировка тележки - не открыта биологическая защита
#define R4AB11LDU	 BUFFER[1278]	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
#define idR4AB11LDU	 546	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
#define A3AZ03LDU	 BUFFER[1280]	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
#define idA3AZ03LDU	 547	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
#define A3AD11LDU	 BUFFER[1282]	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	 548	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
#define A3AD21LDU	 BUFFER[1284]	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	 549	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
#define A3AD02LDU	 BUFFER[1286]	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
#define idA3AD02LDU	 550	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
#define A3AD03LDU	 BUFFER[1288]	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
#define idA3AD03LDU	 551	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
#define A3AD04LDU	 BUFFER[1290]	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
#define idA3AD04LDU	 552	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
#define A3AD05LDU	 BUFFER[1292]	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
#define idA3AD05LDU	 553	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
#define A3AD01LDU	 BUFFER[1294]	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
#define idA3AD01LDU	 554	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
#define A3CV02RDU	 BUFFER[1296]	//( - , DU) Заданная скорость перемещения ИС1
#define idA3CV02RDU	 555	//( - , DU) Заданная скорость перемещения ИС1
#define A3AB07LDU	 BUFFER[1301]	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
#define idA3AB07LDU	 556	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
#define A3AB08LDU	 BUFFER[1303]	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
#define idA3AB08LDU	 557	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
#define A3AB05LDU	 BUFFER[1305]	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
#define idA3AB05LDU	 558	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
#define A3AB06LDU	 BUFFER[1307]	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
#define idA3AB06LDU	 559	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
#define A3AB09LDU	 BUFFER[1309]	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
#define idA3AB09LDU	 560	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
#define A3AB10LDU	 BUFFER[1311]	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
#define idA3AB10LDU	 561	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
#define A3AB11LDU	 BUFFER[1313]	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
#define idA3AB11LDU	 562	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
#define A3AB12LDU	 BUFFER[1315]	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA3AB12LDU	 563	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A3AB14LDU	 BUFFER[1317]	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
#define idA3AB14LDU	 564	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
#define A3AB16LDU	 BUFFER[1319]	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
#define idA3AB16LDU	 565	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
#define A3AB17LDU	 BUFFER[1321]	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
#define idA3AB17LDU	 566	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
#define A3AB18LDU	 BUFFER[1323]	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
#define idA3AB18LDU	 567	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
#define A3AB20LDU	 BUFFER[1325]	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
#define idA3AB20LDU	 568	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
#define B1AD04LDU	 BUFFER[1327]	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
#define idB1AD04LDU	 569	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
#define B1AD05LDU	 BUFFER[1329]	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
#define idB1AD05LDU	 570	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
#define B1AD01LDU	 BUFFER[1331]	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
#define idB1AD01LDU	 571	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
#define B1CV02RDU	 BUFFER[1333]	//( - , DU) Заданная скорость перемещения ББ2
#define idB1CV02RDU	 572	//( - , DU) Заданная скорость перемещения ББ2
#define B1AB07LDU	 BUFFER[1338]	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
#define idB1AB07LDU	 573	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
#define B1AB08LDU	 BUFFER[1340]	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
#define idB1AB08LDU	 574	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
#define B1AB05LDU	 BUFFER[1342]	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
#define idB1AB05LDU	 575	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
#define B1AB06LDU	 BUFFER[1344]	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
#define idB1AB06LDU	 576	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
#define B1AB09LDU	 BUFFER[1346]	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
#define idB1AB09LDU	 577	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
#define B1AB10LDU	 BUFFER[1348]	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
#define idB1AB10LDU	 578	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
#define B1AB11LDU	 BUFFER[1350]	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
#define idB1AB11LDU	 579	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
#define B1AB12LDU	 BUFFER[1352]	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idB1AB12LDU	 580	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define B1AB13LDU	 BUFFER[1354]	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
#define idB1AB13LDU	 581	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
#define B1AB14LDU	 BUFFER[1356]	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
#define idB1AB14LDU	 582	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
#define B1AB16LDU	 BUFFER[1358]	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
#define idB1AB16LDU	 583	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
#define B1AB17LDU	 BUFFER[1360]	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
#define idB1AB17LDU	 584	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
#define B1AB18LDU	 BUFFER[1362]	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
#define idB1AB18LDU	 585	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
#define A3VS12LDU	 BUFFER[1364]	//( - , DU) Движение ИС1 в сторону ВУ
#define idA3VS12LDU	 586	//( - , DU) Движение ИС1 в сторону ВУ
#define A3CV01RDU	 BUFFER[1366]	//( - , DU) Измеренная скорость перемещения ИС1
#define idA3CV01RDU	 587	//( - , DU) Измеренная скорость перемещения ИС1
#define A3AB04LDU	 BUFFER[1371]	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
#define idA3AB04LDU	 588	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
#define A3AB02LDU	 BUFFER[1373]	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
#define idA3AB02LDU	 589	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
#define A3AB01LDU	 BUFFER[1375]	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
#define idA3AB01LDU	 590	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
#define A3VS22LDU	 BUFFER[1377]	//( - , DU) Движение ИС1 в сторону НУ
#define idA3VS22LDU	 591	//( - , DU) Движение ИС1 в сторону НУ
#define B3AB14LDU	 BUFFER[1379]	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
#define idB3AB14LDU	 592	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
#define B3AB16LDU	 BUFFER[1381]	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
#define idB3AB16LDU	 593	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
#define B3AB17LDU	 BUFFER[1383]	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
#define idB3AB17LDU	 594	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
#define B3AB18LDU	 BUFFER[1385]	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
#define idB3AB18LDU	 595	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
#define B3AB20LDU	 BUFFER[1387]	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
#define idB3AB20LDU	 596	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
#define C1MD31LP1	 BUFFER[1389]	//( - , DU) Кнопка СБРОС ББ
#define idC1MD31LP1	 597	//( - , DU) Кнопка СБРОС ББ
#define C1MD31LP2	 BUFFER[1391]	//( - , DU) Кнопка СБРОС ББ
#define idC1MD31LP2	 598	//( - , DU) Кнопка СБРОС ББ
#define A2AD31LDU	 BUFFER[1393]	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
#define idA2AD31LDU	 599	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
#define B2AD31LDU	 BUFFER[1395]	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
#define idB2AD31LDU	 600	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
#define A1AD31LDU	 BUFFER[1397]	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
#define idA1AD31LDU	 601	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
#define B1AD31LDU	 BUFFER[1399]	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
#define idB1AD31LDU	 602	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
#define A2AD32LDU	 BUFFER[1401]	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
#define idA2AD32LDU	 603	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
#define B2AD32LDU	 BUFFER[1403]	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
#define idB2AD32LDU	 604	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
#define A1AD32LDU	 BUFFER[1405]	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
#define idA1AD32LDU	 605	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
#define B1AD32LDU	 BUFFER[1407]	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
#define idB1AD32LDU	 606	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
#define R0MD11LP2	 BUFFER[1409]	//( - , DU) Кнопка Пуск проверки схем сброса
#define idR0MD11LP2	 607	//( - , DU) Кнопка Пуск проверки схем сброса
#define R0VX01LDU	 BUFFER[1411]	//( - , DU) ДО ИМПУЛЬСА
#define idR0VX01LDU	 608	//( - , DU) ДО ИМПУЛЬСА
#define R0VL01IDU	 BUFFER[1413]	//( - , DU) До импульса минут
#define idR0VL01IDU	 609	//( - , DU) До импульса минут
#define R0VL11IDU	 BUFFER[1416]	//( - , DU) До импульса секунд
#define idR0VL11IDU	 610	//( - , DU) До импульса секунд
#define R0VL06RDU	 BUFFER[1419]	//( - , DU) Индикация (Время задержки от ВУ РБ)
#define idR0VL06RDU	 611	//( - , DU) Индикация (Время задержки от ВУ РБ)
#define B3AD33LDU	 BUFFER[1424]	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define idB3AD33LDU	 612	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define B3IS11LDU	 BUFFER[1426]	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
#define idB3IS11LDU	 613	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
#define R0VL02RDU	 BUFFER[1428]	//( - , DU) Индикация (Время задержки ИНИ)
#define idR0VL02RDU	 614	//( - , DU) Индикация (Время задержки ИНИ)
#define B3VS12LDU	 BUFFER[1433]	//( - , DU) Движение ИС2 в сторону ВУ
#define idB3VS12LDU	 615	//( - , DU) Движение ИС2 в сторону ВУ
#define B3CV01RDU	 BUFFER[1435]	//( - , DU) Измеренная скорость перемещения ИС2
#define idB3CV01RDU	 616	//( - , DU) Измеренная скорость перемещения ИС2
#define B3AB04LDU	 BUFFER[1440]	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
#define idB3AB04LDU	 617	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
#define B3AB02LDU	 BUFFER[1442]	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
#define idB3AB02LDU	 618	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
#define B3AB01LDU	 BUFFER[1444]	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
#define idB3AB01LDU	 619	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
#define B3VS22LDU	 BUFFER[1446]	//( - , DU) Движение ИС2 в сторону НУ
#define idB3VS22LDU	 620	//( - , DU) Движение ИС2 в сторону НУ
#define B3AZ03LDU	 BUFFER[1448]	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
#define idB3AZ03LDU	 621	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
#define B3AD11LDU	 BUFFER[1450]	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	 622	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
#define B3AD21LDU	 BUFFER[1452]	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	 623	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
#define B3AD02LDU	 BUFFER[1454]	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
#define idB3AD02LDU	 624	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
#define B3AD03LDU	 BUFFER[1456]	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
#define idB3AD03LDU	 625	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
#define B3AD04LDU	 BUFFER[1458]	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
#define idB3AD04LDU	 626	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
#define B3AD05LDU	 BUFFER[1460]	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
#define idB3AD05LDU	 627	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
#define B3AD01LDU	 BUFFER[1462]	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
#define idB3AD01LDU	 628	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
#define B3CV02RDU	 BUFFER[1464]	//( - , DU) Заданная скорость перемещения ИС2
#define idB3CV02RDU	 629	//( - , DU) Заданная скорость перемещения ИС2
#define B3AB07LDU	 BUFFER[1469]	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
#define idB3AB07LDU	 630	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
#define B3AB08LDU	 BUFFER[1471]	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
#define idB3AB08LDU	 631	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
#define B3AB05LDU	 BUFFER[1473]	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
#define idB3AB05LDU	 632	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
#define B3AB06LDU	 BUFFER[1475]	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
#define idB3AB06LDU	 633	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
#define B3AB09LDU	 BUFFER[1477]	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
#define idB3AB09LDU	 634	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
#define B3AB10LDU	 BUFFER[1479]	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
#define idB3AB10LDU	 635	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
#define B3AB11LDU	 BUFFER[1481]	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
#define idB3AB11LDU	 636	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
#define B3AB12LDU	 BUFFER[1483]	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define idB3AB12LDU	 637	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define B2AD01LDU	 BUFFER[1485]	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
#define idB2AD01LDU	 638	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
#define B2CV02RDU	 BUFFER[1487]	//( - , DU) Заданная скорость перемещения РБ2
#define idB2CV02RDU	 639	//( - , DU) Заданная скорость перемещения РБ2
#define B2AB07LDU	 BUFFER[1492]	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
#define idB2AB07LDU	 640	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
#define B2AB08LDU	 BUFFER[1494]	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
#define idB2AB08LDU	 641	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
#define B2AB05LDU	 BUFFER[1496]	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
#define idB2AB05LDU	 642	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
#define B2AB06LDU	 BUFFER[1498]	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
#define idB2AB06LDU	 643	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
#define B2AB09LDU	 BUFFER[1500]	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
#define idB2AB09LDU	 644	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
#define B2AB10LDU	 BUFFER[1502]	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
#define idB2AB10LDU	 645	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
#define B2AB11LDU	 BUFFER[1504]	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
#define idB2AB11LDU	 646	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
#define B2AB12LDU	 BUFFER[1506]	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define idB2AB12LDU	 647	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define B2AB13LDU	 BUFFER[1508]	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
#define idB2AB13LDU	 648	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
#define B2AB14LDU	 BUFFER[1510]	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
#define idB2AB14LDU	 649	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
#define B2AB16LDU	 BUFFER[1512]	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
#define idB2AB16LDU	 650	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
#define B2AB17LDU	 BUFFER[1514]	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
#define idB2AB17LDU	 651	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
#define R1AZ03LDU	 BUFFER[1516]	//( - , DU) Несанкционированное перемещение МДЗ1
#define idR1AZ03LDU	 652	//( - , DU) Несанкционированное перемещение МДЗ1
#define R1AB01LDU	 BUFFER[1518]	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
#define idR1AB01LDU	 653	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
#define R1AB02LDU	 BUFFER[1520]	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
#define idR1AB02LDU	 654	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
#define R2AZ03LDU	 BUFFER[1522]	//( - , DU) Несанкционированное перемещение МДЗ2
#define idR2AZ03LDU	 655	//( - , DU) Несанкционированное перемещение МДЗ2
#define R2AB01LDU	 BUFFER[1524]	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
#define idR2AB01LDU	 656	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
#define R2AB02LDU	 BUFFER[1526]	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
#define idR2AB02LDU	 657	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
#define R1AB04LDU	 BUFFER[1528]	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
#define idR1AB04LDU	 658	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
#define R2AB04LDU	 BUFFER[1530]	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
#define idR2AB04LDU	 659	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
#define R1AD10LDU	 BUFFER[1532]	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
#define idR1AD10LDU	 660	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
#define A2AB05LDU	 BUFFER[1534]	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
#define idA2AB05LDU	 661	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
#define A2AB06LDU	 BUFFER[1536]	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
#define idA2AB06LDU	 662	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
#define A2AB09LDU	 BUFFER[1538]	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
#define idA2AB09LDU	 663	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
#define A2AB10LDU	 BUFFER[1540]	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
#define idA2AB10LDU	 664	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
#define A2AB11LDU	 BUFFER[1542]	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
#define idA2AB11LDU	 665	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
#define A2AB12LDU	 BUFFER[1544]	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA2AB12LDU	 666	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A2AB13LDU	 BUFFER[1546]	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
#define idA2AB13LDU	 667	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
#define A2AB14LDU	 BUFFER[1548]	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
#define idA2AB14LDU	 668	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
#define A2AB16LDU	 BUFFER[1550]	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
#define idA2AB16LDU	 669	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
#define A2AB17LDU	 BUFFER[1552]	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
#define idA2AB17LDU	 670	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
#define A2AD01LDU	 BUFFER[1554]	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
#define idA2AD01LDU	 671	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
#define A2CV02RDU	 BUFFER[1556]	//( - , DU) Заданная скорость перемещения РБ1
#define idA2CV02RDU	 672	//( - , DU) Заданная скорость перемещения РБ1
#define B2CV01RDU	 BUFFER[1561]	//( - , DU) Измеренная скорость перемещения РБ2
#define idB2CV01RDU	 673	//( - , DU) Измеренная скорость перемещения РБ2
#define B2AB04LDU	 BUFFER[1566]	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
#define idB2AB04LDU	 674	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
#define B2AB02LDU	 BUFFER[1568]	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
#define idB2AB02LDU	 675	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
#define B2AB01LDU	 BUFFER[1570]	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
#define idB2AB01LDU	 676	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
#define B2AZ03LDU	 BUFFER[1572]	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
#define idB2AZ03LDU	 677	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
#define B2AD11LDU	 BUFFER[1574]	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	 678	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
#define B2AD21LDU	 BUFFER[1576]	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	 679	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
#define B2AD02LDU	 BUFFER[1578]	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
#define idB2AD02LDU	 680	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
#define B2AD03LDU	 BUFFER[1580]	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
#define idB2AD03LDU	 681	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
#define B2AD04LDU	 BUFFER[1582]	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
#define idB2AD04LDU	 682	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
#define B2AD05LDU	 BUFFER[1584]	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
#define idB2AD05LDU	 683	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
#define A1AB08LDU	 BUFFER[1586]	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
#define idA1AB08LDU	 684	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
#define A1AB05LDU	 BUFFER[1588]	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
#define idA1AB05LDU	 685	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
#define A1AB06LDU	 BUFFER[1590]	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
#define idA1AB06LDU	 686	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
#define A1AB09LDU	 BUFFER[1592]	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
#define idA1AB09LDU	 687	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
#define A1AB10LDU	 BUFFER[1594]	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
#define idA1AB10LDU	 688	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
#define A1AB11LDU	 BUFFER[1596]	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
#define idA1AB11LDU	 689	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
#define A1AB12LDU	 BUFFER[1598]	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA1AB12LDU	 690	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A1AB13LDU	 BUFFER[1600]	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
#define idA1AB13LDU	 691	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
#define A1AB14LDU	 BUFFER[1602]	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
#define idA1AB14LDU	 692	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
#define A1AB16LDU	 BUFFER[1604]	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
#define idA1AB16LDU	 693	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
#define A1AB17LDU	 BUFFER[1606]	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
#define idA1AB17LDU	 694	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
#define A1AB18LDU	 BUFFER[1608]	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
#define idA1AB18LDU	 695	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
#define B1VS12LDU	 BUFFER[1610]	//( - , DU) Движение ББ2 в сторону ВУ
#define idB1VS12LDU	 696	//( - , DU) Движение ББ2 в сторону ВУ
#define B1CV01RDU	 BUFFER[1612]	//( - , DU) Измеренная скорость перемещения ББ2
#define idB1CV01RDU	 697	//( - , DU) Измеренная скорость перемещения ББ2
#define B1AB04LDU	 BUFFER[1617]	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
#define idB1AB04LDU	 698	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
#define B1AB02LDU	 BUFFER[1619]	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
#define idB1AB02LDU	 699	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
#define B1AB01LDU	 BUFFER[1621]	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
#define idB1AB01LDU	 700	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
#define B1VS22LDU	 BUFFER[1623]	//( - , DU) Движение ББ2 в сторону НУ
#define idB1VS22LDU	 701	//( - , DU) Движение ББ2 в сторону НУ
#define B1AZ03LDU	 BUFFER[1625]	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
#define idB1AZ03LDU	 702	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
#define B1AD11LDU	 BUFFER[1627]	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	 703	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
#define B1AD21LDU	 BUFFER[1629]	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	 704	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
#define B1AD02LDU	 BUFFER[1631]	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
#define idB1AD02LDU	 705	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
#define B1AD03LDU	 BUFFER[1633]	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
#define idB1AD03LDU	 706	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
#define R1AD20LDU	 BUFFER[1635]	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
#define idR1AD20LDU	 707	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
#define R1IS11LDU	 BUFFER[1637]	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
#define idR1IS11LDU	 708	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
#define R1VS22LDU	 BUFFER[1639]	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	 709	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
#define R2VS22LDU	 BUFFER[1641]	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	 710	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
#define R2VS12LDU	 BUFFER[1643]	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	 711	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
#define R1VS12LDU	 BUFFER[1645]	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	 712	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
#define R2IS11LDU	 BUFFER[1647]	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
#define idR2IS11LDU	 713	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
#define A1VS12LDU	 BUFFER[1649]	//( - , DU) Движение ББ1 в сторону ВУ
#define idA1VS12LDU	 714	//( - , DU) Движение ББ1 в сторону ВУ
#define A1CV01RDU	 BUFFER[1651]	//( - , DU) Измеренная скорость перемещения ББ1
#define idA1CV01RDU	 715	//( - , DU) Измеренная скорость перемещения ББ1
#define A1AB04LDU	 BUFFER[1656]	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
#define idA1AB04LDU	 716	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
#define A1AB02LDU	 BUFFER[1658]	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
#define idA1AB02LDU	 717	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
#define A1AB01LDU	 BUFFER[1660]	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
#define idA1AB01LDU	 718	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
#define A1VS22LDU	 BUFFER[1662]	//( - , DU) Движение ББ1 в сторону НУ
#define idA1VS22LDU	 719	//( - , DU) Движение ББ1 в сторону НУ
#define A1AZ03LDU	 BUFFER[1664]	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
#define idA1AZ03LDU	 720	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
#define A1AD11LDU	 BUFFER[1666]	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	 721	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
#define A1AD21LDU	 BUFFER[1668]	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	 722	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
#define A1AD02LDU	 BUFFER[1670]	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
#define idA1AD02LDU	 723	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
#define A1AD03LDU	 BUFFER[1672]	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
#define idA1AD03LDU	 724	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
#define A1AD04LDU	 BUFFER[1674]	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
#define idA1AD04LDU	 725	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
#define A1AD05LDU	 BUFFER[1676]	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
#define idA1AD05LDU	 726	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
#define A1AD01LDU	 BUFFER[1678]	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
#define idA1AD01LDU	 727	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
#define A1CV02RDU	 BUFFER[1680]	//( - , DU) Заданная скорость перемещения ББ1
#define idA1CV02RDU	 728	//( - , DU) Заданная скорость перемещения ББ1
#define A1AB07LDU	 BUFFER[1685]	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
#define idA1AB07LDU	 729	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
#define fEM_A1UC03RDU	 BUFFER[1687]	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define idfEM_A1UC03RDU	 730	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define dEM_A1UC05UDU	 BUFFER[1692]	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC05UDU	 731	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define dEM_A1UC06UDU	 BUFFER[1697]	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC06UDU	 732	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define dEM_A2UC06UDU	 BUFFER[1702]	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC06UDU	 733	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define dEM_A2UC05UDU	 BUFFER[1707]	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC05UDU	 734	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define fEM_A2UC03RDU	 BUFFER[1712]	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define idfEM_A2UC03RDU	 735	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define dEM_A3UC06UDU	 BUFFER[1717]	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC06UDU	 736	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define dEM_A3UC05UDU	 BUFFER[1722]	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC05UDU	 737	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define fEM_A3UC03RDU	 BUFFER[1727]	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define idfEM_A3UC03RDU	 738	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define dEM_A8UC06UDU	 BUFFER[1732]	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define iddEM_A8UC06UDU	 739	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define fEM_A8UC03RDU	 BUFFER[1737]	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
#define idfEM_A8UC03RDU	 740	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
#define dEM_A8UC05UDU	 BUFFER[1742]	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define iddEM_A8UC05UDU	 741	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define fEM_R0UV81RDU	 BUFFER[1747]	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	 742	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	 BUFFER[1752]	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	 743	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	 BUFFER[1757]	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	 744	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	 BUFFER[1762]	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	 745	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define fEM_R0UV86RDU	 BUFFER[1767]	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	 746	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV85RDU	 BUFFER[1772]	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	 747	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV87RDU	 BUFFER[1777]	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	 748	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_A3UP03RDU	 BUFFER[1782]	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	 749	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	 BUFFER[1787]	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	 750	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP43RDU	 BUFFER[1792]	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define idfEM_A3UP43RDU	 751	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define fEM_A3UP44RDU	 BUFFER[1797]	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP44RDU	 752	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP53RDU	 BUFFER[1802]	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP53RDU	 753	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP85RDU	 BUFFER[1807]	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP85RDU	 754	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP88RDU	 BUFFER[1812]	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP88RDU	 755	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP86RDU	 BUFFER[1817]	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP86RDU	 756	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_B8UV01RDU	 BUFFER[1822]	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
#define idfEM_B8UV01RDU	 757	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
#define fEM_B8UV02RDU	 BUFFER[1827]	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
#define idfEM_B8UV02RDU	 758	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
#define fEM_B8UV03RDU	 BUFFER[1832]	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
#define idfEM_B8UV03RDU	 759	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
#define fEM_B8UL04RDU	 BUFFER[1837]	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
#define idfEM_B8UL04RDU	 760	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
#define iEM_A2UV03CDU	 BUFFER[1842]	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define idiEM_A2UV03CDU	 761	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define fEM_A2UV01RDU	 BUFFER[1845]	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define idfEM_A2UV01RDU	 762	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define fEM_A2UV02RDU	 BUFFER[1850]	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define idfEM_A2UV02RDU	 763	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define fEM_A1UV01RDU	 BUFFER[1855]	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define idfEM_A1UV01RDU	 764	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define fEM_A1UV02RDU	 BUFFER[1860]	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define idfEM_A1UV02RDU	 765	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define fEM_A1UC06RDU	 BUFFER[1865]	//(A1UC06RDU) Уставка определения самохода ББ  мм
#define idfEM_A1UC06RDU	 766	//(A1UC06RDU) Уставка определения самохода ББ  мм
#define fEM_A1UC05RDU	 BUFFER[1870]	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A1UC05RDU	 767	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A1UL04RDU	 BUFFER[1875]	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define idfEM_A1UL04RDU	 768	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define fEM_A3UV01RDU	 BUFFER[1880]	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
#define idfEM_A3UV01RDU	 769	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
#define fEM_A3UV02RDU	 BUFFER[1885]	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
#define idfEM_A3UV02RDU	 770	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
#define fEM_A3UC06RDU	 BUFFER[1890]	//(A3UC06RDU) Уставка определения самохода ИС1  мм
#define idfEM_A3UC06RDU	 771	//(A3UC06RDU) Уставка определения самохода ИС1  мм
#define fEM_A3UC05RDU	 BUFFER[1895]	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A3UC05RDU	 772	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define fEM_A3UL04RDU	 BUFFER[1900]	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define idfEM_A3UL04RDU	 773	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define fEM_A3UP54RDU	 BUFFER[1905]	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define idfEM_A3UP54RDU	 774	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define fEM_A3UP87RDU	 BUFFER[1910]	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP87RDU	 775	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_R0UL05RDU	 BUFFER[1915]	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
#define idfEM_R0UL05RDU	 776	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
#define fEM_R0UL20RDU	 BUFFER[1920]	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
#define idfEM_R0UL20RDU	 777	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
#define fEM_B8UV04RDU	 BUFFER[1925]	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
#define idfEM_B8UV04RDU	 778	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
#define fEM_B8UC06RDU	 BUFFER[1930]	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
#define idfEM_B8UC06RDU	 779	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
#define fEM_B8UC05RDU	 BUFFER[1935]	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
#define idfEM_B8UC05RDU	 780	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
#define fEM_A2UL05RDU	 BUFFER[1940]	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define idfEM_A2UL05RDU	 781	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define fEM_A2UL03RDU	 BUFFER[1945]	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL03RDU	 782	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A2UC06RDU	 BUFFER[1950]	//(A2UC06RDU) Уставка определения самохода РБ  мм
#define idfEM_A2UC06RDU	 783	//(A2UC06RDU) Уставка определения самохода РБ  мм
#define fEM_A2UC05RDU	 BUFFER[1955]	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A2UC05RDU	 784	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A2UL04RDU	 BUFFER[1960]	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define idfEM_A2UL04RDU	 785	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define fEM_A1UL03RDU	 BUFFER[1965]	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define idfEM_A1UL03RDU	 786	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define fEM_A1UL05RDU	 BUFFER[1970]	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define idfEM_A1UL05RDU	 787	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define fEM_A3UL03RDU	 BUFFER[1975]	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define idfEM_A3UL03RDU	 788	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define fEM_A3UL05RDU	 BUFFER[1980]	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define idfEM_A3UL05RDU	 789	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define fEM_A1UC08RDU	 BUFFER[1985]	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define idfEM_A1UC08RDU	 790	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define fEM_A3UC08RDU	 BUFFER[1990]	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define idfEM_A3UC08RDU	 791	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define fEM_A1UC07RDU	 BUFFER[1995]	//(A1UC07RDU) Зона возврата при наведении ББ мм
#define idfEM_A1UC07RDU	 792	//(A1UC07RDU) Зона возврата при наведении ББ мм
#define fEM_A1UL01RDU	 BUFFER[2000]	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A1UL01RDU	 793	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A3UC07RDU	 BUFFER[2005]	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define idfEM_A3UC07RDU	 794	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define fEM_A3UL01RDU	 BUFFER[2010]	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A3UL01RDU	 795	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A2UC08RDU	 BUFFER[2015]	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define idfEM_A2UC08RDU	 796	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define fEM_A2UC07RDU	 BUFFER[2020]	//(A2UC07RDU) Зона возврата при наведении РБ  мм
#define idfEM_A2UC07RDU	 797	//(A2UC07RDU) Зона возврата при наведении РБ  мм
#define fEM_A2UL01RDU	 BUFFER[2025]	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A2UL01RDU	 798	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_B8UC01RDU	 BUFFER[2030]	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
#define idfEM_B8UC01RDU	 799	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
#define fEM_B8UL07RDU	 BUFFER[2035]	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
#define idfEM_B8UL07RDU	 800	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
#define fEM_B8UC02RDU	 BUFFER[2040]	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
#define idfEM_B8UC02RDU	 801	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
#define fEM_B8UL01RDU	 BUFFER[2045]	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_B8UL01RDU	 802	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_B8UL05RDU	 BUFFER[2050]	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
#define idfEM_B8UL05RDU	 803	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
#define fEM_B8UL03RDU	 BUFFER[2055]	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
#define idfEM_B8UL03RDU	 804	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
#define fEM_B8UL06RDU	 BUFFER[2060]	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
#define idfEM_B8UL06RDU	 805	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
#define fEM_A9UZ03RDU	 BUFFER[2065]	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
#define idfEM_A9UZ03RDU	 806	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
#define fEM_A9UZ04RDU	 BUFFER[2070]	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
#define idfEM_A9UZ04RDU	 807	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
#define fEM_A9UZ05RDU	 BUFFER[2075]	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
#define idfEM_A9UZ05RDU	 808	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
#define fEM_R4UZ04RDU	 BUFFER[2080]	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define idfEM_R4UZ04RDU	 809	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define fEM_R4UZ03RDU	 BUFFER[2085]	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define idfEM_R4UZ03RDU	 810	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define fEM_R4UZ05RDU	 BUFFER[2090]	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define idfEM_R4UZ05RDU	 811	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define fEM_A5UZ03RDU	 BUFFER[2095]	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
#define idfEM_A5UZ03RDU	 812	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
#define fEM_A5UZ04RDU	 BUFFER[2100]	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
#define idfEM_A5UZ04RDU	 813	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
#define fEM_A5UZ05RDU	 BUFFER[2105]	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
#define idfEM_A5UZ05RDU	 814	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
#define fEM_A4UZ03RDU	 BUFFER[2110]	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
#define idfEM_A4UZ03RDU	 815	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
#define fEM_A4UZ04RDU	 BUFFER[2115]	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
#define idfEM_A4UZ04RDU	 816	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
#define fEM_A4UZ05RDU	 BUFFER[2120]	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
#define idfEM_A4UZ05RDU	 817	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
#define fEM_A6UZ03RDU	 BUFFER[2125]	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
#define idfEM_A6UZ03RDU	 818	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
#define fEM_A6UZ04RDU	 BUFFER[2130]	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
#define idfEM_A6UZ04RDU	 819	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
#define fEM_A6UZ05RDU	 BUFFER[2135]	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
#define idfEM_A6UZ05RDU	 820	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
#define fEM_R1UZ03RDU	 BUFFER[2140]	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define idfEM_R1UZ03RDU	 821	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define fEM_R1UZ04RDU	 BUFFER[2145]	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define idfEM_R1UZ04RDU	 822	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define fEM_R1UZ05RDU	 BUFFER[2150]	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define idfEM_R1UZ05RDU	 823	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define fEM_R0UL04RDU	 BUFFER[2155]	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
#define idfEM_R0UL04RDU	 824	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
#define fEM_R0UL06RDU	 BUFFER[2160]	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
#define idfEM_R0UL06RDU	 825	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
#define fEM_R0UL03RDU	 BUFFER[2165]	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
#define idfEM_R0UL03RDU	 826	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
#define fEM_R0UL17RDU	 BUFFER[2170]	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
#define idfEM_R0UL17RDU	 827	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
#define fEM_R0UL19RDU	 BUFFER[2175]	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define idfEM_R0UL19RDU	 828	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define fEM_R0UL07RDU	 BUFFER[2180]	//(R0UL07RDU) Время срабатывания верхней АС II УР
#define idfEM_R0UL07RDU	 829	//(R0UL07RDU) Время срабатывания верхней АС II УР
#define fEM_R0UL18RDU	 BUFFER[2185]	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
#define idfEM_R0UL18RDU	 830	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
#define fEM_R0UL16RDU	 BUFFER[2190]	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
#define idfEM_R0UL16RDU	 831	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
#define fEM_R0UL02RDU	 BUFFER[2195]	//(R0UL02RDU) Время задержки  ИНИ
#define idfEM_R0UL02RDU	 832	//(R0UL02RDU) Время задержки  ИНИ
#define fEM_R0UN08RDU	 BUFFER[2200]	//(R0UN08RDU) 8-я заданная мощность
#define idfEM_R0UN08RDU	 833	//(R0UN08RDU) 8-я заданная мощность
#define fEM_R0UN07RDU	 BUFFER[2205]	//(R0UN07RDU) 7-я заданная мощность
#define idfEM_R0UN07RDU	 834	//(R0UN07RDU) 7-я заданная мощность
#define fEM_R0UN06RDU	 BUFFER[2210]	//(R0UN06RDU) 6-я заданная мощность
#define idfEM_R0UN06RDU	 835	//(R0UN06RDU) 6-я заданная мощность
#define fEM_R0UN05RDU	 BUFFER[2215]	//(R0UN05RDU) 5-я заданная мощность
#define idfEM_R0UN05RDU	 836	//(R0UN05RDU) 5-я заданная мощность
#define fEM_R0UN04RDU	 BUFFER[2220]	//(R0UN04RDU) 4-я заданная мощность
#define idfEM_R0UN04RDU	 837	//(R0UN04RDU) 4-я заданная мощность
#define fEM_R0UN03RDU	 BUFFER[2225]	//(R0UN03RDU) Ограничение 3 по мощности
#define idfEM_R0UN03RDU	 838	//(R0UN03RDU) Ограничение 3 по мощности
#define fEM_R0UN02RDU	 BUFFER[2230]	//(R0UN02RDU) 2-я заданная мощность
#define idfEM_R0UN02RDU	 839	//(R0UN02RDU) 2-я заданная мощность
#define fEM_R0UN01RDU	 BUFFER[2235]	//(R0UN01RDU) 1-я заданная мощность
#define idfEM_R0UN01RDU	 840	//(R0UN01RDU) 1-я заданная мощность
#define fEM_A2UC82RDU	 BUFFER[2240]	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC82RDU	 841	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define fEM_A2UC83RDU	 BUFFER[2245]	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define idfEM_A2UC83RDU	 842	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define fEM_A1UC83RDU	 BUFFER[2250]	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define idfEM_A1UC83RDU	 843	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define fEM_A2UC81RDU	 BUFFER[2255]	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC81RDU	 844	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define fEM_A1UC81RDU	 BUFFER[2260]	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC81RDU	 845	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define fEM_A1UC82RDU	 BUFFER[2265]	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC82RDU	 846	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define fEM_A2UL83RDU	 BUFFER[2270]	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL83RDU	 847	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A3UC81RDU	 BUFFER[2275]	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define idfEM_A3UC81RDU	 848	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define fEM_A3UC82RDU	 BUFFER[2280]	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define idfEM_A3UC82RDU	 849	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define fEM_R0UN80RDU	 BUFFER[2285]	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define idfEM_R0UN80RDU	 850	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define iEM_A2UV01IDU	 BUFFER[2290]	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV01IDU	 851	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define iEM_A2UV02IDU	 BUFFER[2293]	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV02IDU	 852	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define iEM_A1UV01IDU	 BUFFER[2296]	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV01IDU	 853	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define iEM_A1UV02IDU	 BUFFER[2299]	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV02IDU	 854	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define iEM_A1UV03IDU	 BUFFER[2302]	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define idiEM_A1UV03IDU	 855	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define iEM_A3UV01IDU	 BUFFER[2305]	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define idiEM_A3UV01IDU	 856	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define iEM_A3UV02IDU	 BUFFER[2308]	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define idiEM_A3UV02IDU	 857	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define lEM_R0MD01LC1	 BUFFER[2311]	//(R0MD01LC1) Ручное управление ОРР
#define idlEM_R0MD01LC1	 858	//(R0MD01LC1) Ручное управление ОРР
#define fEM_A3UC09RDU	 BUFFER[2313]	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC09RDU	 859	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define fEM_A2UC02RDU	 BUFFER[2318]	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define idfEM_A2UC02RDU	 860	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define fEM_A1UC02RDU	 BUFFER[2323]	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define idfEM_A1UC02RDU	 861	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define fEM_A3UC02RDU	 BUFFER[2328]	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define idfEM_A3UC02RDU	 862	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define fEM_R0UL21RDU	 BUFFER[2333]	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
#define idfEM_R0UL21RDU	 863	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
#define fEM_R0UN09RDU	 BUFFER[2338]	//(R0UN09RDU) Минимальный период при регулировании мощности
#define idfEM_R0UN09RDU	 864	//(R0UN09RDU) Минимальный период при регулировании мощности
#define fEM_R0UN11RDU	 BUFFER[2343]	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
#define idfEM_R0UN11RDU	 865	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
#define fEM_R0UN12RDU	 BUFFER[2348]	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
#define idfEM_R0UN12RDU	 866	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
#define fEM_R0UN13RDU	 BUFFER[2353]	//(R0UN13RDU) Минимальное изменение координаты, мм
#define idfEM_R0UN13RDU	 867	//(R0UN13RDU) Минимальное изменение координаты, мм
#define fEM_R0UN14RDU	 BUFFER[2358]	//(R0UN14RDU) Максимальная координата штока ИМ, мм
#define idfEM_R0UN14RDU	 868	//(R0UN14RDU) Максимальная координата штока ИМ, мм
#define fEM_R0UN16RDU	 BUFFER[2363]	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN16RDU	 869	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN17RDU	 BUFFER[2368]	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN17RDU	 870	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN18RDU	 BUFFER[2373]	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
#define idfEM_R0UN18RDU	 871	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
#define fEM_R0UN19RDU	 BUFFER[2378]	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define idfEM_R0UN19RDU	 872	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define fEM_R0UN70LDU	 BUFFER[2383]	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN70LDU	 873	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN71LDU	 BUFFER[2388]	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN71LDU	 874	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN72LDU	 BUFFER[2393]	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN72LDU	 875	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN73LDU	 BUFFER[2398]	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN73LDU	 876	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN74LDU	 BUFFER[2403]	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN74LDU	 877	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN75LDU	 BUFFER[2408]	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN75LDU	 878	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN80LDU	 BUFFER[2413]	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN80LDU	 879	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define fEM_R0UN81LDU	 BUFFER[2418]	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN81LDU	 880	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define fEM_R0UN82LDU	 BUFFER[2423]	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN82LDU	 881	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define fEM_R0UN83LDU	 BUFFER[2428]	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN83LDU	 882	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define fEM_R0UN84LDU	 BUFFER[2433]	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN84LDU	 883	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define fEM_R0UN85LDU	 BUFFER[2438]	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN85LDU	 884	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define fEM_R0UT20RDU	 BUFFER[2443]	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define idfEM_R0UT20RDU	 885	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define fEM_R0UN25RDU	 BUFFER[2448]	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
#define idfEM_R0UN25RDU	 886	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
#define fEM_R0UN15RDU	 BUFFER[2453]	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
#define idfEM_R0UN15RDU	 887	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
#define fEM_R0UN26RDU	 BUFFER[2458]	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
#define idfEM_R0UN26RDU	 888	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
#define fEM_R0UN27RDU	 BUFFER[2463]	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
#define idfEM_R0UN27RDU	 889	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
#define fEM_R0UN24RDU	 BUFFER[2468]	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN24RDU	 890	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
#define fEM_R0UL25RDU	 BUFFER[2473]	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define idfEM_R0UL25RDU	 891	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define bFirstEnterFlag	 BUFFER[2478]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 892	//(bFirstEnterFlag) 
#define internal2_m182_y0	 BUFFER[2480]	//(internal2_m182_y0) y0
#define idinternal2_m182_y0	 893	//(internal2_m182_y0) y0
#define internal2_m180_y0	 BUFFER[2485]	//(internal2_m180_y0) y0
#define idinternal2_m180_y0	 894	//(internal2_m180_y0) y0
#define internal2_m215_y0	 BUFFER[2490]	//(internal2_m215_y0) state
#define idinternal2_m215_y0	 895	//(internal2_m215_y0) state
#define internal2_m207_y0	 BUFFER[2492]	//(internal2_m207_y0) state
#define idinternal2_m207_y0	 896	//(internal2_m207_y0) state
#define internal2_m196_y1	 BUFFER[2494]	//(internal2_m196_y1) y1 - внутренний параметр
#define idinternal2_m196_y1	 897	//(internal2_m196_y1) y1 - внутренний параметр
#define internal2_m203_y1	 BUFFER[2496]	//(internal2_m203_y1) y1 - внутренний параметр
#define idinternal2_m203_y1	 898	//(internal2_m203_y1) y1 - внутренний параметр
#define internal2_m185_y1	 BUFFER[2498]	//(internal2_m185_y1) y1 - внутренний параметр
#define idinternal2_m185_y1	 899	//(internal2_m185_y1) y1 - внутренний параметр
#define internal2_m193_y1	 BUFFER[2500]	//(internal2_m193_y1) y1 - внутренний параметр
#define idinternal2_m193_y1	 900	//(internal2_m193_y1) y1 - внутренний параметр
#define internal2_m17_Nk0	 BUFFER[2502]	//(internal2_m17_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m17_Nk0	 901	//(internal2_m17_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m17_SetFlag	 BUFFER[2507]	//(internal2_m17_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m17_SetFlag	 902	//(internal2_m17_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m110_Nk0	 BUFFER[2509]	//(internal2_m110_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m110_Nk0	 903	//(internal2_m110_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m110_SetFlag	 BUFFER[2514]	//(internal2_m110_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m110_SetFlag	 904	//(internal2_m110_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m106_Nk0	 BUFFER[2516]	//(internal2_m106_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m106_Nk0	 905	//(internal2_m106_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m106_SetFlag	 BUFFER[2521]	//(internal2_m106_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m106_SetFlag	 906	//(internal2_m106_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m79_Nk0	 BUFFER[2523]	//(internal2_m79_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m79_Nk0	 907	//(internal2_m79_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m79_SetFlag	 BUFFER[2528]	//(internal2_m79_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m79_SetFlag	 908	//(internal2_m79_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m83_Nk0	 BUFFER[2530]	//(internal2_m83_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m83_Nk0	 909	//(internal2_m83_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m83_SetFlag	 BUFFER[2535]	//(internal2_m83_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m83_SetFlag	 910	//(internal2_m83_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m45_Nk0	 BUFFER[2537]	//(internal2_m45_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m45_Nk0	 911	//(internal2_m45_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m45_SetFlag	 BUFFER[2542]	//(internal2_m45_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m45_SetFlag	 912	//(internal2_m45_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m53_Nk0	 BUFFER[2544]	//(internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m53_Nk0	 913	//(internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m53_SetFlag	 BUFFER[2549]	//(internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m53_SetFlag	 914	//(internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m15_Nk0	 BUFFER[2551]	//(internal2_m15_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m15_Nk0	 915	//(internal2_m15_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m15_SetFlag	 BUFFER[2556]	//(internal2_m15_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m15_SetFlag	 916	//(internal2_m15_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal1_m1236_tx	 BUFFER[2558]	//(internal1_m1236_tx) tx - внутренний параметр
#define idinternal1_m1236_tx	 917	//(internal1_m1236_tx) tx - внутренний параметр
#define internal1_m1217_tx	 BUFFER[2563]	//(internal1_m1217_tx) tx - внутренний параметр
#define idinternal1_m1217_tx	 918	//(internal1_m1217_tx) tx - внутренний параметр
#define internal1_m1218_tx	 BUFFER[2568]	//(internal1_m1218_tx) tx - внутренний параметр
#define idinternal1_m1218_tx	 919	//(internal1_m1218_tx) tx - внутренний параметр
#define internal1_m1239_tx	 BUFFER[2573]	//(internal1_m1239_tx) tx - внутренний параметр
#define idinternal1_m1239_tx	 920	//(internal1_m1239_tx) tx - внутренний параметр
#define internal1_m824_tx	 BUFFER[2578]	//(internal1_m824_tx) tx - внутренний параметр
#define idinternal1_m824_tx	 921	//(internal1_m824_tx) tx - внутренний параметр
#define internal1_m832_tx	 BUFFER[2583]	//(internal1_m832_tx) tx - внутренний параметр
#define idinternal1_m832_tx	 922	//(internal1_m832_tx) tx - внутренний параметр
#define internal1_m823_tx	 BUFFER[2588]	//(internal1_m823_tx) tx - внутренний параметр
#define idinternal1_m823_tx	 923	//(internal1_m823_tx) tx - внутренний параметр
#define internal1_m822_tx	 BUFFER[2593]	//(internal1_m822_tx) tx - внутренний параметр
#define idinternal1_m822_tx	 924	//(internal1_m822_tx) tx - внутренний параметр
#define internal1_m1683_q0	 BUFFER[2598]	//(internal1_m1683_q0) q0 - внутренний параметр
#define idinternal1_m1683_q0	 925	//(internal1_m1683_q0) q0 - внутренний параметр
#define internal1_m2116_q0	 BUFFER[2600]	//(internal1_m2116_q0) q0 - внутренний параметр
#define idinternal1_m2116_q0	 926	//(internal1_m2116_q0) q0 - внутренний параметр
#define internal1_m2100_q0	 BUFFER[2602]	//(internal1_m2100_q0) q0 - внутренний параметр
#define idinternal1_m2100_q0	 927	//(internal1_m2100_q0) q0 - внутренний параметр
#define internal1_m2147_q0	 BUFFER[2604]	//(internal1_m2147_q0) q0 - внутренний параметр
#define idinternal1_m2147_q0	 928	//(internal1_m2147_q0) q0 - внутренний параметр
#define internal1_m2131_q0	 BUFFER[2606]	//(internal1_m2131_q0) q0 - внутренний параметр
#define idinternal1_m2131_q0	 929	//(internal1_m2131_q0) q0 - внутренний параметр
#define internal1_m2122_q0	 BUFFER[2608]	//(internal1_m2122_q0) q0 - внутренний параметр
#define idinternal1_m2122_q0	 930	//(internal1_m2122_q0) q0 - внутренний параметр
#define internal1_m2103_q0	 BUFFER[2610]	//(internal1_m2103_q0) q0 - внутренний параметр
#define idinternal1_m2103_q0	 931	//(internal1_m2103_q0) q0 - внутренний параметр
#define internal1_m2120_q0	 BUFFER[2612]	//(internal1_m2120_q0) q0 - внутренний параметр
#define idinternal1_m2120_q0	 932	//(internal1_m2120_q0) q0 - внутренний параметр
#define internal1_m2101_q0	 BUFFER[2614]	//(internal1_m2101_q0) q0 - внутренний параметр
#define idinternal1_m2101_q0	 933	//(internal1_m2101_q0) q0 - внутренний параметр
#define internal1_m2099_q0	 BUFFER[2616]	//(internal1_m2099_q0) q0 - внутренний параметр
#define idinternal1_m2099_q0	 934	//(internal1_m2099_q0) q0 - внутренний параметр
#define internal1_m2098_q0	 BUFFER[2618]	//(internal1_m2098_q0) q0 - внутренний параметр
#define idinternal1_m2098_q0	 935	//(internal1_m2098_q0) q0 - внутренний параметр
#define internal1_m2112_q0	 BUFFER[2620]	//(internal1_m2112_q0) q0 - внутренний параметр
#define idinternal1_m2112_q0	 936	//(internal1_m2112_q0) q0 - внутренний параметр
#define internal1_m2110_q0	 BUFFER[2622]	//(internal1_m2110_q0) q0 - внутренний параметр
#define idinternal1_m2110_q0	 937	//(internal1_m2110_q0) q0 - внутренний параметр
#define internal1_m2118_q0	 BUFFER[2624]	//(internal1_m2118_q0) q0 - внутренний параметр
#define idinternal1_m2118_q0	 938	//(internal1_m2118_q0) q0 - внутренний параметр
#define internal1_m2114_q0	 BUFFER[2626]	//(internal1_m2114_q0) q0 - внутренний параметр
#define idinternal1_m2114_q0	 939	//(internal1_m2114_q0) q0 - внутренний параметр
#define internal1_m2153_q0	 BUFFER[2628]	//(internal1_m2153_q0) q0 - внутренний параметр
#define idinternal1_m2153_q0	 940	//(internal1_m2153_q0) q0 - внутренний параметр
#define internal1_m2134_q0	 BUFFER[2630]	//(internal1_m2134_q0) q0 - внутренний параметр
#define idinternal1_m2134_q0	 941	//(internal1_m2134_q0) q0 - внутренний параметр
#define internal1_m2151_q0	 BUFFER[2632]	//(internal1_m2151_q0) q0 - внутренний параметр
#define idinternal1_m2151_q0	 942	//(internal1_m2151_q0) q0 - внутренний параметр
#define internal1_m2133_q0	 BUFFER[2634]	//(internal1_m2133_q0) q0 - внутренний параметр
#define idinternal1_m2133_q0	 943	//(internal1_m2133_q0) q0 - внутренний параметр
#define internal1_m2130_q0	 BUFFER[2636]	//(internal1_m2130_q0) q0 - внутренний параметр
#define idinternal1_m2130_q0	 944	//(internal1_m2130_q0) q0 - внутренний параметр
#define internal1_m2129_q0	 BUFFER[2638]	//(internal1_m2129_q0) q0 - внутренний параметр
#define idinternal1_m2129_q0	 945	//(internal1_m2129_q0) q0 - внутренний параметр
#define internal1_m2143_q0	 BUFFER[2640]	//(internal1_m2143_q0) q0 - внутренний параметр
#define idinternal1_m2143_q0	 946	//(internal1_m2143_q0) q0 - внутренний параметр
#define internal1_m2141_q0	 BUFFER[2642]	//(internal1_m2141_q0) q0 - внутренний параметр
#define idinternal1_m2141_q0	 947	//(internal1_m2141_q0) q0 - внутренний параметр
#define internal1_m2019_tx	 BUFFER[2644]	//(internal1_m2019_tx) tx - внутренний параметр
#define idinternal1_m2019_tx	 948	//(internal1_m2019_tx) tx - внутренний параметр
#define internal1_m1998_tx	 BUFFER[2649]	//(internal1_m1998_tx) tx - внутренний параметр
#define idinternal1_m1998_tx	 949	//(internal1_m1998_tx) tx - внутренний параметр
#define internal1_m1707_Pv0	 BUFFER[2654]	//(internal1_m1707_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1707_Pv0	 950	//(internal1_m1707_Pv0)  - Пер. выключатель механизма
#define internal1_m1707_Zv0	 BUFFER[2656]	//(internal1_m1707_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1707_Zv0	 951	//(internal1_m1707_Zv0)  - Зад. выключатель механизма
#define internal1_m1707_MyFirstEnterFlag	 BUFFER[2658]	//(internal1_m1707_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1707_MyFirstEnterFlag	 952	//(internal1_m1707_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m1704_Pv0	 BUFFER[2660]	//(internal1_m1704_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1704_Pv0	 953	//(internal1_m1704_Pv0)  - Пер. выключатель механизма
#define internal1_m1704_Zv0	 BUFFER[2662]	//(internal1_m1704_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1704_Zv0	 954	//(internal1_m1704_Zv0)  - Зад. выключатель механизма
#define internal1_m1704_MyFirstEnterFlag	 BUFFER[2664]	//(internal1_m1704_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1704_MyFirstEnterFlag	 955	//(internal1_m1704_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m2172_tx	 BUFFER[2666]	//(internal1_m2172_tx) tx - время накопленное сек
#define idinternal1_m2172_tx	 956	//(internal1_m2172_tx) tx - время накопленное сек
#define internal1_m2172_y0	 BUFFER[2671]	//(internal1_m2172_y0) y0
#define idinternal1_m2172_y0	 957	//(internal1_m2172_y0) y0
#define internal1_m2175_tx	 BUFFER[2672]	//(internal1_m2175_tx) tx - время накопленное сек
#define idinternal1_m2175_tx	 958	//(internal1_m2175_tx) tx - время накопленное сек
#define internal1_m2175_y0	 BUFFER[2677]	//(internal1_m2175_y0) y0
#define idinternal1_m2175_y0	 959	//(internal1_m2175_y0) y0
#define internal1_m2174_tx	 BUFFER[2678]	//(internal1_m2174_tx) tx - время накопленное сек
#define idinternal1_m2174_tx	 960	//(internal1_m2174_tx) tx - время накопленное сек
#define internal1_m2174_y0	 BUFFER[2683]	//(internal1_m2174_y0) y0
#define idinternal1_m2174_y0	 961	//(internal1_m2174_y0) y0
#define internal1_m2211_tx	 BUFFER[2684]	//(internal1_m2211_tx) tx - внутренний параметр
#define idinternal1_m2211_tx	 962	//(internal1_m2211_tx) tx - внутренний параметр
#define internal1_m2209_tx	 BUFFER[2689]	//(internal1_m2209_tx) tx - время накопленное сек
#define idinternal1_m2209_tx	 963	//(internal1_m2209_tx) tx - время накопленное сек
#define internal1_m2209_y0	 BUFFER[2694]	//(internal1_m2209_y0) y0
#define idinternal1_m2209_y0	 964	//(internal1_m2209_y0) y0
#define internal1_m2214_q0	 BUFFER[2695]	//(internal1_m2214_q0) q0 - внутренний параметр
#define idinternal1_m2214_q0	 965	//(internal1_m2214_q0) q0 - внутренний параметр
#define internal1_m2181_q0	 BUFFER[2697]	//(internal1_m2181_q0) q0 - внутренний параметр
#define idinternal1_m2181_q0	 966	//(internal1_m2181_q0) q0 - внутренний параметр
#define internal1_m2189_tx	 BUFFER[2699]	//(internal1_m2189_tx) tx - внутренний параметр
#define idinternal1_m2189_tx	 967	//(internal1_m2189_tx) tx - внутренний параметр
#define internal1_m2187_q0	 BUFFER[2704]	//(internal1_m2187_q0) q0 - внутренний параметр
#define idinternal1_m2187_q0	 968	//(internal1_m2187_q0) q0 - внутренний параметр
#define internal1_m2013_tx	 BUFFER[2706]	//(internal1_m2013_tx) tx - время накопленное сек
#define idinternal1_m2013_tx	 969	//(internal1_m2013_tx) tx - время накопленное сек
#define internal1_m2013_y0	 BUFFER[2711]	//(internal1_m2013_y0) y0
#define idinternal1_m2013_y0	 970	//(internal1_m2013_y0) y0
#define internal1_m2005_tx	 BUFFER[2712]	//(internal1_m2005_tx) tx - время накопленное сек
#define idinternal1_m2005_tx	 971	//(internal1_m2005_tx) tx - время накопленное сек
#define internal1_m2005_y0	 BUFFER[2717]	//(internal1_m2005_y0) y0
#define idinternal1_m2005_y0	 972	//(internal1_m2005_y0) y0
#define internal1_m1693_q0	 BUFFER[2718]	//(internal1_m1693_q0) q0 - внутренний параметр
#define idinternal1_m1693_q0	 973	//(internal1_m1693_q0) q0 - внутренний параметр
#define internal1_m1698_q0	 BUFFER[2720]	//(internal1_m1698_q0) q0 - внутренний параметр
#define idinternal1_m1698_q0	 974	//(internal1_m1698_q0) q0 - внутренний параметр
#define internal1_m1690_q0	 BUFFER[2722]	//(internal1_m1690_q0) q0 - внутренний параметр
#define idinternal1_m1690_q0	 975	//(internal1_m1690_q0) q0 - внутренний параметр
#define internal1_m1732_q0	 BUFFER[2724]	//(internal1_m1732_q0) q0 - внутренний параметр
#define idinternal1_m1732_q0	 976	//(internal1_m1732_q0) q0 - внутренний параметр
#define internal1_m741_tx	 BUFFER[2726]	//(internal1_m741_tx) tx - время накопленное сек
#define idinternal1_m741_tx	 977	//(internal1_m741_tx) tx - время накопленное сек
#define internal1_m741_y0	 BUFFER[2731]	//(internal1_m741_y0) y0
#define idinternal1_m741_y0	 978	//(internal1_m741_y0) y0
#define internal1_m2009_tx	 BUFFER[2732]	//(internal1_m2009_tx) tx - внутренний параметр
#define idinternal1_m2009_tx	 979	//(internal1_m2009_tx) tx - внутренний параметр
#define internal1_m2012_q0	 BUFFER[2737]	//(internal1_m2012_q0) q0 - внутренний параметр
#define idinternal1_m2012_q0	 980	//(internal1_m2012_q0) q0 - внутренний параметр
#define internal1_m2004_q0	 BUFFER[2739]	//(internal1_m2004_q0) q0 - внутренний параметр
#define idinternal1_m2004_q0	 981	//(internal1_m2004_q0) q0 - внутренний параметр
#define internal1_m1974_tx	 BUFFER[2741]	//(internal1_m1974_tx) tx - внутренний параметр
#define idinternal1_m1974_tx	 982	//(internal1_m1974_tx) tx - внутренний параметр
#define internal1_m1985_tx	 BUFFER[2746]	//(internal1_m1985_tx) tx - внутренний параметр
#define idinternal1_m1985_tx	 983	//(internal1_m1985_tx) tx - внутренний параметр
#define internal1_m1971_tx	 BUFFER[2751]	//(internal1_m1971_tx) tx - внутренний параметр
#define idinternal1_m1971_tx	 984	//(internal1_m1971_tx) tx - внутренний параметр
#define internal1_m1977_q0	 BUFFER[2756]	//(internal1_m1977_q0) q0 - внутренний параметр
#define idinternal1_m1977_q0	 985	//(internal1_m1977_q0) q0 - внутренний параметр
#define internal1_m1989_q0	 BUFFER[2758]	//(internal1_m1989_q0) q0 - внутренний параметр
#define idinternal1_m1989_q0	 986	//(internal1_m1989_q0) q0 - внутренний параметр
#define internal1_m1947_tx	 BUFFER[2760]	//(internal1_m1947_tx) tx - внутренний параметр
#define idinternal1_m1947_tx	 987	//(internal1_m1947_tx) tx - внутренний параметр
#define internal1_m51_tx	 BUFFER[2765]	//(internal1_m51_tx) tx - внутренний параметр
#define idinternal1_m51_tx	 988	//(internal1_m51_tx) tx - внутренний параметр
#define internal1_m338_tx	 BUFFER[2770]	//(internal1_m338_tx) tx - внутренний параметр
#define idinternal1_m338_tx	 989	//(internal1_m338_tx) tx - внутренний параметр
#define internal1_m291_tx	 BUFFER[2775]	//(internal1_m291_tx) tx - внутренний параметр
#define idinternal1_m291_tx	 990	//(internal1_m291_tx) tx - внутренний параметр
#define internal1_m742_tx	 BUFFER[2780]	//(internal1_m742_tx) tx - внутренний параметр
#define idinternal1_m742_tx	 991	//(internal1_m742_tx) tx - внутренний параметр
#define internal1_m1415_tx	 BUFFER[2785]	//(internal1_m1415_tx) tx - внутренний параметр
#define idinternal1_m1415_tx	 992	//(internal1_m1415_tx) tx - внутренний параметр
#define internal1_m113_tx	 BUFFER[2790]	//(internal1_m113_tx) tx - внутренний параметр
#define idinternal1_m113_tx	 993	//(internal1_m113_tx) tx - внутренний параметр
#define internal1_m115_tx	 BUFFER[2795]	//(internal1_m115_tx) tx - внутренний параметр
#define idinternal1_m115_tx	 994	//(internal1_m115_tx) tx - внутренний параметр
#define internal1_m120_tx	 BUFFER[2800]	//(internal1_m120_tx) tx - внутренний параметр
#define idinternal1_m120_tx	 995	//(internal1_m120_tx) tx - внутренний параметр
#define internal1_m21_tx	 BUFFER[2805]	//(internal1_m21_tx) tx - внутренний параметр
#define idinternal1_m21_tx	 996	//(internal1_m21_tx) tx - внутренний параметр
#define internal1_m13_tx	 BUFFER[2810]	//(internal1_m13_tx) tx - внутренний параметр
#define idinternal1_m13_tx	 997	//(internal1_m13_tx) tx - внутренний параметр
#define internal1_m1956_tx	 BUFFER[2815]	//(internal1_m1956_tx) tx - внутренний параметр
#define idinternal1_m1956_tx	 998	//(internal1_m1956_tx) tx - внутренний параметр
#define internal1_m1944_tx	 BUFFER[2820]	//(internal1_m1944_tx) tx - внутренний параметр
#define idinternal1_m1944_tx	 999	//(internal1_m1944_tx) tx - внутренний параметр
#define internal1_m2052_tx	 BUFFER[2825]	//(internal1_m2052_tx) tx - внутренний параметр
#define idinternal1_m2052_tx	 1000	//(internal1_m2052_tx) tx - внутренний параметр
#define internal1_m2056_tx	 BUFFER[2830]	//(internal1_m2056_tx) tx - внутренний параметр
#define idinternal1_m2056_tx	 1001	//(internal1_m2056_tx) tx - внутренний параметр
#define internal1_m1869_tx	 BUFFER[2835]	//(internal1_m1869_tx) tx - внутренний параметр
#define idinternal1_m1869_tx	 1002	//(internal1_m1869_tx) tx - внутренний параметр
#define internal1_m77_tx	 BUFFER[2840]	//(internal1_m77_tx) tx - внутренний параметр
#define idinternal1_m77_tx	 1003	//(internal1_m77_tx) tx - внутренний параметр
#define internal1_m309_tx	 BUFFER[2845]	//(internal1_m309_tx) tx - время накопленное сек
#define idinternal1_m309_tx	 1004	//(internal1_m309_tx) tx - время накопленное сек
#define internal1_m309_y0	 BUFFER[2850]	//(internal1_m309_y0) y0
#define idinternal1_m309_y0	 1005	//(internal1_m309_y0) y0
#define internal1_m1863_tx	 BUFFER[2851]	//(internal1_m1863_tx) tx - время накопленное сек
#define idinternal1_m1863_tx	 1006	//(internal1_m1863_tx) tx - время накопленное сек
#define internal1_m1863_y0	 BUFFER[2856]	//(internal1_m1863_y0) y0
#define idinternal1_m1863_y0	 1007	//(internal1_m1863_y0) y0
#define internal1_m1861_tx	 BUFFER[2857]	//(internal1_m1861_tx) tx - время накопленное сек
#define idinternal1_m1861_tx	 1008	//(internal1_m1861_tx) tx - время накопленное сек
#define internal1_m1861_y0	 BUFFER[2862]	//(internal1_m1861_y0) y0
#define idinternal1_m1861_y0	 1009	//(internal1_m1861_y0) y0
#define internal1_m1850_tx	 BUFFER[2863]	//(internal1_m1850_tx) tx - время накопленное сек
#define idinternal1_m1850_tx	 1010	//(internal1_m1850_tx) tx - время накопленное сек
#define internal1_m1850_y0	 BUFFER[2868]	//(internal1_m1850_y0) y0
#define idinternal1_m1850_y0	 1011	//(internal1_m1850_y0) y0
#define internal1_m1870_q0	 BUFFER[2869]	//(internal1_m1870_q0) q0 - внутренний параметр
#define idinternal1_m1870_q0	 1012	//(internal1_m1870_q0) q0 - внутренний параметр
#define internal1_m1435_q0	 BUFFER[2874]	//(internal1_m1435_q0) q0 - внутренний параметр
#define idinternal1_m1435_q0	 1013	//(internal1_m1435_q0) q0 - внутренний параметр
#define internal1_m1474_q0	 BUFFER[2879]	//(internal1_m1474_q0) q0 - внутренний параметр
#define idinternal1_m1474_q0	 1014	//(internal1_m1474_q0) q0 - внутренний параметр
#define internal1_m1469_q0	 BUFFER[2884]	//(internal1_m1469_q0) q0 - внутренний параметр
#define idinternal1_m1469_q0	 1015	//(internal1_m1469_q0) q0 - внутренний параметр
#define internal1_m1909_q0	 BUFFER[2889]	//(internal1_m1909_q0) q0 - внутренний параметр
#define idinternal1_m1909_q0	 1016	//(internal1_m1909_q0) q0 - внутренний параметр
#define internal1_m1886_tx	 BUFFER[2894]	//(internal1_m1886_tx) tx - время накопленное сек
#define idinternal1_m1886_tx	 1017	//(internal1_m1886_tx) tx - время накопленное сек
#define internal1_m1886_y0	 BUFFER[2899]	//(internal1_m1886_y0) y0
#define idinternal1_m1886_y0	 1018	//(internal1_m1886_y0) y0
#define internal1_m1902_tx	 BUFFER[2900]	//(internal1_m1902_tx) tx - время накопленное сек
#define idinternal1_m1902_tx	 1019	//(internal1_m1902_tx) tx - время накопленное сек
#define internal1_m1902_y0	 BUFFER[2905]	//(internal1_m1902_y0) y0
#define idinternal1_m1902_y0	 1020	//(internal1_m1902_y0) y0
#define internal1_m1899_tx	 BUFFER[2906]	//(internal1_m1899_tx) tx - время накопленное сек
#define idinternal1_m1899_tx	 1021	//(internal1_m1899_tx) tx - время накопленное сек
#define internal1_m1899_y0	 BUFFER[2911]	//(internal1_m1899_y0) y0
#define idinternal1_m1899_y0	 1022	//(internal1_m1899_y0) y0
#define internal1_m2034_tx	 BUFFER[2912]	//(internal1_m2034_tx) tx - время накопленное сек
#define idinternal1_m2034_tx	 1023	//(internal1_m2034_tx) tx - время накопленное сек
#define internal1_m2034_y0	 BUFFER[2917]	//(internal1_m2034_y0) y0
#define idinternal1_m2034_y0	 1024	//(internal1_m2034_y0) y0
#define internal1_m2046_tx	 BUFFER[2918]	//(internal1_m2046_tx) tx - время накопленное сек
#define idinternal1_m2046_tx	 1025	//(internal1_m2046_tx) tx - время накопленное сек
#define internal1_m2046_y0	 BUFFER[2923]	//(internal1_m2046_y0) y0
#define idinternal1_m2046_y0	 1026	//(internal1_m2046_y0) y0
#define internal1_m1800_tx	 BUFFER[2924]	//(internal1_m1800_tx) tx - время накопленное сек
#define idinternal1_m1800_tx	 1027	//(internal1_m1800_tx) tx - время накопленное сек
#define internal1_m1800_y0	 BUFFER[2929]	//(internal1_m1800_y0) y0
#define idinternal1_m1800_y0	 1028	//(internal1_m1800_y0) y0
#define internal1_m1799_tx	 BUFFER[2930]	//(internal1_m1799_tx) tx - время накопленное сек
#define idinternal1_m1799_tx	 1029	//(internal1_m1799_tx) tx - время накопленное сек
#define internal1_m1799_y0	 BUFFER[2935]	//(internal1_m1799_y0) y0
#define idinternal1_m1799_y0	 1030	//(internal1_m1799_y0) y0
#define internal1_m1798_tx	 BUFFER[2936]	//(internal1_m1798_tx) tx - время накопленное сек
#define idinternal1_m1798_tx	 1031	//(internal1_m1798_tx) tx - время накопленное сек
#define internal1_m1798_y0	 BUFFER[2941]	//(internal1_m1798_y0) y0
#define idinternal1_m1798_y0	 1032	//(internal1_m1798_y0) y0
#define internal1_m1797_tx	 BUFFER[2942]	//(internal1_m1797_tx) tx - время накопленное сек
#define idinternal1_m1797_tx	 1033	//(internal1_m1797_tx) tx - время накопленное сек
#define internal1_m1797_y0	 BUFFER[2947]	//(internal1_m1797_y0) y0
#define idinternal1_m1797_y0	 1034	//(internal1_m1797_y0) y0
#define internal1_m1487_tx	 BUFFER[2948]	//(internal1_m1487_tx) tx - время накопленное сек
#define idinternal1_m1487_tx	 1035	//(internal1_m1487_tx) tx - время накопленное сек
#define internal1_m1487_y0	 BUFFER[2953]	//(internal1_m1487_y0) y0
#define idinternal1_m1487_y0	 1036	//(internal1_m1487_y0) y0
#define internal1_m1481_tx	 BUFFER[2954]	//(internal1_m1481_tx) tx - время накопленное сек
#define idinternal1_m1481_tx	 1037	//(internal1_m1481_tx) tx - время накопленное сек
#define internal1_m1481_y0	 BUFFER[2959]	//(internal1_m1481_y0) y0
#define idinternal1_m1481_y0	 1038	//(internal1_m1481_y0) y0
#define internal1_m1431_tx	 BUFFER[2960]	//(internal1_m1431_tx) tx - время накопленное сек
#define idinternal1_m1431_tx	 1039	//(internal1_m1431_tx) tx - время накопленное сек
#define internal1_m1431_y0	 BUFFER[2965]	//(internal1_m1431_y0) y0
#define idinternal1_m1431_y0	 1040	//(internal1_m1431_y0) y0
#define internal1_m825_tx	 BUFFER[2966]	//(internal1_m825_tx) tx - время накопленное сек
#define idinternal1_m825_tx	 1041	//(internal1_m825_tx) tx - время накопленное сек
#define internal1_m825_y0	 BUFFER[2971]	//(internal1_m825_y0) y0
#define idinternal1_m825_y0	 1042	//(internal1_m825_y0) y0
#define internal1_m826_tx	 BUFFER[2972]	//(internal1_m826_tx) tx - время накопленное сек
#define idinternal1_m826_tx	 1043	//(internal1_m826_tx) tx - время накопленное сек
#define internal1_m826_y0	 BUFFER[2977]	//(internal1_m826_y0) y0
#define idinternal1_m826_y0	 1044	//(internal1_m826_y0) y0
#define internal1_m834_tx	 BUFFER[2978]	//(internal1_m834_tx) tx - время накопленное сек
#define idinternal1_m834_tx	 1045	//(internal1_m834_tx) tx - время накопленное сек
#define internal1_m834_y0	 BUFFER[2983]	//(internal1_m834_y0) y0
#define idinternal1_m834_y0	 1046	//(internal1_m834_y0) y0
#define internal1_m187_tx	 BUFFER[2984]	//(internal1_m187_tx) tx - время накопленное сек
#define idinternal1_m187_tx	 1047	//(internal1_m187_tx) tx - время накопленное сек
#define internal1_m187_y0	 BUFFER[2989]	//(internal1_m187_y0) y0
#define idinternal1_m187_y0	 1048	//(internal1_m187_y0) y0
#define internal1_m192_tx	 BUFFER[2990]	//(internal1_m192_tx) tx - время накопленное сек
#define idinternal1_m192_tx	 1049	//(internal1_m192_tx) tx - время накопленное сек
#define internal1_m192_y0	 BUFFER[2995]	//(internal1_m192_y0) y0
#define idinternal1_m192_y0	 1050	//(internal1_m192_y0) y0
#define internal1_m198_tx	 BUFFER[2996]	//(internal1_m198_tx) tx - время накопленное сек
#define idinternal1_m198_tx	 1051	//(internal1_m198_tx) tx - время накопленное сек
#define internal1_m198_y0	 BUFFER[3001]	//(internal1_m198_y0) y0
#define idinternal1_m198_y0	 1052	//(internal1_m198_y0) y0
#define internal1_m518_tx	 BUFFER[3002]	//(internal1_m518_tx) tx - время накопленное сек
#define idinternal1_m518_tx	 1053	//(internal1_m518_tx) tx - время накопленное сек
#define internal1_m518_y0	 BUFFER[3007]	//(internal1_m518_y0) y0
#define idinternal1_m518_y0	 1054	//(internal1_m518_y0) y0
#define internal1_m2084_tx	 BUFFER[3008]	//(internal1_m2084_tx) tx - внутренний параметр
#define idinternal1_m2084_tx	 1055	//(internal1_m2084_tx) tx - внутренний параметр
#define internal1_m1172_tx	 BUFFER[3013]	//(internal1_m1172_tx) tx - внутренний параметр
#define idinternal1_m1172_tx	 1056	//(internal1_m1172_tx) tx - внутренний параметр
#define internal1_m1601_tx	 BUFFER[3018]	//(internal1_m1601_tx) tx - время накопленное сек
#define idinternal1_m1601_tx	 1057	//(internal1_m1601_tx) tx - время накопленное сек
#define internal1_m1601_y0	 BUFFER[3023]	//(internal1_m1601_y0) y0
#define idinternal1_m1601_y0	 1058	//(internal1_m1601_y0) y0
#define internal1_m1137_tx	 BUFFER[3024]	//(internal1_m1137_tx) tx - время накопленное сек
#define idinternal1_m1137_tx	 1059	//(internal1_m1137_tx) tx - время накопленное сек
#define internal1_m1137_y0	 BUFFER[3029]	//(internal1_m1137_y0) y0
#define idinternal1_m1137_y0	 1060	//(internal1_m1137_y0) y0
#define internal1_m1327_tx	 BUFFER[3030]	//(internal1_m1327_tx) tx - время накопленное сек
#define idinternal1_m1327_tx	 1061	//(internal1_m1327_tx) tx - время накопленное сек
#define internal1_m1327_y0	 BUFFER[3035]	//(internal1_m1327_y0) y0
#define idinternal1_m1327_y0	 1062	//(internal1_m1327_y0) y0
#define internal1_m926_tx	 BUFFER[3036]	//(internal1_m926_tx) tx - время накопленное сек
#define idinternal1_m926_tx	 1063	//(internal1_m926_tx) tx - время накопленное сек
#define internal1_m926_y0	 BUFFER[3041]	//(internal1_m926_y0) y0
#define idinternal1_m926_y0	 1064	//(internal1_m926_y0) y0
#define internal1_m1242_tx	 BUFFER[3042]	//(internal1_m1242_tx) tx - время накопленное сек
#define idinternal1_m1242_tx	 1065	//(internal1_m1242_tx) tx - время накопленное сек
#define internal1_m1242_y0	 BUFFER[3047]	//(internal1_m1242_y0) y0
#define idinternal1_m1242_y0	 1066	//(internal1_m1242_y0) y0
#define internal1_m1078_q0	 BUFFER[3048]	//(internal1_m1078_q0) q0 - внутренний параметр
#define idinternal1_m1078_q0	 1067	//(internal1_m1078_q0) q0 - внутренний параметр
#define internal1_m1076_q0	 BUFFER[3050]	//(internal1_m1076_q0) q0 - внутренний параметр
#define idinternal1_m1076_q0	 1068	//(internal1_m1076_q0) q0 - внутренний параметр
#define internal1_m1075_q0	 BUFFER[3052]	//(internal1_m1075_q0) q0 - внутренний параметр
#define idinternal1_m1075_q0	 1069	//(internal1_m1075_q0) q0 - внутренний параметр
#define internal1_m1073_q0	 BUFFER[3054]	//(internal1_m1073_q0) q0 - внутренний параметр
#define idinternal1_m1073_q0	 1070	//(internal1_m1073_q0) q0 - внутренний параметр
#define internal1_m1072_q0	 BUFFER[3056]	//(internal1_m1072_q0) q0 - внутренний параметр
#define idinternal1_m1072_q0	 1071	//(internal1_m1072_q0) q0 - внутренний параметр
#define internal1_m1070_q0	 BUFFER[3058]	//(internal1_m1070_q0) q0 - внутренний параметр
#define idinternal1_m1070_q0	 1072	//(internal1_m1070_q0) q0 - внутренний параметр
#define internal1_m1069_q0	 BUFFER[3060]	//(internal1_m1069_q0) q0 - внутренний параметр
#define idinternal1_m1069_q0	 1073	//(internal1_m1069_q0) q0 - внутренний параметр
#define internal1_m1067_q0	 BUFFER[3062]	//(internal1_m1067_q0) q0 - внутренний параметр
#define idinternal1_m1067_q0	 1074	//(internal1_m1067_q0) q0 - внутренний параметр
#define internal1_m1066_q0	 BUFFER[3064]	//(internal1_m1066_q0) q0 - внутренний параметр
#define idinternal1_m1066_q0	 1075	//(internal1_m1066_q0) q0 - внутренний параметр
#define internal1_m52_x0	 BUFFER[3066]	//(internal1_m52_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m52_x0	 1076	//(internal1_m52_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m986_q0	 BUFFER[3068]	//(internal1_m986_q0) q0 - внутренний параметр
#define idinternal1_m986_q0	 1077	//(internal1_m986_q0) q0 - внутренний параметр
#define internal1_m1424_x0	 BUFFER[3070]	//(internal1_m1424_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1424_x0	 1078	//(internal1_m1424_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1468_x0	 BUFFER[3072]	//(internal1_m1468_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1468_x0	 1079	//(internal1_m1468_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1464_x0	 BUFFER[3074]	//(internal1_m1464_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1464_x0	 1080	//(internal1_m1464_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1878_x0	 BUFFER[3076]	//(internal1_m1878_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1878_x0	 1081	//(internal1_m1878_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1843_x0	 BUFFER[3078]	//(internal1_m1843_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1843_x0	 1082	//(internal1_m1843_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1025_q0	 BUFFER[3080]	//(internal1_m1025_q0) q0 - внутренний параметр
#define idinternal1_m1025_q0	 1083	//(internal1_m1025_q0) q0 - внутренний параметр
#define internal1_m1037_q0	 BUFFER[3082]	//(internal1_m1037_q0) q0 - внутренний параметр
#define idinternal1_m1037_q0	 1084	//(internal1_m1037_q0) q0 - внутренний параметр
#define internal1_m1049_q0	 BUFFER[3084]	//(internal1_m1049_q0) q0 - внутренний параметр
#define idinternal1_m1049_q0	 1085	//(internal1_m1049_q0) q0 - внутренний параметр
#define internal1_m1058_q0	 BUFFER[3086]	//(internal1_m1058_q0) q0 - внутренний параметр
#define idinternal1_m1058_q0	 1086	//(internal1_m1058_q0) q0 - внутренний параметр
#define internal1_m1036_q0	 BUFFER[3088]	//(internal1_m1036_q0) q0 - внутренний параметр
#define idinternal1_m1036_q0	 1087	//(internal1_m1036_q0) q0 - внутренний параметр
#define internal1_m1051_q0	 BUFFER[3090]	//(internal1_m1051_q0) q0 - внутренний параметр
#define idinternal1_m1051_q0	 1088	//(internal1_m1051_q0) q0 - внутренний параметр
#define internal1_m1936_q0	 BUFFER[3092]	//(internal1_m1936_q0) q0 - внутренний параметр
#define idinternal1_m1936_q0	 1089	//(internal1_m1936_q0) q0 - внутренний параметр
#define internal1_m1935_q0	 BUFFER[3094]	//(internal1_m1935_q0) q0 - внутренний параметр
#define idinternal1_m1935_q0	 1090	//(internal1_m1935_q0) q0 - внутренний параметр
#define internal1_m326_Step	 BUFFER[3096]	//(internal1_m326_Step)  - текущий шаг программы
#define idinternal1_m326_Step	 1091	//(internal1_m326_Step)  - текущий шаг программы
#define internal1_m326_rz	 BUFFER[3099]	//(internal1_m326_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m326_rz	 1092	//(internal1_m326_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m326_TimS	 BUFFER[3109]	//(internal1_m326_TimS) Время от старта программы
#define idinternal1_m326_TimS	 1093	//(internal1_m326_TimS) Время от старта программы
#define internal1_m326_FinPr0	 BUFFER[3114]	//(internal1_m326_FinPr0) FinPr - конец программы
#define idinternal1_m326_FinPr0	 1094	//(internal1_m326_FinPr0) FinPr - конец программы
#define internal1_m326_ErrPr0	 BUFFER[3116]	//(internal1_m326_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m326_ErrPr0	 1095	//(internal1_m326_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m326_sbINI0	 BUFFER[3118]	//(internal1_m326_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m326_sbINI0	 1096	//(internal1_m326_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m326_sbVuIS0	 BUFFER[3120]	//(internal1_m326_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m326_sbVuIS0	 1097	//(internal1_m326_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m326_sb2UR0	 BUFFER[3122]	//(internal1_m326_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m326_sb2UR0	 1098	//(internal1_m326_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m326_sbNupIS0	 BUFFER[3124]	//(internal1_m326_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m326_sbNupIS0	 1099	//(internal1_m326_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m326_sbVuRB0	 BUFFER[3126]	//(internal1_m326_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m326_sbVuRB0	 1100	//(internal1_m326_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m326_MyFirstEnterFlag	 BUFFER[3128]	//(internal1_m326_MyFirstEnterFlag)  
#define idinternal1_m326_MyFirstEnterFlag	 1101	//(internal1_m326_MyFirstEnterFlag)  
#define internal1_m334_x0	 BUFFER[3130]	//(internal1_m334_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m334_x0	 1102	//(internal1_m334_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m293_TimS	 BUFFER[3135]	//(internal1_m293_TimS) Время старта
#define idinternal1_m293_TimS	 1103	//(internal1_m293_TimS) Время старта
#define internal1_m268_Step	 BUFFER[3140]	//(internal1_m268_Step)  - текущий шаг программы
#define idinternal1_m268_Step	 1104	//(internal1_m268_Step)  - текущий шаг программы
#define internal1_m268_rz	 BUFFER[3143]	//(internal1_m268_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m268_rz	 1105	//(internal1_m268_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m268_TimS	 BUFFER[3153]	//(internal1_m268_TimS) Время от старта программы
#define idinternal1_m268_TimS	 1106	//(internal1_m268_TimS) Время от старта программы
#define internal1_m268_FinPr0	 BUFFER[3158]	//(internal1_m268_FinPr0) FinPr - конец программы
#define idinternal1_m268_FinPr0	 1107	//(internal1_m268_FinPr0) FinPr - конец программы
#define internal1_m268_ErrPr0	 BUFFER[3160]	//(internal1_m268_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m268_ErrPr0	 1108	//(internal1_m268_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m268_sbINI0	 BUFFER[3162]	//(internal1_m268_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m268_sbINI0	 1109	//(internal1_m268_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m268_sbVuIS0	 BUFFER[3164]	//(internal1_m268_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m268_sbVuIS0	 1110	//(internal1_m268_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m268_sb2UR0	 BUFFER[3166]	//(internal1_m268_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m268_sb2UR0	 1111	//(internal1_m268_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m268_sbNupIS0	 BUFFER[3168]	//(internal1_m268_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m268_sbNupIS0	 1112	//(internal1_m268_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m268_sbVuRB0	 BUFFER[3170]	//(internal1_m268_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m268_sbVuRB0	 1113	//(internal1_m268_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m268_MyFirstEnterFlag	 BUFFER[3172]	//(internal1_m268_MyFirstEnterFlag)  
#define idinternal1_m268_MyFirstEnterFlag	 1114	//(internal1_m268_MyFirstEnterFlag)  
#define internal1_m1398_q0	 BUFFER[3174]	//(internal1_m1398_q0) q0 - внутренний параметр
#define idinternal1_m1398_q0	 1115	//(internal1_m1398_q0) q0 - внутренний параметр
#define internal1_m1399_Step	 BUFFER[3176]	//(internal1_m1399_Step)  - текущий шаг программы
#define idinternal1_m1399_Step	 1116	//(internal1_m1399_Step)  - текущий шаг программы
#define internal1_m1399_rz	 BUFFER[3179]	//(internal1_m1399_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m1399_rz	 1117	//(internal1_m1399_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m1399_TimS	 BUFFER[3185]	//(internal1_m1399_TimS) Время от старта программы
#define idinternal1_m1399_TimS	 1118	//(internal1_m1399_TimS) Время от старта программы
#define internal1_m1399_FinPr0	 BUFFER[3190]	//(internal1_m1399_FinPr0) FinPr - конец программы
#define idinternal1_m1399_FinPr0	 1119	//(internal1_m1399_FinPr0) FinPr - конец программы
#define internal1_m1399_ErrPr0	 BUFFER[3192]	//(internal1_m1399_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m1399_ErrPr0	 1120	//(internal1_m1399_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m1399_sbINI0	 BUFFER[3194]	//(internal1_m1399_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m1399_sbINI0	 1121	//(internal1_m1399_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m1399_sbVuIS0	 BUFFER[3196]	//(internal1_m1399_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m1399_sbVuIS0	 1122	//(internal1_m1399_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m1399_sb2UR0	 BUFFER[3198]	//(internal1_m1399_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m1399_sb2UR0	 1123	//(internal1_m1399_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m1399_sbNupIS0	 BUFFER[3200]	//(internal1_m1399_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m1399_sbNupIS0	 1124	//(internal1_m1399_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m1399_sbVuRB0	 BUFFER[3202]	//(internal1_m1399_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m1399_sbVuRB0	 1125	//(internal1_m1399_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m1399_MyFirstEnterFlag	 BUFFER[3204]	//(internal1_m1399_MyFirstEnterFlag)  
#define idinternal1_m1399_MyFirstEnterFlag	 1126	//(internal1_m1399_MyFirstEnterFlag)  
#define internal1_m1021_q0	 BUFFER[3206]	//(internal1_m1021_q0) q0 - внутренний параметр
#define idinternal1_m1021_q0	 1127	//(internal1_m1021_q0) q0 - внутренний параметр
#define internal1_m1018_q0	 BUFFER[3208]	//(internal1_m1018_q0) q0 - внутренний параметр
#define idinternal1_m1018_q0	 1128	//(internal1_m1018_q0) q0 - внутренний параметр
#define internal1_m1020_q0	 BUFFER[3210]	//(internal1_m1020_q0) q0 - внутренний параметр
#define idinternal1_m1020_q0	 1129	//(internal1_m1020_q0) q0 - внутренний параметр
#define internal1_m1014_q0	 BUFFER[3212]	//(internal1_m1014_q0) q0 - внутренний параметр
#define idinternal1_m1014_q0	 1130	//(internal1_m1014_q0) q0 - внутренний параметр
#define internal1_m743_q0	 BUFFER[3214]	//(internal1_m743_q0) q0 - внутренний параметр
#define idinternal1_m743_q0	 1131	//(internal1_m743_q0) q0 - внутренний параметр
#define internal1_m336_q0	 BUFFER[3216]	//(internal1_m336_q0) q0 - внутренний параметр
#define idinternal1_m336_q0	 1132	//(internal1_m336_q0) q0 - внутренний параметр
#define internal1_m332_q0	 BUFFER[3218]	//(internal1_m332_q0) q0 - внутренний параметр
#define idinternal1_m332_q0	 1133	//(internal1_m332_q0) q0 - внутренний параметр
#define internal1_m288_q0	 BUFFER[3220]	//(internal1_m288_q0) q0 - внутренний параметр
#define idinternal1_m288_q0	 1134	//(internal1_m288_q0) q0 - внутренний параметр
#define internal1_m287_x0	 BUFFER[3222]	//(internal1_m287_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m287_x0	 1135	//(internal1_m287_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1865_q0	 BUFFER[3227]	//(internal1_m1865_q0) q0 - внутренний параметр
#define idinternal1_m1865_q0	 1136	//(internal1_m1865_q0) q0 - внутренний параметр
#define internal1_m1853_q0	 BUFFER[3229]	//(internal1_m1853_q0) q0 - внутренний параметр
#define idinternal1_m1853_q0	 1137	//(internal1_m1853_q0) q0 - внутренний параметр
#define internal1_m1844_q0	 BUFFER[3231]	//(internal1_m1844_q0) q0 - внутренний параметр
#define idinternal1_m1844_q0	 1138	//(internal1_m1844_q0) q0 - внутренний параметр
#define internal1_m1919_q0	 BUFFER[3233]	//(internal1_m1919_q0) q0 - внутренний параметр
#define idinternal1_m1919_q0	 1139	//(internal1_m1919_q0) q0 - внутренний параметр
#define internal1_m1889_q0	 BUFFER[3235]	//(internal1_m1889_q0) q0 - внутренний параметр
#define idinternal1_m1889_q0	 1140	//(internal1_m1889_q0) q0 - внутренний параметр
#define internal1_m1879_q0	 BUFFER[3237]	//(internal1_m1879_q0) q0 - внутренний параметр
#define idinternal1_m1879_q0	 1141	//(internal1_m1879_q0) q0 - внутренний параметр
#define internal1_m1451_q0	 BUFFER[3239]	//(internal1_m1451_q0) q0 - внутренний параметр
#define idinternal1_m1451_q0	 1142	//(internal1_m1451_q0) q0 - внутренний параметр
#define internal1_m1438_x0	 BUFFER[3241]	//(internal1_m1438_x0) был приход сигнала x1
#define idinternal1_m1438_x0	 1143	//(internal1_m1438_x0) был приход сигнала x1
#define internal1_m1438_y0	 BUFFER[3243]	//(internal1_m1438_y0) интервал между сигналами х1 и х2
#define idinternal1_m1438_y0	 1144	//(internal1_m1438_y0) интервал между сигналами х1 и х2
#define internal1_m1434_q0	 BUFFER[3248]	//(internal1_m1434_q0) q0 - внутренний параметр
#define idinternal1_m1434_q0	 1145	//(internal1_m1434_q0) q0 - внутренний параметр
#define internal1_m1425_q0	 BUFFER[3250]	//(internal1_m1425_q0) q0 - внутренний параметр
#define idinternal1_m1425_q0	 1146	//(internal1_m1425_q0) q0 - внутренний параметр
#define internal1_m1484_q0	 BUFFER[3252]	//(internal1_m1484_q0) q0 - внутренний параметр
#define idinternal1_m1484_q0	 1147	//(internal1_m1484_q0) q0 - внутренний параметр
#define internal1_m1504_q0	 BUFFER[3254]	//(internal1_m1504_q0) q0 - внутренний параметр
#define idinternal1_m1504_q0	 1148	//(internal1_m1504_q0) q0 - внутренний параметр
#define internal1_m1471_q0	 BUFFER[3256]	//(internal1_m1471_q0) q0 - внутренний параметр
#define idinternal1_m1471_q0	 1149	//(internal1_m1471_q0) q0 - внутренний параметр
#define internal1_m1485_x0	 BUFFER[3258]	//(internal1_m1485_x0) был приход сигнала x1
#define idinternal1_m1485_x0	 1150	//(internal1_m1485_x0) был приход сигнала x1
#define internal1_m1485_y0	 BUFFER[3260]	//(internal1_m1485_y0) интервал между сигналами х1 и х2
#define idinternal1_m1485_y0	 1151	//(internal1_m1485_y0) интервал между сигналами х1 и х2
#define internal1_m1409_x0	 BUFFER[3265]	//(internal1_m1409_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1409_x0	 1152	//(internal1_m1409_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1490_q0	 BUFFER[3270]	//(internal1_m1490_q0) q0 - внутренний параметр
#define idinternal1_m1490_q0	 1153	//(internal1_m1490_q0) q0 - внутренний параметр
#define internal1_m26_q0	 BUFFER[3272]	//(internal1_m26_q0) q0 - внутренний параметр
#define idinternal1_m26_q0	 1154	//(internal1_m26_q0) q0 - внутренний параметр
#define internal1_m1505_q0	 BUFFER[3274]	//(internal1_m1505_q0) q0 - внутренний параметр
#define idinternal1_m1505_q0	 1155	//(internal1_m1505_q0) q0 - внутренний параметр
#define internal1_m633_q0	 BUFFER[3276]	//(internal1_m633_q0) q0 - внутренний параметр
#define idinternal1_m633_q0	 1156	//(internal1_m633_q0) q0 - внутренний параметр
#define internal1_m618_q0	 BUFFER[3278]	//(internal1_m618_q0) q0 - внутренний параметр
#define idinternal1_m618_q0	 1157	//(internal1_m618_q0) q0 - внутренний параметр
#define internal1_m646_q0	 BUFFER[3280]	//(internal1_m646_q0) q0 - внутренний параметр
#define idinternal1_m646_q0	 1158	//(internal1_m646_q0) q0 - внутренний параметр
#define internal1_m629_q0	 BUFFER[3282]	//(internal1_m629_q0) q0 - внутренний параметр
#define idinternal1_m629_q0	 1159	//(internal1_m629_q0) q0 - внутренний параметр
#define internal1_m613_q0	 BUFFER[3284]	//(internal1_m613_q0) q0 - внутренний параметр
#define idinternal1_m613_q0	 1160	//(internal1_m613_q0) q0 - внутренний параметр
#define internal1_m611_q0	 BUFFER[3286]	//(internal1_m611_q0) q0 - внутренний параметр
#define idinternal1_m611_q0	 1161	//(internal1_m611_q0) q0 - внутренний параметр
#define internal1_m599_q0	 BUFFER[3288]	//(internal1_m599_q0) q0 - внутренний параметр
#define idinternal1_m599_q0	 1162	//(internal1_m599_q0) q0 - внутренний параметр
#define internal1_m1401_q0	 BUFFER[3290]	//(internal1_m1401_q0) q0 - внутренний параметр
#define idinternal1_m1401_q0	 1163	//(internal1_m1401_q0) q0 - внутренний параметр
#define internal1_m609_q0	 BUFFER[3295]	//(internal1_m609_q0) q0 - внутренний параметр
#define idinternal1_m609_q0	 1164	//(internal1_m609_q0) q0 - внутренний параметр
#define internal1_m109_q0	 BUFFER[3297]	//(internal1_m109_q0) q0 - внутренний параметр
#define idinternal1_m109_q0	 1165	//(internal1_m109_q0) q0 - внутренний параметр
#define internal1_m1637_q0	 BUFFER[3299]	//(internal1_m1637_q0) q0 - внутренний параметр
#define idinternal1_m1637_q0	 1166	//(internal1_m1637_q0) q0 - внутренний параметр
#define internal1_m1636_q0	 BUFFER[3301]	//(internal1_m1636_q0) q0 - внутренний параметр
#define idinternal1_m1636_q0	 1167	//(internal1_m1636_q0) q0 - внутренний параметр
#define internal1_m1635_q0	 BUFFER[3303]	//(internal1_m1635_q0) q0 - внутренний параметр
#define idinternal1_m1635_q0	 1168	//(internal1_m1635_q0) q0 - внутренний параметр
#define internal1_m1634_q0	 BUFFER[3305]	//(internal1_m1634_q0) q0 - внутренний параметр
#define idinternal1_m1634_q0	 1169	//(internal1_m1634_q0) q0 - внутренний параметр
#define internal1_m1670_q0	 BUFFER[3307]	//(internal1_m1670_q0) q0 - внутренний параметр
#define idinternal1_m1670_q0	 1170	//(internal1_m1670_q0) q0 - внутренний параметр
#define internal1_m1669_q0	 BUFFER[3309]	//(internal1_m1669_q0) q0 - внутренний параметр
#define idinternal1_m1669_q0	 1171	//(internal1_m1669_q0) q0 - внутренний параметр
#define internal1_m1668_q0	 BUFFER[3311]	//(internal1_m1668_q0) q0 - внутренний параметр
#define idinternal1_m1668_q0	 1172	//(internal1_m1668_q0) q0 - внутренний параметр
#define internal1_m1950_q0	 BUFFER[3313]	//(internal1_m1950_q0) q0 - внутренний параметр
#define idinternal1_m1950_q0	 1173	//(internal1_m1950_q0) q0 - внутренний параметр
#define internal1_m1730_q0	 BUFFER[3315]	//(internal1_m1730_q0) q0 - внутренний параметр
#define idinternal1_m1730_q0	 1174	//(internal1_m1730_q0) q0 - внутренний параметр
#define internal1_m1719_q0	 BUFFER[3317]	//(internal1_m1719_q0) q0 - внутренний параметр
#define idinternal1_m1719_q0	 1175	//(internal1_m1719_q0) q0 - внутренний параметр
#define internal1_m1727_q0	 BUFFER[3319]	//(internal1_m1727_q0) q0 - внутренний параметр
#define idinternal1_m1727_q0	 1176	//(internal1_m1727_q0) q0 - внутренний параметр
#define internal1_m1716_q0	 BUFFER[3321]	//(internal1_m1716_q0) q0 - внутренний параметр
#define idinternal1_m1716_q0	 1177	//(internal1_m1716_q0) q0 - внутренний параметр
#define internal1_m1724_q0	 BUFFER[3323]	//(internal1_m1724_q0) q0 - внутренний параметр
#define idinternal1_m1724_q0	 1178	//(internal1_m1724_q0) q0 - внутренний параметр
#define internal1_m2149_q0	 BUFFER[3325]	//(internal1_m2149_q0) q0 - внутренний параметр
#define idinternal1_m2149_q0	 1179	//(internal1_m2149_q0) q0 - внутренний параметр
#define internal1_m2145_q0	 BUFFER[3327]	//(internal1_m2145_q0) q0 - внутренний параметр
#define idinternal1_m2145_q0	 1180	//(internal1_m2145_q0) q0 - внутренний параметр
#define internal1_m1695_q0	 BUFFER[3329]	//(internal1_m1695_q0) q0 - внутренний параметр
#define idinternal1_m1695_q0	 1181	//(internal1_m1695_q0) q0 - внутренний параметр
#define internal1_m1687_q0	 BUFFER[3331]	//(internal1_m1687_q0) q0 - внутренний параметр
#define idinternal1_m1687_q0	 1182	//(internal1_m1687_q0) q0 - внутренний параметр
#define internal1_m1685_q0	 BUFFER[3333]	//(internal1_m1685_q0) q0 - внутренний параметр
#define idinternal1_m1685_q0	 1183	//(internal1_m1685_q0) q0 - внутренний параметр
#define internal1_m1681_q0	 BUFFER[3335]	//(internal1_m1681_q0) q0 - внутренний параметр
#define idinternal1_m1681_q0	 1184	//(internal1_m1681_q0) q0 - внутренний параметр
#define internal1_m1677_q0	 BUFFER[3337]	//(internal1_m1677_q0) q0 - внутренний параметр
#define idinternal1_m1677_q0	 1185	//(internal1_m1677_q0) q0 - внутренний параметр
#define internal1_m1679_q0	 BUFFER[3339]	//(internal1_m1679_q0) q0 - внутренний параметр
#define idinternal1_m1679_q0	 1186	//(internal1_m1679_q0) q0 - внутренний параметр
#define internal1_m19_q0	 BUFFER[3341]	//(internal1_m19_q0) q0 - внутренний параметр
#define idinternal1_m19_q0	 1187	//(internal1_m19_q0) q0 - внутренний параметр
#define internal1_m1660_q0	 BUFFER[3343]	//(internal1_m1660_q0) q0 - внутренний параметр
#define idinternal1_m1660_q0	 1188	//(internal1_m1660_q0) q0 - внутренний параметр
#define internal1_m1658_q0	 BUFFER[3345]	//(internal1_m1658_q0) q0 - внутренний параметр
#define idinternal1_m1658_q0	 1189	//(internal1_m1658_q0) q0 - внутренний параметр
#define internal1_m1654_q0	 BUFFER[3347]	//(internal1_m1654_q0) q0 - внутренний параметр
#define idinternal1_m1654_q0	 1190	//(internal1_m1654_q0) q0 - внутренний параметр
#define internal1_m1656_q0	 BUFFER[3349]	//(internal1_m1656_q0) q0 - внутренний параметр
#define idinternal1_m1656_q0	 1191	//(internal1_m1656_q0) q0 - внутренний параметр
#define internal1_m1652_q0	 BUFFER[3351]	//(internal1_m1652_q0) q0 - внутренний параметр
#define idinternal1_m1652_q0	 1192	//(internal1_m1652_q0) q0 - внутренний параметр
#define internal1_m1650_q0	 BUFFER[3353]	//(internal1_m1650_q0) q0 - внутренний параметр
#define idinternal1_m1650_q0	 1193	//(internal1_m1650_q0) q0 - внутренний параметр
#define internal1_m2065_q0	 BUFFER[3355]	//(internal1_m2065_q0) q0 - внутренний параметр
#define idinternal1_m2065_q0	 1194	//(internal1_m2065_q0) q0 - внутренний параметр
#define internal1_m2061_q0	 BUFFER[3357]	//(internal1_m2061_q0) q0 - внутренний параметр
#define idinternal1_m2061_q0	 1195	//(internal1_m2061_q0) q0 - внутренний параметр
#define internal1_m2040_q0	 BUFFER[3359]	//(internal1_m2040_q0) q0 - внутренний параметр
#define idinternal1_m2040_q0	 1196	//(internal1_m2040_q0) q0 - внутренний параметр
#define internal1_m2028_q0	 BUFFER[3361]	//(internal1_m2028_q0) q0 - внутренний параметр
#define idinternal1_m2028_q0	 1197	//(internal1_m2028_q0) q0 - внутренний параметр
#define internal1_m1961_q0	 BUFFER[3363]	//(internal1_m1961_q0) q0 - внутренний параметр
#define idinternal1_m1961_q0	 1198	//(internal1_m1961_q0) q0 - внутренний параметр
#define internal1_m1646_q0	 BUFFER[3365]	//(internal1_m1646_q0) q0 - внутренний параметр
#define idinternal1_m1646_q0	 1199	//(internal1_m1646_q0) q0 - внутренний параметр
#define internal1_m1648_q0	 BUFFER[3367]	//(internal1_m1648_q0) q0 - внутренний параметр
#define idinternal1_m1648_q0	 1200	//(internal1_m1648_q0) q0 - внутренний параметр
#define internal1_m1632_q0	 BUFFER[3369]	//(internal1_m1632_q0) q0 - внутренний параметр
#define idinternal1_m1632_q0	 1201	//(internal1_m1632_q0) q0 - внутренний параметр
#define internal1_m1630_q0	 BUFFER[3371]	//(internal1_m1630_q0) q0 - внутренний параметр
#define idinternal1_m1630_q0	 1202	//(internal1_m1630_q0) q0 - внутренний параметр
#define internal1_m1628_q0	 BUFFER[3373]	//(internal1_m1628_q0) q0 - внутренний параметр
#define idinternal1_m1628_q0	 1203	//(internal1_m1628_q0) q0 - внутренний параметр
#define internal1_m1626_q0	 BUFFER[3375]	//(internal1_m1626_q0) q0 - внутренний параметр
#define idinternal1_m1626_q0	 1204	//(internal1_m1626_q0) q0 - внутренний параметр
#define internal1_m1625_q0	 BUFFER[3377]	//(internal1_m1625_q0) q0 - внутренний параметр
#define idinternal1_m1625_q0	 1205	//(internal1_m1625_q0) q0 - внутренний параметр
#define internal1_m1623_q0	 BUFFER[3379]	//(internal1_m1623_q0) q0 - внутренний параметр
#define idinternal1_m1623_q0	 1206	//(internal1_m1623_q0) q0 - внутренний параметр
#define internal1_m1622_q0	 BUFFER[3381]	//(internal1_m1622_q0) q0 - внутренний параметр
#define idinternal1_m1622_q0	 1207	//(internal1_m1622_q0) q0 - внутренний параметр
#define internal1_m1620_q0	 BUFFER[3383]	//(internal1_m1620_q0) q0 - внутренний параметр
#define idinternal1_m1620_q0	 1208	//(internal1_m1620_q0) q0 - внутренний параметр
#define internal1_m2089_DvUp0	 BUFFER[3385]	//(internal1_m2089_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2089_DvUp0	 1209	//(internal1_m2089_DvUp0) - есть команда на движение вперёд
#define internal1_m2089_DvDw0	 BUFFER[3386]	//(internal1_m2089_DvDw0) - есть команда на движение назад
#define idinternal1_m2089_DvDw0	 1210	//(internal1_m2089_DvDw0) - есть команда на движение назад
#define internal1_m2089_FDvUp0	 BUFFER[3387]	//(internal1_m2089_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2089_FDvUp0	 1211	//(internal1_m2089_FDvUp0) - есть команда на движение вперёд
#define internal1_m2089_FDvDw0	 BUFFER[3388]	//(internal1_m2089_FDvDw0) - есть команда на движение назад
#define idinternal1_m2089_FDvDw0	 1212	//(internal1_m2089_FDvDw0) - есть команда на движение назад
#define internal1_m2089_BlDv0	 BUFFER[3389]	//(internal1_m2089_BlDv0) - была блокировка
#define idinternal1_m2089_BlDv0	 1213	//(internal1_m2089_BlDv0) - была блокировка
#define internal1_m2089_Pkv0	 BUFFER[3390]	//(internal1_m2089_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2089_Pkv0	 1214	//(internal1_m2089_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2089_Pkav0	 BUFFER[3391]	//(internal1_m2089_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2089_Pkav0	 1215	//(internal1_m2089_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2089_Zkv0	 BUFFER[3392]	//(internal1_m2089_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2089_Zkv0	 1216	//(internal1_m2089_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2089_Zkav0	 BUFFER[3393]	//(internal1_m2089_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2089_Zkav0	 1217	//(internal1_m2089_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2089_txNm	 BUFFER[3394]	//(internal1_m2089_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2089_txNm	 1218	//(internal1_m2089_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2089_txSm	 BUFFER[3399]	//(internal1_m2089_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2089_txSm	 1219	//(internal1_m2089_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2089_txHr	 BUFFER[3404]	//(internal1_m2089_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2089_txHr	 1220	//(internal1_m2089_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2089_txLd	 BUFFER[3409]	//(internal1_m2089_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2089_txLd	 1221	//(internal1_m2089_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2089_fef	 BUFFER[3414]	//(internal1_m2089_fef) fef
#define idinternal1_m2089_fef	 1222	//(internal1_m2089_fef) fef
#define internal1_m2083_DvUp0	 BUFFER[3415]	//(internal1_m2083_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2083_DvUp0	 1223	//(internal1_m2083_DvUp0) - есть команда на движение вперёд
#define internal1_m2083_DvDw0	 BUFFER[3416]	//(internal1_m2083_DvDw0) - есть команда на движение назад
#define idinternal1_m2083_DvDw0	 1224	//(internal1_m2083_DvDw0) - есть команда на движение назад
#define internal1_m2083_FDvUp0	 BUFFER[3417]	//(internal1_m2083_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2083_FDvUp0	 1225	//(internal1_m2083_FDvUp0) - есть команда на движение вперёд
#define internal1_m2083_FDvDw0	 BUFFER[3418]	//(internal1_m2083_FDvDw0) - есть команда на движение назад
#define idinternal1_m2083_FDvDw0	 1226	//(internal1_m2083_FDvDw0) - есть команда на движение назад
#define internal1_m2083_BlDv0	 BUFFER[3419]	//(internal1_m2083_BlDv0) - была блокировка
#define idinternal1_m2083_BlDv0	 1227	//(internal1_m2083_BlDv0) - была блокировка
#define internal1_m2083_Pkv0	 BUFFER[3420]	//(internal1_m2083_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2083_Pkv0	 1228	//(internal1_m2083_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2083_Pkav0	 BUFFER[3421]	//(internal1_m2083_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2083_Pkav0	 1229	//(internal1_m2083_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2083_Zkv0	 BUFFER[3422]	//(internal1_m2083_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2083_Zkv0	 1230	//(internal1_m2083_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2083_Zkav0	 BUFFER[3423]	//(internal1_m2083_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2083_Zkav0	 1231	//(internal1_m2083_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2083_txNm	 BUFFER[3424]	//(internal1_m2083_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2083_txNm	 1232	//(internal1_m2083_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2083_txSm	 BUFFER[3429]	//(internal1_m2083_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2083_txSm	 1233	//(internal1_m2083_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2083_txHr	 BUFFER[3434]	//(internal1_m2083_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2083_txHr	 1234	//(internal1_m2083_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2083_txLd	 BUFFER[3439]	//(internal1_m2083_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2083_txLd	 1235	//(internal1_m2083_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2083_fef	 BUFFER[3444]	//(internal1_m2083_fef) fef
#define idinternal1_m2083_fef	 1236	//(internal1_m2083_fef) fef
#define internal1_m1476_q0	 BUFFER[3445]	//(internal1_m1476_q0) q0 - внутренний параметр
#define idinternal1_m1476_q0	 1237	//(internal1_m1476_q0) q0 - внутренний параметр
#define internal1_m1479_x0	 BUFFER[3447]	//(internal1_m1479_x0) был приход сигнала x1
#define idinternal1_m1479_x0	 1238	//(internal1_m1479_x0) был приход сигнала x1
#define internal1_m1479_y0	 BUFFER[3449]	//(internal1_m1479_y0) интервал между сигналами х1 и х2
#define idinternal1_m1479_y0	 1239	//(internal1_m1479_y0) интервал между сигналами х1 и х2
#define internal1_m1901_x0	 BUFFER[3454]	//(internal1_m1901_x0) был приход сигнала x1
#define idinternal1_m1901_x0	 1240	//(internal1_m1901_x0) был приход сигнала x1
#define internal1_m1901_y0	 BUFFER[3456]	//(internal1_m1901_y0) интервал между сигналами х1 и х2
#define idinternal1_m1901_y0	 1241	//(internal1_m1901_y0) интервал между сигналами х1 и х2
#define internal1_m1862_x0	 BUFFER[3461]	//(internal1_m1862_x0) был приход сигнала x1
#define idinternal1_m1862_x0	 1242	//(internal1_m1862_x0) был приход сигнала x1
#define internal1_m1862_y0	 BUFFER[3463]	//(internal1_m1862_y0) интервал между сигналами х1 и х2
#define idinternal1_m1862_y0	 1243	//(internal1_m1862_y0) интервал между сигналами х1 и х2
#define internal1_m279_q0	 BUFFER[3468]	//(internal1_m279_q0) q0 - внутренний параметр
#define idinternal1_m279_q0	 1244	//(internal1_m279_q0) q0 - внутренний параметр
#define internal1_m994_q0	 BUFFER[3470]	//(internal1_m994_q0) q0 - внутренний параметр
#define idinternal1_m994_q0	 1245	//(internal1_m994_q0) q0 - внутренний параметр
#define internal1_m621_q0	 BUFFER[3472]	//(internal1_m621_q0) q0 - внутренний параметр
#define idinternal1_m621_q0	 1246	//(internal1_m621_q0) q0 - внутренний параметр
#define internal1_m1298_X0	 BUFFER[3474]	//(internal1_m1298_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1298_X0	 1247	//(internal1_m1298_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1298_t0	 BUFFER[3479]	//(internal1_m1298_t0) время нахождения в зоне возврата
#define idinternal1_m1298_t0	 1248	//(internal1_m1298_t0) время нахождения в зоне возврата
#define internal1_m1298_BLDv0	 BUFFER[3484]	//(internal1_m1298_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1298_BLDv0	 1249	//(internal1_m1298_BLDv0) BlDv - Блокировка движения
#define internal1_m1317_tx	 BUFFER[3485]	//(internal1_m1317_tx) tx - время накопленное сек
#define idinternal1_m1317_tx	 1250	//(internal1_m1317_tx) tx - время накопленное сек
#define internal1_m1317_y0	 BUFFER[3490]	//(internal1_m1317_y0) y0
#define idinternal1_m1317_y0	 1251	//(internal1_m1317_y0) y0
#define internal1_m1319_tx	 BUFFER[3491]	//(internal1_m1319_tx) tx - время накопленное сек
#define idinternal1_m1319_tx	 1252	//(internal1_m1319_tx) tx - время накопленное сек
#define internal1_m1319_y0	 BUFFER[3496]	//(internal1_m1319_y0) y0
#define idinternal1_m1319_y0	 1253	//(internal1_m1319_y0) y0
#define internal1_m1326_xptr	 BUFFER[3497]	//(internal1_m1326_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1326_xptr	 1254	//(internal1_m1326_xptr) указатель текущей позиции в массиве координат
#define internal1_m1326_x0	 BUFFER[3500]	//(internal1_m1326_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1326_x0	 1255	//(internal1_m1326_x0) x0 - массив мгновенных значений координат
#define internal1_m1326_tim0	 BUFFER[3800]	//(internal1_m1326_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1326_tim0	 1256	//(internal1_m1326_tim0) tim0 - массив значений времени цикла
#define internal1_m1326_sumtim	 BUFFER[4100]	//(internal1_m1326_sumtim) sumtim - время в пути
#define idinternal1_m1326_sumtim	 1257	//(internal1_m1326_sumtim) sumtim - время в пути
#define internal1_m1326_StSpeed	 BUFFER[4105]	//(internal1_m1326_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1326_StSpeed	 1258	//(internal1_m1326_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1326_Vz0	 BUFFER[4110]	//(internal1_m1326_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1326_Vz0	 1259	//(internal1_m1326_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1326_flRazg	 BUFFER[4115]	//(internal1_m1326_flRazg) признак разгона/торможения
#define idinternal1_m1326_flRazg	 1260	//(internal1_m1326_flRazg) признак разгона/торможения
#define internal1_m1326_DelSp	 BUFFER[4118]	//(internal1_m1326_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1326_DelSp	 1261	//(internal1_m1326_DelSp) DelSp - время переключения скоростей
#define internal1_m1326_z0	 BUFFER[4123]	//(internal1_m1326_z0) z0 - точка прекращения движения
#define idinternal1_m1326_z0	 1262	//(internal1_m1326_z0) z0 - точка прекращения движения
#define internal1_m1326_txZS	 BUFFER[4128]	//(internal1_m1326_txZS) txZS
#define idinternal1_m1326_txZS	 1263	//(internal1_m1326_txZS) txZS
#define internal1_m1326_tx	 BUFFER[4133]	//(internal1_m1326_tx) tx
#define idinternal1_m1326_tx	 1264	//(internal1_m1326_tx) tx
#define internal1_m1326_txd	 BUFFER[4138]	//(internal1_m1326_txd) txd
#define idinternal1_m1326_txd	 1265	//(internal1_m1326_txd) txd
#define internal1_m1326_txMBl	 BUFFER[4143]	//(internal1_m1326_txMBl) tx
#define idinternal1_m1326_txMBl	 1266	//(internal1_m1326_txMBl) tx
#define internal1_m1326_txBl	 BUFFER[4148]	//(internal1_m1326_txBl) tx
#define idinternal1_m1326_txBl	 1267	//(internal1_m1326_txBl) tx
#define internal1_m1326_Speed0	 BUFFER[4153]	//(internal1_m1326_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1326_Speed0	 1268	//(internal1_m1326_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1326_xz0	 BUFFER[4158]	//(internal1_m1326_xz0) xz0 - новое задание мм
#define idinternal1_m1326_xz0	 1269	//(internal1_m1326_xz0) xz0 - новое задание мм
#define internal1_m1326_tz0	 BUFFER[4163]	//(internal1_m1326_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1326_tz0	 1270	//(internal1_m1326_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1326_Shift0	 BUFFER[4168]	//(internal1_m1326_Shift0) Shift0 - признак самохода
#define idinternal1_m1326_Shift0	 1271	//(internal1_m1326_Shift0) Shift0 - признак самохода
#define internal1_m1326_ShCntlSp0	 BUFFER[4170]	//(internal1_m1326_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1326_ShCntlSp0	 1272	//(internal1_m1326_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1326_ShiftControl	 BUFFER[4172]	//(internal1_m1326_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1326_ShiftControl	 1273	//(internal1_m1326_ShiftControl) ShiftControl - признак самохода
#define internal1_m619_q0	 BUFFER[4174]	//(internal1_m619_q0) q0 - внутренний параметр
#define idinternal1_m619_q0	 1274	//(internal1_m619_q0) q0 - внутренний параметр
#define internal1_m892_X0	 BUFFER[4176]	//(internal1_m892_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m892_X0	 1275	//(internal1_m892_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m892_t0	 BUFFER[4181]	//(internal1_m892_t0) время нахождения в зоне возврата
#define idinternal1_m892_t0	 1276	//(internal1_m892_t0) время нахождения в зоне возврата
#define internal1_m892_BLDv0	 BUFFER[4186]	//(internal1_m892_BLDv0) BlDv - Блокировка движения
#define idinternal1_m892_BLDv0	 1277	//(internal1_m892_BLDv0) BlDv - Блокировка движения
#define internal1_m916_tx	 BUFFER[4187]	//(internal1_m916_tx) tx - время накопленное сек
#define idinternal1_m916_tx	 1278	//(internal1_m916_tx) tx - время накопленное сек
#define internal1_m916_y0	 BUFFER[4192]	//(internal1_m916_y0) y0
#define idinternal1_m916_y0	 1279	//(internal1_m916_y0) y0
#define internal1_m918_tx	 BUFFER[4193]	//(internal1_m918_tx) tx - время накопленное сек
#define idinternal1_m918_tx	 1280	//(internal1_m918_tx) tx - время накопленное сек
#define internal1_m918_y0	 BUFFER[4198]	//(internal1_m918_y0) y0
#define idinternal1_m918_y0	 1281	//(internal1_m918_y0) y0
#define internal1_m925_xptr	 BUFFER[4199]	//(internal1_m925_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m925_xptr	 1282	//(internal1_m925_xptr) указатель текущей позиции в массиве координат
#define internal1_m925_x0	 BUFFER[4202]	//(internal1_m925_x0) x0 - массив мгновенных значений координат
#define idinternal1_m925_x0	 1283	//(internal1_m925_x0) x0 - массив мгновенных значений координат
#define internal1_m925_tim0	 BUFFER[4502]	//(internal1_m925_tim0) tim0 - массив значений времени цикла
#define idinternal1_m925_tim0	 1284	//(internal1_m925_tim0) tim0 - массив значений времени цикла
#define internal1_m925_sumtim	 BUFFER[4802]	//(internal1_m925_sumtim) sumtim - время в пути
#define idinternal1_m925_sumtim	 1285	//(internal1_m925_sumtim) sumtim - время в пути
#define internal1_m925_StSpeed	 BUFFER[4807]	//(internal1_m925_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m925_StSpeed	 1286	//(internal1_m925_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m925_Vz0	 BUFFER[4812]	//(internal1_m925_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m925_Vz0	 1287	//(internal1_m925_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m925_flRazg	 BUFFER[4817]	//(internal1_m925_flRazg) признак разгона/торможения
#define idinternal1_m925_flRazg	 1288	//(internal1_m925_flRazg) признак разгона/торможения
#define internal1_m925_DelSp	 BUFFER[4820]	//(internal1_m925_DelSp) DelSp - время переключения скоростей
#define idinternal1_m925_DelSp	 1289	//(internal1_m925_DelSp) DelSp - время переключения скоростей
#define internal1_m925_z0	 BUFFER[4825]	//(internal1_m925_z0) z0 - точка прекращения движения
#define idinternal1_m925_z0	 1290	//(internal1_m925_z0) z0 - точка прекращения движения
#define internal1_m925_txZS	 BUFFER[4830]	//(internal1_m925_txZS) txZS
#define idinternal1_m925_txZS	 1291	//(internal1_m925_txZS) txZS
#define internal1_m925_tx	 BUFFER[4835]	//(internal1_m925_tx) tx
#define idinternal1_m925_tx	 1292	//(internal1_m925_tx) tx
#define internal1_m925_txd	 BUFFER[4840]	//(internal1_m925_txd) txd
#define idinternal1_m925_txd	 1293	//(internal1_m925_txd) txd
#define internal1_m925_txMBl	 BUFFER[4845]	//(internal1_m925_txMBl) tx
#define idinternal1_m925_txMBl	 1294	//(internal1_m925_txMBl) tx
#define internal1_m925_txBl	 BUFFER[4850]	//(internal1_m925_txBl) tx
#define idinternal1_m925_txBl	 1295	//(internal1_m925_txBl) tx
#define internal1_m925_Speed0	 BUFFER[4855]	//(internal1_m925_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m925_Speed0	 1296	//(internal1_m925_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m925_xz0	 BUFFER[4860]	//(internal1_m925_xz0) xz0 - новое задание мм
#define idinternal1_m925_xz0	 1297	//(internal1_m925_xz0) xz0 - новое задание мм
#define internal1_m925_tz0	 BUFFER[4865]	//(internal1_m925_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m925_tz0	 1298	//(internal1_m925_tz0) tz0 - время защиты от нового задания сек
#define internal1_m925_Shift0	 BUFFER[4870]	//(internal1_m925_Shift0) Shift0 - признак самохода
#define idinternal1_m925_Shift0	 1299	//(internal1_m925_Shift0) Shift0 - признак самохода
#define internal1_m925_ShCntlSp0	 BUFFER[4872]	//(internal1_m925_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m925_ShCntlSp0	 1300	//(internal1_m925_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m925_ShiftControl	 BUFFER[4874]	//(internal1_m925_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m925_ShiftControl	 1301	//(internal1_m925_ShiftControl) ShiftControl - признак самохода
#define internal1_m490_X0	 BUFFER[4876]	//(internal1_m490_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m490_X0	 1302	//(internal1_m490_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m490_t0	 BUFFER[4881]	//(internal1_m490_t0) время нахождения в зоне возврата
#define idinternal1_m490_t0	 1303	//(internal1_m490_t0) время нахождения в зоне возврата
#define internal1_m490_BLDv0	 BUFFER[4886]	//(internal1_m490_BLDv0) BlDv - Блокировка движения
#define idinternal1_m490_BLDv0	 1304	//(internal1_m490_BLDv0) BlDv - Блокировка движения
#define internal1_m510_tx	 BUFFER[4887]	//(internal1_m510_tx) tx - время накопленное сек
#define idinternal1_m510_tx	 1305	//(internal1_m510_tx) tx - время накопленное сек
#define internal1_m510_y0	 BUFFER[4892]	//(internal1_m510_y0) y0
#define idinternal1_m510_y0	 1306	//(internal1_m510_y0) y0
#define internal1_m512_tx	 BUFFER[4893]	//(internal1_m512_tx) tx - время накопленное сек
#define idinternal1_m512_tx	 1307	//(internal1_m512_tx) tx - время накопленное сек
#define internal1_m512_y0	 BUFFER[4898]	//(internal1_m512_y0) y0
#define idinternal1_m512_y0	 1308	//(internal1_m512_y0) y0
#define internal1_m517_xptr	 BUFFER[4899]	//(internal1_m517_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m517_xptr	 1309	//(internal1_m517_xptr) указатель текущей позиции в массиве координат
#define internal1_m517_x0	 BUFFER[4902]	//(internal1_m517_x0) x0 - массив мгновенных значений координат
#define idinternal1_m517_x0	 1310	//(internal1_m517_x0) x0 - массив мгновенных значений координат
#define internal1_m517_tim0	 BUFFER[5652]	//(internal1_m517_tim0) tim0 - массив значений времени цикла
#define idinternal1_m517_tim0	 1311	//(internal1_m517_tim0) tim0 - массив значений времени цикла
#define internal1_m517_sumtim	 BUFFER[6402]	//(internal1_m517_sumtim) sumtim - время в пути
#define idinternal1_m517_sumtim	 1312	//(internal1_m517_sumtim) sumtim - время в пути
#define internal1_m517_StSpeed	 BUFFER[6407]	//(internal1_m517_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m517_StSpeed	 1313	//(internal1_m517_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m517_Vz0	 BUFFER[6412]	//(internal1_m517_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m517_Vz0	 1314	//(internal1_m517_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m517_flRazg	 BUFFER[6417]	//(internal1_m517_flRazg) признак разгона/торможения
#define idinternal1_m517_flRazg	 1315	//(internal1_m517_flRazg) признак разгона/торможения
#define internal1_m517_DelSp	 BUFFER[6420]	//(internal1_m517_DelSp) DelSp - время переключения скоростей
#define idinternal1_m517_DelSp	 1316	//(internal1_m517_DelSp) DelSp - время переключения скоростей
#define internal1_m517_z0	 BUFFER[6425]	//(internal1_m517_z0) z0 - точка прекращения движения
#define idinternal1_m517_z0	 1317	//(internal1_m517_z0) z0 - точка прекращения движения
#define internal1_m517_txZS	 BUFFER[6430]	//(internal1_m517_txZS) txZS
#define idinternal1_m517_txZS	 1318	//(internal1_m517_txZS) txZS
#define internal1_m517_tx	 BUFFER[6435]	//(internal1_m517_tx) tx
#define idinternal1_m517_tx	 1319	//(internal1_m517_tx) tx
#define internal1_m517_txd	 BUFFER[6440]	//(internal1_m517_txd) txd
#define idinternal1_m517_txd	 1320	//(internal1_m517_txd) txd
#define internal1_m517_txMBl	 BUFFER[6445]	//(internal1_m517_txMBl) tx
#define idinternal1_m517_txMBl	 1321	//(internal1_m517_txMBl) tx
#define internal1_m517_txBl	 BUFFER[6450]	//(internal1_m517_txBl) tx
#define idinternal1_m517_txBl	 1322	//(internal1_m517_txBl) tx
#define internal1_m517_Speed0	 BUFFER[6455]	//(internal1_m517_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m517_Speed0	 1323	//(internal1_m517_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m517_xz0	 BUFFER[6460]	//(internal1_m517_xz0) xz0 - новое задание мм
#define idinternal1_m517_xz0	 1324	//(internal1_m517_xz0) xz0 - новое задание мм
#define internal1_m517_tz0	 BUFFER[6465]	//(internal1_m517_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m517_tz0	 1325	//(internal1_m517_tz0) tz0 - время защиты от нового задания сек
#define internal1_m517_Shift0	 BUFFER[6470]	//(internal1_m517_Shift0) Shift0 - признак самохода
#define idinternal1_m517_Shift0	 1326	//(internal1_m517_Shift0) Shift0 - признак самохода
#define internal1_m517_ShCntlSp0	 BUFFER[6472]	//(internal1_m517_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m517_ShCntlSp0	 1327	//(internal1_m517_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m517_ShiftControl	 BUFFER[6474]	//(internal1_m517_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m517_ShiftControl	 1328	//(internal1_m517_ShiftControl) ShiftControl - признак самохода
#define internal1_m616_q0	 BUFFER[6476]	//(internal1_m616_q0) q0 - внутренний параметр
#define idinternal1_m616_q0	 1329	//(internal1_m616_q0) q0 - внутренний параметр
#define internal1_m168_X0	 BUFFER[6478]	//(internal1_m168_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m168_X0	 1330	//(internal1_m168_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m168_t0	 BUFFER[6483]	//(internal1_m168_t0) время нахождения в зоне возврата
#define idinternal1_m168_t0	 1331	//(internal1_m168_t0) время нахождения в зоне возврата
#define internal1_m168_BLDv0	 BUFFER[6488]	//(internal1_m168_BLDv0) BlDv - Блокировка движения
#define idinternal1_m168_BLDv0	 1332	//(internal1_m168_BLDv0) BlDv - Блокировка движения
#define internal1_m197_xptr	 BUFFER[6489]	//(internal1_m197_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m197_xptr	 1333	//(internal1_m197_xptr) указатель текущей позиции в массиве координат
#define internal1_m197_x0	 BUFFER[6492]	//(internal1_m197_x0) x0 - массив мгновенных значений координат
#define idinternal1_m197_x0	 1334	//(internal1_m197_x0) x0 - массив мгновенных значений координат
#define internal1_m197_tim0	 BUFFER[7242]	//(internal1_m197_tim0) tim0 - массив значений времени цикла
#define idinternal1_m197_tim0	 1335	//(internal1_m197_tim0) tim0 - массив значений времени цикла
#define internal1_m197_sumtim	 BUFFER[7992]	//(internal1_m197_sumtim) sumtim - время в пути
#define idinternal1_m197_sumtim	 1336	//(internal1_m197_sumtim) sumtim - время в пути
#define internal1_m197_StSpeed	 BUFFER[7997]	//(internal1_m197_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m197_StSpeed	 1337	//(internal1_m197_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m197_Vz0	 BUFFER[8002]	//(internal1_m197_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m197_Vz0	 1338	//(internal1_m197_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m197_flRazg	 BUFFER[8007]	//(internal1_m197_flRazg) признак разгона/торможения
#define idinternal1_m197_flRazg	 1339	//(internal1_m197_flRazg) признак разгона/торможения
#define internal1_m197_DelSp	 BUFFER[8010]	//(internal1_m197_DelSp) DelSp - время переключения скоростей
#define idinternal1_m197_DelSp	 1340	//(internal1_m197_DelSp) DelSp - время переключения скоростей
#define internal1_m197_z0	 BUFFER[8015]	//(internal1_m197_z0) z0 - точка прекращения движения
#define idinternal1_m197_z0	 1341	//(internal1_m197_z0) z0 - точка прекращения движения
#define internal1_m197_txZS	 BUFFER[8020]	//(internal1_m197_txZS) txZS
#define idinternal1_m197_txZS	 1342	//(internal1_m197_txZS) txZS
#define internal1_m197_tx	 BUFFER[8025]	//(internal1_m197_tx) tx
#define idinternal1_m197_tx	 1343	//(internal1_m197_tx) tx
#define internal1_m197_txd	 BUFFER[8030]	//(internal1_m197_txd) txd
#define idinternal1_m197_txd	 1344	//(internal1_m197_txd) txd
#define internal1_m197_txMBl	 BUFFER[8035]	//(internal1_m197_txMBl) tx
#define idinternal1_m197_txMBl	 1345	//(internal1_m197_txMBl) tx
#define internal1_m197_txBl	 BUFFER[8040]	//(internal1_m197_txBl) tx
#define idinternal1_m197_txBl	 1346	//(internal1_m197_txBl) tx
#define internal1_m197_Speed0	 BUFFER[8045]	//(internal1_m197_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m197_Speed0	 1347	//(internal1_m197_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m197_xz0	 BUFFER[8050]	//(internal1_m197_xz0) xz0 - новое задание мм
#define idinternal1_m197_xz0	 1348	//(internal1_m197_xz0) xz0 - новое задание мм
#define internal1_m197_tz0	 BUFFER[8055]	//(internal1_m197_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m197_tz0	 1349	//(internal1_m197_tz0) tz0 - время защиты от нового задания сек
#define internal1_m197_Shift0	 BUFFER[8060]	//(internal1_m197_Shift0) Shift0 - признак самохода
#define idinternal1_m197_Shift0	 1350	//(internal1_m197_Shift0) Shift0 - признак самохода
#define internal1_m197_ShCntlSp0	 BUFFER[8062]	//(internal1_m197_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m197_ShCntlSp0	 1351	//(internal1_m197_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m197_ShiftControl	 BUFFER[8064]	//(internal1_m197_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m197_ShiftControl	 1352	//(internal1_m197_ShiftControl) ShiftControl - признак самохода
#define internal1_m642_q0	 BUFFER[8066]	//(internal1_m642_q0) q0 - внутренний параметр
#define idinternal1_m642_q0	 1353	//(internal1_m642_q0) q0 - внутренний параметр
#define internal1_m461_DvUp0	 BUFFER[8068]	//(internal1_m461_DvUp0) - есть команда на движение вперёд
#define idinternal1_m461_DvUp0	 1354	//(internal1_m461_DvUp0) - есть команда на движение вперёд
#define internal1_m461_DvDw0	 BUFFER[8069]	//(internal1_m461_DvDw0) - есть команда на движение назад
#define idinternal1_m461_DvDw0	 1355	//(internal1_m461_DvDw0) - есть команда на движение назад
#define internal1_m461_FDvUp0	 BUFFER[8070]	//(internal1_m461_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m461_FDvUp0	 1356	//(internal1_m461_FDvUp0) - есть команда на движение вперёд
#define internal1_m461_FDvDw0	 BUFFER[8071]	//(internal1_m461_FDvDw0) - есть команда на движение назад
#define idinternal1_m461_FDvDw0	 1357	//(internal1_m461_FDvDw0) - есть команда на движение назад
#define internal1_m461_BlDv0	 BUFFER[8072]	//(internal1_m461_BlDv0) - была блокировка
#define idinternal1_m461_BlDv0	 1358	//(internal1_m461_BlDv0) - была блокировка
#define internal1_m461_Pkv0	 BUFFER[8073]	//(internal1_m461_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m461_Pkv0	 1359	//(internal1_m461_Pkv0) Pkv - передний конечный выключатель
#define internal1_m461_Pkav0	 BUFFER[8074]	//(internal1_m461_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m461_Pkav0	 1360	//(internal1_m461_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m461_Zkv0	 BUFFER[8075]	//(internal1_m461_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m461_Zkv0	 1361	//(internal1_m461_Zkv0) Zkv - задний конечный выключатель
#define internal1_m461_Zkav0	 BUFFER[8076]	//(internal1_m461_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m461_Zkav0	 1362	//(internal1_m461_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m461_txNm	 BUFFER[8077]	//(internal1_m461_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m461_txNm	 1363	//(internal1_m461_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m461_txSm	 BUFFER[8082]	//(internal1_m461_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m461_txSm	 1364	//(internal1_m461_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m461_txHr	 BUFFER[8087]	//(internal1_m461_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m461_txHr	 1365	//(internal1_m461_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m461_txLd	 BUFFER[8092]	//(internal1_m461_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m461_txLd	 1366	//(internal1_m461_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m461_fef	 BUFFER[8097]	//(internal1_m461_fef) fef
#define idinternal1_m461_fef	 1367	//(internal1_m461_fef) fef
#define internal1_m455_DvUp0	 BUFFER[8098]	//(internal1_m455_DvUp0) - есть команда на движение вперёд
#define idinternal1_m455_DvUp0	 1368	//(internal1_m455_DvUp0) - есть команда на движение вперёд
#define internal1_m455_DvDw0	 BUFFER[8099]	//(internal1_m455_DvDw0) - есть команда на движение назад
#define idinternal1_m455_DvDw0	 1369	//(internal1_m455_DvDw0) - есть команда на движение назад
#define internal1_m455_FDvUp0	 BUFFER[8100]	//(internal1_m455_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m455_FDvUp0	 1370	//(internal1_m455_FDvUp0) - есть команда на движение вперёд
#define internal1_m455_FDvDw0	 BUFFER[8101]	//(internal1_m455_FDvDw0) - есть команда на движение назад
#define idinternal1_m455_FDvDw0	 1371	//(internal1_m455_FDvDw0) - есть команда на движение назад
#define internal1_m455_BlDv0	 BUFFER[8102]	//(internal1_m455_BlDv0) - была блокировка
#define idinternal1_m455_BlDv0	 1372	//(internal1_m455_BlDv0) - была блокировка
#define internal1_m455_Pkv0	 BUFFER[8103]	//(internal1_m455_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m455_Pkv0	 1373	//(internal1_m455_Pkv0) Pkv - передний конечный выключатель
#define internal1_m455_Pkav0	 BUFFER[8104]	//(internal1_m455_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m455_Pkav0	 1374	//(internal1_m455_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m455_Zkv0	 BUFFER[8105]	//(internal1_m455_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m455_Zkv0	 1375	//(internal1_m455_Zkv0) Zkv - задний конечный выключатель
#define internal1_m455_Zkav0	 BUFFER[8106]	//(internal1_m455_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m455_Zkav0	 1376	//(internal1_m455_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m455_txNm	 BUFFER[8107]	//(internal1_m455_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m455_txNm	 1377	//(internal1_m455_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m455_txSm	 BUFFER[8112]	//(internal1_m455_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m455_txSm	 1378	//(internal1_m455_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m455_txHr	 BUFFER[8117]	//(internal1_m455_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m455_txHr	 1379	//(internal1_m455_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m455_txLd	 BUFFER[8122]	//(internal1_m455_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m455_txLd	 1380	//(internal1_m455_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m455_fef	 BUFFER[8127]	//(internal1_m455_fef) fef
#define idinternal1_m455_fef	 1381	//(internal1_m455_fef) fef
#define internal1_m808_X0	 BUFFER[8128]	//(internal1_m808_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m808_X0	 1382	//(internal1_m808_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m808_t0	 BUFFER[8133]	//(internal1_m808_t0) время нахождения в зоне возврата
#define idinternal1_m808_t0	 1383	//(internal1_m808_t0) время нахождения в зоне возврата
#define internal1_m808_BLDv0	 BUFFER[8138]	//(internal1_m808_BLDv0) BlDv - Блокировка движения
#define idinternal1_m808_BLDv0	 1384	//(internal1_m808_BLDv0) BlDv - Блокировка движения
#define internal1_m831_xptr	 BUFFER[8139]	//(internal1_m831_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m831_xptr	 1385	//(internal1_m831_xptr) указатель текущей позиции в массиве координат
#define internal1_m831_x0	 BUFFER[8142]	//(internal1_m831_x0) x0 - массив мгновенных значений координат
#define idinternal1_m831_x0	 1386	//(internal1_m831_x0) x0 - массив мгновенных значений координат
#define internal1_m831_tim0	 BUFFER[8542]	//(internal1_m831_tim0) tim0 - массив значений времени цикла
#define idinternal1_m831_tim0	 1387	//(internal1_m831_tim0) tim0 - массив значений времени цикла
#define internal1_m831_sumtim	 BUFFER[8942]	//(internal1_m831_sumtim) sumtim - время в пути
#define idinternal1_m831_sumtim	 1388	//(internal1_m831_sumtim) sumtim - время в пути
#define internal1_m831_StSpeed	 BUFFER[8947]	//(internal1_m831_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m831_StSpeed	 1389	//(internal1_m831_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m831_Vz0	 BUFFER[8952]	//(internal1_m831_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m831_Vz0	 1390	//(internal1_m831_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m831_flRazg	 BUFFER[8957]	//(internal1_m831_flRazg) признак разгона/торможения
#define idinternal1_m831_flRazg	 1391	//(internal1_m831_flRazg) признак разгона/торможения
#define internal1_m831_DelSp	 BUFFER[8960]	//(internal1_m831_DelSp) DelSp - время переключения скоростей
#define idinternal1_m831_DelSp	 1392	//(internal1_m831_DelSp) DelSp - время переключения скоростей
#define internal1_m831_z0	 BUFFER[8965]	//(internal1_m831_z0) z0 - точка прекращения движения
#define idinternal1_m831_z0	 1393	//(internal1_m831_z0) z0 - точка прекращения движения
#define internal1_m831_txZS	 BUFFER[8970]	//(internal1_m831_txZS) txZS
#define idinternal1_m831_txZS	 1394	//(internal1_m831_txZS) txZS
#define internal1_m831_tx	 BUFFER[8975]	//(internal1_m831_tx) tx
#define idinternal1_m831_tx	 1395	//(internal1_m831_tx) tx
#define internal1_m831_txd	 BUFFER[8980]	//(internal1_m831_txd) txd
#define idinternal1_m831_txd	 1396	//(internal1_m831_txd) txd
#define internal1_m831_txMBl	 BUFFER[8985]	//(internal1_m831_txMBl) tx
#define idinternal1_m831_txMBl	 1397	//(internal1_m831_txMBl) tx
#define internal1_m831_txBl	 BUFFER[8990]	//(internal1_m831_txBl) tx
#define idinternal1_m831_txBl	 1398	//(internal1_m831_txBl) tx
#define internal1_m831_Speed0	 BUFFER[8995]	//(internal1_m831_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m831_Speed0	 1399	//(internal1_m831_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m831_xz0	 BUFFER[9000]	//(internal1_m831_xz0) xz0 - новое задание мм
#define idinternal1_m831_xz0	 1400	//(internal1_m831_xz0) xz0 - новое задание мм
#define internal1_m831_tz0	 BUFFER[9005]	//(internal1_m831_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m831_tz0	 1401	//(internal1_m831_tz0) tz0 - время защиты от нового задания сек
#define internal1_m831_Shift0	 BUFFER[9010]	//(internal1_m831_Shift0) Shift0 - признак самохода
#define idinternal1_m831_Shift0	 1402	//(internal1_m831_Shift0) Shift0 - признак самохода
#define internal1_m831_ShCntlSp0	 BUFFER[9012]	//(internal1_m831_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m831_ShCntlSp0	 1403	//(internal1_m831_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m831_ShiftControl	 BUFFER[9014]	//(internal1_m831_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m831_ShiftControl	 1404	//(internal1_m831_ShiftControl) ShiftControl - признак самохода
#define internal1_m1580_X0	 BUFFER[9016]	//(internal1_m1580_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1580_X0	 1405	//(internal1_m1580_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1580_t0	 BUFFER[9021]	//(internal1_m1580_t0) время нахождения в зоне возврата
#define idinternal1_m1580_t0	 1406	//(internal1_m1580_t0) время нахождения в зоне возврата
#define internal1_m1580_BLDv0	 BUFFER[9026]	//(internal1_m1580_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1580_BLDv0	 1407	//(internal1_m1580_BLDv0) BlDv - Блокировка движения
#define internal1_m1113_X0	 BUFFER[9027]	//(internal1_m1113_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1113_X0	 1408	//(internal1_m1113_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1113_t0	 BUFFER[9032]	//(internal1_m1113_t0) время нахождения в зоне возврата
#define idinternal1_m1113_t0	 1409	//(internal1_m1113_t0) время нахождения в зоне возврата
#define internal1_m1113_BLDv0	 BUFFER[9037]	//(internal1_m1113_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1113_BLDv0	 1410	//(internal1_m1113_BLDv0) BlDv - Блокировка движения
#define internal1_m614_q0	 BUFFER[9038]	//(internal1_m614_q0) q0 - внутренний параметр
#define idinternal1_m614_q0	 1411	//(internal1_m614_q0) q0 - внутренний параметр
#define internal1_m1197_X0	 BUFFER[9040]	//(internal1_m1197_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1197_X0	 1412	//(internal1_m1197_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1197_t0	 BUFFER[9045]	//(internal1_m1197_t0) время нахождения в зоне возврата
#define idinternal1_m1197_t0	 1413	//(internal1_m1197_t0) время нахождения в зоне возврата
#define internal1_m1197_BLDv0	 BUFFER[9050]	//(internal1_m1197_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1197_BLDv0	 1414	//(internal1_m1197_BLDv0) BlDv - Блокировка движения
#define internal1_m1227_tx	 BUFFER[9051]	//(internal1_m1227_tx) tx - время накопленное сек
#define idinternal1_m1227_tx	 1415	//(internal1_m1227_tx) tx - время накопленное сек
#define internal1_m1227_y0	 BUFFER[9056]	//(internal1_m1227_y0) y0
#define idinternal1_m1227_y0	 1416	//(internal1_m1227_y0) y0
#define internal1_m1226_tx	 BUFFER[9057]	//(internal1_m1226_tx) tx - время накопленное сек
#define idinternal1_m1226_tx	 1417	//(internal1_m1226_tx) tx - время накопленное сек
#define internal1_m1226_y0	 BUFFER[9062]	//(internal1_m1226_y0) y0
#define idinternal1_m1226_y0	 1418	//(internal1_m1226_y0) y0
#define internal1_m1230_xptr	 BUFFER[9063]	//(internal1_m1230_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1230_xptr	 1419	//(internal1_m1230_xptr) указатель текущей позиции в массиве координат
#define internal1_m1230_x0	 BUFFER[9066]	//(internal1_m1230_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1230_x0	 1420	//(internal1_m1230_x0) x0 - массив мгновенных значений координат
#define internal1_m1230_tim0	 BUFFER[9466]	//(internal1_m1230_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1230_tim0	 1421	//(internal1_m1230_tim0) tim0 - массив значений времени цикла
#define internal1_m1230_sumtim	 BUFFER[9866]	//(internal1_m1230_sumtim) sumtim - время в пути
#define idinternal1_m1230_sumtim	 1422	//(internal1_m1230_sumtim) sumtim - время в пути
#define internal1_m1230_StSpeed	 BUFFER[9871]	//(internal1_m1230_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1230_StSpeed	 1423	//(internal1_m1230_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1230_Vz0	 BUFFER[9876]	//(internal1_m1230_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1230_Vz0	 1424	//(internal1_m1230_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1230_flRazg	 BUFFER[9881]	//(internal1_m1230_flRazg) признак разгона/торможения
#define idinternal1_m1230_flRazg	 1425	//(internal1_m1230_flRazg) признак разгона/торможения
#define internal1_m1230_DelSp	 BUFFER[9884]	//(internal1_m1230_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1230_DelSp	 1426	//(internal1_m1230_DelSp) DelSp - время переключения скоростей
#define internal1_m1230_z0	 BUFFER[9889]	//(internal1_m1230_z0) z0 - точка прекращения движения
#define idinternal1_m1230_z0	 1427	//(internal1_m1230_z0) z0 - точка прекращения движения
#define internal1_m1230_txZS	 BUFFER[9894]	//(internal1_m1230_txZS) txZS
#define idinternal1_m1230_txZS	 1428	//(internal1_m1230_txZS) txZS
#define internal1_m1230_tx	 BUFFER[9899]	//(internal1_m1230_tx) tx
#define idinternal1_m1230_tx	 1429	//(internal1_m1230_tx) tx
#define internal1_m1230_txd	 BUFFER[9904]	//(internal1_m1230_txd) txd
#define idinternal1_m1230_txd	 1430	//(internal1_m1230_txd) txd
#define internal1_m1230_txMBl	 BUFFER[9909]	//(internal1_m1230_txMBl) tx
#define idinternal1_m1230_txMBl	 1431	//(internal1_m1230_txMBl) tx
#define internal1_m1230_txBl	 BUFFER[9914]	//(internal1_m1230_txBl) tx
#define idinternal1_m1230_txBl	 1432	//(internal1_m1230_txBl) tx
#define internal1_m1230_Speed0	 BUFFER[9919]	//(internal1_m1230_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1230_Speed0	 1433	//(internal1_m1230_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1230_xz0	 BUFFER[9924]	//(internal1_m1230_xz0) xz0 - новое задание мм
#define idinternal1_m1230_xz0	 1434	//(internal1_m1230_xz0) xz0 - новое задание мм
#define internal1_m1230_tz0	 BUFFER[9929]	//(internal1_m1230_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1230_tz0	 1435	//(internal1_m1230_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1230_Shift0	 BUFFER[9934]	//(internal1_m1230_Shift0) Shift0 - признак самохода
#define idinternal1_m1230_Shift0	 1436	//(internal1_m1230_Shift0) Shift0 - признак самохода
#define internal1_m1230_ShCntlSp0	 BUFFER[9936]	//(internal1_m1230_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1230_ShCntlSp0	 1437	//(internal1_m1230_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1230_ShiftControl	 BUFFER[9938]	//(internal1_m1230_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1230_ShiftControl	 1438	//(internal1_m1230_ShiftControl) ShiftControl - признак самохода
#define internal1_m634_q0	 BUFFER[9940]	//(internal1_m634_q0) q0 - внутренний параметр
#define idinternal1_m634_q0	 1439	//(internal1_m634_q0) q0 - внутренний параметр
#define internal1_m1593_tx	 BUFFER[9942]	//(internal1_m1593_tx) tx - время накопленное сек
#define idinternal1_m1593_tx	 1440	//(internal1_m1593_tx) tx - время накопленное сек
#define internal1_m1593_y0	 BUFFER[9947]	//(internal1_m1593_y0) y0
#define idinternal1_m1593_y0	 1441	//(internal1_m1593_y0) y0
#define internal1_m1597_tx	 BUFFER[9948]	//(internal1_m1597_tx) tx - время накопленное сек
#define idinternal1_m1597_tx	 1442	//(internal1_m1597_tx) tx - время накопленное сек
#define internal1_m1597_y0	 BUFFER[9953]	//(internal1_m1597_y0) y0
#define idinternal1_m1597_y0	 1443	//(internal1_m1597_y0) y0
#define internal1_m1583_DvUp0	 BUFFER[9954]	//(internal1_m1583_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1583_DvUp0	 1444	//(internal1_m1583_DvUp0) - есть команда на движение вперёд
#define internal1_m1583_DvDw0	 BUFFER[9955]	//(internal1_m1583_DvDw0) - есть команда на движение назад
#define idinternal1_m1583_DvDw0	 1445	//(internal1_m1583_DvDw0) - есть команда на движение назад
#define internal1_m1583_FDvUp0	 BUFFER[9956]	//(internal1_m1583_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1583_FDvUp0	 1446	//(internal1_m1583_FDvUp0) - есть команда на движение вперёд
#define internal1_m1583_FDvDw0	 BUFFER[9957]	//(internal1_m1583_FDvDw0) - есть команда на движение назад
#define idinternal1_m1583_FDvDw0	 1447	//(internal1_m1583_FDvDw0) - есть команда на движение назад
#define internal1_m1583_BlDv0	 BUFFER[9958]	//(internal1_m1583_BlDv0) - была блокировка
#define idinternal1_m1583_BlDv0	 1448	//(internal1_m1583_BlDv0) - была блокировка
#define internal1_m1583_Pkv0	 BUFFER[9959]	//(internal1_m1583_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1583_Pkv0	 1449	//(internal1_m1583_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1583_Pkav0	 BUFFER[9960]	//(internal1_m1583_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1583_Pkav0	 1450	//(internal1_m1583_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1583_Zkv0	 BUFFER[9961]	//(internal1_m1583_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1583_Zkv0	 1451	//(internal1_m1583_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1583_Zkav0	 BUFFER[9962]	//(internal1_m1583_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1583_Zkav0	 1452	//(internal1_m1583_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1583_txNm	 BUFFER[9963]	//(internal1_m1583_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1583_txNm	 1453	//(internal1_m1583_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1583_txSm	 BUFFER[9968]	//(internal1_m1583_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1583_txSm	 1454	//(internal1_m1583_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1583_txHr	 BUFFER[9973]	//(internal1_m1583_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1583_txHr	 1455	//(internal1_m1583_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1583_txLd	 BUFFER[9978]	//(internal1_m1583_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1583_txLd	 1456	//(internal1_m1583_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1583_fef	 BUFFER[9983]	//(internal1_m1583_fef) fef
#define idinternal1_m1583_fef	 1457	//(internal1_m1583_fef) fef
#define internal1_m1600_xptr	 BUFFER[9984]	//(internal1_m1600_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1600_xptr	 1458	//(internal1_m1600_xptr) указатель текущей позиции в массиве координат
#define internal1_m1600_x0	 BUFFER[9987]	//(internal1_m1600_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1600_x0	 1459	//(internal1_m1600_x0) x0 - массив мгновенных значений координат
#define internal1_m1600_tim0	 BUFFER[10087]	//(internal1_m1600_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1600_tim0	 1460	//(internal1_m1600_tim0) tim0 - массив значений времени цикла
#define internal1_m1600_sumtim	 BUFFER[10187]	//(internal1_m1600_sumtim) sumtim - время в пути
#define idinternal1_m1600_sumtim	 1461	//(internal1_m1600_sumtim) sumtim - время в пути
#define internal1_m1600_StSpeed	 BUFFER[10192]	//(internal1_m1600_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1600_StSpeed	 1462	//(internal1_m1600_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1600_Vz0	 BUFFER[10197]	//(internal1_m1600_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1600_Vz0	 1463	//(internal1_m1600_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1600_flRazg	 BUFFER[10202]	//(internal1_m1600_flRazg) признак разгона/торможения
#define idinternal1_m1600_flRazg	 1464	//(internal1_m1600_flRazg) признак разгона/торможения
#define internal1_m1600_DelSp	 BUFFER[10205]	//(internal1_m1600_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1600_DelSp	 1465	//(internal1_m1600_DelSp) DelSp - время переключения скоростей
#define internal1_m1600_z0	 BUFFER[10210]	//(internal1_m1600_z0) z0 - точка прекращения движения
#define idinternal1_m1600_z0	 1466	//(internal1_m1600_z0) z0 - точка прекращения движения
#define internal1_m1600_txZS	 BUFFER[10215]	//(internal1_m1600_txZS) txZS
#define idinternal1_m1600_txZS	 1467	//(internal1_m1600_txZS) txZS
#define internal1_m1600_tx	 BUFFER[10220]	//(internal1_m1600_tx) tx
#define idinternal1_m1600_tx	 1468	//(internal1_m1600_tx) tx
#define internal1_m1600_txd	 BUFFER[10225]	//(internal1_m1600_txd) txd
#define idinternal1_m1600_txd	 1469	//(internal1_m1600_txd) txd
#define internal1_m1600_txMBl	 BUFFER[10230]	//(internal1_m1600_txMBl) tx
#define idinternal1_m1600_txMBl	 1470	//(internal1_m1600_txMBl) tx
#define internal1_m1600_txBl	 BUFFER[10235]	//(internal1_m1600_txBl) tx
#define idinternal1_m1600_txBl	 1471	//(internal1_m1600_txBl) tx
#define internal1_m1600_Speed0	 BUFFER[10240]	//(internal1_m1600_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1600_Speed0	 1472	//(internal1_m1600_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1600_xz0	 BUFFER[10245]	//(internal1_m1600_xz0) xz0 - новое задание мм
#define idinternal1_m1600_xz0	 1473	//(internal1_m1600_xz0) xz0 - новое задание мм
#define internal1_m1600_tz0	 BUFFER[10250]	//(internal1_m1600_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1600_tz0	 1474	//(internal1_m1600_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1600_Shift0	 BUFFER[10255]	//(internal1_m1600_Shift0) Shift0 - признак самохода
#define idinternal1_m1600_Shift0	 1475	//(internal1_m1600_Shift0) Shift0 - признак самохода
#define internal1_m1600_ShCntlSp0	 BUFFER[10257]	//(internal1_m1600_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1600_ShCntlSp0	 1476	//(internal1_m1600_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1600_ShiftControl	 BUFFER[10259]	//(internal1_m1600_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1600_ShiftControl	 1477	//(internal1_m1600_ShiftControl) ShiftControl - признак самохода
#define internal1_m1128_tx	 BUFFER[10261]	//(internal1_m1128_tx) tx - время накопленное сек
#define idinternal1_m1128_tx	 1478	//(internal1_m1128_tx) tx - время накопленное сек
#define internal1_m1128_y0	 BUFFER[10266]	//(internal1_m1128_y0) y0
#define idinternal1_m1128_y0	 1479	//(internal1_m1128_y0) y0
#define internal1_m1132_tx	 BUFFER[10267]	//(internal1_m1132_tx) tx - время накопленное сек
#define idinternal1_m1132_tx	 1480	//(internal1_m1132_tx) tx - время накопленное сек
#define internal1_m1132_y0	 BUFFER[10272]	//(internal1_m1132_y0) y0
#define idinternal1_m1132_y0	 1481	//(internal1_m1132_y0) y0
#define internal1_m624_q0	 BUFFER[10273]	//(internal1_m624_q0) q0 - внутренний параметр
#define idinternal1_m624_q0	 1482	//(internal1_m624_q0) q0 - внутренний параметр
#define internal1_m589_q0	 BUFFER[10275]	//(internal1_m589_q0) q0 - внутренний параметр
#define idinternal1_m589_q0	 1483	//(internal1_m589_q0) q0 - внутренний параметр
#define internal1_m1118_DvUp0	 BUFFER[10277]	//(internal1_m1118_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1118_DvUp0	 1484	//(internal1_m1118_DvUp0) - есть команда на движение вперёд
#define internal1_m1118_DvDw0	 BUFFER[10278]	//(internal1_m1118_DvDw0) - есть команда на движение назад
#define idinternal1_m1118_DvDw0	 1485	//(internal1_m1118_DvDw0) - есть команда на движение назад
#define internal1_m1118_FDvUp0	 BUFFER[10279]	//(internal1_m1118_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1118_FDvUp0	 1486	//(internal1_m1118_FDvUp0) - есть команда на движение вперёд
#define internal1_m1118_FDvDw0	 BUFFER[10280]	//(internal1_m1118_FDvDw0) - есть команда на движение назад
#define idinternal1_m1118_FDvDw0	 1487	//(internal1_m1118_FDvDw0) - есть команда на движение назад
#define internal1_m1118_BlDv0	 BUFFER[10281]	//(internal1_m1118_BlDv0) - была блокировка
#define idinternal1_m1118_BlDv0	 1488	//(internal1_m1118_BlDv0) - была блокировка
#define internal1_m1118_Pkv0	 BUFFER[10282]	//(internal1_m1118_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1118_Pkv0	 1489	//(internal1_m1118_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1118_Pkav0	 BUFFER[10283]	//(internal1_m1118_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1118_Pkav0	 1490	//(internal1_m1118_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1118_Zkv0	 BUFFER[10284]	//(internal1_m1118_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1118_Zkv0	 1491	//(internal1_m1118_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1118_Zkav0	 BUFFER[10285]	//(internal1_m1118_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1118_Zkav0	 1492	//(internal1_m1118_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1118_txNm	 BUFFER[10286]	//(internal1_m1118_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1118_txNm	 1493	//(internal1_m1118_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1118_txSm	 BUFFER[10291]	//(internal1_m1118_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1118_txSm	 1494	//(internal1_m1118_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1118_txHr	 BUFFER[10296]	//(internal1_m1118_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1118_txHr	 1495	//(internal1_m1118_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1118_txLd	 BUFFER[10301]	//(internal1_m1118_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1118_txLd	 1496	//(internal1_m1118_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1118_fef	 BUFFER[10306]	//(internal1_m1118_fef) fef
#define idinternal1_m1118_fef	 1497	//(internal1_m1118_fef) fef
#define internal1_m1136_xptr	 BUFFER[10307]	//(internal1_m1136_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1136_xptr	 1498	//(internal1_m1136_xptr) указатель текущей позиции в массиве координат
#define internal1_m1136_x0	 BUFFER[10310]	//(internal1_m1136_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1136_x0	 1499	//(internal1_m1136_x0) x0 - массив мгновенных значений координат
#define internal1_m1136_tim0	 BUFFER[10410]	//(internal1_m1136_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1136_tim0	 1500	//(internal1_m1136_tim0) tim0 - массив значений времени цикла
#define internal1_m1136_sumtim	 BUFFER[10510]	//(internal1_m1136_sumtim) sumtim - время в пути
#define idinternal1_m1136_sumtim	 1501	//(internal1_m1136_sumtim) sumtim - время в пути
#define internal1_m1136_StSpeed	 BUFFER[10515]	//(internal1_m1136_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1136_StSpeed	 1502	//(internal1_m1136_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1136_Vz0	 BUFFER[10520]	//(internal1_m1136_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1136_Vz0	 1503	//(internal1_m1136_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1136_flRazg	 BUFFER[10525]	//(internal1_m1136_flRazg) признак разгона/торможения
#define idinternal1_m1136_flRazg	 1504	//(internal1_m1136_flRazg) признак разгона/торможения
#define internal1_m1136_DelSp	 BUFFER[10528]	//(internal1_m1136_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1136_DelSp	 1505	//(internal1_m1136_DelSp) DelSp - время переключения скоростей
#define internal1_m1136_z0	 BUFFER[10533]	//(internal1_m1136_z0) z0 - точка прекращения движения
#define idinternal1_m1136_z0	 1506	//(internal1_m1136_z0) z0 - точка прекращения движения
#define internal1_m1136_txZS	 BUFFER[10538]	//(internal1_m1136_txZS) txZS
#define idinternal1_m1136_txZS	 1507	//(internal1_m1136_txZS) txZS
#define internal1_m1136_tx	 BUFFER[10543]	//(internal1_m1136_tx) tx
#define idinternal1_m1136_tx	 1508	//(internal1_m1136_tx) tx
#define internal1_m1136_txd	 BUFFER[10548]	//(internal1_m1136_txd) txd
#define idinternal1_m1136_txd	 1509	//(internal1_m1136_txd) txd
#define internal1_m1136_txMBl	 BUFFER[10553]	//(internal1_m1136_txMBl) tx
#define idinternal1_m1136_txMBl	 1510	//(internal1_m1136_txMBl) tx
#define internal1_m1136_txBl	 BUFFER[10558]	//(internal1_m1136_txBl) tx
#define idinternal1_m1136_txBl	 1511	//(internal1_m1136_txBl) tx
#define internal1_m1136_Speed0	 BUFFER[10563]	//(internal1_m1136_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1136_Speed0	 1512	//(internal1_m1136_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1136_xz0	 BUFFER[10568]	//(internal1_m1136_xz0) xz0 - новое задание мм
#define idinternal1_m1136_xz0	 1513	//(internal1_m1136_xz0) xz0 - новое задание мм
#define internal1_m1136_tz0	 BUFFER[10573]	//(internal1_m1136_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1136_tz0	 1514	//(internal1_m1136_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1136_Shift0	 BUFFER[10578]	//(internal1_m1136_Shift0) Shift0 - признак самохода
#define idinternal1_m1136_Shift0	 1515	//(internal1_m1136_Shift0) Shift0 - признак самохода
#define internal1_m1136_ShCntlSp0	 BUFFER[10580]	//(internal1_m1136_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1136_ShCntlSp0	 1516	//(internal1_m1136_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1136_ShiftControl	 BUFFER[10582]	//(internal1_m1136_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1136_ShiftControl	 1517	//(internal1_m1136_ShiftControl) ShiftControl - признак самохода
#define internal1_m737_x0	 BUFFER[10584]	//(internal1_m737_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m737_x0	 1518	//(internal1_m737_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m706_x0	 BUFFER[10586]	//(internal1_m706_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m706_x0	 1519	//(internal1_m706_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m669_x0	 BUFFER[10588]	//(internal1_m669_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m669_x0	 1520	//(internal1_m669_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m762_q0	 BUFFER[10590]	//(internal1_m762_q0) q0 - внутренний параметр
#define idinternal1_m762_q0	 1521	//(internal1_m762_q0) q0 - внутренний параметр
#define internal1_m757_q0	 BUFFER[10592]	//(internal1_m757_q0) q0 - внутренний параметр
#define idinternal1_m757_q0	 1522	//(internal1_m757_q0) q0 - внутренний параметр
#define internal1_m725_q0	 BUFFER[10594]	//(internal1_m725_q0) q0 - внутренний параметр
#define idinternal1_m725_q0	 1523	//(internal1_m725_q0) q0 - внутренний параметр
#define internal1_m727_q0	 BUFFER[10596]	//(internal1_m727_q0) q0 - внутренний параметр
#define idinternal1_m727_q0	 1524	//(internal1_m727_q0) q0 - внутренний параметр
#define internal1_m738_q0	 BUFFER[10598]	//(internal1_m738_q0) q0 - внутренний параметр
#define idinternal1_m738_q0	 1525	//(internal1_m738_q0) q0 - внутренний параметр
#define internal1_m750_q0	 BUFFER[10600]	//(internal1_m750_q0) q0 - внутренний параметр
#define idinternal1_m750_q0	 1526	//(internal1_m750_q0) q0 - внутренний параметр
#define internal1_m729_q0	 BUFFER[10602]	//(internal1_m729_q0) q0 - внутренний параметр
#define idinternal1_m729_q0	 1527	//(internal1_m729_q0) q0 - внутренний параметр
#define internal1_m1174_DvUp0	 BUFFER[10604]	//(internal1_m1174_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1174_DvUp0	 1528	//(internal1_m1174_DvUp0) - есть команда на движение вперёд
#define internal1_m1174_DvDw0	 BUFFER[10605]	//(internal1_m1174_DvDw0) - есть команда на движение назад
#define idinternal1_m1174_DvDw0	 1529	//(internal1_m1174_DvDw0) - есть команда на движение назад
#define internal1_m1174_FDvUp0	 BUFFER[10606]	//(internal1_m1174_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1174_FDvUp0	 1530	//(internal1_m1174_FDvUp0) - есть команда на движение вперёд
#define internal1_m1174_FDvDw0	 BUFFER[10607]	//(internal1_m1174_FDvDw0) - есть команда на движение назад
#define idinternal1_m1174_FDvDw0	 1531	//(internal1_m1174_FDvDw0) - есть команда на движение назад
#define internal1_m1174_BlDv0	 BUFFER[10608]	//(internal1_m1174_BlDv0) - была блокировка
#define idinternal1_m1174_BlDv0	 1532	//(internal1_m1174_BlDv0) - была блокировка
#define internal1_m1174_Pkv0	 BUFFER[10609]	//(internal1_m1174_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1174_Pkv0	 1533	//(internal1_m1174_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1174_Pkav0	 BUFFER[10610]	//(internal1_m1174_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1174_Pkav0	 1534	//(internal1_m1174_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1174_Zkv0	 BUFFER[10611]	//(internal1_m1174_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1174_Zkv0	 1535	//(internal1_m1174_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1174_Zkav0	 BUFFER[10612]	//(internal1_m1174_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1174_Zkav0	 1536	//(internal1_m1174_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1174_txNm	 BUFFER[10613]	//(internal1_m1174_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1174_txNm	 1537	//(internal1_m1174_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1174_txSm	 BUFFER[10618]	//(internal1_m1174_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1174_txSm	 1538	//(internal1_m1174_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1174_txHr	 BUFFER[10623]	//(internal1_m1174_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1174_txHr	 1539	//(internal1_m1174_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1174_txLd	 BUFFER[10628]	//(internal1_m1174_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1174_txLd	 1540	//(internal1_m1174_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1174_fef	 BUFFER[10633]	//(internal1_m1174_fef) fef
#define idinternal1_m1174_fef	 1541	//(internal1_m1174_fef) fef
#define internal1_m1163_DvUp0	 BUFFER[10634]	//(internal1_m1163_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1163_DvUp0	 1542	//(internal1_m1163_DvUp0) - есть команда на движение вперёд
#define internal1_m1163_DvDw0	 BUFFER[10635]	//(internal1_m1163_DvDw0) - есть команда на движение назад
#define idinternal1_m1163_DvDw0	 1543	//(internal1_m1163_DvDw0) - есть команда на движение назад
#define internal1_m1163_FDvUp0	 BUFFER[10636]	//(internal1_m1163_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1163_FDvUp0	 1544	//(internal1_m1163_FDvUp0) - есть команда на движение вперёд
#define internal1_m1163_FDvDw0	 BUFFER[10637]	//(internal1_m1163_FDvDw0) - есть команда на движение назад
#define idinternal1_m1163_FDvDw0	 1545	//(internal1_m1163_FDvDw0) - есть команда на движение назад
#define internal1_m1163_BlDv0	 BUFFER[10638]	//(internal1_m1163_BlDv0) - была блокировка
#define idinternal1_m1163_BlDv0	 1546	//(internal1_m1163_BlDv0) - была блокировка
#define internal1_m1163_Pkv0	 BUFFER[10639]	//(internal1_m1163_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1163_Pkv0	 1547	//(internal1_m1163_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1163_Pkav0	 BUFFER[10640]	//(internal1_m1163_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1163_Pkav0	 1548	//(internal1_m1163_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1163_Zkv0	 BUFFER[10641]	//(internal1_m1163_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1163_Zkv0	 1549	//(internal1_m1163_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1163_Zkav0	 BUFFER[10642]	//(internal1_m1163_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1163_Zkav0	 1550	//(internal1_m1163_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1163_txNm	 BUFFER[10643]	//(internal1_m1163_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1163_txNm	 1551	//(internal1_m1163_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1163_txSm	 BUFFER[10648]	//(internal1_m1163_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1163_txSm	 1552	//(internal1_m1163_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1163_txHr	 BUFFER[10653]	//(internal1_m1163_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1163_txHr	 1553	//(internal1_m1163_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1163_txLd	 BUFFER[10658]	//(internal1_m1163_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1163_txLd	 1554	//(internal1_m1163_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1163_fef	 BUFFER[10663]	//(internal1_m1163_fef) fef
#define idinternal1_m1163_fef	 1555	//(internal1_m1163_fef) fef
#define internal1_m782_DvUp0	 BUFFER[10664]	//(internal1_m782_DvUp0) - есть команда на движение вперёд
#define idinternal1_m782_DvUp0	 1556	//(internal1_m782_DvUp0) - есть команда на движение вперёд
#define internal1_m782_DvDw0	 BUFFER[10665]	//(internal1_m782_DvDw0) - есть команда на движение назад
#define idinternal1_m782_DvDw0	 1557	//(internal1_m782_DvDw0) - есть команда на движение назад
#define internal1_m782_FDvUp0	 BUFFER[10666]	//(internal1_m782_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m782_FDvUp0	 1558	//(internal1_m782_FDvUp0) - есть команда на движение вперёд
#define internal1_m782_FDvDw0	 BUFFER[10667]	//(internal1_m782_FDvDw0) - есть команда на движение назад
#define idinternal1_m782_FDvDw0	 1559	//(internal1_m782_FDvDw0) - есть команда на движение назад
#define internal1_m782_BlDv0	 BUFFER[10668]	//(internal1_m782_BlDv0) - была блокировка
#define idinternal1_m782_BlDv0	 1560	//(internal1_m782_BlDv0) - была блокировка
#define internal1_m782_Pkv0	 BUFFER[10669]	//(internal1_m782_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m782_Pkv0	 1561	//(internal1_m782_Pkv0) Pkv - передний конечный выключатель
#define internal1_m782_Pkav0	 BUFFER[10670]	//(internal1_m782_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m782_Pkav0	 1562	//(internal1_m782_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m782_Zkv0	 BUFFER[10671]	//(internal1_m782_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m782_Zkv0	 1563	//(internal1_m782_Zkv0) Zkv - задний конечный выключатель
#define internal1_m782_Zkav0	 BUFFER[10672]	//(internal1_m782_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m782_Zkav0	 1564	//(internal1_m782_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m782_txNm	 BUFFER[10673]	//(internal1_m782_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m782_txNm	 1565	//(internal1_m782_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m782_txSm	 BUFFER[10678]	//(internal1_m782_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m782_txSm	 1566	//(internal1_m782_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m782_txHr	 BUFFER[10683]	//(internal1_m782_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m782_txHr	 1567	//(internal1_m782_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m782_txLd	 BUFFER[10688]	//(internal1_m782_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m782_txLd	 1568	//(internal1_m782_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m782_fef	 BUFFER[10693]	//(internal1_m782_fef) fef
#define idinternal1_m782_fef	 1569	//(internal1_m782_fef) fef
#define internal1_m778_DvUp0	 BUFFER[10694]	//(internal1_m778_DvUp0) - есть команда на движение вперёд
#define idinternal1_m778_DvUp0	 1570	//(internal1_m778_DvUp0) - есть команда на движение вперёд
#define internal1_m778_DvDw0	 BUFFER[10695]	//(internal1_m778_DvDw0) - есть команда на движение назад
#define idinternal1_m778_DvDw0	 1571	//(internal1_m778_DvDw0) - есть команда на движение назад
#define internal1_m778_FDvUp0	 BUFFER[10696]	//(internal1_m778_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m778_FDvUp0	 1572	//(internal1_m778_FDvUp0) - есть команда на движение вперёд
#define internal1_m778_FDvDw0	 BUFFER[10697]	//(internal1_m778_FDvDw0) - есть команда на движение назад
#define idinternal1_m778_FDvDw0	 1573	//(internal1_m778_FDvDw0) - есть команда на движение назад
#define internal1_m778_BlDv0	 BUFFER[10698]	//(internal1_m778_BlDv0) - была блокировка
#define idinternal1_m778_BlDv0	 1574	//(internal1_m778_BlDv0) - была блокировка
#define internal1_m778_Pkv0	 BUFFER[10699]	//(internal1_m778_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m778_Pkv0	 1575	//(internal1_m778_Pkv0) Pkv - передний конечный выключатель
#define internal1_m778_Pkav0	 BUFFER[10700]	//(internal1_m778_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m778_Pkav0	 1576	//(internal1_m778_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m778_Zkv0	 BUFFER[10701]	//(internal1_m778_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m778_Zkv0	 1577	//(internal1_m778_Zkv0) Zkv - задний конечный выключатель
#define internal1_m778_Zkav0	 BUFFER[10702]	//(internal1_m778_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m778_Zkav0	 1578	//(internal1_m778_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m778_txNm	 BUFFER[10703]	//(internal1_m778_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m778_txNm	 1579	//(internal1_m778_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m778_txSm	 BUFFER[10708]	//(internal1_m778_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m778_txSm	 1580	//(internal1_m778_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m778_txHr	 BUFFER[10713]	//(internal1_m778_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m778_txHr	 1581	//(internal1_m778_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m778_txLd	 BUFFER[10718]	//(internal1_m778_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m778_txLd	 1582	//(internal1_m778_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m778_fef	 BUFFER[10723]	//(internal1_m778_fef) fef
#define idinternal1_m778_fef	 1583	//(internal1_m778_fef) fef
#define internal1_m360_DvUp0	 BUFFER[10724]	//(internal1_m360_DvUp0) - есть команда на движение вперёд
#define idinternal1_m360_DvUp0	 1584	//(internal1_m360_DvUp0) - есть команда на движение вперёд
#define internal1_m360_DvDw0	 BUFFER[10725]	//(internal1_m360_DvDw0) - есть команда на движение назад
#define idinternal1_m360_DvDw0	 1585	//(internal1_m360_DvDw0) - есть команда на движение назад
#define internal1_m360_FDvUp0	 BUFFER[10726]	//(internal1_m360_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m360_FDvUp0	 1586	//(internal1_m360_FDvUp0) - есть команда на движение вперёд
#define internal1_m360_FDvDw0	 BUFFER[10727]	//(internal1_m360_FDvDw0) - есть команда на движение назад
#define idinternal1_m360_FDvDw0	 1587	//(internal1_m360_FDvDw0) - есть команда на движение назад
#define internal1_m360_BlDv0	 BUFFER[10728]	//(internal1_m360_BlDv0) - была блокировка
#define idinternal1_m360_BlDv0	 1588	//(internal1_m360_BlDv0) - была блокировка
#define internal1_m360_Pkv0	 BUFFER[10729]	//(internal1_m360_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m360_Pkv0	 1589	//(internal1_m360_Pkv0) Pkv - передний конечный выключатель
#define internal1_m360_Pkav0	 BUFFER[10730]	//(internal1_m360_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m360_Pkav0	 1590	//(internal1_m360_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m360_Zkv0	 BUFFER[10731]	//(internal1_m360_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m360_Zkv0	 1591	//(internal1_m360_Zkv0) Zkv - задний конечный выключатель
#define internal1_m360_Zkav0	 BUFFER[10732]	//(internal1_m360_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m360_Zkav0	 1592	//(internal1_m360_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m360_txNm	 BUFFER[10733]	//(internal1_m360_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m360_txNm	 1593	//(internal1_m360_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m360_txSm	 BUFFER[10738]	//(internal1_m360_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m360_txSm	 1594	//(internal1_m360_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m360_txHr	 BUFFER[10743]	//(internal1_m360_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m360_txHr	 1595	//(internal1_m360_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m360_txLd	 BUFFER[10748]	//(internal1_m360_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m360_txLd	 1596	//(internal1_m360_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m360_fef	 BUFFER[10753]	//(internal1_m360_fef) fef
#define idinternal1_m360_fef	 1597	//(internal1_m360_fef) fef
#define internal1_m389_DvUp0	 BUFFER[10754]	//(internal1_m389_DvUp0) - есть команда на движение вперёд
#define idinternal1_m389_DvUp0	 1598	//(internal1_m389_DvUp0) - есть команда на движение вперёд
#define internal1_m389_DvDw0	 BUFFER[10755]	//(internal1_m389_DvDw0) - есть команда на движение назад
#define idinternal1_m389_DvDw0	 1599	//(internal1_m389_DvDw0) - есть команда на движение назад
#define internal1_m389_FDvUp0	 BUFFER[10756]	//(internal1_m389_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m389_FDvUp0	 1600	//(internal1_m389_FDvUp0) - есть команда на движение вперёд
#define internal1_m389_FDvDw0	 BUFFER[10757]	//(internal1_m389_FDvDw0) - есть команда на движение назад
#define idinternal1_m389_FDvDw0	 1601	//(internal1_m389_FDvDw0) - есть команда на движение назад
#define internal1_m389_BlDv0	 BUFFER[10758]	//(internal1_m389_BlDv0) - была блокировка
#define idinternal1_m389_BlDv0	 1602	//(internal1_m389_BlDv0) - была блокировка
#define internal1_m389_Pkv0	 BUFFER[10759]	//(internal1_m389_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m389_Pkv0	 1603	//(internal1_m389_Pkv0) Pkv - передний конечный выключатель
#define internal1_m389_Pkav0	 BUFFER[10760]	//(internal1_m389_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m389_Pkav0	 1604	//(internal1_m389_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m389_Zkv0	 BUFFER[10761]	//(internal1_m389_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m389_Zkv0	 1605	//(internal1_m389_Zkv0) Zkv - задний конечный выключатель
#define internal1_m389_Zkav0	 BUFFER[10762]	//(internal1_m389_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m389_Zkav0	 1606	//(internal1_m389_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m389_txNm	 BUFFER[10763]	//(internal1_m389_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m389_txNm	 1607	//(internal1_m389_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m389_txSm	 BUFFER[10768]	//(internal1_m389_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m389_txSm	 1608	//(internal1_m389_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m389_txHr	 BUFFER[10773]	//(internal1_m389_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m389_txHr	 1609	//(internal1_m389_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m389_txLd	 BUFFER[10778]	//(internal1_m389_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m389_txLd	 1610	//(internal1_m389_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m389_fef	 BUFFER[10783]	//(internal1_m389_fef) fef
#define idinternal1_m389_fef	 1611	//(internal1_m389_fef) fef
#define internal1_m383_DvUp0	 BUFFER[10784]	//(internal1_m383_DvUp0) - есть команда на движение вперёд
#define idinternal1_m383_DvUp0	 1612	//(internal1_m383_DvUp0) - есть команда на движение вперёд
#define internal1_m383_DvDw0	 BUFFER[10785]	//(internal1_m383_DvDw0) - есть команда на движение назад
#define idinternal1_m383_DvDw0	 1613	//(internal1_m383_DvDw0) - есть команда на движение назад
#define internal1_m383_FDvUp0	 BUFFER[10786]	//(internal1_m383_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m383_FDvUp0	 1614	//(internal1_m383_FDvUp0) - есть команда на движение вперёд
#define internal1_m383_FDvDw0	 BUFFER[10787]	//(internal1_m383_FDvDw0) - есть команда на движение назад
#define idinternal1_m383_FDvDw0	 1615	//(internal1_m383_FDvDw0) - есть команда на движение назад
#define internal1_m383_BlDv0	 BUFFER[10788]	//(internal1_m383_BlDv0) - была блокировка
#define idinternal1_m383_BlDv0	 1616	//(internal1_m383_BlDv0) - была блокировка
#define internal1_m383_Pkv0	 BUFFER[10789]	//(internal1_m383_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m383_Pkv0	 1617	//(internal1_m383_Pkv0) Pkv - передний конечный выключатель
#define internal1_m383_Pkav0	 BUFFER[10790]	//(internal1_m383_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m383_Pkav0	 1618	//(internal1_m383_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m383_Zkv0	 BUFFER[10791]	//(internal1_m383_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m383_Zkv0	 1619	//(internal1_m383_Zkv0) Zkv - задний конечный выключатель
#define internal1_m383_Zkav0	 BUFFER[10792]	//(internal1_m383_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m383_Zkav0	 1620	//(internal1_m383_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m383_txNm	 BUFFER[10793]	//(internal1_m383_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m383_txNm	 1621	//(internal1_m383_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m383_txSm	 BUFFER[10798]	//(internal1_m383_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m383_txSm	 1622	//(internal1_m383_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m383_txHr	 BUFFER[10803]	//(internal1_m383_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m383_txHr	 1623	//(internal1_m383_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m383_txLd	 BUFFER[10808]	//(internal1_m383_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m383_txLd	 1624	//(internal1_m383_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m383_fef	 BUFFER[10813]	//(internal1_m383_fef) fef
#define idinternal1_m383_fef	 1625	//(internal1_m383_fef) fef
#define internal1_m734_q0	 BUFFER[10814]	//(internal1_m734_q0) q0 - внутренний параметр
#define idinternal1_m734_q0	 1626	//(internal1_m734_q0) q0 - внутренний параметр
#define internal1_m731_q0	 BUFFER[10816]	//(internal1_m731_q0) q0 - внутренний параметр
#define idinternal1_m731_q0	 1627	//(internal1_m731_q0) q0 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &A3VZ15LZ1},	//(vds32:02 - K19VDSR, - ) Имитация срабатывания АЗ от НУП ИС
	{ 2	,1	,1	, &A3VZ15LZ2},	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{ 3	,1	,1	, &B2IS33LDU},	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
	{ 4	,1	,1	, &B3IS31LDU},	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
	{ 5	,1	,1	, &B3IS33LDU},	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
	{ 6	,1	,1	, &B3IS35LDU},	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
	{ 7	,1	,1	, &B4IS10LDU},	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
	{ 8	,1	,1	, &R6IS31LDU},	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
	{ 9	,1	,1	, &R6IS32LDU},	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
	{ 10	,1	,1	, &R6IS42LDU},	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
	{ 11	,1	,1	, &R6IS41LDU},	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
	{ 12	,1	,1	, &R6IS52LDU},	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
	{ 13	,1	,1	, &R6IS51LDU},	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
	{ 14	,1	,1	, &R3IS11LDU},	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
	{ 15	,1	,1	, &R3IS21LDU},	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
	{ 16	,1	,1	, &R0AB03LDU},	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
	{ 17	,1	,1	, &R0AB05LDU},	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
	{ 18	,8	,1	, &R0VN11RZ1},	//( - , MDuBz1) Средняя мощность по BAZ1
	{ 19	,8	,1	, &R0VN11RZ2},	//( - , MDuBz2) Средняя мощность по BAZ2
	{ 20	,1	,1	, &A2AB15LDU},	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{ 21	,1	,1	, &B2AB15LDU},	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{ 22	,1	,1	, &R0AD21LDU},	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
	{ 23	,3	,1	, &B2VS01IDU},	//( - , DU) Готовность к управлению РБ2
	{ 24	,1	,1	, &A7AS31LDU},	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
	{ 25	,1	,1	, &B7AS31LDU},	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
	{ 26	,1	,1	, &A7AZ03LDU},	//( - , DU) Несанкционированное включение обдува АЗ1
	{ 27	,1	,1	, &B7AZ03LDU},	//( - , DU) Несанкционированное включение обдува АЗ2
	{ 28	,1	,1	, &B3MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
	{ 29	,1	,1	, &B3MD11LP1},	//( - , DU) Кнопка ПУСК ИС2
	{ 30	,8	,1	, &R0VL01RDU},	//( - , DU) Индикация Время задержки
	{ 31	,1	,1	, &R0VZ71LZ2},	//(vds32:03 - K22VDSR, - ) Обобщенный сигнал АЗ 2 канала
	{ 32	,1	,1	, &R0VZ71LZ1},	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
	{ 33	,1	,1	, &R0VZ71LDU},	//( - , DU) Обобщенный сигнал АЗ
	{ 34	,1	,1	, &A2IS33LDU},	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
	{ 35	,1	,1	, &A3IS31LDU},	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
	{ 36	,1	,1	, &A3IS33LDU},	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
	{ 37	,1	,1	, &A3IS35LDU},	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
	{ 38	,1	,1	, &A4IS10LDU},	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
	{ 39	,1	,1	, &A1VN71LZ1},	//(vds32:02 - K21VDSR, - ) Блокировка автоматического подъёма ББ
	{ 40	,1	,1	, &A1VN71LZ2},	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{ 41	,1	,1	, &A1AB19LDU},	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
	{ 42	,1	,1	, &R0AD14LZ1},	//(vds32:02 - K20VDSR, - ) Имитация срабатывания АЗ от II УР
	{ 43	,1	,1	, &R0AD14LZ2},	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
	{ 44	,1	,1	, &A3VZ13LZ2},	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{ 45	,1	,1	, &A3VZ13LZ1},	//(vds32:02 - K18VDSR, - ) Имитация срабатывания АЗ от ВУ ИС
	{ 46	,1	,1	, &B6AB05LDU},	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
	{ 47	,1	,1	, &R0AB08LDU},	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
	{ 48	,8	,1	, &A1MC01RP1},	//( - , DU) Заданная координата положения ББ1 мм
	{ 49	,8	,1	, &B1MC01RP1},	//( - , DU) Заданная координата положения ББ2  мм
	{ 50	,8	,1	, &A3MC01RP1},	//( - , DU) Заданная координата положения ИС1 мм
	{ 51	,8	,1	, &B3MC01RP1},	//( - , DU) Заданная координата положения ИС2 мм
	{ 52	,8	,1	, &B8MC01RP2},	//( - , DU) Заданная координата АЗ2 мм
	{ 53	,1	,1	, &R0AB09LDU},	//( - , DU) Ошибка в заданной координате ББ1
	{ 54	,1	,1	, &R0AB10LDU},	//( - , DU) Ошибка в заданной координате ББ2
	{ 55	,1	,1	, &R0AB11LDU},	//( - , DU) Ошибка в заданной координате  ИС1
	{ 56	,1	,1	, &R0AB12LDU},	//( - , DU) Ошибка в заданной координате  ИС2
	{ 57	,1	,1	, &R0AB13LDU},	//( - , DU) Ошибка в заданной координате  АЗ2
	{ 58	,1	,1	, &A4ZAV},	//( - , DU) 
	{ 59	,1	,1	, &A6ZAV},	//( - , DU) 
	{ 60	,1	,1	, &R2ZAV},	//( - , DU) 
	{ 61	,1	,1	, &A5ZAV},	//( - , DU) 
	{ 62	,1	,1	, &B8ZAV},	//( - , DU) 
	{ 63	,1	,1	, &A2ZAV},	//( - , DU) Завершение РБ1,2
	{ 64	,1	,1	, &A8ZAV},	//( - , DU) 
	{ 65	,1	,1	, &A9ZAV},	//( - , DU) Завершение НИ ДС1(2)
	{ 66	,1	,1	, &R4ABL},	//( - , DU) Блокировка тележки -
	{ 67	,1	,1	, &A4UP},	//( - , DU) 
	{ 68	,1	,1	, &A4DW},	//( - , DU) 
	{ 69	,1	,1	, &R0VX02LDU},	//( - , DU) Импульс разрешен
	{ 70	,1	,1	, &R0EE03LDU},	//( - , DU) ВПИС ИС
	{ 71	,1	,1	, &R0AB07LDU},	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
	{ 72	,1	,1	, &R0AD16LDU},	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
	{ 73	,1	,1	, &C2MD31LP1},	//( - , DU) Кнопка СБРОС РБ
	{ 74	,3	,1	, &B6VS01IDU},	//( - , DU) Готовность к управлению БЗ2
	{ 75	,1	,1	, &R2AD20LDU},	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
	{ 76	,1	,1	, &R2AD10LDU},	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
	{ 77	,3	,1	, &B8VS01IDU},	//( - , DU) Готовность к управлению АЗ2
	{ 78	,3	,1	, &A8VS01IDU},	//( - , DU) Готовность к управлению ДС2
	{ 79	,1	,1	, &A1IE03LDU},	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
	{ 80	,1	,1	, &A1IE04LDU},	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
	{ 81	,1	,1	, &A2IE03LDU},	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
	{ 82	,1	,1	, &A2IE04LDU},	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
	{ 83	,1	,1	, &A3IE03LDU},	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
	{ 84	,1	,1	, &A3IE04LDU},	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
	{ 85	,1	,1	, &B1IE03LDU},	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
	{ 86	,1	,1	, &B1IE04LDU},	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
	{ 87	,1	,1	, &B2IE03LDU},	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
	{ 88	,1	,1	, &B2IE04LDU},	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
	{ 89	,1	,1	, &B3IE03LDU},	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
	{ 90	,1	,1	, &B3IE04LDU},	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
	{ 91	,1	,1	, &R0VS11LDU},	//( - , DU) РУ не готова к работе
	{ 92	,3	,1	, &B5VS01IDU},	//( - , DU) Готовность к управлению НЛ2
	{ 93	,3	,1	, &A6VS01IDU},	//( - , DU) Готовность к управлению БЗ1
	{ 94	,3	,1	, &R4VS01IDU},	//( - , DU) Готовность к управлению тележкой реактора
	{ 95	,3	,1	, &R2VS01IDU},	//( - , DU) Готовность к управлению МДЗ2
	{ 96	,3	,1	, &R1VS01IDU},	//( - , DU) Готовность к управлению МДЗ1
	{ 97	,1	,1	, &A9IS11LDU},	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
	{ 98	,1	,1	, &A9IS21LDU},	//(vds32:02 - K24VDSR, - ) Приход на НУ НИ ДС1
	{ 99	,1	,1	, &B9IS11LDU},	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
	{ 100	,1	,1	, &B9IS21LDU},	//(vds32:02 - K26VDSR, - ) Приход на НУ НИ ДС2
	{ 101	,1	,1	, &B9AD10LDU},	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
	{ 102	,1	,1	, &A9AD10LDU},	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
	{ 103	,1	,1	, &A9AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ ДС1
	{ 104	,1	,1	, &A9AB01LDU},	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
	{ 105	,1	,1	, &A9AB02LDU},	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
	{ 106	,1	,1	, &B9AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ ДС2
	{ 107	,1	,1	, &B9AB01LDU},	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
	{ 108	,1	,1	, &B9AB02LDU},	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
	{ 109	,1	,1	, &R0AB01LDU},	//( - , DU) Режим проверки разрешён
	{ 110	,1	,1	, &A3IS22LDU},	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
	{ 111	,1	,1	, &B3IS22LDU},	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
	{ 112	,1	,1	, &A2AD33LDU},	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
	{ 113	,1	,1	, &B2AD33LDU},	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
	{ 114	,1	,1	, &R8AD21LDU},	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
	{ 115	,1	,1	, &R0AD14LDU},	//( - , DU) Имитация срабатывания верхней АС II УР
	{ 116	,8	,1	, &R0VL04RDU},	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
	{ 117	,1	,1	, &R0AB04LDU},	//( - , DU) Нарушение времени срабатывания верхней АС II УР
	{ 118	,1	,1	, &R0AB06LDU},	//( - , DU) Нарушение времени задержки от ВУ РБ
	{ 119	,1	,1	, &R0AB02LDU},	//( - , DU) Нарушение времени задержки ИНИ
	{ 120	,8	,1	, &R0VL03RDU},	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
	{ 121	,8	,1	, &R0VL05RDU},	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
	{ 122	,3	,1	, &R0VL21IDU},	//( - , DU) Декатрон
	{ 123	,1	,1	, &R0VX03LDU},	//( - , DU) Готовность 2 мин
	{ 124	,3	,1	, &R0VS21IDU},	//( - , DU) Индикация ВИД ПРОВЕРКИ
	{ 125	,3	,1	, &A1VS01IDU},	//( - , DU) Готовность к управлению ББ1
	{ 126	,3	,1	, &B1VS01IDU},	//( - , DU) Готовность к управлению ББ2
	{ 127	,3	,1	, &A3VS01IDU},	//( - , DU) Готовность к управлению ИС1
	{ 128	,3	,1	, &B3VS01IDU},	//( - , DU) Готовность к управлению ИС2
	{ 129	,3	,1	, &A2VS01IDU},	//( - , DU) Готовность к управлению РБ1
	{ 130	,3	,1	, &A4VS01IDU},	//( - , DU) Готовность к управлению НИ1
	{ 131	,1	,1	, &A4VS12LDU},	//( - , DU) Движение НИ1 в сторону ВУ
	{ 132	,1	,1	, &A4VS22LDU},	//( - , DU) Движение НИ1 в сторону НУ
	{ 133	,3	,1	, &B4VS01IDU},	//( - , DU) Готовность к управлению НИ2
	{ 134	,1	,1	, &B4VS12LDU},	//( - , DU) Движение НИ2 в сторону ВУ
	{ 135	,1	,1	, &B4VS22LDU},	//( - , DU) Движение НИ2 в сторону НУ
	{ 136	,3	,1	, &A5VS01IDU},	//( - , DU) Готовность к управлению НЛ1
	{ 137	,1	,1	, &B2VS32LDU},	//( - , DU) Индикация  СБРОС РБ2
	{ 138	,1	,1	, &A3VX01LDU},	//( - , DU) Индикация Выстрел ИС1
	{ 139	,1	,1	, &A3IS11LDU},	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
	{ 140	,1	,1	, &B3VX01LDU},	//( - , DU) Индикация Выстрел ИС2
	{ 141	,1	,1	, &R0VS18LDU},	//( - , DU) Индикация  Проверка схем сброса
	{ 142	,1	,1	, &B1MD11LP1},	//( - , DU) Кнопка ПУСК ББ2
	{ 143	,1	,1	, &B1MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
	{ 144	,1	,1	, &B2MD11LP1},	//( - , DU) Кнопка ПУСК РБ2
	{ 145	,1	,1	, &B2MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
	{ 146	,1	,1	, &A2MD11LP1},	//( - , DU) Кнопка ПУСК РБ1
	{ 147	,1	,1	, &A2MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
	{ 148	,1	,1	, &R0IS01LDU},	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
	{ 149	,1	,1	, &R0IS02LDU},	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
	{ 150	,1	,1	, &R0VP73LZ1},	//( - , MDuBz1) ПС давления для РУ
	{ 151	,1	,1	, &R0VP73LZ2},	//( - , MDuBz2) ПС давления для РУ
	{ 152	,1	,1	, &R0VP73LDU},	//( - , DU) ПС давления для РУ
	{ 153	,1	,1	, &R0MD34LP1},	//( - , DU) Кнопка КВИТИРОВАТЬ
	{ 154	,1	,1	, &A0VT71LZ1},	//( - , MDuBz1) АС по температуре в АЗ1
	{ 155	,1	,1	, &B0VT71LZ1},	//( - , MDuBz1) АС по температуре в АЗ2
	{ 156	,1	,1	, &A0VT71LZ2},	//( - , MDuBz2) АС по температуре в АЗ1
	{ 157	,1	,1	, &B0VT71LZ2},	//( - , MDuBz2) АС по температуре в АЗ2
	{ 158	,1	,1	, &B2VS11LDU},	//( - , DU) Движение РБ2 в сторону ВУ
	{ 159	,1	,1	, &B2VS21LDU},	//( - , DU) Движение РБ2 в сторону НУ
	{ 160	,1	,1	, &A3AD33LDU},	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
	{ 161	,1	,1	, &A3AD34LDU},	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
	{ 162	,1	,1	, &A3AD31LDU},	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
	{ 163	,1	,1	, &B3AD34LDU},	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
	{ 164	,1	,1	, &B3AD31LDU},	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
	{ 165	,1	,1	, &A2IS11LDU},	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
	{ 166	,1	,1	, &B2IS11LDU},	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
	{ 167	,1	,1	, &A3MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
	{ 168	,1	,1	, &A3MD11LP1},	//( - , DU) Кнопка ПУСК ИС1
	{ 169	,1	,1	, &R0MD33LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
	{ 170	,1	,1	, &A1MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
	{ 171	,1	,1	, &A1MD11LP1},	//( - , DU) Кнопка ПУСК ББ1
	{ 172	,3	,1	, &R0MW14IP2},	//( - , DU) Переключатель ОБДУВ
	{ 173	,1	,1	, &A7AP31LDU},	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
	{ 174	,1	,1	, &B7AP31LDU},	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
	{ 175	,3	,1	, &R0MW12IP2},	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
	{ 176	,1	,1	, &R0MW17LP1},	//( - , DU) Переключатель АВТ/Р
	{ 177	,1	,1	, &R0VW13LDU},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
	{ 178	,1	,1	, &R0VW23LDU},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
	{ 179	,3	,1	, &R0VX08IDU},	//( - , DU) Индикация Режим
	{ 180	,1	,1	, &R0VX09LDU},	//( - , DU) Индикация регулятор мощности включен/отключен
	{ 181	,1	,1	, &R0VS17LDU},	//( - , DU) Индикация выбора АВТОМАТ
	{ 182	,1	,1	, &A2VS32LDU},	//( - , DU) Индикация  СБРОС РБ1
	{ 183	,1	,1	, &A8MC01LC1},	//( - , DU) Настроить энкодер ДС2
	{ 184	,1	,1	, &A8MC01LC2},	//( - , DU) Настроить энкодер ДС2
	{ 185	,1	,1	, &A3VP42LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
	{ 186	,8	,1	, &A3CP02RDU},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
	{ 187	,1	,1	, &A3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
	{ 188	,1	,1	, &B3VP42LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
	{ 189	,8	,1	, &B3CP02RDU},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
	{ 190	,1	,1	, &B3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
	{ 191	,1	,1	, &B3VP82LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
	{ 192	,1	,1	, &A3VP82LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
	{ 193	,3	,1	, &A3IP02IDU},	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
	{ 194	,3	,1	, &B3IP02IDU},	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
	{ 195	,1	,1	, &A0VE01LDU},	//( - , DU) Напряжение в системы АЗ1 подано
	{ 196	,1	,1	, &B0VE01LDU},	//( - , DU) Напряжение в системы АЗ2 подано
	{ 197	,1	,1	, &A0VP01LDU},	//( - , DU) Давление в системы АЗ1 подано
	{ 198	,1	,1	, &B0VP01LDU},	//( - , DU) Давление в системы АЗ2 подано
	{ 199	,1	,1	, &A0EE01LZ1},	//( - , MDuBz1) Исправность АКНП1
	{ 200	,1	,1	, &A0EE03LZ1},	//( - , MDuBz1) Исправность АКНП3
	{ 201	,1	,1	, &A0EE02LZ1},	//( - , MDuBz1) Исправность АКНП2
	{ 202	,1	,1	, &A0EE04LZ1},	//( - , MDuBz1) Исправность АКНП4
	{ 203	,1	,1	, &A0VN01LDU},	//( - , DU) Каналы АЗ1 проверены
	{ 204	,1	,1	, &B0VN01LDU},	//( - , DU) Каналы АЗ2 проверены
	{ 205	,5	,1	, &A3IC01UDU},	//( - , MDuS) Координата штока ИС1 (дел.энк)
	{ 206	,5	,1	, &B3IC01UDU},	//( - , MDuS) Координата штока ИС2 (дел.энк)
	{ 207	,8	,1	, &B3VC01RDU},	//( - , DU) Координата ИС2, мм
	{ 208	,5	,1	, &A8IC01UDU},	//( - , MDuS) Координата ДС2 (дел.энк)
	{ 209	,8	,1	, &A8VC01RDU},	//( - , DU) Координата ДС2, мм
	{ 210	,5	,1	, &B8IC01UDU},	//( - , MDuS) Координата АЗ2 (дел.энк)
	{ 211	,5	,1	, &A1IC01UDU},	//( - , MDuS) Координата штока ББ1 (дел.энк)
	{ 212	,8	,1	, &A1VC01RDU},	//( - , DU) Координата ББ1, мм
	{ 213	,1	,1	, &A1IS11LDU},	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
	{ 214	,1	,1	, &B1MC01LC1},	//( - , DU) Настроить энкодер ББ2
	{ 215	,1	,1	, &B1MC01LC2},	//( - , DU) Настроить энкодер ББ2
	{ 216	,1	,1	, &A1MC01LC1},	//( - , DU) Настроить энкодер ББ1
	{ 217	,1	,1	, &A1MC01LC2},	//( - , DU) Настроить энкодер ББ1
	{ 218	,1	,1	, &B2MC01LC1},	//( - , DU) Настроить энкодер РБ2
	{ 219	,1	,1	, &B2MC01LC2},	//( - , DU) Настроить энкодер РБ2
	{ 220	,1	,1	, &A2MC01LC1},	//( - , DU) Настроить энкодер РБ1
	{ 221	,1	,1	, &A2MC01LC2},	//( - , DU) Настроить энкодер РБ1
	{ 222	,1	,1	, &B3MC01LC1},	//( - , DU) Настроить энкодер ИС2
	{ 223	,1	,1	, &B3MC01LC2},	//( - , DU) Настроить энкодер ИС2
	{ 224	,1	,1	, &A3MC01LC1},	//( - , DU) Настроить энкодер ИС1
	{ 225	,1	,1	, &A3MC01LC2},	//( - , DU) Настроить энкодер ИС1
	{ 226	,1	,1	, &B8MC01LC1},	//( - , DU) Настроить энкодер АЗ2
	{ 227	,1	,1	, &B8MC01LC2},	//( - , DU) Настроить энкодер АЗ2
	{ 228	,1	,1	, &R0IE01LDU},	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
	{ 229	,1	,1	, &A6IE01LDU},	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
	{ 230	,1	,1	, &B6IE01LDU},	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
	{ 231	,1	,1	, &A8IE01LDU},	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
	{ 232	,1	,1	, &B5IE01LDU},	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
	{ 233	,1	,1	, &A5IE02LDU},	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
	{ 234	,1	,1	, &R1IE01LDU},	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
	{ 235	,1	,1	, &R2IE01LDU},	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
	{ 236	,1	,1	, &R6IS61LDU},	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
	{ 237	,1	,1	, &R6IS66LZZ},	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 238	,1	,1	, &R6IS67LZZ},	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 239	,1	,1	, &R6IS68LZZ},	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 240	,8	,1	, &A3VC01RDU},	//( - , DU) Координата ИС1, мм
	{ 241	,8	,1	, &A2VC01RDU},	//( - , DU) Координата РБ1, мм
	{ 242	,8	,1	, &B2VC01RDU},	//( - , DU) Координата РБ2, мм
	{ 243	,8	,1	, &B8VC01RDU},	//( - , DU) Координата АЗ2, мм
	{ 244	,1	,1	, &A4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
	{ 245	,1	,1	, &B4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
	{ 246	,1	,1	, &A2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
	{ 247	,1	,1	, &B2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
	{ 248	,1	,1	, &A3VP81LDU},	//( - , - ) Давление СПУСК ИС1 в норме
	{ 249	,1	,1	, &B3VP81LDU},	//( - , - ) Давление СПУСК ИС2 в норме
	{ 250	,1	,1	, &R0EE02LDU},	//( - , DU) Питание  АКНП  отключить
	{ 251	,1	,1	, &A0EE01LZ2},	//( - , MDuBz2) Исправность АКНП1
	{ 252	,1	,1	, &A0EE03LZ2},	//( - , MDuBz2) Исправность АКНП3
	{ 253	,1	,1	, &A0EE02LZ2},	//( - , MDuBz2) Исправность АКНП2
	{ 254	,1	,1	, &A0EE04LZ2},	//( - , MDuBz2) Исправность АКНП4
	{ 255	,1	,1	, &A0VP71LZ1},	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
	{ 256	,1	,1	, &A0VP71LZ2},	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
	{ 257	,1	,1	, &B0VP71LZ1},	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
	{ 258	,1	,1	, &B0VP71LZ2},	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
	{ 259	,1	,1	, &A0VS11LDU},	//( - , DU) АЗ1 готова к работе
	{ 260	,1	,1	, &B0VS11LDU},	//( - , DU) АЗ2 готова к работе
	{ 261	,1	,1	, &A1IE01LDU},	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
	{ 262	,1	,1	, &A3IE01LDU},	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
	{ 263	,1	,1	, &A2IE01LDU},	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
	{ 264	,1	,1	, &A1IE02LDU},	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
	{ 265	,1	,1	, &A3IE02LDU},	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
	{ 266	,1	,1	, &A2IE02LDU},	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
	{ 267	,1	,1	, &B1IE01LDU},	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
	{ 268	,1	,1	, &B2IE01LDU},	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
	{ 269	,1	,1	, &B3IE01LDU},	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
	{ 270	,1	,1	, &B1IE02LDU},	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
	{ 271	,1	,1	, &B3IE02LDU},	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
	{ 272	,1	,1	, &B2IE02LDU},	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
	{ 273	,1	,1	, &R0IE02LDU},	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
	{ 274	,8	,1	, &R0VN11RDU},	//( - , DU) Текущая мощность РУ
	{ 275	,8	,1	, &R0VN12RDU},	//( - , DU) Заданная мощность РУ
	{ 276	,1	,1	, &R0AB19LDU},	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
	{ 277	,8	,1	, &R0CN93LDU},	//( - , DU) время работы на мощности более 100Вт, сек
	{ 278	,8	,1	, &R0CN94LDU},	//( - , DU) Скорость изменения мощности
	{ 279	,3	,1	, &R0CN95LDU},	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
	{ 280	,1	,1	, &R0AD03LZ1},	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
	{ 281	,1	,1	, &R0AD03LZ2},	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
	{ 282	,1	,1	, &R0AD04LZ1},	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
	{ 283	,1	,1	, &R0AD04LZ2},	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
	{ 284	,1	,1	, &R0AD05LZ1},	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
	{ 285	,1	,1	, &R0AD05LZ2},	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
	{ 286	,1	,1	, &B8IS12LDU},	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
	{ 287	,1	,1	, &B8IS21LDU},	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
	{ 288	,1	,1	, &A1VP41LZ1},	//( - , DU) Давление СБРОС ББ1 ниже АС
	{ 289	,1	,1	, &A1VP41LZ2},	//( - , DU) Давление СБРОС ББ1 ниже АС
	{ 290	,1	,1	, &R0VL22LDU},	//( - , DU) Конец программы 200сек
	{ 291	,1	,1	, &R0VL23LDU},	//( - , DU) Конец программы 20мин
	{ 292	,1	,1	, &B1VP41LZ1},	//( - , DU) Давление СБРОС ББ2 ниже АС
	{ 293	,1	,1	, &B1VP41LZ2},	//( - , DU) Давление СБРОС ББ2 ниже АС
	{ 294	,1	,1	, &A3AB19LDU},	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
	{ 295	,1	,1	, &B3AB19LDU},	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
	{ 296	,1	,1	, &R0AB14LDU},	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
	{ 297	,1	,1	, &R0AB15LDU},	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
	{ 298	,1	,1	, &A3IS12LDU},	//( - , DU) Приход на ВУ штока ИС1
	{ 299	,1	,1	, &B3IS12LDU},	//( - , DU) Приход на ВУ штока ИС2
	{ 300	,1	,1	, &A1ZAV},	//( - , DU) 
	{ 301	,1	,1	, &A3ZAV},	//( - , DU) 
	{ 302	,1	,1	, &B1AB19LDU},	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
	{ 303	,8	,1	, &R0VN09RZ2},	//( - , MDuBz2) Усредненный период разгона
	{ 304	,8	,1	, &R0VN09RZ1},	//( - , MDuBz1) Усредненный период разгона
	{ 305	,1	,1	, &R0AB16LDU},	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
	{ 306	,1	,1	, &R0AB17LDU},	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
	{ 307	,1	,1	, &R0AB18LDU},	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
	{ 308	,8	,1	, &A0CT01IZ1},	//( - , MDuBz1) Температура АЗ1-1
	{ 309	,8	,1	, &B0CT01IZ1},	//( - , MDuBz1) Температура АЗ2-1
	{ 310	,8	,1	, &A0CT01IZ2},	//( - , MDuBz2) Температура АЗ1-2
	{ 311	,8	,1	, &B0CT01IZ2},	//( - , MDuBz2) Температура АЗ2-2
	{ 312	,8	,1	, &A3MC01RDU},	//( - , DU) Заданная координата положения ИС от регулятора мм
	{ 313	,8	,1	, &A3MC02RDU},	//( - , DU) Температурная корректировка координаты ИМ
	{ 314	,8	,1	, &R0CN91LDU},	//( - , DU) Рассчётная реактивность от регулятора
	{ 315	,8	,1	, &A3MC03RDU},	//( - , DU) Координата положения ИМ 0-й реактивности
	{ 316	,1	,1	, &A3AB15LDU},	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
	{ 317	,1	,1	, &R0AB20LDU},	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
	{ 318	,8	,1	, &R0CN92LDU},	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
	{ 319	,3	,1	, &R0DE0FLDU},	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
	{ 320	,1	,1	, &R0DE31LDU},	//(sbk:20 - S01SBK, DiagnDU) диагностика шкафа ДУ сеть 1
	{ 321	,3	,1	, &TTLDU},	//( - , DU) ttl
	{ 322	,1	,1	, &R0DE32LDU},	//(sbk:20 - S02SBK, DiagnDU) диагностика шкафа ДУ сеть 2
	{ 323	,1	,1	, &R0DE33LDU},	//(sbk:20 - S03SBK, DiagnDU) диагностика шкафа ДУ двери
	{ 324	,1	,1	, &R0DE34LDU},	//(sbk:20 - S04SBK, DiagnDU) диагностика шкафа ДУ температура меньше 43
	{ 325	,1	,1	, &R0DE35LDU},	//(sbk:20 - S05SBK, DiagnDU) диагностика шкафа ДУ температура больше 53
	{ 326	,1	,1	, &R0DE36LDU},	//(sbk:20 - S06SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 1
	{ 327	,1	,1	, &R0DE37LDU},	//(sbk:20 - S07SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 2
	{ 328	,1	,1	, &R0DE38LDU},	//(sbk:20 - S08SBK, DiagnDU) диагностика шкафа ДУ МП15-3 место 3
	{ 329	,1	,1	, &R0DE39LDU},	//(sbk:20 - S09SBK, DiagnDU) диагностика шкафа ДУ МП24-2 место 4
	{ 330	,1	,1	, &R0DEB3LDU},	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
	{ 331	,1	,1	, &R0DEB2LDU},	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
	{ 332	,1	,1	, &R0DEB1LDU},	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
	{ 333	,1	,1	, &R0DEB4LDU},	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
	{ 334	,1	,1	, &R0DE3DLDU},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
	{ 335	,1	,1	, &R0DE3CLDU},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
	{ 336	,1	,1	, &TestDiagnDU},	//( - , DU) Неисправность от
	{ 337	,5	,1	, &B1IC01UDU},	//( - , MDuS) Координата штока ББ2 (дел.энк)
	{ 338	,8	,1	, &B1VC01RDU},	//( - , DU) Координата ББ2, мм
	{ 339	,1	,1	, &B1IS11LDU},	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
	{ 340	,5	,1	, &A2IC01UDU},	//( - , MDuS) Координата штока РБ1 (дел.энк)
	{ 341	,5	,1	, &B2IC01UDU},	//( - , MDuS) Координата штока РБ2 (дел.энк)
	{ 342	,1	,1	, &A3EE03LDU},	//( - , DU) ВПИС ИС1
	{ 343	,1	,1	, &B3EE03LDU},	//( - , DU) ВПИС ИС2
	{ 344	,1	,1	, &B3AB15LDU},	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
	{ 345	,1	,1	, &R5IS21LDU},	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
	{ 346	,1	,1	, &R5VS22LDU},	//( - , DU) Движение ворот отстойной зоны к закрыты
	{ 347	,1	,1	, &R5VS12LDU},	//( - , DU) Движение ворот отстойной зоны к открыты
	{ 348	,3	,1	, &R5VS01IDU},	//( - , DU) Готовность к управлению ворот отстойной зоны
	{ 349	,1	,1	, &R3VS22LDU},	//( - , DU) Движение гомогенных дверей к закрыты
	{ 350	,1	,1	, &R3VS12LDU},	//( - , DU) Движение гомогенных дверей к открыты
	{ 351	,3	,1	, &R3VS01IDU},	//( - , DU) Готовность к управлению гомогенных дверей
	{ 352	,1	,1	, &A3AB13LDU},	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
	{ 353	,1	,1	, &B3AB13LDU},	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
	{ 354	,3	,1	, &R0DE02LDU},	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
	{ 355	,3	,1	, &R0DE03LDU},	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
	{ 356	,3	,1	, &R0DE04LDU},	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
	{ 357	,3	,1	, &R0DE08LDU},	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
	{ 358	,3	,1	, &R0DE05LDU},	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
	{ 359	,3	,1	, &R0DE09LDU},	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
	{ 360	,3	,1	, &R0DE0ALDU},	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
	{ 361	,3	,1	, &R0DE07LDU},	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
	{ 362	,3	,1	, &R0DE0CLDU},	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
	{ 363	,3	,1	, &R0DE0BLDU},	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
	{ 364	,3	,1	, &R0DE0DLDU},	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
	{ 365	,1	,1	, &R4IS11LDU},	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
	{ 366	,1	,1	, &A6AB06LDU},	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
	{ 367	,1	,1	, &A6AB07LDU},	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
	{ 368	,1	,1	, &A6AB08LDU},	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
	{ 369	,1	,1	, &A6AB09LDU},	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
	{ 370	,1	,1	, &B6AB06LDU},	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
	{ 371	,1	,1	, &B6AB07LDU},	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
	{ 372	,1	,1	, &B6AB08LDU},	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
	{ 373	,1	,1	, &B6AB09LDU},	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
	{ 374	,1	,1	, &A6AB05LDU},	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
	{ 375	,1	,1	, &B8VS12LDU},	//( - , DU) Движение АЗ2 в сторону ВУ
	{ 376	,8	,1	, &B8CV01RDU},	//( - , DU) Измеренная скорость перемещения АЗ2
	{ 377	,1	,1	, &B8AB06LDU},	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
	{ 378	,1	,1	, &B8AB07LDU},	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
	{ 379	,1	,1	, &B8AB05LDU},	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
	{ 380	,1	,1	, &B8VS22LDU},	//( - , DU) Движение АЗ2 в сторону НУ
	{ 381	,1	,1	, &B8AZ03LDU},	//( - , DU) Несанкционированное перемещение АЗ2
	{ 382	,1	,1	, &R0MD11LP1},	//( - , DU) Кнопка ПУСК
	{ 383	,1	,1	, &B8AD10LDU},	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
	{ 384	,1	,1	, &B8AD20LDU},	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
	{ 385	,1	,1	, &B8IS11LDU},	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
	{ 386	,1	,1	, &B8AB01LDU},	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
	{ 387	,1	,1	, &B5IS21LDU},	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
	{ 388	,1	,1	, &A5AZ03LDU},	//( - , DU) Несанкционированное перемещение НЛ1
	{ 389	,1	,1	, &A5AB01LDU},	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
	{ 390	,1	,1	, &A5AB02LDU},	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
	{ 391	,1	,1	, &B5AZ03LDU},	//( - , DU) Несанкционированное перемещение НЛ2
	{ 392	,1	,1	, &B5AB01LDU},	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
	{ 393	,1	,1	, &B5AB02LDU},	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
	{ 394	,1	,1	, &A4IS21LDU},	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
	{ 395	,1	,1	, &B4IS21LDU},	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
	{ 396	,1	,1	, &B4AD10LDU},	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
	{ 397	,1	,1	, &A4AD10LDU},	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
	{ 398	,1	,1	, &A4AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ1
	{ 399	,1	,1	, &A4AB01LDU},	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
	{ 400	,1	,1	, &A4AB02LDU},	//( - , DU) Блокировка движения НИ1 - Нет перемещения
	{ 401	,1	,1	, &B4AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ2
	{ 402	,1	,1	, &B4AB01LDU},	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
	{ 403	,1	,1	, &B4AB02LDU},	//( - , DU) Блокировка движения НИ2 - Нет перемещения
	{ 404	,1	,1	, &A5AB04LDU},	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
	{ 405	,1	,1	, &B5AB04LDU},	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
	{ 406	,1	,1	, &A1IS12LDU},	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
	{ 407	,1	,1	, &A2IS12LDU},	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
	{ 408	,1	,1	, &B1IS12LDU},	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
	{ 409	,1	,1	, &B2IS12LDU},	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
	{ 410	,1	,1	, &A8AB09LDU},	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
	{ 411	,1	,1	, &A8AB10LDU},	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
	{ 412	,1	,1	, &A8AB11LDU},	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
	{ 413	,1	,1	, &A8AB12LDU},	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
	{ 414	,1	,1	, &A8AB13LDU},	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
	{ 415	,1	,1	, &A8AB14LDU},	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
	{ 416	,1	,1	, &A8AB02LDU},	//( - , DU) Блокировка движения ДС2- АНИ не установлен
	{ 417	,1	,1	, &A8AB01LDU},	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
	{ 418	,1	,1	, &A2VS11LDU},	//( - , DU) Движение РБ1 в сторону ВУ
	{ 419	,8	,1	, &A2CV01RDU},	//( - , DU) Измеренная скорость перемещения РБ1
	{ 420	,1	,1	, &A2AB04LDU},	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
	{ 421	,1	,1	, &A2AB02LDU},	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
	{ 422	,1	,1	, &A2AB01LDU},	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
	{ 423	,1	,1	, &A2VS21LDU},	//( - , DU) Движение РБ1 в сторону НУ
	{ 424	,1	,1	, &A2AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
	{ 425	,1	,1	, &A2AD11LDU},	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
	{ 426	,1	,1	, &A2AD21LDU},	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
	{ 427	,1	,1	, &A2AD02LDU},	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
	{ 428	,1	,1	, &A2AD03LDU},	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
	{ 429	,1	,1	, &A2AD04LDU},	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
	{ 430	,1	,1	, &A2AD05LDU},	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
	{ 431	,1	,1	, &A2AB07LDU},	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
	{ 432	,1	,1	, &A2AB08LDU},	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
	{ 433	,1	,1	, &B8AB04LDU},	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
	{ 434	,1	,1	, &B8AB08LDU},	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
	{ 435	,1	,1	, &B8AB09LDU},	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
	{ 436	,1	,1	, &B8AB10LDU},	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
	{ 437	,1	,1	, &B8AB11LDU},	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
	{ 438	,1	,1	, &B8AB12LDU},	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
	{ 439	,1	,1	, &B8AB13LDU},	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
	{ 440	,1	,1	, &B8AB14LDU},	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
	{ 441	,1	,1	, &B8AB02LDU},	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
	{ 442	,1	,1	, &A8VS12LDU},	//( - , DU) Движение ДС2 в сторону ВУ
	{ 443	,8	,1	, &A8CV01RDU},	//( - , DU) Измеренная скорость перемещения ДС2
	{ 444	,1	,1	, &A8AB06LDU},	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
	{ 445	,1	,1	, &A8AB07LDU},	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
	{ 446	,1	,1	, &A8AB05LDU},	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
	{ 447	,1	,1	, &A8VS22LDU},	//( - , DU) Движение ДС2 в сторону НУ
	{ 448	,1	,1	, &A8AZ03LDU},	//( - , DU) Несанкционированное перемещение ДС2
	{ 449	,1	,1	, &A8AD10LDU},	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
	{ 450	,1	,1	, &A8AD20LDU},	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
	{ 451	,1	,1	, &B8IS22LDU},	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
	{ 452	,1	,1	, &A8IS12LDU},	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
	{ 453	,1	,1	, &A8AB04LDU},	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
	{ 454	,1	,1	, &A8IS22LDU},	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
	{ 455	,1	,1	, &A8AB08LDU},	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
	{ 456	,1	,1	, &B6IS21LDU},	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
	{ 457	,1	,1	, &A6VS22LDU},	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
	{ 458	,1	,1	, &A6VS12LDU},	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
	{ 459	,1	,1	, &B6VS22LDU},	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
	{ 460	,1	,1	, &B6VS12LDU},	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
	{ 461	,1	,1	, &A6AD10LDU},	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
	{ 462	,1	,1	, &A6AD20LDU},	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
	{ 463	,1	,1	, &B6AD10LDU},	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
	{ 464	,1	,1	, &B6AD20LDU},	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
	{ 465	,1	,1	, &A6AZ03LDU},	//( - , DU) Несанкционированное перемещение БЗ1
	{ 466	,1	,1	, &A6AB01LDU},	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
	{ 467	,1	,1	, &A6AB02LDU},	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
	{ 468	,1	,1	, &B6AZ03LDU},	//( - , DU) Несанкционированное перемещение БЗ2
	{ 469	,1	,1	, &B6AB01LDU},	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
	{ 470	,1	,1	, &B6AB02LDU},	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
	{ 471	,1	,1	, &A6AB04LDU},	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
	{ 472	,1	,1	, &B6AB04LDU},	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
	{ 473	,1	,1	, &R4AB01LDU},	//( - , DU) Блокировка движения тележки - АНИ не установлен
	{ 474	,1	,1	, &R8IS11LDU},	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
	{ 475	,1	,1	, &R6IS21LDU},	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
	{ 476	,1	,1	, &A0VN71LZ2},	//( - , MDuBz2) АЗ по АС мощности для АЗ1
	{ 477	,1	,1	, &A0VN71LZ1},	//( - , MDuBz1) АЗ по АС мощности для АЗ1
	{ 478	,3	,1	, &R0MW15IP1},	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
	{ 479	,3	,1	, &R0MW14IP1},	//( - , DU) Переключатель ПРОГРАММЫ
	{ 480	,3	,1	, &R0MW12IP1},	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
	{ 481	,3	,1	, &R0MW13IP1},	//( - , DU) Переключатель ВЫБОР ЗОН
	{ 482	,3	,1	, &R0MW16IP1},	//( - , DU) Переключатель ВИД ПРОВЕРКИ
	{ 483	,3	,1	, &R0MW11IP1},	//( - , DU) Переключатель ВЫСТРЕЛ
	{ 484	,3	,1	, &R0MW11IP2},	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
	{ 485	,1	,1	, &R0MW13LP2},	//( - , DU) Переключатель СЕТЬ
	{ 486	,1	,1	, &R0MD32LP1},	//( - , DU) Кнопка СПУСК
	{ 487	,1	,1	, &R0MD31LP1},	//( - , DU) Кнопка СТОП
	{ 488	,1	,1	, &A1IS21LDU},	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
	{ 489	,1	,1	, &A2IS21LDU},	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
	{ 490	,1	,1	, &A3IS21LDU},	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
	{ 491	,1	,1	, &B1IS21LDU},	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
	{ 492	,1	,1	, &B2IS21LDU},	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
	{ 493	,1	,1	, &B3IS21LDU},	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
	{ 494	,1	,1	, &R0ES01LDU},	//( - , DU) ОРР не в исходном состоянии
	{ 495	,1	,1	, &R4MD11LP2},	//( - , DU) Кнопка ВПЕРЁД  (тележки)
	{ 496	,1	,1	, &R4MD31LP2},	//( - , DU) Кнопка СТОП  (тележки)
	{ 497	,1	,1	, &R4MD21LP2},	//( - , DU) Кнопка НАЗАД  (тележки)
	{ 498	,1	,1	, &A6IS11LDU},	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
	{ 499	,1	,1	, &A6IS21LDU},	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
	{ 500	,1	,1	, &B6IS11LDU},	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
	{ 501	,1	,1	, &R4AB12LDU},	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
	{ 502	,1	,1	, &A4IS11LDU},	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
	{ 503	,1	,1	, &B4IS11LDU},	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
	{ 504	,1	,1	, &R4AB13LDU},	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
	{ 505	,1	,1	, &R4AB14LDU},	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
	{ 506	,1	,1	, &R4AB15LDU},	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
	{ 507	,1	,1	, &R5IS11LDU},	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
	{ 508	,1	,1	, &R4AB16LDU},	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
	{ 509	,1	,1	, &R4AB17LDU},	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
	{ 510	,1	,1	, &R4AB18LDU},	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
	{ 511	,1	,1	, &R4AD10LDU},	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
	{ 512	,1	,1	, &R4AD20LDU},	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
	{ 513	,1	,1	, &A5VS22LDU},	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
	{ 514	,1	,1	, &A5VS12LDU},	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
	{ 515	,1	,1	, &B5VS22LDU},	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
	{ 516	,1	,1	, &B5VS12LDU},	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
	{ 517	,1	,1	, &B5AD10LDU},	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
	{ 518	,1	,1	, &B5AD20LDU},	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
	{ 519	,1	,1	, &A5AD10LDU},	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
	{ 520	,1	,1	, &A5AD20LDU},	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
	{ 521	,1	,1	, &A5IS11LDU},	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
	{ 522	,1	,1	, &A5IS21LDU},	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
	{ 523	,1	,1	, &B5IS11LDU},	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
	{ 524	,1	,1	, &R0NE01LDU},	//( - , DU) Потеря связи с БАЗ1
	{ 525	,1	,1	, &R0NE02LDU},	//( - , DU) Потеря связи с БАЗ2
	{ 526	,1	,1	, &R4AB02LDU},	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
	{ 527	,1	,1	, &R0NE08LDU},	//( - , DU) Потеря связи с ОПУ
	{ 528	,1	,1	, &R4IS21LDU},	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
	{ 529	,1	,1	, &R4IS22LDU},	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
	{ 530	,1	,1	, &R4IS12LDU},	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
	{ 531	,1	,1	, &R4VS22LDU},	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
	{ 532	,1	,1	, &R4VS12LDU},	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
	{ 533	,1	,1	, &R4AZ03LDU},	//( - , DU) Несанкционированное перемещение тележки
	{ 534	,1	,1	, &R4AB03LDU},	//( - , DU) Блокировка движения тележки - Самоход любого механизма
	{ 535	,1	,1	, &R1IS21LDU},	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
	{ 536	,1	,1	, &R2IS21LDU},	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
	{ 537	,1	,1	, &R4AB04LDU},	//( - , DU) Блокировка движения тележки - Превышение времени движения
	{ 538	,1	,1	, &R4AB05LDU},	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
	{ 539	,1	,1	, &R4AB06LDU},	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
	{ 540	,1	,1	, &R4AB07LDU},	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
	{ 541	,1	,1	, &R4AB08LDU},	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
	{ 542	,1	,1	, &R4AB09LDU},	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
	{ 543	,1	,1	, &B0VN71LZ1},	//( - , MDuBz1) АЗ по АС мощности для АЗ2
	{ 544	,1	,1	, &B0VN71LZ2},	//( - , MDuBz2) АЗ по АС мощности для АЗ2
	{ 545	,1	,1	, &R4AB10LDU},	//( - , DU) Блокировка тележки - не открыта биологическая защита
	{ 546	,1	,1	, &R4AB11LDU},	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
	{ 547	,1	,1	, &A3AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
	{ 548	,1	,1	, &A3AD11LDU},	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
	{ 549	,1	,1	, &A3AD21LDU},	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
	{ 550	,1	,1	, &A3AD02LDU},	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
	{ 551	,1	,1	, &A3AD03LDU},	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
	{ 552	,1	,1	, &A3AD04LDU},	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
	{ 553	,1	,1	, &A3AD05LDU},	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
	{ 554	,1	,1	, &A3AD01LDU},	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
	{ 555	,8	,1	, &A3CV02RDU},	//( - , DU) Заданная скорость перемещения ИС1
	{ 556	,1	,1	, &A3AB07LDU},	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
	{ 557	,1	,1	, &A3AB08LDU},	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
	{ 558	,1	,1	, &A3AB05LDU},	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
	{ 559	,1	,1	, &A3AB06LDU},	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
	{ 560	,1	,1	, &A3AB09LDU},	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
	{ 561	,1	,1	, &A3AB10LDU},	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
	{ 562	,1	,1	, &A3AB11LDU},	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
	{ 563	,1	,1	, &A3AB12LDU},	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 564	,1	,1	, &A3AB14LDU},	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
	{ 565	,1	,1	, &A3AB16LDU},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
	{ 566	,1	,1	, &A3AB17LDU},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
	{ 567	,1	,1	, &A3AB18LDU},	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
	{ 568	,1	,1	, &A3AB20LDU},	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
	{ 569	,1	,1	, &B1AD04LDU},	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
	{ 570	,1	,1	, &B1AD05LDU},	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
	{ 571	,1	,1	, &B1AD01LDU},	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
	{ 572	,8	,1	, &B1CV02RDU},	//( - , DU) Заданная скорость перемещения ББ2
	{ 573	,1	,1	, &B1AB07LDU},	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
	{ 574	,1	,1	, &B1AB08LDU},	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
	{ 575	,1	,1	, &B1AB05LDU},	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
	{ 576	,1	,1	, &B1AB06LDU},	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
	{ 577	,1	,1	, &B1AB09LDU},	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
	{ 578	,1	,1	, &B1AB10LDU},	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
	{ 579	,1	,1	, &B1AB11LDU},	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
	{ 580	,1	,1	, &B1AB12LDU},	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 581	,1	,1	, &B1AB13LDU},	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
	{ 582	,1	,1	, &B1AB14LDU},	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
	{ 583	,1	,1	, &B1AB16LDU},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
	{ 584	,1	,1	, &B1AB17LDU},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
	{ 585	,1	,1	, &B1AB18LDU},	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
	{ 586	,1	,1	, &A3VS12LDU},	//( - , DU) Движение ИС1 в сторону ВУ
	{ 587	,8	,1	, &A3CV01RDU},	//( - , DU) Измеренная скорость перемещения ИС1
	{ 588	,1	,1	, &A3AB04LDU},	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
	{ 589	,1	,1	, &A3AB02LDU},	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
	{ 590	,1	,1	, &A3AB01LDU},	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
	{ 591	,1	,1	, &A3VS22LDU},	//( - , DU) Движение ИС1 в сторону НУ
	{ 592	,1	,1	, &B3AB14LDU},	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
	{ 593	,1	,1	, &B3AB16LDU},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
	{ 594	,1	,1	, &B3AB17LDU},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
	{ 595	,1	,1	, &B3AB18LDU},	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
	{ 596	,1	,1	, &B3AB20LDU},	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
	{ 597	,1	,1	, &C1MD31LP1},	//( - , DU) Кнопка СБРОС ББ
	{ 598	,1	,1	, &C1MD31LP2},	//( - , DU) Кнопка СБРОС ББ
	{ 599	,1	,1	, &A2AD31LDU},	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
	{ 600	,1	,1	, &B2AD31LDU},	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
	{ 601	,1	,1	, &A1AD31LDU},	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
	{ 602	,1	,1	, &B1AD31LDU},	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
	{ 603	,1	,1	, &A2AD32LDU},	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
	{ 604	,1	,1	, &B2AD32LDU},	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
	{ 605	,1	,1	, &A1AD32LDU},	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
	{ 606	,1	,1	, &B1AD32LDU},	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
	{ 607	,1	,1	, &R0MD11LP2},	//( - , DU) Кнопка Пуск проверки схем сброса
	{ 608	,1	,1	, &R0VX01LDU},	//( - , DU) ДО ИМПУЛЬСА
	{ 609	,3	,1	, &R0VL01IDU},	//( - , DU) До импульса минут
	{ 610	,3	,1	, &R0VL11IDU},	//( - , DU) До импульса секунд
	{ 611	,8	,1	, &R0VL06RDU},	//( - , DU) Индикация (Время задержки от ВУ РБ)
	{ 612	,1	,1	, &B3AD33LDU},	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
	{ 613	,1	,1	, &B3IS11LDU},	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
	{ 614	,8	,1	, &R0VL02RDU},	//( - , DU) Индикация (Время задержки ИНИ)
	{ 615	,1	,1	, &B3VS12LDU},	//( - , DU) Движение ИС2 в сторону ВУ
	{ 616	,8	,1	, &B3CV01RDU},	//( - , DU) Измеренная скорость перемещения ИС2
	{ 617	,1	,1	, &B3AB04LDU},	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
	{ 618	,1	,1	, &B3AB02LDU},	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
	{ 619	,1	,1	, &B3AB01LDU},	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
	{ 620	,1	,1	, &B3VS22LDU},	//( - , DU) Движение ИС2 в сторону НУ
	{ 621	,1	,1	, &B3AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
	{ 622	,1	,1	, &B3AD11LDU},	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
	{ 623	,1	,1	, &B3AD21LDU},	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
	{ 624	,1	,1	, &B3AD02LDU},	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
	{ 625	,1	,1	, &B3AD03LDU},	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
	{ 626	,1	,1	, &B3AD04LDU},	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
	{ 627	,1	,1	, &B3AD05LDU},	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
	{ 628	,1	,1	, &B3AD01LDU},	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
	{ 629	,8	,1	, &B3CV02RDU},	//( - , DU) Заданная скорость перемещения ИС2
	{ 630	,1	,1	, &B3AB07LDU},	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
	{ 631	,1	,1	, &B3AB08LDU},	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
	{ 632	,1	,1	, &B3AB05LDU},	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
	{ 633	,1	,1	, &B3AB06LDU},	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
	{ 634	,1	,1	, &B3AB09LDU},	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
	{ 635	,1	,1	, &B3AB10LDU},	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
	{ 636	,1	,1	, &B3AB11LDU},	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
	{ 637	,1	,1	, &B3AB12LDU},	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{ 638	,1	,1	, &B2AD01LDU},	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
	{ 639	,8	,1	, &B2CV02RDU},	//( - , DU) Заданная скорость перемещения РБ2
	{ 640	,1	,1	, &B2AB07LDU},	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
	{ 641	,1	,1	, &B2AB08LDU},	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
	{ 642	,1	,1	, &B2AB05LDU},	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
	{ 643	,1	,1	, &B2AB06LDU},	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
	{ 644	,1	,1	, &B2AB09LDU},	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
	{ 645	,1	,1	, &B2AB10LDU},	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
	{ 646	,1	,1	, &B2AB11LDU},	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
	{ 647	,1	,1	, &B2AB12LDU},	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{ 648	,1	,1	, &B2AB13LDU},	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
	{ 649	,1	,1	, &B2AB14LDU},	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
	{ 650	,1	,1	, &B2AB16LDU},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
	{ 651	,1	,1	, &B2AB17LDU},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
	{ 652	,1	,1	, &R1AZ03LDU},	//( - , DU) Несанкционированное перемещение МДЗ1
	{ 653	,1	,1	, &R1AB01LDU},	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
	{ 654	,1	,1	, &R1AB02LDU},	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
	{ 655	,1	,1	, &R2AZ03LDU},	//( - , DU) Несанкционированное перемещение МДЗ2
	{ 656	,1	,1	, &R2AB01LDU},	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
	{ 657	,1	,1	, &R2AB02LDU},	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
	{ 658	,1	,1	, &R1AB04LDU},	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
	{ 659	,1	,1	, &R2AB04LDU},	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
	{ 660	,1	,1	, &R1AD10LDU},	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
	{ 661	,1	,1	, &A2AB05LDU},	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
	{ 662	,1	,1	, &A2AB06LDU},	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
	{ 663	,1	,1	, &A2AB09LDU},	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
	{ 664	,1	,1	, &A2AB10LDU},	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
	{ 665	,1	,1	, &A2AB11LDU},	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
	{ 666	,1	,1	, &A2AB12LDU},	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 667	,1	,1	, &A2AB13LDU},	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
	{ 668	,1	,1	, &A2AB14LDU},	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
	{ 669	,1	,1	, &A2AB16LDU},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
	{ 670	,1	,1	, &A2AB17LDU},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
	{ 671	,1	,1	, &A2AD01LDU},	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
	{ 672	,8	,1	, &A2CV02RDU},	//( - , DU) Заданная скорость перемещения РБ1
	{ 673	,8	,1	, &B2CV01RDU},	//( - , DU) Измеренная скорость перемещения РБ2
	{ 674	,1	,1	, &B2AB04LDU},	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
	{ 675	,1	,1	, &B2AB02LDU},	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
	{ 676	,1	,1	, &B2AB01LDU},	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
	{ 677	,1	,1	, &B2AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
	{ 678	,1	,1	, &B2AD11LDU},	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
	{ 679	,1	,1	, &B2AD21LDU},	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
	{ 680	,1	,1	, &B2AD02LDU},	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
	{ 681	,1	,1	, &B2AD03LDU},	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
	{ 682	,1	,1	, &B2AD04LDU},	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
	{ 683	,1	,1	, &B2AD05LDU},	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
	{ 684	,1	,1	, &A1AB08LDU},	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
	{ 685	,1	,1	, &A1AB05LDU},	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
	{ 686	,1	,1	, &A1AB06LDU},	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
	{ 687	,1	,1	, &A1AB09LDU},	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
	{ 688	,1	,1	, &A1AB10LDU},	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
	{ 689	,1	,1	, &A1AB11LDU},	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
	{ 690	,1	,1	, &A1AB12LDU},	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 691	,1	,1	, &A1AB13LDU},	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
	{ 692	,1	,1	, &A1AB14LDU},	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
	{ 693	,1	,1	, &A1AB16LDU},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
	{ 694	,1	,1	, &A1AB17LDU},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
	{ 695	,1	,1	, &A1AB18LDU},	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
	{ 696	,1	,1	, &B1VS12LDU},	//( - , DU) Движение ББ2 в сторону ВУ
	{ 697	,8	,1	, &B1CV01RDU},	//( - , DU) Измеренная скорость перемещения ББ2
	{ 698	,1	,1	, &B1AB04LDU},	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
	{ 699	,1	,1	, &B1AB02LDU},	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
	{ 700	,1	,1	, &B1AB01LDU},	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
	{ 701	,1	,1	, &B1VS22LDU},	//( - , DU) Движение ББ2 в сторону НУ
	{ 702	,1	,1	, &B1AZ03LDU},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
	{ 703	,1	,1	, &B1AD11LDU},	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
	{ 704	,1	,1	, &B1AD21LDU},	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
	{ 705	,1	,1	, &B1AD02LDU},	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
	{ 706	,1	,1	, &B1AD03LDU},	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
	{ 707	,1	,1	, &R1AD20LDU},	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
	{ 708	,1	,1	, &R1IS11LDU},	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
	{ 709	,1	,1	, &R1VS22LDU},	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
	{ 710	,1	,1	, &R2VS22LDU},	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
	{ 711	,1	,1	, &R2VS12LDU},	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
	{ 712	,1	,1	, &R1VS12LDU},	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
	{ 713	,1	,1	, &R2IS11LDU},	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
	{ 714	,1	,1	, &A1VS12LDU},	//( - , DU) Движение ББ1 в сторону ВУ
	{ 715	,8	,1	, &A1CV01RDU},	//( - , DU) Измеренная скорость перемещения ББ1
	{ 716	,1	,1	, &A1AB04LDU},	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
	{ 717	,1	,1	, &A1AB02LDU},	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
	{ 718	,1	,1	, &A1AB01LDU},	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
	{ 719	,1	,1	, &A1VS22LDU},	//( - , DU) Движение ББ1 в сторону НУ
	{ 720	,1	,1	, &A1AZ03LDU},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
	{ 721	,1	,1	, &A1AD11LDU},	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
	{ 722	,1	,1	, &A1AD21LDU},	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
	{ 723	,1	,1	, &A1AD02LDU},	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
	{ 724	,1	,1	, &A1AD03LDU},	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
	{ 725	,1	,1	, &A1AD04LDU},	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
	{ 726	,1	,1	, &A1AD05LDU},	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
	{ 727	,1	,1	, &A1AD01LDU},	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
	{ 728	,8	,1	, &A1CV02RDU},	//( - , DU) Заданная скорость перемещения ББ1
	{ 729	,1	,1	, &A1AB07LDU},	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
	{ 730	,8	,1	, &fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
	{ 731	,5	,1	, &dEM_A1UC05UDU},	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
	{ 732	,5	,1	, &dEM_A1UC06UDU},	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
	{ 733	,5	,1	, &dEM_A2UC06UDU},	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
	{ 734	,5	,1	, &dEM_A2UC05UDU},	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
	{ 735	,8	,1	, &fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
	{ 736	,5	,1	, &dEM_A3UC06UDU},	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
	{ 737	,5	,1	, &dEM_A3UC05UDU},	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
	{ 738	,8	,1	, &fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
	{ 739	,5	,1	, &dEM_A8UC06UDU},	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
	{ 740	,8	,1	, &fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
	{ 741	,5	,1	, &dEM_A8UC05UDU},	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
	{ 742	,8	,1	, &fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{ 743	,8	,1	, &fEM_R0UV82RDU},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{ 744	,8	,1	, &fEM_R0UV83RDU},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{ 745	,8	,1	, &fEM_R0UV84RDU},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{ 746	,8	,1	, &fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 747	,8	,1	, &fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{ 748	,8	,1	, &fEM_R0UV87RDU},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 749	,8	,1	, &fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{ 750	,8	,1	, &fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{ 751	,8	,1	, &fEM_A3UP43RDU},	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
	{ 752	,8	,1	, &fEM_A3UP44RDU},	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
	{ 753	,8	,1	, &fEM_A3UP53RDU},	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
	{ 754	,8	,1	, &fEM_A3UP85RDU},	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 755	,8	,1	, &fEM_A3UP88RDU},	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 756	,8	,1	, &fEM_A3UP86RDU},	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 757	,8	,1	, &fEM_B8UV01RDU},	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
	{ 758	,8	,1	, &fEM_B8UV02RDU},	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
	{ 759	,8	,1	, &fEM_B8UV03RDU},	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
	{ 760	,8	,1	, &fEM_B8UL04RDU},	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
	{ 761	,3	,1	, &iEM_A2UV03CDU},	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
	{ 762	,8	,1	, &fEM_A2UV01RDU},	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
	{ 763	,8	,1	, &fEM_A2UV02RDU},	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
	{ 764	,8	,1	, &fEM_A1UV01RDU},	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
	{ 765	,8	,1	, &fEM_A1UV02RDU},	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
	{ 766	,8	,1	, &fEM_A1UC06RDU},	//(A1UC06RDU) Уставка определения самохода ББ  мм
	{ 767	,8	,1	, &fEM_A1UC05RDU},	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
	{ 768	,8	,1	, &fEM_A1UL04RDU},	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
	{ 769	,8	,1	, &fEM_A3UV01RDU},	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
	{ 770	,8	,1	, &fEM_A3UV02RDU},	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
	{ 771	,8	,1	, &fEM_A3UC06RDU},	//(A3UC06RDU) Уставка определения самохода ИС1  мм
	{ 772	,8	,1	, &fEM_A3UC05RDU},	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
	{ 773	,8	,1	, &fEM_A3UL04RDU},	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
	{ 774	,8	,1	, &fEM_A3UP54RDU},	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
	{ 775	,8	,1	, &fEM_A3UP87RDU},	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 776	,8	,1	, &fEM_R0UL05RDU},	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
	{ 777	,8	,1	, &fEM_R0UL20RDU},	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
	{ 778	,8	,1	, &fEM_B8UV04RDU},	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
	{ 779	,8	,1	, &fEM_B8UC06RDU},	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
	{ 780	,8	,1	, &fEM_B8UC05RDU},	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
	{ 781	,8	,1	, &fEM_A2UL05RDU},	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
	{ 782	,8	,1	, &fEM_A2UL03RDU},	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{ 783	,8	,1	, &fEM_A2UC06RDU},	//(A2UC06RDU) Уставка определения самохода РБ  мм
	{ 784	,8	,1	, &fEM_A2UC05RDU},	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
	{ 785	,8	,1	, &fEM_A2UL04RDU},	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
	{ 786	,8	,1	, &fEM_A1UL03RDU},	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
	{ 787	,8	,1	, &fEM_A1UL05RDU},	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
	{ 788	,8	,1	, &fEM_A3UL03RDU},	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
	{ 789	,8	,1	, &fEM_A3UL05RDU},	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
	{ 790	,8	,1	, &fEM_A1UC08RDU},	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
	{ 791	,8	,1	, &fEM_A3UC08RDU},	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
	{ 792	,8	,1	, &fEM_A1UC07RDU},	//(A1UC07RDU) Зона возврата при наведении ББ мм
	{ 793	,8	,1	, &fEM_A1UL01RDU},	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 794	,8	,1	, &fEM_A3UC07RDU},	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
	{ 795	,8	,1	, &fEM_A3UL01RDU},	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 796	,8	,1	, &fEM_A2UC08RDU},	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
	{ 797	,8	,1	, &fEM_A2UC07RDU},	//(A2UC07RDU) Зона возврата при наведении РБ  мм
	{ 798	,8	,1	, &fEM_A2UL01RDU},	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 799	,8	,1	, &fEM_B8UC01RDU},	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
	{ 800	,8	,1	, &fEM_B8UL07RDU},	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
	{ 801	,8	,1	, &fEM_B8UC02RDU},	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
	{ 802	,8	,1	, &fEM_B8UL01RDU},	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 803	,8	,1	, &fEM_B8UL05RDU},	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
	{ 804	,8	,1	, &fEM_B8UL03RDU},	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
	{ 805	,8	,1	, &fEM_B8UL06RDU},	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
	{ 806	,8	,1	, &fEM_A9UZ03RDU},	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
	{ 807	,8	,1	, &fEM_A9UZ04RDU},	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
	{ 808	,8	,1	, &fEM_A9UZ05RDU},	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
	{ 809	,8	,1	, &fEM_R4UZ04RDU},	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
	{ 810	,8	,1	, &fEM_R4UZ03RDU},	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
	{ 811	,8	,1	, &fEM_R4UZ05RDU},	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
	{ 812	,8	,1	, &fEM_A5UZ03RDU},	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
	{ 813	,8	,1	, &fEM_A5UZ04RDU},	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
	{ 814	,8	,1	, &fEM_A5UZ05RDU},	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
	{ 815	,8	,1	, &fEM_A4UZ03RDU},	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
	{ 816	,8	,1	, &fEM_A4UZ04RDU},	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
	{ 817	,8	,1	, &fEM_A4UZ05RDU},	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
	{ 818	,8	,1	, &fEM_A6UZ03RDU},	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
	{ 819	,8	,1	, &fEM_A6UZ04RDU},	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
	{ 820	,8	,1	, &fEM_A6UZ05RDU},	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
	{ 821	,8	,1	, &fEM_R1UZ03RDU},	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
	{ 822	,8	,1	, &fEM_R1UZ04RDU},	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
	{ 823	,8	,1	, &fEM_R1UZ05RDU},	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
	{ 824	,8	,1	, &fEM_R0UL04RDU},	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
	{ 825	,8	,1	, &fEM_R0UL06RDU},	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
	{ 826	,8	,1	, &fEM_R0UL03RDU},	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
	{ 827	,8	,1	, &fEM_R0UL17RDU},	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
	{ 828	,8	,1	, &fEM_R0UL19RDU},	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{ 829	,8	,1	, &fEM_R0UL07RDU},	//(R0UL07RDU) Время срабатывания верхней АС II УР
	{ 830	,8	,1	, &fEM_R0UL18RDU},	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
	{ 831	,8	,1	, &fEM_R0UL16RDU},	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
	{ 832	,8	,1	, &fEM_R0UL02RDU},	//(R0UL02RDU) Время задержки  ИНИ
	{ 833	,8	,1	, &fEM_R0UN08RDU},	//(R0UN08RDU) 8-я заданная мощность
	{ 834	,8	,1	, &fEM_R0UN07RDU},	//(R0UN07RDU) 7-я заданная мощность
	{ 835	,8	,1	, &fEM_R0UN06RDU},	//(R0UN06RDU) 6-я заданная мощность
	{ 836	,8	,1	, &fEM_R0UN05RDU},	//(R0UN05RDU) 5-я заданная мощность
	{ 837	,8	,1	, &fEM_R0UN04RDU},	//(R0UN04RDU) 4-я заданная мощность
	{ 838	,8	,1	, &fEM_R0UN03RDU},	//(R0UN03RDU) Ограничение 3 по мощности
	{ 839	,8	,1	, &fEM_R0UN02RDU},	//(R0UN02RDU) 2-я заданная мощность
	{ 840	,8	,1	, &fEM_R0UN01RDU},	//(R0UN01RDU) 1-я заданная мощность
	{ 841	,8	,1	, &fEM_A2UC82RDU},	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
	{ 842	,8	,1	, &fEM_A2UC83RDU},	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
	{ 843	,8	,1	, &fEM_A1UC83RDU},	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
	{ 844	,8	,1	, &fEM_A2UC81RDU},	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
	{ 845	,8	,1	, &fEM_A1UC81RDU},	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
	{ 846	,8	,1	, &fEM_A1UC82RDU},	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
	{ 847	,8	,1	, &fEM_A2UL83RDU},	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{ 848	,8	,1	, &fEM_A3UC81RDU},	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
	{ 849	,8	,1	, &fEM_A3UC82RDU},	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
	{ 850	,8	,1	, &fEM_R0UN80RDU},	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
	{ 851	,3	,1	, &iEM_A2UV01IDU},	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
	{ 852	,3	,1	, &iEM_A2UV02IDU},	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
	{ 853	,3	,1	, &iEM_A1UV01IDU},	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
	{ 854	,3	,1	, &iEM_A1UV02IDU},	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
	{ 855	,3	,1	, &iEM_A1UV03IDU},	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
	{ 856	,3	,1	, &iEM_A3UV01IDU},	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
	{ 857	,3	,1	, &iEM_A3UV02IDU},	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
	{ 858	,1	,1	, &lEM_R0MD01LC1},	//(R0MD01LC1) Ручное управление ОРР
	{ 859	,8	,1	, &fEM_A3UC09RDU},	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
	{ 860	,8	,1	, &fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
	{ 861	,8	,1	, &fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
	{ 862	,8	,1	, &fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
	{ 863	,8	,1	, &fEM_R0UL21RDU},	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
	{ 864	,8	,1	, &fEM_R0UN09RDU},	//(R0UN09RDU) Минимальный период при регулировании мощности
	{ 865	,8	,1	, &fEM_R0UN11RDU},	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
	{ 866	,8	,1	, &fEM_R0UN12RDU},	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
	{ 867	,8	,1	, &fEM_R0UN13RDU},	//(R0UN13RDU) Минимальное изменение координаты, мм
	{ 868	,8	,1	, &fEM_R0UN14RDU},	//(R0UN14RDU) Максимальная координата штока ИМ, мм
	{ 869	,8	,1	, &fEM_R0UN16RDU},	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
	{ 870	,8	,1	, &fEM_R0UN17RDU},	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
	{ 871	,8	,1	, &fEM_R0UN18RDU},	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
	{ 872	,8	,1	, &fEM_R0UN19RDU},	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
	{ 873	,8	,1	, &fEM_R0UN70LDU},	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
	{ 874	,8	,1	, &fEM_R0UN71LDU},	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
	{ 875	,8	,1	, &fEM_R0UN72LDU},	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
	{ 876	,8	,1	, &fEM_R0UN73LDU},	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
	{ 877	,8	,1	, &fEM_R0UN74LDU},	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
	{ 878	,8	,1	, &fEM_R0UN75LDU},	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
	{ 879	,8	,1	, &fEM_R0UN80LDU},	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
	{ 880	,8	,1	, &fEM_R0UN81LDU},	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
	{ 881	,8	,1	, &fEM_R0UN82LDU},	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
	{ 882	,8	,1	, &fEM_R0UN83LDU},	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
	{ 883	,8	,1	, &fEM_R0UN84LDU},	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
	{ 884	,8	,1	, &fEM_R0UN85LDU},	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
	{ 885	,8	,1	, &fEM_R0UT20RDU},	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
	{ 886	,8	,1	, &fEM_R0UN25RDU},	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
	{ 887	,8	,1	, &fEM_R0UN15RDU},	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
	{ 888	,8	,1	, &fEM_R0UN26RDU},	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
	{ 889	,8	,1	, &fEM_R0UN27RDU},	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
	{ 890	,8	,1	, &fEM_R0UN24RDU},	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 891	,8	,1	, &fEM_R0UL25RDU},	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{ 892	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 893	,8	,1	, &internal2_m182_y0},	//(internal2_m182_y0) y0
	{ 894	,8	,1	, &internal2_m180_y0},	//(internal2_m180_y0) y0
	{ 895	,1	,1	, &internal2_m215_y0},	//(internal2_m215_y0) state
	{ 896	,1	,1	, &internal2_m207_y0},	//(internal2_m207_y0) state
	{ 897	,1	,1	, &internal2_m196_y1},	//(internal2_m196_y1) y1 - внутренний параметр
	{ 898	,1	,1	, &internal2_m203_y1},	//(internal2_m203_y1) y1 - внутренний параметр
	{ 899	,1	,1	, &internal2_m185_y1},	//(internal2_m185_y1) y1 - внутренний параметр
	{ 900	,1	,1	, &internal2_m193_y1},	//(internal2_m193_y1) y1 - внутренний параметр
	{ 901	,5	,1	, &internal2_m17_Nk0},	//(internal2_m17_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 902	,1	,1	, &internal2_m17_SetFlag},	//(internal2_m17_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 903	,5	,1	, &internal2_m110_Nk0},	//(internal2_m110_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 904	,1	,1	, &internal2_m110_SetFlag},	//(internal2_m110_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 905	,5	,1	, &internal2_m106_Nk0},	//(internal2_m106_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 906	,1	,1	, &internal2_m106_SetFlag},	//(internal2_m106_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 907	,5	,1	, &internal2_m79_Nk0},	//(internal2_m79_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 908	,1	,1	, &internal2_m79_SetFlag},	//(internal2_m79_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 909	,5	,1	, &internal2_m83_Nk0},	//(internal2_m83_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 910	,1	,1	, &internal2_m83_SetFlag},	//(internal2_m83_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 911	,5	,1	, &internal2_m45_Nk0},	//(internal2_m45_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 912	,1	,1	, &internal2_m45_SetFlag},	//(internal2_m45_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 913	,5	,1	, &internal2_m53_Nk0},	//(internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 914	,1	,1	, &internal2_m53_SetFlag},	//(internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 915	,5	,1	, &internal2_m15_Nk0},	//(internal2_m15_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 916	,1	,1	, &internal2_m15_SetFlag},	//(internal2_m15_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 917	,8	,1	, &internal1_m1236_tx},	//(internal1_m1236_tx) tx - внутренний параметр
	{ 918	,8	,1	, &internal1_m1217_tx},	//(internal1_m1217_tx) tx - внутренний параметр
	{ 919	,8	,1	, &internal1_m1218_tx},	//(internal1_m1218_tx) tx - внутренний параметр
	{ 920	,8	,1	, &internal1_m1239_tx},	//(internal1_m1239_tx) tx - внутренний параметр
	{ 921	,8	,1	, &internal1_m824_tx},	//(internal1_m824_tx) tx - внутренний параметр
	{ 922	,8	,1	, &internal1_m832_tx},	//(internal1_m832_tx) tx - внутренний параметр
	{ 923	,8	,1	, &internal1_m823_tx},	//(internal1_m823_tx) tx - внутренний параметр
	{ 924	,8	,1	, &internal1_m822_tx},	//(internal1_m822_tx) tx - внутренний параметр
	{ 925	,1	,1	, &internal1_m1683_q0},	//(internal1_m1683_q0) q0 - внутренний параметр
	{ 926	,1	,1	, &internal1_m2116_q0},	//(internal1_m2116_q0) q0 - внутренний параметр
	{ 927	,1	,1	, &internal1_m2100_q0},	//(internal1_m2100_q0) q0 - внутренний параметр
	{ 928	,1	,1	, &internal1_m2147_q0},	//(internal1_m2147_q0) q0 - внутренний параметр
	{ 929	,1	,1	, &internal1_m2131_q0},	//(internal1_m2131_q0) q0 - внутренний параметр
	{ 930	,1	,1	, &internal1_m2122_q0},	//(internal1_m2122_q0) q0 - внутренний параметр
	{ 931	,1	,1	, &internal1_m2103_q0},	//(internal1_m2103_q0) q0 - внутренний параметр
	{ 932	,1	,1	, &internal1_m2120_q0},	//(internal1_m2120_q0) q0 - внутренний параметр
	{ 933	,1	,1	, &internal1_m2101_q0},	//(internal1_m2101_q0) q0 - внутренний параметр
	{ 934	,1	,1	, &internal1_m2099_q0},	//(internal1_m2099_q0) q0 - внутренний параметр
	{ 935	,1	,1	, &internal1_m2098_q0},	//(internal1_m2098_q0) q0 - внутренний параметр
	{ 936	,1	,1	, &internal1_m2112_q0},	//(internal1_m2112_q0) q0 - внутренний параметр
	{ 937	,1	,1	, &internal1_m2110_q0},	//(internal1_m2110_q0) q0 - внутренний параметр
	{ 938	,1	,1	, &internal1_m2118_q0},	//(internal1_m2118_q0) q0 - внутренний параметр
	{ 939	,1	,1	, &internal1_m2114_q0},	//(internal1_m2114_q0) q0 - внутренний параметр
	{ 940	,1	,1	, &internal1_m2153_q0},	//(internal1_m2153_q0) q0 - внутренний параметр
	{ 941	,1	,1	, &internal1_m2134_q0},	//(internal1_m2134_q0) q0 - внутренний параметр
	{ 942	,1	,1	, &internal1_m2151_q0},	//(internal1_m2151_q0) q0 - внутренний параметр
	{ 943	,1	,1	, &internal1_m2133_q0},	//(internal1_m2133_q0) q0 - внутренний параметр
	{ 944	,1	,1	, &internal1_m2130_q0},	//(internal1_m2130_q0) q0 - внутренний параметр
	{ 945	,1	,1	, &internal1_m2129_q0},	//(internal1_m2129_q0) q0 - внутренний параметр
	{ 946	,1	,1	, &internal1_m2143_q0},	//(internal1_m2143_q0) q0 - внутренний параметр
	{ 947	,1	,1	, &internal1_m2141_q0},	//(internal1_m2141_q0) q0 - внутренний параметр
	{ 948	,8	,1	, &internal1_m2019_tx},	//(internal1_m2019_tx) tx - внутренний параметр
	{ 949	,8	,1	, &internal1_m1998_tx},	//(internal1_m1998_tx) tx - внутренний параметр
	{ 950	,1	,1	, &internal1_m1707_Pv0},	//(internal1_m1707_Pv0)  - Пер. выключатель механизма
	{ 951	,1	,1	, &internal1_m1707_Zv0},	//(internal1_m1707_Zv0)  - Зад. выключатель механизма
	{ 952	,1	,1	, &internal1_m1707_MyFirstEnterFlag},	//(internal1_m1707_MyFirstEnterFlag) MyFirstEnterFlag
	{ 953	,1	,1	, &internal1_m1704_Pv0},	//(internal1_m1704_Pv0)  - Пер. выключатель механизма
	{ 954	,1	,1	, &internal1_m1704_Zv0},	//(internal1_m1704_Zv0)  - Зад. выключатель механизма
	{ 955	,1	,1	, &internal1_m1704_MyFirstEnterFlag},	//(internal1_m1704_MyFirstEnterFlag) MyFirstEnterFlag
	{ 956	,8	,1	, &internal1_m2172_tx},	//(internal1_m2172_tx) tx - время накопленное сек
	{ 957	,18	,1	, &internal1_m2172_y0},	//(internal1_m2172_y0) y0
	{ 958	,8	,1	, &internal1_m2175_tx},	//(internal1_m2175_tx) tx - время накопленное сек
	{ 959	,18	,1	, &internal1_m2175_y0},	//(internal1_m2175_y0) y0
	{ 960	,8	,1	, &internal1_m2174_tx},	//(internal1_m2174_tx) tx - время накопленное сек
	{ 961	,18	,1	, &internal1_m2174_y0},	//(internal1_m2174_y0) y0
	{ 962	,8	,1	, &internal1_m2211_tx},	//(internal1_m2211_tx) tx - внутренний параметр
	{ 963	,8	,1	, &internal1_m2209_tx},	//(internal1_m2209_tx) tx - время накопленное сек
	{ 964	,18	,1	, &internal1_m2209_y0},	//(internal1_m2209_y0) y0
	{ 965	,1	,1	, &internal1_m2214_q0},	//(internal1_m2214_q0) q0 - внутренний параметр
	{ 966	,1	,1	, &internal1_m2181_q0},	//(internal1_m2181_q0) q0 - внутренний параметр
	{ 967	,8	,1	, &internal1_m2189_tx},	//(internal1_m2189_tx) tx - внутренний параметр
	{ 968	,1	,1	, &internal1_m2187_q0},	//(internal1_m2187_q0) q0 - внутренний параметр
	{ 969	,8	,1	, &internal1_m2013_tx},	//(internal1_m2013_tx) tx - время накопленное сек
	{ 970	,18	,1	, &internal1_m2013_y0},	//(internal1_m2013_y0) y0
	{ 971	,8	,1	, &internal1_m2005_tx},	//(internal1_m2005_tx) tx - время накопленное сек
	{ 972	,18	,1	, &internal1_m2005_y0},	//(internal1_m2005_y0) y0
	{ 973	,1	,1	, &internal1_m1693_q0},	//(internal1_m1693_q0) q0 - внутренний параметр
	{ 974	,1	,1	, &internal1_m1698_q0},	//(internal1_m1698_q0) q0 - внутренний параметр
	{ 975	,1	,1	, &internal1_m1690_q0},	//(internal1_m1690_q0) q0 - внутренний параметр
	{ 976	,1	,1	, &internal1_m1732_q0},	//(internal1_m1732_q0) q0 - внутренний параметр
	{ 977	,8	,1	, &internal1_m741_tx},	//(internal1_m741_tx) tx - время накопленное сек
	{ 978	,18	,1	, &internal1_m741_y0},	//(internal1_m741_y0) y0
	{ 979	,8	,1	, &internal1_m2009_tx},	//(internal1_m2009_tx) tx - внутренний параметр
	{ 980	,1	,1	, &internal1_m2012_q0},	//(internal1_m2012_q0) q0 - внутренний параметр
	{ 981	,1	,1	, &internal1_m2004_q0},	//(internal1_m2004_q0) q0 - внутренний параметр
	{ 982	,8	,1	, &internal1_m1974_tx},	//(internal1_m1974_tx) tx - внутренний параметр
	{ 983	,8	,1	, &internal1_m1985_tx},	//(internal1_m1985_tx) tx - внутренний параметр
	{ 984	,8	,1	, &internal1_m1971_tx},	//(internal1_m1971_tx) tx - внутренний параметр
	{ 985	,1	,1	, &internal1_m1977_q0},	//(internal1_m1977_q0) q0 - внутренний параметр
	{ 986	,1	,1	, &internal1_m1989_q0},	//(internal1_m1989_q0) q0 - внутренний параметр
	{ 987	,8	,1	, &internal1_m1947_tx},	//(internal1_m1947_tx) tx - внутренний параметр
	{ 988	,8	,1	, &internal1_m51_tx},	//(internal1_m51_tx) tx - внутренний параметр
	{ 989	,8	,1	, &internal1_m338_tx},	//(internal1_m338_tx) tx - внутренний параметр
	{ 990	,8	,1	, &internal1_m291_tx},	//(internal1_m291_tx) tx - внутренний параметр
	{ 991	,8	,1	, &internal1_m742_tx},	//(internal1_m742_tx) tx - внутренний параметр
	{ 992	,8	,1	, &internal1_m1415_tx},	//(internal1_m1415_tx) tx - внутренний параметр
	{ 993	,8	,1	, &internal1_m113_tx},	//(internal1_m113_tx) tx - внутренний параметр
	{ 994	,8	,1	, &internal1_m115_tx},	//(internal1_m115_tx) tx - внутренний параметр
	{ 995	,8	,1	, &internal1_m120_tx},	//(internal1_m120_tx) tx - внутренний параметр
	{ 996	,8	,1	, &internal1_m21_tx},	//(internal1_m21_tx) tx - внутренний параметр
	{ 997	,8	,1	, &internal1_m13_tx},	//(internal1_m13_tx) tx - внутренний параметр
	{ 998	,8	,1	, &internal1_m1956_tx},	//(internal1_m1956_tx) tx - внутренний параметр
	{ 999	,8	,1	, &internal1_m1944_tx},	//(internal1_m1944_tx) tx - внутренний параметр
	{ 1000	,8	,1	, &internal1_m2052_tx},	//(internal1_m2052_tx) tx - внутренний параметр
	{ 1001	,8	,1	, &internal1_m2056_tx},	//(internal1_m2056_tx) tx - внутренний параметр
	{ 1002	,8	,1	, &internal1_m1869_tx},	//(internal1_m1869_tx) tx - внутренний параметр
	{ 1003	,8	,1	, &internal1_m77_tx},	//(internal1_m77_tx) tx - внутренний параметр
	{ 1004	,8	,1	, &internal1_m309_tx},	//(internal1_m309_tx) tx - время накопленное сек
	{ 1005	,18	,1	, &internal1_m309_y0},	//(internal1_m309_y0) y0
	{ 1006	,8	,1	, &internal1_m1863_tx},	//(internal1_m1863_tx) tx - время накопленное сек
	{ 1007	,18	,1	, &internal1_m1863_y0},	//(internal1_m1863_y0) y0
	{ 1008	,8	,1	, &internal1_m1861_tx},	//(internal1_m1861_tx) tx - время накопленное сек
	{ 1009	,18	,1	, &internal1_m1861_y0},	//(internal1_m1861_y0) y0
	{ 1010	,8	,1	, &internal1_m1850_tx},	//(internal1_m1850_tx) tx - время накопленное сек
	{ 1011	,18	,1	, &internal1_m1850_y0},	//(internal1_m1850_y0) y0
	{ 1012	,8	,1	, &internal1_m1870_q0},	//(internal1_m1870_q0) q0 - внутренний параметр
	{ 1013	,8	,1	, &internal1_m1435_q0},	//(internal1_m1435_q0) q0 - внутренний параметр
	{ 1014	,8	,1	, &internal1_m1474_q0},	//(internal1_m1474_q0) q0 - внутренний параметр
	{ 1015	,8	,1	, &internal1_m1469_q0},	//(internal1_m1469_q0) q0 - внутренний параметр
	{ 1016	,8	,1	, &internal1_m1909_q0},	//(internal1_m1909_q0) q0 - внутренний параметр
	{ 1017	,8	,1	, &internal1_m1886_tx},	//(internal1_m1886_tx) tx - время накопленное сек
	{ 1018	,18	,1	, &internal1_m1886_y0},	//(internal1_m1886_y0) y0
	{ 1019	,8	,1	, &internal1_m1902_tx},	//(internal1_m1902_tx) tx - время накопленное сек
	{ 1020	,18	,1	, &internal1_m1902_y0},	//(internal1_m1902_y0) y0
	{ 1021	,8	,1	, &internal1_m1899_tx},	//(internal1_m1899_tx) tx - время накопленное сек
	{ 1022	,18	,1	, &internal1_m1899_y0},	//(internal1_m1899_y0) y0
	{ 1023	,8	,1	, &internal1_m2034_tx},	//(internal1_m2034_tx) tx - время накопленное сек
	{ 1024	,18	,1	, &internal1_m2034_y0},	//(internal1_m2034_y0) y0
	{ 1025	,8	,1	, &internal1_m2046_tx},	//(internal1_m2046_tx) tx - время накопленное сек
	{ 1026	,18	,1	, &internal1_m2046_y0},	//(internal1_m2046_y0) y0
	{ 1027	,8	,1	, &internal1_m1800_tx},	//(internal1_m1800_tx) tx - время накопленное сек
	{ 1028	,18	,1	, &internal1_m1800_y0},	//(internal1_m1800_y0) y0
	{ 1029	,8	,1	, &internal1_m1799_tx},	//(internal1_m1799_tx) tx - время накопленное сек
	{ 1030	,18	,1	, &internal1_m1799_y0},	//(internal1_m1799_y0) y0
	{ 1031	,8	,1	, &internal1_m1798_tx},	//(internal1_m1798_tx) tx - время накопленное сек
	{ 1032	,18	,1	, &internal1_m1798_y0},	//(internal1_m1798_y0) y0
	{ 1033	,8	,1	, &internal1_m1797_tx},	//(internal1_m1797_tx) tx - время накопленное сек
	{ 1034	,18	,1	, &internal1_m1797_y0},	//(internal1_m1797_y0) y0
	{ 1035	,8	,1	, &internal1_m1487_tx},	//(internal1_m1487_tx) tx - время накопленное сек
	{ 1036	,18	,1	, &internal1_m1487_y0},	//(internal1_m1487_y0) y0
	{ 1037	,8	,1	, &internal1_m1481_tx},	//(internal1_m1481_tx) tx - время накопленное сек
	{ 1038	,18	,1	, &internal1_m1481_y0},	//(internal1_m1481_y0) y0
	{ 1039	,8	,1	, &internal1_m1431_tx},	//(internal1_m1431_tx) tx - время накопленное сек
	{ 1040	,18	,1	, &internal1_m1431_y0},	//(internal1_m1431_y0) y0
	{ 1041	,8	,1	, &internal1_m825_tx},	//(internal1_m825_tx) tx - время накопленное сек
	{ 1042	,18	,1	, &internal1_m825_y0},	//(internal1_m825_y0) y0
	{ 1043	,8	,1	, &internal1_m826_tx},	//(internal1_m826_tx) tx - время накопленное сек
	{ 1044	,18	,1	, &internal1_m826_y0},	//(internal1_m826_y0) y0
	{ 1045	,8	,1	, &internal1_m834_tx},	//(internal1_m834_tx) tx - время накопленное сек
	{ 1046	,18	,1	, &internal1_m834_y0},	//(internal1_m834_y0) y0
	{ 1047	,8	,1	, &internal1_m187_tx},	//(internal1_m187_tx) tx - время накопленное сек
	{ 1048	,18	,1	, &internal1_m187_y0},	//(internal1_m187_y0) y0
	{ 1049	,8	,1	, &internal1_m192_tx},	//(internal1_m192_tx) tx - время накопленное сек
	{ 1050	,18	,1	, &internal1_m192_y0},	//(internal1_m192_y0) y0
	{ 1051	,8	,1	, &internal1_m198_tx},	//(internal1_m198_tx) tx - время накопленное сек
	{ 1052	,18	,1	, &internal1_m198_y0},	//(internal1_m198_y0) y0
	{ 1053	,8	,1	, &internal1_m518_tx},	//(internal1_m518_tx) tx - время накопленное сек
	{ 1054	,18	,1	, &internal1_m518_y0},	//(internal1_m518_y0) y0
	{ 1055	,8	,1	, &internal1_m2084_tx},	//(internal1_m2084_tx) tx - внутренний параметр
	{ 1056	,8	,1	, &internal1_m1172_tx},	//(internal1_m1172_tx) tx - внутренний параметр
	{ 1057	,8	,1	, &internal1_m1601_tx},	//(internal1_m1601_tx) tx - время накопленное сек
	{ 1058	,18	,1	, &internal1_m1601_y0},	//(internal1_m1601_y0) y0
	{ 1059	,8	,1	, &internal1_m1137_tx},	//(internal1_m1137_tx) tx - время накопленное сек
	{ 1060	,18	,1	, &internal1_m1137_y0},	//(internal1_m1137_y0) y0
	{ 1061	,8	,1	, &internal1_m1327_tx},	//(internal1_m1327_tx) tx - время накопленное сек
	{ 1062	,18	,1	, &internal1_m1327_y0},	//(internal1_m1327_y0) y0
	{ 1063	,8	,1	, &internal1_m926_tx},	//(internal1_m926_tx) tx - время накопленное сек
	{ 1064	,18	,1	, &internal1_m926_y0},	//(internal1_m926_y0) y0
	{ 1065	,8	,1	, &internal1_m1242_tx},	//(internal1_m1242_tx) tx - время накопленное сек
	{ 1066	,18	,1	, &internal1_m1242_y0},	//(internal1_m1242_y0) y0
	{ 1067	,1	,1	, &internal1_m1078_q0},	//(internal1_m1078_q0) q0 - внутренний параметр
	{ 1068	,1	,1	, &internal1_m1076_q0},	//(internal1_m1076_q0) q0 - внутренний параметр
	{ 1069	,1	,1	, &internal1_m1075_q0},	//(internal1_m1075_q0) q0 - внутренний параметр
	{ 1070	,1	,1	, &internal1_m1073_q0},	//(internal1_m1073_q0) q0 - внутренний параметр
	{ 1071	,1	,1	, &internal1_m1072_q0},	//(internal1_m1072_q0) q0 - внутренний параметр
	{ 1072	,1	,1	, &internal1_m1070_q0},	//(internal1_m1070_q0) q0 - внутренний параметр
	{ 1073	,1	,1	, &internal1_m1069_q0},	//(internal1_m1069_q0) q0 - внутренний параметр
	{ 1074	,1	,1	, &internal1_m1067_q0},	//(internal1_m1067_q0) q0 - внутренний параметр
	{ 1075	,1	,1	, &internal1_m1066_q0},	//(internal1_m1066_q0) q0 - внутренний параметр
	{ 1076	,1	,1	, &internal1_m52_x0},	//(internal1_m52_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1077	,1	,1	, &internal1_m986_q0},	//(internal1_m986_q0) q0 - внутренний параметр
	{ 1078	,1	,1	, &internal1_m1424_x0},	//(internal1_m1424_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1079	,1	,1	, &internal1_m1468_x0},	//(internal1_m1468_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1080	,1	,1	, &internal1_m1464_x0},	//(internal1_m1464_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1081	,1	,1	, &internal1_m1878_x0},	//(internal1_m1878_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1082	,1	,1	, &internal1_m1843_x0},	//(internal1_m1843_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1083	,1	,1	, &internal1_m1025_q0},	//(internal1_m1025_q0) q0 - внутренний параметр
	{ 1084	,1	,1	, &internal1_m1037_q0},	//(internal1_m1037_q0) q0 - внутренний параметр
	{ 1085	,1	,1	, &internal1_m1049_q0},	//(internal1_m1049_q0) q0 - внутренний параметр
	{ 1086	,1	,1	, &internal1_m1058_q0},	//(internal1_m1058_q0) q0 - внутренний параметр
	{ 1087	,1	,1	, &internal1_m1036_q0},	//(internal1_m1036_q0) q0 - внутренний параметр
	{ 1088	,1	,1	, &internal1_m1051_q0},	//(internal1_m1051_q0) q0 - внутренний параметр
	{ 1089	,1	,1	, &internal1_m1936_q0},	//(internal1_m1936_q0) q0 - внутренний параметр
	{ 1090	,1	,1	, &internal1_m1935_q0},	//(internal1_m1935_q0) q0 - внутренний параметр
	{ 1091	,3	,1	, &internal1_m326_Step},	//(internal1_m326_Step)  - текущий шаг программы
	{ 1092	,18	,10	, &internal1_m326_rz},	//(internal1_m326_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1093	,8	,1	, &internal1_m326_TimS},	//(internal1_m326_TimS) Время от старта программы
	{ 1094	,1	,1	, &internal1_m326_FinPr0},	//(internal1_m326_FinPr0) FinPr - конец программы
	{ 1095	,1	,1	, &internal1_m326_ErrPr0},	//(internal1_m326_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1096	,1	,1	, &internal1_m326_sbINI0},	//(internal1_m326_sbINI0) sbINI - запуск проверки ИНИ
	{ 1097	,1	,1	, &internal1_m326_sbVuIS0},	//(internal1_m326_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1098	,1	,1	, &internal1_m326_sb2UR0},	//(internal1_m326_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1099	,1	,1	, &internal1_m326_sbNupIS0},	//(internal1_m326_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1100	,1	,1	, &internal1_m326_sbVuRB0},	//(internal1_m326_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1101	,1	,1	, &internal1_m326_MyFirstEnterFlag},	//(internal1_m326_MyFirstEnterFlag)  
	{ 1102	,5	,1	, &internal1_m334_x0},	//(internal1_m334_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1103	,5	,1	, &internal1_m293_TimS},	//(internal1_m293_TimS) Время старта
	{ 1104	,3	,1	, &internal1_m268_Step},	//(internal1_m268_Step)  - текущий шаг программы
	{ 1105	,18	,10	, &internal1_m268_rz},	//(internal1_m268_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1106	,8	,1	, &internal1_m268_TimS},	//(internal1_m268_TimS) Время от старта программы
	{ 1107	,1	,1	, &internal1_m268_FinPr0},	//(internal1_m268_FinPr0) FinPr - конец программы
	{ 1108	,1	,1	, &internal1_m268_ErrPr0},	//(internal1_m268_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1109	,1	,1	, &internal1_m268_sbINI0},	//(internal1_m268_sbINI0) sbINI - запуск проверки ИНИ
	{ 1110	,1	,1	, &internal1_m268_sbVuIS0},	//(internal1_m268_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1111	,1	,1	, &internal1_m268_sb2UR0},	//(internal1_m268_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1112	,1	,1	, &internal1_m268_sbNupIS0},	//(internal1_m268_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1113	,1	,1	, &internal1_m268_sbVuRB0},	//(internal1_m268_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1114	,1	,1	, &internal1_m268_MyFirstEnterFlag},	//(internal1_m268_MyFirstEnterFlag)  
	{ 1115	,1	,1	, &internal1_m1398_q0},	//(internal1_m1398_q0) q0 - внутренний параметр
	{ 1116	,3	,1	, &internal1_m1399_Step},	//(internal1_m1399_Step)  - текущий шаг программы
	{ 1117	,18	,6	, &internal1_m1399_rz},	//(internal1_m1399_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1118	,8	,1	, &internal1_m1399_TimS},	//(internal1_m1399_TimS) Время от старта программы
	{ 1119	,1	,1	, &internal1_m1399_FinPr0},	//(internal1_m1399_FinPr0) FinPr - конец программы
	{ 1120	,1	,1	, &internal1_m1399_ErrPr0},	//(internal1_m1399_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1121	,1	,1	, &internal1_m1399_sbINI0},	//(internal1_m1399_sbINI0) sbINI - запуск проверки ИНИ
	{ 1122	,1	,1	, &internal1_m1399_sbVuIS0},	//(internal1_m1399_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1123	,1	,1	, &internal1_m1399_sb2UR0},	//(internal1_m1399_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1124	,1	,1	, &internal1_m1399_sbNupIS0},	//(internal1_m1399_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1125	,1	,1	, &internal1_m1399_sbVuRB0},	//(internal1_m1399_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1126	,1	,1	, &internal1_m1399_MyFirstEnterFlag},	//(internal1_m1399_MyFirstEnterFlag)  
	{ 1127	,1	,1	, &internal1_m1021_q0},	//(internal1_m1021_q0) q0 - внутренний параметр
	{ 1128	,1	,1	, &internal1_m1018_q0},	//(internal1_m1018_q0) q0 - внутренний параметр
	{ 1129	,1	,1	, &internal1_m1020_q0},	//(internal1_m1020_q0) q0 - внутренний параметр
	{ 1130	,1	,1	, &internal1_m1014_q0},	//(internal1_m1014_q0) q0 - внутренний параметр
	{ 1131	,1	,1	, &internal1_m743_q0},	//(internal1_m743_q0) q0 - внутренний параметр
	{ 1132	,1	,1	, &internal1_m336_q0},	//(internal1_m336_q0) q0 - внутренний параметр
	{ 1133	,1	,1	, &internal1_m332_q0},	//(internal1_m332_q0) q0 - внутренний параметр
	{ 1134	,1	,1	, &internal1_m288_q0},	//(internal1_m288_q0) q0 - внутренний параметр
	{ 1135	,5	,1	, &internal1_m287_x0},	//(internal1_m287_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1136	,1	,1	, &internal1_m1865_q0},	//(internal1_m1865_q0) q0 - внутренний параметр
	{ 1137	,1	,1	, &internal1_m1853_q0},	//(internal1_m1853_q0) q0 - внутренний параметр
	{ 1138	,1	,1	, &internal1_m1844_q0},	//(internal1_m1844_q0) q0 - внутренний параметр
	{ 1139	,1	,1	, &internal1_m1919_q0},	//(internal1_m1919_q0) q0 - внутренний параметр
	{ 1140	,1	,1	, &internal1_m1889_q0},	//(internal1_m1889_q0) q0 - внутренний параметр
	{ 1141	,1	,1	, &internal1_m1879_q0},	//(internal1_m1879_q0) q0 - внутренний параметр
	{ 1142	,1	,1	, &internal1_m1451_q0},	//(internal1_m1451_q0) q0 - внутренний параметр
	{ 1143	,1	,1	, &internal1_m1438_x0},	//(internal1_m1438_x0) был приход сигнала x1
	{ 1144	,8	,1	, &internal1_m1438_y0},	//(internal1_m1438_y0) интервал между сигналами х1 и х2
	{ 1145	,1	,1	, &internal1_m1434_q0},	//(internal1_m1434_q0) q0 - внутренний параметр
	{ 1146	,1	,1	, &internal1_m1425_q0},	//(internal1_m1425_q0) q0 - внутренний параметр
	{ 1147	,1	,1	, &internal1_m1484_q0},	//(internal1_m1484_q0) q0 - внутренний параметр
	{ 1148	,1	,1	, &internal1_m1504_q0},	//(internal1_m1504_q0) q0 - внутренний параметр
	{ 1149	,1	,1	, &internal1_m1471_q0},	//(internal1_m1471_q0) q0 - внутренний параметр
	{ 1150	,1	,1	, &internal1_m1485_x0},	//(internal1_m1485_x0) был приход сигнала x1
	{ 1151	,8	,1	, &internal1_m1485_y0},	//(internal1_m1485_y0) интервал между сигналами х1 и х2
	{ 1152	,5	,1	, &internal1_m1409_x0},	//(internal1_m1409_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1153	,1	,1	, &internal1_m1490_q0},	//(internal1_m1490_q0) q0 - внутренний параметр
	{ 1154	,1	,1	, &internal1_m26_q0},	//(internal1_m26_q0) q0 - внутренний параметр
	{ 1155	,1	,1	, &internal1_m1505_q0},	//(internal1_m1505_q0) q0 - внутренний параметр
	{ 1156	,1	,1	, &internal1_m633_q0},	//(internal1_m633_q0) q0 - внутренний параметр
	{ 1157	,1	,1	, &internal1_m618_q0},	//(internal1_m618_q0) q0 - внутренний параметр
	{ 1158	,1	,1	, &internal1_m646_q0},	//(internal1_m646_q0) q0 - внутренний параметр
	{ 1159	,1	,1	, &internal1_m629_q0},	//(internal1_m629_q0) q0 - внутренний параметр
	{ 1160	,1	,1	, &internal1_m613_q0},	//(internal1_m613_q0) q0 - внутренний параметр
	{ 1161	,1	,1	, &internal1_m611_q0},	//(internal1_m611_q0) q0 - внутренний параметр
	{ 1162	,1	,1	, &internal1_m599_q0},	//(internal1_m599_q0) q0 - внутренний параметр
	{ 1163	,5	,1	, &internal1_m1401_q0},	//(internal1_m1401_q0) q0 - внутренний параметр
	{ 1164	,1	,1	, &internal1_m609_q0},	//(internal1_m609_q0) q0 - внутренний параметр
	{ 1165	,1	,1	, &internal1_m109_q0},	//(internal1_m109_q0) q0 - внутренний параметр
	{ 1166	,1	,1	, &internal1_m1637_q0},	//(internal1_m1637_q0) q0 - внутренний параметр
	{ 1167	,1	,1	, &internal1_m1636_q0},	//(internal1_m1636_q0) q0 - внутренний параметр
	{ 1168	,1	,1	, &internal1_m1635_q0},	//(internal1_m1635_q0) q0 - внутренний параметр
	{ 1169	,1	,1	, &internal1_m1634_q0},	//(internal1_m1634_q0) q0 - внутренний параметр
	{ 1170	,1	,1	, &internal1_m1670_q0},	//(internal1_m1670_q0) q0 - внутренний параметр
	{ 1171	,1	,1	, &internal1_m1669_q0},	//(internal1_m1669_q0) q0 - внутренний параметр
	{ 1172	,1	,1	, &internal1_m1668_q0},	//(internal1_m1668_q0) q0 - внутренний параметр
	{ 1173	,1	,1	, &internal1_m1950_q0},	//(internal1_m1950_q0) q0 - внутренний параметр
	{ 1174	,1	,1	, &internal1_m1730_q0},	//(internal1_m1730_q0) q0 - внутренний параметр
	{ 1175	,1	,1	, &internal1_m1719_q0},	//(internal1_m1719_q0) q0 - внутренний параметр
	{ 1176	,1	,1	, &internal1_m1727_q0},	//(internal1_m1727_q0) q0 - внутренний параметр
	{ 1177	,1	,1	, &internal1_m1716_q0},	//(internal1_m1716_q0) q0 - внутренний параметр
	{ 1178	,1	,1	, &internal1_m1724_q0},	//(internal1_m1724_q0) q0 - внутренний параметр
	{ 1179	,1	,1	, &internal1_m2149_q0},	//(internal1_m2149_q0) q0 - внутренний параметр
	{ 1180	,1	,1	, &internal1_m2145_q0},	//(internal1_m2145_q0) q0 - внутренний параметр
	{ 1181	,1	,1	, &internal1_m1695_q0},	//(internal1_m1695_q0) q0 - внутренний параметр
	{ 1182	,1	,1	, &internal1_m1687_q0},	//(internal1_m1687_q0) q0 - внутренний параметр
	{ 1183	,1	,1	, &internal1_m1685_q0},	//(internal1_m1685_q0) q0 - внутренний параметр
	{ 1184	,1	,1	, &internal1_m1681_q0},	//(internal1_m1681_q0) q0 - внутренний параметр
	{ 1185	,1	,1	, &internal1_m1677_q0},	//(internal1_m1677_q0) q0 - внутренний параметр
	{ 1186	,1	,1	, &internal1_m1679_q0},	//(internal1_m1679_q0) q0 - внутренний параметр
	{ 1187	,1	,1	, &internal1_m19_q0},	//(internal1_m19_q0) q0 - внутренний параметр
	{ 1188	,1	,1	, &internal1_m1660_q0},	//(internal1_m1660_q0) q0 - внутренний параметр
	{ 1189	,1	,1	, &internal1_m1658_q0},	//(internal1_m1658_q0) q0 - внутренний параметр
	{ 1190	,1	,1	, &internal1_m1654_q0},	//(internal1_m1654_q0) q0 - внутренний параметр
	{ 1191	,1	,1	, &internal1_m1656_q0},	//(internal1_m1656_q0) q0 - внутренний параметр
	{ 1192	,1	,1	, &internal1_m1652_q0},	//(internal1_m1652_q0) q0 - внутренний параметр
	{ 1193	,1	,1	, &internal1_m1650_q0},	//(internal1_m1650_q0) q0 - внутренний параметр
	{ 1194	,1	,1	, &internal1_m2065_q0},	//(internal1_m2065_q0) q0 - внутренний параметр
	{ 1195	,1	,1	, &internal1_m2061_q0},	//(internal1_m2061_q0) q0 - внутренний параметр
	{ 1196	,1	,1	, &internal1_m2040_q0},	//(internal1_m2040_q0) q0 - внутренний параметр
	{ 1197	,1	,1	, &internal1_m2028_q0},	//(internal1_m2028_q0) q0 - внутренний параметр
	{ 1198	,1	,1	, &internal1_m1961_q0},	//(internal1_m1961_q0) q0 - внутренний параметр
	{ 1199	,1	,1	, &internal1_m1646_q0},	//(internal1_m1646_q0) q0 - внутренний параметр
	{ 1200	,1	,1	, &internal1_m1648_q0},	//(internal1_m1648_q0) q0 - внутренний параметр
	{ 1201	,1	,1	, &internal1_m1632_q0},	//(internal1_m1632_q0) q0 - внутренний параметр
	{ 1202	,1	,1	, &internal1_m1630_q0},	//(internal1_m1630_q0) q0 - внутренний параметр
	{ 1203	,1	,1	, &internal1_m1628_q0},	//(internal1_m1628_q0) q0 - внутренний параметр
	{ 1204	,1	,1	, &internal1_m1626_q0},	//(internal1_m1626_q0) q0 - внутренний параметр
	{ 1205	,1	,1	, &internal1_m1625_q0},	//(internal1_m1625_q0) q0 - внутренний параметр
	{ 1206	,1	,1	, &internal1_m1623_q0},	//(internal1_m1623_q0) q0 - внутренний параметр
	{ 1207	,1	,1	, &internal1_m1622_q0},	//(internal1_m1622_q0) q0 - внутренний параметр
	{ 1208	,1	,1	, &internal1_m1620_q0},	//(internal1_m1620_q0) q0 - внутренний параметр
	{ 1209	,18	,1	, &internal1_m2089_DvUp0},	//(internal1_m2089_DvUp0) - есть команда на движение вперёд
	{ 1210	,18	,1	, &internal1_m2089_DvDw0},	//(internal1_m2089_DvDw0) - есть команда на движение назад
	{ 1211	,18	,1	, &internal1_m2089_FDvUp0},	//(internal1_m2089_FDvUp0) - есть команда на движение вперёд
	{ 1212	,18	,1	, &internal1_m2089_FDvDw0},	//(internal1_m2089_FDvDw0) - есть команда на движение назад
	{ 1213	,18	,1	, &internal1_m2089_BlDv0},	//(internal1_m2089_BlDv0) - была блокировка
	{ 1214	,18	,1	, &internal1_m2089_Pkv0},	//(internal1_m2089_Pkv0) Pkv - передний конечный выключатель
	{ 1215	,18	,1	, &internal1_m2089_Pkav0},	//(internal1_m2089_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1216	,18	,1	, &internal1_m2089_Zkv0},	//(internal1_m2089_Zkv0) Zkv - задний конечный выключатель
	{ 1217	,18	,1	, &internal1_m2089_Zkav0},	//(internal1_m2089_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1218	,8	,1	, &internal1_m2089_txNm},	//(internal1_m2089_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1219	,8	,1	, &internal1_m2089_txSm},	//(internal1_m2089_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1220	,8	,1	, &internal1_m2089_txHr},	//(internal1_m2089_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1221	,8	,1	, &internal1_m2089_txLd},	//(internal1_m2089_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1222	,18	,1	, &internal1_m2089_fef},	//(internal1_m2089_fef) fef
	{ 1223	,18	,1	, &internal1_m2083_DvUp0},	//(internal1_m2083_DvUp0) - есть команда на движение вперёд
	{ 1224	,18	,1	, &internal1_m2083_DvDw0},	//(internal1_m2083_DvDw0) - есть команда на движение назад
	{ 1225	,18	,1	, &internal1_m2083_FDvUp0},	//(internal1_m2083_FDvUp0) - есть команда на движение вперёд
	{ 1226	,18	,1	, &internal1_m2083_FDvDw0},	//(internal1_m2083_FDvDw0) - есть команда на движение назад
	{ 1227	,18	,1	, &internal1_m2083_BlDv0},	//(internal1_m2083_BlDv0) - была блокировка
	{ 1228	,18	,1	, &internal1_m2083_Pkv0},	//(internal1_m2083_Pkv0) Pkv - передний конечный выключатель
	{ 1229	,18	,1	, &internal1_m2083_Pkav0},	//(internal1_m2083_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1230	,18	,1	, &internal1_m2083_Zkv0},	//(internal1_m2083_Zkv0) Zkv - задний конечный выключатель
	{ 1231	,18	,1	, &internal1_m2083_Zkav0},	//(internal1_m2083_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1232	,8	,1	, &internal1_m2083_txNm},	//(internal1_m2083_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1233	,8	,1	, &internal1_m2083_txSm},	//(internal1_m2083_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1234	,8	,1	, &internal1_m2083_txHr},	//(internal1_m2083_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1235	,8	,1	, &internal1_m2083_txLd},	//(internal1_m2083_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1236	,18	,1	, &internal1_m2083_fef},	//(internal1_m2083_fef) fef
	{ 1237	,1	,1	, &internal1_m1476_q0},	//(internal1_m1476_q0) q0 - внутренний параметр
	{ 1238	,1	,1	, &internal1_m1479_x0},	//(internal1_m1479_x0) был приход сигнала x1
	{ 1239	,8	,1	, &internal1_m1479_y0},	//(internal1_m1479_y0) интервал между сигналами х1 и х2
	{ 1240	,1	,1	, &internal1_m1901_x0},	//(internal1_m1901_x0) был приход сигнала x1
	{ 1241	,8	,1	, &internal1_m1901_y0},	//(internal1_m1901_y0) интервал между сигналами х1 и х2
	{ 1242	,1	,1	, &internal1_m1862_x0},	//(internal1_m1862_x0) был приход сигнала x1
	{ 1243	,8	,1	, &internal1_m1862_y0},	//(internal1_m1862_y0) интервал между сигналами х1 и х2
	{ 1244	,1	,1	, &internal1_m279_q0},	//(internal1_m279_q0) q0 - внутренний параметр
	{ 1245	,1	,1	, &internal1_m994_q0},	//(internal1_m994_q0) q0 - внутренний параметр
	{ 1246	,1	,1	, &internal1_m621_q0},	//(internal1_m621_q0) q0 - внутренний параметр
	{ 1247	,8	,1	, &internal1_m1298_X0},	//(internal1_m1298_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1248	,8	,1	, &internal1_m1298_t0},	//(internal1_m1298_t0) время нахождения в зоне возврата
	{ 1249	,18	,1	, &internal1_m1298_BLDv0},	//(internal1_m1298_BLDv0) BlDv - Блокировка движения
	{ 1250	,8	,1	, &internal1_m1317_tx},	//(internal1_m1317_tx) tx - время накопленное сек
	{ 1251	,18	,1	, &internal1_m1317_y0},	//(internal1_m1317_y0) y0
	{ 1252	,8	,1	, &internal1_m1319_tx},	//(internal1_m1319_tx) tx - время накопленное сек
	{ 1253	,18	,1	, &internal1_m1319_y0},	//(internal1_m1319_y0) y0
	{ 1254	,3	,1	, &internal1_m1326_xptr},	//(internal1_m1326_xptr) указатель текущей позиции в массиве координат
	{ 1255	,8	,60	, &internal1_m1326_x0},	//(internal1_m1326_x0) x0 - массив мгновенных значений координат
	{ 1256	,8	,60	, &internal1_m1326_tim0},	//(internal1_m1326_tim0) tim0 - массив значений времени цикла
	{ 1257	,8	,1	, &internal1_m1326_sumtim},	//(internal1_m1326_sumtim) sumtim - время в пути
	{ 1258	,8	,1	, &internal1_m1326_StSpeed},	//(internal1_m1326_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1259	,8	,1	, &internal1_m1326_Vz0},	//(internal1_m1326_Vz0) Vz0 - предыдущая заданная скорость
	{ 1260	,3	,1	, &internal1_m1326_flRazg},	//(internal1_m1326_flRazg) признак разгона/торможения
	{ 1261	,8	,1	, &internal1_m1326_DelSp},	//(internal1_m1326_DelSp) DelSp - время переключения скоростей
	{ 1262	,8	,1	, &internal1_m1326_z0},	//(internal1_m1326_z0) z0 - точка прекращения движения
	{ 1263	,8	,1	, &internal1_m1326_txZS},	//(internal1_m1326_txZS) txZS
	{ 1264	,8	,1	, &internal1_m1326_tx},	//(internal1_m1326_tx) tx
	{ 1265	,8	,1	, &internal1_m1326_txd},	//(internal1_m1326_txd) txd
	{ 1266	,8	,1	, &internal1_m1326_txMBl},	//(internal1_m1326_txMBl) tx
	{ 1267	,8	,1	, &internal1_m1326_txBl},	//(internal1_m1326_txBl) tx
	{ 1268	,8	,1	, &internal1_m1326_Speed0},	//(internal1_m1326_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1269	,8	,1	, &internal1_m1326_xz0},	//(internal1_m1326_xz0) xz0 - новое задание мм
	{ 1270	,8	,1	, &internal1_m1326_tz0},	//(internal1_m1326_tz0) tz0 - время защиты от нового задания сек
	{ 1271	,1	,1	, &internal1_m1326_Shift0},	//(internal1_m1326_Shift0) Shift0 - признак самохода
	{ 1272	,1	,1	, &internal1_m1326_ShCntlSp0},	//(internal1_m1326_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1273	,1	,1	, &internal1_m1326_ShiftControl},	//(internal1_m1326_ShiftControl) ShiftControl - признак самохода
	{ 1274	,1	,1	, &internal1_m619_q0},	//(internal1_m619_q0) q0 - внутренний параметр
	{ 1275	,8	,1	, &internal1_m892_X0},	//(internal1_m892_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1276	,8	,1	, &internal1_m892_t0},	//(internal1_m892_t0) время нахождения в зоне возврата
	{ 1277	,18	,1	, &internal1_m892_BLDv0},	//(internal1_m892_BLDv0) BlDv - Блокировка движения
	{ 1278	,8	,1	, &internal1_m916_tx},	//(internal1_m916_tx) tx - время накопленное сек
	{ 1279	,18	,1	, &internal1_m916_y0},	//(internal1_m916_y0) y0
	{ 1280	,8	,1	, &internal1_m918_tx},	//(internal1_m918_tx) tx - время накопленное сек
	{ 1281	,18	,1	, &internal1_m918_y0},	//(internal1_m918_y0) y0
	{ 1282	,3	,1	, &internal1_m925_xptr},	//(internal1_m925_xptr) указатель текущей позиции в массиве координат
	{ 1283	,8	,60	, &internal1_m925_x0},	//(internal1_m925_x0) x0 - массив мгновенных значений координат
	{ 1284	,8	,60	, &internal1_m925_tim0},	//(internal1_m925_tim0) tim0 - массив значений времени цикла
	{ 1285	,8	,1	, &internal1_m925_sumtim},	//(internal1_m925_sumtim) sumtim - время в пути
	{ 1286	,8	,1	, &internal1_m925_StSpeed},	//(internal1_m925_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1287	,8	,1	, &internal1_m925_Vz0},	//(internal1_m925_Vz0) Vz0 - предыдущая заданная скорость
	{ 1288	,3	,1	, &internal1_m925_flRazg},	//(internal1_m925_flRazg) признак разгона/торможения
	{ 1289	,8	,1	, &internal1_m925_DelSp},	//(internal1_m925_DelSp) DelSp - время переключения скоростей
	{ 1290	,8	,1	, &internal1_m925_z0},	//(internal1_m925_z0) z0 - точка прекращения движения
	{ 1291	,8	,1	, &internal1_m925_txZS},	//(internal1_m925_txZS) txZS
	{ 1292	,8	,1	, &internal1_m925_tx},	//(internal1_m925_tx) tx
	{ 1293	,8	,1	, &internal1_m925_txd},	//(internal1_m925_txd) txd
	{ 1294	,8	,1	, &internal1_m925_txMBl},	//(internal1_m925_txMBl) tx
	{ 1295	,8	,1	, &internal1_m925_txBl},	//(internal1_m925_txBl) tx
	{ 1296	,8	,1	, &internal1_m925_Speed0},	//(internal1_m925_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1297	,8	,1	, &internal1_m925_xz0},	//(internal1_m925_xz0) xz0 - новое задание мм
	{ 1298	,8	,1	, &internal1_m925_tz0},	//(internal1_m925_tz0) tz0 - время защиты от нового задания сек
	{ 1299	,1	,1	, &internal1_m925_Shift0},	//(internal1_m925_Shift0) Shift0 - признак самохода
	{ 1300	,1	,1	, &internal1_m925_ShCntlSp0},	//(internal1_m925_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1301	,1	,1	, &internal1_m925_ShiftControl},	//(internal1_m925_ShiftControl) ShiftControl - признак самохода
	{ 1302	,8	,1	, &internal1_m490_X0},	//(internal1_m490_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1303	,8	,1	, &internal1_m490_t0},	//(internal1_m490_t0) время нахождения в зоне возврата
	{ 1304	,18	,1	, &internal1_m490_BLDv0},	//(internal1_m490_BLDv0) BlDv - Блокировка движения
	{ 1305	,8	,1	, &internal1_m510_tx},	//(internal1_m510_tx) tx - время накопленное сек
	{ 1306	,18	,1	, &internal1_m510_y0},	//(internal1_m510_y0) y0
	{ 1307	,8	,1	, &internal1_m512_tx},	//(internal1_m512_tx) tx - время накопленное сек
	{ 1308	,18	,1	, &internal1_m512_y0},	//(internal1_m512_y0) y0
	{ 1309	,3	,1	, &internal1_m517_xptr},	//(internal1_m517_xptr) указатель текущей позиции в массиве координат
	{ 1310	,8	,150	, &internal1_m517_x0},	//(internal1_m517_x0) x0 - массив мгновенных значений координат
	{ 1311	,8	,150	, &internal1_m517_tim0},	//(internal1_m517_tim0) tim0 - массив значений времени цикла
	{ 1312	,8	,1	, &internal1_m517_sumtim},	//(internal1_m517_sumtim) sumtim - время в пути
	{ 1313	,8	,1	, &internal1_m517_StSpeed},	//(internal1_m517_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1314	,8	,1	, &internal1_m517_Vz0},	//(internal1_m517_Vz0) Vz0 - предыдущая заданная скорость
	{ 1315	,3	,1	, &internal1_m517_flRazg},	//(internal1_m517_flRazg) признак разгона/торможения
	{ 1316	,8	,1	, &internal1_m517_DelSp},	//(internal1_m517_DelSp) DelSp - время переключения скоростей
	{ 1317	,8	,1	, &internal1_m517_z0},	//(internal1_m517_z0) z0 - точка прекращения движения
	{ 1318	,8	,1	, &internal1_m517_txZS},	//(internal1_m517_txZS) txZS
	{ 1319	,8	,1	, &internal1_m517_tx},	//(internal1_m517_tx) tx
	{ 1320	,8	,1	, &internal1_m517_txd},	//(internal1_m517_txd) txd
	{ 1321	,8	,1	, &internal1_m517_txMBl},	//(internal1_m517_txMBl) tx
	{ 1322	,8	,1	, &internal1_m517_txBl},	//(internal1_m517_txBl) tx
	{ 1323	,8	,1	, &internal1_m517_Speed0},	//(internal1_m517_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1324	,8	,1	, &internal1_m517_xz0},	//(internal1_m517_xz0) xz0 - новое задание мм
	{ 1325	,8	,1	, &internal1_m517_tz0},	//(internal1_m517_tz0) tz0 - время защиты от нового задания сек
	{ 1326	,1	,1	, &internal1_m517_Shift0},	//(internal1_m517_Shift0) Shift0 - признак самохода
	{ 1327	,1	,1	, &internal1_m517_ShCntlSp0},	//(internal1_m517_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1328	,1	,1	, &internal1_m517_ShiftControl},	//(internal1_m517_ShiftControl) ShiftControl - признак самохода
	{ 1329	,1	,1	, &internal1_m616_q0},	//(internal1_m616_q0) q0 - внутренний параметр
	{ 1330	,8	,1	, &internal1_m168_X0},	//(internal1_m168_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1331	,8	,1	, &internal1_m168_t0},	//(internal1_m168_t0) время нахождения в зоне возврата
	{ 1332	,18	,1	, &internal1_m168_BLDv0},	//(internal1_m168_BLDv0) BlDv - Блокировка движения
	{ 1333	,3	,1	, &internal1_m197_xptr},	//(internal1_m197_xptr) указатель текущей позиции в массиве координат
	{ 1334	,8	,150	, &internal1_m197_x0},	//(internal1_m197_x0) x0 - массив мгновенных значений координат
	{ 1335	,8	,150	, &internal1_m197_tim0},	//(internal1_m197_tim0) tim0 - массив значений времени цикла
	{ 1336	,8	,1	, &internal1_m197_sumtim},	//(internal1_m197_sumtim) sumtim - время в пути
	{ 1337	,8	,1	, &internal1_m197_StSpeed},	//(internal1_m197_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1338	,8	,1	, &internal1_m197_Vz0},	//(internal1_m197_Vz0) Vz0 - предыдущая заданная скорость
	{ 1339	,3	,1	, &internal1_m197_flRazg},	//(internal1_m197_flRazg) признак разгона/торможения
	{ 1340	,8	,1	, &internal1_m197_DelSp},	//(internal1_m197_DelSp) DelSp - время переключения скоростей
	{ 1341	,8	,1	, &internal1_m197_z0},	//(internal1_m197_z0) z0 - точка прекращения движения
	{ 1342	,8	,1	, &internal1_m197_txZS},	//(internal1_m197_txZS) txZS
	{ 1343	,8	,1	, &internal1_m197_tx},	//(internal1_m197_tx) tx
	{ 1344	,8	,1	, &internal1_m197_txd},	//(internal1_m197_txd) txd
	{ 1345	,8	,1	, &internal1_m197_txMBl},	//(internal1_m197_txMBl) tx
	{ 1346	,8	,1	, &internal1_m197_txBl},	//(internal1_m197_txBl) tx
	{ 1347	,8	,1	, &internal1_m197_Speed0},	//(internal1_m197_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1348	,8	,1	, &internal1_m197_xz0},	//(internal1_m197_xz0) xz0 - новое задание мм
	{ 1349	,8	,1	, &internal1_m197_tz0},	//(internal1_m197_tz0) tz0 - время защиты от нового задания сек
	{ 1350	,1	,1	, &internal1_m197_Shift0},	//(internal1_m197_Shift0) Shift0 - признак самохода
	{ 1351	,1	,1	, &internal1_m197_ShCntlSp0},	//(internal1_m197_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1352	,1	,1	, &internal1_m197_ShiftControl},	//(internal1_m197_ShiftControl) ShiftControl - признак самохода
	{ 1353	,1	,1	, &internal1_m642_q0},	//(internal1_m642_q0) q0 - внутренний параметр
	{ 1354	,18	,1	, &internal1_m461_DvUp0},	//(internal1_m461_DvUp0) - есть команда на движение вперёд
	{ 1355	,18	,1	, &internal1_m461_DvDw0},	//(internal1_m461_DvDw0) - есть команда на движение назад
	{ 1356	,18	,1	, &internal1_m461_FDvUp0},	//(internal1_m461_FDvUp0) - есть команда на движение вперёд
	{ 1357	,18	,1	, &internal1_m461_FDvDw0},	//(internal1_m461_FDvDw0) - есть команда на движение назад
	{ 1358	,18	,1	, &internal1_m461_BlDv0},	//(internal1_m461_BlDv0) - была блокировка
	{ 1359	,18	,1	, &internal1_m461_Pkv0},	//(internal1_m461_Pkv0) Pkv - передний конечный выключатель
	{ 1360	,18	,1	, &internal1_m461_Pkav0},	//(internal1_m461_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1361	,18	,1	, &internal1_m461_Zkv0},	//(internal1_m461_Zkv0) Zkv - задний конечный выключатель
	{ 1362	,18	,1	, &internal1_m461_Zkav0},	//(internal1_m461_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1363	,8	,1	, &internal1_m461_txNm},	//(internal1_m461_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1364	,8	,1	, &internal1_m461_txSm},	//(internal1_m461_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1365	,8	,1	, &internal1_m461_txHr},	//(internal1_m461_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1366	,8	,1	, &internal1_m461_txLd},	//(internal1_m461_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1367	,18	,1	, &internal1_m461_fef},	//(internal1_m461_fef) fef
	{ 1368	,18	,1	, &internal1_m455_DvUp0},	//(internal1_m455_DvUp0) - есть команда на движение вперёд
	{ 1369	,18	,1	, &internal1_m455_DvDw0},	//(internal1_m455_DvDw0) - есть команда на движение назад
	{ 1370	,18	,1	, &internal1_m455_FDvUp0},	//(internal1_m455_FDvUp0) - есть команда на движение вперёд
	{ 1371	,18	,1	, &internal1_m455_FDvDw0},	//(internal1_m455_FDvDw0) - есть команда на движение назад
	{ 1372	,18	,1	, &internal1_m455_BlDv0},	//(internal1_m455_BlDv0) - была блокировка
	{ 1373	,18	,1	, &internal1_m455_Pkv0},	//(internal1_m455_Pkv0) Pkv - передний конечный выключатель
	{ 1374	,18	,1	, &internal1_m455_Pkav0},	//(internal1_m455_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1375	,18	,1	, &internal1_m455_Zkv0},	//(internal1_m455_Zkv0) Zkv - задний конечный выключатель
	{ 1376	,18	,1	, &internal1_m455_Zkav0},	//(internal1_m455_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1377	,8	,1	, &internal1_m455_txNm},	//(internal1_m455_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1378	,8	,1	, &internal1_m455_txSm},	//(internal1_m455_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1379	,8	,1	, &internal1_m455_txHr},	//(internal1_m455_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1380	,8	,1	, &internal1_m455_txLd},	//(internal1_m455_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1381	,18	,1	, &internal1_m455_fef},	//(internal1_m455_fef) fef
	{ 1382	,8	,1	, &internal1_m808_X0},	//(internal1_m808_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1383	,8	,1	, &internal1_m808_t0},	//(internal1_m808_t0) время нахождения в зоне возврата
	{ 1384	,18	,1	, &internal1_m808_BLDv0},	//(internal1_m808_BLDv0) BlDv - Блокировка движения
	{ 1385	,3	,1	, &internal1_m831_xptr},	//(internal1_m831_xptr) указатель текущей позиции в массиве координат
	{ 1386	,8	,80	, &internal1_m831_x0},	//(internal1_m831_x0) x0 - массив мгновенных значений координат
	{ 1387	,8	,80	, &internal1_m831_tim0},	//(internal1_m831_tim0) tim0 - массив значений времени цикла
	{ 1388	,8	,1	, &internal1_m831_sumtim},	//(internal1_m831_sumtim) sumtim - время в пути
	{ 1389	,8	,1	, &internal1_m831_StSpeed},	//(internal1_m831_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1390	,8	,1	, &internal1_m831_Vz0},	//(internal1_m831_Vz0) Vz0 - предыдущая заданная скорость
	{ 1391	,3	,1	, &internal1_m831_flRazg},	//(internal1_m831_flRazg) признак разгона/торможения
	{ 1392	,8	,1	, &internal1_m831_DelSp},	//(internal1_m831_DelSp) DelSp - время переключения скоростей
	{ 1393	,8	,1	, &internal1_m831_z0},	//(internal1_m831_z0) z0 - точка прекращения движения
	{ 1394	,8	,1	, &internal1_m831_txZS},	//(internal1_m831_txZS) txZS
	{ 1395	,8	,1	, &internal1_m831_tx},	//(internal1_m831_tx) tx
	{ 1396	,8	,1	, &internal1_m831_txd},	//(internal1_m831_txd) txd
	{ 1397	,8	,1	, &internal1_m831_txMBl},	//(internal1_m831_txMBl) tx
	{ 1398	,8	,1	, &internal1_m831_txBl},	//(internal1_m831_txBl) tx
	{ 1399	,8	,1	, &internal1_m831_Speed0},	//(internal1_m831_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1400	,8	,1	, &internal1_m831_xz0},	//(internal1_m831_xz0) xz0 - новое задание мм
	{ 1401	,8	,1	, &internal1_m831_tz0},	//(internal1_m831_tz0) tz0 - время защиты от нового задания сек
	{ 1402	,1	,1	, &internal1_m831_Shift0},	//(internal1_m831_Shift0) Shift0 - признак самохода
	{ 1403	,1	,1	, &internal1_m831_ShCntlSp0},	//(internal1_m831_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1404	,1	,1	, &internal1_m831_ShiftControl},	//(internal1_m831_ShiftControl) ShiftControl - признак самохода
	{ 1405	,8	,1	, &internal1_m1580_X0},	//(internal1_m1580_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1406	,8	,1	, &internal1_m1580_t0},	//(internal1_m1580_t0) время нахождения в зоне возврата
	{ 1407	,18	,1	, &internal1_m1580_BLDv0},	//(internal1_m1580_BLDv0) BlDv - Блокировка движения
	{ 1408	,8	,1	, &internal1_m1113_X0},	//(internal1_m1113_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1409	,8	,1	, &internal1_m1113_t0},	//(internal1_m1113_t0) время нахождения в зоне возврата
	{ 1410	,18	,1	, &internal1_m1113_BLDv0},	//(internal1_m1113_BLDv0) BlDv - Блокировка движения
	{ 1411	,1	,1	, &internal1_m614_q0},	//(internal1_m614_q0) q0 - внутренний параметр
	{ 1412	,8	,1	, &internal1_m1197_X0},	//(internal1_m1197_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1413	,8	,1	, &internal1_m1197_t0},	//(internal1_m1197_t0) время нахождения в зоне возврата
	{ 1414	,18	,1	, &internal1_m1197_BLDv0},	//(internal1_m1197_BLDv0) BlDv - Блокировка движения
	{ 1415	,8	,1	, &internal1_m1227_tx},	//(internal1_m1227_tx) tx - время накопленное сек
	{ 1416	,18	,1	, &internal1_m1227_y0},	//(internal1_m1227_y0) y0
	{ 1417	,8	,1	, &internal1_m1226_tx},	//(internal1_m1226_tx) tx - время накопленное сек
	{ 1418	,18	,1	, &internal1_m1226_y0},	//(internal1_m1226_y0) y0
	{ 1419	,3	,1	, &internal1_m1230_xptr},	//(internal1_m1230_xptr) указатель текущей позиции в массиве координат
	{ 1420	,8	,80	, &internal1_m1230_x0},	//(internal1_m1230_x0) x0 - массив мгновенных значений координат
	{ 1421	,8	,80	, &internal1_m1230_tim0},	//(internal1_m1230_tim0) tim0 - массив значений времени цикла
	{ 1422	,8	,1	, &internal1_m1230_sumtim},	//(internal1_m1230_sumtim) sumtim - время в пути
	{ 1423	,8	,1	, &internal1_m1230_StSpeed},	//(internal1_m1230_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1424	,8	,1	, &internal1_m1230_Vz0},	//(internal1_m1230_Vz0) Vz0 - предыдущая заданная скорость
	{ 1425	,3	,1	, &internal1_m1230_flRazg},	//(internal1_m1230_flRazg) признак разгона/торможения
	{ 1426	,8	,1	, &internal1_m1230_DelSp},	//(internal1_m1230_DelSp) DelSp - время переключения скоростей
	{ 1427	,8	,1	, &internal1_m1230_z0},	//(internal1_m1230_z0) z0 - точка прекращения движения
	{ 1428	,8	,1	, &internal1_m1230_txZS},	//(internal1_m1230_txZS) txZS
	{ 1429	,8	,1	, &internal1_m1230_tx},	//(internal1_m1230_tx) tx
	{ 1430	,8	,1	, &internal1_m1230_txd},	//(internal1_m1230_txd) txd
	{ 1431	,8	,1	, &internal1_m1230_txMBl},	//(internal1_m1230_txMBl) tx
	{ 1432	,8	,1	, &internal1_m1230_txBl},	//(internal1_m1230_txBl) tx
	{ 1433	,8	,1	, &internal1_m1230_Speed0},	//(internal1_m1230_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1434	,8	,1	, &internal1_m1230_xz0},	//(internal1_m1230_xz0) xz0 - новое задание мм
	{ 1435	,8	,1	, &internal1_m1230_tz0},	//(internal1_m1230_tz0) tz0 - время защиты от нового задания сек
	{ 1436	,1	,1	, &internal1_m1230_Shift0},	//(internal1_m1230_Shift0) Shift0 - признак самохода
	{ 1437	,1	,1	, &internal1_m1230_ShCntlSp0},	//(internal1_m1230_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1438	,1	,1	, &internal1_m1230_ShiftControl},	//(internal1_m1230_ShiftControl) ShiftControl - признак самохода
	{ 1439	,1	,1	, &internal1_m634_q0},	//(internal1_m634_q0) q0 - внутренний параметр
	{ 1440	,8	,1	, &internal1_m1593_tx},	//(internal1_m1593_tx) tx - время накопленное сек
	{ 1441	,18	,1	, &internal1_m1593_y0},	//(internal1_m1593_y0) y0
	{ 1442	,8	,1	, &internal1_m1597_tx},	//(internal1_m1597_tx) tx - время накопленное сек
	{ 1443	,18	,1	, &internal1_m1597_y0},	//(internal1_m1597_y0) y0
	{ 1444	,18	,1	, &internal1_m1583_DvUp0},	//(internal1_m1583_DvUp0) - есть команда на движение вперёд
	{ 1445	,18	,1	, &internal1_m1583_DvDw0},	//(internal1_m1583_DvDw0) - есть команда на движение назад
	{ 1446	,18	,1	, &internal1_m1583_FDvUp0},	//(internal1_m1583_FDvUp0) - есть команда на движение вперёд
	{ 1447	,18	,1	, &internal1_m1583_FDvDw0},	//(internal1_m1583_FDvDw0) - есть команда на движение назад
	{ 1448	,18	,1	, &internal1_m1583_BlDv0},	//(internal1_m1583_BlDv0) - была блокировка
	{ 1449	,18	,1	, &internal1_m1583_Pkv0},	//(internal1_m1583_Pkv0) Pkv - передний конечный выключатель
	{ 1450	,18	,1	, &internal1_m1583_Pkav0},	//(internal1_m1583_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1451	,18	,1	, &internal1_m1583_Zkv0},	//(internal1_m1583_Zkv0) Zkv - задний конечный выключатель
	{ 1452	,18	,1	, &internal1_m1583_Zkav0},	//(internal1_m1583_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1453	,8	,1	, &internal1_m1583_txNm},	//(internal1_m1583_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1454	,8	,1	, &internal1_m1583_txSm},	//(internal1_m1583_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1455	,8	,1	, &internal1_m1583_txHr},	//(internal1_m1583_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1456	,8	,1	, &internal1_m1583_txLd},	//(internal1_m1583_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1457	,18	,1	, &internal1_m1583_fef},	//(internal1_m1583_fef) fef
	{ 1458	,3	,1	, &internal1_m1600_xptr},	//(internal1_m1600_xptr) указатель текущей позиции в массиве координат
	{ 1459	,8	,20	, &internal1_m1600_x0},	//(internal1_m1600_x0) x0 - массив мгновенных значений координат
	{ 1460	,8	,20	, &internal1_m1600_tim0},	//(internal1_m1600_tim0) tim0 - массив значений времени цикла
	{ 1461	,8	,1	, &internal1_m1600_sumtim},	//(internal1_m1600_sumtim) sumtim - время в пути
	{ 1462	,8	,1	, &internal1_m1600_StSpeed},	//(internal1_m1600_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1463	,8	,1	, &internal1_m1600_Vz0},	//(internal1_m1600_Vz0) Vz0 - предыдущая заданная скорость
	{ 1464	,3	,1	, &internal1_m1600_flRazg},	//(internal1_m1600_flRazg) признак разгона/торможения
	{ 1465	,8	,1	, &internal1_m1600_DelSp},	//(internal1_m1600_DelSp) DelSp - время переключения скоростей
	{ 1466	,8	,1	, &internal1_m1600_z0},	//(internal1_m1600_z0) z0 - точка прекращения движения
	{ 1467	,8	,1	, &internal1_m1600_txZS},	//(internal1_m1600_txZS) txZS
	{ 1468	,8	,1	, &internal1_m1600_tx},	//(internal1_m1600_tx) tx
	{ 1469	,8	,1	, &internal1_m1600_txd},	//(internal1_m1600_txd) txd
	{ 1470	,8	,1	, &internal1_m1600_txMBl},	//(internal1_m1600_txMBl) tx
	{ 1471	,8	,1	, &internal1_m1600_txBl},	//(internal1_m1600_txBl) tx
	{ 1472	,8	,1	, &internal1_m1600_Speed0},	//(internal1_m1600_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1473	,8	,1	, &internal1_m1600_xz0},	//(internal1_m1600_xz0) xz0 - новое задание мм
	{ 1474	,8	,1	, &internal1_m1600_tz0},	//(internal1_m1600_tz0) tz0 - время защиты от нового задания сек
	{ 1475	,1	,1	, &internal1_m1600_Shift0},	//(internal1_m1600_Shift0) Shift0 - признак самохода
	{ 1476	,1	,1	, &internal1_m1600_ShCntlSp0},	//(internal1_m1600_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1477	,1	,1	, &internal1_m1600_ShiftControl},	//(internal1_m1600_ShiftControl) ShiftControl - признак самохода
	{ 1478	,8	,1	, &internal1_m1128_tx},	//(internal1_m1128_tx) tx - время накопленное сек
	{ 1479	,18	,1	, &internal1_m1128_y0},	//(internal1_m1128_y0) y0
	{ 1480	,8	,1	, &internal1_m1132_tx},	//(internal1_m1132_tx) tx - время накопленное сек
	{ 1481	,18	,1	, &internal1_m1132_y0},	//(internal1_m1132_y0) y0
	{ 1482	,1	,1	, &internal1_m624_q0},	//(internal1_m624_q0) q0 - внутренний параметр
	{ 1483	,1	,1	, &internal1_m589_q0},	//(internal1_m589_q0) q0 - внутренний параметр
	{ 1484	,18	,1	, &internal1_m1118_DvUp0},	//(internal1_m1118_DvUp0) - есть команда на движение вперёд
	{ 1485	,18	,1	, &internal1_m1118_DvDw0},	//(internal1_m1118_DvDw0) - есть команда на движение назад
	{ 1486	,18	,1	, &internal1_m1118_FDvUp0},	//(internal1_m1118_FDvUp0) - есть команда на движение вперёд
	{ 1487	,18	,1	, &internal1_m1118_FDvDw0},	//(internal1_m1118_FDvDw0) - есть команда на движение назад
	{ 1488	,18	,1	, &internal1_m1118_BlDv0},	//(internal1_m1118_BlDv0) - была блокировка
	{ 1489	,18	,1	, &internal1_m1118_Pkv0},	//(internal1_m1118_Pkv0) Pkv - передний конечный выключатель
	{ 1490	,18	,1	, &internal1_m1118_Pkav0},	//(internal1_m1118_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1491	,18	,1	, &internal1_m1118_Zkv0},	//(internal1_m1118_Zkv0) Zkv - задний конечный выключатель
	{ 1492	,18	,1	, &internal1_m1118_Zkav0},	//(internal1_m1118_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1493	,8	,1	, &internal1_m1118_txNm},	//(internal1_m1118_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1494	,8	,1	, &internal1_m1118_txSm},	//(internal1_m1118_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1495	,8	,1	, &internal1_m1118_txHr},	//(internal1_m1118_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1496	,8	,1	, &internal1_m1118_txLd},	//(internal1_m1118_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1497	,18	,1	, &internal1_m1118_fef},	//(internal1_m1118_fef) fef
	{ 1498	,3	,1	, &internal1_m1136_xptr},	//(internal1_m1136_xptr) указатель текущей позиции в массиве координат
	{ 1499	,8	,20	, &internal1_m1136_x0},	//(internal1_m1136_x0) x0 - массив мгновенных значений координат
	{ 1500	,8	,20	, &internal1_m1136_tim0},	//(internal1_m1136_tim0) tim0 - массив значений времени цикла
	{ 1501	,8	,1	, &internal1_m1136_sumtim},	//(internal1_m1136_sumtim) sumtim - время в пути
	{ 1502	,8	,1	, &internal1_m1136_StSpeed},	//(internal1_m1136_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1503	,8	,1	, &internal1_m1136_Vz0},	//(internal1_m1136_Vz0) Vz0 - предыдущая заданная скорость
	{ 1504	,3	,1	, &internal1_m1136_flRazg},	//(internal1_m1136_flRazg) признак разгона/торможения
	{ 1505	,8	,1	, &internal1_m1136_DelSp},	//(internal1_m1136_DelSp) DelSp - время переключения скоростей
	{ 1506	,8	,1	, &internal1_m1136_z0},	//(internal1_m1136_z0) z0 - точка прекращения движения
	{ 1507	,8	,1	, &internal1_m1136_txZS},	//(internal1_m1136_txZS) txZS
	{ 1508	,8	,1	, &internal1_m1136_tx},	//(internal1_m1136_tx) tx
	{ 1509	,8	,1	, &internal1_m1136_txd},	//(internal1_m1136_txd) txd
	{ 1510	,8	,1	, &internal1_m1136_txMBl},	//(internal1_m1136_txMBl) tx
	{ 1511	,8	,1	, &internal1_m1136_txBl},	//(internal1_m1136_txBl) tx
	{ 1512	,8	,1	, &internal1_m1136_Speed0},	//(internal1_m1136_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1513	,8	,1	, &internal1_m1136_xz0},	//(internal1_m1136_xz0) xz0 - новое задание мм
	{ 1514	,8	,1	, &internal1_m1136_tz0},	//(internal1_m1136_tz0) tz0 - время защиты от нового задания сек
	{ 1515	,1	,1	, &internal1_m1136_Shift0},	//(internal1_m1136_Shift0) Shift0 - признак самохода
	{ 1516	,1	,1	, &internal1_m1136_ShCntlSp0},	//(internal1_m1136_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1517	,1	,1	, &internal1_m1136_ShiftControl},	//(internal1_m1136_ShiftControl) ShiftControl - признак самохода
	{ 1518	,1	,1	, &internal1_m737_x0},	//(internal1_m737_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1519	,1	,1	, &internal1_m706_x0},	//(internal1_m706_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1520	,1	,1	, &internal1_m669_x0},	//(internal1_m669_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1521	,1	,1	, &internal1_m762_q0},	//(internal1_m762_q0) q0 - внутренний параметр
	{ 1522	,1	,1	, &internal1_m757_q0},	//(internal1_m757_q0) q0 - внутренний параметр
	{ 1523	,1	,1	, &internal1_m725_q0},	//(internal1_m725_q0) q0 - внутренний параметр
	{ 1524	,1	,1	, &internal1_m727_q0},	//(internal1_m727_q0) q0 - внутренний параметр
	{ 1525	,1	,1	, &internal1_m738_q0},	//(internal1_m738_q0) q0 - внутренний параметр
	{ 1526	,1	,1	, &internal1_m750_q0},	//(internal1_m750_q0) q0 - внутренний параметр
	{ 1527	,1	,1	, &internal1_m729_q0},	//(internal1_m729_q0) q0 - внутренний параметр
	{ 1528	,18	,1	, &internal1_m1174_DvUp0},	//(internal1_m1174_DvUp0) - есть команда на движение вперёд
	{ 1529	,18	,1	, &internal1_m1174_DvDw0},	//(internal1_m1174_DvDw0) - есть команда на движение назад
	{ 1530	,18	,1	, &internal1_m1174_FDvUp0},	//(internal1_m1174_FDvUp0) - есть команда на движение вперёд
	{ 1531	,18	,1	, &internal1_m1174_FDvDw0},	//(internal1_m1174_FDvDw0) - есть команда на движение назад
	{ 1532	,18	,1	, &internal1_m1174_BlDv0},	//(internal1_m1174_BlDv0) - была блокировка
	{ 1533	,18	,1	, &internal1_m1174_Pkv0},	//(internal1_m1174_Pkv0) Pkv - передний конечный выключатель
	{ 1534	,18	,1	, &internal1_m1174_Pkav0},	//(internal1_m1174_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1535	,18	,1	, &internal1_m1174_Zkv0},	//(internal1_m1174_Zkv0) Zkv - задний конечный выключатель
	{ 1536	,18	,1	, &internal1_m1174_Zkav0},	//(internal1_m1174_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1537	,8	,1	, &internal1_m1174_txNm},	//(internal1_m1174_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1538	,8	,1	, &internal1_m1174_txSm},	//(internal1_m1174_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1539	,8	,1	, &internal1_m1174_txHr},	//(internal1_m1174_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1540	,8	,1	, &internal1_m1174_txLd},	//(internal1_m1174_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1541	,18	,1	, &internal1_m1174_fef},	//(internal1_m1174_fef) fef
	{ 1542	,18	,1	, &internal1_m1163_DvUp0},	//(internal1_m1163_DvUp0) - есть команда на движение вперёд
	{ 1543	,18	,1	, &internal1_m1163_DvDw0},	//(internal1_m1163_DvDw0) - есть команда на движение назад
	{ 1544	,18	,1	, &internal1_m1163_FDvUp0},	//(internal1_m1163_FDvUp0) - есть команда на движение вперёд
	{ 1545	,18	,1	, &internal1_m1163_FDvDw0},	//(internal1_m1163_FDvDw0) - есть команда на движение назад
	{ 1546	,18	,1	, &internal1_m1163_BlDv0},	//(internal1_m1163_BlDv0) - была блокировка
	{ 1547	,18	,1	, &internal1_m1163_Pkv0},	//(internal1_m1163_Pkv0) Pkv - передний конечный выключатель
	{ 1548	,18	,1	, &internal1_m1163_Pkav0},	//(internal1_m1163_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1549	,18	,1	, &internal1_m1163_Zkv0},	//(internal1_m1163_Zkv0) Zkv - задний конечный выключатель
	{ 1550	,18	,1	, &internal1_m1163_Zkav0},	//(internal1_m1163_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1551	,8	,1	, &internal1_m1163_txNm},	//(internal1_m1163_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1552	,8	,1	, &internal1_m1163_txSm},	//(internal1_m1163_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1553	,8	,1	, &internal1_m1163_txHr},	//(internal1_m1163_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1554	,8	,1	, &internal1_m1163_txLd},	//(internal1_m1163_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1555	,18	,1	, &internal1_m1163_fef},	//(internal1_m1163_fef) fef
	{ 1556	,18	,1	, &internal1_m782_DvUp0},	//(internal1_m782_DvUp0) - есть команда на движение вперёд
	{ 1557	,18	,1	, &internal1_m782_DvDw0},	//(internal1_m782_DvDw0) - есть команда на движение назад
	{ 1558	,18	,1	, &internal1_m782_FDvUp0},	//(internal1_m782_FDvUp0) - есть команда на движение вперёд
	{ 1559	,18	,1	, &internal1_m782_FDvDw0},	//(internal1_m782_FDvDw0) - есть команда на движение назад
	{ 1560	,18	,1	, &internal1_m782_BlDv0},	//(internal1_m782_BlDv0) - была блокировка
	{ 1561	,18	,1	, &internal1_m782_Pkv0},	//(internal1_m782_Pkv0) Pkv - передний конечный выключатель
	{ 1562	,18	,1	, &internal1_m782_Pkav0},	//(internal1_m782_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1563	,18	,1	, &internal1_m782_Zkv0},	//(internal1_m782_Zkv0) Zkv - задний конечный выключатель
	{ 1564	,18	,1	, &internal1_m782_Zkav0},	//(internal1_m782_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1565	,8	,1	, &internal1_m782_txNm},	//(internal1_m782_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1566	,8	,1	, &internal1_m782_txSm},	//(internal1_m782_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1567	,8	,1	, &internal1_m782_txHr},	//(internal1_m782_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1568	,8	,1	, &internal1_m782_txLd},	//(internal1_m782_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1569	,18	,1	, &internal1_m782_fef},	//(internal1_m782_fef) fef
	{ 1570	,18	,1	, &internal1_m778_DvUp0},	//(internal1_m778_DvUp0) - есть команда на движение вперёд
	{ 1571	,18	,1	, &internal1_m778_DvDw0},	//(internal1_m778_DvDw0) - есть команда на движение назад
	{ 1572	,18	,1	, &internal1_m778_FDvUp0},	//(internal1_m778_FDvUp0) - есть команда на движение вперёд
	{ 1573	,18	,1	, &internal1_m778_FDvDw0},	//(internal1_m778_FDvDw0) - есть команда на движение назад
	{ 1574	,18	,1	, &internal1_m778_BlDv0},	//(internal1_m778_BlDv0) - была блокировка
	{ 1575	,18	,1	, &internal1_m778_Pkv0},	//(internal1_m778_Pkv0) Pkv - передний конечный выключатель
	{ 1576	,18	,1	, &internal1_m778_Pkav0},	//(internal1_m778_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1577	,18	,1	, &internal1_m778_Zkv0},	//(internal1_m778_Zkv0) Zkv - задний конечный выключатель
	{ 1578	,18	,1	, &internal1_m778_Zkav0},	//(internal1_m778_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1579	,8	,1	, &internal1_m778_txNm},	//(internal1_m778_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1580	,8	,1	, &internal1_m778_txSm},	//(internal1_m778_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1581	,8	,1	, &internal1_m778_txHr},	//(internal1_m778_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1582	,8	,1	, &internal1_m778_txLd},	//(internal1_m778_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1583	,18	,1	, &internal1_m778_fef},	//(internal1_m778_fef) fef
	{ 1584	,18	,1	, &internal1_m360_DvUp0},	//(internal1_m360_DvUp0) - есть команда на движение вперёд
	{ 1585	,18	,1	, &internal1_m360_DvDw0},	//(internal1_m360_DvDw0) - есть команда на движение назад
	{ 1586	,18	,1	, &internal1_m360_FDvUp0},	//(internal1_m360_FDvUp0) - есть команда на движение вперёд
	{ 1587	,18	,1	, &internal1_m360_FDvDw0},	//(internal1_m360_FDvDw0) - есть команда на движение назад
	{ 1588	,18	,1	, &internal1_m360_BlDv0},	//(internal1_m360_BlDv0) - была блокировка
	{ 1589	,18	,1	, &internal1_m360_Pkv0},	//(internal1_m360_Pkv0) Pkv - передний конечный выключатель
	{ 1590	,18	,1	, &internal1_m360_Pkav0},	//(internal1_m360_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1591	,18	,1	, &internal1_m360_Zkv0},	//(internal1_m360_Zkv0) Zkv - задний конечный выключатель
	{ 1592	,18	,1	, &internal1_m360_Zkav0},	//(internal1_m360_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1593	,8	,1	, &internal1_m360_txNm},	//(internal1_m360_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1594	,8	,1	, &internal1_m360_txSm},	//(internal1_m360_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1595	,8	,1	, &internal1_m360_txHr},	//(internal1_m360_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1596	,8	,1	, &internal1_m360_txLd},	//(internal1_m360_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1597	,18	,1	, &internal1_m360_fef},	//(internal1_m360_fef) fef
	{ 1598	,18	,1	, &internal1_m389_DvUp0},	//(internal1_m389_DvUp0) - есть команда на движение вперёд
	{ 1599	,18	,1	, &internal1_m389_DvDw0},	//(internal1_m389_DvDw0) - есть команда на движение назад
	{ 1600	,18	,1	, &internal1_m389_FDvUp0},	//(internal1_m389_FDvUp0) - есть команда на движение вперёд
	{ 1601	,18	,1	, &internal1_m389_FDvDw0},	//(internal1_m389_FDvDw0) - есть команда на движение назад
	{ 1602	,18	,1	, &internal1_m389_BlDv0},	//(internal1_m389_BlDv0) - была блокировка
	{ 1603	,18	,1	, &internal1_m389_Pkv0},	//(internal1_m389_Pkv0) Pkv - передний конечный выключатель
	{ 1604	,18	,1	, &internal1_m389_Pkav0},	//(internal1_m389_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1605	,18	,1	, &internal1_m389_Zkv0},	//(internal1_m389_Zkv0) Zkv - задний конечный выключатель
	{ 1606	,18	,1	, &internal1_m389_Zkav0},	//(internal1_m389_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1607	,8	,1	, &internal1_m389_txNm},	//(internal1_m389_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1608	,8	,1	, &internal1_m389_txSm},	//(internal1_m389_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1609	,8	,1	, &internal1_m389_txHr},	//(internal1_m389_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1610	,8	,1	, &internal1_m389_txLd},	//(internal1_m389_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1611	,18	,1	, &internal1_m389_fef},	//(internal1_m389_fef) fef
	{ 1612	,18	,1	, &internal1_m383_DvUp0},	//(internal1_m383_DvUp0) - есть команда на движение вперёд
	{ 1613	,18	,1	, &internal1_m383_DvDw0},	//(internal1_m383_DvDw0) - есть команда на движение назад
	{ 1614	,18	,1	, &internal1_m383_FDvUp0},	//(internal1_m383_FDvUp0) - есть команда на движение вперёд
	{ 1615	,18	,1	, &internal1_m383_FDvDw0},	//(internal1_m383_FDvDw0) - есть команда на движение назад
	{ 1616	,18	,1	, &internal1_m383_BlDv0},	//(internal1_m383_BlDv0) - была блокировка
	{ 1617	,18	,1	, &internal1_m383_Pkv0},	//(internal1_m383_Pkv0) Pkv - передний конечный выключатель
	{ 1618	,18	,1	, &internal1_m383_Pkav0},	//(internal1_m383_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1619	,18	,1	, &internal1_m383_Zkv0},	//(internal1_m383_Zkv0) Zkv - задний конечный выключатель
	{ 1620	,18	,1	, &internal1_m383_Zkav0},	//(internal1_m383_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1621	,8	,1	, &internal1_m383_txNm},	//(internal1_m383_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1622	,8	,1	, &internal1_m383_txSm},	//(internal1_m383_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1623	,8	,1	, &internal1_m383_txHr},	//(internal1_m383_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1624	,8	,1	, &internal1_m383_txLd},	//(internal1_m383_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1625	,18	,1	, &internal1_m383_fef},	//(internal1_m383_fef) fef
	{ 1626	,1	,1	, &internal1_m734_q0},	//(internal1_m734_q0) q0 - внутренний параметр
	{ 1627	,1	,1	, &internal1_m731_q0},	//(internal1_m731_q0) q0 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="du.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{730,"fEM_A1UC03RDU\0"}, 
{731,"dEM_A1UC05UDU\0"}, 
{732,"dEM_A1UC06UDU\0"}, 
{733,"dEM_A2UC06UDU\0"}, 
{734,"dEM_A2UC05UDU\0"}, 
{735,"fEM_A2UC03RDU\0"}, 
{736,"dEM_A3UC06UDU\0"}, 
{737,"dEM_A3UC05UDU\0"}, 
{738,"fEM_A3UC03RDU\0"}, 
{739,"dEM_A8UC06UDU\0"}, 
{740,"fEM_A8UC03RDU\0"}, 
{741,"dEM_A8UC05UDU\0"}, 
{742,"fEM_R0UV81RDU\0"}, 
{743,"fEM_R0UV82RDU\0"}, 
{744,"fEM_R0UV83RDU\0"}, 
{745,"fEM_R0UV84RDU\0"}, 
{746,"fEM_R0UV86RDU\0"}, 
{747,"fEM_R0UV85RDU\0"}, 
{748,"fEM_R0UV87RDU\0"}, 
{749,"fEM_A3UP03RDU\0"}, 
{750,"fEM_A3UP04RDU\0"}, 
{751,"fEM_A3UP43RDU\0"}, 
{752,"fEM_A3UP44RDU\0"}, 
{753,"fEM_A3UP53RDU\0"}, 
{754,"fEM_A3UP85RDU\0"}, 
{755,"fEM_A3UP88RDU\0"}, 
{756,"fEM_A3UP86RDU\0"}, 
{757,"fEM_B8UV01RDU\0"}, 
{758,"fEM_B8UV02RDU\0"}, 
{759,"fEM_B8UV03RDU\0"}, 
{760,"fEM_B8UL04RDU\0"}, 
{761,"iEM_A2UV03CDU\0"}, 
{762,"fEM_A2UV01RDU\0"}, 
{763,"fEM_A2UV02RDU\0"}, 
{764,"fEM_A1UV01RDU\0"}, 
{765,"fEM_A1UV02RDU\0"}, 
{766,"fEM_A1UC06RDU\0"}, 
{767,"fEM_A1UC05RDU\0"}, 
{768,"fEM_A1UL04RDU\0"}, 
{769,"fEM_A3UV01RDU\0"}, 
{770,"fEM_A3UV02RDU\0"}, 
{771,"fEM_A3UC06RDU\0"}, 
{772,"fEM_A3UC05RDU\0"}, 
{773,"fEM_A3UL04RDU\0"}, 
{774,"fEM_A3UP54RDU\0"}, 
{775,"fEM_A3UP87RDU\0"}, 
{776,"fEM_R0UL05RDU\0"}, 
{777,"fEM_R0UL20RDU\0"}, 
{778,"fEM_B8UV04RDU\0"}, 
{779,"fEM_B8UC06RDU\0"}, 
{780,"fEM_B8UC05RDU\0"}, 
{781,"fEM_A2UL05RDU\0"}, 
{782,"fEM_A2UL03RDU\0"}, 
{783,"fEM_A2UC06RDU\0"}, 
{784,"fEM_A2UC05RDU\0"}, 
{785,"fEM_A2UL04RDU\0"}, 
{786,"fEM_A1UL03RDU\0"}, 
{787,"fEM_A1UL05RDU\0"}, 
{788,"fEM_A3UL03RDU\0"}, 
{789,"fEM_A3UL05RDU\0"}, 
{790,"fEM_A1UC08RDU\0"}, 
{791,"fEM_A3UC08RDU\0"}, 
{792,"fEM_A1UC07RDU\0"}, 
{793,"fEM_A1UL01RDU\0"}, 
{794,"fEM_A3UC07RDU\0"}, 
{795,"fEM_A3UL01RDU\0"}, 
{796,"fEM_A2UC08RDU\0"}, 
{797,"fEM_A2UC07RDU\0"}, 
{798,"fEM_A2UL01RDU\0"}, 
{799,"fEM_B8UC01RDU\0"}, 
{800,"fEM_B8UL07RDU\0"}, 
{801,"fEM_B8UC02RDU\0"}, 
{802,"fEM_B8UL01RDU\0"}, 
{803,"fEM_B8UL05RDU\0"}, 
{804,"fEM_B8UL03RDU\0"}, 
{805,"fEM_B8UL06RDU\0"}, 
{806,"fEM_A9UZ03RDU\0"}, 
{807,"fEM_A9UZ04RDU\0"}, 
{808,"fEM_A9UZ05RDU\0"}, 
{809,"fEM_R4UZ04RDU\0"}, 
{810,"fEM_R4UZ03RDU\0"}, 
{811,"fEM_R4UZ05RDU\0"}, 
{812,"fEM_A5UZ03RDU\0"}, 
{813,"fEM_A5UZ04RDU\0"}, 
{814,"fEM_A5UZ05RDU\0"}, 
{815,"fEM_A4UZ03RDU\0"}, 
{816,"fEM_A4UZ04RDU\0"}, 
{817,"fEM_A4UZ05RDU\0"}, 
{818,"fEM_A6UZ03RDU\0"}, 
{819,"fEM_A6UZ04RDU\0"}, 
{820,"fEM_A6UZ05RDU\0"}, 
{821,"fEM_R1UZ03RDU\0"}, 
{822,"fEM_R1UZ04RDU\0"}, 
{823,"fEM_R1UZ05RDU\0"}, 
{824,"fEM_R0UL04RDU\0"}, 
{825,"fEM_R0UL06RDU\0"}, 
{826,"fEM_R0UL03RDU\0"}, 
{827,"fEM_R0UL17RDU\0"}, 
{828,"fEM_R0UL19RDU\0"}, 
{829,"fEM_R0UL07RDU\0"}, 
{830,"fEM_R0UL18RDU\0"}, 
{831,"fEM_R0UL16RDU\0"}, 
{832,"fEM_R0UL02RDU\0"}, 
{833,"fEM_R0UN08RDU\0"}, 
{834,"fEM_R0UN07RDU\0"}, 
{835,"fEM_R0UN06RDU\0"}, 
{836,"fEM_R0UN05RDU\0"}, 
{837,"fEM_R0UN04RDU\0"}, 
{838,"fEM_R0UN03RDU\0"}, 
{839,"fEM_R0UN02RDU\0"}, 
{840,"fEM_R0UN01RDU\0"}, 
{841,"fEM_A2UC82RDU\0"}, 
{842,"fEM_A2UC83RDU\0"}, 
{843,"fEM_A1UC83RDU\0"}, 
{844,"fEM_A2UC81RDU\0"}, 
{845,"fEM_A1UC81RDU\0"}, 
{846,"fEM_A1UC82RDU\0"}, 
{847,"fEM_A2UL83RDU\0"}, 
{848,"fEM_A3UC81RDU\0"}, 
{849,"fEM_A3UC82RDU\0"}, 
{850,"fEM_R0UN80RDU\0"}, 
{851,"iEM_A2UV01IDU\0"}, 
{852,"iEM_A2UV02IDU\0"}, 
{853,"iEM_A1UV01IDU\0"}, 
{854,"iEM_A1UV02IDU\0"}, 
{855,"iEM_A1UV03IDU\0"}, 
{856,"iEM_A3UV01IDU\0"}, 
{857,"iEM_A3UV02IDU\0"}, 
{858,"lEM_R0MD01LC1\0"}, 
{859,"fEM_A3UC09RDU\0"}, 
{860,"fEM_A2UC02RDU\0"}, 
{861,"fEM_A1UC02RDU\0"}, 
{862,"fEM_A3UC02RDU\0"}, 
{863,"fEM_R0UL21RDU\0"}, 
{864,"fEM_R0UN09RDU\0"}, 
{865,"fEM_R0UN11RDU\0"}, 
{866,"fEM_R0UN12RDU\0"}, 
{867,"fEM_R0UN13RDU\0"}, 
{868,"fEM_R0UN14RDU\0"}, 
{869,"fEM_R0UN16RDU\0"}, 
{870,"fEM_R0UN17RDU\0"}, 
{871,"fEM_R0UN18RDU\0"}, 
{872,"fEM_R0UN19RDU\0"}, 
{873,"fEM_R0UN70LDU\0"}, 
{874,"fEM_R0UN71LDU\0"}, 
{875,"fEM_R0UN72LDU\0"}, 
{876,"fEM_R0UN73LDU\0"}, 
{877,"fEM_R0UN74LDU\0"}, 
{878,"fEM_R0UN75LDU\0"}, 
{879,"fEM_R0UN80LDU\0"}, 
{880,"fEM_R0UN81LDU\0"}, 
{881,"fEM_R0UN82LDU\0"}, 
{882,"fEM_R0UN83LDU\0"}, 
{883,"fEM_R0UN84LDU\0"}, 
{884,"fEM_R0UN85LDU\0"}, 
{885,"fEM_R0UT20RDU\0"}, 
{886,"fEM_R0UN25RDU\0"}, 
{887,"fEM_R0UN15RDU\0"}, 
{888,"fEM_R0UN26RDU\0"}, 
{889,"fEM_R0UN27RDU\0"}, 
{890,"fEM_R0UN24RDU\0"}, 
{891,"fEM_R0UL25RDU\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_DU[]={  // 
	{&B1MD11LP1,1,0},	//( - , DU) Кнопка ПУСК ББ2
	{&R0MW17LP1,1,1},	//( - , DU) Переключатель АВТ/Р
	{&A1MD11LP1,1,2},	//( - , DU) Кнопка ПУСК ББ1
	{&A1MD12LP1,1,3},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
	{&R0MD33LP1,1,4},	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
	{&A3MD11LP1,1,5},	//( - , DU) Кнопка ПУСК ИС1
	{&A3MD12LP1,1,6},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
	{&A3VZ15LZ2,1,7},	//( - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{&A3VZ13LZ2,1,8},	//( - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{&R0AD14LZ2,1,9},	//( - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
	{&A1VN71LZ2,1,10},	//( - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{&B3MD11LP1,1,11},	//( - , DU) Кнопка ПУСК ИС2
	{&B3MD12LP1,1,12},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
	{&R0MD34LP1,1,13},	//( - , DU) Кнопка КВИТИРОВАТЬ
	{&R0IS02LDU,1,14},	//( - K30VDSR, DU) Разрешение ввода от имитатора
	{&A2MD12LP1,1,15},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
	{&A2MD11LP1,1,16},	//( - , DU) Кнопка ПУСК РБ1
	{&B2MD12LP1,1,17},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
	{&B2MD11LP1,1,18},	//( - , DU) Кнопка ПУСК РБ2
	{&B1MD12LP1,1,19},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
	{&R0MD11LP2,1,20},	//( - , DU) Кнопка Пуск проверки схем сброса
	{&C1MD31LP2,1,21},	//( - , DU) Кнопка СБРОС ББ
	{&C1MD31LP1,1,22},	//( - , DU) Кнопка СБРОС ББ
	{&A1MC01LC2,1,23},	//( - , DU) Настроить энкодер ББ1
	{&A1MC01LC1,1,24},	//( - , DU) Настроить энкодер ББ1
	{&B1MC01LC2,1,25},	//( - , DU) Настроить энкодер ББ2
	{&B1MC01LC1,1,26},	//( - , DU) Настроить энкодер ББ2
	{&B1VP41LZ2,1,27},	//( - , DU) Давление СБРОС ББ2 ниже АС
	{&B1VP41LZ1,1,28},	//( - , DU) Давление СБРОС ББ2 ниже АС
	{&A1VP41LZ2,1,29},	//( - , DU) Давление СБРОС ББ1 ниже АС
	{&A1VP41LZ1,1,30},	//( - , DU) Давление СБРОС ББ1 ниже АС
	{&B2MC01LC1,1,31},	//( - , DU) Настроить энкодер РБ2
	{&B2MC01LC2,1,32},	//( - , DU) Настроить энкодер РБ2
	{&A2MC01LC1,1,33},	//( - , DU) Настроить энкодер РБ1
	{&A2MC01LC2,1,34},	//( - , DU) Настроить энкодер РБ1
	{&B3MC01LC1,1,35},	//( - , DU) Настроить энкодер ИС2
	{&B3MC01LC2,1,36},	//( - , DU) Настроить энкодер ИС2
	{&A3MC01LC1,1,37},	//( - , DU) Настроить энкодер ИС1
	{&A3MC01LC2,1,38},	//( - , DU) Настроить энкодер ИС1
	{&B8MC01LC1,1,39},	//( - , DU) Настроить энкодер АЗ2
	{&B8MC01LC2,1,40},	//( - , DU) Настроить энкодер АЗ2
	{&A8MC01LC1,1,41},	//( - , DU) Настроить энкодер ДС2
	{&A8MC01LC2,1,42},	//( - , DU) Настроить энкодер ДС2
	{&C2MD31LP1,1,43},	//( - , DU) Кнопка СБРОС РБ
	{&R0MD11LP1,1,44},	//( - , DU) Кнопка ПУСК
	{&R4MD21LP2,1,45},	//( - , DU) Кнопка НАЗАД  (тележки)
	{&R4MD31LP2,1,46},	//( - , DU) Кнопка СТОП  (тележки)
	{&R4MD11LP2,1,47},	//( - , DU) Кнопка ВПЕРЁД  (тележки)
	{&R0MD31LP1,1,48},	//( - , DU) Кнопка СТОП
	{&R0MD32LP1,1,49},	//( - , DU) Кнопка СПУСК
	{&R0MW13LP2,1,50},	//( - , DU) Переключатель СЕТЬ
	{&R0NE01LDU,1,51},	//( - , DU) Потеря связи с БАЗ1
	{&R0NE02LDU,1,52},	//( - , DU) Потеря связи с БАЗ2
	{&R0NE08LDU,1,53},	//( - , DU) Потеря связи с ОПУ
	{&lEM_R0MD01LC1,1,54},	//( - , DU) Ручное управление ОРР
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DU[]={  // 
	{&R0VS18LDU,1,0},	//( - , DU) Индикация  Проверка схем сброса
	{&B3VX01LDU,1,1},	//( - , DU) Индикация Выстрел ИС2
	{&A3IS11LDU,1,2},	//( - K01VDSR, DU) Приход на ВУ ИС1
	{&A3VX01LDU,1,3},	//( - , DU) Индикация Выстрел ИС1
	{&B2VS32LDU,1,4},	//( - , DU) Индикация  СБРОС РБ2
	{&A2VS32LDU,1,5},	//( - , DU) Индикация  СБРОС РБ1
	{&R0VS17LDU,1,6},	//( - , DU) Индикация выбора АВТОМАТ
	{&R0VX09LDU,1,7},	//( - , DU) Индикация регулятор мощности включен/отключен
	{&R0VW23LDU,1,8},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,1,9},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
	{&B2IS11LDU,1,10},	//( - K11VDSR, DU) Приход на ВУ РБ2-СТР
	{&A2IS11LDU,1,11},	//( - K11VDSR, DU) Приход на ВУ РБ1-СТР
	{&B3IS22LDU,1,12},	//( - K04VDSR, DU) Приход на НУП ИС2
	{&A3IS22LDU,1,13},	//( - K02VDSR, DU) Приход на НУП ИС1
	{&R0AB01LDU,1,14},	//( - , DU) Режим проверки разрешён
	{&B9AB02LDU,1,15},	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
	{&B9AB01LDU,1,16},	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
	{&B9AZ03LDU,1,17},	//( - , DU) Несанкционированное перемещение НИ ДС2
	{&A9AB02LDU,1,18},	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
	{&A9AB01LDU,1,19},	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
	{&A9AZ03LDU,1,20},	//( - , DU) Несанкционированное перемещение НИ ДС1
	{&B9IS11LDU,1,21},	//( - K25VDSR, DU) Приход на ВУ НИ ДС2
	{&B3IS31LDU,1,22},	//( - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
	{&B2IS33LDU,1,23},	//( - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
	{&A1AB19LDU,1,24},	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
	{&A4IS10LDU,1,25},	//( - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
	{&A3IS35LDU,1,26},	//( - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
	{&A3IS33LDU,1,27},	//( - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
	{&A3IS31LDU,1,28},	//( - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
	{&A2IS33LDU,1,29},	//( - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
	{&R0VZ71LDU,1,30},	//( - , DU) Обобщенный сигнал АЗ
	{&B7AZ03LDU,1,31},	//( - , DU) Несанкционированное включение обдува АЗ2
	{&A7AZ03LDU,1,32},	//( - , DU) Несанкционированное включение обдува АЗ1
	{&B7AS31LDU,1,33},	//( - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
	{&A7AS31LDU,1,34},	//( - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
	{&B2VS21LDU,1,35},	//( - , DU) Движение РБ2 в сторону НУ
	{&B2VS11LDU,1,36},	//( - , DU) Движение РБ2 в сторону ВУ
	{&R0VP73LDU,1,37},	//( - , DU) ПС давления для РУ
	{&R0IS01LDU,1,38},	//( - K29VDSR, DU) Признак работы с имитатором
	{&R0VX01LDU,1,39},	//( - , DU) ДО ИМПУЛЬСА
	{&B1AD31LDU,1,40},	//( - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
	{&A1AD31LDU,1,41},	//( - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
	{&B2AD31LDU,1,42},	//( - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
	{&A2AD31LDU,1,43},	//( - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
	{&B3AB20LDU,1,44},	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
	{&B3AB18LDU,1,45},	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
	{&B3AB17LDU,1,46},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
	{&B3AB16LDU,1,47},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
	{&B3AB14LDU,1,48},	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
	{&B3AB12LDU,1,49},	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{&B3AB11LDU,1,50},	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
	{&B3AB10LDU,1,51},	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
	{&B3AB09LDU,1,52},	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
	{&B3AB06LDU,1,53},	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
	{&B3AB05LDU,1,54},	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
	{&B3AB08LDU,1,55},	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
	{&B3AB07LDU,1,56},	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
	{&B3AZ03LDU,1,57},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
	{&B3VS22LDU,1,58},	//( - , DU) Движение ИС2 в сторону НУ
	{&B3AB01LDU,1,59},	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
	{&B3AB02LDU,1,60},	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
	{&B3AB04LDU,1,61},	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
	{&B3VS12LDU,1,62},	//( - , DU) Движение ИС2 в сторону ВУ
	{&A3AB20LDU,1,63},	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
	{&A3AB18LDU,1,64},	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
	{&A3AB17LDU,1,65},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
	{&A9IS11LDU,1,66},	//( - K23VDSR, DU) Приход на ВУ НИ ДС1
	{&B4VS22LDU,1,67},	//( - , DU) Движение НИ2 в сторону НУ
	{&B4VS12LDU,1,68},	//( - , DU) Движение НИ2 в сторону ВУ
	{&A4VS22LDU,1,69},	//( - , DU) Движение НИ1 в сторону НУ
	{&A4VS12LDU,1,70},	//( - , DU) Движение НИ1 в сторону ВУ
	{&B3IS11LDU,1,71},	//( - K03VDSR, DU) Приход на ВУ ИС2
	{&R0AD14LDU,1,72},	//( - , DU) Имитация срабатывания верхней АС II УР
	{&R0AB04LDU,1,73},	//( - , DU) Нарушение времени срабатывания верхней АС II УР
	{&R0AB06LDU,1,74},	//( - , DU) Нарушение времени задержки от ВУ РБ
	{&R0AB02LDU,1,75},	//( - , DU) Нарушение времени задержки ИНИ
	{&R0VX03LDU,1,76},	//( - , DU) Готовность 2 мин
	{&A1IS11LDU,1,77},	//( - K08VDSR, DU) Приход на ВУ ББ1
	{&B1IS11LDU,1,78},	//( - K08VDSR, DU) Приход на ВУ ББ2
	{&TestDiagnDU,1,79},	//( - , DU) Неисправность от
	{&B3AB13LDU,1,80},	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
	{&A3AB13LDU,1,81},	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
	{&R3VS12LDU,1,82},	//( - , DU) Движение гомогенных дверей к открыты
	{&R3VS22LDU,1,83},	//( - , DU) Движение гомогенных дверей к закрыты
	{&R5VS12LDU,1,84},	//( - , DU) Движение ворот отстойной зоны к открыты
	{&R5VS22LDU,1,85},	//( - , DU) Движение ворот отстойной зоны к закрыты
	{&R5IS21LDU,1,86},	//( - K26VDSR, DU) Приход на НУ ворот отстойной зоны
	{&B3AB15LDU,1,87},	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
	{&B3EE03LDU,1,88},	//( - , DU) ВПИС ИС2
	{&A3EE03LDU,1,89},	//( - , DU) ВПИС ИС1
	{&B3AB19LDU,1,90},	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
	{&A3AB19LDU,1,91},	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
	{&R0VL23LDU,1,92},	//( - , DU) Конец программы 20мин
	{&R0VL22LDU,1,93},	//( - , DU) Конец программы 200сек
	{&R0EE02LDU,1,94},	//( - , DU) Питание  АКНП  отключить
	{&B0VS11LDU,1,95},	//( - , DU) АЗ2 готова к работе
	{&A0VS11LDU,1,96},	//( - , DU) АЗ1 готова к работе
	{&B0VN01LDU,1,97},	//( - , DU) Каналы АЗ2 проверены
	{&A0VN01LDU,1,98},	//( - , DU) Каналы АЗ1 проверены
	{&B0VP01LDU,1,99},	//( - , DU) Давление в системы АЗ2 подано
	{&A0VP01LDU,1,100},	//( - , DU) Давление в системы АЗ1 подано
	{&B0VE01LDU,1,101},	//( - , DU) Напряжение в системы АЗ2 подано
	{&A0VE01LDU,1,102},	//( - , DU) Напряжение в системы АЗ1 подано
	{&A3VP82LDU,1,103},	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
	{&B3VP82LDU,1,104},	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
	{&B3VP52LDU,1,105},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
	{&A3VP42LDU,1,106},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
	{&A3VP52LDU,1,107},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
	{&B3VP42LDU,1,108},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
	{&R2ZAV,1,109},	//( - , DU) 
	{&A6ZAV,1,110},	//( - , DU) 
	{&A4ZAV,1,111},	//( - , DU) 
	{&R0AB13LDU,1,112},	//( - , DU) Ошибка в заданной координате  АЗ2
	{&R0AB12LDU,1,113},	//( - , DU) Ошибка в заданной координате  ИС2
	{&R0AB11LDU,1,114},	//( - , DU) Ошибка в заданной координате  ИС1
	{&R0AB10LDU,1,115},	//( - , DU) Ошибка в заданной координате ББ2
	{&R0AB09LDU,1,116},	//( - , DU) Ошибка в заданной координате ББ1
	{&R0AB08LDU,1,117},	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
	{&B6AB05LDU,1,118},	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
	{&R0VS11LDU,1,119},	//( - , DU) РУ не готова к работе
	{&R0AB07LDU,1,120},	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
	{&R0EE03LDU,1,121},	//( - , DU) ВПИС ИС
	{&R0VX02LDU,1,122},	//( - , DU) Импульс разрешен
	{&B2AB15LDU,1,123},	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{&A2AB15LDU,1,124},	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{&R0AB05LDU,1,125},	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
	{&R0AB03LDU,1,126},	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
	{&R3IS21LDU,1,127},	//( - K18VDSR, DU) Приход на НУ гомогенных дверей
	{&R3IS11LDU,1,128},	//( - K17VDSR, DU) Приход на ВУ гомогенных дверей
	{&B4IS10LDU,1,129},	//( - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
	{&B3IS35LDU,1,130},	//( - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
	{&B3IS33LDU,1,131},	//( - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
	{&B8IS21LDU,1,132},	//( - K20VDSR, DU) Приход на НУ1 АЗ2
	{&B8IS12LDU,1,133},	//( - K21VDSR, DU) Приход на ВУ2 АЗ2
	{&R0AB19LDU,1,134},	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
	{&R0AB20LDU,1,135},	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
	{&A3AB15LDU,1,136},	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
	{&R0AB18LDU,1,137},	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
	{&A5ZAV,1,138},	//( - , DU) 
	{&B8ZAV,1,139},	//( - , DU) 
	{&A2ZAV,1,140},	//( - , DU) Завершение РБ1,2
	{&A8ZAV,1,141},	//( - , DU) 
	{&A9ZAV,1,142},	//( - , DU) Завершение НИ ДС1(2)
	{&R4ABL,1,143},	//( - , DU) Блокировка тележки -
	{&A4UP,1,144},	//( - , DU) 
	{&A4DW,1,145},	//( - , DU) 
	{&R0AB14LDU,1,146},	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
	{&R0AB15LDU,1,147},	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
	{&A3IS12LDU,1,148},	//( - , DU) Приход на ВУ штока ИС1
	{&B3IS12LDU,1,149},	//( - , DU) Приход на ВУ штока ИС2
	{&A1ZAV,1,150},	//( - , DU) 
	{&A3ZAV,1,151},	//( - , DU) 
	{&B1AB19LDU,1,152},	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
	{&R0AB16LDU,1,153},	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
	{&R0AB17LDU,1,154},	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
	{&B1IS12LDU,1,155},	//( - K07VDSR, DU) Магнит ББ2 зацеплен
	{&A2IS12LDU,1,156},	//( - K10VDSR, DU) Магнит РБ1 зацеплен
	{&A1IS12LDU,1,157},	//( - K07VDSR, DU) Магнит ББ1 зацеплен
	{&B5AB04LDU,1,158},	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
	{&A5AB04LDU,1,159},	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
	{&B4AB02LDU,1,160},	//( - , DU) Блокировка движения НИ2 - Нет перемещения
	{&B4AB01LDU,1,161},	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
	{&B4AZ03LDU,1,162},	//( - , DU) Несанкционированное перемещение НИ2
	{&A4AB02LDU,1,163},	//( - , DU) Блокировка движения НИ1 - Нет перемещения
	{&A4AB01LDU,1,164},	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
	{&A4AZ03LDU,1,165},	//( - , DU) Несанкционированное перемещение НИ1
	{&B4IS21LDU,1,166},	//( - K32VDSR, DU) Приход на НУ НИ2
	{&A4IS21LDU,1,167},	//( - K15VDSR, DU) Приход на НУ НИ1
	{&B5AB02LDU,1,168},	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
	{&B5AB01LDU,1,169},	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
	{&B5AZ03LDU,1,170},	//( - , DU) Несанкционированное перемещение НЛ2
	{&A5AB02LDU,1,171},	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
	{&A5AB01LDU,1,172},	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
	{&A5AZ03LDU,1,173},	//( - , DU) Несанкционированное перемещение НЛ1
	{&B5IS21LDU,1,174},	//( - K16VDSR, DU) Приход на НУ НЛ2
	{&B5IS11LDU,1,175},	//( - K15VDSR, DU) Приход на ВУ НЛ2
	{&A5IS21LDU,1,176},	//( - K12VDSR, DU) Приход на НУ НЛ1
	{&A5IS11LDU,1,177},	//( - K11VDSR, DU) Приход на ВУ НЛ1
	{&B5VS12LDU,1,178},	//( - K14VDSR, DU) Движение НЛ2 в сторону ВУ
	{&B5VS22LDU,1,179},	//( - K15VDSR, DU) Движение НЛ2 в сторону НУ
	{&A5VS12LDU,1,180},	//( - K11VDSR, DU) Движение НЛ1 в сторону ВУ
	{&A5VS22LDU,1,181},	//( - K12VDSR, DU) Движение НЛ1 в сторону НУ
	{&R4AD20LDU,1,182},	//( - K14FDSR, DU) Перемещение тележки назад
	{&R4AB18LDU,1,183},	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
	{&R4AB17LDU,1,184},	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
	{&R4AB16LDU,1,185},	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
	{&R5IS11LDU,1,186},	//( - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
	{&A8VS12LDU,1,187},	//( - , DU) Движение ДС2 в сторону ВУ
	{&B8AB02LDU,1,188},	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
	{&B8AB14LDU,1,189},	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
	{&B8AB13LDU,1,190},	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
	{&B8AB12LDU,1,191},	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
	{&B8AB11LDU,1,192},	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
	{&B8AB10LDU,1,193},	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
	{&B8AB09LDU,1,194},	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
	{&B8AB08LDU,1,195},	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
	{&B8AB04LDU,1,196},	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
	{&B8AB01LDU,1,197},	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
	{&B8IS11LDU,1,198},	//( - K19VDSR, DU) Приход на ВУ1 АЗ2
	{&B8AZ03LDU,1,199},	//( - , DU) Несанкционированное перемещение АЗ2
	{&B8VS22LDU,1,200},	//( - , DU) Движение АЗ2 в сторону НУ
	{&B8AB05LDU,1,201},	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
	{&B8AB07LDU,1,202},	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
	{&B8AB06LDU,1,203},	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
	{&B8VS12LDU,1,204},	//( - , DU) Движение АЗ2 в сторону ВУ
	{&A6AB05LDU,1,205},	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
	{&B6AB09LDU,1,206},	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
	{&B6AB08LDU,1,207},	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
	{&B6AB07LDU,1,208},	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
	{&B6AB06LDU,1,209},	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
	{&A6AB09LDU,1,210},	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
	{&A6AB08LDU,1,211},	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
	{&A6AB07LDU,1,212},	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
	{&A6AB06LDU,1,213},	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
	{&R4IS11LDU,1,214},	//( - K05VDSR, DU) Приход на ВУ1 тележки
	{&B2IS12LDU,1,215},	//( - K10VDSR, DU) Магнит РБ2 зацеплен
	{&B6AZ03LDU,1,216},	//( - , DU) Несанкционированное перемещение БЗ2
	{&A6AB02LDU,1,217},	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
	{&A6AB01LDU,1,218},	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
	{&A6AZ03LDU,1,219},	//( - , DU) Несанкционированное перемещение БЗ1
	{&B6VS12LDU,1,220},	//( - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
	{&B6VS22LDU,1,221},	//( - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
	{&A6VS12LDU,1,222},	//( - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
	{&A6VS22LDU,1,223},	//( - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
	{&B6IS21LDU,1,224},	//( - K14VDSR, DU) Приход на НУ БЗ2
	{&B6IS11LDU,1,225},	//( - K13VDSR, DU) Приход на ВУ БЗ2
	{&A6IS21LDU,1,226},	//( - K10VDSR, DU) Приход на НУ БЗ1
	{&A6IS11LDU,1,227},	//( - K09VDSR, DU) Приход на ВУ БЗ1
	{&R0ES01LDU,1,228},	//( - , DU) ОРР не в исходном состоянии
	{&B3IS21LDU,1,229},	//( - K13VDSR, DU) Приход на НУ ИС2
	{&B2IS21LDU,1,230},	//( - K12VDSR, DU) Приход на НУ РБ2-СС
	{&B1IS21LDU,1,231},	//( - K09VDSR, DU) Приход на НУ ББ2
	{&A3IS21LDU,1,232},	//( - K13VDSR, DU) Приход на НУ ИС1
	{&A2IS21LDU,1,233},	//( - K12VDSR, DU) Приход на НУ РБ1-СС
	{&A1IS21LDU,1,234},	//( - K09VDSR, DU) Приход на НУ ББ1
	{&R4AB15LDU,1,235},	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
	{&R4AB14LDU,1,236},	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
	{&R4AB13LDU,1,237},	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
	{&B4IS11LDU,1,238},	//( - K31VDSR, DU) Приход на ВУ НИ2
	{&A4IS11LDU,1,239},	//( - K14VDSR, DU) Приход на ВУ НИ1
	{&R4AB12LDU,1,240},	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
	{&R4AB11LDU,1,241},	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
	{&R4AB10LDU,1,242},	//( - , DU) Блокировка тележки - не открыта биологическая защита
	{&R4AB09LDU,1,243},	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
	{&R4AB08LDU,1,244},	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
	{&R4AB07LDU,1,245},	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
	{&R4AB06LDU,1,246},	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
	{&R4AB05LDU,1,247},	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
	{&R4AB04LDU,1,248},	//( - , DU) Блокировка движения тележки - Превышение времени движения
	{&R2IS21LDU,1,249},	//( - K30VDSR, DU) Приход на НУ МДЗ2
	{&R1IS21LDU,1,250},	//( - K28VDSR, DU) Приход на НУ МДЗ1
	{&B6AB01LDU,1,251},	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
	{&B6AB02LDU,1,252},	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
	{&A6AB04LDU,1,253},	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
	{&B6AB04LDU,1,254},	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
	{&R4AB01LDU,1,255},	//( - , DU) Блокировка движения тележки - АНИ не установлен
	{&R8IS11LDU,1,256},	//( - K14VDSR, DU) Аварийный НИ установлен
	{&R4AB02LDU,1,257},	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
	{&R4IS21LDU,1,258},	//( - K07VDSR, DU) Приход на НУ1 тележки
	{&R4IS22LDU,1,259},	//( - K08VDSR, DU) Приход на НУ2 тележки
	{&R4IS12LDU,1,260},	//( - K06VDSR, DU) Приход на ВУ2 тележки
	{&R4VS22LDU,1,261},	//( - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
	{&R4VS12LDU,1,262},	//( - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
	{&R4AZ03LDU,1,263},	//( - , DU) Несанкционированное перемещение тележки
	{&R4AB03LDU,1,264},	//( - , DU) Блокировка движения тележки - Самоход любого механизма
	{&B1VS22LDU,1,265},	//( - , DU) Движение ББ2 в сторону НУ
	{&B1AB01LDU,1,266},	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
	{&B1AB02LDU,1,267},	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
	{&B1AB04LDU,1,268},	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
	{&B1VS12LDU,1,269},	//( - , DU) Движение ББ2 в сторону ВУ
	{&A1AB18LDU,1,270},	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
	{&A1AB17LDU,1,271},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
	{&A1AB16LDU,1,272},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
	{&A1AB14LDU,1,273},	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
	{&A1AB13LDU,1,274},	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
	{&A1AB12LDU,1,275},	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&A1AB11LDU,1,276},	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
	{&A1AB10LDU,1,277},	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
	{&A1AB09LDU,1,278},	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
	{&A1AB06LDU,1,279},	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
	{&A1AB05LDU,1,280},	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
	{&A1AB08LDU,1,281},	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
	{&A1AB07LDU,1,282},	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
	{&A1AZ03LDU,1,283},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
	{&A1VS22LDU,1,284},	//( - , DU) Движение ББ1 в сторону НУ
	{&A1AB01LDU,1,285},	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
	{&A1AB02LDU,1,286},	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
	{&A1AB04LDU,1,287},	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
	{&A1VS12LDU,1,288},	//( - , DU) Движение ББ1 в сторону ВУ
	{&R2IS11LDU,1,289},	//( - K29VDSR, DU) Приход на ВУ МДЗ2
	{&R1VS12LDU,1,290},	//( - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
	{&R2VS12LDU,1,291},	//( - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
	{&R2VS22LDU,1,292},	//( - K09VDSR, DU) Движение МДЗ2 в сторону НУ
	{&R1VS22LDU,1,293},	//( - K06VDSR, DU) Движение МДЗ1 в сторону НУ
	{&A3AB16LDU,1,294},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
	{&A3AB14LDU,1,295},	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
	{&A3AB12LDU,1,296},	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&A3AB11LDU,1,297},	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
	{&A3AB10LDU,1,298},	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
	{&A3AB09LDU,1,299},	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
	{&A3AB06LDU,1,300},	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
	{&A3AB05LDU,1,301},	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
	{&A3AB08LDU,1,302},	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
	{&A3AB07LDU,1,303},	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
	{&A3AZ03LDU,1,304},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
	{&A3VS22LDU,1,305},	//( - , DU) Движение ИС1 в сторону НУ
	{&A3AB01LDU,1,306},	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
	{&A3AB02LDU,1,307},	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
	{&A3AB04LDU,1,308},	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
	{&B1AZ03LDU,1,309},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
	{&B1AB07LDU,1,310},	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
	{&B1AB08LDU,1,311},	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
	{&B1AB05LDU,1,312},	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
	{&B1AB06LDU,1,313},	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
	{&B1AB09LDU,1,314},	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
	{&B1AB10LDU,1,315},	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
	{&B1AB11LDU,1,316},	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
	{&B1AB12LDU,1,317},	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&B1AB13LDU,1,318},	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
	{&B1AB14LDU,1,319},	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
	{&B1AB16LDU,1,320},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
	{&B1AB17LDU,1,321},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
	{&B1AB18LDU,1,322},	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
	{&A3VS12LDU,1,323},	//( - , DU) Движение ИС1 в сторону ВУ
	{&A2AB11LDU,1,324},	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
	{&A2AB10LDU,1,325},	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
	{&A2AB09LDU,1,326},	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
	{&A2AB06LDU,1,327},	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
	{&A2AB05LDU,1,328},	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
	{&A2AB08LDU,1,329},	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
	{&A2AB07LDU,1,330},	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
	{&A2AZ03LDU,1,331},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
	{&A2VS21LDU,1,332},	//( - , DU) Движение РБ1 в сторону НУ
	{&A2AB01LDU,1,333},	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
	{&A2AB02LDU,1,334},	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
	{&A2AB04LDU,1,335},	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
	{&A2VS11LDU,1,336},	//( - , DU) Движение РБ1 в сторону ВУ
	{&A8AB01LDU,1,337},	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
	{&A8AB02LDU,1,338},	//( - , DU) Блокировка движения ДС2- АНИ не установлен
	{&A8AB14LDU,1,339},	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
	{&A8AB13LDU,1,340},	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
	{&A8AB12LDU,1,341},	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
	{&A8AB11LDU,1,342},	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
	{&A8AB10LDU,1,343},	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
	{&A8AB09LDU,1,344},	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
	{&A8AB08LDU,1,345},	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
	{&A8IS22LDU,1,346},	//( - K31VDSR, DU) Приход на механический НУ ДС2
	{&A8AB04LDU,1,347},	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
	{&A8IS12LDU,1,348},	//( - K30VDSR, DU) Приход на механический ВУ ДС2
	{&B8IS22LDU,1,349},	//( - K22VDSR, DU) Приход на НУ2 АЗ2
	{&A8AZ03LDU,1,350},	//( - , DU) Несанкционированное перемещение ДС2
	{&A8VS22LDU,1,351},	//( - , DU) Движение ДС2 в сторону НУ
	{&A8AB05LDU,1,352},	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
	{&A8AB07LDU,1,353},	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
	{&A8AB06LDU,1,354},	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
	{&R1IS11LDU,1,355},	//( - K27VDSR, DU) Приход на ВУ МДЗ1
	{&R2AB04LDU,1,356},	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
	{&R1AB04LDU,1,357},	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
	{&R2AB02LDU,1,358},	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
	{&R2AB01LDU,1,359},	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
	{&R2AZ03LDU,1,360},	//( - , DU) Несанкционированное перемещение МДЗ2
	{&R1AB02LDU,1,361},	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
	{&R1AB01LDU,1,362},	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
	{&R1AZ03LDU,1,363},	//( - , DU) Несанкционированное перемещение МДЗ1
	{&B2AB17LDU,1,364},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
	{&B2AB16LDU,1,365},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
	{&B2AB14LDU,1,366},	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
	{&B2AB13LDU,1,367},	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
	{&B2AB12LDU,1,368},	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{&B2AB11LDU,1,369},	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
	{&B2AB10LDU,1,370},	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
	{&A2AB12LDU,1,371},	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&A2AB13LDU,1,372},	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
	{&A2AB14LDU,1,373},	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
	{&A2AB16LDU,1,374},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
	{&A2AB17LDU,1,375},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
	{&B2AB04LDU,1,376},	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
	{&B2AB02LDU,1,377},	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
	{&B2AB01LDU,1,378},	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
	{&B2AZ03LDU,1,379},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
	{&B2AB07LDU,1,380},	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
	{&B2AB08LDU,1,381},	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
	{&B2AB05LDU,1,382},	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
	{&B2AB06LDU,1,383},	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
	{&B2AB09LDU,1,384},	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DU[]={  // 
	{&R0VX08IDU,3,0},	//( - , DU) Индикация Режим
	{&R0VL01RDU,8,1},	//( - , DU) Индикация Время задержки
	{&B2VS01IDU,3,3},	//( - , DU) Готовность к управлению РБ2
	{&B3CV02RDU,8,4},	//( - , DU) Заданная скорость перемещения ИС2
	{&B3CV01RDU,8,6},	//( - , DU) Измеренная скорость перемещения ИС2
	{&R1VS01IDU,3,8},	//( - , DU) Готовность к управлению МДЗ1
	{&R2VS01IDU,3,9},	//( - , DU) Готовность к управлению МДЗ2
	{&R4VS01IDU,3,10},	//( - , DU) Готовность к управлению тележкой реактора
	{&A6VS01IDU,3,11},	//( - , DU) Готовность к управлению БЗ1
	{&B5VS01IDU,3,12},	//( - , DU) Готовность к управлению НЛ2
	{&A5VS01IDU,3,13},	//( - , DU) Готовность к управлению НЛ1
	{&B4VS01IDU,3,14},	//( - , DU) Готовность к управлению НИ2
	{&A4VS01IDU,3,15},	//( - , DU) Готовность к управлению НИ1
	{&A2VS01IDU,3,16},	//( - , DU) Готовность к управлению РБ1
	{&B3VS01IDU,3,17},	//( - , DU) Готовность к управлению ИС2
	{&A3VS01IDU,3,18},	//( - , DU) Готовность к управлению ИС1
	{&R0VL01IDU,3,19},	//( - , DU) До импульса минут
	{&R0VL11IDU,3,20},	//( - , DU) До импульса секунд
	{&R0VL06RDU,8,21},	//( - , DU) Индикация (Время задержки от ВУ РБ)
	{&R0VL02RDU,8,23},	//( - , DU) Индикация (Время задержки ИНИ)
	{&R0VL04RDU,8,25},	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
	{&R0VL03RDU,8,27},	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
	{&R0VL05RDU,8,29},	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
	{&R0VL21IDU,3,31},	//( - , DU) Декатрон
	{&R0VS21IDU,3,32},	//( - , DU) Индикация ВИД ПРОВЕРКИ
	{&A1VS01IDU,3,33},	//( - , DU) Готовность к управлению ББ1
	{&B1VS01IDU,3,34},	//( - , DU) Готовность к управлению ББ2
	{&A1VC01RDU,8,35},	//( - , DU) Координата ББ1, мм
	{&A8VC01RDU,8,37},	//( - , DU) Координата ДС2, мм
	{&B3VC01RDU,8,39},	//( - , DU) Координата ИС2, мм
	{&B1VC01RDU,8,41},	//( - , DU) Координата ББ2, мм
	{&TTLDU,3,43},	//( - , DU) ttl
	{&R3VS01IDU,3,44},	//( - , DU) Готовность к управлению гомогенных дверей
	{&R5VS01IDU,3,45},	//( - , DU) Готовность к управлению ворот отстойной зоны
	{&B8VC01RDU,8,46},	//( - , DU) Координата АЗ2, мм
	{&B2VC01RDU,8,48},	//( - , DU) Координата РБ2, мм
	{&A2VC01RDU,8,50},	//( - , DU) Координата РБ1, мм
	{&A3VC01RDU,8,52},	//( - , DU) Координата ИС1, мм
	{&A3CP02RDU,8,54},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
	{&B3CP02RDU,8,56},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
	{&A8VS01IDU,3,58},	//( - , DU) Готовность к управлению ДС2
	{&B8VS01IDU,3,59},	//( - , DU) Готовность к управлению АЗ2
	{&B6VS01IDU,3,60},	//( - , DU) Готовность к управлению БЗ2
	{&R0CN95LDU,3,61},	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
	{&R0CN94LDU,8,62},	//( - , DU) Скорость изменения мощности
	{&R0CN93LDU,8,64},	//( - , DU) время работы на мощности более 100Вт, сек
	{&R0VN12RDU,8,66},	//( - , DU) Заданная мощность РУ
	{&R0VN11RDU,8,68},	//( - , DU) Текущая мощность РУ
	{&R0CN92LDU,8,70},	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
	{&A3MC03RDU,8,72},	//( - , DU) Координата положения ИМ 0-й реактивности
	{&R0CN91LDU,8,74},	//( - , DU) Рассчётная реактивность от регулятора
	{&A3MC02RDU,8,76},	//( - , DU) Температурная корректировка координаты ИМ
	{&A3MC01RDU,8,78},	//( - , DU) Заданная координата положения ИС от регулятора мм
	{&A8CV01RDU,8,80},	//( - , DU) Измеренная скорость перемещения ДС2
	{&B8CV01RDU,8,82},	//( - , DU) Измеренная скорость перемещения АЗ2
	{&B1CV01RDU,8,84},	//( - , DU) Измеренная скорость перемещения ББ2
	{&A1CV02RDU,8,86},	//( - , DU) Заданная скорость перемещения ББ1
	{&A1CV01RDU,8,88},	//( - , DU) Измеренная скорость перемещения ББ1
	{&A3CV02RDU,8,90},	//( - , DU) Заданная скорость перемещения ИС1
	{&B1CV02RDU,8,92},	//( - , DU) Заданная скорость перемещения ББ2
	{&A3CV01RDU,8,94},	//( - , DU) Измеренная скорость перемещения ИС1
	{&A2CV01RDU,8,96},	//( - , DU) Измеренная скорость перемещения РБ1
	{&A2CV02RDU,8,98},	//( - , DU) Заданная скорость перемещения РБ1
	{&B2CV01RDU,8,100},	//( - , DU) Измеренная скорость перемещения РБ2
	{&B2CV02RDU,8,102},	//( - , DU) Заданная скорость перемещения РБ2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DU[]={  // 
	{&R0MW12IP2,3,0},	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
	{&R0MW14IP2,3,1},	//( - , DU) Переключатель ОБДУВ
	{&B8MC01RP2,8,2},	//( - , DU) Заданная координата АЗ2 мм
	{&B3MC01RP1,8,4},	//( - , DU) Заданная координата положения ИС2 мм
	{&A3MC01RP1,8,6},	//( - , DU) Заданная координата положения ИС1 мм
	{&B1MC01RP1,8,8},	//( - , DU) Заданная координата положения ББ2  мм
	{&A1MC01RP1,8,10},	//( - , DU) Заданная координата положения ББ1 мм
	{&R0MW11IP2,3,12},	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
	{&R0MW11IP1,3,13},	//( - , DU) Переключатель ВЫСТРЕЛ
	{&R0MW16IP1,3,14},	//( - , DU) Переключатель ВИД ПРОВЕРКИ
	{&R0MW13IP1,3,15},	//( - , DU) Переключатель ВЫБОР ЗОН
	{&R0MW12IP1,3,16},	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
	{&R0MW14IP1,3,17},	//( - , DU) Переключатель ПРОГРАММЫ
	{&R0MW15IP1,3,18},	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
	{&fEM_A1UC03RDU,8,19},	//( - , DU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
	{&dEM_A1UC05UDU,5,21},	//( - , DU) Верхняя граница показания энкодера ББ, деления энкодера
	{&dEM_A1UC06UDU,5,23},	//( - , DU) Нижняя граница показания энкодера ББ, деления энкодера
	{&dEM_A2UC06UDU,5,25},	//( - , DU) Нижняя граница показания энкодера РБ, деления энкодера
	{&dEM_A2UC05UDU,5,27},	//( - , DU) Верхняя граница показания энкодера РБ, деления энкодера
	{&fEM_A2UC03RDU,8,29},	//( - , DU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
	{&dEM_A3UC06UDU,5,31},	//( - , DU) Нижняя граница показания энкодера ИС, деления энкодера
	{&dEM_A3UC05UDU,5,33},	//( - , DU) Верхняя граница показания энкодера ИС, деления энкодера
	{&fEM_A3UC03RDU,8,35},	//( - , DU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
	{&dEM_A8UC06UDU,5,37},	//( - , DU) Нижняя граница показания энкодера АЗ2, деления энкодера
	{&fEM_A8UC03RDU,8,39},	//( - , DU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
	{&dEM_A8UC05UDU,5,41},	//( - , DU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
	{&fEM_R0UV81RDU,8,43},	//( - , DU) 1-я частота двигателя (шагов/секунду)
	{&fEM_R0UV82RDU,8,45},	//( - , DU) 3-я частота двигателя (шагов/секунду)
	{&fEM_R0UV83RDU,8,47},	//( - , DU) 4-я частота двигателя (шагов/секунду)
	{&fEM_R0UV84RDU,8,49},	//( - , DU) 5-я частота двигателя (шагов/секунду)
	{&fEM_R0UV86RDU,8,51},	//( - , DU) 7-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UV85RDU,8,53},	//( - , DU) 6-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UV87RDU,8,55},	//( - , DU) 7-я скорость перемещения ББ (шагов/секунду)
	{&fEM_A3UP03RDU,8,57},	//( - , DU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{&fEM_A3UP04RDU,8,59},	//( - , DU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{&fEM_A3UP43RDU,8,61},	//( - , DU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
	{&fEM_A3UP44RDU,8,63},	//( - , DU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
	{&fEM_A3UP53RDU,8,65},	//( - , DU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
	{&fEM_A3UP85RDU,8,67},	//( - , DU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{&fEM_A3UP88RDU,8,69},	//( - , DU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{&fEM_A3UP86RDU,8,71},	//( - , DU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{&fEM_B8UV01RDU,8,73},	//( - , DU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
	{&fEM_B8UV02RDU,8,75},	//( - , DU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
	{&fEM_B8UV03RDU,8,77},	//( - , DU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
	{&fEM_B8UL04RDU,8,79},	//( - , DU) Задержка определения самохода АЗ-ДС после команды на останов, сек
	{&iEM_A2UV03CDU,3,81},	//( - , DU) Скорость 1-го диапазона РБ назад (вниз)
	{&fEM_A2UV01RDU,8,82},	//( - , DU) Допустимое превышение заданной скорости РБ мм/с
	{&fEM_A2UV02RDU,8,84},	//( - , DU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
	{&fEM_A1UV01RDU,8,86},	//( - , DU) Допустимое превышение заданной скорости ББ мм/с
	{&fEM_A1UV02RDU,8,88},	//( - , DU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
	{&fEM_A1UC06RDU,8,90},	//( - , DU) Уставка определения самохода ББ  мм
	{&fEM_A1UC05RDU,8,92},	//( - , DU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
	{&fEM_A1UL04RDU,8,94},	//( - , DU) Задержка определения самохода ББ после команды на останов, сек
	{&fEM_A3UV01RDU,8,96},	//( - , DU) Допустимое превышение заданной скорости ИС мм/с
	{&fEM_A3UV02RDU,8,98},	//( - , DU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
	{&fEM_A3UC06RDU,8,100},	//( - , DU) Уставка определения самохода ИС1  мм
	{&fEM_A3UC05RDU,8,102},	//( - , DU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
	{&fEM_A3UL04RDU,8,104},	//( - , DU) Задержка определения самохода ИС после команды на останов, сек
	{&fEM_A3UP54RDU,8,106},	//( - , DU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
	{&fEM_A3UP87RDU,8,108},	//( - , DU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{&fEM_R0UL05RDU,8,110},	//( - , DU) Время срабатывания сброса от НУП ИС
	{&fEM_R0UL20RDU,8,112},	//( - , DU) Предельное отклонение от времени задержки  сброса от II УР
	{&fEM_B8UV04RDU,8,114},	//( - , DU) Время разгона механизма при переходе на новую скорость сек
	{&fEM_B8UC06RDU,8,116},	//( - , DU) Уставка определения самохода АЗ-ДС,  мм
	{&fEM_B8UC05RDU,8,118},	//( - , DU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
	{&fEM_A2UL05RDU,8,120},	//( - , DU) Время задержки блокировки РБ по недвижению сек
	{&fEM_A2UL03RDU,8,122},	//( - , DU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{&fEM_A2UC06RDU,8,124},	//( - , DU) Уставка определения самохода РБ  мм
	{&fEM_A2UC05RDU,8,126},	//( - , DU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
	{&fEM_A2UL04RDU,8,128},	//( - , DU) Задержка определения самохода РБ после команды на останов, с
	{&fEM_A1UL03RDU,8,130},	//( - , DU) Задержка определения самохода ББ после останова (достижения скорости 0), с
	{&fEM_A1UL05RDU,8,132},	//( - , DU) Время задержки блокировки ББ по недвижению с
	{&fEM_A3UL03RDU,8,134},	//( - , DU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
	{&fEM_A3UL05RDU,8,136},	//( - , DU) Время задержки блокировки ИС по недвижению сек
	{&fEM_A1UC08RDU,8,138},	//( - , DU) Зона нечувствительности при наведении ББ  мм
	{&fEM_A3UC08RDU,8,140},	//( - , DU) Зона нечувствительности при наведении ИС 0.01 мм
	{&fEM_A1UC07RDU,8,142},	//( - , DU) Зона возврата при наведении ББ мм
	{&fEM_A1UL01RDU,8,144},	//( - , DU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{&fEM_A3UC07RDU,8,146},	//( - , DU) Зона возврата при наведении ИС 0.01 мм
	{&fEM_A3UL01RDU,8,148},	//( - , DU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{&fEM_A2UC08RDU,8,150},	//( - , DU) Зона нечувствительности при наведении РБ мм
	{&fEM_A2UC07RDU,8,152},	//( - , DU) Зона возврата при наведении РБ  мм
	{&fEM_A2UL01RDU,8,154},	//( - , DU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{&fEM_B8UC01RDU,8,156},	//( - , DU) Зона нечувствительности при наведении АЗ2,ДС2 мм
	{&fEM_B8UL07RDU,8,158},	//( - , DU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
	{&fEM_B8UC02RDU,8,160},	//( - , DU) Зона возврата при наведении АЗ2,ДС2  мм
	{&fEM_B8UL01RDU,8,162},	//( - , DU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{&fEM_B8UL05RDU,8,164},	//( - , DU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
	{&fEM_B8UL03RDU,8,166},	//( - , DU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
	{&fEM_B8UL06RDU,8,168},	//( - , DU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
	{&fEM_A9UZ03RDU,8,170},	//( - , DU) Время задержки блокировки НИ  ДС по самоходу сек
	{&fEM_A9UZ04RDU,8,172},	//( - , DU) Время задержки блокировки НИ ДС по превышению времени движения сек
	{&fEM_A9UZ05RDU,8,174},	//( - , DU) Время задержки блокировки НИ ДС по недвижению сек
	{&fEM_R4UZ04RDU,8,176},	//( - , DU) Время задержки блокировки тележки по превышению времени движения сек
	{&fEM_R4UZ03RDU,8,178},	//( - , DU) Время задержки блокировки тележки по самоходу сек
	{&fEM_R4UZ05RDU,8,180},	//( - , DU) Время задержки блокировки тележки по недвижению сек
	{&fEM_A5UZ03RDU,8,182},	//( - , DU) Время задержки блокировки НЛ по самоходу сек
	{&fEM_A5UZ04RDU,8,184},	//( - , DU) Время задержки блокировки НЛ по превышению времени движения сек
	{&fEM_A5UZ05RDU,8,186},	//( - , DU) Время задержки блокировки НЛ по недвижению сек
	{&fEM_A4UZ03RDU,8,188},	//( - , DU) Время задержки блокировки НИ по самоходу сек
	{&fEM_A4UZ04RDU,8,190},	//( - , DU) Время задержки блокировки НИ по превышению времени движения сек
	{&fEM_A4UZ05RDU,8,192},	//( - , DU) Время задержки блокировки НИ по недвижению сек
	{&fEM_A6UZ03RDU,8,194},	//( - , DU) Время задержки блокировки БЗ по самоходу сек
	{&fEM_A6UZ04RDU,8,196},	//( - , DU) Время задержки блокировки БЗ по превышению времени движения сек
	{&fEM_A6UZ05RDU,8,198},	//( - , DU) Время задержки блокировки БЗ по недвижению сек
	{&fEM_R1UZ03RDU,8,200},	//( - , DU) Время задержки блокировки МДЗ по самоходу сек
	{&fEM_R1UZ04RDU,8,202},	//( - , DU) Время задержки блокировки МДЗ по превышению времени движения сек
	{&fEM_R1UZ05RDU,8,204},	//( - , DU) Время задержки блокировки МДЗ по недвижению сек
	{&fEM_R0UL04RDU,8,206},	//( - , DU) Предельное время ожидания срабатывания АЗ от НУП ИС
	{&fEM_R0UL06RDU,8,208},	//( - , DU) Предельное время срабатывания верхней АС II УР
	{&fEM_R0UL03RDU,8,210},	//( - , DU) Время срабатывания сброса от ВУ РБ
	{&fEM_R0UL17RDU,8,212},	//( - , DU) Предельное отклонение от времени задержки  сброса от ВУ РБ
	{&fEM_R0UL19RDU,8,214},	//( - , DU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{&fEM_R0UL07RDU,8,216},	//( - , DU) Время срабатывания верхней АС II УР
	{&fEM_R0UL18RDU,8,218},	//( - , DU) Предельное отклонение от времени задержки  сброса от НУП ИС
	{&fEM_R0UL16RDU,8,220},	//( - , DU) Предельное отклонение от времени задержки  ИНИ
	{&fEM_R0UL02RDU,8,222},	//( - , DU) Время задержки  ИНИ
	{&fEM_R0UN08RDU,8,224},	//( - , DU) 8-я заданная мощность
	{&fEM_R0UN07RDU,8,226},	//( - , DU) 7-я заданная мощность
	{&fEM_R0UN06RDU,8,228},	//( - , DU) 6-я заданная мощность
	{&fEM_R0UN05RDU,8,230},	//( - , DU) 5-я заданная мощность
	{&fEM_R0UN04RDU,8,232},	//( - , DU) 4-я заданная мощность
	{&fEM_R0UN03RDU,8,234},	//( - , DU) Ограничение 3 по мощности
	{&fEM_R0UN02RDU,8,236},	//( - , DU) 2-я заданная мощность
	{&fEM_R0UN01RDU,8,238},	//( - , DU) 1-я заданная мощность
	{&fEM_A2UC82RDU,8,240},	//( - , DU) Граница 2-го диапазона РБ вперёд (вверх)
	{&fEM_A2UC83RDU,8,242},	//( - , DU) Граница 1-го диапазона РБ назад (вниз)
	{&fEM_A1UC83RDU,8,244},	//( - , DU) Граница 1-го диапазона ББ назад (вниз)
	{&fEM_A2UC81RDU,8,246},	//( - , DU) Граница 1-го диапазона РБ вперёд (вверх)
	{&fEM_A1UC81RDU,8,248},	//( - , DU) Граница 1-го диапазона ББ вперёд (вверх)
	{&fEM_A1UC82RDU,8,250},	//( - , DU) Граница 2-го диапазона ББ вперёд (вверх)
	{&fEM_A2UL83RDU,8,252},	//( - , DU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{&fEM_A3UC81RDU,8,254},	//( - , DU) Граница 1-го диапазона ИС вперёд (вверх)
	{&fEM_A3UC82RDU,8,256},	//( - , DU) Граница 1-го диапазона ИС назад (вниз)
	{&fEM_R0UN80RDU,8,258},	//( - , DU) Ограничение по мощности в режиме калибровка и имульс
	{&iEM_A2UV01IDU,3,260},	//( - , DU) Скорость 1-го диапазона РБ вперёд (вверх)
	{&iEM_A2UV02IDU,3,261},	//( - , DU) Скорость 2-го диапазона РБ вперёд (вверх)
	{&iEM_A1UV01IDU,3,262},	//( - , DU) Скорость 1-го диапазона ББ вперёд (вверх)
	{&iEM_A1UV02IDU,3,263},	//( - , DU) Скорость 2-го диапазона ББ вперёд (вверх)
	{&iEM_A1UV03IDU,3,264},	//( - , DU) Скорость1-го диапазона ББ назад (вниз)
	{&iEM_A3UV01IDU,3,265},	//( - , DU) Скорость ИС для 1-го диапазона вперёд (вверх)
	{&iEM_A3UV02IDU,3,266},	//( - , DU) Скорость ИС для 1-го диапазона назад (вниз)
	{&fEM_A3UC09RDU,8,267},	//( - , DU) Координата переднего аварийного выключателя ИС мм
	{&fEM_A2UC02RDU,8,269},	//( - , DU) Коэффициент преобразования частота-скорость(мм/сек)
	{&fEM_A1UC02RDU,8,271},	//( - , DU) Коэффициент преобразования частота-скорость(мм/сек) ББ
	{&fEM_A3UC02RDU,8,273},	//( - , DU) Коэффициент преобразования частота-скорость (мм/сек) ИС
	{&fEM_R0UL21RDU,8,275},	//( - , DU) Предельное время задержки  сброса от ВУ РБ
	{&fEM_R0UN09RDU,8,277},	//( - , DU) Минимальный период при регулировании мощности
	{&fEM_R0UN11RDU,8,279},	//( - , DU) Допустимое превышение заданной мощности  при регулировании
	{&fEM_R0UN12RDU,8,281},	//( - , DU) Зона нечувствительности при регулировании мощности %
	{&fEM_R0UN13RDU,8,283},	//( - , DU) Минимальное изменение координаты, мм
	{&fEM_R0UN14RDU,8,285},	//( - , DU) Максимальная координата штока ИМ, мм
	{&fEM_R0UN16RDU,8,287},	//( - , DU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
	{&fEM_R0UN17RDU,8,289},	//( - , DU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
	{&fEM_R0UN18RDU,8,291},	//( - , DU) Коэффициент t1 ф-ции температурной корректировки ИМ
	{&fEM_R0UN19RDU,8,293},	//( - , DU) Коэффициент t0 ф-ции температурной корректировки ИМ
	{&fEM_R0UN70LDU,8,295},	//( - , DU) 0 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_R0UN71LDU,8,297},	//( - , DU) 1 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_R0UN72LDU,8,299},	//( - , DU) 2 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_R0UN73LDU,8,301},	//( - , DU) 3 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_R0UN74LDU,8,303},	//( - , DU) 4 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_R0UN75LDU,8,305},	//( - , DU) 5 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_R0UN80LDU,8,307},	//( - , DU) 0 - Коэффициент  опережения старта ИМ
	{&fEM_R0UN81LDU,8,309},	//( - , DU) 1 - Коэффициент  опережения старта ИМ
	{&fEM_R0UN82LDU,8,311},	//( - , DU) 2 - Коэффициент  опережения старта ИМ
	{&fEM_R0UN83LDU,8,313},	//( - , DU) 3 - Коэффициент  опережения старта ИМ
	{&fEM_R0UN84LDU,8,315},	//( - , DU) 4 - Коэффициент  опережения старта ИМ
	{&fEM_R0UN85LDU,8,317},	//( - , DU) 5 - Коэффициент  опережения старта ИМ
	{&fEM_R0UT20RDU,8,319},	//( - , DU) Предельное время работы на мощности более 100 Вт, сек
	{&fEM_R0UN25RDU,8,321},	//( - , DU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
	{&fEM_R0UN15RDU,8,323},	//( - , DU) коэффициент рассогласования по координате для транспортной реактивности %
	{&fEM_R0UN26RDU,8,325},	//( - , DU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
	{&fEM_R0UN27RDU,8,327},	//( - , DU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
	{&fEM_R0UN24RDU,8,329},	//( - , DU) Нижняя граница интервала мощности для измерения периода (ватт)
	{&fEM_R0UL25RDU,8,331},	//( - , DU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_MDuBz1[]={  // 
	{&R0AD21LDU,1,0},	//( - , SBz1DU) Подключить защиту от II УР
	{&R0VW23LDU,1,1},	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,1,2},	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MDuBz1[]={  // 
	{&B0VT71LZ1,1,0},	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
	{&R0VP73LZ1,1,1},	//( - , Baz1, SBz1DU) ПС давления для РУ
	{&B0VN71LZ1,1,2},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
	{&A0VN71LZ1,1,3},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
	{&A0EE03LZ1,1,4},	//( - , Baz1, SBz1DU) Исправность АКНП3
	{&A0EE02LZ1,1,5},	//( - , Baz1, SBz1DU) Исправность АКНП2
	{&A0EE04LZ1,1,6},	//( - , Baz1, SBz1DU) Исправность АКНП4
	{&A0EE01LZ1,1,7},	//( - , Baz1, SBz1DU) Исправность АКНП1
	{&B0VP71LZ1,1,8},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
	{&A0VP71LZ1,1,9},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
	{&A0VT71LZ1,1,10},	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MDuBz1[]={  // 
	{&B0CT01IZ1,8,0},	//( - , Baz1, SBz1DU) Температура АЗ2-1
	{&R0VN11RZ1,8,2},	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
	{&R0VN09RZ1,8,4},	//( - , Baz1, SBz1DU) Усредненный период разгона
	{&A0CT01IZ1,8,6},	//( - , Baz1, SBz1DU) Температура АЗ1-1
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
	{&R0AD21LDU,1,0},	//( - , SBz2DU) Подключить защиту от II УР
	{&R0VW23LDU,1,1},	//( - , Baz2, SBz2DU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,1,2},	//( - , Baz2, SBz2DU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MDuBz2[]={  // 
	{&B0VT71LZ2,1,0},	//( - , Baz2, SBz2DU) АС по температуре в АЗ2
	{&R0VP73LZ2,1,1},	//( - , Baz2, SBz2DU) ПС давления для РУ
	{&B0VN71LZ2,1,2},	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ2
	{&A0VN71LZ2,1,3},	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ1
	{&A0EE03LZ2,1,4},	//( - , Baz2, SBz2DU) Исправность АКНП3
	{&A0EE02LZ2,1,5},	//( - , Baz2, SBz2DU) Исправность АКНП2
	{&A0EE04LZ2,1,6},	//( - , Baz2, SBz2DU) Исправность АКНП4
	{&A0EE01LZ2,1,7},	//( - , Baz2, SBz2DU) Исправность АКНП1
	{&B0VP71LZ2,1,8},	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ2
	{&A0VP71LZ2,1,9},	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ1
	{&A0VT71LZ2,1,10},	//( - , Baz2, SBz2DU) АС по температуре в АЗ1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MDuBz2[]={  // 
	{&B0CT01IZ2,8,0},	//( - , Baz2, SBz2DU) Температура АЗ2-1
	{&R0VN11RZ2,8,2},	//( - , Baz2, SBz2DU) Средняя мощность по БАЗ1
	{&R0VN09RZ2,8,4},	//( - , Baz2, SBz2DU) Усредненный период разгона
	{&A0CT01IZ2,8,6},	//( - , Baz2, SBz2DU) Температура АЗ1-1
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
	{&A2IC01UDU,5,0},	//( - , SDu) Координата штока РБ1
	{&A3IC01UDU,5,2},	//( - , SDu) Координата штока ИС1
	{&B3IC01UDU,5,4},	//( - , SDu) Координата штока ИС2
	{&A8IC01UDU,5,6},	//( - , SDu) Координата ДС2
	{&B8IC01UDU,5,8},	//( - , SDu) Координата АЗ2
	{&B2IC01UDU,5,10},	//( - , SDu) Координата штока РБ2
	{&A1IC01UDU,5,12},	//( - , SDu) Координата штока ББ1
	{&B1IC01UDU,5,14},	//( - , SDu) Координата штока ББ2
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
static ModbusRegister coil_DiagnDU[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DiagnDU[]={  // 
	{&R0DE3CLDU,1,0},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
	{&R0DE3DLDU,1,1},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
	{&R0DEB4LDU,1,2},	//( - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
	{&R0DEB1LDU,1,3},	//( - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
	{&R0DEB2LDU,1,4},	//( - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
	{&R0DEB3LDU,1,5},	//( - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
	{&R0DE39LDU,1,6},	//( - S09SBK, DiagnDU) диагностика шкафа ДУ МП24-2 место 4
	{&R0DE38LDU,1,7},	//( - S08SBK, DiagnDU) диагностика шкафа ДУ МП15-3 место 3
	{&R0DE37LDU,1,8},	//( - S07SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 2
	{&R0DE36LDU,1,9},	//( - S06SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 1
	{&R0DE35LDU,1,10},	//( - S05SBK, DiagnDU) диагностика шкафа ДУ температура больше 53
	{&R0DE34LDU,1,11},	//( - S04SBK, DiagnDU) диагностика шкафа ДУ температура меньше 43
	{&R0DE33LDU,1,12},	//( - S03SBK, DiagnDU) диагностика шкафа ДУ двери
	{&R0DE32LDU,1,13},	//( - S02SBK, DiagnDU) диагностика шкафа ДУ сеть 2
	{&R0DE31LDU,1,14},	//( - S01SBK, DiagnDU) диагностика шкафа ДУ сеть 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DiagnDU[]={  // 
	{&R0DE0FLDU,3,0},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
	{&R0DE0DLDU,3,1},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
	{&R0DE0BLDU,3,2},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
	{&R0DE0CLDU,3,3},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
	{&R0DE07LDU,3,4},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
	{&R0DE0ALDU,3,5},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
	{&R0DE09LDU,3,6},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
	{&R0DE05LDU,3,7},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
	{&R0DE08LDU,3,8},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
	{&R0DE04LDU,3,9},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
	{&R0DE03LDU,3,10},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
	{&R0DE02LDU,3,11},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DiagnDU[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_DU[0],&di_DU[0],&ir_DU[0],&hr_DU[0],NULL,NULL,NULL,0},	 //Общий слэйв
	{1,5010,&coil_MDuBz1[0],&di_MDuBz1[0],&ir_MDuBz1[0],&hr_MDuBz1[0],NULL,MDuBz1_ip1,MDuBz1_ip2,100},	 //Мастер ДУ в Баз1
	{1,5009,&coil_MDuBz2[0],&di_MDuBz2[0],&ir_MDuBz2[0],&hr_MDuBz2[0],NULL,MDuBz2_ip1,MDuBz2_ip2,100},	 //Мастер ДУ в Баз2
	{1,5005,&coil_MDuS[0],&di_MDuS[0],&ir_MDuS[0],&hr_MDuS[0],NULL,MDuS_ip1,MDuS_ip2,10},	 //Мастер ДУ в SCM
	{0,5006,&coil_DiagnDU[0],&di_DiagnDU[0],&ir_DiagnDU[0],&hr_DiagnDU[0],NULL,NULL,NULL,0},	 //Диагностика DU

	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3202[132];	//VDS32-02
static vds32r_inipar ini_VDS3202={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3202={0,0,&ini_VDS3202,buf_VDS3202,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3202[]={
	{&R1IS11LDU,1,52},
	{&R2IS11LDU,1,56},
	{&B1IS21LDU,1,16},
	{&R8IS11LDU,1,26},
	{&B2IS12LDU,1,18},
	{&B1IS12LDU,1,12},
	{&B4IS21LDU,1,62},
	{&R0DE02LDU,3,64},
	{&B1IS11LDU,1,14},
	{&B2IS11LDU,1,20},
	{&B9IS21LDU,1,50},
	{&B9IS11LDU,1,48},
	{&A9IS21LDU,1,46},
	{&A9IS11LDU,1,44},
	{&A3VZ13LZ1,1,34},
	{&R0AD14LZ1,1,38},
	{&A1VN71LZ1,1,40},
	{&R0VZ71LZ1,1,42},
	{&B7AS31LDU,1,10},
	{&B4IS10LDU,1,6},
	{&B3IS35LDU,1,0},
	{&B3IS33LDU,1,2},
	{&B3IS31LDU,1,8},
	{&B2IS33LDU,1,4},
	{&A3VZ15LZ1,1,36},
	{&R2IS21LDU,1,58},
	{&R1IS21LDU,1,54},
	{&B4IS11LDU,1,60},
	{&B3IS21LDU,1,24},
	{&B2IS21LDU,1,22},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3203[132];	//VDS32-03
static vds32r_inipar ini_VDS3203={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3203={0,0,&ini_VDS3203,buf_VDS3203,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3203[]={
	{&R0DE03LDU,3,64},
	{&A4IS11LDU,1,26},
	{&A1IS11LDU,1,14},
	{&A2IS21LDU,1,22},
	{&A2IS11LDU,1,20},
	{&R0IS02LDU,1,58},
	{&R0IS01LDU,1,56},
	{&A3VZ13LZ2,1,34},
	{&R0AD14LZ2,1,38},
	{&A1VN71LZ2,1,40},
	{&A4IS10LDU,1,6},
	{&A3IS35LDU,1,0},
	{&A3IS33LDU,1,2},
	{&A3IS31LDU,1,8},
	{&A2IS33LDU,1,4},
	{&R0VZ71LZ2,1,42},
	{&A7AS31LDU,1,10},
	{&A3IS21LDU,1,24},
	{&A3VZ15LZ2,1,36},
	{&A1IS21LDU,1,16},
	{&A1IS12LDU,1,12},
	{&A4IS21LDU,1,28},
	{&A2IS12LDU,1,18},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3204[132];	//VDS32-04
static vds32r_inipar ini_VDS3204={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3204={0,0,&ini_VDS3204,buf_VDS3204,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3204[]={
	{&B6IS21LDU,1,26},
	{&A8IS22LDU,1,60},
	{&A8IS12LDU,1,58},
	{&B8IS22LDU,1,42},
	{&A5IS21LDU,1,22},
	{&A6IS11LDU,1,16},
	{&A5IS11LDU,1,20},
	{&A6IS21LDU,1,18},
	{&B8IS11LDU,1,36},
	{&B5IS21LDU,1,30},
	{&B3IS11LDU,1,4},
	{&A3IS11LDU,1,0},
	{&B3IS22LDU,1,6},
	{&A3IS22LDU,1,2},
	{&R5IS11LDU,1,48},
	{&R6IS21LDU,1,56},
	{&R0DE04LDU,3,64},
	{&B6IS11LDU,1,24},
	{&R5IS21LDU,1,50},
	{&R4IS11LDU,1,8},
	{&B8IS21LDU,1,38},
	{&B8IS12LDU,1,40},
	{&R4IS12LDU,1,10},
	{&R4IS22LDU,1,14},
	{&R3IS11LDU,1,32},
	{&R3IS21LDU,1,34},
	{&R4IS21LDU,1,12},
	{&B5IS11LDU,1,28},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3205[132];	//VDS32-05
static vds32r_inipar ini_VDS3205={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3205={0,0,&ini_VDS3205,buf_VDS3205,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3205[]={
	{&B1IE04LDU,1,30},
	{&B1IE03LDU,1,28},
	{&A3IE04LDU,1,22},
	{&A3IE03LDU,1,20},
	{&A2IE04LDU,1,14},
	{&A2IE03LDU,1,12},
	{&A1IE04LDU,1,6},
	{&R6IS51LDU,1,56},
	{&R6IS52LDU,1,58},
	{&R6IS41LDU,1,52},
	{&R6IS42LDU,1,54},
	{&R6IS32LDU,1,50},
	{&A1IE03LDU,1,4},
	{&R6IS31LDU,1,48},
	{&R0DE05LDU,3,64},
	{&B2IE02LDU,1,32},
	{&B3IE02LDU,1,40},
	{&B1IE02LDU,1,24},
	{&B3IE01LDU,1,42},
	{&B2IE01LDU,1,34},
	{&B1IE01LDU,1,26},
	{&A2IE02LDU,1,8},
	{&A3IE02LDU,1,16},
	{&A1IE02LDU,1,0},
	{&A2IE01LDU,1,10},
	{&A3IE01LDU,1,18},
	{&A1IE01LDU,1,2},
	{&B2IE03LDU,1,36},
	{&B2IE04LDU,1,38},
	{&B3IE03LDU,1,44},
	{&B3IE04LDU,1,46},
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
	{&A2AD21LDU,1,2},
	{&A2AD02LDU,1,6},
	{&A2AD11LDU,1,0},
	{&A2AD03LDU,1,8},
	{&A2AD04LDU,1,10},
	{&A2AD05LDU,1,12},
	{&B2AD04LDU,1,24},
	{&B2AD05LDU,1,26},
	{&B2AD11LDU,1,14},
	{&B2AD03LDU,1,22},
	{&R0DE07LDU,3,38},
	{&A2AD01LDU,1,4},
	{&B2AD02LDU,1,20},
	{&B2AD21LDU,1,16},
	{&B2AD01LDU,1,18},
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
	{&B1AD11LDU,1,14},
	{&B1AD01LDU,1,18},
	{&A1AD01LDU,1,4},
	{&A1AD05LDU,1,12},
	{&B1AD05LDU,1,26},
	{&A1AD04LDU,1,10},
	{&A1AD03LDU,1,8},
	{&A1AD02LDU,1,6},
	{&A1AD21LDU,1,2},
	{&R0DE08LDU,3,38},
	{&A1AD11LDU,1,0},
	{&B1AD21LDU,1,16},
	{&B1AD02LDU,1,20},
	{&B1AD04LDU,1,24},
	{&B1AD03LDU,1,22},
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
	{&R0DE09LDU,3,38},
	{&B7AP31LDU,1,10},
	{&A6AD10LDU,1,16},
	{&A6AD20LDU,1,18},
	{&B6AD10LDU,1,20},
	{&B6AD20LDU,1,22},
	{&B8AD10LDU,1,28},
	{&B2AD33LDU,1,4},
	{&B3AD33LDU,1,2},
	{&B8AD20LDU,1,30},
	{&B3AD31LDU,1,8},
	{&A8AD20LDU,1,14},
	{&R4AD10LDU,1,24},
	{&R4AD20LDU,1,26},
	{&A8AD10LDU,1,12},
	{&B4AD10LDU,1,6},
	{&B3AD34LDU,1,0},
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
	{&R2AD10LDU,1,16},
	{&R2AD20LDU,1,18},
	{&A4AD10LDU,1,6},
	{&A3AD31LDU,1,8},
	{&A7AP31LDU,1,10},
	{&R1AD20LDU,1,14},
	{&R1AD10LDU,1,12},
	{&A3AD34LDU,1,0},
	{&A3AD33LDU,1,2},
	{&R0DE0ALDU,3,38},
	{&A2AD33LDU,1,4},
	{&A5AD20LDU,1,22},
	{&A5AD10LDU,1,20},
	{&B5AD20LDU,1,26},
	{&B5AD10LDU,1,24},
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
	{&A3AD01LDU,1,4},
	{&A3AD05LDU,1,12},
	{&A3AD04LDU,1,10},
	{&B3AD02LDU,1,20},
	{&B3AD03LDU,1,22},
	{&B3AD04LDU,1,24},
	{&B3AD05LDU,1,26},
	{&B3AD01LDU,1,18},
	{&R0DE0BLDU,3,38},
	{&B3AD21LDU,1,16},
	{&B9AD10LDU,1,30},
	{&B3AD11LDU,1,14},
	{&A9AD10LDU,1,28},
	{&A3AD11LDU,1,0},
	{&A3AD21LDU,1,2},
	{&A3AD02LDU,1,6},
	{&A3AD03LDU,1,8},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vas84r.h>
static char buf_VAS8412[30];	//VAS84-12
static vas84r_inipar ini_VAS8412={0xc6,255,1,8,0xff,0,16,};
#pragma pack(push,1)
static table_drv table_VAS8412={0,0,&ini_VAS8412,buf_VAS8412,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VAS8412[]={
	{&A3IP02IDU,3,0},
	{&B3IP02IDU,3,3},
	{&R0DE0CLDU,3,26},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3213[132];	//VDS32-13
static vds32r_inipar ini_VDS3213={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3213={0,0,&ini_VDS3213,buf_VDS3213,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3213[]={
	{&R0DE0DLDU,3,64},
	{&B6VS12LDU,1,38},
	{&R4VS12LDU,1,2},
	{&R4VS22LDU,1,4},
	{&R0IE02LDU,1,44},
	{&B5VS22LDU,1,28},
	{&A5VS12LDU,1,20},
	{&A5VS22LDU,1,22},
	{&R0IE01LDU,1,46},
	{&B5VS12LDU,1,26},
	{&A6IE01LDU,1,36},
	{&B6VS22LDU,1,40},
	{&B6IE01LDU,1,42},
	{&R1VS12LDU,1,8},
	{&R2VS12LDU,1,14},
	{&R2VS22LDU,1,16},
	{&R1VS22LDU,1,10},
	{&A6VS12LDU,1,32},
	{&A8IE01LDU,1,6},
	{&A6VS22LDU,1,34},
	{&B5IE01LDU,1,30},
	{&R6IS61LDU,1,0},
	{&R2IE01LDU,1,18},
	{&R1IE01LDU,1,12},
	{&A5IE02LDU,1,24},
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
	{&R8AD21LDU,1,22},
	{&R0AD16LDU,1,24},
	{&R0DE0FLDU,3,38},
	{&B1AD32LDU,1,8},
	{&A1AD32LDU,1,0},
	{&B2AD32LDU,1,12},
	{&A2AD32LDU,1,4},
	{&B1AD31LDU,1,10},
	{&A1AD31LDU,1,2},
	{&R0AD04LZ2,1,28},
	{&R0AD05LZ1,1,20},
	{&R0AD05LZ2,1,30},
	{&R0AD04LZ1,1,18},
	{&R0AD03LZ2,1,26},
	{&R0AD03LZ1,1,16},
	{&A2AD31LDU,1,6},
	{&B2AD31LDU,1,14},
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
	{&R0DEB2LDU,1,20},
	{&R0DEB1LDU,1,18},
	{&R0DEB4LDU,1,24},
	{&R0DEB3LDU,1,22},
	{&R0DE39LDU,1,16},
	{&R0DE38LDU,1,14},
	{&R0DE37LDU,1,12},
	{&R0DE36LDU,1,10},
	{&R0DE35LDU,1,8},
	{&R0DE34LDU,1,6},
	{&R0DE33LDU,1,4},
	{&R0DE32LDU,1,2},
	{&R0DE31LDU,1,0},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0xc2,0x02,15,132,def_buf_VDS3202,&table_VDS3202}, //VDS32-02
	{0xc2,0x03,15,132,def_buf_VDS3203,&table_VDS3203}, //VDS32-03
	{0xc2,0x04,15,132,def_buf_VDS3204,&table_VDS3204}, //VDS32-04
	{0xc2,0x05,15,132,def_buf_VDS3205,&table_VDS3205}, //VDS32-05
	{0x96,0x07,20,40,def_buf_FDS1607,&table_FDS1607}, //FDS16-07
	{0x96,0x08,20,40,def_buf_FDS1608,&table_FDS1608}, //FDS16-08
	{0x96,0x09,20,40,def_buf_FDS1609,&table_FDS1609}, //FDS16-09
	{0x96,0x0a,20,40,def_buf_FDS1610,&table_FDS1610}, //FDS16-10
	{0x96,0x0b,20,40,def_buf_FDS1611,&table_FDS1611}, //FDS16-11
	{0xc6,0x0c,7,30,def_buf_VAS8412,&table_VAS8412}, //VAS84-12
	{0xc2,0x0d,15,132,def_buf_VDS3213,&table_VDS3213}, //VDS32-13
	{0x96,0x0f,20,40,def_buf_FDS1615,&table_FDS1615}, //FDS16-15
	{0xcc,0x20,4,26,def_buf_SBKFP,&table_SBKFP}, //SBKFP
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
	setAsFloat(730,0.0000976563);
	setAsInt(731,1024200);
	setAsInt(732,-200);
	setAsInt(733,-200);
	setAsInt(734,1024200);
	setAsFloat(735,0.0000976563);
	setAsInt(736,-200);
	setAsInt(737,1689599);
	setAsFloat(738,0.00009765625);
	setAsInt(739,-200);
	setAsFloat(740,0.0009765625);
	setAsInt(741,1536200);
	setAsFloat(742,100);
	setAsFloat(743,200);
	setAsFloat(744,300);
	setAsFloat(745,400);
	setAsFloat(746,600);
	setAsFloat(747,500);
	setAsFloat(748,750);
	setAsFloat(749,2.5);
	setAsFloat(750,0);
	setAsFloat(751,0.46);
	setAsFloat(752,0.49);
	setAsFloat(753,0.52);
	setAsFloat(754,0.53);
	setAsFloat(755,0.67);
	setAsFloat(756,0.56);
	setAsFloat(757,4);
	setAsFloat(758,4);
	setAsFloat(759,10.91);
	setAsFloat(760,3);
	setAsShort(761,4);
	setAsFloat(762,0.15);
	setAsFloat(763,0.15);
	setAsFloat(764,0.4);
	setAsFloat(765,0.4);
	setAsFloat(766,0.03);
	setAsFloat(767,0.04);
	setAsFloat(768,3);
	setAsFloat(769,0.3);
	setAsFloat(770,0.3);
	setAsFloat(771,0.07);
	setAsFloat(772,0.04);
	setAsFloat(773,3);
	setAsFloat(774,0.55);
	setAsFloat(775,0.64);
	setAsFloat(776,0.180);
	setAsFloat(777,0.025);
	setAsFloat(778,0.1);
	setAsFloat(779,2);
	setAsFloat(780,0.3);
	setAsFloat(781,3);
	setAsFloat(782,1.50);
	setAsFloat(783,0.04);
	setAsFloat(784,0.05);
	setAsFloat(785,3);
	setAsFloat(786,1.50);
	setAsFloat(787,3);
	setAsFloat(788,1.50);
	setAsFloat(789,2);
	setAsFloat(790,0.004);
	setAsFloat(791,0.006);
	setAsFloat(792,0.006);
	setAsFloat(793,1.0);
	setAsFloat(794,0.01);
	setAsFloat(795,1);
	setAsFloat(796,0.008);
	setAsFloat(797,0.01);
	setAsFloat(798,1);
	setAsFloat(799,0.4);
	setAsFloat(800,120);
	setAsFloat(801,0.6);
	setAsFloat(802,1);
	setAsFloat(803,2);
	setAsFloat(804,1.50);
	setAsFloat(805,2.0);
	setAsFloat(806,1);
	setAsFloat(807,15);
	setAsFloat(808,0.50);
	setAsFloat(809,360);
	setAsFloat(810,1);
	setAsFloat(811,2);
	setAsFloat(812,1.0);
	setAsFloat(813,6.0);
	setAsFloat(814,0.50);
	setAsFloat(815,1.0);
	setAsFloat(816,16.0);
	setAsFloat(817,3.0);
	setAsFloat(818,1.0);
	setAsFloat(819,60.0);
	setAsFloat(820,0.50);
	setAsFloat(821,1.0);
	setAsFloat(822,20.0);
	setAsFloat(823,0.50);
	setAsFloat(824,2.0);
	setAsFloat(825,2.0);
	setAsFloat(826,1.5);
	setAsFloat(827,0.06);
	setAsFloat(828,0.01);
	setAsFloat(829,0.045);
	setAsFloat(830,0.040);
	setAsFloat(831,0.007);
	setAsFloat(832,0.014);
	setAsFloat(833,2000.0);
	setAsFloat(834,1500.0);
	setAsFloat(835,1000.0);
	setAsFloat(836,800.0);
	setAsFloat(837,500.0);
	setAsFloat(838,200.0);
	setAsFloat(839,100.0);
	setAsFloat(840,0.001);
	setAsFloat(841,100);
	setAsFloat(842,100);
	setAsFloat(843,110.0);
	setAsFloat(844,20);
	setAsFloat(845,30.0);
	setAsFloat(846,100.0);
	setAsFloat(847,1.50);
	setAsFloat(848,170);
	setAsFloat(849,170);
	setAsFloat(850,10);
	setAsShort(851,1);
	setAsShort(852,4);
	setAsShort(853,1);
	setAsShort(854,4);
	setAsShort(855,4);
	setAsShort(856,4);
	setAsShort(857,4);
	setAsBool(858,0);
	setAsFloat(859,159.99);
	setAsFloat(860,0.002375);
	setAsFloat(861,0.000877);
	setAsFloat(862,0.001675);
	setAsFloat(863,2.5);
	setAsFloat(864,30);
	setAsFloat(865,30);
	setAsFloat(866,0.05);
	setAsFloat(867,0.05);
	setAsFloat(868,160.0);
	setAsFloat(869,-170.11);
	setAsFloat(870,76.25088);
	setAsFloat(871,0.271145);
	setAsFloat(872,24.93556615);
	setAsFloat(873,0.1268);
	setAsFloat(874,0.1567);
	setAsFloat(875,0.1858);
	setAsFloat(876,0.2066);
	setAsFloat(877,0.2646);
	setAsFloat(878,0.2995);
	setAsFloat(879,0.721275);
	setAsFloat(880,0.700575);
	setAsFloat(881,0.6681);
	setAsFloat(882,0.61515);
	setAsFloat(883,0.3885);
	setAsFloat(884,0.23325);
	setAsFloat(885,3600.0);
	setAsFloat(886,0.935);
	setAsFloat(887,0.1);
	setAsFloat(888,0.006792308);
	setAsFloat(889,0.000418877);
	setAsFloat(890,0.0015);
	setAsFloat(891,0.30);
	setAsBool(246,1);
	setAsBool(248,1);
	setAsBool(244,1);
	setAsBool(247,1);
	setAsBool(249,1);
	setAsBool(245,1);
	setAsBool(237,1);
	setAsBool(238,1);
	setAsBool(239,1);
}
uspaint8 InternalBuf[8551];

/* ����������� �������� ��� � ������*/
ssint iRM_8_ = {8,0}; /* N-����� ������ */ 
sslong dRM_16777215_ = {16777215,0}; /*  */ 
sschar bRM_1_ = {1,0}; /* FileN - ����� ����� ������ */ 
ssint iRM_0_ = {0,0}; /* FileOffs - �������� � ����� ������ */ 
ssint iRM_4_ = {4,0}; /* p */ 
ssfloat fRM_0_0 = {0.0,0}; /* ��������� ���������� �� �� ��������� */ 
ssfloat fRM_1500_0 = {1500.0,0}; /* ��������� ���������� ��2/��2 �� ��������� */ 
ssfloat fRM_100_ = {100,0}; /* ��������� ���������� �� �� ��������� */ 
ssint iRM_2_ = {2,0}; /* p */ 
ssint iRM_1_ = {1,0}; /* p */ 
ssint iRM_3_ = {3,0}; /* p */ 
ssint iRM_11_ = {11,0}; /* p */ 
ssint iRM_5_ = {5,0}; /* p */ 
ssint iRM_6_ = {6,0}; /* p */ 
ssbool lRM_1_ = {1,0}; /* A-������� ������� ��������� � */ 
ssbool lRM_0_ = {0,0}; /* B-������� ������� ��������� � */ 
sslong dRM_0_ = {0,0}; /* lx ���� ���� */ 
sschar bRM_0_ = {0,0}; /* cx ���� �������� */ 
ssint iRM_21_ = {21,0}; /* N-����� ������ */ 
ssint iRM_17_ = {17,0}; /* N-����� ������ */ 
ssint iRM_7_ = {7,0}; /* N-����� ������ */ 
ssint iRM_20_ = {20,0}; /* N-����� ������ */ 
ssint iRM_18_ = {18,0}; /* N-����� ������ */ 
ssint iRM_80_ = {80,0}; /* N-����� ������ */ 
ssint iRM_10_ = {10,0}; /* N-����� ������ */ 
ssint iRM_150_ = {150,0}; /* N-����� ������ */ 
ssint iRM_12_ = {12,0}; /* N-����� ������ */ 
ssint iRM_60_ = {60,0}; /* N-����� ������ */ 
ssint iRM_9_ = {9,0}; /* p */ 
ssint iRM_16_ = {16,0}; /* n - N-����������� ������� x */ 
ssfloat fRM_0_ = {0,0}; /* x - ������ ������� ���������� */ 
ssint iRM_13_ = {13,0}; /* N-����� ������ */ 
ssint iRM_3276_ = {3276,0}; /* a */ 
ssint iRM_16383_ = {16383,0}; /* b */ 
sschar bRM_2_ = {2,0}; /* type - ��� �������� 1-���,2-�� ��,3-2��,4-��� ��,5-�� ��, 6-����� */ 
sschar bRM_3_ = {3,0}; /* type - ��� �������� 1-���,2-�� ��,3-2��,4-��� ��,5-�� ��, 6-����� */ 
sschar bRM_4_ = {4,0}; /* type - ��� �������� 1-���,2-�� ��,3-2��,4-��� ��,5-�� ��, 6-����� */ 
sschar bRM_5_ = {5,0}; /* type - ��� �������� 1-���,2-�� ��,3-2��,4-��� ��,5-�� ��, 6-����� */ 
sschar bRM_6_ = {6,0}; /* type - ��� �������� 1-���,2-�� ��,3-2��,4-��� ��,5-�� ��, 6-����� */ 
ssfloat fRM_160_ = {160,0}; /* x - ������ ������� ���������� */ 
ssfloat fRM_20_ = {20,0}; /* x - ������ ������� ���������� */ 
ssfloat fRM_20_03 = {20.03,0}; /* X2 */ 
ssfloat fRM_20_0 = {20.0,0}; /* X2 */ 
ssint iRM_14_ = {14,0}; /* n - N-����������� ������� x */ 
ssfloat fRM_2_0 = {2.0,0}; /* tz - ����� �������� */ 
ssfloat fRM_3_0 = {3.0,0}; /* tz - ����� �������� */ 
ssfloat fRM_2_5 = {2.5,0}; /* tz - ����� �������� */ 
ssfloat fRM_15_0 = {15.0,0}; /* tz - ����� �������� */ 
ssfloat fRM_0_002 = {0.002,0}; /* x - ������ ������� ���������� */ 
ssfloat fRM_0_005 = {0.005,0}; /* x - ������ ������� ���������� */ 
ssfloat fRM_0_007 = {0.007,0}; /* x - ������ ������� ���������� */ 
ssfloat fRM_0_01 = {0.01,0}; /* x - ������ ������� ���������� */ 
ssfloat fRM_0_015 = {0.015,0}; /* x - ������ ������� ���������� */ 
ssfloat fRM_0_02 = {0.02,0}; /* x - ������ ������� ���������� */ 
ssfloat fRM_1_7 = {1.7,0}; /* x - ������ ������� ���������� */ 
ssfloat fRM_10_0 = {10.0,0}; /* tz - ����� �������� */ 
ssfloat fRM_0_15 = {0.15,0}; /* tz - ������ ��������, sek */ 
ssfloat fRM_0_2 = {0.2,0}; /* tz - ������ ��������, sek */ 
ssfloat fRM_0_5 = {0.5,0}; /* Tpr - ����� ������ �������� ��� �� ������ ��������� */ 
ssfloat fRM_3_5 = {3.5,0}; /* Tpr - ����� ������ �������� ��� �� ������ ��������� */ 
ssfloat fRM_6_5 = {6.5,0}; /* Tpr - ����� ������ �������� ��� �� ������ ��������� */ 
ssfloat fRM_9_5 = {9.5,0}; /* Tpr - ����� ������ �������� ��� �� ������ ��������� */ 
ssfloat fRM_12_5 = {12.5,0}; /* Tpr - ����� ������ �������� ��� �� ������ ��������� */ 
ssfloat fRM_15_5 = {15.5,0}; /* Tpr - ����� ���������� �������� ��� �� ������ ��������� */ 
ssfloat fRM_30_0 = {30.0,0}; /* Tpr - ����� ������ �������� ��� �� ������ ��������� */ 
ssfloat fRM_50_0 = {50.0,0}; /* Tpr - ����� ������ �������� ��� �� ������ ��������� */ 
ssfloat fRM_70_0 = {70.0,0}; /* Tpr - ����� ������ �������� ��� �� ������ ��������� */ 
ssfloat fRM_90_0 = {90.0,0}; /* Tpr - ����� ������ �������� ��� �� ������ ��������� */ 
ssfloat fRM_110_0 = {110.0,0}; /* Tpr - ����� ������ �������� ��� �� ������ ��������� */ 
ssfloat fRM_130_0 = {130.0,0}; /* Tpr - ����� ������ �������� ��� �� ������ ��������� */ 
ssfloat fRM_150_0 = {150.0,0}; /* Tpr - ����� ������ �������� ��� �� ������ ��������� */ 
ssfloat fRM_170_0 = {170.0,0}; /* Tpr - ����� ������ �������� ��� �� ������ ��������� */ 
ssfloat fRM_200_0 = {200.0,0}; /* Tpr - ����� ��������� �������� ��� �� ������ ��������� */ 
ssfloat fRM_6_0 = {6.0,0}; /* Tpr - ����� ������ �������� ��� �� ������ ��������� */ 
ssfloat fRM_126_0 = {126.0,0}; /* Tpr - ����� ������ �������� ��� �� ������ ��������� */ 
ssfloat fRM_246_0 = {246.0,0}; /* Tpr - ����� ������ �������� ��� �� ������ ��������� */ 
ssfloat fRM_366_0 = {366.0,0}; /* Tpr - ����� ������ �������� ��� �� ������ ��������� */ 
ssfloat fRM_486_0 = {486.0,0}; /* Tpr - ����� ������ �������� ��� �� ������ ��������� */ 
ssfloat fRM_606_0 = {606.0,0}; /* Tpr - ����� ������ �������� ��� �� ������ ��������� */ 
ssfloat fRM_726_0 = {726.0,0}; /* Tpr - ����� ������ �������� ��� �� ������ ��������� */ 
ssfloat fRM_846_0 = {846.0,0}; /* Tpr - ����� ������ �������� ��� �� ������ ��������� */ 
ssfloat fRM_966_0 = {966.0,0}; /* Tpr - ����� ������ �������� ��� �� ������ ��������� */ 
ssfloat fRM_1200_0 = {1200.0,0}; /* Tpr - ����� ���������� �������� ��� �� ������ ��������� */ 
ssfloat fRM_2000_ = {2000,0}; /* Lt_bw - ����� ��������� ������ �������� �������� �����(��) */ 
ssfloat fRM_390_ = {390,0}; /* Kt - �������, ���������(�����������) ��������� ���������, �� */ 
ssfloat fRM_390_0 = {390.0,0}; /* Kt - �������, ���������(�����������) ��������� ���������, �� */ 
ssfloat fRM_1000_ = {1000,0}; /* Lt_fw - ����� ��������� ������ �������� �������� �����(��) */ 
ssfloat fRM_210_0 = {210.0,0}; /* ����� �������� ������� ��� ����� ������ (���) */ 
ssfloat fRM_100_0001 = {100.0001,0}; /* X2 */ 
ssfloat fRM_0_0001 = {0.0001,0}; /* X1 */ 
ssfloat fRM_100_0 = {100.0,0}; /* x1 - ������ ������� �������� */ 
ssfloat fRM_160_0001 = {160.0001,0}; /* X2 */ 
ssfloat fRM_160_00001 = {160.00001,0}; /* X2 */ 
ssfloat fRM_389_99 = {389.99,0}; /* X1 */ 
ssfloat fRM_1500_0001 = {1500.0001,0}; /* X2 */ 
ssint iRM_47_ = {47,0}; /* n - N-����������� ������� ������� ���������� */ 
ssfloat fRM_3_ = {3,0}; /* tz - ����� �������� ��� */ 
ssfloat fRM_55_0 = {55.0,0}; /* X1 */ 
ssfloat fRM_1_0 = {1.0,0}; /* tz - ������ ��������, sek */ 
ssfloat fRM_1_ = {1,0}; /*  */ 

uspaint8 SpaEEPROMBuf[791];

/* ����������� ���������� */
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
ssint var15;
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
ssbool var133;
ssbool var134;
ssbool var135;
ssbool var136;
ssbool var137;
ssbool var138;
ssbool var139;
ssbool var140;
ssint var141;
ssbool var142;
ssbool var143;
ssint var144;
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
ssbool var175;
ssbool var176;
ssbool var177;
ssbool var178;
ssbool var179;
ssbool var180;
ssbool var181;
ssbool var182;
ssbool var183;
ssbool var184;
ssbool var185;
ssbool var186;
ssbool var187;
ssbool var188;
ssfloat var189;
ssbool var190;
ssbool var191;
ssbool var192;
ssbool var193;
ssbool var194;
ssbool var195;
ssbool var196;
ssbool var197;
ssbool var198;
ssfloat var199;
ssfloat var200;
ssbool var201;
ssbool var202;
ssbool var203;
ssfloat var204;
ssfloat var205;
ssbool var206;
ssbool var207;
ssfloat var208;
ssbool var209;
ssbool var210;
ssbool var211;
ssbool var212;
ssbool var213;
ssbool var214;
ssbool var215;
ssbool var216;
ssfloat var217;
ssfloat var218;
ssfloat var219;
ssfloat var220;
ssbool var221;
ssfloat var222;
ssfloat var223;
ssint var224;
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
ssbool var297;
ssbool var298;
ssbool var299;
ssbool var300;
ssbool var301;
ssbool var302;
ssbool var303;
ssbool var304;
ssbool var305;
ssbool var306;
ssbool var307;
ssbool var308;
ssbool var309;
ssbool var310;
ssbool var311;
ssbool var312;
ssbool var313;
ssbool var314;
ssfloat var315;
ssbool var316;
ssbool var317;
ssbool var318;
ssfloat var319;
ssbool var320;
ssbool var321;
ssbool var322;
ssfloat var323;
ssbool var324;
ssbool var325;
ssbool var326;
ssfloat var327;
ssbool var328;
ssbool var329;
ssbool var330;
ssfloat var331;
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
ssfloat var428;
ssfloat var429;
ssbool var430;
ssfloat var431;
ssfloat var432;
ssbool var433;
ssfloat var434;
ssfloat var435;
ssbool var436;
ssfloat var437;
ssfloat var438;
ssbool var439;
ssbool var440;
ssfloat var441;
ssfloat var442;
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
ssbool var458;
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
sslong var572;
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
ssbool var886;
ssbool var887;
ssbool var888;
ssbool var889;
ssbool var890;
ssbool var891;
ssbool var892;
ssbool var893;
ssbool var894;
ssbool var895;
ssbool var896;
ssbool var897;
ssbool var898;
ssbool var899;
ssbool var900;
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
ssbool var956;
ssbool var957;
ssbool var958;
ssbool var959;
ssbool var960;
ssbool var961;
ssbool var962;
ssbool var963;
ssbool var964;
ssbool var965;
ssbool var966;
ssbool var967;
ssbool var968;
ssbool var969;
ssbool var970;
ssbool var971;
ssbool var972;
ssbool var973;
ssbool var974;
ssbool var975;
ssbool var976;
ssbool var977;
ssbool var978;
ssbool var979;
ssbool var980;
ssbool var981;
ssbool var982;
ssfloat var983;
ssbool var984;
ssfloat var985;
ssbool var986;
ssfloat var987;
ssbool var988;
ssbool var989;
ssbool var990;
ssbool var991;
ssfloat var992;
ssfloat var993;
ssfloat var994;
ssfloat var995;
ssfloat var996;
ssfloat var997;
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
ssbool var1022;
ssbool var1023;
ssbool var1024;
ssbool var1025;
ssbool var1026;
ssbool var1027;
ssbool var1028;
ssbool var1029;
ssbool var1030;
ssbool var1031;
ssbool var1032;
ssbool var1033;
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
ssbool var1052;
ssint var1053;
ssint var1054;
ssbool var1055;
ssbool var1056;
ssbool var1057;
ssbool var1058;
ssbool var1059;
ssbool var1060;
sslong var1061;
ssbool var1062;
ssbool var1063;
ssbool var1064;
ssint var1065;
ssbool var1066;
ssbool var1067;
ssbool var1068;
ssbool var1069;
ssbool var1070;
ssbool var1071;
ssbool var1072;
ssbool var1073;
ssbool var1074;
ssint var1075;
ssint var1076;
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
ssbool var1099;
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
sslong var1116;
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
ssfloat var1135;
ssbool var1136;
ssbool var1137;
ssbool var1138;
ssbool var1139;
ssbool var1140;
ssfloat var1141;
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
ssint var1155;
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
ssfloat var1180;
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
ssbool var1209;
ssbool var1210;
ssbool var1211;
ssbool var1212;
ssbool var1213;
ssbool var1214;
ssbool var1215;
ssbool var1216;
ssbool var1217;
ssbool var1218;
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
ssbool var1235;
ssbool var1236;
ssbool var1237;
ssbool var1238;
ssbool var1239;
ssbool var1240;
ssbool var1241;
ssbool var1242;
ssbool var1243;
ssbool var1244;
ssbool var1245;
ssbool var1246;
ssbool var1247;
ssbool var1248;
ssbool var1249;
ssbool var1250;
ssbool var1251;
ssbool var1252;
ssbool var1253;
ssbool var1254;
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
ssbool var1267;
ssbool var1268;
ssbool var1269;
ssbool var1270;
ssbool var1271;
ssbool var1272;
ssbool var1273;
ssbool var1274;
ssbool var1275;
sslong var1276;
ssbool var1277;
ssint var1278;
ssint var1279;
ssbool var1280;
ssfloat var1281;
ssfloat var1282;
ssfloat var1283;
ssbool var1284;
ssbool var1285;
ssbool var1286;
ssbool var1287;
ssbool var1288;
ssbool var1289;
ssbool var1290;
ssbool var1291;
ssbool var1292;
ssbool var1293;
ssbool var1294;
ssbool var1295;
ssbool var1296;
ssbool var1297;
ssbool var1298;
ssbool var1299;
ssint var1300;
ssbool var1301;
sschar var1302;
ssint var1303;
ssbool var1304;
ssfloat var1305;
ssbool var1306;
ssbool var1307;
ssbool var1308;
ssbool var1309;
ssbool var1310;
ssbool var1311;
ssbool var1312;
ssfloat var1313;
sschar var1314;
ssbool var1315;
ssbool var1316;
ssbool var1317;
ssbool var1318;
ssfloat var1319;
ssbool var1320;
ssbool var1321;
ssbool var1322;
ssbool var1323;
ssbool var1324;
ssbool var1325;
ssbool var1326;
ssbool var1327;
ssbool var1328;
ssbool var1329;
ssbool var1330;
ssbool var1331;
ssint var1332;
ssbool var1333;
sschar var1334;
ssint var1335;
ssbool var1336;
ssfloat var1337;
ssbool var1338;
ssbool var1339;
ssbool var1340;
ssbool var1341;
ssbool var1342;
ssbool var1343;
ssbool var1344;
ssfloat var1345;
sschar var1346;
ssbool var1347;
ssbool var1348;
ssbool var1349;
ssbool var1350;
ssfloat var1351;
ssbool var1352;
ssbool var1353;
ssbool var1354;
ssbool var1355;
ssbool var1356;
ssbool var1357;
ssbool var1358;
ssbool var1359;
ssbool var1360;
ssint var1361;
ssbool var1362;
sschar var1363;
ssint var1364;
ssbool var1365;
ssfloat var1366;
ssbool var1367;
ssbool var1368;
ssbool var1369;
ssbool var1370;
ssbool var1371;
ssbool var1372;
ssbool var1373;
ssfloat var1374;
sschar var1375;
ssbool var1376;
ssbool var1377;
ssbool var1378;
ssbool var1379;
ssfloat var1380;
ssbool var1381;
ssbool var1382;
ssbool var1383;
ssbool var1384;
ssbool var1385;
ssbool var1386;
ssbool var1387;
ssbool var1388;
ssbool var1389;
ssbool var1390;
ssbool var1391;
ssbool var1392;
ssbool var1393;
ssint var1394;
ssbool var1395;
sschar var1396;
ssint var1397;
ssbool var1398;
ssfloat var1399;
ssbool var1400;
ssbool var1401;
ssbool var1402;
ssbool var1403;
ssbool var1404;
ssbool var1405;
ssbool var1406;
ssfloat var1407;
sschar var1408;
ssbool var1409;
ssbool var1410;
ssfloat var1411;
ssbool var1412;
ssbool var1413;
ssbool var1414;
ssbool var1415;
ssbool var1416;
ssbool var1417;
ssbool var1418;
ssbool var1419;
ssbool var1420;
ssbool var1421;
ssbool var1422;
ssbool var1423;
ssint var1424;
ssbool var1425;
ssbool var1426;
ssbool var1427;
ssbool var1428;
ssbool var1429;
ssbool var1430;
ssbool var1431;
ssbool var1432;
ssint var1433;
ssbool var1434;
ssbool var1435;
ssbool var1436;
ssbool var1437;
ssbool var1438;
ssbool var1439;
ssbool var1440;
ssint var1441;
ssbool var1442;
sschar var1443;
ssint var1444;
ssbool var1445;
ssfloat var1446;
ssbool var1447;
ssbool var1448;
ssbool var1449;
ssbool var1450;
ssbool var1451;
ssbool var1452;
ssbool var1453;
ssfloat var1454;
sschar var1455;
ssbool var1456;
ssbool var1457;
ssfloat var1458;
ssbool var1459;
ssbool var1460;
ssbool var1461;
ssbool var1462;
ssbool var1463;
ssbool var1464;
ssbool var1465;
ssbool var1466;
sschar var1467;
ssbool var1468;
ssbool var1469;
ssbool var1470;
ssbool var1471;
ssbool var1472;
ssbool var1473;
ssbool var1474;
ssbool var1475;
ssbool var1476;
sschar var1477;
ssbool var1478;
ssbool var1479;
ssint var1480;
ssbool var1481;
sschar var1482;
ssbool var1483;
ssint var1484;
ssbool var1485;
ssbool var1486;
ssfloat var1487;
ssbool var1488;
ssbool var1489;
ssbool var1490;
ssbool var1491;
ssbool var1492;
ssbool var1493;
ssbool var1494;
ssfloat var1495;
sschar var1496;
ssbool var1497;
ssbool var1498;
ssbool var1499;
ssbool var1500;
ssfloat var1501;
ssbool var1502;
ssbool var1503;
ssbool var1504;
ssbool var1505;
ssbool var1506;
ssbool var1507;
ssbool var1508;
ssbool var1509;
ssbool var1510;
ssbool var1511;
ssbool var1512;
ssbool var1513;
ssfloat var1514;
ssbool var1515;
ssbool var1516;
ssbool var1517;
ssbool var1518;
ssbool var1519;
ssbool var1520;
ssbool var1521;
ssbool var1522;
ssbool var1523;
ssbool var1524;
ssbool var1525;
ssbool var1526;
ssbool var1527;
ssbool var1528;
ssbool var1529;
ssbool var1530;
ssfloat var1531;
ssbool var1532;
ssbool var1533;
ssbool var1534;
ssbool var1535;
ssbool var1536;
ssbool var1537;
ssbool var1538;
ssbool var1539;
ssbool var1540;
ssbool var1541;
ssbool var1542;
ssbool var1543;
ssbool var1544;
ssbool var1545;
ssbool var1546;
ssbool var1547;
ssbool var1548;
ssbool var1549;
ssbool var1550;
ssbool var1551;
ssbool var1552;
ssbool var1553;
ssbool var1554;
ssbool var1555;
ssbool var1556;
ssbool var1557;
ssbool var1558;
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
ssint var1569;
ssbool var1570;
ssbool var1571;
ssbool var1572;
ssbool var1573;
ssbool var1574;
ssbool var1575;
ssbool var1576;
ssbool var1577;
ssint var1578;
ssbool var1579;
ssbool var1580;
ssbool var1581;
ssbool var1582;
ssbool var1583;
ssbool var1584;
ssbool var1585;
ssbool var1586;
ssint var1587;
ssbool var1588;
ssbool var1589;
ssbool var1590;
ssbool var1591;
ssbool var1592;
ssbool var1593;
ssbool var1594;
ssbool var1595;
ssint var1596;
ssbool var1597;
ssbool var1598;
ssbool var1599;
ssbool var1600;
ssbool var1601;
ssbool var1602;
ssbool var1603;
ssbool var1604;
ssint var1605;
ssbool var1606;
ssbool var1607;
ssbool var1608;
ssbool var1609;
ssbool var1610;
ssbool var1611;
ssbool var1612;
ssbool var1613;
ssint var1614;
ssbool var1615;
ssbool var1616;
ssbool var1617;
ssbool var1618;
ssbool var1619;
ssbool var1620;
ssbool var1621;
ssbool var1622;
ssint var1623;
ssbool var1624;
ssbool var1625;
ssbool var1626;
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
ssbool var1654;
ssbool var1655;
ssbool var1656;
ssbool var1657;
ssbool var1658;
ssbool var1659;
ssfloat var1660;
ssbool var1661;
ssbool var1662;
ssbool var1663;
ssbool var1664;
ssbool var1665;
ssbool var1666;
ssbool var1667;
ssbool var1668;
ssbool var1669;
ssbool var1670;
ssbool var1671;
ssbool var1672;
ssbool var1673;
ssbool var1674;
ssbool var1675;
ssbool var1676;
ssbool var1677;
ssbool var1678;
ssbool var1679;
ssbool var1680;
ssbool var1681;
ssbool var1682;
ssbool var1683;
ssbool var1684;
ssbool var1685;
ssbool var1686;
ssbool var1687;
ssbool var1688;
ssbool var1689;
ssbool var1690;
ssbool var1691;
ssbool var1692;
ssbool var1693;
ssbool var1694;
ssfloat var1695;
ssfloat var1696;
ssbool var1697;
ssbool var1698;
ssbool var1699;
ssbool var1700;
ssbool var1701;
ssbool var1702;
ssbool var1703;
ssbool var1704;
ssbool var1705;
ssbool var1706;
ssbool var1707;
ssbool var1708;
ssbool var1709;
ssbool var1710;
ssbool var1711;
ssbool var1712;
ssbool var1713;
ssbool var1714;
ssbool var1715;
ssbool var1716;
ssbool var1717;
ssbool var1718;
ssbool var1719;
ssbool var1720;
ssbool var1721;
ssbool var1722;
ssfloat var1723;
ssbool var1724;
ssbool var1725;
ssfloat var1726;
ssbool var1727;
ssbool var1728;
ssfloat var1729;
ssbool var1730;
ssbool var1731;
ssfloat var1732;
ssbool var1733;
ssbool var1734;
ssfloat var1735;
ssbool var1736;
ssbool var1737;
ssfloat var1738;
ssbool var1739;
ssbool var1740;
ssfloat var1741;
ssbool var1742;
ssbool var1743;
ssbool var1744;
ssfloat var1745;
ssbool var1746;
ssbool var1747;
ssbool var1748;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* ���������� �������� */
psbool  array_m168_x_2[13] = {&R0IE02LDU,&R0IE01LDU,&R1IE01LDU,&R2IE01LDU,&A5IE02LDU,&B5IE01LDU,&A6IE01LDU,&R6IS61LDU,&R6IS67LZZ,&R6IS68LZZ,&B6IE01LDU,&A8IE01LDU,&R6IS66LZZ};
psbool  array_m150_x_2[6] = {&B3IE02LDU,&B1IE02LDU,&B2IE01LDU,&B1IE01LDU,&B3IE01LDU,&B2IE02LDU};
psbool  array_m133_x_2[6] = {&A1IE02LDU,&A2IE02LDU,&A1IE01LDU,&A2IE01LDU,&A3IE01LDU,&A3IE02LDU};
psbool  array_m241_x_2[6] = {&var1707,&var1699,&var1713,&B0VT71LZ1,&B0VT71LZ2,&var1658};
psbool  array_m230_x_2[6] = {&var1708,&var1701,&var1714,&A0VT71LZ1,&A0VT71LZ2,&var1658};
psbool  array_m253_x_2[6] = {&var1692,&B0VP71LZ1,&B0VP71LZ2,&var1663,&var1662,&var1661};
psbool  array_m232_x_2[6] = {&var1693,&A0VP71LZ1,&A0VP71LZ2,&var1666,&var1665,&var1664};
psbool  array_m124_x_2[8] = {&var1725,&var1747,&var1743,&var1740,&var1737,&var1734,&var1728,&var1731};
psbool  array_m2299_x_1[6] = {&var12,&var11,&R0DE36LDU,&R0DE37LDU,&R0DE38LDU,&R0DE39LDU};
psint  array_m2283_x_1[12] = {&R0DE0DLDU,&R0DE0FLDU,&R0DE02LDU,&R0DE03LDU,&R0DE04LDU,&R0DE05LDU,&R0DE07LDU,&R0DE08LDU,&R0DE09LDU,&R0DE0ALDU,&R0DE0BLDU,&R0DE0CLDU};
psbool  array_m797_x_1[6] = {&var603,&var1239,&var1215,&var1204,&var1008,&var91};
psbool  array_m1186_x_1[6] = {&var602,&var1219,&var18,&var1241,&var1008,&var111};
psbool  array_m588_x_1[6] = {&var798,&var1107,&var1526,&var1068,&var1485,&var1101};
psbool  array_m587_x_1[6] = {&var798,&var1108,&var1526,&var1068,&var1485,&var1100};
psfloat  array_m2191_a_1[6] = {&fEM_R0UN70LDU,&fEM_R0UN71LDU,&fEM_R0UN72LDU,&fEM_R0UN73LDU,&fEM_R0UN74LDU,&fEM_R0UN75LDU};
psfloat  array_m2191_b_1[6] = {&fEM_R0UN80LDU,&fEM_R0UN81LDU,&fEM_R0UN82LDU,&fEM_R0UN83LDU,&fEM_R0UN84LDU,&fEM_R0UN85LDU};
psfloat  array_m2202_x_1[4] = {&B0CT01IZ1,&A0CT01IZ1,&B0CT01IZ2,&A0CT01IZ2};
psfloat  array_m2225_x_1[2] = {&R0VN09RZ1,&R0VN09RZ2};
psbool  array_m2194_x_1[14] = {&var203,&var176,&var832,&var237,&var239,&var174,&var1648,&var1228,&var1226,&var1659,&var202,&var191,&var187,&var211};
psbool  array_m1_x_1[47] = {&var1191,&lRM_0_,&var336,&var66,&var486,&var1395,&var721,&R0MD34LP1,&var635,&R0MD34LP1,&var694,&R0MD34LP1,&var928,&R0MD34LP1,&var748,&R0MD34LP1,&var926,&var1422,&A2IS12LDU,&var393,&var1222,&var1115,&var1113,&var1026,&var841,&R0MD34LP1,&var423,&var464,&var1266,&var1576,&R0MD34LP1,&var579,&var570,&var525,&B3IS35LDU,&B3IS35LDU,&var258,&var64,&var497,&var305,&var1627,&var1585,&var1612,&var947,&var1599,&R2IS21LDU,&var177};
psfloat  array_m1456_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psbool  array_m1410_x_1[5] = {&var579,&var578,&var577,&var576,&var575};
psbool  array_m546_x_1[14] = {&var746,&var752,&var753,&var744,&var745,&var930,&var931,&var911,&var910,&var742,&var740,&var748,&var741,&var231};
psfloat  array_m82_x_1[2] = {&R0VN11RZ2,&R0VN11RZ1};
psfloat  array_m84_x_1[8] = {&fEM_R0UN01RDU,&fEM_R0UN02RDU,&fEM_R0UN03RDU,&fEM_R0UN04RDU,&fEM_R0UN05RDU,&fEM_R0UN06RDU,&fEM_R0UN07RDU,&fEM_R0UN08RDU};
psfloat  array_m1060_x_1[2] = {&R0VN11RZ2,&R0VN11RZ1};
psfloat  array_m1196_x_1[8] = {&var1487,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m807_x_1[8] = {&var1446,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m891_x_1[8] = {&var1337,&var200,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m1297_x_1[8] = {&var1305,&var199,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m488_x_1[8] = {&var1366,&var327,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m164_x_1[8] = {&var1399,&var331,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m326_Tpr_1[10] = {&fRM_6_0,&fRM_126_0,&fRM_246_0,&fRM_366_0,&fRM_486_0,&fRM_606_0,&fRM_726_0,&fRM_846_0,&fRM_966_0,&fRM_1200_0};
pschar  array_m326_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m326_rz_1[10];
psbool  array_m330_x_1[5] = {&var1056,&var1057,&var1058,&var1059,&var1060};
psbool  array_m264_x_1[7] = {&var832,&var233,&var1035,&var1032,&var239,&var237,&var235};
psfloat  array_m268_Tpr_1[10] = {&fRM_10_0,&fRM_30_0,&fRM_50_0,&fRM_70_0,&fRM_90_0,&fRM_110_0,&fRM_130_0,&fRM_150_0,&fRM_170_0,&fRM_200_0};
pschar  array_m268_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m268_rz_1[10];
psfloat  array_m1399_Tpr_1[6] = {&fRM_0_5,&fRM_3_5,&fRM_6_5,&fRM_9_5,&fRM_12_5,&fRM_15_5};
pschar  array_m1399_type_1[6] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_6_};
pschar  array_m1399_rz_1[6];
psbool  array_m284_x_1[5] = {&var1078,&var1079,&var1080,&var1081,&var1082};
psbool  array_m1171_x_1[5] = {&var1203,&var815,&var1558,&var1208,&var249};
psbool  array_m1158_x_1[4] = {&var1112,&var1154,&var1028,&var1206};
psfloat  array_m1440_x_1[16] = {&var428,&var437,&fRM_0_,&var434,&fRM_0_,&fRM_0_,&fRM_0_,&var431,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&var441};
psbool  array_m1758_x_1[17] = {&var508,&var509,&var515,&var510,&var506,&var507,&var965,&var511,&var512,&var1255,&var513,&var514,&var1247,&var1248,&var1257,&var243,&var244};
psbool  array_m1402_x_1[5] = {&var420,&var543,&var560,&var561,&var450};
psint  array_m303_x_1[3] = {&var1054,&iRM_0_,&var1076};
psint  array_m294_x_1[3] = {&var1053,&iRM_0_,&var1075};
psbool  array_m590_x_1[5] = {&var781,&var1525,&var1292,&var1009,&var209};
psbool  array_m1361_x_1[8] = {&var665,&var666,&var667,&var662,&var661,&var660,&var926,&var658};
psbool  array_m1296_x_1[3] = {&var93,&lRM_0_,&var92};
psfloat  array_m1298_Lt_fw_1[1] = {&fEM_A3UC81RDU};
psint  array_m1298_Vr_fw_1[1] = {&iEM_A3UV01IDU};
psfloat  array_m1298_Lt_bw_1[1] = {&fEM_A3UC82RDU};
psint  array_m1298_Vr_bw_1[1] = {&iEM_A3UV02IDU};
psfloat  array_m1326_x0_1[60];
psfloat  array_m1326_tim0_1[60];
psbool  array_m960_x_1[8] = {&var680,&var682,&var683,&var675,&var681,&var677,&var928,&var409};
psbool  array_m890_x_1[3] = {&var119,&lRM_0_,&var114};
psfloat  array_m892_Lt_fw_1[1] = {&fEM_A3UC81RDU};
psint  array_m892_Vr_fw_1[1] = {&iEM_A3UV01IDU};
psfloat  array_m892_Lt_bw_1[1] = {&fEM_A3UC82RDU};
psint  array_m892_Vr_bw_1[1] = {&iEM_A3UV02IDU};
psfloat  array_m925_x0_1[60];
psfloat  array_m925_tim0_1[60];
psbool  array_m487_x_1[3] = {&var757,&lRM_0_,&var758};
psfloat  array_m490_Lt_fw_1[2] = {&fEM_A1UC81RDU,&fEM_A1UC82RDU};
psint  array_m490_Vr_fw_1[2] = {&iEM_A1UV01IDU,&iEM_A1UV02IDU};
psfloat  array_m490_Lt_bw_1[1] = {&fEM_A1UC83RDU};
psint  array_m490_Vr_bw_1[1] = {&iEM_A1UV03IDU};
psfloat  array_m517_x0_1[150];
psfloat  array_m517_tim0_1[150];
psbool  array_m228_x_1[12] = {&var726,&var728,&var727,&var724,&var722,&var721,&var720,&var934,&var933,&var715,&var718,&var232};
psbool  array_m163_x_1[3] = {&var904,&lRM_0_,&var905};
psfloat  array_m168_Lt_fw_1[2] = {&fEM_A1UC81RDU,&fEM_A1UC82RDU};
psint  array_m168_Vr_fw_1[2] = {&iEM_A1UV01IDU,&iEM_A1UV02IDU};
psfloat  array_m168_Lt_bw_1[1] = {&fEM_A1UC83RDU};
psint  array_m168_Vr_bw_1[1] = {&iEM_A1UV03IDU};
psfloat  array_m197_x0_1[150];
psfloat  array_m197_tim0_1[150];
psbool  array_m865_x_1[10] = {&var692,&var693,&var699,&var700,&var698,&var696,&var695,&var936,&var935,&var694};
psbool  array_m806_x_1[3] = {&var95,&var710,&var94};
psfloat  array_m808_Lt_fw_1[2] = {&fEM_A2UC81RDU,&fEM_A2UC82RDU};
psint  array_m808_Vr_fw_1[2] = {&iEM_A2UV01IDU,&iEM_A2UV02IDU};
psfloat  array_m808_Lt_bw_1[1] = {&fEM_A2UC83RDU};
psint  array_m808_Vr_bw_1[1] = {&iEM_A2UV03CDU};
psfloat  array_m831_x0_1[80];
psfloat  array_m831_tim0_1[80];
psfloat  array_m1580_Lt_fw_1[1] = {&fRM_1000_};
psint  array_m1580_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1580_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1580_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1271_x_1[10] = {&var631,&var632,&var634,&var633,&var635,&var637,&var639,&var636,&var638,&var640};
psbool  array_m146_x_1[5] = {&A1IS21LDU,&A3IS21LDU,&A2IS21LDU,&var951,&var950};
psfloat  array_m1113_Lt_fw_1[1] = {&fRM_2000_};
psint  array_m1113_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1113_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1113_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1195_x_1[3] = {&var123,&var625,&var110};
psfloat  array_m1197_Lt_fw_1[2] = {&fEM_A2UC81RDU,&fEM_A2UC82RDU};
psint  array_m1197_Vr_fw_1[2] = {&iEM_A2UV01IDU,&iEM_A2UV02IDU};
psfloat  array_m1197_Lt_bw_1[1] = {&fEM_A2UC83RDU};
psint  array_m1197_Vr_bw_1[1] = {&iEM_A2UV03CDU};
psfloat  array_m1230_x0_1[80];
psfloat  array_m1230_tim0_1[80];
psfloat  array_m1600_x0_1[20];
psfloat  array_m1600_tim0_1[20];
psbool  array_m1083_x_1[8] = {&var842,&var839,&var840,&var841,&var838,&var837,&var836,&var835};
psbool  array_m591_x_1[18] = {&R0MD31LP1,&var533,&var856,&var535,&var854,&var626,&var761,&var709,&var736,&var756,&var685,&var650,&var912,&var348,&var347,&var616,&var265,&var201};
psfloat  array_m1136_x0_1[20];
psfloat  array_m1136_tim0_1[20];
psbool  array_m431_x_1[7] = {&var957,&var956,&var955,&var954,&var1629,&var946,&var377};
psbool  array_m413_x_1[7] = {&var959,&var1629,&var947,&var960,&var958,&var945,&var147};
psbool  array_m761_x_1[17] = {&var857,&var902,&var901,&var898,&var897,&var894,&var859,&var896,&var864,&var893,&var889,&var891,&var890,&var861,&var855,&var944,&var712};
psbool  array_m132_x_1[21] = {&var735,&var755,&var4,&var6,&var999,&var998,&var1563,&var1572,&var1590,&var1581,&var1617,&var1608,&var486,&var378,&var990,&var991,&var1269,&var1263,&var1427,&var1418,&var1599};

/* ���������� �������� */
_S_and4  S_and4_108_2 = {&var1744,&var1679,&B8IS11LDU,&B8IS12LDU,&var1649};
_S_lkb  S_lkb_112_2 = {&lRM_1_,&var1677,&var1650};
_S_lkb  S_lkb_109_2 = {&lRM_1_,&var1649,&var1651};
_S_lkb  S_lkb_78_2 = {&lRM_1_,&var1680,&var1652};
_S_lkb  S_lkb_52_2 = {&lRM_1_,&var1685,&var1653};
_S_lkb  S_lkb_82_2 = {&lRM_1_,&var1683,&var1654};
_S_lkb  S_lkb_49_2 = {&lRM_1_,&var1689,&var1655};
_S_lkb  S_lkb_24_2 = {&lRM_1_,&var1687,&var1656};
_S_lkb  S_lkb_21_2 = {&lRM_1_,&var1691,&var1657};
_S_or2  S_or2_256_2 = {&var1748,&var1697,&var1658};
_S_bol  S_bol_221_2 = {&fRM_0_5,&var1660,&var1659};
_S_fsumo  S_fsumo_220_2 = {&var1696,&var1695,&var1660};
_S_noto  S_noto_249_2 = {&B3VP81LDU,&var1661};
_S_noto  S_noto_248_2 = {&B2VP82LDU,&var1662};
_S_noto  S_noto_247_2 = {&B4VP82LDU,&var1663};
_S_noto  S_noto_229_2 = {&A3VP81LDU,&var1664};
_S_noto  S_noto_228_2 = {&A2VP82LDU,&var1665};
_S_noto  S_noto_227_2 = {&A4VP82LDU,&var1666};
_S_schl24  S_schl24_149_2 = {&A0EE02LZ1,&A0EE03LZ1,&A0EE01LZ1,&A0EE04LZ1,&var1667};
_S_schl24  S_schl24_143_2 = {&A0EE03LZ2,&A0EE01LZ2,&A0EE02LZ2,&A0EE04LZ2,&var1668};
_S_or2  S_or2_195_2 = {&var1717,&var1718,&var1669};
_S_or2  S_or2_191_2 = {&var1720,&var1721,&var1670};
_S_and2  S_and2_210_2 = {&var1705,&var1716,&var1671};
_S_or2  S_or2_242_2 = {&var1712,&var1711,&var1672};
_S_and4  S_and4_159_2 = {&A0EE02LZ1,&A0EE04LZ1,&A0EE02LZ2,&A0EE04LZ2,&var1673};
_S_or3  S_or3_158_2 = {&var1673,&var820,&var1667,&var1674};
_S_and4  S_and4_136_2 = {&A0EE03LZ1,&A0EE01LZ1,&A0EE01LZ2,&A0EE03LZ2,&var1675};
_S_or3  S_or3_135_2 = {&var1675,&var1668,&var820,&var1676};
_S_and3  S_and3_111_2 = {&var1678,&var1744,&A8IS12LDU,&var1677};
_S_or2  S_or2_104_2 = {&A8MC01LC2,&A8MC01LC1,&var1678};
_S_or2  S_or2_103_2 = {&B8MC01LC2,&B8MC01LC1,&var1679};
_S_and3  S_and3_77_2 = {&var1744,&B3IS11LDU,&var1681,&var1680};
_S_or2  S_or2_71_2 = {&B3MC01LC2,&B3MC01LC1,&var1681};
_S_or2  S_or2_74_2 = {&A3MC01LC2,&A3MC01LC1,&var1682};
_S_and3  S_and3_81_2 = {&var1744,&var1682,&A3IS11LDU,&var1683};
_S_or2  S_or2_43_2 = {&A2MC01LC2,&A2MC01LC1,&var1684};
_S_and3  S_and3_51_2 = {&var1744,&A2IS11LDU,&var1684,&var1685};
_S_or2  S_or2_13_2 = {&A1MC01LC2,&A1MC01LC1,&var1686};
_S_and3  S_and3_23_2 = {&var1686,&var1744,&A1IS11LDU,&var1687};
_S_or2  S_or2_42_2 = {&B2MC01LC1,&B2MC01LC2,&var1688};
_S_and3  S_and3_48_2 = {&var1744,&B2IS11LDU,&var1688,&var1689};
_S_or2  S_or2_11_2 = {&B1MC01LC2,&B1MC01LC1,&var1690};
_S_and3  S_and3_20_2 = {&var1744,&B1IS11LDU,&var1690,&var1691};
_S_and2  S_and2_252_2 = {&var401,&var1669,&var1692};
_S_and2  S_and2_231_2 = {&var401,&var1670,&var1693};
_S_and2  S_and2_217_2 = {&var1706,&var1715,&var1694};
_S_scalzz  S_scalzz_182_2 = {&B3IP02IDU,&iRM_3276_,&iRM_16383_,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&var1695,&internal2_m182_y0};
_S_scalzz  S_scalzz_180_2 = {&A3IP02IDU,&iRM_3276_,&iRM_16383_,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&var1696,&internal2_m180_y0};
_S_noto  S_noto_169_2 = {&var1698,&var1697};
_S_andn  S_andn_168_2 = {array_m168_x_2,&iRM_13_,&var1698};
_S_noto  S_noto_153_2 = {&var1700,&var1699};
_S_andn  S_andn_150_2 = {array_m150_x_2,&iRM_6_,&var1700};
_S_noto  S_noto_134_2 = {&var1702,&var1701};
_S_andn  S_andn_133_2 = {array_m133_x_2,&iRM_6_,&var1702};
_S_noto  S_noto_251_2 = {&var1711,&var1703};
_S_noto  S_noto_233_2 = {&var1712,&var1704};
_S_noto  S_noto_209_2 = {&var1720,&var1705};
_S_noto  S_noto_218_2 = {&var1717,&var1706};
_S_noto  S_noto_157_2 = {&var1674,&var1707};
_S_noto  S_noto_141_2 = {&var1676,&var1708};
_S_noto  S_noto_254_2 = {&var1713,&var1709};
_S_noto  S_noto_238_2 = {&var1714,&var1710};
_S_ornc  S_ornc_241_2 = {array_m241_x_2,&iRM_6_,&var1711,&vainSChar};
_S_ornc  S_ornc_230_2 = {array_m230_x_2,&iRM_6_,&var1712,&vainSChar};
_S_ornc  S_ornc_253_2 = {array_m253_x_2,&iRM_6_,&var1713,&vainSChar};
_S_ornc  S_ornc_232_2 = {array_m232_x_2,&iRM_6_,&var1714,&vainSChar};
_S_tprg  S_tprg_215_2 = {&var1695,&fEM_A3UP85RDU,&fEM_A3UP86RDU,&fEM_A3UP87RDU,&fEM_A3UP88RDU,&var1715,&internal2_m215_y0};
_S_tprg  S_tprg_207_2 = {&var1696,&fEM_A3UP85RDU,&fEM_A3UP86RDU,&fEM_A3UP87RDU,&fEM_A3UP88RDU,&var1716,&internal2_m207_y0};
_S_geterr  S_geterr_187_2 = {&var1695,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var1717};
_S_drg  S_drg_196_2 = {&var1695,&lRM_1_,&lRM_0_,&fEM_A3UP43RDU,&fEM_A3UP44RDU,&var1718,&internal2_m196_y1};
_S_drg  S_drg_203_2 = {&var1695,&lRM_1_,&lRM_0_,&fEM_A3UP53RDU,&fEM_A3UP54RDU,&var1719,&internal2_m203_y1};
_S_geterr  S_geterr_184_2 = {&var1696,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var1720};
_S_drg  S_drg_185_2 = {&var1696,&lRM_1_,&lRM_0_,&fEM_A3UP43RDU,&fEM_A3UP44RDU,&var1721,&internal2_m185_y1};
_S_drg  S_drg_193_2 = {&var1696,&lRM_1_,&lRM_0_,&fEM_A3UP53RDU,&fEM_A3UP54RDU,&var1722,&internal2_m193_y1};
_S_enctkb  S_enctkb_17_2 = {&var1656,&fRM_0_0,&A1IC01UDU,&dEM_A1UC06UDU,&dEM_A1UC05UDU,&fEM_A1UC03RDU,&fRM_100_,&dRM_0_,&var1723,&var1724,&var1725,&internal2_m17_Nk0,&internal2_m17_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_110_2 = {&var1651,&fRM_390_,&B8IC01UDU,&dEM_A8UC06UDU,&dEM_A8UC05UDU,&fEM_A8UC03RDU,&fRM_1500_0,&dRM_0_,&var1726,&var1727,&var1728,&internal2_m110_Nk0,&internal2_m110_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_106_2 = {&var1650,&fRM_390_0,&A8IC01UDU,&dEM_A8UC06UDU,&dEM_A8UC05UDU,&fEM_A8UC03RDU,&fRM_1500_0,&dRM_0_,&var1729,&var1730,&var1731,&internal2_m106_Nk0,&internal2_m106_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_79_2 = {&var1652,&fRM_0_,&B3IC01UDU,&dEM_A3UC06UDU,&dEM_A3UC05UDU,&fEM_A3UC03RDU,&fRM_0_0,&dRM_0_,&var1732,&var1733,&var1734,&internal2_m79_Nk0,&internal2_m79_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_83_2 = {&var1654,&fRM_0_0,&A3IC01UDU,&dEM_A3UC06UDU,&dEM_A3UC05UDU,&fEM_A3UC03RDU,&fRM_0_0,&dRM_0_,&var1735,&var1736,&var1737,&internal2_m83_Nk0,&internal2_m83_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_45_2 = {&var1655,&fRM_0_0,&B2IC01UDU,&dEM_A2UC06UDU,&dEM_A2UC05UDU,&fEM_A2UC03RDU,&fRM_100_,&dRM_0_,&var1738,&var1739,&var1740,&internal2_m45_Nk0,&internal2_m45_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_53_2 = {&var1653,&fRM_0_0,&A2IC01UDU,&dEM_A2UC06UDU,&dEM_A2UC05UDU,&fEM_A2UC03RDU,&fRM_100_,&dRM_0_,&var1741,&var1742,&var1743,&internal2_m53_Nk0,&internal2_m53_SetFlag,&bFirstEnterFlag};
_S_equz_p  S_equz_p_19_2 = {&R0MW12IP1,&iRM_4_,&var1744};
_S_enctkb  S_enctkb_15_2 = {&var1657,&fRM_0_0,&B1IC01UDU,&dEM_A1UC06UDU,&dEM_A1UC05UDU,&fEM_A1UC03RDU,&fRM_100_,&dRM_0_,&var1745,&var1746,&var1747,&internal2_m15_Nk0,&internal2_m15_SetFlag,&bFirstEnterFlag};
_S_ornc  S_ornc_124_2 = {array_m124_x_2,&iRM_8_,&var1748,&vainSChar};
_S_ovbsb  S_ovbsb_1236_1 = {&var1503,&fRM_1_,&var1,&internal1_m1236_tx};
_S_ovbsb  S_ovbsb_1217_1 = {&var1498,&fRM_1_,&var2,&internal1_m1217_tx};
_S_ovbsb  S_ovbsb_1218_1 = {&var1497,&fRM_1_,&var3,&internal1_m1218_tx};
_S_ovbsb  S_ovbsb_1239_1 = {&var1000,&fRM_1_,&var4,&internal1_m1239_tx};
_S_ovbsb  S_ovbsb_824_1 = {&var1460,&fRM_1_,&var5,&internal1_m824_tx};
_S_ovbsb  S_ovbsb_832_1 = {&var708,&fRM_1_,&var6,&internal1_m832_tx};
_S_ovbsb  S_ovbsb_823_1 = {&var707,&fRM_1_,&var7,&internal1_m823_tx};
_S_ovbsb  S_ovbsb_822_1 = {&var706,&fRM_1_,&var8,&internal1_m822_tx};
_S_or3  S_or3_2300_1 = {&var10,&var13,&var14,&var9};
_S_orn  S_orn_2299_1 = {array_m2299_x_1,&iRM_6_,&var10};
_S_or2  S_or2_2304_1 = {&R0DEB3LDU,&R0DEB4LDU,&var11};
_S_or2  S_or2_2297_1 = {&R0DEB1LDU,&R0DEB2LDU,&var12};
_S_and2  S_and2_2288_1 = {&R0DE31LDU,&R0DE32LDU,&var13};
_S_diagndev  S_diagndev_2283_1 = {array_m2283_x_1,&iRM_12_,&var14,&var15};
_S_or2  S_or2_1684_1 = {&var251,&var64,&var16};
_S_and2  S_and2_1674_1 = {&var307,&var1212,&var17};
_S_rs  S_rs_1683_1 = {&var16,&var17,&var18,&vainSBool,&internal1_m1683_q0};
_S_or2  S_or2_1678_1 = {&var307,&var254,&var19};
_S_or2  S_or2_1621_1 = {&var1262,&var307,&var20};
_S_or2  S_or2_1649_1 = {&var306,&var64,&var21};
_S_or2  S_or2_1651_1 = {&var134,&var64,&var22};
_S_or2  S_or2_2123_1 = {&var251,&var60,&var23};
_S_or2  S_or2_2121_1 = {&var60,&var258,&var24};
_S_or2  S_or2_2119_1 = {&var73,&var60,&var25};
_S_and2  S_and2_2102_1 = {&var1209,&var305,&var26};
_S_or2  S_or2_2117_1 = {&var305,&var60,&var27};
_S_noto  S_noto_2125_1 = {&B3IS11LDU,&var28};
_S_or2  S_or2_2152_1 = {&var64,&var258,&var29};
_S_and2  S_and2_2132_1 = {&var1209,&var306,&var30};
_S_noto  S_noto_2156_1 = {&A3IS11LDU,&var31};
_S_or2  S_or2_2154_1 = {&var251,&var64,&var32};
_S_or2  S_or2_2150_1 = {&var64,&var74,&var33};
_S_or2  S_or2_2148_1 = {&var64,&var306,&var34};
_S_or2  S_or2_1629_1 = {&var251,&var64,&var35};
_S_or2  S_or2_1633_1 = {&var251,&var60,&var36};
_S_or2  S_or2_1624_1 = {&var307,&var1262,&var37};
_S_or2  S_or2_1659_1 = {&var60,&var133,&var38};
_S_or2  S_or2_1657_1 = {&var305,&var60,&var39};
_S_or2  S_or2_1700_1 = {&var258,&var60,&var40};
_S_or2  S_or2_1697_1 = {&var258,&var64,&var41};
_S_or2  S_or2_1729_1 = {&var264,&var60,&var42};
_S_or2  S_or2_1726_1 = {&var264,&var64,&var43};
_S_or2  S_or2_1686_1 = {&var251,&var60,&var44};
_S_or2  S_or2_1653_1 = {&var251,&var64,&var45};
_S_or2  S_or2_1661_1 = {&var251,&var60,&var46};
_S_or3  S_or3_2113_1 = {&var258,&var305,&var60,&var47};
_S_or3  S_or3_2115_1 = {&var308,&var305,&var60,&var48};
_S_or3  S_or3_2146_1 = {&var64,&var309,&var306,&var49};
_S_or3  S_or3_2144_1 = {&var258,&var64,&var306,&var50};
_S_or3  S_or3_2111_1 = {&var305,&var251,&var60,&var51};
_S_or3  S_or3_2142_1 = {&var251,&var306,&var64,&var52};
_S_or3  S_or3_1627_1 = {&var251,&var306,&var64,&var53};
_S_or3  S_or3_1631_1 = {&var305,&var251,&var60,&var54};
_S_or3  S_or3_1647_1 = {&var251,&var306,&var64,&var55};
_S_or3  S_or3_1655_1 = {&var251,&var305,&var60,&var56};
_S_or3  S_or3_1682_1 = {&var251,&var307,&var60,&var57};
_S_or3  S_or3_1680_1 = {&var251,&var64,&var307,&var58};
_S_or3  S_or3_1728_1 = {&var60,&var305,&var264,&var59};
_S_noto  S_noto_1723_1 = {&var917,&var60};
_S_or3  S_or3_1699_1 = {&var60,&var258,&var305,&var61};
_S_or3  S_or3_1696_1 = {&var258,&var64,&var306,&var62};
_S_or3  S_or3_1725_1 = {&var264,&var64,&var306,&var63};
_S_noto  S_noto_1722_1 = {&var916,&var64};
_S_regch  S_regch_125_1 = {&R0MW12IP1,&var906,&var65};
_S_or2  S_or2_128_1 = {&var67,&var65,&var66};
_S_or2  S_or2_127_1 = {&R0VZ71LZ1,&R0VZ71LZ2,&var67};
_S_and3  S_and3_1394_1 = {&R0MD11LP2,&var965,&var71,&var68};
_S_and2  S_and2_724_1 = {&R4MD21LP2,&var71,&var69};
_S_and2  S_and2_721_1 = {&R4MD11LP2,&var71,&var70};
_S_noto  S_noto_107_1 = {&var1639,&var71};
_S_and2  S_and2_105_1 = {&R0MD11LP1,&var71,&var72};
_S_noto  S_noto_2126_1 = {&B3IS22LDU,&var73};
_S_noto  S_noto_2157_1 = {&A3IS22LDU,&var74};
_S_and2  S_and2_2050_1 = {&var482,&var1191,&var75};
_S_or3  S_or3_2045_1 = {&var481,&var177,&var115,&var76};
_S_and2  S_and2_2037_1 = {&var478,&var1191,&var77};
_S_or3  S_or3_2031_1 = {&var177,&var479,&var98,&var78};
_S_or2  S_or2_1459_1 = {&var1280,&var1209,&var79};
_S_or2  S_or2_1428_1 = {&var1137,&var1209,&var80};
_S_rs  S_rs_2116_1 = {&var27,&var84,&var81,&vainSBool,&internal1_m2116_q0};
_S_rs  S_rs_2100_1 = {&var28,&var103,&var82,&vainSBool,&internal1_m2100_q0};
_S_noto  S_noto_2124_1 = {&var1719,&var83};
_S_and2  S_and2_2107_1 = {&var83,&var82,&var84};
_S_rs  S_rs_2147_1 = {&var34,&var87,&var85,&vainSBool,&internal1_m2147_q0};
_S_noto  S_noto_2155_1 = {&var1722,&var86};
_S_and2  S_and2_2138_1 = {&var88,&var86,&var87};
_S_rs  S_rs_2131_1 = {&var31,&var121,&var88,&vainSBool,&internal1_m2131_q0};
_S_and4  S_and4_1349_1 = {&var965,&var1209,&var269,&var1254,&var89};
_S_and4  S_and4_948_1 = {&var965,&var1209,&var269,&var1254,&var90};
_S_rs  S_rs_2122_1 = {&var23,&var96,&var91,&vainSBool,&internal1_m2122_q0};
_S_or4  S_or4_1286_1 = {&var601,&var291,&var1004,&var98,&var92};
_S_or4  S_or4_1295_1 = {&var166,&var294,&var777,&var104,&var93};
_S_orn  S_orn_797_1 = {array_m797_x_1,&iRM_6_,&var94};
_S_or3  S_or3_809_1 = {&var796,&var1205,&var107,&var95};
_S_and2  S_and2_2109_1 = {&var258,&var97,&var96};
_S_rs  S_rs_2103_1 = {&var23,&var99,&var97,&vainSBool,&internal1_m2103_q0};
_S_rs  S_rs_2120_1 = {&var24,&var99,&var98,&vainSBool,&internal1_m2120_q0};
_S_and2  S_and2_2108_1 = {&var100,&var73,&var99};
_S_rs  S_rs_2101_1 = {&var24,&var26,&var100,&vainSBool,&internal1_m2101_q0};
_S_rs  S_rs_2099_1 = {&var83,&var105,&var101,&vainSBool,&internal1_m2099_q0};
_S_rs  S_rs_2098_1 = {&var47,&var106,&var102,&vainSBool,&internal1_m2098_q0};
_S_and2  S_and2_2106_1 = {&var258,&var101,&var103};
_S_rs  S_rs_2112_1 = {&var47,&var105,&var104,&vainSBool,&internal1_m2112_q0};
_S_and2  S_and2_2105_1 = {&var102,&var251,&var105};
_S_and2  S_and2_2104_1 = {&var308,&var1209,&var106};
_S_rs  S_rs_2110_1 = {&var51,&var106,&var107,&vainSBool,&internal1_m2110_q0};
_S_rs  S_rs_2118_1 = {&var25,&var26,&var108,&vainSBool,&internal1_m2118_q0};
_S_rs  S_rs_2114_1 = {&var48,&var103,&var109,&vainSBool,&internal1_m2114_q0};
_S_orn  S_orn_1186_1 = {array_m1186_x_1,&iRM_6_,&var110};
_S_rs  S_rs_2153_1 = {&var32,&var112,&var111,&vainSBool,&internal1_m2153_q0};
_S_and2  S_and2_2140_1 = {&var258,&var113,&var112};
_S_rs  S_rs_2134_1 = {&var32,&var116,&var113,&vainSBool,&internal1_m2134_q0};
_S_or4  S_or4_880_1 = {&var600,&var295,&var1004,&var115,&var114};
_S_rs  S_rs_2151_1 = {&var29,&var116,&var115,&vainSBool,&internal1_m2151_q0};
_S_and2  S_and2_2139_1 = {&var117,&var74,&var116};
_S_rs  S_rs_2133_1 = {&var29,&var30,&var117,&vainSBool,&internal1_m2133_q0};
_S_rs  S_rs_2130_1 = {&var86,&var124,&var118,&vainSBool,&internal1_m2130_q0};
_S_or4  S_or4_889_1 = {&var1202,&var166,&var787,&var122,&var119};
_S_rs  S_rs_2129_1 = {&var50,&var125,&var120,&vainSBool,&internal1_m2129_q0};
_S_and2  S_and2_2137_1 = {&var258,&var118,&var121};
_S_rs  S_rs_2143_1 = {&var50,&var124,&var122,&vainSBool,&internal1_m2143_q0};
_S_or3  S_or3_1198_1 = {&var795,&var1207,&var126,&var123};
_S_and2  S_and2_2136_1 = {&var120,&var251,&var124};
_S_and2  S_and2_2135_1 = {&var309,&var1209,&var125};
_S_rs  S_rs_2141_1 = {&var52,&var125,&var126,&vainSBool,&internal1_m2141_q0};
_S_or2  S_or2_2017_1 = {&var168,&var1036,&var127};
_S_ovbs  S_ovbs_2019_1 = {&var227,&fRM_2_0,&var128,&internal1_m2019_tx};
_S_or2  S_or2_2020_1 = {&var1218,&var128,&var129};
_S_ovbs  S_ovbs_1998_1 = {&var228,&fRM_2_0,&var130,&internal1_m1998_tx};
_S_or2  S_or2_1996_1 = {&var169,&var1037,&var131};
_S_or2  S_or2_1999_1 = {&var1238,&var130,&var132};
_S_noto  S_noto_1663_1 = {&B2IS21LDU,&var133};
_S_noto  S_noto_1662_1 = {&A2IS21LDU,&var134};
_S_and2  S_and2_2070_1 = {&var1719,&var483,&var135};
_S_or5  S_or5_2073_1 = {&var658,&var1648,&var152,&var108,&var135,&var136};
_S_or5  S_or5_2072_1 = {&var409,&var1200,&var485,&var1648,&var138,&var137};
_S_and2  S_and2_2047_1 = {&var1722,&var484,&var138};
_S_nocnm  S_nocnm_1707_1 = {&R5IS21LDU,&R5IS11LDU,&var139,&var140,&var141,&internal1_m1707_Pv0,&internal1_m1707_Zv0,&internal1_m1707_MyFirstEnterFlag,&bFirstEnterFlag};
_S_nocnm  S_nocnm_1704_1 = {&R3IS11LDU,&R3IS21LDU,&var142,&var143,&var144,&internal1_m1704_Pv0,&internal1_m1704_Zv0,&internal1_m1704_MyFirstEnterFlag,&bFirstEnterFlag};
_S_or5  S_or5_1967_1 = {&var4,&var6,&C2MD31LP1,&var999,&var998,&var145};
_S_or4  S_or4_1943_1 = {&C1MD31LP2,&C1MD31LP1,&var735,&var755,&var146};
_S_and3  S_and3_409_1 = {&B8IS22LDU,&B8IS21LDU,&var1621,&var147};
_S_and2  S_and2_2035_1 = {&var477,&var177,&var148};
_S_and2  S_and2_2044_1 = {&var480,&var177,&var149};
_S_or4  S_or4_980_1 = {&var1327,&var670,&var669,&var672,&var150};
_S_or4  S_or4_1381_1 = {&var1295,&var651,&var652,&var655,&var151};
_S_and2  S_and2_2074_1 = {&var398,&var1191,&var152};
_S_and2  S_and2_2059_1 = {&var483,&var1648,&var153};
_S_and2  S_and2_2048_1 = {&var484,&var1648,&var154};
_S_or2  S_or2_548_1 = {&B1VP41LZ2,&B1VP41LZ1,&var155};
_S_or2  S_or2_230_1 = {&A1VP41LZ2,&A1VP41LZ1,&var156};
_S_or2  S_or2_1112_1 = {&B8IS22LDU,&B8IS21LDU,&var157};
_S_or2  S_or2_1109_1 = {&B8IS11LDU,&B8IS12LDU,&var158};
_S_or2  S_or2_350_1 = {&R4IS11LDU,&R4IS12LDU,&var159};
_S_or2  S_or2_367_1 = {&R4IS21LDU,&R4IS22LDU,&var160};
_S_or2  S_or2_1068_1 = {&var1007,&R0MD34LP1,&var161};
_S_or2  S_or2_1071_1 = {&var1005,&R0MD34LP1,&var162};
_S_or2  S_or2_1074_1 = {&var1003,&R0MD34LP1,&var163};
_S_or2  S_or2_1077_1 = {&var1001,&R0MD34LP1,&var164};
_S_noto  S_noto_2182_1 = {&var1648,&var165};
_S_zzfs  S_zzfs_2172_1 = {&var183,&fRM_0_5,&var166,&internal1_m2172_tx,&internal1_m2172_y0};
_S_or2  S_or2_2205_1 = {&var359,&var1009,&var167};
_S_andn  S_andn_588_1 = {array_m588_x_1,&iRM_6_,&var168};
_S_andn  S_andn_587_1 = {array_m587_x_1,&iRM_6_,&var169};
_S_or2  S_or2_2221_1 = {&var685,&var650,&var170};
_S_noto  S_noto_2167_1 = {&var1035,&var171};
_S_noto  S_noto_2166_1 = {&var1032,&var172};
_S_zpfs  S_zpfs_2175_1 = {&var171,&fRM_30_0,&var173,&internal1_m2175_tx,&internal1_m2175_y0};
_S_noto  S_noto_2180_1 = {&var173,&var174};
_S_zpfs  S_zpfs_2174_1 = {&var172,&fRM_30_0,&var175,&internal1_m2174_tx,&internal1_m2174_y0};
_S_noto  S_noto_2179_1 = {&var175,&var176};
_S_and3  S_and3_2169_1 = {&var216,&var196,&lRM_1_,&var177};
_S_and2  S_and2_909_1 = {&var1353,&var179,&var178};
_S_noto  S_noto_896_1 = {&var166,&var179};
_S_and2  S_and2_1312_1 = {&var1321,&var181,&var180};
_S_noto  S_noto_1309_1 = {&var166,&var181};
_S_or2  S_or2_2215_1 = {&var192,&var193,&var182};
_S_and2  S_and2_2171_1 = {&var184,&var177,&var183};
_S_abs_subf  S_abs_subf_2162_1 = {&var1735,&var217,&fEM_A3UC08RDU,&vainSFloat,&var184};
_S_and2  S_and2_2217_1 = {&var177,&var192,&var185};
_S_or4  S_or4_1968_1 = {&var145,&var813,&var923,&var185,&var186};
_S_noto  S_noto_2220_1 = {&var170,&var187};
_S_or2  S_or2_2195_1 = {&var210,&var221,&var188};
_S_inf  S_inf_2191_1 = {&var219,array_m2191_a_1,array_m2191_b_1,&iRM_6_,&var189,&vainSInt};
_S_or3  S_or3_2219_1 = {&var206,&var213,&var214,&var190};
_S_noto  S_noto_2218_1 = {&var190,&var191};
_S_noto  S_noto_2216_1 = {&var216,&var192};
_S_ovbs  S_ovbs_2211_1 = {&var195,&fRM_15_0,&var193,&internal1_m2211_tx};
_S_zpfs  S_zpfs_2209_1 = {&var196,&fRM_10_0,&var194,&internal1_m2209_tx,&internal1_m2209_y0};
_S_and2  S_and2_2210_1 = {&var194,&R0MW17LP1,&var195};
_S_rs  S_rs_2214_1 = {&var182,&R0MW17LP1,&var196,&vainSBool,&internal1_m2214_q0};
_S_rs  S_rs_2181_1 = {&var210,&var177,&var197,&vainSBool,&internal1_m2181_q0};
_S_and3  S_and3_2188_1 = {&var212,&var165,&var197,&var198};
_S_ml  S_ml_1290_1 = {&var217,&var319,&var166,&var199};
_S_ml  S_ml_884_1 = {&var217,&var323,&var166,&var200};
_S_and2  S_and2_2235_1 = {&var177,&var336,&var201};
_S_noto  S_noto_2201_1 = {&var167,&var202};
_S_noto  S_noto_2186_1 = {&var1292,&var203};
_S_sr  S_sr_2202_1 = {array_m2202_x_1,&iRM_4_,&var204};
_S_sr  S_sr_2225_1 = {array_m2225_x_1,&iRM_2_,&var205};
_S_and2  S_and2_2239_1 = {&var207,&var177,&var206};
_S_abs_subf  S_abs_subf_2234_1 = {&B3MC01RP1,&A3MC01RP1,&fRM_0_01,&vainSFloat,&var207};
_S_fsumo  S_fsumo_80_1 = {&var985,&fEM_R0UN11RDU,&var208};
_S_or3  S_or3_126_1 = {&var146,&var66,&var188,&var209};
_S_ovbs  S_ovbs_2189_1 = {&var198,&fRM_1_0,&var210,&internal1_m2189_tx};
_S_noto  S_noto_2198_1 = {&var188,&var211};
_S_rs  S_rs_2187_1 = {&var210,&var1648,&var212,&vainSBool,&internal1_m2187_q0};
_S_and2  S_and2_2238_1 = {&var221,&var177,&var213};
_S_and2  S_and2_2237_1 = {&var215,&var177,&var214};
_S_bol  S_bol_2227_1 = {&fEM_R0UN09RDU,&var205,&var215};
_S_andn  S_andn_2194_1 = {array_m2194_x_1,&iRM_14_,&var216};
_S_irm  S_irm_2170_1 = {&var985,&var983,&B3MC01RP1,&var1735,&var205,&var204,&var177,&var1009,&fEM_R0UN12RDU,&fEM_R0UN13RDU,&fEM_R0UN14RDU,&fEM_R0UT20RDU,&var189,&fEM_R0UN15RDU,&fEM_R0UN25RDU,&fEM_R0UN16RDU,&fEM_R0UN17RDU,&fEM_R0UN18RDU,&fEM_R0UN19RDU,&fEM_R0UN27RDU,&fEM_R0UN26RDU,&fEM_R0UN24RDU,&var217,&var218,&var219,&var220,&var221,&var222,&var223,&var224};
_S_noto  S_noto_2025_1 = {&var347,&var225};
_S_noto  S_noto_1995_1 = {&var348,&var226};
_S_and4  S_and4_2018_1 = {&var370,&var127,&var340,&var225,&var227};
_S_and4  S_and4_1997_1 = {&var371,&var131,&var340,&var226,&var228};
_S_zpfs  S_zpfs_2013_1 = {&var354,&fRM_210_0,&var229,&internal1_m2013_tx,&internal1_m2013_y0};
_S_zpfs  S_zpfs_2005_1 = {&var355,&fRM_210_0,&var230,&internal1_m2005_tx,&internal1_m2005_y0};
_S_and2  S_and2_551_1 = {&var1368,&var403,&var231};
_S_and2  S_and2_233_1 = {&var403,&var1401,&var232};
_S_noto  S_noto_1549_1 = {&var234,&var233};
_S_abs_subf  S_abs_subf_1540_1 = {&var1732,&var319,&fEM_A3UC07RDU,&vainSFloat,&var234};
_S_noto  S_noto_1530_1 = {&var236,&var235};
_S_abs_subf  S_abs_subf_1521_1 = {&var323,&var1735,&fEM_A3UC07RDU,&vainSFloat,&var236};
_S_noto  S_noto_1544_1 = {&var238,&var237};
_S_abs_subf  S_abs_subf_1538_1 = {&var327,&var1745,&fEM_A1UC07RDU,&vainSFloat,&var238};
_S_noto  S_noto_1525_1 = {&var240,&var239};
_S_abs_subf  S_abs_subf_1517_1 = {&var331,&var1723,&fEM_A1UC07RDU,&vainSFloat,&var240};
_S_bol  S_bol_1308_1 = {&var1732,&fEM_A3UC09RDU,&var241};
_S_bol  S_bol_905_1 = {&var1735,&fEM_A3UC09RDU,&var242};
_S_noto  S_noto_1770_1 = {&var247,&var243};
_S_noto  S_noto_1759_1 = {&var245,&var244};
_S_and3  S_and3_1752_1 = {&var917,&var246,&var1209,&var245};
_S_bol  S_bol_1744_1 = {&fRM_55_0,&var319,&var246};
_S_and3  S_and3_1771_1 = {&var248,&var916,&var1209,&var247};
_S_bol  S_bol_1780_1 = {&fRM_55_0,&var323,&var248};
_S_and4  S_and4_45_1 = {&var1639,&var915,&var1094,&var1191,&var249};
_S_noto  S_noto_1221_1 = {&var965,&var250};
_S_and2  S_and2_1225_1 = {&var1468,&var965,&var251};
_S_and2  S_and2_1222_1 = {&var1468,&var250,&var252};
_S_noto  S_noto_1169_1 = {&var965,&var253};
_S_and2  S_and2_1170_1 = {&var965,&var1542,&var254};
_S_and2  S_and2_1166_1 = {&var1542,&var253,&var255};
_S_noto  S_noto_914_1 = {&var965,&var256};
_S_and2  S_and2_915_1 = {&var256,&var1324,&var257};
_S_and2  S_and2_911_1 = {&var1324,&var965,&var258};
_S_noto  S_noto_463_1 = {&var965,&var259};
_S_and2  S_and2_464_1 = {&var259,&var1417,&var260};
_S_and2  S_and2_466_1 = {&var1417,&var965,&var261};
_S_noto  S_noto_190_1 = {&var965,&var262};
_S_and2  S_and2_191_1 = {&var262,&var1387,&var263};
_S_and2  S_and2_194_1 = {&var965,&var1387,&var264};
_S_and2  S_and2_121_1 = {&var267,&var392,&var265};
_S_and2  S_and2_122_1 = {&var965,&var392,&var266};
_S_noto  S_noto_116_1 = {&var965,&var267};
_S_and2  S_and2_117_1 = {&var267,&var391,&var268};
_S_and2  S_and2_118_1 = {&var965,&var391,&var269};
_S_and2  S_and2_1619_1 = {&var305,&var1213,&var270};
_S_and2  S_and2_1618_1 = {&var308,&var1213,&var271};
_S_and2  S_and2_1617_1 = {&var306,&var1213,&var272};
_S_and2  S_and2_1616_1 = {&var1213,&var309,&var273};
_S_and2  S_and2_1615_1 = {&var526,&var307,&var274};
_S_and2  S_and2_1614_1 = {&var526,&var310,&var275};
_S_and2  S_and2_1613_1 = {&var527,&var307,&var276};
_S_and2  S_and2_1612_1 = {&var527,&var310,&var277};
_S_and2  S_and2_1645_1 = {&var38,&var1170,&var278};
_S_and2  S_and2_1644_1 = {&var305,&var1214,&var279};
_S_and2  S_and2_1643_1 = {&var1171,&var251,&var280};
_S_and2  S_and2_1642_1 = {&var1214,&var308,&var281};
_S_and2  S_and2_1641_1 = {&var134,&var1172,&var282};
_S_and2  S_and2_1640_1 = {&var1214,&var306,&var283};
_S_and2  S_and2_1639_1 = {&var1173,&var251,&var284};
_S_and2  S_and2_1638_1 = {&var1214,&var309,&var285};
_S_and2  S_and2_1676_1 = {&var251,&var1174,&var286};
_S_and2  S_and2_1675_1 = {&var307,&var1212,&var287};
_S_and2  S_and2_1673_1 = {&var1175,&var254,&var288};
_S_and2  S_and2_1672_1 = {&var1176,&var254,&var289};
_S_and2  S_and2_1671_1 = {&var310,&var1212,&var290};
_S_rs  S_rs_1693_1 = {&var40,&var292,&var291,&vainSBool,&internal1_m1693_q0};
_S_and2  S_and2_1692_1 = {&var1210,&var305,&var292};
_S_and2  S_and2_1691_1 = {&var1210,&var308,&var293};
_S_rs  S_rs_1698_1 = {&var61,&var293,&var294,&vainSBool,&internal1_m1698_q0};
_S_rs  S_rs_1690_1 = {&var41,&var296,&var295,&vainSBool,&internal1_m1690_q0};
_S_and2  S_and2_1689_1 = {&var306,&var1210,&var296};
_S_and2  S_and2_1688_1 = {&var1210,&var309,&var297};
_S_and2  S_and2_1721_1 = {&var307,&var1641,&var298};
_S_rs  S_rs_1732_1 = {&var261,&var298,&var299,&vainSBool,&internal1_m1732_q0};
_S_and2  S_and2_1720_1 = {&var1641,&var310,&var300};
_S_and2  S_and2_1718_1 = {&var305,&var1198,&var301};
_S_and2  S_and2_1717_1 = {&var1198,&var308,&var302};
_S_and2  S_and2_1715_1 = {&var306,&var1198,&var303};
_S_and2  S_and2_1714_1 = {&var1198,&var309,&var304};
_S_and2  S_and2_1734_1 = {&var917,&var307,&var305};
_S_and2  S_and2_1713_1 = {&var916,&var307,&var306};
_S_and2  S_and2_1736_1 = {&var266,&var1254,&var307};
_S_and2  S_and2_1733_1 = {&var310,&var917,&var308};
_S_and2  S_and2_1712_1 = {&var310,&var916,&var309};
_S_and2  S_and2_1735_1 = {&var269,&var1254,&var310};
_S_zpfs  S_zpfs_741_1 = {&var881,&fRM_3_,&var311,&internal1_m741_tx,&internal1_m741_y0};
_S_or4  S_or4_1559_1 = {&var517,&var518,&var519,&var521,&var312};
_S_or5  S_or5_1550_1 = {&var525,&var524,&var523,&var522,&var312,&var313};
_S_andn  S_andn_1_1 = {array_m1_x_1,&iRM_47_,&vainSBool};
_S_or2  S_or2_1532_1 = {&var316,&var317,&var314};
_S_ml  S_ml_1516_1 = {&fRM_1500_0,&B8MC01RP2,&var314,&var315};
_S_bol  S_bol_1522_1 = {&B8MC01RP2,&fRM_1500_0001,&var316};
_S_bol  S_bol_1533_1 = {&fRM_389_99,&B8MC01RP2,&var317};
_S_or2  S_or2_1547_1 = {&var320,&var321,&var318};
_S_ml  S_ml_1537_1 = {&fRM_0_0,&B3MC01RP1,&var318,&var319};
_S_bol  S_bol_1539_1 = {&B3MC01RP1,&fRM_160_00001,&var320};
_S_bol  S_bol_1548_1 = {&fRM_0_0001,&B3MC01RP1,&var321};
_S_or2  S_or2_1527_1 = {&var324,&var325,&var322};
_S_ml  S_ml_1515_1 = {&fRM_0_0,&A3MC01RP1,&var322,&var323};
_S_bol  S_bol_1520_1 = {&A3MC01RP1,&fRM_160_0001,&var324};
_S_bol  S_bol_1529_1 = {&fRM_0_0001,&A3MC01RP1,&var325};
_S_or2  S_or2_1543_1 = {&var328,&var329,&var326};
_S_ml  S_ml_1535_1 = {&fRM_100_0,&B1MC01RP1,&var326,&var327};
_S_bol  S_bol_1541_1 = {&B1MC01RP1,&fRM_100_0001,&var328};
_S_bol  S_bol_1545_1 = {&fRM_0_0001,&B1MC01RP1,&var329};
_S_or2  S_or2_1524_1 = {&var332,&var333,&var330};
_S_ml  S_ml_1513_1 = {&fRM_100_0,&A1MC01RP1,&var330,&var331};
_S_bol  S_bol_1519_1 = {&A1MC01RP1,&fRM_100_0001,&var332};
_S_bol  S_bol_1528_1 = {&fRM_0_0001,&A1MC01RP1,&var333};
_S_and2  S_and2_102_1 = {&var72,&var159,&var334};
_S_noto  S_noto_103_1 = {&var159,&var335};
_S_and2  S_and2_106_1 = {&var72,&var335,&var336};
_S_and2  S_and2_1984_1 = {&var338,&var339,&var337};
_S_or3  S_or3_1983_1 = {&var1216,&var470,&var186,&var338};
_S_noto  S_noto_2021_1 = {&var129,&var339};
_S_noto  S_noto_2010_1 = {&var341,&var340};
_S_ovbs  S_ovbs_2009_1 = {&var1106,&fRM_2_0,&var341,&internal1_m2009_tx};
_S_noto  S_noto_2000_1 = {&var132,&var342};
_S_and2  S_and2_1970_1 = {&var344,&var342,&var343};
_S_or3  S_or3_1969_1 = {&var186,&var1220,&var470,&var344};
_S_noto  S_noto_2015_1 = {&var352,&var345};
_S_and2  S_and2_2016_1 = {&var1191,&var345,&var346};
_S_and2  S_and2_2024_1 = {&var346,&var127,&var347};
_S_and2  S_and2_2003_1 = {&var349,&var131,&var348};
_S_and2  S_and2_2008_1 = {&var350,&var1191,&var349};
_S_noto  S_noto_2007_1 = {&var908,&var350};
_S_noto  S_noto_2023_1 = {&var354,&var351};
_S_or2  S_or2_2014_1 = {&var229,&var351,&var352};
_S_noto  S_noto_2002_1 = {&var355,&var353};
_S_rs  S_rs_2012_1 = {&var229,&var360,&var354,&vainSBool,&internal1_m2012_q0};
_S_rs  S_rs_2004_1 = {&var230,&var361,&var355,&vainSBool,&internal1_m2004_q0};
_S_and2  S_and2_1993_1 = {&var358,&var365,&var356};
_S_and2  S_and2_1981_1 = {&var358,&var362,&var357};
_S_noto  S_noto_1975_1 = {&var359,&var358};
_S_ovbs  S_ovbs_1974_1 = {&var186,&fRM_10_0,&var359,&internal1_m1974_tx};
_S_ovbs  S_ovbs_1985_1 = {&var337,&fRM_2_0,&var360,&internal1_m1985_tx};
_S_ovbs  S_ovbs_1971_1 = {&var343,&fRM_2_0,&var361,&internal1_m1971_tx};
_S_or2  S_or2_1980_1 = {&var393,&var970,&var362};
_S_or2  S_or2_1976_1 = {&var394,&var343,&var363};
_S_or2  S_or2_1988_1 = {&var394,&var337,&var364};
_S_or2  S_or2_1992_1 = {&var393,&var967,&var365};
_S_rs  S_rs_1977_1 = {&var357,&var363,&var366,&vainSBool,&internal1_m1977_q0};
_S_noto  S_noto_1990_1 = {&var368,&var367};
_S_rs  S_rs_1989_1 = {&var356,&var364,&var368,&vainSBool,&internal1_m1989_q0};
_S_noto  S_noto_1978_1 = {&var366,&var369};
_S_noto  S_noto_1986_1 = {&var360,&var370};
_S_noto  S_noto_1972_1 = {&var361,&var371};
_S_and2  S_and2_1965_1 = {&var374,&var476,&var372};
_S_and2  S_and2_1954_1 = {&var374,&var473,&var373};
_S_noto  S_noto_1948_1 = {&var375,&var374};
_S_ovbs  S_ovbs_1947_1 = {&var146,&fRM_3_0,&var375,&internal1_m1947_tx};
_S_or2  S_or2_1472_1 = {&var1140,&lRM_0_,&var376};
_S_and2  S_and2_434_1 = {&var1613,&var1555,&var377};
_S_and2  S_and2_1833_1 = {&var1165,&B7AS31LDU,&var378};
_S_and2  S_and2_445_1 = {&var916,&var762,&var379};
_S_and2  S_and2_437_1 = {&var763,&var916,&var380};
_S_and2  S_and2_474_1 = {&var762,&var917,&var381};
_S_and2  S_and2_470_1 = {&var763,&var917,&var382};
_S_or2  S_or2_361_1 = {&var1626,&var888,&var383};
_S_or2  S_or2_357_1 = {&var1626,&var887,&var384};
_S_ovbs  S_ovbs_51_1 = {&var1638,&fRM_15_0,&var385,&internal1_m51_tx};
_S_ovbs  S_ovbs_338_1 = {&var1113,&fRM_0_02,&var386,&internal1_m338_tx};
_S_ovbs  S_ovbs_291_1 = {&var1115,&fRM_0_02,&var387,&internal1_m291_tx};
_S_ovbs  S_ovbs_742_1 = {&var311,&fRM_0_2,&var388,&internal1_m742_tx};
_S_ovbs  S_ovbs_1415_1 = {&R0MD31LP1,&fRM_10_0,&var389,&internal1_m1415_tx};
_S_ovbs  S_ovbs_113_1 = {&R0MD31LP1,&fRM_0_15,&var390,&internal1_m113_tx};
_S_ovbs  S_ovbs_115_1 = {&var336,&fRM_0_02,&var391,&internal1_m115_tx};
_S_ovbs  S_ovbs_120_1 = {&R0MD32LP1,&fRM_0_02,&var392,&internal1_m120_tx};
_S_ovbs  S_ovbs_21_1 = {&var1191,&fRM_3_0,&var393,&internal1_m21_tx};
_S_ovbs  S_ovbs_13_1 = {&var965,&fRM_3_0,&var394,&internal1_m13_tx};
_S_ovbs  S_ovbs_1956_1 = {&var146,&fRM_2_0,&var395,&internal1_m1956_tx};
_S_ovbs  S_ovbs_1944_1 = {&var146,&fRM_2_0,&var396,&internal1_m1944_tx};
_S_ovbs  S_ovbs_2052_1 = {&var1200,&fRM_2_0,&var397,&internal1_m2052_tx};
_S_ovbs  S_ovbs_2056_1 = {&var108,&fRM_2_0,&var398,&internal1_m2056_tx};
_S_ovbs  S_ovbs_1869_1 = {&var411,&fRM_0_01,&var399,&internal1_m1869_tx};
_S_ovbs  S_ovbs_77_1 = {&R0MW13LP2,&fRM_10_0,&var400,&internal1_m77_tx};
_S_zpfs  S_zpfs_309_1 = {&var819,&fRM_10_0,&var401,&internal1_m309_tx,&internal1_m309_y0};
_S_or2  S_or2_1027_1 = {&var1026,&var589,&var402};
_S_or2  S_or2_234_1 = {&A1VN71LZ1,&A1VN71LZ2,&var403};
_S_or2  S_or2_249_1 = {&var714,&var982,&var404};
_S_or5  S_or5_147_1 = {&B1IS21LDU,&B3IS21LDU,&B2IS21LDU,&var952,&var953,&var405};
_S_and2  S_and2_1024_1 = {&var1463,&var1097,&var406};
_S_or3  S_or3_982_1 = {&var150,&var674,&var673,&var407};
_S_or3  S_or3_1383_1 = {&var657,&var656,&var151,&var408};
_S_and2  S_and2_963_1 = {&var1228,&var1011,&var409};
_S_and3  S_and3_1864_1 = {&var427,&var412,&var420,&var410};
_S_or2  S_or2_1868_1 = {&var414,&var413,&var411};
_S_or3  S_or3_1866_1 = {&var414,&var413,&var423,&var412};
_S_zpfs  S_zpfs_1863_1 = {&var416,&fEM_R0UL02RDU,&var413,&internal1_m1863_tx,&internal1_m1863_y0};
_S_zpfs  S_zpfs_1861_1 = {&var417,&fEM_R0UL02RDU,&var414,&internal1_m1861_tx,&internal1_m1861_y0};
_S_or2  S_or2_1855_1 = {&var417,&var416,&var415};
_S_or2  S_or2_1856_1 = {&var418,&var1130,&var416};
_S_or2  S_or2_1854_1 = {&var419,&var1130,&var417};
_S_and3  S_and3_1848_1 = {&var1187,&var939,&var917,&var418};
_S_and3  S_and3_1847_1 = {&var1188,&var916,&var939,&var419};
_S_or2  S_or2_1845_1 = {&var1130,&var1129,&var420};
_S_or3  S_or3_1852_1 = {&var425,&var1129,&var423,&var421};
_S_and2  S_and2_1860_1 = {&var1130,&var412,&var422};
_S_and2  S_and2_1851_1 = {&var1121,&var424,&var423};
_S_zpfs  S_zpfs_1850_1 = {&var1130,&fEM_R0UL04RDU,&var424,&internal1_m1850_tx,&internal1_m1850_y0};
_S_and2  S_and2_1838_1 = {&var1124,&var573,&var425};
_S_or3  S_or3_1839_1 = {&var1078,&var579,&var1056,&var426};
_S_abs_subf  S_abs_subf_1872_1 = {&fEM_R0UL02RDU,&var428,&fEM_R0UL16RDU,&vainSFloat,&var427};
_S_rsfn  S_rsfn_1870_1 = {&var570,&var429,&var428,&internal1_m1870_q0};
_S_lk  S_lk_1867_1 = {&var1283,&var412,&var429};
_S_abs_subf  S_abs_subf_1444_1 = {&fEM_R0UL05RDU,&var431,&fEM_R0UL18RDU,&vainSFloat,&var430};
_S_rsfn  S_rsfn_1435_1 = {&var570,&var432,&var431,&internal1_m1435_q0};
_S_lk  S_lk_1439_1 = {&var1135,&var557,&var432};
_S_abs_subf  S_abs_subf_1486_1 = {&fEM_R0UL07RDU,&var434,&fEM_R0UL20RDU,&vainSFloat,&var433};
_S_rsfn  S_rsfn_1474_1 = {&var570,&var435,&var434,&internal1_m1474_q0};
_S_lk  S_lk_1477_1 = {&var1141,&var547,&var435};
_S_ma  S_ma_1456_1 = {array_m1456_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_abs_subf  S_abs_subf_1491_1 = {&fEM_R0UL25RDU,&var437,&fEM_R0UL19RDU,&vainSFloat,&var436};
_S_rsfn  S_rsfn_1469_1 = {&var570,&var438,&var437,&internal1_m1469_q0};
_S_lk  S_lk_1480_1 = {&var1281,&var538,&var438};
_S_and3  S_and3_1914_1 = {&var440,&var443,&var450,&var439};
_S_abs_subf  S_abs_subf_1911_1 = {&var441,&fEM_R0UL03RDU,&fEM_R0UL17RDU,&vainSFloat,&var440};
_S_rsfn  S_rsfn_1909_1 = {&var570,&var442,&var441,&internal1_m1909_q0};
_S_lk  S_lk_1905_1 = {&var1282,&var443,&var442};
_S_or3  S_or3_1904_1 = {&var448,&var454,&var453,&var443};
_S_and4  S_and4_1908_1 = {&var453,&var1288,&var466,&var464,&var444};
_S_and4  S_and4_1906_1 = {&var454,&var1288,&var466,&var464,&var445};
_S_and2  S_and2_1898_1 = {&var1133,&var443,&var446};
_S_and2  S_and2_1884_1 = {&var573,&var1123,&var447};
_S_and2  S_and2_1887_1 = {&var451,&var1122,&var448};
_S_or3  S_or3_1888_1 = {&var448,&var447,&var1132,&var449};
_S_or2  S_or2_1880_1 = {&var1133,&var1132,&var450};
_S_zpfs  S_zpfs_1886_1 = {&var1133,&fEM_R0UL21RDU,&var451,&internal1_m1886_tx,&internal1_m1886_y0};
_S_or3  S_or3_1877_1 = {&var575,&var1082,&var1060,&var452};
_S_zpfs  S_zpfs_1902_1 = {&var456,&fEM_R0UL03RDU,&var453,&internal1_m1902_tx,&internal1_m1902_y0};
_S_zpfs  S_zpfs_1899_1 = {&var457,&fEM_R0UL03RDU,&var454,&internal1_m1899_tx,&internal1_m1899_y0};
_S_or2  S_or2_1895_1 = {&var457,&var456,&var455};
_S_or2  S_or2_1896_1 = {&var458,&var1133,&var456};
_S_or2  S_or2_1894_1 = {&var459,&var1133,&var457};
_S_and4  S_and4_1892_1 = {&var1189,&var917,&B2IS12LDU,&var460,&var458};
_S_and4  S_and4_1891_1 = {&var1190,&A2IS12LDU,&var916,&var460,&var459};
_S_and2  S_and2_1885_1 = {&var939,&var464,&var460};
_S_and3  S_and3_1923_1 = {&var917,&var1044,&var463,&var461};
_S_and3  S_and3_1922_1 = {&var916,&var1045,&var463,&var462};
_S_and4  S_and4_1921_1 = {&var1010,&var809,&var811,&var464,&var463};
_S_and2  S_and2_1915_1 = {&var822,&var1011,&var464};
_S_or2  S_or2_1917_1 = {&var1292,&var1009,&var465};
_S_or3  S_or3_1926_1 = {&var469,&var468,&var471,&var466};
_S_and2  S_and2_1916_1 = {&var1048,&A2IS12LDU,&var467};
_S_and2  S_and2_1920_1 = {&var949,&var467,&var468};
_S_and3  S_and3_1925_1 = {&var1287,&var472,&var467,&var469};
_S_or2  S_or2_1934_1 = {&lRM_0_,&var465,&var470};
_S_and2  S_and2_1931_1 = {&var964,&var472,&var471};
_S_and2  S_and2_1933_1 = {&var1047,&B2IS12LDU,&var472};
_S_or2  S_or2_1953_1 = {&var969,&var393,&var473};
_S_or2  S_or2_1949_1 = {&var394,&var146,&var474};
_S_or2  S_or2_1960_1 = {&var146,&var394,&var475};
_S_or2  S_or2_1964_1 = {&var393,&var968,&var476};
_S_or2  S_or2_2027_1 = {&var817,&var1201,&var477};
_S_or2  S_or2_2036_1 = {&var1011,&var1222,&var478};
_S_zpfs  S_zpfs_2034_1 = {&var77,&fRM_15_0,&var479,&internal1_m2034_tx,&internal1_m2034_y0};
_S_or2  S_or2_2039_1 = {&var816,&var109,&var480};
_S_zpfs  S_zpfs_2046_1 = {&var75,&fRM_15_0,&var481,&internal1_m2046_tx,&internal1_m2046_y0};
_S_or2  S_or2_2049_1 = {&var1011,&var1221,&var482};
_S_or2  S_or2_2064_1 = {&var81,&var444,&var483};
_S_or2  S_or2_2060_1 = {&var445,&var85,&var484};
_S_and2  S_and2_2071_1 = {&var1191,&var397,&var485};
_S_and2  S_and2_1832_1 = {&var1166,&A7AS31LDU,&var486};
_S_or3  S_or3_1805_1 = {&var491,&var495,&var493,&var487};
_S_or3  S_or3_1806_1 = {&var494,&var493,&var490,&var488};
_S_or2  S_or2_1819_1 = {&B0VT71LZ1,&B0VT71LZ2,&var489};
_S_and2  S_and2_1810_1 = {&var496,&var489,&var490};
_S_and2  S_and2_1804_1 = {&var496,&var492,&var491};
_S_or2  S_or2_1803_1 = {&A0VT71LZ1,&A0VT71LZ2,&var492};
_S_zpfs  S_zpfs_1800_1 = {&var1183,&fRM_2_5,&var493,&internal1_m1800_tx,&internal1_m1800_y0};
_S_zpfs  S_zpfs_1799_1 = {&var1184,&fRM_2_5,&var494,&internal1_m1799_tx,&internal1_m1799_y0};
_S_zpfs  S_zpfs_1798_1 = {&var1185,&fRM_2_5,&var495,&internal1_m1798_tx,&internal1_m1798_y0};
_S_zpfs  S_zpfs_1797_1 = {&var1186,&fRM_2_5,&var496,&internal1_m1797_tx,&internal1_m1797_y0};
_S_or2  S_or2_1828_1 = {&R0VP73LZ2,&R0VP73LZ1,&var497};
_S_and2  S_and2_1823_1 = {&var108,&var1167,&var498};
_S_or2  S_or2_1818_1 = {&var501,&var498,&var499};
_S_or2  S_or2_1820_1 = {&var81,&var108,&var500};
_S_and2  S_and2_1817_1 = {&var81,&var1157,&var501};
_S_and2  S_and2_1801_1 = {&var1200,&var1168,&var502};
_S_or2  S_or2_1802_1 = {&var505,&var502,&var503};
_S_or2  S_or2_1795_1 = {&var85,&var1200,&var504};
_S_and2  S_and2_1794_1 = {&var85,&var1158,&var505};
_S_or3  S_or3_1764_1 = {&var1251,&var1209,&var1210,&var506};
_S_or3  S_or3_1765_1 = {&var1249,&var1209,&var1210,&var507};
_S_or2  S_or2_1756_1 = {&var1244,&var1209,&var508};
_S_or2  S_or2_1757_1 = {&var1243,&var1209,&var509};
_S_or2  S_or2_1763_1 = {&var1253,&var1212,&var510};
_S_or4  S_or4_1761_1 = {&var1212,&var1250,&var1213,&var1214,&var511};
_S_or4  S_or4_1760_1 = {&var1212,&var1256,&var1213,&var1214,&var512};
_S_or2  S_or2_1754_1 = {&var1245,&var1214,&var513};
_S_or2  S_or2_1753_1 = {&var1246,&var1214,&var514};
_S_or2  S_or2_1762_1 = {&var1212,&var1252,&var515};
_S_or2  S_or2_1731_1 = {&var261,&var307,&var516};
_S_and2  S_and2_1564_1 = {&var1506,&var1464,&var517};
_S_and2  S_and2_1563_1 = {&var1629,&var1464,&var518};
_S_and2  S_and2_1562_1 = {&var906,&var1464,&var519};
_S_or2  S_or2_1561_1 = {&B4IS11LDU,&A4IS11LDU,&var520};
_S_and2  S_and2_1560_1 = {&var520,&var1464,&var521};
_S_and2  S_and2_1554_1 = {&var1672,&var1464,&var522};
_S_and2  S_and2_1553_1 = {&var159,&var1464,&var523};
_S_and2  S_and2_1552_1 = {&var895,&var1464,&var524};
_S_and2  S_and2_1551_1 = {&R3IS21LDU,&var1464,&var525};
_S_or2  S_or2_1611_1 = {&var1642,&var1643,&var526};
_S_or2  S_or2_1610_1 = {&var1644,&var1642,&var527};
_S_or2  S_or2_2085_1 = {&var988,&R0MD34LP1,&var528};
_S_or3  S_or3_2091_1 = {&var1263,&var1265,&var1264,&var529};
_S_or3  S_or3_2082_1 = {&var1269,&var1271,&var1270,&var530};
_S_or2  S_or2_1599_1 = {&var1730,&var1464,&var531};
_S_or2  S_or2_1573_1 = {&var1507,&var1097,&var532};
_S_or5  S_or5_1121_1 = {&var1522,&var534,&var1533,&var1519,&var1520,&var533};
_S_or3  S_or3_1125_1 = {&var1527,&var1528,&var991,&var534};
_S_or5  S_or5_1587_1 = {&var313,&var536,&var1516,&var1508,&var1509,&var535};
_S_or3  S_or3_1590_1 = {&var990,&var1510,&var1511,&var536};
_S_and3  S_and3_1500_1 = {&var538,&var543,&var436,&var537};
_S_and2  S_and2_1503_1 = {&var539,&var1280,&var538};
_S_or3  S_or3_1502_1 = {&A3VZ13LZ2,&A3VZ13LZ1,&var542,&var539};
_S_zpfs  S_zpfs_1487_1 = {&var1280,&fRM_0_2,&var540,&internal1_m1487_tx,&internal1_m1487_y0};
_S_or3  S_or3_1489_1 = {&var1143,&var542,&var544,&var541};
_S_and2  S_and2_1488_1 = {&var1120,&var540,&var542};
_S_or2  S_or2_1478_1 = {&var1280,&var1143,&var543};
_S_and2  S_and2_1466_1 = {&var1125,&var573,&var544};
_S_or3  S_or3_1475_1 = {&var1057,&var1079,&var578,&var545};
_S_or3  S_or3_1496_1 = {&R0AD14LZ1,&R0AD14LZ2,&var549,&var546};
_S_and2  S_and2_1497_1 = {&var546,&var1140,&var547};
_S_zpfs  S_zpfs_1481_1 = {&var1140,&fEM_R0UL06RDU,&var548,&internal1_m1481_tx,&internal1_m1481_y0};
_S_and2  S_and2_1482_1 = {&var548,&var1119,&var549};
_S_or3  S_or3_1483_1 = {&var1138,&var549,&var552,&var550};
_S_or3  S_or3_1458_1 = {&var577,&var1080,&var1058,&var551};
_S_and2  S_and2_1461_1 = {&var1126,&var573,&var552};
_S_and3  S_and3_1499_1 = {&var433,&var547,&var560,&var553};
_S_zpfs  S_zpfs_1431_1 = {&var1137,&fEM_R0UL04RDU,&var554,&internal1_m1431_tx,&internal1_m1431_y0};
_S_and2  S_and2_1432_1 = {&var554,&var1118,&var555};
_S_and3  S_and3_1448_1 = {&var430,&var557,&var561,&var556};
_S_and2  S_and2_1442_1 = {&var558,&var1137,&var557};
_S_or3  S_or3_1441_1 = {&A3VZ15LZ1,&A3VZ15LZ2,&var555,&var558};
_S_or3  S_or3_1433_1 = {&var562,&var555,&var1136,&var559};
_S_or2  S_or2_1470_1 = {&var1140,&var1138,&var560};
_S_or2  S_or2_1429_1 = {&var1137,&var1136,&var561};
_S_and2  S_and2_1421_1 = {&var1127,&var573,&var562};
_S_or3  S_or3_1419_1 = {&var1059,&var1081,&var576,&var563};
_S_or2  S_or2_1393_1 = {&var1635,&var565,&var564};
_S_and2  S_and2_1392_1 = {&var566,&var1181,&var565};
_S_or2  S_or2_1391_1 = {&var962,&var914,&var566};
_S_or2  S_or2_1388_1 = {&var1052,&var1074,&var567};
_S_and2  S_and2_1386_1 = {&var1146,&var1147,&var568};
_S_and2  S_and2_1389_1 = {&var567,&var566,&var569};
_S_or5  S_or5_1390_1 = {&var387,&var386,&var568,&var569,&R0MD34LP1,&var570};
_S_orni  S_orni_1410_1 = {array_m1410_x_1,&iRM_5_,&var571,&var572};
_S_or5  S_or5_1412_1 = {&var1142,&var1117,&var570,&var1062,&var389,&var573};
_S_and2  S_and2_1411_1 = {&var571,&var1275,&var574};
_S_or2  S_or2_1418_1 = {&var1089,&var580,&var575};
_S_or2  S_or2_1414_1 = {&var1088,&var581,&var576};
_S_or2  S_or2_1408_1 = {&var1087,&var582,&var577};
_S_or2  S_or2_1406_1 = {&var1086,&var583,&var578};
_S_or2  S_or2_1404_1 = {&var1085,&var584,&var579};
_S_and2  S_and2_1417_1 = {&var1630,&var585,&var580};
_S_and2  S_and2_1413_1 = {&var1631,&var585,&var581};
_S_and2  S_and2_1407_1 = {&var1632,&var585,&var582};
_S_and2  S_and2_1405_1 = {&var1633,&var585,&var583};
_S_and2  S_and2_1403_1 = {&var1634,&var585,&var584};
_S_and2  S_and2_1397_1 = {&var1635,&var68,&var585};
_S_and3  S_and3_1057_1 = {&var255,&var590,&var608,&var586};
_S_or2  S_or2_1022_1 = {&var1099,&var1095,&var587};
_S_or2  S_or2_1048_1 = {&var1095,&var1029,&var588};
_S_and2  S_and2_1015_1 = {&var1473,&var1096,&var589};
_S_and2  S_and2_1011_1 = {&var1292,&var610,&var590};
_S_or3  S_or3_1019_1 = {&var1095,&var1025,&var1098,&var591};
_S_and2  S_and2_1023_1 = {&var252,&var1292,&var592};
_S_and2  S_and2_1040_1 = {&var263,&var1292,&var593};
_S_and2  S_and2_1056_1 = {&var257,&var1292,&var594};
_S_and2  S_and2_1063_1 = {&var260,&var1292,&var595};
_S_and3  S_and3_1006_1 = {&var598,&var1014,&var1292,&var596};
_S_and3  S_and3_1000_1 = {&var599,&var1014,&var1292,&var597};
_S_and2  S_and2_1008_1 = {&var916,&var1291,&var598};
_S_and2  S_and2_998_1 = {&var917,&var1291,&var599};
_S_and4  S_and4_1007_1 = {&var598,&var1292,&var1022,&var1012,&var600};
_S_and4  S_and4_1001_1 = {&var599,&var1292,&var1022,&var1012,&var601};
_S_and4  S_and4_1005_1 = {&var1292,&var598,&var606,&var1013,&var602};
_S_and4  S_and4_999_1 = {&var1292,&var599,&var606,&var1013,&var603};
_S_and2  S_and2_992_1 = {&var1023,&var1292,&var604};
_S_or4  S_or4_995_1 = {&R0MD31LP1,&var1526,&var268,&var617,&var605};
_S_and3  S_and3_1041_1 = {&var1024,&var1023,&var1022,&var606};
_S_and2  S_and2_1028_1 = {&var608,&var402,&var607};
_S_and2  S_and2_1031_1 = {&var1021,&var606,&var608};
_S_or2  S_or2_1042_1 = {&var1091,&var1033,&var609};
_S_and2  S_and2_1050_1 = {&var611,&var609,&var610};
_S_or2  S_or2_1043_1 = {&var1032,&var1034,&var611};
_S_or2  S_or2_1044_1 = {&var1031,&var1032,&var612};
_S_or2  S_or2_1046_1 = {&var1030,&var1035,&var613};
_S_and2  S_and2_1047_1 = {&var612,&var613,&var614};
_S_or2  S_or2_1034_1 = {&var1091,&var1090,&var615};
_S_and2  S_and2_1035_1 = {&var615,&var1027,&var616};
_S_and5  S_and5_988_1 = {&var618,&var1111,&var1032,&var1091,&var607,&var617};
_S_and2  S_and2_989_1 = {&var1066,&var1067,&var618};
_S_and2  S_and2_1235_1 = {&var1160,&var620,&var619};
_S_or2  S_or2_1233_1 = {&A2MD12LP1,&var621,&var620};
_S_and2  S_and2_1220_1 = {&A2MD11LP1,&var1177,&var621};
_S_or2  S_or2_1213_1 = {&var624,&B2MD12LP1,&var622};
_S_and2  S_and2_1214_1 = {&var622,&var1160,&var623};
_S_and2  S_and2_1206_1 = {&B2MD11LP1,&var1178,&var624};
_S_or3  S_or3_1194_1 = {&var1242,&var1237,&var780,&var625};
_S_or5  S_or5_1207_1 = {&var628,&var4,&var1,&var3,&var2,&var626};
_S_or2  S_or2_1229_1 = {&var1742,&var1488,&var627};
_S_or3  S_or3_1285_1 = {&var1469,&var629,&var630,&var628};
_S_and2  S_and2_1280_1 = {&var1488,&var963,&var629};
_S_and2  S_and2_1279_1 = {&var913,&var1488,&var630};
_S_and3  S_and3_1278_1 = {&var405,&var949,&var645,&var631};
_S_and2  S_and2_1277_1 = {&var159,&var645,&var632};
_S_and3  S_and3_1273_1 = {&var938,&var984,&var645,&var633};
_S_and2  S_and2_1272_1 = {&var497,&var645,&var634};
_S_and2  S_and2_1260_1 = {&var1479,&var645,&var635};
_S_and2  S_and2_1247_1 = {&var1672,&var645,&var636};
_S_and2  S_and2_1262_1 = {&var66,&var645,&var637};
_S_and2  S_and2_1248_1 = {&R3IS21LDU,&var645,&var638};
_S_and2  S_and2_1263_1 = {&var641,&var645,&var639};
_S_and3  S_and3_1249_1 = {&var642,&var1478,&var645,&var640};
_S_or2  S_or2_1264_1 = {&var1471,&var1472,&var641};
_S_or2  S_or2_1250_1 = {&A4IS11LDU,&B4IS11LDU,&var642};
_S_and3  S_and3_1259_1 = {&var1212,&var269,&var965,&var643};
_S_and3  S_and3_1258_1 = {&var1214,&var269,&var965,&var644};
_S_or3  S_or3_1252_1 = {&var1489,&var644,&var643,&var645};
_S_and2  S_and2_1337_1 = {&var647,&var1160,&var646};
_S_or2  S_or2_1333_1 = {&var648,&B3MD12LP1,&var647};
_S_and2  S_and2_1322_1 = {&B3MD11LP1,&var1156,&var648};
_S_or2  S_or2_1325_1 = {&var1733,&var1306,&var649};
_S_or5  S_or5_1311_1 = {&var408,&var1316,&var1315,&var180,&var998,&var650};
_S_and2  S_and2_1371_1 = {&var1306,&var963,&var651};
_S_and2  S_and2_1370_1 = {&var1306,&var913,&var652};
_S_and2  S_and2_1379_1 = {&var979,&var1294,&var653};
_S_or2  S_or2_1374_1 = {&var653,&var980,&var654};
_S_and3  S_and3_1369_1 = {&var1169,&var654,&var663,&var655};
_S_and3  S_and3_1368_1 = {&var405,&var964,&var663,&var656};
_S_and2  S_and2_1367_1 = {&var159,&var663,&var657};
_S_and2  S_and2_1364_1 = {&var1226,&var1011,&var658};
_S_or2  S_or2_1354_1 = {&var1297,&var1296,&var659};
_S_and2  S_and2_1353_1 = {&var659,&var663,&var660};
_S_and2  S_and2_1352_1 = {&var66,&var663,&var661};
_S_and2  S_and2_1350_1 = {&var1299,&var663,&var662};
_S_or2  S_or2_1341_1 = {&var1308,&var89,&var663};
_S_or2  S_or2_1342_1 = {&B4IS11LDU,&A4IS11LDU,&var664};
_S_and3  S_and3_1340_1 = {&var1298,&var664,&var663,&var665};
_S_and2  S_and2_1339_1 = {&R3IS21LDU,&var663,&var666};
_S_and2  S_and2_1338_1 = {&var1672,&var663,&var667};
_S_and2  S_and2_978_1 = {&var977,&var1326,&var668};
_S_and2  S_and2_969_1 = {&var913,&var1338,&var669};
_S_and2  S_and2_970_1 = {&var963,&var1338,&var670};
_S_or2  S_or2_973_1 = {&var978,&var668,&var671};
_S_and3  S_and3_968_1 = {&var1169,&var671,&var678,&var672};
_S_and3  S_and3_967_1 = {&var949,&var405,&var678,&var673};
_S_and2  S_and2_966_1 = {&var159,&var678,&var674};
_S_and2  S_and2_949_1 = {&var1331,&var678,&var675};
_S_or2  S_or2_953_1 = {&var1329,&var1328,&var676};
_S_and2  S_and2_952_1 = {&var676,&var678,&var677};
_S_or2  S_or2_940_1 = {&var1340,&var90,&var678};
_S_or2  S_or2_941_1 = {&B4IS11LDU,&A4IS11LDU,&var679};
_S_and3  S_and3_939_1 = {&var679,&var1330,&var678,&var680};
_S_and2  S_and2_951_1 = {&var66,&var678,&var681};
_S_and2  S_and2_938_1 = {&R3IS21LDU,&var678,&var682};
_S_and2  S_and2_937_1 = {&var1672,&var678,&var683};
_S_or2  S_or2_924_1 = {&var1338,&var1736,&var684};
_S_or5  S_or5_908_1 = {&var407,&var999,&var178,&var1347,&var1348,&var685};
_S_and2  S_and2_936_1 = {&var1160,&var687,&var686};
_S_or2  S_or2_932_1 = {&var688,&A3MD12LP1,&var687};
_S_and2  S_and2_921_1 = {&A3MD11LP1,&var1211,&var688};
_S_or3  S_or3_879_1 = {&var1436,&var691,&var690,&var689};
_S_and2  S_and2_873_1 = {&var1447,&var913,&var690};
_S_and2  S_and2_874_1 = {&var1447,&var963,&var691};
_S_and3  S_and3_872_1 = {&var1470,&var964,&var703,&var692};
_S_and2  S_and2_871_1 = {&var159,&var703,&var693};
_S_and2  S_and2_854_1 = {&var1440,&var703,&var694};
_S_and2  S_and2_856_1 = {&var66,&var703,&var695};
_S_and2  S_and2_857_1 = {&var697,&var703,&var696};
_S_or2  S_or2_858_1 = {&var1438,&var1437,&var697};
_S_and2  S_and2_841_1 = {&var1672,&var703,&var698};
_S_and3  S_and3_843_1 = {&var1439,&var704,&var703,&var699};
_S_and2  S_and2_842_1 = {&R3IS21LDU,&var703,&var700};
_S_and3  S_and3_853_1 = {&var1212,&var269,&var965,&var701};
_S_and3  S_and3_852_1 = {&var269,&var1214,&var965,&var702};
_S_or3  S_or3_846_1 = {&var1448,&var701,&var702,&var703};
_S_or2  S_or2_844_1 = {&B4IS11LDU,&A4IS11LDU,&var704};
_S_or2  S_or2_830_1 = {&var1739,&var1447,&var705};
_S_zpfs  S_zpfs_825_1 = {&var1461,&fRM_3_0,&var706,&internal1_m825_tx,&internal1_m825_y0};
_S_zpfs  S_zpfs_826_1 = {&var1462,&fRM_2_0,&var707,&internal1_m826_tx,&internal1_m826_y0};
_S_zpfs  S_zpfs_834_1 = {&var1459,&fEM_A2UL83RDU,&var708,&internal1_m834_tx,&internal1_m834_y0};
_S_or5  S_or5_817_1 = {&var689,&var6,&var5,&var7,&var8,&var709};
_S_or3  S_or3_805_1 = {&var1217,&var1240,&var775,&var710};
_S_or4  S_or4_790_1 = {&var1583,&var1581,&var1582,&var1584,&var711};
_S_or2  S_or2_781_1 = {&var713,&var711,&var712};
_S_or4  S_or4_774_1 = {&var1592,&var1591,&var1590,&var1593,&var713};
_S_and2  S_and2_254_1 = {&var981,&var1386,&var714};
_S_and3  S_and3_243_1 = {&var949,&var405,&var1401,&var715};
_S_or3  S_or3_256_1 = {&var719,&var717,&var1389,&var716};
_S_and2  S_and2_246_1 = {&var1400,&var963,&var717};
_S_and3  S_and3_244_1 = {&var404,&var1169,&var1401,&var718};
_S_and2  S_and2_245_1 = {&var913,&var1400,&var719};
_S_and2  S_and2_242_1 = {&var159,&var1401,&var720};
_S_and2  S_and2_217_1 = {&var1393,&var1401,&var721};
_S_and2  S_and2_219_1 = {&var66,&var1401,&var722};
_S_or2  S_or2_221_1 = {&var1390,&var1391,&var723};
_S_and2  S_and2_220_1 = {&var723,&var1401,&var724};
_S_or2  S_or2_210_1 = {&B4IS11LDU,&A4IS11LDU,&var725};
_S_and3  S_and3_209_1 = {&var1392,&var725,&var1401,&var726};
_S_and2  S_and2_207_1 = {&var1672,&var1401,&var727};
_S_and2  S_and2_208_1 = {&R3IS21LDU,&var1401,&var728};
_S_and2  S_and2_186_1 = {&var1160,&var731,&var729};
_S_and2  S_and2_176_1 = {&A1MD11LP1,&var1199,&var730};
_S_or2  S_or2_182_1 = {&A1MD12LP1,&var730,&var731};
_S_or2  S_or2_196_1 = {&var1400,&var1724,&var732};
_S_zpfs  S_zpfs_187_1 = {&var1415,&fRM_2_0,&var733,&internal1_m187_tx,&internal1_m187_y0};
_S_zpfs  S_zpfs_192_1 = {&var1414,&fRM_2_0,&var734,&internal1_m192_tx,&internal1_m192_y0};
_S_zpfs  S_zpfs_198_1 = {&var1412,&fEM_A1UL03RDU,&var735,&internal1_m198_tx,&internal1_m198_y0};
_S_or5  S_or5_180_1 = {&var716,&var735,&var734,&var733,&var1413,&var736};
_S_orn  S_orn_546_1 = {array_m546_x_1,&iRM_14_,&var737};
_S_and2  S_and2_569_1 = {&var1356,&var976,&var738};
_S_or2  S_or2_564_1 = {&var975,&var738,&var739};
_S_and3  S_and3_558_1 = {&var964,&var1470,&var1368,&var740};
_S_and2  S_and2_557_1 = {&var159,&var1368,&var741};
_S_and3  S_and3_559_1 = {&var1169,&var1368,&var739,&var742};
_S_or2  S_or2_539_1 = {&var1358,&var1357,&var743};
_S_and2  S_and2_538_1 = {&var743,&var1368,&var744};
_S_and2  S_and2_537_1 = {&var1368,&var66,&var745};
_S_and3  S_and3_527_1 = {&var1359,&var747,&var1368,&var746};
_S_or2  S_or2_528_1 = {&B4IS11LDU,&A4IS11LDU,&var747};
_S_and2  S_and2_535_1 = {&var1368,&var1360,&var748};
_S_or2  S_or2_505_1 = {&B1MD12LP1,&var751,&var749};
_S_and2  S_and2_509_1 = {&var1160,&var749,&var750};
_S_and2  S_and2_500_1 = {&B1MD11LP1,&var1179,&var751};
_S_and2  S_and2_526_1 = {&var1368,&R3IS21LDU,&var752};
_S_and2  S_and2_525_1 = {&var1368,&var1672,&var753};
_S_or2  S_or2_516_1 = {&var1367,&var1746,&var754};
_S_zpfs  S_zpfs_518_1 = {&var1381,&fEM_A1UL03RDU,&var755,&internal1_m518_tx,&internal1_m518_y0};
_S_or5  S_or5_501_1 = {&var909,&var755,&var1382,&var1376,&var1377,&var756};
_S_or2  S_or2_489_1 = {&var1195,&var776,&var757};
_S_or3  S_or3_479_1 = {&var597,&var1194,&var1006,&var758};
_S_or4  S_or4_469_1 = {&var1420,&var1418,&var1420,&var1419,&var759};
_S_or4  S_or4_451_1 = {&var1429,&var1427,&var1428,&var1430,&var760};
_S_or2  S_or2_458_1 = {&var760,&var759,&var761};
_S_and3  S_and3_442_1 = {&var764,&var1160,&R0MD33LP1,&var762};
_S_and3  S_and3_443_1 = {&var1160,&var765,&R0MD33LP1,&var763};
_S_or3  S_or3_435_1 = {&var299,&var1015,&var1002,&var764};
_S_or2  S_or2_436_1 = {&var1416,&var1193,&var765};
_S_or2  S_or2_744_1 = {&var1551,&var1552,&var766};
_S_and2  S_and2_328_1 = {&var1051,&var1113,&var767};
_S_or2  S_or2_347_1 = {&B4IS21LDU,&A4IS21LDU,&var768};
_S_or2  S_or2_342_1 = {&A2IS21LDU,&B2IS21LDU,&var769};
_S_or2  S_or2_337_1 = {&var772,&var1055,&var770};
_S_and3  S_and3_335_1 = {&var1114,&var1109,&var1110,&var771};
_S_or4  S_or4_333_1 = {&var1040,&var209,&R0MD31LP1,&var1050,&var772};
_S_and4  S_and4_329_1 = {&var962,&var830,&var268,&var920,&var773};
_S_or2  S_or2_324_1 = {&R0MD34LP1,&var1050,&var774};
_S_and3  S_and3_598_1 = {&var797,&var1293,&B2IS12LDU,&var775};
_S_and2  S_and2_597_1 = {&var797,&var1325,&var776};
_S_and2  S_and2_596_1 = {&var797,&var1388,&var777};
_S_or2  S_or2_640_1 = {&A2IS12LDU,&B2IS12LDU,&var778};
_S_or2  S_or2_617_1 = {&var1523,&var1149,&var779};
_S_and3  S_and3_608_1 = {&A2IS12LDU,&var1293,&var798,&var780};
_S_and2  S_and2_639_1 = {&var782,&var1293,&var781};
_S_or2  S_or2_641_1 = {&var1092,&var252,&var782};
_S_or2  S_or2_622_1 = {&var1523,&var1148,&var783};
_S_or2  S_or2_620_1 = {&var785,&var1523,&var784};
_S_and2  S_and2_632_1 = {&var1325,&var263,&var785};
_S_and2  S_and2_607_1 = {&var798,&var1325,&var786};
_S_and2  S_and2_606_1 = {&var798,&var1388,&var787};
_S_and2  S_and2_631_1 = {&var257,&var1388,&var788};
_S_and2  S_and2_647_1 = {&var260,&var1416,&var789};
_S_or2  S_or2_643_1 = {&var1523,&var1150,&var790};
_S_or2  S_or2_638_1 = {&var792,&var789,&var791};
_S_and2  S_and2_630_1 = {&var800,&var1385,&var792};
_S_and2  S_and2_636_1 = {&var800,&R0MD33LP1,&var793};
_S_or2  S_or2_586_1 = {&var973,&var974,&var794};
_S_and4  S_and4_605_1 = {&var973,&var798,&var1485,&A2IS12LDU,&var795};
_S_and4  S_and4_595_1 = {&var797,&var974,&var1485,&B2IS12LDU,&var796};
_S_and2  S_and2_594_1 = {&var917,&var1483,&var797};
_S_and2  S_and2_604_1 = {&var916,&var1483,&var798};
_S_or2  S_or2_635_1 = {&var1093,&var252,&var799};
_S_and2  S_and2_628_1 = {&var799,&var1485,&var800};
_S_or2  S_or2_615_1 = {&var1523,&var1151,&var801};
_S_or2  S_or2_627_1 = {&var1463,&var1106,&var802};
_S_and2  S_and2_626_1 = {&var802,&var1507,&var803};
_S_or2  S_or2_612_1 = {&var1523,&var1152,&var804};
_S_and2  S_and2_625_1 = {&var1524,&var1473,&var805};
_S_or2  S_or2_610_1 = {&var1523,&var1153,&var806};
_S_and2  S_and2_623_1 = {&var255,&var1526,&var807};
_S_or2  S_or2_602_1 = {&var1161,&var1523,&var808};
_S_and2  S_and2_302_1 = {&var1223,&var811,&var809};
_S_and2  S_and2_290_1 = {&var811,&var1038,&var810};
_S_or2  S_or2_285_1 = {&var1052,&var1074,&var811};
_S_and3  S_and3_281_1 = {&var1289,&var1109,&var1110,&var812};
_S_and3  S_and3_296_1 = {&var769,&var1039,&var814,&var813};
_S_or2  S_or2_286_1 = {&var1289,&var1114,&var814};
_S_and2  S_and2_295_1 = {&var768,&var814,&var815};
_S_and2  S_and2_316_1 = {&var820,&var917,&var816};
_S_and2  S_and2_317_1 = {&var916,&var820,&var817};
_S_and2  S_and2_322_1 = {&var1011,&var809,&var818};
_S_and2  S_and2_310_1 = {&var820,&var1011,&var819};
_S_and2  S_and2_315_1 = {&var1191,&var821,&var820};
_S_or2  S_or2_311_1 = {&var822,&var767,&var821};
_S_or2  S_or2_312_1 = {&var823,&var767,&var822};
_S_and4  S_and4_313_1 = {&var1115,&var1063,&var1064,&var914,&var823};
_S_or2  S_or2_298_1 = {&var1115,&var1113,&var824};
_S_and2  S_and2_283_1 = {&var1077,&var1046,&var825};
_S_or2  S_or2_289_1 = {&var828,&var825,&var826};
_S_or2  S_or2_263_1 = {&R0MD34LP1,&var1049,&var827};
_S_or4  S_or4_280_1 = {&var1040,&R0MD31LP1,&var209,&var1049,&var828};
_S_and3  S_and3_273_1 = {&var830,&var919,&var268,&var829};
_S_or2  S_or2_272_1 = {&var1068,&var1254,&var830};
_S_and3  S_and3_274_1 = {&var1069,&var1071,&var1070,&var831};
_S_or2  S_or2_265_1 = {&var833,&var831,&var832};
_S_and3  S_and3_259_1 = {&R0MD33LP1,&var1073,&var1072,&var833};
_S_or2  S_or2_1093_1 = {&B4IS11LDU,&A4IS11LDU,&var834};
_S_and2  S_and2_1096_1 = {&var1474,&var1521,&var835};
_S_and2  S_and2_1095_1 = {&var1474,&var1629,&var836};
_S_and2  S_and2_1094_1 = {&var1474,&var906,&var837};
_S_and2  S_and2_1092_1 = {&var1474,&var834,&var838};
_S_and2  S_and2_1086_1 = {&var1474,&var159,&var839};
_S_and2  S_and2_1085_1 = {&var895,&var1474,&var840};
_S_and2  S_and2_1084_1 = {&var1474,&R3IS21LDU,&var841};
_S_and2  S_and2_1087_1 = {&var1474,&var1672,&var842};
_S_and2  S_and2_1079_1 = {&var252,&var1008,&var843};
_S_and2  S_and2_1080_1 = {&var263,&var1006,&var844};
_S_and2  S_and2_1081_1 = {&var257,&var1004,&var845};
_S_and2  S_and2_1082_1 = {&var260,&var1002,&var846};
_S_or2  S_or2_1064_1 = {&R0MD31LP1,&var848,&var847};
_S_and4  S_and4_1065_1 = {&var164,&var163,&var162,&var161,&var848};
_S_or2  S_or2_1135_1 = {&var1474,&var1727,&var849};
_S_or2  S_or2_1111_1 = {&var1524,&var1096,&var850};
_S_or2  S_or2_1176_1 = {&var1565,&var1564,&var851};
_S_or2  S_or2_1162_1 = {&var1574,&var1573,&var852};
_S_or2  S_or2_1173_1 = {&var989,&R0MD34LP1,&var853};
_S_or2  S_or2_1149_1 = {&var851,&var1629,&var854};
_S_or2  S_or2_1147_1 = {&var856,&var854,&var855};
_S_or2  S_or2_1148_1 = {&var852,&var1629,&var856};
_S_or4  S_or4_359_1 = {&var1601,&var1600,&var1602,&var1599,&var857};
_S_or2  S_or2_660_1 = {&B5IS11LDU,&A5IS11LDU,&var858};
_S_and2  S_and2_659_1 = {&var863,&var858,&var859};
_S_or2  S_or2_658_1 = {&B6IS11LDU,&A6IS11LDU,&var860};
_S_and2  S_and2_657_1 = {&var863,&var860,&var861};
_S_or2  S_or2_656_1 = {&A4IS11LDU,&B4IS11LDU,&var862};
_S_or2  S_or2_649_1 = {&var865,&var866,&var863};
_S_and2  S_and2_655_1 = {&var863,&var862,&var864};
_S_and2  S_and2_651_1 = {&var159,&var876,&var865};
_S_and2  S_and2_648_1 = {&var160,&var869,&var866};
_S_and2  S_and2_764_1 = {&var1627,&var1545,&var867};
_S_and2  S_and2_760_1 = {&var1627,&var1546,&var868};
_S_and3  S_and3_755_1 = {&var1627,&var160,&var1552,&var869};
_S_or2  S_or2_763_1 = {&var1547,&var1541,&var870};
_S_or2  S_or2_758_1 = {&var1545,&var1547,&var871};
_S_or2  S_or2_754_1 = {&var1547,&var1546,&var872};
_S_and2  S_and2_736_1 = {&var1541,&var1627,&var873};
_S_or2  S_or2_728_1 = {&var1548,&var1549,&var874};
_S_or2  S_or2_723_1 = {&var1606,&var1548,&var875};
_S_and2  S_and2_720_1 = {&var1549,&var1628,&var876};
_S_and2  S_and2_719_1 = {&var1606,&var1628,&var877};
_S_and2  S_and2_748_1 = {&var255,&var1627,&var878};
_S_and2  S_and2_730_1 = {&var255,&var1558,&var879};
_S_and2  S_and2_746_1 = {&var1628,&var255,&var880};
_S_or2  S_or2_740_1 = {&var1628,&var1627,&var881};
_S_or3  S_or3_733_1 = {&var70,&var884,&var885,&var882};
_S_or4  S_or4_732_1 = {&var884,&var69,&var886,&var1537,&var883};
_S_or3  S_or3_722_1 = {&R4MD31LP2,&var873,&var877,&var884};
_S_or2  S_or2_752_1 = {&var1626,&var888,&var885};
_S_or2  S_or2_751_1 = {&var1626,&var887,&var886};
_S_and2  S_and2_670_1 = {&var70,&var1540,&var887};
_S_and3  S_and3_699_1 = {&var1539,&var1553,&var69,&var888};
_S_and2  S_and2_704_1 = {&R5IS11LDU,&var903,&var889};
_S_and3  S_and3_702_1 = {&var1191,&R3IS21LDU,&var903,&var890};
_S_and2  S_and2_703_1 = {&R6IS21LDU,&var903,&var891};
_S_or2  S_or2_701_1 = {&B8IS22LDU,&A8IS22LDU,&var892};
_S_and2  S_and2_700_1 = {&var892,&var903,&var893};
_S_and2  S_and2_687_1 = {&var903,&var895,&var894};
_S_or4  S_or4_688_1 = {&A0VN71LZ1,&B0VN71LZ1,&B0VN71LZ2,&A0VN71LZ2,&var895};
_S_and2  S_and2_685_1 = {&var900,&var903,&var896};
_S_and2  S_and2_676_1 = {&var906,&var903,&var897};
_S_and2  S_and2_675_1 = {&var1629,&var903,&var898};
_S_or3  S_or3_674_1 = {&R0NE01LDU,&R0NE02LDU,&R0NE08LDU,&var899};
_S_or2  S_or2_686_1 = {&R1IS21LDU,&R2IS21LDU,&var900};
_S_and2  S_and2_673_1 = {&var903,&var899,&var901};
_S_and2  S_and2_671_1 = {&var1607,&var903,&var902};
_S_or2  S_or2_662_1 = {&var1628,&var1627,&var903};
_S_or2  S_or2_166_1 = {&var1197,&var786,&var904};
_S_or3  S_or3_156_1 = {&var596,&var1196,&var1006,&var905};
_S_or2  S_or2_149_1 = {&var1470,&var405,&var906};
_S_or3  S_or3_108_1 = {&var1159,&var391,&var392,&var907};
_S_or2  S_or2_2006_1 = {&var353,&var230,&var908};
_S_or3  S_or3_571_1 = {&var910,&var911,&var737,&var909};
_S_and2  S_and2_560_1 = {&var1367,&var913,&var910};
_S_and2  S_and2_561_1 = {&var1367,&var963,&var911};
_S_or2  S_or2_60_1 = {&var963,&var913,&var912};
_S_and2  S_and2_63_1 = {&var914,&var1042,&var913};
_S_and2  S_and2_62_1 = {&var1636,&var1043,&var914};
_S_or2  S_or2_48_1 = {&A4IS21LDU,&B4IS21LDU,&var915};
_S_or2  S_or2_35_1 = {&var1287,&var1284,&var916};
_S_or2  S_or2_39_1 = {&var1287,&var1286,&var917};
_S_or2  S_or2_20_1 = {&var1191,&var1144,&var918};
_S_or2  S_or2_8_1 = {&var1646,&var965,&var919};
_S_or2  S_or2_14_1 = {&var965,&var1647,&var920};
_S_and3  S_and3_987_1 = {&var265,&var1640,&var940,&var921};
_S_and3  S_and3_584_1 = {&var940,&var268,&var1640,&var922};
_S_and2  S_and2_1053_1 = {&var986,&var924,&var923};
_S_or2  S_or2_1059_1 = {&var1647,&var1646,&var924};
_S_or2  S_or2_1363_1 = {&var1648,&var1646,&var925};
_S_and3  S_and3_1362_1 = {&var984,&var925,&var663,&var926};
_S_or2  S_or2_962_1 = {&var1648,&var1646,&var927};
_S_and3  S_and3_961_1 = {&var984,&var927,&var678,&var928};
_S_or2  S_or2_550_1 = {&var1648,&var1646,&var929};
_S_and3  S_and3_549_1 = {&var984,&var929,&var1368,&var930};
_S_and2  S_and2_547_1 = {&var155,&var1368,&var931};
_S_or2  S_or2_232_1 = {&var1648,&var1646,&var932};
_S_and3  S_and3_231_1 = {&var984,&var932,&var1401,&var933};
_S_and2  S_and2_229_1 = {&var1401,&var156,&var934};
_S_and3  S_and3_867_1 = {&var984,&var937,&var703,&var935};
_S_and2  S_and2_866_1 = {&var497,&var703,&var936};
_S_or2  S_or2_868_1 = {&var1648,&var1646,&var937};
_S_or2  S_or2_1274_1 = {&var1648,&var1646,&var938};
_S_or2  S_or2_6_1 = {&var1647,&var1646,&var939};
_S_or3  S_or3_5_1 = {&var1648,&var1647,&var1646,&var940};
_S_or2  S_or2_739_1 = {&var1548,&var1550,&var941};
_S_or2  S_or2_432_1 = {&var1629,&var946,&var942};
_S_or2  S_or2_415_1 = {&var1629,&var947,&var943};
_S_or4  S_or4_416_1 = {&var943,&var1557,&var1556,&var942,&var944};
_S_and2  S_and2_408_1 = {&A8IS22LDU,&var1621,&var945};
_S_or3  S_or3_394_1 = {&var1611,&var1609,&var1610,&var946};
_S_or3  S_or3_379_1 = {&var1619,&var1618,&var1620,&var947};
_S_and2  S_and2_726_1 = {&var1628,&var1550,&var948};
_S_and2  S_and2_38_1 = {&var1284,&var1285,&var949};
_S_and2  S_and2_142_1 = {&var1560,&var1182,&var950};
_S_and2  S_and2_150_1 = {&var1562,&var1182,&var951};
_S_and2  S_and2_153_1 = {&var1559,&var1182,&var952};
_S_and2  S_and2_145_1 = {&var1182,&var1561,&var953};
_S_and2  S_and2_429_1 = {&var906,&var1613,&var954};
_S_and2  S_and2_428_1 = {&B8IS22LDU,&var1613,&var955};
_S_and2  S_and2_427_1 = {&A8IS22LDU,&var1613,&var956};
_S_and2  S_and2_426_1 = {&R5IS11LDU,&var1613,&var957};
_S_and2  S_and2_418_1 = {&var1555,&var1621,&var958};
_S_and2  S_and2_407_1 = {&R5IS11LDU,&var1621,&var959};
_S_and2  S_and2_411_1 = {&var906,&var1621,&var960};
_S_and2  S_and2_112_1 = {&var965,&var390,&var961};
_S_and2  S_and2_58_1 = {&var1637,&var1043,&var962};
_S_and2  S_and2_59_1 = {&var962,&var1041,&var963};
_S_and2  S_and2_42_1 = {&var1285,&var1286,&var964};
_S_and2  S_and2_11_1 = {&var1645,&var1277,&var965};
_S_and2  S_and2_31_1 = {&var1208,&var254,&var966};
_S_and2  S_and2_30_1 = {&var1102,&var1191,&var967};
_S_and2  S_and2_29_1 = {&var1103,&var1191,&var968};
_S_and2  S_and2_28_1 = {&var1104,&var1191,&var969};
_S_and2  S_and2_27_1 = {&var1105,&var1191,&var970};
_S_and2  S_and2_753_1 = {&var1544,&var1552,&var971};
_S_and2  S_and2_735_1 = {&var1551,&var1628,&var972};
_S_bol  S_bol_585_1 = {&var1741,&fRM_20_0,&var973};
_S_bol  S_bol_579_1 = {&var1738,&fRM_20_0,&var974};
_S_bol  S_bol_570_1 = {&var1738,&fRM_20_03,&var975};
_S_bol  S_bol_568_1 = {&var1741,&fRM_20_03,&var976};
_S_bol  S_bol_977_1 = {&var1738,&fRM_20_03,&var977};
_S_bol  S_bol_979_1 = {&var1741,&fRM_20_03,&var978};
_S_bol  S_bol_1378_1 = {&var1741,&fRM_20_03,&var979};
_S_bol  S_bol_1380_1 = {&var1738,&fRM_20_03,&var980};
_S_bol  S_bol_253_1 = {&var1738,&fRM_20_03,&var981};
_S_bol  S_bol_255_1 = {&var1741,&fRM_20_03,&var982};
_S_sr  S_sr_82_1 = {array_m82_x_1,&iRM_2_,&var983};
_S_bol  S_bol_81_1 = {&var983,&var208,&var984};
_S_ma  S_ma_84_1 = {array_m84_x_1,&R0MW15IP1,&iRM_8_,&var985};
_S_bol  S_bol_1054_1 = {&var987,&fEM_R0UN80RDU,&var986};
_S_sr  S_sr_1060_1 = {array_m1060_x_1,&iRM_2_,&var987};
_S_ovbs  S_ovbs_2084_1 = {&lRM_1_,&fEM_A9UZ04RDU,&var988,&internal1_m2084_tx};
_S_ovbs  S_ovbs_1172_1 = {&lRM_1_,&fEM_A4UZ04RDU,&var989,&internal1_m1172_tx};
_S_zpfs  S_zpfs_1601_1 = {&var1515,&fEM_B8UL03RDU,&var990,&internal1_m1601_tx,&internal1_m1601_y0};
_S_zpfs  S_zpfs_1137_1 = {&var1532,&fEM_B8UL03RDU,&var991,&internal1_m1137_tx,&internal1_m1137_y0};
_S_ma  S_ma_1196_1 = {array_m1196_x_1,&var1484,&iRM_8_,&var992};
_S_ma  S_ma_807_1 = {array_m807_x_1,&var1444,&iRM_8_,&var993};
_S_ma  S_ma_891_1 = {array_m891_x_1,&var1335,&iRM_8_,&var994};
_S_ma  S_ma_1297_1 = {array_m1297_x_1,&var1303,&iRM_8_,&var995};
_S_ma  S_ma_488_1 = {array_m488_x_1,&var1364,&iRM_8_,&var996};
_S_ma  S_ma_164_1 = {array_m164_x_1,&var1397,&iRM_8_,&var997};
_S_zpfs  S_zpfs_1327_1 = {&var1320,&fEM_A3UL03RDU,&var998,&internal1_m1327_tx,&internal1_m1327_y0};
_S_zpfs  S_zpfs_926_1 = {&var1352,&fEM_A3UL03RDU,&var999,&internal1_m926_tx,&internal1_m926_y0};
_S_zpfs  S_zpfs_1242_1 = {&var1502,&fEM_A2UL03RDU,&var1000,&internal1_m1242_tx,&internal1_m1242_y0};
_S_rs  S_rs_1078_1 = {&var847,&var846,&var1001,&vainSBool,&internal1_m1078_q0};
_S_rs  S_rs_1076_1 = {&var164,&var1009,&var1002,&vainSBool,&internal1_m1076_q0};
_S_rs  S_rs_1075_1 = {&var847,&var845,&var1003,&vainSBool,&internal1_m1075_q0};
_S_rs  S_rs_1073_1 = {&var163,&var1009,&var1004,&vainSBool,&internal1_m1073_q0};
_S_rs  S_rs_1072_1 = {&var847,&var844,&var1005,&vainSBool,&internal1_m1072_q0};
_S_rs  S_rs_1070_1 = {&var162,&var1009,&var1006,&vainSBool,&internal1_m1070_q0};
_S_rs  S_rs_1069_1 = {&var847,&var843,&var1007,&vainSBool,&internal1_m1069_q0};
_S_rs  S_rs_1067_1 = {&var161,&var1009,&var1008,&vainSBool,&internal1_m1067_q0};
_S_rs  S_rs_1066_1 = {&var847,&var209,&var1009,&vainSBool,&internal1_m1066_q0};
_S_noto  S_noto_1918_1 = {&var465,&var1010};
_S_swtakt  S_swtakt_52_1 = {&var385,&var1011,&internal1_m52_x0};
_S_noto  S_noto_1052_1 = {&var1023,&var1012};
_S_noto  S_noto_1026_1 = {&var1021,&var1013};
_S_noto  S_noto_1038_1 = {&var1022,&var1014};
_S_rs  S_rs_986_1 = {&var1024,&var604,&var1015,&vainSBool,&internal1_m986_q0};
_S_swtakt  S_swtakt_1424_1 = {&var563,&var1016,&internal1_m1424_x0};
_S_swtakt  S_swtakt_1468_1 = {&var551,&var1017,&internal1_m1468_x0};
_S_swtakt  S_swtakt_1464_1 = {&var545,&var1018,&internal1_m1464_x0};
_S_swtakt  S_swtakt_1878_1 = {&var452,&var1019,&internal1_m1878_x0};
_S_swtakt  S_swtakt_1843_1 = {&var426,&var1020,&internal1_m1843_x0};
_S_rs  S_rs_1025_1 = {&var1095,&var592,&var1021,&vainSBool,&internal1_m1025_q0};
_S_rs  S_rs_1037_1 = {&var1095,&var593,&var1022,&vainSBool,&internal1_m1037_q0};
_S_rs  S_rs_1049_1 = {&var1095,&var594,&var1023,&vainSBool,&internal1_m1049_q0};
_S_rs  S_rs_1058_1 = {&var1095,&var595,&var1024,&vainSBool,&internal1_m1058_q0};
_S_noto  S_noto_1012_1 = {&var610,&var1025};
_S_noto  S_noto_1039_1 = {&var610,&var1026};
_S_noto  S_noto_1045_1 = {&var614,&var1027};
_S_rs  S_rs_1036_1 = {&var588,&var590,&var1028,&vainSBool,&internal1_m1036_q0};
_S_rs  S_rs_1051_1 = {&var1095,&var586,&var1029,&vainSBool,&internal1_m1051_q0};
_S_bol  S_bol_1033_1 = {&var1726,&var315,&var1030};
_S_bol  S_bol_1032_1 = {&var1729,&var315,&var1031};
_S_noto  S_noto_993_1 = {&var1090,&var1032};
_S_bol  S_bol_1030_1 = {&var315,&var1726,&var1033};
_S_bol  S_bol_1029_1 = {&var315,&var1729,&var1034};
_S_noto  S_noto_1016_1 = {&var1091,&var1035};
_S_rs  S_rs_1936_1 = {&var470,&var461,&var1036,&vainSBool,&internal1_m1936_q0};
_S_rs  S_rs_1935_1 = {&var470,&var462,&var1037,&vainSBool,&internal1_m1935_q0};
_S_noto  S_noto_323_1 = {&var818,&var1038};
_S_noto  S_noto_305_1 = {&var811,&var1039};
_S_noto  S_noto_277_1 = {&var830,&var1040};
_S_noto  S_noto_56_1 = {&var1052,&var1041};
_S_noto  S_noto_67_1 = {&var1074,&var1042};
_S_noto  S_noto_66_1 = {&var1009,&var1043};
_S_noto  S_noto_1930_1 = {&B2IS11LDU,&var1044};
_S_noto  S_noto_1928_1 = {&A2IS11LDU,&var1045};
_S_noto  S_noto_282_1 = {&var268,&var1046};
_S_noto  S_noto_1937_1 = {&B2IS11LDU,&var1047};
_S_noto  S_noto_1912_1 = {&A2IS11LDU,&var1048};
_S_noto  S_noto_269_1 = {&var914,&var1049};
_S_noto  S_noto_327_1 = {&var962,&var1050};
_S_bolz  S_bolz_331_1 = {&iRM_2_,&var1053,&var1051};
_S_provsbr  S_provsbr_326_1 = {&var1113,&var774,&var1128,&var1145,&var1139,&var1134,&var1131,&var1129,&var1143,&var1138,&var1136,&var1132,&iRM_10_,array_m326_Tpr_1,array_m326_type_1,&var1052,&var1053,&var1054,&var1055,&var1056,&var1057,&var1058,&var1059,&var1060,&internal1_m326_Step,array_m326_rz_1,&internal1_m326_TimS,&internal1_m326_FinPr0,&internal1_m326_ErrPr0,&internal1_m326_sbINI0,&internal1_m326_sbVuIS0,&internal1_m326_sb2UR0,&internal1_m326_sbNupIS0,&internal1_m326_sbVuRB0,&internal1_m326_MyFirstEnterFlag};
_S_orni  S_orni_330_1 = {array_m330_x_1,&iRM_5_,&vainSBool,&var1061};
_S_cntch  S_cntch_334_1 = {&var1061,&var1062,&internal1_m334_x0};
_S_bolz  S_bolz_308_1 = {&iRM_20_,&var1076,&var1063};
_S_equz_p  S_equz_p_307_1 = {&var1075,&iRM_0_,&var1064};
_S_decatron  S_decatron_293_1 = {&var810,&var1065,&internal1_m293_TimS};
_S_noto  S_noto_990_1 = {&R2IS21LDU,&var1066};
_S_noto  S_noto_984_1 = {&R1IS21LDU,&var1067};
_S_andn  S_andn_264_1 = {array_m264_x_1,&iRM_7_,&var1068};
_S_noto  S_noto_266_1 = {&R0MD33LP1,&var1069};
_S_noto  S_noto_275_1 = {&R2IS21LDU,&var1070};
_S_noto  S_noto_270_1 = {&R1IS21LDU,&var1071};
_S_noto  S_noto_261_1 = {&R1IS11LDU,&var1072};
_S_noto  S_noto_258_1 = {&R2IS11LDU,&var1073};
_S_provsbr  S_provsbr_268_1 = {&var1115,&var827,&var1128,&var1145,&var1139,&var1134,&var1131,&var1129,&var1143,&var1138,&var1136,&var1132,&iRM_10_,array_m268_Tpr_1,array_m268_type_1,&var1074,&var1075,&var1076,&var1077,&var1078,&var1079,&var1080,&var1081,&var1082,&internal1_m268_Step,array_m268_rz_1,&internal1_m268_TimS,&internal1_m268_FinPr0,&internal1_m268_ErrPr0,&internal1_m268_sbINI0,&internal1_m268_sbVuIS0,&internal1_m268_sb2UR0,&internal1_m268_sbNupIS0,&internal1_m268_sbVuRB0,&internal1_m268_MyFirstEnterFlag};
_S_rs  S_rs_1398_1 = {&var1084,&var585,&var1083,&vainSBool,&internal1_m1398_q0};
_S_provsbr  S_provsbr_1399_1 = {&var1083,&R0MD34LP1,&var1128,&var1145,&var1139,&var1134,&var1131,&var1129,&var1143,&var1138,&var1136,&var1132,&iRM_6_,array_m1399_Tpr_1,array_m1399_type_1,&var1084,&vainSInt,&vainSInt,&vainSBool,&var1085,&var1086,&var1087,&var1088,&var1089,&internal1_m1399_Step,array_m1399_rz_1,&internal1_m1399_TimS,&internal1_m1399_FinPr0,&internal1_m1399_ErrPr0,&internal1_m1399_sbINI0,&internal1_m1399_sbVuIS0,&internal1_m1399_sb2UR0,&internal1_m1399_sbNupIS0,&internal1_m1399_sbVuRB0,&internal1_m1399_MyFirstEnterFlag};
_S_abs_subf  S_abs_subf_996_1 = {&var315,&var1729,&fEM_B8UC01RDU,&vainSFloat,&var1090};
_S_abs_subf  S_abs_subf_1009_1 = {&var1726,&var315,&fEM_B8UC01RDU,&vainSFloat,&var1091};
_S_noto  S_noto_645_1 = {&var778,&var1092};
_S_noto  S_noto_592_1 = {&var794,&var1093};
_S_noto  S_noto_49_1 = {&var311,&var1094};
_S_noto  S_noto_1013_1 = {&var1292,&var1095};
_S_rs  S_rs_1021_1 = {&var587,&var406,&var1096,&vainSBool,&internal1_m1021_q0};
_S_rs  S_rs_1018_1 = {&var591,&var586,&var1097,&vainSBool,&internal1_m1018_q0};
_S_rs  S_rs_1020_1 = {&var1095,&var406,&var1098,&vainSBool,&internal1_m1020_q0};
_S_rs  S_rs_1014_1 = {&var1095,&var589,&var1099,&vainSBool,&internal1_m1014_q0};
_S_noto  S_noto_581_1 = {&A2IS21LDU,&var1100};
_S_noto  S_noto_583_1 = {&B2IS21LDU,&var1101};
_S_noto  S_noto_25_1 = {&B2IS21LDU,&var1102};
_S_noto  S_noto_24_1 = {&B1IS21LDU,&var1103};
_S_noto  S_noto_23_1 = {&A1IS21LDU,&var1104};
_S_noto  S_noto_22_1 = {&A2IS21LDU,&var1105};
_S_newstage  S_newstage_593_1 = {&var132,&var129,&A2IS12LDU,&B2IS12LDU,&var1106};
_S_noto  S_noto_582_1 = {&B2IS12LDU,&var1107};
_S_noto  S_noto_580_1 = {&A2IS12LDU,&var1108};
_S_noto  S_noto_340_1 = {&var769,&var1109};
_S_noto  S_noto_344_1 = {&var768,&var1110};
_S_noto  S_noto_983_1 = {&var906,&var1111};
_S_rs  S_rs_743_1 = {&var766,&var388,&var1112,&vainSBool,&internal1_m743_q0};
_S_rs  S_rs_336_1 = {&var770,&var771,&var1113,&vainSBool,&internal1_m336_q0};
_S_rs  S_rs_332_1 = {&var772,&var773,&var1114,&vainSBool,&internal1_m332_q0};
_S_rs  S_rs_288_1 = {&var826,&var812,&var1115,&vainSBool,&internal1_m288_q0};
_S_orni  S_orni_284_1 = {array_m284_x_1,&iRM_5_,&vainSBool,&var1116};
_S_cntch  S_cntch_287_1 = {&var1116,&var1117,&internal1_m287_x0};
_S_noto  S_noto_1437_1 = {&var1136,&var1118};
_S_noto  S_noto_1493_1 = {&var1138,&var1119};
_S_noto  S_noto_1495_1 = {&var1143,&var1120};
_S_noto  S_noto_1859_1 = {&var1129,&var1121};
_S_noto  S_noto_1893_1 = {&var1132,&var1122};
_S_noto  S_noto_1874_1 = {&var1019,&var1123};
_S_noto  S_noto_1837_1 = {&var1020,&var1124};
_S_noto  S_noto_1465_1 = {&var1018,&var1125};
_S_noto  S_noto_1460_1 = {&var1017,&var1126};
_S_noto  S_noto_1420_1 = {&var1016,&var1127};
_S_rs  S_rs_1865_1 = {&var570,&var410,&var1128,&vainSBool,&internal1_m1865_q0};
_S_rs  S_rs_1853_1 = {&var425,&var422,&var1129,&vainSBool,&internal1_m1853_q0};
_S_rs  S_rs_1844_1 = {&var421,&var1020,&var1130,&vainSBool,&internal1_m1844_q0};
_S_rs  S_rs_1919_1 = {&var570,&var439,&var1131,&vainSBool,&internal1_m1919_q0};
_S_rs  S_rs_1889_1 = {&var447,&var446,&var1132,&vainSBool,&internal1_m1889_q0};
_S_rs  S_rs_1879_1 = {&var449,&var1019,&var1133,&vainSBool,&internal1_m1879_q0};
_S_rs  S_rs_1451_1 = {&var570,&var556,&var1134,&vainSBool,&internal1_m1451_q0};
_S_kvf  S_kvf_1438_1 = {&var1137,&var557,&fRM_0_0,&var1135,&vainSInt,&vainSInt,&internal1_m1438_x0,&internal1_m1438_y0,&bFirstEnterFlag};
_S_rs  S_rs_1434_1 = {&var562,&var557,&var1136,&vainSBool,&internal1_m1434_q0};
_S_rs  S_rs_1425_1 = {&var559,&var1016,&var1137,&vainSBool,&internal1_m1425_q0};
_S_rs  S_rs_1484_1 = {&var552,&var547,&var1138,&vainSBool,&internal1_m1484_q0};
_S_rs  S_rs_1504_1 = {&var570,&var553,&var1139,&vainSBool,&internal1_m1504_q0};
_S_rs  S_rs_1471_1 = {&var550,&var1017,&var1140,&vainSBool,&internal1_m1471_q0};
_S_kvf  S_kvf_1485_1 = {&var1140,&var547,&fRM_0_0,&var1141,&vainSInt,&vainSInt,&internal1_m1485_x0,&internal1_m1485_y0,&bFirstEnterFlag};
_S_cntch  S_cntch_1409_1 = {&var572,&var1142,&internal1_m1409_x0};
_S_rs  S_rs_1490_1 = {&var544,&var538,&var1143,&vainSBool,&internal1_m1490_q0};
_S_rs  S_rs_26_1 = {&var1191,&var966,&var1144,&vainSBool,&internal1_m26_q0};
_S_rs  S_rs_1505_1 = {&var570,&var537,&var1145,&vainSBool,&internal1_m1505_q0};
_S_noto  S_noto_1387_1 = {&var566,&var1146};
_S_noto  S_noto_1385_1 = {&var965,&var1147};
_S_rs  S_rs_633_1 = {&var1523,&var781,&var1148,&vainSBool,&internal1_m633_q0};
_S_rs  S_rs_618_1 = {&var1523,&var788,&var1149,&vainSBool,&internal1_m618_q0};
_S_rs  S_rs_646_1 = {&var1523,&var789,&var1150,&vainSBool,&internal1_m646_q0};
_S_rs  S_rs_629_1 = {&var1523,&var800,&var1151,&vainSBool,&internal1_m629_q0};
_S_rs  S_rs_613_1 = {&var1523,&var803,&var1152,&vainSBool,&internal1_m613_q0};
_S_rs  S_rs_611_1 = {&var1523,&var805,&var1153,&vainSBool,&internal1_m611_q0};
_S_rs  S_rs_599_1 = {&var808,&var1526,&var1154,&vainSBool,&internal1_m599_q0};
_S_rsun  S_rsun_1401_1 = {&var570,&var1276,&vainSLong,&var1155,&internal1_m1401_q0};
_S_noto  S_noto_1328_1 = {&B3MD12LP1,&var1156};
_S_noto  S_noto_1813_1 = {&B3IS11LDU,&var1157};
_S_noto  S_noto_1787_1 = {&A3IS11LDU,&var1158};
_S_noto  S_noto_111_1 = {&var965,&var1159};
_S_noto  S_noto_110_1 = {&var1164,&var1160};
_S_rs  S_rs_609_1 = {&var1523,&var807,&var1161,&vainSBool,&internal1_m609_q0};
_S_orni  S_orni_1171_1 = {array_m1171_x_1,&iRM_5_,&var1162,&vainSLong};
_S_orni  S_orni_1158_1 = {array_m1158_x_1,&iRM_4_,&var1163,&vainSLong};
_S_rs  S_rs_109_1 = {&var907,&var961,&var1164,&vainSBool,&internal1_m109_q0};
_S_noto  S_noto_1816_1 = {&var488,&var1165};
_S_noto  S_noto_1815_1 = {&var487,&var1166};
_S_noto  S_noto_1827_1 = {&B3IS22LDU,&var1167};
_S_noto  S_noto_1808_1 = {&A3IS22LDU,&var1168};
_S_newstage  S_newstage_1811_1 = {&var504,&var500,&var503,&var499,&vainSBool};
_S_noto  S_noto_1755_1 = {&var1254,&var1169};
_S_rs  S_rs_1637_1 = {&var46,&var279,&var1170,&vainSBool,&internal1_m1637_q0};
_S_rs  S_rs_1636_1 = {&var39,&var281,&var1171,&vainSBool,&internal1_m1636_q0};
_S_rs  S_rs_1635_1 = {&var45,&var283,&var1172,&vainSBool,&internal1_m1635_q0};
_S_rs  S_rs_1634_1 = {&var21,&var285,&var1173,&vainSBool,&internal1_m1634_q0};
_S_rs  S_rs_1670_1 = {&var254,&var287,&var1174,&vainSBool,&internal1_m1670_q0};
_S_rs  S_rs_1669_1 = {&var57,&var290,&var1175,&vainSBool,&internal1_m1669_q0};
_S_rs  S_rs_1668_1 = {&var58,&var290,&var1176,&vainSBool,&internal1_m1668_q0};
_S_noto  S_noto_1224_1 = {&A2MD12LP1,&var1177};
_S_noto  S_noto_1209_1 = {&B2MD12LP1,&var1178};
_S_noto  S_noto_503_1 = {&B1MD12LP1,&var1179};
_S_ma  S_ma_1440_1 = {array_m1440_x_1,&var1155,&iRM_16_,&var1180};
_S_noto  S_noto_1395_1 = {&var822,&var1181};
_S_noto  S_noto_140_1 = {&var965,&var1182};
_S_equz_p  S_equz_p_1793_1 = {&R0MW14IP2,&iRM_5_,&var1183};
_S_equz_p  S_equz_p_1792_1 = {&R0MW14IP2,&iRM_4_,&var1184};
_S_equz_p  S_equz_p_1791_1 = {&R0MW14IP2,&iRM_3_,&var1185};
_S_equz_p  S_equz_p_1789_1 = {&R0MW14IP2,&iRM_1_,&vainSBool};
_S_equz_p  S_equz_p_1790_1 = {&R0MW14IP2,&iRM_2_,&var1186};
_S_noto  S_noto_1846_1 = {&B3IS11LDU,&var1187};
_S_noto  S_noto_1841_1 = {&A3IS11LDU,&var1188};
_S_noto  S_noto_1883_1 = {&B2IS11LDU,&var1189};
_S_noto  S_noto_1890_1 = {&A2IS11LDU,&var1190};
_S_noto  S_noto_12_1 = {&var1645,&var1191};
_S_rs  S_rs_1950_1 = {&var373,&var474,&var1192,&vainSBool,&internal1_m1950_q0};
_S_rs  S_rs_1730_1 = {&var516,&var300,&var1193,&vainSBool,&internal1_m1730_q0};
_S_rs  S_rs_1719_1 = {&var42,&var301,&var1194,&vainSBool,&internal1_m1719_q0};
_S_rs  S_rs_1727_1 = {&var59,&var302,&var1195,&vainSBool,&internal1_m1727_q0};
_S_rs  S_rs_1716_1 = {&var43,&var303,&var1196,&vainSBool,&internal1_m1716_q0};
_S_rs  S_rs_1724_1 = {&var63,&var304,&var1197,&vainSBool,&internal1_m1724_q0};
_S_equz_p  S_equz_p_99_1 = {&R0MW16IP1,&iRM_10_,&var1198};
_S_noto  S_noto_178_1 = {&A1MD12LP1,&var1199};
_S_rs  S_rs_2149_1 = {&var33,&var30,&var1200,&vainSBool,&internal1_m2149_q0};
_S_rs  S_rs_2145_1 = {&var49,&var121,&var1201,&vainSBool,&internal1_m2145_q0};
_S_rs  S_rs_1695_1 = {&var62,&var297,&var1202,&vainSBool,&internal1_m1695_q0};
_S_rs  S_rs_1687_1 = {&var254,&var286,&var1203,&vainSBool,&internal1_m1687_q0};
_S_rs  S_rs_1685_1 = {&var44,&var287,&var1204,&vainSBool,&internal1_m1685_q0};
_S_rs  S_rs_1681_1 = {&var57,&var288,&var1205,&vainSBool,&internal1_m1681_q0};
_S_rs  S_rs_1677_1 = {&var19,&var290,&var1206,&vainSBool,&internal1_m1677_q0};
_S_rs  S_rs_1679_1 = {&var58,&var289,&var1207,&vainSBool,&internal1_m1679_q0};
_S_rs  S_rs_19_1 = {&var918,&var394,&var1208,&vainSBool,&internal1_m19_q0};
_S_equz_p  S_equz_p_98_1 = {&R0MW16IP1,&iRM_9_,&var1209};
_S_equz_p  S_equz_p_97_1 = {&R0MW16IP1,&iRM_8_,&var1210};
_S_noto  S_noto_927_1 = {&A3MD12LP1,&var1211};
_S_equz_p  S_equz_p_96_1 = {&R0MW16IP1,&iRM_7_,&var1212};
_S_equz_p  S_equz_p_95_1 = {&R0MW16IP1,&iRM_6_,&var1213};
_S_equz_p  S_equz_p_94_1 = {&R0MW16IP1,&iRM_5_,&var1214};
_S_rs  S_rs_1660_1 = {&var46,&var278,&var1215,&vainSBool,&internal1_m1660_q0};
_S_rs  S_rs_1658_1 = {&var38,&var279,&var1216,&vainSBool,&internal1_m1658_q0};
_S_rs  S_rs_1654_1 = {&var56,&var281,&var1217,&vainSBool,&internal1_m1654_q0};
_S_rs  S_rs_1656_1 = {&var39,&var280,&var1218,&vainSBool,&internal1_m1656_q0};
_S_rs  S_rs_1652_1 = {&var45,&var282,&var1219,&vainSBool,&internal1_m1652_q0};
_S_rs  S_rs_1650_1 = {&var22,&var283,&var1220,&vainSBool,&internal1_m1650_q0};
_S_rs  S_rs_2065_1 = {&var136,&var483,&var1221,&vainSBool,&internal1_m2065_q0};
_S_rs  S_rs_2061_1 = {&var137,&var484,&var1222,&vainSBool,&internal1_m2061_q0};
_S_equz_p  S_equz_p_297_1 = {&var1065,&iRM_0_,&var1223};
_S_noto  S_noto_2066_1 = {&var1221,&var1224};
_S_noto  S_noto_2057_1 = {&var398,&var1225};
_S_noto  S_noto_2041_1 = {&var1227,&var1226};
_S_rs  S_rs_2040_1 = {&var76,&var480,&var1227,&vainSBool,&internal1_m2040_q0};
_S_noto  S_noto_2029_1 = {&var1229,&var1228};
_S_rs  S_rs_2028_1 = {&var78,&var477,&var1229,&vainSBool,&internal1_m2028_q0};
_S_noto  S_noto_2062_1 = {&var1222,&var1230};
_S_noto  S_noto_2053_1 = {&var397,&var1231};
_S_noto  S_noto_1962_1 = {&var1233,&var1232};
_S_rs  S_rs_1961_1 = {&var372,&var475,&var1233,&vainSBool,&internal1_m1961_q0};
_S_noto  S_noto_1951_1 = {&var1192,&var1234};
_S_noto  S_noto_1957_1 = {&var395,&var1235};
_S_noto  S_noto_1945_1 = {&var396,&var1236};
_S_rs  S_rs_1646_1 = {&var55,&var285,&var1237,&vainSBool,&internal1_m1646_q0};
_S_rs  S_rs_1648_1 = {&var21,&var284,&var1238,&vainSBool,&internal1_m1648_q0};
_S_rs  S_rs_1632_1 = {&var36,&var270,&var1239,&vainSBool,&internal1_m1632_q0};
_S_rs  S_rs_1630_1 = {&var54,&var271,&var1240,&vainSBool,&internal1_m1630_q0};
_S_rs  S_rs_1628_1 = {&var35,&var272,&var1241,&vainSBool,&internal1_m1628_q0};
_S_rs  S_rs_1626_1 = {&var53,&var273,&var1242,&vainSBool,&internal1_m1626_q0};
_S_noto  S_noto_1750_1 = {&B3IS22LDU,&var1243};
_S_noto  S_noto_1749_1 = {&A3IS22LDU,&var1244};
_S_noto  S_noto_1748_1 = {&B2IS12LDU,&var1245};
_S_noto  S_noto_1747_1 = {&A2IS12LDU,&var1246};
_S_noto  S_noto_1746_1 = {&B1IS12LDU,&var1247};
_S_noto  S_noto_1745_1 = {&A1IS12LDU,&var1248};
_S_noto  S_noto_1775_1 = {&B3IS21LDU,&var1249};
_S_noto  S_noto_1769_1 = {&B2IS21LDU,&var1250};
_S_noto  S_noto_1774_1 = {&A3IS21LDU,&var1251};
_S_noto  S_noto_1772_1 = {&B4IS21LDU,&var1252};
_S_noto  S_noto_1773_1 = {&A4IS21LDU,&var1253};
_S_andn  S_andn_1758_1 = {array_m1758_x_1,&iRM_17_,&var1254};
_S_noto  S_noto_1767_1 = {&B1IS21LDU,&var1255};
_S_noto  S_noto_1768_1 = {&A2IS21LDU,&var1256};
_S_noto  S_noto_1766_1 = {&A1IS21LDU,&var1257};
_S_rs  S_rs_1625_1 = {&var1262,&var274,&var1258,&vainSBool,&internal1_m1625_q0};
_S_rs  S_rs_1623_1 = {&var37,&var275,&var1259,&vainSBool,&internal1_m1623_q0};
_S_rs  S_rs_1622_1 = {&var1262,&var276,&var1260,&vainSBool,&internal1_m1622_q0};
_S_rs  S_rs_1620_1 = {&var20,&var277,&var1261,&vainSBool,&internal1_m1620_q0};
_S_newstage  S_newstage_2087_1 = {&var1274,&var1268,&var1273,&var1267,&var1262};
_S_samhd  S_samhd_2089_1 = {&var528,&var529,&var529,&var1259,&var1258,&var1259,&var1258,&B9IS11LDU,&B9IS11LDU,&B9IS21LDU,&B9IS21LDU,&bRM_1_,&fEM_A9UZ05RDU,&fEM_A9UZ03RDU,&fEM_A9UZ04RDU,&var1263,&var1264,&vainSBool,&var1265,&var1266,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1267,&var1268,&internal1_m2089_DvUp0,&internal1_m2089_DvDw0,&internal1_m2089_FDvUp0,&internal1_m2089_FDvDw0,&internal1_m2089_BlDv0,&internal1_m2089_Pkv0,&internal1_m2089_Pkav0,&internal1_m2089_Zkv0,&internal1_m2089_Zkav0,&internal1_m2089_txNm,&internal1_m2089_txSm,&internal1_m2089_txHr,&internal1_m2089_txLd,&internal1_m2089_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_2083_1 = {&var528,&var530,&var530,&var1261,&var1260,&var1261,&var1260,&A9IS11LDU,&A9IS11LDU,&A9IS21LDU,&A9IS21LDU,&bRM_1_,&fEM_A9UZ05RDU,&fEM_A9UZ03RDU,&fEM_A9UZ04RDU,&var1269,&var1270,&vainSBool,&var1271,&var1272,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1273,&var1274,&internal1_m2083_DvUp0,&internal1_m2083_DvDw0,&internal1_m2083_FDvUp0,&internal1_m2083_FDvDw0,&internal1_m2083_BlDv0,&internal1_m2083_Pkv0,&internal1_m2083_Pkav0,&internal1_m2083_Zkv0,&internal1_m2083_Zkav0,&internal1_m2083_txNm,&internal1_m2083_txSm,&internal1_m2083_txHr,&internal1_m2083_txLd,&internal1_m2083_fef,&bFirstEnterFlag};
_S_orni  S_orni_1402_1 = {array_m1402_x_1,&iRM_5_,&var1275,&var1276};
_S_noto  S_noto_78_1 = {&var400,&var1277};
_S_maz  S_maz_303_1 = {array_m303_x_1,&R0MW12IP1,&iRM_3_,&var1278};
_S_maz  S_maz_294_1 = {array_m294_x_1,&R0MW12IP1,&iRM_3_,&var1279};
_S_rs  S_rs_1476_1 = {&var541,&var1018,&var1280,&vainSBool,&internal1_m1476_q0};
_S_kvf  S_kvf_1479_1 = {&var1280,&var538,&fRM_0_0,&var1281,&vainSInt,&vainSInt,&internal1_m1479_x0,&internal1_m1479_y0,&bFirstEnterFlag};
_S_kvf  S_kvf_1901_1 = {&var455,&var443,&fRM_0_0,&var1282,&vainSInt,&vainSInt,&internal1_m1901_x0,&internal1_m1901_y0,&bFirstEnterFlag};
_S_kvf  S_kvf_1862_1 = {&var415,&var412,&fRM_0_0,&var1283,&vainSInt,&vainSInt,&internal1_m1862_x0,&internal1_m1862_y0,&bFirstEnterFlag};
_S_equz_p  S_equz_p_37_1 = {&R0MW13IP1,&iRM_1_,&var1284};
_S_noto  S_noto_34_1 = {&var1287,&var1285};
_S_equz_p  S_equz_p_41_1 = {&R0MW13IP1,&iRM_2_,&var1286};
_S_equz_p  S_equz_p_32_1 = {&R0MW13IP1,&iRM_3_,&var1287};
_S_noto  S_noto_1903_1 = {&var1133,&var1288};
_S_rs  S_rs_279_1 = {&var828,&var829,&var1289,&vainSBool,&internal1_m279_q0};
_S_orn  S_orn_590_1 = {array_m590_x_1,&iRM_5_,&var1290};
_S_noto  S_noto_1003_1 = {&lEM_R0MD01LC1,&var1291};
_S_rs  S_rs_994_1 = {&var605,&var921,&var1292,&vainSBool,&internal1_m994_q0};
_S_rs  S_rs_621_1 = {&var783,&var785,&var1293,&vainSBool,&internal1_m621_q0};
_S_noto  S_noto_1382_1 = {&var964,&var1294};
_S_orn  S_orn_1361_1 = {array_m1361_x_1,&iRM_8_,&var1295};
_S_noto  S_noto_1360_1 = {&var1463,&var1296};
_S_noto  S_noto_1359_1 = {&var1473,&var1297};
_S_noto  S_noto_1343_1 = {&var965,&var1298};
_S_noto  S_noto_1351_1 = {&R8IS11LDU,&var1299};
_S_charint  S_charint_1288_1 = {&var1302,&var1300};
_S_ornc  S_ornc_1296_1 = {array_m1296_x_1,&iRM_3_,&var1301,&var1302};
_S_fsumz  S_fsumz_1289_1 = {&var1300,&iRM_1_,&var1303};
_S_cnshd  S_cnshd_1298_1 = {&R0MD34LP1,&var1732,&var995,&var319,&var1301,&var650,&var646,&iRM_1_,array_m1298_Lt_fw_1,array_m1298_Vr_fw_1,&iRM_1_,array_m1298_Lt_bw_1,array_m1298_Vr_bw_1,&fEM_A3UC08RDU,&fEM_A3UC07RDU,&fEM_A3UL01RDU,&fEM_A3UC02RDU,&var1304,&vainSBool,&var1305,&var1306,&var1307,&var1308,&var1309,&var1310,&var1311,&var1312,&var1313,&var1314,&internal1_m1298_X0,&internal1_m1298_t0,&internal1_m1298_BLDv0};
_S_zpfs  S_zpfs_1317_1 = {&var1323,&fRM_2_0,&var1315,&internal1_m1317_tx,&internal1_m1317_y0};
_S_zpfs  S_zpfs_1319_1 = {&var1322,&fRM_3_0,&var1316,&internal1_m1319_tx,&internal1_m1319_y0};
_S_fnapb  S_fnapb_1326_1 = {&var1732,&var995,&var649,&R0MD34LP1,&var1306,&var1313,&fEM_B8UV04RDU,&fEM_A3UV01RDU,&fEM_A3UV02RDU,&fEM_A3UC06RDU,&fEM_A3UC05RDU,&iRM_60_,&fEM_A3UL04RDU,&fEM_A3UL05RDU,&fEM_A3UL03RDU,&var1317,&var1318,&var1319,&var1320,&var1321,&var1322,&var1323,&vainSFloat,&internal1_m1326_xptr,array_m1326_x0_1,array_m1326_tim0_1,&internal1_m1326_sumtim,&internal1_m1326_StSpeed,&internal1_m1326_Vz0,&internal1_m1326_flRazg,&internal1_m1326_DelSp,&internal1_m1326_z0,&internal1_m1326_txZS,&internal1_m1326_tx,&internal1_m1326_txd,&internal1_m1326_txMBl,&internal1_m1326_txBl,&internal1_m1326_Speed0,&internal1_m1326_xz0,&internal1_m1326_tz0,&internal1_m1326_Shift0,&internal1_m1326_ShCntlSp0,&internal1_m1326_ShiftControl,&bFirstEnterFlag};
_S_newstage  S_newstage_904_1 = {&var1333,&var1301,&var1336,&var1304,&var1324};
_S_rs  S_rs_619_1 = {&var784,&var788,&var1325,&vainSBool,&internal1_m619_q0};
_S_noto  S_noto_981_1 = {&var949,&var1326};
_S_orn  S_orn_960_1 = {array_m960_x_1,&iRM_8_,&var1327};
_S_noto  S_noto_959_1 = {&var1463,&var1328};
_S_noto  S_noto_958_1 = {&var1473,&var1329};
_S_noto  S_noto_942_1 = {&var965,&var1330};
_S_noto  S_noto_950_1 = {&R8IS11LDU,&var1331};
_S_charint  S_charint_882_1 = {&var1334,&var1332};
_S_ornc  S_ornc_890_1 = {array_m890_x_1,&iRM_3_,&var1333,&var1334};
_S_fsumz  S_fsumz_883_1 = {&var1332,&iRM_1_,&var1335};
_S_cnshd  S_cnshd_892_1 = {&R0MD34LP1,&var1735,&var994,&var323,&var1333,&var685,&var686,&iRM_1_,array_m892_Lt_fw_1,array_m892_Vr_fw_1,&iRM_1_,array_m892_Lt_bw_1,array_m892_Vr_bw_1,&fEM_A3UC08RDU,&fEM_A3UC07RDU,&fEM_A3UL01RDU,&fEM_A3UC02RDU,&var1336,&vainSBool,&var1337,&var1338,&var1339,&var1340,&var1341,&var1342,&var1343,&var1344,&var1345,&var1346,&internal1_m892_X0,&internal1_m892_t0,&internal1_m892_BLDv0};
_S_zpfs  S_zpfs_916_1 = {&var1355,&fRM_2_0,&var1347,&internal1_m916_tx,&internal1_m916_y0};
_S_zpfs  S_zpfs_918_1 = {&var1354,&fRM_3_0,&var1348,&internal1_m918_tx,&internal1_m918_y0};
_S_fnapb  S_fnapb_925_1 = {&var1735,&var994,&var684,&R0MD34LP1,&var1338,&var1345,&fEM_B8UV04RDU,&fEM_A3UV01RDU,&fEM_A3UV02RDU,&fEM_A3UC06RDU,&fEM_A3UC05RDU,&iRM_60_,&fEM_A3UL04RDU,&fEM_A3UL05RDU,&fEM_A3UL03RDU,&var1349,&var1350,&var1351,&var1352,&var1353,&var1354,&var1355,&vainSFloat,&internal1_m925_xptr,array_m925_x0_1,array_m925_tim0_1,&internal1_m925_sumtim,&internal1_m925_StSpeed,&internal1_m925_Vz0,&internal1_m925_flRazg,&internal1_m925_DelSp,&internal1_m925_z0,&internal1_m925_txZS,&internal1_m925_tx,&internal1_m925_txd,&internal1_m925_txMBl,&internal1_m925_txBl,&internal1_m925_Speed0,&internal1_m925_xz0,&internal1_m925_tz0,&internal1_m925_Shift0,&internal1_m925_ShCntlSp0,&internal1_m925_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_572_1 = {&var964,&var1356};
_S_noto  S_noto_545_1 = {&var1463,&var1357};
_S_noto  S_noto_544_1 = {&var1473,&var1358};
_S_noto  S_noto_529_1 = {&var965,&var1359};
_S_noto  S_noto_536_1 = {&R8IS11LDU,&var1360};
_S_charint  S_charint_481_1 = {&var1363,&var1361};
_S_ornc  S_ornc_487_1 = {array_m487_x_1,&iRM_3_,&var1362,&var1363};
_S_fsumz  S_fsumz_482_1 = {&var1361,&iRM_1_,&var1364};
_S_cnshd  S_cnshd_490_1 = {&R0MD34LP1,&var1745,&var996,&var327,&var1362,&var756,&var750,&iRM_2_,array_m490_Lt_fw_1,array_m490_Vr_fw_1,&iRM_1_,array_m490_Lt_bw_1,array_m490_Vr_bw_1,&fEM_A1UC08RDU,&fEM_A1UC07RDU,&fEM_A1UL01RDU,&fEM_A1UC02RDU,&var1365,&vainSBool,&var1366,&var1367,&var1368,&var1369,&var1370,&var1371,&var1372,&var1373,&var1374,&var1375,&internal1_m490_X0,&internal1_m490_t0,&internal1_m490_BLDv0};
_S_zpfs  S_zpfs_510_1 = {&var1384,&fRM_2_0,&var1376,&internal1_m510_tx,&internal1_m510_y0};
_S_zpfs  S_zpfs_512_1 = {&var1383,&fRM_3_0,&var1377,&internal1_m512_tx,&internal1_m512_y0};
_S_fnapb  S_fnapb_517_1 = {&var1745,&var996,&var754,&R0MD34LP1,&var1367,&var1374,&fEM_B8UV04RDU,&fEM_A1UV01RDU,&fEM_A1UV02RDU,&fEM_A1UC06RDU,&fEM_A1UC05RDU,&iRM_150_,&fEM_A1UL04RDU,&fEM_A1UL05RDU,&fEM_A1UL03RDU,&var1378,&var1379,&var1380,&var1381,&var1382,&var1383,&var1384,&vainSFloat,&internal1_m517_xptr,array_m517_x0_1,array_m517_tim0_1,&internal1_m517_sumtim,&internal1_m517_StSpeed,&internal1_m517_Vz0,&internal1_m517_flRazg,&internal1_m517_DelSp,&internal1_m517_z0,&internal1_m517_txZS,&internal1_m517_tx,&internal1_m517_txd,&internal1_m517_txMBl,&internal1_m517_txBl,&internal1_m517_Speed0,&internal1_m517_xz0,&internal1_m517_tz0,&internal1_m517_Shift0,&internal1_m517_ShCntlSp0,&internal1_m517_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_637_1 = {&R0MD33LP1,&var1385};
_S_noto  S_noto_257_1 = {&var949,&var1386};
_S_newstage  S_newstage_205_1 = {&var1395,&var1362,&var1398,&var1365,&var1387};
_S_rs  S_rs_616_1 = {&var779,&var791,&var1388,&vainSBool,&internal1_m616_q0};
_S_orn  S_orn_228_1 = {array_m228_x_1,&iRM_12_,&var1389};
_S_noto  S_noto_227_1 = {&var1463,&var1390};
_S_noto  S_noto_226_1 = {&var1473,&var1391};
_S_noto  S_noto_211_1 = {&var965,&var1392};
_S_noto  S_noto_218_1 = {&R8IS11LDU,&var1393};
_S_charint  S_charint_157_1 = {&var1396,&var1394};
_S_ornc  S_ornc_163_1 = {array_m163_x_1,&iRM_3_,&var1395,&var1396};
_S_fsumz  S_fsumz_158_1 = {&var1394,&iRM_1_,&var1397};
_S_cnshd  S_cnshd_168_1 = {&R0MD34LP1,&var1723,&var997,&var331,&var1395,&var736,&var729,&iRM_2_,array_m168_Lt_fw_1,array_m168_Vr_fw_1,&iRM_1_,array_m168_Lt_bw_1,array_m168_Vr_bw_1,&fEM_A1UC08RDU,&fEM_A1UC07RDU,&fEM_A1UL01RDU,&fEM_A1UC02RDU,&var1398,&vainSBool,&var1399,&var1400,&var1401,&var1402,&var1403,&var1404,&var1405,&var1406,&var1407,&var1408,&internal1_m168_X0,&internal1_m168_t0,&internal1_m168_BLDv0};
_S_fnapb  S_fnapb_197_1 = {&var1723,&var997,&var732,&R0MD34LP1,&var1400,&var1407,&fEM_B8UV04RDU,&fEM_A1UV01RDU,&fEM_A1UV02RDU,&fEM_A1UC06RDU,&fEM_A1UC05RDU,&iRM_150_,&fEM_A1UL04RDU,&fEM_A1UL05RDU,&fEM_A1UL03RDU,&var1409,&var1410,&var1411,&var1412,&var1413,&var1414,&var1415,&vainSFloat,&internal1_m197_xptr,array_m197_x0_1,array_m197_tim0_1,&internal1_m197_sumtim,&internal1_m197_StSpeed,&internal1_m197_Vz0,&internal1_m197_flRazg,&internal1_m197_DelSp,&internal1_m197_z0,&internal1_m197_txZS,&internal1_m197_tx,&internal1_m197_txd,&internal1_m197_txMBl,&internal1_m197_txBl,&internal1_m197_Speed0,&internal1_m197_xz0,&internal1_m197_tz0,&internal1_m197_Shift0,&internal1_m197_ShCntlSp0,&internal1_m197_ShiftControl,&bFirstEnterFlag};
_S_rs  S_rs_642_1 = {&var790,&var793,&var1416,&vainSBool,&internal1_m642_q0};
_S_newstage  S_newstage_457_1 = {&var1435,&var1426,&var1434,&var1425,&var1417};
_S_samhd  S_samhd_461_1 = {&R0MD34LP1,&var759,&var759,&var382,&var381,&R2VS12LDU,&R2VS22LDU,&R2IS11LDU,&R2IS11LDU,&R2IS21LDU,&R2IS21LDU,&bRM_0_,&fEM_R1UZ05RDU,&fEM_R1UZ03RDU,&fEM_R1UZ04RDU,&var1418,&var1419,&var1420,&var1421,&var1422,&var1423,&vainSBool,&vainSBool,&var1424,&var1425,&var1426,&internal1_m461_DvUp0,&internal1_m461_DvDw0,&internal1_m461_FDvUp0,&internal1_m461_FDvDw0,&internal1_m461_BlDv0,&internal1_m461_Pkv0,&internal1_m461_Pkav0,&internal1_m461_Zkv0,&internal1_m461_Zkav0,&internal1_m461_txNm,&internal1_m461_txSm,&internal1_m461_txHr,&internal1_m461_txLd,&internal1_m461_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_455_1 = {&R0MD34LP1,&var760,&var760,&var380,&var379,&R1VS12LDU,&R1VS22LDU,&R1IS11LDU,&R1IS11LDU,&R1IS21LDU,&R1IS21LDU,&bRM_0_,&fEM_R1UZ05RDU,&fEM_R1UZ03RDU,&fEM_R1UZ04RDU,&var1427,&var1428,&var1429,&var1430,&var1431,&var1432,&vainSBool,&vainSBool,&var1433,&var1434,&var1435,&internal1_m455_DvUp0,&internal1_m455_DvDw0,&internal1_m455_FDvUp0,&internal1_m455_FDvDw0,&internal1_m455_BlDv0,&internal1_m455_Pkv0,&internal1_m455_Pkav0,&internal1_m455_Zkv0,&internal1_m455_Zkav0,&internal1_m455_txNm,&internal1_m455_txSm,&internal1_m455_txHr,&internal1_m455_txLd,&internal1_m455_fef,&bFirstEnterFlag};
_S_orn  S_orn_865_1 = {array_m865_x_1,&iRM_10_,&var1436};
_S_noto  S_noto_864_1 = {&var1463,&var1437};
_S_noto  S_noto_863_1 = {&var1473,&var1438};
_S_noto  S_noto_845_1 = {&var965,&var1439};
_S_noto  S_noto_855_1 = {&R8IS11LDU,&var1440};
_S_charint  S_charint_798_1 = {&var1443,&var1441};
_S_ornc  S_ornc_806_1 = {array_m806_x_1,&iRM_3_,&var1442,&var1443};
_S_fsumz  S_fsumz_799_1 = {&var1441,&iRM_1_,&var1444};
_S_cnshd  S_cnshd_808_1 = {&R0MD34LP1,&var1738,&var993,&var993,&var1442,&var709,&var623,&iRM_2_,array_m808_Lt_fw_1,array_m808_Vr_fw_1,&iRM_1_,array_m808_Lt_bw_1,array_m808_Vr_bw_1,&fEM_A2UC08RDU,&fEM_A2UC07RDU,&fEM_A2UL01RDU,&fEM_A2UC02RDU,&var1445,&vainSBool,&var1446,&var1447,&var1448,&var1449,&var1450,&var1451,&var1452,&var1453,&var1454,&var1455,&internal1_m808_X0,&internal1_m808_t0,&internal1_m808_BLDv0};
_S_fnapb  S_fnapb_831_1 = {&var1738,&var993,&var705,&R0MD34LP1,&var1447,&var1454,&fEM_B8UV04RDU,&fEM_A2UV01RDU,&fEM_A2UV02RDU,&fEM_A2UC06RDU,&fEM_A2UC05RDU,&iRM_80_,&fEM_A2UL04RDU,&fEM_A2UL05RDU,&fEM_A2UL83RDU,&var1456,&var1457,&var1458,&var1459,&var1460,&var1461,&var1462,&vainSFloat,&internal1_m831_xptr,array_m831_x0_1,array_m831_tim0_1,&internal1_m831_sumtim,&internal1_m831_StSpeed,&internal1_m831_Vz0,&internal1_m831_flRazg,&internal1_m831_DelSp,&internal1_m831_z0,&internal1_m831_txZS,&internal1_m831_tx,&internal1_m831_txd,&internal1_m831_txMBl,&internal1_m831_txBl,&internal1_m831_Speed0,&internal1_m831_xz0,&internal1_m831_tz0,&internal1_m831_Shift0,&internal1_m831_ShCntlSp0,&internal1_m831_ShiftControl,&bFirstEnterFlag};
_S_cnshd  S_cnshd_1580_1 = {&R0MD34LP1,&var1729,&var315,&var315,&var532,&var535,&lRM_1_,&iRM_1_,array_m1580_Lt_fw_1,array_m1580_Vr_fw_1,&iRM_1_,array_m1580_Lt_bw_1,array_m1580_Vr_bw_1,&fEM_B8UC01RDU,&fEM_B8UC02RDU,&fEM_B8UL01RDU,&fRM_0_0,&var1463,&vainSBool,&vainSFloat,&var1464,&var1465,&var1466,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1467,&internal1_m1580_X0,&internal1_m1580_t0,&internal1_m1580_BLDv0};
_S_newstage  S_newstage_1237_1 = {&var1481,&var1442,&var1486,&var1445,&var1468};
_S_orn  S_orn_1271_1 = {array_m1271_x_1,&iRM_10_,&var1469};
_S_orn  S_orn_146_1 = {array_m146_x_1,&iRM_5_,&var1470};
_S_noto  S_noto_1270_1 = {&var1463,&var1471};
_S_noto  S_noto_1269_1 = {&var1473,&var1472};
_S_cnshd  S_cnshd_1113_1 = {&R0MD34LP1,&var1726,&var315,&var315,&var850,&var533,&lRM_1_,&iRM_1_,array_m1113_Lt_fw_1,array_m1113_Vr_fw_1,&iRM_1_,array_m1113_Lt_bw_1,array_m1113_Vr_bw_1,&fEM_B8UC01RDU,&fEM_B8UC02RDU,&fEM_B8UL01RDU,&fRM_0_0,&var1473,&vainSBool,&vainSFloat,&var1474,&var1475,&var1476,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1477,&internal1_m1113_X0,&internal1_m1113_t0,&internal1_m1113_BLDv0};
_S_noto  S_noto_1251_1 = {&var965,&var1478};
_S_noto  S_noto_1261_1 = {&R8IS11LDU,&var1479};
_S_charint  S_charint_1187_1 = {&var1482,&var1480};
_S_ornc  S_ornc_1195_1 = {array_m1195_x_1,&iRM_3_,&var1481,&var1482};
_S_noto  S_noto_601_1 = {&lEM_R0MD01LC1,&var1483};
_S_fsumz  S_fsumz_1188_1 = {&var1480,&iRM_1_,&var1484};
_S_rs  S_rs_614_1 = {&var801,&var803,&var1485,&vainSBool,&internal1_m614_q0};
_S_cnshd  S_cnshd_1197_1 = {&R0MD34LP1,&var1741,&var992,&var992,&var1481,&var626,&var619,&iRM_2_,array_m1197_Lt_fw_1,array_m1197_Vr_fw_1,&iRM_1_,array_m1197_Lt_bw_1,array_m1197_Vr_bw_1,&fEM_A2UC08RDU,&fEM_A2UC07RDU,&fEM_A2UL01RDU,&fEM_A2UC02RDU,&var1486,&vainSBool,&var1487,&var1488,&var1489,&var1490,&var1491,&var1492,&var1493,&var1494,&var1495,&var1496,&internal1_m1197_X0,&internal1_m1197_t0,&internal1_m1197_BLDv0};
_S_zpfs  S_zpfs_1227_1 = {&var1505,&fRM_2_0,&var1497,&internal1_m1227_tx,&internal1_m1227_y0};
_S_zpfs  S_zpfs_1226_1 = {&var1504,&fRM_3_0,&var1498,&internal1_m1226_tx,&internal1_m1226_y0};
_S_fnapb  S_fnapb_1230_1 = {&var1741,&var992,&var627,&R0MD34LP1,&var1488,&var1495,&fEM_B8UV04RDU,&fEM_A2UV01RDU,&fEM_A2UV02RDU,&fEM_A2UC06RDU,&fEM_A2UC05RDU,&iRM_80_,&fEM_A2UL04RDU,&fEM_A2UL05RDU,&fEM_A2UL03RDU,&var1499,&var1500,&var1501,&var1502,&var1503,&var1504,&var1505,&vainSFloat,&internal1_m1230_xptr,array_m1230_x0_1,array_m1230_tim0_1,&internal1_m1230_sumtim,&internal1_m1230_StSpeed,&internal1_m1230_Vz0,&internal1_m1230_flRazg,&internal1_m1230_DelSp,&internal1_m1230_z0,&internal1_m1230_txZS,&internal1_m1230_tx,&internal1_m1230_txd,&internal1_m1230_txMBl,&internal1_m1230_txBl,&internal1_m1230_Speed0,&internal1_m1230_xz0,&internal1_m1230_tz0,&internal1_m1230_Shift0,&internal1_m1230_ShCntlSp0,&internal1_m1230_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_1565_1 = {&R8IS11LDU,&var1506};
_S_rs  S_rs_634_1 = {&var804,&var805,&var1507,&vainSBool,&internal1_m634_q0};
_S_zpfs  S_zpfs_1593_1 = {&var1518,&fRM_2_0,&var1508,&internal1_m1593_tx,&internal1_m1593_y0};
_S_zpfs  S_zpfs_1597_1 = {&var1517,&fRM_3_0,&var1509,&internal1_m1597_tx,&internal1_m1597_y0};
_S_samhd  S_samhd_1583_1 = {&R0MD34LP1,&var535,&var535,&var1465,&var1466,&var1512,&var1513,&A8IS12LDU,&A8IS12LDU,&A8IS22LDU,&A8IS22LDU,&bRM_3_,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&fEM_B8UL07RDU,&vainSBool,&vainSBool,&var1510,&var1511,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,&internal1_m1583_DvUp0,&internal1_m1583_DvDw0,&internal1_m1583_FDvUp0,&internal1_m1583_FDvDw0,&internal1_m1583_BlDv0,&internal1_m1583_Pkv0,&internal1_m1583_Pkav0,&internal1_m1583_Zkv0,&internal1_m1583_Zkav0,&internal1_m1583_txNm,&internal1_m1583_txSm,&internal1_m1583_txHr,&internal1_m1583_txLd,&internal1_m1583_fef,&bFirstEnterFlag};
_S_fnapb  S_fnapb_1600_1 = {&var1729,&var315,&var531,&R0MD34LP1,&var1464,&fEM_B8UV03RDU,&fEM_B8UV04RDU,&fEM_B8UV01RDU,&fEM_B8UV02RDU,&fEM_B8UC06RDU,&fEM_B8UC05RDU,&iRM_20_,&fEM_B8UL04RDU,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&var1512,&var1513,&var1514,&var1515,&var1516,&var1517,&var1518,&vainSFloat,&internal1_m1600_xptr,array_m1600_x0_1,array_m1600_tim0_1,&internal1_m1600_sumtim,&internal1_m1600_StSpeed,&internal1_m1600_Vz0,&internal1_m1600_flRazg,&internal1_m1600_DelSp,&internal1_m1600_z0,&internal1_m1600_txZS,&internal1_m1600_tx,&internal1_m1600_txd,&internal1_m1600_txMBl,&internal1_m1600_txBl,&internal1_m1600_Speed0,&internal1_m1600_xz0,&internal1_m1600_tz0,&internal1_m1600_Shift0,&internal1_m1600_ShCntlSp0,&internal1_m1600_ShiftControl,&bFirstEnterFlag};
_S_zpfs  S_zpfs_1128_1 = {&var1535,&fRM_2_0,&var1519,&internal1_m1128_tx,&internal1_m1128_y0};
_S_zpfs  S_zpfs_1132_1 = {&var1534,&fRM_3_0,&var1520,&internal1_m1132_tx,&internal1_m1132_y0};
_S_noto  S_noto_1097_1 = {&R8IS11LDU,&var1521};
_S_orn  S_orn_1083_1 = {array_m1083_x_1,&iRM_8_,&var1522};
_S_noto  S_noto_603_1 = {&var1526,&var1523};
_S_rs  S_rs_624_1 = {&var806,&var807,&var1524,&vainSBool,&internal1_m624_q0};
_S_orn  S_orn_591_1 = {array_m591_x_1,&iRM_18_,&var1525};
_S_rs  S_rs_589_1 = {&var1290,&var922,&var1526,&vainSBool,&internal1_m589_q0};
_S_samhd  S_samhd_1118_1 = {&R0MD34LP1,&var533,&var533,&var1475,&var1476,&var1529,&var1530,&var158,&var158,&var157,&var157,&bRM_3_,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&fEM_B8UL07RDU,&vainSBool,&vainSBool,&var1527,&var1528,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,&internal1_m1118_DvUp0,&internal1_m1118_DvDw0,&internal1_m1118_FDvUp0,&internal1_m1118_FDvDw0,&internal1_m1118_BlDv0,&internal1_m1118_Pkv0,&internal1_m1118_Pkav0,&internal1_m1118_Zkv0,&internal1_m1118_Zkav0,&internal1_m1118_txNm,&internal1_m1118_txSm,&internal1_m1118_txHr,&internal1_m1118_txLd,&internal1_m1118_fef,&bFirstEnterFlag};
_S_fnapb  S_fnapb_1136_1 = {&var1726,&var315,&var849,&R0MD34LP1,&var1474,&fEM_B8UV03RDU,&fEM_B8UV04RDU,&fEM_B8UV01RDU,&fEM_B8UV02RDU,&fEM_B8UC06RDU,&fEM_B8UC05RDU,&iRM_20_,&fEM_B8UL04RDU,&fEM_B8UL06RDU,&fEM_B8UL03RDU,&var1529,&var1530,&var1531,&var1532,&var1533,&var1534,&var1535,&vainSFloat,&internal1_m1136_xptr,array_m1136_x0_1,array_m1136_tim0_1,&internal1_m1136_sumtim,&internal1_m1136_StSpeed,&internal1_m1136_Vz0,&internal1_m1136_flRazg,&internal1_m1136_DelSp,&internal1_m1136_z0,&internal1_m1136_txZS,&internal1_m1136_tx,&internal1_m1136_txd,&internal1_m1136_txMBl,&internal1_m1136_txBl,&internal1_m1136_Speed0,&internal1_m1136_xz0,&internal1_m1136_tz0,&internal1_m1136_Shift0,&internal1_m1136_ShCntlSp0,&internal1_m1136_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_714_1 = {&A5IS21LDU,&var1536};
_S_vmemb  S_vmemb_737_1 = {&var1538,&var1537,&internal1_m737_x0};
_S_noto  S_noto_745_1 = {&var159,&var1538};
_S_vmemb  S_vmemb_706_1 = {&var1536,&var1539,&internal1_m706_x0};
_S_vmemb  S_vmemb_669_1 = {&var1554,&var1540,&internal1_m669_x0};
_S_newstage  S_newstage_780_1 = {&var1598,&var1589,&var1597,&var1588,&var1541};
_S_newstage  S_newstage_1168_1 = {&var1580,&var1571,&var1579,&var1570,&var1542};
_S_newstage  S_newstage_386_1 = {&var1625,&var1616,&var1624,&var1615,&var1543};
_S_noto  S_noto_756_1 = {&var160,&var1544};
_S_rs  S_rs_762_1 = {&var870,&var1543,&var1545,&vainSBool,&internal1_m762_q0};
_S_rs  S_rs_757_1 = {&var871,&var971,&var1546,&vainSBool,&internal1_m757_q0};
_S_noto  S_noto_749_1 = {&var1627,&var1547};
_S_noto  S_noto_747_1 = {&var1628,&var1548};
_S_rs  S_rs_725_1 = {&var875,&var1543,&var1549,&vainSBool,&internal1_m725_q0};
_S_rs  S_rs_727_1 = {&var874,&var1541,&var1550,&vainSBool,&internal1_m727_q0};
_S_rs  S_rs_738_1 = {&var941,&var880,&var1551,&vainSBool,&internal1_m738_q0};
_S_rs  S_rs_750_1 = {&var872,&var878,&var1552,&vainSBool,&internal1_m750_q0};
_S_noto  S_noto_705_1 = {&var160,&var1553};
_S_noto  S_noto_661_1 = {&var159,&var1554};
_S_noto  S_noto_417_1 = {&R8IS11LDU,&var1555};
_S_orn  S_orn_431_1 = {array_m431_x_1,&iRM_7_,&var1556};
_S_orn  S_orn_413_1 = {array_m413_x_1,&iRM_7_,&var1557};
_S_rs  S_rs_729_1 = {&var879,&var884,&var1558,&vainSBool,&internal1_m729_q0};
_S_noto  S_noto_154_1 = {&B2IS12LDU,&var1559};
_S_noto  S_noto_143_1 = {&A2IS12LDU,&var1560};
_S_noto  S_noto_144_1 = {&B1IS12LDU,&var1561};
_S_noto  S_noto_152_1 = {&A1IS12LDU,&var1562};
_S_samhd  S_samhd_1174_1 = {&var853,&var854,&var854,&var1163,&var1162,&var1163,&var1162,&B4IS11LDU,&B4IS11LDU,&B4IS21LDU,&B4IS21LDU,&bRM_1_,&fEM_A4UZ05RDU,&fEM_A4UZ03RDU,&fEM_A4UZ04RDU,&var1563,&var1564,&vainSBool,&var1565,&var1566,&vainSBool,&var1567,&var1568,&var1569,&var1570,&var1571,&internal1_m1174_DvUp0,&internal1_m1174_DvDw0,&internal1_m1174_FDvUp0,&internal1_m1174_FDvDw0,&internal1_m1174_BlDv0,&internal1_m1174_Pkv0,&internal1_m1174_Pkav0,&internal1_m1174_Zkv0,&internal1_m1174_Zkav0,&internal1_m1174_txNm,&internal1_m1174_txSm,&internal1_m1174_txHr,&internal1_m1174_txLd,&internal1_m1174_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_1163_1 = {&var853,&var856,&var856,&var1163,&var1162,&var1163,&var1162,&A4IS11LDU,&A4IS11LDU,&A4IS21LDU,&A4IS21LDU,&bRM_1_,&fEM_A4UZ05RDU,&fEM_A4UZ03RDU,&fEM_A4UZ04RDU,&var1572,&var1573,&vainSBool,&var1574,&var1575,&vainSBool,&var1576,&var1577,&var1578,&var1579,&var1580,&internal1_m1163_DvUp0,&internal1_m1163_DvDw0,&internal1_m1163_FDvUp0,&internal1_m1163_FDvDw0,&internal1_m1163_BlDv0,&internal1_m1163_Pkv0,&internal1_m1163_Pkav0,&internal1_m1163_Zkv0,&internal1_m1163_Zkav0,&internal1_m1163_txNm,&internal1_m1163_txSm,&internal1_m1163_txHr,&internal1_m1163_txLd,&internal1_m1163_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_782_1 = {&R0MD34LP1,&var711,&var711,&var972,&var867,&B5VS12LDU,&B5VS22LDU,&B5IS11LDU,&B5IS11LDU,&B5IS21LDU,&B5IS21LDU,&bRM_0_,&fEM_A5UZ05RDU,&fEM_A5UZ03RDU,&fEM_A5UZ04RDU,&var1581,&var1582,&var1583,&var1584,&var1585,&var1586,&vainSBool,&vainSBool,&var1587,&var1588,&var1589,&internal1_m782_DvUp0,&internal1_m782_DvDw0,&internal1_m782_FDvUp0,&internal1_m782_FDvDw0,&internal1_m782_BlDv0,&internal1_m782_Pkv0,&internal1_m782_Pkav0,&internal1_m782_Zkv0,&internal1_m782_Zkav0,&internal1_m782_txNm,&internal1_m782_txSm,&internal1_m782_txHr,&internal1_m782_txLd,&internal1_m782_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_778_1 = {&R0MD34LP1,&var713,&var713,&var972,&var867,&A5VS12LDU,&A5VS22LDU,&A5IS11LDU,&A5IS11LDU,&A5IS21LDU,&A5IS21LDU,&bRM_0_,&fEM_A5UZ05RDU,&fEM_A5UZ03RDU,&fEM_A5UZ04RDU,&var1590,&var1591,&var1592,&var1593,&var1594,&var1595,&vainSBool,&vainSBool,&var1596,&var1597,&var1598,&internal1_m778_DvUp0,&internal1_m778_DvDw0,&internal1_m778_FDvUp0,&internal1_m778_FDvDw0,&internal1_m778_BlDv0,&internal1_m778_Pkv0,&internal1_m778_Pkav0,&internal1_m778_Zkv0,&internal1_m778_Zkav0,&internal1_m778_txNm,&internal1_m778_txSm,&internal1_m778_txHr,&internal1_m778_txLd,&internal1_m778_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_360_1 = {&R0MD34LP1,&var384,&var383,&var876,&var869,&R4VS12LDU,&R4VS22LDU,&R4IS11LDU,&R4IS12LDU,&R4IS21LDU,&R4IS22LDU,&bRM_0_,&fEM_R4UZ05RDU,&fEM_R4UZ03RDU,&fEM_R4UZ04RDU,&var1599,&var1600,&var1601,&var1602,&var1603,&var1604,&vainSBool,&vainSBool,&var1605,&var1606,&vainSBool,&internal1_m360_DvUp0,&internal1_m360_DvDw0,&internal1_m360_FDvUp0,&internal1_m360_FDvDw0,&internal1_m360_BlDv0,&internal1_m360_Pkv0,&internal1_m360_Pkav0,&internal1_m360_Zkv0,&internal1_m360_Zkav0,&internal1_m360_txNm,&internal1_m360_txSm,&internal1_m360_txHr,&internal1_m360_txLd,&internal1_m360_fef,&bFirstEnterFlag};
_S_noto  S_noto_672_1 = {&R8IS11LDU,&var1607};
_S_samhd  S_samhd_389_1 = {&R0MD34LP1,&var1556,&var942,&var948,&var868,&B6VS12LDU,&B6VS22LDU,&B6IS11LDU,&B6IS11LDU,&B6IS21LDU,&B6IS21LDU,&bRM_0_,&fEM_A6UZ05RDU,&fEM_A6UZ03RDU,&fEM_A6UZ04RDU,&var1608,&var1609,&var1610,&var1611,&var1612,&var1613,&vainSBool,&vainSBool,&var1614,&var1615,&var1616,&internal1_m389_DvUp0,&internal1_m389_DvDw0,&internal1_m389_FDvUp0,&internal1_m389_FDvDw0,&internal1_m389_BlDv0,&internal1_m389_Pkv0,&internal1_m389_Pkav0,&internal1_m389_Zkv0,&internal1_m389_Zkav0,&internal1_m389_txNm,&internal1_m389_txSm,&internal1_m389_txHr,&internal1_m389_txLd,&internal1_m389_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_383_1 = {&R0MD34LP1,&var1557,&var943,&var948,&var868,&A6VS12LDU,&A6VS22LDU,&A6IS11LDU,&A6IS11LDU,&A6IS21LDU,&A6IS21LDU,&bRM_0_,&fEM_A6UZ05RDU,&fEM_A6UZ03RDU,&fEM_A6UZ04RDU,&var1617,&var1618,&var1619,&var1620,&var1621,&var1622,&vainSBool,&vainSBool,&var1623,&var1624,&var1625,&internal1_m383_DvUp0,&internal1_m383_DvDw0,&internal1_m383_FDvUp0,&internal1_m383_FDvDw0,&internal1_m383_BlDv0,&internal1_m383_Pkv0,&internal1_m383_Pkav0,&internal1_m383_Zkv0,&internal1_m383_Zkav0,&internal1_m383_txNm,&internal1_m383_txSm,&internal1_m383_txHr,&internal1_m383_txLd,&internal1_m383_fef,&bFirstEnterFlag};
_S_orn  S_orn_761_1 = {array_m761_x_1,&iRM_17_,&var1626};
_S_rs  S_rs_734_1 = {&var882,&var69,&var1627,&vainSBool,&internal1_m734_q0};
_S_rs  S_rs_731_1 = {&var883,&var70,&var1628,&vainSBool,&internal1_m731_q0};
_S_orni  S_orni_132_1 = {array_m132_x_1,&iRM_21_,&var1629,&vainSLong};
_S_equz_p  S_equz_p_74_1 = {&R0MW11IP2,&iRM_6_,&var1630};
_S_equz_p  S_equz_p_72_1 = {&R0MW11IP2,&iRM_5_,&var1631};
_S_equz_p  S_equz_p_70_1 = {&R0MW11IP2,&iRM_4_,&var1632};
_S_equz_p  S_equz_p_69_1 = {&R0MW11IP2,&iRM_3_,&var1633};
_S_equz_p  S_equz_p_68_1 = {&R0MW11IP2,&iRM_2_,&var1634};
_S_equz_p  S_equz_p_65_1 = {&R0MW11IP2,&iRM_1_,&var1635};
_S_equz_p  S_equz_p_61_1 = {&R0MW14IP1,&iRM_3_,&var1636};
_S_equz_p  S_equz_p_55_1 = {&R0MW14IP1,&iRM_1_,&vainSBool};
_S_equz_p  S_equz_p_57_1 = {&R0MW14IP1,&iRM_2_,&var1637};
_S_equz_p  S_equz_p_50_1 = {&R0MW11IP1,&iRM_3_,&var1638};
_S_equz_p  S_equz_p_43_1 = {&R0MW11IP1,&iRM_1_,&var1639};
_S_equz_p  S_equz_p_46_1 = {&R0MW11IP1,&iRM_2_,&var1640};
_S_equz_p  S_equz_p_100_1 = {&R0MW16IP1,&iRM_11_,&var1641};
_S_equz_p  S_equz_p_93_1 = {&R0MW16IP1,&iRM_4_,&var1642};
_S_equz_p  S_equz_p_92_1 = {&R0MW16IP1,&iRM_3_,&var1643};
_S_equz_p  S_equz_p_91_1 = {&R0MW16IP1,&iRM_2_,&var1644};
_S_equz_p  S_equz_p_10_1 = {&R0MW12IP1,&iRM_4_,&var1645};
_S_equz_p  S_equz_p_7_1 = {&R0MW12IP1,&iRM_3_,&var1646};
_S_equz_p  S_equz_p_2_1 = {&R0MW12IP1,&iRM_1_,&var1647};
_S_equz_p  S_equz_p_4_1 = {&R0MW12IP1,&iRM_2_,&var1648};


void ZeroVar()
{
   var1.b=0;
   var2.b=0;
   var3.b=0;
   var4.b=0;
   var5.b=0;
   var6.b=0;
   var7.b=0;
   var8.b=0;
   var9.b=0;
   var10.b=0;
   var11.b=0;
   var12.b=0;
   var13.b=0;
   var14.b=0;
   var15.i=0;
   var16.b=0;
   var17.b=0;
   var18.b=0;
   var19.b=0;
   var20.b=0;
   var21.b=0;
   var22.b=0;
   var23.b=0;
   var24.b=0;
   var25.b=0;
   var26.b=0;
   var27.b=0;
   var28.b=0;
   var29.b=0;
   var30.b=0;
   var31.b=0;
   var32.b=0;
   var33.b=0;
   var34.b=0;
   var35.b=0;
   var36.b=0;
   var37.b=0;
   var38.b=0;
   var39.b=0;
   var40.b=0;
   var41.b=0;
   var42.b=0;
   var43.b=0;
   var44.b=0;
   var45.b=0;
   var46.b=0;
   var47.b=0;
   var48.b=0;
   var49.b=0;
   var50.b=0;
   var51.b=0;
   var52.b=0;
   var53.b=0;
   var54.b=0;
   var55.b=0;
   var56.b=0;
   var57.b=0;
   var58.b=0;
   var59.b=0;
   var60.b=0;
   var61.b=0;
   var62.b=0;
   var63.b=0;
   var64.b=0;
   var65.b=0;
   var66.b=0;
   var67.b=0;
   var68.b=0;
   var69.b=0;
   var70.b=0;
   var71.b=0;
   var72.b=0;
   var73.b=0;
   var74.b=0;
   var75.b=0;
   var76.b=0;
   var77.b=0;
   var78.b=0;
   var79.b=0;
   var80.b=0;
   var81.b=0;
   var82.b=0;
   var83.b=0;
   var84.b=0;
   var85.b=0;
   var86.b=0;
   var87.b=0;
   var88.b=0;
   var89.b=0;
   var90.b=0;
   var91.b=0;
   var92.b=0;
   var93.b=0;
   var94.b=0;
   var95.b=0;
   var96.b=0;
   var97.b=0;
   var98.b=0;
   var99.b=0;
   var100.b=0;
   var101.b=0;
   var102.b=0;
   var103.b=0;
   var104.b=0;
   var105.b=0;
   var106.b=0;
   var107.b=0;
   var108.b=0;
   var109.b=0;
   var110.b=0;
   var111.b=0;
   var112.b=0;
   var113.b=0;
   var114.b=0;
   var115.b=0;
   var116.b=0;
   var117.b=0;
   var118.b=0;
   var119.b=0;
   var120.b=0;
   var121.b=0;
   var122.b=0;
   var123.b=0;
   var124.b=0;
   var125.b=0;
   var126.b=0;
   var127.b=0;
   var128.b=0;
   var129.b=0;
   var130.b=0;
   var131.b=0;
   var132.b=0;
   var133.b=0;
   var134.b=0;
   var135.b=0;
   var136.b=0;
   var137.b=0;
   var138.b=0;
   var139.b=0;
   var140.b=0;
   var141.i=0;
   var142.b=0;
   var143.b=0;
   var144.i=0;
   var145.b=0;
   var146.b=0;
   var147.b=0;
   var148.b=0;
   var149.b=0;
   var150.b=0;
   var151.b=0;
   var152.b=0;
   var153.b=0;
   var154.b=0;
   var155.b=0;
   var156.b=0;
   var157.b=0;
   var158.b=0;
   var159.b=0;
   var160.b=0;
   var161.b=0;
   var162.b=0;
   var163.b=0;
   var164.b=0;
   var165.b=0;
   var166.b=0;
   var167.b=0;
   var168.b=0;
   var169.b=0;
   var170.b=0;
   var171.b=0;
   var172.b=0;
   var173.b=0;
   var174.b=0;
   var175.b=0;
   var176.b=0;
   var177.b=0;
   var178.b=0;
   var179.b=0;
   var180.b=0;
   var181.b=0;
   var182.b=0;
   var183.b=0;
   var184.b=0;
   var185.b=0;
   var186.b=0;
   var187.b=0;
   var188.b=0;
   var189.f=0.0;
   var190.b=0;
   var191.b=0;
   var192.b=0;
   var193.b=0;
   var194.b=0;
   var195.b=0;
   var196.b=0;
   var197.b=0;
   var198.b=0;
   var199.f=0.0;
   var200.f=0.0;
   var201.b=0;
   var202.b=0;
   var203.b=0;
   var204.f=0.0;
   var205.f=0.0;
   var206.b=0;
   var207.b=0;
   var208.f=0.0;
   var209.b=0;
   var210.b=0;
   var211.b=0;
   var212.b=0;
   var213.b=0;
   var214.b=0;
   var215.b=0;
   var216.b=0;
   var217.f=0.0;
   var218.f=0.0;
   var219.f=0.0;
   var220.f=0.0;
   var221.b=0;
   var222.f=0.0;
   var223.f=0.0;
   var224.i=0;
   var225.b=0;
   var226.b=0;
   var227.b=0;
   var228.b=0;
   var229.b=0;
   var230.b=0;
   var231.b=0;
   var232.b=0;
   var233.b=0;
   var234.b=0;
   var235.b=0;
   var236.b=0;
   var237.b=0;
   var238.b=0;
   var239.b=0;
   var240.b=0;
   var241.b=0;
   var242.b=0;
   var243.b=0;
   var244.b=0;
   var245.b=0;
   var246.b=0;
   var247.b=0;
   var248.b=0;
   var249.b=0;
   var250.b=0;
   var251.b=0;
   var252.b=0;
   var253.b=0;
   var254.b=0;
   var255.b=0;
   var256.b=0;
   var257.b=0;
   var258.b=0;
   var259.b=0;
   var260.b=0;
   var261.b=0;
   var262.b=0;
   var263.b=0;
   var264.b=0;
   var265.b=0;
   var266.b=0;
   var267.b=0;
   var268.b=0;
   var269.b=0;
   var270.b=0;
   var271.b=0;
   var272.b=0;
   var273.b=0;
   var274.b=0;
   var275.b=0;
   var276.b=0;
   var277.b=0;
   var278.b=0;
   var279.b=0;
   var280.b=0;
   var281.b=0;
   var282.b=0;
   var283.b=0;
   var284.b=0;
   var285.b=0;
   var286.b=0;
   var287.b=0;
   var288.b=0;
   var289.b=0;
   var290.b=0;
   var291.b=0;
   var292.b=0;
   var293.b=0;
   var294.b=0;
   var295.b=0;
   var296.b=0;
   var297.b=0;
   var298.b=0;
   var299.b=0;
   var300.b=0;
   var301.b=0;
   var302.b=0;
   var303.b=0;
   var304.b=0;
   var305.b=0;
   var306.b=0;
   var307.b=0;
   var308.b=0;
   var309.b=0;
   var310.b=0;
   var311.b=0;
   var312.b=0;
   var313.b=0;
   var314.b=0;
   var315.f=0.0;
   var316.b=0;
   var317.b=0;
   var318.b=0;
   var319.f=0.0;
   var320.b=0;
   var321.b=0;
   var322.b=0;
   var323.f=0.0;
   var324.b=0;
   var325.b=0;
   var326.b=0;
   var327.f=0.0;
   var328.b=0;
   var329.b=0;
   var330.b=0;
   var331.f=0.0;
   var332.b=0;
   var333.b=0;
   var334.b=0;
   var335.b=0;
   var336.b=0;
   var337.b=0;
   var338.b=0;
   var339.b=0;
   var340.b=0;
   var341.b=0;
   var342.b=0;
   var343.b=0;
   var344.b=0;
   var345.b=0;
   var346.b=0;
   var347.b=0;
   var348.b=0;
   var349.b=0;
   var350.b=0;
   var351.b=0;
   var352.b=0;
   var353.b=0;
   var354.b=0;
   var355.b=0;
   var356.b=0;
   var357.b=0;
   var358.b=0;
   var359.b=0;
   var360.b=0;
   var361.b=0;
   var362.b=0;
   var363.b=0;
   var364.b=0;
   var365.b=0;
   var366.b=0;
   var367.b=0;
   var368.b=0;
   var369.b=0;
   var370.b=0;
   var371.b=0;
   var372.b=0;
   var373.b=0;
   var374.b=0;
   var375.b=0;
   var376.b=0;
   var377.b=0;
   var378.b=0;
   var379.b=0;
   var380.b=0;
   var381.b=0;
   var382.b=0;
   var383.b=0;
   var384.b=0;
   var385.b=0;
   var386.b=0;
   var387.b=0;
   var388.b=0;
   var389.b=0;
   var390.b=0;
   var391.b=0;
   var392.b=0;
   var393.b=0;
   var394.b=0;
   var395.b=0;
   var396.b=0;
   var397.b=0;
   var398.b=0;
   var399.b=0;
   var400.b=0;
   var401.b=0;
   var402.b=0;
   var403.b=0;
   var404.b=0;
   var405.b=0;
   var406.b=0;
   var407.b=0;
   var408.b=0;
   var409.b=0;
   var410.b=0;
   var411.b=0;
   var412.b=0;
   var413.b=0;
   var414.b=0;
   var415.b=0;
   var416.b=0;
   var417.b=0;
   var418.b=0;
   var419.b=0;
   var420.b=0;
   var421.b=0;
   var422.b=0;
   var423.b=0;
   var424.b=0;
   var425.b=0;
   var426.b=0;
   var427.b=0;
   var428.f=0.0;
   var429.f=0.0;
   var430.b=0;
   var431.f=0.0;
   var432.f=0.0;
   var433.b=0;
   var434.f=0.0;
   var435.f=0.0;
   var436.b=0;
   var437.f=0.0;
   var438.f=0.0;
   var439.b=0;
   var440.b=0;
   var441.f=0.0;
   var442.f=0.0;
   var443.b=0;
   var444.b=0;
   var445.b=0;
   var446.b=0;
   var447.b=0;
   var448.b=0;
   var449.b=0;
   var450.b=0;
   var451.b=0;
   var452.b=0;
   var453.b=0;
   var454.b=0;
   var455.b=0;
   var456.b=0;
   var457.b=0;
   var458.b=0;
   var459.b=0;
   var460.b=0;
   var461.b=0;
   var462.b=0;
   var463.b=0;
   var464.b=0;
   var465.b=0;
   var466.b=0;
   var467.b=0;
   var468.b=0;
   var469.b=0;
   var470.b=0;
   var471.b=0;
   var472.b=0;
   var473.b=0;
   var474.b=0;
   var475.b=0;
   var476.b=0;
   var477.b=0;
   var478.b=0;
   var479.b=0;
   var480.b=0;
   var481.b=0;
   var482.b=0;
   var483.b=0;
   var484.b=0;
   var485.b=0;
   var486.b=0;
   var487.b=0;
   var488.b=0;
   var489.b=0;
   var490.b=0;
   var491.b=0;
   var492.b=0;
   var493.b=0;
   var494.b=0;
   var495.b=0;
   var496.b=0;
   var497.b=0;
   var498.b=0;
   var499.b=0;
   var500.b=0;
   var501.b=0;
   var502.b=0;
   var503.b=0;
   var504.b=0;
   var505.b=0;
   var506.b=0;
   var507.b=0;
   var508.b=0;
   var509.b=0;
   var510.b=0;
   var511.b=0;
   var512.b=0;
   var513.b=0;
   var514.b=0;
   var515.b=0;
   var516.b=0;
   var517.b=0;
   var518.b=0;
   var519.b=0;
   var520.b=0;
   var521.b=0;
   var522.b=0;
   var523.b=0;
   var524.b=0;
   var525.b=0;
   var526.b=0;
   var527.b=0;
   var528.b=0;
   var529.b=0;
   var530.b=0;
   var531.b=0;
   var532.b=0;
   var533.b=0;
   var534.b=0;
   var535.b=0;
   var536.b=0;
   var537.b=0;
   var538.b=0;
   var539.b=0;
   var540.b=0;
   var541.b=0;
   var542.b=0;
   var543.b=0;
   var544.b=0;
   var545.b=0;
   var546.b=0;
   var547.b=0;
   var548.b=0;
   var549.b=0;
   var550.b=0;
   var551.b=0;
   var552.b=0;
   var553.b=0;
   var554.b=0;
   var555.b=0;
   var556.b=0;
   var557.b=0;
   var558.b=0;
   var559.b=0;
   var560.b=0;
   var561.b=0;
   var562.b=0;
   var563.b=0;
   var564.b=0;
   var565.b=0;
   var566.b=0;
   var567.b=0;
   var568.b=0;
   var569.b=0;
   var570.b=0;
   var571.b=0;
   var572.l=0L;
   var573.b=0;
   var574.b=0;
   var575.b=0;
   var576.b=0;
   var577.b=0;
   var578.b=0;
   var579.b=0;
   var580.b=0;
   var581.b=0;
   var582.b=0;
   var583.b=0;
   var584.b=0;
   var585.b=0;
   var586.b=0;
   var587.b=0;
   var588.b=0;
   var589.b=0;
   var590.b=0;
   var591.b=0;
   var592.b=0;
   var593.b=0;
   var594.b=0;
   var595.b=0;
   var596.b=0;
   var597.b=0;
   var598.b=0;
   var599.b=0;
   var600.b=0;
   var601.b=0;
   var602.b=0;
   var603.b=0;
   var604.b=0;
   var605.b=0;
   var606.b=0;
   var607.b=0;
   var608.b=0;
   var609.b=0;
   var610.b=0;
   var611.b=0;
   var612.b=0;
   var613.b=0;
   var614.b=0;
   var615.b=0;
   var616.b=0;
   var617.b=0;
   var618.b=0;
   var619.b=0;
   var620.b=0;
   var621.b=0;
   var622.b=0;
   var623.b=0;
   var624.b=0;
   var625.b=0;
   var626.b=0;
   var627.b=0;
   var628.b=0;
   var629.b=0;
   var630.b=0;
   var631.b=0;
   var632.b=0;
   var633.b=0;
   var634.b=0;
   var635.b=0;
   var636.b=0;
   var637.b=0;
   var638.b=0;
   var639.b=0;
   var640.b=0;
   var641.b=0;
   var642.b=0;
   var643.b=0;
   var644.b=0;
   var645.b=0;
   var646.b=0;
   var647.b=0;
   var648.b=0;
   var649.b=0;
   var650.b=0;
   var651.b=0;
   var652.b=0;
   var653.b=0;
   var654.b=0;
   var655.b=0;
   var656.b=0;
   var657.b=0;
   var658.b=0;
   var659.b=0;
   var660.b=0;
   var661.b=0;
   var662.b=0;
   var663.b=0;
   var664.b=0;
   var665.b=0;
   var666.b=0;
   var667.b=0;
   var668.b=0;
   var669.b=0;
   var670.b=0;
   var671.b=0;
   var672.b=0;
   var673.b=0;
   var674.b=0;
   var675.b=0;
   var676.b=0;
   var677.b=0;
   var678.b=0;
   var679.b=0;
   var680.b=0;
   var681.b=0;
   var682.b=0;
   var683.b=0;
   var684.b=0;
   var685.b=0;
   var686.b=0;
   var687.b=0;
   var688.b=0;
   var689.b=0;
   var690.b=0;
   var691.b=0;
   var692.b=0;
   var693.b=0;
   var694.b=0;
   var695.b=0;
   var696.b=0;
   var697.b=0;
   var698.b=0;
   var699.b=0;
   var700.b=0;
   var701.b=0;
   var702.b=0;
   var703.b=0;
   var704.b=0;
   var705.b=0;
   var706.b=0;
   var707.b=0;
   var708.b=0;
   var709.b=0;
   var710.b=0;
   var711.b=0;
   var712.b=0;
   var713.b=0;
   var714.b=0;
   var715.b=0;
   var716.b=0;
   var717.b=0;
   var718.b=0;
   var719.b=0;
   var720.b=0;
   var721.b=0;
   var722.b=0;
   var723.b=0;
   var724.b=0;
   var725.b=0;
   var726.b=0;
   var727.b=0;
   var728.b=0;
   var729.b=0;
   var730.b=0;
   var731.b=0;
   var732.b=0;
   var733.b=0;
   var734.b=0;
   var735.b=0;
   var736.b=0;
   var737.b=0;
   var738.b=0;
   var739.b=0;
   var740.b=0;
   var741.b=0;
   var742.b=0;
   var743.b=0;
   var744.b=0;
   var745.b=0;
   var746.b=0;
   var747.b=0;
   var748.b=0;
   var749.b=0;
   var750.b=0;
   var751.b=0;
   var752.b=0;
   var753.b=0;
   var754.b=0;
   var755.b=0;
   var756.b=0;
   var757.b=0;
   var758.b=0;
   var759.b=0;
   var760.b=0;
   var761.b=0;
   var762.b=0;
   var763.b=0;
   var764.b=0;
   var765.b=0;
   var766.b=0;
   var767.b=0;
   var768.b=0;
   var769.b=0;
   var770.b=0;
   var771.b=0;
   var772.b=0;
   var773.b=0;
   var774.b=0;
   var775.b=0;
   var776.b=0;
   var777.b=0;
   var778.b=0;
   var779.b=0;
   var780.b=0;
   var781.b=0;
   var782.b=0;
   var783.b=0;
   var784.b=0;
   var785.b=0;
   var786.b=0;
   var787.b=0;
   var788.b=0;
   var789.b=0;
   var790.b=0;
   var791.b=0;
   var792.b=0;
   var793.b=0;
   var794.b=0;
   var795.b=0;
   var796.b=0;
   var797.b=0;
   var798.b=0;
   var799.b=0;
   var800.b=0;
   var801.b=0;
   var802.b=0;
   var803.b=0;
   var804.b=0;
   var805.b=0;
   var806.b=0;
   var807.b=0;
   var808.b=0;
   var809.b=0;
   var810.b=0;
   var811.b=0;
   var812.b=0;
   var813.b=0;
   var814.b=0;
   var815.b=0;
   var816.b=0;
   var817.b=0;
   var818.b=0;
   var819.b=0;
   var820.b=0;
   var821.b=0;
   var822.b=0;
   var823.b=0;
   var824.b=0;
   var825.b=0;
   var826.b=0;
   var827.b=0;
   var828.b=0;
   var829.b=0;
   var830.b=0;
   var831.b=0;
   var832.b=0;
   var833.b=0;
   var834.b=0;
   var835.b=0;
   var836.b=0;
   var837.b=0;
   var838.b=0;
   var839.b=0;
   var840.b=0;
   var841.b=0;
   var842.b=0;
   var843.b=0;
   var844.b=0;
   var845.b=0;
   var846.b=0;
   var847.b=0;
   var848.b=0;
   var849.b=0;
   var850.b=0;
   var851.b=0;
   var852.b=0;
   var853.b=0;
   var854.b=0;
   var855.b=0;
   var856.b=0;
   var857.b=0;
   var858.b=0;
   var859.b=0;
   var860.b=0;
   var861.b=0;
   var862.b=0;
   var863.b=0;
   var864.b=0;
   var865.b=0;
   var866.b=0;
   var867.b=0;
   var868.b=0;
   var869.b=0;
   var870.b=0;
   var871.b=0;
   var872.b=0;
   var873.b=0;
   var874.b=0;
   var875.b=0;
   var876.b=0;
   var877.b=0;
   var878.b=0;
   var879.b=0;
   var880.b=0;
   var881.b=0;
   var882.b=0;
   var883.b=0;
   var884.b=0;
   var885.b=0;
   var886.b=0;
   var887.b=0;
   var888.b=0;
   var889.b=0;
   var890.b=0;
   var891.b=0;
   var892.b=0;
   var893.b=0;
   var894.b=0;
   var895.b=0;
   var896.b=0;
   var897.b=0;
   var898.b=0;
   var899.b=0;
   var900.b=0;
   var901.b=0;
   var902.b=0;
   var903.b=0;
   var904.b=0;
   var905.b=0;
   var906.b=0;
   var907.b=0;
   var908.b=0;
   var909.b=0;
   var910.b=0;
   var911.b=0;
   var912.b=0;
   var913.b=0;
   var914.b=0;
   var915.b=0;
   var916.b=0;
   var917.b=0;
   var918.b=0;
   var919.b=0;
   var920.b=0;
   var921.b=0;
   var922.b=0;
   var923.b=0;
   var924.b=0;
   var925.b=0;
   var926.b=0;
   var927.b=0;
   var928.b=0;
   var929.b=0;
   var930.b=0;
   var931.b=0;
   var932.b=0;
   var933.b=0;
   var934.b=0;
   var935.b=0;
   var936.b=0;
   var937.b=0;
   var938.b=0;
   var939.b=0;
   var940.b=0;
   var941.b=0;
   var942.b=0;
   var943.b=0;
   var944.b=0;
   var945.b=0;
   var946.b=0;
   var947.b=0;
   var948.b=0;
   var949.b=0;
   var950.b=0;
   var951.b=0;
   var952.b=0;
   var953.b=0;
   var954.b=0;
   var955.b=0;
   var956.b=0;
   var957.b=0;
   var958.b=0;
   var959.b=0;
   var960.b=0;
   var961.b=0;
   var962.b=0;
   var963.b=0;
   var964.b=0;
   var965.b=0;
   var966.b=0;
   var967.b=0;
   var968.b=0;
   var969.b=0;
   var970.b=0;
   var971.b=0;
   var972.b=0;
   var973.b=0;
   var974.b=0;
   var975.b=0;
   var976.b=0;
   var977.b=0;
   var978.b=0;
   var979.b=0;
   var980.b=0;
   var981.b=0;
   var982.b=0;
   var983.f=0.0;
   var984.b=0;
   var985.f=0.0;
   var986.b=0;
   var987.f=0.0;
   var988.b=0;
   var989.b=0;
   var990.b=0;
   var991.b=0;
   var992.f=0.0;
   var993.f=0.0;
   var994.f=0.0;
   var995.f=0.0;
   var996.f=0.0;
   var997.f=0.0;
   var998.b=0;
   var999.b=0;
   var1000.b=0;
   var1001.b=0;
   var1002.b=0;
   var1003.b=0;
   var1004.b=0;
   var1005.b=0;
   var1006.b=0;
   var1007.b=0;
   var1008.b=0;
   var1009.b=0;
   var1010.b=0;
   var1011.b=0;
   var1012.b=0;
   var1013.b=0;
   var1014.b=0;
   var1015.b=0;
   var1016.b=0;
   var1017.b=0;
   var1018.b=0;
   var1019.b=0;
   var1020.b=0;
   var1021.b=0;
   var1022.b=0;
   var1023.b=0;
   var1024.b=0;
   var1025.b=0;
   var1026.b=0;
   var1027.b=0;
   var1028.b=0;
   var1029.b=0;
   var1030.b=0;
   var1031.b=0;
   var1032.b=0;
   var1033.b=0;
   var1034.b=0;
   var1035.b=0;
   var1036.b=0;
   var1037.b=0;
   var1038.b=0;
   var1039.b=0;
   var1040.b=0;
   var1041.b=0;
   var1042.b=0;
   var1043.b=0;
   var1044.b=0;
   var1045.b=0;
   var1046.b=0;
   var1047.b=0;
   var1048.b=0;
   var1049.b=0;
   var1050.b=0;
   var1051.b=0;
   var1052.b=0;
   var1053.i=0;
   var1054.i=0;
   var1055.b=0;
   var1056.b=0;
   var1057.b=0;
   var1058.b=0;
   var1059.b=0;
   var1060.b=0;
   var1061.l=0L;
   var1062.b=0;
   var1063.b=0;
   var1064.b=0;
   var1065.i=0;
   var1066.b=0;
   var1067.b=0;
   var1068.b=0;
   var1069.b=0;
   var1070.b=0;
   var1071.b=0;
   var1072.b=0;
   var1073.b=0;
   var1074.b=0;
   var1075.i=0;
   var1076.i=0;
   var1077.b=0;
   var1078.b=0;
   var1079.b=0;
   var1080.b=0;
   var1081.b=0;
   var1082.b=0;
   var1083.b=0;
   var1084.b=0;
   var1085.b=0;
   var1086.b=0;
   var1087.b=0;
   var1088.b=0;
   var1089.b=0;
   var1090.b=0;
   var1091.b=0;
   var1092.b=0;
   var1093.b=0;
   var1094.b=0;
   var1095.b=0;
   var1096.b=0;
   var1097.b=0;
   var1098.b=0;
   var1099.b=0;
   var1100.b=0;
   var1101.b=0;
   var1102.b=0;
   var1103.b=0;
   var1104.b=0;
   var1105.b=0;
   var1106.b=0;
   var1107.b=0;
   var1108.b=0;
   var1109.b=0;
   var1110.b=0;
   var1111.b=0;
   var1112.b=0;
   var1113.b=0;
   var1114.b=0;
   var1115.b=0;
   var1116.l=0L;
   var1117.b=0;
   var1118.b=0;
   var1119.b=0;
   var1120.b=0;
   var1121.b=0;
   var1122.b=0;
   var1123.b=0;
   var1124.b=0;
   var1125.b=0;
   var1126.b=0;
   var1127.b=0;
   var1128.b=0;
   var1129.b=0;
   var1130.b=0;
   var1131.b=0;
   var1132.b=0;
   var1133.b=0;
   var1134.b=0;
   var1135.f=0.0;
   var1136.b=0;
   var1137.b=0;
   var1138.b=0;
   var1139.b=0;
   var1140.b=0;
   var1141.f=0.0;
   var1142.b=0;
   var1143.b=0;
   var1144.b=0;
   var1145.b=0;
   var1146.b=0;
   var1147.b=0;
   var1148.b=0;
   var1149.b=0;
   var1150.b=0;
   var1151.b=0;
   var1152.b=0;
   var1153.b=0;
   var1154.b=0;
   var1155.i=0;
   var1156.b=0;
   var1157.b=0;
   var1158.b=0;
   var1159.b=0;
   var1160.b=0;
   var1161.b=0;
   var1162.b=0;
   var1163.b=0;
   var1164.b=0;
   var1165.b=0;
   var1166.b=0;
   var1167.b=0;
   var1168.b=0;
   var1169.b=0;
   var1170.b=0;
   var1171.b=0;
   var1172.b=0;
   var1173.b=0;
   var1174.b=0;
   var1175.b=0;
   var1176.b=0;
   var1177.b=0;
   var1178.b=0;
   var1179.b=0;
   var1180.f=0.0;
   var1181.b=0;
   var1182.b=0;
   var1183.b=0;
   var1184.b=0;
   var1185.b=0;
   var1186.b=0;
   var1187.b=0;
   var1188.b=0;
   var1189.b=0;
   var1190.b=0;
   var1191.b=0;
   var1192.b=0;
   var1193.b=0;
   var1194.b=0;
   var1195.b=0;
   var1196.b=0;
   var1197.b=0;
   var1198.b=0;
   var1199.b=0;
   var1200.b=0;
   var1201.b=0;
   var1202.b=0;
   var1203.b=0;
   var1204.b=0;
   var1205.b=0;
   var1206.b=0;
   var1207.b=0;
   var1208.b=0;
   var1209.b=0;
   var1210.b=0;
   var1211.b=0;
   var1212.b=0;
   var1213.b=0;
   var1214.b=0;
   var1215.b=0;
   var1216.b=0;
   var1217.b=0;
   var1218.b=0;
   var1219.b=0;
   var1220.b=0;
   var1221.b=0;
   var1222.b=0;
   var1223.b=0;
   var1224.b=0;
   var1225.b=0;
   var1226.b=0;
   var1227.b=0;
   var1228.b=0;
   var1229.b=0;
   var1230.b=0;
   var1231.b=0;
   var1232.b=0;
   var1233.b=0;
   var1234.b=0;
   var1235.b=0;
   var1236.b=0;
   var1237.b=0;
   var1238.b=0;
   var1239.b=0;
   var1240.b=0;
   var1241.b=0;
   var1242.b=0;
   var1243.b=0;
   var1244.b=0;
   var1245.b=0;
   var1246.b=0;
   var1247.b=0;
   var1248.b=0;
   var1249.b=0;
   var1250.b=0;
   var1251.b=0;
   var1252.b=0;
   var1253.b=0;
   var1254.b=0;
   var1255.b=0;
   var1256.b=0;
   var1257.b=0;
   var1258.b=0;
   var1259.b=0;
   var1260.b=0;
   var1261.b=0;
   var1262.b=0;
   var1263.b=0;
   var1264.b=0;
   var1265.b=0;
   var1266.b=0;
   var1267.b=0;
   var1268.b=0;
   var1269.b=0;
   var1270.b=0;
   var1271.b=0;
   var1272.b=0;
   var1273.b=0;
   var1274.b=0;
   var1275.b=0;
   var1276.l=0L;
   var1277.b=0;
   var1278.i=0;
   var1279.i=0;
   var1280.b=0;
   var1281.f=0.0;
   var1282.f=0.0;
   var1283.f=0.0;
   var1284.b=0;
   var1285.b=0;
   var1286.b=0;
   var1287.b=0;
   var1288.b=0;
   var1289.b=0;
   var1290.b=0;
   var1291.b=0;
   var1292.b=0;
   var1293.b=0;
   var1294.b=0;
   var1295.b=0;
   var1296.b=0;
   var1297.b=0;
   var1298.b=0;
   var1299.b=0;
   var1300.i=0;
   var1301.b=0;
   var1302.c=0;
   var1303.i=0;
   var1304.b=0;
   var1305.f=0.0;
   var1306.b=0;
   var1307.b=0;
   var1308.b=0;
   var1309.b=0;
   var1310.b=0;
   var1311.b=0;
   var1312.b=0;
   var1313.f=0.0;
   var1314.c=0;
   var1315.b=0;
   var1316.b=0;
   var1317.b=0;
   var1318.b=0;
   var1319.f=0.0;
   var1320.b=0;
   var1321.b=0;
   var1322.b=0;
   var1323.b=0;
   var1324.b=0;
   var1325.b=0;
   var1326.b=0;
   var1327.b=0;
   var1328.b=0;
   var1329.b=0;
   var1330.b=0;
   var1331.b=0;
   var1332.i=0;
   var1333.b=0;
   var1334.c=0;
   var1335.i=0;
   var1336.b=0;
   var1337.f=0.0;
   var1338.b=0;
   var1339.b=0;
   var1340.b=0;
   var1341.b=0;
   var1342.b=0;
   var1343.b=0;
   var1344.b=0;
   var1345.f=0.0;
   var1346.c=0;
   var1347.b=0;
   var1348.b=0;
   var1349.b=0;
   var1350.b=0;
   var1351.f=0.0;
   var1352.b=0;
   var1353.b=0;
   var1354.b=0;
   var1355.b=0;
   var1356.b=0;
   var1357.b=0;
   var1358.b=0;
   var1359.b=0;
   var1360.b=0;
   var1361.i=0;
   var1362.b=0;
   var1363.c=0;
   var1364.i=0;
   var1365.b=0;
   var1366.f=0.0;
   var1367.b=0;
   var1368.b=0;
   var1369.b=0;
   var1370.b=0;
   var1371.b=0;
   var1372.b=0;
   var1373.b=0;
   var1374.f=0.0;
   var1375.c=0;
   var1376.b=0;
   var1377.b=0;
   var1378.b=0;
   var1379.b=0;
   var1380.f=0.0;
   var1381.b=0;
   var1382.b=0;
   var1383.b=0;
   var1384.b=0;
   var1385.b=0;
   var1386.b=0;
   var1387.b=0;
   var1388.b=0;
   var1389.b=0;
   var1390.b=0;
   var1391.b=0;
   var1392.b=0;
   var1393.b=0;
   var1394.i=0;
   var1395.b=0;
   var1396.c=0;
   var1397.i=0;
   var1398.b=0;
   var1399.f=0.0;
   var1400.b=0;
   var1401.b=0;
   var1402.b=0;
   var1403.b=0;
   var1404.b=0;
   var1405.b=0;
   var1406.b=0;
   var1407.f=0.0;
   var1408.c=0;
   var1409.b=0;
   var1410.b=0;
   var1411.f=0.0;
   var1412.b=0;
   var1413.b=0;
   var1414.b=0;
   var1415.b=0;
   var1416.b=0;
   var1417.b=0;
   var1418.b=0;
   var1419.b=0;
   var1420.b=0;
   var1421.b=0;
   var1422.b=0;
   var1423.b=0;
   var1424.i=0;
   var1425.b=0;
   var1426.b=0;
   var1427.b=0;
   var1428.b=0;
   var1429.b=0;
   var1430.b=0;
   var1431.b=0;
   var1432.b=0;
   var1433.i=0;
   var1434.b=0;
   var1435.b=0;
   var1436.b=0;
   var1437.b=0;
   var1438.b=0;
   var1439.b=0;
   var1440.b=0;
   var1441.i=0;
   var1442.b=0;
   var1443.c=0;
   var1444.i=0;
   var1445.b=0;
   var1446.f=0.0;
   var1447.b=0;
   var1448.b=0;
   var1449.b=0;
   var1450.b=0;
   var1451.b=0;
   var1452.b=0;
   var1453.b=0;
   var1454.f=0.0;
   var1455.c=0;
   var1456.b=0;
   var1457.b=0;
   var1458.f=0.0;
   var1459.b=0;
   var1460.b=0;
   var1461.b=0;
   var1462.b=0;
   var1463.b=0;
   var1464.b=0;
   var1465.b=0;
   var1466.b=0;
   var1467.c=0;
   var1468.b=0;
   var1469.b=0;
   var1470.b=0;
   var1471.b=0;
   var1472.b=0;
   var1473.b=0;
   var1474.b=0;
   var1475.b=0;
   var1476.b=0;
   var1477.c=0;
   var1478.b=0;
   var1479.b=0;
   var1480.i=0;
   var1481.b=0;
   var1482.c=0;
   var1483.b=0;
   var1484.i=0;
   var1485.b=0;
   var1486.b=0;
   var1487.f=0.0;
   var1488.b=0;
   var1489.b=0;
   var1490.b=0;
   var1491.b=0;
   var1492.b=0;
   var1493.b=0;
   var1494.b=0;
   var1495.f=0.0;
   var1496.c=0;
   var1497.b=0;
   var1498.b=0;
   var1499.b=0;
   var1500.b=0;
   var1501.f=0.0;
   var1502.b=0;
   var1503.b=0;
   var1504.b=0;
   var1505.b=0;
   var1506.b=0;
   var1507.b=0;
   var1508.b=0;
   var1509.b=0;
   var1510.b=0;
   var1511.b=0;
   var1512.b=0;
   var1513.b=0;
   var1514.f=0.0;
   var1515.b=0;
   var1516.b=0;
   var1517.b=0;
   var1518.b=0;
   var1519.b=0;
   var1520.b=0;
   var1521.b=0;
   var1522.b=0;
   var1523.b=0;
   var1524.b=0;
   var1525.b=0;
   var1526.b=0;
   var1527.b=0;
   var1528.b=0;
   var1529.b=0;
   var1530.b=0;
   var1531.f=0.0;
   var1532.b=0;
   var1533.b=0;
   var1534.b=0;
   var1535.b=0;
   var1536.b=0;
   var1537.b=0;
   var1538.b=0;
   var1539.b=0;
   var1540.b=0;
   var1541.b=0;
   var1542.b=0;
   var1543.b=0;
   var1544.b=0;
   var1545.b=0;
   var1546.b=0;
   var1547.b=0;
   var1548.b=0;
   var1549.b=0;
   var1550.b=0;
   var1551.b=0;
   var1552.b=0;
   var1553.b=0;
   var1554.b=0;
   var1555.b=0;
   var1556.b=0;
   var1557.b=0;
   var1558.b=0;
   var1559.b=0;
   var1560.b=0;
   var1561.b=0;
   var1562.b=0;
   var1563.b=0;
   var1564.b=0;
   var1565.b=0;
   var1566.b=0;
   var1567.b=0;
   var1568.b=0;
   var1569.i=0;
   var1570.b=0;
   var1571.b=0;
   var1572.b=0;
   var1573.b=0;
   var1574.b=0;
   var1575.b=0;
   var1576.b=0;
   var1577.b=0;
   var1578.i=0;
   var1579.b=0;
   var1580.b=0;
   var1581.b=0;
   var1582.b=0;
   var1583.b=0;
   var1584.b=0;
   var1585.b=0;
   var1586.b=0;
   var1587.i=0;
   var1588.b=0;
   var1589.b=0;
   var1590.b=0;
   var1591.b=0;
   var1592.b=0;
   var1593.b=0;
   var1594.b=0;
   var1595.b=0;
   var1596.i=0;
   var1597.b=0;
   var1598.b=0;
   var1599.b=0;
   var1600.b=0;
   var1601.b=0;
   var1602.b=0;
   var1603.b=0;
   var1604.b=0;
   var1605.i=0;
   var1606.b=0;
   var1607.b=0;
   var1608.b=0;
   var1609.b=0;
   var1610.b=0;
   var1611.b=0;
   var1612.b=0;
   var1613.b=0;
   var1614.i=0;
   var1615.b=0;
   var1616.b=0;
   var1617.b=0;
   var1618.b=0;
   var1619.b=0;
   var1620.b=0;
   var1621.b=0;
   var1622.b=0;
   var1623.i=0;
   var1624.b=0;
   var1625.b=0;
   var1626.b=0;
   var1627.b=0;
   var1628.b=0;
   var1629.b=0;
   var1630.b=0;
   var1631.b=0;
   var1632.b=0;
   var1633.b=0;
   var1634.b=0;
   var1635.b=0;
   var1636.b=0;
   var1637.b=0;
   var1638.b=0;
   var1639.b=0;
   var1640.b=0;
   var1641.b=0;
   var1642.b=0;
   var1643.b=0;
   var1644.b=0;
   var1645.b=0;
   var1646.b=0;
   var1647.b=0;
   var1648.b=0;
   var1649.b=0;
   var1650.b=0;
   var1651.b=0;
   var1652.b=0;
   var1653.b=0;
   var1654.b=0;
   var1655.b=0;
   var1656.b=0;
   var1657.b=0;
   var1658.b=0;
   var1659.b=0;
   var1660.f=0.0;
   var1661.b=0;
   var1662.b=0;
   var1663.b=0;
   var1664.b=0;
   var1665.b=0;
   var1666.b=0;
   var1667.b=0;
   var1668.b=0;
   var1669.b=0;
   var1670.b=0;
   var1671.b=0;
   var1672.b=0;
   var1673.b=0;
   var1674.b=0;
   var1675.b=0;
   var1676.b=0;
   var1677.b=0;
   var1678.b=0;
   var1679.b=0;
   var1680.b=0;
   var1681.b=0;
   var1682.b=0;
   var1683.b=0;
   var1684.b=0;
   var1685.b=0;
   var1686.b=0;
   var1687.b=0;
   var1688.b=0;
   var1689.b=0;
   var1690.b=0;
   var1691.b=0;
   var1692.b=0;
   var1693.b=0;
   var1694.b=0;
   var1695.f=0.0;
   var1696.f=0.0;
   var1697.b=0;
   var1698.b=0;
   var1699.b=0;
   var1700.b=0;
   var1701.b=0;
   var1702.b=0;
   var1703.b=0;
   var1704.b=0;
   var1705.b=0;
   var1706.b=0;
   var1707.b=0;
   var1708.b=0;
   var1709.b=0;
   var1710.b=0;
   var1711.b=0;
   var1712.b=0;
   var1713.b=0;
   var1714.b=0;
   var1715.b=0;
   var1716.b=0;
   var1717.b=0;
   var1718.b=0;
   var1719.b=0;
   var1720.b=0;
   var1721.b=0;
   var1722.b=0;
   var1723.f=0.0;
   var1724.b=0;
   var1725.b=0;
   var1726.f=0.0;
   var1727.b=0;
   var1728.b=0;
   var1729.f=0.0;
   var1730.b=0;
   var1731.b=0;
   var1732.f=0.0;
   var1733.b=0;
   var1734.b=0;
   var1735.f=0.0;
   var1736.b=0;
   var1737.b=0;
   var1738.f=0.0;
   var1739.b=0;
   var1740.b=0;
   var1741.f=0.0;
   var1742.b=0;
   var1743.b=0;
   var1744.b=0;
   var1745.f=0.0;
   var1746.b=0;
   var1747.b=0;
   var1748.b=0;
   vainSLong.l=0L;
   vainSFloat.f=0.0;
   vainSInt.i=0;
   vainSBool.b=0;
   vainSChar.c=0;

}
int freebuff = 0, delay = 0;
void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  equz_p(&S_equz_p_19_2);
  andn(&S_andn_133_2);
  noto(&S_noto_134_2);
  andn(&S_andn_150_2);
  noto(&S_noto_153_2);
  scalzz(&S_scalzz_180_2);
  scalzz(&S_scalzz_182_2);
  or2(&S_or2_11_2);
  or2(&S_or2_42_2);
  or2(&S_or2_13_2);
  or2(&S_or2_43_2);
  or2(&S_or2_74_2);
  or2(&S_or2_71_2);
  and3(&S_and3_77_2);
  or2(&S_or2_103_2);
  or2(&S_or2_104_2);
  and3(&S_and3_111_2);
  and4(&S_and4_136_2);
  and4(&S_and4_159_2);
  schl24(&S_schl24_143_2);
  schl24(&S_schl24_149_2);
  noto(&S_noto_227_2);
  noto(&S_noto_228_2);
  noto(&S_noto_229_2);
  noto(&S_noto_247_2);
  noto(&S_noto_248_2);
  noto(&S_noto_249_2);
  fsumo(&S_fsumo_220_2);
  bol(&S_bol_221_2);
  lkb(&S_lkb_78_2);
  lkb(&S_lkb_112_2);
  and4(&S_and4_108_2);
  enctkb(&S_enctkb_79_2);
  enctkb(&S_enctkb_106_2);
  drg(&S_drg_193_2);
  drg(&S_drg_185_2);
  geterr(&S_geterr_184_2);
  drg(&S_drg_203_2);
  drg(&S_drg_196_2);
  geterr(&S_geterr_187_2);
  tprg(&S_tprg_207_2);
  tprg(&S_tprg_215_2);
  noto(&S_noto_218_2);
  noto(&S_noto_209_2);
  andn(&S_andn_168_2);
  noto(&S_noto_169_2);
  and2(&S_and2_217_2);
  and3(&S_and3_20_2);
  and3(&S_and3_48_2);
  and3(&S_and3_23_2);
  and3(&S_and3_51_2);
  and3(&S_and3_81_2);
  or3(&S_or3_135_2);
  or3(&S_or3_158_2);
  and2(&S_and2_210_2);
  or2(&S_or2_191_2);
  or2(&S_or2_195_2);
  lkb(&S_lkb_21_2);
  lkb(&S_lkb_24_2);
  lkb(&S_lkb_49_2);
  lkb(&S_lkb_82_2);
  lkb(&S_lkb_52_2);
  lkb(&S_lkb_109_2);
  enctkb(&S_enctkb_15_2);
  enctkb(&S_enctkb_53_2);
  enctkb(&S_enctkb_45_2);
  enctkb(&S_enctkb_83_2);
  enctkb(&S_enctkb_110_2);
  enctkb(&S_enctkb_17_2);
  noto(&S_noto_141_2);
  noto(&S_noto_157_2);
  and2(&S_and2_231_2);
  and2(&S_and2_252_2);
  ornc(&S_ornc_124_2);
  ornc(&S_ornc_232_2);
  ornc(&S_ornc_253_2);
  noto(&S_noto_238_2);
  noto(&S_noto_254_2);
  or2(&S_or2_256_2);
  ornc(&S_ornc_230_2);
  ornc(&S_ornc_241_2);
  noto(&S_noto_233_2);
  noto(&S_noto_251_2);
  or2(&S_or2_242_2);
  setData(idR0EE02LDU,&var820);
  setData(idB8VC01RDU,&var1726);
  setData(idB2VC01RDU,&var1738);
  setData(idA2VC01RDU,&var1741);
  setData(idA3VC01RDU,&var1735);
  setData(idB0VS11LDU,&var1703);
  setData(idA0VS11LDU,&var1704);
  setData(idB0VN01LDU,&var1673);
  setData(idA0VN01LDU,&var1675);
  setData(idB0VP01LDU,&var1709);
  setData(idA0VP01LDU,&var1710);
  setData(idB0VE01LDU,&var1700);
  setData(idA0VE01LDU,&var1702);
  setData(idA3VP82LDU,&var1671);
  setData(idB3VP82LDU,&var1694);
  setData(idB3VP52LDU,&var1719);
  setData(idB3CP02RDU,&var1695);
  setData(idB3VP42LDU,&var1669);
  setData(idA3VP52LDU,&var1722);
  setData(idA3CP02RDU,&var1696);
  setData(idA3VP42LDU,&var1670);
  setData(idA1VC01RDU,&var1723);
  setData(idA8VC01RDU,&var1729);
  setData(idB3VC01RDU,&var1732);
  setData(idB1VC01RDU,&var1745);
  equz_p(&S_equz_p_4_1);
  equz_p(&S_equz_p_2_1);
  equz_p(&S_equz_p_7_1);
  equz_p(&S_equz_p_10_1);
  equz_p(&S_equz_p_91_1);
  equz_p(&S_equz_p_92_1);
  equz_p(&S_equz_p_93_1);
  equz_p(&S_equz_p_100_1);
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
  noto(&S_noto_144_1);
  noto(&S_noto_143_1);
  noto(&S_noto_154_1);
  noto(&S_noto_747_1);
  noto(&S_noto_714_1);
  noto(&S_noto_1097_1);
  noto(&S_noto_1565_1);
  noto(&S_noto_1261_1);
  noto(&S_noto_855_1);
  noto(&S_noto_218_1);
  noto(&S_noto_536_1);
  noto(&S_noto_950_1);
  rs(&S_rs_619_1);
  noto(&S_noto_1351_1);
  equz_p(&S_equz_p_32_1);
  equz_p(&S_equz_p_41_1);
  noto(&S_noto_34_1);
  equz_p(&S_equz_p_37_1);
  rs(&S_rs_1476_1);
  noto(&S_noto_1768_1);
  noto(&S_noto_1767_1);
  noto(&S_noto_1773_1);
  noto(&S_noto_1769_1);
  noto(&S_noto_1775_1);
  noto(&S_noto_1746_1);
  noto(&S_noto_1747_1);
  noto(&S_noto_1748_1);
  noto(&S_noto_1749_1);
  noto(&S_noto_1750_1);
  noto(&S_noto_2062_1);
  equz_p(&S_equz_p_94_1);
  equz_p(&S_equz_p_95_1);
  equz_p(&S_equz_p_96_1);
  noto(&S_noto_927_1);
  equz_p(&S_equz_p_97_1);
  equz_p(&S_equz_p_98_1);
  noto(&S_noto_178_1);
  equz_p(&S_equz_p_99_1);
  noto(&S_noto_12_1);
  noto(&S_noto_1846_1);
  equz_p(&S_equz_p_1790_1);
  equz_p(&S_equz_p_1789_1);
  equz_p(&S_equz_p_1791_1);
  equz_p(&S_equz_p_1792_1);
  equz_p(&S_equz_p_1793_1);
  noto(&S_noto_1755_1);
  noto(&S_noto_1808_1);
  noto(&S_noto_1827_1);
  rs(&S_rs_609_1);
  noto(&S_noto_1787_1);
  noto(&S_noto_1813_1);
  noto(&S_noto_1328_1);
  rsun(&S_rsun_1401_1);
  rs(&S_rs_611_1);
  rs(&S_rs_613_1);
  rs(&S_rs_629_1);
  rs(&S_rs_646_1);
  rs(&S_rs_618_1);
  rs(&S_rs_633_1);
  rs(&S_rs_26_1);
  rs(&S_rs_1471_1);
  rs(&S_rs_1425_1);
  rs(&S_rs_1879_1);
  noto(&S_noto_1420_1);
  noto(&S_noto_1460_1);
  noto(&S_noto_1465_1);
  noto(&S_noto_1837_1);
  noto(&S_noto_1874_1);
  noto(&S_noto_1893_1);
  noto(&S_noto_1859_1);
  noto(&S_noto_580_1);
  noto(&S_noto_22_1);
  noto(&S_noto_23_1);
  noto(&S_noto_24_1);
  noto(&S_noto_25_1);
  noto(&S_noto_583_1);
  noto(&S_noto_581_1);
  noto(&S_noto_49_1);
  noto(&S_noto_258_1);
  noto(&S_noto_261_1);
  noto(&S_noto_270_1);
  noto(&S_noto_275_1);
  noto(&S_noto_266_1);
  noto(&S_noto_984_1);
  noto(&S_noto_990_1);
  noto(&S_noto_1928_1);
  noto(&S_noto_1930_1);
  rs(&S_rs_1067_1);
  rs(&S_rs_1070_1);
  rs(&S_rs_1073_1);
  rs(&S_rs_1076_1);
  ovbs(&S_ovbs_1172_1);
  ovbs(&S_ovbs_2084_1);
  sr(&S_sr_1060_1);
  bol(&S_bol_1054_1);
  ma(&S_ma_84_1);
  sr(&S_sr_82_1);
  bol(&S_bol_255_1);
  bol(&S_bol_253_1);
  bol(&S_bol_1380_1);
  bol(&S_bol_1378_1);
  bol(&S_bol_979_1);
  bol(&S_bol_977_1);
  bol(&S_bol_568_1);
  bol(&S_bol_570_1);
  bol(&S_bol_579_1);
  bol(&S_bol_585_1);
  and2(&S_and2_735_1);
  and2(&S_and2_27_1);
  and2(&S_and2_28_1);
  and2(&S_and2_29_1);
  and2(&S_and2_30_1);
  and2(&S_and2_42_1);
  and2(&S_and2_38_1);
  and2(&S_and2_726_1);
  or4(&S_or4_416_1);
  or2(&S_or2_739_1);
  or3(&S_or3_5_1);
  or2(&S_or2_6_1);
  or2(&S_or2_1274_1);
  or2(&S_or2_868_1);
  or2(&S_or2_232_1);
  or2(&S_or2_550_1);
  or2(&S_or2_962_1);
  or2(&S_or2_1363_1);
  or2(&S_or2_1059_1);
  and2(&S_and2_1053_1);
  or2(&S_or2_20_1);
  or2(&S_or2_39_1);
  or2(&S_or2_35_1);
  or2(&S_or2_48_1);
  or2(&S_or2_686_1);
  or3(&S_or3_674_1);
  or4(&S_or4_688_1);
  or2(&S_or2_701_1);
  or3(&S_or3_722_1);
  and2(&S_and2_746_1);
  and2(&S_and2_720_1);
  or2(&S_or2_728_1);
  or2(&S_or2_656_1);
  or2(&S_or2_658_1);
  or2(&S_or2_660_1);
  or2(&S_or2_1147_1);
  or2(&S_or2_1173_1);
  and4(&S_and4_1065_1);
  or2(&S_or2_1064_1);
  and2(&S_and2_1079_1);
  or2(&S_or2_1093_1);
  and3(&S_and3_259_1);
  and3(&S_and3_274_1);
  or2(&S_or2_602_1);
  or2(&S_or2_610_1);
  or2(&S_or2_612_1);
  or2(&S_or2_615_1);
  or2(&S_or2_586_1);
  and2(&S_and2_636_1);
  or2(&S_or2_643_1);
  and2(&S_and2_607_1);
  or2(&S_or2_622_1);
  or2(&S_or2_617_1);
  or2(&S_or2_640_1);
  and2(&S_and2_597_1);
  or2(&S_or2_342_1);
  or2(&S_or2_347_1);
  or2(&S_or2_744_1);
  or2(&S_or2_458_1);
  or2(&S_or2_516_1);
  and2(&S_and2_525_1);
  and2(&S_and2_526_1);
  and2(&S_and2_535_1);
  or2(&S_or2_528_1);
  or2(&S_or2_196_1);
  and2(&S_and2_176_1);
  and2(&S_and2_208_1);
  and2(&S_and2_207_1);
  or2(&S_or2_210_1);
  and2(&S_and2_217_1);
  or2(&S_or2_781_1);
  or2(&S_or2_830_1);
  or2(&S_or2_844_1);
  and2(&S_and2_921_1);
  or2(&S_or2_932_1);
  or2(&S_or2_924_1);
  or2(&S_or2_941_1);
  or2(&S_or2_1342_1);
  or2(&S_or2_1325_1);
  and2(&S_and2_1322_1);
  or2(&S_or2_1333_1);
  or2(&S_or2_1250_1);
  or2(&S_or2_1229_1);
  and2(&S_and2_989_1);
  and2(&S_and2_1421_1);
  zpfs(&S_zpfs_1431_1);
  and2(&S_and2_1461_1);
  zpfs(&S_zpfs_1481_1);
  and2(&S_and2_1466_1);
  zpfs(&S_zpfs_1487_1);
  and2(&S_and2_1503_1);
  or2(&S_or2_2085_1);
  or2(&S_or2_1610_1);
  or2(&S_or2_1611_1);
  or2(&S_or2_1561_1);
  or2(&S_or2_1753_1);
  or2(&S_or2_1754_1);
  or4(&S_or4_1760_1);
  or4(&S_or4_1761_1);
  or2(&S_or2_1763_1);
  or2(&S_or2_1757_1);
  or2(&S_or2_1756_1);
  or3(&S_or3_1765_1);
  and2(&S_and2_1794_1);
  or2(&S_or2_1795_1);
  and2(&S_and2_1801_1);
  and2(&S_and2_1817_1);
  or2(&S_or2_1828_1);
  zpfs(&S_zpfs_1797_1);
  zpfs(&S_zpfs_1798_1);
  zpfs(&S_zpfs_1799_1);
  zpfs(&S_zpfs_1800_1);
  or2(&S_or2_1803_1);
  and2(&S_and2_1804_1);
  or2(&S_or2_1819_1);
  or3(&S_or3_1805_1);
  or2(&S_or2_1880_1);
  ma(&S_ma_1456_1);
  zpfs(&S_zpfs_1850_1);
  and2(&S_and2_1851_1);
  or2(&S_or2_1845_1);
  and3(&S_and3_1848_1);
  or2(&S_or2_1856_1);
  or2(&S_or2_234_1);
  ovbs(&S_ovbs_77_1);
  ovbs(&S_ovbs_21_1);
  ovbs(&S_ovbs_120_1);
  ovbs(&S_ovbs_113_1);
  ovbs(&S_ovbs_1415_1);
  ovbs(&S_ovbs_742_1);
  ovbs(&S_ovbs_291_1);
  ovbs(&S_ovbs_338_1);
  ovbs(&S_ovbs_51_1);
  or2(&S_or2_1992_1);
  or2(&S_or2_1980_1);
  noto(&S_noto_2010_1);
  bol(&S_bol_1545_1);
  bol(&S_bol_1541_1);
  or2(&S_or2_1543_1);
  bol(&S_bol_1529_1);
  bol(&S_bol_1520_1);
  or2(&S_or2_1527_1);
  bol(&S_bol_1548_1);
  bol(&S_bol_1539_1);
  or2(&S_or2_1547_1);
  bol(&S_bol_1533_1);
  bol(&S_bol_1522_1);
  or2(&S_or2_1532_1);
  and4(&S_and4_45_1);
  abs_subf(&S_abs_subf_1538_1);
  noto(&S_noto_1544_1);
  and2(&S_and2_233_1);
  and2(&S_and2_551_1);
  and2(&S_and2_2238_1);
  rs(&S_rs_2187_1);
  sr(&S_sr_2225_1);
  sr(&S_sr_2202_1);
  rs(&S_rs_2181_1);
  zpfs(&S_zpfs_2209_1);
  or2(&S_or2_2195_1);
  abs_subf(&S_abs_subf_2162_1);
  and2(&S_and2_2171_1);
  noto(&S_noto_896_1);
  zzfs(&S_zzfs_2172_1);
  noto(&S_noto_2182_1);
  or2(&S_or2_1077_1);
  or2(&S_or2_367_1);
  or2(&S_or2_350_1);
  or2(&S_or2_1109_1);
  or2(&S_or2_1112_1);
  or2(&S_or2_230_1);
  or2(&S_or2_548_1);
  nocnm(&S_nocnm_1704_1);
  nocnm(&S_nocnm_1707_1);
  noto(&S_noto_1662_1);
  noto(&S_noto_1663_1);
  noto(&S_noto_2155_1);
  noto(&S_noto_2124_1);
  or2(&S_or2_1428_1);
  or2(&S_or2_1459_1);
  noto(&S_noto_2157_1);
  noto(&S_noto_2126_1);
  noto(&S_noto_107_1);
  and2(&S_and2_721_1);
  and2(&S_and2_724_1);
  or2(&S_or2_127_1);
  noto(&S_noto_1722_1);
  noto(&S_noto_1723_1);
  or2(&S_or2_1686_1);
  or2(&S_or2_1726_1);
  or2(&S_or2_1729_1);
  or2(&S_or2_1697_1);
  or2(&S_or2_1700_1);
  or2(&S_or2_1659_1);
  or2(&S_or2_1633_1);
  or2(&S_or2_1629_1);
  or2(&S_or2_2150_1);
  or2(&S_or2_2154_1);
  or2(&S_or2_2152_1);
  or2(&S_or2_2119_1);
  or2(&S_or2_2121_1);
  or2(&S_or2_2123_1);
  or2(&S_or2_1651_1);
  or2(&S_or2_1684_1);
  diagndev(&S_diagndev_2283_1);
  and2(&S_and2_2288_1);
  or2(&S_or2_2297_1);
  or2(&S_or2_2304_1);
  orn(&S_orn_2299_1);
  or3(&S_or3_2300_1);
  noto(&S_noto_672_1);
  noto(&S_noto_152_1);
  rs(&S_rs_729_1);
  noto(&S_noto_417_1);
  noto(&S_noto_661_1);
  noto(&S_noto_705_1);
  rs(&S_rs_738_1);
  noto(&S_noto_756_1);
  vmemb(&S_vmemb_669_1);
  vmemb(&S_vmemb_706_1);
  noto(&S_noto_745_1);
  vmemb(&S_vmemb_737_1);
  rs(&S_rs_624_1);
  rs(&S_rs_634_1);
  rs(&S_rs_614_1);
  noto(&S_noto_601_1);
  rs(&S_rs_642_1);
  noto(&S_noto_257_1);
  noto(&S_noto_637_1);
  noto(&S_noto_572_1);
  noto(&S_noto_981_1);
  noto(&S_noto_1382_1);
  noto(&S_noto_1003_1);
  noto(&S_noto_1903_1);
  kvf(&S_kvf_1479_1);
  noto(&S_noto_78_1);
  samhd(&S_samhd_2083_1);
  samhd(&S_samhd_2089_1);
  newstage(&S_newstage_2087_1);
  noto(&S_noto_1766_1);
  noto(&S_noto_1772_1);
  noto(&S_noto_1774_1);
  noto(&S_noto_1745_1);
  noto(&S_noto_1890_1);
  noto(&S_noto_1883_1);
  noto(&S_noto_1841_1);
  noto(&S_noto_503_1);
  noto(&S_noto_1209_1);
  noto(&S_noto_1224_1);
  noto(&S_noto_1815_1);
  rs(&S_rs_1490_1);
  kvf(&S_kvf_1485_1);
  rs(&S_rs_1484_1);
  noto(&S_noto_1495_1);
  noto(&S_noto_1493_1);
  rs(&S_rs_743_1);
  noto(&S_noto_344_1);
  noto(&S_noto_340_1);
  noto(&S_noto_582_1);
  noto(&S_noto_592_1);
  noto(&S_noto_645_1);
  noto(&S_noto_1912_1);
  noto(&S_noto_1937_1);
  swtakt(&S_swtakt_52_1);
  rs(&S_rs_1069_1);
  and2(&S_and2_753_1);
  and2(&S_and2_11_1);
  and2(&S_and2_112_1);
  and2(&S_and2_229_1);
  and2(&S_and2_547_1);
  or2(&S_or2_14_1);
  or2(&S_or2_8_1);
  or2(&S_or2_166_1);
  and3(&S_and3_699_1);
  and2(&S_and2_670_1);
  or3(&S_or3_733_1);
  and2(&S_and2_730_1);
  and2(&S_and2_651_1);
  or2(&S_or2_265_1);
  and3(&S_and3_281_1);
  or2(&S_or2_635_1);
  and2(&S_and2_604_1);
  and2(&S_and2_594_1);
  and4(&S_and4_595_1);
  and4(&S_and4_605_1);
  and2(&S_and2_630_1);
  or2(&S_or2_638_1);
  or2(&S_or2_641_1);
  and3(&S_and3_335_1);
  and2(&S_and2_500_1);
  or2(&S_or2_505_1);
  and2(&S_and2_557_1);
  and2(&S_and2_569_1);
  or2(&S_or2_182_1);
  and2(&S_and2_242_1);
  and2(&S_and2_254_1);
  and2(&S_and2_978_1);
  and2(&S_and2_1364_1);
  and2(&S_and2_1379_1);
  and2(&S_and2_1206_1);
  or2(&S_or2_1213_1);
  and2(&S_and2_1220_1);
  or2(&S_or2_1233_1);
  and2(&S_and2_998_1);
  and2(&S_and2_1008_1);
  or2(&S_or2_1470_1);
  and2(&S_and2_1432_1);
  and2(&S_and2_1482_1);
  or3(&S_or3_1496_1);
  or2(&S_or2_1478_1);
  and2(&S_and2_1488_1);
  or3(&S_or3_1489_1);
  or3(&S_or3_1502_1);
  or3(&S_or3_2082_1);
  or3(&S_or3_2091_1);
  or2(&S_or2_1762_1);
  or3(&S_or3_1764_1);
  or2(&S_or2_1802_1);
  and2(&S_and2_1810_1);
  or3(&S_or3_1806_1);
  and2(&S_and2_1832_1);
  or2(&S_or2_2036_1);
  or2(&S_or2_1964_1);
  or2(&S_or2_1953_1);
  and2(&S_and2_1933_1);
  and2(&S_and2_1931_1);
  and2(&S_and2_1916_1);
  and2(&S_and2_1915_1);
  and2(&S_and2_1885_1);
  and4(&S_and4_1891_1);
  and4(&S_and4_1892_1);
  or2(&S_or2_1894_1);
  or2(&S_or2_1896_1);
  or2(&S_or2_1895_1);
  zpfs(&S_zpfs_1899_1);
  zpfs(&S_zpfs_1902_1);
  zpfs(&S_zpfs_1886_1);
  and2(&S_and2_1887_1);
  or3(&S_or3_1904_1);
  lk(&S_lk_1480_1);
  rsfn(&S_rsfn_1469_1);
  abs_subf(&S_abs_subf_1491_1);
  lk(&S_lk_1477_1);
  rsfn(&S_rsfn_1474_1);
  abs_subf(&S_abs_subf_1486_1);
  and3(&S_and3_1847_1);
  or2(&S_or2_1854_1);
  or2(&S_or2_1855_1);
  zpfs(&S_zpfs_1861_1);
  zpfs(&S_zpfs_1863_1);
  or3(&S_or3_1866_1);
  or2(&S_or2_1868_1);
  and2(&S_and2_963_1);
  or2(&S_or2_249_1);
  ovbs(&S_ovbs_1869_1);
  ovbs(&S_ovbs_13_1);
  or2(&S_or2_1472_1);
  noto(&S_noto_103_1);
  bol(&S_bol_1528_1);
  bol(&S_bol_1519_1);
  or2(&S_or2_1524_1);
  ml(&S_ml_1535_1);
  ml(&S_ml_1515_1);
  ml(&S_ml_1537_1);
  ml(&S_ml_1516_1);
  and2(&S_and2_118_1);
  noto(&S_noto_116_1);
  and2(&S_and2_122_1);
  and2(&S_and2_121_1);
  noto(&S_noto_190_1);
  noto(&S_noto_463_1);
  noto(&S_noto_914_1);
  noto(&S_noto_1169_1);
  noto(&S_noto_1221_1);
  bol(&S_bol_1780_1);
  and3(&S_and3_1771_1);
  bol(&S_bol_1744_1);
  and3(&S_and3_1752_1);
  noto(&S_noto_1759_1);
  noto(&S_noto_1770_1);
  bol(&S_bol_905_1);
  bol(&S_bol_1308_1);
  abs_subf(&S_abs_subf_1521_1);
  noto(&S_noto_1530_1);
  abs_subf(&S_abs_subf_1540_1);
  noto(&S_noto_1549_1);
  bol(&S_bol_2227_1);
  and2(&S_and2_2237_1);
  noto(&S_noto_2198_1);
  fsumo(&S_fsumo_80_1);
  abs_subf(&S_abs_subf_2234_1);
  and2(&S_and2_2239_1);
  and3(&S_and3_2188_1);
  and2(&S_and2_2210_1);
  ovbs(&S_ovbs_2211_1);
  or3(&S_or3_2219_1);
  inf(&S_inf_2191_1);
  noto(&S_noto_1309_1);
  or2(&S_or2_1068_1);
  and2(&S_and2_2037_1);
  and2(&S_and2_105_1);
  and3(&S_and3_1394_1);
  noto(&S_noto_2156_1);
  noto(&S_noto_2125_1);
  rs(&S_rs_734_1);
  noto(&S_noto_749_1);
  noto(&S_noto_1251_1);
  noto(&S_noto_845_1);
  noto(&S_noto_211_1);
  rs(&S_rs_616_1);
  noto(&S_noto_529_1);
  noto(&S_noto_942_1);
  noto(&S_noto_1343_1);
  kvf(&S_kvf_1862_1);
  kvf(&S_kvf_1901_1);
  andn(&S_andn_1758_1);
  rs(&S_rs_19_1);
  noto(&S_noto_140_1);
  noto(&S_noto_1816_1);
  noto(&S_noto_111_1);
  noto(&S_noto_1385_1);
  abs_subf(&S_abs_subf_1009_1);
  abs_subf(&S_abs_subf_996_1);
  noto(&S_noto_1016_1);
  bol(&S_bol_1029_1);
  bol(&S_bol_1030_1);
  noto(&S_noto_993_1);
  bol(&S_bol_1032_1);
  bol(&S_bol_1033_1);
  bol(&S_bol_81_1);
  and2(&S_and2_31_1);
  and2(&S_and2_145_1);
  and2(&S_and2_153_1);
  and2(&S_and2_150_1);
  and2(&S_and2_142_1);
  and3(&S_and3_231_1);
  and3(&S_and3_549_1);
  and3(&S_and3_987_1);
  or3(&S_or3_108_1);
  or2(&S_or2_662_1);
  and2(&S_and2_671_1);
  and2(&S_and2_673_1);
  and2(&S_and2_685_1);
  and2(&S_and2_687_1);
  and2(&S_and2_700_1);
  and2(&S_and2_703_1);
  and3(&S_and3_702_1);
  and2(&S_and2_704_1);
  or2(&S_or2_740_1);
  and2(&S_and2_748_1);
  or2(&S_or2_754_1);
  or2(&S_or2_758_1);
  and3(&S_and3_755_1);
  and2(&S_and2_760_1);
  and2(&S_and2_764_1);
  and2(&S_and2_648_1);
  or2(&S_or2_649_1);
  and2(&S_and2_657_1);
  and2(&S_and2_659_1);
  and2(&S_and2_628_1);
  and2(&S_and2_606_1);
  and2(&S_and2_596_1);
  and3(&S_and3_527_1);
  or2(&S_or2_564_1);
  and3(&S_and3_209_1);
  and3(&S_and3_244_1);
  and3(&S_and3_852_1);
  and3(&S_and3_853_1);
  or2(&S_or2_973_1);
  or2(&S_or2_1374_1);
  and3(&S_and3_1258_1);
  and3(&S_and3_1259_1);
  or2(&S_or2_1034_1);
  or2(&S_or2_1046_1);
  or2(&S_or2_1044_1);
  or2(&S_or2_1043_1);
  or2(&S_or2_1042_1);
  and2(&S_and2_1397_1);
  and2(&S_and2_1403_1);
  and2(&S_and2_1405_1);
  and2(&S_and2_1407_1);
  and2(&S_and2_1413_1);
  and2(&S_and2_1417_1);
  or3(&S_or3_1441_1);
  and2(&S_and2_1442_1);
  and3(&S_and3_1499_1);
  or3(&S_or3_1483_1);
  and2(&S_and2_1497_1);
  and3(&S_and3_1500_1);
  zpfs(&S_zpfs_2034_1);
  and3(&S_and3_1925_1);
  and2(&S_and2_1920_1);
  or3(&S_or3_1926_1);
  and2(&S_and2_1898_1);
  and4(&S_and4_1906_1);
  and4(&S_and4_1908_1);
  lk(&S_lk_1905_1);
  rsfn(&S_rsfn_1909_1);
  abs_subf(&S_abs_subf_1911_1);
  and3(&S_and3_1914_1);
  lk(&S_lk_1867_1);
  rsfn(&S_rsfn_1870_1);
  abs_subf(&S_abs_subf_1872_1);
  and2(&S_and2_1860_1);
  and3(&S_and3_1864_1);
  or5(&S_or5_147_1);
  and2(&S_and2_1833_1);
  and2(&S_and2_106_1);
  and2(&S_and2_102_1);
  ml(&S_ml_1513_1);
  zpfs(&S_zpfs_741_1);
  and2(&S_and2_1735_1);
  and2(&S_and2_1712_1);
  and2(&S_and2_1733_1);
  and2(&S_and2_1736_1);
  and2(&S_and2_1713_1);
  and2(&S_and2_1734_1);
  and2(&S_and2_1714_1);
  and2(&S_and2_1715_1);
  and2(&S_and2_1717_1);
  and2(&S_and2_1718_1);
  and2(&S_and2_1720_1);
  and2(&S_and2_1721_1);
  and2(&S_and2_1688_1);
  and2(&S_and2_1689_1);
  rs(&S_rs_1690_1);
  and2(&S_and2_1691_1);
  and2(&S_and2_1692_1);
  rs(&S_rs_1693_1);
  and2(&S_and2_1671_1);
  and2(&S_and2_1675_1);
  and2(&S_and2_1638_1);
  and2(&S_and2_1640_1);
  and2(&S_and2_1642_1);
  and2(&S_and2_1644_1);
  and2(&S_and2_1612_1);
  and2(&S_and2_1613_1);
  and2(&S_and2_1614_1);
  and2(&S_and2_1615_1);
  and2(&S_and2_1616_1);
  and2(&S_and2_1617_1);
  and2(&S_and2_1618_1);
  and2(&S_and2_1619_1);
  and2(&S_and2_117_1);
  abs_subf(&S_abs_subf_1517_1);
  noto(&S_noto_1525_1);
  ovbs(&S_ovbs_2189_1);
  and2(&S_and2_2235_1);
  noto(&S_noto_2218_1);
  noto(&S_noto_2166_1);
  noto(&S_noto_2167_1);
  and2(&S_and2_2135_1);
  or4(&S_or4_889_1);
  and2(&S_and2_2104_1);
  or4(&S_or4_1295_1);
  and4(&S_and4_948_1);
  and4(&S_and4_1349_1);
  or3(&S_or3_1725_1);
  or3(&S_or3_1696_1);
  or3(&S_or3_1699_1);
  or3(&S_or3_1728_1);
  or3(&S_or3_1680_1);
  or3(&S_or3_1682_1);
  or3(&S_or3_1631_1);
  or3(&S_or3_1627_1);
  or3(&S_or3_2142_1);
  or3(&S_or3_2111_1);
  or3(&S_or3_2144_1);
  or3(&S_or3_2146_1);
  or3(&S_or3_2115_1);
  or3(&S_or3_2113_1);
  or2(&S_or2_1657_1);
  or2(&S_or2_1624_1);
  or2(&S_or2_2148_1);
  and2(&S_and2_2132_1);
  or2(&S_or2_2117_1);
  and2(&S_and2_2102_1);
  or2(&S_or2_1649_1);
  or2(&S_or2_1621_1);
  or2(&S_or2_1678_1);
  and2(&S_and2_1674_1);
  samhd(&S_samhd_383_1);
  samhd(&S_samhd_389_1);
  samhd(&S_samhd_778_1);
  samhd(&S_samhd_782_1);
  rs(&S_rs_750_1);
  rs(&S_rs_757_1);
  newstage(&S_newstage_386_1);
  newstage(&S_newstage_780_1);
  orn(&S_orn_146_1);
  rs(&S_rs_1620_1);
  rs(&S_rs_1622_1);
  rs(&S_rs_1623_1);
  rs(&S_rs_1625_1);
  rs(&S_rs_1626_1);
  rs(&S_rs_1628_1);
  rs(&S_rs_1630_1);
  rs(&S_rs_1632_1);
  rs(&S_rs_1650_1);
  rs(&S_rs_1658_1);
  rs(&S_rs_1677_1);
  rs(&S_rs_1685_1);
  rs(&S_rs_1695_1);
  rs(&S_rs_2149_1);
  rs(&S_rs_1724_1);
  rs(&S_rs_1716_1);
  rs(&S_rs_1727_1);
  rs(&S_rs_1719_1);
  rs(&S_rs_1730_1);
  rs(&S_rs_1668_1);
  rs(&S_rs_1669_1);
  rs(&S_rs_1670_1);
  rs(&S_rs_1634_1);
  rs(&S_rs_1635_1);
  rs(&S_rs_1636_1);
  rs(&S_rs_1637_1);
  rs(&S_rs_109_1);
  noto(&S_noto_110_1);
  rs(&S_rs_1505_1);
  rs(&S_rs_1504_1);
  rs(&S_rs_1434_1);
  kvf(&S_kvf_1438_1);
  rs(&S_rs_1919_1);
  rs(&S_rs_1865_1);
  noto(&S_noto_1437_1);
  andn(&S_andn_264_1);
  noto(&S_noto_282_1);
  and2(&S_and2_407_1);
  and2(&S_and2_418_1);
  and2(&S_and2_426_1);
  and2(&S_and2_427_1);
  and2(&S_and2_428_1);
  or3(&S_or3_379_1);
  or3(&S_or3_394_1);
  and2(&S_and2_408_1);
  and3(&S_and3_584_1);
  or2(&S_or2_149_1);
  and2(&S_and2_676_1);
  and2(&S_and2_736_1);
  or2(&S_or2_763_1);
  and2(&S_and2_655_1);
  or2(&S_or2_272_1);
  and3(&S_and3_273_1);
  or2(&S_or2_436_1);
  and3(&S_and3_443_1);
  or2(&S_or2_489_1);
  and2(&S_and2_509_1);
  and3(&S_and3_559_1);
  and3(&S_and3_558_1);
  and2(&S_and2_186_1);
  and3(&S_and3_243_1);
  or4(&S_or4_774_1);
  or4(&S_or4_790_1);
  or3(&S_or3_846_1);
  and2(&S_and2_842_1);
  and3(&S_and3_843_1);
  and2(&S_and2_841_1);
  and2(&S_and2_854_1);
  and2(&S_and2_871_1);
  and3(&S_and3_872_1);
  and2(&S_and2_936_1);
  or2(&S_or2_940_1);
  and2(&S_and2_949_1);
  and2(&S_and2_966_1);
  and3(&S_and3_967_1);
  and3(&S_and3_968_1);
  or2(&S_or2_1341_1);
  and2(&S_and2_1350_1);
  and2(&S_and2_1367_1);
  and3(&S_and3_1368_1);
  and3(&S_and3_1369_1);
  and2(&S_and2_1337_1);
  or3(&S_or3_1252_1);
  and3(&S_and3_1249_1);
  and2(&S_and2_1248_1);
  and2(&S_and2_1247_1);
  and2(&S_and2_1260_1);
  and2(&S_and2_1272_1);
  and3(&S_and3_1273_1);
  and2(&S_and2_1277_1);
  and3(&S_and3_1278_1);
  and2(&S_and2_1214_1);
  and2(&S_and2_1235_1);
  and2(&S_and2_1047_1);
  and2(&S_and2_1050_1);
  or2(&S_or2_1429_1);
  or3(&S_or3_1433_1);
  or2(&S_or2_1731_1);
  or2(&S_or2_2060_1);
  or2(&S_or2_2064_1);
  lk(&S_lk_1439_1);
  rsfn(&S_rsfn_1435_1);
  abs_subf(&S_abs_subf_1444_1);
  ovbs(&S_ovbs_2052_1);
  ovbs(&S_ovbs_115_1);
  and2(&S_and2_470_1);
  and2(&S_and2_437_1);
  and2(&S_and2_434_1);
  rs(&S_rs_1732_1);
  rs(&S_rs_1698_1);
  and2(&S_and2_1672_1);
  and2(&S_and2_1673_1);
  and2(&S_and2_1676_1);
  and2(&S_and2_1641_1);
  and2(&S_and2_1645_1);
  zpfs(&S_zpfs_2174_1);
  zpfs(&S_zpfs_2175_1);
  and2(&S_and2_2048_1);
  and2(&S_and2_2059_1);
  and3(&S_and3_409_1);
  and2(&S_and2_2047_1);
  and2(&S_and2_2070_1);
  rs(&S_rs_2141_1);
  rs(&S_rs_2129_1);
  rs(&S_rs_2133_1);
  and2(&S_and2_2139_1);
  rs(&S_rs_2151_1);
  rs(&S_rs_2134_1);
  and2(&S_and2_2140_1);
  rs(&S_rs_2153_1);
  rs(&S_rs_2118_1);
  rs(&S_rs_2110_1);
  rs(&S_rs_2098_1);
  rs(&S_rs_2101_1);
  and2(&S_and2_2108_1);
  rs(&S_rs_2120_1);
  rs(&S_rs_2103_1);
  and2(&S_and2_2109_1);
  rs(&S_rs_2122_1);
  regch(&S_regch_125_1);
  rs(&S_rs_1683_1);
  rs(&S_rs_727_1);
  rs(&S_rs_762_1);
  rs(&S_rs_589_1);
  noto(&S_noto_603_1);
  orni(&S_orni_1402_1);
  noto(&S_noto_2053_1);
  rs(&S_rs_1652_1);
  rs(&S_rs_1660_1);
  rs(&S_rs_1679_1);
  rs(&S_rs_1681_1);
  rs(&S_rs_1687_1);
  ma(&S_ma_1440_1);
  rs(&S_rs_599_1);
  noto(&S_noto_983_1);
  noto(&S_noto_277_1);
  noto(&S_noto_1045_1);
  noto(&S_noto_1039_1);
  noto(&S_noto_1012_1);
  and2(&S_and2_411_1);
  and2(&S_and2_429_1);
  and2(&S_and2_866_1);
  and3(&S_and3_867_1);
  and3(&S_and3_961_1);
  and3(&S_and3_1362_1);
  and2(&S_and2_623_1);
  and2(&S_and2_937_1);
  and2(&S_and2_938_1);
  and3(&S_and3_939_1);
  and2(&S_and2_1338_1);
  and2(&S_and2_1339_1);
  and3(&S_and3_1340_1);
  and5(&S_and5_988_1);
  and2(&S_and2_1035_1);
  or4(&S_or4_995_1);
  and3(&S_and3_1448_1);
  or2(&S_or2_1820_1);
  and2(&S_and2_1823_1);
  and2(&S_and2_2071_1);
  ovbs(&S_ovbs_2056_1);
  noto(&S_noto_2179_1);
  noto(&S_noto_2180_1);
  andn(&S_andn_587_1);
  andn(&S_andn_588_1);
  and2(&S_and2_2074_1);
  or5(&S_or5_2072_1);
  or5(&S_or5_2073_1);
  and2(&S_and2_2136_1);
  or3(&S_or3_1198_1);
  rs(&S_rs_2143_1);
  rs(&S_rs_2130_1);
  and2(&S_and2_2105_1);
  rs(&S_rs_2112_1);
  rs(&S_rs_2099_1);
  or3(&S_or3_809_1);
  or2(&S_or2_128_1);
  rs(&S_rs_994_1);
  noto(&S_noto_2057_1);
  rs(&S_rs_2061_1);
  rs(&S_rs_2065_1);
  rs(&S_rs_1451_1);
  noto(&S_noto_1013_1);
  provsbr(&S_provsbr_1399_1);
  rs(&S_rs_1398_1);
  and2(&S_and2_537_1);
  and2(&S_and2_219_1);
  and2(&S_and2_856_1);
  and2(&S_and2_951_1);
  and2(&S_and2_1352_1);
  and2(&S_and2_1262_1);
  and3(&S_and3_1000_1);
  and3(&S_and3_1006_1);
  and2(&S_and2_1023_1);
  and2(&S_and2_1011_1);
  and3(&S_and3_1057_1);
  or2(&S_or2_1404_1);
  or2(&S_or2_1406_1);
  or2(&S_or2_1408_1);
  or2(&S_or2_1414_1);
  or2(&S_or2_1418_1);
  orni(&S_orni_1410_1);
  or2(&S_or2_1818_1);
  or2(&S_or2_2049_1);
  noto(&S_noto_2186_1);
  and2(&S_and2_2137_1);
  and2(&S_and2_2106_1);
  rs(&S_rs_2131_1);
  and2(&S_and2_2138_1);
  rs(&S_rs_2147_1);
  rs(&S_rs_2100_1);
  and2(&S_and2_2050_1);
  noto(&S_noto_2066_1);
  rs(&S_rs_2145_1);
  newstage(&S_newstage_1811_1);
  cntch(&S_cntch_1409_1);
  rs(&S_rs_1018_1);
  rs(&S_rs_1051_1);
  rs(&S_rs_1025_1);
  noto(&S_noto_1026_1);
  or3(&S_or3_156_1);
  or3(&S_or3_479_1);
  or2(&S_or2_1048_1);
  and2(&S_and2_1411_1);
  or2(&S_or2_1573_1);
  zpfs(&S_zpfs_2046_1);
  rs(&S_rs_2114_1);
  and2(&S_and2_2107_1);
  rs(&S_rs_2116_1);
  cnshd(&S_cnshd_1580_1);
  noto(&S_noto_864_1);
  ornc(&S_ornc_163_1);
  charint(&S_charint_157_1);
  noto(&S_noto_227_1);
  ornc(&S_ornc_487_1);
  charint(&S_charint_481_1);
  noto(&S_noto_545_1);
  noto(&S_noto_959_1);
  noto(&S_noto_1360_1);
  rs(&S_rs_1036_1);
  or2(&S_or2_1599_1);
  and2(&S_and2_1551_1);
  and2(&S_and2_1552_1);
  and2(&S_and2_1553_1);
  and2(&S_and2_1554_1);
  and2(&S_and2_1560_1);
  and2(&S_and2_1562_1);
  and2(&S_and2_1564_1);
  and2(&S_and2_1024_1);
  fnapb(&S_fnapb_1600_1);
  samhd(&S_samhd_1583_1);
  zpfs(&S_zpfs_1597_1);
  zpfs(&S_zpfs_1593_1);
  noto(&S_noto_1270_1);
  fsumz(&S_fsumz_158_1);
  fsumz(&S_fsumz_482_1);
  orni(&S_orni_1158_1);
  rs(&S_rs_1020_1);
  rs(&S_rs_1021_1);
  ma(&S_ma_164_1);
  ma(&S_ma_488_1);
  zpfs(&S_zpfs_1601_1);
  or2(&S_or2_1111_1);
  or3(&S_or3_1019_1);
  or3(&S_or3_1590_1);
  samhd(&S_samhd_1163_1);
  samhd(&S_samhd_1174_1);
  newstage(&S_newstage_1168_1);
  cnshd(&S_cnshd_1113_1);
  noto(&S_noto_1269_1);
  noto(&S_noto_863_1);
  fnapb(&S_fnapb_197_1);
  noto(&S_noto_226_1);
  fnapb(&S_fnapb_517_1);
  zpfs(&S_zpfs_512_1);
  zpfs(&S_zpfs_510_1);
  noto(&S_noto_544_1);
  noto(&S_noto_958_1);
  noto(&S_noto_1359_1);
  or2(&S_or2_1162_1);
  or2(&S_or2_1176_1);
  or2(&S_or2_1135_1);
  and2(&S_and2_1087_1);
  and2(&S_and2_1084_1);
  and2(&S_and2_1085_1);
  and2(&S_and2_1086_1);
  and2(&S_and2_1092_1);
  and2(&S_and2_1094_1);
  and2(&S_and2_1096_1);
  and2(&S_and2_625_1);
  zpfs(&S_zpfs_518_1);
  or2(&S_or2_539_1);
  zpfs(&S_zpfs_198_1);
  zpfs(&S_zpfs_192_1);
  zpfs(&S_zpfs_187_1);
  or2(&S_or2_221_1);
  or2(&S_or2_858_1);
  and2(&S_and2_857_1);
  or2(&S_or2_953_1);
  or2(&S_or2_1354_1);
  or2(&S_or2_1264_1);
  and2(&S_and2_1263_1);
  and2(&S_and2_1015_1);
  or2(&S_or2_1027_1);
  and2(&S_and2_1166_1);
  and2(&S_and2_1170_1);
  or4(&S_or4_1943_1);
  fnapb(&S_fnapb_1136_1);
  samhd(&S_samhd_1118_1);
  zpfs(&S_zpfs_1132_1);
  zpfs(&S_zpfs_1128_1);
  orn(&S_orn_1271_1);
  orn(&S_orn_865_1);
  rs(&S_rs_1014_1);
  zpfs(&S_zpfs_1137_1);
  and2(&S_and2_538_1);
  and2(&S_and2_220_1);
  and2(&S_and2_952_1);
  and2(&S_and2_1353_1);
  and2(&S_and2_1028_1);
  or2(&S_or2_1022_1);
  or3(&S_or3_1125_1);
  or2(&S_or2_1960_1);
  or2(&S_or2_1949_1);
  ovbs(&S_ovbs_1944_1);
  ovbs(&S_ovbs_1956_1);
  ovbs(&S_ovbs_1947_1);
  noto(&S_noto_1948_1);
  and2(&S_and2_1954_1);
  and2(&S_and2_1965_1);
  or3(&S_or3_126_1);
  orn(&S_orn_228_1);
  orn(&S_orn_960_1);
  orn(&S_orn_1361_1);
  noto(&S_noto_1945_1);
  noto(&S_noto_1957_1);
  rs(&S_rs_1961_1);
  noto(&S_noto_1962_1);
  rs(&S_rs_1950_1);
  rs(&S_rs_1066_1);
  or2(&S_or2_1917_1);
  irm(&S_irm_2170_1);
  ml(&S_ml_884_1);
  ml(&S_ml_1290_1);
  noto(&S_noto_1951_1);
  noto(&S_noto_66_1);
  noto(&S_noto_1918_1);
  and2(&S_and2_58_1);
  and2(&S_and2_62_1);
  and4(&S_and4_329_1);
  or2(&S_or2_1391_1);
  or2(&S_or2_1934_1);
  noto(&S_noto_1387_1);
  rs(&S_rs_332_1);
  noto(&S_noto_327_1);
  noto(&S_noto_269_1);
  rs(&S_rs_1935_1);
  rs(&S_rs_1936_1);
  or4(&S_or4_280_1);
  or2(&S_or2_263_1);
  or2(&S_or2_286_1);
  or2(&S_or2_324_1);
  or4(&S_or4_333_1);
  and2(&S_and2_1386_1);
  or2(&S_or2_1996_1);
  or2(&S_or2_2017_1);
  rs(&S_rs_279_1);
  provsbr(&S_provsbr_268_1);
  equz_p(&S_equz_p_307_1);
  bolz(&S_bolz_308_1);
  provsbr(&S_provsbr_326_1);
  bolz(&S_bolz_331_1);
  noto(&S_noto_67_1);
  noto(&S_noto_56_1);
  and2(&S_and2_59_1);
  and2(&S_and2_63_1);
  or2(&S_or2_60_1);
  and2(&S_and2_561_1);
  and2(&S_and2_560_1);
  and2(&S_and2_283_1);
  and4(&S_and4_313_1);
  and2(&S_and2_295_1);
  or2(&S_or2_285_1);
  and2(&S_and2_290_1);
  or2(&S_or2_337_1);
  and2(&S_and2_328_1);
  orn(&S_orn_546_1);
  and2(&S_and2_245_1);
  and2(&S_and2_246_1);
  or3(&S_or3_256_1);
  and2(&S_and2_874_1);
  and2(&S_and2_873_1);
  or3(&S_or3_879_1);
  and2(&S_and2_970_1);
  and2(&S_and2_969_1);
  and2(&S_and2_1370_1);
  and2(&S_and2_1371_1);
  and2(&S_and2_1279_1);
  and2(&S_and2_1280_1);
  or3(&S_or3_1285_1);
  or2(&S_or2_1388_1);
  or3(&S_or3_1419_1);
  or3(&S_or3_1458_1);
  or3(&S_or3_1475_1);
  or3(&S_or3_1877_1);
  or3(&S_or3_1839_1);
  or4(&S_or4_1381_1);
  or4(&S_or4_980_1);
  maz(&S_maz_294_1);
  maz(&S_maz_303_1);
  orni(&S_orni_1171_1);
  orni(&S_orni_284_1);
  rs(&S_rs_336_1);
  decatron(&S_decatron_293_1);
  orni(&S_orni_330_1);
  noto(&S_noto_305_1);
  swtakt(&S_swtakt_1843_1);
  swtakt(&S_swtakt_1878_1);
  swtakt(&S_swtakt_1464_1);
  swtakt(&S_swtakt_1468_1);
  swtakt(&S_swtakt_1424_1);
  or3(&S_or3_571_1);
  or2(&S_or2_289_1);
  or2(&S_or2_298_1);
  or2(&S_or2_312_1);
  or2(&S_or2_311_1);
  and2(&S_and2_315_1);
  and2(&S_and2_310_1);
  and2(&S_and2_317_1);
  and2(&S_and2_316_1);
  and3(&S_and3_296_1);
  or5(&S_or5_501_1);
  or5(&S_or5_180_1);
  and2(&S_and2_1389_1);
  or2(&S_or2_2039_1);
  or2(&S_or2_2027_1);
  or3(&S_or3_1383_1);
  or3(&S_or3_982_1);
  zpfs(&S_zpfs_309_1);
  cnshd(&S_cnshd_168_1);
  cnshd(&S_cnshd_490_1);
  equz_p(&S_equz_p_297_1);
  noto(&S_noto_1395_1);
  cntch(&S_cntch_287_1);
  rs(&S_rs_288_1);
  cntch(&S_cntch_334_1);
  and2(&S_and2_302_1);
  or5(&S_or5_1412_1);
  or5(&S_or5_1390_1);
  and2(&S_and2_1392_1);
  or2(&S_or2_1393_1);
  and4(&S_and4_1921_1);
  and3(&S_and3_1922_1);
  and3(&S_and3_1923_1);
  and2(&S_and2_1884_1);
  and2(&S_and2_1838_1);
  or3(&S_or3_1852_1);
  newstage(&S_newstage_205_1);
  rs(&S_rs_1889_1);
  rs(&S_rs_1844_1);
  rs(&S_rs_1853_1);
  and2(&S_and2_322_1);
  or3(&S_or3_1888_1);
  and2(&S_and2_194_1);
  and2(&S_and2_191_1);
  noto(&S_noto_323_1);
  and2(&S_and2_1080_1);
  and2(&S_and2_632_1);
  or2(&S_or2_620_1);
  and2(&S_and2_1040_1);
  rs(&S_rs_621_1);
  rs(&S_rs_1037_1);
  noto(&S_noto_1038_1);
  rs(&S_rs_1072_1);
  and2(&S_and2_639_1);
  and3(&S_and3_608_1);
  and3(&S_and3_598_1);
  or3(&S_or3_805_1);
  or3(&S_or3_1194_1);
  and4(&S_and4_1001_1);
  and4(&S_and4_1007_1);
  or2(&S_or2_1071_1);
  or4(&S_or4_880_1);
  or4(&S_or4_1286_1);
  ornc(&S_ornc_890_1);
  charint(&S_charint_882_1);
  ornc(&S_ornc_1296_1);
  charint(&S_charint_1288_1);
  fsumz(&S_fsumz_883_1);
  fsumz(&S_fsumz_1289_1);
  ma(&S_ma_1297_1);
  ma(&S_ma_891_1);
  fnapb(&S_fnapb_925_1);
  zpfs(&S_zpfs_918_1);
  zpfs(&S_zpfs_916_1);
  fnapb(&S_fnapb_1326_1);
  zpfs(&S_zpfs_1319_1);
  zpfs(&S_zpfs_1317_1);
  zpfs(&S_zpfs_926_1);
  zpfs(&S_zpfs_1327_1);
  and2(&S_and2_1312_1);
  and2(&S_and2_909_1);
  or5(&S_or5_908_1);
  or5(&S_or5_1311_1);
  or2(&S_or2_2221_1);
  cnshd(&S_cnshd_892_1);
  cnshd(&S_cnshd_1298_1);
  noto(&S_noto_2220_1);
  newstage(&S_newstage_904_1);
  and2(&S_and2_911_1);
  and2(&S_and2_915_1);
  andn(&S_andn_2194_1);
  noto(&S_noto_2216_1);
  and2(&S_and2_2217_1);
  or2(&S_or2_2215_1);
  and3(&S_and3_2169_1);
  and2(&S_and2_2044_1);
  and2(&S_and2_2035_1);
  or3(&S_or3_2031_1);
  or3(&S_or3_2045_1);
  rs(&S_rs_2028_1);
  noto(&S_noto_2029_1);
  rs(&S_rs_2040_1);
  noto(&S_noto_2041_1);
  and2(&S_and2_1081_1);
  and2(&S_and2_631_1);
  and2(&S_and2_1056_1);
  rs(&S_rs_2214_1);
  rs(&S_rs_1049_1);
  noto(&S_noto_1052_1);
  rs(&S_rs_1075_1);
  and3(&S_and3_1041_1);
  and2(&S_and2_992_1);
  and4(&S_and4_999_1);
  and4(&S_and4_1005_1);
  or2(&S_or2_1074_1);
  orn(&S_orn_1186_1);
  orn(&S_orn_797_1);
  ornc(&S_ornc_1195_1);
  charint(&S_charint_1187_1);
  ornc(&S_ornc_806_1);
  charint(&S_charint_798_1);
  rs(&S_rs_986_1);
  or3(&S_or3_435_1);
  and3(&S_and3_442_1);
  and2(&S_and2_1031_1);
  and2(&S_and2_474_1);
  and2(&S_and2_445_1);
  fsumz(&S_fsumz_1188_1);
  fsumz(&S_fsumz_799_1);
  samhd(&S_samhd_455_1);
  samhd(&S_samhd_461_1);
  newstage(&S_newstage_457_1);
  ma(&S_ma_807_1);
  ma(&S_ma_1196_1);
  or4(&S_or4_451_1);
  or4(&S_or4_469_1);
  and2(&S_and2_466_1);
  and2(&S_and2_464_1);
  fnapb(&S_fnapb_1230_1);
  zpfs(&S_zpfs_1226_1);
  zpfs(&S_zpfs_1227_1);
  fnapb(&S_fnapb_831_1);
  zpfs(&S_zpfs_1242_1);
  and2(&S_and2_1082_1);
  and2(&S_and2_647_1);
  zpfs(&S_zpfs_834_1);
  zpfs(&S_zpfs_826_1);
  zpfs(&S_zpfs_825_1);
  and2(&S_and2_1063_1);
  ovbsb(&S_ovbsb_822_1);
  ovbsb(&S_ovbsb_823_1);
  ovbsb(&S_ovbsb_832_1);
  ovbsb(&S_ovbsb_824_1);
  ovbsb(&S_ovbsb_1239_1);
  ovbsb(&S_ovbsb_1218_1);
  ovbsb(&S_ovbsb_1217_1);
  ovbsb(&S_ovbsb_1236_1);
  orni(&S_orni_132_1);
  orn(&S_orn_413_1);
  orn(&S_orn_431_1);
  rs(&S_rs_1058_1);
  rs(&S_rs_1078_1);
  or2(&S_or2_415_1);
  or2(&S_or2_432_1);
  and2(&S_and2_675_1);
  or2(&S_or2_1148_1);
  or2(&S_or2_1149_1);
  and2(&S_and2_1095_1);
  or5(&S_or5_817_1);
  or5(&S_or5_1207_1);
  and2(&S_and2_1563_1);
  or4(&S_or4_1559_1);
  or5(&S_or5_1967_1);
  orn(&S_orn_761_1);
  orn(&S_orn_1083_1);
  cnshd(&S_cnshd_1197_1);
  cnshd(&S_cnshd_808_1);
  or2(&S_or2_751_1);
  or2(&S_or2_752_1);
  or4(&S_or4_732_1);
  or5(&S_or5_1121_1);
  or2(&S_or2_357_1);
  or2(&S_or2_361_1);
  or5(&S_or5_1550_1);
  or4(&S_or4_1968_1);
  rs(&S_rs_731_1);
  samhd(&S_samhd_360_1);
  newstage(&S_newstage_1237_1);
  and2(&S_and2_719_1);
  or2(&S_or2_723_1);
  or4(&S_or4_359_1);
  or5(&S_or5_1587_1);
  ovbs(&S_ovbs_1974_1);
  noto(&S_noto_1975_1);
  and2(&S_and2_1981_1);
  and2(&S_and2_1993_1);
  or3(&S_or3_1969_1);
  and2(&S_and2_1970_1);
  or3(&S_or3_1983_1);
  and2(&S_and2_1984_1);
  andn(&S_andn_1_1);
  and2(&S_and2_1222_1);
  and2(&S_and2_1225_1);
  or2(&S_or2_2205_1);
  or3(&S_or3_1655_1);
  or3(&S_or3_1647_1);
  or2(&S_or2_1661_1);
  or2(&S_or2_1653_1);
  rs(&S_rs_725_1);
  rs(&S_rs_1646_1);
  rs(&S_rs_1654_1);
  or2(&S_or2_1988_1);
  or2(&S_or2_1976_1);
  ovbs(&S_ovbs_1971_1);
  ovbs(&S_ovbs_1985_1);
  rs(&S_rs_2004_1);
  rs(&S_rs_2012_1);
  noto(&S_noto_2002_1);
  noto(&S_noto_2023_1);
  and2(&S_and2_1639_1);
  and2(&S_and2_1643_1);
  zpfs(&S_zpfs_2005_1);
  zpfs(&S_zpfs_2013_1);
  noto(&S_noto_2201_1);
  rs(&S_rs_1648_1);
  rs(&S_rs_1656_1);
  or2(&S_or2_2006_1);
  noto(&S_noto_1972_1);
  noto(&S_noto_1986_1);
  rs(&S_rs_1989_1);
  noto(&S_noto_1990_1);
  rs(&S_rs_1977_1);
  or2(&S_or2_2014_1);
  noto(&S_noto_2007_1);
  and2(&S_and2_2008_1);
  and2(&S_and2_2003_1);
  noto(&S_noto_2015_1);
  noto(&S_noto_1995_1);
  noto(&S_noto_1978_1);
  and2(&S_and2_2016_1);
  and4(&S_and4_1997_1);
  ovbs(&S_ovbs_1998_1);
  and2(&S_and2_2024_1);
  noto(&S_noto_2025_1);
  or2(&S_or2_1999_1);
  orn(&S_orn_591_1);
  orn(&S_orn_590_1);
  noto(&S_noto_2000_1);
  and4(&S_and4_2018_1);
  ovbs(&S_ovbs_2019_1);
  or2(&S_or2_2020_1);
  newstage(&S_newstage_593_1);
  or2(&S_or2_627_1);
  ovbs(&S_ovbs_2009_1);
  noto(&S_noto_2021_1);
  and2(&S_and2_626_1);
  setData(idTestDiagnDU,&var9);
  setData(idR0DE3CLDU,&var12);
  setData(idR0DE3DLDU,&var11);
  setData(idTTLDU,&var15);
  setData(idB3AB13LDU,&var135);
  setData(idA3AB13LDU,&var138);
  setData(idR3VS01IDU,&var144);
  setData(idR3VS12LDU,&var142);
  setData(idR3VS22LDU,&var143);
  setData(idR5VS01IDU,&var141);
  setData(idR5VS12LDU,&var139);
  setData(idR5VS22LDU,&var140);
  setData(idB3AB15LDU,&var148);
  setData(idB3EE03LDU,&var816);
  setData(idA3EE03LDU,&var817);
  setData(idB3AB19LDU,&var153);
  setData(idA3AB19LDU,&var154);
  setData(idR0VL23LDU,&var1052);
  setData(idR0VL22LDU,&var1074);
  setData(idR0AD05LZ2,&var80);
  setData(idR0AD05LZ1,&var80);
  setData(idR0AD04LZ2,&var376);
  setData(idR0AD04LZ1,&var376);
  setData(idR0AD03LZ2,&var79);
  setData(idR0AD03LZ1,&var79);
  setData(idR0CN95LDU,&var224);
  setData(idR0CN94LDU,&var223);
  setData(idR0CN93LDU,&var222);
  setData(idR0AB19LDU,&var185);
  setData(idR0VN12RDU,&var985);
  setData(idR0VN11RDU,&var983);
  setData(idR0CN92LDU,&var189);
  setData(idR0AB20LDU,&var201);
  setData(idA3AB15LDU,&var149);
  setData(idA3MC03RDU,&var220);
  setData(idR0CN91LDU,&var219);
  setData(idA3MC02RDU,&var218);
  setData(idA3MC01RDU,&var217);
  setData(idR0AB18LDU,&var206);
  setData(idR0AB17LDU,&var213);
  setData(idR0AB16LDU,&var214);
  setData(idB1AB19LDU,&var231);
  setData(idA3ZAV,&var1324);
  setData(idA1ZAV,&var1387);
  setData(idB3IS12LDU,&var241);
  setData(idA3IS12LDU,&var242);
  setData(idR0AB15LDU,&var247);
  setData(idR0AB14LDU,&var245);
  setData(idA4DW,&var1162);
  setData(idA4UP,&var1163);
  setData(idR4ABL,&var1626);
  setData(idA9ZAV,&var1262);
  setData(idA8ZAV,&var1463);
  setData(idA2ZAV,&var1468);
  setData(idB8ZAV,&var1473);
  setData(idA5ZAV,&var1541);
  setData(idR2ZAV,&var1417);
  setData(idA6ZAV,&var1543);
  setData(idA4ZAV,&var1542);
  setData(idR0AB13LDU,&var314);
  setData(idR0AB12LDU,&var318);
  setData(idR0AB11LDU,&var322);
  setData(idR0AB10LDU,&var326);
  setData(idR0AB09LDU,&var330);
  setData(idR0AB08LDU,&var334);
  setData(idB6AB05LDU,&var377);
  setData(idR0VS11LDU,&var1672);
  setData(idA8VS01IDU,&var1467);
  setData(idB8VS01IDU,&var1477);
  setData(idR2AD10LDU,&var1422);
  setData(idR2AD20LDU,&var1423);
  setData(idB6VS01IDU,&var1614);
  setData(idR0AD16LDU,&lRM_0_);
  setData(idR0AB07LDU,&var616);
  setData(idR0EE03LDU,&var401);
  setData(idR0VX02LDU,&var822);
  setData(idR0AD21LDU,&var820);
  setData(idB2AB15LDU,&var347);
  setData(idA2AB15LDU,&var348);
  setData(idR0AB05LDU,&var1134);
  setData(idR0AB03LDU,&var1145);
  setData(idA1AB19LDU,&var232);
  setData(idR0VZ71LDU,&var66);
  setData(idR0VL01RDU,&var1180);
  setData(idB7AZ03LDU,&var378);
  setData(idA7AZ03LDU,&var486);
  setData(idB2VS01IDU,&var1455);
  setData(idB2VS21LDU,&var1457);
  setData(idB2VS11LDU,&var1456);
  setData(idR0VP73LDU,&var497);
  setData(idR0VS18LDU,&var574);
  setData(idB3VX01LDU,&var444);
  setData(idA3VX01LDU,&var445);
  setData(idB2VS32LDU,&var360);
  setData(idA2VS32LDU,&var361);
  setData(idR0VS17LDU,&var564);
  setData(idR0VX09LDU,&var177);
  moveData(idR0VX08IDU,idR0MW12IP1);
  setData(idR0VW23LDU,&var917);
  setData(idR0VW13LDU,&var916);
  setData(idB7AP31LDU,&var1165);
  setData(idA7AP31LDU,&var1166);
  setData(idB3AD31LDU,&var1225);
  setData(idB3AD34LDU,&var1226);
  setData(idA3AD31LDU,&var1231);
  setData(idA3AD34LDU,&var1228);
  setData(idA3AD33LDU,&var1230);
  setData(idB2AD33LDU,&var339);
  setData(idA2AD33LDU,&var342);
  setData(idR0AB01LDU,&var1254);
  setData(idB9AB02LDU,&var1264);
  setData(idB9AB01LDU,&var1265);
  setData(idB9AZ03LDU,&var1263);
  setData(idA9AB02LDU,&var1270);
  setData(idA9AB01LDU,&var1271);
  setData(idA9AZ03LDU,&var1269);
  setData(idA9AD10LDU,&var1272);
  setData(idB9AD10LDU,&var1266);
  setData(idR1VS01IDU,&var1433);
  setData(idR2VS01IDU,&var1424);
  setData(idR4VS01IDU,&var1605);
  setData(idA6VS01IDU,&var1623);
  setData(idB5VS01IDU,&var1587);
  setData(idA5VS01IDU,&var1596);
  setData(idB4VS22LDU,&var1568);
  setData(idB4VS12LDU,&var1567);
  setData(idB4VS01IDU,&var1569);
  setData(idA4VS22LDU,&var1577);
  setData(idA4VS12LDU,&var1576);
  setData(idA4VS01IDU,&var1578);
  setData(idA2VS01IDU,&var1496);
  setData(idB3VS01IDU,&var1314);
  setData(idA3VS01IDU,&var1346);
  setData(idB1VS01IDU,&var1375);
  setData(idA1VS01IDU,&var1408);
  setData(idR0VS21IDU,&var1155);
  setData(idR0VX03LDU,&var767);
  setData(idR0VL21IDU,&var1065);
  setData(idR0VL05RDU,&var431);
  setData(idR0VL03RDU,&var437);
  setData(idR0AB02LDU,&var1128);
  setData(idR0AB06LDU,&var1131);
  setData(idR0AB04LDU,&var1139);
  setData(idR0VL04RDU,&var434);
  setData(idR0AD14LDU,&var376);
  setData(idR8AD21LDU,&var399);
  setData(idR0VL02RDU,&var428);
  setData(idB3AD33LDU,&var1224);
  setData(idR0VL06RDU,&var441);
  setData(idR0VL11IDU,&var1278);
  setData(idR0VL01IDU,&var1279);
  setData(idR0VX01LDU,&var824);
  setData(idB1AD32LDU,&var1232);
  setData(idA1AD32LDU,&var1234);
  setData(idB2AD32LDU,&var367);
  setData(idA2AD32LDU,&var369);
  setData(idB1AD31LDU,&var1235);
  setData(idA1AD31LDU,&var1236);
  setData(idB2AD31LDU,&var370);
  setData(idA2AD31LDU,&var371);
  setData(idB3AB20LDU,&var658);
  setData(idB3AB18LDU,&var655);
  setData(idB3AB17LDU,&var651);
  setData(idB3AB16LDU,&var652);
  setData(idB3AB14LDU,&var926);
  setData(idB3AB12LDU,&var656);
  setData(idB3AB11LDU,&var660);
  setData(idB3AB10LDU,&var661);
  setData(idB3AB09LDU,&var662);
  setData(idB3AB06LDU,&var665);
  setData(idB3AB05LDU,&var667);
  setData(idB3AB08LDU,&var657);
  setData(idB3AB07LDU,&var666);
  setData(idB3CV02RDU,&var1313);
  setData(idB3AD01LDU,&var1306);
  setData(idB3AD05LDU,&var1312);
  setData(idB3AD04LDU,&var1311);
  setData(idB3AD03LDU,&var1310);
  setData(idB3AD02LDU,&var1309);
  setData(idB3AD21LDU,&var1307);
  setData(idB3AD11LDU,&var1308);
  setData(idB3AZ03LDU,&var998);
  setData(idB3VS22LDU,&var1317);
  setData(idB3AB01LDU,&var1315);
  setData(idB3AB02LDU,&var1316);
  setData(idB3AB04LDU,&var1321);
  setData(idB3CV01RDU,&var1319);
  setData(idB3VS12LDU,&var1318);
  setData(idA3AB20LDU,&var409);
  setData(idA3AB18LDU,&var672);
  setData(idA3AB17LDU,&var670);
  setData(idA3AB16LDU,&var669);
  setData(idA3AB14LDU,&var928);
  setData(idA3AB12LDU,&var673);
  setData(idA3AB11LDU,&var677);
  setData(idA3AB10LDU,&var681);
  setData(idA3AB09LDU,&var675);
  setData(idA3AB06LDU,&var680);
  setData(idA3AB05LDU,&var683);
  setData(idA3AB08LDU,&var674);
  setData(idA3AB07LDU,&var682);
  setData(idA3CV02RDU,&var1345);
  setData(idA3AD01LDU,&var1338);
  setData(idA3AD05LDU,&var1344);
  setData(idA3AD04LDU,&var1343);
  setData(idA3AD03LDU,&var1342);
  setData(idA3AD02LDU,&var1341);
  setData(idA3AD21LDU,&var1339);
  setData(idA3AD11LDU,&var1340);
  setData(idA3AZ03LDU,&var999);
  setData(idA3VS22LDU,&var1349);
  setData(idA3AB01LDU,&var1347);
  setData(idA3AB02LDU,&var1348);
  setData(idA3AB04LDU,&var1353);
  setData(idA3CV01RDU,&var1351);
  setData(idA3VS12LDU,&var1350);
  setData(idB1AB18LDU,&var742);
  setData(idB1AB17LDU,&var911);
  setData(idB1AB16LDU,&var910);
  setData(idB1AB14LDU,&var930);
  setData(idB1AB13LDU,&var931);
  setData(idB1AB12LDU,&var740);
  setData(idB1AB11LDU,&var744);
  setData(idB1AB10LDU,&var745);
  setData(idB1AB09LDU,&var748);
  setData(idB1AB06LDU,&var746);
  setData(idB1AB05LDU,&var753);
  setData(idB1AB08LDU,&var741);
  setData(idB1AB07LDU,&var752);
  setData(idB1CV02RDU,&var1374);
  setData(idB1AD01LDU,&var1367);
  setData(idB1AD05LDU,&var1373);
  setData(idB1AD04LDU,&var1372);
  setData(idB1AD03LDU,&var1371);
  setData(idB1AD02LDU,&var1370);
  setData(idB1AD21LDU,&var1369);
  setData(idB1AD11LDU,&var1368);
  setData(idB1AZ03LDU,&var755);
  setData(idB1VS22LDU,&var1379);
  setData(idB1AB01LDU,&var1376);
  setData(idB1AB02LDU,&var1377);
  setData(idB1AB04LDU,&var1382);
  setData(idB1CV01RDU,&var1380);
  setData(idB1VS12LDU,&var1378);
  setData(idA1AB18LDU,&var718);
  setData(idA1AB17LDU,&var717);
  setData(idA1AB16LDU,&var719);
  setData(idA1AB14LDU,&var933);
  setData(idA1AB13LDU,&var934);
  setData(idA1AB12LDU,&var715);
  setData(idA1AB11LDU,&var724);
  setData(idA1AB10LDU,&var722);
  setData(idA1AB09LDU,&var721);
  setData(idA1AB06LDU,&var726);
  setData(idA1AB05LDU,&var727);
  setData(idA1AB08LDU,&var720);
  setData(idA1AB07LDU,&var728);
  setData(idA1CV02RDU,&var1407);
  setData(idA1AD01LDU,&var1400);
  setData(idA1AD05LDU,&var1406);
  setData(idA1AD04LDU,&var1405);
  setData(idA1AD03LDU,&var1404);
  setData(idA1AD02LDU,&var1403);
  setData(idA1AD21LDU,&var1402);
  setData(idA1AD11LDU,&var1401);
  setData(idA1AZ03LDU,&var735);
  setData(idA1VS22LDU,&var1410);
  setData(idA1AB01LDU,&var733);
  setData(idA1AB02LDU,&var734);
  setData(idA1AB04LDU,&var1413);
  setData(idA1CV01RDU,&var1411);
  setData(idA1VS12LDU,&var1409);
  setData(idR1AD20LDU,&var1432);
  setData(idR1AD10LDU,&var1431);
  setData(idR2AB04LDU,&var1420);
  setData(idR1AB04LDU,&var1429);
  setData(idR2AB02LDU,&var1419);
  setData(idR2AB01LDU,&var1421);
  setData(idR2AZ03LDU,&var1418);
  setData(idR1AB02LDU,&var1428);
  setData(idR1AB01LDU,&var1430);
  setData(idR1AZ03LDU,&var1427);
  setData(idB2AB17LDU,&var691);
  setData(idB2AB16LDU,&var690);
  setData(idB2AB14LDU,&var935);
  setData(idB2AB13LDU,&var936);
  setData(idB2AB12LDU,&var692);
  setData(idB2AB11LDU,&var696);
  setData(idB2AB10LDU,&var695);
  setData(idB2AB09LDU,&var694);
  setData(idB2AB06LDU,&var699);
  setData(idB2AB05LDU,&var698);
  setData(idB2AB08LDU,&var693);
  setData(idB2AB07LDU,&var700);
  setData(idB2CV02RDU,&var1454);
  setData(idB2AD01LDU,&var1447);
  setData(idB2AD05LDU,&var1453);
  setData(idB2AD04LDU,&var1452);
  setData(idB2AD03LDU,&var1451);
  setData(idB2AD02LDU,&var1450);
  setData(idB2AD21LDU,&var1449);
  setData(idB2AD11LDU,&var1448);
  setData(idB2AZ03LDU,&var6);
  setData(idB2AB01LDU,&var7);
  setData(idB2AB02LDU,&var8);
  setData(idB2AB04LDU,&var5);
  setData(idB2CV01RDU,&var1458);
  setData(idA2CV02RDU,&var1495);
  setData(idA2AD01LDU,&var1488);
  setData(idA2AB17LDU,&var629);
  setData(idA2AB16LDU,&var630);
  setData(idA2AB14LDU,&var633);
  setData(idA2AB13LDU,&var634);
  setData(idA2AB12LDU,&var631);
  setData(idA2AB11LDU,&var639);
  setData(idA2AB10LDU,&var637);
  setData(idA2AB09LDU,&var635);
  setData(idA2AB06LDU,&var640);
  setData(idA2AB05LDU,&var636);
  setData(idA2AB08LDU,&var632);
  setData(idA2AB07LDU,&var638);
  setData(idA2AD05LDU,&var1494);
  setData(idA2AD04LDU,&var1493);
  setData(idA2AD03LDU,&var1492);
  setData(idA2AD02LDU,&var1491);
  setData(idA2AD21LDU,&var1490);
  setData(idA2AD11LDU,&var1489);
  setData(idA2AZ03LDU,&var4);
  setData(idA2VS21LDU,&var1500);
  setData(idA2AB01LDU,&var3);
  setData(idA2AB02LDU,&var2);
  setData(idA2AB04LDU,&var1);
  setData(idA2CV01RDU,&var1501);
  setData(idA2VS11LDU,&var1499);
  setData(idA8AB01LDU,&var1511);
  setData(idA8AB02LDU,&var517);
  setData(idA8AB14LDU,&var518);
  setData(idA8AB13LDU,&var519);
  setData(idA8AB12LDU,&var521);
  setData(idA8AB11LDU,&var522);
  setData(idA8AB10LDU,&var523);
  setData(idA8AB09LDU,&var524);
  setData(idA8AB08LDU,&var525);
  setData(idA8AB04LDU,&var1510);
  setData(idA8AD20LDU,&var1466);
  setData(idA8AD10LDU,&var1465);
  setData(idA8AZ03LDU,&var990);
  setData(idA8VS22LDU,&var1513);
  setData(idA8AB05LDU,&var1508);
  setData(idA8AB07LDU,&var1509);
  setData(idA8AB06LDU,&var1516);
  setData(idA8CV01RDU,&var1514);
  setData(idA8VS12LDU,&var1512);
  setData(idB8AB02LDU,&var835);
  setData(idB8AB14LDU,&var836);
  setData(idB8AB13LDU,&var837);
  setData(idB8AB12LDU,&var838);
  setData(idB8AB11LDU,&var842);
  setData(idB8AB10LDU,&var839);
  setData(idB8AB09LDU,&var840);
  setData(idB8AB08LDU,&var841);
  setData(idB8AB04LDU,&var1527);
  setData(idB8AB01LDU,&var1528);
  setData(idB8AD20LDU,&var1476);
  setData(idB8AD10LDU,&var1475);
  setData(idB8AZ03LDU,&var991);
  setData(idB8VS22LDU,&var1530);
  setData(idB8AB05LDU,&var1519);
  setData(idB8AB07LDU,&var1520);
  setData(idB8AB06LDU,&var1533);
  setData(idB8CV01RDU,&var1531);
  setData(idB8VS12LDU,&var1529);
  setData(idA6AB05LDU,&var958);
  setData(idB6AB09LDU,&var957);
  setData(idB6AB08LDU,&var956);
  setData(idB6AB07LDU,&var955);
  setData(idB6AB06LDU,&var954);
  setData(idA6AB09LDU,&var959);
  setData(idA6AB08LDU,&var945);
  setData(idA6AB07LDU,&var147);
  setData(idA6AB06LDU,&var960);
  setData(idB5AB04LDU,&var1583);
  setData(idA5AB04LDU,&var1592);
  setData(idB4AB02LDU,&var1564);
  setData(idB4AB01LDU,&var1565);
  setData(idB4AZ03LDU,&var1563);
  setData(idA4AB02LDU,&var1573);
  setData(idA4AB01LDU,&var1574);
  setData(idA4AZ03LDU,&var1572);
  setData(idA4AD10LDU,&var1575);
  setData(idB4AD10LDU,&var1566);
  setData(idB5AB02LDU,&var1582);
  setData(idB5AB01LDU,&var1584);
  setData(idB5AZ03LDU,&var1581);
  setData(idA5AB02LDU,&var1591);
  setData(idA5AB01LDU,&var1593);
  setData(idA5AZ03LDU,&var1590);
  setData(idA5AD20LDU,&var1595);
  setData(idA5AD10LDU,&var1594);
  setData(idB5AD20LDU,&var1586);
  setData(idB5AD10LDU,&var1585);
  setData(idR4AD20LDU,&var1604);
  setData(idR4AD10LDU,&var1603);
  setData(idR4AB18LDU,&var888);
  setData(idR4AB17LDU,&var887);
  setData(idR4AB16LDU,&var890);
  setData(idR4AB15LDU,&var889);
  setData(idR4AB14LDU,&var891);
  setData(idR4AB13LDU,&var859);
  setData(idR4AB12LDU,&var864);
  setData(idR4AB11LDU,&var896);
  setData(idR4AB10LDU,&var861);
  setData(idR4AB09LDU,&var894);
  setData(idR4AB08LDU,&var893);
  setData(idR4AB07LDU,&var897);
  setData(idR4AB06LDU,&var1601);
  setData(idR4AB05LDU,&var1600);
  setData(idR4AB04LDU,&var1602);
  setData(idR4AB03LDU,&var898);
  setData(idR4AZ03LDU,&var1599);
  setData(idR4AB02LDU,&var901);
  setData(idR4AB01LDU,&var902);
  setData(idB6AB04LDU,&var1610);
  setData(idA6AB04LDU,&var1619);
  setData(idB6AB02LDU,&var1609);
  setData(idB6AB01LDU,&var1611);
  setData(idB6AZ03LDU,&var1608);
  setData(idA6AB02LDU,&var1618);
  setData(idA6AB01LDU,&var1620);
  setData(idA6AZ03LDU,&var1617);
  setData(idB6AD20LDU,&var1613);
  setData(idB6AD10LDU,&var1612);
  setData(idA6AD20LDU,&var1622);
  setData(idA6AD10LDU,&var1621);
  setData(idR0ES01LDU,&var906);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
  for( i=0;i<10;i++ )
    array_m326_rz_1[i] = &(&internal1_m326_rz)[i*1];
  for( i=0;i<10;i++ )
    array_m268_rz_1[i] = &(&internal1_m268_rz)[i*1];
  for( i=0;i<6;i++ )
    array_m1399_rz_1[i] = &(&internal1_m1399_rz)[i*1];
  for( i=0;i<60;i++ )
    array_m1326_x0_1[i] = &(&internal1_m1326_x0)[i*5];
  for( i=0;i<60;i++ )
    array_m1326_tim0_1[i] = &(&internal1_m1326_tim0)[i*5];
  for( i=0;i<60;i++ )
    array_m925_x0_1[i] = &(&internal1_m925_x0)[i*5];
  for( i=0;i<60;i++ )
    array_m925_tim0_1[i] = &(&internal1_m925_tim0)[i*5];
  for( i=0;i<150;i++ )
    array_m517_x0_1[i] = &(&internal1_m517_x0)[i*5];
  for( i=0;i<150;i++ )
    array_m517_tim0_1[i] = &(&internal1_m517_tim0)[i*5];
  for( i=0;i<150;i++ )
    array_m197_x0_1[i] = &(&internal1_m197_x0)[i*5];
  for( i=0;i<150;i++ )
    array_m197_tim0_1[i] = &(&internal1_m197_tim0)[i*5];
  for( i=0;i<80;i++ )
    array_m831_x0_1[i] = &(&internal1_m831_x0)[i*5];
  for( i=0;i<80;i++ )
    array_m831_tim0_1[i] = &(&internal1_m831_tim0)[i*5];
  for( i=0;i<80;i++ )
    array_m1230_x0_1[i] = &(&internal1_m1230_x0)[i*5];
  for( i=0;i<80;i++ )
    array_m1230_tim0_1[i] = &(&internal1_m1230_tim0)[i*5];
  for( i=0;i<20;i++ )
    array_m1600_x0_1[i] = &(&internal1_m1600_x0)[i*5];
  for( i=0;i<20;i++ )
    array_m1600_tim0_1[i] = &(&internal1_m1600_tim0)[i*5];
  for( i=0;i<20;i++ )
    array_m1136_x0_1[i] = &(&internal1_m1136_x0)[i*5];
  for( i=0;i<20;i++ )
    array_m1136_tim0_1[i] = &(&internal1_m1136_tim0)[i*5];
}

void MainCycle(void)
{
if ((getAsShort(idR0MW11IP1) == 2) || (getAsShort(idR0MW11IP1) == 3)) { 
     if(delay++ < 200) return;
     freebuff = 0;
     delay = delay > 32000 ? 32000 : delay; 
       Scheme(); 
 }
 else {
      delay = 0;
      if (freebuff)
            return;
       else{
           freebuff = 1;
           memset(BUFFER, 0, SIZE_BUFFER);
           InitSetConst();
           ZeroVar();
           if (SimulOn) {
                 if (initAllSimul(CodeSub, drivers, SimulIP, SimulPort))
           return EXIT_FAILURE;
           } else {
                 if (initAllDrivers(drivers))
                 return EXIT_FAILURE;
           }
           }
       }


}
#endif
