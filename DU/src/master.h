#ifndef DU_H
#define DU_H
// Подсистема DU:DU
static char SimulOn=0;
static short CodeSub=2;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 10792
static char BUFFER[10792];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.50\0", 5432, "192.168.10.150\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define B3IS33LDU	 BUFFER[0]	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
#define idB3IS33LDU	 1	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
#define B3IS35LDU	 BUFFER[2]	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
#define idB3IS35LDU	 2	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
#define B4IS10LDU	 BUFFER[4]	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
#define idB4IS10LDU	 3	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
#define R6IS31LDU	 BUFFER[6]	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
#define idR6IS31LDU	 4	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
#define R6IS32LDU	 BUFFER[8]	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
#define idR6IS32LDU	 5	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
#define R6IS42LDU	 BUFFER[10]	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
#define idR6IS42LDU	 6	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
#define R6IS41LDU	 BUFFER[12]	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
#define idR6IS41LDU	 7	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
#define R6IS52LDU	 BUFFER[14]	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
#define idR6IS52LDU	 8	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
#define R6IS51LDU	 BUFFER[16]	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
#define idR6IS51LDU	 9	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
#define R3IS11LDU	 BUFFER[18]	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
#define idR3IS11LDU	 10	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
#define R3IS21LDU	 BUFFER[20]	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
#define idR3IS21LDU	 11	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
#define R0AB03LDU	 BUFFER[22]	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
#define idR0AB03LDU	 12	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
#define R0AB05LDU	 BUFFER[24]	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
#define idR0AB05LDU	 13	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
#define R0VN11RZ1	 BUFFER[26]	//( - , MDuBz1) Средняя мощность по BAZ1
#define idR0VN11RZ1	 14	//( - , MDuBz1) Средняя мощность по BAZ1
#define R0VN11RZ2	 BUFFER[31]	//( - , MDuBz2) Средняя мощность по BAZ2
#define idR0VN11RZ2	 15	//( - , MDuBz2) Средняя мощность по BAZ2
#define A2AB15LDU	 BUFFER[36]	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define idA2AB15LDU	 16	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define B2AB15LDU	 BUFFER[38]	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define idB2AB15LDU	 17	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define R0AD21LDU	 BUFFER[40]	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
#define idR0AD21LDU	 18	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
#define R0VX02LDU	 BUFFER[42]	//( - , DU) Импульс разрешен
#define idR0VX02LDU	 19	//( - , DU) Импульс разрешен
#define R0EE03LDU	 BUFFER[44]	//( - , DU) ВПИС ИС
#define idR0EE03LDU	 20	//( - , DU) ВПИС ИС
#define R0AB07LDU	 BUFFER[46]	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
#define idR0AB07LDU	 21	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
#define R0AD16LDU	 BUFFER[48]	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
#define idR0AD16LDU	 22	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
#define C2MD31LP1	 BUFFER[50]	//( - , DU) Кнопка СБРОС РБ
#define idC2MD31LP1	 23	//( - , DU) Кнопка СБРОС РБ
#define B7AZ03LDU	 BUFFER[52]	//( - , DU) Несанкционированное включение обдува АЗ2
#define idB7AZ03LDU	 24	//( - , DU) Несанкционированное включение обдува АЗ2
#define B3MD12LP1	 BUFFER[54]	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
#define idB3MD12LP1	 25	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
#define B3MD11LP1	 BUFFER[56]	//( - , DU) Кнопка ПУСК ИС2
#define idB3MD11LP1	 26	//( - , DU) Кнопка ПУСК ИС2
#define R0VL01RDU	 BUFFER[58]	//( - , DU) Индикация Время задержки
#define idR0VL01RDU	 27	//( - , DU) Индикация Время задержки
#define R0VZ71LZ2	 BUFFER[63]	//(vds32:03 - K22VDSR, DU) Обобщенный сигнал АЗ 2 канала
#define idR0VZ71LZ2	 28	//(vds32:03 - K22VDSR, DU) Обобщенный сигнал АЗ 2 канала
#define R0VZ71LZ1	 BUFFER[65]	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
#define idR0VZ71LZ1	 29	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
#define R0VZ71LDU	 BUFFER[67]	//( - , DU) Обобщенный сигнал АЗ
#define idR0VZ71LDU	 30	//( - , DU) Обобщенный сигнал АЗ
#define A2IS33LDU	 BUFFER[69]	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
#define idA2IS33LDU	 31	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
#define A3IS31LDU	 BUFFER[71]	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
#define idA3IS31LDU	 32	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
#define A3IS33LDU	 BUFFER[73]	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
#define idA3IS33LDU	 33	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
#define A3IS35LDU	 BUFFER[75]	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
#define idA3IS35LDU	 34	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
#define A4IS10LDU	 BUFFER[77]	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
#define idA4IS10LDU	 35	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
#define A1VN71LZ1	 BUFFER[79]	//(vds32:02 - K21VDSR, - ) Блокировка автоматического подъёма ББ
#define idA1VN71LZ1	 36	//(vds32:02 - K21VDSR, - ) Блокировка автоматического подъёма ББ
#define A1VN71LZ2	 BUFFER[81]	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define idA1VN71LZ2	 37	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define A1AB19LDU	 BUFFER[83]	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
#define idA1AB19LDU	 38	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
#define R0AD14LZ1	 BUFFER[85]	//(vds32:02 - K20VDSR, - ) Имитация срабатывания АЗ от II УР
#define idR0AD14LZ1	 39	//(vds32:02 - K20VDSR, - ) Имитация срабатывания АЗ от II УР
#define R0AD14LZ2	 BUFFER[87]	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
#define idR0AD14LZ2	 40	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
#define A3VZ13LZ2	 BUFFER[89]	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ2	 41	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define A3VZ13LZ1	 BUFFER[91]	//(vds32:02 - K18VDSR, - ) Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ1	 42	//(vds32:02 - K18VDSR, - ) Имитация срабатывания АЗ от ВУ ИС
#define A3VZ15LZ1	 BUFFER[93]	//(vds32:02 - K19VDSR, - ) Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ1	 43	//(vds32:02 - K19VDSR, - ) Имитация срабатывания АЗ от НУП ИС
#define A3VZ15LZ2	 BUFFER[95]	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ2	 44	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define B2IS33LDU	 BUFFER[97]	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
#define idB2IS33LDU	 45	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
#define B3IS31LDU	 BUFFER[99]	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
#define idB3IS31LDU	 46	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
#define B3MC01RP1	 BUFFER[101]	//( - , DU) Заданная координата положения ИС2 мм
#define idB3MC01RP1	 47	//( - , DU) Заданная координата положения ИС2 мм
#define B8MC01RP2	 BUFFER[106]	//( - , DU) Заданная координата АЗ2 мм
#define idB8MC01RP2	 48	//( - , DU) Заданная координата АЗ2 мм
#define R0AB09LDU	 BUFFER[111]	//( - , DU) Ошибка в заданной координате ББ1
#define idR0AB09LDU	 49	//( - , DU) Ошибка в заданной координате ББ1
#define R0AB10LDU	 BUFFER[113]	//( - , DU) Ошибка в заданной координате ББ2
#define idR0AB10LDU	 50	//( - , DU) Ошибка в заданной координате ББ2
#define R0AB11LDU	 BUFFER[115]	//( - , DU) Ошибка в заданной координате  ИС1
#define idR0AB11LDU	 51	//( - , DU) Ошибка в заданной координате  ИС1
#define R0AB12LDU	 BUFFER[117]	//( - , DU) Ошибка в заданной координате  ИС2
#define idR0AB12LDU	 52	//( - , DU) Ошибка в заданной координате  ИС2
#define R0AB13LDU	 BUFFER[119]	//( - , DU) Ошибка в заданной координате  АЗ2
#define idR0AB13LDU	 53	//( - , DU) Ошибка в заданной координате  АЗ2
#define A4ZAV	 BUFFER[121]	//( - , DU) 
#define idA4ZAV	 54	//( - , DU) 
#define A6ZAV	 BUFFER[123]	//( - , DU) 
#define idA6ZAV	 55	//( - , DU) 
#define R2ZAV	 BUFFER[125]	//( - , DU) 
#define idR2ZAV	 56	//( - , DU) 
#define A5ZAV	 BUFFER[127]	//( - , DU) 
#define idA5ZAV	 57	//( - , DU) 
#define B8ZAV	 BUFFER[129]	//( - , DU) 
#define idB8ZAV	 58	//( - , DU) 
#define A2ZAV	 BUFFER[131]	//( - , DU) Завершение РБ1,2
#define idA2ZAV	 59	//( - , DU) Завершение РБ1,2
#define A8ZAV	 BUFFER[133]	//( - , DU) 
#define idA8ZAV	 60	//( - , DU) 
#define A9ZAV	 BUFFER[135]	//( - , DU) Завершение НИ ДС1(2)
#define idA9ZAV	 61	//( - , DU) Завершение НИ ДС1(2)
#define R4ABL	 BUFFER[137]	//( - , DU) Блокировка тележки -
#define idR4ABL	 62	//( - , DU) Блокировка тележки -
#define A4UP	 BUFFER[139]	//( - , DU) 
#define idA4UP	 63	//( - , DU) 
#define A4DW	 BUFFER[141]	//( - , DU) 
#define idA4DW	 64	//( - , DU) 
#define R0AB14LDU	 BUFFER[143]	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
#define idR0AB14LDU	 65	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
#define R0AB15LDU	 BUFFER[145]	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
#define idR0AB15LDU	 66	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
#define A3IS12LDU	 BUFFER[147]	//( - , DU) Приход на ВУ штока ИС1
#define idA3IS12LDU	 67	//( - , DU) Приход на ВУ штока ИС1
#define B3IS12LDU	 BUFFER[149]	//( - , DU) Приход на ВУ штока ИС2
#define idB3IS12LDU	 68	//( - , DU) Приход на ВУ штока ИС2
#define A1ZAV	 BUFFER[151]	//( - , DU) 
#define idA1ZAV	 69	//( - , DU) 
#define B6VS01IDU	 BUFFER[153]	//( - , DU) Готовность к управлению БЗ2
#define idB6VS01IDU	 70	//( - , DU) Готовность к управлению БЗ2
#define R2AD20LDU	 BUFFER[156]	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
#define idR2AD20LDU	 71	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
#define R2AD10LDU	 BUFFER[158]	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
#define idR2AD10LDU	 72	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
#define B8VS01IDU	 BUFFER[160]	//( - , DU) Готовность к управлению АЗ2
#define idB8VS01IDU	 73	//( - , DU) Готовность к управлению АЗ2
#define A8VS01IDU	 BUFFER[163]	//( - , DU) Готовность к управлению ДС2
#define idA8VS01IDU	 74	//( - , DU) Готовность к управлению ДС2
#define A1IE03LDU	 BUFFER[166]	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
#define idA1IE03LDU	 75	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
#define A1IE04LDU	 BUFFER[168]	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
#define idA1IE04LDU	 76	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
#define A2IE03LDU	 BUFFER[170]	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
#define idA2IE03LDU	 77	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
#define A2IE04LDU	 BUFFER[172]	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
#define idA2IE04LDU	 78	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
#define A3IE03LDU	 BUFFER[174]	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
#define idA3IE03LDU	 79	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
#define A3IE04LDU	 BUFFER[176]	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
#define idA3IE04LDU	 80	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
#define B1IE03LDU	 BUFFER[178]	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
#define idB1IE03LDU	 81	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
#define B1IE04LDU	 BUFFER[180]	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
#define idB1IE04LDU	 82	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
#define B2IE03LDU	 BUFFER[182]	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
#define idB2IE03LDU	 83	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
#define B2IE04LDU	 BUFFER[184]	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
#define idB2IE04LDU	 84	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
#define B3IE03LDU	 BUFFER[186]	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
#define idB3IE03LDU	 85	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
#define B3IE04LDU	 BUFFER[188]	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
#define idB3IE04LDU	 86	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
#define R0VS11LDU	 BUFFER[190]	//( - , DU) РУ не готова к работе
#define idR0VS11LDU	 87	//( - , DU) РУ не готова к работе
#define B6AB05LDU	 BUFFER[192]	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
#define idB6AB05LDU	 88	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
#define R0AB08LDU	 BUFFER[194]	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
#define idR0AB08LDU	 89	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
#define A1MC01RP1	 BUFFER[196]	//( - , DU) Заданная координата положения ББ1 мм
#define idA1MC01RP1	 90	//( - , DU) Заданная координата положения ББ1 мм
#define B1MC01RP1	 BUFFER[201]	//( - , DU) Заданная координата положения ББ2  мм
#define idB1MC01RP1	 91	//( - , DU) Заданная координата положения ББ2  мм
#define A3MC01RP1	 BUFFER[206]	//( - , DU) Заданная координата положения ИС1 мм
#define idA3MC01RP1	 92	//( - , DU) Заданная координата положения ИС1 мм
#define R2VS01IDU	 BUFFER[211]	//( - , DU) Готовность к управлению МДЗ2
#define idR2VS01IDU	 93	//( - , DU) Готовность к управлению МДЗ2
#define R1VS01IDU	 BUFFER[214]	//( - , DU) Готовность к управлению МДЗ1
#define idR1VS01IDU	 94	//( - , DU) Готовность к управлению МДЗ1
#define A9IS11LDU	 BUFFER[217]	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
#define idA9IS11LDU	 95	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
#define A9IS21LDU	 BUFFER[219]	//(vds32:02 - K24VDSR, - ) Приход на НУ НИ ДС1
#define idA9IS21LDU	 96	//(vds32:02 - K24VDSR, - ) Приход на НУ НИ ДС1
#define B9IS11LDU	 BUFFER[221]	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
#define idB9IS11LDU	 97	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
#define B9IS21LDU	 BUFFER[223]	//(vds32:02 - K26VDSR, - ) Приход на НУ НИ ДС2
#define idB9IS21LDU	 98	//(vds32:02 - K26VDSR, - ) Приход на НУ НИ ДС2
#define B9AD10LDU	 BUFFER[225]	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
#define idB9AD10LDU	 99	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
#define A9AD10LDU	 BUFFER[227]	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
#define idA9AD10LDU	 100	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
#define A9AZ03LDU	 BUFFER[229]	//( - , DU) Несанкционированное перемещение НИ ДС1
#define idA9AZ03LDU	 101	//( - , DU) Несанкционированное перемещение НИ ДС1
#define A9AB01LDU	 BUFFER[231]	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
#define idA9AB01LDU	 102	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
#define A9AB02LDU	 BUFFER[233]	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
#define idA9AB02LDU	 103	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
#define B9AZ03LDU	 BUFFER[235]	//( - , DU) Несанкционированное перемещение НИ ДС2
#define idB9AZ03LDU	 104	//( - , DU) Несанкционированное перемещение НИ ДС2
#define B9AB01LDU	 BUFFER[237]	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
#define idB9AB01LDU	 105	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
#define B9AB02LDU	 BUFFER[239]	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
#define idB9AB02LDU	 106	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
#define R0AB01LDU	 BUFFER[241]	//( - , DU) Режим проверки разрешён
#define idR0AB01LDU	 107	//( - , DU) Режим проверки разрешён
#define A3IS22LDU	 BUFFER[243]	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
#define idA3IS22LDU	 108	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
#define B3IS22LDU	 BUFFER[245]	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
#define idB3IS22LDU	 109	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
#define A2AD33LDU	 BUFFER[247]	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
#define idA2AD33LDU	 110	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
#define B2AD33LDU	 BUFFER[249]	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
#define idB2AD33LDU	 111	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
#define A3AD33LDU	 BUFFER[251]	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
#define idA3AD33LDU	 112	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
#define A3AD34LDU	 BUFFER[253]	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
#define idA3AD34LDU	 113	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
#define A3AD31LDU	 BUFFER[255]	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
#define idA3AD31LDU	 114	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
#define B3AD34LDU	 BUFFER[257]	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
#define idB3AD34LDU	 115	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
#define R0AB04LDU	 BUFFER[259]	//( - , DU) Нарушение времени срабатывания верхней АС II УР
#define idR0AB04LDU	 116	//( - , DU) Нарушение времени срабатывания верхней АС II УР
#define R0AB06LDU	 BUFFER[261]	//( - , DU) Нарушение времени задержки от ВУ РБ
#define idR0AB06LDU	 117	//( - , DU) Нарушение времени задержки от ВУ РБ
#define R0AB02LDU	 BUFFER[263]	//( - , DU) Нарушение времени задержки ИНИ
#define idR0AB02LDU	 118	//( - , DU) Нарушение времени задержки ИНИ
#define R0VL03RDU	 BUFFER[265]	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define idR0VL03RDU	 119	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define R0VL05RDU	 BUFFER[270]	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
#define idR0VL05RDU	 120	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
#define R0VL21IDU	 BUFFER[275]	//( - , DU) Декатрон
#define idR0VL21IDU	 121	//( - , DU) Декатрон
#define R0VX03LDU	 BUFFER[278]	//( - , DU) Готовность 2 мин
#define idR0VX03LDU	 122	//( - , DU) Готовность 2 мин
#define R0VS21IDU	 BUFFER[280]	//( - , DU) Индикация ВИД ПРОВЕРКИ
#define idR0VS21IDU	 123	//( - , DU) Индикация ВИД ПРОВЕРКИ
#define A1VS01IDU	 BUFFER[283]	//( - , DU) Готовность к управлению ББ1
#define idA1VS01IDU	 124	//( - , DU) Готовность к управлению ББ1
#define B1VS01IDU	 BUFFER[286]	//( - , DU) Готовность к управлению ББ2
#define idB1VS01IDU	 125	//( - , DU) Готовность к управлению ББ2
#define A3VS01IDU	 BUFFER[289]	//( - , DU) Готовность к управлению ИС1
#define idA3VS01IDU	 126	//( - , DU) Готовность к управлению ИС1
#define B3VS01IDU	 BUFFER[292]	//( - , DU) Готовность к управлению ИС2
#define idB3VS01IDU	 127	//( - , DU) Готовность к управлению ИС2
#define A2VS01IDU	 BUFFER[295]	//( - , DU) Готовность к управлению РБ1
#define idA2VS01IDU	 128	//( - , DU) Готовность к управлению РБ1
#define A4VS01IDU	 BUFFER[298]	//( - , DU) Готовность к управлению НИ1
#define idA4VS01IDU	 129	//( - , DU) Готовность к управлению НИ1
#define A4VS12LDU	 BUFFER[301]	//( - , DU) Движение НИ1 в сторону ВУ
#define idA4VS12LDU	 130	//( - , DU) Движение НИ1 в сторону ВУ
#define A4VS22LDU	 BUFFER[303]	//( - , DU) Движение НИ1 в сторону НУ
#define idA4VS22LDU	 131	//( - , DU) Движение НИ1 в сторону НУ
#define B4VS01IDU	 BUFFER[305]	//( - , DU) Готовность к управлению НИ2
#define idB4VS01IDU	 132	//( - , DU) Готовность к управлению НИ2
#define B4VS12LDU	 BUFFER[308]	//( - , DU) Движение НИ2 в сторону ВУ
#define idB4VS12LDU	 133	//( - , DU) Движение НИ2 в сторону ВУ
#define B4VS22LDU	 BUFFER[310]	//( - , DU) Движение НИ2 в сторону НУ
#define idB4VS22LDU	 134	//( - , DU) Движение НИ2 в сторону НУ
#define A5VS01IDU	 BUFFER[312]	//( - , DU) Готовность к управлению НЛ1
#define idA5VS01IDU	 135	//( - , DU) Готовность к управлению НЛ1
#define B5VS01IDU	 BUFFER[315]	//( - , DU) Готовность к управлению НЛ2
#define idB5VS01IDU	 136	//( - , DU) Готовность к управлению НЛ2
#define A6VS01IDU	 BUFFER[318]	//( - , DU) Готовность к управлению БЗ1
#define idA6VS01IDU	 137	//( - , DU) Готовность к управлению БЗ1
#define R4VS01IDU	 BUFFER[321]	//( - , DU) Готовность к управлению тележкой реактора
#define idR4VS01IDU	 138	//( - , DU) Готовность к управлению тележкой реактора
#define R0VS18LDU	 BUFFER[324]	//( - , DU) Индикация  Проверка схем сброса
#define idR0VS18LDU	 139	//( - , DU) Индикация  Проверка схем сброса
#define B1MD11LP1	 BUFFER[326]	//( - , DU) Кнопка ПУСК ББ2
#define idB1MD11LP1	 140	//( - , DU) Кнопка ПУСК ББ2
#define B1MD12LP1	 BUFFER[328]	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
#define idB1MD12LP1	 141	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
#define B2MD11LP1	 BUFFER[330]	//( - , DU) Кнопка ПУСК РБ2
#define idB2MD11LP1	 142	//( - , DU) Кнопка ПУСК РБ2
#define B2MD12LP1	 BUFFER[332]	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
#define idB2MD12LP1	 143	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
#define A2MD11LP1	 BUFFER[334]	//( - , DU) Кнопка ПУСК РБ1
#define idA2MD11LP1	 144	//( - , DU) Кнопка ПУСК РБ1
#define A2MD12LP1	 BUFFER[336]	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
#define idA2MD12LP1	 145	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
#define R0IS01LDU	 BUFFER[338]	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
#define idR0IS01LDU	 146	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
#define R0IS02LDU	 BUFFER[340]	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
#define idR0IS02LDU	 147	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
#define R0VP73LZ1	 BUFFER[342]	//( - , MDuBz1) ПС давления для РУ
#define idR0VP73LZ1	 148	//( - , MDuBz1) ПС давления для РУ
#define R0VP73LZ2	 BUFFER[344]	//( - , MDuBz2) ПС давления для РУ
#define idR0VP73LZ2	 149	//( - , MDuBz2) ПС давления для РУ
#define R0VP73LDU	 BUFFER[346]	//( - , DU) ПС давления для РУ
#define idR0VP73LDU	 150	//( - , DU) ПС давления для РУ
#define R0MD34LP1	 BUFFER[348]	//( - , DU) Кнопка КВИТИРОВАТЬ
#define idR0MD34LP1	 151	//( - , DU) Кнопка КВИТИРОВАТЬ
#define A0VT71LZ1	 BUFFER[350]	//( - , MDuBz1) АС по температуре в АЗ1
#define idA0VT71LZ1	 152	//( - , MDuBz1) АС по температуре в АЗ1
#define B0VT71LZ1	 BUFFER[352]	//( - , MDuBz1) АС по температуре в АЗ2
#define idB0VT71LZ1	 153	//( - , MDuBz1) АС по температуре в АЗ2
#define A0VT71LZ2	 BUFFER[354]	//( - , MDuBz2) АС по температуре в АЗ1
#define idA0VT71LZ2	 154	//( - , MDuBz2) АС по температуре в АЗ1
#define B0VT71LZ2	 BUFFER[356]	//( - , MDuBz2) АС по температуре в АЗ2
#define idB0VT71LZ2	 155	//( - , MDuBz2) АС по температуре в АЗ2
#define B2VS11LDU	 BUFFER[358]	//( - , DU) Движение РБ2 в сторону ВУ
#define idB2VS11LDU	 156	//( - , DU) Движение РБ2 в сторону ВУ
#define B2VS21LDU	 BUFFER[360]	//( - , DU) Движение РБ2 в сторону НУ
#define idB2VS21LDU	 157	//( - , DU) Движение РБ2 в сторону НУ
#define B2VS01IDU	 BUFFER[362]	//( - , DU) Готовность к управлению РБ2
#define idB2VS01IDU	 158	//( - , DU) Готовность к управлению РБ2
#define A7AS31LDU	 BUFFER[365]	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
#define idA7AS31LDU	 159	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
#define B7AS31LDU	 BUFFER[367]	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
#define idB7AS31LDU	 160	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
#define A7AZ03LDU	 BUFFER[369]	//( - , DU) Несанкционированное включение обдува АЗ1
#define idA7AZ03LDU	 161	//( - , DU) Несанкционированное включение обдува АЗ1
#define B3AD31LDU	 BUFFER[371]	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
#define idB3AD31LDU	 162	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
#define A2IS11LDU	 BUFFER[373]	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
#define idA2IS11LDU	 163	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
#define B2IS11LDU	 BUFFER[375]	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
#define idB2IS11LDU	 164	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
#define A3MD12LP1	 BUFFER[377]	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
#define idA3MD12LP1	 165	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
#define A3MD11LP1	 BUFFER[379]	//( - , DU) Кнопка ПУСК ИС1
#define idA3MD11LP1	 166	//( - , DU) Кнопка ПУСК ИС1
#define R0MD33LP1	 BUFFER[381]	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
#define idR0MD33LP1	 167	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
#define A1MD12LP1	 BUFFER[383]	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
#define idA1MD12LP1	 168	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
#define A1MD11LP1	 BUFFER[385]	//( - , DU) Кнопка ПУСК ББ1
#define idA1MD11LP1	 169	//( - , DU) Кнопка ПУСК ББ1
#define R0MW14IP2	 BUFFER[387]	//( - , DU) Переключатель ОБДУВ
#define idR0MW14IP2	 170	//( - , DU) Переключатель ОБДУВ
#define A7AP31LDU	 BUFFER[390]	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
#define idA7AP31LDU	 171	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
#define B7AP31LDU	 BUFFER[392]	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
#define idB7AP31LDU	 172	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
#define R0MW12IP2	 BUFFER[394]	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define idR0MW12IP2	 173	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define R0MW17LP1	 BUFFER[397]	//( - , DU) Переключатель АВТ/Р
#define idR0MW17LP1	 174	//( - , DU) Переключатель АВТ/Р
#define R0VW13LDU	 BUFFER[399]	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
#define idR0VW13LDU	 175	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
#define R0VW23LDU	 BUFFER[401]	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
#define idR0VW23LDU	 176	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
#define R0VX08IDU	 BUFFER[403]	//( - , DU) Индикация Режим
#define idR0VX08IDU	 177	//( - , DU) Индикация Режим
#define R0VX09LDU	 BUFFER[406]	//( - , DU) Индикация регулятор мощности включен/отключен
#define idR0VX09LDU	 178	//( - , DU) Индикация регулятор мощности включен/отключен
#define R0VS17LDU	 BUFFER[408]	//( - , DU) Индикация выбора АВТОМАТ
#define idR0VS17LDU	 179	//( - , DU) Индикация выбора АВТОМАТ
#define A2VS32LDU	 BUFFER[410]	//( - , DU) Индикация  СБРОС РБ1
#define idA2VS32LDU	 180	//( - , DU) Индикация  СБРОС РБ1
#define B2VS32LDU	 BUFFER[412]	//( - , DU) Индикация  СБРОС РБ2
#define idB2VS32LDU	 181	//( - , DU) Индикация  СБРОС РБ2
#define A3VX01LDU	 BUFFER[414]	//( - , DU) Индикация Выстрел ИС1
#define idA3VX01LDU	 182	//( - , DU) Индикация Выстрел ИС1
#define A3IS11LDU	 BUFFER[416]	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
#define idA3IS11LDU	 183	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
#define B3VX01LDU	 BUFFER[418]	//( - , DU) Индикация Выстрел ИС2
#define idB3VX01LDU	 184	//( - , DU) Индикация Выстрел ИС2
#define A3VP52LDU	 BUFFER[420]	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define idA3VP52LDU	 185	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define B3VP42LDU	 BUFFER[422]	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
#define idB3VP42LDU	 186	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
#define B3CP02RDU	 BUFFER[424]	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
#define idB3CP02RDU	 187	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
#define B3VP52LDU	 BUFFER[429]	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define idB3VP52LDU	 188	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define B3VP82LDU	 BUFFER[431]	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
#define idB3VP82LDU	 189	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
#define A3VP82LDU	 BUFFER[433]	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
#define idA3VP82LDU	 190	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
#define A3IP02IDU	 BUFFER[435]	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	 191	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
#define B3IP02IDU	 BUFFER[438]	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
#define idB3IP02IDU	 192	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
#define A0VE01LDU	 BUFFER[441]	//( - , DU) Напряжение в системы АЗ1 подано
#define idA0VE01LDU	 193	//( - , DU) Напряжение в системы АЗ1 подано
#define B0VE01LDU	 BUFFER[443]	//( - , DU) Напряжение в системы АЗ2 подано
#define idB0VE01LDU	 194	//( - , DU) Напряжение в системы АЗ2 подано
#define A0VP01LDU	 BUFFER[445]	//( - , DU) Давление в системы АЗ1 подано
#define idA0VP01LDU	 195	//( - , DU) Давление в системы АЗ1 подано
#define B0VP01LDU	 BUFFER[447]	//( - , DU) Давление в системы АЗ2 подано
#define idB0VP01LDU	 196	//( - , DU) Давление в системы АЗ2 подано
#define A0EE01LZ1	 BUFFER[449]	//( - , MDuBz1) Исправность АКНП1
#define idA0EE01LZ1	 197	//( - , MDuBz1) Исправность АКНП1
#define A0EE03LZ1	 BUFFER[451]	//( - , MDuBz1) Исправность АКНП3
#define idA0EE03LZ1	 198	//( - , MDuBz1) Исправность АКНП3
#define A0EE02LZ1	 BUFFER[453]	//( - , MDuBz1) Исправность АКНП2
#define idA0EE02LZ1	 199	//( - , MDuBz1) Исправность АКНП2
#define A0EE04LZ1	 BUFFER[455]	//( - , MDuBz1) Исправность АКНП4
#define idA0EE04LZ1	 200	//( - , MDuBz1) Исправность АКНП4
#define A0VN01LDU	 BUFFER[457]	//( - , DU) Каналы АЗ1 проверены
#define idA0VN01LDU	 201	//( - , DU) Каналы АЗ1 проверены
#define B0VN01LDU	 BUFFER[459]	//( - , DU) Каналы АЗ2 проверены
#define idB0VN01LDU	 202	//( - , DU) Каналы АЗ2 проверены
#define A0EE01LZ2	 BUFFER[461]	//( - , MDuBz2) Исправность АКНП1
#define idA0EE01LZ2	 203	//( - , MDuBz2) Исправность АКНП1
#define A0EE03LZ2	 BUFFER[463]	//( - , MDuBz2) Исправность АКНП3
#define idA0EE03LZ2	 204	//( - , MDuBz2) Исправность АКНП3
#define A0EE02LZ2	 BUFFER[465]	//( - , MDuBz2) Исправность АКНП2
#define idA0EE02LZ2	 205	//( - , MDuBz2) Исправность АКНП2
#define A0EE04LZ2	 BUFFER[467]	//( - , MDuBz2) Исправность АКНП4
#define idA0EE04LZ2	 206	//( - , MDuBz2) Исправность АКНП4
#define A0VP71LZ1	 BUFFER[469]	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ1	 207	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
#define A8VC01RDU	 BUFFER[471]	//( - , DU) Координата ДС2, мм
#define idA8VC01RDU	 208	//( - , DU) Координата ДС2, мм
#define B8IC01UDU	 BUFFER[476]	//( - , MDuS) Координата АЗ2 (дел.энк)
#define idB8IC01UDU	 209	//( - , MDuS) Координата АЗ2 (дел.энк)
#define A1IC01UDU	 BUFFER[481]	//( - , MDuS) Координата штока ББ1 (дел.энк)
#define idA1IC01UDU	 210	//( - , MDuS) Координата штока ББ1 (дел.энк)
#define A1VC01RDU	 BUFFER[486]	//( - , DU) Координата ББ1, мм
#define idA1VC01RDU	 211	//( - , DU) Координата ББ1, мм
#define A1IS11LDU	 BUFFER[491]	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
#define idA1IS11LDU	 212	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
#define B1MC01LC1	 BUFFER[493]	//( - , DU) Настроить энкодер ББ2
#define idB1MC01LC1	 213	//( - , DU) Настроить энкодер ББ2
#define B1MC01LC2	 BUFFER[495]	//( - , DU) Настроить энкодер ББ2
#define idB1MC01LC2	 214	//( - , DU) Настроить энкодер ББ2
#define A1MC01LC1	 BUFFER[497]	//( - , DU) Настроить энкодер ББ1
#define idA1MC01LC1	 215	//( - , DU) Настроить энкодер ББ1
#define A1MC01LC2	 BUFFER[499]	//( - , DU) Настроить энкодер ББ1
#define idA1MC01LC2	 216	//( - , DU) Настроить энкодер ББ1
#define B2MC01LC1	 BUFFER[501]	//( - , DU) Настроить энкодер РБ2
#define idB2MC01LC1	 217	//( - , DU) Настроить энкодер РБ2
#define B2MC01LC2	 BUFFER[503]	//( - , DU) Настроить энкодер РБ2
#define idB2MC01LC2	 218	//( - , DU) Настроить энкодер РБ2
#define A2MC01LC1	 BUFFER[505]	//( - , DU) Настроить энкодер РБ1
#define idA2MC01LC1	 219	//( - , DU) Настроить энкодер РБ1
#define A2MC01LC2	 BUFFER[507]	//( - , DU) Настроить энкодер РБ1
#define idA2MC01LC2	 220	//( - , DU) Настроить энкодер РБ1
#define B3MC01LC1	 BUFFER[509]	//( - , DU) Настроить энкодер ИС2
#define idB3MC01LC1	 221	//( - , DU) Настроить энкодер ИС2
#define B3MC01LC2	 BUFFER[511]	//( - , DU) Настроить энкодер ИС2
#define idB3MC01LC2	 222	//( - , DU) Настроить энкодер ИС2
#define A3MC01LC1	 BUFFER[513]	//( - , DU) Настроить энкодер ИС1
#define idA3MC01LC1	 223	//( - , DU) Настроить энкодер ИС1
#define A3MC01LC2	 BUFFER[515]	//( - , DU) Настроить энкодер ИС1
#define idA3MC01LC2	 224	//( - , DU) Настроить энкодер ИС1
#define B8MC01LC1	 BUFFER[517]	//( - , DU) Настроить энкодер АЗ2
#define idB8MC01LC1	 225	//( - , DU) Настроить энкодер АЗ2
#define B8MC01LC2	 BUFFER[519]	//( - , DU) Настроить энкодер АЗ2
#define idB8MC01LC2	 226	//( - , DU) Настроить энкодер АЗ2
#define A8MC01LC1	 BUFFER[521]	//( - , DU) Настроить энкодер ДС2
#define idA8MC01LC1	 227	//( - , DU) Настроить энкодер ДС2
#define A8MC01LC2	 BUFFER[523]	//( - , DU) Настроить энкодер ДС2
#define idA8MC01LC2	 228	//( - , DU) Настроить энкодер ДС2
#define A3VP42LDU	 BUFFER[525]	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
#define idA3VP42LDU	 229	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
#define A3CP02RDU	 BUFFER[527]	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
#define idA3CP02RDU	 230	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
#define A5IE02LDU	 BUFFER[532]	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
#define idA5IE02LDU	 231	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
#define R1IE01LDU	 BUFFER[534]	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
#define idR1IE01LDU	 232	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
#define R2IE01LDU	 BUFFER[536]	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
#define idR2IE01LDU	 233	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
#define R6IS61LDU	 BUFFER[538]	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
#define idR6IS61LDU	 234	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
#define R6IS64LDU	 BUFFER[540]	//( - , MDuS) Исправность ВИП ССДИ-35 1канал
#define idR6IS64LDU	 235	//( - , MDuS) Исправность ВИП ССДИ-35 1канал
#define R6IS65LDU	 BUFFER[542]	//( - , MDuS) Исправность ВИП ССДИ-35 2канал
#define idR6IS65LDU	 236	//( - , MDuS) Исправность ВИП ССДИ-35 2канал
#define R6IS62LDU	 BUFFER[544]	//( - , MDuS) Исправность ВИП ССДИ-39 1канал
#define idR6IS62LDU	 237	//( - , MDuS) Исправность ВИП ССДИ-39 1канал
#define R6IS63LDU	 BUFFER[546]	//( - , MDuS) Исправность ВИП ССДИ-39 2канал
#define idR6IS63LDU	 238	//( - , MDuS) Исправность ВИП ССДИ-39 2канал
#define R6IS66LZZ	 BUFFER[548]	//( - , MDuS) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 239	//( - , MDuS) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	 BUFFER[550]	//( - , MDuS) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 240	//( - , MDuS) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	 BUFFER[552]	//( - , MDuS) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 241	//( - , MDuS) Исправность ВИП 4,0 (№7) ССДИ-2
#define syn_R0EE03LDU	 BUFFER[554]	//( - , DU) ВПИС ИС
#define idsyn_R0EE03LDU	 242	//( - , DU) ВПИС ИС
#define A3VC01RDU	 BUFFER[556]	//( - , DU) Координата ИС1, мм
#define idA3VC01RDU	 243	//( - , DU) Координата ИС1, мм
#define A2VC01RDU	 BUFFER[561]	//( - , DU) Координата РБ1, мм
#define idA2VC01RDU	 244	//( - , DU) Координата РБ1, мм
#define B2VC01RDU	 BUFFER[566]	//( - , DU) Координата РБ2, мм
#define idB2VC01RDU	 245	//( - , DU) Координата РБ2, мм
#define B8VC01RDU	 BUFFER[571]	//( - , DU) Координата АЗ2, мм
#define idB8VC01RDU	 246	//( - , DU) Координата АЗ2, мм
#define A4VP82LDU	 BUFFER[576]	//( - , MDuS) Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	 247	//( - , MDuS) Давление ПОДЪЁМ НИ1 в норме
#define B4VP82LDU	 BUFFER[578]	//( - , MDuS) Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	 248	//( - , MDuS) Давление ПОДЪЁМ НИ2 в норме
#define A2VP82LDU	 BUFFER[580]	//( - , MDuS) Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	 249	//( - , MDuS) Давление ПОДЪЁМ РБ1 в норме
#define B2VP82LDU	 BUFFER[582]	//( - , MDuS) Давление ПОДЪЁМ РБ2 в норме
#define idB2VP82LDU	 250	//( - , MDuS) Давление ПОДЪЁМ РБ2 в норме
#define A3VP81LDU	 BUFFER[584]	//( - , MDuS) Давление СПУСК ИС1 в норме
#define idA3VP81LDU	 251	//( - , MDuS) Давление СПУСК ИС1 в норме
#define B3VP81LDU	 BUFFER[586]	//( - , MDuS) Давление СПУСК ИС2 в норме
#define idB3VP81LDU	 252	//( - , MDuS) Давление СПУСК ИС2 в норме
#define R0EE02LDU	 BUFFER[588]	//( - , DU) Питание  АКНП  отключить
#define idR0EE02LDU	 253	//( - , DU) Питание  АКНП  отключить
#define A0VP71LZ2	 BUFFER[590]	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ2	 254	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
#define B0VP71LZ1	 BUFFER[592]	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ1	 255	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
#define B0VP71LZ2	 BUFFER[594]	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ2	 256	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
#define A0VS11LDU	 BUFFER[596]	//( - , DU) АЗ1 готова к работе
#define idA0VS11LDU	 257	//( - , DU) АЗ1 готова к работе
#define B0VS11LDU	 BUFFER[598]	//( - , DU) АЗ2 готова к работе
#define idB0VS11LDU	 258	//( - , DU) АЗ2 готова к работе
#define A1IE01LDU	 BUFFER[600]	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
#define idA1IE01LDU	 259	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
#define A3IE01LDU	 BUFFER[602]	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
#define idA3IE01LDU	 260	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
#define A2IE01LDU	 BUFFER[604]	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
#define idA2IE01LDU	 261	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
#define A1IE02LDU	 BUFFER[606]	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
#define idA1IE02LDU	 262	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
#define A3IE02LDU	 BUFFER[608]	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
#define idA3IE02LDU	 263	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
#define A2IE02LDU	 BUFFER[610]	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
#define idA2IE02LDU	 264	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
#define B1IE01LDU	 BUFFER[612]	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
#define idB1IE01LDU	 265	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
#define B2IE01LDU	 BUFFER[614]	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
#define idB2IE01LDU	 266	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
#define B3IE01LDU	 BUFFER[616]	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
#define idB3IE01LDU	 267	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
#define B1IE02LDU	 BUFFER[618]	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
#define idB1IE02LDU	 268	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
#define B3IE02LDU	 BUFFER[620]	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
#define idB3IE02LDU	 269	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
#define B2IE02LDU	 BUFFER[622]	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
#define idB2IE02LDU	 270	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
#define R0IE02LDU	 BUFFER[624]	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
#define idR0IE02LDU	 271	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
#define R0IE01LDU	 BUFFER[626]	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
#define idR0IE01LDU	 272	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
#define A6IE01LDU	 BUFFER[628]	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
#define idA6IE01LDU	 273	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
#define B6IE01LDU	 BUFFER[630]	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
#define idB6IE01LDU	 274	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
#define A8IE01LDU	 BUFFER[632]	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
#define idA8IE01LDU	 275	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
#define B5IE01LDU	 BUFFER[634]	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
#define idB5IE01LDU	 276	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
#define R0CN95LDU	 BUFFER[636]	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
#define idR0CN95LDU	 277	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
#define R0AD03LZ1	 BUFFER[639]	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
#define idR0AD03LZ1	 278	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
#define R0AD03LZ2	 BUFFER[641]	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
#define idR0AD03LZ2	 279	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
#define R0AD04LZ1	 BUFFER[643]	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define idR0AD04LZ1	 280	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define R0AD04LZ2	 BUFFER[645]	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define idR0AD04LZ2	 281	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define R0AD05LZ1	 BUFFER[647]	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
#define idR0AD05LZ1	 282	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
#define R0AD05LZ2	 BUFFER[649]	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
#define idR0AD05LZ2	 283	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
#define B8IS12LDU	 BUFFER[651]	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
#define idB8IS12LDU	 284	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
#define B8IS21LDU	 BUFFER[653]	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
#define idB8IS21LDU	 285	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
#define A1VP41LZ1	 BUFFER[655]	//( - , DU) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ1	 286	//( - , DU) Давление СБРОС ББ1 ниже АС
#define A1VP41LZ2	 BUFFER[657]	//( - , DU) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ2	 287	//( - , DU) Давление СБРОС ББ1 ниже АС
#define R0VL22LDU	 BUFFER[659]	//( - , DU) Конец программы 200сек
#define idR0VL22LDU	 288	//( - , DU) Конец программы 200сек
#define R0VL23LDU	 BUFFER[661]	//( - , DU) Конец программы 20мин
#define idR0VL23LDU	 289	//( - , DU) Конец программы 20мин
#define B1VP41LZ1	 BUFFER[663]	//( - , DU) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ1	 290	//( - , DU) Давление СБРОС ББ2 ниже АС
#define B1VP41LZ2	 BUFFER[665]	//( - , DU) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ2	 291	//( - , DU) Давление СБРОС ББ2 ниже АС
#define A3AB19LDU	 BUFFER[667]	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
#define idA3AB19LDU	 292	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
#define B3AB19LDU	 BUFFER[669]	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
#define idB3AB19LDU	 293	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
#define A3EE03LDU	 BUFFER[671]	//( - , DU) ВПИС ИС1
#define idA3EE03LDU	 294	//( - , DU) ВПИС ИС1
#define B3EE03LDU	 BUFFER[673]	//( - , DU) ВПИС ИС2
#define idB3EE03LDU	 295	//( - , DU) ВПИС ИС2
#define B3AB15LDU	 BUFFER[675]	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
#define idB3AB15LDU	 296	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
#define R5IS21LDU	 BUFFER[677]	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	 297	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
#define R5VS22LDU	 BUFFER[679]	//( - , DU) Движение ворот отстойной зоны к закрыты
#define idR5VS22LDU	 298	//( - , DU) Движение ворот отстойной зоны к закрыты
#define R5VS12LDU	 BUFFER[681]	//( - , DU) Движение ворот отстойной зоны к открыты
#define idR5VS12LDU	 299	//( - , DU) Движение ворот отстойной зоны к открыты
#define A3ZAV	 BUFFER[683]	//( - , DU) 
#define idA3ZAV	 300	//( - , DU) 
#define B1AB19LDU	 BUFFER[685]	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
#define idB1AB19LDU	 301	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
#define R0VN09RZ2	 BUFFER[687]	//( - , MDuBz2) Усредненный период разгона
#define idR0VN09RZ2	 302	//( - , MDuBz2) Усредненный период разгона
#define R0VN09RZ1	 BUFFER[692]	//( - , MDuBz1) Усредненный период разгона
#define idR0VN09RZ1	 303	//( - , MDuBz1) Усредненный период разгона
#define R0AB16LDU	 BUFFER[697]	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
#define idR0AB16LDU	 304	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
#define R0AB17LDU	 BUFFER[699]	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
#define idR0AB17LDU	 305	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
#define R0AB18LDU	 BUFFER[701]	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
#define idR0AB18LDU	 306	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
#define A0CT01IZ1	 BUFFER[703]	//( - , MDuBz1) Температура АЗ1-1
#define idA0CT01IZ1	 307	//( - , MDuBz1) Температура АЗ1-1
#define B0CT01IZ1	 BUFFER[708]	//( - , MDuBz1) Температура АЗ2-1
#define idB0CT01IZ1	 308	//( - , MDuBz1) Температура АЗ2-1
#define A0CT01IZ2	 BUFFER[713]	//( - , MDuBz2) Температура АЗ1-2
#define idA0CT01IZ2	 309	//( - , MDuBz2) Температура АЗ1-2
#define B0CT01IZ2	 BUFFER[718]	//( - , MDuBz2) Температура АЗ2-2
#define idB0CT01IZ2	 310	//( - , MDuBz2) Температура АЗ2-2
#define A3MC01RDU	 BUFFER[723]	//( - , DU) Заданная координата положения ИС от регулятора мм
#define idA3MC01RDU	 311	//( - , DU) Заданная координата положения ИС от регулятора мм
#define A3MC02RDU	 BUFFER[728]	//( - , DU) Температурная корректировка координаты ИМ
#define idA3MC02RDU	 312	//( - , DU) Температурная корректировка координаты ИМ
#define R0CN91LDU	 BUFFER[733]	//( - , DU) Рассчётная реактивность от регулятора
#define idR0CN91LDU	 313	//( - , DU) Рассчётная реактивность от регулятора
#define A3MC03RDU	 BUFFER[738]	//( - , DU) Координата положения ИМ 0-й реактивности
#define idA3MC03RDU	 314	//( - , DU) Координата положения ИМ 0-й реактивности
#define A3AB15LDU	 BUFFER[743]	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
#define idA3AB15LDU	 315	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
#define R0AB20LDU	 BUFFER[745]	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
#define idR0AB20LDU	 316	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
#define R0CN92LDU	 BUFFER[747]	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
#define idR0CN92LDU	 317	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
#define R0VN11RDU	 BUFFER[752]	//( - , DU) Текущая мощность РУ
#define idR0VN11RDU	 318	//( - , DU) Текущая мощность РУ
#define R0VN12RDU	 BUFFER[757]	//( - , DU) Заданная мощность РУ
#define idR0VN12RDU	 319	//( - , DU) Заданная мощность РУ
#define R0AB19LDU	 BUFFER[762]	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
#define idR0AB19LDU	 320	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
#define R0CN93LDU	 BUFFER[764]	//( - , DU) время работы на мощности более 100Вт, сек
#define idR0CN93LDU	 321	//( - , DU) время работы на мощности более 100Вт, сек
#define R0CN94LDU	 BUFFER[769]	//( - , DU) Скорость изменения мощности
#define idR0CN94LDU	 322	//( - , DU) Скорость изменения мощности
#define R0DE33LDU	 BUFFER[774]	//(sbk:20 - S03SBK, DiagnDU) диагностика шкафа ДУ двери
#define idR0DE33LDU	 323	//(sbk:20 - S03SBK, DiagnDU) диагностика шкафа ДУ двери
#define R0DE34LDU	 BUFFER[776]	//(sbk:20 - S04SBK, DiagnDU) диагностика шкафа ДУ температура меньше 43
#define idR0DE34LDU	 324	//(sbk:20 - S04SBK, DiagnDU) диагностика шкафа ДУ температура меньше 43
#define R0DE35LDU	 BUFFER[778]	//(sbk:20 - S05SBK, DiagnDU) диагностика шкафа ДУ температура больше 53
#define idR0DE35LDU	 325	//(sbk:20 - S05SBK, DiagnDU) диагностика шкафа ДУ температура больше 53
#define R0DE36LDU	 BUFFER[780]	//(sbk:20 - S06SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 1
#define idR0DE36LDU	 326	//(sbk:20 - S06SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 1
#define R0DE37LDU	 BUFFER[782]	//(sbk:20 - S07SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 2
#define idR0DE37LDU	 327	//(sbk:20 - S07SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 2
#define R0DE38LDU	 BUFFER[784]	//(sbk:20 - S08SBK, DiagnDU) диагностика шкафа ДУ МП15-3 место 3
#define idR0DE38LDU	 328	//(sbk:20 - S08SBK, DiagnDU) диагностика шкафа ДУ МП15-3 место 3
#define R0DE39LDU	 BUFFER[786]	//(sbk:20 - S09SBK, DiagnDU) диагностика шкафа ДУ МП24-2 место 4
#define idR0DE39LDU	 329	//(sbk:20 - S09SBK, DiagnDU) диагностика шкафа ДУ МП24-2 место 4
#define R0DEB3LDU	 BUFFER[788]	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
#define idR0DEB3LDU	 330	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
#define R0DEB2LDU	 BUFFER[790]	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
#define idR0DEB2LDU	 331	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
#define R0DEB1LDU	 BUFFER[792]	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
#define idR0DEB1LDU	 332	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
#define R0DEB4LDU	 BUFFER[794]	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
#define idR0DEB4LDU	 333	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
#define R0DE3DLDU	 BUFFER[796]	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
#define idR0DE3DLDU	 334	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
#define R0DE3CLDU	 BUFFER[798]	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
#define idR0DE3CLDU	 335	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
#define TestDiagnDU	 BUFFER[800]	//( - , DU) Неисправность от
#define idTestDiagnDU	 336	//( - , DU) Неисправность от
#define B1IC01UDU	 BUFFER[802]	//( - , MDuS) Координата штока ББ2 (дел.энк)
#define idB1IC01UDU	 337	//( - , MDuS) Координата штока ББ2 (дел.энк)
#define B1VC01RDU	 BUFFER[807]	//( - , DU) Координата ББ2, мм
#define idB1VC01RDU	 338	//( - , DU) Координата ББ2, мм
#define B1IS11LDU	 BUFFER[812]	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
#define idB1IS11LDU	 339	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
#define A2IC01UDU	 BUFFER[814]	//( - , MDuS) Координата штока РБ1 (дел.энк)
#define idA2IC01UDU	 340	//( - , MDuS) Координата штока РБ1 (дел.энк)
#define B2IC01UDU	 BUFFER[819]	//( - , MDuS) Координата штока РБ2 (дел.энк)
#define idB2IC01UDU	 341	//( - , MDuS) Координата штока РБ2 (дел.энк)
#define A3IC01UDU	 BUFFER[824]	//( - , MDuS) Координата штока ИС1 (дел.энк)
#define idA3IC01UDU	 342	//( - , MDuS) Координата штока ИС1 (дел.энк)
#define B3IC01UDU	 BUFFER[829]	//( - , MDuS) Координата штока ИС2 (дел.энк)
#define idB3IC01UDU	 343	//( - , MDuS) Координата штока ИС2 (дел.энк)
#define B3VC01RDU	 BUFFER[834]	//( - , DU) Координата ИС2, мм
#define idB3VC01RDU	 344	//( - , DU) Координата ИС2, мм
#define A8IC01UDU	 BUFFER[839]	//( - , MDuS) Координата ДС2 (дел.энк)
#define idA8IC01UDU	 345	//( - , MDuS) Координата ДС2 (дел.энк)
#define R5VS01IDU	 BUFFER[844]	//( - , DU) Готовность к управлению ворот отстойной зоны
#define idR5VS01IDU	 346	//( - , DU) Готовность к управлению ворот отстойной зоны
#define R3VS22LDU	 BUFFER[847]	//( - , DU) Движение гомогенных дверей к закрыты
#define idR3VS22LDU	 347	//( - , DU) Движение гомогенных дверей к закрыты
#define R3VS12LDU	 BUFFER[849]	//( - , DU) Движение гомогенных дверей к открыты
#define idR3VS12LDU	 348	//( - , DU) Движение гомогенных дверей к открыты
#define R3VS01IDU	 BUFFER[851]	//( - , DU) Готовность к управлению гомогенных дверей
#define idR3VS01IDU	 349	//( - , DU) Готовность к управлению гомогенных дверей
#define A3AB13LDU	 BUFFER[854]	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
#define idA3AB13LDU	 350	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
#define syn_A3VP52LDU	 BUFFER[856]	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define idsyn_A3VP52LDU	 351	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define B3AB13LDU	 BUFFER[858]	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define idB3AB13LDU	 352	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define syn_B3VP52LDU	 BUFFER[860]	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define idsyn_B3VP52LDU	 353	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define R0DE02LDU	 BUFFER[862]	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
#define idR0DE02LDU	 354	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
#define R0DE03LDU	 BUFFER[865]	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
#define idR0DE03LDU	 355	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
#define R0DE04LDU	 BUFFER[868]	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
#define idR0DE04LDU	 356	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
#define R0DE08LDU	 BUFFER[871]	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
#define idR0DE08LDU	 357	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
#define R0DE05LDU	 BUFFER[874]	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
#define idR0DE05LDU	 358	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
#define R0DE09LDU	 BUFFER[877]	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
#define idR0DE09LDU	 359	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
#define R0DE0ALDU	 BUFFER[880]	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
#define idR0DE0ALDU	 360	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
#define R0DE07LDU	 BUFFER[883]	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
#define idR0DE07LDU	 361	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
#define R0DE0CLDU	 BUFFER[886]	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
#define idR0DE0CLDU	 362	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
#define R0DE0BLDU	 BUFFER[889]	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
#define idR0DE0BLDU	 363	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
#define R0DE0DLDU	 BUFFER[892]	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
#define idR0DE0DLDU	 364	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
#define R0DE0FLDU	 BUFFER[895]	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
#define idR0DE0FLDU	 365	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
#define R0DE31LDU	 BUFFER[898]	//(sbk:20 - S01SBK, DiagnDU) диагностика шкафа ДУ сеть 1
#define idR0DE31LDU	 366	//(sbk:20 - S01SBK, DiagnDU) диагностика шкафа ДУ сеть 1
#define TTLDU	 BUFFER[900]	//( - , DU) ttl
#define idTTLDU	 367	//( - , DU) ttl
#define R0DE32LDU	 BUFFER[903]	//(sbk:20 - S02SBK, DiagnDU) диагностика шкафа ДУ сеть 2
#define idR0DE32LDU	 368	//(sbk:20 - S02SBK, DiagnDU) диагностика шкафа ДУ сеть 2
#define A6AB06LDU	 BUFFER[905]	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
#define idA6AB06LDU	 369	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
#define A6AB07LDU	 BUFFER[907]	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
#define idA6AB07LDU	 370	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
#define A6AB08LDU	 BUFFER[909]	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
#define idA6AB08LDU	 371	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
#define A6AB09LDU	 BUFFER[911]	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
#define idA6AB09LDU	 372	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
#define B6AB06LDU	 BUFFER[913]	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
#define idB6AB06LDU	 373	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
#define B6AB07LDU	 BUFFER[915]	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
#define idB6AB07LDU	 374	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
#define B6AB08LDU	 BUFFER[917]	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
#define idB6AB08LDU	 375	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
#define B6AB09LDU	 BUFFER[919]	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
#define idB6AB09LDU	 376	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
#define A6AB05LDU	 BUFFER[921]	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
#define idA6AB05LDU	 377	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
#define B8VS12LDU	 BUFFER[923]	//( - , DU) Движение АЗ2 в сторону ВУ
#define idB8VS12LDU	 378	//( - , DU) Движение АЗ2 в сторону ВУ
#define B8CV01RDU	 BUFFER[925]	//( - , DU) Измеренная скорость перемещения АЗ2
#define idB8CV01RDU	 379	//( - , DU) Измеренная скорость перемещения АЗ2
#define B8AB06LDU	 BUFFER[930]	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
#define idB8AB06LDU	 380	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
#define B8AB07LDU	 BUFFER[932]	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
#define idB8AB07LDU	 381	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
#define B8AB05LDU	 BUFFER[934]	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
#define idB8AB05LDU	 382	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
#define B8VS22LDU	 BUFFER[936]	//( - , DU) Движение АЗ2 в сторону НУ
#define idB8VS22LDU	 383	//( - , DU) Движение АЗ2 в сторону НУ
#define B8AZ03LDU	 BUFFER[938]	//( - , DU) Несанкционированное перемещение АЗ2
#define idB8AZ03LDU	 384	//( - , DU) Несанкционированное перемещение АЗ2
#define R0MD11LP1	 BUFFER[940]	//( - , DU) Кнопка ПУСК
#define idR0MD11LP1	 385	//( - , DU) Кнопка ПУСК
#define B8AD10LDU	 BUFFER[942]	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
#define idB8AD10LDU	 386	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
#define B8AD20LDU	 BUFFER[944]	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
#define idB8AD20LDU	 387	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
#define B8IS11LDU	 BUFFER[946]	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
#define idB8IS11LDU	 388	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
#define B8AB01LDU	 BUFFER[948]	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
#define idB8AB01LDU	 389	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
#define B8AB04LDU	 BUFFER[950]	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
#define idB8AB04LDU	 390	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
#define B8AB08LDU	 BUFFER[952]	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
#define idB8AB08LDU	 391	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
#define A5AZ03LDU	 BUFFER[954]	//( - , DU) Несанкционированное перемещение НЛ1
#define idA5AZ03LDU	 392	//( - , DU) Несанкционированное перемещение НЛ1
#define A5AB01LDU	 BUFFER[956]	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
#define idA5AB01LDU	 393	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
#define A5AB02LDU	 BUFFER[958]	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
#define idA5AB02LDU	 394	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
#define B5AZ03LDU	 BUFFER[960]	//( - , DU) Несанкционированное перемещение НЛ2
#define idB5AZ03LDU	 395	//( - , DU) Несанкционированное перемещение НЛ2
#define B5AB01LDU	 BUFFER[962]	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
#define idB5AB01LDU	 396	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
#define B5AB02LDU	 BUFFER[964]	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
#define idB5AB02LDU	 397	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
#define A4IS21LDU	 BUFFER[966]	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
#define idA4IS21LDU	 398	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
#define B4IS21LDU	 BUFFER[968]	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
#define idB4IS21LDU	 399	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
#define B4AD10LDU	 BUFFER[970]	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
#define idB4AD10LDU	 400	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
#define A4AD10LDU	 BUFFER[972]	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
#define idA4AD10LDU	 401	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
#define A4AZ03LDU	 BUFFER[974]	//( - , DU) Несанкционированное перемещение НИ1
#define idA4AZ03LDU	 402	//( - , DU) Несанкционированное перемещение НИ1
#define A4AB01LDU	 BUFFER[976]	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
#define idA4AB01LDU	 403	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
#define A4AB02LDU	 BUFFER[978]	//( - , DU) Блокировка движения НИ1 - Нет перемещения
#define idA4AB02LDU	 404	//( - , DU) Блокировка движения НИ1 - Нет перемещения
#define B4AZ03LDU	 BUFFER[980]	//( - , DU) Несанкционированное перемещение НИ2
#define idB4AZ03LDU	 405	//( - , DU) Несанкционированное перемещение НИ2
#define B4AB01LDU	 BUFFER[982]	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
#define idB4AB01LDU	 406	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
#define B4AB02LDU	 BUFFER[984]	//( - , DU) Блокировка движения НИ2 - Нет перемещения
#define idB4AB02LDU	 407	//( - , DU) Блокировка движения НИ2 - Нет перемещения
#define A5AB04LDU	 BUFFER[986]	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
#define idA5AB04LDU	 408	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
#define B5AB04LDU	 BUFFER[988]	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
#define idB5AB04LDU	 409	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
#define A1IS12LDU	 BUFFER[990]	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
#define idA1IS12LDU	 410	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
#define A2IS12LDU	 BUFFER[992]	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
#define idA2IS12LDU	 411	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
#define B1IS12LDU	 BUFFER[994]	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
#define idB1IS12LDU	 412	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
#define B2IS12LDU	 BUFFER[996]	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
#define idB2IS12LDU	 413	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
#define R4IS11LDU	 BUFFER[998]	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
#define idR4IS11LDU	 414	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
#define A8AB11LDU	 BUFFER[1000]	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
#define idA8AB11LDU	 415	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
#define A8AB12LDU	 BUFFER[1002]	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
#define idA8AB12LDU	 416	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
#define A8AB13LDU	 BUFFER[1004]	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
#define idA8AB13LDU	 417	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
#define A8AB14LDU	 BUFFER[1006]	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
#define idA8AB14LDU	 418	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
#define A8AB02LDU	 BUFFER[1008]	//( - , DU) Блокировка движения ДС2- АНИ не установлен
#define idA8AB02LDU	 419	//( - , DU) Блокировка движения ДС2- АНИ не установлен
#define A8AB01LDU	 BUFFER[1010]	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
#define idA8AB01LDU	 420	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
#define A2VS11LDU	 BUFFER[1012]	//( - , DU) Движение РБ1 в сторону ВУ
#define idA2VS11LDU	 421	//( - , DU) Движение РБ1 в сторону ВУ
#define A2CV01RDU	 BUFFER[1014]	//( - , DU) Измеренная скорость перемещения РБ1
#define idA2CV01RDU	 422	//( - , DU) Измеренная скорость перемещения РБ1
#define A2AB04LDU	 BUFFER[1019]	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
#define idA2AB04LDU	 423	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
#define A2AB02LDU	 BUFFER[1021]	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
#define idA2AB02LDU	 424	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
#define A2AB01LDU	 BUFFER[1023]	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
#define idA2AB01LDU	 425	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
#define A2VS21LDU	 BUFFER[1025]	//( - , DU) Движение РБ1 в сторону НУ
#define idA2VS21LDU	 426	//( - , DU) Движение РБ1 в сторону НУ
#define A2AZ03LDU	 BUFFER[1027]	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
#define idA2AZ03LDU	 427	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
#define A2AD11LDU	 BUFFER[1029]	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	 428	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
#define A2AD21LDU	 BUFFER[1031]	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	 429	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
#define A2AD02LDU	 BUFFER[1033]	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
#define idA2AD02LDU	 430	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
#define A2AD03LDU	 BUFFER[1035]	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
#define idA2AD03LDU	 431	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
#define A2AD04LDU	 BUFFER[1037]	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
#define idA2AD04LDU	 432	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
#define A2AD05LDU	 BUFFER[1039]	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
#define idA2AD05LDU	 433	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
#define A2AB07LDU	 BUFFER[1041]	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
#define idA2AB07LDU	 434	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
#define A2AB08LDU	 BUFFER[1043]	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
#define idA2AB08LDU	 435	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
#define A2AB05LDU	 BUFFER[1045]	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
#define idA2AB05LDU	 436	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
#define A2AB06LDU	 BUFFER[1047]	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
#define idA2AB06LDU	 437	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
#define B8AB09LDU	 BUFFER[1049]	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
#define idB8AB09LDU	 438	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
#define B8AB10LDU	 BUFFER[1051]	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
#define idB8AB10LDU	 439	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
#define B8AB11LDU	 BUFFER[1053]	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
#define idB8AB11LDU	 440	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
#define B8AB12LDU	 BUFFER[1055]	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
#define idB8AB12LDU	 441	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
#define B8AB13LDU	 BUFFER[1057]	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
#define idB8AB13LDU	 442	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
#define B8AB14LDU	 BUFFER[1059]	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
#define idB8AB14LDU	 443	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
#define B8AB02LDU	 BUFFER[1061]	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
#define idB8AB02LDU	 444	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
#define A8VS12LDU	 BUFFER[1063]	//( - , DU) Движение ДС2 в сторону ВУ
#define idA8VS12LDU	 445	//( - , DU) Движение ДС2 в сторону ВУ
#define A8CV01RDU	 BUFFER[1065]	//( - , DU) Измеренная скорость перемещения ДС2
#define idA8CV01RDU	 446	//( - , DU) Измеренная скорость перемещения ДС2
#define A8AB06LDU	 BUFFER[1070]	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
#define idA8AB06LDU	 447	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
#define A8AB07LDU	 BUFFER[1072]	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
#define idA8AB07LDU	 448	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
#define A8AB05LDU	 BUFFER[1074]	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
#define idA8AB05LDU	 449	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
#define A8VS22LDU	 BUFFER[1076]	//( - , DU) Движение ДС2 в сторону НУ
#define idA8VS22LDU	 450	//( - , DU) Движение ДС2 в сторону НУ
#define A8AZ03LDU	 BUFFER[1078]	//( - , DU) Несанкционированное перемещение ДС2
#define idA8AZ03LDU	 451	//( - , DU) Несанкционированное перемещение ДС2
#define A8AD10LDU	 BUFFER[1080]	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
#define idA8AD10LDU	 452	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
#define A8AD20LDU	 BUFFER[1082]	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
#define idA8AD20LDU	 453	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
#define B8IS22LDU	 BUFFER[1084]	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
#define idB8IS22LDU	 454	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
#define A8IS12LDU	 BUFFER[1086]	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
#define idA8IS12LDU	 455	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
#define A8AB04LDU	 BUFFER[1088]	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
#define idA8AB04LDU	 456	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
#define A8IS22LDU	 BUFFER[1090]	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
#define idA8IS22LDU	 457	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
#define A8AB08LDU	 BUFFER[1092]	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define idA8AB08LDU	 458	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define A8AB09LDU	 BUFFER[1094]	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
#define idA8AB09LDU	 459	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
#define A8AB10LDU	 BUFFER[1096]	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
#define idA8AB10LDU	 460	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
#define B6IS21LDU	 BUFFER[1098]	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
#define idB6IS21LDU	 461	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
#define A6VS22LDU	 BUFFER[1100]	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
#define idA6VS22LDU	 462	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
#define A6VS12LDU	 BUFFER[1102]	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
#define idA6VS12LDU	 463	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
#define B6VS22LDU	 BUFFER[1104]	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
#define idB6VS22LDU	 464	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
#define B6VS12LDU	 BUFFER[1106]	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
#define idB6VS12LDU	 465	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
#define A6AD10LDU	 BUFFER[1108]	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
#define idA6AD10LDU	 466	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
#define A6AD20LDU	 BUFFER[1110]	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
#define idA6AD20LDU	 467	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
#define B6AD10LDU	 BUFFER[1112]	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
#define idB6AD10LDU	 468	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
#define B6AD20LDU	 BUFFER[1114]	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
#define idB6AD20LDU	 469	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
#define A6AZ03LDU	 BUFFER[1116]	//( - , DU) Несанкционированное перемещение БЗ1
#define idA6AZ03LDU	 470	//( - , DU) Несанкционированное перемещение БЗ1
#define A6AB01LDU	 BUFFER[1118]	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
#define idA6AB01LDU	 471	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
#define A6AB02LDU	 BUFFER[1120]	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
#define idA6AB02LDU	 472	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
#define B6AZ03LDU	 BUFFER[1122]	//( - , DU) Несанкционированное перемещение БЗ2
#define idB6AZ03LDU	 473	//( - , DU) Несанкционированное перемещение БЗ2
#define B6AB01LDU	 BUFFER[1124]	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
#define idB6AB01LDU	 474	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
#define B6AB02LDU	 BUFFER[1126]	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
#define idB6AB02LDU	 475	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
#define A6AB04LDU	 BUFFER[1128]	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
#define idA6AB04LDU	 476	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
#define B6AB04LDU	 BUFFER[1130]	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
#define idB6AB04LDU	 477	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
#define R4AB01LDU	 BUFFER[1132]	//( - , DU) Блокировка движения тележки - АНИ не установлен
#define idR4AB01LDU	 478	//( - , DU) Блокировка движения тележки - АНИ не установлен
#define R8IS11LDU	 BUFFER[1134]	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
#define idR8IS11LDU	 479	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
#define R6IS21LDU	 BUFFER[1136]	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
#define idR6IS21LDU	 480	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
#define A0VN71LZ2	 BUFFER[1138]	//( - , MDuBz2) АЗ по АС мощности для АЗ1
#define idA0VN71LZ2	 481	//( - , MDuBz2) АЗ по АС мощности для АЗ1
#define A0VN71LZ1	 BUFFER[1140]	//( - , MDuBz1) АЗ по АС мощности для АЗ1
#define idA0VN71LZ1	 482	//( - , MDuBz1) АЗ по АС мощности для АЗ1
#define R0NE01LDU	 BUFFER[1142]	//( - , DU) Потеря связи с БАЗ1
#define idR0NE01LDU	 483	//( - , DU) Потеря связи с БАЗ1
#define R0MW15IP1	 BUFFER[1144]	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
#define idR0MW15IP1	 484	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
#define R0MW14IP1	 BUFFER[1147]	//( - , DU) Переключатель ПРОГРАММЫ
#define idR0MW14IP1	 485	//( - , DU) Переключатель ПРОГРАММЫ
#define R0MW12IP1	 BUFFER[1150]	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
#define idR0MW12IP1	 486	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
#define R0MW13IP1	 BUFFER[1153]	//( - , DU) Переключатель ВЫБОР ЗОН
#define idR0MW13IP1	 487	//( - , DU) Переключатель ВЫБОР ЗОН
#define R0MW16IP1	 BUFFER[1156]	//( - , DU) Переключатель ВИД ПРОВЕРКИ
#define idR0MW16IP1	 488	//( - , DU) Переключатель ВИД ПРОВЕРКИ
#define R0MW11IP1	 BUFFER[1159]	//( - , DU) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	 489	//( - , DU) Переключатель ВЫСТРЕЛ
#define R0MW11IP2	 BUFFER[1162]	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
#define idR0MW11IP2	 490	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
#define R0MW13LP2	 BUFFER[1165]	//( - , DU) Переключатель СЕТЬ
#define idR0MW13LP2	 491	//( - , DU) Переключатель СЕТЬ
#define R0MD32LP1	 BUFFER[1167]	//( - , DU) Кнопка СПУСК
#define idR0MD32LP1	 492	//( - , DU) Кнопка СПУСК
#define R0MD31LP1	 BUFFER[1169]	//( - , DU) Кнопка СТОП
#define idR0MD31LP1	 493	//( - , DU) Кнопка СТОП
#define A1IS21LDU	 BUFFER[1171]	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
#define idA1IS21LDU	 494	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
#define A2IS21LDU	 BUFFER[1173]	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
#define idA2IS21LDU	 495	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
#define A3IS21LDU	 BUFFER[1175]	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
#define idA3IS21LDU	 496	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
#define B1IS21LDU	 BUFFER[1177]	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
#define idB1IS21LDU	 497	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
#define B2IS21LDU	 BUFFER[1179]	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
#define idB2IS21LDU	 498	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
#define B3IS21LDU	 BUFFER[1181]	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
#define idB3IS21LDU	 499	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
#define R0ES01LDU	 BUFFER[1183]	//( - , DU) ОРР не в исходном состоянии
#define idR0ES01LDU	 500	//( - , DU) ОРР не в исходном состоянии
#define R4MD11LP2	 BUFFER[1185]	//( - , DU) Кнопка ВПЕРЁД  (тележки)
#define idR4MD11LP2	 501	//( - , DU) Кнопка ВПЕРЁД  (тележки)
#define R4MD31LP2	 BUFFER[1187]	//( - , DU) Кнопка СТОП  (тележки)
#define idR4MD31LP2	 502	//( - , DU) Кнопка СТОП  (тележки)
#define R4MD21LP2	 BUFFER[1189]	//( - , DU) Кнопка НАЗАД  (тележки)
#define idR4MD21LP2	 503	//( - , DU) Кнопка НАЗАД  (тележки)
#define A6IS11LDU	 BUFFER[1191]	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
#define idA6IS11LDU	 504	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
#define A6IS21LDU	 BUFFER[1193]	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
#define idA6IS21LDU	 505	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
#define B6IS11LDU	 BUFFER[1195]	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
#define idB6IS11LDU	 506	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
#define A4IS11LDU	 BUFFER[1197]	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
#define idA4IS11LDU	 507	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
#define B4IS11LDU	 BUFFER[1199]	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
#define idB4IS11LDU	 508	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
#define R4AB13LDU	 BUFFER[1201]	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
#define idR4AB13LDU	 509	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
#define R4AB14LDU	 BUFFER[1203]	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
#define idR4AB14LDU	 510	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
#define R4AB15LDU	 BUFFER[1205]	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
#define idR4AB15LDU	 511	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
#define R5IS11LDU	 BUFFER[1207]	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	 512	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
#define R4AB16LDU	 BUFFER[1209]	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
#define idR4AB16LDU	 513	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
#define R4AB17LDU	 BUFFER[1211]	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define idR4AB17LDU	 514	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define R4AB18LDU	 BUFFER[1213]	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define idR4AB18LDU	 515	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define R4AD10LDU	 BUFFER[1215]	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
#define idR4AD10LDU	 516	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
#define R4AD20LDU	 BUFFER[1217]	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
#define idR4AD20LDU	 517	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
#define A5VS22LDU	 BUFFER[1219]	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
#define idA5VS22LDU	 518	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
#define A5VS12LDU	 BUFFER[1221]	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
#define idA5VS12LDU	 519	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
#define B5VS22LDU	 BUFFER[1223]	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
#define idB5VS22LDU	 520	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
#define B5VS12LDU	 BUFFER[1225]	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
#define idB5VS12LDU	 521	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
#define B5AD10LDU	 BUFFER[1227]	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
#define idB5AD10LDU	 522	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
#define B5AD20LDU	 BUFFER[1229]	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
#define idB5AD20LDU	 523	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
#define A5AD10LDU	 BUFFER[1231]	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
#define idA5AD10LDU	 524	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
#define A5AD20LDU	 BUFFER[1233]	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
#define idA5AD20LDU	 525	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
#define A5IS11LDU	 BUFFER[1235]	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
#define idA5IS11LDU	 526	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
#define A5IS21LDU	 BUFFER[1237]	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
#define idA5IS21LDU	 527	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
#define B5IS11LDU	 BUFFER[1239]	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
#define idB5IS11LDU	 528	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
#define B5IS21LDU	 BUFFER[1241]	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
#define idB5IS21LDU	 529	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
#define R0NE02LDU	 BUFFER[1243]	//( - , DU) Потеря связи с БАЗ2
#define idR0NE02LDU	 530	//( - , DU) Потеря связи с БАЗ2
#define R4AB02LDU	 BUFFER[1245]	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
#define idR4AB02LDU	 531	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
#define R0NE08LDU	 BUFFER[1247]	//( - , DU) Потеря связи с ОПУ
#define idR0NE08LDU	 532	//( - , DU) Потеря связи с ОПУ
#define R4IS21LDU	 BUFFER[1249]	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
#define idR4IS21LDU	 533	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
#define R4IS22LDU	 BUFFER[1251]	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
#define idR4IS22LDU	 534	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
#define R4IS12LDU	 BUFFER[1253]	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
#define idR4IS12LDU	 535	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
#define R4VS22LDU	 BUFFER[1255]	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
#define idR4VS22LDU	 536	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
#define R4VS12LDU	 BUFFER[1257]	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
#define idR4VS12LDU	 537	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
#define R4AZ03LDU	 BUFFER[1259]	//( - , DU) Несанкционированное перемещение тележки
#define idR4AZ03LDU	 538	//( - , DU) Несанкционированное перемещение тележки
#define R4AB03LDU	 BUFFER[1261]	//( - , DU) Блокировка движения тележки - Самоход любого механизма
#define idR4AB03LDU	 539	//( - , DU) Блокировка движения тележки - Самоход любого механизма
#define R1IS21LDU	 BUFFER[1263]	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
#define idR1IS21LDU	 540	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
#define R2IS21LDU	 BUFFER[1265]	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
#define idR2IS21LDU	 541	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
#define R4AB04LDU	 BUFFER[1267]	//( - , DU) Блокировка движения тележки - Превышение времени движения
#define idR4AB04LDU	 542	//( - , DU) Блокировка движения тележки - Превышение времени движения
#define R4AB05LDU	 BUFFER[1269]	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
#define idR4AB05LDU	 543	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
#define R4AB06LDU	 BUFFER[1271]	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
#define idR4AB06LDU	 544	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
#define R4AB07LDU	 BUFFER[1273]	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
#define idR4AB07LDU	 545	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
#define R4AB08LDU	 BUFFER[1275]	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define idR4AB08LDU	 546	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define R4AB09LDU	 BUFFER[1277]	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
#define idR4AB09LDU	 547	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
#define B0VN71LZ1	 BUFFER[1279]	//( - , MDuBz1) АЗ по АС мощности для АЗ2
#define idB0VN71LZ1	 548	//( - , MDuBz1) АЗ по АС мощности для АЗ2
#define B0VN71LZ2	 BUFFER[1281]	//( - , MDuBz2) АЗ по АС мощности для АЗ2
#define idB0VN71LZ2	 549	//( - , MDuBz2) АЗ по АС мощности для АЗ2
#define R4AB10LDU	 BUFFER[1283]	//( - , DU) Блокировка тележки - не открыта биологическая защита
#define idR4AB10LDU	 550	//( - , DU) Блокировка тележки - не открыта биологическая защита
#define R4AB11LDU	 BUFFER[1285]	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
#define idR4AB11LDU	 551	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
#define R4AB12LDU	 BUFFER[1287]	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
#define idR4AB12LDU	 552	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
#define A3AD21LDU	 BUFFER[1289]	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	 553	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
#define A3AD02LDU	 BUFFER[1291]	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
#define idA3AD02LDU	 554	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
#define A3AD03LDU	 BUFFER[1293]	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
#define idA3AD03LDU	 555	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
#define A3AD04LDU	 BUFFER[1295]	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
#define idA3AD04LDU	 556	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
#define A3AD05LDU	 BUFFER[1297]	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
#define idA3AD05LDU	 557	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
#define A3AD01LDU	 BUFFER[1299]	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
#define idA3AD01LDU	 558	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
#define A3CV02RDU	 BUFFER[1301]	//( - , DU) Заданная скорость перемещения ИС1
#define idA3CV02RDU	 559	//( - , DU) Заданная скорость перемещения ИС1
#define A3AB07LDU	 BUFFER[1306]	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
#define idA3AB07LDU	 560	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
#define A3AB08LDU	 BUFFER[1308]	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
#define idA3AB08LDU	 561	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
#define A3AB05LDU	 BUFFER[1310]	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
#define idA3AB05LDU	 562	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
#define A3AB06LDU	 BUFFER[1312]	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
#define idA3AB06LDU	 563	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
#define A3AB09LDU	 BUFFER[1314]	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
#define idA3AB09LDU	 564	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
#define A3AB10LDU	 BUFFER[1316]	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
#define idA3AB10LDU	 565	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
#define A3AB11LDU	 BUFFER[1318]	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
#define idA3AB11LDU	 566	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
#define A3AB12LDU	 BUFFER[1320]	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA3AB12LDU	 567	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A3AB14LDU	 BUFFER[1322]	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
#define idA3AB14LDU	 568	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
#define A3AB16LDU	 BUFFER[1324]	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
#define idA3AB16LDU	 569	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
#define A3AB17LDU	 BUFFER[1326]	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
#define idA3AB17LDU	 570	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
#define A3AB18LDU	 BUFFER[1328]	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
#define idA3AB18LDU	 571	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
#define A3AB20LDU	 BUFFER[1330]	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
#define idA3AB20LDU	 572	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
#define B3VS12LDU	 BUFFER[1332]	//( - , DU) Движение ИС2 в сторону ВУ
#define idB3VS12LDU	 573	//( - , DU) Движение ИС2 в сторону ВУ
#define B3CV01RDU	 BUFFER[1334]	//( - , DU) Измеренная скорость перемещения ИС2
#define idB3CV01RDU	 574	//( - , DU) Измеренная скорость перемещения ИС2
#define B3AB04LDU	 BUFFER[1339]	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
#define idB3AB04LDU	 575	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
#define B1AD01LDU	 BUFFER[1341]	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
#define idB1AD01LDU	 576	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
#define B1CV02RDU	 BUFFER[1343]	//( - , DU) Заданная скорость перемещения ББ2
#define idB1CV02RDU	 577	//( - , DU) Заданная скорость перемещения ББ2
#define B1AB07LDU	 BUFFER[1348]	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
#define idB1AB07LDU	 578	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
#define B1AB08LDU	 BUFFER[1350]	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
#define idB1AB08LDU	 579	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
#define B1AB05LDU	 BUFFER[1352]	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
#define idB1AB05LDU	 580	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
#define B1AB06LDU	 BUFFER[1354]	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
#define idB1AB06LDU	 581	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
#define B1AB09LDU	 BUFFER[1356]	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
#define idB1AB09LDU	 582	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
#define B1AB10LDU	 BUFFER[1358]	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
#define idB1AB10LDU	 583	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
#define B1AB11LDU	 BUFFER[1360]	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
#define idB1AB11LDU	 584	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
#define B1AB12LDU	 BUFFER[1362]	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idB1AB12LDU	 585	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define B1AB13LDU	 BUFFER[1364]	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
#define idB1AB13LDU	 586	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
#define B1AB14LDU	 BUFFER[1366]	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
#define idB1AB14LDU	 587	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
#define B1AB16LDU	 BUFFER[1368]	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
#define idB1AB16LDU	 588	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
#define B1AB17LDU	 BUFFER[1370]	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
#define idB1AB17LDU	 589	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
#define B1AB18LDU	 BUFFER[1372]	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
#define idB1AB18LDU	 590	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
#define A3VS12LDU	 BUFFER[1374]	//( - , DU) Движение ИС1 в сторону ВУ
#define idA3VS12LDU	 591	//( - , DU) Движение ИС1 в сторону ВУ
#define A3CV01RDU	 BUFFER[1376]	//( - , DU) Измеренная скорость перемещения ИС1
#define idA3CV01RDU	 592	//( - , DU) Измеренная скорость перемещения ИС1
#define A3AB04LDU	 BUFFER[1381]	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
#define idA3AB04LDU	 593	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
#define A3AB02LDU	 BUFFER[1383]	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
#define idA3AB02LDU	 594	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
#define A3AB01LDU	 BUFFER[1385]	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
#define idA3AB01LDU	 595	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
#define A3VS22LDU	 BUFFER[1387]	//( - , DU) Движение ИС1 в сторону НУ
#define idA3VS22LDU	 596	//( - , DU) Движение ИС1 в сторону НУ
#define A3AZ03LDU	 BUFFER[1389]	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
#define idA3AZ03LDU	 597	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
#define A3AD11LDU	 BUFFER[1391]	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	 598	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
#define B3AB18LDU	 BUFFER[1393]	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
#define idB3AB18LDU	 599	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
#define B3AB20LDU	 BUFFER[1395]	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
#define idB3AB20LDU	 600	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
#define C1MD31LP1	 BUFFER[1397]	//( - , DU) Кнопка СБРОС ББ
#define idC1MD31LP1	 601	//( - , DU) Кнопка СБРОС ББ
#define C1MD31LP2	 BUFFER[1399]	//( - , DU) Кнопка СБРОС ББ
#define idC1MD31LP2	 602	//( - , DU) Кнопка СБРОС ББ
#define A2AD31LDU	 BUFFER[1401]	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
#define idA2AD31LDU	 603	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
#define B2AD31LDU	 BUFFER[1403]	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
#define idB2AD31LDU	 604	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
#define A1AD31LDU	 BUFFER[1405]	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
#define idA1AD31LDU	 605	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
#define B1AD31LDU	 BUFFER[1407]	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
#define idB1AD31LDU	 606	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
#define A2AD32LDU	 BUFFER[1409]	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
#define idA2AD32LDU	 607	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
#define B2AD32LDU	 BUFFER[1411]	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
#define idB2AD32LDU	 608	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
#define A1AD32LDU	 BUFFER[1413]	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
#define idA1AD32LDU	 609	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
#define B1AD32LDU	 BUFFER[1415]	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
#define idB1AD32LDU	 610	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
#define R0MD11LP2	 BUFFER[1417]	//( - , DU) Кнопка Пуск проверки схем сброса
#define idR0MD11LP2	 611	//( - , DU) Кнопка Пуск проверки схем сброса
#define R0VX01LDU	 BUFFER[1419]	//( - , DU) ДО ИМПУЛЬСА
#define idR0VX01LDU	 612	//( - , DU) ДО ИМПУЛЬСА
#define R0VL01IDU	 BUFFER[1421]	//( - , DU) До импульса минут
#define idR0VL01IDU	 613	//( - , DU) До импульса минут
#define R0VL11IDU	 BUFFER[1424]	//( - , DU) До импульса секунд
#define idR0VL11IDU	 614	//( - , DU) До импульса секунд
#define R0VL06RDU	 BUFFER[1427]	//( - , DU) Индикация (Время задержки от ВУ РБ)
#define idR0VL06RDU	 615	//( - , DU) Индикация (Время задержки от ВУ РБ)
#define B3AD33LDU	 BUFFER[1432]	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 закрыть (обесточить)
#define idB3AD33LDU	 616	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 закрыть (обесточить)
#define B3IS11LDU	 BUFFER[1434]	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
#define idB3IS11LDU	 617	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
#define R0VL02RDU	 BUFFER[1436]	//( - , DU) Индикация (Время задержки ИНИ)
#define idR0VL02RDU	 618	//( - , DU) Индикация (Время задержки ИНИ)
#define R8AD21LDU	 BUFFER[1441]	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
#define idR8AD21LDU	 619	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
#define R0AD14LDU	 BUFFER[1443]	//( - , DU) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 620	//( - , DU) Имитация срабатывания верхней АС II УР
#define R0VL04RDU	 BUFFER[1445]	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
#define idR0VL04RDU	 621	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
#define B3AB02LDU	 BUFFER[1450]	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
#define idB3AB02LDU	 622	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
#define B3AB01LDU	 BUFFER[1452]	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
#define idB3AB01LDU	 623	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
#define B3VS22LDU	 BUFFER[1454]	//( - , DU) Движение ИС2 в сторону НУ
#define idB3VS22LDU	 624	//( - , DU) Движение ИС2 в сторону НУ
#define B3AZ03LDU	 BUFFER[1456]	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
#define idB3AZ03LDU	 625	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
#define B3AD11LDU	 BUFFER[1458]	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	 626	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
#define B3AD21LDU	 BUFFER[1460]	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	 627	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
#define B3AD02LDU	 BUFFER[1462]	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
#define idB3AD02LDU	 628	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
#define B3AD03LDU	 BUFFER[1464]	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
#define idB3AD03LDU	 629	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
#define B3AD04LDU	 BUFFER[1466]	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
#define idB3AD04LDU	 630	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
#define B3AD05LDU	 BUFFER[1468]	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
#define idB3AD05LDU	 631	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
#define B3AD01LDU	 BUFFER[1470]	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
#define idB3AD01LDU	 632	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
#define B3CV02RDU	 BUFFER[1472]	//( - , DU) Заданная скорость перемещения ИС2
#define idB3CV02RDU	 633	//( - , DU) Заданная скорость перемещения ИС2
#define B3AB07LDU	 BUFFER[1477]	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
#define idB3AB07LDU	 634	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
#define B3AB08LDU	 BUFFER[1479]	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
#define idB3AB08LDU	 635	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
#define B3AB05LDU	 BUFFER[1481]	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
#define idB3AB05LDU	 636	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
#define B3AB06LDU	 BUFFER[1483]	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
#define idB3AB06LDU	 637	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
#define B3AB09LDU	 BUFFER[1485]	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
#define idB3AB09LDU	 638	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
#define B3AB10LDU	 BUFFER[1487]	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
#define idB3AB10LDU	 639	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
#define B3AB11LDU	 BUFFER[1489]	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
#define idB3AB11LDU	 640	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
#define B3AB12LDU	 BUFFER[1491]	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define idB3AB12LDU	 641	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define B3AB14LDU	 BUFFER[1493]	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
#define idB3AB14LDU	 642	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
#define B3AB16LDU	 BUFFER[1495]	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
#define idB3AB16LDU	 643	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
#define B3AB17LDU	 BUFFER[1497]	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
#define idB3AB17LDU	 644	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
#define B2AB07LDU	 BUFFER[1499]	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
#define idB2AB07LDU	 645	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
#define B2AB08LDU	 BUFFER[1501]	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
#define idB2AB08LDU	 646	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
#define B2AB05LDU	 BUFFER[1503]	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
#define idB2AB05LDU	 647	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
#define B2AB06LDU	 BUFFER[1505]	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
#define idB2AB06LDU	 648	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
#define B2AB09LDU	 BUFFER[1507]	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
#define idB2AB09LDU	 649	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
#define B2AB10LDU	 BUFFER[1509]	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
#define idB2AB10LDU	 650	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
#define B2AB11LDU	 BUFFER[1511]	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
#define idB2AB11LDU	 651	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
#define B2AB12LDU	 BUFFER[1513]	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define idB2AB12LDU	 652	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define B2AB13LDU	 BUFFER[1515]	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
#define idB2AB13LDU	 653	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
#define B2AB14LDU	 BUFFER[1517]	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
#define idB2AB14LDU	 654	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
#define B2AB16LDU	 BUFFER[1519]	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
#define idB2AB16LDU	 655	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
#define B2AB17LDU	 BUFFER[1521]	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
#define idB2AB17LDU	 656	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
#define R1AZ03LDU	 BUFFER[1523]	//( - , DU) Несанкционированное перемещение МДЗ1
#define idR1AZ03LDU	 657	//( - , DU) Несанкционированное перемещение МДЗ1
#define R1AB01LDU	 BUFFER[1525]	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
#define idR1AB01LDU	 658	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
#define R1AB02LDU	 BUFFER[1527]	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
#define idR1AB02LDU	 659	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
#define R2AZ03LDU	 BUFFER[1529]	//( - , DU) Несанкционированное перемещение МДЗ2
#define idR2AZ03LDU	 660	//( - , DU) Несанкционированное перемещение МДЗ2
#define R2AB01LDU	 BUFFER[1531]	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
#define idR2AB01LDU	 661	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
#define R2AB02LDU	 BUFFER[1533]	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
#define idR2AB02LDU	 662	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
#define R1AB04LDU	 BUFFER[1535]	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
#define idR1AB04LDU	 663	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
#define R2AB04LDU	 BUFFER[1537]	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
#define idR2AB04LDU	 664	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
#define R1AD10LDU	 BUFFER[1539]	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
#define idR1AD10LDU	 665	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
#define R1AD20LDU	 BUFFER[1541]	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
#define idR1AD20LDU	 666	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
#define R1IS11LDU	 BUFFER[1543]	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
#define idR1IS11LDU	 667	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
#define A2AB09LDU	 BUFFER[1545]	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
#define idA2AB09LDU	 668	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
#define A2AB10LDU	 BUFFER[1547]	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
#define idA2AB10LDU	 669	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
#define A2AB11LDU	 BUFFER[1549]	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
#define idA2AB11LDU	 670	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
#define A2AB12LDU	 BUFFER[1551]	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA2AB12LDU	 671	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A2AB13LDU	 BUFFER[1553]	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
#define idA2AB13LDU	 672	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
#define A2AB14LDU	 BUFFER[1555]	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
#define idA2AB14LDU	 673	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
#define A2AB16LDU	 BUFFER[1557]	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
#define idA2AB16LDU	 674	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
#define A2AB17LDU	 BUFFER[1559]	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
#define idA2AB17LDU	 675	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
#define A2AD01LDU	 BUFFER[1561]	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
#define idA2AD01LDU	 676	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
#define A2CV02RDU	 BUFFER[1563]	//( - , DU) Заданная скорость перемещения РБ1
#define idA2CV02RDU	 677	//( - , DU) Заданная скорость перемещения РБ1
#define B2CV01RDU	 BUFFER[1568]	//( - , DU) Измеренная скорость перемещения РБ2
#define idB2CV01RDU	 678	//( - , DU) Измеренная скорость перемещения РБ2
#define B2AB04LDU	 BUFFER[1573]	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
#define idB2AB04LDU	 679	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
#define B2AB02LDU	 BUFFER[1575]	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
#define idB2AB02LDU	 680	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
#define B2AB01LDU	 BUFFER[1577]	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
#define idB2AB01LDU	 681	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
#define B2AZ03LDU	 BUFFER[1579]	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
#define idB2AZ03LDU	 682	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
#define B2AD11LDU	 BUFFER[1581]	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	 683	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
#define B2AD21LDU	 BUFFER[1583]	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	 684	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
#define B2AD02LDU	 BUFFER[1585]	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
#define idB2AD02LDU	 685	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
#define B2AD03LDU	 BUFFER[1587]	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
#define idB2AD03LDU	 686	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
#define B2AD04LDU	 BUFFER[1589]	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
#define idB2AD04LDU	 687	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
#define B2AD05LDU	 BUFFER[1591]	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
#define idB2AD05LDU	 688	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
#define B2AD01LDU	 BUFFER[1593]	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
#define idB2AD01LDU	 689	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
#define B2CV02RDU	 BUFFER[1595]	//( - , DU) Заданная скорость перемещения РБ2
#define idB2CV02RDU	 690	//( - , DU) Заданная скорость перемещения РБ2
#define A1AB06LDU	 BUFFER[1600]	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
#define idA1AB06LDU	 691	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
#define A1AB09LDU	 BUFFER[1602]	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
#define idA1AB09LDU	 692	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
#define A1AB10LDU	 BUFFER[1604]	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
#define idA1AB10LDU	 693	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
#define A1AB11LDU	 BUFFER[1606]	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
#define idA1AB11LDU	 694	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
#define A1AB12LDU	 BUFFER[1608]	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA1AB12LDU	 695	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A1AB13LDU	 BUFFER[1610]	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
#define idA1AB13LDU	 696	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
#define A1AB14LDU	 BUFFER[1612]	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
#define idA1AB14LDU	 697	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
#define A1AB16LDU	 BUFFER[1614]	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
#define idA1AB16LDU	 698	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
#define A1AB17LDU	 BUFFER[1616]	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
#define idA1AB17LDU	 699	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
#define A1AB18LDU	 BUFFER[1618]	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
#define idA1AB18LDU	 700	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
#define B1VS12LDU	 BUFFER[1620]	//( - , DU) Движение ББ2 в сторону ВУ
#define idB1VS12LDU	 701	//( - , DU) Движение ББ2 в сторону ВУ
#define B1CV01RDU	 BUFFER[1622]	//( - , DU) Измеренная скорость перемещения ББ2
#define idB1CV01RDU	 702	//( - , DU) Измеренная скорость перемещения ББ2
#define B1AB04LDU	 BUFFER[1627]	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
#define idB1AB04LDU	 703	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
#define B1AB02LDU	 BUFFER[1629]	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
#define idB1AB02LDU	 704	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
#define B1AB01LDU	 BUFFER[1631]	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
#define idB1AB01LDU	 705	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
#define B1VS22LDU	 BUFFER[1633]	//( - , DU) Движение ББ2 в сторону НУ
#define idB1VS22LDU	 706	//( - , DU) Движение ББ2 в сторону НУ
#define B1AZ03LDU	 BUFFER[1635]	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
#define idB1AZ03LDU	 707	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
#define B1AD11LDU	 BUFFER[1637]	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	 708	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
#define B1AD21LDU	 BUFFER[1639]	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	 709	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
#define B1AD02LDU	 BUFFER[1641]	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
#define idB1AD02LDU	 710	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
#define B1AD03LDU	 BUFFER[1643]	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
#define idB1AD03LDU	 711	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
#define B1AD04LDU	 BUFFER[1645]	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
#define idB1AD04LDU	 712	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
#define B1AD05LDU	 BUFFER[1647]	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
#define idB1AD05LDU	 713	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
#define R1VS22LDU	 BUFFER[1649]	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	 714	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
#define R2VS22LDU	 BUFFER[1651]	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	 715	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
#define R2VS12LDU	 BUFFER[1653]	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	 716	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
#define R1VS12LDU	 BUFFER[1655]	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	 717	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
#define R2IS11LDU	 BUFFER[1657]	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
#define idR2IS11LDU	 718	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
#define A1VS12LDU	 BUFFER[1659]	//( - , DU) Движение ББ1 в сторону ВУ
#define idA1VS12LDU	 719	//( - , DU) Движение ББ1 в сторону ВУ
#define A1CV01RDU	 BUFFER[1661]	//( - , DU) Измеренная скорость перемещения ББ1
#define idA1CV01RDU	 720	//( - , DU) Измеренная скорость перемещения ББ1
#define A1AB04LDU	 BUFFER[1666]	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
#define idA1AB04LDU	 721	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
#define A1AB02LDU	 BUFFER[1668]	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
#define idA1AB02LDU	 722	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
#define A1AB01LDU	 BUFFER[1670]	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
#define idA1AB01LDU	 723	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
#define A1VS22LDU	 BUFFER[1672]	//( - , DU) Движение ББ1 в сторону НУ
#define idA1VS22LDU	 724	//( - , DU) Движение ББ1 в сторону НУ
#define A1AZ03LDU	 BUFFER[1674]	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
#define idA1AZ03LDU	 725	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
#define A1AD11LDU	 BUFFER[1676]	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	 726	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
#define A1AD21LDU	 BUFFER[1678]	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	 727	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
#define A1AD02LDU	 BUFFER[1680]	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
#define idA1AD02LDU	 728	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
#define A1AD03LDU	 BUFFER[1682]	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
#define idA1AD03LDU	 729	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
#define A1AD04LDU	 BUFFER[1684]	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
#define idA1AD04LDU	 730	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
#define A1AD05LDU	 BUFFER[1686]	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
#define idA1AD05LDU	 731	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
#define A1AD01LDU	 BUFFER[1688]	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
#define idA1AD01LDU	 732	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
#define A1CV02RDU	 BUFFER[1690]	//( - , DU) Заданная скорость перемещения ББ1
#define idA1CV02RDU	 733	//( - , DU) Заданная скорость перемещения ББ1
#define A1AB07LDU	 BUFFER[1695]	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
#define idA1AB07LDU	 734	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
#define A1AB08LDU	 BUFFER[1697]	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
#define idA1AB08LDU	 735	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
#define A1AB05LDU	 BUFFER[1699]	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
#define idA1AB05LDU	 736	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
#define fEM_A1UC03RDU	 BUFFER[1701]	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define idfEM_A1UC03RDU	 737	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define dEM_A1UC05UDU	 BUFFER[1706]	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC05UDU	 738	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define dEM_A1UC06UDU	 BUFFER[1711]	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC06UDU	 739	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define dEM_A2UC06UDU	 BUFFER[1716]	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC06UDU	 740	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define dEM_A2UC05UDU	 BUFFER[1721]	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC05UDU	 741	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define fEM_A2UC03RDU	 BUFFER[1726]	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define idfEM_A2UC03RDU	 742	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define dEM_A3UC06UDU	 BUFFER[1731]	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC06UDU	 743	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define dEM_A3UC05UDU	 BUFFER[1736]	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC05UDU	 744	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define fEM_A3UC03RDU	 BUFFER[1741]	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define idfEM_A3UC03RDU	 745	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define dEM_A8UC06UDU	 BUFFER[1746]	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define iddEM_A8UC06UDU	 746	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define fEM_A8UC03RDU	 BUFFER[1751]	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
#define idfEM_A8UC03RDU	 747	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
#define dEM_A8UC05UDU	 BUFFER[1756]	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define iddEM_A8UC05UDU	 748	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define fEM_R0UV81RDU	 BUFFER[1761]	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	 749	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	 BUFFER[1766]	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	 750	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	 BUFFER[1771]	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	 751	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	 BUFFER[1776]	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	 752	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define fEM_R0UV86RDU	 BUFFER[1781]	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	 753	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV85RDU	 BUFFER[1786]	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	 754	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV87RDU	 BUFFER[1791]	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	 755	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_A3UP03RDU	 BUFFER[1796]	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	 756	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	 BUFFER[1801]	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	 757	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP43RDU	 BUFFER[1806]	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define idfEM_A3UP43RDU	 758	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define fEM_A3UP44RDU	 BUFFER[1811]	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP44RDU	 759	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP53RDU	 BUFFER[1816]	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP53RDU	 760	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP85RDU	 BUFFER[1821]	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP85RDU	 761	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP88RDU	 BUFFER[1826]	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP88RDU	 762	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP86RDU	 BUFFER[1831]	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP86RDU	 763	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_B8UV01RDU	 BUFFER[1836]	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
#define idfEM_B8UV01RDU	 764	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
#define fEM_B8UV02RDU	 BUFFER[1841]	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
#define idfEM_B8UV02RDU	 765	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
#define fEM_B8UV03RDU	 BUFFER[1846]	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
#define idfEM_B8UV03RDU	 766	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
#define fEM_B8UL04RDU	 BUFFER[1851]	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
#define idfEM_B8UL04RDU	 767	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
#define iEM_A2UV03CDU	 BUFFER[1856]	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define idiEM_A2UV03CDU	 768	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define fEM_A2UV01RDU	 BUFFER[1859]	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define idfEM_A2UV01RDU	 769	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define fEM_A2UV02RDU	 BUFFER[1864]	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define idfEM_A2UV02RDU	 770	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define fEM_A1UV01RDU	 BUFFER[1869]	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define idfEM_A1UV01RDU	 771	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define fEM_A1UV02RDU	 BUFFER[1874]	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define idfEM_A1UV02RDU	 772	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define fEM_A1UC06RDU	 BUFFER[1879]	//(A1UC06RDU) Уставка определения самохода ББ  мм
#define idfEM_A1UC06RDU	 773	//(A1UC06RDU) Уставка определения самохода ББ  мм
#define fEM_A1UC05RDU	 BUFFER[1884]	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A1UC05RDU	 774	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A1UL04RDU	 BUFFER[1889]	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define idfEM_A1UL04RDU	 775	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define fEM_A3UV01RDU	 BUFFER[1894]	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
#define idfEM_A3UV01RDU	 776	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
#define fEM_A3UV02RDU	 BUFFER[1899]	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
#define idfEM_A3UV02RDU	 777	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
#define fEM_A3UC06RDU	 BUFFER[1904]	//(A3UC06RDU) Уставка определения самохода ИС1  мм
#define idfEM_A3UC06RDU	 778	//(A3UC06RDU) Уставка определения самохода ИС1  мм
#define fEM_A3UC05RDU	 BUFFER[1909]	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A3UC05RDU	 779	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define fEM_A3UL04RDU	 BUFFER[1914]	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define idfEM_A3UL04RDU	 780	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define fEM_A3UP54RDU	 BUFFER[1919]	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define idfEM_A3UP54RDU	 781	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define fEM_A3UP87RDU	 BUFFER[1924]	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP87RDU	 782	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_R0UL05RDU	 BUFFER[1929]	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
#define idfEM_R0UL05RDU	 783	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
#define fEM_R0UL20RDU	 BUFFER[1934]	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
#define idfEM_R0UL20RDU	 784	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
#define fEM_B8UV04RDU	 BUFFER[1939]	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
#define idfEM_B8UV04RDU	 785	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
#define fEM_B8UC06RDU	 BUFFER[1944]	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
#define idfEM_B8UC06RDU	 786	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
#define fEM_B8UC05RDU	 BUFFER[1949]	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
#define idfEM_B8UC05RDU	 787	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
#define fEM_A2UL05RDU	 BUFFER[1954]	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define idfEM_A2UL05RDU	 788	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define fEM_A2UL03RDU	 BUFFER[1959]	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL03RDU	 789	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A2UC06RDU	 BUFFER[1964]	//(A2UC06RDU) Уставка определения самохода РБ  мм
#define idfEM_A2UC06RDU	 790	//(A2UC06RDU) Уставка определения самохода РБ  мм
#define fEM_A2UC05RDU	 BUFFER[1969]	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A2UC05RDU	 791	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A2UL04RDU	 BUFFER[1974]	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define idfEM_A2UL04RDU	 792	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define fEM_A1UL03RDU	 BUFFER[1979]	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define idfEM_A1UL03RDU	 793	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define fEM_A1UL05RDU	 BUFFER[1984]	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define idfEM_A1UL05RDU	 794	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define fEM_A3UL03RDU	 BUFFER[1989]	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define idfEM_A3UL03RDU	 795	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define fEM_A3UL05RDU	 BUFFER[1994]	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define idfEM_A3UL05RDU	 796	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define fEM_A1UC08RDU	 BUFFER[1999]	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define idfEM_A1UC08RDU	 797	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define fEM_A3UC08RDU	 BUFFER[2004]	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define idfEM_A3UC08RDU	 798	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define fEM_A1UC07RDU	 BUFFER[2009]	//(A1UC07RDU) Зона возврата при наведении ББ мм
#define idfEM_A1UC07RDU	 799	//(A1UC07RDU) Зона возврата при наведении ББ мм
#define fEM_A1UL01RDU	 BUFFER[2014]	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A1UL01RDU	 800	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A3UC07RDU	 BUFFER[2019]	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define idfEM_A3UC07RDU	 801	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define fEM_A3UL01RDU	 BUFFER[2024]	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A3UL01RDU	 802	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A2UC08RDU	 BUFFER[2029]	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define idfEM_A2UC08RDU	 803	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define fEM_A2UC07RDU	 BUFFER[2034]	//(A2UC07RDU) Зона возврата при наведении РБ  мм
#define idfEM_A2UC07RDU	 804	//(A2UC07RDU) Зона возврата при наведении РБ  мм
#define fEM_A2UL01RDU	 BUFFER[2039]	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A2UL01RDU	 805	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_B8UC01RDU	 BUFFER[2044]	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
#define idfEM_B8UC01RDU	 806	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
#define fEM_B8UL07RDU	 BUFFER[2049]	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
#define idfEM_B8UL07RDU	 807	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
#define fEM_B8UC02RDU	 BUFFER[2054]	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
#define idfEM_B8UC02RDU	 808	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
#define fEM_B8UL01RDU	 BUFFER[2059]	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_B8UL01RDU	 809	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_B8UL05RDU	 BUFFER[2064]	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
#define idfEM_B8UL05RDU	 810	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
#define fEM_B8UL03RDU	 BUFFER[2069]	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
#define idfEM_B8UL03RDU	 811	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
#define fEM_B8UL06RDU	 BUFFER[2074]	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
#define idfEM_B8UL06RDU	 812	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
#define fEM_A9UZ03RDU	 BUFFER[2079]	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
#define idfEM_A9UZ03RDU	 813	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
#define fEM_A9UZ04RDU	 BUFFER[2084]	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
#define idfEM_A9UZ04RDU	 814	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
#define fEM_A9UZ05RDU	 BUFFER[2089]	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
#define idfEM_A9UZ05RDU	 815	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
#define fEM_R4UZ04RDU	 BUFFER[2094]	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define idfEM_R4UZ04RDU	 816	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define fEM_R4UZ03RDU	 BUFFER[2099]	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define idfEM_R4UZ03RDU	 817	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define fEM_R4UZ05RDU	 BUFFER[2104]	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define idfEM_R4UZ05RDU	 818	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define fEM_A5UZ03RDU	 BUFFER[2109]	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
#define idfEM_A5UZ03RDU	 819	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
#define fEM_A5UZ04RDU	 BUFFER[2114]	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
#define idfEM_A5UZ04RDU	 820	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
#define fEM_A5UZ05RDU	 BUFFER[2119]	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
#define idfEM_A5UZ05RDU	 821	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
#define fEM_A4UZ03RDU	 BUFFER[2124]	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
#define idfEM_A4UZ03RDU	 822	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
#define fEM_A4UZ04RDU	 BUFFER[2129]	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
#define idfEM_A4UZ04RDU	 823	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
#define fEM_A4UZ05RDU	 BUFFER[2134]	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
#define idfEM_A4UZ05RDU	 824	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
#define fEM_A6UZ03RDU	 BUFFER[2139]	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
#define idfEM_A6UZ03RDU	 825	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
#define fEM_A6UZ04RDU	 BUFFER[2144]	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
#define idfEM_A6UZ04RDU	 826	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
#define fEM_A6UZ05RDU	 BUFFER[2149]	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
#define idfEM_A6UZ05RDU	 827	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
#define fEM_R1UZ03RDU	 BUFFER[2154]	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define idfEM_R1UZ03RDU	 828	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define fEM_R1UZ04RDU	 BUFFER[2159]	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define idfEM_R1UZ04RDU	 829	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define fEM_R1UZ05RDU	 BUFFER[2164]	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define idfEM_R1UZ05RDU	 830	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define fEM_R0UL04RDU	 BUFFER[2169]	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
#define idfEM_R0UL04RDU	 831	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
#define fEM_R0UL06RDU	 BUFFER[2174]	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
#define idfEM_R0UL06RDU	 832	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
#define fEM_R0UL03RDU	 BUFFER[2179]	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
#define idfEM_R0UL03RDU	 833	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
#define fEM_R0UL17RDU	 BUFFER[2184]	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
#define idfEM_R0UL17RDU	 834	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
#define fEM_R0UL19RDU	 BUFFER[2189]	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define idfEM_R0UL19RDU	 835	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define fEM_R0UL07RDU	 BUFFER[2194]	//(R0UL07RDU) Время срабатывания верхней АС II УР
#define idfEM_R0UL07RDU	 836	//(R0UL07RDU) Время срабатывания верхней АС II УР
#define fEM_R0UL18RDU	 BUFFER[2199]	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
#define idfEM_R0UL18RDU	 837	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
#define fEM_R0UL16RDU	 BUFFER[2204]	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
#define idfEM_R0UL16RDU	 838	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
#define fEM_R0UL02RDU	 BUFFER[2209]	//(R0UL02RDU) Время задержки  ИНИ
#define idfEM_R0UL02RDU	 839	//(R0UL02RDU) Время задержки  ИНИ
#define fEM_R0UN08RDU	 BUFFER[2214]	//(R0UN08RDU) 8-я заданная мощность
#define idfEM_R0UN08RDU	 840	//(R0UN08RDU) 8-я заданная мощность
#define fEM_R0UN07RDU	 BUFFER[2219]	//(R0UN07RDU) 7-я заданная мощность
#define idfEM_R0UN07RDU	 841	//(R0UN07RDU) 7-я заданная мощность
#define fEM_R0UN06RDU	 BUFFER[2224]	//(R0UN06RDU) 6-я заданная мощность
#define idfEM_R0UN06RDU	 842	//(R0UN06RDU) 6-я заданная мощность
#define fEM_R0UN05RDU	 BUFFER[2229]	//(R0UN05RDU) 5-я заданная мощность
#define idfEM_R0UN05RDU	 843	//(R0UN05RDU) 5-я заданная мощность
#define fEM_R0UN04RDU	 BUFFER[2234]	//(R0UN04RDU) 4-я заданная мощность
#define idfEM_R0UN04RDU	 844	//(R0UN04RDU) 4-я заданная мощность
#define fEM_R0UN03RDU	 BUFFER[2239]	//(R0UN03RDU) Ограничение 3 по мощности
#define idfEM_R0UN03RDU	 845	//(R0UN03RDU) Ограничение 3 по мощности
#define fEM_R0UN02RDU	 BUFFER[2244]	//(R0UN02RDU) 2-я заданная мощность
#define idfEM_R0UN02RDU	 846	//(R0UN02RDU) 2-я заданная мощность
#define fEM_R0UN01RDU	 BUFFER[2249]	//(R0UN01RDU) 1-я заданная мощность
#define idfEM_R0UN01RDU	 847	//(R0UN01RDU) 1-я заданная мощность
#define fEM_A2UC82RDU	 BUFFER[2254]	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC82RDU	 848	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define fEM_A2UC83RDU	 BUFFER[2259]	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define idfEM_A2UC83RDU	 849	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define fEM_A1UC83RDU	 BUFFER[2264]	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define idfEM_A1UC83RDU	 850	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define fEM_A2UC81RDU	 BUFFER[2269]	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC81RDU	 851	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define fEM_A1UC81RDU	 BUFFER[2274]	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC81RDU	 852	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define fEM_A1UC82RDU	 BUFFER[2279]	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC82RDU	 853	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define fEM_A2UL83RDU	 BUFFER[2284]	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL83RDU	 854	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A3UC81RDU	 BUFFER[2289]	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define idfEM_A3UC81RDU	 855	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define fEM_A3UC82RDU	 BUFFER[2294]	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define idfEM_A3UC82RDU	 856	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define fEM_R0UN80RDU	 BUFFER[2299]	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define idfEM_R0UN80RDU	 857	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define iEM_A2UV01IDU	 BUFFER[2304]	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV01IDU	 858	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define iEM_A2UV02IDU	 BUFFER[2307]	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV02IDU	 859	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define iEM_A1UV01IDU	 BUFFER[2310]	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV01IDU	 860	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define iEM_A1UV02IDU	 BUFFER[2313]	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV02IDU	 861	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define iEM_A1UV03IDU	 BUFFER[2316]	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define idiEM_A1UV03IDU	 862	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define iEM_A3UV01IDU	 BUFFER[2319]	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define idiEM_A3UV01IDU	 863	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define iEM_A3UV02IDU	 BUFFER[2322]	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define idiEM_A3UV02IDU	 864	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define lEM_R0MD01LC1	 BUFFER[2325]	//(R0MD01LC1) Ручное управление ОРР
#define idlEM_R0MD01LC1	 865	//(R0MD01LC1) Ручное управление ОРР
#define fEM_A3UC09RDU	 BUFFER[2327]	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC09RDU	 866	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define fEM_A2UC02RDU	 BUFFER[2332]	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define idfEM_A2UC02RDU	 867	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define fEM_A1UC02RDU	 BUFFER[2337]	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define idfEM_A1UC02RDU	 868	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define fEM_A3UC02RDU	 BUFFER[2342]	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define idfEM_A3UC02RDU	 869	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define fEM_R0UL21RDU	 BUFFER[2347]	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
#define idfEM_R0UL21RDU	 870	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
#define fEM_R0UN09RDU	 BUFFER[2352]	//(R0UN09RDU) Минимальный период при регулировании мощности
#define idfEM_R0UN09RDU	 871	//(R0UN09RDU) Минимальный период при регулировании мощности
#define fEM_R0UN11RDU	 BUFFER[2357]	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
#define idfEM_R0UN11RDU	 872	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
#define fEM_R0UN12RDU	 BUFFER[2362]	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
#define idfEM_R0UN12RDU	 873	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
#define fEM_R0UN13RDU	 BUFFER[2367]	//(R0UN13RDU) Минимальное изменение координаты, мм
#define idfEM_R0UN13RDU	 874	//(R0UN13RDU) Минимальное изменение координаты, мм
#define fEM_R0UN14RDU	 BUFFER[2372]	//(R0UN14RDU) Максимальная координата штока ИМ, мм
#define idfEM_R0UN14RDU	 875	//(R0UN14RDU) Максимальная координата штока ИМ, мм
#define fEM_R0UN16RDU	 BUFFER[2377]	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN16RDU	 876	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN17RDU	 BUFFER[2382]	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN17RDU	 877	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN18RDU	 BUFFER[2387]	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
#define idfEM_R0UN18RDU	 878	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
#define fEM_R0UN19RDU	 BUFFER[2392]	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define idfEM_R0UN19RDU	 879	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define fEM_R0UN70LDU	 BUFFER[2397]	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN70LDU	 880	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN71LDU	 BUFFER[2402]	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN71LDU	 881	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN72LDU	 BUFFER[2407]	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN72LDU	 882	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN73LDU	 BUFFER[2412]	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN73LDU	 883	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN74LDU	 BUFFER[2417]	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN74LDU	 884	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN75LDU	 BUFFER[2422]	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN75LDU	 885	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN80LDU	 BUFFER[2427]	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN80LDU	 886	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define fEM_R0UN81LDU	 BUFFER[2432]	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN81LDU	 887	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define fEM_R0UN82LDU	 BUFFER[2437]	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN82LDU	 888	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define fEM_R0UN83LDU	 BUFFER[2442]	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN83LDU	 889	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define fEM_R0UN84LDU	 BUFFER[2447]	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN84LDU	 890	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define fEM_R0UN85LDU	 BUFFER[2452]	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN85LDU	 891	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define fEM_R0UT20RDU	 BUFFER[2457]	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define idfEM_R0UT20RDU	 892	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define fEM_R0UN25RDU	 BUFFER[2462]	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
#define idfEM_R0UN25RDU	 893	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
#define fEM_R0UN15RDU	 BUFFER[2467]	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
#define idfEM_R0UN15RDU	 894	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
#define fEM_R0UN26RDU	 BUFFER[2472]	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
#define idfEM_R0UN26RDU	 895	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
#define fEM_R0UN27RDU	 BUFFER[2477]	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
#define idfEM_R0UN27RDU	 896	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
#define fEM_R0UN24RDU	 BUFFER[2482]	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN24RDU	 897	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
#define fEM_R0UL25RDU	 BUFFER[2487]	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define idfEM_R0UL25RDU	 898	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define bFirstEnterFlag	 BUFFER[2492]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 899	//(bFirstEnterFlag) 
#define internal2_m186_y0	 BUFFER[2494]	//(internal2_m186_y0) y0
#define idinternal2_m186_y0	 900	//(internal2_m186_y0) y0
#define internal2_m184_y0	 BUFFER[2499]	//(internal2_m184_y0) y0
#define idinternal2_m184_y0	 901	//(internal2_m184_y0) y0
#define internal2_m216_y0	 BUFFER[2504]	//(internal2_m216_y0) state
#define idinternal2_m216_y0	 902	//(internal2_m216_y0) state
#define internal2_m210_y0	 BUFFER[2506]	//(internal2_m210_y0) state
#define idinternal2_m210_y0	 903	//(internal2_m210_y0) state
#define internal2_m199_y1	 BUFFER[2508]	//(internal2_m199_y1) y1 - внутренний параметр
#define idinternal2_m199_y1	 904	//(internal2_m199_y1) y1 - внутренний параметр
#define internal2_m206_y1	 BUFFER[2510]	//(internal2_m206_y1) y1 - внутренний параметр
#define idinternal2_m206_y1	 905	//(internal2_m206_y1) y1 - внутренний параметр
#define internal2_m189_y1	 BUFFER[2512]	//(internal2_m189_y1) y1 - внутренний параметр
#define idinternal2_m189_y1	 906	//(internal2_m189_y1) y1 - внутренний параметр
#define internal2_m196_y1	 BUFFER[2514]	//(internal2_m196_y1) y1 - внутренний параметр
#define idinternal2_m196_y1	 907	//(internal2_m196_y1) y1 - внутренний параметр
#define internal2_m16_Nk0	 BUFFER[2516]	//(internal2_m16_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m16_Nk0	 908	//(internal2_m16_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m16_SetFlag	 BUFFER[2521]	//(internal2_m16_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m16_SetFlag	 909	//(internal2_m16_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m108_Nk0	 BUFFER[2523]	//(internal2_m108_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m108_Nk0	 910	//(internal2_m108_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m108_SetFlag	 BUFFER[2528]	//(internal2_m108_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m108_SetFlag	 911	//(internal2_m108_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m112_Nk0	 BUFFER[2530]	//(internal2_m112_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m112_Nk0	 912	//(internal2_m112_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m112_SetFlag	 BUFFER[2535]	//(internal2_m112_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m112_SetFlag	 913	//(internal2_m112_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m75_Nk0	 BUFFER[2537]	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m75_Nk0	 914	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m75_SetFlag	 BUFFER[2542]	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m75_SetFlag	 915	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m77_Nk0	 BUFFER[2544]	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m77_Nk0	 916	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m77_SetFlag	 BUFFER[2549]	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m77_SetFlag	 917	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m47_Nk0	 BUFFER[2551]	//(internal2_m47_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m47_Nk0	 918	//(internal2_m47_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m47_SetFlag	 BUFFER[2556]	//(internal2_m47_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m47_SetFlag	 919	//(internal2_m47_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m51_Nk0	 BUFFER[2558]	//(internal2_m51_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m51_Nk0	 920	//(internal2_m51_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m51_SetFlag	 BUFFER[2563]	//(internal2_m51_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m51_SetFlag	 921	//(internal2_m51_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m21_Nk0	 BUFFER[2565]	//(internal2_m21_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m21_Nk0	 922	//(internal2_m21_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m21_SetFlag	 BUFFER[2570]	//(internal2_m21_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m21_SetFlag	 923	//(internal2_m21_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal1_m1676_q0	 BUFFER[2572]	//(internal1_m1676_q0) q0 - внутренний параметр
#define idinternal1_m1676_q0	 924	//(internal1_m1676_q0) q0 - внутренний параметр
#define internal1_m2109_q0	 BUFFER[2574]	//(internal1_m2109_q0) q0 - внутренний параметр
#define idinternal1_m2109_q0	 925	//(internal1_m2109_q0) q0 - внутренний параметр
#define internal1_m2093_q0	 BUFFER[2576]	//(internal1_m2093_q0) q0 - внутренний параметр
#define idinternal1_m2093_q0	 926	//(internal1_m2093_q0) q0 - внутренний параметр
#define internal1_m2141_q0	 BUFFER[2578]	//(internal1_m2141_q0) q0 - внутренний параметр
#define idinternal1_m2141_q0	 927	//(internal1_m2141_q0) q0 - внутренний параметр
#define internal1_m2125_q0	 BUFFER[2580]	//(internal1_m2125_q0) q0 - внутренний параметр
#define idinternal1_m2125_q0	 928	//(internal1_m2125_q0) q0 - внутренний параметр
#define internal1_m2115_q0	 BUFFER[2582]	//(internal1_m2115_q0) q0 - внутренний параметр
#define idinternal1_m2115_q0	 929	//(internal1_m2115_q0) q0 - внутренний параметр
#define internal1_m2096_q0	 BUFFER[2584]	//(internal1_m2096_q0) q0 - внутренний параметр
#define idinternal1_m2096_q0	 930	//(internal1_m2096_q0) q0 - внутренний параметр
#define internal1_m2113_q0	 BUFFER[2586]	//(internal1_m2113_q0) q0 - внутренний параметр
#define idinternal1_m2113_q0	 931	//(internal1_m2113_q0) q0 - внутренний параметр
#define internal1_m2094_q0	 BUFFER[2588]	//(internal1_m2094_q0) q0 - внутренний параметр
#define idinternal1_m2094_q0	 932	//(internal1_m2094_q0) q0 - внутренний параметр
#define internal1_m2092_q0	 BUFFER[2590]	//(internal1_m2092_q0) q0 - внутренний параметр
#define idinternal1_m2092_q0	 933	//(internal1_m2092_q0) q0 - внутренний параметр
#define internal1_m2091_q0	 BUFFER[2592]	//(internal1_m2091_q0) q0 - внутренний параметр
#define idinternal1_m2091_q0	 934	//(internal1_m2091_q0) q0 - внутренний параметр
#define internal1_m2105_q0	 BUFFER[2594]	//(internal1_m2105_q0) q0 - внутренний параметр
#define idinternal1_m2105_q0	 935	//(internal1_m2105_q0) q0 - внутренний параметр
#define internal1_m2103_q0	 BUFFER[2596]	//(internal1_m2103_q0) q0 - внутренний параметр
#define idinternal1_m2103_q0	 936	//(internal1_m2103_q0) q0 - внутренний параметр
#define internal1_m2111_q0	 BUFFER[2598]	//(internal1_m2111_q0) q0 - внутренний параметр
#define idinternal1_m2111_q0	 937	//(internal1_m2111_q0) q0 - внутренний параметр
#define internal1_m2107_q0	 BUFFER[2600]	//(internal1_m2107_q0) q0 - внутренний параметр
#define idinternal1_m2107_q0	 938	//(internal1_m2107_q0) q0 - внутренний параметр
#define internal1_m2147_q0	 BUFFER[2602]	//(internal1_m2147_q0) q0 - внутренний параметр
#define idinternal1_m2147_q0	 939	//(internal1_m2147_q0) q0 - внутренний параметр
#define internal1_m2128_q0	 BUFFER[2604]	//(internal1_m2128_q0) q0 - внутренний параметр
#define idinternal1_m2128_q0	 940	//(internal1_m2128_q0) q0 - внутренний параметр
#define internal1_m2145_q0	 BUFFER[2606]	//(internal1_m2145_q0) q0 - внутренний параметр
#define idinternal1_m2145_q0	 941	//(internal1_m2145_q0) q0 - внутренний параметр
#define internal1_m2127_q0	 BUFFER[2608]	//(internal1_m2127_q0) q0 - внутренний параметр
#define idinternal1_m2127_q0	 942	//(internal1_m2127_q0) q0 - внутренний параметр
#define internal1_m2124_q0	 BUFFER[2610]	//(internal1_m2124_q0) q0 - внутренний параметр
#define idinternal1_m2124_q0	 943	//(internal1_m2124_q0) q0 - внутренний параметр
#define internal1_m2123_q0	 BUFFER[2612]	//(internal1_m2123_q0) q0 - внутренний параметр
#define idinternal1_m2123_q0	 944	//(internal1_m2123_q0) q0 - внутренний параметр
#define internal1_m2137_q0	 BUFFER[2614]	//(internal1_m2137_q0) q0 - внутренний параметр
#define idinternal1_m2137_q0	 945	//(internal1_m2137_q0) q0 - внутренний параметр
#define internal1_m2135_q0	 BUFFER[2616]	//(internal1_m2135_q0) q0 - внутренний параметр
#define idinternal1_m2135_q0	 946	//(internal1_m2135_q0) q0 - внутренний параметр
#define internal1_m2012_tx	 BUFFER[2618]	//(internal1_m2012_tx) tx - внутренний параметр
#define idinternal1_m2012_tx	 947	//(internal1_m2012_tx) tx - внутренний параметр
#define internal1_m1991_tx	 BUFFER[2623]	//(internal1_m1991_tx) tx - внутренний параметр
#define idinternal1_m1991_tx	 948	//(internal1_m1991_tx) tx - внутренний параметр
#define internal1_m1698_Pv0	 BUFFER[2628]	//(internal1_m1698_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1698_Pv0	 949	//(internal1_m1698_Pv0)  - Пер. выключатель механизма
#define internal1_m1698_Zv0	 BUFFER[2630]	//(internal1_m1698_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1698_Zv0	 950	//(internal1_m1698_Zv0)  - Зад. выключатель механизма
#define internal1_m1698_MyFirstEnterFlag	 BUFFER[2632]	//(internal1_m1698_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1698_MyFirstEnterFlag	 951	//(internal1_m1698_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m1697_Pv0	 BUFFER[2634]	//(internal1_m1697_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1697_Pv0	 952	//(internal1_m1697_Pv0)  - Пер. выключатель механизма
#define internal1_m1697_Zv0	 BUFFER[2636]	//(internal1_m1697_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1697_Zv0	 953	//(internal1_m1697_Zv0)  - Зад. выключатель механизма
#define internal1_m1697_MyFirstEnterFlag	 BUFFER[2638]	//(internal1_m1697_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1697_MyFirstEnterFlag	 954	//(internal1_m1697_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m2165_tx	 BUFFER[2640]	//(internal1_m2165_tx) tx - время накопленное сек
#define idinternal1_m2165_tx	 955	//(internal1_m2165_tx) tx - время накопленное сек
#define internal1_m2165_y0	 BUFFER[2645]	//(internal1_m2165_y0) y0
#define idinternal1_m2165_y0	 956	//(internal1_m2165_y0) y0
#define internal1_m2170_tx	 BUFFER[2646]	//(internal1_m2170_tx) tx - время накопленное сек
#define idinternal1_m2170_tx	 957	//(internal1_m2170_tx) tx - время накопленное сек
#define internal1_m2170_y0	 BUFFER[2651]	//(internal1_m2170_y0) y0
#define idinternal1_m2170_y0	 958	//(internal1_m2170_y0) y0
#define internal1_m2169_tx	 BUFFER[2652]	//(internal1_m2169_tx) tx - время накопленное сек
#define idinternal1_m2169_tx	 959	//(internal1_m2169_tx) tx - время накопленное сек
#define internal1_m2169_y0	 BUFFER[2657]	//(internal1_m2169_y0) y0
#define idinternal1_m2169_y0	 960	//(internal1_m2169_y0) y0
#define internal1_m2206_tx	 BUFFER[2658]	//(internal1_m2206_tx) tx - внутренний параметр
#define idinternal1_m2206_tx	 961	//(internal1_m2206_tx) tx - внутренний параметр
#define internal1_m2204_tx	 BUFFER[2663]	//(internal1_m2204_tx) tx - время накопленное сек
#define idinternal1_m2204_tx	 962	//(internal1_m2204_tx) tx - время накопленное сек
#define internal1_m2204_y0	 BUFFER[2668]	//(internal1_m2204_y0) y0
#define idinternal1_m2204_y0	 963	//(internal1_m2204_y0) y0
#define internal1_m2209_q0	 BUFFER[2669]	//(internal1_m2209_q0) q0 - внутренний параметр
#define idinternal1_m2209_q0	 964	//(internal1_m2209_q0) q0 - внутренний параметр
#define internal1_m2176_q0	 BUFFER[2671]	//(internal1_m2176_q0) q0 - внутренний параметр
#define idinternal1_m2176_q0	 965	//(internal1_m2176_q0) q0 - внутренний параметр
#define internal1_m2184_tx	 BUFFER[2673]	//(internal1_m2184_tx) tx - внутренний параметр
#define idinternal1_m2184_tx	 966	//(internal1_m2184_tx) tx - внутренний параметр
#define internal1_m2182_q0	 BUFFER[2678]	//(internal1_m2182_q0) q0 - внутренний параметр
#define idinternal1_m2182_q0	 967	//(internal1_m2182_q0) q0 - внутренний параметр
#define internal1_m2006_tx	 BUFFER[2680]	//(internal1_m2006_tx) tx - время накопленное сек
#define idinternal1_m2006_tx	 968	//(internal1_m2006_tx) tx - время накопленное сек
#define internal1_m2006_y0	 BUFFER[2685]	//(internal1_m2006_y0) y0
#define idinternal1_m2006_y0	 969	//(internal1_m2006_y0) y0
#define internal1_m1998_tx	 BUFFER[2686]	//(internal1_m1998_tx) tx - время накопленное сек
#define idinternal1_m1998_tx	 970	//(internal1_m1998_tx) tx - время накопленное сек
#define internal1_m1998_y0	 BUFFER[2691]	//(internal1_m1998_y0) y0
#define idinternal1_m1998_y0	 971	//(internal1_m1998_y0) y0
#define internal1_m1686_q0	 BUFFER[2692]	//(internal1_m1686_q0) q0 - внутренний параметр
#define idinternal1_m1686_q0	 972	//(internal1_m1686_q0) q0 - внутренний параметр
#define internal1_m1691_q0	 BUFFER[2694]	//(internal1_m1691_q0) q0 - внутренний параметр
#define idinternal1_m1691_q0	 973	//(internal1_m1691_q0) q0 - внутренний параметр
#define internal1_m1683_q0	 BUFFER[2696]	//(internal1_m1683_q0) q0 - внутренний параметр
#define idinternal1_m1683_q0	 974	//(internal1_m1683_q0) q0 - внутренний параметр
#define internal1_m1725_q0	 BUFFER[2698]	//(internal1_m1725_q0) q0 - внутренний параметр
#define idinternal1_m1725_q0	 975	//(internal1_m1725_q0) q0 - внутренний параметр
#define internal1_m740_tx	 BUFFER[2700]	//(internal1_m740_tx) tx - время накопленное сек
#define idinternal1_m740_tx	 976	//(internal1_m740_tx) tx - время накопленное сек
#define internal1_m740_y0	 BUFFER[2705]	//(internal1_m740_y0) y0
#define idinternal1_m740_y0	 977	//(internal1_m740_y0) y0
#define internal1_m2002_tx	 BUFFER[2706]	//(internal1_m2002_tx) tx - внутренний параметр
#define idinternal1_m2002_tx	 978	//(internal1_m2002_tx) tx - внутренний параметр
#define internal1_m2005_q0	 BUFFER[2711]	//(internal1_m2005_q0) q0 - внутренний параметр
#define idinternal1_m2005_q0	 979	//(internal1_m2005_q0) q0 - внутренний параметр
#define internal1_m1997_q0	 BUFFER[2713]	//(internal1_m1997_q0) q0 - внутренний параметр
#define idinternal1_m1997_q0	 980	//(internal1_m1997_q0) q0 - внутренний параметр
#define internal1_m1967_tx	 BUFFER[2715]	//(internal1_m1967_tx) tx - внутренний параметр
#define idinternal1_m1967_tx	 981	//(internal1_m1967_tx) tx - внутренний параметр
#define internal1_m1978_tx	 BUFFER[2720]	//(internal1_m1978_tx) tx - внутренний параметр
#define idinternal1_m1978_tx	 982	//(internal1_m1978_tx) tx - внутренний параметр
#define internal1_m1964_tx	 BUFFER[2725]	//(internal1_m1964_tx) tx - внутренний параметр
#define idinternal1_m1964_tx	 983	//(internal1_m1964_tx) tx - внутренний параметр
#define internal1_m1970_q0	 BUFFER[2730]	//(internal1_m1970_q0) q0 - внутренний параметр
#define idinternal1_m1970_q0	 984	//(internal1_m1970_q0) q0 - внутренний параметр
#define internal1_m1982_q0	 BUFFER[2732]	//(internal1_m1982_q0) q0 - внутренний параметр
#define idinternal1_m1982_q0	 985	//(internal1_m1982_q0) q0 - внутренний параметр
#define internal1_m1940_tx	 BUFFER[2734]	//(internal1_m1940_tx) tx - внутренний параметр
#define idinternal1_m1940_tx	 986	//(internal1_m1940_tx) tx - внутренний параметр
#define internal1_m51_tx	 BUFFER[2739]	//(internal1_m51_tx) tx - внутренний параметр
#define idinternal1_m51_tx	 987	//(internal1_m51_tx) tx - внутренний параметр
#define internal1_m337_tx	 BUFFER[2744]	//(internal1_m337_tx) tx - внутренний параметр
#define idinternal1_m337_tx	 988	//(internal1_m337_tx) tx - внутренний параметр
#define internal1_m292_tx	 BUFFER[2749]	//(internal1_m292_tx) tx - внутренний параметр
#define idinternal1_m292_tx	 989	//(internal1_m292_tx) tx - внутренний параметр
#define internal1_m741_tx	 BUFFER[2754]	//(internal1_m741_tx) tx - внутренний параметр
#define idinternal1_m741_tx	 990	//(internal1_m741_tx) tx - внутренний параметр
#define internal1_m1406_tx	 BUFFER[2759]	//(internal1_m1406_tx) tx - внутренний параметр
#define idinternal1_m1406_tx	 991	//(internal1_m1406_tx) tx - внутренний параметр
#define internal1_m113_tx	 BUFFER[2764]	//(internal1_m113_tx) tx - внутренний параметр
#define idinternal1_m113_tx	 992	//(internal1_m113_tx) tx - внутренний параметр
#define internal1_m115_tx	 BUFFER[2769]	//(internal1_m115_tx) tx - внутренний параметр
#define idinternal1_m115_tx	 993	//(internal1_m115_tx) tx - внутренний параметр
#define internal1_m120_tx	 BUFFER[2774]	//(internal1_m120_tx) tx - внутренний параметр
#define idinternal1_m120_tx	 994	//(internal1_m120_tx) tx - внутренний параметр
#define internal1_m21_tx	 BUFFER[2779]	//(internal1_m21_tx) tx - внутренний параметр
#define idinternal1_m21_tx	 995	//(internal1_m21_tx) tx - внутренний параметр
#define internal1_m13_tx	 BUFFER[2784]	//(internal1_m13_tx) tx - внутренний параметр
#define idinternal1_m13_tx	 996	//(internal1_m13_tx) tx - внутренний параметр
#define internal1_m1949_tx	 BUFFER[2789]	//(internal1_m1949_tx) tx - внутренний параметр
#define idinternal1_m1949_tx	 997	//(internal1_m1949_tx) tx - внутренний параметр
#define internal1_m1937_tx	 BUFFER[2794]	//(internal1_m1937_tx) tx - внутренний параметр
#define idinternal1_m1937_tx	 998	//(internal1_m1937_tx) tx - внутренний параметр
#define internal1_m2045_tx	 BUFFER[2799]	//(internal1_m2045_tx) tx - внутренний параметр
#define idinternal1_m2045_tx	 999	//(internal1_m2045_tx) tx - внутренний параметр
#define internal1_m2049_tx	 BUFFER[2804]	//(internal1_m2049_tx) tx - внутренний параметр
#define idinternal1_m2049_tx	 1000	//(internal1_m2049_tx) tx - внутренний параметр
#define internal1_m1862_tx	 BUFFER[2809]	//(internal1_m1862_tx) tx - внутренний параметр
#define idinternal1_m1862_tx	 1001	//(internal1_m1862_tx) tx - внутренний параметр
#define internal1_m77_tx	 BUFFER[2814]	//(internal1_m77_tx) tx - внутренний параметр
#define idinternal1_m77_tx	 1002	//(internal1_m77_tx) tx - внутренний параметр
#define internal1_m306_tx	 BUFFER[2819]	//(internal1_m306_tx) tx - время накопленное сек
#define idinternal1_m306_tx	 1003	//(internal1_m306_tx) tx - время накопленное сек
#define internal1_m306_y0	 BUFFER[2824]	//(internal1_m306_y0) y0
#define idinternal1_m306_y0	 1004	//(internal1_m306_y0) y0
#define internal1_m1856_tx	 BUFFER[2825]	//(internal1_m1856_tx) tx - время накопленное сек
#define idinternal1_m1856_tx	 1005	//(internal1_m1856_tx) tx - время накопленное сек
#define internal1_m1856_y0	 BUFFER[2830]	//(internal1_m1856_y0) y0
#define idinternal1_m1856_y0	 1006	//(internal1_m1856_y0) y0
#define internal1_m1854_tx	 BUFFER[2831]	//(internal1_m1854_tx) tx - время накопленное сек
#define idinternal1_m1854_tx	 1007	//(internal1_m1854_tx) tx - время накопленное сек
#define internal1_m1854_y0	 BUFFER[2836]	//(internal1_m1854_y0) y0
#define idinternal1_m1854_y0	 1008	//(internal1_m1854_y0) y0
#define internal1_m1843_tx	 BUFFER[2837]	//(internal1_m1843_tx) tx - время накопленное сек
#define idinternal1_m1843_tx	 1009	//(internal1_m1843_tx) tx - время накопленное сек
#define internal1_m1843_y0	 BUFFER[2842]	//(internal1_m1843_y0) y0
#define idinternal1_m1843_y0	 1010	//(internal1_m1843_y0) y0
#define internal1_m1863_q0	 BUFFER[2843]	//(internal1_m1863_q0) q0 - внутренний параметр
#define idinternal1_m1863_q0	 1011	//(internal1_m1863_q0) q0 - внутренний параметр
#define internal1_m1426_q0	 BUFFER[2848]	//(internal1_m1426_q0) q0 - внутренний параметр
#define idinternal1_m1426_q0	 1012	//(internal1_m1426_q0) q0 - внутренний параметр
#define internal1_m1464_q0	 BUFFER[2853]	//(internal1_m1464_q0) q0 - внутренний параметр
#define idinternal1_m1464_q0	 1013	//(internal1_m1464_q0) q0 - внутренний параметр
#define internal1_m1467_q0	 BUFFER[2858]	//(internal1_m1467_q0) q0 - внутренний параметр
#define idinternal1_m1467_q0	 1014	//(internal1_m1467_q0) q0 - внутренний параметр
#define internal1_m1902_q0	 BUFFER[2863]	//(internal1_m1902_q0) q0 - внутренний параметр
#define idinternal1_m1902_q0	 1015	//(internal1_m1902_q0) q0 - внутренний параметр
#define internal1_m1879_tx	 BUFFER[2868]	//(internal1_m1879_tx) tx - время накопленное сек
#define idinternal1_m1879_tx	 1016	//(internal1_m1879_tx) tx - время накопленное сек
#define internal1_m1879_y0	 BUFFER[2873]	//(internal1_m1879_y0) y0
#define idinternal1_m1879_y0	 1017	//(internal1_m1879_y0) y0
#define internal1_m1895_tx	 BUFFER[2874]	//(internal1_m1895_tx) tx - время накопленное сек
#define idinternal1_m1895_tx	 1018	//(internal1_m1895_tx) tx - время накопленное сек
#define internal1_m1895_y0	 BUFFER[2879]	//(internal1_m1895_y0) y0
#define idinternal1_m1895_y0	 1019	//(internal1_m1895_y0) y0
#define internal1_m1892_tx	 BUFFER[2880]	//(internal1_m1892_tx) tx - время накопленное сек
#define idinternal1_m1892_tx	 1020	//(internal1_m1892_tx) tx - время накопленное сек
#define internal1_m1892_y0	 BUFFER[2885]	//(internal1_m1892_y0) y0
#define idinternal1_m1892_y0	 1021	//(internal1_m1892_y0) y0
#define internal1_m2026_tx	 BUFFER[2886]	//(internal1_m2026_tx) tx - время накопленное сек
#define idinternal1_m2026_tx	 1022	//(internal1_m2026_tx) tx - время накопленное сек
#define internal1_m2026_y0	 BUFFER[2891]	//(internal1_m2026_y0) y0
#define idinternal1_m2026_y0	 1023	//(internal1_m2026_y0) y0
#define internal1_m2039_tx	 BUFFER[2892]	//(internal1_m2039_tx) tx - время накопленное сек
#define idinternal1_m2039_tx	 1024	//(internal1_m2039_tx) tx - время накопленное сек
#define internal1_m2039_y0	 BUFFER[2897]	//(internal1_m2039_y0) y0
#define idinternal1_m2039_y0	 1025	//(internal1_m2039_y0) y0
#define internal1_m1793_tx	 BUFFER[2898]	//(internal1_m1793_tx) tx - время накопленное сек
#define idinternal1_m1793_tx	 1026	//(internal1_m1793_tx) tx - время накопленное сек
#define internal1_m1793_y0	 BUFFER[2903]	//(internal1_m1793_y0) y0
#define idinternal1_m1793_y0	 1027	//(internal1_m1793_y0) y0
#define internal1_m1792_tx	 BUFFER[2904]	//(internal1_m1792_tx) tx - время накопленное сек
#define idinternal1_m1792_tx	 1028	//(internal1_m1792_tx) tx - время накопленное сек
#define internal1_m1792_y0	 BUFFER[2909]	//(internal1_m1792_y0) y0
#define idinternal1_m1792_y0	 1029	//(internal1_m1792_y0) y0
#define internal1_m1791_tx	 BUFFER[2910]	//(internal1_m1791_tx) tx - время накопленное сек
#define idinternal1_m1791_tx	 1030	//(internal1_m1791_tx) tx - время накопленное сек
#define internal1_m1791_y0	 BUFFER[2915]	//(internal1_m1791_y0) y0
#define idinternal1_m1791_y0	 1031	//(internal1_m1791_y0) y0
#define internal1_m1790_tx	 BUFFER[2916]	//(internal1_m1790_tx) tx - время накопленное сек
#define idinternal1_m1790_tx	 1032	//(internal1_m1790_tx) tx - время накопленное сек
#define internal1_m1790_y0	 BUFFER[2921]	//(internal1_m1790_y0) y0
#define idinternal1_m1790_y0	 1033	//(internal1_m1790_y0) y0
#define internal1_m1478_tx	 BUFFER[2922]	//(internal1_m1478_tx) tx - время накопленное сек
#define idinternal1_m1478_tx	 1034	//(internal1_m1478_tx) tx - время накопленное сек
#define internal1_m1478_y0	 BUFFER[2927]	//(internal1_m1478_y0) y0
#define idinternal1_m1478_y0	 1035	//(internal1_m1478_y0) y0
#define internal1_m1472_tx	 BUFFER[2928]	//(internal1_m1472_tx) tx - время накопленное сек
#define idinternal1_m1472_tx	 1036	//(internal1_m1472_tx) tx - время накопленное сек
#define internal1_m1472_y0	 BUFFER[2933]	//(internal1_m1472_y0) y0
#define idinternal1_m1472_y0	 1037	//(internal1_m1472_y0) y0
#define internal1_m1422_tx	 BUFFER[2934]	//(internal1_m1422_tx) tx - время накопленное сек
#define idinternal1_m1422_tx	 1038	//(internal1_m1422_tx) tx - время накопленное сек
#define internal1_m1422_y0	 BUFFER[2939]	//(internal1_m1422_y0) y0
#define idinternal1_m1422_y0	 1039	//(internal1_m1422_y0) y0
#define internal1_m823_tx	 BUFFER[2940]	//(internal1_m823_tx) tx - время накопленное сек
#define idinternal1_m823_tx	 1040	//(internal1_m823_tx) tx - время накопленное сек
#define internal1_m823_y0	 BUFFER[2945]	//(internal1_m823_y0) y0
#define idinternal1_m823_y0	 1041	//(internal1_m823_y0) y0
#define internal1_m821_tx	 BUFFER[2946]	//(internal1_m821_tx) tx - время накопленное сек
#define idinternal1_m821_tx	 1042	//(internal1_m821_tx) tx - время накопленное сек
#define internal1_m821_y0	 BUFFER[2951]	//(internal1_m821_y0) y0
#define idinternal1_m821_y0	 1043	//(internal1_m821_y0) y0
#define internal1_m828_tx	 BUFFER[2952]	//(internal1_m828_tx) tx - время накопленное сек
#define idinternal1_m828_tx	 1044	//(internal1_m828_tx) tx - время накопленное сек
#define internal1_m828_y0	 BUFFER[2957]	//(internal1_m828_y0) y0
#define idinternal1_m828_y0	 1045	//(internal1_m828_y0) y0
#define internal1_m187_tx	 BUFFER[2958]	//(internal1_m187_tx) tx - время накопленное сек
#define idinternal1_m187_tx	 1046	//(internal1_m187_tx) tx - время накопленное сек
#define internal1_m187_y0	 BUFFER[2963]	//(internal1_m187_y0) y0
#define idinternal1_m187_y0	 1047	//(internal1_m187_y0) y0
#define internal1_m192_tx	 BUFFER[2964]	//(internal1_m192_tx) tx - время накопленное сек
#define idinternal1_m192_tx	 1048	//(internal1_m192_tx) tx - время накопленное сек
#define internal1_m192_y0	 BUFFER[2969]	//(internal1_m192_y0) y0
#define idinternal1_m192_y0	 1049	//(internal1_m192_y0) y0
#define internal1_m198_tx	 BUFFER[2970]	//(internal1_m198_tx) tx - время накопленное сек
#define idinternal1_m198_tx	 1050	//(internal1_m198_tx) tx - время накопленное сек
#define internal1_m198_y0	 BUFFER[2975]	//(internal1_m198_y0) y0
#define idinternal1_m198_y0	 1051	//(internal1_m198_y0) y0
#define internal1_m517_tx	 BUFFER[2976]	//(internal1_m517_tx) tx - время накопленное сек
#define idinternal1_m517_tx	 1052	//(internal1_m517_tx) tx - время накопленное сек
#define internal1_m517_y0	 BUFFER[2981]	//(internal1_m517_y0) y0
#define idinternal1_m517_y0	 1053	//(internal1_m517_y0) y0
#define internal1_m2077_tx	 BUFFER[2982]	//(internal1_m2077_tx) tx - внутренний параметр
#define idinternal1_m2077_tx	 1054	//(internal1_m2077_tx) tx - внутренний параметр
#define internal1_m1166_tx	 BUFFER[2987]	//(internal1_m1166_tx) tx - внутренний параметр
#define idinternal1_m1166_tx	 1055	//(internal1_m1166_tx) tx - внутренний параметр
#define internal1_m1592_tx	 BUFFER[2992]	//(internal1_m1592_tx) tx - время накопленное сек
#define idinternal1_m1592_tx	 1056	//(internal1_m1592_tx) tx - время накопленное сек
#define internal1_m1592_y0	 BUFFER[2997]	//(internal1_m1592_y0) y0
#define idinternal1_m1592_y0	 1057	//(internal1_m1592_y0) y0
#define internal1_m1132_tx	 BUFFER[2998]	//(internal1_m1132_tx) tx - время накопленное сек
#define idinternal1_m1132_tx	 1058	//(internal1_m1132_tx) tx - время накопленное сек
#define internal1_m1132_y0	 BUFFER[3003]	//(internal1_m1132_y0) y0
#define idinternal1_m1132_y0	 1059	//(internal1_m1132_y0) y0
#define internal1_m1318_tx	 BUFFER[3004]	//(internal1_m1318_tx) tx - время накопленное сек
#define idinternal1_m1318_tx	 1060	//(internal1_m1318_tx) tx - время накопленное сек
#define internal1_m1318_y0	 BUFFER[3009]	//(internal1_m1318_y0) y0
#define idinternal1_m1318_y0	 1061	//(internal1_m1318_y0) y0
#define internal1_m921_tx	 BUFFER[3010]	//(internal1_m921_tx) tx - время накопленное сек
#define idinternal1_m921_tx	 1062	//(internal1_m921_tx) tx - время накопленное сек
#define internal1_m921_y0	 BUFFER[3015]	//(internal1_m921_y0) y0
#define idinternal1_m921_y0	 1063	//(internal1_m921_y0) y0
#define internal1_m1227_tx	 BUFFER[3016]	//(internal1_m1227_tx) tx - время накопленное сек
#define idinternal1_m1227_tx	 1064	//(internal1_m1227_tx) tx - время накопленное сек
#define internal1_m1227_y0	 BUFFER[3021]	//(internal1_m1227_y0) y0
#define idinternal1_m1227_y0	 1065	//(internal1_m1227_y0) y0
#define internal1_m1073_q0	 BUFFER[3022]	//(internal1_m1073_q0) q0 - внутренний параметр
#define idinternal1_m1073_q0	 1066	//(internal1_m1073_q0) q0 - внутренний параметр
#define internal1_m1071_q0	 BUFFER[3024]	//(internal1_m1071_q0) q0 - внутренний параметр
#define idinternal1_m1071_q0	 1067	//(internal1_m1071_q0) q0 - внутренний параметр
#define internal1_m1070_q0	 BUFFER[3026]	//(internal1_m1070_q0) q0 - внутренний параметр
#define idinternal1_m1070_q0	 1068	//(internal1_m1070_q0) q0 - внутренний параметр
#define internal1_m1068_q0	 BUFFER[3028]	//(internal1_m1068_q0) q0 - внутренний параметр
#define idinternal1_m1068_q0	 1069	//(internal1_m1068_q0) q0 - внутренний параметр
#define internal1_m1067_q0	 BUFFER[3030]	//(internal1_m1067_q0) q0 - внутренний параметр
#define idinternal1_m1067_q0	 1070	//(internal1_m1067_q0) q0 - внутренний параметр
#define internal1_m1065_q0	 BUFFER[3032]	//(internal1_m1065_q0) q0 - внутренний параметр
#define idinternal1_m1065_q0	 1071	//(internal1_m1065_q0) q0 - внутренний параметр
#define internal1_m1064_q0	 BUFFER[3034]	//(internal1_m1064_q0) q0 - внутренний параметр
#define idinternal1_m1064_q0	 1072	//(internal1_m1064_q0) q0 - внутренний параметр
#define internal1_m1062_q0	 BUFFER[3036]	//(internal1_m1062_q0) q0 - внутренний параметр
#define idinternal1_m1062_q0	 1073	//(internal1_m1062_q0) q0 - внутренний параметр
#define internal1_m1061_q0	 BUFFER[3038]	//(internal1_m1061_q0) q0 - внутренний параметр
#define idinternal1_m1061_q0	 1074	//(internal1_m1061_q0) q0 - внутренний параметр
#define internal1_m52_x0	 BUFFER[3040]	//(internal1_m52_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m52_x0	 1075	//(internal1_m52_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m981_q0	 BUFFER[3042]	//(internal1_m981_q0) q0 - внутренний параметр
#define idinternal1_m981_q0	 1076	//(internal1_m981_q0) q0 - внутренний параметр
#define internal1_m1415_x0	 BUFFER[3044]	//(internal1_m1415_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1415_x0	 1077	//(internal1_m1415_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1459_x0	 BUFFER[3046]	//(internal1_m1459_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1459_x0	 1078	//(internal1_m1459_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1455_x0	 BUFFER[3048]	//(internal1_m1455_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1455_x0	 1079	//(internal1_m1455_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1871_x0	 BUFFER[3050]	//(internal1_m1871_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1871_x0	 1080	//(internal1_m1871_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1836_x0	 BUFFER[3052]	//(internal1_m1836_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1836_x0	 1081	//(internal1_m1836_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1020_q0	 BUFFER[3054]	//(internal1_m1020_q0) q0 - внутренний параметр
#define idinternal1_m1020_q0	 1082	//(internal1_m1020_q0) q0 - внутренний параметр
#define internal1_m1032_q0	 BUFFER[3056]	//(internal1_m1032_q0) q0 - внутренний параметр
#define idinternal1_m1032_q0	 1083	//(internal1_m1032_q0) q0 - внутренний параметр
#define internal1_m1044_q0	 BUFFER[3058]	//(internal1_m1044_q0) q0 - внутренний параметр
#define idinternal1_m1044_q0	 1084	//(internal1_m1044_q0) q0 - внутренний параметр
#define internal1_m1054_q0	 BUFFER[3060]	//(internal1_m1054_q0) q0 - внутренний параметр
#define idinternal1_m1054_q0	 1085	//(internal1_m1054_q0) q0 - внутренний параметр
#define internal1_m1031_q0	 BUFFER[3062]	//(internal1_m1031_q0) q0 - внутренний параметр
#define idinternal1_m1031_q0	 1086	//(internal1_m1031_q0) q0 - внутренний параметр
#define internal1_m1046_q0	 BUFFER[3064]	//(internal1_m1046_q0) q0 - внутренний параметр
#define idinternal1_m1046_q0	 1087	//(internal1_m1046_q0) q0 - внутренний параметр
#define internal1_m1929_q0	 BUFFER[3066]	//(internal1_m1929_q0) q0 - внутренний параметр
#define idinternal1_m1929_q0	 1088	//(internal1_m1929_q0) q0 - внутренний параметр
#define internal1_m1928_q0	 BUFFER[3068]	//(internal1_m1928_q0) q0 - внутренний параметр
#define idinternal1_m1928_q0	 1089	//(internal1_m1928_q0) q0 - внутренний параметр
#define internal1_m325_Step	 BUFFER[3070]	//(internal1_m325_Step)  - текущий шаг программы
#define idinternal1_m325_Step	 1090	//(internal1_m325_Step)  - текущий шаг программы
#define internal1_m325_rz	 BUFFER[3073]	//(internal1_m325_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m325_rz	 1091	//(internal1_m325_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m325_TimS	 BUFFER[3083]	//(internal1_m325_TimS) Время от старта программы
#define idinternal1_m325_TimS	 1092	//(internal1_m325_TimS) Время от старта программы
#define internal1_m325_FinPr0	 BUFFER[3088]	//(internal1_m325_FinPr0) FinPr - конец программы
#define idinternal1_m325_FinPr0	 1093	//(internal1_m325_FinPr0) FinPr - конец программы
#define internal1_m325_ErrPr0	 BUFFER[3090]	//(internal1_m325_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m325_ErrPr0	 1094	//(internal1_m325_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m325_sbINI0	 BUFFER[3092]	//(internal1_m325_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m325_sbINI0	 1095	//(internal1_m325_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m325_sbVuIS0	 BUFFER[3094]	//(internal1_m325_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m325_sbVuIS0	 1096	//(internal1_m325_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m325_sb2UR0	 BUFFER[3096]	//(internal1_m325_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m325_sb2UR0	 1097	//(internal1_m325_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m325_sbNupIS0	 BUFFER[3098]	//(internal1_m325_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m325_sbNupIS0	 1098	//(internal1_m325_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m325_sbVuRB0	 BUFFER[3100]	//(internal1_m325_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m325_sbVuRB0	 1099	//(internal1_m325_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m325_MyFirstEnterFlag	 BUFFER[3102]	//(internal1_m325_MyFirstEnterFlag)  
#define idinternal1_m325_MyFirstEnterFlag	 1100	//(internal1_m325_MyFirstEnterFlag)  
#define internal1_m333_x0	 BUFFER[3104]	//(internal1_m333_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m333_x0	 1101	//(internal1_m333_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m291_TimS	 BUFFER[3109]	//(internal1_m291_TimS) Время старта
#define idinternal1_m291_TimS	 1102	//(internal1_m291_TimS) Время старта
#define internal1_m268_Step	 BUFFER[3114]	//(internal1_m268_Step)  - текущий шаг программы
#define idinternal1_m268_Step	 1103	//(internal1_m268_Step)  - текущий шаг программы
#define internal1_m268_rz	 BUFFER[3117]	//(internal1_m268_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m268_rz	 1104	//(internal1_m268_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m268_TimS	 BUFFER[3127]	//(internal1_m268_TimS) Время от старта программы
#define idinternal1_m268_TimS	 1105	//(internal1_m268_TimS) Время от старта программы
#define internal1_m268_FinPr0	 BUFFER[3132]	//(internal1_m268_FinPr0) FinPr - конец программы
#define idinternal1_m268_FinPr0	 1106	//(internal1_m268_FinPr0) FinPr - конец программы
#define internal1_m268_ErrPr0	 BUFFER[3134]	//(internal1_m268_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m268_ErrPr0	 1107	//(internal1_m268_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m268_sbINI0	 BUFFER[3136]	//(internal1_m268_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m268_sbINI0	 1108	//(internal1_m268_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m268_sbVuIS0	 BUFFER[3138]	//(internal1_m268_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m268_sbVuIS0	 1109	//(internal1_m268_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m268_sb2UR0	 BUFFER[3140]	//(internal1_m268_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m268_sb2UR0	 1110	//(internal1_m268_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m268_sbNupIS0	 BUFFER[3142]	//(internal1_m268_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m268_sbNupIS0	 1111	//(internal1_m268_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m268_sbVuRB0	 BUFFER[3144]	//(internal1_m268_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m268_sbVuRB0	 1112	//(internal1_m268_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m268_MyFirstEnterFlag	 BUFFER[3146]	//(internal1_m268_MyFirstEnterFlag)  
#define idinternal1_m268_MyFirstEnterFlag	 1113	//(internal1_m268_MyFirstEnterFlag)  
#define internal1_m1389_q0	 BUFFER[3148]	//(internal1_m1389_q0) q0 - внутренний параметр
#define idinternal1_m1389_q0	 1114	//(internal1_m1389_q0) q0 - внутренний параметр
#define internal1_m1390_Step	 BUFFER[3150]	//(internal1_m1390_Step)  - текущий шаг программы
#define idinternal1_m1390_Step	 1115	//(internal1_m1390_Step)  - текущий шаг программы
#define internal1_m1390_rz	 BUFFER[3153]	//(internal1_m1390_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m1390_rz	 1116	//(internal1_m1390_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m1390_TimS	 BUFFER[3159]	//(internal1_m1390_TimS) Время от старта программы
#define idinternal1_m1390_TimS	 1117	//(internal1_m1390_TimS) Время от старта программы
#define internal1_m1390_FinPr0	 BUFFER[3164]	//(internal1_m1390_FinPr0) FinPr - конец программы
#define idinternal1_m1390_FinPr0	 1118	//(internal1_m1390_FinPr0) FinPr - конец программы
#define internal1_m1390_ErrPr0	 BUFFER[3166]	//(internal1_m1390_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m1390_ErrPr0	 1119	//(internal1_m1390_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m1390_sbINI0	 BUFFER[3168]	//(internal1_m1390_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m1390_sbINI0	 1120	//(internal1_m1390_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m1390_sbVuIS0	 BUFFER[3170]	//(internal1_m1390_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m1390_sbVuIS0	 1121	//(internal1_m1390_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m1390_sb2UR0	 BUFFER[3172]	//(internal1_m1390_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m1390_sb2UR0	 1122	//(internal1_m1390_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m1390_sbNupIS0	 BUFFER[3174]	//(internal1_m1390_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m1390_sbNupIS0	 1123	//(internal1_m1390_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m1390_sbVuRB0	 BUFFER[3176]	//(internal1_m1390_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m1390_sbVuRB0	 1124	//(internal1_m1390_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m1390_MyFirstEnterFlag	 BUFFER[3178]	//(internal1_m1390_MyFirstEnterFlag)  
#define idinternal1_m1390_MyFirstEnterFlag	 1125	//(internal1_m1390_MyFirstEnterFlag)  
#define internal1_m1015_q0	 BUFFER[3180]	//(internal1_m1015_q0) q0 - внутренний параметр
#define idinternal1_m1015_q0	 1126	//(internal1_m1015_q0) q0 - внутренний параметр
#define internal1_m1012_q0	 BUFFER[3182]	//(internal1_m1012_q0) q0 - внутренний параметр
#define idinternal1_m1012_q0	 1127	//(internal1_m1012_q0) q0 - внутренний параметр
#define internal1_m1014_q0	 BUFFER[3184]	//(internal1_m1014_q0) q0 - внутренний параметр
#define idinternal1_m1014_q0	 1128	//(internal1_m1014_q0) q0 - внутренний параметр
#define internal1_m1009_q0	 BUFFER[3186]	//(internal1_m1009_q0) q0 - внутренний параметр
#define idinternal1_m1009_q0	 1129	//(internal1_m1009_q0) q0 - внутренний параметр
#define internal1_m742_q0	 BUFFER[3188]	//(internal1_m742_q0) q0 - внутренний параметр
#define idinternal1_m742_q0	 1130	//(internal1_m742_q0) q0 - внутренний параметр
#define internal1_m335_q0	 BUFFER[3190]	//(internal1_m335_q0) q0 - внутренний параметр
#define idinternal1_m335_q0	 1131	//(internal1_m335_q0) q0 - внутренний параметр
#define internal1_m331_q0	 BUFFER[3192]	//(internal1_m331_q0) q0 - внутренний параметр
#define idinternal1_m331_q0	 1132	//(internal1_m331_q0) q0 - внутренний параметр
#define internal1_m288_q0	 BUFFER[3194]	//(internal1_m288_q0) q0 - внутренний параметр
#define idinternal1_m288_q0	 1133	//(internal1_m288_q0) q0 - внутренний параметр
#define internal1_m287_x0	 BUFFER[3196]	//(internal1_m287_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m287_x0	 1134	//(internal1_m287_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1858_q0	 BUFFER[3201]	//(internal1_m1858_q0) q0 - внутренний параметр
#define idinternal1_m1858_q0	 1135	//(internal1_m1858_q0) q0 - внутренний параметр
#define internal1_m1846_q0	 BUFFER[3203]	//(internal1_m1846_q0) q0 - внутренний параметр
#define idinternal1_m1846_q0	 1136	//(internal1_m1846_q0) q0 - внутренний параметр
#define internal1_m1837_q0	 BUFFER[3205]	//(internal1_m1837_q0) q0 - внутренний параметр
#define idinternal1_m1837_q0	 1137	//(internal1_m1837_q0) q0 - внутренний параметр
#define internal1_m1912_q0	 BUFFER[3207]	//(internal1_m1912_q0) q0 - внутренний параметр
#define idinternal1_m1912_q0	 1138	//(internal1_m1912_q0) q0 - внутренний параметр
#define internal1_m1882_q0	 BUFFER[3209]	//(internal1_m1882_q0) q0 - внутренний параметр
#define idinternal1_m1882_q0	 1139	//(internal1_m1882_q0) q0 - внутренний параметр
#define internal1_m1872_q0	 BUFFER[3211]	//(internal1_m1872_q0) q0 - внутренний параметр
#define idinternal1_m1872_q0	 1140	//(internal1_m1872_q0) q0 - внутренний параметр
#define internal1_m1442_q0	 BUFFER[3213]	//(internal1_m1442_q0) q0 - внутренний параметр
#define idinternal1_m1442_q0	 1141	//(internal1_m1442_q0) q0 - внутренний параметр
#define internal1_m1429_x0	 BUFFER[3215]	//(internal1_m1429_x0) был приход сигнала x1
#define idinternal1_m1429_x0	 1142	//(internal1_m1429_x0) был приход сигнала x1
#define internal1_m1429_y0	 BUFFER[3217]	//(internal1_m1429_y0) интервал между сигналами х1 и х2
#define idinternal1_m1429_y0	 1143	//(internal1_m1429_y0) интервал между сигналами х1 и х2
#define internal1_m1425_q0	 BUFFER[3222]	//(internal1_m1425_q0) q0 - внутренний параметр
#define idinternal1_m1425_q0	 1144	//(internal1_m1425_q0) q0 - внутренний параметр
#define internal1_m1416_q0	 BUFFER[3224]	//(internal1_m1416_q0) q0 - внутренний параметр
#define idinternal1_m1416_q0	 1145	//(internal1_m1416_q0) q0 - внутренний параметр
#define internal1_m1475_q0	 BUFFER[3226]	//(internal1_m1475_q0) q0 - внутренний параметр
#define idinternal1_m1475_q0	 1146	//(internal1_m1475_q0) q0 - внутренний параметр
#define internal1_m1495_q0	 BUFFER[3228]	//(internal1_m1495_q0) q0 - внутренний параметр
#define idinternal1_m1495_q0	 1147	//(internal1_m1495_q0) q0 - внутренний параметр
#define internal1_m1461_q0	 BUFFER[3230]	//(internal1_m1461_q0) q0 - внутренний параметр
#define idinternal1_m1461_q0	 1148	//(internal1_m1461_q0) q0 - внутренний параметр
#define internal1_m1476_x0	 BUFFER[3232]	//(internal1_m1476_x0) был приход сигнала x1
#define idinternal1_m1476_x0	 1149	//(internal1_m1476_x0) был приход сигнала x1
#define internal1_m1476_y0	 BUFFER[3234]	//(internal1_m1476_y0) интервал между сигналами х1 и х2
#define idinternal1_m1476_y0	 1150	//(internal1_m1476_y0) интервал между сигналами х1 и х2
#define internal1_m1400_x0	 BUFFER[3239]	//(internal1_m1400_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1400_x0	 1151	//(internal1_m1400_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1481_q0	 BUFFER[3244]	//(internal1_m1481_q0) q0 - внутренний параметр
#define idinternal1_m1481_q0	 1152	//(internal1_m1481_q0) q0 - внутренний параметр
#define internal1_m26_q0	 BUFFER[3246]	//(internal1_m26_q0) q0 - внутренний параметр
#define idinternal1_m26_q0	 1153	//(internal1_m26_q0) q0 - внутренний параметр
#define internal1_m1496_q0	 BUFFER[3248]	//(internal1_m1496_q0) q0 - внутренний параметр
#define idinternal1_m1496_q0	 1154	//(internal1_m1496_q0) q0 - внутренний параметр
#define internal1_m632_q0	 BUFFER[3250]	//(internal1_m632_q0) q0 - внутренний параметр
#define idinternal1_m632_q0	 1155	//(internal1_m632_q0) q0 - внутренний параметр
#define internal1_m617_q0	 BUFFER[3252]	//(internal1_m617_q0) q0 - внутренний параметр
#define idinternal1_m617_q0	 1156	//(internal1_m617_q0) q0 - внутренний параметр
#define internal1_m644_q0	 BUFFER[3254]	//(internal1_m644_q0) q0 - внутренний параметр
#define idinternal1_m644_q0	 1157	//(internal1_m644_q0) q0 - внутренний параметр
#define internal1_m628_q0	 BUFFER[3256]	//(internal1_m628_q0) q0 - внутренний параметр
#define idinternal1_m628_q0	 1158	//(internal1_m628_q0) q0 - внутренний параметр
#define internal1_m612_q0	 BUFFER[3258]	//(internal1_m612_q0) q0 - внутренний параметр
#define idinternal1_m612_q0	 1159	//(internal1_m612_q0) q0 - внутренний параметр
#define internal1_m610_q0	 BUFFER[3260]	//(internal1_m610_q0) q0 - внутренний параметр
#define idinternal1_m610_q0	 1160	//(internal1_m610_q0) q0 - внутренний параметр
#define internal1_m598_q0	 BUFFER[3262]	//(internal1_m598_q0) q0 - внутренний параметр
#define idinternal1_m598_q0	 1161	//(internal1_m598_q0) q0 - внутренний параметр
#define internal1_m1392_q0	 BUFFER[3264]	//(internal1_m1392_q0) q0 - внутренний параметр
#define idinternal1_m1392_q0	 1162	//(internal1_m1392_q0) q0 - внутренний параметр
#define internal1_m608_q0	 BUFFER[3269]	//(internal1_m608_q0) q0 - внутренний параметр
#define idinternal1_m608_q0	 1163	//(internal1_m608_q0) q0 - внутренний параметр
#define internal1_m109_q0	 BUFFER[3271]	//(internal1_m109_q0) q0 - внутренний параметр
#define idinternal1_m109_q0	 1164	//(internal1_m109_q0) q0 - внутренний параметр
#define internal1_m1628_q0	 BUFFER[3273]	//(internal1_m1628_q0) q0 - внутренний параметр
#define idinternal1_m1628_q0	 1165	//(internal1_m1628_q0) q0 - внутренний параметр
#define internal1_m1627_q0	 BUFFER[3275]	//(internal1_m1627_q0) q0 - внутренний параметр
#define idinternal1_m1627_q0	 1166	//(internal1_m1627_q0) q0 - внутренний параметр
#define internal1_m1626_q0	 BUFFER[3277]	//(internal1_m1626_q0) q0 - внутренний параметр
#define idinternal1_m1626_q0	 1167	//(internal1_m1626_q0) q0 - внутренний параметр
#define internal1_m1625_q0	 BUFFER[3279]	//(internal1_m1625_q0) q0 - внутренний параметр
#define idinternal1_m1625_q0	 1168	//(internal1_m1625_q0) q0 - внутренний параметр
#define internal1_m1663_q0	 BUFFER[3281]	//(internal1_m1663_q0) q0 - внутренний параметр
#define idinternal1_m1663_q0	 1169	//(internal1_m1663_q0) q0 - внутренний параметр
#define internal1_m1662_q0	 BUFFER[3283]	//(internal1_m1662_q0) q0 - внутренний параметр
#define idinternal1_m1662_q0	 1170	//(internal1_m1662_q0) q0 - внутренний параметр
#define internal1_m1661_q0	 BUFFER[3285]	//(internal1_m1661_q0) q0 - внутренний параметр
#define idinternal1_m1661_q0	 1171	//(internal1_m1661_q0) q0 - внутренний параметр
#define internal1_m1943_q0	 BUFFER[3287]	//(internal1_m1943_q0) q0 - внутренний параметр
#define idinternal1_m1943_q0	 1172	//(internal1_m1943_q0) q0 - внутренний параметр
#define internal1_m1723_q0	 BUFFER[3289]	//(internal1_m1723_q0) q0 - внутренний параметр
#define idinternal1_m1723_q0	 1173	//(internal1_m1723_q0) q0 - внутренний параметр
#define internal1_m1713_q0	 BUFFER[3291]	//(internal1_m1713_q0) q0 - внутренний параметр
#define idinternal1_m1713_q0	 1174	//(internal1_m1713_q0) q0 - внутренний параметр
#define internal1_m1720_q0	 BUFFER[3293]	//(internal1_m1720_q0) q0 - внутренний параметр
#define idinternal1_m1720_q0	 1175	//(internal1_m1720_q0) q0 - внутренний параметр
#define internal1_m1709_q0	 BUFFER[3295]	//(internal1_m1709_q0) q0 - внутренний параметр
#define idinternal1_m1709_q0	 1176	//(internal1_m1709_q0) q0 - внутренний параметр
#define internal1_m1717_q0	 BUFFER[3297]	//(internal1_m1717_q0) q0 - внутренний параметр
#define idinternal1_m1717_q0	 1177	//(internal1_m1717_q0) q0 - внутренний параметр
#define internal1_m2143_q0	 BUFFER[3299]	//(internal1_m2143_q0) q0 - внутренний параметр
#define idinternal1_m2143_q0	 1178	//(internal1_m2143_q0) q0 - внутренний параметр
#define internal1_m2139_q0	 BUFFER[3301]	//(internal1_m2139_q0) q0 - внутренний параметр
#define idinternal1_m2139_q0	 1179	//(internal1_m2139_q0) q0 - внутренний параметр
#define internal1_m1688_q0	 BUFFER[3303]	//(internal1_m1688_q0) q0 - внутренний параметр
#define idinternal1_m1688_q0	 1180	//(internal1_m1688_q0) q0 - внутренний параметр
#define internal1_m1680_q0	 BUFFER[3305]	//(internal1_m1680_q0) q0 - внутренний параметр
#define idinternal1_m1680_q0	 1181	//(internal1_m1680_q0) q0 - внутренний параметр
#define internal1_m1678_q0	 BUFFER[3307]	//(internal1_m1678_q0) q0 - внутренний параметр
#define idinternal1_m1678_q0	 1182	//(internal1_m1678_q0) q0 - внутренний параметр
#define internal1_m1674_q0	 BUFFER[3309]	//(internal1_m1674_q0) q0 - внутренний параметр
#define idinternal1_m1674_q0	 1183	//(internal1_m1674_q0) q0 - внутренний параметр
#define internal1_m1670_q0	 BUFFER[3311]	//(internal1_m1670_q0) q0 - внутренний параметр
#define idinternal1_m1670_q0	 1184	//(internal1_m1670_q0) q0 - внутренний параметр
#define internal1_m1672_q0	 BUFFER[3313]	//(internal1_m1672_q0) q0 - внутренний параметр
#define idinternal1_m1672_q0	 1185	//(internal1_m1672_q0) q0 - внутренний параметр
#define internal1_m19_q0	 BUFFER[3315]	//(internal1_m19_q0) q0 - внутренний параметр
#define idinternal1_m19_q0	 1186	//(internal1_m19_q0) q0 - внутренний параметр
#define internal1_m1651_q0	 BUFFER[3317]	//(internal1_m1651_q0) q0 - внутренний параметр
#define idinternal1_m1651_q0	 1187	//(internal1_m1651_q0) q0 - внутренний параметр
#define internal1_m1649_q0	 BUFFER[3319]	//(internal1_m1649_q0) q0 - внутренний параметр
#define idinternal1_m1649_q0	 1188	//(internal1_m1649_q0) q0 - внутренний параметр
#define internal1_m1645_q0	 BUFFER[3321]	//(internal1_m1645_q0) q0 - внутренний параметр
#define idinternal1_m1645_q0	 1189	//(internal1_m1645_q0) q0 - внутренний параметр
#define internal1_m1647_q0	 BUFFER[3323]	//(internal1_m1647_q0) q0 - внутренний параметр
#define idinternal1_m1647_q0	 1190	//(internal1_m1647_q0) q0 - внутренний параметр
#define internal1_m1643_q0	 BUFFER[3325]	//(internal1_m1643_q0) q0 - внутренний параметр
#define idinternal1_m1643_q0	 1191	//(internal1_m1643_q0) q0 - внутренний параметр
#define internal1_m1641_q0	 BUFFER[3327]	//(internal1_m1641_q0) q0 - внутренний параметр
#define idinternal1_m1641_q0	 1192	//(internal1_m1641_q0) q0 - внутренний параметр
#define internal1_m2059_q0	 BUFFER[3329]	//(internal1_m2059_q0) q0 - внутренний параметр
#define idinternal1_m2059_q0	 1193	//(internal1_m2059_q0) q0 - внутренний параметр
#define internal1_m2054_q0	 BUFFER[3331]	//(internal1_m2054_q0) q0 - внутренний параметр
#define idinternal1_m2054_q0	 1194	//(internal1_m2054_q0) q0 - внутренний параметр
#define internal1_m2033_q0	 BUFFER[3333]	//(internal1_m2033_q0) q0 - внутренний параметр
#define idinternal1_m2033_q0	 1195	//(internal1_m2033_q0) q0 - внутренний параметр
#define internal1_m2021_q0	 BUFFER[3335]	//(internal1_m2021_q0) q0 - внутренний параметр
#define idinternal1_m2021_q0	 1196	//(internal1_m2021_q0) q0 - внутренний параметр
#define internal1_m1954_q0	 BUFFER[3337]	//(internal1_m1954_q0) q0 - внутренний параметр
#define idinternal1_m1954_q0	 1197	//(internal1_m1954_q0) q0 - внутренний параметр
#define internal1_m1637_q0	 BUFFER[3339]	//(internal1_m1637_q0) q0 - внутренний параметр
#define idinternal1_m1637_q0	 1198	//(internal1_m1637_q0) q0 - внутренний параметр
#define internal1_m1639_q0	 BUFFER[3341]	//(internal1_m1639_q0) q0 - внутренний параметр
#define idinternal1_m1639_q0	 1199	//(internal1_m1639_q0) q0 - внутренний параметр
#define internal1_m1623_q0	 BUFFER[3343]	//(internal1_m1623_q0) q0 - внутренний параметр
#define idinternal1_m1623_q0	 1200	//(internal1_m1623_q0) q0 - внутренний параметр
#define internal1_m1621_q0	 BUFFER[3345]	//(internal1_m1621_q0) q0 - внутренний параметр
#define idinternal1_m1621_q0	 1201	//(internal1_m1621_q0) q0 - внутренний параметр
#define internal1_m1619_q0	 BUFFER[3347]	//(internal1_m1619_q0) q0 - внутренний параметр
#define idinternal1_m1619_q0	 1202	//(internal1_m1619_q0) q0 - внутренний параметр
#define internal1_m1617_q0	 BUFFER[3349]	//(internal1_m1617_q0) q0 - внутренний параметр
#define idinternal1_m1617_q0	 1203	//(internal1_m1617_q0) q0 - внутренний параметр
#define internal1_m1616_q0	 BUFFER[3351]	//(internal1_m1616_q0) q0 - внутренний параметр
#define idinternal1_m1616_q0	 1204	//(internal1_m1616_q0) q0 - внутренний параметр
#define internal1_m1614_q0	 BUFFER[3353]	//(internal1_m1614_q0) q0 - внутренний параметр
#define idinternal1_m1614_q0	 1205	//(internal1_m1614_q0) q0 - внутренний параметр
#define internal1_m1613_q0	 BUFFER[3355]	//(internal1_m1613_q0) q0 - внутренний параметр
#define idinternal1_m1613_q0	 1206	//(internal1_m1613_q0) q0 - внутренний параметр
#define internal1_m1611_q0	 BUFFER[3357]	//(internal1_m1611_q0) q0 - внутренний параметр
#define idinternal1_m1611_q0	 1207	//(internal1_m1611_q0) q0 - внутренний параметр
#define internal1_m2082_DvUp0	 BUFFER[3359]	//(internal1_m2082_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2082_DvUp0	 1208	//(internal1_m2082_DvUp0) - есть команда на движение вперёд
#define internal1_m2082_DvDw0	 BUFFER[3360]	//(internal1_m2082_DvDw0) - есть команда на движение назад
#define idinternal1_m2082_DvDw0	 1209	//(internal1_m2082_DvDw0) - есть команда на движение назад
#define internal1_m2082_FDvUp0	 BUFFER[3361]	//(internal1_m2082_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2082_FDvUp0	 1210	//(internal1_m2082_FDvUp0) - есть команда на движение вперёд
#define internal1_m2082_FDvDw0	 BUFFER[3362]	//(internal1_m2082_FDvDw0) - есть команда на движение назад
#define idinternal1_m2082_FDvDw0	 1211	//(internal1_m2082_FDvDw0) - есть команда на движение назад
#define internal1_m2082_BlDv0	 BUFFER[3363]	//(internal1_m2082_BlDv0) - была блокировка
#define idinternal1_m2082_BlDv0	 1212	//(internal1_m2082_BlDv0) - была блокировка
#define internal1_m2082_Pkv0	 BUFFER[3364]	//(internal1_m2082_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2082_Pkv0	 1213	//(internal1_m2082_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2082_Pkav0	 BUFFER[3365]	//(internal1_m2082_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2082_Pkav0	 1214	//(internal1_m2082_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2082_Zkv0	 BUFFER[3366]	//(internal1_m2082_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2082_Zkv0	 1215	//(internal1_m2082_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2082_Zkav0	 BUFFER[3367]	//(internal1_m2082_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2082_Zkav0	 1216	//(internal1_m2082_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2082_txNm	 BUFFER[3368]	//(internal1_m2082_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2082_txNm	 1217	//(internal1_m2082_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2082_txSm	 BUFFER[3373]	//(internal1_m2082_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2082_txSm	 1218	//(internal1_m2082_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2082_txHr	 BUFFER[3378]	//(internal1_m2082_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2082_txHr	 1219	//(internal1_m2082_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2082_txLd	 BUFFER[3383]	//(internal1_m2082_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2082_txLd	 1220	//(internal1_m2082_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2082_fef	 BUFFER[3388]	//(internal1_m2082_fef) fef
#define idinternal1_m2082_fef	 1221	//(internal1_m2082_fef) fef
#define internal1_m2076_DvUp0	 BUFFER[3389]	//(internal1_m2076_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2076_DvUp0	 1222	//(internal1_m2076_DvUp0) - есть команда на движение вперёд
#define internal1_m2076_DvDw0	 BUFFER[3390]	//(internal1_m2076_DvDw0) - есть команда на движение назад
#define idinternal1_m2076_DvDw0	 1223	//(internal1_m2076_DvDw0) - есть команда на движение назад
#define internal1_m2076_FDvUp0	 BUFFER[3391]	//(internal1_m2076_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2076_FDvUp0	 1224	//(internal1_m2076_FDvUp0) - есть команда на движение вперёд
#define internal1_m2076_FDvDw0	 BUFFER[3392]	//(internal1_m2076_FDvDw0) - есть команда на движение назад
#define idinternal1_m2076_FDvDw0	 1225	//(internal1_m2076_FDvDw0) - есть команда на движение назад
#define internal1_m2076_BlDv0	 BUFFER[3393]	//(internal1_m2076_BlDv0) - была блокировка
#define idinternal1_m2076_BlDv0	 1226	//(internal1_m2076_BlDv0) - была блокировка
#define internal1_m2076_Pkv0	 BUFFER[3394]	//(internal1_m2076_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2076_Pkv0	 1227	//(internal1_m2076_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2076_Pkav0	 BUFFER[3395]	//(internal1_m2076_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2076_Pkav0	 1228	//(internal1_m2076_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2076_Zkv0	 BUFFER[3396]	//(internal1_m2076_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2076_Zkv0	 1229	//(internal1_m2076_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2076_Zkav0	 BUFFER[3397]	//(internal1_m2076_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2076_Zkav0	 1230	//(internal1_m2076_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2076_txNm	 BUFFER[3398]	//(internal1_m2076_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2076_txNm	 1231	//(internal1_m2076_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2076_txSm	 BUFFER[3403]	//(internal1_m2076_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2076_txSm	 1232	//(internal1_m2076_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2076_txHr	 BUFFER[3408]	//(internal1_m2076_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2076_txHr	 1233	//(internal1_m2076_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2076_txLd	 BUFFER[3413]	//(internal1_m2076_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2076_txLd	 1234	//(internal1_m2076_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2076_fef	 BUFFER[3418]	//(internal1_m2076_fef) fef
#define idinternal1_m2076_fef	 1235	//(internal1_m2076_fef) fef
#define internal1_m1466_q0	 BUFFER[3419]	//(internal1_m1466_q0) q0 - внутренний параметр
#define idinternal1_m1466_q0	 1236	//(internal1_m1466_q0) q0 - внутренний параметр
#define internal1_m1470_x0	 BUFFER[3421]	//(internal1_m1470_x0) был приход сигнала x1
#define idinternal1_m1470_x0	 1237	//(internal1_m1470_x0) был приход сигнала x1
#define internal1_m1470_y0	 BUFFER[3423]	//(internal1_m1470_y0) интервал между сигналами х1 и х2
#define idinternal1_m1470_y0	 1238	//(internal1_m1470_y0) интервал между сигналами х1 и х2
#define internal1_m1894_x0	 BUFFER[3428]	//(internal1_m1894_x0) был приход сигнала x1
#define idinternal1_m1894_x0	 1239	//(internal1_m1894_x0) был приход сигнала x1
#define internal1_m1894_y0	 BUFFER[3430]	//(internal1_m1894_y0) интервал между сигналами х1 и х2
#define idinternal1_m1894_y0	 1240	//(internal1_m1894_y0) интервал между сигналами х1 и х2
#define internal1_m1855_x0	 BUFFER[3435]	//(internal1_m1855_x0) был приход сигнала x1
#define idinternal1_m1855_x0	 1241	//(internal1_m1855_x0) был приход сигнала x1
#define internal1_m1855_y0	 BUFFER[3437]	//(internal1_m1855_y0) интервал между сигналами х1 и х2
#define idinternal1_m1855_y0	 1242	//(internal1_m1855_y0) интервал между сигналами х1 и х2
#define internal1_m279_q0	 BUFFER[3442]	//(internal1_m279_q0) q0 - внутренний параметр
#define idinternal1_m279_q0	 1243	//(internal1_m279_q0) q0 - внутренний параметр
#define internal1_m989_q0	 BUFFER[3444]	//(internal1_m989_q0) q0 - внутренний параметр
#define idinternal1_m989_q0	 1244	//(internal1_m989_q0) q0 - внутренний параметр
#define internal1_m620_q0	 BUFFER[3446]	//(internal1_m620_q0) q0 - внутренний параметр
#define idinternal1_m620_q0	 1245	//(internal1_m620_q0) q0 - внутренний параметр
#define internal1_m1289_X0	 BUFFER[3448]	//(internal1_m1289_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1289_X0	 1246	//(internal1_m1289_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1289_t0	 BUFFER[3453]	//(internal1_m1289_t0) время нахождения в зоне возврата
#define idinternal1_m1289_t0	 1247	//(internal1_m1289_t0) время нахождения в зоне возврата
#define internal1_m1289_BLDv0	 BUFFER[3458]	//(internal1_m1289_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1289_BLDv0	 1248	//(internal1_m1289_BLDv0) BlDv - Блокировка движения
#define internal1_m1308_tx	 BUFFER[3459]	//(internal1_m1308_tx) tx - время накопленное сек
#define idinternal1_m1308_tx	 1249	//(internal1_m1308_tx) tx - время накопленное сек
#define internal1_m1308_y0	 BUFFER[3464]	//(internal1_m1308_y0) y0
#define idinternal1_m1308_y0	 1250	//(internal1_m1308_y0) y0
#define internal1_m1309_tx	 BUFFER[3465]	//(internal1_m1309_tx) tx - время накопленное сек
#define idinternal1_m1309_tx	 1251	//(internal1_m1309_tx) tx - время накопленное сек
#define internal1_m1309_y0	 BUFFER[3470]	//(internal1_m1309_y0) y0
#define idinternal1_m1309_y0	 1252	//(internal1_m1309_y0) y0
#define internal1_m1317_xptr	 BUFFER[3471]	//(internal1_m1317_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1317_xptr	 1253	//(internal1_m1317_xptr) указатель текущей позиции в массиве координат
#define internal1_m1317_x0	 BUFFER[3474]	//(internal1_m1317_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1317_x0	 1254	//(internal1_m1317_x0) x0 - массив мгновенных значений координат
#define internal1_m1317_tim0	 BUFFER[3774]	//(internal1_m1317_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1317_tim0	 1255	//(internal1_m1317_tim0) tim0 - массив значений времени цикла
#define internal1_m1317_sumtim	 BUFFER[4074]	//(internal1_m1317_sumtim) sumtim - время в пути
#define idinternal1_m1317_sumtim	 1256	//(internal1_m1317_sumtim) sumtim - время в пути
#define internal1_m1317_StSpeed	 BUFFER[4079]	//(internal1_m1317_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1317_StSpeed	 1257	//(internal1_m1317_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1317_Vz0	 BUFFER[4084]	//(internal1_m1317_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1317_Vz0	 1258	//(internal1_m1317_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1317_flRazg	 BUFFER[4089]	//(internal1_m1317_flRazg) признак разгона/торможения
#define idinternal1_m1317_flRazg	 1259	//(internal1_m1317_flRazg) признак разгона/торможения
#define internal1_m1317_DelSp	 BUFFER[4092]	//(internal1_m1317_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1317_DelSp	 1260	//(internal1_m1317_DelSp) DelSp - время переключения скоростей
#define internal1_m1317_z0	 BUFFER[4097]	//(internal1_m1317_z0) z0 - точка прекращения движения
#define idinternal1_m1317_z0	 1261	//(internal1_m1317_z0) z0 - точка прекращения движения
#define internal1_m1317_txZS	 BUFFER[4102]	//(internal1_m1317_txZS) txZS
#define idinternal1_m1317_txZS	 1262	//(internal1_m1317_txZS) txZS
#define internal1_m1317_tx	 BUFFER[4107]	//(internal1_m1317_tx) tx
#define idinternal1_m1317_tx	 1263	//(internal1_m1317_tx) tx
#define internal1_m1317_txd	 BUFFER[4112]	//(internal1_m1317_txd) txd
#define idinternal1_m1317_txd	 1264	//(internal1_m1317_txd) txd
#define internal1_m1317_txMBl	 BUFFER[4117]	//(internal1_m1317_txMBl) tx
#define idinternal1_m1317_txMBl	 1265	//(internal1_m1317_txMBl) tx
#define internal1_m1317_txBl	 BUFFER[4122]	//(internal1_m1317_txBl) tx
#define idinternal1_m1317_txBl	 1266	//(internal1_m1317_txBl) tx
#define internal1_m1317_Speed0	 BUFFER[4127]	//(internal1_m1317_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1317_Speed0	 1267	//(internal1_m1317_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1317_xz0	 BUFFER[4132]	//(internal1_m1317_xz0) xz0 - новое задание мм
#define idinternal1_m1317_xz0	 1268	//(internal1_m1317_xz0) xz0 - новое задание мм
#define internal1_m1317_tz0	 BUFFER[4137]	//(internal1_m1317_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1317_tz0	 1269	//(internal1_m1317_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1317_Shift0	 BUFFER[4142]	//(internal1_m1317_Shift0) Shift0 - признак самохода
#define idinternal1_m1317_Shift0	 1270	//(internal1_m1317_Shift0) Shift0 - признак самохода
#define internal1_m1317_ShCntlSp0	 BUFFER[4144]	//(internal1_m1317_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1317_ShCntlSp0	 1271	//(internal1_m1317_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1317_ShiftControl	 BUFFER[4146]	//(internal1_m1317_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1317_ShiftControl	 1272	//(internal1_m1317_ShiftControl) ShiftControl - признак самохода
#define internal1_m618_q0	 BUFFER[4148]	//(internal1_m618_q0) q0 - внутренний параметр
#define idinternal1_m618_q0	 1273	//(internal1_m618_q0) q0 - внутренний параметр
#define internal1_m887_X0	 BUFFER[4150]	//(internal1_m887_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m887_X0	 1274	//(internal1_m887_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m887_t0	 BUFFER[4155]	//(internal1_m887_t0) время нахождения в зоне возврата
#define idinternal1_m887_t0	 1275	//(internal1_m887_t0) время нахождения в зоне возврата
#define internal1_m887_BLDv0	 BUFFER[4160]	//(internal1_m887_BLDv0) BlDv - Блокировка движения
#define idinternal1_m887_BLDv0	 1276	//(internal1_m887_BLDv0) BlDv - Блокировка движения
#define internal1_m911_tx	 BUFFER[4161]	//(internal1_m911_tx) tx - время накопленное сек
#define idinternal1_m911_tx	 1277	//(internal1_m911_tx) tx - время накопленное сек
#define internal1_m911_y0	 BUFFER[4166]	//(internal1_m911_y0) y0
#define idinternal1_m911_y0	 1278	//(internal1_m911_y0) y0
#define internal1_m914_tx	 BUFFER[4167]	//(internal1_m914_tx) tx - время накопленное сек
#define idinternal1_m914_tx	 1279	//(internal1_m914_tx) tx - время накопленное сек
#define internal1_m914_y0	 BUFFER[4172]	//(internal1_m914_y0) y0
#define idinternal1_m914_y0	 1280	//(internal1_m914_y0) y0
#define internal1_m920_xptr	 BUFFER[4173]	//(internal1_m920_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m920_xptr	 1281	//(internal1_m920_xptr) указатель текущей позиции в массиве координат
#define internal1_m920_x0	 BUFFER[4176]	//(internal1_m920_x0) x0 - массив мгновенных значений координат
#define idinternal1_m920_x0	 1282	//(internal1_m920_x0) x0 - массив мгновенных значений координат
#define internal1_m920_tim0	 BUFFER[4476]	//(internal1_m920_tim0) tim0 - массив значений времени цикла
#define idinternal1_m920_tim0	 1283	//(internal1_m920_tim0) tim0 - массив значений времени цикла
#define internal1_m920_sumtim	 BUFFER[4776]	//(internal1_m920_sumtim) sumtim - время в пути
#define idinternal1_m920_sumtim	 1284	//(internal1_m920_sumtim) sumtim - время в пути
#define internal1_m920_StSpeed	 BUFFER[4781]	//(internal1_m920_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m920_StSpeed	 1285	//(internal1_m920_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m920_Vz0	 BUFFER[4786]	//(internal1_m920_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m920_Vz0	 1286	//(internal1_m920_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m920_flRazg	 BUFFER[4791]	//(internal1_m920_flRazg) признак разгона/торможения
#define idinternal1_m920_flRazg	 1287	//(internal1_m920_flRazg) признак разгона/торможения
#define internal1_m920_DelSp	 BUFFER[4794]	//(internal1_m920_DelSp) DelSp - время переключения скоростей
#define idinternal1_m920_DelSp	 1288	//(internal1_m920_DelSp) DelSp - время переключения скоростей
#define internal1_m920_z0	 BUFFER[4799]	//(internal1_m920_z0) z0 - точка прекращения движения
#define idinternal1_m920_z0	 1289	//(internal1_m920_z0) z0 - точка прекращения движения
#define internal1_m920_txZS	 BUFFER[4804]	//(internal1_m920_txZS) txZS
#define idinternal1_m920_txZS	 1290	//(internal1_m920_txZS) txZS
#define internal1_m920_tx	 BUFFER[4809]	//(internal1_m920_tx) tx
#define idinternal1_m920_tx	 1291	//(internal1_m920_tx) tx
#define internal1_m920_txd	 BUFFER[4814]	//(internal1_m920_txd) txd
#define idinternal1_m920_txd	 1292	//(internal1_m920_txd) txd
#define internal1_m920_txMBl	 BUFFER[4819]	//(internal1_m920_txMBl) tx
#define idinternal1_m920_txMBl	 1293	//(internal1_m920_txMBl) tx
#define internal1_m920_txBl	 BUFFER[4824]	//(internal1_m920_txBl) tx
#define idinternal1_m920_txBl	 1294	//(internal1_m920_txBl) tx
#define internal1_m920_Speed0	 BUFFER[4829]	//(internal1_m920_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m920_Speed0	 1295	//(internal1_m920_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m920_xz0	 BUFFER[4834]	//(internal1_m920_xz0) xz0 - новое задание мм
#define idinternal1_m920_xz0	 1296	//(internal1_m920_xz0) xz0 - новое задание мм
#define internal1_m920_tz0	 BUFFER[4839]	//(internal1_m920_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m920_tz0	 1297	//(internal1_m920_tz0) tz0 - время защиты от нового задания сек
#define internal1_m920_Shift0	 BUFFER[4844]	//(internal1_m920_Shift0) Shift0 - признак самохода
#define idinternal1_m920_Shift0	 1298	//(internal1_m920_Shift0) Shift0 - признак самохода
#define internal1_m920_ShCntlSp0	 BUFFER[4846]	//(internal1_m920_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m920_ShCntlSp0	 1299	//(internal1_m920_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m920_ShiftControl	 BUFFER[4848]	//(internal1_m920_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m920_ShiftControl	 1300	//(internal1_m920_ShiftControl) ShiftControl - признак самохода
#define internal1_m489_X0	 BUFFER[4850]	//(internal1_m489_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m489_X0	 1301	//(internal1_m489_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m489_t0	 BUFFER[4855]	//(internal1_m489_t0) время нахождения в зоне возврата
#define idinternal1_m489_t0	 1302	//(internal1_m489_t0) время нахождения в зоне возврата
#define internal1_m489_BLDv0	 BUFFER[4860]	//(internal1_m489_BLDv0) BlDv - Блокировка движения
#define idinternal1_m489_BLDv0	 1303	//(internal1_m489_BLDv0) BlDv - Блокировка движения
#define internal1_m509_tx	 BUFFER[4861]	//(internal1_m509_tx) tx - время накопленное сек
#define idinternal1_m509_tx	 1304	//(internal1_m509_tx) tx - время накопленное сек
#define internal1_m509_y0	 BUFFER[4866]	//(internal1_m509_y0) y0
#define idinternal1_m509_y0	 1305	//(internal1_m509_y0) y0
#define internal1_m512_tx	 BUFFER[4867]	//(internal1_m512_tx) tx - время накопленное сек
#define idinternal1_m512_tx	 1306	//(internal1_m512_tx) tx - время накопленное сек
#define internal1_m512_y0	 BUFFER[4872]	//(internal1_m512_y0) y0
#define idinternal1_m512_y0	 1307	//(internal1_m512_y0) y0
#define internal1_m516_xptr	 BUFFER[4873]	//(internal1_m516_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m516_xptr	 1308	//(internal1_m516_xptr) указатель текущей позиции в массиве координат
#define internal1_m516_x0	 BUFFER[4876]	//(internal1_m516_x0) x0 - массив мгновенных значений координат
#define idinternal1_m516_x0	 1309	//(internal1_m516_x0) x0 - массив мгновенных значений координат
#define internal1_m516_tim0	 BUFFER[5626]	//(internal1_m516_tim0) tim0 - массив значений времени цикла
#define idinternal1_m516_tim0	 1310	//(internal1_m516_tim0) tim0 - массив значений времени цикла
#define internal1_m516_sumtim	 BUFFER[6376]	//(internal1_m516_sumtim) sumtim - время в пути
#define idinternal1_m516_sumtim	 1311	//(internal1_m516_sumtim) sumtim - время в пути
#define internal1_m516_StSpeed	 BUFFER[6381]	//(internal1_m516_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m516_StSpeed	 1312	//(internal1_m516_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m516_Vz0	 BUFFER[6386]	//(internal1_m516_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m516_Vz0	 1313	//(internal1_m516_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m516_flRazg	 BUFFER[6391]	//(internal1_m516_flRazg) признак разгона/торможения
#define idinternal1_m516_flRazg	 1314	//(internal1_m516_flRazg) признак разгона/торможения
#define internal1_m516_DelSp	 BUFFER[6394]	//(internal1_m516_DelSp) DelSp - время переключения скоростей
#define idinternal1_m516_DelSp	 1315	//(internal1_m516_DelSp) DelSp - время переключения скоростей
#define internal1_m516_z0	 BUFFER[6399]	//(internal1_m516_z0) z0 - точка прекращения движения
#define idinternal1_m516_z0	 1316	//(internal1_m516_z0) z0 - точка прекращения движения
#define internal1_m516_txZS	 BUFFER[6404]	//(internal1_m516_txZS) txZS
#define idinternal1_m516_txZS	 1317	//(internal1_m516_txZS) txZS
#define internal1_m516_tx	 BUFFER[6409]	//(internal1_m516_tx) tx
#define idinternal1_m516_tx	 1318	//(internal1_m516_tx) tx
#define internal1_m516_txd	 BUFFER[6414]	//(internal1_m516_txd) txd
#define idinternal1_m516_txd	 1319	//(internal1_m516_txd) txd
#define internal1_m516_txMBl	 BUFFER[6419]	//(internal1_m516_txMBl) tx
#define idinternal1_m516_txMBl	 1320	//(internal1_m516_txMBl) tx
#define internal1_m516_txBl	 BUFFER[6424]	//(internal1_m516_txBl) tx
#define idinternal1_m516_txBl	 1321	//(internal1_m516_txBl) tx
#define internal1_m516_Speed0	 BUFFER[6429]	//(internal1_m516_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m516_Speed0	 1322	//(internal1_m516_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m516_xz0	 BUFFER[6434]	//(internal1_m516_xz0) xz0 - новое задание мм
#define idinternal1_m516_xz0	 1323	//(internal1_m516_xz0) xz0 - новое задание мм
#define internal1_m516_tz0	 BUFFER[6439]	//(internal1_m516_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m516_tz0	 1324	//(internal1_m516_tz0) tz0 - время защиты от нового задания сек
#define internal1_m516_Shift0	 BUFFER[6444]	//(internal1_m516_Shift0) Shift0 - признак самохода
#define idinternal1_m516_Shift0	 1325	//(internal1_m516_Shift0) Shift0 - признак самохода
#define internal1_m516_ShCntlSp0	 BUFFER[6446]	//(internal1_m516_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m516_ShCntlSp0	 1326	//(internal1_m516_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m516_ShiftControl	 BUFFER[6448]	//(internal1_m516_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m516_ShiftControl	 1327	//(internal1_m516_ShiftControl) ShiftControl - признак самохода
#define internal1_m615_q0	 BUFFER[6450]	//(internal1_m615_q0) q0 - внутренний параметр
#define idinternal1_m615_q0	 1328	//(internal1_m615_q0) q0 - внутренний параметр
#define internal1_m168_X0	 BUFFER[6452]	//(internal1_m168_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m168_X0	 1329	//(internal1_m168_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m168_t0	 BUFFER[6457]	//(internal1_m168_t0) время нахождения в зоне возврата
#define idinternal1_m168_t0	 1330	//(internal1_m168_t0) время нахождения в зоне возврата
#define internal1_m168_BLDv0	 BUFFER[6462]	//(internal1_m168_BLDv0) BlDv - Блокировка движения
#define idinternal1_m168_BLDv0	 1331	//(internal1_m168_BLDv0) BlDv - Блокировка движения
#define internal1_m197_xptr	 BUFFER[6463]	//(internal1_m197_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m197_xptr	 1332	//(internal1_m197_xptr) указатель текущей позиции в массиве координат
#define internal1_m197_x0	 BUFFER[6466]	//(internal1_m197_x0) x0 - массив мгновенных значений координат
#define idinternal1_m197_x0	 1333	//(internal1_m197_x0) x0 - массив мгновенных значений координат
#define internal1_m197_tim0	 BUFFER[7216]	//(internal1_m197_tim0) tim0 - массив значений времени цикла
#define idinternal1_m197_tim0	 1334	//(internal1_m197_tim0) tim0 - массив значений времени цикла
#define internal1_m197_sumtim	 BUFFER[7966]	//(internal1_m197_sumtim) sumtim - время в пути
#define idinternal1_m197_sumtim	 1335	//(internal1_m197_sumtim) sumtim - время в пути
#define internal1_m197_StSpeed	 BUFFER[7971]	//(internal1_m197_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m197_StSpeed	 1336	//(internal1_m197_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m197_Vz0	 BUFFER[7976]	//(internal1_m197_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m197_Vz0	 1337	//(internal1_m197_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m197_flRazg	 BUFFER[7981]	//(internal1_m197_flRazg) признак разгона/торможения
#define idinternal1_m197_flRazg	 1338	//(internal1_m197_flRazg) признак разгона/торможения
#define internal1_m197_DelSp	 BUFFER[7984]	//(internal1_m197_DelSp) DelSp - время переключения скоростей
#define idinternal1_m197_DelSp	 1339	//(internal1_m197_DelSp) DelSp - время переключения скоростей
#define internal1_m197_z0	 BUFFER[7989]	//(internal1_m197_z0) z0 - точка прекращения движения
#define idinternal1_m197_z0	 1340	//(internal1_m197_z0) z0 - точка прекращения движения
#define internal1_m197_txZS	 BUFFER[7994]	//(internal1_m197_txZS) txZS
#define idinternal1_m197_txZS	 1341	//(internal1_m197_txZS) txZS
#define internal1_m197_tx	 BUFFER[7999]	//(internal1_m197_tx) tx
#define idinternal1_m197_tx	 1342	//(internal1_m197_tx) tx
#define internal1_m197_txd	 BUFFER[8004]	//(internal1_m197_txd) txd
#define idinternal1_m197_txd	 1343	//(internal1_m197_txd) txd
#define internal1_m197_txMBl	 BUFFER[8009]	//(internal1_m197_txMBl) tx
#define idinternal1_m197_txMBl	 1344	//(internal1_m197_txMBl) tx
#define internal1_m197_txBl	 BUFFER[8014]	//(internal1_m197_txBl) tx
#define idinternal1_m197_txBl	 1345	//(internal1_m197_txBl) tx
#define internal1_m197_Speed0	 BUFFER[8019]	//(internal1_m197_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m197_Speed0	 1346	//(internal1_m197_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m197_xz0	 BUFFER[8024]	//(internal1_m197_xz0) xz0 - новое задание мм
#define idinternal1_m197_xz0	 1347	//(internal1_m197_xz0) xz0 - новое задание мм
#define internal1_m197_tz0	 BUFFER[8029]	//(internal1_m197_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m197_tz0	 1348	//(internal1_m197_tz0) tz0 - время защиты от нового задания сек
#define internal1_m197_Shift0	 BUFFER[8034]	//(internal1_m197_Shift0) Shift0 - признак самохода
#define idinternal1_m197_Shift0	 1349	//(internal1_m197_Shift0) Shift0 - признак самохода
#define internal1_m197_ShCntlSp0	 BUFFER[8036]	//(internal1_m197_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m197_ShCntlSp0	 1350	//(internal1_m197_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m197_ShiftControl	 BUFFER[8038]	//(internal1_m197_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m197_ShiftControl	 1351	//(internal1_m197_ShiftControl) ShiftControl - признак самохода
#define internal1_m641_q0	 BUFFER[8040]	//(internal1_m641_q0) q0 - внутренний параметр
#define idinternal1_m641_q0	 1352	//(internal1_m641_q0) q0 - внутренний параметр
#define internal1_m460_DvUp0	 BUFFER[8042]	//(internal1_m460_DvUp0) - есть команда на движение вперёд
#define idinternal1_m460_DvUp0	 1353	//(internal1_m460_DvUp0) - есть команда на движение вперёд
#define internal1_m460_DvDw0	 BUFFER[8043]	//(internal1_m460_DvDw0) - есть команда на движение назад
#define idinternal1_m460_DvDw0	 1354	//(internal1_m460_DvDw0) - есть команда на движение назад
#define internal1_m460_FDvUp0	 BUFFER[8044]	//(internal1_m460_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m460_FDvUp0	 1355	//(internal1_m460_FDvUp0) - есть команда на движение вперёд
#define internal1_m460_FDvDw0	 BUFFER[8045]	//(internal1_m460_FDvDw0) - есть команда на движение назад
#define idinternal1_m460_FDvDw0	 1356	//(internal1_m460_FDvDw0) - есть команда на движение назад
#define internal1_m460_BlDv0	 BUFFER[8046]	//(internal1_m460_BlDv0) - была блокировка
#define idinternal1_m460_BlDv0	 1357	//(internal1_m460_BlDv0) - была блокировка
#define internal1_m460_Pkv0	 BUFFER[8047]	//(internal1_m460_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m460_Pkv0	 1358	//(internal1_m460_Pkv0) Pkv - передний конечный выключатель
#define internal1_m460_Pkav0	 BUFFER[8048]	//(internal1_m460_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m460_Pkav0	 1359	//(internal1_m460_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m460_Zkv0	 BUFFER[8049]	//(internal1_m460_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m460_Zkv0	 1360	//(internal1_m460_Zkv0) Zkv - задний конечный выключатель
#define internal1_m460_Zkav0	 BUFFER[8050]	//(internal1_m460_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m460_Zkav0	 1361	//(internal1_m460_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m460_txNm	 BUFFER[8051]	//(internal1_m460_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m460_txNm	 1362	//(internal1_m460_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m460_txSm	 BUFFER[8056]	//(internal1_m460_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m460_txSm	 1363	//(internal1_m460_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m460_txHr	 BUFFER[8061]	//(internal1_m460_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m460_txHr	 1364	//(internal1_m460_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m460_txLd	 BUFFER[8066]	//(internal1_m460_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m460_txLd	 1365	//(internal1_m460_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m460_fef	 BUFFER[8071]	//(internal1_m460_fef) fef
#define idinternal1_m460_fef	 1366	//(internal1_m460_fef) fef
#define internal1_m454_DvUp0	 BUFFER[8072]	//(internal1_m454_DvUp0) - есть команда на движение вперёд
#define idinternal1_m454_DvUp0	 1367	//(internal1_m454_DvUp0) - есть команда на движение вперёд
#define internal1_m454_DvDw0	 BUFFER[8073]	//(internal1_m454_DvDw0) - есть команда на движение назад
#define idinternal1_m454_DvDw0	 1368	//(internal1_m454_DvDw0) - есть команда на движение назад
#define internal1_m454_FDvUp0	 BUFFER[8074]	//(internal1_m454_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m454_FDvUp0	 1369	//(internal1_m454_FDvUp0) - есть команда на движение вперёд
#define internal1_m454_FDvDw0	 BUFFER[8075]	//(internal1_m454_FDvDw0) - есть команда на движение назад
#define idinternal1_m454_FDvDw0	 1370	//(internal1_m454_FDvDw0) - есть команда на движение назад
#define internal1_m454_BlDv0	 BUFFER[8076]	//(internal1_m454_BlDv0) - была блокировка
#define idinternal1_m454_BlDv0	 1371	//(internal1_m454_BlDv0) - была блокировка
#define internal1_m454_Pkv0	 BUFFER[8077]	//(internal1_m454_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m454_Pkv0	 1372	//(internal1_m454_Pkv0) Pkv - передний конечный выключатель
#define internal1_m454_Pkav0	 BUFFER[8078]	//(internal1_m454_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m454_Pkav0	 1373	//(internal1_m454_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m454_Zkv0	 BUFFER[8079]	//(internal1_m454_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m454_Zkv0	 1374	//(internal1_m454_Zkv0) Zkv - задний конечный выключатель
#define internal1_m454_Zkav0	 BUFFER[8080]	//(internal1_m454_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m454_Zkav0	 1375	//(internal1_m454_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m454_txNm	 BUFFER[8081]	//(internal1_m454_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m454_txNm	 1376	//(internal1_m454_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m454_txSm	 BUFFER[8086]	//(internal1_m454_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m454_txSm	 1377	//(internal1_m454_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m454_txHr	 BUFFER[8091]	//(internal1_m454_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m454_txHr	 1378	//(internal1_m454_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m454_txLd	 BUFFER[8096]	//(internal1_m454_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m454_txLd	 1379	//(internal1_m454_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m454_fef	 BUFFER[8101]	//(internal1_m454_fef) fef
#define idinternal1_m454_fef	 1380	//(internal1_m454_fef) fef
#define internal1_m807_X0	 BUFFER[8102]	//(internal1_m807_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m807_X0	 1381	//(internal1_m807_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m807_t0	 BUFFER[8107]	//(internal1_m807_t0) время нахождения в зоне возврата
#define idinternal1_m807_t0	 1382	//(internal1_m807_t0) время нахождения в зоне возврата
#define internal1_m807_BLDv0	 BUFFER[8112]	//(internal1_m807_BLDv0) BlDv - Блокировка движения
#define idinternal1_m807_BLDv0	 1383	//(internal1_m807_BLDv0) BlDv - Блокировка движения
#define internal1_m827_xptr	 BUFFER[8113]	//(internal1_m827_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m827_xptr	 1384	//(internal1_m827_xptr) указатель текущей позиции в массиве координат
#define internal1_m827_x0	 BUFFER[8116]	//(internal1_m827_x0) x0 - массив мгновенных значений координат
#define idinternal1_m827_x0	 1385	//(internal1_m827_x0) x0 - массив мгновенных значений координат
#define internal1_m827_tim0	 BUFFER[8516]	//(internal1_m827_tim0) tim0 - массив значений времени цикла
#define idinternal1_m827_tim0	 1386	//(internal1_m827_tim0) tim0 - массив значений времени цикла
#define internal1_m827_sumtim	 BUFFER[8916]	//(internal1_m827_sumtim) sumtim - время в пути
#define idinternal1_m827_sumtim	 1387	//(internal1_m827_sumtim) sumtim - время в пути
#define internal1_m827_StSpeed	 BUFFER[8921]	//(internal1_m827_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m827_StSpeed	 1388	//(internal1_m827_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m827_Vz0	 BUFFER[8926]	//(internal1_m827_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m827_Vz0	 1389	//(internal1_m827_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m827_flRazg	 BUFFER[8931]	//(internal1_m827_flRazg) признак разгона/торможения
#define idinternal1_m827_flRazg	 1390	//(internal1_m827_flRazg) признак разгона/торможения
#define internal1_m827_DelSp	 BUFFER[8934]	//(internal1_m827_DelSp) DelSp - время переключения скоростей
#define idinternal1_m827_DelSp	 1391	//(internal1_m827_DelSp) DelSp - время переключения скоростей
#define internal1_m827_z0	 BUFFER[8939]	//(internal1_m827_z0) z0 - точка прекращения движения
#define idinternal1_m827_z0	 1392	//(internal1_m827_z0) z0 - точка прекращения движения
#define internal1_m827_txZS	 BUFFER[8944]	//(internal1_m827_txZS) txZS
#define idinternal1_m827_txZS	 1393	//(internal1_m827_txZS) txZS
#define internal1_m827_tx	 BUFFER[8949]	//(internal1_m827_tx) tx
#define idinternal1_m827_tx	 1394	//(internal1_m827_tx) tx
#define internal1_m827_txd	 BUFFER[8954]	//(internal1_m827_txd) txd
#define idinternal1_m827_txd	 1395	//(internal1_m827_txd) txd
#define internal1_m827_txMBl	 BUFFER[8959]	//(internal1_m827_txMBl) tx
#define idinternal1_m827_txMBl	 1396	//(internal1_m827_txMBl) tx
#define internal1_m827_txBl	 BUFFER[8964]	//(internal1_m827_txBl) tx
#define idinternal1_m827_txBl	 1397	//(internal1_m827_txBl) tx
#define internal1_m827_Speed0	 BUFFER[8969]	//(internal1_m827_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m827_Speed0	 1398	//(internal1_m827_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m827_xz0	 BUFFER[8974]	//(internal1_m827_xz0) xz0 - новое задание мм
#define idinternal1_m827_xz0	 1399	//(internal1_m827_xz0) xz0 - новое задание мм
#define internal1_m827_tz0	 BUFFER[8979]	//(internal1_m827_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m827_tz0	 1400	//(internal1_m827_tz0) tz0 - время защиты от нового задания сек
#define internal1_m827_Shift0	 BUFFER[8984]	//(internal1_m827_Shift0) Shift0 - признак самохода
#define idinternal1_m827_Shift0	 1401	//(internal1_m827_Shift0) Shift0 - признак самохода
#define internal1_m827_ShCntlSp0	 BUFFER[8986]	//(internal1_m827_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m827_ShCntlSp0	 1402	//(internal1_m827_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m827_ShiftControl	 BUFFER[8988]	//(internal1_m827_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m827_ShiftControl	 1403	//(internal1_m827_ShiftControl) ShiftControl - признак самохода
#define internal1_m1571_X0	 BUFFER[8990]	//(internal1_m1571_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1571_X0	 1404	//(internal1_m1571_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1571_t0	 BUFFER[8995]	//(internal1_m1571_t0) время нахождения в зоне возврата
#define idinternal1_m1571_t0	 1405	//(internal1_m1571_t0) время нахождения в зоне возврата
#define internal1_m1571_BLDv0	 BUFFER[9000]	//(internal1_m1571_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1571_BLDv0	 1406	//(internal1_m1571_BLDv0) BlDv - Блокировка движения
#define internal1_m1107_X0	 BUFFER[9001]	//(internal1_m1107_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1107_X0	 1407	//(internal1_m1107_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1107_t0	 BUFFER[9006]	//(internal1_m1107_t0) время нахождения в зоне возврата
#define idinternal1_m1107_t0	 1408	//(internal1_m1107_t0) время нахождения в зоне возврата
#define internal1_m1107_BLDv0	 BUFFER[9011]	//(internal1_m1107_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1107_BLDv0	 1409	//(internal1_m1107_BLDv0) BlDv - Блокировка движения
#define internal1_m613_q0	 BUFFER[9012]	//(internal1_m613_q0) q0 - внутренний параметр
#define idinternal1_m613_q0	 1410	//(internal1_m613_q0) q0 - внутренний параметр
#define internal1_m1192_X0	 BUFFER[9014]	//(internal1_m1192_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1192_X0	 1411	//(internal1_m1192_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1192_t0	 BUFFER[9019]	//(internal1_m1192_t0) время нахождения в зоне возврата
#define idinternal1_m1192_t0	 1412	//(internal1_m1192_t0) время нахождения в зоне возврата
#define internal1_m1192_BLDv0	 BUFFER[9024]	//(internal1_m1192_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1192_BLDv0	 1413	//(internal1_m1192_BLDv0) BlDv - Блокировка движения
#define internal1_m1212_tx	 BUFFER[9025]	//(internal1_m1212_tx) tx - время накопленное сек
#define idinternal1_m1212_tx	 1414	//(internal1_m1212_tx) tx - время накопленное сек
#define internal1_m1212_y0	 BUFFER[9030]	//(internal1_m1212_y0) y0
#define idinternal1_m1212_y0	 1415	//(internal1_m1212_y0) y0
#define internal1_m1220_tx	 BUFFER[9031]	//(internal1_m1220_tx) tx - время накопленное сек
#define idinternal1_m1220_tx	 1416	//(internal1_m1220_tx) tx - время накопленное сек
#define internal1_m1220_y0	 BUFFER[9036]	//(internal1_m1220_y0) y0
#define idinternal1_m1220_y0	 1417	//(internal1_m1220_y0) y0
#define internal1_m1226_xptr	 BUFFER[9037]	//(internal1_m1226_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1226_xptr	 1418	//(internal1_m1226_xptr) указатель текущей позиции в массиве координат
#define internal1_m1226_x0	 BUFFER[9040]	//(internal1_m1226_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1226_x0	 1419	//(internal1_m1226_x0) x0 - массив мгновенных значений координат
#define internal1_m1226_tim0	 BUFFER[9440]	//(internal1_m1226_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1226_tim0	 1420	//(internal1_m1226_tim0) tim0 - массив значений времени цикла
#define internal1_m1226_sumtim	 BUFFER[9840]	//(internal1_m1226_sumtim) sumtim - время в пути
#define idinternal1_m1226_sumtim	 1421	//(internal1_m1226_sumtim) sumtim - время в пути
#define internal1_m1226_StSpeed	 BUFFER[9845]	//(internal1_m1226_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1226_StSpeed	 1422	//(internal1_m1226_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1226_Vz0	 BUFFER[9850]	//(internal1_m1226_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1226_Vz0	 1423	//(internal1_m1226_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1226_flRazg	 BUFFER[9855]	//(internal1_m1226_flRazg) признак разгона/торможения
#define idinternal1_m1226_flRazg	 1424	//(internal1_m1226_flRazg) признак разгона/торможения
#define internal1_m1226_DelSp	 BUFFER[9858]	//(internal1_m1226_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1226_DelSp	 1425	//(internal1_m1226_DelSp) DelSp - время переключения скоростей
#define internal1_m1226_z0	 BUFFER[9863]	//(internal1_m1226_z0) z0 - точка прекращения движения
#define idinternal1_m1226_z0	 1426	//(internal1_m1226_z0) z0 - точка прекращения движения
#define internal1_m1226_txZS	 BUFFER[9868]	//(internal1_m1226_txZS) txZS
#define idinternal1_m1226_txZS	 1427	//(internal1_m1226_txZS) txZS
#define internal1_m1226_tx	 BUFFER[9873]	//(internal1_m1226_tx) tx
#define idinternal1_m1226_tx	 1428	//(internal1_m1226_tx) tx
#define internal1_m1226_txd	 BUFFER[9878]	//(internal1_m1226_txd) txd
#define idinternal1_m1226_txd	 1429	//(internal1_m1226_txd) txd
#define internal1_m1226_txMBl	 BUFFER[9883]	//(internal1_m1226_txMBl) tx
#define idinternal1_m1226_txMBl	 1430	//(internal1_m1226_txMBl) tx
#define internal1_m1226_txBl	 BUFFER[9888]	//(internal1_m1226_txBl) tx
#define idinternal1_m1226_txBl	 1431	//(internal1_m1226_txBl) tx
#define internal1_m1226_Speed0	 BUFFER[9893]	//(internal1_m1226_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1226_Speed0	 1432	//(internal1_m1226_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1226_xz0	 BUFFER[9898]	//(internal1_m1226_xz0) xz0 - новое задание мм
#define idinternal1_m1226_xz0	 1433	//(internal1_m1226_xz0) xz0 - новое задание мм
#define internal1_m1226_tz0	 BUFFER[9903]	//(internal1_m1226_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1226_tz0	 1434	//(internal1_m1226_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1226_Shift0	 BUFFER[9908]	//(internal1_m1226_Shift0) Shift0 - признак самохода
#define idinternal1_m1226_Shift0	 1435	//(internal1_m1226_Shift0) Shift0 - признак самохода
#define internal1_m1226_ShCntlSp0	 BUFFER[9910]	//(internal1_m1226_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1226_ShCntlSp0	 1436	//(internal1_m1226_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1226_ShiftControl	 BUFFER[9912]	//(internal1_m1226_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1226_ShiftControl	 1437	//(internal1_m1226_ShiftControl) ShiftControl - признак самохода
#define internal1_m633_q0	 BUFFER[9914]	//(internal1_m633_q0) q0 - внутренний параметр
#define idinternal1_m633_q0	 1438	//(internal1_m633_q0) q0 - внутренний параметр
#define internal1_m1584_tx	 BUFFER[9916]	//(internal1_m1584_tx) tx - время накопленное сек
#define idinternal1_m1584_tx	 1439	//(internal1_m1584_tx) tx - время накопленное сек
#define internal1_m1584_y0	 BUFFER[9921]	//(internal1_m1584_y0) y0
#define idinternal1_m1584_y0	 1440	//(internal1_m1584_y0) y0
#define internal1_m1586_tx	 BUFFER[9922]	//(internal1_m1586_tx) tx - время накопленное сек
#define idinternal1_m1586_tx	 1441	//(internal1_m1586_tx) tx - время накопленное сек
#define internal1_m1586_y0	 BUFFER[9927]	//(internal1_m1586_y0) y0
#define idinternal1_m1586_y0	 1442	//(internal1_m1586_y0) y0
#define internal1_m1574_DvUp0	 BUFFER[9928]	//(internal1_m1574_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1574_DvUp0	 1443	//(internal1_m1574_DvUp0) - есть команда на движение вперёд
#define internal1_m1574_DvDw0	 BUFFER[9929]	//(internal1_m1574_DvDw0) - есть команда на движение назад
#define idinternal1_m1574_DvDw0	 1444	//(internal1_m1574_DvDw0) - есть команда на движение назад
#define internal1_m1574_FDvUp0	 BUFFER[9930]	//(internal1_m1574_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1574_FDvUp0	 1445	//(internal1_m1574_FDvUp0) - есть команда на движение вперёд
#define internal1_m1574_FDvDw0	 BUFFER[9931]	//(internal1_m1574_FDvDw0) - есть команда на движение назад
#define idinternal1_m1574_FDvDw0	 1446	//(internal1_m1574_FDvDw0) - есть команда на движение назад
#define internal1_m1574_BlDv0	 BUFFER[9932]	//(internal1_m1574_BlDv0) - была блокировка
#define idinternal1_m1574_BlDv0	 1447	//(internal1_m1574_BlDv0) - была блокировка
#define internal1_m1574_Pkv0	 BUFFER[9933]	//(internal1_m1574_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1574_Pkv0	 1448	//(internal1_m1574_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1574_Pkav0	 BUFFER[9934]	//(internal1_m1574_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1574_Pkav0	 1449	//(internal1_m1574_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1574_Zkv0	 BUFFER[9935]	//(internal1_m1574_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1574_Zkv0	 1450	//(internal1_m1574_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1574_Zkav0	 BUFFER[9936]	//(internal1_m1574_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1574_Zkav0	 1451	//(internal1_m1574_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1574_txNm	 BUFFER[9937]	//(internal1_m1574_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1574_txNm	 1452	//(internal1_m1574_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1574_txSm	 BUFFER[9942]	//(internal1_m1574_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1574_txSm	 1453	//(internal1_m1574_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1574_txHr	 BUFFER[9947]	//(internal1_m1574_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1574_txHr	 1454	//(internal1_m1574_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1574_txLd	 BUFFER[9952]	//(internal1_m1574_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1574_txLd	 1455	//(internal1_m1574_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1574_fef	 BUFFER[9957]	//(internal1_m1574_fef) fef
#define idinternal1_m1574_fef	 1456	//(internal1_m1574_fef) fef
#define internal1_m1591_xptr	 BUFFER[9958]	//(internal1_m1591_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1591_xptr	 1457	//(internal1_m1591_xptr) указатель текущей позиции в массиве координат
#define internal1_m1591_x0	 BUFFER[9961]	//(internal1_m1591_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1591_x0	 1458	//(internal1_m1591_x0) x0 - массив мгновенных значений координат
#define internal1_m1591_tim0	 BUFFER[10061]	//(internal1_m1591_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1591_tim0	 1459	//(internal1_m1591_tim0) tim0 - массив значений времени цикла
#define internal1_m1591_sumtim	 BUFFER[10161]	//(internal1_m1591_sumtim) sumtim - время в пути
#define idinternal1_m1591_sumtim	 1460	//(internal1_m1591_sumtim) sumtim - время в пути
#define internal1_m1591_StSpeed	 BUFFER[10166]	//(internal1_m1591_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1591_StSpeed	 1461	//(internal1_m1591_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1591_Vz0	 BUFFER[10171]	//(internal1_m1591_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1591_Vz0	 1462	//(internal1_m1591_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1591_flRazg	 BUFFER[10176]	//(internal1_m1591_flRazg) признак разгона/торможения
#define idinternal1_m1591_flRazg	 1463	//(internal1_m1591_flRazg) признак разгона/торможения
#define internal1_m1591_DelSp	 BUFFER[10179]	//(internal1_m1591_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1591_DelSp	 1464	//(internal1_m1591_DelSp) DelSp - время переключения скоростей
#define internal1_m1591_z0	 BUFFER[10184]	//(internal1_m1591_z0) z0 - точка прекращения движения
#define idinternal1_m1591_z0	 1465	//(internal1_m1591_z0) z0 - точка прекращения движения
#define internal1_m1591_txZS	 BUFFER[10189]	//(internal1_m1591_txZS) txZS
#define idinternal1_m1591_txZS	 1466	//(internal1_m1591_txZS) txZS
#define internal1_m1591_tx	 BUFFER[10194]	//(internal1_m1591_tx) tx
#define idinternal1_m1591_tx	 1467	//(internal1_m1591_tx) tx
#define internal1_m1591_txd	 BUFFER[10199]	//(internal1_m1591_txd) txd
#define idinternal1_m1591_txd	 1468	//(internal1_m1591_txd) txd
#define internal1_m1591_txMBl	 BUFFER[10204]	//(internal1_m1591_txMBl) tx
#define idinternal1_m1591_txMBl	 1469	//(internal1_m1591_txMBl) tx
#define internal1_m1591_txBl	 BUFFER[10209]	//(internal1_m1591_txBl) tx
#define idinternal1_m1591_txBl	 1470	//(internal1_m1591_txBl) tx
#define internal1_m1591_Speed0	 BUFFER[10214]	//(internal1_m1591_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1591_Speed0	 1471	//(internal1_m1591_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1591_xz0	 BUFFER[10219]	//(internal1_m1591_xz0) xz0 - новое задание мм
#define idinternal1_m1591_xz0	 1472	//(internal1_m1591_xz0) xz0 - новое задание мм
#define internal1_m1591_tz0	 BUFFER[10224]	//(internal1_m1591_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1591_tz0	 1473	//(internal1_m1591_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1591_Shift0	 BUFFER[10229]	//(internal1_m1591_Shift0) Shift0 - признак самохода
#define idinternal1_m1591_Shift0	 1474	//(internal1_m1591_Shift0) Shift0 - признак самохода
#define internal1_m1591_ShCntlSp0	 BUFFER[10231]	//(internal1_m1591_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1591_ShCntlSp0	 1475	//(internal1_m1591_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1591_ShiftControl	 BUFFER[10233]	//(internal1_m1591_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1591_ShiftControl	 1476	//(internal1_m1591_ShiftControl) ShiftControl - признак самохода
#define internal1_m1123_tx	 BUFFER[10235]	//(internal1_m1123_tx) tx - время накопленное сек
#define idinternal1_m1123_tx	 1477	//(internal1_m1123_tx) tx - время накопленное сек
#define internal1_m1123_y0	 BUFFER[10240]	//(internal1_m1123_y0) y0
#define idinternal1_m1123_y0	 1478	//(internal1_m1123_y0) y0
#define internal1_m1128_tx	 BUFFER[10241]	//(internal1_m1128_tx) tx - время накопленное сек
#define idinternal1_m1128_tx	 1479	//(internal1_m1128_tx) tx - время накопленное сек
#define internal1_m1128_y0	 BUFFER[10246]	//(internal1_m1128_y0) y0
#define idinternal1_m1128_y0	 1480	//(internal1_m1128_y0) y0
#define internal1_m623_q0	 BUFFER[10247]	//(internal1_m623_q0) q0 - внутренний параметр
#define idinternal1_m623_q0	 1481	//(internal1_m623_q0) q0 - внутренний параметр
#define internal1_m588_q0	 BUFFER[10249]	//(internal1_m588_q0) q0 - внутренний параметр
#define idinternal1_m588_q0	 1482	//(internal1_m588_q0) q0 - внутренний параметр
#define internal1_m1115_DvUp0	 BUFFER[10251]	//(internal1_m1115_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1115_DvUp0	 1483	//(internal1_m1115_DvUp0) - есть команда на движение вперёд
#define internal1_m1115_DvDw0	 BUFFER[10252]	//(internal1_m1115_DvDw0) - есть команда на движение назад
#define idinternal1_m1115_DvDw0	 1484	//(internal1_m1115_DvDw0) - есть команда на движение назад
#define internal1_m1115_FDvUp0	 BUFFER[10253]	//(internal1_m1115_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1115_FDvUp0	 1485	//(internal1_m1115_FDvUp0) - есть команда на движение вперёд
#define internal1_m1115_FDvDw0	 BUFFER[10254]	//(internal1_m1115_FDvDw0) - есть команда на движение назад
#define idinternal1_m1115_FDvDw0	 1486	//(internal1_m1115_FDvDw0) - есть команда на движение назад
#define internal1_m1115_BlDv0	 BUFFER[10255]	//(internal1_m1115_BlDv0) - была блокировка
#define idinternal1_m1115_BlDv0	 1487	//(internal1_m1115_BlDv0) - была блокировка
#define internal1_m1115_Pkv0	 BUFFER[10256]	//(internal1_m1115_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1115_Pkv0	 1488	//(internal1_m1115_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1115_Pkav0	 BUFFER[10257]	//(internal1_m1115_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1115_Pkav0	 1489	//(internal1_m1115_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1115_Zkv0	 BUFFER[10258]	//(internal1_m1115_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1115_Zkv0	 1490	//(internal1_m1115_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1115_Zkav0	 BUFFER[10259]	//(internal1_m1115_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1115_Zkav0	 1491	//(internal1_m1115_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1115_txNm	 BUFFER[10260]	//(internal1_m1115_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1115_txNm	 1492	//(internal1_m1115_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1115_txSm	 BUFFER[10265]	//(internal1_m1115_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1115_txSm	 1493	//(internal1_m1115_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1115_txHr	 BUFFER[10270]	//(internal1_m1115_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1115_txHr	 1494	//(internal1_m1115_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1115_txLd	 BUFFER[10275]	//(internal1_m1115_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1115_txLd	 1495	//(internal1_m1115_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1115_fef	 BUFFER[10280]	//(internal1_m1115_fef) fef
#define idinternal1_m1115_fef	 1496	//(internal1_m1115_fef) fef
#define internal1_m1131_xptr	 BUFFER[10281]	//(internal1_m1131_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1131_xptr	 1497	//(internal1_m1131_xptr) указатель текущей позиции в массиве координат
#define internal1_m1131_x0	 BUFFER[10284]	//(internal1_m1131_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1131_x0	 1498	//(internal1_m1131_x0) x0 - массив мгновенных значений координат
#define internal1_m1131_tim0	 BUFFER[10384]	//(internal1_m1131_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1131_tim0	 1499	//(internal1_m1131_tim0) tim0 - массив значений времени цикла
#define internal1_m1131_sumtim	 BUFFER[10484]	//(internal1_m1131_sumtim) sumtim - время в пути
#define idinternal1_m1131_sumtim	 1500	//(internal1_m1131_sumtim) sumtim - время в пути
#define internal1_m1131_StSpeed	 BUFFER[10489]	//(internal1_m1131_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1131_StSpeed	 1501	//(internal1_m1131_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1131_Vz0	 BUFFER[10494]	//(internal1_m1131_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1131_Vz0	 1502	//(internal1_m1131_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1131_flRazg	 BUFFER[10499]	//(internal1_m1131_flRazg) признак разгона/торможения
#define idinternal1_m1131_flRazg	 1503	//(internal1_m1131_flRazg) признак разгона/торможения
#define internal1_m1131_DelSp	 BUFFER[10502]	//(internal1_m1131_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1131_DelSp	 1504	//(internal1_m1131_DelSp) DelSp - время переключения скоростей
#define internal1_m1131_z0	 BUFFER[10507]	//(internal1_m1131_z0) z0 - точка прекращения движения
#define idinternal1_m1131_z0	 1505	//(internal1_m1131_z0) z0 - точка прекращения движения
#define internal1_m1131_txZS	 BUFFER[10512]	//(internal1_m1131_txZS) txZS
#define idinternal1_m1131_txZS	 1506	//(internal1_m1131_txZS) txZS
#define internal1_m1131_tx	 BUFFER[10517]	//(internal1_m1131_tx) tx
#define idinternal1_m1131_tx	 1507	//(internal1_m1131_tx) tx
#define internal1_m1131_txd	 BUFFER[10522]	//(internal1_m1131_txd) txd
#define idinternal1_m1131_txd	 1508	//(internal1_m1131_txd) txd
#define internal1_m1131_txMBl	 BUFFER[10527]	//(internal1_m1131_txMBl) tx
#define idinternal1_m1131_txMBl	 1509	//(internal1_m1131_txMBl) tx
#define internal1_m1131_txBl	 BUFFER[10532]	//(internal1_m1131_txBl) tx
#define idinternal1_m1131_txBl	 1510	//(internal1_m1131_txBl) tx
#define internal1_m1131_Speed0	 BUFFER[10537]	//(internal1_m1131_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1131_Speed0	 1511	//(internal1_m1131_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1131_xz0	 BUFFER[10542]	//(internal1_m1131_xz0) xz0 - новое задание мм
#define idinternal1_m1131_xz0	 1512	//(internal1_m1131_xz0) xz0 - новое задание мм
#define internal1_m1131_tz0	 BUFFER[10547]	//(internal1_m1131_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1131_tz0	 1513	//(internal1_m1131_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1131_Shift0	 BUFFER[10552]	//(internal1_m1131_Shift0) Shift0 - признак самохода
#define idinternal1_m1131_Shift0	 1514	//(internal1_m1131_Shift0) Shift0 - признак самохода
#define internal1_m1131_ShCntlSp0	 BUFFER[10554]	//(internal1_m1131_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1131_ShCntlSp0	 1515	//(internal1_m1131_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1131_ShiftControl	 BUFFER[10556]	//(internal1_m1131_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1131_ShiftControl	 1516	//(internal1_m1131_ShiftControl) ShiftControl - признак самохода
#define internal1_m736_x0	 BUFFER[10558]	//(internal1_m736_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m736_x0	 1517	//(internal1_m736_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m705_x0	 BUFFER[10560]	//(internal1_m705_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m705_x0	 1518	//(internal1_m705_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m669_x0	 BUFFER[10562]	//(internal1_m669_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m669_x0	 1519	//(internal1_m669_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m761_q0	 BUFFER[10564]	//(internal1_m761_q0) q0 - внутренний параметр
#define idinternal1_m761_q0	 1520	//(internal1_m761_q0) q0 - внутренний параметр
#define internal1_m756_q0	 BUFFER[10566]	//(internal1_m756_q0) q0 - внутренний параметр
#define idinternal1_m756_q0	 1521	//(internal1_m756_q0) q0 - внутренний параметр
#define internal1_m724_q0	 BUFFER[10568]	//(internal1_m724_q0) q0 - внутренний параметр
#define idinternal1_m724_q0	 1522	//(internal1_m724_q0) q0 - внутренний параметр
#define internal1_m729_q0	 BUFFER[10570]	//(internal1_m729_q0) q0 - внутренний параметр
#define idinternal1_m729_q0	 1523	//(internal1_m729_q0) q0 - внутренний параметр
#define internal1_m737_q0	 BUFFER[10572]	//(internal1_m737_q0) q0 - внутренний параметр
#define idinternal1_m737_q0	 1524	//(internal1_m737_q0) q0 - внутренний параметр
#define internal1_m749_q0	 BUFFER[10574]	//(internal1_m749_q0) q0 - внутренний параметр
#define idinternal1_m749_q0	 1525	//(internal1_m749_q0) q0 - внутренний параметр
#define internal1_m727_q0	 BUFFER[10576]	//(internal1_m727_q0) q0 - внутренний параметр
#define idinternal1_m727_q0	 1526	//(internal1_m727_q0) q0 - внутренний параметр
#define internal1_m1168_DvUp0	 BUFFER[10578]	//(internal1_m1168_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1168_DvUp0	 1527	//(internal1_m1168_DvUp0) - есть команда на движение вперёд
#define internal1_m1168_DvDw0	 BUFFER[10579]	//(internal1_m1168_DvDw0) - есть команда на движение назад
#define idinternal1_m1168_DvDw0	 1528	//(internal1_m1168_DvDw0) - есть команда на движение назад
#define internal1_m1168_FDvUp0	 BUFFER[10580]	//(internal1_m1168_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1168_FDvUp0	 1529	//(internal1_m1168_FDvUp0) - есть команда на движение вперёд
#define internal1_m1168_FDvDw0	 BUFFER[10581]	//(internal1_m1168_FDvDw0) - есть команда на движение назад
#define idinternal1_m1168_FDvDw0	 1530	//(internal1_m1168_FDvDw0) - есть команда на движение назад
#define internal1_m1168_BlDv0	 BUFFER[10582]	//(internal1_m1168_BlDv0) - была блокировка
#define idinternal1_m1168_BlDv0	 1531	//(internal1_m1168_BlDv0) - была блокировка
#define internal1_m1168_Pkv0	 BUFFER[10583]	//(internal1_m1168_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1168_Pkv0	 1532	//(internal1_m1168_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1168_Pkav0	 BUFFER[10584]	//(internal1_m1168_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1168_Pkav0	 1533	//(internal1_m1168_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1168_Zkv0	 BUFFER[10585]	//(internal1_m1168_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1168_Zkv0	 1534	//(internal1_m1168_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1168_Zkav0	 BUFFER[10586]	//(internal1_m1168_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1168_Zkav0	 1535	//(internal1_m1168_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1168_txNm	 BUFFER[10587]	//(internal1_m1168_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1168_txNm	 1536	//(internal1_m1168_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1168_txSm	 BUFFER[10592]	//(internal1_m1168_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1168_txSm	 1537	//(internal1_m1168_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1168_txHr	 BUFFER[10597]	//(internal1_m1168_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1168_txHr	 1538	//(internal1_m1168_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1168_txLd	 BUFFER[10602]	//(internal1_m1168_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1168_txLd	 1539	//(internal1_m1168_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1168_fef	 BUFFER[10607]	//(internal1_m1168_fef) fef
#define idinternal1_m1168_fef	 1540	//(internal1_m1168_fef) fef
#define internal1_m1158_DvUp0	 BUFFER[10608]	//(internal1_m1158_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1158_DvUp0	 1541	//(internal1_m1158_DvUp0) - есть команда на движение вперёд
#define internal1_m1158_DvDw0	 BUFFER[10609]	//(internal1_m1158_DvDw0) - есть команда на движение назад
#define idinternal1_m1158_DvDw0	 1542	//(internal1_m1158_DvDw0) - есть команда на движение назад
#define internal1_m1158_FDvUp0	 BUFFER[10610]	//(internal1_m1158_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1158_FDvUp0	 1543	//(internal1_m1158_FDvUp0) - есть команда на движение вперёд
#define internal1_m1158_FDvDw0	 BUFFER[10611]	//(internal1_m1158_FDvDw0) - есть команда на движение назад
#define idinternal1_m1158_FDvDw0	 1544	//(internal1_m1158_FDvDw0) - есть команда на движение назад
#define internal1_m1158_BlDv0	 BUFFER[10612]	//(internal1_m1158_BlDv0) - была блокировка
#define idinternal1_m1158_BlDv0	 1545	//(internal1_m1158_BlDv0) - была блокировка
#define internal1_m1158_Pkv0	 BUFFER[10613]	//(internal1_m1158_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1158_Pkv0	 1546	//(internal1_m1158_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1158_Pkav0	 BUFFER[10614]	//(internal1_m1158_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1158_Pkav0	 1547	//(internal1_m1158_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1158_Zkv0	 BUFFER[10615]	//(internal1_m1158_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1158_Zkv0	 1548	//(internal1_m1158_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1158_Zkav0	 BUFFER[10616]	//(internal1_m1158_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1158_Zkav0	 1549	//(internal1_m1158_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1158_txNm	 BUFFER[10617]	//(internal1_m1158_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1158_txNm	 1550	//(internal1_m1158_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1158_txSm	 BUFFER[10622]	//(internal1_m1158_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1158_txSm	 1551	//(internal1_m1158_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1158_txHr	 BUFFER[10627]	//(internal1_m1158_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1158_txHr	 1552	//(internal1_m1158_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1158_txLd	 BUFFER[10632]	//(internal1_m1158_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1158_txLd	 1553	//(internal1_m1158_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1158_fef	 BUFFER[10637]	//(internal1_m1158_fef) fef
#define idinternal1_m1158_fef	 1554	//(internal1_m1158_fef) fef
#define internal1_m781_DvUp0	 BUFFER[10638]	//(internal1_m781_DvUp0) - есть команда на движение вперёд
#define idinternal1_m781_DvUp0	 1555	//(internal1_m781_DvUp0) - есть команда на движение вперёд
#define internal1_m781_DvDw0	 BUFFER[10639]	//(internal1_m781_DvDw0) - есть команда на движение назад
#define idinternal1_m781_DvDw0	 1556	//(internal1_m781_DvDw0) - есть команда на движение назад
#define internal1_m781_FDvUp0	 BUFFER[10640]	//(internal1_m781_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m781_FDvUp0	 1557	//(internal1_m781_FDvUp0) - есть команда на движение вперёд
#define internal1_m781_FDvDw0	 BUFFER[10641]	//(internal1_m781_FDvDw0) - есть команда на движение назад
#define idinternal1_m781_FDvDw0	 1558	//(internal1_m781_FDvDw0) - есть команда на движение назад
#define internal1_m781_BlDv0	 BUFFER[10642]	//(internal1_m781_BlDv0) - была блокировка
#define idinternal1_m781_BlDv0	 1559	//(internal1_m781_BlDv0) - была блокировка
#define internal1_m781_Pkv0	 BUFFER[10643]	//(internal1_m781_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m781_Pkv0	 1560	//(internal1_m781_Pkv0) Pkv - передний конечный выключатель
#define internal1_m781_Pkav0	 BUFFER[10644]	//(internal1_m781_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m781_Pkav0	 1561	//(internal1_m781_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m781_Zkv0	 BUFFER[10645]	//(internal1_m781_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m781_Zkv0	 1562	//(internal1_m781_Zkv0) Zkv - задний конечный выключатель
#define internal1_m781_Zkav0	 BUFFER[10646]	//(internal1_m781_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m781_Zkav0	 1563	//(internal1_m781_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m781_txNm	 BUFFER[10647]	//(internal1_m781_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m781_txNm	 1564	//(internal1_m781_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m781_txSm	 BUFFER[10652]	//(internal1_m781_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m781_txSm	 1565	//(internal1_m781_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m781_txHr	 BUFFER[10657]	//(internal1_m781_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m781_txHr	 1566	//(internal1_m781_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m781_txLd	 BUFFER[10662]	//(internal1_m781_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m781_txLd	 1567	//(internal1_m781_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m781_fef	 BUFFER[10667]	//(internal1_m781_fef) fef
#define idinternal1_m781_fef	 1568	//(internal1_m781_fef) fef
#define internal1_m777_DvUp0	 BUFFER[10668]	//(internal1_m777_DvUp0) - есть команда на движение вперёд
#define idinternal1_m777_DvUp0	 1569	//(internal1_m777_DvUp0) - есть команда на движение вперёд
#define internal1_m777_DvDw0	 BUFFER[10669]	//(internal1_m777_DvDw0) - есть команда на движение назад
#define idinternal1_m777_DvDw0	 1570	//(internal1_m777_DvDw0) - есть команда на движение назад
#define internal1_m777_FDvUp0	 BUFFER[10670]	//(internal1_m777_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m777_FDvUp0	 1571	//(internal1_m777_FDvUp0) - есть команда на движение вперёд
#define internal1_m777_FDvDw0	 BUFFER[10671]	//(internal1_m777_FDvDw0) - есть команда на движение назад
#define idinternal1_m777_FDvDw0	 1572	//(internal1_m777_FDvDw0) - есть команда на движение назад
#define internal1_m777_BlDv0	 BUFFER[10672]	//(internal1_m777_BlDv0) - была блокировка
#define idinternal1_m777_BlDv0	 1573	//(internal1_m777_BlDv0) - была блокировка
#define internal1_m777_Pkv0	 BUFFER[10673]	//(internal1_m777_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m777_Pkv0	 1574	//(internal1_m777_Pkv0) Pkv - передний конечный выключатель
#define internal1_m777_Pkav0	 BUFFER[10674]	//(internal1_m777_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m777_Pkav0	 1575	//(internal1_m777_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m777_Zkv0	 BUFFER[10675]	//(internal1_m777_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m777_Zkv0	 1576	//(internal1_m777_Zkv0) Zkv - задний конечный выключатель
#define internal1_m777_Zkav0	 BUFFER[10676]	//(internal1_m777_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m777_Zkav0	 1577	//(internal1_m777_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m777_txNm	 BUFFER[10677]	//(internal1_m777_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m777_txNm	 1578	//(internal1_m777_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m777_txSm	 BUFFER[10682]	//(internal1_m777_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m777_txSm	 1579	//(internal1_m777_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m777_txHr	 BUFFER[10687]	//(internal1_m777_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m777_txHr	 1580	//(internal1_m777_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m777_txLd	 BUFFER[10692]	//(internal1_m777_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m777_txLd	 1581	//(internal1_m777_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m777_fef	 BUFFER[10697]	//(internal1_m777_fef) fef
#define idinternal1_m777_fef	 1582	//(internal1_m777_fef) fef
#define internal1_m359_DvUp0	 BUFFER[10698]	//(internal1_m359_DvUp0) - есть команда на движение вперёд
#define idinternal1_m359_DvUp0	 1583	//(internal1_m359_DvUp0) - есть команда на движение вперёд
#define internal1_m359_DvDw0	 BUFFER[10699]	//(internal1_m359_DvDw0) - есть команда на движение назад
#define idinternal1_m359_DvDw0	 1584	//(internal1_m359_DvDw0) - есть команда на движение назад
#define internal1_m359_FDvUp0	 BUFFER[10700]	//(internal1_m359_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m359_FDvUp0	 1585	//(internal1_m359_FDvUp0) - есть команда на движение вперёд
#define internal1_m359_FDvDw0	 BUFFER[10701]	//(internal1_m359_FDvDw0) - есть команда на движение назад
#define idinternal1_m359_FDvDw0	 1586	//(internal1_m359_FDvDw0) - есть команда на движение назад
#define internal1_m359_BlDv0	 BUFFER[10702]	//(internal1_m359_BlDv0) - была блокировка
#define idinternal1_m359_BlDv0	 1587	//(internal1_m359_BlDv0) - была блокировка
#define internal1_m359_Pkv0	 BUFFER[10703]	//(internal1_m359_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m359_Pkv0	 1588	//(internal1_m359_Pkv0) Pkv - передний конечный выключатель
#define internal1_m359_Pkav0	 BUFFER[10704]	//(internal1_m359_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m359_Pkav0	 1589	//(internal1_m359_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m359_Zkv0	 BUFFER[10705]	//(internal1_m359_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m359_Zkv0	 1590	//(internal1_m359_Zkv0) Zkv - задний конечный выключатель
#define internal1_m359_Zkav0	 BUFFER[10706]	//(internal1_m359_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m359_Zkav0	 1591	//(internal1_m359_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m359_txNm	 BUFFER[10707]	//(internal1_m359_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m359_txNm	 1592	//(internal1_m359_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m359_txSm	 BUFFER[10712]	//(internal1_m359_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m359_txSm	 1593	//(internal1_m359_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m359_txHr	 BUFFER[10717]	//(internal1_m359_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m359_txHr	 1594	//(internal1_m359_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m359_txLd	 BUFFER[10722]	//(internal1_m359_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m359_txLd	 1595	//(internal1_m359_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m359_fef	 BUFFER[10727]	//(internal1_m359_fef) fef
#define idinternal1_m359_fef	 1596	//(internal1_m359_fef) fef
#define internal1_m388_DvUp0	 BUFFER[10728]	//(internal1_m388_DvUp0) - есть команда на движение вперёд
#define idinternal1_m388_DvUp0	 1597	//(internal1_m388_DvUp0) - есть команда на движение вперёд
#define internal1_m388_DvDw0	 BUFFER[10729]	//(internal1_m388_DvDw0) - есть команда на движение назад
#define idinternal1_m388_DvDw0	 1598	//(internal1_m388_DvDw0) - есть команда на движение назад
#define internal1_m388_FDvUp0	 BUFFER[10730]	//(internal1_m388_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m388_FDvUp0	 1599	//(internal1_m388_FDvUp0) - есть команда на движение вперёд
#define internal1_m388_FDvDw0	 BUFFER[10731]	//(internal1_m388_FDvDw0) - есть команда на движение назад
#define idinternal1_m388_FDvDw0	 1600	//(internal1_m388_FDvDw0) - есть команда на движение назад
#define internal1_m388_BlDv0	 BUFFER[10732]	//(internal1_m388_BlDv0) - была блокировка
#define idinternal1_m388_BlDv0	 1601	//(internal1_m388_BlDv0) - была блокировка
#define internal1_m388_Pkv0	 BUFFER[10733]	//(internal1_m388_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m388_Pkv0	 1602	//(internal1_m388_Pkv0) Pkv - передний конечный выключатель
#define internal1_m388_Pkav0	 BUFFER[10734]	//(internal1_m388_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m388_Pkav0	 1603	//(internal1_m388_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m388_Zkv0	 BUFFER[10735]	//(internal1_m388_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m388_Zkv0	 1604	//(internal1_m388_Zkv0) Zkv - задний конечный выключатель
#define internal1_m388_Zkav0	 BUFFER[10736]	//(internal1_m388_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m388_Zkav0	 1605	//(internal1_m388_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m388_txNm	 BUFFER[10737]	//(internal1_m388_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m388_txNm	 1606	//(internal1_m388_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m388_txSm	 BUFFER[10742]	//(internal1_m388_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m388_txSm	 1607	//(internal1_m388_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m388_txHr	 BUFFER[10747]	//(internal1_m388_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m388_txHr	 1608	//(internal1_m388_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m388_txLd	 BUFFER[10752]	//(internal1_m388_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m388_txLd	 1609	//(internal1_m388_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m388_fef	 BUFFER[10757]	//(internal1_m388_fef) fef
#define idinternal1_m388_fef	 1610	//(internal1_m388_fef) fef
#define internal1_m382_DvUp0	 BUFFER[10758]	//(internal1_m382_DvUp0) - есть команда на движение вперёд
#define idinternal1_m382_DvUp0	 1611	//(internal1_m382_DvUp0) - есть команда на движение вперёд
#define internal1_m382_DvDw0	 BUFFER[10759]	//(internal1_m382_DvDw0) - есть команда на движение назад
#define idinternal1_m382_DvDw0	 1612	//(internal1_m382_DvDw0) - есть команда на движение назад
#define internal1_m382_FDvUp0	 BUFFER[10760]	//(internal1_m382_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m382_FDvUp0	 1613	//(internal1_m382_FDvUp0) - есть команда на движение вперёд
#define internal1_m382_FDvDw0	 BUFFER[10761]	//(internal1_m382_FDvDw0) - есть команда на движение назад
#define idinternal1_m382_FDvDw0	 1614	//(internal1_m382_FDvDw0) - есть команда на движение назад
#define internal1_m382_BlDv0	 BUFFER[10762]	//(internal1_m382_BlDv0) - была блокировка
#define idinternal1_m382_BlDv0	 1615	//(internal1_m382_BlDv0) - была блокировка
#define internal1_m382_Pkv0	 BUFFER[10763]	//(internal1_m382_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m382_Pkv0	 1616	//(internal1_m382_Pkv0) Pkv - передний конечный выключатель
#define internal1_m382_Pkav0	 BUFFER[10764]	//(internal1_m382_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m382_Pkav0	 1617	//(internal1_m382_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m382_Zkv0	 BUFFER[10765]	//(internal1_m382_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m382_Zkv0	 1618	//(internal1_m382_Zkv0) Zkv - задний конечный выключатель
#define internal1_m382_Zkav0	 BUFFER[10766]	//(internal1_m382_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m382_Zkav0	 1619	//(internal1_m382_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m382_txNm	 BUFFER[10767]	//(internal1_m382_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m382_txNm	 1620	//(internal1_m382_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m382_txSm	 BUFFER[10772]	//(internal1_m382_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m382_txSm	 1621	//(internal1_m382_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m382_txHr	 BUFFER[10777]	//(internal1_m382_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m382_txHr	 1622	//(internal1_m382_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m382_txLd	 BUFFER[10782]	//(internal1_m382_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m382_txLd	 1623	//(internal1_m382_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m382_fef	 BUFFER[10787]	//(internal1_m382_fef) fef
#define idinternal1_m382_fef	 1624	//(internal1_m382_fef) fef
#define internal1_m733_q0	 BUFFER[10788]	//(internal1_m733_q0) q0 - внутренний параметр
#define idinternal1_m733_q0	 1625	//(internal1_m733_q0) q0 - внутренний параметр
#define internal1_m730_q0	 BUFFER[10790]	//(internal1_m730_q0) q0 - внутренний параметр
#define idinternal1_m730_q0	 1626	//(internal1_m730_q0) q0 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &B3IS33LDU},	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
	{ 2	,1	,1	, &B3IS35LDU},	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
	{ 3	,1	,1	, &B4IS10LDU},	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
	{ 4	,1	,1	, &R6IS31LDU},	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
	{ 5	,1	,1	, &R6IS32LDU},	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
	{ 6	,1	,1	, &R6IS42LDU},	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
	{ 7	,1	,1	, &R6IS41LDU},	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
	{ 8	,1	,1	, &R6IS52LDU},	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
	{ 9	,1	,1	, &R6IS51LDU},	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
	{ 10	,1	,1	, &R3IS11LDU},	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
	{ 11	,1	,1	, &R3IS21LDU},	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
	{ 12	,1	,1	, &R0AB03LDU},	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
	{ 13	,1	,1	, &R0AB05LDU},	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
	{ 14	,8	,1	, &R0VN11RZ1},	//( - , MDuBz1) Средняя мощность по BAZ1
	{ 15	,8	,1	, &R0VN11RZ2},	//( - , MDuBz2) Средняя мощность по BAZ2
	{ 16	,1	,1	, &A2AB15LDU},	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{ 17	,1	,1	, &B2AB15LDU},	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{ 18	,1	,1	, &R0AD21LDU},	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
	{ 19	,1	,1	, &R0VX02LDU},	//( - , DU) Импульс разрешен
	{ 20	,1	,1	, &R0EE03LDU},	//( - , DU) ВПИС ИС
	{ 21	,1	,1	, &R0AB07LDU},	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
	{ 22	,1	,1	, &R0AD16LDU},	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
	{ 23	,1	,1	, &C2MD31LP1},	//( - , DU) Кнопка СБРОС РБ
	{ 24	,1	,1	, &B7AZ03LDU},	//( - , DU) Несанкционированное включение обдува АЗ2
	{ 25	,1	,1	, &B3MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
	{ 26	,1	,1	, &B3MD11LP1},	//( - , DU) Кнопка ПУСК ИС2
	{ 27	,8	,1	, &R0VL01RDU},	//( - , DU) Индикация Время задержки
	{ 28	,1	,1	, &R0VZ71LZ2},	//(vds32:03 - K22VDSR, DU) Обобщенный сигнал АЗ 2 канала
	{ 29	,1	,1	, &R0VZ71LZ1},	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
	{ 30	,1	,1	, &R0VZ71LDU},	//( - , DU) Обобщенный сигнал АЗ
	{ 31	,1	,1	, &A2IS33LDU},	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
	{ 32	,1	,1	, &A3IS31LDU},	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
	{ 33	,1	,1	, &A3IS33LDU},	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
	{ 34	,1	,1	, &A3IS35LDU},	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
	{ 35	,1	,1	, &A4IS10LDU},	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
	{ 36	,1	,1	, &A1VN71LZ1},	//(vds32:02 - K21VDSR, - ) Блокировка автоматического подъёма ББ
	{ 37	,1	,1	, &A1VN71LZ2},	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{ 38	,1	,1	, &A1AB19LDU},	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
	{ 39	,1	,1	, &R0AD14LZ1},	//(vds32:02 - K20VDSR, - ) Имитация срабатывания АЗ от II УР
	{ 40	,1	,1	, &R0AD14LZ2},	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
	{ 41	,1	,1	, &A3VZ13LZ2},	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{ 42	,1	,1	, &A3VZ13LZ1},	//(vds32:02 - K18VDSR, - ) Имитация срабатывания АЗ от ВУ ИС
	{ 43	,1	,1	, &A3VZ15LZ1},	//(vds32:02 - K19VDSR, - ) Имитация срабатывания АЗ от НУП ИС
	{ 44	,1	,1	, &A3VZ15LZ2},	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{ 45	,1	,1	, &B2IS33LDU},	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
	{ 46	,1	,1	, &B3IS31LDU},	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
	{ 47	,8	,1	, &B3MC01RP1},	//( - , DU) Заданная координата положения ИС2 мм
	{ 48	,8	,1	, &B8MC01RP2},	//( - , DU) Заданная координата АЗ2 мм
	{ 49	,1	,1	, &R0AB09LDU},	//( - , DU) Ошибка в заданной координате ББ1
	{ 50	,1	,1	, &R0AB10LDU},	//( - , DU) Ошибка в заданной координате ББ2
	{ 51	,1	,1	, &R0AB11LDU},	//( - , DU) Ошибка в заданной координате  ИС1
	{ 52	,1	,1	, &R0AB12LDU},	//( - , DU) Ошибка в заданной координате  ИС2
	{ 53	,1	,1	, &R0AB13LDU},	//( - , DU) Ошибка в заданной координате  АЗ2
	{ 54	,1	,1	, &A4ZAV},	//( - , DU) 
	{ 55	,1	,1	, &A6ZAV},	//( - , DU) 
	{ 56	,1	,1	, &R2ZAV},	//( - , DU) 
	{ 57	,1	,1	, &A5ZAV},	//( - , DU) 
	{ 58	,1	,1	, &B8ZAV},	//( - , DU) 
	{ 59	,1	,1	, &A2ZAV},	//( - , DU) Завершение РБ1,2
	{ 60	,1	,1	, &A8ZAV},	//( - , DU) 
	{ 61	,1	,1	, &A9ZAV},	//( - , DU) Завершение НИ ДС1(2)
	{ 62	,1	,1	, &R4ABL},	//( - , DU) Блокировка тележки -
	{ 63	,1	,1	, &A4UP},	//( - , DU) 
	{ 64	,1	,1	, &A4DW},	//( - , DU) 
	{ 65	,1	,1	, &R0AB14LDU},	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
	{ 66	,1	,1	, &R0AB15LDU},	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
	{ 67	,1	,1	, &A3IS12LDU},	//( - , DU) Приход на ВУ штока ИС1
	{ 68	,1	,1	, &B3IS12LDU},	//( - , DU) Приход на ВУ штока ИС2
	{ 69	,1	,1	, &A1ZAV},	//( - , DU) 
	{ 70	,3	,1	, &B6VS01IDU},	//( - , DU) Готовность к управлению БЗ2
	{ 71	,1	,1	, &R2AD20LDU},	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
	{ 72	,1	,1	, &R2AD10LDU},	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
	{ 73	,3	,1	, &B8VS01IDU},	//( - , DU) Готовность к управлению АЗ2
	{ 74	,3	,1	, &A8VS01IDU},	//( - , DU) Готовность к управлению ДС2
	{ 75	,1	,1	, &A1IE03LDU},	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
	{ 76	,1	,1	, &A1IE04LDU},	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
	{ 77	,1	,1	, &A2IE03LDU},	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
	{ 78	,1	,1	, &A2IE04LDU},	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
	{ 79	,1	,1	, &A3IE03LDU},	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
	{ 80	,1	,1	, &A3IE04LDU},	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
	{ 81	,1	,1	, &B1IE03LDU},	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
	{ 82	,1	,1	, &B1IE04LDU},	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
	{ 83	,1	,1	, &B2IE03LDU},	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
	{ 84	,1	,1	, &B2IE04LDU},	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
	{ 85	,1	,1	, &B3IE03LDU},	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
	{ 86	,1	,1	, &B3IE04LDU},	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
	{ 87	,1	,1	, &R0VS11LDU},	//( - , DU) РУ не готова к работе
	{ 88	,1	,1	, &B6AB05LDU},	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
	{ 89	,1	,1	, &R0AB08LDU},	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
	{ 90	,8	,1	, &A1MC01RP1},	//( - , DU) Заданная координата положения ББ1 мм
	{ 91	,8	,1	, &B1MC01RP1},	//( - , DU) Заданная координата положения ББ2  мм
	{ 92	,8	,1	, &A3MC01RP1},	//( - , DU) Заданная координата положения ИС1 мм
	{ 93	,3	,1	, &R2VS01IDU},	//( - , DU) Готовность к управлению МДЗ2
	{ 94	,3	,1	, &R1VS01IDU},	//( - , DU) Готовность к управлению МДЗ1
	{ 95	,1	,1	, &A9IS11LDU},	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
	{ 96	,1	,1	, &A9IS21LDU},	//(vds32:02 - K24VDSR, - ) Приход на НУ НИ ДС1
	{ 97	,1	,1	, &B9IS11LDU},	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
	{ 98	,1	,1	, &B9IS21LDU},	//(vds32:02 - K26VDSR, - ) Приход на НУ НИ ДС2
	{ 99	,1	,1	, &B9AD10LDU},	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
	{ 100	,1	,1	, &A9AD10LDU},	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
	{ 101	,1	,1	, &A9AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ ДС1
	{ 102	,1	,1	, &A9AB01LDU},	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
	{ 103	,1	,1	, &A9AB02LDU},	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
	{ 104	,1	,1	, &B9AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ ДС2
	{ 105	,1	,1	, &B9AB01LDU},	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
	{ 106	,1	,1	, &B9AB02LDU},	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
	{ 107	,1	,1	, &R0AB01LDU},	//( - , DU) Режим проверки разрешён
	{ 108	,1	,1	, &A3IS22LDU},	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
	{ 109	,1	,1	, &B3IS22LDU},	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
	{ 110	,1	,1	, &A2AD33LDU},	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
	{ 111	,1	,1	, &B2AD33LDU},	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
	{ 112	,1	,1	, &A3AD33LDU},	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
	{ 113	,1	,1	, &A3AD34LDU},	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
	{ 114	,1	,1	, &A3AD31LDU},	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
	{ 115	,1	,1	, &B3AD34LDU},	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
	{ 116	,1	,1	, &R0AB04LDU},	//( - , DU) Нарушение времени срабатывания верхней АС II УР
	{ 117	,1	,1	, &R0AB06LDU},	//( - , DU) Нарушение времени задержки от ВУ РБ
	{ 118	,1	,1	, &R0AB02LDU},	//( - , DU) Нарушение времени задержки ИНИ
	{ 119	,8	,1	, &R0VL03RDU},	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
	{ 120	,8	,1	, &R0VL05RDU},	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
	{ 121	,3	,1	, &R0VL21IDU},	//( - , DU) Декатрон
	{ 122	,1	,1	, &R0VX03LDU},	//( - , DU) Готовность 2 мин
	{ 123	,3	,1	, &R0VS21IDU},	//( - , DU) Индикация ВИД ПРОВЕРКИ
	{ 124	,3	,1	, &A1VS01IDU},	//( - , DU) Готовность к управлению ББ1
	{ 125	,3	,1	, &B1VS01IDU},	//( - , DU) Готовность к управлению ББ2
	{ 126	,3	,1	, &A3VS01IDU},	//( - , DU) Готовность к управлению ИС1
	{ 127	,3	,1	, &B3VS01IDU},	//( - , DU) Готовность к управлению ИС2
	{ 128	,3	,1	, &A2VS01IDU},	//( - , DU) Готовность к управлению РБ1
	{ 129	,3	,1	, &A4VS01IDU},	//( - , DU) Готовность к управлению НИ1
	{ 130	,1	,1	, &A4VS12LDU},	//( - , DU) Движение НИ1 в сторону ВУ
	{ 131	,1	,1	, &A4VS22LDU},	//( - , DU) Движение НИ1 в сторону НУ
	{ 132	,3	,1	, &B4VS01IDU},	//( - , DU) Готовность к управлению НИ2
	{ 133	,1	,1	, &B4VS12LDU},	//( - , DU) Движение НИ2 в сторону ВУ
	{ 134	,1	,1	, &B4VS22LDU},	//( - , DU) Движение НИ2 в сторону НУ
	{ 135	,3	,1	, &A5VS01IDU},	//( - , DU) Готовность к управлению НЛ1
	{ 136	,3	,1	, &B5VS01IDU},	//( - , DU) Готовность к управлению НЛ2
	{ 137	,3	,1	, &A6VS01IDU},	//( - , DU) Готовность к управлению БЗ1
	{ 138	,3	,1	, &R4VS01IDU},	//( - , DU) Готовность к управлению тележкой реактора
	{ 139	,1	,1	, &R0VS18LDU},	//( - , DU) Индикация  Проверка схем сброса
	{ 140	,1	,1	, &B1MD11LP1},	//( - , DU) Кнопка ПУСК ББ2
	{ 141	,1	,1	, &B1MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
	{ 142	,1	,1	, &B2MD11LP1},	//( - , DU) Кнопка ПУСК РБ2
	{ 143	,1	,1	, &B2MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
	{ 144	,1	,1	, &A2MD11LP1},	//( - , DU) Кнопка ПУСК РБ1
	{ 145	,1	,1	, &A2MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
	{ 146	,1	,1	, &R0IS01LDU},	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
	{ 147	,1	,1	, &R0IS02LDU},	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
	{ 148	,1	,1	, &R0VP73LZ1},	//( - , MDuBz1) ПС давления для РУ
	{ 149	,1	,1	, &R0VP73LZ2},	//( - , MDuBz2) ПС давления для РУ
	{ 150	,1	,1	, &R0VP73LDU},	//( - , DU) ПС давления для РУ
	{ 151	,1	,1	, &R0MD34LP1},	//( - , DU) Кнопка КВИТИРОВАТЬ
	{ 152	,1	,1	, &A0VT71LZ1},	//( - , MDuBz1) АС по температуре в АЗ1
	{ 153	,1	,1	, &B0VT71LZ1},	//( - , MDuBz1) АС по температуре в АЗ2
	{ 154	,1	,1	, &A0VT71LZ2},	//( - , MDuBz2) АС по температуре в АЗ1
	{ 155	,1	,1	, &B0VT71LZ2},	//( - , MDuBz2) АС по температуре в АЗ2
	{ 156	,1	,1	, &B2VS11LDU},	//( - , DU) Движение РБ2 в сторону ВУ
	{ 157	,1	,1	, &B2VS21LDU},	//( - , DU) Движение РБ2 в сторону НУ
	{ 158	,3	,1	, &B2VS01IDU},	//( - , DU) Готовность к управлению РБ2
	{ 159	,1	,1	, &A7AS31LDU},	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
	{ 160	,1	,1	, &B7AS31LDU},	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
	{ 161	,1	,1	, &A7AZ03LDU},	//( - , DU) Несанкционированное включение обдува АЗ1
	{ 162	,1	,1	, &B3AD31LDU},	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
	{ 163	,1	,1	, &A2IS11LDU},	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
	{ 164	,1	,1	, &B2IS11LDU},	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
	{ 165	,1	,1	, &A3MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
	{ 166	,1	,1	, &A3MD11LP1},	//( - , DU) Кнопка ПУСК ИС1
	{ 167	,1	,1	, &R0MD33LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
	{ 168	,1	,1	, &A1MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
	{ 169	,1	,1	, &A1MD11LP1},	//( - , DU) Кнопка ПУСК ББ1
	{ 170	,3	,1	, &R0MW14IP2},	//( - , DU) Переключатель ОБДУВ
	{ 171	,1	,1	, &A7AP31LDU},	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
	{ 172	,1	,1	, &B7AP31LDU},	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
	{ 173	,3	,1	, &R0MW12IP2},	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
	{ 174	,1	,1	, &R0MW17LP1},	//( - , DU) Переключатель АВТ/Р
	{ 175	,1	,1	, &R0VW13LDU},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
	{ 176	,1	,1	, &R0VW23LDU},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
	{ 177	,3	,1	, &R0VX08IDU},	//( - , DU) Индикация Режим
	{ 178	,1	,1	, &R0VX09LDU},	//( - , DU) Индикация регулятор мощности включен/отключен
	{ 179	,1	,1	, &R0VS17LDU},	//( - , DU) Индикация выбора АВТОМАТ
	{ 180	,1	,1	, &A2VS32LDU},	//( - , DU) Индикация  СБРОС РБ1
	{ 181	,1	,1	, &B2VS32LDU},	//( - , DU) Индикация  СБРОС РБ2
	{ 182	,1	,1	, &A3VX01LDU},	//( - , DU) Индикация Выстрел ИС1
	{ 183	,1	,1	, &A3IS11LDU},	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
	{ 184	,1	,1	, &B3VX01LDU},	//( - , DU) Индикация Выстрел ИС2
	{ 185	,1	,1	, &A3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
	{ 186	,1	,1	, &B3VP42LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
	{ 187	,8	,1	, &B3CP02RDU},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
	{ 188	,1	,1	, &B3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
	{ 189	,1	,1	, &B3VP82LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
	{ 190	,1	,1	, &A3VP82LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
	{ 191	,3	,1	, &A3IP02IDU},	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
	{ 192	,3	,1	, &B3IP02IDU},	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
	{ 193	,1	,1	, &A0VE01LDU},	//( - , DU) Напряжение в системы АЗ1 подано
	{ 194	,1	,1	, &B0VE01LDU},	//( - , DU) Напряжение в системы АЗ2 подано
	{ 195	,1	,1	, &A0VP01LDU},	//( - , DU) Давление в системы АЗ1 подано
	{ 196	,1	,1	, &B0VP01LDU},	//( - , DU) Давление в системы АЗ2 подано
	{ 197	,1	,1	, &A0EE01LZ1},	//( - , MDuBz1) Исправность АКНП1
	{ 198	,1	,1	, &A0EE03LZ1},	//( - , MDuBz1) Исправность АКНП3
	{ 199	,1	,1	, &A0EE02LZ1},	//( - , MDuBz1) Исправность АКНП2
	{ 200	,1	,1	, &A0EE04LZ1},	//( - , MDuBz1) Исправность АКНП4
	{ 201	,1	,1	, &A0VN01LDU},	//( - , DU) Каналы АЗ1 проверены
	{ 202	,1	,1	, &B0VN01LDU},	//( - , DU) Каналы АЗ2 проверены
	{ 203	,1	,1	, &A0EE01LZ2},	//( - , MDuBz2) Исправность АКНП1
	{ 204	,1	,1	, &A0EE03LZ2},	//( - , MDuBz2) Исправность АКНП3
	{ 205	,1	,1	, &A0EE02LZ2},	//( - , MDuBz2) Исправность АКНП2
	{ 206	,1	,1	, &A0EE04LZ2},	//( - , MDuBz2) Исправность АКНП4
	{ 207	,1	,1	, &A0VP71LZ1},	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
	{ 208	,8	,1	, &A8VC01RDU},	//( - , DU) Координата ДС2, мм
	{ 209	,5	,1	, &B8IC01UDU},	//( - , MDuS) Координата АЗ2 (дел.энк)
	{ 210	,5	,1	, &A1IC01UDU},	//( - , MDuS) Координата штока ББ1 (дел.энк)
	{ 211	,8	,1	, &A1VC01RDU},	//( - , DU) Координата ББ1, мм
	{ 212	,1	,1	, &A1IS11LDU},	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
	{ 213	,1	,1	, &B1MC01LC1},	//( - , DU) Настроить энкодер ББ2
	{ 214	,1	,1	, &B1MC01LC2},	//( - , DU) Настроить энкодер ББ2
	{ 215	,1	,1	, &A1MC01LC1},	//( - , DU) Настроить энкодер ББ1
	{ 216	,1	,1	, &A1MC01LC2},	//( - , DU) Настроить энкодер ББ1
	{ 217	,1	,1	, &B2MC01LC1},	//( - , DU) Настроить энкодер РБ2
	{ 218	,1	,1	, &B2MC01LC2},	//( - , DU) Настроить энкодер РБ2
	{ 219	,1	,1	, &A2MC01LC1},	//( - , DU) Настроить энкодер РБ1
	{ 220	,1	,1	, &A2MC01LC2},	//( - , DU) Настроить энкодер РБ1
	{ 221	,1	,1	, &B3MC01LC1},	//( - , DU) Настроить энкодер ИС2
	{ 222	,1	,1	, &B3MC01LC2},	//( - , DU) Настроить энкодер ИС2
	{ 223	,1	,1	, &A3MC01LC1},	//( - , DU) Настроить энкодер ИС1
	{ 224	,1	,1	, &A3MC01LC2},	//( - , DU) Настроить энкодер ИС1
	{ 225	,1	,1	, &B8MC01LC1},	//( - , DU) Настроить энкодер АЗ2
	{ 226	,1	,1	, &B8MC01LC2},	//( - , DU) Настроить энкодер АЗ2
	{ 227	,1	,1	, &A8MC01LC1},	//( - , DU) Настроить энкодер ДС2
	{ 228	,1	,1	, &A8MC01LC2},	//( - , DU) Настроить энкодер ДС2
	{ 229	,1	,1	, &A3VP42LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
	{ 230	,8	,1	, &A3CP02RDU},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
	{ 231	,1	,1	, &A5IE02LDU},	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
	{ 232	,1	,1	, &R1IE01LDU},	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
	{ 233	,1	,1	, &R2IE01LDU},	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
	{ 234	,1	,1	, &R6IS61LDU},	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
	{ 235	,1	,1	, &R6IS64LDU},	//( - , MDuS) Исправность ВИП ССДИ-35 1канал
	{ 236	,1	,1	, &R6IS65LDU},	//( - , MDuS) Исправность ВИП ССДИ-35 2канал
	{ 237	,1	,1	, &R6IS62LDU},	//( - , MDuS) Исправность ВИП ССДИ-39 1канал
	{ 238	,1	,1	, &R6IS63LDU},	//( - , MDuS) Исправность ВИП ССДИ-39 2канал
	{ 239	,1	,1	, &R6IS66LZZ},	//( - , MDuS) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 240	,1	,1	, &R6IS67LZZ},	//( - , MDuS) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 241	,1	,1	, &R6IS68LZZ},	//( - , MDuS) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 242	,1	,1	, &syn_R0EE03LDU},	//( - , DU) ВПИС ИС
	{ 243	,8	,1	, &A3VC01RDU},	//( - , DU) Координата ИС1, мм
	{ 244	,8	,1	, &A2VC01RDU},	//( - , DU) Координата РБ1, мм
	{ 245	,8	,1	, &B2VC01RDU},	//( - , DU) Координата РБ2, мм
	{ 246	,8	,1	, &B8VC01RDU},	//( - , DU) Координата АЗ2, мм
	{ 247	,1	,1	, &A4VP82LDU},	//( - , MDuS) Давление ПОДЪЁМ НИ1 в норме
	{ 248	,1	,1	, &B4VP82LDU},	//( - , MDuS) Давление ПОДЪЁМ НИ2 в норме
	{ 249	,1	,1	, &A2VP82LDU},	//( - , MDuS) Давление ПОДЪЁМ РБ1 в норме
	{ 250	,1	,1	, &B2VP82LDU},	//( - , MDuS) Давление ПОДЪЁМ РБ2 в норме
	{ 251	,1	,1	, &A3VP81LDU},	//( - , MDuS) Давление СПУСК ИС1 в норме
	{ 252	,1	,1	, &B3VP81LDU},	//( - , MDuS) Давление СПУСК ИС2 в норме
	{ 253	,1	,1	, &R0EE02LDU},	//( - , DU) Питание  АКНП  отключить
	{ 254	,1	,1	, &A0VP71LZ2},	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
	{ 255	,1	,1	, &B0VP71LZ1},	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
	{ 256	,1	,1	, &B0VP71LZ2},	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
	{ 257	,1	,1	, &A0VS11LDU},	//( - , DU) АЗ1 готова к работе
	{ 258	,1	,1	, &B0VS11LDU},	//( - , DU) АЗ2 готова к работе
	{ 259	,1	,1	, &A1IE01LDU},	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
	{ 260	,1	,1	, &A3IE01LDU},	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
	{ 261	,1	,1	, &A2IE01LDU},	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
	{ 262	,1	,1	, &A1IE02LDU},	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
	{ 263	,1	,1	, &A3IE02LDU},	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
	{ 264	,1	,1	, &A2IE02LDU},	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
	{ 265	,1	,1	, &B1IE01LDU},	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
	{ 266	,1	,1	, &B2IE01LDU},	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
	{ 267	,1	,1	, &B3IE01LDU},	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
	{ 268	,1	,1	, &B1IE02LDU},	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
	{ 269	,1	,1	, &B3IE02LDU},	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
	{ 270	,1	,1	, &B2IE02LDU},	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
	{ 271	,1	,1	, &R0IE02LDU},	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
	{ 272	,1	,1	, &R0IE01LDU},	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
	{ 273	,1	,1	, &A6IE01LDU},	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
	{ 274	,1	,1	, &B6IE01LDU},	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
	{ 275	,1	,1	, &A8IE01LDU},	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
	{ 276	,1	,1	, &B5IE01LDU},	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
	{ 277	,3	,1	, &R0CN95LDU},	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
	{ 278	,1	,1	, &R0AD03LZ1},	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
	{ 279	,1	,1	, &R0AD03LZ2},	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
	{ 280	,1	,1	, &R0AD04LZ1},	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
	{ 281	,1	,1	, &R0AD04LZ2},	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
	{ 282	,1	,1	, &R0AD05LZ1},	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
	{ 283	,1	,1	, &R0AD05LZ2},	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
	{ 284	,1	,1	, &B8IS12LDU},	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
	{ 285	,1	,1	, &B8IS21LDU},	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
	{ 286	,1	,1	, &A1VP41LZ1},	//( - , DU) Давление СБРОС ББ1 ниже АС
	{ 287	,1	,1	, &A1VP41LZ2},	//( - , DU) Давление СБРОС ББ1 ниже АС
	{ 288	,1	,1	, &R0VL22LDU},	//( - , DU) Конец программы 200сек
	{ 289	,1	,1	, &R0VL23LDU},	//( - , DU) Конец программы 20мин
	{ 290	,1	,1	, &B1VP41LZ1},	//( - , DU) Давление СБРОС ББ2 ниже АС
	{ 291	,1	,1	, &B1VP41LZ2},	//( - , DU) Давление СБРОС ББ2 ниже АС
	{ 292	,1	,1	, &A3AB19LDU},	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
	{ 293	,1	,1	, &B3AB19LDU},	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
	{ 294	,1	,1	, &A3EE03LDU},	//( - , DU) ВПИС ИС1
	{ 295	,1	,1	, &B3EE03LDU},	//( - , DU) ВПИС ИС2
	{ 296	,1	,1	, &B3AB15LDU},	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
	{ 297	,1	,1	, &R5IS21LDU},	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
	{ 298	,1	,1	, &R5VS22LDU},	//( - , DU) Движение ворот отстойной зоны к закрыты
	{ 299	,1	,1	, &R5VS12LDU},	//( - , DU) Движение ворот отстойной зоны к открыты
	{ 300	,1	,1	, &A3ZAV},	//( - , DU) 
	{ 301	,1	,1	, &B1AB19LDU},	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
	{ 302	,8	,1	, &R0VN09RZ2},	//( - , MDuBz2) Усредненный период разгона
	{ 303	,8	,1	, &R0VN09RZ1},	//( - , MDuBz1) Усредненный период разгона
	{ 304	,1	,1	, &R0AB16LDU},	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
	{ 305	,1	,1	, &R0AB17LDU},	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
	{ 306	,1	,1	, &R0AB18LDU},	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
	{ 307	,8	,1	, &A0CT01IZ1},	//( - , MDuBz1) Температура АЗ1-1
	{ 308	,8	,1	, &B0CT01IZ1},	//( - , MDuBz1) Температура АЗ2-1
	{ 309	,8	,1	, &A0CT01IZ2},	//( - , MDuBz2) Температура АЗ1-2
	{ 310	,8	,1	, &B0CT01IZ2},	//( - , MDuBz2) Температура АЗ2-2
	{ 311	,8	,1	, &A3MC01RDU},	//( - , DU) Заданная координата положения ИС от регулятора мм
	{ 312	,8	,1	, &A3MC02RDU},	//( - , DU) Температурная корректировка координаты ИМ
	{ 313	,8	,1	, &R0CN91LDU},	//( - , DU) Рассчётная реактивность от регулятора
	{ 314	,8	,1	, &A3MC03RDU},	//( - , DU) Координата положения ИМ 0-й реактивности
	{ 315	,1	,1	, &A3AB15LDU},	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
	{ 316	,1	,1	, &R0AB20LDU},	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
	{ 317	,8	,1	, &R0CN92LDU},	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
	{ 318	,8	,1	, &R0VN11RDU},	//( - , DU) Текущая мощность РУ
	{ 319	,8	,1	, &R0VN12RDU},	//( - , DU) Заданная мощность РУ
	{ 320	,1	,1	, &R0AB19LDU},	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
	{ 321	,8	,1	, &R0CN93LDU},	//( - , DU) время работы на мощности более 100Вт, сек
	{ 322	,8	,1	, &R0CN94LDU},	//( - , DU) Скорость изменения мощности
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
	{ 342	,5	,1	, &A3IC01UDU},	//( - , MDuS) Координата штока ИС1 (дел.энк)
	{ 343	,5	,1	, &B3IC01UDU},	//( - , MDuS) Координата штока ИС2 (дел.энк)
	{ 344	,8	,1	, &B3VC01RDU},	//( - , DU) Координата ИС2, мм
	{ 345	,5	,1	, &A8IC01UDU},	//( - , MDuS) Координата ДС2 (дел.энк)
	{ 346	,3	,1	, &R5VS01IDU},	//( - , DU) Готовность к управлению ворот отстойной зоны
	{ 347	,1	,1	, &R3VS22LDU},	//( - , DU) Движение гомогенных дверей к закрыты
	{ 348	,1	,1	, &R3VS12LDU},	//( - , DU) Движение гомогенных дверей к открыты
	{ 349	,3	,1	, &R3VS01IDU},	//( - , DU) Готовность к управлению гомогенных дверей
	{ 350	,1	,1	, &A3AB13LDU},	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
	{ 351	,1	,1	, &syn_A3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
	{ 352	,1	,1	, &B3AB13LDU},	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
	{ 353	,1	,1	, &syn_B3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
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
	{ 365	,3	,1	, &R0DE0FLDU},	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
	{ 366	,1	,1	, &R0DE31LDU},	//(sbk:20 - S01SBK, DiagnDU) диагностика шкафа ДУ сеть 1
	{ 367	,3	,1	, &TTLDU},	//( - , DU) ttl
	{ 368	,1	,1	, &R0DE32LDU},	//(sbk:20 - S02SBK, DiagnDU) диагностика шкафа ДУ сеть 2
	{ 369	,1	,1	, &A6AB06LDU},	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
	{ 370	,1	,1	, &A6AB07LDU},	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
	{ 371	,1	,1	, &A6AB08LDU},	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
	{ 372	,1	,1	, &A6AB09LDU},	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
	{ 373	,1	,1	, &B6AB06LDU},	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
	{ 374	,1	,1	, &B6AB07LDU},	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
	{ 375	,1	,1	, &B6AB08LDU},	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
	{ 376	,1	,1	, &B6AB09LDU},	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
	{ 377	,1	,1	, &A6AB05LDU},	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
	{ 378	,1	,1	, &B8VS12LDU},	//( - , DU) Движение АЗ2 в сторону ВУ
	{ 379	,8	,1	, &B8CV01RDU},	//( - , DU) Измеренная скорость перемещения АЗ2
	{ 380	,1	,1	, &B8AB06LDU},	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
	{ 381	,1	,1	, &B8AB07LDU},	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
	{ 382	,1	,1	, &B8AB05LDU},	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
	{ 383	,1	,1	, &B8VS22LDU},	//( - , DU) Движение АЗ2 в сторону НУ
	{ 384	,1	,1	, &B8AZ03LDU},	//( - , DU) Несанкционированное перемещение АЗ2
	{ 385	,1	,1	, &R0MD11LP1},	//( - , DU) Кнопка ПУСК
	{ 386	,1	,1	, &B8AD10LDU},	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
	{ 387	,1	,1	, &B8AD20LDU},	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
	{ 388	,1	,1	, &B8IS11LDU},	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
	{ 389	,1	,1	, &B8AB01LDU},	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
	{ 390	,1	,1	, &B8AB04LDU},	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
	{ 391	,1	,1	, &B8AB08LDU},	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
	{ 392	,1	,1	, &A5AZ03LDU},	//( - , DU) Несанкционированное перемещение НЛ1
	{ 393	,1	,1	, &A5AB01LDU},	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
	{ 394	,1	,1	, &A5AB02LDU},	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
	{ 395	,1	,1	, &B5AZ03LDU},	//( - , DU) Несанкционированное перемещение НЛ2
	{ 396	,1	,1	, &B5AB01LDU},	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
	{ 397	,1	,1	, &B5AB02LDU},	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
	{ 398	,1	,1	, &A4IS21LDU},	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
	{ 399	,1	,1	, &B4IS21LDU},	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
	{ 400	,1	,1	, &B4AD10LDU},	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
	{ 401	,1	,1	, &A4AD10LDU},	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
	{ 402	,1	,1	, &A4AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ1
	{ 403	,1	,1	, &A4AB01LDU},	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
	{ 404	,1	,1	, &A4AB02LDU},	//( - , DU) Блокировка движения НИ1 - Нет перемещения
	{ 405	,1	,1	, &B4AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ2
	{ 406	,1	,1	, &B4AB01LDU},	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
	{ 407	,1	,1	, &B4AB02LDU},	//( - , DU) Блокировка движения НИ2 - Нет перемещения
	{ 408	,1	,1	, &A5AB04LDU},	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
	{ 409	,1	,1	, &B5AB04LDU},	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
	{ 410	,1	,1	, &A1IS12LDU},	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
	{ 411	,1	,1	, &A2IS12LDU},	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
	{ 412	,1	,1	, &B1IS12LDU},	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
	{ 413	,1	,1	, &B2IS12LDU},	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
	{ 414	,1	,1	, &R4IS11LDU},	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
	{ 415	,1	,1	, &A8AB11LDU},	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
	{ 416	,1	,1	, &A8AB12LDU},	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
	{ 417	,1	,1	, &A8AB13LDU},	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
	{ 418	,1	,1	, &A8AB14LDU},	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
	{ 419	,1	,1	, &A8AB02LDU},	//( - , DU) Блокировка движения ДС2- АНИ не установлен
	{ 420	,1	,1	, &A8AB01LDU},	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
	{ 421	,1	,1	, &A2VS11LDU},	//( - , DU) Движение РБ1 в сторону ВУ
	{ 422	,8	,1	, &A2CV01RDU},	//( - , DU) Измеренная скорость перемещения РБ1
	{ 423	,1	,1	, &A2AB04LDU},	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
	{ 424	,1	,1	, &A2AB02LDU},	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
	{ 425	,1	,1	, &A2AB01LDU},	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
	{ 426	,1	,1	, &A2VS21LDU},	//( - , DU) Движение РБ1 в сторону НУ
	{ 427	,1	,1	, &A2AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
	{ 428	,1	,1	, &A2AD11LDU},	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
	{ 429	,1	,1	, &A2AD21LDU},	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
	{ 430	,1	,1	, &A2AD02LDU},	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
	{ 431	,1	,1	, &A2AD03LDU},	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
	{ 432	,1	,1	, &A2AD04LDU},	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
	{ 433	,1	,1	, &A2AD05LDU},	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
	{ 434	,1	,1	, &A2AB07LDU},	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
	{ 435	,1	,1	, &A2AB08LDU},	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
	{ 436	,1	,1	, &A2AB05LDU},	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
	{ 437	,1	,1	, &A2AB06LDU},	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
	{ 438	,1	,1	, &B8AB09LDU},	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
	{ 439	,1	,1	, &B8AB10LDU},	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
	{ 440	,1	,1	, &B8AB11LDU},	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
	{ 441	,1	,1	, &B8AB12LDU},	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
	{ 442	,1	,1	, &B8AB13LDU},	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
	{ 443	,1	,1	, &B8AB14LDU},	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
	{ 444	,1	,1	, &B8AB02LDU},	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
	{ 445	,1	,1	, &A8VS12LDU},	//( - , DU) Движение ДС2 в сторону ВУ
	{ 446	,8	,1	, &A8CV01RDU},	//( - , DU) Измеренная скорость перемещения ДС2
	{ 447	,1	,1	, &A8AB06LDU},	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
	{ 448	,1	,1	, &A8AB07LDU},	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
	{ 449	,1	,1	, &A8AB05LDU},	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
	{ 450	,1	,1	, &A8VS22LDU},	//( - , DU) Движение ДС2 в сторону НУ
	{ 451	,1	,1	, &A8AZ03LDU},	//( - , DU) Несанкционированное перемещение ДС2
	{ 452	,1	,1	, &A8AD10LDU},	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
	{ 453	,1	,1	, &A8AD20LDU},	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
	{ 454	,1	,1	, &B8IS22LDU},	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
	{ 455	,1	,1	, &A8IS12LDU},	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
	{ 456	,1	,1	, &A8AB04LDU},	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
	{ 457	,1	,1	, &A8IS22LDU},	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
	{ 458	,1	,1	, &A8AB08LDU},	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
	{ 459	,1	,1	, &A8AB09LDU},	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
	{ 460	,1	,1	, &A8AB10LDU},	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
	{ 461	,1	,1	, &B6IS21LDU},	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
	{ 462	,1	,1	, &A6VS22LDU},	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
	{ 463	,1	,1	, &A6VS12LDU},	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
	{ 464	,1	,1	, &B6VS22LDU},	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
	{ 465	,1	,1	, &B6VS12LDU},	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
	{ 466	,1	,1	, &A6AD10LDU},	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
	{ 467	,1	,1	, &A6AD20LDU},	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
	{ 468	,1	,1	, &B6AD10LDU},	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
	{ 469	,1	,1	, &B6AD20LDU},	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
	{ 470	,1	,1	, &A6AZ03LDU},	//( - , DU) Несанкционированное перемещение БЗ1
	{ 471	,1	,1	, &A6AB01LDU},	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
	{ 472	,1	,1	, &A6AB02LDU},	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
	{ 473	,1	,1	, &B6AZ03LDU},	//( - , DU) Несанкционированное перемещение БЗ2
	{ 474	,1	,1	, &B6AB01LDU},	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
	{ 475	,1	,1	, &B6AB02LDU},	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
	{ 476	,1	,1	, &A6AB04LDU},	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
	{ 477	,1	,1	, &B6AB04LDU},	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
	{ 478	,1	,1	, &R4AB01LDU},	//( - , DU) Блокировка движения тележки - АНИ не установлен
	{ 479	,1	,1	, &R8IS11LDU},	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
	{ 480	,1	,1	, &R6IS21LDU},	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
	{ 481	,1	,1	, &A0VN71LZ2},	//( - , MDuBz2) АЗ по АС мощности для АЗ1
	{ 482	,1	,1	, &A0VN71LZ1},	//( - , MDuBz1) АЗ по АС мощности для АЗ1
	{ 483	,1	,1	, &R0NE01LDU},	//( - , DU) Потеря связи с БАЗ1
	{ 484	,3	,1	, &R0MW15IP1},	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
	{ 485	,3	,1	, &R0MW14IP1},	//( - , DU) Переключатель ПРОГРАММЫ
	{ 486	,3	,1	, &R0MW12IP1},	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
	{ 487	,3	,1	, &R0MW13IP1},	//( - , DU) Переключатель ВЫБОР ЗОН
	{ 488	,3	,1	, &R0MW16IP1},	//( - , DU) Переключатель ВИД ПРОВЕРКИ
	{ 489	,3	,1	, &R0MW11IP1},	//( - , DU) Переключатель ВЫСТРЕЛ
	{ 490	,3	,1	, &R0MW11IP2},	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
	{ 491	,1	,1	, &R0MW13LP2},	//( - , DU) Переключатель СЕТЬ
	{ 492	,1	,1	, &R0MD32LP1},	//( - , DU) Кнопка СПУСК
	{ 493	,1	,1	, &R0MD31LP1},	//( - , DU) Кнопка СТОП
	{ 494	,1	,1	, &A1IS21LDU},	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
	{ 495	,1	,1	, &A2IS21LDU},	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
	{ 496	,1	,1	, &A3IS21LDU},	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
	{ 497	,1	,1	, &B1IS21LDU},	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
	{ 498	,1	,1	, &B2IS21LDU},	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
	{ 499	,1	,1	, &B3IS21LDU},	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
	{ 500	,1	,1	, &R0ES01LDU},	//( - , DU) ОРР не в исходном состоянии
	{ 501	,1	,1	, &R4MD11LP2},	//( - , DU) Кнопка ВПЕРЁД  (тележки)
	{ 502	,1	,1	, &R4MD31LP2},	//( - , DU) Кнопка СТОП  (тележки)
	{ 503	,1	,1	, &R4MD21LP2},	//( - , DU) Кнопка НАЗАД  (тележки)
	{ 504	,1	,1	, &A6IS11LDU},	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
	{ 505	,1	,1	, &A6IS21LDU},	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
	{ 506	,1	,1	, &B6IS11LDU},	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
	{ 507	,1	,1	, &A4IS11LDU},	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
	{ 508	,1	,1	, &B4IS11LDU},	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
	{ 509	,1	,1	, &R4AB13LDU},	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
	{ 510	,1	,1	, &R4AB14LDU},	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
	{ 511	,1	,1	, &R4AB15LDU},	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
	{ 512	,1	,1	, &R5IS11LDU},	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
	{ 513	,1	,1	, &R4AB16LDU},	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
	{ 514	,1	,1	, &R4AB17LDU},	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
	{ 515	,1	,1	, &R4AB18LDU},	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
	{ 516	,1	,1	, &R4AD10LDU},	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
	{ 517	,1	,1	, &R4AD20LDU},	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
	{ 518	,1	,1	, &A5VS22LDU},	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
	{ 519	,1	,1	, &A5VS12LDU},	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
	{ 520	,1	,1	, &B5VS22LDU},	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
	{ 521	,1	,1	, &B5VS12LDU},	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
	{ 522	,1	,1	, &B5AD10LDU},	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
	{ 523	,1	,1	, &B5AD20LDU},	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
	{ 524	,1	,1	, &A5AD10LDU},	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
	{ 525	,1	,1	, &A5AD20LDU},	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
	{ 526	,1	,1	, &A5IS11LDU},	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
	{ 527	,1	,1	, &A5IS21LDU},	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
	{ 528	,1	,1	, &B5IS11LDU},	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
	{ 529	,1	,1	, &B5IS21LDU},	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
	{ 530	,1	,1	, &R0NE02LDU},	//( - , DU) Потеря связи с БАЗ2
	{ 531	,1	,1	, &R4AB02LDU},	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
	{ 532	,1	,1	, &R0NE08LDU},	//( - , DU) Потеря связи с ОПУ
	{ 533	,1	,1	, &R4IS21LDU},	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
	{ 534	,1	,1	, &R4IS22LDU},	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
	{ 535	,1	,1	, &R4IS12LDU},	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
	{ 536	,1	,1	, &R4VS22LDU},	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
	{ 537	,1	,1	, &R4VS12LDU},	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
	{ 538	,1	,1	, &R4AZ03LDU},	//( - , DU) Несанкционированное перемещение тележки
	{ 539	,1	,1	, &R4AB03LDU},	//( - , DU) Блокировка движения тележки - Самоход любого механизма
	{ 540	,1	,1	, &R1IS21LDU},	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
	{ 541	,1	,1	, &R2IS21LDU},	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
	{ 542	,1	,1	, &R4AB04LDU},	//( - , DU) Блокировка движения тележки - Превышение времени движения
	{ 543	,1	,1	, &R4AB05LDU},	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
	{ 544	,1	,1	, &R4AB06LDU},	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
	{ 545	,1	,1	, &R4AB07LDU},	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
	{ 546	,1	,1	, &R4AB08LDU},	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
	{ 547	,1	,1	, &R4AB09LDU},	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
	{ 548	,1	,1	, &B0VN71LZ1},	//( - , MDuBz1) АЗ по АС мощности для АЗ2
	{ 549	,1	,1	, &B0VN71LZ2},	//( - , MDuBz2) АЗ по АС мощности для АЗ2
	{ 550	,1	,1	, &R4AB10LDU},	//( - , DU) Блокировка тележки - не открыта биологическая защита
	{ 551	,1	,1	, &R4AB11LDU},	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
	{ 552	,1	,1	, &R4AB12LDU},	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
	{ 553	,1	,1	, &A3AD21LDU},	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
	{ 554	,1	,1	, &A3AD02LDU},	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
	{ 555	,1	,1	, &A3AD03LDU},	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
	{ 556	,1	,1	, &A3AD04LDU},	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
	{ 557	,1	,1	, &A3AD05LDU},	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
	{ 558	,1	,1	, &A3AD01LDU},	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
	{ 559	,8	,1	, &A3CV02RDU},	//( - , DU) Заданная скорость перемещения ИС1
	{ 560	,1	,1	, &A3AB07LDU},	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
	{ 561	,1	,1	, &A3AB08LDU},	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
	{ 562	,1	,1	, &A3AB05LDU},	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
	{ 563	,1	,1	, &A3AB06LDU},	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
	{ 564	,1	,1	, &A3AB09LDU},	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
	{ 565	,1	,1	, &A3AB10LDU},	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
	{ 566	,1	,1	, &A3AB11LDU},	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
	{ 567	,1	,1	, &A3AB12LDU},	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 568	,1	,1	, &A3AB14LDU},	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
	{ 569	,1	,1	, &A3AB16LDU},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
	{ 570	,1	,1	, &A3AB17LDU},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
	{ 571	,1	,1	, &A3AB18LDU},	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
	{ 572	,1	,1	, &A3AB20LDU},	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
	{ 573	,1	,1	, &B3VS12LDU},	//( - , DU) Движение ИС2 в сторону ВУ
	{ 574	,8	,1	, &B3CV01RDU},	//( - , DU) Измеренная скорость перемещения ИС2
	{ 575	,1	,1	, &B3AB04LDU},	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
	{ 576	,1	,1	, &B1AD01LDU},	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
	{ 577	,8	,1	, &B1CV02RDU},	//( - , DU) Заданная скорость перемещения ББ2
	{ 578	,1	,1	, &B1AB07LDU},	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
	{ 579	,1	,1	, &B1AB08LDU},	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
	{ 580	,1	,1	, &B1AB05LDU},	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
	{ 581	,1	,1	, &B1AB06LDU},	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
	{ 582	,1	,1	, &B1AB09LDU},	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
	{ 583	,1	,1	, &B1AB10LDU},	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
	{ 584	,1	,1	, &B1AB11LDU},	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
	{ 585	,1	,1	, &B1AB12LDU},	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 586	,1	,1	, &B1AB13LDU},	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
	{ 587	,1	,1	, &B1AB14LDU},	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
	{ 588	,1	,1	, &B1AB16LDU},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
	{ 589	,1	,1	, &B1AB17LDU},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
	{ 590	,1	,1	, &B1AB18LDU},	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
	{ 591	,1	,1	, &A3VS12LDU},	//( - , DU) Движение ИС1 в сторону ВУ
	{ 592	,8	,1	, &A3CV01RDU},	//( - , DU) Измеренная скорость перемещения ИС1
	{ 593	,1	,1	, &A3AB04LDU},	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
	{ 594	,1	,1	, &A3AB02LDU},	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
	{ 595	,1	,1	, &A3AB01LDU},	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
	{ 596	,1	,1	, &A3VS22LDU},	//( - , DU) Движение ИС1 в сторону НУ
	{ 597	,1	,1	, &A3AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
	{ 598	,1	,1	, &A3AD11LDU},	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
	{ 599	,1	,1	, &B3AB18LDU},	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
	{ 600	,1	,1	, &B3AB20LDU},	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
	{ 601	,1	,1	, &C1MD31LP1},	//( - , DU) Кнопка СБРОС ББ
	{ 602	,1	,1	, &C1MD31LP2},	//( - , DU) Кнопка СБРОС ББ
	{ 603	,1	,1	, &A2AD31LDU},	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
	{ 604	,1	,1	, &B2AD31LDU},	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
	{ 605	,1	,1	, &A1AD31LDU},	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
	{ 606	,1	,1	, &B1AD31LDU},	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
	{ 607	,1	,1	, &A2AD32LDU},	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
	{ 608	,1	,1	, &B2AD32LDU},	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
	{ 609	,1	,1	, &A1AD32LDU},	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
	{ 610	,1	,1	, &B1AD32LDU},	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
	{ 611	,1	,1	, &R0MD11LP2},	//( - , DU) Кнопка Пуск проверки схем сброса
	{ 612	,1	,1	, &R0VX01LDU},	//( - , DU) ДО ИМПУЛЬСА
	{ 613	,3	,1	, &R0VL01IDU},	//( - , DU) До импульса минут
	{ 614	,3	,1	, &R0VL11IDU},	//( - , DU) До импульса секунд
	{ 615	,8	,1	, &R0VL06RDU},	//( - , DU) Индикация (Время задержки от ВУ РБ)
	{ 616	,1	,1	, &B3AD33LDU},	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 закрыть (обесточить)
	{ 617	,1	,1	, &B3IS11LDU},	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
	{ 618	,8	,1	, &R0VL02RDU},	//( - , DU) Индикация (Время задержки ИНИ)
	{ 619	,1	,1	, &R8AD21LDU},	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
	{ 620	,1	,1	, &R0AD14LDU},	//( - , DU) Имитация срабатывания верхней АС II УР
	{ 621	,8	,1	, &R0VL04RDU},	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
	{ 622	,1	,1	, &B3AB02LDU},	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
	{ 623	,1	,1	, &B3AB01LDU},	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
	{ 624	,1	,1	, &B3VS22LDU},	//( - , DU) Движение ИС2 в сторону НУ
	{ 625	,1	,1	, &B3AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
	{ 626	,1	,1	, &B3AD11LDU},	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
	{ 627	,1	,1	, &B3AD21LDU},	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
	{ 628	,1	,1	, &B3AD02LDU},	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
	{ 629	,1	,1	, &B3AD03LDU},	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
	{ 630	,1	,1	, &B3AD04LDU},	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
	{ 631	,1	,1	, &B3AD05LDU},	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
	{ 632	,1	,1	, &B3AD01LDU},	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
	{ 633	,8	,1	, &B3CV02RDU},	//( - , DU) Заданная скорость перемещения ИС2
	{ 634	,1	,1	, &B3AB07LDU},	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
	{ 635	,1	,1	, &B3AB08LDU},	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
	{ 636	,1	,1	, &B3AB05LDU},	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
	{ 637	,1	,1	, &B3AB06LDU},	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
	{ 638	,1	,1	, &B3AB09LDU},	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
	{ 639	,1	,1	, &B3AB10LDU},	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
	{ 640	,1	,1	, &B3AB11LDU},	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
	{ 641	,1	,1	, &B3AB12LDU},	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{ 642	,1	,1	, &B3AB14LDU},	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
	{ 643	,1	,1	, &B3AB16LDU},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
	{ 644	,1	,1	, &B3AB17LDU},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
	{ 645	,1	,1	, &B2AB07LDU},	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
	{ 646	,1	,1	, &B2AB08LDU},	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
	{ 647	,1	,1	, &B2AB05LDU},	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
	{ 648	,1	,1	, &B2AB06LDU},	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
	{ 649	,1	,1	, &B2AB09LDU},	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
	{ 650	,1	,1	, &B2AB10LDU},	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
	{ 651	,1	,1	, &B2AB11LDU},	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
	{ 652	,1	,1	, &B2AB12LDU},	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{ 653	,1	,1	, &B2AB13LDU},	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
	{ 654	,1	,1	, &B2AB14LDU},	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
	{ 655	,1	,1	, &B2AB16LDU},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
	{ 656	,1	,1	, &B2AB17LDU},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
	{ 657	,1	,1	, &R1AZ03LDU},	//( - , DU) Несанкционированное перемещение МДЗ1
	{ 658	,1	,1	, &R1AB01LDU},	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
	{ 659	,1	,1	, &R1AB02LDU},	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
	{ 660	,1	,1	, &R2AZ03LDU},	//( - , DU) Несанкционированное перемещение МДЗ2
	{ 661	,1	,1	, &R2AB01LDU},	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
	{ 662	,1	,1	, &R2AB02LDU},	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
	{ 663	,1	,1	, &R1AB04LDU},	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
	{ 664	,1	,1	, &R2AB04LDU},	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
	{ 665	,1	,1	, &R1AD10LDU},	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
	{ 666	,1	,1	, &R1AD20LDU},	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
	{ 667	,1	,1	, &R1IS11LDU},	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
	{ 668	,1	,1	, &A2AB09LDU},	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
	{ 669	,1	,1	, &A2AB10LDU},	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
	{ 670	,1	,1	, &A2AB11LDU},	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
	{ 671	,1	,1	, &A2AB12LDU},	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 672	,1	,1	, &A2AB13LDU},	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
	{ 673	,1	,1	, &A2AB14LDU},	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
	{ 674	,1	,1	, &A2AB16LDU},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
	{ 675	,1	,1	, &A2AB17LDU},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
	{ 676	,1	,1	, &A2AD01LDU},	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
	{ 677	,8	,1	, &A2CV02RDU},	//( - , DU) Заданная скорость перемещения РБ1
	{ 678	,8	,1	, &B2CV01RDU},	//( - , DU) Измеренная скорость перемещения РБ2
	{ 679	,1	,1	, &B2AB04LDU},	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
	{ 680	,1	,1	, &B2AB02LDU},	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
	{ 681	,1	,1	, &B2AB01LDU},	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
	{ 682	,1	,1	, &B2AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
	{ 683	,1	,1	, &B2AD11LDU},	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
	{ 684	,1	,1	, &B2AD21LDU},	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
	{ 685	,1	,1	, &B2AD02LDU},	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
	{ 686	,1	,1	, &B2AD03LDU},	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
	{ 687	,1	,1	, &B2AD04LDU},	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
	{ 688	,1	,1	, &B2AD05LDU},	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
	{ 689	,1	,1	, &B2AD01LDU},	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
	{ 690	,8	,1	, &B2CV02RDU},	//( - , DU) Заданная скорость перемещения РБ2
	{ 691	,1	,1	, &A1AB06LDU},	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
	{ 692	,1	,1	, &A1AB09LDU},	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
	{ 693	,1	,1	, &A1AB10LDU},	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
	{ 694	,1	,1	, &A1AB11LDU},	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
	{ 695	,1	,1	, &A1AB12LDU},	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 696	,1	,1	, &A1AB13LDU},	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
	{ 697	,1	,1	, &A1AB14LDU},	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
	{ 698	,1	,1	, &A1AB16LDU},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
	{ 699	,1	,1	, &A1AB17LDU},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
	{ 700	,1	,1	, &A1AB18LDU},	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
	{ 701	,1	,1	, &B1VS12LDU},	//( - , DU) Движение ББ2 в сторону ВУ
	{ 702	,8	,1	, &B1CV01RDU},	//( - , DU) Измеренная скорость перемещения ББ2
	{ 703	,1	,1	, &B1AB04LDU},	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
	{ 704	,1	,1	, &B1AB02LDU},	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
	{ 705	,1	,1	, &B1AB01LDU},	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
	{ 706	,1	,1	, &B1VS22LDU},	//( - , DU) Движение ББ2 в сторону НУ
	{ 707	,1	,1	, &B1AZ03LDU},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
	{ 708	,1	,1	, &B1AD11LDU},	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
	{ 709	,1	,1	, &B1AD21LDU},	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
	{ 710	,1	,1	, &B1AD02LDU},	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
	{ 711	,1	,1	, &B1AD03LDU},	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
	{ 712	,1	,1	, &B1AD04LDU},	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
	{ 713	,1	,1	, &B1AD05LDU},	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
	{ 714	,1	,1	, &R1VS22LDU},	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
	{ 715	,1	,1	, &R2VS22LDU},	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
	{ 716	,1	,1	, &R2VS12LDU},	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
	{ 717	,1	,1	, &R1VS12LDU},	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
	{ 718	,1	,1	, &R2IS11LDU},	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
	{ 719	,1	,1	, &A1VS12LDU},	//( - , DU) Движение ББ1 в сторону ВУ
	{ 720	,8	,1	, &A1CV01RDU},	//( - , DU) Измеренная скорость перемещения ББ1
	{ 721	,1	,1	, &A1AB04LDU},	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
	{ 722	,1	,1	, &A1AB02LDU},	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
	{ 723	,1	,1	, &A1AB01LDU},	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
	{ 724	,1	,1	, &A1VS22LDU},	//( - , DU) Движение ББ1 в сторону НУ
	{ 725	,1	,1	, &A1AZ03LDU},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
	{ 726	,1	,1	, &A1AD11LDU},	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
	{ 727	,1	,1	, &A1AD21LDU},	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
	{ 728	,1	,1	, &A1AD02LDU},	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
	{ 729	,1	,1	, &A1AD03LDU},	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
	{ 730	,1	,1	, &A1AD04LDU},	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
	{ 731	,1	,1	, &A1AD05LDU},	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
	{ 732	,1	,1	, &A1AD01LDU},	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
	{ 733	,8	,1	, &A1CV02RDU},	//( - , DU) Заданная скорость перемещения ББ1
	{ 734	,1	,1	, &A1AB07LDU},	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
	{ 735	,1	,1	, &A1AB08LDU},	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
	{ 736	,1	,1	, &A1AB05LDU},	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
	{ 737	,8	,1	, &fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
	{ 738	,5	,1	, &dEM_A1UC05UDU},	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
	{ 739	,5	,1	, &dEM_A1UC06UDU},	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
	{ 740	,5	,1	, &dEM_A2UC06UDU},	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
	{ 741	,5	,1	, &dEM_A2UC05UDU},	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
	{ 742	,8	,1	, &fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
	{ 743	,5	,1	, &dEM_A3UC06UDU},	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
	{ 744	,5	,1	, &dEM_A3UC05UDU},	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
	{ 745	,8	,1	, &fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
	{ 746	,5	,1	, &dEM_A8UC06UDU},	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
	{ 747	,8	,1	, &fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
	{ 748	,5	,1	, &dEM_A8UC05UDU},	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
	{ 749	,8	,1	, &fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{ 750	,8	,1	, &fEM_R0UV82RDU},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{ 751	,8	,1	, &fEM_R0UV83RDU},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{ 752	,8	,1	, &fEM_R0UV84RDU},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{ 753	,8	,1	, &fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 754	,8	,1	, &fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{ 755	,8	,1	, &fEM_R0UV87RDU},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 756	,8	,1	, &fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{ 757	,8	,1	, &fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{ 758	,8	,1	, &fEM_A3UP43RDU},	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
	{ 759	,8	,1	, &fEM_A3UP44RDU},	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
	{ 760	,8	,1	, &fEM_A3UP53RDU},	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
	{ 761	,8	,1	, &fEM_A3UP85RDU},	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 762	,8	,1	, &fEM_A3UP88RDU},	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 763	,8	,1	, &fEM_A3UP86RDU},	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 764	,8	,1	, &fEM_B8UV01RDU},	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
	{ 765	,8	,1	, &fEM_B8UV02RDU},	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
	{ 766	,8	,1	, &fEM_B8UV03RDU},	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
	{ 767	,8	,1	, &fEM_B8UL04RDU},	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
	{ 768	,3	,1	, &iEM_A2UV03CDU},	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
	{ 769	,8	,1	, &fEM_A2UV01RDU},	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
	{ 770	,8	,1	, &fEM_A2UV02RDU},	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
	{ 771	,8	,1	, &fEM_A1UV01RDU},	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
	{ 772	,8	,1	, &fEM_A1UV02RDU},	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
	{ 773	,8	,1	, &fEM_A1UC06RDU},	//(A1UC06RDU) Уставка определения самохода ББ  мм
	{ 774	,8	,1	, &fEM_A1UC05RDU},	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
	{ 775	,8	,1	, &fEM_A1UL04RDU},	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
	{ 776	,8	,1	, &fEM_A3UV01RDU},	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
	{ 777	,8	,1	, &fEM_A3UV02RDU},	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
	{ 778	,8	,1	, &fEM_A3UC06RDU},	//(A3UC06RDU) Уставка определения самохода ИС1  мм
	{ 779	,8	,1	, &fEM_A3UC05RDU},	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
	{ 780	,8	,1	, &fEM_A3UL04RDU},	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
	{ 781	,8	,1	, &fEM_A3UP54RDU},	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
	{ 782	,8	,1	, &fEM_A3UP87RDU},	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 783	,8	,1	, &fEM_R0UL05RDU},	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
	{ 784	,8	,1	, &fEM_R0UL20RDU},	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
	{ 785	,8	,1	, &fEM_B8UV04RDU},	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
	{ 786	,8	,1	, &fEM_B8UC06RDU},	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
	{ 787	,8	,1	, &fEM_B8UC05RDU},	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
	{ 788	,8	,1	, &fEM_A2UL05RDU},	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
	{ 789	,8	,1	, &fEM_A2UL03RDU},	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{ 790	,8	,1	, &fEM_A2UC06RDU},	//(A2UC06RDU) Уставка определения самохода РБ  мм
	{ 791	,8	,1	, &fEM_A2UC05RDU},	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
	{ 792	,8	,1	, &fEM_A2UL04RDU},	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
	{ 793	,8	,1	, &fEM_A1UL03RDU},	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
	{ 794	,8	,1	, &fEM_A1UL05RDU},	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
	{ 795	,8	,1	, &fEM_A3UL03RDU},	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
	{ 796	,8	,1	, &fEM_A3UL05RDU},	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
	{ 797	,8	,1	, &fEM_A1UC08RDU},	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
	{ 798	,8	,1	, &fEM_A3UC08RDU},	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
	{ 799	,8	,1	, &fEM_A1UC07RDU},	//(A1UC07RDU) Зона возврата при наведении ББ мм
	{ 800	,8	,1	, &fEM_A1UL01RDU},	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 801	,8	,1	, &fEM_A3UC07RDU},	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
	{ 802	,8	,1	, &fEM_A3UL01RDU},	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 803	,8	,1	, &fEM_A2UC08RDU},	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
	{ 804	,8	,1	, &fEM_A2UC07RDU},	//(A2UC07RDU) Зона возврата при наведении РБ  мм
	{ 805	,8	,1	, &fEM_A2UL01RDU},	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 806	,8	,1	, &fEM_B8UC01RDU},	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
	{ 807	,8	,1	, &fEM_B8UL07RDU},	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
	{ 808	,8	,1	, &fEM_B8UC02RDU},	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
	{ 809	,8	,1	, &fEM_B8UL01RDU},	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 810	,8	,1	, &fEM_B8UL05RDU},	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
	{ 811	,8	,1	, &fEM_B8UL03RDU},	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
	{ 812	,8	,1	, &fEM_B8UL06RDU},	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
	{ 813	,8	,1	, &fEM_A9UZ03RDU},	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
	{ 814	,8	,1	, &fEM_A9UZ04RDU},	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
	{ 815	,8	,1	, &fEM_A9UZ05RDU},	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
	{ 816	,8	,1	, &fEM_R4UZ04RDU},	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
	{ 817	,8	,1	, &fEM_R4UZ03RDU},	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
	{ 818	,8	,1	, &fEM_R4UZ05RDU},	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
	{ 819	,8	,1	, &fEM_A5UZ03RDU},	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
	{ 820	,8	,1	, &fEM_A5UZ04RDU},	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
	{ 821	,8	,1	, &fEM_A5UZ05RDU},	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
	{ 822	,8	,1	, &fEM_A4UZ03RDU},	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
	{ 823	,8	,1	, &fEM_A4UZ04RDU},	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
	{ 824	,8	,1	, &fEM_A4UZ05RDU},	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
	{ 825	,8	,1	, &fEM_A6UZ03RDU},	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
	{ 826	,8	,1	, &fEM_A6UZ04RDU},	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
	{ 827	,8	,1	, &fEM_A6UZ05RDU},	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
	{ 828	,8	,1	, &fEM_R1UZ03RDU},	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
	{ 829	,8	,1	, &fEM_R1UZ04RDU},	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
	{ 830	,8	,1	, &fEM_R1UZ05RDU},	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
	{ 831	,8	,1	, &fEM_R0UL04RDU},	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
	{ 832	,8	,1	, &fEM_R0UL06RDU},	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
	{ 833	,8	,1	, &fEM_R0UL03RDU},	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
	{ 834	,8	,1	, &fEM_R0UL17RDU},	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
	{ 835	,8	,1	, &fEM_R0UL19RDU},	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{ 836	,8	,1	, &fEM_R0UL07RDU},	//(R0UL07RDU) Время срабатывания верхней АС II УР
	{ 837	,8	,1	, &fEM_R0UL18RDU},	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
	{ 838	,8	,1	, &fEM_R0UL16RDU},	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
	{ 839	,8	,1	, &fEM_R0UL02RDU},	//(R0UL02RDU) Время задержки  ИНИ
	{ 840	,8	,1	, &fEM_R0UN08RDU},	//(R0UN08RDU) 8-я заданная мощность
	{ 841	,8	,1	, &fEM_R0UN07RDU},	//(R0UN07RDU) 7-я заданная мощность
	{ 842	,8	,1	, &fEM_R0UN06RDU},	//(R0UN06RDU) 6-я заданная мощность
	{ 843	,8	,1	, &fEM_R0UN05RDU},	//(R0UN05RDU) 5-я заданная мощность
	{ 844	,8	,1	, &fEM_R0UN04RDU},	//(R0UN04RDU) 4-я заданная мощность
	{ 845	,8	,1	, &fEM_R0UN03RDU},	//(R0UN03RDU) Ограничение 3 по мощности
	{ 846	,8	,1	, &fEM_R0UN02RDU},	//(R0UN02RDU) 2-я заданная мощность
	{ 847	,8	,1	, &fEM_R0UN01RDU},	//(R0UN01RDU) 1-я заданная мощность
	{ 848	,8	,1	, &fEM_A2UC82RDU},	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
	{ 849	,8	,1	, &fEM_A2UC83RDU},	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
	{ 850	,8	,1	, &fEM_A1UC83RDU},	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
	{ 851	,8	,1	, &fEM_A2UC81RDU},	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
	{ 852	,8	,1	, &fEM_A1UC81RDU},	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
	{ 853	,8	,1	, &fEM_A1UC82RDU},	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
	{ 854	,8	,1	, &fEM_A2UL83RDU},	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{ 855	,8	,1	, &fEM_A3UC81RDU},	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
	{ 856	,8	,1	, &fEM_A3UC82RDU},	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
	{ 857	,8	,1	, &fEM_R0UN80RDU},	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
	{ 858	,3	,1	, &iEM_A2UV01IDU},	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
	{ 859	,3	,1	, &iEM_A2UV02IDU},	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
	{ 860	,3	,1	, &iEM_A1UV01IDU},	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
	{ 861	,3	,1	, &iEM_A1UV02IDU},	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
	{ 862	,3	,1	, &iEM_A1UV03IDU},	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
	{ 863	,3	,1	, &iEM_A3UV01IDU},	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
	{ 864	,3	,1	, &iEM_A3UV02IDU},	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
	{ 865	,1	,1	, &lEM_R0MD01LC1},	//(R0MD01LC1) Ручное управление ОРР
	{ 866	,8	,1	, &fEM_A3UC09RDU},	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
	{ 867	,8	,1	, &fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
	{ 868	,8	,1	, &fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
	{ 869	,8	,1	, &fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
	{ 870	,8	,1	, &fEM_R0UL21RDU},	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
	{ 871	,8	,1	, &fEM_R0UN09RDU},	//(R0UN09RDU) Минимальный период при регулировании мощности
	{ 872	,8	,1	, &fEM_R0UN11RDU},	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
	{ 873	,8	,1	, &fEM_R0UN12RDU},	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
	{ 874	,8	,1	, &fEM_R0UN13RDU},	//(R0UN13RDU) Минимальное изменение координаты, мм
	{ 875	,8	,1	, &fEM_R0UN14RDU},	//(R0UN14RDU) Максимальная координата штока ИМ, мм
	{ 876	,8	,1	, &fEM_R0UN16RDU},	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
	{ 877	,8	,1	, &fEM_R0UN17RDU},	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
	{ 878	,8	,1	, &fEM_R0UN18RDU},	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
	{ 879	,8	,1	, &fEM_R0UN19RDU},	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
	{ 880	,8	,1	, &fEM_R0UN70LDU},	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
	{ 881	,8	,1	, &fEM_R0UN71LDU},	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
	{ 882	,8	,1	, &fEM_R0UN72LDU},	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
	{ 883	,8	,1	, &fEM_R0UN73LDU},	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
	{ 884	,8	,1	, &fEM_R0UN74LDU},	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
	{ 885	,8	,1	, &fEM_R0UN75LDU},	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
	{ 886	,8	,1	, &fEM_R0UN80LDU},	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
	{ 887	,8	,1	, &fEM_R0UN81LDU},	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
	{ 888	,8	,1	, &fEM_R0UN82LDU},	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
	{ 889	,8	,1	, &fEM_R0UN83LDU},	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
	{ 890	,8	,1	, &fEM_R0UN84LDU},	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
	{ 891	,8	,1	, &fEM_R0UN85LDU},	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
	{ 892	,8	,1	, &fEM_R0UT20RDU},	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
	{ 893	,8	,1	, &fEM_R0UN25RDU},	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
	{ 894	,8	,1	, &fEM_R0UN15RDU},	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
	{ 895	,8	,1	, &fEM_R0UN26RDU},	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
	{ 896	,8	,1	, &fEM_R0UN27RDU},	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
	{ 897	,8	,1	, &fEM_R0UN24RDU},	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 898	,8	,1	, &fEM_R0UL25RDU},	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{ 899	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 900	,8	,1	, &internal2_m186_y0},	//(internal2_m186_y0) y0
	{ 901	,8	,1	, &internal2_m184_y0},	//(internal2_m184_y0) y0
	{ 902	,1	,1	, &internal2_m216_y0},	//(internal2_m216_y0) state
	{ 903	,1	,1	, &internal2_m210_y0},	//(internal2_m210_y0) state
	{ 904	,1	,1	, &internal2_m199_y1},	//(internal2_m199_y1) y1 - внутренний параметр
	{ 905	,1	,1	, &internal2_m206_y1},	//(internal2_m206_y1) y1 - внутренний параметр
	{ 906	,1	,1	, &internal2_m189_y1},	//(internal2_m189_y1) y1 - внутренний параметр
	{ 907	,1	,1	, &internal2_m196_y1},	//(internal2_m196_y1) y1 - внутренний параметр
	{ 908	,5	,1	, &internal2_m16_Nk0},	//(internal2_m16_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 909	,1	,1	, &internal2_m16_SetFlag},	//(internal2_m16_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 910	,5	,1	, &internal2_m108_Nk0},	//(internal2_m108_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 911	,1	,1	, &internal2_m108_SetFlag},	//(internal2_m108_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 912	,5	,1	, &internal2_m112_Nk0},	//(internal2_m112_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 913	,1	,1	, &internal2_m112_SetFlag},	//(internal2_m112_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 914	,5	,1	, &internal2_m75_Nk0},	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 915	,1	,1	, &internal2_m75_SetFlag},	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 916	,5	,1	, &internal2_m77_Nk0},	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 917	,1	,1	, &internal2_m77_SetFlag},	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 918	,5	,1	, &internal2_m47_Nk0},	//(internal2_m47_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 919	,1	,1	, &internal2_m47_SetFlag},	//(internal2_m47_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 920	,5	,1	, &internal2_m51_Nk0},	//(internal2_m51_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 921	,1	,1	, &internal2_m51_SetFlag},	//(internal2_m51_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 922	,5	,1	, &internal2_m21_Nk0},	//(internal2_m21_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 923	,1	,1	, &internal2_m21_SetFlag},	//(internal2_m21_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 924	,1	,1	, &internal1_m1676_q0},	//(internal1_m1676_q0) q0 - внутренний параметр
	{ 925	,1	,1	, &internal1_m2109_q0},	//(internal1_m2109_q0) q0 - внутренний параметр
	{ 926	,1	,1	, &internal1_m2093_q0},	//(internal1_m2093_q0) q0 - внутренний параметр
	{ 927	,1	,1	, &internal1_m2141_q0},	//(internal1_m2141_q0) q0 - внутренний параметр
	{ 928	,1	,1	, &internal1_m2125_q0},	//(internal1_m2125_q0) q0 - внутренний параметр
	{ 929	,1	,1	, &internal1_m2115_q0},	//(internal1_m2115_q0) q0 - внутренний параметр
	{ 930	,1	,1	, &internal1_m2096_q0},	//(internal1_m2096_q0) q0 - внутренний параметр
	{ 931	,1	,1	, &internal1_m2113_q0},	//(internal1_m2113_q0) q0 - внутренний параметр
	{ 932	,1	,1	, &internal1_m2094_q0},	//(internal1_m2094_q0) q0 - внутренний параметр
	{ 933	,1	,1	, &internal1_m2092_q0},	//(internal1_m2092_q0) q0 - внутренний параметр
	{ 934	,1	,1	, &internal1_m2091_q0},	//(internal1_m2091_q0) q0 - внутренний параметр
	{ 935	,1	,1	, &internal1_m2105_q0},	//(internal1_m2105_q0) q0 - внутренний параметр
	{ 936	,1	,1	, &internal1_m2103_q0},	//(internal1_m2103_q0) q0 - внутренний параметр
	{ 937	,1	,1	, &internal1_m2111_q0},	//(internal1_m2111_q0) q0 - внутренний параметр
	{ 938	,1	,1	, &internal1_m2107_q0},	//(internal1_m2107_q0) q0 - внутренний параметр
	{ 939	,1	,1	, &internal1_m2147_q0},	//(internal1_m2147_q0) q0 - внутренний параметр
	{ 940	,1	,1	, &internal1_m2128_q0},	//(internal1_m2128_q0) q0 - внутренний параметр
	{ 941	,1	,1	, &internal1_m2145_q0},	//(internal1_m2145_q0) q0 - внутренний параметр
	{ 942	,1	,1	, &internal1_m2127_q0},	//(internal1_m2127_q0) q0 - внутренний параметр
	{ 943	,1	,1	, &internal1_m2124_q0},	//(internal1_m2124_q0) q0 - внутренний параметр
	{ 944	,1	,1	, &internal1_m2123_q0},	//(internal1_m2123_q0) q0 - внутренний параметр
	{ 945	,1	,1	, &internal1_m2137_q0},	//(internal1_m2137_q0) q0 - внутренний параметр
	{ 946	,1	,1	, &internal1_m2135_q0},	//(internal1_m2135_q0) q0 - внутренний параметр
	{ 947	,8	,1	, &internal1_m2012_tx},	//(internal1_m2012_tx) tx - внутренний параметр
	{ 948	,8	,1	, &internal1_m1991_tx},	//(internal1_m1991_tx) tx - внутренний параметр
	{ 949	,1	,1	, &internal1_m1698_Pv0},	//(internal1_m1698_Pv0)  - Пер. выключатель механизма
	{ 950	,1	,1	, &internal1_m1698_Zv0},	//(internal1_m1698_Zv0)  - Зад. выключатель механизма
	{ 951	,1	,1	, &internal1_m1698_MyFirstEnterFlag},	//(internal1_m1698_MyFirstEnterFlag) MyFirstEnterFlag
	{ 952	,1	,1	, &internal1_m1697_Pv0},	//(internal1_m1697_Pv0)  - Пер. выключатель механизма
	{ 953	,1	,1	, &internal1_m1697_Zv0},	//(internal1_m1697_Zv0)  - Зад. выключатель механизма
	{ 954	,1	,1	, &internal1_m1697_MyFirstEnterFlag},	//(internal1_m1697_MyFirstEnterFlag) MyFirstEnterFlag
	{ 955	,8	,1	, &internal1_m2165_tx},	//(internal1_m2165_tx) tx - время накопленное сек
	{ 956	,18	,1	, &internal1_m2165_y0},	//(internal1_m2165_y0) y0
	{ 957	,8	,1	, &internal1_m2170_tx},	//(internal1_m2170_tx) tx - время накопленное сек
	{ 958	,18	,1	, &internal1_m2170_y0},	//(internal1_m2170_y0) y0
	{ 959	,8	,1	, &internal1_m2169_tx},	//(internal1_m2169_tx) tx - время накопленное сек
	{ 960	,18	,1	, &internal1_m2169_y0},	//(internal1_m2169_y0) y0
	{ 961	,8	,1	, &internal1_m2206_tx},	//(internal1_m2206_tx) tx - внутренний параметр
	{ 962	,8	,1	, &internal1_m2204_tx},	//(internal1_m2204_tx) tx - время накопленное сек
	{ 963	,18	,1	, &internal1_m2204_y0},	//(internal1_m2204_y0) y0
	{ 964	,1	,1	, &internal1_m2209_q0},	//(internal1_m2209_q0) q0 - внутренний параметр
	{ 965	,1	,1	, &internal1_m2176_q0},	//(internal1_m2176_q0) q0 - внутренний параметр
	{ 966	,8	,1	, &internal1_m2184_tx},	//(internal1_m2184_tx) tx - внутренний параметр
	{ 967	,1	,1	, &internal1_m2182_q0},	//(internal1_m2182_q0) q0 - внутренний параметр
	{ 968	,8	,1	, &internal1_m2006_tx},	//(internal1_m2006_tx) tx - время накопленное сек
	{ 969	,18	,1	, &internal1_m2006_y0},	//(internal1_m2006_y0) y0
	{ 970	,8	,1	, &internal1_m1998_tx},	//(internal1_m1998_tx) tx - время накопленное сек
	{ 971	,18	,1	, &internal1_m1998_y0},	//(internal1_m1998_y0) y0
	{ 972	,1	,1	, &internal1_m1686_q0},	//(internal1_m1686_q0) q0 - внутренний параметр
	{ 973	,1	,1	, &internal1_m1691_q0},	//(internal1_m1691_q0) q0 - внутренний параметр
	{ 974	,1	,1	, &internal1_m1683_q0},	//(internal1_m1683_q0) q0 - внутренний параметр
	{ 975	,1	,1	, &internal1_m1725_q0},	//(internal1_m1725_q0) q0 - внутренний параметр
	{ 976	,8	,1	, &internal1_m740_tx},	//(internal1_m740_tx) tx - время накопленное сек
	{ 977	,18	,1	, &internal1_m740_y0},	//(internal1_m740_y0) y0
	{ 978	,8	,1	, &internal1_m2002_tx},	//(internal1_m2002_tx) tx - внутренний параметр
	{ 979	,1	,1	, &internal1_m2005_q0},	//(internal1_m2005_q0) q0 - внутренний параметр
	{ 980	,1	,1	, &internal1_m1997_q0},	//(internal1_m1997_q0) q0 - внутренний параметр
	{ 981	,8	,1	, &internal1_m1967_tx},	//(internal1_m1967_tx) tx - внутренний параметр
	{ 982	,8	,1	, &internal1_m1978_tx},	//(internal1_m1978_tx) tx - внутренний параметр
	{ 983	,8	,1	, &internal1_m1964_tx},	//(internal1_m1964_tx) tx - внутренний параметр
	{ 984	,1	,1	, &internal1_m1970_q0},	//(internal1_m1970_q0) q0 - внутренний параметр
	{ 985	,1	,1	, &internal1_m1982_q0},	//(internal1_m1982_q0) q0 - внутренний параметр
	{ 986	,8	,1	, &internal1_m1940_tx},	//(internal1_m1940_tx) tx - внутренний параметр
	{ 987	,8	,1	, &internal1_m51_tx},	//(internal1_m51_tx) tx - внутренний параметр
	{ 988	,8	,1	, &internal1_m337_tx},	//(internal1_m337_tx) tx - внутренний параметр
	{ 989	,8	,1	, &internal1_m292_tx},	//(internal1_m292_tx) tx - внутренний параметр
	{ 990	,8	,1	, &internal1_m741_tx},	//(internal1_m741_tx) tx - внутренний параметр
	{ 991	,8	,1	, &internal1_m1406_tx},	//(internal1_m1406_tx) tx - внутренний параметр
	{ 992	,8	,1	, &internal1_m113_tx},	//(internal1_m113_tx) tx - внутренний параметр
	{ 993	,8	,1	, &internal1_m115_tx},	//(internal1_m115_tx) tx - внутренний параметр
	{ 994	,8	,1	, &internal1_m120_tx},	//(internal1_m120_tx) tx - внутренний параметр
	{ 995	,8	,1	, &internal1_m21_tx},	//(internal1_m21_tx) tx - внутренний параметр
	{ 996	,8	,1	, &internal1_m13_tx},	//(internal1_m13_tx) tx - внутренний параметр
	{ 997	,8	,1	, &internal1_m1949_tx},	//(internal1_m1949_tx) tx - внутренний параметр
	{ 998	,8	,1	, &internal1_m1937_tx},	//(internal1_m1937_tx) tx - внутренний параметр
	{ 999	,8	,1	, &internal1_m2045_tx},	//(internal1_m2045_tx) tx - внутренний параметр
	{ 1000	,8	,1	, &internal1_m2049_tx},	//(internal1_m2049_tx) tx - внутренний параметр
	{ 1001	,8	,1	, &internal1_m1862_tx},	//(internal1_m1862_tx) tx - внутренний параметр
	{ 1002	,8	,1	, &internal1_m77_tx},	//(internal1_m77_tx) tx - внутренний параметр
	{ 1003	,8	,1	, &internal1_m306_tx},	//(internal1_m306_tx) tx - время накопленное сек
	{ 1004	,18	,1	, &internal1_m306_y0},	//(internal1_m306_y0) y0
	{ 1005	,8	,1	, &internal1_m1856_tx},	//(internal1_m1856_tx) tx - время накопленное сек
	{ 1006	,18	,1	, &internal1_m1856_y0},	//(internal1_m1856_y0) y0
	{ 1007	,8	,1	, &internal1_m1854_tx},	//(internal1_m1854_tx) tx - время накопленное сек
	{ 1008	,18	,1	, &internal1_m1854_y0},	//(internal1_m1854_y0) y0
	{ 1009	,8	,1	, &internal1_m1843_tx},	//(internal1_m1843_tx) tx - время накопленное сек
	{ 1010	,18	,1	, &internal1_m1843_y0},	//(internal1_m1843_y0) y0
	{ 1011	,8	,1	, &internal1_m1863_q0},	//(internal1_m1863_q0) q0 - внутренний параметр
	{ 1012	,8	,1	, &internal1_m1426_q0},	//(internal1_m1426_q0) q0 - внутренний параметр
	{ 1013	,8	,1	, &internal1_m1464_q0},	//(internal1_m1464_q0) q0 - внутренний параметр
	{ 1014	,8	,1	, &internal1_m1467_q0},	//(internal1_m1467_q0) q0 - внутренний параметр
	{ 1015	,8	,1	, &internal1_m1902_q0},	//(internal1_m1902_q0) q0 - внутренний параметр
	{ 1016	,8	,1	, &internal1_m1879_tx},	//(internal1_m1879_tx) tx - время накопленное сек
	{ 1017	,18	,1	, &internal1_m1879_y0},	//(internal1_m1879_y0) y0
	{ 1018	,8	,1	, &internal1_m1895_tx},	//(internal1_m1895_tx) tx - время накопленное сек
	{ 1019	,18	,1	, &internal1_m1895_y0},	//(internal1_m1895_y0) y0
	{ 1020	,8	,1	, &internal1_m1892_tx},	//(internal1_m1892_tx) tx - время накопленное сек
	{ 1021	,18	,1	, &internal1_m1892_y0},	//(internal1_m1892_y0) y0
	{ 1022	,8	,1	, &internal1_m2026_tx},	//(internal1_m2026_tx) tx - время накопленное сек
	{ 1023	,18	,1	, &internal1_m2026_y0},	//(internal1_m2026_y0) y0
	{ 1024	,8	,1	, &internal1_m2039_tx},	//(internal1_m2039_tx) tx - время накопленное сек
	{ 1025	,18	,1	, &internal1_m2039_y0},	//(internal1_m2039_y0) y0
	{ 1026	,8	,1	, &internal1_m1793_tx},	//(internal1_m1793_tx) tx - время накопленное сек
	{ 1027	,18	,1	, &internal1_m1793_y0},	//(internal1_m1793_y0) y0
	{ 1028	,8	,1	, &internal1_m1792_tx},	//(internal1_m1792_tx) tx - время накопленное сек
	{ 1029	,18	,1	, &internal1_m1792_y0},	//(internal1_m1792_y0) y0
	{ 1030	,8	,1	, &internal1_m1791_tx},	//(internal1_m1791_tx) tx - время накопленное сек
	{ 1031	,18	,1	, &internal1_m1791_y0},	//(internal1_m1791_y0) y0
	{ 1032	,8	,1	, &internal1_m1790_tx},	//(internal1_m1790_tx) tx - время накопленное сек
	{ 1033	,18	,1	, &internal1_m1790_y0},	//(internal1_m1790_y0) y0
	{ 1034	,8	,1	, &internal1_m1478_tx},	//(internal1_m1478_tx) tx - время накопленное сек
	{ 1035	,18	,1	, &internal1_m1478_y0},	//(internal1_m1478_y0) y0
	{ 1036	,8	,1	, &internal1_m1472_tx},	//(internal1_m1472_tx) tx - время накопленное сек
	{ 1037	,18	,1	, &internal1_m1472_y0},	//(internal1_m1472_y0) y0
	{ 1038	,8	,1	, &internal1_m1422_tx},	//(internal1_m1422_tx) tx - время накопленное сек
	{ 1039	,18	,1	, &internal1_m1422_y0},	//(internal1_m1422_y0) y0
	{ 1040	,8	,1	, &internal1_m823_tx},	//(internal1_m823_tx) tx - время накопленное сек
	{ 1041	,18	,1	, &internal1_m823_y0},	//(internal1_m823_y0) y0
	{ 1042	,8	,1	, &internal1_m821_tx},	//(internal1_m821_tx) tx - время накопленное сек
	{ 1043	,18	,1	, &internal1_m821_y0},	//(internal1_m821_y0) y0
	{ 1044	,8	,1	, &internal1_m828_tx},	//(internal1_m828_tx) tx - время накопленное сек
	{ 1045	,18	,1	, &internal1_m828_y0},	//(internal1_m828_y0) y0
	{ 1046	,8	,1	, &internal1_m187_tx},	//(internal1_m187_tx) tx - время накопленное сек
	{ 1047	,18	,1	, &internal1_m187_y0},	//(internal1_m187_y0) y0
	{ 1048	,8	,1	, &internal1_m192_tx},	//(internal1_m192_tx) tx - время накопленное сек
	{ 1049	,18	,1	, &internal1_m192_y0},	//(internal1_m192_y0) y0
	{ 1050	,8	,1	, &internal1_m198_tx},	//(internal1_m198_tx) tx - время накопленное сек
	{ 1051	,18	,1	, &internal1_m198_y0},	//(internal1_m198_y0) y0
	{ 1052	,8	,1	, &internal1_m517_tx},	//(internal1_m517_tx) tx - время накопленное сек
	{ 1053	,18	,1	, &internal1_m517_y0},	//(internal1_m517_y0) y0
	{ 1054	,8	,1	, &internal1_m2077_tx},	//(internal1_m2077_tx) tx - внутренний параметр
	{ 1055	,8	,1	, &internal1_m1166_tx},	//(internal1_m1166_tx) tx - внутренний параметр
	{ 1056	,8	,1	, &internal1_m1592_tx},	//(internal1_m1592_tx) tx - время накопленное сек
	{ 1057	,18	,1	, &internal1_m1592_y0},	//(internal1_m1592_y0) y0
	{ 1058	,8	,1	, &internal1_m1132_tx},	//(internal1_m1132_tx) tx - время накопленное сек
	{ 1059	,18	,1	, &internal1_m1132_y0},	//(internal1_m1132_y0) y0
	{ 1060	,8	,1	, &internal1_m1318_tx},	//(internal1_m1318_tx) tx - время накопленное сек
	{ 1061	,18	,1	, &internal1_m1318_y0},	//(internal1_m1318_y0) y0
	{ 1062	,8	,1	, &internal1_m921_tx},	//(internal1_m921_tx) tx - время накопленное сек
	{ 1063	,18	,1	, &internal1_m921_y0},	//(internal1_m921_y0) y0
	{ 1064	,8	,1	, &internal1_m1227_tx},	//(internal1_m1227_tx) tx - время накопленное сек
	{ 1065	,18	,1	, &internal1_m1227_y0},	//(internal1_m1227_y0) y0
	{ 1066	,1	,1	, &internal1_m1073_q0},	//(internal1_m1073_q0) q0 - внутренний параметр
	{ 1067	,1	,1	, &internal1_m1071_q0},	//(internal1_m1071_q0) q0 - внутренний параметр
	{ 1068	,1	,1	, &internal1_m1070_q0},	//(internal1_m1070_q0) q0 - внутренний параметр
	{ 1069	,1	,1	, &internal1_m1068_q0},	//(internal1_m1068_q0) q0 - внутренний параметр
	{ 1070	,1	,1	, &internal1_m1067_q0},	//(internal1_m1067_q0) q0 - внутренний параметр
	{ 1071	,1	,1	, &internal1_m1065_q0},	//(internal1_m1065_q0) q0 - внутренний параметр
	{ 1072	,1	,1	, &internal1_m1064_q0},	//(internal1_m1064_q0) q0 - внутренний параметр
	{ 1073	,1	,1	, &internal1_m1062_q0},	//(internal1_m1062_q0) q0 - внутренний параметр
	{ 1074	,1	,1	, &internal1_m1061_q0},	//(internal1_m1061_q0) q0 - внутренний параметр
	{ 1075	,1	,1	, &internal1_m52_x0},	//(internal1_m52_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1076	,1	,1	, &internal1_m981_q0},	//(internal1_m981_q0) q0 - внутренний параметр
	{ 1077	,1	,1	, &internal1_m1415_x0},	//(internal1_m1415_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1078	,1	,1	, &internal1_m1459_x0},	//(internal1_m1459_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1079	,1	,1	, &internal1_m1455_x0},	//(internal1_m1455_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1080	,1	,1	, &internal1_m1871_x0},	//(internal1_m1871_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1081	,1	,1	, &internal1_m1836_x0},	//(internal1_m1836_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1082	,1	,1	, &internal1_m1020_q0},	//(internal1_m1020_q0) q0 - внутренний параметр
	{ 1083	,1	,1	, &internal1_m1032_q0},	//(internal1_m1032_q0) q0 - внутренний параметр
	{ 1084	,1	,1	, &internal1_m1044_q0},	//(internal1_m1044_q0) q0 - внутренний параметр
	{ 1085	,1	,1	, &internal1_m1054_q0},	//(internal1_m1054_q0) q0 - внутренний параметр
	{ 1086	,1	,1	, &internal1_m1031_q0},	//(internal1_m1031_q0) q0 - внутренний параметр
	{ 1087	,1	,1	, &internal1_m1046_q0},	//(internal1_m1046_q0) q0 - внутренний параметр
	{ 1088	,1	,1	, &internal1_m1929_q0},	//(internal1_m1929_q0) q0 - внутренний параметр
	{ 1089	,1	,1	, &internal1_m1928_q0},	//(internal1_m1928_q0) q0 - внутренний параметр
	{ 1090	,3	,1	, &internal1_m325_Step},	//(internal1_m325_Step)  - текущий шаг программы
	{ 1091	,18	,10	, &internal1_m325_rz},	//(internal1_m325_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1092	,8	,1	, &internal1_m325_TimS},	//(internal1_m325_TimS) Время от старта программы
	{ 1093	,1	,1	, &internal1_m325_FinPr0},	//(internal1_m325_FinPr0) FinPr - конец программы
	{ 1094	,1	,1	, &internal1_m325_ErrPr0},	//(internal1_m325_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1095	,1	,1	, &internal1_m325_sbINI0},	//(internal1_m325_sbINI0) sbINI - запуск проверки ИНИ
	{ 1096	,1	,1	, &internal1_m325_sbVuIS0},	//(internal1_m325_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1097	,1	,1	, &internal1_m325_sb2UR0},	//(internal1_m325_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1098	,1	,1	, &internal1_m325_sbNupIS0},	//(internal1_m325_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1099	,1	,1	, &internal1_m325_sbVuRB0},	//(internal1_m325_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1100	,1	,1	, &internal1_m325_MyFirstEnterFlag},	//(internal1_m325_MyFirstEnterFlag)  
	{ 1101	,5	,1	, &internal1_m333_x0},	//(internal1_m333_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1102	,5	,1	, &internal1_m291_TimS},	//(internal1_m291_TimS) Время старта
	{ 1103	,3	,1	, &internal1_m268_Step},	//(internal1_m268_Step)  - текущий шаг программы
	{ 1104	,18	,10	, &internal1_m268_rz},	//(internal1_m268_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1105	,8	,1	, &internal1_m268_TimS},	//(internal1_m268_TimS) Время от старта программы
	{ 1106	,1	,1	, &internal1_m268_FinPr0},	//(internal1_m268_FinPr0) FinPr - конец программы
	{ 1107	,1	,1	, &internal1_m268_ErrPr0},	//(internal1_m268_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1108	,1	,1	, &internal1_m268_sbINI0},	//(internal1_m268_sbINI0) sbINI - запуск проверки ИНИ
	{ 1109	,1	,1	, &internal1_m268_sbVuIS0},	//(internal1_m268_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1110	,1	,1	, &internal1_m268_sb2UR0},	//(internal1_m268_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1111	,1	,1	, &internal1_m268_sbNupIS0},	//(internal1_m268_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1112	,1	,1	, &internal1_m268_sbVuRB0},	//(internal1_m268_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1113	,1	,1	, &internal1_m268_MyFirstEnterFlag},	//(internal1_m268_MyFirstEnterFlag)  
	{ 1114	,1	,1	, &internal1_m1389_q0},	//(internal1_m1389_q0) q0 - внутренний параметр
	{ 1115	,3	,1	, &internal1_m1390_Step},	//(internal1_m1390_Step)  - текущий шаг программы
	{ 1116	,18	,6	, &internal1_m1390_rz},	//(internal1_m1390_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1117	,8	,1	, &internal1_m1390_TimS},	//(internal1_m1390_TimS) Время от старта программы
	{ 1118	,1	,1	, &internal1_m1390_FinPr0},	//(internal1_m1390_FinPr0) FinPr - конец программы
	{ 1119	,1	,1	, &internal1_m1390_ErrPr0},	//(internal1_m1390_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1120	,1	,1	, &internal1_m1390_sbINI0},	//(internal1_m1390_sbINI0) sbINI - запуск проверки ИНИ
	{ 1121	,1	,1	, &internal1_m1390_sbVuIS0},	//(internal1_m1390_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1122	,1	,1	, &internal1_m1390_sb2UR0},	//(internal1_m1390_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1123	,1	,1	, &internal1_m1390_sbNupIS0},	//(internal1_m1390_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1124	,1	,1	, &internal1_m1390_sbVuRB0},	//(internal1_m1390_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1125	,1	,1	, &internal1_m1390_MyFirstEnterFlag},	//(internal1_m1390_MyFirstEnterFlag)  
	{ 1126	,1	,1	, &internal1_m1015_q0},	//(internal1_m1015_q0) q0 - внутренний параметр
	{ 1127	,1	,1	, &internal1_m1012_q0},	//(internal1_m1012_q0) q0 - внутренний параметр
	{ 1128	,1	,1	, &internal1_m1014_q0},	//(internal1_m1014_q0) q0 - внутренний параметр
	{ 1129	,1	,1	, &internal1_m1009_q0},	//(internal1_m1009_q0) q0 - внутренний параметр
	{ 1130	,1	,1	, &internal1_m742_q0},	//(internal1_m742_q0) q0 - внутренний параметр
	{ 1131	,1	,1	, &internal1_m335_q0},	//(internal1_m335_q0) q0 - внутренний параметр
	{ 1132	,1	,1	, &internal1_m331_q0},	//(internal1_m331_q0) q0 - внутренний параметр
	{ 1133	,1	,1	, &internal1_m288_q0},	//(internal1_m288_q0) q0 - внутренний параметр
	{ 1134	,5	,1	, &internal1_m287_x0},	//(internal1_m287_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1135	,1	,1	, &internal1_m1858_q0},	//(internal1_m1858_q0) q0 - внутренний параметр
	{ 1136	,1	,1	, &internal1_m1846_q0},	//(internal1_m1846_q0) q0 - внутренний параметр
	{ 1137	,1	,1	, &internal1_m1837_q0},	//(internal1_m1837_q0) q0 - внутренний параметр
	{ 1138	,1	,1	, &internal1_m1912_q0},	//(internal1_m1912_q0) q0 - внутренний параметр
	{ 1139	,1	,1	, &internal1_m1882_q0},	//(internal1_m1882_q0) q0 - внутренний параметр
	{ 1140	,1	,1	, &internal1_m1872_q0},	//(internal1_m1872_q0) q0 - внутренний параметр
	{ 1141	,1	,1	, &internal1_m1442_q0},	//(internal1_m1442_q0) q0 - внутренний параметр
	{ 1142	,1	,1	, &internal1_m1429_x0},	//(internal1_m1429_x0) был приход сигнала x1
	{ 1143	,8	,1	, &internal1_m1429_y0},	//(internal1_m1429_y0) интервал между сигналами х1 и х2
	{ 1144	,1	,1	, &internal1_m1425_q0},	//(internal1_m1425_q0) q0 - внутренний параметр
	{ 1145	,1	,1	, &internal1_m1416_q0},	//(internal1_m1416_q0) q0 - внутренний параметр
	{ 1146	,1	,1	, &internal1_m1475_q0},	//(internal1_m1475_q0) q0 - внутренний параметр
	{ 1147	,1	,1	, &internal1_m1495_q0},	//(internal1_m1495_q0) q0 - внутренний параметр
	{ 1148	,1	,1	, &internal1_m1461_q0},	//(internal1_m1461_q0) q0 - внутренний параметр
	{ 1149	,1	,1	, &internal1_m1476_x0},	//(internal1_m1476_x0) был приход сигнала x1
	{ 1150	,8	,1	, &internal1_m1476_y0},	//(internal1_m1476_y0) интервал между сигналами х1 и х2
	{ 1151	,5	,1	, &internal1_m1400_x0},	//(internal1_m1400_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1152	,1	,1	, &internal1_m1481_q0},	//(internal1_m1481_q0) q0 - внутренний параметр
	{ 1153	,1	,1	, &internal1_m26_q0},	//(internal1_m26_q0) q0 - внутренний параметр
	{ 1154	,1	,1	, &internal1_m1496_q0},	//(internal1_m1496_q0) q0 - внутренний параметр
	{ 1155	,1	,1	, &internal1_m632_q0},	//(internal1_m632_q0) q0 - внутренний параметр
	{ 1156	,1	,1	, &internal1_m617_q0},	//(internal1_m617_q0) q0 - внутренний параметр
	{ 1157	,1	,1	, &internal1_m644_q0},	//(internal1_m644_q0) q0 - внутренний параметр
	{ 1158	,1	,1	, &internal1_m628_q0},	//(internal1_m628_q0) q0 - внутренний параметр
	{ 1159	,1	,1	, &internal1_m612_q0},	//(internal1_m612_q0) q0 - внутренний параметр
	{ 1160	,1	,1	, &internal1_m610_q0},	//(internal1_m610_q0) q0 - внутренний параметр
	{ 1161	,1	,1	, &internal1_m598_q0},	//(internal1_m598_q0) q0 - внутренний параметр
	{ 1162	,5	,1	, &internal1_m1392_q0},	//(internal1_m1392_q0) q0 - внутренний параметр
	{ 1163	,1	,1	, &internal1_m608_q0},	//(internal1_m608_q0) q0 - внутренний параметр
	{ 1164	,1	,1	, &internal1_m109_q0},	//(internal1_m109_q0) q0 - внутренний параметр
	{ 1165	,1	,1	, &internal1_m1628_q0},	//(internal1_m1628_q0) q0 - внутренний параметр
	{ 1166	,1	,1	, &internal1_m1627_q0},	//(internal1_m1627_q0) q0 - внутренний параметр
	{ 1167	,1	,1	, &internal1_m1626_q0},	//(internal1_m1626_q0) q0 - внутренний параметр
	{ 1168	,1	,1	, &internal1_m1625_q0},	//(internal1_m1625_q0) q0 - внутренний параметр
	{ 1169	,1	,1	, &internal1_m1663_q0},	//(internal1_m1663_q0) q0 - внутренний параметр
	{ 1170	,1	,1	, &internal1_m1662_q0},	//(internal1_m1662_q0) q0 - внутренний параметр
	{ 1171	,1	,1	, &internal1_m1661_q0},	//(internal1_m1661_q0) q0 - внутренний параметр
	{ 1172	,1	,1	, &internal1_m1943_q0},	//(internal1_m1943_q0) q0 - внутренний параметр
	{ 1173	,1	,1	, &internal1_m1723_q0},	//(internal1_m1723_q0) q0 - внутренний параметр
	{ 1174	,1	,1	, &internal1_m1713_q0},	//(internal1_m1713_q0) q0 - внутренний параметр
	{ 1175	,1	,1	, &internal1_m1720_q0},	//(internal1_m1720_q0) q0 - внутренний параметр
	{ 1176	,1	,1	, &internal1_m1709_q0},	//(internal1_m1709_q0) q0 - внутренний параметр
	{ 1177	,1	,1	, &internal1_m1717_q0},	//(internal1_m1717_q0) q0 - внутренний параметр
	{ 1178	,1	,1	, &internal1_m2143_q0},	//(internal1_m2143_q0) q0 - внутренний параметр
	{ 1179	,1	,1	, &internal1_m2139_q0},	//(internal1_m2139_q0) q0 - внутренний параметр
	{ 1180	,1	,1	, &internal1_m1688_q0},	//(internal1_m1688_q0) q0 - внутренний параметр
	{ 1181	,1	,1	, &internal1_m1680_q0},	//(internal1_m1680_q0) q0 - внутренний параметр
	{ 1182	,1	,1	, &internal1_m1678_q0},	//(internal1_m1678_q0) q0 - внутренний параметр
	{ 1183	,1	,1	, &internal1_m1674_q0},	//(internal1_m1674_q0) q0 - внутренний параметр
	{ 1184	,1	,1	, &internal1_m1670_q0},	//(internal1_m1670_q0) q0 - внутренний параметр
	{ 1185	,1	,1	, &internal1_m1672_q0},	//(internal1_m1672_q0) q0 - внутренний параметр
	{ 1186	,1	,1	, &internal1_m19_q0},	//(internal1_m19_q0) q0 - внутренний параметр
	{ 1187	,1	,1	, &internal1_m1651_q0},	//(internal1_m1651_q0) q0 - внутренний параметр
	{ 1188	,1	,1	, &internal1_m1649_q0},	//(internal1_m1649_q0) q0 - внутренний параметр
	{ 1189	,1	,1	, &internal1_m1645_q0},	//(internal1_m1645_q0) q0 - внутренний параметр
	{ 1190	,1	,1	, &internal1_m1647_q0},	//(internal1_m1647_q0) q0 - внутренний параметр
	{ 1191	,1	,1	, &internal1_m1643_q0},	//(internal1_m1643_q0) q0 - внутренний параметр
	{ 1192	,1	,1	, &internal1_m1641_q0},	//(internal1_m1641_q0) q0 - внутренний параметр
	{ 1193	,1	,1	, &internal1_m2059_q0},	//(internal1_m2059_q0) q0 - внутренний параметр
	{ 1194	,1	,1	, &internal1_m2054_q0},	//(internal1_m2054_q0) q0 - внутренний параметр
	{ 1195	,1	,1	, &internal1_m2033_q0},	//(internal1_m2033_q0) q0 - внутренний параметр
	{ 1196	,1	,1	, &internal1_m2021_q0},	//(internal1_m2021_q0) q0 - внутренний параметр
	{ 1197	,1	,1	, &internal1_m1954_q0},	//(internal1_m1954_q0) q0 - внутренний параметр
	{ 1198	,1	,1	, &internal1_m1637_q0},	//(internal1_m1637_q0) q0 - внутренний параметр
	{ 1199	,1	,1	, &internal1_m1639_q0},	//(internal1_m1639_q0) q0 - внутренний параметр
	{ 1200	,1	,1	, &internal1_m1623_q0},	//(internal1_m1623_q0) q0 - внутренний параметр
	{ 1201	,1	,1	, &internal1_m1621_q0},	//(internal1_m1621_q0) q0 - внутренний параметр
	{ 1202	,1	,1	, &internal1_m1619_q0},	//(internal1_m1619_q0) q0 - внутренний параметр
	{ 1203	,1	,1	, &internal1_m1617_q0},	//(internal1_m1617_q0) q0 - внутренний параметр
	{ 1204	,1	,1	, &internal1_m1616_q0},	//(internal1_m1616_q0) q0 - внутренний параметр
	{ 1205	,1	,1	, &internal1_m1614_q0},	//(internal1_m1614_q0) q0 - внутренний параметр
	{ 1206	,1	,1	, &internal1_m1613_q0},	//(internal1_m1613_q0) q0 - внутренний параметр
	{ 1207	,1	,1	, &internal1_m1611_q0},	//(internal1_m1611_q0) q0 - внутренний параметр
	{ 1208	,18	,1	, &internal1_m2082_DvUp0},	//(internal1_m2082_DvUp0) - есть команда на движение вперёд
	{ 1209	,18	,1	, &internal1_m2082_DvDw0},	//(internal1_m2082_DvDw0) - есть команда на движение назад
	{ 1210	,18	,1	, &internal1_m2082_FDvUp0},	//(internal1_m2082_FDvUp0) - есть команда на движение вперёд
	{ 1211	,18	,1	, &internal1_m2082_FDvDw0},	//(internal1_m2082_FDvDw0) - есть команда на движение назад
	{ 1212	,18	,1	, &internal1_m2082_BlDv0},	//(internal1_m2082_BlDv0) - была блокировка
	{ 1213	,18	,1	, &internal1_m2082_Pkv0},	//(internal1_m2082_Pkv0) Pkv - передний конечный выключатель
	{ 1214	,18	,1	, &internal1_m2082_Pkav0},	//(internal1_m2082_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1215	,18	,1	, &internal1_m2082_Zkv0},	//(internal1_m2082_Zkv0) Zkv - задний конечный выключатель
	{ 1216	,18	,1	, &internal1_m2082_Zkav0},	//(internal1_m2082_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1217	,8	,1	, &internal1_m2082_txNm},	//(internal1_m2082_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1218	,8	,1	, &internal1_m2082_txSm},	//(internal1_m2082_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1219	,8	,1	, &internal1_m2082_txHr},	//(internal1_m2082_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1220	,8	,1	, &internal1_m2082_txLd},	//(internal1_m2082_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1221	,18	,1	, &internal1_m2082_fef},	//(internal1_m2082_fef) fef
	{ 1222	,18	,1	, &internal1_m2076_DvUp0},	//(internal1_m2076_DvUp0) - есть команда на движение вперёд
	{ 1223	,18	,1	, &internal1_m2076_DvDw0},	//(internal1_m2076_DvDw0) - есть команда на движение назад
	{ 1224	,18	,1	, &internal1_m2076_FDvUp0},	//(internal1_m2076_FDvUp0) - есть команда на движение вперёд
	{ 1225	,18	,1	, &internal1_m2076_FDvDw0},	//(internal1_m2076_FDvDw0) - есть команда на движение назад
	{ 1226	,18	,1	, &internal1_m2076_BlDv0},	//(internal1_m2076_BlDv0) - была блокировка
	{ 1227	,18	,1	, &internal1_m2076_Pkv0},	//(internal1_m2076_Pkv0) Pkv - передний конечный выключатель
	{ 1228	,18	,1	, &internal1_m2076_Pkav0},	//(internal1_m2076_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1229	,18	,1	, &internal1_m2076_Zkv0},	//(internal1_m2076_Zkv0) Zkv - задний конечный выключатель
	{ 1230	,18	,1	, &internal1_m2076_Zkav0},	//(internal1_m2076_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1231	,8	,1	, &internal1_m2076_txNm},	//(internal1_m2076_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1232	,8	,1	, &internal1_m2076_txSm},	//(internal1_m2076_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1233	,8	,1	, &internal1_m2076_txHr},	//(internal1_m2076_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1234	,8	,1	, &internal1_m2076_txLd},	//(internal1_m2076_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1235	,18	,1	, &internal1_m2076_fef},	//(internal1_m2076_fef) fef
	{ 1236	,1	,1	, &internal1_m1466_q0},	//(internal1_m1466_q0) q0 - внутренний параметр
	{ 1237	,1	,1	, &internal1_m1470_x0},	//(internal1_m1470_x0) был приход сигнала x1
	{ 1238	,8	,1	, &internal1_m1470_y0},	//(internal1_m1470_y0) интервал между сигналами х1 и х2
	{ 1239	,1	,1	, &internal1_m1894_x0},	//(internal1_m1894_x0) был приход сигнала x1
	{ 1240	,8	,1	, &internal1_m1894_y0},	//(internal1_m1894_y0) интервал между сигналами х1 и х2
	{ 1241	,1	,1	, &internal1_m1855_x0},	//(internal1_m1855_x0) был приход сигнала x1
	{ 1242	,8	,1	, &internal1_m1855_y0},	//(internal1_m1855_y0) интервал между сигналами х1 и х2
	{ 1243	,1	,1	, &internal1_m279_q0},	//(internal1_m279_q0) q0 - внутренний параметр
	{ 1244	,1	,1	, &internal1_m989_q0},	//(internal1_m989_q0) q0 - внутренний параметр
	{ 1245	,1	,1	, &internal1_m620_q0},	//(internal1_m620_q0) q0 - внутренний параметр
	{ 1246	,8	,1	, &internal1_m1289_X0},	//(internal1_m1289_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1247	,8	,1	, &internal1_m1289_t0},	//(internal1_m1289_t0) время нахождения в зоне возврата
	{ 1248	,18	,1	, &internal1_m1289_BLDv0},	//(internal1_m1289_BLDv0) BlDv - Блокировка движения
	{ 1249	,8	,1	, &internal1_m1308_tx},	//(internal1_m1308_tx) tx - время накопленное сек
	{ 1250	,18	,1	, &internal1_m1308_y0},	//(internal1_m1308_y0) y0
	{ 1251	,8	,1	, &internal1_m1309_tx},	//(internal1_m1309_tx) tx - время накопленное сек
	{ 1252	,18	,1	, &internal1_m1309_y0},	//(internal1_m1309_y0) y0
	{ 1253	,3	,1	, &internal1_m1317_xptr},	//(internal1_m1317_xptr) указатель текущей позиции в массиве координат
	{ 1254	,8	,60	, &internal1_m1317_x0},	//(internal1_m1317_x0) x0 - массив мгновенных значений координат
	{ 1255	,8	,60	, &internal1_m1317_tim0},	//(internal1_m1317_tim0) tim0 - массив значений времени цикла
	{ 1256	,8	,1	, &internal1_m1317_sumtim},	//(internal1_m1317_sumtim) sumtim - время в пути
	{ 1257	,8	,1	, &internal1_m1317_StSpeed},	//(internal1_m1317_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1258	,8	,1	, &internal1_m1317_Vz0},	//(internal1_m1317_Vz0) Vz0 - предыдущая заданная скорость
	{ 1259	,3	,1	, &internal1_m1317_flRazg},	//(internal1_m1317_flRazg) признак разгона/торможения
	{ 1260	,8	,1	, &internal1_m1317_DelSp},	//(internal1_m1317_DelSp) DelSp - время переключения скоростей
	{ 1261	,8	,1	, &internal1_m1317_z0},	//(internal1_m1317_z0) z0 - точка прекращения движения
	{ 1262	,8	,1	, &internal1_m1317_txZS},	//(internal1_m1317_txZS) txZS
	{ 1263	,8	,1	, &internal1_m1317_tx},	//(internal1_m1317_tx) tx
	{ 1264	,8	,1	, &internal1_m1317_txd},	//(internal1_m1317_txd) txd
	{ 1265	,8	,1	, &internal1_m1317_txMBl},	//(internal1_m1317_txMBl) tx
	{ 1266	,8	,1	, &internal1_m1317_txBl},	//(internal1_m1317_txBl) tx
	{ 1267	,8	,1	, &internal1_m1317_Speed0},	//(internal1_m1317_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1268	,8	,1	, &internal1_m1317_xz0},	//(internal1_m1317_xz0) xz0 - новое задание мм
	{ 1269	,8	,1	, &internal1_m1317_tz0},	//(internal1_m1317_tz0) tz0 - время защиты от нового задания сек
	{ 1270	,1	,1	, &internal1_m1317_Shift0},	//(internal1_m1317_Shift0) Shift0 - признак самохода
	{ 1271	,1	,1	, &internal1_m1317_ShCntlSp0},	//(internal1_m1317_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1272	,1	,1	, &internal1_m1317_ShiftControl},	//(internal1_m1317_ShiftControl) ShiftControl - признак самохода
	{ 1273	,1	,1	, &internal1_m618_q0},	//(internal1_m618_q0) q0 - внутренний параметр
	{ 1274	,8	,1	, &internal1_m887_X0},	//(internal1_m887_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1275	,8	,1	, &internal1_m887_t0},	//(internal1_m887_t0) время нахождения в зоне возврата
	{ 1276	,18	,1	, &internal1_m887_BLDv0},	//(internal1_m887_BLDv0) BlDv - Блокировка движения
	{ 1277	,8	,1	, &internal1_m911_tx},	//(internal1_m911_tx) tx - время накопленное сек
	{ 1278	,18	,1	, &internal1_m911_y0},	//(internal1_m911_y0) y0
	{ 1279	,8	,1	, &internal1_m914_tx},	//(internal1_m914_tx) tx - время накопленное сек
	{ 1280	,18	,1	, &internal1_m914_y0},	//(internal1_m914_y0) y0
	{ 1281	,3	,1	, &internal1_m920_xptr},	//(internal1_m920_xptr) указатель текущей позиции в массиве координат
	{ 1282	,8	,60	, &internal1_m920_x0},	//(internal1_m920_x0) x0 - массив мгновенных значений координат
	{ 1283	,8	,60	, &internal1_m920_tim0},	//(internal1_m920_tim0) tim0 - массив значений времени цикла
	{ 1284	,8	,1	, &internal1_m920_sumtim},	//(internal1_m920_sumtim) sumtim - время в пути
	{ 1285	,8	,1	, &internal1_m920_StSpeed},	//(internal1_m920_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1286	,8	,1	, &internal1_m920_Vz0},	//(internal1_m920_Vz0) Vz0 - предыдущая заданная скорость
	{ 1287	,3	,1	, &internal1_m920_flRazg},	//(internal1_m920_flRazg) признак разгона/торможения
	{ 1288	,8	,1	, &internal1_m920_DelSp},	//(internal1_m920_DelSp) DelSp - время переключения скоростей
	{ 1289	,8	,1	, &internal1_m920_z0},	//(internal1_m920_z0) z0 - точка прекращения движения
	{ 1290	,8	,1	, &internal1_m920_txZS},	//(internal1_m920_txZS) txZS
	{ 1291	,8	,1	, &internal1_m920_tx},	//(internal1_m920_tx) tx
	{ 1292	,8	,1	, &internal1_m920_txd},	//(internal1_m920_txd) txd
	{ 1293	,8	,1	, &internal1_m920_txMBl},	//(internal1_m920_txMBl) tx
	{ 1294	,8	,1	, &internal1_m920_txBl},	//(internal1_m920_txBl) tx
	{ 1295	,8	,1	, &internal1_m920_Speed0},	//(internal1_m920_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1296	,8	,1	, &internal1_m920_xz0},	//(internal1_m920_xz0) xz0 - новое задание мм
	{ 1297	,8	,1	, &internal1_m920_tz0},	//(internal1_m920_tz0) tz0 - время защиты от нового задания сек
	{ 1298	,1	,1	, &internal1_m920_Shift0},	//(internal1_m920_Shift0) Shift0 - признак самохода
	{ 1299	,1	,1	, &internal1_m920_ShCntlSp0},	//(internal1_m920_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1300	,1	,1	, &internal1_m920_ShiftControl},	//(internal1_m920_ShiftControl) ShiftControl - признак самохода
	{ 1301	,8	,1	, &internal1_m489_X0},	//(internal1_m489_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1302	,8	,1	, &internal1_m489_t0},	//(internal1_m489_t0) время нахождения в зоне возврата
	{ 1303	,18	,1	, &internal1_m489_BLDv0},	//(internal1_m489_BLDv0) BlDv - Блокировка движения
	{ 1304	,8	,1	, &internal1_m509_tx},	//(internal1_m509_tx) tx - время накопленное сек
	{ 1305	,18	,1	, &internal1_m509_y0},	//(internal1_m509_y0) y0
	{ 1306	,8	,1	, &internal1_m512_tx},	//(internal1_m512_tx) tx - время накопленное сек
	{ 1307	,18	,1	, &internal1_m512_y0},	//(internal1_m512_y0) y0
	{ 1308	,3	,1	, &internal1_m516_xptr},	//(internal1_m516_xptr) указатель текущей позиции в массиве координат
	{ 1309	,8	,150	, &internal1_m516_x0},	//(internal1_m516_x0) x0 - массив мгновенных значений координат
	{ 1310	,8	,150	, &internal1_m516_tim0},	//(internal1_m516_tim0) tim0 - массив значений времени цикла
	{ 1311	,8	,1	, &internal1_m516_sumtim},	//(internal1_m516_sumtim) sumtim - время в пути
	{ 1312	,8	,1	, &internal1_m516_StSpeed},	//(internal1_m516_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1313	,8	,1	, &internal1_m516_Vz0},	//(internal1_m516_Vz0) Vz0 - предыдущая заданная скорость
	{ 1314	,3	,1	, &internal1_m516_flRazg},	//(internal1_m516_flRazg) признак разгона/торможения
	{ 1315	,8	,1	, &internal1_m516_DelSp},	//(internal1_m516_DelSp) DelSp - время переключения скоростей
	{ 1316	,8	,1	, &internal1_m516_z0},	//(internal1_m516_z0) z0 - точка прекращения движения
	{ 1317	,8	,1	, &internal1_m516_txZS},	//(internal1_m516_txZS) txZS
	{ 1318	,8	,1	, &internal1_m516_tx},	//(internal1_m516_tx) tx
	{ 1319	,8	,1	, &internal1_m516_txd},	//(internal1_m516_txd) txd
	{ 1320	,8	,1	, &internal1_m516_txMBl},	//(internal1_m516_txMBl) tx
	{ 1321	,8	,1	, &internal1_m516_txBl},	//(internal1_m516_txBl) tx
	{ 1322	,8	,1	, &internal1_m516_Speed0},	//(internal1_m516_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1323	,8	,1	, &internal1_m516_xz0},	//(internal1_m516_xz0) xz0 - новое задание мм
	{ 1324	,8	,1	, &internal1_m516_tz0},	//(internal1_m516_tz0) tz0 - время защиты от нового задания сек
	{ 1325	,1	,1	, &internal1_m516_Shift0},	//(internal1_m516_Shift0) Shift0 - признак самохода
	{ 1326	,1	,1	, &internal1_m516_ShCntlSp0},	//(internal1_m516_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1327	,1	,1	, &internal1_m516_ShiftControl},	//(internal1_m516_ShiftControl) ShiftControl - признак самохода
	{ 1328	,1	,1	, &internal1_m615_q0},	//(internal1_m615_q0) q0 - внутренний параметр
	{ 1329	,8	,1	, &internal1_m168_X0},	//(internal1_m168_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1330	,8	,1	, &internal1_m168_t0},	//(internal1_m168_t0) время нахождения в зоне возврата
	{ 1331	,18	,1	, &internal1_m168_BLDv0},	//(internal1_m168_BLDv0) BlDv - Блокировка движения
	{ 1332	,3	,1	, &internal1_m197_xptr},	//(internal1_m197_xptr) указатель текущей позиции в массиве координат
	{ 1333	,8	,150	, &internal1_m197_x0},	//(internal1_m197_x0) x0 - массив мгновенных значений координат
	{ 1334	,8	,150	, &internal1_m197_tim0},	//(internal1_m197_tim0) tim0 - массив значений времени цикла
	{ 1335	,8	,1	, &internal1_m197_sumtim},	//(internal1_m197_sumtim) sumtim - время в пути
	{ 1336	,8	,1	, &internal1_m197_StSpeed},	//(internal1_m197_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1337	,8	,1	, &internal1_m197_Vz0},	//(internal1_m197_Vz0) Vz0 - предыдущая заданная скорость
	{ 1338	,3	,1	, &internal1_m197_flRazg},	//(internal1_m197_flRazg) признак разгона/торможения
	{ 1339	,8	,1	, &internal1_m197_DelSp},	//(internal1_m197_DelSp) DelSp - время переключения скоростей
	{ 1340	,8	,1	, &internal1_m197_z0},	//(internal1_m197_z0) z0 - точка прекращения движения
	{ 1341	,8	,1	, &internal1_m197_txZS},	//(internal1_m197_txZS) txZS
	{ 1342	,8	,1	, &internal1_m197_tx},	//(internal1_m197_tx) tx
	{ 1343	,8	,1	, &internal1_m197_txd},	//(internal1_m197_txd) txd
	{ 1344	,8	,1	, &internal1_m197_txMBl},	//(internal1_m197_txMBl) tx
	{ 1345	,8	,1	, &internal1_m197_txBl},	//(internal1_m197_txBl) tx
	{ 1346	,8	,1	, &internal1_m197_Speed0},	//(internal1_m197_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1347	,8	,1	, &internal1_m197_xz0},	//(internal1_m197_xz0) xz0 - новое задание мм
	{ 1348	,8	,1	, &internal1_m197_tz0},	//(internal1_m197_tz0) tz0 - время защиты от нового задания сек
	{ 1349	,1	,1	, &internal1_m197_Shift0},	//(internal1_m197_Shift0) Shift0 - признак самохода
	{ 1350	,1	,1	, &internal1_m197_ShCntlSp0},	//(internal1_m197_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1351	,1	,1	, &internal1_m197_ShiftControl},	//(internal1_m197_ShiftControl) ShiftControl - признак самохода
	{ 1352	,1	,1	, &internal1_m641_q0},	//(internal1_m641_q0) q0 - внутренний параметр
	{ 1353	,18	,1	, &internal1_m460_DvUp0},	//(internal1_m460_DvUp0) - есть команда на движение вперёд
	{ 1354	,18	,1	, &internal1_m460_DvDw0},	//(internal1_m460_DvDw0) - есть команда на движение назад
	{ 1355	,18	,1	, &internal1_m460_FDvUp0},	//(internal1_m460_FDvUp0) - есть команда на движение вперёд
	{ 1356	,18	,1	, &internal1_m460_FDvDw0},	//(internal1_m460_FDvDw0) - есть команда на движение назад
	{ 1357	,18	,1	, &internal1_m460_BlDv0},	//(internal1_m460_BlDv0) - была блокировка
	{ 1358	,18	,1	, &internal1_m460_Pkv0},	//(internal1_m460_Pkv0) Pkv - передний конечный выключатель
	{ 1359	,18	,1	, &internal1_m460_Pkav0},	//(internal1_m460_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1360	,18	,1	, &internal1_m460_Zkv0},	//(internal1_m460_Zkv0) Zkv - задний конечный выключатель
	{ 1361	,18	,1	, &internal1_m460_Zkav0},	//(internal1_m460_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1362	,8	,1	, &internal1_m460_txNm},	//(internal1_m460_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1363	,8	,1	, &internal1_m460_txSm},	//(internal1_m460_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1364	,8	,1	, &internal1_m460_txHr},	//(internal1_m460_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1365	,8	,1	, &internal1_m460_txLd},	//(internal1_m460_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1366	,18	,1	, &internal1_m460_fef},	//(internal1_m460_fef) fef
	{ 1367	,18	,1	, &internal1_m454_DvUp0},	//(internal1_m454_DvUp0) - есть команда на движение вперёд
	{ 1368	,18	,1	, &internal1_m454_DvDw0},	//(internal1_m454_DvDw0) - есть команда на движение назад
	{ 1369	,18	,1	, &internal1_m454_FDvUp0},	//(internal1_m454_FDvUp0) - есть команда на движение вперёд
	{ 1370	,18	,1	, &internal1_m454_FDvDw0},	//(internal1_m454_FDvDw0) - есть команда на движение назад
	{ 1371	,18	,1	, &internal1_m454_BlDv0},	//(internal1_m454_BlDv0) - была блокировка
	{ 1372	,18	,1	, &internal1_m454_Pkv0},	//(internal1_m454_Pkv0) Pkv - передний конечный выключатель
	{ 1373	,18	,1	, &internal1_m454_Pkav0},	//(internal1_m454_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1374	,18	,1	, &internal1_m454_Zkv0},	//(internal1_m454_Zkv0) Zkv - задний конечный выключатель
	{ 1375	,18	,1	, &internal1_m454_Zkav0},	//(internal1_m454_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1376	,8	,1	, &internal1_m454_txNm},	//(internal1_m454_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1377	,8	,1	, &internal1_m454_txSm},	//(internal1_m454_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1378	,8	,1	, &internal1_m454_txHr},	//(internal1_m454_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1379	,8	,1	, &internal1_m454_txLd},	//(internal1_m454_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1380	,18	,1	, &internal1_m454_fef},	//(internal1_m454_fef) fef
	{ 1381	,8	,1	, &internal1_m807_X0},	//(internal1_m807_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1382	,8	,1	, &internal1_m807_t0},	//(internal1_m807_t0) время нахождения в зоне возврата
	{ 1383	,18	,1	, &internal1_m807_BLDv0},	//(internal1_m807_BLDv0) BlDv - Блокировка движения
	{ 1384	,3	,1	, &internal1_m827_xptr},	//(internal1_m827_xptr) указатель текущей позиции в массиве координат
	{ 1385	,8	,80	, &internal1_m827_x0},	//(internal1_m827_x0) x0 - массив мгновенных значений координат
	{ 1386	,8	,80	, &internal1_m827_tim0},	//(internal1_m827_tim0) tim0 - массив значений времени цикла
	{ 1387	,8	,1	, &internal1_m827_sumtim},	//(internal1_m827_sumtim) sumtim - время в пути
	{ 1388	,8	,1	, &internal1_m827_StSpeed},	//(internal1_m827_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1389	,8	,1	, &internal1_m827_Vz0},	//(internal1_m827_Vz0) Vz0 - предыдущая заданная скорость
	{ 1390	,3	,1	, &internal1_m827_flRazg},	//(internal1_m827_flRazg) признак разгона/торможения
	{ 1391	,8	,1	, &internal1_m827_DelSp},	//(internal1_m827_DelSp) DelSp - время переключения скоростей
	{ 1392	,8	,1	, &internal1_m827_z0},	//(internal1_m827_z0) z0 - точка прекращения движения
	{ 1393	,8	,1	, &internal1_m827_txZS},	//(internal1_m827_txZS) txZS
	{ 1394	,8	,1	, &internal1_m827_tx},	//(internal1_m827_tx) tx
	{ 1395	,8	,1	, &internal1_m827_txd},	//(internal1_m827_txd) txd
	{ 1396	,8	,1	, &internal1_m827_txMBl},	//(internal1_m827_txMBl) tx
	{ 1397	,8	,1	, &internal1_m827_txBl},	//(internal1_m827_txBl) tx
	{ 1398	,8	,1	, &internal1_m827_Speed0},	//(internal1_m827_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1399	,8	,1	, &internal1_m827_xz0},	//(internal1_m827_xz0) xz0 - новое задание мм
	{ 1400	,8	,1	, &internal1_m827_tz0},	//(internal1_m827_tz0) tz0 - время защиты от нового задания сек
	{ 1401	,1	,1	, &internal1_m827_Shift0},	//(internal1_m827_Shift0) Shift0 - признак самохода
	{ 1402	,1	,1	, &internal1_m827_ShCntlSp0},	//(internal1_m827_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1403	,1	,1	, &internal1_m827_ShiftControl},	//(internal1_m827_ShiftControl) ShiftControl - признак самохода
	{ 1404	,8	,1	, &internal1_m1571_X0},	//(internal1_m1571_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1405	,8	,1	, &internal1_m1571_t0},	//(internal1_m1571_t0) время нахождения в зоне возврата
	{ 1406	,18	,1	, &internal1_m1571_BLDv0},	//(internal1_m1571_BLDv0) BlDv - Блокировка движения
	{ 1407	,8	,1	, &internal1_m1107_X0},	//(internal1_m1107_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1408	,8	,1	, &internal1_m1107_t0},	//(internal1_m1107_t0) время нахождения в зоне возврата
	{ 1409	,18	,1	, &internal1_m1107_BLDv0},	//(internal1_m1107_BLDv0) BlDv - Блокировка движения
	{ 1410	,1	,1	, &internal1_m613_q0},	//(internal1_m613_q0) q0 - внутренний параметр
	{ 1411	,8	,1	, &internal1_m1192_X0},	//(internal1_m1192_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1412	,8	,1	, &internal1_m1192_t0},	//(internal1_m1192_t0) время нахождения в зоне возврата
	{ 1413	,18	,1	, &internal1_m1192_BLDv0},	//(internal1_m1192_BLDv0) BlDv - Блокировка движения
	{ 1414	,8	,1	, &internal1_m1212_tx},	//(internal1_m1212_tx) tx - время накопленное сек
	{ 1415	,18	,1	, &internal1_m1212_y0},	//(internal1_m1212_y0) y0
	{ 1416	,8	,1	, &internal1_m1220_tx},	//(internal1_m1220_tx) tx - время накопленное сек
	{ 1417	,18	,1	, &internal1_m1220_y0},	//(internal1_m1220_y0) y0
	{ 1418	,3	,1	, &internal1_m1226_xptr},	//(internal1_m1226_xptr) указатель текущей позиции в массиве координат
	{ 1419	,8	,80	, &internal1_m1226_x0},	//(internal1_m1226_x0) x0 - массив мгновенных значений координат
	{ 1420	,8	,80	, &internal1_m1226_tim0},	//(internal1_m1226_tim0) tim0 - массив значений времени цикла
	{ 1421	,8	,1	, &internal1_m1226_sumtim},	//(internal1_m1226_sumtim) sumtim - время в пути
	{ 1422	,8	,1	, &internal1_m1226_StSpeed},	//(internal1_m1226_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1423	,8	,1	, &internal1_m1226_Vz0},	//(internal1_m1226_Vz0) Vz0 - предыдущая заданная скорость
	{ 1424	,3	,1	, &internal1_m1226_flRazg},	//(internal1_m1226_flRazg) признак разгона/торможения
	{ 1425	,8	,1	, &internal1_m1226_DelSp},	//(internal1_m1226_DelSp) DelSp - время переключения скоростей
	{ 1426	,8	,1	, &internal1_m1226_z0},	//(internal1_m1226_z0) z0 - точка прекращения движения
	{ 1427	,8	,1	, &internal1_m1226_txZS},	//(internal1_m1226_txZS) txZS
	{ 1428	,8	,1	, &internal1_m1226_tx},	//(internal1_m1226_tx) tx
	{ 1429	,8	,1	, &internal1_m1226_txd},	//(internal1_m1226_txd) txd
	{ 1430	,8	,1	, &internal1_m1226_txMBl},	//(internal1_m1226_txMBl) tx
	{ 1431	,8	,1	, &internal1_m1226_txBl},	//(internal1_m1226_txBl) tx
	{ 1432	,8	,1	, &internal1_m1226_Speed0},	//(internal1_m1226_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1433	,8	,1	, &internal1_m1226_xz0},	//(internal1_m1226_xz0) xz0 - новое задание мм
	{ 1434	,8	,1	, &internal1_m1226_tz0},	//(internal1_m1226_tz0) tz0 - время защиты от нового задания сек
	{ 1435	,1	,1	, &internal1_m1226_Shift0},	//(internal1_m1226_Shift0) Shift0 - признак самохода
	{ 1436	,1	,1	, &internal1_m1226_ShCntlSp0},	//(internal1_m1226_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1437	,1	,1	, &internal1_m1226_ShiftControl},	//(internal1_m1226_ShiftControl) ShiftControl - признак самохода
	{ 1438	,1	,1	, &internal1_m633_q0},	//(internal1_m633_q0) q0 - внутренний параметр
	{ 1439	,8	,1	, &internal1_m1584_tx},	//(internal1_m1584_tx) tx - время накопленное сек
	{ 1440	,18	,1	, &internal1_m1584_y0},	//(internal1_m1584_y0) y0
	{ 1441	,8	,1	, &internal1_m1586_tx},	//(internal1_m1586_tx) tx - время накопленное сек
	{ 1442	,18	,1	, &internal1_m1586_y0},	//(internal1_m1586_y0) y0
	{ 1443	,18	,1	, &internal1_m1574_DvUp0},	//(internal1_m1574_DvUp0) - есть команда на движение вперёд
	{ 1444	,18	,1	, &internal1_m1574_DvDw0},	//(internal1_m1574_DvDw0) - есть команда на движение назад
	{ 1445	,18	,1	, &internal1_m1574_FDvUp0},	//(internal1_m1574_FDvUp0) - есть команда на движение вперёд
	{ 1446	,18	,1	, &internal1_m1574_FDvDw0},	//(internal1_m1574_FDvDw0) - есть команда на движение назад
	{ 1447	,18	,1	, &internal1_m1574_BlDv0},	//(internal1_m1574_BlDv0) - была блокировка
	{ 1448	,18	,1	, &internal1_m1574_Pkv0},	//(internal1_m1574_Pkv0) Pkv - передний конечный выключатель
	{ 1449	,18	,1	, &internal1_m1574_Pkav0},	//(internal1_m1574_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1450	,18	,1	, &internal1_m1574_Zkv0},	//(internal1_m1574_Zkv0) Zkv - задний конечный выключатель
	{ 1451	,18	,1	, &internal1_m1574_Zkav0},	//(internal1_m1574_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1452	,8	,1	, &internal1_m1574_txNm},	//(internal1_m1574_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1453	,8	,1	, &internal1_m1574_txSm},	//(internal1_m1574_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1454	,8	,1	, &internal1_m1574_txHr},	//(internal1_m1574_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1455	,8	,1	, &internal1_m1574_txLd},	//(internal1_m1574_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1456	,18	,1	, &internal1_m1574_fef},	//(internal1_m1574_fef) fef
	{ 1457	,3	,1	, &internal1_m1591_xptr},	//(internal1_m1591_xptr) указатель текущей позиции в массиве координат
	{ 1458	,8	,20	, &internal1_m1591_x0},	//(internal1_m1591_x0) x0 - массив мгновенных значений координат
	{ 1459	,8	,20	, &internal1_m1591_tim0},	//(internal1_m1591_tim0) tim0 - массив значений времени цикла
	{ 1460	,8	,1	, &internal1_m1591_sumtim},	//(internal1_m1591_sumtim) sumtim - время в пути
	{ 1461	,8	,1	, &internal1_m1591_StSpeed},	//(internal1_m1591_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1462	,8	,1	, &internal1_m1591_Vz0},	//(internal1_m1591_Vz0) Vz0 - предыдущая заданная скорость
	{ 1463	,3	,1	, &internal1_m1591_flRazg},	//(internal1_m1591_flRazg) признак разгона/торможения
	{ 1464	,8	,1	, &internal1_m1591_DelSp},	//(internal1_m1591_DelSp) DelSp - время переключения скоростей
	{ 1465	,8	,1	, &internal1_m1591_z0},	//(internal1_m1591_z0) z0 - точка прекращения движения
	{ 1466	,8	,1	, &internal1_m1591_txZS},	//(internal1_m1591_txZS) txZS
	{ 1467	,8	,1	, &internal1_m1591_tx},	//(internal1_m1591_tx) tx
	{ 1468	,8	,1	, &internal1_m1591_txd},	//(internal1_m1591_txd) txd
	{ 1469	,8	,1	, &internal1_m1591_txMBl},	//(internal1_m1591_txMBl) tx
	{ 1470	,8	,1	, &internal1_m1591_txBl},	//(internal1_m1591_txBl) tx
	{ 1471	,8	,1	, &internal1_m1591_Speed0},	//(internal1_m1591_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1472	,8	,1	, &internal1_m1591_xz0},	//(internal1_m1591_xz0) xz0 - новое задание мм
	{ 1473	,8	,1	, &internal1_m1591_tz0},	//(internal1_m1591_tz0) tz0 - время защиты от нового задания сек
	{ 1474	,1	,1	, &internal1_m1591_Shift0},	//(internal1_m1591_Shift0) Shift0 - признак самохода
	{ 1475	,1	,1	, &internal1_m1591_ShCntlSp0},	//(internal1_m1591_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1476	,1	,1	, &internal1_m1591_ShiftControl},	//(internal1_m1591_ShiftControl) ShiftControl - признак самохода
	{ 1477	,8	,1	, &internal1_m1123_tx},	//(internal1_m1123_tx) tx - время накопленное сек
	{ 1478	,18	,1	, &internal1_m1123_y0},	//(internal1_m1123_y0) y0
	{ 1479	,8	,1	, &internal1_m1128_tx},	//(internal1_m1128_tx) tx - время накопленное сек
	{ 1480	,18	,1	, &internal1_m1128_y0},	//(internal1_m1128_y0) y0
	{ 1481	,1	,1	, &internal1_m623_q0},	//(internal1_m623_q0) q0 - внутренний параметр
	{ 1482	,1	,1	, &internal1_m588_q0},	//(internal1_m588_q0) q0 - внутренний параметр
	{ 1483	,18	,1	, &internal1_m1115_DvUp0},	//(internal1_m1115_DvUp0) - есть команда на движение вперёд
	{ 1484	,18	,1	, &internal1_m1115_DvDw0},	//(internal1_m1115_DvDw0) - есть команда на движение назад
	{ 1485	,18	,1	, &internal1_m1115_FDvUp0},	//(internal1_m1115_FDvUp0) - есть команда на движение вперёд
	{ 1486	,18	,1	, &internal1_m1115_FDvDw0},	//(internal1_m1115_FDvDw0) - есть команда на движение назад
	{ 1487	,18	,1	, &internal1_m1115_BlDv0},	//(internal1_m1115_BlDv0) - была блокировка
	{ 1488	,18	,1	, &internal1_m1115_Pkv0},	//(internal1_m1115_Pkv0) Pkv - передний конечный выключатель
	{ 1489	,18	,1	, &internal1_m1115_Pkav0},	//(internal1_m1115_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1490	,18	,1	, &internal1_m1115_Zkv0},	//(internal1_m1115_Zkv0) Zkv - задний конечный выключатель
	{ 1491	,18	,1	, &internal1_m1115_Zkav0},	//(internal1_m1115_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1492	,8	,1	, &internal1_m1115_txNm},	//(internal1_m1115_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1493	,8	,1	, &internal1_m1115_txSm},	//(internal1_m1115_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1494	,8	,1	, &internal1_m1115_txHr},	//(internal1_m1115_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1495	,8	,1	, &internal1_m1115_txLd},	//(internal1_m1115_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1496	,18	,1	, &internal1_m1115_fef},	//(internal1_m1115_fef) fef
	{ 1497	,3	,1	, &internal1_m1131_xptr},	//(internal1_m1131_xptr) указатель текущей позиции в массиве координат
	{ 1498	,8	,20	, &internal1_m1131_x0},	//(internal1_m1131_x0) x0 - массив мгновенных значений координат
	{ 1499	,8	,20	, &internal1_m1131_tim0},	//(internal1_m1131_tim0) tim0 - массив значений времени цикла
	{ 1500	,8	,1	, &internal1_m1131_sumtim},	//(internal1_m1131_sumtim) sumtim - время в пути
	{ 1501	,8	,1	, &internal1_m1131_StSpeed},	//(internal1_m1131_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1502	,8	,1	, &internal1_m1131_Vz0},	//(internal1_m1131_Vz0) Vz0 - предыдущая заданная скорость
	{ 1503	,3	,1	, &internal1_m1131_flRazg},	//(internal1_m1131_flRazg) признак разгона/торможения
	{ 1504	,8	,1	, &internal1_m1131_DelSp},	//(internal1_m1131_DelSp) DelSp - время переключения скоростей
	{ 1505	,8	,1	, &internal1_m1131_z0},	//(internal1_m1131_z0) z0 - точка прекращения движения
	{ 1506	,8	,1	, &internal1_m1131_txZS},	//(internal1_m1131_txZS) txZS
	{ 1507	,8	,1	, &internal1_m1131_tx},	//(internal1_m1131_tx) tx
	{ 1508	,8	,1	, &internal1_m1131_txd},	//(internal1_m1131_txd) txd
	{ 1509	,8	,1	, &internal1_m1131_txMBl},	//(internal1_m1131_txMBl) tx
	{ 1510	,8	,1	, &internal1_m1131_txBl},	//(internal1_m1131_txBl) tx
	{ 1511	,8	,1	, &internal1_m1131_Speed0},	//(internal1_m1131_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1512	,8	,1	, &internal1_m1131_xz0},	//(internal1_m1131_xz0) xz0 - новое задание мм
	{ 1513	,8	,1	, &internal1_m1131_tz0},	//(internal1_m1131_tz0) tz0 - время защиты от нового задания сек
	{ 1514	,1	,1	, &internal1_m1131_Shift0},	//(internal1_m1131_Shift0) Shift0 - признак самохода
	{ 1515	,1	,1	, &internal1_m1131_ShCntlSp0},	//(internal1_m1131_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1516	,1	,1	, &internal1_m1131_ShiftControl},	//(internal1_m1131_ShiftControl) ShiftControl - признак самохода
	{ 1517	,1	,1	, &internal1_m736_x0},	//(internal1_m736_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1518	,1	,1	, &internal1_m705_x0},	//(internal1_m705_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1519	,1	,1	, &internal1_m669_x0},	//(internal1_m669_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1520	,1	,1	, &internal1_m761_q0},	//(internal1_m761_q0) q0 - внутренний параметр
	{ 1521	,1	,1	, &internal1_m756_q0},	//(internal1_m756_q0) q0 - внутренний параметр
	{ 1522	,1	,1	, &internal1_m724_q0},	//(internal1_m724_q0) q0 - внутренний параметр
	{ 1523	,1	,1	, &internal1_m729_q0},	//(internal1_m729_q0) q0 - внутренний параметр
	{ 1524	,1	,1	, &internal1_m737_q0},	//(internal1_m737_q0) q0 - внутренний параметр
	{ 1525	,1	,1	, &internal1_m749_q0},	//(internal1_m749_q0) q0 - внутренний параметр
	{ 1526	,1	,1	, &internal1_m727_q0},	//(internal1_m727_q0) q0 - внутренний параметр
	{ 1527	,18	,1	, &internal1_m1168_DvUp0},	//(internal1_m1168_DvUp0) - есть команда на движение вперёд
	{ 1528	,18	,1	, &internal1_m1168_DvDw0},	//(internal1_m1168_DvDw0) - есть команда на движение назад
	{ 1529	,18	,1	, &internal1_m1168_FDvUp0},	//(internal1_m1168_FDvUp0) - есть команда на движение вперёд
	{ 1530	,18	,1	, &internal1_m1168_FDvDw0},	//(internal1_m1168_FDvDw0) - есть команда на движение назад
	{ 1531	,18	,1	, &internal1_m1168_BlDv0},	//(internal1_m1168_BlDv0) - была блокировка
	{ 1532	,18	,1	, &internal1_m1168_Pkv0},	//(internal1_m1168_Pkv0) Pkv - передний конечный выключатель
	{ 1533	,18	,1	, &internal1_m1168_Pkav0},	//(internal1_m1168_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1534	,18	,1	, &internal1_m1168_Zkv0},	//(internal1_m1168_Zkv0) Zkv - задний конечный выключатель
	{ 1535	,18	,1	, &internal1_m1168_Zkav0},	//(internal1_m1168_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1536	,8	,1	, &internal1_m1168_txNm},	//(internal1_m1168_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1537	,8	,1	, &internal1_m1168_txSm},	//(internal1_m1168_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1538	,8	,1	, &internal1_m1168_txHr},	//(internal1_m1168_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1539	,8	,1	, &internal1_m1168_txLd},	//(internal1_m1168_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1540	,18	,1	, &internal1_m1168_fef},	//(internal1_m1168_fef) fef
	{ 1541	,18	,1	, &internal1_m1158_DvUp0},	//(internal1_m1158_DvUp0) - есть команда на движение вперёд
	{ 1542	,18	,1	, &internal1_m1158_DvDw0},	//(internal1_m1158_DvDw0) - есть команда на движение назад
	{ 1543	,18	,1	, &internal1_m1158_FDvUp0},	//(internal1_m1158_FDvUp0) - есть команда на движение вперёд
	{ 1544	,18	,1	, &internal1_m1158_FDvDw0},	//(internal1_m1158_FDvDw0) - есть команда на движение назад
	{ 1545	,18	,1	, &internal1_m1158_BlDv0},	//(internal1_m1158_BlDv0) - была блокировка
	{ 1546	,18	,1	, &internal1_m1158_Pkv0},	//(internal1_m1158_Pkv0) Pkv - передний конечный выключатель
	{ 1547	,18	,1	, &internal1_m1158_Pkav0},	//(internal1_m1158_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1548	,18	,1	, &internal1_m1158_Zkv0},	//(internal1_m1158_Zkv0) Zkv - задний конечный выключатель
	{ 1549	,18	,1	, &internal1_m1158_Zkav0},	//(internal1_m1158_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1550	,8	,1	, &internal1_m1158_txNm},	//(internal1_m1158_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1551	,8	,1	, &internal1_m1158_txSm},	//(internal1_m1158_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1552	,8	,1	, &internal1_m1158_txHr},	//(internal1_m1158_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1553	,8	,1	, &internal1_m1158_txLd},	//(internal1_m1158_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1554	,18	,1	, &internal1_m1158_fef},	//(internal1_m1158_fef) fef
	{ 1555	,18	,1	, &internal1_m781_DvUp0},	//(internal1_m781_DvUp0) - есть команда на движение вперёд
	{ 1556	,18	,1	, &internal1_m781_DvDw0},	//(internal1_m781_DvDw0) - есть команда на движение назад
	{ 1557	,18	,1	, &internal1_m781_FDvUp0},	//(internal1_m781_FDvUp0) - есть команда на движение вперёд
	{ 1558	,18	,1	, &internal1_m781_FDvDw0},	//(internal1_m781_FDvDw0) - есть команда на движение назад
	{ 1559	,18	,1	, &internal1_m781_BlDv0},	//(internal1_m781_BlDv0) - была блокировка
	{ 1560	,18	,1	, &internal1_m781_Pkv0},	//(internal1_m781_Pkv0) Pkv - передний конечный выключатель
	{ 1561	,18	,1	, &internal1_m781_Pkav0},	//(internal1_m781_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1562	,18	,1	, &internal1_m781_Zkv0},	//(internal1_m781_Zkv0) Zkv - задний конечный выключатель
	{ 1563	,18	,1	, &internal1_m781_Zkav0},	//(internal1_m781_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1564	,8	,1	, &internal1_m781_txNm},	//(internal1_m781_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1565	,8	,1	, &internal1_m781_txSm},	//(internal1_m781_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1566	,8	,1	, &internal1_m781_txHr},	//(internal1_m781_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1567	,8	,1	, &internal1_m781_txLd},	//(internal1_m781_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1568	,18	,1	, &internal1_m781_fef},	//(internal1_m781_fef) fef
	{ 1569	,18	,1	, &internal1_m777_DvUp0},	//(internal1_m777_DvUp0) - есть команда на движение вперёд
	{ 1570	,18	,1	, &internal1_m777_DvDw0},	//(internal1_m777_DvDw0) - есть команда на движение назад
	{ 1571	,18	,1	, &internal1_m777_FDvUp0},	//(internal1_m777_FDvUp0) - есть команда на движение вперёд
	{ 1572	,18	,1	, &internal1_m777_FDvDw0},	//(internal1_m777_FDvDw0) - есть команда на движение назад
	{ 1573	,18	,1	, &internal1_m777_BlDv0},	//(internal1_m777_BlDv0) - была блокировка
	{ 1574	,18	,1	, &internal1_m777_Pkv0},	//(internal1_m777_Pkv0) Pkv - передний конечный выключатель
	{ 1575	,18	,1	, &internal1_m777_Pkav0},	//(internal1_m777_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1576	,18	,1	, &internal1_m777_Zkv0},	//(internal1_m777_Zkv0) Zkv - задний конечный выключатель
	{ 1577	,18	,1	, &internal1_m777_Zkav0},	//(internal1_m777_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1578	,8	,1	, &internal1_m777_txNm},	//(internal1_m777_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1579	,8	,1	, &internal1_m777_txSm},	//(internal1_m777_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1580	,8	,1	, &internal1_m777_txHr},	//(internal1_m777_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1581	,8	,1	, &internal1_m777_txLd},	//(internal1_m777_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1582	,18	,1	, &internal1_m777_fef},	//(internal1_m777_fef) fef
	{ 1583	,18	,1	, &internal1_m359_DvUp0},	//(internal1_m359_DvUp0) - есть команда на движение вперёд
	{ 1584	,18	,1	, &internal1_m359_DvDw0},	//(internal1_m359_DvDw0) - есть команда на движение назад
	{ 1585	,18	,1	, &internal1_m359_FDvUp0},	//(internal1_m359_FDvUp0) - есть команда на движение вперёд
	{ 1586	,18	,1	, &internal1_m359_FDvDw0},	//(internal1_m359_FDvDw0) - есть команда на движение назад
	{ 1587	,18	,1	, &internal1_m359_BlDv0},	//(internal1_m359_BlDv0) - была блокировка
	{ 1588	,18	,1	, &internal1_m359_Pkv0},	//(internal1_m359_Pkv0) Pkv - передний конечный выключатель
	{ 1589	,18	,1	, &internal1_m359_Pkav0},	//(internal1_m359_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1590	,18	,1	, &internal1_m359_Zkv0},	//(internal1_m359_Zkv0) Zkv - задний конечный выключатель
	{ 1591	,18	,1	, &internal1_m359_Zkav0},	//(internal1_m359_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1592	,8	,1	, &internal1_m359_txNm},	//(internal1_m359_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1593	,8	,1	, &internal1_m359_txSm},	//(internal1_m359_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1594	,8	,1	, &internal1_m359_txHr},	//(internal1_m359_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1595	,8	,1	, &internal1_m359_txLd},	//(internal1_m359_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1596	,18	,1	, &internal1_m359_fef},	//(internal1_m359_fef) fef
	{ 1597	,18	,1	, &internal1_m388_DvUp0},	//(internal1_m388_DvUp0) - есть команда на движение вперёд
	{ 1598	,18	,1	, &internal1_m388_DvDw0},	//(internal1_m388_DvDw0) - есть команда на движение назад
	{ 1599	,18	,1	, &internal1_m388_FDvUp0},	//(internal1_m388_FDvUp0) - есть команда на движение вперёд
	{ 1600	,18	,1	, &internal1_m388_FDvDw0},	//(internal1_m388_FDvDw0) - есть команда на движение назад
	{ 1601	,18	,1	, &internal1_m388_BlDv0},	//(internal1_m388_BlDv0) - была блокировка
	{ 1602	,18	,1	, &internal1_m388_Pkv0},	//(internal1_m388_Pkv0) Pkv - передний конечный выключатель
	{ 1603	,18	,1	, &internal1_m388_Pkav0},	//(internal1_m388_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1604	,18	,1	, &internal1_m388_Zkv0},	//(internal1_m388_Zkv0) Zkv - задний конечный выключатель
	{ 1605	,18	,1	, &internal1_m388_Zkav0},	//(internal1_m388_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1606	,8	,1	, &internal1_m388_txNm},	//(internal1_m388_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1607	,8	,1	, &internal1_m388_txSm},	//(internal1_m388_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1608	,8	,1	, &internal1_m388_txHr},	//(internal1_m388_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1609	,8	,1	, &internal1_m388_txLd},	//(internal1_m388_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1610	,18	,1	, &internal1_m388_fef},	//(internal1_m388_fef) fef
	{ 1611	,18	,1	, &internal1_m382_DvUp0},	//(internal1_m382_DvUp0) - есть команда на движение вперёд
	{ 1612	,18	,1	, &internal1_m382_DvDw0},	//(internal1_m382_DvDw0) - есть команда на движение назад
	{ 1613	,18	,1	, &internal1_m382_FDvUp0},	//(internal1_m382_FDvUp0) - есть команда на движение вперёд
	{ 1614	,18	,1	, &internal1_m382_FDvDw0},	//(internal1_m382_FDvDw0) - есть команда на движение назад
	{ 1615	,18	,1	, &internal1_m382_BlDv0},	//(internal1_m382_BlDv0) - была блокировка
	{ 1616	,18	,1	, &internal1_m382_Pkv0},	//(internal1_m382_Pkv0) Pkv - передний конечный выключатель
	{ 1617	,18	,1	, &internal1_m382_Pkav0},	//(internal1_m382_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1618	,18	,1	, &internal1_m382_Zkv0},	//(internal1_m382_Zkv0) Zkv - задний конечный выключатель
	{ 1619	,18	,1	, &internal1_m382_Zkav0},	//(internal1_m382_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1620	,8	,1	, &internal1_m382_txNm},	//(internal1_m382_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1621	,8	,1	, &internal1_m382_txSm},	//(internal1_m382_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1622	,8	,1	, &internal1_m382_txHr},	//(internal1_m382_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1623	,8	,1	, &internal1_m382_txLd},	//(internal1_m382_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1624	,18	,1	, &internal1_m382_fef},	//(internal1_m382_fef) fef
	{ 1625	,1	,1	, &internal1_m733_q0},	//(internal1_m733_q0) q0 - внутренний параметр
	{ 1626	,1	,1	, &internal1_m730_q0},	//(internal1_m730_q0) q0 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="du.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{737,"fEM_A1UC03RDU\0"}, 
{738,"dEM_A1UC05UDU\0"}, 
{739,"dEM_A1UC06UDU\0"}, 
{740,"dEM_A2UC06UDU\0"}, 
{741,"dEM_A2UC05UDU\0"}, 
{742,"fEM_A2UC03RDU\0"}, 
{743,"dEM_A3UC06UDU\0"}, 
{744,"dEM_A3UC05UDU\0"}, 
{745,"fEM_A3UC03RDU\0"}, 
{746,"dEM_A8UC06UDU\0"}, 
{747,"fEM_A8UC03RDU\0"}, 
{748,"dEM_A8UC05UDU\0"}, 
{749,"fEM_R0UV81RDU\0"}, 
{750,"fEM_R0UV82RDU\0"}, 
{751,"fEM_R0UV83RDU\0"}, 
{752,"fEM_R0UV84RDU\0"}, 
{753,"fEM_R0UV86RDU\0"}, 
{754,"fEM_R0UV85RDU\0"}, 
{755,"fEM_R0UV87RDU\0"}, 
{756,"fEM_A3UP03RDU\0"}, 
{757,"fEM_A3UP04RDU\0"}, 
{758,"fEM_A3UP43RDU\0"}, 
{759,"fEM_A3UP44RDU\0"}, 
{760,"fEM_A3UP53RDU\0"}, 
{761,"fEM_A3UP85RDU\0"}, 
{762,"fEM_A3UP88RDU\0"}, 
{763,"fEM_A3UP86RDU\0"}, 
{764,"fEM_B8UV01RDU\0"}, 
{765,"fEM_B8UV02RDU\0"}, 
{766,"fEM_B8UV03RDU\0"}, 
{767,"fEM_B8UL04RDU\0"}, 
{768,"iEM_A2UV03CDU\0"}, 
{769,"fEM_A2UV01RDU\0"}, 
{770,"fEM_A2UV02RDU\0"}, 
{771,"fEM_A1UV01RDU\0"}, 
{772,"fEM_A1UV02RDU\0"}, 
{773,"fEM_A1UC06RDU\0"}, 
{774,"fEM_A1UC05RDU\0"}, 
{775,"fEM_A1UL04RDU\0"}, 
{776,"fEM_A3UV01RDU\0"}, 
{777,"fEM_A3UV02RDU\0"}, 
{778,"fEM_A3UC06RDU\0"}, 
{779,"fEM_A3UC05RDU\0"}, 
{780,"fEM_A3UL04RDU\0"}, 
{781,"fEM_A3UP54RDU\0"}, 
{782,"fEM_A3UP87RDU\0"}, 
{783,"fEM_R0UL05RDU\0"}, 
{784,"fEM_R0UL20RDU\0"}, 
{785,"fEM_B8UV04RDU\0"}, 
{786,"fEM_B8UC06RDU\0"}, 
{787,"fEM_B8UC05RDU\0"}, 
{788,"fEM_A2UL05RDU\0"}, 
{789,"fEM_A2UL03RDU\0"}, 
{790,"fEM_A2UC06RDU\0"}, 
{791,"fEM_A2UC05RDU\0"}, 
{792,"fEM_A2UL04RDU\0"}, 
{793,"fEM_A1UL03RDU\0"}, 
{794,"fEM_A1UL05RDU\0"}, 
{795,"fEM_A3UL03RDU\0"}, 
{796,"fEM_A3UL05RDU\0"}, 
{797,"fEM_A1UC08RDU\0"}, 
{798,"fEM_A3UC08RDU\0"}, 
{799,"fEM_A1UC07RDU\0"}, 
{800,"fEM_A1UL01RDU\0"}, 
{801,"fEM_A3UC07RDU\0"}, 
{802,"fEM_A3UL01RDU\0"}, 
{803,"fEM_A2UC08RDU\0"}, 
{804,"fEM_A2UC07RDU\0"}, 
{805,"fEM_A2UL01RDU\0"}, 
{806,"fEM_B8UC01RDU\0"}, 
{807,"fEM_B8UL07RDU\0"}, 
{808,"fEM_B8UC02RDU\0"}, 
{809,"fEM_B8UL01RDU\0"}, 
{810,"fEM_B8UL05RDU\0"}, 
{811,"fEM_B8UL03RDU\0"}, 
{812,"fEM_B8UL06RDU\0"}, 
{813,"fEM_A9UZ03RDU\0"}, 
{814,"fEM_A9UZ04RDU\0"}, 
{815,"fEM_A9UZ05RDU\0"}, 
{816,"fEM_R4UZ04RDU\0"}, 
{817,"fEM_R4UZ03RDU\0"}, 
{818,"fEM_R4UZ05RDU\0"}, 
{819,"fEM_A5UZ03RDU\0"}, 
{820,"fEM_A5UZ04RDU\0"}, 
{821,"fEM_A5UZ05RDU\0"}, 
{822,"fEM_A4UZ03RDU\0"}, 
{823,"fEM_A4UZ04RDU\0"}, 
{824,"fEM_A4UZ05RDU\0"}, 
{825,"fEM_A6UZ03RDU\0"}, 
{826,"fEM_A6UZ04RDU\0"}, 
{827,"fEM_A6UZ05RDU\0"}, 
{828,"fEM_R1UZ03RDU\0"}, 
{829,"fEM_R1UZ04RDU\0"}, 
{830,"fEM_R1UZ05RDU\0"}, 
{831,"fEM_R0UL04RDU\0"}, 
{832,"fEM_R0UL06RDU\0"}, 
{833,"fEM_R0UL03RDU\0"}, 
{834,"fEM_R0UL17RDU\0"}, 
{835,"fEM_R0UL19RDU\0"}, 
{836,"fEM_R0UL07RDU\0"}, 
{837,"fEM_R0UL18RDU\0"}, 
{838,"fEM_R0UL16RDU\0"}, 
{839,"fEM_R0UL02RDU\0"}, 
{840,"fEM_R0UN08RDU\0"}, 
{841,"fEM_R0UN07RDU\0"}, 
{842,"fEM_R0UN06RDU\0"}, 
{843,"fEM_R0UN05RDU\0"}, 
{844,"fEM_R0UN04RDU\0"}, 
{845,"fEM_R0UN03RDU\0"}, 
{846,"fEM_R0UN02RDU\0"}, 
{847,"fEM_R0UN01RDU\0"}, 
{848,"fEM_A2UC82RDU\0"}, 
{849,"fEM_A2UC83RDU\0"}, 
{850,"fEM_A1UC83RDU\0"}, 
{851,"fEM_A2UC81RDU\0"}, 
{852,"fEM_A1UC81RDU\0"}, 
{853,"fEM_A1UC82RDU\0"}, 
{854,"fEM_A2UL83RDU\0"}, 
{855,"fEM_A3UC81RDU\0"}, 
{856,"fEM_A3UC82RDU\0"}, 
{857,"fEM_R0UN80RDU\0"}, 
{858,"iEM_A2UV01IDU\0"}, 
{859,"iEM_A2UV02IDU\0"}, 
{860,"iEM_A1UV01IDU\0"}, 
{861,"iEM_A1UV02IDU\0"}, 
{862,"iEM_A1UV03IDU\0"}, 
{863,"iEM_A3UV01IDU\0"}, 
{864,"iEM_A3UV02IDU\0"}, 
{865,"lEM_R0MD01LC1\0"}, 
{866,"fEM_A3UC09RDU\0"}, 
{867,"fEM_A2UC02RDU\0"}, 
{868,"fEM_A1UC02RDU\0"}, 
{869,"fEM_A3UC02RDU\0"}, 
{870,"fEM_R0UL21RDU\0"}, 
{871,"fEM_R0UN09RDU\0"}, 
{872,"fEM_R0UN11RDU\0"}, 
{873,"fEM_R0UN12RDU\0"}, 
{874,"fEM_R0UN13RDU\0"}, 
{875,"fEM_R0UN14RDU\0"}, 
{876,"fEM_R0UN16RDU\0"}, 
{877,"fEM_R0UN17RDU\0"}, 
{878,"fEM_R0UN18RDU\0"}, 
{879,"fEM_R0UN19RDU\0"}, 
{880,"fEM_R0UN70LDU\0"}, 
{881,"fEM_R0UN71LDU\0"}, 
{882,"fEM_R0UN72LDU\0"}, 
{883,"fEM_R0UN73LDU\0"}, 
{884,"fEM_R0UN74LDU\0"}, 
{885,"fEM_R0UN75LDU\0"}, 
{886,"fEM_R0UN80LDU\0"}, 
{887,"fEM_R0UN81LDU\0"}, 
{888,"fEM_R0UN82LDU\0"}, 
{889,"fEM_R0UN83LDU\0"}, 
{890,"fEM_R0UN84LDU\0"}, 
{891,"fEM_R0UN85LDU\0"}, 
{892,"fEM_R0UT20RDU\0"}, 
{893,"fEM_R0UN25RDU\0"}, 
{894,"fEM_R0UN15RDU\0"}, 
{895,"fEM_R0UN26RDU\0"}, 
{896,"fEM_R0UN27RDU\0"}, 
{897,"fEM_R0UN24RDU\0"}, 
{898,"fEM_R0UL25RDU\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_DU[]={  // 
	{&B2MD11LP1,1,0},	//( - , DU) Кнопка ПУСК РБ2
	{&B1MD12LP1,1,1},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
	{&B1MD11LP1,1,2},	//( - , DU) Кнопка ПУСК ББ2
	{&R0MW17LP1,1,3},	//( - , DU) Переключатель АВТ/Р
	{&A1MD11LP1,1,4},	//( - , DU) Кнопка ПУСК ББ1
	{&A1MD12LP1,1,5},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
	{&R0MD33LP1,1,6},	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
	{&A3MD11LP1,1,7},	//( - , DU) Кнопка ПУСК ИС1
	{&A3MD12LP1,1,8},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
	{&A3VZ15LZ2,1,9},	//( - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{&A3VZ13LZ2,1,10},	//( - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{&R0AD14LZ2,1,11},	//( - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
	{&A1VN71LZ2,1,12},	//( - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{&R0VZ71LZ2,1,13},	//( - K22VDSR, DU) Обобщенный сигнал АЗ 2 канала
	{&B2MD12LP1,1,14},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
	{&A2MD11LP1,1,15},	//( - , DU) Кнопка ПУСК РБ1
	{&A2MD12LP1,1,16},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
	{&R0IS02LDU,1,17},	//( - K30VDSR, DU) Разрешение ввода от имитатора
	{&R0MD34LP1,1,18},	//( - , DU) Кнопка КВИТИРОВАТЬ
	{&B3MD12LP1,1,19},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
	{&B3MD11LP1,1,20},	//( - , DU) Кнопка ПУСК ИС2
	{&R0MD11LP2,1,21},	//( - , DU) Кнопка Пуск проверки схем сброса
	{&C1MD31LP2,1,22},	//( - , DU) Кнопка СБРОС ББ
	{&C1MD31LP1,1,23},	//( - , DU) Кнопка СБРОС ББ
	{&B2MC01LC1,1,24},	//( - , DU) Настроить энкодер РБ2
	{&A1MC01LC2,1,25},	//( - , DU) Настроить энкодер ББ1
	{&A1MC01LC1,1,26},	//( - , DU) Настроить энкодер ББ1
	{&B1MC01LC2,1,27},	//( - , DU) Настроить энкодер ББ2
	{&B1MC01LC1,1,28},	//( - , DU) Настроить энкодер ББ2
	{&syn_B3VP52LDU,1,29},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
	{&syn_A3VP52LDU,1,30},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
	{&B1VP41LZ2,1,31},	//( - , DU) Давление СБРОС ББ2 ниже АС
	{&B1VP41LZ1,1,32},	//( - , DU) Давление СБРОС ББ2 ниже АС
	{&syn_R0EE03LDU,1,33},	//( - , DU) ВПИС ИС
	{&B2MC01LC2,1,34},	//( - , DU) Настроить энкодер РБ2
	{&A2MC01LC1,1,35},	//( - , DU) Настроить энкодер РБ1
	{&A2MC01LC2,1,36},	//( - , DU) Настроить энкодер РБ1
	{&B3MC01LC1,1,37},	//( - , DU) Настроить энкодер ИС2
	{&B3MC01LC2,1,38},	//( - , DU) Настроить энкодер ИС2
	{&A3MC01LC1,1,39},	//( - , DU) Настроить энкодер ИС1
	{&A3MC01LC2,1,40},	//( - , DU) Настроить энкодер ИС1
	{&B8MC01LC1,1,41},	//( - , DU) Настроить энкодер АЗ2
	{&B8MC01LC2,1,42},	//( - , DU) Настроить энкодер АЗ2
	{&A8MC01LC1,1,43},	//( - , DU) Настроить энкодер ДС2
	{&A8MC01LC2,1,44},	//( - , DU) Настроить энкодер ДС2
	{&C2MD31LP1,1,45},	//( - , DU) Кнопка СБРОС РБ
	{&A1VP41LZ2,1,46},	//( - , DU) Давление СБРОС ББ1 ниже АС
	{&A1VP41LZ1,1,47},	//( - , DU) Давление СБРОС ББ1 ниже АС
	{&R0MD11LP1,1,48},	//( - , DU) Кнопка ПУСК
	{&R4MD21LP2,1,49},	//( - , DU) Кнопка НАЗАД  (тележки)
	{&R4MD31LP2,1,50},	//( - , DU) Кнопка СТОП  (тележки)
	{&R4MD11LP2,1,51},	//( - , DU) Кнопка ВПЕРЁД  (тележки)
	{&R0MD31LP1,1,52},	//( - , DU) Кнопка СТОП
	{&R0MD32LP1,1,53},	//( - , DU) Кнопка СПУСК
	{&R0MW13LP2,1,54},	//( - , DU) Переключатель СЕТЬ
	{&R0NE01LDU,1,55},	//( - , DU) Потеря связи с БАЗ1
	{&R0NE02LDU,1,56},	//( - , DU) Потеря связи с БАЗ2
	{&R0NE08LDU,1,57},	//( - , DU) Потеря связи с ОПУ
	{&lEM_R0MD01LC1,1,58},	//( - , DU) Ручное управление ОРР
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
	{&B3IS35LDU,1,20},	//( - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
	{&B3IS33LDU,1,21},	//( - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
	{&B3IS31LDU,1,22},	//( - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
	{&B2IS33LDU,1,23},	//( - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
	{&A1AB19LDU,1,24},	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
	{&A4IS10LDU,1,25},	//( - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
	{&A3IS35LDU,1,26},	//( - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
	{&A3IS33LDU,1,27},	//( - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
	{&A3IS31LDU,1,28},	//( - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
	{&A2IS33LDU,1,29},	//( - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
	{&R0VZ71LDU,1,30},	//( - , DU) Обобщенный сигнал АЗ
	{&R0IS01LDU,1,31},	//( - K29VDSR, DU) Признак работы с имитатором
	{&R0VP73LDU,1,32},	//( - , DU) ПС давления для РУ
	{&B2VS11LDU,1,33},	//( - , DU) Движение РБ2 в сторону ВУ
	{&B2VS21LDU,1,34},	//( - , DU) Движение РБ2 в сторону НУ
	{&A7AS31LDU,1,35},	//( - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
	{&B7AS31LDU,1,36},	//( - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
	{&A7AZ03LDU,1,37},	//( - , DU) Несанкционированное включение обдува АЗ1
	{&B7AZ03LDU,1,38},	//( - , DU) Несанкционированное включение обдува АЗ2
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
	{&A9AZ03LDU,1,64},	//( - , DU) Несанкционированное перемещение НИ ДС1
	{&B9IS11LDU,1,65},	//( - K25VDSR, DU) Приход на ВУ НИ ДС2
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
	{&R0EE02LDU,1,93},	//( - , DU) Питание  АКНП  отключить
	{&B0VS11LDU,1,94},	//( - , DU) АЗ2 готова к работе
	{&A0VS11LDU,1,95},	//( - , DU) АЗ1 готова к работе
	{&B0VN01LDU,1,96},	//( - , DU) Каналы АЗ2 проверены
	{&A0VN01LDU,1,97},	//( - , DU) Каналы АЗ1 проверены
	{&B0VP01LDU,1,98},	//( - , DU) Давление в системы АЗ2 подано
	{&A0VP01LDU,1,99},	//( - , DU) Давление в системы АЗ1 подано
	{&B0VE01LDU,1,100},	//( - , DU) Напряжение в системы АЗ2 подано
	{&A0VE01LDU,1,101},	//( - , DU) Напряжение в системы АЗ1 подано
	{&A3VP82LDU,1,102},	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
	{&B3VP82LDU,1,103},	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
	{&A3VP42LDU,1,104},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
	{&A3VP52LDU,1,105},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
	{&B3VP42LDU,1,106},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
	{&B3VP52LDU,1,107},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
	{&A2ZAV,1,108},	//( - , DU) Завершение РБ1,2
	{&B8ZAV,1,109},	//( - , DU) 
	{&A5ZAV,1,110},	//( - , DU) 
	{&R2ZAV,1,111},	//( - , DU) 
	{&A6ZAV,1,112},	//( - , DU) 
	{&A4ZAV,1,113},	//( - , DU) 
	{&R0AB13LDU,1,114},	//( - , DU) Ошибка в заданной координате  АЗ2
	{&R0AB12LDU,1,115},	//( - , DU) Ошибка в заданной координате  ИС2
	{&R0AB11LDU,1,116},	//( - , DU) Ошибка в заданной координате  ИС1
	{&R0AB10LDU,1,117},	//( - , DU) Ошибка в заданной координате ББ2
	{&R0AB09LDU,1,118},	//( - , DU) Ошибка в заданной координате ББ1
	{&B4IS10LDU,1,119},	//( - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
	{&R3IS11LDU,1,120},	//( - K17VDSR, DU) Приход на ВУ гомогенных дверей
	{&R3IS21LDU,1,121},	//( - K18VDSR, DU) Приход на НУ гомогенных дверей
	{&R0AB03LDU,1,122},	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
	{&R0AB05LDU,1,123},	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
	{&A2AB15LDU,1,124},	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{&B2AB15LDU,1,125},	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{&R0VX02LDU,1,126},	//( - , DU) Импульс разрешен
	{&R0EE03LDU,1,127},	//( - , DU) ВПИС ИС
	{&R0AB07LDU,1,128},	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
	{&R0VS11LDU,1,129},	//( - , DU) РУ не готова к работе
	{&B6AB05LDU,1,130},	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
	{&R0AB08LDU,1,131},	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
	{&R0VL22LDU,1,132},	//( - , DU) Конец программы 200сек
	{&B8IS21LDU,1,133},	//( - K20VDSR, DU) Приход на НУ1 АЗ2
	{&B8IS12LDU,1,134},	//( - K21VDSR, DU) Приход на ВУ2 АЗ2
	{&R0AB19LDU,1,135},	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
	{&R0AB20LDU,1,136},	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
	{&A3AB15LDU,1,137},	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
	{&A8ZAV,1,138},	//( - , DU) 
	{&A9ZAV,1,139},	//( - , DU) Завершение НИ ДС1(2)
	{&R4ABL,1,140},	//( - , DU) Блокировка тележки -
	{&A4UP,1,141},	//( - , DU) 
	{&A4DW,1,142},	//( - , DU) 
	{&R0AB14LDU,1,143},	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
	{&R0AB15LDU,1,144},	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
	{&A3IS12LDU,1,145},	//( - , DU) Приход на ВУ штока ИС1
	{&B3IS12LDU,1,146},	//( - , DU) Приход на ВУ штока ИС2
	{&A1ZAV,1,147},	//( - , DU) 
	{&A3ZAV,1,148},	//( - , DU) 
	{&B1AB19LDU,1,149},	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
	{&R0AB16LDU,1,150},	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
	{&R0AB17LDU,1,151},	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
	{&R0AB18LDU,1,152},	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
	{&B1IS12LDU,1,153},	//( - K07VDSR, DU) Магнит ББ2 зацеплен
	{&A2IS12LDU,1,154},	//( - K10VDSR, DU) Магнит РБ1 зацеплен
	{&A1IS12LDU,1,155},	//( - K07VDSR, DU) Магнит ББ1 зацеплен
	{&B5AB04LDU,1,156},	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
	{&A5AB04LDU,1,157},	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
	{&B4AB02LDU,1,158},	//( - , DU) Блокировка движения НИ2 - Нет перемещения
	{&B4AB01LDU,1,159},	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
	{&B4AZ03LDU,1,160},	//( - , DU) Несанкционированное перемещение НИ2
	{&A4AB02LDU,1,161},	//( - , DU) Блокировка движения НИ1 - Нет перемещения
	{&A4AB01LDU,1,162},	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
	{&A4AZ03LDU,1,163},	//( - , DU) Несанкционированное перемещение НИ1
	{&B4IS21LDU,1,164},	//( - K32VDSR, DU) Приход на НУ НИ2
	{&A4IS21LDU,1,165},	//( - K15VDSR, DU) Приход на НУ НИ1
	{&B5AB02LDU,1,166},	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
	{&B5AB01LDU,1,167},	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
	{&B5AZ03LDU,1,168},	//( - , DU) Несанкционированное перемещение НЛ2
	{&A5AB02LDU,1,169},	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
	{&A5AB01LDU,1,170},	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
	{&A5AZ03LDU,1,171},	//( - , DU) Несанкционированное перемещение НЛ1
	{&B5IS21LDU,1,172},	//( - K16VDSR, DU) Приход на НУ НЛ2
	{&B5IS11LDU,1,173},	//( - K15VDSR, DU) Приход на ВУ НЛ2
	{&A5IS21LDU,1,174},	//( - K12VDSR, DU) Приход на НУ НЛ1
	{&A5IS11LDU,1,175},	//( - K11VDSR, DU) Приход на ВУ НЛ1
	{&B5VS12LDU,1,176},	//( - K14VDSR, DU) Движение НЛ2 в сторону ВУ
	{&B5VS22LDU,1,177},	//( - K15VDSR, DU) Движение НЛ2 в сторону НУ
	{&A5VS12LDU,1,178},	//( - K11VDSR, DU) Движение НЛ1 в сторону ВУ
	{&A5VS22LDU,1,179},	//( - K12VDSR, DU) Движение НЛ1 в сторону НУ
	{&R4AD20LDU,1,180},	//( - K14FDSR, DU) Перемещение тележки назад
	{&R4AB18LDU,1,181},	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
	{&R4AB17LDU,1,182},	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
	{&R4AB16LDU,1,183},	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
	{&R5IS11LDU,1,184},	//( - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
	{&A8AB06LDU,1,185},	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
	{&A8VS12LDU,1,186},	//( - , DU) Движение ДС2 в сторону ВУ
	{&B8AB02LDU,1,187},	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
	{&B8AB14LDU,1,188},	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
	{&B8AB13LDU,1,189},	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
	{&B8AB12LDU,1,190},	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
	{&B8AB11LDU,1,191},	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
	{&B8AB10LDU,1,192},	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
	{&B8AB09LDU,1,193},	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
	{&B8AB08LDU,1,194},	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
	{&B8AB04LDU,1,195},	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
	{&B8AB01LDU,1,196},	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
	{&B8IS11LDU,1,197},	//( - K19VDSR, DU) Приход на ВУ1 АЗ2
	{&B8AZ03LDU,1,198},	//( - , DU) Несанкционированное перемещение АЗ2
	{&B2IS12LDU,1,199},	//( - K10VDSR, DU) Магнит РБ2 зацеплен
	{&R4IS11LDU,1,200},	//( - K05VDSR, DU) Приход на ВУ1 тележки
	{&A6AB06LDU,1,201},	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
	{&A6AB07LDU,1,202},	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
	{&A6AB08LDU,1,203},	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
	{&A6AB09LDU,1,204},	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
	{&B6AB06LDU,1,205},	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
	{&B6AB07LDU,1,206},	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
	{&B6AB08LDU,1,207},	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
	{&B6AB09LDU,1,208},	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
	{&A6AB05LDU,1,209},	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
	{&B8VS12LDU,1,210},	//( - , DU) Движение АЗ2 в сторону ВУ
	{&B8AB06LDU,1,211},	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
	{&B8AB07LDU,1,212},	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
	{&B8AB05LDU,1,213},	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
	{&B8VS22LDU,1,214},	//( - , DU) Движение АЗ2 в сторону НУ
	{&B6AZ03LDU,1,215},	//( - , DU) Несанкционированное перемещение БЗ2
	{&A6AB02LDU,1,216},	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
	{&A6AB01LDU,1,217},	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
	{&A6AZ03LDU,1,218},	//( - , DU) Несанкционированное перемещение БЗ1
	{&B6VS12LDU,1,219},	//( - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
	{&B6VS22LDU,1,220},	//( - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
	{&A6VS12LDU,1,221},	//( - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
	{&A6VS22LDU,1,222},	//( - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
	{&B6IS21LDU,1,223},	//( - K14VDSR, DU) Приход на НУ БЗ2
	{&B6IS11LDU,1,224},	//( - K13VDSR, DU) Приход на ВУ БЗ2
	{&A6IS21LDU,1,225},	//( - K10VDSR, DU) Приход на НУ БЗ1
	{&A6IS11LDU,1,226},	//( - K09VDSR, DU) Приход на ВУ БЗ1
	{&R0ES01LDU,1,227},	//( - , DU) ОРР не в исходном состоянии
	{&B3IS21LDU,1,228},	//( - K13VDSR, DU) Приход на НУ ИС2
	{&B2IS21LDU,1,229},	//( - K12VDSR, DU) Приход на НУ РБ2-СС
	{&B1IS21LDU,1,230},	//( - K09VDSR, DU) Приход на НУ ББ2
	{&A3IS21LDU,1,231},	//( - K13VDSR, DU) Приход на НУ ИС1
	{&A2IS21LDU,1,232},	//( - K12VDSR, DU) Приход на НУ РБ1-СС
	{&A1IS21LDU,1,233},	//( - K09VDSR, DU) Приход на НУ ББ1
	{&R4AB15LDU,1,234},	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
	{&R4AB14LDU,1,235},	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
	{&R4AB13LDU,1,236},	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
	{&B4IS11LDU,1,237},	//( - K31VDSR, DU) Приход на ВУ НИ2
	{&A4IS11LDU,1,238},	//( - K14VDSR, DU) Приход на ВУ НИ1
	{&R4AB12LDU,1,239},	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
	{&R4AB11LDU,1,240},	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
	{&R4AB10LDU,1,241},	//( - , DU) Блокировка тележки - не открыта биологическая защита
	{&R4AB09LDU,1,242},	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
	{&R4AB08LDU,1,243},	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
	{&R4AB07LDU,1,244},	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
	{&R4AB06LDU,1,245},	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
	{&R4AB05LDU,1,246},	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
	{&R4AB04LDU,1,247},	//( - , DU) Блокировка движения тележки - Превышение времени движения
	{&R2IS21LDU,1,248},	//( - K30VDSR, DU) Приход на НУ МДЗ2
	{&R1IS21LDU,1,249},	//( - K28VDSR, DU) Приход на НУ МДЗ1
	{&B6AB01LDU,1,250},	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
	{&B6AB02LDU,1,251},	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
	{&A6AB04LDU,1,252},	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
	{&B6AB04LDU,1,253},	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
	{&R4AB01LDU,1,254},	//( - , DU) Блокировка движения тележки - АНИ не установлен
	{&R8IS11LDU,1,255},	//( - K14VDSR, DU) Аварийный НИ установлен
	{&R4AB02LDU,1,256},	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
	{&R4IS21LDU,1,257},	//( - K07VDSR, DU) Приход на НУ1 тележки
	{&R4IS22LDU,1,258},	//( - K08VDSR, DU) Приход на НУ2 тележки
	{&R4IS12LDU,1,259},	//( - K06VDSR, DU) Приход на ВУ2 тележки
	{&R4VS22LDU,1,260},	//( - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
	{&R4VS12LDU,1,261},	//( - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
	{&R4AZ03LDU,1,262},	//( - , DU) Несанкционированное перемещение тележки
	{&R4AB03LDU,1,263},	//( - , DU) Блокировка движения тележки - Самоход любого механизма
	{&B1AZ03LDU,1,264},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
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
	{&A3AB18LDU,1,292},	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
	{&A3AB17LDU,1,293},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
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
	{&B1AB07LDU,1,307},	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
	{&B1AB08LDU,1,308},	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
	{&B1AB05LDU,1,309},	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
	{&B1AB06LDU,1,310},	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
	{&B1AB09LDU,1,311},	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
	{&B1AB10LDU,1,312},	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
	{&B1AB11LDU,1,313},	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
	{&B1AB12LDU,1,314},	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&B1AB13LDU,1,315},	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
	{&B1AB14LDU,1,316},	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
	{&B1AB16LDU,1,317},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
	{&B1AB17LDU,1,318},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
	{&B1AB18LDU,1,319},	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
	{&A3VS12LDU,1,320},	//( - , DU) Движение ИС1 в сторону ВУ
	{&A3AB04LDU,1,321},	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
	{&A3AB02LDU,1,322},	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
	{&A2AB13LDU,1,323},	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
	{&A2AB12LDU,1,324},	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&A2AB11LDU,1,325},	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
	{&A2AB10LDU,1,326},	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
	{&A2AB09LDU,1,327},	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
	{&A2AB06LDU,1,328},	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
	{&A2AB05LDU,1,329},	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
	{&A2AB08LDU,1,330},	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
	{&A2AB07LDU,1,331},	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
	{&A2AZ03LDU,1,332},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
	{&A2VS21LDU,1,333},	//( - , DU) Движение РБ1 в сторону НУ
	{&A2AB01LDU,1,334},	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
	{&A2AB02LDU,1,335},	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
	{&A2AB04LDU,1,336},	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
	{&A2VS11LDU,1,337},	//( - , DU) Движение РБ1 в сторону ВУ
	{&A8AB07LDU,1,338},	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
	{&A8AB05LDU,1,339},	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
	{&A8VS22LDU,1,340},	//( - , DU) Движение ДС2 в сторону НУ
	{&A8AZ03LDU,1,341},	//( - , DU) Несанкционированное перемещение ДС2
	{&B8IS22LDU,1,342},	//( - K22VDSR, DU) Приход на НУ2 АЗ2
	{&A8IS12LDU,1,343},	//( - K30VDSR, DU) Приход на механический ВУ ДС2
	{&A8AB04LDU,1,344},	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
	{&A8IS22LDU,1,345},	//( - K31VDSR, DU) Приход на механический НУ ДС2
	{&A8AB08LDU,1,346},	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
	{&A8AB09LDU,1,347},	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
	{&A8AB10LDU,1,348},	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
	{&A8AB11LDU,1,349},	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
	{&A8AB12LDU,1,350},	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
	{&A8AB13LDU,1,351},	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
	{&A8AB14LDU,1,352},	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
	{&A8AB02LDU,1,353},	//( - , DU) Блокировка движения ДС2- АНИ не установлен
	{&A8AB01LDU,1,354},	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
	{&R2VS22LDU,1,355},	//( - K09VDSR, DU) Движение МДЗ2 в сторону НУ
	{&R1VS22LDU,1,356},	//( - K06VDSR, DU) Движение МДЗ1 в сторону НУ
	{&R1IS11LDU,1,357},	//( - K27VDSR, DU) Приход на ВУ МДЗ1
	{&R2AB04LDU,1,358},	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
	{&R1AB04LDU,1,359},	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
	{&R2AB02LDU,1,360},	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
	{&R2AB01LDU,1,361},	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
	{&R2AZ03LDU,1,362},	//( - , DU) Несанкционированное перемещение МДЗ2
	{&R1AB02LDU,1,363},	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
	{&R1AB01LDU,1,364},	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
	{&R1AZ03LDU,1,365},	//( - , DU) Несанкционированное перемещение МДЗ1
	{&B2AB17LDU,1,366},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
	{&B2AB16LDU,1,367},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
	{&B2AB14LDU,1,368},	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
	{&B2AB13LDU,1,369},	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
	{&B2AB12LDU,1,370},	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{&A2AB14LDU,1,371},	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
	{&A2AB16LDU,1,372},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
	{&A2AB17LDU,1,373},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
	{&B2AB04LDU,1,374},	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
	{&B2AB02LDU,1,375},	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
	{&B2AB01LDU,1,376},	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
	{&B2AZ03LDU,1,377},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
	{&B2AB07LDU,1,378},	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
	{&B2AB08LDU,1,379},	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
	{&B2AB05LDU,1,380},	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
	{&B2AB06LDU,1,381},	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
	{&B2AB09LDU,1,382},	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
	{&B2AB10LDU,1,383},	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
	{&B2AB11LDU,1,384},	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DU[]={  // 
	{&R0VX08IDU,3,0},	//( - , DU) Индикация Режим
	{&B2VS01IDU,3,1},	//( - , DU) Готовность к управлению РБ2
	{&R0VL01RDU,8,2},	//( - , DU) Индикация Время задержки
	{&R0VL11IDU,3,4},	//( - , DU) До импульса секунд
	{&R0VL01IDU,3,5},	//( - , DU) До импульса минут
	{&B3CV02RDU,8,6},	//( - , DU) Заданная скорость перемещения ИС2
	{&B3CV01RDU,8,8},	//( - , DU) Измеренная скорость перемещения ИС2
	{&R1VS01IDU,3,10},	//( - , DU) Готовность к управлению МДЗ1
	{&R2VS01IDU,3,11},	//( - , DU) Готовность к управлению МДЗ2
	{&R4VS01IDU,3,12},	//( - , DU) Готовность к управлению тележкой реактора
	{&A6VS01IDU,3,13},	//( - , DU) Готовность к управлению БЗ1
	{&B5VS01IDU,3,14},	//( - , DU) Готовность к управлению НЛ2
	{&A5VS01IDU,3,15},	//( - , DU) Готовность к управлению НЛ1
	{&B4VS01IDU,3,16},	//( - , DU) Готовность к управлению НИ2
	{&A4VS01IDU,3,17},	//( - , DU) Готовность к управлению НИ1
	{&A2VS01IDU,3,18},	//( - , DU) Готовность к управлению РБ1
	{&R0VL06RDU,8,19},	//( - , DU) Индикация (Время задержки от ВУ РБ)
	{&R0VL02RDU,8,21},	//( - , DU) Индикация (Время задержки ИНИ)
	{&R0VL04RDU,8,23},	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
	{&R0VL03RDU,8,25},	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
	{&R0VL05RDU,8,27},	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
	{&R0VL21IDU,3,29},	//( - , DU) Декатрон
	{&R0VS21IDU,3,30},	//( - , DU) Индикация ВИД ПРОВЕРКИ
	{&A1VS01IDU,3,31},	//( - , DU) Готовность к управлению ББ1
	{&B1VS01IDU,3,32},	//( - , DU) Готовность к управлению ББ2
	{&A3VS01IDU,3,33},	//( - , DU) Готовность к управлению ИС1
	{&B3VS01IDU,3,34},	//( - , DU) Готовность к управлению ИС2
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
	{&B6VS01IDU,3,58},	//( - , DU) Готовность к управлению БЗ2
	{&B8VS01IDU,3,59},	//( - , DU) Готовность к управлению АЗ2
	{&A8VS01IDU,3,60},	//( - , DU) Готовность к управлению ДС2
	{&R0CN95LDU,3,61},	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
	{&R0CN94LDU,8,62},	//( - , DU) Скорость изменения мощности
	{&R0CN93LDU,8,64},	//( - , DU) время работы на мощности более 100Вт, сек
	{&R0VN12RDU,8,66},	//( - , DU) Заданная мощность РУ
	{&R0VN11RDU,8,68},	//( - , DU) Текущая мощность РУ
	{&R0CN92LDU,8,70},	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
	{&A3MC03RDU,8,72},	//( - , DU) Координата положения ИМ 0-й реактивности
	{&R0CN91LDU,8,74},	//( - , DU) Рассчётная реактивность от регулятора
	{&A3MC01RDU,8,76},	//( - , DU) Заданная координата положения ИС от регулятора мм
	{&A3MC02RDU,8,78},	//( - , DU) Температурная корректировка координаты ИМ
	{&A8CV01RDU,8,80},	//( - , DU) Измеренная скорость перемещения ДС2
	{&B8CV01RDU,8,82},	//( - , DU) Измеренная скорость перемещения АЗ2
	{&B1CV02RDU,8,84},	//( - , DU) Заданная скорость перемещения ББ2
	{&B1CV01RDU,8,86},	//( - , DU) Измеренная скорость перемещения ББ2
	{&A1CV02RDU,8,88},	//( - , DU) Заданная скорость перемещения ББ1
	{&A1CV01RDU,8,90},	//( - , DU) Измеренная скорость перемещения ББ1
	{&A3CV02RDU,8,92},	//( - , DU) Заданная скорость перемещения ИС1
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
	{&B4VP82LDU,1,0},	//( - , SDu) Давление ПОДЪЁМ НИ2 в норме
	{&A4VP82LDU,1,1},	//( - , SDu) Давление ПОДЪЁМ НИ1 в норме
	{&B2VP82LDU,1,2},	//( - , SDu) Давление ПОДЪЁМ РБ2 в норме
	{&R6IS68LZZ,1,3},	//( - K19DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№7) ССДИ-2
	{&R6IS67LZZ,1,4},	//( - K18DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{&R6IS66LZZ,1,5},	//( - K17DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{&R6IS65LDU,1,6},	//( - , SDu) Исправность ВИП ССДИ-35 2канал
	{&R6IS64LDU,1,7},	//( - , SDu) Исправность ВИП ССДИ-35 1канал
	{&R6IS63LDU,1,8},	//( - , SDu) Исправность ВИП ССДИ-39 2канал
	{&R6IS62LDU,1,9},	//( - , SDu) Исправность ВИП ССДИ-39 1канал
	{&B3VP81LDU,1,10},	//( - , SDu) Давление СПУСК ИС2 в норме
	{&A3VP81LDU,1,11},	//( - , SDu) Давление СПУСК ИС1 в норме
	{&A2VP82LDU,1,12},	//( - , SDu) Давление ПОДЪЁМ РБ1 в норме
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MDuS[]={  // 
	{&B1IC01UDU,5,0},	//( - , SDu) Координата штока ББ2
	{&A1IC01UDU,5,2},	//( - , SDu) Координата штока ББ1
	{&B2IC01UDU,5,4},	//( - , SDu) Координата штока РБ2
	{&B8IC01UDU,5,6},	//( - , SDu) Координата АЗ2
	{&A8IC01UDU,5,8},	//( - , SDu) Координата ДС2
	{&B3IC01UDU,5,10},	//( - , SDu) Координата штока ИС2
	{&A3IC01UDU,5,12},	//( - , SDu) Координата штока ИС1
	{&A2IC01UDU,5,14},	//( - , SDu) Координата штока РБ1
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
	{1,5005,&coil_MDuS[0],&di_MDuS[0],&ir_MDuS[0],&hr_MDuS[0],NULL,MDuS_ip1,MDuS_ip2,100},	 //Мастер ДУ в SCM
	{0,5006,&coil_DiagnDU[0],&di_DiagnDU[0],&ir_DiagnDU[0],&hr_DiagnDU[0],NULL,NULL,NULL,0},	 //Диагностика корзины DU

	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3202[66];	//VDS32-02
static vds32r_inipar ini_VDS3202={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3202={0,0,&ini_VDS3202,buf_VDS3202,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3202[]={
	{&B3IS33LDU,1,2},
	{&R1IS11LDU,1,52},
	{&A1VN71LZ1,1,40},
	{&R2IS11LDU,1,56},
	{&R0VZ71LZ1,1,42},
	{&B3IS31LDU,1,8},
	{&A3VZ15LZ1,1,36},
	{&A3VZ13LZ1,1,34},
	{&B3IS35LDU,1,0},
	{&B4IS10LDU,1,6},
	{&B2IS33LDU,1,4},
	{&R0AD14LZ1,1,38},
	{&B4IS11LDU,1,60},
	{&B2IS12LDU,1,18},
	{&B1IS12LDU,1,12},
	{&B3IS21LDU,1,24},
	{&R1IS21LDU,1,54},
	{&R2IS21LDU,1,58},
	{&B2IS21LDU,1,22},
	{&B4IS21LDU,1,62},
	{&B9IS21LDU,1,50},
	{&B9IS11LDU,1,48},
	{&B1IS21LDU,1,16},
	{&R0DE02LDU,3,64},
	{&A9IS21LDU,1,46},
	{&B1IS11LDU,1,14},
	{&B7AS31LDU,1,10},
	{&A9IS11LDU,1,44},
	{&R8IS11LDU,1,26},
	{&B2IS11LDU,1,20},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3203[66];	//VDS32-03
static vds32r_inipar ini_VDS3203={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3203={0,0,&ini_VDS3203,buf_VDS3203,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3203[]={
	{&A4IS10LDU,1,6},
	{&R0IS01LDU,1,56},
	{&R0IS02LDU,1,58},
	{&A1VN71LZ2,1,40},
	{&A4IS11LDU,1,26},
	{&R0AD14LZ2,1,38},
	{&A3VZ13LZ2,1,34},
	{&A3VZ15LZ2,1,36},
	{&A2IS11LDU,1,20},
	{&A7AS31LDU,1,10},
	{&A1IS21LDU,1,16},
	{&A3IS21LDU,1,24},
	{&A2IS21LDU,1,22},
	{&R0DE03LDU,3,64},
	{&A4IS21LDU,1,28},
	{&R0VZ71LZ2,1,42},
	{&A1IS12LDU,1,12},
	{&A2IS12LDU,1,18},
	{&A1IS11LDU,1,14},
	{&A2IS33LDU,1,4},
	{&A3IS31LDU,1,8},
	{&A3IS33LDU,1,2},
	{&A3IS35LDU,1,0},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3204[66];	//VDS32-04
static vds32r_inipar ini_VDS3204={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3204={0,0,&ini_VDS3204,buf_VDS3204,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3204[]={
	{&R5IS21LDU,1,50},
	{&B8IS21LDU,1,38},
	{&B8IS12LDU,1,40},
	{&R3IS11LDU,1,32},
	{&R3IS21LDU,1,34},
	{&R0DE04LDU,3,64},
	{&B8IS11LDU,1,36},
	{&A8IS12LDU,1,58},
	{&A8IS22LDU,1,60},
	{&R4IS11LDU,1,8},
	{&B6IS21LDU,1,26},
	{&A3IS11LDU,1,0},
	{&B8IS22LDU,1,42},
	{&B3IS11LDU,1,4},
	{&A3IS22LDU,1,2},
	{&B3IS22LDU,1,6},
	{&R4IS12LDU,1,10},
	{&R4IS22LDU,1,14},
	{&R4IS21LDU,1,12},
	{&B5IS21LDU,1,30},
	{&B5IS11LDU,1,28},
	{&A5IS21LDU,1,22},
	{&A5IS11LDU,1,20},
	{&R5IS11LDU,1,48},
	{&B6IS11LDU,1,24},
	{&A6IS21LDU,1,18},
	{&A6IS11LDU,1,16},
	{&R6IS21LDU,1,56},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3205[66];	//VDS32-05
static vds32r_inipar ini_VDS3205={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3205={0,0,&ini_VDS3205,buf_VDS3205,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3205[]={
	{&A3IE01LDU,1,18},
	{&A2IE01LDU,1,10},
	{&B1IE04LDU,1,30},
	{&A1IE02LDU,1,0},
	{&A3IE02LDU,1,16},
	{&A2IE02LDU,1,8},
	{&B1IE01LDU,1,26},
	{&B2IE01LDU,1,34},
	{&B3IE01LDU,1,42},
	{&B1IE02LDU,1,24},
	{&B3IE02LDU,1,40},
	{&B3IE04LDU,1,46},
	{&B3IE03LDU,1,44},
	{&B2IE03LDU,1,36},
	{&R6IS51LDU,1,56},
	{&R6IS52LDU,1,58},
	{&B2IE04LDU,1,38},
	{&R6IS31LDU,1,48},
	{&B2IE02LDU,1,32},
	{&R6IS41LDU,1,52},
	{&R6IS42LDU,1,54},
	{&R6IS32LDU,1,50},
	{&A1IE03LDU,1,4},
	{&A1IE04LDU,1,6},
	{&A2IE03LDU,1,12},
	{&A2IE04LDU,1,14},
	{&R0DE05LDU,3,64},
	{&A1IE01LDU,1,2},
	{&B1IE03LDU,1,28},
	{&A3IE03LDU,1,20},
	{&A3IE04LDU,1,22},
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
	{&B2AD21LDU,1,16},
	{&B2AD02LDU,1,20},
	{&B2AD03LDU,1,22},
	{&B2AD04LDU,1,24},
	{&A2AD05LDU,1,12},
	{&B2AD05LDU,1,26},
	{&A2AD04LDU,1,10},
	{&B2AD01LDU,1,18},
	{&A2AD03LDU,1,8},
	{&A2AD02LDU,1,6},
	{&R0DE07LDU,3,38},
	{&A2AD21LDU,1,2},
	{&A2AD11LDU,1,0},
	{&B2AD11LDU,1,14},
	{&A2AD01LDU,1,4},
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
	{&B1AD01LDU,1,18},
	{&B1AD11LDU,1,14},
	{&B1AD21LDU,1,16},
	{&A1AD02LDU,1,6},
	{&B1AD02LDU,1,20},
	{&A1AD01LDU,1,4},
	{&B1AD03LDU,1,22},
	{&B1AD04LDU,1,24},
	{&A1AD05LDU,1,12},
	{&A1AD04LDU,1,10},
	{&B1AD05LDU,1,26},
	{&A1AD03LDU,1,8},
	{&A1AD11LDU,1,0},
	{&A1AD21LDU,1,2},
	{&R0DE08LDU,3,38},
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
	{&A6AD10LDU,1,16},
	{&A6AD20LDU,1,18},
	{&B6AD10LDU,1,20},
	{&B6AD20LDU,1,22},
	{&B8AD20LDU,1,30},
	{&B8AD10LDU,1,28},
	{&B3AD33LDU,1,2},
	{&B2AD33LDU,1,4},
	{&B7AP31LDU,1,10},
	{&B3AD34LDU,1,0},
	{&B3AD31LDU,1,8},
	{&A8AD20LDU,1,14},
	{&A8AD10LDU,1,12},
	{&R4AD20LDU,1,26},
	{&B4AD10LDU,1,6},
	{&R0DE09LDU,3,38},
	{&R4AD10LDU,1,24},
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
	{&A5AD10LDU,1,20},
	{&A3AD33LDU,1,2},
	{&A5AD20LDU,1,22},
	{&A3AD34LDU,1,0},
	{&A3AD31LDU,1,8},
	{&A2AD33LDU,1,4},
	{&A7AP31LDU,1,10},
	{&R1AD20LDU,1,14},
	{&R1AD10LDU,1,12},
	{&B5AD20LDU,1,26},
	{&B5AD10LDU,1,24},
	{&A4AD10LDU,1,6},
	{&R2AD20LDU,1,18},
	{&R2AD10LDU,1,16},
	{&R0DE0ALDU,3,38},
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
	{&R0DE0BLDU,3,38},
	{&B3AD01LDU,1,18},
	{&B3AD03LDU,1,22},
	{&B3AD02LDU,1,20},
	{&B3AD05LDU,1,26},
	{&B3AD04LDU,1,24},
	{&A9AD10LDU,1,28},
	{&B9AD10LDU,1,30},
	{&B3AD21LDU,1,16},
	{&B3AD11LDU,1,14},
	{&A3AD01LDU,1,4},
	{&A3AD05LDU,1,12},
	{&A3AD04LDU,1,10},
	{&A3AD11LDU,1,0},
	{&A3AD03LDU,1,8},
	{&A3AD02LDU,1,6},
	{&A3AD21LDU,1,2},
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
	{&B3IP02IDU,3,3},
	{&R0DE0CLDU,3,26},
	{&A3IP02IDU,3,0},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3213[66];	//VDS32-13
static vds32r_inipar ini_VDS3213={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3213={0,0,&ini_VDS3213,buf_VDS3213,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3213[]={
	{&A5VS12LDU,1,20},
	{&A5VS22LDU,1,22},
	{&R0IE02LDU,1,44},
	{&R0IE01LDU,1,46},
	{&A6IE01LDU,1,36},
	{&B6IE01LDU,1,42},
	{&A8IE01LDU,1,6},
	{&B5IE01LDU,1,30},
	{&A6VS22LDU,1,34},
	{&A6VS12LDU,1,32},
	{&B6VS22LDU,1,40},
	{&B6VS12LDU,1,38},
	{&B5VS22LDU,1,28},
	{&B5VS12LDU,1,26},
	{&R4VS22LDU,1,4},
	{&R4VS12LDU,1,2},
	{&R1VS12LDU,1,8},
	{&R2VS12LDU,1,14},
	{&R2VS22LDU,1,16},
	{&R1VS22LDU,1,10},
	{&A5IE02LDU,1,24},
	{&R1IE01LDU,1,12},
	{&R2IE01LDU,1,18},
	{&R6IS61LDU,1,0},
	{&R0DE0DLDU,3,64},
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
	{&A2AD31LDU,1,6},
	{&B2AD31LDU,1,14},
	{&B1AD32LDU,1,8},
	{&A1AD32LDU,1,0},
	{&A1AD31LDU,1,2},
	{&B2AD32LDU,1,12},
	{&B1AD31LDU,1,10},
	{&R8AD21LDU,1,22},
	{&R0AD04LZ2,1,28},
	{&R0AD05LZ1,1,20},
	{&R0AD05LZ2,1,30},
	{&A2AD32LDU,1,4},
	{&R0AD04LZ1,1,18},
	{&R0AD03LZ2,1,26},
	{&R0AD03LZ1,1,16},
	{&R0AD16LDU,1,24},
	{&R0DE0FLDU,3,38},
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
	{&R0DE37LDU,1,12},
	{&R0DE36LDU,1,10},
	{&R0DE35LDU,1,8},
	{&R0DE34LDU,1,6},
	{&R0DE33LDU,1,4},
	{&R0DE38LDU,1,14},
	{&R0DE39LDU,1,16},
	{&R0DEB3LDU,1,22},
	{&R0DEB2LDU,1,20},
	{&R0DEB1LDU,1,18},
	{&R0DEB4LDU,1,24},
	{&R0DE32LDU,1,2},
	{&R0DE31LDU,1,0},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0xc2,0x02,15,66,def_buf_VDS3202,&table_VDS3202}, //VDS32-02
	{0xc2,0x03,15,66,def_buf_VDS3203,&table_VDS3203}, //VDS32-03
	{0xc2,0x04,15,66,def_buf_VDS3204,&table_VDS3204}, //VDS32-04
	{0xc2,0x05,15,66,def_buf_VDS3205,&table_VDS3205}, //VDS32-05
	{0x96,0x07,20,40,def_buf_FDS1607,&table_FDS1607}, //FDS16-07
	{0x96,0x08,20,40,def_buf_FDS1608,&table_FDS1608}, //FDS16-08
	{0x96,0x09,20,40,def_buf_FDS1609,&table_FDS1609}, //FDS16-09
	{0x96,0x0a,20,40,def_buf_FDS1610,&table_FDS1610}, //FDS16-10
	{0x96,0x0b,20,40,def_buf_FDS1611,&table_FDS1611}, //FDS16-11
	{0xc6,0x0c,7,30,def_buf_VAS8412,&table_VAS8412}, //VAS84-12
	{0xc2,0x0d,15,66,def_buf_VDS3213,&table_VDS3213}, //VDS32-13
	{0x96,0x0f,20,40,def_buf_FDS1615,&table_FDS1615}, //FDS16-15
	{0xcc,0x20,4,26,def_buf_SBKFP,&table_SBKFP}, //SBKFP
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
	setAsFloat(737,0.0000976563);
	setAsInt(738,1024200);
	setAsInt(739,-200);
	setAsInt(740,-200);
	setAsInt(741,1024200);
	setAsFloat(742,0.0000976563);
	setAsInt(743,-200);
	setAsInt(744,1689599);
	setAsFloat(745,0.00009765625);
	setAsInt(746,-200);
	setAsFloat(747,0.0009765625);
	setAsInt(748,1536200);
	setAsFloat(749,100);
	setAsFloat(750,200);
	setAsFloat(751,300);
	setAsFloat(752,400);
	setAsFloat(753,600);
	setAsFloat(754,500);
	setAsFloat(755,750);
	setAsFloat(756,2.5);
	setAsFloat(757,0);
	setAsFloat(758,0.46);
	setAsFloat(759,0.49);
	setAsFloat(760,0.52);
	setAsFloat(761,0.53);
	setAsFloat(762,0.67);
	setAsFloat(763,0.56);
	setAsFloat(764,4);
	setAsFloat(765,4);
	setAsFloat(766,10.91);
	setAsFloat(767,3);
	setAsShort(768,4);
	setAsFloat(769,0.15);
	setAsFloat(770,0.15);
	setAsFloat(771,0.4);
	setAsFloat(772,0.4);
	setAsFloat(773,0.03);
	setAsFloat(774,0.04);
	setAsFloat(775,3);
	setAsFloat(776,0.3);
	setAsFloat(777,0.3);
	setAsFloat(778,0.07);
	setAsFloat(779,0.04);
	setAsFloat(780,3);
	setAsFloat(781,0.55);
	setAsFloat(782,0.64);
	setAsFloat(783,0.180);
	setAsFloat(784,0.025);
	setAsFloat(785,0.1);
	setAsFloat(786,2);
	setAsFloat(787,0.3);
	setAsFloat(788,3);
	setAsFloat(789,1.50);
	setAsFloat(790,0.04);
	setAsFloat(791,0.05);
	setAsFloat(792,3);
	setAsFloat(793,1.50);
	setAsFloat(794,3);
	setAsFloat(795,1.50);
	setAsFloat(796,2);
	setAsFloat(797,0.004);
	setAsFloat(798,0.006);
	setAsFloat(799,0.006);
	setAsFloat(800,1.0);
	setAsFloat(801,0.01);
	setAsFloat(802,1);
	setAsFloat(803,0.008);
	setAsFloat(804,0.01);
	setAsFloat(805,1);
	setAsFloat(806,0.4);
	setAsFloat(807,120);
	setAsFloat(808,0.6);
	setAsFloat(809,1);
	setAsFloat(810,2);
	setAsFloat(811,1.50);
	setAsFloat(812,2.0);
	setAsFloat(813,1);
	setAsFloat(814,15);
	setAsFloat(815,0.50);
	setAsFloat(816,360);
	setAsFloat(817,1);
	setAsFloat(818,2);
	setAsFloat(819,1.0);
	setAsFloat(820,6.0);
	setAsFloat(821,0.50);
	setAsFloat(822,1.0);
	setAsFloat(823,16.0);
	setAsFloat(824,3.0);
	setAsFloat(825,1.0);
	setAsFloat(826,60.0);
	setAsFloat(827,0.50);
	setAsFloat(828,1.0);
	setAsFloat(829,20.0);
	setAsFloat(830,0.50);
	setAsFloat(831,2.0);
	setAsFloat(832,2.0);
	setAsFloat(833,1.5);
	setAsFloat(834,0.06);
	setAsFloat(835,0.01);
	setAsFloat(836,0.045);
	setAsFloat(837,0.040);
	setAsFloat(838,0.007);
	setAsFloat(839,0.014);
	setAsFloat(840,2000.0);
	setAsFloat(841,1500.0);
	setAsFloat(842,1000.0);
	setAsFloat(843,800.0);
	setAsFloat(844,500.0);
	setAsFloat(845,200.0);
	setAsFloat(846,100.0);
	setAsFloat(847,0.001);
	setAsFloat(848,100);
	setAsFloat(849,100);
	setAsFloat(850,110.0);
	setAsFloat(851,20);
	setAsFloat(852,30.0);
	setAsFloat(853,100.0);
	setAsFloat(854,1.50);
	setAsFloat(855,170);
	setAsFloat(856,170);
	setAsFloat(857,10);
	setAsShort(858,1);
	setAsShort(859,4);
	setAsShort(860,1);
	setAsShort(861,4);
	setAsShort(862,4);
	setAsShort(863,4);
	setAsShort(864,4);
	setAsBool(865,0);
	setAsFloat(866,159.99);
	setAsFloat(867,0.002375);
	setAsFloat(868,0.000877);
	setAsFloat(869,0.001675);
	setAsFloat(870,2.5);
	setAsFloat(871,30);
	setAsFloat(872,30);
	setAsFloat(873,0.05);
	setAsFloat(874,0.05);
	setAsFloat(875,160.0);
	setAsFloat(876,-170.11);
	setAsFloat(877,76.25088);
	setAsFloat(878,0.271145);
	setAsFloat(879,24.93556615);
	setAsFloat(880,0.1268);
	setAsFloat(881,0.1567);
	setAsFloat(882,0.1858);
	setAsFloat(883,0.2066);
	setAsFloat(884,0.2646);
	setAsFloat(885,0.2995);
	setAsFloat(886,0.721275);
	setAsFloat(887,0.700575);
	setAsFloat(888,0.6681);
	setAsFloat(889,0.61515);
	setAsFloat(890,0.3885);
	setAsFloat(891,0.23325);
	setAsFloat(892,3600.0);
	setAsFloat(893,0.935);
	setAsFloat(894,0.1);
	setAsFloat(895,0.006792308);
	setAsFloat(896,0.000418877);
	setAsFloat(897,0.0015);
	setAsFloat(898,0.30);
}
uspaint8 InternalBuf[8511];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssint iRM_8_ = {8,0}; /* N-число входов */ 
sslong dRM_16777215_ = {16777215,0}; /*  */ 
sschar bRM_1_ = {1,0}; /* FileN - номер файла ЭСППЗУ */ 
ssint iRM_0_ = {0,0}; /* FileOffs - смещение в файле ЭСППЗУ */ 
ssint iRM_4_ = {4,0}; /* p */ 
ssfloat fRM_0_0 = {0.0,0}; /* Стартовая координата ИС по умолчанию */ 
ssfloat fRM_1500_0 = {1500.0,0}; /* Стартовая координата АЗ2/ДС2 по умолчанию */ 
ssfloat fRM_100_ = {100,0}; /* Стартовая координата ББ по умолчанию */ 
ssint iRM_2_ = {2,0}; /* p */ 
ssint iRM_1_ = {1,0}; /* p */ 
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
ssint iRM_9_ = {9,0}; /* p */ 
ssint iRM_16_ = {16,0}; /* n - N-размерность массива x */ 
ssfloat fRM_0_ = {0,0}; /* x - массив входных параметров */ 
ssint iRM_3276_ = {3276,0}; /* a */ 
ssint iRM_16383_ = {16383,0}; /* b */ 
sschar bRM_2_ = {2,0}; /* type - тип проверки 1-ини,2-ву ис,3-2ур,4-нуп ис,5-ву рб, 6-конец */ 
sschar bRM_3_ = {3,0}; /* type - тип проверки 1-ини,2-ву ис,3-2ур,4-нуп ис,5-ву рб, 6-конец */ 
sschar bRM_4_ = {4,0}; /* type - тип проверки 1-ини,2-ву ис,3-2ур,4-нуп ис,5-ву рб, 6-конец */ 
sschar bRM_5_ = {5,0}; /* type - тип проверки 1-ини,2-ву ис,3-2ур,4-нуп ис,5-ву рб, 6-конец */ 
sschar bRM_6_ = {6,0}; /* type - тип проверки 1-ини,2-ву ис,3-2ур,4-нуп ис,5-ву рб, 6-конец */ 
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
ssfloat fRM_100_0 = {100.0,0}; /* x1 - первый входной параметр */ 
ssfloat fRM_160_0001 = {160.0001,0}; /* X2 */ 
ssfloat fRM_160_00001 = {160.00001,0}; /* X2 */ 
ssfloat fRM_389_99 = {389.99,0}; /* X1 */ 
ssfloat fRM_1500_0001 = {1500.0001,0}; /* X2 */ 
ssint iRM_47_ = {47,0}; /* n - N-размерность массива входных параметров */ 
ssfloat fRM_3_ = {3,0}; /* tz - время задержки сек */ 
ssfloat fRM_55_0 = {55.0,0}; /* X1 */ 
ssfloat fRM_1_0 = {1.0,0}; /* tz - ширина импульса, sek */ 

uspaint8 SpaEEPROMBuf[791];

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
ssbool var133;
ssbool var134;
ssint var135;
ssbool var136;
ssbool var137;
ssint var138;
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
ssbool var175;
ssbool var176;
ssbool var177;
ssbool var178;
ssbool var179;
ssbool var180;
ssbool var181;
ssbool var182;
ssfloat var183;
ssbool var184;
ssbool var185;
ssbool var186;
ssbool var187;
ssbool var188;
ssbool var189;
ssbool var190;
ssbool var191;
ssbool var192;
ssfloat var193;
ssfloat var194;
ssbool var195;
ssbool var196;
ssbool var197;
ssfloat var198;
ssfloat var199;
ssbool var200;
ssbool var201;
ssfloat var202;
ssbool var203;
ssbool var204;
ssbool var205;
ssbool var206;
ssbool var207;
ssbool var208;
ssbool var209;
ssbool var210;
ssfloat var211;
ssfloat var212;
ssfloat var213;
ssfloat var214;
ssbool var215;
ssfloat var216;
ssfloat var217;
ssint var218;
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
ssfloat var309;
ssbool var310;
ssbool var311;
ssbool var312;
ssfloat var313;
ssbool var314;
ssbool var315;
ssbool var316;
ssfloat var317;
ssbool var318;
ssbool var319;
ssbool var320;
ssfloat var321;
ssbool var322;
ssbool var323;
ssbool var324;
ssfloat var325;
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
ssfloat var422;
ssfloat var423;
ssbool var424;
ssfloat var425;
ssfloat var426;
ssbool var427;
ssfloat var428;
ssfloat var429;
ssbool var430;
ssfloat var431;
ssfloat var432;
ssbool var433;
ssbool var434;
ssfloat var435;
ssfloat var436;
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
sslong var566;
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
ssfloat var977;
ssbool var978;
ssfloat var979;
ssbool var980;
ssfloat var981;
ssbool var982;
ssbool var983;
ssbool var984;
ssbool var985;
ssfloat var986;
ssfloat var987;
ssfloat var988;
ssfloat var989;
ssfloat var990;
ssfloat var991;
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
ssint var1047;
ssint var1048;
ssbool var1049;
ssbool var1050;
ssbool var1051;
ssbool var1052;
ssbool var1053;
ssbool var1054;
sslong var1055;
ssbool var1056;
ssbool var1057;
ssbool var1058;
ssint var1059;
ssbool var1060;
ssbool var1061;
ssbool var1062;
ssbool var1063;
ssbool var1064;
ssbool var1065;
ssbool var1066;
ssbool var1067;
ssbool var1068;
ssint var1069;
ssint var1070;
ssbool var1071;
ssbool var1072;
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
sslong var1110;
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
ssfloat var1129;
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
ssbool var1141;
ssbool var1142;
ssbool var1143;
ssbool var1144;
ssbool var1145;
ssbool var1146;
ssbool var1147;
ssbool var1148;
ssint var1149;
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
ssfloat var1174;
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
sslong var1270;
ssbool var1271;
ssint var1272;
ssint var1273;
ssbool var1274;
ssfloat var1275;
ssfloat var1276;
ssfloat var1277;
ssbool var1278;
ssbool var1279;
ssbool var1280;
ssbool var1281;
ssbool var1282;
ssbool var1283;
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
ssint var1294;
ssbool var1295;
sschar var1296;
ssint var1297;
ssbool var1298;
ssfloat var1299;
ssbool var1300;
ssbool var1301;
ssbool var1302;
ssbool var1303;
ssbool var1304;
ssbool var1305;
ssbool var1306;
ssfloat var1307;
sschar var1308;
ssbool var1309;
ssbool var1310;
ssbool var1311;
ssbool var1312;
ssfloat var1313;
ssbool var1314;
ssbool var1315;
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
ssint var1326;
ssbool var1327;
sschar var1328;
ssint var1329;
ssbool var1330;
ssfloat var1331;
ssbool var1332;
ssbool var1333;
ssbool var1334;
ssbool var1335;
ssbool var1336;
ssbool var1337;
ssbool var1338;
ssfloat var1339;
sschar var1340;
ssbool var1341;
ssbool var1342;
ssbool var1343;
ssbool var1344;
ssfloat var1345;
ssbool var1346;
ssbool var1347;
ssbool var1348;
ssbool var1349;
ssbool var1350;
ssbool var1351;
ssbool var1352;
ssbool var1353;
ssbool var1354;
ssint var1355;
ssbool var1356;
sschar var1357;
ssint var1358;
ssbool var1359;
ssfloat var1360;
ssbool var1361;
ssbool var1362;
ssbool var1363;
ssbool var1364;
ssbool var1365;
ssbool var1366;
ssbool var1367;
ssfloat var1368;
sschar var1369;
ssbool var1370;
ssbool var1371;
ssbool var1372;
ssbool var1373;
ssfloat var1374;
ssbool var1375;
ssbool var1376;
ssbool var1377;
ssbool var1378;
ssbool var1379;
ssbool var1380;
ssbool var1381;
ssbool var1382;
ssbool var1383;
ssbool var1384;
ssbool var1385;
ssbool var1386;
ssbool var1387;
ssint var1388;
ssbool var1389;
sschar var1390;
ssint var1391;
ssbool var1392;
ssfloat var1393;
ssbool var1394;
ssbool var1395;
ssbool var1396;
ssbool var1397;
ssbool var1398;
ssbool var1399;
ssbool var1400;
ssfloat var1401;
sschar var1402;
ssbool var1403;
ssbool var1404;
ssfloat var1405;
ssbool var1406;
ssbool var1407;
ssbool var1408;
ssbool var1409;
ssbool var1410;
ssbool var1411;
ssbool var1412;
ssbool var1413;
ssbool var1414;
ssbool var1415;
ssbool var1416;
ssbool var1417;
ssint var1418;
ssbool var1419;
ssbool var1420;
ssbool var1421;
ssbool var1422;
ssbool var1423;
ssbool var1424;
ssbool var1425;
ssbool var1426;
ssint var1427;
ssbool var1428;
ssbool var1429;
ssbool var1430;
ssbool var1431;
ssbool var1432;
ssbool var1433;
ssbool var1434;
ssint var1435;
ssbool var1436;
sschar var1437;
ssint var1438;
ssbool var1439;
ssfloat var1440;
ssbool var1441;
ssbool var1442;
ssbool var1443;
ssbool var1444;
ssbool var1445;
ssbool var1446;
ssbool var1447;
ssfloat var1448;
sschar var1449;
ssbool var1450;
ssbool var1451;
ssfloat var1452;
ssbool var1453;
ssbool var1454;
ssbool var1455;
ssbool var1456;
ssbool var1457;
ssbool var1458;
ssbool var1459;
ssbool var1460;
sschar var1461;
ssbool var1462;
ssbool var1463;
ssbool var1464;
ssbool var1465;
ssbool var1466;
ssbool var1467;
ssbool var1468;
ssbool var1469;
ssbool var1470;
sschar var1471;
ssbool var1472;
ssbool var1473;
ssint var1474;
ssbool var1475;
sschar var1476;
ssbool var1477;
ssint var1478;
ssbool var1479;
ssbool var1480;
ssfloat var1481;
ssbool var1482;
ssbool var1483;
ssbool var1484;
ssbool var1485;
ssbool var1486;
ssbool var1487;
ssbool var1488;
ssfloat var1489;
sschar var1490;
ssbool var1491;
ssbool var1492;
ssbool var1493;
ssbool var1494;
ssfloat var1495;
ssbool var1496;
ssbool var1497;
ssbool var1498;
ssbool var1499;
ssbool var1500;
ssbool var1501;
ssbool var1502;
ssbool var1503;
ssbool var1504;
ssbool var1505;
ssbool var1506;
ssbool var1507;
ssfloat var1508;
ssbool var1509;
ssbool var1510;
ssbool var1511;
ssbool var1512;
ssbool var1513;
ssbool var1514;
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
ssfloat var1525;
ssbool var1526;
ssbool var1527;
ssbool var1528;
ssbool var1529;
ssbool var1530;
ssbool var1531;
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
ssint var1563;
ssbool var1564;
ssbool var1565;
ssbool var1566;
ssbool var1567;
ssbool var1568;
ssbool var1569;
ssbool var1570;
ssbool var1571;
ssint var1572;
ssbool var1573;
ssbool var1574;
ssbool var1575;
ssbool var1576;
ssbool var1577;
ssbool var1578;
ssbool var1579;
ssbool var1580;
ssint var1581;
ssbool var1582;
ssbool var1583;
ssbool var1584;
ssbool var1585;
ssbool var1586;
ssbool var1587;
ssbool var1588;
ssbool var1589;
ssint var1590;
ssbool var1591;
ssbool var1592;
ssbool var1593;
ssbool var1594;
ssbool var1595;
ssbool var1596;
ssbool var1597;
ssbool var1598;
ssint var1599;
ssbool var1600;
ssbool var1601;
ssbool var1602;
ssbool var1603;
ssbool var1604;
ssbool var1605;
ssbool var1606;
ssbool var1607;
ssint var1608;
ssbool var1609;
ssbool var1610;
ssbool var1611;
ssbool var1612;
ssbool var1613;
ssbool var1614;
ssbool var1615;
ssbool var1616;
ssint var1617;
ssbool var1618;
ssbool var1619;
ssbool var1620;
ssbool var1621;
ssbool var1622;
ssbool var1623;
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
ssfloat var1654;
ssbool var1655;
ssbool var1656;
ssbool var1657;
ssbool var1658;
ssbool var1659;
ssbool var1660;
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
ssfloat var1689;
ssfloat var1690;
ssbool var1691;
ssbool var1692;
ssbool var1693;
ssbool var1694;
ssbool var1695;
ssbool var1696;
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
ssfloat var1717;
ssbool var1718;
ssbool var1719;
ssfloat var1720;
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
ssbool var1738;
ssfloat var1739;
ssbool var1740;
ssbool var1741;
ssbool var1742;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m170_x_2[17] = {&R0IE02LDU,&R0IE01LDU,&A8IE01LDU,&B6IE01LDU,&R1IE01LDU,&R2IE01LDU,&A5IE02LDU,&B5IE01LDU,&A6IE01LDU,&R6IS62LDU,&R6IS63LDU,&R6IS64LDU,&R6IS65LDU,&R6IS61LDU,&R6IS68LZZ,&R6IS67LZZ,&R6IS66LZZ};
psbool  array_m150_x_2[6] = {&B3IE02LDU,&B1IE02LDU,&B2IE01LDU,&B1IE01LDU,&B3IE01LDU,&B2IE02LDU};
psbool  array_m131_x_2[6] = {&A1IE02LDU,&A2IE02LDU,&A1IE01LDU,&A2IE01LDU,&A3IE01LDU,&A3IE02LDU};
psbool  array_m243_x_2[6] = {&var1701,&var1693,&var1707,&B0VT71LZ1,&B0VT71LZ2,&var1652};
psbool  array_m232_x_2[6] = {&var1702,&var1695,&var1708,&A0VT71LZ1,&A0VT71LZ2,&var1652};
psbool  array_m255_x_2[6] = {&var1686,&B0VP71LZ1,&B0VP71LZ2,&var1657,&var1656,&var1655};
psbool  array_m234_x_2[6] = {&var1687,&A0VP71LZ1,&A0VP71LZ2,&var1660,&var1659,&var1658};
psbool  array_m124_x_2[8] = {&var1719,&var1741,&var1737,&var1734,&var1731,&var1728,&var1722,&var1725};
psbool  array_m2294_x_1[6] = {&var4,&var3,&R0DE36LDU,&R0DE37LDU,&R0DE38LDU,&R0DE39LDU};
psint  array_m2278_x_1[12] = {&R0DE0DLDU,&R0DE0FLDU,&R0DE02LDU,&R0DE03LDU,&R0DE04LDU,&R0DE05LDU,&R0DE07LDU,&R0DE08LDU,&R0DE09LDU,&R0DE0ALDU,&R0DE0BLDU,&R0DE0CLDU};
psbool  array_m796_x_1[6] = {&var597,&var1233,&var1209,&var1198,&var1002,&var85};
psbool  array_m1181_x_1[6] = {&var596,&var1213,&var10,&var1235,&var1002,&var105};
psbool  array_m587_x_1[6] = {&var792,&var1101,&var1520,&var1062,&var1479,&var1095};
psbool  array_m586_x_1[6] = {&var792,&var1102,&var1520,&var1062,&var1479,&var1094};
psfloat  array_m2185_a_1[6] = {&fEM_R0UN70LDU,&fEM_R0UN71LDU,&fEM_R0UN72LDU,&fEM_R0UN73LDU,&fEM_R0UN74LDU,&fEM_R0UN75LDU};
psfloat  array_m2185_b_1[6] = {&fEM_R0UN80LDU,&fEM_R0UN81LDU,&fEM_R0UN82LDU,&fEM_R0UN83LDU,&fEM_R0UN84LDU,&fEM_R0UN85LDU};
psfloat  array_m2199_x_1[4] = {&B0CT01IZ1,&A0CT01IZ1,&B0CT01IZ2,&A0CT01IZ2};
psfloat  array_m2220_x_1[2] = {&R0VN09RZ1,&R0VN09RZ2};
psbool  array_m2189_x_1[14] = {&var197,&var170,&var826,&var231,&var233,&var168,&var1642,&var1222,&var1220,&var1653,&var196,&var185,&var181,&var205};
psbool  array_m1_x_1[47] = {&var1185,&lRM_0_,&var330,&var60,&var480,&var1389,&var715,&R0MD34LP1,&var629,&R0MD34LP1,&var688,&R0MD34LP1,&var922,&R0MD34LP1,&var742,&R0MD34LP1,&var920,&var1416,&A2IS12LDU,&var387,&var1216,&var1109,&var1107,&var1020,&var835,&R0MD34LP1,&var417,&var458,&var1260,&var1570,&R0MD34LP1,&var573,&var564,&var519,&B3IS35LDU,&B3IS35LDU,&var252,&var58,&var491,&var299,&var1621,&var1579,&var1606,&var941,&var1593,&R2IS21LDU,&var171};
psfloat  array_m1447_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psbool  array_m1401_x_1[5] = {&var573,&var572,&var571,&var570,&var569};
psbool  array_m545_x_1[14] = {&var740,&var746,&var747,&var738,&var739,&var924,&var925,&var905,&var904,&var736,&var734,&var742,&var735,&var225};
psfloat  array_m82_x_1[2] = {&R0VN11RZ2,&R0VN11RZ1};
psfloat  array_m84_x_1[8] = {&fEM_R0UN01RDU,&fEM_R0UN02RDU,&fEM_R0UN03RDU,&fEM_R0UN04RDU,&fEM_R0UN05RDU,&fEM_R0UN06RDU,&fEM_R0UN07RDU,&fEM_R0UN08RDU};
psfloat  array_m1056_x_1[2] = {&R0VN11RZ2,&R0VN11RZ1};
psfloat  array_m1191_x_1[8] = {&var1481,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m801_x_1[8] = {&var1440,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m886_x_1[8] = {&var1331,&var194,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m1288_x_1[8] = {&var1299,&var193,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m487_x_1[8] = {&var1360,&var321,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m164_x_1[8] = {&var1393,&var325,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m325_Tpr_1[10] = {&fRM_6_0,&fRM_126_0,&fRM_246_0,&fRM_366_0,&fRM_486_0,&fRM_606_0,&fRM_726_0,&fRM_846_0,&fRM_966_0,&fRM_1200_0};
pschar  array_m325_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m325_rz_1[10];
psbool  array_m329_x_1[5] = {&var1050,&var1051,&var1052,&var1053,&var1054};
psbool  array_m264_x_1[7] = {&var826,&var227,&var1029,&var1026,&var233,&var231,&var229};
psfloat  array_m268_Tpr_1[10] = {&fRM_10_0,&fRM_30_0,&fRM_50_0,&fRM_70_0,&fRM_90_0,&fRM_110_0,&fRM_130_0,&fRM_150_0,&fRM_170_0,&fRM_200_0};
pschar  array_m268_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m268_rz_1[10];
psfloat  array_m1390_Tpr_1[6] = {&fRM_0_5,&fRM_3_5,&fRM_6_5,&fRM_9_5,&fRM_12_5,&fRM_15_5};
pschar  array_m1390_type_1[6] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_6_};
pschar  array_m1390_rz_1[6];
psbool  array_m284_x_1[5] = {&var1072,&var1073,&var1074,&var1075,&var1076};
psbool  array_m1165_x_1[5] = {&var1197,&var809,&var1552,&var1202,&var243};
psbool  array_m1153_x_1[4] = {&var1106,&var1148,&var1022,&var1200};
psfloat  array_m1431_x_1[16] = {&var422,&var431,&fRM_0_,&var428,&fRM_0_,&fRM_0_,&fRM_0_,&var425,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&var435};
psbool  array_m1751_x_1[17] = {&var502,&var503,&var509,&var504,&var500,&var501,&var959,&var505,&var506,&var1249,&var507,&var508,&var1241,&var1242,&var1251,&var237,&var238};
psbool  array_m1393_x_1[5] = {&var414,&var537,&var554,&var555,&var444};
psint  array_m303_x_1[3] = {&var1048,&iRM_0_,&var1070};
psint  array_m294_x_1[3] = {&var1047,&iRM_0_,&var1069};
psbool  array_m589_x_1[5] = {&var775,&var1519,&var1286,&var1003,&var203};
psbool  array_m1352_x_1[8] = {&var659,&var660,&var661,&var656,&var655,&var654,&var920,&var652};
psbool  array_m1287_x_1[3] = {&var87,&lRM_0_,&var86};
psfloat  array_m1289_Lt_fw_1[1] = {&fEM_A3UC81RDU};
psint  array_m1289_Vr_fw_1[1] = {&iEM_A3UV01IDU};
psfloat  array_m1289_Lt_bw_1[1] = {&fEM_A3UC82RDU};
psint  array_m1289_Vr_bw_1[1] = {&iEM_A3UV02IDU};
psfloat  array_m1317_x0_1[60];
psfloat  array_m1317_tim0_1[60];
psbool  array_m955_x_1[8] = {&var674,&var676,&var677,&var669,&var675,&var671,&var922,&var403};
psbool  array_m885_x_1[3] = {&var113,&lRM_0_,&var108};
psfloat  array_m887_Lt_fw_1[1] = {&fEM_A3UC81RDU};
psint  array_m887_Vr_fw_1[1] = {&iEM_A3UV01IDU};
psfloat  array_m887_Lt_bw_1[1] = {&fEM_A3UC82RDU};
psint  array_m887_Vr_bw_1[1] = {&iEM_A3UV02IDU};
psfloat  array_m920_x0_1[60];
psfloat  array_m920_tim0_1[60];
psbool  array_m486_x_1[3] = {&var751,&lRM_0_,&var752};
psfloat  array_m489_Lt_fw_1[2] = {&fEM_A1UC81RDU,&fEM_A1UC82RDU};
psint  array_m489_Vr_fw_1[2] = {&iEM_A1UV01IDU,&iEM_A1UV02IDU};
psfloat  array_m489_Lt_bw_1[1] = {&fEM_A1UC83RDU};
psint  array_m489_Vr_bw_1[1] = {&iEM_A1UV03IDU};
psfloat  array_m516_x0_1[150];
psfloat  array_m516_tim0_1[150];
psbool  array_m228_x_1[12] = {&var720,&var722,&var721,&var718,&var716,&var715,&var714,&var928,&var927,&var709,&var712,&var226};
psbool  array_m163_x_1[3] = {&var898,&lRM_0_,&var899};
psfloat  array_m168_Lt_fw_1[2] = {&fEM_A1UC81RDU,&fEM_A1UC82RDU};
psint  array_m168_Vr_fw_1[2] = {&iEM_A1UV01IDU,&iEM_A1UV02IDU};
psfloat  array_m168_Lt_bw_1[1] = {&fEM_A1UC83RDU};
psint  array_m168_Vr_bw_1[1] = {&iEM_A1UV03IDU};
psfloat  array_m197_x0_1[150];
psfloat  array_m197_tim0_1[150];
psbool  array_m860_x_1[10] = {&var686,&var687,&var693,&var694,&var692,&var690,&var689,&var930,&var929,&var688};
psbool  array_m806_x_1[3] = {&var89,&var704,&var88};
psfloat  array_m807_Lt_fw_1[2] = {&fEM_A2UC81RDU,&fEM_A2UC82RDU};
psint  array_m807_Vr_fw_1[2] = {&iEM_A2UV01IDU,&iEM_A2UV02IDU};
psfloat  array_m807_Lt_bw_1[1] = {&fEM_A2UC83RDU};
psint  array_m807_Vr_bw_1[1] = {&iEM_A2UV03CDU};
psfloat  array_m827_x0_1[80];
psfloat  array_m827_tim0_1[80];
psfloat  array_m1571_Lt_fw_1[1] = {&fRM_1000_};
psint  array_m1571_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1571_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1571_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1262_x_1[10] = {&var625,&var626,&var628,&var627,&var629,&var631,&var633,&var630,&var632,&var634};
psbool  array_m146_x_1[5] = {&A1IS21LDU,&A3IS21LDU,&A2IS21LDU,&var945,&var944};
psfloat  array_m1107_Lt_fw_1[1] = {&fRM_2000_};
psint  array_m1107_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1107_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1107_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1190_x_1[3] = {&var117,&var619,&var104};
psfloat  array_m1192_Lt_fw_1[2] = {&fEM_A2UC81RDU,&fEM_A2UC82RDU};
psint  array_m1192_Vr_fw_1[2] = {&iEM_A2UV01IDU,&iEM_A2UV02IDU};
psfloat  array_m1192_Lt_bw_1[1] = {&fEM_A2UC83RDU};
psint  array_m1192_Vr_bw_1[1] = {&iEM_A2UV03CDU};
psfloat  array_m1226_x0_1[80];
psfloat  array_m1226_tim0_1[80];
psfloat  array_m1591_x0_1[20];
psfloat  array_m1591_tim0_1[20];
psbool  array_m1078_x_1[8] = {&var836,&var833,&var834,&var835,&var832,&var831,&var830,&var829};
psbool  array_m590_x_1[18] = {&R0MD31LP1,&var527,&var850,&var529,&var848,&var620,&var755,&var703,&var730,&var750,&var679,&var644,&var906,&var342,&var341,&var610,&var259,&var195};
psfloat  array_m1131_x0_1[20];
psfloat  array_m1131_tim0_1[20];
psbool  array_m430_x_1[7] = {&var951,&var950,&var949,&var948,&var1623,&var940,&var371};
psbool  array_m412_x_1[7] = {&var953,&var1623,&var941,&var954,&var952,&var939,&var141};
psbool  array_m760_x_1[17] = {&var851,&var896,&var895,&var892,&var891,&var888,&var853,&var890,&var858,&var887,&var883,&var885,&var884,&var855,&var849,&var938,&var706};
psbool  array_m132_x_1[21] = {&var729,&var749,&var994,&var702,&var993,&var992,&var1557,&var1566,&var1584,&var1575,&var1611,&var1602,&var480,&var372,&var984,&var985,&var1263,&var1257,&var1421,&var1412,&var1593};

/* Объявление структур */
_S_and4  S_and4_106_2 = {&var1738,&var1673,&B8IS11LDU,&B8IS12LDU,&var1643};
_S_lkb  S_lkb_111_2 = {&lRM_1_,&var1671,&var1644};
_S_lkb  S_lkb_107_2 = {&lRM_1_,&var1643,&var1645};
_S_lkb  S_lkb_80_2 = {&lRM_1_,&var1674,&var1646};
_S_lkb  S_lkb_50_2 = {&lRM_1_,&var1679,&var1647};
_S_lkb  S_lkb_83_2 = {&lRM_1_,&var1677,&var1648};
_S_lkb  S_lkb_46_2 = {&lRM_1_,&var1683,&var1649};
_S_lkb  S_lkb_24_2 = {&lRM_1_,&var1681,&var1650};
_S_lkb  S_lkb_20_2 = {&lRM_1_,&var1685,&var1651};
_S_or2  S_or2_258_2 = {&var1742,&var1691,&var1652};
_S_bol  S_bol_223_2 = {&fRM_0_5,&var1654,&var1653};
_S_fsumo  S_fsumo_222_2 = {&var1690,&var1689,&var1654};
_S_noto  S_noto_251_2 = {&B3VP81LDU,&var1655};
_S_noto  S_noto_250_2 = {&B2VP82LDU,&var1656};
_S_noto  S_noto_249_2 = {&B4VP82LDU,&var1657};
_S_noto  S_noto_231_2 = {&A3VP81LDU,&var1658};
_S_noto  S_noto_230_2 = {&A2VP82LDU,&var1659};
_S_noto  S_noto_229_2 = {&A4VP82LDU,&var1660};
_S_schl24  S_schl24_149_2 = {&A0EE02LZ1,&A0EE03LZ1,&A0EE01LZ1,&A0EE04LZ1,&var1661};
_S_schl24  S_schl24_143_2 = {&A0EE03LZ2,&A0EE01LZ2,&A0EE02LZ2,&A0EE04LZ2,&var1662};
_S_or2  S_or2_198_2 = {&var1711,&var1712,&var1663};
_S_or2  S_or2_195_2 = {&var1714,&var1715,&var1664};
_S_and2  S_and2_213_2 = {&var1699,&var1710,&var1665};
_S_or2  S_or2_244_2 = {&var1706,&var1705,&var1666};
_S_and4  S_and4_159_2 = {&A0EE02LZ1,&A0EE04LZ1,&A0EE02LZ2,&A0EE04LZ2,&var1667};
_S_or3  S_or3_158_2 = {&var1667,&var814,&var1661,&var1668};
_S_and4  S_and4_136_2 = {&A0EE03LZ1,&A0EE01LZ1,&A0EE01LZ2,&A0EE03LZ2,&var1669};
_S_or3  S_or3_135_2 = {&var1669,&var1662,&var814,&var1670};
_S_and3  S_and3_110_2 = {&var1672,&var1738,&A8IS12LDU,&var1671};
_S_or2  S_or2_104_2 = {&A8MC01LC2,&A8MC01LC1,&var1672};
_S_or2  S_or2_103_2 = {&B8MC01LC2,&B8MC01LC1,&var1673};
_S_and3  S_and3_79_2 = {&var1738,&B3IS11LDU,&var1675,&var1674};
_S_or2  S_or2_71_2 = {&B3MC01LC2,&B3MC01LC1,&var1675};
_S_or2  S_or2_74_2 = {&A3MC01LC2,&A3MC01LC1,&var1676};
_S_and3  S_and3_82_2 = {&var1738,&var1676,&A3IS11LDU,&var1677};
_S_or2  S_or2_43_2 = {&A2MC01LC2,&A2MC01LC1,&var1678};
_S_and3  S_and3_49_2 = {&var1738,&A2IS11LDU,&var1678,&var1679};
_S_or2  S_or2_13_2 = {&A1MC01LC2,&A1MC01LC1,&var1680};
_S_and3  S_and3_23_2 = {&var1680,&var1738,&A1IS11LDU,&var1681};
_S_or2  S_or2_42_2 = {&B2MC01LC1,&B2MC01LC2,&var1682};
_S_and3  S_and3_45_2 = {&var1738,&B2IS11LDU,&var1682,&var1683};
_S_or2  S_or2_11_2 = {&B1MC01LC2,&B1MC01LC1,&var1684};
_S_and3  S_and3_19_2 = {&var1738,&B1IS11LDU,&var1684,&var1685};
_S_and2  S_and2_254_2 = {&syn_R0EE03LDU,&var1663,&var1686};
_S_and2  S_and2_233_2 = {&syn_R0EE03LDU,&var1664,&var1687};
_S_and2  S_and2_219_2 = {&var1700,&var1709,&var1688};
_S_scalzz  S_scalzz_186_2 = {&B3IP02IDU,&iRM_3276_,&iRM_16383_,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&var1689,&internal2_m186_y0};
_S_scalzz  S_scalzz_184_2 = {&A3IP02IDU,&iRM_3276_,&iRM_16383_,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&var1690,&internal2_m184_y0};
_S_noto  S_noto_171_2 = {&var1692,&var1691};
_S_andn  S_andn_170_2 = {array_m170_x_2,&iRM_17_,&var1692};
_S_noto  S_noto_153_2 = {&var1694,&var1693};
_S_andn  S_andn_150_2 = {array_m150_x_2,&iRM_6_,&var1694};
_S_noto  S_noto_134_2 = {&var1696,&var1695};
_S_andn  S_andn_131_2 = {array_m131_x_2,&iRM_6_,&var1696};
_S_noto  S_noto_253_2 = {&var1705,&var1697};
_S_noto  S_noto_235_2 = {&var1706,&var1698};
_S_noto  S_noto_212_2 = {&var1714,&var1699};
_S_noto  S_noto_220_2 = {&var1711,&var1700};
_S_noto  S_noto_157_2 = {&var1668,&var1701};
_S_noto  S_noto_141_2 = {&var1670,&var1702};
_S_noto  S_noto_256_2 = {&var1707,&var1703};
_S_noto  S_noto_240_2 = {&var1708,&var1704};
_S_ornc  S_ornc_243_2 = {array_m243_x_2,&iRM_6_,&var1705,&vainSChar};
_S_ornc  S_ornc_232_2 = {array_m232_x_2,&iRM_6_,&var1706,&vainSChar};
_S_ornc  S_ornc_255_2 = {array_m255_x_2,&iRM_6_,&var1707,&vainSChar};
_S_ornc  S_ornc_234_2 = {array_m234_x_2,&iRM_6_,&var1708,&vainSChar};
_S_tprg  S_tprg_216_2 = {&var1689,&fEM_A3UP85RDU,&fEM_A3UP86RDU,&fEM_A3UP87RDU,&fEM_A3UP88RDU,&var1709,&internal2_m216_y0};
_S_tprg  S_tprg_210_2 = {&var1690,&fEM_A3UP85RDU,&fEM_A3UP86RDU,&fEM_A3UP87RDU,&fEM_A3UP88RDU,&var1710,&internal2_m210_y0};
_S_geterr  S_geterr_191_2 = {&var1689,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var1711};
_S_drg  S_drg_199_2 = {&var1689,&lRM_1_,&lRM_0_,&fEM_A3UP43RDU,&fEM_A3UP44RDU,&var1712,&internal2_m199_y1};
_S_drg  S_drg_206_2 = {&var1689,&lRM_1_,&lRM_0_,&fEM_A3UP53RDU,&fEM_A3UP54RDU,&var1713,&internal2_m206_y1};
_S_geterr  S_geterr_188_2 = {&var1690,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var1714};
_S_drg  S_drg_189_2 = {&var1690,&lRM_1_,&lRM_0_,&fEM_A3UP43RDU,&fEM_A3UP44RDU,&var1715,&internal2_m189_y1};
_S_drg  S_drg_196_2 = {&var1690,&lRM_1_,&lRM_0_,&fEM_A3UP53RDU,&fEM_A3UP54RDU,&var1716,&internal2_m196_y1};
_S_enctkb  S_enctkb_16_2 = {&var1650,&fRM_0_0,&A1IC01UDU,&dEM_A1UC06UDU,&dEM_A1UC05UDU,&fEM_A1UC03RDU,&fRM_100_,&dRM_0_,&var1717,&var1718,&var1719,&internal2_m16_Nk0,&internal2_m16_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_108_2 = {&var1645,&fRM_390_,&B8IC01UDU,&dEM_A8UC06UDU,&dEM_A8UC05UDU,&fEM_A8UC03RDU,&fRM_1500_0,&dRM_0_,&var1720,&var1721,&var1722,&internal2_m108_Nk0,&internal2_m108_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_112_2 = {&var1644,&fRM_390_0,&A8IC01UDU,&dEM_A8UC06UDU,&dEM_A8UC05UDU,&fEM_A8UC03RDU,&fRM_1500_0,&dRM_0_,&var1723,&var1724,&var1725,&internal2_m112_Nk0,&internal2_m112_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_75_2 = {&var1646,&fRM_0_,&B3IC01UDU,&dEM_A3UC06UDU,&dEM_A3UC05UDU,&fEM_A3UC03RDU,&fRM_0_0,&dRM_0_,&var1726,&var1727,&var1728,&internal2_m75_Nk0,&internal2_m75_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_77_2 = {&var1648,&fRM_0_0,&A3IC01UDU,&dEM_A3UC06UDU,&dEM_A3UC05UDU,&fEM_A3UC03RDU,&fRM_0_0,&dRM_0_,&var1729,&var1730,&var1731,&internal2_m77_Nk0,&internal2_m77_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_47_2 = {&var1649,&fRM_0_0,&B2IC01UDU,&dEM_A2UC06UDU,&dEM_A2UC05UDU,&fEM_A2UC03RDU,&fRM_100_,&dRM_0_,&var1732,&var1733,&var1734,&internal2_m47_Nk0,&internal2_m47_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_51_2 = {&var1647,&fRM_0_0,&A2IC01UDU,&dEM_A2UC06UDU,&dEM_A2UC05UDU,&fEM_A2UC03RDU,&fRM_100_,&dRM_0_,&var1735,&var1736,&var1737,&internal2_m51_Nk0,&internal2_m51_SetFlag,&bFirstEnterFlag};
_S_equz_p  S_equz_p_18_2 = {&R0MW12IP1,&iRM_4_,&var1738};
_S_enctkb  S_enctkb_21_2 = {&var1651,&fRM_0_0,&B1IC01UDU,&dEM_A1UC06UDU,&dEM_A1UC05UDU,&fEM_A1UC03RDU,&fRM_100_,&dRM_0_,&var1739,&var1740,&var1741,&internal2_m21_Nk0,&internal2_m21_SetFlag,&bFirstEnterFlag};
_S_ornc  S_ornc_124_2 = {array_m124_x_2,&iRM_8_,&var1742,&vainSChar};
_S_or3  S_or3_2295_1 = {&var2,&var5,&var6,&var1};
_S_orn  S_orn_2294_1 = {array_m2294_x_1,&iRM_6_,&var2};
_S_or2  S_or2_2299_1 = {&R0DEB3LDU,&R0DEB4LDU,&var3};
_S_or2  S_or2_2292_1 = {&R0DEB1LDU,&R0DEB2LDU,&var4};
_S_and2  S_and2_2283_1 = {&R0DE31LDU,&R0DE32LDU,&var5};
_S_diagndev  S_diagndev_2278_1 = {array_m2278_x_1,&iRM_12_,&var6,&var7};
_S_or2  S_or2_1677_1 = {&var245,&var58,&var8};
_S_and2  S_and2_1667_1 = {&var301,&var1206,&var9};
_S_rs  S_rs_1676_1 = {&var8,&var9,&var10,&vainSBool,&internal1_m1676_q0};
_S_or2  S_or2_1671_1 = {&var301,&var248,&var11};
_S_or2  S_or2_1612_1 = {&var1256,&var301,&var12};
_S_noto  S_noto_1655_1 = {&B2IS11LDU,&var13};
_S_or2  S_or2_1640_1 = {&var16,&var58,&var14};
_S_or2  S_or2_1642_1 = {&var128,&var58,&var15};
_S_noto  S_noto_1653_1 = {&A2IS11LDU,&var16};
_S_or2  S_or2_2116_1 = {&var245,&var54,&var17};
_S_or2  S_or2_2114_1 = {&var54,&var252,&var18};
_S_or2  S_or2_2112_1 = {&var67,&var54,&var19};
_S_and2  S_and2_2095_1 = {&var1203,&var299,&var20};
_S_or2  S_or2_2110_1 = {&var22,&var54,&var21};
_S_noto  S_noto_2119_1 = {&B3IS11LDU,&var22};
_S_or2  S_or2_2146_1 = {&var58,&var252,&var23};
_S_and2  S_and2_2126_1 = {&var1203,&var300,&var24};
_S_noto  S_noto_2151_1 = {&A3IS11LDU,&var25};
_S_or2  S_or2_2148_1 = {&var245,&var58,&var26};
_S_or2  S_or2_2144_1 = {&var58,&var68,&var27};
_S_or2  S_or2_2142_1 = {&var58,&var25,&var28};
_S_or2  S_or2_1620_1 = {&var245,&var58,&var29};
_S_or2  S_or2_1624_1 = {&var245,&var54,&var30};
_S_or2  S_or2_1615_1 = {&var301,&var1256,&var31};
_S_or2  S_or2_1650_1 = {&var54,&var127,&var32};
_S_or2  S_or2_1648_1 = {&var13,&var54,&var33};
_S_or2  S_or2_1693_1 = {&var252,&var54,&var34};
_S_or2  S_or2_1690_1 = {&var252,&var58,&var35};
_S_or2  S_or2_1722_1 = {&var258,&var54,&var36};
_S_or2  S_or2_1719_1 = {&var258,&var58,&var37};
_S_or2  S_or2_1679_1 = {&var245,&var54,&var38};
_S_or2  S_or2_1644_1 = {&var245,&var58,&var39};
_S_or2  S_or2_1652_1 = {&var245,&var54,&var40};
_S_or3  S_or3_2106_1 = {&var252,&var299,&var54,&var41};
_S_or3  S_or3_2108_1 = {&var77,&var299,&var54,&var42};
_S_or3  S_or3_2140_1 = {&var58,&var80,&var300,&var43};
_S_or3  S_or3_2138_1 = {&var252,&var58,&var300,&var44};
_S_or3  S_or3_2104_1 = {&var299,&var245,&var54,&var45};
_S_or3  S_or3_2136_1 = {&var245,&var300,&var58,&var46};
_S_or3  S_or3_1618_1 = {&var245,&var300,&var58,&var47};
_S_or3  S_or3_1622_1 = {&var299,&var245,&var54,&var48};
_S_or3  S_or3_1638_1 = {&var245,&var300,&var58,&var49};
_S_or3  S_or3_1646_1 = {&var245,&var299,&var54,&var50};
_S_or3  S_or3_1675_1 = {&var245,&var301,&var54,&var51};
_S_or3  S_or3_1673_1 = {&var245,&var58,&var301,&var52};
_S_or3  S_or3_1721_1 = {&var54,&var299,&var258,&var53};
_S_noto  S_noto_1716_1 = {&var911,&var54};
_S_or3  S_or3_1692_1 = {&var54,&var252,&var299,&var55};
_S_or3  S_or3_1689_1 = {&var252,&var58,&var300,&var56};
_S_or3  S_or3_1718_1 = {&var258,&var58,&var300,&var57};
_S_noto  S_noto_1712_1 = {&var910,&var58};
_S_regch  S_regch_125_1 = {&R0MW12IP1,&var900,&var59};
_S_or2  S_or2_128_1 = {&var61,&var59,&var60};
_S_or2  S_or2_127_1 = {&R0VZ71LZ1,&R0VZ71LZ2,&var61};
_S_and3  S_and3_1385_1 = {&R0MD11LP2,&var959,&var65,&var62};
_S_and2  S_and2_723_1 = {&R4MD21LP2,&var65,&var63};
_S_and2  S_and2_722_1 = {&R4MD11LP2,&var65,&var64};
_S_noto  S_noto_107_1 = {&var1633,&var65};
_S_and2  S_and2_105_1 = {&R0MD11LP1,&var65,&var66};
_S_noto  S_noto_2120_1 = {&B3IS22LDU,&var67};
_S_noto  S_noto_2152_1 = {&A3IS22LDU,&var68};
_S_and2  S_and2_2043_1 = {&var476,&var1185,&var69};
_S_or3  S_or3_2038_1 = {&var475,&var171,&var109,&var70};
_S_and2  S_and2_2029_1 = {&var472,&var1185,&var71};
_S_or3  S_or3_2024_1 = {&var171,&var473,&var92,&var72};
_S_or2  S_or2_1450_1 = {&var1274,&var1203,&var73};
_S_or2  S_or2_1419_1 = {&var1131,&var1203,&var74};
_S_rs  S_rs_2109_1 = {&var21,&var78,&var75,&vainSBool,&internal1_m2109_q0};
_S_rs  S_rs_2093_1 = {&var21,&var97,&var76,&vainSBool,&internal1_m2093_q0};
_S_noto  S_noto_2117_1 = {&syn_B3VP52LDU,&var77};
_S_and2  S_and2_2100_1 = {&var77,&var76,&var78};
_S_rs  S_rs_2141_1 = {&var28,&var81,&var79,&vainSBool,&internal1_m2141_q0};
_S_noto  S_noto_2149_1 = {&syn_A3VP52LDU,&var80};
_S_and2  S_and2_2132_1 = {&var82,&var80,&var81};
_S_rs  S_rs_2125_1 = {&var28,&var115,&var82,&vainSBool,&internal1_m2125_q0};
_S_and4  S_and4_1340_1 = {&var959,&var1203,&var263,&var1248,&var83};
_S_and4  S_and4_943_1 = {&var959,&var1203,&var263,&var1248,&var84};
_S_rs  S_rs_2115_1 = {&var17,&var90,&var85,&vainSBool,&internal1_m2115_q0};
_S_or4  S_or4_1277_1 = {&var595,&var285,&var998,&var92,&var86};
_S_or4  S_or4_1286_1 = {&var160,&var288,&var771,&var98,&var87};
_S_orn  S_orn_796_1 = {array_m796_x_1,&iRM_6_,&var88};
_S_or3  S_or3_808_1 = {&var790,&var1199,&var101,&var89};
_S_and2  S_and2_2102_1 = {&var252,&var91,&var90};
_S_rs  S_rs_2096_1 = {&var17,&var93,&var91,&vainSBool,&internal1_m2096_q0};
_S_rs  S_rs_2113_1 = {&var93,&var18,&var92,&vainSBool,&internal1_m2113_q0};
_S_and2  S_and2_2101_1 = {&var94,&var67,&var93};
_S_rs  S_rs_2094_1 = {&var18,&var20,&var94,&vainSBool,&internal1_m2094_q0};
_S_rs  S_rs_2092_1 = {&var42,&var99,&var95,&vainSBool,&internal1_m2092_q0};
_S_rs  S_rs_2091_1 = {&var41,&var100,&var96,&vainSBool,&internal1_m2091_q0};
_S_and2  S_and2_2099_1 = {&var252,&var95,&var97};
_S_rs  S_rs_2105_1 = {&var41,&var99,&var98,&vainSBool,&internal1_m2105_q0};
_S_and2  S_and2_2098_1 = {&var96,&var245,&var99};
_S_and2  S_and2_2097_1 = {&var302,&var1203,&var100};
_S_rs  S_rs_2103_1 = {&var45,&var100,&var101,&vainSBool,&internal1_m2103_q0};
_S_rs  S_rs_2111_1 = {&var20,&var19,&var102,&vainSBool,&internal1_m2111_q0};
_S_rs  S_rs_2107_1 = {&var42,&var97,&var103,&vainSBool,&internal1_m2107_q0};
_S_orn  S_orn_1181_1 = {array_m1181_x_1,&iRM_6_,&var104};
_S_rs  S_rs_2147_1 = {&var26,&var106,&var105,&vainSBool,&internal1_m2147_q0};
_S_and2  S_and2_2134_1 = {&var252,&var107,&var106};
_S_rs  S_rs_2128_1 = {&var26,&var110,&var107,&vainSBool,&internal1_m2128_q0};
_S_or4  S_or4_875_1 = {&var594,&var289,&var998,&var109,&var108};
_S_rs  S_rs_2145_1 = {&var23,&var110,&var109,&vainSBool,&internal1_m2145_q0};
_S_and2  S_and2_2133_1 = {&var111,&var68,&var110};
_S_rs  S_rs_2127_1 = {&var23,&var24,&var111,&vainSBool,&internal1_m2127_q0};
_S_rs  S_rs_2124_1 = {&var43,&var118,&var112,&vainSBool,&internal1_m2124_q0};
_S_or4  S_or4_884_1 = {&var1196,&var160,&var781,&var116,&var113};
_S_rs  S_rs_2123_1 = {&var44,&var119,&var114,&vainSBool,&internal1_m2123_q0};
_S_and2  S_and2_2131_1 = {&var252,&var112,&var115};
_S_rs  S_rs_2137_1 = {&var44,&var118,&var116,&vainSBool,&internal1_m2137_q0};
_S_or3  S_or3_1193_1 = {&var789,&var1201,&var120,&var117};
_S_and2  S_and2_2130_1 = {&var114,&var245,&var118};
_S_and2  S_and2_2129_1 = {&var303,&var1203,&var119};
_S_rs  S_rs_2135_1 = {&var46,&var119,&var120,&vainSBool,&internal1_m2135_q0};
_S_or2  S_or2_2010_1 = {&var162,&var1030,&var121};
_S_ovbs  S_ovbs_2012_1 = {&var221,&fRM_2_0,&var122,&internal1_m2012_tx};
_S_or2  S_or2_2013_1 = {&var1212,&var122,&var123};
_S_ovbs  S_ovbs_1991_1 = {&var222,&fRM_2_0,&var124,&internal1_m1991_tx};
_S_or2  S_or2_1989_1 = {&var163,&var1031,&var125};
_S_or2  S_or2_1992_1 = {&var1232,&var124,&var126};
_S_noto  S_noto_1656_1 = {&B2IS21LDU,&var127};
_S_noto  S_noto_1654_1 = {&A2IS21LDU,&var128};
_S_and2  S_and2_2063_1 = {&syn_B3VP52LDU,&var477,&var129};
_S_or5  S_or5_2066_1 = {&var652,&var1642,&var146,&var102,&var129,&var130};
_S_or5  S_or5_2065_1 = {&var403,&var1194,&var479,&var1642,&syn_A3VP52LDU,&var131};
_S_and2  S_and2_2040_1 = {&syn_A3VP52LDU,&var478,&var132};
_S_nocnm  S_nocnm_1698_1 = {&R5IS21LDU,&R5IS11LDU,&var133,&var134,&var135,&internal1_m1698_Pv0,&internal1_m1698_Zv0,&internal1_m1698_MyFirstEnterFlag,&bFirstEnterFlag};
_S_nocnm  S_nocnm_1697_1 = {&R3IS11LDU,&R3IS21LDU,&var136,&var137,&var138,&internal1_m1697_Pv0,&internal1_m1697_Zv0,&internal1_m1697_MyFirstEnterFlag,&bFirstEnterFlag};
_S_or5  S_or5_1960_1 = {&var994,&var702,&C2MD31LP1,&var993,&var992,&var139};
_S_or4  S_or4_1936_1 = {&C1MD31LP2,&C1MD31LP1,&var729,&var749,&var140};
_S_and3  S_and3_408_1 = {&B8IS22LDU,&B8IS21LDU,&var1615,&var141};
_S_and2  S_and2_2027_1 = {&var471,&var171,&var142};
_S_and2  S_and2_2037_1 = {&var474,&var171,&var143};
_S_or4  S_or4_975_1 = {&var1321,&var664,&var663,&var666,&var144};
_S_or4  S_or4_1372_1 = {&var1289,&var645,&var646,&var649,&var145};
_S_and2  S_and2_2067_1 = {&var392,&var1185,&var146};
_S_and2  S_and2_2052_1 = {&var477,&var1642,&var147};
_S_and2  S_and2_2041_1 = {&var478,&var1642,&var148};
_S_or2  S_or2_547_1 = {&B1VP41LZ2,&B1VP41LZ1,&var149};
_S_or2  S_or2_230_1 = {&A1VP41LZ2,&A1VP41LZ1,&var150};
_S_or2  S_or2_1111_1 = {&B8IS22LDU,&B8IS21LDU,&var151};
_S_or2  S_or2_1104_1 = {&B8IS11LDU,&B8IS12LDU,&var152};
_S_or2  S_or2_349_1 = {&R4IS11LDU,&R4IS12LDU,&var153};
_S_or2  S_or2_366_1 = {&R4IS21LDU,&R4IS22LDU,&var154};
_S_or2  S_or2_1063_1 = {&var1001,&R0MD34LP1,&var155};
_S_or2  S_or2_1066_1 = {&var999,&R0MD34LP1,&var156};
_S_or2  S_or2_1069_1 = {&var997,&R0MD34LP1,&var157};
_S_or2  S_or2_1072_1 = {&var995,&R0MD34LP1,&var158};
_S_noto  S_noto_2177_1 = {&var1642,&var159};
_S_zzfs  S_zzfs_2165_1 = {&var177,&fRM_0_5,&var160,&internal1_m2165_tx,&internal1_m2165_y0};
_S_or2  S_or2_2200_1 = {&var353,&var1003,&var161};
_S_andn  S_andn_587_1 = {array_m587_x_1,&iRM_6_,&var162};
_S_andn  S_andn_586_1 = {array_m586_x_1,&iRM_6_,&var163};
_S_or2  S_or2_2214_1 = {&var679,&var644,&var164};
_S_noto  S_noto_2162_1 = {&var1029,&var165};
_S_noto  S_noto_2161_1 = {&var1026,&var166};
_S_zpfs  S_zpfs_2170_1 = {&var165,&fRM_30_0,&var167,&internal1_m2170_tx,&internal1_m2170_y0};
_S_noto  S_noto_2175_1 = {&var167,&var168};
_S_zpfs  S_zpfs_2169_1 = {&var166,&fRM_30_0,&var169,&internal1_m2169_tx,&internal1_m2169_y0};
_S_noto  S_noto_2174_1 = {&var169,&var170};
_S_and3  S_and3_2167_1 = {&var210,&var190,&lRM_1_,&var171};
_S_and2  S_and2_903_1 = {&var1347,&var173,&var172};
_S_noto  S_noto_890_1 = {&var160,&var173};
_S_and2  S_and2_1303_1 = {&var1315,&var175,&var174};
_S_noto  S_noto_1300_1 = {&var160,&var175};
_S_or2  S_or2_2210_1 = {&var186,&var187,&var176};
_S_and2  S_and2_2164_1 = {&var178,&var171,&var177};
_S_abs_subf  S_abs_subf_2157_1 = {&var1729,&var211,&fEM_A3UC08RDU,&vainSFloat,&var178};
_S_and2  S_and2_2212_1 = {&var171,&var186,&var179};
_S_or4  S_or4_1961_1 = {&var139,&var807,&var917,&var179,&var180};
_S_noto  S_noto_2213_1 = {&var164,&var181};
_S_or2  S_or2_2192_1 = {&var204,&var215,&var182};
_S_inf  S_inf_2185_1 = {&var213,array_m2185_a_1,array_m2185_b_1,&iRM_6_,&var183,&vainSInt};
_S_or3  S_or3_2218_1 = {&var200,&var207,&var208,&var184};
_S_noto  S_noto_2217_1 = {&var184,&var185};
_S_noto  S_noto_2211_1 = {&var210,&var186};
_S_ovbs  S_ovbs_2206_1 = {&var189,&fRM_15_0,&var187,&internal1_m2206_tx};
_S_zpfs  S_zpfs_2204_1 = {&var190,&fRM_10_0,&var188,&internal1_m2204_tx,&internal1_m2204_y0};
_S_and2  S_and2_2205_1 = {&var188,&R0MW17LP1,&var189};
_S_rs  S_rs_2209_1 = {&var176,&R0MW17LP1,&var190,&vainSBool,&internal1_m2209_q0};
_S_rs  S_rs_2176_1 = {&var204,&var171,&var191,&vainSBool,&internal1_m2176_q0};
_S_and3  S_and3_2183_1 = {&var206,&var159,&var191,&var192};
_S_ml  S_ml_1281_1 = {&var211,&var313,&var160,&var193};
_S_ml  S_ml_881_1 = {&var211,&var317,&var160,&var194};
_S_and2  S_and2_2230_1 = {&var171,&var330,&var195};
_S_noto  S_noto_2198_1 = {&var161,&var196};
_S_noto  S_noto_2181_1 = {&var1286,&var197};
_S_sr  S_sr_2199_1 = {array_m2199_x_1,&iRM_4_,&var198};
_S_sr  S_sr_2220_1 = {array_m2220_x_1,&iRM_2_,&var199};
_S_and2  S_and2_2234_1 = {&var201,&var171,&var200};
_S_abs_subf  S_abs_subf_2229_1 = {&B3MC01RP1,&A3MC01RP1,&fRM_0_01,&vainSFloat,&var201};
_S_fsumo  S_fsumo_80_1 = {&var979,&fEM_R0UN11RDU,&var202};
_S_or3  S_or3_126_1 = {&var140,&var60,&var182,&var203};
_S_ovbs  S_ovbs_2184_1 = {&var192,&fRM_1_0,&var204,&internal1_m2184_tx};
_S_noto  S_noto_2191_1 = {&var182,&var205};
_S_rs  S_rs_2182_1 = {&var204,&var1642,&var206,&vainSBool,&internal1_m2182_q0};
_S_and2  S_and2_2233_1 = {&var215,&var171,&var207};
_S_and2  S_and2_2232_1 = {&var209,&var171,&var208};
_S_bol  S_bol_2221_1 = {&fEM_R0UN09RDU,&var199,&var209};
_S_andn  S_andn_2189_1 = {array_m2189_x_1,&iRM_14_,&var210};
_S_irm  S_irm_2168_1 = {&var979,&var977,&B3MC01RP1,&var1729,&var199,&var198,&var171,&var1003,&fEM_R0UN12RDU,&fEM_R0UN13RDU,&fEM_R0UN14RDU,&fEM_R0UT20RDU,&var183,&fEM_R0UN15RDU,&fEM_R0UN25RDU,&fEM_R0UN16RDU,&fEM_R0UN17RDU,&fEM_R0UN18RDU,&fEM_R0UN19RDU,&fEM_R0UN27RDU,&fEM_R0UN26RDU,&fEM_R0UN24RDU,&var211,&var212,&var213,&var214,&var215,&var216,&var217,&var218};
_S_noto  S_noto_2018_1 = {&var341,&var219};
_S_noto  S_noto_1988_1 = {&var342,&var220};
_S_and4  S_and4_2011_1 = {&var364,&var121,&var334,&var219,&var221};
_S_and4  S_and4_1990_1 = {&var365,&var125,&var334,&var220,&var222};
_S_zpfs  S_zpfs_2006_1 = {&var348,&fRM_210_0,&var223,&internal1_m2006_tx,&internal1_m2006_y0};
_S_zpfs  S_zpfs_1998_1 = {&var349,&fRM_210_0,&var224,&internal1_m1998_tx,&internal1_m1998_y0};
_S_and2  S_and2_550_1 = {&var1362,&var397,&var225};
_S_and2  S_and2_233_1 = {&var397,&var1395,&var226};
_S_noto  S_noto_1537_1 = {&var228,&var227};
_S_abs_subf  S_abs_subf_1531_1 = {&var1726,&var313,&fEM_A3UC07RDU,&vainSFloat,&var228};
_S_noto  S_noto_1518_1 = {&var230,&var229};
_S_abs_subf  S_abs_subf_1509_1 = {&var317,&var1729,&fEM_A3UC07RDU,&vainSFloat,&var230};
_S_noto  S_noto_1535_1 = {&var232,&var231};
_S_abs_subf  S_abs_subf_1529_1 = {&var321,&var1739,&fEM_A1UC07RDU,&vainSFloat,&var232};
_S_noto  S_noto_1515_1 = {&var234,&var233};
_S_abs_subf  S_abs_subf_1508_1 = {&var325,&var1717,&fEM_A1UC07RDU,&vainSFloat,&var234};
_S_bol  S_bol_1299_1 = {&var1726,&fEM_A3UC09RDU,&var235};
_S_bol  S_bol_900_1 = {&var1729,&fEM_A3UC09RDU,&var236};
_S_noto  S_noto_1763_1 = {&var241,&var237};
_S_noto  S_noto_1752_1 = {&var239,&var238};
_S_and3  S_and3_1745_1 = {&var911,&var240,&var1203,&var239};
_S_bol  S_bol_1737_1 = {&fRM_55_0,&var313,&var240};
_S_and3  S_and3_1764_1 = {&var242,&var910,&var1203,&var241};
_S_bol  S_bol_1773_1 = {&fRM_55_0,&var317,&var242};
_S_and4  S_and4_45_1 = {&var1633,&var909,&var1088,&var1185,&var243};
_S_noto  S_noto_1214_1 = {&var959,&var244};
_S_and2  S_and2_1219_1 = {&var1462,&var959,&var245};
_S_and2  S_and2_1215_1 = {&var1462,&var244,&var246};
_S_noto  S_noto_1161_1 = {&var959,&var247};
_S_and2  S_and2_1169_1 = {&var959,&var1536,&var248};
_S_and2  S_and2_1162_1 = {&var1536,&var247,&var249};
_S_noto  S_noto_909_1 = {&var959,&var250};
_S_and2  S_and2_910_1 = {&var250,&var1318,&var251};
_S_and2  S_and2_906_1 = {&var1318,&var959,&var252};
_S_noto  S_noto_462_1 = {&var959,&var253};
_S_and2  S_and2_463_1 = {&var253,&var1411,&var254};
_S_and2  S_and2_465_1 = {&var1411,&var959,&var255};
_S_noto  S_noto_190_1 = {&var959,&var256};
_S_and2  S_and2_191_1 = {&var256,&var1381,&var257};
_S_and2  S_and2_194_1 = {&var959,&var1381,&var258};
_S_and2  S_and2_121_1 = {&var261,&var386,&var259};
_S_and2  S_and2_122_1 = {&var959,&var386,&var260};
_S_noto  S_noto_116_1 = {&var959,&var261};
_S_and2  S_and2_117_1 = {&var261,&var385,&var262};
_S_and2  S_and2_118_1 = {&var959,&var385,&var263};
_S_and2  S_and2_1610_1 = {&var299,&var1207,&var264};
_S_and2  S_and2_1609_1 = {&var302,&var1207,&var265};
_S_and2  S_and2_1608_1 = {&var300,&var1207,&var266};
_S_and2  S_and2_1607_1 = {&var1207,&var303,&var267};
_S_and2  S_and2_1606_1 = {&var520,&var301,&var268};
_S_and2  S_and2_1605_1 = {&var520,&var304,&var269};
_S_and2  S_and2_1604_1 = {&var521,&var301,&var270};
_S_and2  S_and2_1603_1 = {&var521,&var304,&var271};
_S_and2  S_and2_1636_1 = {&var32,&var1164,&var272};
_S_and2  S_and2_1635_1 = {&var299,&var1208,&var273};
_S_and2  S_and2_1634_1 = {&var1165,&var299,&var274};
_S_and2  S_and2_1633_1 = {&var1208,&var302,&var275};
_S_and2  S_and2_1632_1 = {&var128,&var1166,&var276};
_S_and2  S_and2_1631_1 = {&var1208,&var300,&var277};
_S_and2  S_and2_1630_1 = {&var1167,&var245,&var278};
_S_and2  S_and2_1629_1 = {&var1208,&var303,&var279};
_S_and2  S_and2_1669_1 = {&var245,&var1168,&var280};
_S_and2  S_and2_1668_1 = {&var301,&var1206,&var281};
_S_and2  S_and2_1666_1 = {&var1169,&var248,&var282};
_S_and2  S_and2_1665_1 = {&var1170,&var248,&var283};
_S_and2  S_and2_1664_1 = {&var304,&var1206,&var284};
_S_rs  S_rs_1686_1 = {&var34,&var286,&var285,&vainSBool,&internal1_m1686_q0};
_S_and2  S_and2_1685_1 = {&var1204,&var299,&var286};
_S_and2  S_and2_1684_1 = {&var1204,&var302,&var287};
_S_rs  S_rs_1691_1 = {&var55,&var287,&var288,&vainSBool,&internal1_m1691_q0};
_S_rs  S_rs_1683_1 = {&var35,&var290,&var289,&vainSBool,&internal1_m1683_q0};
_S_and2  S_and2_1682_1 = {&var300,&var1204,&var290};
_S_and2  S_and2_1681_1 = {&var1204,&var303,&var291};
_S_and2  S_and2_1715_1 = {&var301,&var1635,&var292};
_S_rs  S_rs_1725_1 = {&var255,&var292,&var293,&vainSBool,&internal1_m1725_q0};
_S_and2  S_and2_1714_1 = {&var1635,&var304,&var294};
_S_and2  S_and2_1711_1 = {&var299,&var1192,&var295};
_S_and2  S_and2_1710_1 = {&var1192,&var302,&var296};
_S_and2  S_and2_1708_1 = {&var300,&var1192,&var297};
_S_and2  S_and2_1707_1 = {&var1192,&var303,&var298};
_S_and2  S_and2_1727_1 = {&var911,&var301,&var299};
_S_and2  S_and2_1706_1 = {&var910,&var301,&var300};
_S_and2  S_and2_1729_1 = {&var260,&var1248,&var301};
_S_and2  S_and2_1726_1 = {&var304,&var911,&var302};
_S_and2  S_and2_1705_1 = {&var304,&var910,&var303};
_S_and2  S_and2_1728_1 = {&var263,&var1248,&var304};
_S_zpfs  S_zpfs_740_1 = {&var875,&fRM_3_,&var305,&internal1_m740_tx,&internal1_m740_y0};
_S_or4  S_or4_1550_1 = {&var511,&var512,&var513,&var515,&var306};
_S_or5  S_or5_1541_1 = {&var519,&var518,&var517,&var516,&var306,&var307};
_S_andn  S_andn_1_1 = {array_m1_x_1,&iRM_47_,&vainSBool};
_S_or2  S_or2_1519_1 = {&var310,&var311,&var308};
_S_ml  S_ml_1507_1 = {&fRM_1500_0,&B8MC01RP2,&var308,&var309};
_S_bol  S_bol_1517_1 = {&B8MC01RP2,&fRM_1500_0001,&var310};
_S_bol  S_bol_1524_1 = {&fRM_389_99,&B8MC01RP2,&var311};
_S_or2  S_or2_1536_1 = {&var314,&var315,&var312};
_S_ml  S_ml_1528_1 = {&fRM_0_0,&B3MC01RP1,&var312,&var313};
_S_bol  S_bol_1530_1 = {&B3MC01RP1,&fRM_160_00001,&var314};
_S_bol  S_bol_1540_1 = {&fRM_0_0001,&B3MC01RP1,&var315};
_S_or2  S_or2_1516_1 = {&var318,&var319,&var316};
_S_ml  S_ml_1506_1 = {&fRM_0_0,&A3MC01RP1,&var316,&var317};
_S_bol  S_bol_1512_1 = {&A3MC01RP1,&fRM_160_0001,&var318};
_S_bol  S_bol_1522_1 = {&fRM_0_0001,&A3MC01RP1,&var319};
_S_or2  S_or2_1534_1 = {&var322,&var323,&var320};
_S_ml  S_ml_1526_1 = {&fRM_100_0,&B1MC01RP1,&var320,&var321};
_S_bol  S_bol_1532_1 = {&B1MC01RP1,&fRM_100_0001,&var322};
_S_bol  S_bol_1538_1 = {&fRM_0_0001,&B1MC01RP1,&var323};
_S_or2  S_or2_1514_1 = {&var326,&var327,&var324};
_S_ml  S_ml_1504_1 = {&fRM_100_0,&A1MC01RP1,&var324,&var325};
_S_bol  S_bol_1511_1 = {&A1MC01RP1,&fRM_100_0001,&var326};
_S_bol  S_bol_1520_1 = {&fRM_0_0001,&A1MC01RP1,&var327};
_S_and2  S_and2_102_1 = {&var66,&var153,&var328};
_S_noto  S_noto_103_1 = {&var153,&var329};
_S_and2  S_and2_106_1 = {&var66,&var329,&var330};
_S_and2  S_and2_1977_1 = {&var332,&var333,&var331};
_S_or3  S_or3_1976_1 = {&var1210,&var464,&var180,&var332};
_S_noto  S_noto_2014_1 = {&var123,&var333};
_S_noto  S_noto_2003_1 = {&var335,&var334};
_S_ovbs  S_ovbs_2002_1 = {&var1100,&fRM_2_0,&var335,&internal1_m2002_tx};
_S_noto  S_noto_1993_1 = {&var126,&var336};
_S_and2  S_and2_1963_1 = {&var338,&var336,&var337};
_S_or3  S_or3_1962_1 = {&var180,&var1214,&var464,&var338};
_S_noto  S_noto_2008_1 = {&var346,&var339};
_S_and2  S_and2_2009_1 = {&var1185,&var339,&var340};
_S_and2  S_and2_2017_1 = {&var340,&var121,&var341};
_S_and2  S_and2_1996_1 = {&var343,&var125,&var342};
_S_and2  S_and2_2001_1 = {&var344,&var1185,&var343};
_S_noto  S_noto_2000_1 = {&var902,&var344};
_S_noto  S_noto_2016_1 = {&var348,&var345};
_S_or2  S_or2_2007_1 = {&var223,&var345,&var346};
_S_noto  S_noto_1995_1 = {&var349,&var347};
_S_rs  S_rs_2005_1 = {&var223,&var354,&var348,&vainSBool,&internal1_m2005_q0};
_S_rs  S_rs_1997_1 = {&var224,&var355,&var349,&vainSBool,&internal1_m1997_q0};
_S_and2  S_and2_1986_1 = {&var352,&var359,&var350};
_S_and2  S_and2_1974_1 = {&var352,&var356,&var351};
_S_noto  S_noto_1968_1 = {&var353,&var352};
_S_ovbs  S_ovbs_1967_1 = {&var180,&fRM_10_0,&var353,&internal1_m1967_tx};
_S_ovbs  S_ovbs_1978_1 = {&var331,&fRM_2_0,&var354,&internal1_m1978_tx};
_S_ovbs  S_ovbs_1964_1 = {&var337,&fRM_2_0,&var355,&internal1_m1964_tx};
_S_or2  S_or2_1973_1 = {&var387,&var964,&var356};
_S_or2  S_or2_1969_1 = {&var388,&var337,&var357};
_S_or2  S_or2_1981_1 = {&var388,&var331,&var358};
_S_or2  S_or2_1985_1 = {&var387,&var961,&var359};
_S_rs  S_rs_1970_1 = {&var351,&var357,&var360,&vainSBool,&internal1_m1970_q0};
_S_noto  S_noto_1983_1 = {&var362,&var361};
_S_rs  S_rs_1982_1 = {&var350,&var358,&var362,&vainSBool,&internal1_m1982_q0};
_S_noto  S_noto_1971_1 = {&var360,&var363};
_S_noto  S_noto_1979_1 = {&var354,&var364};
_S_noto  S_noto_1965_1 = {&var355,&var365};
_S_and2  S_and2_1958_1 = {&var368,&var470,&var366};
_S_and2  S_and2_1947_1 = {&var368,&var467,&var367};
_S_noto  S_noto_1941_1 = {&var369,&var368};
_S_ovbs  S_ovbs_1940_1 = {&var140,&fRM_3_0,&var369,&internal1_m1940_tx};
_S_or2  S_or2_1462_1 = {&var1134,&lRM_0_,&var370};
_S_and2  S_and2_433_1 = {&var1607,&var1549,&var371};
_S_and2  S_and2_1826_1 = {&var1159,&B7AS31LDU,&var372};
_S_and2  S_and2_444_1 = {&var910,&var756,&var373};
_S_and2  S_and2_436_1 = {&var757,&var910,&var374};
_S_and2  S_and2_473_1 = {&var756,&var911,&var375};
_S_and2  S_and2_469_1 = {&var757,&var911,&var376};
_S_or2  S_or2_360_1 = {&var1620,&var882,&var377};
_S_or2  S_or2_356_1 = {&var1620,&var881,&var378};
_S_ovbs  S_ovbs_51_1 = {&var1632,&fRM_15_0,&var379,&internal1_m51_tx};
_S_ovbs  S_ovbs_337_1 = {&var1107,&fRM_0_02,&var380,&internal1_m337_tx};
_S_ovbs  S_ovbs_292_1 = {&var1109,&fRM_0_02,&var381,&internal1_m292_tx};
_S_ovbs  S_ovbs_741_1 = {&var305,&fRM_0_2,&var382,&internal1_m741_tx};
_S_ovbs  S_ovbs_1406_1 = {&R0MD31LP1,&fRM_10_0,&var383,&internal1_m1406_tx};
_S_ovbs  S_ovbs_113_1 = {&R0MD31LP1,&fRM_0_15,&var384,&internal1_m113_tx};
_S_ovbs  S_ovbs_115_1 = {&var330,&fRM_0_02,&var385,&internal1_m115_tx};
_S_ovbs  S_ovbs_120_1 = {&R0MD32LP1,&fRM_0_02,&var386,&internal1_m120_tx};
_S_ovbs  S_ovbs_21_1 = {&var1185,&fRM_3_0,&var387,&internal1_m21_tx};
_S_ovbs  S_ovbs_13_1 = {&var959,&fRM_3_0,&var388,&internal1_m13_tx};
_S_ovbs  S_ovbs_1949_1 = {&var140,&fRM_2_0,&var389,&internal1_m1949_tx};
_S_ovbs  S_ovbs_1937_1 = {&var140,&fRM_2_0,&var390,&internal1_m1937_tx};
_S_ovbs  S_ovbs_2045_1 = {&var1194,&fRM_2_0,&var391,&internal1_m2045_tx};
_S_ovbs  S_ovbs_2049_1 = {&var102,&fRM_2_0,&var392,&internal1_m2049_tx};
_S_ovbs  S_ovbs_1862_1 = {&var405,&fRM_0_01,&var393,&internal1_m1862_tx};
_S_ovbs  S_ovbs_77_1 = {&R0MW13LP2,&fRM_10_0,&var394,&internal1_m77_tx};
_S_zpfs  S_zpfs_306_1 = {&var813,&fRM_10_0,&var395,&internal1_m306_tx,&internal1_m306_y0};
_S_or2  S_or2_1022_1 = {&var1020,&var583,&var396};
_S_or2  S_or2_234_1 = {&A1VN71LZ1,&A1VN71LZ2,&var397};
_S_or2  S_or2_249_1 = {&var708,&var976,&var398};
_S_or5  S_or5_148_1 = {&B1IS21LDU,&B3IS21LDU,&B2IS21LDU,&var946,&var947,&var399};
_S_and2  S_and2_1019_1 = {&var1457,&var1091,&var400};
_S_or3  S_or3_977_1 = {&var144,&var668,&var667,&var401};
_S_or3  S_or3_1374_1 = {&var651,&var650,&var145,&var402};
_S_and2  S_and2_958_1 = {&var1222,&var1005,&var403};
_S_and3  S_and3_1857_1 = {&var421,&var406,&var414,&var404};
_S_or2  S_or2_1861_1 = {&var408,&var407,&var405};
_S_or3  S_or3_1859_1 = {&var408,&var407,&var417,&var406};
_S_zpfs  S_zpfs_1856_1 = {&var410,&fEM_R0UL02RDU,&var407,&internal1_m1856_tx,&internal1_m1856_y0};
_S_zpfs  S_zpfs_1854_1 = {&var411,&fEM_R0UL02RDU,&var408,&internal1_m1854_tx,&internal1_m1854_y0};
_S_or2  S_or2_1848_1 = {&var411,&var410,&var409};
_S_or2  S_or2_1849_1 = {&var412,&var1124,&var410};
_S_or2  S_or2_1847_1 = {&var413,&var1124,&var411};
_S_and3  S_and3_1841_1 = {&var1181,&var933,&var911,&var412};
_S_and3  S_and3_1840_1 = {&var1182,&var910,&var933,&var413};
_S_or2  S_or2_1838_1 = {&var1124,&var1123,&var414};
_S_or3  S_or3_1845_1 = {&var419,&var1123,&var417,&var415};
_S_and2  S_and2_1853_1 = {&var1124,&var406,&var416};
_S_and2  S_and2_1844_1 = {&var1115,&var418,&var417};
_S_zpfs  S_zpfs_1843_1 = {&var1124,&fEM_R0UL04RDU,&var418,&internal1_m1843_tx,&internal1_m1843_y0};
_S_and2  S_and2_1831_1 = {&var1118,&var567,&var419};
_S_or3  S_or3_1832_1 = {&var1072,&var573,&var1050,&var420};
_S_abs_subf  S_abs_subf_1865_1 = {&fEM_R0UL02RDU,&var422,&fEM_R0UL16RDU,&vainSFloat,&var421};
_S_rsfn  S_rsfn_1863_1 = {&var564,&var423,&var422,&internal1_m1863_q0};
_S_lk  S_lk_1860_1 = {&var1277,&var406,&var423};
_S_abs_subf  S_abs_subf_1435_1 = {&fEM_R0UL05RDU,&var425,&fEM_R0UL18RDU,&vainSFloat,&var424};
_S_rsfn  S_rsfn_1426_1 = {&var564,&var426,&var425,&internal1_m1426_q0};
_S_lk  S_lk_1430_1 = {&var1129,&var551,&var426};
_S_abs_subf  S_abs_subf_1477_1 = {&fEM_R0UL07RDU,&var428,&fEM_R0UL20RDU,&vainSFloat,&var427};
_S_rsfn  S_rsfn_1464_1 = {&var564,&var429,&var428,&internal1_m1464_q0};
_S_lk  S_lk_1468_1 = {&var1135,&var541,&var429};
_S_ma  S_ma_1447_1 = {array_m1447_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_abs_subf  S_abs_subf_1482_1 = {&fEM_R0UL25RDU,&var431,&fEM_R0UL19RDU,&vainSFloat,&var430};
_S_rsfn  S_rsfn_1467_1 = {&var564,&var432,&var431,&internal1_m1467_q0};
_S_lk  S_lk_1471_1 = {&var1275,&var532,&var432};
_S_and3  S_and3_1907_1 = {&var434,&var437,&var444,&var433};
_S_abs_subf  S_abs_subf_1904_1 = {&var435,&fEM_R0UL03RDU,&fEM_R0UL17RDU,&vainSFloat,&var434};
_S_rsfn  S_rsfn_1902_1 = {&var564,&var436,&var435,&internal1_m1902_q0};
_S_lk  S_lk_1898_1 = {&var1276,&var437,&var436};
_S_or3  S_or3_1897_1 = {&var442,&var448,&var447,&var437};
_S_and4  S_and4_1901_1 = {&var447,&var1282,&var460,&var458,&var438};
_S_and4  S_and4_1899_1 = {&var448,&var1282,&var460,&var458,&var439};
_S_and2  S_and2_1891_1 = {&var1127,&var437,&var440};
_S_and2  S_and2_1877_1 = {&var567,&var1117,&var441};
_S_and2  S_and2_1880_1 = {&var445,&var1116,&var442};
_S_or3  S_or3_1881_1 = {&var442,&var441,&var1126,&var443};
_S_or2  S_or2_1873_1 = {&var1127,&var1126,&var444};
_S_zpfs  S_zpfs_1879_1 = {&var1127,&fEM_R0UL21RDU,&var445,&internal1_m1879_tx,&internal1_m1879_y0};
_S_or3  S_or3_1870_1 = {&var569,&var1076,&var1054,&var446};
_S_zpfs  S_zpfs_1895_1 = {&var450,&fEM_R0UL03RDU,&var447,&internal1_m1895_tx,&internal1_m1895_y0};
_S_zpfs  S_zpfs_1892_1 = {&var451,&fEM_R0UL03RDU,&var448,&internal1_m1892_tx,&internal1_m1892_y0};
_S_or2  S_or2_1887_1 = {&var451,&var450,&var449};
_S_or2  S_or2_1888_1 = {&var452,&var1127,&var450};
_S_or2  S_or2_1886_1 = {&var453,&var1127,&var451};
_S_and4  S_and4_1885_1 = {&var1183,&var911,&B2IS12LDU,&var454,&var452};
_S_and4  S_and4_1884_1 = {&var1184,&A2IS12LDU,&var910,&var454,&var453};
_S_and2  S_and2_1878_1 = {&var933,&var458,&var454};
_S_and3  S_and3_1916_1 = {&var911,&var1038,&var457,&var455};
_S_and3  S_and3_1915_1 = {&var910,&var1039,&var457,&var456};
_S_and4  S_and4_1914_1 = {&var1004,&var803,&var805,&var458,&var457};
_S_and2  S_and2_1908_1 = {&var816,&var1005,&var458};
_S_or2  S_or2_1910_1 = {&var1286,&var1003,&var459};
_S_or3  S_or3_1919_1 = {&var463,&var462,&var465,&var460};
_S_and2  S_and2_1909_1 = {&var1042,&A2IS12LDU,&var461};
_S_and2  S_and2_1913_1 = {&var943,&var461,&var462};
_S_and3  S_and3_1918_1 = {&var1281,&var466,&var461,&var463};
_S_or2  S_or2_1927_1 = {&lRM_0_,&var459,&var464};
_S_and2  S_and2_1924_1 = {&var958,&var466,&var465};
_S_and2  S_and2_1926_1 = {&var1041,&B2IS12LDU,&var466};
_S_or2  S_or2_1946_1 = {&var963,&var387,&var467};
_S_or2  S_or2_1942_1 = {&var388,&var140,&var468};
_S_or2  S_or2_1953_1 = {&var140,&var388,&var469};
_S_or2  S_or2_1957_1 = {&var387,&var962,&var470};
_S_or2  S_or2_2020_1 = {&var811,&var1195,&var471};
_S_or2  S_or2_2028_1 = {&var1005,&var1216,&var472};
_S_zpfs  S_zpfs_2026_1 = {&var71,&fRM_15_0,&var473,&internal1_m2026_tx,&internal1_m2026_y0};
_S_or2  S_or2_2032_1 = {&var810,&var103,&var474};
_S_zpfs  S_zpfs_2039_1 = {&var69,&fRM_15_0,&var475,&internal1_m2039_tx,&internal1_m2039_y0};
_S_or2  S_or2_2042_1 = {&var1005,&var1215,&var476};
_S_or2  S_or2_2058_1 = {&var75,&var438,&var477};
_S_or2  S_or2_2053_1 = {&var439,&var79,&var478};
_S_and2  S_and2_2064_1 = {&var1185,&var391,&var479};
_S_and2  S_and2_1825_1 = {&var1160,&A7AS31LDU,&var480};
_S_or3  S_or3_1798_1 = {&var485,&var489,&var487,&var481};
_S_or3  S_or3_1799_1 = {&var488,&var487,&var484,&var482};
_S_or2  S_or2_1812_1 = {&B0VT71LZ1,&B0VT71LZ2,&var483};
_S_and2  S_and2_1803_1 = {&var490,&var483,&var484};
_S_and2  S_and2_1797_1 = {&var490,&var486,&var485};
_S_or2  S_or2_1796_1 = {&A0VT71LZ1,&A0VT71LZ2,&var486};
_S_zpfs  S_zpfs_1793_1 = {&var1177,&fRM_2_5,&var487,&internal1_m1793_tx,&internal1_m1793_y0};
_S_zpfs  S_zpfs_1792_1 = {&var1178,&fRM_2_5,&var488,&internal1_m1792_tx,&internal1_m1792_y0};
_S_zpfs  S_zpfs_1791_1 = {&var1179,&fRM_2_5,&var489,&internal1_m1791_tx,&internal1_m1791_y0};
_S_zpfs  S_zpfs_1790_1 = {&var1180,&fRM_2_5,&var490,&internal1_m1790_tx,&internal1_m1790_y0};
_S_or2  S_or2_1821_1 = {&R0VP73LZ2,&R0VP73LZ1,&var491};
_S_and2  S_and2_1816_1 = {&var102,&var1161,&var492};
_S_or2  S_or2_1811_1 = {&var495,&var492,&var493};
_S_or2  S_or2_1813_1 = {&var75,&var102,&var494};
_S_and2  S_and2_1810_1 = {&var75,&var1151,&var495};
_S_and2  S_and2_1794_1 = {&var1194,&var1162,&var496};
_S_or2  S_or2_1795_1 = {&var499,&var496,&var497};
_S_or2  S_or2_1788_1 = {&var79,&var1194,&var498};
_S_and2  S_and2_1787_1 = {&var79,&var1152,&var499};
_S_or3  S_or3_1757_1 = {&var1245,&var1203,&var1204,&var500};
_S_or3  S_or3_1758_1 = {&var1243,&var1203,&var1204,&var501};
_S_or2  S_or2_1749_1 = {&var1238,&var1203,&var502};
_S_or2  S_or2_1750_1 = {&var1237,&var1203,&var503};
_S_or2  S_or2_1756_1 = {&var1247,&var1206,&var504};
_S_or4  S_or4_1754_1 = {&var1206,&var1244,&var1207,&var1208,&var505};
_S_or4  S_or4_1753_1 = {&var1206,&var1250,&var1207,&var1208,&var506};
_S_or2  S_or2_1747_1 = {&var1239,&var1208,&var507};
_S_or2  S_or2_1746_1 = {&var1240,&var1208,&var508};
_S_or2  S_or2_1755_1 = {&var1206,&var1246,&var509};
_S_or2  S_or2_1724_1 = {&var255,&var301,&var510};
_S_and2  S_and2_1555_1 = {&var1500,&var1458,&var511};
_S_and2  S_and2_1554_1 = {&var1623,&var1458,&var512};
_S_and2  S_and2_1553_1 = {&var900,&var1458,&var513};
_S_or2  S_or2_1552_1 = {&B4IS11LDU,&A4IS11LDU,&var514};
_S_and2  S_and2_1551_1 = {&var514,&var1458,&var515};
_S_and2  S_and2_1545_1 = {&var1666,&var1458,&var516};
_S_and2  S_and2_1544_1 = {&var153,&var1458,&var517};
_S_and2  S_and2_1543_1 = {&var889,&var1458,&var518};
_S_and2  S_and2_1542_1 = {&R3IS21LDU,&var1458,&var519};
_S_or2  S_or2_1602_1 = {&var1636,&var1637,&var520};
_S_or2  S_or2_1601_1 = {&var1638,&var1636,&var521};
_S_or2  S_or2_2078_1 = {&var982,&R0MD34LP1,&var522};
_S_or3  S_or3_2084_1 = {&var1257,&var1259,&var1258,&var523};
_S_or3  S_or3_2075_1 = {&var1263,&var1265,&var1264,&var524};
_S_or2  S_or2_1590_1 = {&var1724,&var1458,&var525};
_S_or2  S_or2_1564_1 = {&var1501,&var1091,&var526};
_S_or5  S_or5_1116_1 = {&var1516,&var528,&var1527,&var1513,&var1514,&var527};
_S_or3  S_or3_1120_1 = {&var1521,&var1522,&var985,&var528};
_S_or5  S_or5_1578_1 = {&var307,&var530,&var1510,&var1502,&var1503,&var529};
_S_or3  S_or3_1581_1 = {&var984,&var1504,&var1505,&var530};
_S_and3  S_and3_1491_1 = {&var532,&var537,&var430,&var531};
_S_and2  S_and2_1494_1 = {&var533,&var1274,&var532};
_S_or3  S_or3_1493_1 = {&A3VZ13LZ2,&A3VZ13LZ1,&var536,&var533};
_S_zpfs  S_zpfs_1478_1 = {&var1274,&fRM_0_2,&var534,&internal1_m1478_tx,&internal1_m1478_y0};
_S_or3  S_or3_1480_1 = {&var1137,&var536,&var538,&var535};
_S_and2  S_and2_1479_1 = {&var1114,&var534,&var536};
_S_or2  S_or2_1469_1 = {&var1274,&var1137,&var537};
_S_and2  S_and2_1457_1 = {&var1119,&var567,&var538};
_S_or3  S_or3_1465_1 = {&var1051,&var1073,&var572,&var539};
_S_or3  S_or3_1487_1 = {&R0AD14LZ1,&R0AD14LZ2,&var543,&var540};
_S_and2  S_and2_1488_1 = {&var540,&var1134,&var541};
_S_zpfs  S_zpfs_1472_1 = {&var1134,&fEM_R0UL06RDU,&var542,&internal1_m1472_tx,&internal1_m1472_y0};
_S_and2  S_and2_1473_1 = {&var542,&var1113,&var543};
_S_or3  S_or3_1474_1 = {&var1132,&var543,&var546,&var544};
_S_or3  S_or3_1449_1 = {&var571,&var1074,&var1052,&var545};
_S_and2  S_and2_1452_1 = {&var1120,&var567,&var546};
_S_and3  S_and3_1490_1 = {&var427,&var541,&var554,&var547};
_S_zpfs  S_zpfs_1422_1 = {&var1131,&fEM_R0UL04RDU,&var548,&internal1_m1422_tx,&internal1_m1422_y0};
_S_and2  S_and2_1423_1 = {&var548,&var1112,&var549};
_S_and3  S_and3_1439_1 = {&var424,&var551,&var555,&var550};
_S_and2  S_and2_1433_1 = {&var552,&var1131,&var551};
_S_or3  S_or3_1432_1 = {&A3VZ15LZ1,&A3VZ15LZ2,&var549,&var552};
_S_or3  S_or3_1424_1 = {&var556,&var549,&var1130,&var553};
_S_or2  S_or2_1460_1 = {&var1134,&var1132,&var554};
_S_or2  S_or2_1420_1 = {&var1131,&var1130,&var555};
_S_and2  S_and2_1412_1 = {&var1121,&var567,&var556};
_S_or3  S_or3_1410_1 = {&var1053,&var1075,&var570,&var557};
_S_or2  S_or2_1384_1 = {&var1629,&var559,&var558};
_S_and2  S_and2_1383_1 = {&var560,&var1175,&var559};
_S_or2  S_or2_1382_1 = {&var956,&var908,&var560};
_S_or2  S_or2_1379_1 = {&var1046,&var1068,&var561};
_S_and2  S_and2_1377_1 = {&var1140,&var1141,&var562};
_S_and2  S_and2_1380_1 = {&var561,&var560,&var563};
_S_or5  S_or5_1381_1 = {&var381,&var380,&var562,&var563,&R0MD34LP1,&var564};
_S_orni  S_orni_1401_1 = {array_m1401_x_1,&iRM_5_,&var565,&var566};
_S_or5  S_or5_1403_1 = {&var1136,&var1111,&var564,&var1056,&var383,&var567};
_S_and2  S_and2_1402_1 = {&var565,&var1269,&var568};
_S_or2  S_or2_1409_1 = {&var1083,&var574,&var569};
_S_or2  S_or2_1405_1 = {&var1082,&var575,&var570};
_S_or2  S_or2_1399_1 = {&var1081,&var576,&var571};
_S_or2  S_or2_1397_1 = {&var1080,&var577,&var572};
_S_or2  S_or2_1395_1 = {&var1079,&var578,&var573};
_S_and2  S_and2_1408_1 = {&var1624,&var579,&var574};
_S_and2  S_and2_1404_1 = {&var1625,&var579,&var575};
_S_and2  S_and2_1398_1 = {&var1626,&var579,&var576};
_S_and2  S_and2_1396_1 = {&var1627,&var579,&var577};
_S_and2  S_and2_1394_1 = {&var1628,&var579,&var578};
_S_and2  S_and2_1388_1 = {&var1629,&var62,&var579};
_S_and3  S_and3_1052_1 = {&var249,&var584,&var602,&var580};
_S_or2  S_or2_1016_1 = {&var1093,&var1089,&var581};
_S_or2  S_or2_1043_1 = {&var1089,&var1023,&var582};
_S_and2  S_and2_1010_1 = {&var1467,&var1090,&var583};
_S_and2  S_and2_1006_1 = {&var1286,&var604,&var584};
_S_or3  S_or3_1013_1 = {&var1089,&var1019,&var1092,&var585};
_S_and2  S_and2_1017_1 = {&var246,&var1286,&var586};
_S_and2  S_and2_1035_1 = {&var257,&var1286,&var587};
_S_and2  S_and2_1051_1 = {&var251,&var1286,&var588};
_S_and2  S_and2_1058_1 = {&var254,&var1286,&var589};
_S_and3  S_and3_1001_1 = {&var592,&var1008,&var1286,&var590};
_S_and3  S_and3_995_1 = {&var593,&var1008,&var1286,&var591};
_S_and2  S_and2_1003_1 = {&var910,&var1285,&var592};
_S_and2  S_and2_993_1 = {&var911,&var1285,&var593};
_S_and4  S_and4_1002_1 = {&var592,&var1286,&var1016,&var1006,&var594};
_S_and4  S_and4_996_1 = {&var593,&var1286,&var1016,&var1006,&var595};
_S_and4  S_and4_1000_1 = {&var1286,&var592,&var600,&var1007,&var596};
_S_and4  S_and4_994_1 = {&var1286,&var593,&var600,&var1007,&var597};
_S_and2  S_and2_987_1 = {&var1017,&var1286,&var598};
_S_or4  S_or4_990_1 = {&R0MD31LP1,&var1520,&var262,&var611,&var599};
_S_and3  S_and3_1036_1 = {&var1018,&var1017,&var1016,&var600};
_S_and2  S_and2_1023_1 = {&var602,&var396,&var601};
_S_and2  S_and2_1026_1 = {&var1015,&var600,&var602};
_S_or2  S_or2_1037_1 = {&var1085,&var1027,&var603};
_S_and2  S_and2_1045_1 = {&var605,&var603,&var604};
_S_or2  S_or2_1038_1 = {&var1026,&var1028,&var605};
_S_or2  S_or2_1039_1 = {&var1025,&var1026,&var606};
_S_or2  S_or2_1041_1 = {&var1024,&var1029,&var607};
_S_and2  S_and2_1042_1 = {&var606,&var607,&var608};
_S_or2  S_or2_1029_1 = {&var1085,&var1084,&var609};
_S_and2  S_and2_1030_1 = {&var609,&var1021,&var610};
_S_and5  S_and5_983_1 = {&var612,&var1105,&var1026,&var1085,&var601,&var611};
_S_and2  S_and2_984_1 = {&var1060,&var1061,&var612};
_S_and2  S_and2_1231_1 = {&var1154,&var614,&var613};
_S_or2  S_or2_1225_1 = {&A2MD12LP1,&var615,&var614};
_S_and2  S_and2_1213_1 = {&A2MD11LP1,&var1171,&var615};
_S_or2  S_or2_1207_1 = {&var618,&B2MD12LP1,&var616};
_S_and2  S_and2_1209_1 = {&var616,&var1154,&var617};
_S_and2  S_and2_1201_1 = {&B2MD11LP1,&var1172,&var618};
_S_or3  S_or3_1189_1 = {&var1236,&var1231,&var774,&var619};
_S_or5  S_or5_1205_1 = {&var622,&var994,&var1497,&var1491,&var1492,&var620};
_S_or2  S_or2_1224_1 = {&var1736,&var1482,&var621};
_S_or3  S_or3_1276_1 = {&var1463,&var623,&var624,&var622};
_S_and2  S_and2_1271_1 = {&var1482,&var957,&var623};
_S_and2  S_and2_1270_1 = {&var907,&var1482,&var624};
_S_and3  S_and3_1269_1 = {&var399,&var943,&var639,&var625};
_S_and2  S_and2_1268_1 = {&var153,&var639,&var626};
_S_and3  S_and3_1264_1 = {&var932,&var978,&var639,&var627};
_S_and2  S_and2_1263_1 = {&var491,&var639,&var628};
_S_and2  S_and2_1251_1 = {&var1473,&var639,&var629};
_S_and2  S_and2_1238_1 = {&var1666,&var639,&var630};
_S_and2  S_and2_1253_1 = {&var60,&var639,&var631};
_S_and2  S_and2_1239_1 = {&R3IS21LDU,&var639,&var632};
_S_and2  S_and2_1254_1 = {&var635,&var639,&var633};
_S_and3  S_and3_1240_1 = {&var636,&var1472,&var639,&var634};
_S_or2  S_or2_1255_1 = {&var1465,&var1466,&var635};
_S_or2  S_or2_1243_1 = {&A4IS11LDU,&B4IS11LDU,&var636};
_S_and3  S_and3_1250_1 = {&var1206,&var263,&var959,&var637};
_S_and3  S_and3_1249_1 = {&var1208,&var263,&var959,&var638};
_S_or3  S_or3_1242_1 = {&var1483,&var638,&var637,&var639};
_S_and2  S_and2_1328_1 = {&var641,&var1154,&var640};
_S_or2  S_or2_1324_1 = {&var642,&B3MD12LP1,&var641};
_S_and2  S_and2_1313_1 = {&B3MD11LP1,&var1150,&var642};
_S_or2  S_or2_1316_1 = {&var1727,&var1300,&var643};
_S_or5  S_or5_1302_1 = {&var402,&var1310,&var1309,&var174,&var992,&var644};
_S_and2  S_and2_1362_1 = {&var1300,&var957,&var645};
_S_and2  S_and2_1361_1 = {&var1300,&var907,&var646};
_S_and2  S_and2_1370_1 = {&var973,&var1288,&var647};
_S_or2  S_or2_1365_1 = {&var647,&var974,&var648};
_S_and3  S_and3_1360_1 = {&var1163,&var648,&var657,&var649};
_S_and3  S_and3_1359_1 = {&var399,&var958,&var657,&var650};
_S_and2  S_and2_1358_1 = {&var153,&var657,&var651};
_S_and2  S_and2_1355_1 = {&var1220,&var1005,&var652};
_S_or2  S_or2_1345_1 = {&var1291,&var1290,&var653};
_S_and2  S_and2_1344_1 = {&var653,&var657,&var654};
_S_and2  S_and2_1343_1 = {&var60,&var657,&var655};
_S_and2  S_and2_1341_1 = {&var1293,&var657,&var656};
_S_or2  S_or2_1332_1 = {&var1302,&var83,&var657};
_S_or2  S_or2_1333_1 = {&B4IS11LDU,&A4IS11LDU,&var658};
_S_and3  S_and3_1331_1 = {&var1292,&var658,&var657,&var659};
_S_and2  S_and2_1330_1 = {&R3IS21LDU,&var657,&var660};
_S_and2  S_and2_1329_1 = {&var1666,&var657,&var661};
_S_and2  S_and2_973_1 = {&var971,&var1320,&var662};
_S_and2  S_and2_964_1 = {&var907,&var1332,&var663};
_S_and2  S_and2_965_1 = {&var957,&var1332,&var664};
_S_or2  S_or2_968_1 = {&var972,&var662,&var665};
_S_and3  S_and3_963_1 = {&var1163,&var665,&var672,&var666};
_S_and3  S_and3_962_1 = {&var943,&var399,&var672,&var667};
_S_and2  S_and2_961_1 = {&var153,&var672,&var668};
_S_and2  S_and2_944_1 = {&var1325,&var672,&var669};
_S_or2  S_or2_948_1 = {&var1323,&var1322,&var670};
_S_and2  S_and2_947_1 = {&var670,&var672,&var671};
_S_or2  S_or2_935_1 = {&var1334,&var84,&var672};
_S_or2  S_or2_936_1 = {&B4IS11LDU,&A4IS11LDU,&var673};
_S_and3  S_and3_934_1 = {&var673,&var1324,&var672,&var674};
_S_and2  S_and2_946_1 = {&var60,&var672,&var675};
_S_and2  S_and2_933_1 = {&R3IS21LDU,&var672,&var676};
_S_and2  S_and2_932_1 = {&var1666,&var672,&var677};
_S_or2  S_or2_919_1 = {&var1332,&var1730,&var678};
_S_or5  S_or5_902_1 = {&var401,&var993,&var172,&var1341,&var1342,&var679};
_S_and2  S_and2_931_1 = {&var1154,&var681,&var680};
_S_or2  S_or2_927_1 = {&var682,&A3MD12LP1,&var681};
_S_and2  S_and2_916_1 = {&A3MD11LP1,&var1205,&var682};
_S_or3  S_or3_874_1 = {&var1430,&var685,&var684,&var683};
_S_and2  S_and2_868_1 = {&var1441,&var907,&var684};
_S_and2  S_and2_869_1 = {&var1441,&var957,&var685};
_S_and3  S_and3_867_1 = {&var1464,&var958,&var697,&var686};
_S_and2  S_and2_866_1 = {&var153,&var697,&var687};
_S_and2  S_and2_849_1 = {&var1434,&var697,&var688};
_S_and2  S_and2_851_1 = {&var60,&var697,&var689};
_S_and2  S_and2_852_1 = {&var691,&var697,&var690};
_S_or2  S_or2_853_1 = {&var1432,&var1431,&var691};
_S_and2  S_and2_836_1 = {&var1666,&var697,&var692};
_S_and3  S_and3_838_1 = {&var1433,&var698,&var697,&var693};
_S_and2  S_and2_837_1 = {&R3IS21LDU,&var697,&var694};
_S_and3  S_and3_848_1 = {&var1206,&var263,&var959,&var695};
_S_and3  S_and3_847_1 = {&var263,&var1208,&var959,&var696};
_S_or3  S_or3_840_1 = {&var1442,&var695,&var696,&var697};
_S_or2  S_or2_841_1 = {&B4IS11LDU,&A4IS11LDU,&var698};
_S_or2  S_or2_826_1 = {&var1733,&var1441,&var699};
_S_zpfs  S_zpfs_823_1 = {&var1455,&fRM_3_0,&var700,&internal1_m823_tx,&internal1_m823_y0};
_S_zpfs  S_zpfs_821_1 = {&var1456,&fRM_2_0,&var701,&internal1_m821_tx,&internal1_m821_y0};
_S_zpfs  S_zpfs_828_1 = {&var1453,&fEM_A2UL83RDU,&var702,&internal1_m828_tx,&internal1_m828_y0};
_S_or5  S_or5_816_1 = {&var683,&var702,&var1454,&var701,&var700,&var703};
_S_or3  S_or3_805_1 = {&var1211,&var1234,&var769,&var704};
_S_or4  S_or4_789_1 = {&var1577,&var1575,&var1576,&var1578,&var705};
_S_or2  S_or2_780_1 = {&var707,&var705,&var706};
_S_or4  S_or4_773_1 = {&var1586,&var1585,&var1584,&var1587,&var707};
_S_and2  S_and2_254_1 = {&var975,&var1380,&var708};
_S_and3  S_and3_243_1 = {&var943,&var399,&var1395,&var709};
_S_or3  S_or3_256_1 = {&var713,&var711,&var1383,&var710};
_S_and2  S_and2_246_1 = {&var1394,&var957,&var711};
_S_and3  S_and3_244_1 = {&var398,&var1163,&var1395,&var712};
_S_and2  S_and2_245_1 = {&var907,&var1394,&var713};
_S_and2  S_and2_242_1 = {&var153,&var1395,&var714};
_S_and2  S_and2_217_1 = {&var1387,&var1395,&var715};
_S_and2  S_and2_219_1 = {&var60,&var1395,&var716};
_S_or2  S_or2_221_1 = {&var1384,&var1385,&var717};
_S_and2  S_and2_220_1 = {&var717,&var1395,&var718};
_S_or2  S_or2_210_1 = {&B4IS11LDU,&A4IS11LDU,&var719};
_S_and3  S_and3_209_1 = {&var1386,&var719,&var1395,&var720};
_S_and2  S_and2_207_1 = {&var1666,&var1395,&var721};
_S_and2  S_and2_208_1 = {&R3IS21LDU,&var1395,&var722};
_S_and2  S_and2_185_1 = {&var1154,&var725,&var723};
_S_and2  S_and2_176_1 = {&A1MD11LP1,&var1193,&var724};
_S_or2  S_or2_182_1 = {&A1MD12LP1,&var724,&var725};
_S_or2  S_or2_196_1 = {&var1394,&var1718,&var726};
_S_zpfs  S_zpfs_187_1 = {&var1409,&fRM_2_0,&var727,&internal1_m187_tx,&internal1_m187_y0};
_S_zpfs  S_zpfs_192_1 = {&var1408,&fRM_2_0,&var728,&internal1_m192_tx,&internal1_m192_y0};
_S_zpfs  S_zpfs_198_1 = {&var1406,&fEM_A1UL03RDU,&var729,&internal1_m198_tx,&internal1_m198_y0};
_S_or5  S_or5_180_1 = {&var710,&var729,&var728,&var727,&var1407,&var730};
_S_orn  S_orn_545_1 = {array_m545_x_1,&iRM_14_,&var731};
_S_and2  S_and2_568_1 = {&var1350,&var970,&var732};
_S_or2  S_or2_563_1 = {&var969,&var732,&var733};
_S_and3  S_and3_557_1 = {&var958,&var1464,&var1362,&var734};
_S_and2  S_and2_556_1 = {&var153,&var1362,&var735};
_S_and3  S_and3_558_1 = {&var1163,&var1362,&var733,&var736};
_S_or2  S_or2_538_1 = {&var1352,&var1351,&var737};
_S_and2  S_and2_537_1 = {&var737,&var1362,&var738};
_S_and2  S_and2_536_1 = {&var1362,&var60,&var739};
_S_and3  S_and3_526_1 = {&var1353,&var741,&var1362,&var740};
_S_or2  S_or2_527_1 = {&B4IS11LDU,&A4IS11LDU,&var741};
_S_and2  S_and2_534_1 = {&var1362,&var1354,&var742};
_S_or2  S_or2_504_1 = {&B1MD12LP1,&var745,&var743};
_S_and2  S_and2_508_1 = {&var1154,&var743,&var744};
_S_and2  S_and2_498_1 = {&B1MD11LP1,&var1173,&var745};
_S_and2  S_and2_525_1 = {&var1362,&R3IS21LDU,&var746};
_S_and2  S_and2_524_1 = {&var1362,&var1666,&var747};
_S_or2  S_or2_515_1 = {&var1361,&var1740,&var748};
_S_zpfs  S_zpfs_517_1 = {&var1375,&fEM_A1UL03RDU,&var749,&internal1_m517_tx,&internal1_m517_y0};
_S_or5  S_or5_500_1 = {&var903,&var749,&var1376,&var1370,&var1371,&var750};
_S_or2  S_or2_488_1 = {&var1189,&var770,&var751};
_S_or3  S_or3_478_1 = {&var591,&var1188,&var1000,&var752};
_S_or4  S_or4_468_1 = {&var1414,&var1412,&var1414,&var1413,&var753};
_S_or4  S_or4_450_1 = {&var1423,&var1421,&var1422,&var1424,&var754};
_S_or2  S_or2_457_1 = {&var754,&var753,&var755};
_S_and3  S_and3_441_1 = {&var758,&var1154,&R0MD33LP1,&var756};
_S_and3  S_and3_442_1 = {&var1154,&var759,&R0MD33LP1,&var757};
_S_or3  S_or3_434_1 = {&var293,&var1009,&var996,&var758};
_S_or2  S_or2_435_1 = {&var1410,&var1187,&var759};
_S_or2  S_or2_743_1 = {&var1545,&var1546,&var760};
_S_and2  S_and2_327_1 = {&var1045,&var1107,&var761};
_S_or2  S_or2_346_1 = {&B4IS21LDU,&A4IS21LDU,&var762};
_S_or2  S_or2_341_1 = {&A2IS21LDU,&B2IS21LDU,&var763};
_S_or2  S_or2_336_1 = {&var766,&var1049,&var764};
_S_and3  S_and3_334_1 = {&var1108,&var1103,&var1104,&var765};
_S_or4  S_or4_332_1 = {&var1034,&var203,&R0MD31LP1,&var1044,&var766};
_S_and4  S_and4_328_1 = {&var956,&var824,&var262,&var914,&var767};
_S_or2  S_or2_323_1 = {&R0MD34LP1,&var1044,&var768};
_S_and3  S_and3_597_1 = {&var791,&var1287,&B2IS12LDU,&var769};
_S_and2  S_and2_596_1 = {&var791,&var1319,&var770};
_S_and2  S_and2_595_1 = {&var791,&var1382,&var771};
_S_or2  S_or2_639_1 = {&A2IS12LDU,&B2IS12LDU,&var772};
_S_or2  S_or2_616_1 = {&var1517,&var1143,&var773};
_S_and3  S_and3_607_1 = {&A2IS12LDU,&var1287,&var792,&var774};
_S_and2  S_and2_638_1 = {&var776,&var1287,&var775};
_S_or2  S_or2_640_1 = {&var1086,&var246,&var776};
_S_or2  S_or2_621_1 = {&var1517,&var1142,&var777};
_S_or2  S_or2_619_1 = {&var779,&var1517,&var778};
_S_and2  S_and2_631_1 = {&var1319,&var257,&var779};
_S_and2  S_and2_606_1 = {&var792,&var1319,&var780};
_S_and2  S_and2_605_1 = {&var792,&var1382,&var781};
_S_and2  S_and2_630_1 = {&var251,&var1382,&var782};
_S_and2  S_and2_646_1 = {&var254,&var1410,&var783};
_S_or2  S_or2_642_1 = {&var1517,&var1144,&var784};
_S_or2  S_or2_637_1 = {&var786,&var783,&var785};
_S_and2  S_and2_629_1 = {&var794,&var1379,&var786};
_S_and2  S_and2_635_1 = {&var794,&R0MD33LP1,&var787};
_S_or2  S_or2_585_1 = {&var967,&var968,&var788};
_S_and4  S_and4_604_1 = {&var967,&var792,&var1479,&A2IS12LDU,&var789};
_S_and4  S_and4_594_1 = {&var791,&var968,&var1479,&B2IS12LDU,&var790};
_S_and2  S_and2_593_1 = {&var911,&var1477,&var791};
_S_and2  S_and2_603_1 = {&var910,&var1477,&var792};
_S_or2  S_or2_634_1 = {&var1087,&var246,&var793};
_S_and2  S_and2_627_1 = {&var793,&var1479,&var794};
_S_or2  S_or2_614_1 = {&var1517,&var1145,&var795};
_S_or2  S_or2_626_1 = {&var1457,&var1100,&var796};
_S_and2  S_and2_625_1 = {&var796,&var1501,&var797};
_S_or2  S_or2_611_1 = {&var1517,&var1146,&var798};
_S_and2  S_and2_624_1 = {&var1518,&var1467,&var799};
_S_or2  S_or2_609_1 = {&var1517,&var1147,&var800};
_S_and2  S_and2_622_1 = {&var249,&var1520,&var801};
_S_or2  S_or2_601_1 = {&var1155,&var1517,&var802};
_S_and2  S_and2_302_1 = {&var1217,&var805,&var803};
_S_and2  S_and2_290_1 = {&var805,&var1032,&var804};
_S_or2  S_or2_285_1 = {&var1046,&var1068,&var805};
_S_and3  S_and3_281_1 = {&var1283,&var1103,&var1104,&var806};
_S_and3  S_and3_296_1 = {&var763,&var1033,&var808,&var807};
_S_or2  S_or2_286_1 = {&var1283,&var1108,&var808};
_S_and2  S_and2_295_1 = {&var762,&var808,&var809};
_S_and2  S_and2_315_1 = {&var814,&var911,&var810};
_S_and2  S_and2_316_1 = {&var910,&var814,&var811};
_S_and2  S_and2_321_1 = {&var1005,&var803,&var812};
_S_and2  S_and2_309_1 = {&var814,&var1005,&var813};
_S_and2  S_and2_314_1 = {&var1185,&var815,&var814};
_S_or2  S_or2_310_1 = {&var816,&var761,&var815};
_S_or2  S_or2_311_1 = {&var817,&var761,&var816};
_S_and4  S_and4_312_1 = {&var1109,&var1057,&var1058,&var908,&var817};
_S_or2  S_or2_298_1 = {&var1109,&var1107,&var818};
_S_and2  S_and2_283_1 = {&var1071,&var1040,&var819};
_S_or2  S_or2_289_1 = {&var822,&var819,&var820};
_S_or2  S_or2_263_1 = {&R0MD34LP1,&var1043,&var821};
_S_or4  S_or4_280_1 = {&var1034,&R0MD31LP1,&var203,&var1043,&var822};
_S_and3  S_and3_273_1 = {&var824,&var913,&var262,&var823};
_S_or2  S_or2_272_1 = {&var1062,&var1248,&var824};
_S_and3  S_and3_274_1 = {&var1063,&var1065,&var1064,&var825};
_S_or2  S_or2_265_1 = {&var827,&var825,&var826};
_S_and3  S_and3_259_1 = {&R0MD33LP1,&var1067,&var1066,&var827};
_S_or2  S_or2_1088_1 = {&B4IS11LDU,&A4IS11LDU,&var828};
_S_and2  S_and2_1091_1 = {&var1468,&var1515,&var829};
_S_and2  S_and2_1090_1 = {&var1468,&var1623,&var830};
_S_and2  S_and2_1089_1 = {&var1468,&var900,&var831};
_S_and2  S_and2_1087_1 = {&var1468,&var828,&var832};
_S_and2  S_and2_1081_1 = {&var1468,&var153,&var833};
_S_and2  S_and2_1080_1 = {&var889,&var1468,&var834};
_S_and2  S_and2_1079_1 = {&var1468,&R3IS21LDU,&var835};
_S_and2  S_and2_1082_1 = {&var1468,&var1666,&var836};
_S_and2  S_and2_1074_1 = {&var246,&var1002,&var837};
_S_and2  S_and2_1075_1 = {&var257,&var1000,&var838};
_S_and2  S_and2_1076_1 = {&var251,&var998,&var839};
_S_and2  S_and2_1077_1 = {&var254,&var996,&var840};
_S_or2  S_or2_1059_1 = {&R0MD31LP1,&var842,&var841};
_S_and4  S_and4_1060_1 = {&var158,&var157,&var156,&var155,&var842};
_S_or2  S_or2_1130_1 = {&var1468,&var1721,&var843};
_S_or2  S_or2_1106_1 = {&var1518,&var1090,&var844};
_S_or2  S_or2_1171_1 = {&var1559,&var1558,&var845};
_S_or2  S_or2_1157_1 = {&var1568,&var1567,&var846};
_S_or2  S_or2_1167_1 = {&var983,&R0MD34LP1,&var847};
_S_or2  S_or2_1144_1 = {&var845,&var1623,&var848};
_S_or2  S_or2_1142_1 = {&var850,&var848,&var849};
_S_or2  S_or2_1143_1 = {&var846,&var1623,&var850};
_S_or4  S_or4_358_1 = {&var1595,&var1594,&var1596,&var1593,&var851};
_S_or2  S_or2_659_1 = {&B5IS11LDU,&A5IS11LDU,&var852};
_S_and2  S_and2_658_1 = {&var857,&var852,&var853};
_S_or2  S_or2_657_1 = {&B6IS11LDU,&A6IS11LDU,&var854};
_S_and2  S_and2_656_1 = {&var857,&var854,&var855};
_S_or2  S_or2_655_1 = {&A4IS11LDU,&B4IS11LDU,&var856};
_S_or2  S_or2_648_1 = {&var859,&var860,&var857};
_S_and2  S_and2_654_1 = {&var857,&var856,&var858};
_S_and2  S_and2_651_1 = {&var153,&var870,&var859};
_S_and2  S_and2_647_1 = {&var154,&var863,&var860};
_S_and2  S_and2_763_1 = {&var1621,&var1539,&var861};
_S_and2  S_and2_759_1 = {&var1621,&var1540,&var862};
_S_and3  S_and3_754_1 = {&var1621,&var154,&var1546,&var863};
_S_or2  S_or2_762_1 = {&var1541,&var1535,&var864};
_S_or2  S_or2_757_1 = {&var1539,&var1541,&var865};
_S_or2  S_or2_753_1 = {&var1541,&var1540,&var866};
_S_and2  S_and2_735_1 = {&var1535,&var1621,&var867};
_S_or2  S_or2_726_1 = {&var1542,&var1543,&var868};
_S_or2  S_or2_721_1 = {&var1600,&var1542,&var869};
_S_and2  S_and2_719_1 = {&var1543,&var1622,&var870};
_S_and2  S_and2_718_1 = {&var1600,&var1622,&var871};
_S_and2  S_and2_747_1 = {&var249,&var1621,&var872};
_S_and2  S_and2_728_1 = {&var249,&var1552,&var873};
_S_and2  S_and2_745_1 = {&var1622,&var249,&var874};
_S_or2  S_or2_739_1 = {&var1622,&var1621,&var875};
_S_or3  S_or3_732_1 = {&var64,&var878,&var879,&var876};
_S_or4  S_or4_731_1 = {&var878,&var63,&var880,&var1531,&var877};
_S_or3  S_or3_720_1 = {&R4MD31LP2,&var867,&var871,&var878};
_S_or2  S_or2_751_1 = {&var1620,&var882,&var879};
_S_or2  S_or2_750_1 = {&var1620,&var881,&var880};
_S_and2  S_and2_665_1 = {&var64,&var1534,&var881};
_S_and3  S_and3_698_1 = {&var1533,&var1547,&var63,&var882};
_S_and2  S_and2_703_1 = {&R5IS11LDU,&var897,&var883};
_S_and3  S_and3_701_1 = {&var1185,&R3IS21LDU,&var897,&var884};
_S_and2  S_and2_702_1 = {&R6IS21LDU,&var897,&var885};
_S_or2  S_or2_700_1 = {&B8IS22LDU,&A8IS22LDU,&var886};
_S_and2  S_and2_699_1 = {&var886,&var897,&var887};
_S_and2  S_and2_686_1 = {&var897,&var889,&var888};
_S_or4  S_or4_687_1 = {&A0VN71LZ1,&B0VN71LZ1,&B0VN71LZ2,&A0VN71LZ2,&var889};
_S_and2  S_and2_684_1 = {&var894,&var897,&var890};
_S_and2  S_and2_675_1 = {&var900,&var897,&var891};
_S_and2  S_and2_674_1 = {&var1623,&var897,&var892};
_S_or3  S_or3_673_1 = {&R0NE01LDU,&R0NE02LDU,&R0NE08LDU,&var893};
_S_or2  S_or2_685_1 = {&R1IS21LDU,&R2IS21LDU,&var894};
_S_and2  S_and2_672_1 = {&var897,&var893,&var895};
_S_and2  S_and2_670_1 = {&var1601,&var897,&var896};
_S_or2  S_or2_661_1 = {&var1622,&var1621,&var897};
_S_or2  S_or2_166_1 = {&var1191,&var780,&var898};
_S_or3  S_or3_156_1 = {&var590,&var1190,&var1000,&var899};
_S_or2  S_or2_147_1 = {&var1464,&var399,&var900};
_S_or3  S_or3_108_1 = {&var1153,&var385,&var386,&var901};
_S_or2  S_or2_1999_1 = {&var347,&var224,&var902};
_S_or3  S_or3_570_1 = {&var904,&var905,&var731,&var903};
_S_and2  S_and2_559_1 = {&var1361,&var907,&var904};
_S_and2  S_and2_560_1 = {&var1361,&var957,&var905};
_S_or2  S_or2_60_1 = {&var957,&var907,&var906};
_S_and2  S_and2_63_1 = {&var908,&var1036,&var907};
_S_and2  S_and2_62_1 = {&var1630,&var1037,&var908};
_S_or2  S_or2_48_1 = {&A4IS21LDU,&B4IS21LDU,&var909};
_S_or2  S_or2_35_1 = {&var1281,&var1278,&var910};
_S_or2  S_or2_39_1 = {&var1281,&var1280,&var911};
_S_or2  S_or2_20_1 = {&var1185,&var1138,&var912};
_S_or2  S_or2_8_1 = {&var1640,&var959,&var913};
_S_or2  S_or2_14_1 = {&var959,&var1641,&var914};
_S_and3  S_and3_982_1 = {&var259,&var1634,&var934,&var915};
_S_and3  S_and3_583_1 = {&var934,&var262,&var1634,&var916};
_S_and2  S_and2_1048_1 = {&var980,&var918,&var917};
_S_or2  S_or2_1055_1 = {&var1641,&var1640,&var918};
_S_or2  S_or2_1354_1 = {&var1642,&var1640,&var919};
_S_and3  S_and3_1353_1 = {&var978,&var919,&var657,&var920};
_S_or2  S_or2_957_1 = {&var1642,&var1640,&var921};
_S_and3  S_and3_956_1 = {&var978,&var921,&var672,&var922};
_S_or2  S_or2_549_1 = {&var1642,&var1640,&var923};
_S_and3  S_and3_548_1 = {&var978,&var923,&var1362,&var924};
_S_and2  S_and2_546_1 = {&var149,&var1362,&var925};
_S_or2  S_or2_232_1 = {&var1642,&var1640,&var926};
_S_and3  S_and3_231_1 = {&var978,&var926,&var1395,&var927};
_S_and2  S_and2_229_1 = {&var1395,&var150,&var928};
_S_and3  S_and3_862_1 = {&var978,&var931,&var697,&var929};
_S_and2  S_and2_861_1 = {&var491,&var697,&var930};
_S_or2  S_or2_863_1 = {&var1642,&var1640,&var931};
_S_or2  S_or2_1265_1 = {&var1642,&var1640,&var932};
_S_or2  S_or2_6_1 = {&var1641,&var1640,&var933};
_S_or3  S_or3_5_1 = {&var1642,&var1641,&var1640,&var934};
_S_or2  S_or2_738_1 = {&var1542,&var1544,&var935};
_S_or2  S_or2_431_1 = {&var1623,&var940,&var936};
_S_or2  S_or2_414_1 = {&var1623,&var941,&var937};
_S_or4  S_or4_415_1 = {&var937,&var1551,&var1550,&var936,&var938};
_S_and2  S_and2_407_1 = {&A8IS22LDU,&var1615,&var939};
_S_or3  S_or3_393_1 = {&var1605,&var1603,&var1604,&var940};
_S_or3  S_or3_378_1 = {&var1613,&var1612,&var1614,&var941};
_S_and2  S_and2_725_1 = {&var1622,&var1544,&var942};
_S_and2  S_and2_38_1 = {&var1278,&var1279,&var943};
_S_and2  S_and2_142_1 = {&var1554,&var1176,&var944};
_S_and2  S_and2_150_1 = {&var1556,&var1176,&var945};
_S_and2  S_and2_153_1 = {&var1553,&var1176,&var946};
_S_and2  S_and2_145_1 = {&var1176,&var1555,&var947};
_S_and2  S_and2_428_1 = {&var900,&var1607,&var948};
_S_and2  S_and2_427_1 = {&B8IS22LDU,&var1607,&var949};
_S_and2  S_and2_426_1 = {&A8IS22LDU,&var1607,&var950};
_S_and2  S_and2_425_1 = {&R5IS11LDU,&var1607,&var951};
_S_and2  S_and2_417_1 = {&var1549,&var1615,&var952};
_S_and2  S_and2_406_1 = {&R5IS11LDU,&var1615,&var953};
_S_and2  S_and2_410_1 = {&var900,&var1615,&var954};
_S_and2  S_and2_112_1 = {&var959,&var384,&var955};
_S_and2  S_and2_58_1 = {&var1631,&var1037,&var956};
_S_and2  S_and2_59_1 = {&var956,&var1035,&var957};
_S_and2  S_and2_42_1 = {&var1279,&var1280,&var958};
_S_and2  S_and2_11_1 = {&var1639,&var1271,&var959};
_S_and2  S_and2_31_1 = {&var1202,&var248,&var960};
_S_and2  S_and2_30_1 = {&var1096,&var1185,&var961};
_S_and2  S_and2_29_1 = {&var1097,&var1185,&var962};
_S_and2  S_and2_28_1 = {&var1098,&var1185,&var963};
_S_and2  S_and2_27_1 = {&var1099,&var1185,&var964};
_S_and2  S_and2_752_1 = {&var1538,&var1546,&var965};
_S_and2  S_and2_734_1 = {&var1545,&var1622,&var966};
_S_bol  S_bol_584_1 = {&var1735,&fRM_20_0,&var967};
_S_bol  S_bol_578_1 = {&var1732,&fRM_20_0,&var968};
_S_bol  S_bol_569_1 = {&var1732,&fRM_20_03,&var969};
_S_bol  S_bol_567_1 = {&var1735,&fRM_20_03,&var970};
_S_bol  S_bol_972_1 = {&var1732,&fRM_20_03,&var971};
_S_bol  S_bol_974_1 = {&var1735,&fRM_20_03,&var972};
_S_bol  S_bol_1369_1 = {&var1735,&fRM_20_03,&var973};
_S_bol  S_bol_1371_1 = {&var1732,&fRM_20_03,&var974};
_S_bol  S_bol_253_1 = {&var1732,&fRM_20_03,&var975};
_S_bol  S_bol_255_1 = {&var1735,&fRM_20_03,&var976};
_S_sr  S_sr_82_1 = {array_m82_x_1,&iRM_2_,&var977};
_S_bol  S_bol_81_1 = {&var977,&var202,&var978};
_S_ma  S_ma_84_1 = {array_m84_x_1,&R0MW15IP1,&iRM_8_,&var979};
_S_bol  S_bol_1049_1 = {&var981,&fEM_R0UN80RDU,&var980};
_S_sr  S_sr_1056_1 = {array_m1056_x_1,&iRM_2_,&var981};
_S_ovbs  S_ovbs_2077_1 = {&lRM_1_,&fEM_A9UZ04RDU,&var982,&internal1_m2077_tx};
_S_ovbs  S_ovbs_1166_1 = {&lRM_1_,&fEM_A4UZ04RDU,&var983,&internal1_m1166_tx};
_S_zpfs  S_zpfs_1592_1 = {&var1509,&fEM_B8UL03RDU,&var984,&internal1_m1592_tx,&internal1_m1592_y0};
_S_zpfs  S_zpfs_1132_1 = {&var1526,&fEM_B8UL03RDU,&var985,&internal1_m1132_tx,&internal1_m1132_y0};
_S_ma  S_ma_1191_1 = {array_m1191_x_1,&var1478,&iRM_8_,&var986};
_S_ma  S_ma_801_1 = {array_m801_x_1,&var1438,&iRM_8_,&var987};
_S_ma  S_ma_886_1 = {array_m886_x_1,&var1329,&iRM_8_,&var988};
_S_ma  S_ma_1288_1 = {array_m1288_x_1,&var1297,&iRM_8_,&var989};
_S_ma  S_ma_487_1 = {array_m487_x_1,&var1358,&iRM_8_,&var990};
_S_ma  S_ma_164_1 = {array_m164_x_1,&var1391,&iRM_8_,&var991};
_S_zpfs  S_zpfs_1318_1 = {&var1314,&fEM_A3UL03RDU,&var992,&internal1_m1318_tx,&internal1_m1318_y0};
_S_zpfs  S_zpfs_921_1 = {&var1346,&fEM_A3UL03RDU,&var993,&internal1_m921_tx,&internal1_m921_y0};
_S_zpfs  S_zpfs_1227_1 = {&var1496,&fEM_A2UL03RDU,&var994,&internal1_m1227_tx,&internal1_m1227_y0};
_S_rs  S_rs_1073_1 = {&var841,&var840,&var995,&vainSBool,&internal1_m1073_q0};
_S_rs  S_rs_1071_1 = {&var158,&var1003,&var996,&vainSBool,&internal1_m1071_q0};
_S_rs  S_rs_1070_1 = {&var841,&var839,&var997,&vainSBool,&internal1_m1070_q0};
_S_rs  S_rs_1068_1 = {&var157,&var1003,&var998,&vainSBool,&internal1_m1068_q0};
_S_rs  S_rs_1067_1 = {&var841,&var838,&var999,&vainSBool,&internal1_m1067_q0};
_S_rs  S_rs_1065_1 = {&var156,&var1003,&var1000,&vainSBool,&internal1_m1065_q0};
_S_rs  S_rs_1064_1 = {&var841,&var837,&var1001,&vainSBool,&internal1_m1064_q0};
_S_rs  S_rs_1062_1 = {&var155,&var1003,&var1002,&vainSBool,&internal1_m1062_q0};
_S_rs  S_rs_1061_1 = {&var841,&var203,&var1003,&vainSBool,&internal1_m1061_q0};
_S_noto  S_noto_1911_1 = {&var459,&var1004};
_S_swtakt  S_swtakt_52_1 = {&var379,&var1005,&internal1_m52_x0};
_S_noto  S_noto_1047_1 = {&var1017,&var1006};
_S_noto  S_noto_1021_1 = {&var1015,&var1007};
_S_noto  S_noto_1033_1 = {&var1016,&var1008};
_S_rs  S_rs_981_1 = {&var1018,&var598,&var1009,&vainSBool,&internal1_m981_q0};
_S_swtakt  S_swtakt_1415_1 = {&var557,&var1010,&internal1_m1415_x0};
_S_swtakt  S_swtakt_1459_1 = {&var545,&var1011,&internal1_m1459_x0};
_S_swtakt  S_swtakt_1455_1 = {&var539,&var1012,&internal1_m1455_x0};
_S_swtakt  S_swtakt_1871_1 = {&var446,&var1013,&internal1_m1871_x0};
_S_swtakt  S_swtakt_1836_1 = {&var420,&var1014,&internal1_m1836_x0};
_S_rs  S_rs_1020_1 = {&var1089,&var586,&var1015,&vainSBool,&internal1_m1020_q0};
_S_rs  S_rs_1032_1 = {&var1089,&var587,&var1016,&vainSBool,&internal1_m1032_q0};
_S_rs  S_rs_1044_1 = {&var1089,&var588,&var1017,&vainSBool,&internal1_m1044_q0};
_S_rs  S_rs_1054_1 = {&var1089,&var589,&var1018,&vainSBool,&internal1_m1054_q0};
_S_noto  S_noto_1007_1 = {&var604,&var1019};
_S_noto  S_noto_1034_1 = {&var604,&var1020};
_S_noto  S_noto_1040_1 = {&var608,&var1021};
_S_rs  S_rs_1031_1 = {&var582,&var584,&var1022,&vainSBool,&internal1_m1031_q0};
_S_rs  S_rs_1046_1 = {&var1089,&var580,&var1023,&vainSBool,&internal1_m1046_q0};
_S_bol  S_bol_1028_1 = {&var1720,&var309,&var1024};
_S_bol  S_bol_1027_1 = {&var1723,&var309,&var1025};
_S_noto  S_noto_988_1 = {&var1084,&var1026};
_S_bol  S_bol_1025_1 = {&var309,&var1720,&var1027};
_S_bol  S_bol_1024_1 = {&var309,&var1723,&var1028};
_S_noto  S_noto_1011_1 = {&var1085,&var1029};
_S_rs  S_rs_1929_1 = {&var464,&var455,&var1030,&vainSBool,&internal1_m1929_q0};
_S_rs  S_rs_1928_1 = {&var464,&var456,&var1031,&vainSBool,&internal1_m1928_q0};
_S_noto  S_noto_322_1 = {&var812,&var1032};
_S_noto  S_noto_304_1 = {&var805,&var1033};
_S_noto  S_noto_277_1 = {&var824,&var1034};
_S_noto  S_noto_56_1 = {&var1046,&var1035};
_S_noto  S_noto_67_1 = {&var1068,&var1036};
_S_noto  S_noto_66_1 = {&var1003,&var1037};
_S_noto  S_noto_1923_1 = {&B2IS11LDU,&var1038};
_S_noto  S_noto_1921_1 = {&A2IS11LDU,&var1039};
_S_noto  S_noto_282_1 = {&var262,&var1040};
_S_noto  S_noto_1930_1 = {&B2IS11LDU,&var1041};
_S_noto  S_noto_1905_1 = {&A2IS11LDU,&var1042};
_S_noto  S_noto_269_1 = {&var908,&var1043};
_S_noto  S_noto_326_1 = {&var956,&var1044};
_S_bolz  S_bolz_330_1 = {&iRM_2_,&var1047,&var1045};
_S_provsbr  S_provsbr_325_1 = {&var1107,&var768,&var1122,&var1139,&var1133,&var1128,&var1125,&var1123,&var1137,&var1132,&var1130,&var1126,&iRM_10_,array_m325_Tpr_1,array_m325_type_1,&var1046,&var1047,&var1048,&var1049,&var1050,&var1051,&var1052,&var1053,&var1054,&internal1_m325_Step,array_m325_rz_1,&internal1_m325_TimS,&internal1_m325_FinPr0,&internal1_m325_ErrPr0,&internal1_m325_sbINI0,&internal1_m325_sbVuIS0,&internal1_m325_sb2UR0,&internal1_m325_sbNupIS0,&internal1_m325_sbVuRB0,&internal1_m325_MyFirstEnterFlag};
_S_orni  S_orni_329_1 = {array_m329_x_1,&iRM_5_,&vainSBool,&var1055};
_S_cntch  S_cntch_333_1 = {&var1055,&var1056,&internal1_m333_x0};
_S_bolz  S_bolz_308_1 = {&iRM_20_,&var1070,&var1057};
_S_equz_p  S_equz_p_307_1 = {&var1069,&iRM_0_,&var1058};
_S_decatron  S_decatron_291_1 = {&var804,&var1059,&internal1_m291_TimS};
_S_noto  S_noto_985_1 = {&R2IS21LDU,&var1060};
_S_noto  S_noto_979_1 = {&R1IS21LDU,&var1061};
_S_andn  S_andn_264_1 = {array_m264_x_1,&iRM_7_,&var1062};
_S_noto  S_noto_266_1 = {&R0MD33LP1,&var1063};
_S_noto  S_noto_275_1 = {&R2IS21LDU,&var1064};
_S_noto  S_noto_270_1 = {&R1IS21LDU,&var1065};
_S_noto  S_noto_261_1 = {&R1IS11LDU,&var1066};
_S_noto  S_noto_258_1 = {&R2IS11LDU,&var1067};
_S_provsbr  S_provsbr_268_1 = {&var1109,&var821,&var1122,&var1139,&var1133,&var1128,&var1125,&var1123,&var1137,&var1132,&var1130,&var1126,&iRM_10_,array_m268_Tpr_1,array_m268_type_1,&var1068,&var1069,&var1070,&var1071,&var1072,&var1073,&var1074,&var1075,&var1076,&internal1_m268_Step,array_m268_rz_1,&internal1_m268_TimS,&internal1_m268_FinPr0,&internal1_m268_ErrPr0,&internal1_m268_sbINI0,&internal1_m268_sbVuIS0,&internal1_m268_sb2UR0,&internal1_m268_sbNupIS0,&internal1_m268_sbVuRB0,&internal1_m268_MyFirstEnterFlag};
_S_rs  S_rs_1389_1 = {&var1078,&var579,&var1077,&vainSBool,&internal1_m1389_q0};
_S_provsbr  S_provsbr_1390_1 = {&var1077,&R0MD34LP1,&var1122,&var1139,&var1133,&var1128,&var1125,&var1123,&var1137,&var1132,&var1130,&var1126,&iRM_6_,array_m1390_Tpr_1,array_m1390_type_1,&var1078,&vainSInt,&vainSInt,&vainSBool,&var1079,&var1080,&var1081,&var1082,&var1083,&internal1_m1390_Step,array_m1390_rz_1,&internal1_m1390_TimS,&internal1_m1390_FinPr0,&internal1_m1390_ErrPr0,&internal1_m1390_sbINI0,&internal1_m1390_sbVuIS0,&internal1_m1390_sb2UR0,&internal1_m1390_sbNupIS0,&internal1_m1390_sbVuRB0,&internal1_m1390_MyFirstEnterFlag};
_S_abs_subf  S_abs_subf_991_1 = {&var309,&var1723,&fEM_B8UC01RDU,&vainSFloat,&var1084};
_S_abs_subf  S_abs_subf_1004_1 = {&var1720,&var309,&fEM_B8UC01RDU,&vainSFloat,&var1085};
_S_noto  S_noto_643_1 = {&var772,&var1086};
_S_noto  S_noto_591_1 = {&var788,&var1087};
_S_noto  S_noto_49_1 = {&var305,&var1088};
_S_noto  S_noto_1008_1 = {&var1286,&var1089};
_S_rs  S_rs_1015_1 = {&var581,&var400,&var1090,&vainSBool,&internal1_m1015_q0};
_S_rs  S_rs_1012_1 = {&var585,&var580,&var1091,&vainSBool,&internal1_m1012_q0};
_S_rs  S_rs_1014_1 = {&var1089,&var400,&var1092,&vainSBool,&internal1_m1014_q0};
_S_rs  S_rs_1009_1 = {&var1089,&var583,&var1093,&vainSBool,&internal1_m1009_q0};
_S_noto  S_noto_580_1 = {&A2IS21LDU,&var1094};
_S_noto  S_noto_582_1 = {&B2IS21LDU,&var1095};
_S_noto  S_noto_25_1 = {&B2IS21LDU,&var1096};
_S_noto  S_noto_24_1 = {&B1IS21LDU,&var1097};
_S_noto  S_noto_23_1 = {&A1IS21LDU,&var1098};
_S_noto  S_noto_22_1 = {&A2IS21LDU,&var1099};
_S_newstage  S_newstage_592_1 = {&var126,&var123,&A2IS12LDU,&B2IS12LDU,&var1100};
_S_noto  S_noto_581_1 = {&B2IS12LDU,&var1101};
_S_noto  S_noto_579_1 = {&A2IS12LDU,&var1102};
_S_noto  S_noto_339_1 = {&var763,&var1103};
_S_noto  S_noto_343_1 = {&var762,&var1104};
_S_noto  S_noto_978_1 = {&var900,&var1105};
_S_rs  S_rs_742_1 = {&var760,&var382,&var1106,&vainSBool,&internal1_m742_q0};
_S_rs  S_rs_335_1 = {&var764,&var765,&var1107,&vainSBool,&internal1_m335_q0};
_S_rs  S_rs_331_1 = {&var766,&var767,&var1108,&vainSBool,&internal1_m331_q0};
_S_rs  S_rs_288_1 = {&var820,&var806,&var1109,&vainSBool,&internal1_m288_q0};
_S_orni  S_orni_284_1 = {array_m284_x_1,&iRM_5_,&vainSBool,&var1110};
_S_cntch  S_cntch_287_1 = {&var1110,&var1111,&internal1_m287_x0};
_S_noto  S_noto_1428_1 = {&var1130,&var1112};
_S_noto  S_noto_1484_1 = {&var1132,&var1113};
_S_noto  S_noto_1486_1 = {&var1137,&var1114};
_S_noto  S_noto_1852_1 = {&var1123,&var1115};
_S_noto  S_noto_1890_1 = {&var1126,&var1116};
_S_noto  S_noto_1867_1 = {&var1013,&var1117};
_S_noto  S_noto_1830_1 = {&var1014,&var1118};
_S_noto  S_noto_1456_1 = {&var1012,&var1119};
_S_noto  S_noto_1451_1 = {&var1011,&var1120};
_S_noto  S_noto_1411_1 = {&var1010,&var1121};
_S_rs  S_rs_1858_1 = {&var564,&var404,&var1122,&vainSBool,&internal1_m1858_q0};
_S_rs  S_rs_1846_1 = {&var419,&var416,&var1123,&vainSBool,&internal1_m1846_q0};
_S_rs  S_rs_1837_1 = {&var415,&var1014,&var1124,&vainSBool,&internal1_m1837_q0};
_S_rs  S_rs_1912_1 = {&var564,&var433,&var1125,&vainSBool,&internal1_m1912_q0};
_S_rs  S_rs_1882_1 = {&var441,&var440,&var1126,&vainSBool,&internal1_m1882_q0};
_S_rs  S_rs_1872_1 = {&var443,&var1013,&var1127,&vainSBool,&internal1_m1872_q0};
_S_rs  S_rs_1442_1 = {&var564,&var550,&var1128,&vainSBool,&internal1_m1442_q0};
_S_kvf  S_kvf_1429_1 = {&var1131,&var551,&fRM_0_0,&var1129,&vainSInt,&vainSInt,&internal1_m1429_x0,&internal1_m1429_y0,&bFirstEnterFlag};
_S_rs  S_rs_1425_1 = {&var556,&var551,&var1130,&vainSBool,&internal1_m1425_q0};
_S_rs  S_rs_1416_1 = {&var553,&var1010,&var1131,&vainSBool,&internal1_m1416_q0};
_S_rs  S_rs_1475_1 = {&var546,&var541,&var1132,&vainSBool,&internal1_m1475_q0};
_S_rs  S_rs_1495_1 = {&var564,&var547,&var1133,&vainSBool,&internal1_m1495_q0};
_S_rs  S_rs_1461_1 = {&var544,&var1011,&var1134,&vainSBool,&internal1_m1461_q0};
_S_kvf  S_kvf_1476_1 = {&var1134,&var541,&fRM_0_0,&var1135,&vainSInt,&vainSInt,&internal1_m1476_x0,&internal1_m1476_y0,&bFirstEnterFlag};
_S_cntch  S_cntch_1400_1 = {&var566,&var1136,&internal1_m1400_x0};
_S_rs  S_rs_1481_1 = {&var538,&var532,&var1137,&vainSBool,&internal1_m1481_q0};
_S_rs  S_rs_26_1 = {&var1185,&var960,&var1138,&vainSBool,&internal1_m26_q0};
_S_rs  S_rs_1496_1 = {&var564,&var531,&var1139,&vainSBool,&internal1_m1496_q0};
_S_noto  S_noto_1378_1 = {&var560,&var1140};
_S_noto  S_noto_1376_1 = {&var959,&var1141};
_S_rs  S_rs_632_1 = {&var1517,&var775,&var1142,&vainSBool,&internal1_m632_q0};
_S_rs  S_rs_617_1 = {&var1517,&var782,&var1143,&vainSBool,&internal1_m617_q0};
_S_rs  S_rs_644_1 = {&var1517,&var783,&var1144,&vainSBool,&internal1_m644_q0};
_S_rs  S_rs_628_1 = {&var1517,&var794,&var1145,&vainSBool,&internal1_m628_q0};
_S_rs  S_rs_612_1 = {&var1517,&var797,&var1146,&vainSBool,&internal1_m612_q0};
_S_rs  S_rs_610_1 = {&var1517,&var799,&var1147,&vainSBool,&internal1_m610_q0};
_S_rs  S_rs_598_1 = {&var802,&var1520,&var1148,&vainSBool,&internal1_m598_q0};
_S_rsun  S_rsun_1392_1 = {&var564,&var1270,&vainSLong,&var1149,&internal1_m1392_q0};
_S_noto  S_noto_1319_1 = {&B3MD12LP1,&var1150};
_S_noto  S_noto_1806_1 = {&B3IS11LDU,&var1151};
_S_noto  S_noto_1780_1 = {&A3IS11LDU,&var1152};
_S_noto  S_noto_111_1 = {&var959,&var1153};
_S_noto  S_noto_110_1 = {&var1158,&var1154};
_S_rs  S_rs_608_1 = {&var1517,&var801,&var1155,&vainSBool,&internal1_m608_q0};
_S_orni  S_orni_1165_1 = {array_m1165_x_1,&iRM_5_,&var1156,&vainSLong};
_S_orni  S_orni_1153_1 = {array_m1153_x_1,&iRM_4_,&var1157,&vainSLong};
_S_rs  S_rs_109_1 = {&var901,&var955,&var1158,&vainSBool,&internal1_m109_q0};
_S_noto  S_noto_1809_1 = {&var482,&var1159};
_S_noto  S_noto_1808_1 = {&var481,&var1160};
_S_noto  S_noto_1820_1 = {&B3IS22LDU,&var1161};
_S_noto  S_noto_1801_1 = {&A3IS22LDU,&var1162};
_S_newstage  S_newstage_1804_1 = {&var498,&var494,&var497,&var493,&vainSBool};
_S_noto  S_noto_1748_1 = {&var1248,&var1163};
_S_rs  S_rs_1628_1 = {&var40,&var273,&var1164,&vainSBool,&internal1_m1628_q0};
_S_rs  S_rs_1627_1 = {&var33,&var275,&var1165,&vainSBool,&internal1_m1627_q0};
_S_rs  S_rs_1626_1 = {&var39,&var277,&var1166,&vainSBool,&internal1_m1626_q0};
_S_rs  S_rs_1625_1 = {&var14,&var279,&var1167,&vainSBool,&internal1_m1625_q0};
_S_rs  S_rs_1663_1 = {&var248,&var281,&var1168,&vainSBool,&internal1_m1663_q0};
_S_rs  S_rs_1662_1 = {&var51,&var284,&var1169,&vainSBool,&internal1_m1662_q0};
_S_rs  S_rs_1661_1 = {&var52,&var284,&var1170,&vainSBool,&internal1_m1661_q0};
_S_noto  S_noto_1218_1 = {&A2MD12LP1,&var1171};
_S_noto  S_noto_1203_1 = {&B2MD12LP1,&var1172};
_S_noto  S_noto_502_1 = {&B1MD12LP1,&var1173};
_S_ma  S_ma_1431_1 = {array_m1431_x_1,&var1149,&iRM_16_,&var1174};
_S_noto  S_noto_1386_1 = {&var816,&var1175};
_S_noto  S_noto_140_1 = {&var959,&var1176};
_S_equz_p  S_equz_p_1786_1 = {&R0MW14IP2,&iRM_5_,&var1177};
_S_equz_p  S_equz_p_1785_1 = {&R0MW14IP2,&iRM_4_,&var1178};
_S_equz_p  S_equz_p_1784_1 = {&R0MW14IP2,&iRM_3_,&var1179};
_S_equz_p  S_equz_p_1782_1 = {&R0MW14IP2,&iRM_1_,&vainSBool};
_S_equz_p  S_equz_p_1783_1 = {&R0MW14IP2,&iRM_2_,&var1180};
_S_noto  S_noto_1839_1 = {&B3IS11LDU,&var1181};
_S_noto  S_noto_1834_1 = {&A3IS11LDU,&var1182};
_S_noto  S_noto_1876_1 = {&B2IS11LDU,&var1183};
_S_noto  S_noto_1883_1 = {&A2IS11LDU,&var1184};
_S_noto  S_noto_12_1 = {&var1639,&var1185};
_S_rs  S_rs_1943_1 = {&var367,&var468,&var1186,&vainSBool,&internal1_m1943_q0};
_S_rs  S_rs_1723_1 = {&var510,&var294,&var1187,&vainSBool,&internal1_m1723_q0};
_S_rs  S_rs_1713_1 = {&var36,&var295,&var1188,&vainSBool,&internal1_m1713_q0};
_S_rs  S_rs_1720_1 = {&var53,&var296,&var1189,&vainSBool,&internal1_m1720_q0};
_S_rs  S_rs_1709_1 = {&var37,&var297,&var1190,&vainSBool,&internal1_m1709_q0};
_S_rs  S_rs_1717_1 = {&var57,&var298,&var1191,&vainSBool,&internal1_m1717_q0};
_S_equz_p  S_equz_p_99_1 = {&R0MW16IP1,&iRM_10_,&var1192};
_S_noto  S_noto_178_1 = {&A1MD12LP1,&var1193};
_S_rs  S_rs_2143_1 = {&var27,&var24,&var1194,&vainSBool,&internal1_m2143_q0};
_S_rs  S_rs_2139_1 = {&var43,&var115,&var1195,&vainSBool,&internal1_m2139_q0};
_S_rs  S_rs_1688_1 = {&var56,&var291,&var1196,&vainSBool,&internal1_m1688_q0};
_S_rs  S_rs_1680_1 = {&var248,&var280,&var1197,&vainSBool,&internal1_m1680_q0};
_S_rs  S_rs_1678_1 = {&var38,&var281,&var1198,&vainSBool,&internal1_m1678_q0};
_S_rs  S_rs_1674_1 = {&var51,&var282,&var1199,&vainSBool,&internal1_m1674_q0};
_S_rs  S_rs_1670_1 = {&var11,&var284,&var1200,&vainSBool,&internal1_m1670_q0};
_S_rs  S_rs_1672_1 = {&var52,&var283,&var1201,&vainSBool,&internal1_m1672_q0};
_S_rs  S_rs_19_1 = {&var912,&var388,&var1202,&vainSBool,&internal1_m19_q0};
_S_equz_p  S_equz_p_98_1 = {&R0MW16IP1,&iRM_9_,&var1203};
_S_equz_p  S_equz_p_97_1 = {&R0MW16IP1,&iRM_8_,&var1204};
_S_noto  S_noto_922_1 = {&A3MD12LP1,&var1205};
_S_equz_p  S_equz_p_96_1 = {&R0MW16IP1,&iRM_7_,&var1206};
_S_equz_p  S_equz_p_95_1 = {&R0MW16IP1,&iRM_6_,&var1207};
_S_equz_p  S_equz_p_94_1 = {&R0MW16IP1,&iRM_5_,&var1208};
_S_rs  S_rs_1651_1 = {&var40,&var272,&var1209,&vainSBool,&internal1_m1651_q0};
_S_rs  S_rs_1649_1 = {&var32,&var273,&var1210,&vainSBool,&internal1_m1649_q0};
_S_rs  S_rs_1645_1 = {&var50,&var275,&var1211,&vainSBool,&internal1_m1645_q0};
_S_rs  S_rs_1647_1 = {&var33,&var274,&var1212,&vainSBool,&internal1_m1647_q0};
_S_rs  S_rs_1643_1 = {&var39,&var276,&var1213,&vainSBool,&internal1_m1643_q0};
_S_rs  S_rs_1641_1 = {&var15,&var277,&var1214,&vainSBool,&internal1_m1641_q0};
_S_rs  S_rs_2059_1 = {&var130,&var477,&var1215,&vainSBool,&internal1_m2059_q0};
_S_rs  S_rs_2054_1 = {&var131,&var478,&var1216,&vainSBool,&internal1_m2054_q0};
_S_equz_p  S_equz_p_297_1 = {&var1059,&iRM_0_,&var1217};
_S_noto  S_noto_2060_1 = {&var1215,&var1218};
_S_noto  S_noto_2050_1 = {&var392,&var1219};
_S_noto  S_noto_2034_1 = {&var1221,&var1220};
_S_rs  S_rs_2033_1 = {&var70,&var474,&var1221,&vainSBool,&internal1_m2033_q0};
_S_noto  S_noto_2022_1 = {&var1223,&var1222};
_S_rs  S_rs_2021_1 = {&var72,&var471,&var1223,&vainSBool,&internal1_m2021_q0};
_S_noto  S_noto_2055_1 = {&var1216,&var1224};
_S_noto  S_noto_2046_1 = {&var391,&var1225};
_S_noto  S_noto_1955_1 = {&var1227,&var1226};
_S_rs  S_rs_1954_1 = {&var366,&var469,&var1227,&vainSBool,&internal1_m1954_q0};
_S_noto  S_noto_1944_1 = {&var1186,&var1228};
_S_noto  S_noto_1950_1 = {&var389,&var1229};
_S_noto  S_noto_1938_1 = {&var390,&var1230};
_S_rs  S_rs_1637_1 = {&var49,&var279,&var1231,&vainSBool,&internal1_m1637_q0};
_S_rs  S_rs_1639_1 = {&var14,&var278,&var1232,&vainSBool,&internal1_m1639_q0};
_S_rs  S_rs_1623_1 = {&var30,&var264,&var1233,&vainSBool,&internal1_m1623_q0};
_S_rs  S_rs_1621_1 = {&var48,&var265,&var1234,&vainSBool,&internal1_m1621_q0};
_S_rs  S_rs_1619_1 = {&var29,&var266,&var1235,&vainSBool,&internal1_m1619_q0};
_S_rs  S_rs_1617_1 = {&var47,&var267,&var1236,&vainSBool,&internal1_m1617_q0};
_S_noto  S_noto_1743_1 = {&B3IS22LDU,&var1237};
_S_noto  S_noto_1742_1 = {&A3IS22LDU,&var1238};
_S_noto  S_noto_1741_1 = {&B2IS12LDU,&var1239};
_S_noto  S_noto_1740_1 = {&A2IS12LDU,&var1240};
_S_noto  S_noto_1739_1 = {&B1IS12LDU,&var1241};
_S_noto  S_noto_1738_1 = {&A1IS12LDU,&var1242};
_S_noto  S_noto_1768_1 = {&B3IS21LDU,&var1243};
_S_noto  S_noto_1762_1 = {&B2IS21LDU,&var1244};
_S_noto  S_noto_1767_1 = {&A3IS21LDU,&var1245};
_S_noto  S_noto_1765_1 = {&B4IS21LDU,&var1246};
_S_noto  S_noto_1766_1 = {&A4IS21LDU,&var1247};
_S_andn  S_andn_1751_1 = {array_m1751_x_1,&iRM_17_,&var1248};
_S_noto  S_noto_1760_1 = {&B1IS21LDU,&var1249};
_S_noto  S_noto_1761_1 = {&A2IS21LDU,&var1250};
_S_noto  S_noto_1759_1 = {&A1IS21LDU,&var1251};
_S_rs  S_rs_1616_1 = {&var1256,&var268,&var1252,&vainSBool,&internal1_m1616_q0};
_S_rs  S_rs_1614_1 = {&var31,&var269,&var1253,&vainSBool,&internal1_m1614_q0};
_S_rs  S_rs_1613_1 = {&var1256,&var270,&var1254,&vainSBool,&internal1_m1613_q0};
_S_rs  S_rs_1611_1 = {&var12,&var271,&var1255,&vainSBool,&internal1_m1611_q0};
_S_newstage  S_newstage_2080_1 = {&var1268,&var1262,&var1267,&var1261,&var1256};
_S_samhd  S_samhd_2082_1 = {&var522,&var523,&var523,&var1253,&var1252,&var1253,&var1252,&B9IS11LDU,&B9IS11LDU,&B9IS21LDU,&B9IS21LDU,&bRM_1_,&fEM_A9UZ05RDU,&fEM_A9UZ03RDU,&fEM_A9UZ04RDU,&var1257,&var1258,&vainSBool,&var1259,&var1260,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1261,&var1262,&internal1_m2082_DvUp0,&internal1_m2082_DvDw0,&internal1_m2082_FDvUp0,&internal1_m2082_FDvDw0,&internal1_m2082_BlDv0,&internal1_m2082_Pkv0,&internal1_m2082_Pkav0,&internal1_m2082_Zkv0,&internal1_m2082_Zkav0,&internal1_m2082_txNm,&internal1_m2082_txSm,&internal1_m2082_txHr,&internal1_m2082_txLd,&internal1_m2082_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_2076_1 = {&var522,&var524,&var524,&var1255,&var1254,&var1255,&var1254,&A9IS11LDU,&A9IS11LDU,&A9IS21LDU,&A9IS21LDU,&bRM_1_,&fEM_A9UZ05RDU,&fEM_A9UZ03RDU,&fEM_A9UZ04RDU,&var1263,&var1264,&vainSBool,&var1265,&var1266,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1267,&var1268,&internal1_m2076_DvUp0,&internal1_m2076_DvDw0,&internal1_m2076_FDvUp0,&internal1_m2076_FDvDw0,&internal1_m2076_BlDv0,&internal1_m2076_Pkv0,&internal1_m2076_Pkav0,&internal1_m2076_Zkv0,&internal1_m2076_Zkav0,&internal1_m2076_txNm,&internal1_m2076_txSm,&internal1_m2076_txHr,&internal1_m2076_txLd,&internal1_m2076_fef,&bFirstEnterFlag};
_S_orni  S_orni_1393_1 = {array_m1393_x_1,&iRM_5_,&var1269,&var1270};
_S_noto  S_noto_78_1 = {&var394,&var1271};
_S_maz  S_maz_303_1 = {array_m303_x_1,&R0MW12IP1,&iRM_3_,&var1272};
_S_maz  S_maz_294_1 = {array_m294_x_1,&R0MW12IP1,&iRM_3_,&var1273};
_S_rs  S_rs_1466_1 = {&var535,&var1012,&var1274,&vainSBool,&internal1_m1466_q0};
_S_kvf  S_kvf_1470_1 = {&var1274,&var532,&fRM_0_0,&var1275,&vainSInt,&vainSInt,&internal1_m1470_x0,&internal1_m1470_y0,&bFirstEnterFlag};
_S_kvf  S_kvf_1894_1 = {&var449,&var437,&fRM_0_0,&var1276,&vainSInt,&vainSInt,&internal1_m1894_x0,&internal1_m1894_y0,&bFirstEnterFlag};
_S_kvf  S_kvf_1855_1 = {&var409,&var406,&fRM_0_0,&var1277,&vainSInt,&vainSInt,&internal1_m1855_x0,&internal1_m1855_y0,&bFirstEnterFlag};
_S_equz_p  S_equz_p_37_1 = {&R0MW13IP1,&iRM_1_,&var1278};
_S_noto  S_noto_34_1 = {&var1281,&var1279};
_S_equz_p  S_equz_p_41_1 = {&R0MW13IP1,&iRM_2_,&var1280};
_S_equz_p  S_equz_p_32_1 = {&R0MW13IP1,&iRM_3_,&var1281};
_S_noto  S_noto_1896_1 = {&var1127,&var1282};
_S_rs  S_rs_279_1 = {&var822,&var823,&var1283,&vainSBool,&internal1_m279_q0};
_S_orn  S_orn_589_1 = {array_m589_x_1,&iRM_5_,&var1284};
_S_noto  S_noto_998_1 = {&lEM_R0MD01LC1,&var1285};
_S_rs  S_rs_989_1 = {&var599,&var915,&var1286,&vainSBool,&internal1_m989_q0};
_S_rs  S_rs_620_1 = {&var777,&var779,&var1287,&vainSBool,&internal1_m620_q0};
_S_noto  S_noto_1373_1 = {&var958,&var1288};
_S_orn  S_orn_1352_1 = {array_m1352_x_1,&iRM_8_,&var1289};
_S_noto  S_noto_1351_1 = {&var1457,&var1290};
_S_noto  S_noto_1350_1 = {&var1467,&var1291};
_S_noto  S_noto_1334_1 = {&var959,&var1292};
_S_noto  S_noto_1342_1 = {&R8IS11LDU,&var1293};
_S_charint  S_charint_1279_1 = {&var1296,&var1294};
_S_ornc  S_ornc_1287_1 = {array_m1287_x_1,&iRM_3_,&var1295,&var1296};
_S_fsumz  S_fsumz_1280_1 = {&var1294,&iRM_1_,&var1297};
_S_cnshd  S_cnshd_1289_1 = {&R0MD34LP1,&var1726,&var989,&var313,&var1295,&var644,&var640,&iRM_1_,array_m1289_Lt_fw_1,array_m1289_Vr_fw_1,&iRM_1_,array_m1289_Lt_bw_1,array_m1289_Vr_bw_1,&fEM_A3UC08RDU,&fEM_A3UC07RDU,&fEM_A3UL01RDU,&fEM_A3UC02RDU,&var1298,&vainSBool,&var1299,&var1300,&var1301,&var1302,&var1303,&var1304,&var1305,&var1306,&var1307,&var1308,&internal1_m1289_X0,&internal1_m1289_t0,&internal1_m1289_BLDv0};
_S_zpfs  S_zpfs_1308_1 = {&var1317,&fRM_2_0,&var1309,&internal1_m1308_tx,&internal1_m1308_y0};
_S_zpfs  S_zpfs_1309_1 = {&var1316,&fRM_3_0,&var1310,&internal1_m1309_tx,&internal1_m1309_y0};
_S_fnapb  S_fnapb_1317_1 = {&var1726,&var989,&var643,&R0MD34LP1,&var1300,&var1307,&fEM_B8UV04RDU,&fEM_A3UV01RDU,&fEM_A3UV02RDU,&fEM_A3UC06RDU,&fEM_A3UC05RDU,&iRM_60_,&fEM_A3UL04RDU,&fEM_A3UL05RDU,&fEM_A3UL03RDU,&var1311,&var1312,&var1313,&var1314,&var1315,&var1316,&var1317,&vainSFloat,&internal1_m1317_xptr,array_m1317_x0_1,array_m1317_tim0_1,&internal1_m1317_sumtim,&internal1_m1317_StSpeed,&internal1_m1317_Vz0,&internal1_m1317_flRazg,&internal1_m1317_DelSp,&internal1_m1317_z0,&internal1_m1317_txZS,&internal1_m1317_tx,&internal1_m1317_txd,&internal1_m1317_txMBl,&internal1_m1317_txBl,&internal1_m1317_Speed0,&internal1_m1317_xz0,&internal1_m1317_tz0,&internal1_m1317_Shift0,&internal1_m1317_ShCntlSp0,&internal1_m1317_ShiftControl,&bFirstEnterFlag};
_S_newstage  S_newstage_899_1 = {&var1327,&var1295,&var1330,&var1298,&var1318};
_S_rs  S_rs_618_1 = {&var778,&var782,&var1319,&vainSBool,&internal1_m618_q0};
_S_noto  S_noto_976_1 = {&var943,&var1320};
_S_orn  S_orn_955_1 = {array_m955_x_1,&iRM_8_,&var1321};
_S_noto  S_noto_954_1 = {&var1457,&var1322};
_S_noto  S_noto_953_1 = {&var1467,&var1323};
_S_noto  S_noto_937_1 = {&var959,&var1324};
_S_noto  S_noto_945_1 = {&R8IS11LDU,&var1325};
_S_charint  S_charint_879_1 = {&var1328,&var1326};
_S_ornc  S_ornc_885_1 = {array_m885_x_1,&iRM_3_,&var1327,&var1328};
_S_fsumz  S_fsumz_880_1 = {&var1326,&iRM_1_,&var1329};
_S_cnshd  S_cnshd_887_1 = {&R0MD34LP1,&var1729,&var988,&var317,&var1327,&var679,&var680,&iRM_1_,array_m887_Lt_fw_1,array_m887_Vr_fw_1,&iRM_1_,array_m887_Lt_bw_1,array_m887_Vr_bw_1,&fEM_A3UC08RDU,&fEM_A3UC07RDU,&fEM_A3UL01RDU,&fEM_A3UC02RDU,&var1330,&vainSBool,&var1331,&var1332,&var1333,&var1334,&var1335,&var1336,&var1337,&var1338,&var1339,&var1340,&internal1_m887_X0,&internal1_m887_t0,&internal1_m887_BLDv0};
_S_zpfs  S_zpfs_911_1 = {&var1349,&fRM_2_0,&var1341,&internal1_m911_tx,&internal1_m911_y0};
_S_zpfs  S_zpfs_914_1 = {&var1348,&fRM_3_0,&var1342,&internal1_m914_tx,&internal1_m914_y0};
_S_fnapb  S_fnapb_920_1 = {&var1729,&var988,&var678,&R0MD34LP1,&var1332,&var1339,&fEM_B8UV04RDU,&fEM_A3UV01RDU,&fEM_A3UV02RDU,&fEM_A3UC06RDU,&fEM_A3UC05RDU,&iRM_60_,&fEM_A3UL04RDU,&fEM_A3UL05RDU,&fEM_A3UL03RDU,&var1343,&var1344,&var1345,&var1346,&var1347,&var1348,&var1349,&vainSFloat,&internal1_m920_xptr,array_m920_x0_1,array_m920_tim0_1,&internal1_m920_sumtim,&internal1_m920_StSpeed,&internal1_m920_Vz0,&internal1_m920_flRazg,&internal1_m920_DelSp,&internal1_m920_z0,&internal1_m920_txZS,&internal1_m920_tx,&internal1_m920_txd,&internal1_m920_txMBl,&internal1_m920_txBl,&internal1_m920_Speed0,&internal1_m920_xz0,&internal1_m920_tz0,&internal1_m920_Shift0,&internal1_m920_ShCntlSp0,&internal1_m920_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_571_1 = {&var958,&var1350};
_S_noto  S_noto_544_1 = {&var1457,&var1351};
_S_noto  S_noto_543_1 = {&var1467,&var1352};
_S_noto  S_noto_528_1 = {&var959,&var1353};
_S_noto  S_noto_535_1 = {&R8IS11LDU,&var1354};
_S_charint  S_charint_480_1 = {&var1357,&var1355};
_S_ornc  S_ornc_486_1 = {array_m486_x_1,&iRM_3_,&var1356,&var1357};
_S_fsumz  S_fsumz_481_1 = {&var1355,&iRM_1_,&var1358};
_S_cnshd  S_cnshd_489_1 = {&R0MD34LP1,&var1739,&var990,&var321,&var1356,&var750,&var744,&iRM_2_,array_m489_Lt_fw_1,array_m489_Vr_fw_1,&iRM_1_,array_m489_Lt_bw_1,array_m489_Vr_bw_1,&fEM_A1UC08RDU,&fEM_A1UC07RDU,&fEM_A1UL01RDU,&fEM_A1UC02RDU,&var1359,&vainSBool,&var1360,&var1361,&var1362,&var1363,&var1364,&var1365,&var1366,&var1367,&var1368,&var1369,&internal1_m489_X0,&internal1_m489_t0,&internal1_m489_BLDv0};
_S_zpfs  S_zpfs_509_1 = {&var1378,&fRM_2_0,&var1370,&internal1_m509_tx,&internal1_m509_y0};
_S_zpfs  S_zpfs_512_1 = {&var1377,&fRM_3_0,&var1371,&internal1_m512_tx,&internal1_m512_y0};
_S_fnapb  S_fnapb_516_1 = {&var1739,&var990,&var748,&R0MD34LP1,&var1361,&var1368,&fEM_B8UV04RDU,&fEM_A1UV01RDU,&fEM_A1UV02RDU,&fEM_A1UC06RDU,&fEM_A1UC05RDU,&iRM_150_,&fEM_A1UL04RDU,&fEM_A1UL05RDU,&fEM_A1UL03RDU,&var1372,&var1373,&var1374,&var1375,&var1376,&var1377,&var1378,&vainSFloat,&internal1_m516_xptr,array_m516_x0_1,array_m516_tim0_1,&internal1_m516_sumtim,&internal1_m516_StSpeed,&internal1_m516_Vz0,&internal1_m516_flRazg,&internal1_m516_DelSp,&internal1_m516_z0,&internal1_m516_txZS,&internal1_m516_tx,&internal1_m516_txd,&internal1_m516_txMBl,&internal1_m516_txBl,&internal1_m516_Speed0,&internal1_m516_xz0,&internal1_m516_tz0,&internal1_m516_Shift0,&internal1_m516_ShCntlSp0,&internal1_m516_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_636_1 = {&R0MD33LP1,&var1379};
_S_noto  S_noto_257_1 = {&var943,&var1380};
_S_newstage  S_newstage_205_1 = {&var1389,&var1356,&var1392,&var1359,&var1381};
_S_rs  S_rs_615_1 = {&var773,&var785,&var1382,&vainSBool,&internal1_m615_q0};
_S_orn  S_orn_228_1 = {array_m228_x_1,&iRM_12_,&var1383};
_S_noto  S_noto_227_1 = {&var1457,&var1384};
_S_noto  S_noto_226_1 = {&var1467,&var1385};
_S_noto  S_noto_211_1 = {&var959,&var1386};
_S_noto  S_noto_218_1 = {&R8IS11LDU,&var1387};
_S_charint  S_charint_157_1 = {&var1390,&var1388};
_S_ornc  S_ornc_163_1 = {array_m163_x_1,&iRM_3_,&var1389,&var1390};
_S_fsumz  S_fsumz_158_1 = {&var1388,&iRM_1_,&var1391};
_S_cnshd  S_cnshd_168_1 = {&R0MD34LP1,&var1717,&var991,&var325,&var1389,&var730,&var723,&iRM_2_,array_m168_Lt_fw_1,array_m168_Vr_fw_1,&iRM_1_,array_m168_Lt_bw_1,array_m168_Vr_bw_1,&fEM_A1UC08RDU,&fEM_A1UC07RDU,&fEM_A1UL01RDU,&fEM_A1UC02RDU,&var1392,&vainSBool,&var1393,&var1394,&var1395,&var1396,&var1397,&var1398,&var1399,&var1400,&var1401,&var1402,&internal1_m168_X0,&internal1_m168_t0,&internal1_m168_BLDv0};
_S_fnapb  S_fnapb_197_1 = {&var1717,&var991,&var726,&R0MD34LP1,&var1394,&var1401,&fEM_B8UV04RDU,&fEM_A1UV01RDU,&fEM_A1UV02RDU,&fEM_A1UC06RDU,&fEM_A1UC05RDU,&iRM_150_,&fEM_A1UL04RDU,&fEM_A1UL05RDU,&fEM_A1UL03RDU,&var1403,&var1404,&var1405,&var1406,&var1407,&var1408,&var1409,&vainSFloat,&internal1_m197_xptr,array_m197_x0_1,array_m197_tim0_1,&internal1_m197_sumtim,&internal1_m197_StSpeed,&internal1_m197_Vz0,&internal1_m197_flRazg,&internal1_m197_DelSp,&internal1_m197_z0,&internal1_m197_txZS,&internal1_m197_tx,&internal1_m197_txd,&internal1_m197_txMBl,&internal1_m197_txBl,&internal1_m197_Speed0,&internal1_m197_xz0,&internal1_m197_tz0,&internal1_m197_Shift0,&internal1_m197_ShCntlSp0,&internal1_m197_ShiftControl,&bFirstEnterFlag};
_S_rs  S_rs_641_1 = {&var784,&var787,&var1410,&vainSBool,&internal1_m641_q0};
_S_newstage  S_newstage_456_1 = {&var1429,&var1420,&var1428,&var1419,&var1411};
_S_samhd  S_samhd_460_1 = {&R0MD34LP1,&var753,&var753,&var376,&var375,&R2VS12LDU,&R2VS22LDU,&R2IS11LDU,&R2IS11LDU,&R2IS21LDU,&R2IS21LDU,&bRM_0_,&fEM_R1UZ05RDU,&fEM_R1UZ03RDU,&fEM_R1UZ04RDU,&var1412,&var1413,&var1414,&var1415,&var1416,&var1417,&vainSBool,&vainSBool,&var1418,&var1419,&var1420,&internal1_m460_DvUp0,&internal1_m460_DvDw0,&internal1_m460_FDvUp0,&internal1_m460_FDvDw0,&internal1_m460_BlDv0,&internal1_m460_Pkv0,&internal1_m460_Pkav0,&internal1_m460_Zkv0,&internal1_m460_Zkav0,&internal1_m460_txNm,&internal1_m460_txSm,&internal1_m460_txHr,&internal1_m460_txLd,&internal1_m460_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_454_1 = {&R0MD34LP1,&var754,&var754,&var374,&var373,&R1VS12LDU,&R1VS22LDU,&R1IS11LDU,&R1IS11LDU,&R1IS21LDU,&R1IS21LDU,&bRM_0_,&fEM_R1UZ05RDU,&fEM_R1UZ03RDU,&fEM_R1UZ04RDU,&var1421,&var1422,&var1423,&var1424,&var1425,&var1426,&vainSBool,&vainSBool,&var1427,&var1428,&var1429,&internal1_m454_DvUp0,&internal1_m454_DvDw0,&internal1_m454_FDvUp0,&internal1_m454_FDvDw0,&internal1_m454_BlDv0,&internal1_m454_Pkv0,&internal1_m454_Pkav0,&internal1_m454_Zkv0,&internal1_m454_Zkav0,&internal1_m454_txNm,&internal1_m454_txSm,&internal1_m454_txHr,&internal1_m454_txLd,&internal1_m454_fef,&bFirstEnterFlag};
_S_orn  S_orn_860_1 = {array_m860_x_1,&iRM_10_,&var1430};
_S_noto  S_noto_859_1 = {&var1457,&var1431};
_S_noto  S_noto_858_1 = {&var1467,&var1432};
_S_noto  S_noto_839_1 = {&var959,&var1433};
_S_noto  S_noto_850_1 = {&R8IS11LDU,&var1434};
_S_charint  S_charint_797_1 = {&var1437,&var1435};
_S_ornc  S_ornc_806_1 = {array_m806_x_1,&iRM_3_,&var1436,&var1437};
_S_fsumz  S_fsumz_798_1 = {&var1435,&iRM_1_,&var1438};
_S_cnshd  S_cnshd_807_1 = {&R0MD34LP1,&var1732,&var987,&var987,&var1436,&var703,&var617,&iRM_2_,array_m807_Lt_fw_1,array_m807_Vr_fw_1,&iRM_1_,array_m807_Lt_bw_1,array_m807_Vr_bw_1,&fEM_A2UC08RDU,&fEM_A2UC07RDU,&fEM_A2UL01RDU,&fEM_A2UC02RDU,&var1439,&vainSBool,&var1440,&var1441,&var1442,&var1443,&var1444,&var1445,&var1446,&var1447,&var1448,&var1449,&internal1_m807_X0,&internal1_m807_t0,&internal1_m807_BLDv0};
_S_fnapb  S_fnapb_827_1 = {&var1732,&var987,&var699,&R0MD34LP1,&var1441,&var1448,&fEM_B8UV04RDU,&fEM_A2UV01RDU,&fEM_A2UV02RDU,&fEM_A2UC06RDU,&fEM_A2UC05RDU,&iRM_80_,&fEM_A2UL04RDU,&fEM_A2UL05RDU,&fEM_A2UL83RDU,&var1450,&var1451,&var1452,&var1453,&var1454,&var1455,&var1456,&vainSFloat,&internal1_m827_xptr,array_m827_x0_1,array_m827_tim0_1,&internal1_m827_sumtim,&internal1_m827_StSpeed,&internal1_m827_Vz0,&internal1_m827_flRazg,&internal1_m827_DelSp,&internal1_m827_z0,&internal1_m827_txZS,&internal1_m827_tx,&internal1_m827_txd,&internal1_m827_txMBl,&internal1_m827_txBl,&internal1_m827_Speed0,&internal1_m827_xz0,&internal1_m827_tz0,&internal1_m827_Shift0,&internal1_m827_ShCntlSp0,&internal1_m827_ShiftControl,&bFirstEnterFlag};
_S_cnshd  S_cnshd_1571_1 = {&R0MD34LP1,&var1723,&var309,&var309,&var526,&var529,&lRM_1_,&iRM_1_,array_m1571_Lt_fw_1,array_m1571_Vr_fw_1,&iRM_1_,array_m1571_Lt_bw_1,array_m1571_Vr_bw_1,&fEM_B8UC01RDU,&fEM_B8UC02RDU,&fEM_B8UL01RDU,&fRM_0_0,&var1457,&vainSBool,&vainSFloat,&var1458,&var1459,&var1460,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1461,&internal1_m1571_X0,&internal1_m1571_t0,&internal1_m1571_BLDv0};
_S_newstage  S_newstage_1232_1 = {&var1475,&var1436,&var1480,&var1439,&var1462};
_S_orn  S_orn_1262_1 = {array_m1262_x_1,&iRM_10_,&var1463};
_S_orn  S_orn_146_1 = {array_m146_x_1,&iRM_5_,&var1464};
_S_noto  S_noto_1261_1 = {&var1457,&var1465};
_S_noto  S_noto_1260_1 = {&var1467,&var1466};
_S_cnshd  S_cnshd_1107_1 = {&R0MD34LP1,&var1720,&var309,&var309,&var844,&var527,&lRM_1_,&iRM_1_,array_m1107_Lt_fw_1,array_m1107_Vr_fw_1,&iRM_1_,array_m1107_Lt_bw_1,array_m1107_Vr_bw_1,&fEM_B8UC01RDU,&fEM_B8UC02RDU,&fEM_B8UL01RDU,&fRM_0_0,&var1467,&vainSBool,&vainSFloat,&var1468,&var1469,&var1470,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1471,&internal1_m1107_X0,&internal1_m1107_t0,&internal1_m1107_BLDv0};
_S_noto  S_noto_1241_1 = {&var959,&var1472};
_S_noto  S_noto_1252_1 = {&R8IS11LDU,&var1473};
_S_charint  S_charint_1182_1 = {&var1476,&var1474};
_S_ornc  S_ornc_1190_1 = {array_m1190_x_1,&iRM_3_,&var1475,&var1476};
_S_noto  S_noto_600_1 = {&lEM_R0MD01LC1,&var1477};
_S_fsumz  S_fsumz_1183_1 = {&var1474,&iRM_1_,&var1478};
_S_rs  S_rs_613_1 = {&var795,&var797,&var1479,&vainSBool,&internal1_m613_q0};
_S_cnshd  S_cnshd_1192_1 = {&R0MD34LP1,&var1735,&var986,&var986,&var1475,&var620,&var613,&iRM_2_,array_m1192_Lt_fw_1,array_m1192_Vr_fw_1,&iRM_1_,array_m1192_Lt_bw_1,array_m1192_Vr_bw_1,&fEM_A2UC08RDU,&fEM_A2UC07RDU,&fEM_A2UL01RDU,&fEM_A2UC02RDU,&var1480,&vainSBool,&var1481,&var1482,&var1483,&var1484,&var1485,&var1486,&var1487,&var1488,&var1489,&var1490,&internal1_m1192_X0,&internal1_m1192_t0,&internal1_m1192_BLDv0};
_S_zpfs  S_zpfs_1212_1 = {&var1499,&fRM_2_0,&var1491,&internal1_m1212_tx,&internal1_m1212_y0};
_S_zpfs  S_zpfs_1220_1 = {&var1498,&fRM_3_0,&var1492,&internal1_m1220_tx,&internal1_m1220_y0};
_S_fnapb  S_fnapb_1226_1 = {&var1735,&var986,&var621,&R0MD34LP1,&var1482,&var1489,&fEM_B8UV04RDU,&fEM_A2UV01RDU,&fEM_A2UV02RDU,&fEM_A2UC06RDU,&fEM_A2UC05RDU,&iRM_80_,&fEM_A2UL04RDU,&fEM_A2UL05RDU,&fEM_A2UL03RDU,&var1493,&var1494,&var1495,&var1496,&var1497,&var1498,&var1499,&vainSFloat,&internal1_m1226_xptr,array_m1226_x0_1,array_m1226_tim0_1,&internal1_m1226_sumtim,&internal1_m1226_StSpeed,&internal1_m1226_Vz0,&internal1_m1226_flRazg,&internal1_m1226_DelSp,&internal1_m1226_z0,&internal1_m1226_txZS,&internal1_m1226_tx,&internal1_m1226_txd,&internal1_m1226_txMBl,&internal1_m1226_txBl,&internal1_m1226_Speed0,&internal1_m1226_xz0,&internal1_m1226_tz0,&internal1_m1226_Shift0,&internal1_m1226_ShCntlSp0,&internal1_m1226_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_1556_1 = {&R8IS11LDU,&var1500};
_S_rs  S_rs_633_1 = {&var798,&var799,&var1501,&vainSBool,&internal1_m633_q0};
_S_zpfs  S_zpfs_1584_1 = {&var1512,&fRM_2_0,&var1502,&internal1_m1584_tx,&internal1_m1584_y0};
_S_zpfs  S_zpfs_1586_1 = {&var1511,&fRM_3_0,&var1503,&internal1_m1586_tx,&internal1_m1586_y0};
_S_samhd  S_samhd_1574_1 = {&R0MD34LP1,&var529,&var529,&var1459,&var1460,&var1506,&var1507,&A8IS12LDU,&A8IS12LDU,&A8IS22LDU,&A8IS22LDU,&bRM_3_,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&fEM_B8UL07RDU,&vainSBool,&vainSBool,&var1504,&var1505,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,&internal1_m1574_DvUp0,&internal1_m1574_DvDw0,&internal1_m1574_FDvUp0,&internal1_m1574_FDvDw0,&internal1_m1574_BlDv0,&internal1_m1574_Pkv0,&internal1_m1574_Pkav0,&internal1_m1574_Zkv0,&internal1_m1574_Zkav0,&internal1_m1574_txNm,&internal1_m1574_txSm,&internal1_m1574_txHr,&internal1_m1574_txLd,&internal1_m1574_fef,&bFirstEnterFlag};
_S_fnapb  S_fnapb_1591_1 = {&var1723,&var309,&var525,&R0MD34LP1,&var1458,&fEM_B8UV03RDU,&fEM_B8UV04RDU,&fEM_B8UV01RDU,&fEM_B8UV02RDU,&fEM_B8UC06RDU,&fEM_B8UC05RDU,&iRM_20_,&fEM_B8UL04RDU,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&var1506,&var1507,&var1508,&var1509,&var1510,&var1511,&var1512,&vainSFloat,&internal1_m1591_xptr,array_m1591_x0_1,array_m1591_tim0_1,&internal1_m1591_sumtim,&internal1_m1591_StSpeed,&internal1_m1591_Vz0,&internal1_m1591_flRazg,&internal1_m1591_DelSp,&internal1_m1591_z0,&internal1_m1591_txZS,&internal1_m1591_tx,&internal1_m1591_txd,&internal1_m1591_txMBl,&internal1_m1591_txBl,&internal1_m1591_Speed0,&internal1_m1591_xz0,&internal1_m1591_tz0,&internal1_m1591_Shift0,&internal1_m1591_ShCntlSp0,&internal1_m1591_ShiftControl,&bFirstEnterFlag};
_S_zpfs  S_zpfs_1123_1 = {&var1529,&fRM_2_0,&var1513,&internal1_m1123_tx,&internal1_m1123_y0};
_S_zpfs  S_zpfs_1128_1 = {&var1528,&fRM_3_0,&var1514,&internal1_m1128_tx,&internal1_m1128_y0};
_S_noto  S_noto_1092_1 = {&R8IS11LDU,&var1515};
_S_orn  S_orn_1078_1 = {array_m1078_x_1,&iRM_8_,&var1516};
_S_noto  S_noto_602_1 = {&var1520,&var1517};
_S_rs  S_rs_623_1 = {&var800,&var801,&var1518,&vainSBool,&internal1_m623_q0};
_S_orn  S_orn_590_1 = {array_m590_x_1,&iRM_18_,&var1519};
_S_rs  S_rs_588_1 = {&var1284,&var916,&var1520,&vainSBool,&internal1_m588_q0};
_S_samhd  S_samhd_1115_1 = {&R0MD34LP1,&var527,&var527,&var1469,&var1470,&var1523,&var1524,&var152,&var152,&var151,&var151,&bRM_3_,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&fEM_B8UL07RDU,&vainSBool,&vainSBool,&var1521,&var1522,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,&internal1_m1115_DvUp0,&internal1_m1115_DvDw0,&internal1_m1115_FDvUp0,&internal1_m1115_FDvDw0,&internal1_m1115_BlDv0,&internal1_m1115_Pkv0,&internal1_m1115_Pkav0,&internal1_m1115_Zkv0,&internal1_m1115_Zkav0,&internal1_m1115_txNm,&internal1_m1115_txSm,&internal1_m1115_txHr,&internal1_m1115_txLd,&internal1_m1115_fef,&bFirstEnterFlag};
_S_fnapb  S_fnapb_1131_1 = {&var1720,&var309,&var843,&R0MD34LP1,&var1468,&fEM_B8UV03RDU,&fEM_B8UV04RDU,&fEM_B8UV01RDU,&fEM_B8UV02RDU,&fEM_B8UC06RDU,&fEM_B8UC05RDU,&iRM_20_,&fEM_B8UL04RDU,&fEM_B8UL06RDU,&fEM_B8UL03RDU,&var1523,&var1524,&var1525,&var1526,&var1527,&var1528,&var1529,&vainSFloat,&internal1_m1131_xptr,array_m1131_x0_1,array_m1131_tim0_1,&internal1_m1131_sumtim,&internal1_m1131_StSpeed,&internal1_m1131_Vz0,&internal1_m1131_flRazg,&internal1_m1131_DelSp,&internal1_m1131_z0,&internal1_m1131_txZS,&internal1_m1131_tx,&internal1_m1131_txd,&internal1_m1131_txMBl,&internal1_m1131_txBl,&internal1_m1131_Speed0,&internal1_m1131_xz0,&internal1_m1131_tz0,&internal1_m1131_Shift0,&internal1_m1131_ShCntlSp0,&internal1_m1131_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_713_1 = {&A5IS21LDU,&var1530};
_S_vmemb  S_vmemb_736_1 = {&var1532,&var1531,&internal1_m736_x0};
_S_noto  S_noto_744_1 = {&var153,&var1532};
_S_vmemb  S_vmemb_705_1 = {&var1530,&var1533,&internal1_m705_x0};
_S_vmemb  S_vmemb_669_1 = {&var1548,&var1534,&internal1_m669_x0};
_S_newstage  S_newstage_779_1 = {&var1592,&var1583,&var1591,&var1582,&var1535};
_S_newstage  S_newstage_1164_1 = {&var1574,&var1565,&var1573,&var1564,&var1536};
_S_newstage  S_newstage_385_1 = {&var1619,&var1610,&var1618,&var1609,&var1537};
_S_noto  S_noto_755_1 = {&var154,&var1538};
_S_rs  S_rs_761_1 = {&var864,&var1537,&var1539,&vainSBool,&internal1_m761_q0};
_S_rs  S_rs_756_1 = {&var865,&var965,&var1540,&vainSBool,&internal1_m756_q0};
_S_noto  S_noto_748_1 = {&var1621,&var1541};
_S_noto  S_noto_746_1 = {&var1622,&var1542};
_S_rs  S_rs_724_1 = {&var869,&var1537,&var1543,&vainSBool,&internal1_m724_q0};
_S_rs  S_rs_729_1 = {&var868,&var1535,&var1544,&vainSBool,&internal1_m729_q0};
_S_rs  S_rs_737_1 = {&var935,&var874,&var1545,&vainSBool,&internal1_m737_q0};
_S_rs  S_rs_749_1 = {&var866,&var872,&var1546,&vainSBool,&internal1_m749_q0};
_S_noto  S_noto_704_1 = {&var154,&var1547};
_S_noto  S_noto_660_1 = {&var153,&var1548};
_S_noto  S_noto_416_1 = {&R8IS11LDU,&var1549};
_S_orn  S_orn_430_1 = {array_m430_x_1,&iRM_7_,&var1550};
_S_orn  S_orn_412_1 = {array_m412_x_1,&iRM_7_,&var1551};
_S_rs  S_rs_727_1 = {&var873,&var878,&var1552,&vainSBool,&internal1_m727_q0};
_S_noto  S_noto_154_1 = {&B2IS12LDU,&var1553};
_S_noto  S_noto_143_1 = {&A2IS12LDU,&var1554};
_S_noto  S_noto_144_1 = {&B1IS12LDU,&var1555};
_S_noto  S_noto_152_1 = {&A1IS12LDU,&var1556};
_S_samhd  S_samhd_1168_1 = {&var847,&var848,&var848,&var1157,&var1156,&var1157,&var1156,&B4IS11LDU,&B4IS11LDU,&B4IS21LDU,&B4IS21LDU,&bRM_1_,&fEM_A4UZ05RDU,&fEM_A4UZ03RDU,&fEM_A4UZ04RDU,&var1557,&var1558,&vainSBool,&var1559,&var1560,&vainSBool,&var1561,&var1562,&var1563,&var1564,&var1565,&internal1_m1168_DvUp0,&internal1_m1168_DvDw0,&internal1_m1168_FDvUp0,&internal1_m1168_FDvDw0,&internal1_m1168_BlDv0,&internal1_m1168_Pkv0,&internal1_m1168_Pkav0,&internal1_m1168_Zkv0,&internal1_m1168_Zkav0,&internal1_m1168_txNm,&internal1_m1168_txSm,&internal1_m1168_txHr,&internal1_m1168_txLd,&internal1_m1168_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_1158_1 = {&var847,&var850,&var850,&var1157,&var1156,&var1157,&var1156,&A4IS11LDU,&A4IS11LDU,&A4IS21LDU,&A4IS21LDU,&bRM_1_,&fEM_A4UZ05RDU,&fEM_A4UZ03RDU,&fEM_A4UZ04RDU,&var1566,&var1567,&vainSBool,&var1568,&var1569,&vainSBool,&var1570,&var1571,&var1572,&var1573,&var1574,&internal1_m1158_DvUp0,&internal1_m1158_DvDw0,&internal1_m1158_FDvUp0,&internal1_m1158_FDvDw0,&internal1_m1158_BlDv0,&internal1_m1158_Pkv0,&internal1_m1158_Pkav0,&internal1_m1158_Zkv0,&internal1_m1158_Zkav0,&internal1_m1158_txNm,&internal1_m1158_txSm,&internal1_m1158_txHr,&internal1_m1158_txLd,&internal1_m1158_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_781_1 = {&R0MD34LP1,&var705,&var705,&var966,&var861,&B5VS12LDU,&B5VS22LDU,&B5IS11LDU,&B5IS11LDU,&B5IS21LDU,&B5IS21LDU,&bRM_0_,&fEM_A5UZ05RDU,&fEM_A5UZ03RDU,&fEM_A5UZ04RDU,&var1575,&var1576,&var1577,&var1578,&var1579,&var1580,&vainSBool,&vainSBool,&var1581,&var1582,&var1583,&internal1_m781_DvUp0,&internal1_m781_DvDw0,&internal1_m781_FDvUp0,&internal1_m781_FDvDw0,&internal1_m781_BlDv0,&internal1_m781_Pkv0,&internal1_m781_Pkav0,&internal1_m781_Zkv0,&internal1_m781_Zkav0,&internal1_m781_txNm,&internal1_m781_txSm,&internal1_m781_txHr,&internal1_m781_txLd,&internal1_m781_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_777_1 = {&R0MD34LP1,&var707,&var707,&var966,&var861,&A5VS12LDU,&A5VS22LDU,&A5IS11LDU,&A5IS11LDU,&A5IS21LDU,&A5IS21LDU,&bRM_0_,&fEM_A5UZ05RDU,&fEM_A5UZ03RDU,&fEM_A5UZ04RDU,&var1584,&var1585,&var1586,&var1587,&var1588,&var1589,&vainSBool,&vainSBool,&var1590,&var1591,&var1592,&internal1_m777_DvUp0,&internal1_m777_DvDw0,&internal1_m777_FDvUp0,&internal1_m777_FDvDw0,&internal1_m777_BlDv0,&internal1_m777_Pkv0,&internal1_m777_Pkav0,&internal1_m777_Zkv0,&internal1_m777_Zkav0,&internal1_m777_txNm,&internal1_m777_txSm,&internal1_m777_txHr,&internal1_m777_txLd,&internal1_m777_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_359_1 = {&R0MD34LP1,&var378,&var377,&var870,&var863,&R4VS12LDU,&R4VS22LDU,&R4IS11LDU,&R4IS12LDU,&R4IS21LDU,&R4IS22LDU,&bRM_0_,&fEM_R4UZ05RDU,&fEM_R4UZ03RDU,&fEM_R4UZ04RDU,&var1593,&var1594,&var1595,&var1596,&var1597,&var1598,&vainSBool,&vainSBool,&var1599,&var1600,&vainSBool,&internal1_m359_DvUp0,&internal1_m359_DvDw0,&internal1_m359_FDvUp0,&internal1_m359_FDvDw0,&internal1_m359_BlDv0,&internal1_m359_Pkv0,&internal1_m359_Pkav0,&internal1_m359_Zkv0,&internal1_m359_Zkav0,&internal1_m359_txNm,&internal1_m359_txSm,&internal1_m359_txHr,&internal1_m359_txLd,&internal1_m359_fef,&bFirstEnterFlag};
_S_noto  S_noto_671_1 = {&R8IS11LDU,&var1601};
_S_samhd  S_samhd_388_1 = {&R0MD34LP1,&var1550,&var936,&var942,&var862,&B6VS12LDU,&B6VS22LDU,&B6IS11LDU,&B6IS11LDU,&B6IS21LDU,&B6IS21LDU,&bRM_0_,&fEM_A6UZ05RDU,&fEM_A6UZ03RDU,&fEM_A6UZ04RDU,&var1602,&var1603,&var1604,&var1605,&var1606,&var1607,&vainSBool,&vainSBool,&var1608,&var1609,&var1610,&internal1_m388_DvUp0,&internal1_m388_DvDw0,&internal1_m388_FDvUp0,&internal1_m388_FDvDw0,&internal1_m388_BlDv0,&internal1_m388_Pkv0,&internal1_m388_Pkav0,&internal1_m388_Zkv0,&internal1_m388_Zkav0,&internal1_m388_txNm,&internal1_m388_txSm,&internal1_m388_txHr,&internal1_m388_txLd,&internal1_m388_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_382_1 = {&R0MD34LP1,&var1551,&var937,&var942,&var862,&A6VS12LDU,&A6VS22LDU,&A6IS11LDU,&A6IS11LDU,&A6IS21LDU,&A6IS21LDU,&bRM_0_,&fEM_A6UZ05RDU,&fEM_A6UZ03RDU,&fEM_A6UZ04RDU,&var1611,&var1612,&var1613,&var1614,&var1615,&var1616,&vainSBool,&vainSBool,&var1617,&var1618,&var1619,&internal1_m382_DvUp0,&internal1_m382_DvDw0,&internal1_m382_FDvUp0,&internal1_m382_FDvDw0,&internal1_m382_BlDv0,&internal1_m382_Pkv0,&internal1_m382_Pkav0,&internal1_m382_Zkv0,&internal1_m382_Zkav0,&internal1_m382_txNm,&internal1_m382_txSm,&internal1_m382_txHr,&internal1_m382_txLd,&internal1_m382_fef,&bFirstEnterFlag};
_S_orn  S_orn_760_1 = {array_m760_x_1,&iRM_17_,&var1620};
_S_rs  S_rs_733_1 = {&var876,&var63,&var1621,&vainSBool,&internal1_m733_q0};
_S_rs  S_rs_730_1 = {&var877,&var64,&var1622,&vainSBool,&internal1_m730_q0};
_S_orni  S_orni_132_1 = {array_m132_x_1,&iRM_21_,&var1623,&vainSLong};
_S_equz_p  S_equz_p_74_1 = {&R0MW11IP2,&iRM_6_,&var1624};
_S_equz_p  S_equz_p_72_1 = {&R0MW11IP2,&iRM_5_,&var1625};
_S_equz_p  S_equz_p_70_1 = {&R0MW11IP2,&iRM_4_,&var1626};
_S_equz_p  S_equz_p_69_1 = {&R0MW11IP2,&iRM_3_,&var1627};
_S_equz_p  S_equz_p_68_1 = {&R0MW11IP2,&iRM_2_,&var1628};
_S_equz_p  S_equz_p_65_1 = {&R0MW11IP2,&iRM_1_,&var1629};
_S_equz_p  S_equz_p_61_1 = {&R0MW14IP1,&iRM_3_,&var1630};
_S_equz_p  S_equz_p_55_1 = {&R0MW14IP1,&iRM_1_,&vainSBool};
_S_equz_p  S_equz_p_57_1 = {&R0MW14IP1,&iRM_2_,&var1631};
_S_equz_p  S_equz_p_50_1 = {&R0MW11IP1,&iRM_3_,&var1632};
_S_equz_p  S_equz_p_43_1 = {&R0MW11IP1,&iRM_1_,&var1633};
_S_equz_p  S_equz_p_46_1 = {&R0MW11IP1,&iRM_2_,&var1634};
_S_equz_p  S_equz_p_100_1 = {&R0MW16IP1,&iRM_11_,&var1635};
_S_equz_p  S_equz_p_93_1 = {&R0MW16IP1,&iRM_4_,&var1636};
_S_equz_p  S_equz_p_92_1 = {&R0MW16IP1,&iRM_3_,&var1637};
_S_equz_p  S_equz_p_91_1 = {&R0MW16IP1,&iRM_2_,&var1638};
_S_equz_p  S_equz_p_10_1 = {&R0MW12IP1,&iRM_4_,&var1639};
_S_equz_p  S_equz_p_7_1 = {&R0MW12IP1,&iRM_3_,&var1640};
_S_equz_p  S_equz_p_2_1 = {&R0MW12IP1,&iRM_1_,&var1641};
_S_equz_p  S_equz_p_4_1 = {&R0MW12IP1,&iRM_2_,&var1642};


int freebuff = 0, delay = 0;
void Scheme()
{
if ((getAsShort(idR0MW11IP1) == 2) || (getAsShort(idR0MW11IP1) == 3)) { 
     if(delay++ < 300) return;
     freebuff = 0;
     delay = delay > 32000 ? 32000 : delay; 
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  equz_p(&S_equz_p_18_2);
  andn(&S_andn_131_2);
  noto(&S_noto_134_2);
  andn(&S_andn_150_2);
  noto(&S_noto_153_2);
  scalzz(&S_scalzz_184_2);
  scalzz(&S_scalzz_186_2);
  or2(&S_or2_11_2);
  or2(&S_or2_42_2);
  or2(&S_or2_13_2);
  or2(&S_or2_43_2);
  or2(&S_or2_74_2);
  or2(&S_or2_71_2);
  and3(&S_and3_79_2);
  or2(&S_or2_103_2);
  or2(&S_or2_104_2);
  and3(&S_and3_110_2);
  and4(&S_and4_136_2);
  and4(&S_and4_159_2);
  schl24(&S_schl24_143_2);
  schl24(&S_schl24_149_2);
  noto(&S_noto_229_2);
  noto(&S_noto_230_2);
  noto(&S_noto_231_2);
  noto(&S_noto_249_2);
  noto(&S_noto_250_2);
  noto(&S_noto_251_2);
  fsumo(&S_fsumo_222_2);
  bol(&S_bol_223_2);
  lkb(&S_lkb_80_2);
  lkb(&S_lkb_111_2);
  and4(&S_and4_106_2);
  enctkb(&S_enctkb_75_2);
  enctkb(&S_enctkb_112_2);
  drg(&S_drg_196_2);
  drg(&S_drg_189_2);
  geterr(&S_geterr_188_2);
  drg(&S_drg_206_2);
  drg(&S_drg_199_2);
  geterr(&S_geterr_191_2);
  tprg(&S_tprg_210_2);
  tprg(&S_tprg_216_2);
  noto(&S_noto_220_2);
  noto(&S_noto_212_2);
  andn(&S_andn_170_2);
  noto(&S_noto_171_2);
  and2(&S_and2_219_2);
  and3(&S_and3_19_2);
  and3(&S_and3_45_2);
  and3(&S_and3_23_2);
  and3(&S_and3_49_2);
  and3(&S_and3_82_2);
  or3(&S_or3_135_2);
  or3(&S_or3_158_2);
  and2(&S_and2_213_2);
  or2(&S_or2_195_2);
  or2(&S_or2_198_2);
  lkb(&S_lkb_20_2);
  lkb(&S_lkb_24_2);
  lkb(&S_lkb_46_2);
  lkb(&S_lkb_83_2);
  lkb(&S_lkb_50_2);
  lkb(&S_lkb_107_2);
  enctkb(&S_enctkb_21_2);
  enctkb(&S_enctkb_51_2);
  enctkb(&S_enctkb_47_2);
  enctkb(&S_enctkb_77_2);
  enctkb(&S_enctkb_108_2);
  enctkb(&S_enctkb_16_2);
  noto(&S_noto_141_2);
  noto(&S_noto_157_2);
  and2(&S_and2_233_2);
  and2(&S_and2_254_2);
  ornc(&S_ornc_124_2);
  ornc(&S_ornc_234_2);
  ornc(&S_ornc_255_2);
  noto(&S_noto_240_2);
  noto(&S_noto_256_2);
  or2(&S_or2_258_2);
  ornc(&S_ornc_232_2);
  ornc(&S_ornc_243_2);
  noto(&S_noto_235_2);
  noto(&S_noto_253_2);
  or2(&S_or2_244_2);
  setData(idR0EE02LDU,&var814);
  setData(idB8VC01RDU,&var1720);
  setData(idB2VC01RDU,&var1732);
  setData(idA2VC01RDU,&var1735);
  setData(idA3VC01RDU,&var1729);
  setData(idB0VS11LDU,&var1697);
  setData(idA0VS11LDU,&var1698);
  setData(idB0VN01LDU,&var1667);
  setData(idA0VN01LDU,&var1669);
  setData(idB0VP01LDU,&var1703);
  setData(idA0VP01LDU,&var1704);
  setData(idB0VE01LDU,&var1694);
  setData(idA0VE01LDU,&var1696);
  setData(idA3VP82LDU,&var1665);
  setData(idB3VP82LDU,&var1688);
  setData(idB3VP52LDU,&var1713);
  setData(idB3CP02RDU,&var1689);
  setData(idB3VP42LDU,&var1663);
  setData(idA3VP52LDU,&var1716);
  setData(idA3CP02RDU,&var1690);
  setData(idA3VP42LDU,&var1664);
  setData(idA1VC01RDU,&var1717);
  setData(idA8VC01RDU,&var1723);
  setData(idB3VC01RDU,&var1726);
  setData(idB1VC01RDU,&var1739);
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
  noto(&S_noto_746_1);
  noto(&S_noto_713_1);
  noto(&S_noto_1092_1);
  noto(&S_noto_1556_1);
  noto(&S_noto_1252_1);
  noto(&S_noto_850_1);
  noto(&S_noto_218_1);
  noto(&S_noto_535_1);
  noto(&S_noto_945_1);
  rs(&S_rs_618_1);
  noto(&S_noto_1342_1);
  equz_p(&S_equz_p_32_1);
  equz_p(&S_equz_p_41_1);
  noto(&S_noto_34_1);
  equz_p(&S_equz_p_37_1);
  rs(&S_rs_1466_1);
  noto(&S_noto_1761_1);
  noto(&S_noto_1760_1);
  noto(&S_noto_1766_1);
  noto(&S_noto_1762_1);
  noto(&S_noto_1768_1);
  noto(&S_noto_1739_1);
  noto(&S_noto_1740_1);
  noto(&S_noto_1741_1);
  noto(&S_noto_1742_1);
  noto(&S_noto_1743_1);
  noto(&S_noto_2055_1);
  equz_p(&S_equz_p_94_1);
  equz_p(&S_equz_p_95_1);
  equz_p(&S_equz_p_96_1);
  noto(&S_noto_922_1);
  equz_p(&S_equz_p_97_1);
  equz_p(&S_equz_p_98_1);
  noto(&S_noto_178_1);
  equz_p(&S_equz_p_99_1);
  noto(&S_noto_12_1);
  noto(&S_noto_1839_1);
  equz_p(&S_equz_p_1783_1);
  equz_p(&S_equz_p_1782_1);
  equz_p(&S_equz_p_1784_1);
  equz_p(&S_equz_p_1785_1);
  equz_p(&S_equz_p_1786_1);
  noto(&S_noto_1748_1);
  noto(&S_noto_1801_1);
  noto(&S_noto_1820_1);
  rs(&S_rs_608_1);
  noto(&S_noto_1780_1);
  noto(&S_noto_1806_1);
  noto(&S_noto_1319_1);
  rsun(&S_rsun_1392_1);
  rs(&S_rs_610_1);
  rs(&S_rs_612_1);
  rs(&S_rs_628_1);
  rs(&S_rs_644_1);
  rs(&S_rs_617_1);
  rs(&S_rs_632_1);
  rs(&S_rs_26_1);
  rs(&S_rs_1461_1);
  rs(&S_rs_1416_1);
  rs(&S_rs_1872_1);
  noto(&S_noto_1411_1);
  noto(&S_noto_1451_1);
  noto(&S_noto_1456_1);
  noto(&S_noto_1830_1);
  noto(&S_noto_1867_1);
  noto(&S_noto_1890_1);
  noto(&S_noto_1852_1);
  noto(&S_noto_579_1);
  noto(&S_noto_22_1);
  noto(&S_noto_23_1);
  noto(&S_noto_24_1);
  noto(&S_noto_25_1);
  noto(&S_noto_582_1);
  noto(&S_noto_580_1);
  noto(&S_noto_49_1);
  noto(&S_noto_258_1);
  noto(&S_noto_261_1);
  noto(&S_noto_270_1);
  noto(&S_noto_275_1);
  noto(&S_noto_266_1);
  noto(&S_noto_979_1);
  noto(&S_noto_985_1);
  noto(&S_noto_1921_1);
  noto(&S_noto_1923_1);
  rs(&S_rs_1062_1);
  rs(&S_rs_1065_1);
  rs(&S_rs_1068_1);
  rs(&S_rs_1071_1);
  ovbs(&S_ovbs_1166_1);
  ovbs(&S_ovbs_2077_1);
  sr(&S_sr_1056_1);
  bol(&S_bol_1049_1);
  ma(&S_ma_84_1);
  sr(&S_sr_82_1);
  bol(&S_bol_255_1);
  bol(&S_bol_253_1);
  bol(&S_bol_1371_1);
  bol(&S_bol_1369_1);
  bol(&S_bol_974_1);
  bol(&S_bol_972_1);
  bol(&S_bol_567_1);
  bol(&S_bol_569_1);
  bol(&S_bol_578_1);
  bol(&S_bol_584_1);
  and2(&S_and2_734_1);
  and2(&S_and2_27_1);
  and2(&S_and2_28_1);
  and2(&S_and2_29_1);
  and2(&S_and2_30_1);
  and2(&S_and2_42_1);
  and2(&S_and2_38_1);
  and2(&S_and2_725_1);
  or4(&S_or4_415_1);
  or2(&S_or2_738_1);
  or3(&S_or3_5_1);
  or2(&S_or2_6_1);
  or2(&S_or2_1265_1);
  or2(&S_or2_863_1);
  or2(&S_or2_232_1);
  or2(&S_or2_549_1);
  or2(&S_or2_957_1);
  or2(&S_or2_1354_1);
  or2(&S_or2_1055_1);
  and2(&S_and2_1048_1);
  or2(&S_or2_20_1);
  or2(&S_or2_39_1);
  or2(&S_or2_35_1);
  or2(&S_or2_48_1);
  or2(&S_or2_685_1);
  or3(&S_or3_673_1);
  or4(&S_or4_687_1);
  or2(&S_or2_700_1);
  or3(&S_or3_720_1);
  and2(&S_and2_745_1);
  and2(&S_and2_719_1);
  or2(&S_or2_726_1);
  or2(&S_or2_655_1);
  or2(&S_or2_657_1);
  or2(&S_or2_659_1);
  or2(&S_or2_1142_1);
  or2(&S_or2_1167_1);
  and4(&S_and4_1060_1);
  or2(&S_or2_1059_1);
  and2(&S_and2_1074_1);
  or2(&S_or2_1088_1);
  and3(&S_and3_259_1);
  and3(&S_and3_274_1);
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
  or2(&S_or2_341_1);
  or2(&S_or2_346_1);
  or2(&S_or2_743_1);
  or2(&S_or2_457_1);
  or2(&S_or2_515_1);
  and2(&S_and2_524_1);
  and2(&S_and2_525_1);
  and2(&S_and2_534_1);
  or2(&S_or2_527_1);
  or2(&S_or2_196_1);
  and2(&S_and2_176_1);
  and2(&S_and2_208_1);
  and2(&S_and2_207_1);
  or2(&S_or2_210_1);
  and2(&S_and2_217_1);
  or2(&S_or2_780_1);
  or2(&S_or2_826_1);
  or2(&S_or2_841_1);
  and2(&S_and2_916_1);
  or2(&S_or2_927_1);
  or2(&S_or2_919_1);
  or2(&S_or2_936_1);
  or2(&S_or2_1333_1);
  or2(&S_or2_1316_1);
  and2(&S_and2_1313_1);
  or2(&S_or2_1324_1);
  or2(&S_or2_1243_1);
  or2(&S_or2_1224_1);
  and2(&S_and2_984_1);
  and2(&S_and2_1412_1);
  zpfs(&S_zpfs_1422_1);
  and2(&S_and2_1452_1);
  zpfs(&S_zpfs_1472_1);
  and2(&S_and2_1457_1);
  zpfs(&S_zpfs_1478_1);
  and2(&S_and2_1494_1);
  or2(&S_or2_2078_1);
  or2(&S_or2_1601_1);
  or2(&S_or2_1602_1);
  or2(&S_or2_1552_1);
  or2(&S_or2_1746_1);
  or2(&S_or2_1747_1);
  or4(&S_or4_1753_1);
  or4(&S_or4_1754_1);
  or2(&S_or2_1756_1);
  or2(&S_or2_1750_1);
  or2(&S_or2_1749_1);
  or3(&S_or3_1758_1);
  and2(&S_and2_1787_1);
  or2(&S_or2_1788_1);
  and2(&S_and2_1794_1);
  and2(&S_and2_1810_1);
  or2(&S_or2_1821_1);
  zpfs(&S_zpfs_1790_1);
  zpfs(&S_zpfs_1791_1);
  zpfs(&S_zpfs_1792_1);
  zpfs(&S_zpfs_1793_1);
  or2(&S_or2_1796_1);
  and2(&S_and2_1797_1);
  or2(&S_or2_1812_1);
  or3(&S_or3_1798_1);
  or2(&S_or2_1873_1);
  ma(&S_ma_1447_1);
  zpfs(&S_zpfs_1843_1);
  and2(&S_and2_1844_1);
  or2(&S_or2_1838_1);
  and3(&S_and3_1841_1);
  or2(&S_or2_1849_1);
  or2(&S_or2_234_1);
  ovbs(&S_ovbs_77_1);
  ovbs(&S_ovbs_21_1);
  ovbs(&S_ovbs_120_1);
  ovbs(&S_ovbs_113_1);
  ovbs(&S_ovbs_1406_1);
  ovbs(&S_ovbs_741_1);
  ovbs(&S_ovbs_292_1);
  ovbs(&S_ovbs_337_1);
  ovbs(&S_ovbs_51_1);
  or2(&S_or2_1985_1);
  or2(&S_or2_1973_1);
  noto(&S_noto_2003_1);
  bol(&S_bol_1538_1);
  bol(&S_bol_1532_1);
  or2(&S_or2_1534_1);
  bol(&S_bol_1522_1);
  bol(&S_bol_1512_1);
  or2(&S_or2_1516_1);
  bol(&S_bol_1540_1);
  bol(&S_bol_1530_1);
  or2(&S_or2_1536_1);
  bol(&S_bol_1524_1);
  bol(&S_bol_1517_1);
  or2(&S_or2_1519_1);
  and4(&S_and4_45_1);
  abs_subf(&S_abs_subf_1529_1);
  noto(&S_noto_1535_1);
  and2(&S_and2_233_1);
  and2(&S_and2_550_1);
  and2(&S_and2_2233_1);
  rs(&S_rs_2182_1);
  sr(&S_sr_2220_1);
  sr(&S_sr_2199_1);
  rs(&S_rs_2176_1);
  zpfs(&S_zpfs_2204_1);
  or2(&S_or2_2192_1);
  abs_subf(&S_abs_subf_2157_1);
  and2(&S_and2_2164_1);
  noto(&S_noto_890_1);
  zzfs(&S_zzfs_2165_1);
  noto(&S_noto_2177_1);
  or2(&S_or2_1072_1);
  or2(&S_or2_366_1);
  or2(&S_or2_349_1);
  or2(&S_or2_1104_1);
  or2(&S_or2_1111_1);
  or2(&S_or2_230_1);
  or2(&S_or2_547_1);
  nocnm(&S_nocnm_1697_1);
  nocnm(&S_nocnm_1698_1);
  noto(&S_noto_1654_1);
  noto(&S_noto_1656_1);
  noto(&S_noto_2149_1);
  noto(&S_noto_2117_1);
  or2(&S_or2_1419_1);
  or2(&S_or2_1450_1);
  noto(&S_noto_2152_1);
  noto(&S_noto_2120_1);
  noto(&S_noto_107_1);
  and2(&S_and2_722_1);
  and2(&S_and2_723_1);
  or2(&S_or2_127_1);
  noto(&S_noto_1712_1);
  noto(&S_noto_1716_1);
  or2(&S_or2_1679_1);
  or2(&S_or2_1719_1);
  or2(&S_or2_1722_1);
  or2(&S_or2_1690_1);
  or2(&S_or2_1693_1);
  or2(&S_or2_1650_1);
  or2(&S_or2_1624_1);
  or2(&S_or2_1620_1);
  or2(&S_or2_2144_1);
  or2(&S_or2_2148_1);
  or2(&S_or2_2146_1);
  or2(&S_or2_2112_1);
  or2(&S_or2_2114_1);
  or2(&S_or2_2116_1);
  noto(&S_noto_1653_1);
  or2(&S_or2_1642_1);
  or2(&S_or2_1640_1);
  noto(&S_noto_1655_1);
  or2(&S_or2_1677_1);
  diagndev(&S_diagndev_2278_1);
  and2(&S_and2_2283_1);
  or2(&S_or2_2292_1);
  or2(&S_or2_2299_1);
  orn(&S_orn_2294_1);
  or3(&S_or3_2295_1);
  noto(&S_noto_671_1);
  noto(&S_noto_152_1);
  rs(&S_rs_727_1);
  noto(&S_noto_416_1);
  noto(&S_noto_660_1);
  noto(&S_noto_704_1);
  rs(&S_rs_737_1);
  noto(&S_noto_755_1);
  vmemb(&S_vmemb_669_1);
  vmemb(&S_vmemb_705_1);
  noto(&S_noto_744_1);
  vmemb(&S_vmemb_736_1);
  rs(&S_rs_623_1);
  rs(&S_rs_633_1);
  rs(&S_rs_613_1);
  noto(&S_noto_600_1);
  rs(&S_rs_641_1);
  noto(&S_noto_257_1);
  noto(&S_noto_636_1);
  noto(&S_noto_571_1);
  noto(&S_noto_976_1);
  noto(&S_noto_1373_1);
  noto(&S_noto_998_1);
  noto(&S_noto_1896_1);
  kvf(&S_kvf_1470_1);
  noto(&S_noto_78_1);
  samhd(&S_samhd_2076_1);
  samhd(&S_samhd_2082_1);
  newstage(&S_newstage_2080_1);
  noto(&S_noto_1759_1);
  noto(&S_noto_1765_1);
  noto(&S_noto_1767_1);
  noto(&S_noto_1738_1);
  noto(&S_noto_1883_1);
  noto(&S_noto_1876_1);
  noto(&S_noto_1834_1);
  noto(&S_noto_502_1);
  noto(&S_noto_1203_1);
  noto(&S_noto_1218_1);
  noto(&S_noto_1808_1);
  rs(&S_rs_1481_1);
  kvf(&S_kvf_1476_1);
  rs(&S_rs_1475_1);
  noto(&S_noto_1486_1);
  noto(&S_noto_1484_1);
  rs(&S_rs_742_1);
  noto(&S_noto_343_1);
  noto(&S_noto_339_1);
  noto(&S_noto_581_1);
  noto(&S_noto_591_1);
  noto(&S_noto_643_1);
  noto(&S_noto_1905_1);
  noto(&S_noto_1930_1);
  swtakt(&S_swtakt_52_1);
  rs(&S_rs_1064_1);
  and2(&S_and2_752_1);
  and2(&S_and2_11_1);
  and2(&S_and2_112_1);
  and2(&S_and2_229_1);
  and2(&S_and2_546_1);
  or2(&S_or2_14_1);
  or2(&S_or2_8_1);
  or2(&S_or2_166_1);
  and3(&S_and3_698_1);
  and2(&S_and2_665_1);
  or3(&S_or3_732_1);
  and2(&S_and2_728_1);
  and2(&S_and2_651_1);
  or2(&S_or2_265_1);
  and3(&S_and3_281_1);
  or2(&S_or2_634_1);
  and2(&S_and2_603_1);
  and2(&S_and2_593_1);
  and4(&S_and4_594_1);
  and4(&S_and4_604_1);
  and2(&S_and2_629_1);
  or2(&S_or2_637_1);
  or2(&S_or2_640_1);
  and3(&S_and3_334_1);
  and2(&S_and2_498_1);
  or2(&S_or2_504_1);
  and2(&S_and2_556_1);
  and2(&S_and2_568_1);
  or2(&S_or2_182_1);
  and2(&S_and2_242_1);
  and2(&S_and2_254_1);
  and2(&S_and2_973_1);
  and2(&S_and2_1355_1);
  and2(&S_and2_1370_1);
  and2(&S_and2_1201_1);
  or2(&S_or2_1207_1);
  and2(&S_and2_1213_1);
  or2(&S_or2_1225_1);
  and2(&S_and2_993_1);
  and2(&S_and2_1003_1);
  or2(&S_or2_1460_1);
  and2(&S_and2_1423_1);
  and2(&S_and2_1473_1);
  or3(&S_or3_1487_1);
  or2(&S_or2_1469_1);
  and2(&S_and2_1479_1);
  or3(&S_or3_1480_1);
  or3(&S_or3_1493_1);
  or3(&S_or3_2075_1);
  or3(&S_or3_2084_1);
  or2(&S_or2_1755_1);
  or3(&S_or3_1757_1);
  or2(&S_or2_1795_1);
  and2(&S_and2_1803_1);
  or3(&S_or3_1799_1);
  and2(&S_and2_1825_1);
  or2(&S_or2_2028_1);
  or2(&S_or2_1957_1);
  or2(&S_or2_1946_1);
  and2(&S_and2_1926_1);
  and2(&S_and2_1924_1);
  and2(&S_and2_1909_1);
  and2(&S_and2_1908_1);
  and2(&S_and2_1878_1);
  and4(&S_and4_1884_1);
  and4(&S_and4_1885_1);
  or2(&S_or2_1886_1);
  or2(&S_or2_1888_1);
  or2(&S_or2_1887_1);
  zpfs(&S_zpfs_1892_1);
  zpfs(&S_zpfs_1895_1);
  zpfs(&S_zpfs_1879_1);
  and2(&S_and2_1880_1);
  or3(&S_or3_1897_1);
  lk(&S_lk_1471_1);
  rsfn(&S_rsfn_1467_1);
  abs_subf(&S_abs_subf_1482_1);
  lk(&S_lk_1468_1);
  rsfn(&S_rsfn_1464_1);
  abs_subf(&S_abs_subf_1477_1);
  and3(&S_and3_1840_1);
  or2(&S_or2_1847_1);
  or2(&S_or2_1848_1);
  zpfs(&S_zpfs_1854_1);
  zpfs(&S_zpfs_1856_1);
  or3(&S_or3_1859_1);
  or2(&S_or2_1861_1);
  and2(&S_and2_958_1);
  or2(&S_or2_249_1);
  ovbs(&S_ovbs_1862_1);
  ovbs(&S_ovbs_13_1);
  or2(&S_or2_1462_1);
  noto(&S_noto_103_1);
  bol(&S_bol_1520_1);
  bol(&S_bol_1511_1);
  or2(&S_or2_1514_1);
  ml(&S_ml_1526_1);
  ml(&S_ml_1506_1);
  ml(&S_ml_1528_1);
  ml(&S_ml_1507_1);
  and2(&S_and2_118_1);
  noto(&S_noto_116_1);
  and2(&S_and2_122_1);
  and2(&S_and2_121_1);
  noto(&S_noto_190_1);
  noto(&S_noto_462_1);
  noto(&S_noto_909_1);
  noto(&S_noto_1161_1);
  noto(&S_noto_1214_1);
  bol(&S_bol_1773_1);
  and3(&S_and3_1764_1);
  bol(&S_bol_1737_1);
  and3(&S_and3_1745_1);
  noto(&S_noto_1752_1);
  noto(&S_noto_1763_1);
  bol(&S_bol_900_1);
  bol(&S_bol_1299_1);
  abs_subf(&S_abs_subf_1509_1);
  noto(&S_noto_1518_1);
  abs_subf(&S_abs_subf_1531_1);
  noto(&S_noto_1537_1);
  bol(&S_bol_2221_1);
  and2(&S_and2_2232_1);
  noto(&S_noto_2191_1);
  fsumo(&S_fsumo_80_1);
  abs_subf(&S_abs_subf_2229_1);
  and2(&S_and2_2234_1);
  and3(&S_and3_2183_1);
  and2(&S_and2_2205_1);
  ovbs(&S_ovbs_2206_1);
  or3(&S_or3_2218_1);
  inf(&S_inf_2185_1);
  noto(&S_noto_1300_1);
  or2(&S_or2_1063_1);
  and2(&S_and2_2029_1);
  and2(&S_and2_105_1);
  and3(&S_and3_1385_1);
  or2(&S_or2_1648_1);
  noto(&S_noto_2151_1);
  noto(&S_noto_2119_1);
  or2(&S_or2_2110_1);
  rs(&S_rs_733_1);
  noto(&S_noto_748_1);
  noto(&S_noto_1241_1);
  noto(&S_noto_839_1);
  noto(&S_noto_211_1);
  rs(&S_rs_615_1);
  noto(&S_noto_528_1);
  noto(&S_noto_937_1);
  noto(&S_noto_1334_1);
  kvf(&S_kvf_1855_1);
  kvf(&S_kvf_1894_1);
  andn(&S_andn_1751_1);
  rs(&S_rs_19_1);
  noto(&S_noto_140_1);
  noto(&S_noto_1809_1);
  noto(&S_noto_111_1);
  noto(&S_noto_1376_1);
  abs_subf(&S_abs_subf_1004_1);
  abs_subf(&S_abs_subf_991_1);
  noto(&S_noto_1011_1);
  bol(&S_bol_1024_1);
  bol(&S_bol_1025_1);
  noto(&S_noto_988_1);
  bol(&S_bol_1027_1);
  bol(&S_bol_1028_1);
  bol(&S_bol_81_1);
  and2(&S_and2_31_1);
  and2(&S_and2_145_1);
  and2(&S_and2_153_1);
  and2(&S_and2_150_1);
  and2(&S_and2_142_1);
  and3(&S_and3_231_1);
  and3(&S_and3_548_1);
  and3(&S_and3_982_1);
  or3(&S_or3_108_1);
  or2(&S_or2_661_1);
  and2(&S_and2_670_1);
  and2(&S_and2_672_1);
  and2(&S_and2_684_1);
  and2(&S_and2_686_1);
  and2(&S_and2_699_1);
  and2(&S_and2_702_1);
  and3(&S_and3_701_1);
  and2(&S_and2_703_1);
  or2(&S_or2_739_1);
  and2(&S_and2_747_1);
  or2(&S_or2_753_1);
  or2(&S_or2_757_1);
  and3(&S_and3_754_1);
  and2(&S_and2_759_1);
  and2(&S_and2_763_1);
  and2(&S_and2_647_1);
  or2(&S_or2_648_1);
  and2(&S_and2_656_1);
  and2(&S_and2_658_1);
  and2(&S_and2_627_1);
  and2(&S_and2_605_1);
  and2(&S_and2_595_1);
  and3(&S_and3_526_1);
  or2(&S_or2_563_1);
  and3(&S_and3_209_1);
  and3(&S_and3_244_1);
  and3(&S_and3_847_1);
  and3(&S_and3_848_1);
  or2(&S_or2_968_1);
  or2(&S_or2_1365_1);
  and3(&S_and3_1249_1);
  and3(&S_and3_1250_1);
  or2(&S_or2_1029_1);
  or2(&S_or2_1041_1);
  or2(&S_or2_1039_1);
  or2(&S_or2_1038_1);
  or2(&S_or2_1037_1);
  and2(&S_and2_1388_1);
  and2(&S_and2_1394_1);
  and2(&S_and2_1396_1);
  and2(&S_and2_1398_1);
  and2(&S_and2_1404_1);
  and2(&S_and2_1408_1);
  or3(&S_or3_1432_1);
  and2(&S_and2_1433_1);
  and3(&S_and3_1490_1);
  or3(&S_or3_1474_1);
  and2(&S_and2_1488_1);
  and3(&S_and3_1491_1);
  zpfs(&S_zpfs_2026_1);
  and3(&S_and3_1918_1);
  and2(&S_and2_1913_1);
  or3(&S_or3_1919_1);
  and2(&S_and2_1891_1);
  and4(&S_and4_1899_1);
  and4(&S_and4_1901_1);
  lk(&S_lk_1898_1);
  rsfn(&S_rsfn_1902_1);
  abs_subf(&S_abs_subf_1904_1);
  and3(&S_and3_1907_1);
  lk(&S_lk_1860_1);
  rsfn(&S_rsfn_1863_1);
  abs_subf(&S_abs_subf_1865_1);
  and2(&S_and2_1853_1);
  and3(&S_and3_1857_1);
  or5(&S_or5_148_1);
  and2(&S_and2_1826_1);
  and2(&S_and2_106_1);
  and2(&S_and2_102_1);
  ml(&S_ml_1504_1);
  zpfs(&S_zpfs_740_1);
  and2(&S_and2_1728_1);
  and2(&S_and2_1705_1);
  and2(&S_and2_1726_1);
  and2(&S_and2_1729_1);
  and2(&S_and2_1706_1);
  and2(&S_and2_1727_1);
  and2(&S_and2_1707_1);
  and2(&S_and2_1708_1);
  and2(&S_and2_1710_1);
  and2(&S_and2_1711_1);
  and2(&S_and2_1714_1);
  and2(&S_and2_1715_1);
  and2(&S_and2_1681_1);
  and2(&S_and2_1682_1);
  rs(&S_rs_1683_1);
  and2(&S_and2_1684_1);
  and2(&S_and2_1685_1);
  rs(&S_rs_1686_1);
  and2(&S_and2_1664_1);
  and2(&S_and2_1668_1);
  and2(&S_and2_1629_1);
  and2(&S_and2_1631_1);
  and2(&S_and2_1633_1);
  and2(&S_and2_1635_1);
  and2(&S_and2_1603_1);
  and2(&S_and2_1604_1);
  and2(&S_and2_1605_1);
  and2(&S_and2_1606_1);
  and2(&S_and2_1607_1);
  and2(&S_and2_1608_1);
  and2(&S_and2_1609_1);
  and2(&S_and2_1610_1);
  and2(&S_and2_117_1);
  abs_subf(&S_abs_subf_1508_1);
  noto(&S_noto_1515_1);
  ovbs(&S_ovbs_2184_1);
  and2(&S_and2_2230_1);
  noto(&S_noto_2217_1);
  noto(&S_noto_2161_1);
  noto(&S_noto_2162_1);
  and2(&S_and2_2129_1);
  or4(&S_or4_884_1);
  and2(&S_and2_2097_1);
  or4(&S_or4_1286_1);
  and4(&S_and4_943_1);
  and4(&S_and4_1340_1);
  or3(&S_or3_1718_1);
  or3(&S_or3_1689_1);
  or3(&S_or3_1692_1);
  or3(&S_or3_1721_1);
  or3(&S_or3_1673_1);
  or3(&S_or3_1675_1);
  or3(&S_or3_1622_1);
  or3(&S_or3_1618_1);
  or3(&S_or3_2136_1);
  or3(&S_or3_2104_1);
  or3(&S_or3_2138_1);
  or3(&S_or3_2140_1);
  or3(&S_or3_2108_1);
  or3(&S_or3_2106_1);
  or2(&S_or2_1615_1);
  or2(&S_or2_2142_1);
  and2(&S_and2_2126_1);
  and2(&S_and2_2095_1);
  or2(&S_or2_1612_1);
  or2(&S_or2_1671_1);
  and2(&S_and2_1667_1);
  samhd(&S_samhd_382_1);
  samhd(&S_samhd_388_1);
  samhd(&S_samhd_777_1);
  samhd(&S_samhd_781_1);
  rs(&S_rs_749_1);
  rs(&S_rs_756_1);
  newstage(&S_newstage_385_1);
  newstage(&S_newstage_779_1);
  orn(&S_orn_146_1);
  rs(&S_rs_1611_1);
  rs(&S_rs_1613_1);
  rs(&S_rs_1614_1);
  rs(&S_rs_1616_1);
  rs(&S_rs_1617_1);
  rs(&S_rs_1619_1);
  rs(&S_rs_1621_1);
  rs(&S_rs_1623_1);
  rs(&S_rs_1641_1);
  rs(&S_rs_1649_1);
  rs(&S_rs_1670_1);
  rs(&S_rs_1678_1);
  rs(&S_rs_1688_1);
  rs(&S_rs_2143_1);
  rs(&S_rs_1717_1);
  rs(&S_rs_1709_1);
  rs(&S_rs_1720_1);
  rs(&S_rs_1713_1);
  rs(&S_rs_1723_1);
  rs(&S_rs_1661_1);
  rs(&S_rs_1662_1);
  rs(&S_rs_1663_1);
  rs(&S_rs_1625_1);
  rs(&S_rs_1626_1);
  rs(&S_rs_1627_1);
  rs(&S_rs_1628_1);
  rs(&S_rs_109_1);
  noto(&S_noto_110_1);
  rs(&S_rs_1496_1);
  rs(&S_rs_1495_1);
  rs(&S_rs_1425_1);
  kvf(&S_kvf_1429_1);
  rs(&S_rs_1912_1);
  rs(&S_rs_1858_1);
  noto(&S_noto_1428_1);
  andn(&S_andn_264_1);
  noto(&S_noto_282_1);
  and2(&S_and2_406_1);
  and2(&S_and2_417_1);
  and2(&S_and2_425_1);
  and2(&S_and2_426_1);
  and2(&S_and2_427_1);
  or3(&S_or3_378_1);
  or3(&S_or3_393_1);
  and2(&S_and2_407_1);
  and3(&S_and3_583_1);
  or2(&S_or2_147_1);
  and2(&S_and2_675_1);
  and2(&S_and2_735_1);
  or2(&S_or2_762_1);
  and2(&S_and2_654_1);
  or2(&S_or2_272_1);
  and3(&S_and3_273_1);
  or2(&S_or2_435_1);
  and3(&S_and3_442_1);
  or2(&S_or2_488_1);
  and2(&S_and2_508_1);
  and3(&S_and3_558_1);
  and3(&S_and3_557_1);
  and2(&S_and2_185_1);
  and3(&S_and3_243_1);
  or4(&S_or4_773_1);
  or4(&S_or4_789_1);
  or3(&S_or3_840_1);
  and2(&S_and2_837_1);
  and3(&S_and3_838_1);
  and2(&S_and2_836_1);
  and2(&S_and2_849_1);
  and2(&S_and2_866_1);
  and3(&S_and3_867_1);
  and2(&S_and2_931_1);
  or2(&S_or2_935_1);
  and2(&S_and2_944_1);
  and2(&S_and2_961_1);
  and3(&S_and3_962_1);
  and3(&S_and3_963_1);
  or2(&S_or2_1332_1);
  and2(&S_and2_1341_1);
  and2(&S_and2_1358_1);
  and3(&S_and3_1359_1);
  and3(&S_and3_1360_1);
  and2(&S_and2_1328_1);
  or3(&S_or3_1242_1);
  and3(&S_and3_1240_1);
  and2(&S_and2_1239_1);
  and2(&S_and2_1238_1);
  and2(&S_and2_1251_1);
  and2(&S_and2_1263_1);
  and3(&S_and3_1264_1);
  and2(&S_and2_1268_1);
  and3(&S_and3_1269_1);
  and2(&S_and2_1209_1);
  and2(&S_and2_1231_1);
  and2(&S_and2_1042_1);
  and2(&S_and2_1045_1);
  or2(&S_or2_1420_1);
  or3(&S_or3_1424_1);
  or2(&S_or2_1724_1);
  or2(&S_or2_2053_1);
  or2(&S_or2_2058_1);
  lk(&S_lk_1430_1);
  rsfn(&S_rsfn_1426_1);
  abs_subf(&S_abs_subf_1435_1);
  ovbs(&S_ovbs_2045_1);
  ovbs(&S_ovbs_115_1);
  and2(&S_and2_469_1);
  and2(&S_and2_436_1);
  and2(&S_and2_433_1);
  rs(&S_rs_1725_1);
  rs(&S_rs_1691_1);
  and2(&S_and2_1665_1);
  and2(&S_and2_1666_1);
  and2(&S_and2_1669_1);
  and2(&S_and2_1632_1);
  and2(&S_and2_1634_1);
  and2(&S_and2_1636_1);
  zpfs(&S_zpfs_2169_1);
  zpfs(&S_zpfs_2170_1);
  and2(&S_and2_2041_1);
  and2(&S_and2_2052_1);
  and3(&S_and3_408_1);
  and2(&S_and2_2040_1);
  and2(&S_and2_2063_1);
  rs(&S_rs_2135_1);
  rs(&S_rs_2123_1);
  rs(&S_rs_2127_1);
  and2(&S_and2_2133_1);
  rs(&S_rs_2145_1);
  rs(&S_rs_2128_1);
  and2(&S_and2_2134_1);
  rs(&S_rs_2147_1);
  rs(&S_rs_2111_1);
  rs(&S_rs_2103_1);
  rs(&S_rs_2091_1);
  rs(&S_rs_2094_1);
  and2(&S_and2_2101_1);
  rs(&S_rs_2113_1);
  rs(&S_rs_2096_1);
  and2(&S_and2_2102_1);
  rs(&S_rs_2115_1);
  regch(&S_regch_125_1);
  rs(&S_rs_1676_1);
  rs(&S_rs_729_1);
  rs(&S_rs_761_1);
  rs(&S_rs_588_1);
  noto(&S_noto_602_1);
  orni(&S_orni_1393_1);
  noto(&S_noto_2046_1);
  rs(&S_rs_1643_1);
  rs(&S_rs_1647_1);
  rs(&S_rs_1651_1);
  rs(&S_rs_1672_1);
  rs(&S_rs_1674_1);
  rs(&S_rs_1680_1);
  ma(&S_ma_1431_1);
  rs(&S_rs_598_1);
  noto(&S_noto_978_1);
  noto(&S_noto_277_1);
  noto(&S_noto_1040_1);
  noto(&S_noto_1034_1);
  noto(&S_noto_1007_1);
  and2(&S_and2_410_1);
  and2(&S_and2_428_1);
  and2(&S_and2_861_1);
  and3(&S_and3_862_1);
  and3(&S_and3_956_1);
  and3(&S_and3_1353_1);
  and2(&S_and2_622_1);
  and2(&S_and2_932_1);
  and2(&S_and2_933_1);
  and3(&S_and3_934_1);
  and2(&S_and2_1329_1);
  and2(&S_and2_1330_1);
  and3(&S_and3_1331_1);
  and5(&S_and5_983_1);
  and2(&S_and2_1030_1);
  or4(&S_or4_990_1);
  and3(&S_and3_1439_1);
  or2(&S_or2_1813_1);
  and2(&S_and2_1816_1);
  and2(&S_and2_2064_1);
  ovbs(&S_ovbs_2049_1);
  noto(&S_noto_2174_1);
  noto(&S_noto_2175_1);
  andn(&S_andn_586_1);
  andn(&S_andn_587_1);
  and2(&S_and2_2067_1);
  or5(&S_or5_2065_1);
  or5(&S_or5_2066_1);
  and2(&S_and2_2130_1);
  or3(&S_or3_1193_1);
  rs(&S_rs_2137_1);
  rs(&S_rs_2124_1);
  and2(&S_and2_2098_1);
  rs(&S_rs_2105_1);
  rs(&S_rs_2092_1);
  or3(&S_or3_808_1);
  or2(&S_or2_128_1);
  rs(&S_rs_989_1);
  noto(&S_noto_2050_1);
  rs(&S_rs_2054_1);
  rs(&S_rs_2059_1);
  rs(&S_rs_1442_1);
  noto(&S_noto_1008_1);
  provsbr(&S_provsbr_1390_1);
  rs(&S_rs_1389_1);
  and2(&S_and2_536_1);
  and2(&S_and2_219_1);
  and2(&S_and2_851_1);
  and2(&S_and2_946_1);
  and2(&S_and2_1343_1);
  and2(&S_and2_1253_1);
  and3(&S_and3_995_1);
  and3(&S_and3_1001_1);
  and2(&S_and2_1017_1);
  and2(&S_and2_1006_1);
  and3(&S_and3_1052_1);
  or2(&S_or2_1395_1);
  or2(&S_or2_1397_1);
  or2(&S_or2_1399_1);
  or2(&S_or2_1405_1);
  or2(&S_or2_1409_1);
  orni(&S_orni_1401_1);
  or2(&S_or2_1811_1);
  or2(&S_or2_2042_1);
  noto(&S_noto_2181_1);
  and2(&S_and2_2131_1);
  and2(&S_and2_2099_1);
  rs(&S_rs_2125_1);
  and2(&S_and2_2132_1);
  rs(&S_rs_2141_1);
  rs(&S_rs_2093_1);
  and2(&S_and2_2043_1);
  noto(&S_noto_2060_1);
  rs(&S_rs_2139_1);
  newstage(&S_newstage_1804_1);
  cntch(&S_cntch_1400_1);
  rs(&S_rs_1012_1);
  rs(&S_rs_1046_1);
  rs(&S_rs_1020_1);
  noto(&S_noto_1021_1);
  or3(&S_or3_156_1);
  or3(&S_or3_478_1);
  or2(&S_or2_1043_1);
  and2(&S_and2_1402_1);
  or2(&S_or2_1564_1);
  zpfs(&S_zpfs_2039_1);
  rs(&S_rs_2107_1);
  and2(&S_and2_2100_1);
  rs(&S_rs_2109_1);
  cnshd(&S_cnshd_1571_1);
  noto(&S_noto_859_1);
  ornc(&S_ornc_163_1);
  charint(&S_charint_157_1);
  noto(&S_noto_227_1);
  ornc(&S_ornc_486_1);
  charint(&S_charint_480_1);
  noto(&S_noto_544_1);
  noto(&S_noto_954_1);
  noto(&S_noto_1351_1);
  rs(&S_rs_1031_1);
  or2(&S_or2_1590_1);
  and2(&S_and2_1542_1);
  and2(&S_and2_1543_1);
  and2(&S_and2_1544_1);
  and2(&S_and2_1545_1);
  and2(&S_and2_1551_1);
  and2(&S_and2_1553_1);
  and2(&S_and2_1555_1);
  and2(&S_and2_1019_1);
  fnapb(&S_fnapb_1591_1);
  samhd(&S_samhd_1574_1);
  zpfs(&S_zpfs_1586_1);
  zpfs(&S_zpfs_1584_1);
  noto(&S_noto_1261_1);
  fsumz(&S_fsumz_158_1);
  fsumz(&S_fsumz_481_1);
  orni(&S_orni_1153_1);
  rs(&S_rs_1014_1);
  rs(&S_rs_1015_1);
  ma(&S_ma_164_1);
  ma(&S_ma_487_1);
  zpfs(&S_zpfs_1592_1);
  or2(&S_or2_1106_1);
  or3(&S_or3_1013_1);
  or3(&S_or3_1581_1);
  samhd(&S_samhd_1158_1);
  samhd(&S_samhd_1168_1);
  newstage(&S_newstage_1164_1);
  cnshd(&S_cnshd_1107_1);
  noto(&S_noto_1260_1);
  noto(&S_noto_858_1);
  fnapb(&S_fnapb_197_1);
  noto(&S_noto_226_1);
  fnapb(&S_fnapb_516_1);
  zpfs(&S_zpfs_512_1);
  zpfs(&S_zpfs_509_1);
  noto(&S_noto_543_1);
  noto(&S_noto_953_1);
  noto(&S_noto_1350_1);
  or2(&S_or2_1157_1);
  or2(&S_or2_1171_1);
  or2(&S_or2_1130_1);
  and2(&S_and2_1082_1);
  and2(&S_and2_1079_1);
  and2(&S_and2_1080_1);
  and2(&S_and2_1081_1);
  and2(&S_and2_1087_1);
  and2(&S_and2_1089_1);
  and2(&S_and2_1091_1);
  and2(&S_and2_624_1);
  zpfs(&S_zpfs_517_1);
  or2(&S_or2_538_1);
  zpfs(&S_zpfs_198_1);
  zpfs(&S_zpfs_192_1);
  zpfs(&S_zpfs_187_1);
  or2(&S_or2_221_1);
  or2(&S_or2_853_1);
  and2(&S_and2_852_1);
  or2(&S_or2_948_1);
  or2(&S_or2_1345_1);
  or2(&S_or2_1255_1);
  and2(&S_and2_1254_1);
  and2(&S_and2_1010_1);
  or2(&S_or2_1022_1);
  and2(&S_and2_1162_1);
  and2(&S_and2_1169_1);
  or4(&S_or4_1936_1);
  fnapb(&S_fnapb_1131_1);
  samhd(&S_samhd_1115_1);
  zpfs(&S_zpfs_1128_1);
  zpfs(&S_zpfs_1123_1);
  orn(&S_orn_1262_1);
  orn(&S_orn_860_1);
  rs(&S_rs_1009_1);
  zpfs(&S_zpfs_1132_1);
  and2(&S_and2_537_1);
  and2(&S_and2_220_1);
  and2(&S_and2_947_1);
  and2(&S_and2_1344_1);
  and2(&S_and2_1023_1);
  or2(&S_or2_1016_1);
  or3(&S_or3_1120_1);
  or2(&S_or2_1953_1);
  or2(&S_or2_1942_1);
  ovbs(&S_ovbs_1937_1);
  ovbs(&S_ovbs_1949_1);
  ovbs(&S_ovbs_1940_1);
  noto(&S_noto_1941_1);
  and2(&S_and2_1947_1);
  and2(&S_and2_1958_1);
  or3(&S_or3_126_1);
  orn(&S_orn_228_1);
  orn(&S_orn_955_1);
  orn(&S_orn_1352_1);
  noto(&S_noto_1938_1);
  noto(&S_noto_1950_1);
  rs(&S_rs_1954_1);
  noto(&S_noto_1955_1);
  rs(&S_rs_1943_1);
  rs(&S_rs_1061_1);
  or2(&S_or2_1910_1);
  irm(&S_irm_2168_1);
  ml(&S_ml_881_1);
  ml(&S_ml_1281_1);
  noto(&S_noto_1944_1);
  noto(&S_noto_66_1);
  noto(&S_noto_1911_1);
  and2(&S_and2_58_1);
  and2(&S_and2_62_1);
  and4(&S_and4_328_1);
  or2(&S_or2_1382_1);
  or2(&S_or2_1927_1);
  noto(&S_noto_1378_1);
  rs(&S_rs_331_1);
  noto(&S_noto_326_1);
  noto(&S_noto_269_1);
  rs(&S_rs_1928_1);
  rs(&S_rs_1929_1);
  or4(&S_or4_280_1);
  or2(&S_or2_263_1);
  or2(&S_or2_286_1);
  or2(&S_or2_323_1);
  or4(&S_or4_332_1);
  and2(&S_and2_1377_1);
  or2(&S_or2_1989_1);
  or2(&S_or2_2010_1);
  rs(&S_rs_279_1);
  provsbr(&S_provsbr_268_1);
  equz_p(&S_equz_p_307_1);
  bolz(&S_bolz_308_1);
  provsbr(&S_provsbr_325_1);
  bolz(&S_bolz_330_1);
  noto(&S_noto_67_1);
  noto(&S_noto_56_1);
  and2(&S_and2_59_1);
  and2(&S_and2_63_1);
  or2(&S_or2_60_1);
  and2(&S_and2_560_1);
  and2(&S_and2_559_1);
  and2(&S_and2_283_1);
  and4(&S_and4_312_1);
  and2(&S_and2_295_1);
  or2(&S_or2_285_1);
  and2(&S_and2_290_1);
  or2(&S_or2_336_1);
  and2(&S_and2_327_1);
  orn(&S_orn_545_1);
  and2(&S_and2_245_1);
  and2(&S_and2_246_1);
  or3(&S_or3_256_1);
  and2(&S_and2_869_1);
  and2(&S_and2_868_1);
  or3(&S_or3_874_1);
  and2(&S_and2_965_1);
  and2(&S_and2_964_1);
  and2(&S_and2_1361_1);
  and2(&S_and2_1362_1);
  and2(&S_and2_1270_1);
  and2(&S_and2_1271_1);
  or3(&S_or3_1276_1);
  or2(&S_or2_1379_1);
  or3(&S_or3_1410_1);
  or3(&S_or3_1449_1);
  or3(&S_or3_1465_1);
  or3(&S_or3_1870_1);
  or3(&S_or3_1832_1);
  or4(&S_or4_1372_1);
  or4(&S_or4_975_1);
  maz(&S_maz_294_1);
  maz(&S_maz_303_1);
  orni(&S_orni_1165_1);
  orni(&S_orni_284_1);
  rs(&S_rs_335_1);
  decatron(&S_decatron_291_1);
  orni(&S_orni_329_1);
  noto(&S_noto_304_1);
  swtakt(&S_swtakt_1836_1);
  swtakt(&S_swtakt_1871_1);
  swtakt(&S_swtakt_1455_1);
  swtakt(&S_swtakt_1459_1);
  swtakt(&S_swtakt_1415_1);
  or3(&S_or3_570_1);
  or2(&S_or2_289_1);
  or2(&S_or2_298_1);
  or2(&S_or2_311_1);
  or2(&S_or2_310_1);
  and2(&S_and2_314_1);
  and2(&S_and2_309_1);
  and2(&S_and2_316_1);
  and2(&S_and2_315_1);
  and3(&S_and3_296_1);
  or5(&S_or5_500_1);
  or5(&S_or5_180_1);
  and2(&S_and2_1380_1);
  or2(&S_or2_2032_1);
  or2(&S_or2_2020_1);
  or3(&S_or3_1374_1);
  or3(&S_or3_977_1);
  zpfs(&S_zpfs_306_1);
  cnshd(&S_cnshd_168_1);
  cnshd(&S_cnshd_489_1);
  equz_p(&S_equz_p_297_1);
  noto(&S_noto_1386_1);
  cntch(&S_cntch_287_1);
  rs(&S_rs_288_1);
  cntch(&S_cntch_333_1);
  and2(&S_and2_302_1);
  or5(&S_or5_1403_1);
  or5(&S_or5_1381_1);
  and2(&S_and2_1383_1);
  or2(&S_or2_1384_1);
  and4(&S_and4_1914_1);
  and3(&S_and3_1915_1);
  and3(&S_and3_1916_1);
  and2(&S_and2_1877_1);
  and2(&S_and2_1831_1);
  or3(&S_or3_1845_1);
  newstage(&S_newstage_205_1);
  rs(&S_rs_1882_1);
  rs(&S_rs_1837_1);
  rs(&S_rs_1846_1);
  and2(&S_and2_321_1);
  or3(&S_or3_1881_1);
  and2(&S_and2_194_1);
  and2(&S_and2_191_1);
  noto(&S_noto_322_1);
  and2(&S_and2_1075_1);
  and2(&S_and2_631_1);
  or2(&S_or2_619_1);
  and2(&S_and2_1035_1);
  rs(&S_rs_620_1);
  rs(&S_rs_1032_1);
  noto(&S_noto_1033_1);
  rs(&S_rs_1067_1);
  and2(&S_and2_638_1);
  and3(&S_and3_607_1);
  and3(&S_and3_597_1);
  or3(&S_or3_805_1);
  or3(&S_or3_1189_1);
  and4(&S_and4_996_1);
  and4(&S_and4_1002_1);
  or2(&S_or2_1066_1);
  or4(&S_or4_875_1);
  or4(&S_or4_1277_1);
  ornc(&S_ornc_885_1);
  charint(&S_charint_879_1);
  ornc(&S_ornc_1287_1);
  charint(&S_charint_1279_1);
  fsumz(&S_fsumz_880_1);
  fsumz(&S_fsumz_1280_1);
  ma(&S_ma_1288_1);
  ma(&S_ma_886_1);
  fnapb(&S_fnapb_920_1);
  zpfs(&S_zpfs_914_1);
  zpfs(&S_zpfs_911_1);
  fnapb(&S_fnapb_1317_1);
  zpfs(&S_zpfs_1309_1);
  zpfs(&S_zpfs_1308_1);
  zpfs(&S_zpfs_921_1);
  zpfs(&S_zpfs_1318_1);
  and2(&S_and2_1303_1);
  and2(&S_and2_903_1);
  or5(&S_or5_902_1);
  or5(&S_or5_1302_1);
  or2(&S_or2_2214_1);
  cnshd(&S_cnshd_887_1);
  cnshd(&S_cnshd_1289_1);
  noto(&S_noto_2213_1);
  newstage(&S_newstage_899_1);
  and2(&S_and2_906_1);
  and2(&S_and2_910_1);
  andn(&S_andn_2189_1);
  noto(&S_noto_2211_1);
  and2(&S_and2_2212_1);
  or2(&S_or2_2210_1);
  and3(&S_and3_2167_1);
  and2(&S_and2_2037_1);
  and2(&S_and2_2027_1);
  or3(&S_or3_2024_1);
  or3(&S_or3_2038_1);
  rs(&S_rs_2021_1);
  noto(&S_noto_2022_1);
  rs(&S_rs_2033_1);
  noto(&S_noto_2034_1);
  and2(&S_and2_1076_1);
  and2(&S_and2_630_1);
  and2(&S_and2_1051_1);
  rs(&S_rs_2209_1);
  rs(&S_rs_1044_1);
  noto(&S_noto_1047_1);
  rs(&S_rs_1070_1);
  and3(&S_and3_1036_1);
  and2(&S_and2_987_1);
  and4(&S_and4_994_1);
  and4(&S_and4_1000_1);
  or2(&S_or2_1069_1);
  orn(&S_orn_1181_1);
  orn(&S_orn_796_1);
  ornc(&S_ornc_1190_1);
  charint(&S_charint_1182_1);
  ornc(&S_ornc_806_1);
  charint(&S_charint_797_1);
  rs(&S_rs_981_1);
  or3(&S_or3_434_1);
  and3(&S_and3_441_1);
  and2(&S_and2_1026_1);
  and2(&S_and2_473_1);
  and2(&S_and2_444_1);
  fsumz(&S_fsumz_1183_1);
  fsumz(&S_fsumz_798_1);
  samhd(&S_samhd_454_1);
  samhd(&S_samhd_460_1);
  newstage(&S_newstage_456_1);
  ma(&S_ma_801_1);
  ma(&S_ma_1191_1);
  or4(&S_or4_450_1);
  or4(&S_or4_468_1);
  and2(&S_and2_465_1);
  and2(&S_and2_463_1);
  fnapb(&S_fnapb_1226_1);
  zpfs(&S_zpfs_1220_1);
  zpfs(&S_zpfs_1212_1);
  fnapb(&S_fnapb_827_1);
  zpfs(&S_zpfs_1227_1);
  and2(&S_and2_1077_1);
  and2(&S_and2_646_1);
  zpfs(&S_zpfs_828_1);
  zpfs(&S_zpfs_821_1);
  zpfs(&S_zpfs_823_1);
  or5(&S_or5_1205_1);
  and2(&S_and2_1058_1);
  or5(&S_or5_1960_1);
  orni(&S_orni_132_1);
  orn(&S_orn_412_1);
  orn(&S_orn_430_1);
  cnshd(&S_cnshd_1192_1);
  rs(&S_rs_1054_1);
  rs(&S_rs_1073_1);
  or2(&S_or2_414_1);
  or2(&S_or2_431_1);
  and2(&S_and2_674_1);
  or2(&S_or2_1143_1);
  or2(&S_or2_1144_1);
  and2(&S_and2_1090_1);
  or5(&S_or5_816_1);
  and2(&S_and2_1554_1);
  or4(&S_or4_1550_1);
  or4(&S_or4_1961_1);
  orn(&S_orn_760_1);
  orn(&S_orn_1078_1);
  cnshd(&S_cnshd_807_1);
  or2(&S_or2_750_1);
  or2(&S_or2_751_1);
  or4(&S_or4_731_1);
  or5(&S_or5_1116_1);
  or2(&S_or2_356_1);
  or2(&S_or2_360_1);
  ovbs(&S_ovbs_1967_1);
  noto(&S_noto_1968_1);
  and2(&S_and2_1974_1);
  and2(&S_and2_1986_1);
  or3(&S_or3_1962_1);
  and2(&S_and2_1963_1);
  or3(&S_or3_1976_1);
  and2(&S_and2_1977_1);
  or5(&S_or5_1541_1);
  or2(&S_or2_2200_1);
  rs(&S_rs_730_1);
  samhd(&S_samhd_359_1);
  newstage(&S_newstage_1232_1);
  and2(&S_and2_718_1);
  or2(&S_or2_721_1);
  or4(&S_or4_358_1);
  or5(&S_or5_1578_1);
  or2(&S_or2_1981_1);
  or2(&S_or2_1969_1);
  ovbs(&S_ovbs_1964_1);
  ovbs(&S_ovbs_1978_1);
  rs(&S_rs_1997_1);
  rs(&S_rs_2005_1);
  noto(&S_noto_1995_1);
  noto(&S_noto_2016_1);
  andn(&S_andn_1_1);
  and2(&S_and2_1215_1);
  and2(&S_and2_1219_1);
  zpfs(&S_zpfs_1998_1);
  zpfs(&S_zpfs_2006_1);
  noto(&S_noto_2198_1);
  or3(&S_or3_1646_1);
  or3(&S_or3_1638_1);
  or2(&S_or2_1652_1);
  or2(&S_or2_1644_1);
  rs(&S_rs_724_1);
  rs(&S_rs_1637_1);
  rs(&S_rs_1645_1);
  or2(&S_or2_1999_1);
  noto(&S_noto_1965_1);
  noto(&S_noto_1979_1);
  rs(&S_rs_1982_1);
  noto(&S_noto_1983_1);
  rs(&S_rs_1970_1);
  or2(&S_or2_2007_1);
  noto(&S_noto_2000_1);
  and2(&S_and2_2001_1);
  and2(&S_and2_1996_1);
  noto(&S_noto_2008_1);
  and2(&S_and2_1630_1);
  noto(&S_noto_1988_1);
  rs(&S_rs_1639_1);
  noto(&S_noto_1971_1);
  and2(&S_and2_2009_1);
  and4(&S_and4_1990_1);
  ovbs(&S_ovbs_1991_1);
  and2(&S_and2_2017_1);
  noto(&S_noto_2018_1);
  or2(&S_or2_1992_1);
  orn(&S_orn_590_1);
  orn(&S_orn_589_1);
  noto(&S_noto_1993_1);
  and4(&S_and4_2011_1);
  ovbs(&S_ovbs_2012_1);
  or2(&S_or2_2013_1);
  newstage(&S_newstage_592_1);
  or2(&S_or2_626_1);
  ovbs(&S_ovbs_2002_1);
  noto(&S_noto_2014_1);
  and2(&S_and2_625_1);
  setData(idTestDiagnDU,&var1);
  setData(idR0DE3CLDU,&var4);
  setData(idR0DE3DLDU,&var3);
  setData(idTTLDU,&var7);
  setData(idB3AB13LDU,&var129);
  setData(idA3AB13LDU,&var132);
  setData(idR3VS01IDU,&var138);
  setData(idR3VS12LDU,&var136);
  setData(idR3VS22LDU,&var137);
  setData(idR5VS01IDU,&var135);
  setData(idR5VS12LDU,&var133);
  setData(idR5VS22LDU,&var134);
  setData(idB3AB15LDU,&var142);
  setData(idB3EE03LDU,&var810);
  setData(idA3EE03LDU,&var811);
  setData(idB3AB19LDU,&var147);
  setData(idA3AB19LDU,&var148);
  setData(idR0VL23LDU,&var1046);
  setData(idR0VL22LDU,&var1068);
  setData(idR0AD05LZ2,&var74);
  setData(idR0AD05LZ1,&var74);
  setData(idR0AD04LZ2,&var370);
  setData(idR0AD04LZ1,&var370);
  setData(idR0AD03LZ2,&var73);
  setData(idR0AD03LZ1,&var73);
  setData(idR0CN95LDU,&var218);
  setData(idR0CN94LDU,&var217);
  setData(idR0CN93LDU,&var216);
  setData(idR0AB19LDU,&var179);
  setData(idR0VN12RDU,&var979);
  setData(idR0VN11RDU,&var977);
  setData(idR0CN92LDU,&var183);
  setData(idR0AB20LDU,&var195);
  setData(idA3AB15LDU,&var143);
  setData(idA3MC03RDU,&var214);
  setData(idR0CN91LDU,&var213);
  setData(idA3MC02RDU,&var212);
  setData(idA3MC01RDU,&var211);
  setData(idR0AB18LDU,&var200);
  setData(idR0AB17LDU,&var207);
  setData(idR0AB16LDU,&var208);
  setData(idB1AB19LDU,&var225);
  setData(idA3ZAV,&var1318);
  setData(idA1ZAV,&var1381);
  setData(idB3IS12LDU,&var235);
  setData(idA3IS12LDU,&var236);
  setData(idR0AB15LDU,&var241);
  setData(idR0AB14LDU,&var239);
  setData(idA4DW,&var1156);
  setData(idA4UP,&var1157);
  setData(idR4ABL,&var1620);
  setData(idA9ZAV,&var1256);
  setData(idA8ZAV,&var1457);
  setData(idA2ZAV,&var1462);
  setData(idB8ZAV,&var1467);
  setData(idA5ZAV,&var1535);
  setData(idR2ZAV,&var1411);
  setData(idA6ZAV,&var1537);
  setData(idA4ZAV,&var1536);
  setData(idR0AB13LDU,&var308);
  setData(idR0AB12LDU,&var312);
  setData(idR0AB11LDU,&var316);
  setData(idR0AB10LDU,&var320);
  setData(idR0AB09LDU,&var324);
  setData(idR0AB08LDU,&var328);
  setData(idB6AB05LDU,&var371);
  setData(idR0VS11LDU,&var1666);
  setData(idA8VS01IDU,&var1461);
  setData(idB8VS01IDU,&var1471);
  setData(idR2AD10LDU,&var1416);
  setData(idR2AD20LDU,&var1417);
  setData(idB6VS01IDU,&var1608);
  setData(idR0AD16LDU,&lRM_0_);
  setData(idR0AB07LDU,&var610);
  setData(idR0EE03LDU,&var395);
  setData(idR0VX02LDU,&var816);
  setData(idR0AD21LDU,&var814);
  setData(idB2AB15LDU,&var341);
  setData(idA2AB15LDU,&var342);
  setData(idR0AB05LDU,&var1128);
  setData(idR0AB03LDU,&var1139);
  setData(idA1AB19LDU,&var226);
  setData(idR0VZ71LDU,&var60);
  setData(idR0VL01RDU,&var1174);
  setData(idB7AZ03LDU,&var372);
  setData(idA7AZ03LDU,&var480);
  setData(idB2VS01IDU,&var1449);
  setData(idB2VS21LDU,&var1451);
  setData(idB2VS11LDU,&var1450);
  setData(idR0VP73LDU,&var491);
  setData(idR0VS18LDU,&var568);
  setData(idB3VX01LDU,&var438);
  setData(idA3VX01LDU,&var439);
  setData(idB2VS32LDU,&var354);
  setData(idA2VS32LDU,&var355);
  setData(idR0VS17LDU,&var558);
  setData(idR0VX09LDU,&var171);
  moveData(idR0VX08IDU,idR0MW12IP1);
  setData(idR0VW23LDU,&var911);
  setData(idR0VW13LDU,&var910);
  setData(idB7AP31LDU,&var1159);
  setData(idA7AP31LDU,&var1160);
  setData(idB3AD31LDU,&var1219);
  setData(idB3AD34LDU,&var1220);
  setData(idA3AD31LDU,&var1225);
  setData(idA3AD34LDU,&var1222);
  setData(idA3AD33LDU,&var1224);
  setData(idB2AD33LDU,&var333);
  setData(idA2AD33LDU,&var336);
  setData(idR0AB01LDU,&var1248);
  setData(idB9AB02LDU,&var1258);
  setData(idB9AB01LDU,&var1259);
  setData(idB9AZ03LDU,&var1257);
  setData(idA9AB02LDU,&var1264);
  setData(idA9AB01LDU,&var1265);
  setData(idA9AZ03LDU,&var1263);
  setData(idA9AD10LDU,&var1266);
  setData(idB9AD10LDU,&var1260);
  setData(idR1VS01IDU,&var1427);
  setData(idR2VS01IDU,&var1418);
  setData(idR4VS01IDU,&var1599);
  setData(idA6VS01IDU,&var1617);
  setData(idB5VS01IDU,&var1581);
  setData(idA5VS01IDU,&var1590);
  setData(idB4VS22LDU,&var1562);
  setData(idB4VS12LDU,&var1561);
  setData(idB4VS01IDU,&var1563);
  setData(idA4VS22LDU,&var1571);
  setData(idA4VS12LDU,&var1570);
  setData(idA4VS01IDU,&var1572);
  setData(idA2VS01IDU,&var1490);
  setData(idB3VS01IDU,&var1308);
  setData(idA3VS01IDU,&var1340);
  setData(idB1VS01IDU,&var1369);
  setData(idA1VS01IDU,&var1402);
  setData(idR0VS21IDU,&var1149);
  setData(idR0VX03LDU,&var761);
  setData(idR0VL21IDU,&var1059);
  setData(idR0VL05RDU,&var425);
  setData(idR0VL03RDU,&var431);
  setData(idR0AB02LDU,&var1122);
  setData(idR0AB06LDU,&var1125);
  setData(idR0AB04LDU,&var1133);
  setData(idR0VL04RDU,&var428);
  setData(idR0AD14LDU,&var370);
  setData(idR8AD21LDU,&var393);
  setData(idR0VL02RDU,&var422);
  setData(idB3AD33LDU,&var1218);
  setData(idR0VL06RDU,&var435);
  setData(idR0VL11IDU,&var1272);
  setData(idR0VL01IDU,&var1273);
  setData(idR0VX01LDU,&var818);
  setData(idB1AD32LDU,&var1226);
  setData(idA1AD32LDU,&var1228);
  setData(idB2AD32LDU,&var361);
  setData(idA2AD32LDU,&var363);
  setData(idB1AD31LDU,&var1229);
  setData(idA1AD31LDU,&var1230);
  setData(idB2AD31LDU,&var364);
  setData(idA2AD31LDU,&var365);
  setData(idB3AB20LDU,&var652);
  setData(idB3AB18LDU,&var649);
  setData(idB3AB17LDU,&var645);
  setData(idB3AB16LDU,&var646);
  setData(idB3AB14LDU,&var920);
  setData(idB3AB12LDU,&var650);
  setData(idB3AB11LDU,&var654);
  setData(idB3AB10LDU,&var655);
  setData(idB3AB09LDU,&var656);
  setData(idB3AB06LDU,&var659);
  setData(idB3AB05LDU,&var661);
  setData(idB3AB08LDU,&var651);
  setData(idB3AB07LDU,&var660);
  setData(idB3CV02RDU,&var1307);
  setData(idB3AD01LDU,&var1300);
  setData(idB3AD05LDU,&var1306);
  setData(idB3AD04LDU,&var1305);
  setData(idB3AD03LDU,&var1304);
  setData(idB3AD02LDU,&var1303);
  setData(idB3AD21LDU,&var1301);
  setData(idB3AD11LDU,&var1302);
  setData(idB3AZ03LDU,&var992);
  setData(idB3VS22LDU,&var1311);
  setData(idB3AB01LDU,&var1309);
  setData(idB3AB02LDU,&var1310);
  setData(idB3AB04LDU,&var1315);
  setData(idB3CV01RDU,&var1313);
  setData(idB3VS12LDU,&var1312);
  setData(idA3AB20LDU,&var403);
  setData(idA3AB18LDU,&var666);
  setData(idA3AB17LDU,&var664);
  setData(idA3AB16LDU,&var663);
  setData(idA3AB14LDU,&var922);
  setData(idA3AB12LDU,&var667);
  setData(idA3AB11LDU,&var671);
  setData(idA3AB10LDU,&var675);
  setData(idA3AB09LDU,&var669);
  setData(idA3AB06LDU,&var674);
  setData(idA3AB05LDU,&var677);
  setData(idA3AB08LDU,&var668);
  setData(idA3AB07LDU,&var676);
  setData(idA3CV02RDU,&var1339);
  setData(idA3AD01LDU,&var1332);
  setData(idA3AD05LDU,&var1338);
  setData(idA3AD04LDU,&var1337);
  setData(idA3AD03LDU,&var1336);
  setData(idA3AD02LDU,&var1335);
  setData(idA3AD21LDU,&var1333);
  setData(idA3AD11LDU,&var1334);
  setData(idA3AZ03LDU,&var993);
  setData(idA3VS22LDU,&var1343);
  setData(idA3AB01LDU,&var1341);
  setData(idA3AB02LDU,&var1342);
  setData(idA3AB04LDU,&var1347);
  setData(idA3CV01RDU,&var1345);
  setData(idA3VS12LDU,&var1344);
  setData(idB1AB18LDU,&var736);
  setData(idB1AB17LDU,&var905);
  setData(idB1AB16LDU,&var904);
  setData(idB1AB14LDU,&var924);
  setData(idB1AB13LDU,&var925);
  setData(idB1AB12LDU,&var734);
  setData(idB1AB11LDU,&var738);
  setData(idB1AB10LDU,&var739);
  setData(idB1AB09LDU,&var742);
  setData(idB1AB06LDU,&var740);
  setData(idB1AB05LDU,&var747);
  setData(idB1AB08LDU,&var735);
  setData(idB1AB07LDU,&var746);
  setData(idB1CV02RDU,&var1368);
  setData(idB1AD01LDU,&var1361);
  setData(idB1AD05LDU,&var1367);
  setData(idB1AD04LDU,&var1366);
  setData(idB1AD03LDU,&var1365);
  setData(idB1AD02LDU,&var1364);
  setData(idB1AD21LDU,&var1363);
  setData(idB1AD11LDU,&var1362);
  setData(idB1AZ03LDU,&var749);
  setData(idB1VS22LDU,&var1373);
  setData(idB1AB01LDU,&var1370);
  setData(idB1AB02LDU,&var1371);
  setData(idB1AB04LDU,&var1376);
  setData(idB1CV01RDU,&var1374);
  setData(idB1VS12LDU,&var1372);
  setData(idA1AB18LDU,&var712);
  setData(idA1AB17LDU,&var711);
  setData(idA1AB16LDU,&var713);
  setData(idA1AB14LDU,&var927);
  setData(idA1AB13LDU,&var928);
  setData(idA1AB12LDU,&var709);
  setData(idA1AB11LDU,&var718);
  setData(idA1AB10LDU,&var716);
  setData(idA1AB09LDU,&var715);
  setData(idA1AB06LDU,&var720);
  setData(idA1AB05LDU,&var721);
  setData(idA1AB08LDU,&var714);
  setData(idA1AB07LDU,&var722);
  setData(idA1CV02RDU,&var1401);
  setData(idA1AD01LDU,&var1394);
  setData(idA1AD05LDU,&var1400);
  setData(idA1AD04LDU,&var1399);
  setData(idA1AD03LDU,&var1398);
  setData(idA1AD02LDU,&var1397);
  setData(idA1AD21LDU,&var1396);
  setData(idA1AD11LDU,&var1395);
  setData(idA1AZ03LDU,&var729);
  setData(idA1VS22LDU,&var1404);
  setData(idA1AB01LDU,&var727);
  setData(idA1AB02LDU,&var728);
  setData(idA1AB04LDU,&var1407);
  setData(idA1CV01RDU,&var1405);
  setData(idA1VS12LDU,&var1403);
  setData(idR1AD20LDU,&var1426);
  setData(idR1AD10LDU,&var1425);
  setData(idR2AB04LDU,&var1414);
  setData(idR1AB04LDU,&var1423);
  setData(idR2AB02LDU,&var1413);
  setData(idR2AB01LDU,&var1415);
  setData(idR2AZ03LDU,&var1412);
  setData(idR1AB02LDU,&var1422);
  setData(idR1AB01LDU,&var1424);
  setData(idR1AZ03LDU,&var1421);
  setData(idB2AB17LDU,&var685);
  setData(idB2AB16LDU,&var684);
  setData(idB2AB14LDU,&var929);
  setData(idB2AB13LDU,&var930);
  setData(idB2AB12LDU,&var686);
  setData(idB2AB11LDU,&var690);
  setData(idB2AB10LDU,&var689);
  setData(idB2AB09LDU,&var688);
  setData(idB2AB06LDU,&var693);
  setData(idB2AB05LDU,&var692);
  setData(idB2AB08LDU,&var687);
  setData(idB2AB07LDU,&var694);
  setData(idB2CV02RDU,&var1448);
  setData(idB2AD01LDU,&var1441);
  setData(idB2AD05LDU,&var1447);
  setData(idB2AD04LDU,&var1446);
  setData(idB2AD03LDU,&var1445);
  setData(idB2AD02LDU,&var1444);
  setData(idB2AD21LDU,&var1443);
  setData(idB2AD11LDU,&var1442);
  setData(idB2AZ03LDU,&var702);
  setData(idB2AB01LDU,&var701);
  setData(idB2AB02LDU,&var700);
  setData(idB2AB04LDU,&var1454);
  setData(idB2CV01RDU,&var1452);
  setData(idA2CV02RDU,&var1489);
  setData(idA2AD01LDU,&var1482);
  setData(idA2AB17LDU,&var623);
  setData(idA2AB16LDU,&var624);
  setData(idA2AB14LDU,&var627);
  setData(idA2AB13LDU,&var628);
  setData(idA2AB12LDU,&var625);
  setData(idA2AB11LDU,&var633);
  setData(idA2AB10LDU,&var631);
  setData(idA2AB09LDU,&var629);
  setData(idA2AB06LDU,&var634);
  setData(idA2AB05LDU,&var630);
  setData(idA2AB08LDU,&var626);
  setData(idA2AB07LDU,&var632);
  setData(idA2AD05LDU,&var1488);
  setData(idA2AD04LDU,&var1487);
  setData(idA2AD03LDU,&var1486);
  setData(idA2AD02LDU,&var1485);
  setData(idA2AD21LDU,&var1484);
  setData(idA2AD11LDU,&var1483);
  setData(idA2AZ03LDU,&var994);
  setData(idA2VS21LDU,&var1494);
  setData(idA2AB01LDU,&var1491);
  setData(idA2AB02LDU,&var1492);
  setData(idA2AB04LDU,&var1497);
  setData(idA2CV01RDU,&var1495);
  setData(idA2VS11LDU,&var1493);
  setData(idA8AB01LDU,&var1505);
  setData(idA8AB02LDU,&var511);
  setData(idA8AB14LDU,&var512);
  setData(idA8AB13LDU,&var513);
  setData(idA8AB12LDU,&var515);
  setData(idA8AB11LDU,&var516);
  setData(idA8AB10LDU,&var517);
  setData(idA8AB09LDU,&var518);
  setData(idA8AB08LDU,&var519);
  setData(idA8AB04LDU,&var1504);
  setData(idA8AD20LDU,&var1460);
  setData(idA8AD10LDU,&var1459);
  setData(idA8AZ03LDU,&var984);
  setData(idA8VS22LDU,&var1507);
  setData(idA8AB05LDU,&var1502);
  setData(idA8AB07LDU,&var1503);
  setData(idA8AB06LDU,&var1510);
  setData(idA8CV01RDU,&var1508);
  setData(idA8VS12LDU,&var1506);
  setData(idB8AB02LDU,&var829);
  setData(idB8AB14LDU,&var830);
  setData(idB8AB13LDU,&var831);
  setData(idB8AB12LDU,&var832);
  setData(idB8AB11LDU,&var836);
  setData(idB8AB10LDU,&var833);
  setData(idB8AB09LDU,&var834);
  setData(idB8AB08LDU,&var835);
  setData(idB8AB04LDU,&var1521);
  setData(idB8AB01LDU,&var1522);
  setData(idB8AD20LDU,&var1470);
  setData(idB8AD10LDU,&var1469);
  setData(idB8AZ03LDU,&var985);
  setData(idB8VS22LDU,&var1524);
  setData(idB8AB05LDU,&var1513);
  setData(idB8AB07LDU,&var1514);
  setData(idB8AB06LDU,&var1527);
  setData(idB8CV01RDU,&var1525);
  setData(idB8VS12LDU,&var1523);
  setData(idA6AB05LDU,&var952);
  setData(idB6AB09LDU,&var951);
  setData(idB6AB08LDU,&var950);
  setData(idB6AB07LDU,&var949);
  setData(idB6AB06LDU,&var948);
  setData(idA6AB09LDU,&var953);
  setData(idA6AB08LDU,&var939);
  setData(idA6AB07LDU,&var141);
  setData(idA6AB06LDU,&var954);
  setData(idB5AB04LDU,&var1577);
  setData(idA5AB04LDU,&var1586);
  setData(idB4AB02LDU,&var1558);
  setData(idB4AB01LDU,&var1559);
  setData(idB4AZ03LDU,&var1557);
  setData(idA4AB02LDU,&var1567);
  setData(idA4AB01LDU,&var1568);
  setData(idA4AZ03LDU,&var1566);
  setData(idA4AD10LDU,&var1569);
  setData(idB4AD10LDU,&var1560);
  setData(idB5AB02LDU,&var1576);
  setData(idB5AB01LDU,&var1578);
  setData(idB5AZ03LDU,&var1575);
  setData(idA5AB02LDU,&var1585);
  setData(idA5AB01LDU,&var1587);
  setData(idA5AZ03LDU,&var1584);
  setData(idA5AD20LDU,&var1589);
  setData(idA5AD10LDU,&var1588);
  setData(idB5AD20LDU,&var1580);
  setData(idB5AD10LDU,&var1579);
  setData(idR4AD20LDU,&var1598);
  setData(idR4AD10LDU,&var1597);
  setData(idR4AB18LDU,&var882);
  setData(idR4AB17LDU,&var881);
  setData(idR4AB16LDU,&var884);
  setData(idR4AB15LDU,&var883);
  setData(idR4AB14LDU,&var885);
  setData(idR4AB13LDU,&var853);
  setData(idR4AB12LDU,&var858);
  setData(idR4AB11LDU,&var890);
  setData(idR4AB10LDU,&var855);
  setData(idR4AB09LDU,&var888);
  setData(idR4AB08LDU,&var887);
  setData(idR4AB07LDU,&var891);
  setData(idR4AB06LDU,&var1595);
  setData(idR4AB05LDU,&var1594);
  setData(idR4AB04LDU,&var1596);
  setData(idR4AB03LDU,&var892);
  setData(idR4AZ03LDU,&var1593);
  setData(idR4AB02LDU,&var895);
  setData(idR4AB01LDU,&var896);
  setData(idB6AB04LDU,&var1604);
  setData(idA6AB04LDU,&var1613);
  setData(idB6AB02LDU,&var1603);
  setData(idB6AB01LDU,&var1605);
  setData(idB6AZ03LDU,&var1602);
  setData(idA6AB02LDU,&var1612);
  setData(idA6AB01LDU,&var1614);
  setData(idA6AZ03LDU,&var1611);
  setData(idB6AD20LDU,&var1607);
  setData(idB6AD10LDU,&var1606);
  setData(idA6AD20LDU,&var1616);
  setData(idA6AD10LDU,&var1615);
  setData(idR0ES01LDU,&var900);

  setAsBool(idbFirstEnterFlag,1); 
 }
 else {
      delay = 0;
      if (freebuff)
            return;
       else{
           freebuff = 1;
           memset(BUFFER, 0, SIZE_BUFFER);
           InitSetConst();
           initAllDrivers(drivers);
           }
       }

}

void InitInternalParametr(void)
{
  int i;
  for( i=0;i<10;i++ )
    array_m325_rz_1[i] = &(&internal1_m325_rz)[i*1];
  for( i=0;i<10;i++ )
    array_m268_rz_1[i] = &(&internal1_m268_rz)[i*1];
  for( i=0;i<6;i++ )
    array_m1390_rz_1[i] = &(&internal1_m1390_rz)[i*1];
  for( i=0;i<60;i++ )
    array_m1317_x0_1[i] = &(&internal1_m1317_x0)[i*5];
  for( i=0;i<60;i++ )
    array_m1317_tim0_1[i] = &(&internal1_m1317_tim0)[i*5];
  for( i=0;i<60;i++ )
    array_m920_x0_1[i] = &(&internal1_m920_x0)[i*5];
  for( i=0;i<60;i++ )
    array_m920_tim0_1[i] = &(&internal1_m920_tim0)[i*5];
  for( i=0;i<150;i++ )
    array_m516_x0_1[i] = &(&internal1_m516_x0)[i*5];
  for( i=0;i<150;i++ )
    array_m516_tim0_1[i] = &(&internal1_m516_tim0)[i*5];
  for( i=0;i<150;i++ )
    array_m197_x0_1[i] = &(&internal1_m197_x0)[i*5];
  for( i=0;i<150;i++ )
    array_m197_tim0_1[i] = &(&internal1_m197_tim0)[i*5];
  for( i=0;i<80;i++ )
    array_m827_x0_1[i] = &(&internal1_m827_x0)[i*5];
  for( i=0;i<80;i++ )
    array_m827_tim0_1[i] = &(&internal1_m827_tim0)[i*5];
  for( i=0;i<80;i++ )
    array_m1226_x0_1[i] = &(&internal1_m1226_x0)[i*5];
  for( i=0;i<80;i++ )
    array_m1226_tim0_1[i] = &(&internal1_m1226_tim0)[i*5];
  for( i=0;i<20;i++ )
    array_m1591_x0_1[i] = &(&internal1_m1591_x0)[i*5];
  for( i=0;i<20;i++ )
    array_m1591_tim0_1[i] = &(&internal1_m1591_tim0)[i*5];
  for( i=0;i<20;i++ )
    array_m1131_x0_1[i] = &(&internal1_m1131_x0)[i*5];
  for( i=0;i<20;i++ )
    array_m1131_tim0_1[i] = &(&internal1_m1131_tim0)[i*5];
}

#endif
