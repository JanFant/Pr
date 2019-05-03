#ifndef DU_H
#define DU_H
// Подсистема DU:DU
static char SimulOn=0;
static short CodeSub=2;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt, taktScheme=0, taktSS=0;
#define SIZE_BUFFER 11950
static char BUFFER[11950];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.50\0", 5432, "192.168.10.150\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define B4IS10LDU	 BUFFER[0]	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
#define idB4IS10LDU	 1	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
#define R6IS31LDU	 BUFFER[2]	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
#define idR6IS31LDU	 2	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
#define R6IS32LDU	 BUFFER[4]	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
#define idR6IS32LDU	 3	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
#define R6IS42LDU	 BUFFER[6]	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
#define idR6IS42LDU	 4	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
#define R6IS41LDU	 BUFFER[8]	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
#define idR6IS41LDU	 5	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
#define R6IS52LDU	 BUFFER[10]	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
#define idR6IS52LDU	 6	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
#define R6IS51LDU	 BUFFER[12]	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
#define idR6IS51LDU	 7	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
#define R3IS11LDU	 BUFFER[14]	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
#define idR3IS11LDU	 8	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
#define R3IS21LDU	 BUFFER[16]	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
#define idR3IS21LDU	 9	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
#define R0AB03LDU	 BUFFER[18]	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
#define idR0AB03LDU	 10	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
#define R0AB05LDU	 BUFFER[20]	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
#define idR0AB05LDU	 11	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
#define R0VN11RZ1	 BUFFER[22]	//( - , MDuBz1) Средняя мощность по BAZ1
#define idR0VN11RZ1	 12	//( - , MDuBz1) Средняя мощность по BAZ1
#define R0VN11RZ2	 BUFFER[27]	//( - , MDuBz2) Средняя мощность по BAZ2
#define idR0VN11RZ2	 13	//( - , MDuBz2) Средняя мощность по BAZ2
#define A2AB15LDU	 BUFFER[32]	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define idA2AB15LDU	 14	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define B2AB15LDU	 BUFFER[34]	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define idB2AB15LDU	 15	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define R0AD21LDU	 BUFFER[36]	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
#define idR0AD21LDU	 16	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
#define R0VX02LDU	 BUFFER[38]	//( - , DU) Импульс разрешен
#define idR0VX02LDU	 17	//( - , DU) Импульс разрешен
#define R0EE03LDU	 BUFFER[40]	//( - , DU) ВПИС ИС
#define idR0EE03LDU	 18	//( - , DU) ВПИС ИС
#define R0AB07LDU	 BUFFER[42]	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
#define idR0AB07LDU	 19	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
#define R0AD16LDU	 BUFFER[44]	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
#define idR0AD16LDU	 20	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
#define C2MD31LP1	 BUFFER[46]	//( - , DU) Кнопка СБРОС РБ
#define idC2MD31LP1	 21	//( - , DU) Кнопка СБРОС РБ
#define B6VS01IDU	 BUFFER[48]	//( - , DU) Готовность к управлению БЗ2
#define idB6VS01IDU	 22	//( - , DU) Готовность к управлению БЗ2
#define R2AD20LDU	 BUFFER[51]	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
#define idR2AD20LDU	 23	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
#define B3MD11LP1	 BUFFER[53]	//( - , DU) Кнопка ПУСК ИС2
#define idB3MD11LP1	 24	//( - , DU) Кнопка ПУСК ИС2
#define R0VL01RDU	 BUFFER[55]	//( - , DU) Индикация Время задержки
#define idR0VL01RDU	 25	//( - , DU) Индикация Время задержки
#define R0VZ71LZ2	 BUFFER[60]	//(vds32:03 - K22VDSR, - ) Обобщенный сигнал АЗ 2 канала
#define idR0VZ71LZ2	 26	//(vds32:03 - K22VDSR, - ) Обобщенный сигнал АЗ 2 канала
#define R0VZ71LZ1	 BUFFER[62]	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
#define idR0VZ71LZ1	 27	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
#define R0VZ71LDU	 BUFFER[64]	//( - , DU) Обобщенный сигнал АЗ
#define idR0VZ71LDU	 28	//( - , DU) Обобщенный сигнал АЗ
#define A2IS33LDU	 BUFFER[66]	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
#define idA2IS33LDU	 29	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
#define A3IS31LDU	 BUFFER[68]	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
#define idA3IS31LDU	 30	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
#define A3IS33LDU	 BUFFER[70]	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
#define idA3IS33LDU	 31	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
#define A3IS35LDU	 BUFFER[72]	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
#define idA3IS35LDU	 32	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
#define A4IS10LDU	 BUFFER[74]	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
#define idA4IS10LDU	 33	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
#define A1VN71LZ1	 BUFFER[76]	//(vds32:02 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define idA1VN71LZ1	 34	//(vds32:02 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define A1VN71LZ2	 BUFFER[78]	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define idA1VN71LZ2	 35	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define A1AB19LDU	 BUFFER[80]	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
#define idA1AB19LDU	 36	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
#define R0AD14LZ1	 BUFFER[82]	//(vds32:02 - K20VDSR, DU) Имитация срабатывания АЗ от II УР
#define idR0AD14LZ1	 37	//(vds32:02 - K20VDSR, DU) Имитация срабатывания АЗ от II УР
#define R0AD14LZ2	 BUFFER[84]	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
#define idR0AD14LZ2	 38	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
#define A3VZ13LZ2	 BUFFER[86]	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ2	 39	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define A3VZ13LZ1	 BUFFER[88]	//(vds32:02 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ1	 40	//(vds32:02 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define A3VZ15LZ1	 BUFFER[90]	//(vds32:02 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ1	 41	//(vds32:02 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define A3VZ15LZ2	 BUFFER[92]	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ2	 42	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define B2IS33LDU	 BUFFER[94]	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
#define idB2IS33LDU	 43	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
#define B3IS31LDU	 BUFFER[96]	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
#define idB3IS31LDU	 44	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
#define B3IS33LDU	 BUFFER[98]	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
#define idB3IS33LDU	 45	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
#define B3IS35LDU	 BUFFER[100]	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
#define idB3IS35LDU	 46	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
#define R0AB09LDU	 BUFFER[102]	//( - , DU) Ошибка в заданной координате ББ1
#define idR0AB09LDU	 47	//( - , DU) Ошибка в заданной координате ББ1
#define R0AB10LDU	 BUFFER[104]	//( - , DU) Ошибка в заданной координате ББ2
#define idR0AB10LDU	 48	//( - , DU) Ошибка в заданной координате ББ2
#define R0AB11LDU	 BUFFER[106]	//( - , DU) Ошибка в заданной координате  ИС1
#define idR0AB11LDU	 49	//( - , DU) Ошибка в заданной координате  ИС1
#define R0AB12LDU	 BUFFER[108]	//( - , DU) Ошибка в заданной координате  ИС2
#define idR0AB12LDU	 50	//( - , DU) Ошибка в заданной координате  ИС2
#define R0AB13LDU	 BUFFER[110]	//( - , DU) Ошибка в заданной координате  АЗ2
#define idR0AB13LDU	 51	//( - , DU) Ошибка в заданной координате  АЗ2
#define A4ZAV	 BUFFER[112]	//( - , DU) 
#define idA4ZAV	 52	//( - , DU) 
#define A6ZAV	 BUFFER[114]	//( - , DU) 
#define idA6ZAV	 53	//( - , DU) 
#define R2ZAV	 BUFFER[116]	//( - , DU) 
#define idR2ZAV	 54	//( - , DU) 
#define A5ZAV	 BUFFER[118]	//( - , DU) 
#define idA5ZAV	 55	//( - , DU) 
#define B8ZAV	 BUFFER[120]	//( - , DU) 
#define idB8ZAV	 56	//( - , DU) 
#define A2ZAV	 BUFFER[122]	//( - , DU) Завершение РБ1,2
#define idA2ZAV	 57	//( - , DU) Завершение РБ1,2
#define A8ZAV	 BUFFER[124]	//( - , DU) 
#define idA8ZAV	 58	//( - , DU) 
#define A9ZAV	 BUFFER[126]	//( - , DU) Завершение НИ ДС1(2)
#define idA9ZAV	 59	//( - , DU) Завершение НИ ДС1(2)
#define R4ABL	 BUFFER[128]	//( - , DU) Блокировка тележки -
#define idR4ABL	 60	//( - , DU) Блокировка тележки -
#define A4UP	 BUFFER[130]	//( - , DU) 
#define idA4UP	 61	//( - , DU) 
#define A4DW	 BUFFER[132]	//( - , DU) 
#define idA4DW	 62	//( - , DU) 
#define R0AB14LDU	 BUFFER[134]	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
#define idR0AB14LDU	 63	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
#define R0AB15LDU	 BUFFER[136]	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
#define idR0AB15LDU	 64	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
#define A3IS12LDU	 BUFFER[138]	//( - , DU) Приход на ВУ штока ИС1
#define idA3IS12LDU	 65	//( - , DU) Приход на ВУ штока ИС1
#define B3IS12LDU	 BUFFER[140]	//( - , DU) Приход на ВУ штока ИС2
#define idB3IS12LDU	 66	//( - , DU) Приход на ВУ штока ИС2
#define A1ZAV	 BUFFER[142]	//( - , DU) 
#define idA1ZAV	 67	//( - , DU) 
#define A3ZAV	 BUFFER[144]	//( - , DU) 
#define idA3ZAV	 68	//( - , DU) 
#define B1AB19LDU	 BUFFER[146]	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
#define idB1AB19LDU	 69	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
#define R2AD10LDU	 BUFFER[148]	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
#define idR2AD10LDU	 70	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
#define B8VS01IDU	 BUFFER[150]	//( - , DU) Готовность к управлению АЗ2
#define idB8VS01IDU	 71	//( - , DU) Готовность к управлению АЗ2
#define A8VS01IDU	 BUFFER[153]	//( - , DU) Готовность к управлению ДС2
#define idA8VS01IDU	 72	//( - , DU) Готовность к управлению ДС2
#define A1IE03LDU	 BUFFER[156]	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
#define idA1IE03LDU	 73	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
#define A1IE04LDU	 BUFFER[158]	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
#define idA1IE04LDU	 74	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
#define A2IE03LDU	 BUFFER[160]	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
#define idA2IE03LDU	 75	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
#define A2IE04LDU	 BUFFER[162]	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
#define idA2IE04LDU	 76	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
#define A3IE03LDU	 BUFFER[164]	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
#define idA3IE03LDU	 77	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
#define A3IE04LDU	 BUFFER[166]	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
#define idA3IE04LDU	 78	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
#define B1IE03LDU	 BUFFER[168]	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
#define idB1IE03LDU	 79	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
#define B1IE04LDU	 BUFFER[170]	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
#define idB1IE04LDU	 80	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
#define B2IE03LDU	 BUFFER[172]	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
#define idB2IE03LDU	 81	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
#define B2IE04LDU	 BUFFER[174]	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
#define idB2IE04LDU	 82	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
#define B3IE03LDU	 BUFFER[176]	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
#define idB3IE03LDU	 83	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
#define B3IE04LDU	 BUFFER[178]	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
#define idB3IE04LDU	 84	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
#define R0VS11LDU	 BUFFER[180]	//( - , DU) РУ не готова к работе
#define idR0VS11LDU	 85	//( - , DU) РУ не готова к работе
#define B6AB05LDU	 BUFFER[182]	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
#define idB6AB05LDU	 86	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
#define R0AB08LDU	 BUFFER[184]	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
#define idR0AB08LDU	 87	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
#define A1MC01RP1	 BUFFER[186]	//( - , DU) Заданная координата положения ББ1 мм
#define idA1MC01RP1	 88	//( - , DU) Заданная координата положения ББ1 мм
#define B1MC01RP1	 BUFFER[191]	//( - , DU) Заданная координата положения ББ2  мм
#define idB1MC01RP1	 89	//( - , DU) Заданная координата положения ББ2  мм
#define A3MC01RP1	 BUFFER[196]	//( - , DU) Заданная координата положения ИС1 мм
#define idA3MC01RP1	 90	//( - , DU) Заданная координата положения ИС1 мм
#define B3MC01RP1	 BUFFER[201]	//( - , DU) Заданная координата положения ИС2 мм
#define idB3MC01RP1	 91	//( - , DU) Заданная координата положения ИС2 мм
#define B8MC01RP2	 BUFFER[206]	//( - , DU) Заданная координата АЗ2 мм
#define idB8MC01RP2	 92	//( - , DU) Заданная координата АЗ2 мм
#define A9IS11LDU	 BUFFER[211]	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
#define idA9IS11LDU	 93	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
#define A9IS21LDU	 BUFFER[213]	//(vds32:02 - K24VDSR, - ) Приход на НУ НИ ДС1
#define idA9IS21LDU	 94	//(vds32:02 - K24VDSR, - ) Приход на НУ НИ ДС1
#define B9IS11LDU	 BUFFER[215]	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
#define idB9IS11LDU	 95	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
#define B9IS21LDU	 BUFFER[217]	//(vds32:02 - K26VDSR, - ) Приход на НУ НИ ДС2
#define idB9IS21LDU	 96	//(vds32:02 - K26VDSR, - ) Приход на НУ НИ ДС2
#define B9AD10LDU	 BUFFER[219]	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
#define idB9AD10LDU	 97	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
#define A9AD10LDU	 BUFFER[221]	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
#define idA9AD10LDU	 98	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
#define A9AZ03LDU	 BUFFER[223]	//( - , DU) Несанкционированное перемещение НИ ДС1
#define idA9AZ03LDU	 99	//( - , DU) Несанкционированное перемещение НИ ДС1
#define A9AB01LDU	 BUFFER[225]	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
#define idA9AB01LDU	 100	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
#define A9AB02LDU	 BUFFER[227]	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
#define idA9AB02LDU	 101	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
#define B9AZ03LDU	 BUFFER[229]	//( - , DU) Несанкционированное перемещение НИ ДС2
#define idB9AZ03LDU	 102	//( - , DU) Несанкционированное перемещение НИ ДС2
#define B9AB01LDU	 BUFFER[231]	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
#define idB9AB01LDU	 103	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
#define B9AB02LDU	 BUFFER[233]	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
#define idB9AB02LDU	 104	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
#define R0AB01LDU	 BUFFER[235]	//( - , DU) Режим проверки разрешён
#define idR0AB01LDU	 105	//( - , DU) Режим проверки разрешён
#define A3IS22LDU	 BUFFER[237]	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
#define idA3IS22LDU	 106	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
#define B3IS22LDU	 BUFFER[239]	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
#define idB3IS22LDU	 107	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
#define A2AD33LDU	 BUFFER[241]	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
#define idA2AD33LDU	 108	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
#define B2AD33LDU	 BUFFER[243]	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
#define idB2AD33LDU	 109	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
#define A3AD33LDU	 BUFFER[245]	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
#define idA3AD33LDU	 110	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
#define A3AD34LDU	 BUFFER[247]	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
#define idA3AD34LDU	 111	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
#define A3AD31LDU	 BUFFER[249]	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
#define idA3AD31LDU	 112	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
#define B3AD34LDU	 BUFFER[251]	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
#define idB3AD34LDU	 113	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
#define B3AD31LDU	 BUFFER[253]	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
#define idB3AD31LDU	 114	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
#define A2IS11LDU	 BUFFER[255]	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
#define idA2IS11LDU	 115	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
#define R0AB02LDU	 BUFFER[257]	//( - , DU) Нарушение времени задержки ИНИ
#define idR0AB02LDU	 116	//( - , DU) Нарушение времени задержки ИНИ
#define R0VL03RDU	 BUFFER[259]	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define idR0VL03RDU	 117	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define R0VL05RDU	 BUFFER[264]	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
#define idR0VL05RDU	 118	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
#define R0VL21IDU	 BUFFER[269]	//( - , DU) Декатрон
#define idR0VL21IDU	 119	//( - , DU) Декатрон
#define R0VX03LDU	 BUFFER[272]	//( - , DU) Готовность 2 мин
#define idR0VX03LDU	 120	//( - , DU) Готовность 2 мин
#define R0VS21IDU	 BUFFER[274]	//( - , DU) Индикация ВИД ПРОВЕРКИ
#define idR0VS21IDU	 121	//( - , DU) Индикация ВИД ПРОВЕРКИ
#define A1VS01IDU	 BUFFER[277]	//( - , DU) Готовность к управлению ББ1
#define idA1VS01IDU	 122	//( - , DU) Готовность к управлению ББ1
#define B1VS01IDU	 BUFFER[280]	//( - , DU) Готовность к управлению ББ2
#define idB1VS01IDU	 123	//( - , DU) Готовность к управлению ББ2
#define A3VS01IDU	 BUFFER[283]	//( - , DU) Готовность к управлению ИС1
#define idA3VS01IDU	 124	//( - , DU) Готовность к управлению ИС1
#define B3VS01IDU	 BUFFER[286]	//( - , DU) Готовность к управлению ИС2
#define idB3VS01IDU	 125	//( - , DU) Готовность к управлению ИС2
#define A2VS01IDU	 BUFFER[289]	//( - , DU) Готовность к управлению РБ1
#define idA2VS01IDU	 126	//( - , DU) Готовность к управлению РБ1
#define A4VS01IDU	 BUFFER[292]	//( - , DU) Готовность к управлению НИ1
#define idA4VS01IDU	 127	//( - , DU) Готовность к управлению НИ1
#define A4VS12LDU	 BUFFER[295]	//( - , DU) Движение НИ1 в сторону ВУ
#define idA4VS12LDU	 128	//( - , DU) Движение НИ1 в сторону ВУ
#define A4VS22LDU	 BUFFER[297]	//( - , DU) Движение НИ1 в сторону НУ
#define idA4VS22LDU	 129	//( - , DU) Движение НИ1 в сторону НУ
#define B4VS01IDU	 BUFFER[299]	//( - , DU) Готовность к управлению НИ2
#define idB4VS01IDU	 130	//( - , DU) Готовность к управлению НИ2
#define B4VS12LDU	 BUFFER[302]	//( - , DU) Движение НИ2 в сторону ВУ
#define idB4VS12LDU	 131	//( - , DU) Движение НИ2 в сторону ВУ
#define B4VS22LDU	 BUFFER[304]	//( - , DU) Движение НИ2 в сторону НУ
#define idB4VS22LDU	 132	//( - , DU) Движение НИ2 в сторону НУ
#define A5VS01IDU	 BUFFER[306]	//( - , DU) Готовность к управлению НЛ1
#define idA5VS01IDU	 133	//( - , DU) Готовность к управлению НЛ1
#define B5VS01IDU	 BUFFER[309]	//( - , DU) Готовность к управлению НЛ2
#define idB5VS01IDU	 134	//( - , DU) Готовность к управлению НЛ2
#define A6VS01IDU	 BUFFER[312]	//( - , DU) Готовность к управлению БЗ1
#define idA6VS01IDU	 135	//( - , DU) Готовность к управлению БЗ1
#define R4VS01IDU	 BUFFER[315]	//( - , DU) Готовность к управлению тележкой реактора
#define idR4VS01IDU	 136	//( - , DU) Готовность к управлению тележкой реактора
#define R2VS01IDU	 BUFFER[318]	//( - , DU) Готовность к управлению МДЗ2
#define idR2VS01IDU	 137	//( - , DU) Готовность к управлению МДЗ2
#define R1VS01IDU	 BUFFER[321]	//( - , DU) Готовность к управлению МДЗ1
#define idR1VS01IDU	 138	//( - , DU) Готовность к управлению МДЗ1
#define B1MD12LP1	 BUFFER[324]	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
#define idB1MD12LP1	 139	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
#define B2MD11LP1	 BUFFER[326]	//( - , DU) Кнопка ПУСК РБ2
#define idB2MD11LP1	 140	//( - , DU) Кнопка ПУСК РБ2
#define B2MD12LP1	 BUFFER[328]	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
#define idB2MD12LP1	 141	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
#define A2MD11LP1	 BUFFER[330]	//( - , DU) Кнопка ПУСК РБ1
#define idA2MD11LP1	 142	//( - , DU) Кнопка ПУСК РБ1
#define A2MD12LP1	 BUFFER[332]	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
#define idA2MD12LP1	 143	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
#define R0IS01LDU	 BUFFER[334]	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
#define idR0IS01LDU	 144	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
#define R0IS02LDU	 BUFFER[336]	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
#define idR0IS02LDU	 145	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
#define R0VP73LZ1	 BUFFER[338]	//( - , MDuBz1) ПС давления для РУ
#define idR0VP73LZ1	 146	//( - , MDuBz1) ПС давления для РУ
#define R0VP73LZ2	 BUFFER[340]	//( - , MDuBz2) ПС давления для РУ
#define idR0VP73LZ2	 147	//( - , MDuBz2) ПС давления для РУ
#define R0VP73LDU	 BUFFER[342]	//( - , DU) ПС давления для РУ
#define idR0VP73LDU	 148	//( - , DU) ПС давления для РУ
#define R0MD34LP1	 BUFFER[344]	//( - , DU) Кнопка КВИТИРОВАТЬ
#define idR0MD34LP1	 149	//( - , DU) Кнопка КВИТИРОВАТЬ
#define A0VT71LZ1	 BUFFER[346]	//( - , MDuBz1) АС по температуре в АЗ1
#define idA0VT71LZ1	 150	//( - , MDuBz1) АС по температуре в АЗ1
#define B0VT71LZ1	 BUFFER[348]	//( - , MDuBz1) АС по температуре в АЗ2
#define idB0VT71LZ1	 151	//( - , MDuBz1) АС по температуре в АЗ2
#define A0VT71LZ2	 BUFFER[350]	//( - , MDuBz2) АС по температуре в АЗ1
#define idA0VT71LZ2	 152	//( - , MDuBz2) АС по температуре в АЗ1
#define B0VT71LZ2	 BUFFER[352]	//( - , MDuBz2) АС по температуре в АЗ2
#define idB0VT71LZ2	 153	//( - , MDuBz2) АС по температуре в АЗ2
#define B2VS11LDU	 BUFFER[354]	//( - , DU) Движение РБ2 в сторону ВУ
#define idB2VS11LDU	 154	//( - , DU) Движение РБ2 в сторону ВУ
#define B2VS21LDU	 BUFFER[356]	//( - , DU) Движение РБ2 в сторону НУ
#define idB2VS21LDU	 155	//( - , DU) Движение РБ2 в сторону НУ
#define B2VS01IDU	 BUFFER[358]	//( - , DU) Готовность к управлению РБ2
#define idB2VS01IDU	 156	//( - , DU) Готовность к управлению РБ2
#define A7AS31LDU	 BUFFER[361]	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
#define idA7AS31LDU	 157	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
#define B7AS31LDU	 BUFFER[363]	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
#define idB7AS31LDU	 158	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
#define A7AZ03LDU	 BUFFER[365]	//( - , DU) Несанкционированное включение обдува АЗ1
#define idA7AZ03LDU	 159	//( - , DU) Несанкционированное включение обдува АЗ1
#define B7AZ03LDU	 BUFFER[367]	//( - , DU) Несанкционированное включение обдува АЗ2
#define idB7AZ03LDU	 160	//( - , DU) Несанкционированное включение обдува АЗ2
#define B3MD12LP1	 BUFFER[369]	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
#define idB3MD12LP1	 161	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
#define B2IS11LDU	 BUFFER[371]	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
#define idB2IS11LDU	 162	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
#define A3MD12LP1	 BUFFER[373]	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
#define idA3MD12LP1	 163	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
#define A3MD11LP1	 BUFFER[375]	//( - , DU) Кнопка ПУСК ИС1
#define idA3MD11LP1	 164	//( - , DU) Кнопка ПУСК ИС1
#define R0MD33LP1	 BUFFER[377]	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
#define idR0MD33LP1	 165	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
#define A1MD12LP1	 BUFFER[379]	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
#define idA1MD12LP1	 166	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
#define A1MD11LP1	 BUFFER[381]	//( - , DU) Кнопка ПУСК ББ1
#define idA1MD11LP1	 167	//( - , DU) Кнопка ПУСК ББ1
#define R0MW14IP2	 BUFFER[383]	//( - , DU) Переключатель ОБДУВ
#define idR0MW14IP2	 168	//( - , DU) Переключатель ОБДУВ
#define A7AP31LDU	 BUFFER[386]	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
#define idA7AP31LDU	 169	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
#define B7AP31LDU	 BUFFER[388]	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
#define idB7AP31LDU	 170	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
#define R0MW12IP2	 BUFFER[390]	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define idR0MW12IP2	 171	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define R0MW17LP1	 BUFFER[393]	//( - , DU) Переключатель АВТ/Р
#define idR0MW17LP1	 172	//( - , DU) Переключатель АВТ/Р
#define R0VW13LDU	 BUFFER[395]	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
#define idR0VW13LDU	 173	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
#define R0VW23LDU	 BUFFER[397]	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
#define idR0VW23LDU	 174	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
#define R0VX08IDU	 BUFFER[399]	//( - , DU) Индикация Режим
#define idR0VX08IDU	 175	//( - , DU) Индикация Режим
#define R0VX09LDU	 BUFFER[402]	//( - , DU) Индикация регулятор мощности включен/отключен
#define idR0VX09LDU	 176	//( - , DU) Индикация регулятор мощности включен/отключен
#define R0VS17LDU	 BUFFER[404]	//( - , DU) Индикация выбора АВТОМАТ
#define idR0VS17LDU	 177	//( - , DU) Индикация выбора АВТОМАТ
#define A2VS32LDU	 BUFFER[406]	//( - , DU) Индикация  СБРОС РБ1
#define idA2VS32LDU	 178	//( - , DU) Индикация  СБРОС РБ1
#define B2VS32LDU	 BUFFER[408]	//( - , DU) Индикация  СБРОС РБ2
#define idB2VS32LDU	 179	//( - , DU) Индикация  СБРОС РБ2
#define A3VX01LDU	 BUFFER[410]	//( - , DU) Индикация Выстрел ИС1
#define idA3VX01LDU	 180	//( - , DU) Индикация Выстрел ИС1
#define A3IS11LDU	 BUFFER[412]	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
#define idA3IS11LDU	 181	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
#define B3VX01LDU	 BUFFER[414]	//( - , DU) Индикация Выстрел ИС2
#define idB3VX01LDU	 182	//( - , DU) Индикация Выстрел ИС2
#define R0VS18LDU	 BUFFER[416]	//( - , DU) Индикация  Проверка схем сброса
#define idR0VS18LDU	 183	//( - , DU) Индикация  Проверка схем сброса
#define B1MD11LP1	 BUFFER[418]	//( - , DU) Кнопка ПУСК ББ2
#define idB1MD11LP1	 184	//( - , DU) Кнопка ПУСК ББ2
#define B8MC01LC2	 BUFFER[420]	//( - , DU) Настроить энкодер АЗ2
#define idB8MC01LC2	 185	//( - , DU) Настроить энкодер АЗ2
#define A8MC01LC1	 BUFFER[422]	//( - , DU) Настроить энкодер ДС2
#define idA8MC01LC1	 186	//( - , DU) Настроить энкодер ДС2
#define A8MC01LC2	 BUFFER[424]	//( - , DU) Настроить энкодер ДС2
#define idA8MC01LC2	 187	//( - , DU) Настроить энкодер ДС2
#define A3VP42LDU	 BUFFER[426]	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
#define idA3VP42LDU	 188	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
#define A3CP02RDU	 BUFFER[428]	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
#define idA3CP02RDU	 189	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
#define A3VP52LDU	 BUFFER[433]	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define idA3VP52LDU	 190	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define B3VP42LDU	 BUFFER[435]	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
#define idB3VP42LDU	 191	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
#define B3CP02RDU	 BUFFER[437]	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
#define idB3CP02RDU	 192	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
#define B3VP52LDU	 BUFFER[442]	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define idB3VP52LDU	 193	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define B3VP82LDU	 BUFFER[444]	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
#define idB3VP82LDU	 194	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
#define A3VP82LDU	 BUFFER[446]	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
#define idA3VP82LDU	 195	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
#define A3IP02IDU	 BUFFER[448]	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	 196	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
#define B3IP02IDU	 BUFFER[451]	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
#define idB3IP02IDU	 197	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
#define A0VE01LDU	 BUFFER[454]	//( - , DU) Напряжение в системы АЗ1 подано
#define idA0VE01LDU	 198	//( - , DU) Напряжение в системы АЗ1 подано
#define B0VE01LDU	 BUFFER[456]	//( - , DU) Напряжение в системы АЗ2 подано
#define idB0VE01LDU	 199	//( - , DU) Напряжение в системы АЗ2 подано
#define A0VP01LDU	 BUFFER[458]	//( - , DU) Давление в системы АЗ1 подано
#define idA0VP01LDU	 200	//( - , DU) Давление в системы АЗ1 подано
#define B0VP01LDU	 BUFFER[460]	//( - , DU) Давление в системы АЗ2 подано
#define idB0VP01LDU	 201	//( - , DU) Давление в системы АЗ2 подано
#define A0EE01LZ1	 BUFFER[462]	//( - , MDuBz1) Исправность АКНП1
#define idA0EE01LZ1	 202	//( - , MDuBz1) Исправность АКНП1
#define A0EE03LZ1	 BUFFER[464]	//( - , MDuBz1) Исправность АКНП3
#define idA0EE03LZ1	 203	//( - , MDuBz1) Исправность АКНП3
#define A0EE02LZ1	 BUFFER[466]	//( - , MDuBz1) Исправность АКНП2
#define idA0EE02LZ1	 204	//( - , MDuBz1) Исправность АКНП2
#define A0EE04LZ1	 BUFFER[468]	//( - , MDuBz1) Исправность АКНП4
#define idA0EE04LZ1	 205	//( - , MDuBz1) Исправность АКНП4
#define A0VN01LDU	 BUFFER[470]	//( - , DU) Каналы АЗ1 проверены
#define idA0VN01LDU	 206	//( - , DU) Каналы АЗ1 проверены
#define B0VN01LDU	 BUFFER[472]	//( - , DU) Каналы АЗ2 проверены
#define idB0VN01LDU	 207	//( - , DU) Каналы АЗ2 проверены
#define B2IC01UDU	 BUFFER[474]	//( - , MDuS) Координата штока РБ2 (дел.энк)
#define idB2IC01UDU	 208	//( - , MDuS) Координата штока РБ2 (дел.энк)
#define A3IC01UDU	 BUFFER[479]	//( - , MDuS) Координата штока ИС1 (дел.энк)
#define idA3IC01UDU	 209	//( - , MDuS) Координата штока ИС1 (дел.энк)
#define B3IC01UDU	 BUFFER[484]	//( - , MDuS) Координата штока ИС2 (дел.энк)
#define idB3IC01UDU	 210	//( - , MDuS) Координата штока ИС2 (дел.энк)
#define B3VC01RDU	 BUFFER[489]	//( - , DU) Координата ИС2, мм
#define idB3VC01RDU	 211	//( - , DU) Координата ИС2, мм
#define A8IC01UDU	 BUFFER[494]	//( - , MDuS) Координата ДС2 (дел.энк)
#define idA8IC01UDU	 212	//( - , MDuS) Координата ДС2 (дел.энк)
#define A8VC01RDU	 BUFFER[499]	//( - , DU) Координата ДС2, мм
#define idA8VC01RDU	 213	//( - , DU) Координата ДС2, мм
#define B8IC01UDU	 BUFFER[504]	//( - , MDuS) Координата АЗ2 (дел.энк)
#define idB8IC01UDU	 214	//( - , MDuS) Координата АЗ2 (дел.энк)
#define A1IC01UDU	 BUFFER[509]	//( - , MDuS) Координата штока ББ1 (дел.энк)
#define idA1IC01UDU	 215	//( - , MDuS) Координата штока ББ1 (дел.энк)
#define A1VC01RDU	 BUFFER[514]	//( - , DU) Координата ББ1, мм
#define idA1VC01RDU	 216	//( - , DU) Координата ББ1, мм
#define A1IS11LDU	 BUFFER[519]	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
#define idA1IS11LDU	 217	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
#define B1MC01LC1	 BUFFER[521]	//( - , DU) Настроить энкодер ББ2
#define idB1MC01LC1	 218	//( - , DU) Настроить энкодер ББ2
#define B1MC01LC2	 BUFFER[523]	//( - , DU) Настроить энкодер ББ2
#define idB1MC01LC2	 219	//( - , DU) Настроить энкодер ББ2
#define A1MC01LC1	 BUFFER[525]	//( - , DU) Настроить энкодер ББ1
#define idA1MC01LC1	 220	//( - , DU) Настроить энкодер ББ1
#define A1MC01LC2	 BUFFER[527]	//( - , DU) Настроить энкодер ББ1
#define idA1MC01LC2	 221	//( - , DU) Настроить энкодер ББ1
#define B2MC01LC1	 BUFFER[529]	//( - , DU) Настроить энкодер РБ2
#define idB2MC01LC1	 222	//( - , DU) Настроить энкодер РБ2
#define B2MC01LC2	 BUFFER[531]	//( - , DU) Настроить энкодер РБ2
#define idB2MC01LC2	 223	//( - , DU) Настроить энкодер РБ2
#define A2MC01LC1	 BUFFER[533]	//( - , DU) Настроить энкодер РБ1
#define idA2MC01LC1	 224	//( - , DU) Настроить энкодер РБ1
#define A2MC01LC2	 BUFFER[535]	//( - , DU) Настроить энкодер РБ1
#define idA2MC01LC2	 225	//( - , DU) Настроить энкодер РБ1
#define B3MC01LC1	 BUFFER[537]	//( - , DU) Настроить энкодер ИС2
#define idB3MC01LC1	 226	//( - , DU) Настроить энкодер ИС2
#define B3MC01LC2	 BUFFER[539]	//( - , DU) Настроить энкодер ИС2
#define idB3MC01LC2	 227	//( - , DU) Настроить энкодер ИС2
#define A3MC01LC1	 BUFFER[541]	//( - , DU) Настроить энкодер ИС1
#define idA3MC01LC1	 228	//( - , DU) Настроить энкодер ИС1
#define A3MC01LC2	 BUFFER[543]	//( - , DU) Настроить энкодер ИС1
#define idA3MC01LC2	 229	//( - , DU) Настроить энкодер ИС1
#define B8MC01LC1	 BUFFER[545]	//( - , DU) Настроить энкодер АЗ2
#define idB8MC01LC1	 230	//( - , DU) Настроить энкодер АЗ2
#define R0IE01LDU	 BUFFER[547]	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
#define idR0IE01LDU	 231	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
#define A6IE01LDU	 BUFFER[549]	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
#define idA6IE01LDU	 232	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
#define B6IE01LDU	 BUFFER[551]	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
#define idB6IE01LDU	 233	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
#define A8IE01LDU	 BUFFER[553]	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
#define idA8IE01LDU	 234	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
#define B5IE01LDU	 BUFFER[555]	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
#define idB5IE01LDU	 235	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
#define A5IE02LDU	 BUFFER[557]	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
#define idA5IE02LDU	 236	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
#define R1IE01LDU	 BUFFER[559]	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
#define idR1IE01LDU	 237	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
#define R2IE01LDU	 BUFFER[561]	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
#define idR2IE01LDU	 238	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
#define R6IS61LDU	 BUFFER[563]	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
#define idR6IS61LDU	 239	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
#define R6IS66LZZ	 BUFFER[565]	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 240	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	 BUFFER[567]	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 241	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	 BUFFER[569]	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 242	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define A3VC01RDU	 BUFFER[571]	//( - , DU) Координата ИС1, мм
#define idA3VC01RDU	 243	//( - , DU) Координата ИС1, мм
#define A2VC01RDU	 BUFFER[576]	//( - , DU) Координата РБ1, мм
#define idA2VC01RDU	 244	//( - , DU) Координата РБ1, мм
#define B2VC01RDU	 BUFFER[581]	//( - , DU) Координата РБ2, мм
#define idB2VC01RDU	 245	//( - , DU) Координата РБ2, мм
#define B8VC01RDU	 BUFFER[586]	//( - , DU, MDuBz1, MDuBz2) Координата АЗ2, мм
#define idB8VC01RDU	 246	//( - , DU, MDuBz1, MDuBz2) Координата АЗ2, мм
#define A4VP82LDU	 BUFFER[591]	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	 247	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define B4VP82LDU	 BUFFER[593]	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	 248	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define A2VP82LDU	 BUFFER[595]	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	 249	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define B2VP82LDU	 BUFFER[597]	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define idB2VP82LDU	 250	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define A3VP81LDU	 BUFFER[599]	//( - , - ) Давление СПУСК ИС1 в норме
#define idA3VP81LDU	 251	//( - , - ) Давление СПУСК ИС1 в норме
#define B3VP81LDU	 BUFFER[601]	//( - , - ) Давление СПУСК ИС2 в норме
#define idB3VP81LDU	 252	//( - , - ) Давление СПУСК ИС2 в норме
#define R0EE02LDU	 BUFFER[603]	//( - , DU) Питание  АКНП  отключить
#define idR0EE02LDU	 253	//( - , DU) Питание  АКНП  отключить
#define A0EE01LZ2	 BUFFER[605]	//( - , MDuBz2) Исправность АКНП1
#define idA0EE01LZ2	 254	//( - , MDuBz2) Исправность АКНП1
#define A0EE03LZ2	 BUFFER[607]	//( - , MDuBz2) Исправность АКНП3
#define idA0EE03LZ2	 255	//( - , MDuBz2) Исправность АКНП3
#define A0EE02LZ2	 BUFFER[609]	//( - , MDuBz2) Исправность АКНП2
#define idA0EE02LZ2	 256	//( - , MDuBz2) Исправность АКНП2
#define A0EE04LZ2	 BUFFER[611]	//( - , MDuBz2) Исправность АКНП4
#define idA0EE04LZ2	 257	//( - , MDuBz2) Исправность АКНП4
#define A0VP71LZ1	 BUFFER[613]	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ1	 258	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
#define A0VP71LZ2	 BUFFER[615]	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ2	 259	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
#define B0VP71LZ1	 BUFFER[617]	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ1	 260	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
#define B0VP71LZ2	 BUFFER[619]	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ2	 261	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
#define A0VS11LDU	 BUFFER[621]	//( - , DU) АЗ1 готова к работе
#define idA0VS11LDU	 262	//( - , DU) АЗ1 готова к работе
#define B0VS11LDU	 BUFFER[623]	//( - , DU) АЗ2 готова к работе
#define idB0VS11LDU	 263	//( - , DU) АЗ2 готова к работе
#define A1IE01LDU	 BUFFER[625]	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
#define idA1IE01LDU	 264	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
#define A3IE01LDU	 BUFFER[627]	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
#define idA3IE01LDU	 265	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
#define A2IE01LDU	 BUFFER[629]	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
#define idA2IE01LDU	 266	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
#define A1IE02LDU	 BUFFER[631]	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
#define idA1IE02LDU	 267	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
#define A3IE02LDU	 BUFFER[633]	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
#define idA3IE02LDU	 268	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
#define A2IE02LDU	 BUFFER[635]	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
#define idA2IE02LDU	 269	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
#define B1IE01LDU	 BUFFER[637]	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
#define idB1IE01LDU	 270	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
#define B2IE01LDU	 BUFFER[639]	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
#define idB2IE01LDU	 271	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
#define B3IE01LDU	 BUFFER[641]	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
#define idB3IE01LDU	 272	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
#define B1IE02LDU	 BUFFER[643]	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
#define idB1IE02LDU	 273	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
#define B3IE02LDU	 BUFFER[645]	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
#define idB3IE02LDU	 274	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
#define B2IE02LDU	 BUFFER[647]	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
#define idB2IE02LDU	 275	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
#define R0IE02LDU	 BUFFER[649]	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
#define idR0IE02LDU	 276	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
#define R0AD03LZ2	 BUFFER[651]	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
#define idR0AD03LZ2	 277	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
#define R0AD04LZ1	 BUFFER[653]	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define idR0AD04LZ1	 278	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define R0AD04LZ2	 BUFFER[655]	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define idR0AD04LZ2	 279	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define R0AD05LZ1	 BUFFER[657]	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
#define idR0AD05LZ1	 280	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
#define R0AD05LZ2	 BUFFER[659]	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
#define idR0AD05LZ2	 281	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
#define B8IS12LDU	 BUFFER[661]	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
#define idB8IS12LDU	 282	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
#define B8IS21LDU	 BUFFER[663]	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
#define idB8IS21LDU	 283	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
#define A1VP41LZ1	 BUFFER[665]	//( - , MDuBz1) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ1	 284	//( - , MDuBz1) Давление СБРОС ББ1 ниже АС
#define A1VP41LZ2	 BUFFER[667]	//( - , MDuBz2) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ2	 285	//( - , MDuBz2) Давление СБРОС ББ1 ниже АС
#define R0VL22LDU	 BUFFER[669]	//( - , DU) Конец программы 200сек
#define idR0VL22LDU	 286	//( - , DU) Конец программы 200сек
#define R0VL23LDU	 BUFFER[671]	//( - , DU) Конец программы 20мин
#define idR0VL23LDU	 287	//( - , DU) Конец программы 20мин
#define B1VP41LZ1	 BUFFER[673]	//( - , MDuBz1) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ1	 288	//( - , MDuBz1) Давление СБРОС ББ2 ниже АС
#define B1VP41LZ2	 BUFFER[675]	//( - , MDuBz2) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ2	 289	//( - , MDuBz2) Давление СБРОС ББ2 ниже АС
#define A3AB19LDU	 BUFFER[677]	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
#define idA3AB19LDU	 290	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
#define B3AB19LDU	 BUFFER[679]	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
#define idB3AB19LDU	 291	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
#define A3EE03LDU	 BUFFER[681]	//( - , DU) ВПИС ИС1
#define idA3EE03LDU	 292	//( - , DU) ВПИС ИС1
#define B3EE03LDU	 BUFFER[683]	//( - , DU) ВПИС ИС2
#define idB3EE03LDU	 293	//( - , DU) ВПИС ИС2
#define B3AB15LDU	 BUFFER[685]	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
#define idB3AB15LDU	 294	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
#define R5IS21LDU	 BUFFER[687]	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	 295	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
#define R5VS22LDU	 BUFFER[689]	//( - , DU) Движение ворот отстойной зоны к закрыты
#define idR5VS22LDU	 296	//( - , DU) Движение ворот отстойной зоны к закрыты
#define R5VS12LDU	 BUFFER[691]	//( - , DU) Движение ворот отстойной зоны к открыты
#define idR5VS12LDU	 297	//( - , DU) Движение ворот отстойной зоны к открыты
#define R5VS01IDU	 BUFFER[693]	//( - , DU) Готовность к управлению ворот отстойной зоны
#define idR5VS01IDU	 298	//( - , DU) Готовность к управлению ворот отстойной зоны
#define R3VS22LDU	 BUFFER[696]	//( - , DU) Движение гомогенных дверей к закрыты
#define idR3VS22LDU	 299	//( - , DU) Движение гомогенных дверей к закрыты
#define R0VN09RZ2	 BUFFER[698]	//( - , MDuBz2) Усредненный период разгона
#define idR0VN09RZ2	 300	//( - , MDuBz2) Усредненный период разгона
#define R0VN09RZ1	 BUFFER[703]	//( - , MDuBz1) Усредненный период разгона
#define idR0VN09RZ1	 301	//( - , MDuBz1) Усредненный период разгона
#define R0AB16LDU	 BUFFER[708]	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
#define idR0AB16LDU	 302	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
#define R0AB17LDU	 BUFFER[710]	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
#define idR0AB17LDU	 303	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
#define R0AB18LDU	 BUFFER[712]	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
#define idR0AB18LDU	 304	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
#define A0CT01IZ1	 BUFFER[714]	//( - , MDuBz1) Температура АЗ1-1
#define idA0CT01IZ1	 305	//( - , MDuBz1) Температура АЗ1-1
#define B0CT01IZ1	 BUFFER[719]	//( - , MDuBz1) Температура АЗ2-1
#define idB0CT01IZ1	 306	//( - , MDuBz1) Температура АЗ2-1
#define A0CT01IZ2	 BUFFER[724]	//( - , MDuBz2) Температура АЗ1-2
#define idA0CT01IZ2	 307	//( - , MDuBz2) Температура АЗ1-2
#define B0CT01IZ2	 BUFFER[729]	//( - , MDuBz2) Температура АЗ2-2
#define idB0CT01IZ2	 308	//( - , MDuBz2) Температура АЗ2-2
#define A3MC01RDU	 BUFFER[734]	//( - , DU) Заданная координата положения ИС от регулятора мм
#define idA3MC01RDU	 309	//( - , DU) Заданная координата положения ИС от регулятора мм
#define A3MC02RDU	 BUFFER[739]	//( - , DU) Температурная корректировка координаты ИМ
#define idA3MC02RDU	 310	//( - , DU) Температурная корректировка координаты ИМ
#define R0CN91LDU	 BUFFER[744]	//( - , DU) Рассчётная реактивность от регулятора
#define idR0CN91LDU	 311	//( - , DU) Рассчётная реактивность от регулятора
#define A3MC03RDU	 BUFFER[749]	//( - , DU) Координата положения ИМ 0-й реактивности
#define idA3MC03RDU	 312	//( - , DU) Координата положения ИМ 0-й реактивности
#define A3AB15LDU	 BUFFER[754]	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
#define idA3AB15LDU	 313	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
#define R0AB20LDU	 BUFFER[756]	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
#define idR0AB20LDU	 314	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
#define R0CN92LDU	 BUFFER[758]	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
#define idR0CN92LDU	 315	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
#define R0VN11RDU	 BUFFER[763]	//( - , DU) Текущая мощность РУ
#define idR0VN11RDU	 316	//( - , DU) Текущая мощность РУ
#define R0VN12RDU	 BUFFER[768]	//( - , DU) Заданная мощность РУ
#define idR0VN12RDU	 317	//( - , DU) Заданная мощность РУ
#define R0AB19LDU	 BUFFER[773]	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
#define idR0AB19LDU	 318	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
#define R0CN93LDU	 BUFFER[775]	//( - , DU) время работы на мощности более 100Вт, сек
#define idR0CN93LDU	 319	//( - , DU) время работы на мощности более 100Вт, сек
#define R0CN94LDU	 BUFFER[780]	//( - , DU) Скорость изменения мощности
#define idR0CN94LDU	 320	//( - , DU) Скорость изменения мощности
#define R0CN95LDU	 BUFFER[785]	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
#define idR0CN95LDU	 321	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
#define R0AD03LZ1	 BUFFER[788]	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
#define idR0AD03LZ1	 322	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
#define R0DE37LDU	 BUFFER[790]	//(sbk:20 - S07SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 2
#define idR0DE37LDU	 323	//(sbk:20 - S07SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 2
#define R0DE38LDU	 BUFFER[792]	//(sbk:20 - S08SBK, DiagnDU) диагностика шкафа ДУ МП15-3 место 3
#define idR0DE38LDU	 324	//(sbk:20 - S08SBK, DiagnDU) диагностика шкафа ДУ МП15-3 место 3
#define R0DE39LDU	 BUFFER[794]	//(sbk:20 - S09SBK, DiagnDU) диагностика шкафа ДУ МП24-2 место 4
#define idR0DE39LDU	 325	//(sbk:20 - S09SBK, DiagnDU) диагностика шкафа ДУ МП24-2 место 4
#define R0DEB3LDU	 BUFFER[796]	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
#define idR0DEB3LDU	 326	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
#define R0DEB2LDU	 BUFFER[798]	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
#define idR0DEB2LDU	 327	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
#define R0DEB1LDU	 BUFFER[800]	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
#define idR0DEB1LDU	 328	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
#define R0DEB4LDU	 BUFFER[802]	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
#define idR0DEB4LDU	 329	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
#define R0DE3DLDU	 BUFFER[804]	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
#define idR0DE3DLDU	 330	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
#define R0DE3CLDU	 BUFFER[806]	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
#define idR0DE3CLDU	 331	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
#define TestDiagnDU	 BUFFER[808]	//( - , DU) Неисправность от
#define idTestDiagnDU	 332	//( - , DU) Неисправность от
#define B3CV01RDU	 BUFFER[810]	//( - , DU) Измеренная скорость перемещения ИС2
#define idB3CV01RDU	 333	//( - , DU) Измеренная скорость перемещения ИС2
#define venc01	 BUFFER[815]	//(vencf8l:01 - venc01, - ) заначение реального энкодера ББ1
#define idvenc01	 334	//(vencf8l:01 - venc01, - ) заначение реального энкодера ББ1
#define venc02	 BUFFER[820]	//(vencf8l:01 - venc02, - ) заначение реального энкодера РБ1
#define idvenc02	 335	//(vencf8l:01 - venc02, - ) заначение реального энкодера РБ1
#define venc03	 BUFFER[825]	//(vencf8l:01 - venc03, - ) заначение реального энкодера ИС1
#define idvenc03	 336	//(vencf8l:01 - venc03, - ) заначение реального энкодера ИС1
#define venc04	 BUFFER[830]	//(vencf8l:01 - venc04, - ) заначение реального энкодера ДС2
#define idvenc04	 337	//(vencf8l:01 - venc04, - ) заначение реального энкодера ДС2
#define venc05	 BUFFER[835]	//(vencf8l:01 - venc05, - ) заначение реального энкодера ББ2
#define idvenc05	 338	//(vencf8l:01 - venc05, - ) заначение реального энкодера ББ2
#define venc06	 BUFFER[840]	//(vencf8l:01 - venc06, - ) заначение реального энкодера РБ2
#define idvenc06	 339	//(vencf8l:01 - venc06, - ) заначение реального энкодера РБ2
#define venc07	 BUFFER[845]	//(vencf8l:01 - venc07, - ) заначение реального энкодера ИС2
#define idvenc07	 340	//(vencf8l:01 - venc07, - ) заначение реального энкодера ИС2
#define venc08	 BUFFER[850]	//(vencf8l:01 - venc08, - ) заначение реального энкодера АЗ2
#define idvenc08	 341	//(vencf8l:01 - venc08, - ) заначение реального энкодера АЗ2
#define B1IC01UDU	 BUFFER[855]	//( - , MDuS) Координата штока ББ2 (дел.энк)
#define idB1IC01UDU	 342	//( - , MDuS) Координата штока ББ2 (дел.энк)
#define B1VC01RDU	 BUFFER[860]	//( - , DU) Координата ББ2, мм
#define idB1VC01RDU	 343	//( - , DU) Координата ББ2, мм
#define B1IS11LDU	 BUFFER[865]	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
#define idB1IS11LDU	 344	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
#define A2IC01UDU	 BUFFER[867]	//( - , MDuS) Координата штока РБ1 (дел.энк)
#define idA2IC01UDU	 345	//( - , MDuS) Координата штока РБ1 (дел.энк)
#define R3VS12LDU	 BUFFER[872]	//( - , DU) Движение гомогенных дверей к открыты
#define idR3VS12LDU	 346	//( - , DU) Движение гомогенных дверей к открыты
#define R3VS01IDU	 BUFFER[874]	//( - , DU) Готовность к управлению гомогенных дверей
#define idR3VS01IDU	 347	//( - , DU) Готовность к управлению гомогенных дверей
#define A3AB13LDU	 BUFFER[877]	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
#define idA3AB13LDU	 348	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
#define B3AB13LDU	 BUFFER[879]	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define idB3AB13LDU	 349	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define R0DE02LDU	 BUFFER[881]	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
#define idR0DE02LDU	 350	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
#define R0DE03LDU	 BUFFER[884]	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
#define idR0DE03LDU	 351	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
#define R0DE04LDU	 BUFFER[887]	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
#define idR0DE04LDU	 352	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
#define R0DE08LDU	 BUFFER[890]	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
#define idR0DE08LDU	 353	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
#define R0DE05LDU	 BUFFER[893]	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
#define idR0DE05LDU	 354	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
#define R0DE09LDU	 BUFFER[896]	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
#define idR0DE09LDU	 355	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
#define R0DE0ALDU	 BUFFER[899]	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
#define idR0DE0ALDU	 356	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
#define R0DE07LDU	 BUFFER[902]	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
#define idR0DE07LDU	 357	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
#define R0DE0CLDU	 BUFFER[905]	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
#define idR0DE0CLDU	 358	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
#define R0DE0BLDU	 BUFFER[908]	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
#define idR0DE0BLDU	 359	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
#define R0DE0DLDU	 BUFFER[911]	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
#define idR0DE0DLDU	 360	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
#define R0DE0FLDU	 BUFFER[914]	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
#define idR0DE0FLDU	 361	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
#define R0DE31LDU	 BUFFER[917]	//(sbk:20 - S01SBK, DiagnDU) диагностика шкафа ДУ сеть 1
#define idR0DE31LDU	 362	//(sbk:20 - S01SBK, DiagnDU) диагностика шкафа ДУ сеть 1
#define TTLDU	 BUFFER[919]	//( - , DU) ttl
#define idTTLDU	 363	//( - , DU) ttl
#define R0DE32LDU	 BUFFER[922]	//(sbk:20 - S02SBK, DiagnDU) диагностика шкафа ДУ сеть 2
#define idR0DE32LDU	 364	//(sbk:20 - S02SBK, DiagnDU) диагностика шкафа ДУ сеть 2
#define R0DE33LDU	 BUFFER[924]	//(sbk:20 - S03SBK, DiagnDU) диагностика шкафа ДУ двери
#define idR0DE33LDU	 365	//(sbk:20 - S03SBK, DiagnDU) диагностика шкафа ДУ двери
#define R0DE34LDU	 BUFFER[926]	//(sbk:20 - S04SBK, DiagnDU) диагностика шкафа ДУ температура меньше 43
#define idR0DE34LDU	 366	//(sbk:20 - S04SBK, DiagnDU) диагностика шкафа ДУ температура меньше 43
#define R0DE35LDU	 BUFFER[928]	//(sbk:20 - S05SBK, DiagnDU) диагностика шкафа ДУ температура больше 53
#define idR0DE35LDU	 367	//(sbk:20 - S05SBK, DiagnDU) диагностика шкафа ДУ температура больше 53
#define R0DE36LDU	 BUFFER[930]	//(sbk:20 - S06SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 1
#define idR0DE36LDU	 368	//(sbk:20 - S06SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 1
#define A6AB06LDU	 BUFFER[932]	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
#define idA6AB06LDU	 369	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
#define A6AB07LDU	 BUFFER[934]	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
#define idA6AB07LDU	 370	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
#define A6AB08LDU	 BUFFER[936]	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
#define idA6AB08LDU	 371	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
#define A6AB09LDU	 BUFFER[938]	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
#define idA6AB09LDU	 372	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
#define B6AB06LDU	 BUFFER[940]	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
#define idB6AB06LDU	 373	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
#define B6AB07LDU	 BUFFER[942]	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
#define idB6AB07LDU	 374	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
#define B6AB08LDU	 BUFFER[944]	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
#define idB6AB08LDU	 375	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
#define B6AB09LDU	 BUFFER[946]	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
#define idB6AB09LDU	 376	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
#define A6AB05LDU	 BUFFER[948]	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
#define idA6AB05LDU	 377	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
#define B8VS12LDU	 BUFFER[950]	//( - , DU) Движение АЗ2 в сторону ВУ
#define idB8VS12LDU	 378	//( - , DU) Движение АЗ2 в сторону ВУ
#define B8CV01RDU	 BUFFER[952]	//( - , DU) Измеренная скорость перемещения АЗ2
#define idB8CV01RDU	 379	//( - , DU) Измеренная скорость перемещения АЗ2
#define B8AB06LDU	 BUFFER[957]	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
#define idB8AB06LDU	 380	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
#define B8AB07LDU	 BUFFER[959]	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
#define idB8AB07LDU	 381	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
#define B8AB05LDU	 BUFFER[961]	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
#define idB8AB05LDU	 382	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
#define B8VS22LDU	 BUFFER[963]	//( - , DU) Движение АЗ2 в сторону НУ
#define idB8VS22LDU	 383	//( - , DU) Движение АЗ2 в сторону НУ
#define B8AZ03LDU	 BUFFER[965]	//( - , DU) Несанкционированное перемещение АЗ2
#define idB8AZ03LDU	 384	//( - , DU) Несанкционированное перемещение АЗ2
#define R0MD11LP1	 BUFFER[967]	//( - , DU) Кнопка ПУСК
#define idR0MD11LP1	 385	//( - , DU) Кнопка ПУСК
#define B8AD10LDU	 BUFFER[969]	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
#define idB8AD10LDU	 386	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
#define B8AD20LDU	 BUFFER[971]	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
#define idB8AD20LDU	 387	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
#define B8IS11LDU	 BUFFER[973]	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
#define idB8IS11LDU	 388	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
#define B8AB01LDU	 BUFFER[975]	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
#define idB8AB01LDU	 389	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
#define B8AB04LDU	 BUFFER[977]	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
#define idB8AB04LDU	 390	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
#define B8AB08LDU	 BUFFER[979]	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
#define idB8AB08LDU	 391	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
#define A5AZ03LDU	 BUFFER[981]	//( - , DU) Несанкционированное перемещение НЛ1
#define idA5AZ03LDU	 392	//( - , DU) Несанкционированное перемещение НЛ1
#define A5AB01LDU	 BUFFER[983]	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
#define idA5AB01LDU	 393	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
#define A5AB02LDU	 BUFFER[985]	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
#define idA5AB02LDU	 394	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
#define B5AZ03LDU	 BUFFER[987]	//( - , DU) Несанкционированное перемещение НЛ2
#define idB5AZ03LDU	 395	//( - , DU) Несанкционированное перемещение НЛ2
#define B5AB01LDU	 BUFFER[989]	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
#define idB5AB01LDU	 396	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
#define B5AB02LDU	 BUFFER[991]	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
#define idB5AB02LDU	 397	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
#define A4IS21LDU	 BUFFER[993]	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
#define idA4IS21LDU	 398	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
#define B4IS21LDU	 BUFFER[995]	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
#define idB4IS21LDU	 399	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
#define B4AD10LDU	 BUFFER[997]	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
#define idB4AD10LDU	 400	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
#define A4AD10LDU	 BUFFER[999]	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
#define idA4AD10LDU	 401	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
#define A4AZ03LDU	 BUFFER[1001]	//( - , DU) Несанкционированное перемещение НИ1
#define idA4AZ03LDU	 402	//( - , DU) Несанкционированное перемещение НИ1
#define A4AB01LDU	 BUFFER[1003]	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
#define idA4AB01LDU	 403	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
#define A4AB02LDU	 BUFFER[1005]	//( - , DU) Блокировка движения НИ1 - Нет перемещения
#define idA4AB02LDU	 404	//( - , DU) Блокировка движения НИ1 - Нет перемещения
#define B4AZ03LDU	 BUFFER[1007]	//( - , DU) Несанкционированное перемещение НИ2
#define idB4AZ03LDU	 405	//( - , DU) Несанкционированное перемещение НИ2
#define B4AB01LDU	 BUFFER[1009]	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
#define idB4AB01LDU	 406	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
#define B4AB02LDU	 BUFFER[1011]	//( - , DU) Блокировка движения НИ2 - Нет перемещения
#define idB4AB02LDU	 407	//( - , DU) Блокировка движения НИ2 - Нет перемещения
#define A5AB04LDU	 BUFFER[1013]	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
#define idA5AB04LDU	 408	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
#define B5AB04LDU	 BUFFER[1015]	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
#define idB5AB04LDU	 409	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
#define A1IS12LDU	 BUFFER[1017]	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
#define idA1IS12LDU	 410	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
#define A2IS12LDU	 BUFFER[1019]	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
#define idA2IS12LDU	 411	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
#define B1IS12LDU	 BUFFER[1021]	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
#define idB1IS12LDU	 412	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
#define B2IS12LDU	 BUFFER[1023]	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
#define idB2IS12LDU	 413	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
#define R4IS11LDU	 BUFFER[1025]	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
#define idR4IS11LDU	 414	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
#define A8AB11LDU	 BUFFER[1027]	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
#define idA8AB11LDU	 415	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
#define A8AB12LDU	 BUFFER[1029]	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
#define idA8AB12LDU	 416	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
#define A8AB13LDU	 BUFFER[1031]	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
#define idA8AB13LDU	 417	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
#define A8AB14LDU	 BUFFER[1033]	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
#define idA8AB14LDU	 418	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
#define A8AB02LDU	 BUFFER[1035]	//( - , DU) Блокировка движения ДС2- АНИ не установлен
#define idA8AB02LDU	 419	//( - , DU) Блокировка движения ДС2- АНИ не установлен
#define A8AB01LDU	 BUFFER[1037]	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
#define idA8AB01LDU	 420	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
#define A2VS11LDU	 BUFFER[1039]	//( - , DU) Движение РБ1 в сторону ВУ
#define idA2VS11LDU	 421	//( - , DU) Движение РБ1 в сторону ВУ
#define A2CV01RDU	 BUFFER[1041]	//( - , DU) Измеренная скорость перемещения РБ1
#define idA2CV01RDU	 422	//( - , DU) Измеренная скорость перемещения РБ1
#define A2AB04LDU	 BUFFER[1046]	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
#define idA2AB04LDU	 423	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
#define A2AB02LDU	 BUFFER[1048]	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
#define idA2AB02LDU	 424	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
#define A2AB01LDU	 BUFFER[1050]	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
#define idA2AB01LDU	 425	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
#define A2VS21LDU	 BUFFER[1052]	//( - , DU) Движение РБ1 в сторону НУ
#define idA2VS21LDU	 426	//( - , DU) Движение РБ1 в сторону НУ
#define A2AZ03LDU	 BUFFER[1054]	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
#define idA2AZ03LDU	 427	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
#define A2AD11LDU	 BUFFER[1056]	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	 428	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
#define A2AD21LDU	 BUFFER[1058]	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	 429	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
#define A2AD02LDU	 BUFFER[1060]	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
#define idA2AD02LDU	 430	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
#define A2AD03LDU	 BUFFER[1062]	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
#define idA2AD03LDU	 431	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
#define A2AD04LDU	 BUFFER[1064]	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
#define idA2AD04LDU	 432	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
#define A2AD05LDU	 BUFFER[1066]	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
#define idA2AD05LDU	 433	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
#define A2AB07LDU	 BUFFER[1068]	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
#define idA2AB07LDU	 434	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
#define A2AB08LDU	 BUFFER[1070]	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
#define idA2AB08LDU	 435	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
#define A2AB05LDU	 BUFFER[1072]	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
#define idA2AB05LDU	 436	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
#define A2AB06LDU	 BUFFER[1074]	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
#define idA2AB06LDU	 437	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
#define B8AB09LDU	 BUFFER[1076]	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
#define idB8AB09LDU	 438	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
#define B8AB10LDU	 BUFFER[1078]	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
#define idB8AB10LDU	 439	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
#define B8AB11LDU	 BUFFER[1080]	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
#define idB8AB11LDU	 440	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
#define B8AB12LDU	 BUFFER[1082]	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
#define idB8AB12LDU	 441	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
#define B8AB13LDU	 BUFFER[1084]	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
#define idB8AB13LDU	 442	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
#define B8AB14LDU	 BUFFER[1086]	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
#define idB8AB14LDU	 443	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
#define B8AB02LDU	 BUFFER[1088]	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
#define idB8AB02LDU	 444	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
#define A8VS12LDU	 BUFFER[1090]	//( - , DU) Движение ДС2 в сторону ВУ
#define idA8VS12LDU	 445	//( - , DU) Движение ДС2 в сторону ВУ
#define A8CV01RDU	 BUFFER[1092]	//( - , DU) Измеренная скорость перемещения ДС2
#define idA8CV01RDU	 446	//( - , DU) Измеренная скорость перемещения ДС2
#define A8AB06LDU	 BUFFER[1097]	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
#define idA8AB06LDU	 447	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
#define A8AB07LDU	 BUFFER[1099]	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
#define idA8AB07LDU	 448	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
#define A8AB05LDU	 BUFFER[1101]	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
#define idA8AB05LDU	 449	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
#define A8VS22LDU	 BUFFER[1103]	//( - , DU) Движение ДС2 в сторону НУ
#define idA8VS22LDU	 450	//( - , DU) Движение ДС2 в сторону НУ
#define A8AZ03LDU	 BUFFER[1105]	//( - , DU) Несанкционированное перемещение ДС2
#define idA8AZ03LDU	 451	//( - , DU) Несанкционированное перемещение ДС2
#define A8AD10LDU	 BUFFER[1107]	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
#define idA8AD10LDU	 452	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
#define A8AD20LDU	 BUFFER[1109]	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
#define idA8AD20LDU	 453	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
#define B8IS22LDU	 BUFFER[1111]	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
#define idB8IS22LDU	 454	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
#define A8IS12LDU	 BUFFER[1113]	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
#define idA8IS12LDU	 455	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
#define A8AB04LDU	 BUFFER[1115]	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
#define idA8AB04LDU	 456	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
#define A8IS22LDU	 BUFFER[1117]	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
#define idA8IS22LDU	 457	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
#define A8AB08LDU	 BUFFER[1119]	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define idA8AB08LDU	 458	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define A8AB09LDU	 BUFFER[1121]	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
#define idA8AB09LDU	 459	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
#define A8AB10LDU	 BUFFER[1123]	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
#define idA8AB10LDU	 460	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
#define B6IS21LDU	 BUFFER[1125]	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
#define idB6IS21LDU	 461	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
#define A6VS22LDU	 BUFFER[1127]	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
#define idA6VS22LDU	 462	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
#define A6VS12LDU	 BUFFER[1129]	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
#define idA6VS12LDU	 463	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
#define B6VS22LDU	 BUFFER[1131]	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
#define idB6VS22LDU	 464	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
#define B6VS12LDU	 BUFFER[1133]	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
#define idB6VS12LDU	 465	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
#define A6AD10LDU	 BUFFER[1135]	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
#define idA6AD10LDU	 466	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
#define A6AD20LDU	 BUFFER[1137]	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
#define idA6AD20LDU	 467	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
#define B6AD10LDU	 BUFFER[1139]	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
#define idB6AD10LDU	 468	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
#define B6AD20LDU	 BUFFER[1141]	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
#define idB6AD20LDU	 469	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
#define A6AZ03LDU	 BUFFER[1143]	//( - , DU) Несанкционированное перемещение БЗ1
#define idA6AZ03LDU	 470	//( - , DU) Несанкционированное перемещение БЗ1
#define A6AB01LDU	 BUFFER[1145]	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
#define idA6AB01LDU	 471	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
#define A6AB02LDU	 BUFFER[1147]	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
#define idA6AB02LDU	 472	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
#define B6AZ03LDU	 BUFFER[1149]	//( - , DU) Несанкционированное перемещение БЗ2
#define idB6AZ03LDU	 473	//( - , DU) Несанкционированное перемещение БЗ2
#define B6AB01LDU	 BUFFER[1151]	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
#define idB6AB01LDU	 474	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
#define B6AB02LDU	 BUFFER[1153]	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
#define idB6AB02LDU	 475	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
#define A6AB04LDU	 BUFFER[1155]	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
#define idA6AB04LDU	 476	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
#define B6AB04LDU	 BUFFER[1157]	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
#define idB6AB04LDU	 477	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
#define R4AB01LDU	 BUFFER[1159]	//( - , DU) Блокировка движения тележки - АНИ не установлен
#define idR4AB01LDU	 478	//( - , DU) Блокировка движения тележки - АНИ не установлен
#define R8IS11LDU	 BUFFER[1161]	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
#define idR8IS11LDU	 479	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
#define R6IS21LDU	 BUFFER[1163]	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
#define idR6IS21LDU	 480	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
#define A0VN71LZ2	 BUFFER[1165]	//( - , MDuBz2) АЗ по АС мощности для АЗ1
#define idA0VN71LZ2	 481	//( - , MDuBz2) АЗ по АС мощности для АЗ1
#define A0VN71LZ1	 BUFFER[1167]	//( - , MDuBz1) АЗ по АС мощности для АЗ1
#define idA0VN71LZ1	 482	//( - , MDuBz1) АЗ по АС мощности для АЗ1
#define R0NE01LDU	 BUFFER[1169]	//( - , DU) Потеря связи с БАЗ1
#define idR0NE01LDU	 483	//( - , DU) Потеря связи с БАЗ1
#define R0MW15IP1	 BUFFER[1171]	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
#define idR0MW15IP1	 484	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
#define R0MW14IP1	 BUFFER[1174]	//( - , DU) Переключатель ПРОГРАММЫ
#define idR0MW14IP1	 485	//( - , DU) Переключатель ПРОГРАММЫ
#define R0MW12IP1	 BUFFER[1177]	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
#define idR0MW12IP1	 486	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
#define R0MW13IP1	 BUFFER[1180]	//( - , DU) Переключатель ВЫБОР ЗОН
#define idR0MW13IP1	 487	//( - , DU) Переключатель ВЫБОР ЗОН
#define R0MW16IP1	 BUFFER[1183]	//( - , DU) Переключатель ВИД ПРОВЕРКИ
#define idR0MW16IP1	 488	//( - , DU) Переключатель ВИД ПРОВЕРКИ
#define R0MW11IP1	 BUFFER[1186]	//( - , DU) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	 489	//( - , DU) Переключатель ВЫСТРЕЛ
#define R0MW11IP2	 BUFFER[1189]	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
#define idR0MW11IP2	 490	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
#define R0MW13LP2	 BUFFER[1192]	//( - , DU) Переключатель СЕТЬ
#define idR0MW13LP2	 491	//( - , DU) Переключатель СЕТЬ
#define R0MD32LP1	 BUFFER[1194]	//( - , DU) Кнопка СПУСК
#define idR0MD32LP1	 492	//( - , DU) Кнопка СПУСК
#define R0MD31LP1	 BUFFER[1196]	//( - , DU) Кнопка СТОП
#define idR0MD31LP1	 493	//( - , DU) Кнопка СТОП
#define A1IS21LDU	 BUFFER[1198]	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
#define idA1IS21LDU	 494	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
#define A2IS21LDU	 BUFFER[1200]	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
#define idA2IS21LDU	 495	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
#define A3IS21LDU	 BUFFER[1202]	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
#define idA3IS21LDU	 496	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
#define B1IS21LDU	 BUFFER[1204]	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
#define idB1IS21LDU	 497	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
#define B2IS21LDU	 BUFFER[1206]	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
#define idB2IS21LDU	 498	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
#define B3IS21LDU	 BUFFER[1208]	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
#define idB3IS21LDU	 499	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
#define R0ES01LDU	 BUFFER[1210]	//( - , DU) ОРР не в исходном состоянии
#define idR0ES01LDU	 500	//( - , DU) ОРР не в исходном состоянии
#define R4MD11LP2	 BUFFER[1212]	//( - , DU) Кнопка ВПЕРЁД  (тележки)
#define idR4MD11LP2	 501	//( - , DU) Кнопка ВПЕРЁД  (тележки)
#define R4MD31LP2	 BUFFER[1214]	//( - , DU) Кнопка СТОП  (тележки)
#define idR4MD31LP2	 502	//( - , DU) Кнопка СТОП  (тележки)
#define R4MD21LP2	 BUFFER[1216]	//( - , DU) Кнопка НАЗАД  (тележки)
#define idR4MD21LP2	 503	//( - , DU) Кнопка НАЗАД  (тележки)
#define A6IS11LDU	 BUFFER[1218]	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
#define idA6IS11LDU	 504	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
#define A6IS21LDU	 BUFFER[1220]	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
#define idA6IS21LDU	 505	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
#define B6IS11LDU	 BUFFER[1222]	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
#define idB6IS11LDU	 506	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
#define A4IS11LDU	 BUFFER[1224]	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
#define idA4IS11LDU	 507	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
#define B4IS11LDU	 BUFFER[1226]	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
#define idB4IS11LDU	 508	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
#define R4AB13LDU	 BUFFER[1228]	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
#define idR4AB13LDU	 509	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
#define R4AB14LDU	 BUFFER[1230]	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
#define idR4AB14LDU	 510	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
#define R4AB15LDU	 BUFFER[1232]	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
#define idR4AB15LDU	 511	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
#define R5IS11LDU	 BUFFER[1234]	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	 512	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
#define R4AB16LDU	 BUFFER[1236]	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
#define idR4AB16LDU	 513	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
#define R4AB17LDU	 BUFFER[1238]	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define idR4AB17LDU	 514	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define R4AB18LDU	 BUFFER[1240]	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define idR4AB18LDU	 515	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define R4AD10LDU	 BUFFER[1242]	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
#define idR4AD10LDU	 516	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
#define R4AD20LDU	 BUFFER[1244]	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
#define idR4AD20LDU	 517	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
#define A5VS22LDU	 BUFFER[1246]	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
#define idA5VS22LDU	 518	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
#define A5VS12LDU	 BUFFER[1248]	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
#define idA5VS12LDU	 519	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
#define B5VS22LDU	 BUFFER[1250]	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
#define idB5VS22LDU	 520	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
#define B5VS12LDU	 BUFFER[1252]	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
#define idB5VS12LDU	 521	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
#define B5AD10LDU	 BUFFER[1254]	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
#define idB5AD10LDU	 522	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
#define B5AD20LDU	 BUFFER[1256]	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
#define idB5AD20LDU	 523	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
#define A5AD10LDU	 BUFFER[1258]	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
#define idA5AD10LDU	 524	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
#define A5AD20LDU	 BUFFER[1260]	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
#define idA5AD20LDU	 525	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
#define A5IS11LDU	 BUFFER[1262]	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
#define idA5IS11LDU	 526	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
#define A5IS21LDU	 BUFFER[1264]	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
#define idA5IS21LDU	 527	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
#define B5IS11LDU	 BUFFER[1266]	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
#define idB5IS11LDU	 528	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
#define B5IS21LDU	 BUFFER[1268]	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
#define idB5IS21LDU	 529	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
#define R0NE02LDU	 BUFFER[1270]	//( - , DU) Потеря связи с БАЗ2
#define idR0NE02LDU	 530	//( - , DU) Потеря связи с БАЗ2
#define R4AB02LDU	 BUFFER[1272]	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
#define idR4AB02LDU	 531	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
#define R0NE08LDU	 BUFFER[1274]	//( - , DU) Потеря связи с ОПУ
#define idR0NE08LDU	 532	//( - , DU) Потеря связи с ОПУ
#define R4IS21LDU	 BUFFER[1276]	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
#define idR4IS21LDU	 533	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
#define R4IS22LDU	 BUFFER[1278]	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
#define idR4IS22LDU	 534	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
#define R4IS12LDU	 BUFFER[1280]	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
#define idR4IS12LDU	 535	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
#define R4VS22LDU	 BUFFER[1282]	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
#define idR4VS22LDU	 536	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
#define R4VS12LDU	 BUFFER[1284]	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
#define idR4VS12LDU	 537	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
#define R4AZ03LDU	 BUFFER[1286]	//( - , DU) Несанкционированное перемещение тележки
#define idR4AZ03LDU	 538	//( - , DU) Несанкционированное перемещение тележки
#define R4AB03LDU	 BUFFER[1288]	//( - , DU) Блокировка движения тележки - Самоход любого механизма
#define idR4AB03LDU	 539	//( - , DU) Блокировка движения тележки - Самоход любого механизма
#define R1IS21LDU	 BUFFER[1290]	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
#define idR1IS21LDU	 540	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
#define R2IS21LDU	 BUFFER[1292]	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
#define idR2IS21LDU	 541	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
#define R4AB04LDU	 BUFFER[1294]	//( - , DU) Блокировка движения тележки - Превышение времени движения
#define idR4AB04LDU	 542	//( - , DU) Блокировка движения тележки - Превышение времени движения
#define R4AB05LDU	 BUFFER[1296]	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
#define idR4AB05LDU	 543	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
#define R4AB06LDU	 BUFFER[1298]	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
#define idR4AB06LDU	 544	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
#define R4AB07LDU	 BUFFER[1300]	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
#define idR4AB07LDU	 545	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
#define R4AB08LDU	 BUFFER[1302]	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define idR4AB08LDU	 546	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define R4AB09LDU	 BUFFER[1304]	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
#define idR4AB09LDU	 547	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
#define B0VN71LZ1	 BUFFER[1306]	//( - , MDuBz1) АЗ по АС мощности для АЗ2
#define idB0VN71LZ1	 548	//( - , MDuBz1) АЗ по АС мощности для АЗ2
#define B0VN71LZ2	 BUFFER[1308]	//( - , MDuBz2) АЗ по АС мощности для АЗ2
#define idB0VN71LZ2	 549	//( - , MDuBz2) АЗ по АС мощности для АЗ2
#define R4AB10LDU	 BUFFER[1310]	//( - , DU) Блокировка тележки - не открыта биологическая защита
#define idR4AB10LDU	 550	//( - , DU) Блокировка тележки - не открыта биологическая защита
#define R4AB11LDU	 BUFFER[1312]	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
#define idR4AB11LDU	 551	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
#define R4AB12LDU	 BUFFER[1314]	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
#define idR4AB12LDU	 552	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
#define A3AD02LDU	 BUFFER[1316]	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
#define idA3AD02LDU	 553	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
#define A3AD03LDU	 BUFFER[1318]	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
#define idA3AD03LDU	 554	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
#define A3AD04LDU	 BUFFER[1320]	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
#define idA3AD04LDU	 555	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
#define A3AD05LDU	 BUFFER[1322]	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
#define idA3AD05LDU	 556	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
#define A3AD01LDU	 BUFFER[1324]	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
#define idA3AD01LDU	 557	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
#define A3CV02RDU	 BUFFER[1326]	//( - , DU) Заданная скорость перемещения ИС1
#define idA3CV02RDU	 558	//( - , DU) Заданная скорость перемещения ИС1
#define A3AB07LDU	 BUFFER[1331]	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
#define idA3AB07LDU	 559	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
#define A3AB08LDU	 BUFFER[1333]	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
#define idA3AB08LDU	 560	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
#define A3AB05LDU	 BUFFER[1335]	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
#define idA3AB05LDU	 561	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
#define A3AB06LDU	 BUFFER[1337]	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
#define idA3AB06LDU	 562	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
#define A3AB09LDU	 BUFFER[1339]	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
#define idA3AB09LDU	 563	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
#define A3AB10LDU	 BUFFER[1341]	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
#define idA3AB10LDU	 564	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
#define A3AB11LDU	 BUFFER[1343]	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
#define idA3AB11LDU	 565	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
#define A3AB12LDU	 BUFFER[1345]	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA3AB12LDU	 566	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A3AB14LDU	 BUFFER[1347]	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
#define idA3AB14LDU	 567	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
#define A3AB16LDU	 BUFFER[1349]	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
#define idA3AB16LDU	 568	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
#define A3AB17LDU	 BUFFER[1351]	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
#define idA3AB17LDU	 569	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
#define A3AB18LDU	 BUFFER[1353]	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
#define idA3AB18LDU	 570	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
#define A3AB20LDU	 BUFFER[1355]	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
#define idA3AB20LDU	 571	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
#define B3VS12LDU	 BUFFER[1357]	//( - , DU) Движение ИС2 в сторону ВУ
#define idB3VS12LDU	 572	//( - , DU) Движение ИС2 в сторону ВУ
#define B3AB04LDU	 BUFFER[1359]	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
#define idB3AB04LDU	 573	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
#define B3AB02LDU	 BUFFER[1361]	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
#define idB3AB02LDU	 574	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
#define B3AB01LDU	 BUFFER[1363]	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
#define idB3AB01LDU	 575	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
#define B1CV02RDU	 BUFFER[1365]	//( - , DU) Заданная скорость перемещения ББ2
#define idB1CV02RDU	 576	//( - , DU) Заданная скорость перемещения ББ2
#define B1AB07LDU	 BUFFER[1370]	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
#define idB1AB07LDU	 577	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
#define B1AB08LDU	 BUFFER[1372]	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
#define idB1AB08LDU	 578	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
#define B1AB05LDU	 BUFFER[1374]	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
#define idB1AB05LDU	 579	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
#define B1AB06LDU	 BUFFER[1376]	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
#define idB1AB06LDU	 580	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
#define B1AB09LDU	 BUFFER[1378]	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
#define idB1AB09LDU	 581	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
#define B1AB10LDU	 BUFFER[1380]	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
#define idB1AB10LDU	 582	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
#define B1AB11LDU	 BUFFER[1382]	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
#define idB1AB11LDU	 583	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
#define B1AB12LDU	 BUFFER[1384]	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idB1AB12LDU	 584	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define B1AB13LDU	 BUFFER[1386]	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
#define idB1AB13LDU	 585	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
#define B1AB14LDU	 BUFFER[1388]	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
#define idB1AB14LDU	 586	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
#define B1AB16LDU	 BUFFER[1390]	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
#define idB1AB16LDU	 587	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
#define B1AB17LDU	 BUFFER[1392]	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
#define idB1AB17LDU	 588	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
#define B1AB18LDU	 BUFFER[1394]	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
#define idB1AB18LDU	 589	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
#define A3VS12LDU	 BUFFER[1396]	//( - , DU) Движение ИС1 в сторону ВУ
#define idA3VS12LDU	 590	//( - , DU) Движение ИС1 в сторону ВУ
#define A3CV01RDU	 BUFFER[1398]	//( - , DU) Измеренная скорость перемещения ИС1
#define idA3CV01RDU	 591	//( - , DU) Измеренная скорость перемещения ИС1
#define A3AB04LDU	 BUFFER[1403]	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
#define idA3AB04LDU	 592	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
#define A3AB02LDU	 BUFFER[1405]	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
#define idA3AB02LDU	 593	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
#define A3AB01LDU	 BUFFER[1407]	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
#define idA3AB01LDU	 594	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
#define A3VS22LDU	 BUFFER[1409]	//( - , DU) Движение ИС1 в сторону НУ
#define idA3VS22LDU	 595	//( - , DU) Движение ИС1 в сторону НУ
#define A3AZ03LDU	 BUFFER[1411]	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
#define idA3AZ03LDU	 596	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
#define A3AD11LDU	 BUFFER[1413]	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	 597	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
#define A3AD21LDU	 BUFFER[1415]	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	 598	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
#define C1MD31LP1	 BUFFER[1417]	//( - , DU) Кнопка СБРОС ББ
#define idC1MD31LP1	 599	//( - , DU) Кнопка СБРОС ББ
#define C1MD31LP2	 BUFFER[1419]	//( - , DU) Кнопка СБРОС ББ
#define idC1MD31LP2	 600	//( - , DU) Кнопка СБРОС ББ
#define A2AD31LDU	 BUFFER[1421]	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
#define idA2AD31LDU	 601	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
#define B2AD31LDU	 BUFFER[1423]	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
#define idB2AD31LDU	 602	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
#define A1AD31LDU	 BUFFER[1425]	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
#define idA1AD31LDU	 603	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
#define B1AD31LDU	 BUFFER[1427]	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
#define idB1AD31LDU	 604	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
#define A2AD32LDU	 BUFFER[1429]	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
#define idA2AD32LDU	 605	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
#define B2AD32LDU	 BUFFER[1431]	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
#define idB2AD32LDU	 606	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
#define A1AD32LDU	 BUFFER[1433]	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
#define idA1AD32LDU	 607	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
#define B1AD32LDU	 BUFFER[1435]	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
#define idB1AD32LDU	 608	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
#define R0MD11LP2	 BUFFER[1437]	//( - , DU) Кнопка Пуск проверки схем сброса
#define idR0MD11LP2	 609	//( - , DU) Кнопка Пуск проверки схем сброса
#define R0VX01LDU	 BUFFER[1439]	//( - , DU) ДО ИМПУЛЬСА
#define idR0VX01LDU	 610	//( - , DU) ДО ИМПУЛЬСА
#define R0VL01IDU	 BUFFER[1441]	//( - , DU) До импульса минут
#define idR0VL01IDU	 611	//( - , DU) До импульса минут
#define R0VL11IDU	 BUFFER[1444]	//( - , DU) До импульса секунд
#define idR0VL11IDU	 612	//( - , DU) До импульса секунд
#define R0VL06RDU	 BUFFER[1447]	//( - , DU) Индикация (Время задержки от ВУ РБ)
#define idR0VL06RDU	 613	//( - , DU) Индикация (Время задержки от ВУ РБ)
#define B3AD33LDU	 BUFFER[1452]	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define idB3AD33LDU	 614	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define B3IS11LDU	 BUFFER[1454]	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
#define idB3IS11LDU	 615	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
#define R0VL02RDU	 BUFFER[1456]	//( - , DU) Индикация (Время задержки ИНИ)
#define idR0VL02RDU	 616	//( - , DU) Индикация (Время задержки ИНИ)
#define R8AD21LDU	 BUFFER[1461]	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
#define idR8AD21LDU	 617	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
#define R0AD14LDU	 BUFFER[1463]	//( - , DU) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 618	//( - , DU) Имитация срабатывания верхней АС II УР
#define R0VL04RDU	 BUFFER[1465]	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
#define idR0VL04RDU	 619	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
#define R0AB04LDU	 BUFFER[1470]	//( - , DU) Нарушение времени срабатывания верхней АС II УР
#define idR0AB04LDU	 620	//( - , DU) Нарушение времени срабатывания верхней АС II УР
#define R0AB06LDU	 BUFFER[1472]	//( - , DU) Нарушение времени задержки от ВУ РБ
#define idR0AB06LDU	 621	//( - , DU) Нарушение времени задержки от ВУ РБ
#define B3VS22LDU	 BUFFER[1474]	//( - , DU) Движение ИС2 в сторону НУ
#define idB3VS22LDU	 622	//( - , DU) Движение ИС2 в сторону НУ
#define B3AZ03LDU	 BUFFER[1476]	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
#define idB3AZ03LDU	 623	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
#define B3AD11LDU	 BUFFER[1478]	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	 624	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
#define B3AD21LDU	 BUFFER[1480]	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	 625	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
#define B3AD02LDU	 BUFFER[1482]	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
#define idB3AD02LDU	 626	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
#define B3AD03LDU	 BUFFER[1484]	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
#define idB3AD03LDU	 627	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
#define B3AD04LDU	 BUFFER[1486]	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
#define idB3AD04LDU	 628	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
#define B3AD05LDU	 BUFFER[1488]	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
#define idB3AD05LDU	 629	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
#define B3AD01LDU	 BUFFER[1490]	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
#define idB3AD01LDU	 630	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
#define B3CV02RDU	 BUFFER[1492]	//( - , DU) Заданная скорость перемещения ИС2
#define idB3CV02RDU	 631	//( - , DU) Заданная скорость перемещения ИС2
#define B3AB07LDU	 BUFFER[1497]	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
#define idB3AB07LDU	 632	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
#define B3AB08LDU	 BUFFER[1499]	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
#define idB3AB08LDU	 633	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
#define B3AB05LDU	 BUFFER[1501]	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
#define idB3AB05LDU	 634	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
#define B3AB06LDU	 BUFFER[1503]	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
#define idB3AB06LDU	 635	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
#define B3AB09LDU	 BUFFER[1505]	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
#define idB3AB09LDU	 636	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
#define B3AB10LDU	 BUFFER[1507]	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
#define idB3AB10LDU	 637	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
#define B3AB11LDU	 BUFFER[1509]	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
#define idB3AB11LDU	 638	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
#define B3AB12LDU	 BUFFER[1511]	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define idB3AB12LDU	 639	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define B3AB14LDU	 BUFFER[1513]	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
#define idB3AB14LDU	 640	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
#define B3AB16LDU	 BUFFER[1515]	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
#define idB3AB16LDU	 641	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
#define B3AB17LDU	 BUFFER[1517]	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
#define idB3AB17LDU	 642	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
#define B3AB18LDU	 BUFFER[1519]	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
#define idB3AB18LDU	 643	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
#define B3AB20LDU	 BUFFER[1521]	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
#define idB3AB20LDU	 644	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
#define B2AB07LDU	 BUFFER[1523]	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
#define idB2AB07LDU	 645	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
#define B2AB08LDU	 BUFFER[1525]	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
#define idB2AB08LDU	 646	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
#define B2AB05LDU	 BUFFER[1527]	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
#define idB2AB05LDU	 647	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
#define B2AB06LDU	 BUFFER[1529]	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
#define idB2AB06LDU	 648	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
#define B2AB09LDU	 BUFFER[1531]	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
#define idB2AB09LDU	 649	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
#define B2AB10LDU	 BUFFER[1533]	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
#define idB2AB10LDU	 650	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
#define B2AB11LDU	 BUFFER[1535]	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
#define idB2AB11LDU	 651	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
#define B2AB12LDU	 BUFFER[1537]	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define idB2AB12LDU	 652	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define B2AB13LDU	 BUFFER[1539]	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
#define idB2AB13LDU	 653	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
#define B2AB14LDU	 BUFFER[1541]	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
#define idB2AB14LDU	 654	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
#define B2AB16LDU	 BUFFER[1543]	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
#define idB2AB16LDU	 655	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
#define B2AB17LDU	 BUFFER[1545]	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
#define idB2AB17LDU	 656	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
#define R1AZ03LDU	 BUFFER[1547]	//( - , DU) Несанкционированное перемещение МДЗ1
#define idR1AZ03LDU	 657	//( - , DU) Несанкционированное перемещение МДЗ1
#define R1AB01LDU	 BUFFER[1549]	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
#define idR1AB01LDU	 658	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
#define R1AB02LDU	 BUFFER[1551]	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
#define idR1AB02LDU	 659	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
#define R2AZ03LDU	 BUFFER[1553]	//( - , DU) Несанкционированное перемещение МДЗ2
#define idR2AZ03LDU	 660	//( - , DU) Несанкционированное перемещение МДЗ2
#define R2AB01LDU	 BUFFER[1555]	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
#define idR2AB01LDU	 661	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
#define R2AB02LDU	 BUFFER[1557]	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
#define idR2AB02LDU	 662	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
#define R1AB04LDU	 BUFFER[1559]	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
#define idR1AB04LDU	 663	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
#define R2AB04LDU	 BUFFER[1561]	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
#define idR2AB04LDU	 664	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
#define R1AD10LDU	 BUFFER[1563]	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
#define idR1AD10LDU	 665	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
#define R1AD20LDU	 BUFFER[1565]	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
#define idR1AD20LDU	 666	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
#define R1IS11LDU	 BUFFER[1567]	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
#define idR1IS11LDU	 667	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
#define A2AB09LDU	 BUFFER[1569]	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
#define idA2AB09LDU	 668	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
#define A2AB10LDU	 BUFFER[1571]	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
#define idA2AB10LDU	 669	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
#define A2AB11LDU	 BUFFER[1573]	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
#define idA2AB11LDU	 670	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
#define A2AB12LDU	 BUFFER[1575]	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA2AB12LDU	 671	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A2AB13LDU	 BUFFER[1577]	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
#define idA2AB13LDU	 672	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
#define A2AB14LDU	 BUFFER[1579]	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
#define idA2AB14LDU	 673	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
#define A2AB16LDU	 BUFFER[1581]	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
#define idA2AB16LDU	 674	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
#define A2AB17LDU	 BUFFER[1583]	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
#define idA2AB17LDU	 675	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
#define A2AD01LDU	 BUFFER[1585]	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
#define idA2AD01LDU	 676	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
#define A2CV02RDU	 BUFFER[1587]	//( - , DU) Заданная скорость перемещения РБ1
#define idA2CV02RDU	 677	//( - , DU) Заданная скорость перемещения РБ1
#define B2CV01RDU	 BUFFER[1592]	//( - , DU) Измеренная скорость перемещения РБ2
#define idB2CV01RDU	 678	//( - , DU) Измеренная скорость перемещения РБ2
#define B2AB04LDU	 BUFFER[1597]	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
#define idB2AB04LDU	 679	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
#define B2AB02LDU	 BUFFER[1599]	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
#define idB2AB02LDU	 680	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
#define B2AB01LDU	 BUFFER[1601]	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
#define idB2AB01LDU	 681	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
#define B2AZ03LDU	 BUFFER[1603]	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
#define idB2AZ03LDU	 682	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
#define B2AD11LDU	 BUFFER[1605]	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	 683	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
#define B2AD21LDU	 BUFFER[1607]	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	 684	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
#define B2AD02LDU	 BUFFER[1609]	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
#define idB2AD02LDU	 685	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
#define B2AD03LDU	 BUFFER[1611]	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
#define idB2AD03LDU	 686	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
#define B2AD04LDU	 BUFFER[1613]	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
#define idB2AD04LDU	 687	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
#define B2AD05LDU	 BUFFER[1615]	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
#define idB2AD05LDU	 688	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
#define B2AD01LDU	 BUFFER[1617]	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
#define idB2AD01LDU	 689	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
#define B2CV02RDU	 BUFFER[1619]	//( - , DU) Заданная скорость перемещения РБ2
#define idB2CV02RDU	 690	//( - , DU) Заданная скорость перемещения РБ2
#define A1AB09LDU	 BUFFER[1624]	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
#define idA1AB09LDU	 691	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
#define A1AB10LDU	 BUFFER[1626]	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
#define idA1AB10LDU	 692	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
#define A1AB11LDU	 BUFFER[1628]	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
#define idA1AB11LDU	 693	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
#define A1AB12LDU	 BUFFER[1630]	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA1AB12LDU	 694	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A1AB13LDU	 BUFFER[1632]	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
#define idA1AB13LDU	 695	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
#define A1AB14LDU	 BUFFER[1634]	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
#define idA1AB14LDU	 696	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
#define A1AB16LDU	 BUFFER[1636]	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
#define idA1AB16LDU	 697	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
#define A1AB17LDU	 BUFFER[1638]	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
#define idA1AB17LDU	 698	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
#define A1AB18LDU	 BUFFER[1640]	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
#define idA1AB18LDU	 699	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
#define B1VS12LDU	 BUFFER[1642]	//( - , DU) Движение ББ2 в сторону ВУ
#define idB1VS12LDU	 700	//( - , DU) Движение ББ2 в сторону ВУ
#define B1CV01RDU	 BUFFER[1644]	//( - , DU) Измеренная скорость перемещения ББ2
#define idB1CV01RDU	 701	//( - , DU) Измеренная скорость перемещения ББ2
#define B1AB04LDU	 BUFFER[1649]	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
#define idB1AB04LDU	 702	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
#define B1AB02LDU	 BUFFER[1651]	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
#define idB1AB02LDU	 703	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
#define B1AB01LDU	 BUFFER[1653]	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
#define idB1AB01LDU	 704	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
#define B1VS22LDU	 BUFFER[1655]	//( - , DU) Движение ББ2 в сторону НУ
#define idB1VS22LDU	 705	//( - , DU) Движение ББ2 в сторону НУ
#define B1AZ03LDU	 BUFFER[1657]	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
#define idB1AZ03LDU	 706	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
#define B1AD11LDU	 BUFFER[1659]	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	 707	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
#define B1AD21LDU	 BUFFER[1661]	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	 708	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
#define B1AD02LDU	 BUFFER[1663]	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
#define idB1AD02LDU	 709	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
#define B1AD03LDU	 BUFFER[1665]	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
#define idB1AD03LDU	 710	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
#define B1AD04LDU	 BUFFER[1667]	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
#define idB1AD04LDU	 711	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
#define B1AD05LDU	 BUFFER[1669]	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
#define idB1AD05LDU	 712	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
#define B1AD01LDU	 BUFFER[1671]	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
#define idB1AD01LDU	 713	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
#define R1VS22LDU	 BUFFER[1673]	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	 714	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
#define R2VS22LDU	 BUFFER[1675]	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	 715	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
#define R2VS12LDU	 BUFFER[1677]	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	 716	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
#define R1VS12LDU	 BUFFER[1679]	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	 717	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
#define R2IS11LDU	 BUFFER[1681]	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
#define idR2IS11LDU	 718	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
#define A1VS12LDU	 BUFFER[1683]	//( - , DU) Движение ББ1 в сторону ВУ
#define idA1VS12LDU	 719	//( - , DU) Движение ББ1 в сторону ВУ
#define A1CV01RDU	 BUFFER[1685]	//( - , DU) Измеренная скорость перемещения ББ1
#define idA1CV01RDU	 720	//( - , DU) Измеренная скорость перемещения ББ1
#define A1AB04LDU	 BUFFER[1690]	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
#define idA1AB04LDU	 721	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
#define A1AB02LDU	 BUFFER[1692]	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
#define idA1AB02LDU	 722	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
#define A1AB01LDU	 BUFFER[1694]	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
#define idA1AB01LDU	 723	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
#define A1VS22LDU	 BUFFER[1696]	//( - , DU) Движение ББ1 в сторону НУ
#define idA1VS22LDU	 724	//( - , DU) Движение ББ1 в сторону НУ
#define A1AZ03LDU	 BUFFER[1698]	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
#define idA1AZ03LDU	 725	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
#define A1AD11LDU	 BUFFER[1700]	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	 726	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
#define A1AD21LDU	 BUFFER[1702]	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	 727	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
#define A1AD02LDU	 BUFFER[1704]	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
#define idA1AD02LDU	 728	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
#define A1AD03LDU	 BUFFER[1706]	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
#define idA1AD03LDU	 729	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
#define A1AD04LDU	 BUFFER[1708]	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
#define idA1AD04LDU	 730	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
#define A1AD05LDU	 BUFFER[1710]	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
#define idA1AD05LDU	 731	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
#define A1AD01LDU	 BUFFER[1712]	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
#define idA1AD01LDU	 732	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
#define A1CV02RDU	 BUFFER[1714]	//( - , DU) Заданная скорость перемещения ББ1
#define idA1CV02RDU	 733	//( - , DU) Заданная скорость перемещения ББ1
#define A1AB07LDU	 BUFFER[1719]	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
#define idA1AB07LDU	 734	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
#define A1AB08LDU	 BUFFER[1721]	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
#define idA1AB08LDU	 735	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
#define A1AB05LDU	 BUFFER[1723]	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
#define idA1AB05LDU	 736	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
#define A1AB06LDU	 BUFFER[1725]	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
#define idA1AB06LDU	 737	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
#define fEM_A1UC03RDU	 BUFFER[1727]	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define idfEM_A1UC03RDU	 738	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define dEM_A1UC05UDU	 BUFFER[1732]	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC05UDU	 739	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define dEM_A1UC06UDU	 BUFFER[1737]	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC06UDU	 740	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define dEM_A2UC06UDU	 BUFFER[1742]	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC06UDU	 741	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define dEM_A2UC05UDU	 BUFFER[1747]	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC05UDU	 742	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define fEM_A2UC03RDU	 BUFFER[1752]	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define idfEM_A2UC03RDU	 743	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define dEM_A3UC06UDU	 BUFFER[1757]	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC06UDU	 744	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define dEM_A3UC05UDU	 BUFFER[1762]	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC05UDU	 745	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define fEM_A3UC03RDU	 BUFFER[1767]	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define idfEM_A3UC03RDU	 746	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define dEM_A8UC06UDU	 BUFFER[1772]	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define iddEM_A8UC06UDU	 747	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define fEM_A8UC03RDU	 BUFFER[1777]	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
#define idfEM_A8UC03RDU	 748	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
#define dEM_A8UC05UDU	 BUFFER[1782]	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define iddEM_A8UC05UDU	 749	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define fEM_R0UV81RDU	 BUFFER[1787]	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	 750	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	 BUFFER[1792]	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	 751	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	 BUFFER[1797]	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	 752	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	 BUFFER[1802]	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	 753	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define fEM_R0UV86RDU	 BUFFER[1807]	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	 754	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV85RDU	 BUFFER[1812]	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	 755	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV87RDU	 BUFFER[1817]	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	 756	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_A3UP03RDU	 BUFFER[1822]	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	 757	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	 BUFFER[1827]	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	 758	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP43RDU	 BUFFER[1832]	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define idfEM_A3UP43RDU	 759	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define fEM_A3UP44RDU	 BUFFER[1837]	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP44RDU	 760	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP53RDU	 BUFFER[1842]	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP53RDU	 761	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP85RDU	 BUFFER[1847]	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP85RDU	 762	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP88RDU	 BUFFER[1852]	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP88RDU	 763	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP86RDU	 BUFFER[1857]	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP86RDU	 764	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_B8UV01RDU	 BUFFER[1862]	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
#define idfEM_B8UV01RDU	 765	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
#define fEM_B8UV02RDU	 BUFFER[1867]	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
#define idfEM_B8UV02RDU	 766	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
#define fEM_B8UV03RDU	 BUFFER[1872]	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
#define idfEM_B8UV03RDU	 767	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
#define fEM_B8UL04RDU	 BUFFER[1877]	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
#define idfEM_B8UL04RDU	 768	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
#define iEM_A2UV03CDU	 BUFFER[1882]	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define idiEM_A2UV03CDU	 769	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define fEM_A2UV01RDU	 BUFFER[1885]	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define idfEM_A2UV01RDU	 770	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define fEM_A2UV02RDU	 BUFFER[1890]	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define idfEM_A2UV02RDU	 771	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define fEM_A1UV01RDU	 BUFFER[1895]	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define idfEM_A1UV01RDU	 772	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define fEM_A1UV02RDU	 BUFFER[1900]	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define idfEM_A1UV02RDU	 773	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define fEM_A1UC06RDU	 BUFFER[1905]	//(A1UC06RDU) Уставка определения самохода ББ  мм
#define idfEM_A1UC06RDU	 774	//(A1UC06RDU) Уставка определения самохода ББ  мм
#define fEM_A1UC05RDU	 BUFFER[1910]	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A1UC05RDU	 775	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A1UL04RDU	 BUFFER[1915]	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define idfEM_A1UL04RDU	 776	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define fEM_A3UV01RDU	 BUFFER[1920]	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
#define idfEM_A3UV01RDU	 777	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
#define fEM_A3UV02RDU	 BUFFER[1925]	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
#define idfEM_A3UV02RDU	 778	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
#define fEM_A3UC06RDU	 BUFFER[1930]	//(A3UC06RDU) Уставка определения самохода ИС1  мм
#define idfEM_A3UC06RDU	 779	//(A3UC06RDU) Уставка определения самохода ИС1  мм
#define fEM_A3UC05RDU	 BUFFER[1935]	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A3UC05RDU	 780	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define fEM_A3UL04RDU	 BUFFER[1940]	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define idfEM_A3UL04RDU	 781	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define fEM_A3UP54RDU	 BUFFER[1945]	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define idfEM_A3UP54RDU	 782	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define fEM_A3UP87RDU	 BUFFER[1950]	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP87RDU	 783	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_R0UL05RDU	 BUFFER[1955]	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
#define idfEM_R0UL05RDU	 784	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
#define fEM_R0UL20RDU	 BUFFER[1960]	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
#define idfEM_R0UL20RDU	 785	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
#define fEM_B8UV04RDU	 BUFFER[1965]	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
#define idfEM_B8UV04RDU	 786	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
#define fEM_B8UC06RDU	 BUFFER[1970]	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
#define idfEM_B8UC06RDU	 787	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
#define fEM_B8UC05RDU	 BUFFER[1975]	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
#define idfEM_B8UC05RDU	 788	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
#define fEM_A2UL05RDU	 BUFFER[1980]	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define idfEM_A2UL05RDU	 789	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define fEM_A2UL03RDU	 BUFFER[1985]	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL03RDU	 790	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A2UC06RDU	 BUFFER[1990]	//(A2UC06RDU) Уставка определения самохода РБ  мм
#define idfEM_A2UC06RDU	 791	//(A2UC06RDU) Уставка определения самохода РБ  мм
#define fEM_A2UC05RDU	 BUFFER[1995]	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A2UC05RDU	 792	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A2UL04RDU	 BUFFER[2000]	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define idfEM_A2UL04RDU	 793	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define fEM_A1UL03RDU	 BUFFER[2005]	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define idfEM_A1UL03RDU	 794	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define fEM_A1UL05RDU	 BUFFER[2010]	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define idfEM_A1UL05RDU	 795	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define fEM_A3UL03RDU	 BUFFER[2015]	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define idfEM_A3UL03RDU	 796	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define fEM_A3UL05RDU	 BUFFER[2020]	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define idfEM_A3UL05RDU	 797	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define fEM_A1UC08RDU	 BUFFER[2025]	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define idfEM_A1UC08RDU	 798	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define fEM_A3UC08RDU	 BUFFER[2030]	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define idfEM_A3UC08RDU	 799	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define fEM_A1UC07RDU	 BUFFER[2035]	//(A1UC07RDU) Зона возврата при наведении ББ мм
#define idfEM_A1UC07RDU	 800	//(A1UC07RDU) Зона возврата при наведении ББ мм
#define fEM_A1UL01RDU	 BUFFER[2040]	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A1UL01RDU	 801	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A3UC07RDU	 BUFFER[2045]	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define idfEM_A3UC07RDU	 802	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define fEM_A3UL01RDU	 BUFFER[2050]	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A3UL01RDU	 803	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A2UC08RDU	 BUFFER[2055]	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define idfEM_A2UC08RDU	 804	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define fEM_A2UC07RDU	 BUFFER[2060]	//(A2UC07RDU) Зона возврата при наведении РБ  мм
#define idfEM_A2UC07RDU	 805	//(A2UC07RDU) Зона возврата при наведении РБ  мм
#define fEM_A2UL01RDU	 BUFFER[2065]	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A2UL01RDU	 806	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_B8UC01RDU	 BUFFER[2070]	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
#define idfEM_B8UC01RDU	 807	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
#define fEM_B8UL07RDU	 BUFFER[2075]	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
#define idfEM_B8UL07RDU	 808	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
#define fEM_B8UC02RDU	 BUFFER[2080]	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
#define idfEM_B8UC02RDU	 809	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
#define fEM_B8UL01RDU	 BUFFER[2085]	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_B8UL01RDU	 810	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_B8UL05RDU	 BUFFER[2090]	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
#define idfEM_B8UL05RDU	 811	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
#define fEM_B8UL03RDU	 BUFFER[2095]	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
#define idfEM_B8UL03RDU	 812	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
#define fEM_B8UL06RDU	 BUFFER[2100]	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
#define idfEM_B8UL06RDU	 813	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
#define fEM_A9UZ03RDU	 BUFFER[2105]	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
#define idfEM_A9UZ03RDU	 814	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
#define fEM_A9UZ04RDU	 BUFFER[2110]	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
#define idfEM_A9UZ04RDU	 815	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
#define fEM_A9UZ05RDU	 BUFFER[2115]	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
#define idfEM_A9UZ05RDU	 816	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
#define fEM_R4UZ04RDU	 BUFFER[2120]	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define idfEM_R4UZ04RDU	 817	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define fEM_R4UZ03RDU	 BUFFER[2125]	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define idfEM_R4UZ03RDU	 818	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define fEM_R4UZ05RDU	 BUFFER[2130]	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define idfEM_R4UZ05RDU	 819	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define fEM_A5UZ03RDU	 BUFFER[2135]	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
#define idfEM_A5UZ03RDU	 820	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
#define fEM_A5UZ04RDU	 BUFFER[2140]	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
#define idfEM_A5UZ04RDU	 821	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
#define fEM_A5UZ05RDU	 BUFFER[2145]	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
#define idfEM_A5UZ05RDU	 822	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
#define fEM_A4UZ03RDU	 BUFFER[2150]	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
#define idfEM_A4UZ03RDU	 823	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
#define fEM_A4UZ04RDU	 BUFFER[2155]	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
#define idfEM_A4UZ04RDU	 824	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
#define fEM_A4UZ05RDU	 BUFFER[2160]	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
#define idfEM_A4UZ05RDU	 825	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
#define fEM_A6UZ03RDU	 BUFFER[2165]	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
#define idfEM_A6UZ03RDU	 826	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
#define fEM_A6UZ04RDU	 BUFFER[2170]	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
#define idfEM_A6UZ04RDU	 827	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
#define fEM_A6UZ05RDU	 BUFFER[2175]	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
#define idfEM_A6UZ05RDU	 828	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
#define fEM_R1UZ03RDU	 BUFFER[2180]	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define idfEM_R1UZ03RDU	 829	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define fEM_R1UZ04RDU	 BUFFER[2185]	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define idfEM_R1UZ04RDU	 830	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define fEM_R1UZ05RDU	 BUFFER[2190]	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define idfEM_R1UZ05RDU	 831	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define fEM_R0UL04RDU	 BUFFER[2195]	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
#define idfEM_R0UL04RDU	 832	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
#define fEM_R0UL06RDU	 BUFFER[2200]	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
#define idfEM_R0UL06RDU	 833	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
#define fEM_R0UL03RDU	 BUFFER[2205]	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
#define idfEM_R0UL03RDU	 834	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
#define fEM_R0UL17RDU	 BUFFER[2210]	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
#define idfEM_R0UL17RDU	 835	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
#define fEM_R0UL19RDU	 BUFFER[2215]	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define idfEM_R0UL19RDU	 836	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define fEM_R0UL07RDU	 BUFFER[2220]	//(R0UL07RDU) Время срабатывания верхней АС II УР
#define idfEM_R0UL07RDU	 837	//(R0UL07RDU) Время срабатывания верхней АС II УР
#define fEM_R0UL18RDU	 BUFFER[2225]	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
#define idfEM_R0UL18RDU	 838	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
#define fEM_R0UL16RDU	 BUFFER[2230]	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
#define idfEM_R0UL16RDU	 839	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
#define fEM_R0UL02RDU	 BUFFER[2235]	//(R0UL02RDU) Время задержки  ИНИ
#define idfEM_R0UL02RDU	 840	//(R0UL02RDU) Время задержки  ИНИ
#define fEM_R0UN08RDU	 BUFFER[2240]	//(R0UN08RDU) 8-я заданная мощность
#define idfEM_R0UN08RDU	 841	//(R0UN08RDU) 8-я заданная мощность
#define fEM_R0UN07RDU	 BUFFER[2245]	//(R0UN07RDU) 7-я заданная мощность
#define idfEM_R0UN07RDU	 842	//(R0UN07RDU) 7-я заданная мощность
#define fEM_R0UN06RDU	 BUFFER[2250]	//(R0UN06RDU) 6-я заданная мощность
#define idfEM_R0UN06RDU	 843	//(R0UN06RDU) 6-я заданная мощность
#define fEM_R0UN05RDU	 BUFFER[2255]	//(R0UN05RDU) 5-я заданная мощность
#define idfEM_R0UN05RDU	 844	//(R0UN05RDU) 5-я заданная мощность
#define fEM_R0UN04RDU	 BUFFER[2260]	//(R0UN04RDU) 4-я заданная мощность
#define idfEM_R0UN04RDU	 845	//(R0UN04RDU) 4-я заданная мощность
#define fEM_R0UN03RDU	 BUFFER[2265]	//(R0UN03RDU) Ограничение 3 по мощности
#define idfEM_R0UN03RDU	 846	//(R0UN03RDU) Ограничение 3 по мощности
#define fEM_R0UN02RDU	 BUFFER[2270]	//(R0UN02RDU) 2-я заданная мощность
#define idfEM_R0UN02RDU	 847	//(R0UN02RDU) 2-я заданная мощность
#define fEM_R0UN01RDU	 BUFFER[2275]	//(R0UN01RDU) 1-я заданная мощность
#define idfEM_R0UN01RDU	 848	//(R0UN01RDU) 1-я заданная мощность
#define fEM_A2UC82RDU	 BUFFER[2280]	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC82RDU	 849	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define fEM_A2UC83RDU	 BUFFER[2285]	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define idfEM_A2UC83RDU	 850	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define fEM_A1UC83RDU	 BUFFER[2290]	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define idfEM_A1UC83RDU	 851	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define fEM_A2UC81RDU	 BUFFER[2295]	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC81RDU	 852	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define fEM_A1UC81RDU	 BUFFER[2300]	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC81RDU	 853	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define fEM_A1UC82RDU	 BUFFER[2305]	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC82RDU	 854	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define fEM_A2UL83RDU	 BUFFER[2310]	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL83RDU	 855	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A3UC81RDU	 BUFFER[2315]	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define idfEM_A3UC81RDU	 856	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define fEM_A3UC82RDU	 BUFFER[2320]	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define idfEM_A3UC82RDU	 857	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define fEM_R0UN80RDU	 BUFFER[2325]	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define idfEM_R0UN80RDU	 858	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define iEM_A2UV01IDU	 BUFFER[2330]	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV01IDU	 859	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define iEM_A2UV02IDU	 BUFFER[2333]	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV02IDU	 860	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define iEM_A1UV01IDU	 BUFFER[2336]	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV01IDU	 861	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define iEM_A1UV02IDU	 BUFFER[2339]	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV02IDU	 862	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define iEM_A1UV03IDU	 BUFFER[2342]	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define idiEM_A1UV03IDU	 863	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define iEM_A3UV01IDU	 BUFFER[2345]	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define idiEM_A3UV01IDU	 864	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define iEM_A3UV02IDU	 BUFFER[2348]	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define idiEM_A3UV02IDU	 865	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define lEM_R0MD01LC1	 BUFFER[2351]	//(R0MD01LC1) Ручное управление ОРР
#define idlEM_R0MD01LC1	 866	//(R0MD01LC1) Ручное управление ОРР
#define fEM_A3UC09RDU	 BUFFER[2353]	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC09RDU	 867	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define fEM_A2UC02RDU	 BUFFER[2358]	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define idfEM_A2UC02RDU	 868	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define fEM_A1UC02RDU	 BUFFER[2363]	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define idfEM_A1UC02RDU	 869	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define fEM_A3UC02RDU	 BUFFER[2368]	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define idfEM_A3UC02RDU	 870	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define fEM_R0UL21RDU	 BUFFER[2373]	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
#define idfEM_R0UL21RDU	 871	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
#define fEM_R0UN09RDU	 BUFFER[2378]	//(R0UN09RDU) Минимальный период при регулировании мощности
#define idfEM_R0UN09RDU	 872	//(R0UN09RDU) Минимальный период при регулировании мощности
#define fEM_R0UN11RDU	 BUFFER[2383]	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
#define idfEM_R0UN11RDU	 873	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
#define fEM_R0UN12RDU	 BUFFER[2388]	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
#define idfEM_R0UN12RDU	 874	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
#define fEM_R0UN13RDU	 BUFFER[2393]	//(R0UN13RDU) Минимальное изменение координаты, мм
#define idfEM_R0UN13RDU	 875	//(R0UN13RDU) Минимальное изменение координаты, мм
#define fEM_R0UN14RDU	 BUFFER[2398]	//(R0UN14RDU) Максимальная координата штока ИМ, мм
#define idfEM_R0UN14RDU	 876	//(R0UN14RDU) Максимальная координата штока ИМ, мм
#define fEM_R0UN16RDU	 BUFFER[2403]	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN16RDU	 877	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN17RDU	 BUFFER[2408]	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN17RDU	 878	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN18RDU	 BUFFER[2413]	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
#define idfEM_R0UN18RDU	 879	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
#define fEM_R0UN19RDU	 BUFFER[2418]	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define idfEM_R0UN19RDU	 880	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define fEM_R0UN70LDU	 BUFFER[2423]	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN70LDU	 881	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN71LDU	 BUFFER[2428]	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN71LDU	 882	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN72LDU	 BUFFER[2433]	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN72LDU	 883	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN73LDU	 BUFFER[2438]	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN73LDU	 884	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN74LDU	 BUFFER[2443]	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN74LDU	 885	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN75LDU	 BUFFER[2448]	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN75LDU	 886	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN80LDU	 BUFFER[2453]	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN80LDU	 887	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define fEM_R0UN81LDU	 BUFFER[2458]	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN81LDU	 888	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define fEM_R0UN82LDU	 BUFFER[2463]	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN82LDU	 889	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define fEM_R0UN83LDU	 BUFFER[2468]	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN83LDU	 890	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define fEM_R0UN84LDU	 BUFFER[2473]	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN84LDU	 891	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define fEM_R0UN85LDU	 BUFFER[2478]	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN85LDU	 892	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define fEM_R0UT20RDU	 BUFFER[2483]	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define idfEM_R0UT20RDU	 893	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define fEM_R0UN25RDU	 BUFFER[2488]	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
#define idfEM_R0UN25RDU	 894	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
#define fEM_R0UN15RDU	 BUFFER[2493]	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
#define idfEM_R0UN15RDU	 895	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
#define fEM_R0UN26RDU	 BUFFER[2498]	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
#define idfEM_R0UN26RDU	 896	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
#define fEM_R0UN27RDU	 BUFFER[2503]	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
#define idfEM_R0UN27RDU	 897	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
#define fEM_R0UN24RDU	 BUFFER[2508]	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN24RDU	 898	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
#define fEM_R0UL25RDU	 BUFFER[2513]	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define idfEM_R0UL25RDU	 899	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define bFirstEnterFlag	 BUFFER[2518]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 900	//(bFirstEnterFlag) 
#define internal2_m182_tx	 BUFFER[2520]	//(internal2_m182_tx) tx - время накопленное сек
#define idinternal2_m182_tx	 901	//(internal2_m182_tx) tx - время накопленное сек
#define internal2_m182_y0	 BUFFER[2525]	//(internal2_m182_y0) y0
#define idinternal2_m182_y0	 902	//(internal2_m182_y0) y0
#define internal2_m176_tx	 BUFFER[2526]	//(internal2_m176_tx) tx - время накопленное сек
#define idinternal2_m176_tx	 903	//(internal2_m176_tx) tx - время накопленное сек
#define internal2_m176_y0	 BUFFER[2531]	//(internal2_m176_y0) y0
#define idinternal2_m176_y0	 904	//(internal2_m176_y0) y0
#define internal2_m173_tx	 BUFFER[2532]	//(internal2_m173_tx) tx - время накопленное сек
#define idinternal2_m173_tx	 905	//(internal2_m173_tx) tx - время накопленное сек
#define internal2_m173_y0	 BUFFER[2537]	//(internal2_m173_y0) y0
#define idinternal2_m173_y0	 906	//(internal2_m173_y0) y0
#define internal2_m165_tx	 BUFFER[2538]	//(internal2_m165_tx) tx - время накопленное сек
#define idinternal2_m165_tx	 907	//(internal2_m165_tx) tx - время накопленное сек
#define internal2_m165_y0	 BUFFER[2543]	//(internal2_m165_y0) y0
#define idinternal2_m165_y0	 908	//(internal2_m165_y0) y0
#define internal2_m158_tx	 BUFFER[2544]	//(internal2_m158_tx) tx - время накопленное сек
#define idinternal2_m158_tx	 909	//(internal2_m158_tx) tx - время накопленное сек
#define internal2_m158_y0	 BUFFER[2549]	//(internal2_m158_y0) y0
#define idinternal2_m158_y0	 910	//(internal2_m158_y0) y0
#define internal2_m155_tx	 BUFFER[2550]	//(internal2_m155_tx) tx - время накопленное сек
#define idinternal2_m155_tx	 911	//(internal2_m155_tx) tx - время накопленное сек
#define internal2_m155_y0	 BUFFER[2555]	//(internal2_m155_y0) y0
#define idinternal2_m155_y0	 912	//(internal2_m155_y0) y0
#define internal2_m149_tx	 BUFFER[2556]	//(internal2_m149_tx) tx - время накопленное сек
#define idinternal2_m149_tx	 913	//(internal2_m149_tx) tx - время накопленное сек
#define internal2_m149_y0	 BUFFER[2561]	//(internal2_m149_y0) y0
#define idinternal2_m149_y0	 914	//(internal2_m149_y0) y0
#define internal2_m144_tx	 BUFFER[2562]	//(internal2_m144_tx) tx - время накопленное сек
#define idinternal2_m144_tx	 915	//(internal2_m144_tx) tx - время накопленное сек
#define internal2_m144_y0	 BUFFER[2567]	//(internal2_m144_y0) y0
#define idinternal2_m144_y0	 916	//(internal2_m144_y0) y0
#define internal2_m141_tx	 BUFFER[2568]	//(internal2_m141_tx) tx - время накопленное сек
#define idinternal2_m141_tx	 917	//(internal2_m141_tx) tx - время накопленное сек
#define internal2_m141_y0	 BUFFER[2573]	//(internal2_m141_y0) y0
#define idinternal2_m141_y0	 918	//(internal2_m141_y0) y0
#define internal2_m134_tx	 BUFFER[2574]	//(internal2_m134_tx) tx - время накопленное сек
#define idinternal2_m134_tx	 919	//(internal2_m134_tx) tx - время накопленное сек
#define internal2_m134_y0	 BUFFER[2579]	//(internal2_m134_y0) y0
#define idinternal2_m134_y0	 920	//(internal2_m134_y0) y0
#define internal2_m132_tx	 BUFFER[2580]	//(internal2_m132_tx) tx - время накопленное сек
#define idinternal2_m132_tx	 921	//(internal2_m132_tx) tx - время накопленное сек
#define internal2_m132_y0	 BUFFER[2585]	//(internal2_m132_y0) y0
#define idinternal2_m132_y0	 922	//(internal2_m132_y0) y0
#define internal2_m127_tx	 BUFFER[2586]	//(internal2_m127_tx) tx - время накопленное сек
#define idinternal2_m127_tx	 923	//(internal2_m127_tx) tx - время накопленное сек
#define internal2_m127_y0	 BUFFER[2591]	//(internal2_m127_y0) y0
#define idinternal2_m127_y0	 924	//(internal2_m127_y0) y0
#define internal2_m195_y0	 BUFFER[2592]	//(internal2_m195_y0) y0
#define idinternal2_m195_y0	 925	//(internal2_m195_y0) y0
#define internal2_m193_y0	 BUFFER[2597]	//(internal2_m193_y0) y0
#define idinternal2_m193_y0	 926	//(internal2_m193_y0) y0
#define internal2_m228_y0	 BUFFER[2602]	//(internal2_m228_y0) state
#define idinternal2_m228_y0	 927	//(internal2_m228_y0) state
#define internal2_m220_y0	 BUFFER[2604]	//(internal2_m220_y0) state
#define idinternal2_m220_y0	 928	//(internal2_m220_y0) state
#define internal2_m208_y1	 BUFFER[2606]	//(internal2_m208_y1) y1 - внутренний параметр
#define idinternal2_m208_y1	 929	//(internal2_m208_y1) y1 - внутренний параметр
#define internal2_m214_y1	 BUFFER[2608]	//(internal2_m214_y1) y1 - внутренний параметр
#define idinternal2_m214_y1	 930	//(internal2_m214_y1) y1 - внутренний параметр
#define internal2_m198_y1	 BUFFER[2610]	//(internal2_m198_y1) y1 - внутренний параметр
#define idinternal2_m198_y1	 931	//(internal2_m198_y1) y1 - внутренний параметр
#define internal2_m205_y1	 BUFFER[2612]	//(internal2_m205_y1) y1 - внутренний параметр
#define idinternal2_m205_y1	 932	//(internal2_m205_y1) y1 - внутренний параметр
#define internal2_m17_Nk0	 BUFFER[2614]	//(internal2_m17_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m17_Nk0	 933	//(internal2_m17_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m17_SetFlag	 BUFFER[2619]	//(internal2_m17_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m17_SetFlag	 934	//(internal2_m17_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m110_Nk0	 BUFFER[2621]	//(internal2_m110_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m110_Nk0	 935	//(internal2_m110_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m110_SetFlag	 BUFFER[2626]	//(internal2_m110_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m110_SetFlag	 936	//(internal2_m110_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m106_Nk0	 BUFFER[2628]	//(internal2_m106_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m106_Nk0	 937	//(internal2_m106_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m106_SetFlag	 BUFFER[2633]	//(internal2_m106_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m106_SetFlag	 938	//(internal2_m106_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m75_Nk0	 BUFFER[2635]	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m75_Nk0	 939	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m75_SetFlag	 BUFFER[2640]	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m75_SetFlag	 940	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m77_Nk0	 BUFFER[2642]	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m77_Nk0	 941	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m77_SetFlag	 BUFFER[2647]	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m77_SetFlag	 942	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m49_Nk0	 BUFFER[2649]	//(internal2_m49_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m49_Nk0	 943	//(internal2_m49_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m49_SetFlag	 BUFFER[2654]	//(internal2_m49_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m49_SetFlag	 944	//(internal2_m49_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m53_Nk0	 BUFFER[2656]	//(internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m53_Nk0	 945	//(internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m53_SetFlag	 BUFFER[2661]	//(internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m53_SetFlag	 946	//(internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m15_Nk0	 BUFFER[2663]	//(internal2_m15_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m15_Nk0	 947	//(internal2_m15_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m15_SetFlag	 BUFFER[2668]	//(internal2_m15_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m15_SetFlag	 948	//(internal2_m15_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal1_m2019_tx	 BUFFER[2670]	//(internal1_m2019_tx) tx - внутренний параметр
#define idinternal1_m2019_tx	 949	//(internal1_m2019_tx) tx - внутренний параметр
#define internal1_m2018_tx	 BUFFER[2675]	//(internal1_m2018_tx) tx - внутренний параметр
#define idinternal1_m2018_tx	 950	//(internal1_m2018_tx) tx - внутренний параметр
#define internal1_m774_tx	 BUFFER[2680]	//(internal1_m774_tx) tx - внутренний параметр
#define idinternal1_m774_tx	 951	//(internal1_m774_tx) tx - внутренний параметр
#define internal1_m731_tx	 BUFFER[2685]	//(internal1_m731_tx) tx - внутренний параметр
#define idinternal1_m731_tx	 952	//(internal1_m731_tx) tx - внутренний параметр
#define internal1_m788_tx	 BUFFER[2690]	//(internal1_m788_tx) tx - внутренний параметр
#define idinternal1_m788_tx	 953	//(internal1_m788_tx) tx - внутренний параметр
#define internal1_m785_tx	 BUFFER[2695]	//(internal1_m785_tx) tx - внутренний параметр
#define idinternal1_m785_tx	 954	//(internal1_m785_tx) tx - внутренний параметр
#define internal1_m784_tx	 BUFFER[2700]	//(internal1_m784_tx) tx - внутренний параметр
#define idinternal1_m784_tx	 955	//(internal1_m784_tx) tx - внутренний параметр
#define internal1_m740_tx	 BUFFER[2705]	//(internal1_m740_tx) tx - внутренний параметр
#define idinternal1_m740_tx	 956	//(internal1_m740_tx) tx - внутренний параметр
#define internal1_m729_tx	 BUFFER[2710]	//(internal1_m729_tx) tx - внутренний параметр
#define idinternal1_m729_tx	 957	//(internal1_m729_tx) tx - внутренний параметр
#define internal1_m735_tx	 BUFFER[2715]	//(internal1_m735_tx) tx - внутренний параметр
#define idinternal1_m735_tx	 958	//(internal1_m735_tx) tx - внутренний параметр
#define internal1_m766_tx	 BUFFER[2720]	//(internal1_m766_tx) tx - внутренний параметр
#define idinternal1_m766_tx	 959	//(internal1_m766_tx) tx - внутренний параметр
#define internal1_m783_tx	 BUFFER[2725]	//(internal1_m783_tx) tx - внутренний параметр
#define idinternal1_m783_tx	 960	//(internal1_m783_tx) tx - внутренний параметр
#define internal1_m756_tx	 BUFFER[2730]	//(internal1_m756_tx) tx - внутренний параметр
#define idinternal1_m756_tx	 961	//(internal1_m756_tx) tx - внутренний параметр
#define internal1_m387_tx	 BUFFER[2735]	//(internal1_m387_tx) tx - внутренний параметр
#define idinternal1_m387_tx	 962	//(internal1_m387_tx) tx - внутренний параметр
#define internal1_m386_tx	 BUFFER[2740]	//(internal1_m386_tx) tx - внутренний параметр
#define idinternal1_m386_tx	 963	//(internal1_m386_tx) tx - внутренний параметр
#define internal1_m385_tx	 BUFFER[2745]	//(internal1_m385_tx) tx - внутренний параметр
#define idinternal1_m385_tx	 964	//(internal1_m385_tx) tx - внутренний параметр
#define internal1_m384_tx	 BUFFER[2750]	//(internal1_m384_tx) tx - внутренний параметр
#define idinternal1_m384_tx	 965	//(internal1_m384_tx) tx - внутренний параметр
#define internal1_m755_tx	 BUFFER[2755]	//(internal1_m755_tx) tx - внутренний параметр
#define idinternal1_m755_tx	 966	//(internal1_m755_tx) tx - внутренний параметр
#define internal1_m750_tx	 BUFFER[2760]	//(internal1_m750_tx) tx - внутренний параметр
#define idinternal1_m750_tx	 967	//(internal1_m750_tx) tx - внутренний параметр
#define internal1_m759_tx	 BUFFER[2765]	//(internal1_m759_tx) tx - внутренний параметр
#define idinternal1_m759_tx	 968	//(internal1_m759_tx) tx - внутренний параметр
#define internal1_m764_tx	 BUFFER[2770]	//(internal1_m764_tx) tx - внутренний параметр
#define idinternal1_m764_tx	 969	//(internal1_m764_tx) tx - внутренний параметр
#define internal1_m520_tx	 BUFFER[2775]	//(internal1_m520_tx) tx - внутренний параметр
#define idinternal1_m520_tx	 970	//(internal1_m520_tx) tx - внутренний параметр
#define internal1_m519_tx	 BUFFER[2780]	//(internal1_m519_tx) tx - внутренний параметр
#define idinternal1_m519_tx	 971	//(internal1_m519_tx) tx - внутренний параметр
#define internal1_m518_tx	 BUFFER[2785]	//(internal1_m518_tx) tx - внутренний параметр
#define idinternal1_m518_tx	 972	//(internal1_m518_tx) tx - внутренний параметр
#define internal1_m514_tx	 BUFFER[2790]	//(internal1_m514_tx) tx - внутренний параметр
#define idinternal1_m514_tx	 973	//(internal1_m514_tx) tx - внутренний параметр
#define internal1_m491_tx	 BUFFER[2795]	//(internal1_m491_tx) tx - внутренний параметр
#define idinternal1_m491_tx	 974	//(internal1_m491_tx) tx - внутренний параметр
#define internal1_m490_tx	 BUFFER[2800]	//(internal1_m490_tx) tx - внутренний параметр
#define idinternal1_m490_tx	 975	//(internal1_m490_tx) tx - внутренний параметр
#define internal1_m489_tx	 BUFFER[2805]	//(internal1_m489_tx) tx - внутренний параметр
#define idinternal1_m489_tx	 976	//(internal1_m489_tx) tx - внутренний параметр
#define internal1_m492_tx	 BUFFER[2810]	//(internal1_m492_tx) tx - внутренний параметр
#define idinternal1_m492_tx	 977	//(internal1_m492_tx) tx - внутренний параметр
#define internal1_m2436_tx	 BUFFER[2815]	//(internal1_m2436_tx) tx - внутренний параметр
#define idinternal1_m2436_tx	 978	//(internal1_m2436_tx) tx - внутренний параметр
#define internal1_m2145_tx	 BUFFER[2820]	//(internal1_m2145_tx) tx - внутренний параметр
#define idinternal1_m2145_tx	 979	//(internal1_m2145_tx) tx - внутренний параметр
#define internal1_m2435_tx	 BUFFER[2825]	//(internal1_m2435_tx) tx - внутренний параметр
#define idinternal1_m2435_tx	 980	//(internal1_m2435_tx) tx - внутренний параметр
#define internal1_m2434_tx	 BUFFER[2830]	//(internal1_m2434_tx) tx - внутренний параметр
#define idinternal1_m2434_tx	 981	//(internal1_m2434_tx) tx - внутренний параметр
#define internal1_m2433_tx	 BUFFER[2835]	//(internal1_m2433_tx) tx - внутренний параметр
#define idinternal1_m2433_tx	 982	//(internal1_m2433_tx) tx - внутренний параметр
#define internal1_m102_tx	 BUFFER[2840]	//(internal1_m102_tx) tx - внутренний параметр
#define idinternal1_m102_tx	 983	//(internal1_m102_tx) tx - внутренний параметр
#define internal1_m1137_tx	 BUFFER[2845]	//(internal1_m1137_tx) tx - внутренний параметр
#define idinternal1_m1137_tx	 984	//(internal1_m1137_tx) tx - внутренний параметр
#define internal1_m2291_tx	 BUFFER[2850]	//(internal1_m2291_tx) tx - внутренний параметр
#define idinternal1_m2291_tx	 985	//(internal1_m2291_tx) tx - внутренний параметр
#define internal1_m2290_tx	 BUFFER[2855]	//(internal1_m2290_tx) tx - внутренний параметр
#define idinternal1_m2290_tx	 986	//(internal1_m2290_tx) tx - внутренний параметр
#define internal1_m2289_tx	 BUFFER[2860]	//(internal1_m2289_tx) tx - внутренний параметр
#define idinternal1_m2289_tx	 987	//(internal1_m2289_tx) tx - внутренний параметр
#define internal1_m1228_tx	 BUFFER[2865]	//(internal1_m1228_tx) tx - внутренний параметр
#define idinternal1_m1228_tx	 988	//(internal1_m1228_tx) tx - внутренний параметр
#define internal1_m1227_tx	 BUFFER[2870]	//(internal1_m1227_tx) tx - внутренний параметр
#define idinternal1_m1227_tx	 989	//(internal1_m1227_tx) tx - внутренний параметр
#define internal1_m1222_tx	 BUFFER[2875]	//(internal1_m1222_tx) tx - внутренний параметр
#define idinternal1_m1222_tx	 990	//(internal1_m1222_tx) tx - внутренний параметр
#define internal1_m1215_tx	 BUFFER[2880]	//(internal1_m1215_tx) tx - внутренний параметр
#define idinternal1_m1215_tx	 991	//(internal1_m1215_tx) tx - внутренний параметр
#define internal1_m1213_tx	 BUFFER[2885]	//(internal1_m1213_tx) tx - внутренний параметр
#define idinternal1_m1213_tx	 992	//(internal1_m1213_tx) tx - внутренний параметр
#define internal1_m1211_tx	 BUFFER[2890]	//(internal1_m1211_tx) tx - внутренний параметр
#define idinternal1_m1211_tx	 993	//(internal1_m1211_tx) tx - внутренний параметр
#define internal1_m1209_tx	 BUFFER[2895]	//(internal1_m1209_tx) tx - внутренний параметр
#define idinternal1_m1209_tx	 994	//(internal1_m1209_tx) tx - внутренний параметр
#define internal1_m1252_tx	 BUFFER[2900]	//(internal1_m1252_tx) tx - внутренний параметр
#define idinternal1_m1252_tx	 995	//(internal1_m1252_tx) tx - внутренний параметр
#define internal1_m1259_tx	 BUFFER[2905]	//(internal1_m1259_tx) tx - внутренний параметр
#define idinternal1_m1259_tx	 996	//(internal1_m1259_tx) tx - внутренний параметр
#define internal1_m1264_tx	 BUFFER[2910]	//(internal1_m1264_tx) tx - внутренний параметр
#define idinternal1_m1264_tx	 997	//(internal1_m1264_tx) tx - внутренний параметр
#define internal1_m1270_tx	 BUFFER[2915]	//(internal1_m1270_tx) tx - внутренний параметр
#define idinternal1_m1270_tx	 998	//(internal1_m1270_tx) tx - внутренний параметр
#define internal1_m1230_tx	 BUFFER[2920]	//(internal1_m1230_tx) tx - внутренний параметр
#define idinternal1_m1230_tx	 999	//(internal1_m1230_tx) tx - внутренний параметр
#define internal1_m1251_tx	 BUFFER[2925]	//(internal1_m1251_tx) tx - внутренний параметр
#define idinternal1_m1251_tx	 1000	//(internal1_m1251_tx) tx - внутренний параметр
#define internal1_m1265_tx	 BUFFER[2930]	//(internal1_m1265_tx) tx - внутренний параметр
#define idinternal1_m1265_tx	 1001	//(internal1_m1265_tx) tx - внутренний параметр
#define internal1_m469_tx	 BUFFER[2935]	//(internal1_m469_tx) tx - внутренний параметр
#define idinternal1_m469_tx	 1002	//(internal1_m469_tx) tx - внутренний параметр
#define internal1_m463_tx	 BUFFER[2940]	//(internal1_m463_tx) tx - внутренний параметр
#define idinternal1_m463_tx	 1003	//(internal1_m463_tx) tx - внутренний параметр
#define internal1_m465_tx	 BUFFER[2945]	//(internal1_m465_tx) tx - внутренний параметр
#define idinternal1_m465_tx	 1004	//(internal1_m465_tx) tx - внутренний параметр
#define internal1_m467_tx	 BUFFER[2950]	//(internal1_m467_tx) tx - внутренний параметр
#define idinternal1_m467_tx	 1005	//(internal1_m467_tx) tx - внутренний параметр
#define internal1_m474_tx	 BUFFER[2955]	//(internal1_m474_tx) tx - внутренний параметр
#define idinternal1_m474_tx	 1006	//(internal1_m474_tx) tx - внутренний параметр
#define internal1_m428_tx	 BUFFER[2960]	//(internal1_m428_tx) tx - внутренний параметр
#define idinternal1_m428_tx	 1007	//(internal1_m428_tx) tx - внутренний параметр
#define internal1_m426_tx	 BUFFER[2965]	//(internal1_m426_tx) tx - внутренний параметр
#define idinternal1_m426_tx	 1008	//(internal1_m426_tx) tx - внутренний параметр
#define internal1_m427_tx	 BUFFER[2970]	//(internal1_m427_tx) tx - внутренний параметр
#define idinternal1_m427_tx	 1009	//(internal1_m427_tx) tx - внутренний параметр
#define internal1_m420_tx	 BUFFER[2975]	//(internal1_m420_tx) tx - внутренний параметр
#define idinternal1_m420_tx	 1010	//(internal1_m420_tx) tx - внутренний параметр
#define internal1_m882_tx	 BUFFER[2980]	//(internal1_m882_tx) tx - внутренний параметр
#define idinternal1_m882_tx	 1011	//(internal1_m882_tx) tx - внутренний параметр
#define internal1_m881_tx	 BUFFER[2985]	//(internal1_m881_tx) tx - внутренний параметр
#define idinternal1_m881_tx	 1012	//(internal1_m881_tx) tx - внутренний параметр
#define internal1_m880_tx	 BUFFER[2990]	//(internal1_m880_tx) tx - внутренний параметр
#define idinternal1_m880_tx	 1013	//(internal1_m880_tx) tx - внутренний параметр
#define internal1_m876_tx	 BUFFER[2995]	//(internal1_m876_tx) tx - внутренний параметр
#define idinternal1_m876_tx	 1014	//(internal1_m876_tx) tx - внутренний параметр
#define internal1_m1316_tx	 BUFFER[3000]	//(internal1_m1316_tx) tx - внутренний параметр
#define idinternal1_m1316_tx	 1015	//(internal1_m1316_tx) tx - внутренний параметр
#define internal1_m1315_tx	 BUFFER[3005]	//(internal1_m1315_tx) tx - внутренний параметр
#define idinternal1_m1315_tx	 1016	//(internal1_m1315_tx) tx - внутренний параметр
#define internal1_m1314_tx	 BUFFER[3010]	//(internal1_m1314_tx) tx - внутренний параметр
#define idinternal1_m1314_tx	 1017	//(internal1_m1314_tx) tx - внутренний параметр
#define internal1_m1527_tx	 BUFFER[3015]	//(internal1_m1527_tx) tx - внутренний параметр
#define idinternal1_m1527_tx	 1018	//(internal1_m1527_tx) tx - внутренний параметр
#define internal1_m1540_tx	 BUFFER[3020]	//(internal1_m1540_tx) tx - внутренний параметр
#define idinternal1_m1540_tx	 1019	//(internal1_m1540_tx) tx - внутренний параметр
#define internal1_m1539_tx	 BUFFER[3025]	//(internal1_m1539_tx) tx - внутренний параметр
#define idinternal1_m1539_tx	 1020	//(internal1_m1539_tx) tx - внутренний параметр
#define internal1_m1538_tx	 BUFFER[3030]	//(internal1_m1538_tx) tx - внутренний параметр
#define idinternal1_m1538_tx	 1021	//(internal1_m1538_tx) tx - внутренний параметр
#define internal1_m1529_tx	 BUFFER[3035]	//(internal1_m1529_tx) tx - внутренний параметр
#define idinternal1_m1529_tx	 1022	//(internal1_m1529_tx) tx - внутренний параметр
#define internal1_m2263_tx	 BUFFER[3040]	//(internal1_m2263_tx) tx - внутренний параметр
#define idinternal1_m2263_tx	 1023	//(internal1_m2263_tx) tx - внутренний параметр
#define internal1_m2246_tx	 BUFFER[3045]	//(internal1_m2246_tx) tx - внутренний параметр
#define idinternal1_m2246_tx	 1024	//(internal1_m2246_tx) tx - внутренний параметр
#define internal1_m2223_tx	 BUFFER[3050]	//(internal1_m2223_tx) tx - внутренний параметр
#define idinternal1_m2223_tx	 1025	//(internal1_m2223_tx) tx - внутренний параметр
#define internal1_m1537_tx	 BUFFER[3055]	//(internal1_m1537_tx) tx - внутренний параметр
#define idinternal1_m1537_tx	 1026	//(internal1_m1537_tx) tx - внутренний параметр
#define internal1_m1518_tx	 BUFFER[3060]	//(internal1_m1518_tx) tx - внутренний параметр
#define idinternal1_m1518_tx	 1027	//(internal1_m1518_tx) tx - внутренний параметр
#define internal1_m1517_tx	 BUFFER[3065]	//(internal1_m1517_tx) tx - внутренний параметр
#define idinternal1_m1517_tx	 1028	//(internal1_m1517_tx) tx - внутренний параметр
#define internal1_m1514_tx	 BUFFER[3070]	//(internal1_m1514_tx) tx - внутренний параметр
#define idinternal1_m1514_tx	 1029	//(internal1_m1514_tx) tx - внутренний параметр
#define internal1_m1536_tx	 BUFFER[3075]	//(internal1_m1536_tx) tx - внутренний параметр
#define idinternal1_m1536_tx	 1030	//(internal1_m1536_tx) tx - внутренний параметр
#define internal1_m1502_tx	 BUFFER[3080]	//(internal1_m1502_tx) tx - внутренний параметр
#define idinternal1_m1502_tx	 1031	//(internal1_m1502_tx) tx - внутренний параметр
#define internal1_m1504_tx	 BUFFER[3085]	//(internal1_m1504_tx) tx - внутренний параметр
#define idinternal1_m1504_tx	 1032	//(internal1_m1504_tx) tx - внутренний параметр
#define internal1_m1501_tx	 BUFFER[3090]	//(internal1_m1501_tx) tx - внутренний параметр
#define idinternal1_m1501_tx	 1033	//(internal1_m1501_tx) tx - внутренний параметр
#define internal1_m1474_tx	 BUFFER[3095]	//(internal1_m1474_tx) tx - внутренний параметр
#define idinternal1_m1474_tx	 1034	//(internal1_m1474_tx) tx - внутренний параметр
#define internal1_m1473_tx	 BUFFER[3100]	//(internal1_m1473_tx) tx - внутренний параметр
#define idinternal1_m1473_tx	 1035	//(internal1_m1473_tx) tx - внутренний параметр
#define internal1_m1482_tx	 BUFFER[3105]	//(internal1_m1482_tx) tx - внутренний параметр
#define idinternal1_m1482_tx	 1036	//(internal1_m1482_tx) tx - внутренний параметр
#define internal1_m1486_tx	 BUFFER[3110]	//(internal1_m1486_tx) tx - внутренний параметр
#define idinternal1_m1486_tx	 1037	//(internal1_m1486_tx) tx - внутренний параметр
#define internal1_m975_tx	 BUFFER[3115]	//(internal1_m975_tx) tx - внутренний параметр
#define idinternal1_m975_tx	 1038	//(internal1_m975_tx) tx - внутренний параметр
#define internal1_m978_tx	 BUFFER[3120]	//(internal1_m978_tx) tx - внутренний параметр
#define idinternal1_m978_tx	 1039	//(internal1_m978_tx) tx - внутренний параметр
#define internal1_m2214_tx	 BUFFER[3125]	//(internal1_m2214_tx) tx - внутренний параметр
#define idinternal1_m2214_tx	 1040	//(internal1_m2214_tx) tx - внутренний параметр
#define internal1_m968_tx	 BUFFER[3130]	//(internal1_m968_tx) tx - внутренний параметр
#define idinternal1_m968_tx	 1041	//(internal1_m968_tx) tx - внутренний параметр
#define internal1_m966_tx	 BUFFER[3135]	//(internal1_m966_tx) tx - внутренний параметр
#define idinternal1_m966_tx	 1042	//(internal1_m966_tx) tx - внутренний параметр
#define internal1_m974_tx	 BUFFER[3140]	//(internal1_m974_tx) tx - внутренний параметр
#define idinternal1_m974_tx	 1043	//(internal1_m974_tx) tx - внутренний параметр
#define internal1_m958_tx	 BUFFER[3145]	//(internal1_m958_tx) tx - внутренний параметр
#define idinternal1_m958_tx	 1044	//(internal1_m958_tx) tx - внутренний параметр
#define internal1_m955_tx	 BUFFER[3150]	//(internal1_m955_tx) tx - внутренний параметр
#define idinternal1_m955_tx	 1045	//(internal1_m955_tx) tx - внутренний параметр
#define internal1_m952_tx	 BUFFER[3155]	//(internal1_m952_tx) tx - внутренний параметр
#define idinternal1_m952_tx	 1046	//(internal1_m952_tx) tx - внутренний параметр
#define internal1_m973_tx	 BUFFER[3160]	//(internal1_m973_tx) tx - внутренний параметр
#define idinternal1_m973_tx	 1047	//(internal1_m973_tx) tx - внутренний параметр
#define internal1_m938_tx	 BUFFER[3165]	//(internal1_m938_tx) tx - внутренний параметр
#define idinternal1_m938_tx	 1048	//(internal1_m938_tx) tx - внутренний параметр
#define internal1_m939_tx	 BUFFER[3170]	//(internal1_m939_tx) tx - внутренний параметр
#define idinternal1_m939_tx	 1049	//(internal1_m939_tx) tx - внутренний параметр
#define internal1_m941_tx	 BUFFER[3175]	//(internal1_m941_tx) tx - внутренний параметр
#define idinternal1_m941_tx	 1050	//(internal1_m941_tx) tx - внутренний параметр
#define internal1_m627_tx	 BUFFER[3180]	//(internal1_m627_tx) tx - внутренний параметр
#define idinternal1_m627_tx	 1051	//(internal1_m627_tx) tx - внутренний параметр
#define internal1_m629_tx	 BUFFER[3185]	//(internal1_m629_tx) tx - внутренний параметр
#define idinternal1_m629_tx	 1052	//(internal1_m629_tx) tx - внутренний параметр
#define internal1_m628_tx	 BUFFER[3190]	//(internal1_m628_tx) tx - внутренний параметр
#define idinternal1_m628_tx	 1053	//(internal1_m628_tx) tx - внутренний параметр
#define internal1_m615_tx	 BUFFER[3195]	//(internal1_m615_tx) tx - внутренний параметр
#define idinternal1_m615_tx	 1054	//(internal1_m615_tx) tx - внутренний параметр
#define internal1_m614_tx	 BUFFER[3200]	//(internal1_m614_tx) tx - внутренний параметр
#define idinternal1_m614_tx	 1055	//(internal1_m614_tx) tx - внутренний параметр
#define internal1_m611_tx	 BUFFER[3205]	//(internal1_m611_tx) tx - внутренний параметр
#define idinternal1_m611_tx	 1056	//(internal1_m611_tx) tx - внутренний параметр
#define internal1_m624_tx	 BUFFER[3210]	//(internal1_m624_tx) tx - внутренний параметр
#define idinternal1_m624_tx	 1057	//(internal1_m624_tx) tx - внутренний параметр
#define internal1_m601_tx	 BUFFER[3215]	//(internal1_m601_tx) tx - внутренний параметр
#define idinternal1_m601_tx	 1058	//(internal1_m601_tx) tx - внутренний параметр
#define internal1_m600_tx	 BUFFER[3220]	//(internal1_m600_tx) tx - внутренний параметр
#define idinternal1_m600_tx	 1059	//(internal1_m600_tx) tx - внутренний параметр
#define internal1_m596_tx	 BUFFER[3225]	//(internal1_m596_tx) tx - внутренний параметр
#define idinternal1_m596_tx	 1060	//(internal1_m596_tx) tx - внутренний параметр
#define internal1_m625_tx	 BUFFER[3230]	//(internal1_m625_tx) tx - внутренний параметр
#define idinternal1_m625_tx	 1061	//(internal1_m625_tx) tx - внутренний параметр
#define internal1_m587_tx	 BUFFER[3235]	//(internal1_m587_tx) tx - внутренний параметр
#define idinternal1_m587_tx	 1062	//(internal1_m587_tx) tx - внутренний параметр
#define internal1_m583_tx	 BUFFER[3240]	//(internal1_m583_tx) tx - внутренний параметр
#define idinternal1_m583_tx	 1063	//(internal1_m583_tx) tx - внутренний параметр
#define internal1_m585_tx	 BUFFER[3245]	//(internal1_m585_tx) tx - внутренний параметр
#define idinternal1_m585_tx	 1064	//(internal1_m585_tx) tx - внутренний параметр
#define internal1_m563_tx	 BUFFER[3250]	//(internal1_m563_tx) tx - внутренний параметр
#define idinternal1_m563_tx	 1065	//(internal1_m563_tx) tx - внутренний параметр
#define internal1_m564_tx	 BUFFER[3255]	//(internal1_m564_tx) tx - внутренний параметр
#define idinternal1_m564_tx	 1066	//(internal1_m564_tx) tx - внутренний параметр
#define internal1_m565_tx	 BUFFER[3260]	//(internal1_m565_tx) tx - внутренний параметр
#define idinternal1_m565_tx	 1067	//(internal1_m565_tx) tx - внутренний параметр
#define internal1_m570_tx	 BUFFER[3265]	//(internal1_m570_tx) tx - внутренний параметр
#define idinternal1_m570_tx	 1068	//(internal1_m570_tx) tx - внутренний параметр
#define internal1_m2274_tx	 BUFFER[3270]	//(internal1_m2274_tx) tx - внутренний параметр
#define idinternal1_m2274_tx	 1069	//(internal1_m2274_tx) tx - внутренний параметр
#define internal1_m2275_tx	 BUFFER[3275]	//(internal1_m2275_tx) tx - внутренний параметр
#define idinternal1_m2275_tx	 1070	//(internal1_m2275_tx) tx - внутренний параметр
#define internal1_m2276_tx	 BUFFER[3280]	//(internal1_m2276_tx) tx - внутренний параметр
#define idinternal1_m2276_tx	 1071	//(internal1_m2276_tx) tx - внутренний параметр
#define internal1_m1745_tx	 BUFFER[3285]	//(internal1_m1745_tx) tx - внутренний параметр
#define idinternal1_m1745_tx	 1072	//(internal1_m1745_tx) tx - внутренний параметр
#define internal1_m1744_tx	 BUFFER[3290]	//(internal1_m1744_tx) tx - внутренний параметр
#define idinternal1_m1744_tx	 1073	//(internal1_m1744_tx) tx - внутренний параметр
#define internal1_m1739_tx	 BUFFER[3295]	//(internal1_m1739_tx) tx - внутренний параметр
#define idinternal1_m1739_tx	 1074	//(internal1_m1739_tx) tx - внутренний параметр
#define internal1_m1730_tx	 BUFFER[3300]	//(internal1_m1730_tx) tx - внутренний параметр
#define idinternal1_m1730_tx	 1075	//(internal1_m1730_tx) tx - внутренний параметр
#define internal1_m1728_tx	 BUFFER[3305]	//(internal1_m1728_tx) tx - внутренний параметр
#define idinternal1_m1728_tx	 1076	//(internal1_m1728_tx) tx - внутренний параметр
#define internal1_m1726_tx	 BUFFER[3310]	//(internal1_m1726_tx) tx - внутренний параметр
#define idinternal1_m1726_tx	 1077	//(internal1_m1726_tx) tx - внутренний параметр
#define internal1_m1725_tx	 BUFFER[3315]	//(internal1_m1725_tx) tx - внутренний параметр
#define idinternal1_m1725_tx	 1078	//(internal1_m1725_tx) tx - внутренний параметр
#define internal1_m1766_tx	 BUFFER[3320]	//(internal1_m1766_tx) tx - внутренний параметр
#define idinternal1_m1766_tx	 1079	//(internal1_m1766_tx) tx - внутренний параметр
#define internal1_m1774_tx	 BUFFER[3325]	//(internal1_m1774_tx) tx - внутренний параметр
#define idinternal1_m1774_tx	 1080	//(internal1_m1774_tx) tx - внутренний параметр
#define internal1_m1781_tx	 BUFFER[3330]	//(internal1_m1781_tx) tx - внутренний параметр
#define idinternal1_m1781_tx	 1081	//(internal1_m1781_tx) tx - внутренний параметр
#define internal1_m1782_tx	 BUFFER[3335]	//(internal1_m1782_tx) tx - внутренний параметр
#define idinternal1_m1782_tx	 1082	//(internal1_m1782_tx) tx - внутренний параметр
#define internal1_m1772_tx	 BUFFER[3340]	//(internal1_m1772_tx) tx - внутренний параметр
#define idinternal1_m1772_tx	 1083	//(internal1_m1772_tx) tx - внутренний параметр
#define internal1_m1747_tx	 BUFFER[3345]	//(internal1_m1747_tx) tx - внутренний параметр
#define idinternal1_m1747_tx	 1084	//(internal1_m1747_tx) tx - внутренний параметр
#define internal1_m1761_tx	 BUFFER[3350]	//(internal1_m1761_tx) tx - внутренний параметр
#define idinternal1_m1761_tx	 1085	//(internal1_m1761_tx) tx - внутренний параметр
#define internal1_m446_tx	 BUFFER[3355]	//(internal1_m446_tx) tx - внутренний параметр
#define idinternal1_m446_tx	 1086	//(internal1_m446_tx) tx - внутренний параметр
#define internal1_m437_tx	 BUFFER[3360]	//(internal1_m437_tx) tx - внутренний параметр
#define idinternal1_m437_tx	 1087	//(internal1_m437_tx) tx - внутренний параметр
#define internal1_m438_tx	 BUFFER[3365]	//(internal1_m438_tx) tx - внутренний параметр
#define idinternal1_m438_tx	 1088	//(internal1_m438_tx) tx - внутренний параметр
#define internal1_m440_tx	 BUFFER[3370]	//(internal1_m440_tx) tx - внутренний параметр
#define idinternal1_m440_tx	 1089	//(internal1_m440_tx) tx - внутренний параметр
#define internal1_m454_tx	 BUFFER[3375]	//(internal1_m454_tx) tx - внутренний параметр
#define idinternal1_m454_tx	 1090	//(internal1_m454_tx) tx - внутренний параметр
#define internal1_m404_tx	 BUFFER[3380]	//(internal1_m404_tx) tx - внутренний параметр
#define idinternal1_m404_tx	 1091	//(internal1_m404_tx) tx - внутренний параметр
#define internal1_m401_tx	 BUFFER[3385]	//(internal1_m401_tx) tx - внутренний параметр
#define idinternal1_m401_tx	 1092	//(internal1_m401_tx) tx - внутренний параметр
#define internal1_m400_tx	 BUFFER[3390]	//(internal1_m400_tx) tx - внутренний параметр
#define idinternal1_m400_tx	 1093	//(internal1_m400_tx) tx - внутренний параметр
#define internal1_m399_tx	 BUFFER[3395]	//(internal1_m399_tx) tx - внутренний параметр
#define idinternal1_m399_tx	 1094	//(internal1_m399_tx) tx - внутренний параметр
#define internal1_m859_tx	 BUFFER[3400]	//(internal1_m859_tx) tx - внутренний параметр
#define idinternal1_m859_tx	 1095	//(internal1_m859_tx) tx - внутренний параметр
#define internal1_m855_tx	 BUFFER[3405]	//(internal1_m855_tx) tx - внутренний параметр
#define idinternal1_m855_tx	 1096	//(internal1_m855_tx) tx - внутренний параметр
#define internal1_m854_tx	 BUFFER[3410]	//(internal1_m854_tx) tx - внутренний параметр
#define idinternal1_m854_tx	 1097	//(internal1_m854_tx) tx - внутренний параметр
#define internal1_m853_tx	 BUFFER[3415]	//(internal1_m853_tx) tx - внутренний параметр
#define idinternal1_m853_tx	 1098	//(internal1_m853_tx) tx - внутренний параметр
#define internal1_m1297_tx	 BUFFER[3420]	//(internal1_m1297_tx) tx - внутренний параметр
#define idinternal1_m1297_tx	 1099	//(internal1_m1297_tx) tx - внутренний параметр
#define internal1_m1294_tx	 BUFFER[3425]	//(internal1_m1294_tx) tx - внутренний параметр
#define idinternal1_m1294_tx	 1100	//(internal1_m1294_tx) tx - внутренний параметр
#define internal1_m1293_tx	 BUFFER[3430]	//(internal1_m1293_tx) tx - внутренний параметр
#define idinternal1_m1293_tx	 1101	//(internal1_m1293_tx) tx - внутренний параметр
#define internal1_m1076_tx	 BUFFER[3435]	//(internal1_m1076_tx) tx - внутренний параметр
#define idinternal1_m1076_tx	 1102	//(internal1_m1076_tx) tx - внутренний параметр
#define internal1_m2229_tx	 BUFFER[3440]	//(internal1_m2229_tx) tx - внутренний параметр
#define idinternal1_m2229_tx	 1103	//(internal1_m2229_tx) tx - внутренний параметр
#define internal1_m1087_tx	 BUFFER[3445]	//(internal1_m1087_tx) tx - внутренний параметр
#define idinternal1_m1087_tx	 1104	//(internal1_m1087_tx) tx - внутренний параметр
#define internal1_m1089_tx	 BUFFER[3450]	//(internal1_m1089_tx) tx - внутренний параметр
#define idinternal1_m1089_tx	 1105	//(internal1_m1089_tx) tx - внутренний параметр
#define internal1_m1088_tx	 BUFFER[3455]	//(internal1_m1088_tx) tx - внутренний параметр
#define idinternal1_m1088_tx	 1106	//(internal1_m1088_tx) tx - внутренний параметр
#define internal1_m2231_tx	 BUFFER[3460]	//(internal1_m2231_tx) tx - внутренний параметр
#define idinternal1_m2231_tx	 1107	//(internal1_m2231_tx) tx - внутренний параметр
#define internal1_m1078_tx	 BUFFER[3465]	//(internal1_m1078_tx) tx - внутренний параметр
#define idinternal1_m1078_tx	 1108	//(internal1_m1078_tx) tx - внутренний параметр
#define internal1_m2228_tx	 BUFFER[3470]	//(internal1_m2228_tx) tx - внутренний параметр
#define idinternal1_m2228_tx	 1109	//(internal1_m2228_tx) tx - внутренний параметр
#define internal1_m1086_tx	 BUFFER[3475]	//(internal1_m1086_tx) tx - внутренний параметр
#define idinternal1_m1086_tx	 1110	//(internal1_m1086_tx) tx - внутренний параметр
#define internal1_m1065_tx	 BUFFER[3480]	//(internal1_m1065_tx) tx - внутренний параметр
#define idinternal1_m1065_tx	 1111	//(internal1_m1065_tx) tx - внутренний параметр
#define internal1_m1064_tx	 BUFFER[3485]	//(internal1_m1064_tx) tx - внутренний параметр
#define idinternal1_m1064_tx	 1112	//(internal1_m1064_tx) tx - внутренний параметр
#define internal1_m1063_tx	 BUFFER[3490]	//(internal1_m1063_tx) tx - внутренний параметр
#define idinternal1_m1063_tx	 1113	//(internal1_m1063_tx) tx - внутренний параметр
#define internal1_m1085_tx	 BUFFER[3495]	//(internal1_m1085_tx) tx - внутренний параметр
#define idinternal1_m1085_tx	 1114	//(internal1_m1085_tx) tx - внутренний параметр
#define internal1_m1053_tx	 BUFFER[3500]	//(internal1_m1053_tx) tx - внутренний параметр
#define idinternal1_m1053_tx	 1115	//(internal1_m1053_tx) tx - внутренний параметр
#define internal1_m1051_tx	 BUFFER[3505]	//(internal1_m1051_tx) tx - внутренний параметр
#define idinternal1_m1051_tx	 1116	//(internal1_m1051_tx) tx - внутренний параметр
#define internal1_m1050_tx	 BUFFER[3510]	//(internal1_m1050_tx) tx - внутренний параметр
#define idinternal1_m1050_tx	 1117	//(internal1_m1050_tx) tx - внутренний параметр
#define internal1_m1029_tx	 BUFFER[3515]	//(internal1_m1029_tx) tx - внутренний параметр
#define idinternal1_m1029_tx	 1118	//(internal1_m1029_tx) tx - внутренний параметр
#define internal1_m1028_tx	 BUFFER[3520]	//(internal1_m1028_tx) tx - внутренний параметр
#define idinternal1_m1028_tx	 1119	//(internal1_m1028_tx) tx - внутренний параметр
#define internal1_m1018_tx	 BUFFER[3525]	//(internal1_m1018_tx) tx - внутренний параметр
#define idinternal1_m1018_tx	 1120	//(internal1_m1018_tx) tx - внутренний параметр
#define internal1_m1035_tx	 BUFFER[3530]	//(internal1_m1035_tx) tx - внутренний параметр
#define idinternal1_m1035_tx	 1121	//(internal1_m1035_tx) tx - внутренний параметр
#define internal1_m1432_tx	 BUFFER[3535]	//(internal1_m1432_tx) tx - внутренний параметр
#define idinternal1_m1432_tx	 1122	//(internal1_m1432_tx) tx - внутренний параметр
#define internal1_m1431_tx	 BUFFER[3540]	//(internal1_m1431_tx) tx - внутренний параметр
#define idinternal1_m1431_tx	 1123	//(internal1_m1431_tx) tx - внутренний параметр
#define internal1_m2181_tx	 BUFFER[3545]	//(internal1_m2181_tx) tx - внутренний параметр
#define idinternal1_m2181_tx	 1124	//(internal1_m2181_tx) tx - внутренний параметр
#define internal1_m1423_tx	 BUFFER[3550]	//(internal1_m1423_tx) tx - внутренний параметр
#define idinternal1_m1423_tx	 1125	//(internal1_m1423_tx) tx - внутренний параметр
#define internal1_m1424_tx	 BUFFER[3555]	//(internal1_m1424_tx) tx - внутренний параметр
#define idinternal1_m1424_tx	 1126	//(internal1_m1424_tx) tx - внутренний параметр
#define internal1_m1430_tx	 BUFFER[3560]	//(internal1_m1430_tx) tx - внутренний параметр
#define idinternal1_m1430_tx	 1127	//(internal1_m1430_tx) tx - внутренний параметр
#define internal1_m1412_tx	 BUFFER[3565]	//(internal1_m1412_tx) tx - внутренний параметр
#define idinternal1_m1412_tx	 1128	//(internal1_m1412_tx) tx - внутренний параметр
#define internal1_m1411_tx	 BUFFER[3570]	//(internal1_m1411_tx) tx - внутренний параметр
#define idinternal1_m1411_tx	 1129	//(internal1_m1411_tx) tx - внутренний параметр
#define internal1_m1408_tx	 BUFFER[3575]	//(internal1_m1408_tx) tx - внутренний параметр
#define idinternal1_m1408_tx	 1130	//(internal1_m1408_tx) tx - внутренний параметр
#define internal1_m1429_tx	 BUFFER[3580]	//(internal1_m1429_tx) tx - внутренний параметр
#define idinternal1_m1429_tx	 1131	//(internal1_m1429_tx) tx - внутренний параметр
#define internal1_m1394_tx	 BUFFER[3585]	//(internal1_m1394_tx) tx - внутренний параметр
#define idinternal1_m1394_tx	 1132	//(internal1_m1394_tx) tx - внутренний параметр
#define internal1_m1393_tx	 BUFFER[3590]	//(internal1_m1393_tx) tx - внутренний параметр
#define idinternal1_m1393_tx	 1133	//(internal1_m1393_tx) tx - внутренний параметр
#define internal1_m1396_tx	 BUFFER[3595]	//(internal1_m1396_tx) tx - внутренний параметр
#define idinternal1_m1396_tx	 1134	//(internal1_m1396_tx) tx - внутренний параметр
#define internal1_m244_tx	 BUFFER[3600]	//(internal1_m244_tx) tx - внутренний параметр
#define idinternal1_m244_tx	 1135	//(internal1_m244_tx) tx - внутренний параметр
#define internal1_m259_tx	 BUFFER[3605]	//(internal1_m259_tx) tx - внутренний параметр
#define idinternal1_m259_tx	 1136	//(internal1_m259_tx) tx - внутренний параметр
#define internal1_m266_tx	 BUFFER[3610]	//(internal1_m266_tx) tx - внутренний параметр
#define idinternal1_m266_tx	 1137	//(internal1_m266_tx) tx - внутренний параметр
#define internal1_m265_tx	 BUFFER[3615]	//(internal1_m265_tx) tx - внутренний параметр
#define idinternal1_m265_tx	 1138	//(internal1_m265_tx) tx - внутренний параметр
#define internal1_m252_tx	 BUFFER[3620]	//(internal1_m252_tx) tx - внутренний параметр
#define idinternal1_m252_tx	 1139	//(internal1_m252_tx) tx - внутренний параметр
#define internal1_m247_tx	 BUFFER[3625]	//(internal1_m247_tx) tx - внутренний параметр
#define idinternal1_m247_tx	 1140	//(internal1_m247_tx) tx - внутренний параметр
#define internal1_m263_tx	 BUFFER[3630]	//(internal1_m263_tx) tx - внутренний параметр
#define idinternal1_m263_tx	 1141	//(internal1_m263_tx) tx - внутренний параметр
#define internal1_m235_tx	 BUFFER[3635]	//(internal1_m235_tx) tx - внутренний параметр
#define idinternal1_m235_tx	 1142	//(internal1_m235_tx) tx - внутренний параметр
#define internal1_m234_tx	 BUFFER[3640]	//(internal1_m234_tx) tx - внутренний параметр
#define idinternal1_m234_tx	 1143	//(internal1_m234_tx) tx - внутренний параметр
#define internal1_m230_tx	 BUFFER[3645]	//(internal1_m230_tx) tx - внутренний параметр
#define idinternal1_m230_tx	 1144	//(internal1_m230_tx) tx - внутренний параметр
#define internal1_m262_tx	 BUFFER[3650]	//(internal1_m262_tx) tx - внутренний параметр
#define idinternal1_m262_tx	 1145	//(internal1_m262_tx) tx - внутренний параметр
#define internal1_m219_tx	 BUFFER[3655]	//(internal1_m219_tx) tx - внутренний параметр
#define idinternal1_m219_tx	 1146	//(internal1_m219_tx) tx - внутренний параметр
#define internal1_m221_tx	 BUFFER[3660]	//(internal1_m221_tx) tx - внутренний параметр
#define idinternal1_m221_tx	 1147	//(internal1_m221_tx) tx - внутренний параметр
#define internal1_m218_tx	 BUFFER[3665]	//(internal1_m218_tx) tx - внутренний параметр
#define idinternal1_m218_tx	 1148	//(internal1_m218_tx) tx - внутренний параметр
#define internal1_m197_tx	 BUFFER[3670]	//(internal1_m197_tx) tx - внутренний параметр
#define idinternal1_m197_tx	 1149	//(internal1_m197_tx) tx - внутренний параметр
#define internal1_m196_tx	 BUFFER[3675]	//(internal1_m196_tx) tx - внутренний параметр
#define idinternal1_m196_tx	 1150	//(internal1_m196_tx) tx - внутренний параметр
#define internal1_m195_tx	 BUFFER[3680]	//(internal1_m195_tx) tx - внутренний параметр
#define idinternal1_m195_tx	 1151	//(internal1_m195_tx) tx - внутренний параметр
#define internal1_m203_tx	 BUFFER[3685]	//(internal1_m203_tx) tx - внутренний параметр
#define idinternal1_m203_tx	 1152	//(internal1_m203_tx) tx - внутренний параметр
#define internal1_m1375_tx	 BUFFER[3690]	//(internal1_m1375_tx) tx - внутренний параметр
#define idinternal1_m1375_tx	 1153	//(internal1_m1375_tx) tx - внутренний параметр
#define internal1_m1357_tx	 BUFFER[3695]	//(internal1_m1357_tx) tx - внутренний параметр
#define idinternal1_m1357_tx	 1154	//(internal1_m1357_tx) tx - внутренний параметр
#define internal1_m1362_tx	 BUFFER[3700]	//(internal1_m1362_tx) tx - внутренний параметр
#define idinternal1_m1362_tx	 1155	//(internal1_m1362_tx) tx - внутренний параметр
#define internal1_m1378_tx	 BUFFER[3705]	//(internal1_m1378_tx) tx - внутренний параметр
#define idinternal1_m1378_tx	 1156	//(internal1_m1378_tx) tx - внутренний параметр
#define internal1_m918_tx	 BUFFER[3710]	//(internal1_m918_tx) tx - внутренний параметр
#define idinternal1_m918_tx	 1157	//(internal1_m918_tx) tx - внутренний параметр
#define internal1_m923_tx	 BUFFER[3715]	//(internal1_m923_tx) tx - внутренний параметр
#define idinternal1_m923_tx	 1158	//(internal1_m923_tx) tx - внутренний параметр
#define internal1_m913_tx	 BUFFER[3720]	//(internal1_m913_tx) tx - внутренний параметр
#define idinternal1_m913_tx	 1159	//(internal1_m913_tx) tx - внутренний параметр
#define internal1_m914_tx	 BUFFER[3725]	//(internal1_m914_tx) tx - внутренний параметр
#define idinternal1_m914_tx	 1160	//(internal1_m914_tx) tx - внутренний параметр
#define internal1_m1866_q0	 BUFFER[3730]	//(internal1_m1866_q0) q0 - внутренний параметр
#define idinternal1_m1866_q0	 1161	//(internal1_m1866_q0) q0 - внутренний параметр
#define internal1_m2316_q0	 BUFFER[3732]	//(internal1_m2316_q0) q0 - внутренний параметр
#define idinternal1_m2316_q0	 1162	//(internal1_m2316_q0) q0 - внутренний параметр
#define internal1_m2300_q0	 BUFFER[3734]	//(internal1_m2300_q0) q0 - внутренний параметр
#define idinternal1_m2300_q0	 1163	//(internal1_m2300_q0) q0 - внутренний параметр
#define internal1_m2347_q0	 BUFFER[3736]	//(internal1_m2347_q0) q0 - внутренний параметр
#define idinternal1_m2347_q0	 1164	//(internal1_m2347_q0) q0 - внутренний параметр
#define internal1_m2331_q0	 BUFFER[3738]	//(internal1_m2331_q0) q0 - внутренний параметр
#define idinternal1_m2331_q0	 1165	//(internal1_m2331_q0) q0 - внутренний параметр
#define internal1_m2322_q0	 BUFFER[3740]	//(internal1_m2322_q0) q0 - внутренний параметр
#define idinternal1_m2322_q0	 1166	//(internal1_m2322_q0) q0 - внутренний параметр
#define internal1_m2303_q0	 BUFFER[3742]	//(internal1_m2303_q0) q0 - внутренний параметр
#define idinternal1_m2303_q0	 1167	//(internal1_m2303_q0) q0 - внутренний параметр
#define internal1_m2320_q0	 BUFFER[3744]	//(internal1_m2320_q0) q0 - внутренний параметр
#define idinternal1_m2320_q0	 1168	//(internal1_m2320_q0) q0 - внутренний параметр
#define internal1_m2301_q0	 BUFFER[3746]	//(internal1_m2301_q0) q0 - внутренний параметр
#define idinternal1_m2301_q0	 1169	//(internal1_m2301_q0) q0 - внутренний параметр
#define internal1_m2299_q0	 BUFFER[3748]	//(internal1_m2299_q0) q0 - внутренний параметр
#define idinternal1_m2299_q0	 1170	//(internal1_m2299_q0) q0 - внутренний параметр
#define internal1_m2298_q0	 BUFFER[3750]	//(internal1_m2298_q0) q0 - внутренний параметр
#define idinternal1_m2298_q0	 1171	//(internal1_m2298_q0) q0 - внутренний параметр
#define internal1_m2312_q0	 BUFFER[3752]	//(internal1_m2312_q0) q0 - внутренний параметр
#define idinternal1_m2312_q0	 1172	//(internal1_m2312_q0) q0 - внутренний параметр
#define internal1_m2310_q0	 BUFFER[3754]	//(internal1_m2310_q0) q0 - внутренний параметр
#define idinternal1_m2310_q0	 1173	//(internal1_m2310_q0) q0 - внутренний параметр
#define internal1_m2318_q0	 BUFFER[3756]	//(internal1_m2318_q0) q0 - внутренний параметр
#define idinternal1_m2318_q0	 1174	//(internal1_m2318_q0) q0 - внутренний параметр
#define internal1_m2314_q0	 BUFFER[3758]	//(internal1_m2314_q0) q0 - внутренний параметр
#define idinternal1_m2314_q0	 1175	//(internal1_m2314_q0) q0 - внутренний параметр
#define internal1_m2353_q0	 BUFFER[3760]	//(internal1_m2353_q0) q0 - внутренний параметр
#define idinternal1_m2353_q0	 1176	//(internal1_m2353_q0) q0 - внутренний параметр
#define internal1_m2334_q0	 BUFFER[3762]	//(internal1_m2334_q0) q0 - внутренний параметр
#define idinternal1_m2334_q0	 1177	//(internal1_m2334_q0) q0 - внутренний параметр
#define internal1_m2351_q0	 BUFFER[3764]	//(internal1_m2351_q0) q0 - внутренний параметр
#define idinternal1_m2351_q0	 1178	//(internal1_m2351_q0) q0 - внутренний параметр
#define internal1_m2333_q0	 BUFFER[3766]	//(internal1_m2333_q0) q0 - внутренний параметр
#define idinternal1_m2333_q0	 1179	//(internal1_m2333_q0) q0 - внутренний параметр
#define internal1_m2330_q0	 BUFFER[3768]	//(internal1_m2330_q0) q0 - внутренний параметр
#define idinternal1_m2330_q0	 1180	//(internal1_m2330_q0) q0 - внутренний параметр
#define internal1_m2329_q0	 BUFFER[3770]	//(internal1_m2329_q0) q0 - внутренний параметр
#define idinternal1_m2329_q0	 1181	//(internal1_m2329_q0) q0 - внутренний параметр
#define internal1_m2343_q0	 BUFFER[3772]	//(internal1_m2343_q0) q0 - внутренний параметр
#define idinternal1_m2343_q0	 1182	//(internal1_m2343_q0) q0 - внутренний параметр
#define internal1_m2341_q0	 BUFFER[3774]	//(internal1_m2341_q0) q0 - внутренний параметр
#define idinternal1_m2341_q0	 1183	//(internal1_m2341_q0) q0 - внутренний параметр
#define internal1_m2206_tx	 BUFFER[3776]	//(internal1_m2206_tx) tx - внутренний параметр
#define idinternal1_m2206_tx	 1184	//(internal1_m2206_tx) tx - внутренний параметр
#define internal1_m2185_tx	 BUFFER[3781]	//(internal1_m2185_tx) tx - внутренний параметр
#define idinternal1_m2185_tx	 1185	//(internal1_m2185_tx) tx - внутренний параметр
#define internal1_m1889_Pv0	 BUFFER[3786]	//(internal1_m1889_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1889_Pv0	 1186	//(internal1_m1889_Pv0)  - Пер. выключатель механизма
#define internal1_m1889_Zv0	 BUFFER[3788]	//(internal1_m1889_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1889_Zv0	 1187	//(internal1_m1889_Zv0)  - Зад. выключатель механизма
#define internal1_m1889_MyFirstEnterFlag	 BUFFER[3790]	//(internal1_m1889_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1889_MyFirstEnterFlag	 1188	//(internal1_m1889_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m1887_Pv0	 BUFFER[3792]	//(internal1_m1887_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1887_Pv0	 1189	//(internal1_m1887_Pv0)  - Пер. выключатель механизма
#define internal1_m1887_Zv0	 BUFFER[3794]	//(internal1_m1887_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1887_Zv0	 1190	//(internal1_m1887_Zv0)  - Зад. выключатель механизма
#define internal1_m1887_MyFirstEnterFlag	 BUFFER[3796]	//(internal1_m1887_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1887_MyFirstEnterFlag	 1191	//(internal1_m1887_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m2371_tx	 BUFFER[3798]	//(internal1_m2371_tx) tx - время накопленное сек
#define idinternal1_m2371_tx	 1192	//(internal1_m2371_tx) tx - время накопленное сек
#define internal1_m2371_y0	 BUFFER[3803]	//(internal1_m2371_y0) y0
#define idinternal1_m2371_y0	 1193	//(internal1_m2371_y0) y0
#define internal1_m2375_tx	 BUFFER[3804]	//(internal1_m2375_tx) tx - время накопленное сек
#define idinternal1_m2375_tx	 1194	//(internal1_m2375_tx) tx - время накопленное сек
#define internal1_m2375_y0	 BUFFER[3809]	//(internal1_m2375_y0) y0
#define idinternal1_m2375_y0	 1195	//(internal1_m2375_y0) y0
#define internal1_m2374_tx	 BUFFER[3810]	//(internal1_m2374_tx) tx - время накопленное сек
#define idinternal1_m2374_tx	 1196	//(internal1_m2374_tx) tx - время накопленное сек
#define internal1_m2374_y0	 BUFFER[3815]	//(internal1_m2374_y0) y0
#define idinternal1_m2374_y0	 1197	//(internal1_m2374_y0) y0
#define internal1_m2411_tx	 BUFFER[3816]	//(internal1_m2411_tx) tx - внутренний параметр
#define idinternal1_m2411_tx	 1198	//(internal1_m2411_tx) tx - внутренний параметр
#define internal1_m2409_tx	 BUFFER[3821]	//(internal1_m2409_tx) tx - время накопленное сек
#define idinternal1_m2409_tx	 1199	//(internal1_m2409_tx) tx - время накопленное сек
#define internal1_m2409_y0	 BUFFER[3826]	//(internal1_m2409_y0) y0
#define idinternal1_m2409_y0	 1200	//(internal1_m2409_y0) y0
#define internal1_m2414_q0	 BUFFER[3827]	//(internal1_m2414_q0) q0 - внутренний параметр
#define idinternal1_m2414_q0	 1201	//(internal1_m2414_q0) q0 - внутренний параметр
#define internal1_m2381_q0	 BUFFER[3829]	//(internal1_m2381_q0) q0 - внутренний параметр
#define idinternal1_m2381_q0	 1202	//(internal1_m2381_q0) q0 - внутренний параметр
#define internal1_m2389_tx	 BUFFER[3831]	//(internal1_m2389_tx) tx - внутренний параметр
#define idinternal1_m2389_tx	 1203	//(internal1_m2389_tx) tx - внутренний параметр
#define internal1_m2387_q0	 BUFFER[3836]	//(internal1_m2387_q0) q0 - внутренний параметр
#define idinternal1_m2387_q0	 1204	//(internal1_m2387_q0) q0 - внутренний параметр
#define internal1_m2200_tx	 BUFFER[3838]	//(internal1_m2200_tx) tx - время накопленное сек
#define idinternal1_m2200_tx	 1205	//(internal1_m2200_tx) tx - время накопленное сек
#define internal1_m2200_y0	 BUFFER[3843]	//(internal1_m2200_y0) y0
#define idinternal1_m2200_y0	 1206	//(internal1_m2200_y0) y0
#define internal1_m2192_tx	 BUFFER[3844]	//(internal1_m2192_tx) tx - время накопленное сек
#define idinternal1_m2192_tx	 1207	//(internal1_m2192_tx) tx - время накопленное сек
#define internal1_m2192_y0	 BUFFER[3849]	//(internal1_m2192_y0) y0
#define idinternal1_m2192_y0	 1208	//(internal1_m2192_y0) y0
#define internal1_m1876_q0	 BUFFER[3850]	//(internal1_m1876_q0) q0 - внутренний параметр
#define idinternal1_m1876_q0	 1209	//(internal1_m1876_q0) q0 - внутренний параметр
#define internal1_m1881_q0	 BUFFER[3852]	//(internal1_m1881_q0) q0 - внутренний параметр
#define idinternal1_m1881_q0	 1210	//(internal1_m1881_q0) q0 - внутренний параметр
#define internal1_m1873_q0	 BUFFER[3854]	//(internal1_m1873_q0) q0 - внутренний параметр
#define idinternal1_m1873_q0	 1211	//(internal1_m1873_q0) q0 - внутренний параметр
#define internal1_m1915_q0	 BUFFER[3856]	//(internal1_m1915_q0) q0 - внутренний параметр
#define idinternal1_m1915_q0	 1212	//(internal1_m1915_q0) q0 - внутренний параметр
#define internal1_m823_tx	 BUFFER[3858]	//(internal1_m823_tx) tx - время накопленное сек
#define idinternal1_m823_tx	 1213	//(internal1_m823_tx) tx - время накопленное сек
#define internal1_m823_y0	 BUFFER[3863]	//(internal1_m823_y0) y0
#define idinternal1_m823_y0	 1214	//(internal1_m823_y0) y0
#define internal1_m2196_tx	 BUFFER[3864]	//(internal1_m2196_tx) tx - внутренний параметр
#define idinternal1_m2196_tx	 1215	//(internal1_m2196_tx) tx - внутренний параметр
#define internal1_m2199_q0	 BUFFER[3869]	//(internal1_m2199_q0) q0 - внутренний параметр
#define idinternal1_m2199_q0	 1216	//(internal1_m2199_q0) q0 - внутренний параметр
#define internal1_m2191_q0	 BUFFER[3871]	//(internal1_m2191_q0) q0 - внутренний параметр
#define idinternal1_m2191_q0	 1217	//(internal1_m2191_q0) q0 - внутренний параметр
#define internal1_m2160_tx	 BUFFER[3873]	//(internal1_m2160_tx) tx - внутренний параметр
#define idinternal1_m2160_tx	 1218	//(internal1_m2160_tx) tx - внутренний параметр
#define internal1_m2171_tx	 BUFFER[3878]	//(internal1_m2171_tx) tx - внутренний параметр
#define idinternal1_m2171_tx	 1219	//(internal1_m2171_tx) tx - внутренний параметр
#define internal1_m2157_tx	 BUFFER[3883]	//(internal1_m2157_tx) tx - внутренний параметр
#define idinternal1_m2157_tx	 1220	//(internal1_m2157_tx) tx - внутренний параметр
#define internal1_m2163_q0	 BUFFER[3888]	//(internal1_m2163_q0) q0 - внутренний параметр
#define idinternal1_m2163_q0	 1221	//(internal1_m2163_q0) q0 - внутренний параметр
#define internal1_m2175_q0	 BUFFER[3890]	//(internal1_m2175_q0) q0 - внутренний параметр
#define idinternal1_m2175_q0	 1222	//(internal1_m2175_q0) q0 - внутренний параметр
#define internal1_m2132_tx	 BUFFER[3892]	//(internal1_m2132_tx) tx - внутренний параметр
#define idinternal1_m2132_tx	 1223	//(internal1_m2132_tx) tx - внутренний параметр
#define internal1_m51_tx	 BUFFER[3897]	//(internal1_m51_tx) tx - внутренний параметр
#define idinternal1_m51_tx	 1224	//(internal1_m51_tx) tx - внутренний параметр
#define internal1_m357_tx	 BUFFER[3902]	//(internal1_m357_tx) tx - внутренний параметр
#define idinternal1_m357_tx	 1225	//(internal1_m357_tx) tx - внутренний параметр
#define internal1_m312_tx	 BUFFER[3907]	//(internal1_m312_tx) tx - внутренний параметр
#define idinternal1_m312_tx	 1226	//(internal1_m312_tx) tx - внутренний параметр
#define internal1_m824_tx	 BUFFER[3912]	//(internal1_m824_tx) tx - внутренний параметр
#define idinternal1_m824_tx	 1227	//(internal1_m824_tx) tx - внутренний параметр
#define internal1_m1584_tx	 BUFFER[3917]	//(internal1_m1584_tx) tx - внутренний параметр
#define idinternal1_m1584_tx	 1228	//(internal1_m1584_tx) tx - внутренний параметр
#define internal1_m114_tx	 BUFFER[3922]	//(internal1_m114_tx) tx - внутренний параметр
#define idinternal1_m114_tx	 1229	//(internal1_m114_tx) tx - внутренний параметр
#define internal1_m116_tx	 BUFFER[3927]	//(internal1_m116_tx) tx - внутренний параметр
#define idinternal1_m116_tx	 1230	//(internal1_m116_tx) tx - внутренний параметр
#define internal1_m121_tx	 BUFFER[3932]	//(internal1_m121_tx) tx - внутренний параметр
#define idinternal1_m121_tx	 1231	//(internal1_m121_tx) tx - внутренний параметр
#define internal1_m21_tx	 BUFFER[3937]	//(internal1_m21_tx) tx - внутренний параметр
#define idinternal1_m21_tx	 1232	//(internal1_m21_tx) tx - внутренний параметр
#define internal1_m13_tx	 BUFFER[3942]	//(internal1_m13_tx) tx - внутренний параметр
#define idinternal1_m13_tx	 1233	//(internal1_m13_tx) tx - внутренний параметр
#define internal1_m2142_tx	 BUFFER[3947]	//(internal1_m2142_tx) tx - внутренний параметр
#define idinternal1_m2142_tx	 1234	//(internal1_m2142_tx) tx - внутренний параметр
#define internal1_m2129_tx	 BUFFER[3952]	//(internal1_m2129_tx) tx - внутренний параметр
#define idinternal1_m2129_tx	 1235	//(internal1_m2129_tx) tx - внутренний параметр
#define internal1_m2247_tx	 BUFFER[3957]	//(internal1_m2247_tx) tx - внутренний параметр
#define idinternal1_m2247_tx	 1236	//(internal1_m2247_tx) tx - внутренний параметр
#define internal1_m2249_tx	 BUFFER[3962]	//(internal1_m2249_tx) tx - внутренний параметр
#define idinternal1_m2249_tx	 1237	//(internal1_m2249_tx) tx - внутренний параметр
#define internal1_m2054_tx	 BUFFER[3967]	//(internal1_m2054_tx) tx - внутренний параметр
#define idinternal1_m2054_tx	 1238	//(internal1_m2054_tx) tx - внутренний параметр
#define internal1_m77_tx	 BUFFER[3972]	//(internal1_m77_tx) tx - внутренний параметр
#define idinternal1_m77_tx	 1239	//(internal1_m77_tx) tx - внутренний параметр
#define internal1_m328_tx	 BUFFER[3977]	//(internal1_m328_tx) tx - время накопленное сек
#define idinternal1_m328_tx	 1240	//(internal1_m328_tx) tx - время накопленное сек
#define internal1_m328_y0	 BUFFER[3982]	//(internal1_m328_y0) y0
#define idinternal1_m328_y0	 1241	//(internal1_m328_y0) y0
#define internal1_m2048_tx	 BUFFER[3983]	//(internal1_m2048_tx) tx - время накопленное сек
#define idinternal1_m2048_tx	 1242	//(internal1_m2048_tx) tx - время накопленное сек
#define internal1_m2048_y0	 BUFFER[3988]	//(internal1_m2048_y0) y0
#define idinternal1_m2048_y0	 1243	//(internal1_m2048_y0) y0
#define internal1_m2046_tx	 BUFFER[3989]	//(internal1_m2046_tx) tx - время накопленное сек
#define idinternal1_m2046_tx	 1244	//(internal1_m2046_tx) tx - время накопленное сек
#define internal1_m2046_y0	 BUFFER[3994]	//(internal1_m2046_y0) y0
#define idinternal1_m2046_y0	 1245	//(internal1_m2046_y0) y0
#define internal1_m2035_tx	 BUFFER[3995]	//(internal1_m2035_tx) tx - время накопленное сек
#define idinternal1_m2035_tx	 1246	//(internal1_m2035_tx) tx - время накопленное сек
#define internal1_m2035_y0	 BUFFER[4000]	//(internal1_m2035_y0) y0
#define idinternal1_m2035_y0	 1247	//(internal1_m2035_y0) y0
#define internal1_m2055_q0	 BUFFER[4001]	//(internal1_m2055_q0) q0 - внутренний параметр
#define idinternal1_m2055_q0	 1248	//(internal1_m2055_q0) q0 - внутренний параметр
#define internal1_m1604_q0	 BUFFER[4006]	//(internal1_m1604_q0) q0 - внутренний параметр
#define idinternal1_m1604_q0	 1249	//(internal1_m1604_q0) q0 - внутренний параметр
#define internal1_m1642_q0	 BUFFER[4011]	//(internal1_m1642_q0) q0 - внутренний параметр
#define idinternal1_m1642_q0	 1250	//(internal1_m1642_q0) q0 - внутренний параметр
#define internal1_m1645_q0	 BUFFER[4016]	//(internal1_m1645_q0) q0 - внутренний параметр
#define idinternal1_m1645_q0	 1251	//(internal1_m1645_q0) q0 - внутренний параметр
#define internal1_m2094_q0	 BUFFER[4021]	//(internal1_m2094_q0) q0 - внутренний параметр
#define idinternal1_m2094_q0	 1252	//(internal1_m2094_q0) q0 - внутренний параметр
#define internal1_m2074_tx	 BUFFER[4026]	//(internal1_m2074_tx) tx - время накопленное сек
#define idinternal1_m2074_tx	 1253	//(internal1_m2074_tx) tx - время накопленное сек
#define internal1_m2074_y0	 BUFFER[4031]	//(internal1_m2074_y0) y0
#define idinternal1_m2074_y0	 1254	//(internal1_m2074_y0) y0
#define internal1_m2087_tx	 BUFFER[4032]	//(internal1_m2087_tx) tx - время накопленное сек
#define idinternal1_m2087_tx	 1255	//(internal1_m2087_tx) tx - время накопленное сек
#define internal1_m2087_y0	 BUFFER[4037]	//(internal1_m2087_y0) y0
#define idinternal1_m2087_y0	 1256	//(internal1_m2087_y0) y0
#define internal1_m2084_tx	 BUFFER[4038]	//(internal1_m2084_tx) tx - время накопленное сек
#define idinternal1_m2084_tx	 1257	//(internal1_m2084_tx) tx - время накопленное сек
#define internal1_m2084_y0	 BUFFER[4043]	//(internal1_m2084_y0) y0
#define idinternal1_m2084_y0	 1258	//(internal1_m2084_y0) y0
#define internal1_m2227_tx	 BUFFER[4044]	//(internal1_m2227_tx) tx - время накопленное сек
#define idinternal1_m2227_tx	 1259	//(internal1_m2227_tx) tx - время накопленное сек
#define internal1_m2227_y0	 BUFFER[4049]	//(internal1_m2227_y0) y0
#define idinternal1_m2227_y0	 1260	//(internal1_m2227_y0) y0
#define internal1_m2238_tx	 BUFFER[4050]	//(internal1_m2238_tx) tx - время накопленное сек
#define idinternal1_m2238_tx	 1261	//(internal1_m2238_tx) tx - время накопленное сек
#define internal1_m2238_y0	 BUFFER[4055]	//(internal1_m2238_y0) y0
#define idinternal1_m2238_y0	 1262	//(internal1_m2238_y0) y0
#define internal1_m1983_tx	 BUFFER[4056]	//(internal1_m1983_tx) tx - время накопленное сек
#define idinternal1_m1983_tx	 1263	//(internal1_m1983_tx) tx - время накопленное сек
#define internal1_m1983_y0	 BUFFER[4061]	//(internal1_m1983_y0) y0
#define idinternal1_m1983_y0	 1264	//(internal1_m1983_y0) y0
#define internal1_m1982_tx	 BUFFER[4062]	//(internal1_m1982_tx) tx - время накопленное сек
#define idinternal1_m1982_tx	 1265	//(internal1_m1982_tx) tx - время накопленное сек
#define internal1_m1982_y0	 BUFFER[4067]	//(internal1_m1982_y0) y0
#define idinternal1_m1982_y0	 1266	//(internal1_m1982_y0) y0
#define internal1_m1981_tx	 BUFFER[4068]	//(internal1_m1981_tx) tx - время накопленное сек
#define idinternal1_m1981_tx	 1267	//(internal1_m1981_tx) tx - время накопленное сек
#define internal1_m1981_y0	 BUFFER[4073]	//(internal1_m1981_y0) y0
#define idinternal1_m1981_y0	 1268	//(internal1_m1981_y0) y0
#define internal1_m1980_tx	 BUFFER[4074]	//(internal1_m1980_tx) tx - время накопленное сек
#define idinternal1_m1980_tx	 1269	//(internal1_m1980_tx) tx - время накопленное сек
#define internal1_m1980_y0	 BUFFER[4079]	//(internal1_m1980_y0) y0
#define idinternal1_m1980_y0	 1270	//(internal1_m1980_y0) y0
#define internal1_m1656_tx	 BUFFER[4080]	//(internal1_m1656_tx) tx - время накопленное сек
#define idinternal1_m1656_tx	 1271	//(internal1_m1656_tx) tx - время накопленное сек
#define internal1_m1656_y0	 BUFFER[4085]	//(internal1_m1656_y0) y0
#define idinternal1_m1656_y0	 1272	//(internal1_m1656_y0) y0
#define internal1_m1650_tx	 BUFFER[4086]	//(internal1_m1650_tx) tx - время накопленное сек
#define idinternal1_m1650_tx	 1273	//(internal1_m1650_tx) tx - время накопленное сек
#define internal1_m1650_y0	 BUFFER[4091]	//(internal1_m1650_y0) y0
#define idinternal1_m1650_y0	 1274	//(internal1_m1650_y0) y0
#define internal1_m1600_tx	 BUFFER[4092]	//(internal1_m1600_tx) tx - время накопленное сек
#define idinternal1_m1600_tx	 1275	//(internal1_m1600_tx) tx - время накопленное сек
#define internal1_m1600_y0	 BUFFER[4097]	//(internal1_m1600_y0) y0
#define idinternal1_m1600_y0	 1276	//(internal1_m1600_y0) y0
#define internal1_m911_tx	 BUFFER[4098]	//(internal1_m911_tx) tx - время накопленное сек
#define idinternal1_m911_tx	 1277	//(internal1_m911_tx) tx - время накопленное сек
#define internal1_m911_y0	 BUFFER[4103]	//(internal1_m911_y0) y0
#define idinternal1_m911_y0	 1278	//(internal1_m911_y0) y0
#define internal1_m910_tx	 BUFFER[4104]	//(internal1_m910_tx) tx - время накопленное сек
#define idinternal1_m910_tx	 1279	//(internal1_m910_tx) tx - время накопленное сек
#define internal1_m910_y0	 BUFFER[4109]	//(internal1_m910_y0) y0
#define idinternal1_m910_y0	 1280	//(internal1_m910_y0) y0
#define internal1_m928_tx	 BUFFER[4110]	//(internal1_m928_tx) tx - время накопленное сек
#define idinternal1_m928_tx	 1281	//(internal1_m928_tx) tx - время накопленное сек
#define internal1_m928_y0	 BUFFER[4115]	//(internal1_m928_y0) y0
#define idinternal1_m928_y0	 1282	//(internal1_m928_y0) y0
#define internal1_m187_tx	 BUFFER[4116]	//(internal1_m187_tx) tx - время накопленное сек
#define idinternal1_m187_tx	 1283	//(internal1_m187_tx) tx - время накопленное сек
#define internal1_m187_y0	 BUFFER[4121]	//(internal1_m187_y0) y0
#define idinternal1_m187_y0	 1284	//(internal1_m187_y0) y0
#define internal1_m186_tx	 BUFFER[4122]	//(internal1_m186_tx) tx - время накопленное сек
#define idinternal1_m186_tx	 1285	//(internal1_m186_tx) tx - время накопленное сек
#define internal1_m186_y0	 BUFFER[4127]	//(internal1_m186_y0) y0
#define idinternal1_m186_y0	 1286	//(internal1_m186_y0) y0
#define internal1_m208_tx	 BUFFER[4128]	//(internal1_m208_tx) tx - время накопленное сек
#define idinternal1_m208_tx	 1287	//(internal1_m208_tx) tx - время накопленное сек
#define internal1_m208_y0	 BUFFER[4133]	//(internal1_m208_y0) y0
#define idinternal1_m208_y0	 1288	//(internal1_m208_y0) y0
#define internal1_m577_tx	 BUFFER[4134]	//(internal1_m577_tx) tx - время накопленное сек
#define idinternal1_m577_tx	 1289	//(internal1_m577_tx) tx - время накопленное сек
#define internal1_m577_y0	 BUFFER[4139]	//(internal1_m577_y0) y0
#define idinternal1_m577_y0	 1290	//(internal1_m577_y0) y0
#define internal1_m2281_tx	 BUFFER[4140]	//(internal1_m2281_tx) tx - внутренний параметр
#define idinternal1_m2281_tx	 1291	//(internal1_m2281_tx) tx - внутренний параметр
#define internal1_m1307_tx	 BUFFER[4145]	//(internal1_m1307_tx) tx - внутренний параметр
#define idinternal1_m1307_tx	 1292	//(internal1_m1307_tx) tx - внутренний параметр
#define internal1_m1785_tx	 BUFFER[4150]	//(internal1_m1785_tx) tx - время накопленное сек
#define idinternal1_m1785_tx	 1293	//(internal1_m1785_tx) tx - время накопленное сек
#define internal1_m1785_y0	 BUFFER[4155]	//(internal1_m1785_y0) y0
#define idinternal1_m1785_y0	 1294	//(internal1_m1785_y0) y0
#define internal1_m1272_tx	 BUFFER[4156]	//(internal1_m1272_tx) tx - время накопленное сек
#define idinternal1_m1272_tx	 1295	//(internal1_m1272_tx) tx - время накопленное сек
#define internal1_m1272_y0	 BUFFER[4161]	//(internal1_m1272_y0) y0
#define idinternal1_m1272_y0	 1296	//(internal1_m1272_y0) y0
#define internal1_m1492_tx	 BUFFER[4162]	//(internal1_m1492_tx) tx - время накопленное сек
#define idinternal1_m1492_tx	 1297	//(internal1_m1492_tx) tx - время накопленное сек
#define internal1_m1492_y0	 BUFFER[4167]	//(internal1_m1492_y0) y0
#define idinternal1_m1492_y0	 1298	//(internal1_m1492_y0) y0
#define internal1_m1041_tx	 BUFFER[4168]	//(internal1_m1041_tx) tx - время накопленное сек
#define idinternal1_m1041_tx	 1299	//(internal1_m1041_tx) tx - время накопленное сек
#define internal1_m1041_y0	 BUFFER[4173]	//(internal1_m1041_y0) y0
#define idinternal1_m1041_y0	 1300	//(internal1_m1041_y0) y0
#define internal1_m1382_tx	 BUFFER[4174]	//(internal1_m1382_tx) tx - время накопленное сек
#define idinternal1_m1382_tx	 1301	//(internal1_m1382_tx) tx - время накопленное сек
#define internal1_m1382_y0	 BUFFER[4179]	//(internal1_m1382_y0) y0
#define idinternal1_m1382_y0	 1302	//(internal1_m1382_y0) y0
#define internal1_m1198_q0	 BUFFER[4180]	//(internal1_m1198_q0) q0 - внутренний параметр
#define idinternal1_m1198_q0	 1303	//(internal1_m1198_q0) q0 - внутренний параметр
#define internal1_m1196_q0	 BUFFER[4182]	//(internal1_m1196_q0) q0 - внутренний параметр
#define idinternal1_m1196_q0	 1304	//(internal1_m1196_q0) q0 - внутренний параметр
#define internal1_m1195_q0	 BUFFER[4184]	//(internal1_m1195_q0) q0 - внутренний параметр
#define idinternal1_m1195_q0	 1305	//(internal1_m1195_q0) q0 - внутренний параметр
#define internal1_m1193_q0	 BUFFER[4186]	//(internal1_m1193_q0) q0 - внутренний параметр
#define idinternal1_m1193_q0	 1306	//(internal1_m1193_q0) q0 - внутренний параметр
#define internal1_m1192_q0	 BUFFER[4188]	//(internal1_m1192_q0) q0 - внутренний параметр
#define idinternal1_m1192_q0	 1307	//(internal1_m1192_q0) q0 - внутренний параметр
#define internal1_m1190_q0	 BUFFER[4190]	//(internal1_m1190_q0) q0 - внутренний параметр
#define idinternal1_m1190_q0	 1308	//(internal1_m1190_q0) q0 - внутренний параметр
#define internal1_m1189_q0	 BUFFER[4192]	//(internal1_m1189_q0) q0 - внутренний параметр
#define idinternal1_m1189_q0	 1309	//(internal1_m1189_q0) q0 - внутренний параметр
#define internal1_m1187_q0	 BUFFER[4194]	//(internal1_m1187_q0) q0 - внутренний параметр
#define idinternal1_m1187_q0	 1310	//(internal1_m1187_q0) q0 - внутренний параметр
#define internal1_m1186_q0	 BUFFER[4196]	//(internal1_m1186_q0) q0 - внутренний параметр
#define idinternal1_m1186_q0	 1311	//(internal1_m1186_q0) q0 - внутренний параметр
#define internal1_m52_x0	 BUFFER[4198]	//(internal1_m52_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m52_x0	 1312	//(internal1_m52_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1105_q0	 BUFFER[4200]	//(internal1_m1105_q0) q0 - внутренний параметр
#define idinternal1_m1105_q0	 1313	//(internal1_m1105_q0) q0 - внутренний параметр
#define internal1_m1593_x0	 BUFFER[4202]	//(internal1_m1593_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1593_x0	 1314	//(internal1_m1593_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1637_x0	 BUFFER[4204]	//(internal1_m1637_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1637_x0	 1315	//(internal1_m1637_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1633_x0	 BUFFER[4206]	//(internal1_m1633_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1633_x0	 1316	//(internal1_m1633_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m2063_x0	 BUFFER[4208]	//(internal1_m2063_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m2063_x0	 1317	//(internal1_m2063_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m2028_x0	 BUFFER[4210]	//(internal1_m2028_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m2028_x0	 1318	//(internal1_m2028_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1145_q0	 BUFFER[4212]	//(internal1_m1145_q0) q0 - внутренний параметр
#define idinternal1_m1145_q0	 1319	//(internal1_m1145_q0) q0 - внутренний параметр
#define internal1_m1157_q0	 BUFFER[4214]	//(internal1_m1157_q0) q0 - внутренний параметр
#define idinternal1_m1157_q0	 1320	//(internal1_m1157_q0) q0 - внутренний параметр
#define internal1_m1169_q0	 BUFFER[4216]	//(internal1_m1169_q0) q0 - внутренний параметр
#define idinternal1_m1169_q0	 1321	//(internal1_m1169_q0) q0 - внутренний параметр
#define internal1_m1178_q0	 BUFFER[4218]	//(internal1_m1178_q0) q0 - внутренний параметр
#define idinternal1_m1178_q0	 1322	//(internal1_m1178_q0) q0 - внутренний параметр
#define internal1_m1156_q0	 BUFFER[4220]	//(internal1_m1156_q0) q0 - внутренний параметр
#define idinternal1_m1156_q0	 1323	//(internal1_m1156_q0) q0 - внутренний параметр
#define internal1_m1171_q0	 BUFFER[4222]	//(internal1_m1171_q0) q0 - внутренний параметр
#define idinternal1_m1171_q0	 1324	//(internal1_m1171_q0) q0 - внутренний параметр
#define internal1_m2121_q0	 BUFFER[4224]	//(internal1_m2121_q0) q0 - внутренний параметр
#define idinternal1_m2121_q0	 1325	//(internal1_m2121_q0) q0 - внутренний параметр
#define internal1_m2120_q0	 BUFFER[4226]	//(internal1_m2120_q0) q0 - внутренний параметр
#define idinternal1_m2120_q0	 1326	//(internal1_m2120_q0) q0 - внутренний параметр
#define internal1_m345_Step	 BUFFER[4228]	//(internal1_m345_Step)  - текущий шаг программы
#define idinternal1_m345_Step	 1327	//(internal1_m345_Step)  - текущий шаг программы
#define internal1_m345_rz	 BUFFER[4231]	//(internal1_m345_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m345_rz	 1328	//(internal1_m345_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m345_TimS	 BUFFER[4241]	//(internal1_m345_TimS) Время от старта программы
#define idinternal1_m345_TimS	 1329	//(internal1_m345_TimS) Время от старта программы
#define internal1_m345_FinPr0	 BUFFER[4246]	//(internal1_m345_FinPr0) FinPr - конец программы
#define idinternal1_m345_FinPr0	 1330	//(internal1_m345_FinPr0) FinPr - конец программы
#define internal1_m345_ErrPr0	 BUFFER[4248]	//(internal1_m345_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m345_ErrPr0	 1331	//(internal1_m345_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m345_sbINI0	 BUFFER[4250]	//(internal1_m345_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m345_sbINI0	 1332	//(internal1_m345_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m345_sbVuIS0	 BUFFER[4252]	//(internal1_m345_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m345_sbVuIS0	 1333	//(internal1_m345_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m345_sb2UR0	 BUFFER[4254]	//(internal1_m345_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m345_sb2UR0	 1334	//(internal1_m345_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m345_sbNupIS0	 BUFFER[4256]	//(internal1_m345_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m345_sbNupIS0	 1335	//(internal1_m345_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m345_sbVuRB0	 BUFFER[4258]	//(internal1_m345_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m345_sbVuRB0	 1336	//(internal1_m345_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m345_MyFirstEnterFlag	 BUFFER[4260]	//(internal1_m345_MyFirstEnterFlag)  
#define idinternal1_m345_MyFirstEnterFlag	 1337	//(internal1_m345_MyFirstEnterFlag)  
#define internal1_m353_x0	 BUFFER[4262]	//(internal1_m353_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m353_x0	 1338	//(internal1_m353_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m311_TimS	 BUFFER[4267]	//(internal1_m311_TimS) Время старта
#define idinternal1_m311_TimS	 1339	//(internal1_m311_TimS) Время старта
#define internal1_m287_Step	 BUFFER[4272]	//(internal1_m287_Step)  - текущий шаг программы
#define idinternal1_m287_Step	 1340	//(internal1_m287_Step)  - текущий шаг программы
#define internal1_m287_rz	 BUFFER[4275]	//(internal1_m287_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m287_rz	 1341	//(internal1_m287_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m287_TimS	 BUFFER[4285]	//(internal1_m287_TimS) Время от старта программы
#define idinternal1_m287_TimS	 1342	//(internal1_m287_TimS) Время от старта программы
#define internal1_m287_FinPr0	 BUFFER[4290]	//(internal1_m287_FinPr0) FinPr - конец программы
#define idinternal1_m287_FinPr0	 1343	//(internal1_m287_FinPr0) FinPr - конец программы
#define internal1_m287_ErrPr0	 BUFFER[4292]	//(internal1_m287_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m287_ErrPr0	 1344	//(internal1_m287_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m287_sbINI0	 BUFFER[4294]	//(internal1_m287_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m287_sbINI0	 1345	//(internal1_m287_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m287_sbVuIS0	 BUFFER[4296]	//(internal1_m287_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m287_sbVuIS0	 1346	//(internal1_m287_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m287_sb2UR0	 BUFFER[4298]	//(internal1_m287_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m287_sb2UR0	 1347	//(internal1_m287_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m287_sbNupIS0	 BUFFER[4300]	//(internal1_m287_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m287_sbNupIS0	 1348	//(internal1_m287_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m287_sbVuRB0	 BUFFER[4302]	//(internal1_m287_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m287_sbVuRB0	 1349	//(internal1_m287_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m287_MyFirstEnterFlag	 BUFFER[4304]	//(internal1_m287_MyFirstEnterFlag)  
#define idinternal1_m287_MyFirstEnterFlag	 1350	//(internal1_m287_MyFirstEnterFlag)  
#define internal1_m1567_q0	 BUFFER[4306]	//(internal1_m1567_q0) q0 - внутренний параметр
#define idinternal1_m1567_q0	 1351	//(internal1_m1567_q0) q0 - внутренний параметр
#define internal1_m1568_Step	 BUFFER[4308]	//(internal1_m1568_Step)  - текущий шаг программы
#define idinternal1_m1568_Step	 1352	//(internal1_m1568_Step)  - текущий шаг программы
#define internal1_m1568_rz	 BUFFER[4311]	//(internal1_m1568_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m1568_rz	 1353	//(internal1_m1568_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m1568_TimS	 BUFFER[4317]	//(internal1_m1568_TimS) Время от старта программы
#define idinternal1_m1568_TimS	 1354	//(internal1_m1568_TimS) Время от старта программы
#define internal1_m1568_FinPr0	 BUFFER[4322]	//(internal1_m1568_FinPr0) FinPr - конец программы
#define idinternal1_m1568_FinPr0	 1355	//(internal1_m1568_FinPr0) FinPr - конец программы
#define internal1_m1568_ErrPr0	 BUFFER[4324]	//(internal1_m1568_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m1568_ErrPr0	 1356	//(internal1_m1568_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m1568_sbINI0	 BUFFER[4326]	//(internal1_m1568_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m1568_sbINI0	 1357	//(internal1_m1568_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m1568_sbVuIS0	 BUFFER[4328]	//(internal1_m1568_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m1568_sbVuIS0	 1358	//(internal1_m1568_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m1568_sb2UR0	 BUFFER[4330]	//(internal1_m1568_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m1568_sb2UR0	 1359	//(internal1_m1568_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m1568_sbNupIS0	 BUFFER[4332]	//(internal1_m1568_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m1568_sbNupIS0	 1360	//(internal1_m1568_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m1568_sbVuRB0	 BUFFER[4334]	//(internal1_m1568_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m1568_sbVuRB0	 1361	//(internal1_m1568_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m1568_MyFirstEnterFlag	 BUFFER[4336]	//(internal1_m1568_MyFirstEnterFlag)  
#define idinternal1_m1568_MyFirstEnterFlag	 1362	//(internal1_m1568_MyFirstEnterFlag)  
#define internal1_m1141_q0	 BUFFER[4338]	//(internal1_m1141_q0) q0 - внутренний параметр
#define idinternal1_m1141_q0	 1363	//(internal1_m1141_q0) q0 - внутренний параметр
#define internal1_m1138_q0	 BUFFER[4340]	//(internal1_m1138_q0) q0 - внутренний параметр
#define idinternal1_m1138_q0	 1364	//(internal1_m1138_q0) q0 - внутренний параметр
#define internal1_m1140_q0	 BUFFER[4342]	//(internal1_m1140_q0) q0 - внутренний параметр
#define idinternal1_m1140_q0	 1365	//(internal1_m1140_q0) q0 - внутренний параметр
#define internal1_m1134_q0	 BUFFER[4344]	//(internal1_m1134_q0) q0 - внутренний параметр
#define idinternal1_m1134_q0	 1366	//(internal1_m1134_q0) q0 - внутренний параметр
#define internal1_m825_q0	 BUFFER[4346]	//(internal1_m825_q0) q0 - внутренний параметр
#define idinternal1_m825_q0	 1367	//(internal1_m825_q0) q0 - внутренний параметр
#define internal1_m355_q0	 BUFFER[4348]	//(internal1_m355_q0) q0 - внутренний параметр
#define idinternal1_m355_q0	 1368	//(internal1_m355_q0) q0 - внутренний параметр
#define internal1_m351_q0	 BUFFER[4350]	//(internal1_m351_q0) q0 - внутренний параметр
#define idinternal1_m351_q0	 1369	//(internal1_m351_q0) q0 - внутренний параметр
#define internal1_m307_q0	 BUFFER[4352]	//(internal1_m307_q0) q0 - внутренний параметр
#define idinternal1_m307_q0	 1370	//(internal1_m307_q0) q0 - внутренний параметр
#define internal1_m306_x0	 BUFFER[4354]	//(internal1_m306_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m306_x0	 1371	//(internal1_m306_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m2050_q0	 BUFFER[4359]	//(internal1_m2050_q0) q0 - внутренний параметр
#define idinternal1_m2050_q0	 1372	//(internal1_m2050_q0) q0 - внутренний параметр
#define internal1_m2038_q0	 BUFFER[4361]	//(internal1_m2038_q0) q0 - внутренний параметр
#define idinternal1_m2038_q0	 1373	//(internal1_m2038_q0) q0 - внутренний параметр
#define internal1_m2029_q0	 BUFFER[4363]	//(internal1_m2029_q0) q0 - внутренний параметр
#define idinternal1_m2029_q0	 1374	//(internal1_m2029_q0) q0 - внутренний параметр
#define internal1_m2104_q0	 BUFFER[4365]	//(internal1_m2104_q0) q0 - внутренний параметр
#define idinternal1_m2104_q0	 1375	//(internal1_m2104_q0) q0 - внутренний параметр
#define internal1_m2071_q0	 BUFFER[4367]	//(internal1_m2071_q0) q0 - внутренний параметр
#define idinternal1_m2071_q0	 1376	//(internal1_m2071_q0) q0 - внутренний параметр
#define internal1_m2064_q0	 BUFFER[4369]	//(internal1_m2064_q0) q0 - внутренний параметр
#define idinternal1_m2064_q0	 1377	//(internal1_m2064_q0) q0 - внутренний параметр
#define internal1_m1620_q0	 BUFFER[4371]	//(internal1_m1620_q0) q0 - внутренний параметр
#define idinternal1_m1620_q0	 1378	//(internal1_m1620_q0) q0 - внутренний параметр
#define internal1_m1607_x0	 BUFFER[4373]	//(internal1_m1607_x0) был приход сигнала x1
#define idinternal1_m1607_x0	 1379	//(internal1_m1607_x0) был приход сигнала x1
#define internal1_m1607_y0	 BUFFER[4375]	//(internal1_m1607_y0) интервал между сигналами х1 и х2
#define idinternal1_m1607_y0	 1380	//(internal1_m1607_y0) интервал между сигналами х1 и х2
#define internal1_m1603_q0	 BUFFER[4380]	//(internal1_m1603_q0) q0 - внутренний параметр
#define idinternal1_m1603_q0	 1381	//(internal1_m1603_q0) q0 - внутренний параметр
#define internal1_m1594_q0	 BUFFER[4382]	//(internal1_m1594_q0) q0 - внутренний параметр
#define idinternal1_m1594_q0	 1382	//(internal1_m1594_q0) q0 - внутренний параметр
#define internal1_m1653_q0	 BUFFER[4384]	//(internal1_m1653_q0) q0 - внутренний параметр
#define idinternal1_m1653_q0	 1383	//(internal1_m1653_q0) q0 - внутренний параметр
#define internal1_m1673_q0	 BUFFER[4386]	//(internal1_m1673_q0) q0 - внутренний параметр
#define idinternal1_m1673_q0	 1384	//(internal1_m1673_q0) q0 - внутренний параметр
#define internal1_m1639_q0	 BUFFER[4388]	//(internal1_m1639_q0) q0 - внутренний параметр
#define idinternal1_m1639_q0	 1385	//(internal1_m1639_q0) q0 - внутренний параметр
#define internal1_m1654_x0	 BUFFER[4390]	//(internal1_m1654_x0) был приход сигнала x1
#define idinternal1_m1654_x0	 1386	//(internal1_m1654_x0) был приход сигнала x1
#define internal1_m1654_y0	 BUFFER[4392]	//(internal1_m1654_y0) интервал между сигналами х1 и х2
#define idinternal1_m1654_y0	 1387	//(internal1_m1654_y0) интервал между сигналами х1 и х2
#define internal1_m1578_x0	 BUFFER[4397]	//(internal1_m1578_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1578_x0	 1388	//(internal1_m1578_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1659_q0	 BUFFER[4402]	//(internal1_m1659_q0) q0 - внутренний параметр
#define idinternal1_m1659_q0	 1389	//(internal1_m1659_q0) q0 - внутренний параметр
#define internal1_m26_q0	 BUFFER[4404]	//(internal1_m26_q0) q0 - внутренний параметр
#define idinternal1_m26_q0	 1390	//(internal1_m26_q0) q0 - внутренний параметр
#define internal1_m1674_q0	 BUFFER[4406]	//(internal1_m1674_q0) q0 - внутренний параметр
#define idinternal1_m1674_q0	 1391	//(internal1_m1674_q0) q0 - внутренний параметр
#define internal1_m700_q0	 BUFFER[4408]	//(internal1_m700_q0) q0 - внутренний параметр
#define idinternal1_m700_q0	 1392	//(internal1_m700_q0) q0 - внутренний параметр
#define internal1_m685_q0	 BUFFER[4410]	//(internal1_m685_q0) q0 - внутренний параметр
#define idinternal1_m685_q0	 1393	//(internal1_m685_q0) q0 - внутренний параметр
#define internal1_m712_q0	 BUFFER[4412]	//(internal1_m712_q0) q0 - внутренний параметр
#define idinternal1_m712_q0	 1394	//(internal1_m712_q0) q0 - внутренний параметр
#define internal1_m696_q0	 BUFFER[4414]	//(internal1_m696_q0) q0 - внутренний параметр
#define idinternal1_m696_q0	 1395	//(internal1_m696_q0) q0 - внутренний параметр
#define internal1_m680_q0	 BUFFER[4416]	//(internal1_m680_q0) q0 - внутренний параметр
#define idinternal1_m680_q0	 1396	//(internal1_m680_q0) q0 - внутренний параметр
#define internal1_m678_q0	 BUFFER[4418]	//(internal1_m678_q0) q0 - внутренний параметр
#define idinternal1_m678_q0	 1397	//(internal1_m678_q0) q0 - внутренний параметр
#define internal1_m666_q0	 BUFFER[4420]	//(internal1_m666_q0) q0 - внутренний параметр
#define idinternal1_m666_q0	 1398	//(internal1_m666_q0) q0 - внутренний параметр
#define internal1_m1570_q0	 BUFFER[4422]	//(internal1_m1570_q0) q0 - внутренний параметр
#define idinternal1_m1570_q0	 1399	//(internal1_m1570_q0) q0 - внутренний параметр
#define internal1_m676_q0	 BUFFER[4427]	//(internal1_m676_q0) q0 - внутренний параметр
#define idinternal1_m676_q0	 1400	//(internal1_m676_q0) q0 - внутренний параметр
#define internal1_m110_q0	 BUFFER[4429]	//(internal1_m110_q0) q0 - внутренний параметр
#define idinternal1_m110_q0	 1401	//(internal1_m110_q0) q0 - внутренний параметр
#define internal1_m1820_q0	 BUFFER[4431]	//(internal1_m1820_q0) q0 - внутренний параметр
#define idinternal1_m1820_q0	 1402	//(internal1_m1820_q0) q0 - внутренний параметр
#define internal1_m1819_q0	 BUFFER[4433]	//(internal1_m1819_q0) q0 - внутренний параметр
#define idinternal1_m1819_q0	 1403	//(internal1_m1819_q0) q0 - внутренний параметр
#define internal1_m1818_q0	 BUFFER[4435]	//(internal1_m1818_q0) q0 - внутренний параметр
#define idinternal1_m1818_q0	 1404	//(internal1_m1818_q0) q0 - внутренний параметр
#define internal1_m1817_q0	 BUFFER[4437]	//(internal1_m1817_q0) q0 - внутренний параметр
#define idinternal1_m1817_q0	 1405	//(internal1_m1817_q0) q0 - внутренний параметр
#define internal1_m1853_q0	 BUFFER[4439]	//(internal1_m1853_q0) q0 - внутренний параметр
#define idinternal1_m1853_q0	 1406	//(internal1_m1853_q0) q0 - внутренний параметр
#define internal1_m1852_q0	 BUFFER[4441]	//(internal1_m1852_q0) q0 - внутренний параметр
#define idinternal1_m1852_q0	 1407	//(internal1_m1852_q0) q0 - внутренний параметр
#define internal1_m1851_q0	 BUFFER[4443]	//(internal1_m1851_q0) q0 - внутренний параметр
#define idinternal1_m1851_q0	 1408	//(internal1_m1851_q0) q0 - внутренний параметр
#define internal1_m2135_q0	 BUFFER[4445]	//(internal1_m2135_q0) q0 - внутренний параметр
#define idinternal1_m2135_q0	 1409	//(internal1_m2135_q0) q0 - внутренний параметр
#define internal1_m1913_q0	 BUFFER[4447]	//(internal1_m1913_q0) q0 - внутренний параметр
#define idinternal1_m1913_q0	 1410	//(internal1_m1913_q0) q0 - внутренний параметр
#define internal1_m1905_q0	 BUFFER[4449]	//(internal1_m1905_q0) q0 - внутренний параметр
#define idinternal1_m1905_q0	 1411	//(internal1_m1905_q0) q0 - внутренний параметр
#define internal1_m1910_q0	 BUFFER[4451]	//(internal1_m1910_q0) q0 - внутренний параметр
#define idinternal1_m1910_q0	 1412	//(internal1_m1910_q0) q0 - внутренний параметр
#define internal1_m1904_q0	 BUFFER[4453]	//(internal1_m1904_q0) q0 - внутренний параметр
#define idinternal1_m1904_q0	 1413	//(internal1_m1904_q0) q0 - внутренний параметр
#define internal1_m1907_q0	 BUFFER[4455]	//(internal1_m1907_q0) q0 - внутренний параметр
#define idinternal1_m1907_q0	 1414	//(internal1_m1907_q0) q0 - внутренний параметр
#define internal1_m2349_q0	 BUFFER[4457]	//(internal1_m2349_q0) q0 - внутренний параметр
#define idinternal1_m2349_q0	 1415	//(internal1_m2349_q0) q0 - внутренний параметр
#define internal1_m2345_q0	 BUFFER[4459]	//(internal1_m2345_q0) q0 - внутренний параметр
#define idinternal1_m2345_q0	 1416	//(internal1_m2345_q0) q0 - внутренний параметр
#define internal1_m1878_q0	 BUFFER[4461]	//(internal1_m1878_q0) q0 - внутренний параметр
#define idinternal1_m1878_q0	 1417	//(internal1_m1878_q0) q0 - внутренний параметр
#define internal1_m1870_q0	 BUFFER[4463]	//(internal1_m1870_q0) q0 - внутренний параметр
#define idinternal1_m1870_q0	 1418	//(internal1_m1870_q0) q0 - внутренний параметр
#define internal1_m1868_q0	 BUFFER[4465]	//(internal1_m1868_q0) q0 - внутренний параметр
#define idinternal1_m1868_q0	 1419	//(internal1_m1868_q0) q0 - внутренний параметр
#define internal1_m1864_q0	 BUFFER[4467]	//(internal1_m1864_q0) q0 - внутренний параметр
#define idinternal1_m1864_q0	 1420	//(internal1_m1864_q0) q0 - внутренний параметр
#define internal1_m1860_q0	 BUFFER[4469]	//(internal1_m1860_q0) q0 - внутренний параметр
#define idinternal1_m1860_q0	 1421	//(internal1_m1860_q0) q0 - внутренний параметр
#define internal1_m1862_q0	 BUFFER[4471]	//(internal1_m1862_q0) q0 - внутренний параметр
#define idinternal1_m1862_q0	 1422	//(internal1_m1862_q0) q0 - внутренний параметр
#define internal1_m19_q0	 BUFFER[4473]	//(internal1_m19_q0) q0 - внутренний параметр
#define idinternal1_m19_q0	 1423	//(internal1_m19_q0) q0 - внутренний параметр
#define internal1_m1843_q0	 BUFFER[4475]	//(internal1_m1843_q0) q0 - внутренний параметр
#define idinternal1_m1843_q0	 1424	//(internal1_m1843_q0) q0 - внутренний параметр
#define internal1_m1841_q0	 BUFFER[4477]	//(internal1_m1841_q0) q0 - внутренний параметр
#define idinternal1_m1841_q0	 1425	//(internal1_m1841_q0) q0 - внутренний параметр
#define internal1_m1837_q0	 BUFFER[4479]	//(internal1_m1837_q0) q0 - внутренний параметр
#define idinternal1_m1837_q0	 1426	//(internal1_m1837_q0) q0 - внутренний параметр
#define internal1_m1839_q0	 BUFFER[4481]	//(internal1_m1839_q0) q0 - внутренний параметр
#define idinternal1_m1839_q0	 1427	//(internal1_m1839_q0) q0 - внутренний параметр
#define internal1_m1835_q0	 BUFFER[4483]	//(internal1_m1835_q0) q0 - внутренний параметр
#define idinternal1_m1835_q0	 1428	//(internal1_m1835_q0) q0 - внутренний параметр
#define internal1_m1833_q0	 BUFFER[4485]	//(internal1_m1833_q0) q0 - внутренний параметр
#define idinternal1_m1833_q0	 1429	//(internal1_m1833_q0) q0 - внутренний параметр
#define internal1_m2258_q0	 BUFFER[4487]	//(internal1_m2258_q0) q0 - внутренний параметр
#define idinternal1_m2258_q0	 1430	//(internal1_m2258_q0) q0 - внутренний параметр
#define internal1_m2255_q0	 BUFFER[4489]	//(internal1_m2255_q0) q0 - внутренний параметр
#define idinternal1_m2255_q0	 1431	//(internal1_m2255_q0) q0 - внутренний параметр
#define internal1_m2234_q0	 BUFFER[4491]	//(internal1_m2234_q0) q0 - внутренний параметр
#define idinternal1_m2234_q0	 1432	//(internal1_m2234_q0) q0 - внутренний параметр
#define internal1_m2216_q0	 BUFFER[4493]	//(internal1_m2216_q0) q0 - внутренний параметр
#define idinternal1_m2216_q0	 1433	//(internal1_m2216_q0) q0 - внутренний параметр
#define internal1_m2147_q0	 BUFFER[4495]	//(internal1_m2147_q0) q0 - внутренний параметр
#define idinternal1_m2147_q0	 1434	//(internal1_m2147_q0) q0 - внутренний параметр
#define internal1_m1829_q0	 BUFFER[4497]	//(internal1_m1829_q0) q0 - внутренний параметр
#define idinternal1_m1829_q0	 1435	//(internal1_m1829_q0) q0 - внутренний параметр
#define internal1_m1831_q0	 BUFFER[4499]	//(internal1_m1831_q0) q0 - внутренний параметр
#define idinternal1_m1831_q0	 1436	//(internal1_m1831_q0) q0 - внутренний параметр
#define internal1_m1815_q0	 BUFFER[4501]	//(internal1_m1815_q0) q0 - внутренний параметр
#define idinternal1_m1815_q0	 1437	//(internal1_m1815_q0) q0 - внутренний параметр
#define internal1_m1813_q0	 BUFFER[4503]	//(internal1_m1813_q0) q0 - внутренний параметр
#define idinternal1_m1813_q0	 1438	//(internal1_m1813_q0) q0 - внутренний параметр
#define internal1_m1811_q0	 BUFFER[4505]	//(internal1_m1811_q0) q0 - внутренний параметр
#define idinternal1_m1811_q0	 1439	//(internal1_m1811_q0) q0 - внутренний параметр
#define internal1_m1809_q0	 BUFFER[4507]	//(internal1_m1809_q0) q0 - внутренний параметр
#define idinternal1_m1809_q0	 1440	//(internal1_m1809_q0) q0 - внутренний параметр
#define internal1_m1808_q0	 BUFFER[4509]	//(internal1_m1808_q0) q0 - внутренний параметр
#define idinternal1_m1808_q0	 1441	//(internal1_m1808_q0) q0 - внутренний параметр
#define internal1_m1806_q0	 BUFFER[4511]	//(internal1_m1806_q0) q0 - внутренний параметр
#define idinternal1_m1806_q0	 1442	//(internal1_m1806_q0) q0 - внутренний параметр
#define internal1_m1805_q0	 BUFFER[4513]	//(internal1_m1805_q0) q0 - внутренний параметр
#define idinternal1_m1805_q0	 1443	//(internal1_m1805_q0) q0 - внутренний параметр
#define internal1_m1803_q0	 BUFFER[4515]	//(internal1_m1803_q0) q0 - внутренний параметр
#define idinternal1_m1803_q0	 1444	//(internal1_m1803_q0) q0 - внутренний параметр
#define internal1_m2286_DvUp0	 BUFFER[4517]	//(internal1_m2286_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2286_DvUp0	 1445	//(internal1_m2286_DvUp0) - есть команда на движение вперёд
#define internal1_m2286_DvDw0	 BUFFER[4518]	//(internal1_m2286_DvDw0) - есть команда на движение назад
#define idinternal1_m2286_DvDw0	 1446	//(internal1_m2286_DvDw0) - есть команда на движение назад
#define internal1_m2286_FDvUp0	 BUFFER[4519]	//(internal1_m2286_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2286_FDvUp0	 1447	//(internal1_m2286_FDvUp0) - есть команда на движение вперёд
#define internal1_m2286_FDvDw0	 BUFFER[4520]	//(internal1_m2286_FDvDw0) - есть команда на движение назад
#define idinternal1_m2286_FDvDw0	 1448	//(internal1_m2286_FDvDw0) - есть команда на движение назад
#define internal1_m2286_BlDv0	 BUFFER[4521]	//(internal1_m2286_BlDv0) - была блокировка
#define idinternal1_m2286_BlDv0	 1449	//(internal1_m2286_BlDv0) - была блокировка
#define internal1_m2286_Pkv0	 BUFFER[4522]	//(internal1_m2286_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2286_Pkv0	 1450	//(internal1_m2286_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2286_Pkav0	 BUFFER[4523]	//(internal1_m2286_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2286_Pkav0	 1451	//(internal1_m2286_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2286_Zkv0	 BUFFER[4524]	//(internal1_m2286_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2286_Zkv0	 1452	//(internal1_m2286_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2286_Zkav0	 BUFFER[4525]	//(internal1_m2286_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2286_Zkav0	 1453	//(internal1_m2286_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2286_txNm	 BUFFER[4526]	//(internal1_m2286_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2286_txNm	 1454	//(internal1_m2286_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2286_txSm	 BUFFER[4531]	//(internal1_m2286_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2286_txSm	 1455	//(internal1_m2286_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2286_txHr	 BUFFER[4536]	//(internal1_m2286_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2286_txHr	 1456	//(internal1_m2286_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2286_txLd	 BUFFER[4541]	//(internal1_m2286_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2286_txLd	 1457	//(internal1_m2286_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2286_fef	 BUFFER[4546]	//(internal1_m2286_fef) fef
#define idinternal1_m2286_fef	 1458	//(internal1_m2286_fef) fef
#define internal1_m2280_DvUp0	 BUFFER[4547]	//(internal1_m2280_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2280_DvUp0	 1459	//(internal1_m2280_DvUp0) - есть команда на движение вперёд
#define internal1_m2280_DvDw0	 BUFFER[4548]	//(internal1_m2280_DvDw0) - есть команда на движение назад
#define idinternal1_m2280_DvDw0	 1460	//(internal1_m2280_DvDw0) - есть команда на движение назад
#define internal1_m2280_FDvUp0	 BUFFER[4549]	//(internal1_m2280_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2280_FDvUp0	 1461	//(internal1_m2280_FDvUp0) - есть команда на движение вперёд
#define internal1_m2280_FDvDw0	 BUFFER[4550]	//(internal1_m2280_FDvDw0) - есть команда на движение назад
#define idinternal1_m2280_FDvDw0	 1462	//(internal1_m2280_FDvDw0) - есть команда на движение назад
#define internal1_m2280_BlDv0	 BUFFER[4551]	//(internal1_m2280_BlDv0) - была блокировка
#define idinternal1_m2280_BlDv0	 1463	//(internal1_m2280_BlDv0) - была блокировка
#define internal1_m2280_Pkv0	 BUFFER[4552]	//(internal1_m2280_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2280_Pkv0	 1464	//(internal1_m2280_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2280_Pkav0	 BUFFER[4553]	//(internal1_m2280_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2280_Pkav0	 1465	//(internal1_m2280_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2280_Zkv0	 BUFFER[4554]	//(internal1_m2280_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2280_Zkv0	 1466	//(internal1_m2280_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2280_Zkav0	 BUFFER[4555]	//(internal1_m2280_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2280_Zkav0	 1467	//(internal1_m2280_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2280_txNm	 BUFFER[4556]	//(internal1_m2280_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2280_txNm	 1468	//(internal1_m2280_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2280_txSm	 BUFFER[4561]	//(internal1_m2280_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2280_txSm	 1469	//(internal1_m2280_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2280_txHr	 BUFFER[4566]	//(internal1_m2280_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2280_txHr	 1470	//(internal1_m2280_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2280_txLd	 BUFFER[4571]	//(internal1_m2280_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2280_txLd	 1471	//(internal1_m2280_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2280_fef	 BUFFER[4576]	//(internal1_m2280_fef) fef
#define idinternal1_m2280_fef	 1472	//(internal1_m2280_fef) fef
#define internal1_m1644_q0	 BUFFER[4577]	//(internal1_m1644_q0) q0 - внутренний параметр
#define idinternal1_m1644_q0	 1473	//(internal1_m1644_q0) q0 - внутренний параметр
#define internal1_m1648_x0	 BUFFER[4579]	//(internal1_m1648_x0) был приход сигнала x1
#define idinternal1_m1648_x0	 1474	//(internal1_m1648_x0) был приход сигнала x1
#define internal1_m1648_y0	 BUFFER[4581]	//(internal1_m1648_y0) интервал между сигналами х1 и х2
#define idinternal1_m1648_y0	 1475	//(internal1_m1648_y0) интервал между сигналами х1 и х2
#define internal1_m2086_x0	 BUFFER[4586]	//(internal1_m2086_x0) был приход сигнала x1
#define idinternal1_m2086_x0	 1476	//(internal1_m2086_x0) был приход сигнала x1
#define internal1_m2086_y0	 BUFFER[4588]	//(internal1_m2086_y0) интервал между сигналами х1 и х2
#define idinternal1_m2086_y0	 1477	//(internal1_m2086_y0) интервал между сигналами х1 и х2
#define internal1_m2047_x0	 BUFFER[4593]	//(internal1_m2047_x0) был приход сигнала x1
#define idinternal1_m2047_x0	 1478	//(internal1_m2047_x0) был приход сигнала x1
#define internal1_m2047_y0	 BUFFER[4595]	//(internal1_m2047_y0) интервал между сигналами х1 и х2
#define idinternal1_m2047_y0	 1479	//(internal1_m2047_y0) интервал между сигналами х1 и х2
#define internal1_m298_q0	 BUFFER[4600]	//(internal1_m298_q0) q0 - внутренний параметр
#define idinternal1_m298_q0	 1480	//(internal1_m298_q0) q0 - внутренний параметр
#define internal1_m1113_q0	 BUFFER[4602]	//(internal1_m1113_q0) q0 - внутренний параметр
#define idinternal1_m1113_q0	 1481	//(internal1_m1113_q0) q0 - внутренний параметр
#define internal1_m688_q0	 BUFFER[4604]	//(internal1_m688_q0) q0 - внутренний параметр
#define idinternal1_m688_q0	 1482	//(internal1_m688_q0) q0 - внутренний параметр
#define internal1_m1450_X0	 BUFFER[4606]	//(internal1_m1450_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1450_X0	 1483	//(internal1_m1450_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1450_t0	 BUFFER[4611]	//(internal1_m1450_t0) время нахождения в зоне возврата
#define idinternal1_m1450_t0	 1484	//(internal1_m1450_t0) время нахождения в зоне возврата
#define internal1_m1450_BLDv0	 BUFFER[4616]	//(internal1_m1450_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1450_BLDv0	 1485	//(internal1_m1450_BLDv0) BlDv - Блокировка движения
#define internal1_m1467_tx	 BUFFER[4617]	//(internal1_m1467_tx) tx - время накопленное сек
#define idinternal1_m1467_tx	 1486	//(internal1_m1467_tx) tx - время накопленное сек
#define internal1_m1467_y0	 BUFFER[4622]	//(internal1_m1467_y0) y0
#define idinternal1_m1467_y0	 1487	//(internal1_m1467_y0) y0
#define internal1_m1468_tx	 BUFFER[4623]	//(internal1_m1468_tx) tx - время накопленное сек
#define idinternal1_m1468_tx	 1488	//(internal1_m1468_tx) tx - время накопленное сек
#define internal1_m1468_y0	 BUFFER[4628]	//(internal1_m1468_y0) y0
#define idinternal1_m1468_y0	 1489	//(internal1_m1468_y0) y0
#define internal1_m1476_xptr	 BUFFER[4629]	//(internal1_m1476_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1476_xptr	 1490	//(internal1_m1476_xptr) указатель текущей позиции в массиве координат
#define internal1_m1476_x0	 BUFFER[4632]	//(internal1_m1476_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1476_x0	 1491	//(internal1_m1476_x0) x0 - массив мгновенных значений координат
#define internal1_m1476_tim0	 BUFFER[4932]	//(internal1_m1476_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1476_tim0	 1492	//(internal1_m1476_tim0) tim0 - массив значений времени цикла
#define internal1_m1476_sumtim	 BUFFER[5232]	//(internal1_m1476_sumtim) sumtim - время в пути
#define idinternal1_m1476_sumtim	 1493	//(internal1_m1476_sumtim) sumtim - время в пути
#define internal1_m1476_StSpeed	 BUFFER[5237]	//(internal1_m1476_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1476_StSpeed	 1494	//(internal1_m1476_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1476_Vz0	 BUFFER[5242]	//(internal1_m1476_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1476_Vz0	 1495	//(internal1_m1476_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1476_flRazg	 BUFFER[5247]	//(internal1_m1476_flRazg) признак разгона/торможения
#define idinternal1_m1476_flRazg	 1496	//(internal1_m1476_flRazg) признак разгона/торможения
#define internal1_m1476_DelSp	 BUFFER[5250]	//(internal1_m1476_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1476_DelSp	 1497	//(internal1_m1476_DelSp) DelSp - время переключения скоростей
#define internal1_m1476_z0	 BUFFER[5255]	//(internal1_m1476_z0) z0 - точка прекращения движения
#define idinternal1_m1476_z0	 1498	//(internal1_m1476_z0) z0 - точка прекращения движения
#define internal1_m1476_txZS	 BUFFER[5260]	//(internal1_m1476_txZS) txZS
#define idinternal1_m1476_txZS	 1499	//(internal1_m1476_txZS) txZS
#define internal1_m1476_tx	 BUFFER[5265]	//(internal1_m1476_tx) tx
#define idinternal1_m1476_tx	 1500	//(internal1_m1476_tx) tx
#define internal1_m1476_txd	 BUFFER[5270]	//(internal1_m1476_txd) txd
#define idinternal1_m1476_txd	 1501	//(internal1_m1476_txd) txd
#define internal1_m1476_txMBl	 BUFFER[5275]	//(internal1_m1476_txMBl) tx
#define idinternal1_m1476_txMBl	 1502	//(internal1_m1476_txMBl) tx
#define internal1_m1476_txBl	 BUFFER[5280]	//(internal1_m1476_txBl) tx
#define idinternal1_m1476_txBl	 1503	//(internal1_m1476_txBl) tx
#define internal1_m1476_Speed0	 BUFFER[5285]	//(internal1_m1476_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1476_Speed0	 1504	//(internal1_m1476_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1476_xz0	 BUFFER[5290]	//(internal1_m1476_xz0) xz0 - новое задание мм
#define idinternal1_m1476_xz0	 1505	//(internal1_m1476_xz0) xz0 - новое задание мм
#define internal1_m1476_tz0	 BUFFER[5295]	//(internal1_m1476_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1476_tz0	 1506	//(internal1_m1476_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1476_Shift0	 BUFFER[5300]	//(internal1_m1476_Shift0) Shift0 - признак самохода
#define idinternal1_m1476_Shift0	 1507	//(internal1_m1476_Shift0) Shift0 - признак самохода
#define internal1_m1476_ShCntlSp0	 BUFFER[5302]	//(internal1_m1476_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1476_ShCntlSp0	 1508	//(internal1_m1476_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1476_ShiftControl	 BUFFER[5304]	//(internal1_m1476_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1476_ShiftControl	 1509	//(internal1_m1476_ShiftControl) ShiftControl - признак самохода
#define internal1_m686_q0	 BUFFER[5306]	//(internal1_m686_q0) q0 - внутренний параметр
#define idinternal1_m686_q0	 1510	//(internal1_m686_q0) q0 - внутренний параметр
#define internal1_m994_X0	 BUFFER[5308]	//(internal1_m994_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m994_X0	 1511	//(internal1_m994_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m994_t0	 BUFFER[5313]	//(internal1_m994_t0) время нахождения в зоне возврата
#define idinternal1_m994_t0	 1512	//(internal1_m994_t0) время нахождения в зоне возврата
#define internal1_m994_BLDv0	 BUFFER[5318]	//(internal1_m994_BLDv0) BlDv - Блокировка движения
#define idinternal1_m994_BLDv0	 1513	//(internal1_m994_BLDv0) BlDv - Блокировка движения
#define internal1_m1017_tx	 BUFFER[5319]	//(internal1_m1017_tx) tx - время накопленное сек
#define idinternal1_m1017_tx	 1514	//(internal1_m1017_tx) tx - время накопленное сек
#define internal1_m1017_y0	 BUFFER[5324]	//(internal1_m1017_y0) y0
#define idinternal1_m1017_y0	 1515	//(internal1_m1017_y0) y0
#define internal1_m1016_tx	 BUFFER[5325]	//(internal1_m1016_tx) tx - время накопленное сек
#define idinternal1_m1016_tx	 1516	//(internal1_m1016_tx) tx - время накопленное сек
#define internal1_m1016_y0	 BUFFER[5330]	//(internal1_m1016_y0) y0
#define idinternal1_m1016_y0	 1517	//(internal1_m1016_y0) y0
#define internal1_m1024_xptr	 BUFFER[5331]	//(internal1_m1024_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1024_xptr	 1518	//(internal1_m1024_xptr) указатель текущей позиции в массиве координат
#define internal1_m1024_x0	 BUFFER[5334]	//(internal1_m1024_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1024_x0	 1519	//(internal1_m1024_x0) x0 - массив мгновенных значений координат
#define internal1_m1024_tim0	 BUFFER[5634]	//(internal1_m1024_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1024_tim0	 1520	//(internal1_m1024_tim0) tim0 - массив значений времени цикла
#define internal1_m1024_sumtim	 BUFFER[5934]	//(internal1_m1024_sumtim) sumtim - время в пути
#define idinternal1_m1024_sumtim	 1521	//(internal1_m1024_sumtim) sumtim - время в пути
#define internal1_m1024_StSpeed	 BUFFER[5939]	//(internal1_m1024_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1024_StSpeed	 1522	//(internal1_m1024_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1024_Vz0	 BUFFER[5944]	//(internal1_m1024_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1024_Vz0	 1523	//(internal1_m1024_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1024_flRazg	 BUFFER[5949]	//(internal1_m1024_flRazg) признак разгона/торможения
#define idinternal1_m1024_flRazg	 1524	//(internal1_m1024_flRazg) признак разгона/торможения
#define internal1_m1024_DelSp	 BUFFER[5952]	//(internal1_m1024_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1024_DelSp	 1525	//(internal1_m1024_DelSp) DelSp - время переключения скоростей
#define internal1_m1024_z0	 BUFFER[5957]	//(internal1_m1024_z0) z0 - точка прекращения движения
#define idinternal1_m1024_z0	 1526	//(internal1_m1024_z0) z0 - точка прекращения движения
#define internal1_m1024_txZS	 BUFFER[5962]	//(internal1_m1024_txZS) txZS
#define idinternal1_m1024_txZS	 1527	//(internal1_m1024_txZS) txZS
#define internal1_m1024_tx	 BUFFER[5967]	//(internal1_m1024_tx) tx
#define idinternal1_m1024_tx	 1528	//(internal1_m1024_tx) tx
#define internal1_m1024_txd	 BUFFER[5972]	//(internal1_m1024_txd) txd
#define idinternal1_m1024_txd	 1529	//(internal1_m1024_txd) txd
#define internal1_m1024_txMBl	 BUFFER[5977]	//(internal1_m1024_txMBl) tx
#define idinternal1_m1024_txMBl	 1530	//(internal1_m1024_txMBl) tx
#define internal1_m1024_txBl	 BUFFER[5982]	//(internal1_m1024_txBl) tx
#define idinternal1_m1024_txBl	 1531	//(internal1_m1024_txBl) tx
#define internal1_m1024_Speed0	 BUFFER[5987]	//(internal1_m1024_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1024_Speed0	 1532	//(internal1_m1024_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1024_xz0	 BUFFER[5992]	//(internal1_m1024_xz0) xz0 - новое задание мм
#define idinternal1_m1024_xz0	 1533	//(internal1_m1024_xz0) xz0 - новое задание мм
#define internal1_m1024_tz0	 BUFFER[5997]	//(internal1_m1024_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1024_tz0	 1534	//(internal1_m1024_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1024_Shift0	 BUFFER[6002]	//(internal1_m1024_Shift0) Shift0 - признак самохода
#define idinternal1_m1024_Shift0	 1535	//(internal1_m1024_Shift0) Shift0 - признак самохода
#define internal1_m1024_ShCntlSp0	 BUFFER[6004]	//(internal1_m1024_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1024_ShCntlSp0	 1536	//(internal1_m1024_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1024_ShiftControl	 BUFFER[6006]	//(internal1_m1024_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1024_ShiftControl	 1537	//(internal1_m1024_ShiftControl) ShiftControl - признак самохода
#define internal1_m539_X0	 BUFFER[6008]	//(internal1_m539_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m539_X0	 1538	//(internal1_m539_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m539_t0	 BUFFER[6013]	//(internal1_m539_t0) время нахождения в зоне возврата
#define idinternal1_m539_t0	 1539	//(internal1_m539_t0) время нахождения в зоне возврата
#define internal1_m539_BLDv0	 BUFFER[6018]	//(internal1_m539_BLDv0) BlDv - Блокировка движения
#define idinternal1_m539_BLDv0	 1540	//(internal1_m539_BLDv0) BlDv - Блокировка движения
#define internal1_m558_tx	 BUFFER[6019]	//(internal1_m558_tx) tx - время накопленное сек
#define idinternal1_m558_tx	 1541	//(internal1_m558_tx) tx - время накопленное сек
#define internal1_m558_y0	 BUFFER[6024]	//(internal1_m558_y0) y0
#define idinternal1_m558_y0	 1542	//(internal1_m558_y0) y0
#define internal1_m557_tx	 BUFFER[6025]	//(internal1_m557_tx) tx - время накопленное сек
#define idinternal1_m557_tx	 1543	//(internal1_m557_tx) tx - время накопленное сек
#define internal1_m557_y0	 BUFFER[6030]	//(internal1_m557_y0) y0
#define idinternal1_m557_y0	 1544	//(internal1_m557_y0) y0
#define internal1_m562_xptr	 BUFFER[6031]	//(internal1_m562_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m562_xptr	 1545	//(internal1_m562_xptr) указатель текущей позиции в массиве координат
#define internal1_m562_x0	 BUFFER[6034]	//(internal1_m562_x0) x0 - массив мгновенных значений координат
#define idinternal1_m562_x0	 1546	//(internal1_m562_x0) x0 - массив мгновенных значений координат
#define internal1_m562_tim0	 BUFFER[6784]	//(internal1_m562_tim0) tim0 - массив значений времени цикла
#define idinternal1_m562_tim0	 1547	//(internal1_m562_tim0) tim0 - массив значений времени цикла
#define internal1_m562_sumtim	 BUFFER[7534]	//(internal1_m562_sumtim) sumtim - время в пути
#define idinternal1_m562_sumtim	 1548	//(internal1_m562_sumtim) sumtim - время в пути
#define internal1_m562_StSpeed	 BUFFER[7539]	//(internal1_m562_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m562_StSpeed	 1549	//(internal1_m562_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m562_Vz0	 BUFFER[7544]	//(internal1_m562_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m562_Vz0	 1550	//(internal1_m562_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m562_flRazg	 BUFFER[7549]	//(internal1_m562_flRazg) признак разгона/торможения
#define idinternal1_m562_flRazg	 1551	//(internal1_m562_flRazg) признак разгона/торможения
#define internal1_m562_DelSp	 BUFFER[7552]	//(internal1_m562_DelSp) DelSp - время переключения скоростей
#define idinternal1_m562_DelSp	 1552	//(internal1_m562_DelSp) DelSp - время переключения скоростей
#define internal1_m562_z0	 BUFFER[7557]	//(internal1_m562_z0) z0 - точка прекращения движения
#define idinternal1_m562_z0	 1553	//(internal1_m562_z0) z0 - точка прекращения движения
#define internal1_m562_txZS	 BUFFER[7562]	//(internal1_m562_txZS) txZS
#define idinternal1_m562_txZS	 1554	//(internal1_m562_txZS) txZS
#define internal1_m562_tx	 BUFFER[7567]	//(internal1_m562_tx) tx
#define idinternal1_m562_tx	 1555	//(internal1_m562_tx) tx
#define internal1_m562_txd	 BUFFER[7572]	//(internal1_m562_txd) txd
#define idinternal1_m562_txd	 1556	//(internal1_m562_txd) txd
#define internal1_m562_txMBl	 BUFFER[7577]	//(internal1_m562_txMBl) tx
#define idinternal1_m562_txMBl	 1557	//(internal1_m562_txMBl) tx
#define internal1_m562_txBl	 BUFFER[7582]	//(internal1_m562_txBl) tx
#define idinternal1_m562_txBl	 1558	//(internal1_m562_txBl) tx
#define internal1_m562_Speed0	 BUFFER[7587]	//(internal1_m562_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m562_Speed0	 1559	//(internal1_m562_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m562_xz0	 BUFFER[7592]	//(internal1_m562_xz0) xz0 - новое задание мм
#define idinternal1_m562_xz0	 1560	//(internal1_m562_xz0) xz0 - новое задание мм
#define internal1_m562_tz0	 BUFFER[7597]	//(internal1_m562_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m562_tz0	 1561	//(internal1_m562_tz0) tz0 - время защиты от нового задания сек
#define internal1_m562_Shift0	 BUFFER[7602]	//(internal1_m562_Shift0) Shift0 - признак самохода
#define idinternal1_m562_Shift0	 1562	//(internal1_m562_Shift0) Shift0 - признак самохода
#define internal1_m562_ShCntlSp0	 BUFFER[7604]	//(internal1_m562_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m562_ShCntlSp0	 1563	//(internal1_m562_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m562_ShiftControl	 BUFFER[7606]	//(internal1_m562_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m562_ShiftControl	 1564	//(internal1_m562_ShiftControl) ShiftControl - признак самохода
#define internal1_m683_q0	 BUFFER[7608]	//(internal1_m683_q0) q0 - внутренний параметр
#define idinternal1_m683_q0	 1565	//(internal1_m683_q0) q0 - внутренний параметр
#define internal1_m169_X0	 BUFFER[7610]	//(internal1_m169_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m169_X0	 1566	//(internal1_m169_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m169_t0	 BUFFER[7615]	//(internal1_m169_t0) время нахождения в зоне возврата
#define idinternal1_m169_t0	 1567	//(internal1_m169_t0) время нахождения в зоне возврата
#define internal1_m169_BLDv0	 BUFFER[7620]	//(internal1_m169_BLDv0) BlDv - Блокировка движения
#define idinternal1_m169_BLDv0	 1568	//(internal1_m169_BLDv0) BlDv - Блокировка движения
#define internal1_m194_xptr	 BUFFER[7621]	//(internal1_m194_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m194_xptr	 1569	//(internal1_m194_xptr) указатель текущей позиции в массиве координат
#define internal1_m194_x0	 BUFFER[7624]	//(internal1_m194_x0) x0 - массив мгновенных значений координат
#define idinternal1_m194_x0	 1570	//(internal1_m194_x0) x0 - массив мгновенных значений координат
#define internal1_m194_tim0	 BUFFER[8374]	//(internal1_m194_tim0) tim0 - массив значений времени цикла
#define idinternal1_m194_tim0	 1571	//(internal1_m194_tim0) tim0 - массив значений времени цикла
#define internal1_m194_sumtim	 BUFFER[9124]	//(internal1_m194_sumtim) sumtim - время в пути
#define idinternal1_m194_sumtim	 1572	//(internal1_m194_sumtim) sumtim - время в пути
#define internal1_m194_StSpeed	 BUFFER[9129]	//(internal1_m194_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m194_StSpeed	 1573	//(internal1_m194_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m194_Vz0	 BUFFER[9134]	//(internal1_m194_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m194_Vz0	 1574	//(internal1_m194_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m194_flRazg	 BUFFER[9139]	//(internal1_m194_flRazg) признак разгона/торможения
#define idinternal1_m194_flRazg	 1575	//(internal1_m194_flRazg) признак разгона/торможения
#define internal1_m194_DelSp	 BUFFER[9142]	//(internal1_m194_DelSp) DelSp - время переключения скоростей
#define idinternal1_m194_DelSp	 1576	//(internal1_m194_DelSp) DelSp - время переключения скоростей
#define internal1_m194_z0	 BUFFER[9147]	//(internal1_m194_z0) z0 - точка прекращения движения
#define idinternal1_m194_z0	 1577	//(internal1_m194_z0) z0 - точка прекращения движения
#define internal1_m194_txZS	 BUFFER[9152]	//(internal1_m194_txZS) txZS
#define idinternal1_m194_txZS	 1578	//(internal1_m194_txZS) txZS
#define internal1_m194_tx	 BUFFER[9157]	//(internal1_m194_tx) tx
#define idinternal1_m194_tx	 1579	//(internal1_m194_tx) tx
#define internal1_m194_txd	 BUFFER[9162]	//(internal1_m194_txd) txd
#define idinternal1_m194_txd	 1580	//(internal1_m194_txd) txd
#define internal1_m194_txMBl	 BUFFER[9167]	//(internal1_m194_txMBl) tx
#define idinternal1_m194_txMBl	 1581	//(internal1_m194_txMBl) tx
#define internal1_m194_txBl	 BUFFER[9172]	//(internal1_m194_txBl) tx
#define idinternal1_m194_txBl	 1582	//(internal1_m194_txBl) tx
#define internal1_m194_Speed0	 BUFFER[9177]	//(internal1_m194_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m194_Speed0	 1583	//(internal1_m194_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m194_xz0	 BUFFER[9182]	//(internal1_m194_xz0) xz0 - новое задание мм
#define idinternal1_m194_xz0	 1584	//(internal1_m194_xz0) xz0 - новое задание мм
#define internal1_m194_tz0	 BUFFER[9187]	//(internal1_m194_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m194_tz0	 1585	//(internal1_m194_tz0) tz0 - время защиты от нового задания сек
#define internal1_m194_Shift0	 BUFFER[9192]	//(internal1_m194_Shift0) Shift0 - признак самохода
#define idinternal1_m194_Shift0	 1586	//(internal1_m194_Shift0) Shift0 - признак самохода
#define internal1_m194_ShCntlSp0	 BUFFER[9194]	//(internal1_m194_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m194_ShCntlSp0	 1587	//(internal1_m194_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m194_ShiftControl	 BUFFER[9196]	//(internal1_m194_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m194_ShiftControl	 1588	//(internal1_m194_ShiftControl) ShiftControl - признак самохода
#define internal1_m709_q0	 BUFFER[9198]	//(internal1_m709_q0) q0 - внутренний параметр
#define idinternal1_m709_q0	 1589	//(internal1_m709_q0) q0 - внутренний параметр
#define internal1_m506_DvUp0	 BUFFER[9200]	//(internal1_m506_DvUp0) - есть команда на движение вперёд
#define idinternal1_m506_DvUp0	 1590	//(internal1_m506_DvUp0) - есть команда на движение вперёд
#define internal1_m506_DvDw0	 BUFFER[9201]	//(internal1_m506_DvDw0) - есть команда на движение назад
#define idinternal1_m506_DvDw0	 1591	//(internal1_m506_DvDw0) - есть команда на движение назад
#define internal1_m506_FDvUp0	 BUFFER[9202]	//(internal1_m506_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m506_FDvUp0	 1592	//(internal1_m506_FDvUp0) - есть команда на движение вперёд
#define internal1_m506_FDvDw0	 BUFFER[9203]	//(internal1_m506_FDvDw0) - есть команда на движение назад
#define idinternal1_m506_FDvDw0	 1593	//(internal1_m506_FDvDw0) - есть команда на движение назад
#define internal1_m506_BlDv0	 BUFFER[9204]	//(internal1_m506_BlDv0) - была блокировка
#define idinternal1_m506_BlDv0	 1594	//(internal1_m506_BlDv0) - была блокировка
#define internal1_m506_Pkv0	 BUFFER[9205]	//(internal1_m506_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m506_Pkv0	 1595	//(internal1_m506_Pkv0) Pkv - передний конечный выключатель
#define internal1_m506_Pkav0	 BUFFER[9206]	//(internal1_m506_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m506_Pkav0	 1596	//(internal1_m506_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m506_Zkv0	 BUFFER[9207]	//(internal1_m506_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m506_Zkv0	 1597	//(internal1_m506_Zkv0) Zkv - задний конечный выключатель
#define internal1_m506_Zkav0	 BUFFER[9208]	//(internal1_m506_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m506_Zkav0	 1598	//(internal1_m506_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m506_txNm	 BUFFER[9209]	//(internal1_m506_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m506_txNm	 1599	//(internal1_m506_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m506_txSm	 BUFFER[9214]	//(internal1_m506_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m506_txSm	 1600	//(internal1_m506_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m506_txHr	 BUFFER[9219]	//(internal1_m506_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m506_txHr	 1601	//(internal1_m506_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m506_txLd	 BUFFER[9224]	//(internal1_m506_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m506_txLd	 1602	//(internal1_m506_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m506_fef	 BUFFER[9229]	//(internal1_m506_fef) fef
#define idinternal1_m506_fef	 1603	//(internal1_m506_fef) fef
#define internal1_m500_DvUp0	 BUFFER[9230]	//(internal1_m500_DvUp0) - есть команда на движение вперёд
#define idinternal1_m500_DvUp0	 1604	//(internal1_m500_DvUp0) - есть команда на движение вперёд
#define internal1_m500_DvDw0	 BUFFER[9231]	//(internal1_m500_DvDw0) - есть команда на движение назад
#define idinternal1_m500_DvDw0	 1605	//(internal1_m500_DvDw0) - есть команда на движение назад
#define internal1_m500_FDvUp0	 BUFFER[9232]	//(internal1_m500_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m500_FDvUp0	 1606	//(internal1_m500_FDvUp0) - есть команда на движение вперёд
#define internal1_m500_FDvDw0	 BUFFER[9233]	//(internal1_m500_FDvDw0) - есть команда на движение назад
#define idinternal1_m500_FDvDw0	 1607	//(internal1_m500_FDvDw0) - есть команда на движение назад
#define internal1_m500_BlDv0	 BUFFER[9234]	//(internal1_m500_BlDv0) - была блокировка
#define idinternal1_m500_BlDv0	 1608	//(internal1_m500_BlDv0) - была блокировка
#define internal1_m500_Pkv0	 BUFFER[9235]	//(internal1_m500_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m500_Pkv0	 1609	//(internal1_m500_Pkv0) Pkv - передний конечный выключатель
#define internal1_m500_Pkav0	 BUFFER[9236]	//(internal1_m500_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m500_Pkav0	 1610	//(internal1_m500_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m500_Zkv0	 BUFFER[9237]	//(internal1_m500_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m500_Zkv0	 1611	//(internal1_m500_Zkv0) Zkv - задний конечный выключатель
#define internal1_m500_Zkav0	 BUFFER[9238]	//(internal1_m500_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m500_Zkav0	 1612	//(internal1_m500_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m500_txNm	 BUFFER[9239]	//(internal1_m500_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m500_txNm	 1613	//(internal1_m500_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m500_txSm	 BUFFER[9244]	//(internal1_m500_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m500_txSm	 1614	//(internal1_m500_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m500_txHr	 BUFFER[9249]	//(internal1_m500_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m500_txHr	 1615	//(internal1_m500_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m500_txLd	 BUFFER[9254]	//(internal1_m500_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m500_txLd	 1616	//(internal1_m500_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m500_fef	 BUFFER[9259]	//(internal1_m500_fef) fef
#define idinternal1_m500_fef	 1617	//(internal1_m500_fef) fef
#define internal1_m898_X0	 BUFFER[9260]	//(internal1_m898_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m898_X0	 1618	//(internal1_m898_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m898_t0	 BUFFER[9265]	//(internal1_m898_t0) время нахождения в зоне возврата
#define idinternal1_m898_t0	 1619	//(internal1_m898_t0) время нахождения в зоне возврата
#define internal1_m898_BLDv0	 BUFFER[9270]	//(internal1_m898_BLDv0) BlDv - Блокировка движения
#define idinternal1_m898_BLDv0	 1620	//(internal1_m898_BLDv0) BlDv - Блокировка движения
#define internal1_m916_xptr	 BUFFER[9271]	//(internal1_m916_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m916_xptr	 1621	//(internal1_m916_xptr) указатель текущей позиции в массиве координат
#define internal1_m916_x0	 BUFFER[9274]	//(internal1_m916_x0) x0 - массив мгновенных значений координат
#define idinternal1_m916_x0	 1622	//(internal1_m916_x0) x0 - массив мгновенных значений координат
#define internal1_m916_tim0	 BUFFER[9674]	//(internal1_m916_tim0) tim0 - массив значений времени цикла
#define idinternal1_m916_tim0	 1623	//(internal1_m916_tim0) tim0 - массив значений времени цикла
#define internal1_m916_sumtim	 BUFFER[10074]	//(internal1_m916_sumtim) sumtim - время в пути
#define idinternal1_m916_sumtim	 1624	//(internal1_m916_sumtim) sumtim - время в пути
#define internal1_m916_StSpeed	 BUFFER[10079]	//(internal1_m916_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m916_StSpeed	 1625	//(internal1_m916_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m916_Vz0	 BUFFER[10084]	//(internal1_m916_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m916_Vz0	 1626	//(internal1_m916_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m916_flRazg	 BUFFER[10089]	//(internal1_m916_flRazg) признак разгона/торможения
#define idinternal1_m916_flRazg	 1627	//(internal1_m916_flRazg) признак разгона/торможения
#define internal1_m916_DelSp	 BUFFER[10092]	//(internal1_m916_DelSp) DelSp - время переключения скоростей
#define idinternal1_m916_DelSp	 1628	//(internal1_m916_DelSp) DelSp - время переключения скоростей
#define internal1_m916_z0	 BUFFER[10097]	//(internal1_m916_z0) z0 - точка прекращения движения
#define idinternal1_m916_z0	 1629	//(internal1_m916_z0) z0 - точка прекращения движения
#define internal1_m916_txZS	 BUFFER[10102]	//(internal1_m916_txZS) txZS
#define idinternal1_m916_txZS	 1630	//(internal1_m916_txZS) txZS
#define internal1_m916_tx	 BUFFER[10107]	//(internal1_m916_tx) tx
#define idinternal1_m916_tx	 1631	//(internal1_m916_tx) tx
#define internal1_m916_txd	 BUFFER[10112]	//(internal1_m916_txd) txd
#define idinternal1_m916_txd	 1632	//(internal1_m916_txd) txd
#define internal1_m916_txMBl	 BUFFER[10117]	//(internal1_m916_txMBl) tx
#define idinternal1_m916_txMBl	 1633	//(internal1_m916_txMBl) tx
#define internal1_m916_txBl	 BUFFER[10122]	//(internal1_m916_txBl) tx
#define idinternal1_m916_txBl	 1634	//(internal1_m916_txBl) tx
#define internal1_m916_Speed0	 BUFFER[10127]	//(internal1_m916_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m916_Speed0	 1635	//(internal1_m916_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m916_xz0	 BUFFER[10132]	//(internal1_m916_xz0) xz0 - новое задание мм
#define idinternal1_m916_xz0	 1636	//(internal1_m916_xz0) xz0 - новое задание мм
#define internal1_m916_tz0	 BUFFER[10137]	//(internal1_m916_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m916_tz0	 1637	//(internal1_m916_tz0) tz0 - время защиты от нового задания сек
#define internal1_m916_Shift0	 BUFFER[10142]	//(internal1_m916_Shift0) Shift0 - признак самохода
#define idinternal1_m916_Shift0	 1638	//(internal1_m916_Shift0) Shift0 - признак самохода
#define internal1_m916_ShCntlSp0	 BUFFER[10144]	//(internal1_m916_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m916_ShCntlSp0	 1639	//(internal1_m916_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m916_ShiftControl	 BUFFER[10146]	//(internal1_m916_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m916_ShiftControl	 1640	//(internal1_m916_ShiftControl) ShiftControl - признак самохода
#define internal1_m1757_X0	 BUFFER[10148]	//(internal1_m1757_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1757_X0	 1641	//(internal1_m1757_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1757_t0	 BUFFER[10153]	//(internal1_m1757_t0) время нахождения в зоне возврата
#define idinternal1_m1757_t0	 1642	//(internal1_m1757_t0) время нахождения в зоне возврата
#define internal1_m1757_BLDv0	 BUFFER[10158]	//(internal1_m1757_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1757_BLDv0	 1643	//(internal1_m1757_BLDv0) BlDv - Блокировка движения
#define internal1_m1242_X0	 BUFFER[10159]	//(internal1_m1242_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1242_X0	 1644	//(internal1_m1242_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1242_t0	 BUFFER[10164]	//(internal1_m1242_t0) время нахождения в зоне возврата
#define idinternal1_m1242_t0	 1645	//(internal1_m1242_t0) время нахождения в зоне возврата
#define internal1_m1242_BLDv0	 BUFFER[10169]	//(internal1_m1242_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1242_BLDv0	 1646	//(internal1_m1242_BLDv0) BlDv - Блокировка движения
#define internal1_m681_q0	 BUFFER[10170]	//(internal1_m681_q0) q0 - внутренний параметр
#define idinternal1_m681_q0	 1647	//(internal1_m681_q0) q0 - внутренний параметр
#define internal1_m1337_X0	 BUFFER[10172]	//(internal1_m1337_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1337_X0	 1648	//(internal1_m1337_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1337_t0	 BUFFER[10177]	//(internal1_m1337_t0) время нахождения в зоне возврата
#define idinternal1_m1337_t0	 1649	//(internal1_m1337_t0) время нахождения в зоне возврата
#define internal1_m1337_BLDv0	 BUFFER[10182]	//(internal1_m1337_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1337_BLDv0	 1650	//(internal1_m1337_BLDv0) BlDv - Блокировка движения
#define internal1_m1366_tx	 BUFFER[10183]	//(internal1_m1366_tx) tx - время накопленное сек
#define idinternal1_m1366_tx	 1651	//(internal1_m1366_tx) tx - время накопленное сек
#define internal1_m1366_y0	 BUFFER[10188]	//(internal1_m1366_y0) y0
#define idinternal1_m1366_y0	 1652	//(internal1_m1366_y0) y0
#define internal1_m1365_tx	 BUFFER[10189]	//(internal1_m1365_tx) tx - время накопленное сек
#define idinternal1_m1365_tx	 1653	//(internal1_m1365_tx) tx - время накопленное сек
#define internal1_m1365_y0	 BUFFER[10194]	//(internal1_m1365_y0) y0
#define idinternal1_m1365_y0	 1654	//(internal1_m1365_y0) y0
#define internal1_m1372_xptr	 BUFFER[10195]	//(internal1_m1372_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1372_xptr	 1655	//(internal1_m1372_xptr) указатель текущей позиции в массиве координат
#define internal1_m1372_x0	 BUFFER[10198]	//(internal1_m1372_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1372_x0	 1656	//(internal1_m1372_x0) x0 - массив мгновенных значений координат
#define internal1_m1372_tim0	 BUFFER[10598]	//(internal1_m1372_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1372_tim0	 1657	//(internal1_m1372_tim0) tim0 - массив значений времени цикла
#define internal1_m1372_sumtim	 BUFFER[10998]	//(internal1_m1372_sumtim) sumtim - время в пути
#define idinternal1_m1372_sumtim	 1658	//(internal1_m1372_sumtim) sumtim - время в пути
#define internal1_m1372_StSpeed	 BUFFER[11003]	//(internal1_m1372_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1372_StSpeed	 1659	//(internal1_m1372_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1372_Vz0	 BUFFER[11008]	//(internal1_m1372_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1372_Vz0	 1660	//(internal1_m1372_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1372_flRazg	 BUFFER[11013]	//(internal1_m1372_flRazg) признак разгона/торможения
#define idinternal1_m1372_flRazg	 1661	//(internal1_m1372_flRazg) признак разгона/торможения
#define internal1_m1372_DelSp	 BUFFER[11016]	//(internal1_m1372_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1372_DelSp	 1662	//(internal1_m1372_DelSp) DelSp - время переключения скоростей
#define internal1_m1372_z0	 BUFFER[11021]	//(internal1_m1372_z0) z0 - точка прекращения движения
#define idinternal1_m1372_z0	 1663	//(internal1_m1372_z0) z0 - точка прекращения движения
#define internal1_m1372_txZS	 BUFFER[11026]	//(internal1_m1372_txZS) txZS
#define idinternal1_m1372_txZS	 1664	//(internal1_m1372_txZS) txZS
#define internal1_m1372_tx	 BUFFER[11031]	//(internal1_m1372_tx) tx
#define idinternal1_m1372_tx	 1665	//(internal1_m1372_tx) tx
#define internal1_m1372_txd	 BUFFER[11036]	//(internal1_m1372_txd) txd
#define idinternal1_m1372_txd	 1666	//(internal1_m1372_txd) txd
#define internal1_m1372_txMBl	 BUFFER[11041]	//(internal1_m1372_txMBl) tx
#define idinternal1_m1372_txMBl	 1667	//(internal1_m1372_txMBl) tx
#define internal1_m1372_txBl	 BUFFER[11046]	//(internal1_m1372_txBl) tx
#define idinternal1_m1372_txBl	 1668	//(internal1_m1372_txBl) tx
#define internal1_m1372_Speed0	 BUFFER[11051]	//(internal1_m1372_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1372_Speed0	 1669	//(internal1_m1372_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1372_xz0	 BUFFER[11056]	//(internal1_m1372_xz0) xz0 - новое задание мм
#define idinternal1_m1372_xz0	 1670	//(internal1_m1372_xz0) xz0 - новое задание мм
#define internal1_m1372_tz0	 BUFFER[11061]	//(internal1_m1372_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1372_tz0	 1671	//(internal1_m1372_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1372_Shift0	 BUFFER[11066]	//(internal1_m1372_Shift0) Shift0 - признак самохода
#define idinternal1_m1372_Shift0	 1672	//(internal1_m1372_Shift0) Shift0 - признак самохода
#define internal1_m1372_ShCntlSp0	 BUFFER[11068]	//(internal1_m1372_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1372_ShCntlSp0	 1673	//(internal1_m1372_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1372_ShiftControl	 BUFFER[11070]	//(internal1_m1372_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1372_ShiftControl	 1674	//(internal1_m1372_ShiftControl) ShiftControl - признак самохода
#define internal1_m701_q0	 BUFFER[11072]	//(internal1_m701_q0) q0 - внутренний параметр
#define idinternal1_m701_q0	 1675	//(internal1_m701_q0) q0 - внутренний параметр
#define internal1_m1771_tx	 BUFFER[11074]	//(internal1_m1771_tx) tx - время накопленное сек
#define idinternal1_m1771_tx	 1676	//(internal1_m1771_tx) tx - время накопленное сек
#define internal1_m1771_y0	 BUFFER[11079]	//(internal1_m1771_y0) y0
#define idinternal1_m1771_y0	 1677	//(internal1_m1771_y0) y0
#define internal1_m1775_tx	 BUFFER[11080]	//(internal1_m1775_tx) tx - время накопленное сек
#define idinternal1_m1775_tx	 1678	//(internal1_m1775_tx) tx - время накопленное сек
#define internal1_m1775_y0	 BUFFER[11085]	//(internal1_m1775_y0) y0
#define idinternal1_m1775_y0	 1679	//(internal1_m1775_y0) y0
#define internal1_m1760_DvUp0	 BUFFER[11086]	//(internal1_m1760_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1760_DvUp0	 1680	//(internal1_m1760_DvUp0) - есть команда на движение вперёд
#define internal1_m1760_DvDw0	 BUFFER[11087]	//(internal1_m1760_DvDw0) - есть команда на движение назад
#define idinternal1_m1760_DvDw0	 1681	//(internal1_m1760_DvDw0) - есть команда на движение назад
#define internal1_m1760_FDvUp0	 BUFFER[11088]	//(internal1_m1760_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1760_FDvUp0	 1682	//(internal1_m1760_FDvUp0) - есть команда на движение вперёд
#define internal1_m1760_FDvDw0	 BUFFER[11089]	//(internal1_m1760_FDvDw0) - есть команда на движение назад
#define idinternal1_m1760_FDvDw0	 1683	//(internal1_m1760_FDvDw0) - есть команда на движение назад
#define internal1_m1760_BlDv0	 BUFFER[11090]	//(internal1_m1760_BlDv0) - была блокировка
#define idinternal1_m1760_BlDv0	 1684	//(internal1_m1760_BlDv0) - была блокировка
#define internal1_m1760_Pkv0	 BUFFER[11091]	//(internal1_m1760_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1760_Pkv0	 1685	//(internal1_m1760_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1760_Pkav0	 BUFFER[11092]	//(internal1_m1760_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1760_Pkav0	 1686	//(internal1_m1760_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1760_Zkv0	 BUFFER[11093]	//(internal1_m1760_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1760_Zkv0	 1687	//(internal1_m1760_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1760_Zkav0	 BUFFER[11094]	//(internal1_m1760_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1760_Zkav0	 1688	//(internal1_m1760_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1760_txNm	 BUFFER[11095]	//(internal1_m1760_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1760_txNm	 1689	//(internal1_m1760_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1760_txSm	 BUFFER[11100]	//(internal1_m1760_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1760_txSm	 1690	//(internal1_m1760_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1760_txHr	 BUFFER[11105]	//(internal1_m1760_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1760_txHr	 1691	//(internal1_m1760_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1760_txLd	 BUFFER[11110]	//(internal1_m1760_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1760_txLd	 1692	//(internal1_m1760_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1760_fef	 BUFFER[11115]	//(internal1_m1760_fef) fef
#define idinternal1_m1760_fef	 1693	//(internal1_m1760_fef) fef
#define internal1_m1779_xptr	 BUFFER[11116]	//(internal1_m1779_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1779_xptr	 1694	//(internal1_m1779_xptr) указатель текущей позиции в массиве координат
#define internal1_m1779_x0	 BUFFER[11119]	//(internal1_m1779_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1779_x0	 1695	//(internal1_m1779_x0) x0 - массив мгновенных значений координат
#define internal1_m1779_tim0	 BUFFER[11219]	//(internal1_m1779_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1779_tim0	 1696	//(internal1_m1779_tim0) tim0 - массив значений времени цикла
#define internal1_m1779_sumtim	 BUFFER[11319]	//(internal1_m1779_sumtim) sumtim - время в пути
#define idinternal1_m1779_sumtim	 1697	//(internal1_m1779_sumtim) sumtim - время в пути
#define internal1_m1779_StSpeed	 BUFFER[11324]	//(internal1_m1779_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1779_StSpeed	 1698	//(internal1_m1779_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1779_Vz0	 BUFFER[11329]	//(internal1_m1779_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1779_Vz0	 1699	//(internal1_m1779_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1779_flRazg	 BUFFER[11334]	//(internal1_m1779_flRazg) признак разгона/торможения
#define idinternal1_m1779_flRazg	 1700	//(internal1_m1779_flRazg) признак разгона/торможения
#define internal1_m1779_DelSp	 BUFFER[11337]	//(internal1_m1779_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1779_DelSp	 1701	//(internal1_m1779_DelSp) DelSp - время переключения скоростей
#define internal1_m1779_z0	 BUFFER[11342]	//(internal1_m1779_z0) z0 - точка прекращения движения
#define idinternal1_m1779_z0	 1702	//(internal1_m1779_z0) z0 - точка прекращения движения
#define internal1_m1779_txZS	 BUFFER[11347]	//(internal1_m1779_txZS) txZS
#define idinternal1_m1779_txZS	 1703	//(internal1_m1779_txZS) txZS
#define internal1_m1779_tx	 BUFFER[11352]	//(internal1_m1779_tx) tx
#define idinternal1_m1779_tx	 1704	//(internal1_m1779_tx) tx
#define internal1_m1779_txd	 BUFFER[11357]	//(internal1_m1779_txd) txd
#define idinternal1_m1779_txd	 1705	//(internal1_m1779_txd) txd
#define internal1_m1779_txMBl	 BUFFER[11362]	//(internal1_m1779_txMBl) tx
#define idinternal1_m1779_txMBl	 1706	//(internal1_m1779_txMBl) tx
#define internal1_m1779_txBl	 BUFFER[11367]	//(internal1_m1779_txBl) tx
#define idinternal1_m1779_txBl	 1707	//(internal1_m1779_txBl) tx
#define internal1_m1779_Speed0	 BUFFER[11372]	//(internal1_m1779_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1779_Speed0	 1708	//(internal1_m1779_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1779_xz0	 BUFFER[11377]	//(internal1_m1779_xz0) xz0 - новое задание мм
#define idinternal1_m1779_xz0	 1709	//(internal1_m1779_xz0) xz0 - новое задание мм
#define internal1_m1779_tz0	 BUFFER[11382]	//(internal1_m1779_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1779_tz0	 1710	//(internal1_m1779_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1779_Shift0	 BUFFER[11387]	//(internal1_m1779_Shift0) Shift0 - признак самохода
#define idinternal1_m1779_Shift0	 1711	//(internal1_m1779_Shift0) Shift0 - признак самохода
#define internal1_m1779_ShCntlSp0	 BUFFER[11389]	//(internal1_m1779_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1779_ShCntlSp0	 1712	//(internal1_m1779_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1779_ShiftControl	 BUFFER[11391]	//(internal1_m1779_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1779_ShiftControl	 1713	//(internal1_m1779_ShiftControl) ShiftControl - признак самохода
#define internal1_m1257_tx	 BUFFER[11393]	//(internal1_m1257_tx) tx - время накопленное сек
#define idinternal1_m1257_tx	 1714	//(internal1_m1257_tx) tx - время накопленное сек
#define internal1_m1257_y0	 BUFFER[11398]	//(internal1_m1257_y0) y0
#define idinternal1_m1257_y0	 1715	//(internal1_m1257_y0) y0
#define internal1_m1261_tx	 BUFFER[11399]	//(internal1_m1261_tx) tx - время накопленное сек
#define idinternal1_m1261_tx	 1716	//(internal1_m1261_tx) tx - время накопленное сек
#define internal1_m1261_y0	 BUFFER[11404]	//(internal1_m1261_y0) y0
#define idinternal1_m1261_y0	 1717	//(internal1_m1261_y0) y0
#define internal1_m691_q0	 BUFFER[11405]	//(internal1_m691_q0) q0 - внутренний параметр
#define idinternal1_m691_q0	 1718	//(internal1_m691_q0) q0 - внутренний параметр
#define internal1_m656_q0	 BUFFER[11407]	//(internal1_m656_q0) q0 - внутренний параметр
#define idinternal1_m656_q0	 1719	//(internal1_m656_q0) q0 - внутренний параметр
#define internal1_m1248_DvUp0	 BUFFER[11409]	//(internal1_m1248_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1248_DvUp0	 1720	//(internal1_m1248_DvUp0) - есть команда на движение вперёд
#define internal1_m1248_DvDw0	 BUFFER[11410]	//(internal1_m1248_DvDw0) - есть команда на движение назад
#define idinternal1_m1248_DvDw0	 1721	//(internal1_m1248_DvDw0) - есть команда на движение назад
#define internal1_m1248_FDvUp0	 BUFFER[11411]	//(internal1_m1248_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1248_FDvUp0	 1722	//(internal1_m1248_FDvUp0) - есть команда на движение вперёд
#define internal1_m1248_FDvDw0	 BUFFER[11412]	//(internal1_m1248_FDvDw0) - есть команда на движение назад
#define idinternal1_m1248_FDvDw0	 1723	//(internal1_m1248_FDvDw0) - есть команда на движение назад
#define internal1_m1248_BlDv0	 BUFFER[11413]	//(internal1_m1248_BlDv0) - была блокировка
#define idinternal1_m1248_BlDv0	 1724	//(internal1_m1248_BlDv0) - была блокировка
#define internal1_m1248_Pkv0	 BUFFER[11414]	//(internal1_m1248_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1248_Pkv0	 1725	//(internal1_m1248_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1248_Pkav0	 BUFFER[11415]	//(internal1_m1248_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1248_Pkav0	 1726	//(internal1_m1248_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1248_Zkv0	 BUFFER[11416]	//(internal1_m1248_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1248_Zkv0	 1727	//(internal1_m1248_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1248_Zkav0	 BUFFER[11417]	//(internal1_m1248_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1248_Zkav0	 1728	//(internal1_m1248_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1248_txNm	 BUFFER[11418]	//(internal1_m1248_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1248_txNm	 1729	//(internal1_m1248_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1248_txSm	 BUFFER[11423]	//(internal1_m1248_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1248_txSm	 1730	//(internal1_m1248_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1248_txHr	 BUFFER[11428]	//(internal1_m1248_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1248_txHr	 1731	//(internal1_m1248_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1248_txLd	 BUFFER[11433]	//(internal1_m1248_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1248_txLd	 1732	//(internal1_m1248_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1248_fef	 BUFFER[11438]	//(internal1_m1248_fef) fef
#define idinternal1_m1248_fef	 1733	//(internal1_m1248_fef) fef
#define internal1_m1267_xptr	 BUFFER[11439]	//(internal1_m1267_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1267_xptr	 1734	//(internal1_m1267_xptr) указатель текущей позиции в массиве координат
#define internal1_m1267_x0	 BUFFER[11442]	//(internal1_m1267_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1267_x0	 1735	//(internal1_m1267_x0) x0 - массив мгновенных значений координат
#define internal1_m1267_tim0	 BUFFER[11542]	//(internal1_m1267_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1267_tim0	 1736	//(internal1_m1267_tim0) tim0 - массив значений времени цикла
#define internal1_m1267_sumtim	 BUFFER[11642]	//(internal1_m1267_sumtim) sumtim - время в пути
#define idinternal1_m1267_sumtim	 1737	//(internal1_m1267_sumtim) sumtim - время в пути
#define internal1_m1267_StSpeed	 BUFFER[11647]	//(internal1_m1267_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1267_StSpeed	 1738	//(internal1_m1267_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1267_Vz0	 BUFFER[11652]	//(internal1_m1267_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1267_Vz0	 1739	//(internal1_m1267_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1267_flRazg	 BUFFER[11657]	//(internal1_m1267_flRazg) признак разгона/торможения
#define idinternal1_m1267_flRazg	 1740	//(internal1_m1267_flRazg) признак разгона/торможения
#define internal1_m1267_DelSp	 BUFFER[11660]	//(internal1_m1267_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1267_DelSp	 1741	//(internal1_m1267_DelSp) DelSp - время переключения скоростей
#define internal1_m1267_z0	 BUFFER[11665]	//(internal1_m1267_z0) z0 - точка прекращения движения
#define idinternal1_m1267_z0	 1742	//(internal1_m1267_z0) z0 - точка прекращения движения
#define internal1_m1267_txZS	 BUFFER[11670]	//(internal1_m1267_txZS) txZS
#define idinternal1_m1267_txZS	 1743	//(internal1_m1267_txZS) txZS
#define internal1_m1267_tx	 BUFFER[11675]	//(internal1_m1267_tx) tx
#define idinternal1_m1267_tx	 1744	//(internal1_m1267_tx) tx
#define internal1_m1267_txd	 BUFFER[11680]	//(internal1_m1267_txd) txd
#define idinternal1_m1267_txd	 1745	//(internal1_m1267_txd) txd
#define internal1_m1267_txMBl	 BUFFER[11685]	//(internal1_m1267_txMBl) tx
#define idinternal1_m1267_txMBl	 1746	//(internal1_m1267_txMBl) tx
#define internal1_m1267_txBl	 BUFFER[11690]	//(internal1_m1267_txBl) tx
#define idinternal1_m1267_txBl	 1747	//(internal1_m1267_txBl) tx
#define internal1_m1267_Speed0	 BUFFER[11695]	//(internal1_m1267_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1267_Speed0	 1748	//(internal1_m1267_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1267_xz0	 BUFFER[11700]	//(internal1_m1267_xz0) xz0 - новое задание мм
#define idinternal1_m1267_xz0	 1749	//(internal1_m1267_xz0) xz0 - новое задание мм
#define internal1_m1267_tz0	 BUFFER[11705]	//(internal1_m1267_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1267_tz0	 1750	//(internal1_m1267_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1267_Shift0	 BUFFER[11710]	//(internal1_m1267_Shift0) Shift0 - признак самохода
#define idinternal1_m1267_Shift0	 1751	//(internal1_m1267_Shift0) Shift0 - признак самохода
#define internal1_m1267_ShCntlSp0	 BUFFER[11712]	//(internal1_m1267_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1267_ShCntlSp0	 1752	//(internal1_m1267_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1267_ShiftControl	 BUFFER[11714]	//(internal1_m1267_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1267_ShiftControl	 1753	//(internal1_m1267_ShiftControl) ShiftControl - признак самохода
#define internal1_m819_x0	 BUFFER[11716]	//(internal1_m819_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m819_x0	 1754	//(internal1_m819_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m787_x0	 BUFFER[11718]	//(internal1_m787_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m787_x0	 1755	//(internal1_m787_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m730_x0	 BUFFER[11720]	//(internal1_m730_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m730_x0	 1756	//(internal1_m730_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m844_q0	 BUFFER[11722]	//(internal1_m844_q0) q0 - внутренний параметр
#define idinternal1_m844_q0	 1757	//(internal1_m844_q0) q0 - внутренний параметр
#define internal1_m839_q0	 BUFFER[11724]	//(internal1_m839_q0) q0 - внутренний параметр
#define idinternal1_m839_q0	 1758	//(internal1_m839_q0) q0 - внутренний параметр
#define internal1_m807_q0	 BUFFER[11726]	//(internal1_m807_q0) q0 - внутренний параметр
#define idinternal1_m807_q0	 1759	//(internal1_m807_q0) q0 - внутренний параметр
#define internal1_m812_q0	 BUFFER[11728]	//(internal1_m812_q0) q0 - внутренний параметр
#define idinternal1_m812_q0	 1760	//(internal1_m812_q0) q0 - внутренний параметр
#define internal1_m820_q0	 BUFFER[11730]	//(internal1_m820_q0) q0 - внутренний параметр
#define idinternal1_m820_q0	 1761	//(internal1_m820_q0) q0 - внутренний параметр
#define internal1_m832_q0	 BUFFER[11732]	//(internal1_m832_q0) q0 - внутренний параметр
#define idinternal1_m832_q0	 1762	//(internal1_m832_q0) q0 - внутренний параметр
#define internal1_m810_q0	 BUFFER[11734]	//(internal1_m810_q0) q0 - внутренний параметр
#define idinternal1_m810_q0	 1763	//(internal1_m810_q0) q0 - внутренний параметр
#define internal1_m1309_DvUp0	 BUFFER[11736]	//(internal1_m1309_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1309_DvUp0	 1764	//(internal1_m1309_DvUp0) - есть команда на движение вперёд
#define internal1_m1309_DvDw0	 BUFFER[11737]	//(internal1_m1309_DvDw0) - есть команда на движение назад
#define idinternal1_m1309_DvDw0	 1765	//(internal1_m1309_DvDw0) - есть команда на движение назад
#define internal1_m1309_FDvUp0	 BUFFER[11738]	//(internal1_m1309_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1309_FDvUp0	 1766	//(internal1_m1309_FDvUp0) - есть команда на движение вперёд
#define internal1_m1309_FDvDw0	 BUFFER[11739]	//(internal1_m1309_FDvDw0) - есть команда на движение назад
#define idinternal1_m1309_FDvDw0	 1767	//(internal1_m1309_FDvDw0) - есть команда на движение назад
#define internal1_m1309_BlDv0	 BUFFER[11740]	//(internal1_m1309_BlDv0) - была блокировка
#define idinternal1_m1309_BlDv0	 1768	//(internal1_m1309_BlDv0) - была блокировка
#define internal1_m1309_Pkv0	 BUFFER[11741]	//(internal1_m1309_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1309_Pkv0	 1769	//(internal1_m1309_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1309_Pkav0	 BUFFER[11742]	//(internal1_m1309_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1309_Pkav0	 1770	//(internal1_m1309_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1309_Zkv0	 BUFFER[11743]	//(internal1_m1309_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1309_Zkv0	 1771	//(internal1_m1309_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1309_Zkav0	 BUFFER[11744]	//(internal1_m1309_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1309_Zkav0	 1772	//(internal1_m1309_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1309_txNm	 BUFFER[11745]	//(internal1_m1309_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1309_txNm	 1773	//(internal1_m1309_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1309_txSm	 BUFFER[11750]	//(internal1_m1309_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1309_txSm	 1774	//(internal1_m1309_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1309_txHr	 BUFFER[11755]	//(internal1_m1309_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1309_txHr	 1775	//(internal1_m1309_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1309_txLd	 BUFFER[11760]	//(internal1_m1309_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1309_txLd	 1776	//(internal1_m1309_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1309_fef	 BUFFER[11765]	//(internal1_m1309_fef) fef
#define idinternal1_m1309_fef	 1777	//(internal1_m1309_fef) fef
#define internal1_m1300_DvUp0	 BUFFER[11766]	//(internal1_m1300_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1300_DvUp0	 1778	//(internal1_m1300_DvUp0) - есть команда на движение вперёд
#define internal1_m1300_DvDw0	 BUFFER[11767]	//(internal1_m1300_DvDw0) - есть команда на движение назад
#define idinternal1_m1300_DvDw0	 1779	//(internal1_m1300_DvDw0) - есть команда на движение назад
#define internal1_m1300_FDvUp0	 BUFFER[11768]	//(internal1_m1300_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1300_FDvUp0	 1780	//(internal1_m1300_FDvUp0) - есть команда на движение вперёд
#define internal1_m1300_FDvDw0	 BUFFER[11769]	//(internal1_m1300_FDvDw0) - есть команда на движение назад
#define idinternal1_m1300_FDvDw0	 1781	//(internal1_m1300_FDvDw0) - есть команда на движение назад
#define internal1_m1300_BlDv0	 BUFFER[11770]	//(internal1_m1300_BlDv0) - была блокировка
#define idinternal1_m1300_BlDv0	 1782	//(internal1_m1300_BlDv0) - была блокировка
#define internal1_m1300_Pkv0	 BUFFER[11771]	//(internal1_m1300_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1300_Pkv0	 1783	//(internal1_m1300_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1300_Pkav0	 BUFFER[11772]	//(internal1_m1300_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1300_Pkav0	 1784	//(internal1_m1300_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1300_Zkv0	 BUFFER[11773]	//(internal1_m1300_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1300_Zkv0	 1785	//(internal1_m1300_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1300_Zkav0	 BUFFER[11774]	//(internal1_m1300_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1300_Zkav0	 1786	//(internal1_m1300_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1300_txNm	 BUFFER[11775]	//(internal1_m1300_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1300_txNm	 1787	//(internal1_m1300_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1300_txSm	 BUFFER[11780]	//(internal1_m1300_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1300_txSm	 1788	//(internal1_m1300_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1300_txHr	 BUFFER[11785]	//(internal1_m1300_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1300_txHr	 1789	//(internal1_m1300_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1300_txLd	 BUFFER[11790]	//(internal1_m1300_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1300_txLd	 1790	//(internal1_m1300_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1300_fef	 BUFFER[11795]	//(internal1_m1300_fef) fef
#define idinternal1_m1300_fef	 1791	//(internal1_m1300_fef) fef
#define internal1_m868_DvUp0	 BUFFER[11796]	//(internal1_m868_DvUp0) - есть команда на движение вперёд
#define idinternal1_m868_DvUp0	 1792	//(internal1_m868_DvUp0) - есть команда на движение вперёд
#define internal1_m868_DvDw0	 BUFFER[11797]	//(internal1_m868_DvDw0) - есть команда на движение назад
#define idinternal1_m868_DvDw0	 1793	//(internal1_m868_DvDw0) - есть команда на движение назад
#define internal1_m868_FDvUp0	 BUFFER[11798]	//(internal1_m868_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m868_FDvUp0	 1794	//(internal1_m868_FDvUp0) - есть команда на движение вперёд
#define internal1_m868_FDvDw0	 BUFFER[11799]	//(internal1_m868_FDvDw0) - есть команда на движение назад
#define idinternal1_m868_FDvDw0	 1795	//(internal1_m868_FDvDw0) - есть команда на движение назад
#define internal1_m868_BlDv0	 BUFFER[11800]	//(internal1_m868_BlDv0) - была блокировка
#define idinternal1_m868_BlDv0	 1796	//(internal1_m868_BlDv0) - была блокировка
#define internal1_m868_Pkv0	 BUFFER[11801]	//(internal1_m868_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m868_Pkv0	 1797	//(internal1_m868_Pkv0) Pkv - передний конечный выключатель
#define internal1_m868_Pkav0	 BUFFER[11802]	//(internal1_m868_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m868_Pkav0	 1798	//(internal1_m868_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m868_Zkv0	 BUFFER[11803]	//(internal1_m868_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m868_Zkv0	 1799	//(internal1_m868_Zkv0) Zkv - задний конечный выключатель
#define internal1_m868_Zkav0	 BUFFER[11804]	//(internal1_m868_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m868_Zkav0	 1800	//(internal1_m868_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m868_txNm	 BUFFER[11805]	//(internal1_m868_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m868_txNm	 1801	//(internal1_m868_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m868_txSm	 BUFFER[11810]	//(internal1_m868_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m868_txSm	 1802	//(internal1_m868_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m868_txHr	 BUFFER[11815]	//(internal1_m868_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m868_txHr	 1803	//(internal1_m868_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m868_txLd	 BUFFER[11820]	//(internal1_m868_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m868_txLd	 1804	//(internal1_m868_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m868_fef	 BUFFER[11825]	//(internal1_m868_fef) fef
#define idinternal1_m868_fef	 1805	//(internal1_m868_fef) fef
#define internal1_m864_DvUp0	 BUFFER[11826]	//(internal1_m864_DvUp0) - есть команда на движение вперёд
#define idinternal1_m864_DvUp0	 1806	//(internal1_m864_DvUp0) - есть команда на движение вперёд
#define internal1_m864_DvDw0	 BUFFER[11827]	//(internal1_m864_DvDw0) - есть команда на движение назад
#define idinternal1_m864_DvDw0	 1807	//(internal1_m864_DvDw0) - есть команда на движение назад
#define internal1_m864_FDvUp0	 BUFFER[11828]	//(internal1_m864_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m864_FDvUp0	 1808	//(internal1_m864_FDvUp0) - есть команда на движение вперёд
#define internal1_m864_FDvDw0	 BUFFER[11829]	//(internal1_m864_FDvDw0) - есть команда на движение назад
#define idinternal1_m864_FDvDw0	 1809	//(internal1_m864_FDvDw0) - есть команда на движение назад
#define internal1_m864_BlDv0	 BUFFER[11830]	//(internal1_m864_BlDv0) - была блокировка
#define idinternal1_m864_BlDv0	 1810	//(internal1_m864_BlDv0) - была блокировка
#define internal1_m864_Pkv0	 BUFFER[11831]	//(internal1_m864_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m864_Pkv0	 1811	//(internal1_m864_Pkv0) Pkv - передний конечный выключатель
#define internal1_m864_Pkav0	 BUFFER[11832]	//(internal1_m864_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m864_Pkav0	 1812	//(internal1_m864_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m864_Zkv0	 BUFFER[11833]	//(internal1_m864_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m864_Zkv0	 1813	//(internal1_m864_Zkv0) Zkv - задний конечный выключатель
#define internal1_m864_Zkav0	 BUFFER[11834]	//(internal1_m864_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m864_Zkav0	 1814	//(internal1_m864_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m864_txNm	 BUFFER[11835]	//(internal1_m864_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m864_txNm	 1815	//(internal1_m864_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m864_txSm	 BUFFER[11840]	//(internal1_m864_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m864_txSm	 1816	//(internal1_m864_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m864_txHr	 BUFFER[11845]	//(internal1_m864_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m864_txHr	 1817	//(internal1_m864_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m864_txLd	 BUFFER[11850]	//(internal1_m864_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m864_txLd	 1818	//(internal1_m864_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m864_fef	 BUFFER[11855]	//(internal1_m864_fef) fef
#define idinternal1_m864_fef	 1819	//(internal1_m864_fef) fef
#define internal1_m379_DvUp0	 BUFFER[11856]	//(internal1_m379_DvUp0) - есть команда на движение вперёд
#define idinternal1_m379_DvUp0	 1820	//(internal1_m379_DvUp0) - есть команда на движение вперёд
#define internal1_m379_DvDw0	 BUFFER[11857]	//(internal1_m379_DvDw0) - есть команда на движение назад
#define idinternal1_m379_DvDw0	 1821	//(internal1_m379_DvDw0) - есть команда на движение назад
#define internal1_m379_FDvUp0	 BUFFER[11858]	//(internal1_m379_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m379_FDvUp0	 1822	//(internal1_m379_FDvUp0) - есть команда на движение вперёд
#define internal1_m379_FDvDw0	 BUFFER[11859]	//(internal1_m379_FDvDw0) - есть команда на движение назад
#define idinternal1_m379_FDvDw0	 1823	//(internal1_m379_FDvDw0) - есть команда на движение назад
#define internal1_m379_BlDv0	 BUFFER[11860]	//(internal1_m379_BlDv0) - была блокировка
#define idinternal1_m379_BlDv0	 1824	//(internal1_m379_BlDv0) - была блокировка
#define internal1_m379_Pkv0	 BUFFER[11861]	//(internal1_m379_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m379_Pkv0	 1825	//(internal1_m379_Pkv0) Pkv - передний конечный выключатель
#define internal1_m379_Pkav0	 BUFFER[11862]	//(internal1_m379_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m379_Pkav0	 1826	//(internal1_m379_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m379_Zkv0	 BUFFER[11863]	//(internal1_m379_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m379_Zkv0	 1827	//(internal1_m379_Zkv0) Zkv - задний конечный выключатель
#define internal1_m379_Zkav0	 BUFFER[11864]	//(internal1_m379_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m379_Zkav0	 1828	//(internal1_m379_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m379_txNm	 BUFFER[11865]	//(internal1_m379_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m379_txNm	 1829	//(internal1_m379_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m379_txSm	 BUFFER[11870]	//(internal1_m379_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m379_txSm	 1830	//(internal1_m379_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m379_txHr	 BUFFER[11875]	//(internal1_m379_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m379_txHr	 1831	//(internal1_m379_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m379_txLd	 BUFFER[11880]	//(internal1_m379_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m379_txLd	 1832	//(internal1_m379_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m379_fef	 BUFFER[11885]	//(internal1_m379_fef) fef
#define idinternal1_m379_fef	 1833	//(internal1_m379_fef) fef
#define internal1_m416_DvUp0	 BUFFER[11886]	//(internal1_m416_DvUp0) - есть команда на движение вперёд
#define idinternal1_m416_DvUp0	 1834	//(internal1_m416_DvUp0) - есть команда на движение вперёд
#define internal1_m416_DvDw0	 BUFFER[11887]	//(internal1_m416_DvDw0) - есть команда на движение назад
#define idinternal1_m416_DvDw0	 1835	//(internal1_m416_DvDw0) - есть команда на движение назад
#define internal1_m416_FDvUp0	 BUFFER[11888]	//(internal1_m416_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m416_FDvUp0	 1836	//(internal1_m416_FDvUp0) - есть команда на движение вперёд
#define internal1_m416_FDvDw0	 BUFFER[11889]	//(internal1_m416_FDvDw0) - есть команда на движение назад
#define idinternal1_m416_FDvDw0	 1837	//(internal1_m416_FDvDw0) - есть команда на движение назад
#define internal1_m416_BlDv0	 BUFFER[11890]	//(internal1_m416_BlDv0) - была блокировка
#define idinternal1_m416_BlDv0	 1838	//(internal1_m416_BlDv0) - была блокировка
#define internal1_m416_Pkv0	 BUFFER[11891]	//(internal1_m416_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m416_Pkv0	 1839	//(internal1_m416_Pkv0) Pkv - передний конечный выключатель
#define internal1_m416_Pkav0	 BUFFER[11892]	//(internal1_m416_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m416_Pkav0	 1840	//(internal1_m416_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m416_Zkv0	 BUFFER[11893]	//(internal1_m416_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m416_Zkv0	 1841	//(internal1_m416_Zkv0) Zkv - задний конечный выключатель
#define internal1_m416_Zkav0	 BUFFER[11894]	//(internal1_m416_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m416_Zkav0	 1842	//(internal1_m416_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m416_txNm	 BUFFER[11895]	//(internal1_m416_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m416_txNm	 1843	//(internal1_m416_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m416_txSm	 BUFFER[11900]	//(internal1_m416_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m416_txSm	 1844	//(internal1_m416_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m416_txHr	 BUFFER[11905]	//(internal1_m416_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m416_txHr	 1845	//(internal1_m416_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m416_txLd	 BUFFER[11910]	//(internal1_m416_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m416_txLd	 1846	//(internal1_m416_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m416_fef	 BUFFER[11915]	//(internal1_m416_fef) fef
#define idinternal1_m416_fef	 1847	//(internal1_m416_fef) fef
#define internal1_m410_DvUp0	 BUFFER[11916]	//(internal1_m410_DvUp0) - есть команда на движение вперёд
#define idinternal1_m410_DvUp0	 1848	//(internal1_m410_DvUp0) - есть команда на движение вперёд
#define internal1_m410_DvDw0	 BUFFER[11917]	//(internal1_m410_DvDw0) - есть команда на движение назад
#define idinternal1_m410_DvDw0	 1849	//(internal1_m410_DvDw0) - есть команда на движение назад
#define internal1_m410_FDvUp0	 BUFFER[11918]	//(internal1_m410_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m410_FDvUp0	 1850	//(internal1_m410_FDvUp0) - есть команда на движение вперёд
#define internal1_m410_FDvDw0	 BUFFER[11919]	//(internal1_m410_FDvDw0) - есть команда на движение назад
#define idinternal1_m410_FDvDw0	 1851	//(internal1_m410_FDvDw0) - есть команда на движение назад
#define internal1_m410_BlDv0	 BUFFER[11920]	//(internal1_m410_BlDv0) - была блокировка
#define idinternal1_m410_BlDv0	 1852	//(internal1_m410_BlDv0) - была блокировка
#define internal1_m410_Pkv0	 BUFFER[11921]	//(internal1_m410_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m410_Pkv0	 1853	//(internal1_m410_Pkv0) Pkv - передний конечный выключатель
#define internal1_m410_Pkav0	 BUFFER[11922]	//(internal1_m410_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m410_Pkav0	 1854	//(internal1_m410_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m410_Zkv0	 BUFFER[11923]	//(internal1_m410_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m410_Zkv0	 1855	//(internal1_m410_Zkv0) Zkv - задний конечный выключатель
#define internal1_m410_Zkav0	 BUFFER[11924]	//(internal1_m410_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m410_Zkav0	 1856	//(internal1_m410_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m410_txNm	 BUFFER[11925]	//(internal1_m410_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m410_txNm	 1857	//(internal1_m410_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m410_txSm	 BUFFER[11930]	//(internal1_m410_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m410_txSm	 1858	//(internal1_m410_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m410_txHr	 BUFFER[11935]	//(internal1_m410_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m410_txHr	 1859	//(internal1_m410_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m410_txLd	 BUFFER[11940]	//(internal1_m410_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m410_txLd	 1860	//(internal1_m410_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m410_fef	 BUFFER[11945]	//(internal1_m410_fef) fef
#define idinternal1_m410_fef	 1861	//(internal1_m410_fef) fef
#define internal1_m816_q0	 BUFFER[11946]	//(internal1_m816_q0) q0 - внутренний параметр
#define idinternal1_m816_q0	 1862	//(internal1_m816_q0) q0 - внутренний параметр
#define internal1_m813_q0	 BUFFER[11948]	//(internal1_m813_q0) q0 - внутренний параметр
#define idinternal1_m813_q0	 1863	//(internal1_m813_q0) q0 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &B4IS10LDU},	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
	{ 2	,1	,1	, &R6IS31LDU},	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
	{ 3	,1	,1	, &R6IS32LDU},	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
	{ 4	,1	,1	, &R6IS42LDU},	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
	{ 5	,1	,1	, &R6IS41LDU},	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
	{ 6	,1	,1	, &R6IS52LDU},	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
	{ 7	,1	,1	, &R6IS51LDU},	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
	{ 8	,1	,1	, &R3IS11LDU},	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
	{ 9	,1	,1	, &R3IS21LDU},	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
	{ 10	,1	,1	, &R0AB03LDU},	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
	{ 11	,1	,1	, &R0AB05LDU},	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
	{ 12	,8	,1	, &R0VN11RZ1},	//( - , MDuBz1) Средняя мощность по BAZ1
	{ 13	,8	,1	, &R0VN11RZ2},	//( - , MDuBz2) Средняя мощность по BAZ2
	{ 14	,1	,1	, &A2AB15LDU},	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{ 15	,1	,1	, &B2AB15LDU},	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{ 16	,1	,1	, &R0AD21LDU},	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
	{ 17	,1	,1	, &R0VX02LDU},	//( - , DU) Импульс разрешен
	{ 18	,1	,1	, &R0EE03LDU},	//( - , DU) ВПИС ИС
	{ 19	,1	,1	, &R0AB07LDU},	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
	{ 20	,1	,1	, &R0AD16LDU},	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
	{ 21	,1	,1	, &C2MD31LP1},	//( - , DU) Кнопка СБРОС РБ
	{ 22	,3	,1	, &B6VS01IDU},	//( - , DU) Готовность к управлению БЗ2
	{ 23	,1	,1	, &R2AD20LDU},	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
	{ 24	,1	,1	, &B3MD11LP1},	//( - , DU) Кнопка ПУСК ИС2
	{ 25	,8	,1	, &R0VL01RDU},	//( - , DU) Индикация Время задержки
	{ 26	,1	,1	, &R0VZ71LZ2},	//(vds32:03 - K22VDSR, - ) Обобщенный сигнал АЗ 2 канала
	{ 27	,1	,1	, &R0VZ71LZ1},	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
	{ 28	,1	,1	, &R0VZ71LDU},	//( - , DU) Обобщенный сигнал АЗ
	{ 29	,1	,1	, &A2IS33LDU},	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
	{ 30	,1	,1	, &A3IS31LDU},	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
	{ 31	,1	,1	, &A3IS33LDU},	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
	{ 32	,1	,1	, &A3IS35LDU},	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
	{ 33	,1	,1	, &A4IS10LDU},	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
	{ 34	,1	,1	, &A1VN71LZ1},	//(vds32:02 - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{ 35	,1	,1	, &A1VN71LZ2},	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{ 36	,1	,1	, &A1AB19LDU},	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
	{ 37	,1	,1	, &R0AD14LZ1},	//(vds32:02 - K20VDSR, DU) Имитация срабатывания АЗ от II УР
	{ 38	,1	,1	, &R0AD14LZ2},	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
	{ 39	,1	,1	, &A3VZ13LZ2},	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{ 40	,1	,1	, &A3VZ13LZ1},	//(vds32:02 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{ 41	,1	,1	, &A3VZ15LZ1},	//(vds32:02 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{ 42	,1	,1	, &A3VZ15LZ2},	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{ 43	,1	,1	, &B2IS33LDU},	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
	{ 44	,1	,1	, &B3IS31LDU},	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
	{ 45	,1	,1	, &B3IS33LDU},	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
	{ 46	,1	,1	, &B3IS35LDU},	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
	{ 47	,1	,1	, &R0AB09LDU},	//( - , DU) Ошибка в заданной координате ББ1
	{ 48	,1	,1	, &R0AB10LDU},	//( - , DU) Ошибка в заданной координате ББ2
	{ 49	,1	,1	, &R0AB11LDU},	//( - , DU) Ошибка в заданной координате  ИС1
	{ 50	,1	,1	, &R0AB12LDU},	//( - , DU) Ошибка в заданной координате  ИС2
	{ 51	,1	,1	, &R0AB13LDU},	//( - , DU) Ошибка в заданной координате  АЗ2
	{ 52	,1	,1	, &A4ZAV},	//( - , DU) 
	{ 53	,1	,1	, &A6ZAV},	//( - , DU) 
	{ 54	,1	,1	, &R2ZAV},	//( - , DU) 
	{ 55	,1	,1	, &A5ZAV},	//( - , DU) 
	{ 56	,1	,1	, &B8ZAV},	//( - , DU) 
	{ 57	,1	,1	, &A2ZAV},	//( - , DU) Завершение РБ1,2
	{ 58	,1	,1	, &A8ZAV},	//( - , DU) 
	{ 59	,1	,1	, &A9ZAV},	//( - , DU) Завершение НИ ДС1(2)
	{ 60	,1	,1	, &R4ABL},	//( - , DU) Блокировка тележки -
	{ 61	,1	,1	, &A4UP},	//( - , DU) 
	{ 62	,1	,1	, &A4DW},	//( - , DU) 
	{ 63	,1	,1	, &R0AB14LDU},	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
	{ 64	,1	,1	, &R0AB15LDU},	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
	{ 65	,1	,1	, &A3IS12LDU},	//( - , DU) Приход на ВУ штока ИС1
	{ 66	,1	,1	, &B3IS12LDU},	//( - , DU) Приход на ВУ штока ИС2
	{ 67	,1	,1	, &A1ZAV},	//( - , DU) 
	{ 68	,1	,1	, &A3ZAV},	//( - , DU) 
	{ 69	,1	,1	, &B1AB19LDU},	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
	{ 70	,1	,1	, &R2AD10LDU},	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
	{ 71	,3	,1	, &B8VS01IDU},	//( - , DU) Готовность к управлению АЗ2
	{ 72	,3	,1	, &A8VS01IDU},	//( - , DU) Готовность к управлению ДС2
	{ 73	,1	,1	, &A1IE03LDU},	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
	{ 74	,1	,1	, &A1IE04LDU},	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
	{ 75	,1	,1	, &A2IE03LDU},	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
	{ 76	,1	,1	, &A2IE04LDU},	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
	{ 77	,1	,1	, &A3IE03LDU},	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
	{ 78	,1	,1	, &A3IE04LDU},	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
	{ 79	,1	,1	, &B1IE03LDU},	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
	{ 80	,1	,1	, &B1IE04LDU},	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
	{ 81	,1	,1	, &B2IE03LDU},	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
	{ 82	,1	,1	, &B2IE04LDU},	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
	{ 83	,1	,1	, &B3IE03LDU},	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
	{ 84	,1	,1	, &B3IE04LDU},	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
	{ 85	,1	,1	, &R0VS11LDU},	//( - , DU) РУ не готова к работе
	{ 86	,1	,1	, &B6AB05LDU},	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
	{ 87	,1	,1	, &R0AB08LDU},	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
	{ 88	,8	,1	, &A1MC01RP1},	//( - , DU) Заданная координата положения ББ1 мм
	{ 89	,8	,1	, &B1MC01RP1},	//( - , DU) Заданная координата положения ББ2  мм
	{ 90	,8	,1	, &A3MC01RP1},	//( - , DU) Заданная координата положения ИС1 мм
	{ 91	,8	,1	, &B3MC01RP1},	//( - , DU) Заданная координата положения ИС2 мм
	{ 92	,8	,1	, &B8MC01RP2},	//( - , DU) Заданная координата АЗ2 мм
	{ 93	,1	,1	, &A9IS11LDU},	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
	{ 94	,1	,1	, &A9IS21LDU},	//(vds32:02 - K24VDSR, - ) Приход на НУ НИ ДС1
	{ 95	,1	,1	, &B9IS11LDU},	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
	{ 96	,1	,1	, &B9IS21LDU},	//(vds32:02 - K26VDSR, - ) Приход на НУ НИ ДС2
	{ 97	,1	,1	, &B9AD10LDU},	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
	{ 98	,1	,1	, &A9AD10LDU},	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
	{ 99	,1	,1	, &A9AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ ДС1
	{ 100	,1	,1	, &A9AB01LDU},	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
	{ 101	,1	,1	, &A9AB02LDU},	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
	{ 102	,1	,1	, &B9AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ ДС2
	{ 103	,1	,1	, &B9AB01LDU},	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
	{ 104	,1	,1	, &B9AB02LDU},	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
	{ 105	,1	,1	, &R0AB01LDU},	//( - , DU) Режим проверки разрешён
	{ 106	,1	,1	, &A3IS22LDU},	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
	{ 107	,1	,1	, &B3IS22LDU},	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
	{ 108	,1	,1	, &A2AD33LDU},	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
	{ 109	,1	,1	, &B2AD33LDU},	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
	{ 110	,1	,1	, &A3AD33LDU},	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
	{ 111	,1	,1	, &A3AD34LDU},	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
	{ 112	,1	,1	, &A3AD31LDU},	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
	{ 113	,1	,1	, &B3AD34LDU},	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
	{ 114	,1	,1	, &B3AD31LDU},	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
	{ 115	,1	,1	, &A2IS11LDU},	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
	{ 116	,1	,1	, &R0AB02LDU},	//( - , DU) Нарушение времени задержки ИНИ
	{ 117	,8	,1	, &R0VL03RDU},	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
	{ 118	,8	,1	, &R0VL05RDU},	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
	{ 119	,3	,1	, &R0VL21IDU},	//( - , DU) Декатрон
	{ 120	,1	,1	, &R0VX03LDU},	//( - , DU) Готовность 2 мин
	{ 121	,3	,1	, &R0VS21IDU},	//( - , DU) Индикация ВИД ПРОВЕРКИ
	{ 122	,3	,1	, &A1VS01IDU},	//( - , DU) Готовность к управлению ББ1
	{ 123	,3	,1	, &B1VS01IDU},	//( - , DU) Готовность к управлению ББ2
	{ 124	,3	,1	, &A3VS01IDU},	//( - , DU) Готовность к управлению ИС1
	{ 125	,3	,1	, &B3VS01IDU},	//( - , DU) Готовность к управлению ИС2
	{ 126	,3	,1	, &A2VS01IDU},	//( - , DU) Готовность к управлению РБ1
	{ 127	,3	,1	, &A4VS01IDU},	//( - , DU) Готовность к управлению НИ1
	{ 128	,1	,1	, &A4VS12LDU},	//( - , DU) Движение НИ1 в сторону ВУ
	{ 129	,1	,1	, &A4VS22LDU},	//( - , DU) Движение НИ1 в сторону НУ
	{ 130	,3	,1	, &B4VS01IDU},	//( - , DU) Готовность к управлению НИ2
	{ 131	,1	,1	, &B4VS12LDU},	//( - , DU) Движение НИ2 в сторону ВУ
	{ 132	,1	,1	, &B4VS22LDU},	//( - , DU) Движение НИ2 в сторону НУ
	{ 133	,3	,1	, &A5VS01IDU},	//( - , DU) Готовность к управлению НЛ1
	{ 134	,3	,1	, &B5VS01IDU},	//( - , DU) Готовность к управлению НЛ2
	{ 135	,3	,1	, &A6VS01IDU},	//( - , DU) Готовность к управлению БЗ1
	{ 136	,3	,1	, &R4VS01IDU},	//( - , DU) Готовность к управлению тележкой реактора
	{ 137	,3	,1	, &R2VS01IDU},	//( - , DU) Готовность к управлению МДЗ2
	{ 138	,3	,1	, &R1VS01IDU},	//( - , DU) Готовность к управлению МДЗ1
	{ 139	,1	,1	, &B1MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
	{ 140	,1	,1	, &B2MD11LP1},	//( - , DU) Кнопка ПУСК РБ2
	{ 141	,1	,1	, &B2MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
	{ 142	,1	,1	, &A2MD11LP1},	//( - , DU) Кнопка ПУСК РБ1
	{ 143	,1	,1	, &A2MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
	{ 144	,1	,1	, &R0IS01LDU},	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
	{ 145	,1	,1	, &R0IS02LDU},	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
	{ 146	,1	,1	, &R0VP73LZ1},	//( - , MDuBz1) ПС давления для РУ
	{ 147	,1	,1	, &R0VP73LZ2},	//( - , MDuBz2) ПС давления для РУ
	{ 148	,1	,1	, &R0VP73LDU},	//( - , DU) ПС давления для РУ
	{ 149	,1	,1	, &R0MD34LP1},	//( - , DU) Кнопка КВИТИРОВАТЬ
	{ 150	,1	,1	, &A0VT71LZ1},	//( - , MDuBz1) АС по температуре в АЗ1
	{ 151	,1	,1	, &B0VT71LZ1},	//( - , MDuBz1) АС по температуре в АЗ2
	{ 152	,1	,1	, &A0VT71LZ2},	//( - , MDuBz2) АС по температуре в АЗ1
	{ 153	,1	,1	, &B0VT71LZ2},	//( - , MDuBz2) АС по температуре в АЗ2
	{ 154	,1	,1	, &B2VS11LDU},	//( - , DU) Движение РБ2 в сторону ВУ
	{ 155	,1	,1	, &B2VS21LDU},	//( - , DU) Движение РБ2 в сторону НУ
	{ 156	,3	,1	, &B2VS01IDU},	//( - , DU) Готовность к управлению РБ2
	{ 157	,1	,1	, &A7AS31LDU},	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
	{ 158	,1	,1	, &B7AS31LDU},	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
	{ 159	,1	,1	, &A7AZ03LDU},	//( - , DU) Несанкционированное включение обдува АЗ1
	{ 160	,1	,1	, &B7AZ03LDU},	//( - , DU) Несанкционированное включение обдува АЗ2
	{ 161	,1	,1	, &B3MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
	{ 162	,1	,1	, &B2IS11LDU},	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
	{ 163	,1	,1	, &A3MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
	{ 164	,1	,1	, &A3MD11LP1},	//( - , DU) Кнопка ПУСК ИС1
	{ 165	,1	,1	, &R0MD33LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
	{ 166	,1	,1	, &A1MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
	{ 167	,1	,1	, &A1MD11LP1},	//( - , DU) Кнопка ПУСК ББ1
	{ 168	,3	,1	, &R0MW14IP2},	//( - , DU) Переключатель ОБДУВ
	{ 169	,1	,1	, &A7AP31LDU},	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
	{ 170	,1	,1	, &B7AP31LDU},	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
	{ 171	,3	,1	, &R0MW12IP2},	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
	{ 172	,1	,1	, &R0MW17LP1},	//( - , DU) Переключатель АВТ/Р
	{ 173	,1	,1	, &R0VW13LDU},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
	{ 174	,1	,1	, &R0VW23LDU},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
	{ 175	,3	,1	, &R0VX08IDU},	//( - , DU) Индикация Режим
	{ 176	,1	,1	, &R0VX09LDU},	//( - , DU) Индикация регулятор мощности включен/отключен
	{ 177	,1	,1	, &R0VS17LDU},	//( - , DU) Индикация выбора АВТОМАТ
	{ 178	,1	,1	, &A2VS32LDU},	//( - , DU) Индикация  СБРОС РБ1
	{ 179	,1	,1	, &B2VS32LDU},	//( - , DU) Индикация  СБРОС РБ2
	{ 180	,1	,1	, &A3VX01LDU},	//( - , DU) Индикация Выстрел ИС1
	{ 181	,1	,1	, &A3IS11LDU},	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
	{ 182	,1	,1	, &B3VX01LDU},	//( - , DU) Индикация Выстрел ИС2
	{ 183	,1	,1	, &R0VS18LDU},	//( - , DU) Индикация  Проверка схем сброса
	{ 184	,1	,1	, &B1MD11LP1},	//( - , DU) Кнопка ПУСК ББ2
	{ 185	,1	,1	, &B8MC01LC2},	//( - , DU) Настроить энкодер АЗ2
	{ 186	,1	,1	, &A8MC01LC1},	//( - , DU) Настроить энкодер ДС2
	{ 187	,1	,1	, &A8MC01LC2},	//( - , DU) Настроить энкодер ДС2
	{ 188	,1	,1	, &A3VP42LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
	{ 189	,8	,1	, &A3CP02RDU},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
	{ 190	,1	,1	, &A3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
	{ 191	,1	,1	, &B3VP42LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
	{ 192	,8	,1	, &B3CP02RDU},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
	{ 193	,1	,1	, &B3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
	{ 194	,1	,1	, &B3VP82LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
	{ 195	,1	,1	, &A3VP82LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
	{ 196	,3	,1	, &A3IP02IDU},	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
	{ 197	,3	,1	, &B3IP02IDU},	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
	{ 198	,1	,1	, &A0VE01LDU},	//( - , DU) Напряжение в системы АЗ1 подано
	{ 199	,1	,1	, &B0VE01LDU},	//( - , DU) Напряжение в системы АЗ2 подано
	{ 200	,1	,1	, &A0VP01LDU},	//( - , DU) Давление в системы АЗ1 подано
	{ 201	,1	,1	, &B0VP01LDU},	//( - , DU) Давление в системы АЗ2 подано
	{ 202	,1	,1	, &A0EE01LZ1},	//( - , MDuBz1) Исправность АКНП1
	{ 203	,1	,1	, &A0EE03LZ1},	//( - , MDuBz1) Исправность АКНП3
	{ 204	,1	,1	, &A0EE02LZ1},	//( - , MDuBz1) Исправность АКНП2
	{ 205	,1	,1	, &A0EE04LZ1},	//( - , MDuBz1) Исправность АКНП4
	{ 206	,1	,1	, &A0VN01LDU},	//( - , DU) Каналы АЗ1 проверены
	{ 207	,1	,1	, &B0VN01LDU},	//( - , DU) Каналы АЗ2 проверены
	{ 208	,5	,1	, &B2IC01UDU},	//( - , MDuS) Координата штока РБ2 (дел.энк)
	{ 209	,5	,1	, &A3IC01UDU},	//( - , MDuS) Координата штока ИС1 (дел.энк)
	{ 210	,5	,1	, &B3IC01UDU},	//( - , MDuS) Координата штока ИС2 (дел.энк)
	{ 211	,8	,1	, &B3VC01RDU},	//( - , DU) Координата ИС2, мм
	{ 212	,5	,1	, &A8IC01UDU},	//( - , MDuS) Координата ДС2 (дел.энк)
	{ 213	,8	,1	, &A8VC01RDU},	//( - , DU) Координата ДС2, мм
	{ 214	,5	,1	, &B8IC01UDU},	//( - , MDuS) Координата АЗ2 (дел.энк)
	{ 215	,5	,1	, &A1IC01UDU},	//( - , MDuS) Координата штока ББ1 (дел.энк)
	{ 216	,8	,1	, &A1VC01RDU},	//( - , DU) Координата ББ1, мм
	{ 217	,1	,1	, &A1IS11LDU},	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
	{ 218	,1	,1	, &B1MC01LC1},	//( - , DU) Настроить энкодер ББ2
	{ 219	,1	,1	, &B1MC01LC2},	//( - , DU) Настроить энкодер ББ2
	{ 220	,1	,1	, &A1MC01LC1},	//( - , DU) Настроить энкодер ББ1
	{ 221	,1	,1	, &A1MC01LC2},	//( - , DU) Настроить энкодер ББ1
	{ 222	,1	,1	, &B2MC01LC1},	//( - , DU) Настроить энкодер РБ2
	{ 223	,1	,1	, &B2MC01LC2},	//( - , DU) Настроить энкодер РБ2
	{ 224	,1	,1	, &A2MC01LC1},	//( - , DU) Настроить энкодер РБ1
	{ 225	,1	,1	, &A2MC01LC2},	//( - , DU) Настроить энкодер РБ1
	{ 226	,1	,1	, &B3MC01LC1},	//( - , DU) Настроить энкодер ИС2
	{ 227	,1	,1	, &B3MC01LC2},	//( - , DU) Настроить энкодер ИС2
	{ 228	,1	,1	, &A3MC01LC1},	//( - , DU) Настроить энкодер ИС1
	{ 229	,1	,1	, &A3MC01LC2},	//( - , DU) Настроить энкодер ИС1
	{ 230	,1	,1	, &B8MC01LC1},	//( - , DU) Настроить энкодер АЗ2
	{ 231	,1	,1	, &R0IE01LDU},	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
	{ 232	,1	,1	, &A6IE01LDU},	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
	{ 233	,1	,1	, &B6IE01LDU},	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
	{ 234	,1	,1	, &A8IE01LDU},	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
	{ 235	,1	,1	, &B5IE01LDU},	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
	{ 236	,1	,1	, &A5IE02LDU},	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
	{ 237	,1	,1	, &R1IE01LDU},	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
	{ 238	,1	,1	, &R2IE01LDU},	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
	{ 239	,1	,1	, &R6IS61LDU},	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
	{ 240	,1	,1	, &R6IS66LZZ},	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 241	,1	,1	, &R6IS67LZZ},	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 242	,1	,1	, &R6IS68LZZ},	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 243	,8	,1	, &A3VC01RDU},	//( - , DU) Координата ИС1, мм
	{ 244	,8	,1	, &A2VC01RDU},	//( - , DU) Координата РБ1, мм
	{ 245	,8	,1	, &B2VC01RDU},	//( - , DU) Координата РБ2, мм
	{ 246	,8	,1	, &B8VC01RDU},	//( - , DU, MDuBz1, MDuBz2) Координата АЗ2, мм
	{ 247	,1	,1	, &A4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
	{ 248	,1	,1	, &B4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
	{ 249	,1	,1	, &A2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
	{ 250	,1	,1	, &B2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
	{ 251	,1	,1	, &A3VP81LDU},	//( - , - ) Давление СПУСК ИС1 в норме
	{ 252	,1	,1	, &B3VP81LDU},	//( - , - ) Давление СПУСК ИС2 в норме
	{ 253	,1	,1	, &R0EE02LDU},	//( - , DU) Питание  АКНП  отключить
	{ 254	,1	,1	, &A0EE01LZ2},	//( - , MDuBz2) Исправность АКНП1
	{ 255	,1	,1	, &A0EE03LZ2},	//( - , MDuBz2) Исправность АКНП3
	{ 256	,1	,1	, &A0EE02LZ2},	//( - , MDuBz2) Исправность АКНП2
	{ 257	,1	,1	, &A0EE04LZ2},	//( - , MDuBz2) Исправность АКНП4
	{ 258	,1	,1	, &A0VP71LZ1},	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
	{ 259	,1	,1	, &A0VP71LZ2},	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
	{ 260	,1	,1	, &B0VP71LZ1},	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
	{ 261	,1	,1	, &B0VP71LZ2},	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
	{ 262	,1	,1	, &A0VS11LDU},	//( - , DU) АЗ1 готова к работе
	{ 263	,1	,1	, &B0VS11LDU},	//( - , DU) АЗ2 готова к работе
	{ 264	,1	,1	, &A1IE01LDU},	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
	{ 265	,1	,1	, &A3IE01LDU},	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
	{ 266	,1	,1	, &A2IE01LDU},	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
	{ 267	,1	,1	, &A1IE02LDU},	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
	{ 268	,1	,1	, &A3IE02LDU},	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
	{ 269	,1	,1	, &A2IE02LDU},	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
	{ 270	,1	,1	, &B1IE01LDU},	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
	{ 271	,1	,1	, &B2IE01LDU},	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
	{ 272	,1	,1	, &B3IE01LDU},	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
	{ 273	,1	,1	, &B1IE02LDU},	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
	{ 274	,1	,1	, &B3IE02LDU},	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
	{ 275	,1	,1	, &B2IE02LDU},	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
	{ 276	,1	,1	, &R0IE02LDU},	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
	{ 277	,1	,1	, &R0AD03LZ2},	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
	{ 278	,1	,1	, &R0AD04LZ1},	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
	{ 279	,1	,1	, &R0AD04LZ2},	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
	{ 280	,1	,1	, &R0AD05LZ1},	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
	{ 281	,1	,1	, &R0AD05LZ2},	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
	{ 282	,1	,1	, &B8IS12LDU},	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
	{ 283	,1	,1	, &B8IS21LDU},	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
	{ 284	,1	,1	, &A1VP41LZ1},	//( - , MDuBz1) Давление СБРОС ББ1 ниже АС
	{ 285	,1	,1	, &A1VP41LZ2},	//( - , MDuBz2) Давление СБРОС ББ1 ниже АС
	{ 286	,1	,1	, &R0VL22LDU},	//( - , DU) Конец программы 200сек
	{ 287	,1	,1	, &R0VL23LDU},	//( - , DU) Конец программы 20мин
	{ 288	,1	,1	, &B1VP41LZ1},	//( - , MDuBz1) Давление СБРОС ББ2 ниже АС
	{ 289	,1	,1	, &B1VP41LZ2},	//( - , MDuBz2) Давление СБРОС ББ2 ниже АС
	{ 290	,1	,1	, &A3AB19LDU},	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
	{ 291	,1	,1	, &B3AB19LDU},	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
	{ 292	,1	,1	, &A3EE03LDU},	//( - , DU) ВПИС ИС1
	{ 293	,1	,1	, &B3EE03LDU},	//( - , DU) ВПИС ИС2
	{ 294	,1	,1	, &B3AB15LDU},	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
	{ 295	,1	,1	, &R5IS21LDU},	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
	{ 296	,1	,1	, &R5VS22LDU},	//( - , DU) Движение ворот отстойной зоны к закрыты
	{ 297	,1	,1	, &R5VS12LDU},	//( - , DU) Движение ворот отстойной зоны к открыты
	{ 298	,3	,1	, &R5VS01IDU},	//( - , DU) Готовность к управлению ворот отстойной зоны
	{ 299	,1	,1	, &R3VS22LDU},	//( - , DU) Движение гомогенных дверей к закрыты
	{ 300	,8	,1	, &R0VN09RZ2},	//( - , MDuBz2) Усредненный период разгона
	{ 301	,8	,1	, &R0VN09RZ1},	//( - , MDuBz1) Усредненный период разгона
	{ 302	,1	,1	, &R0AB16LDU},	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
	{ 303	,1	,1	, &R0AB17LDU},	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
	{ 304	,1	,1	, &R0AB18LDU},	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
	{ 305	,8	,1	, &A0CT01IZ1},	//( - , MDuBz1) Температура АЗ1-1
	{ 306	,8	,1	, &B0CT01IZ1},	//( - , MDuBz1) Температура АЗ2-1
	{ 307	,8	,1	, &A0CT01IZ2},	//( - , MDuBz2) Температура АЗ1-2
	{ 308	,8	,1	, &B0CT01IZ2},	//( - , MDuBz2) Температура АЗ2-2
	{ 309	,8	,1	, &A3MC01RDU},	//( - , DU) Заданная координата положения ИС от регулятора мм
	{ 310	,8	,1	, &A3MC02RDU},	//( - , DU) Температурная корректировка координаты ИМ
	{ 311	,8	,1	, &R0CN91LDU},	//( - , DU) Рассчётная реактивность от регулятора
	{ 312	,8	,1	, &A3MC03RDU},	//( - , DU) Координата положения ИМ 0-й реактивности
	{ 313	,1	,1	, &A3AB15LDU},	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
	{ 314	,1	,1	, &R0AB20LDU},	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
	{ 315	,8	,1	, &R0CN92LDU},	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
	{ 316	,8	,1	, &R0VN11RDU},	//( - , DU) Текущая мощность РУ
	{ 317	,8	,1	, &R0VN12RDU},	//( - , DU) Заданная мощность РУ
	{ 318	,1	,1	, &R0AB19LDU},	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
	{ 319	,8	,1	, &R0CN93LDU},	//( - , DU) время работы на мощности более 100Вт, сек
	{ 320	,8	,1	, &R0CN94LDU},	//( - , DU) Скорость изменения мощности
	{ 321	,3	,1	, &R0CN95LDU},	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
	{ 322	,1	,1	, &R0AD03LZ1},	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
	{ 323	,1	,1	, &R0DE37LDU},	//(sbk:20 - S07SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 2
	{ 324	,1	,1	, &R0DE38LDU},	//(sbk:20 - S08SBK, DiagnDU) диагностика шкафа ДУ МП15-3 место 3
	{ 325	,1	,1	, &R0DE39LDU},	//(sbk:20 - S09SBK, DiagnDU) диагностика шкафа ДУ МП24-2 место 4
	{ 326	,1	,1	, &R0DEB3LDU},	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
	{ 327	,1	,1	, &R0DEB2LDU},	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
	{ 328	,1	,1	, &R0DEB1LDU},	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
	{ 329	,1	,1	, &R0DEB4LDU},	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
	{ 330	,1	,1	, &R0DE3DLDU},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
	{ 331	,1	,1	, &R0DE3CLDU},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
	{ 332	,1	,1	, &TestDiagnDU},	//( - , DU) Неисправность от
	{ 333	,8	,1	, &B3CV01RDU},	//( - , DU) Измеренная скорость перемещения ИС2
	{ 334	,5	,1	, &venc01},	//(vencf8l:01 - venc01, - ) заначение реального энкодера ББ1
	{ 335	,5	,1	, &venc02},	//(vencf8l:01 - venc02, - ) заначение реального энкодера РБ1
	{ 336	,5	,1	, &venc03},	//(vencf8l:01 - venc03, - ) заначение реального энкодера ИС1
	{ 337	,5	,1	, &venc04},	//(vencf8l:01 - venc04, - ) заначение реального энкодера ДС2
	{ 338	,5	,1	, &venc05},	//(vencf8l:01 - venc05, - ) заначение реального энкодера ББ2
	{ 339	,5	,1	, &venc06},	//(vencf8l:01 - venc06, - ) заначение реального энкодера РБ2
	{ 340	,5	,1	, &venc07},	//(vencf8l:01 - venc07, - ) заначение реального энкодера ИС2
	{ 341	,5	,1	, &venc08},	//(vencf8l:01 - venc08, - ) заначение реального энкодера АЗ2
	{ 342	,5	,1	, &B1IC01UDU},	//( - , MDuS) Координата штока ББ2 (дел.энк)
	{ 343	,8	,1	, &B1VC01RDU},	//( - , DU) Координата ББ2, мм
	{ 344	,1	,1	, &B1IS11LDU},	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
	{ 345	,5	,1	, &A2IC01UDU},	//( - , MDuS) Координата штока РБ1 (дел.энк)
	{ 346	,1	,1	, &R3VS12LDU},	//( - , DU) Движение гомогенных дверей к открыты
	{ 347	,3	,1	, &R3VS01IDU},	//( - , DU) Готовность к управлению гомогенных дверей
	{ 348	,1	,1	, &A3AB13LDU},	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
	{ 349	,1	,1	, &B3AB13LDU},	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
	{ 350	,3	,1	, &R0DE02LDU},	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
	{ 351	,3	,1	, &R0DE03LDU},	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
	{ 352	,3	,1	, &R0DE04LDU},	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
	{ 353	,3	,1	, &R0DE08LDU},	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
	{ 354	,3	,1	, &R0DE05LDU},	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
	{ 355	,3	,1	, &R0DE09LDU},	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
	{ 356	,3	,1	, &R0DE0ALDU},	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
	{ 357	,3	,1	, &R0DE07LDU},	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
	{ 358	,3	,1	, &R0DE0CLDU},	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
	{ 359	,3	,1	, &R0DE0BLDU},	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
	{ 360	,3	,1	, &R0DE0DLDU},	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
	{ 361	,3	,1	, &R0DE0FLDU},	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
	{ 362	,1	,1	, &R0DE31LDU},	//(sbk:20 - S01SBK, DiagnDU) диагностика шкафа ДУ сеть 1
	{ 363	,3	,1	, &TTLDU},	//( - , DU) ttl
	{ 364	,1	,1	, &R0DE32LDU},	//(sbk:20 - S02SBK, DiagnDU) диагностика шкафа ДУ сеть 2
	{ 365	,1	,1	, &R0DE33LDU},	//(sbk:20 - S03SBK, DiagnDU) диагностика шкафа ДУ двери
	{ 366	,1	,1	, &R0DE34LDU},	//(sbk:20 - S04SBK, DiagnDU) диагностика шкафа ДУ температура меньше 43
	{ 367	,1	,1	, &R0DE35LDU},	//(sbk:20 - S05SBK, DiagnDU) диагностика шкафа ДУ температура больше 53
	{ 368	,1	,1	, &R0DE36LDU},	//(sbk:20 - S06SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 1
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
	{ 553	,1	,1	, &A3AD02LDU},	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
	{ 554	,1	,1	, &A3AD03LDU},	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
	{ 555	,1	,1	, &A3AD04LDU},	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
	{ 556	,1	,1	, &A3AD05LDU},	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
	{ 557	,1	,1	, &A3AD01LDU},	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
	{ 558	,8	,1	, &A3CV02RDU},	//( - , DU) Заданная скорость перемещения ИС1
	{ 559	,1	,1	, &A3AB07LDU},	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
	{ 560	,1	,1	, &A3AB08LDU},	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
	{ 561	,1	,1	, &A3AB05LDU},	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
	{ 562	,1	,1	, &A3AB06LDU},	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
	{ 563	,1	,1	, &A3AB09LDU},	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
	{ 564	,1	,1	, &A3AB10LDU},	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
	{ 565	,1	,1	, &A3AB11LDU},	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
	{ 566	,1	,1	, &A3AB12LDU},	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 567	,1	,1	, &A3AB14LDU},	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
	{ 568	,1	,1	, &A3AB16LDU},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
	{ 569	,1	,1	, &A3AB17LDU},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
	{ 570	,1	,1	, &A3AB18LDU},	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
	{ 571	,1	,1	, &A3AB20LDU},	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
	{ 572	,1	,1	, &B3VS12LDU},	//( - , DU) Движение ИС2 в сторону ВУ
	{ 573	,1	,1	, &B3AB04LDU},	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
	{ 574	,1	,1	, &B3AB02LDU},	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
	{ 575	,1	,1	, &B3AB01LDU},	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
	{ 576	,8	,1	, &B1CV02RDU},	//( - , DU) Заданная скорость перемещения ББ2
	{ 577	,1	,1	, &B1AB07LDU},	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
	{ 578	,1	,1	, &B1AB08LDU},	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
	{ 579	,1	,1	, &B1AB05LDU},	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
	{ 580	,1	,1	, &B1AB06LDU},	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
	{ 581	,1	,1	, &B1AB09LDU},	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
	{ 582	,1	,1	, &B1AB10LDU},	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
	{ 583	,1	,1	, &B1AB11LDU},	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
	{ 584	,1	,1	, &B1AB12LDU},	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 585	,1	,1	, &B1AB13LDU},	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
	{ 586	,1	,1	, &B1AB14LDU},	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
	{ 587	,1	,1	, &B1AB16LDU},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
	{ 588	,1	,1	, &B1AB17LDU},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
	{ 589	,1	,1	, &B1AB18LDU},	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
	{ 590	,1	,1	, &A3VS12LDU},	//( - , DU) Движение ИС1 в сторону ВУ
	{ 591	,8	,1	, &A3CV01RDU},	//( - , DU) Измеренная скорость перемещения ИС1
	{ 592	,1	,1	, &A3AB04LDU},	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
	{ 593	,1	,1	, &A3AB02LDU},	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
	{ 594	,1	,1	, &A3AB01LDU},	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
	{ 595	,1	,1	, &A3VS22LDU},	//( - , DU) Движение ИС1 в сторону НУ
	{ 596	,1	,1	, &A3AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
	{ 597	,1	,1	, &A3AD11LDU},	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
	{ 598	,1	,1	, &A3AD21LDU},	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
	{ 599	,1	,1	, &C1MD31LP1},	//( - , DU) Кнопка СБРОС ББ
	{ 600	,1	,1	, &C1MD31LP2},	//( - , DU) Кнопка СБРОС ББ
	{ 601	,1	,1	, &A2AD31LDU},	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
	{ 602	,1	,1	, &B2AD31LDU},	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
	{ 603	,1	,1	, &A1AD31LDU},	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
	{ 604	,1	,1	, &B1AD31LDU},	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
	{ 605	,1	,1	, &A2AD32LDU},	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
	{ 606	,1	,1	, &B2AD32LDU},	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
	{ 607	,1	,1	, &A1AD32LDU},	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
	{ 608	,1	,1	, &B1AD32LDU},	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
	{ 609	,1	,1	, &R0MD11LP2},	//( - , DU) Кнопка Пуск проверки схем сброса
	{ 610	,1	,1	, &R0VX01LDU},	//( - , DU) ДО ИМПУЛЬСА
	{ 611	,3	,1	, &R0VL01IDU},	//( - , DU) До импульса минут
	{ 612	,3	,1	, &R0VL11IDU},	//( - , DU) До импульса секунд
	{ 613	,8	,1	, &R0VL06RDU},	//( - , DU) Индикация (Время задержки от ВУ РБ)
	{ 614	,1	,1	, &B3AD33LDU},	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
	{ 615	,1	,1	, &B3IS11LDU},	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
	{ 616	,8	,1	, &R0VL02RDU},	//( - , DU) Индикация (Время задержки ИНИ)
	{ 617	,1	,1	, &R8AD21LDU},	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
	{ 618	,1	,1	, &R0AD14LDU},	//( - , DU) Имитация срабатывания верхней АС II УР
	{ 619	,8	,1	, &R0VL04RDU},	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
	{ 620	,1	,1	, &R0AB04LDU},	//( - , DU) Нарушение времени срабатывания верхней АС II УР
	{ 621	,1	,1	, &R0AB06LDU},	//( - , DU) Нарушение времени задержки от ВУ РБ
	{ 622	,1	,1	, &B3VS22LDU},	//( - , DU) Движение ИС2 в сторону НУ
	{ 623	,1	,1	, &B3AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
	{ 624	,1	,1	, &B3AD11LDU},	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
	{ 625	,1	,1	, &B3AD21LDU},	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
	{ 626	,1	,1	, &B3AD02LDU},	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
	{ 627	,1	,1	, &B3AD03LDU},	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
	{ 628	,1	,1	, &B3AD04LDU},	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
	{ 629	,1	,1	, &B3AD05LDU},	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
	{ 630	,1	,1	, &B3AD01LDU},	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
	{ 631	,8	,1	, &B3CV02RDU},	//( - , DU) Заданная скорость перемещения ИС2
	{ 632	,1	,1	, &B3AB07LDU},	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
	{ 633	,1	,1	, &B3AB08LDU},	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
	{ 634	,1	,1	, &B3AB05LDU},	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
	{ 635	,1	,1	, &B3AB06LDU},	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
	{ 636	,1	,1	, &B3AB09LDU},	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
	{ 637	,1	,1	, &B3AB10LDU},	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
	{ 638	,1	,1	, &B3AB11LDU},	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
	{ 639	,1	,1	, &B3AB12LDU},	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{ 640	,1	,1	, &B3AB14LDU},	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
	{ 641	,1	,1	, &B3AB16LDU},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
	{ 642	,1	,1	, &B3AB17LDU},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
	{ 643	,1	,1	, &B3AB18LDU},	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
	{ 644	,1	,1	, &B3AB20LDU},	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
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
	{ 691	,1	,1	, &A1AB09LDU},	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
	{ 692	,1	,1	, &A1AB10LDU},	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
	{ 693	,1	,1	, &A1AB11LDU},	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
	{ 694	,1	,1	, &A1AB12LDU},	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 695	,1	,1	, &A1AB13LDU},	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
	{ 696	,1	,1	, &A1AB14LDU},	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
	{ 697	,1	,1	, &A1AB16LDU},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
	{ 698	,1	,1	, &A1AB17LDU},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
	{ 699	,1	,1	, &A1AB18LDU},	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
	{ 700	,1	,1	, &B1VS12LDU},	//( - , DU) Движение ББ2 в сторону ВУ
	{ 701	,8	,1	, &B1CV01RDU},	//( - , DU) Измеренная скорость перемещения ББ2
	{ 702	,1	,1	, &B1AB04LDU},	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
	{ 703	,1	,1	, &B1AB02LDU},	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
	{ 704	,1	,1	, &B1AB01LDU},	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
	{ 705	,1	,1	, &B1VS22LDU},	//( - , DU) Движение ББ2 в сторону НУ
	{ 706	,1	,1	, &B1AZ03LDU},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
	{ 707	,1	,1	, &B1AD11LDU},	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
	{ 708	,1	,1	, &B1AD21LDU},	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
	{ 709	,1	,1	, &B1AD02LDU},	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
	{ 710	,1	,1	, &B1AD03LDU},	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
	{ 711	,1	,1	, &B1AD04LDU},	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
	{ 712	,1	,1	, &B1AD05LDU},	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
	{ 713	,1	,1	, &B1AD01LDU},	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
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
	{ 737	,1	,1	, &A1AB06LDU},	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
	{ 738	,8	,1	, &fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
	{ 739	,5	,1	, &dEM_A1UC05UDU},	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
	{ 740	,5	,1	, &dEM_A1UC06UDU},	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
	{ 741	,5	,1	, &dEM_A2UC06UDU},	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
	{ 742	,5	,1	, &dEM_A2UC05UDU},	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
	{ 743	,8	,1	, &fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
	{ 744	,5	,1	, &dEM_A3UC06UDU},	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
	{ 745	,5	,1	, &dEM_A3UC05UDU},	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
	{ 746	,8	,1	, &fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
	{ 747	,5	,1	, &dEM_A8UC06UDU},	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
	{ 748	,8	,1	, &fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
	{ 749	,5	,1	, &dEM_A8UC05UDU},	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
	{ 750	,8	,1	, &fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{ 751	,8	,1	, &fEM_R0UV82RDU},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{ 752	,8	,1	, &fEM_R0UV83RDU},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{ 753	,8	,1	, &fEM_R0UV84RDU},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{ 754	,8	,1	, &fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 755	,8	,1	, &fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{ 756	,8	,1	, &fEM_R0UV87RDU},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 757	,8	,1	, &fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{ 758	,8	,1	, &fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{ 759	,8	,1	, &fEM_A3UP43RDU},	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
	{ 760	,8	,1	, &fEM_A3UP44RDU},	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
	{ 761	,8	,1	, &fEM_A3UP53RDU},	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
	{ 762	,8	,1	, &fEM_A3UP85RDU},	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 763	,8	,1	, &fEM_A3UP88RDU},	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 764	,8	,1	, &fEM_A3UP86RDU},	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 765	,8	,1	, &fEM_B8UV01RDU},	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
	{ 766	,8	,1	, &fEM_B8UV02RDU},	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
	{ 767	,8	,1	, &fEM_B8UV03RDU},	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
	{ 768	,8	,1	, &fEM_B8UL04RDU},	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
	{ 769	,3	,1	, &iEM_A2UV03CDU},	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
	{ 770	,8	,1	, &fEM_A2UV01RDU},	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
	{ 771	,8	,1	, &fEM_A2UV02RDU},	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
	{ 772	,8	,1	, &fEM_A1UV01RDU},	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
	{ 773	,8	,1	, &fEM_A1UV02RDU},	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
	{ 774	,8	,1	, &fEM_A1UC06RDU},	//(A1UC06RDU) Уставка определения самохода ББ  мм
	{ 775	,8	,1	, &fEM_A1UC05RDU},	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
	{ 776	,8	,1	, &fEM_A1UL04RDU},	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
	{ 777	,8	,1	, &fEM_A3UV01RDU},	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
	{ 778	,8	,1	, &fEM_A3UV02RDU},	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
	{ 779	,8	,1	, &fEM_A3UC06RDU},	//(A3UC06RDU) Уставка определения самохода ИС1  мм
	{ 780	,8	,1	, &fEM_A3UC05RDU},	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
	{ 781	,8	,1	, &fEM_A3UL04RDU},	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
	{ 782	,8	,1	, &fEM_A3UP54RDU},	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
	{ 783	,8	,1	, &fEM_A3UP87RDU},	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 784	,8	,1	, &fEM_R0UL05RDU},	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
	{ 785	,8	,1	, &fEM_R0UL20RDU},	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
	{ 786	,8	,1	, &fEM_B8UV04RDU},	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
	{ 787	,8	,1	, &fEM_B8UC06RDU},	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
	{ 788	,8	,1	, &fEM_B8UC05RDU},	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
	{ 789	,8	,1	, &fEM_A2UL05RDU},	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
	{ 790	,8	,1	, &fEM_A2UL03RDU},	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{ 791	,8	,1	, &fEM_A2UC06RDU},	//(A2UC06RDU) Уставка определения самохода РБ  мм
	{ 792	,8	,1	, &fEM_A2UC05RDU},	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
	{ 793	,8	,1	, &fEM_A2UL04RDU},	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
	{ 794	,8	,1	, &fEM_A1UL03RDU},	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
	{ 795	,8	,1	, &fEM_A1UL05RDU},	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
	{ 796	,8	,1	, &fEM_A3UL03RDU},	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
	{ 797	,8	,1	, &fEM_A3UL05RDU},	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
	{ 798	,8	,1	, &fEM_A1UC08RDU},	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
	{ 799	,8	,1	, &fEM_A3UC08RDU},	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
	{ 800	,8	,1	, &fEM_A1UC07RDU},	//(A1UC07RDU) Зона возврата при наведении ББ мм
	{ 801	,8	,1	, &fEM_A1UL01RDU},	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 802	,8	,1	, &fEM_A3UC07RDU},	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
	{ 803	,8	,1	, &fEM_A3UL01RDU},	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 804	,8	,1	, &fEM_A2UC08RDU},	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
	{ 805	,8	,1	, &fEM_A2UC07RDU},	//(A2UC07RDU) Зона возврата при наведении РБ  мм
	{ 806	,8	,1	, &fEM_A2UL01RDU},	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 807	,8	,1	, &fEM_B8UC01RDU},	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
	{ 808	,8	,1	, &fEM_B8UL07RDU},	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
	{ 809	,8	,1	, &fEM_B8UC02RDU},	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
	{ 810	,8	,1	, &fEM_B8UL01RDU},	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 811	,8	,1	, &fEM_B8UL05RDU},	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
	{ 812	,8	,1	, &fEM_B8UL03RDU},	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
	{ 813	,8	,1	, &fEM_B8UL06RDU},	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
	{ 814	,8	,1	, &fEM_A9UZ03RDU},	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
	{ 815	,8	,1	, &fEM_A9UZ04RDU},	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
	{ 816	,8	,1	, &fEM_A9UZ05RDU},	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
	{ 817	,8	,1	, &fEM_R4UZ04RDU},	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
	{ 818	,8	,1	, &fEM_R4UZ03RDU},	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
	{ 819	,8	,1	, &fEM_R4UZ05RDU},	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
	{ 820	,8	,1	, &fEM_A5UZ03RDU},	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
	{ 821	,8	,1	, &fEM_A5UZ04RDU},	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
	{ 822	,8	,1	, &fEM_A5UZ05RDU},	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
	{ 823	,8	,1	, &fEM_A4UZ03RDU},	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
	{ 824	,8	,1	, &fEM_A4UZ04RDU},	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
	{ 825	,8	,1	, &fEM_A4UZ05RDU},	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
	{ 826	,8	,1	, &fEM_A6UZ03RDU},	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
	{ 827	,8	,1	, &fEM_A6UZ04RDU},	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
	{ 828	,8	,1	, &fEM_A6UZ05RDU},	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
	{ 829	,8	,1	, &fEM_R1UZ03RDU},	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
	{ 830	,8	,1	, &fEM_R1UZ04RDU},	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
	{ 831	,8	,1	, &fEM_R1UZ05RDU},	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
	{ 832	,8	,1	, &fEM_R0UL04RDU},	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
	{ 833	,8	,1	, &fEM_R0UL06RDU},	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
	{ 834	,8	,1	, &fEM_R0UL03RDU},	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
	{ 835	,8	,1	, &fEM_R0UL17RDU},	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
	{ 836	,8	,1	, &fEM_R0UL19RDU},	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{ 837	,8	,1	, &fEM_R0UL07RDU},	//(R0UL07RDU) Время срабатывания верхней АС II УР
	{ 838	,8	,1	, &fEM_R0UL18RDU},	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
	{ 839	,8	,1	, &fEM_R0UL16RDU},	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
	{ 840	,8	,1	, &fEM_R0UL02RDU},	//(R0UL02RDU) Время задержки  ИНИ
	{ 841	,8	,1	, &fEM_R0UN08RDU},	//(R0UN08RDU) 8-я заданная мощность
	{ 842	,8	,1	, &fEM_R0UN07RDU},	//(R0UN07RDU) 7-я заданная мощность
	{ 843	,8	,1	, &fEM_R0UN06RDU},	//(R0UN06RDU) 6-я заданная мощность
	{ 844	,8	,1	, &fEM_R0UN05RDU},	//(R0UN05RDU) 5-я заданная мощность
	{ 845	,8	,1	, &fEM_R0UN04RDU},	//(R0UN04RDU) 4-я заданная мощность
	{ 846	,8	,1	, &fEM_R0UN03RDU},	//(R0UN03RDU) Ограничение 3 по мощности
	{ 847	,8	,1	, &fEM_R0UN02RDU},	//(R0UN02RDU) 2-я заданная мощность
	{ 848	,8	,1	, &fEM_R0UN01RDU},	//(R0UN01RDU) 1-я заданная мощность
	{ 849	,8	,1	, &fEM_A2UC82RDU},	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
	{ 850	,8	,1	, &fEM_A2UC83RDU},	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
	{ 851	,8	,1	, &fEM_A1UC83RDU},	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
	{ 852	,8	,1	, &fEM_A2UC81RDU},	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
	{ 853	,8	,1	, &fEM_A1UC81RDU},	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
	{ 854	,8	,1	, &fEM_A1UC82RDU},	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
	{ 855	,8	,1	, &fEM_A2UL83RDU},	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{ 856	,8	,1	, &fEM_A3UC81RDU},	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
	{ 857	,8	,1	, &fEM_A3UC82RDU},	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
	{ 858	,8	,1	, &fEM_R0UN80RDU},	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
	{ 859	,3	,1	, &iEM_A2UV01IDU},	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
	{ 860	,3	,1	, &iEM_A2UV02IDU},	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
	{ 861	,3	,1	, &iEM_A1UV01IDU},	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
	{ 862	,3	,1	, &iEM_A1UV02IDU},	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
	{ 863	,3	,1	, &iEM_A1UV03IDU},	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
	{ 864	,3	,1	, &iEM_A3UV01IDU},	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
	{ 865	,3	,1	, &iEM_A3UV02IDU},	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
	{ 866	,1	,1	, &lEM_R0MD01LC1},	//(R0MD01LC1) Ручное управление ОРР
	{ 867	,8	,1	, &fEM_A3UC09RDU},	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
	{ 868	,8	,1	, &fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
	{ 869	,8	,1	, &fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
	{ 870	,8	,1	, &fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
	{ 871	,8	,1	, &fEM_R0UL21RDU},	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
	{ 872	,8	,1	, &fEM_R0UN09RDU},	//(R0UN09RDU) Минимальный период при регулировании мощности
	{ 873	,8	,1	, &fEM_R0UN11RDU},	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
	{ 874	,8	,1	, &fEM_R0UN12RDU},	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
	{ 875	,8	,1	, &fEM_R0UN13RDU},	//(R0UN13RDU) Минимальное изменение координаты, мм
	{ 876	,8	,1	, &fEM_R0UN14RDU},	//(R0UN14RDU) Максимальная координата штока ИМ, мм
	{ 877	,8	,1	, &fEM_R0UN16RDU},	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
	{ 878	,8	,1	, &fEM_R0UN17RDU},	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
	{ 879	,8	,1	, &fEM_R0UN18RDU},	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
	{ 880	,8	,1	, &fEM_R0UN19RDU},	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
	{ 881	,8	,1	, &fEM_R0UN70LDU},	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
	{ 882	,8	,1	, &fEM_R0UN71LDU},	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
	{ 883	,8	,1	, &fEM_R0UN72LDU},	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
	{ 884	,8	,1	, &fEM_R0UN73LDU},	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
	{ 885	,8	,1	, &fEM_R0UN74LDU},	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
	{ 886	,8	,1	, &fEM_R0UN75LDU},	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
	{ 887	,8	,1	, &fEM_R0UN80LDU},	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
	{ 888	,8	,1	, &fEM_R0UN81LDU},	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
	{ 889	,8	,1	, &fEM_R0UN82LDU},	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
	{ 890	,8	,1	, &fEM_R0UN83LDU},	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
	{ 891	,8	,1	, &fEM_R0UN84LDU},	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
	{ 892	,8	,1	, &fEM_R0UN85LDU},	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
	{ 893	,8	,1	, &fEM_R0UT20RDU},	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
	{ 894	,8	,1	, &fEM_R0UN25RDU},	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
	{ 895	,8	,1	, &fEM_R0UN15RDU},	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
	{ 896	,8	,1	, &fEM_R0UN26RDU},	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
	{ 897	,8	,1	, &fEM_R0UN27RDU},	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
	{ 898	,8	,1	, &fEM_R0UN24RDU},	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 899	,8	,1	, &fEM_R0UL25RDU},	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{ 900	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 901	,8	,1	, &internal2_m182_tx},	//(internal2_m182_tx) tx - время накопленное сек
	{ 902	,18	,1	, &internal2_m182_y0},	//(internal2_m182_y0) y0
	{ 903	,8	,1	, &internal2_m176_tx},	//(internal2_m176_tx) tx - время накопленное сек
	{ 904	,18	,1	, &internal2_m176_y0},	//(internal2_m176_y0) y0
	{ 905	,8	,1	, &internal2_m173_tx},	//(internal2_m173_tx) tx - время накопленное сек
	{ 906	,18	,1	, &internal2_m173_y0},	//(internal2_m173_y0) y0
	{ 907	,8	,1	, &internal2_m165_tx},	//(internal2_m165_tx) tx - время накопленное сек
	{ 908	,18	,1	, &internal2_m165_y0},	//(internal2_m165_y0) y0
	{ 909	,8	,1	, &internal2_m158_tx},	//(internal2_m158_tx) tx - время накопленное сек
	{ 910	,18	,1	, &internal2_m158_y0},	//(internal2_m158_y0) y0
	{ 911	,8	,1	, &internal2_m155_tx},	//(internal2_m155_tx) tx - время накопленное сек
	{ 912	,18	,1	, &internal2_m155_y0},	//(internal2_m155_y0) y0
	{ 913	,8	,1	, &internal2_m149_tx},	//(internal2_m149_tx) tx - время накопленное сек
	{ 914	,18	,1	, &internal2_m149_y0},	//(internal2_m149_y0) y0
	{ 915	,8	,1	, &internal2_m144_tx},	//(internal2_m144_tx) tx - время накопленное сек
	{ 916	,18	,1	, &internal2_m144_y0},	//(internal2_m144_y0) y0
	{ 917	,8	,1	, &internal2_m141_tx},	//(internal2_m141_tx) tx - время накопленное сек
	{ 918	,18	,1	, &internal2_m141_y0},	//(internal2_m141_y0) y0
	{ 919	,8	,1	, &internal2_m134_tx},	//(internal2_m134_tx) tx - время накопленное сек
	{ 920	,18	,1	, &internal2_m134_y0},	//(internal2_m134_y0) y0
	{ 921	,8	,1	, &internal2_m132_tx},	//(internal2_m132_tx) tx - время накопленное сек
	{ 922	,18	,1	, &internal2_m132_y0},	//(internal2_m132_y0) y0
	{ 923	,8	,1	, &internal2_m127_tx},	//(internal2_m127_tx) tx - время накопленное сек
	{ 924	,18	,1	, &internal2_m127_y0},	//(internal2_m127_y0) y0
	{ 925	,8	,1	, &internal2_m195_y0},	//(internal2_m195_y0) y0
	{ 926	,8	,1	, &internal2_m193_y0},	//(internal2_m193_y0) y0
	{ 927	,1	,1	, &internal2_m228_y0},	//(internal2_m228_y0) state
	{ 928	,1	,1	, &internal2_m220_y0},	//(internal2_m220_y0) state
	{ 929	,1	,1	, &internal2_m208_y1},	//(internal2_m208_y1) y1 - внутренний параметр
	{ 930	,1	,1	, &internal2_m214_y1},	//(internal2_m214_y1) y1 - внутренний параметр
	{ 931	,1	,1	, &internal2_m198_y1},	//(internal2_m198_y1) y1 - внутренний параметр
	{ 932	,1	,1	, &internal2_m205_y1},	//(internal2_m205_y1) y1 - внутренний параметр
	{ 933	,5	,1	, &internal2_m17_Nk0},	//(internal2_m17_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 934	,1	,1	, &internal2_m17_SetFlag},	//(internal2_m17_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 935	,5	,1	, &internal2_m110_Nk0},	//(internal2_m110_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 936	,1	,1	, &internal2_m110_SetFlag},	//(internal2_m110_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 937	,5	,1	, &internal2_m106_Nk0},	//(internal2_m106_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 938	,1	,1	, &internal2_m106_SetFlag},	//(internal2_m106_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 939	,5	,1	, &internal2_m75_Nk0},	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 940	,1	,1	, &internal2_m75_SetFlag},	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 941	,5	,1	, &internal2_m77_Nk0},	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 942	,1	,1	, &internal2_m77_SetFlag},	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 943	,5	,1	, &internal2_m49_Nk0},	//(internal2_m49_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 944	,1	,1	, &internal2_m49_SetFlag},	//(internal2_m49_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 945	,5	,1	, &internal2_m53_Nk0},	//(internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 946	,1	,1	, &internal2_m53_SetFlag},	//(internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 947	,5	,1	, &internal2_m15_Nk0},	//(internal2_m15_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 948	,1	,1	, &internal2_m15_SetFlag},	//(internal2_m15_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 949	,8	,1	, &internal1_m2019_tx},	//(internal1_m2019_tx) tx - внутренний параметр
	{ 950	,8	,1	, &internal1_m2018_tx},	//(internal1_m2018_tx) tx - внутренний параметр
	{ 951	,8	,1	, &internal1_m774_tx},	//(internal1_m774_tx) tx - внутренний параметр
	{ 952	,8	,1	, &internal1_m731_tx},	//(internal1_m731_tx) tx - внутренний параметр
	{ 953	,8	,1	, &internal1_m788_tx},	//(internal1_m788_tx) tx - внутренний параметр
	{ 954	,8	,1	, &internal1_m785_tx},	//(internal1_m785_tx) tx - внутренний параметр
	{ 955	,8	,1	, &internal1_m784_tx},	//(internal1_m784_tx) tx - внутренний параметр
	{ 956	,8	,1	, &internal1_m740_tx},	//(internal1_m740_tx) tx - внутренний параметр
	{ 957	,8	,1	, &internal1_m729_tx},	//(internal1_m729_tx) tx - внутренний параметр
	{ 958	,8	,1	, &internal1_m735_tx},	//(internal1_m735_tx) tx - внутренний параметр
	{ 959	,8	,1	, &internal1_m766_tx},	//(internal1_m766_tx) tx - внутренний параметр
	{ 960	,8	,1	, &internal1_m783_tx},	//(internal1_m783_tx) tx - внутренний параметр
	{ 961	,8	,1	, &internal1_m756_tx},	//(internal1_m756_tx) tx - внутренний параметр
	{ 962	,8	,1	, &internal1_m387_tx},	//(internal1_m387_tx) tx - внутренний параметр
	{ 963	,8	,1	, &internal1_m386_tx},	//(internal1_m386_tx) tx - внутренний параметр
	{ 964	,8	,1	, &internal1_m385_tx},	//(internal1_m385_tx) tx - внутренний параметр
	{ 965	,8	,1	, &internal1_m384_tx},	//(internal1_m384_tx) tx - внутренний параметр
	{ 966	,8	,1	, &internal1_m755_tx},	//(internal1_m755_tx) tx - внутренний параметр
	{ 967	,8	,1	, &internal1_m750_tx},	//(internal1_m750_tx) tx - внутренний параметр
	{ 968	,8	,1	, &internal1_m759_tx},	//(internal1_m759_tx) tx - внутренний параметр
	{ 969	,8	,1	, &internal1_m764_tx},	//(internal1_m764_tx) tx - внутренний параметр
	{ 970	,8	,1	, &internal1_m520_tx},	//(internal1_m520_tx) tx - внутренний параметр
	{ 971	,8	,1	, &internal1_m519_tx},	//(internal1_m519_tx) tx - внутренний параметр
	{ 972	,8	,1	, &internal1_m518_tx},	//(internal1_m518_tx) tx - внутренний параметр
	{ 973	,8	,1	, &internal1_m514_tx},	//(internal1_m514_tx) tx - внутренний параметр
	{ 974	,8	,1	, &internal1_m491_tx},	//(internal1_m491_tx) tx - внутренний параметр
	{ 975	,8	,1	, &internal1_m490_tx},	//(internal1_m490_tx) tx - внутренний параметр
	{ 976	,8	,1	, &internal1_m489_tx},	//(internal1_m489_tx) tx - внутренний параметр
	{ 977	,8	,1	, &internal1_m492_tx},	//(internal1_m492_tx) tx - внутренний параметр
	{ 978	,8	,1	, &internal1_m2436_tx},	//(internal1_m2436_tx) tx - внутренний параметр
	{ 979	,8	,1	, &internal1_m2145_tx},	//(internal1_m2145_tx) tx - внутренний параметр
	{ 980	,8	,1	, &internal1_m2435_tx},	//(internal1_m2435_tx) tx - внутренний параметр
	{ 981	,8	,1	, &internal1_m2434_tx},	//(internal1_m2434_tx) tx - внутренний параметр
	{ 982	,8	,1	, &internal1_m2433_tx},	//(internal1_m2433_tx) tx - внутренний параметр
	{ 983	,8	,1	, &internal1_m102_tx},	//(internal1_m102_tx) tx - внутренний параметр
	{ 984	,8	,1	, &internal1_m1137_tx},	//(internal1_m1137_tx) tx - внутренний параметр
	{ 985	,8	,1	, &internal1_m2291_tx},	//(internal1_m2291_tx) tx - внутренний параметр
	{ 986	,8	,1	, &internal1_m2290_tx},	//(internal1_m2290_tx) tx - внутренний параметр
	{ 987	,8	,1	, &internal1_m2289_tx},	//(internal1_m2289_tx) tx - внутренний параметр
	{ 988	,8	,1	, &internal1_m1228_tx},	//(internal1_m1228_tx) tx - внутренний параметр
	{ 989	,8	,1	, &internal1_m1227_tx},	//(internal1_m1227_tx) tx - внутренний параметр
	{ 990	,8	,1	, &internal1_m1222_tx},	//(internal1_m1222_tx) tx - внутренний параметр
	{ 991	,8	,1	, &internal1_m1215_tx},	//(internal1_m1215_tx) tx - внутренний параметр
	{ 992	,8	,1	, &internal1_m1213_tx},	//(internal1_m1213_tx) tx - внутренний параметр
	{ 993	,8	,1	, &internal1_m1211_tx},	//(internal1_m1211_tx) tx - внутренний параметр
	{ 994	,8	,1	, &internal1_m1209_tx},	//(internal1_m1209_tx) tx - внутренний параметр
	{ 995	,8	,1	, &internal1_m1252_tx},	//(internal1_m1252_tx) tx - внутренний параметр
	{ 996	,8	,1	, &internal1_m1259_tx},	//(internal1_m1259_tx) tx - внутренний параметр
	{ 997	,8	,1	, &internal1_m1264_tx},	//(internal1_m1264_tx) tx - внутренний параметр
	{ 998	,8	,1	, &internal1_m1270_tx},	//(internal1_m1270_tx) tx - внутренний параметр
	{ 999	,8	,1	, &internal1_m1230_tx},	//(internal1_m1230_tx) tx - внутренний параметр
	{ 1000	,8	,1	, &internal1_m1251_tx},	//(internal1_m1251_tx) tx - внутренний параметр
	{ 1001	,8	,1	, &internal1_m1265_tx},	//(internal1_m1265_tx) tx - внутренний параметр
	{ 1002	,8	,1	, &internal1_m469_tx},	//(internal1_m469_tx) tx - внутренний параметр
	{ 1003	,8	,1	, &internal1_m463_tx},	//(internal1_m463_tx) tx - внутренний параметр
	{ 1004	,8	,1	, &internal1_m465_tx},	//(internal1_m465_tx) tx - внутренний параметр
	{ 1005	,8	,1	, &internal1_m467_tx},	//(internal1_m467_tx) tx - внутренний параметр
	{ 1006	,8	,1	, &internal1_m474_tx},	//(internal1_m474_tx) tx - внутренний параметр
	{ 1007	,8	,1	, &internal1_m428_tx},	//(internal1_m428_tx) tx - внутренний параметр
	{ 1008	,8	,1	, &internal1_m426_tx},	//(internal1_m426_tx) tx - внутренний параметр
	{ 1009	,8	,1	, &internal1_m427_tx},	//(internal1_m427_tx) tx - внутренний параметр
	{ 1010	,8	,1	, &internal1_m420_tx},	//(internal1_m420_tx) tx - внутренний параметр
	{ 1011	,8	,1	, &internal1_m882_tx},	//(internal1_m882_tx) tx - внутренний параметр
	{ 1012	,8	,1	, &internal1_m881_tx},	//(internal1_m881_tx) tx - внутренний параметр
	{ 1013	,8	,1	, &internal1_m880_tx},	//(internal1_m880_tx) tx - внутренний параметр
	{ 1014	,8	,1	, &internal1_m876_tx},	//(internal1_m876_tx) tx - внутренний параметр
	{ 1015	,8	,1	, &internal1_m1316_tx},	//(internal1_m1316_tx) tx - внутренний параметр
	{ 1016	,8	,1	, &internal1_m1315_tx},	//(internal1_m1315_tx) tx - внутренний параметр
	{ 1017	,8	,1	, &internal1_m1314_tx},	//(internal1_m1314_tx) tx - внутренний параметр
	{ 1018	,8	,1	, &internal1_m1527_tx},	//(internal1_m1527_tx) tx - внутренний параметр
	{ 1019	,8	,1	, &internal1_m1540_tx},	//(internal1_m1540_tx) tx - внутренний параметр
	{ 1020	,8	,1	, &internal1_m1539_tx},	//(internal1_m1539_tx) tx - внутренний параметр
	{ 1021	,8	,1	, &internal1_m1538_tx},	//(internal1_m1538_tx) tx - внутренний параметр
	{ 1022	,8	,1	, &internal1_m1529_tx},	//(internal1_m1529_tx) tx - внутренний параметр
	{ 1023	,8	,1	, &internal1_m2263_tx},	//(internal1_m2263_tx) tx - внутренний параметр
	{ 1024	,8	,1	, &internal1_m2246_tx},	//(internal1_m2246_tx) tx - внутренний параметр
	{ 1025	,8	,1	, &internal1_m2223_tx},	//(internal1_m2223_tx) tx - внутренний параметр
	{ 1026	,8	,1	, &internal1_m1537_tx},	//(internal1_m1537_tx) tx - внутренний параметр
	{ 1027	,8	,1	, &internal1_m1518_tx},	//(internal1_m1518_tx) tx - внутренний параметр
	{ 1028	,8	,1	, &internal1_m1517_tx},	//(internal1_m1517_tx) tx - внутренний параметр
	{ 1029	,8	,1	, &internal1_m1514_tx},	//(internal1_m1514_tx) tx - внутренний параметр
	{ 1030	,8	,1	, &internal1_m1536_tx},	//(internal1_m1536_tx) tx - внутренний параметр
	{ 1031	,8	,1	, &internal1_m1502_tx},	//(internal1_m1502_tx) tx - внутренний параметр
	{ 1032	,8	,1	, &internal1_m1504_tx},	//(internal1_m1504_tx) tx - внутренний параметр
	{ 1033	,8	,1	, &internal1_m1501_tx},	//(internal1_m1501_tx) tx - внутренний параметр
	{ 1034	,8	,1	, &internal1_m1474_tx},	//(internal1_m1474_tx) tx - внутренний параметр
	{ 1035	,8	,1	, &internal1_m1473_tx},	//(internal1_m1473_tx) tx - внутренний параметр
	{ 1036	,8	,1	, &internal1_m1482_tx},	//(internal1_m1482_tx) tx - внутренний параметр
	{ 1037	,8	,1	, &internal1_m1486_tx},	//(internal1_m1486_tx) tx - внутренний параметр
	{ 1038	,8	,1	, &internal1_m975_tx},	//(internal1_m975_tx) tx - внутренний параметр
	{ 1039	,8	,1	, &internal1_m978_tx},	//(internal1_m978_tx) tx - внутренний параметр
	{ 1040	,8	,1	, &internal1_m2214_tx},	//(internal1_m2214_tx) tx - внутренний параметр
	{ 1041	,8	,1	, &internal1_m968_tx},	//(internal1_m968_tx) tx - внутренний параметр
	{ 1042	,8	,1	, &internal1_m966_tx},	//(internal1_m966_tx) tx - внутренний параметр
	{ 1043	,8	,1	, &internal1_m974_tx},	//(internal1_m974_tx) tx - внутренний параметр
	{ 1044	,8	,1	, &internal1_m958_tx},	//(internal1_m958_tx) tx - внутренний параметр
	{ 1045	,8	,1	, &internal1_m955_tx},	//(internal1_m955_tx) tx - внутренний параметр
	{ 1046	,8	,1	, &internal1_m952_tx},	//(internal1_m952_tx) tx - внутренний параметр
	{ 1047	,8	,1	, &internal1_m973_tx},	//(internal1_m973_tx) tx - внутренний параметр
	{ 1048	,8	,1	, &internal1_m938_tx},	//(internal1_m938_tx) tx - внутренний параметр
	{ 1049	,8	,1	, &internal1_m939_tx},	//(internal1_m939_tx) tx - внутренний параметр
	{ 1050	,8	,1	, &internal1_m941_tx},	//(internal1_m941_tx) tx - внутренний параметр
	{ 1051	,8	,1	, &internal1_m627_tx},	//(internal1_m627_tx) tx - внутренний параметр
	{ 1052	,8	,1	, &internal1_m629_tx},	//(internal1_m629_tx) tx - внутренний параметр
	{ 1053	,8	,1	, &internal1_m628_tx},	//(internal1_m628_tx) tx - внутренний параметр
	{ 1054	,8	,1	, &internal1_m615_tx},	//(internal1_m615_tx) tx - внутренний параметр
	{ 1055	,8	,1	, &internal1_m614_tx},	//(internal1_m614_tx) tx - внутренний параметр
	{ 1056	,8	,1	, &internal1_m611_tx},	//(internal1_m611_tx) tx - внутренний параметр
	{ 1057	,8	,1	, &internal1_m624_tx},	//(internal1_m624_tx) tx - внутренний параметр
	{ 1058	,8	,1	, &internal1_m601_tx},	//(internal1_m601_tx) tx - внутренний параметр
	{ 1059	,8	,1	, &internal1_m600_tx},	//(internal1_m600_tx) tx - внутренний параметр
	{ 1060	,8	,1	, &internal1_m596_tx},	//(internal1_m596_tx) tx - внутренний параметр
	{ 1061	,8	,1	, &internal1_m625_tx},	//(internal1_m625_tx) tx - внутренний параметр
	{ 1062	,8	,1	, &internal1_m587_tx},	//(internal1_m587_tx) tx - внутренний параметр
	{ 1063	,8	,1	, &internal1_m583_tx},	//(internal1_m583_tx) tx - внутренний параметр
	{ 1064	,8	,1	, &internal1_m585_tx},	//(internal1_m585_tx) tx - внутренний параметр
	{ 1065	,8	,1	, &internal1_m563_tx},	//(internal1_m563_tx) tx - внутренний параметр
	{ 1066	,8	,1	, &internal1_m564_tx},	//(internal1_m564_tx) tx - внутренний параметр
	{ 1067	,8	,1	, &internal1_m565_tx},	//(internal1_m565_tx) tx - внутренний параметр
	{ 1068	,8	,1	, &internal1_m570_tx},	//(internal1_m570_tx) tx - внутренний параметр
	{ 1069	,8	,1	, &internal1_m2274_tx},	//(internal1_m2274_tx) tx - внутренний параметр
	{ 1070	,8	,1	, &internal1_m2275_tx},	//(internal1_m2275_tx) tx - внутренний параметр
	{ 1071	,8	,1	, &internal1_m2276_tx},	//(internal1_m2276_tx) tx - внутренний параметр
	{ 1072	,8	,1	, &internal1_m1745_tx},	//(internal1_m1745_tx) tx - внутренний параметр
	{ 1073	,8	,1	, &internal1_m1744_tx},	//(internal1_m1744_tx) tx - внутренний параметр
	{ 1074	,8	,1	, &internal1_m1739_tx},	//(internal1_m1739_tx) tx - внутренний параметр
	{ 1075	,8	,1	, &internal1_m1730_tx},	//(internal1_m1730_tx) tx - внутренний параметр
	{ 1076	,8	,1	, &internal1_m1728_tx},	//(internal1_m1728_tx) tx - внутренний параметр
	{ 1077	,8	,1	, &internal1_m1726_tx},	//(internal1_m1726_tx) tx - внутренний параметр
	{ 1078	,8	,1	, &internal1_m1725_tx},	//(internal1_m1725_tx) tx - внутренний параметр
	{ 1079	,8	,1	, &internal1_m1766_tx},	//(internal1_m1766_tx) tx - внутренний параметр
	{ 1080	,8	,1	, &internal1_m1774_tx},	//(internal1_m1774_tx) tx - внутренний параметр
	{ 1081	,8	,1	, &internal1_m1781_tx},	//(internal1_m1781_tx) tx - внутренний параметр
	{ 1082	,8	,1	, &internal1_m1782_tx},	//(internal1_m1782_tx) tx - внутренний параметр
	{ 1083	,8	,1	, &internal1_m1772_tx},	//(internal1_m1772_tx) tx - внутренний параметр
	{ 1084	,8	,1	, &internal1_m1747_tx},	//(internal1_m1747_tx) tx - внутренний параметр
	{ 1085	,8	,1	, &internal1_m1761_tx},	//(internal1_m1761_tx) tx - внутренний параметр
	{ 1086	,8	,1	, &internal1_m446_tx},	//(internal1_m446_tx) tx - внутренний параметр
	{ 1087	,8	,1	, &internal1_m437_tx},	//(internal1_m437_tx) tx - внутренний параметр
	{ 1088	,8	,1	, &internal1_m438_tx},	//(internal1_m438_tx) tx - внутренний параметр
	{ 1089	,8	,1	, &internal1_m440_tx},	//(internal1_m440_tx) tx - внутренний параметр
	{ 1090	,8	,1	, &internal1_m454_tx},	//(internal1_m454_tx) tx - внутренний параметр
	{ 1091	,8	,1	, &internal1_m404_tx},	//(internal1_m404_tx) tx - внутренний параметр
	{ 1092	,8	,1	, &internal1_m401_tx},	//(internal1_m401_tx) tx - внутренний параметр
	{ 1093	,8	,1	, &internal1_m400_tx},	//(internal1_m400_tx) tx - внутренний параметр
	{ 1094	,8	,1	, &internal1_m399_tx},	//(internal1_m399_tx) tx - внутренний параметр
	{ 1095	,8	,1	, &internal1_m859_tx},	//(internal1_m859_tx) tx - внутренний параметр
	{ 1096	,8	,1	, &internal1_m855_tx},	//(internal1_m855_tx) tx - внутренний параметр
	{ 1097	,8	,1	, &internal1_m854_tx},	//(internal1_m854_tx) tx - внутренний параметр
	{ 1098	,8	,1	, &internal1_m853_tx},	//(internal1_m853_tx) tx - внутренний параметр
	{ 1099	,8	,1	, &internal1_m1297_tx},	//(internal1_m1297_tx) tx - внутренний параметр
	{ 1100	,8	,1	, &internal1_m1294_tx},	//(internal1_m1294_tx) tx - внутренний параметр
	{ 1101	,8	,1	, &internal1_m1293_tx},	//(internal1_m1293_tx) tx - внутренний параметр
	{ 1102	,8	,1	, &internal1_m1076_tx},	//(internal1_m1076_tx) tx - внутренний параметр
	{ 1103	,8	,1	, &internal1_m2229_tx},	//(internal1_m2229_tx) tx - внутренний параметр
	{ 1104	,8	,1	, &internal1_m1087_tx},	//(internal1_m1087_tx) tx - внутренний параметр
	{ 1105	,8	,1	, &internal1_m1089_tx},	//(internal1_m1089_tx) tx - внутренний параметр
	{ 1106	,8	,1	, &internal1_m1088_tx},	//(internal1_m1088_tx) tx - внутренний параметр
	{ 1107	,8	,1	, &internal1_m2231_tx},	//(internal1_m2231_tx) tx - внутренний параметр
	{ 1108	,8	,1	, &internal1_m1078_tx},	//(internal1_m1078_tx) tx - внутренний параметр
	{ 1109	,8	,1	, &internal1_m2228_tx},	//(internal1_m2228_tx) tx - внутренний параметр
	{ 1110	,8	,1	, &internal1_m1086_tx},	//(internal1_m1086_tx) tx - внутренний параметр
	{ 1111	,8	,1	, &internal1_m1065_tx},	//(internal1_m1065_tx) tx - внутренний параметр
	{ 1112	,8	,1	, &internal1_m1064_tx},	//(internal1_m1064_tx) tx - внутренний параметр
	{ 1113	,8	,1	, &internal1_m1063_tx},	//(internal1_m1063_tx) tx - внутренний параметр
	{ 1114	,8	,1	, &internal1_m1085_tx},	//(internal1_m1085_tx) tx - внутренний параметр
	{ 1115	,8	,1	, &internal1_m1053_tx},	//(internal1_m1053_tx) tx - внутренний параметр
	{ 1116	,8	,1	, &internal1_m1051_tx},	//(internal1_m1051_tx) tx - внутренний параметр
	{ 1117	,8	,1	, &internal1_m1050_tx},	//(internal1_m1050_tx) tx - внутренний параметр
	{ 1118	,8	,1	, &internal1_m1029_tx},	//(internal1_m1029_tx) tx - внутренний параметр
	{ 1119	,8	,1	, &internal1_m1028_tx},	//(internal1_m1028_tx) tx - внутренний параметр
	{ 1120	,8	,1	, &internal1_m1018_tx},	//(internal1_m1018_tx) tx - внутренний параметр
	{ 1121	,8	,1	, &internal1_m1035_tx},	//(internal1_m1035_tx) tx - внутренний параметр
	{ 1122	,8	,1	, &internal1_m1432_tx},	//(internal1_m1432_tx) tx - внутренний параметр
	{ 1123	,8	,1	, &internal1_m1431_tx},	//(internal1_m1431_tx) tx - внутренний параметр
	{ 1124	,8	,1	, &internal1_m2181_tx},	//(internal1_m2181_tx) tx - внутренний параметр
	{ 1125	,8	,1	, &internal1_m1423_tx},	//(internal1_m1423_tx) tx - внутренний параметр
	{ 1126	,8	,1	, &internal1_m1424_tx},	//(internal1_m1424_tx) tx - внутренний параметр
	{ 1127	,8	,1	, &internal1_m1430_tx},	//(internal1_m1430_tx) tx - внутренний параметр
	{ 1128	,8	,1	, &internal1_m1412_tx},	//(internal1_m1412_tx) tx - внутренний параметр
	{ 1129	,8	,1	, &internal1_m1411_tx},	//(internal1_m1411_tx) tx - внутренний параметр
	{ 1130	,8	,1	, &internal1_m1408_tx},	//(internal1_m1408_tx) tx - внутренний параметр
	{ 1131	,8	,1	, &internal1_m1429_tx},	//(internal1_m1429_tx) tx - внутренний параметр
	{ 1132	,8	,1	, &internal1_m1394_tx},	//(internal1_m1394_tx) tx - внутренний параметр
	{ 1133	,8	,1	, &internal1_m1393_tx},	//(internal1_m1393_tx) tx - внутренний параметр
	{ 1134	,8	,1	, &internal1_m1396_tx},	//(internal1_m1396_tx) tx - внутренний параметр
	{ 1135	,8	,1	, &internal1_m244_tx},	//(internal1_m244_tx) tx - внутренний параметр
	{ 1136	,8	,1	, &internal1_m259_tx},	//(internal1_m259_tx) tx - внутренний параметр
	{ 1137	,8	,1	, &internal1_m266_tx},	//(internal1_m266_tx) tx - внутренний параметр
	{ 1138	,8	,1	, &internal1_m265_tx},	//(internal1_m265_tx) tx - внутренний параметр
	{ 1139	,8	,1	, &internal1_m252_tx},	//(internal1_m252_tx) tx - внутренний параметр
	{ 1140	,8	,1	, &internal1_m247_tx},	//(internal1_m247_tx) tx - внутренний параметр
	{ 1141	,8	,1	, &internal1_m263_tx},	//(internal1_m263_tx) tx - внутренний параметр
	{ 1142	,8	,1	, &internal1_m235_tx},	//(internal1_m235_tx) tx - внутренний параметр
	{ 1143	,8	,1	, &internal1_m234_tx},	//(internal1_m234_tx) tx - внутренний параметр
	{ 1144	,8	,1	, &internal1_m230_tx},	//(internal1_m230_tx) tx - внутренний параметр
	{ 1145	,8	,1	, &internal1_m262_tx},	//(internal1_m262_tx) tx - внутренний параметр
	{ 1146	,8	,1	, &internal1_m219_tx},	//(internal1_m219_tx) tx - внутренний параметр
	{ 1147	,8	,1	, &internal1_m221_tx},	//(internal1_m221_tx) tx - внутренний параметр
	{ 1148	,8	,1	, &internal1_m218_tx},	//(internal1_m218_tx) tx - внутренний параметр
	{ 1149	,8	,1	, &internal1_m197_tx},	//(internal1_m197_tx) tx - внутренний параметр
	{ 1150	,8	,1	, &internal1_m196_tx},	//(internal1_m196_tx) tx - внутренний параметр
	{ 1151	,8	,1	, &internal1_m195_tx},	//(internal1_m195_tx) tx - внутренний параметр
	{ 1152	,8	,1	, &internal1_m203_tx},	//(internal1_m203_tx) tx - внутренний параметр
	{ 1153	,8	,1	, &internal1_m1375_tx},	//(internal1_m1375_tx) tx - внутренний параметр
	{ 1154	,8	,1	, &internal1_m1357_tx},	//(internal1_m1357_tx) tx - внутренний параметр
	{ 1155	,8	,1	, &internal1_m1362_tx},	//(internal1_m1362_tx) tx - внутренний параметр
	{ 1156	,8	,1	, &internal1_m1378_tx},	//(internal1_m1378_tx) tx - внутренний параметр
	{ 1157	,8	,1	, &internal1_m918_tx},	//(internal1_m918_tx) tx - внутренний параметр
	{ 1158	,8	,1	, &internal1_m923_tx},	//(internal1_m923_tx) tx - внутренний параметр
	{ 1159	,8	,1	, &internal1_m913_tx},	//(internal1_m913_tx) tx - внутренний параметр
	{ 1160	,8	,1	, &internal1_m914_tx},	//(internal1_m914_tx) tx - внутренний параметр
	{ 1161	,1	,1	, &internal1_m1866_q0},	//(internal1_m1866_q0) q0 - внутренний параметр
	{ 1162	,1	,1	, &internal1_m2316_q0},	//(internal1_m2316_q0) q0 - внутренний параметр
	{ 1163	,1	,1	, &internal1_m2300_q0},	//(internal1_m2300_q0) q0 - внутренний параметр
	{ 1164	,1	,1	, &internal1_m2347_q0},	//(internal1_m2347_q0) q0 - внутренний параметр
	{ 1165	,1	,1	, &internal1_m2331_q0},	//(internal1_m2331_q0) q0 - внутренний параметр
	{ 1166	,1	,1	, &internal1_m2322_q0},	//(internal1_m2322_q0) q0 - внутренний параметр
	{ 1167	,1	,1	, &internal1_m2303_q0},	//(internal1_m2303_q0) q0 - внутренний параметр
	{ 1168	,1	,1	, &internal1_m2320_q0},	//(internal1_m2320_q0) q0 - внутренний параметр
	{ 1169	,1	,1	, &internal1_m2301_q0},	//(internal1_m2301_q0) q0 - внутренний параметр
	{ 1170	,1	,1	, &internal1_m2299_q0},	//(internal1_m2299_q0) q0 - внутренний параметр
	{ 1171	,1	,1	, &internal1_m2298_q0},	//(internal1_m2298_q0) q0 - внутренний параметр
	{ 1172	,1	,1	, &internal1_m2312_q0},	//(internal1_m2312_q0) q0 - внутренний параметр
	{ 1173	,1	,1	, &internal1_m2310_q0},	//(internal1_m2310_q0) q0 - внутренний параметр
	{ 1174	,1	,1	, &internal1_m2318_q0},	//(internal1_m2318_q0) q0 - внутренний параметр
	{ 1175	,1	,1	, &internal1_m2314_q0},	//(internal1_m2314_q0) q0 - внутренний параметр
	{ 1176	,1	,1	, &internal1_m2353_q0},	//(internal1_m2353_q0) q0 - внутренний параметр
	{ 1177	,1	,1	, &internal1_m2334_q0},	//(internal1_m2334_q0) q0 - внутренний параметр
	{ 1178	,1	,1	, &internal1_m2351_q0},	//(internal1_m2351_q0) q0 - внутренний параметр
	{ 1179	,1	,1	, &internal1_m2333_q0},	//(internal1_m2333_q0) q0 - внутренний параметр
	{ 1180	,1	,1	, &internal1_m2330_q0},	//(internal1_m2330_q0) q0 - внутренний параметр
	{ 1181	,1	,1	, &internal1_m2329_q0},	//(internal1_m2329_q0) q0 - внутренний параметр
	{ 1182	,1	,1	, &internal1_m2343_q0},	//(internal1_m2343_q0) q0 - внутренний параметр
	{ 1183	,1	,1	, &internal1_m2341_q0},	//(internal1_m2341_q0) q0 - внутренний параметр
	{ 1184	,8	,1	, &internal1_m2206_tx},	//(internal1_m2206_tx) tx - внутренний параметр
	{ 1185	,8	,1	, &internal1_m2185_tx},	//(internal1_m2185_tx) tx - внутренний параметр
	{ 1186	,1	,1	, &internal1_m1889_Pv0},	//(internal1_m1889_Pv0)  - Пер. выключатель механизма
	{ 1187	,1	,1	, &internal1_m1889_Zv0},	//(internal1_m1889_Zv0)  - Зад. выключатель механизма
	{ 1188	,1	,1	, &internal1_m1889_MyFirstEnterFlag},	//(internal1_m1889_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1189	,1	,1	, &internal1_m1887_Pv0},	//(internal1_m1887_Pv0)  - Пер. выключатель механизма
	{ 1190	,1	,1	, &internal1_m1887_Zv0},	//(internal1_m1887_Zv0)  - Зад. выключатель механизма
	{ 1191	,1	,1	, &internal1_m1887_MyFirstEnterFlag},	//(internal1_m1887_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1192	,8	,1	, &internal1_m2371_tx},	//(internal1_m2371_tx) tx - время накопленное сек
	{ 1193	,18	,1	, &internal1_m2371_y0},	//(internal1_m2371_y0) y0
	{ 1194	,8	,1	, &internal1_m2375_tx},	//(internal1_m2375_tx) tx - время накопленное сек
	{ 1195	,18	,1	, &internal1_m2375_y0},	//(internal1_m2375_y0) y0
	{ 1196	,8	,1	, &internal1_m2374_tx},	//(internal1_m2374_tx) tx - время накопленное сек
	{ 1197	,18	,1	, &internal1_m2374_y0},	//(internal1_m2374_y0) y0
	{ 1198	,8	,1	, &internal1_m2411_tx},	//(internal1_m2411_tx) tx - внутренний параметр
	{ 1199	,8	,1	, &internal1_m2409_tx},	//(internal1_m2409_tx) tx - время накопленное сек
	{ 1200	,18	,1	, &internal1_m2409_y0},	//(internal1_m2409_y0) y0
	{ 1201	,1	,1	, &internal1_m2414_q0},	//(internal1_m2414_q0) q0 - внутренний параметр
	{ 1202	,1	,1	, &internal1_m2381_q0},	//(internal1_m2381_q0) q0 - внутренний параметр
	{ 1203	,8	,1	, &internal1_m2389_tx},	//(internal1_m2389_tx) tx - внутренний параметр
	{ 1204	,1	,1	, &internal1_m2387_q0},	//(internal1_m2387_q0) q0 - внутренний параметр
	{ 1205	,8	,1	, &internal1_m2200_tx},	//(internal1_m2200_tx) tx - время накопленное сек
	{ 1206	,18	,1	, &internal1_m2200_y0},	//(internal1_m2200_y0) y0
	{ 1207	,8	,1	, &internal1_m2192_tx},	//(internal1_m2192_tx) tx - время накопленное сек
	{ 1208	,18	,1	, &internal1_m2192_y0},	//(internal1_m2192_y0) y0
	{ 1209	,1	,1	, &internal1_m1876_q0},	//(internal1_m1876_q0) q0 - внутренний параметр
	{ 1210	,1	,1	, &internal1_m1881_q0},	//(internal1_m1881_q0) q0 - внутренний параметр
	{ 1211	,1	,1	, &internal1_m1873_q0},	//(internal1_m1873_q0) q0 - внутренний параметр
	{ 1212	,1	,1	, &internal1_m1915_q0},	//(internal1_m1915_q0) q0 - внутренний параметр
	{ 1213	,8	,1	, &internal1_m823_tx},	//(internal1_m823_tx) tx - время накопленное сек
	{ 1214	,18	,1	, &internal1_m823_y0},	//(internal1_m823_y0) y0
	{ 1215	,8	,1	, &internal1_m2196_tx},	//(internal1_m2196_tx) tx - внутренний параметр
	{ 1216	,1	,1	, &internal1_m2199_q0},	//(internal1_m2199_q0) q0 - внутренний параметр
	{ 1217	,1	,1	, &internal1_m2191_q0},	//(internal1_m2191_q0) q0 - внутренний параметр
	{ 1218	,8	,1	, &internal1_m2160_tx},	//(internal1_m2160_tx) tx - внутренний параметр
	{ 1219	,8	,1	, &internal1_m2171_tx},	//(internal1_m2171_tx) tx - внутренний параметр
	{ 1220	,8	,1	, &internal1_m2157_tx},	//(internal1_m2157_tx) tx - внутренний параметр
	{ 1221	,1	,1	, &internal1_m2163_q0},	//(internal1_m2163_q0) q0 - внутренний параметр
	{ 1222	,1	,1	, &internal1_m2175_q0},	//(internal1_m2175_q0) q0 - внутренний параметр
	{ 1223	,8	,1	, &internal1_m2132_tx},	//(internal1_m2132_tx) tx - внутренний параметр
	{ 1224	,8	,1	, &internal1_m51_tx},	//(internal1_m51_tx) tx - внутренний параметр
	{ 1225	,8	,1	, &internal1_m357_tx},	//(internal1_m357_tx) tx - внутренний параметр
	{ 1226	,8	,1	, &internal1_m312_tx},	//(internal1_m312_tx) tx - внутренний параметр
	{ 1227	,8	,1	, &internal1_m824_tx},	//(internal1_m824_tx) tx - внутренний параметр
	{ 1228	,8	,1	, &internal1_m1584_tx},	//(internal1_m1584_tx) tx - внутренний параметр
	{ 1229	,8	,1	, &internal1_m114_tx},	//(internal1_m114_tx) tx - внутренний параметр
	{ 1230	,8	,1	, &internal1_m116_tx},	//(internal1_m116_tx) tx - внутренний параметр
	{ 1231	,8	,1	, &internal1_m121_tx},	//(internal1_m121_tx) tx - внутренний параметр
	{ 1232	,8	,1	, &internal1_m21_tx},	//(internal1_m21_tx) tx - внутренний параметр
	{ 1233	,8	,1	, &internal1_m13_tx},	//(internal1_m13_tx) tx - внутренний параметр
	{ 1234	,8	,1	, &internal1_m2142_tx},	//(internal1_m2142_tx) tx - внутренний параметр
	{ 1235	,8	,1	, &internal1_m2129_tx},	//(internal1_m2129_tx) tx - внутренний параметр
	{ 1236	,8	,1	, &internal1_m2247_tx},	//(internal1_m2247_tx) tx - внутренний параметр
	{ 1237	,8	,1	, &internal1_m2249_tx},	//(internal1_m2249_tx) tx - внутренний параметр
	{ 1238	,8	,1	, &internal1_m2054_tx},	//(internal1_m2054_tx) tx - внутренний параметр
	{ 1239	,8	,1	, &internal1_m77_tx},	//(internal1_m77_tx) tx - внутренний параметр
	{ 1240	,8	,1	, &internal1_m328_tx},	//(internal1_m328_tx) tx - время накопленное сек
	{ 1241	,18	,1	, &internal1_m328_y0},	//(internal1_m328_y0) y0
	{ 1242	,8	,1	, &internal1_m2048_tx},	//(internal1_m2048_tx) tx - время накопленное сек
	{ 1243	,18	,1	, &internal1_m2048_y0},	//(internal1_m2048_y0) y0
	{ 1244	,8	,1	, &internal1_m2046_tx},	//(internal1_m2046_tx) tx - время накопленное сек
	{ 1245	,18	,1	, &internal1_m2046_y0},	//(internal1_m2046_y0) y0
	{ 1246	,8	,1	, &internal1_m2035_tx},	//(internal1_m2035_tx) tx - время накопленное сек
	{ 1247	,18	,1	, &internal1_m2035_y0},	//(internal1_m2035_y0) y0
	{ 1248	,8	,1	, &internal1_m2055_q0},	//(internal1_m2055_q0) q0 - внутренний параметр
	{ 1249	,8	,1	, &internal1_m1604_q0},	//(internal1_m1604_q0) q0 - внутренний параметр
	{ 1250	,8	,1	, &internal1_m1642_q0},	//(internal1_m1642_q0) q0 - внутренний параметр
	{ 1251	,8	,1	, &internal1_m1645_q0},	//(internal1_m1645_q0) q0 - внутренний параметр
	{ 1252	,8	,1	, &internal1_m2094_q0},	//(internal1_m2094_q0) q0 - внутренний параметр
	{ 1253	,8	,1	, &internal1_m2074_tx},	//(internal1_m2074_tx) tx - время накопленное сек
	{ 1254	,18	,1	, &internal1_m2074_y0},	//(internal1_m2074_y0) y0
	{ 1255	,8	,1	, &internal1_m2087_tx},	//(internal1_m2087_tx) tx - время накопленное сек
	{ 1256	,18	,1	, &internal1_m2087_y0},	//(internal1_m2087_y0) y0
	{ 1257	,8	,1	, &internal1_m2084_tx},	//(internal1_m2084_tx) tx - время накопленное сек
	{ 1258	,18	,1	, &internal1_m2084_y0},	//(internal1_m2084_y0) y0
	{ 1259	,8	,1	, &internal1_m2227_tx},	//(internal1_m2227_tx) tx - время накопленное сек
	{ 1260	,18	,1	, &internal1_m2227_y0},	//(internal1_m2227_y0) y0
	{ 1261	,8	,1	, &internal1_m2238_tx},	//(internal1_m2238_tx) tx - время накопленное сек
	{ 1262	,18	,1	, &internal1_m2238_y0},	//(internal1_m2238_y0) y0
	{ 1263	,8	,1	, &internal1_m1983_tx},	//(internal1_m1983_tx) tx - время накопленное сек
	{ 1264	,18	,1	, &internal1_m1983_y0},	//(internal1_m1983_y0) y0
	{ 1265	,8	,1	, &internal1_m1982_tx},	//(internal1_m1982_tx) tx - время накопленное сек
	{ 1266	,18	,1	, &internal1_m1982_y0},	//(internal1_m1982_y0) y0
	{ 1267	,8	,1	, &internal1_m1981_tx},	//(internal1_m1981_tx) tx - время накопленное сек
	{ 1268	,18	,1	, &internal1_m1981_y0},	//(internal1_m1981_y0) y0
	{ 1269	,8	,1	, &internal1_m1980_tx},	//(internal1_m1980_tx) tx - время накопленное сек
	{ 1270	,18	,1	, &internal1_m1980_y0},	//(internal1_m1980_y0) y0
	{ 1271	,8	,1	, &internal1_m1656_tx},	//(internal1_m1656_tx) tx - время накопленное сек
	{ 1272	,18	,1	, &internal1_m1656_y0},	//(internal1_m1656_y0) y0
	{ 1273	,8	,1	, &internal1_m1650_tx},	//(internal1_m1650_tx) tx - время накопленное сек
	{ 1274	,18	,1	, &internal1_m1650_y0},	//(internal1_m1650_y0) y0
	{ 1275	,8	,1	, &internal1_m1600_tx},	//(internal1_m1600_tx) tx - время накопленное сек
	{ 1276	,18	,1	, &internal1_m1600_y0},	//(internal1_m1600_y0) y0
	{ 1277	,8	,1	, &internal1_m911_tx},	//(internal1_m911_tx) tx - время накопленное сек
	{ 1278	,18	,1	, &internal1_m911_y0},	//(internal1_m911_y0) y0
	{ 1279	,8	,1	, &internal1_m910_tx},	//(internal1_m910_tx) tx - время накопленное сек
	{ 1280	,18	,1	, &internal1_m910_y0},	//(internal1_m910_y0) y0
	{ 1281	,8	,1	, &internal1_m928_tx},	//(internal1_m928_tx) tx - время накопленное сек
	{ 1282	,18	,1	, &internal1_m928_y0},	//(internal1_m928_y0) y0
	{ 1283	,8	,1	, &internal1_m187_tx},	//(internal1_m187_tx) tx - время накопленное сек
	{ 1284	,18	,1	, &internal1_m187_y0},	//(internal1_m187_y0) y0
	{ 1285	,8	,1	, &internal1_m186_tx},	//(internal1_m186_tx) tx - время накопленное сек
	{ 1286	,18	,1	, &internal1_m186_y0},	//(internal1_m186_y0) y0
	{ 1287	,8	,1	, &internal1_m208_tx},	//(internal1_m208_tx) tx - время накопленное сек
	{ 1288	,18	,1	, &internal1_m208_y0},	//(internal1_m208_y0) y0
	{ 1289	,8	,1	, &internal1_m577_tx},	//(internal1_m577_tx) tx - время накопленное сек
	{ 1290	,18	,1	, &internal1_m577_y0},	//(internal1_m577_y0) y0
	{ 1291	,8	,1	, &internal1_m2281_tx},	//(internal1_m2281_tx) tx - внутренний параметр
	{ 1292	,8	,1	, &internal1_m1307_tx},	//(internal1_m1307_tx) tx - внутренний параметр
	{ 1293	,8	,1	, &internal1_m1785_tx},	//(internal1_m1785_tx) tx - время накопленное сек
	{ 1294	,18	,1	, &internal1_m1785_y0},	//(internal1_m1785_y0) y0
	{ 1295	,8	,1	, &internal1_m1272_tx},	//(internal1_m1272_tx) tx - время накопленное сек
	{ 1296	,18	,1	, &internal1_m1272_y0},	//(internal1_m1272_y0) y0
	{ 1297	,8	,1	, &internal1_m1492_tx},	//(internal1_m1492_tx) tx - время накопленное сек
	{ 1298	,18	,1	, &internal1_m1492_y0},	//(internal1_m1492_y0) y0
	{ 1299	,8	,1	, &internal1_m1041_tx},	//(internal1_m1041_tx) tx - время накопленное сек
	{ 1300	,18	,1	, &internal1_m1041_y0},	//(internal1_m1041_y0) y0
	{ 1301	,8	,1	, &internal1_m1382_tx},	//(internal1_m1382_tx) tx - время накопленное сек
	{ 1302	,18	,1	, &internal1_m1382_y0},	//(internal1_m1382_y0) y0
	{ 1303	,1	,1	, &internal1_m1198_q0},	//(internal1_m1198_q0) q0 - внутренний параметр
	{ 1304	,1	,1	, &internal1_m1196_q0},	//(internal1_m1196_q0) q0 - внутренний параметр
	{ 1305	,1	,1	, &internal1_m1195_q0},	//(internal1_m1195_q0) q0 - внутренний параметр
	{ 1306	,1	,1	, &internal1_m1193_q0},	//(internal1_m1193_q0) q0 - внутренний параметр
	{ 1307	,1	,1	, &internal1_m1192_q0},	//(internal1_m1192_q0) q0 - внутренний параметр
	{ 1308	,1	,1	, &internal1_m1190_q0},	//(internal1_m1190_q0) q0 - внутренний параметр
	{ 1309	,1	,1	, &internal1_m1189_q0},	//(internal1_m1189_q0) q0 - внутренний параметр
	{ 1310	,1	,1	, &internal1_m1187_q0},	//(internal1_m1187_q0) q0 - внутренний параметр
	{ 1311	,1	,1	, &internal1_m1186_q0},	//(internal1_m1186_q0) q0 - внутренний параметр
	{ 1312	,1	,1	, &internal1_m52_x0},	//(internal1_m52_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1313	,1	,1	, &internal1_m1105_q0},	//(internal1_m1105_q0) q0 - внутренний параметр
	{ 1314	,1	,1	, &internal1_m1593_x0},	//(internal1_m1593_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1315	,1	,1	, &internal1_m1637_x0},	//(internal1_m1637_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1316	,1	,1	, &internal1_m1633_x0},	//(internal1_m1633_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1317	,1	,1	, &internal1_m2063_x0},	//(internal1_m2063_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1318	,1	,1	, &internal1_m2028_x0},	//(internal1_m2028_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1319	,1	,1	, &internal1_m1145_q0},	//(internal1_m1145_q0) q0 - внутренний параметр
	{ 1320	,1	,1	, &internal1_m1157_q0},	//(internal1_m1157_q0) q0 - внутренний параметр
	{ 1321	,1	,1	, &internal1_m1169_q0},	//(internal1_m1169_q0) q0 - внутренний параметр
	{ 1322	,1	,1	, &internal1_m1178_q0},	//(internal1_m1178_q0) q0 - внутренний параметр
	{ 1323	,1	,1	, &internal1_m1156_q0},	//(internal1_m1156_q0) q0 - внутренний параметр
	{ 1324	,1	,1	, &internal1_m1171_q0},	//(internal1_m1171_q0) q0 - внутренний параметр
	{ 1325	,1	,1	, &internal1_m2121_q0},	//(internal1_m2121_q0) q0 - внутренний параметр
	{ 1326	,1	,1	, &internal1_m2120_q0},	//(internal1_m2120_q0) q0 - внутренний параметр
	{ 1327	,3	,1	, &internal1_m345_Step},	//(internal1_m345_Step)  - текущий шаг программы
	{ 1328	,18	,10	, &internal1_m345_rz},	//(internal1_m345_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1329	,8	,1	, &internal1_m345_TimS},	//(internal1_m345_TimS) Время от старта программы
	{ 1330	,1	,1	, &internal1_m345_FinPr0},	//(internal1_m345_FinPr0) FinPr - конец программы
	{ 1331	,1	,1	, &internal1_m345_ErrPr0},	//(internal1_m345_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1332	,1	,1	, &internal1_m345_sbINI0},	//(internal1_m345_sbINI0) sbINI - запуск проверки ИНИ
	{ 1333	,1	,1	, &internal1_m345_sbVuIS0},	//(internal1_m345_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1334	,1	,1	, &internal1_m345_sb2UR0},	//(internal1_m345_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1335	,1	,1	, &internal1_m345_sbNupIS0},	//(internal1_m345_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1336	,1	,1	, &internal1_m345_sbVuRB0},	//(internal1_m345_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1337	,1	,1	, &internal1_m345_MyFirstEnterFlag},	//(internal1_m345_MyFirstEnterFlag)  
	{ 1338	,5	,1	, &internal1_m353_x0},	//(internal1_m353_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1339	,5	,1	, &internal1_m311_TimS},	//(internal1_m311_TimS) Время старта
	{ 1340	,3	,1	, &internal1_m287_Step},	//(internal1_m287_Step)  - текущий шаг программы
	{ 1341	,18	,10	, &internal1_m287_rz},	//(internal1_m287_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1342	,8	,1	, &internal1_m287_TimS},	//(internal1_m287_TimS) Время от старта программы
	{ 1343	,1	,1	, &internal1_m287_FinPr0},	//(internal1_m287_FinPr0) FinPr - конец программы
	{ 1344	,1	,1	, &internal1_m287_ErrPr0},	//(internal1_m287_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1345	,1	,1	, &internal1_m287_sbINI0},	//(internal1_m287_sbINI0) sbINI - запуск проверки ИНИ
	{ 1346	,1	,1	, &internal1_m287_sbVuIS0},	//(internal1_m287_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1347	,1	,1	, &internal1_m287_sb2UR0},	//(internal1_m287_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1348	,1	,1	, &internal1_m287_sbNupIS0},	//(internal1_m287_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1349	,1	,1	, &internal1_m287_sbVuRB0},	//(internal1_m287_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1350	,1	,1	, &internal1_m287_MyFirstEnterFlag},	//(internal1_m287_MyFirstEnterFlag)  
	{ 1351	,1	,1	, &internal1_m1567_q0},	//(internal1_m1567_q0) q0 - внутренний параметр
	{ 1352	,3	,1	, &internal1_m1568_Step},	//(internal1_m1568_Step)  - текущий шаг программы
	{ 1353	,18	,6	, &internal1_m1568_rz},	//(internal1_m1568_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1354	,8	,1	, &internal1_m1568_TimS},	//(internal1_m1568_TimS) Время от старта программы
	{ 1355	,1	,1	, &internal1_m1568_FinPr0},	//(internal1_m1568_FinPr0) FinPr - конец программы
	{ 1356	,1	,1	, &internal1_m1568_ErrPr0},	//(internal1_m1568_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1357	,1	,1	, &internal1_m1568_sbINI0},	//(internal1_m1568_sbINI0) sbINI - запуск проверки ИНИ
	{ 1358	,1	,1	, &internal1_m1568_sbVuIS0},	//(internal1_m1568_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1359	,1	,1	, &internal1_m1568_sb2UR0},	//(internal1_m1568_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1360	,1	,1	, &internal1_m1568_sbNupIS0},	//(internal1_m1568_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1361	,1	,1	, &internal1_m1568_sbVuRB0},	//(internal1_m1568_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1362	,1	,1	, &internal1_m1568_MyFirstEnterFlag},	//(internal1_m1568_MyFirstEnterFlag)  
	{ 1363	,1	,1	, &internal1_m1141_q0},	//(internal1_m1141_q0) q0 - внутренний параметр
	{ 1364	,1	,1	, &internal1_m1138_q0},	//(internal1_m1138_q0) q0 - внутренний параметр
	{ 1365	,1	,1	, &internal1_m1140_q0},	//(internal1_m1140_q0) q0 - внутренний параметр
	{ 1366	,1	,1	, &internal1_m1134_q0},	//(internal1_m1134_q0) q0 - внутренний параметр
	{ 1367	,1	,1	, &internal1_m825_q0},	//(internal1_m825_q0) q0 - внутренний параметр
	{ 1368	,1	,1	, &internal1_m355_q0},	//(internal1_m355_q0) q0 - внутренний параметр
	{ 1369	,1	,1	, &internal1_m351_q0},	//(internal1_m351_q0) q0 - внутренний параметр
	{ 1370	,1	,1	, &internal1_m307_q0},	//(internal1_m307_q0) q0 - внутренний параметр
	{ 1371	,5	,1	, &internal1_m306_x0},	//(internal1_m306_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1372	,1	,1	, &internal1_m2050_q0},	//(internal1_m2050_q0) q0 - внутренний параметр
	{ 1373	,1	,1	, &internal1_m2038_q0},	//(internal1_m2038_q0) q0 - внутренний параметр
	{ 1374	,1	,1	, &internal1_m2029_q0},	//(internal1_m2029_q0) q0 - внутренний параметр
	{ 1375	,1	,1	, &internal1_m2104_q0},	//(internal1_m2104_q0) q0 - внутренний параметр
	{ 1376	,1	,1	, &internal1_m2071_q0},	//(internal1_m2071_q0) q0 - внутренний параметр
	{ 1377	,1	,1	, &internal1_m2064_q0},	//(internal1_m2064_q0) q0 - внутренний параметр
	{ 1378	,1	,1	, &internal1_m1620_q0},	//(internal1_m1620_q0) q0 - внутренний параметр
	{ 1379	,1	,1	, &internal1_m1607_x0},	//(internal1_m1607_x0) был приход сигнала x1
	{ 1380	,8	,1	, &internal1_m1607_y0},	//(internal1_m1607_y0) интервал между сигналами х1 и х2
	{ 1381	,1	,1	, &internal1_m1603_q0},	//(internal1_m1603_q0) q0 - внутренний параметр
	{ 1382	,1	,1	, &internal1_m1594_q0},	//(internal1_m1594_q0) q0 - внутренний параметр
	{ 1383	,1	,1	, &internal1_m1653_q0},	//(internal1_m1653_q0) q0 - внутренний параметр
	{ 1384	,1	,1	, &internal1_m1673_q0},	//(internal1_m1673_q0) q0 - внутренний параметр
	{ 1385	,1	,1	, &internal1_m1639_q0},	//(internal1_m1639_q0) q0 - внутренний параметр
	{ 1386	,1	,1	, &internal1_m1654_x0},	//(internal1_m1654_x0) был приход сигнала x1
	{ 1387	,8	,1	, &internal1_m1654_y0},	//(internal1_m1654_y0) интервал между сигналами х1 и х2
	{ 1388	,5	,1	, &internal1_m1578_x0},	//(internal1_m1578_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1389	,1	,1	, &internal1_m1659_q0},	//(internal1_m1659_q0) q0 - внутренний параметр
	{ 1390	,1	,1	, &internal1_m26_q0},	//(internal1_m26_q0) q0 - внутренний параметр
	{ 1391	,1	,1	, &internal1_m1674_q0},	//(internal1_m1674_q0) q0 - внутренний параметр
	{ 1392	,1	,1	, &internal1_m700_q0},	//(internal1_m700_q0) q0 - внутренний параметр
	{ 1393	,1	,1	, &internal1_m685_q0},	//(internal1_m685_q0) q0 - внутренний параметр
	{ 1394	,1	,1	, &internal1_m712_q0},	//(internal1_m712_q0) q0 - внутренний параметр
	{ 1395	,1	,1	, &internal1_m696_q0},	//(internal1_m696_q0) q0 - внутренний параметр
	{ 1396	,1	,1	, &internal1_m680_q0},	//(internal1_m680_q0) q0 - внутренний параметр
	{ 1397	,1	,1	, &internal1_m678_q0},	//(internal1_m678_q0) q0 - внутренний параметр
	{ 1398	,1	,1	, &internal1_m666_q0},	//(internal1_m666_q0) q0 - внутренний параметр
	{ 1399	,5	,1	, &internal1_m1570_q0},	//(internal1_m1570_q0) q0 - внутренний параметр
	{ 1400	,1	,1	, &internal1_m676_q0},	//(internal1_m676_q0) q0 - внутренний параметр
	{ 1401	,1	,1	, &internal1_m110_q0},	//(internal1_m110_q0) q0 - внутренний параметр
	{ 1402	,1	,1	, &internal1_m1820_q0},	//(internal1_m1820_q0) q0 - внутренний параметр
	{ 1403	,1	,1	, &internal1_m1819_q0},	//(internal1_m1819_q0) q0 - внутренний параметр
	{ 1404	,1	,1	, &internal1_m1818_q0},	//(internal1_m1818_q0) q0 - внутренний параметр
	{ 1405	,1	,1	, &internal1_m1817_q0},	//(internal1_m1817_q0) q0 - внутренний параметр
	{ 1406	,1	,1	, &internal1_m1853_q0},	//(internal1_m1853_q0) q0 - внутренний параметр
	{ 1407	,1	,1	, &internal1_m1852_q0},	//(internal1_m1852_q0) q0 - внутренний параметр
	{ 1408	,1	,1	, &internal1_m1851_q0},	//(internal1_m1851_q0) q0 - внутренний параметр
	{ 1409	,1	,1	, &internal1_m2135_q0},	//(internal1_m2135_q0) q0 - внутренний параметр
	{ 1410	,1	,1	, &internal1_m1913_q0},	//(internal1_m1913_q0) q0 - внутренний параметр
	{ 1411	,1	,1	, &internal1_m1905_q0},	//(internal1_m1905_q0) q0 - внутренний параметр
	{ 1412	,1	,1	, &internal1_m1910_q0},	//(internal1_m1910_q0) q0 - внутренний параметр
	{ 1413	,1	,1	, &internal1_m1904_q0},	//(internal1_m1904_q0) q0 - внутренний параметр
	{ 1414	,1	,1	, &internal1_m1907_q0},	//(internal1_m1907_q0) q0 - внутренний параметр
	{ 1415	,1	,1	, &internal1_m2349_q0},	//(internal1_m2349_q0) q0 - внутренний параметр
	{ 1416	,1	,1	, &internal1_m2345_q0},	//(internal1_m2345_q0) q0 - внутренний параметр
	{ 1417	,1	,1	, &internal1_m1878_q0},	//(internal1_m1878_q0) q0 - внутренний параметр
	{ 1418	,1	,1	, &internal1_m1870_q0},	//(internal1_m1870_q0) q0 - внутренний параметр
	{ 1419	,1	,1	, &internal1_m1868_q0},	//(internal1_m1868_q0) q0 - внутренний параметр
	{ 1420	,1	,1	, &internal1_m1864_q0},	//(internal1_m1864_q0) q0 - внутренний параметр
	{ 1421	,1	,1	, &internal1_m1860_q0},	//(internal1_m1860_q0) q0 - внутренний параметр
	{ 1422	,1	,1	, &internal1_m1862_q0},	//(internal1_m1862_q0) q0 - внутренний параметр
	{ 1423	,1	,1	, &internal1_m19_q0},	//(internal1_m19_q0) q0 - внутренний параметр
	{ 1424	,1	,1	, &internal1_m1843_q0},	//(internal1_m1843_q0) q0 - внутренний параметр
	{ 1425	,1	,1	, &internal1_m1841_q0},	//(internal1_m1841_q0) q0 - внутренний параметр
	{ 1426	,1	,1	, &internal1_m1837_q0},	//(internal1_m1837_q0) q0 - внутренний параметр
	{ 1427	,1	,1	, &internal1_m1839_q0},	//(internal1_m1839_q0) q0 - внутренний параметр
	{ 1428	,1	,1	, &internal1_m1835_q0},	//(internal1_m1835_q0) q0 - внутренний параметр
	{ 1429	,1	,1	, &internal1_m1833_q0},	//(internal1_m1833_q0) q0 - внутренний параметр
	{ 1430	,1	,1	, &internal1_m2258_q0},	//(internal1_m2258_q0) q0 - внутренний параметр
	{ 1431	,1	,1	, &internal1_m2255_q0},	//(internal1_m2255_q0) q0 - внутренний параметр
	{ 1432	,1	,1	, &internal1_m2234_q0},	//(internal1_m2234_q0) q0 - внутренний параметр
	{ 1433	,1	,1	, &internal1_m2216_q0},	//(internal1_m2216_q0) q0 - внутренний параметр
	{ 1434	,1	,1	, &internal1_m2147_q0},	//(internal1_m2147_q0) q0 - внутренний параметр
	{ 1435	,1	,1	, &internal1_m1829_q0},	//(internal1_m1829_q0) q0 - внутренний параметр
	{ 1436	,1	,1	, &internal1_m1831_q0},	//(internal1_m1831_q0) q0 - внутренний параметр
	{ 1437	,1	,1	, &internal1_m1815_q0},	//(internal1_m1815_q0) q0 - внутренний параметр
	{ 1438	,1	,1	, &internal1_m1813_q0},	//(internal1_m1813_q0) q0 - внутренний параметр
	{ 1439	,1	,1	, &internal1_m1811_q0},	//(internal1_m1811_q0) q0 - внутренний параметр
	{ 1440	,1	,1	, &internal1_m1809_q0},	//(internal1_m1809_q0) q0 - внутренний параметр
	{ 1441	,1	,1	, &internal1_m1808_q0},	//(internal1_m1808_q0) q0 - внутренний параметр
	{ 1442	,1	,1	, &internal1_m1806_q0},	//(internal1_m1806_q0) q0 - внутренний параметр
	{ 1443	,1	,1	, &internal1_m1805_q0},	//(internal1_m1805_q0) q0 - внутренний параметр
	{ 1444	,1	,1	, &internal1_m1803_q0},	//(internal1_m1803_q0) q0 - внутренний параметр
	{ 1445	,18	,1	, &internal1_m2286_DvUp0},	//(internal1_m2286_DvUp0) - есть команда на движение вперёд
	{ 1446	,18	,1	, &internal1_m2286_DvDw0},	//(internal1_m2286_DvDw0) - есть команда на движение назад
	{ 1447	,18	,1	, &internal1_m2286_FDvUp0},	//(internal1_m2286_FDvUp0) - есть команда на движение вперёд
	{ 1448	,18	,1	, &internal1_m2286_FDvDw0},	//(internal1_m2286_FDvDw0) - есть команда на движение назад
	{ 1449	,18	,1	, &internal1_m2286_BlDv0},	//(internal1_m2286_BlDv0) - была блокировка
	{ 1450	,18	,1	, &internal1_m2286_Pkv0},	//(internal1_m2286_Pkv0) Pkv - передний конечный выключатель
	{ 1451	,18	,1	, &internal1_m2286_Pkav0},	//(internal1_m2286_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1452	,18	,1	, &internal1_m2286_Zkv0},	//(internal1_m2286_Zkv0) Zkv - задний конечный выключатель
	{ 1453	,18	,1	, &internal1_m2286_Zkav0},	//(internal1_m2286_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1454	,8	,1	, &internal1_m2286_txNm},	//(internal1_m2286_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1455	,8	,1	, &internal1_m2286_txSm},	//(internal1_m2286_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1456	,8	,1	, &internal1_m2286_txHr},	//(internal1_m2286_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1457	,8	,1	, &internal1_m2286_txLd},	//(internal1_m2286_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1458	,18	,1	, &internal1_m2286_fef},	//(internal1_m2286_fef) fef
	{ 1459	,18	,1	, &internal1_m2280_DvUp0},	//(internal1_m2280_DvUp0) - есть команда на движение вперёд
	{ 1460	,18	,1	, &internal1_m2280_DvDw0},	//(internal1_m2280_DvDw0) - есть команда на движение назад
	{ 1461	,18	,1	, &internal1_m2280_FDvUp0},	//(internal1_m2280_FDvUp0) - есть команда на движение вперёд
	{ 1462	,18	,1	, &internal1_m2280_FDvDw0},	//(internal1_m2280_FDvDw0) - есть команда на движение назад
	{ 1463	,18	,1	, &internal1_m2280_BlDv0},	//(internal1_m2280_BlDv0) - была блокировка
	{ 1464	,18	,1	, &internal1_m2280_Pkv0},	//(internal1_m2280_Pkv0) Pkv - передний конечный выключатель
	{ 1465	,18	,1	, &internal1_m2280_Pkav0},	//(internal1_m2280_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1466	,18	,1	, &internal1_m2280_Zkv0},	//(internal1_m2280_Zkv0) Zkv - задний конечный выключатель
	{ 1467	,18	,1	, &internal1_m2280_Zkav0},	//(internal1_m2280_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1468	,8	,1	, &internal1_m2280_txNm},	//(internal1_m2280_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1469	,8	,1	, &internal1_m2280_txSm},	//(internal1_m2280_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1470	,8	,1	, &internal1_m2280_txHr},	//(internal1_m2280_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1471	,8	,1	, &internal1_m2280_txLd},	//(internal1_m2280_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1472	,18	,1	, &internal1_m2280_fef},	//(internal1_m2280_fef) fef
	{ 1473	,1	,1	, &internal1_m1644_q0},	//(internal1_m1644_q0) q0 - внутренний параметр
	{ 1474	,1	,1	, &internal1_m1648_x0},	//(internal1_m1648_x0) был приход сигнала x1
	{ 1475	,8	,1	, &internal1_m1648_y0},	//(internal1_m1648_y0) интервал между сигналами х1 и х2
	{ 1476	,1	,1	, &internal1_m2086_x0},	//(internal1_m2086_x0) был приход сигнала x1
	{ 1477	,8	,1	, &internal1_m2086_y0},	//(internal1_m2086_y0) интервал между сигналами х1 и х2
	{ 1478	,1	,1	, &internal1_m2047_x0},	//(internal1_m2047_x0) был приход сигнала x1
	{ 1479	,8	,1	, &internal1_m2047_y0},	//(internal1_m2047_y0) интервал между сигналами х1 и х2
	{ 1480	,1	,1	, &internal1_m298_q0},	//(internal1_m298_q0) q0 - внутренний параметр
	{ 1481	,1	,1	, &internal1_m1113_q0},	//(internal1_m1113_q0) q0 - внутренний параметр
	{ 1482	,1	,1	, &internal1_m688_q0},	//(internal1_m688_q0) q0 - внутренний параметр
	{ 1483	,8	,1	, &internal1_m1450_X0},	//(internal1_m1450_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1484	,8	,1	, &internal1_m1450_t0},	//(internal1_m1450_t0) время нахождения в зоне возврата
	{ 1485	,18	,1	, &internal1_m1450_BLDv0},	//(internal1_m1450_BLDv0) BlDv - Блокировка движения
	{ 1486	,8	,1	, &internal1_m1467_tx},	//(internal1_m1467_tx) tx - время накопленное сек
	{ 1487	,18	,1	, &internal1_m1467_y0},	//(internal1_m1467_y0) y0
	{ 1488	,8	,1	, &internal1_m1468_tx},	//(internal1_m1468_tx) tx - время накопленное сек
	{ 1489	,18	,1	, &internal1_m1468_y0},	//(internal1_m1468_y0) y0
	{ 1490	,3	,1	, &internal1_m1476_xptr},	//(internal1_m1476_xptr) указатель текущей позиции в массиве координат
	{ 1491	,8	,60	, &internal1_m1476_x0},	//(internal1_m1476_x0) x0 - массив мгновенных значений координат
	{ 1492	,8	,60	, &internal1_m1476_tim0},	//(internal1_m1476_tim0) tim0 - массив значений времени цикла
	{ 1493	,8	,1	, &internal1_m1476_sumtim},	//(internal1_m1476_sumtim) sumtim - время в пути
	{ 1494	,8	,1	, &internal1_m1476_StSpeed},	//(internal1_m1476_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1495	,8	,1	, &internal1_m1476_Vz0},	//(internal1_m1476_Vz0) Vz0 - предыдущая заданная скорость
	{ 1496	,3	,1	, &internal1_m1476_flRazg},	//(internal1_m1476_flRazg) признак разгона/торможения
	{ 1497	,8	,1	, &internal1_m1476_DelSp},	//(internal1_m1476_DelSp) DelSp - время переключения скоростей
	{ 1498	,8	,1	, &internal1_m1476_z0},	//(internal1_m1476_z0) z0 - точка прекращения движения
	{ 1499	,8	,1	, &internal1_m1476_txZS},	//(internal1_m1476_txZS) txZS
	{ 1500	,8	,1	, &internal1_m1476_tx},	//(internal1_m1476_tx) tx
	{ 1501	,8	,1	, &internal1_m1476_txd},	//(internal1_m1476_txd) txd
	{ 1502	,8	,1	, &internal1_m1476_txMBl},	//(internal1_m1476_txMBl) tx
	{ 1503	,8	,1	, &internal1_m1476_txBl},	//(internal1_m1476_txBl) tx
	{ 1504	,8	,1	, &internal1_m1476_Speed0},	//(internal1_m1476_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1505	,8	,1	, &internal1_m1476_xz0},	//(internal1_m1476_xz0) xz0 - новое задание мм
	{ 1506	,8	,1	, &internal1_m1476_tz0},	//(internal1_m1476_tz0) tz0 - время защиты от нового задания сек
	{ 1507	,1	,1	, &internal1_m1476_Shift0},	//(internal1_m1476_Shift0) Shift0 - признак самохода
	{ 1508	,1	,1	, &internal1_m1476_ShCntlSp0},	//(internal1_m1476_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1509	,1	,1	, &internal1_m1476_ShiftControl},	//(internal1_m1476_ShiftControl) ShiftControl - признак самохода
	{ 1510	,1	,1	, &internal1_m686_q0},	//(internal1_m686_q0) q0 - внутренний параметр
	{ 1511	,8	,1	, &internal1_m994_X0},	//(internal1_m994_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1512	,8	,1	, &internal1_m994_t0},	//(internal1_m994_t0) время нахождения в зоне возврата
	{ 1513	,18	,1	, &internal1_m994_BLDv0},	//(internal1_m994_BLDv0) BlDv - Блокировка движения
	{ 1514	,8	,1	, &internal1_m1017_tx},	//(internal1_m1017_tx) tx - время накопленное сек
	{ 1515	,18	,1	, &internal1_m1017_y0},	//(internal1_m1017_y0) y0
	{ 1516	,8	,1	, &internal1_m1016_tx},	//(internal1_m1016_tx) tx - время накопленное сек
	{ 1517	,18	,1	, &internal1_m1016_y0},	//(internal1_m1016_y0) y0
	{ 1518	,3	,1	, &internal1_m1024_xptr},	//(internal1_m1024_xptr) указатель текущей позиции в массиве координат
	{ 1519	,8	,60	, &internal1_m1024_x0},	//(internal1_m1024_x0) x0 - массив мгновенных значений координат
	{ 1520	,8	,60	, &internal1_m1024_tim0},	//(internal1_m1024_tim0) tim0 - массив значений времени цикла
	{ 1521	,8	,1	, &internal1_m1024_sumtim},	//(internal1_m1024_sumtim) sumtim - время в пути
	{ 1522	,8	,1	, &internal1_m1024_StSpeed},	//(internal1_m1024_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1523	,8	,1	, &internal1_m1024_Vz0},	//(internal1_m1024_Vz0) Vz0 - предыдущая заданная скорость
	{ 1524	,3	,1	, &internal1_m1024_flRazg},	//(internal1_m1024_flRazg) признак разгона/торможения
	{ 1525	,8	,1	, &internal1_m1024_DelSp},	//(internal1_m1024_DelSp) DelSp - время переключения скоростей
	{ 1526	,8	,1	, &internal1_m1024_z0},	//(internal1_m1024_z0) z0 - точка прекращения движения
	{ 1527	,8	,1	, &internal1_m1024_txZS},	//(internal1_m1024_txZS) txZS
	{ 1528	,8	,1	, &internal1_m1024_tx},	//(internal1_m1024_tx) tx
	{ 1529	,8	,1	, &internal1_m1024_txd},	//(internal1_m1024_txd) txd
	{ 1530	,8	,1	, &internal1_m1024_txMBl},	//(internal1_m1024_txMBl) tx
	{ 1531	,8	,1	, &internal1_m1024_txBl},	//(internal1_m1024_txBl) tx
	{ 1532	,8	,1	, &internal1_m1024_Speed0},	//(internal1_m1024_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1533	,8	,1	, &internal1_m1024_xz0},	//(internal1_m1024_xz0) xz0 - новое задание мм
	{ 1534	,8	,1	, &internal1_m1024_tz0},	//(internal1_m1024_tz0) tz0 - время защиты от нового задания сек
	{ 1535	,1	,1	, &internal1_m1024_Shift0},	//(internal1_m1024_Shift0) Shift0 - признак самохода
	{ 1536	,1	,1	, &internal1_m1024_ShCntlSp0},	//(internal1_m1024_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1537	,1	,1	, &internal1_m1024_ShiftControl},	//(internal1_m1024_ShiftControl) ShiftControl - признак самохода
	{ 1538	,8	,1	, &internal1_m539_X0},	//(internal1_m539_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1539	,8	,1	, &internal1_m539_t0},	//(internal1_m539_t0) время нахождения в зоне возврата
	{ 1540	,18	,1	, &internal1_m539_BLDv0},	//(internal1_m539_BLDv0) BlDv - Блокировка движения
	{ 1541	,8	,1	, &internal1_m558_tx},	//(internal1_m558_tx) tx - время накопленное сек
	{ 1542	,18	,1	, &internal1_m558_y0},	//(internal1_m558_y0) y0
	{ 1543	,8	,1	, &internal1_m557_tx},	//(internal1_m557_tx) tx - время накопленное сек
	{ 1544	,18	,1	, &internal1_m557_y0},	//(internal1_m557_y0) y0
	{ 1545	,3	,1	, &internal1_m562_xptr},	//(internal1_m562_xptr) указатель текущей позиции в массиве координат
	{ 1546	,8	,150	, &internal1_m562_x0},	//(internal1_m562_x0) x0 - массив мгновенных значений координат
	{ 1547	,8	,150	, &internal1_m562_tim0},	//(internal1_m562_tim0) tim0 - массив значений времени цикла
	{ 1548	,8	,1	, &internal1_m562_sumtim},	//(internal1_m562_sumtim) sumtim - время в пути
	{ 1549	,8	,1	, &internal1_m562_StSpeed},	//(internal1_m562_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1550	,8	,1	, &internal1_m562_Vz0},	//(internal1_m562_Vz0) Vz0 - предыдущая заданная скорость
	{ 1551	,3	,1	, &internal1_m562_flRazg},	//(internal1_m562_flRazg) признак разгона/торможения
	{ 1552	,8	,1	, &internal1_m562_DelSp},	//(internal1_m562_DelSp) DelSp - время переключения скоростей
	{ 1553	,8	,1	, &internal1_m562_z0},	//(internal1_m562_z0) z0 - точка прекращения движения
	{ 1554	,8	,1	, &internal1_m562_txZS},	//(internal1_m562_txZS) txZS
	{ 1555	,8	,1	, &internal1_m562_tx},	//(internal1_m562_tx) tx
	{ 1556	,8	,1	, &internal1_m562_txd},	//(internal1_m562_txd) txd
	{ 1557	,8	,1	, &internal1_m562_txMBl},	//(internal1_m562_txMBl) tx
	{ 1558	,8	,1	, &internal1_m562_txBl},	//(internal1_m562_txBl) tx
	{ 1559	,8	,1	, &internal1_m562_Speed0},	//(internal1_m562_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1560	,8	,1	, &internal1_m562_xz0},	//(internal1_m562_xz0) xz0 - новое задание мм
	{ 1561	,8	,1	, &internal1_m562_tz0},	//(internal1_m562_tz0) tz0 - время защиты от нового задания сек
	{ 1562	,1	,1	, &internal1_m562_Shift0},	//(internal1_m562_Shift0) Shift0 - признак самохода
	{ 1563	,1	,1	, &internal1_m562_ShCntlSp0},	//(internal1_m562_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1564	,1	,1	, &internal1_m562_ShiftControl},	//(internal1_m562_ShiftControl) ShiftControl - признак самохода
	{ 1565	,1	,1	, &internal1_m683_q0},	//(internal1_m683_q0) q0 - внутренний параметр
	{ 1566	,8	,1	, &internal1_m169_X0},	//(internal1_m169_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1567	,8	,1	, &internal1_m169_t0},	//(internal1_m169_t0) время нахождения в зоне возврата
	{ 1568	,18	,1	, &internal1_m169_BLDv0},	//(internal1_m169_BLDv0) BlDv - Блокировка движения
	{ 1569	,3	,1	, &internal1_m194_xptr},	//(internal1_m194_xptr) указатель текущей позиции в массиве координат
	{ 1570	,8	,150	, &internal1_m194_x0},	//(internal1_m194_x0) x0 - массив мгновенных значений координат
	{ 1571	,8	,150	, &internal1_m194_tim0},	//(internal1_m194_tim0) tim0 - массив значений времени цикла
	{ 1572	,8	,1	, &internal1_m194_sumtim},	//(internal1_m194_sumtim) sumtim - время в пути
	{ 1573	,8	,1	, &internal1_m194_StSpeed},	//(internal1_m194_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1574	,8	,1	, &internal1_m194_Vz0},	//(internal1_m194_Vz0) Vz0 - предыдущая заданная скорость
	{ 1575	,3	,1	, &internal1_m194_flRazg},	//(internal1_m194_flRazg) признак разгона/торможения
	{ 1576	,8	,1	, &internal1_m194_DelSp},	//(internal1_m194_DelSp) DelSp - время переключения скоростей
	{ 1577	,8	,1	, &internal1_m194_z0},	//(internal1_m194_z0) z0 - точка прекращения движения
	{ 1578	,8	,1	, &internal1_m194_txZS},	//(internal1_m194_txZS) txZS
	{ 1579	,8	,1	, &internal1_m194_tx},	//(internal1_m194_tx) tx
	{ 1580	,8	,1	, &internal1_m194_txd},	//(internal1_m194_txd) txd
	{ 1581	,8	,1	, &internal1_m194_txMBl},	//(internal1_m194_txMBl) tx
	{ 1582	,8	,1	, &internal1_m194_txBl},	//(internal1_m194_txBl) tx
	{ 1583	,8	,1	, &internal1_m194_Speed0},	//(internal1_m194_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1584	,8	,1	, &internal1_m194_xz0},	//(internal1_m194_xz0) xz0 - новое задание мм
	{ 1585	,8	,1	, &internal1_m194_tz0},	//(internal1_m194_tz0) tz0 - время защиты от нового задания сек
	{ 1586	,1	,1	, &internal1_m194_Shift0},	//(internal1_m194_Shift0) Shift0 - признак самохода
	{ 1587	,1	,1	, &internal1_m194_ShCntlSp0},	//(internal1_m194_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1588	,1	,1	, &internal1_m194_ShiftControl},	//(internal1_m194_ShiftControl) ShiftControl - признак самохода
	{ 1589	,1	,1	, &internal1_m709_q0},	//(internal1_m709_q0) q0 - внутренний параметр
	{ 1590	,18	,1	, &internal1_m506_DvUp0},	//(internal1_m506_DvUp0) - есть команда на движение вперёд
	{ 1591	,18	,1	, &internal1_m506_DvDw0},	//(internal1_m506_DvDw0) - есть команда на движение назад
	{ 1592	,18	,1	, &internal1_m506_FDvUp0},	//(internal1_m506_FDvUp0) - есть команда на движение вперёд
	{ 1593	,18	,1	, &internal1_m506_FDvDw0},	//(internal1_m506_FDvDw0) - есть команда на движение назад
	{ 1594	,18	,1	, &internal1_m506_BlDv0},	//(internal1_m506_BlDv0) - была блокировка
	{ 1595	,18	,1	, &internal1_m506_Pkv0},	//(internal1_m506_Pkv0) Pkv - передний конечный выключатель
	{ 1596	,18	,1	, &internal1_m506_Pkav0},	//(internal1_m506_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1597	,18	,1	, &internal1_m506_Zkv0},	//(internal1_m506_Zkv0) Zkv - задний конечный выключатель
	{ 1598	,18	,1	, &internal1_m506_Zkav0},	//(internal1_m506_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1599	,8	,1	, &internal1_m506_txNm},	//(internal1_m506_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1600	,8	,1	, &internal1_m506_txSm},	//(internal1_m506_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1601	,8	,1	, &internal1_m506_txHr},	//(internal1_m506_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1602	,8	,1	, &internal1_m506_txLd},	//(internal1_m506_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1603	,18	,1	, &internal1_m506_fef},	//(internal1_m506_fef) fef
	{ 1604	,18	,1	, &internal1_m500_DvUp0},	//(internal1_m500_DvUp0) - есть команда на движение вперёд
	{ 1605	,18	,1	, &internal1_m500_DvDw0},	//(internal1_m500_DvDw0) - есть команда на движение назад
	{ 1606	,18	,1	, &internal1_m500_FDvUp0},	//(internal1_m500_FDvUp0) - есть команда на движение вперёд
	{ 1607	,18	,1	, &internal1_m500_FDvDw0},	//(internal1_m500_FDvDw0) - есть команда на движение назад
	{ 1608	,18	,1	, &internal1_m500_BlDv0},	//(internal1_m500_BlDv0) - была блокировка
	{ 1609	,18	,1	, &internal1_m500_Pkv0},	//(internal1_m500_Pkv0) Pkv - передний конечный выключатель
	{ 1610	,18	,1	, &internal1_m500_Pkav0},	//(internal1_m500_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1611	,18	,1	, &internal1_m500_Zkv0},	//(internal1_m500_Zkv0) Zkv - задний конечный выключатель
	{ 1612	,18	,1	, &internal1_m500_Zkav0},	//(internal1_m500_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1613	,8	,1	, &internal1_m500_txNm},	//(internal1_m500_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1614	,8	,1	, &internal1_m500_txSm},	//(internal1_m500_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1615	,8	,1	, &internal1_m500_txHr},	//(internal1_m500_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1616	,8	,1	, &internal1_m500_txLd},	//(internal1_m500_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1617	,18	,1	, &internal1_m500_fef},	//(internal1_m500_fef) fef
	{ 1618	,8	,1	, &internal1_m898_X0},	//(internal1_m898_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1619	,8	,1	, &internal1_m898_t0},	//(internal1_m898_t0) время нахождения в зоне возврата
	{ 1620	,18	,1	, &internal1_m898_BLDv0},	//(internal1_m898_BLDv0) BlDv - Блокировка движения
	{ 1621	,3	,1	, &internal1_m916_xptr},	//(internal1_m916_xptr) указатель текущей позиции в массиве координат
	{ 1622	,8	,80	, &internal1_m916_x0},	//(internal1_m916_x0) x0 - массив мгновенных значений координат
	{ 1623	,8	,80	, &internal1_m916_tim0},	//(internal1_m916_tim0) tim0 - массив значений времени цикла
	{ 1624	,8	,1	, &internal1_m916_sumtim},	//(internal1_m916_sumtim) sumtim - время в пути
	{ 1625	,8	,1	, &internal1_m916_StSpeed},	//(internal1_m916_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1626	,8	,1	, &internal1_m916_Vz0},	//(internal1_m916_Vz0) Vz0 - предыдущая заданная скорость
	{ 1627	,3	,1	, &internal1_m916_flRazg},	//(internal1_m916_flRazg) признак разгона/торможения
	{ 1628	,8	,1	, &internal1_m916_DelSp},	//(internal1_m916_DelSp) DelSp - время переключения скоростей
	{ 1629	,8	,1	, &internal1_m916_z0},	//(internal1_m916_z0) z0 - точка прекращения движения
	{ 1630	,8	,1	, &internal1_m916_txZS},	//(internal1_m916_txZS) txZS
	{ 1631	,8	,1	, &internal1_m916_tx},	//(internal1_m916_tx) tx
	{ 1632	,8	,1	, &internal1_m916_txd},	//(internal1_m916_txd) txd
	{ 1633	,8	,1	, &internal1_m916_txMBl},	//(internal1_m916_txMBl) tx
	{ 1634	,8	,1	, &internal1_m916_txBl},	//(internal1_m916_txBl) tx
	{ 1635	,8	,1	, &internal1_m916_Speed0},	//(internal1_m916_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1636	,8	,1	, &internal1_m916_xz0},	//(internal1_m916_xz0) xz0 - новое задание мм
	{ 1637	,8	,1	, &internal1_m916_tz0},	//(internal1_m916_tz0) tz0 - время защиты от нового задания сек
	{ 1638	,1	,1	, &internal1_m916_Shift0},	//(internal1_m916_Shift0) Shift0 - признак самохода
	{ 1639	,1	,1	, &internal1_m916_ShCntlSp0},	//(internal1_m916_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1640	,1	,1	, &internal1_m916_ShiftControl},	//(internal1_m916_ShiftControl) ShiftControl - признак самохода
	{ 1641	,8	,1	, &internal1_m1757_X0},	//(internal1_m1757_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1642	,8	,1	, &internal1_m1757_t0},	//(internal1_m1757_t0) время нахождения в зоне возврата
	{ 1643	,18	,1	, &internal1_m1757_BLDv0},	//(internal1_m1757_BLDv0) BlDv - Блокировка движения
	{ 1644	,8	,1	, &internal1_m1242_X0},	//(internal1_m1242_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1645	,8	,1	, &internal1_m1242_t0},	//(internal1_m1242_t0) время нахождения в зоне возврата
	{ 1646	,18	,1	, &internal1_m1242_BLDv0},	//(internal1_m1242_BLDv0) BlDv - Блокировка движения
	{ 1647	,1	,1	, &internal1_m681_q0},	//(internal1_m681_q0) q0 - внутренний параметр
	{ 1648	,8	,1	, &internal1_m1337_X0},	//(internal1_m1337_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1649	,8	,1	, &internal1_m1337_t0},	//(internal1_m1337_t0) время нахождения в зоне возврата
	{ 1650	,18	,1	, &internal1_m1337_BLDv0},	//(internal1_m1337_BLDv0) BlDv - Блокировка движения
	{ 1651	,8	,1	, &internal1_m1366_tx},	//(internal1_m1366_tx) tx - время накопленное сек
	{ 1652	,18	,1	, &internal1_m1366_y0},	//(internal1_m1366_y0) y0
	{ 1653	,8	,1	, &internal1_m1365_tx},	//(internal1_m1365_tx) tx - время накопленное сек
	{ 1654	,18	,1	, &internal1_m1365_y0},	//(internal1_m1365_y0) y0
	{ 1655	,3	,1	, &internal1_m1372_xptr},	//(internal1_m1372_xptr) указатель текущей позиции в массиве координат
	{ 1656	,8	,80	, &internal1_m1372_x0},	//(internal1_m1372_x0) x0 - массив мгновенных значений координат
	{ 1657	,8	,80	, &internal1_m1372_tim0},	//(internal1_m1372_tim0) tim0 - массив значений времени цикла
	{ 1658	,8	,1	, &internal1_m1372_sumtim},	//(internal1_m1372_sumtim) sumtim - время в пути
	{ 1659	,8	,1	, &internal1_m1372_StSpeed},	//(internal1_m1372_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1660	,8	,1	, &internal1_m1372_Vz0},	//(internal1_m1372_Vz0) Vz0 - предыдущая заданная скорость
	{ 1661	,3	,1	, &internal1_m1372_flRazg},	//(internal1_m1372_flRazg) признак разгона/торможения
	{ 1662	,8	,1	, &internal1_m1372_DelSp},	//(internal1_m1372_DelSp) DelSp - время переключения скоростей
	{ 1663	,8	,1	, &internal1_m1372_z0},	//(internal1_m1372_z0) z0 - точка прекращения движения
	{ 1664	,8	,1	, &internal1_m1372_txZS},	//(internal1_m1372_txZS) txZS
	{ 1665	,8	,1	, &internal1_m1372_tx},	//(internal1_m1372_tx) tx
	{ 1666	,8	,1	, &internal1_m1372_txd},	//(internal1_m1372_txd) txd
	{ 1667	,8	,1	, &internal1_m1372_txMBl},	//(internal1_m1372_txMBl) tx
	{ 1668	,8	,1	, &internal1_m1372_txBl},	//(internal1_m1372_txBl) tx
	{ 1669	,8	,1	, &internal1_m1372_Speed0},	//(internal1_m1372_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1670	,8	,1	, &internal1_m1372_xz0},	//(internal1_m1372_xz0) xz0 - новое задание мм
	{ 1671	,8	,1	, &internal1_m1372_tz0},	//(internal1_m1372_tz0) tz0 - время защиты от нового задания сек
	{ 1672	,1	,1	, &internal1_m1372_Shift0},	//(internal1_m1372_Shift0) Shift0 - признак самохода
	{ 1673	,1	,1	, &internal1_m1372_ShCntlSp0},	//(internal1_m1372_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1674	,1	,1	, &internal1_m1372_ShiftControl},	//(internal1_m1372_ShiftControl) ShiftControl - признак самохода
	{ 1675	,1	,1	, &internal1_m701_q0},	//(internal1_m701_q0) q0 - внутренний параметр
	{ 1676	,8	,1	, &internal1_m1771_tx},	//(internal1_m1771_tx) tx - время накопленное сек
	{ 1677	,18	,1	, &internal1_m1771_y0},	//(internal1_m1771_y0) y0
	{ 1678	,8	,1	, &internal1_m1775_tx},	//(internal1_m1775_tx) tx - время накопленное сек
	{ 1679	,18	,1	, &internal1_m1775_y0},	//(internal1_m1775_y0) y0
	{ 1680	,18	,1	, &internal1_m1760_DvUp0},	//(internal1_m1760_DvUp0) - есть команда на движение вперёд
	{ 1681	,18	,1	, &internal1_m1760_DvDw0},	//(internal1_m1760_DvDw0) - есть команда на движение назад
	{ 1682	,18	,1	, &internal1_m1760_FDvUp0},	//(internal1_m1760_FDvUp0) - есть команда на движение вперёд
	{ 1683	,18	,1	, &internal1_m1760_FDvDw0},	//(internal1_m1760_FDvDw0) - есть команда на движение назад
	{ 1684	,18	,1	, &internal1_m1760_BlDv0},	//(internal1_m1760_BlDv0) - была блокировка
	{ 1685	,18	,1	, &internal1_m1760_Pkv0},	//(internal1_m1760_Pkv0) Pkv - передний конечный выключатель
	{ 1686	,18	,1	, &internal1_m1760_Pkav0},	//(internal1_m1760_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1687	,18	,1	, &internal1_m1760_Zkv0},	//(internal1_m1760_Zkv0) Zkv - задний конечный выключатель
	{ 1688	,18	,1	, &internal1_m1760_Zkav0},	//(internal1_m1760_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1689	,8	,1	, &internal1_m1760_txNm},	//(internal1_m1760_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1690	,8	,1	, &internal1_m1760_txSm},	//(internal1_m1760_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1691	,8	,1	, &internal1_m1760_txHr},	//(internal1_m1760_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1692	,8	,1	, &internal1_m1760_txLd},	//(internal1_m1760_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1693	,18	,1	, &internal1_m1760_fef},	//(internal1_m1760_fef) fef
	{ 1694	,3	,1	, &internal1_m1779_xptr},	//(internal1_m1779_xptr) указатель текущей позиции в массиве координат
	{ 1695	,8	,20	, &internal1_m1779_x0},	//(internal1_m1779_x0) x0 - массив мгновенных значений координат
	{ 1696	,8	,20	, &internal1_m1779_tim0},	//(internal1_m1779_tim0) tim0 - массив значений времени цикла
	{ 1697	,8	,1	, &internal1_m1779_sumtim},	//(internal1_m1779_sumtim) sumtim - время в пути
	{ 1698	,8	,1	, &internal1_m1779_StSpeed},	//(internal1_m1779_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1699	,8	,1	, &internal1_m1779_Vz0},	//(internal1_m1779_Vz0) Vz0 - предыдущая заданная скорость
	{ 1700	,3	,1	, &internal1_m1779_flRazg},	//(internal1_m1779_flRazg) признак разгона/торможения
	{ 1701	,8	,1	, &internal1_m1779_DelSp},	//(internal1_m1779_DelSp) DelSp - время переключения скоростей
	{ 1702	,8	,1	, &internal1_m1779_z0},	//(internal1_m1779_z0) z0 - точка прекращения движения
	{ 1703	,8	,1	, &internal1_m1779_txZS},	//(internal1_m1779_txZS) txZS
	{ 1704	,8	,1	, &internal1_m1779_tx},	//(internal1_m1779_tx) tx
	{ 1705	,8	,1	, &internal1_m1779_txd},	//(internal1_m1779_txd) txd
	{ 1706	,8	,1	, &internal1_m1779_txMBl},	//(internal1_m1779_txMBl) tx
	{ 1707	,8	,1	, &internal1_m1779_txBl},	//(internal1_m1779_txBl) tx
	{ 1708	,8	,1	, &internal1_m1779_Speed0},	//(internal1_m1779_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1709	,8	,1	, &internal1_m1779_xz0},	//(internal1_m1779_xz0) xz0 - новое задание мм
	{ 1710	,8	,1	, &internal1_m1779_tz0},	//(internal1_m1779_tz0) tz0 - время защиты от нового задания сек
	{ 1711	,1	,1	, &internal1_m1779_Shift0},	//(internal1_m1779_Shift0) Shift0 - признак самохода
	{ 1712	,1	,1	, &internal1_m1779_ShCntlSp0},	//(internal1_m1779_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1713	,1	,1	, &internal1_m1779_ShiftControl},	//(internal1_m1779_ShiftControl) ShiftControl - признак самохода
	{ 1714	,8	,1	, &internal1_m1257_tx},	//(internal1_m1257_tx) tx - время накопленное сек
	{ 1715	,18	,1	, &internal1_m1257_y0},	//(internal1_m1257_y0) y0
	{ 1716	,8	,1	, &internal1_m1261_tx},	//(internal1_m1261_tx) tx - время накопленное сек
	{ 1717	,18	,1	, &internal1_m1261_y0},	//(internal1_m1261_y0) y0
	{ 1718	,1	,1	, &internal1_m691_q0},	//(internal1_m691_q0) q0 - внутренний параметр
	{ 1719	,1	,1	, &internal1_m656_q0},	//(internal1_m656_q0) q0 - внутренний параметр
	{ 1720	,18	,1	, &internal1_m1248_DvUp0},	//(internal1_m1248_DvUp0) - есть команда на движение вперёд
	{ 1721	,18	,1	, &internal1_m1248_DvDw0},	//(internal1_m1248_DvDw0) - есть команда на движение назад
	{ 1722	,18	,1	, &internal1_m1248_FDvUp0},	//(internal1_m1248_FDvUp0) - есть команда на движение вперёд
	{ 1723	,18	,1	, &internal1_m1248_FDvDw0},	//(internal1_m1248_FDvDw0) - есть команда на движение назад
	{ 1724	,18	,1	, &internal1_m1248_BlDv0},	//(internal1_m1248_BlDv0) - была блокировка
	{ 1725	,18	,1	, &internal1_m1248_Pkv0},	//(internal1_m1248_Pkv0) Pkv - передний конечный выключатель
	{ 1726	,18	,1	, &internal1_m1248_Pkav0},	//(internal1_m1248_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1727	,18	,1	, &internal1_m1248_Zkv0},	//(internal1_m1248_Zkv0) Zkv - задний конечный выключатель
	{ 1728	,18	,1	, &internal1_m1248_Zkav0},	//(internal1_m1248_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1729	,8	,1	, &internal1_m1248_txNm},	//(internal1_m1248_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1730	,8	,1	, &internal1_m1248_txSm},	//(internal1_m1248_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1731	,8	,1	, &internal1_m1248_txHr},	//(internal1_m1248_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1732	,8	,1	, &internal1_m1248_txLd},	//(internal1_m1248_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1733	,18	,1	, &internal1_m1248_fef},	//(internal1_m1248_fef) fef
	{ 1734	,3	,1	, &internal1_m1267_xptr},	//(internal1_m1267_xptr) указатель текущей позиции в массиве координат
	{ 1735	,8	,20	, &internal1_m1267_x0},	//(internal1_m1267_x0) x0 - массив мгновенных значений координат
	{ 1736	,8	,20	, &internal1_m1267_tim0},	//(internal1_m1267_tim0) tim0 - массив значений времени цикла
	{ 1737	,8	,1	, &internal1_m1267_sumtim},	//(internal1_m1267_sumtim) sumtim - время в пути
	{ 1738	,8	,1	, &internal1_m1267_StSpeed},	//(internal1_m1267_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1739	,8	,1	, &internal1_m1267_Vz0},	//(internal1_m1267_Vz0) Vz0 - предыдущая заданная скорость
	{ 1740	,3	,1	, &internal1_m1267_flRazg},	//(internal1_m1267_flRazg) признак разгона/торможения
	{ 1741	,8	,1	, &internal1_m1267_DelSp},	//(internal1_m1267_DelSp) DelSp - время переключения скоростей
	{ 1742	,8	,1	, &internal1_m1267_z0},	//(internal1_m1267_z0) z0 - точка прекращения движения
	{ 1743	,8	,1	, &internal1_m1267_txZS},	//(internal1_m1267_txZS) txZS
	{ 1744	,8	,1	, &internal1_m1267_tx},	//(internal1_m1267_tx) tx
	{ 1745	,8	,1	, &internal1_m1267_txd},	//(internal1_m1267_txd) txd
	{ 1746	,8	,1	, &internal1_m1267_txMBl},	//(internal1_m1267_txMBl) tx
	{ 1747	,8	,1	, &internal1_m1267_txBl},	//(internal1_m1267_txBl) tx
	{ 1748	,8	,1	, &internal1_m1267_Speed0},	//(internal1_m1267_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1749	,8	,1	, &internal1_m1267_xz0},	//(internal1_m1267_xz0) xz0 - новое задание мм
	{ 1750	,8	,1	, &internal1_m1267_tz0},	//(internal1_m1267_tz0) tz0 - время защиты от нового задания сек
	{ 1751	,1	,1	, &internal1_m1267_Shift0},	//(internal1_m1267_Shift0) Shift0 - признак самохода
	{ 1752	,1	,1	, &internal1_m1267_ShCntlSp0},	//(internal1_m1267_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1753	,1	,1	, &internal1_m1267_ShiftControl},	//(internal1_m1267_ShiftControl) ShiftControl - признак самохода
	{ 1754	,1	,1	, &internal1_m819_x0},	//(internal1_m819_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1755	,1	,1	, &internal1_m787_x0},	//(internal1_m787_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1756	,1	,1	, &internal1_m730_x0},	//(internal1_m730_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1757	,1	,1	, &internal1_m844_q0},	//(internal1_m844_q0) q0 - внутренний параметр
	{ 1758	,1	,1	, &internal1_m839_q0},	//(internal1_m839_q0) q0 - внутренний параметр
	{ 1759	,1	,1	, &internal1_m807_q0},	//(internal1_m807_q0) q0 - внутренний параметр
	{ 1760	,1	,1	, &internal1_m812_q0},	//(internal1_m812_q0) q0 - внутренний параметр
	{ 1761	,1	,1	, &internal1_m820_q0},	//(internal1_m820_q0) q0 - внутренний параметр
	{ 1762	,1	,1	, &internal1_m832_q0},	//(internal1_m832_q0) q0 - внутренний параметр
	{ 1763	,1	,1	, &internal1_m810_q0},	//(internal1_m810_q0) q0 - внутренний параметр
	{ 1764	,18	,1	, &internal1_m1309_DvUp0},	//(internal1_m1309_DvUp0) - есть команда на движение вперёд
	{ 1765	,18	,1	, &internal1_m1309_DvDw0},	//(internal1_m1309_DvDw0) - есть команда на движение назад
	{ 1766	,18	,1	, &internal1_m1309_FDvUp0},	//(internal1_m1309_FDvUp0) - есть команда на движение вперёд
	{ 1767	,18	,1	, &internal1_m1309_FDvDw0},	//(internal1_m1309_FDvDw0) - есть команда на движение назад
	{ 1768	,18	,1	, &internal1_m1309_BlDv0},	//(internal1_m1309_BlDv0) - была блокировка
	{ 1769	,18	,1	, &internal1_m1309_Pkv0},	//(internal1_m1309_Pkv0) Pkv - передний конечный выключатель
	{ 1770	,18	,1	, &internal1_m1309_Pkav0},	//(internal1_m1309_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1771	,18	,1	, &internal1_m1309_Zkv0},	//(internal1_m1309_Zkv0) Zkv - задний конечный выключатель
	{ 1772	,18	,1	, &internal1_m1309_Zkav0},	//(internal1_m1309_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1773	,8	,1	, &internal1_m1309_txNm},	//(internal1_m1309_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1774	,8	,1	, &internal1_m1309_txSm},	//(internal1_m1309_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1775	,8	,1	, &internal1_m1309_txHr},	//(internal1_m1309_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1776	,8	,1	, &internal1_m1309_txLd},	//(internal1_m1309_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1777	,18	,1	, &internal1_m1309_fef},	//(internal1_m1309_fef) fef
	{ 1778	,18	,1	, &internal1_m1300_DvUp0},	//(internal1_m1300_DvUp0) - есть команда на движение вперёд
	{ 1779	,18	,1	, &internal1_m1300_DvDw0},	//(internal1_m1300_DvDw0) - есть команда на движение назад
	{ 1780	,18	,1	, &internal1_m1300_FDvUp0},	//(internal1_m1300_FDvUp0) - есть команда на движение вперёд
	{ 1781	,18	,1	, &internal1_m1300_FDvDw0},	//(internal1_m1300_FDvDw0) - есть команда на движение назад
	{ 1782	,18	,1	, &internal1_m1300_BlDv0},	//(internal1_m1300_BlDv0) - была блокировка
	{ 1783	,18	,1	, &internal1_m1300_Pkv0},	//(internal1_m1300_Pkv0) Pkv - передний конечный выключатель
	{ 1784	,18	,1	, &internal1_m1300_Pkav0},	//(internal1_m1300_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1785	,18	,1	, &internal1_m1300_Zkv0},	//(internal1_m1300_Zkv0) Zkv - задний конечный выключатель
	{ 1786	,18	,1	, &internal1_m1300_Zkav0},	//(internal1_m1300_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1787	,8	,1	, &internal1_m1300_txNm},	//(internal1_m1300_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1788	,8	,1	, &internal1_m1300_txSm},	//(internal1_m1300_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1789	,8	,1	, &internal1_m1300_txHr},	//(internal1_m1300_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1790	,8	,1	, &internal1_m1300_txLd},	//(internal1_m1300_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1791	,18	,1	, &internal1_m1300_fef},	//(internal1_m1300_fef) fef
	{ 1792	,18	,1	, &internal1_m868_DvUp0},	//(internal1_m868_DvUp0) - есть команда на движение вперёд
	{ 1793	,18	,1	, &internal1_m868_DvDw0},	//(internal1_m868_DvDw0) - есть команда на движение назад
	{ 1794	,18	,1	, &internal1_m868_FDvUp0},	//(internal1_m868_FDvUp0) - есть команда на движение вперёд
	{ 1795	,18	,1	, &internal1_m868_FDvDw0},	//(internal1_m868_FDvDw0) - есть команда на движение назад
	{ 1796	,18	,1	, &internal1_m868_BlDv0},	//(internal1_m868_BlDv0) - была блокировка
	{ 1797	,18	,1	, &internal1_m868_Pkv0},	//(internal1_m868_Pkv0) Pkv - передний конечный выключатель
	{ 1798	,18	,1	, &internal1_m868_Pkav0},	//(internal1_m868_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1799	,18	,1	, &internal1_m868_Zkv0},	//(internal1_m868_Zkv0) Zkv - задний конечный выключатель
	{ 1800	,18	,1	, &internal1_m868_Zkav0},	//(internal1_m868_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1801	,8	,1	, &internal1_m868_txNm},	//(internal1_m868_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1802	,8	,1	, &internal1_m868_txSm},	//(internal1_m868_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1803	,8	,1	, &internal1_m868_txHr},	//(internal1_m868_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1804	,8	,1	, &internal1_m868_txLd},	//(internal1_m868_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1805	,18	,1	, &internal1_m868_fef},	//(internal1_m868_fef) fef
	{ 1806	,18	,1	, &internal1_m864_DvUp0},	//(internal1_m864_DvUp0) - есть команда на движение вперёд
	{ 1807	,18	,1	, &internal1_m864_DvDw0},	//(internal1_m864_DvDw0) - есть команда на движение назад
	{ 1808	,18	,1	, &internal1_m864_FDvUp0},	//(internal1_m864_FDvUp0) - есть команда на движение вперёд
	{ 1809	,18	,1	, &internal1_m864_FDvDw0},	//(internal1_m864_FDvDw0) - есть команда на движение назад
	{ 1810	,18	,1	, &internal1_m864_BlDv0},	//(internal1_m864_BlDv0) - была блокировка
	{ 1811	,18	,1	, &internal1_m864_Pkv0},	//(internal1_m864_Pkv0) Pkv - передний конечный выключатель
	{ 1812	,18	,1	, &internal1_m864_Pkav0},	//(internal1_m864_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1813	,18	,1	, &internal1_m864_Zkv0},	//(internal1_m864_Zkv0) Zkv - задний конечный выключатель
	{ 1814	,18	,1	, &internal1_m864_Zkav0},	//(internal1_m864_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1815	,8	,1	, &internal1_m864_txNm},	//(internal1_m864_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1816	,8	,1	, &internal1_m864_txSm},	//(internal1_m864_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1817	,8	,1	, &internal1_m864_txHr},	//(internal1_m864_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1818	,8	,1	, &internal1_m864_txLd},	//(internal1_m864_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1819	,18	,1	, &internal1_m864_fef},	//(internal1_m864_fef) fef
	{ 1820	,18	,1	, &internal1_m379_DvUp0},	//(internal1_m379_DvUp0) - есть команда на движение вперёд
	{ 1821	,18	,1	, &internal1_m379_DvDw0},	//(internal1_m379_DvDw0) - есть команда на движение назад
	{ 1822	,18	,1	, &internal1_m379_FDvUp0},	//(internal1_m379_FDvUp0) - есть команда на движение вперёд
	{ 1823	,18	,1	, &internal1_m379_FDvDw0},	//(internal1_m379_FDvDw0) - есть команда на движение назад
	{ 1824	,18	,1	, &internal1_m379_BlDv0},	//(internal1_m379_BlDv0) - была блокировка
	{ 1825	,18	,1	, &internal1_m379_Pkv0},	//(internal1_m379_Pkv0) Pkv - передний конечный выключатель
	{ 1826	,18	,1	, &internal1_m379_Pkav0},	//(internal1_m379_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1827	,18	,1	, &internal1_m379_Zkv0},	//(internal1_m379_Zkv0) Zkv - задний конечный выключатель
	{ 1828	,18	,1	, &internal1_m379_Zkav0},	//(internal1_m379_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1829	,8	,1	, &internal1_m379_txNm},	//(internal1_m379_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1830	,8	,1	, &internal1_m379_txSm},	//(internal1_m379_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1831	,8	,1	, &internal1_m379_txHr},	//(internal1_m379_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1832	,8	,1	, &internal1_m379_txLd},	//(internal1_m379_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1833	,18	,1	, &internal1_m379_fef},	//(internal1_m379_fef) fef
	{ 1834	,18	,1	, &internal1_m416_DvUp0},	//(internal1_m416_DvUp0) - есть команда на движение вперёд
	{ 1835	,18	,1	, &internal1_m416_DvDw0},	//(internal1_m416_DvDw0) - есть команда на движение назад
	{ 1836	,18	,1	, &internal1_m416_FDvUp0},	//(internal1_m416_FDvUp0) - есть команда на движение вперёд
	{ 1837	,18	,1	, &internal1_m416_FDvDw0},	//(internal1_m416_FDvDw0) - есть команда на движение назад
	{ 1838	,18	,1	, &internal1_m416_BlDv0},	//(internal1_m416_BlDv0) - была блокировка
	{ 1839	,18	,1	, &internal1_m416_Pkv0},	//(internal1_m416_Pkv0) Pkv - передний конечный выключатель
	{ 1840	,18	,1	, &internal1_m416_Pkav0},	//(internal1_m416_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1841	,18	,1	, &internal1_m416_Zkv0},	//(internal1_m416_Zkv0) Zkv - задний конечный выключатель
	{ 1842	,18	,1	, &internal1_m416_Zkav0},	//(internal1_m416_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1843	,8	,1	, &internal1_m416_txNm},	//(internal1_m416_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1844	,8	,1	, &internal1_m416_txSm},	//(internal1_m416_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1845	,8	,1	, &internal1_m416_txHr},	//(internal1_m416_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1846	,8	,1	, &internal1_m416_txLd},	//(internal1_m416_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1847	,18	,1	, &internal1_m416_fef},	//(internal1_m416_fef) fef
	{ 1848	,18	,1	, &internal1_m410_DvUp0},	//(internal1_m410_DvUp0) - есть команда на движение вперёд
	{ 1849	,18	,1	, &internal1_m410_DvDw0},	//(internal1_m410_DvDw0) - есть команда на движение назад
	{ 1850	,18	,1	, &internal1_m410_FDvUp0},	//(internal1_m410_FDvUp0) - есть команда на движение вперёд
	{ 1851	,18	,1	, &internal1_m410_FDvDw0},	//(internal1_m410_FDvDw0) - есть команда на движение назад
	{ 1852	,18	,1	, &internal1_m410_BlDv0},	//(internal1_m410_BlDv0) - была блокировка
	{ 1853	,18	,1	, &internal1_m410_Pkv0},	//(internal1_m410_Pkv0) Pkv - передний конечный выключатель
	{ 1854	,18	,1	, &internal1_m410_Pkav0},	//(internal1_m410_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1855	,18	,1	, &internal1_m410_Zkv0},	//(internal1_m410_Zkv0) Zkv - задний конечный выключатель
	{ 1856	,18	,1	, &internal1_m410_Zkav0},	//(internal1_m410_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1857	,8	,1	, &internal1_m410_txNm},	//(internal1_m410_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1858	,8	,1	, &internal1_m410_txSm},	//(internal1_m410_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1859	,8	,1	, &internal1_m410_txHr},	//(internal1_m410_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1860	,8	,1	, &internal1_m410_txLd},	//(internal1_m410_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1861	,18	,1	, &internal1_m410_fef},	//(internal1_m410_fef) fef
	{ 1862	,1	,1	, &internal1_m816_q0},	//(internal1_m816_q0) q0 - внутренний параметр
	{ 1863	,1	,1	, &internal1_m813_q0},	//(internal1_m813_q0) q0 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="du.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{738,"fEM_A1UC03RDU\0"}, 
{739,"dEM_A1UC05UDU\0"}, 
{740,"dEM_A1UC06UDU\0"}, 
{741,"dEM_A2UC06UDU\0"}, 
{742,"dEM_A2UC05UDU\0"}, 
{743,"fEM_A2UC03RDU\0"}, 
{744,"dEM_A3UC06UDU\0"}, 
{745,"dEM_A3UC05UDU\0"}, 
{746,"fEM_A3UC03RDU\0"}, 
{747,"dEM_A8UC06UDU\0"}, 
{748,"fEM_A8UC03RDU\0"}, 
{749,"dEM_A8UC05UDU\0"}, 
{750,"fEM_R0UV81RDU\0"}, 
{751,"fEM_R0UV82RDU\0"}, 
{752,"fEM_R0UV83RDU\0"}, 
{753,"fEM_R0UV84RDU\0"}, 
{754,"fEM_R0UV86RDU\0"}, 
{755,"fEM_R0UV85RDU\0"}, 
{756,"fEM_R0UV87RDU\0"}, 
{757,"fEM_A3UP03RDU\0"}, 
{758,"fEM_A3UP04RDU\0"}, 
{759,"fEM_A3UP43RDU\0"}, 
{760,"fEM_A3UP44RDU\0"}, 
{761,"fEM_A3UP53RDU\0"}, 
{762,"fEM_A3UP85RDU\0"}, 
{763,"fEM_A3UP88RDU\0"}, 
{764,"fEM_A3UP86RDU\0"}, 
{765,"fEM_B8UV01RDU\0"}, 
{766,"fEM_B8UV02RDU\0"}, 
{767,"fEM_B8UV03RDU\0"}, 
{768,"fEM_B8UL04RDU\0"}, 
{769,"iEM_A2UV03CDU\0"}, 
{770,"fEM_A2UV01RDU\0"}, 
{771,"fEM_A2UV02RDU\0"}, 
{772,"fEM_A1UV01RDU\0"}, 
{773,"fEM_A1UV02RDU\0"}, 
{774,"fEM_A1UC06RDU\0"}, 
{775,"fEM_A1UC05RDU\0"}, 
{776,"fEM_A1UL04RDU\0"}, 
{777,"fEM_A3UV01RDU\0"}, 
{778,"fEM_A3UV02RDU\0"}, 
{779,"fEM_A3UC06RDU\0"}, 
{780,"fEM_A3UC05RDU\0"}, 
{781,"fEM_A3UL04RDU\0"}, 
{782,"fEM_A3UP54RDU\0"}, 
{783,"fEM_A3UP87RDU\0"}, 
{784,"fEM_R0UL05RDU\0"}, 
{785,"fEM_R0UL20RDU\0"}, 
{786,"fEM_B8UV04RDU\0"}, 
{787,"fEM_B8UC06RDU\0"}, 
{788,"fEM_B8UC05RDU\0"}, 
{789,"fEM_A2UL05RDU\0"}, 
{790,"fEM_A2UL03RDU\0"}, 
{791,"fEM_A2UC06RDU\0"}, 
{792,"fEM_A2UC05RDU\0"}, 
{793,"fEM_A2UL04RDU\0"}, 
{794,"fEM_A1UL03RDU\0"}, 
{795,"fEM_A1UL05RDU\0"}, 
{796,"fEM_A3UL03RDU\0"}, 
{797,"fEM_A3UL05RDU\0"}, 
{798,"fEM_A1UC08RDU\0"}, 
{799,"fEM_A3UC08RDU\0"}, 
{800,"fEM_A1UC07RDU\0"}, 
{801,"fEM_A1UL01RDU\0"}, 
{802,"fEM_A3UC07RDU\0"}, 
{803,"fEM_A3UL01RDU\0"}, 
{804,"fEM_A2UC08RDU\0"}, 
{805,"fEM_A2UC07RDU\0"}, 
{806,"fEM_A2UL01RDU\0"}, 
{807,"fEM_B8UC01RDU\0"}, 
{808,"fEM_B8UL07RDU\0"}, 
{809,"fEM_B8UC02RDU\0"}, 
{810,"fEM_B8UL01RDU\0"}, 
{811,"fEM_B8UL05RDU\0"}, 
{812,"fEM_B8UL03RDU\0"}, 
{813,"fEM_B8UL06RDU\0"}, 
{814,"fEM_A9UZ03RDU\0"}, 
{815,"fEM_A9UZ04RDU\0"}, 
{816,"fEM_A9UZ05RDU\0"}, 
{817,"fEM_R4UZ04RDU\0"}, 
{818,"fEM_R4UZ03RDU\0"}, 
{819,"fEM_R4UZ05RDU\0"}, 
{820,"fEM_A5UZ03RDU\0"}, 
{821,"fEM_A5UZ04RDU\0"}, 
{822,"fEM_A5UZ05RDU\0"}, 
{823,"fEM_A4UZ03RDU\0"}, 
{824,"fEM_A4UZ04RDU\0"}, 
{825,"fEM_A4UZ05RDU\0"}, 
{826,"fEM_A6UZ03RDU\0"}, 
{827,"fEM_A6UZ04RDU\0"}, 
{828,"fEM_A6UZ05RDU\0"}, 
{829,"fEM_R1UZ03RDU\0"}, 
{830,"fEM_R1UZ04RDU\0"}, 
{831,"fEM_R1UZ05RDU\0"}, 
{832,"fEM_R0UL04RDU\0"}, 
{833,"fEM_R0UL06RDU\0"}, 
{834,"fEM_R0UL03RDU\0"}, 
{835,"fEM_R0UL17RDU\0"}, 
{836,"fEM_R0UL19RDU\0"}, 
{837,"fEM_R0UL07RDU\0"}, 
{838,"fEM_R0UL18RDU\0"}, 
{839,"fEM_R0UL16RDU\0"}, 
{840,"fEM_R0UL02RDU\0"}, 
{841,"fEM_R0UN08RDU\0"}, 
{842,"fEM_R0UN07RDU\0"}, 
{843,"fEM_R0UN06RDU\0"}, 
{844,"fEM_R0UN05RDU\0"}, 
{845,"fEM_R0UN04RDU\0"}, 
{846,"fEM_R0UN03RDU\0"}, 
{847,"fEM_R0UN02RDU\0"}, 
{848,"fEM_R0UN01RDU\0"}, 
{849,"fEM_A2UC82RDU\0"}, 
{850,"fEM_A2UC83RDU\0"}, 
{851,"fEM_A1UC83RDU\0"}, 
{852,"fEM_A2UC81RDU\0"}, 
{853,"fEM_A1UC81RDU\0"}, 
{854,"fEM_A1UC82RDU\0"}, 
{855,"fEM_A2UL83RDU\0"}, 
{856,"fEM_A3UC81RDU\0"}, 
{857,"fEM_A3UC82RDU\0"}, 
{858,"fEM_R0UN80RDU\0"}, 
{859,"iEM_A2UV01IDU\0"}, 
{860,"iEM_A2UV02IDU\0"}, 
{861,"iEM_A1UV01IDU\0"}, 
{862,"iEM_A1UV02IDU\0"}, 
{863,"iEM_A1UV03IDU\0"}, 
{864,"iEM_A3UV01IDU\0"}, 
{865,"iEM_A3UV02IDU\0"}, 
{866,"lEM_R0MD01LC1\0"}, 
{867,"fEM_A3UC09RDU\0"}, 
{868,"fEM_A2UC02RDU\0"}, 
{869,"fEM_A1UC02RDU\0"}, 
{870,"fEM_A3UC02RDU\0"}, 
{871,"fEM_R0UL21RDU\0"}, 
{872,"fEM_R0UN09RDU\0"}, 
{873,"fEM_R0UN11RDU\0"}, 
{874,"fEM_R0UN12RDU\0"}, 
{875,"fEM_R0UN13RDU\0"}, 
{876,"fEM_R0UN14RDU\0"}, 
{877,"fEM_R0UN16RDU\0"}, 
{878,"fEM_R0UN17RDU\0"}, 
{879,"fEM_R0UN18RDU\0"}, 
{880,"fEM_R0UN19RDU\0"}, 
{881,"fEM_R0UN70LDU\0"}, 
{882,"fEM_R0UN71LDU\0"}, 
{883,"fEM_R0UN72LDU\0"}, 
{884,"fEM_R0UN73LDU\0"}, 
{885,"fEM_R0UN74LDU\0"}, 
{886,"fEM_R0UN75LDU\0"}, 
{887,"fEM_R0UN80LDU\0"}, 
{888,"fEM_R0UN81LDU\0"}, 
{889,"fEM_R0UN82LDU\0"}, 
{890,"fEM_R0UN83LDU\0"}, 
{891,"fEM_R0UN84LDU\0"}, 
{892,"fEM_R0UN85LDU\0"}, 
{893,"fEM_R0UT20RDU\0"}, 
{894,"fEM_R0UN25RDU\0"}, 
{895,"fEM_R0UN15RDU\0"}, 
{896,"fEM_R0UN26RDU\0"}, 
{897,"fEM_R0UN27RDU\0"}, 
{898,"fEM_R0UN24RDU\0"}, 
{899,"fEM_R0UL25RDU\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_DU[]={  // 
	{&B1MD12LP1,1,0},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
	{&B1MD11LP1,1,1},	//( - , DU) Кнопка ПУСК ББ2
	{&R0MW17LP1,1,2},	//( - , DU) Переключатель АВТ/Р
	{&A1MD11LP1,1,3},	//( - , DU) Кнопка ПУСК ББ1
	{&A1MD12LP1,1,4},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
	{&R0MD33LP1,1,5},	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
	{&A3MD11LP1,1,6},	//( - , DU) Кнопка ПУСК ИС1
	{&A3MD12LP1,1,7},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
	{&B3MD11LP1,1,8},	//( - , DU) Кнопка ПУСК ИС2
	{&B3MD12LP1,1,9},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
	{&R0MD34LP1,1,10},	//( - , DU) Кнопка КВИТИРОВАТЬ
	{&A2MD12LP1,1,11},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
	{&A2MD11LP1,1,12},	//( - , DU) Кнопка ПУСК РБ1
	{&B2MD12LP1,1,13},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
	{&B2MD11LP1,1,14},	//( - , DU) Кнопка ПУСК РБ2
	{&R0MD11LP2,1,15},	//( - , DU) Кнопка Пуск проверки схем сброса
	{&C1MD31LP2,1,16},	//( - , DU) Кнопка СБРОС ББ
	{&C1MD31LP1,1,17},	//( - , DU) Кнопка СБРОС ББ
	{&A1MC01LC2,1,18},	//( - , DU) Настроить энкодер ББ1
	{&A1MC01LC1,1,19},	//( - , DU) Настроить энкодер ББ1
	{&B1MC01LC2,1,20},	//( - , DU) Настроить энкодер ББ2
	{&B1MC01LC1,1,21},	//( - , DU) Настроить энкодер ББ2
	{&B2MC01LC1,1,22},	//( - , DU) Настроить энкодер РБ2
	{&B2MC01LC2,1,23},	//( - , DU) Настроить энкодер РБ2
	{&A2MC01LC1,1,24},	//( - , DU) Настроить энкодер РБ1
	{&A2MC01LC2,1,25},	//( - , DU) Настроить энкодер РБ1
	{&B3MC01LC1,1,26},	//( - , DU) Настроить энкодер ИС2
	{&B3MC01LC2,1,27},	//( - , DU) Настроить энкодер ИС2
	{&A3MC01LC1,1,28},	//( - , DU) Настроить энкодер ИС1
	{&A3MC01LC2,1,29},	//( - , DU) Настроить энкодер ИС1
	{&B8MC01LC1,1,30},	//( - , DU) Настроить энкодер АЗ2
	{&B8MC01LC2,1,31},	//( - , DU) Настроить энкодер АЗ2
	{&A8MC01LC1,1,32},	//( - , DU) Настроить энкодер ДС2
	{&A8MC01LC2,1,33},	//( - , DU) Настроить энкодер ДС2
	{&C2MD31LP1,1,34},	//( - , DU) Кнопка СБРОС РБ
	{&R0MD11LP1,1,35},	//( - , DU) Кнопка ПУСК
	{&R4MD21LP2,1,36},	//( - , DU) Кнопка НАЗАД  (тележки)
	{&R4MD31LP2,1,37},	//( - , DU) Кнопка СТОП  (тележки)
	{&R4MD11LP2,1,38},	//( - , DU) Кнопка ВПЕРЁД  (тележки)
	{&R0MD31LP1,1,39},	//( - , DU) Кнопка СТОП
	{&R0MD32LP1,1,40},	//( - , DU) Кнопка СПУСК
	{&R0MW13LP2,1,41},	//( - , DU) Переключатель СЕТЬ
	{&R0NE01LDU,1,42},	//( - , DU) Потеря связи с БАЗ1
	{&R0NE02LDU,1,43},	//( - , DU) Потеря связи с БАЗ2
	{&R0NE08LDU,1,44},	//( - , DU) Потеря связи с ОПУ
	{&lEM_R0MD01LC1,1,45},	//( - , DU) Ручное управление ОРР
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
	{&A3VZ15LZ1,1,21},	//( - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{&A3VZ13LZ1,1,22},	//( - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{&A3VZ13LZ2,1,23},	//( - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{&R0AD14LZ2,1,24},	//( - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
	{&R0AD14LZ1,1,25},	//( - K20VDSR, DU) Имитация срабатывания АЗ от II УР
	{&A1AB19LDU,1,26},	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
	{&A1VN71LZ2,1,27},	//( - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{&A1VN71LZ1,1,28},	//( - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{&A4IS10LDU,1,29},	//( - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
	{&A3IS35LDU,1,30},	//( - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
	{&A3IS33LDU,1,31},	//( - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
	{&A3IS31LDU,1,32},	//( - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
	{&A2IS33LDU,1,33},	//( - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
	{&R0VZ71LDU,1,34},	//( - , DU) Обобщенный сигнал АЗ
	{&B7AZ03LDU,1,35},	//( - , DU) Несанкционированное включение обдува АЗ2
	{&A7AZ03LDU,1,36},	//( - , DU) Несанкционированное включение обдува АЗ1
	{&B7AS31LDU,1,37},	//( - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
	{&A7AS31LDU,1,38},	//( - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
	{&B2VS21LDU,1,39},	//( - , DU) Движение РБ2 в сторону НУ
	{&B2VS11LDU,1,40},	//( - , DU) Движение РБ2 в сторону ВУ
	{&R0VP73LDU,1,41},	//( - , DU) ПС давления для РУ
	{&R0IS02LDU,1,42},	//( - K30VDSR, DU) Разрешение ввода от имитатора
	{&R0IS01LDU,1,43},	//( - K29VDSR, DU) Признак работы с имитатором
	{&R0VX01LDU,1,44},	//( - , DU) ДО ИМПУЛЬСА
	{&B1AD31LDU,1,45},	//( - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
	{&A1AD31LDU,1,46},	//( - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
	{&B2AD31LDU,1,47},	//( - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
	{&A2AD31LDU,1,48},	//( - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
	{&B3AB20LDU,1,49},	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
	{&B3AB18LDU,1,50},	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
	{&B3AB17LDU,1,51},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
	{&B3AB16LDU,1,52},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
	{&B3AB14LDU,1,53},	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
	{&B3AB12LDU,1,54},	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{&B3AB11LDU,1,55},	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
	{&B3AB10LDU,1,56},	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
	{&B3AB09LDU,1,57},	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
	{&B3AB06LDU,1,58},	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
	{&B3AB05LDU,1,59},	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
	{&B3AB08LDU,1,60},	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
	{&B3AB07LDU,1,61},	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
	{&B3AZ03LDU,1,62},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
	{&B3VS22LDU,1,63},	//( - , DU) Движение ИС2 в сторону НУ
	{&B3AB01LDU,1,64},	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
	{&B3AB02LDU,1,65},	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
	{&B3AB04LDU,1,66},	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
	{&B3VS12LDU,1,67},	//( - , DU) Движение ИС2 в сторону ВУ
	{&A3AB20LDU,1,68},	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
	{&A3AB18LDU,1,69},	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
	{&A3AB17LDU,1,70},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
	{&B9IS11LDU,1,71},	//( - K25VDSR, DU) Приход на ВУ НИ ДС2
	{&A9IS11LDU,1,72},	//( - K23VDSR, DU) Приход на ВУ НИ ДС1
	{&B4VS22LDU,1,73},	//( - , DU) Движение НИ2 в сторону НУ
	{&B4VS12LDU,1,74},	//( - , DU) Движение НИ2 в сторону ВУ
	{&A4VS22LDU,1,75},	//( - , DU) Движение НИ1 в сторону НУ
	{&A4VS12LDU,1,76},	//( - , DU) Движение НИ1 в сторону ВУ
	{&B3IS11LDU,1,77},	//( - K03VDSR, DU) Приход на ВУ ИС2
	{&R0AD14LDU,1,78},	//( - , DU) Имитация срабатывания верхней АС II УР
	{&R0AB04LDU,1,79},	//( - , DU) Нарушение времени срабатывания верхней АС II УР
	{&R0AB06LDU,1,80},	//( - , DU) Нарушение времени задержки от ВУ РБ
	{&R0AB02LDU,1,81},	//( - , DU) Нарушение времени задержки ИНИ
	{&R0VX03LDU,1,82},	//( - , DU) Готовность 2 мин
	{&A1IS11LDU,1,83},	//( - K08VDSR, DU) Приход на ВУ ББ1
	{&B1IS11LDU,1,84},	//( - K08VDSR, DU) Приход на ВУ ББ2
	{&TestDiagnDU,1,85},	//( - , DU) Неисправность от
	{&B3AB13LDU,1,86},	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
	{&A3AB13LDU,1,87},	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
	{&R3VS12LDU,1,88},	//( - , DU) Движение гомогенных дверей к открыты
	{&R3VS22LDU,1,89},	//( - , DU) Движение гомогенных дверей к закрыты
	{&R5VS12LDU,1,90},	//( - , DU) Движение ворот отстойной зоны к открыты
	{&R5VS22LDU,1,91},	//( - , DU) Движение ворот отстойной зоны к закрыты
	{&R5IS21LDU,1,92},	//( - K26VDSR, DU) Приход на НУ ворот отстойной зоны
	{&B3AB15LDU,1,93},	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
	{&B3EE03LDU,1,94},	//( - , DU) ВПИС ИС2
	{&A3EE03LDU,1,95},	//( - , DU) ВПИС ИС1
	{&B3AB19LDU,1,96},	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
	{&A3AB19LDU,1,97},	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
	{&R0VL23LDU,1,98},	//( - , DU) Конец программы 20мин
	{&R0VL22LDU,1,99},	//( - , DU) Конец программы 200сек
	{&B8IS21LDU,1,100},	//( - K20VDSR, DU) Приход на НУ1 АЗ2
	{&B8IS12LDU,1,101},	//( - K21VDSR, DU) Приход на ВУ2 АЗ2
	{&R0EE02LDU,1,102},	//( - , DU) Питание  АКНП  отключить
	{&B0VS11LDU,1,103},	//( - , DU) АЗ2 готова к работе
	{&A0VS11LDU,1,104},	//( - , DU) АЗ1 готова к работе
	{&B0VN01LDU,1,105},	//( - , DU) Каналы АЗ2 проверены
	{&A0VN01LDU,1,106},	//( - , DU) Каналы АЗ1 проверены
	{&B0VP01LDU,1,107},	//( - , DU) Давление в системы АЗ2 подано
	{&A0VP01LDU,1,108},	//( - , DU) Давление в системы АЗ1 подано
	{&B0VE01LDU,1,109},	//( - , DU) Напряжение в системы АЗ2 подано
	{&A0VE01LDU,1,110},	//( - , DU) Напряжение в системы АЗ1 подано
	{&A3VP82LDU,1,111},	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
	{&B3VP82LDU,1,112},	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
	{&B3VP52LDU,1,113},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
	{&A3VP42LDU,1,114},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
	{&A3VP52LDU,1,115},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
	{&B3VP42LDU,1,116},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
	{&R0AB13LDU,1,117},	//( - , DU) Ошибка в заданной координате  АЗ2
	{&R0AB12LDU,1,118},	//( - , DU) Ошибка в заданной координате  ИС2
	{&R0AB11LDU,1,119},	//( - , DU) Ошибка в заданной координате  ИС1
	{&R0AB10LDU,1,120},	//( - , DU) Ошибка в заданной координате ББ2
	{&R0AB09LDU,1,121},	//( - , DU) Ошибка в заданной координате ББ1
	{&R0AB08LDU,1,122},	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
	{&B6AB05LDU,1,123},	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
	{&R0VS11LDU,1,124},	//( - , DU) РУ не готова к работе
	{&R0AB07LDU,1,125},	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
	{&R0EE03LDU,1,126},	//( - , DU) ВПИС ИС
	{&R0VX02LDU,1,127},	//( - , DU) Импульс разрешен
	{&B2AB15LDU,1,128},	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{&A2AB15LDU,1,129},	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{&R0AB05LDU,1,130},	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
	{&R0AB03LDU,1,131},	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
	{&R3IS21LDU,1,132},	//( - K18VDSR, DU) Приход на НУ гомогенных дверей
	{&R3IS11LDU,1,133},	//( - K17VDSR, DU) Приход на ВУ гомогенных дверей
	{&B4IS10LDU,1,134},	//( - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
	{&B3IS35LDU,1,135},	//( - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
	{&B3IS33LDU,1,136},	//( - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
	{&B3IS31LDU,1,137},	//( - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
	{&B2IS33LDU,1,138},	//( - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
	{&A3VZ15LZ2,1,139},	//( - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{&R0AB19LDU,1,140},	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
	{&R0AB20LDU,1,141},	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
	{&A3AB15LDU,1,142},	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
	{&R0AB18LDU,1,143},	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
	{&R0AB17LDU,1,144},	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
	{&R0AB16LDU,1,145},	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
	{&B1AB19LDU,1,146},	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
	{&A4ZAV,1,147},	//( - , DU) 
	{&A6ZAV,1,148},	//( - , DU) 
	{&R2ZAV,1,149},	//( - , DU) 
	{&A5ZAV,1,150},	//( - , DU) 
	{&B8ZAV,1,151},	//( - , DU) 
	{&A2ZAV,1,152},	//( - , DU) Завершение РБ1,2
	{&A8ZAV,1,153},	//( - , DU) 
	{&A9ZAV,1,154},	//( - , DU) Завершение НИ ДС1(2)
	{&R4ABL,1,155},	//( - , DU) Блокировка тележки -
	{&A4UP,1,156},	//( - , DU) 
	{&A4DW,1,157},	//( - , DU) 
	{&R0AB14LDU,1,158},	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
	{&R0AB15LDU,1,159},	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
	{&A3IS12LDU,1,160},	//( - , DU) Приход на ВУ штока ИС1
	{&B3IS12LDU,1,161},	//( - , DU) Приход на ВУ штока ИС2
	{&A1ZAV,1,162},	//( - , DU) 
	{&A3ZAV,1,163},	//( - , DU) 
	{&B1IS12LDU,1,164},	//( - K07VDSR, DU) Магнит ББ2 зацеплен
	{&A2IS12LDU,1,165},	//( - K10VDSR, DU) Магнит РБ1 зацеплен
	{&A1IS12LDU,1,166},	//( - K07VDSR, DU) Магнит ББ1 зацеплен
	{&B5AB04LDU,1,167},	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
	{&A5AB04LDU,1,168},	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
	{&B4AB02LDU,1,169},	//( - , DU) Блокировка движения НИ2 - Нет перемещения
	{&B4AB01LDU,1,170},	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
	{&B4AZ03LDU,1,171},	//( - , DU) Несанкционированное перемещение НИ2
	{&A4AB02LDU,1,172},	//( - , DU) Блокировка движения НИ1 - Нет перемещения
	{&A4AB01LDU,1,173},	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
	{&A4AZ03LDU,1,174},	//( - , DU) Несанкционированное перемещение НИ1
	{&B4IS21LDU,1,175},	//( - K32VDSR, DU) Приход на НУ НИ2
	{&A4IS21LDU,1,176},	//( - K15VDSR, DU) Приход на НУ НИ1
	{&B5AB02LDU,1,177},	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
	{&B5AB01LDU,1,178},	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
	{&B5AZ03LDU,1,179},	//( - , DU) Несанкционированное перемещение НЛ2
	{&A5AB02LDU,1,180},	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
	{&A5AB01LDU,1,181},	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
	{&A5AZ03LDU,1,182},	//( - , DU) Несанкционированное перемещение НЛ1
	{&B5IS21LDU,1,183},	//( - K16VDSR, DU) Приход на НУ НЛ2
	{&B5IS11LDU,1,184},	//( - K15VDSR, DU) Приход на ВУ НЛ2
	{&A5IS21LDU,1,185},	//( - K12VDSR, DU) Приход на НУ НЛ1
	{&A5IS11LDU,1,186},	//( - K11VDSR, DU) Приход на ВУ НЛ1
	{&B5VS12LDU,1,187},	//( - K14VDSR, DU) Движение НЛ2 в сторону ВУ
	{&B5VS22LDU,1,188},	//( - K15VDSR, DU) Движение НЛ2 в сторону НУ
	{&A5VS12LDU,1,189},	//( - K11VDSR, DU) Движение НЛ1 в сторону ВУ
	{&A5VS22LDU,1,190},	//( - K12VDSR, DU) Движение НЛ1 в сторону НУ
	{&R4AD20LDU,1,191},	//( - K14FDSR, DU) Перемещение тележки назад
	{&R4AB18LDU,1,192},	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
	{&R4AB17LDU,1,193},	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
	{&R4AB16LDU,1,194},	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
	{&R5IS11LDU,1,195},	//( - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
	{&A8VS12LDU,1,196},	//( - , DU) Движение ДС2 в сторону ВУ
	{&B8AB02LDU,1,197},	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
	{&B8AB14LDU,1,198},	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
	{&B8AB13LDU,1,199},	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
	{&B8AB12LDU,1,200},	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
	{&B8AB11LDU,1,201},	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
	{&B8AB10LDU,1,202},	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
	{&B8AB09LDU,1,203},	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
	{&B8AB08LDU,1,204},	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
	{&B8AB04LDU,1,205},	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
	{&B8AB01LDU,1,206},	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
	{&B8IS11LDU,1,207},	//( - K19VDSR, DU) Приход на ВУ1 АЗ2
	{&B8AZ03LDU,1,208},	//( - , DU) Несанкционированное перемещение АЗ2
	{&B8VS22LDU,1,209},	//( - , DU) Движение АЗ2 в сторону НУ
	{&B8AB05LDU,1,210},	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
	{&B8AB07LDU,1,211},	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
	{&B8AB06LDU,1,212},	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
	{&B8VS12LDU,1,213},	//( - , DU) Движение АЗ2 в сторону ВУ
	{&A6AB05LDU,1,214},	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
	{&B6AB09LDU,1,215},	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
	{&B6AB08LDU,1,216},	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
	{&B6AB07LDU,1,217},	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
	{&B6AB06LDU,1,218},	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
	{&A6AB09LDU,1,219},	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
	{&A6AB08LDU,1,220},	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
	{&A6AB07LDU,1,221},	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
	{&A6AB06LDU,1,222},	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
	{&R4IS11LDU,1,223},	//( - K05VDSR, DU) Приход на ВУ1 тележки
	{&B2IS12LDU,1,224},	//( - K10VDSR, DU) Магнит РБ2 зацеплен
	{&B6AZ03LDU,1,225},	//( - , DU) Несанкционированное перемещение БЗ2
	{&A6AB02LDU,1,226},	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
	{&A6AB01LDU,1,227},	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
	{&A6AZ03LDU,1,228},	//( - , DU) Несанкционированное перемещение БЗ1
	{&B6VS12LDU,1,229},	//( - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
	{&B6VS22LDU,1,230},	//( - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
	{&A6VS12LDU,1,231},	//( - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
	{&A6VS22LDU,1,232},	//( - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
	{&B6IS21LDU,1,233},	//( - K14VDSR, DU) Приход на НУ БЗ2
	{&B6IS11LDU,1,234},	//( - K13VDSR, DU) Приход на ВУ БЗ2
	{&A6IS21LDU,1,235},	//( - K10VDSR, DU) Приход на НУ БЗ1
	{&A6IS11LDU,1,236},	//( - K09VDSR, DU) Приход на ВУ БЗ1
	{&R0ES01LDU,1,237},	//( - , DU) ОРР не в исходном состоянии
	{&B3IS21LDU,1,238},	//( - K13VDSR, DU) Приход на НУ ИС2
	{&B2IS21LDU,1,239},	//( - K12VDSR, DU) Приход на НУ РБ2-СС
	{&B1IS21LDU,1,240},	//( - K09VDSR, DU) Приход на НУ ББ2
	{&A3IS21LDU,1,241},	//( - K13VDSR, DU) Приход на НУ ИС1
	{&A2IS21LDU,1,242},	//( - K12VDSR, DU) Приход на НУ РБ1-СС
	{&A1IS21LDU,1,243},	//( - K09VDSR, DU) Приход на НУ ББ1
	{&R4AB15LDU,1,244},	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
	{&R4AB14LDU,1,245},	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
	{&R4AB13LDU,1,246},	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
	{&B4IS11LDU,1,247},	//( - K31VDSR, DU) Приход на ВУ НИ2
	{&A4IS11LDU,1,248},	//( - K14VDSR, DU) Приход на ВУ НИ1
	{&R4AB12LDU,1,249},	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
	{&R4AB11LDU,1,250},	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
	{&R4AB10LDU,1,251},	//( - , DU) Блокировка тележки - не открыта биологическая защита
	{&R4AB09LDU,1,252},	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
	{&R4AB08LDU,1,253},	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
	{&R4AB07LDU,1,254},	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
	{&R4AB06LDU,1,255},	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
	{&R4AB05LDU,1,256},	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
	{&R4AB04LDU,1,257},	//( - , DU) Блокировка движения тележки - Превышение времени движения
	{&R2IS21LDU,1,258},	//( - K30VDSR, DU) Приход на НУ МДЗ2
	{&R1IS21LDU,1,259},	//( - K28VDSR, DU) Приход на НУ МДЗ1
	{&B6AB01LDU,1,260},	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
	{&B6AB02LDU,1,261},	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
	{&A6AB04LDU,1,262},	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
	{&B6AB04LDU,1,263},	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
	{&R4AB01LDU,1,264},	//( - , DU) Блокировка движения тележки - АНИ не установлен
	{&R8IS11LDU,1,265},	//( - K14VDSR, DU) Аварийный НИ установлен
	{&R4AB02LDU,1,266},	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
	{&R4IS21LDU,1,267},	//( - K07VDSR, DU) Приход на НУ1 тележки
	{&R4IS22LDU,1,268},	//( - K08VDSR, DU) Приход на НУ2 тележки
	{&R4IS12LDU,1,269},	//( - K06VDSR, DU) Приход на ВУ2 тележки
	{&R4VS22LDU,1,270},	//( - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
	{&R4VS12LDU,1,271},	//( - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
	{&R4AZ03LDU,1,272},	//( - , DU) Несанкционированное перемещение тележки
	{&R4AB03LDU,1,273},	//( - , DU) Блокировка движения тележки - Самоход любого механизма
	{&B1VS22LDU,1,274},	//( - , DU) Движение ББ2 в сторону НУ
	{&B1AB01LDU,1,275},	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
	{&B1AB02LDU,1,276},	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
	{&B1AB04LDU,1,277},	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
	{&B1VS12LDU,1,278},	//( - , DU) Движение ББ2 в сторону ВУ
	{&A1AB18LDU,1,279},	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
	{&A1AB17LDU,1,280},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
	{&A1AB16LDU,1,281},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
	{&A1AB14LDU,1,282},	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
	{&A1AB13LDU,1,283},	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
	{&A1AB12LDU,1,284},	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&A1AB11LDU,1,285},	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
	{&A1AB10LDU,1,286},	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
	{&A1AB09LDU,1,287},	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
	{&A1AB06LDU,1,288},	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
	{&A1AB05LDU,1,289},	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
	{&A1AB08LDU,1,290},	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
	{&A1AB07LDU,1,291},	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
	{&A1AZ03LDU,1,292},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
	{&A1VS22LDU,1,293},	//( - , DU) Движение ББ1 в сторону НУ
	{&A1AB01LDU,1,294},	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
	{&A1AB02LDU,1,295},	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
	{&A1AB04LDU,1,296},	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
	{&A1VS12LDU,1,297},	//( - , DU) Движение ББ1 в сторону ВУ
	{&R2IS11LDU,1,298},	//( - K29VDSR, DU) Приход на ВУ МДЗ2
	{&R1VS12LDU,1,299},	//( - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
	{&R2VS12LDU,1,300},	//( - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
	{&R2VS22LDU,1,301},	//( - K09VDSR, DU) Движение МДЗ2 в сторону НУ
	{&R1VS22LDU,1,302},	//( - K06VDSR, DU) Движение МДЗ1 в сторону НУ
	{&A3AB16LDU,1,303},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
	{&A3AB14LDU,1,304},	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
	{&A3AB12LDU,1,305},	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&A3AB11LDU,1,306},	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
	{&A3AB10LDU,1,307},	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
	{&A3AB09LDU,1,308},	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
	{&A3AB06LDU,1,309},	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
	{&A3AB05LDU,1,310},	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
	{&A3AB08LDU,1,311},	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
	{&A3AB07LDU,1,312},	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
	{&A3AZ03LDU,1,313},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
	{&A3VS22LDU,1,314},	//( - , DU) Движение ИС1 в сторону НУ
	{&A3AB01LDU,1,315},	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
	{&A3AB02LDU,1,316},	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
	{&A3AB04LDU,1,317},	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
	{&B1AZ03LDU,1,318},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
	{&B1AB07LDU,1,319},	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
	{&B1AB08LDU,1,320},	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
	{&B1AB05LDU,1,321},	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
	{&B1AB06LDU,1,322},	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
	{&B1AB09LDU,1,323},	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
	{&B1AB10LDU,1,324},	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
	{&B1AB11LDU,1,325},	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
	{&B1AB12LDU,1,326},	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&B1AB13LDU,1,327},	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
	{&B1AB14LDU,1,328},	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
	{&B1AB16LDU,1,329},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
	{&B1AB17LDU,1,330},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
	{&B1AB18LDU,1,331},	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
	{&A3VS12LDU,1,332},	//( - , DU) Движение ИС1 в сторону ВУ
	{&A2AB11LDU,1,333},	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
	{&A2AB10LDU,1,334},	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
	{&A2AB09LDU,1,335},	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
	{&A2AB06LDU,1,336},	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
	{&A2AB05LDU,1,337},	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
	{&A2AB08LDU,1,338},	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
	{&A2AB07LDU,1,339},	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
	{&A2AZ03LDU,1,340},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
	{&A2VS21LDU,1,341},	//( - , DU) Движение РБ1 в сторону НУ
	{&A2AB01LDU,1,342},	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
	{&A2AB02LDU,1,343},	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
	{&A2AB04LDU,1,344},	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
	{&A2VS11LDU,1,345},	//( - , DU) Движение РБ1 в сторону ВУ
	{&A8AB01LDU,1,346},	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
	{&A8AB02LDU,1,347},	//( - , DU) Блокировка движения ДС2- АНИ не установлен
	{&A8AB14LDU,1,348},	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
	{&A8AB13LDU,1,349},	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
	{&A8AB12LDU,1,350},	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
	{&A8AB11LDU,1,351},	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
	{&A8AB10LDU,1,352},	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
	{&A8AB09LDU,1,353},	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
	{&A8AB08LDU,1,354},	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
	{&A8IS22LDU,1,355},	//( - K31VDSR, DU) Приход на механический НУ ДС2
	{&A8AB04LDU,1,356},	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
	{&A8IS12LDU,1,357},	//( - K30VDSR, DU) Приход на механический ВУ ДС2
	{&B8IS22LDU,1,358},	//( - K22VDSR, DU) Приход на НУ2 АЗ2
	{&A8AZ03LDU,1,359},	//( - , DU) Несанкционированное перемещение ДС2
	{&A8VS22LDU,1,360},	//( - , DU) Движение ДС2 в сторону НУ
	{&A8AB05LDU,1,361},	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
	{&A8AB07LDU,1,362},	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
	{&A8AB06LDU,1,363},	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
	{&R1IS11LDU,1,364},	//( - K27VDSR, DU) Приход на ВУ МДЗ1
	{&R2AB04LDU,1,365},	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
	{&R1AB04LDU,1,366},	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
	{&R2AB02LDU,1,367},	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
	{&R2AB01LDU,1,368},	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
	{&R2AZ03LDU,1,369},	//( - , DU) Несанкционированное перемещение МДЗ2
	{&R1AB02LDU,1,370},	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
	{&R1AB01LDU,1,371},	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
	{&R1AZ03LDU,1,372},	//( - , DU) Несанкционированное перемещение МДЗ1
	{&B2AB17LDU,1,373},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
	{&B2AB16LDU,1,374},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
	{&B2AB14LDU,1,375},	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
	{&B2AB13LDU,1,376},	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
	{&B2AB12LDU,1,377},	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{&B2AB11LDU,1,378},	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
	{&B2AB10LDU,1,379},	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
	{&A2AB12LDU,1,380},	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&A2AB13LDU,1,381},	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
	{&A2AB14LDU,1,382},	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
	{&A2AB16LDU,1,383},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
	{&A2AB17LDU,1,384},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
	{&B2AB04LDU,1,385},	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
	{&B2AB02LDU,1,386},	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
	{&B2AB01LDU,1,387},	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
	{&B2AZ03LDU,1,388},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
	{&B2AB07LDU,1,389},	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
	{&B2AB08LDU,1,390},	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
	{&B2AB05LDU,1,391},	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
	{&B2AB06LDU,1,392},	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
	{&B2AB09LDU,1,393},	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DU[]={  // 
	{&R0VX08IDU,3,0},	//( - , DU) Индикация Режим
	{&R0VL01RDU,8,1},	//( - , DU) Индикация Время задержки
	{&B2VS01IDU,3,3},	//( - , DU) Готовность к управлению РБ2
	{&R0VL01IDU,3,4},	//( - , DU) До импульса минут
	{&B3CV02RDU,8,5},	//( - , DU) Заданная скорость перемещения ИС2
	{&R1VS01IDU,3,7},	//( - , DU) Готовность к управлению МДЗ1
	{&R2VS01IDU,3,8},	//( - , DU) Готовность к управлению МДЗ2
	{&R4VS01IDU,3,9},	//( - , DU) Готовность к управлению тележкой реактора
	{&A6VS01IDU,3,10},	//( - , DU) Готовность к управлению БЗ1
	{&B5VS01IDU,3,11},	//( - , DU) Готовность к управлению НЛ2
	{&A5VS01IDU,3,12},	//( - , DU) Готовность к управлению НЛ1
	{&B4VS01IDU,3,13},	//( - , DU) Готовность к управлению НИ2
	{&A4VS01IDU,3,14},	//( - , DU) Готовность к управлению НИ1
	{&A2VS01IDU,3,15},	//( - , DU) Готовность к управлению РБ1
	{&B3VS01IDU,3,16},	//( - , DU) Готовность к управлению ИС2
	{&R0VL11IDU,3,17},	//( - , DU) До импульса секунд
	{&R0VL06RDU,8,18},	//( - , DU) Индикация (Время задержки от ВУ РБ)
	{&R0VL02RDU,8,20},	//( - , DU) Индикация (Время задержки ИНИ)
	{&R0VL04RDU,8,22},	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
	{&R0VL03RDU,8,24},	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
	{&R0VL05RDU,8,26},	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
	{&R0VL21IDU,3,28},	//( - , DU) Декатрон
	{&R0VS21IDU,3,29},	//( - , DU) Индикация ВИД ПРОВЕРКИ
	{&A1VS01IDU,3,30},	//( - , DU) Готовность к управлению ББ1
	{&B1VS01IDU,3,31},	//( - , DU) Готовность к управлению ББ2
	{&A3VS01IDU,3,32},	//( - , DU) Готовность к управлению ИС1
	{&A1VC01RDU,8,33},	//( - , DU) Координата ББ1, мм
	{&A8VC01RDU,8,35},	//( - , DU) Координата ДС2, мм
	{&B3VC01RDU,8,37},	//( - , DU) Координата ИС2, мм
	{&B1VC01RDU,8,39},	//( - , DU) Координата ББ2, мм
	{&B3CV01RDU,8,41},	//( - , DU) Измеренная скорость перемещения ИС2
	{&TTLDU,3,43},	//( - , DU) ttl
	{&R3VS01IDU,3,44},	//( - , DU) Готовность к управлению гомогенных дверей
	{&R5VS01IDU,3,45},	//( - , DU) Готовность к управлению ворот отстойной зоны
	{&R0CN95LDU,3,46},	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
	{&B8VC01RDU,8,47},	//( - , DU, MDuBz1, MDuBz2) Координата АЗ2, мм
	{&B2VC01RDU,8,49},	//( - , DU) Координата РБ2, мм
	{&A2VC01RDU,8,51},	//( - , DU) Координата РБ1, мм
	{&A3VC01RDU,8,53},	//( - , DU) Координата ИС1, мм
	{&A3CP02RDU,8,55},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
	{&B3CP02RDU,8,57},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
	{&A8VS01IDU,3,59},	//( - , DU) Готовность к управлению ДС2
	{&B8VS01IDU,3,60},	//( - , DU) Готовность к управлению АЗ2
	{&B6VS01IDU,3,61},	//( - , DU) Готовность к управлению БЗ2
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
	{&B1VP41LZ1,1,10},	//( - , Baz1, SBz1DU) Давление СБРОС ББ2 ниже АС
	{&A1VP41LZ1,1,11},	//( - , Baz1, SBz1DU) Давление СБРОС ББ1 ниже АС
	{&A0VT71LZ1,1,12},	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
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
	{&B8VC01RDU,8,0},	//( - , SBz1DU, MBz1A1, MBz1A2, MBz1A3, MBz1A4) Координата АЗ2, мм
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
	{&B1VP41LZ2,1,10},	//( - , Baz2, SBz2DU) Давление СБРОС ББ2 ниже АС
	{&A1VP41LZ2,1,11},	//( - , Baz2, SBz2DU) Давление СБРОС ББ1 ниже АС
	{&A0VT71LZ2,1,12},	//( - , Baz2, SBz2DU) АС по температуре в АЗ1
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
	{&B8VC01RDU,8,0},	//( - , SBz2DU, MBz2A1, MBz2A2, MBz2A3, MBz2A4) Координата АЗ2, мм
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
static ModbusDevice modbuses[]={
	{0,5002,&coil_DU[0],&di_DU[0],&ir_DU[0],&hr_DU[0],NULL,NULL,NULL,0},	 //Общий слэйв
	{0,5006,&coil_DiagnDU[0],&di_DiagnDU[0],&ir_DiagnDU[0],&hr_DiagnDU[0],NULL,NULL,NULL,0},	 //Диагностика DU
	{1,5010,&coil_MDuBz1[0],&di_MDuBz1[0],&ir_MDuBz1[0],&hr_MDuBz1[0],NULL,MDuBz1_ip1,MDuBz1_ip2,100},	 //Мастер ДУ в Баз1
	{1,5009,&coil_MDuBz2[0],&di_MDuBz2[0],&ir_MDuBz2[0],&hr_MDuBz2[0],NULL,MDuBz2_ip1,MDuBz2_ip2,100},	 //Мастер ДУ в Баз2
	{1,5005,&coil_MDuS[0],&di_MDuS[0],&ir_MDuS[0],&hr_MDuS[0],NULL,MDuS_ip1,MDuS_ip2,10},	 //Мастер ДУ в SCM

	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},};
#pragma pop
#include <fp8/drivers/vencf8l.h>
static char buf_VENCF[84];	//VENCF
static vencf8_inipar ini_VENCF={0xc2,0xff,0,0x6,0x96,};
#pragma pack(push,1)
static table_drv table_VENCF={0,0,&ini_VENCF,buf_VENCF,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VENCF[]={
	{&venc08,5,75},
	{&venc07,5,70},
	{&venc06,5,65},
	{&venc01,5,40},
	{&venc02,5,45},
	{&venc05,5,60},
	{&venc04,5,55},
	{&venc03,5,50},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3202[132];	//VDS32-02
static vds32r_inipar ini_VDS3202={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3202={0,0,&ini_VDS3202,buf_VDS3202,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3202[]={
	{&R2IS11LDU,1,56},
	{&R0VZ71LZ1,1,42},
	{&A1VN71LZ1,1,40},
	{&R0AD14LZ1,1,38},
	{&A3VZ13LZ1,1,34},
	{&A3VZ15LZ1,1,36},
	{&B2IS33LDU,1,4},
	{&R1IS11LDU,1,52},
	{&B3IS31LDU,1,8},
	{&B3IS33LDU,1,2},
	{&B3IS35LDU,1,0},
	{&B4IS10LDU,1,6},
	{&B3IS21LDU,1,24},
	{&B1IS11LDU,1,14},
	{&R0DE02LDU,3,64},
	{&B7AS31LDU,1,10},
	{&R1IS21LDU,1,54},
	{&B2IS11LDU,1,20},
	{&B1IS12LDU,1,12},
	{&B4IS11LDU,1,60},
	{&R2IS21LDU,1,58},
	{&B2IS12LDU,1,18},
	{&B9IS21LDU,1,50},
	{&B9IS11LDU,1,48},
	{&A9IS21LDU,1,46},
	{&B1IS21LDU,1,16},
	{&R8IS11LDU,1,26},
	{&A9IS11LDU,1,44},
	{&B2IS21LDU,1,22},
	{&B4IS21LDU,1,62},
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
	{&A1IS11LDU,1,14},
	{&R0IS01LDU,1,56},
	{&R0IS02LDU,1,58},
	{&A1IS12LDU,1,12},
	{&A2IS33LDU,1,4},
	{&A4IS11LDU,1,26},
	{&A3IS31LDU,1,8},
	{&A3IS33LDU,1,2},
	{&A3IS35LDU,1,0},
	{&A4IS10LDU,1,6},
	{&A1VN71LZ2,1,40},
	{&A3VZ15LZ2,1,36},
	{&A3VZ13LZ2,1,34},
	{&R0AD14LZ2,1,38},
	{&A4IS21LDU,1,28},
	{&A7AS31LDU,1,10},
	{&A2IS12LDU,1,18},
	{&A2IS11LDU,1,20},
	{&R0DE03LDU,3,64},
	{&R0VZ71LZ2,1,42},
	{&A1IS21LDU,1,16},
	{&A2IS21LDU,1,22},
	{&A3IS21LDU,1,24},
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
	{&B8IS11LDU,1,36},
	{&B3IS11LDU,1,4},
	{&A5IS21LDU,1,22},
	{&A5IS11LDU,1,20},
	{&A8IS12LDU,1,58},
	{&B6IS21LDU,1,26},
	{&A3IS11LDU,1,0},
	{&R3IS11LDU,1,32},
	{&R3IS21LDU,1,34},
	{&R6IS21LDU,1,56},
	{&R5IS11LDU,1,48},
	{&A8IS22LDU,1,60},
	{&R4IS11LDU,1,8},
	{&R5IS21LDU,1,50},
	{&B8IS21LDU,1,38},
	{&B8IS12LDU,1,40},
	{&R0DE04LDU,3,64},
	{&B6IS11LDU,1,24},
	{&A6IS21LDU,1,18},
	{&A6IS11LDU,1,16},
	{&A3IS22LDU,1,2},
	{&B3IS22LDU,1,6},
	{&B5IS11LDU,1,28},
	{&B5IS21LDU,1,30},
	{&R4IS21LDU,1,12},
	{&R4IS22LDU,1,14},
	{&R4IS12LDU,1,10},
	{&B8IS22LDU,1,42},
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
	{&A1IE01LDU,1,2},
	{&R0DE05LDU,3,64},
	{&A1IE03LDU,1,4},
	{&A1IE04LDU,1,6},
	{&A2IE03LDU,1,12},
	{&A2IE04LDU,1,14},
	{&A3IE03LDU,1,20},
	{&A3IE04LDU,1,22},
	{&B1IE03LDU,1,28},
	{&B1IE04LDU,1,30},
	{&B2IE03LDU,1,36},
	{&B2IE04LDU,1,38},
	{&B3IE03LDU,1,44},
	{&B3IE04LDU,1,46},
	{&R6IS41LDU,1,52},
	{&R6IS42LDU,1,54},
	{&R6IS32LDU,1,50},
	{&R6IS31LDU,1,48},
	{&A3IE01LDU,1,18},
	{&R6IS51LDU,1,56},
	{&R6IS52LDU,1,58},
	{&A2IE01LDU,1,10},
	{&A1IE02LDU,1,0},
	{&A3IE02LDU,1,16},
	{&A2IE02LDU,1,8},
	{&B1IE01LDU,1,26},
	{&B2IE01LDU,1,34},
	{&B2IE02LDU,1,32},
	{&B3IE01LDU,1,42},
	{&B1IE02LDU,1,24},
	{&B3IE02LDU,1,40},
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
	{&B2AD11LDU,1,14},
	{&A2AD01LDU,1,4},
	{&B2AD21LDU,1,16},
	{&B2AD02LDU,1,20},
	{&B2AD03LDU,1,22},
	{&B2AD04LDU,1,24},
	{&B2AD05LDU,1,26},
	{&B2AD01LDU,1,18},
	{&A2AD11LDU,1,0},
	{&A2AD21LDU,1,2},
	{&A2AD02LDU,1,6},
	{&A2AD03LDU,1,8},
	{&A2AD04LDU,1,10},
	{&R0DE07LDU,3,38},
	{&A2AD05LDU,1,12},
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
	{&A1AD03LDU,1,8},
	{&A1AD04LDU,1,10},
	{&A1AD05LDU,1,12},
	{&A1AD01LDU,1,4},
	{&R0DE08LDU,3,38},
	{&A1AD21LDU,1,2},
	{&B1AD01LDU,1,18},
	{&B1AD05LDU,1,26},
	{&A1AD11LDU,1,0},
	{&B1AD11LDU,1,14},
	{&B1AD21LDU,1,16},
	{&B1AD04LDU,1,24},
	{&A1AD02LDU,1,6},
	{&B1AD03LDU,1,22},
	{&B1AD02LDU,1,20},
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
	{&B3AD33LDU,1,2},
	{&B7AP31LDU,1,10},
	{&B4AD10LDU,1,6},
	{&A6AD20LDU,1,18},
	{&B2AD33LDU,1,4},
	{&B3AD34LDU,1,0},
	{&B3AD31LDU,1,8},
	{&B6AD10LDU,1,20},
	{&B6AD20LDU,1,22},
	{&A6AD10LDU,1,16},
	{&B8AD10LDU,1,28},
	{&B8AD20LDU,1,30},
	{&R4AD20LDU,1,26},
	{&R0DE09LDU,3,38},
	{&A8AD10LDU,1,12},
	{&R4AD10LDU,1,24},
	{&A8AD20LDU,1,14},
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
	{&A4AD10LDU,1,6},
	{&A3AD33LDU,1,2},
	{&R0DE0ALDU,3,38},
	{&A2AD33LDU,1,4},
	{&A3AD34LDU,1,0},
	{&A3AD31LDU,1,8},
	{&R2AD20LDU,1,18},
	{&A7AP31LDU,1,10},
	{&R2AD10LDU,1,16},
	{&R1AD20LDU,1,14},
	{&A5AD20LDU,1,22},
	{&A5AD10LDU,1,20},
	{&B5AD20LDU,1,26},
	{&B5AD10LDU,1,24},
	{&R1AD10LDU,1,12},
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
	{&B3AD01LDU,1,18},
	{&B3AD05LDU,1,26},
	{&R0DE0BLDU,3,38},
	{&A3AD02LDU,1,6},
	{&A3AD03LDU,1,8},
	{&A3AD04LDU,1,10},
	{&A3AD05LDU,1,12},
	{&A3AD01LDU,1,4},
	{&A3AD11LDU,1,0},
	{&A3AD21LDU,1,2},
	{&B9AD10LDU,1,30},
	{&A9AD10LDU,1,28},
	{&B3AD11LDU,1,14},
	{&B3AD21LDU,1,16},
	{&B3AD02LDU,1,20},
	{&B3AD03LDU,1,22},
	{&B3AD04LDU,1,24},
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
	{&B6VS22LDU,1,40},
	{&A6VS22LDU,1,34},
	{&A6VS12LDU,1,32},
	{&R1VS12LDU,1,8},
	{&R2VS12LDU,1,14},
	{&R2VS22LDU,1,16},
	{&R1VS22LDU,1,10},
	{&R0DE0DLDU,3,64},
	{&R4VS12LDU,1,2},
	{&R4VS22LDU,1,4},
	{&B5VS12LDU,1,26},
	{&B5VS22LDU,1,28},
	{&A5VS12LDU,1,20},
	{&A5VS22LDU,1,22},
	{&R6IS61LDU,1,0},
	{&R2IE01LDU,1,18},
	{&B6VS12LDU,1,38},
	{&R0IE01LDU,1,46},
	{&A6IE01LDU,1,36},
	{&B6IE01LDU,1,42},
	{&A8IE01LDU,1,6},
	{&B5IE01LDU,1,30},
	{&A5IE02LDU,1,24},
	{&R0IE02LDU,1,44},
	{&R1IE01LDU,1,12},
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
	{&B1AD32LDU,1,8},
	{&A1AD31LDU,1,2},
	{&A1AD32LDU,1,0},
	{&B2AD31LDU,1,14},
	{&A2AD31LDU,1,6},
	{&A2AD32LDU,1,4},
	{&B2AD32LDU,1,12},
	{&B1AD31LDU,1,10},
	{&R0AD03LZ2,1,26},
	{&R0AD04LZ1,1,18},
	{&R0DE0FLDU,3,38},
	{&R0AD04LZ2,1,28},
	{&R0AD05LZ1,1,20},
	{&R0AD05LZ2,1,30},
	{&R0AD16LDU,1,24},
	{&R0AD03LZ1,1,16},
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
	{&R0DE38LDU,1,14},
	{&R0DE39LDU,1,16},
	{&R0DEB3LDU,1,22},
	{&R0DEB2LDU,1,20},
	{&R0DEB1LDU,1,18},
	{&R0DE36LDU,1,10},
	{&R0DE35LDU,1,8},
	{&R0DE34LDU,1,6},
	{&R0DE33LDU,1,4},
	{&R0DE32LDU,1,2},
	{&R0DE31LDU,1,0},
	{&R0DEB4LDU,1,24},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0x02,0x01,5,84,def_buf_VENCF,&table_VENCF}, //VENCF
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
	setAsFloat(738,0.0000976563);
	setAsInt(739,1024200);
	setAsInt(740,-200);
	setAsInt(741,-200);
	setAsInt(742,1024200);
	setAsFloat(743,0.0000976563);
	setAsInt(744,-200);
	setAsInt(745,1689599);
	setAsFloat(746,0.00009765625);
	setAsInt(747,-200);
	setAsFloat(748,0.0009765625);
	setAsInt(749,1536200);
	setAsFloat(750,100);
	setAsFloat(751,200);
	setAsFloat(752,300);
	setAsFloat(753,400);
	setAsFloat(754,600);
	setAsFloat(755,500);
	setAsFloat(756,750);
	setAsFloat(757,2.5);
	setAsFloat(758,0);
	setAsFloat(759,0.46);
	setAsFloat(760,0.49);
	setAsFloat(761,0.52);
	setAsFloat(762,0.53);
	setAsFloat(763,0.67);
	setAsFloat(764,0.56);
	setAsFloat(765,4);
	setAsFloat(766,4);
	setAsFloat(767,10.91);
	setAsFloat(768,3);
	setAsShort(769,4);
	setAsFloat(770,0.15);
	setAsFloat(771,0.15);
	setAsFloat(772,0.4);
	setAsFloat(773,0.4);
	setAsFloat(774,0.03);
	setAsFloat(775,0.04);
	setAsFloat(776,3);
	setAsFloat(777,0.3);
	setAsFloat(778,0.3);
	setAsFloat(779,0.07);
	setAsFloat(780,0.04);
	setAsFloat(781,3);
	setAsFloat(782,0.55);
	setAsFloat(783,0.64);
	setAsFloat(784,0.180);
	setAsFloat(785,0.025);
	setAsFloat(786,0.1);
	setAsFloat(787,2);
	setAsFloat(788,0.3);
	setAsFloat(789,3);
	setAsFloat(790,1.50);
	setAsFloat(791,0.04);
	setAsFloat(792,0.05);
	setAsFloat(793,3);
	setAsFloat(794,1.50);
	setAsFloat(795,3);
	setAsFloat(796,1.50);
	setAsFloat(797,2);
	setAsFloat(798,0.004);
	setAsFloat(799,0.006);
	setAsFloat(800,0.006);
	setAsFloat(801,1.0);
	setAsFloat(802,0.01);
	setAsFloat(803,1);
	setAsFloat(804,0.008);
	setAsFloat(805,0.01);
	setAsFloat(806,1);
	setAsFloat(807,0.4);
	setAsFloat(808,120);
	setAsFloat(809,0.6);
	setAsFloat(810,1);
	setAsFloat(811,2);
	setAsFloat(812,1.50);
	setAsFloat(813,2.0);
	setAsFloat(814,1);
	setAsFloat(815,15);
	setAsFloat(816,0.50);
	setAsFloat(817,360);
	setAsFloat(818,1);
	setAsFloat(819,2);
	setAsFloat(820,1.0);
	setAsFloat(821,6.0);
	setAsFloat(822,0.50);
	setAsFloat(823,1.0);
	setAsFloat(824,16.0);
	setAsFloat(825,3.0);
	setAsFloat(826,1.0);
	setAsFloat(827,60.0);
	setAsFloat(828,0.50);
	setAsFloat(829,1.0);
	setAsFloat(830,20.0);
	setAsFloat(831,1);
	setAsFloat(832,2.0);
	setAsFloat(833,2.0);
	setAsFloat(834,1.5);
	setAsFloat(835,0.06);
	setAsFloat(836,0.01);
	setAsFloat(837,0.045);
	setAsFloat(838,0.040);
	setAsFloat(839,0.007);
	setAsFloat(840,0.014);
	setAsFloat(841,2000.0);
	setAsFloat(842,1500.0);
	setAsFloat(843,1000.0);
	setAsFloat(844,800.0);
	setAsFloat(845,500.0);
	setAsFloat(846,200.0);
	setAsFloat(847,100.0);
	setAsFloat(848,0.001);
	setAsFloat(849,100);
	setAsFloat(850,100);
	setAsFloat(851,110.0);
	setAsFloat(852,20);
	setAsFloat(853,30.0);
	setAsFloat(854,100.0);
	setAsFloat(855,1.50);
	setAsFloat(856,170);
	setAsFloat(857,170);
	setAsFloat(858,10);
	setAsShort(859,1);
	setAsShort(860,4);
	setAsShort(861,1);
	setAsShort(862,4);
	setAsShort(863,4);
	setAsShort(864,4);
	setAsShort(865,4);
	setAsBool(866,0);
	setAsFloat(867,159.99);
	setAsFloat(868,0.002375);
	setAsFloat(869,0.000877);
	setAsFloat(870,0.001675);
	setAsFloat(871,2.5);
	setAsFloat(872,30);
	setAsFloat(873,30);
	setAsFloat(874,0.05);
	setAsFloat(875,0.05);
	setAsFloat(876,160.0);
	setAsFloat(877,-170.11);
	setAsFloat(878,76.25088);
	setAsFloat(879,0.271145);
	setAsFloat(880,24.93556615);
	setAsFloat(881,0.1268);
	setAsFloat(882,0.1567);
	setAsFloat(883,0.1858);
	setAsFloat(884,0.2066);
	setAsFloat(885,0.2646);
	setAsFloat(886,0.2995);
	setAsFloat(887,0.721275);
	setAsFloat(888,0.700575);
	setAsFloat(889,0.6681);
	setAsFloat(890,0.61515);
	setAsFloat(891,0.3885);
	setAsFloat(892,0.23325);
	setAsFloat(893,3600.0);
	setAsFloat(894,0.935);
	setAsFloat(895,0.1);
	setAsFloat(896,0.006792308);
	setAsFloat(897,0.000418877);
	setAsFloat(898,0.0015);
	setAsFloat(899,0.30);
	setAsBool(249,1);
	setAsBool(251,1);
	setAsBool(247,1);
	setAsBool(250,1);
	setAsBool(252,1);
	setAsBool(248,1);
	setAsBool(240,1);
	setAsBool(241,1);
	setAsBool(242,1);
}
uspaint8 InternalBuf[9655];

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
ssint iRM_14_ = {14,0}; /* n - N-����������� ������� ������� ���������� */ 
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
ssbool var189;
ssbool var190;
ssbool var191;
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
ssbool var309;
ssbool var310;
ssbool var311;
ssbool var312;
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
ssint var344;
ssbool var345;
ssbool var346;
ssint var347;
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
ssfloat var392;
ssbool var393;
ssbool var394;
ssbool var395;
ssbool var396;
ssbool var397;
ssbool var398;
ssbool var399;
ssbool var400;
ssbool var401;
ssfloat var402;
ssfloat var403;
ssbool var404;
ssbool var405;
ssbool var406;
ssfloat var407;
ssfloat var408;
ssbool var409;
ssbool var410;
ssfloat var411;
ssbool var412;
ssbool var413;
ssbool var414;
ssbool var415;
ssbool var416;
ssbool var417;
ssbool var418;
ssbool var419;
ssfloat var420;
ssfloat var421;
ssfloat var422;
ssfloat var423;
ssbool var424;
ssfloat var425;
ssfloat var426;
ssint var427;
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
ssfloat var518;
ssbool var519;
ssbool var520;
ssbool var521;
ssfloat var522;
ssbool var523;
ssbool var524;
ssbool var525;
ssfloat var526;
ssbool var527;
ssbool var528;
ssbool var529;
ssfloat var530;
ssbool var531;
ssbool var532;
ssbool var533;
ssfloat var534;
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
ssfloat var631;
ssfloat var632;
ssbool var633;
ssfloat var634;
ssfloat var635;
ssbool var636;
ssfloat var637;
ssfloat var638;
ssbool var639;
ssfloat var640;
ssfloat var641;
ssbool var642;
ssbool var643;
ssfloat var644;
ssfloat var645;
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
sslong var775;
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
ssbool var1053;
ssbool var1054;
ssbool var1055;
ssbool var1056;
ssbool var1057;
ssbool var1058;
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
ssfloat var1186;
ssbool var1187;
ssfloat var1188;
ssbool var1189;
ssfloat var1190;
ssbool var1191;
ssbool var1192;
ssbool var1193;
ssbool var1194;
ssfloat var1195;
ssfloat var1196;
ssfloat var1197;
ssfloat var1198;
ssfloat var1199;
ssfloat var1200;
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
ssint var1256;
ssint var1257;
ssbool var1258;
ssbool var1259;
ssbool var1260;
ssbool var1261;
ssbool var1262;
ssbool var1263;
sslong var1264;
ssbool var1265;
ssbool var1266;
ssbool var1267;
ssint var1268;
ssbool var1269;
ssbool var1270;
ssbool var1271;
ssbool var1272;
ssbool var1273;
ssbool var1274;
ssbool var1275;
ssbool var1276;
ssbool var1277;
ssint var1278;
ssint var1279;
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
ssbool var1294;
ssbool var1295;
ssbool var1296;
ssbool var1297;
ssbool var1298;
ssbool var1299;
ssbool var1300;
ssbool var1301;
ssbool var1302;
ssbool var1303;
ssbool var1304;
ssbool var1305;
ssbool var1306;
ssbool var1307;
ssbool var1308;
ssbool var1309;
ssbool var1310;
ssbool var1311;
ssbool var1312;
ssbool var1313;
ssbool var1314;
ssbool var1315;
ssbool var1316;
ssbool var1317;
ssbool var1318;
sslong var1319;
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
ssbool var1332;
ssbool var1333;
ssbool var1334;
ssbool var1335;
ssbool var1336;
ssbool var1337;
ssfloat var1338;
ssbool var1339;
ssbool var1340;
ssbool var1341;
ssbool var1342;
ssbool var1343;
ssfloat var1344;
ssbool var1345;
ssbool var1346;
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
ssint var1358;
ssbool var1359;
ssbool var1360;
ssbool var1361;
ssbool var1362;
ssbool var1363;
ssbool var1364;
ssbool var1365;
ssbool var1366;
ssbool var1367;
ssbool var1368;
ssbool var1369;
ssbool var1370;
ssbool var1371;
ssbool var1372;
ssbool var1373;
ssbool var1374;
ssbool var1375;
ssbool var1376;
ssbool var1377;
ssbool var1378;
ssbool var1379;
ssbool var1380;
ssbool var1381;
ssbool var1382;
ssfloat var1383;
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
ssbool var1394;
ssbool var1395;
ssbool var1396;
ssbool var1397;
ssbool var1398;
ssbool var1399;
ssbool var1400;
ssbool var1401;
ssbool var1402;
ssbool var1403;
ssbool var1404;
ssbool var1405;
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
ssbool var1418;
ssbool var1419;
ssbool var1420;
ssbool var1421;
ssbool var1422;
ssbool var1423;
ssbool var1424;
ssbool var1425;
ssbool var1426;
ssbool var1427;
ssbool var1428;
ssbool var1429;
ssbool var1430;
ssbool var1431;
ssbool var1432;
ssbool var1433;
ssbool var1434;
ssbool var1435;
ssbool var1436;
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
ssbool var1449;
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
ssbool var1466;
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
sslong var1479;
ssbool var1480;
ssint var1481;
ssint var1482;
ssbool var1483;
ssfloat var1484;
ssfloat var1485;
ssfloat var1486;
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
ssint var1503;
ssbool var1504;
sschar var1505;
ssint var1506;
ssbool var1507;
ssfloat var1508;
ssbool var1509;
ssbool var1510;
ssbool var1511;
ssbool var1512;
ssbool var1513;
ssbool var1514;
ssbool var1515;
ssfloat var1516;
sschar var1517;
ssbool var1518;
ssbool var1519;
ssbool var1520;
ssbool var1521;
ssfloat var1522;
ssbool var1523;
ssbool var1524;
ssbool var1525;
ssbool var1526;
ssbool var1527;
ssbool var1528;
ssbool var1529;
ssbool var1530;
ssbool var1531;
ssbool var1532;
ssbool var1533;
ssbool var1534;
ssint var1535;
ssbool var1536;
sschar var1537;
ssint var1538;
ssbool var1539;
ssfloat var1540;
ssbool var1541;
ssbool var1542;
ssbool var1543;
ssbool var1544;
ssbool var1545;
ssbool var1546;
ssbool var1547;
ssfloat var1548;
sschar var1549;
ssbool var1550;
ssbool var1551;
ssbool var1552;
ssbool var1553;
ssfloat var1554;
ssbool var1555;
ssbool var1556;
ssbool var1557;
ssbool var1558;
ssbool var1559;
ssbool var1560;
ssbool var1561;
ssbool var1562;
ssbool var1563;
ssint var1564;
ssbool var1565;
sschar var1566;
ssint var1567;
ssbool var1568;
ssfloat var1569;
ssbool var1570;
ssbool var1571;
ssbool var1572;
ssbool var1573;
ssbool var1574;
ssbool var1575;
ssbool var1576;
ssfloat var1577;
sschar var1578;
ssbool var1579;
ssbool var1580;
ssbool var1581;
ssbool var1582;
ssfloat var1583;
ssbool var1584;
ssbool var1585;
ssbool var1586;
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
ssint var1597;
ssbool var1598;
sschar var1599;
ssint var1600;
ssbool var1601;
ssfloat var1602;
ssbool var1603;
ssbool var1604;
ssbool var1605;
ssbool var1606;
ssbool var1607;
ssbool var1608;
ssbool var1609;
ssfloat var1610;
sschar var1611;
ssbool var1612;
ssbool var1613;
ssfloat var1614;
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
ssbool var1625;
ssbool var1626;
ssint var1627;
ssbool var1628;
ssbool var1629;
ssbool var1630;
ssbool var1631;
ssbool var1632;
ssbool var1633;
ssbool var1634;
ssbool var1635;
ssint var1636;
ssbool var1637;
ssbool var1638;
ssbool var1639;
ssbool var1640;
ssbool var1641;
ssbool var1642;
ssbool var1643;
ssint var1644;
ssbool var1645;
sschar var1646;
ssint var1647;
ssbool var1648;
ssfloat var1649;
ssbool var1650;
ssbool var1651;
ssbool var1652;
ssbool var1653;
ssbool var1654;
ssbool var1655;
ssbool var1656;
ssfloat var1657;
sschar var1658;
ssbool var1659;
ssbool var1660;
ssfloat var1661;
ssbool var1662;
ssbool var1663;
ssbool var1664;
ssbool var1665;
ssbool var1666;
ssbool var1667;
ssbool var1668;
ssbool var1669;
sschar var1670;
ssbool var1671;
ssbool var1672;
ssbool var1673;
ssbool var1674;
ssbool var1675;
ssbool var1676;
ssbool var1677;
ssbool var1678;
ssbool var1679;
sschar var1680;
ssbool var1681;
ssbool var1682;
ssint var1683;
ssbool var1684;
sschar var1685;
ssbool var1686;
ssint var1687;
ssbool var1688;
ssbool var1689;
ssfloat var1690;
ssbool var1691;
ssbool var1692;
ssbool var1693;
ssbool var1694;
ssbool var1695;
ssbool var1696;
ssbool var1697;
ssfloat var1698;
sschar var1699;
ssbool var1700;
ssbool var1701;
ssbool var1702;
ssbool var1703;
ssfloat var1704;
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
ssbool var1720;
ssbool var1721;
ssbool var1722;
ssbool var1723;
ssbool var1724;
ssbool var1725;
ssbool var1726;
ssbool var1727;
ssbool var1728;
ssbool var1729;
ssbool var1730;
ssbool var1731;
ssbool var1732;
ssbool var1733;
ssfloat var1734;
ssbool var1735;
ssbool var1736;
ssbool var1737;
ssbool var1738;
ssbool var1739;
ssbool var1740;
ssbool var1741;
ssbool var1742;
ssbool var1743;
ssbool var1744;
ssbool var1745;
ssbool var1746;
ssbool var1747;
ssbool var1748;
ssbool var1749;
ssbool var1750;
ssbool var1751;
ssbool var1752;
ssbool var1753;
ssbool var1754;
ssbool var1755;
ssbool var1756;
ssbool var1757;
ssbool var1758;
ssbool var1759;
ssbool var1760;
ssbool var1761;
ssbool var1762;
ssbool var1763;
ssbool var1764;
ssbool var1765;
ssbool var1766;
ssbool var1767;
ssbool var1768;
ssbool var1769;
ssbool var1770;
ssbool var1771;
ssint var1772;
ssbool var1773;
ssbool var1774;
ssbool var1775;
ssbool var1776;
ssbool var1777;
ssbool var1778;
ssbool var1779;
ssbool var1780;
ssint var1781;
ssbool var1782;
ssbool var1783;
ssbool var1784;
ssbool var1785;
ssbool var1786;
ssbool var1787;
ssbool var1788;
ssbool var1789;
ssint var1790;
ssbool var1791;
ssbool var1792;
ssbool var1793;
ssbool var1794;
ssbool var1795;
ssbool var1796;
ssbool var1797;
ssbool var1798;
ssint var1799;
ssbool var1800;
ssbool var1801;
ssbool var1802;
ssbool var1803;
ssbool var1804;
ssbool var1805;
ssbool var1806;
ssbool var1807;
ssint var1808;
ssbool var1809;
ssbool var1810;
ssbool var1811;
ssbool var1812;
ssbool var1813;
ssbool var1814;
ssbool var1815;
ssbool var1816;
ssint var1817;
ssbool var1818;
ssbool var1819;
ssbool var1820;
ssbool var1821;
ssbool var1822;
ssbool var1823;
ssbool var1824;
ssbool var1825;
ssint var1826;
ssbool var1827;
ssbool var1828;
ssbool var1829;
ssbool var1830;
ssbool var1831;
ssbool var1832;
ssbool var1833;
ssbool var1834;
ssbool var1835;
ssbool var1836;
ssbool var1837;
ssbool var1838;
ssbool var1839;
ssbool var1840;
ssbool var1841;
ssbool var1842;
ssbool var1843;
ssbool var1844;
ssbool var1845;
ssbool var1846;
ssbool var1847;
ssbool var1848;
ssbool var1849;
ssbool var1850;
ssbool var1851;
ssbool var1852;
ssbool var1853;
ssbool var1854;
ssbool var1855;
ssbool var1856;
ssbool var1857;
ssbool var1858;
ssbool var1859;
ssbool var1860;
ssbool var1861;
ssbool var1862;
ssbool var1863;
ssbool var1864;
ssbool var1865;
ssbool var1866;
ssbool var1867;
ssbool var1868;
ssbool var1869;
ssbool var1870;
ssbool var1871;
ssbool var1872;
ssbool var1873;
ssbool var1874;
ssfloat var1875;
ssbool var1876;
ssbool var1877;
ssbool var1878;
ssbool var1879;
ssbool var1880;
ssbool var1881;
ssbool var1882;
ssbool var1883;
ssbool var1884;
ssbool var1885;
ssbool var1886;
ssbool var1887;
ssbool var1888;
ssbool var1889;
ssbool var1890;
ssbool var1891;
ssbool var1892;
ssbool var1893;
ssbool var1894;
ssbool var1895;
ssbool var1896;
ssbool var1897;
ssbool var1898;
ssbool var1899;
ssbool var1900;
ssbool var1901;
ssbool var1902;
ssbool var1903;
ssbool var1904;
ssbool var1905;
ssbool var1906;
ssbool var1907;
ssbool var1908;
ssbool var1909;
ssfloat var1910;
ssfloat var1911;
ssbool var1912;
ssbool var1913;
ssbool var1914;
ssbool var1915;
ssbool var1916;
ssbool var1917;
ssbool var1918;
ssbool var1919;
ssbool var1920;
ssbool var1921;
ssbool var1922;
ssbool var1923;
ssbool var1924;
ssbool var1925;
ssbool var1926;
ssbool var1927;
ssbool var1928;
ssbool var1929;
ssbool var1930;
ssbool var1931;
ssbool var1932;
ssbool var1933;
ssbool var1934;
ssbool var1935;
ssbool var1936;
ssbool var1937;
ssfloat var1938;
ssbool var1939;
ssbool var1940;
ssfloat var1941;
ssbool var1942;
ssbool var1943;
ssfloat var1944;
ssbool var1945;
ssbool var1946;
ssfloat var1947;
ssbool var1948;
ssbool var1949;
ssfloat var1950;
ssbool var1951;
ssbool var1952;
ssfloat var1953;
ssbool var1954;
ssbool var1955;
ssfloat var1956;
ssbool var1957;
ssbool var1958;
ssbool var1959;
ssfloat var1960;
ssbool var1961;
ssbool var1962;
ssbool var1963;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* ���������� �������� */
psbool  array_m179_x_2[13] = {&R0IE02LDU,&R0IE01LDU,&R1IE01LDU,&R2IE01LDU,&A5IE02LDU,&B5IE01LDU,&A6IE01LDU,&R6IS61LDU,&R6IS67LZZ,&R6IS68LZZ,&B6IE01LDU,&A8IE01LDU,&R6IS66LZZ};
psbool  array_m166_x_2[6] = {&var1857,&var1856,&var1855,&var1854,&var1853,&var1852};
psbool  array_m138_x_2[6] = {&var1863,&var1862,&var1861,&var1860,&var1859,&var1858};
psbool  array_m254_x_2[6] = {&var1922,&var1914,&var1928,&B0VT71LZ1,&B0VT71LZ2,&var1873};
psbool  array_m243_x_2[6] = {&var1923,&var1916,&var1929,&A0VT71LZ1,&A0VT71LZ2,&var1873};
psbool  array_m266_x_2[6] = {&var1907,&B0VP71LZ1,&B0VP71LZ2,&var1878,&var1877,&var1876};
psbool  array_m245_x_2[6] = {&var1908,&A0VP71LZ1,&A0VP71LZ2,&var1881,&var1880,&var1879};
psbool  array_m124_x_2[8] = {&var1940,&var1962,&var1958,&var1955,&var1952,&var1949,&var1943,&var1946};
psbool  array_m2503_x_1[6] = {&var215,&var214,&R0DE36LDU,&R0DE37LDU,&R0DE38LDU,&R0DE39LDU};
psint  array_m2487_x_1[12] = {&R0DE0DLDU,&R0DE0FLDU,&R0DE02LDU,&R0DE03LDU,&R0DE04LDU,&R0DE05LDU,&R0DE07LDU,&R0DE08LDU,&R0DE09LDU,&R0DE0ALDU,&R0DE0BLDU,&R0DE0CLDU};
psbool  array_m887_x_1[6] = {&var806,&var1442,&var1418,&var1407,&var1211,&var294};
psbool  array_m1326_x_1[6] = {&var805,&var1422,&var221,&var1444,&var1211,&var314};
psbool  array_m655_x_1[6] = {&var1001,&var1310,&var1729,&var1271,&var1688,&var1304};
psbool  array_m654_x_1[6] = {&var1001,&var1311,&var1729,&var1271,&var1688,&var1303};
psfloat  array_m2392_a_1[6] = {&fEM_R0UN70LDU,&fEM_R0UN71LDU,&fEM_R0UN72LDU,&fEM_R0UN73LDU,&fEM_R0UN74LDU,&fEM_R0UN75LDU};
psfloat  array_m2392_b_1[6] = {&fEM_R0UN80LDU,&fEM_R0UN81LDU,&fEM_R0UN82LDU,&fEM_R0UN83LDU,&fEM_R0UN84LDU,&fEM_R0UN85LDU};
psfloat  array_m2402_x_1[4] = {&B0CT01IZ1,&A0CT01IZ1,&B0CT01IZ2,&A0CT01IZ2};
psfloat  array_m2425_x_1[2] = {&R0VN09RZ1,&R0VN09RZ2};
psbool  array_m2394_x_1[14] = {&var406,&var379,&var1035,&var440,&var442,&var377,&var1851,&var1431,&var1429,&var1874,&var405,&var394,&var390,&var414};
psbool  array_m1_x_1[47] = {&var1394,&lRM_0_,&var539,&var269,&var689,&var1598,&var924,&R0MD34LP1,&var838,&R0MD34LP1,&var897,&R0MD34LP1,&var1131,&R0MD34LP1,&var951,&R0MD34LP1,&var1129,&var1625,&A2IS12LDU,&var596,&var1425,&var1318,&var1316,&var1229,&var1044,&R0MD34LP1,&var626,&var667,&var1469,&var1779,&R0MD34LP1,&var782,&var773,&var728,&B3IS35LDU,&B3IS35LDU,&var461,&var267,&var700,&var508,&var1830,&var1788,&var1815,&var1150,&var1802,&R2IS21LDU,&var380};
psfloat  array_m1625_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psbool  array_m1579_x_1[5] = {&var782,&var781,&var780,&var779,&var778};
psbool  array_m605_x_1[12] = {&var949,&var955,&var956,&var947,&var948,&var1133,&var1134,&var434,&var944,&var945,&var943,&var951};
psfloat  array_m82_x_1[2] = {&R0VN11RZ2,&R0VN11RZ1};
psfloat  array_m84_x_1[8] = {&fEM_R0UN01RDU,&fEM_R0UN02RDU,&fEM_R0UN03RDU,&fEM_R0UN04RDU,&fEM_R0UN05RDU,&fEM_R0UN06RDU,&fEM_R0UN07RDU,&fEM_R0UN08RDU};
psfloat  array_m1180_x_1[2] = {&R0VN11RZ2,&R0VN11RZ1};
psfloat  array_m1335_x_1[8] = {&var1690,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m895_x_1[8] = {&var1649,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m993_x_1[8] = {&var1540,&var403,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m1449_x_1[8] = {&var1508,&var402,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m537_x_1[8] = {&var1569,&var530,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m164_x_1[8] = {&var1602,&var534,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m345_Tpr_1[10] = {&fRM_6_0,&fRM_126_0,&fRM_246_0,&fRM_366_0,&fRM_486_0,&fRM_606_0,&fRM_726_0,&fRM_846_0,&fRM_966_0,&fRM_1200_0};
pschar  array_m345_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m345_rz_1[10];
psbool  array_m349_x_1[5] = {&var1259,&var1260,&var1261,&var1262,&var1263};
psbool  array_m283_x_1[7] = {&var1035,&var436,&var1238,&var1235,&var442,&var440,&var438};
psfloat  array_m287_Tpr_1[10] = {&fRM_10_0,&fRM_30_0,&fRM_50_0,&fRM_70_0,&fRM_90_0,&fRM_110_0,&fRM_130_0,&fRM_150_0,&fRM_170_0,&fRM_200_0};
pschar  array_m287_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m287_rz_1[10];
psfloat  array_m1568_Tpr_1[6] = {&fRM_0_5,&fRM_3_5,&fRM_6_5,&fRM_9_5,&fRM_12_5,&fRM_15_5};
pschar  array_m1568_type_1[6] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_6_};
pschar  array_m1568_rz_1[6];
psbool  array_m303_x_1[5] = {&var1281,&var1282,&var1283,&var1284,&var1285};
psbool  array_m1311_x_1[5] = {&var1406,&var1018,&var1761,&var1411,&var452};
psbool  array_m1295_x_1[4] = {&var1315,&var1357,&var1231,&var1409};
psfloat  array_m1609_x_1[16] = {&var631,&var640,&fRM_0_,&var637,&fRM_0_,&fRM_0_,&fRM_0_,&var634,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&var644};
psbool  array_m1941_x_1[17] = {&var711,&var712,&var718,&var713,&var709,&var710,&var1168,&var714,&var715,&var1458,&var716,&var717,&var1450,&var1451,&var1460,&var446,&var447};
psbool  array_m1571_x_1[5] = {&var623,&var746,&var763,&var764,&var653};
psint  array_m322_x_1[3] = {&var1257,&iRM_0_,&var1279};
psint  array_m313_x_1[3] = {&var1256,&iRM_0_,&var1278};
psbool  array_m657_x_1[5] = {&var984,&var1728,&var1495,&var1212,&var412};
psbool  array_m1521_x_1[8] = {&var868,&var869,&var870,&var865,&var864,&var863,&var1129,&var861};
psbool  array_m1448_x_1[3] = {&var296,&lRM_0_,&var295};
psfloat  array_m1450_Lt_fw_1[1] = {&fEM_A3UC81RDU};
psint  array_m1450_Vr_fw_1[1] = {&iEM_A3UV01IDU};
psfloat  array_m1450_Lt_bw_1[1] = {&fEM_A3UC82RDU};
psint  array_m1450_Vr_bw_1[1] = {&iEM_A3UV02IDU};
psfloat  array_m1476_x0_1[60];
psfloat  array_m1476_tim0_1[60];
psbool  array_m1068_x_1[8] = {&var883,&var885,&var886,&var878,&var884,&var880,&var1131,&var612};
psbool  array_m992_x_1[3] = {&var322,&lRM_0_,&var317};
psfloat  array_m994_Lt_fw_1[1] = {&fEM_A3UC81RDU};
psint  array_m994_Vr_fw_1[1] = {&iEM_A3UV01IDU};
psfloat  array_m994_Lt_bw_1[1] = {&fEM_A3UC82RDU};
psint  array_m994_Vr_bw_1[1] = {&iEM_A3UV02IDU};
psfloat  array_m1024_x0_1[60];
psfloat  array_m1024_tim0_1[60];
psbool  array_m536_x_1[3] = {&var960,&lRM_0_,&var961};
psfloat  array_m539_Lt_fw_1[2] = {&fEM_A1UC81RDU,&fEM_A1UC82RDU};
psint  array_m539_Vr_fw_1[2] = {&iEM_A1UV01IDU,&iEM_A1UV02IDU};
psfloat  array_m539_Lt_bw_1[1] = {&fEM_A1UC83RDU};
psint  array_m539_Vr_bw_1[1] = {&iEM_A1UV03IDU};
psfloat  array_m562_x0_1[150];
psfloat  array_m562_tim0_1[150];
psbool  array_m239_x_1[12] = {&var929,&var931,&var930,&var927,&var925,&var924,&var923,&var1137,&var1136,&var918,&var921,&var435};
psbool  array_m166_x_1[3] = {&var1107,&lRM_0_,&var1108};
psfloat  array_m169_Lt_fw_1[2] = {&fEM_A1UC81RDU,&fEM_A1UC82RDU};
psint  array_m169_Vr_fw_1[2] = {&iEM_A1UV01IDU,&iEM_A1UV02IDU};
psfloat  array_m169_Lt_bw_1[1] = {&fEM_A1UC83RDU};
psint  array_m169_Vr_bw_1[1] = {&iEM_A1UV03IDU};
psfloat  array_m194_x0_1[150];
psfloat  array_m194_tim0_1[150];
psbool  array_m956_x_1[10] = {&var895,&var896,&var902,&var903,&var901,&var899,&var898,&var1139,&var1138,&var897};
psbool  array_m894_x_1[3] = {&var298,&var913,&var297};
psfloat  array_m898_Lt_fw_1[2] = {&fEM_A2UC81RDU,&fEM_A2UC82RDU};
psint  array_m898_Vr_fw_1[2] = {&iEM_A2UV01IDU,&iEM_A2UV02IDU};
psfloat  array_m898_Lt_bw_1[1] = {&fEM_A2UC83RDU};
psint  array_m898_Vr_bw_1[1] = {&iEM_A2UV03CDU};
psfloat  array_m916_x0_1[80];
psfloat  array_m916_tim0_1[80];
psfloat  array_m1757_Lt_fw_1[1] = {&fRM_1000_};
psint  array_m1757_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1757_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1757_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1416_x_1[10] = {&var834,&var835,&var837,&var836,&var838,&var840,&var842,&var839,&var841,&var843};
psbool  array_m147_x_1[5] = {&A1IS21LDU,&A3IS21LDU,&A2IS21LDU,&var1154,&var1153};
psfloat  array_m1242_Lt_fw_1[1] = {&fRM_2000_};
psint  array_m1242_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1242_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1242_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1334_x_1[3] = {&var326,&var828,&var313};
psfloat  array_m1337_Lt_fw_1[2] = {&fEM_A2UC81RDU,&fEM_A2UC82RDU};
psint  array_m1337_Vr_fw_1[2] = {&iEM_A2UV01IDU,&iEM_A2UV02IDU};
psfloat  array_m1337_Lt_bw_1[1] = {&fEM_A2UC83RDU};
psint  array_m1337_Vr_bw_1[1] = {&iEM_A2UV03CDU};
psfloat  array_m1372_x0_1[80];
psfloat  array_m1372_tim0_1[80];
psfloat  array_m1779_x0_1[20];
psfloat  array_m1779_tim0_1[20];
psbool  array_m1203_x_1[8] = {&var1045,&var1042,&var1043,&var1044,&var1041,&var1040,&var1039,&var1038};
psbool  array_m658_x_1[18] = {&R0MD31LP1,&var736,&var1059,&var738,&var1057,&var829,&var964,&var912,&var939,&var959,&var888,&var853,&var1115,&var551,&var550,&var819,&var468,&var404};
psfloat  array_m1267_x0_1[20];
psfloat  array_m1267_tim0_1[20];
psbool  array_m470_x_1[7] = {&var1160,&var1159,&var1158,&var1157,&var1832,&var1149,&var580};
psbool  array_m448_x_1[7] = {&var1162,&var1832,&var1150,&var1163,&var1161,&var1148,&var350};
psbool  array_m843_x_1[17] = {&var1060,&var1105,&var1104,&var1101,&var1100,&var1097,&var1062,&var1099,&var1067,&var1096,&var1092,&var1094,&var1093,&var1064,&var1058,&var1147,&var915};
psbool  array_m133_x_1[21] = {&var938,&var958,&var1203,&var911,&var1202,&var1201,&var1766,&var1775,&var1793,&var1784,&var1820,&var1811,&var689,&var581,&var1193,&var1194,&var1472,&var1466,&var1630,&var1621,&var1802};

/* ���������� �������� */
_S_zzfs  S_zzfs_182_2 = {&B2IE02LDU,&fRM_1_,&var1852,&internal2_m182_tx,&internal2_m182_y0};
_S_zzfs  S_zzfs_176_2 = {&B3IE01LDU,&fRM_1_,&var1853,&internal2_m176_tx,&internal2_m176_y0};
_S_zzfs  S_zzfs_173_2 = {&B1IE01LDU,&fRM_1_,&var1854,&internal2_m173_tx,&internal2_m173_y0};
_S_zzfs  S_zzfs_165_2 = {&B2IE01LDU,&fRM_1_,&var1855,&internal2_m165_tx,&internal2_m165_y0};
_S_zzfs  S_zzfs_158_2 = {&B1IE02LDU,&fRM_1_,&var1856,&internal2_m158_tx,&internal2_m158_y0};
_S_zzfs  S_zzfs_155_2 = {&B3IE02LDU,&fRM_1_,&var1857,&internal2_m155_tx,&internal2_m155_y0};
_S_zzfs  S_zzfs_149_2 = {&A3IE02LDU,&fRM_1_,&var1858,&internal2_m149_tx,&internal2_m149_y0};
_S_zzfs  S_zzfs_144_2 = {&A3IE01LDU,&fRM_1_,&var1859,&internal2_m144_tx,&internal2_m144_y0};
_S_zzfs  S_zzfs_141_2 = {&A2IE01LDU,&fRM_1_,&var1860,&internal2_m141_tx,&internal2_m141_y0};
_S_zzfs  S_zzfs_134_2 = {&A1IE01LDU,&fRM_1_,&var1861,&internal2_m134_tx,&internal2_m134_y0};
_S_zzfs  S_zzfs_132_2 = {&A2IE02LDU,&fRM_1_,&var1862,&internal2_m132_tx,&internal2_m132_y0};
_S_zzfs  S_zzfs_127_2 = {&A1IE02LDU,&fRM_1_,&var1863,&internal2_m127_tx,&internal2_m127_y0};
_S_and4  S_and4_108_2 = {&var1959,&var1894,&B8IS11LDU,&B8IS12LDU,&var1864};
_S_lkb  S_lkb_112_2 = {&lRM_1_,&var1892,&var1865};
_S_lkb  S_lkb_109_2 = {&lRM_1_,&var1864,&var1866};
_S_lkb  S_lkb_80_2 = {&lRM_1_,&var1895,&var1867};
_S_lkb  S_lkb_52_2 = {&lRM_1_,&var1900,&var1868};
_S_lkb  S_lkb_83_2 = {&lRM_1_,&var1898,&var1869};
_S_lkb  S_lkb_48_2 = {&lRM_1_,&var1904,&var1870};
_S_lkb  S_lkb_24_2 = {&lRM_1_,&var1902,&var1871};
_S_lkb  S_lkb_21_2 = {&lRM_1_,&var1906,&var1872};
_S_or2  S_or2_269_2 = {&var1963,&var1912,&var1873};
_S_bol  S_bol_234_2 = {&fRM_0_5,&var1875,&var1874};
_S_fsumo  S_fsumo_233_2 = {&var1911,&var1910,&var1875};
_S_noto  S_noto_262_2 = {&B3VP81LDU,&var1876};
_S_noto  S_noto_261_2 = {&B2VP82LDU,&var1877};
_S_noto  S_noto_260_2 = {&B4VP82LDU,&var1878};
_S_noto  S_noto_242_2 = {&A3VP81LDU,&var1879};
_S_noto  S_noto_241_2 = {&A2VP82LDU,&var1880};
_S_noto  S_noto_240_2 = {&A4VP82LDU,&var1881};
_S_schl24  S_schl24_151_2 = {&A0EE02LZ1,&A0EE03LZ1,&A0EE01LZ1,&A0EE04LZ1,&var1882};
_S_schl24  S_schl24_147_2 = {&A0EE03LZ2,&A0EE01LZ2,&A0EE02LZ2,&A0EE04LZ2,&var1883};
_S_or2  S_or2_207_2 = {&var1932,&var1933,&var1884};
_S_or2  S_or2_203_2 = {&var1935,&var1936,&var1885};
_S_and2  S_and2_223_2 = {&var1920,&var1931,&var1886};
_S_or2  S_or2_255_2 = {&var1927,&var1926,&var1887};
_S_and4  S_and4_162_2 = {&A0EE02LZ1,&A0EE04LZ1,&A0EE02LZ2,&A0EE04LZ2,&var1888};
_S_or3  S_or3_161_2 = {&var1888,&var1023,&var1882,&var1889};
_S_and4  S_and4_136_2 = {&A0EE03LZ1,&A0EE01LZ1,&A0EE01LZ2,&A0EE03LZ2,&var1890};
_S_or3  S_or3_135_2 = {&var1890,&var1883,&var1023,&var1891};
_S_and3  S_and3_111_2 = {&var1893,&var1959,&A8IS12LDU,&var1892};
_S_or2  S_or2_104_2 = {&A8MC01LC2,&A8MC01LC1,&var1893};
_S_or2  S_or2_103_2 = {&B8MC01LC2,&B8MC01LC1,&var1894};
_S_and3  S_and3_79_2 = {&var1959,&B3IS11LDU,&var1896,&var1895};
_S_or2  S_or2_71_2 = {&B3MC01LC2,&B3MC01LC1,&var1896};
_S_or2  S_or2_74_2 = {&A3MC01LC2,&A3MC01LC1,&var1897};
_S_and3  S_and3_82_2 = {&var1959,&var1897,&A3IS11LDU,&var1898};
_S_or2  S_or2_43_2 = {&A2MC01LC2,&A2MC01LC1,&var1899};
_S_and3  S_and3_51_2 = {&var1959,&A2IS11LDU,&var1899,&var1900};
_S_or2  S_or2_13_2 = {&A1MC01LC2,&A1MC01LC1,&var1901};
_S_and3  S_and3_23_2 = {&var1901,&var1959,&A1IS11LDU,&var1902};
_S_or2  S_or2_42_2 = {&B2MC01LC1,&B2MC01LC2,&var1903};
_S_and3  S_and3_47_2 = {&var1959,&B2IS11LDU,&var1903,&var1904};
_S_or2  S_or2_11_2 = {&B1MC01LC2,&B1MC01LC1,&var1905};
_S_and3  S_and3_20_2 = {&var1959,&B1IS11LDU,&var1905,&var1906};
_S_and2  S_and2_265_2 = {&var604,&var1884,&var1907};
_S_and2  S_and2_244_2 = {&var604,&var1885,&var1908};
_S_and2  S_and2_230_2 = {&var1921,&var1930,&var1909};
_S_scalzz  S_scalzz_195_2 = {&B3IP02IDU,&iRM_3276_,&iRM_16383_,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&var1910,&internal2_m195_y0};
_S_scalzz  S_scalzz_193_2 = {&A3IP02IDU,&iRM_3276_,&iRM_16383_,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&var1911,&internal2_m193_y0};
_S_noto  S_noto_180_2 = {&var1913,&var1912};
_S_andn  S_andn_179_2 = {array_m179_x_2,&iRM_13_,&var1913};
_S_noto  S_noto_177_2 = {&var1915,&var1914};
_S_andn  S_andn_166_2 = {array_m166_x_2,&iRM_6_,&var1915};
_S_noto  S_noto_145_2 = {&var1917,&var1916};
_S_andn  S_andn_138_2 = {array_m138_x_2,&iRM_6_,&var1917};
_S_noto  S_noto_264_2 = {&var1926,&var1918};
_S_noto  S_noto_246_2 = {&var1927,&var1919};
_S_noto  S_noto_222_2 = {&var1935,&var1920};
_S_noto  S_noto_231_2 = {&var1932,&var1921};
_S_noto  S_noto_160_2 = {&var1889,&var1922};
_S_noto  S_noto_142_2 = {&var1891,&var1923};
_S_noto  S_noto_267_2 = {&var1928,&var1924};
_S_noto  S_noto_251_2 = {&var1929,&var1925};
_S_ornc  S_ornc_254_2 = {array_m254_x_2,&iRM_6_,&var1926,&vainSChar};
_S_ornc  S_ornc_243_2 = {array_m243_x_2,&iRM_6_,&var1927,&vainSChar};
_S_ornc  S_ornc_266_2 = {array_m266_x_2,&iRM_6_,&var1928,&vainSChar};
_S_ornc  S_ornc_245_2 = {array_m245_x_2,&iRM_6_,&var1929,&vainSChar};
_S_tprg  S_tprg_228_2 = {&var1910,&fEM_A3UP85RDU,&fEM_A3UP86RDU,&fEM_A3UP87RDU,&fEM_A3UP88RDU,&var1930,&internal2_m228_y0};
_S_tprg  S_tprg_220_2 = {&var1911,&fEM_A3UP85RDU,&fEM_A3UP86RDU,&fEM_A3UP87RDU,&fEM_A3UP88RDU,&var1931,&internal2_m220_y0};
_S_geterr  S_geterr_200_2 = {&var1910,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var1932};
_S_drg  S_drg_208_2 = {&var1910,&lRM_1_,&lRM_0_,&fEM_A3UP43RDU,&fEM_A3UP44RDU,&var1933,&internal2_m208_y1};
_S_drg  S_drg_214_2 = {&var1910,&lRM_1_,&lRM_0_,&fEM_A3UP53RDU,&fEM_A3UP54RDU,&var1934,&internal2_m214_y1};
_S_geterr  S_geterr_197_2 = {&var1911,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var1935};
_S_drg  S_drg_198_2 = {&var1911,&lRM_1_,&lRM_0_,&fEM_A3UP43RDU,&fEM_A3UP44RDU,&var1936,&internal2_m198_y1};
_S_drg  S_drg_205_2 = {&var1911,&lRM_1_,&lRM_0_,&fEM_A3UP53RDU,&fEM_A3UP54RDU,&var1937,&internal2_m205_y1};
_S_enctkb  S_enctkb_17_2 = {&var1871,&fRM_0_0,&A1IC01UDU,&dEM_A1UC06UDU,&dEM_A1UC05UDU,&fEM_A1UC03RDU,&fRM_100_,&dRM_0_,&var1938,&var1939,&var1940,&internal2_m17_Nk0,&internal2_m17_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_110_2 = {&var1866,&fRM_390_,&B8IC01UDU,&dEM_A8UC06UDU,&dEM_A8UC05UDU,&fEM_A8UC03RDU,&fRM_1500_0,&dRM_0_,&var1941,&var1942,&var1943,&internal2_m110_Nk0,&internal2_m110_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_106_2 = {&var1865,&fRM_390_0,&A8IC01UDU,&dEM_A8UC06UDU,&dEM_A8UC05UDU,&fEM_A8UC03RDU,&fRM_1500_0,&dRM_0_,&var1944,&var1945,&var1946,&internal2_m106_Nk0,&internal2_m106_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_75_2 = {&var1867,&fRM_0_,&B3IC01UDU,&dEM_A3UC06UDU,&dEM_A3UC05UDU,&fEM_A3UC03RDU,&fRM_0_0,&dRM_0_,&var1947,&var1948,&var1949,&internal2_m75_Nk0,&internal2_m75_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_77_2 = {&var1869,&fRM_0_0,&A3IC01UDU,&dEM_A3UC06UDU,&dEM_A3UC05UDU,&fEM_A3UC03RDU,&fRM_0_0,&dRM_0_,&var1950,&var1951,&var1952,&internal2_m77_Nk0,&internal2_m77_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_49_2 = {&var1870,&fRM_0_0,&B2IC01UDU,&dEM_A2UC06UDU,&dEM_A2UC05UDU,&fEM_A2UC03RDU,&fRM_100_,&dRM_0_,&var1953,&var1954,&var1955,&internal2_m49_Nk0,&internal2_m49_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_53_2 = {&var1868,&fRM_0_0,&A2IC01UDU,&dEM_A2UC06UDU,&dEM_A2UC05UDU,&fEM_A2UC03RDU,&fRM_100_,&dRM_0_,&var1956,&var1957,&var1958,&internal2_m53_Nk0,&internal2_m53_SetFlag,&bFirstEnterFlag};
_S_equz_p  S_equz_p_19_2 = {&R0MW12IP1,&iRM_4_,&var1959};
_S_enctkb  S_enctkb_15_2 = {&var1872,&fRM_0_0,&B1IC01UDU,&dEM_A1UC06UDU,&dEM_A1UC05UDU,&fEM_A1UC03RDU,&fRM_100_,&dRM_0_,&var1960,&var1961,&var1962,&internal2_m15_Nk0,&internal2_m15_SetFlag,&bFirstEnterFlag};
_S_ornc  S_ornc_124_2 = {array_m124_x_2,&iRM_8_,&var1963,&vainSChar};
_S_ovbsb  S_ovbsb_2019_1 = {&var581,&var1,&internal1_m2019_tx};
_S_ovbsb  S_ovbsb_2018_1 = {&var689,&var2,&internal1_m2018_tx};
_S_ovbsb  S_ovbsb_774_1 = {&var1091,&var3,&internal1_m774_tx};
_S_ovbsb  S_ovbsb_731_1 = {&var1090,&var4,&internal1_m731_tx};
_S_ovbsb  S_ovbsb_788_1 = {&var1093,&var5,&internal1_m788_tx};
_S_ovbsb  S_ovbsb_785_1 = {&var1092,&var6,&internal1_m785_tx};
_S_ovbsb  S_ovbsb_784_1 = {&var1094,&var7,&internal1_m784_tx};
_S_ovbsb  S_ovbsb_740_1 = {&var1062,&var8,&internal1_m740_tx};
_S_ovbsb  S_ovbsb_729_1 = {&var1067,&var9,&internal1_m729_tx};
_S_ovbsb  S_ovbsb_735_1 = {&var1064,&var10,&internal1_m735_tx};
_S_ovbsb  S_ovbsb_766_1 = {&var1097,&var11,&internal1_m766_tx};
_S_ovbsb  S_ovbsb_783_1 = {&var1096,&var12,&internal1_m783_tx};
_S_ovbsb  S_ovbsb_756_1 = {&var1100,&var13,&internal1_m756_tx};
_S_ovbsb  S_ovbsb_387_1 = {&var1804,&var14,&internal1_m387_tx};
_S_ovbsb  S_ovbsb_386_1 = {&var1803,&var15,&internal1_m386_tx};
_S_ovbsb  S_ovbsb_385_1 = {&var1805,&var16,&internal1_m385_tx};
_S_ovbsb  S_ovbsb_384_1 = {&var1802,&var17,&internal1_m384_tx};
_S_ovbsb  S_ovbsb_755_1 = {&var1101,&var18,&internal1_m755_tx};
_S_ovbsb  S_ovbsb_750_1 = {&var1104,&var19,&internal1_m750_tx};
_S_ovbsb  S_ovbsb_759_1 = {&var1105,&var20,&internal1_m759_tx};
_S_ovbsb  S_ovbsb_764_1 = {&var1099,&var21,&internal1_m764_tx};
_S_ovbsb  S_ovbsb_520_1 = {&var1623,&var22,&internal1_m520_tx};
_S_ovbsb  S_ovbsb_519_1 = {&var1622,&var23,&internal1_m519_tx};
_S_ovbsb  S_ovbsb_518_1 = {&var1624,&var24,&internal1_m518_tx};
_S_ovbsb  S_ovbsb_514_1 = {&var1621,&var25,&internal1_m514_tx};
_S_ovbsb  S_ovbsb_491_1 = {&var1632,&var26,&internal1_m491_tx};
_S_ovbsb  S_ovbsb_490_1 = {&var1631,&var27,&internal1_m490_tx};
_S_ovbsb  S_ovbsb_489_1 = {&var1633,&var28,&internal1_m489_tx};
_S_ovbsb  S_ovbsb_492_1 = {&var1630,&var29,&internal1_m492_tx};
_S_ovbsb  S_ovbsb_2436_1 = {&var404,&var30,&internal1_m2436_tx};
_S_ovbsb  S_ovbsb_2145_1 = {&var388,&var31,&internal1_m2145_tx};
_S_ovbsb  S_ovbsb_2435_1 = {&var409,&var32,&internal1_m2435_tx};
_S_ovbsb  S_ovbsb_2434_1 = {&var416,&var33,&internal1_m2434_tx};
_S_ovbsb  S_ovbsb_2433_1 = {&var417,&var34,&internal1_m2433_tx};
_S_ovbsb  S_ovbsb_102_1 = {&var537,&var35,&internal1_m102_tx};
_S_ovbsb  S_ovbsb_1137_1 = {&var819,&var36,&internal1_m1137_tx};
_S_ovbsb  S_ovbsb_2291_1 = {&var1467,&var37,&internal1_m2291_tx};
_S_ovbsb  S_ovbsb_2290_1 = {&var1468,&var38,&internal1_m2290_tx};
_S_ovbsb  S_ovbsb_2289_1 = {&var1466,&var39,&internal1_m2289_tx};
_S_ovbsb  S_ovbsb_1228_1 = {&var1039,&var40,&internal1_m1228_tx};
_S_ovbsb  S_ovbsb_1227_1 = {&var1040,&var41,&internal1_m1227_tx};
_S_ovbsb  S_ovbsb_1222_1 = {&var1041,&var42,&internal1_m1222_tx};
_S_ovbsb  S_ovbsb_1215_1 = {&var1045,&var43,&internal1_m1215_tx};
_S_ovbsb  S_ovbsb_1213_1 = {&var1042,&var44,&internal1_m1213_tx};
_S_ovbsb  S_ovbsb_1211_1 = {&var1043,&var45,&internal1_m1211_tx};
_S_ovbsb  S_ovbsb_1209_1 = {&var1044,&var46,&internal1_m1209_tx};
_S_ovbsb  S_ovbsb_1252_1 = {&var1722,&var47,&internal1_m1252_tx};
_S_ovbsb  S_ovbsb_1259_1 = {&var1723,&var48,&internal1_m1259_tx};
_S_ovbsb  S_ovbsb_1264_1 = {&var1736,&var49,&internal1_m1264_tx};
_S_ovbsb  S_ovbsb_1270_1 = {&var1194,&var50,&internal1_m1270_tx};
_S_ovbsb  S_ovbsb_1230_1 = {&var1038,&var51,&internal1_m1230_tx};
_S_ovbsb  S_ovbsb_1251_1 = {&var1730,&var52,&internal1_m1251_tx};
_S_ovbsb  S_ovbsb_1265_1 = {&var1731,&var53,&internal1_m1265_tx};
_S_ovbsb  S_ovbsb_469_1 = {&var1160,&var54,&internal1_m469_tx};
_S_ovbsb  S_ovbsb_463_1 = {&var1159,&var55,&internal1_m463_tx};
_S_ovbsb  S_ovbsb_465_1 = {&var1158,&var56,&internal1_m465_tx};
_S_ovbsb  S_ovbsb_467_1 = {&var1157,&var57,&internal1_m467_tx};
_S_ovbsb  S_ovbsb_474_1 = {&var580,&var58,&internal1_m474_tx};
_S_ovbsb  S_ovbsb_428_1 = {&var1813,&var59,&internal1_m428_tx};
_S_ovbsb  S_ovbsb_426_1 = {&var1814,&var60,&internal1_m426_tx};
_S_ovbsb  S_ovbsb_427_1 = {&var1812,&var61,&internal1_m427_tx};
_S_ovbsb  S_ovbsb_420_1 = {&var1811,&var62,&internal1_m420_tx};
_S_ovbsb  S_ovbsb_882_1 = {&var1786,&var63,&internal1_m882_tx};
_S_ovbsb  S_ovbsb_881_1 = {&var1785,&var64,&internal1_m881_tx};
_S_ovbsb  S_ovbsb_880_1 = {&var1787,&var65,&internal1_m880_tx};
_S_ovbsb  S_ovbsb_876_1 = {&var1784,&var66,&internal1_m876_tx};
_S_ovbsb  S_ovbsb_1316_1 = {&var1767,&var67,&internal1_m1316_tx};
_S_ovbsb  S_ovbsb_1315_1 = {&var1768,&var68,&internal1_m1315_tx};
_S_ovbsb  S_ovbsb_1314_1 = {&var1766,&var69,&internal1_m1314_tx};
_S_ovbsb  S_ovbsb_1527_1 = {&var861,&var70,&internal1_m1527_tx};
_S_ovbsb  S_ovbsb_1540_1 = {&var854,&var71,&internal1_m1540_tx};
_S_ovbsb  S_ovbsb_1539_1 = {&var855,&var72,&internal1_m1539_tx};
_S_ovbsb  S_ovbsb_1538_1 = {&var858,&var73,&internal1_m1538_tx};
_S_ovbsb  S_ovbsb_1529_1 = {&var1129,&var74,&internal1_m1529_tx};
_S_ovbsb  S_ovbsb_2263_1 = {&var338,&var75,&internal1_m2263_tx};
_S_ovbsb  S_ovbsb_2246_1 = {&var356,&var76,&internal1_m2246_tx};
_S_ovbsb  S_ovbsb_2223_1 = {&var351,&var77,&internal1_m2223_tx};
_S_ovbsb  S_ovbsb_1537_1 = {&var859,&var78,&internal1_m1537_tx};
_S_ovbsb  S_ovbsb_1518_1 = {&var863,&var79,&internal1_m1518_tx};
_S_ovbsb  S_ovbsb_1517_1 = {&var864,&var80,&internal1_m1517_tx};
_S_ovbsb  S_ovbsb_1514_1 = {&var865,&var81,&internal1_m1514_tx};
_S_ovbsb  S_ovbsb_1536_1 = {&var860,&var82,&internal1_m1536_tx};
_S_ovbsb  S_ovbsb_1502_1 = {&var869,&var83,&internal1_m1502_tx};
_S_ovbsb  S_ovbsb_1504_1 = {&var868,&var84,&internal1_m1504_tx};
_S_ovbsb  S_ovbsb_1501_1 = {&var870,&var85,&internal1_m1501_tx};
_S_ovbsb  S_ovbsb_1474_1 = {&var1519,&var86,&internal1_m1474_tx};
_S_ovbsb  S_ovbsb_1473_1 = {&var1518,&var87,&internal1_m1473_tx};
_S_ovbsb  S_ovbsb_1482_1 = {&var1524,&var88,&internal1_m1482_tx};
_S_ovbsb  S_ovbsb_1486_1 = {&var1201,&var89,&internal1_m1486_tx};
_S_ovbsb  S_ovbsb_975_1 = {&var894,&var90,&internal1_m975_tx};
_S_ovbsb  S_ovbsb_978_1 = {&var893,&var91,&internal1_m978_tx};
_S_ovbsb  S_ovbsb_2214_1 = {&var550,&var92,&internal1_m2214_tx};
_S_ovbsb  S_ovbsb_968_1 = {&var1138,&var93,&internal1_m968_tx};
_S_ovbsb  S_ovbsb_966_1 = {&var1139,&var94,&internal1_m966_tx};
_S_ovbsb  S_ovbsb_974_1 = {&var895,&var95,&internal1_m974_tx};
_S_ovbsb  S_ovbsb_958_1 = {&var899,&var96,&internal1_m958_tx};
_S_ovbsb  S_ovbsb_955_1 = {&var898,&var97,&internal1_m955_tx};
_S_ovbsb  S_ovbsb_952_1 = {&var897,&var98,&internal1_m952_tx};
_S_ovbsb  S_ovbsb_973_1 = {&var896,&var99,&internal1_m973_tx};
_S_ovbsb  S_ovbsb_938_1 = {&var903,&var100,&internal1_m938_tx};
_S_ovbsb  S_ovbsb_939_1 = {&var902,&var101,&internal1_m939_tx};
_S_ovbsb  S_ovbsb_941_1 = {&var901,&var102,&internal1_m941_tx};
_S_ovbsb  S_ovbsb_627_1 = {&var945,&var103,&internal1_m627_tx};
_S_ovbsb  S_ovbsb_629_1 = {&var1114,&var104,&internal1_m629_tx};
_S_ovbsb  S_ovbsb_628_1 = {&var1113,&var105,&internal1_m628_tx};
_S_ovbsb  S_ovbsb_615_1 = {&var434,&var106,&internal1_m615_tx};
_S_ovbsb  S_ovbsb_614_1 = {&var1133,&var107,&internal1_m614_tx};
_S_ovbsb  S_ovbsb_611_1 = {&var1134,&var108,&internal1_m611_tx};
_S_ovbsb  S_ovbsb_624_1 = {&var943,&var109,&internal1_m624_tx};
_S_ovbsb  S_ovbsb_601_1 = {&var947,&var110,&internal1_m601_tx};
_S_ovbsb  S_ovbsb_600_1 = {&var948,&var111,&internal1_m600_tx};
_S_ovbsb  S_ovbsb_596_1 = {&var951,&var112,&internal1_m596_tx};
_S_ovbsb  S_ovbsb_625_1 = {&var944,&var113,&internal1_m625_tx};
_S_ovbsb  S_ovbsb_587_1 = {&var949,&var114,&internal1_m587_tx};
_S_ovbsb  S_ovbsb_583_1 = {&var955,&var115,&internal1_m583_tx};
_S_ovbsb  S_ovbsb_585_1 = {&var956,&var116,&internal1_m585_tx};
_S_ovbsb  S_ovbsb_563_1 = {&var1579,&var117,&internal1_m563_tx};
_S_ovbsb  S_ovbsb_564_1 = {&var1580,&var118,&internal1_m564_tx};
_S_ovbsb  S_ovbsb_565_1 = {&var1585,&var119,&internal1_m565_tx};
_S_ovbsb  S_ovbsb_570_1 = {&var958,&var120,&internal1_m570_tx};
_S_ovbsb  S_ovbsb_2274_1 = {&var1472,&var121,&internal1_m2274_tx};
_S_ovbsb  S_ovbsb_2275_1 = {&var1474,&var122,&internal1_m2275_tx};
_S_ovbsb  S_ovbsb_2276_1 = {&var1473,&var123,&internal1_m2276_tx};
_S_ovbsb  S_ovbsb_1745_1 = {&var721,&var124,&internal1_m1745_tx};
_S_ovbsb  S_ovbsb_1744_1 = {&var722,&var125,&internal1_m1744_tx};
_S_ovbsb  S_ovbsb_1739_1 = {&var724,&var126,&internal1_m1739_tx};
_S_ovbsb  S_ovbsb_1730_1 = {&var725,&var127,&internal1_m1730_tx};
_S_ovbsb  S_ovbsb_1728_1 = {&var726,&var128,&internal1_m1728_tx};
_S_ovbsb  S_ovbsb_1726_1 = {&var727,&var129,&internal1_m1726_tx};
_S_ovbsb  S_ovbsb_1725_1 = {&var728,&var130,&internal1_m1725_tx};
_S_ovbsb  S_ovbsb_1766_1 = {&var1711,&var131,&internal1_m1766_tx};
_S_ovbsb  S_ovbsb_1774_1 = {&var1712,&var132,&internal1_m1774_tx};
_S_ovbsb  S_ovbsb_1781_1 = {&var1719,&var133,&internal1_m1781_tx};
_S_ovbsb  S_ovbsb_1782_1 = {&var1193,&var134,&internal1_m1782_tx};
_S_ovbsb  S_ovbsb_1772_1 = {&var1714,&var135,&internal1_m1772_tx};
_S_ovbsb  S_ovbsb_1747_1 = {&var720,&var136,&internal1_m1747_tx};
_S_ovbsb  S_ovbsb_1761_1 = {&var1713,&var137,&internal1_m1761_tx};
_S_ovbsb  S_ovbsb_446_1 = {&var1162,&var138,&internal1_m446_tx};
_S_ovbsb  S_ovbsb_437_1 = {&var1148,&var139,&internal1_m437_tx};
_S_ovbsb  S_ovbsb_438_1 = {&var350,&var140,&internal1_m438_tx};
_S_ovbsb  S_ovbsb_440_1 = {&var1163,&var141,&internal1_m440_tx};
_S_ovbsb  S_ovbsb_454_1 = {&var1161,&var142,&internal1_m454_tx};
_S_ovbsb  S_ovbsb_404_1 = {&var1820,&var143,&internal1_m404_tx};
_S_ovbsb  S_ovbsb_401_1 = {&var1822,&var144,&internal1_m401_tx};
_S_ovbsb  S_ovbsb_400_1 = {&var1821,&var145,&internal1_m400_tx};
_S_ovbsb  S_ovbsb_399_1 = {&var1823,&var146,&internal1_m399_tx};
_S_ovbsb  S_ovbsb_859_1 = {&var1793,&var147,&internal1_m859_tx};
_S_ovbsb  S_ovbsb_855_1 = {&var1795,&var148,&internal1_m855_tx};
_S_ovbsb  S_ovbsb_854_1 = {&var1794,&var149,&internal1_m854_tx};
_S_ovbsb  S_ovbsb_853_1 = {&var1796,&var150,&internal1_m853_tx};
_S_ovbsb  S_ovbsb_1297_1 = {&var1775,&var151,&internal1_m1297_tx};
_S_ovbsb  S_ovbsb_1294_1 = {&var1776,&var152,&internal1_m1294_tx};
_S_ovbsb  S_ovbsb_1293_1 = {&var1777,&var153,&internal1_m1293_tx};
_S_ovbsb  S_ovbsb_1076_1 = {&var612,&var154,&internal1_m1076_tx};
_S_ovbsb  S_ovbsb_2229_1 = {&var357,&var155,&internal1_m2229_tx};
_S_ovbsb  S_ovbsb_1087_1 = {&var875,&var156,&internal1_m1087_tx};
_S_ovbsb  S_ovbsb_1089_1 = {&var873,&var157,&internal1_m1089_tx};
_S_ovbsb  S_ovbsb_1088_1 = {&var872,&var158,&internal1_m1088_tx};
_S_ovbsb  S_ovbsb_2231_1 = {&var352,&var159,&internal1_m2231_tx};
_S_ovbsb  S_ovbsb_1078_1 = {&var1131,&var160,&internal1_m1078_tx};
_S_ovbsb  S_ovbsb_2228_1 = {&var341,&var161,&internal1_m2228_tx};
_S_ovbsb  S_ovbsb_1086_1 = {&var876,&var162,&internal1_m1086_tx};
_S_ovbsb  S_ovbsb_1065_1 = {&var880,&var163,&internal1_m1065_tx};
_S_ovbsb  S_ovbsb_1064_1 = {&var884,&var164,&internal1_m1064_tx};
_S_ovbsb  S_ovbsb_1063_1 = {&var878,&var165,&internal1_m1063_tx};
_S_ovbsb  S_ovbsb_1085_1 = {&var877,&var166,&internal1_m1085_tx};
_S_ovbsb  S_ovbsb_1053_1 = {&var883,&var167,&internal1_m1053_tx};
_S_ovbsb  S_ovbsb_1051_1 = {&var885,&var168,&internal1_m1051_tx};
_S_ovbsb  S_ovbsb_1050_1 = {&var886,&var169,&internal1_m1050_tx};
_S_ovbsb  S_ovbsb_1029_1 = {&var1550,&var170,&internal1_m1029_tx};
_S_ovbsb  S_ovbsb_1028_1 = {&var1551,&var171,&internal1_m1028_tx};
_S_ovbsb  S_ovbsb_1018_1 = {&var1556,&var172,&internal1_m1018_tx};
_S_ovbsb  S_ovbsb_1035_1 = {&var1202,&var173,&internal1_m1035_tx};
_S_ovbsb  S_ovbsb_1432_1 = {&var832,&var174,&internal1_m1432_tx};
_S_ovbsb  S_ovbsb_1431_1 = {&var833,&var175,&internal1_m1431_tx};
_S_ovbsb  S_ovbsb_2181_1 = {&var551,&var176,&internal1_m2181_tx};
_S_ovbsb  S_ovbsb_1423_1 = {&var836,&var177,&internal1_m1423_tx};
_S_ovbsb  S_ovbsb_1424_1 = {&var837,&var178,&internal1_m1424_tx};
_S_ovbsb  S_ovbsb_1430_1 = {&var834,&var179,&internal1_m1430_tx};
_S_ovbsb  S_ovbsb_1412_1 = {&var842,&var180,&internal1_m1412_tx};
_S_ovbsb  S_ovbsb_1411_1 = {&var840,&var181,&internal1_m1411_tx};
_S_ovbsb  S_ovbsb_1408_1 = {&var838,&var182,&internal1_m1408_tx};
_S_ovbsb  S_ovbsb_1429_1 = {&var835,&var183,&internal1_m1429_tx};
_S_ovbsb  S_ovbsb_1394_1 = {&var843,&var184,&internal1_m1394_tx};
_S_ovbsb  S_ovbsb_1393_1 = {&var841,&var185,&internal1_m1393_tx};
_S_ovbsb  S_ovbsb_1396_1 = {&var839,&var186,&internal1_m1396_tx};
_S_ovbsb  S_ovbsb_244_1 = {&var435,&var187,&internal1_m244_tx};
_S_ovbsb  S_ovbsb_259_1 = {&var921,&var188,&internal1_m259_tx};
_S_ovbsb  S_ovbsb_266_1 = {&var920,&var189,&internal1_m266_tx};
_S_ovbsb  S_ovbsb_265_1 = {&var922,&var190,&internal1_m265_tx};
_S_ovbsb  S_ovbsb_252_1 = {&var1136,&var191,&internal1_m252_tx};
_S_ovbsb  S_ovbsb_247_1 = {&var1137,&var192,&internal1_m247_tx};
_S_ovbsb  S_ovbsb_263_1 = {&var918,&var193,&internal1_m263_tx};
_S_ovbsb  S_ovbsb_235_1 = {&var927,&var194,&internal1_m235_tx};
_S_ovbsb  S_ovbsb_234_1 = {&var925,&var195,&internal1_m234_tx};
_S_ovbsb  S_ovbsb_230_1 = {&var924,&var196,&internal1_m230_tx};
_S_ovbsb  S_ovbsb_262_1 = {&var923,&var197,&internal1_m262_tx};
_S_ovbsb  S_ovbsb_219_1 = {&var931,&var198,&internal1_m219_tx};
_S_ovbsb  S_ovbsb_221_1 = {&var929,&var199,&internal1_m221_tx};
_S_ovbsb  S_ovbsb_218_1 = {&var930,&var200,&internal1_m218_tx};
_S_ovbsb  S_ovbsb_197_1 = {&var1616,&var201,&internal1_m197_tx};
_S_ovbsb  S_ovbsb_196_1 = {&var1617,&var202,&internal1_m196_tx};
_S_ovbsb  S_ovbsb_195_1 = {&var1618,&var203,&internal1_m195_tx};
_S_ovbsb  S_ovbsb_203_1 = {&var938,&var204,&internal1_m203_tx};
_S_ovbsb  S_ovbsb_1375_1 = {&var1706,&var205,&internal1_m1375_tx};
_S_ovbsb  S_ovbsb_1357_1 = {&var1701,&var206,&internal1_m1357_tx};
_S_ovbsb  S_ovbsb_1362_1 = {&var1700,&var207,&internal1_m1362_tx};
_S_ovbsb  S_ovbsb_1378_1 = {&var1203,&var208,&internal1_m1378_tx};
_S_ovbsb  S_ovbsb_918_1 = {&var1663,&var209,&internal1_m918_tx};
_S_ovbsb  S_ovbsb_923_1 = {&var911,&var210,&internal1_m923_tx};
_S_ovbsb  S_ovbsb_913_1 = {&var910,&var211,&internal1_m913_tx};
_S_ovbsb  S_ovbsb_914_1 = {&var909,&var212,&internal1_m914_tx};
_S_or3  S_or3_2504_1 = {&var213,&var216,&var217,&vainSBool};
_S_orn  S_orn_2503_1 = {array_m2503_x_1,&iRM_6_,&var213};
_S_or2  S_or2_2508_1 = {&R0DEB3LDU,&R0DEB4LDU,&var214};
_S_or2  S_or2_2501_1 = {&R0DEB1LDU,&R0DEB2LDU,&var215};
_S_and2  S_and2_2492_1 = {&R0DE31LDU,&R0DE32LDU,&var216};
_S_diagndev  S_diagndev_2487_1 = {array_m2487_x_1,&iRM_12_,&var217,&var218};
_S_or2  S_or2_1867_1 = {&var454,&var267,&var219};
_S_and2  S_and2_1857_1 = {&var510,&var1415,&var220};
_S_rs  S_rs_1866_1 = {&var219,&var220,&var221,&vainSBool,&internal1_m1866_q0};
_S_or2  S_or2_1861_1 = {&var510,&var457,&var222};
_S_or2  S_or2_1804_1 = {&var1465,&var510,&var223};
_S_or2  S_or2_1832_1 = {&var509,&var267,&var224};
_S_or2  S_or2_1834_1 = {&var337,&var267,&var225};
_S_or2  S_or2_2323_1 = {&var454,&var263,&var226};
_S_or2  S_or2_2321_1 = {&var263,&var461,&var227};
_S_or2  S_or2_2319_1 = {&var276,&var263,&var228};
_S_and2  S_and2_2302_1 = {&var1412,&var508,&var229};
_S_or2  S_or2_2317_1 = {&var508,&var263,&var230};
_S_noto  S_noto_2325_1 = {&B3IS11LDU,&var231};
_S_or2  S_or2_2352_1 = {&var267,&var461,&var232};
_S_and2  S_and2_2332_1 = {&var1412,&var509,&var233};
_S_noto  S_noto_2356_1 = {&A3IS11LDU,&var234};
_S_or2  S_or2_2354_1 = {&var454,&var267,&var235};
_S_or2  S_or2_2350_1 = {&var267,&var277,&var236};
_S_or2  S_or2_2348_1 = {&var267,&var509,&var237};
_S_or2  S_or2_1812_1 = {&var454,&var267,&var238};
_S_or2  S_or2_1816_1 = {&var454,&var263,&var239};
_S_or2  S_or2_1807_1 = {&var510,&var1465,&var240};
_S_or2  S_or2_1842_1 = {&var263,&var336,&var241};
_S_or2  S_or2_1840_1 = {&var508,&var263,&var242};
_S_or2  S_or2_1883_1 = {&var461,&var263,&var243};
_S_or2  S_or2_1880_1 = {&var461,&var267,&var244};
_S_or2  S_or2_1912_1 = {&var467,&var263,&var245};
_S_or2  S_or2_1909_1 = {&var467,&var267,&var246};
_S_or2  S_or2_1869_1 = {&var454,&var263,&var247};
_S_or2  S_or2_1836_1 = {&var454,&var267,&var248};
_S_or2  S_or2_1844_1 = {&var454,&var263,&var249};
_S_or3  S_or3_2313_1 = {&var461,&var508,&var263,&var250};
_S_or3  S_or3_2315_1 = {&var511,&var508,&var263,&var251};
_S_or3  S_or3_2346_1 = {&var267,&var512,&var509,&var252};
_S_or3  S_or3_2344_1 = {&var461,&var267,&var509,&var253};
_S_or3  S_or3_2311_1 = {&var508,&var454,&var263,&var254};
_S_or3  S_or3_2342_1 = {&var454,&var509,&var267,&var255};
_S_or3  S_or3_1810_1 = {&var454,&var509,&var267,&var256};
_S_or3  S_or3_1814_1 = {&var508,&var454,&var263,&var257};
_S_or3  S_or3_1830_1 = {&var454,&var509,&var267,&var258};
_S_or3  S_or3_1838_1 = {&var454,&var508,&var263,&var259};
_S_or3  S_or3_1865_1 = {&var454,&var510,&var263,&var260};
_S_or3  S_or3_1863_1 = {&var454,&var267,&var510,&var261};
_S_or3  S_or3_1911_1 = {&var263,&var508,&var467,&var262};
_S_noto  S_noto_1906_1 = {&var1120,&var263};
_S_or3  S_or3_1882_1 = {&var263,&var461,&var508,&var264};
_S_or3  S_or3_1879_1 = {&var461,&var267,&var509,&var265};
_S_or3  S_or3_1908_1 = {&var467,&var267,&var509,&var266};
_S_noto  S_noto_1903_1 = {&var1119,&var267};
_S_regch  S_regch_126_1 = {&R0MW12IP1,&var1109,&var268};
_S_or2  S_or2_129_1 = {&var270,&var268,&var269};
_S_or2  S_or2_128_1 = {&R0VZ71LZ1,&R0VZ71LZ2,&var270};
_S_and3  S_and3_1563_1 = {&R0MD11LP2,&var1168,&var274,&var271};
_S_and2  S_and2_806_1 = {&R4MD21LP2,&var274,&var272};
_S_and2  S_and2_803_1 = {&R4MD11LP2,&var274,&var273};
_S_noto  S_noto_108_1 = {&var1842,&var274};
_S_and2  S_and2_106_1 = {&R0MD11LP1,&var274,&var275};
_S_noto  S_noto_2326_1 = {&B3IS22LDU,&var276};
_S_noto  S_noto_2357_1 = {&A3IS22LDU,&var277};
_S_and2  S_and2_2244_1 = {&var685,&var1394,&var278};
_S_or3  S_or3_2237_1 = {&var684,&var380,&var318,&var279};
_S_and2  S_and2_2226_1 = {&var681,&var1394,&var280};
_S_or3  S_or3_2222_1 = {&var380,&var682,&var301,&var281};
_S_or2  S_or2_1628_1 = {&var1483,&var1412,&var282};
_S_or2  S_or2_1597_1 = {&var1340,&var1412,&var283};
_S_rs  S_rs_2316_1 = {&var230,&var287,&var284,&vainSBool,&internal1_m2316_q0};
_S_rs  S_rs_2300_1 = {&var231,&var306,&var285,&vainSBool,&internal1_m2300_q0};
_S_noto  S_noto_2324_1 = {&var1934,&var286};
_S_and2  S_and2_2307_1 = {&var286,&var285,&var287};
_S_rs  S_rs_2347_1 = {&var237,&var290,&var288,&vainSBool,&internal1_m2347_q0};
_S_noto  S_noto_2355_1 = {&var1937,&var289};
_S_and2  S_and2_2338_1 = {&var291,&var289,&var290};
_S_rs  S_rs_2331_1 = {&var234,&var324,&var291,&vainSBool,&internal1_m2331_q0};
_S_and4  S_and4_1508_1 = {&var1168,&var1412,&var472,&var1457,&var292};
_S_and4  S_and4_1057_1 = {&var1168,&var1412,&var472,&var1457,&var293};
_S_rs  S_rs_2322_1 = {&var226,&var299,&var294,&vainSBool,&internal1_m2322_q0};
_S_or4  S_or4_1438_1 = {&var804,&var494,&var1207,&var301,&var295};
_S_or4  S_or4_1447_1 = {&var369,&var497,&var980,&var307,&var296};
_S_orn  S_orn_887_1 = {array_m887_x_1,&iRM_6_,&var297};
_S_or3  S_or3_899_1 = {&var999,&var1408,&var310,&var298};
_S_and2  S_and2_2309_1 = {&var461,&var300,&var299};
_S_rs  S_rs_2303_1 = {&var226,&var302,&var300,&vainSBool,&internal1_m2303_q0};
_S_rs  S_rs_2320_1 = {&var227,&var302,&var301,&vainSBool,&internal1_m2320_q0};
_S_and2  S_and2_2308_1 = {&var303,&var276,&var302};
_S_rs  S_rs_2301_1 = {&var227,&var229,&var303,&vainSBool,&internal1_m2301_q0};
_S_rs  S_rs_2299_1 = {&var286,&var308,&var304,&vainSBool,&internal1_m2299_q0};
_S_rs  S_rs_2298_1 = {&var250,&var309,&var305,&vainSBool,&internal1_m2298_q0};
_S_and2  S_and2_2306_1 = {&var461,&var304,&var306};
_S_rs  S_rs_2312_1 = {&var250,&var308,&var307,&vainSBool,&internal1_m2312_q0};
_S_and2  S_and2_2305_1 = {&var305,&var454,&var308};
_S_and2  S_and2_2304_1 = {&var511,&var1412,&var309};
_S_rs  S_rs_2310_1 = {&var254,&var309,&var310,&vainSBool,&internal1_m2310_q0};
_S_rs  S_rs_2318_1 = {&var228,&var229,&var311,&vainSBool,&internal1_m2318_q0};
_S_rs  S_rs_2314_1 = {&var251,&var306,&var312,&vainSBool,&internal1_m2314_q0};
_S_orn  S_orn_1326_1 = {array_m1326_x_1,&iRM_6_,&var313};
_S_rs  S_rs_2353_1 = {&var235,&var315,&var314,&vainSBool,&internal1_m2353_q0};
_S_and2  S_and2_2340_1 = {&var461,&var316,&var315};
_S_rs  S_rs_2334_1 = {&var235,&var319,&var316,&vainSBool,&internal1_m2334_q0};
_S_or4  S_or4_982_1 = {&var803,&var498,&var1207,&var318,&var317};
_S_rs  S_rs_2351_1 = {&var232,&var319,&var318,&vainSBool,&internal1_m2351_q0};
_S_and2  S_and2_2339_1 = {&var320,&var277,&var319};
_S_rs  S_rs_2333_1 = {&var232,&var233,&var320,&vainSBool,&internal1_m2333_q0};
_S_rs  S_rs_2330_1 = {&var289,&var327,&var321,&vainSBool,&internal1_m2330_q0};
_S_or4  S_or4_991_1 = {&var1405,&var369,&var990,&var325,&var322};
_S_rs  S_rs_2329_1 = {&var253,&var328,&var323,&vainSBool,&internal1_m2329_q0};
_S_and2  S_and2_2337_1 = {&var461,&var321,&var324};
_S_rs  S_rs_2343_1 = {&var253,&var327,&var325,&vainSBool,&internal1_m2343_q0};
_S_or3  S_or3_1338_1 = {&var998,&var1410,&var329,&var326};
_S_and2  S_and2_2336_1 = {&var323,&var454,&var327};
_S_and2  S_and2_2335_1 = {&var512,&var1412,&var328};
_S_rs  S_rs_2341_1 = {&var255,&var328,&var329,&vainSBool,&internal1_m2341_q0};
_S_or2  S_or2_2204_1 = {&var371,&var1239,&var330};
_S_ovbs  S_ovbs_2206_1 = {&var430,&fRM_2_0,&var331,&internal1_m2206_tx};
_S_or2  S_or2_2207_1 = {&var1421,&var331,&var332};
_S_ovbs  S_ovbs_2185_1 = {&var431,&fRM_2_0,&var333,&internal1_m2185_tx};
_S_or2  S_or2_2183_1 = {&var372,&var1240,&var334};
_S_or2  S_or2_2186_1 = {&var1441,&var333,&var335};
_S_noto  S_noto_1846_1 = {&B2IS21LDU,&var336};
_S_noto  S_noto_1845_1 = {&A2IS21LDU,&var337};
_S_and2  S_and2_2264_1 = {&var1934,&var686,&var338};
_S_or5  S_or5_2267_1 = {&var861,&var1851,&var355,&var311,&var338,&var339};
_S_or5  S_or5_2266_1 = {&var612,&var1403,&var688,&var1851,&var341,&var340};
_S_and2  S_and2_2239_1 = {&var1937,&var687,&var341};
_S_nocnm  S_nocnm_1889_1 = {&R5IS21LDU,&R5IS11LDU,&var342,&var343,&var344,&internal1_m1889_Pv0,&internal1_m1889_Zv0,&internal1_m1889_MyFirstEnterFlag,&bFirstEnterFlag};
_S_nocnm  S_nocnm_1887_1 = {&R3IS11LDU,&R3IS21LDU,&var345,&var346,&var347,&internal1_m1887_Pv0,&internal1_m1887_Zv0,&internal1_m1887_MyFirstEnterFlag,&bFirstEnterFlag};
_S_or5  S_or5_2153_1 = {&var1203,&var911,&C2MD31LP1,&var1202,&var1201,&var348};
_S_or4  S_or4_2128_1 = {&C1MD31LP2,&C1MD31LP1,&var938,&var958,&var349};
_S_and3  S_and3_443_1 = {&B8IS22LDU,&B8IS21LDU,&var1824,&var350};
_S_and2  S_and2_2224_1 = {&var680,&var380,&var351};
_S_and2  S_and2_2232_1 = {&var683,&var380,&var352};
_S_or4  S_or4_1098_1 = {&var1530,&var873,&var872,&var875,&var353};
_S_or4  S_or4_1550_1 = {&var1498,&var855,&var854,&var858,&var354};
_S_and2  S_and2_2268_1 = {&var601,&var1394,&var355};
_S_and2  S_and2_2253_1 = {&var686,&var1851,&var356};
_S_and2  S_and2_2240_1 = {&var687,&var1851,&var357};
_S_or2  S_or2_607_1 = {&B1VP41LZ2,&B1VP41LZ1,&var358};
_S_or2  S_or2_241_1 = {&A1VP41LZ2,&A1VP41LZ1,&var359};
_S_or2  S_or2_1241_1 = {&B8IS22LDU,&B8IS21LDU,&var360};
_S_or2  S_or2_1237_1 = {&B8IS11LDU,&B8IS12LDU,&var361};
_S_or2  S_or2_369_1 = {&R4IS11LDU,&R4IS12LDU,&var362};
_S_or2  S_or2_382_1 = {&R4IS21LDU,&R4IS22LDU,&var363};
_S_or2  S_or2_1188_1 = {&var1210,&R0MD34LP1,&var364};
_S_or2  S_or2_1191_1 = {&var1208,&R0MD34LP1,&var365};
_S_or2  S_or2_1194_1 = {&var1206,&R0MD34LP1,&var366};
_S_or2  S_or2_1197_1 = {&var1204,&R0MD34LP1,&var367};
_S_noto  S_noto_2382_1 = {&var1851,&var368};
_S_zzfs  S_zzfs_2371_1 = {&var386,&fRM_0_5,&var369,&internal1_m2371_tx,&internal1_m2371_y0};
_S_or2  S_or2_2405_1 = {&var562,&var1212,&var370};
_S_andn  S_andn_655_1 = {array_m655_x_1,&iRM_6_,&var371};
_S_andn  S_andn_654_1 = {array_m654_x_1,&iRM_6_,&var372};
_S_or2  S_or2_2421_1 = {&var888,&var853,&var373};
_S_noto  S_noto_2367_1 = {&var1238,&var374};
_S_noto  S_noto_2366_1 = {&var1235,&var375};
_S_zpfs  S_zpfs_2375_1 = {&var374,&fRM_30_0,&var376,&internal1_m2375_tx,&internal1_m2375_y0};
_S_noto  S_noto_2380_1 = {&var376,&var377};
_S_zpfs  S_zpfs_2374_1 = {&var375,&fRM_30_0,&var378,&internal1_m2374_tx,&internal1_m2374_y0};
_S_noto  S_noto_2379_1 = {&var378,&var379};
_S_and3  S_and3_2373_1 = {&var419,&var399,&lRM_1_,&var380};
_S_and2  S_and2_1010_1 = {&var1556,&var382,&var381};
_S_noto  S_noto_997_1 = {&var369,&var382};
_S_and2  S_and2_1464_1 = {&var1524,&var384,&var383};
_S_noto  S_noto_1461_1 = {&var369,&var384};
_S_or2  S_or2_2415_1 = {&var395,&var396,&var385};
_S_and2  S_and2_2370_1 = {&var387,&var380,&var386};
_S_abs_subf  S_abs_subf_2362_1 = {&var1950,&var420,&fEM_A3UC08RDU,&vainSFloat,&var387};
_S_and2  S_and2_2417_1 = {&var380,&var395,&var388};
_S_or4  S_or4_2154_1 = {&var348,&var1016,&var1126,&var388,&var389};
_S_noto  S_noto_2420_1 = {&var373,&var390};
_S_or2  S_or2_2397_1 = {&var413,&var424,&var391};
_S_inf  S_inf_2392_1 = {&var422,array_m2392_a_1,array_m2392_b_1,&iRM_6_,&var392,&vainSInt};
_S_or3  S_or3_2419_1 = {&var409,&var416,&var417,&var393};
_S_noto  S_noto_2418_1 = {&var393,&var394};
_S_noto  S_noto_2416_1 = {&var419,&var395};
_S_ovbs  S_ovbs_2411_1 = {&var398,&fRM_15_0,&var396,&internal1_m2411_tx};
_S_zpfs  S_zpfs_2409_1 = {&var399,&fRM_10_0,&var397,&internal1_m2409_tx,&internal1_m2409_y0};
_S_and2  S_and2_2410_1 = {&var397,&R0MW17LP1,&var398};
_S_rs  S_rs_2414_1 = {&var385,&R0MW17LP1,&var399,&vainSBool,&internal1_m2414_q0};
_S_rs  S_rs_2381_1 = {&var413,&var380,&var400,&vainSBool,&internal1_m2381_q0};
_S_and3  S_and3_2388_1 = {&var415,&var368,&var400,&var401};
_S_ml  S_ml_1444_1 = {&var420,&var522,&var369,&var402};
_S_ml  S_ml_988_1 = {&var420,&var526,&var369,&var403};
_S_and2  S_and2_2444_1 = {&var380,&var539,&var404};
_S_noto  S_noto_2401_1 = {&var370,&var405};
_S_noto  S_noto_2386_1 = {&var1495,&var406};
_S_sr  S_sr_2402_1 = {array_m2402_x_1,&iRM_4_,&var407};
_S_sr  S_sr_2425_1 = {array_m2425_x_1,&iRM_2_,&var408};
_S_and2  S_and2_2442_1 = {&var410,&var380,&var409};
_S_abs_subf  S_abs_subf_2437_1 = {&B3MC01RP1,&A3MC01RP1,&fRM_0_01,&vainSFloat,&var410};
_S_fsumo  S_fsumo_80_1 = {&var1188,&fEM_R0UN11RDU,&var411};
_S_or3  S_or3_127_1 = {&var349,&var269,&var391,&var412};
_S_ovbs  S_ovbs_2389_1 = {&var401,&fRM_1_0,&var413,&internal1_m2389_tx};
_S_noto  S_noto_2396_1 = {&var391,&var414};
_S_rs  S_rs_2387_1 = {&var413,&var1851,&var415,&vainSBool,&internal1_m2387_q0};
_S_and2  S_and2_2440_1 = {&var424,&var380,&var416};
_S_and2  S_and2_2439_1 = {&var418,&var380,&var417};
_S_bol  S_bol_2428_1 = {&fEM_R0UN09RDU,&var408,&var418};
_S_andn  S_andn_2394_1 = {array_m2394_x_1,&iRM_14_,&var419};
_S_irm  S_irm_2369_1 = {&var1188,&var1186,&B3MC01RP1,&var1950,&var408,&var407,&var380,&var1212,&fEM_R0UN12RDU,&fEM_R0UN13RDU,&fEM_R0UN14RDU,&fEM_R0UT20RDU,&var392,&fEM_R0UN15RDU,&fEM_R0UN25RDU,&fEM_R0UN16RDU,&fEM_R0UN17RDU,&fEM_R0UN18RDU,&fEM_R0UN19RDU,&fEM_R0UN27RDU,&fEM_R0UN26RDU,&fEM_R0UN24RDU,&var420,&var421,&var422,&var423,&var424,&var425,&var426,&var427};
_S_noto  S_noto_2213_1 = {&var550,&var428};
_S_noto  S_noto_2182_1 = {&var551,&var429};
_S_and4  S_and4_2205_1 = {&var573,&var330,&var543,&var428,&var430};
_S_and4  S_and4_2184_1 = {&var574,&var334,&var543,&var429,&var431};
_S_zpfs  S_zpfs_2200_1 = {&var557,&fRM_210_0,&var432,&internal1_m2200_tx,&internal1_m2200_y0};
_S_zpfs  S_zpfs_2192_1 = {&var558,&fRM_210_0,&var433,&internal1_m2192_tx,&internal1_m2192_y0};
_S_and2  S_and2_610_1 = {&var1571,&var606,&var434};
_S_and2  S_and2_245_1 = {&var606,&var1604,&var435};
_S_noto  S_noto_1718_1 = {&var437,&var436};
_S_abs_subf  S_abs_subf_1709_1 = {&var1947,&var522,&fEM_A3UC07RDU,&vainSFloat,&var437};
_S_noto  S_noto_1698_1 = {&var439,&var438};
_S_abs_subf  S_abs_subf_1688_1 = {&var526,&var1950,&fEM_A3UC07RDU,&vainSFloat,&var439};
_S_noto  S_noto_1713_1 = {&var441,&var440};
_S_abs_subf  S_abs_subf_1707_1 = {&var530,&var1960,&fEM_A1UC07RDU,&vainSFloat,&var441};
_S_noto  S_noto_1696_1 = {&var443,&var442};
_S_abs_subf  S_abs_subf_1686_1 = {&var534,&var1938,&fEM_A1UC07RDU,&vainSFloat,&var443};
_S_bol  S_bol_1460_1 = {&var1947,&fEM_A3UC09RDU,&var444};
_S_bol  S_bol_1007_1 = {&var1950,&fEM_A3UC09RDU,&var445};
_S_noto  S_noto_1953_1 = {&var450,&var446};
_S_noto  S_noto_1942_1 = {&var448,&var447};
_S_and3  S_and3_1935_1 = {&var1120,&var449,&var1412,&var448};
_S_bol  S_bol_1927_1 = {&fRM_55_0,&var522,&var449};
_S_and3  S_and3_1954_1 = {&var451,&var1119,&var1412,&var450};
_S_bol  S_bol_1963_1 = {&fRM_55_0,&var526,&var451};
_S_and4  S_and4_45_1 = {&var1842,&var1118,&var1297,&var1394,&var452};
_S_noto  S_noto_1360_1 = {&var1168,&var453};
_S_and2  S_and2_1364_1 = {&var1671,&var1168,&var454};
_S_and2  S_and2_1361_1 = {&var1671,&var453,&var455};
_S_noto  S_noto_1303_1 = {&var1168,&var456};
_S_and2  S_and2_1310_1 = {&var1168,&var1745,&var457};
_S_and2  S_and2_1304_1 = {&var1745,&var456,&var458};
_S_noto  S_noto_1014_1 = {&var1168,&var459};
_S_and2  S_and2_1015_1 = {&var459,&var1527,&var460};
_S_and2  S_and2_1012_1 = {&var1527,&var1168,&var461};
_S_noto  S_noto_507_1 = {&var1168,&var462};
_S_and2  S_and2_508_1 = {&var462,&var1620,&var463};
_S_and2  S_and2_511_1 = {&var1620,&var1168,&var464};
_S_noto  S_noto_188_1 = {&var1168,&var465};
_S_and2  S_and2_189_1 = {&var465,&var1590,&var466};
_S_and2  S_and2_191_1 = {&var1168,&var1590,&var467};
_S_and2  S_and2_122_1 = {&var470,&var595,&var468};
_S_and2  S_and2_123_1 = {&var1168,&var595,&var469};
_S_noto  S_noto_117_1 = {&var1168,&var470};
_S_and2  S_and2_118_1 = {&var470,&var594,&var471};
_S_and2  S_and2_119_1 = {&var1168,&var594,&var472};
_S_and2  S_and2_1802_1 = {&var508,&var1416,&var473};
_S_and2  S_and2_1801_1 = {&var511,&var1416,&var474};
_S_and2  S_and2_1800_1 = {&var509,&var1416,&var475};
_S_and2  S_and2_1799_1 = {&var1416,&var512,&var476};
_S_and2  S_and2_1798_1 = {&var729,&var510,&var477};
_S_and2  S_and2_1797_1 = {&var729,&var513,&var478};
_S_and2  S_and2_1796_1 = {&var730,&var510,&var479};
_S_and2  S_and2_1795_1 = {&var730,&var513,&var480};
_S_and2  S_and2_1828_1 = {&var241,&var1373,&var481};
_S_and2  S_and2_1827_1 = {&var508,&var1417,&var482};
_S_and2  S_and2_1826_1 = {&var1374,&var454,&var483};
_S_and2  S_and2_1825_1 = {&var1417,&var511,&var484};
_S_and2  S_and2_1824_1 = {&var337,&var1375,&var485};
_S_and2  S_and2_1823_1 = {&var1417,&var509,&var486};
_S_and2  S_and2_1822_1 = {&var1376,&var454,&var487};
_S_and2  S_and2_1821_1 = {&var1417,&var512,&var488};
_S_and2  S_and2_1859_1 = {&var454,&var1377,&var489};
_S_and2  S_and2_1858_1 = {&var510,&var1415,&var490};
_S_and2  S_and2_1856_1 = {&var1378,&var457,&var491};
_S_and2  S_and2_1855_1 = {&var1379,&var457,&var492};
_S_and2  S_and2_1854_1 = {&var513,&var1415,&var493};
_S_rs  S_rs_1876_1 = {&var243,&var495,&var494,&vainSBool,&internal1_m1876_q0};
_S_and2  S_and2_1875_1 = {&var1413,&var508,&var495};
_S_and2  S_and2_1874_1 = {&var1413,&var511,&var496};
_S_rs  S_rs_1881_1 = {&var264,&var496,&var497,&vainSBool,&internal1_m1881_q0};
_S_rs  S_rs_1873_1 = {&var244,&var499,&var498,&vainSBool,&internal1_m1873_q0};
_S_and2  S_and2_1872_1 = {&var509,&var1413,&var499};
_S_and2  S_and2_1871_1 = {&var1413,&var512,&var500};
_S_and2  S_and2_1902_1 = {&var510,&var1844,&var501};
_S_rs  S_rs_1915_1 = {&var464,&var501,&var502,&vainSBool,&internal1_m1915_q0};
_S_and2  S_and2_1901_1 = {&var1844,&var513,&var503};
_S_and2  S_and2_1900_1 = {&var508,&var1401,&var504};
_S_and2  S_and2_1899_1 = {&var1401,&var511,&var505};
_S_and2  S_and2_1898_1 = {&var509,&var1401,&var506};
_S_and2  S_and2_1897_1 = {&var1401,&var512,&var507};
_S_and2  S_and2_1917_1 = {&var1120,&var510,&var508};
_S_and2  S_and2_1896_1 = {&var1119,&var510,&var509};
_S_and2  S_and2_1919_1 = {&var469,&var1457,&var510};
_S_and2  S_and2_1916_1 = {&var513,&var1120,&var511};
_S_and2  S_and2_1895_1 = {&var513,&var1119,&var512};
_S_and2  S_and2_1918_1 = {&var472,&var1457,&var513};
_S_zpfs  S_zpfs_823_1 = {&var1084,&fRM_3_,&var514,&internal1_m823_tx,&internal1_m823_y0};
_S_or4  S_or4_1732_1 = {&var720,&var721,&var722,&var724,&var515};
_S_or5  S_or5_1719_1 = {&var728,&var727,&var726,&var725,&var515,&var516};
_S_andn  S_andn_1_1 = {array_m1_x_1,&iRM_47_,&vainSBool};
_S_or2  S_or2_1700_1 = {&var519,&var520,&var517};
_S_ml  S_ml_1685_1 = {&fRM_1500_0,&B8MC01RP2,&var517,&var518};
_S_bol  S_bol_1693_1 = {&B8MC01RP2,&fRM_1500_0001,&var519};
_S_bol  S_bol_1702_1 = {&fRM_389_99,&B8MC01RP2,&var520};
_S_or2  S_or2_1716_1 = {&var523,&var524,&var521};
_S_ml  S_ml_1706_1 = {&fRM_0_0,&B3MC01RP1,&var521,&var522};
_S_bol  S_bol_1708_1 = {&B3MC01RP1,&fRM_160_00001,&var523};
_S_bol  S_bol_1717_1 = {&fRM_0_0001,&B3MC01RP1,&var524};
_S_or2  S_or2_1692_1 = {&var527,&var528,&var525};
_S_ml  S_ml_1684_1 = {&fRM_0_0,&A3MC01RP1,&var525,&var526};
_S_bol  S_bol_1687_1 = {&A3MC01RP1,&fRM_160_0001,&var527};
_S_bol  S_bol_1697_1 = {&fRM_0_0001,&A3MC01RP1,&var528};
_S_or2  S_or2_1712_1 = {&var531,&var532,&var529};
_S_ml  S_ml_1704_1 = {&fRM_100_0,&B1MC01RP1,&var529,&var530};
_S_bol  S_bol_1710_1 = {&B1MC01RP1,&fRM_100_0001,&var531};
_S_bol  S_bol_1714_1 = {&fRM_0_0001,&B1MC01RP1,&var532};
_S_or2  S_or2_1695_1 = {&var535,&var536,&var533};
_S_ml  S_ml_1682_1 = {&fRM_100_0,&A1MC01RP1,&var533,&var534};
_S_bol  S_bol_1690_1 = {&A1MC01RP1,&fRM_100_0001,&var535};
_S_bol  S_bol_1701_1 = {&fRM_0_0001,&A1MC01RP1,&var536};
_S_and2  S_and2_103_1 = {&var275,&var362,&var537};
_S_noto  S_noto_104_1 = {&var362,&var538};
_S_and2  S_and2_107_1 = {&var275,&var538,&var539};
_S_and2  S_and2_2170_1 = {&var541,&var542,&var540};
_S_or3  S_or3_2169_1 = {&var1419,&var673,&var389,&var541};
_S_noto  S_noto_2208_1 = {&var332,&var542};
_S_noto  S_noto_2197_1 = {&var544,&var543};
_S_ovbs  S_ovbs_2196_1 = {&var1309,&fRM_2_0,&var544,&internal1_m2196_tx};
_S_noto  S_noto_2187_1 = {&var335,&var545};
_S_and2  S_and2_2156_1 = {&var547,&var545,&var546};
_S_or3  S_or3_2155_1 = {&var389,&var1423,&var673,&var547};
_S_noto  S_noto_2202_1 = {&var555,&var548};
_S_and2  S_and2_2203_1 = {&var1394,&var548,&var549};
_S_and2  S_and2_2211_1 = {&var549,&var330,&var550};
_S_and2  S_and2_2190_1 = {&var552,&var334,&var551};
_S_and2  S_and2_2195_1 = {&var553,&var1394,&var552};
_S_noto  S_noto_2194_1 = {&var1111,&var553};
_S_noto  S_noto_2210_1 = {&var557,&var554};
_S_or2  S_or2_2201_1 = {&var432,&var554,&var555};
_S_noto  S_noto_2189_1 = {&var558,&var556};
_S_rs  S_rs_2199_1 = {&var432,&var563,&var557,&vainSBool,&internal1_m2199_q0};
_S_rs  S_rs_2191_1 = {&var433,&var564,&var558,&vainSBool,&internal1_m2191_q0};
_S_and2  S_and2_2179_1 = {&var561,&var568,&var559};
_S_and2  S_and2_2167_1 = {&var561,&var565,&var560};
_S_noto  S_noto_2161_1 = {&var562,&var561};
_S_ovbs  S_ovbs_2160_1 = {&var389,&fRM_10_0,&var562,&internal1_m2160_tx};
_S_ovbs  S_ovbs_2171_1 = {&var540,&fRM_2_0,&var563,&internal1_m2171_tx};
_S_ovbs  S_ovbs_2157_1 = {&var546,&fRM_2_0,&var564,&internal1_m2157_tx};
_S_or2  S_or2_2166_1 = {&var596,&var1173,&var565};
_S_or2  S_or2_2162_1 = {&var597,&var546,&var566};
_S_or2  S_or2_2174_1 = {&var597,&var540,&var567};
_S_or2  S_or2_2178_1 = {&var596,&var1170,&var568};
_S_rs  S_rs_2163_1 = {&var560,&var566,&var569,&vainSBool,&internal1_m2163_q0};
_S_noto  S_noto_2176_1 = {&var571,&var570};
_S_rs  S_rs_2175_1 = {&var559,&var567,&var571,&vainSBool,&internal1_m2175_q0};
_S_noto  S_noto_2164_1 = {&var569,&var572};
_S_noto  S_noto_2172_1 = {&var563,&var573};
_S_noto  S_noto_2158_1 = {&var564,&var574};
_S_and2  S_and2_2151_1 = {&var577,&var679,&var575};
_S_and2  S_and2_2139_1 = {&var577,&var676,&var576};
_S_noto  S_noto_2133_1 = {&var578,&var577};
_S_ovbs  S_ovbs_2132_1 = {&var349,&fRM_3_0,&var578,&internal1_m2132_tx};
_S_or2  S_or2_1640_1 = {&var1343,&lRM_0_,&var579};
_S_and2  S_and2_475_1 = {&var1816,&var1758,&var580};
_S_and2  S_and2_2016_1 = {&var1368,&B7AS31LDU,&var581};
_S_and2  S_and2_487_1 = {&var1119,&var965,&var582};
_S_and2  S_and2_478_1 = {&var966,&var1119,&var583};
_S_and2  S_and2_521_1 = {&var965,&var1120,&var584};
_S_and2  S_and2_516_1 = {&var966,&var1120,&var585};
_S_or2  S_or2_380_1 = {&var1829,&var1091,&var586};
_S_or2  S_or2_376_1 = {&var1829,&var1090,&var587};
_S_ovbs  S_ovbs_51_1 = {&var1841,&fRM_15_0,&var588,&internal1_m51_tx};
_S_ovbs  S_ovbs_357_1 = {&var1316,&fRM_0_02,&var589,&internal1_m357_tx};
_S_ovbs  S_ovbs_312_1 = {&var1318,&fRM_0_02,&var590,&internal1_m312_tx};
_S_ovbs  S_ovbs_824_1 = {&var514,&fRM_0_2,&var591,&internal1_m824_tx};
_S_ovbs  S_ovbs_1584_1 = {&R0MD31LP1,&fRM_10_0,&var592,&internal1_m1584_tx};
_S_ovbs  S_ovbs_114_1 = {&R0MD31LP1,&fRM_0_15,&var593,&internal1_m114_tx};
_S_ovbs  S_ovbs_116_1 = {&var539,&fRM_0_02,&var594,&internal1_m116_tx};
_S_ovbs  S_ovbs_121_1 = {&R0MD32LP1,&fRM_0_02,&var595,&internal1_m121_tx};
_S_ovbs  S_ovbs_21_1 = {&var1394,&fRM_3_0,&var596,&internal1_m21_tx};
_S_ovbs  S_ovbs_13_1 = {&var1168,&fRM_3_0,&var597,&internal1_m13_tx};
_S_ovbs  S_ovbs_2142_1 = {&var349,&fRM_2_0,&var598,&internal1_m2142_tx};
_S_ovbs  S_ovbs_2129_1 = {&var349,&fRM_2_0,&var599,&internal1_m2129_tx};
_S_ovbs  S_ovbs_2247_1 = {&var1403,&fRM_2_0,&var600,&internal1_m2247_tx};
_S_ovbs  S_ovbs_2249_1 = {&var311,&fRM_2_0,&var601,&internal1_m2249_tx};
_S_ovbs  S_ovbs_2054_1 = {&var614,&fRM_0_01,&var602,&internal1_m2054_tx};
_S_ovbs  S_ovbs_77_1 = {&R0MW13LP2,&fRM_10_0,&var603,&internal1_m77_tx};
_S_zpfs  S_zpfs_328_1 = {&var1022,&fRM_10_0,&var604,&internal1_m328_tx,&internal1_m328_y0};
_S_or2  S_or2_1147_1 = {&var1229,&var792,&var605};
_S_or2  S_or2_246_1 = {&A1VN71LZ1,&A1VN71LZ2,&var606};
_S_or2  S_or2_267_1 = {&var917,&var1185,&var607};
_S_or5  S_or5_149_1 = {&B1IS21LDU,&B3IS21LDU,&B2IS21LDU,&var1155,&var1156,&var608};
_S_and2  S_and2_1144_1 = {&var1666,&var1300,&var609};
_S_or3  S_or3_1101_1 = {&var353,&var877,&var876,&var610};
_S_or3  S_or3_1552_1 = {&var860,&var859,&var354,&var611};
_S_and2  S_and2_1075_1 = {&var1431,&var1214,&var612};
_S_and3  S_and3_2049_1 = {&var630,&var615,&var623,&var613};
_S_or2  S_or2_2053_1 = {&var617,&var616,&var614};
_S_or3  S_or3_2051_1 = {&var617,&var616,&var626,&var615};
_S_zpfs  S_zpfs_2048_1 = {&var619,&fEM_R0UL02RDU,&var616,&internal1_m2048_tx,&internal1_m2048_y0};
_S_zpfs  S_zpfs_2046_1 = {&var620,&fEM_R0UL02RDU,&var617,&internal1_m2046_tx,&internal1_m2046_y0};
_S_or2  S_or2_2040_1 = {&var620,&var619,&var618};
_S_or2  S_or2_2041_1 = {&var621,&var1333,&var619};
_S_or2  S_or2_2039_1 = {&var622,&var1333,&var620};
_S_and3  S_and3_2033_1 = {&var1390,&var1142,&var1120,&var621};
_S_and3  S_and3_2032_1 = {&var1391,&var1119,&var1142,&var622};
_S_or2  S_or2_2030_1 = {&var1333,&var1332,&var623};
_S_or3  S_or3_2037_1 = {&var628,&var1332,&var626,&var624};
_S_and2  S_and2_2045_1 = {&var1333,&var615,&var625};
_S_and2  S_and2_2036_1 = {&var1324,&var627,&var626};
_S_zpfs  S_zpfs_2035_1 = {&var1333,&fEM_R0UL04RDU,&var627,&internal1_m2035_tx,&internal1_m2035_y0};
_S_and2  S_and2_2023_1 = {&var1327,&var776,&var628};
_S_or3  S_or3_2024_1 = {&var1281,&var782,&var1259,&var629};
_S_abs_subf  S_abs_subf_2057_1 = {&fEM_R0UL02RDU,&var631,&fEM_R0UL16RDU,&vainSFloat,&var630};
_S_rsfn  S_rsfn_2055_1 = {&var773,&var632,&var631,&internal1_m2055_q0};
_S_lk  S_lk_2052_1 = {&var1486,&var615,&var632};
_S_abs_subf  S_abs_subf_1613_1 = {&fEM_R0UL05RDU,&var634,&fEM_R0UL18RDU,&vainSFloat,&var633};
_S_rsfn  S_rsfn_1604_1 = {&var773,&var635,&var634,&internal1_m1604_q0};
_S_lk  S_lk_1608_1 = {&var1338,&var760,&var635};
_S_abs_subf  S_abs_subf_1655_1 = {&fEM_R0UL07RDU,&var637,&fEM_R0UL20RDU,&vainSFloat,&var636};
_S_rsfn  S_rsfn_1642_1 = {&var773,&var638,&var637,&internal1_m1642_q0};
_S_lk  S_lk_1646_1 = {&var1344,&var750,&var638};
_S_ma  S_ma_1625_1 = {array_m1625_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_abs_subf  S_abs_subf_1660_1 = {&fEM_R0UL25RDU,&var640,&fEM_R0UL19RDU,&vainSFloat,&var639};
_S_rsfn  S_rsfn_1645_1 = {&var773,&var641,&var640,&internal1_m1645_q0};
_S_lk  S_lk_1649_1 = {&var1484,&var741,&var641};
_S_and3  S_and3_2099_1 = {&var643,&var646,&var653,&var642};
_S_abs_subf  S_abs_subf_2096_1 = {&var644,&fEM_R0UL03RDU,&fEM_R0UL17RDU,&vainSFloat,&var643};
_S_rsfn  S_rsfn_2094_1 = {&var773,&var645,&var644,&internal1_m2094_q0};
_S_lk  S_lk_2089_1 = {&var1485,&var646,&var645};
_S_or3  S_or3_2088_1 = {&var651,&var657,&var656,&var646};
_S_and4  S_and4_2093_1 = {&var656,&var1491,&var669,&var667,&var647};
_S_and4  S_and4_2091_1 = {&var657,&var1491,&var669,&var667,&var648};
_S_and2  S_and2_2083_1 = {&var1336,&var646,&var649};
_S_and2  S_and2_2069_1 = {&var776,&var1326,&var650};
_S_and2  S_and2_2075_1 = {&var654,&var1325,&var651};
_S_or3  S_or3_2076_1 = {&var651,&var650,&var1335,&var652};
_S_or2  S_or2_2065_1 = {&var1336,&var1335,&var653};
_S_zpfs  S_zpfs_2074_1 = {&var1336,&fEM_R0UL21RDU,&var654,&internal1_m2074_tx,&internal1_m2074_y0};
_S_or3  S_or3_2062_1 = {&var778,&var1285,&var1263,&var655};
_S_zpfs  S_zpfs_2087_1 = {&var659,&fEM_R0UL03RDU,&var656,&internal1_m2087_tx,&internal1_m2087_y0};
_S_zpfs  S_zpfs_2084_1 = {&var660,&fEM_R0UL03RDU,&var657,&internal1_m2084_tx,&internal1_m2084_y0};
_S_or2  S_or2_2080_1 = {&var660,&var659,&var658};
_S_or2  S_or2_2081_1 = {&var661,&var1336,&var659};
_S_or2  S_or2_2079_1 = {&var662,&var1336,&var660};
_S_and4  S_and4_2077_1 = {&var1392,&var1120,&B2IS12LDU,&var663,&var661};
_S_and4  S_and4_2073_1 = {&var1393,&A2IS12LDU,&var1119,&var663,&var662};
_S_and2  S_and2_2070_1 = {&var1142,&var667,&var663};
_S_and3  S_and3_2108_1 = {&var1120,&var1247,&var666,&var664};
_S_and3  S_and3_2107_1 = {&var1119,&var1248,&var666,&var665};
_S_and4  S_and4_2106_1 = {&var1213,&var1012,&var1014,&var667,&var666};
_S_and2  S_and2_2100_1 = {&var1025,&var1214,&var667};
_S_or2  S_or2_2102_1 = {&var1495,&var1212,&var668};
_S_or3  S_or3_2111_1 = {&var672,&var671,&var674,&var669};
_S_and2  S_and2_2101_1 = {&var1251,&A2IS12LDU,&var670};
_S_and2  S_and2_2105_1 = {&var1152,&var670,&var671};
_S_and3  S_and3_2110_1 = {&var1490,&var675,&var670,&var672};
_S_or2  S_or2_2119_1 = {&lRM_0_,&var668,&var673};
_S_and2  S_and2_2116_1 = {&var1167,&var675,&var674};
_S_and2  S_and2_2118_1 = {&var1250,&B2IS12LDU,&var675};
_S_or2  S_or2_2138_1 = {&var1172,&var596,&var676};
_S_or2  S_or2_2134_1 = {&var597,&var349,&var677};
_S_or2  S_or2_2146_1 = {&var349,&var597,&var678};
_S_or2  S_or2_2150_1 = {&var596,&var1171,&var679};
_S_or2  S_or2_2215_1 = {&var1020,&var1404,&var680};
_S_or2  S_or2_2225_1 = {&var1214,&var1425,&var681};
_S_zpfs  S_zpfs_2227_1 = {&var280,&fRM_15_0,&var682,&internal1_m2227_tx,&internal1_m2227_y0};
_S_or2  S_or2_2233_1 = {&var1019,&var312,&var683};
_S_zpfs  S_zpfs_2238_1 = {&var278,&fRM_15_0,&var684,&internal1_m2238_tx,&internal1_m2238_y0};
_S_or2  S_or2_2243_1 = {&var1214,&var1424,&var685};
_S_or2  S_or2_2257_1 = {&var284,&var647,&var686};
_S_or2  S_or2_2254_1 = {&var648,&var288,&var687};
_S_and2  S_and2_2265_1 = {&var1394,&var600,&var688};
_S_and2  S_and2_2015_1 = {&var1369,&A7AS31LDU,&var689};
_S_or3  S_or3_1988_1 = {&var694,&var698,&var696,&var690};
_S_or3  S_or3_1989_1 = {&var697,&var696,&var693,&var691};
_S_or2  S_or2_2002_1 = {&B0VT71LZ1,&B0VT71LZ2,&var692};
_S_and2  S_and2_1993_1 = {&var699,&var692,&var693};
_S_and2  S_and2_1987_1 = {&var699,&var695,&var694};
_S_or2  S_or2_1986_1 = {&A0VT71LZ1,&A0VT71LZ2,&var695};
_S_zpfs  S_zpfs_1983_1 = {&var1386,&fRM_2_5,&var696,&internal1_m1983_tx,&internal1_m1983_y0};
_S_zpfs  S_zpfs_1982_1 = {&var1387,&fRM_2_5,&var697,&internal1_m1982_tx,&internal1_m1982_y0};
_S_zpfs  S_zpfs_1981_1 = {&var1388,&fRM_2_5,&var698,&internal1_m1981_tx,&internal1_m1981_y0};
_S_zpfs  S_zpfs_1980_1 = {&var1389,&fRM_2_5,&var699,&internal1_m1980_tx,&internal1_m1980_y0};
_S_or2  S_or2_2011_1 = {&R0VP73LZ2,&R0VP73LZ1,&var700};
_S_and2  S_and2_2006_1 = {&var311,&var1370,&var701};
_S_or2  S_or2_2001_1 = {&var704,&var701,&var702};
_S_or2  S_or2_2003_1 = {&var284,&var311,&var703};
_S_and2  S_and2_2000_1 = {&var284,&var1360,&var704};
_S_and2  S_and2_1984_1 = {&var1403,&var1371,&var705};
_S_or2  S_or2_1985_1 = {&var708,&var705,&var706};
_S_or2  S_or2_1978_1 = {&var288,&var1403,&var707};
_S_and2  S_and2_1977_1 = {&var288,&var1361,&var708};
_S_or3  S_or3_1947_1 = {&var1454,&var1412,&var1413,&var709};
_S_or3  S_or3_1948_1 = {&var1452,&var1412,&var1413,&var710};
_S_or2  S_or2_1939_1 = {&var1447,&var1412,&var711};
_S_or2  S_or2_1940_1 = {&var1446,&var1412,&var712};
_S_or2  S_or2_1946_1 = {&var1456,&var1415,&var713};
_S_or4  S_or4_1944_1 = {&var1415,&var1453,&var1416,&var1417,&var714};
_S_or4  S_or4_1943_1 = {&var1415,&var1459,&var1416,&var1417,&var715};
_S_or2  S_or2_1937_1 = {&var1448,&var1417,&var716};
_S_or2  S_or2_1936_1 = {&var1449,&var1417,&var717};
_S_or2  S_or2_1945_1 = {&var1415,&var1455,&var718};
_S_or2  S_or2_1914_1 = {&var464,&var510,&var719};
_S_and2  S_and2_1737_1 = {&var1709,&var1667,&var720};
_S_and2  S_and2_1736_1 = {&var1832,&var1667,&var721};
_S_and2  S_and2_1735_1 = {&var1109,&var1667,&var722};
_S_or2  S_or2_1734_1 = {&B4IS11LDU,&A4IS11LDU,&var723};
_S_and2  S_and2_1733_1 = {&var723,&var1667,&var724};
_S_and2  S_and2_1723_1 = {&var1887,&var1667,&var725};
_S_and2  S_and2_1722_1 = {&var362,&var1667,&var726};
_S_and2  S_and2_1721_1 = {&var1098,&var1667,&var727};
_S_and2  S_and2_1720_1 = {&R3IS21LDU,&var1667,&var728};
_S_or2  S_or2_1794_1 = {&var1845,&var1846,&var729};
_S_or2  S_or2_1793_1 = {&var1847,&var1845,&var730};
_S_or2  S_or2_2282_1 = {&var1191,&R0MD34LP1,&var731};
_S_or3  S_or3_2288_1 = {&var1466,&var1468,&var1467,&var732};
_S_or3  S_or3_2279_1 = {&var1472,&var1474,&var1473,&var733};
_S_or2  S_or2_1778_1 = {&var1945,&var1667,&var734};
_S_or2  S_or2_1750_1 = {&var1710,&var1300,&var735};
_S_or5  S_or5_1250_1 = {&var1725,&var737,&var1736,&var1722,&var1723,&var736};
_S_or3  S_or3_1254_1 = {&var1730,&var1731,&var1194,&var737};
_S_or5  S_or5_1765_1 = {&var516,&var739,&var1719,&var1711,&var1712,&var738};
_S_or3  S_or3_1768_1 = {&var1193,&var1714,&var1713,&var739};
_S_and3  S_and3_1670_1 = {&var741,&var746,&var639,&var740};
_S_and2  S_and2_1672_1 = {&var742,&var1483,&var741};
_S_or3  S_or3_1671_1 = {&A3VZ13LZ2,&A3VZ13LZ1,&var745,&var742};
_S_zpfs  S_zpfs_1656_1 = {&var1483,&fRM_0_2,&var743,&internal1_m1656_tx,&internal1_m1656_y0};
_S_or3  S_or3_1658_1 = {&var1346,&var745,&var747,&var744};
_S_and2  S_and2_1657_1 = {&var1323,&var743,&var745};
_S_or2  S_or2_1647_1 = {&var1483,&var1346,&var746};
_S_and2  S_and2_1635_1 = {&var1328,&var776,&var747};
_S_or3  S_or3_1643_1 = {&var1260,&var1282,&var781,&var748};
_S_or3  S_or3_1666_1 = {&R0AD14LZ1,&R0AD14LZ2,&var752,&var749};
_S_and2  S_and2_1667_1 = {&var749,&var1343,&var750};
_S_zpfs  S_zpfs_1650_1 = {&var1343,&fEM_R0UL06RDU,&var751,&internal1_m1650_tx,&internal1_m1650_y0};
_S_and2  S_and2_1651_1 = {&var751,&var1322,&var752};
_S_or3  S_or3_1652_1 = {&var1341,&var752,&var755,&var753};
_S_or3  S_or3_1627_1 = {&var780,&var1283,&var1261,&var754};
_S_and2  S_and2_1630_1 = {&var1329,&var776,&var755};
_S_and3  S_and3_1669_1 = {&var636,&var750,&var763,&var756};
_S_zpfs  S_zpfs_1600_1 = {&var1340,&fEM_R0UL04RDU,&var757,&internal1_m1600_tx,&internal1_m1600_y0};
_S_and2  S_and2_1601_1 = {&var757,&var1321,&var758};
_S_and3  S_and3_1617_1 = {&var633,&var760,&var764,&var759};
_S_and2  S_and2_1611_1 = {&var761,&var1340,&var760};
_S_or3  S_or3_1610_1 = {&A3VZ15LZ1,&A3VZ15LZ2,&var758,&var761};
_S_or3  S_or3_1602_1 = {&var765,&var758,&var1339,&var762};
_S_or2  S_or2_1638_1 = {&var1343,&var1341,&var763};
_S_or2  S_or2_1598_1 = {&var1340,&var1339,&var764};
_S_and2  S_and2_1590_1 = {&var1330,&var776,&var765};
_S_or3  S_or3_1588_1 = {&var1262,&var1284,&var779,&var766};
_S_or2  S_or2_1562_1 = {&var1838,&var768,&var767};
_S_and2  S_and2_1561_1 = {&var769,&var1384,&var768};
_S_or2  S_or2_1560_1 = {&var1165,&var1117,&var769};
_S_or2  S_or2_1557_1 = {&var1255,&var1277,&var770};
_S_and2  S_and2_1555_1 = {&var1349,&var1350,&var771};
_S_and2  S_and2_1558_1 = {&var770,&var769,&var772};
_S_or5  S_or5_1559_1 = {&var590,&var589,&var771,&var772,&R0MD34LP1,&var773};
_S_orni  S_orni_1579_1 = {array_m1579_x_1,&iRM_5_,&var774,&var775};
_S_or5  S_or5_1581_1 = {&var1345,&var1320,&var773,&var1265,&var592,&var776};
_S_and2  S_and2_1580_1 = {&var774,&var1478,&var777};
_S_or2  S_or2_1587_1 = {&var1292,&var783,&var778};
_S_or2  S_or2_1583_1 = {&var1291,&var784,&var779};
_S_or2  S_or2_1577_1 = {&var1290,&var785,&var780};
_S_or2  S_or2_1575_1 = {&var1289,&var786,&var781};
_S_or2  S_or2_1573_1 = {&var1288,&var787,&var782};
_S_and2  S_and2_1586_1 = {&var1833,&var788,&var783};
_S_and2  S_and2_1582_1 = {&var1834,&var788,&var784};
_S_and2  S_and2_1576_1 = {&var1835,&var788,&var785};
_S_and2  S_and2_1574_1 = {&var1836,&var788,&var786};
_S_and2  S_and2_1572_1 = {&var1837,&var788,&var787};
_S_and2  S_and2_1566_1 = {&var1838,&var271,&var788};
_S_and3  S_and3_1177_1 = {&var458,&var793,&var811,&var789};
_S_or2  S_or2_1142_1 = {&var1302,&var1298,&var790};
_S_or2  S_or2_1167_1 = {&var1298,&var1232,&var791};
_S_and2  S_and2_1135_1 = {&var1676,&var1299,&var792};
_S_and2  S_and2_1130_1 = {&var1495,&var813,&var793};
_S_or3  S_or3_1139_1 = {&var1298,&var1228,&var1301,&var794};
_S_and2  S_and2_1143_1 = {&var455,&var1495,&var795};
_S_and2  S_and2_1168_1 = {&var466,&var1495,&var796};
_S_and2  S_and2_1176_1 = {&var460,&var1495,&var797};
_S_and2  S_and2_1183_1 = {&var463,&var1495,&var798};
_S_and3  S_and3_1125_1 = {&var801,&var1217,&var1495,&var799};
_S_and3  S_and3_1119_1 = {&var802,&var1217,&var1495,&var800};
_S_and2  S_and2_1127_1 = {&var1119,&var1494,&var801};
_S_and2  S_and2_1117_1 = {&var1120,&var1494,&var802};
_S_and4  S_and4_1126_1 = {&var801,&var1495,&var1225,&var1215,&var803};
_S_and4  S_and4_1120_1 = {&var802,&var1495,&var1225,&var1215,&var804};
_S_and4  S_and4_1124_1 = {&var1495,&var801,&var809,&var1216,&var805};
_S_and4  S_and4_1118_1 = {&var1495,&var802,&var809,&var1216,&var806};
_S_and2  S_and2_1111_1 = {&var1226,&var1495,&var807};
_S_or4  S_or4_1114_1 = {&R0MD31LP1,&var1729,&var471,&var820,&var808};
_S_and3  S_and3_1164_1 = {&var1227,&var1226,&var1225,&var809};
_S_and2  S_and2_1148_1 = {&var811,&var605,&var810};
_S_and2  S_and2_1151_1 = {&var1224,&var809,&var811};
_S_or2  S_or2_1159_1 = {&var1294,&var1236,&var812};
_S_and2  S_and2_1170_1 = {&var814,&var812,&var813};
_S_or2  S_or2_1160_1 = {&var1235,&var1237,&var814};
_S_or2  S_or2_1161_1 = {&var1234,&var1235,&var815};
_S_or2  S_or2_1165_1 = {&var1233,&var1238,&var816};
_S_and2  S_and2_1166_1 = {&var815,&var816,&var817};
_S_or2  S_or2_1154_1 = {&var1294,&var1293,&var818};
_S_and2  S_and2_1155_1 = {&var818,&var1230,&var819};
_S_and5  S_and5_1107_1 = {&var821,&var1314,&var1235,&var1294,&var810,&var820};
_S_and2  S_and2_1108_1 = {&var1269,&var1270,&var821};
_S_and2  S_and2_1376_1 = {&var1363,&var823,&var822};
_S_or2  S_or2_1371_1 = {&A2MD12LP1,&var824,&var823};
_S_and2  S_and2_1359_1 = {&A2MD11LP1,&var1380,&var824};
_S_or2  S_or2_1352_1 = {&var827,&B2MD12LP1,&var825};
_S_and2  S_and2_1356_1 = {&var825,&var1363,&var826};
_S_and2  S_and2_1346_1 = {&B2MD11LP1,&var1381,&var827};
_S_or3  S_or3_1333_1 = {&var1445,&var1440,&var983,&var828};
_S_or5  S_or5_1349_1 = {&var831,&var1203,&var1706,&var1701,&var1700,&var829};
_S_or2  S_or2_1370_1 = {&var1957,&var1691,&var830};
_S_or3  S_or3_1437_1 = {&var1672,&var832,&var833,&var831};
_S_and2  S_and2_1428_1 = {&var1691,&var1166,&var832};
_S_and2  S_and2_1427_1 = {&var1116,&var1691,&var833};
_S_and3  S_and3_1426_1 = {&var608,&var1152,&var848,&var834};
_S_and2  S_and2_1425_1 = {&var362,&var848,&var835};
_S_and3  S_and3_1419_1 = {&var1141,&var1187,&var848,&var836};
_S_and2  S_and2_1418_1 = {&var700,&var848,&var837};
_S_and2  S_and2_1403_1 = {&var1682,&var848,&var838};
_S_and2  S_and2_1387_1 = {&var1887,&var848,&var839};
_S_and2  S_and2_1405_1 = {&var269,&var848,&var840};
_S_and2  S_and2_1388_1 = {&R3IS21LDU,&var848,&var841};
_S_and2  S_and2_1406_1 = {&var844,&var848,&var842};
_S_and3  S_and3_1389_1 = {&var845,&var1681,&var848,&var843};
_S_or2  S_or2_1407_1 = {&var1674,&var1675,&var844};
_S_or2  S_or2_1390_1 = {&A4IS11LDU,&B4IS11LDU,&var845};
_S_and3  S_and3_1402_1 = {&var1415,&var472,&var1168,&var846};
_S_and3  S_and3_1401_1 = {&var1417,&var472,&var1168,&var847};
_S_or3  S_or3_1392_1 = {&var1692,&var847,&var846,&var848};
_S_and2  S_and2_1484_1 = {&var850,&var1363,&var849};
_S_or2  S_or2_1483_1 = {&var851,&B3MD12LP1,&var850};
_S_and2  S_and2_1470_1 = {&B3MD11LP1,&var1359,&var851};
_S_or2  S_or2_1475_1 = {&var1948,&var1509,&var852};
_S_or5  S_or5_1463_1 = {&var611,&var1518,&var1519,&var383,&var1201,&var853};
_S_and2  S_and2_1535_1 = {&var1509,&var1166,&var854};
_S_and2  S_and2_1534_1 = {&var1509,&var1116,&var855};
_S_and2  S_and2_1548_1 = {&var1182,&var1497,&var856};
_S_or2  S_or2_1541_1 = {&var856,&var1183,&var857};
_S_and3  S_and3_1533_1 = {&var1372,&var857,&var866,&var858};
_S_and3  S_and3_1532_1 = {&var608,&var1167,&var866,&var859};
_S_and2  S_and2_1531_1 = {&var362,&var866,&var860};
_S_and2  S_and2_1526_1 = {&var1429,&var1214,&var861};
_S_or2  S_or2_1513_1 = {&var1500,&var1499,&var862};
_S_and2  S_and2_1512_1 = {&var862,&var866,&var863};
_S_and2  S_and2_1511_1 = {&var269,&var866,&var864};
_S_and2  S_and2_1509_1 = {&var1502,&var866,&var865};
_S_or2  S_or2_1498_1 = {&var1511,&var292,&var866};
_S_or2  S_or2_1499_1 = {&B4IS11LDU,&A4IS11LDU,&var867};
_S_and3  S_and3_1496_1 = {&var1501,&var867,&var866,&var868};
_S_and2  S_and2_1495_1 = {&R3IS21LDU,&var866,&var869};
_S_and2  S_and2_1494_1 = {&var1887,&var866,&var870};
_S_and2  S_and2_1094_1 = {&var1180,&var1529,&var871};
_S_and2  S_and2_1083_1 = {&var1116,&var1541,&var872};
_S_and2  S_and2_1084_1 = {&var1166,&var1541,&var873};
_S_or2  S_or2_1090_1 = {&var1181,&var871,&var874};
_S_and3  S_and3_1082_1 = {&var1372,&var874,&var881,&var875};
_S_and3  S_and3_1081_1 = {&var1152,&var608,&var881,&var876};
_S_and2  S_and2_1080_1 = {&var362,&var881,&var877};
_S_and2  S_and2_1058_1 = {&var1534,&var881,&var878};
_S_or2  S_or2_1062_1 = {&var1532,&var1531,&var879};
_S_and2  S_and2_1061_1 = {&var879,&var881,&var880};
_S_or2  S_or2_1047_1 = {&var1543,&var293,&var881};
_S_or2  S_or2_1048_1 = {&B4IS11LDU,&A4IS11LDU,&var882};
_S_and3  S_and3_1045_1 = {&var882,&var1533,&var881,&var883};
_S_and2  S_and2_1060_1 = {&var269,&var881,&var884};
_S_and2  S_and2_1044_1 = {&R3IS21LDU,&var881,&var885};
_S_and2  S_and2_1043_1 = {&var1887,&var881,&var886};
_S_or2  S_or2_1023_1 = {&var1541,&var1951,&var887};
_S_or5  S_or5_1009_1 = {&var610,&var1202,&var381,&var1550,&var1551,&var888};
_S_and2  S_and2_1036_1 = {&var1363,&var890,&var889};
_S_or2  S_or2_1031_1 = {&var891,&A3MD12LP1,&var890};
_S_and2  S_and2_1020_1 = {&A3MD11LP1,&var1414,&var891};
_S_or3  S_or3_981_1 = {&var1639,&var894,&var893,&var892};
_S_and2  S_and2_971_1 = {&var1650,&var1116,&var893};
_S_and2  S_and2_972_1 = {&var1650,&var1166,&var894};
_S_and3  S_and3_970_1 = {&var1673,&var1167,&var906,&var895};
_S_and2  S_and2_969_1 = {&var362,&var906,&var896};
_S_and2  S_and2_947_1 = {&var1643,&var906,&var897};
_S_and2  S_and2_949_1 = {&var269,&var906,&var898};
_S_and2  S_and2_950_1 = {&var900,&var906,&var899};
_S_or2  S_or2_951_1 = {&var1641,&var1640,&var900};
_S_and2  S_and2_931_1 = {&var1887,&var906,&var901};
_S_and3  S_and3_933_1 = {&var1642,&var907,&var906,&var902};
_S_and2  S_and2_932_1 = {&R3IS21LDU,&var906,&var903};
_S_and3  S_and3_946_1 = {&var1415,&var472,&var1168,&var904};
_S_and3  S_and3_945_1 = {&var472,&var1417,&var1168,&var905};
_S_or3  S_or3_934_1 = {&var1651,&var904,&var905,&var906};
_S_or2  S_or2_935_1 = {&B4IS11LDU,&A4IS11LDU,&var907};
_S_or2  S_or2_915_1 = {&var1954,&var1650,&var908};
_S_zpfs  S_zpfs_911_1 = {&var1664,&fRM_3_0,&var909,&internal1_m911_tx,&internal1_m911_y0};
_S_zpfs  S_zpfs_910_1 = {&var1665,&fRM_2_0,&var910,&internal1_m910_tx,&internal1_m910_y0};
_S_zpfs  S_zpfs_928_1 = {&var1662,&fEM_A2UL83RDU,&var911,&internal1_m928_tx,&internal1_m928_y0};
_S_or5  S_or5_907_1 = {&var892,&var911,&var1663,&var910,&var909,&var912};
_S_or3  S_or3_897_1 = {&var1420,&var1443,&var978,&var913};
_S_or4  S_or4_875_1 = {&var1786,&var1784,&var1785,&var1787,&var914};
_S_or2  S_or2_867_1 = {&var916,&var914,&var915};
_S_or4  S_or4_860_1 = {&var1795,&var1794,&var1793,&var1796,&var916};
_S_and2  S_and2_271_1 = {&var1184,&var1589,&var917};
_S_and3  S_and3_257_1 = {&var1152,&var608,&var1604,&var918};
_S_or3  S_or3_275_1 = {&var920,&var922,&var1592,&var919};
_S_and2  S_and2_261_1 = {&var1603,&var1166,&var920};
_S_and3  S_and3_258_1 = {&var607,&var1372,&var1604,&var921};
_S_and2  S_and2_260_1 = {&var1116,&var1603,&var922};
_S_and2  S_and2_256_1 = {&var362,&var1604,&var923};
_S_and2  S_and2_225_1 = {&var1596,&var1604,&var924};
_S_and2  S_and2_227_1 = {&var269,&var1604,&var925};
_S_or2  S_or2_229_1 = {&var1593,&var1594,&var926};
_S_and2  S_and2_228_1 = {&var926,&var1604,&var927};
_S_or2  S_or2_215_1 = {&B4IS11LDU,&A4IS11LDU,&var928};
_S_and3  S_and3_214_1 = {&var1595,&var928,&var1604,&var929};
_S_and2  S_and2_212_1 = {&var1887,&var1604,&var930};
_S_and2  S_and2_213_1 = {&R3IS21LDU,&var1604,&var931};
_S_and2  S_and2_184_1 = {&var1363,&var934,&var932};
_S_and2  S_and2_177_1 = {&A1MD11LP1,&var1402,&var933};
_S_or2  S_or2_183_1 = {&A1MD12LP1,&var933,&var934};
_S_or2  S_or2_193_1 = {&var1603,&var1939,&var935};
_S_zpfs  S_zpfs_187_1 = {&var1618,&fRM_2_0,&var936,&internal1_m187_tx,&internal1_m187_y0};
_S_zpfs  S_zpfs_186_1 = {&var1617,&fRM_2_0,&var937,&internal1_m186_tx,&internal1_m186_y0};
_S_zpfs  S_zpfs_208_1 = {&var1615,&fEM_A1UL03RDU,&var938,&internal1_m208_tx,&internal1_m208_y0};
_S_or5  S_or5_181_1 = {&var919,&var938,&var937,&var936,&var1616,&var939};
_S_orn  S_orn_605_1 = {array_m605_x_1,&iRM_12_,&var940};
_S_and2  S_and2_634_1 = {&var1559,&var1179,&var941};
_S_or2  S_or2_630_1 = {&var1178,&var941,&var942};
_S_and3  S_and3_620_1 = {&var1167,&var1673,&var1571,&var943};
_S_and2  S_and2_619_1 = {&var362,&var1571,&var944};
_S_and3  S_and3_621_1 = {&var1372,&var1571,&var942,&var945};
_S_or2  S_or2_595_1 = {&var1561,&var1560,&var946};
_S_and2  S_and2_594_1 = {&var946,&var1571,&var947};
_S_and2  S_and2_593_1 = {&var1571,&var269,&var948};
_S_and3  S_and3_580_1 = {&var1562,&var950,&var1571,&var949};
_S_or2  S_or2_581_1 = {&B4IS11LDU,&A4IS11LDU,&var950};
_S_and2  S_and2_591_1 = {&var1571,&var1563,&var951};
_S_or2  S_or2_554_1 = {&B1MD12LP1,&var954,&var952};
_S_and2  S_and2_556_1 = {&var1363,&var952,&var953};
_S_and2  S_and2_549_1 = {&B1MD11LP1,&var1382,&var954};
_S_and2  S_and2_579_1 = {&var1571,&R3IS21LDU,&var955};
_S_and2  S_and2_578_1 = {&var1571,&var1887,&var956};
_S_or2  S_or2_561_1 = {&var1570,&var1961,&var957};
_S_zpfs  S_zpfs_577_1 = {&var1584,&fEM_A1UL03RDU,&var958,&internal1_m577_tx,&internal1_m577_y0};
_S_or5  S_or5_550_1 = {&var1112,&var958,&var1585,&var1579,&var1580,&var959};
_S_or2  S_or2_538_1 = {&var1398,&var979,&var960};
_S_or3  S_or3_528_1 = {&var800,&var1397,&var1209,&var961};
_S_or4  S_or4_515_1 = {&var1624,&var1621,&var1623,&var1622,&var962};
_S_or4  S_or4_496_1 = {&var1632,&var1630,&var1631,&var1633,&var963};
_S_or2  S_or2_503_1 = {&var963,&var962,&var964};
_S_and3  S_and3_485_1 = {&var967,&var1363,&R0MD33LP1,&var965};
_S_and3  S_and3_486_1 = {&var1363,&var968,&R0MD33LP1,&var966};
_S_or3  S_or3_476_1 = {&var502,&var1218,&var1205,&var967};
_S_or2  S_or2_477_1 = {&var1619,&var1396,&var968};
_S_or2  S_or2_826_1 = {&var1754,&var1755,&var969};
_S_and2  S_and2_347_1 = {&var1254,&var1316,&var970};
_S_or2  S_or2_366_1 = {&B4IS21LDU,&A4IS21LDU,&var971};
_S_or2  S_or2_361_1 = {&A2IS21LDU,&B2IS21LDU,&var972};
_S_or2  S_or2_356_1 = {&var975,&var1258,&var973};
_S_and3  S_and3_354_1 = {&var1317,&var1312,&var1313,&var974};
_S_or4  S_or4_352_1 = {&var1243,&var412,&R0MD31LP1,&var1253,&var975};
_S_and4  S_and4_348_1 = {&var1165,&var1033,&var471,&var1123,&var976};
_S_or2  S_or2_343_1 = {&R0MD34LP1,&var1253,&var977};
_S_and3  S_and3_665_1 = {&var1000,&var1496,&B2IS12LDU,&var978};
_S_and2  S_and2_664_1 = {&var1000,&var1528,&var979};
_S_and2  S_and2_663_1 = {&var1000,&var1591,&var980};
_S_or2  S_or2_707_1 = {&A2IS12LDU,&B2IS12LDU,&var981};
_S_or2  S_or2_684_1 = {&var1726,&var1352,&var982};
_S_and3  S_and3_675_1 = {&A2IS12LDU,&var1496,&var1001,&var983};
_S_and2  S_and2_706_1 = {&var985,&var1496,&var984};
_S_or2  S_or2_708_1 = {&var1295,&var455,&var985};
_S_or2  S_or2_689_1 = {&var1726,&var1351,&var986};
_S_or2  S_or2_687_1 = {&var988,&var1726,&var987};
_S_and2  S_and2_699_1 = {&var1528,&var466,&var988};
_S_and2  S_and2_674_1 = {&var1001,&var1528,&var989};
_S_and2  S_and2_673_1 = {&var1001,&var1591,&var990};
_S_and2  S_and2_698_1 = {&var460,&var1591,&var991};
_S_and2  S_and2_714_1 = {&var463,&var1619,&var992};
_S_or2  S_or2_710_1 = {&var1726,&var1353,&var993};
_S_or2  S_or2_705_1 = {&var995,&var992,&var994};
_S_and2  S_and2_697_1 = {&var1003,&var1588,&var995};
_S_and2  S_and2_703_1 = {&var1003,&R0MD33LP1,&var996};
_S_or2  S_or2_653_1 = {&var1176,&var1177,&var997};
_S_and4  S_and4_672_1 = {&var1176,&var1001,&var1688,&A2IS12LDU,&var998};
_S_and4  S_and4_662_1 = {&var1000,&var1177,&var1688,&B2IS12LDU,&var999};
_S_and2  S_and2_661_1 = {&var1120,&var1686,&var1000};
_S_and2  S_and2_671_1 = {&var1119,&var1686,&var1001};
_S_or2  S_or2_702_1 = {&var1296,&var455,&var1002};
_S_and2  S_and2_695_1 = {&var1002,&var1688,&var1003};
_S_or2  S_or2_682_1 = {&var1726,&var1354,&var1004};
_S_or2  S_or2_694_1 = {&var1666,&var1309,&var1005};
_S_and2  S_and2_693_1 = {&var1005,&var1710,&var1006};
_S_or2  S_or2_679_1 = {&var1726,&var1355,&var1007};
_S_and2  S_and2_692_1 = {&var1727,&var1676,&var1008};
_S_or2  S_or2_677_1 = {&var1726,&var1356,&var1009};
_S_and2  S_and2_690_1 = {&var458,&var1729,&var1010};
_S_or2  S_or2_669_1 = {&var1364,&var1726,&var1011};
_S_and2  S_and2_321_1 = {&var1426,&var1014,&var1012};
_S_and2  S_and2_309_1 = {&var1014,&var1241,&var1013};
_S_or2  S_or2_304_1 = {&var1255,&var1277,&var1014};
_S_and3  S_and3_300_1 = {&var1492,&var1312,&var1313,&var1015};
_S_and3  S_and3_315_1 = {&var972,&var1242,&var1017,&var1016};
_S_or2  S_or2_305_1 = {&var1492,&var1317,&var1017};
_S_and2  S_and2_314_1 = {&var971,&var1017,&var1018};
_S_and2  S_and2_335_1 = {&var1023,&var1120,&var1019};
_S_and2  S_and2_336_1 = {&var1119,&var1023,&var1020};
_S_and2  S_and2_341_1 = {&var1214,&var1012,&var1021};
_S_and2  S_and2_329_1 = {&var1023,&var1214,&var1022};
_S_and2  S_and2_334_1 = {&var1394,&var1024,&var1023};
_S_or2  S_or2_330_1 = {&var1025,&var970,&var1024};
_S_or2  S_or2_331_1 = {&var1026,&var970,&var1025};
_S_and4  S_and4_332_1 = {&var1318,&var1266,&var1267,&var1117,&var1026};
_S_or2  S_or2_317_1 = {&var1318,&var1316,&var1027};
_S_and2  S_and2_302_1 = {&var1280,&var1249,&var1028};
_S_or2  S_or2_308_1 = {&var1031,&var1028,&var1029};
_S_or2  S_or2_282_1 = {&R0MD34LP1,&var1252,&var1030};
_S_or4  S_or4_299_1 = {&var1243,&R0MD31LP1,&var412,&var1252,&var1031};
_S_and3  S_and3_292_1 = {&var1033,&var1122,&var471,&var1032};
_S_or2  S_or2_291_1 = {&var1271,&var1457,&var1033};
_S_and3  S_and3_296_1 = {&var1272,&var1274,&var1273,&var1034};
_S_or2  S_or2_284_1 = {&var1036,&var1034,&var1035};
_S_and3  S_and3_278_1 = {&R0MD33LP1,&var1276,&var1275,&var1036};
_S_or2  S_or2_1217_1 = {&B4IS11LDU,&A4IS11LDU,&var1037};
_S_and2  S_and2_1220_1 = {&var1677,&var1724,&var1038};
_S_and2  S_and2_1219_1 = {&var1677,&var1832,&var1039};
_S_and2  S_and2_1218_1 = {&var1677,&var1109,&var1040};
_S_and2  S_and2_1216_1 = {&var1677,&var1037,&var1041};
_S_and2  S_and2_1206_1 = {&var1677,&var362,&var1042};
_S_and2  S_and2_1205_1 = {&var1098,&var1677,&var1043};
_S_and2  S_and2_1204_1 = {&var1677,&R3IS21LDU,&var1044};
_S_and2  S_and2_1207_1 = {&var1677,&var1887,&var1045};
_S_and2  S_and2_1199_1 = {&var455,&var1211,&var1046};
_S_and2  S_and2_1200_1 = {&var466,&var1209,&var1047};
_S_and2  S_and2_1201_1 = {&var460,&var1207,&var1048};
_S_and2  S_and2_1202_1 = {&var463,&var1205,&var1049};
_S_or2  S_or2_1184_1 = {&R0MD31LP1,&var1051,&var1050};
_S_and4  S_and4_1185_1 = {&var367,&var366,&var365,&var364,&var1051};
_S_or2  S_or2_1266_1 = {&var1677,&var1942,&var1052};
_S_or2  S_or2_1239_1 = {&var1727,&var1299,&var1053};
_S_or2  S_or2_1313_1 = {&var1768,&var1767,&var1054};
_S_or2  S_or2_1299_1 = {&var1777,&var1776,&var1055};
_S_or2  S_or2_1308_1 = {&var1192,&R0MD34LP1,&var1056};
_S_or2  S_or2_1283_1 = {&var1054,&var1832,&var1057};
_S_or2  S_or2_1281_1 = {&var1059,&var1057,&var1058};
_S_or2  S_or2_1282_1 = {&var1055,&var1832,&var1059};
_S_or4  S_or4_378_1 = {&var1804,&var1803,&var1805,&var1802,&var1060};
_S_or2  S_or2_728_1 = {&B5IS11LDU,&A5IS11LDU,&var1061};
_S_and2  S_and2_727_1 = {&var1066,&var1061,&var1062};
_S_or2  S_or2_726_1 = {&B6IS11LDU,&A6IS11LDU,&var1063};
_S_and2  S_and2_725_1 = {&var1066,&var1063,&var1064};
_S_or2  S_or2_724_1 = {&A4IS11LDU,&B4IS11LDU,&var1065};
_S_or2  S_or2_716_1 = {&var1068,&var1069,&var1066};
_S_and2  S_and2_722_1 = {&var1066,&var1065,&var1067};
_S_and2  S_and2_719_1 = {&var362,&var1079,&var1068};
_S_and2  S_and2_715_1 = {&var363,&var1072,&var1069};
_S_and2  S_and2_846_1 = {&var1830,&var1748,&var1070};
_S_and2  S_and2_842_1 = {&var1830,&var1749,&var1071};
_S_and3  S_and3_837_1 = {&var1830,&var363,&var1755,&var1072};
_S_or2  S_or2_845_1 = {&var1750,&var1744,&var1073};
_S_or2  S_or2_840_1 = {&var1748,&var1750,&var1074};
_S_or2  S_or2_836_1 = {&var1750,&var1749,&var1075};
_S_and2  S_and2_818_1 = {&var1744,&var1830,&var1076};
_S_or2  S_or2_809_1 = {&var1751,&var1752,&var1077};
_S_or2  S_or2_805_1 = {&var1809,&var1751,&var1078};
_S_and2  S_and2_802_1 = {&var1752,&var1831,&var1079};
_S_and2  S_and2_801_1 = {&var1809,&var1831,&var1080};
_S_and2  S_and2_830_1 = {&var458,&var1830,&var1081};
_S_and2  S_and2_811_1 = {&var458,&var1761,&var1082};
_S_and2  S_and2_828_1 = {&var1831,&var458,&var1083};
_S_or2  S_or2_822_1 = {&var1831,&var1830,&var1084};
_S_or3  S_or3_815_1 = {&var273,&var1087,&var1088,&var1085};
_S_or4  S_or4_814_1 = {&var1087,&var272,&var1089,&var1740,&var1086};
_S_or3  S_or3_804_1 = {&R4MD31LP2,&var1076,&var1080,&var1087};
_S_or2  S_or2_834_1 = {&var1829,&var1091,&var1088};
_S_or2  S_or2_833_1 = {&var1829,&var1090,&var1089};
_S_and2  S_and2_738_1 = {&var273,&var1743,&var1090};
_S_and3  S_and3_777_1 = {&var1742,&var1756,&var272,&var1091};
_S_and2  S_and2_782_1 = {&R5IS11LDU,&var1106,&var1092};
_S_and3  S_and3_780_1 = {&var1394,&R3IS21LDU,&var1106,&var1093};
_S_and2  S_and2_781_1 = {&R6IS21LDU,&var1106,&var1094};
_S_or2  S_or2_779_1 = {&B8IS22LDU,&A8IS22LDU,&var1095};
_S_and2  S_and2_778_1 = {&var1095,&var1106,&var1096};
_S_and2  S_and2_761_1 = {&var1106,&var1098,&var1097};
_S_or4  S_or4_762_1 = {&A0VN71LZ1,&B0VN71LZ1,&B0VN71LZ2,&A0VN71LZ2,&var1098};
_S_and2  S_and2_760_1 = {&var1103,&var1106,&var1099};
_S_and2  S_and2_747_1 = {&var1109,&var1106,&var1100};
_S_and2  S_and2_746_1 = {&var1832,&var1106,&var1101};
_S_or3  S_or3_745_1 = {&R0NE01LDU,&R0NE02LDU,&R0NE08LDU,&var1102};
_S_or2  S_or2_758_1 = {&R1IS21LDU,&R2IS21LDU,&var1103};
_S_and2  S_and2_744_1 = {&var1106,&var1102,&var1104};
_S_and2  S_and2_742_1 = {&var1810,&var1106,&var1105};
_S_or2  S_or2_732_1 = {&var1831,&var1830,&var1106};
_S_or2  S_or2_167_1 = {&var1400,&var989,&var1107};
_S_or3  S_or3_157_1 = {&var799,&var1399,&var1209,&var1108};
_S_or2  S_or2_148_1 = {&var1673,&var608,&var1109};
_S_or3  S_or3_109_1 = {&var1362,&var594,&var595,&var1110};
_S_or2  S_or2_2193_1 = {&var556,&var433,&var1111};
_S_or3  S_or3_638_1 = {&var1113,&var1114,&var940,&var1112};
_S_and2  S_and2_622_1 = {&var1570,&var1116,&var1113};
_S_and2  S_and2_623_1 = {&var1570,&var1166,&var1114};
_S_or2  S_or2_60_1 = {&var1166,&var1116,&var1115};
_S_and2  S_and2_63_1 = {&var1117,&var1245,&var1116};
_S_and2  S_and2_62_1 = {&var1839,&var1246,&var1117};
_S_or2  S_or2_48_1 = {&A4IS21LDU,&B4IS21LDU,&var1118};
_S_or2  S_or2_35_1 = {&var1490,&var1487,&var1119};
_S_or2  S_or2_39_1 = {&var1490,&var1489,&var1120};
_S_or2  S_or2_20_1 = {&var1394,&var1347,&var1121};
_S_or2  S_or2_8_1 = {&var1849,&var1168,&var1122};
_S_or2  S_or2_14_1 = {&var1168,&var1850,&var1123};
_S_and3  S_and3_1106_1 = {&var468,&var1843,&var1143,&var1124};
_S_and3  S_and3_651_1 = {&var1143,&var471,&var1843,&var1125};
_S_and2  S_and2_1173_1 = {&var1189,&var1127,&var1126};
_S_or2  S_or2_1179_1 = {&var1850,&var1849,&var1127};
_S_or2  S_or2_1525_1 = {&var1851,&var1849,&var1128};
_S_and3  S_and3_1524_1 = {&var1187,&var1128,&var866,&var1129};
_S_or2  S_or2_1074_1 = {&var1851,&var1849,&var1130};
_S_and3  S_and3_1073_1 = {&var1187,&var1130,&var881,&var1131};
_S_or2  S_or2_609_1 = {&var1851,&var1849,&var1132};
_S_and3  S_and3_608_1 = {&var1187,&var1132,&var1571,&var1133};
_S_and2  S_and2_606_1 = {&var358,&var1571,&var1134};
_S_or2  S_or2_243_1 = {&var1851,&var1849,&var1135};
_S_and3  S_and3_242_1 = {&var1187,&var1135,&var1604,&var1136};
_S_and2  S_and2_240_1 = {&var1604,&var359,&var1137};
_S_and3  S_and3_963_1 = {&var1187,&var1140,&var906,&var1138};
_S_and2  S_and2_962_1 = {&var700,&var906,&var1139};
_S_or2  S_or2_964_1 = {&var1851,&var1849,&var1140};
_S_or2  S_or2_1420_1 = {&var1851,&var1849,&var1141};
_S_or2  S_or2_6_1 = {&var1850,&var1849,&var1142};
_S_or3  S_or3_5_1 = {&var1851,&var1850,&var1849,&var1143};
_S_or2  S_or2_821_1 = {&var1751,&var1753,&var1144};
_S_or2  S_or2_472_1 = {&var1832,&var1149,&var1145};
_S_or2  S_or2_450_1 = {&var1832,&var1150,&var1146};
_S_or4  S_or4_451_1 = {&var1146,&var1760,&var1759,&var1145,&var1147};
_S_and2  S_and2_442_1 = {&A8IS22LDU,&var1824,&var1148};
_S_or3  S_or3_422_1 = {&var1814,&var1812,&var1813,&var1149};
_S_or3  S_or3_406_1 = {&var1822,&var1821,&var1823,&var1150};
_S_and2  S_and2_808_1 = {&var1831,&var1753,&var1151};
_S_and2  S_and2_38_1 = {&var1487,&var1488,&var1152};
_S_and2  S_and2_143_1 = {&var1763,&var1385,&var1153};
_S_and2  S_and2_151_1 = {&var1765,&var1385,&var1154};
_S_and2  S_and2_154_1 = {&var1762,&var1385,&var1155};
_S_and2  S_and2_146_1 = {&var1385,&var1764,&var1156};
_S_and2  S_and2_468_1 = {&var1109,&var1816,&var1157};
_S_and2  S_and2_466_1 = {&B8IS22LDU,&var1816,&var1158};
_S_and2  S_and2_464_1 = {&A8IS22LDU,&var1816,&var1159};
_S_and2  S_and2_462_1 = {&R5IS11LDU,&var1816,&var1160};
_S_and2  S_and2_453_1 = {&var1758,&var1824,&var1161};
_S_and2  S_and2_441_1 = {&R5IS11LDU,&var1824,&var1162};
_S_and2  S_and2_445_1 = {&var1109,&var1824,&var1163};
_S_and2  S_and2_113_1 = {&var1168,&var593,&var1164};
_S_and2  S_and2_58_1 = {&var1840,&var1246,&var1165};
_S_and2  S_and2_59_1 = {&var1165,&var1244,&var1166};
_S_and2  S_and2_42_1 = {&var1488,&var1489,&var1167};
_S_and2  S_and2_11_1 = {&var1848,&var1480,&var1168};
_S_and2  S_and2_31_1 = {&var1411,&var457,&var1169};
_S_and2  S_and2_30_1 = {&var1305,&var1394,&var1170};
_S_and2  S_and2_29_1 = {&var1306,&var1394,&var1171};
_S_and2  S_and2_28_1 = {&var1307,&var1394,&var1172};
_S_and2  S_and2_27_1 = {&var1308,&var1394,&var1173};
_S_and2  S_and2_835_1 = {&var1747,&var1755,&var1174};
_S_and2  S_and2_817_1 = {&var1754,&var1831,&var1175};
_S_bol  S_bol_652_1 = {&var1956,&fRM_20_0,&var1176};
_S_bol  S_bol_646_1 = {&var1953,&fRM_20_0,&var1177};
_S_bol  S_bol_637_1 = {&var1953,&fRM_20_03,&var1178};
_S_bol  S_bol_633_1 = {&var1956,&fRM_20_03,&var1179};
_S_bol  S_bol_1093_1 = {&var1953,&fRM_20_03,&var1180};
_S_bol  S_bol_1100_1 = {&var1956,&fRM_20_03,&var1181};
_S_bol  S_bol_1547_1 = {&var1956,&fRM_20_03,&var1182};
_S_bol  S_bol_1549_1 = {&var1953,&fRM_20_03,&var1183};
_S_bol  S_bol_270_1 = {&var1953,&fRM_20_03,&var1184};
_S_bol  S_bol_274_1 = {&var1956,&fRM_20_03,&var1185};
_S_sr  S_sr_82_1 = {array_m82_x_1,&iRM_2_,&var1186};
_S_bol  S_bol_81_1 = {&var1186,&var411,&var1187};
_S_ma  S_ma_84_1 = {array_m84_x_1,&R0MW15IP1,&iRM_8_,&var1188};
_S_bol  S_bol_1174_1 = {&var1190,&fEM_R0UN80RDU,&var1189};
_S_sr  S_sr_1180_1 = {array_m1180_x_1,&iRM_2_,&var1190};
_S_ovbs  S_ovbs_2281_1 = {&lRM_1_,&fEM_A9UZ04RDU,&var1191,&internal1_m2281_tx};
_S_ovbs  S_ovbs_1307_1 = {&lRM_1_,&fEM_A4UZ04RDU,&var1192,&internal1_m1307_tx};
_S_zpfs  S_zpfs_1785_1 = {&var1718,&fEM_B8UL03RDU,&var1193,&internal1_m1785_tx,&internal1_m1785_y0};
_S_zpfs  S_zpfs_1272_1 = {&var1735,&fEM_B8UL03RDU,&var1194,&internal1_m1272_tx,&internal1_m1272_y0};
_S_ma  S_ma_1335_1 = {array_m1335_x_1,&var1687,&iRM_8_,&var1195};
_S_ma  S_ma_895_1 = {array_m895_x_1,&var1647,&iRM_8_,&var1196};
_S_ma  S_ma_993_1 = {array_m993_x_1,&var1538,&iRM_8_,&var1197};
_S_ma  S_ma_1449_1 = {array_m1449_x_1,&var1506,&iRM_8_,&var1198};
_S_ma  S_ma_537_1 = {array_m537_x_1,&var1567,&iRM_8_,&var1199};
_S_ma  S_ma_164_1 = {array_m164_x_1,&var1600,&iRM_8_,&var1200};
_S_zpfs  S_zpfs_1492_1 = {&var1523,&fEM_A3UL03RDU,&var1201,&internal1_m1492_tx,&internal1_m1492_y0};
_S_zpfs  S_zpfs_1041_1 = {&var1555,&fEM_A3UL03RDU,&var1202,&internal1_m1041_tx,&internal1_m1041_y0};
_S_zpfs  S_zpfs_1382_1 = {&var1705,&fEM_A2UL03RDU,&var1203,&internal1_m1382_tx,&internal1_m1382_y0};
_S_rs  S_rs_1198_1 = {&var1050,&var1049,&var1204,&vainSBool,&internal1_m1198_q0};
_S_rs  S_rs_1196_1 = {&var367,&var1212,&var1205,&vainSBool,&internal1_m1196_q0};
_S_rs  S_rs_1195_1 = {&var1050,&var1048,&var1206,&vainSBool,&internal1_m1195_q0};
_S_rs  S_rs_1193_1 = {&var366,&var1212,&var1207,&vainSBool,&internal1_m1193_q0};
_S_rs  S_rs_1192_1 = {&var1050,&var1047,&var1208,&vainSBool,&internal1_m1192_q0};
_S_rs  S_rs_1190_1 = {&var365,&var1212,&var1209,&vainSBool,&internal1_m1190_q0};
_S_rs  S_rs_1189_1 = {&var1050,&var1046,&var1210,&vainSBool,&internal1_m1189_q0};
_S_rs  S_rs_1187_1 = {&var364,&var1212,&var1211,&vainSBool,&internal1_m1187_q0};
_S_rs  S_rs_1186_1 = {&var1050,&var412,&var1212,&vainSBool,&internal1_m1186_q0};
_S_noto  S_noto_2103_1 = {&var668,&var1213};
_S_swtakt  S_swtakt_52_1 = {&var588,&var1214,&internal1_m52_x0};
_S_noto  S_noto_1172_1 = {&var1226,&var1215};
_S_noto  S_noto_1146_1 = {&var1224,&var1216};
_S_noto  S_noto_1158_1 = {&var1225,&var1217};
_S_rs  S_rs_1105_1 = {&var1227,&var807,&var1218,&vainSBool,&internal1_m1105_q0};
_S_swtakt  S_swtakt_1593_1 = {&var766,&var1219,&internal1_m1593_x0};
_S_swtakt  S_swtakt_1637_1 = {&var754,&var1220,&internal1_m1637_x0};
_S_swtakt  S_swtakt_1633_1 = {&var748,&var1221,&internal1_m1633_x0};
_S_swtakt  S_swtakt_2063_1 = {&var655,&var1222,&internal1_m2063_x0};
_S_swtakt  S_swtakt_2028_1 = {&var629,&var1223,&internal1_m2028_x0};
_S_rs  S_rs_1145_1 = {&var1298,&var795,&var1224,&vainSBool,&internal1_m1145_q0};
_S_rs  S_rs_1157_1 = {&var1298,&var796,&var1225,&vainSBool,&internal1_m1157_q0};
_S_rs  S_rs_1169_1 = {&var1298,&var797,&var1226,&vainSBool,&internal1_m1169_q0};
_S_rs  S_rs_1178_1 = {&var1298,&var798,&var1227,&vainSBool,&internal1_m1178_q0};
_S_noto  S_noto_1133_1 = {&var813,&var1228};
_S_noto  S_noto_1163_1 = {&var813,&var1229};
_S_noto  S_noto_1162_1 = {&var817,&var1230};
_S_rs  S_rs_1156_1 = {&var791,&var793,&var1231,&vainSBool,&internal1_m1156_q0};
_S_rs  S_rs_1171_1 = {&var1298,&var789,&var1232,&vainSBool,&internal1_m1171_q0};
_S_bol  S_bol_1153_1 = {&var1941,&var518,&var1233};
_S_bol  S_bol_1152_1 = {&var1944,&var518,&var1234};
_S_noto  S_noto_1112_1 = {&var1293,&var1235};
_S_bol  S_bol_1150_1 = {&var518,&var1941,&var1236};
_S_bol  S_bol_1149_1 = {&var518,&var1944,&var1237};
_S_noto  S_noto_1136_1 = {&var1294,&var1238};
_S_rs  S_rs_2121_1 = {&var673,&var664,&var1239,&vainSBool,&internal1_m2121_q0};
_S_rs  S_rs_2120_1 = {&var673,&var665,&var1240,&vainSBool,&internal1_m2120_q0};
_S_noto  S_noto_342_1 = {&var1021,&var1241};
_S_noto  S_noto_325_1 = {&var1014,&var1242};
_S_noto  S_noto_295_1 = {&var1033,&var1243};
_S_noto  S_noto_56_1 = {&var1255,&var1244};
_S_noto  S_noto_67_1 = {&var1277,&var1245};
_S_noto  S_noto_66_1 = {&var1212,&var1246};
_S_noto  S_noto_2115_1 = {&B2IS11LDU,&var1247};
_S_noto  S_noto_2113_1 = {&A2IS11LDU,&var1248};
_S_noto  S_noto_301_1 = {&var471,&var1249};
_S_noto  S_noto_2122_1 = {&B2IS11LDU,&var1250};
_S_noto  S_noto_2097_1 = {&A2IS11LDU,&var1251};
_S_noto  S_noto_288_1 = {&var1117,&var1252};
_S_noto  S_noto_346_1 = {&var1165,&var1253};
_S_bolz  S_bolz_350_1 = {&iRM_2_,&var1256,&var1254};
_S_provsbr  S_provsbr_345_1 = {&var1316,&var977,&var1331,&var1348,&var1342,&var1337,&var1334,&var1332,&var1346,&var1341,&var1339,&var1335,&iRM_10_,array_m345_Tpr_1,array_m345_type_1,&var1255,&var1256,&var1257,&var1258,&var1259,&var1260,&var1261,&var1262,&var1263,&internal1_m345_Step,array_m345_rz_1,&internal1_m345_TimS,&internal1_m345_FinPr0,&internal1_m345_ErrPr0,&internal1_m345_sbINI0,&internal1_m345_sbVuIS0,&internal1_m345_sb2UR0,&internal1_m345_sbNupIS0,&internal1_m345_sbVuRB0,&internal1_m345_MyFirstEnterFlag};
_S_orni  S_orni_349_1 = {array_m349_x_1,&iRM_5_,&vainSBool,&var1264};
_S_cntch  S_cntch_353_1 = {&var1264,&var1265,&internal1_m353_x0};
_S_bolz  S_bolz_327_1 = {&iRM_20_,&var1279,&var1266};
_S_equz_p  S_equz_p_326_1 = {&var1278,&iRM_0_,&var1267};
_S_decatron  S_decatron_311_1 = {&var1013,&var1268,&internal1_m311_TimS};
_S_noto  S_noto_1109_1 = {&R2IS21LDU,&var1269};
_S_noto  S_noto_1103_1 = {&R1IS21LDU,&var1270};
_S_andn  S_andn_283_1 = {array_m283_x_1,&iRM_7_,&var1271};
_S_noto  S_noto_285_1 = {&R0MD33LP1,&var1272};
_S_noto  S_noto_293_1 = {&R2IS21LDU,&var1273};
_S_noto  S_noto_289_1 = {&R1IS21LDU,&var1274};
_S_noto  S_noto_280_1 = {&R1IS11LDU,&var1275};
_S_noto  S_noto_277_1 = {&R2IS11LDU,&var1276};
_S_provsbr  S_provsbr_287_1 = {&var1318,&var1030,&var1331,&var1348,&var1342,&var1337,&var1334,&var1332,&var1346,&var1341,&var1339,&var1335,&iRM_10_,array_m287_Tpr_1,array_m287_type_1,&var1277,&var1278,&var1279,&var1280,&var1281,&var1282,&var1283,&var1284,&var1285,&internal1_m287_Step,array_m287_rz_1,&internal1_m287_TimS,&internal1_m287_FinPr0,&internal1_m287_ErrPr0,&internal1_m287_sbINI0,&internal1_m287_sbVuIS0,&internal1_m287_sb2UR0,&internal1_m287_sbNupIS0,&internal1_m287_sbVuRB0,&internal1_m287_MyFirstEnterFlag};
_S_rs  S_rs_1567_1 = {&var1287,&var788,&var1286,&vainSBool,&internal1_m1567_q0};
_S_provsbr  S_provsbr_1568_1 = {&var1286,&R0MD34LP1,&var1331,&var1348,&var1342,&var1337,&var1334,&var1332,&var1346,&var1341,&var1339,&var1335,&iRM_6_,array_m1568_Tpr_1,array_m1568_type_1,&var1287,&vainSInt,&vainSInt,&vainSBool,&var1288,&var1289,&var1290,&var1291,&var1292,&internal1_m1568_Step,array_m1568_rz_1,&internal1_m1568_TimS,&internal1_m1568_FinPr0,&internal1_m1568_ErrPr0,&internal1_m1568_sbINI0,&internal1_m1568_sbVuIS0,&internal1_m1568_sb2UR0,&internal1_m1568_sbNupIS0,&internal1_m1568_sbVuRB0,&internal1_m1568_MyFirstEnterFlag};
_S_abs_subf  S_abs_subf_1115_1 = {&var518,&var1944,&fEM_B8UC01RDU,&vainSFloat,&var1293};
_S_abs_subf  S_abs_subf_1128_1 = {&var1941,&var518,&fEM_B8UC01RDU,&vainSFloat,&var1294};
_S_noto  S_noto_711_1 = {&var981,&var1295};
_S_noto  S_noto_659_1 = {&var997,&var1296};
_S_noto  S_noto_49_1 = {&var514,&var1297};
_S_noto  S_noto_1131_1 = {&var1495,&var1298};
_S_rs  S_rs_1141_1 = {&var790,&var609,&var1299,&vainSBool,&internal1_m1141_q0};
_S_rs  S_rs_1138_1 = {&var794,&var789,&var1300,&vainSBool,&internal1_m1138_q0};
_S_rs  S_rs_1140_1 = {&var1298,&var609,&var1301,&vainSBool,&internal1_m1140_q0};
_S_rs  S_rs_1134_1 = {&var1298,&var792,&var1302,&vainSBool,&internal1_m1134_q0};
_S_noto  S_noto_648_1 = {&A2IS21LDU,&var1303};
_S_noto  S_noto_650_1 = {&B2IS21LDU,&var1304};
_S_noto  S_noto_25_1 = {&B2IS21LDU,&var1305};
_S_noto  S_noto_24_1 = {&B1IS21LDU,&var1306};
_S_noto  S_noto_23_1 = {&A1IS21LDU,&var1307};
_S_noto  S_noto_22_1 = {&A2IS21LDU,&var1308};
_S_newstage  S_newstage_660_1 = {&var335,&var332,&A2IS12LDU,&B2IS12LDU,&var1309};
_S_noto  S_noto_649_1 = {&B2IS12LDU,&var1310};
_S_noto  S_noto_647_1 = {&A2IS12LDU,&var1311};
_S_noto  S_noto_359_1 = {&var972,&var1312};
_S_noto  S_noto_363_1 = {&var971,&var1313};
_S_noto  S_noto_1102_1 = {&var1109,&var1314};
_S_rs  S_rs_825_1 = {&var969,&var591,&var1315,&vainSBool,&internal1_m825_q0};
_S_rs  S_rs_355_1 = {&var973,&var974,&var1316,&vainSBool,&internal1_m355_q0};
_S_rs  S_rs_351_1 = {&var975,&var976,&var1317,&vainSBool,&internal1_m351_q0};
_S_rs  S_rs_307_1 = {&var1029,&var1015,&var1318,&vainSBool,&internal1_m307_q0};
_S_orni  S_orni_303_1 = {array_m303_x_1,&iRM_5_,&vainSBool,&var1319};
_S_cntch  S_cntch_306_1 = {&var1319,&var1320,&internal1_m306_x0};
_S_noto  S_noto_1606_1 = {&var1339,&var1321};
_S_noto  S_noto_1662_1 = {&var1341,&var1322};
_S_noto  S_noto_1664_1 = {&var1346,&var1323};
_S_noto  S_noto_2044_1 = {&var1332,&var1324};
_S_noto  S_noto_2078_1 = {&var1335,&var1325};
_S_noto  S_noto_2059_1 = {&var1222,&var1326};
_S_noto  S_noto_2022_1 = {&var1223,&var1327};
_S_noto  S_noto_1634_1 = {&var1221,&var1328};
_S_noto  S_noto_1629_1 = {&var1220,&var1329};
_S_noto  S_noto_1589_1 = {&var1219,&var1330};
_S_rs  S_rs_2050_1 = {&var773,&var613,&var1331,&vainSBool,&internal1_m2050_q0};
_S_rs  S_rs_2038_1 = {&var628,&var625,&var1332,&vainSBool,&internal1_m2038_q0};
_S_rs  S_rs_2029_1 = {&var624,&var1223,&var1333,&vainSBool,&internal1_m2029_q0};
_S_rs  S_rs_2104_1 = {&var773,&var642,&var1334,&vainSBool,&internal1_m2104_q0};
_S_rs  S_rs_2071_1 = {&var650,&var649,&var1335,&vainSBool,&internal1_m2071_q0};
_S_rs  S_rs_2064_1 = {&var652,&var1222,&var1336,&vainSBool,&internal1_m2064_q0};
_S_rs  S_rs_1620_1 = {&var773,&var759,&var1337,&vainSBool,&internal1_m1620_q0};
_S_kvf  S_kvf_1607_1 = {&var1340,&var760,&fRM_0_0,&var1338,&vainSInt,&vainSInt,&internal1_m1607_x0,&internal1_m1607_y0,&bFirstEnterFlag};
_S_rs  S_rs_1603_1 = {&var765,&var760,&var1339,&vainSBool,&internal1_m1603_q0};
_S_rs  S_rs_1594_1 = {&var762,&var1219,&var1340,&vainSBool,&internal1_m1594_q0};
_S_rs  S_rs_1653_1 = {&var755,&var750,&var1341,&vainSBool,&internal1_m1653_q0};
_S_rs  S_rs_1673_1 = {&var773,&var756,&var1342,&vainSBool,&internal1_m1673_q0};
_S_rs  S_rs_1639_1 = {&var753,&var1220,&var1343,&vainSBool,&internal1_m1639_q0};
_S_kvf  S_kvf_1654_1 = {&var1343,&var750,&fRM_0_0,&var1344,&vainSInt,&vainSInt,&internal1_m1654_x0,&internal1_m1654_y0,&bFirstEnterFlag};
_S_cntch  S_cntch_1578_1 = {&var775,&var1345,&internal1_m1578_x0};
_S_rs  S_rs_1659_1 = {&var747,&var741,&var1346,&vainSBool,&internal1_m1659_q0};
_S_rs  S_rs_26_1 = {&var1394,&var1169,&var1347,&vainSBool,&internal1_m26_q0};
_S_rs  S_rs_1674_1 = {&var773,&var740,&var1348,&vainSBool,&internal1_m1674_q0};
_S_noto  S_noto_1556_1 = {&var769,&var1349};
_S_noto  S_noto_1554_1 = {&var1168,&var1350};
_S_rs  S_rs_700_1 = {&var1726,&var984,&var1351,&vainSBool,&internal1_m700_q0};
_S_rs  S_rs_685_1 = {&var1726,&var991,&var1352,&vainSBool,&internal1_m685_q0};
_S_rs  S_rs_712_1 = {&var1726,&var992,&var1353,&vainSBool,&internal1_m712_q0};
_S_rs  S_rs_696_1 = {&var1726,&var1003,&var1354,&vainSBool,&internal1_m696_q0};
_S_rs  S_rs_680_1 = {&var1726,&var1006,&var1355,&vainSBool,&internal1_m680_q0};
_S_rs  S_rs_678_1 = {&var1726,&var1008,&var1356,&vainSBool,&internal1_m678_q0};
_S_rs  S_rs_666_1 = {&var1011,&var1729,&var1357,&vainSBool,&internal1_m666_q0};
_S_rsun  S_rsun_1570_1 = {&var773,&var1479,&vainSLong,&var1358,&internal1_m1570_q0};
_S_noto  S_noto_1477_1 = {&B3MD12LP1,&var1359};
_S_noto  S_noto_1996_1 = {&B3IS11LDU,&var1360};
_S_noto  S_noto_1970_1 = {&A3IS11LDU,&var1361};
_S_noto  S_noto_112_1 = {&var1168,&var1362};
_S_noto  S_noto_111_1 = {&var1367,&var1363};
_S_rs  S_rs_676_1 = {&var1726,&var1010,&var1364,&vainSBool,&internal1_m676_q0};
_S_orni  S_orni_1311_1 = {array_m1311_x_1,&iRM_5_,&var1365,&vainSLong};
_S_orni  S_orni_1295_1 = {array_m1295_x_1,&iRM_4_,&var1366,&vainSLong};
_S_rs  S_rs_110_1 = {&var1110,&var1164,&var1367,&vainSBool,&internal1_m110_q0};
_S_noto  S_noto_1999_1 = {&var691,&var1368};
_S_noto  S_noto_1998_1 = {&var690,&var1369};
_S_noto  S_noto_2010_1 = {&B3IS22LDU,&var1370};
_S_noto  S_noto_1991_1 = {&A3IS22LDU,&var1371};
_S_newstage  S_newstage_1994_1 = {&var707,&var703,&var706,&var702,&vainSBool};
_S_noto  S_noto_1938_1 = {&var1457,&var1372};
_S_rs  S_rs_1820_1 = {&var249,&var482,&var1373,&vainSBool,&internal1_m1820_q0};
_S_rs  S_rs_1819_1 = {&var242,&var484,&var1374,&vainSBool,&internal1_m1819_q0};
_S_rs  S_rs_1818_1 = {&var248,&var486,&var1375,&vainSBool,&internal1_m1818_q0};
_S_rs  S_rs_1817_1 = {&var224,&var488,&var1376,&vainSBool,&internal1_m1817_q0};
_S_rs  S_rs_1853_1 = {&var457,&var490,&var1377,&vainSBool,&internal1_m1853_q0};
_S_rs  S_rs_1852_1 = {&var260,&var493,&var1378,&vainSBool,&internal1_m1852_q0};
_S_rs  S_rs_1851_1 = {&var261,&var493,&var1379,&vainSBool,&internal1_m1851_q0};
_S_noto  S_noto_1363_1 = {&A2MD12LP1,&var1380};
_S_noto  S_noto_1347_1 = {&B2MD12LP1,&var1381};
_S_noto  S_noto_552_1 = {&B1MD12LP1,&var1382};
_S_ma  S_ma_1609_1 = {array_m1609_x_1,&var1358,&iRM_16_,&var1383};
_S_noto  S_noto_1564_1 = {&var1025,&var1384};
_S_noto  S_noto_141_1 = {&var1168,&var1385};
_S_equz_p  S_equz_p_1976_1 = {&R0MW14IP2,&iRM_5_,&var1386};
_S_equz_p  S_equz_p_1975_1 = {&R0MW14IP2,&iRM_4_,&var1387};
_S_equz_p  S_equz_p_1974_1 = {&R0MW14IP2,&iRM_3_,&var1388};
_S_equz_p  S_equz_p_1972_1 = {&R0MW14IP2,&iRM_1_,&vainSBool};
_S_equz_p  S_equz_p_1973_1 = {&R0MW14IP2,&iRM_2_,&var1389};
_S_noto  S_noto_2031_1 = {&B3IS11LDU,&var1390};
_S_noto  S_noto_2026_1 = {&A3IS11LDU,&var1391};
_S_noto  S_noto_2068_1 = {&B2IS11LDU,&var1392};
_S_noto  S_noto_2072_1 = {&A2IS11LDU,&var1393};
_S_noto  S_noto_12_1 = {&var1848,&var1394};
_S_rs  S_rs_2135_1 = {&var576,&var677,&var1395,&vainSBool,&internal1_m2135_q0};
_S_rs  S_rs_1913_1 = {&var719,&var503,&var1396,&vainSBool,&internal1_m1913_q0};
_S_rs  S_rs_1905_1 = {&var245,&var504,&var1397,&vainSBool,&internal1_m1905_q0};
_S_rs  S_rs_1910_1 = {&var262,&var505,&var1398,&vainSBool,&internal1_m1910_q0};
_S_rs  S_rs_1904_1 = {&var246,&var506,&var1399,&vainSBool,&internal1_m1904_q0};
_S_rs  S_rs_1907_1 = {&var266,&var507,&var1400,&vainSBool,&internal1_m1907_q0};
_S_equz_p  S_equz_p_99_1 = {&R0MW16IP1,&iRM_10_,&var1401};
_S_noto  S_noto_179_1 = {&A1MD12LP1,&var1402};
_S_rs  S_rs_2349_1 = {&var236,&var233,&var1403,&vainSBool,&internal1_m2349_q0};
_S_rs  S_rs_2345_1 = {&var252,&var324,&var1404,&vainSBool,&internal1_m2345_q0};
_S_rs  S_rs_1878_1 = {&var265,&var500,&var1405,&vainSBool,&internal1_m1878_q0};
_S_rs  S_rs_1870_1 = {&var457,&var489,&var1406,&vainSBool,&internal1_m1870_q0};
_S_rs  S_rs_1868_1 = {&var247,&var490,&var1407,&vainSBool,&internal1_m1868_q0};
_S_rs  S_rs_1864_1 = {&var260,&var491,&var1408,&vainSBool,&internal1_m1864_q0};
_S_rs  S_rs_1860_1 = {&var222,&var493,&var1409,&vainSBool,&internal1_m1860_q0};
_S_rs  S_rs_1862_1 = {&var261,&var492,&var1410,&vainSBool,&internal1_m1862_q0};
_S_rs  S_rs_19_1 = {&var1121,&var597,&var1411,&vainSBool,&internal1_m19_q0};
_S_equz_p  S_equz_p_98_1 = {&R0MW16IP1,&iRM_9_,&var1412};
_S_equz_p  S_equz_p_97_1 = {&R0MW16IP1,&iRM_8_,&var1413};
_S_noto  S_noto_1025_1 = {&A3MD12LP1,&var1414};
_S_equz_p  S_equz_p_96_1 = {&R0MW16IP1,&iRM_7_,&var1415};
_S_equz_p  S_equz_p_95_1 = {&R0MW16IP1,&iRM_6_,&var1416};
_S_equz_p  S_equz_p_94_1 = {&R0MW16IP1,&iRM_5_,&var1417};
_S_rs  S_rs_1843_1 = {&var249,&var481,&var1418,&vainSBool,&internal1_m1843_q0};
_S_rs  S_rs_1841_1 = {&var241,&var482,&var1419,&vainSBool,&internal1_m1841_q0};
_S_rs  S_rs_1837_1 = {&var259,&var484,&var1420,&vainSBool,&internal1_m1837_q0};
_S_rs  S_rs_1839_1 = {&var242,&var483,&var1421,&vainSBool,&internal1_m1839_q0};
_S_rs  S_rs_1835_1 = {&var248,&var485,&var1422,&vainSBool,&internal1_m1835_q0};
_S_rs  S_rs_1833_1 = {&var225,&var486,&var1423,&vainSBool,&internal1_m1833_q0};
_S_rs  S_rs_2258_1 = {&var339,&var686,&var1424,&vainSBool,&internal1_m2258_q0};
_S_rs  S_rs_2255_1 = {&var340,&var687,&var1425,&vainSBool,&internal1_m2255_q0};
_S_equz_p  S_equz_p_316_1 = {&var1268,&iRM_0_,&var1426};
_S_noto  S_noto_2259_1 = {&var1424,&var1427};
_S_noto  S_noto_2250_1 = {&var601,&var1428};
_S_noto  S_noto_2235_1 = {&var1430,&var1429};
_S_rs  S_rs_2234_1 = {&var279,&var683,&var1430,&vainSBool,&internal1_m2234_q0};
_S_noto  S_noto_2217_1 = {&var1432,&var1431};
_S_rs  S_rs_2216_1 = {&var281,&var680,&var1432,&vainSBool,&internal1_m2216_q0};
_S_noto  S_noto_2256_1 = {&var1425,&var1433};
_S_noto  S_noto_2248_1 = {&var600,&var1434};
_S_noto  S_noto_2148_1 = {&var1436,&var1435};
_S_rs  S_rs_2147_1 = {&var575,&var678,&var1436,&vainSBool,&internal1_m2147_q0};
_S_noto  S_noto_2136_1 = {&var1395,&var1437};
_S_noto  S_noto_2143_1 = {&var598,&var1438};
_S_noto  S_noto_2130_1 = {&var599,&var1439};
_S_rs  S_rs_1829_1 = {&var258,&var488,&var1440,&vainSBool,&internal1_m1829_q0};
_S_rs  S_rs_1831_1 = {&var224,&var487,&var1441,&vainSBool,&internal1_m1831_q0};
_S_rs  S_rs_1815_1 = {&var239,&var473,&var1442,&vainSBool,&internal1_m1815_q0};
_S_rs  S_rs_1813_1 = {&var257,&var474,&var1443,&vainSBool,&internal1_m1813_q0};
_S_rs  S_rs_1811_1 = {&var238,&var475,&var1444,&vainSBool,&internal1_m1811_q0};
_S_rs  S_rs_1809_1 = {&var256,&var476,&var1445,&vainSBool,&internal1_m1809_q0};
_S_noto  S_noto_1933_1 = {&B3IS22LDU,&var1446};
_S_noto  S_noto_1932_1 = {&A3IS22LDU,&var1447};
_S_noto  S_noto_1931_1 = {&B2IS12LDU,&var1448};
_S_noto  S_noto_1930_1 = {&A2IS12LDU,&var1449};
_S_noto  S_noto_1929_1 = {&B1IS12LDU,&var1450};
_S_noto  S_noto_1928_1 = {&A1IS12LDU,&var1451};
_S_noto  S_noto_1958_1 = {&B3IS21LDU,&var1452};
_S_noto  S_noto_1952_1 = {&B2IS21LDU,&var1453};
_S_noto  S_noto_1957_1 = {&A3IS21LDU,&var1454};
_S_noto  S_noto_1955_1 = {&B4IS21LDU,&var1455};
_S_noto  S_noto_1956_1 = {&A4IS21LDU,&var1456};
_S_andn  S_andn_1941_1 = {array_m1941_x_1,&iRM_17_,&var1457};
_S_noto  S_noto_1950_1 = {&B1IS21LDU,&var1458};
_S_noto  S_noto_1951_1 = {&A2IS21LDU,&var1459};
_S_noto  S_noto_1949_1 = {&A1IS21LDU,&var1460};
_S_rs  S_rs_1808_1 = {&var1465,&var477,&var1461,&vainSBool,&internal1_m1808_q0};
_S_rs  S_rs_1806_1 = {&var240,&var478,&var1462,&vainSBool,&internal1_m1806_q0};
_S_rs  S_rs_1805_1 = {&var1465,&var479,&var1463,&vainSBool,&internal1_m1805_q0};
_S_rs  S_rs_1803_1 = {&var223,&var480,&var1464,&vainSBool,&internal1_m1803_q0};
_S_newstage  S_newstage_2284_1 = {&var1477,&var1471,&var1476,&var1470,&var1465};
_S_samhd  S_samhd_2286_1 = {&var731,&var732,&var732,&var1462,&var1461,&var1462,&var1461,&B9IS11LDU,&B9IS11LDU,&B9IS21LDU,&B9IS21LDU,&bRM_1_,&fEM_A9UZ05RDU,&fEM_A9UZ03RDU,&fEM_A9UZ04RDU,&var1466,&var1467,&var1468,&vainSBool,&var1469,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1470,&var1471,&internal1_m2286_DvUp0,&internal1_m2286_DvDw0,&internal1_m2286_FDvUp0,&internal1_m2286_FDvDw0,&internal1_m2286_BlDv0,&internal1_m2286_Pkv0,&internal1_m2286_Pkav0,&internal1_m2286_Zkv0,&internal1_m2286_Zkav0,&internal1_m2286_txNm,&internal1_m2286_txSm,&internal1_m2286_txHr,&internal1_m2286_txLd,&internal1_m2286_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_2280_1 = {&var731,&var733,&var733,&var1464,&var1463,&var1464,&var1463,&A9IS11LDU,&A9IS11LDU,&A9IS21LDU,&A9IS21LDU,&bRM_1_,&fEM_A9UZ05RDU,&fEM_A9UZ03RDU,&fEM_A9UZ04RDU,&var1472,&var1473,&var1474,&vainSBool,&var1475,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1476,&var1477,&internal1_m2280_DvUp0,&internal1_m2280_DvDw0,&internal1_m2280_FDvUp0,&internal1_m2280_FDvDw0,&internal1_m2280_BlDv0,&internal1_m2280_Pkv0,&internal1_m2280_Pkav0,&internal1_m2280_Zkv0,&internal1_m2280_Zkav0,&internal1_m2280_txNm,&internal1_m2280_txSm,&internal1_m2280_txHr,&internal1_m2280_txLd,&internal1_m2280_fef,&bFirstEnterFlag};
_S_orni  S_orni_1571_1 = {array_m1571_x_1,&iRM_5_,&var1478,&var1479};
_S_noto  S_noto_78_1 = {&var603,&var1480};
_S_maz  S_maz_322_1 = {array_m322_x_1,&R0MW12IP1,&iRM_3_,&var1481};
_S_maz  S_maz_313_1 = {array_m313_x_1,&R0MW12IP1,&iRM_3_,&var1482};
_S_rs  S_rs_1644_1 = {&var744,&var1221,&var1483,&vainSBool,&internal1_m1644_q0};
_S_kvf  S_kvf_1648_1 = {&var1483,&var741,&fRM_0_0,&var1484,&vainSInt,&vainSInt,&internal1_m1648_x0,&internal1_m1648_y0,&bFirstEnterFlag};
_S_kvf  S_kvf_2086_1 = {&var658,&var646,&fRM_0_0,&var1485,&vainSInt,&vainSInt,&internal1_m2086_x0,&internal1_m2086_y0,&bFirstEnterFlag};
_S_kvf  S_kvf_2047_1 = {&var618,&var615,&fRM_0_0,&var1486,&vainSInt,&vainSInt,&internal1_m2047_x0,&internal1_m2047_y0,&bFirstEnterFlag};
_S_equz_p  S_equz_p_37_1 = {&R0MW13IP1,&iRM_1_,&var1487};
_S_noto  S_noto_34_1 = {&var1490,&var1488};
_S_equz_p  S_equz_p_41_1 = {&R0MW13IP1,&iRM_2_,&var1489};
_S_equz_p  S_equz_p_32_1 = {&R0MW13IP1,&iRM_3_,&var1490};
_S_noto  S_noto_2090_1 = {&var1336,&var1491};
_S_rs  S_rs_298_1 = {&var1031,&var1032,&var1492,&vainSBool,&internal1_m298_q0};
_S_orn  S_orn_657_1 = {array_m657_x_1,&iRM_5_,&var1493};
_S_noto  S_noto_1122_1 = {&lEM_R0MD01LC1,&var1494};
_S_rs  S_rs_1113_1 = {&var808,&var1124,&var1495,&vainSBool,&internal1_m1113_q0};
_S_rs  S_rs_688_1 = {&var986,&var988,&var1496,&vainSBool,&internal1_m688_q0};
_S_noto  S_noto_1551_1 = {&var1167,&var1497};
_S_orn  S_orn_1521_1 = {array_m1521_x_1,&iRM_8_,&var1498};
_S_noto  S_noto_1520_1 = {&var1666,&var1499};
_S_noto  S_noto_1519_1 = {&var1676,&var1500};
_S_noto  S_noto_1497_1 = {&var1168,&var1501};
_S_noto  S_noto_1510_1 = {&R8IS11LDU,&var1502};
_S_charint  S_charint_1442_1 = {&var1505,&var1503};
_S_ornc  S_ornc_1448_1 = {array_m1448_x_1,&iRM_3_,&var1504,&var1505};
_S_fsumz  S_fsumz_1443_1 = {&var1503,&iRM_1_,&var1506};
_S_cnshd  S_cnshd_1450_1 = {&R0MD34LP1,&var1947,&var1198,&var522,&var1504,&var853,&var849,&iRM_1_,array_m1450_Lt_fw_1,array_m1450_Vr_fw_1,&iRM_1_,array_m1450_Lt_bw_1,array_m1450_Vr_bw_1,&fEM_A3UC08RDU,&fEM_A3UC07RDU,&fEM_A3UL01RDU,&fEM_A3UC02RDU,&var1507,&vainSBool,&var1508,&var1509,&var1510,&var1511,&var1512,&var1513,&var1514,&var1515,&var1516,&var1517,&internal1_m1450_X0,&internal1_m1450_t0,&internal1_m1450_BLDv0};
_S_zpfs  S_zpfs_1467_1 = {&var1526,&fRM_2_0,&var1518,&internal1_m1467_tx,&internal1_m1467_y0};
_S_zpfs  S_zpfs_1468_1 = {&var1525,&fRM_3_0,&var1519,&internal1_m1468_tx,&internal1_m1468_y0};
_S_fnapb  S_fnapb_1476_1 = {&var1947,&var1198,&var852,&R0MD34LP1,&var1509,&var1516,&fEM_B8UV04RDU,&fEM_A3UV01RDU,&fEM_A3UV02RDU,&fEM_A3UC06RDU,&fEM_A3UC05RDU,&iRM_60_,&fEM_A3UL04RDU,&fEM_A3UL05RDU,&fEM_A3UL03RDU,&var1520,&var1521,&var1522,&var1523,&var1524,&var1525,&var1526,&vainSFloat,&internal1_m1476_xptr,array_m1476_x0_1,array_m1476_tim0_1,&internal1_m1476_sumtim,&internal1_m1476_StSpeed,&internal1_m1476_Vz0,&internal1_m1476_flRazg,&internal1_m1476_DelSp,&internal1_m1476_z0,&internal1_m1476_txZS,&internal1_m1476_tx,&internal1_m1476_txd,&internal1_m1476_txMBl,&internal1_m1476_txBl,&internal1_m1476_Speed0,&internal1_m1476_xz0,&internal1_m1476_tz0,&internal1_m1476_Shift0,&internal1_m1476_ShCntlSp0,&internal1_m1476_ShiftControl,&bFirstEnterFlag};
_S_newstage  S_newstage_1006_1 = {&var1536,&var1504,&var1539,&var1507,&var1527};
_S_rs  S_rs_686_1 = {&var987,&var991,&var1528,&vainSBool,&internal1_m686_q0};
_S_noto  S_noto_1099_1 = {&var1152,&var1529};
_S_orn  S_orn_1068_1 = {array_m1068_x_1,&iRM_8_,&var1530};
_S_noto  S_noto_1067_1 = {&var1666,&var1531};
_S_noto  S_noto_1066_1 = {&var1676,&var1532};
_S_noto  S_noto_1046_1 = {&var1168,&var1533};
_S_noto  S_noto_1059_1 = {&R8IS11LDU,&var1534};
_S_charint  S_charint_986_1 = {&var1537,&var1535};
_S_ornc  S_ornc_992_1 = {array_m992_x_1,&iRM_3_,&var1536,&var1537};
_S_fsumz  S_fsumz_987_1 = {&var1535,&iRM_1_,&var1538};
_S_cnshd  S_cnshd_994_1 = {&R0MD34LP1,&var1950,&var1197,&var526,&var1536,&var888,&var889,&iRM_1_,array_m994_Lt_fw_1,array_m994_Vr_fw_1,&iRM_1_,array_m994_Lt_bw_1,array_m994_Vr_bw_1,&fEM_A3UC08RDU,&fEM_A3UC07RDU,&fEM_A3UL01RDU,&fEM_A3UC02RDU,&var1539,&vainSBool,&var1540,&var1541,&var1542,&var1543,&var1544,&var1545,&var1546,&var1547,&var1548,&var1549,&internal1_m994_X0,&internal1_m994_t0,&internal1_m994_BLDv0};
_S_zpfs  S_zpfs_1017_1 = {&var1558,&fRM_2_0,&var1550,&internal1_m1017_tx,&internal1_m1017_y0};
_S_zpfs  S_zpfs_1016_1 = {&var1557,&fRM_3_0,&var1551,&internal1_m1016_tx,&internal1_m1016_y0};
_S_fnapb  S_fnapb_1024_1 = {&var1950,&var1197,&var887,&R0MD34LP1,&var1541,&var1548,&fEM_B8UV04RDU,&fEM_A3UV01RDU,&fEM_A3UV02RDU,&fEM_A3UC06RDU,&fEM_A3UC05RDU,&iRM_60_,&fEM_A3UL04RDU,&fEM_A3UL05RDU,&fEM_A3UL03RDU,&var1552,&var1553,&var1554,&var1555,&var1556,&var1557,&var1558,&vainSFloat,&internal1_m1024_xptr,array_m1024_x0_1,array_m1024_tim0_1,&internal1_m1024_sumtim,&internal1_m1024_StSpeed,&internal1_m1024_Vz0,&internal1_m1024_flRazg,&internal1_m1024_DelSp,&internal1_m1024_z0,&internal1_m1024_txZS,&internal1_m1024_tx,&internal1_m1024_txd,&internal1_m1024_txMBl,&internal1_m1024_txBl,&internal1_m1024_Speed0,&internal1_m1024_xz0,&internal1_m1024_tz0,&internal1_m1024_Shift0,&internal1_m1024_ShCntlSp0,&internal1_m1024_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_639_1 = {&var1167,&var1559};
_S_noto  S_noto_604_1 = {&var1666,&var1560};
_S_noto  S_noto_603_1 = {&var1676,&var1561};
_S_noto  S_noto_582_1 = {&var1168,&var1562};
_S_noto  S_noto_592_1 = {&R8IS11LDU,&var1563};
_S_charint  S_charint_530_1 = {&var1566,&var1564};
_S_ornc  S_ornc_536_1 = {array_m536_x_1,&iRM_3_,&var1565,&var1566};
_S_fsumz  S_fsumz_531_1 = {&var1564,&iRM_1_,&var1567};
_S_cnshd  S_cnshd_539_1 = {&R0MD34LP1,&var1960,&var1199,&var530,&var1565,&var959,&var953,&iRM_2_,array_m539_Lt_fw_1,array_m539_Vr_fw_1,&iRM_1_,array_m539_Lt_bw_1,array_m539_Vr_bw_1,&fEM_A1UC08RDU,&fEM_A1UC07RDU,&fEM_A1UL01RDU,&fEM_A1UC02RDU,&var1568,&vainSBool,&var1569,&var1570,&var1571,&var1572,&var1573,&var1574,&var1575,&var1576,&var1577,&var1578,&internal1_m539_X0,&internal1_m539_t0,&internal1_m539_BLDv0};
_S_zpfs  S_zpfs_558_1 = {&var1587,&fRM_2_0,&var1579,&internal1_m558_tx,&internal1_m558_y0};
_S_zpfs  S_zpfs_557_1 = {&var1586,&fRM_3_0,&var1580,&internal1_m557_tx,&internal1_m557_y0};
_S_fnapb  S_fnapb_562_1 = {&var1960,&var1199,&var957,&R0MD34LP1,&var1570,&var1577,&fEM_B8UV04RDU,&fEM_A1UV01RDU,&fEM_A1UV02RDU,&fEM_A1UC06RDU,&fEM_A1UC05RDU,&iRM_150_,&fEM_A1UL04RDU,&fEM_A1UL05RDU,&fEM_A1UL03RDU,&var1581,&var1582,&var1583,&var1584,&var1585,&var1586,&var1587,&vainSFloat,&internal1_m562_xptr,array_m562_x0_1,array_m562_tim0_1,&internal1_m562_sumtim,&internal1_m562_StSpeed,&internal1_m562_Vz0,&internal1_m562_flRazg,&internal1_m562_DelSp,&internal1_m562_z0,&internal1_m562_txZS,&internal1_m562_tx,&internal1_m562_txd,&internal1_m562_txMBl,&internal1_m562_txBl,&internal1_m562_Speed0,&internal1_m562_xz0,&internal1_m562_tz0,&internal1_m562_Shift0,&internal1_m562_ShCntlSp0,&internal1_m562_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_704_1 = {&R0MD33LP1,&var1588};
_S_noto  S_noto_276_1 = {&var1152,&var1589};
_S_newstage  S_newstage_204_1 = {&var1598,&var1565,&var1601,&var1568,&var1590};
_S_rs  S_rs_683_1 = {&var982,&var994,&var1591,&vainSBool,&internal1_m683_q0};
_S_orn  S_orn_239_1 = {array_m239_x_1,&iRM_12_,&var1592};
_S_noto  S_noto_238_1 = {&var1666,&var1593};
_S_noto  S_noto_237_1 = {&var1676,&var1594};
_S_noto  S_noto_216_1 = {&var1168,&var1595};
_S_noto  S_noto_226_1 = {&R8IS11LDU,&var1596};
_S_charint  S_charint_158_1 = {&var1599,&var1597};
_S_ornc  S_ornc_166_1 = {array_m166_x_1,&iRM_3_,&var1598,&var1599};
_S_fsumz  S_fsumz_159_1 = {&var1597,&iRM_1_,&var1600};
_S_cnshd  S_cnshd_169_1 = {&R0MD34LP1,&var1938,&var1200,&var534,&var1598,&var939,&var932,&iRM_2_,array_m169_Lt_fw_1,array_m169_Vr_fw_1,&iRM_1_,array_m169_Lt_bw_1,array_m169_Vr_bw_1,&fEM_A1UC08RDU,&fEM_A1UC07RDU,&fEM_A1UL01RDU,&fEM_A1UC02RDU,&var1601,&vainSBool,&var1602,&var1603,&var1604,&var1605,&var1606,&var1607,&var1608,&var1609,&var1610,&var1611,&internal1_m169_X0,&internal1_m169_t0,&internal1_m169_BLDv0};
_S_fnapb  S_fnapb_194_1 = {&var1938,&var1200,&var935,&R0MD34LP1,&var1603,&var1610,&fEM_B8UV04RDU,&fEM_A1UV01RDU,&fEM_A1UV02RDU,&fEM_A1UC06RDU,&fEM_A1UC05RDU,&iRM_150_,&fEM_A1UL04RDU,&fEM_A1UL05RDU,&fEM_A1UL03RDU,&var1612,&var1613,&var1614,&var1615,&var1616,&var1617,&var1618,&vainSFloat,&internal1_m194_xptr,array_m194_x0_1,array_m194_tim0_1,&internal1_m194_sumtim,&internal1_m194_StSpeed,&internal1_m194_Vz0,&internal1_m194_flRazg,&internal1_m194_DelSp,&internal1_m194_z0,&internal1_m194_txZS,&internal1_m194_tx,&internal1_m194_txd,&internal1_m194_txMBl,&internal1_m194_txBl,&internal1_m194_Speed0,&internal1_m194_xz0,&internal1_m194_tz0,&internal1_m194_Shift0,&internal1_m194_ShCntlSp0,&internal1_m194_ShiftControl,&bFirstEnterFlag};
_S_rs  S_rs_709_1 = {&var993,&var996,&var1619,&vainSBool,&internal1_m709_q0};
_S_newstage  S_newstage_502_1 = {&var1638,&var1629,&var1637,&var1628,&var1620};
_S_samhd  S_samhd_506_1 = {&R0MD34LP1,&var962,&var962,&var585,&var584,&R2VS12LDU,&R2VS22LDU,&R2IS11LDU,&R2IS11LDU,&R2IS21LDU,&R2IS21LDU,&bRM_0_,&fEM_R1UZ05RDU,&fEM_R1UZ03RDU,&fEM_R1UZ04RDU,&var1621,&var1622,&var1623,&var1624,&var1625,&var1626,&vainSBool,&vainSBool,&var1627,&var1628,&var1629,&internal1_m506_DvUp0,&internal1_m506_DvDw0,&internal1_m506_FDvUp0,&internal1_m506_FDvDw0,&internal1_m506_BlDv0,&internal1_m506_Pkv0,&internal1_m506_Pkav0,&internal1_m506_Zkv0,&internal1_m506_Zkav0,&internal1_m506_txNm,&internal1_m506_txSm,&internal1_m506_txHr,&internal1_m506_txLd,&internal1_m506_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_500_1 = {&R0MD34LP1,&var963,&var963,&var583,&var582,&R1VS12LDU,&R1VS22LDU,&R1IS11LDU,&R1IS11LDU,&R1IS21LDU,&R1IS21LDU,&bRM_0_,&fEM_R1UZ05RDU,&fEM_R1UZ03RDU,&fEM_R1UZ04RDU,&var1630,&var1631,&var1632,&var1633,&var1634,&var1635,&vainSBool,&vainSBool,&var1636,&var1637,&var1638,&internal1_m500_DvUp0,&internal1_m500_DvDw0,&internal1_m500_FDvUp0,&internal1_m500_FDvDw0,&internal1_m500_BlDv0,&internal1_m500_Pkv0,&internal1_m500_Pkav0,&internal1_m500_Zkv0,&internal1_m500_Zkav0,&internal1_m500_txNm,&internal1_m500_txSm,&internal1_m500_txHr,&internal1_m500_txLd,&internal1_m500_fef,&bFirstEnterFlag};
_S_orn  S_orn_956_1 = {array_m956_x_1,&iRM_10_,&var1639};
_S_noto  S_noto_961_1 = {&var1666,&var1640};
_S_noto  S_noto_960_1 = {&var1676,&var1641};
_S_noto  S_noto_936_1 = {&var1168,&var1642};
_S_noto  S_noto_948_1 = {&R8IS11LDU,&var1643};
_S_charint  S_charint_888_1 = {&var1646,&var1644};
_S_ornc  S_ornc_894_1 = {array_m894_x_1,&iRM_3_,&var1645,&var1646};
_S_fsumz  S_fsumz_889_1 = {&var1644,&iRM_1_,&var1647};
_S_cnshd  S_cnshd_898_1 = {&R0MD34LP1,&var1953,&var1196,&var1196,&var1645,&var912,&var826,&iRM_2_,array_m898_Lt_fw_1,array_m898_Vr_fw_1,&iRM_1_,array_m898_Lt_bw_1,array_m898_Vr_bw_1,&fEM_A2UC08RDU,&fEM_A2UC07RDU,&fEM_A2UL01RDU,&fEM_A2UC02RDU,&var1648,&vainSBool,&var1649,&var1650,&var1651,&var1652,&var1653,&var1654,&var1655,&var1656,&var1657,&var1658,&internal1_m898_X0,&internal1_m898_t0,&internal1_m898_BLDv0};
_S_fnapb  S_fnapb_916_1 = {&var1953,&var1196,&var908,&R0MD34LP1,&var1650,&var1657,&fEM_B8UV04RDU,&fEM_A2UV01RDU,&fEM_A2UV02RDU,&fEM_A2UC06RDU,&fEM_A2UC05RDU,&iRM_80_,&fEM_A2UL04RDU,&fEM_A2UL05RDU,&fEM_A2UL83RDU,&var1659,&var1660,&var1661,&var1662,&var1663,&var1664,&var1665,&vainSFloat,&internal1_m916_xptr,array_m916_x0_1,array_m916_tim0_1,&internal1_m916_sumtim,&internal1_m916_StSpeed,&internal1_m916_Vz0,&internal1_m916_flRazg,&internal1_m916_DelSp,&internal1_m916_z0,&internal1_m916_txZS,&internal1_m916_tx,&internal1_m916_txd,&internal1_m916_txMBl,&internal1_m916_txBl,&internal1_m916_Speed0,&internal1_m916_xz0,&internal1_m916_tz0,&internal1_m916_Shift0,&internal1_m916_ShCntlSp0,&internal1_m916_ShiftControl,&bFirstEnterFlag};
_S_cnshd  S_cnshd_1757_1 = {&R0MD34LP1,&var1944,&var518,&var518,&var735,&var738,&lRM_1_,&iRM_1_,array_m1757_Lt_fw_1,array_m1757_Vr_fw_1,&iRM_1_,array_m1757_Lt_bw_1,array_m1757_Vr_bw_1,&fEM_B8UC01RDU,&fEM_B8UC02RDU,&fEM_B8UL01RDU,&fRM_0_0,&var1666,&vainSBool,&vainSFloat,&var1667,&var1668,&var1669,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1670,&internal1_m1757_X0,&internal1_m1757_t0,&internal1_m1757_BLDv0};
_S_newstage  S_newstage_1379_1 = {&var1684,&var1645,&var1689,&var1648,&var1671};
_S_orn  S_orn_1416_1 = {array_m1416_x_1,&iRM_10_,&var1672};
_S_orn  S_orn_147_1 = {array_m147_x_1,&iRM_5_,&var1673};
_S_noto  S_noto_1415_1 = {&var1666,&var1674};
_S_noto  S_noto_1414_1 = {&var1676,&var1675};
_S_cnshd  S_cnshd_1242_1 = {&R0MD34LP1,&var1941,&var518,&var518,&var1053,&var736,&lRM_1_,&iRM_1_,array_m1242_Lt_fw_1,array_m1242_Vr_fw_1,&iRM_1_,array_m1242_Lt_bw_1,array_m1242_Vr_bw_1,&fEM_B8UC01RDU,&fEM_B8UC02RDU,&fEM_B8UL01RDU,&fRM_0_0,&var1676,&vainSBool,&vainSFloat,&var1677,&var1678,&var1679,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1680,&internal1_m1242_X0,&internal1_m1242_t0,&internal1_m1242_BLDv0};
_S_noto  S_noto_1391_1 = {&var1168,&var1681};
_S_noto  S_noto_1404_1 = {&R8IS11LDU,&var1682};
_S_charint  S_charint_1327_1 = {&var1685,&var1683};
_S_ornc  S_ornc_1334_1 = {array_m1334_x_1,&iRM_3_,&var1684,&var1685};
_S_noto  S_noto_668_1 = {&lEM_R0MD01LC1,&var1686};
_S_fsumz  S_fsumz_1328_1 = {&var1683,&iRM_1_,&var1687};
_S_rs  S_rs_681_1 = {&var1004,&var1006,&var1688,&vainSBool,&internal1_m681_q0};
_S_cnshd  S_cnshd_1337_1 = {&R0MD34LP1,&var1956,&var1195,&var1195,&var1684,&var829,&var822,&iRM_2_,array_m1337_Lt_fw_1,array_m1337_Vr_fw_1,&iRM_1_,array_m1337_Lt_bw_1,array_m1337_Vr_bw_1,&fEM_A2UC08RDU,&fEM_A2UC07RDU,&fEM_A2UL01RDU,&fEM_A2UC02RDU,&var1689,&vainSBool,&var1690,&var1691,&var1692,&var1693,&var1694,&var1695,&var1696,&var1697,&var1698,&var1699,&internal1_m1337_X0,&internal1_m1337_t0,&internal1_m1337_BLDv0};
_S_zpfs  S_zpfs_1366_1 = {&var1708,&fRM_2_0,&var1700,&internal1_m1366_tx,&internal1_m1366_y0};
_S_zpfs  S_zpfs_1365_1 = {&var1707,&fRM_3_0,&var1701,&internal1_m1365_tx,&internal1_m1365_y0};
_S_fnapb  S_fnapb_1372_1 = {&var1956,&var1195,&var830,&R0MD34LP1,&var1691,&var1698,&fEM_B8UV04RDU,&fEM_A2UV01RDU,&fEM_A2UV02RDU,&fEM_A2UC06RDU,&fEM_A2UC05RDU,&iRM_80_,&fEM_A2UL04RDU,&fEM_A2UL05RDU,&fEM_A2UL03RDU,&var1702,&var1703,&var1704,&var1705,&var1706,&var1707,&var1708,&vainSFloat,&internal1_m1372_xptr,array_m1372_x0_1,array_m1372_tim0_1,&internal1_m1372_sumtim,&internal1_m1372_StSpeed,&internal1_m1372_Vz0,&internal1_m1372_flRazg,&internal1_m1372_DelSp,&internal1_m1372_z0,&internal1_m1372_txZS,&internal1_m1372_tx,&internal1_m1372_txd,&internal1_m1372_txMBl,&internal1_m1372_txBl,&internal1_m1372_Speed0,&internal1_m1372_xz0,&internal1_m1372_tz0,&internal1_m1372_Shift0,&internal1_m1372_ShCntlSp0,&internal1_m1372_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_1738_1 = {&R8IS11LDU,&var1709};
_S_rs  S_rs_701_1 = {&var1007,&var1008,&var1710,&vainSBool,&internal1_m701_q0};
_S_zpfs  S_zpfs_1771_1 = {&var1721,&fRM_2_0,&var1711,&internal1_m1771_tx,&internal1_m1771_y0};
_S_zpfs  S_zpfs_1775_1 = {&var1720,&fRM_3_0,&var1712,&internal1_m1775_tx,&internal1_m1775_y0};
_S_samhd  S_samhd_1760_1 = {&R0MD34LP1,&var738,&var738,&var1668,&var1669,&var1715,&var1716,&A8IS12LDU,&A8IS12LDU,&A8IS22LDU,&A8IS22LDU,&bRM_3_,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&fEM_B8UL07RDU,&var1713,&var1714,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,&internal1_m1760_DvUp0,&internal1_m1760_DvDw0,&internal1_m1760_FDvUp0,&internal1_m1760_FDvDw0,&internal1_m1760_BlDv0,&internal1_m1760_Pkv0,&internal1_m1760_Pkav0,&internal1_m1760_Zkv0,&internal1_m1760_Zkav0,&internal1_m1760_txNm,&internal1_m1760_txSm,&internal1_m1760_txHr,&internal1_m1760_txLd,&internal1_m1760_fef,&bFirstEnterFlag};
_S_fnapb  S_fnapb_1779_1 = {&var1944,&var518,&var734,&R0MD34LP1,&var1667,&fEM_B8UV03RDU,&fEM_B8UV04RDU,&fEM_B8UV01RDU,&fEM_B8UV02RDU,&fEM_B8UC06RDU,&fEM_B8UC05RDU,&iRM_20_,&fEM_B8UL04RDU,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&var1715,&var1716,&var1717,&var1718,&var1719,&var1720,&var1721,&vainSFloat,&internal1_m1779_xptr,array_m1779_x0_1,array_m1779_tim0_1,&internal1_m1779_sumtim,&internal1_m1779_StSpeed,&internal1_m1779_Vz0,&internal1_m1779_flRazg,&internal1_m1779_DelSp,&internal1_m1779_z0,&internal1_m1779_txZS,&internal1_m1779_tx,&internal1_m1779_txd,&internal1_m1779_txMBl,&internal1_m1779_txBl,&internal1_m1779_Speed0,&internal1_m1779_xz0,&internal1_m1779_tz0,&internal1_m1779_Shift0,&internal1_m1779_ShCntlSp0,&internal1_m1779_ShiftControl,&bFirstEnterFlag};
_S_zpfs  S_zpfs_1257_1 = {&var1738,&fRM_2_0,&var1722,&internal1_m1257_tx,&internal1_m1257_y0};
_S_zpfs  S_zpfs_1261_1 = {&var1737,&fRM_3_0,&var1723,&internal1_m1261_tx,&internal1_m1261_y0};
_S_noto  S_noto_1221_1 = {&R8IS11LDU,&var1724};
_S_orn  S_orn_1203_1 = {array_m1203_x_1,&iRM_8_,&var1725};
_S_noto  S_noto_670_1 = {&var1729,&var1726};
_S_rs  S_rs_691_1 = {&var1009,&var1010,&var1727,&vainSBool,&internal1_m691_q0};
_S_orn  S_orn_658_1 = {array_m658_x_1,&iRM_18_,&var1728};
_S_rs  S_rs_656_1 = {&var1493,&var1125,&var1729,&vainSBool,&internal1_m656_q0};
_S_samhd  S_samhd_1248_1 = {&R0MD34LP1,&var736,&var736,&var1678,&var1679,&var1732,&var1733,&var361,&var361,&var360,&var360,&bRM_3_,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&fEM_B8UL07RDU,&vainSBool,&vainSBool,&var1730,&var1731,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,&internal1_m1248_DvUp0,&internal1_m1248_DvDw0,&internal1_m1248_FDvUp0,&internal1_m1248_FDvDw0,&internal1_m1248_BlDv0,&internal1_m1248_Pkv0,&internal1_m1248_Pkav0,&internal1_m1248_Zkv0,&internal1_m1248_Zkav0,&internal1_m1248_txNm,&internal1_m1248_txSm,&internal1_m1248_txHr,&internal1_m1248_txLd,&internal1_m1248_fef,&bFirstEnterFlag};
_S_fnapb  S_fnapb_1267_1 = {&var1941,&var518,&var1052,&R0MD34LP1,&var1677,&fEM_B8UV03RDU,&fEM_B8UV04RDU,&fEM_B8UV01RDU,&fEM_B8UV02RDU,&fEM_B8UC06RDU,&fEM_B8UC05RDU,&iRM_20_,&fEM_B8UL04RDU,&fEM_B8UL06RDU,&fEM_B8UL03RDU,&var1732,&var1733,&var1734,&var1735,&var1736,&var1737,&var1738,&vainSFloat,&internal1_m1267_xptr,array_m1267_x0_1,array_m1267_tim0_1,&internal1_m1267_sumtim,&internal1_m1267_StSpeed,&internal1_m1267_Vz0,&internal1_m1267_flRazg,&internal1_m1267_DelSp,&internal1_m1267_z0,&internal1_m1267_txZS,&internal1_m1267_tx,&internal1_m1267_txd,&internal1_m1267_txMBl,&internal1_m1267_txBl,&internal1_m1267_Speed0,&internal1_m1267_xz0,&internal1_m1267_tz0,&internal1_m1267_Shift0,&internal1_m1267_ShCntlSp0,&internal1_m1267_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_796_1 = {&A5IS21LDU,&var1739};
_S_vmemb  S_vmemb_819_1 = {&var1741,&var1740,&internal1_m819_x0};
_S_noto  S_noto_827_1 = {&var362,&var1741};
_S_vmemb  S_vmemb_787_1 = {&var1739,&var1742,&internal1_m787_x0};
_S_vmemb  S_vmemb_730_1 = {&var1757,&var1743,&internal1_m730_x0};
_S_newstage  S_newstage_866_1 = {&var1801,&var1792,&var1800,&var1791,&var1744};
_S_newstage  S_newstage_1306_1 = {&var1783,&var1774,&var1782,&var1773,&var1745};
_S_newstage  S_newstage_413_1 = {&var1828,&var1819,&var1827,&var1818,&var1746};
_S_noto  S_noto_838_1 = {&var363,&var1747};
_S_rs  S_rs_844_1 = {&var1073,&var1746,&var1748,&vainSBool,&internal1_m844_q0};
_S_rs  S_rs_839_1 = {&var1074,&var1174,&var1749,&vainSBool,&internal1_m839_q0};
_S_noto  S_noto_831_1 = {&var1830,&var1750};
_S_noto  S_noto_829_1 = {&var1831,&var1751};
_S_rs  S_rs_807_1 = {&var1078,&var1746,&var1752,&vainSBool,&internal1_m807_q0};
_S_rs  S_rs_812_1 = {&var1077,&var1744,&var1753,&vainSBool,&internal1_m812_q0};
_S_rs  S_rs_820_1 = {&var1144,&var1083,&var1754,&vainSBool,&internal1_m820_q0};
_S_rs  S_rs_832_1 = {&var1075,&var1081,&var1755,&vainSBool,&internal1_m832_q0};
_S_noto  S_noto_786_1 = {&var363,&var1756};
_S_noto  S_noto_723_1 = {&var362,&var1757};
_S_noto  S_noto_452_1 = {&R8IS11LDU,&var1758};
_S_orn  S_orn_470_1 = {array_m470_x_1,&iRM_7_,&var1759};
_S_orn  S_orn_448_1 = {array_m448_x_1,&iRM_7_,&var1760};
_S_rs  S_rs_810_1 = {&var1082,&var1087,&var1761,&vainSBool,&internal1_m810_q0};
_S_noto  S_noto_155_1 = {&B2IS12LDU,&var1762};
_S_noto  S_noto_144_1 = {&A2IS12LDU,&var1763};
_S_noto  S_noto_145_1 = {&B1IS12LDU,&var1764};
_S_noto  S_noto_153_1 = {&A1IS12LDU,&var1765};
_S_samhd  S_samhd_1309_1 = {&var1056,&var1057,&var1057,&var1366,&var1365,&var1366,&var1365,&B4IS11LDU,&B4IS11LDU,&B4IS21LDU,&B4IS21LDU,&bRM_1_,&fEM_A4UZ05RDU,&fEM_A4UZ03RDU,&fEM_A4UZ04RDU,&var1766,&var1767,&var1768,&vainSBool,&var1769,&vainSBool,&var1770,&var1771,&var1772,&var1773,&var1774,&internal1_m1309_DvUp0,&internal1_m1309_DvDw0,&internal1_m1309_FDvUp0,&internal1_m1309_FDvDw0,&internal1_m1309_BlDv0,&internal1_m1309_Pkv0,&internal1_m1309_Pkav0,&internal1_m1309_Zkv0,&internal1_m1309_Zkav0,&internal1_m1309_txNm,&internal1_m1309_txSm,&internal1_m1309_txHr,&internal1_m1309_txLd,&internal1_m1309_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_1300_1 = {&var1056,&var1059,&var1059,&var1366,&var1365,&var1366,&var1365,&A4IS11LDU,&A4IS11LDU,&A4IS21LDU,&A4IS21LDU,&bRM_1_,&fEM_A4UZ05RDU,&fEM_A4UZ03RDU,&fEM_A4UZ04RDU,&var1775,&var1776,&var1777,&vainSBool,&var1778,&vainSBool,&var1779,&var1780,&var1781,&var1782,&var1783,&internal1_m1300_DvUp0,&internal1_m1300_DvDw0,&internal1_m1300_FDvUp0,&internal1_m1300_FDvDw0,&internal1_m1300_BlDv0,&internal1_m1300_Pkv0,&internal1_m1300_Pkav0,&internal1_m1300_Zkv0,&internal1_m1300_Zkav0,&internal1_m1300_txNm,&internal1_m1300_txSm,&internal1_m1300_txHr,&internal1_m1300_txLd,&internal1_m1300_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_868_1 = {&R0MD34LP1,&var914,&var914,&var1175,&var1070,&B5VS12LDU,&B5VS22LDU,&B5IS11LDU,&B5IS11LDU,&B5IS21LDU,&B5IS21LDU,&bRM_0_,&fEM_A5UZ05RDU,&fEM_A5UZ03RDU,&fEM_A5UZ04RDU,&var1784,&var1785,&var1786,&var1787,&var1788,&var1789,&vainSBool,&vainSBool,&var1790,&var1791,&var1792,&internal1_m868_DvUp0,&internal1_m868_DvDw0,&internal1_m868_FDvUp0,&internal1_m868_FDvDw0,&internal1_m868_BlDv0,&internal1_m868_Pkv0,&internal1_m868_Pkav0,&internal1_m868_Zkv0,&internal1_m868_Zkav0,&internal1_m868_txNm,&internal1_m868_txSm,&internal1_m868_txHr,&internal1_m868_txLd,&internal1_m868_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_864_1 = {&R0MD34LP1,&var916,&var916,&var1175,&var1070,&A5VS12LDU,&A5VS22LDU,&A5IS11LDU,&A5IS11LDU,&A5IS21LDU,&A5IS21LDU,&bRM_0_,&fEM_A5UZ05RDU,&fEM_A5UZ03RDU,&fEM_A5UZ04RDU,&var1793,&var1794,&var1795,&var1796,&var1797,&var1798,&vainSBool,&vainSBool,&var1799,&var1800,&var1801,&internal1_m864_DvUp0,&internal1_m864_DvDw0,&internal1_m864_FDvUp0,&internal1_m864_FDvDw0,&internal1_m864_BlDv0,&internal1_m864_Pkv0,&internal1_m864_Pkav0,&internal1_m864_Zkv0,&internal1_m864_Zkav0,&internal1_m864_txNm,&internal1_m864_txSm,&internal1_m864_txHr,&internal1_m864_txLd,&internal1_m864_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_379_1 = {&R0MD34LP1,&var587,&var586,&var1079,&var1072,&R4VS12LDU,&R4VS22LDU,&R4IS11LDU,&R4IS12LDU,&R4IS21LDU,&R4IS22LDU,&bRM_0_,&fEM_R4UZ05RDU,&fEM_R4UZ03RDU,&fEM_R4UZ04RDU,&var1802,&var1803,&var1804,&var1805,&var1806,&var1807,&vainSBool,&vainSBool,&var1808,&var1809,&vainSBool,&internal1_m379_DvUp0,&internal1_m379_DvDw0,&internal1_m379_FDvUp0,&internal1_m379_FDvDw0,&internal1_m379_BlDv0,&internal1_m379_Pkv0,&internal1_m379_Pkav0,&internal1_m379_Zkv0,&internal1_m379_Zkav0,&internal1_m379_txNm,&internal1_m379_txSm,&internal1_m379_txHr,&internal1_m379_txLd,&internal1_m379_fef,&bFirstEnterFlag};
_S_noto  S_noto_743_1 = {&R8IS11LDU,&var1810};
_S_samhd  S_samhd_416_1 = {&R0MD34LP1,&var1759,&var1145,&var1151,&var1071,&B6VS12LDU,&B6VS22LDU,&B6IS11LDU,&B6IS11LDU,&B6IS21LDU,&B6IS21LDU,&bRM_0_,&fEM_A6UZ05RDU,&fEM_A6UZ03RDU,&fEM_A6UZ04RDU,&var1811,&var1812,&var1813,&var1814,&var1815,&var1816,&vainSBool,&vainSBool,&var1817,&var1818,&var1819,&internal1_m416_DvUp0,&internal1_m416_DvDw0,&internal1_m416_FDvUp0,&internal1_m416_FDvDw0,&internal1_m416_BlDv0,&internal1_m416_Pkv0,&internal1_m416_Pkav0,&internal1_m416_Zkv0,&internal1_m416_Zkav0,&internal1_m416_txNm,&internal1_m416_txSm,&internal1_m416_txHr,&internal1_m416_txLd,&internal1_m416_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_410_1 = {&R0MD34LP1,&var1760,&var1146,&var1151,&var1071,&A6VS12LDU,&A6VS22LDU,&A6IS11LDU,&A6IS11LDU,&A6IS21LDU,&A6IS21LDU,&bRM_0_,&fEM_A6UZ05RDU,&fEM_A6UZ03RDU,&fEM_A6UZ04RDU,&var1820,&var1821,&var1822,&var1823,&var1824,&var1825,&vainSBool,&vainSBool,&var1826,&var1827,&var1828,&internal1_m410_DvUp0,&internal1_m410_DvDw0,&internal1_m410_FDvUp0,&internal1_m410_FDvDw0,&internal1_m410_BlDv0,&internal1_m410_Pkv0,&internal1_m410_Pkav0,&internal1_m410_Zkv0,&internal1_m410_Zkav0,&internal1_m410_txNm,&internal1_m410_txSm,&internal1_m410_txHr,&internal1_m410_txLd,&internal1_m410_fef,&bFirstEnterFlag};
_S_orn  S_orn_843_1 = {array_m843_x_1,&iRM_17_,&var1829};
_S_rs  S_rs_816_1 = {&var1085,&var272,&var1830,&vainSBool,&internal1_m816_q0};
_S_rs  S_rs_813_1 = {&var1086,&var273,&var1831,&vainSBool,&internal1_m813_q0};
_S_orni  S_orni_133_1 = {array_m133_x_1,&iRM_21_,&var1832,&vainSLong};
_S_equz_p  S_equz_p_74_1 = {&R0MW11IP2,&iRM_6_,&var1833};
_S_equz_p  S_equz_p_72_1 = {&R0MW11IP2,&iRM_5_,&var1834};
_S_equz_p  S_equz_p_70_1 = {&R0MW11IP2,&iRM_4_,&var1835};
_S_equz_p  S_equz_p_69_1 = {&R0MW11IP2,&iRM_3_,&var1836};
_S_equz_p  S_equz_p_68_1 = {&R0MW11IP2,&iRM_2_,&var1837};
_S_equz_p  S_equz_p_65_1 = {&R0MW11IP2,&iRM_1_,&var1838};
_S_equz_p  S_equz_p_61_1 = {&R0MW14IP1,&iRM_3_,&var1839};
_S_equz_p  S_equz_p_55_1 = {&R0MW14IP1,&iRM_1_,&vainSBool};
_S_equz_p  S_equz_p_57_1 = {&R0MW14IP1,&iRM_2_,&var1840};
_S_equz_p  S_equz_p_50_1 = {&R0MW11IP1,&iRM_3_,&var1841};
_S_equz_p  S_equz_p_43_1 = {&R0MW11IP1,&iRM_1_,&var1842};
_S_equz_p  S_equz_p_46_1 = {&R0MW11IP1,&iRM_2_,&var1843};
_S_equz_p  S_equz_p_100_1 = {&R0MW16IP1,&iRM_11_,&var1844};
_S_equz_p  S_equz_p_93_1 = {&R0MW16IP1,&iRM_4_,&var1845};
_S_equz_p  S_equz_p_92_1 = {&R0MW16IP1,&iRM_3_,&var1846};
_S_equz_p  S_equz_p_91_1 = {&R0MW16IP1,&iRM_2_,&var1847};
_S_equz_p  S_equz_p_10_1 = {&R0MW12IP1,&iRM_4_,&var1848};
_S_equz_p  S_equz_p_7_1 = {&R0MW12IP1,&iRM_3_,&var1849};
_S_equz_p  S_equz_p_2_1 = {&R0MW12IP1,&iRM_1_,&var1850};
_S_equz_p  S_equz_p_4_1 = {&R0MW12IP1,&iRM_2_,&var1851};


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
   var15.b=0;
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
   var141.b=0;
   var142.b=0;
   var143.b=0;
   var144.b=0;
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
   var189.b=0;
   var190.b=0;
   var191.b=0;
   var192.b=0;
   var193.b=0;
   var194.b=0;
   var195.b=0;
   var196.b=0;
   var197.b=0;
   var198.b=0;
   var199.b=0;
   var200.b=0;
   var201.b=0;
   var202.b=0;
   var203.b=0;
   var204.b=0;
   var205.b=0;
   var206.b=0;
   var207.b=0;
   var208.b=0;
   var209.b=0;
   var210.b=0;
   var211.b=0;
   var212.b=0;
   var213.b=0;
   var214.b=0;
   var215.b=0;
   var216.b=0;
   var217.b=0;
   var218.i=0;
   var219.b=0;
   var220.b=0;
   var221.b=0;
   var222.b=0;
   var223.b=0;
   var224.b=0;
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
   var315.b=0;
   var316.b=0;
   var317.b=0;
   var318.b=0;
   var319.b=0;
   var320.b=0;
   var321.b=0;
   var322.b=0;
   var323.b=0;
   var324.b=0;
   var325.b=0;
   var326.b=0;
   var327.b=0;
   var328.b=0;
   var329.b=0;
   var330.b=0;
   var331.b=0;
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
   var344.i=0;
   var345.b=0;
   var346.b=0;
   var347.i=0;
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
   var392.f=0.0;
   var393.b=0;
   var394.b=0;
   var395.b=0;
   var396.b=0;
   var397.b=0;
   var398.b=0;
   var399.b=0;
   var400.b=0;
   var401.b=0;
   var402.f=0.0;
   var403.f=0.0;
   var404.b=0;
   var405.b=0;
   var406.b=0;
   var407.f=0.0;
   var408.f=0.0;
   var409.b=0;
   var410.b=0;
   var411.f=0.0;
   var412.b=0;
   var413.b=0;
   var414.b=0;
   var415.b=0;
   var416.b=0;
   var417.b=0;
   var418.b=0;
   var419.b=0;
   var420.f=0.0;
   var421.f=0.0;
   var422.f=0.0;
   var423.f=0.0;
   var424.b=0;
   var425.f=0.0;
   var426.f=0.0;
   var427.i=0;
   var428.b=0;
   var429.b=0;
   var430.b=0;
   var431.b=0;
   var432.b=0;
   var433.b=0;
   var434.b=0;
   var435.b=0;
   var436.b=0;
   var437.b=0;
   var438.b=0;
   var439.b=0;
   var440.b=0;
   var441.b=0;
   var442.b=0;
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
   var518.f=0.0;
   var519.b=0;
   var520.b=0;
   var521.b=0;
   var522.f=0.0;
   var523.b=0;
   var524.b=0;
   var525.b=0;
   var526.f=0.0;
   var527.b=0;
   var528.b=0;
   var529.b=0;
   var530.f=0.0;
   var531.b=0;
   var532.b=0;
   var533.b=0;
   var534.f=0.0;
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
   var572.b=0;
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
   var631.f=0.0;
   var632.f=0.0;
   var633.b=0;
   var634.f=0.0;
   var635.f=0.0;
   var636.b=0;
   var637.f=0.0;
   var638.f=0.0;
   var639.b=0;
   var640.f=0.0;
   var641.f=0.0;
   var642.b=0;
   var643.b=0;
   var644.f=0.0;
   var645.f=0.0;
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
   var775.l=0L;
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
   var983.b=0;
   var984.b=0;
   var985.b=0;
   var986.b=0;
   var987.b=0;
   var988.b=0;
   var989.b=0;
   var990.b=0;
   var991.b=0;
   var992.b=0;
   var993.b=0;
   var994.b=0;
   var995.b=0;
   var996.b=0;
   var997.b=0;
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
   var1053.b=0;
   var1054.b=0;
   var1055.b=0;
   var1056.b=0;
   var1057.b=0;
   var1058.b=0;
   var1059.b=0;
   var1060.b=0;
   var1061.b=0;
   var1062.b=0;
   var1063.b=0;
   var1064.b=0;
   var1065.b=0;
   var1066.b=0;
   var1067.b=0;
   var1068.b=0;
   var1069.b=0;
   var1070.b=0;
   var1071.b=0;
   var1072.b=0;
   var1073.b=0;
   var1074.b=0;
   var1075.b=0;
   var1076.b=0;
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
   var1116.b=0;
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
   var1135.b=0;
   var1136.b=0;
   var1137.b=0;
   var1138.b=0;
   var1139.b=0;
   var1140.b=0;
   var1141.b=0;
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
   var1155.b=0;
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
   var1180.b=0;
   var1181.b=0;
   var1182.b=0;
   var1183.b=0;
   var1184.b=0;
   var1185.b=0;
   var1186.f=0.0;
   var1187.b=0;
   var1188.f=0.0;
   var1189.b=0;
   var1190.f=0.0;
   var1191.b=0;
   var1192.b=0;
   var1193.b=0;
   var1194.b=0;
   var1195.f=0.0;
   var1196.f=0.0;
   var1197.f=0.0;
   var1198.f=0.0;
   var1199.f=0.0;
   var1200.f=0.0;
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
   var1256.i=0;
   var1257.i=0;
   var1258.b=0;
   var1259.b=0;
   var1260.b=0;
   var1261.b=0;
   var1262.b=0;
   var1263.b=0;
   var1264.l=0L;
   var1265.b=0;
   var1266.b=0;
   var1267.b=0;
   var1268.i=0;
   var1269.b=0;
   var1270.b=0;
   var1271.b=0;
   var1272.b=0;
   var1273.b=0;
   var1274.b=0;
   var1275.b=0;
   var1276.b=0;
   var1277.b=0;
   var1278.i=0;
   var1279.i=0;
   var1280.b=0;
   var1281.b=0;
   var1282.b=0;
   var1283.b=0;
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
   var1300.b=0;
   var1301.b=0;
   var1302.b=0;
   var1303.b=0;
   var1304.b=0;
   var1305.b=0;
   var1306.b=0;
   var1307.b=0;
   var1308.b=0;
   var1309.b=0;
   var1310.b=0;
   var1311.b=0;
   var1312.b=0;
   var1313.b=0;
   var1314.b=0;
   var1315.b=0;
   var1316.b=0;
   var1317.b=0;
   var1318.b=0;
   var1319.l=0L;
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
   var1332.b=0;
   var1333.b=0;
   var1334.b=0;
   var1335.b=0;
   var1336.b=0;
   var1337.b=0;
   var1338.f=0.0;
   var1339.b=0;
   var1340.b=0;
   var1341.b=0;
   var1342.b=0;
   var1343.b=0;
   var1344.f=0.0;
   var1345.b=0;
   var1346.b=0;
   var1347.b=0;
   var1348.b=0;
   var1349.b=0;
   var1350.b=0;
   var1351.b=0;
   var1352.b=0;
   var1353.b=0;
   var1354.b=0;
   var1355.b=0;
   var1356.b=0;
   var1357.b=0;
   var1358.i=0;
   var1359.b=0;
   var1360.b=0;
   var1361.b=0;
   var1362.b=0;
   var1363.b=0;
   var1364.b=0;
   var1365.b=0;
   var1366.b=0;
   var1367.b=0;
   var1368.b=0;
   var1369.b=0;
   var1370.b=0;
   var1371.b=0;
   var1372.b=0;
   var1373.b=0;
   var1374.b=0;
   var1375.b=0;
   var1376.b=0;
   var1377.b=0;
   var1378.b=0;
   var1379.b=0;
   var1380.b=0;
   var1381.b=0;
   var1382.b=0;
   var1383.f=0.0;
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
   var1394.b=0;
   var1395.b=0;
   var1396.b=0;
   var1397.b=0;
   var1398.b=0;
   var1399.b=0;
   var1400.b=0;
   var1401.b=0;
   var1402.b=0;
   var1403.b=0;
   var1404.b=0;
   var1405.b=0;
   var1406.b=0;
   var1407.b=0;
   var1408.b=0;
   var1409.b=0;
   var1410.b=0;
   var1411.b=0;
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
   var1424.b=0;
   var1425.b=0;
   var1426.b=0;
   var1427.b=0;
   var1428.b=0;
   var1429.b=0;
   var1430.b=0;
   var1431.b=0;
   var1432.b=0;
   var1433.b=0;
   var1434.b=0;
   var1435.b=0;
   var1436.b=0;
   var1437.b=0;
   var1438.b=0;
   var1439.b=0;
   var1440.b=0;
   var1441.b=0;
   var1442.b=0;
   var1443.b=0;
   var1444.b=0;
   var1445.b=0;
   var1446.b=0;
   var1447.b=0;
   var1448.b=0;
   var1449.b=0;
   var1450.b=0;
   var1451.b=0;
   var1452.b=0;
   var1453.b=0;
   var1454.b=0;
   var1455.b=0;
   var1456.b=0;
   var1457.b=0;
   var1458.b=0;
   var1459.b=0;
   var1460.b=0;
   var1461.b=0;
   var1462.b=0;
   var1463.b=0;
   var1464.b=0;
   var1465.b=0;
   var1466.b=0;
   var1467.b=0;
   var1468.b=0;
   var1469.b=0;
   var1470.b=0;
   var1471.b=0;
   var1472.b=0;
   var1473.b=0;
   var1474.b=0;
   var1475.b=0;
   var1476.b=0;
   var1477.b=0;
   var1478.b=0;
   var1479.l=0L;
   var1480.b=0;
   var1481.i=0;
   var1482.i=0;
   var1483.b=0;
   var1484.f=0.0;
   var1485.f=0.0;
   var1486.f=0.0;
   var1487.b=0;
   var1488.b=0;
   var1489.b=0;
   var1490.b=0;
   var1491.b=0;
   var1492.b=0;
   var1493.b=0;
   var1494.b=0;
   var1495.b=0;
   var1496.b=0;
   var1497.b=0;
   var1498.b=0;
   var1499.b=0;
   var1500.b=0;
   var1501.b=0;
   var1502.b=0;
   var1503.i=0;
   var1504.b=0;
   var1505.c=0;
   var1506.i=0;
   var1507.b=0;
   var1508.f=0.0;
   var1509.b=0;
   var1510.b=0;
   var1511.b=0;
   var1512.b=0;
   var1513.b=0;
   var1514.b=0;
   var1515.b=0;
   var1516.f=0.0;
   var1517.c=0;
   var1518.b=0;
   var1519.b=0;
   var1520.b=0;
   var1521.b=0;
   var1522.f=0.0;
   var1523.b=0;
   var1524.b=0;
   var1525.b=0;
   var1526.b=0;
   var1527.b=0;
   var1528.b=0;
   var1529.b=0;
   var1530.b=0;
   var1531.b=0;
   var1532.b=0;
   var1533.b=0;
   var1534.b=0;
   var1535.i=0;
   var1536.b=0;
   var1537.c=0;
   var1538.i=0;
   var1539.b=0;
   var1540.f=0.0;
   var1541.b=0;
   var1542.b=0;
   var1543.b=0;
   var1544.b=0;
   var1545.b=0;
   var1546.b=0;
   var1547.b=0;
   var1548.f=0.0;
   var1549.c=0;
   var1550.b=0;
   var1551.b=0;
   var1552.b=0;
   var1553.b=0;
   var1554.f=0.0;
   var1555.b=0;
   var1556.b=0;
   var1557.b=0;
   var1558.b=0;
   var1559.b=0;
   var1560.b=0;
   var1561.b=0;
   var1562.b=0;
   var1563.b=0;
   var1564.i=0;
   var1565.b=0;
   var1566.c=0;
   var1567.i=0;
   var1568.b=0;
   var1569.f=0.0;
   var1570.b=0;
   var1571.b=0;
   var1572.b=0;
   var1573.b=0;
   var1574.b=0;
   var1575.b=0;
   var1576.b=0;
   var1577.f=0.0;
   var1578.c=0;
   var1579.b=0;
   var1580.b=0;
   var1581.b=0;
   var1582.b=0;
   var1583.f=0.0;
   var1584.b=0;
   var1585.b=0;
   var1586.b=0;
   var1587.b=0;
   var1588.b=0;
   var1589.b=0;
   var1590.b=0;
   var1591.b=0;
   var1592.b=0;
   var1593.b=0;
   var1594.b=0;
   var1595.b=0;
   var1596.b=0;
   var1597.i=0;
   var1598.b=0;
   var1599.c=0;
   var1600.i=0;
   var1601.b=0;
   var1602.f=0.0;
   var1603.b=0;
   var1604.b=0;
   var1605.b=0;
   var1606.b=0;
   var1607.b=0;
   var1608.b=0;
   var1609.b=0;
   var1610.f=0.0;
   var1611.c=0;
   var1612.b=0;
   var1613.b=0;
   var1614.f=0.0;
   var1615.b=0;
   var1616.b=0;
   var1617.b=0;
   var1618.b=0;
   var1619.b=0;
   var1620.b=0;
   var1621.b=0;
   var1622.b=0;
   var1623.b=0;
   var1624.b=0;
   var1625.b=0;
   var1626.b=0;
   var1627.i=0;
   var1628.b=0;
   var1629.b=0;
   var1630.b=0;
   var1631.b=0;
   var1632.b=0;
   var1633.b=0;
   var1634.b=0;
   var1635.b=0;
   var1636.i=0;
   var1637.b=0;
   var1638.b=0;
   var1639.b=0;
   var1640.b=0;
   var1641.b=0;
   var1642.b=0;
   var1643.b=0;
   var1644.i=0;
   var1645.b=0;
   var1646.c=0;
   var1647.i=0;
   var1648.b=0;
   var1649.f=0.0;
   var1650.b=0;
   var1651.b=0;
   var1652.b=0;
   var1653.b=0;
   var1654.b=0;
   var1655.b=0;
   var1656.b=0;
   var1657.f=0.0;
   var1658.c=0;
   var1659.b=0;
   var1660.b=0;
   var1661.f=0.0;
   var1662.b=0;
   var1663.b=0;
   var1664.b=0;
   var1665.b=0;
   var1666.b=0;
   var1667.b=0;
   var1668.b=0;
   var1669.b=0;
   var1670.c=0;
   var1671.b=0;
   var1672.b=0;
   var1673.b=0;
   var1674.b=0;
   var1675.b=0;
   var1676.b=0;
   var1677.b=0;
   var1678.b=0;
   var1679.b=0;
   var1680.c=0;
   var1681.b=0;
   var1682.b=0;
   var1683.i=0;
   var1684.b=0;
   var1685.c=0;
   var1686.b=0;
   var1687.i=0;
   var1688.b=0;
   var1689.b=0;
   var1690.f=0.0;
   var1691.b=0;
   var1692.b=0;
   var1693.b=0;
   var1694.b=0;
   var1695.b=0;
   var1696.b=0;
   var1697.b=0;
   var1698.f=0.0;
   var1699.c=0;
   var1700.b=0;
   var1701.b=0;
   var1702.b=0;
   var1703.b=0;
   var1704.f=0.0;
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
   var1717.f=0.0;
   var1718.b=0;
   var1719.b=0;
   var1720.b=0;
   var1721.b=0;
   var1722.b=0;
   var1723.b=0;
   var1724.b=0;
   var1725.b=0;
   var1726.b=0;
   var1727.b=0;
   var1728.b=0;
   var1729.b=0;
   var1730.b=0;
   var1731.b=0;
   var1732.b=0;
   var1733.b=0;
   var1734.f=0.0;
   var1735.b=0;
   var1736.b=0;
   var1737.b=0;
   var1738.b=0;
   var1739.b=0;
   var1740.b=0;
   var1741.b=0;
   var1742.b=0;
   var1743.b=0;
   var1744.b=0;
   var1745.b=0;
   var1746.b=0;
   var1747.b=0;
   var1748.b=0;
   var1749.b=0;
   var1750.b=0;
   var1751.b=0;
   var1752.b=0;
   var1753.b=0;
   var1754.b=0;
   var1755.b=0;
   var1756.b=0;
   var1757.b=0;
   var1758.b=0;
   var1759.b=0;
   var1760.b=0;
   var1761.b=0;
   var1762.b=0;
   var1763.b=0;
   var1764.b=0;
   var1765.b=0;
   var1766.b=0;
   var1767.b=0;
   var1768.b=0;
   var1769.b=0;
   var1770.b=0;
   var1771.b=0;
   var1772.i=0;
   var1773.b=0;
   var1774.b=0;
   var1775.b=0;
   var1776.b=0;
   var1777.b=0;
   var1778.b=0;
   var1779.b=0;
   var1780.b=0;
   var1781.i=0;
   var1782.b=0;
   var1783.b=0;
   var1784.b=0;
   var1785.b=0;
   var1786.b=0;
   var1787.b=0;
   var1788.b=0;
   var1789.b=0;
   var1790.i=0;
   var1791.b=0;
   var1792.b=0;
   var1793.b=0;
   var1794.b=0;
   var1795.b=0;
   var1796.b=0;
   var1797.b=0;
   var1798.b=0;
   var1799.i=0;
   var1800.b=0;
   var1801.b=0;
   var1802.b=0;
   var1803.b=0;
   var1804.b=0;
   var1805.b=0;
   var1806.b=0;
   var1807.b=0;
   var1808.i=0;
   var1809.b=0;
   var1810.b=0;
   var1811.b=0;
   var1812.b=0;
   var1813.b=0;
   var1814.b=0;
   var1815.b=0;
   var1816.b=0;
   var1817.i=0;
   var1818.b=0;
   var1819.b=0;
   var1820.b=0;
   var1821.b=0;
   var1822.b=0;
   var1823.b=0;
   var1824.b=0;
   var1825.b=0;
   var1826.i=0;
   var1827.b=0;
   var1828.b=0;
   var1829.b=0;
   var1830.b=0;
   var1831.b=0;
   var1832.b=0;
   var1833.b=0;
   var1834.b=0;
   var1835.b=0;
   var1836.b=0;
   var1837.b=0;
   var1838.b=0;
   var1839.b=0;
   var1840.b=0;
   var1841.b=0;
   var1842.b=0;
   var1843.b=0;
   var1844.b=0;
   var1845.b=0;
   var1846.b=0;
   var1847.b=0;
   var1848.b=0;
   var1849.b=0;
   var1850.b=0;
   var1851.b=0;
   var1852.b=0;
   var1853.b=0;
   var1854.b=0;
   var1855.b=0;
   var1856.b=0;
   var1857.b=0;
   var1858.b=0;
   var1859.b=0;
   var1860.b=0;
   var1861.b=0;
   var1862.b=0;
   var1863.b=0;
   var1864.b=0;
   var1865.b=0;
   var1866.b=0;
   var1867.b=0;
   var1868.b=0;
   var1869.b=0;
   var1870.b=0;
   var1871.b=0;
   var1872.b=0;
   var1873.b=0;
   var1874.b=0;
   var1875.f=0.0;
   var1876.b=0;
   var1877.b=0;
   var1878.b=0;
   var1879.b=0;
   var1880.b=0;
   var1881.b=0;
   var1882.b=0;
   var1883.b=0;
   var1884.b=0;
   var1885.b=0;
   var1886.b=0;
   var1887.b=0;
   var1888.b=0;
   var1889.b=0;
   var1890.b=0;
   var1891.b=0;
   var1892.b=0;
   var1893.b=0;
   var1894.b=0;
   var1895.b=0;
   var1896.b=0;
   var1897.b=0;
   var1898.b=0;
   var1899.b=0;
   var1900.b=0;
   var1901.b=0;
   var1902.b=0;
   var1903.b=0;
   var1904.b=0;
   var1905.b=0;
   var1906.b=0;
   var1907.b=0;
   var1908.b=0;
   var1909.b=0;
   var1910.f=0.0;
   var1911.f=0.0;
   var1912.b=0;
   var1913.b=0;
   var1914.b=0;
   var1915.b=0;
   var1916.b=0;
   var1917.b=0;
   var1918.b=0;
   var1919.b=0;
   var1920.b=0;
   var1921.b=0;
   var1922.b=0;
   var1923.b=0;
   var1924.b=0;
   var1925.b=0;
   var1926.b=0;
   var1927.b=0;
   var1928.b=0;
   var1929.b=0;
   var1930.b=0;
   var1931.b=0;
   var1932.b=0;
   var1933.b=0;
   var1934.b=0;
   var1935.b=0;
   var1936.b=0;
   var1937.b=0;
   var1938.f=0.0;
   var1939.b=0;
   var1940.b=0;
   var1941.f=0.0;
   var1942.b=0;
   var1943.b=0;
   var1944.f=0.0;
   var1945.b=0;
   var1946.b=0;
   var1947.f=0.0;
   var1948.b=0;
   var1949.b=0;
   var1950.f=0.0;
   var1951.b=0;
   var1952.b=0;
   var1953.f=0.0;
   var1954.b=0;
   var1955.b=0;
   var1956.f=0.0;
   var1957.b=0;
   var1958.b=0;
   var1959.b=0;
   var1960.f=0.0;
   var1961.b=0;
   var1962.b=0;
   var1963.b=0;
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
  scalzz(&S_scalzz_193_2);
  scalzz(&S_scalzz_195_2);
  or2(&S_or2_11_2);
  or2(&S_or2_42_2);
  or2(&S_or2_13_2);
  or2(&S_or2_43_2);
  or2(&S_or2_74_2);
  or2(&S_or2_71_2);
  and3(&S_and3_79_2);
  or2(&S_or2_103_2);
  or2(&S_or2_104_2);
  and3(&S_and3_111_2);
  and4(&S_and4_136_2);
  and4(&S_and4_162_2);
  schl24(&S_schl24_147_2);
  schl24(&S_schl24_151_2);
  noto(&S_noto_240_2);
  noto(&S_noto_241_2);
  noto(&S_noto_242_2);
  noto(&S_noto_260_2);
  noto(&S_noto_261_2);
  noto(&S_noto_262_2);
  fsumo(&S_fsumo_233_2);
  bol(&S_bol_234_2);
  lkb(&S_lkb_80_2);
  lkb(&S_lkb_112_2);
  and4(&S_and4_108_2);
  zzfs(&S_zzfs_127_2);
  zzfs(&S_zzfs_132_2);
  zzfs(&S_zzfs_134_2);
  zzfs(&S_zzfs_141_2);
  zzfs(&S_zzfs_144_2);
  zzfs(&S_zzfs_149_2);
  zzfs(&S_zzfs_155_2);
  zzfs(&S_zzfs_158_2);
  zzfs(&S_zzfs_165_2);
  zzfs(&S_zzfs_173_2);
  zzfs(&S_zzfs_176_2);
  zzfs(&S_zzfs_182_2);
  enctkb(&S_enctkb_75_2);
  enctkb(&S_enctkb_106_2);
  drg(&S_drg_205_2);
  drg(&S_drg_198_2);
  geterr(&S_geterr_197_2);
  drg(&S_drg_214_2);
  drg(&S_drg_208_2);
  geterr(&S_geterr_200_2);
  tprg(&S_tprg_220_2);
  tprg(&S_tprg_228_2);
  noto(&S_noto_231_2);
  noto(&S_noto_222_2);
  andn(&S_andn_138_2);
  noto(&S_noto_145_2);
  andn(&S_andn_166_2);
  noto(&S_noto_177_2);
  andn(&S_andn_179_2);
  noto(&S_noto_180_2);
  and2(&S_and2_230_2);
  and3(&S_and3_20_2);
  and3(&S_and3_47_2);
  and3(&S_and3_23_2);
  and3(&S_and3_51_2);
  and3(&S_and3_82_2);
  or3(&S_or3_135_2);
  or3(&S_or3_161_2);
  and2(&S_and2_223_2);
  or2(&S_or2_203_2);
  or2(&S_or2_207_2);
  lkb(&S_lkb_21_2);
  lkb(&S_lkb_24_2);
  lkb(&S_lkb_48_2);
  lkb(&S_lkb_83_2);
  lkb(&S_lkb_52_2);
  lkb(&S_lkb_109_2);
  enctkb(&S_enctkb_15_2);
  enctkb(&S_enctkb_53_2);
  enctkb(&S_enctkb_49_2);
  enctkb(&S_enctkb_77_2);
  enctkb(&S_enctkb_110_2);
  enctkb(&S_enctkb_17_2);
  noto(&S_noto_142_2);
  noto(&S_noto_160_2);
  and2(&S_and2_244_2);
  and2(&S_and2_265_2);
  ornc(&S_ornc_124_2);
  ornc(&S_ornc_245_2);
  ornc(&S_ornc_266_2);
  noto(&S_noto_251_2);
  noto(&S_noto_267_2);
  or2(&S_or2_269_2);
  ornc(&S_ornc_243_2);
  ornc(&S_ornc_254_2);
  noto(&S_noto_246_2);
  noto(&S_noto_264_2);
  or2(&S_or2_255_2);
  setData(idR0EE02LDU,&var1023);
  setData(idB8VC01RDU,&var1941);
  setData(idB2VC01RDU,&var1953);
  setData(idA2VC01RDU,&var1956);
  setData(idA3VC01RDU,&var1950);
  setData(idB0VS11LDU,&var1918);
  setData(idA0VS11LDU,&var1919);
  setData(idB0VN01LDU,&var1888);
  setData(idA0VN01LDU,&var1890);
  setData(idB0VP01LDU,&var1924);
  setData(idA0VP01LDU,&var1925);
  setData(idB0VE01LDU,&var1915);
  setData(idA0VE01LDU,&var1917);
  setData(idA3VP82LDU,&var1886);
  setData(idB3VP82LDU,&var1909);
  setData(idB3VP52LDU,&var1934);
  setData(idB3CP02RDU,&var1910);
  setData(idB3VP42LDU,&var1884);
  setData(idA3VP52LDU,&var1937);
  setData(idA3CP02RDU,&var1911);
  setData(idA3VP42LDU,&var1885);
  setData(idA1VC01RDU,&var1938);
  setData(idA8VC01RDU,&var1944);
  setData(idB3VC01RDU,&var1947);
  setData(idB1VC01RDU,&var1960);
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
  noto(&S_noto_145_1);
  noto(&S_noto_144_1);
  noto(&S_noto_155_1);
  noto(&S_noto_829_1);
  noto(&S_noto_796_1);
  noto(&S_noto_1221_1);
  noto(&S_noto_1738_1);
  noto(&S_noto_1404_1);
  noto(&S_noto_948_1);
  noto(&S_noto_226_1);
  noto(&S_noto_592_1);
  noto(&S_noto_1059_1);
  rs(&S_rs_686_1);
  noto(&S_noto_1510_1);
  equz_p(&S_equz_p_32_1);
  equz_p(&S_equz_p_41_1);
  noto(&S_noto_34_1);
  equz_p(&S_equz_p_37_1);
  rs(&S_rs_1644_1);
  noto(&S_noto_1951_1);
  noto(&S_noto_1950_1);
  noto(&S_noto_1956_1);
  noto(&S_noto_1952_1);
  noto(&S_noto_1958_1);
  noto(&S_noto_1929_1);
  noto(&S_noto_1930_1);
  noto(&S_noto_1931_1);
  noto(&S_noto_1932_1);
  noto(&S_noto_1933_1);
  noto(&S_noto_2256_1);
  equz_p(&S_equz_p_94_1);
  equz_p(&S_equz_p_95_1);
  equz_p(&S_equz_p_96_1);
  noto(&S_noto_1025_1);
  equz_p(&S_equz_p_97_1);
  equz_p(&S_equz_p_98_1);
  noto(&S_noto_179_1);
  equz_p(&S_equz_p_99_1);
  noto(&S_noto_12_1);
  noto(&S_noto_2031_1);
  equz_p(&S_equz_p_1973_1);
  equz_p(&S_equz_p_1972_1);
  equz_p(&S_equz_p_1974_1);
  equz_p(&S_equz_p_1975_1);
  equz_p(&S_equz_p_1976_1);
  noto(&S_noto_1938_1);
  noto(&S_noto_1991_1);
  noto(&S_noto_2010_1);
  rs(&S_rs_676_1);
  noto(&S_noto_1970_1);
  noto(&S_noto_1996_1);
  noto(&S_noto_1477_1);
  rsun(&S_rsun_1570_1);
  rs(&S_rs_678_1);
  rs(&S_rs_680_1);
  rs(&S_rs_696_1);
  rs(&S_rs_712_1);
  rs(&S_rs_685_1);
  rs(&S_rs_700_1);
  rs(&S_rs_26_1);
  rs(&S_rs_1639_1);
  rs(&S_rs_1594_1);
  rs(&S_rs_2064_1);
  noto(&S_noto_1589_1);
  noto(&S_noto_1629_1);
  noto(&S_noto_1634_1);
  noto(&S_noto_2022_1);
  noto(&S_noto_2059_1);
  noto(&S_noto_2078_1);
  noto(&S_noto_2044_1);
  noto(&S_noto_647_1);
  noto(&S_noto_22_1);
  noto(&S_noto_23_1);
  noto(&S_noto_24_1);
  noto(&S_noto_25_1);
  noto(&S_noto_650_1);
  noto(&S_noto_648_1);
  noto(&S_noto_49_1);
  noto(&S_noto_277_1);
  noto(&S_noto_280_1);
  noto(&S_noto_289_1);
  noto(&S_noto_293_1);
  noto(&S_noto_285_1);
  noto(&S_noto_1103_1);
  noto(&S_noto_1109_1);
  noto(&S_noto_2113_1);
  noto(&S_noto_2115_1);
  rs(&S_rs_1187_1);
  rs(&S_rs_1190_1);
  rs(&S_rs_1193_1);
  rs(&S_rs_1196_1);
  ovbs(&S_ovbs_1307_1);
  ovbs(&S_ovbs_2281_1);
  sr(&S_sr_1180_1);
  bol(&S_bol_1174_1);
  ma(&S_ma_84_1);
  sr(&S_sr_82_1);
  bol(&S_bol_274_1);
  bol(&S_bol_270_1);
  bol(&S_bol_1549_1);
  bol(&S_bol_1547_1);
  bol(&S_bol_1100_1);
  bol(&S_bol_1093_1);
  bol(&S_bol_633_1);
  bol(&S_bol_637_1);
  bol(&S_bol_646_1);
  bol(&S_bol_652_1);
  and2(&S_and2_817_1);
  and2(&S_and2_27_1);
  and2(&S_and2_28_1);
  and2(&S_and2_29_1);
  and2(&S_and2_30_1);
  and2(&S_and2_42_1);
  and2(&S_and2_38_1);
  and2(&S_and2_808_1);
  or4(&S_or4_451_1);
  or2(&S_or2_821_1);
  or3(&S_or3_5_1);
  or2(&S_or2_6_1);
  or2(&S_or2_1420_1);
  or2(&S_or2_964_1);
  or2(&S_or2_243_1);
  or2(&S_or2_609_1);
  or2(&S_or2_1074_1);
  or2(&S_or2_1525_1);
  or2(&S_or2_1179_1);
  and2(&S_and2_1173_1);
  or2(&S_or2_20_1);
  or2(&S_or2_39_1);
  or2(&S_or2_35_1);
  or2(&S_or2_48_1);
  or2(&S_or2_758_1);
  or3(&S_or3_745_1);
  or4(&S_or4_762_1);
  or2(&S_or2_779_1);
  or3(&S_or3_804_1);
  and2(&S_and2_828_1);
  and2(&S_and2_802_1);
  or2(&S_or2_809_1);
  or2(&S_or2_724_1);
  or2(&S_or2_726_1);
  or2(&S_or2_728_1);
  or2(&S_or2_1281_1);
  or2(&S_or2_1308_1);
  and4(&S_and4_1185_1);
  or2(&S_or2_1184_1);
  and2(&S_and2_1199_1);
  or2(&S_or2_1217_1);
  and3(&S_and3_278_1);
  and3(&S_and3_296_1);
  or2(&S_or2_669_1);
  or2(&S_or2_677_1);
  or2(&S_or2_679_1);
  or2(&S_or2_682_1);
  or2(&S_or2_653_1);
  and2(&S_and2_703_1);
  or2(&S_or2_710_1);
  and2(&S_and2_674_1);
  or2(&S_or2_689_1);
  or2(&S_or2_684_1);
  or2(&S_or2_707_1);
  and2(&S_and2_664_1);
  or2(&S_or2_361_1);
  or2(&S_or2_366_1);
  or2(&S_or2_826_1);
  or2(&S_or2_503_1);
  or2(&S_or2_561_1);
  and2(&S_and2_578_1);
  and2(&S_and2_579_1);
  and2(&S_and2_591_1);
  or2(&S_or2_581_1);
  or2(&S_or2_193_1);
  and2(&S_and2_177_1);
  and2(&S_and2_213_1);
  and2(&S_and2_212_1);
  or2(&S_or2_215_1);
  and2(&S_and2_225_1);
  or2(&S_or2_867_1);
  or2(&S_or2_915_1);
  or2(&S_or2_935_1);
  and2(&S_and2_1020_1);
  or2(&S_or2_1031_1);
  or2(&S_or2_1023_1);
  or2(&S_or2_1048_1);
  or2(&S_or2_1499_1);
  or2(&S_or2_1475_1);
  and2(&S_and2_1470_1);
  or2(&S_or2_1483_1);
  or2(&S_or2_1390_1);
  or2(&S_or2_1370_1);
  and2(&S_and2_1108_1);
  and2(&S_and2_1590_1);
  zpfs(&S_zpfs_1600_1);
  and2(&S_and2_1630_1);
  zpfs(&S_zpfs_1650_1);
  and2(&S_and2_1635_1);
  zpfs(&S_zpfs_1656_1);
  and2(&S_and2_1672_1);
  or2(&S_or2_2282_1);
  or2(&S_or2_1793_1);
  or2(&S_or2_1794_1);
  or2(&S_or2_1734_1);
  or2(&S_or2_1936_1);
  or2(&S_or2_1937_1);
  or4(&S_or4_1943_1);
  or4(&S_or4_1944_1);
  or2(&S_or2_1946_1);
  or2(&S_or2_1940_1);
  or2(&S_or2_1939_1);
  or3(&S_or3_1948_1);
  and2(&S_and2_1977_1);
  or2(&S_or2_1978_1);
  and2(&S_and2_1984_1);
  and2(&S_and2_2000_1);
  or2(&S_or2_2011_1);
  zpfs(&S_zpfs_1980_1);
  zpfs(&S_zpfs_1981_1);
  zpfs(&S_zpfs_1982_1);
  zpfs(&S_zpfs_1983_1);
  or2(&S_or2_1986_1);
  and2(&S_and2_1987_1);
  or2(&S_or2_2002_1);
  or3(&S_or3_1988_1);
  or2(&S_or2_2065_1);
  ma(&S_ma_1625_1);
  zpfs(&S_zpfs_2035_1);
  and2(&S_and2_2036_1);
  or2(&S_or2_2030_1);
  and3(&S_and3_2033_1);
  or2(&S_or2_2041_1);
  or2(&S_or2_246_1);
  ovbs(&S_ovbs_77_1);
  ovbs(&S_ovbs_21_1);
  ovbs(&S_ovbs_121_1);
  ovbs(&S_ovbs_114_1);
  ovbs(&S_ovbs_1584_1);
  ovbs(&S_ovbs_824_1);
  ovbs(&S_ovbs_312_1);
  ovbs(&S_ovbs_357_1);
  ovbs(&S_ovbs_51_1);
  or2(&S_or2_2178_1);
  or2(&S_or2_2166_1);
  noto(&S_noto_2197_1);
  bol(&S_bol_1714_1);
  bol(&S_bol_1710_1);
  or2(&S_or2_1712_1);
  bol(&S_bol_1697_1);
  bol(&S_bol_1687_1);
  or2(&S_or2_1692_1);
  bol(&S_bol_1717_1);
  bol(&S_bol_1708_1);
  or2(&S_or2_1716_1);
  bol(&S_bol_1702_1);
  bol(&S_bol_1693_1);
  or2(&S_or2_1700_1);
  and4(&S_and4_45_1);
  abs_subf(&S_abs_subf_1707_1);
  noto(&S_noto_1713_1);
  and2(&S_and2_245_1);
  and2(&S_and2_610_1);
  and2(&S_and2_2440_1);
  rs(&S_rs_2387_1);
  sr(&S_sr_2425_1);
  sr(&S_sr_2402_1);
  rs(&S_rs_2381_1);
  zpfs(&S_zpfs_2409_1);
  or2(&S_or2_2397_1);
  abs_subf(&S_abs_subf_2362_1);
  and2(&S_and2_2370_1);
  noto(&S_noto_997_1);
  zzfs(&S_zzfs_2371_1);
  noto(&S_noto_2382_1);
  or2(&S_or2_1197_1);
  or2(&S_or2_382_1);
  or2(&S_or2_369_1);
  or2(&S_or2_1237_1);
  or2(&S_or2_1241_1);
  or2(&S_or2_241_1);
  or2(&S_or2_607_1);
  nocnm(&S_nocnm_1887_1);
  nocnm(&S_nocnm_1889_1);
  noto(&S_noto_1845_1);
  noto(&S_noto_1846_1);
  noto(&S_noto_2355_1);
  noto(&S_noto_2324_1);
  or2(&S_or2_1597_1);
  or2(&S_or2_1628_1);
  noto(&S_noto_2357_1);
  noto(&S_noto_2326_1);
  noto(&S_noto_108_1);
  and2(&S_and2_803_1);
  and2(&S_and2_806_1);
  or2(&S_or2_128_1);
  noto(&S_noto_1903_1);
  noto(&S_noto_1906_1);
  or2(&S_or2_1869_1);
  or2(&S_or2_1909_1);
  or2(&S_or2_1912_1);
  or2(&S_or2_1880_1);
  or2(&S_or2_1883_1);
  or2(&S_or2_1842_1);
  or2(&S_or2_1816_1);
  or2(&S_or2_1812_1);
  or2(&S_or2_2350_1);
  or2(&S_or2_2354_1);
  or2(&S_or2_2352_1);
  or2(&S_or2_2319_1);
  or2(&S_or2_2321_1);
  or2(&S_or2_2323_1);
  or2(&S_or2_1834_1);
  or2(&S_or2_1867_1);
  diagndev(&S_diagndev_2487_1);
  and2(&S_and2_2492_1);
  or2(&S_or2_2501_1);
  or2(&S_or2_2508_1);
  orn(&S_orn_2503_1);
  or3(&S_or3_2504_1);
  ovbsb(&S_ovbsb_218_1);
  ovbsb(&S_ovbsb_219_1);
  ovbsb(&S_ovbsb_230_1);
  ovbsb(&S_ovbsb_244_1);
  ovbsb(&S_ovbsb_585_1);
  ovbsb(&S_ovbsb_583_1);
  ovbsb(&S_ovbsb_596_1);
  ovbsb(&S_ovbsb_615_1);
  ovbsb(&S_ovbsb_2434_1);
  ovbsb(&S_ovbsb_384_1);
  noto(&S_noto_743_1);
  noto(&S_noto_153_1);
  rs(&S_rs_810_1);
  noto(&S_noto_452_1);
  noto(&S_noto_723_1);
  noto(&S_noto_786_1);
  rs(&S_rs_820_1);
  noto(&S_noto_838_1);
  vmemb(&S_vmemb_730_1);
  vmemb(&S_vmemb_787_1);
  noto(&S_noto_827_1);
  vmemb(&S_vmemb_819_1);
  rs(&S_rs_691_1);
  rs(&S_rs_701_1);
  rs(&S_rs_681_1);
  noto(&S_noto_668_1);
  rs(&S_rs_709_1);
  noto(&S_noto_276_1);
  noto(&S_noto_704_1);
  noto(&S_noto_639_1);
  noto(&S_noto_1099_1);
  noto(&S_noto_1551_1);
  noto(&S_noto_1122_1);
  noto(&S_noto_2090_1);
  kvf(&S_kvf_1648_1);
  noto(&S_noto_78_1);
  samhd(&S_samhd_2280_1);
  samhd(&S_samhd_2286_1);
  newstage(&S_newstage_2284_1);
  noto(&S_noto_1949_1);
  noto(&S_noto_1955_1);
  noto(&S_noto_1957_1);
  noto(&S_noto_1928_1);
  noto(&S_noto_2072_1);
  noto(&S_noto_2068_1);
  noto(&S_noto_2026_1);
  noto(&S_noto_552_1);
  noto(&S_noto_1347_1);
  noto(&S_noto_1363_1);
  noto(&S_noto_1998_1);
  rs(&S_rs_1659_1);
  kvf(&S_kvf_1654_1);
  rs(&S_rs_1653_1);
  noto(&S_noto_1664_1);
  noto(&S_noto_1662_1);
  rs(&S_rs_825_1);
  noto(&S_noto_363_1);
  noto(&S_noto_359_1);
  noto(&S_noto_649_1);
  noto(&S_noto_659_1);
  noto(&S_noto_711_1);
  noto(&S_noto_2097_1);
  noto(&S_noto_2122_1);
  swtakt(&S_swtakt_52_1);
  rs(&S_rs_1189_1);
  and2(&S_and2_835_1);
  and2(&S_and2_11_1);
  and2(&S_and2_113_1);
  and2(&S_and2_240_1);
  and2(&S_and2_606_1);
  or2(&S_or2_14_1);
  or2(&S_or2_8_1);
  or2(&S_or2_167_1);
  and3(&S_and3_777_1);
  and2(&S_and2_738_1);
  or3(&S_or3_815_1);
  and2(&S_and2_811_1);
  and2(&S_and2_719_1);
  or2(&S_or2_284_1);
  and3(&S_and3_300_1);
  or2(&S_or2_702_1);
  and2(&S_and2_671_1);
  and2(&S_and2_661_1);
  and4(&S_and4_662_1);
  and4(&S_and4_672_1);
  and2(&S_and2_697_1);
  or2(&S_or2_705_1);
  or2(&S_or2_708_1);
  and3(&S_and3_354_1);
  and2(&S_and2_549_1);
  or2(&S_or2_554_1);
  and2(&S_and2_619_1);
  and2(&S_and2_634_1);
  or2(&S_or2_183_1);
  and2(&S_and2_256_1);
  and2(&S_and2_271_1);
  and2(&S_and2_1094_1);
  and2(&S_and2_1526_1);
  and2(&S_and2_1548_1);
  and2(&S_and2_1346_1);
  or2(&S_or2_1352_1);
  and2(&S_and2_1359_1);
  or2(&S_or2_1371_1);
  and2(&S_and2_1117_1);
  and2(&S_and2_1127_1);
  or2(&S_or2_1638_1);
  and2(&S_and2_1601_1);
  and2(&S_and2_1651_1);
  or3(&S_or3_1666_1);
  or2(&S_or2_1647_1);
  and2(&S_and2_1657_1);
  or3(&S_or3_1658_1);
  or3(&S_or3_1671_1);
  or3(&S_or3_2279_1);
  or3(&S_or3_2288_1);
  or2(&S_or2_1945_1);
  or3(&S_or3_1947_1);
  or2(&S_or2_1985_1);
  and2(&S_and2_1993_1);
  or3(&S_or3_1989_1);
  and2(&S_and2_2015_1);
  or2(&S_or2_2225_1);
  or2(&S_or2_2150_1);
  or2(&S_or2_2138_1);
  and2(&S_and2_2118_1);
  and2(&S_and2_2116_1);
  and2(&S_and2_2101_1);
  and2(&S_and2_2100_1);
  and2(&S_and2_2070_1);
  and4(&S_and4_2073_1);
  and4(&S_and4_2077_1);
  or2(&S_or2_2079_1);
  or2(&S_or2_2081_1);
  or2(&S_or2_2080_1);
  zpfs(&S_zpfs_2084_1);
  zpfs(&S_zpfs_2087_1);
  zpfs(&S_zpfs_2074_1);
  and2(&S_and2_2075_1);
  or3(&S_or3_2088_1);
  lk(&S_lk_1649_1);
  rsfn(&S_rsfn_1645_1);
  abs_subf(&S_abs_subf_1660_1);
  lk(&S_lk_1646_1);
  rsfn(&S_rsfn_1642_1);
  abs_subf(&S_abs_subf_1655_1);
  and3(&S_and3_2032_1);
  or2(&S_or2_2039_1);
  or2(&S_or2_2040_1);
  zpfs(&S_zpfs_2046_1);
  zpfs(&S_zpfs_2048_1);
  or3(&S_or3_2051_1);
  or2(&S_or2_2053_1);
  and2(&S_and2_1075_1);
  or2(&S_or2_267_1);
  ovbs(&S_ovbs_2054_1);
  ovbs(&S_ovbs_13_1);
  or2(&S_or2_1640_1);
  noto(&S_noto_104_1);
  bol(&S_bol_1701_1);
  bol(&S_bol_1690_1);
  or2(&S_or2_1695_1);
  ml(&S_ml_1704_1);
  ml(&S_ml_1684_1);
  ml(&S_ml_1706_1);
  ml(&S_ml_1685_1);
  and2(&S_and2_119_1);
  noto(&S_noto_117_1);
  and2(&S_and2_123_1);
  and2(&S_and2_122_1);
  noto(&S_noto_188_1);
  noto(&S_noto_507_1);
  noto(&S_noto_1014_1);
  noto(&S_noto_1303_1);
  noto(&S_noto_1360_1);
  bol(&S_bol_1963_1);
  and3(&S_and3_1954_1);
  bol(&S_bol_1927_1);
  and3(&S_and3_1935_1);
  noto(&S_noto_1942_1);
  noto(&S_noto_1953_1);
  bol(&S_bol_1007_1);
  bol(&S_bol_1460_1);
  abs_subf(&S_abs_subf_1688_1);
  noto(&S_noto_1698_1);
  abs_subf(&S_abs_subf_1709_1);
  noto(&S_noto_1718_1);
  bol(&S_bol_2428_1);
  and2(&S_and2_2439_1);
  noto(&S_noto_2396_1);
  fsumo(&S_fsumo_80_1);
  abs_subf(&S_abs_subf_2437_1);
  and2(&S_and2_2442_1);
  and3(&S_and3_2388_1);
  and2(&S_and2_2410_1);
  ovbs(&S_ovbs_2411_1);
  or3(&S_or3_2419_1);
  inf(&S_inf_2392_1);
  noto(&S_noto_1461_1);
  or2(&S_or2_1188_1);
  and2(&S_and2_2226_1);
  and2(&S_and2_106_1);
  and3(&S_and3_1563_1);
  noto(&S_noto_2356_1);
  noto(&S_noto_2325_1);
  ovbsb(&S_ovbsb_262_1);
  ovbsb(&S_ovbsb_247_1);
  ovbsb(&S_ovbsb_1076_1);
  ovbsb(&S_ovbsb_2276_1);
  ovbsb(&S_ovbsb_2275_1);
  ovbsb(&S_ovbsb_2274_1);
  ovbsb(&S_ovbsb_625_1);
  ovbsb(&S_ovbsb_611_1);
  ovbsb(&S_ovbsb_1527_1);
  ovbsb(&S_ovbsb_2289_1);
  ovbsb(&S_ovbsb_2290_1);
  ovbsb(&S_ovbsb_2291_1);
  ovbsb(&S_ovbsb_2433_1);
  ovbsb(&S_ovbsb_2435_1);
  ovbsb(&S_ovbsb_731_1);
  ovbsb(&S_ovbsb_774_1);
  ovbsb(&S_ovbsb_2018_1);
  rs(&S_rs_816_1);
  noto(&S_noto_831_1);
  noto(&S_noto_1391_1);
  noto(&S_noto_936_1);
  noto(&S_noto_216_1);
  rs(&S_rs_683_1);
  noto(&S_noto_582_1);
  noto(&S_noto_1046_1);
  noto(&S_noto_1497_1);
  kvf(&S_kvf_2047_1);
  kvf(&S_kvf_2086_1);
  andn(&S_andn_1941_1);
  rs(&S_rs_19_1);
  noto(&S_noto_141_1);
  noto(&S_noto_1999_1);
  noto(&S_noto_112_1);
  noto(&S_noto_1554_1);
  abs_subf(&S_abs_subf_1128_1);
  abs_subf(&S_abs_subf_1115_1);
  noto(&S_noto_1136_1);
  bol(&S_bol_1149_1);
  bol(&S_bol_1150_1);
  noto(&S_noto_1112_1);
  bol(&S_bol_1152_1);
  bol(&S_bol_1153_1);
  bol(&S_bol_81_1);
  and2(&S_and2_31_1);
  and2(&S_and2_146_1);
  and2(&S_and2_154_1);
  and2(&S_and2_151_1);
  and2(&S_and2_143_1);
  and3(&S_and3_242_1);
  and3(&S_and3_608_1);
  and3(&S_and3_1106_1);
  or3(&S_or3_109_1);
  or2(&S_or2_732_1);
  and2(&S_and2_742_1);
  and2(&S_and2_744_1);
  and2(&S_and2_760_1);
  and2(&S_and2_761_1);
  and2(&S_and2_778_1);
  and2(&S_and2_781_1);
  and3(&S_and3_780_1);
  and2(&S_and2_782_1);
  or2(&S_or2_822_1);
  and2(&S_and2_830_1);
  or2(&S_or2_836_1);
  or2(&S_or2_840_1);
  and3(&S_and3_837_1);
  and2(&S_and2_842_1);
  and2(&S_and2_846_1);
  and2(&S_and2_715_1);
  or2(&S_or2_716_1);
  and2(&S_and2_725_1);
  and2(&S_and2_727_1);
  and2(&S_and2_695_1);
  and2(&S_and2_673_1);
  and2(&S_and2_663_1);
  and3(&S_and3_580_1);
  or2(&S_or2_630_1);
  and3(&S_and3_214_1);
  and3(&S_and3_258_1);
  and3(&S_and3_945_1);
  and3(&S_and3_946_1);
  or2(&S_or2_1090_1);
  or2(&S_or2_1541_1);
  and3(&S_and3_1401_1);
  and3(&S_and3_1402_1);
  or2(&S_or2_1154_1);
  or2(&S_or2_1165_1);
  or2(&S_or2_1161_1);
  or2(&S_or2_1160_1);
  or2(&S_or2_1159_1);
  and2(&S_and2_1566_1);
  and2(&S_and2_1572_1);
  and2(&S_and2_1574_1);
  and2(&S_and2_1576_1);
  and2(&S_and2_1582_1);
  and2(&S_and2_1586_1);
  or3(&S_or3_1610_1);
  and2(&S_and2_1611_1);
  and3(&S_and3_1669_1);
  or3(&S_or3_1652_1);
  and2(&S_and2_1667_1);
  and3(&S_and3_1670_1);
  zpfs(&S_zpfs_2227_1);
  and3(&S_and3_2110_1);
  and2(&S_and2_2105_1);
  or3(&S_or3_2111_1);
  and2(&S_and2_2083_1);
  and4(&S_and4_2091_1);
  and4(&S_and4_2093_1);
  lk(&S_lk_2089_1);
  rsfn(&S_rsfn_2094_1);
  abs_subf(&S_abs_subf_2096_1);
  and3(&S_and3_2099_1);
  lk(&S_lk_2052_1);
  rsfn(&S_rsfn_2055_1);
  abs_subf(&S_abs_subf_2057_1);
  and2(&S_and2_2045_1);
  and3(&S_and3_2049_1);
  or5(&S_or5_149_1);
  and2(&S_and2_2016_1);
  and2(&S_and2_107_1);
  and2(&S_and2_103_1);
  ml(&S_ml_1682_1);
  zpfs(&S_zpfs_823_1);
  and2(&S_and2_1918_1);
  and2(&S_and2_1895_1);
  and2(&S_and2_1916_1);
  and2(&S_and2_1919_1);
  and2(&S_and2_1896_1);
  and2(&S_and2_1917_1);
  and2(&S_and2_1897_1);
  and2(&S_and2_1898_1);
  and2(&S_and2_1899_1);
  and2(&S_and2_1900_1);
  and2(&S_and2_1901_1);
  and2(&S_and2_1902_1);
  and2(&S_and2_1871_1);
  and2(&S_and2_1872_1);
  rs(&S_rs_1873_1);
  and2(&S_and2_1874_1);
  and2(&S_and2_1875_1);
  rs(&S_rs_1876_1);
  and2(&S_and2_1854_1);
  and2(&S_and2_1858_1);
  and2(&S_and2_1821_1);
  and2(&S_and2_1823_1);
  and2(&S_and2_1825_1);
  and2(&S_and2_1827_1);
  and2(&S_and2_1795_1);
  and2(&S_and2_1796_1);
  and2(&S_and2_1797_1);
  and2(&S_and2_1798_1);
  and2(&S_and2_1799_1);
  and2(&S_and2_1800_1);
  and2(&S_and2_1801_1);
  and2(&S_and2_1802_1);
  and2(&S_and2_118_1);
  abs_subf(&S_abs_subf_1686_1);
  noto(&S_noto_1696_1);
  ovbs(&S_ovbs_2389_1);
  and2(&S_and2_2444_1);
  noto(&S_noto_2418_1);
  noto(&S_noto_2366_1);
  noto(&S_noto_2367_1);
  and2(&S_and2_2335_1);
  or4(&S_or4_991_1);
  and2(&S_and2_2304_1);
  or4(&S_or4_1447_1);
  and4(&S_and4_1057_1);
  and4(&S_and4_1508_1);
  or3(&S_or3_1908_1);
  or3(&S_or3_1879_1);
  or3(&S_or3_1882_1);
  or3(&S_or3_1911_1);
  or3(&S_or3_1863_1);
  or3(&S_or3_1865_1);
  or3(&S_or3_1814_1);
  or3(&S_or3_1810_1);
  or3(&S_or3_2342_1);
  or3(&S_or3_2311_1);
  or3(&S_or3_2344_1);
  or3(&S_or3_2346_1);
  or3(&S_or3_2315_1);
  or3(&S_or3_2313_1);
  or2(&S_or2_1840_1);
  or2(&S_or2_1807_1);
  or2(&S_or2_2348_1);
  and2(&S_and2_2332_1);
  or2(&S_or2_2317_1);
  and2(&S_and2_2302_1);
  or2(&S_or2_1832_1);
  or2(&S_or2_1804_1);
  or2(&S_or2_1861_1);
  and2(&S_and2_1857_1);
  ovbsb(&S_ovbsb_221_1);
  ovbsb(&S_ovbsb_252_1);
  ovbsb(&S_ovbsb_259_1);
  ovbsb(&S_ovbsb_587_1);
  ovbsb(&S_ovbsb_614_1);
  ovbsb(&S_ovbsb_102_1);
  ovbsb(&S_ovbsb_2436_1);
  ovbsb(&S_ovbsb_764_1);
  ovbsb(&S_ovbsb_759_1);
  ovbsb(&S_ovbsb_750_1);
  ovbsb(&S_ovbsb_783_1);
  ovbsb(&S_ovbsb_766_1);
  ovbsb(&S_ovbsb_735_1);
  ovbsb(&S_ovbsb_740_1);
  ovbsb(&S_ovbsb_784_1);
  ovbsb(&S_ovbsb_785_1);
  ovbsb(&S_ovbsb_788_1);
  ovbsb(&S_ovbsb_2019_1);
  samhd(&S_samhd_410_1);
  samhd(&S_samhd_416_1);
  samhd(&S_samhd_864_1);
  samhd(&S_samhd_868_1);
  rs(&S_rs_832_1);
  rs(&S_rs_839_1);
  newstage(&S_newstage_413_1);
  newstage(&S_newstage_866_1);
  orn(&S_orn_147_1);
  rs(&S_rs_1803_1);
  rs(&S_rs_1805_1);
  rs(&S_rs_1806_1);
  rs(&S_rs_1808_1);
  rs(&S_rs_1809_1);
  rs(&S_rs_1811_1);
  rs(&S_rs_1813_1);
  rs(&S_rs_1815_1);
  rs(&S_rs_1833_1);
  rs(&S_rs_1841_1);
  rs(&S_rs_1860_1);
  rs(&S_rs_1868_1);
  rs(&S_rs_1878_1);
  rs(&S_rs_2349_1);
  rs(&S_rs_1907_1);
  rs(&S_rs_1904_1);
  rs(&S_rs_1910_1);
  rs(&S_rs_1905_1);
  rs(&S_rs_1913_1);
  rs(&S_rs_1851_1);
  rs(&S_rs_1852_1);
  rs(&S_rs_1853_1);
  rs(&S_rs_1817_1);
  rs(&S_rs_1818_1);
  rs(&S_rs_1819_1);
  rs(&S_rs_1820_1);
  rs(&S_rs_110_1);
  noto(&S_noto_111_1);
  rs(&S_rs_1674_1);
  rs(&S_rs_1673_1);
  rs(&S_rs_1603_1);
  kvf(&S_kvf_1607_1);
  rs(&S_rs_2104_1);
  rs(&S_rs_2050_1);
  noto(&S_noto_1606_1);
  andn(&S_andn_283_1);
  noto(&S_noto_301_1);
  and2(&S_and2_441_1);
  and2(&S_and2_453_1);
  and2(&S_and2_462_1);
  and2(&S_and2_464_1);
  and2(&S_and2_466_1);
  or3(&S_or3_406_1);
  or3(&S_or3_422_1);
  and2(&S_and2_442_1);
  and3(&S_and3_651_1);
  or2(&S_or2_148_1);
  and2(&S_and2_747_1);
  and2(&S_and2_818_1);
  or2(&S_or2_845_1);
  and2(&S_and2_722_1);
  or2(&S_or2_291_1);
  and3(&S_and3_292_1);
  or2(&S_or2_477_1);
  and3(&S_and3_486_1);
  or2(&S_or2_538_1);
  and2(&S_and2_556_1);
  and3(&S_and3_621_1);
  and3(&S_and3_620_1);
  and2(&S_and2_184_1);
  and3(&S_and3_257_1);
  or4(&S_or4_860_1);
  or4(&S_or4_875_1);
  or3(&S_or3_934_1);
  and2(&S_and2_932_1);
  and3(&S_and3_933_1);
  and2(&S_and2_931_1);
  and2(&S_and2_947_1);
  and2(&S_and2_969_1);
  and3(&S_and3_970_1);
  and2(&S_and2_1036_1);
  or2(&S_or2_1047_1);
  and2(&S_and2_1058_1);
  and2(&S_and2_1080_1);
  and3(&S_and3_1081_1);
  and3(&S_and3_1082_1);
  or2(&S_or2_1498_1);
  and2(&S_and2_1509_1);
  and2(&S_and2_1531_1);
  and3(&S_and3_1532_1);
  and3(&S_and3_1533_1);
  and2(&S_and2_1484_1);
  or3(&S_or3_1392_1);
  and3(&S_and3_1389_1);
  and2(&S_and2_1388_1);
  and2(&S_and2_1387_1);
  and2(&S_and2_1403_1);
  and2(&S_and2_1418_1);
  and3(&S_and3_1419_1);
  and2(&S_and2_1425_1);
  and3(&S_and3_1426_1);
  and2(&S_and2_1356_1);
  and2(&S_and2_1376_1);
  and2(&S_and2_1166_1);
  and2(&S_and2_1170_1);
  or2(&S_or2_1598_1);
  or3(&S_or3_1602_1);
  or2(&S_or2_1914_1);
  or2(&S_or2_2254_1);
  lk(&S_lk_1608_1);
  rsfn(&S_rsfn_1604_1);
  abs_subf(&S_abs_subf_1613_1);
  ovbs(&S_ovbs_2247_1);
  ovbs(&S_ovbs_116_1);
  and2(&S_and2_516_1);
  and2(&S_and2_478_1);
  and2(&S_and2_475_1);
  rs(&S_rs_1915_1);
  rs(&S_rs_1881_1);
  and2(&S_and2_1855_1);
  and2(&S_and2_1856_1);
  and2(&S_and2_1859_1);
  and2(&S_and2_1824_1);
  and2(&S_and2_1828_1);
  zpfs(&S_zpfs_2374_1);
  zpfs(&S_zpfs_2375_1);
  and2(&S_and2_2240_1);
  and3(&S_and3_443_1);
  and2(&S_and2_2239_1);
  rs(&S_rs_2341_1);
  rs(&S_rs_2329_1);
  rs(&S_rs_2333_1);
  and2(&S_and2_2339_1);
  rs(&S_rs_2351_1);
  rs(&S_rs_2334_1);
  and2(&S_and2_2340_1);
  rs(&S_rs_2353_1);
  rs(&S_rs_2318_1);
  rs(&S_rs_2310_1);
  rs(&S_rs_2298_1);
  rs(&S_rs_2301_1);
  and2(&S_and2_2308_1);
  rs(&S_rs_2320_1);
  rs(&S_rs_2303_1);
  and2(&S_and2_2309_1);
  rs(&S_rs_2322_1);
  regch(&S_regch_126_1);
  rs(&S_rs_1866_1);
  ovbsb(&S_ovbsb_263_1);
  ovbsb(&S_ovbsb_1396_1);
  ovbsb(&S_ovbsb_1393_1);
  ovbsb(&S_ovbsb_1394_1);
  ovbsb(&S_ovbsb_1429_1);
  ovbsb(&S_ovbsb_1408_1);
  ovbsb(&S_ovbsb_1430_1);
  ovbsb(&S_ovbsb_1424_1);
  ovbsb(&S_ovbsb_1423_1);
  ovbsb(&S_ovbsb_1085_1);
  ovbsb(&S_ovbsb_1063_1);
  ovbsb(&S_ovbsb_1086_1);
  ovbsb(&S_ovbsb_2228_1);
  ovbsb(&S_ovbsb_1087_1);
  ovbsb(&S_ovbsb_2229_1);
  ovbsb(&S_ovbsb_853_1);
  ovbsb(&S_ovbsb_854_1);
  ovbsb(&S_ovbsb_855_1);
  ovbsb(&S_ovbsb_859_1);
  ovbsb(&S_ovbsb_399_1);
  ovbsb(&S_ovbsb_400_1);
  ovbsb(&S_ovbsb_401_1);
  ovbsb(&S_ovbsb_404_1);
  ovbsb(&S_ovbsb_454_1);
  ovbsb(&S_ovbsb_438_1);
  ovbsb(&S_ovbsb_437_1);
  ovbsb(&S_ovbsb_446_1);
  ovbsb(&S_ovbsb_624_1);
  ovbsb(&S_ovbsb_627_1);
  ovbsb(&S_ovbsb_941_1);
  ovbsb(&S_ovbsb_939_1);
  ovbsb(&S_ovbsb_938_1);
  ovbsb(&S_ovbsb_973_1);
  ovbsb(&S_ovbsb_952_1);
  ovbsb(&S_ovbsb_974_1);
  ovbsb(&S_ovbsb_1536_1);
  ovbsb(&S_ovbsb_1514_1);
  ovbsb(&S_ovbsb_1537_1);
  ovbsb(&S_ovbsb_1538_1);
  ovbsb(&S_ovbsb_876_1);
  ovbsb(&S_ovbsb_880_1);
  ovbsb(&S_ovbsb_881_1);
  ovbsb(&S_ovbsb_882_1);
  ovbsb(&S_ovbsb_420_1);
  ovbsb(&S_ovbsb_427_1);
  ovbsb(&S_ovbsb_426_1);
  ovbsb(&S_ovbsb_428_1);
  ovbsb(&S_ovbsb_474_1);
  ovbsb(&S_ovbsb_465_1);
  ovbsb(&S_ovbsb_463_1);
  ovbsb(&S_ovbsb_469_1);
  ovbsb(&S_ovbsb_756_1);
  ovbsb(&S_ovbsb_729_1);
  rs(&S_rs_812_1);
  rs(&S_rs_844_1);
  rs(&S_rs_656_1);
  noto(&S_noto_670_1);
  orni(&S_orni_1571_1);
  noto(&S_noto_2248_1);
  rs(&S_rs_1835_1);
  rs(&S_rs_1843_1);
  rs(&S_rs_1862_1);
  rs(&S_rs_1864_1);
  rs(&S_rs_1870_1);
  ma(&S_ma_1609_1);
  rs(&S_rs_666_1);
  noto(&S_noto_1102_1);
  noto(&S_noto_295_1);
  noto(&S_noto_1162_1);
  noto(&S_noto_1163_1);
  noto(&S_noto_1133_1);
  and2(&S_and2_445_1);
  and2(&S_and2_468_1);
  and2(&S_and2_962_1);
  and3(&S_and3_963_1);
  and3(&S_and3_1073_1);
  and3(&S_and3_1524_1);
  and2(&S_and2_690_1);
  and2(&S_and2_1043_1);
  and2(&S_and2_1044_1);
  and3(&S_and3_1045_1);
  and2(&S_and2_1494_1);
  and2(&S_and2_1495_1);
  and3(&S_and3_1496_1);
  and5(&S_and5_1107_1);
  and2(&S_and2_1155_1);
  or4(&S_or4_1114_1);
  and3(&S_and3_1617_1);
  or2(&S_or2_2003_1);
  and2(&S_and2_2006_1);
  and2(&S_and2_2265_1);
  ovbs(&S_ovbs_2249_1);
  noto(&S_noto_2379_1);
  noto(&S_noto_2380_1);
  andn(&S_andn_654_1);
  andn(&S_andn_655_1);
  and2(&S_and2_2268_1);
  or5(&S_or5_2266_1);
  and2(&S_and2_2336_1);
  or3(&S_or3_1338_1);
  rs(&S_rs_2343_1);
  rs(&S_rs_2330_1);
  and2(&S_and2_2305_1);
  rs(&S_rs_2312_1);
  rs(&S_rs_2299_1);
  or3(&S_or3_899_1);
  or2(&S_or2_129_1);
  ovbsb(&S_ovbsb_1050_1);
  ovbsb(&S_ovbsb_1051_1);
  ovbsb(&S_ovbsb_1053_1);
  ovbsb(&S_ovbsb_1078_1);
  ovbsb(&S_ovbsb_440_1);
  ovbsb(&S_ovbsb_966_1);
  ovbsb(&S_ovbsb_968_1);
  ovbsb(&S_ovbsb_1501_1);
  ovbsb(&S_ovbsb_1504_1);
  ovbsb(&S_ovbsb_1502_1);
  ovbsb(&S_ovbsb_1529_1);
  ovbsb(&S_ovbsb_467_1);
  ovbsb(&S_ovbsb_1137_1);
  rs(&S_rs_1113_1);
  noto(&S_noto_2250_1);
  rs(&S_rs_2255_1);
  rs(&S_rs_1620_1);
  noto(&S_noto_1131_1);
  provsbr(&S_provsbr_1568_1);
  rs(&S_rs_1567_1);
  and2(&S_and2_593_1);
  and2(&S_and2_227_1);
  and2(&S_and2_949_1);
  and2(&S_and2_1060_1);
  and2(&S_and2_1511_1);
  and2(&S_and2_1405_1);
  and3(&S_and3_1119_1);
  and3(&S_and3_1125_1);
  and2(&S_and2_1143_1);
  and2(&S_and2_1130_1);
  and3(&S_and3_1177_1);
  or2(&S_or2_1573_1);
  or2(&S_or2_1575_1);
  or2(&S_or2_1577_1);
  or2(&S_or2_1583_1);
  or2(&S_or2_1587_1);
  orni(&S_orni_1579_1);
  or2(&S_or2_2001_1);
  noto(&S_noto_2386_1);
  and2(&S_and2_2337_1);
  and2(&S_and2_2306_1);
  rs(&S_rs_2331_1);
  and2(&S_and2_2338_1);
  rs(&S_rs_2347_1);
  rs(&S_rs_2300_1);
  ovbsb(&S_ovbsb_234_1);
  ovbsb(&S_ovbsb_1411_1);
  ovbsb(&S_ovbsb_1064_1);
  ovbsb(&S_ovbsb_600_1);
  ovbsb(&S_ovbsb_955_1);
  ovbsb(&S_ovbsb_1517_1);
  rs(&S_rs_2345_1);
  newstage(&S_newstage_1994_1);
  cntch(&S_cntch_1578_1);
  rs(&S_rs_1138_1);
  rs(&S_rs_1171_1);
  rs(&S_rs_1145_1);
  noto(&S_noto_1146_1);
  or3(&S_or3_157_1);
  or3(&S_or3_528_1);
  or2(&S_or2_1167_1);
  and2(&S_and2_1580_1);
  or2(&S_or2_1750_1);
  rs(&S_rs_2314_1);
  and2(&S_and2_2307_1);
  rs(&S_rs_2316_1);
  cnshd(&S_cnshd_1757_1);
  noto(&S_noto_961_1);
  ornc(&S_ornc_166_1);
  charint(&S_charint_158_1);
  noto(&S_noto_238_1);
  ornc(&S_ornc_536_1);
  charint(&S_charint_530_1);
  noto(&S_noto_604_1);
  noto(&S_noto_1067_1);
  noto(&S_noto_1520_1);
  rs(&S_rs_1156_1);
  or2(&S_or2_1778_1);
  and2(&S_and2_1720_1);
  and2(&S_and2_1721_1);
  and2(&S_and2_1722_1);
  and2(&S_and2_1723_1);
  and2(&S_and2_1733_1);
  and2(&S_and2_1735_1);
  and2(&S_and2_1737_1);
  or2(&S_or2_2257_1);
  and2(&S_and2_1144_1);
  and2(&S_and2_2253_1);
  and2(&S_and2_2264_1);
  ovbsb(&S_ovbsb_1747_1);
  ovbsb(&S_ovbsb_1725_1);
  ovbsb(&S_ovbsb_1726_1);
  ovbsb(&S_ovbsb_1728_1);
  ovbsb(&S_ovbsb_1730_1);
  ovbsb(&S_ovbsb_1739_1);
  ovbsb(&S_ovbsb_1744_1);
  ovbsb(&S_ovbsb_2246_1);
  ovbsb(&S_ovbsb_2263_1);
  fnapb(&S_fnapb_1779_1);
  samhd(&S_samhd_1760_1);
  zpfs(&S_zpfs_1775_1);
  zpfs(&S_zpfs_1771_1);
  noto(&S_noto_1415_1);
  fsumz(&S_fsumz_159_1);
  fsumz(&S_fsumz_531_1);
  orni(&S_orni_1295_1);
  rs(&S_rs_1140_1);
  rs(&S_rs_1141_1);
  ma(&S_ma_164_1);
  ma(&S_ma_537_1);
  zpfs(&S_zpfs_1785_1);
  or2(&S_or2_1239_1);
  or3(&S_or3_1139_1);
  or3(&S_or3_1768_1);
  or5(&S_or5_2267_1);
  ovbsb(&S_ovbsb_1761_1);
  ovbsb(&S_ovbsb_1772_1);
  ovbsb(&S_ovbsb_1782_1);
  ovbsb(&S_ovbsb_1781_1);
  ovbsb(&S_ovbsb_1774_1);
  ovbsb(&S_ovbsb_1766_1);
  samhd(&S_samhd_1300_1);
  samhd(&S_samhd_1309_1);
  newstage(&S_newstage_1306_1);
  cnshd(&S_cnshd_1242_1);
  noto(&S_noto_1414_1);
  noto(&S_noto_960_1);
  fnapb(&S_fnapb_194_1);
  noto(&S_noto_237_1);
  fnapb(&S_fnapb_562_1);
  zpfs(&S_zpfs_557_1);
  zpfs(&S_zpfs_558_1);
  noto(&S_noto_603_1);
  noto(&S_noto_1066_1);
  noto(&S_noto_1519_1);
  rs(&S_rs_2258_1);
  or2(&S_or2_1299_1);
  or2(&S_or2_1313_1);
  or2(&S_or2_1266_1);
  and2(&S_and2_1207_1);
  and2(&S_and2_1204_1);
  and2(&S_and2_1205_1);
  and2(&S_and2_1206_1);
  and2(&S_and2_1216_1);
  and2(&S_and2_1218_1);
  and2(&S_and2_1220_1);
  and2(&S_and2_692_1);
  zpfs(&S_zpfs_577_1);
  or2(&S_or2_595_1);
  zpfs(&S_zpfs_208_1);
  zpfs(&S_zpfs_186_1);
  zpfs(&S_zpfs_187_1);
  or2(&S_or2_229_1);
  or2(&S_or2_951_1);
  and2(&S_and2_950_1);
  or2(&S_or2_1062_1);
  or2(&S_or2_1513_1);
  or2(&S_or2_1407_1);
  and2(&S_and2_1406_1);
  and2(&S_and2_1135_1);
  or2(&S_or2_2243_1);
  or2(&S_or2_1147_1);
  and2(&S_and2_1304_1);
  and2(&S_and2_1310_1);
  or4(&S_or4_2128_1);
  and2(&S_and2_2244_1);
  ovbsb(&S_ovbsb_203_1);
  ovbsb(&S_ovbsb_195_1);
  ovbsb(&S_ovbsb_196_1);
  ovbsb(&S_ovbsb_197_1);
  ovbsb(&S_ovbsb_1412_1);
  ovbsb(&S_ovbsb_1293_1);
  ovbsb(&S_ovbsb_1294_1);
  ovbsb(&S_ovbsb_1297_1);
  ovbsb(&S_ovbsb_570_1);
  ovbsb(&S_ovbsb_565_1);
  ovbsb(&S_ovbsb_564_1);
  ovbsb(&S_ovbsb_563_1);
  ovbsb(&S_ovbsb_958_1);
  ovbsb(&S_ovbsb_1314_1);
  ovbsb(&S_ovbsb_1315_1);
  ovbsb(&S_ovbsb_1316_1);
  ovbsb(&S_ovbsb_1230_1);
  ovbsb(&S_ovbsb_1209_1);
  ovbsb(&S_ovbsb_1211_1);
  ovbsb(&S_ovbsb_1213_1);
  ovbsb(&S_ovbsb_1215_1);
  ovbsb(&S_ovbsb_1222_1);
  ovbsb(&S_ovbsb_1227_1);
  fnapb(&S_fnapb_1267_1);
  samhd(&S_samhd_1248_1);
  zpfs(&S_zpfs_1261_1);
  zpfs(&S_zpfs_1257_1);
  orn(&S_orn_1416_1);
  orn(&S_orn_956_1);
  noto(&S_noto_2259_1);
  rs(&S_rs_1134_1);
  zpfs(&S_zpfs_1272_1);
  and2(&S_and2_594_1);
  orn(&S_orn_605_1);
  and2(&S_and2_228_1);
  and2(&S_and2_1061_1);
  and2(&S_and2_1512_1);
  and2(&S_and2_1148_1);
  or2(&S_or2_1142_1);
  or3(&S_or3_1254_1);
  zpfs(&S_zpfs_2238_1);
  or2(&S_or2_2146_1);
  or2(&S_or2_2134_1);
  ovbs(&S_ovbs_2129_1);
  ovbs(&S_ovbs_2142_1);
  ovbs(&S_ovbs_2132_1);
  noto(&S_noto_2133_1);
  and2(&S_and2_2139_1);
  and2(&S_and2_2151_1);
  or3(&S_or3_127_1);
  ovbsb(&S_ovbsb_235_1);
  ovbsb(&S_ovbsb_1065_1);
  ovbsb(&S_ovbsb_601_1);
  ovbsb(&S_ovbsb_1518_1);
  ovbsb(&S_ovbsb_1265_1);
  ovbsb(&S_ovbsb_1251_1);
  ovbsb(&S_ovbsb_1270_1);
  ovbsb(&S_ovbsb_1264_1);
  ovbsb(&S_ovbsb_1259_1);
  ovbsb(&S_ovbsb_1252_1);
  orn(&S_orn_239_1);
  orn(&S_orn_1068_1);
  orn(&S_orn_1521_1);
  noto(&S_noto_2130_1);
  noto(&S_noto_2143_1);
  rs(&S_rs_2147_1);
  noto(&S_noto_2148_1);
  rs(&S_rs_2135_1);
  rs(&S_rs_1186_1);
  or2(&S_or2_2102_1);
  irm(&S_irm_2369_1);
  ml(&S_ml_988_1);
  ml(&S_ml_1444_1);
  noto(&S_noto_2136_1);
  noto(&S_noto_66_1);
  noto(&S_noto_2103_1);
  and2(&S_and2_58_1);
  and2(&S_and2_62_1);
  and4(&S_and4_348_1);
  or2(&S_or2_1560_1);
  or2(&S_or2_2119_1);
  noto(&S_noto_1556_1);
  rs(&S_rs_351_1);
  noto(&S_noto_346_1);
  noto(&S_noto_288_1);
  rs(&S_rs_2120_1);
  rs(&S_rs_2121_1);
  or4(&S_or4_299_1);
  or2(&S_or2_282_1);
  or2(&S_or2_305_1);
  or2(&S_or2_343_1);
  or4(&S_or4_352_1);
  and2(&S_and2_1555_1);
  or2(&S_or2_2183_1);
  or2(&S_or2_2204_1);
  rs(&S_rs_298_1);
  provsbr(&S_provsbr_287_1);
  equz_p(&S_equz_p_326_1);
  bolz(&S_bolz_327_1);
  provsbr(&S_provsbr_345_1);
  bolz(&S_bolz_350_1);
  noto(&S_noto_67_1);
  noto(&S_noto_56_1);
  and2(&S_and2_59_1);
  and2(&S_and2_63_1);
  or2(&S_or2_60_1);
  and2(&S_and2_623_1);
  and2(&S_and2_622_1);
  or3(&S_or3_638_1);
  and2(&S_and2_302_1);
  and4(&S_and4_332_1);
  and2(&S_and2_314_1);
  or2(&S_or2_304_1);
  and2(&S_and2_309_1);
  or2(&S_or2_356_1);
  and2(&S_and2_347_1);
  or5(&S_or5_550_1);
  and2(&S_and2_260_1);
  and2(&S_and2_261_1);
  or3(&S_or3_275_1);
  and2(&S_and2_972_1);
  and2(&S_and2_971_1);
  or3(&S_or3_981_1);
  and2(&S_and2_1084_1);
  and2(&S_and2_1083_1);
  and2(&S_and2_1534_1);
  and2(&S_and2_1535_1);
  and2(&S_and2_1427_1);
  and2(&S_and2_1428_1);
  or3(&S_or3_1437_1);
  or2(&S_or2_1557_1);
  or3(&S_or3_1588_1);
  or3(&S_or3_1627_1);
  or3(&S_or3_1643_1);
  or3(&S_or3_2062_1);
  or3(&S_or3_2024_1);
  or4(&S_or4_1550_1);
  or4(&S_or4_1098_1);
  ovbsb(&S_ovbsb_265_1);
  ovbsb(&S_ovbsb_266_1);
  ovbsb(&S_ovbsb_1431_1);
  ovbsb(&S_ovbsb_1432_1);
  ovbsb(&S_ovbsb_1088_1);
  ovbsb(&S_ovbsb_1089_1);
  ovbsb(&S_ovbsb_628_1);
  ovbsb(&S_ovbsb_629_1);
  ovbsb(&S_ovbsb_978_1);
  ovbsb(&S_ovbsb_975_1);
  ovbsb(&S_ovbsb_1539_1);
  ovbsb(&S_ovbsb_1540_1);
  cnshd(&S_cnshd_539_1);
  maz(&S_maz_313_1);
  maz(&S_maz_322_1);
  orni(&S_orni_1311_1);
  orni(&S_orni_303_1);
  rs(&S_rs_355_1);
  decatron(&S_decatron_311_1);
  orni(&S_orni_349_1);
  noto(&S_noto_325_1);
  swtakt(&S_swtakt_2028_1);
  swtakt(&S_swtakt_2063_1);
  swtakt(&S_swtakt_1633_1);
  swtakt(&S_swtakt_1637_1);
  swtakt(&S_swtakt_1593_1);
  or2(&S_or2_308_1);
  or2(&S_or2_317_1);
  or2(&S_or2_331_1);
  or2(&S_or2_330_1);
  and2(&S_and2_334_1);
  and2(&S_and2_329_1);
  and2(&S_and2_336_1);
  and2(&S_and2_335_1);
  and3(&S_and3_315_1);
  or5(&S_or5_181_1);
  and2(&S_and2_1558_1);
  or2(&S_or2_2233_1);
  or2(&S_or2_2215_1);
  or3(&S_or3_1552_1);
  or3(&S_or3_1101_1);
  zpfs(&S_zpfs_328_1);
  cnshd(&S_cnshd_169_1);
  newstage(&S_newstage_204_1);
  equz_p(&S_equz_p_316_1);
  noto(&S_noto_1564_1);
  cntch(&S_cntch_306_1);
  rs(&S_rs_307_1);
  cntch(&S_cntch_353_1);
  and2(&S_and2_321_1);
  or5(&S_or5_1581_1);
  or5(&S_or5_1559_1);
  and2(&S_and2_1561_1);
  or2(&S_or2_1562_1);
  and4(&S_and4_2106_1);
  and3(&S_and3_2107_1);
  and3(&S_and3_2108_1);
  and2(&S_and2_2069_1);
  and2(&S_and2_2023_1);
  or3(&S_or3_2037_1);
  and2(&S_and2_191_1);
  and2(&S_and2_189_1);
  rs(&S_rs_2071_1);
  rs(&S_rs_2029_1);
  rs(&S_rs_2038_1);
  and2(&S_and2_1200_1);
  and2(&S_and2_341_1);
  and2(&S_and2_699_1);
  or2(&S_or2_687_1);
  and2(&S_and2_1168_1);
  or3(&S_or3_2076_1);
  rs(&S_rs_688_1);
  noto(&S_noto_342_1);
  rs(&S_rs_1157_1);
  noto(&S_noto_1158_1);
  rs(&S_rs_1192_1);
  and2(&S_and2_706_1);
  and3(&S_and3_675_1);
  and3(&S_and3_665_1);
  or3(&S_or3_897_1);
  or3(&S_or3_1333_1);
  and4(&S_and4_1120_1);
  and4(&S_and4_1126_1);
  or2(&S_or2_1191_1);
  or4(&S_or4_982_1);
  or4(&S_or4_1438_1);
  ornc(&S_ornc_992_1);
  charint(&S_charint_986_1);
  ornc(&S_ornc_1448_1);
  charint(&S_charint_1442_1);
  fsumz(&S_fsumz_987_1);
  fsumz(&S_fsumz_1443_1);
  ma(&S_ma_1449_1);
  ma(&S_ma_993_1);
  fnapb(&S_fnapb_1024_1);
  zpfs(&S_zpfs_1016_1);
  zpfs(&S_zpfs_1017_1);
  fnapb(&S_fnapb_1476_1);
  zpfs(&S_zpfs_1468_1);
  zpfs(&S_zpfs_1467_1);
  zpfs(&S_zpfs_1041_1);
  zpfs(&S_zpfs_1492_1);
  and2(&S_and2_1464_1);
  and2(&S_and2_1010_1);
  ovbsb(&S_ovbsb_1035_1);
  ovbsb(&S_ovbsb_1018_1);
  ovbsb(&S_ovbsb_1028_1);
  ovbsb(&S_ovbsb_1029_1);
  ovbsb(&S_ovbsb_1486_1);
  ovbsb(&S_ovbsb_1482_1);
  ovbsb(&S_ovbsb_1473_1);
  ovbsb(&S_ovbsb_1474_1);
  or5(&S_or5_1009_1);
  or5(&S_or5_1463_1);
  or2(&S_or2_2421_1);
  cnshd(&S_cnshd_994_1);
  cnshd(&S_cnshd_1450_1);
  noto(&S_noto_2420_1);
  newstage(&S_newstage_1006_1);
  and2(&S_and2_1012_1);
  and2(&S_and2_1015_1);
  andn(&S_andn_2394_1);
  noto(&S_noto_2416_1);
  and2(&S_and2_2417_1);
  or2(&S_or2_2415_1);
  and3(&S_and3_2373_1);
  and2(&S_and2_2232_1);
  and2(&S_and2_2224_1);
  or3(&S_or3_2222_1);
  or3(&S_or3_2237_1);
  ovbsb(&S_ovbsb_2231_1);
  ovbsb(&S_ovbsb_2223_1);
  ovbsb(&S_ovbsb_2145_1);
  rs(&S_rs_2216_1);
  noto(&S_noto_2217_1);
  rs(&S_rs_2234_1);
  noto(&S_noto_2235_1);
  and2(&S_and2_1201_1);
  and2(&S_and2_698_1);
  and2(&S_and2_1176_1);
  rs(&S_rs_2414_1);
  rs(&S_rs_1169_1);
  noto(&S_noto_1172_1);
  rs(&S_rs_1195_1);
  and3(&S_and3_1164_1);
  and2(&S_and2_1111_1);
  and4(&S_and4_1118_1);
  and4(&S_and4_1124_1);
  or2(&S_or2_1194_1);
  orn(&S_orn_1326_1);
  orn(&S_orn_887_1);
  ornc(&S_ornc_1334_1);
  charint(&S_charint_1327_1);
  ornc(&S_ornc_894_1);
  charint(&S_charint_888_1);
  rs(&S_rs_1105_1);
  or3(&S_or3_476_1);
  and3(&S_and3_485_1);
  and2(&S_and2_1151_1);
  and2(&S_and2_521_1);
  and2(&S_and2_487_1);
  fsumz(&S_fsumz_1328_1);
  fsumz(&S_fsumz_889_1);
  samhd(&S_samhd_500_1);
  samhd(&S_samhd_506_1);
  newstage(&S_newstage_502_1);
  ma(&S_ma_895_1);
  ma(&S_ma_1335_1);
  or4(&S_or4_496_1);
  or4(&S_or4_515_1);
  andn(&S_andn_1_1);
  and2(&S_and2_511_1);
  and2(&S_and2_508_1);
  ovbsb(&S_ovbsb_492_1);
  ovbsb(&S_ovbsb_489_1);
  ovbsb(&S_ovbsb_490_1);
  ovbsb(&S_ovbsb_491_1);
  ovbsb(&S_ovbsb_514_1);
  ovbsb(&S_ovbsb_518_1);
  ovbsb(&S_ovbsb_519_1);
  ovbsb(&S_ovbsb_520_1);
  fnapb(&S_fnapb_1372_1);
  zpfs(&S_zpfs_1365_1);
  zpfs(&S_zpfs_1366_1);
  fnapb(&S_fnapb_916_1);
  zpfs(&S_zpfs_1382_1);
  and2(&S_and2_1202_1);
  and2(&S_and2_714_1);
  zpfs(&S_zpfs_928_1);
  zpfs(&S_zpfs_910_1);
  zpfs(&S_zpfs_911_1);
  or5(&S_or5_1349_1);
  and2(&S_and2_1183_1);
  or5(&S_or5_2153_1);
  ovbsb(&S_ovbsb_914_1);
  ovbsb(&S_ovbsb_913_1);
  ovbsb(&S_ovbsb_923_1);
  ovbsb(&S_ovbsb_918_1);
  ovbsb(&S_ovbsb_1378_1);
  ovbsb(&S_ovbsb_1362_1);
  ovbsb(&S_ovbsb_1357_1);
  ovbsb(&S_ovbsb_1375_1);
  orni(&S_orni_133_1);
  orn(&S_orn_448_1);
  orn(&S_orn_470_1);
  cnshd(&S_cnshd_1337_1);
  rs(&S_rs_1178_1);
  rs(&S_rs_1198_1);
  or2(&S_or2_450_1);
  or2(&S_or2_472_1);
  and2(&S_and2_746_1);
  or2(&S_or2_1282_1);
  or2(&S_or2_1283_1);
  and2(&S_and2_1219_1);
  or5(&S_or5_907_1);
  and2(&S_and2_1736_1);
  or4(&S_or4_1732_1);
  or4(&S_or4_2154_1);
  ovbsb(&S_ovbsb_1745_1);
  ovbsb(&S_ovbsb_1228_1);
  ovbsb(&S_ovbsb_755_1);
  orn(&S_orn_843_1);
  orn(&S_orn_1203_1);
  cnshd(&S_cnshd_898_1);
  or2(&S_or2_833_1);
  or2(&S_or2_834_1);
  or4(&S_or4_814_1);
  or5(&S_or5_1250_1);
  or2(&S_or2_376_1);
  or2(&S_or2_380_1);
  ovbs(&S_ovbs_2160_1);
  noto(&S_noto_2161_1);
  and2(&S_and2_2167_1);
  and2(&S_and2_2179_1);
  or3(&S_or3_2155_1);
  and2(&S_and2_2156_1);
  or3(&S_or3_2169_1);
  and2(&S_and2_2170_1);
  or5(&S_or5_1719_1);
  or2(&S_or2_2405_1);
  rs(&S_rs_813_1);
  samhd(&S_samhd_379_1);
  newstage(&S_newstage_1379_1);
  and2(&S_and2_801_1);
  or2(&S_or2_805_1);
  or4(&S_or4_378_1);
  or5(&S_or5_1765_1);
  or2(&S_or2_2174_1);
  or2(&S_or2_2162_1);
  ovbs(&S_ovbs_2157_1);
  ovbs(&S_ovbs_2171_1);
  rs(&S_rs_2191_1);
  rs(&S_rs_2199_1);
  noto(&S_noto_2189_1);
  noto(&S_noto_2210_1);
  and2(&S_and2_1361_1);
  and2(&S_and2_1364_1);
  zpfs(&S_zpfs_2192_1);
  zpfs(&S_zpfs_2200_1);
  noto(&S_noto_2401_1);
  or3(&S_or3_1838_1);
  or3(&S_or3_1830_1);
  or2(&S_or2_1844_1);
  or2(&S_or2_1836_1);
  ovbsb(&S_ovbsb_385_1);
  ovbsb(&S_ovbsb_386_1);
  ovbsb(&S_ovbsb_387_1);
  rs(&S_rs_807_1);
  rs(&S_rs_1829_1);
  rs(&S_rs_1837_1);
  or2(&S_or2_2193_1);
  noto(&S_noto_2158_1);
  noto(&S_noto_2172_1);
  rs(&S_rs_2175_1);
  noto(&S_noto_2176_1);
  rs(&S_rs_2163_1);
  or2(&S_or2_2201_1);
  noto(&S_noto_2194_1);
  and2(&S_and2_2195_1);
  and2(&S_and2_2190_1);
  noto(&S_noto_2202_1);
  and2(&S_and2_1822_1);
  and2(&S_and2_1826_1);
  noto(&S_noto_2182_1);
  ovbsb(&S_ovbsb_2181_1);
  rs(&S_rs_1831_1);
  rs(&S_rs_1839_1);
  noto(&S_noto_2164_1);
  and2(&S_and2_2203_1);
  and4(&S_and4_2184_1);
  ovbs(&S_ovbs_2185_1);
  and2(&S_and2_2211_1);
  noto(&S_noto_2213_1);
  or2(&S_or2_2186_1);
  ovbsb(&S_ovbsb_2214_1);
  orn(&S_orn_658_1);
  orn(&S_orn_657_1);
  noto(&S_noto_2187_1);
  and4(&S_and4_2205_1);
  ovbs(&S_ovbs_2206_1);
  or2(&S_or2_2207_1);
  newstage(&S_newstage_660_1);
  or2(&S_or2_694_1);
  ovbs(&S_ovbs_2196_1);
  noto(&S_noto_2208_1);
  and2(&S_and2_693_1);
  setData(idB3CV01RDU,&var1522);
  setData(idR0DE3CLDU,&var215);
  setData(idR0DE3DLDU,&var214);
  setData(idTTLDU,&var218);
  setData(idB3AB13LDU,&var75);
  setData(idA3AB13LDU,&var161);
  setData(idR3VS01IDU,&var347);
  setData(idR3VS12LDU,&var345);
  setData(idR3VS22LDU,&var346);
  setData(idR5VS01IDU,&var344);
  setData(idR5VS12LDU,&var342);
  setData(idR5VS22LDU,&var343);
  setData(idB3AB15LDU,&var77);
  setData(idB3EE03LDU,&var1019);
  setData(idA3EE03LDU,&var1020);
  setData(idB3AB19LDU,&var76);
  setData(idA3AB19LDU,&var155);
  setData(idR0VL23LDU,&var1255);
  setData(idR0VL22LDU,&var1277);
  setData(idR0AD05LZ2,&var283);
  setData(idR0AD05LZ1,&var283);
  setData(idR0AD04LZ2,&var579);
  setData(idR0AD04LZ1,&var579);
  setData(idR0AD03LZ2,&var282);
  setData(idR0AD03LZ1,&var282);
  setData(idR0CN95LDU,&var427);
  setData(idR0CN94LDU,&var426);
  setData(idR0CN93LDU,&var425);
  setData(idR0AB19LDU,&var31);
  setData(idR0VN12RDU,&var1188);
  setData(idR0VN11RDU,&var1186);
  setData(idR0CN92LDU,&var392);
  setData(idR0AB20LDU,&var30);
  setData(idA3AB15LDU,&var159);
  setData(idA3MC03RDU,&var423);
  setData(idR0CN91LDU,&var422);
  setData(idA3MC02RDU,&var421);
  setData(idA3MC01RDU,&var420);
  setData(idR0AB18LDU,&var32);
  setData(idR0AB17LDU,&var33);
  setData(idR0AB16LDU,&var34);
  setData(idB1AB19LDU,&var106);
  setData(idA3ZAV,&var1527);
  setData(idA1ZAV,&var1590);
  setData(idB3IS12LDU,&var444);
  setData(idA3IS12LDU,&var445);
  setData(idR0AB15LDU,&var450);
  setData(idR0AB14LDU,&var448);
  setData(idA4DW,&var1365);
  setData(idA4UP,&var1366);
  setData(idR4ABL,&var1829);
  setData(idA9ZAV,&var1465);
  setData(idA8ZAV,&var1666);
  setData(idA2ZAV,&var1671);
  setData(idB8ZAV,&var1676);
  setData(idA5ZAV,&var1744);
  setData(idR2ZAV,&var1620);
  setData(idA6ZAV,&var1746);
  setData(idA4ZAV,&var1745);
  setData(idR0AB13LDU,&var517);
  setData(idR0AB12LDU,&var521);
  setData(idR0AB11LDU,&var525);
  setData(idR0AB10LDU,&var529);
  setData(idR0AB09LDU,&var533);
  setData(idR0AB08LDU,&var35);
  setData(idB6AB05LDU,&var58);
  setData(idR0VS11LDU,&var1887);
  setData(idA8VS01IDU,&var1670);
  setData(idB8VS01IDU,&var1680);
  setData(idR2AD10LDU,&var1625);
  setData(idR2AD20LDU,&var1626);
  setData(idB6VS01IDU,&var1817);
  setData(idR0AD16LDU,&lRM_0_);
  setData(idR0AB07LDU,&var36);
  setData(idR0EE03LDU,&var604);
  setData(idR0VX02LDU,&var1025);
  setData(idR0AD21LDU,&var1023);
  setData(idB2AB15LDU,&var92);
  setData(idA2AB15LDU,&var176);
  setData(idR0AB05LDU,&var1337);
  setData(idR0AB03LDU,&var1348);
  setData(idA1AB19LDU,&var187);
  setData(idR0VZ71LDU,&var269);
  setData(idR0VL01RDU,&var1383);
  setData(idB7AZ03LDU,&var1);
  setData(idA7AZ03LDU,&var2);
  setData(idB2VS01IDU,&var1658);
  setData(idB2VS21LDU,&var1660);
  setData(idB2VS11LDU,&var1659);
  setData(idR0VP73LDU,&var700);
  setData(idR0VS18LDU,&var777);
  setData(idB3VX01LDU,&var647);
  setData(idA3VX01LDU,&var648);
  setData(idB2VS32LDU,&var563);
  setData(idA2VS32LDU,&var564);
  setData(idR0VS17LDU,&var767);
  setData(idR0VX09LDU,&var380);
  moveData(idR0VX08IDU,idR0MW12IP1);
  setData(idR0VW23LDU,&var1120);
  setData(idR0VW13LDU,&var1119);
  setData(idB7AP31LDU,&var1368);
  setData(idA7AP31LDU,&var1369);
  setData(idB3AD31LDU,&var1428);
  setData(idB3AD34LDU,&var1429);
  setData(idA3AD31LDU,&var1434);
  setData(idA3AD34LDU,&var1431);
  setData(idA3AD33LDU,&var1433);
  setData(idB2AD33LDU,&var542);
  setData(idA2AD33LDU,&var545);
  setData(idR0AB01LDU,&var1457);
  setData(idB9AB02LDU,&var37);
  setData(idB9AB01LDU,&var38);
  setData(idB9AZ03LDU,&var39);
  setData(idA9AB02LDU,&var123);
  setData(idA9AB01LDU,&var122);
  setData(idA9AZ03LDU,&var121);
  setData(idA9AD10LDU,&var1475);
  setData(idB9AD10LDU,&var1469);
  setData(idR1VS01IDU,&var1636);
  setData(idR2VS01IDU,&var1627);
  setData(idR4VS01IDU,&var1808);
  setData(idA6VS01IDU,&var1826);
  setData(idB5VS01IDU,&var1790);
  setData(idA5VS01IDU,&var1799);
  setData(idB4VS22LDU,&var1771);
  setData(idB4VS12LDU,&var1770);
  setData(idB4VS01IDU,&var1772);
  setData(idA4VS22LDU,&var1780);
  setData(idA4VS12LDU,&var1779);
  setData(idA4VS01IDU,&var1781);
  setData(idA2VS01IDU,&var1699);
  setData(idB3VS01IDU,&var1517);
  setData(idA3VS01IDU,&var1549);
  setData(idB1VS01IDU,&var1578);
  setData(idA1VS01IDU,&var1611);
  setData(idR0VS21IDU,&var1358);
  setData(idR0VX03LDU,&var970);
  setData(idR0VL21IDU,&var1268);
  setData(idR0VL05RDU,&var634);
  setData(idR0VL03RDU,&var640);
  setData(idR0AB02LDU,&var1331);
  setData(idR0AB06LDU,&var1334);
  setData(idR0AB04LDU,&var1342);
  setData(idR0VL04RDU,&var637);
  setData(idR0AD14LDU,&var579);
  setData(idR8AD21LDU,&var602);
  setData(idR0VL02RDU,&var631);
  setData(idB3AD33LDU,&var1427);
  setData(idR0VL06RDU,&var644);
  setData(idR0VL11IDU,&var1481);
  setData(idR0VL01IDU,&var1482);
  setData(idR0VX01LDU,&var1027);
  setData(idB1AD32LDU,&var1435);
  setData(idA1AD32LDU,&var1437);
  setData(idB2AD32LDU,&var570);
  setData(idA2AD32LDU,&var572);
  setData(idB1AD31LDU,&var1438);
  setData(idA1AD31LDU,&var1439);
  setData(idB2AD31LDU,&var573);
  setData(idA2AD31LDU,&var574);
  setData(idB3AB20LDU,&var70);
  setData(idB3AB18LDU,&var73);
  setData(idB3AB17LDU,&var71);
  setData(idB3AB16LDU,&var72);
  setData(idB3AB14LDU,&var74);
  setData(idB3AB12LDU,&var78);
  setData(idB3AB11LDU,&var79);
  setData(idB3AB10LDU,&var80);
  setData(idB3AB09LDU,&var81);
  setData(idB3AB06LDU,&var84);
  setData(idB3AB05LDU,&var85);
  setData(idB3AB08LDU,&var82);
  setData(idB3AB07LDU,&var83);
  setData(idB3CV02RDU,&var1516);
  setData(idB3AD01LDU,&var1509);
  setData(idB3AD05LDU,&var1515);
  setData(idB3AD04LDU,&var1514);
  setData(idB3AD03LDU,&var1513);
  setData(idB3AD02LDU,&var1512);
  setData(idB3AD21LDU,&var1510);
  setData(idB3AD11LDU,&var1511);
  setData(idB3AZ03LDU,&var89);
  setData(idB3VS22LDU,&var1520);
  setData(idB3AB01LDU,&var87);
  setData(idB3AB02LDU,&var86);
  setData(idB3AB04LDU,&var88);
  setData(idB3VS12LDU,&var1521);
  setData(idA3AB20LDU,&var154);
  setData(idA3AB18LDU,&var156);
  setData(idA3AB17LDU,&var157);
  setData(idA3AB16LDU,&var158);
  setData(idA3AB14LDU,&var160);
  setData(idA3AB12LDU,&var162);
  setData(idA3AB11LDU,&var163);
  setData(idA3AB10LDU,&var164);
  setData(idA3AB09LDU,&var165);
  setData(idA3AB06LDU,&var167);
  setData(idA3AB05LDU,&var169);
  setData(idA3AB08LDU,&var166);
  setData(idA3AB07LDU,&var168);
  setData(idA3CV02RDU,&var1548);
  setData(idA3AD01LDU,&var1541);
  setData(idA3AD05LDU,&var1547);
  setData(idA3AD04LDU,&var1546);
  setData(idA3AD03LDU,&var1545);
  setData(idA3AD02LDU,&var1544);
  setData(idA3AD21LDU,&var1542);
  setData(idA3AD11LDU,&var1543);
  setData(idA3AZ03LDU,&var173);
  setData(idA3VS22LDU,&var1552);
  setData(idA3AB01LDU,&var170);
  setData(idA3AB02LDU,&var171);
  setData(idA3AB04LDU,&var172);
  setData(idA3CV01RDU,&var1554);
  setData(idA3VS12LDU,&var1553);
  setData(idB1AB18LDU,&var103);
  setData(idB1AB17LDU,&var104);
  setData(idB1AB16LDU,&var105);
  setData(idB1AB14LDU,&var107);
  setData(idB1AB13LDU,&var108);
  setData(idB1AB12LDU,&var109);
  setData(idB1AB11LDU,&var110);
  setData(idB1AB10LDU,&var111);
  setData(idB1AB09LDU,&var112);
  setData(idB1AB06LDU,&var114);
  setData(idB1AB05LDU,&var116);
  setData(idB1AB08LDU,&var113);
  setData(idB1AB07LDU,&var115);
  setData(idB1CV02RDU,&var1577);
  setData(idB1AD01LDU,&var1570);
  setData(idB1AD05LDU,&var1576);
  setData(idB1AD04LDU,&var1575);
  setData(idB1AD03LDU,&var1574);
  setData(idB1AD02LDU,&var1573);
  setData(idB1AD21LDU,&var1572);
  setData(idB1AD11LDU,&var1571);
  setData(idB1AZ03LDU,&var120);
  setData(idB1VS22LDU,&var1582);
  setData(idB1AB01LDU,&var117);
  setData(idB1AB02LDU,&var118);
  setData(idB1AB04LDU,&var119);
  setData(idB1CV01RDU,&var1583);
  setData(idB1VS12LDU,&var1581);
  setData(idA1AB18LDU,&var188);
  setData(idA1AB17LDU,&var189);
  setData(idA1AB16LDU,&var190);
  setData(idA1AB14LDU,&var191);
  setData(idA1AB13LDU,&var192);
  setData(idA1AB12LDU,&var193);
  setData(idA1AB11LDU,&var194);
  setData(idA1AB10LDU,&var195);
  setData(idA1AB09LDU,&var196);
  setData(idA1AB06LDU,&var199);
  setData(idA1AB05LDU,&var200);
  setData(idA1AB08LDU,&var197);
  setData(idA1AB07LDU,&var198);
  setData(idA1CV02RDU,&var1610);
  setData(idA1AD01LDU,&var1603);
  setData(idA1AD05LDU,&var1609);
  setData(idA1AD04LDU,&var1608);
  setData(idA1AD03LDU,&var1607);
  setData(idA1AD02LDU,&var1606);
  setData(idA1AD21LDU,&var1605);
  setData(idA1AD11LDU,&var1604);
  setData(idA1AZ03LDU,&var204);
  setData(idA1VS22LDU,&var1613);
  setData(idA1AB01LDU,&var203);
  setData(idA1AB02LDU,&var202);
  setData(idA1AB04LDU,&var201);
  setData(idA1CV01RDU,&var1614);
  setData(idA1VS12LDU,&var1612);
  setData(idR1AD20LDU,&var1635);
  setData(idR1AD10LDU,&var1634);
  setData(idR2AB04LDU,&var22);
  setData(idR1AB04LDU,&var26);
  setData(idR2AB02LDU,&var23);
  setData(idR2AB01LDU,&var24);
  setData(idR2AZ03LDU,&var25);
  setData(idR1AB02LDU,&var27);
  setData(idR1AB01LDU,&var28);
  setData(idR1AZ03LDU,&var29);
  setData(idB2AB17LDU,&var90);
  setData(idB2AB16LDU,&var91);
  setData(idB2AB14LDU,&var93);
  setData(idB2AB13LDU,&var94);
  setData(idB2AB12LDU,&var95);
  setData(idB2AB11LDU,&var96);
  setData(idB2AB10LDU,&var97);
  setData(idB2AB09LDU,&var98);
  setData(idB2AB06LDU,&var101);
  setData(idB2AB05LDU,&var102);
  setData(idB2AB08LDU,&var99);
  setData(idB2AB07LDU,&var100);
  setData(idB2CV02RDU,&var1657);
  setData(idB2AD01LDU,&var1650);
  setData(idB2AD05LDU,&var1656);
  setData(idB2AD04LDU,&var1655);
  setData(idB2AD03LDU,&var1654);
  setData(idB2AD02LDU,&var1653);
  setData(idB2AD21LDU,&var1652);
  setData(idB2AD11LDU,&var1651);
  setData(idB2AZ03LDU,&var210);
  setData(idB2AB01LDU,&var211);
  setData(idB2AB02LDU,&var212);
  setData(idB2AB04LDU,&var209);
  setData(idB2CV01RDU,&var1661);
  setData(idA2CV02RDU,&var1698);
  setData(idA2AD01LDU,&var1691);
  setData(idA2AB17LDU,&var174);
  setData(idA2AB16LDU,&var175);
  setData(idA2AB14LDU,&var177);
  setData(idA2AB13LDU,&var178);
  setData(idA2AB12LDU,&var179);
  setData(idA2AB11LDU,&var180);
  setData(idA2AB10LDU,&var181);
  setData(idA2AB09LDU,&var182);
  setData(idA2AB06LDU,&var184);
  setData(idA2AB05LDU,&var186);
  setData(idA2AB08LDU,&var183);
  setData(idA2AB07LDU,&var185);
  setData(idA2AD05LDU,&var1697);
  setData(idA2AD04LDU,&var1696);
  setData(idA2AD03LDU,&var1695);
  setData(idA2AD02LDU,&var1694);
  setData(idA2AD21LDU,&var1693);
  setData(idA2AD11LDU,&var1692);
  setData(idA2AZ03LDU,&var208);
  setData(idA2VS21LDU,&var1703);
  setData(idA2AB01LDU,&var207);
  setData(idA2AB02LDU,&var206);
  setData(idA2AB04LDU,&var205);
  setData(idA2CV01RDU,&var1704);
  setData(idA2VS11LDU,&var1702);
  setData(idA8AB01LDU,&var137);
  setData(idA8AB02LDU,&var136);
  setData(idA8AB14LDU,&var124);
  setData(idA8AB13LDU,&var125);
  setData(idA8AB12LDU,&var126);
  setData(idA8AB11LDU,&var127);
  setData(idA8AB10LDU,&var128);
  setData(idA8AB09LDU,&var129);
  setData(idA8AB08LDU,&var130);
  setData(idA8AB04LDU,&var135);
  setData(idA8AD20LDU,&var1669);
  setData(idA8AD10LDU,&var1668);
  setData(idA8AZ03LDU,&var134);
  setData(idA8VS22LDU,&var1716);
  setData(idA8AB05LDU,&var131);
  setData(idA8AB07LDU,&var132);
  setData(idA8AB06LDU,&var133);
  setData(idA8CV01RDU,&var1717);
  setData(idA8VS12LDU,&var1715);
  setData(idB8AB02LDU,&var51);
  setData(idB8AB14LDU,&var40);
  setData(idB8AB13LDU,&var41);
  setData(idB8AB12LDU,&var42);
  setData(idB8AB11LDU,&var43);
  setData(idB8AB10LDU,&var44);
  setData(idB8AB09LDU,&var45);
  setData(idB8AB08LDU,&var46);
  setData(idB8AB04LDU,&var52);
  setData(idB8AB01LDU,&var53);
  setData(idB8AD20LDU,&var1679);
  setData(idB8AD10LDU,&var1678);
  setData(idB8AZ03LDU,&var50);
  setData(idB8VS22LDU,&var1733);
  setData(idB8AB05LDU,&var47);
  setData(idB8AB07LDU,&var48);
  setData(idB8AB06LDU,&var49);
  setData(idB8CV01RDU,&var1734);
  setData(idB8VS12LDU,&var1732);
  setData(idA6AB05LDU,&var142);
  setData(idB6AB09LDU,&var54);
  setData(idB6AB08LDU,&var55);
  setData(idB6AB07LDU,&var56);
  setData(idB6AB06LDU,&var57);
  setData(idA6AB09LDU,&var138);
  setData(idA6AB08LDU,&var139);
  setData(idA6AB07LDU,&var140);
  setData(idA6AB06LDU,&var141);
  setData(idB5AB04LDU,&var63);
  setData(idA5AB04LDU,&var148);
  setData(idB4AB02LDU,&var67);
  setData(idB4AB01LDU,&var68);
  setData(idB4AZ03LDU,&var69);
  setData(idA4AB02LDU,&var152);
  setData(idA4AB01LDU,&var153);
  setData(idA4AZ03LDU,&var151);
  setData(idA4AD10LDU,&var1778);
  setData(idB4AD10LDU,&var1769);
  setData(idB5AB02LDU,&var64);
  setData(idB5AB01LDU,&var65);
  setData(idB5AZ03LDU,&var66);
  setData(idA5AB02LDU,&var149);
  setData(idA5AB01LDU,&var150);
  setData(idA5AZ03LDU,&var147);
  setData(idA5AD20LDU,&var1798);
  setData(idA5AD10LDU,&var1797);
  setData(idB5AD20LDU,&var1789);
  setData(idB5AD10LDU,&var1788);
  setData(idR4AD20LDU,&var1807);
  setData(idR4AD10LDU,&var1806);
  setData(idR4AB18LDU,&var3);
  setData(idR4AB17LDU,&var4);
  setData(idR4AB16LDU,&var5);
  setData(idR4AB15LDU,&var6);
  setData(idR4AB14LDU,&var7);
  setData(idR4AB13LDU,&var8);
  setData(idR4AB12LDU,&var9);
  setData(idR4AB11LDU,&var21);
  setData(idR4AB10LDU,&var10);
  setData(idR4AB09LDU,&var11);
  setData(idR4AB08LDU,&var12);
  setData(idR4AB07LDU,&var13);
  setData(idR4AB06LDU,&var14);
  setData(idR4AB05LDU,&var15);
  setData(idR4AB04LDU,&var16);
  setData(idR4AB03LDU,&var18);
  setData(idR4AZ03LDU,&var17);
  setData(idR4AB02LDU,&var19);
  setData(idR4AB01LDU,&var20);
  setData(idB6AB04LDU,&var59);
  setData(idA6AB04LDU,&var144);
  setData(idB6AB02LDU,&var61);
  setData(idB6AB01LDU,&var60);
  setData(idB6AZ03LDU,&var62);
  setData(idA6AB02LDU,&var145);
  setData(idA6AB01LDU,&var146);
  setData(idA6AZ03LDU,&var143);
  setData(idB6AD20LDU,&var1816);
  setData(idB6AD10LDU,&var1815);
  setData(idA6AD20LDU,&var1825);
  setData(idA6AD10LDU,&var1824);
  setData(idR0ES01LDU,&var1109);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
  for( i=0;i<10;i++ )
    array_m345_rz_1[i] = &(&internal1_m345_rz)[i*1];
  for( i=0;i<10;i++ )
    array_m287_rz_1[i] = &(&internal1_m287_rz)[i*1];
  for( i=0;i<6;i++ )
    array_m1568_rz_1[i] = &(&internal1_m1568_rz)[i*1];
  for( i=0;i<60;i++ )
    array_m1476_x0_1[i] = &(&internal1_m1476_x0)[i*5];
  for( i=0;i<60;i++ )
    array_m1476_tim0_1[i] = &(&internal1_m1476_tim0)[i*5];
  for( i=0;i<60;i++ )
    array_m1024_x0_1[i] = &(&internal1_m1024_x0)[i*5];
  for( i=0;i<60;i++ )
    array_m1024_tim0_1[i] = &(&internal1_m1024_tim0)[i*5];
  for( i=0;i<150;i++ )
    array_m562_x0_1[i] = &(&internal1_m562_x0)[i*5];
  for( i=0;i<150;i++ )
    array_m562_tim0_1[i] = &(&internal1_m562_tim0)[i*5];
  for( i=0;i<150;i++ )
    array_m194_x0_1[i] = &(&internal1_m194_x0)[i*5];
  for( i=0;i<150;i++ )
    array_m194_tim0_1[i] = &(&internal1_m194_tim0)[i*5];
  for( i=0;i<80;i++ )
    array_m916_x0_1[i] = &(&internal1_m916_x0)[i*5];
  for( i=0;i<80;i++ )
    array_m916_tim0_1[i] = &(&internal1_m916_tim0)[i*5];
  for( i=0;i<80;i++ )
    array_m1372_x0_1[i] = &(&internal1_m1372_x0)[i*5];
  for( i=0;i<80;i++ )
    array_m1372_tim0_1[i] = &(&internal1_m1372_tim0)[i*5];
  for( i=0;i<20;i++ )
    array_m1779_x0_1[i] = &(&internal1_m1779_x0)[i*5];
  for( i=0;i<20;i++ )
    array_m1779_tim0_1[i] = &(&internal1_m1779_tim0)[i*5];
  for( i=0;i<20;i++ )
    array_m1267_x0_1[i] = &(&internal1_m1267_x0)[i*5];
  for( i=0;i<20;i++ )
    array_m1267_tim0_1[i] = &(&internal1_m1267_tim0)[i*5];
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
