#ifndef DU_H
#define DU_H
// Подсистема DU:DU
static char SimulOn=0;
static short CodeSub=2;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt, taktScheme=0, taktSS=0;
#define SIZE_BUFFER 12012
static char BUFFER[12012];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.50\0", 5432, "192.168.10.150\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R6IS32LDU	 BUFFER[0]	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
#define idR6IS32LDU	 1	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
#define R6IS42LDU	 BUFFER[2]	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
#define idR6IS42LDU	 2	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
#define R6IS41LDU	 BUFFER[4]	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
#define idR6IS41LDU	 3	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
#define R6IS52LDU	 BUFFER[6]	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
#define idR6IS52LDU	 4	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
#define R6IS51LDU	 BUFFER[8]	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
#define idR6IS51LDU	 5	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
#define R3IS11LDU	 BUFFER[10]	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
#define idR3IS11LDU	 6	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
#define R3IS21LDU	 BUFFER[12]	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
#define idR3IS21LDU	 7	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
#define R0AB03LDU	 BUFFER[14]	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
#define idR0AB03LDU	 8	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
#define R0AB05LDU	 BUFFER[16]	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
#define idR0AB05LDU	 9	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
#define R0VN11RZ1	 BUFFER[18]	//( - , MDuBz1) Средняя мощность по BAZ1
#define idR0VN11RZ1	 10	//( - , MDuBz1) Средняя мощность по BAZ1
#define R0VN11RZ2	 BUFFER[23]	//( - , MDuBz2) Средняя мощность по BAZ2
#define idR0VN11RZ2	 11	//( - , MDuBz2) Средняя мощность по BAZ2
#define A2AB15LDU	 BUFFER[28]	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define idA2AB15LDU	 12	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define B2AB15LDU	 BUFFER[30]	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define idB2AB15LDU	 13	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define R0AD21LDU	 BUFFER[32]	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
#define idR0AD21LDU	 14	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
#define R0VX02LDU	 BUFFER[34]	//( - , DU) Импульс разрешен
#define idR0VX02LDU	 15	//( - , DU) Импульс разрешен
#define R0EE03LDU	 BUFFER[36]	//( - , DU) ВПИС ИС
#define idR0EE03LDU	 16	//( - , DU) ВПИС ИС
#define R0AB07LDU	 BUFFER[38]	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
#define idR0AB07LDU	 17	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
#define R0AD16LDU	 BUFFER[40]	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
#define idR0AD16LDU	 18	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
#define C2MD31LP1	 BUFFER[42]	//( - , DU) Кнопка СБРОС РБ
#define idC2MD31LP1	 19	//( - , DU) Кнопка СБРОС РБ
#define B6VS01IDU	 BUFFER[44]	//( - , DU) Готовность к управлению БЗ2
#define idB6VS01IDU	 20	//( - , DU) Готовность к управлению БЗ2
#define R2AD20LDU	 BUFFER[47]	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
#define idR2AD20LDU	 21	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
#define R2AD10LDU	 BUFFER[49]	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
#define idR2AD10LDU	 22	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
#define B8VS01IDU	 BUFFER[51]	//( - , DU) Готовность к управлению АЗ2
#define idB8VS01IDU	 23	//( - , DU) Готовность к управлению АЗ2
#define R0VZ71LZ2	 BUFFER[54]	//(vds32:03 - K22VDSR, - ) Обобщенный сигнал АЗ 2 канала
#define idR0VZ71LZ2	 24	//(vds32:03 - K22VDSR, - ) Обобщенный сигнал АЗ 2 канала
#define R0VZ71LZ1	 BUFFER[56]	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
#define idR0VZ71LZ1	 25	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
#define R0VZ71LDU	 BUFFER[58]	//( - , DU) Обобщенный сигнал АЗ
#define idR0VZ71LDU	 26	//( - , DU) Обобщенный сигнал АЗ
#define A2IS33LDU	 BUFFER[60]	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
#define idA2IS33LDU	 27	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
#define A3IS31LDU	 BUFFER[62]	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
#define idA3IS31LDU	 28	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
#define A3IS33LDU	 BUFFER[64]	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
#define idA3IS33LDU	 29	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
#define A3IS35LDU	 BUFFER[66]	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
#define idA3IS35LDU	 30	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
#define A4IS10LDU	 BUFFER[68]	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
#define idA4IS10LDU	 31	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
#define A1VN71LZ1	 BUFFER[70]	//(vds32:02 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define idA1VN71LZ1	 32	//(vds32:02 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define A1VN71LZ2	 BUFFER[72]	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define idA1VN71LZ2	 33	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define A1AB19LDU	 BUFFER[74]	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
#define idA1AB19LDU	 34	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
#define R0AD14LZ1	 BUFFER[76]	//(vds32:02 - K20VDSR, DU) Имитация срабатывания АЗ от II УР
#define idR0AD14LZ1	 35	//(vds32:02 - K20VDSR, DU) Имитация срабатывания АЗ от II УР
#define R0AD14LZ2	 BUFFER[78]	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
#define idR0AD14LZ2	 36	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
#define A3VZ13LZ2	 BUFFER[80]	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ2	 37	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define A3VZ13LZ1	 BUFFER[82]	//(vds32:02 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ1	 38	//(vds32:02 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define A3VZ15LZ1	 BUFFER[84]	//(vds32:02 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ1	 39	//(vds32:02 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define A3VZ15LZ2	 BUFFER[86]	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ2	 40	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define B2IS33LDU	 BUFFER[88]	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
#define idB2IS33LDU	 41	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
#define B3IS31LDU	 BUFFER[90]	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
#define idB3IS31LDU	 42	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
#define B3IS33LDU	 BUFFER[92]	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
#define idB3IS33LDU	 43	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
#define B3IS35LDU	 BUFFER[94]	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
#define idB3IS35LDU	 44	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
#define B4IS10LDU	 BUFFER[96]	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
#define idB4IS10LDU	 45	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
#define R6IS31LDU	 BUFFER[98]	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
#define idR6IS31LDU	 46	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
#define R0AB11LDU	 BUFFER[100]	//( - , DU) Ошибка в заданной координате  ИС1
#define idR0AB11LDU	 47	//( - , DU) Ошибка в заданной координате  ИС1
#define R0AB12LDU	 BUFFER[102]	//( - , DU) Ошибка в заданной координате  ИС2
#define idR0AB12LDU	 48	//( - , DU) Ошибка в заданной координате  ИС2
#define R0AB13LDU	 BUFFER[104]	//( - , DU) Ошибка в заданной координате  АЗ2
#define idR0AB13LDU	 49	//( - , DU) Ошибка в заданной координате  АЗ2
#define A4ZAV	 BUFFER[106]	//( - , DU) 
#define idA4ZAV	 50	//( - , DU) 
#define A6ZAV	 BUFFER[108]	//( - , DU) 
#define idA6ZAV	 51	//( - , DU) 
#define R2ZAV	 BUFFER[110]	//( - , DU) 
#define idR2ZAV	 52	//( - , DU) 
#define A5ZAV	 BUFFER[112]	//( - , DU) 
#define idA5ZAV	 53	//( - , DU) 
#define B8ZAV	 BUFFER[114]	//( - , DU) 
#define idB8ZAV	 54	//( - , DU) 
#define A2ZAV	 BUFFER[116]	//( - , DU) Завершение РБ1,2
#define idA2ZAV	 55	//( - , DU) Завершение РБ1,2
#define A8ZAV	 BUFFER[118]	//( - , DU) 
#define idA8ZAV	 56	//( - , DU) 
#define A9ZAV	 BUFFER[120]	//( - , DU) Завершение НИ ДС1(2)
#define idA9ZAV	 57	//( - , DU) Завершение НИ ДС1(2)
#define R4ABL	 BUFFER[122]	//( - , DU) Блокировка тележки -
#define idR4ABL	 58	//( - , DU) Блокировка тележки -
#define A4UP	 BUFFER[124]	//( - , DU) 
#define idA4UP	 59	//( - , DU) 
#define A4DW	 BUFFER[126]	//( - , DU) 
#define idA4DW	 60	//( - , DU) 
#define R0AB14LDU	 BUFFER[128]	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
#define idR0AB14LDU	 61	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
#define R0AB15LDU	 BUFFER[130]	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
#define idR0AB15LDU	 62	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
#define A3IS12LDU	 BUFFER[132]	//( - , DU) Приход на ВУ штока ИС1
#define idA3IS12LDU	 63	//( - , DU) Приход на ВУ штока ИС1
#define B3IS12LDU	 BUFFER[134]	//( - , DU) Приход на ВУ штока ИС2
#define idB3IS12LDU	 64	//( - , DU) Приход на ВУ штока ИС2
#define A1ZAV	 BUFFER[136]	//( - , DU) 
#define idA1ZAV	 65	//( - , DU) 
#define A3ZAV	 BUFFER[138]	//( - , DU) 
#define idA3ZAV	 66	//( - , DU) 
#define B1AB19LDU	 BUFFER[140]	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
#define idB1AB19LDU	 67	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
#define R0AB16LDU	 BUFFER[142]	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
#define idR0AB16LDU	 68	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
#define R0AB17LDU	 BUFFER[144]	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
#define idR0AB17LDU	 69	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
#define A8VS01IDU	 BUFFER[146]	//( - , DU) Готовность к управлению ДС2
#define idA8VS01IDU	 70	//( - , DU) Готовность к управлению ДС2
#define A1IE03LDU	 BUFFER[149]	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
#define idA1IE03LDU	 71	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
#define A1IE04LDU	 BUFFER[151]	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
#define idA1IE04LDU	 72	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
#define A2IE03LDU	 BUFFER[153]	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
#define idA2IE03LDU	 73	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
#define A2IE04LDU	 BUFFER[155]	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
#define idA2IE04LDU	 74	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
#define A3IE03LDU	 BUFFER[157]	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
#define idA3IE03LDU	 75	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
#define A3IE04LDU	 BUFFER[159]	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
#define idA3IE04LDU	 76	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
#define B1IE03LDU	 BUFFER[161]	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
#define idB1IE03LDU	 77	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
#define B1IE04LDU	 BUFFER[163]	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
#define idB1IE04LDU	 78	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
#define B2IE03LDU	 BUFFER[165]	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
#define idB2IE03LDU	 79	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
#define B2IE04LDU	 BUFFER[167]	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
#define idB2IE04LDU	 80	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
#define B3IE03LDU	 BUFFER[169]	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
#define idB3IE03LDU	 81	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
#define B3IE04LDU	 BUFFER[171]	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
#define idB3IE04LDU	 82	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
#define R0VS11LDU	 BUFFER[173]	//( - , DU) РУ не готова к работе
#define idR0VS11LDU	 83	//( - , DU) РУ не готова к работе
#define B6AB05LDU	 BUFFER[175]	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
#define idB6AB05LDU	 84	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
#define R0AB08LDU	 BUFFER[177]	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
#define idR0AB08LDU	 85	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
#define A1MC01RP1	 BUFFER[179]	//( - , DU) Заданная координата положения ББ1 мм
#define idA1MC01RP1	 86	//( - , DU) Заданная координата положения ББ1 мм
#define B1MC01RP1	 BUFFER[184]	//( - , DU) Заданная координата положения ББ2  мм
#define idB1MC01RP1	 87	//( - , DU) Заданная координата положения ББ2  мм
#define A3MC01RP1	 BUFFER[189]	//( - , DU) Заданная координата положения ИС1 мм
#define idA3MC01RP1	 88	//( - , DU) Заданная координата положения ИС1 мм
#define B3MC01RP1	 BUFFER[194]	//( - , DU) Заданная координата положения ИС2 мм
#define idB3MC01RP1	 89	//( - , DU) Заданная координата положения ИС2 мм
#define B8MC01RP2	 BUFFER[199]	//( - , DU) Заданная координата АЗ2 мм
#define idB8MC01RP2	 90	//( - , DU) Заданная координата АЗ2 мм
#define R0AB09LDU	 BUFFER[204]	//( - , DU) Ошибка в заданной координате ББ1
#define idR0AB09LDU	 91	//( - , DU) Ошибка в заданной координате ББ1
#define R0AB10LDU	 BUFFER[206]	//( - , DU) Ошибка в заданной координате ББ2
#define idR0AB10LDU	 92	//( - , DU) Ошибка в заданной координате ББ2
#define B9IS21LDU	 BUFFER[208]	//(vds32:02 - K26VDSR, - ) Приход на НУ НИ ДС2
#define idB9IS21LDU	 93	//(vds32:02 - K26VDSR, - ) Приход на НУ НИ ДС2
#define B9AD10LDU	 BUFFER[210]	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
#define idB9AD10LDU	 94	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
#define A9AD10LDU	 BUFFER[212]	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
#define idA9AD10LDU	 95	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
#define A9AZ03LDU	 BUFFER[214]	//( - , DU) Несанкционированное перемещение НИ ДС1
#define idA9AZ03LDU	 96	//( - , DU) Несанкционированное перемещение НИ ДС1
#define A9AB01LDU	 BUFFER[216]	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
#define idA9AB01LDU	 97	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
#define A9AB02LDU	 BUFFER[218]	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
#define idA9AB02LDU	 98	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
#define B9AZ03LDU	 BUFFER[220]	//( - , DU) Несанкционированное перемещение НИ ДС2
#define idB9AZ03LDU	 99	//( - , DU) Несанкционированное перемещение НИ ДС2
#define B9AB01LDU	 BUFFER[222]	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
#define idB9AB01LDU	 100	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
#define B9AB02LDU	 BUFFER[224]	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
#define idB9AB02LDU	 101	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
#define R0AB01LDU	 BUFFER[226]	//( - , DU) Режим проверки разрешён
#define idR0AB01LDU	 102	//( - , DU) Режим проверки разрешён
#define A3IS22LDU	 BUFFER[228]	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
#define idA3IS22LDU	 103	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
#define B3IS22LDU	 BUFFER[230]	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
#define idB3IS22LDU	 104	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
#define A2AD33LDU	 BUFFER[232]	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
#define idA2AD33LDU	 105	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
#define B2AD33LDU	 BUFFER[234]	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
#define idB2AD33LDU	 106	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
#define A3AD33LDU	 BUFFER[236]	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
#define idA3AD33LDU	 107	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
#define A3AD34LDU	 BUFFER[238]	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
#define idA3AD34LDU	 108	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
#define A3AD31LDU	 BUFFER[240]	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
#define idA3AD31LDU	 109	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
#define B3AD34LDU	 BUFFER[242]	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
#define idB3AD34LDU	 110	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
#define B3AD31LDU	 BUFFER[244]	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
#define idB3AD31LDU	 111	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
#define A2IS11LDU	 BUFFER[246]	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
#define idA2IS11LDU	 112	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
#define B2IS11LDU	 BUFFER[248]	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
#define idB2IS11LDU	 113	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
#define A3MD12LP1	 BUFFER[250]	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
#define idA3MD12LP1	 114	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
#define A3MD11LP1	 BUFFER[252]	//( - , DU) Кнопка ПУСК ИС1
#define idA3MD11LP1	 115	//( - , DU) Кнопка ПУСК ИС1
#define R0VL21IDU	 BUFFER[254]	//( - , DU) Декатрон
#define idR0VL21IDU	 116	//( - , DU) Декатрон
#define R0VX03LDU	 BUFFER[257]	//( - , DU) Готовность 2 мин
#define idR0VX03LDU	 117	//( - , DU) Готовность 2 мин
#define R0VS21IDU	 BUFFER[259]	//( - , DU) Индикация ВИД ПРОВЕРКИ
#define idR0VS21IDU	 118	//( - , DU) Индикация ВИД ПРОВЕРКИ
#define A1VS01IDU	 BUFFER[262]	//( - , DU) Готовность к управлению ББ1
#define idA1VS01IDU	 119	//( - , DU) Готовность к управлению ББ1
#define B1VS01IDU	 BUFFER[265]	//( - , DU) Готовность к управлению ББ2
#define idB1VS01IDU	 120	//( - , DU) Готовность к управлению ББ2
#define A3VS01IDU	 BUFFER[268]	//( - , DU) Готовность к управлению ИС1
#define idA3VS01IDU	 121	//( - , DU) Готовность к управлению ИС1
#define B3VS01IDU	 BUFFER[271]	//( - , DU) Готовность к управлению ИС2
#define idB3VS01IDU	 122	//( - , DU) Готовность к управлению ИС2
#define A2VS01IDU	 BUFFER[274]	//( - , DU) Готовность к управлению РБ1
#define idA2VS01IDU	 123	//( - , DU) Готовность к управлению РБ1
#define A4VS01IDU	 BUFFER[277]	//( - , DU) Готовность к управлению НИ1
#define idA4VS01IDU	 124	//( - , DU) Готовность к управлению НИ1
#define A4VS12LDU	 BUFFER[280]	//( - , DU) Движение НИ1 в сторону ВУ
#define idA4VS12LDU	 125	//( - , DU) Движение НИ1 в сторону ВУ
#define A4VS22LDU	 BUFFER[282]	//( - , DU) Движение НИ1 в сторону НУ
#define idA4VS22LDU	 126	//( - , DU) Движение НИ1 в сторону НУ
#define B4VS01IDU	 BUFFER[284]	//( - , DU) Готовность к управлению НИ2
#define idB4VS01IDU	 127	//( - , DU) Готовность к управлению НИ2
#define B4VS12LDU	 BUFFER[287]	//( - , DU) Движение НИ2 в сторону ВУ
#define idB4VS12LDU	 128	//( - , DU) Движение НИ2 в сторону ВУ
#define B4VS22LDU	 BUFFER[289]	//( - , DU) Движение НИ2 в сторону НУ
#define idB4VS22LDU	 129	//( - , DU) Движение НИ2 в сторону НУ
#define A5VS01IDU	 BUFFER[291]	//( - , DU) Готовность к управлению НЛ1
#define idA5VS01IDU	 130	//( - , DU) Готовность к управлению НЛ1
#define B5VS01IDU	 BUFFER[294]	//( - , DU) Готовность к управлению НЛ2
#define idB5VS01IDU	 131	//( - , DU) Готовность к управлению НЛ2
#define A6VS01IDU	 BUFFER[297]	//( - , DU) Готовность к управлению БЗ1
#define idA6VS01IDU	 132	//( - , DU) Готовность к управлению БЗ1
#define R4VS01IDU	 BUFFER[300]	//( - , DU) Готовность к управлению тележкой реактора
#define idR4VS01IDU	 133	//( - , DU) Готовность к управлению тележкой реактора
#define R2VS01IDU	 BUFFER[303]	//( - , DU) Готовность к управлению МДЗ2
#define idR2VS01IDU	 134	//( - , DU) Готовность к управлению МДЗ2
#define R1VS01IDU	 BUFFER[306]	//( - , DU) Готовность к управлению МДЗ1
#define idR1VS01IDU	 135	//( - , DU) Готовность к управлению МДЗ1
#define A9IS11LDU	 BUFFER[309]	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
#define idA9IS11LDU	 136	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
#define A9IS21LDU	 BUFFER[311]	//(vds32:02 - K24VDSR, - ) Приход на НУ НИ ДС1
#define idA9IS21LDU	 137	//(vds32:02 - K24VDSR, - ) Приход на НУ НИ ДС1
#define B9IS11LDU	 BUFFER[313]	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
#define idB9IS11LDU	 138	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
#define A2MD12LP1	 BUFFER[315]	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
#define idA2MD12LP1	 139	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
#define B3IS11LDU	 BUFFER[317]	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
#define idB3IS11LDU	 140	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
#define A3IS11LDU	 BUFFER[319]	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
#define idA3IS11LDU	 141	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
#define R0IS01LDU	 BUFFER[321]	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
#define idR0IS01LDU	 142	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
#define R0IS02LDU	 BUFFER[323]	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
#define idR0IS02LDU	 143	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
#define R0VP73LZ1	 BUFFER[325]	//( - , MDuBz1) ПС давления для РУ
#define idR0VP73LZ1	 144	//( - , MDuBz1) ПС давления для РУ
#define R0VP73LZ2	 BUFFER[327]	//( - , MDuBz2) ПС давления для РУ
#define idR0VP73LZ2	 145	//( - , MDuBz2) ПС давления для РУ
#define R0VP73LDU	 BUFFER[329]	//( - , DU) ПС давления для РУ
#define idR0VP73LDU	 146	//( - , DU) ПС давления для РУ
#define R0MD34LP1	 BUFFER[331]	//( - , DU) Кнопка КВИТИРОВАТЬ
#define idR0MD34LP1	 147	//( - , DU) Кнопка КВИТИРОВАТЬ
#define A0VT71LZ1	 BUFFER[333]	//( - , MDuBz1) АС по температуре в АЗ1
#define idA0VT71LZ1	 148	//( - , MDuBz1) АС по температуре в АЗ1
#define B0VT71LZ1	 BUFFER[335]	//( - , MDuBz1) АС по температуре в АЗ2
#define idB0VT71LZ1	 149	//( - , MDuBz1) АС по температуре в АЗ2
#define A0VT71LZ2	 BUFFER[337]	//( - , MDuBz2) АС по температуре в АЗ1
#define idA0VT71LZ2	 150	//( - , MDuBz2) АС по температуре в АЗ1
#define B0VT71LZ2	 BUFFER[339]	//( - , MDuBz2) АС по температуре в АЗ2
#define idB0VT71LZ2	 151	//( - , MDuBz2) АС по температуре в АЗ2
#define B2VS11LDU	 BUFFER[341]	//( - , DU) Движение РБ2 в сторону ВУ
#define idB2VS11LDU	 152	//( - , DU) Движение РБ2 в сторону ВУ
#define B2VS21LDU	 BUFFER[343]	//( - , DU) Движение РБ2 в сторону НУ
#define idB2VS21LDU	 153	//( - , DU) Движение РБ2 в сторону НУ
#define B2VS01IDU	 BUFFER[345]	//( - , DU) Готовность к управлению РБ2
#define idB2VS01IDU	 154	//( - , DU) Готовность к управлению РБ2
#define A7AS31LDU	 BUFFER[348]	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
#define idA7AS31LDU	 155	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
#define B7AS31LDU	 BUFFER[350]	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
#define idB7AS31LDU	 156	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
#define A7AZ03LDU	 BUFFER[352]	//( - , DU) Несанкционированное включение обдува АЗ1
#define idA7AZ03LDU	 157	//( - , DU) Несанкционированное включение обдува АЗ1
#define B7AZ03LDU	 BUFFER[354]	//( - , DU) Несанкционированное включение обдува АЗ2
#define idB7AZ03LDU	 158	//( - , DU) Несанкционированное включение обдува АЗ2
#define B3MD12LP1	 BUFFER[356]	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
#define idB3MD12LP1	 159	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
#define B3MD11LP1	 BUFFER[358]	//( - , DU) Кнопка ПУСК ИС2
#define idB3MD11LP1	 160	//( - , DU) Кнопка ПУСК ИС2
#define R0VL01RDU	 BUFFER[360]	//( - , DU) Индикация Время задержки
#define idR0VL01RDU	 161	//( - , DU) Индикация Время задержки
#define R0MD33LP1	 BUFFER[365]	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
#define idR0MD33LP1	 162	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
#define A1MD12LP1	 BUFFER[367]	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
#define idA1MD12LP1	 163	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
#define A1MD11LP1	 BUFFER[369]	//( - , DU) Кнопка ПУСК ББ1
#define idA1MD11LP1	 164	//( - , DU) Кнопка ПУСК ББ1
#define R0MW14IP2	 BUFFER[371]	//( - , DU) Переключатель ОБДУВ
#define idR0MW14IP2	 165	//( - , DU) Переключатель ОБДУВ
#define A7AP31LDU	 BUFFER[374]	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
#define idA7AP31LDU	 166	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
#define B7AP31LDU	 BUFFER[376]	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
#define idB7AP31LDU	 167	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
#define R0MW12IP2	 BUFFER[378]	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define idR0MW12IP2	 168	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define R0MW17LP1	 BUFFER[381]	//( - , DU) Переключатель АВТ/Р
#define idR0MW17LP1	 169	//( - , DU) Переключатель АВТ/Р
#define R0VW13LDU	 BUFFER[383]	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
#define idR0VW13LDU	 170	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
#define R0VW23LDU	 BUFFER[385]	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
#define idR0VW23LDU	 171	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
#define R0VX08IDU	 BUFFER[387]	//( - , DU) Индикация Режим
#define idR0VX08IDU	 172	//( - , DU) Индикация Режим
#define R0VX09LDU	 BUFFER[390]	//( - , DU) Индикация регулятор мощности включен/отключен
#define idR0VX09LDU	 173	//( - , DU) Индикация регулятор мощности включен/отключен
#define R0VS17LDU	 BUFFER[392]	//( - , DU) Индикация выбора АВТОМАТ
#define idR0VS17LDU	 174	//( - , DU) Индикация выбора АВТОМАТ
#define A2VS32LDU	 BUFFER[394]	//( - , DU) Индикация  СБРОС РБ1
#define idA2VS32LDU	 175	//( - , DU) Индикация  СБРОС РБ1
#define B2VS32LDU	 BUFFER[396]	//( - , DU) Индикация  СБРОС РБ2
#define idB2VS32LDU	 176	//( - , DU) Индикация  СБРОС РБ2
#define A3VX01LDU	 BUFFER[398]	//( - , DU) Индикация Выстрел ИС1
#define idA3VX01LDU	 177	//( - , DU) Индикация Выстрел ИС1
#define B3VX01LDU	 BUFFER[400]	//( - , DU) Индикация Выстрел ИС2
#define idB3VX01LDU	 178	//( - , DU) Индикация Выстрел ИС2
#define R0VS18LDU	 BUFFER[402]	//( - , DU) Индикация  Проверка схем сброса
#define idR0VS18LDU	 179	//( - , DU) Индикация  Проверка схем сброса
#define B1MD11LP1	 BUFFER[404]	//( - , DU) Кнопка ПУСК ББ2
#define idB1MD11LP1	 180	//( - , DU) Кнопка ПУСК ББ2
#define B1MD12LP1	 BUFFER[406]	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
#define idB1MD12LP1	 181	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
#define B2MD11LP1	 BUFFER[408]	//( - , DU) Кнопка ПУСК РБ2
#define idB2MD11LP1	 182	//( - , DU) Кнопка ПУСК РБ2
#define B2MD12LP1	 BUFFER[410]	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
#define idB2MD12LP1	 183	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
#define A2MD11LP1	 BUFFER[412]	//( - , DU) Кнопка ПУСК РБ1
#define idA2MD11LP1	 184	//( - , DU) Кнопка ПУСК РБ1
#define B8MC01LC2	 BUFFER[414]	//( - , DU) Настроить энкодер АЗ2
#define idB8MC01LC2	 185	//( - , DU) Настроить энкодер АЗ2
#define A8MC01LC1	 BUFFER[416]	//( - , DU) Настроить энкодер ДС2
#define idA8MC01LC1	 186	//( - , DU) Настроить энкодер ДС2
#define A8MC01LC2	 BUFFER[418]	//( - , DU) Настроить энкодер ДС2
#define idA8MC01LC2	 187	//( - , DU) Настроить энкодер ДС2
#define A3VP42LDU	 BUFFER[420]	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
#define idA3VP42LDU	 188	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
#define A3CP02RDU	 BUFFER[422]	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
#define idA3CP02RDU	 189	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
#define A3VP52LDU	 BUFFER[427]	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define idA3VP52LDU	 190	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define B3VP42LDU	 BUFFER[429]	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
#define idB3VP42LDU	 191	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
#define B3CP02RDU	 BUFFER[431]	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
#define idB3CP02RDU	 192	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
#define B3VP52LDU	 BUFFER[436]	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define idB3VP52LDU	 193	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define B3VP82LDU	 BUFFER[438]	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
#define idB3VP82LDU	 194	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
#define A3VP82LDU	 BUFFER[440]	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
#define idA3VP82LDU	 195	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
#define A3IP02IDU	 BUFFER[442]	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	 196	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
#define B3IP02IDU	 BUFFER[445]	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
#define idB3IP02IDU	 197	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
#define A0VE01LDU	 BUFFER[448]	//( - , DU) Напряжение в системы АЗ1 подано
#define idA0VE01LDU	 198	//( - , DU) Напряжение в системы АЗ1 подано
#define B0VE01LDU	 BUFFER[450]	//( - , DU) Напряжение в системы АЗ2 подано
#define idB0VE01LDU	 199	//( - , DU) Напряжение в системы АЗ2 подано
#define A0VP01LDU	 BUFFER[452]	//( - , DU) Давление в системы АЗ1 подано
#define idA0VP01LDU	 200	//( - , DU) Давление в системы АЗ1 подано
#define B0VP01LDU	 BUFFER[454]	//( - , DU) Давление в системы АЗ2 подано
#define idB0VP01LDU	 201	//( - , DU) Давление в системы АЗ2 подано
#define A0EE01LZ1	 BUFFER[456]	//( - , MDuBz1) Исправность АКНП1
#define idA0EE01LZ1	 202	//( - , MDuBz1) Исправность АКНП1
#define A0EE03LZ1	 BUFFER[458]	//( - , MDuBz1) Исправность АКНП3
#define idA0EE03LZ1	 203	//( - , MDuBz1) Исправность АКНП3
#define A0EE02LZ1	 BUFFER[460]	//( - , MDuBz1) Исправность АКНП2
#define idA0EE02LZ1	 204	//( - , MDuBz1) Исправность АКНП2
#define A0EE04LZ1	 BUFFER[462]	//( - , MDuBz1) Исправность АКНП4
#define idA0EE04LZ1	 205	//( - , MDuBz1) Исправность АКНП4
#define A0VN01LDU	 BUFFER[464]	//( - , DU) Каналы АЗ1 проверены
#define idA0VN01LDU	 206	//( - , DU) Каналы АЗ1 проверены
#define B0VN01LDU	 BUFFER[466]	//( - , DU) Каналы АЗ2 проверены
#define idB0VN01LDU	 207	//( - , DU) Каналы АЗ2 проверены
#define B2IC01UDU	 BUFFER[468]	//( - , MDuS) Координата штока РБ2 (дел.энк)
#define idB2IC01UDU	 208	//( - , MDuS) Координата штока РБ2 (дел.энк)
#define A3IC01UDU	 BUFFER[473]	//( - , MDuS) Координата штока ИС1 (дел.энк)
#define idA3IC01UDU	 209	//( - , MDuS) Координата штока ИС1 (дел.энк)
#define B3IC01UDU	 BUFFER[478]	//( - , MDuS) Координата штока ИС2 (дел.энк)
#define idB3IC01UDU	 210	//( - , MDuS) Координата штока ИС2 (дел.энк)
#define B3VC01RDU	 BUFFER[483]	//( - , DU) Координата ИС2, мм
#define idB3VC01RDU	 211	//( - , DU) Координата ИС2, мм
#define A8IC01UDU	 BUFFER[488]	//( - , MDuS) Координата ДС2 (дел.энк)
#define idA8IC01UDU	 212	//( - , MDuS) Координата ДС2 (дел.энк)
#define A8VC01RDU	 BUFFER[493]	//( - , DU) Координата ДС2, мм
#define idA8VC01RDU	 213	//( - , DU) Координата ДС2, мм
#define B8IC01UDU	 BUFFER[498]	//( - , MDuS) Координата АЗ2 (дел.энк)
#define idB8IC01UDU	 214	//( - , MDuS) Координата АЗ2 (дел.энк)
#define A1IC01UDU	 BUFFER[503]	//( - , MDuS) Координата штока ББ1 (дел.энк)
#define idA1IC01UDU	 215	//( - , MDuS) Координата штока ББ1 (дел.энк)
#define A1VC01RDU	 BUFFER[508]	//( - , DU) Координата ББ1, мм
#define idA1VC01RDU	 216	//( - , DU) Координата ББ1, мм
#define A1IS11LDU	 BUFFER[513]	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
#define idA1IS11LDU	 217	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
#define B1MC01LC1	 BUFFER[515]	//( - , DU) Настроить энкодер ББ2
#define idB1MC01LC1	 218	//( - , DU) Настроить энкодер ББ2
#define B1MC01LC2	 BUFFER[517]	//( - , DU) Настроить энкодер ББ2
#define idB1MC01LC2	 219	//( - , DU) Настроить энкодер ББ2
#define A1MC01LC1	 BUFFER[519]	//( - , DU) Настроить энкодер ББ1
#define idA1MC01LC1	 220	//( - , DU) Настроить энкодер ББ1
#define A1MC01LC2	 BUFFER[521]	//( - , DU) Настроить энкодер ББ1
#define idA1MC01LC2	 221	//( - , DU) Настроить энкодер ББ1
#define B2MC01LC1	 BUFFER[523]	//( - , DU) Настроить энкодер РБ2
#define idB2MC01LC1	 222	//( - , DU) Настроить энкодер РБ2
#define B2MC01LC2	 BUFFER[525]	//( - , DU) Настроить энкодер РБ2
#define idB2MC01LC2	 223	//( - , DU) Настроить энкодер РБ2
#define A2MC01LC1	 BUFFER[527]	//( - , DU) Настроить энкодер РБ1
#define idA2MC01LC1	 224	//( - , DU) Настроить энкодер РБ1
#define A2MC01LC2	 BUFFER[529]	//( - , DU) Настроить энкодер РБ1
#define idA2MC01LC2	 225	//( - , DU) Настроить энкодер РБ1
#define B3MC01LC1	 BUFFER[531]	//( - , DU) Настроить энкодер ИС2
#define idB3MC01LC1	 226	//( - , DU) Настроить энкодер ИС2
#define B3MC01LC2	 BUFFER[533]	//( - , DU) Настроить энкодер ИС2
#define idB3MC01LC2	 227	//( - , DU) Настроить энкодер ИС2
#define A3MC01LC1	 BUFFER[535]	//( - , DU) Настроить энкодер ИС1
#define idA3MC01LC1	 228	//( - , DU) Настроить энкодер ИС1
#define A3MC01LC2	 BUFFER[537]	//( - , DU) Настроить энкодер ИС1
#define idA3MC01LC2	 229	//( - , DU) Настроить энкодер ИС1
#define B8MC01LC1	 BUFFER[539]	//( - , DU) Настроить энкодер АЗ2
#define idB8MC01LC1	 230	//( - , DU) Настроить энкодер АЗ2
#define R0IE01LDU	 BUFFER[541]	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
#define idR0IE01LDU	 231	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
#define A6IE01LDU	 BUFFER[543]	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
#define idA6IE01LDU	 232	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
#define B6IE01LDU	 BUFFER[545]	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
#define idB6IE01LDU	 233	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
#define A8IE01LDU	 BUFFER[547]	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
#define idA8IE01LDU	 234	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
#define B5IE01LDU	 BUFFER[549]	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
#define idB5IE01LDU	 235	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
#define A5IE02LDU	 BUFFER[551]	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
#define idA5IE02LDU	 236	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
#define R1IE01LDU	 BUFFER[553]	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
#define idR1IE01LDU	 237	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
#define R2IE01LDU	 BUFFER[555]	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
#define idR2IE01LDU	 238	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
#define R6IS61LDU	 BUFFER[557]	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
#define idR6IS61LDU	 239	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
#define R6IS66LZZ	 BUFFER[559]	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 240	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	 BUFFER[561]	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 241	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	 BUFFER[563]	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 242	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define A3VC01RDU	 BUFFER[565]	//( - , DU) Координата ИС1, мм
#define idA3VC01RDU	 243	//( - , DU) Координата ИС1, мм
#define A2VC01RDU	 BUFFER[570]	//( - , DU) Координата РБ1, мм
#define idA2VC01RDU	 244	//( - , DU) Координата РБ1, мм
#define B2VC01RDU	 BUFFER[575]	//( - , DU) Координата РБ2, мм
#define idB2VC01RDU	 245	//( - , DU) Координата РБ2, мм
#define B8VC01RDU	 BUFFER[580]	//( - , DU, MDuBz1, MDuBz2) Координата АЗ2, мм
#define idB8VC01RDU	 246	//( - , DU, MDuBz1, MDuBz2) Координата АЗ2, мм
#define A4VP82LDU	 BUFFER[585]	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	 247	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define B4VP82LDU	 BUFFER[587]	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	 248	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define A2VP82LDU	 BUFFER[589]	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	 249	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define B2VP82LDU	 BUFFER[591]	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define idB2VP82LDU	 250	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define A3VP81LDU	 BUFFER[593]	//( - , - ) Давление СПУСК ИС1 в норме
#define idA3VP81LDU	 251	//( - , - ) Давление СПУСК ИС1 в норме
#define B3VP81LDU	 BUFFER[595]	//( - , - ) Давление СПУСК ИС2 в норме
#define idB3VP81LDU	 252	//( - , - ) Давление СПУСК ИС2 в норме
#define R0EE02LDU	 BUFFER[597]	//( - , DU) Питание  АКНП  отключить
#define idR0EE02LDU	 253	//( - , DU) Питание  АКНП  отключить
#define A0EE01LZ2	 BUFFER[599]	//( - , MDuBz2) Исправность АКНП1
#define idA0EE01LZ2	 254	//( - , MDuBz2) Исправность АКНП1
#define A0EE03LZ2	 BUFFER[601]	//( - , MDuBz2) Исправность АКНП3
#define idA0EE03LZ2	 255	//( - , MDuBz2) Исправность АКНП3
#define A0EE02LZ2	 BUFFER[603]	//( - , MDuBz2) Исправность АКНП2
#define idA0EE02LZ2	 256	//( - , MDuBz2) Исправность АКНП2
#define A0EE04LZ2	 BUFFER[605]	//( - , MDuBz2) Исправность АКНП4
#define idA0EE04LZ2	 257	//( - , MDuBz2) Исправность АКНП4
#define A0VP71LZ1	 BUFFER[607]	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ1	 258	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
#define A0VP71LZ2	 BUFFER[609]	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ2	 259	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
#define B0VP71LZ1	 BUFFER[611]	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ1	 260	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
#define B0VP71LZ2	 BUFFER[613]	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ2	 261	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
#define A0VS11LDU	 BUFFER[615]	//( - , DU) АЗ1 готова к работе
#define idA0VS11LDU	 262	//( - , DU) АЗ1 готова к работе
#define B0VS11LDU	 BUFFER[617]	//( - , DU) АЗ2 готова к работе
#define idB0VS11LDU	 263	//( - , DU) АЗ2 готова к работе
#define A1IE01LDU	 BUFFER[619]	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
#define idA1IE01LDU	 264	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
#define A3IE01LDU	 BUFFER[621]	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
#define idA3IE01LDU	 265	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
#define A2IE01LDU	 BUFFER[623]	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
#define idA2IE01LDU	 266	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
#define A1IE02LDU	 BUFFER[625]	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
#define idA1IE02LDU	 267	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
#define A3IE02LDU	 BUFFER[627]	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
#define idA3IE02LDU	 268	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
#define A2IE02LDU	 BUFFER[629]	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
#define idA2IE02LDU	 269	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
#define B1IE01LDU	 BUFFER[631]	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
#define idB1IE01LDU	 270	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
#define B2IE01LDU	 BUFFER[633]	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
#define idB2IE01LDU	 271	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
#define B3IE01LDU	 BUFFER[635]	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
#define idB3IE01LDU	 272	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
#define B1IE02LDU	 BUFFER[637]	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
#define idB1IE02LDU	 273	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
#define B3IE02LDU	 BUFFER[639]	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
#define idB3IE02LDU	 274	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
#define B2IE02LDU	 BUFFER[641]	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
#define idB2IE02LDU	 275	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
#define R0IE02LDU	 BUFFER[643]	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
#define idR0IE02LDU	 276	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
#define R0AD05LZ2	 BUFFER[645]	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
#define idR0AD05LZ2	 277	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
#define B8IS12LDU	 BUFFER[647]	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
#define idB8IS12LDU	 278	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
#define B8IS21LDU	 BUFFER[649]	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
#define idB8IS21LDU	 279	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
#define A1VP41LZ1	 BUFFER[651]	//( - , MDuBz1) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ1	 280	//( - , MDuBz1) Давление СБРОС ББ1 ниже АС
#define A1VP41LZ2	 BUFFER[653]	//( - , MDuBz2) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ2	 281	//( - , MDuBz2) Давление СБРОС ББ1 ниже АС
#define R0VL22LDU	 BUFFER[655]	//( - , DU) Конец программы 200сек
#define idR0VL22LDU	 282	//( - , DU) Конец программы 200сек
#define R0VL23LDU	 BUFFER[657]	//( - , DU) Конец программы 20мин
#define idR0VL23LDU	 283	//( - , DU) Конец программы 20мин
#define B1VP41LZ1	 BUFFER[659]	//( - , MDuBz1) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ1	 284	//( - , MDuBz1) Давление СБРОС ББ2 ниже АС
#define B1VP41LZ2	 BUFFER[661]	//( - , MDuBz2) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ2	 285	//( - , MDuBz2) Давление СБРОС ББ2 ниже АС
#define A3AB19LDU	 BUFFER[663]	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
#define idA3AB19LDU	 286	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
#define B3AB19LDU	 BUFFER[665]	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
#define idB3AB19LDU	 287	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
#define A3EE03LDU	 BUFFER[667]	//( - , DU) ВПИС ИС1
#define idA3EE03LDU	 288	//( - , DU) ВПИС ИС1
#define B3EE03LDU	 BUFFER[669]	//( - , DU) ВПИС ИС2
#define idB3EE03LDU	 289	//( - , DU) ВПИС ИС2
#define B3AB15LDU	 BUFFER[671]	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
#define idB3AB15LDU	 290	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
#define R5IS21LDU	 BUFFER[673]	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	 291	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
#define R5VS22LDU	 BUFFER[675]	//( - , DU) Движение ворот отстойной зоны к закрыты
#define idR5VS22LDU	 292	//( - , DU) Движение ворот отстойной зоны к закрыты
#define R5VS12LDU	 BUFFER[677]	//( - , DU) Движение ворот отстойной зоны к открыты
#define idR5VS12LDU	 293	//( - , DU) Движение ворот отстойной зоны к открыты
#define R5VS01IDU	 BUFFER[679]	//( - , DU) Готовность к управлению ворот отстойной зоны
#define idR5VS01IDU	 294	//( - , DU) Готовность к управлению ворот отстойной зоны
#define R3VS22LDU	 BUFFER[682]	//( - , DU) Движение гомогенных дверей к закрыты
#define idR3VS22LDU	 295	//( - , DU) Движение гомогенных дверей к закрыты
#define R3VS12LDU	 BUFFER[684]	//( - , DU) Движение гомогенных дверей к открыты
#define idR3VS12LDU	 296	//( - , DU) Движение гомогенных дверей к открыты
#define R3VS01IDU	 BUFFER[686]	//( - , DU) Готовность к управлению гомогенных дверей
#define idR3VS01IDU	 297	//( - , DU) Готовность к управлению гомогенных дверей
#define A3AB13LDU	 BUFFER[689]	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
#define idA3AB13LDU	 298	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
#define B3AB13LDU	 BUFFER[691]	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define idB3AB13LDU	 299	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define R0AB18LDU	 BUFFER[693]	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
#define idR0AB18LDU	 300	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
#define A0CT01IZ1	 BUFFER[695]	//( - , MDuBz1) Температура АЗ1-1
#define idA0CT01IZ1	 301	//( - , MDuBz1) Температура АЗ1-1
#define B0CT01IZ1	 BUFFER[700]	//( - , MDuBz1) Температура АЗ2-1
#define idB0CT01IZ1	 302	//( - , MDuBz1) Температура АЗ2-1
#define A0CT01IZ2	 BUFFER[705]	//( - , MDuBz2) Температура АЗ1-2
#define idA0CT01IZ2	 303	//( - , MDuBz2) Температура АЗ1-2
#define B0CT01IZ2	 BUFFER[710]	//( - , MDuBz2) Температура АЗ2-2
#define idB0CT01IZ2	 304	//( - , MDuBz2) Температура АЗ2-2
#define A3MC01RDU	 BUFFER[715]	//( - , DU) Заданная координата положения ИС от регулятора мм
#define idA3MC01RDU	 305	//( - , DU) Заданная координата положения ИС от регулятора мм
#define A3MC02RDU	 BUFFER[720]	//( - , DU) Температурная корректировка координаты ИМ
#define idA3MC02RDU	 306	//( - , DU) Температурная корректировка координаты ИМ
#define R0CN91LDU	 BUFFER[725]	//( - , DU) Рассчётная реактивность от регулятора
#define idR0CN91LDU	 307	//( - , DU) Рассчётная реактивность от регулятора
#define A3MC03RDU	 BUFFER[730]	//( - , DU) Координата положения ИМ 0-й реактивности
#define idA3MC03RDU	 308	//( - , DU) Координата положения ИМ 0-й реактивности
#define A3AB15LDU	 BUFFER[735]	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
#define idA3AB15LDU	 309	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
#define R0AB20LDU	 BUFFER[737]	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
#define idR0AB20LDU	 310	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
#define R0CN92LDU	 BUFFER[739]	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
#define idR0CN92LDU	 311	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
#define R0VN11RDU	 BUFFER[744]	//( - , DU) Текущая мощность РУ
#define idR0VN11RDU	 312	//( - , DU) Текущая мощность РУ
#define R0VN12RDU	 BUFFER[749]	//( - , DU) Заданная мощность РУ
#define idR0VN12RDU	 313	//( - , DU) Заданная мощность РУ
#define R0AB19LDU	 BUFFER[754]	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
#define idR0AB19LDU	 314	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
#define R0CN93LDU	 BUFFER[756]	//( - , DU) время работы на мощности более 100Вт, сек
#define idR0CN93LDU	 315	//( - , DU) время работы на мощности более 100Вт, сек
#define R0CN94LDU	 BUFFER[761]	//( - , DU) Скорость изменения мощности
#define idR0CN94LDU	 316	//( - , DU) Скорость изменения мощности
#define R0CN95LDU	 BUFFER[766]	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
#define idR0CN95LDU	 317	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
#define R0AD03LZ1	 BUFFER[769]	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
#define idR0AD03LZ1	 318	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
#define R0AD03LZ2	 BUFFER[771]	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
#define idR0AD03LZ2	 319	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
#define R0AD04LZ1	 BUFFER[773]	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define idR0AD04LZ1	 320	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define R0AD04LZ2	 BUFFER[775]	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define idR0AD04LZ2	 321	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define R0AD05LZ1	 BUFFER[777]	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
#define idR0AD05LZ1	 322	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
#define R0DEB1LDU	 BUFFER[779]	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
#define idR0DEB1LDU	 323	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
#define R0DEB4LDU	 BUFFER[781]	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
#define idR0DEB4LDU	 324	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
#define R0DE3DLDU	 BUFFER[783]	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
#define idR0DE3DLDU	 325	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
#define R0DE3CLDU	 BUFFER[785]	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
#define idR0DE3CLDU	 326	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
#define TestDiagnDU	 BUFFER[787]	//( - , DU) Неисправность от
#define idTestDiagnDU	 327	//( - , DU) Неисправность от
#define B3CV01RDU	 BUFFER[789]	//( - , DU) Измеренная скорость перемещения ИС2
#define idB3CV01RDU	 328	//( - , DU) Измеренная скорость перемещения ИС2
#define R0DE01LDU	 BUFFER[794]	//(vencf8l:01 - DiagnVDS, DiagnDU) диагностика модуля ДУ на 1 месте
#define idR0DE01LDU	 329	//(vencf8l:01 - DiagnVDS, DiagnDU) диагностика модуля ДУ на 1 месте
#define R0DE06LDU	 BUFFER[797]	//(vencf8l:01 - DiagnFDS, DiagnDU) диагностика модуля ДУ на 6 месте
#define idR0DE06LDU	 330	//(vencf8l:01 - DiagnFDS, DiagnDU) диагностика модуля ДУ на 6 месте
#define venc01	 BUFFER[800]	//(vencf8l:01 - venc01, - ) заначение реального энкодера ББ1
#define idvenc01	 331	//(vencf8l:01 - venc01, - ) заначение реального энкодера ББ1
#define venc02	 BUFFER[805]	//(vencf8l:01 - venc02, - ) заначение реального энкодера РБ1
#define idvenc02	 332	//(vencf8l:01 - venc02, - ) заначение реального энкодера РБ1
#define venc03	 BUFFER[810]	//(vencf8l:01 - venc03, - ) заначение реального энкодера Ис1
#define idvenc03	 333	//(vencf8l:01 - venc03, - ) заначение реального энкодера Ис1
#define venc04	 BUFFER[815]	//(vencf8l:01 - venc04, - ) заначение реального энкодера ДС1
#define idvenc04	 334	//(vencf8l:01 - venc04, - ) заначение реального энкодера ДС1
#define venc05	 BUFFER[820]	//(vencf8l:01 - venc05, - ) заначение реального энкодера ББ2
#define idvenc05	 335	//(vencf8l:01 - venc05, - ) заначение реального энкодера ББ2
#define venc06	 BUFFER[825]	//(vencf8l:01 - venc06, - ) заначение реального энкодера РБ2
#define idvenc06	 336	//(vencf8l:01 - venc06, - ) заначение реального энкодера РБ2
#define venc07	 BUFFER[830]	//(vencf8l:01 - venc07, - ) заначение реального энкодера ИС2
#define idvenc07	 337	//(vencf8l:01 - venc07, - ) заначение реального энкодера ИС2
#define venc08	 BUFFER[835]	//(vencf8l:01 - venc08, - ) заначение реального энкодера АЗ2
#define idvenc08	 338	//(vencf8l:01 - venc08, - ) заначение реального энкодера АЗ2
#define R0VN15RDU	 BUFFER[840]	//( - , DU) Период разгона РУ
#define idR0VN15RDU	 339	//( - , DU) Период разгона РУ
#define R8AD21LDU	 BUFFER[845]	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
#define idR8AD21LDU	 340	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
#define R8AD22LDU	 BUFFER[847]	//(vds32:02 - K15VDSR, - ) Сигнал синхронизации с импульсом
#define idR8AD22LDU	 341	//(vds32:02 - K15VDSR, - ) Сигнал синхронизации с импульсом
#define B1IC01UDU	 BUFFER[849]	//( - , MDuS) Координата штока ББ2 (дел.энк)
#define idB1IC01UDU	 342	//( - , MDuS) Координата штока ББ2 (дел.энк)
#define B1VC01RDU	 BUFFER[854]	//( - , DU) Координата ББ2, мм
#define idB1VC01RDU	 343	//( - , DU) Координата ББ2, мм
#define B1IS11LDU	 BUFFER[859]	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
#define idB1IS11LDU	 344	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
#define A2IC01UDU	 BUFFER[861]	//( - , MDuS) Координата штока РБ1 (дел.энк)
#define idA2IC01UDU	 345	//( - , MDuS) Координата штока РБ1 (дел.энк)
#define R0DE02LDU	 BUFFER[866]	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
#define idR0DE02LDU	 346	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
#define R0DE03LDU	 BUFFER[869]	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
#define idR0DE03LDU	 347	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
#define R0DE04LDU	 BUFFER[872]	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
#define idR0DE04LDU	 348	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
#define R0DE08LDU	 BUFFER[875]	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
#define idR0DE08LDU	 349	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
#define R0DE05LDU	 BUFFER[878]	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
#define idR0DE05LDU	 350	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
#define R0DE09LDU	 BUFFER[881]	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
#define idR0DE09LDU	 351	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
#define R0DE0ALDU	 BUFFER[884]	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
#define idR0DE0ALDU	 352	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
#define R0DE07LDU	 BUFFER[887]	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
#define idR0DE07LDU	 353	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
#define R0DE0CLDU	 BUFFER[890]	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
#define idR0DE0CLDU	 354	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
#define R0DE0BLDU	 BUFFER[893]	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
#define idR0DE0BLDU	 355	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
#define R0DE0DLDU	 BUFFER[896]	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
#define idR0DE0DLDU	 356	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
#define R0DE0FLDU	 BUFFER[899]	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
#define idR0DE0FLDU	 357	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
#define R0DE31LDU	 BUFFER[902]	//(sbk:20 - S01SBK, DiagnDU) диагностика шкафа ДУ сеть 1
#define idR0DE31LDU	 358	//(sbk:20 - S01SBK, DiagnDU) диагностика шкафа ДУ сеть 1
#define TTLDU	 BUFFER[904]	//( - , DU) ttl
#define idTTLDU	 359	//( - , DU) ttl
#define R0DE32LDU	 BUFFER[907]	//(sbk:20 - S02SBK, DiagnDU) диагностика шкафа ДУ сеть 2
#define idR0DE32LDU	 360	//(sbk:20 - S02SBK, DiagnDU) диагностика шкафа ДУ сеть 2
#define R0DE33LDU	 BUFFER[909]	//(sbk:20 - S03SBK, DiagnDU) диагностика шкафа ДУ двери
#define idR0DE33LDU	 361	//(sbk:20 - S03SBK, DiagnDU) диагностика шкафа ДУ двери
#define R0DE34LDU	 BUFFER[911]	//(sbk:20 - S04SBK, DiagnDU) диагностика шкафа ДУ температура меньше 43
#define idR0DE34LDU	 362	//(sbk:20 - S04SBK, DiagnDU) диагностика шкафа ДУ температура меньше 43
#define R0DE35LDU	 BUFFER[913]	//(sbk:20 - S05SBK, DiagnDU) диагностика шкафа ДУ температура больше 53
#define idR0DE35LDU	 363	//(sbk:20 - S05SBK, DiagnDU) диагностика шкафа ДУ температура больше 53
#define R0DE36LDU	 BUFFER[915]	//(sbk:20 - S06SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 1
#define idR0DE36LDU	 364	//(sbk:20 - S06SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 1
#define R0DE37LDU	 BUFFER[917]	//(sbk:20 - S07SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 2
#define idR0DE37LDU	 365	//(sbk:20 - S07SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 2
#define R0DE38LDU	 BUFFER[919]	//(sbk:20 - S08SBK, DiagnDU) диагностика шкафа ДУ МП15-3 место 3
#define idR0DE38LDU	 366	//(sbk:20 - S08SBK, DiagnDU) диагностика шкафа ДУ МП15-3 место 3
#define R0DE39LDU	 BUFFER[921]	//(sbk:20 - S09SBK, DiagnDU) диагностика шкафа ДУ МП24-2 место 4
#define idR0DE39LDU	 367	//(sbk:20 - S09SBK, DiagnDU) диагностика шкафа ДУ МП24-2 место 4
#define R0DEB3LDU	 BUFFER[923]	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
#define idR0DEB3LDU	 368	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
#define R0DEB2LDU	 BUFFER[925]	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
#define idR0DEB2LDU	 369	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
#define A6AB07LDU	 BUFFER[927]	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
#define idA6AB07LDU	 370	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
#define A6AB08LDU	 BUFFER[929]	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
#define idA6AB08LDU	 371	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
#define A6AB09LDU	 BUFFER[931]	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
#define idA6AB09LDU	 372	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
#define B6AB06LDU	 BUFFER[933]	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
#define idB6AB06LDU	 373	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
#define B6AB07LDU	 BUFFER[935]	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
#define idB6AB07LDU	 374	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
#define B6AB08LDU	 BUFFER[937]	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
#define idB6AB08LDU	 375	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
#define B6AB09LDU	 BUFFER[939]	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
#define idB6AB09LDU	 376	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
#define A6AB05LDU	 BUFFER[941]	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
#define idA6AB05LDU	 377	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
#define B8VS12LDU	 BUFFER[943]	//( - , DU) Движение АЗ2 в сторону ВУ
#define idB8VS12LDU	 378	//( - , DU) Движение АЗ2 в сторону ВУ
#define B8CV01RDU	 BUFFER[945]	//( - , DU) Измеренная скорость перемещения АЗ2
#define idB8CV01RDU	 379	//( - , DU) Измеренная скорость перемещения АЗ2
#define B8AB06LDU	 BUFFER[950]	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
#define idB8AB06LDU	 380	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
#define B8AB07LDU	 BUFFER[952]	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
#define idB8AB07LDU	 381	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
#define B8AB05LDU	 BUFFER[954]	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
#define idB8AB05LDU	 382	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
#define B8VS22LDU	 BUFFER[956]	//( - , DU) Движение АЗ2 в сторону НУ
#define idB8VS22LDU	 383	//( - , DU) Движение АЗ2 в сторону НУ
#define B8AZ03LDU	 BUFFER[958]	//( - , DU) Несанкционированное перемещение АЗ2
#define idB8AZ03LDU	 384	//( - , DU) Несанкционированное перемещение АЗ2
#define R0MD11LP1	 BUFFER[960]	//( - , DU) Кнопка ПУСК
#define idR0MD11LP1	 385	//( - , DU) Кнопка ПУСК
#define B8AD10LDU	 BUFFER[962]	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
#define idB8AD10LDU	 386	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
#define B8AD20LDU	 BUFFER[964]	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
#define idB8AD20LDU	 387	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
#define B8IS11LDU	 BUFFER[966]	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
#define idB8IS11LDU	 388	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
#define B8AB01LDU	 BUFFER[968]	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
#define idB8AB01LDU	 389	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
#define B8AB04LDU	 BUFFER[970]	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
#define idB8AB04LDU	 390	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
#define B8AB08LDU	 BUFFER[972]	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
#define idB8AB08LDU	 391	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
#define B8AB09LDU	 BUFFER[974]	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
#define idB8AB09LDU	 392	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
#define A5AB01LDU	 BUFFER[976]	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
#define idA5AB01LDU	 393	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
#define A5AB02LDU	 BUFFER[978]	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
#define idA5AB02LDU	 394	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
#define B5AZ03LDU	 BUFFER[980]	//( - , DU) Несанкционированное перемещение НЛ2
#define idB5AZ03LDU	 395	//( - , DU) Несанкционированное перемещение НЛ2
#define B5AB01LDU	 BUFFER[982]	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
#define idB5AB01LDU	 396	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
#define B5AB02LDU	 BUFFER[984]	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
#define idB5AB02LDU	 397	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
#define A4IS21LDU	 BUFFER[986]	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
#define idA4IS21LDU	 398	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
#define B4IS21LDU	 BUFFER[988]	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
#define idB4IS21LDU	 399	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
#define B4AD10LDU	 BUFFER[990]	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
#define idB4AD10LDU	 400	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
#define A4AD10LDU	 BUFFER[992]	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
#define idA4AD10LDU	 401	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
#define A4AZ03LDU	 BUFFER[994]	//( - , DU) Несанкционированное перемещение НИ1
#define idA4AZ03LDU	 402	//( - , DU) Несанкционированное перемещение НИ1
#define A4AB01LDU	 BUFFER[996]	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
#define idA4AB01LDU	 403	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
#define A4AB02LDU	 BUFFER[998]	//( - , DU) Блокировка движения НИ1 - Нет перемещения
#define idA4AB02LDU	 404	//( - , DU) Блокировка движения НИ1 - Нет перемещения
#define B4AZ03LDU	 BUFFER[1000]	//( - , DU) Несанкционированное перемещение НИ2
#define idB4AZ03LDU	 405	//( - , DU) Несанкционированное перемещение НИ2
#define B4AB01LDU	 BUFFER[1002]	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
#define idB4AB01LDU	 406	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
#define B4AB02LDU	 BUFFER[1004]	//( - , DU) Блокировка движения НИ2 - Нет перемещения
#define idB4AB02LDU	 407	//( - , DU) Блокировка движения НИ2 - Нет перемещения
#define A5AB04LDU	 BUFFER[1006]	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
#define idA5AB04LDU	 408	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
#define B5AB04LDU	 BUFFER[1008]	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
#define idB5AB04LDU	 409	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
#define A1IS12LDU	 BUFFER[1010]	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
#define idA1IS12LDU	 410	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
#define A2IS12LDU	 BUFFER[1012]	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
#define idA2IS12LDU	 411	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
#define B1IS12LDU	 BUFFER[1014]	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
#define idB1IS12LDU	 412	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
#define B2IS12LDU	 BUFFER[1016]	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
#define idB2IS12LDU	 413	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
#define R4IS11LDU	 BUFFER[1018]	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
#define idR4IS11LDU	 414	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
#define A6AB06LDU	 BUFFER[1020]	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
#define idA6AB06LDU	 415	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
#define A8AB12LDU	 BUFFER[1022]	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
#define idA8AB12LDU	 416	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
#define A8AB13LDU	 BUFFER[1024]	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
#define idA8AB13LDU	 417	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
#define A8AB14LDU	 BUFFER[1026]	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
#define idA8AB14LDU	 418	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
#define A8AB02LDU	 BUFFER[1028]	//( - , DU) Блокировка движения ДС2- АНИ не установлен
#define idA8AB02LDU	 419	//( - , DU) Блокировка движения ДС2- АНИ не установлен
#define A8AB01LDU	 BUFFER[1030]	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
#define idA8AB01LDU	 420	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
#define A2VS11LDU	 BUFFER[1032]	//( - , DU) Движение РБ1 в сторону ВУ
#define idA2VS11LDU	 421	//( - , DU) Движение РБ1 в сторону ВУ
#define A2CV01RDU	 BUFFER[1034]	//( - , DU) Измеренная скорость перемещения РБ1
#define idA2CV01RDU	 422	//( - , DU) Измеренная скорость перемещения РБ1
#define A2AB04LDU	 BUFFER[1039]	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
#define idA2AB04LDU	 423	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
#define A2AB02LDU	 BUFFER[1041]	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
#define idA2AB02LDU	 424	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
#define A2AB01LDU	 BUFFER[1043]	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
#define idA2AB01LDU	 425	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
#define A2VS21LDU	 BUFFER[1045]	//( - , DU) Движение РБ1 в сторону НУ
#define idA2VS21LDU	 426	//( - , DU) Движение РБ1 в сторону НУ
#define A2AZ03LDU	 BUFFER[1047]	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
#define idA2AZ03LDU	 427	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
#define A2AD11LDU	 BUFFER[1049]	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	 428	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
#define A2AD21LDU	 BUFFER[1051]	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	 429	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
#define A2AD02LDU	 BUFFER[1053]	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
#define idA2AD02LDU	 430	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
#define A2AD03LDU	 BUFFER[1055]	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
#define idA2AD03LDU	 431	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
#define A2AD04LDU	 BUFFER[1057]	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
#define idA2AD04LDU	 432	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
#define A2AD05LDU	 BUFFER[1059]	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
#define idA2AD05LDU	 433	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
#define A2AB07LDU	 BUFFER[1061]	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
#define idA2AB07LDU	 434	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
#define A2AB08LDU	 BUFFER[1063]	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
#define idA2AB08LDU	 435	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
#define A2AB05LDU	 BUFFER[1065]	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
#define idA2AB05LDU	 436	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
#define A2AB06LDU	 BUFFER[1067]	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
#define idA2AB06LDU	 437	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
#define A2AB09LDU	 BUFFER[1069]	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
#define idA2AB09LDU	 438	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
#define B8AB10LDU	 BUFFER[1071]	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
#define idB8AB10LDU	 439	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
#define B8AB11LDU	 BUFFER[1073]	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
#define idB8AB11LDU	 440	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
#define B8AB12LDU	 BUFFER[1075]	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
#define idB8AB12LDU	 441	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
#define B8AB13LDU	 BUFFER[1077]	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
#define idB8AB13LDU	 442	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
#define B8AB14LDU	 BUFFER[1079]	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
#define idB8AB14LDU	 443	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
#define B8AB02LDU	 BUFFER[1081]	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
#define idB8AB02LDU	 444	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
#define A8VS12LDU	 BUFFER[1083]	//( - , DU) Движение ДС2 в сторону ВУ
#define idA8VS12LDU	 445	//( - , DU) Движение ДС2 в сторону ВУ
#define A8CV01RDU	 BUFFER[1085]	//( - , DU) Измеренная скорость перемещения ДС2
#define idA8CV01RDU	 446	//( - , DU) Измеренная скорость перемещения ДС2
#define A8AB06LDU	 BUFFER[1090]	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
#define idA8AB06LDU	 447	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
#define A8AB07LDU	 BUFFER[1092]	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
#define idA8AB07LDU	 448	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
#define A8AB05LDU	 BUFFER[1094]	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
#define idA8AB05LDU	 449	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
#define A8VS22LDU	 BUFFER[1096]	//( - , DU) Движение ДС2 в сторону НУ
#define idA8VS22LDU	 450	//( - , DU) Движение ДС2 в сторону НУ
#define A8AZ03LDU	 BUFFER[1098]	//( - , DU) Несанкционированное перемещение ДС2
#define idA8AZ03LDU	 451	//( - , DU) Несанкционированное перемещение ДС2
#define A8AD10LDU	 BUFFER[1100]	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
#define idA8AD10LDU	 452	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
#define A8AD20LDU	 BUFFER[1102]	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
#define idA8AD20LDU	 453	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
#define B8IS22LDU	 BUFFER[1104]	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
#define idB8IS22LDU	 454	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
#define A8IS12LDU	 BUFFER[1106]	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
#define idA8IS12LDU	 455	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
#define A8AB04LDU	 BUFFER[1108]	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
#define idA8AB04LDU	 456	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
#define A8IS22LDU	 BUFFER[1110]	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
#define idA8IS22LDU	 457	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
#define A8AB08LDU	 BUFFER[1112]	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define idA8AB08LDU	 458	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define A8AB09LDU	 BUFFER[1114]	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
#define idA8AB09LDU	 459	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
#define A8AB10LDU	 BUFFER[1116]	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
#define idA8AB10LDU	 460	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
#define A8AB11LDU	 BUFFER[1118]	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
#define idA8AB11LDU	 461	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
#define B6IS21LDU	 BUFFER[1120]	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
#define idB6IS21LDU	 462	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
#define A6VS22LDU	 BUFFER[1122]	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
#define idA6VS22LDU	 463	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
#define A6VS12LDU	 BUFFER[1124]	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
#define idA6VS12LDU	 464	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
#define B6VS22LDU	 BUFFER[1126]	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
#define idB6VS22LDU	 465	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
#define B6VS12LDU	 BUFFER[1128]	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
#define idB6VS12LDU	 466	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
#define A6AD10LDU	 BUFFER[1130]	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
#define idA6AD10LDU	 467	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
#define A6AD20LDU	 BUFFER[1132]	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
#define idA6AD20LDU	 468	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
#define B6AD10LDU	 BUFFER[1134]	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
#define idB6AD10LDU	 469	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
#define B6AD20LDU	 BUFFER[1136]	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
#define idB6AD20LDU	 470	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
#define A6AZ03LDU	 BUFFER[1138]	//( - , DU) Несанкционированное перемещение БЗ1
#define idA6AZ03LDU	 471	//( - , DU) Несанкционированное перемещение БЗ1
#define A6AB01LDU	 BUFFER[1140]	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
#define idA6AB01LDU	 472	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
#define A6AB02LDU	 BUFFER[1142]	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
#define idA6AB02LDU	 473	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
#define B6AZ03LDU	 BUFFER[1144]	//( - , DU) Несанкционированное перемещение БЗ2
#define idB6AZ03LDU	 474	//( - , DU) Несанкционированное перемещение БЗ2
#define B6AB01LDU	 BUFFER[1146]	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
#define idB6AB01LDU	 475	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
#define B6AB02LDU	 BUFFER[1148]	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
#define idB6AB02LDU	 476	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
#define A6AB04LDU	 BUFFER[1150]	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
#define idA6AB04LDU	 477	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
#define B6AB04LDU	 BUFFER[1152]	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
#define idB6AB04LDU	 478	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
#define R4AB01LDU	 BUFFER[1154]	//( - , DU) Блокировка движения тележки - АНИ не установлен
#define idR4AB01LDU	 479	//( - , DU) Блокировка движения тележки - АНИ не установлен
#define R8IS11LDU	 BUFFER[1156]	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
#define idR8IS11LDU	 480	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
#define R6IS21LDU	 BUFFER[1158]	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
#define idR6IS21LDU	 481	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
#define A0VN71LZ2	 BUFFER[1160]	//( - , MDuBz2) АЗ по АС мощности для АЗ1
#define idA0VN71LZ2	 482	//( - , MDuBz2) АЗ по АС мощности для АЗ1
#define A0VN71LZ1	 BUFFER[1162]	//( - , MDuBz1) АЗ по АС мощности для АЗ1
#define idA0VN71LZ1	 483	//( - , MDuBz1) АЗ по АС мощности для АЗ1
#define R0NE01LDU	 BUFFER[1164]	//( - , DU) Потеря связи с БАЗ1
#define idR0NE01LDU	 484	//( - , DU) Потеря связи с БАЗ1
#define R0MW15IP1	 BUFFER[1166]	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
#define idR0MW15IP1	 485	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
#define R0MW14IP1	 BUFFER[1169]	//( - , DU) Переключатель ПРОГРАММЫ
#define idR0MW14IP1	 486	//( - , DU) Переключатель ПРОГРАММЫ
#define R0MW12IP1	 BUFFER[1172]	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
#define idR0MW12IP1	 487	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
#define R0MW13IP1	 BUFFER[1175]	//( - , DU) Переключатель ВЫБОР ЗОН
#define idR0MW13IP1	 488	//( - , DU) Переключатель ВЫБОР ЗОН
#define R0MW16IP1	 BUFFER[1178]	//( - , DU) Переключатель ВИД ПРОВЕРКИ
#define idR0MW16IP1	 489	//( - , DU) Переключатель ВИД ПРОВЕРКИ
#define R0MW11IP1	 BUFFER[1181]	//( - , DU) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	 490	//( - , DU) Переключатель ВЫСТРЕЛ
#define R0MW11IP2	 BUFFER[1184]	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
#define idR0MW11IP2	 491	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
#define R0MW13LP2	 BUFFER[1187]	//( - , DU) Переключатель СЕТЬ
#define idR0MW13LP2	 492	//( - , DU) Переключатель СЕТЬ
#define R0MD32LP1	 BUFFER[1189]	//( - , DU) Кнопка СПУСК
#define idR0MD32LP1	 493	//( - , DU) Кнопка СПУСК
#define R0MD31LP1	 BUFFER[1191]	//( - , DU) Кнопка СТОП
#define idR0MD31LP1	 494	//( - , DU) Кнопка СТОП
#define A1IS21LDU	 BUFFER[1193]	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
#define idA1IS21LDU	 495	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
#define A2IS21LDU	 BUFFER[1195]	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
#define idA2IS21LDU	 496	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
#define A3IS21LDU	 BUFFER[1197]	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
#define idA3IS21LDU	 497	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
#define B1IS21LDU	 BUFFER[1199]	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
#define idB1IS21LDU	 498	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
#define B2IS21LDU	 BUFFER[1201]	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
#define idB2IS21LDU	 499	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
#define B3IS21LDU	 BUFFER[1203]	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
#define idB3IS21LDU	 500	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
#define R0ES01LDU	 BUFFER[1205]	//( - , DU) ОРР не в исходном состоянии
#define idR0ES01LDU	 501	//( - , DU) ОРР не в исходном состоянии
#define R4MD11LP2	 BUFFER[1207]	//( - , DU) Кнопка ВПЕРЁД  (тележки)
#define idR4MD11LP2	 502	//( - , DU) Кнопка ВПЕРЁД  (тележки)
#define R4MD31LP2	 BUFFER[1209]	//( - , DU) Кнопка СТОП  (тележки)
#define idR4MD31LP2	 503	//( - , DU) Кнопка СТОП  (тележки)
#define R4MD21LP2	 BUFFER[1211]	//( - , DU) Кнопка НАЗАД  (тележки)
#define idR4MD21LP2	 504	//( - , DU) Кнопка НАЗАД  (тележки)
#define A6IS11LDU	 BUFFER[1213]	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
#define idA6IS11LDU	 505	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
#define A6IS21LDU	 BUFFER[1215]	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
#define idA6IS21LDU	 506	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
#define B6IS11LDU	 BUFFER[1217]	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
#define idB6IS11LDU	 507	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
#define B4IS11LDU	 BUFFER[1219]	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
#define idB4IS11LDU	 508	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
#define R4AB13LDU	 BUFFER[1221]	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
#define idR4AB13LDU	 509	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
#define R4AB14LDU	 BUFFER[1223]	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
#define idR4AB14LDU	 510	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
#define R4AB15LDU	 BUFFER[1225]	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
#define idR4AB15LDU	 511	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
#define R5IS11LDU	 BUFFER[1227]	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	 512	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
#define R4AB16LDU	 BUFFER[1229]	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
#define idR4AB16LDU	 513	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
#define R4AB17LDU	 BUFFER[1231]	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define idR4AB17LDU	 514	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define R4AB18LDU	 BUFFER[1233]	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define idR4AB18LDU	 515	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define R4AD10LDU	 BUFFER[1235]	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
#define idR4AD10LDU	 516	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
#define R4AD20LDU	 BUFFER[1237]	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
#define idR4AD20LDU	 517	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
#define A5VS22LDU	 BUFFER[1239]	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
#define idA5VS22LDU	 518	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
#define A5VS12LDU	 BUFFER[1241]	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
#define idA5VS12LDU	 519	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
#define B5VS22LDU	 BUFFER[1243]	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
#define idB5VS22LDU	 520	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
#define B5VS12LDU	 BUFFER[1245]	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
#define idB5VS12LDU	 521	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
#define B5AD10LDU	 BUFFER[1247]	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
#define idB5AD10LDU	 522	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
#define B5AD20LDU	 BUFFER[1249]	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
#define idB5AD20LDU	 523	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
#define A5AD10LDU	 BUFFER[1251]	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
#define idA5AD10LDU	 524	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
#define A5AD20LDU	 BUFFER[1253]	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
#define idA5AD20LDU	 525	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
#define A5IS11LDU	 BUFFER[1255]	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
#define idA5IS11LDU	 526	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
#define A5IS21LDU	 BUFFER[1257]	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
#define idA5IS21LDU	 527	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
#define B5IS11LDU	 BUFFER[1259]	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
#define idB5IS11LDU	 528	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
#define B5IS21LDU	 BUFFER[1261]	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
#define idB5IS21LDU	 529	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
#define A5AZ03LDU	 BUFFER[1263]	//( - , DU) Несанкционированное перемещение НЛ1
#define idA5AZ03LDU	 530	//( - , DU) Несанкционированное перемещение НЛ1
#define R0NE02LDU	 BUFFER[1265]	//( - , DU) Потеря связи с БАЗ2
#define idR0NE02LDU	 531	//( - , DU) Потеря связи с БАЗ2
#define R4AB02LDU	 BUFFER[1267]	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
#define idR4AB02LDU	 532	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
#define R0NE08LDU	 BUFFER[1269]	//( - , DU) Потеря связи с ОПУ
#define idR0NE08LDU	 533	//( - , DU) Потеря связи с ОПУ
#define R4IS21LDU	 BUFFER[1271]	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
#define idR4IS21LDU	 534	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
#define R4IS22LDU	 BUFFER[1273]	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
#define idR4IS22LDU	 535	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
#define R4IS12LDU	 BUFFER[1275]	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
#define idR4IS12LDU	 536	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
#define R4VS22LDU	 BUFFER[1277]	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
#define idR4VS22LDU	 537	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
#define R4VS12LDU	 BUFFER[1279]	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
#define idR4VS12LDU	 538	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
#define R4AZ03LDU	 BUFFER[1281]	//( - , DU) Несанкционированное перемещение тележки
#define idR4AZ03LDU	 539	//( - , DU) Несанкционированное перемещение тележки
#define R4AB03LDU	 BUFFER[1283]	//( - , DU) Блокировка движения тележки - Самоход любого механизма
#define idR4AB03LDU	 540	//( - , DU) Блокировка движения тележки - Самоход любого механизма
#define R1IS21LDU	 BUFFER[1285]	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
#define idR1IS21LDU	 541	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
#define R2IS21LDU	 BUFFER[1287]	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
#define idR2IS21LDU	 542	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
#define R4AB04LDU	 BUFFER[1289]	//( - , DU) Блокировка движения тележки - Превышение времени движения
#define idR4AB04LDU	 543	//( - , DU) Блокировка движения тележки - Превышение времени движения
#define R4AB05LDU	 BUFFER[1291]	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
#define idR4AB05LDU	 544	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
#define R4AB06LDU	 BUFFER[1293]	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
#define idR4AB06LDU	 545	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
#define R4AB07LDU	 BUFFER[1295]	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
#define idR4AB07LDU	 546	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
#define R4AB08LDU	 BUFFER[1297]	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define idR4AB08LDU	 547	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define R4AB09LDU	 BUFFER[1299]	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
#define idR4AB09LDU	 548	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
#define B0VN71LZ1	 BUFFER[1301]	//( - , MDuBz1) АЗ по АС мощности для АЗ2
#define idB0VN71LZ1	 549	//( - , MDuBz1) АЗ по АС мощности для АЗ2
#define B0VN71LZ2	 BUFFER[1303]	//( - , MDuBz2) АЗ по АС мощности для АЗ2
#define idB0VN71LZ2	 550	//( - , MDuBz2) АЗ по АС мощности для АЗ2
#define R4AB10LDU	 BUFFER[1305]	//( - , DU) Блокировка тележки - не открыта биологическая защита
#define idR4AB10LDU	 551	//( - , DU) Блокировка тележки - не открыта биологическая защита
#define R4AB11LDU	 BUFFER[1307]	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
#define idR4AB11LDU	 552	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
#define R4AB12LDU	 BUFFER[1309]	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
#define idR4AB12LDU	 553	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
#define A4IS11LDU	 BUFFER[1311]	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
#define idA4IS11LDU	 554	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
#define A3AD03LDU	 BUFFER[1313]	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
#define idA3AD03LDU	 555	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
#define A3AD04LDU	 BUFFER[1315]	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
#define idA3AD04LDU	 556	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
#define A3AD05LDU	 BUFFER[1317]	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
#define idA3AD05LDU	 557	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
#define A3AD01LDU	 BUFFER[1319]	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
#define idA3AD01LDU	 558	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
#define A3CV02RDU	 BUFFER[1321]	//( - , DU) Заданная скорость перемещения ИС1
#define idA3CV02RDU	 559	//( - , DU) Заданная скорость перемещения ИС1
#define A3AB07LDU	 BUFFER[1326]	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
#define idA3AB07LDU	 560	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
#define A3AB08LDU	 BUFFER[1328]	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
#define idA3AB08LDU	 561	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
#define A3AB05LDU	 BUFFER[1330]	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
#define idA3AB05LDU	 562	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
#define A3AB06LDU	 BUFFER[1332]	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
#define idA3AB06LDU	 563	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
#define A3AB09LDU	 BUFFER[1334]	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
#define idA3AB09LDU	 564	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
#define A3AB10LDU	 BUFFER[1336]	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
#define idA3AB10LDU	 565	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
#define A3AB11LDU	 BUFFER[1338]	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
#define idA3AB11LDU	 566	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
#define A3AB12LDU	 BUFFER[1340]	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA3AB12LDU	 567	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A3AB14LDU	 BUFFER[1342]	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
#define idA3AB14LDU	 568	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
#define A3AB16LDU	 BUFFER[1344]	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
#define idA3AB16LDU	 569	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
#define A3AB17LDU	 BUFFER[1346]	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
#define idA3AB17LDU	 570	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
#define A3AB18LDU	 BUFFER[1348]	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
#define idA3AB18LDU	 571	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
#define A3AB20LDU	 BUFFER[1350]	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
#define idA3AB20LDU	 572	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
#define B3VS12LDU	 BUFFER[1352]	//( - , DU) Движение ИС2 в сторону ВУ
#define idB3VS12LDU	 573	//( - , DU) Движение ИС2 в сторону ВУ
#define B3AB04LDU	 BUFFER[1354]	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
#define idB3AB04LDU	 574	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
#define B3AB02LDU	 BUFFER[1356]	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
#define idB3AB02LDU	 575	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
#define B3AB01LDU	 BUFFER[1358]	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
#define idB3AB01LDU	 576	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
#define B3VS22LDU	 BUFFER[1360]	//( - , DU) Движение ИС2 в сторону НУ
#define idB3VS22LDU	 577	//( - , DU) Движение ИС2 в сторону НУ
#define B1AB07LDU	 BUFFER[1362]	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
#define idB1AB07LDU	 578	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
#define B1AB08LDU	 BUFFER[1364]	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
#define idB1AB08LDU	 579	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
#define B1AB05LDU	 BUFFER[1366]	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
#define idB1AB05LDU	 580	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
#define B1AB06LDU	 BUFFER[1368]	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
#define idB1AB06LDU	 581	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
#define B1AB09LDU	 BUFFER[1370]	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
#define idB1AB09LDU	 582	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
#define B1AB10LDU	 BUFFER[1372]	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
#define idB1AB10LDU	 583	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
#define B1AB11LDU	 BUFFER[1374]	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
#define idB1AB11LDU	 584	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
#define B1AB12LDU	 BUFFER[1376]	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idB1AB12LDU	 585	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define B1AB13LDU	 BUFFER[1378]	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
#define idB1AB13LDU	 586	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
#define B1AB14LDU	 BUFFER[1380]	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
#define idB1AB14LDU	 587	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
#define B1AB16LDU	 BUFFER[1382]	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
#define idB1AB16LDU	 588	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
#define B1AB17LDU	 BUFFER[1384]	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
#define idB1AB17LDU	 589	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
#define B1AB18LDU	 BUFFER[1386]	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
#define idB1AB18LDU	 590	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
#define A3VS12LDU	 BUFFER[1388]	//( - , DU) Движение ИС1 в сторону ВУ
#define idA3VS12LDU	 591	//( - , DU) Движение ИС1 в сторону ВУ
#define A3CV01RDU	 BUFFER[1390]	//( - , DU) Измеренная скорость перемещения ИС1
#define idA3CV01RDU	 592	//( - , DU) Измеренная скорость перемещения ИС1
#define A3AB04LDU	 BUFFER[1395]	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
#define idA3AB04LDU	 593	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
#define A3AB02LDU	 BUFFER[1397]	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
#define idA3AB02LDU	 594	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
#define A3AB01LDU	 BUFFER[1399]	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
#define idA3AB01LDU	 595	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
#define A3VS22LDU	 BUFFER[1401]	//( - , DU) Движение ИС1 в сторону НУ
#define idA3VS22LDU	 596	//( - , DU) Движение ИС1 в сторону НУ
#define A3AZ03LDU	 BUFFER[1403]	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
#define idA3AZ03LDU	 597	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
#define A3AD11LDU	 BUFFER[1405]	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	 598	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
#define A3AD21LDU	 BUFFER[1407]	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	 599	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
#define A3AD02LDU	 BUFFER[1409]	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
#define idA3AD02LDU	 600	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
#define C1MD31LP2	 BUFFER[1411]	//( - , DU) Кнопка СБРОС ББ
#define idC1MD31LP2	 601	//( - , DU) Кнопка СБРОС ББ
#define A2AD31LDU	 BUFFER[1413]	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
#define idA2AD31LDU	 602	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
#define B2AD31LDU	 BUFFER[1415]	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
#define idB2AD31LDU	 603	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
#define A1AD31LDU	 BUFFER[1417]	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
#define idA1AD31LDU	 604	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
#define B1AD31LDU	 BUFFER[1419]	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
#define idB1AD31LDU	 605	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
#define A2AD32LDU	 BUFFER[1421]	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
#define idA2AD32LDU	 606	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
#define B2AD32LDU	 BUFFER[1423]	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
#define idB2AD32LDU	 607	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
#define A1AD32LDU	 BUFFER[1425]	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
#define idA1AD32LDU	 608	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
#define B1AD32LDU	 BUFFER[1427]	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
#define idB1AD32LDU	 609	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
#define R0MD11LP2	 BUFFER[1429]	//( - , DU) Кнопка Пуск проверки схем сброса
#define idR0MD11LP2	 610	//( - , DU) Кнопка Пуск проверки схем сброса
#define R0VX01LDU	 BUFFER[1431]	//( - , DU) ДО ИМПУЛЬСА
#define idR0VX01LDU	 611	//( - , DU) ДО ИМПУЛЬСА
#define R0VL01IDU	 BUFFER[1433]	//( - , DU) До импульса минут
#define idR0VL01IDU	 612	//( - , DU) До импульса минут
#define R0VL11IDU	 BUFFER[1436]	//( - , DU) До импульса секунд
#define idR0VL11IDU	 613	//( - , DU) До импульса секунд
#define R0VL06RDU	 BUFFER[1439]	//( - , DU) Индикация (Время задержки от ВУ РБ)
#define idR0VL06RDU	 614	//( - , DU) Индикация (Время задержки от ВУ РБ)
#define B3AD33LDU	 BUFFER[1444]	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define idB3AD33LDU	 615	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define R0VL02RDU	 BUFFER[1446]	//( - , DU) Индикация (Время задержки ИНИ)
#define idR0VL02RDU	 616	//( - , DU) Индикация (Время задержки ИНИ)
#define R0AD14LDU	 BUFFER[1451]	//( - , DU) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 617	//( - , DU) Имитация срабатывания верхней АС II УР
#define R0VL04RDU	 BUFFER[1453]	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
#define idR0VL04RDU	 618	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
#define R0AB04LDU	 BUFFER[1458]	//( - , DU) Нарушение времени срабатывания верхней АС II УР
#define idR0AB04LDU	 619	//( - , DU) Нарушение времени срабатывания верхней АС II УР
#define R0AB06LDU	 BUFFER[1460]	//( - , DU) Нарушение времени задержки от ВУ РБ
#define idR0AB06LDU	 620	//( - , DU) Нарушение времени задержки от ВУ РБ
#define R0AB02LDU	 BUFFER[1462]	//( - , DU) Нарушение времени задержки ИНИ
#define idR0AB02LDU	 621	//( - , DU) Нарушение времени задержки ИНИ
#define R0VL03RDU	 BUFFER[1464]	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define idR0VL03RDU	 622	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define R0VL05RDU	 BUFFER[1469]	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
#define idR0VL05RDU	 623	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
#define B3AZ03LDU	 BUFFER[1474]	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
#define idB3AZ03LDU	 624	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
#define B3AD11LDU	 BUFFER[1476]	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	 625	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
#define B3AD21LDU	 BUFFER[1478]	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	 626	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
#define B3AD02LDU	 BUFFER[1480]	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
#define idB3AD02LDU	 627	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
#define B3AD03LDU	 BUFFER[1482]	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
#define idB3AD03LDU	 628	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
#define B3AD04LDU	 BUFFER[1484]	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
#define idB3AD04LDU	 629	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
#define B3AD05LDU	 BUFFER[1486]	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
#define idB3AD05LDU	 630	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
#define B3AD01LDU	 BUFFER[1488]	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
#define idB3AD01LDU	 631	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
#define B3CV02RDU	 BUFFER[1490]	//( - , DU) Заданная скорость перемещения ИС2
#define idB3CV02RDU	 632	//( - , DU) Заданная скорость перемещения ИС2
#define B3AB07LDU	 BUFFER[1495]	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
#define idB3AB07LDU	 633	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
#define B3AB08LDU	 BUFFER[1497]	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
#define idB3AB08LDU	 634	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
#define B3AB05LDU	 BUFFER[1499]	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
#define idB3AB05LDU	 635	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
#define B3AB06LDU	 BUFFER[1501]	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
#define idB3AB06LDU	 636	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
#define B3AB09LDU	 BUFFER[1503]	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
#define idB3AB09LDU	 637	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
#define B3AB10LDU	 BUFFER[1505]	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
#define idB3AB10LDU	 638	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
#define B3AB11LDU	 BUFFER[1507]	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
#define idB3AB11LDU	 639	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
#define B3AB12LDU	 BUFFER[1509]	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define idB3AB12LDU	 640	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define B3AB14LDU	 BUFFER[1511]	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
#define idB3AB14LDU	 641	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
#define B3AB16LDU	 BUFFER[1513]	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
#define idB3AB16LDU	 642	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
#define B3AB17LDU	 BUFFER[1515]	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
#define idB3AB17LDU	 643	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
#define B3AB18LDU	 BUFFER[1517]	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
#define idB3AB18LDU	 644	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
#define B3AB20LDU	 BUFFER[1519]	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
#define idB3AB20LDU	 645	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
#define C1MD31LP1	 BUFFER[1521]	//( - , DU) Кнопка СБРОС ББ
#define idC1MD31LP1	 646	//( - , DU) Кнопка СБРОС ББ
#define B2AB08LDU	 BUFFER[1523]	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
#define idB2AB08LDU	 647	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
#define B2AB05LDU	 BUFFER[1525]	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
#define idB2AB05LDU	 648	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
#define B2AB06LDU	 BUFFER[1527]	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
#define idB2AB06LDU	 649	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
#define B2AB09LDU	 BUFFER[1529]	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
#define idB2AB09LDU	 650	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
#define B2AB10LDU	 BUFFER[1531]	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
#define idB2AB10LDU	 651	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
#define B2AB11LDU	 BUFFER[1533]	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
#define idB2AB11LDU	 652	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
#define B2AB12LDU	 BUFFER[1535]	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define idB2AB12LDU	 653	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define B2AB13LDU	 BUFFER[1537]	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
#define idB2AB13LDU	 654	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
#define B2AB14LDU	 BUFFER[1539]	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
#define idB2AB14LDU	 655	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
#define B2AB16LDU	 BUFFER[1541]	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
#define idB2AB16LDU	 656	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
#define B2AB17LDU	 BUFFER[1543]	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
#define idB2AB17LDU	 657	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
#define R1AZ03LDU	 BUFFER[1545]	//( - , DU) Несанкционированное перемещение МДЗ1
#define idR1AZ03LDU	 658	//( - , DU) Несанкционированное перемещение МДЗ1
#define R1AB01LDU	 BUFFER[1547]	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
#define idR1AB01LDU	 659	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
#define R1AB02LDU	 BUFFER[1549]	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
#define idR1AB02LDU	 660	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
#define R2AZ03LDU	 BUFFER[1551]	//( - , DU) Несанкционированное перемещение МДЗ2
#define idR2AZ03LDU	 661	//( - , DU) Несанкционированное перемещение МДЗ2
#define R2AB01LDU	 BUFFER[1553]	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
#define idR2AB01LDU	 662	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
#define R2AB02LDU	 BUFFER[1555]	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
#define idR2AB02LDU	 663	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
#define R1AB04LDU	 BUFFER[1557]	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
#define idR1AB04LDU	 664	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
#define R2AB04LDU	 BUFFER[1559]	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
#define idR2AB04LDU	 665	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
#define R1AD10LDU	 BUFFER[1561]	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
#define idR1AD10LDU	 666	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
#define R1AD20LDU	 BUFFER[1563]	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
#define idR1AD20LDU	 667	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
#define R1IS11LDU	 BUFFER[1565]	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
#define idR1IS11LDU	 668	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
#define R1VS22LDU	 BUFFER[1567]	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	 669	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
#define A2AB10LDU	 BUFFER[1569]	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
#define idA2AB10LDU	 670	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
#define A2AB11LDU	 BUFFER[1571]	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
#define idA2AB11LDU	 671	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
#define A2AB12LDU	 BUFFER[1573]	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA2AB12LDU	 672	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A2AB13LDU	 BUFFER[1575]	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
#define idA2AB13LDU	 673	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
#define A2AB14LDU	 BUFFER[1577]	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
#define idA2AB14LDU	 674	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
#define A2AB16LDU	 BUFFER[1579]	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
#define idA2AB16LDU	 675	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
#define A2AB17LDU	 BUFFER[1581]	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
#define idA2AB17LDU	 676	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
#define A2AD01LDU	 BUFFER[1583]	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
#define idA2AD01LDU	 677	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
#define A2CV02RDU	 BUFFER[1585]	//( - , DU) Заданная скорость перемещения РБ1
#define idA2CV02RDU	 678	//( - , DU) Заданная скорость перемещения РБ1
#define B2CV01RDU	 BUFFER[1590]	//( - , DU) Измеренная скорость перемещения РБ2
#define idB2CV01RDU	 679	//( - , DU) Измеренная скорость перемещения РБ2
#define B2AB04LDU	 BUFFER[1595]	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
#define idB2AB04LDU	 680	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
#define B2AB02LDU	 BUFFER[1597]	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
#define idB2AB02LDU	 681	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
#define B2AB01LDU	 BUFFER[1599]	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
#define idB2AB01LDU	 682	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
#define B2AZ03LDU	 BUFFER[1601]	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
#define idB2AZ03LDU	 683	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
#define B2AD11LDU	 BUFFER[1603]	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	 684	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
#define B2AD21LDU	 BUFFER[1605]	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	 685	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
#define B2AD02LDU	 BUFFER[1607]	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
#define idB2AD02LDU	 686	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
#define B2AD03LDU	 BUFFER[1609]	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
#define idB2AD03LDU	 687	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
#define B2AD04LDU	 BUFFER[1611]	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
#define idB2AD04LDU	 688	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
#define B2AD05LDU	 BUFFER[1613]	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
#define idB2AD05LDU	 689	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
#define B2AD01LDU	 BUFFER[1615]	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
#define idB2AD01LDU	 690	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
#define B2CV02RDU	 BUFFER[1617]	//( - , DU) Заданная скорость перемещения РБ2
#define idB2CV02RDU	 691	//( - , DU) Заданная скорость перемещения РБ2
#define B2AB07LDU	 BUFFER[1622]	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
#define idB2AB07LDU	 692	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
#define A1AB10LDU	 BUFFER[1624]	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
#define idA1AB10LDU	 693	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
#define A1AB11LDU	 BUFFER[1626]	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
#define idA1AB11LDU	 694	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
#define A1AB12LDU	 BUFFER[1628]	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA1AB12LDU	 695	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A1AB13LDU	 BUFFER[1630]	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
#define idA1AB13LDU	 696	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
#define A1AB14LDU	 BUFFER[1632]	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
#define idA1AB14LDU	 697	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
#define A1AB16LDU	 BUFFER[1634]	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
#define idA1AB16LDU	 698	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
#define A1AB17LDU	 BUFFER[1636]	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
#define idA1AB17LDU	 699	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
#define A1AB18LDU	 BUFFER[1638]	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
#define idA1AB18LDU	 700	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
#define B1VS12LDU	 BUFFER[1640]	//( - , DU) Движение ББ2 в сторону ВУ
#define idB1VS12LDU	 701	//( - , DU) Движение ББ2 в сторону ВУ
#define B1CV01RDU	 BUFFER[1642]	//( - , DU) Измеренная скорость перемещения ББ2
#define idB1CV01RDU	 702	//( - , DU) Измеренная скорость перемещения ББ2
#define B1AB04LDU	 BUFFER[1647]	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
#define idB1AB04LDU	 703	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
#define B1AB02LDU	 BUFFER[1649]	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
#define idB1AB02LDU	 704	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
#define B1AB01LDU	 BUFFER[1651]	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
#define idB1AB01LDU	 705	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
#define B1VS22LDU	 BUFFER[1653]	//( - , DU) Движение ББ2 в сторону НУ
#define idB1VS22LDU	 706	//( - , DU) Движение ББ2 в сторону НУ
#define B1AZ03LDU	 BUFFER[1655]	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
#define idB1AZ03LDU	 707	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
#define B1AD11LDU	 BUFFER[1657]	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	 708	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
#define B1AD21LDU	 BUFFER[1659]	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	 709	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
#define B1AD02LDU	 BUFFER[1661]	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
#define idB1AD02LDU	 710	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
#define B1AD03LDU	 BUFFER[1663]	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
#define idB1AD03LDU	 711	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
#define B1AD04LDU	 BUFFER[1665]	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
#define idB1AD04LDU	 712	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
#define B1AD05LDU	 BUFFER[1667]	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
#define idB1AD05LDU	 713	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
#define B1AD01LDU	 BUFFER[1669]	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
#define idB1AD01LDU	 714	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
#define B1CV02RDU	 BUFFER[1671]	//( - , DU) Заданная скорость перемещения ББ2
#define idB1CV02RDU	 715	//( - , DU) Заданная скорость перемещения ББ2
#define R2VS22LDU	 BUFFER[1676]	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	 716	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
#define R2VS12LDU	 BUFFER[1678]	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	 717	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
#define R1VS12LDU	 BUFFER[1680]	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	 718	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
#define R2IS11LDU	 BUFFER[1682]	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
#define idR2IS11LDU	 719	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
#define A1VS12LDU	 BUFFER[1684]	//( - , DU) Движение ББ1 в сторону ВУ
#define idA1VS12LDU	 720	//( - , DU) Движение ББ1 в сторону ВУ
#define A1CV01RDU	 BUFFER[1686]	//( - , DU) Измеренная скорость перемещения ББ1
#define idA1CV01RDU	 721	//( - , DU) Измеренная скорость перемещения ББ1
#define A1AB04LDU	 BUFFER[1691]	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
#define idA1AB04LDU	 722	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
#define A1AB02LDU	 BUFFER[1693]	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
#define idA1AB02LDU	 723	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
#define A1AB01LDU	 BUFFER[1695]	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
#define idA1AB01LDU	 724	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
#define A1VS22LDU	 BUFFER[1697]	//( - , DU) Движение ББ1 в сторону НУ
#define idA1VS22LDU	 725	//( - , DU) Движение ББ1 в сторону НУ
#define A1AZ03LDU	 BUFFER[1699]	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
#define idA1AZ03LDU	 726	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
#define A1AD11LDU	 BUFFER[1701]	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	 727	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
#define A1AD21LDU	 BUFFER[1703]	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	 728	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
#define A1AD02LDU	 BUFFER[1705]	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
#define idA1AD02LDU	 729	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
#define A1AD03LDU	 BUFFER[1707]	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
#define idA1AD03LDU	 730	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
#define A1AD04LDU	 BUFFER[1709]	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
#define idA1AD04LDU	 731	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
#define A1AD05LDU	 BUFFER[1711]	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
#define idA1AD05LDU	 732	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
#define A1AD01LDU	 BUFFER[1713]	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
#define idA1AD01LDU	 733	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
#define A1CV02RDU	 BUFFER[1715]	//( - , DU) Заданная скорость перемещения ББ1
#define idA1CV02RDU	 734	//( - , DU) Заданная скорость перемещения ББ1
#define A1AB07LDU	 BUFFER[1720]	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
#define idA1AB07LDU	 735	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
#define A1AB08LDU	 BUFFER[1722]	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
#define idA1AB08LDU	 736	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
#define A1AB05LDU	 BUFFER[1724]	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
#define idA1AB05LDU	 737	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
#define A1AB06LDU	 BUFFER[1726]	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
#define idA1AB06LDU	 738	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
#define A1AB09LDU	 BUFFER[1728]	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
#define idA1AB09LDU	 739	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
#define fEM_A1UC03RDU	 BUFFER[1730]	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define idfEM_A1UC03RDU	 740	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define dEM_A1UC05UDU	 BUFFER[1735]	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC05UDU	 741	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define dEM_A1UC06UDU	 BUFFER[1740]	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC06UDU	 742	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define dEM_A2UC06UDU	 BUFFER[1745]	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC06UDU	 743	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define dEM_A2UC05UDU	 BUFFER[1750]	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC05UDU	 744	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define fEM_A2UC03RDU	 BUFFER[1755]	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define idfEM_A2UC03RDU	 745	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define dEM_A3UC06UDU	 BUFFER[1760]	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC06UDU	 746	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define dEM_A3UC05UDU	 BUFFER[1765]	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC05UDU	 747	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define fEM_A3UC03RDU	 BUFFER[1770]	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define idfEM_A3UC03RDU	 748	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define dEM_A8UC06UDU	 BUFFER[1775]	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define iddEM_A8UC06UDU	 749	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define fEM_A8UC03RDU	 BUFFER[1780]	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
#define idfEM_A8UC03RDU	 750	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
#define dEM_A8UC05UDU	 BUFFER[1785]	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define iddEM_A8UC05UDU	 751	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define fEM_R0UV81RDU	 BUFFER[1790]	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	 752	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	 BUFFER[1795]	//(R0UV82RDU) 2-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	 753	//(R0UV82RDU) 2-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	 BUFFER[1800]	//(R0UV83RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	 754	//(R0UV83RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	 BUFFER[1805]	//(R0UV84RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	 755	//(R0UV84RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV86RDU	 BUFFER[1810]	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	 756	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV85RDU	 BUFFER[1815]	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	 757	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV87RDU	 BUFFER[1820]	//(R0UV87RDU) 8-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	 758	//(R0UV87RDU) 8-я скорость перемещения ББ (шагов/секунду)
#define fEM_A3UP03RDU	 BUFFER[1825]	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	 759	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	 BUFFER[1830]	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	 760	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP43RDU	 BUFFER[1835]	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define idfEM_A3UP43RDU	 761	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define fEM_A3UP44RDU	 BUFFER[1840]	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP44RDU	 762	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP53RDU	 BUFFER[1845]	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP53RDU	 763	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP85RDU	 BUFFER[1850]	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP85RDU	 764	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP88RDU	 BUFFER[1855]	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP88RDU	 765	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP86RDU	 BUFFER[1860]	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP86RDU	 766	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_B8UV01RDU	 BUFFER[1865]	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
#define idfEM_B8UV01RDU	 767	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
#define fEM_B8UV02RDU	 BUFFER[1870]	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
#define idfEM_B8UV02RDU	 768	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
#define fEM_B8UV03RDU	 BUFFER[1875]	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
#define idfEM_B8UV03RDU	 769	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
#define fEM_B8UL04RDU	 BUFFER[1880]	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
#define idfEM_B8UL04RDU	 770	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
#define iEM_A2UV03CDU	 BUFFER[1885]	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define idiEM_A2UV03CDU	 771	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define fEM_A2UV01RDU	 BUFFER[1888]	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define idfEM_A2UV01RDU	 772	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define fEM_A2UV02RDU	 BUFFER[1893]	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define idfEM_A2UV02RDU	 773	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define fEM_A1UV01RDU	 BUFFER[1898]	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define idfEM_A1UV01RDU	 774	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define fEM_A1UV02RDU	 BUFFER[1903]	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define idfEM_A1UV02RDU	 775	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define fEM_A1UC06RDU	 BUFFER[1908]	//(A1UC06RDU) Уставка определения самохода ББ  мм
#define idfEM_A1UC06RDU	 776	//(A1UC06RDU) Уставка определения самохода ББ  мм
#define fEM_A1UC05RDU	 BUFFER[1913]	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A1UC05RDU	 777	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A1UL04RDU	 BUFFER[1918]	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define idfEM_A1UL04RDU	 778	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define fEM_A3UV01RDU	 BUFFER[1923]	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
#define idfEM_A3UV01RDU	 779	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
#define fEM_A3UV02RDU	 BUFFER[1928]	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
#define idfEM_A3UV02RDU	 780	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
#define fEM_A3UC06RDU	 BUFFER[1933]	//(A3UC06RDU) Уставка определения самохода ИС1  мм
#define idfEM_A3UC06RDU	 781	//(A3UC06RDU) Уставка определения самохода ИС1  мм
#define fEM_A3UC05RDU	 BUFFER[1938]	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A3UC05RDU	 782	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define fEM_A3UL04RDU	 BUFFER[1943]	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define idfEM_A3UL04RDU	 783	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define fEM_A3UP54RDU	 BUFFER[1948]	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define idfEM_A3UP54RDU	 784	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define fEM_A3UP87RDU	 BUFFER[1953]	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP87RDU	 785	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_R0UL05RDU	 BUFFER[1958]	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
#define idfEM_R0UL05RDU	 786	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
#define fEM_R0UL20RDU	 BUFFER[1963]	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
#define idfEM_R0UL20RDU	 787	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
#define fEM_B8UV04RDU	 BUFFER[1968]	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
#define idfEM_B8UV04RDU	 788	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
#define fEM_B8UC06RDU	 BUFFER[1973]	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
#define idfEM_B8UC06RDU	 789	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
#define fEM_B8UC05RDU	 BUFFER[1978]	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
#define idfEM_B8UC05RDU	 790	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
#define fEM_A2UL05RDU	 BUFFER[1983]	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define idfEM_A2UL05RDU	 791	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define fEM_A2UL03RDU	 BUFFER[1988]	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL03RDU	 792	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A2UC06RDU	 BUFFER[1993]	//(A2UC06RDU) Уставка определения самохода РБ  мм
#define idfEM_A2UC06RDU	 793	//(A2UC06RDU) Уставка определения самохода РБ  мм
#define fEM_A2UC05RDU	 BUFFER[1998]	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A2UC05RDU	 794	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A2UL04RDU	 BUFFER[2003]	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define idfEM_A2UL04RDU	 795	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define fEM_A1UL03RDU	 BUFFER[2008]	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define idfEM_A1UL03RDU	 796	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define fEM_A1UL05RDU	 BUFFER[2013]	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define idfEM_A1UL05RDU	 797	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define fEM_A3UL03RDU	 BUFFER[2018]	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define idfEM_A3UL03RDU	 798	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define fEM_A3UL05RDU	 BUFFER[2023]	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define idfEM_A3UL05RDU	 799	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define fEM_A1UC08RDU	 BUFFER[2028]	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define idfEM_A1UC08RDU	 800	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define fEM_A3UC08RDU	 BUFFER[2033]	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define idfEM_A3UC08RDU	 801	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define fEM_A1UC07RDU	 BUFFER[2038]	//(A1UC07RDU) Зона возврата при наведении ББ мм
#define idfEM_A1UC07RDU	 802	//(A1UC07RDU) Зона возврата при наведении ББ мм
#define fEM_A1UL01RDU	 BUFFER[2043]	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A1UL01RDU	 803	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A3UC07RDU	 BUFFER[2048]	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define idfEM_A3UC07RDU	 804	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define fEM_A3UL01RDU	 BUFFER[2053]	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A3UL01RDU	 805	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A2UC08RDU	 BUFFER[2058]	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define idfEM_A2UC08RDU	 806	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define fEM_A2UC07RDU	 BUFFER[2063]	//(A2UC07RDU) Зона возврата при наведении РБ  мм
#define idfEM_A2UC07RDU	 807	//(A2UC07RDU) Зона возврата при наведении РБ  мм
#define fEM_A2UL01RDU	 BUFFER[2068]	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A2UL01RDU	 808	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_B8UC01RDU	 BUFFER[2073]	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
#define idfEM_B8UC01RDU	 809	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
#define fEM_B8UL07RDU	 BUFFER[2078]	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
#define idfEM_B8UL07RDU	 810	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
#define fEM_B8UC02RDU	 BUFFER[2083]	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
#define idfEM_B8UC02RDU	 811	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
#define fEM_B8UL01RDU	 BUFFER[2088]	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_B8UL01RDU	 812	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_B8UL05RDU	 BUFFER[2093]	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
#define idfEM_B8UL05RDU	 813	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
#define fEM_B8UL03RDU	 BUFFER[2098]	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
#define idfEM_B8UL03RDU	 814	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
#define fEM_B8UL06RDU	 BUFFER[2103]	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
#define idfEM_B8UL06RDU	 815	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
#define fEM_A9UZ03RDU	 BUFFER[2108]	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
#define idfEM_A9UZ03RDU	 816	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
#define fEM_A9UZ04RDU	 BUFFER[2113]	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
#define idfEM_A9UZ04RDU	 817	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
#define fEM_A9UZ05RDU	 BUFFER[2118]	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
#define idfEM_A9UZ05RDU	 818	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
#define fEM_R4UZ04RDU	 BUFFER[2123]	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define idfEM_R4UZ04RDU	 819	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define fEM_R4UZ03RDU	 BUFFER[2128]	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define idfEM_R4UZ03RDU	 820	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define fEM_R4UZ05RDU	 BUFFER[2133]	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define idfEM_R4UZ05RDU	 821	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define fEM_A5UZ03RDU	 BUFFER[2138]	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
#define idfEM_A5UZ03RDU	 822	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
#define fEM_A5UZ04RDU	 BUFFER[2143]	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
#define idfEM_A5UZ04RDU	 823	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
#define fEM_A5UZ05RDU	 BUFFER[2148]	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
#define idfEM_A5UZ05RDU	 824	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
#define fEM_A4UZ03RDU	 BUFFER[2153]	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
#define idfEM_A4UZ03RDU	 825	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
#define fEM_A4UZ04RDU	 BUFFER[2158]	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
#define idfEM_A4UZ04RDU	 826	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
#define fEM_A4UZ05RDU	 BUFFER[2163]	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
#define idfEM_A4UZ05RDU	 827	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
#define fEM_A6UZ03RDU	 BUFFER[2168]	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
#define idfEM_A6UZ03RDU	 828	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
#define fEM_A6UZ04RDU	 BUFFER[2173]	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
#define idfEM_A6UZ04RDU	 829	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
#define fEM_A6UZ05RDU	 BUFFER[2178]	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
#define idfEM_A6UZ05RDU	 830	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
#define fEM_R1UZ03RDU	 BUFFER[2183]	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define idfEM_R1UZ03RDU	 831	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define fEM_R1UZ04RDU	 BUFFER[2188]	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define idfEM_R1UZ04RDU	 832	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define fEM_R1UZ05RDU	 BUFFER[2193]	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define idfEM_R1UZ05RDU	 833	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define fEM_R0UL04RDU	 BUFFER[2198]	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
#define idfEM_R0UL04RDU	 834	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
#define fEM_R0UL06RDU	 BUFFER[2203]	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
#define idfEM_R0UL06RDU	 835	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
#define fEM_R0UL03RDU	 BUFFER[2208]	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
#define idfEM_R0UL03RDU	 836	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
#define fEM_R0UL17RDU	 BUFFER[2213]	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
#define idfEM_R0UL17RDU	 837	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
#define fEM_R0UL19RDU	 BUFFER[2218]	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define idfEM_R0UL19RDU	 838	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define fEM_R0UL07RDU	 BUFFER[2223]	//(R0UL07RDU) Время срабатывания верхней АС II УР
#define idfEM_R0UL07RDU	 839	//(R0UL07RDU) Время срабатывания верхней АС II УР
#define fEM_R0UL18RDU	 BUFFER[2228]	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
#define idfEM_R0UL18RDU	 840	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
#define fEM_R0UL16RDU	 BUFFER[2233]	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
#define idfEM_R0UL16RDU	 841	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
#define fEM_R0UL02RDU	 BUFFER[2238]	//(R0UL02RDU) Время задержки  ИНИ
#define idfEM_R0UL02RDU	 842	//(R0UL02RDU) Время задержки  ИНИ
#define fEM_R0UN08RDU	 BUFFER[2243]	//(R0UN08RDU) 8-я заданная мощность
#define idfEM_R0UN08RDU	 843	//(R0UN08RDU) 8-я заданная мощность
#define fEM_R0UN07RDU	 BUFFER[2248]	//(R0UN07RDU) 7-я заданная мощность
#define idfEM_R0UN07RDU	 844	//(R0UN07RDU) 7-я заданная мощность
#define fEM_R0UN06RDU	 BUFFER[2253]	//(R0UN06RDU) 6-я заданная мощность
#define idfEM_R0UN06RDU	 845	//(R0UN06RDU) 6-я заданная мощность
#define fEM_R0UN05RDU	 BUFFER[2258]	//(R0UN05RDU) 5-я заданная мощность
#define idfEM_R0UN05RDU	 846	//(R0UN05RDU) 5-я заданная мощность
#define fEM_R0UN04RDU	 BUFFER[2263]	//(R0UN04RDU) 4-я заданная мощность
#define idfEM_R0UN04RDU	 847	//(R0UN04RDU) 4-я заданная мощность
#define fEM_R0UN03RDU	 BUFFER[2268]	//(R0UN03RDU) Ограничение 3 по мощности
#define idfEM_R0UN03RDU	 848	//(R0UN03RDU) Ограничение 3 по мощности
#define fEM_R0UN02RDU	 BUFFER[2273]	//(R0UN02RDU) 2-я заданная мощность
#define idfEM_R0UN02RDU	 849	//(R0UN02RDU) 2-я заданная мощность
#define fEM_R0UN01RDU	 BUFFER[2278]	//(R0UN01RDU) 1-я заданная мощность
#define idfEM_R0UN01RDU	 850	//(R0UN01RDU) 1-я заданная мощность
#define fEM_A2UC82RDU	 BUFFER[2283]	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC82RDU	 851	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define fEM_A2UC83RDU	 BUFFER[2288]	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define idfEM_A2UC83RDU	 852	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define fEM_A1UC83RDU	 BUFFER[2293]	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define idfEM_A1UC83RDU	 853	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define fEM_A2UC81RDU	 BUFFER[2298]	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC81RDU	 854	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define fEM_A1UC81RDU	 BUFFER[2303]	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC81RDU	 855	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define fEM_A1UC82RDU	 BUFFER[2308]	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC82RDU	 856	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define fEM_A2UL83RDU	 BUFFER[2313]	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL83RDU	 857	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A3UC81RDU	 BUFFER[2318]	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define idfEM_A3UC81RDU	 858	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define fEM_A3UC82RDU	 BUFFER[2323]	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define idfEM_A3UC82RDU	 859	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define fEM_R0UN80RDU	 BUFFER[2328]	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define idfEM_R0UN80RDU	 860	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define iEM_A2UV01IDU	 BUFFER[2333]	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV01IDU	 861	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define iEM_A2UV02IDU	 BUFFER[2336]	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV02IDU	 862	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define iEM_A1UV01IDU	 BUFFER[2339]	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV01IDU	 863	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define iEM_A1UV02IDU	 BUFFER[2342]	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV02IDU	 864	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define iEM_A1UV03IDU	 BUFFER[2345]	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define idiEM_A1UV03IDU	 865	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define iEM_A3UV01IDU	 BUFFER[2348]	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define idiEM_A3UV01IDU	 866	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define iEM_A3UV02IDU	 BUFFER[2351]	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define idiEM_A3UV02IDU	 867	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define lEM_R0MD01LC1	 BUFFER[2354]	//(R0MD01LC1) Ручное управление ОРР
#define idlEM_R0MD01LC1	 868	//(R0MD01LC1) Ручное управление ОРР
#define fEM_A3UC09RDU	 BUFFER[2356]	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC09RDU	 869	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define fEM_A2UC02RDU	 BUFFER[2361]	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define idfEM_A2UC02RDU	 870	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define fEM_A1UC02RDU	 BUFFER[2366]	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define idfEM_A1UC02RDU	 871	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define fEM_A3UC02RDU	 BUFFER[2371]	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define idfEM_A3UC02RDU	 872	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define fEM_R0UL21RDU	 BUFFER[2376]	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
#define idfEM_R0UL21RDU	 873	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
#define fEM_R0UN09RDU	 BUFFER[2381]	//(R0UN09RDU) Минимальный период при регулировании мощности
#define idfEM_R0UN09RDU	 874	//(R0UN09RDU) Минимальный период при регулировании мощности
#define fEM_R0UN11RDU	 BUFFER[2386]	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
#define idfEM_R0UN11RDU	 875	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
#define fEM_R0UN12RDU	 BUFFER[2391]	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
#define idfEM_R0UN12RDU	 876	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
#define fEM_R0UN13RDU	 BUFFER[2396]	//(R0UN13RDU) Минимальное изменение координаты, мм
#define idfEM_R0UN13RDU	 877	//(R0UN13RDU) Минимальное изменение координаты, мм
#define fEM_R0UN14RDU	 BUFFER[2401]	//(R0UN14RDU) Максимальная координата штока ИМ, мм
#define idfEM_R0UN14RDU	 878	//(R0UN14RDU) Максимальная координата штока ИМ, мм
#define fEM_R0UN16RDU	 BUFFER[2406]	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN16RDU	 879	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN17RDU	 BUFFER[2411]	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN17RDU	 880	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN18RDU	 BUFFER[2416]	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
#define idfEM_R0UN18RDU	 881	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
#define fEM_R0UN19RDU	 BUFFER[2421]	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define idfEM_R0UN19RDU	 882	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define fEM_R0UN70LDU	 BUFFER[2426]	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN70LDU	 883	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN71LDU	 BUFFER[2431]	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN71LDU	 884	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN72LDU	 BUFFER[2436]	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN72LDU	 885	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN73LDU	 BUFFER[2441]	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN73LDU	 886	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN74LDU	 BUFFER[2446]	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN74LDU	 887	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN75LDU	 BUFFER[2451]	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN75LDU	 888	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN80LDU	 BUFFER[2456]	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN80LDU	 889	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define fEM_R0UN81LDU	 BUFFER[2461]	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN81LDU	 890	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define fEM_R0UN82LDU	 BUFFER[2466]	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN82LDU	 891	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define fEM_R0UN83LDU	 BUFFER[2471]	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN83LDU	 892	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define fEM_R0UN84LDU	 BUFFER[2476]	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN84LDU	 893	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define fEM_R0UN85LDU	 BUFFER[2481]	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN85LDU	 894	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define fEM_R0UT20RDU	 BUFFER[2486]	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define idfEM_R0UT20RDU	 895	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define fEM_R0UN25RDU	 BUFFER[2491]	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
#define idfEM_R0UN25RDU	 896	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
#define fEM_R0UN15RDU	 BUFFER[2496]	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
#define idfEM_R0UN15RDU	 897	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
#define fEM_R0UN26RDU	 BUFFER[2501]	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
#define idfEM_R0UN26RDU	 898	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
#define fEM_R0UN27RDU	 BUFFER[2506]	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
#define idfEM_R0UN27RDU	 899	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
#define fEM_R0UN24RDU	 BUFFER[2511]	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN24RDU	 900	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
#define fEM_R0UL25RDU	 BUFFER[2516]	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define idfEM_R0UL25RDU	 901	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define fEM_R0UL01RSS	 BUFFER[2521]	//(R0UL01RSS) Шаг измерения периода (сек)
#define idfEM_R0UL01RSS	 902	//(R0UL01RSS) Шаг измерения периода (сек)
#define fEM_R0UL02RSS	 BUFFER[2526]	//(R0UL02RSS) Tф-постоянная времени, с
#define idfEM_R0UL02RSS	 903	//(R0UL02RSS) Tф-постоянная времени, с
#define fEM_R0UN03RSS	 BUFFER[2531]	//(R0UN03RSS) нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN03RSS	 904	//(R0UN03RSS) нижняя граница интервала мощности для измерения периода (ватт)
#define bFirstEnterFlag	 BUFFER[2536]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 905	//(bFirstEnterFlag) 
#define internal2_m182_tx	 BUFFER[2538]	//(internal2_m182_tx) tx - время накопленное сек
#define idinternal2_m182_tx	 906	//(internal2_m182_tx) tx - время накопленное сек
#define internal2_m182_y0	 BUFFER[2543]	//(internal2_m182_y0) y0
#define idinternal2_m182_y0	 907	//(internal2_m182_y0) y0
#define internal2_m176_tx	 BUFFER[2544]	//(internal2_m176_tx) tx - время накопленное сек
#define idinternal2_m176_tx	 908	//(internal2_m176_tx) tx - время накопленное сек
#define internal2_m176_y0	 BUFFER[2549]	//(internal2_m176_y0) y0
#define idinternal2_m176_y0	 909	//(internal2_m176_y0) y0
#define internal2_m173_tx	 BUFFER[2550]	//(internal2_m173_tx) tx - время накопленное сек
#define idinternal2_m173_tx	 910	//(internal2_m173_tx) tx - время накопленное сек
#define internal2_m173_y0	 BUFFER[2555]	//(internal2_m173_y0) y0
#define idinternal2_m173_y0	 911	//(internal2_m173_y0) y0
#define internal2_m165_tx	 BUFFER[2556]	//(internal2_m165_tx) tx - время накопленное сек
#define idinternal2_m165_tx	 912	//(internal2_m165_tx) tx - время накопленное сек
#define internal2_m165_y0	 BUFFER[2561]	//(internal2_m165_y0) y0
#define idinternal2_m165_y0	 913	//(internal2_m165_y0) y0
#define internal2_m158_tx	 BUFFER[2562]	//(internal2_m158_tx) tx - время накопленное сек
#define idinternal2_m158_tx	 914	//(internal2_m158_tx) tx - время накопленное сек
#define internal2_m158_y0	 BUFFER[2567]	//(internal2_m158_y0) y0
#define idinternal2_m158_y0	 915	//(internal2_m158_y0) y0
#define internal2_m155_tx	 BUFFER[2568]	//(internal2_m155_tx) tx - время накопленное сек
#define idinternal2_m155_tx	 916	//(internal2_m155_tx) tx - время накопленное сек
#define internal2_m155_y0	 BUFFER[2573]	//(internal2_m155_y0) y0
#define idinternal2_m155_y0	 917	//(internal2_m155_y0) y0
#define internal2_m149_tx	 BUFFER[2574]	//(internal2_m149_tx) tx - время накопленное сек
#define idinternal2_m149_tx	 918	//(internal2_m149_tx) tx - время накопленное сек
#define internal2_m149_y0	 BUFFER[2579]	//(internal2_m149_y0) y0
#define idinternal2_m149_y0	 919	//(internal2_m149_y0) y0
#define internal2_m144_tx	 BUFFER[2580]	//(internal2_m144_tx) tx - время накопленное сек
#define idinternal2_m144_tx	 920	//(internal2_m144_tx) tx - время накопленное сек
#define internal2_m144_y0	 BUFFER[2585]	//(internal2_m144_y0) y0
#define idinternal2_m144_y0	 921	//(internal2_m144_y0) y0
#define internal2_m141_tx	 BUFFER[2586]	//(internal2_m141_tx) tx - время накопленное сек
#define idinternal2_m141_tx	 922	//(internal2_m141_tx) tx - время накопленное сек
#define internal2_m141_y0	 BUFFER[2591]	//(internal2_m141_y0) y0
#define idinternal2_m141_y0	 923	//(internal2_m141_y0) y0
#define internal2_m134_tx	 BUFFER[2592]	//(internal2_m134_tx) tx - время накопленное сек
#define idinternal2_m134_tx	 924	//(internal2_m134_tx) tx - время накопленное сек
#define internal2_m134_y0	 BUFFER[2597]	//(internal2_m134_y0) y0
#define idinternal2_m134_y0	 925	//(internal2_m134_y0) y0
#define internal2_m132_tx	 BUFFER[2598]	//(internal2_m132_tx) tx - время накопленное сек
#define idinternal2_m132_tx	 926	//(internal2_m132_tx) tx - время накопленное сек
#define internal2_m132_y0	 BUFFER[2603]	//(internal2_m132_y0) y0
#define idinternal2_m132_y0	 927	//(internal2_m132_y0) y0
#define internal2_m127_tx	 BUFFER[2604]	//(internal2_m127_tx) tx - время накопленное сек
#define idinternal2_m127_tx	 928	//(internal2_m127_tx) tx - время накопленное сек
#define internal2_m127_y0	 BUFFER[2609]	//(internal2_m127_y0) y0
#define idinternal2_m127_y0	 929	//(internal2_m127_y0) y0
#define internal2_m195_y0	 BUFFER[2610]	//(internal2_m195_y0) y0
#define idinternal2_m195_y0	 930	//(internal2_m195_y0) y0
#define internal2_m193_y0	 BUFFER[2615]	//(internal2_m193_y0) y0
#define idinternal2_m193_y0	 931	//(internal2_m193_y0) y0
#define internal2_m228_y0	 BUFFER[2620]	//(internal2_m228_y0) state
#define idinternal2_m228_y0	 932	//(internal2_m228_y0) state
#define internal2_m220_y0	 BUFFER[2622]	//(internal2_m220_y0) state
#define idinternal2_m220_y0	 933	//(internal2_m220_y0) state
#define internal2_m208_y1	 BUFFER[2624]	//(internal2_m208_y1) y1 - внутренний параметр
#define idinternal2_m208_y1	 934	//(internal2_m208_y1) y1 - внутренний параметр
#define internal2_m214_y1	 BUFFER[2626]	//(internal2_m214_y1) y1 - внутренний параметр
#define idinternal2_m214_y1	 935	//(internal2_m214_y1) y1 - внутренний параметр
#define internal2_m198_y1	 BUFFER[2628]	//(internal2_m198_y1) y1 - внутренний параметр
#define idinternal2_m198_y1	 936	//(internal2_m198_y1) y1 - внутренний параметр
#define internal2_m205_y1	 BUFFER[2630]	//(internal2_m205_y1) y1 - внутренний параметр
#define idinternal2_m205_y1	 937	//(internal2_m205_y1) y1 - внутренний параметр
#define internal2_m17_Nk0	 BUFFER[2632]	//(internal2_m17_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m17_Nk0	 938	//(internal2_m17_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m17_SetFlag	 BUFFER[2637]	//(internal2_m17_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m17_SetFlag	 939	//(internal2_m17_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m110_Nk0	 BUFFER[2639]	//(internal2_m110_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m110_Nk0	 940	//(internal2_m110_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m110_SetFlag	 BUFFER[2644]	//(internal2_m110_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m110_SetFlag	 941	//(internal2_m110_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m106_Nk0	 BUFFER[2646]	//(internal2_m106_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m106_Nk0	 942	//(internal2_m106_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m106_SetFlag	 BUFFER[2651]	//(internal2_m106_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m106_SetFlag	 943	//(internal2_m106_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m75_Nk0	 BUFFER[2653]	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m75_Nk0	 944	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m75_SetFlag	 BUFFER[2658]	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m75_SetFlag	 945	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m77_Nk0	 BUFFER[2660]	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m77_Nk0	 946	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m77_SetFlag	 BUFFER[2665]	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m77_SetFlag	 947	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m49_Nk0	 BUFFER[2667]	//(internal2_m49_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m49_Nk0	 948	//(internal2_m49_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m49_SetFlag	 BUFFER[2672]	//(internal2_m49_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m49_SetFlag	 949	//(internal2_m49_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m53_Nk0	 BUFFER[2674]	//(internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m53_Nk0	 950	//(internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m53_SetFlag	 BUFFER[2679]	//(internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m53_SetFlag	 951	//(internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m15_Nk0	 BUFFER[2681]	//(internal2_m15_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m15_Nk0	 952	//(internal2_m15_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m15_SetFlag	 BUFFER[2686]	//(internal2_m15_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m15_SetFlag	 953	//(internal2_m15_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal1_m78_flst	 BUFFER[2688]	//(internal1_m78_flst)  флаг старта измерения
#define idinternal1_m78_flst	 954	//(internal1_m78_flst)  флаг старта измерения
#define internal1_m78_chsr	 BUFFER[2691]	//(internal1_m78_chsr)  счетчик усреднения
#define idinternal1_m78_chsr	 955	//(internal1_m78_chsr)  счетчик усреднения
#define internal1_m78_chizm	 BUFFER[2694]	//(internal1_m78_chizm)  счетчик уменьшения мощности
#define idinternal1_m78_chizm	 956	//(internal1_m78_chizm)  счетчик уменьшения мощности
#define internal1_m78_sumtim	 BUFFER[2697]	//(internal1_m78_sumtim)  время измерения мощности
#define idinternal1_m78_sumtim	 957	//(internal1_m78_sumtim)  время измерения мощности
#define internal1_m78_W1	 BUFFER[2702]	//(internal1_m78_W1)  мощность на старте измерения
#define idinternal1_m78_W1	 958	//(internal1_m78_W1)  мощность на старте измерения
#define internal1_m78_W2	 BUFFER[2707]	//(internal1_m78_W2)  мощность в конце измерения
#define idinternal1_m78_W2	 959	//(internal1_m78_W2)  мощность в конце измерения
#define internal1_m78_Wmin	 BUFFER[2712]	//(internal1_m78_Wmin)  минимальное измерение в серии
#define idinternal1_m78_Wmin	 960	//(internal1_m78_Wmin)  минимальное измерение в серии
#define internal1_m78_Wmax	 BUFFER[2717]	//(internal1_m78_Wmax)  максимальное измерение в серии
#define idinternal1_m78_Wmax	 961	//(internal1_m78_Wmax)  максимальное измерение в серии
#define internal1_m78_Wlast	 BUFFER[2722]	//(internal1_m78_Wlast)  последнее растущее измерение
#define idinternal1_m78_Wlast	 962	//(internal1_m78_Wlast)  последнее растущее измерение
#define internal1_m78_y0	 BUFFER[2727]	//(internal1_m78_y0) y0 - внутренний параметр
#define idinternal1_m78_y0	 963	//(internal1_m78_y0) y0 - внутренний параметр
#define internal1_m78_MyFirstEnterFlag	 BUFFER[2732]	//(internal1_m78_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m78_MyFirstEnterFlag	 964	//(internal1_m78_MyFirstEnterFlag)  FirstEnterFlag
#define internal1_m2035_tx	 BUFFER[2734]	//(internal1_m2035_tx) tx - внутренний параметр
#define idinternal1_m2035_tx	 965	//(internal1_m2035_tx) tx - внутренний параметр
#define internal1_m2034_tx	 BUFFER[2739]	//(internal1_m2034_tx) tx - внутренний параметр
#define idinternal1_m2034_tx	 966	//(internal1_m2034_tx) tx - внутренний параметр
#define internal1_m780_tx	 BUFFER[2744]	//(internal1_m780_tx) tx - внутренний параметр
#define idinternal1_m780_tx	 967	//(internal1_m780_tx) tx - внутренний параметр
#define internal1_m737_tx	 BUFFER[2749]	//(internal1_m737_tx) tx - внутренний параметр
#define idinternal1_m737_tx	 968	//(internal1_m737_tx) tx - внутренний параметр
#define internal1_m790_tx	 BUFFER[2754]	//(internal1_m790_tx) tx - внутренний параметр
#define idinternal1_m790_tx	 969	//(internal1_m790_tx) tx - внутренний параметр
#define internal1_m792_tx	 BUFFER[2759]	//(internal1_m792_tx) tx - внутренний параметр
#define idinternal1_m792_tx	 970	//(internal1_m792_tx) tx - внутренний параметр
#define internal1_m791_tx	 BUFFER[2764]	//(internal1_m791_tx) tx - внутренний параметр
#define idinternal1_m791_tx	 971	//(internal1_m791_tx) tx - внутренний параметр
#define internal1_m746_tx	 BUFFER[2769]	//(internal1_m746_tx) tx - внутренний параметр
#define idinternal1_m746_tx	 972	//(internal1_m746_tx) tx - внутренний параметр
#define internal1_m730_tx	 BUFFER[2774]	//(internal1_m730_tx) tx - внутренний параметр
#define idinternal1_m730_tx	 973	//(internal1_m730_tx) tx - внутренний параметр
#define internal1_m741_tx	 BUFFER[2779]	//(internal1_m741_tx) tx - внутренний параметр
#define idinternal1_m741_tx	 974	//(internal1_m741_tx) tx - внутренний параметр
#define internal1_m772_tx	 BUFFER[2784]	//(internal1_m772_tx) tx - внутренний параметр
#define idinternal1_m772_tx	 975	//(internal1_m772_tx) tx - внутренний параметр
#define internal1_m789_tx	 BUFFER[2789]	//(internal1_m789_tx) tx - внутренний параметр
#define idinternal1_m789_tx	 976	//(internal1_m789_tx) tx - внутренний параметр
#define internal1_m762_tx	 BUFFER[2794]	//(internal1_m762_tx) tx - внутренний параметр
#define idinternal1_m762_tx	 977	//(internal1_m762_tx) tx - внутренний параметр
#define internal1_m393_tx	 BUFFER[2799]	//(internal1_m393_tx) tx - внутренний параметр
#define idinternal1_m393_tx	 978	//(internal1_m393_tx) tx - внутренний параметр
#define internal1_m392_tx	 BUFFER[2804]	//(internal1_m392_tx) tx - внутренний параметр
#define idinternal1_m392_tx	 979	//(internal1_m392_tx) tx - внутренний параметр
#define internal1_m391_tx	 BUFFER[2809]	//(internal1_m391_tx) tx - внутренний параметр
#define idinternal1_m391_tx	 980	//(internal1_m391_tx) tx - внутренний параметр
#define internal1_m390_tx	 BUFFER[2814]	//(internal1_m390_tx) tx - внутренний параметр
#define idinternal1_m390_tx	 981	//(internal1_m390_tx) tx - внутренний параметр
#define internal1_m761_tx	 BUFFER[2819]	//(internal1_m761_tx) tx - внутренний параметр
#define idinternal1_m761_tx	 982	//(internal1_m761_tx) tx - внутренний параметр
#define internal1_m756_tx	 BUFFER[2824]	//(internal1_m756_tx) tx - внутренний параметр
#define idinternal1_m756_tx	 983	//(internal1_m756_tx) tx - внутренний параметр
#define internal1_m764_tx	 BUFFER[2829]	//(internal1_m764_tx) tx - внутренний параметр
#define idinternal1_m764_tx	 984	//(internal1_m764_tx) tx - внутренний параметр
#define internal1_m770_tx	 BUFFER[2834]	//(internal1_m770_tx) tx - внутренний параметр
#define idinternal1_m770_tx	 985	//(internal1_m770_tx) tx - внутренний параметр
#define internal1_m526_tx	 BUFFER[2839]	//(internal1_m526_tx) tx - внутренний параметр
#define idinternal1_m526_tx	 986	//(internal1_m526_tx) tx - внутренний параметр
#define internal1_m525_tx	 BUFFER[2844]	//(internal1_m525_tx) tx - внутренний параметр
#define idinternal1_m525_tx	 987	//(internal1_m525_tx) tx - внутренний параметр
#define internal1_m524_tx	 BUFFER[2849]	//(internal1_m524_tx) tx - внутренний параметр
#define idinternal1_m524_tx	 988	//(internal1_m524_tx) tx - внутренний параметр
#define internal1_m520_tx	 BUFFER[2854]	//(internal1_m520_tx) tx - внутренний параметр
#define idinternal1_m520_tx	 989	//(internal1_m520_tx) tx - внутренний параметр
#define internal1_m497_tx	 BUFFER[2859]	//(internal1_m497_tx) tx - внутренний параметр
#define idinternal1_m497_tx	 990	//(internal1_m497_tx) tx - внутренний параметр
#define internal1_m496_tx	 BUFFER[2864]	//(internal1_m496_tx) tx - внутренний параметр
#define idinternal1_m496_tx	 991	//(internal1_m496_tx) tx - внутренний параметр
#define internal1_m495_tx	 BUFFER[2869]	//(internal1_m495_tx) tx - внутренний параметр
#define idinternal1_m495_tx	 992	//(internal1_m495_tx) tx - внутренний параметр
#define internal1_m498_tx	 BUFFER[2874]	//(internal1_m498_tx) tx - внутренний параметр
#define idinternal1_m498_tx	 993	//(internal1_m498_tx) tx - внутренний параметр
#define internal1_m2437_tx	 BUFFER[2879]	//(internal1_m2437_tx) tx - внутренний параметр
#define idinternal1_m2437_tx	 994	//(internal1_m2437_tx) tx - внутренний параметр
#define internal1_m2149_tx	 BUFFER[2884]	//(internal1_m2149_tx) tx - внутренний параметр
#define idinternal1_m2149_tx	 995	//(internal1_m2149_tx) tx - внутренний параметр
#define internal1_m2436_tx	 BUFFER[2889]	//(internal1_m2436_tx) tx - внутренний параметр
#define idinternal1_m2436_tx	 996	//(internal1_m2436_tx) tx - внутренний параметр
#define internal1_m2435_tx	 BUFFER[2894]	//(internal1_m2435_tx) tx - внутренний параметр
#define idinternal1_m2435_tx	 997	//(internal1_m2435_tx) tx - внутренний параметр
#define internal1_m2433_tx	 BUFFER[2899]	//(internal1_m2433_tx) tx - внутренний параметр
#define idinternal1_m2433_tx	 998	//(internal1_m2433_tx) tx - внутренний параметр
#define internal1_m108_tx	 BUFFER[2904]	//(internal1_m108_tx) tx - внутренний параметр
#define idinternal1_m108_tx	 999	//(internal1_m108_tx) tx - внутренний параметр
#define internal1_m1144_tx	 BUFFER[2909]	//(internal1_m1144_tx) tx - внутренний параметр
#define idinternal1_m1144_tx	 1000	//(internal1_m1144_tx) tx - внутренний параметр
#define internal1_m2295_tx	 BUFFER[2914]	//(internal1_m2295_tx) tx - внутренний параметр
#define idinternal1_m2295_tx	 1001	//(internal1_m2295_tx) tx - внутренний параметр
#define internal1_m2294_tx	 BUFFER[2919]	//(internal1_m2294_tx) tx - внутренний параметр
#define idinternal1_m2294_tx	 1002	//(internal1_m2294_tx) tx - внутренний параметр
#define internal1_m2293_tx	 BUFFER[2924]	//(internal1_m2293_tx) tx - внутренний параметр
#define idinternal1_m2293_tx	 1003	//(internal1_m2293_tx) tx - внутренний параметр
#define internal1_m1234_tx	 BUFFER[2929]	//(internal1_m1234_tx) tx - внутренний параметр
#define idinternal1_m1234_tx	 1004	//(internal1_m1234_tx) tx - внутренний параметр
#define internal1_m1233_tx	 BUFFER[2934]	//(internal1_m1233_tx) tx - внутренний параметр
#define idinternal1_m1233_tx	 1005	//(internal1_m1233_tx) tx - внутренний параметр
#define internal1_m1228_tx	 BUFFER[2939]	//(internal1_m1228_tx) tx - внутренний параметр
#define idinternal1_m1228_tx	 1006	//(internal1_m1228_tx) tx - внутренний параметр
#define internal1_m1221_tx	 BUFFER[2944]	//(internal1_m1221_tx) tx - внутренний параметр
#define idinternal1_m1221_tx	 1007	//(internal1_m1221_tx) tx - внутренний параметр
#define internal1_m1219_tx	 BUFFER[2949]	//(internal1_m1219_tx) tx - внутренний параметр
#define idinternal1_m1219_tx	 1008	//(internal1_m1219_tx) tx - внутренний параметр
#define internal1_m1217_tx	 BUFFER[2954]	//(internal1_m1217_tx) tx - внутренний параметр
#define idinternal1_m1217_tx	 1009	//(internal1_m1217_tx) tx - внутренний параметр
#define internal1_m1215_tx	 BUFFER[2959]	//(internal1_m1215_tx) tx - внутренний параметр
#define idinternal1_m1215_tx	 1010	//(internal1_m1215_tx) tx - внутренний параметр
#define internal1_m1258_tx	 BUFFER[2964]	//(internal1_m1258_tx) tx - внутренний параметр
#define idinternal1_m1258_tx	 1011	//(internal1_m1258_tx) tx - внутренний параметр
#define internal1_m1265_tx	 BUFFER[2969]	//(internal1_m1265_tx) tx - внутренний параметр
#define idinternal1_m1265_tx	 1012	//(internal1_m1265_tx) tx - внутренний параметр
#define internal1_m1270_tx	 BUFFER[2974]	//(internal1_m1270_tx) tx - внутренний параметр
#define idinternal1_m1270_tx	 1013	//(internal1_m1270_tx) tx - внутренний параметр
#define internal1_m1276_tx	 BUFFER[2979]	//(internal1_m1276_tx) tx - внутренний параметр
#define idinternal1_m1276_tx	 1014	//(internal1_m1276_tx) tx - внутренний параметр
#define internal1_m1236_tx	 BUFFER[2984]	//(internal1_m1236_tx) tx - внутренний параметр
#define idinternal1_m1236_tx	 1015	//(internal1_m1236_tx) tx - внутренний параметр
#define internal1_m1257_tx	 BUFFER[2989]	//(internal1_m1257_tx) tx - внутренний параметр
#define idinternal1_m1257_tx	 1016	//(internal1_m1257_tx) tx - внутренний параметр
#define internal1_m1271_tx	 BUFFER[2994]	//(internal1_m1271_tx) tx - внутренний параметр
#define idinternal1_m1271_tx	 1017	//(internal1_m1271_tx) tx - внутренний параметр
#define internal1_m475_tx	 BUFFER[2999]	//(internal1_m475_tx) tx - внутренний параметр
#define idinternal1_m475_tx	 1018	//(internal1_m475_tx) tx - внутренний параметр
#define internal1_m469_tx	 BUFFER[3004]	//(internal1_m469_tx) tx - внутренний параметр
#define idinternal1_m469_tx	 1019	//(internal1_m469_tx) tx - внутренний параметр
#define internal1_m471_tx	 BUFFER[3009]	//(internal1_m471_tx) tx - внутренний параметр
#define idinternal1_m471_tx	 1020	//(internal1_m471_tx) tx - внутренний параметр
#define internal1_m473_tx	 BUFFER[3014]	//(internal1_m473_tx) tx - внутренний параметр
#define idinternal1_m473_tx	 1021	//(internal1_m473_tx) tx - внутренний параметр
#define internal1_m480_tx	 BUFFER[3019]	//(internal1_m480_tx) tx - внутренний параметр
#define idinternal1_m480_tx	 1022	//(internal1_m480_tx) tx - внутренний параметр
#define internal1_m434_tx	 BUFFER[3024]	//(internal1_m434_tx) tx - внутренний параметр
#define idinternal1_m434_tx	 1023	//(internal1_m434_tx) tx - внутренний параметр
#define internal1_m432_tx	 BUFFER[3029]	//(internal1_m432_tx) tx - внутренний параметр
#define idinternal1_m432_tx	 1024	//(internal1_m432_tx) tx - внутренний параметр
#define internal1_m433_tx	 BUFFER[3034]	//(internal1_m433_tx) tx - внутренний параметр
#define idinternal1_m433_tx	 1025	//(internal1_m433_tx) tx - внутренний параметр
#define internal1_m426_tx	 BUFFER[3039]	//(internal1_m426_tx) tx - внутренний параметр
#define idinternal1_m426_tx	 1026	//(internal1_m426_tx) tx - внутренний параметр
#define internal1_m888_tx	 BUFFER[3044]	//(internal1_m888_tx) tx - внутренний параметр
#define idinternal1_m888_tx	 1027	//(internal1_m888_tx) tx - внутренний параметр
#define internal1_m887_tx	 BUFFER[3049]	//(internal1_m887_tx) tx - внутренний параметр
#define idinternal1_m887_tx	 1028	//(internal1_m887_tx) tx - внутренний параметр
#define internal1_m886_tx	 BUFFER[3054]	//(internal1_m886_tx) tx - внутренний параметр
#define idinternal1_m886_tx	 1029	//(internal1_m886_tx) tx - внутренний параметр
#define internal1_m882_tx	 BUFFER[3059]	//(internal1_m882_tx) tx - внутренний параметр
#define idinternal1_m882_tx	 1030	//(internal1_m882_tx) tx - внутренний параметр
#define internal1_m1322_tx	 BUFFER[3064]	//(internal1_m1322_tx) tx - внутренний параметр
#define idinternal1_m1322_tx	 1031	//(internal1_m1322_tx) tx - внутренний параметр
#define internal1_m1321_tx	 BUFFER[3069]	//(internal1_m1321_tx) tx - внутренний параметр
#define idinternal1_m1321_tx	 1032	//(internal1_m1321_tx) tx - внутренний параметр
#define internal1_m1320_tx	 BUFFER[3074]	//(internal1_m1320_tx) tx - внутренний параметр
#define idinternal1_m1320_tx	 1033	//(internal1_m1320_tx) tx - внутренний параметр
#define internal1_m1533_tx	 BUFFER[3079]	//(internal1_m1533_tx) tx - внутренний параметр
#define idinternal1_m1533_tx	 1034	//(internal1_m1533_tx) tx - внутренний параметр
#define internal1_m1546_tx	 BUFFER[3084]	//(internal1_m1546_tx) tx - внутренний параметр
#define idinternal1_m1546_tx	 1035	//(internal1_m1546_tx) tx - внутренний параметр
#define internal1_m1545_tx	 BUFFER[3089]	//(internal1_m1545_tx) tx - внутренний параметр
#define idinternal1_m1545_tx	 1036	//(internal1_m1545_tx) tx - внутренний параметр
#define internal1_m1544_tx	 BUFFER[3094]	//(internal1_m1544_tx) tx - внутренний параметр
#define idinternal1_m1544_tx	 1037	//(internal1_m1544_tx) tx - внутренний параметр
#define internal1_m1535_tx	 BUFFER[3099]	//(internal1_m1535_tx) tx - внутренний параметр
#define idinternal1_m1535_tx	 1038	//(internal1_m1535_tx) tx - внутренний параметр
#define internal1_m2267_tx	 BUFFER[3104]	//(internal1_m2267_tx) tx - внутренний параметр
#define idinternal1_m2267_tx	 1039	//(internal1_m2267_tx) tx - внутренний параметр
#define internal1_m2250_tx	 BUFFER[3109]	//(internal1_m2250_tx) tx - внутренний параметр
#define idinternal1_m2250_tx	 1040	//(internal1_m2250_tx) tx - внутренний параметр
#define internal1_m2227_tx	 BUFFER[3114]	//(internal1_m2227_tx) tx - внутренний параметр
#define idinternal1_m2227_tx	 1041	//(internal1_m2227_tx) tx - внутренний параметр
#define internal1_m1543_tx	 BUFFER[3119]	//(internal1_m1543_tx) tx - внутренний параметр
#define idinternal1_m1543_tx	 1042	//(internal1_m1543_tx) tx - внутренний параметр
#define internal1_m1524_tx	 BUFFER[3124]	//(internal1_m1524_tx) tx - внутренний параметр
#define idinternal1_m1524_tx	 1043	//(internal1_m1524_tx) tx - внутренний параметр
#define internal1_m1523_tx	 BUFFER[3129]	//(internal1_m1523_tx) tx - внутренний параметр
#define idinternal1_m1523_tx	 1044	//(internal1_m1523_tx) tx - внутренний параметр
#define internal1_m1520_tx	 BUFFER[3134]	//(internal1_m1520_tx) tx - внутренний параметр
#define idinternal1_m1520_tx	 1045	//(internal1_m1520_tx) tx - внутренний параметр
#define internal1_m1542_tx	 BUFFER[3139]	//(internal1_m1542_tx) tx - внутренний параметр
#define idinternal1_m1542_tx	 1046	//(internal1_m1542_tx) tx - внутренний параметр
#define internal1_m1508_tx	 BUFFER[3144]	//(internal1_m1508_tx) tx - внутренний параметр
#define idinternal1_m1508_tx	 1047	//(internal1_m1508_tx) tx - внутренний параметр
#define internal1_m1510_tx	 BUFFER[3149]	//(internal1_m1510_tx) tx - внутренний параметр
#define idinternal1_m1510_tx	 1048	//(internal1_m1510_tx) tx - внутренний параметр
#define internal1_m1507_tx	 BUFFER[3154]	//(internal1_m1507_tx) tx - внутренний параметр
#define idinternal1_m1507_tx	 1049	//(internal1_m1507_tx) tx - внутренний параметр
#define internal1_m1480_tx	 BUFFER[3159]	//(internal1_m1480_tx) tx - внутренний параметр
#define idinternal1_m1480_tx	 1050	//(internal1_m1480_tx) tx - внутренний параметр
#define internal1_m1479_tx	 BUFFER[3164]	//(internal1_m1479_tx) tx - внутренний параметр
#define idinternal1_m1479_tx	 1051	//(internal1_m1479_tx) tx - внутренний параметр
#define internal1_m1488_tx	 BUFFER[3169]	//(internal1_m1488_tx) tx - внутренний параметр
#define idinternal1_m1488_tx	 1052	//(internal1_m1488_tx) tx - внутренний параметр
#define internal1_m1492_tx	 BUFFER[3174]	//(internal1_m1492_tx) tx - внутренний параметр
#define idinternal1_m1492_tx	 1053	//(internal1_m1492_tx) tx - внутренний параметр
#define internal1_m981_tx	 BUFFER[3179]	//(internal1_m981_tx) tx - внутренний параметр
#define idinternal1_m981_tx	 1054	//(internal1_m981_tx) tx - внутренний параметр
#define internal1_m984_tx	 BUFFER[3184]	//(internal1_m984_tx) tx - внутренний параметр
#define idinternal1_m984_tx	 1055	//(internal1_m984_tx) tx - внутренний параметр
#define internal1_m2218_tx	 BUFFER[3189]	//(internal1_m2218_tx) tx - внутренний параметр
#define idinternal1_m2218_tx	 1056	//(internal1_m2218_tx) tx - внутренний параметр
#define internal1_m974_tx	 BUFFER[3194]	//(internal1_m974_tx) tx - внутренний параметр
#define idinternal1_m974_tx	 1057	//(internal1_m974_tx) tx - внутренний параметр
#define internal1_m972_tx	 BUFFER[3199]	//(internal1_m972_tx) tx - внутренний параметр
#define idinternal1_m972_tx	 1058	//(internal1_m972_tx) tx - внутренний параметр
#define internal1_m980_tx	 BUFFER[3204]	//(internal1_m980_tx) tx - внутренний параметр
#define idinternal1_m980_tx	 1059	//(internal1_m980_tx) tx - внутренний параметр
#define internal1_m966_tx	 BUFFER[3209]	//(internal1_m966_tx) tx - внутренний параметр
#define idinternal1_m966_tx	 1060	//(internal1_m966_tx) tx - внутренний параметр
#define internal1_m959_tx	 BUFFER[3214]	//(internal1_m959_tx) tx - внутренний параметр
#define idinternal1_m959_tx	 1061	//(internal1_m959_tx) tx - внутренний параметр
#define internal1_m958_tx	 BUFFER[3219]	//(internal1_m958_tx) tx - внутренний параметр
#define idinternal1_m958_tx	 1062	//(internal1_m958_tx) tx - внутренний параметр
#define internal1_m979_tx	 BUFFER[3224]	//(internal1_m979_tx) tx - внутренний параметр
#define idinternal1_m979_tx	 1063	//(internal1_m979_tx) tx - внутренний параметр
#define internal1_m946_tx	 BUFFER[3229]	//(internal1_m946_tx) tx - внутренний параметр
#define idinternal1_m946_tx	 1064	//(internal1_m946_tx) tx - внутренний параметр
#define internal1_m947_tx	 BUFFER[3234]	//(internal1_m947_tx) tx - внутренний параметр
#define idinternal1_m947_tx	 1065	//(internal1_m947_tx) tx - внутренний параметр
#define internal1_m944_tx	 BUFFER[3239]	//(internal1_m944_tx) tx - внутренний параметр
#define idinternal1_m944_tx	 1066	//(internal1_m944_tx) tx - внутренний параметр
#define internal1_m632_tx	 BUFFER[3244]	//(internal1_m632_tx) tx - внутренний параметр
#define idinternal1_m632_tx	 1067	//(internal1_m632_tx) tx - внутренний параметр
#define internal1_m635_tx	 BUFFER[3249]	//(internal1_m635_tx) tx - внутренний параметр
#define idinternal1_m635_tx	 1068	//(internal1_m635_tx) tx - внутренний параметр
#define internal1_m634_tx	 BUFFER[3254]	//(internal1_m634_tx) tx - внутренний параметр
#define idinternal1_m634_tx	 1069	//(internal1_m634_tx) tx - внутренний параметр
#define internal1_m624_tx	 BUFFER[3259]	//(internal1_m624_tx) tx - внутренний параметр
#define idinternal1_m624_tx	 1070	//(internal1_m624_tx) tx - внутренний параметр
#define internal1_m621_tx	 BUFFER[3264]	//(internal1_m621_tx) tx - внутренний параметр
#define idinternal1_m621_tx	 1071	//(internal1_m621_tx) tx - внутренний параметр
#define internal1_m617_tx	 BUFFER[3269]	//(internal1_m617_tx) tx - внутренний параметр
#define idinternal1_m617_tx	 1072	//(internal1_m617_tx) tx - внутренний параметр
#define internal1_m630_tx	 BUFFER[3274]	//(internal1_m630_tx) tx - внутренний параметр
#define idinternal1_m630_tx	 1073	//(internal1_m630_tx) tx - внутренний параметр
#define internal1_m607_tx	 BUFFER[3279]	//(internal1_m607_tx) tx - внутренний параметр
#define idinternal1_m607_tx	 1074	//(internal1_m607_tx) tx - внутренний параметр
#define internal1_m606_tx	 BUFFER[3284]	//(internal1_m606_tx) tx - внутренний параметр
#define idinternal1_m606_tx	 1075	//(internal1_m606_tx) tx - внутренний параметр
#define internal1_m602_tx	 BUFFER[3289]	//(internal1_m602_tx) tx - внутренний параметр
#define idinternal1_m602_tx	 1076	//(internal1_m602_tx) tx - внутренний параметр
#define internal1_m633_tx	 BUFFER[3294]	//(internal1_m633_tx) tx - внутренний параметр
#define idinternal1_m633_tx	 1077	//(internal1_m633_tx) tx - внутренний параметр
#define internal1_m590_tx	 BUFFER[3299]	//(internal1_m590_tx) tx - внутренний параметр
#define idinternal1_m590_tx	 1078	//(internal1_m590_tx) tx - внутренний параметр
#define internal1_m589_tx	 BUFFER[3304]	//(internal1_m589_tx) tx - внутренний параметр
#define idinternal1_m589_tx	 1079	//(internal1_m589_tx) tx - внутренний параметр
#define internal1_m592_tx	 BUFFER[3309]	//(internal1_m592_tx) tx - внутренний параметр
#define idinternal1_m592_tx	 1080	//(internal1_m592_tx) tx - внутренний параметр
#define internal1_m569_tx	 BUFFER[3314]	//(internal1_m569_tx) tx - внутренний параметр
#define idinternal1_m569_tx	 1081	//(internal1_m569_tx) tx - внутренний параметр
#define internal1_m570_tx	 BUFFER[3319]	//(internal1_m570_tx) tx - внутренний параметр
#define idinternal1_m570_tx	 1082	//(internal1_m570_tx) tx - внутренний параметр
#define internal1_m571_tx	 BUFFER[3324]	//(internal1_m571_tx) tx - внутренний параметр
#define idinternal1_m571_tx	 1083	//(internal1_m571_tx) tx - внутренний параметр
#define internal1_m576_tx	 BUFFER[3329]	//(internal1_m576_tx) tx - внутренний параметр
#define idinternal1_m576_tx	 1084	//(internal1_m576_tx) tx - внутренний параметр
#define internal1_m2278_tx	 BUFFER[3334]	//(internal1_m2278_tx) tx - внутренний параметр
#define idinternal1_m2278_tx	 1085	//(internal1_m2278_tx) tx - внутренний параметр
#define internal1_m2279_tx	 BUFFER[3339]	//(internal1_m2279_tx) tx - внутренний параметр
#define idinternal1_m2279_tx	 1086	//(internal1_m2279_tx) tx - внутренний параметр
#define internal1_m2280_tx	 BUFFER[3344]	//(internal1_m2280_tx) tx - внутренний параметр
#define idinternal1_m2280_tx	 1087	//(internal1_m2280_tx) tx - внутренний параметр
#define internal1_m1761_tx	 BUFFER[3349]	//(internal1_m1761_tx) tx - внутренний параметр
#define idinternal1_m1761_tx	 1088	//(internal1_m1761_tx) tx - внутренний параметр
#define internal1_m1760_tx	 BUFFER[3354]	//(internal1_m1760_tx) tx - внутренний параметр
#define idinternal1_m1760_tx	 1089	//(internal1_m1760_tx) tx - внутренний параметр
#define internal1_m1755_tx	 BUFFER[3359]	//(internal1_m1755_tx) tx - внутренний параметр
#define idinternal1_m1755_tx	 1090	//(internal1_m1755_tx) tx - внутренний параметр
#define internal1_m1746_tx	 BUFFER[3364]	//(internal1_m1746_tx) tx - внутренний параметр
#define idinternal1_m1746_tx	 1091	//(internal1_m1746_tx) tx - внутренний параметр
#define internal1_m1744_tx	 BUFFER[3369]	//(internal1_m1744_tx) tx - внутренний параметр
#define idinternal1_m1744_tx	 1092	//(internal1_m1744_tx) tx - внутренний параметр
#define internal1_m1742_tx	 BUFFER[3374]	//(internal1_m1742_tx) tx - внутренний параметр
#define idinternal1_m1742_tx	 1093	//(internal1_m1742_tx) tx - внутренний параметр
#define internal1_m1741_tx	 BUFFER[3379]	//(internal1_m1741_tx) tx - внутренний параметр
#define idinternal1_m1741_tx	 1094	//(internal1_m1741_tx) tx - внутренний параметр
#define internal1_m1782_tx	 BUFFER[3384]	//(internal1_m1782_tx) tx - внутренний параметр
#define idinternal1_m1782_tx	 1095	//(internal1_m1782_tx) tx - внутренний параметр
#define internal1_m1790_tx	 BUFFER[3389]	//(internal1_m1790_tx) tx - внутренний параметр
#define idinternal1_m1790_tx	 1096	//(internal1_m1790_tx) tx - внутренний параметр
#define internal1_m1797_tx	 BUFFER[3394]	//(internal1_m1797_tx) tx - внутренний параметр
#define idinternal1_m1797_tx	 1097	//(internal1_m1797_tx) tx - внутренний параметр
#define internal1_m1798_tx	 BUFFER[3399]	//(internal1_m1798_tx) tx - внутренний параметр
#define idinternal1_m1798_tx	 1098	//(internal1_m1798_tx) tx - внутренний параметр
#define internal1_m1788_tx	 BUFFER[3404]	//(internal1_m1788_tx) tx - внутренний параметр
#define idinternal1_m1788_tx	 1099	//(internal1_m1788_tx) tx - внутренний параметр
#define internal1_m1763_tx	 BUFFER[3409]	//(internal1_m1763_tx) tx - внутренний параметр
#define idinternal1_m1763_tx	 1100	//(internal1_m1763_tx) tx - внутренний параметр
#define internal1_m1777_tx	 BUFFER[3414]	//(internal1_m1777_tx) tx - внутренний параметр
#define idinternal1_m1777_tx	 1101	//(internal1_m1777_tx) tx - внутренний параметр
#define internal1_m452_tx	 BUFFER[3419]	//(internal1_m452_tx) tx - внутренний параметр
#define idinternal1_m452_tx	 1102	//(internal1_m452_tx) tx - внутренний параметр
#define internal1_m443_tx	 BUFFER[3424]	//(internal1_m443_tx) tx - внутренний параметр
#define idinternal1_m443_tx	 1103	//(internal1_m443_tx) tx - внутренний параметр
#define internal1_m444_tx	 BUFFER[3429]	//(internal1_m444_tx) tx - внутренний параметр
#define idinternal1_m444_tx	 1104	//(internal1_m444_tx) tx - внутренний параметр
#define internal1_m446_tx	 BUFFER[3434]	//(internal1_m446_tx) tx - внутренний параметр
#define idinternal1_m446_tx	 1105	//(internal1_m446_tx) tx - внутренний параметр
#define internal1_m460_tx	 BUFFER[3439]	//(internal1_m460_tx) tx - внутренний параметр
#define idinternal1_m460_tx	 1106	//(internal1_m460_tx) tx - внутренний параметр
#define internal1_m410_tx	 BUFFER[3444]	//(internal1_m410_tx) tx - внутренний параметр
#define idinternal1_m410_tx	 1107	//(internal1_m410_tx) tx - внутренний параметр
#define internal1_m407_tx	 BUFFER[3449]	//(internal1_m407_tx) tx - внутренний параметр
#define idinternal1_m407_tx	 1108	//(internal1_m407_tx) tx - внутренний параметр
#define internal1_m406_tx	 BUFFER[3454]	//(internal1_m406_tx) tx - внутренний параметр
#define idinternal1_m406_tx	 1109	//(internal1_m406_tx) tx - внутренний параметр
#define internal1_m405_tx	 BUFFER[3459]	//(internal1_m405_tx) tx - внутренний параметр
#define idinternal1_m405_tx	 1110	//(internal1_m405_tx) tx - внутренний параметр
#define internal1_m865_tx	 BUFFER[3464]	//(internal1_m865_tx) tx - внутренний параметр
#define idinternal1_m865_tx	 1111	//(internal1_m865_tx) tx - внутренний параметр
#define internal1_m861_tx	 BUFFER[3469]	//(internal1_m861_tx) tx - внутренний параметр
#define idinternal1_m861_tx	 1112	//(internal1_m861_tx) tx - внутренний параметр
#define internal1_m860_tx	 BUFFER[3474]	//(internal1_m860_tx) tx - внутренний параметр
#define idinternal1_m860_tx	 1113	//(internal1_m860_tx) tx - внутренний параметр
#define internal1_m859_tx	 BUFFER[3479]	//(internal1_m859_tx) tx - внутренний параметр
#define idinternal1_m859_tx	 1114	//(internal1_m859_tx) tx - внутренний параметр
#define internal1_m1303_tx	 BUFFER[3484]	//(internal1_m1303_tx) tx - внутренний параметр
#define idinternal1_m1303_tx	 1115	//(internal1_m1303_tx) tx - внутренний параметр
#define internal1_m1300_tx	 BUFFER[3489]	//(internal1_m1300_tx) tx - внутренний параметр
#define idinternal1_m1300_tx	 1116	//(internal1_m1300_tx) tx - внутренний параметр
#define internal1_m1299_tx	 BUFFER[3494]	//(internal1_m1299_tx) tx - внутренний параметр
#define idinternal1_m1299_tx	 1117	//(internal1_m1299_tx) tx - внутренний параметр
#define internal1_m1082_tx	 BUFFER[3499]	//(internal1_m1082_tx) tx - внутренний параметр
#define idinternal1_m1082_tx	 1118	//(internal1_m1082_tx) tx - внутренний параметр
#define internal1_m2239_tx	 BUFFER[3504]	//(internal1_m2239_tx) tx - внутренний параметр
#define idinternal1_m2239_tx	 1119	//(internal1_m2239_tx) tx - внутренний параметр
#define internal1_m1093_tx	 BUFFER[3509]	//(internal1_m1093_tx) tx - внутренний параметр
#define idinternal1_m1093_tx	 1120	//(internal1_m1093_tx) tx - внутренний параметр
#define internal1_m1095_tx	 BUFFER[3514]	//(internal1_m1095_tx) tx - внутренний параметр
#define idinternal1_m1095_tx	 1121	//(internal1_m1095_tx) tx - внутренний параметр
#define internal1_m1094_tx	 BUFFER[3519]	//(internal1_m1094_tx) tx - внутренний параметр
#define idinternal1_m1094_tx	 1122	//(internal1_m1094_tx) tx - внутренний параметр
#define internal1_m2233_tx	 BUFFER[3524]	//(internal1_m2233_tx) tx - внутренний параметр
#define idinternal1_m2233_tx	 1123	//(internal1_m2233_tx) tx - внутренний параметр
#define internal1_m1084_tx	 BUFFER[3529]	//(internal1_m1084_tx) tx - внутренний параметр
#define idinternal1_m1084_tx	 1124	//(internal1_m1084_tx) tx - внутренний параметр
#define internal1_m2238_tx	 BUFFER[3534]	//(internal1_m2238_tx) tx - внутренний параметр
#define idinternal1_m2238_tx	 1125	//(internal1_m2238_tx) tx - внутренний параметр
#define internal1_m1092_tx	 BUFFER[3539]	//(internal1_m1092_tx) tx - внутренний параметр
#define idinternal1_m1092_tx	 1126	//(internal1_m1092_tx) tx - внутренний параметр
#define internal1_m1074_tx	 BUFFER[3544]	//(internal1_m1074_tx) tx - внутренний параметр
#define idinternal1_m1074_tx	 1127	//(internal1_m1074_tx) tx - внутренний параметр
#define internal1_m1073_tx	 BUFFER[3549]	//(internal1_m1073_tx) tx - внутренний параметр
#define idinternal1_m1073_tx	 1128	//(internal1_m1073_tx) tx - внутренний параметр
#define internal1_m1069_tx	 BUFFER[3554]	//(internal1_m1069_tx) tx - внутренний параметр
#define idinternal1_m1069_tx	 1129	//(internal1_m1069_tx) tx - внутренний параметр
#define internal1_m1091_tx	 BUFFER[3559]	//(internal1_m1091_tx) tx - внутренний параметр
#define idinternal1_m1091_tx	 1130	//(internal1_m1091_tx) tx - внутренний параметр
#define internal1_m1059_tx	 BUFFER[3564]	//(internal1_m1059_tx) tx - внутренний параметр
#define idinternal1_m1059_tx	 1131	//(internal1_m1059_tx) tx - внутренний параметр
#define internal1_m1057_tx	 BUFFER[3569]	//(internal1_m1057_tx) tx - внутренний параметр
#define idinternal1_m1057_tx	 1132	//(internal1_m1057_tx) tx - внутренний параметр
#define internal1_m1056_tx	 BUFFER[3574]	//(internal1_m1056_tx) tx - внутренний параметр
#define idinternal1_m1056_tx	 1133	//(internal1_m1056_tx) tx - внутренний параметр
#define internal1_m1035_tx	 BUFFER[3579]	//(internal1_m1035_tx) tx - внутренний параметр
#define idinternal1_m1035_tx	 1134	//(internal1_m1035_tx) tx - внутренний параметр
#define internal1_m1034_tx	 BUFFER[3584]	//(internal1_m1034_tx) tx - внутренний параметр
#define idinternal1_m1034_tx	 1135	//(internal1_m1034_tx) tx - внутренний параметр
#define internal1_m1024_tx	 BUFFER[3589]	//(internal1_m1024_tx) tx - внутренний параметр
#define idinternal1_m1024_tx	 1136	//(internal1_m1024_tx) tx - внутренний параметр
#define internal1_m1041_tx	 BUFFER[3594]	//(internal1_m1041_tx) tx - внутренний параметр
#define idinternal1_m1041_tx	 1137	//(internal1_m1041_tx) tx - внутренний параметр
#define internal1_m1438_tx	 BUFFER[3599]	//(internal1_m1438_tx) tx - внутренний параметр
#define idinternal1_m1438_tx	 1138	//(internal1_m1438_tx) tx - внутренний параметр
#define internal1_m1437_tx	 BUFFER[3604]	//(internal1_m1437_tx) tx - внутренний параметр
#define idinternal1_m1437_tx	 1139	//(internal1_m1437_tx) tx - внутренний параметр
#define internal1_m2185_tx	 BUFFER[3609]	//(internal1_m2185_tx) tx - внутренний параметр
#define idinternal1_m2185_tx	 1140	//(internal1_m2185_tx) tx - внутренний параметр
#define internal1_m1428_tx	 BUFFER[3614]	//(internal1_m1428_tx) tx - внутренний параметр
#define idinternal1_m1428_tx	 1141	//(internal1_m1428_tx) tx - внутренний параметр
#define internal1_m1429_tx	 BUFFER[3619]	//(internal1_m1429_tx) tx - внутренний параметр
#define idinternal1_m1429_tx	 1142	//(internal1_m1429_tx) tx - внутренний параметр
#define internal1_m1436_tx	 BUFFER[3624]	//(internal1_m1436_tx) tx - внутренний параметр
#define idinternal1_m1436_tx	 1143	//(internal1_m1436_tx) tx - внутренний параметр
#define internal1_m1419_tx	 BUFFER[3629]	//(internal1_m1419_tx) tx - внутренний параметр
#define idinternal1_m1419_tx	 1144	//(internal1_m1419_tx) tx - внутренний параметр
#define internal1_m1418_tx	 BUFFER[3634]	//(internal1_m1418_tx) tx - внутренний параметр
#define idinternal1_m1418_tx	 1145	//(internal1_m1418_tx) tx - внутренний параметр
#define internal1_m1414_tx	 BUFFER[3639]	//(internal1_m1414_tx) tx - внутренний параметр
#define idinternal1_m1414_tx	 1146	//(internal1_m1414_tx) tx - внутренний параметр
#define internal1_m1435_tx	 BUFFER[3644]	//(internal1_m1435_tx) tx - внутренний параметр
#define idinternal1_m1435_tx	 1147	//(internal1_m1435_tx) tx - внутренний параметр
#define internal1_m1401_tx	 BUFFER[3649]	//(internal1_m1401_tx) tx - внутренний параметр
#define idinternal1_m1401_tx	 1148	//(internal1_m1401_tx) tx - внутренний параметр
#define internal1_m1399_tx	 BUFFER[3654]	//(internal1_m1399_tx) tx - внутренний параметр
#define idinternal1_m1399_tx	 1149	//(internal1_m1399_tx) tx - внутренний параметр
#define internal1_m1405_tx	 BUFFER[3659]	//(internal1_m1405_tx) tx - внутренний параметр
#define idinternal1_m1405_tx	 1150	//(internal1_m1405_tx) tx - внутренний параметр
#define internal1_m250_tx	 BUFFER[3664]	//(internal1_m250_tx) tx - внутренний параметр
#define idinternal1_m250_tx	 1151	//(internal1_m250_tx) tx - внутренний параметр
#define internal1_m265_tx	 BUFFER[3669]	//(internal1_m265_tx) tx - внутренний параметр
#define idinternal1_m265_tx	 1152	//(internal1_m265_tx) tx - внутренний параметр
#define internal1_m272_tx	 BUFFER[3674]	//(internal1_m272_tx) tx - внутренний параметр
#define idinternal1_m272_tx	 1153	//(internal1_m272_tx) tx - внутренний параметр
#define internal1_m271_tx	 BUFFER[3679]	//(internal1_m271_tx) tx - внутренний параметр
#define idinternal1_m271_tx	 1154	//(internal1_m271_tx) tx - внутренний параметр
#define internal1_m257_tx	 BUFFER[3684]	//(internal1_m257_tx) tx - внутренний параметр
#define idinternal1_m257_tx	 1155	//(internal1_m257_tx) tx - внутренний параметр
#define internal1_m253_tx	 BUFFER[3689]	//(internal1_m253_tx) tx - внутренний параметр
#define idinternal1_m253_tx	 1156	//(internal1_m253_tx) tx - внутренний параметр
#define internal1_m269_tx	 BUFFER[3694]	//(internal1_m269_tx) tx - внутренний параметр
#define idinternal1_m269_tx	 1157	//(internal1_m269_tx) tx - внутренний параметр
#define internal1_m241_tx	 BUFFER[3699]	//(internal1_m241_tx) tx - внутренний параметр
#define idinternal1_m241_tx	 1158	//(internal1_m241_tx) tx - внутренний параметр
#define internal1_m240_tx	 BUFFER[3704]	//(internal1_m240_tx) tx - внутренний параметр
#define idinternal1_m240_tx	 1159	//(internal1_m240_tx) tx - внутренний параметр
#define internal1_m236_tx	 BUFFER[3709]	//(internal1_m236_tx) tx - внутренний параметр
#define idinternal1_m236_tx	 1160	//(internal1_m236_tx) tx - внутренний параметр
#define internal1_m268_tx	 BUFFER[3714]	//(internal1_m268_tx) tx - внутренний параметр
#define idinternal1_m268_tx	 1161	//(internal1_m268_tx) tx - внутренний параметр
#define internal1_m225_tx	 BUFFER[3719]	//(internal1_m225_tx) tx - внутренний параметр
#define idinternal1_m225_tx	 1162	//(internal1_m225_tx) tx - внутренний параметр
#define internal1_m227_tx	 BUFFER[3724]	//(internal1_m227_tx) tx - внутренний параметр
#define idinternal1_m227_tx	 1163	//(internal1_m227_tx) tx - внутренний параметр
#define internal1_m224_tx	 BUFFER[3729]	//(internal1_m224_tx) tx - внутренний параметр
#define idinternal1_m224_tx	 1164	//(internal1_m224_tx) tx - внутренний параметр
#define internal1_m203_tx	 BUFFER[3734]	//(internal1_m203_tx) tx - внутренний параметр
#define idinternal1_m203_tx	 1165	//(internal1_m203_tx) tx - внутренний параметр
#define internal1_m202_tx	 BUFFER[3739]	//(internal1_m202_tx) tx - внутренний параметр
#define idinternal1_m202_tx	 1166	//(internal1_m202_tx) tx - внутренний параметр
#define internal1_m201_tx	 BUFFER[3744]	//(internal1_m201_tx) tx - внутренний параметр
#define idinternal1_m201_tx	 1167	//(internal1_m201_tx) tx - внутренний параметр
#define internal1_m209_tx	 BUFFER[3749]	//(internal1_m209_tx) tx - внутренний параметр
#define idinternal1_m209_tx	 1168	//(internal1_m209_tx) tx - внутренний параметр
#define internal1_m1381_tx	 BUFFER[3754]	//(internal1_m1381_tx) tx - внутренний параметр
#define idinternal1_m1381_tx	 1169	//(internal1_m1381_tx) tx - внутренний параметр
#define internal1_m1363_tx	 BUFFER[3759]	//(internal1_m1363_tx) tx - внутренний параметр
#define idinternal1_m1363_tx	 1170	//(internal1_m1363_tx) tx - внутренний параметр
#define internal1_m1368_tx	 BUFFER[3764]	//(internal1_m1368_tx) tx - внутренний параметр
#define idinternal1_m1368_tx	 1171	//(internal1_m1368_tx) tx - внутренний параметр
#define internal1_m1383_tx	 BUFFER[3769]	//(internal1_m1383_tx) tx - внутренний параметр
#define idinternal1_m1383_tx	 1172	//(internal1_m1383_tx) tx - внутренний параметр
#define internal1_m924_tx	 BUFFER[3774]	//(internal1_m924_tx) tx - внутренний параметр
#define idinternal1_m924_tx	 1173	//(internal1_m924_tx) tx - внутренний параметр
#define internal1_m929_tx	 BUFFER[3779]	//(internal1_m929_tx) tx - внутренний параметр
#define idinternal1_m929_tx	 1174	//(internal1_m929_tx) tx - внутренний параметр
#define internal1_m919_tx	 BUFFER[3784]	//(internal1_m919_tx) tx - внутренний параметр
#define idinternal1_m919_tx	 1175	//(internal1_m919_tx) tx - внутренний параметр
#define internal1_m920_tx	 BUFFER[3789]	//(internal1_m920_tx) tx - внутренний параметр
#define idinternal1_m920_tx	 1176	//(internal1_m920_tx) tx - внутренний параметр
#define internal1_m2488_sttlf	 BUFFER[3794]	//(internal1_m2488_sttlf) sttlf - счетчик для вещественного формата
#define idinternal1_m2488_sttlf	 1177	//(internal1_m2488_sttlf) sttlf - счетчик для вещественного формата
#define internal1_m1882_q0	 BUFFER[3797]	//(internal1_m1882_q0) q0 - внутренний параметр
#define idinternal1_m1882_q0	 1178	//(internal1_m1882_q0) q0 - внутренний параметр
#define internal1_m2320_q0	 BUFFER[3799]	//(internal1_m2320_q0) q0 - внутренний параметр
#define idinternal1_m2320_q0	 1179	//(internal1_m2320_q0) q0 - внутренний параметр
#define internal1_m2304_q0	 BUFFER[3801]	//(internal1_m2304_q0) q0 - внутренний параметр
#define idinternal1_m2304_q0	 1180	//(internal1_m2304_q0) q0 - внутренний параметр
#define internal1_m2351_q0	 BUFFER[3803]	//(internal1_m2351_q0) q0 - внутренний параметр
#define idinternal1_m2351_q0	 1181	//(internal1_m2351_q0) q0 - внутренний параметр
#define internal1_m2335_q0	 BUFFER[3805]	//(internal1_m2335_q0) q0 - внутренний параметр
#define idinternal1_m2335_q0	 1182	//(internal1_m2335_q0) q0 - внутренний параметр
#define internal1_m2326_q0	 BUFFER[3807]	//(internal1_m2326_q0) q0 - внутренний параметр
#define idinternal1_m2326_q0	 1183	//(internal1_m2326_q0) q0 - внутренний параметр
#define internal1_m2307_q0	 BUFFER[3809]	//(internal1_m2307_q0) q0 - внутренний параметр
#define idinternal1_m2307_q0	 1184	//(internal1_m2307_q0) q0 - внутренний параметр
#define internal1_m2324_q0	 BUFFER[3811]	//(internal1_m2324_q0) q0 - внутренний параметр
#define idinternal1_m2324_q0	 1185	//(internal1_m2324_q0) q0 - внутренний параметр
#define internal1_m2305_q0	 BUFFER[3813]	//(internal1_m2305_q0) q0 - внутренний параметр
#define idinternal1_m2305_q0	 1186	//(internal1_m2305_q0) q0 - внутренний параметр
#define internal1_m2303_q0	 BUFFER[3815]	//(internal1_m2303_q0) q0 - внутренний параметр
#define idinternal1_m2303_q0	 1187	//(internal1_m2303_q0) q0 - внутренний параметр
#define internal1_m2302_q0	 BUFFER[3817]	//(internal1_m2302_q0) q0 - внутренний параметр
#define idinternal1_m2302_q0	 1188	//(internal1_m2302_q0) q0 - внутренний параметр
#define internal1_m2316_q0	 BUFFER[3819]	//(internal1_m2316_q0) q0 - внутренний параметр
#define idinternal1_m2316_q0	 1189	//(internal1_m2316_q0) q0 - внутренний параметр
#define internal1_m2314_q0	 BUFFER[3821]	//(internal1_m2314_q0) q0 - внутренний параметр
#define idinternal1_m2314_q0	 1190	//(internal1_m2314_q0) q0 - внутренний параметр
#define internal1_m2322_q0	 BUFFER[3823]	//(internal1_m2322_q0) q0 - внутренний параметр
#define idinternal1_m2322_q0	 1191	//(internal1_m2322_q0) q0 - внутренний параметр
#define internal1_m2318_q0	 BUFFER[3825]	//(internal1_m2318_q0) q0 - внутренний параметр
#define idinternal1_m2318_q0	 1192	//(internal1_m2318_q0) q0 - внутренний параметр
#define internal1_m2357_q0	 BUFFER[3827]	//(internal1_m2357_q0) q0 - внутренний параметр
#define idinternal1_m2357_q0	 1193	//(internal1_m2357_q0) q0 - внутренний параметр
#define internal1_m2338_q0	 BUFFER[3829]	//(internal1_m2338_q0) q0 - внутренний параметр
#define idinternal1_m2338_q0	 1194	//(internal1_m2338_q0) q0 - внутренний параметр
#define internal1_m2355_q0	 BUFFER[3831]	//(internal1_m2355_q0) q0 - внутренний параметр
#define idinternal1_m2355_q0	 1195	//(internal1_m2355_q0) q0 - внутренний параметр
#define internal1_m2337_q0	 BUFFER[3833]	//(internal1_m2337_q0) q0 - внутренний параметр
#define idinternal1_m2337_q0	 1196	//(internal1_m2337_q0) q0 - внутренний параметр
#define internal1_m2334_q0	 BUFFER[3835]	//(internal1_m2334_q0) q0 - внутренний параметр
#define idinternal1_m2334_q0	 1197	//(internal1_m2334_q0) q0 - внутренний параметр
#define internal1_m2333_q0	 BUFFER[3837]	//(internal1_m2333_q0) q0 - внутренний параметр
#define idinternal1_m2333_q0	 1198	//(internal1_m2333_q0) q0 - внутренний параметр
#define internal1_m2347_q0	 BUFFER[3839]	//(internal1_m2347_q0) q0 - внутренний параметр
#define idinternal1_m2347_q0	 1199	//(internal1_m2347_q0) q0 - внутренний параметр
#define internal1_m2345_q0	 BUFFER[3841]	//(internal1_m2345_q0) q0 - внутренний параметр
#define idinternal1_m2345_q0	 1200	//(internal1_m2345_q0) q0 - внутренний параметр
#define internal1_m2210_tx	 BUFFER[3843]	//(internal1_m2210_tx) tx - внутренний параметр
#define idinternal1_m2210_tx	 1201	//(internal1_m2210_tx) tx - внутренний параметр
#define internal1_m2189_tx	 BUFFER[3848]	//(internal1_m2189_tx) tx - внутренний параметр
#define idinternal1_m2189_tx	 1202	//(internal1_m2189_tx) tx - внутренний параметр
#define internal1_m1905_Pv0	 BUFFER[3853]	//(internal1_m1905_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1905_Pv0	 1203	//(internal1_m1905_Pv0)  - Пер. выключатель механизма
#define internal1_m1905_Zv0	 BUFFER[3855]	//(internal1_m1905_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1905_Zv0	 1204	//(internal1_m1905_Zv0)  - Зад. выключатель механизма
#define internal1_m1905_MyFirstEnterFlag	 BUFFER[3857]	//(internal1_m1905_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1905_MyFirstEnterFlag	 1205	//(internal1_m1905_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m1903_Pv0	 BUFFER[3859]	//(internal1_m1903_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1903_Pv0	 1206	//(internal1_m1903_Pv0)  - Пер. выключатель механизма
#define internal1_m1903_Zv0	 BUFFER[3861]	//(internal1_m1903_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1903_Zv0	 1207	//(internal1_m1903_Zv0)  - Зад. выключатель механизма
#define internal1_m1903_MyFirstEnterFlag	 BUFFER[3863]	//(internal1_m1903_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1903_MyFirstEnterFlag	 1208	//(internal1_m1903_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m2374_tx	 BUFFER[3865]	//(internal1_m2374_tx) tx - время накопленное сек
#define idinternal1_m2374_tx	 1209	//(internal1_m2374_tx) tx - время накопленное сек
#define internal1_m2374_y0	 BUFFER[3870]	//(internal1_m2374_y0) y0
#define idinternal1_m2374_y0	 1210	//(internal1_m2374_y0) y0
#define internal1_m2379_tx	 BUFFER[3871]	//(internal1_m2379_tx) tx - время накопленное сек
#define idinternal1_m2379_tx	 1211	//(internal1_m2379_tx) tx - время накопленное сек
#define internal1_m2379_y0	 BUFFER[3876]	//(internal1_m2379_y0) y0
#define idinternal1_m2379_y0	 1212	//(internal1_m2379_y0) y0
#define internal1_m2378_tx	 BUFFER[3877]	//(internal1_m2378_tx) tx - время накопленное сек
#define idinternal1_m2378_tx	 1213	//(internal1_m2378_tx) tx - время накопленное сек
#define internal1_m2378_y0	 BUFFER[3882]	//(internal1_m2378_y0) y0
#define idinternal1_m2378_y0	 1214	//(internal1_m2378_y0) y0
#define internal1_m2415_tx	 BUFFER[3883]	//(internal1_m2415_tx) tx - внутренний параметр
#define idinternal1_m2415_tx	 1215	//(internal1_m2415_tx) tx - внутренний параметр
#define internal1_m2413_tx	 BUFFER[3888]	//(internal1_m2413_tx) tx - время накопленное сек
#define idinternal1_m2413_tx	 1216	//(internal1_m2413_tx) tx - время накопленное сек
#define internal1_m2413_y0	 BUFFER[3893]	//(internal1_m2413_y0) y0
#define idinternal1_m2413_y0	 1217	//(internal1_m2413_y0) y0
#define internal1_m2418_q0	 BUFFER[3894]	//(internal1_m2418_q0) q0 - внутренний параметр
#define idinternal1_m2418_q0	 1218	//(internal1_m2418_q0) q0 - внутренний параметр
#define internal1_m2385_q0	 BUFFER[3896]	//(internal1_m2385_q0) q0 - внутренний параметр
#define idinternal1_m2385_q0	 1219	//(internal1_m2385_q0) q0 - внутренний параметр
#define internal1_m2393_tx	 BUFFER[3898]	//(internal1_m2393_tx) tx - внутренний параметр
#define idinternal1_m2393_tx	 1220	//(internal1_m2393_tx) tx - внутренний параметр
#define internal1_m2391_q0	 BUFFER[3903]	//(internal1_m2391_q0) q0 - внутренний параметр
#define idinternal1_m2391_q0	 1221	//(internal1_m2391_q0) q0 - внутренний параметр
#define internal1_m2204_tx	 BUFFER[3905]	//(internal1_m2204_tx) tx - время накопленное сек
#define idinternal1_m2204_tx	 1222	//(internal1_m2204_tx) tx - время накопленное сек
#define internal1_m2204_y0	 BUFFER[3910]	//(internal1_m2204_y0) y0
#define idinternal1_m2204_y0	 1223	//(internal1_m2204_y0) y0
#define internal1_m2196_tx	 BUFFER[3911]	//(internal1_m2196_tx) tx - время накопленное сек
#define idinternal1_m2196_tx	 1224	//(internal1_m2196_tx) tx - время накопленное сек
#define internal1_m2196_y0	 BUFFER[3916]	//(internal1_m2196_y0) y0
#define idinternal1_m2196_y0	 1225	//(internal1_m2196_y0) y0
#define internal1_m1892_q0	 BUFFER[3917]	//(internal1_m1892_q0) q0 - внутренний параметр
#define idinternal1_m1892_q0	 1226	//(internal1_m1892_q0) q0 - внутренний параметр
#define internal1_m1897_q0	 BUFFER[3919]	//(internal1_m1897_q0) q0 - внутренний параметр
#define idinternal1_m1897_q0	 1227	//(internal1_m1897_q0) q0 - внутренний параметр
#define internal1_m1889_q0	 BUFFER[3921]	//(internal1_m1889_q0) q0 - внутренний параметр
#define idinternal1_m1889_q0	 1228	//(internal1_m1889_q0) q0 - внутренний параметр
#define internal1_m1931_q0	 BUFFER[3923]	//(internal1_m1931_q0) q0 - внутренний параметр
#define idinternal1_m1931_q0	 1229	//(internal1_m1931_q0) q0 - внутренний параметр
#define internal1_m829_tx	 BUFFER[3925]	//(internal1_m829_tx) tx - время накопленное сек
#define idinternal1_m829_tx	 1230	//(internal1_m829_tx) tx - время накопленное сек
#define internal1_m829_y0	 BUFFER[3930]	//(internal1_m829_y0) y0
#define idinternal1_m829_y0	 1231	//(internal1_m829_y0) y0
#define internal1_m2200_tx	 BUFFER[3931]	//(internal1_m2200_tx) tx - внутренний параметр
#define idinternal1_m2200_tx	 1232	//(internal1_m2200_tx) tx - внутренний параметр
#define internal1_m2203_q0	 BUFFER[3936]	//(internal1_m2203_q0) q0 - внутренний параметр
#define idinternal1_m2203_q0	 1233	//(internal1_m2203_q0) q0 - внутренний параметр
#define internal1_m2195_q0	 BUFFER[3938]	//(internal1_m2195_q0) q0 - внутренний параметр
#define idinternal1_m2195_q0	 1234	//(internal1_m2195_q0) q0 - внутренний параметр
#define internal1_m2164_tx	 BUFFER[3940]	//(internal1_m2164_tx) tx - внутренний параметр
#define idinternal1_m2164_tx	 1235	//(internal1_m2164_tx) tx - внутренний параметр
#define internal1_m2175_tx	 BUFFER[3945]	//(internal1_m2175_tx) tx - внутренний параметр
#define idinternal1_m2175_tx	 1236	//(internal1_m2175_tx) tx - внутренний параметр
#define internal1_m2161_tx	 BUFFER[3950]	//(internal1_m2161_tx) tx - внутренний параметр
#define idinternal1_m2161_tx	 1237	//(internal1_m2161_tx) tx - внутренний параметр
#define internal1_m2167_q0	 BUFFER[3955]	//(internal1_m2167_q0) q0 - внутренний параметр
#define idinternal1_m2167_q0	 1238	//(internal1_m2167_q0) q0 - внутренний параметр
#define internal1_m2179_q0	 BUFFER[3957]	//(internal1_m2179_q0) q0 - внутренний параметр
#define idinternal1_m2179_q0	 1239	//(internal1_m2179_q0) q0 - внутренний параметр
#define internal1_m2136_tx	 BUFFER[3959]	//(internal1_m2136_tx) tx - внутренний параметр
#define idinternal1_m2136_tx	 1240	//(internal1_m2136_tx) tx - внутренний параметр
#define internal1_m51_tx	 BUFFER[3964]	//(internal1_m51_tx) tx - внутренний параметр
#define idinternal1_m51_tx	 1241	//(internal1_m51_tx) tx - внутренний параметр
#define internal1_m363_tx	 BUFFER[3969]	//(internal1_m363_tx) tx - внутренний параметр
#define idinternal1_m363_tx	 1242	//(internal1_m363_tx) tx - внутренний параметр
#define internal1_m317_tx	 BUFFER[3974]	//(internal1_m317_tx) tx - внутренний параметр
#define idinternal1_m317_tx	 1243	//(internal1_m317_tx) tx - внутренний параметр
#define internal1_m830_tx	 BUFFER[3979]	//(internal1_m830_tx) tx - внутренний параметр
#define idinternal1_m830_tx	 1244	//(internal1_m830_tx) tx - внутренний параметр
#define internal1_m1600_tx	 BUFFER[3984]	//(internal1_m1600_tx) tx - внутренний параметр
#define idinternal1_m1600_tx	 1245	//(internal1_m1600_tx) tx - внутренний параметр
#define internal1_m120_tx	 BUFFER[3989]	//(internal1_m120_tx) tx - внутренний параметр
#define idinternal1_m120_tx	 1246	//(internal1_m120_tx) tx - внутренний параметр
#define internal1_m122_tx	 BUFFER[3994]	//(internal1_m122_tx) tx - внутренний параметр
#define idinternal1_m122_tx	 1247	//(internal1_m122_tx) tx - внутренний параметр
#define internal1_m127_tx	 BUFFER[3999]	//(internal1_m127_tx) tx - внутренний параметр
#define idinternal1_m127_tx	 1248	//(internal1_m127_tx) tx - внутренний параметр
#define internal1_m21_tx	 BUFFER[4004]	//(internal1_m21_tx) tx - внутренний параметр
#define idinternal1_m21_tx	 1249	//(internal1_m21_tx) tx - внутренний параметр
#define internal1_m13_tx	 BUFFER[4009]	//(internal1_m13_tx) tx - внутренний параметр
#define idinternal1_m13_tx	 1250	//(internal1_m13_tx) tx - внутренний параметр
#define internal1_m2146_tx	 BUFFER[4014]	//(internal1_m2146_tx) tx - внутренний параметр
#define idinternal1_m2146_tx	 1251	//(internal1_m2146_tx) tx - внутренний параметр
#define internal1_m2133_tx	 BUFFER[4019]	//(internal1_m2133_tx) tx - внутренний параметр
#define idinternal1_m2133_tx	 1252	//(internal1_m2133_tx) tx - внутренний параметр
#define internal1_m2251_tx	 BUFFER[4024]	//(internal1_m2251_tx) tx - внутренний параметр
#define idinternal1_m2251_tx	 1253	//(internal1_m2251_tx) tx - внутренний параметр
#define internal1_m2253_tx	 BUFFER[4029]	//(internal1_m2253_tx) tx - внутренний параметр
#define idinternal1_m2253_tx	 1254	//(internal1_m2253_tx) tx - внутренний параметр
#define internal1_m82_tx	 BUFFER[4034]	//(internal1_m82_tx) tx - внутренний параметр
#define idinternal1_m82_tx	 1255	//(internal1_m82_tx) tx - внутренний параметр
#define internal1_m334_tx	 BUFFER[4039]	//(internal1_m334_tx) tx - время накопленное сек
#define idinternal1_m334_tx	 1256	//(internal1_m334_tx) tx - время накопленное сек
#define internal1_m334_y0	 BUFFER[4044]	//(internal1_m334_y0) y0
#define idinternal1_m334_y0	 1257	//(internal1_m334_y0) y0
#define internal1_m2045_tx	 BUFFER[4045]	//(internal1_m2045_tx) tx - время накопленное сек
#define idinternal1_m2045_tx	 1258	//(internal1_m2045_tx) tx - время накопленное сек
#define internal1_m2045_y0	 BUFFER[4050]	//(internal1_m2045_y0) y0
#define idinternal1_m2045_y0	 1259	//(internal1_m2045_y0) y0
#define internal1_m2059_q0	 BUFFER[4051]	//(internal1_m2059_q0) q0 - внутренний параметр
#define idinternal1_m2059_q0	 1260	//(internal1_m2059_q0) q0 - внутренний параметр
#define internal1_m1620_q0	 BUFFER[4056]	//(internal1_m1620_q0) q0 - внутренний параметр
#define idinternal1_m1620_q0	 1261	//(internal1_m1620_q0) q0 - внутренний параметр
#define internal1_m1659_q0	 BUFFER[4061]	//(internal1_m1659_q0) q0 - внутренний параметр
#define idinternal1_m1659_q0	 1262	//(internal1_m1659_q0) q0 - внутренний параметр
#define internal1_m1656_q0	 BUFFER[4066]	//(internal1_m1656_q0) q0 - внутренний параметр
#define idinternal1_m1656_q0	 1263	//(internal1_m1656_q0) q0 - внутренний параметр
#define internal1_m2098_q0	 BUFFER[4071]	//(internal1_m2098_q0) q0 - внутренний параметр
#define idinternal1_m2098_q0	 1264	//(internal1_m2098_q0) q0 - внутренний параметр
#define internal1_m2076_tx	 BUFFER[4076]	//(internal1_m2076_tx) tx - время накопленное сек
#define idinternal1_m2076_tx	 1265	//(internal1_m2076_tx) tx - время накопленное сек
#define internal1_m2076_y0	 BUFFER[4081]	//(internal1_m2076_y0) y0
#define idinternal1_m2076_y0	 1266	//(internal1_m2076_y0) y0
#define internal1_m2091_tx	 BUFFER[4082]	//(internal1_m2091_tx) tx - время накопленное сек
#define idinternal1_m2091_tx	 1267	//(internal1_m2091_tx) tx - время накопленное сек
#define internal1_m2091_y0	 BUFFER[4087]	//(internal1_m2091_y0) y0
#define idinternal1_m2091_y0	 1268	//(internal1_m2091_y0) y0
#define internal1_m2088_tx	 BUFFER[4088]	//(internal1_m2088_tx) tx - время накопленное сек
#define idinternal1_m2088_tx	 1269	//(internal1_m2088_tx) tx - время накопленное сек
#define internal1_m2088_y0	 BUFFER[4093]	//(internal1_m2088_y0) y0
#define idinternal1_m2088_y0	 1270	//(internal1_m2088_y0) y0
#define internal1_m2231_tx	 BUFFER[4094]	//(internal1_m2231_tx) tx - время накопленное сек
#define idinternal1_m2231_tx	 1271	//(internal1_m2231_tx) tx - время накопленное сек
#define internal1_m2231_y0	 BUFFER[4099]	//(internal1_m2231_y0) y0
#define idinternal1_m2231_y0	 1272	//(internal1_m2231_y0) y0
#define internal1_m2242_tx	 BUFFER[4100]	//(internal1_m2242_tx) tx - время накопленное сек
#define idinternal1_m2242_tx	 1273	//(internal1_m2242_tx) tx - время накопленное сек
#define internal1_m2242_y0	 BUFFER[4105]	//(internal1_m2242_y0) y0
#define idinternal1_m2242_y0	 1274	//(internal1_m2242_y0) y0
#define internal1_m1999_tx	 BUFFER[4106]	//(internal1_m1999_tx) tx - время накопленное сек
#define idinternal1_m1999_tx	 1275	//(internal1_m1999_tx) tx - время накопленное сек
#define internal1_m1999_y0	 BUFFER[4111]	//(internal1_m1999_y0) y0
#define idinternal1_m1999_y0	 1276	//(internal1_m1999_y0) y0
#define internal1_m1998_tx	 BUFFER[4112]	//(internal1_m1998_tx) tx - время накопленное сек
#define idinternal1_m1998_tx	 1277	//(internal1_m1998_tx) tx - время накопленное сек
#define internal1_m1998_y0	 BUFFER[4117]	//(internal1_m1998_y0) y0
#define idinternal1_m1998_y0	 1278	//(internal1_m1998_y0) y0
#define internal1_m1997_tx	 BUFFER[4118]	//(internal1_m1997_tx) tx - время накопленное сек
#define idinternal1_m1997_tx	 1279	//(internal1_m1997_tx) tx - время накопленное сек
#define internal1_m1997_y0	 BUFFER[4123]	//(internal1_m1997_y0) y0
#define idinternal1_m1997_y0	 1280	//(internal1_m1997_y0) y0
#define internal1_m1996_tx	 BUFFER[4124]	//(internal1_m1996_tx) tx - время накопленное сек
#define idinternal1_m1996_tx	 1281	//(internal1_m1996_tx) tx - время накопленное сек
#define internal1_m1996_y0	 BUFFER[4129]	//(internal1_m1996_y0) y0
#define idinternal1_m1996_y0	 1282	//(internal1_m1996_y0) y0
#define internal1_m1672_tx	 BUFFER[4130]	//(internal1_m1672_tx) tx - время накопленное сек
#define idinternal1_m1672_tx	 1283	//(internal1_m1672_tx) tx - время накопленное сек
#define internal1_m1672_y0	 BUFFER[4135]	//(internal1_m1672_y0) y0
#define idinternal1_m1672_y0	 1284	//(internal1_m1672_y0) y0
#define internal1_m1666_tx	 BUFFER[4136]	//(internal1_m1666_tx) tx - время накопленное сек
#define idinternal1_m1666_tx	 1285	//(internal1_m1666_tx) tx - время накопленное сек
#define internal1_m1666_y0	 BUFFER[4141]	//(internal1_m1666_y0) y0
#define idinternal1_m1666_y0	 1286	//(internal1_m1666_y0) y0
#define internal1_m1616_tx	 BUFFER[4142]	//(internal1_m1616_tx) tx - время накопленное сек
#define idinternal1_m1616_tx	 1287	//(internal1_m1616_tx) tx - время накопленное сек
#define internal1_m1616_y0	 BUFFER[4147]	//(internal1_m1616_y0) y0
#define idinternal1_m1616_y0	 1288	//(internal1_m1616_y0) y0
#define internal1_m917_tx	 BUFFER[4148]	//(internal1_m917_tx) tx - время накопленное сек
#define idinternal1_m917_tx	 1289	//(internal1_m917_tx) tx - время накопленное сек
#define internal1_m917_y0	 BUFFER[4153]	//(internal1_m917_y0) y0
#define idinternal1_m917_y0	 1290	//(internal1_m917_y0) y0
#define internal1_m916_tx	 BUFFER[4154]	//(internal1_m916_tx) tx - время накопленное сек
#define idinternal1_m916_tx	 1291	//(internal1_m916_tx) tx - время накопленное сек
#define internal1_m916_y0	 BUFFER[4159]	//(internal1_m916_y0) y0
#define idinternal1_m916_y0	 1292	//(internal1_m916_y0) y0
#define internal1_m934_tx	 BUFFER[4160]	//(internal1_m934_tx) tx - время накопленное сек
#define idinternal1_m934_tx	 1293	//(internal1_m934_tx) tx - время накопленное сек
#define internal1_m934_y0	 BUFFER[4165]	//(internal1_m934_y0) y0
#define idinternal1_m934_y0	 1294	//(internal1_m934_y0) y0
#define internal1_m193_tx	 BUFFER[4166]	//(internal1_m193_tx) tx - время накопленное сек
#define idinternal1_m193_tx	 1295	//(internal1_m193_tx) tx - время накопленное сек
#define internal1_m193_y0	 BUFFER[4171]	//(internal1_m193_y0) y0
#define idinternal1_m193_y0	 1296	//(internal1_m193_y0) y0
#define internal1_m192_tx	 BUFFER[4172]	//(internal1_m192_tx) tx - время накопленное сек
#define idinternal1_m192_tx	 1297	//(internal1_m192_tx) tx - время накопленное сек
#define internal1_m192_y0	 BUFFER[4177]	//(internal1_m192_y0) y0
#define idinternal1_m192_y0	 1298	//(internal1_m192_y0) y0
#define internal1_m214_tx	 BUFFER[4178]	//(internal1_m214_tx) tx - время накопленное сек
#define idinternal1_m214_tx	 1299	//(internal1_m214_tx) tx - время накопленное сек
#define internal1_m214_y0	 BUFFER[4183]	//(internal1_m214_y0) y0
#define idinternal1_m214_y0	 1300	//(internal1_m214_y0) y0
#define internal1_m583_tx	 BUFFER[4184]	//(internal1_m583_tx) tx - время накопленное сек
#define idinternal1_m583_tx	 1301	//(internal1_m583_tx) tx - время накопленное сек
#define internal1_m583_y0	 BUFFER[4189]	//(internal1_m583_y0) y0
#define idinternal1_m583_y0	 1302	//(internal1_m583_y0) y0
#define internal1_m2285_tx	 BUFFER[4190]	//(internal1_m2285_tx) tx - внутренний параметр
#define idinternal1_m2285_tx	 1303	//(internal1_m2285_tx) tx - внутренний параметр
#define internal1_m1314_tx	 BUFFER[4195]	//(internal1_m1314_tx) tx - внутренний параметр
#define idinternal1_m1314_tx	 1304	//(internal1_m1314_tx) tx - внутренний параметр
#define internal1_m1801_tx	 BUFFER[4200]	//(internal1_m1801_tx) tx - время накопленное сек
#define idinternal1_m1801_tx	 1305	//(internal1_m1801_tx) tx - время накопленное сек
#define internal1_m1801_y0	 BUFFER[4205]	//(internal1_m1801_y0) y0
#define idinternal1_m1801_y0	 1306	//(internal1_m1801_y0) y0
#define internal1_m1278_tx	 BUFFER[4206]	//(internal1_m1278_tx) tx - время накопленное сек
#define idinternal1_m1278_tx	 1307	//(internal1_m1278_tx) tx - время накопленное сек
#define internal1_m1278_y0	 BUFFER[4211]	//(internal1_m1278_y0) y0
#define idinternal1_m1278_y0	 1308	//(internal1_m1278_y0) y0
#define internal1_m1498_tx	 BUFFER[4212]	//(internal1_m1498_tx) tx - время накопленное сек
#define idinternal1_m1498_tx	 1309	//(internal1_m1498_tx) tx - время накопленное сек
#define internal1_m1498_y0	 BUFFER[4217]	//(internal1_m1498_y0) y0
#define idinternal1_m1498_y0	 1310	//(internal1_m1498_y0) y0
#define internal1_m1047_tx	 BUFFER[4218]	//(internal1_m1047_tx) tx - время накопленное сек
#define idinternal1_m1047_tx	 1311	//(internal1_m1047_tx) tx - время накопленное сек
#define internal1_m1047_y0	 BUFFER[4223]	//(internal1_m1047_y0) y0
#define idinternal1_m1047_y0	 1312	//(internal1_m1047_y0) y0
#define internal1_m1388_tx	 BUFFER[4224]	//(internal1_m1388_tx) tx - время накопленное сек
#define idinternal1_m1388_tx	 1313	//(internal1_m1388_tx) tx - время накопленное сек
#define internal1_m1388_y0	 BUFFER[4229]	//(internal1_m1388_y0) y0
#define idinternal1_m1388_y0	 1314	//(internal1_m1388_y0) y0
#define internal1_m1204_q0	 BUFFER[4230]	//(internal1_m1204_q0) q0 - внутренний параметр
#define idinternal1_m1204_q0	 1315	//(internal1_m1204_q0) q0 - внутренний параметр
#define internal1_m1202_q0	 BUFFER[4232]	//(internal1_m1202_q0) q0 - внутренний параметр
#define idinternal1_m1202_q0	 1316	//(internal1_m1202_q0) q0 - внутренний параметр
#define internal1_m1201_q0	 BUFFER[4234]	//(internal1_m1201_q0) q0 - внутренний параметр
#define idinternal1_m1201_q0	 1317	//(internal1_m1201_q0) q0 - внутренний параметр
#define internal1_m1199_q0	 BUFFER[4236]	//(internal1_m1199_q0) q0 - внутренний параметр
#define idinternal1_m1199_q0	 1318	//(internal1_m1199_q0) q0 - внутренний параметр
#define internal1_m1198_q0	 BUFFER[4238]	//(internal1_m1198_q0) q0 - внутренний параметр
#define idinternal1_m1198_q0	 1319	//(internal1_m1198_q0) q0 - внутренний параметр
#define internal1_m1196_q0	 BUFFER[4240]	//(internal1_m1196_q0) q0 - внутренний параметр
#define idinternal1_m1196_q0	 1320	//(internal1_m1196_q0) q0 - внутренний параметр
#define internal1_m1195_q0	 BUFFER[4242]	//(internal1_m1195_q0) q0 - внутренний параметр
#define idinternal1_m1195_q0	 1321	//(internal1_m1195_q0) q0 - внутренний параметр
#define internal1_m1193_q0	 BUFFER[4244]	//(internal1_m1193_q0) q0 - внутренний параметр
#define idinternal1_m1193_q0	 1322	//(internal1_m1193_q0) q0 - внутренний параметр
#define internal1_m1192_q0	 BUFFER[4246]	//(internal1_m1192_q0) q0 - внутренний параметр
#define idinternal1_m1192_q0	 1323	//(internal1_m1192_q0) q0 - внутренний параметр
#define internal1_m52_x0	 BUFFER[4248]	//(internal1_m52_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m52_x0	 1324	//(internal1_m52_x0) - значение входного параметра на предыдущем шаге
#define internal1_m52_LastSwitch	 BUFFER[4250]	//(internal1_m52_LastSwitch) - значение флага отключения сети
#define idinternal1_m52_LastSwitch	 1325	//(internal1_m52_LastSwitch) - значение флага отключения сети
#define internal1_m1111_q0	 BUFFER[4252]	//(internal1_m1111_q0) q0 - внутренний параметр
#define idinternal1_m1111_q0	 1326	//(internal1_m1111_q0) q0 - внутренний параметр
#define internal1_m1609_x0	 BUFFER[4254]	//(internal1_m1609_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m1609_x0	 1327	//(internal1_m1609_x0) - значение входного параметра на предыдущем шаге
#define internal1_m1609_LastSwitch	 BUFFER[4256]	//(internal1_m1609_LastSwitch) - значение флага отключения сети
#define idinternal1_m1609_LastSwitch	 1328	//(internal1_m1609_LastSwitch) - значение флага отключения сети
#define internal1_m1653_x0	 BUFFER[4258]	//(internal1_m1653_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m1653_x0	 1329	//(internal1_m1653_x0) - значение входного параметра на предыдущем шаге
#define internal1_m1653_LastSwitch	 BUFFER[4260]	//(internal1_m1653_LastSwitch) - значение флага отключения сети
#define idinternal1_m1653_LastSwitch	 1330	//(internal1_m1653_LastSwitch) - значение флага отключения сети
#define internal1_m1649_x0	 BUFFER[4262]	//(internal1_m1649_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m1649_x0	 1331	//(internal1_m1649_x0) - значение входного параметра на предыдущем шаге
#define internal1_m1649_LastSwitch	 BUFFER[4264]	//(internal1_m1649_LastSwitch) - значение флага отключения сети
#define idinternal1_m1649_LastSwitch	 1332	//(internal1_m1649_LastSwitch) - значение флага отключения сети
#define internal1_m2067_x0	 BUFFER[4266]	//(internal1_m2067_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m2067_x0	 1333	//(internal1_m2067_x0) - значение входного параметра на предыдущем шаге
#define internal1_m2067_LastSwitch	 BUFFER[4268]	//(internal1_m2067_LastSwitch) - значение флага отключения сети
#define idinternal1_m2067_LastSwitch	 1334	//(internal1_m2067_LastSwitch) - значение флага отключения сети
#define internal1_m2041_x0	 BUFFER[4270]	//(internal1_m2041_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m2041_x0	 1335	//(internal1_m2041_x0) - значение входного параметра на предыдущем шаге
#define internal1_m2041_LastSwitch	 BUFFER[4272]	//(internal1_m2041_LastSwitch) - значение флага отключения сети
#define idinternal1_m2041_LastSwitch	 1336	//(internal1_m2041_LastSwitch) - значение флага отключения сети
#define internal1_m1151_q0	 BUFFER[4274]	//(internal1_m1151_q0) q0 - внутренний параметр
#define idinternal1_m1151_q0	 1337	//(internal1_m1151_q0) q0 - внутренний параметр
#define internal1_m1163_q0	 BUFFER[4276]	//(internal1_m1163_q0) q0 - внутренний параметр
#define idinternal1_m1163_q0	 1338	//(internal1_m1163_q0) q0 - внутренний параметр
#define internal1_m1175_q0	 BUFFER[4278]	//(internal1_m1175_q0) q0 - внутренний параметр
#define idinternal1_m1175_q0	 1339	//(internal1_m1175_q0) q0 - внутренний параметр
#define internal1_m1184_q0	 BUFFER[4280]	//(internal1_m1184_q0) q0 - внутренний параметр
#define idinternal1_m1184_q0	 1340	//(internal1_m1184_q0) q0 - внутренний параметр
#define internal1_m1162_q0	 BUFFER[4282]	//(internal1_m1162_q0) q0 - внутренний параметр
#define idinternal1_m1162_q0	 1341	//(internal1_m1162_q0) q0 - внутренний параметр
#define internal1_m1177_q0	 BUFFER[4284]	//(internal1_m1177_q0) q0 - внутренний параметр
#define idinternal1_m1177_q0	 1342	//(internal1_m1177_q0) q0 - внутренний параметр
#define internal1_m2125_q0	 BUFFER[4286]	//(internal1_m2125_q0) q0 - внутренний параметр
#define idinternal1_m2125_q0	 1343	//(internal1_m2125_q0) q0 - внутренний параметр
#define internal1_m2124_q0	 BUFFER[4288]	//(internal1_m2124_q0) q0 - внутренний параметр
#define idinternal1_m2124_q0	 1344	//(internal1_m2124_q0) q0 - внутренний параметр
#define internal1_m351_Step	 BUFFER[4290]	//(internal1_m351_Step)  - текущий шаг программы
#define idinternal1_m351_Step	 1345	//(internal1_m351_Step)  - текущий шаг программы
#define internal1_m351_rz	 BUFFER[4293]	//(internal1_m351_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m351_rz	 1346	//(internal1_m351_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m351_TimS	 BUFFER[4303]	//(internal1_m351_TimS) Время от старта программы
#define idinternal1_m351_TimS	 1347	//(internal1_m351_TimS) Время от старта программы
#define internal1_m351_FinPr0	 BUFFER[4308]	//(internal1_m351_FinPr0) FinPr - конец программы
#define idinternal1_m351_FinPr0	 1348	//(internal1_m351_FinPr0) FinPr - конец программы
#define internal1_m351_ErrPr0	 BUFFER[4310]	//(internal1_m351_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m351_ErrPr0	 1349	//(internal1_m351_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m351_sbINI0	 BUFFER[4312]	//(internal1_m351_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m351_sbINI0	 1350	//(internal1_m351_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m351_sbVuIS0	 BUFFER[4314]	//(internal1_m351_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m351_sbVuIS0	 1351	//(internal1_m351_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m351_sb2UR0	 BUFFER[4316]	//(internal1_m351_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m351_sb2UR0	 1352	//(internal1_m351_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m351_sbNupIS0	 BUFFER[4318]	//(internal1_m351_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m351_sbNupIS0	 1353	//(internal1_m351_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m351_sbVuRB0	 BUFFER[4320]	//(internal1_m351_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m351_sbVuRB0	 1354	//(internal1_m351_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m351_MyFirstEnterFlag	 BUFFER[4322]	//(internal1_m351_MyFirstEnterFlag)  
#define idinternal1_m351_MyFirstEnterFlag	 1355	//(internal1_m351_MyFirstEnterFlag)  
#define internal1_m359_x0	 BUFFER[4324]	//(internal1_m359_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m359_x0	 1356	//(internal1_m359_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m316_TimS	 BUFFER[4329]	//(internal1_m316_TimS) Время старта
#define idinternal1_m316_TimS	 1357	//(internal1_m316_TimS) Время старта
#define internal1_m293_Step	 BUFFER[4334]	//(internal1_m293_Step)  - текущий шаг программы
#define idinternal1_m293_Step	 1358	//(internal1_m293_Step)  - текущий шаг программы
#define internal1_m293_rz	 BUFFER[4337]	//(internal1_m293_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m293_rz	 1359	//(internal1_m293_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m293_TimS	 BUFFER[4347]	//(internal1_m293_TimS) Время от старта программы
#define idinternal1_m293_TimS	 1360	//(internal1_m293_TimS) Время от старта программы
#define internal1_m293_FinPr0	 BUFFER[4352]	//(internal1_m293_FinPr0) FinPr - конец программы
#define idinternal1_m293_FinPr0	 1361	//(internal1_m293_FinPr0) FinPr - конец программы
#define internal1_m293_ErrPr0	 BUFFER[4354]	//(internal1_m293_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m293_ErrPr0	 1362	//(internal1_m293_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m293_sbINI0	 BUFFER[4356]	//(internal1_m293_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m293_sbINI0	 1363	//(internal1_m293_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m293_sbVuIS0	 BUFFER[4358]	//(internal1_m293_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m293_sbVuIS0	 1364	//(internal1_m293_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m293_sb2UR0	 BUFFER[4360]	//(internal1_m293_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m293_sb2UR0	 1365	//(internal1_m293_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m293_sbNupIS0	 BUFFER[4362]	//(internal1_m293_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m293_sbNupIS0	 1366	//(internal1_m293_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m293_sbVuRB0	 BUFFER[4364]	//(internal1_m293_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m293_sbVuRB0	 1367	//(internal1_m293_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m293_MyFirstEnterFlag	 BUFFER[4366]	//(internal1_m293_MyFirstEnterFlag)  
#define idinternal1_m293_MyFirstEnterFlag	 1368	//(internal1_m293_MyFirstEnterFlag)  
#define internal1_m1572_q0	 BUFFER[4368]	//(internal1_m1572_q0) q0 - внутренний параметр
#define idinternal1_m1572_q0	 1369	//(internal1_m1572_q0) q0 - внутренний параметр
#define internal1_m1573_Step	 BUFFER[4370]	//(internal1_m1573_Step)  - текущий шаг программы
#define idinternal1_m1573_Step	 1370	//(internal1_m1573_Step)  - текущий шаг программы
#define internal1_m1573_rz	 BUFFER[4373]	//(internal1_m1573_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m1573_rz	 1371	//(internal1_m1573_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m1573_TimS	 BUFFER[4379]	//(internal1_m1573_TimS) Время от старта программы
#define idinternal1_m1573_TimS	 1372	//(internal1_m1573_TimS) Время от старта программы
#define internal1_m1573_FinPr0	 BUFFER[4384]	//(internal1_m1573_FinPr0) FinPr - конец программы
#define idinternal1_m1573_FinPr0	 1373	//(internal1_m1573_FinPr0) FinPr - конец программы
#define internal1_m1573_ErrPr0	 BUFFER[4386]	//(internal1_m1573_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m1573_ErrPr0	 1374	//(internal1_m1573_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m1573_sbINI0	 BUFFER[4388]	//(internal1_m1573_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m1573_sbINI0	 1375	//(internal1_m1573_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m1573_sbVuIS0	 BUFFER[4390]	//(internal1_m1573_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m1573_sbVuIS0	 1376	//(internal1_m1573_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m1573_sb2UR0	 BUFFER[4392]	//(internal1_m1573_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m1573_sb2UR0	 1377	//(internal1_m1573_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m1573_sbNupIS0	 BUFFER[4394]	//(internal1_m1573_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m1573_sbNupIS0	 1378	//(internal1_m1573_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m1573_sbVuRB0	 BUFFER[4396]	//(internal1_m1573_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m1573_sbVuRB0	 1379	//(internal1_m1573_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m1573_MyFirstEnterFlag	 BUFFER[4398]	//(internal1_m1573_MyFirstEnterFlag)  
#define idinternal1_m1573_MyFirstEnterFlag	 1380	//(internal1_m1573_MyFirstEnterFlag)  
#define internal1_m1148_q0	 BUFFER[4400]	//(internal1_m1148_q0) q0 - внутренний параметр
#define idinternal1_m1148_q0	 1381	//(internal1_m1148_q0) q0 - внутренний параметр
#define internal1_m1145_q0	 BUFFER[4402]	//(internal1_m1145_q0) q0 - внутренний параметр
#define idinternal1_m1145_q0	 1382	//(internal1_m1145_q0) q0 - внутренний параметр
#define internal1_m1147_q0	 BUFFER[4404]	//(internal1_m1147_q0) q0 - внутренний параметр
#define idinternal1_m1147_q0	 1383	//(internal1_m1147_q0) q0 - внутренний параметр
#define internal1_m1140_q0	 BUFFER[4406]	//(internal1_m1140_q0) q0 - внутренний параметр
#define idinternal1_m1140_q0	 1384	//(internal1_m1140_q0) q0 - внутренний параметр
#define internal1_m831_q0	 BUFFER[4408]	//(internal1_m831_q0) q0 - внутренний параметр
#define idinternal1_m831_q0	 1385	//(internal1_m831_q0) q0 - внутренний параметр
#define internal1_m361_q0	 BUFFER[4410]	//(internal1_m361_q0) q0 - внутренний параметр
#define idinternal1_m361_q0	 1386	//(internal1_m361_q0) q0 - внутренний параметр
#define internal1_m357_q0	 BUFFER[4412]	//(internal1_m357_q0) q0 - внутренний параметр
#define idinternal1_m357_q0	 1387	//(internal1_m357_q0) q0 - внутренний параметр
#define internal1_m313_q0	 BUFFER[4414]	//(internal1_m313_q0) q0 - внутренний параметр
#define idinternal1_m313_q0	 1388	//(internal1_m313_q0) q0 - внутренний параметр
#define internal1_m312_x0	 BUFFER[4416]	//(internal1_m312_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m312_x0	 1389	//(internal1_m312_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m2055_q0	 BUFFER[4421]	//(internal1_m2055_q0) q0 - внутренний параметр
#define idinternal1_m2055_q0	 1390	//(internal1_m2055_q0) q0 - внутренний параметр
#define internal1_m2048_q0	 BUFFER[4423]	//(internal1_m2048_q0) q0 - внутренний параметр
#define idinternal1_m2048_q0	 1391	//(internal1_m2048_q0) q0 - внутренний параметр
#define internal1_m2042_q0	 BUFFER[4425]	//(internal1_m2042_q0) q0 - внутренний параметр
#define idinternal1_m2042_q0	 1392	//(internal1_m2042_q0) q0 - внутренний параметр
#define internal1_m2108_q0	 BUFFER[4427]	//(internal1_m2108_q0) q0 - внутренний параметр
#define idinternal1_m2108_q0	 1393	//(internal1_m2108_q0) q0 - внутренний параметр
#define internal1_m2079_q0	 BUFFER[4429]	//(internal1_m2079_q0) q0 - внутренний параметр
#define idinternal1_m2079_q0	 1394	//(internal1_m2079_q0) q0 - внутренний параметр
#define internal1_m2068_q0	 BUFFER[4431]	//(internal1_m2068_q0) q0 - внутренний параметр
#define idinternal1_m2068_q0	 1395	//(internal1_m2068_q0) q0 - внутренний параметр
#define internal1_m1636_q0	 BUFFER[4433]	//(internal1_m1636_q0) q0 - внутренний параметр
#define idinternal1_m1636_q0	 1396	//(internal1_m1636_q0) q0 - внутренний параметр
#define internal1_m1623_x0	 BUFFER[4435]	//(internal1_m1623_x0) был приход сигнала x1
#define idinternal1_m1623_x0	 1397	//(internal1_m1623_x0) был приход сигнала x1
#define internal1_m1623_y0	 BUFFER[4437]	//(internal1_m1623_y0) интервал между сигналами х1 и х2
#define idinternal1_m1623_y0	 1398	//(internal1_m1623_y0) интервал между сигналами х1 и х2
#define internal1_m1619_q0	 BUFFER[4442]	//(internal1_m1619_q0) q0 - внутренний параметр
#define idinternal1_m1619_q0	 1399	//(internal1_m1619_q0) q0 - внутренний параметр
#define internal1_m1610_q0	 BUFFER[4444]	//(internal1_m1610_q0) q0 - внутренний параметр
#define idinternal1_m1610_q0	 1400	//(internal1_m1610_q0) q0 - внутренний параметр
#define internal1_m1669_q0	 BUFFER[4446]	//(internal1_m1669_q0) q0 - внутренний параметр
#define idinternal1_m1669_q0	 1401	//(internal1_m1669_q0) q0 - внутренний параметр
#define internal1_m1689_q0	 BUFFER[4448]	//(internal1_m1689_q0) q0 - внутренний параметр
#define idinternal1_m1689_q0	 1402	//(internal1_m1689_q0) q0 - внутренний параметр
#define internal1_m1654_q0	 BUFFER[4450]	//(internal1_m1654_q0) q0 - внутренний параметр
#define idinternal1_m1654_q0	 1403	//(internal1_m1654_q0) q0 - внутренний параметр
#define internal1_m1670_x0	 BUFFER[4452]	//(internal1_m1670_x0) был приход сигнала x1
#define idinternal1_m1670_x0	 1404	//(internal1_m1670_x0) был приход сигнала x1
#define internal1_m1670_y0	 BUFFER[4454]	//(internal1_m1670_y0) интервал между сигналами х1 и х2
#define idinternal1_m1670_y0	 1405	//(internal1_m1670_y0) интервал между сигналами х1 и х2
#define internal1_m1590_x0	 BUFFER[4459]	//(internal1_m1590_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1590_x0	 1406	//(internal1_m1590_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1675_q0	 BUFFER[4464]	//(internal1_m1675_q0) q0 - внутренний параметр
#define idinternal1_m1675_q0	 1407	//(internal1_m1675_q0) q0 - внутренний параметр
#define internal1_m26_q0	 BUFFER[4466]	//(internal1_m26_q0) q0 - внутренний параметр
#define idinternal1_m26_q0	 1408	//(internal1_m26_q0) q0 - внутренний параметр
#define internal1_m1690_q0	 BUFFER[4468]	//(internal1_m1690_q0) q0 - внутренний параметр
#define idinternal1_m1690_q0	 1409	//(internal1_m1690_q0) q0 - внутренний параметр
#define internal1_m706_q0	 BUFFER[4470]	//(internal1_m706_q0) q0 - внутренний параметр
#define idinternal1_m706_q0	 1410	//(internal1_m706_q0) q0 - внутренний параметр
#define internal1_m691_q0	 BUFFER[4472]	//(internal1_m691_q0) q0 - внутренний параметр
#define idinternal1_m691_q0	 1411	//(internal1_m691_q0) q0 - внутренний параметр
#define internal1_m719_q0	 BUFFER[4474]	//(internal1_m719_q0) q0 - внутренний параметр
#define idinternal1_m719_q0	 1412	//(internal1_m719_q0) q0 - внутренний параметр
#define internal1_m702_q0	 BUFFER[4476]	//(internal1_m702_q0) q0 - внутренний параметр
#define idinternal1_m702_q0	 1413	//(internal1_m702_q0) q0 - внутренний параметр
#define internal1_m686_q0	 BUFFER[4478]	//(internal1_m686_q0) q0 - внутренний параметр
#define idinternal1_m686_q0	 1414	//(internal1_m686_q0) q0 - внутренний параметр
#define internal1_m684_q0	 BUFFER[4480]	//(internal1_m684_q0) q0 - внутренний параметр
#define idinternal1_m684_q0	 1415	//(internal1_m684_q0) q0 - внутренний параметр
#define internal1_m672_q0	 BUFFER[4482]	//(internal1_m672_q0) q0 - внутренний параметр
#define idinternal1_m672_q0	 1416	//(internal1_m672_q0) q0 - внутренний параметр
#define internal1_m1575_q0	 BUFFER[4484]	//(internal1_m1575_q0) q0 - внутренний параметр
#define idinternal1_m1575_q0	 1417	//(internal1_m1575_q0) q0 - внутренний параметр
#define internal1_m682_q0	 BUFFER[4489]	//(internal1_m682_q0) q0 - внутренний параметр
#define idinternal1_m682_q0	 1418	//(internal1_m682_q0) q0 - внутренний параметр
#define internal1_m116_q0	 BUFFER[4491]	//(internal1_m116_q0) q0 - внутренний параметр
#define idinternal1_m116_q0	 1419	//(internal1_m116_q0) q0 - внутренний параметр
#define internal1_m1836_q0	 BUFFER[4493]	//(internal1_m1836_q0) q0 - внутренний параметр
#define idinternal1_m1836_q0	 1420	//(internal1_m1836_q0) q0 - внутренний параметр
#define internal1_m1835_q0	 BUFFER[4495]	//(internal1_m1835_q0) q0 - внутренний параметр
#define idinternal1_m1835_q0	 1421	//(internal1_m1835_q0) q0 - внутренний параметр
#define internal1_m1834_q0	 BUFFER[4497]	//(internal1_m1834_q0) q0 - внутренний параметр
#define idinternal1_m1834_q0	 1422	//(internal1_m1834_q0) q0 - внутренний параметр
#define internal1_m1833_q0	 BUFFER[4499]	//(internal1_m1833_q0) q0 - внутренний параметр
#define idinternal1_m1833_q0	 1423	//(internal1_m1833_q0) q0 - внутренний параметр
#define internal1_m1869_q0	 BUFFER[4501]	//(internal1_m1869_q0) q0 - внутренний параметр
#define idinternal1_m1869_q0	 1424	//(internal1_m1869_q0) q0 - внутренний параметр
#define internal1_m1868_q0	 BUFFER[4503]	//(internal1_m1868_q0) q0 - внутренний параметр
#define idinternal1_m1868_q0	 1425	//(internal1_m1868_q0) q0 - внутренний параметр
#define internal1_m1867_q0	 BUFFER[4505]	//(internal1_m1867_q0) q0 - внутренний параметр
#define idinternal1_m1867_q0	 1426	//(internal1_m1867_q0) q0 - внутренний параметр
#define internal1_m2139_q0	 BUFFER[4507]	//(internal1_m2139_q0) q0 - внутренний параметр
#define idinternal1_m2139_q0	 1427	//(internal1_m2139_q0) q0 - внутренний параметр
#define internal1_m1929_q0	 BUFFER[4509]	//(internal1_m1929_q0) q0 - внутренний параметр
#define idinternal1_m1929_q0	 1428	//(internal1_m1929_q0) q0 - внутренний параметр
#define internal1_m1918_q0	 BUFFER[4511]	//(internal1_m1918_q0) q0 - внутренний параметр
#define idinternal1_m1918_q0	 1429	//(internal1_m1918_q0) q0 - внутренний параметр
#define internal1_m1926_q0	 BUFFER[4513]	//(internal1_m1926_q0) q0 - внутренний параметр
#define idinternal1_m1926_q0	 1430	//(internal1_m1926_q0) q0 - внутренний параметр
#define internal1_m1915_q0	 BUFFER[4515]	//(internal1_m1915_q0) q0 - внутренний параметр
#define idinternal1_m1915_q0	 1431	//(internal1_m1915_q0) q0 - внутренний параметр
#define internal1_m1923_q0	 BUFFER[4517]	//(internal1_m1923_q0) q0 - внутренний параметр
#define idinternal1_m1923_q0	 1432	//(internal1_m1923_q0) q0 - внутренний параметр
#define internal1_m2353_q0	 BUFFER[4519]	//(internal1_m2353_q0) q0 - внутренний параметр
#define idinternal1_m2353_q0	 1433	//(internal1_m2353_q0) q0 - внутренний параметр
#define internal1_m2349_q0	 BUFFER[4521]	//(internal1_m2349_q0) q0 - внутренний параметр
#define idinternal1_m2349_q0	 1434	//(internal1_m2349_q0) q0 - внутренний параметр
#define internal1_m1894_q0	 BUFFER[4523]	//(internal1_m1894_q0) q0 - внутренний параметр
#define idinternal1_m1894_q0	 1435	//(internal1_m1894_q0) q0 - внутренний параметр
#define internal1_m1886_q0	 BUFFER[4525]	//(internal1_m1886_q0) q0 - внутренний параметр
#define idinternal1_m1886_q0	 1436	//(internal1_m1886_q0) q0 - внутренний параметр
#define internal1_m1884_q0	 BUFFER[4527]	//(internal1_m1884_q0) q0 - внутренний параметр
#define idinternal1_m1884_q0	 1437	//(internal1_m1884_q0) q0 - внутренний параметр
#define internal1_m1880_q0	 BUFFER[4529]	//(internal1_m1880_q0) q0 - внутренний параметр
#define idinternal1_m1880_q0	 1438	//(internal1_m1880_q0) q0 - внутренний параметр
#define internal1_m1876_q0	 BUFFER[4531]	//(internal1_m1876_q0) q0 - внутренний параметр
#define idinternal1_m1876_q0	 1439	//(internal1_m1876_q0) q0 - внутренний параметр
#define internal1_m1878_q0	 BUFFER[4533]	//(internal1_m1878_q0) q0 - внутренний параметр
#define idinternal1_m1878_q0	 1440	//(internal1_m1878_q0) q0 - внутренний параметр
#define internal1_m19_q0	 BUFFER[4535]	//(internal1_m19_q0) q0 - внутренний параметр
#define idinternal1_m19_q0	 1441	//(internal1_m19_q0) q0 - внутренний параметр
#define internal1_m1859_q0	 BUFFER[4537]	//(internal1_m1859_q0) q0 - внутренний параметр
#define idinternal1_m1859_q0	 1442	//(internal1_m1859_q0) q0 - внутренний параметр
#define internal1_m1857_q0	 BUFFER[4539]	//(internal1_m1857_q0) q0 - внутренний параметр
#define idinternal1_m1857_q0	 1443	//(internal1_m1857_q0) q0 - внутренний параметр
#define internal1_m1853_q0	 BUFFER[4541]	//(internal1_m1853_q0) q0 - внутренний параметр
#define idinternal1_m1853_q0	 1444	//(internal1_m1853_q0) q0 - внутренний параметр
#define internal1_m1855_q0	 BUFFER[4543]	//(internal1_m1855_q0) q0 - внутренний параметр
#define idinternal1_m1855_q0	 1445	//(internal1_m1855_q0) q0 - внутренний параметр
#define internal1_m1851_q0	 BUFFER[4545]	//(internal1_m1851_q0) q0 - внутренний параметр
#define idinternal1_m1851_q0	 1446	//(internal1_m1851_q0) q0 - внутренний параметр
#define internal1_m1849_q0	 BUFFER[4547]	//(internal1_m1849_q0) q0 - внутренний параметр
#define idinternal1_m1849_q0	 1447	//(internal1_m1849_q0) q0 - внутренний параметр
#define internal1_m2264_q0	 BUFFER[4549]	//(internal1_m2264_q0) q0 - внутренний параметр
#define idinternal1_m2264_q0	 1448	//(internal1_m2264_q0) q0 - внутренний параметр
#define internal1_m2259_q0	 BUFFER[4551]	//(internal1_m2259_q0) q0 - внутренний параметр
#define idinternal1_m2259_q0	 1449	//(internal1_m2259_q0) q0 - внутренний параметр
#define internal1_m2236_q0	 BUFFER[4553]	//(internal1_m2236_q0) q0 - внутренний параметр
#define idinternal1_m2236_q0	 1450	//(internal1_m2236_q0) q0 - внутренний параметр
#define internal1_m2220_q0	 BUFFER[4555]	//(internal1_m2220_q0) q0 - внутренний параметр
#define idinternal1_m2220_q0	 1451	//(internal1_m2220_q0) q0 - внутренний параметр
#define internal1_m2151_q0	 BUFFER[4557]	//(internal1_m2151_q0) q0 - внутренний параметр
#define idinternal1_m2151_q0	 1452	//(internal1_m2151_q0) q0 - внутренний параметр
#define internal1_m1845_q0	 BUFFER[4559]	//(internal1_m1845_q0) q0 - внутренний параметр
#define idinternal1_m1845_q0	 1453	//(internal1_m1845_q0) q0 - внутренний параметр
#define internal1_m1847_q0	 BUFFER[4561]	//(internal1_m1847_q0) q0 - внутренний параметр
#define idinternal1_m1847_q0	 1454	//(internal1_m1847_q0) q0 - внутренний параметр
#define internal1_m1831_q0	 BUFFER[4563]	//(internal1_m1831_q0) q0 - внутренний параметр
#define idinternal1_m1831_q0	 1455	//(internal1_m1831_q0) q0 - внутренний параметр
#define internal1_m1829_q0	 BUFFER[4565]	//(internal1_m1829_q0) q0 - внутренний параметр
#define idinternal1_m1829_q0	 1456	//(internal1_m1829_q0) q0 - внутренний параметр
#define internal1_m1827_q0	 BUFFER[4567]	//(internal1_m1827_q0) q0 - внутренний параметр
#define idinternal1_m1827_q0	 1457	//(internal1_m1827_q0) q0 - внутренний параметр
#define internal1_m1825_q0	 BUFFER[4569]	//(internal1_m1825_q0) q0 - внутренний параметр
#define idinternal1_m1825_q0	 1458	//(internal1_m1825_q0) q0 - внутренний параметр
#define internal1_m1824_q0	 BUFFER[4571]	//(internal1_m1824_q0) q0 - внутренний параметр
#define idinternal1_m1824_q0	 1459	//(internal1_m1824_q0) q0 - внутренний параметр
#define internal1_m1822_q0	 BUFFER[4573]	//(internal1_m1822_q0) q0 - внутренний параметр
#define idinternal1_m1822_q0	 1460	//(internal1_m1822_q0) q0 - внутренний параметр
#define internal1_m1821_q0	 BUFFER[4575]	//(internal1_m1821_q0) q0 - внутренний параметр
#define idinternal1_m1821_q0	 1461	//(internal1_m1821_q0) q0 - внутренний параметр
#define internal1_m1819_q0	 BUFFER[4577]	//(internal1_m1819_q0) q0 - внутренний параметр
#define idinternal1_m1819_q0	 1462	//(internal1_m1819_q0) q0 - внутренний параметр
#define internal1_m2290_DvUp0	 BUFFER[4579]	//(internal1_m2290_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2290_DvUp0	 1463	//(internal1_m2290_DvUp0) - есть команда на движение вперёд
#define internal1_m2290_DvDw0	 BUFFER[4580]	//(internal1_m2290_DvDw0) - есть команда на движение назад
#define idinternal1_m2290_DvDw0	 1464	//(internal1_m2290_DvDw0) - есть команда на движение назад
#define internal1_m2290_FDvUp0	 BUFFER[4581]	//(internal1_m2290_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2290_FDvUp0	 1465	//(internal1_m2290_FDvUp0) - есть команда на движение вперёд
#define internal1_m2290_FDvDw0	 BUFFER[4582]	//(internal1_m2290_FDvDw0) - есть команда на движение назад
#define idinternal1_m2290_FDvDw0	 1466	//(internal1_m2290_FDvDw0) - есть команда на движение назад
#define internal1_m2290_BlDv0	 BUFFER[4583]	//(internal1_m2290_BlDv0) - была блокировка
#define idinternal1_m2290_BlDv0	 1467	//(internal1_m2290_BlDv0) - была блокировка
#define internal1_m2290_Pkv0	 BUFFER[4584]	//(internal1_m2290_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2290_Pkv0	 1468	//(internal1_m2290_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2290_Pkav0	 BUFFER[4585]	//(internal1_m2290_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2290_Pkav0	 1469	//(internal1_m2290_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2290_Zkv0	 BUFFER[4586]	//(internal1_m2290_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2290_Zkv0	 1470	//(internal1_m2290_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2290_Zkav0	 BUFFER[4587]	//(internal1_m2290_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2290_Zkav0	 1471	//(internal1_m2290_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2290_txNm	 BUFFER[4588]	//(internal1_m2290_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2290_txNm	 1472	//(internal1_m2290_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2290_txSm	 BUFFER[4593]	//(internal1_m2290_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2290_txSm	 1473	//(internal1_m2290_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2290_txHr	 BUFFER[4598]	//(internal1_m2290_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2290_txHr	 1474	//(internal1_m2290_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2290_txLd	 BUFFER[4603]	//(internal1_m2290_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2290_txLd	 1475	//(internal1_m2290_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2290_fef	 BUFFER[4608]	//(internal1_m2290_fef) fef
#define idinternal1_m2290_fef	 1476	//(internal1_m2290_fef) fef
#define internal1_m2284_DvUp0	 BUFFER[4609]	//(internal1_m2284_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2284_DvUp0	 1477	//(internal1_m2284_DvUp0) - есть команда на движение вперёд
#define internal1_m2284_DvDw0	 BUFFER[4610]	//(internal1_m2284_DvDw0) - есть команда на движение назад
#define idinternal1_m2284_DvDw0	 1478	//(internal1_m2284_DvDw0) - есть команда на движение назад
#define internal1_m2284_FDvUp0	 BUFFER[4611]	//(internal1_m2284_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2284_FDvUp0	 1479	//(internal1_m2284_FDvUp0) - есть команда на движение вперёд
#define internal1_m2284_FDvDw0	 BUFFER[4612]	//(internal1_m2284_FDvDw0) - есть команда на движение назад
#define idinternal1_m2284_FDvDw0	 1480	//(internal1_m2284_FDvDw0) - есть команда на движение назад
#define internal1_m2284_BlDv0	 BUFFER[4613]	//(internal1_m2284_BlDv0) - была блокировка
#define idinternal1_m2284_BlDv0	 1481	//(internal1_m2284_BlDv0) - была блокировка
#define internal1_m2284_Pkv0	 BUFFER[4614]	//(internal1_m2284_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2284_Pkv0	 1482	//(internal1_m2284_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2284_Pkav0	 BUFFER[4615]	//(internal1_m2284_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2284_Pkav0	 1483	//(internal1_m2284_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2284_Zkv0	 BUFFER[4616]	//(internal1_m2284_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2284_Zkv0	 1484	//(internal1_m2284_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2284_Zkav0	 BUFFER[4617]	//(internal1_m2284_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2284_Zkav0	 1485	//(internal1_m2284_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2284_txNm	 BUFFER[4618]	//(internal1_m2284_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2284_txNm	 1486	//(internal1_m2284_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2284_txSm	 BUFFER[4623]	//(internal1_m2284_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2284_txSm	 1487	//(internal1_m2284_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2284_txHr	 BUFFER[4628]	//(internal1_m2284_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2284_txHr	 1488	//(internal1_m2284_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2284_txLd	 BUFFER[4633]	//(internal1_m2284_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2284_txLd	 1489	//(internal1_m2284_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2284_fef	 BUFFER[4638]	//(internal1_m2284_fef) fef
#define idinternal1_m2284_fef	 1490	//(internal1_m2284_fef) fef
#define internal1_m1661_q0	 BUFFER[4639]	//(internal1_m1661_q0) q0 - внутренний параметр
#define idinternal1_m1661_q0	 1491	//(internal1_m1661_q0) q0 - внутренний параметр
#define internal1_m1664_x0	 BUFFER[4641]	//(internal1_m1664_x0) был приход сигнала x1
#define idinternal1_m1664_x0	 1492	//(internal1_m1664_x0) был приход сигнала x1
#define internal1_m1664_y0	 BUFFER[4643]	//(internal1_m1664_y0) интервал между сигналами х1 и х2
#define idinternal1_m1664_y0	 1493	//(internal1_m1664_y0) интервал между сигналами х1 и х2
#define internal1_m2090_x0	 BUFFER[4648]	//(internal1_m2090_x0) был приход сигнала x1
#define idinternal1_m2090_x0	 1494	//(internal1_m2090_x0) был приход сигнала x1
#define internal1_m2090_y0	 BUFFER[4650]	//(internal1_m2090_y0) интервал между сигналами х1 и х2
#define idinternal1_m2090_y0	 1495	//(internal1_m2090_y0) интервал между сигналами х1 и х2
#define internal1_m2050_x0	 BUFFER[4655]	//(internal1_m2050_x0) был приход сигнала x1
#define idinternal1_m2050_x0	 1496	//(internal1_m2050_x0) был приход сигнала x1
#define internal1_m2050_y0	 BUFFER[4657]	//(internal1_m2050_y0) интервал между сигналами х1 и х2
#define idinternal1_m2050_y0	 1497	//(internal1_m2050_y0) интервал между сигналами х1 и х2
#define internal1_m304_q0	 BUFFER[4662]	//(internal1_m304_q0) q0 - внутренний параметр
#define idinternal1_m304_q0	 1498	//(internal1_m304_q0) q0 - внутренний параметр
#define internal1_m1119_q0	 BUFFER[4664]	//(internal1_m1119_q0) q0 - внутренний параметр
#define idinternal1_m1119_q0	 1499	//(internal1_m1119_q0) q0 - внутренний параметр
#define internal1_m694_q0	 BUFFER[4666]	//(internal1_m694_q0) q0 - внутренний параметр
#define idinternal1_m694_q0	 1500	//(internal1_m694_q0) q0 - внутренний параметр
#define internal1_m1456_X0	 BUFFER[4668]	//(internal1_m1456_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1456_X0	 1501	//(internal1_m1456_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1456_t0	 BUFFER[4673]	//(internal1_m1456_t0) время нахождения в зоне возврата
#define idinternal1_m1456_t0	 1502	//(internal1_m1456_t0) время нахождения в зоне возврата
#define internal1_m1456_BLDv0	 BUFFER[4678]	//(internal1_m1456_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1456_BLDv0	 1503	//(internal1_m1456_BLDv0) BlDv - Блокировка движения
#define internal1_m1473_tx	 BUFFER[4679]	//(internal1_m1473_tx) tx - время накопленное сек
#define idinternal1_m1473_tx	 1504	//(internal1_m1473_tx) tx - время накопленное сек
#define internal1_m1473_y0	 BUFFER[4684]	//(internal1_m1473_y0) y0
#define idinternal1_m1473_y0	 1505	//(internal1_m1473_y0) y0
#define internal1_m1474_tx	 BUFFER[4685]	//(internal1_m1474_tx) tx - время накопленное сек
#define idinternal1_m1474_tx	 1506	//(internal1_m1474_tx) tx - время накопленное сек
#define internal1_m1474_y0	 BUFFER[4690]	//(internal1_m1474_y0) y0
#define idinternal1_m1474_y0	 1507	//(internal1_m1474_y0) y0
#define internal1_m1482_xptr	 BUFFER[4691]	//(internal1_m1482_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1482_xptr	 1508	//(internal1_m1482_xptr) указатель текущей позиции в массиве координат
#define internal1_m1482_x0	 BUFFER[4694]	//(internal1_m1482_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1482_x0	 1509	//(internal1_m1482_x0) x0 - массив мгновенных значений координат
#define internal1_m1482_tim0	 BUFFER[4994]	//(internal1_m1482_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1482_tim0	 1510	//(internal1_m1482_tim0) tim0 - массив значений времени цикла
#define internal1_m1482_sumtim	 BUFFER[5294]	//(internal1_m1482_sumtim) sumtim - время в пути
#define idinternal1_m1482_sumtim	 1511	//(internal1_m1482_sumtim) sumtim - время в пути
#define internal1_m1482_StSpeed	 BUFFER[5299]	//(internal1_m1482_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1482_StSpeed	 1512	//(internal1_m1482_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1482_Vz0	 BUFFER[5304]	//(internal1_m1482_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1482_Vz0	 1513	//(internal1_m1482_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1482_flRazg	 BUFFER[5309]	//(internal1_m1482_flRazg) признак разгона/торможения
#define idinternal1_m1482_flRazg	 1514	//(internal1_m1482_flRazg) признак разгона/торможения
#define internal1_m1482_DelSp	 BUFFER[5312]	//(internal1_m1482_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1482_DelSp	 1515	//(internal1_m1482_DelSp) DelSp - время переключения скоростей
#define internal1_m1482_z0	 BUFFER[5317]	//(internal1_m1482_z0) z0 - точка прекращения движения
#define idinternal1_m1482_z0	 1516	//(internal1_m1482_z0) z0 - точка прекращения движения
#define internal1_m1482_txZS	 BUFFER[5322]	//(internal1_m1482_txZS) txZS
#define idinternal1_m1482_txZS	 1517	//(internal1_m1482_txZS) txZS
#define internal1_m1482_tx	 BUFFER[5327]	//(internal1_m1482_tx) tx
#define idinternal1_m1482_tx	 1518	//(internal1_m1482_tx) tx
#define internal1_m1482_txd	 BUFFER[5332]	//(internal1_m1482_txd) txd
#define idinternal1_m1482_txd	 1519	//(internal1_m1482_txd) txd
#define internal1_m1482_txMBl	 BUFFER[5337]	//(internal1_m1482_txMBl) tx
#define idinternal1_m1482_txMBl	 1520	//(internal1_m1482_txMBl) tx
#define internal1_m1482_txBl	 BUFFER[5342]	//(internal1_m1482_txBl) tx
#define idinternal1_m1482_txBl	 1521	//(internal1_m1482_txBl) tx
#define internal1_m1482_Speed0	 BUFFER[5347]	//(internal1_m1482_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1482_Speed0	 1522	//(internal1_m1482_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1482_xz0	 BUFFER[5352]	//(internal1_m1482_xz0) xz0 - новое задание мм
#define idinternal1_m1482_xz0	 1523	//(internal1_m1482_xz0) xz0 - новое задание мм
#define internal1_m1482_tz0	 BUFFER[5357]	//(internal1_m1482_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1482_tz0	 1524	//(internal1_m1482_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1482_Shift0	 BUFFER[5362]	//(internal1_m1482_Shift0) Shift0 - признак самохода
#define idinternal1_m1482_Shift0	 1525	//(internal1_m1482_Shift0) Shift0 - признак самохода
#define internal1_m1482_ShCntlSp0	 BUFFER[5364]	//(internal1_m1482_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1482_ShCntlSp0	 1526	//(internal1_m1482_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1482_ShiftControl	 BUFFER[5366]	//(internal1_m1482_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1482_ShiftControl	 1527	//(internal1_m1482_ShiftControl) ShiftControl - признак самохода
#define internal1_m692_q0	 BUFFER[5368]	//(internal1_m692_q0) q0 - внутренний параметр
#define idinternal1_m692_q0	 1528	//(internal1_m692_q0) q0 - внутренний параметр
#define internal1_m1000_X0	 BUFFER[5370]	//(internal1_m1000_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1000_X0	 1529	//(internal1_m1000_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1000_t0	 BUFFER[5375]	//(internal1_m1000_t0) время нахождения в зоне возврата
#define idinternal1_m1000_t0	 1530	//(internal1_m1000_t0) время нахождения в зоне возврата
#define internal1_m1000_BLDv0	 BUFFER[5380]	//(internal1_m1000_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1000_BLDv0	 1531	//(internal1_m1000_BLDv0) BlDv - Блокировка движения
#define internal1_m1023_tx	 BUFFER[5381]	//(internal1_m1023_tx) tx - время накопленное сек
#define idinternal1_m1023_tx	 1532	//(internal1_m1023_tx) tx - время накопленное сек
#define internal1_m1023_y0	 BUFFER[5386]	//(internal1_m1023_y0) y0
#define idinternal1_m1023_y0	 1533	//(internal1_m1023_y0) y0
#define internal1_m1022_tx	 BUFFER[5387]	//(internal1_m1022_tx) tx - время накопленное сек
#define idinternal1_m1022_tx	 1534	//(internal1_m1022_tx) tx - время накопленное сек
#define internal1_m1022_y0	 BUFFER[5392]	//(internal1_m1022_y0) y0
#define idinternal1_m1022_y0	 1535	//(internal1_m1022_y0) y0
#define internal1_m1030_xptr	 BUFFER[5393]	//(internal1_m1030_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1030_xptr	 1536	//(internal1_m1030_xptr) указатель текущей позиции в массиве координат
#define internal1_m1030_x0	 BUFFER[5396]	//(internal1_m1030_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1030_x0	 1537	//(internal1_m1030_x0) x0 - массив мгновенных значений координат
#define internal1_m1030_tim0	 BUFFER[5696]	//(internal1_m1030_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1030_tim0	 1538	//(internal1_m1030_tim0) tim0 - массив значений времени цикла
#define internal1_m1030_sumtim	 BUFFER[5996]	//(internal1_m1030_sumtim) sumtim - время в пути
#define idinternal1_m1030_sumtim	 1539	//(internal1_m1030_sumtim) sumtim - время в пути
#define internal1_m1030_StSpeed	 BUFFER[6001]	//(internal1_m1030_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1030_StSpeed	 1540	//(internal1_m1030_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1030_Vz0	 BUFFER[6006]	//(internal1_m1030_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1030_Vz0	 1541	//(internal1_m1030_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1030_flRazg	 BUFFER[6011]	//(internal1_m1030_flRazg) признак разгона/торможения
#define idinternal1_m1030_flRazg	 1542	//(internal1_m1030_flRazg) признак разгона/торможения
#define internal1_m1030_DelSp	 BUFFER[6014]	//(internal1_m1030_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1030_DelSp	 1543	//(internal1_m1030_DelSp) DelSp - время переключения скоростей
#define internal1_m1030_z0	 BUFFER[6019]	//(internal1_m1030_z0) z0 - точка прекращения движения
#define idinternal1_m1030_z0	 1544	//(internal1_m1030_z0) z0 - точка прекращения движения
#define internal1_m1030_txZS	 BUFFER[6024]	//(internal1_m1030_txZS) txZS
#define idinternal1_m1030_txZS	 1545	//(internal1_m1030_txZS) txZS
#define internal1_m1030_tx	 BUFFER[6029]	//(internal1_m1030_tx) tx
#define idinternal1_m1030_tx	 1546	//(internal1_m1030_tx) tx
#define internal1_m1030_txd	 BUFFER[6034]	//(internal1_m1030_txd) txd
#define idinternal1_m1030_txd	 1547	//(internal1_m1030_txd) txd
#define internal1_m1030_txMBl	 BUFFER[6039]	//(internal1_m1030_txMBl) tx
#define idinternal1_m1030_txMBl	 1548	//(internal1_m1030_txMBl) tx
#define internal1_m1030_txBl	 BUFFER[6044]	//(internal1_m1030_txBl) tx
#define idinternal1_m1030_txBl	 1549	//(internal1_m1030_txBl) tx
#define internal1_m1030_Speed0	 BUFFER[6049]	//(internal1_m1030_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1030_Speed0	 1550	//(internal1_m1030_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1030_xz0	 BUFFER[6054]	//(internal1_m1030_xz0) xz0 - новое задание мм
#define idinternal1_m1030_xz0	 1551	//(internal1_m1030_xz0) xz0 - новое задание мм
#define internal1_m1030_tz0	 BUFFER[6059]	//(internal1_m1030_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1030_tz0	 1552	//(internal1_m1030_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1030_Shift0	 BUFFER[6064]	//(internal1_m1030_Shift0) Shift0 - признак самохода
#define idinternal1_m1030_Shift0	 1553	//(internal1_m1030_Shift0) Shift0 - признак самохода
#define internal1_m1030_ShCntlSp0	 BUFFER[6066]	//(internal1_m1030_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1030_ShCntlSp0	 1554	//(internal1_m1030_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1030_ShiftControl	 BUFFER[6068]	//(internal1_m1030_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1030_ShiftControl	 1555	//(internal1_m1030_ShiftControl) ShiftControl - признак самохода
#define internal1_m545_X0	 BUFFER[6070]	//(internal1_m545_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m545_X0	 1556	//(internal1_m545_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m545_t0	 BUFFER[6075]	//(internal1_m545_t0) время нахождения в зоне возврата
#define idinternal1_m545_t0	 1557	//(internal1_m545_t0) время нахождения в зоне возврата
#define internal1_m545_BLDv0	 BUFFER[6080]	//(internal1_m545_BLDv0) BlDv - Блокировка движения
#define idinternal1_m545_BLDv0	 1558	//(internal1_m545_BLDv0) BlDv - Блокировка движения
#define internal1_m564_tx	 BUFFER[6081]	//(internal1_m564_tx) tx - время накопленное сек
#define idinternal1_m564_tx	 1559	//(internal1_m564_tx) tx - время накопленное сек
#define internal1_m564_y0	 BUFFER[6086]	//(internal1_m564_y0) y0
#define idinternal1_m564_y0	 1560	//(internal1_m564_y0) y0
#define internal1_m563_tx	 BUFFER[6087]	//(internal1_m563_tx) tx - время накопленное сек
#define idinternal1_m563_tx	 1561	//(internal1_m563_tx) tx - время накопленное сек
#define internal1_m563_y0	 BUFFER[6092]	//(internal1_m563_y0) y0
#define idinternal1_m563_y0	 1562	//(internal1_m563_y0) y0
#define internal1_m568_xptr	 BUFFER[6093]	//(internal1_m568_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m568_xptr	 1563	//(internal1_m568_xptr) указатель текущей позиции в массиве координат
#define internal1_m568_x0	 BUFFER[6096]	//(internal1_m568_x0) x0 - массив мгновенных значений координат
#define idinternal1_m568_x0	 1564	//(internal1_m568_x0) x0 - массив мгновенных значений координат
#define internal1_m568_tim0	 BUFFER[6846]	//(internal1_m568_tim0) tim0 - массив значений времени цикла
#define idinternal1_m568_tim0	 1565	//(internal1_m568_tim0) tim0 - массив значений времени цикла
#define internal1_m568_sumtim	 BUFFER[7596]	//(internal1_m568_sumtim) sumtim - время в пути
#define idinternal1_m568_sumtim	 1566	//(internal1_m568_sumtim) sumtim - время в пути
#define internal1_m568_StSpeed	 BUFFER[7601]	//(internal1_m568_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m568_StSpeed	 1567	//(internal1_m568_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m568_Vz0	 BUFFER[7606]	//(internal1_m568_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m568_Vz0	 1568	//(internal1_m568_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m568_flRazg	 BUFFER[7611]	//(internal1_m568_flRazg) признак разгона/торможения
#define idinternal1_m568_flRazg	 1569	//(internal1_m568_flRazg) признак разгона/торможения
#define internal1_m568_DelSp	 BUFFER[7614]	//(internal1_m568_DelSp) DelSp - время переключения скоростей
#define idinternal1_m568_DelSp	 1570	//(internal1_m568_DelSp) DelSp - время переключения скоростей
#define internal1_m568_z0	 BUFFER[7619]	//(internal1_m568_z0) z0 - точка прекращения движения
#define idinternal1_m568_z0	 1571	//(internal1_m568_z0) z0 - точка прекращения движения
#define internal1_m568_txZS	 BUFFER[7624]	//(internal1_m568_txZS) txZS
#define idinternal1_m568_txZS	 1572	//(internal1_m568_txZS) txZS
#define internal1_m568_tx	 BUFFER[7629]	//(internal1_m568_tx) tx
#define idinternal1_m568_tx	 1573	//(internal1_m568_tx) tx
#define internal1_m568_txd	 BUFFER[7634]	//(internal1_m568_txd) txd
#define idinternal1_m568_txd	 1574	//(internal1_m568_txd) txd
#define internal1_m568_txMBl	 BUFFER[7639]	//(internal1_m568_txMBl) tx
#define idinternal1_m568_txMBl	 1575	//(internal1_m568_txMBl) tx
#define internal1_m568_txBl	 BUFFER[7644]	//(internal1_m568_txBl) tx
#define idinternal1_m568_txBl	 1576	//(internal1_m568_txBl) tx
#define internal1_m568_Speed0	 BUFFER[7649]	//(internal1_m568_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m568_Speed0	 1577	//(internal1_m568_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m568_xz0	 BUFFER[7654]	//(internal1_m568_xz0) xz0 - новое задание мм
#define idinternal1_m568_xz0	 1578	//(internal1_m568_xz0) xz0 - новое задание мм
#define internal1_m568_tz0	 BUFFER[7659]	//(internal1_m568_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m568_tz0	 1579	//(internal1_m568_tz0) tz0 - время защиты от нового задания сек
#define internal1_m568_Shift0	 BUFFER[7664]	//(internal1_m568_Shift0) Shift0 - признак самохода
#define idinternal1_m568_Shift0	 1580	//(internal1_m568_Shift0) Shift0 - признак самохода
#define internal1_m568_ShCntlSp0	 BUFFER[7666]	//(internal1_m568_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m568_ShCntlSp0	 1581	//(internal1_m568_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m568_ShiftControl	 BUFFER[7668]	//(internal1_m568_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m568_ShiftControl	 1582	//(internal1_m568_ShiftControl) ShiftControl - признак самохода
#define internal1_m689_q0	 BUFFER[7670]	//(internal1_m689_q0) q0 - внутренний параметр
#define idinternal1_m689_q0	 1583	//(internal1_m689_q0) q0 - внутренний параметр
#define internal1_m175_X0	 BUFFER[7672]	//(internal1_m175_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m175_X0	 1584	//(internal1_m175_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m175_t0	 BUFFER[7677]	//(internal1_m175_t0) время нахождения в зоне возврата
#define idinternal1_m175_t0	 1585	//(internal1_m175_t0) время нахождения в зоне возврата
#define internal1_m175_BLDv0	 BUFFER[7682]	//(internal1_m175_BLDv0) BlDv - Блокировка движения
#define idinternal1_m175_BLDv0	 1586	//(internal1_m175_BLDv0) BlDv - Блокировка движения
#define internal1_m200_xptr	 BUFFER[7683]	//(internal1_m200_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m200_xptr	 1587	//(internal1_m200_xptr) указатель текущей позиции в массиве координат
#define internal1_m200_x0	 BUFFER[7686]	//(internal1_m200_x0) x0 - массив мгновенных значений координат
#define idinternal1_m200_x0	 1588	//(internal1_m200_x0) x0 - массив мгновенных значений координат
#define internal1_m200_tim0	 BUFFER[8436]	//(internal1_m200_tim0) tim0 - массив значений времени цикла
#define idinternal1_m200_tim0	 1589	//(internal1_m200_tim0) tim0 - массив значений времени цикла
#define internal1_m200_sumtim	 BUFFER[9186]	//(internal1_m200_sumtim) sumtim - время в пути
#define idinternal1_m200_sumtim	 1590	//(internal1_m200_sumtim) sumtim - время в пути
#define internal1_m200_StSpeed	 BUFFER[9191]	//(internal1_m200_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m200_StSpeed	 1591	//(internal1_m200_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m200_Vz0	 BUFFER[9196]	//(internal1_m200_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m200_Vz0	 1592	//(internal1_m200_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m200_flRazg	 BUFFER[9201]	//(internal1_m200_flRazg) признак разгона/торможения
#define idinternal1_m200_flRazg	 1593	//(internal1_m200_flRazg) признак разгона/торможения
#define internal1_m200_DelSp	 BUFFER[9204]	//(internal1_m200_DelSp) DelSp - время переключения скоростей
#define idinternal1_m200_DelSp	 1594	//(internal1_m200_DelSp) DelSp - время переключения скоростей
#define internal1_m200_z0	 BUFFER[9209]	//(internal1_m200_z0) z0 - точка прекращения движения
#define idinternal1_m200_z0	 1595	//(internal1_m200_z0) z0 - точка прекращения движения
#define internal1_m200_txZS	 BUFFER[9214]	//(internal1_m200_txZS) txZS
#define idinternal1_m200_txZS	 1596	//(internal1_m200_txZS) txZS
#define internal1_m200_tx	 BUFFER[9219]	//(internal1_m200_tx) tx
#define idinternal1_m200_tx	 1597	//(internal1_m200_tx) tx
#define internal1_m200_txd	 BUFFER[9224]	//(internal1_m200_txd) txd
#define idinternal1_m200_txd	 1598	//(internal1_m200_txd) txd
#define internal1_m200_txMBl	 BUFFER[9229]	//(internal1_m200_txMBl) tx
#define idinternal1_m200_txMBl	 1599	//(internal1_m200_txMBl) tx
#define internal1_m200_txBl	 BUFFER[9234]	//(internal1_m200_txBl) tx
#define idinternal1_m200_txBl	 1600	//(internal1_m200_txBl) tx
#define internal1_m200_Speed0	 BUFFER[9239]	//(internal1_m200_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m200_Speed0	 1601	//(internal1_m200_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m200_xz0	 BUFFER[9244]	//(internal1_m200_xz0) xz0 - новое задание мм
#define idinternal1_m200_xz0	 1602	//(internal1_m200_xz0) xz0 - новое задание мм
#define internal1_m200_tz0	 BUFFER[9249]	//(internal1_m200_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m200_tz0	 1603	//(internal1_m200_tz0) tz0 - время защиты от нового задания сек
#define internal1_m200_Shift0	 BUFFER[9254]	//(internal1_m200_Shift0) Shift0 - признак самохода
#define idinternal1_m200_Shift0	 1604	//(internal1_m200_Shift0) Shift0 - признак самохода
#define internal1_m200_ShCntlSp0	 BUFFER[9256]	//(internal1_m200_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m200_ShCntlSp0	 1605	//(internal1_m200_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m200_ShiftControl	 BUFFER[9258]	//(internal1_m200_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m200_ShiftControl	 1606	//(internal1_m200_ShiftControl) ShiftControl - признак самохода
#define internal1_m715_q0	 BUFFER[9260]	//(internal1_m715_q0) q0 - внутренний параметр
#define idinternal1_m715_q0	 1607	//(internal1_m715_q0) q0 - внутренний параметр
#define internal1_m512_DvUp0	 BUFFER[9262]	//(internal1_m512_DvUp0) - есть команда на движение вперёд
#define idinternal1_m512_DvUp0	 1608	//(internal1_m512_DvUp0) - есть команда на движение вперёд
#define internal1_m512_DvDw0	 BUFFER[9263]	//(internal1_m512_DvDw0) - есть команда на движение назад
#define idinternal1_m512_DvDw0	 1609	//(internal1_m512_DvDw0) - есть команда на движение назад
#define internal1_m512_FDvUp0	 BUFFER[9264]	//(internal1_m512_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m512_FDvUp0	 1610	//(internal1_m512_FDvUp0) - есть команда на движение вперёд
#define internal1_m512_FDvDw0	 BUFFER[9265]	//(internal1_m512_FDvDw0) - есть команда на движение назад
#define idinternal1_m512_FDvDw0	 1611	//(internal1_m512_FDvDw0) - есть команда на движение назад
#define internal1_m512_BlDv0	 BUFFER[9266]	//(internal1_m512_BlDv0) - была блокировка
#define idinternal1_m512_BlDv0	 1612	//(internal1_m512_BlDv0) - была блокировка
#define internal1_m512_Pkv0	 BUFFER[9267]	//(internal1_m512_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m512_Pkv0	 1613	//(internal1_m512_Pkv0) Pkv - передний конечный выключатель
#define internal1_m512_Pkav0	 BUFFER[9268]	//(internal1_m512_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m512_Pkav0	 1614	//(internal1_m512_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m512_Zkv0	 BUFFER[9269]	//(internal1_m512_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m512_Zkv0	 1615	//(internal1_m512_Zkv0) Zkv - задний конечный выключатель
#define internal1_m512_Zkav0	 BUFFER[9270]	//(internal1_m512_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m512_Zkav0	 1616	//(internal1_m512_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m512_txNm	 BUFFER[9271]	//(internal1_m512_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m512_txNm	 1617	//(internal1_m512_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m512_txSm	 BUFFER[9276]	//(internal1_m512_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m512_txSm	 1618	//(internal1_m512_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m512_txHr	 BUFFER[9281]	//(internal1_m512_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m512_txHr	 1619	//(internal1_m512_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m512_txLd	 BUFFER[9286]	//(internal1_m512_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m512_txLd	 1620	//(internal1_m512_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m512_fef	 BUFFER[9291]	//(internal1_m512_fef) fef
#define idinternal1_m512_fef	 1621	//(internal1_m512_fef) fef
#define internal1_m506_DvUp0	 BUFFER[9292]	//(internal1_m506_DvUp0) - есть команда на движение вперёд
#define idinternal1_m506_DvUp0	 1622	//(internal1_m506_DvUp0) - есть команда на движение вперёд
#define internal1_m506_DvDw0	 BUFFER[9293]	//(internal1_m506_DvDw0) - есть команда на движение назад
#define idinternal1_m506_DvDw0	 1623	//(internal1_m506_DvDw0) - есть команда на движение назад
#define internal1_m506_FDvUp0	 BUFFER[9294]	//(internal1_m506_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m506_FDvUp0	 1624	//(internal1_m506_FDvUp0) - есть команда на движение вперёд
#define internal1_m506_FDvDw0	 BUFFER[9295]	//(internal1_m506_FDvDw0) - есть команда на движение назад
#define idinternal1_m506_FDvDw0	 1625	//(internal1_m506_FDvDw0) - есть команда на движение назад
#define internal1_m506_BlDv0	 BUFFER[9296]	//(internal1_m506_BlDv0) - была блокировка
#define idinternal1_m506_BlDv0	 1626	//(internal1_m506_BlDv0) - была блокировка
#define internal1_m506_Pkv0	 BUFFER[9297]	//(internal1_m506_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m506_Pkv0	 1627	//(internal1_m506_Pkv0) Pkv - передний конечный выключатель
#define internal1_m506_Pkav0	 BUFFER[9298]	//(internal1_m506_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m506_Pkav0	 1628	//(internal1_m506_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m506_Zkv0	 BUFFER[9299]	//(internal1_m506_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m506_Zkv0	 1629	//(internal1_m506_Zkv0) Zkv - задний конечный выключатель
#define internal1_m506_Zkav0	 BUFFER[9300]	//(internal1_m506_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m506_Zkav0	 1630	//(internal1_m506_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m506_txNm	 BUFFER[9301]	//(internal1_m506_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m506_txNm	 1631	//(internal1_m506_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m506_txSm	 BUFFER[9306]	//(internal1_m506_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m506_txSm	 1632	//(internal1_m506_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m506_txHr	 BUFFER[9311]	//(internal1_m506_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m506_txHr	 1633	//(internal1_m506_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m506_txLd	 BUFFER[9316]	//(internal1_m506_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m506_txLd	 1634	//(internal1_m506_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m506_fef	 BUFFER[9321]	//(internal1_m506_fef) fef
#define idinternal1_m506_fef	 1635	//(internal1_m506_fef) fef
#define internal1_m904_X0	 BUFFER[9322]	//(internal1_m904_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m904_X0	 1636	//(internal1_m904_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m904_t0	 BUFFER[9327]	//(internal1_m904_t0) время нахождения в зоне возврата
#define idinternal1_m904_t0	 1637	//(internal1_m904_t0) время нахождения в зоне возврата
#define internal1_m904_BLDv0	 BUFFER[9332]	//(internal1_m904_BLDv0) BlDv - Блокировка движения
#define idinternal1_m904_BLDv0	 1638	//(internal1_m904_BLDv0) BlDv - Блокировка движения
#define internal1_m922_xptr	 BUFFER[9333]	//(internal1_m922_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m922_xptr	 1639	//(internal1_m922_xptr) указатель текущей позиции в массиве координат
#define internal1_m922_x0	 BUFFER[9336]	//(internal1_m922_x0) x0 - массив мгновенных значений координат
#define idinternal1_m922_x0	 1640	//(internal1_m922_x0) x0 - массив мгновенных значений координат
#define internal1_m922_tim0	 BUFFER[9736]	//(internal1_m922_tim0) tim0 - массив значений времени цикла
#define idinternal1_m922_tim0	 1641	//(internal1_m922_tim0) tim0 - массив значений времени цикла
#define internal1_m922_sumtim	 BUFFER[10136]	//(internal1_m922_sumtim) sumtim - время в пути
#define idinternal1_m922_sumtim	 1642	//(internal1_m922_sumtim) sumtim - время в пути
#define internal1_m922_StSpeed	 BUFFER[10141]	//(internal1_m922_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m922_StSpeed	 1643	//(internal1_m922_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m922_Vz0	 BUFFER[10146]	//(internal1_m922_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m922_Vz0	 1644	//(internal1_m922_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m922_flRazg	 BUFFER[10151]	//(internal1_m922_flRazg) признак разгона/торможения
#define idinternal1_m922_flRazg	 1645	//(internal1_m922_flRazg) признак разгона/торможения
#define internal1_m922_DelSp	 BUFFER[10154]	//(internal1_m922_DelSp) DelSp - время переключения скоростей
#define idinternal1_m922_DelSp	 1646	//(internal1_m922_DelSp) DelSp - время переключения скоростей
#define internal1_m922_z0	 BUFFER[10159]	//(internal1_m922_z0) z0 - точка прекращения движения
#define idinternal1_m922_z0	 1647	//(internal1_m922_z0) z0 - точка прекращения движения
#define internal1_m922_txZS	 BUFFER[10164]	//(internal1_m922_txZS) txZS
#define idinternal1_m922_txZS	 1648	//(internal1_m922_txZS) txZS
#define internal1_m922_tx	 BUFFER[10169]	//(internal1_m922_tx) tx
#define idinternal1_m922_tx	 1649	//(internal1_m922_tx) tx
#define internal1_m922_txd	 BUFFER[10174]	//(internal1_m922_txd) txd
#define idinternal1_m922_txd	 1650	//(internal1_m922_txd) txd
#define internal1_m922_txMBl	 BUFFER[10179]	//(internal1_m922_txMBl) tx
#define idinternal1_m922_txMBl	 1651	//(internal1_m922_txMBl) tx
#define internal1_m922_txBl	 BUFFER[10184]	//(internal1_m922_txBl) tx
#define idinternal1_m922_txBl	 1652	//(internal1_m922_txBl) tx
#define internal1_m922_Speed0	 BUFFER[10189]	//(internal1_m922_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m922_Speed0	 1653	//(internal1_m922_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m922_xz0	 BUFFER[10194]	//(internal1_m922_xz0) xz0 - новое задание мм
#define idinternal1_m922_xz0	 1654	//(internal1_m922_xz0) xz0 - новое задание мм
#define internal1_m922_tz0	 BUFFER[10199]	//(internal1_m922_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m922_tz0	 1655	//(internal1_m922_tz0) tz0 - время защиты от нового задания сек
#define internal1_m922_Shift0	 BUFFER[10204]	//(internal1_m922_Shift0) Shift0 - признак самохода
#define idinternal1_m922_Shift0	 1656	//(internal1_m922_Shift0) Shift0 - признак самохода
#define internal1_m922_ShCntlSp0	 BUFFER[10206]	//(internal1_m922_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m922_ShCntlSp0	 1657	//(internal1_m922_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m922_ShiftControl	 BUFFER[10208]	//(internal1_m922_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m922_ShiftControl	 1658	//(internal1_m922_ShiftControl) ShiftControl - признак самохода
#define internal1_m1773_X0	 BUFFER[10210]	//(internal1_m1773_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1773_X0	 1659	//(internal1_m1773_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1773_t0	 BUFFER[10215]	//(internal1_m1773_t0) время нахождения в зоне возврата
#define idinternal1_m1773_t0	 1660	//(internal1_m1773_t0) время нахождения в зоне возврата
#define internal1_m1773_BLDv0	 BUFFER[10220]	//(internal1_m1773_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1773_BLDv0	 1661	//(internal1_m1773_BLDv0) BlDv - Блокировка движения
#define internal1_m1246_X0	 BUFFER[10221]	//(internal1_m1246_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1246_X0	 1662	//(internal1_m1246_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1246_t0	 BUFFER[10226]	//(internal1_m1246_t0) время нахождения в зоне возврата
#define idinternal1_m1246_t0	 1663	//(internal1_m1246_t0) время нахождения в зоне возврата
#define internal1_m1246_BLDv0	 BUFFER[10231]	//(internal1_m1246_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1246_BLDv0	 1664	//(internal1_m1246_BLDv0) BlDv - Блокировка движения
#define internal1_m687_q0	 BUFFER[10232]	//(internal1_m687_q0) q0 - внутренний параметр
#define idinternal1_m687_q0	 1665	//(internal1_m687_q0) q0 - внутренний параметр
#define internal1_m1343_X0	 BUFFER[10234]	//(internal1_m1343_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1343_X0	 1666	//(internal1_m1343_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1343_t0	 BUFFER[10239]	//(internal1_m1343_t0) время нахождения в зоне возврата
#define idinternal1_m1343_t0	 1667	//(internal1_m1343_t0) время нахождения в зоне возврата
#define internal1_m1343_BLDv0	 BUFFER[10244]	//(internal1_m1343_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1343_BLDv0	 1668	//(internal1_m1343_BLDv0) BlDv - Блокировка движения
#define internal1_m1371_tx	 BUFFER[10245]	//(internal1_m1371_tx) tx - время накопленное сек
#define idinternal1_m1371_tx	 1669	//(internal1_m1371_tx) tx - время накопленное сек
#define internal1_m1371_y0	 BUFFER[10250]	//(internal1_m1371_y0) y0
#define idinternal1_m1371_y0	 1670	//(internal1_m1371_y0) y0
#define internal1_m1370_tx	 BUFFER[10251]	//(internal1_m1370_tx) tx - время накопленное сек
#define idinternal1_m1370_tx	 1671	//(internal1_m1370_tx) tx - время накопленное сек
#define internal1_m1370_y0	 BUFFER[10256]	//(internal1_m1370_y0) y0
#define idinternal1_m1370_y0	 1672	//(internal1_m1370_y0) y0
#define internal1_m1378_xptr	 BUFFER[10257]	//(internal1_m1378_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1378_xptr	 1673	//(internal1_m1378_xptr) указатель текущей позиции в массиве координат
#define internal1_m1378_x0	 BUFFER[10260]	//(internal1_m1378_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1378_x0	 1674	//(internal1_m1378_x0) x0 - массив мгновенных значений координат
#define internal1_m1378_tim0	 BUFFER[10660]	//(internal1_m1378_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1378_tim0	 1675	//(internal1_m1378_tim0) tim0 - массив значений времени цикла
#define internal1_m1378_sumtim	 BUFFER[11060]	//(internal1_m1378_sumtim) sumtim - время в пути
#define idinternal1_m1378_sumtim	 1676	//(internal1_m1378_sumtim) sumtim - время в пути
#define internal1_m1378_StSpeed	 BUFFER[11065]	//(internal1_m1378_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1378_StSpeed	 1677	//(internal1_m1378_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1378_Vz0	 BUFFER[11070]	//(internal1_m1378_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1378_Vz0	 1678	//(internal1_m1378_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1378_flRazg	 BUFFER[11075]	//(internal1_m1378_flRazg) признак разгона/торможения
#define idinternal1_m1378_flRazg	 1679	//(internal1_m1378_flRazg) признак разгона/торможения
#define internal1_m1378_DelSp	 BUFFER[11078]	//(internal1_m1378_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1378_DelSp	 1680	//(internal1_m1378_DelSp) DelSp - время переключения скоростей
#define internal1_m1378_z0	 BUFFER[11083]	//(internal1_m1378_z0) z0 - точка прекращения движения
#define idinternal1_m1378_z0	 1681	//(internal1_m1378_z0) z0 - точка прекращения движения
#define internal1_m1378_txZS	 BUFFER[11088]	//(internal1_m1378_txZS) txZS
#define idinternal1_m1378_txZS	 1682	//(internal1_m1378_txZS) txZS
#define internal1_m1378_tx	 BUFFER[11093]	//(internal1_m1378_tx) tx
#define idinternal1_m1378_tx	 1683	//(internal1_m1378_tx) tx
#define internal1_m1378_txd	 BUFFER[11098]	//(internal1_m1378_txd) txd
#define idinternal1_m1378_txd	 1684	//(internal1_m1378_txd) txd
#define internal1_m1378_txMBl	 BUFFER[11103]	//(internal1_m1378_txMBl) tx
#define idinternal1_m1378_txMBl	 1685	//(internal1_m1378_txMBl) tx
#define internal1_m1378_txBl	 BUFFER[11108]	//(internal1_m1378_txBl) tx
#define idinternal1_m1378_txBl	 1686	//(internal1_m1378_txBl) tx
#define internal1_m1378_Speed0	 BUFFER[11113]	//(internal1_m1378_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1378_Speed0	 1687	//(internal1_m1378_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1378_xz0	 BUFFER[11118]	//(internal1_m1378_xz0) xz0 - новое задание мм
#define idinternal1_m1378_xz0	 1688	//(internal1_m1378_xz0) xz0 - новое задание мм
#define internal1_m1378_tz0	 BUFFER[11123]	//(internal1_m1378_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1378_tz0	 1689	//(internal1_m1378_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1378_Shift0	 BUFFER[11128]	//(internal1_m1378_Shift0) Shift0 - признак самохода
#define idinternal1_m1378_Shift0	 1690	//(internal1_m1378_Shift0) Shift0 - признак самохода
#define internal1_m1378_ShCntlSp0	 BUFFER[11130]	//(internal1_m1378_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1378_ShCntlSp0	 1691	//(internal1_m1378_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1378_ShiftControl	 BUFFER[11132]	//(internal1_m1378_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1378_ShiftControl	 1692	//(internal1_m1378_ShiftControl) ShiftControl - признак самохода
#define internal1_m707_q0	 BUFFER[11134]	//(internal1_m707_q0) q0 - внутренний параметр
#define idinternal1_m707_q0	 1693	//(internal1_m707_q0) q0 - внутренний параметр
#define internal1_m1787_tx	 BUFFER[11136]	//(internal1_m1787_tx) tx - время накопленное сек
#define idinternal1_m1787_tx	 1694	//(internal1_m1787_tx) tx - время накопленное сек
#define internal1_m1787_y0	 BUFFER[11141]	//(internal1_m1787_y0) y0
#define idinternal1_m1787_y0	 1695	//(internal1_m1787_y0) y0
#define internal1_m1791_tx	 BUFFER[11142]	//(internal1_m1791_tx) tx - время накопленное сек
#define idinternal1_m1791_tx	 1696	//(internal1_m1791_tx) tx - время накопленное сек
#define internal1_m1791_y0	 BUFFER[11147]	//(internal1_m1791_y0) y0
#define idinternal1_m1791_y0	 1697	//(internal1_m1791_y0) y0
#define internal1_m1776_DvUp0	 BUFFER[11148]	//(internal1_m1776_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1776_DvUp0	 1698	//(internal1_m1776_DvUp0) - есть команда на движение вперёд
#define internal1_m1776_DvDw0	 BUFFER[11149]	//(internal1_m1776_DvDw0) - есть команда на движение назад
#define idinternal1_m1776_DvDw0	 1699	//(internal1_m1776_DvDw0) - есть команда на движение назад
#define internal1_m1776_FDvUp0	 BUFFER[11150]	//(internal1_m1776_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1776_FDvUp0	 1700	//(internal1_m1776_FDvUp0) - есть команда на движение вперёд
#define internal1_m1776_FDvDw0	 BUFFER[11151]	//(internal1_m1776_FDvDw0) - есть команда на движение назад
#define idinternal1_m1776_FDvDw0	 1701	//(internal1_m1776_FDvDw0) - есть команда на движение назад
#define internal1_m1776_BlDv0	 BUFFER[11152]	//(internal1_m1776_BlDv0) - была блокировка
#define idinternal1_m1776_BlDv0	 1702	//(internal1_m1776_BlDv0) - была блокировка
#define internal1_m1776_Pkv0	 BUFFER[11153]	//(internal1_m1776_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1776_Pkv0	 1703	//(internal1_m1776_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1776_Pkav0	 BUFFER[11154]	//(internal1_m1776_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1776_Pkav0	 1704	//(internal1_m1776_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1776_Zkv0	 BUFFER[11155]	//(internal1_m1776_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1776_Zkv0	 1705	//(internal1_m1776_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1776_Zkav0	 BUFFER[11156]	//(internal1_m1776_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1776_Zkav0	 1706	//(internal1_m1776_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1776_txNm	 BUFFER[11157]	//(internal1_m1776_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1776_txNm	 1707	//(internal1_m1776_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1776_txSm	 BUFFER[11162]	//(internal1_m1776_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1776_txSm	 1708	//(internal1_m1776_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1776_txHr	 BUFFER[11167]	//(internal1_m1776_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1776_txHr	 1709	//(internal1_m1776_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1776_txLd	 BUFFER[11172]	//(internal1_m1776_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1776_txLd	 1710	//(internal1_m1776_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1776_fef	 BUFFER[11177]	//(internal1_m1776_fef) fef
#define idinternal1_m1776_fef	 1711	//(internal1_m1776_fef) fef
#define internal1_m1795_xptr	 BUFFER[11178]	//(internal1_m1795_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1795_xptr	 1712	//(internal1_m1795_xptr) указатель текущей позиции в массиве координат
#define internal1_m1795_x0	 BUFFER[11181]	//(internal1_m1795_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1795_x0	 1713	//(internal1_m1795_x0) x0 - массив мгновенных значений координат
#define internal1_m1795_tim0	 BUFFER[11281]	//(internal1_m1795_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1795_tim0	 1714	//(internal1_m1795_tim0) tim0 - массив значений времени цикла
#define internal1_m1795_sumtim	 BUFFER[11381]	//(internal1_m1795_sumtim) sumtim - время в пути
#define idinternal1_m1795_sumtim	 1715	//(internal1_m1795_sumtim) sumtim - время в пути
#define internal1_m1795_StSpeed	 BUFFER[11386]	//(internal1_m1795_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1795_StSpeed	 1716	//(internal1_m1795_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1795_Vz0	 BUFFER[11391]	//(internal1_m1795_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1795_Vz0	 1717	//(internal1_m1795_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1795_flRazg	 BUFFER[11396]	//(internal1_m1795_flRazg) признак разгона/торможения
#define idinternal1_m1795_flRazg	 1718	//(internal1_m1795_flRazg) признак разгона/торможения
#define internal1_m1795_DelSp	 BUFFER[11399]	//(internal1_m1795_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1795_DelSp	 1719	//(internal1_m1795_DelSp) DelSp - время переключения скоростей
#define internal1_m1795_z0	 BUFFER[11404]	//(internal1_m1795_z0) z0 - точка прекращения движения
#define idinternal1_m1795_z0	 1720	//(internal1_m1795_z0) z0 - точка прекращения движения
#define internal1_m1795_txZS	 BUFFER[11409]	//(internal1_m1795_txZS) txZS
#define idinternal1_m1795_txZS	 1721	//(internal1_m1795_txZS) txZS
#define internal1_m1795_tx	 BUFFER[11414]	//(internal1_m1795_tx) tx
#define idinternal1_m1795_tx	 1722	//(internal1_m1795_tx) tx
#define internal1_m1795_txd	 BUFFER[11419]	//(internal1_m1795_txd) txd
#define idinternal1_m1795_txd	 1723	//(internal1_m1795_txd) txd
#define internal1_m1795_txMBl	 BUFFER[11424]	//(internal1_m1795_txMBl) tx
#define idinternal1_m1795_txMBl	 1724	//(internal1_m1795_txMBl) tx
#define internal1_m1795_txBl	 BUFFER[11429]	//(internal1_m1795_txBl) tx
#define idinternal1_m1795_txBl	 1725	//(internal1_m1795_txBl) tx
#define internal1_m1795_Speed0	 BUFFER[11434]	//(internal1_m1795_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1795_Speed0	 1726	//(internal1_m1795_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1795_xz0	 BUFFER[11439]	//(internal1_m1795_xz0) xz0 - новое задание мм
#define idinternal1_m1795_xz0	 1727	//(internal1_m1795_xz0) xz0 - новое задание мм
#define internal1_m1795_tz0	 BUFFER[11444]	//(internal1_m1795_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1795_tz0	 1728	//(internal1_m1795_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1795_Shift0	 BUFFER[11449]	//(internal1_m1795_Shift0) Shift0 - признак самохода
#define idinternal1_m1795_Shift0	 1729	//(internal1_m1795_Shift0) Shift0 - признак самохода
#define internal1_m1795_ShCntlSp0	 BUFFER[11451]	//(internal1_m1795_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1795_ShCntlSp0	 1730	//(internal1_m1795_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1795_ShiftControl	 BUFFER[11453]	//(internal1_m1795_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1795_ShiftControl	 1731	//(internal1_m1795_ShiftControl) ShiftControl - признак самохода
#define internal1_m1263_tx	 BUFFER[11455]	//(internal1_m1263_tx) tx - время накопленное сек
#define idinternal1_m1263_tx	 1732	//(internal1_m1263_tx) tx - время накопленное сек
#define internal1_m1263_y0	 BUFFER[11460]	//(internal1_m1263_y0) y0
#define idinternal1_m1263_y0	 1733	//(internal1_m1263_y0) y0
#define internal1_m1267_tx	 BUFFER[11461]	//(internal1_m1267_tx) tx - время накопленное сек
#define idinternal1_m1267_tx	 1734	//(internal1_m1267_tx) tx - время накопленное сек
#define internal1_m1267_y0	 BUFFER[11466]	//(internal1_m1267_y0) y0
#define idinternal1_m1267_y0	 1735	//(internal1_m1267_y0) y0
#define internal1_m697_q0	 BUFFER[11467]	//(internal1_m697_q0) q0 - внутренний параметр
#define idinternal1_m697_q0	 1736	//(internal1_m697_q0) q0 - внутренний параметр
#define internal1_m662_q0	 BUFFER[11469]	//(internal1_m662_q0) q0 - внутренний параметр
#define idinternal1_m662_q0	 1737	//(internal1_m662_q0) q0 - внутренний параметр
#define internal1_m1253_DvUp0	 BUFFER[11471]	//(internal1_m1253_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1253_DvUp0	 1738	//(internal1_m1253_DvUp0) - есть команда на движение вперёд
#define internal1_m1253_DvDw0	 BUFFER[11472]	//(internal1_m1253_DvDw0) - есть команда на движение назад
#define idinternal1_m1253_DvDw0	 1739	//(internal1_m1253_DvDw0) - есть команда на движение назад
#define internal1_m1253_FDvUp0	 BUFFER[11473]	//(internal1_m1253_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1253_FDvUp0	 1740	//(internal1_m1253_FDvUp0) - есть команда на движение вперёд
#define internal1_m1253_FDvDw0	 BUFFER[11474]	//(internal1_m1253_FDvDw0) - есть команда на движение назад
#define idinternal1_m1253_FDvDw0	 1741	//(internal1_m1253_FDvDw0) - есть команда на движение назад
#define internal1_m1253_BlDv0	 BUFFER[11475]	//(internal1_m1253_BlDv0) - была блокировка
#define idinternal1_m1253_BlDv0	 1742	//(internal1_m1253_BlDv0) - была блокировка
#define internal1_m1253_Pkv0	 BUFFER[11476]	//(internal1_m1253_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1253_Pkv0	 1743	//(internal1_m1253_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1253_Pkav0	 BUFFER[11477]	//(internal1_m1253_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1253_Pkav0	 1744	//(internal1_m1253_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1253_Zkv0	 BUFFER[11478]	//(internal1_m1253_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1253_Zkv0	 1745	//(internal1_m1253_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1253_Zkav0	 BUFFER[11479]	//(internal1_m1253_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1253_Zkav0	 1746	//(internal1_m1253_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1253_txNm	 BUFFER[11480]	//(internal1_m1253_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1253_txNm	 1747	//(internal1_m1253_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1253_txSm	 BUFFER[11485]	//(internal1_m1253_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1253_txSm	 1748	//(internal1_m1253_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1253_txHr	 BUFFER[11490]	//(internal1_m1253_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1253_txHr	 1749	//(internal1_m1253_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1253_txLd	 BUFFER[11495]	//(internal1_m1253_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1253_txLd	 1750	//(internal1_m1253_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1253_fef	 BUFFER[11500]	//(internal1_m1253_fef) fef
#define idinternal1_m1253_fef	 1751	//(internal1_m1253_fef) fef
#define internal1_m1273_xptr	 BUFFER[11501]	//(internal1_m1273_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1273_xptr	 1752	//(internal1_m1273_xptr) указатель текущей позиции в массиве координат
#define internal1_m1273_x0	 BUFFER[11504]	//(internal1_m1273_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1273_x0	 1753	//(internal1_m1273_x0) x0 - массив мгновенных значений координат
#define internal1_m1273_tim0	 BUFFER[11604]	//(internal1_m1273_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1273_tim0	 1754	//(internal1_m1273_tim0) tim0 - массив значений времени цикла
#define internal1_m1273_sumtim	 BUFFER[11704]	//(internal1_m1273_sumtim) sumtim - время в пути
#define idinternal1_m1273_sumtim	 1755	//(internal1_m1273_sumtim) sumtim - время в пути
#define internal1_m1273_StSpeed	 BUFFER[11709]	//(internal1_m1273_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1273_StSpeed	 1756	//(internal1_m1273_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1273_Vz0	 BUFFER[11714]	//(internal1_m1273_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1273_Vz0	 1757	//(internal1_m1273_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1273_flRazg	 BUFFER[11719]	//(internal1_m1273_flRazg) признак разгона/торможения
#define idinternal1_m1273_flRazg	 1758	//(internal1_m1273_flRazg) признак разгона/торможения
#define internal1_m1273_DelSp	 BUFFER[11722]	//(internal1_m1273_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1273_DelSp	 1759	//(internal1_m1273_DelSp) DelSp - время переключения скоростей
#define internal1_m1273_z0	 BUFFER[11727]	//(internal1_m1273_z0) z0 - точка прекращения движения
#define idinternal1_m1273_z0	 1760	//(internal1_m1273_z0) z0 - точка прекращения движения
#define internal1_m1273_txZS	 BUFFER[11732]	//(internal1_m1273_txZS) txZS
#define idinternal1_m1273_txZS	 1761	//(internal1_m1273_txZS) txZS
#define internal1_m1273_tx	 BUFFER[11737]	//(internal1_m1273_tx) tx
#define idinternal1_m1273_tx	 1762	//(internal1_m1273_tx) tx
#define internal1_m1273_txd	 BUFFER[11742]	//(internal1_m1273_txd) txd
#define idinternal1_m1273_txd	 1763	//(internal1_m1273_txd) txd
#define internal1_m1273_txMBl	 BUFFER[11747]	//(internal1_m1273_txMBl) tx
#define idinternal1_m1273_txMBl	 1764	//(internal1_m1273_txMBl) tx
#define internal1_m1273_txBl	 BUFFER[11752]	//(internal1_m1273_txBl) tx
#define idinternal1_m1273_txBl	 1765	//(internal1_m1273_txBl) tx
#define internal1_m1273_Speed0	 BUFFER[11757]	//(internal1_m1273_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1273_Speed0	 1766	//(internal1_m1273_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1273_xz0	 BUFFER[11762]	//(internal1_m1273_xz0) xz0 - новое задание мм
#define idinternal1_m1273_xz0	 1767	//(internal1_m1273_xz0) xz0 - новое задание мм
#define internal1_m1273_tz0	 BUFFER[11767]	//(internal1_m1273_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1273_tz0	 1768	//(internal1_m1273_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1273_Shift0	 BUFFER[11772]	//(internal1_m1273_Shift0) Shift0 - признак самохода
#define idinternal1_m1273_Shift0	 1769	//(internal1_m1273_Shift0) Shift0 - признак самохода
#define internal1_m1273_ShCntlSp0	 BUFFER[11774]	//(internal1_m1273_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1273_ShCntlSp0	 1770	//(internal1_m1273_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1273_ShiftControl	 BUFFER[11776]	//(internal1_m1273_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1273_ShiftControl	 1771	//(internal1_m1273_ShiftControl) ShiftControl - признак самохода
#define internal1_m825_x0	 BUFFER[11778]	//(internal1_m825_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m825_x0	 1772	//(internal1_m825_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m794_x0	 BUFFER[11780]	//(internal1_m794_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m794_x0	 1773	//(internal1_m794_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m736_x0	 BUFFER[11782]	//(internal1_m736_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m736_x0	 1774	//(internal1_m736_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m850_q0	 BUFFER[11784]	//(internal1_m850_q0) q0 - внутренний параметр
#define idinternal1_m850_q0	 1775	//(internal1_m850_q0) q0 - внутренний параметр
#define internal1_m845_q0	 BUFFER[11786]	//(internal1_m845_q0) q0 - внутренний параметр
#define idinternal1_m845_q0	 1776	//(internal1_m845_q0) q0 - внутренний параметр
#define internal1_m813_q0	 BUFFER[11788]	//(internal1_m813_q0) q0 - внутренний параметр
#define idinternal1_m813_q0	 1777	//(internal1_m813_q0) q0 - внутренний параметр
#define internal1_m818_q0	 BUFFER[11790]	//(internal1_m818_q0) q0 - внутренний параметр
#define idinternal1_m818_q0	 1778	//(internal1_m818_q0) q0 - внутренний параметр
#define internal1_m826_q0	 BUFFER[11792]	//(internal1_m826_q0) q0 - внутренний параметр
#define idinternal1_m826_q0	 1779	//(internal1_m826_q0) q0 - внутренний параметр
#define internal1_m838_q0	 BUFFER[11794]	//(internal1_m838_q0) q0 - внутренний параметр
#define idinternal1_m838_q0	 1780	//(internal1_m838_q0) q0 - внутренний параметр
#define internal1_m816_q0	 BUFFER[11796]	//(internal1_m816_q0) q0 - внутренний параметр
#define idinternal1_m816_q0	 1781	//(internal1_m816_q0) q0 - внутренний параметр
#define internal1_m1316_DvUp0	 BUFFER[11798]	//(internal1_m1316_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1316_DvUp0	 1782	//(internal1_m1316_DvUp0) - есть команда на движение вперёд
#define internal1_m1316_DvDw0	 BUFFER[11799]	//(internal1_m1316_DvDw0) - есть команда на движение назад
#define idinternal1_m1316_DvDw0	 1783	//(internal1_m1316_DvDw0) - есть команда на движение назад
#define internal1_m1316_FDvUp0	 BUFFER[11800]	//(internal1_m1316_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1316_FDvUp0	 1784	//(internal1_m1316_FDvUp0) - есть команда на движение вперёд
#define internal1_m1316_FDvDw0	 BUFFER[11801]	//(internal1_m1316_FDvDw0) - есть команда на движение назад
#define idinternal1_m1316_FDvDw0	 1785	//(internal1_m1316_FDvDw0) - есть команда на движение назад
#define internal1_m1316_BlDv0	 BUFFER[11802]	//(internal1_m1316_BlDv0) - была блокировка
#define idinternal1_m1316_BlDv0	 1786	//(internal1_m1316_BlDv0) - была блокировка
#define internal1_m1316_Pkv0	 BUFFER[11803]	//(internal1_m1316_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1316_Pkv0	 1787	//(internal1_m1316_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1316_Pkav0	 BUFFER[11804]	//(internal1_m1316_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1316_Pkav0	 1788	//(internal1_m1316_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1316_Zkv0	 BUFFER[11805]	//(internal1_m1316_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1316_Zkv0	 1789	//(internal1_m1316_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1316_Zkav0	 BUFFER[11806]	//(internal1_m1316_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1316_Zkav0	 1790	//(internal1_m1316_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1316_txNm	 BUFFER[11807]	//(internal1_m1316_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1316_txNm	 1791	//(internal1_m1316_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1316_txSm	 BUFFER[11812]	//(internal1_m1316_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1316_txSm	 1792	//(internal1_m1316_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1316_txHr	 BUFFER[11817]	//(internal1_m1316_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1316_txHr	 1793	//(internal1_m1316_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1316_txLd	 BUFFER[11822]	//(internal1_m1316_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1316_txLd	 1794	//(internal1_m1316_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1316_fef	 BUFFER[11827]	//(internal1_m1316_fef) fef
#define idinternal1_m1316_fef	 1795	//(internal1_m1316_fef) fef
#define internal1_m1306_DvUp0	 BUFFER[11828]	//(internal1_m1306_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1306_DvUp0	 1796	//(internal1_m1306_DvUp0) - есть команда на движение вперёд
#define internal1_m1306_DvDw0	 BUFFER[11829]	//(internal1_m1306_DvDw0) - есть команда на движение назад
#define idinternal1_m1306_DvDw0	 1797	//(internal1_m1306_DvDw0) - есть команда на движение назад
#define internal1_m1306_FDvUp0	 BUFFER[11830]	//(internal1_m1306_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1306_FDvUp0	 1798	//(internal1_m1306_FDvUp0) - есть команда на движение вперёд
#define internal1_m1306_FDvDw0	 BUFFER[11831]	//(internal1_m1306_FDvDw0) - есть команда на движение назад
#define idinternal1_m1306_FDvDw0	 1799	//(internal1_m1306_FDvDw0) - есть команда на движение назад
#define internal1_m1306_BlDv0	 BUFFER[11832]	//(internal1_m1306_BlDv0) - была блокировка
#define idinternal1_m1306_BlDv0	 1800	//(internal1_m1306_BlDv0) - была блокировка
#define internal1_m1306_Pkv0	 BUFFER[11833]	//(internal1_m1306_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1306_Pkv0	 1801	//(internal1_m1306_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1306_Pkav0	 BUFFER[11834]	//(internal1_m1306_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1306_Pkav0	 1802	//(internal1_m1306_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1306_Zkv0	 BUFFER[11835]	//(internal1_m1306_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1306_Zkv0	 1803	//(internal1_m1306_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1306_Zkav0	 BUFFER[11836]	//(internal1_m1306_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1306_Zkav0	 1804	//(internal1_m1306_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1306_txNm	 BUFFER[11837]	//(internal1_m1306_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1306_txNm	 1805	//(internal1_m1306_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1306_txSm	 BUFFER[11842]	//(internal1_m1306_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1306_txSm	 1806	//(internal1_m1306_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1306_txHr	 BUFFER[11847]	//(internal1_m1306_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1306_txHr	 1807	//(internal1_m1306_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1306_txLd	 BUFFER[11852]	//(internal1_m1306_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1306_txLd	 1808	//(internal1_m1306_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1306_fef	 BUFFER[11857]	//(internal1_m1306_fef) fef
#define idinternal1_m1306_fef	 1809	//(internal1_m1306_fef) fef
#define internal1_m874_DvUp0	 BUFFER[11858]	//(internal1_m874_DvUp0) - есть команда на движение вперёд
#define idinternal1_m874_DvUp0	 1810	//(internal1_m874_DvUp0) - есть команда на движение вперёд
#define internal1_m874_DvDw0	 BUFFER[11859]	//(internal1_m874_DvDw0) - есть команда на движение назад
#define idinternal1_m874_DvDw0	 1811	//(internal1_m874_DvDw0) - есть команда на движение назад
#define internal1_m874_FDvUp0	 BUFFER[11860]	//(internal1_m874_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m874_FDvUp0	 1812	//(internal1_m874_FDvUp0) - есть команда на движение вперёд
#define internal1_m874_FDvDw0	 BUFFER[11861]	//(internal1_m874_FDvDw0) - есть команда на движение назад
#define idinternal1_m874_FDvDw0	 1813	//(internal1_m874_FDvDw0) - есть команда на движение назад
#define internal1_m874_BlDv0	 BUFFER[11862]	//(internal1_m874_BlDv0) - была блокировка
#define idinternal1_m874_BlDv0	 1814	//(internal1_m874_BlDv0) - была блокировка
#define internal1_m874_Pkv0	 BUFFER[11863]	//(internal1_m874_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m874_Pkv0	 1815	//(internal1_m874_Pkv0) Pkv - передний конечный выключатель
#define internal1_m874_Pkav0	 BUFFER[11864]	//(internal1_m874_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m874_Pkav0	 1816	//(internal1_m874_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m874_Zkv0	 BUFFER[11865]	//(internal1_m874_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m874_Zkv0	 1817	//(internal1_m874_Zkv0) Zkv - задний конечный выключатель
#define internal1_m874_Zkav0	 BUFFER[11866]	//(internal1_m874_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m874_Zkav0	 1818	//(internal1_m874_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m874_txNm	 BUFFER[11867]	//(internal1_m874_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m874_txNm	 1819	//(internal1_m874_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m874_txSm	 BUFFER[11872]	//(internal1_m874_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m874_txSm	 1820	//(internal1_m874_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m874_txHr	 BUFFER[11877]	//(internal1_m874_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m874_txHr	 1821	//(internal1_m874_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m874_txLd	 BUFFER[11882]	//(internal1_m874_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m874_txLd	 1822	//(internal1_m874_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m874_fef	 BUFFER[11887]	//(internal1_m874_fef) fef
#define idinternal1_m874_fef	 1823	//(internal1_m874_fef) fef
#define internal1_m870_DvUp0	 BUFFER[11888]	//(internal1_m870_DvUp0) - есть команда на движение вперёд
#define idinternal1_m870_DvUp0	 1824	//(internal1_m870_DvUp0) - есть команда на движение вперёд
#define internal1_m870_DvDw0	 BUFFER[11889]	//(internal1_m870_DvDw0) - есть команда на движение назад
#define idinternal1_m870_DvDw0	 1825	//(internal1_m870_DvDw0) - есть команда на движение назад
#define internal1_m870_FDvUp0	 BUFFER[11890]	//(internal1_m870_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m870_FDvUp0	 1826	//(internal1_m870_FDvUp0) - есть команда на движение вперёд
#define internal1_m870_FDvDw0	 BUFFER[11891]	//(internal1_m870_FDvDw0) - есть команда на движение назад
#define idinternal1_m870_FDvDw0	 1827	//(internal1_m870_FDvDw0) - есть команда на движение назад
#define internal1_m870_BlDv0	 BUFFER[11892]	//(internal1_m870_BlDv0) - была блокировка
#define idinternal1_m870_BlDv0	 1828	//(internal1_m870_BlDv0) - была блокировка
#define internal1_m870_Pkv0	 BUFFER[11893]	//(internal1_m870_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m870_Pkv0	 1829	//(internal1_m870_Pkv0) Pkv - передний конечный выключатель
#define internal1_m870_Pkav0	 BUFFER[11894]	//(internal1_m870_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m870_Pkav0	 1830	//(internal1_m870_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m870_Zkv0	 BUFFER[11895]	//(internal1_m870_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m870_Zkv0	 1831	//(internal1_m870_Zkv0) Zkv - задний конечный выключатель
#define internal1_m870_Zkav0	 BUFFER[11896]	//(internal1_m870_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m870_Zkav0	 1832	//(internal1_m870_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m870_txNm	 BUFFER[11897]	//(internal1_m870_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m870_txNm	 1833	//(internal1_m870_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m870_txSm	 BUFFER[11902]	//(internal1_m870_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m870_txSm	 1834	//(internal1_m870_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m870_txHr	 BUFFER[11907]	//(internal1_m870_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m870_txHr	 1835	//(internal1_m870_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m870_txLd	 BUFFER[11912]	//(internal1_m870_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m870_txLd	 1836	//(internal1_m870_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m870_fef	 BUFFER[11917]	//(internal1_m870_fef) fef
#define idinternal1_m870_fef	 1837	//(internal1_m870_fef) fef
#define internal1_m385_DvUp0	 BUFFER[11918]	//(internal1_m385_DvUp0) - есть команда на движение вперёд
#define idinternal1_m385_DvUp0	 1838	//(internal1_m385_DvUp0) - есть команда на движение вперёд
#define internal1_m385_DvDw0	 BUFFER[11919]	//(internal1_m385_DvDw0) - есть команда на движение назад
#define idinternal1_m385_DvDw0	 1839	//(internal1_m385_DvDw0) - есть команда на движение назад
#define internal1_m385_FDvUp0	 BUFFER[11920]	//(internal1_m385_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m385_FDvUp0	 1840	//(internal1_m385_FDvUp0) - есть команда на движение вперёд
#define internal1_m385_FDvDw0	 BUFFER[11921]	//(internal1_m385_FDvDw0) - есть команда на движение назад
#define idinternal1_m385_FDvDw0	 1841	//(internal1_m385_FDvDw0) - есть команда на движение назад
#define internal1_m385_BlDv0	 BUFFER[11922]	//(internal1_m385_BlDv0) - была блокировка
#define idinternal1_m385_BlDv0	 1842	//(internal1_m385_BlDv0) - была блокировка
#define internal1_m385_Pkv0	 BUFFER[11923]	//(internal1_m385_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m385_Pkv0	 1843	//(internal1_m385_Pkv0) Pkv - передний конечный выключатель
#define internal1_m385_Pkav0	 BUFFER[11924]	//(internal1_m385_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m385_Pkav0	 1844	//(internal1_m385_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m385_Zkv0	 BUFFER[11925]	//(internal1_m385_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m385_Zkv0	 1845	//(internal1_m385_Zkv0) Zkv - задний конечный выключатель
#define internal1_m385_Zkav0	 BUFFER[11926]	//(internal1_m385_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m385_Zkav0	 1846	//(internal1_m385_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m385_txNm	 BUFFER[11927]	//(internal1_m385_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m385_txNm	 1847	//(internal1_m385_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m385_txSm	 BUFFER[11932]	//(internal1_m385_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m385_txSm	 1848	//(internal1_m385_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m385_txHr	 BUFFER[11937]	//(internal1_m385_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m385_txHr	 1849	//(internal1_m385_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m385_txLd	 BUFFER[11942]	//(internal1_m385_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m385_txLd	 1850	//(internal1_m385_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m385_fef	 BUFFER[11947]	//(internal1_m385_fef) fef
#define idinternal1_m385_fef	 1851	//(internal1_m385_fef) fef
#define internal1_m422_DvUp0	 BUFFER[11948]	//(internal1_m422_DvUp0) - есть команда на движение вперёд
#define idinternal1_m422_DvUp0	 1852	//(internal1_m422_DvUp0) - есть команда на движение вперёд
#define internal1_m422_DvDw0	 BUFFER[11949]	//(internal1_m422_DvDw0) - есть команда на движение назад
#define idinternal1_m422_DvDw0	 1853	//(internal1_m422_DvDw0) - есть команда на движение назад
#define internal1_m422_FDvUp0	 BUFFER[11950]	//(internal1_m422_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m422_FDvUp0	 1854	//(internal1_m422_FDvUp0) - есть команда на движение вперёд
#define internal1_m422_FDvDw0	 BUFFER[11951]	//(internal1_m422_FDvDw0) - есть команда на движение назад
#define idinternal1_m422_FDvDw0	 1855	//(internal1_m422_FDvDw0) - есть команда на движение назад
#define internal1_m422_BlDv0	 BUFFER[11952]	//(internal1_m422_BlDv0) - была блокировка
#define idinternal1_m422_BlDv0	 1856	//(internal1_m422_BlDv0) - была блокировка
#define internal1_m422_Pkv0	 BUFFER[11953]	//(internal1_m422_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m422_Pkv0	 1857	//(internal1_m422_Pkv0) Pkv - передний конечный выключатель
#define internal1_m422_Pkav0	 BUFFER[11954]	//(internal1_m422_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m422_Pkav0	 1858	//(internal1_m422_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m422_Zkv0	 BUFFER[11955]	//(internal1_m422_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m422_Zkv0	 1859	//(internal1_m422_Zkv0) Zkv - задний конечный выключатель
#define internal1_m422_Zkav0	 BUFFER[11956]	//(internal1_m422_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m422_Zkav0	 1860	//(internal1_m422_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m422_txNm	 BUFFER[11957]	//(internal1_m422_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m422_txNm	 1861	//(internal1_m422_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m422_txSm	 BUFFER[11962]	//(internal1_m422_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m422_txSm	 1862	//(internal1_m422_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m422_txHr	 BUFFER[11967]	//(internal1_m422_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m422_txHr	 1863	//(internal1_m422_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m422_txLd	 BUFFER[11972]	//(internal1_m422_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m422_txLd	 1864	//(internal1_m422_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m422_fef	 BUFFER[11977]	//(internal1_m422_fef) fef
#define idinternal1_m422_fef	 1865	//(internal1_m422_fef) fef
#define internal1_m416_DvUp0	 BUFFER[11978]	//(internal1_m416_DvUp0) - есть команда на движение вперёд
#define idinternal1_m416_DvUp0	 1866	//(internal1_m416_DvUp0) - есть команда на движение вперёд
#define internal1_m416_DvDw0	 BUFFER[11979]	//(internal1_m416_DvDw0) - есть команда на движение назад
#define idinternal1_m416_DvDw0	 1867	//(internal1_m416_DvDw0) - есть команда на движение назад
#define internal1_m416_FDvUp0	 BUFFER[11980]	//(internal1_m416_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m416_FDvUp0	 1868	//(internal1_m416_FDvUp0) - есть команда на движение вперёд
#define internal1_m416_FDvDw0	 BUFFER[11981]	//(internal1_m416_FDvDw0) - есть команда на движение назад
#define idinternal1_m416_FDvDw0	 1869	//(internal1_m416_FDvDw0) - есть команда на движение назад
#define internal1_m416_BlDv0	 BUFFER[11982]	//(internal1_m416_BlDv0) - была блокировка
#define idinternal1_m416_BlDv0	 1870	//(internal1_m416_BlDv0) - была блокировка
#define internal1_m416_Pkv0	 BUFFER[11983]	//(internal1_m416_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m416_Pkv0	 1871	//(internal1_m416_Pkv0) Pkv - передний конечный выключатель
#define internal1_m416_Pkav0	 BUFFER[11984]	//(internal1_m416_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m416_Pkav0	 1872	//(internal1_m416_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m416_Zkv0	 BUFFER[11985]	//(internal1_m416_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m416_Zkv0	 1873	//(internal1_m416_Zkv0) Zkv - задний конечный выключатель
#define internal1_m416_Zkav0	 BUFFER[11986]	//(internal1_m416_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m416_Zkav0	 1874	//(internal1_m416_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m416_txNm	 BUFFER[11987]	//(internal1_m416_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m416_txNm	 1875	//(internal1_m416_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m416_txSm	 BUFFER[11992]	//(internal1_m416_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m416_txSm	 1876	//(internal1_m416_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m416_txHr	 BUFFER[11997]	//(internal1_m416_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m416_txHr	 1877	//(internal1_m416_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m416_txLd	 BUFFER[12002]	//(internal1_m416_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m416_txLd	 1878	//(internal1_m416_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m416_fef	 BUFFER[12007]	//(internal1_m416_fef) fef
#define idinternal1_m416_fef	 1879	//(internal1_m416_fef) fef
#define internal1_m822_q0	 BUFFER[12008]	//(internal1_m822_q0) q0 - внутренний параметр
#define idinternal1_m822_q0	 1880	//(internal1_m822_q0) q0 - внутренний параметр
#define internal1_m819_q0	 BUFFER[12010]	//(internal1_m819_q0) q0 - внутренний параметр
#define idinternal1_m819_q0	 1881	//(internal1_m819_q0) q0 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &R6IS32LDU},	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
	{ 2	,1	,1	, &R6IS42LDU},	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
	{ 3	,1	,1	, &R6IS41LDU},	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
	{ 4	,1	,1	, &R6IS52LDU},	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
	{ 5	,1	,1	, &R6IS51LDU},	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
	{ 6	,1	,1	, &R3IS11LDU},	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
	{ 7	,1	,1	, &R3IS21LDU},	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
	{ 8	,1	,1	, &R0AB03LDU},	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
	{ 9	,1	,1	, &R0AB05LDU},	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
	{ 10	,8	,1	, &R0VN11RZ1},	//( - , MDuBz1) Средняя мощность по BAZ1
	{ 11	,8	,1	, &R0VN11RZ2},	//( - , MDuBz2) Средняя мощность по BAZ2
	{ 12	,1	,1	, &A2AB15LDU},	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{ 13	,1	,1	, &B2AB15LDU},	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{ 14	,1	,1	, &R0AD21LDU},	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
	{ 15	,1	,1	, &R0VX02LDU},	//( - , DU) Импульс разрешен
	{ 16	,1	,1	, &R0EE03LDU},	//( - , DU) ВПИС ИС
	{ 17	,1	,1	, &R0AB07LDU},	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
	{ 18	,1	,1	, &R0AD16LDU},	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
	{ 19	,1	,1	, &C2MD31LP1},	//( - , DU) Кнопка СБРОС РБ
	{ 20	,3	,1	, &B6VS01IDU},	//( - , DU) Готовность к управлению БЗ2
	{ 21	,1	,1	, &R2AD20LDU},	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
	{ 22	,1	,1	, &R2AD10LDU},	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
	{ 23	,3	,1	, &B8VS01IDU},	//( - , DU) Готовность к управлению АЗ2
	{ 24	,1	,1	, &R0VZ71LZ2},	//(vds32:03 - K22VDSR, - ) Обобщенный сигнал АЗ 2 канала
	{ 25	,1	,1	, &R0VZ71LZ1},	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
	{ 26	,1	,1	, &R0VZ71LDU},	//( - , DU) Обобщенный сигнал АЗ
	{ 27	,1	,1	, &A2IS33LDU},	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
	{ 28	,1	,1	, &A3IS31LDU},	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
	{ 29	,1	,1	, &A3IS33LDU},	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
	{ 30	,1	,1	, &A3IS35LDU},	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
	{ 31	,1	,1	, &A4IS10LDU},	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
	{ 32	,1	,1	, &A1VN71LZ1},	//(vds32:02 - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{ 33	,1	,1	, &A1VN71LZ2},	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{ 34	,1	,1	, &A1AB19LDU},	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
	{ 35	,1	,1	, &R0AD14LZ1},	//(vds32:02 - K20VDSR, DU) Имитация срабатывания АЗ от II УР
	{ 36	,1	,1	, &R0AD14LZ2},	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
	{ 37	,1	,1	, &A3VZ13LZ2},	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{ 38	,1	,1	, &A3VZ13LZ1},	//(vds32:02 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{ 39	,1	,1	, &A3VZ15LZ1},	//(vds32:02 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{ 40	,1	,1	, &A3VZ15LZ2},	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{ 41	,1	,1	, &B2IS33LDU},	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
	{ 42	,1	,1	, &B3IS31LDU},	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
	{ 43	,1	,1	, &B3IS33LDU},	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
	{ 44	,1	,1	, &B3IS35LDU},	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
	{ 45	,1	,1	, &B4IS10LDU},	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
	{ 46	,1	,1	, &R6IS31LDU},	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
	{ 47	,1	,1	, &R0AB11LDU},	//( - , DU) Ошибка в заданной координате  ИС1
	{ 48	,1	,1	, &R0AB12LDU},	//( - , DU) Ошибка в заданной координате  ИС2
	{ 49	,1	,1	, &R0AB13LDU},	//( - , DU) Ошибка в заданной координате  АЗ2
	{ 50	,1	,1	, &A4ZAV},	//( - , DU) 
	{ 51	,1	,1	, &A6ZAV},	//( - , DU) 
	{ 52	,1	,1	, &R2ZAV},	//( - , DU) 
	{ 53	,1	,1	, &A5ZAV},	//( - , DU) 
	{ 54	,1	,1	, &B8ZAV},	//( - , DU) 
	{ 55	,1	,1	, &A2ZAV},	//( - , DU) Завершение РБ1,2
	{ 56	,1	,1	, &A8ZAV},	//( - , DU) 
	{ 57	,1	,1	, &A9ZAV},	//( - , DU) Завершение НИ ДС1(2)
	{ 58	,1	,1	, &R4ABL},	//( - , DU) Блокировка тележки -
	{ 59	,1	,1	, &A4UP},	//( - , DU) 
	{ 60	,1	,1	, &A4DW},	//( - , DU) 
	{ 61	,1	,1	, &R0AB14LDU},	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
	{ 62	,1	,1	, &R0AB15LDU},	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
	{ 63	,1	,1	, &A3IS12LDU},	//( - , DU) Приход на ВУ штока ИС1
	{ 64	,1	,1	, &B3IS12LDU},	//( - , DU) Приход на ВУ штока ИС2
	{ 65	,1	,1	, &A1ZAV},	//( - , DU) 
	{ 66	,1	,1	, &A3ZAV},	//( - , DU) 
	{ 67	,1	,1	, &B1AB19LDU},	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
	{ 68	,1	,1	, &R0AB16LDU},	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
	{ 69	,1	,1	, &R0AB17LDU},	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
	{ 70	,3	,1	, &A8VS01IDU},	//( - , DU) Готовность к управлению ДС2
	{ 71	,1	,1	, &A1IE03LDU},	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
	{ 72	,1	,1	, &A1IE04LDU},	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
	{ 73	,1	,1	, &A2IE03LDU},	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
	{ 74	,1	,1	, &A2IE04LDU},	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
	{ 75	,1	,1	, &A3IE03LDU},	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
	{ 76	,1	,1	, &A3IE04LDU},	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
	{ 77	,1	,1	, &B1IE03LDU},	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
	{ 78	,1	,1	, &B1IE04LDU},	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
	{ 79	,1	,1	, &B2IE03LDU},	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
	{ 80	,1	,1	, &B2IE04LDU},	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
	{ 81	,1	,1	, &B3IE03LDU},	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
	{ 82	,1	,1	, &B3IE04LDU},	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
	{ 83	,1	,1	, &R0VS11LDU},	//( - , DU) РУ не готова к работе
	{ 84	,1	,1	, &B6AB05LDU},	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
	{ 85	,1	,1	, &R0AB08LDU},	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
	{ 86	,8	,1	, &A1MC01RP1},	//( - , DU) Заданная координата положения ББ1 мм
	{ 87	,8	,1	, &B1MC01RP1},	//( - , DU) Заданная координата положения ББ2  мм
	{ 88	,8	,1	, &A3MC01RP1},	//( - , DU) Заданная координата положения ИС1 мм
	{ 89	,8	,1	, &B3MC01RP1},	//( - , DU) Заданная координата положения ИС2 мм
	{ 90	,8	,1	, &B8MC01RP2},	//( - , DU) Заданная координата АЗ2 мм
	{ 91	,1	,1	, &R0AB09LDU},	//( - , DU) Ошибка в заданной координате ББ1
	{ 92	,1	,1	, &R0AB10LDU},	//( - , DU) Ошибка в заданной координате ББ2
	{ 93	,1	,1	, &B9IS21LDU},	//(vds32:02 - K26VDSR, - ) Приход на НУ НИ ДС2
	{ 94	,1	,1	, &B9AD10LDU},	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
	{ 95	,1	,1	, &A9AD10LDU},	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
	{ 96	,1	,1	, &A9AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ ДС1
	{ 97	,1	,1	, &A9AB01LDU},	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
	{ 98	,1	,1	, &A9AB02LDU},	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
	{ 99	,1	,1	, &B9AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ ДС2
	{ 100	,1	,1	, &B9AB01LDU},	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
	{ 101	,1	,1	, &B9AB02LDU},	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
	{ 102	,1	,1	, &R0AB01LDU},	//( - , DU) Режим проверки разрешён
	{ 103	,1	,1	, &A3IS22LDU},	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
	{ 104	,1	,1	, &B3IS22LDU},	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
	{ 105	,1	,1	, &A2AD33LDU},	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
	{ 106	,1	,1	, &B2AD33LDU},	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
	{ 107	,1	,1	, &A3AD33LDU},	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
	{ 108	,1	,1	, &A3AD34LDU},	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
	{ 109	,1	,1	, &A3AD31LDU},	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
	{ 110	,1	,1	, &B3AD34LDU},	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
	{ 111	,1	,1	, &B3AD31LDU},	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
	{ 112	,1	,1	, &A2IS11LDU},	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
	{ 113	,1	,1	, &B2IS11LDU},	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
	{ 114	,1	,1	, &A3MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
	{ 115	,1	,1	, &A3MD11LP1},	//( - , DU) Кнопка ПУСК ИС1
	{ 116	,3	,1	, &R0VL21IDU},	//( - , DU) Декатрон
	{ 117	,1	,1	, &R0VX03LDU},	//( - , DU) Готовность 2 мин
	{ 118	,3	,1	, &R0VS21IDU},	//( - , DU) Индикация ВИД ПРОВЕРКИ
	{ 119	,3	,1	, &A1VS01IDU},	//( - , DU) Готовность к управлению ББ1
	{ 120	,3	,1	, &B1VS01IDU},	//( - , DU) Готовность к управлению ББ2
	{ 121	,3	,1	, &A3VS01IDU},	//( - , DU) Готовность к управлению ИС1
	{ 122	,3	,1	, &B3VS01IDU},	//( - , DU) Готовность к управлению ИС2
	{ 123	,3	,1	, &A2VS01IDU},	//( - , DU) Готовность к управлению РБ1
	{ 124	,3	,1	, &A4VS01IDU},	//( - , DU) Готовность к управлению НИ1
	{ 125	,1	,1	, &A4VS12LDU},	//( - , DU) Движение НИ1 в сторону ВУ
	{ 126	,1	,1	, &A4VS22LDU},	//( - , DU) Движение НИ1 в сторону НУ
	{ 127	,3	,1	, &B4VS01IDU},	//( - , DU) Готовность к управлению НИ2
	{ 128	,1	,1	, &B4VS12LDU},	//( - , DU) Движение НИ2 в сторону ВУ
	{ 129	,1	,1	, &B4VS22LDU},	//( - , DU) Движение НИ2 в сторону НУ
	{ 130	,3	,1	, &A5VS01IDU},	//( - , DU) Готовность к управлению НЛ1
	{ 131	,3	,1	, &B5VS01IDU},	//( - , DU) Готовность к управлению НЛ2
	{ 132	,3	,1	, &A6VS01IDU},	//( - , DU) Готовность к управлению БЗ1
	{ 133	,3	,1	, &R4VS01IDU},	//( - , DU) Готовность к управлению тележкой реактора
	{ 134	,3	,1	, &R2VS01IDU},	//( - , DU) Готовность к управлению МДЗ2
	{ 135	,3	,1	, &R1VS01IDU},	//( - , DU) Готовность к управлению МДЗ1
	{ 136	,1	,1	, &A9IS11LDU},	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
	{ 137	,1	,1	, &A9IS21LDU},	//(vds32:02 - K24VDSR, - ) Приход на НУ НИ ДС1
	{ 138	,1	,1	, &B9IS11LDU},	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
	{ 139	,1	,1	, &A2MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
	{ 140	,1	,1	, &B3IS11LDU},	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
	{ 141	,1	,1	, &A3IS11LDU},	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
	{ 142	,1	,1	, &R0IS01LDU},	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
	{ 143	,1	,1	, &R0IS02LDU},	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
	{ 144	,1	,1	, &R0VP73LZ1},	//( - , MDuBz1) ПС давления для РУ
	{ 145	,1	,1	, &R0VP73LZ2},	//( - , MDuBz2) ПС давления для РУ
	{ 146	,1	,1	, &R0VP73LDU},	//( - , DU) ПС давления для РУ
	{ 147	,1	,1	, &R0MD34LP1},	//( - , DU) Кнопка КВИТИРОВАТЬ
	{ 148	,1	,1	, &A0VT71LZ1},	//( - , MDuBz1) АС по температуре в АЗ1
	{ 149	,1	,1	, &B0VT71LZ1},	//( - , MDuBz1) АС по температуре в АЗ2
	{ 150	,1	,1	, &A0VT71LZ2},	//( - , MDuBz2) АС по температуре в АЗ1
	{ 151	,1	,1	, &B0VT71LZ2},	//( - , MDuBz2) АС по температуре в АЗ2
	{ 152	,1	,1	, &B2VS11LDU},	//( - , DU) Движение РБ2 в сторону ВУ
	{ 153	,1	,1	, &B2VS21LDU},	//( - , DU) Движение РБ2 в сторону НУ
	{ 154	,3	,1	, &B2VS01IDU},	//( - , DU) Готовность к управлению РБ2
	{ 155	,1	,1	, &A7AS31LDU},	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
	{ 156	,1	,1	, &B7AS31LDU},	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
	{ 157	,1	,1	, &A7AZ03LDU},	//( - , DU) Несанкционированное включение обдува АЗ1
	{ 158	,1	,1	, &B7AZ03LDU},	//( - , DU) Несанкционированное включение обдува АЗ2
	{ 159	,1	,1	, &B3MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
	{ 160	,1	,1	, &B3MD11LP1},	//( - , DU) Кнопка ПУСК ИС2
	{ 161	,8	,1	, &R0VL01RDU},	//( - , DU) Индикация Время задержки
	{ 162	,1	,1	, &R0MD33LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
	{ 163	,1	,1	, &A1MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
	{ 164	,1	,1	, &A1MD11LP1},	//( - , DU) Кнопка ПУСК ББ1
	{ 165	,3	,1	, &R0MW14IP2},	//( - , DU) Переключатель ОБДУВ
	{ 166	,1	,1	, &A7AP31LDU},	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
	{ 167	,1	,1	, &B7AP31LDU},	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
	{ 168	,3	,1	, &R0MW12IP2},	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
	{ 169	,1	,1	, &R0MW17LP1},	//( - , DU) Переключатель АВТ/Р
	{ 170	,1	,1	, &R0VW13LDU},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
	{ 171	,1	,1	, &R0VW23LDU},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
	{ 172	,3	,1	, &R0VX08IDU},	//( - , DU) Индикация Режим
	{ 173	,1	,1	, &R0VX09LDU},	//( - , DU) Индикация регулятор мощности включен/отключен
	{ 174	,1	,1	, &R0VS17LDU},	//( - , DU) Индикация выбора АВТОМАТ
	{ 175	,1	,1	, &A2VS32LDU},	//( - , DU) Индикация  СБРОС РБ1
	{ 176	,1	,1	, &B2VS32LDU},	//( - , DU) Индикация  СБРОС РБ2
	{ 177	,1	,1	, &A3VX01LDU},	//( - , DU) Индикация Выстрел ИС1
	{ 178	,1	,1	, &B3VX01LDU},	//( - , DU) Индикация Выстрел ИС2
	{ 179	,1	,1	, &R0VS18LDU},	//( - , DU) Индикация  Проверка схем сброса
	{ 180	,1	,1	, &B1MD11LP1},	//( - , DU) Кнопка ПУСК ББ2
	{ 181	,1	,1	, &B1MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
	{ 182	,1	,1	, &B2MD11LP1},	//( - , DU) Кнопка ПУСК РБ2
	{ 183	,1	,1	, &B2MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
	{ 184	,1	,1	, &A2MD11LP1},	//( - , DU) Кнопка ПУСК РБ1
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
	{ 277	,1	,1	, &R0AD05LZ2},	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
	{ 278	,1	,1	, &B8IS12LDU},	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
	{ 279	,1	,1	, &B8IS21LDU},	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
	{ 280	,1	,1	, &A1VP41LZ1},	//( - , MDuBz1) Давление СБРОС ББ1 ниже АС
	{ 281	,1	,1	, &A1VP41LZ2},	//( - , MDuBz2) Давление СБРОС ББ1 ниже АС
	{ 282	,1	,1	, &R0VL22LDU},	//( - , DU) Конец программы 200сек
	{ 283	,1	,1	, &R0VL23LDU},	//( - , DU) Конец программы 20мин
	{ 284	,1	,1	, &B1VP41LZ1},	//( - , MDuBz1) Давление СБРОС ББ2 ниже АС
	{ 285	,1	,1	, &B1VP41LZ2},	//( - , MDuBz2) Давление СБРОС ББ2 ниже АС
	{ 286	,1	,1	, &A3AB19LDU},	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
	{ 287	,1	,1	, &B3AB19LDU},	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
	{ 288	,1	,1	, &A3EE03LDU},	//( - , DU) ВПИС ИС1
	{ 289	,1	,1	, &B3EE03LDU},	//( - , DU) ВПИС ИС2
	{ 290	,1	,1	, &B3AB15LDU},	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
	{ 291	,1	,1	, &R5IS21LDU},	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
	{ 292	,1	,1	, &R5VS22LDU},	//( - , DU) Движение ворот отстойной зоны к закрыты
	{ 293	,1	,1	, &R5VS12LDU},	//( - , DU) Движение ворот отстойной зоны к открыты
	{ 294	,3	,1	, &R5VS01IDU},	//( - , DU) Готовность к управлению ворот отстойной зоны
	{ 295	,1	,1	, &R3VS22LDU},	//( - , DU) Движение гомогенных дверей к закрыты
	{ 296	,1	,1	, &R3VS12LDU},	//( - , DU) Движение гомогенных дверей к открыты
	{ 297	,3	,1	, &R3VS01IDU},	//( - , DU) Готовность к управлению гомогенных дверей
	{ 298	,1	,1	, &A3AB13LDU},	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
	{ 299	,1	,1	, &B3AB13LDU},	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
	{ 300	,1	,1	, &R0AB18LDU},	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
	{ 301	,8	,1	, &A0CT01IZ1},	//( - , MDuBz1) Температура АЗ1-1
	{ 302	,8	,1	, &B0CT01IZ1},	//( - , MDuBz1) Температура АЗ2-1
	{ 303	,8	,1	, &A0CT01IZ2},	//( - , MDuBz2) Температура АЗ1-2
	{ 304	,8	,1	, &B0CT01IZ2},	//( - , MDuBz2) Температура АЗ2-2
	{ 305	,8	,1	, &A3MC01RDU},	//( - , DU) Заданная координата положения ИС от регулятора мм
	{ 306	,8	,1	, &A3MC02RDU},	//( - , DU) Температурная корректировка координаты ИМ
	{ 307	,8	,1	, &R0CN91LDU},	//( - , DU) Рассчётная реактивность от регулятора
	{ 308	,8	,1	, &A3MC03RDU},	//( - , DU) Координата положения ИМ 0-й реактивности
	{ 309	,1	,1	, &A3AB15LDU},	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
	{ 310	,1	,1	, &R0AB20LDU},	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
	{ 311	,8	,1	, &R0CN92LDU},	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
	{ 312	,8	,1	, &R0VN11RDU},	//( - , DU) Текущая мощность РУ
	{ 313	,8	,1	, &R0VN12RDU},	//( - , DU) Заданная мощность РУ
	{ 314	,1	,1	, &R0AB19LDU},	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
	{ 315	,8	,1	, &R0CN93LDU},	//( - , DU) время работы на мощности более 100Вт, сек
	{ 316	,8	,1	, &R0CN94LDU},	//( - , DU) Скорость изменения мощности
	{ 317	,3	,1	, &R0CN95LDU},	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
	{ 318	,1	,1	, &R0AD03LZ1},	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
	{ 319	,1	,1	, &R0AD03LZ2},	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
	{ 320	,1	,1	, &R0AD04LZ1},	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
	{ 321	,1	,1	, &R0AD04LZ2},	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
	{ 322	,1	,1	, &R0AD05LZ1},	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
	{ 323	,1	,1	, &R0DEB1LDU},	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
	{ 324	,1	,1	, &R0DEB4LDU},	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
	{ 325	,1	,1	, &R0DE3DLDU},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
	{ 326	,1	,1	, &R0DE3CLDU},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
	{ 327	,1	,1	, &TestDiagnDU},	//( - , DU) Неисправность от
	{ 328	,8	,1	, &B3CV01RDU},	//( - , DU) Измеренная скорость перемещения ИС2
	{ 329	,3	,1	, &R0DE01LDU},	//(vencf8l:01 - DiagnVDS, DiagnDU) диагностика модуля ДУ на 1 месте
	{ 330	,3	,1	, &R0DE06LDU},	//(vencf8l:01 - DiagnFDS, DiagnDU) диагностика модуля ДУ на 6 месте
	{ 331	,5	,1	, &venc01},	//(vencf8l:01 - venc01, - ) заначение реального энкодера ББ1
	{ 332	,5	,1	, &venc02},	//(vencf8l:01 - venc02, - ) заначение реального энкодера РБ1
	{ 333	,5	,1	, &venc03},	//(vencf8l:01 - venc03, - ) заначение реального энкодера Ис1
	{ 334	,5	,1	, &venc04},	//(vencf8l:01 - venc04, - ) заначение реального энкодера ДС1
	{ 335	,5	,1	, &venc05},	//(vencf8l:01 - venc05, - ) заначение реального энкодера ББ2
	{ 336	,5	,1	, &venc06},	//(vencf8l:01 - venc06, - ) заначение реального энкодера РБ2
	{ 337	,5	,1	, &venc07},	//(vencf8l:01 - venc07, - ) заначение реального энкодера ИС2
	{ 338	,5	,1	, &venc08},	//(vencf8l:01 - venc08, - ) заначение реального энкодера АЗ2
	{ 339	,8	,1	, &R0VN15RDU},	//( - , DU) Период разгона РУ
	{ 340	,1	,1	, &R8AD21LDU},	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
	{ 341	,1	,1	, &R8AD22LDU},	//(vds32:02 - K15VDSR, - ) Сигнал синхронизации с импульсом
	{ 342	,5	,1	, &B1IC01UDU},	//( - , MDuS) Координата штока ББ2 (дел.энк)
	{ 343	,8	,1	, &B1VC01RDU},	//( - , DU) Координата ББ2, мм
	{ 344	,1	,1	, &B1IS11LDU},	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
	{ 345	,5	,1	, &A2IC01UDU},	//( - , MDuS) Координата штока РБ1 (дел.энк)
	{ 346	,3	,1	, &R0DE02LDU},	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
	{ 347	,3	,1	, &R0DE03LDU},	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
	{ 348	,3	,1	, &R0DE04LDU},	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
	{ 349	,3	,1	, &R0DE08LDU},	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
	{ 350	,3	,1	, &R0DE05LDU},	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
	{ 351	,3	,1	, &R0DE09LDU},	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
	{ 352	,3	,1	, &R0DE0ALDU},	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
	{ 353	,3	,1	, &R0DE07LDU},	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
	{ 354	,3	,1	, &R0DE0CLDU},	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
	{ 355	,3	,1	, &R0DE0BLDU},	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
	{ 356	,3	,1	, &R0DE0DLDU},	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
	{ 357	,3	,1	, &R0DE0FLDU},	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
	{ 358	,1	,1	, &R0DE31LDU},	//(sbk:20 - S01SBK, DiagnDU) диагностика шкафа ДУ сеть 1
	{ 359	,3	,1	, &TTLDU},	//( - , DU) ttl
	{ 360	,1	,1	, &R0DE32LDU},	//(sbk:20 - S02SBK, DiagnDU) диагностика шкафа ДУ сеть 2
	{ 361	,1	,1	, &R0DE33LDU},	//(sbk:20 - S03SBK, DiagnDU) диагностика шкафа ДУ двери
	{ 362	,1	,1	, &R0DE34LDU},	//(sbk:20 - S04SBK, DiagnDU) диагностика шкафа ДУ температура меньше 43
	{ 363	,1	,1	, &R0DE35LDU},	//(sbk:20 - S05SBK, DiagnDU) диагностика шкафа ДУ температура больше 53
	{ 364	,1	,1	, &R0DE36LDU},	//(sbk:20 - S06SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 1
	{ 365	,1	,1	, &R0DE37LDU},	//(sbk:20 - S07SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 2
	{ 366	,1	,1	, &R0DE38LDU},	//(sbk:20 - S08SBK, DiagnDU) диагностика шкафа ДУ МП15-3 место 3
	{ 367	,1	,1	, &R0DE39LDU},	//(sbk:20 - S09SBK, DiagnDU) диагностика шкафа ДУ МП24-2 место 4
	{ 368	,1	,1	, &R0DEB3LDU},	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
	{ 369	,1	,1	, &R0DEB2LDU},	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
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
	{ 392	,1	,1	, &B8AB09LDU},	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
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
	{ 415	,1	,1	, &A6AB06LDU},	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
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
	{ 438	,1	,1	, &A2AB09LDU},	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
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
	{ 461	,1	,1	, &A8AB11LDU},	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
	{ 462	,1	,1	, &B6IS21LDU},	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
	{ 463	,1	,1	, &A6VS22LDU},	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
	{ 464	,1	,1	, &A6VS12LDU},	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
	{ 465	,1	,1	, &B6VS22LDU},	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
	{ 466	,1	,1	, &B6VS12LDU},	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
	{ 467	,1	,1	, &A6AD10LDU},	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
	{ 468	,1	,1	, &A6AD20LDU},	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
	{ 469	,1	,1	, &B6AD10LDU},	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
	{ 470	,1	,1	, &B6AD20LDU},	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
	{ 471	,1	,1	, &A6AZ03LDU},	//( - , DU) Несанкционированное перемещение БЗ1
	{ 472	,1	,1	, &A6AB01LDU},	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
	{ 473	,1	,1	, &A6AB02LDU},	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
	{ 474	,1	,1	, &B6AZ03LDU},	//( - , DU) Несанкционированное перемещение БЗ2
	{ 475	,1	,1	, &B6AB01LDU},	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
	{ 476	,1	,1	, &B6AB02LDU},	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
	{ 477	,1	,1	, &A6AB04LDU},	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
	{ 478	,1	,1	, &B6AB04LDU},	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
	{ 479	,1	,1	, &R4AB01LDU},	//( - , DU) Блокировка движения тележки - АНИ не установлен
	{ 480	,1	,1	, &R8IS11LDU},	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
	{ 481	,1	,1	, &R6IS21LDU},	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
	{ 482	,1	,1	, &A0VN71LZ2},	//( - , MDuBz2) АЗ по АС мощности для АЗ1
	{ 483	,1	,1	, &A0VN71LZ1},	//( - , MDuBz1) АЗ по АС мощности для АЗ1
	{ 484	,1	,1	, &R0NE01LDU},	//( - , DU) Потеря связи с БАЗ1
	{ 485	,3	,1	, &R0MW15IP1},	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
	{ 486	,3	,1	, &R0MW14IP1},	//( - , DU) Переключатель ПРОГРАММЫ
	{ 487	,3	,1	, &R0MW12IP1},	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
	{ 488	,3	,1	, &R0MW13IP1},	//( - , DU) Переключатель ВЫБОР ЗОН
	{ 489	,3	,1	, &R0MW16IP1},	//( - , DU) Переключатель ВИД ПРОВЕРКИ
	{ 490	,3	,1	, &R0MW11IP1},	//( - , DU) Переключатель ВЫСТРЕЛ
	{ 491	,3	,1	, &R0MW11IP2},	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
	{ 492	,1	,1	, &R0MW13LP2},	//( - , DU) Переключатель СЕТЬ
	{ 493	,1	,1	, &R0MD32LP1},	//( - , DU) Кнопка СПУСК
	{ 494	,1	,1	, &R0MD31LP1},	//( - , DU) Кнопка СТОП
	{ 495	,1	,1	, &A1IS21LDU},	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
	{ 496	,1	,1	, &A2IS21LDU},	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
	{ 497	,1	,1	, &A3IS21LDU},	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
	{ 498	,1	,1	, &B1IS21LDU},	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
	{ 499	,1	,1	, &B2IS21LDU},	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
	{ 500	,1	,1	, &B3IS21LDU},	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
	{ 501	,1	,1	, &R0ES01LDU},	//( - , DU) ОРР не в исходном состоянии
	{ 502	,1	,1	, &R4MD11LP2},	//( - , DU) Кнопка ВПЕРЁД  (тележки)
	{ 503	,1	,1	, &R4MD31LP2},	//( - , DU) Кнопка СТОП  (тележки)
	{ 504	,1	,1	, &R4MD21LP2},	//( - , DU) Кнопка НАЗАД  (тележки)
	{ 505	,1	,1	, &A6IS11LDU},	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
	{ 506	,1	,1	, &A6IS21LDU},	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
	{ 507	,1	,1	, &B6IS11LDU},	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
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
	{ 530	,1	,1	, &A5AZ03LDU},	//( - , DU) Несанкционированное перемещение НЛ1
	{ 531	,1	,1	, &R0NE02LDU},	//( - , DU) Потеря связи с БАЗ2
	{ 532	,1	,1	, &R4AB02LDU},	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
	{ 533	,1	,1	, &R0NE08LDU},	//( - , DU) Потеря связи с ОПУ
	{ 534	,1	,1	, &R4IS21LDU},	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
	{ 535	,1	,1	, &R4IS22LDU},	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
	{ 536	,1	,1	, &R4IS12LDU},	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
	{ 537	,1	,1	, &R4VS22LDU},	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
	{ 538	,1	,1	, &R4VS12LDU},	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
	{ 539	,1	,1	, &R4AZ03LDU},	//( - , DU) Несанкционированное перемещение тележки
	{ 540	,1	,1	, &R4AB03LDU},	//( - , DU) Блокировка движения тележки - Самоход любого механизма
	{ 541	,1	,1	, &R1IS21LDU},	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
	{ 542	,1	,1	, &R2IS21LDU},	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
	{ 543	,1	,1	, &R4AB04LDU},	//( - , DU) Блокировка движения тележки - Превышение времени движения
	{ 544	,1	,1	, &R4AB05LDU},	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
	{ 545	,1	,1	, &R4AB06LDU},	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
	{ 546	,1	,1	, &R4AB07LDU},	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
	{ 547	,1	,1	, &R4AB08LDU},	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
	{ 548	,1	,1	, &R4AB09LDU},	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
	{ 549	,1	,1	, &B0VN71LZ1},	//( - , MDuBz1) АЗ по АС мощности для АЗ2
	{ 550	,1	,1	, &B0VN71LZ2},	//( - , MDuBz2) АЗ по АС мощности для АЗ2
	{ 551	,1	,1	, &R4AB10LDU},	//( - , DU) Блокировка тележки - не открыта биологическая защита
	{ 552	,1	,1	, &R4AB11LDU},	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
	{ 553	,1	,1	, &R4AB12LDU},	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
	{ 554	,1	,1	, &A4IS11LDU},	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
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
	{ 574	,1	,1	, &B3AB04LDU},	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
	{ 575	,1	,1	, &B3AB02LDU},	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
	{ 576	,1	,1	, &B3AB01LDU},	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
	{ 577	,1	,1	, &B3VS22LDU},	//( - , DU) Движение ИС2 в сторону НУ
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
	{ 599	,1	,1	, &A3AD21LDU},	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
	{ 600	,1	,1	, &A3AD02LDU},	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
	{ 601	,1	,1	, &C1MD31LP2},	//( - , DU) Кнопка СБРОС ББ
	{ 602	,1	,1	, &A2AD31LDU},	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
	{ 603	,1	,1	, &B2AD31LDU},	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
	{ 604	,1	,1	, &A1AD31LDU},	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
	{ 605	,1	,1	, &B1AD31LDU},	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
	{ 606	,1	,1	, &A2AD32LDU},	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
	{ 607	,1	,1	, &B2AD32LDU},	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
	{ 608	,1	,1	, &A1AD32LDU},	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
	{ 609	,1	,1	, &B1AD32LDU},	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
	{ 610	,1	,1	, &R0MD11LP2},	//( - , DU) Кнопка Пуск проверки схем сброса
	{ 611	,1	,1	, &R0VX01LDU},	//( - , DU) ДО ИМПУЛЬСА
	{ 612	,3	,1	, &R0VL01IDU},	//( - , DU) До импульса минут
	{ 613	,3	,1	, &R0VL11IDU},	//( - , DU) До импульса секунд
	{ 614	,8	,1	, &R0VL06RDU},	//( - , DU) Индикация (Время задержки от ВУ РБ)
	{ 615	,1	,1	, &B3AD33LDU},	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
	{ 616	,8	,1	, &R0VL02RDU},	//( - , DU) Индикация (Время задержки ИНИ)
	{ 617	,1	,1	, &R0AD14LDU},	//( - , DU) Имитация срабатывания верхней АС II УР
	{ 618	,8	,1	, &R0VL04RDU},	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
	{ 619	,1	,1	, &R0AB04LDU},	//( - , DU) Нарушение времени срабатывания верхней АС II УР
	{ 620	,1	,1	, &R0AB06LDU},	//( - , DU) Нарушение времени задержки от ВУ РБ
	{ 621	,1	,1	, &R0AB02LDU},	//( - , DU) Нарушение времени задержки ИНИ
	{ 622	,8	,1	, &R0VL03RDU},	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
	{ 623	,8	,1	, &R0VL05RDU},	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
	{ 624	,1	,1	, &B3AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
	{ 625	,1	,1	, &B3AD11LDU},	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
	{ 626	,1	,1	, &B3AD21LDU},	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
	{ 627	,1	,1	, &B3AD02LDU},	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
	{ 628	,1	,1	, &B3AD03LDU},	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
	{ 629	,1	,1	, &B3AD04LDU},	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
	{ 630	,1	,1	, &B3AD05LDU},	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
	{ 631	,1	,1	, &B3AD01LDU},	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
	{ 632	,8	,1	, &B3CV02RDU},	//( - , DU) Заданная скорость перемещения ИС2
	{ 633	,1	,1	, &B3AB07LDU},	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
	{ 634	,1	,1	, &B3AB08LDU},	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
	{ 635	,1	,1	, &B3AB05LDU},	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
	{ 636	,1	,1	, &B3AB06LDU},	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
	{ 637	,1	,1	, &B3AB09LDU},	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
	{ 638	,1	,1	, &B3AB10LDU},	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
	{ 639	,1	,1	, &B3AB11LDU},	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
	{ 640	,1	,1	, &B3AB12LDU},	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{ 641	,1	,1	, &B3AB14LDU},	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
	{ 642	,1	,1	, &B3AB16LDU},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
	{ 643	,1	,1	, &B3AB17LDU},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
	{ 644	,1	,1	, &B3AB18LDU},	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
	{ 645	,1	,1	, &B3AB20LDU},	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
	{ 646	,1	,1	, &C1MD31LP1},	//( - , DU) Кнопка СБРОС ББ
	{ 647	,1	,1	, &B2AB08LDU},	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
	{ 648	,1	,1	, &B2AB05LDU},	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
	{ 649	,1	,1	, &B2AB06LDU},	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
	{ 650	,1	,1	, &B2AB09LDU},	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
	{ 651	,1	,1	, &B2AB10LDU},	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
	{ 652	,1	,1	, &B2AB11LDU},	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
	{ 653	,1	,1	, &B2AB12LDU},	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{ 654	,1	,1	, &B2AB13LDU},	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
	{ 655	,1	,1	, &B2AB14LDU},	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
	{ 656	,1	,1	, &B2AB16LDU},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
	{ 657	,1	,1	, &B2AB17LDU},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
	{ 658	,1	,1	, &R1AZ03LDU},	//( - , DU) Несанкционированное перемещение МДЗ1
	{ 659	,1	,1	, &R1AB01LDU},	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
	{ 660	,1	,1	, &R1AB02LDU},	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
	{ 661	,1	,1	, &R2AZ03LDU},	//( - , DU) Несанкционированное перемещение МДЗ2
	{ 662	,1	,1	, &R2AB01LDU},	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
	{ 663	,1	,1	, &R2AB02LDU},	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
	{ 664	,1	,1	, &R1AB04LDU},	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
	{ 665	,1	,1	, &R2AB04LDU},	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
	{ 666	,1	,1	, &R1AD10LDU},	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
	{ 667	,1	,1	, &R1AD20LDU},	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
	{ 668	,1	,1	, &R1IS11LDU},	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
	{ 669	,1	,1	, &R1VS22LDU},	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
	{ 670	,1	,1	, &A2AB10LDU},	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
	{ 671	,1	,1	, &A2AB11LDU},	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
	{ 672	,1	,1	, &A2AB12LDU},	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 673	,1	,1	, &A2AB13LDU},	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
	{ 674	,1	,1	, &A2AB14LDU},	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
	{ 675	,1	,1	, &A2AB16LDU},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
	{ 676	,1	,1	, &A2AB17LDU},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
	{ 677	,1	,1	, &A2AD01LDU},	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
	{ 678	,8	,1	, &A2CV02RDU},	//( - , DU) Заданная скорость перемещения РБ1
	{ 679	,8	,1	, &B2CV01RDU},	//( - , DU) Измеренная скорость перемещения РБ2
	{ 680	,1	,1	, &B2AB04LDU},	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
	{ 681	,1	,1	, &B2AB02LDU},	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
	{ 682	,1	,1	, &B2AB01LDU},	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
	{ 683	,1	,1	, &B2AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
	{ 684	,1	,1	, &B2AD11LDU},	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
	{ 685	,1	,1	, &B2AD21LDU},	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
	{ 686	,1	,1	, &B2AD02LDU},	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
	{ 687	,1	,1	, &B2AD03LDU},	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
	{ 688	,1	,1	, &B2AD04LDU},	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
	{ 689	,1	,1	, &B2AD05LDU},	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
	{ 690	,1	,1	, &B2AD01LDU},	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
	{ 691	,8	,1	, &B2CV02RDU},	//( - , DU) Заданная скорость перемещения РБ2
	{ 692	,1	,1	, &B2AB07LDU},	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
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
	{ 714	,1	,1	, &B1AD01LDU},	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
	{ 715	,8	,1	, &B1CV02RDU},	//( - , DU) Заданная скорость перемещения ББ2
	{ 716	,1	,1	, &R2VS22LDU},	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
	{ 717	,1	,1	, &R2VS12LDU},	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
	{ 718	,1	,1	, &R1VS12LDU},	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
	{ 719	,1	,1	, &R2IS11LDU},	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
	{ 720	,1	,1	, &A1VS12LDU},	//( - , DU) Движение ББ1 в сторону ВУ
	{ 721	,8	,1	, &A1CV01RDU},	//( - , DU) Измеренная скорость перемещения ББ1
	{ 722	,1	,1	, &A1AB04LDU},	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
	{ 723	,1	,1	, &A1AB02LDU},	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
	{ 724	,1	,1	, &A1AB01LDU},	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
	{ 725	,1	,1	, &A1VS22LDU},	//( - , DU) Движение ББ1 в сторону НУ
	{ 726	,1	,1	, &A1AZ03LDU},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
	{ 727	,1	,1	, &A1AD11LDU},	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
	{ 728	,1	,1	, &A1AD21LDU},	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
	{ 729	,1	,1	, &A1AD02LDU},	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
	{ 730	,1	,1	, &A1AD03LDU},	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
	{ 731	,1	,1	, &A1AD04LDU},	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
	{ 732	,1	,1	, &A1AD05LDU},	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
	{ 733	,1	,1	, &A1AD01LDU},	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
	{ 734	,8	,1	, &A1CV02RDU},	//( - , DU) Заданная скорость перемещения ББ1
	{ 735	,1	,1	, &A1AB07LDU},	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
	{ 736	,1	,1	, &A1AB08LDU},	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
	{ 737	,1	,1	, &A1AB05LDU},	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
	{ 738	,1	,1	, &A1AB06LDU},	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
	{ 739	,1	,1	, &A1AB09LDU},	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
	{ 740	,8	,1	, &fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
	{ 741	,5	,1	, &dEM_A1UC05UDU},	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
	{ 742	,5	,1	, &dEM_A1UC06UDU},	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
	{ 743	,5	,1	, &dEM_A2UC06UDU},	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
	{ 744	,5	,1	, &dEM_A2UC05UDU},	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
	{ 745	,8	,1	, &fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
	{ 746	,5	,1	, &dEM_A3UC06UDU},	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
	{ 747	,5	,1	, &dEM_A3UC05UDU},	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
	{ 748	,8	,1	, &fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
	{ 749	,5	,1	, &dEM_A8UC06UDU},	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
	{ 750	,8	,1	, &fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
	{ 751	,5	,1	, &dEM_A8UC05UDU},	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
	{ 752	,8	,1	, &fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{ 753	,8	,1	, &fEM_R0UV82RDU},	//(R0UV82RDU) 2-я частота двигателя (шагов/секунду)
	{ 754	,8	,1	, &fEM_R0UV83RDU},	//(R0UV83RDU) 3-я частота двигателя (шагов/секунду)
	{ 755	,8	,1	, &fEM_R0UV84RDU},	//(R0UV84RDU) 4-я частота двигателя (шагов/секунду)
	{ 756	,8	,1	, &fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 757	,8	,1	, &fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{ 758	,8	,1	, &fEM_R0UV87RDU},	//(R0UV87RDU) 8-я скорость перемещения ББ (шагов/секунду)
	{ 759	,8	,1	, &fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{ 760	,8	,1	, &fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{ 761	,8	,1	, &fEM_A3UP43RDU},	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
	{ 762	,8	,1	, &fEM_A3UP44RDU},	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
	{ 763	,8	,1	, &fEM_A3UP53RDU},	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
	{ 764	,8	,1	, &fEM_A3UP85RDU},	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 765	,8	,1	, &fEM_A3UP88RDU},	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 766	,8	,1	, &fEM_A3UP86RDU},	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 767	,8	,1	, &fEM_B8UV01RDU},	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
	{ 768	,8	,1	, &fEM_B8UV02RDU},	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
	{ 769	,8	,1	, &fEM_B8UV03RDU},	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
	{ 770	,8	,1	, &fEM_B8UL04RDU},	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
	{ 771	,3	,1	, &iEM_A2UV03CDU},	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
	{ 772	,8	,1	, &fEM_A2UV01RDU},	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
	{ 773	,8	,1	, &fEM_A2UV02RDU},	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
	{ 774	,8	,1	, &fEM_A1UV01RDU},	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
	{ 775	,8	,1	, &fEM_A1UV02RDU},	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
	{ 776	,8	,1	, &fEM_A1UC06RDU},	//(A1UC06RDU) Уставка определения самохода ББ  мм
	{ 777	,8	,1	, &fEM_A1UC05RDU},	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
	{ 778	,8	,1	, &fEM_A1UL04RDU},	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
	{ 779	,8	,1	, &fEM_A3UV01RDU},	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
	{ 780	,8	,1	, &fEM_A3UV02RDU},	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
	{ 781	,8	,1	, &fEM_A3UC06RDU},	//(A3UC06RDU) Уставка определения самохода ИС1  мм
	{ 782	,8	,1	, &fEM_A3UC05RDU},	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
	{ 783	,8	,1	, &fEM_A3UL04RDU},	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
	{ 784	,8	,1	, &fEM_A3UP54RDU},	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
	{ 785	,8	,1	, &fEM_A3UP87RDU},	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 786	,8	,1	, &fEM_R0UL05RDU},	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
	{ 787	,8	,1	, &fEM_R0UL20RDU},	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
	{ 788	,8	,1	, &fEM_B8UV04RDU},	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
	{ 789	,8	,1	, &fEM_B8UC06RDU},	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
	{ 790	,8	,1	, &fEM_B8UC05RDU},	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
	{ 791	,8	,1	, &fEM_A2UL05RDU},	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
	{ 792	,8	,1	, &fEM_A2UL03RDU},	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{ 793	,8	,1	, &fEM_A2UC06RDU},	//(A2UC06RDU) Уставка определения самохода РБ  мм
	{ 794	,8	,1	, &fEM_A2UC05RDU},	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
	{ 795	,8	,1	, &fEM_A2UL04RDU},	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
	{ 796	,8	,1	, &fEM_A1UL03RDU},	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
	{ 797	,8	,1	, &fEM_A1UL05RDU},	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
	{ 798	,8	,1	, &fEM_A3UL03RDU},	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
	{ 799	,8	,1	, &fEM_A3UL05RDU},	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
	{ 800	,8	,1	, &fEM_A1UC08RDU},	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
	{ 801	,8	,1	, &fEM_A3UC08RDU},	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
	{ 802	,8	,1	, &fEM_A1UC07RDU},	//(A1UC07RDU) Зона возврата при наведении ББ мм
	{ 803	,8	,1	, &fEM_A1UL01RDU},	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 804	,8	,1	, &fEM_A3UC07RDU},	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
	{ 805	,8	,1	, &fEM_A3UL01RDU},	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 806	,8	,1	, &fEM_A2UC08RDU},	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
	{ 807	,8	,1	, &fEM_A2UC07RDU},	//(A2UC07RDU) Зона возврата при наведении РБ  мм
	{ 808	,8	,1	, &fEM_A2UL01RDU},	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 809	,8	,1	, &fEM_B8UC01RDU},	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
	{ 810	,8	,1	, &fEM_B8UL07RDU},	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
	{ 811	,8	,1	, &fEM_B8UC02RDU},	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
	{ 812	,8	,1	, &fEM_B8UL01RDU},	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 813	,8	,1	, &fEM_B8UL05RDU},	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
	{ 814	,8	,1	, &fEM_B8UL03RDU},	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
	{ 815	,8	,1	, &fEM_B8UL06RDU},	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
	{ 816	,8	,1	, &fEM_A9UZ03RDU},	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
	{ 817	,8	,1	, &fEM_A9UZ04RDU},	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
	{ 818	,8	,1	, &fEM_A9UZ05RDU},	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
	{ 819	,8	,1	, &fEM_R4UZ04RDU},	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
	{ 820	,8	,1	, &fEM_R4UZ03RDU},	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
	{ 821	,8	,1	, &fEM_R4UZ05RDU},	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
	{ 822	,8	,1	, &fEM_A5UZ03RDU},	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
	{ 823	,8	,1	, &fEM_A5UZ04RDU},	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
	{ 824	,8	,1	, &fEM_A5UZ05RDU},	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
	{ 825	,8	,1	, &fEM_A4UZ03RDU},	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
	{ 826	,8	,1	, &fEM_A4UZ04RDU},	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
	{ 827	,8	,1	, &fEM_A4UZ05RDU},	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
	{ 828	,8	,1	, &fEM_A6UZ03RDU},	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
	{ 829	,8	,1	, &fEM_A6UZ04RDU},	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
	{ 830	,8	,1	, &fEM_A6UZ05RDU},	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
	{ 831	,8	,1	, &fEM_R1UZ03RDU},	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
	{ 832	,8	,1	, &fEM_R1UZ04RDU},	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
	{ 833	,8	,1	, &fEM_R1UZ05RDU},	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
	{ 834	,8	,1	, &fEM_R0UL04RDU},	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
	{ 835	,8	,1	, &fEM_R0UL06RDU},	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
	{ 836	,8	,1	, &fEM_R0UL03RDU},	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
	{ 837	,8	,1	, &fEM_R0UL17RDU},	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
	{ 838	,8	,1	, &fEM_R0UL19RDU},	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{ 839	,8	,1	, &fEM_R0UL07RDU},	//(R0UL07RDU) Время срабатывания верхней АС II УР
	{ 840	,8	,1	, &fEM_R0UL18RDU},	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
	{ 841	,8	,1	, &fEM_R0UL16RDU},	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
	{ 842	,8	,1	, &fEM_R0UL02RDU},	//(R0UL02RDU) Время задержки  ИНИ
	{ 843	,8	,1	, &fEM_R0UN08RDU},	//(R0UN08RDU) 8-я заданная мощность
	{ 844	,8	,1	, &fEM_R0UN07RDU},	//(R0UN07RDU) 7-я заданная мощность
	{ 845	,8	,1	, &fEM_R0UN06RDU},	//(R0UN06RDU) 6-я заданная мощность
	{ 846	,8	,1	, &fEM_R0UN05RDU},	//(R0UN05RDU) 5-я заданная мощность
	{ 847	,8	,1	, &fEM_R0UN04RDU},	//(R0UN04RDU) 4-я заданная мощность
	{ 848	,8	,1	, &fEM_R0UN03RDU},	//(R0UN03RDU) Ограничение 3 по мощности
	{ 849	,8	,1	, &fEM_R0UN02RDU},	//(R0UN02RDU) 2-я заданная мощность
	{ 850	,8	,1	, &fEM_R0UN01RDU},	//(R0UN01RDU) 1-я заданная мощность
	{ 851	,8	,1	, &fEM_A2UC82RDU},	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
	{ 852	,8	,1	, &fEM_A2UC83RDU},	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
	{ 853	,8	,1	, &fEM_A1UC83RDU},	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
	{ 854	,8	,1	, &fEM_A2UC81RDU},	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
	{ 855	,8	,1	, &fEM_A1UC81RDU},	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
	{ 856	,8	,1	, &fEM_A1UC82RDU},	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
	{ 857	,8	,1	, &fEM_A2UL83RDU},	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{ 858	,8	,1	, &fEM_A3UC81RDU},	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
	{ 859	,8	,1	, &fEM_A3UC82RDU},	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
	{ 860	,8	,1	, &fEM_R0UN80RDU},	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
	{ 861	,3	,1	, &iEM_A2UV01IDU},	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
	{ 862	,3	,1	, &iEM_A2UV02IDU},	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
	{ 863	,3	,1	, &iEM_A1UV01IDU},	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
	{ 864	,3	,1	, &iEM_A1UV02IDU},	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
	{ 865	,3	,1	, &iEM_A1UV03IDU},	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
	{ 866	,3	,1	, &iEM_A3UV01IDU},	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
	{ 867	,3	,1	, &iEM_A3UV02IDU},	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
	{ 868	,1	,1	, &lEM_R0MD01LC1},	//(R0MD01LC1) Ручное управление ОРР
	{ 869	,8	,1	, &fEM_A3UC09RDU},	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
	{ 870	,8	,1	, &fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
	{ 871	,8	,1	, &fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
	{ 872	,8	,1	, &fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
	{ 873	,8	,1	, &fEM_R0UL21RDU},	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
	{ 874	,8	,1	, &fEM_R0UN09RDU},	//(R0UN09RDU) Минимальный период при регулировании мощности
	{ 875	,8	,1	, &fEM_R0UN11RDU},	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
	{ 876	,8	,1	, &fEM_R0UN12RDU},	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
	{ 877	,8	,1	, &fEM_R0UN13RDU},	//(R0UN13RDU) Минимальное изменение координаты, мм
	{ 878	,8	,1	, &fEM_R0UN14RDU},	//(R0UN14RDU) Максимальная координата штока ИМ, мм
	{ 879	,8	,1	, &fEM_R0UN16RDU},	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
	{ 880	,8	,1	, &fEM_R0UN17RDU},	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
	{ 881	,8	,1	, &fEM_R0UN18RDU},	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
	{ 882	,8	,1	, &fEM_R0UN19RDU},	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
	{ 883	,8	,1	, &fEM_R0UN70LDU},	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
	{ 884	,8	,1	, &fEM_R0UN71LDU},	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
	{ 885	,8	,1	, &fEM_R0UN72LDU},	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
	{ 886	,8	,1	, &fEM_R0UN73LDU},	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
	{ 887	,8	,1	, &fEM_R0UN74LDU},	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
	{ 888	,8	,1	, &fEM_R0UN75LDU},	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
	{ 889	,8	,1	, &fEM_R0UN80LDU},	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
	{ 890	,8	,1	, &fEM_R0UN81LDU},	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
	{ 891	,8	,1	, &fEM_R0UN82LDU},	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
	{ 892	,8	,1	, &fEM_R0UN83LDU},	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
	{ 893	,8	,1	, &fEM_R0UN84LDU},	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
	{ 894	,8	,1	, &fEM_R0UN85LDU},	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
	{ 895	,8	,1	, &fEM_R0UT20RDU},	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
	{ 896	,8	,1	, &fEM_R0UN25RDU},	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
	{ 897	,8	,1	, &fEM_R0UN15RDU},	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
	{ 898	,8	,1	, &fEM_R0UN26RDU},	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
	{ 899	,8	,1	, &fEM_R0UN27RDU},	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
	{ 900	,8	,1	, &fEM_R0UN24RDU},	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 901	,8	,1	, &fEM_R0UL25RDU},	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{ 902	,8	,1	, &fEM_R0UL01RSS},	//(R0UL01RSS) Шаг измерения периода (сек)
	{ 903	,8	,1	, &fEM_R0UL02RSS},	//(R0UL02RSS) Tф-постоянная времени, с
	{ 904	,8	,1	, &fEM_R0UN03RSS},	//(R0UN03RSS) нижняя граница интервала мощности для измерения периода (ватт)
	{ 905	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 906	,8	,1	, &internal2_m182_tx},	//(internal2_m182_tx) tx - время накопленное сек
	{ 907	,18	,1	, &internal2_m182_y0},	//(internal2_m182_y0) y0
	{ 908	,8	,1	, &internal2_m176_tx},	//(internal2_m176_tx) tx - время накопленное сек
	{ 909	,18	,1	, &internal2_m176_y0},	//(internal2_m176_y0) y0
	{ 910	,8	,1	, &internal2_m173_tx},	//(internal2_m173_tx) tx - время накопленное сек
	{ 911	,18	,1	, &internal2_m173_y0},	//(internal2_m173_y0) y0
	{ 912	,8	,1	, &internal2_m165_tx},	//(internal2_m165_tx) tx - время накопленное сек
	{ 913	,18	,1	, &internal2_m165_y0},	//(internal2_m165_y0) y0
	{ 914	,8	,1	, &internal2_m158_tx},	//(internal2_m158_tx) tx - время накопленное сек
	{ 915	,18	,1	, &internal2_m158_y0},	//(internal2_m158_y0) y0
	{ 916	,8	,1	, &internal2_m155_tx},	//(internal2_m155_tx) tx - время накопленное сек
	{ 917	,18	,1	, &internal2_m155_y0},	//(internal2_m155_y0) y0
	{ 918	,8	,1	, &internal2_m149_tx},	//(internal2_m149_tx) tx - время накопленное сек
	{ 919	,18	,1	, &internal2_m149_y0},	//(internal2_m149_y0) y0
	{ 920	,8	,1	, &internal2_m144_tx},	//(internal2_m144_tx) tx - время накопленное сек
	{ 921	,18	,1	, &internal2_m144_y0},	//(internal2_m144_y0) y0
	{ 922	,8	,1	, &internal2_m141_tx},	//(internal2_m141_tx) tx - время накопленное сек
	{ 923	,18	,1	, &internal2_m141_y0},	//(internal2_m141_y0) y0
	{ 924	,8	,1	, &internal2_m134_tx},	//(internal2_m134_tx) tx - время накопленное сек
	{ 925	,18	,1	, &internal2_m134_y0},	//(internal2_m134_y0) y0
	{ 926	,8	,1	, &internal2_m132_tx},	//(internal2_m132_tx) tx - время накопленное сек
	{ 927	,18	,1	, &internal2_m132_y0},	//(internal2_m132_y0) y0
	{ 928	,8	,1	, &internal2_m127_tx},	//(internal2_m127_tx) tx - время накопленное сек
	{ 929	,18	,1	, &internal2_m127_y0},	//(internal2_m127_y0) y0
	{ 930	,8	,1	, &internal2_m195_y0},	//(internal2_m195_y0) y0
	{ 931	,8	,1	, &internal2_m193_y0},	//(internal2_m193_y0) y0
	{ 932	,1	,1	, &internal2_m228_y0},	//(internal2_m228_y0) state
	{ 933	,1	,1	, &internal2_m220_y0},	//(internal2_m220_y0) state
	{ 934	,1	,1	, &internal2_m208_y1},	//(internal2_m208_y1) y1 - внутренний параметр
	{ 935	,1	,1	, &internal2_m214_y1},	//(internal2_m214_y1) y1 - внутренний параметр
	{ 936	,1	,1	, &internal2_m198_y1},	//(internal2_m198_y1) y1 - внутренний параметр
	{ 937	,1	,1	, &internal2_m205_y1},	//(internal2_m205_y1) y1 - внутренний параметр
	{ 938	,5	,1	, &internal2_m17_Nk0},	//(internal2_m17_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 939	,1	,1	, &internal2_m17_SetFlag},	//(internal2_m17_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 940	,5	,1	, &internal2_m110_Nk0},	//(internal2_m110_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 941	,1	,1	, &internal2_m110_SetFlag},	//(internal2_m110_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 942	,5	,1	, &internal2_m106_Nk0},	//(internal2_m106_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 943	,1	,1	, &internal2_m106_SetFlag},	//(internal2_m106_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 944	,5	,1	, &internal2_m75_Nk0},	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 945	,1	,1	, &internal2_m75_SetFlag},	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 946	,5	,1	, &internal2_m77_Nk0},	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 947	,1	,1	, &internal2_m77_SetFlag},	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 948	,5	,1	, &internal2_m49_Nk0},	//(internal2_m49_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 949	,1	,1	, &internal2_m49_SetFlag},	//(internal2_m49_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 950	,5	,1	, &internal2_m53_Nk0},	//(internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 951	,1	,1	, &internal2_m53_SetFlag},	//(internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 952	,5	,1	, &internal2_m15_Nk0},	//(internal2_m15_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 953	,1	,1	, &internal2_m15_SetFlag},	//(internal2_m15_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 954	,3	,1	, &internal1_m78_flst},	//(internal1_m78_flst)  флаг старта измерения
	{ 955	,3	,1	, &internal1_m78_chsr},	//(internal1_m78_chsr)  счетчик усреднения
	{ 956	,3	,1	, &internal1_m78_chizm},	//(internal1_m78_chizm)  счетчик уменьшения мощности
	{ 957	,8	,1	, &internal1_m78_sumtim},	//(internal1_m78_sumtim)  время измерения мощности
	{ 958	,8	,1	, &internal1_m78_W1},	//(internal1_m78_W1)  мощность на старте измерения
	{ 959	,8	,1	, &internal1_m78_W2},	//(internal1_m78_W2)  мощность в конце измерения
	{ 960	,8	,1	, &internal1_m78_Wmin},	//(internal1_m78_Wmin)  минимальное измерение в серии
	{ 961	,8	,1	, &internal1_m78_Wmax},	//(internal1_m78_Wmax)  максимальное измерение в серии
	{ 962	,8	,1	, &internal1_m78_Wlast},	//(internal1_m78_Wlast)  последнее растущее измерение
	{ 963	,8	,1	, &internal1_m78_y0},	//(internal1_m78_y0) y0 - внутренний параметр
	{ 964	,1	,1	, &internal1_m78_MyFirstEnterFlag},	//(internal1_m78_MyFirstEnterFlag)  FirstEnterFlag
	{ 965	,8	,1	, &internal1_m2035_tx},	//(internal1_m2035_tx) tx - внутренний параметр
	{ 966	,8	,1	, &internal1_m2034_tx},	//(internal1_m2034_tx) tx - внутренний параметр
	{ 967	,8	,1	, &internal1_m780_tx},	//(internal1_m780_tx) tx - внутренний параметр
	{ 968	,8	,1	, &internal1_m737_tx},	//(internal1_m737_tx) tx - внутренний параметр
	{ 969	,8	,1	, &internal1_m790_tx},	//(internal1_m790_tx) tx - внутренний параметр
	{ 970	,8	,1	, &internal1_m792_tx},	//(internal1_m792_tx) tx - внутренний параметр
	{ 971	,8	,1	, &internal1_m791_tx},	//(internal1_m791_tx) tx - внутренний параметр
	{ 972	,8	,1	, &internal1_m746_tx},	//(internal1_m746_tx) tx - внутренний параметр
	{ 973	,8	,1	, &internal1_m730_tx},	//(internal1_m730_tx) tx - внутренний параметр
	{ 974	,8	,1	, &internal1_m741_tx},	//(internal1_m741_tx) tx - внутренний параметр
	{ 975	,8	,1	, &internal1_m772_tx},	//(internal1_m772_tx) tx - внутренний параметр
	{ 976	,8	,1	, &internal1_m789_tx},	//(internal1_m789_tx) tx - внутренний параметр
	{ 977	,8	,1	, &internal1_m762_tx},	//(internal1_m762_tx) tx - внутренний параметр
	{ 978	,8	,1	, &internal1_m393_tx},	//(internal1_m393_tx) tx - внутренний параметр
	{ 979	,8	,1	, &internal1_m392_tx},	//(internal1_m392_tx) tx - внутренний параметр
	{ 980	,8	,1	, &internal1_m391_tx},	//(internal1_m391_tx) tx - внутренний параметр
	{ 981	,8	,1	, &internal1_m390_tx},	//(internal1_m390_tx) tx - внутренний параметр
	{ 982	,8	,1	, &internal1_m761_tx},	//(internal1_m761_tx) tx - внутренний параметр
	{ 983	,8	,1	, &internal1_m756_tx},	//(internal1_m756_tx) tx - внутренний параметр
	{ 984	,8	,1	, &internal1_m764_tx},	//(internal1_m764_tx) tx - внутренний параметр
	{ 985	,8	,1	, &internal1_m770_tx},	//(internal1_m770_tx) tx - внутренний параметр
	{ 986	,8	,1	, &internal1_m526_tx},	//(internal1_m526_tx) tx - внутренний параметр
	{ 987	,8	,1	, &internal1_m525_tx},	//(internal1_m525_tx) tx - внутренний параметр
	{ 988	,8	,1	, &internal1_m524_tx},	//(internal1_m524_tx) tx - внутренний параметр
	{ 989	,8	,1	, &internal1_m520_tx},	//(internal1_m520_tx) tx - внутренний параметр
	{ 990	,8	,1	, &internal1_m497_tx},	//(internal1_m497_tx) tx - внутренний параметр
	{ 991	,8	,1	, &internal1_m496_tx},	//(internal1_m496_tx) tx - внутренний параметр
	{ 992	,8	,1	, &internal1_m495_tx},	//(internal1_m495_tx) tx - внутренний параметр
	{ 993	,8	,1	, &internal1_m498_tx},	//(internal1_m498_tx) tx - внутренний параметр
	{ 994	,8	,1	, &internal1_m2437_tx},	//(internal1_m2437_tx) tx - внутренний параметр
	{ 995	,8	,1	, &internal1_m2149_tx},	//(internal1_m2149_tx) tx - внутренний параметр
	{ 996	,8	,1	, &internal1_m2436_tx},	//(internal1_m2436_tx) tx - внутренний параметр
	{ 997	,8	,1	, &internal1_m2435_tx},	//(internal1_m2435_tx) tx - внутренний параметр
	{ 998	,8	,1	, &internal1_m2433_tx},	//(internal1_m2433_tx) tx - внутренний параметр
	{ 999	,8	,1	, &internal1_m108_tx},	//(internal1_m108_tx) tx - внутренний параметр
	{ 1000	,8	,1	, &internal1_m1144_tx},	//(internal1_m1144_tx) tx - внутренний параметр
	{ 1001	,8	,1	, &internal1_m2295_tx},	//(internal1_m2295_tx) tx - внутренний параметр
	{ 1002	,8	,1	, &internal1_m2294_tx},	//(internal1_m2294_tx) tx - внутренний параметр
	{ 1003	,8	,1	, &internal1_m2293_tx},	//(internal1_m2293_tx) tx - внутренний параметр
	{ 1004	,8	,1	, &internal1_m1234_tx},	//(internal1_m1234_tx) tx - внутренний параметр
	{ 1005	,8	,1	, &internal1_m1233_tx},	//(internal1_m1233_tx) tx - внутренний параметр
	{ 1006	,8	,1	, &internal1_m1228_tx},	//(internal1_m1228_tx) tx - внутренний параметр
	{ 1007	,8	,1	, &internal1_m1221_tx},	//(internal1_m1221_tx) tx - внутренний параметр
	{ 1008	,8	,1	, &internal1_m1219_tx},	//(internal1_m1219_tx) tx - внутренний параметр
	{ 1009	,8	,1	, &internal1_m1217_tx},	//(internal1_m1217_tx) tx - внутренний параметр
	{ 1010	,8	,1	, &internal1_m1215_tx},	//(internal1_m1215_tx) tx - внутренний параметр
	{ 1011	,8	,1	, &internal1_m1258_tx},	//(internal1_m1258_tx) tx - внутренний параметр
	{ 1012	,8	,1	, &internal1_m1265_tx},	//(internal1_m1265_tx) tx - внутренний параметр
	{ 1013	,8	,1	, &internal1_m1270_tx},	//(internal1_m1270_tx) tx - внутренний параметр
	{ 1014	,8	,1	, &internal1_m1276_tx},	//(internal1_m1276_tx) tx - внутренний параметр
	{ 1015	,8	,1	, &internal1_m1236_tx},	//(internal1_m1236_tx) tx - внутренний параметр
	{ 1016	,8	,1	, &internal1_m1257_tx},	//(internal1_m1257_tx) tx - внутренний параметр
	{ 1017	,8	,1	, &internal1_m1271_tx},	//(internal1_m1271_tx) tx - внутренний параметр
	{ 1018	,8	,1	, &internal1_m475_tx},	//(internal1_m475_tx) tx - внутренний параметр
	{ 1019	,8	,1	, &internal1_m469_tx},	//(internal1_m469_tx) tx - внутренний параметр
	{ 1020	,8	,1	, &internal1_m471_tx},	//(internal1_m471_tx) tx - внутренний параметр
	{ 1021	,8	,1	, &internal1_m473_tx},	//(internal1_m473_tx) tx - внутренний параметр
	{ 1022	,8	,1	, &internal1_m480_tx},	//(internal1_m480_tx) tx - внутренний параметр
	{ 1023	,8	,1	, &internal1_m434_tx},	//(internal1_m434_tx) tx - внутренний параметр
	{ 1024	,8	,1	, &internal1_m432_tx},	//(internal1_m432_tx) tx - внутренний параметр
	{ 1025	,8	,1	, &internal1_m433_tx},	//(internal1_m433_tx) tx - внутренний параметр
	{ 1026	,8	,1	, &internal1_m426_tx},	//(internal1_m426_tx) tx - внутренний параметр
	{ 1027	,8	,1	, &internal1_m888_tx},	//(internal1_m888_tx) tx - внутренний параметр
	{ 1028	,8	,1	, &internal1_m887_tx},	//(internal1_m887_tx) tx - внутренний параметр
	{ 1029	,8	,1	, &internal1_m886_tx},	//(internal1_m886_tx) tx - внутренний параметр
	{ 1030	,8	,1	, &internal1_m882_tx},	//(internal1_m882_tx) tx - внутренний параметр
	{ 1031	,8	,1	, &internal1_m1322_tx},	//(internal1_m1322_tx) tx - внутренний параметр
	{ 1032	,8	,1	, &internal1_m1321_tx},	//(internal1_m1321_tx) tx - внутренний параметр
	{ 1033	,8	,1	, &internal1_m1320_tx},	//(internal1_m1320_tx) tx - внутренний параметр
	{ 1034	,8	,1	, &internal1_m1533_tx},	//(internal1_m1533_tx) tx - внутренний параметр
	{ 1035	,8	,1	, &internal1_m1546_tx},	//(internal1_m1546_tx) tx - внутренний параметр
	{ 1036	,8	,1	, &internal1_m1545_tx},	//(internal1_m1545_tx) tx - внутренний параметр
	{ 1037	,8	,1	, &internal1_m1544_tx},	//(internal1_m1544_tx) tx - внутренний параметр
	{ 1038	,8	,1	, &internal1_m1535_tx},	//(internal1_m1535_tx) tx - внутренний параметр
	{ 1039	,8	,1	, &internal1_m2267_tx},	//(internal1_m2267_tx) tx - внутренний параметр
	{ 1040	,8	,1	, &internal1_m2250_tx},	//(internal1_m2250_tx) tx - внутренний параметр
	{ 1041	,8	,1	, &internal1_m2227_tx},	//(internal1_m2227_tx) tx - внутренний параметр
	{ 1042	,8	,1	, &internal1_m1543_tx},	//(internal1_m1543_tx) tx - внутренний параметр
	{ 1043	,8	,1	, &internal1_m1524_tx},	//(internal1_m1524_tx) tx - внутренний параметр
	{ 1044	,8	,1	, &internal1_m1523_tx},	//(internal1_m1523_tx) tx - внутренний параметр
	{ 1045	,8	,1	, &internal1_m1520_tx},	//(internal1_m1520_tx) tx - внутренний параметр
	{ 1046	,8	,1	, &internal1_m1542_tx},	//(internal1_m1542_tx) tx - внутренний параметр
	{ 1047	,8	,1	, &internal1_m1508_tx},	//(internal1_m1508_tx) tx - внутренний параметр
	{ 1048	,8	,1	, &internal1_m1510_tx},	//(internal1_m1510_tx) tx - внутренний параметр
	{ 1049	,8	,1	, &internal1_m1507_tx},	//(internal1_m1507_tx) tx - внутренний параметр
	{ 1050	,8	,1	, &internal1_m1480_tx},	//(internal1_m1480_tx) tx - внутренний параметр
	{ 1051	,8	,1	, &internal1_m1479_tx},	//(internal1_m1479_tx) tx - внутренний параметр
	{ 1052	,8	,1	, &internal1_m1488_tx},	//(internal1_m1488_tx) tx - внутренний параметр
	{ 1053	,8	,1	, &internal1_m1492_tx},	//(internal1_m1492_tx) tx - внутренний параметр
	{ 1054	,8	,1	, &internal1_m981_tx},	//(internal1_m981_tx) tx - внутренний параметр
	{ 1055	,8	,1	, &internal1_m984_tx},	//(internal1_m984_tx) tx - внутренний параметр
	{ 1056	,8	,1	, &internal1_m2218_tx},	//(internal1_m2218_tx) tx - внутренний параметр
	{ 1057	,8	,1	, &internal1_m974_tx},	//(internal1_m974_tx) tx - внутренний параметр
	{ 1058	,8	,1	, &internal1_m972_tx},	//(internal1_m972_tx) tx - внутренний параметр
	{ 1059	,8	,1	, &internal1_m980_tx},	//(internal1_m980_tx) tx - внутренний параметр
	{ 1060	,8	,1	, &internal1_m966_tx},	//(internal1_m966_tx) tx - внутренний параметр
	{ 1061	,8	,1	, &internal1_m959_tx},	//(internal1_m959_tx) tx - внутренний параметр
	{ 1062	,8	,1	, &internal1_m958_tx},	//(internal1_m958_tx) tx - внутренний параметр
	{ 1063	,8	,1	, &internal1_m979_tx},	//(internal1_m979_tx) tx - внутренний параметр
	{ 1064	,8	,1	, &internal1_m946_tx},	//(internal1_m946_tx) tx - внутренний параметр
	{ 1065	,8	,1	, &internal1_m947_tx},	//(internal1_m947_tx) tx - внутренний параметр
	{ 1066	,8	,1	, &internal1_m944_tx},	//(internal1_m944_tx) tx - внутренний параметр
	{ 1067	,8	,1	, &internal1_m632_tx},	//(internal1_m632_tx) tx - внутренний параметр
	{ 1068	,8	,1	, &internal1_m635_tx},	//(internal1_m635_tx) tx - внутренний параметр
	{ 1069	,8	,1	, &internal1_m634_tx},	//(internal1_m634_tx) tx - внутренний параметр
	{ 1070	,8	,1	, &internal1_m624_tx},	//(internal1_m624_tx) tx - внутренний параметр
	{ 1071	,8	,1	, &internal1_m621_tx},	//(internal1_m621_tx) tx - внутренний параметр
	{ 1072	,8	,1	, &internal1_m617_tx},	//(internal1_m617_tx) tx - внутренний параметр
	{ 1073	,8	,1	, &internal1_m630_tx},	//(internal1_m630_tx) tx - внутренний параметр
	{ 1074	,8	,1	, &internal1_m607_tx},	//(internal1_m607_tx) tx - внутренний параметр
	{ 1075	,8	,1	, &internal1_m606_tx},	//(internal1_m606_tx) tx - внутренний параметр
	{ 1076	,8	,1	, &internal1_m602_tx},	//(internal1_m602_tx) tx - внутренний параметр
	{ 1077	,8	,1	, &internal1_m633_tx},	//(internal1_m633_tx) tx - внутренний параметр
	{ 1078	,8	,1	, &internal1_m590_tx},	//(internal1_m590_tx) tx - внутренний параметр
	{ 1079	,8	,1	, &internal1_m589_tx},	//(internal1_m589_tx) tx - внутренний параметр
	{ 1080	,8	,1	, &internal1_m592_tx},	//(internal1_m592_tx) tx - внутренний параметр
	{ 1081	,8	,1	, &internal1_m569_tx},	//(internal1_m569_tx) tx - внутренний параметр
	{ 1082	,8	,1	, &internal1_m570_tx},	//(internal1_m570_tx) tx - внутренний параметр
	{ 1083	,8	,1	, &internal1_m571_tx},	//(internal1_m571_tx) tx - внутренний параметр
	{ 1084	,8	,1	, &internal1_m576_tx},	//(internal1_m576_tx) tx - внутренний параметр
	{ 1085	,8	,1	, &internal1_m2278_tx},	//(internal1_m2278_tx) tx - внутренний параметр
	{ 1086	,8	,1	, &internal1_m2279_tx},	//(internal1_m2279_tx) tx - внутренний параметр
	{ 1087	,8	,1	, &internal1_m2280_tx},	//(internal1_m2280_tx) tx - внутренний параметр
	{ 1088	,8	,1	, &internal1_m1761_tx},	//(internal1_m1761_tx) tx - внутренний параметр
	{ 1089	,8	,1	, &internal1_m1760_tx},	//(internal1_m1760_tx) tx - внутренний параметр
	{ 1090	,8	,1	, &internal1_m1755_tx},	//(internal1_m1755_tx) tx - внутренний параметр
	{ 1091	,8	,1	, &internal1_m1746_tx},	//(internal1_m1746_tx) tx - внутренний параметр
	{ 1092	,8	,1	, &internal1_m1744_tx},	//(internal1_m1744_tx) tx - внутренний параметр
	{ 1093	,8	,1	, &internal1_m1742_tx},	//(internal1_m1742_tx) tx - внутренний параметр
	{ 1094	,8	,1	, &internal1_m1741_tx},	//(internal1_m1741_tx) tx - внутренний параметр
	{ 1095	,8	,1	, &internal1_m1782_tx},	//(internal1_m1782_tx) tx - внутренний параметр
	{ 1096	,8	,1	, &internal1_m1790_tx},	//(internal1_m1790_tx) tx - внутренний параметр
	{ 1097	,8	,1	, &internal1_m1797_tx},	//(internal1_m1797_tx) tx - внутренний параметр
	{ 1098	,8	,1	, &internal1_m1798_tx},	//(internal1_m1798_tx) tx - внутренний параметр
	{ 1099	,8	,1	, &internal1_m1788_tx},	//(internal1_m1788_tx) tx - внутренний параметр
	{ 1100	,8	,1	, &internal1_m1763_tx},	//(internal1_m1763_tx) tx - внутренний параметр
	{ 1101	,8	,1	, &internal1_m1777_tx},	//(internal1_m1777_tx) tx - внутренний параметр
	{ 1102	,8	,1	, &internal1_m452_tx},	//(internal1_m452_tx) tx - внутренний параметр
	{ 1103	,8	,1	, &internal1_m443_tx},	//(internal1_m443_tx) tx - внутренний параметр
	{ 1104	,8	,1	, &internal1_m444_tx},	//(internal1_m444_tx) tx - внутренний параметр
	{ 1105	,8	,1	, &internal1_m446_tx},	//(internal1_m446_tx) tx - внутренний параметр
	{ 1106	,8	,1	, &internal1_m460_tx},	//(internal1_m460_tx) tx - внутренний параметр
	{ 1107	,8	,1	, &internal1_m410_tx},	//(internal1_m410_tx) tx - внутренний параметр
	{ 1108	,8	,1	, &internal1_m407_tx},	//(internal1_m407_tx) tx - внутренний параметр
	{ 1109	,8	,1	, &internal1_m406_tx},	//(internal1_m406_tx) tx - внутренний параметр
	{ 1110	,8	,1	, &internal1_m405_tx},	//(internal1_m405_tx) tx - внутренний параметр
	{ 1111	,8	,1	, &internal1_m865_tx},	//(internal1_m865_tx) tx - внутренний параметр
	{ 1112	,8	,1	, &internal1_m861_tx},	//(internal1_m861_tx) tx - внутренний параметр
	{ 1113	,8	,1	, &internal1_m860_tx},	//(internal1_m860_tx) tx - внутренний параметр
	{ 1114	,8	,1	, &internal1_m859_tx},	//(internal1_m859_tx) tx - внутренний параметр
	{ 1115	,8	,1	, &internal1_m1303_tx},	//(internal1_m1303_tx) tx - внутренний параметр
	{ 1116	,8	,1	, &internal1_m1300_tx},	//(internal1_m1300_tx) tx - внутренний параметр
	{ 1117	,8	,1	, &internal1_m1299_tx},	//(internal1_m1299_tx) tx - внутренний параметр
	{ 1118	,8	,1	, &internal1_m1082_tx},	//(internal1_m1082_tx) tx - внутренний параметр
	{ 1119	,8	,1	, &internal1_m2239_tx},	//(internal1_m2239_tx) tx - внутренний параметр
	{ 1120	,8	,1	, &internal1_m1093_tx},	//(internal1_m1093_tx) tx - внутренний параметр
	{ 1121	,8	,1	, &internal1_m1095_tx},	//(internal1_m1095_tx) tx - внутренний параметр
	{ 1122	,8	,1	, &internal1_m1094_tx},	//(internal1_m1094_tx) tx - внутренний параметр
	{ 1123	,8	,1	, &internal1_m2233_tx},	//(internal1_m2233_tx) tx - внутренний параметр
	{ 1124	,8	,1	, &internal1_m1084_tx},	//(internal1_m1084_tx) tx - внутренний параметр
	{ 1125	,8	,1	, &internal1_m2238_tx},	//(internal1_m2238_tx) tx - внутренний параметр
	{ 1126	,8	,1	, &internal1_m1092_tx},	//(internal1_m1092_tx) tx - внутренний параметр
	{ 1127	,8	,1	, &internal1_m1074_tx},	//(internal1_m1074_tx) tx - внутренний параметр
	{ 1128	,8	,1	, &internal1_m1073_tx},	//(internal1_m1073_tx) tx - внутренний параметр
	{ 1129	,8	,1	, &internal1_m1069_tx},	//(internal1_m1069_tx) tx - внутренний параметр
	{ 1130	,8	,1	, &internal1_m1091_tx},	//(internal1_m1091_tx) tx - внутренний параметр
	{ 1131	,8	,1	, &internal1_m1059_tx},	//(internal1_m1059_tx) tx - внутренний параметр
	{ 1132	,8	,1	, &internal1_m1057_tx},	//(internal1_m1057_tx) tx - внутренний параметр
	{ 1133	,8	,1	, &internal1_m1056_tx},	//(internal1_m1056_tx) tx - внутренний параметр
	{ 1134	,8	,1	, &internal1_m1035_tx},	//(internal1_m1035_tx) tx - внутренний параметр
	{ 1135	,8	,1	, &internal1_m1034_tx},	//(internal1_m1034_tx) tx - внутренний параметр
	{ 1136	,8	,1	, &internal1_m1024_tx},	//(internal1_m1024_tx) tx - внутренний параметр
	{ 1137	,8	,1	, &internal1_m1041_tx},	//(internal1_m1041_tx) tx - внутренний параметр
	{ 1138	,8	,1	, &internal1_m1438_tx},	//(internal1_m1438_tx) tx - внутренний параметр
	{ 1139	,8	,1	, &internal1_m1437_tx},	//(internal1_m1437_tx) tx - внутренний параметр
	{ 1140	,8	,1	, &internal1_m2185_tx},	//(internal1_m2185_tx) tx - внутренний параметр
	{ 1141	,8	,1	, &internal1_m1428_tx},	//(internal1_m1428_tx) tx - внутренний параметр
	{ 1142	,8	,1	, &internal1_m1429_tx},	//(internal1_m1429_tx) tx - внутренний параметр
	{ 1143	,8	,1	, &internal1_m1436_tx},	//(internal1_m1436_tx) tx - внутренний параметр
	{ 1144	,8	,1	, &internal1_m1419_tx},	//(internal1_m1419_tx) tx - внутренний параметр
	{ 1145	,8	,1	, &internal1_m1418_tx},	//(internal1_m1418_tx) tx - внутренний параметр
	{ 1146	,8	,1	, &internal1_m1414_tx},	//(internal1_m1414_tx) tx - внутренний параметр
	{ 1147	,8	,1	, &internal1_m1435_tx},	//(internal1_m1435_tx) tx - внутренний параметр
	{ 1148	,8	,1	, &internal1_m1401_tx},	//(internal1_m1401_tx) tx - внутренний параметр
	{ 1149	,8	,1	, &internal1_m1399_tx},	//(internal1_m1399_tx) tx - внутренний параметр
	{ 1150	,8	,1	, &internal1_m1405_tx},	//(internal1_m1405_tx) tx - внутренний параметр
	{ 1151	,8	,1	, &internal1_m250_tx},	//(internal1_m250_tx) tx - внутренний параметр
	{ 1152	,8	,1	, &internal1_m265_tx},	//(internal1_m265_tx) tx - внутренний параметр
	{ 1153	,8	,1	, &internal1_m272_tx},	//(internal1_m272_tx) tx - внутренний параметр
	{ 1154	,8	,1	, &internal1_m271_tx},	//(internal1_m271_tx) tx - внутренний параметр
	{ 1155	,8	,1	, &internal1_m257_tx},	//(internal1_m257_tx) tx - внутренний параметр
	{ 1156	,8	,1	, &internal1_m253_tx},	//(internal1_m253_tx) tx - внутренний параметр
	{ 1157	,8	,1	, &internal1_m269_tx},	//(internal1_m269_tx) tx - внутренний параметр
	{ 1158	,8	,1	, &internal1_m241_tx},	//(internal1_m241_tx) tx - внутренний параметр
	{ 1159	,8	,1	, &internal1_m240_tx},	//(internal1_m240_tx) tx - внутренний параметр
	{ 1160	,8	,1	, &internal1_m236_tx},	//(internal1_m236_tx) tx - внутренний параметр
	{ 1161	,8	,1	, &internal1_m268_tx},	//(internal1_m268_tx) tx - внутренний параметр
	{ 1162	,8	,1	, &internal1_m225_tx},	//(internal1_m225_tx) tx - внутренний параметр
	{ 1163	,8	,1	, &internal1_m227_tx},	//(internal1_m227_tx) tx - внутренний параметр
	{ 1164	,8	,1	, &internal1_m224_tx},	//(internal1_m224_tx) tx - внутренний параметр
	{ 1165	,8	,1	, &internal1_m203_tx},	//(internal1_m203_tx) tx - внутренний параметр
	{ 1166	,8	,1	, &internal1_m202_tx},	//(internal1_m202_tx) tx - внутренний параметр
	{ 1167	,8	,1	, &internal1_m201_tx},	//(internal1_m201_tx) tx - внутренний параметр
	{ 1168	,8	,1	, &internal1_m209_tx},	//(internal1_m209_tx) tx - внутренний параметр
	{ 1169	,8	,1	, &internal1_m1381_tx},	//(internal1_m1381_tx) tx - внутренний параметр
	{ 1170	,8	,1	, &internal1_m1363_tx},	//(internal1_m1363_tx) tx - внутренний параметр
	{ 1171	,8	,1	, &internal1_m1368_tx},	//(internal1_m1368_tx) tx - внутренний параметр
	{ 1172	,8	,1	, &internal1_m1383_tx},	//(internal1_m1383_tx) tx - внутренний параметр
	{ 1173	,8	,1	, &internal1_m924_tx},	//(internal1_m924_tx) tx - внутренний параметр
	{ 1174	,8	,1	, &internal1_m929_tx},	//(internal1_m929_tx) tx - внутренний параметр
	{ 1175	,8	,1	, &internal1_m919_tx},	//(internal1_m919_tx) tx - внутренний параметр
	{ 1176	,8	,1	, &internal1_m920_tx},	//(internal1_m920_tx) tx - внутренний параметр
	{ 1177	,3	,1	, &internal1_m2488_sttlf},	//(internal1_m2488_sttlf) sttlf - счетчик для вещественного формата
	{ 1178	,1	,1	, &internal1_m1882_q0},	//(internal1_m1882_q0) q0 - внутренний параметр
	{ 1179	,1	,1	, &internal1_m2320_q0},	//(internal1_m2320_q0) q0 - внутренний параметр
	{ 1180	,1	,1	, &internal1_m2304_q0},	//(internal1_m2304_q0) q0 - внутренний параметр
	{ 1181	,1	,1	, &internal1_m2351_q0},	//(internal1_m2351_q0) q0 - внутренний параметр
	{ 1182	,1	,1	, &internal1_m2335_q0},	//(internal1_m2335_q0) q0 - внутренний параметр
	{ 1183	,1	,1	, &internal1_m2326_q0},	//(internal1_m2326_q0) q0 - внутренний параметр
	{ 1184	,1	,1	, &internal1_m2307_q0},	//(internal1_m2307_q0) q0 - внутренний параметр
	{ 1185	,1	,1	, &internal1_m2324_q0},	//(internal1_m2324_q0) q0 - внутренний параметр
	{ 1186	,1	,1	, &internal1_m2305_q0},	//(internal1_m2305_q0) q0 - внутренний параметр
	{ 1187	,1	,1	, &internal1_m2303_q0},	//(internal1_m2303_q0) q0 - внутренний параметр
	{ 1188	,1	,1	, &internal1_m2302_q0},	//(internal1_m2302_q0) q0 - внутренний параметр
	{ 1189	,1	,1	, &internal1_m2316_q0},	//(internal1_m2316_q0) q0 - внутренний параметр
	{ 1190	,1	,1	, &internal1_m2314_q0},	//(internal1_m2314_q0) q0 - внутренний параметр
	{ 1191	,1	,1	, &internal1_m2322_q0},	//(internal1_m2322_q0) q0 - внутренний параметр
	{ 1192	,1	,1	, &internal1_m2318_q0},	//(internal1_m2318_q0) q0 - внутренний параметр
	{ 1193	,1	,1	, &internal1_m2357_q0},	//(internal1_m2357_q0) q0 - внутренний параметр
	{ 1194	,1	,1	, &internal1_m2338_q0},	//(internal1_m2338_q0) q0 - внутренний параметр
	{ 1195	,1	,1	, &internal1_m2355_q0},	//(internal1_m2355_q0) q0 - внутренний параметр
	{ 1196	,1	,1	, &internal1_m2337_q0},	//(internal1_m2337_q0) q0 - внутренний параметр
	{ 1197	,1	,1	, &internal1_m2334_q0},	//(internal1_m2334_q0) q0 - внутренний параметр
	{ 1198	,1	,1	, &internal1_m2333_q0},	//(internal1_m2333_q0) q0 - внутренний параметр
	{ 1199	,1	,1	, &internal1_m2347_q0},	//(internal1_m2347_q0) q0 - внутренний параметр
	{ 1200	,1	,1	, &internal1_m2345_q0},	//(internal1_m2345_q0) q0 - внутренний параметр
	{ 1201	,8	,1	, &internal1_m2210_tx},	//(internal1_m2210_tx) tx - внутренний параметр
	{ 1202	,8	,1	, &internal1_m2189_tx},	//(internal1_m2189_tx) tx - внутренний параметр
	{ 1203	,1	,1	, &internal1_m1905_Pv0},	//(internal1_m1905_Pv0)  - Пер. выключатель механизма
	{ 1204	,1	,1	, &internal1_m1905_Zv0},	//(internal1_m1905_Zv0)  - Зад. выключатель механизма
	{ 1205	,1	,1	, &internal1_m1905_MyFirstEnterFlag},	//(internal1_m1905_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1206	,1	,1	, &internal1_m1903_Pv0},	//(internal1_m1903_Pv0)  - Пер. выключатель механизма
	{ 1207	,1	,1	, &internal1_m1903_Zv0},	//(internal1_m1903_Zv0)  - Зад. выключатель механизма
	{ 1208	,1	,1	, &internal1_m1903_MyFirstEnterFlag},	//(internal1_m1903_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1209	,8	,1	, &internal1_m2374_tx},	//(internal1_m2374_tx) tx - время накопленное сек
	{ 1210	,18	,1	, &internal1_m2374_y0},	//(internal1_m2374_y0) y0
	{ 1211	,8	,1	, &internal1_m2379_tx},	//(internal1_m2379_tx) tx - время накопленное сек
	{ 1212	,18	,1	, &internal1_m2379_y0},	//(internal1_m2379_y0) y0
	{ 1213	,8	,1	, &internal1_m2378_tx},	//(internal1_m2378_tx) tx - время накопленное сек
	{ 1214	,18	,1	, &internal1_m2378_y0},	//(internal1_m2378_y0) y0
	{ 1215	,8	,1	, &internal1_m2415_tx},	//(internal1_m2415_tx) tx - внутренний параметр
	{ 1216	,8	,1	, &internal1_m2413_tx},	//(internal1_m2413_tx) tx - время накопленное сек
	{ 1217	,18	,1	, &internal1_m2413_y0},	//(internal1_m2413_y0) y0
	{ 1218	,1	,1	, &internal1_m2418_q0},	//(internal1_m2418_q0) q0 - внутренний параметр
	{ 1219	,1	,1	, &internal1_m2385_q0},	//(internal1_m2385_q0) q0 - внутренний параметр
	{ 1220	,8	,1	, &internal1_m2393_tx},	//(internal1_m2393_tx) tx - внутренний параметр
	{ 1221	,1	,1	, &internal1_m2391_q0},	//(internal1_m2391_q0) q0 - внутренний параметр
	{ 1222	,8	,1	, &internal1_m2204_tx},	//(internal1_m2204_tx) tx - время накопленное сек
	{ 1223	,18	,1	, &internal1_m2204_y0},	//(internal1_m2204_y0) y0
	{ 1224	,8	,1	, &internal1_m2196_tx},	//(internal1_m2196_tx) tx - время накопленное сек
	{ 1225	,18	,1	, &internal1_m2196_y0},	//(internal1_m2196_y0) y0
	{ 1226	,1	,1	, &internal1_m1892_q0},	//(internal1_m1892_q0) q0 - внутренний параметр
	{ 1227	,1	,1	, &internal1_m1897_q0},	//(internal1_m1897_q0) q0 - внутренний параметр
	{ 1228	,1	,1	, &internal1_m1889_q0},	//(internal1_m1889_q0) q0 - внутренний параметр
	{ 1229	,1	,1	, &internal1_m1931_q0},	//(internal1_m1931_q0) q0 - внутренний параметр
	{ 1230	,8	,1	, &internal1_m829_tx},	//(internal1_m829_tx) tx - время накопленное сек
	{ 1231	,18	,1	, &internal1_m829_y0},	//(internal1_m829_y0) y0
	{ 1232	,8	,1	, &internal1_m2200_tx},	//(internal1_m2200_tx) tx - внутренний параметр
	{ 1233	,1	,1	, &internal1_m2203_q0},	//(internal1_m2203_q0) q0 - внутренний параметр
	{ 1234	,1	,1	, &internal1_m2195_q0},	//(internal1_m2195_q0) q0 - внутренний параметр
	{ 1235	,8	,1	, &internal1_m2164_tx},	//(internal1_m2164_tx) tx - внутренний параметр
	{ 1236	,8	,1	, &internal1_m2175_tx},	//(internal1_m2175_tx) tx - внутренний параметр
	{ 1237	,8	,1	, &internal1_m2161_tx},	//(internal1_m2161_tx) tx - внутренний параметр
	{ 1238	,1	,1	, &internal1_m2167_q0},	//(internal1_m2167_q0) q0 - внутренний параметр
	{ 1239	,1	,1	, &internal1_m2179_q0},	//(internal1_m2179_q0) q0 - внутренний параметр
	{ 1240	,8	,1	, &internal1_m2136_tx},	//(internal1_m2136_tx) tx - внутренний параметр
	{ 1241	,8	,1	, &internal1_m51_tx},	//(internal1_m51_tx) tx - внутренний параметр
	{ 1242	,8	,1	, &internal1_m363_tx},	//(internal1_m363_tx) tx - внутренний параметр
	{ 1243	,8	,1	, &internal1_m317_tx},	//(internal1_m317_tx) tx - внутренний параметр
	{ 1244	,8	,1	, &internal1_m830_tx},	//(internal1_m830_tx) tx - внутренний параметр
	{ 1245	,8	,1	, &internal1_m1600_tx},	//(internal1_m1600_tx) tx - внутренний параметр
	{ 1246	,8	,1	, &internal1_m120_tx},	//(internal1_m120_tx) tx - внутренний параметр
	{ 1247	,8	,1	, &internal1_m122_tx},	//(internal1_m122_tx) tx - внутренний параметр
	{ 1248	,8	,1	, &internal1_m127_tx},	//(internal1_m127_tx) tx - внутренний параметр
	{ 1249	,8	,1	, &internal1_m21_tx},	//(internal1_m21_tx) tx - внутренний параметр
	{ 1250	,8	,1	, &internal1_m13_tx},	//(internal1_m13_tx) tx - внутренний параметр
	{ 1251	,8	,1	, &internal1_m2146_tx},	//(internal1_m2146_tx) tx - внутренний параметр
	{ 1252	,8	,1	, &internal1_m2133_tx},	//(internal1_m2133_tx) tx - внутренний параметр
	{ 1253	,8	,1	, &internal1_m2251_tx},	//(internal1_m2251_tx) tx - внутренний параметр
	{ 1254	,8	,1	, &internal1_m2253_tx},	//(internal1_m2253_tx) tx - внутренний параметр
	{ 1255	,8	,1	, &internal1_m82_tx},	//(internal1_m82_tx) tx - внутренний параметр
	{ 1256	,8	,1	, &internal1_m334_tx},	//(internal1_m334_tx) tx - время накопленное сек
	{ 1257	,18	,1	, &internal1_m334_y0},	//(internal1_m334_y0) y0
	{ 1258	,8	,1	, &internal1_m2045_tx},	//(internal1_m2045_tx) tx - время накопленное сек
	{ 1259	,18	,1	, &internal1_m2045_y0},	//(internal1_m2045_y0) y0
	{ 1260	,8	,1	, &internal1_m2059_q0},	//(internal1_m2059_q0) q0 - внутренний параметр
	{ 1261	,8	,1	, &internal1_m1620_q0},	//(internal1_m1620_q0) q0 - внутренний параметр
	{ 1262	,8	,1	, &internal1_m1659_q0},	//(internal1_m1659_q0) q0 - внутренний параметр
	{ 1263	,8	,1	, &internal1_m1656_q0},	//(internal1_m1656_q0) q0 - внутренний параметр
	{ 1264	,8	,1	, &internal1_m2098_q0},	//(internal1_m2098_q0) q0 - внутренний параметр
	{ 1265	,8	,1	, &internal1_m2076_tx},	//(internal1_m2076_tx) tx - время накопленное сек
	{ 1266	,18	,1	, &internal1_m2076_y0},	//(internal1_m2076_y0) y0
	{ 1267	,8	,1	, &internal1_m2091_tx},	//(internal1_m2091_tx) tx - время накопленное сек
	{ 1268	,18	,1	, &internal1_m2091_y0},	//(internal1_m2091_y0) y0
	{ 1269	,8	,1	, &internal1_m2088_tx},	//(internal1_m2088_tx) tx - время накопленное сек
	{ 1270	,18	,1	, &internal1_m2088_y0},	//(internal1_m2088_y0) y0
	{ 1271	,8	,1	, &internal1_m2231_tx},	//(internal1_m2231_tx) tx - время накопленное сек
	{ 1272	,18	,1	, &internal1_m2231_y0},	//(internal1_m2231_y0) y0
	{ 1273	,8	,1	, &internal1_m2242_tx},	//(internal1_m2242_tx) tx - время накопленное сек
	{ 1274	,18	,1	, &internal1_m2242_y0},	//(internal1_m2242_y0) y0
	{ 1275	,8	,1	, &internal1_m1999_tx},	//(internal1_m1999_tx) tx - время накопленное сек
	{ 1276	,18	,1	, &internal1_m1999_y0},	//(internal1_m1999_y0) y0
	{ 1277	,8	,1	, &internal1_m1998_tx},	//(internal1_m1998_tx) tx - время накопленное сек
	{ 1278	,18	,1	, &internal1_m1998_y0},	//(internal1_m1998_y0) y0
	{ 1279	,8	,1	, &internal1_m1997_tx},	//(internal1_m1997_tx) tx - время накопленное сек
	{ 1280	,18	,1	, &internal1_m1997_y0},	//(internal1_m1997_y0) y0
	{ 1281	,8	,1	, &internal1_m1996_tx},	//(internal1_m1996_tx) tx - время накопленное сек
	{ 1282	,18	,1	, &internal1_m1996_y0},	//(internal1_m1996_y0) y0
	{ 1283	,8	,1	, &internal1_m1672_tx},	//(internal1_m1672_tx) tx - время накопленное сек
	{ 1284	,18	,1	, &internal1_m1672_y0},	//(internal1_m1672_y0) y0
	{ 1285	,8	,1	, &internal1_m1666_tx},	//(internal1_m1666_tx) tx - время накопленное сек
	{ 1286	,18	,1	, &internal1_m1666_y0},	//(internal1_m1666_y0) y0
	{ 1287	,8	,1	, &internal1_m1616_tx},	//(internal1_m1616_tx) tx - время накопленное сек
	{ 1288	,18	,1	, &internal1_m1616_y0},	//(internal1_m1616_y0) y0
	{ 1289	,8	,1	, &internal1_m917_tx},	//(internal1_m917_tx) tx - время накопленное сек
	{ 1290	,18	,1	, &internal1_m917_y0},	//(internal1_m917_y0) y0
	{ 1291	,8	,1	, &internal1_m916_tx},	//(internal1_m916_tx) tx - время накопленное сек
	{ 1292	,18	,1	, &internal1_m916_y0},	//(internal1_m916_y0) y0
	{ 1293	,8	,1	, &internal1_m934_tx},	//(internal1_m934_tx) tx - время накопленное сек
	{ 1294	,18	,1	, &internal1_m934_y0},	//(internal1_m934_y0) y0
	{ 1295	,8	,1	, &internal1_m193_tx},	//(internal1_m193_tx) tx - время накопленное сек
	{ 1296	,18	,1	, &internal1_m193_y0},	//(internal1_m193_y0) y0
	{ 1297	,8	,1	, &internal1_m192_tx},	//(internal1_m192_tx) tx - время накопленное сек
	{ 1298	,18	,1	, &internal1_m192_y0},	//(internal1_m192_y0) y0
	{ 1299	,8	,1	, &internal1_m214_tx},	//(internal1_m214_tx) tx - время накопленное сек
	{ 1300	,18	,1	, &internal1_m214_y0},	//(internal1_m214_y0) y0
	{ 1301	,8	,1	, &internal1_m583_tx},	//(internal1_m583_tx) tx - время накопленное сек
	{ 1302	,18	,1	, &internal1_m583_y0},	//(internal1_m583_y0) y0
	{ 1303	,8	,1	, &internal1_m2285_tx},	//(internal1_m2285_tx) tx - внутренний параметр
	{ 1304	,8	,1	, &internal1_m1314_tx},	//(internal1_m1314_tx) tx - внутренний параметр
	{ 1305	,8	,1	, &internal1_m1801_tx},	//(internal1_m1801_tx) tx - время накопленное сек
	{ 1306	,18	,1	, &internal1_m1801_y0},	//(internal1_m1801_y0) y0
	{ 1307	,8	,1	, &internal1_m1278_tx},	//(internal1_m1278_tx) tx - время накопленное сек
	{ 1308	,18	,1	, &internal1_m1278_y0},	//(internal1_m1278_y0) y0
	{ 1309	,8	,1	, &internal1_m1498_tx},	//(internal1_m1498_tx) tx - время накопленное сек
	{ 1310	,18	,1	, &internal1_m1498_y0},	//(internal1_m1498_y0) y0
	{ 1311	,8	,1	, &internal1_m1047_tx},	//(internal1_m1047_tx) tx - время накопленное сек
	{ 1312	,18	,1	, &internal1_m1047_y0},	//(internal1_m1047_y0) y0
	{ 1313	,8	,1	, &internal1_m1388_tx},	//(internal1_m1388_tx) tx - время накопленное сек
	{ 1314	,18	,1	, &internal1_m1388_y0},	//(internal1_m1388_y0) y0
	{ 1315	,1	,1	, &internal1_m1204_q0},	//(internal1_m1204_q0) q0 - внутренний параметр
	{ 1316	,1	,1	, &internal1_m1202_q0},	//(internal1_m1202_q0) q0 - внутренний параметр
	{ 1317	,1	,1	, &internal1_m1201_q0},	//(internal1_m1201_q0) q0 - внутренний параметр
	{ 1318	,1	,1	, &internal1_m1199_q0},	//(internal1_m1199_q0) q0 - внутренний параметр
	{ 1319	,1	,1	, &internal1_m1198_q0},	//(internal1_m1198_q0) q0 - внутренний параметр
	{ 1320	,1	,1	, &internal1_m1196_q0},	//(internal1_m1196_q0) q0 - внутренний параметр
	{ 1321	,1	,1	, &internal1_m1195_q0},	//(internal1_m1195_q0) q0 - внутренний параметр
	{ 1322	,1	,1	, &internal1_m1193_q0},	//(internal1_m1193_q0) q0 - внутренний параметр
	{ 1323	,1	,1	, &internal1_m1192_q0},	//(internal1_m1192_q0) q0 - внутренний параметр
	{ 1324	,1	,1	, &internal1_m52_x0},	//(internal1_m52_x0) - значение входного параметра на предыдущем шаге
	{ 1325	,1	,1	, &internal1_m52_LastSwitch},	//(internal1_m52_LastSwitch) - значение флага отключения сети
	{ 1326	,1	,1	, &internal1_m1111_q0},	//(internal1_m1111_q0) q0 - внутренний параметр
	{ 1327	,1	,1	, &internal1_m1609_x0},	//(internal1_m1609_x0) - значение входного параметра на предыдущем шаге
	{ 1328	,1	,1	, &internal1_m1609_LastSwitch},	//(internal1_m1609_LastSwitch) - значение флага отключения сети
	{ 1329	,1	,1	, &internal1_m1653_x0},	//(internal1_m1653_x0) - значение входного параметра на предыдущем шаге
	{ 1330	,1	,1	, &internal1_m1653_LastSwitch},	//(internal1_m1653_LastSwitch) - значение флага отключения сети
	{ 1331	,1	,1	, &internal1_m1649_x0},	//(internal1_m1649_x0) - значение входного параметра на предыдущем шаге
	{ 1332	,1	,1	, &internal1_m1649_LastSwitch},	//(internal1_m1649_LastSwitch) - значение флага отключения сети
	{ 1333	,1	,1	, &internal1_m2067_x0},	//(internal1_m2067_x0) - значение входного параметра на предыдущем шаге
	{ 1334	,1	,1	, &internal1_m2067_LastSwitch},	//(internal1_m2067_LastSwitch) - значение флага отключения сети
	{ 1335	,1	,1	, &internal1_m2041_x0},	//(internal1_m2041_x0) - значение входного параметра на предыдущем шаге
	{ 1336	,1	,1	, &internal1_m2041_LastSwitch},	//(internal1_m2041_LastSwitch) - значение флага отключения сети
	{ 1337	,1	,1	, &internal1_m1151_q0},	//(internal1_m1151_q0) q0 - внутренний параметр
	{ 1338	,1	,1	, &internal1_m1163_q0},	//(internal1_m1163_q0) q0 - внутренний параметр
	{ 1339	,1	,1	, &internal1_m1175_q0},	//(internal1_m1175_q0) q0 - внутренний параметр
	{ 1340	,1	,1	, &internal1_m1184_q0},	//(internal1_m1184_q0) q0 - внутренний параметр
	{ 1341	,1	,1	, &internal1_m1162_q0},	//(internal1_m1162_q0) q0 - внутренний параметр
	{ 1342	,1	,1	, &internal1_m1177_q0},	//(internal1_m1177_q0) q0 - внутренний параметр
	{ 1343	,1	,1	, &internal1_m2125_q0},	//(internal1_m2125_q0) q0 - внутренний параметр
	{ 1344	,1	,1	, &internal1_m2124_q0},	//(internal1_m2124_q0) q0 - внутренний параметр
	{ 1345	,3	,1	, &internal1_m351_Step},	//(internal1_m351_Step)  - текущий шаг программы
	{ 1346	,18	,10	, &internal1_m351_rz},	//(internal1_m351_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1347	,8	,1	, &internal1_m351_TimS},	//(internal1_m351_TimS) Время от старта программы
	{ 1348	,1	,1	, &internal1_m351_FinPr0},	//(internal1_m351_FinPr0) FinPr - конец программы
	{ 1349	,1	,1	, &internal1_m351_ErrPr0},	//(internal1_m351_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1350	,1	,1	, &internal1_m351_sbINI0},	//(internal1_m351_sbINI0) sbINI - запуск проверки ИНИ
	{ 1351	,1	,1	, &internal1_m351_sbVuIS0},	//(internal1_m351_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1352	,1	,1	, &internal1_m351_sb2UR0},	//(internal1_m351_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1353	,1	,1	, &internal1_m351_sbNupIS0},	//(internal1_m351_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1354	,1	,1	, &internal1_m351_sbVuRB0},	//(internal1_m351_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1355	,1	,1	, &internal1_m351_MyFirstEnterFlag},	//(internal1_m351_MyFirstEnterFlag)  
	{ 1356	,5	,1	, &internal1_m359_x0},	//(internal1_m359_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1357	,5	,1	, &internal1_m316_TimS},	//(internal1_m316_TimS) Время старта
	{ 1358	,3	,1	, &internal1_m293_Step},	//(internal1_m293_Step)  - текущий шаг программы
	{ 1359	,18	,10	, &internal1_m293_rz},	//(internal1_m293_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1360	,8	,1	, &internal1_m293_TimS},	//(internal1_m293_TimS) Время от старта программы
	{ 1361	,1	,1	, &internal1_m293_FinPr0},	//(internal1_m293_FinPr0) FinPr - конец программы
	{ 1362	,1	,1	, &internal1_m293_ErrPr0},	//(internal1_m293_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1363	,1	,1	, &internal1_m293_sbINI0},	//(internal1_m293_sbINI0) sbINI - запуск проверки ИНИ
	{ 1364	,1	,1	, &internal1_m293_sbVuIS0},	//(internal1_m293_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1365	,1	,1	, &internal1_m293_sb2UR0},	//(internal1_m293_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1366	,1	,1	, &internal1_m293_sbNupIS0},	//(internal1_m293_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1367	,1	,1	, &internal1_m293_sbVuRB0},	//(internal1_m293_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1368	,1	,1	, &internal1_m293_MyFirstEnterFlag},	//(internal1_m293_MyFirstEnterFlag)  
	{ 1369	,1	,1	, &internal1_m1572_q0},	//(internal1_m1572_q0) q0 - внутренний параметр
	{ 1370	,3	,1	, &internal1_m1573_Step},	//(internal1_m1573_Step)  - текущий шаг программы
	{ 1371	,18	,6	, &internal1_m1573_rz},	//(internal1_m1573_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1372	,8	,1	, &internal1_m1573_TimS},	//(internal1_m1573_TimS) Время от старта программы
	{ 1373	,1	,1	, &internal1_m1573_FinPr0},	//(internal1_m1573_FinPr0) FinPr - конец программы
	{ 1374	,1	,1	, &internal1_m1573_ErrPr0},	//(internal1_m1573_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1375	,1	,1	, &internal1_m1573_sbINI0},	//(internal1_m1573_sbINI0) sbINI - запуск проверки ИНИ
	{ 1376	,1	,1	, &internal1_m1573_sbVuIS0},	//(internal1_m1573_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1377	,1	,1	, &internal1_m1573_sb2UR0},	//(internal1_m1573_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1378	,1	,1	, &internal1_m1573_sbNupIS0},	//(internal1_m1573_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1379	,1	,1	, &internal1_m1573_sbVuRB0},	//(internal1_m1573_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1380	,1	,1	, &internal1_m1573_MyFirstEnterFlag},	//(internal1_m1573_MyFirstEnterFlag)  
	{ 1381	,1	,1	, &internal1_m1148_q0},	//(internal1_m1148_q0) q0 - внутренний параметр
	{ 1382	,1	,1	, &internal1_m1145_q0},	//(internal1_m1145_q0) q0 - внутренний параметр
	{ 1383	,1	,1	, &internal1_m1147_q0},	//(internal1_m1147_q0) q0 - внутренний параметр
	{ 1384	,1	,1	, &internal1_m1140_q0},	//(internal1_m1140_q0) q0 - внутренний параметр
	{ 1385	,1	,1	, &internal1_m831_q0},	//(internal1_m831_q0) q0 - внутренний параметр
	{ 1386	,1	,1	, &internal1_m361_q0},	//(internal1_m361_q0) q0 - внутренний параметр
	{ 1387	,1	,1	, &internal1_m357_q0},	//(internal1_m357_q0) q0 - внутренний параметр
	{ 1388	,1	,1	, &internal1_m313_q0},	//(internal1_m313_q0) q0 - внутренний параметр
	{ 1389	,5	,1	, &internal1_m312_x0},	//(internal1_m312_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1390	,1	,1	, &internal1_m2055_q0},	//(internal1_m2055_q0) q0 - внутренний параметр
	{ 1391	,1	,1	, &internal1_m2048_q0},	//(internal1_m2048_q0) q0 - внутренний параметр
	{ 1392	,1	,1	, &internal1_m2042_q0},	//(internal1_m2042_q0) q0 - внутренний параметр
	{ 1393	,1	,1	, &internal1_m2108_q0},	//(internal1_m2108_q0) q0 - внутренний параметр
	{ 1394	,1	,1	, &internal1_m2079_q0},	//(internal1_m2079_q0) q0 - внутренний параметр
	{ 1395	,1	,1	, &internal1_m2068_q0},	//(internal1_m2068_q0) q0 - внутренний параметр
	{ 1396	,1	,1	, &internal1_m1636_q0},	//(internal1_m1636_q0) q0 - внутренний параметр
	{ 1397	,1	,1	, &internal1_m1623_x0},	//(internal1_m1623_x0) был приход сигнала x1
	{ 1398	,8	,1	, &internal1_m1623_y0},	//(internal1_m1623_y0) интервал между сигналами х1 и х2
	{ 1399	,1	,1	, &internal1_m1619_q0},	//(internal1_m1619_q0) q0 - внутренний параметр
	{ 1400	,1	,1	, &internal1_m1610_q0},	//(internal1_m1610_q0) q0 - внутренний параметр
	{ 1401	,1	,1	, &internal1_m1669_q0},	//(internal1_m1669_q0) q0 - внутренний параметр
	{ 1402	,1	,1	, &internal1_m1689_q0},	//(internal1_m1689_q0) q0 - внутренний параметр
	{ 1403	,1	,1	, &internal1_m1654_q0},	//(internal1_m1654_q0) q0 - внутренний параметр
	{ 1404	,1	,1	, &internal1_m1670_x0},	//(internal1_m1670_x0) был приход сигнала x1
	{ 1405	,8	,1	, &internal1_m1670_y0},	//(internal1_m1670_y0) интервал между сигналами х1 и х2
	{ 1406	,5	,1	, &internal1_m1590_x0},	//(internal1_m1590_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1407	,1	,1	, &internal1_m1675_q0},	//(internal1_m1675_q0) q0 - внутренний параметр
	{ 1408	,1	,1	, &internal1_m26_q0},	//(internal1_m26_q0) q0 - внутренний параметр
	{ 1409	,1	,1	, &internal1_m1690_q0},	//(internal1_m1690_q0) q0 - внутренний параметр
	{ 1410	,1	,1	, &internal1_m706_q0},	//(internal1_m706_q0) q0 - внутренний параметр
	{ 1411	,1	,1	, &internal1_m691_q0},	//(internal1_m691_q0) q0 - внутренний параметр
	{ 1412	,1	,1	, &internal1_m719_q0},	//(internal1_m719_q0) q0 - внутренний параметр
	{ 1413	,1	,1	, &internal1_m702_q0},	//(internal1_m702_q0) q0 - внутренний параметр
	{ 1414	,1	,1	, &internal1_m686_q0},	//(internal1_m686_q0) q0 - внутренний параметр
	{ 1415	,1	,1	, &internal1_m684_q0},	//(internal1_m684_q0) q0 - внутренний параметр
	{ 1416	,1	,1	, &internal1_m672_q0},	//(internal1_m672_q0) q0 - внутренний параметр
	{ 1417	,5	,1	, &internal1_m1575_q0},	//(internal1_m1575_q0) q0 - внутренний параметр
	{ 1418	,1	,1	, &internal1_m682_q0},	//(internal1_m682_q0) q0 - внутренний параметр
	{ 1419	,1	,1	, &internal1_m116_q0},	//(internal1_m116_q0) q0 - внутренний параметр
	{ 1420	,1	,1	, &internal1_m1836_q0},	//(internal1_m1836_q0) q0 - внутренний параметр
	{ 1421	,1	,1	, &internal1_m1835_q0},	//(internal1_m1835_q0) q0 - внутренний параметр
	{ 1422	,1	,1	, &internal1_m1834_q0},	//(internal1_m1834_q0) q0 - внутренний параметр
	{ 1423	,1	,1	, &internal1_m1833_q0},	//(internal1_m1833_q0) q0 - внутренний параметр
	{ 1424	,1	,1	, &internal1_m1869_q0},	//(internal1_m1869_q0) q0 - внутренний параметр
	{ 1425	,1	,1	, &internal1_m1868_q0},	//(internal1_m1868_q0) q0 - внутренний параметр
	{ 1426	,1	,1	, &internal1_m1867_q0},	//(internal1_m1867_q0) q0 - внутренний параметр
	{ 1427	,1	,1	, &internal1_m2139_q0},	//(internal1_m2139_q0) q0 - внутренний параметр
	{ 1428	,1	,1	, &internal1_m1929_q0},	//(internal1_m1929_q0) q0 - внутренний параметр
	{ 1429	,1	,1	, &internal1_m1918_q0},	//(internal1_m1918_q0) q0 - внутренний параметр
	{ 1430	,1	,1	, &internal1_m1926_q0},	//(internal1_m1926_q0) q0 - внутренний параметр
	{ 1431	,1	,1	, &internal1_m1915_q0},	//(internal1_m1915_q0) q0 - внутренний параметр
	{ 1432	,1	,1	, &internal1_m1923_q0},	//(internal1_m1923_q0) q0 - внутренний параметр
	{ 1433	,1	,1	, &internal1_m2353_q0},	//(internal1_m2353_q0) q0 - внутренний параметр
	{ 1434	,1	,1	, &internal1_m2349_q0},	//(internal1_m2349_q0) q0 - внутренний параметр
	{ 1435	,1	,1	, &internal1_m1894_q0},	//(internal1_m1894_q0) q0 - внутренний параметр
	{ 1436	,1	,1	, &internal1_m1886_q0},	//(internal1_m1886_q0) q0 - внутренний параметр
	{ 1437	,1	,1	, &internal1_m1884_q0},	//(internal1_m1884_q0) q0 - внутренний параметр
	{ 1438	,1	,1	, &internal1_m1880_q0},	//(internal1_m1880_q0) q0 - внутренний параметр
	{ 1439	,1	,1	, &internal1_m1876_q0},	//(internal1_m1876_q0) q0 - внутренний параметр
	{ 1440	,1	,1	, &internal1_m1878_q0},	//(internal1_m1878_q0) q0 - внутренний параметр
	{ 1441	,1	,1	, &internal1_m19_q0},	//(internal1_m19_q0) q0 - внутренний параметр
	{ 1442	,1	,1	, &internal1_m1859_q0},	//(internal1_m1859_q0) q0 - внутренний параметр
	{ 1443	,1	,1	, &internal1_m1857_q0},	//(internal1_m1857_q0) q0 - внутренний параметр
	{ 1444	,1	,1	, &internal1_m1853_q0},	//(internal1_m1853_q0) q0 - внутренний параметр
	{ 1445	,1	,1	, &internal1_m1855_q0},	//(internal1_m1855_q0) q0 - внутренний параметр
	{ 1446	,1	,1	, &internal1_m1851_q0},	//(internal1_m1851_q0) q0 - внутренний параметр
	{ 1447	,1	,1	, &internal1_m1849_q0},	//(internal1_m1849_q0) q0 - внутренний параметр
	{ 1448	,1	,1	, &internal1_m2264_q0},	//(internal1_m2264_q0) q0 - внутренний параметр
	{ 1449	,1	,1	, &internal1_m2259_q0},	//(internal1_m2259_q0) q0 - внутренний параметр
	{ 1450	,1	,1	, &internal1_m2236_q0},	//(internal1_m2236_q0) q0 - внутренний параметр
	{ 1451	,1	,1	, &internal1_m2220_q0},	//(internal1_m2220_q0) q0 - внутренний параметр
	{ 1452	,1	,1	, &internal1_m2151_q0},	//(internal1_m2151_q0) q0 - внутренний параметр
	{ 1453	,1	,1	, &internal1_m1845_q0},	//(internal1_m1845_q0) q0 - внутренний параметр
	{ 1454	,1	,1	, &internal1_m1847_q0},	//(internal1_m1847_q0) q0 - внутренний параметр
	{ 1455	,1	,1	, &internal1_m1831_q0},	//(internal1_m1831_q0) q0 - внутренний параметр
	{ 1456	,1	,1	, &internal1_m1829_q0},	//(internal1_m1829_q0) q0 - внутренний параметр
	{ 1457	,1	,1	, &internal1_m1827_q0},	//(internal1_m1827_q0) q0 - внутренний параметр
	{ 1458	,1	,1	, &internal1_m1825_q0},	//(internal1_m1825_q0) q0 - внутренний параметр
	{ 1459	,1	,1	, &internal1_m1824_q0},	//(internal1_m1824_q0) q0 - внутренний параметр
	{ 1460	,1	,1	, &internal1_m1822_q0},	//(internal1_m1822_q0) q0 - внутренний параметр
	{ 1461	,1	,1	, &internal1_m1821_q0},	//(internal1_m1821_q0) q0 - внутренний параметр
	{ 1462	,1	,1	, &internal1_m1819_q0},	//(internal1_m1819_q0) q0 - внутренний параметр
	{ 1463	,18	,1	, &internal1_m2290_DvUp0},	//(internal1_m2290_DvUp0) - есть команда на движение вперёд
	{ 1464	,18	,1	, &internal1_m2290_DvDw0},	//(internal1_m2290_DvDw0) - есть команда на движение назад
	{ 1465	,18	,1	, &internal1_m2290_FDvUp0},	//(internal1_m2290_FDvUp0) - есть команда на движение вперёд
	{ 1466	,18	,1	, &internal1_m2290_FDvDw0},	//(internal1_m2290_FDvDw0) - есть команда на движение назад
	{ 1467	,18	,1	, &internal1_m2290_BlDv0},	//(internal1_m2290_BlDv0) - была блокировка
	{ 1468	,18	,1	, &internal1_m2290_Pkv0},	//(internal1_m2290_Pkv0) Pkv - передний конечный выключатель
	{ 1469	,18	,1	, &internal1_m2290_Pkav0},	//(internal1_m2290_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1470	,18	,1	, &internal1_m2290_Zkv0},	//(internal1_m2290_Zkv0) Zkv - задний конечный выключатель
	{ 1471	,18	,1	, &internal1_m2290_Zkav0},	//(internal1_m2290_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1472	,8	,1	, &internal1_m2290_txNm},	//(internal1_m2290_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1473	,8	,1	, &internal1_m2290_txSm},	//(internal1_m2290_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1474	,8	,1	, &internal1_m2290_txHr},	//(internal1_m2290_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1475	,8	,1	, &internal1_m2290_txLd},	//(internal1_m2290_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1476	,18	,1	, &internal1_m2290_fef},	//(internal1_m2290_fef) fef
	{ 1477	,18	,1	, &internal1_m2284_DvUp0},	//(internal1_m2284_DvUp0) - есть команда на движение вперёд
	{ 1478	,18	,1	, &internal1_m2284_DvDw0},	//(internal1_m2284_DvDw0) - есть команда на движение назад
	{ 1479	,18	,1	, &internal1_m2284_FDvUp0},	//(internal1_m2284_FDvUp0) - есть команда на движение вперёд
	{ 1480	,18	,1	, &internal1_m2284_FDvDw0},	//(internal1_m2284_FDvDw0) - есть команда на движение назад
	{ 1481	,18	,1	, &internal1_m2284_BlDv0},	//(internal1_m2284_BlDv0) - была блокировка
	{ 1482	,18	,1	, &internal1_m2284_Pkv0},	//(internal1_m2284_Pkv0) Pkv - передний конечный выключатель
	{ 1483	,18	,1	, &internal1_m2284_Pkav0},	//(internal1_m2284_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1484	,18	,1	, &internal1_m2284_Zkv0},	//(internal1_m2284_Zkv0) Zkv - задний конечный выключатель
	{ 1485	,18	,1	, &internal1_m2284_Zkav0},	//(internal1_m2284_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1486	,8	,1	, &internal1_m2284_txNm},	//(internal1_m2284_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1487	,8	,1	, &internal1_m2284_txSm},	//(internal1_m2284_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1488	,8	,1	, &internal1_m2284_txHr},	//(internal1_m2284_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1489	,8	,1	, &internal1_m2284_txLd},	//(internal1_m2284_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1490	,18	,1	, &internal1_m2284_fef},	//(internal1_m2284_fef) fef
	{ 1491	,1	,1	, &internal1_m1661_q0},	//(internal1_m1661_q0) q0 - внутренний параметр
	{ 1492	,1	,1	, &internal1_m1664_x0},	//(internal1_m1664_x0) был приход сигнала x1
	{ 1493	,8	,1	, &internal1_m1664_y0},	//(internal1_m1664_y0) интервал между сигналами х1 и х2
	{ 1494	,1	,1	, &internal1_m2090_x0},	//(internal1_m2090_x0) был приход сигнала x1
	{ 1495	,8	,1	, &internal1_m2090_y0},	//(internal1_m2090_y0) интервал между сигналами х1 и х2
	{ 1496	,1	,1	, &internal1_m2050_x0},	//(internal1_m2050_x0) был приход сигнала x1
	{ 1497	,8	,1	, &internal1_m2050_y0},	//(internal1_m2050_y0) интервал между сигналами х1 и х2
	{ 1498	,1	,1	, &internal1_m304_q0},	//(internal1_m304_q0) q0 - внутренний параметр
	{ 1499	,1	,1	, &internal1_m1119_q0},	//(internal1_m1119_q0) q0 - внутренний параметр
	{ 1500	,1	,1	, &internal1_m694_q0},	//(internal1_m694_q0) q0 - внутренний параметр
	{ 1501	,8	,1	, &internal1_m1456_X0},	//(internal1_m1456_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1502	,8	,1	, &internal1_m1456_t0},	//(internal1_m1456_t0) время нахождения в зоне возврата
	{ 1503	,18	,1	, &internal1_m1456_BLDv0},	//(internal1_m1456_BLDv0) BlDv - Блокировка движения
	{ 1504	,8	,1	, &internal1_m1473_tx},	//(internal1_m1473_tx) tx - время накопленное сек
	{ 1505	,18	,1	, &internal1_m1473_y0},	//(internal1_m1473_y0) y0
	{ 1506	,8	,1	, &internal1_m1474_tx},	//(internal1_m1474_tx) tx - время накопленное сек
	{ 1507	,18	,1	, &internal1_m1474_y0},	//(internal1_m1474_y0) y0
	{ 1508	,3	,1	, &internal1_m1482_xptr},	//(internal1_m1482_xptr) указатель текущей позиции в массиве координат
	{ 1509	,8	,60	, &internal1_m1482_x0},	//(internal1_m1482_x0) x0 - массив мгновенных значений координат
	{ 1510	,8	,60	, &internal1_m1482_tim0},	//(internal1_m1482_tim0) tim0 - массив значений времени цикла
	{ 1511	,8	,1	, &internal1_m1482_sumtim},	//(internal1_m1482_sumtim) sumtim - время в пути
	{ 1512	,8	,1	, &internal1_m1482_StSpeed},	//(internal1_m1482_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1513	,8	,1	, &internal1_m1482_Vz0},	//(internal1_m1482_Vz0) Vz0 - предыдущая заданная скорость
	{ 1514	,3	,1	, &internal1_m1482_flRazg},	//(internal1_m1482_flRazg) признак разгона/торможения
	{ 1515	,8	,1	, &internal1_m1482_DelSp},	//(internal1_m1482_DelSp) DelSp - время переключения скоростей
	{ 1516	,8	,1	, &internal1_m1482_z0},	//(internal1_m1482_z0) z0 - точка прекращения движения
	{ 1517	,8	,1	, &internal1_m1482_txZS},	//(internal1_m1482_txZS) txZS
	{ 1518	,8	,1	, &internal1_m1482_tx},	//(internal1_m1482_tx) tx
	{ 1519	,8	,1	, &internal1_m1482_txd},	//(internal1_m1482_txd) txd
	{ 1520	,8	,1	, &internal1_m1482_txMBl},	//(internal1_m1482_txMBl) tx
	{ 1521	,8	,1	, &internal1_m1482_txBl},	//(internal1_m1482_txBl) tx
	{ 1522	,8	,1	, &internal1_m1482_Speed0},	//(internal1_m1482_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1523	,8	,1	, &internal1_m1482_xz0},	//(internal1_m1482_xz0) xz0 - новое задание мм
	{ 1524	,8	,1	, &internal1_m1482_tz0},	//(internal1_m1482_tz0) tz0 - время защиты от нового задания сек
	{ 1525	,1	,1	, &internal1_m1482_Shift0},	//(internal1_m1482_Shift0) Shift0 - признак самохода
	{ 1526	,1	,1	, &internal1_m1482_ShCntlSp0},	//(internal1_m1482_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1527	,1	,1	, &internal1_m1482_ShiftControl},	//(internal1_m1482_ShiftControl) ShiftControl - признак самохода
	{ 1528	,1	,1	, &internal1_m692_q0},	//(internal1_m692_q0) q0 - внутренний параметр
	{ 1529	,8	,1	, &internal1_m1000_X0},	//(internal1_m1000_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1530	,8	,1	, &internal1_m1000_t0},	//(internal1_m1000_t0) время нахождения в зоне возврата
	{ 1531	,18	,1	, &internal1_m1000_BLDv0},	//(internal1_m1000_BLDv0) BlDv - Блокировка движения
	{ 1532	,8	,1	, &internal1_m1023_tx},	//(internal1_m1023_tx) tx - время накопленное сек
	{ 1533	,18	,1	, &internal1_m1023_y0},	//(internal1_m1023_y0) y0
	{ 1534	,8	,1	, &internal1_m1022_tx},	//(internal1_m1022_tx) tx - время накопленное сек
	{ 1535	,18	,1	, &internal1_m1022_y0},	//(internal1_m1022_y0) y0
	{ 1536	,3	,1	, &internal1_m1030_xptr},	//(internal1_m1030_xptr) указатель текущей позиции в массиве координат
	{ 1537	,8	,60	, &internal1_m1030_x0},	//(internal1_m1030_x0) x0 - массив мгновенных значений координат
	{ 1538	,8	,60	, &internal1_m1030_tim0},	//(internal1_m1030_tim0) tim0 - массив значений времени цикла
	{ 1539	,8	,1	, &internal1_m1030_sumtim},	//(internal1_m1030_sumtim) sumtim - время в пути
	{ 1540	,8	,1	, &internal1_m1030_StSpeed},	//(internal1_m1030_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1541	,8	,1	, &internal1_m1030_Vz0},	//(internal1_m1030_Vz0) Vz0 - предыдущая заданная скорость
	{ 1542	,3	,1	, &internal1_m1030_flRazg},	//(internal1_m1030_flRazg) признак разгона/торможения
	{ 1543	,8	,1	, &internal1_m1030_DelSp},	//(internal1_m1030_DelSp) DelSp - время переключения скоростей
	{ 1544	,8	,1	, &internal1_m1030_z0},	//(internal1_m1030_z0) z0 - точка прекращения движения
	{ 1545	,8	,1	, &internal1_m1030_txZS},	//(internal1_m1030_txZS) txZS
	{ 1546	,8	,1	, &internal1_m1030_tx},	//(internal1_m1030_tx) tx
	{ 1547	,8	,1	, &internal1_m1030_txd},	//(internal1_m1030_txd) txd
	{ 1548	,8	,1	, &internal1_m1030_txMBl},	//(internal1_m1030_txMBl) tx
	{ 1549	,8	,1	, &internal1_m1030_txBl},	//(internal1_m1030_txBl) tx
	{ 1550	,8	,1	, &internal1_m1030_Speed0},	//(internal1_m1030_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1551	,8	,1	, &internal1_m1030_xz0},	//(internal1_m1030_xz0) xz0 - новое задание мм
	{ 1552	,8	,1	, &internal1_m1030_tz0},	//(internal1_m1030_tz0) tz0 - время защиты от нового задания сек
	{ 1553	,1	,1	, &internal1_m1030_Shift0},	//(internal1_m1030_Shift0) Shift0 - признак самохода
	{ 1554	,1	,1	, &internal1_m1030_ShCntlSp0},	//(internal1_m1030_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1555	,1	,1	, &internal1_m1030_ShiftControl},	//(internal1_m1030_ShiftControl) ShiftControl - признак самохода
	{ 1556	,8	,1	, &internal1_m545_X0},	//(internal1_m545_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1557	,8	,1	, &internal1_m545_t0},	//(internal1_m545_t0) время нахождения в зоне возврата
	{ 1558	,18	,1	, &internal1_m545_BLDv0},	//(internal1_m545_BLDv0) BlDv - Блокировка движения
	{ 1559	,8	,1	, &internal1_m564_tx},	//(internal1_m564_tx) tx - время накопленное сек
	{ 1560	,18	,1	, &internal1_m564_y0},	//(internal1_m564_y0) y0
	{ 1561	,8	,1	, &internal1_m563_tx},	//(internal1_m563_tx) tx - время накопленное сек
	{ 1562	,18	,1	, &internal1_m563_y0},	//(internal1_m563_y0) y0
	{ 1563	,3	,1	, &internal1_m568_xptr},	//(internal1_m568_xptr) указатель текущей позиции в массиве координат
	{ 1564	,8	,150	, &internal1_m568_x0},	//(internal1_m568_x0) x0 - массив мгновенных значений координат
	{ 1565	,8	,150	, &internal1_m568_tim0},	//(internal1_m568_tim0) tim0 - массив значений времени цикла
	{ 1566	,8	,1	, &internal1_m568_sumtim},	//(internal1_m568_sumtim) sumtim - время в пути
	{ 1567	,8	,1	, &internal1_m568_StSpeed},	//(internal1_m568_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1568	,8	,1	, &internal1_m568_Vz0},	//(internal1_m568_Vz0) Vz0 - предыдущая заданная скорость
	{ 1569	,3	,1	, &internal1_m568_flRazg},	//(internal1_m568_flRazg) признак разгона/торможения
	{ 1570	,8	,1	, &internal1_m568_DelSp},	//(internal1_m568_DelSp) DelSp - время переключения скоростей
	{ 1571	,8	,1	, &internal1_m568_z0},	//(internal1_m568_z0) z0 - точка прекращения движения
	{ 1572	,8	,1	, &internal1_m568_txZS},	//(internal1_m568_txZS) txZS
	{ 1573	,8	,1	, &internal1_m568_tx},	//(internal1_m568_tx) tx
	{ 1574	,8	,1	, &internal1_m568_txd},	//(internal1_m568_txd) txd
	{ 1575	,8	,1	, &internal1_m568_txMBl},	//(internal1_m568_txMBl) tx
	{ 1576	,8	,1	, &internal1_m568_txBl},	//(internal1_m568_txBl) tx
	{ 1577	,8	,1	, &internal1_m568_Speed0},	//(internal1_m568_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1578	,8	,1	, &internal1_m568_xz0},	//(internal1_m568_xz0) xz0 - новое задание мм
	{ 1579	,8	,1	, &internal1_m568_tz0},	//(internal1_m568_tz0) tz0 - время защиты от нового задания сек
	{ 1580	,1	,1	, &internal1_m568_Shift0},	//(internal1_m568_Shift0) Shift0 - признак самохода
	{ 1581	,1	,1	, &internal1_m568_ShCntlSp0},	//(internal1_m568_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1582	,1	,1	, &internal1_m568_ShiftControl},	//(internal1_m568_ShiftControl) ShiftControl - признак самохода
	{ 1583	,1	,1	, &internal1_m689_q0},	//(internal1_m689_q0) q0 - внутренний параметр
	{ 1584	,8	,1	, &internal1_m175_X0},	//(internal1_m175_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1585	,8	,1	, &internal1_m175_t0},	//(internal1_m175_t0) время нахождения в зоне возврата
	{ 1586	,18	,1	, &internal1_m175_BLDv0},	//(internal1_m175_BLDv0) BlDv - Блокировка движения
	{ 1587	,3	,1	, &internal1_m200_xptr},	//(internal1_m200_xptr) указатель текущей позиции в массиве координат
	{ 1588	,8	,150	, &internal1_m200_x0},	//(internal1_m200_x0) x0 - массив мгновенных значений координат
	{ 1589	,8	,150	, &internal1_m200_tim0},	//(internal1_m200_tim0) tim0 - массив значений времени цикла
	{ 1590	,8	,1	, &internal1_m200_sumtim},	//(internal1_m200_sumtim) sumtim - время в пути
	{ 1591	,8	,1	, &internal1_m200_StSpeed},	//(internal1_m200_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1592	,8	,1	, &internal1_m200_Vz0},	//(internal1_m200_Vz0) Vz0 - предыдущая заданная скорость
	{ 1593	,3	,1	, &internal1_m200_flRazg},	//(internal1_m200_flRazg) признак разгона/торможения
	{ 1594	,8	,1	, &internal1_m200_DelSp},	//(internal1_m200_DelSp) DelSp - время переключения скоростей
	{ 1595	,8	,1	, &internal1_m200_z0},	//(internal1_m200_z0) z0 - точка прекращения движения
	{ 1596	,8	,1	, &internal1_m200_txZS},	//(internal1_m200_txZS) txZS
	{ 1597	,8	,1	, &internal1_m200_tx},	//(internal1_m200_tx) tx
	{ 1598	,8	,1	, &internal1_m200_txd},	//(internal1_m200_txd) txd
	{ 1599	,8	,1	, &internal1_m200_txMBl},	//(internal1_m200_txMBl) tx
	{ 1600	,8	,1	, &internal1_m200_txBl},	//(internal1_m200_txBl) tx
	{ 1601	,8	,1	, &internal1_m200_Speed0},	//(internal1_m200_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1602	,8	,1	, &internal1_m200_xz0},	//(internal1_m200_xz0) xz0 - новое задание мм
	{ 1603	,8	,1	, &internal1_m200_tz0},	//(internal1_m200_tz0) tz0 - время защиты от нового задания сек
	{ 1604	,1	,1	, &internal1_m200_Shift0},	//(internal1_m200_Shift0) Shift0 - признак самохода
	{ 1605	,1	,1	, &internal1_m200_ShCntlSp0},	//(internal1_m200_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1606	,1	,1	, &internal1_m200_ShiftControl},	//(internal1_m200_ShiftControl) ShiftControl - признак самохода
	{ 1607	,1	,1	, &internal1_m715_q0},	//(internal1_m715_q0) q0 - внутренний параметр
	{ 1608	,18	,1	, &internal1_m512_DvUp0},	//(internal1_m512_DvUp0) - есть команда на движение вперёд
	{ 1609	,18	,1	, &internal1_m512_DvDw0},	//(internal1_m512_DvDw0) - есть команда на движение назад
	{ 1610	,18	,1	, &internal1_m512_FDvUp0},	//(internal1_m512_FDvUp0) - есть команда на движение вперёд
	{ 1611	,18	,1	, &internal1_m512_FDvDw0},	//(internal1_m512_FDvDw0) - есть команда на движение назад
	{ 1612	,18	,1	, &internal1_m512_BlDv0},	//(internal1_m512_BlDv0) - была блокировка
	{ 1613	,18	,1	, &internal1_m512_Pkv0},	//(internal1_m512_Pkv0) Pkv - передний конечный выключатель
	{ 1614	,18	,1	, &internal1_m512_Pkav0},	//(internal1_m512_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1615	,18	,1	, &internal1_m512_Zkv0},	//(internal1_m512_Zkv0) Zkv - задний конечный выключатель
	{ 1616	,18	,1	, &internal1_m512_Zkav0},	//(internal1_m512_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1617	,8	,1	, &internal1_m512_txNm},	//(internal1_m512_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1618	,8	,1	, &internal1_m512_txSm},	//(internal1_m512_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1619	,8	,1	, &internal1_m512_txHr},	//(internal1_m512_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1620	,8	,1	, &internal1_m512_txLd},	//(internal1_m512_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1621	,18	,1	, &internal1_m512_fef},	//(internal1_m512_fef) fef
	{ 1622	,18	,1	, &internal1_m506_DvUp0},	//(internal1_m506_DvUp0) - есть команда на движение вперёд
	{ 1623	,18	,1	, &internal1_m506_DvDw0},	//(internal1_m506_DvDw0) - есть команда на движение назад
	{ 1624	,18	,1	, &internal1_m506_FDvUp0},	//(internal1_m506_FDvUp0) - есть команда на движение вперёд
	{ 1625	,18	,1	, &internal1_m506_FDvDw0},	//(internal1_m506_FDvDw0) - есть команда на движение назад
	{ 1626	,18	,1	, &internal1_m506_BlDv0},	//(internal1_m506_BlDv0) - была блокировка
	{ 1627	,18	,1	, &internal1_m506_Pkv0},	//(internal1_m506_Pkv0) Pkv - передний конечный выключатель
	{ 1628	,18	,1	, &internal1_m506_Pkav0},	//(internal1_m506_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1629	,18	,1	, &internal1_m506_Zkv0},	//(internal1_m506_Zkv0) Zkv - задний конечный выключатель
	{ 1630	,18	,1	, &internal1_m506_Zkav0},	//(internal1_m506_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1631	,8	,1	, &internal1_m506_txNm},	//(internal1_m506_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1632	,8	,1	, &internal1_m506_txSm},	//(internal1_m506_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1633	,8	,1	, &internal1_m506_txHr},	//(internal1_m506_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1634	,8	,1	, &internal1_m506_txLd},	//(internal1_m506_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1635	,18	,1	, &internal1_m506_fef},	//(internal1_m506_fef) fef
	{ 1636	,8	,1	, &internal1_m904_X0},	//(internal1_m904_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1637	,8	,1	, &internal1_m904_t0},	//(internal1_m904_t0) время нахождения в зоне возврата
	{ 1638	,18	,1	, &internal1_m904_BLDv0},	//(internal1_m904_BLDv0) BlDv - Блокировка движения
	{ 1639	,3	,1	, &internal1_m922_xptr},	//(internal1_m922_xptr) указатель текущей позиции в массиве координат
	{ 1640	,8	,80	, &internal1_m922_x0},	//(internal1_m922_x0) x0 - массив мгновенных значений координат
	{ 1641	,8	,80	, &internal1_m922_tim0},	//(internal1_m922_tim0) tim0 - массив значений времени цикла
	{ 1642	,8	,1	, &internal1_m922_sumtim},	//(internal1_m922_sumtim) sumtim - время в пути
	{ 1643	,8	,1	, &internal1_m922_StSpeed},	//(internal1_m922_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1644	,8	,1	, &internal1_m922_Vz0},	//(internal1_m922_Vz0) Vz0 - предыдущая заданная скорость
	{ 1645	,3	,1	, &internal1_m922_flRazg},	//(internal1_m922_flRazg) признак разгона/торможения
	{ 1646	,8	,1	, &internal1_m922_DelSp},	//(internal1_m922_DelSp) DelSp - время переключения скоростей
	{ 1647	,8	,1	, &internal1_m922_z0},	//(internal1_m922_z0) z0 - точка прекращения движения
	{ 1648	,8	,1	, &internal1_m922_txZS},	//(internal1_m922_txZS) txZS
	{ 1649	,8	,1	, &internal1_m922_tx},	//(internal1_m922_tx) tx
	{ 1650	,8	,1	, &internal1_m922_txd},	//(internal1_m922_txd) txd
	{ 1651	,8	,1	, &internal1_m922_txMBl},	//(internal1_m922_txMBl) tx
	{ 1652	,8	,1	, &internal1_m922_txBl},	//(internal1_m922_txBl) tx
	{ 1653	,8	,1	, &internal1_m922_Speed0},	//(internal1_m922_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1654	,8	,1	, &internal1_m922_xz0},	//(internal1_m922_xz0) xz0 - новое задание мм
	{ 1655	,8	,1	, &internal1_m922_tz0},	//(internal1_m922_tz0) tz0 - время защиты от нового задания сек
	{ 1656	,1	,1	, &internal1_m922_Shift0},	//(internal1_m922_Shift0) Shift0 - признак самохода
	{ 1657	,1	,1	, &internal1_m922_ShCntlSp0},	//(internal1_m922_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1658	,1	,1	, &internal1_m922_ShiftControl},	//(internal1_m922_ShiftControl) ShiftControl - признак самохода
	{ 1659	,8	,1	, &internal1_m1773_X0},	//(internal1_m1773_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1660	,8	,1	, &internal1_m1773_t0},	//(internal1_m1773_t0) время нахождения в зоне возврата
	{ 1661	,18	,1	, &internal1_m1773_BLDv0},	//(internal1_m1773_BLDv0) BlDv - Блокировка движения
	{ 1662	,8	,1	, &internal1_m1246_X0},	//(internal1_m1246_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1663	,8	,1	, &internal1_m1246_t0},	//(internal1_m1246_t0) время нахождения в зоне возврата
	{ 1664	,18	,1	, &internal1_m1246_BLDv0},	//(internal1_m1246_BLDv0) BlDv - Блокировка движения
	{ 1665	,1	,1	, &internal1_m687_q0},	//(internal1_m687_q0) q0 - внутренний параметр
	{ 1666	,8	,1	, &internal1_m1343_X0},	//(internal1_m1343_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1667	,8	,1	, &internal1_m1343_t0},	//(internal1_m1343_t0) время нахождения в зоне возврата
	{ 1668	,18	,1	, &internal1_m1343_BLDv0},	//(internal1_m1343_BLDv0) BlDv - Блокировка движения
	{ 1669	,8	,1	, &internal1_m1371_tx},	//(internal1_m1371_tx) tx - время накопленное сек
	{ 1670	,18	,1	, &internal1_m1371_y0},	//(internal1_m1371_y0) y0
	{ 1671	,8	,1	, &internal1_m1370_tx},	//(internal1_m1370_tx) tx - время накопленное сек
	{ 1672	,18	,1	, &internal1_m1370_y0},	//(internal1_m1370_y0) y0
	{ 1673	,3	,1	, &internal1_m1378_xptr},	//(internal1_m1378_xptr) указатель текущей позиции в массиве координат
	{ 1674	,8	,80	, &internal1_m1378_x0},	//(internal1_m1378_x0) x0 - массив мгновенных значений координат
	{ 1675	,8	,80	, &internal1_m1378_tim0},	//(internal1_m1378_tim0) tim0 - массив значений времени цикла
	{ 1676	,8	,1	, &internal1_m1378_sumtim},	//(internal1_m1378_sumtim) sumtim - время в пути
	{ 1677	,8	,1	, &internal1_m1378_StSpeed},	//(internal1_m1378_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1678	,8	,1	, &internal1_m1378_Vz0},	//(internal1_m1378_Vz0) Vz0 - предыдущая заданная скорость
	{ 1679	,3	,1	, &internal1_m1378_flRazg},	//(internal1_m1378_flRazg) признак разгона/торможения
	{ 1680	,8	,1	, &internal1_m1378_DelSp},	//(internal1_m1378_DelSp) DelSp - время переключения скоростей
	{ 1681	,8	,1	, &internal1_m1378_z0},	//(internal1_m1378_z0) z0 - точка прекращения движения
	{ 1682	,8	,1	, &internal1_m1378_txZS},	//(internal1_m1378_txZS) txZS
	{ 1683	,8	,1	, &internal1_m1378_tx},	//(internal1_m1378_tx) tx
	{ 1684	,8	,1	, &internal1_m1378_txd},	//(internal1_m1378_txd) txd
	{ 1685	,8	,1	, &internal1_m1378_txMBl},	//(internal1_m1378_txMBl) tx
	{ 1686	,8	,1	, &internal1_m1378_txBl},	//(internal1_m1378_txBl) tx
	{ 1687	,8	,1	, &internal1_m1378_Speed0},	//(internal1_m1378_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1688	,8	,1	, &internal1_m1378_xz0},	//(internal1_m1378_xz0) xz0 - новое задание мм
	{ 1689	,8	,1	, &internal1_m1378_tz0},	//(internal1_m1378_tz0) tz0 - время защиты от нового задания сек
	{ 1690	,1	,1	, &internal1_m1378_Shift0},	//(internal1_m1378_Shift0) Shift0 - признак самохода
	{ 1691	,1	,1	, &internal1_m1378_ShCntlSp0},	//(internal1_m1378_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1692	,1	,1	, &internal1_m1378_ShiftControl},	//(internal1_m1378_ShiftControl) ShiftControl - признак самохода
	{ 1693	,1	,1	, &internal1_m707_q0},	//(internal1_m707_q0) q0 - внутренний параметр
	{ 1694	,8	,1	, &internal1_m1787_tx},	//(internal1_m1787_tx) tx - время накопленное сек
	{ 1695	,18	,1	, &internal1_m1787_y0},	//(internal1_m1787_y0) y0
	{ 1696	,8	,1	, &internal1_m1791_tx},	//(internal1_m1791_tx) tx - время накопленное сек
	{ 1697	,18	,1	, &internal1_m1791_y0},	//(internal1_m1791_y0) y0
	{ 1698	,18	,1	, &internal1_m1776_DvUp0},	//(internal1_m1776_DvUp0) - есть команда на движение вперёд
	{ 1699	,18	,1	, &internal1_m1776_DvDw0},	//(internal1_m1776_DvDw0) - есть команда на движение назад
	{ 1700	,18	,1	, &internal1_m1776_FDvUp0},	//(internal1_m1776_FDvUp0) - есть команда на движение вперёд
	{ 1701	,18	,1	, &internal1_m1776_FDvDw0},	//(internal1_m1776_FDvDw0) - есть команда на движение назад
	{ 1702	,18	,1	, &internal1_m1776_BlDv0},	//(internal1_m1776_BlDv0) - была блокировка
	{ 1703	,18	,1	, &internal1_m1776_Pkv0},	//(internal1_m1776_Pkv0) Pkv - передний конечный выключатель
	{ 1704	,18	,1	, &internal1_m1776_Pkav0},	//(internal1_m1776_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1705	,18	,1	, &internal1_m1776_Zkv0},	//(internal1_m1776_Zkv0) Zkv - задний конечный выключатель
	{ 1706	,18	,1	, &internal1_m1776_Zkav0},	//(internal1_m1776_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1707	,8	,1	, &internal1_m1776_txNm},	//(internal1_m1776_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1708	,8	,1	, &internal1_m1776_txSm},	//(internal1_m1776_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1709	,8	,1	, &internal1_m1776_txHr},	//(internal1_m1776_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1710	,8	,1	, &internal1_m1776_txLd},	//(internal1_m1776_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1711	,18	,1	, &internal1_m1776_fef},	//(internal1_m1776_fef) fef
	{ 1712	,3	,1	, &internal1_m1795_xptr},	//(internal1_m1795_xptr) указатель текущей позиции в массиве координат
	{ 1713	,8	,20	, &internal1_m1795_x0},	//(internal1_m1795_x0) x0 - массив мгновенных значений координат
	{ 1714	,8	,20	, &internal1_m1795_tim0},	//(internal1_m1795_tim0) tim0 - массив значений времени цикла
	{ 1715	,8	,1	, &internal1_m1795_sumtim},	//(internal1_m1795_sumtim) sumtim - время в пути
	{ 1716	,8	,1	, &internal1_m1795_StSpeed},	//(internal1_m1795_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1717	,8	,1	, &internal1_m1795_Vz0},	//(internal1_m1795_Vz0) Vz0 - предыдущая заданная скорость
	{ 1718	,3	,1	, &internal1_m1795_flRazg},	//(internal1_m1795_flRazg) признак разгона/торможения
	{ 1719	,8	,1	, &internal1_m1795_DelSp},	//(internal1_m1795_DelSp) DelSp - время переключения скоростей
	{ 1720	,8	,1	, &internal1_m1795_z0},	//(internal1_m1795_z0) z0 - точка прекращения движения
	{ 1721	,8	,1	, &internal1_m1795_txZS},	//(internal1_m1795_txZS) txZS
	{ 1722	,8	,1	, &internal1_m1795_tx},	//(internal1_m1795_tx) tx
	{ 1723	,8	,1	, &internal1_m1795_txd},	//(internal1_m1795_txd) txd
	{ 1724	,8	,1	, &internal1_m1795_txMBl},	//(internal1_m1795_txMBl) tx
	{ 1725	,8	,1	, &internal1_m1795_txBl},	//(internal1_m1795_txBl) tx
	{ 1726	,8	,1	, &internal1_m1795_Speed0},	//(internal1_m1795_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1727	,8	,1	, &internal1_m1795_xz0},	//(internal1_m1795_xz0) xz0 - новое задание мм
	{ 1728	,8	,1	, &internal1_m1795_tz0},	//(internal1_m1795_tz0) tz0 - время защиты от нового задания сек
	{ 1729	,1	,1	, &internal1_m1795_Shift0},	//(internal1_m1795_Shift0) Shift0 - признак самохода
	{ 1730	,1	,1	, &internal1_m1795_ShCntlSp0},	//(internal1_m1795_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1731	,1	,1	, &internal1_m1795_ShiftControl},	//(internal1_m1795_ShiftControl) ShiftControl - признак самохода
	{ 1732	,8	,1	, &internal1_m1263_tx},	//(internal1_m1263_tx) tx - время накопленное сек
	{ 1733	,18	,1	, &internal1_m1263_y0},	//(internal1_m1263_y0) y0
	{ 1734	,8	,1	, &internal1_m1267_tx},	//(internal1_m1267_tx) tx - время накопленное сек
	{ 1735	,18	,1	, &internal1_m1267_y0},	//(internal1_m1267_y0) y0
	{ 1736	,1	,1	, &internal1_m697_q0},	//(internal1_m697_q0) q0 - внутренний параметр
	{ 1737	,1	,1	, &internal1_m662_q0},	//(internal1_m662_q0) q0 - внутренний параметр
	{ 1738	,18	,1	, &internal1_m1253_DvUp0},	//(internal1_m1253_DvUp0) - есть команда на движение вперёд
	{ 1739	,18	,1	, &internal1_m1253_DvDw0},	//(internal1_m1253_DvDw0) - есть команда на движение назад
	{ 1740	,18	,1	, &internal1_m1253_FDvUp0},	//(internal1_m1253_FDvUp0) - есть команда на движение вперёд
	{ 1741	,18	,1	, &internal1_m1253_FDvDw0},	//(internal1_m1253_FDvDw0) - есть команда на движение назад
	{ 1742	,18	,1	, &internal1_m1253_BlDv0},	//(internal1_m1253_BlDv0) - была блокировка
	{ 1743	,18	,1	, &internal1_m1253_Pkv0},	//(internal1_m1253_Pkv0) Pkv - передний конечный выключатель
	{ 1744	,18	,1	, &internal1_m1253_Pkav0},	//(internal1_m1253_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1745	,18	,1	, &internal1_m1253_Zkv0},	//(internal1_m1253_Zkv0) Zkv - задний конечный выключатель
	{ 1746	,18	,1	, &internal1_m1253_Zkav0},	//(internal1_m1253_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1747	,8	,1	, &internal1_m1253_txNm},	//(internal1_m1253_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1748	,8	,1	, &internal1_m1253_txSm},	//(internal1_m1253_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1749	,8	,1	, &internal1_m1253_txHr},	//(internal1_m1253_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1750	,8	,1	, &internal1_m1253_txLd},	//(internal1_m1253_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1751	,18	,1	, &internal1_m1253_fef},	//(internal1_m1253_fef) fef
	{ 1752	,3	,1	, &internal1_m1273_xptr},	//(internal1_m1273_xptr) указатель текущей позиции в массиве координат
	{ 1753	,8	,20	, &internal1_m1273_x0},	//(internal1_m1273_x0) x0 - массив мгновенных значений координат
	{ 1754	,8	,20	, &internal1_m1273_tim0},	//(internal1_m1273_tim0) tim0 - массив значений времени цикла
	{ 1755	,8	,1	, &internal1_m1273_sumtim},	//(internal1_m1273_sumtim) sumtim - время в пути
	{ 1756	,8	,1	, &internal1_m1273_StSpeed},	//(internal1_m1273_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1757	,8	,1	, &internal1_m1273_Vz0},	//(internal1_m1273_Vz0) Vz0 - предыдущая заданная скорость
	{ 1758	,3	,1	, &internal1_m1273_flRazg},	//(internal1_m1273_flRazg) признак разгона/торможения
	{ 1759	,8	,1	, &internal1_m1273_DelSp},	//(internal1_m1273_DelSp) DelSp - время переключения скоростей
	{ 1760	,8	,1	, &internal1_m1273_z0},	//(internal1_m1273_z0) z0 - точка прекращения движения
	{ 1761	,8	,1	, &internal1_m1273_txZS},	//(internal1_m1273_txZS) txZS
	{ 1762	,8	,1	, &internal1_m1273_tx},	//(internal1_m1273_tx) tx
	{ 1763	,8	,1	, &internal1_m1273_txd},	//(internal1_m1273_txd) txd
	{ 1764	,8	,1	, &internal1_m1273_txMBl},	//(internal1_m1273_txMBl) tx
	{ 1765	,8	,1	, &internal1_m1273_txBl},	//(internal1_m1273_txBl) tx
	{ 1766	,8	,1	, &internal1_m1273_Speed0},	//(internal1_m1273_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1767	,8	,1	, &internal1_m1273_xz0},	//(internal1_m1273_xz0) xz0 - новое задание мм
	{ 1768	,8	,1	, &internal1_m1273_tz0},	//(internal1_m1273_tz0) tz0 - время защиты от нового задания сек
	{ 1769	,1	,1	, &internal1_m1273_Shift0},	//(internal1_m1273_Shift0) Shift0 - признак самохода
	{ 1770	,1	,1	, &internal1_m1273_ShCntlSp0},	//(internal1_m1273_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1771	,1	,1	, &internal1_m1273_ShiftControl},	//(internal1_m1273_ShiftControl) ShiftControl - признак самохода
	{ 1772	,1	,1	, &internal1_m825_x0},	//(internal1_m825_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1773	,1	,1	, &internal1_m794_x0},	//(internal1_m794_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1774	,1	,1	, &internal1_m736_x0},	//(internal1_m736_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1775	,1	,1	, &internal1_m850_q0},	//(internal1_m850_q0) q0 - внутренний параметр
	{ 1776	,1	,1	, &internal1_m845_q0},	//(internal1_m845_q0) q0 - внутренний параметр
	{ 1777	,1	,1	, &internal1_m813_q0},	//(internal1_m813_q0) q0 - внутренний параметр
	{ 1778	,1	,1	, &internal1_m818_q0},	//(internal1_m818_q0) q0 - внутренний параметр
	{ 1779	,1	,1	, &internal1_m826_q0},	//(internal1_m826_q0) q0 - внутренний параметр
	{ 1780	,1	,1	, &internal1_m838_q0},	//(internal1_m838_q0) q0 - внутренний параметр
	{ 1781	,1	,1	, &internal1_m816_q0},	//(internal1_m816_q0) q0 - внутренний параметр
	{ 1782	,18	,1	, &internal1_m1316_DvUp0},	//(internal1_m1316_DvUp0) - есть команда на движение вперёд
	{ 1783	,18	,1	, &internal1_m1316_DvDw0},	//(internal1_m1316_DvDw0) - есть команда на движение назад
	{ 1784	,18	,1	, &internal1_m1316_FDvUp0},	//(internal1_m1316_FDvUp0) - есть команда на движение вперёд
	{ 1785	,18	,1	, &internal1_m1316_FDvDw0},	//(internal1_m1316_FDvDw0) - есть команда на движение назад
	{ 1786	,18	,1	, &internal1_m1316_BlDv0},	//(internal1_m1316_BlDv0) - была блокировка
	{ 1787	,18	,1	, &internal1_m1316_Pkv0},	//(internal1_m1316_Pkv0) Pkv - передний конечный выключатель
	{ 1788	,18	,1	, &internal1_m1316_Pkav0},	//(internal1_m1316_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1789	,18	,1	, &internal1_m1316_Zkv0},	//(internal1_m1316_Zkv0) Zkv - задний конечный выключатель
	{ 1790	,18	,1	, &internal1_m1316_Zkav0},	//(internal1_m1316_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1791	,8	,1	, &internal1_m1316_txNm},	//(internal1_m1316_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1792	,8	,1	, &internal1_m1316_txSm},	//(internal1_m1316_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1793	,8	,1	, &internal1_m1316_txHr},	//(internal1_m1316_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1794	,8	,1	, &internal1_m1316_txLd},	//(internal1_m1316_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1795	,18	,1	, &internal1_m1316_fef},	//(internal1_m1316_fef) fef
	{ 1796	,18	,1	, &internal1_m1306_DvUp0},	//(internal1_m1306_DvUp0) - есть команда на движение вперёд
	{ 1797	,18	,1	, &internal1_m1306_DvDw0},	//(internal1_m1306_DvDw0) - есть команда на движение назад
	{ 1798	,18	,1	, &internal1_m1306_FDvUp0},	//(internal1_m1306_FDvUp0) - есть команда на движение вперёд
	{ 1799	,18	,1	, &internal1_m1306_FDvDw0},	//(internal1_m1306_FDvDw0) - есть команда на движение назад
	{ 1800	,18	,1	, &internal1_m1306_BlDv0},	//(internal1_m1306_BlDv0) - была блокировка
	{ 1801	,18	,1	, &internal1_m1306_Pkv0},	//(internal1_m1306_Pkv0) Pkv - передний конечный выключатель
	{ 1802	,18	,1	, &internal1_m1306_Pkav0},	//(internal1_m1306_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1803	,18	,1	, &internal1_m1306_Zkv0},	//(internal1_m1306_Zkv0) Zkv - задний конечный выключатель
	{ 1804	,18	,1	, &internal1_m1306_Zkav0},	//(internal1_m1306_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1805	,8	,1	, &internal1_m1306_txNm},	//(internal1_m1306_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1806	,8	,1	, &internal1_m1306_txSm},	//(internal1_m1306_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1807	,8	,1	, &internal1_m1306_txHr},	//(internal1_m1306_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1808	,8	,1	, &internal1_m1306_txLd},	//(internal1_m1306_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1809	,18	,1	, &internal1_m1306_fef},	//(internal1_m1306_fef) fef
	{ 1810	,18	,1	, &internal1_m874_DvUp0},	//(internal1_m874_DvUp0) - есть команда на движение вперёд
	{ 1811	,18	,1	, &internal1_m874_DvDw0},	//(internal1_m874_DvDw0) - есть команда на движение назад
	{ 1812	,18	,1	, &internal1_m874_FDvUp0},	//(internal1_m874_FDvUp0) - есть команда на движение вперёд
	{ 1813	,18	,1	, &internal1_m874_FDvDw0},	//(internal1_m874_FDvDw0) - есть команда на движение назад
	{ 1814	,18	,1	, &internal1_m874_BlDv0},	//(internal1_m874_BlDv0) - была блокировка
	{ 1815	,18	,1	, &internal1_m874_Pkv0},	//(internal1_m874_Pkv0) Pkv - передний конечный выключатель
	{ 1816	,18	,1	, &internal1_m874_Pkav0},	//(internal1_m874_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1817	,18	,1	, &internal1_m874_Zkv0},	//(internal1_m874_Zkv0) Zkv - задний конечный выключатель
	{ 1818	,18	,1	, &internal1_m874_Zkav0},	//(internal1_m874_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1819	,8	,1	, &internal1_m874_txNm},	//(internal1_m874_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1820	,8	,1	, &internal1_m874_txSm},	//(internal1_m874_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1821	,8	,1	, &internal1_m874_txHr},	//(internal1_m874_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1822	,8	,1	, &internal1_m874_txLd},	//(internal1_m874_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1823	,18	,1	, &internal1_m874_fef},	//(internal1_m874_fef) fef
	{ 1824	,18	,1	, &internal1_m870_DvUp0},	//(internal1_m870_DvUp0) - есть команда на движение вперёд
	{ 1825	,18	,1	, &internal1_m870_DvDw0},	//(internal1_m870_DvDw0) - есть команда на движение назад
	{ 1826	,18	,1	, &internal1_m870_FDvUp0},	//(internal1_m870_FDvUp0) - есть команда на движение вперёд
	{ 1827	,18	,1	, &internal1_m870_FDvDw0},	//(internal1_m870_FDvDw0) - есть команда на движение назад
	{ 1828	,18	,1	, &internal1_m870_BlDv0},	//(internal1_m870_BlDv0) - была блокировка
	{ 1829	,18	,1	, &internal1_m870_Pkv0},	//(internal1_m870_Pkv0) Pkv - передний конечный выключатель
	{ 1830	,18	,1	, &internal1_m870_Pkav0},	//(internal1_m870_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1831	,18	,1	, &internal1_m870_Zkv0},	//(internal1_m870_Zkv0) Zkv - задний конечный выключатель
	{ 1832	,18	,1	, &internal1_m870_Zkav0},	//(internal1_m870_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1833	,8	,1	, &internal1_m870_txNm},	//(internal1_m870_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1834	,8	,1	, &internal1_m870_txSm},	//(internal1_m870_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1835	,8	,1	, &internal1_m870_txHr},	//(internal1_m870_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1836	,8	,1	, &internal1_m870_txLd},	//(internal1_m870_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1837	,18	,1	, &internal1_m870_fef},	//(internal1_m870_fef) fef
	{ 1838	,18	,1	, &internal1_m385_DvUp0},	//(internal1_m385_DvUp0) - есть команда на движение вперёд
	{ 1839	,18	,1	, &internal1_m385_DvDw0},	//(internal1_m385_DvDw0) - есть команда на движение назад
	{ 1840	,18	,1	, &internal1_m385_FDvUp0},	//(internal1_m385_FDvUp0) - есть команда на движение вперёд
	{ 1841	,18	,1	, &internal1_m385_FDvDw0},	//(internal1_m385_FDvDw0) - есть команда на движение назад
	{ 1842	,18	,1	, &internal1_m385_BlDv0},	//(internal1_m385_BlDv0) - была блокировка
	{ 1843	,18	,1	, &internal1_m385_Pkv0},	//(internal1_m385_Pkv0) Pkv - передний конечный выключатель
	{ 1844	,18	,1	, &internal1_m385_Pkav0},	//(internal1_m385_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1845	,18	,1	, &internal1_m385_Zkv0},	//(internal1_m385_Zkv0) Zkv - задний конечный выключатель
	{ 1846	,18	,1	, &internal1_m385_Zkav0},	//(internal1_m385_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1847	,8	,1	, &internal1_m385_txNm},	//(internal1_m385_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1848	,8	,1	, &internal1_m385_txSm},	//(internal1_m385_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1849	,8	,1	, &internal1_m385_txHr},	//(internal1_m385_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1850	,8	,1	, &internal1_m385_txLd},	//(internal1_m385_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1851	,18	,1	, &internal1_m385_fef},	//(internal1_m385_fef) fef
	{ 1852	,18	,1	, &internal1_m422_DvUp0},	//(internal1_m422_DvUp0) - есть команда на движение вперёд
	{ 1853	,18	,1	, &internal1_m422_DvDw0},	//(internal1_m422_DvDw0) - есть команда на движение назад
	{ 1854	,18	,1	, &internal1_m422_FDvUp0},	//(internal1_m422_FDvUp0) - есть команда на движение вперёд
	{ 1855	,18	,1	, &internal1_m422_FDvDw0},	//(internal1_m422_FDvDw0) - есть команда на движение назад
	{ 1856	,18	,1	, &internal1_m422_BlDv0},	//(internal1_m422_BlDv0) - была блокировка
	{ 1857	,18	,1	, &internal1_m422_Pkv0},	//(internal1_m422_Pkv0) Pkv - передний конечный выключатель
	{ 1858	,18	,1	, &internal1_m422_Pkav0},	//(internal1_m422_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1859	,18	,1	, &internal1_m422_Zkv0},	//(internal1_m422_Zkv0) Zkv - задний конечный выключатель
	{ 1860	,18	,1	, &internal1_m422_Zkav0},	//(internal1_m422_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1861	,8	,1	, &internal1_m422_txNm},	//(internal1_m422_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1862	,8	,1	, &internal1_m422_txSm},	//(internal1_m422_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1863	,8	,1	, &internal1_m422_txHr},	//(internal1_m422_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1864	,8	,1	, &internal1_m422_txLd},	//(internal1_m422_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1865	,18	,1	, &internal1_m422_fef},	//(internal1_m422_fef) fef
	{ 1866	,18	,1	, &internal1_m416_DvUp0},	//(internal1_m416_DvUp0) - есть команда на движение вперёд
	{ 1867	,18	,1	, &internal1_m416_DvDw0},	//(internal1_m416_DvDw0) - есть команда на движение назад
	{ 1868	,18	,1	, &internal1_m416_FDvUp0},	//(internal1_m416_FDvUp0) - есть команда на движение вперёд
	{ 1869	,18	,1	, &internal1_m416_FDvDw0},	//(internal1_m416_FDvDw0) - есть команда на движение назад
	{ 1870	,18	,1	, &internal1_m416_BlDv0},	//(internal1_m416_BlDv0) - была блокировка
	{ 1871	,18	,1	, &internal1_m416_Pkv0},	//(internal1_m416_Pkv0) Pkv - передний конечный выключатель
	{ 1872	,18	,1	, &internal1_m416_Pkav0},	//(internal1_m416_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1873	,18	,1	, &internal1_m416_Zkv0},	//(internal1_m416_Zkv0) Zkv - задний конечный выключатель
	{ 1874	,18	,1	, &internal1_m416_Zkav0},	//(internal1_m416_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1875	,8	,1	, &internal1_m416_txNm},	//(internal1_m416_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1876	,8	,1	, &internal1_m416_txSm},	//(internal1_m416_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1877	,8	,1	, &internal1_m416_txHr},	//(internal1_m416_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1878	,8	,1	, &internal1_m416_txLd},	//(internal1_m416_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1879	,18	,1	, &internal1_m416_fef},	//(internal1_m416_fef) fef
	{ 1880	,1	,1	, &internal1_m822_q0},	//(internal1_m822_q0) q0 - внутренний параметр
	{ 1881	,1	,1	, &internal1_m819_q0},	//(internal1_m819_q0) q0 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="du.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{740,"fEM_A1UC03RDU\0"}, 
{741,"dEM_A1UC05UDU\0"}, 
{742,"dEM_A1UC06UDU\0"}, 
{743,"dEM_A2UC06UDU\0"}, 
{744,"dEM_A2UC05UDU\0"}, 
{745,"fEM_A2UC03RDU\0"}, 
{746,"dEM_A3UC06UDU\0"}, 
{747,"dEM_A3UC05UDU\0"}, 
{748,"fEM_A3UC03RDU\0"}, 
{749,"dEM_A8UC06UDU\0"}, 
{750,"fEM_A8UC03RDU\0"}, 
{751,"dEM_A8UC05UDU\0"}, 
{752,"fEM_R0UV81RDU\0"}, 
{753,"fEM_R0UV82RDU\0"}, 
{754,"fEM_R0UV83RDU\0"}, 
{755,"fEM_R0UV84RDU\0"}, 
{756,"fEM_R0UV86RDU\0"}, 
{757,"fEM_R0UV85RDU\0"}, 
{758,"fEM_R0UV87RDU\0"}, 
{759,"fEM_A3UP03RDU\0"}, 
{760,"fEM_A3UP04RDU\0"}, 
{761,"fEM_A3UP43RDU\0"}, 
{762,"fEM_A3UP44RDU\0"}, 
{763,"fEM_A3UP53RDU\0"}, 
{764,"fEM_A3UP85RDU\0"}, 
{765,"fEM_A3UP88RDU\0"}, 
{766,"fEM_A3UP86RDU\0"}, 
{767,"fEM_B8UV01RDU\0"}, 
{768,"fEM_B8UV02RDU\0"}, 
{769,"fEM_B8UV03RDU\0"}, 
{770,"fEM_B8UL04RDU\0"}, 
{771,"iEM_A2UV03CDU\0"}, 
{772,"fEM_A2UV01RDU\0"}, 
{773,"fEM_A2UV02RDU\0"}, 
{774,"fEM_A1UV01RDU\0"}, 
{775,"fEM_A1UV02RDU\0"}, 
{776,"fEM_A1UC06RDU\0"}, 
{777,"fEM_A1UC05RDU\0"}, 
{778,"fEM_A1UL04RDU\0"}, 
{779,"fEM_A3UV01RDU\0"}, 
{780,"fEM_A3UV02RDU\0"}, 
{781,"fEM_A3UC06RDU\0"}, 
{782,"fEM_A3UC05RDU\0"}, 
{783,"fEM_A3UL04RDU\0"}, 
{784,"fEM_A3UP54RDU\0"}, 
{785,"fEM_A3UP87RDU\0"}, 
{786,"fEM_R0UL05RDU\0"}, 
{787,"fEM_R0UL20RDU\0"}, 
{788,"fEM_B8UV04RDU\0"}, 
{789,"fEM_B8UC06RDU\0"}, 
{790,"fEM_B8UC05RDU\0"}, 
{791,"fEM_A2UL05RDU\0"}, 
{792,"fEM_A2UL03RDU\0"}, 
{793,"fEM_A2UC06RDU\0"}, 
{794,"fEM_A2UC05RDU\0"}, 
{795,"fEM_A2UL04RDU\0"}, 
{796,"fEM_A1UL03RDU\0"}, 
{797,"fEM_A1UL05RDU\0"}, 
{798,"fEM_A3UL03RDU\0"}, 
{799,"fEM_A3UL05RDU\0"}, 
{800,"fEM_A1UC08RDU\0"}, 
{801,"fEM_A3UC08RDU\0"}, 
{802,"fEM_A1UC07RDU\0"}, 
{803,"fEM_A1UL01RDU\0"}, 
{804,"fEM_A3UC07RDU\0"}, 
{805,"fEM_A3UL01RDU\0"}, 
{806,"fEM_A2UC08RDU\0"}, 
{807,"fEM_A2UC07RDU\0"}, 
{808,"fEM_A2UL01RDU\0"}, 
{809,"fEM_B8UC01RDU\0"}, 
{810,"fEM_B8UL07RDU\0"}, 
{811,"fEM_B8UC02RDU\0"}, 
{812,"fEM_B8UL01RDU\0"}, 
{813,"fEM_B8UL05RDU\0"}, 
{814,"fEM_B8UL03RDU\0"}, 
{815,"fEM_B8UL06RDU\0"}, 
{816,"fEM_A9UZ03RDU\0"}, 
{817,"fEM_A9UZ04RDU\0"}, 
{818,"fEM_A9UZ05RDU\0"}, 
{819,"fEM_R4UZ04RDU\0"}, 
{820,"fEM_R4UZ03RDU\0"}, 
{821,"fEM_R4UZ05RDU\0"}, 
{822,"fEM_A5UZ03RDU\0"}, 
{823,"fEM_A5UZ04RDU\0"}, 
{824,"fEM_A5UZ05RDU\0"}, 
{825,"fEM_A4UZ03RDU\0"}, 
{826,"fEM_A4UZ04RDU\0"}, 
{827,"fEM_A4UZ05RDU\0"}, 
{828,"fEM_A6UZ03RDU\0"}, 
{829,"fEM_A6UZ04RDU\0"}, 
{830,"fEM_A6UZ05RDU\0"}, 
{831,"fEM_R1UZ03RDU\0"}, 
{832,"fEM_R1UZ04RDU\0"}, 
{833,"fEM_R1UZ05RDU\0"}, 
{834,"fEM_R0UL04RDU\0"}, 
{835,"fEM_R0UL06RDU\0"}, 
{836,"fEM_R0UL03RDU\0"}, 
{837,"fEM_R0UL17RDU\0"}, 
{838,"fEM_R0UL19RDU\0"}, 
{839,"fEM_R0UL07RDU\0"}, 
{840,"fEM_R0UL18RDU\0"}, 
{841,"fEM_R0UL16RDU\0"}, 
{842,"fEM_R0UL02RDU\0"}, 
{843,"fEM_R0UN08RDU\0"}, 
{844,"fEM_R0UN07RDU\0"}, 
{845,"fEM_R0UN06RDU\0"}, 
{846,"fEM_R0UN05RDU\0"}, 
{847,"fEM_R0UN04RDU\0"}, 
{848,"fEM_R0UN03RDU\0"}, 
{849,"fEM_R0UN02RDU\0"}, 
{850,"fEM_R0UN01RDU\0"}, 
{851,"fEM_A2UC82RDU\0"}, 
{852,"fEM_A2UC83RDU\0"}, 
{853,"fEM_A1UC83RDU\0"}, 
{854,"fEM_A2UC81RDU\0"}, 
{855,"fEM_A1UC81RDU\0"}, 
{856,"fEM_A1UC82RDU\0"}, 
{857,"fEM_A2UL83RDU\0"}, 
{858,"fEM_A3UC81RDU\0"}, 
{859,"fEM_A3UC82RDU\0"}, 
{860,"fEM_R0UN80RDU\0"}, 
{861,"iEM_A2UV01IDU\0"}, 
{862,"iEM_A2UV02IDU\0"}, 
{863,"iEM_A1UV01IDU\0"}, 
{864,"iEM_A1UV02IDU\0"}, 
{865,"iEM_A1UV03IDU\0"}, 
{866,"iEM_A3UV01IDU\0"}, 
{867,"iEM_A3UV02IDU\0"}, 
{868,"lEM_R0MD01LC1\0"}, 
{869,"fEM_A3UC09RDU\0"}, 
{870,"fEM_A2UC02RDU\0"}, 
{871,"fEM_A1UC02RDU\0"}, 
{872,"fEM_A3UC02RDU\0"}, 
{873,"fEM_R0UL21RDU\0"}, 
{874,"fEM_R0UN09RDU\0"}, 
{875,"fEM_R0UN11RDU\0"}, 
{876,"fEM_R0UN12RDU\0"}, 
{877,"fEM_R0UN13RDU\0"}, 
{878,"fEM_R0UN14RDU\0"}, 
{879,"fEM_R0UN16RDU\0"}, 
{880,"fEM_R0UN17RDU\0"}, 
{881,"fEM_R0UN18RDU\0"}, 
{882,"fEM_R0UN19RDU\0"}, 
{883,"fEM_R0UN70LDU\0"}, 
{884,"fEM_R0UN71LDU\0"}, 
{885,"fEM_R0UN72LDU\0"}, 
{886,"fEM_R0UN73LDU\0"}, 
{887,"fEM_R0UN74LDU\0"}, 
{888,"fEM_R0UN75LDU\0"}, 
{889,"fEM_R0UN80LDU\0"}, 
{890,"fEM_R0UN81LDU\0"}, 
{891,"fEM_R0UN82LDU\0"}, 
{892,"fEM_R0UN83LDU\0"}, 
{893,"fEM_R0UN84LDU\0"}, 
{894,"fEM_R0UN85LDU\0"}, 
{895,"fEM_R0UT20RDU\0"}, 
{896,"fEM_R0UN25RDU\0"}, 
{897,"fEM_R0UN15RDU\0"}, 
{898,"fEM_R0UN26RDU\0"}, 
{899,"fEM_R0UN27RDU\0"}, 
{900,"fEM_R0UN24RDU\0"}, 
{901,"fEM_R0UL25RDU\0"}, 
{902,"fEM_R0UL01RSS\0"}, 
{903,"fEM_R0UL02RSS\0"}, 
{904,"fEM_R0UN03RSS\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_DU[]={  // 
	{&A2MD11LP1,1,0},	//( - , DU) Кнопка ПУСК РБ1
	{&B2MD12LP1,1,1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
	{&B2MD11LP1,1,2},	//( - , DU) Кнопка ПУСК РБ2
	{&B1MD12LP1,1,3},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
	{&B1MD11LP1,1,4},	//( - , DU) Кнопка ПУСК ББ2
	{&R0MW17LP1,1,5},	//( - , DU) Переключатель АВТ/Р
	{&A1MD11LP1,1,6},	//( - , DU) Кнопка ПУСК ББ1
	{&A1MD12LP1,1,7},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
	{&R0MD33LP1,1,8},	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
	{&A3MD11LP1,1,9},	//( - , DU) Кнопка ПУСК ИС1
	{&A3MD12LP1,1,10},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
	{&B3MD11LP1,1,11},	//( - , DU) Кнопка ПУСК ИС2
	{&B3MD12LP1,1,12},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
	{&R0MD34LP1,1,13},	//( - , DU) Кнопка КВИТИРОВАТЬ
	{&A2MD12LP1,1,14},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
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
	{&A3VX01LDU,1,2},	//( - , DU) Индикация Выстрел ИС1
	{&B2VS32LDU,1,3},	//( - , DU) Индикация  СБРОС РБ2
	{&A2VS32LDU,1,4},	//( - , DU) Индикация  СБРОС РБ1
	{&R0VS17LDU,1,5},	//( - , DU) Индикация выбора АВТОМАТ
	{&R0VX09LDU,1,6},	//( - , DU) Индикация регулятор мощности включен/отключен
	{&R0VW23LDU,1,7},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,1,8},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
	{&B2IS11LDU,1,9},	//( - K11VDSR, DU) Приход на ВУ РБ2-СТР
	{&A2IS11LDU,1,10},	//( - K11VDSR, DU) Приход на ВУ РБ1-СТР
	{&B3IS22LDU,1,11},	//( - K04VDSR, DU) Приход на НУП ИС2
	{&A3IS22LDU,1,12},	//( - K02VDSR, DU) Приход на НУП ИС1
	{&R0AB01LDU,1,13},	//( - , DU) Режим проверки разрешён
	{&B9AB02LDU,1,14},	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
	{&B9AB01LDU,1,15},	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
	{&B9AZ03LDU,1,16},	//( - , DU) Несанкционированное перемещение НИ ДС2
	{&A9AB02LDU,1,17},	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
	{&A3VZ15LZ2,1,18},	//( - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{&A3VZ15LZ1,1,19},	//( - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{&A3VZ13LZ1,1,20},	//( - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{&A3VZ13LZ2,1,21},	//( - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{&R0AD14LZ2,1,22},	//( - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
	{&R0AD14LZ1,1,23},	//( - K20VDSR, DU) Имитация срабатывания АЗ от II УР
	{&A1AB19LDU,1,24},	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
	{&A1VN71LZ2,1,25},	//( - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{&A1VN71LZ1,1,26},	//( - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{&A4IS10LDU,1,27},	//( - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
	{&A3IS35LDU,1,28},	//( - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
	{&A3IS33LDU,1,29},	//( - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
	{&A3IS31LDU,1,30},	//( - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
	{&A2IS33LDU,1,31},	//( - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
	{&R0VZ71LDU,1,32},	//( - , DU) Обобщенный сигнал АЗ
	{&B7AZ03LDU,1,33},	//( - , DU) Несанкционированное включение обдува АЗ2
	{&A7AZ03LDU,1,34},	//( - , DU) Несанкционированное включение обдува АЗ1
	{&B7AS31LDU,1,35},	//( - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
	{&A7AS31LDU,1,36},	//( - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
	{&B2VS21LDU,1,37},	//( - , DU) Движение РБ2 в сторону НУ
	{&B2VS11LDU,1,38},	//( - , DU) Движение РБ2 в сторону ВУ
	{&R0VP73LDU,1,39},	//( - , DU) ПС давления для РУ
	{&R0IS02LDU,1,40},	//( - K30VDSR, DU) Разрешение ввода от имитатора
	{&R0IS01LDU,1,41},	//( - K29VDSR, DU) Признак работы с имитатором
	{&A3IS11LDU,1,42},	//( - K01VDSR, DU) Приход на ВУ ИС1
	{&B3IS11LDU,1,43},	//( - K03VDSR, DU) Приход на ВУ ИС2
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
	{&A9AB01LDU,1,70},	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
	{&A9AZ03LDU,1,71},	//( - , DU) Несанкционированное перемещение НИ ДС1
	{&B9IS11LDU,1,72},	//( - K25VDSR, DU) Приход на ВУ НИ ДС2
	{&A9IS11LDU,1,73},	//( - K23VDSR, DU) Приход на ВУ НИ ДС1
	{&B4VS22LDU,1,74},	//( - , DU) Движение НИ2 в сторону НУ
	{&B4VS12LDU,1,75},	//( - , DU) Движение НИ2 в сторону ВУ
	{&A4VS22LDU,1,76},	//( - , DU) Движение НИ1 в сторону НУ
	{&A4VS12LDU,1,77},	//( - , DU) Движение НИ1 в сторону ВУ
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
	{&A4ZAV,1,117},	//( - , DU) 
	{&R0AB13LDU,1,118},	//( - , DU) Ошибка в заданной координате  АЗ2
	{&R0AB12LDU,1,119},	//( - , DU) Ошибка в заданной координате  ИС2
	{&R0AB11LDU,1,120},	//( - , DU) Ошибка в заданной координате  ИС1
	{&R0AB10LDU,1,121},	//( - , DU) Ошибка в заданной координате ББ2
	{&R0AB09LDU,1,122},	//( - , DU) Ошибка в заданной координате ББ1
	{&R0AB08LDU,1,123},	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
	{&B6AB05LDU,1,124},	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
	{&R0VS11LDU,1,125},	//( - , DU) РУ не готова к работе
	{&R0AB07LDU,1,126},	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
	{&R0EE03LDU,1,127},	//( - , DU) ВПИС ИС
	{&R0VX02LDU,1,128},	//( - , DU) Импульс разрешен
	{&B2AB15LDU,1,129},	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{&A2AB15LDU,1,130},	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{&R0AB05LDU,1,131},	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
	{&R0AB03LDU,1,132},	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
	{&R3IS21LDU,1,133},	//( - K18VDSR, DU) Приход на НУ гомогенных дверей
	{&R3IS11LDU,1,134},	//( - K17VDSR, DU) Приход на ВУ гомогенных дверей
	{&B4IS10LDU,1,135},	//( - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
	{&B3IS35LDU,1,136},	//( - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
	{&B3IS33LDU,1,137},	//( - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
	{&B3IS31LDU,1,138},	//( - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
	{&B2IS33LDU,1,139},	//( - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
	{&R0AB19LDU,1,140},	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
	{&R0AB20LDU,1,141},	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
	{&A3AB15LDU,1,142},	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
	{&R0AB18LDU,1,143},	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
	{&R0AB17LDU,1,144},	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
	{&R0AB16LDU,1,145},	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
	{&A6ZAV,1,146},	//( - , DU) 
	{&R2ZAV,1,147},	//( - , DU) 
	{&A5ZAV,1,148},	//( - , DU) 
	{&B8ZAV,1,149},	//( - , DU) 
	{&A2ZAV,1,150},	//( - , DU) Завершение РБ1,2
	{&A8ZAV,1,151},	//( - , DU) 
	{&A9ZAV,1,152},	//( - , DU) Завершение НИ ДС1(2)
	{&R4ABL,1,153},	//( - , DU) Блокировка тележки -
	{&A4UP,1,154},	//( - , DU) 
	{&A4DW,1,155},	//( - , DU) 
	{&R0AB14LDU,1,156},	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
	{&R0AB15LDU,1,157},	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
	{&A3IS12LDU,1,158},	//( - , DU) Приход на ВУ штока ИС1
	{&B3IS12LDU,1,159},	//( - , DU) Приход на ВУ штока ИС2
	{&A1ZAV,1,160},	//( - , DU) 
	{&A3ZAV,1,161},	//( - , DU) 
	{&B1AB19LDU,1,162},	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
	{&B1IS12LDU,1,163},	//( - K07VDSR, DU) Магнит ББ2 зацеплен
	{&A2IS12LDU,1,164},	//( - K10VDSR, DU) Магнит РБ1 зацеплен
	{&A1IS12LDU,1,165},	//( - K07VDSR, DU) Магнит ББ1 зацеплен
	{&B5AB04LDU,1,166},	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
	{&A5AB04LDU,1,167},	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
	{&B4AB02LDU,1,168},	//( - , DU) Блокировка движения НИ2 - Нет перемещения
	{&B4AB01LDU,1,169},	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
	{&B4AZ03LDU,1,170},	//( - , DU) Несанкционированное перемещение НИ2
	{&A4AB02LDU,1,171},	//( - , DU) Блокировка движения НИ1 - Нет перемещения
	{&A4AB01LDU,1,172},	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
	{&A4AZ03LDU,1,173},	//( - , DU) Несанкционированное перемещение НИ1
	{&B4IS21LDU,1,174},	//( - K32VDSR, DU) Приход на НУ НИ2
	{&A4IS21LDU,1,175},	//( - K15VDSR, DU) Приход на НУ НИ1
	{&B5AB02LDU,1,176},	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
	{&B5AB01LDU,1,177},	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
	{&B5AZ03LDU,1,178},	//( - , DU) Несанкционированное перемещение НЛ2
	{&A5AB02LDU,1,179},	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
	{&A5AB01LDU,1,180},	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
	{&A5AZ03LDU,1,181},	//( - , DU) Несанкционированное перемещение НЛ1
	{&B5IS21LDU,1,182},	//( - K16VDSR, DU) Приход на НУ НЛ2
	{&B5IS11LDU,1,183},	//( - K15VDSR, DU) Приход на ВУ НЛ2
	{&A5IS21LDU,1,184},	//( - K12VDSR, DU) Приход на НУ НЛ1
	{&A5IS11LDU,1,185},	//( - K11VDSR, DU) Приход на ВУ НЛ1
	{&B5VS12LDU,1,186},	//( - K14VDSR, DU) Движение НЛ2 в сторону ВУ
	{&B5VS22LDU,1,187},	//( - K15VDSR, DU) Движение НЛ2 в сторону НУ
	{&A5VS12LDU,1,188},	//( - K11VDSR, DU) Движение НЛ1 в сторону ВУ
	{&A5VS22LDU,1,189},	//( - K12VDSR, DU) Движение НЛ1 в сторону НУ
	{&R4AD20LDU,1,190},	//( - K14FDSR, DU) Перемещение тележки назад
	{&R4AB18LDU,1,191},	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
	{&R4AB17LDU,1,192},	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
	{&R4AB16LDU,1,193},	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
	{&R5IS11LDU,1,194},	//( - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
	{&A8AB06LDU,1,195},	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
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
	{&B2IS12LDU,1,209},	//( - K10VDSR, DU) Магнит РБ2 зацеплен
	{&R4IS11LDU,1,210},	//( - K05VDSR, DU) Приход на ВУ1 тележки
	{&A6AB06LDU,1,211},	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
	{&A6AB07LDU,1,212},	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
	{&A6AB08LDU,1,213},	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
	{&A6AB09LDU,1,214},	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
	{&B6AB06LDU,1,215},	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
	{&B6AB07LDU,1,216},	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
	{&B6AB08LDU,1,217},	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
	{&B6AB09LDU,1,218},	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
	{&A6AB05LDU,1,219},	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
	{&B8VS12LDU,1,220},	//( - , DU) Движение АЗ2 в сторону ВУ
	{&B8AB06LDU,1,221},	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
	{&B8AB07LDU,1,222},	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
	{&B8AB05LDU,1,223},	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
	{&B8VS22LDU,1,224},	//( - , DU) Движение АЗ2 в сторону НУ
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
	{&B1AZ03LDU,1,274},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
	{&B1VS22LDU,1,275},	//( - , DU) Движение ББ2 в сторону НУ
	{&B1AB01LDU,1,276},	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
	{&B1AB02LDU,1,277},	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
	{&B1AB04LDU,1,278},	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
	{&B1VS12LDU,1,279},	//( - , DU) Движение ББ2 в сторону ВУ
	{&A1AB18LDU,1,280},	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
	{&A1AB17LDU,1,281},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
	{&A1AB16LDU,1,282},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
	{&A1AB14LDU,1,283},	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
	{&A1AB13LDU,1,284},	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
	{&A1AB12LDU,1,285},	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&A1AB11LDU,1,286},	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
	{&A1AB10LDU,1,287},	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
	{&A1AB09LDU,1,288},	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
	{&A1AB06LDU,1,289},	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
	{&A1AB05LDU,1,290},	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
	{&A1AB08LDU,1,291},	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
	{&A1AB07LDU,1,292},	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
	{&A1AZ03LDU,1,293},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
	{&A1VS22LDU,1,294},	//( - , DU) Движение ББ1 в сторону НУ
	{&A1AB01LDU,1,295},	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
	{&A1AB02LDU,1,296},	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
	{&A1AB04LDU,1,297},	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
	{&A1VS12LDU,1,298},	//( - , DU) Движение ББ1 в сторону ВУ
	{&R2IS11LDU,1,299},	//( - K29VDSR, DU) Приход на ВУ МДЗ2
	{&R1VS12LDU,1,300},	//( - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
	{&R2VS12LDU,1,301},	//( - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
	{&R2VS22LDU,1,302},	//( - K09VDSR, DU) Движение МДЗ2 в сторону НУ
	{&A3AB17LDU,1,303},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
	{&A3AB16LDU,1,304},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
	{&A3AB14LDU,1,305},	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
	{&A3AB12LDU,1,306},	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&A3AB11LDU,1,307},	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
	{&A3AB10LDU,1,308},	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
	{&A3AB09LDU,1,309},	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
	{&A3AB06LDU,1,310},	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
	{&A3AB05LDU,1,311},	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
	{&A3AB08LDU,1,312},	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
	{&A3AB07LDU,1,313},	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
	{&A3AZ03LDU,1,314},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
	{&A3VS22LDU,1,315},	//( - , DU) Движение ИС1 в сторону НУ
	{&A3AB01LDU,1,316},	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
	{&A3AB02LDU,1,317},	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
	{&B1AB07LDU,1,318},	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
	{&B1AB08LDU,1,319},	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
	{&B1AB05LDU,1,320},	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
	{&B1AB06LDU,1,321},	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
	{&B1AB09LDU,1,322},	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
	{&B1AB10LDU,1,323},	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
	{&B1AB11LDU,1,324},	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
	{&B1AB12LDU,1,325},	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&B1AB13LDU,1,326},	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
	{&B1AB14LDU,1,327},	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
	{&B1AB16LDU,1,328},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
	{&B1AB17LDU,1,329},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
	{&B1AB18LDU,1,330},	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
	{&A3VS12LDU,1,331},	//( - , DU) Движение ИС1 в сторону ВУ
	{&A3AB04LDU,1,332},	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
	{&A2AB12LDU,1,333},	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&A2AB11LDU,1,334},	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
	{&A2AB10LDU,1,335},	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
	{&A2AB09LDU,1,336},	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
	{&A2AB06LDU,1,337},	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
	{&A2AB05LDU,1,338},	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
	{&A2AB08LDU,1,339},	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
	{&A2AB07LDU,1,340},	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
	{&A2AZ03LDU,1,341},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
	{&A2VS21LDU,1,342},	//( - , DU) Движение РБ1 в сторону НУ
	{&A2AB01LDU,1,343},	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
	{&A2AB02LDU,1,344},	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
	{&A2AB04LDU,1,345},	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
	{&A2VS11LDU,1,346},	//( - , DU) Движение РБ1 в сторону ВУ
	{&A8AB01LDU,1,347},	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
	{&A8AB02LDU,1,348},	//( - , DU) Блокировка движения ДС2- АНИ не установлен
	{&A8AB14LDU,1,349},	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
	{&A8AB13LDU,1,350},	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
	{&A8AB12LDU,1,351},	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
	{&A8AB11LDU,1,352},	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
	{&A8AB10LDU,1,353},	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
	{&A8AB09LDU,1,354},	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
	{&A8AB08LDU,1,355},	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
	{&A8IS22LDU,1,356},	//( - K31VDSR, DU) Приход на механический НУ ДС2
	{&A8AB04LDU,1,357},	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
	{&A8IS12LDU,1,358},	//( - K30VDSR, DU) Приход на механический ВУ ДС2
	{&B8IS22LDU,1,359},	//( - K22VDSR, DU) Приход на НУ2 АЗ2
	{&A8AZ03LDU,1,360},	//( - , DU) Несанкционированное перемещение ДС2
	{&A8VS22LDU,1,361},	//( - , DU) Движение ДС2 в сторону НУ
	{&A8AB05LDU,1,362},	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
	{&A8AB07LDU,1,363},	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
	{&R1VS22LDU,1,364},	//( - K06VDSR, DU) Движение МДЗ1 в сторону НУ
	{&R1IS11LDU,1,365},	//( - K27VDSR, DU) Приход на ВУ МДЗ1
	{&R2AB04LDU,1,366},	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
	{&R1AB04LDU,1,367},	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
	{&R2AB02LDU,1,368},	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
	{&R2AB01LDU,1,369},	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
	{&R2AZ03LDU,1,370},	//( - , DU) Несанкционированное перемещение МДЗ2
	{&R1AB02LDU,1,371},	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
	{&R1AB01LDU,1,372},	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
	{&R1AZ03LDU,1,373},	//( - , DU) Несанкционированное перемещение МДЗ1
	{&B2AB17LDU,1,374},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
	{&B2AB16LDU,1,375},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
	{&B2AB14LDU,1,376},	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
	{&B2AB13LDU,1,377},	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
	{&B2AB12LDU,1,378},	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{&B2AB11LDU,1,379},	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
	{&A2AB13LDU,1,380},	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
	{&A2AB14LDU,1,381},	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
	{&A2AB16LDU,1,382},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
	{&A2AB17LDU,1,383},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
	{&B2AB04LDU,1,384},	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
	{&B2AB02LDU,1,385},	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
	{&B2AB01LDU,1,386},	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
	{&B2AZ03LDU,1,387},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
	{&B2AB07LDU,1,388},	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
	{&B2AB08LDU,1,389},	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
	{&B2AB05LDU,1,390},	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
	{&B2AB06LDU,1,391},	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
	{&B2AB09LDU,1,392},	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
	{&B2AB10LDU,1,393},	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DU[]={  // 
	{&R0VX08IDU,3,0},	//( - , DU) Индикация Режим
	{&R0VL01RDU,8,1},	//( - , DU) Индикация Время задержки
	{&B2VS01IDU,3,3},	//( - , DU) Готовность к управлению РБ2
	{&R0VL11IDU,3,4},	//( - , DU) До импульса секунд
	{&R0VL01IDU,3,5},	//( - , DU) До импульса минут
	{&B3CV02RDU,8,6},	//( - , DU) Заданная скорость перемещения ИС2
	{&R1VS01IDU,3,8},	//( - , DU) Готовность к управлению МДЗ1
	{&R2VS01IDU,3,9},	//( - , DU) Готовность к управлению МДЗ2
	{&R4VS01IDU,3,10},	//( - , DU) Готовность к управлению тележкой реактора
	{&A6VS01IDU,3,11},	//( - , DU) Готовность к управлению БЗ1
	{&B5VS01IDU,3,12},	//( - , DU) Готовность к управлению НЛ2
	{&A5VS01IDU,3,13},	//( - , DU) Готовность к управлению НЛ1
	{&B4VS01IDU,3,14},	//( - , DU) Готовность к управлению НИ2
	{&A4VS01IDU,3,15},	//( - , DU) Готовность к управлению НИ1
	{&R0VL06RDU,8,16},	//( - , DU) Индикация (Время задержки от ВУ РБ)
	{&R0VL02RDU,8,18},	//( - , DU) Индикация (Время задержки ИНИ)
	{&R0VL04RDU,8,20},	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
	{&R0VL03RDU,8,22},	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
	{&R0VL05RDU,8,24},	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
	{&R0VL21IDU,3,26},	//( - , DU) Декатрон
	{&R0VS21IDU,3,27},	//( - , DU) Индикация ВИД ПРОВЕРКИ
	{&A1VS01IDU,3,28},	//( - , DU) Готовность к управлению ББ1
	{&B1VS01IDU,3,29},	//( - , DU) Готовность к управлению ББ2
	{&A3VS01IDU,3,30},	//( - , DU) Готовность к управлению ИС1
	{&B3VS01IDU,3,31},	//( - , DU) Готовность к управлению ИС2
	{&A2VS01IDU,3,32},	//( - , DU) Готовность к управлению РБ1
	{&A1VC01RDU,8,33},	//( - , DU) Координата ББ1, мм
	{&A8VC01RDU,8,35},	//( - , DU) Координата ДС2, мм
	{&B3VC01RDU,8,37},	//( - , DU) Координата ИС2, мм
	{&B1VC01RDU,8,39},	//( - , DU) Координата ББ2, мм
	{&R0VN15RDU,8,41},	//( - , DU) Период разгона РУ
	{&B3CV01RDU,8,43},	//( - , DU) Измеренная скорость перемещения ИС2
	{&TTLDU,3,45},	//( - , DU) ttl
	{&R3VS01IDU,3,46},	//( - , DU) Готовность к управлению гомогенных дверей
	{&R5VS01IDU,3,47},	//( - , DU) Готовность к управлению ворот отстойной зоны
	{&B8VC01RDU,8,48},	//( - , DU, MDuBz1, MDuBz2) Координата АЗ2, мм
	{&B2VC01RDU,8,50},	//( - , DU) Координата РБ2, мм
	{&A2VC01RDU,8,52},	//( - , DU) Координата РБ1, мм
	{&A3VC01RDU,8,54},	//( - , DU) Координата ИС1, мм
	{&A3CP02RDU,8,56},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
	{&B3CP02RDU,8,58},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
	{&A8VS01IDU,3,60},	//( - , DU) Готовность к управлению ДС2
	{&B8VS01IDU,3,61},	//( - , DU) Готовность к управлению АЗ2
	{&B6VS01IDU,3,62},	//( - , DU) Готовность к управлению БЗ2
	{&R0CN95LDU,3,63},	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
	{&R0CN94LDU,8,64},	//( - , DU) Скорость изменения мощности
	{&R0CN93LDU,8,66},	//( - , DU) время работы на мощности более 100Вт, сек
	{&R0VN12RDU,8,68},	//( - , DU) Заданная мощность РУ
	{&R0VN11RDU,8,70},	//( - , DU) Текущая мощность РУ
	{&R0CN92LDU,8,72},	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
	{&A3MC03RDU,8,74},	//( - , DU) Координата положения ИМ 0-й реактивности
	{&R0CN91LDU,8,76},	//( - , DU) Рассчётная реактивность от регулятора
	{&A3MC02RDU,8,78},	//( - , DU) Температурная корректировка координаты ИМ
	{&A3MC01RDU,8,80},	//( - , DU) Заданная координата положения ИС от регулятора мм
	{&A8CV01RDU,8,82},	//( - , DU) Измеренная скорость перемещения ДС2
	{&B8CV01RDU,8,84},	//( - , DU) Измеренная скорость перемещения АЗ2
	{&B1CV01RDU,8,86},	//( - , DU) Измеренная скорость перемещения ББ2
	{&A1CV02RDU,8,88},	//( - , DU) Заданная скорость перемещения ББ1
	{&A1CV01RDU,8,90},	//( - , DU) Измеренная скорость перемещения ББ1
	{&A3CV02RDU,8,92},	//( - , DU) Заданная скорость перемещения ИС1
	{&B1CV02RDU,8,94},	//( - , DU) Заданная скорость перемещения ББ2
	{&A3CV01RDU,8,96},	//( - , DU) Измеренная скорость перемещения ИС1
	{&A2CV01RDU,8,98},	//( - , DU) Измеренная скорость перемещения РБ1
	{&A2CV02RDU,8,100},	//( - , DU) Заданная скорость перемещения РБ1
	{&B2CV01RDU,8,102},	//( - , DU) Измеренная скорость перемещения РБ2
	{&B2CV02RDU,8,104},	//( - , DU) Заданная скорость перемещения РБ2
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
	{&fEM_R0UV82RDU,8,45},	//( - , DU) 2-я частота двигателя (шагов/секунду)
	{&fEM_R0UV83RDU,8,47},	//( - , DU) 3-я частота двигателя (шагов/секунду)
	{&fEM_R0UV84RDU,8,49},	//( - , DU) 4-я частота двигателя (шагов/секунду)
	{&fEM_R0UV86RDU,8,51},	//( - , DU) 7-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UV85RDU,8,53},	//( - , DU) 6-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UV87RDU,8,55},	//( - , DU) 8-я скорость перемещения ББ (шагов/секунду)
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
	{&fEM_R0UL01RSS,8,333},	//( - , DU) Шаг измерения периода (сек)
	{&fEM_R0UL02RSS,8,335},	//( - , DU) Tф-постоянная времени, с
	{&fEM_R0UN03RSS,8,337},	//( - , DU) нижняя граница интервала мощности для измерения периода (ватт)
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
	{&R0DE06LDU,3,0},	//( - DiagnFDS, DiagnDU) диагностика модуля ДУ на 6 месте
	{&R0DE01LDU,3,1},	//( - DiagnVDS, DiagnDU) диагностика модуля ДУ на 1 месте
	{&R0DE0FLDU,3,2},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
	{&R0DE0DLDU,3,3},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
	{&R0DE0BLDU,3,4},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
	{&R0DE0CLDU,3,5},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
	{&R0DE07LDU,3,6},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
	{&R0DE0ALDU,3,7},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
	{&R0DE09LDU,3,8},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
	{&R0DE05LDU,3,9},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
	{&R0DE08LDU,3,10},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
	{&R0DE04LDU,3,11},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
	{&R0DE03LDU,3,12},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
	{&R0DE02LDU,3,13},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
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
	{&A0CT01IZ1,8,4},	//( - , Baz1, SBz1DU) Температура АЗ1-1
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
	{&A0CT01IZ2,8,4},	//( - , Baz2, SBz2DU) Температура АЗ1-1
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
	{&B8IC01UDU,5,8},	//( - , SDu) Координата АЗ2, мм
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
static char buf_VENCF[86];	//VENCF
static vencf8_inipar ini_VENCF={0xc2,0xff,0,0x6,0x96,};
#pragma pack(push,1)
static table_drv table_VENCF={0,0,&ini_VENCF,buf_VENCF,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VENCF[]={
	{&R0DE01LDU,3,82},
	{&venc08,5,75},
	{&venc07,5,70},
	{&venc06,5,65},
	{&venc05,5,60},
	{&venc04,5,55},
	{&venc03,5,50},
	{&venc02,5,45},
	{&venc01,5,40},
	{&R0DE06LDU,3,80},
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
	{&A9IS11LDU,1,44},
	{&A9IS21LDU,1,46},
	{&B2IS12LDU,1,18},
	{&B1IS12LDU,1,12},
	{&B2IS21LDU,1,22},
	{&B3IS21LDU,1,24},
	{&B7AS31LDU,1,10},
	{&B9IS11LDU,1,48},
	{&B2IS33LDU,1,4},
	{&B4IS21LDU,1,62},
	{&B4IS11LDU,1,60},
	{&A3VZ15LZ1,1,36},
	{&A3VZ13LZ1,1,34},
	{&R2IS21LDU,1,58},
	{&R1IS21LDU,1,54},
	{&B2IS11LDU,1,20},
	{&B1IS11LDU,1,14},
	{&A1VN71LZ1,1,40},
	{&R8IS11LDU,1,26},
	{&R0DE02LDU,3,64},
	{&B4IS10LDU,1,6},
	{&R1IS11LDU,1,52},
	{&R0VZ71LZ1,1,42},
	{&R8AD22LDU,1,28},
	{&R0AD14LZ1,1,38},
	{&R2IS11LDU,1,56},
	{&B1IS21LDU,1,16},
	{&B3IS35LDU,1,0},
	{&B3IS33LDU,1,2},
	{&B9IS21LDU,1,50},
	{&B3IS31LDU,1,8},
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
	{&R0VZ71LZ2,1,42},
	{&A2IS33LDU,1,4},
	{&A3IS31LDU,1,8},
	{&A3IS33LDU,1,2},
	{&A3IS35LDU,1,0},
	{&A4IS10LDU,1,6},
	{&A1VN71LZ2,1,40},
	{&A3IS21LDU,1,24},
	{&A2IS21LDU,1,22},
	{&A3VZ15LZ2,1,36},
	{&A1IS21LDU,1,16},
	{&A3VZ13LZ2,1,34},
	{&R0AD14LZ2,1,38},
	{&R0IS02LDU,1,58},
	{&R0IS01LDU,1,56},
	{&A4IS21LDU,1,28},
	{&A1IS11LDU,1,14},
	{&A4IS11LDU,1,26},
	{&A2IS11LDU,1,20},
	{&A2IS12LDU,1,18},
	{&R0DE03LDU,3,64},
	{&A1IS12LDU,1,12},
	{&A7AS31LDU,1,10},
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
	{&A5IS11LDU,1,20},
	{&B8IS11LDU,1,36},
	{&A5IS21LDU,1,22},
	{&R0DE04LDU,3,64},
	{&B5IS11LDU,1,28},
	{&B5IS21LDU,1,30},
	{&R4IS21LDU,1,12},
	{&R4IS22LDU,1,14},
	{&B3IS11LDU,1,4},
	{&A3IS11LDU,1,0},
	{&R4IS12LDU,1,10},
	{&R6IS21LDU,1,56},
	{&B8IS21LDU,1,38},
	{&B8IS12LDU,1,40},
	{&A6IS21LDU,1,18},
	{&A6IS11LDU,1,16},
	{&B6IS21LDU,1,26},
	{&A8IS22LDU,1,60},
	{&B6IS11LDU,1,24},
	{&R5IS21LDU,1,50},
	{&A8IS12LDU,1,58},
	{&B8IS22LDU,1,42},
	{&R3IS21LDU,1,34},
	{&R4IS11LDU,1,8},
	{&R5IS11LDU,1,48},
	{&A3IS22LDU,1,2},
	{&B3IS22LDU,1,6},
	{&R3IS11LDU,1,32},
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
	{&R6IS52LDU,1,58},
	{&B2IE02LDU,1,32},
	{&R6IS41LDU,1,52},
	{&R6IS51LDU,1,56},
	{&R6IS42LDU,1,54},
	{&R6IS32LDU,1,50},
	{&B2IE03LDU,1,36},
	{&B1IE04LDU,1,30},
	{&B1IE03LDU,1,28},
	{&B2IE04LDU,1,38},
	{&A3IE04LDU,1,22},
	{&A3IE03LDU,1,20},
	{&B3IE03LDU,1,44},
	{&A2IE04LDU,1,14},
	{&A2IE03LDU,1,12},
	{&A1IE04LDU,1,6},
	{&B3IE04LDU,1,46},
	{&A1IE03LDU,1,4},
	{&A1IE01LDU,1,2},
	{&A3IE01LDU,1,18},
	{&A2IE01LDU,1,10},
	{&R6IS31LDU,1,48},
	{&B3IE02LDU,1,40},
	{&B1IE02LDU,1,24},
	{&R0DE05LDU,3,64},
	{&B3IE01LDU,1,42},
	{&B2IE01LDU,1,34},
	{&B1IE01LDU,1,26},
	{&A2IE02LDU,1,8},
	{&A3IE02LDU,1,16},
	{&A1IE02LDU,1,0},
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
	{&A2AD04LDU,1,10},
	{&A2AD05LDU,1,12},
	{&A2AD03LDU,1,8},
	{&A2AD02LDU,1,6},
	{&A2AD21LDU,1,2},
	{&A2AD01LDU,1,4},
	{&B2AD11LDU,1,14},
	{&B2AD21LDU,1,16},
	{&B2AD02LDU,1,20},
	{&B2AD03LDU,1,22},
	{&B2AD04LDU,1,24},
	{&B2AD05LDU,1,26},
	{&A2AD11LDU,1,0},
	{&B2AD01LDU,1,18},
	{&R0DE07LDU,3,38},
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
	{&B1AD21LDU,1,16},
	{&B1AD01LDU,1,18},
	{&B1AD05LDU,1,26},
	{&B1AD04LDU,1,24},
	{&B1AD03LDU,1,22},
	{&B1AD02LDU,1,20},
	{&A1AD01LDU,1,4},
	{&A1AD05LDU,1,12},
	{&A1AD04LDU,1,10},
	{&A1AD03LDU,1,8},
	{&A1AD02LDU,1,6},
	{&A1AD21LDU,1,2},
	{&A1AD11LDU,1,0},
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
	{&R4AD20LDU,1,26},
	{&B2AD33LDU,1,4},
	{&B3AD34LDU,1,0},
	{&B3AD31LDU,1,8},
	{&A8AD20LDU,1,14},
	{&R0DE09LDU,3,38},
	{&A8AD10LDU,1,12},
	{&B4AD10LDU,1,6},
	{&B8AD20LDU,1,30},
	{&B7AP31LDU,1,10},
	{&B8AD10LDU,1,28},
	{&B6AD20LDU,1,22},
	{&B6AD10LDU,1,20},
	{&A6AD20LDU,1,18},
	{&A6AD10LDU,1,16},
	{&B3AD33LDU,1,2},
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
	{&A3AD33LDU,1,2},
	{&A3AD34LDU,1,0},
	{&A3AD31LDU,1,8},
	{&R1AD10LDU,1,12},
	{&R1AD20LDU,1,14},
	{&A2AD33LDU,1,4},
	{&R2AD10LDU,1,16},
	{&R2AD20LDU,1,18},
	{&R0DE0ALDU,3,38},
	{&A4AD10LDU,1,6},
	{&B5AD10LDU,1,24},
	{&B5AD20LDU,1,26},
	{&A5AD10LDU,1,20},
	{&A5AD20LDU,1,22},
	{&A7AP31LDU,1,10},
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
	{&B3AD03LDU,1,22},
	{&B3AD02LDU,1,20},
	{&B3AD04LDU,1,24},
	{&B3AD21LDU,1,16},
	{&B3AD05LDU,1,26},
	{&B3AD01LDU,1,18},
	{&B3AD11LDU,1,14},
	{&A9AD10LDU,1,28},
	{&R0DE0BLDU,3,38},
	{&B9AD10LDU,1,30},
	{&A3AD11LDU,1,0},
	{&A3AD21LDU,1,2},
	{&A3AD02LDU,1,6},
	{&A3AD01LDU,1,4},
	{&A3AD05LDU,1,12},
	{&A3AD04LDU,1,10},
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
	{&B3IP02IDU,3,3},
	{&R0DE0CLDU,3,26},
	{&A3IP02IDU,3,0},
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
	{&A5VS22LDU,1,22},
	{&B5VS22LDU,1,28},
	{&B5VS12LDU,1,26},
	{&R0DE0DLDU,3,64},
	{&R4VS12LDU,1,2},
	{&A5VS12LDU,1,20},
	{&R1VS12LDU,1,8},
	{&R2VS12LDU,1,14},
	{&R2VS22LDU,1,16},
	{&R4VS22LDU,1,4},
	{&R1VS22LDU,1,10},
	{&R6IS61LDU,1,0},
	{&R2IE01LDU,1,18},
	{&R1IE01LDU,1,12},
	{&A5IE02LDU,1,24},
	{&B5IE01LDU,1,30},
	{&R0IE02LDU,1,44},
	{&A8IE01LDU,1,6},
	{&A6VS22LDU,1,34},
	{&A6VS12LDU,1,32},
	{&B6VS22LDU,1,40},
	{&B6VS12LDU,1,38},
	{&R0IE01LDU,1,46},
	{&A6IE01LDU,1,36},
	{&B6IE01LDU,1,42},
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
	{&R0AD16LDU,1,24},
	{&R0AD05LZ2,1,30},
	{&R0AD05LZ1,1,20},
	{&R0AD04LZ2,1,28},
	{&R0AD04LZ1,1,18},
	{&R0AD03LZ2,1,26},
	{&R0AD03LZ1,1,16},
	{&R8AD21LDU,1,22},
	{&B1AD32LDU,1,8},
	{&A1AD32LDU,1,0},
	{&B2AD32LDU,1,12},
	{&R0DE0FLDU,3,38},
	{&A2AD32LDU,1,4},
	{&B1AD31LDU,1,10},
	{&A1AD31LDU,1,2},
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
	{&R0DEB4LDU,1,24},
	{&R0DEB1LDU,1,18},
	{&R0DEB3LDU,1,22},
	{&R0DE39LDU,1,16},
	{&R0DE35LDU,1,8},
	{&R0DE36LDU,1,10},
	{&R0DE34LDU,1,6},
	{&R0DE33LDU,1,4},
	{&R0DE37LDU,1,12},
	{&R0DE32LDU,1,2},
	{&R0DE38LDU,1,14},
	{&R0DEB2LDU,1,20},
	{&R0DE31LDU,1,0},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0x02,0x01,5,86,def_buf_VENCF,&table_VENCF}, //VENCF
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
	setAsFloat(740,0.00009765625);
	setAsInt(741,1024200);
	setAsInt(742,-200);
	setAsInt(743,-200);
	setAsInt(744,1024200);
	setAsFloat(745,0.00009765625);
	setAsInt(746,-200);
	setAsInt(747,1689599);
	setAsFloat(748,0.00009765625);
	setAsInt(749,-200);
	setAsFloat(750,0.0009765625);
	setAsInt(751,1536200);
	setAsFloat(752,100);
	setAsFloat(753,200);
	setAsFloat(754,300);
	setAsFloat(755,400);
	setAsFloat(756,600);
	setAsFloat(757,500);
	setAsFloat(758,750);
	setAsFloat(759,2.5);
	setAsFloat(760,0);
	setAsFloat(761,0.46);
	setAsFloat(762,0.49);
	setAsFloat(763,0.52);
	setAsFloat(764,0.53);
	setAsFloat(765,0.67);
	setAsFloat(766,0.56);
	setAsFloat(767,4);
	setAsFloat(768,4);
	setAsFloat(769,10.91);
	setAsFloat(770,3);
	setAsShort(771,4);
	setAsFloat(772,0.4);
	setAsFloat(773,0.4);
	setAsFloat(774,0.4);
	setAsFloat(775,0.4);
	setAsFloat(776,0.03);
	setAsFloat(777,0.04);
	setAsFloat(778,3);
	setAsFloat(779,0.4);
	setAsFloat(780,0.4);
	setAsFloat(781,0.07);
	setAsFloat(782,0.04);
	setAsFloat(783,3);
	setAsFloat(784,0.55);
	setAsFloat(785,0.64);
	setAsFloat(786,0.180);
	setAsFloat(787,1.0);
	setAsFloat(788,0.1);
	setAsFloat(789,2);
	setAsFloat(790,0.3);
	setAsFloat(791,3);
	setAsFloat(792,1.50);
	setAsFloat(793,0.04);
	setAsFloat(794,0.05);
	setAsFloat(795,3);
	setAsFloat(796,1.50);
	setAsFloat(797,3);
	setAsFloat(798,1.50);
	setAsFloat(799,2);
	setAsFloat(800,0.004);
	setAsFloat(801,0.006);
	setAsFloat(802,0.006);
	setAsFloat(803,1.0);
	setAsFloat(804,0.01);
	setAsFloat(805,1);
	setAsFloat(806,0.008);
	setAsFloat(807,0.01);
	setAsFloat(808,1);
	setAsFloat(809,0.4);
	setAsFloat(810,120);
	setAsFloat(811,0.6);
	setAsFloat(812,1);
	setAsFloat(813,2);
	setAsFloat(814,1.50);
	setAsFloat(815,2.0);
	setAsFloat(816,1);
	setAsFloat(817,15);
	setAsFloat(818,0.50);
	setAsFloat(819,360);
	setAsFloat(820,1);
	setAsFloat(821,2);
	setAsFloat(822,1.0);
	setAsFloat(823,6.0);
	setAsFloat(824,0.50);
	setAsFloat(825,1.0);
	setAsFloat(826,16.0);
	setAsFloat(827,3.0);
	setAsFloat(828,1.0);
	setAsFloat(829,60.0);
	setAsFloat(830,0.50);
	setAsFloat(831,1.0);
	setAsFloat(832,20.0);
	setAsFloat(833,1);
	setAsFloat(834,2.0);
	setAsFloat(835,2.0);
	setAsFloat(836,1.5);
	setAsFloat(837,0.06);
	setAsFloat(838,0.008);
	setAsFloat(839,0.045);
	setAsFloat(840,0.040);
	setAsFloat(841,0.007);
	setAsFloat(842,0.014);
	setAsFloat(843,2000.0);
	setAsFloat(844,1500.0);
	setAsFloat(845,1000.0);
	setAsFloat(846,800.0);
	setAsFloat(847,500.0);
	setAsFloat(848,200.0);
	setAsFloat(849,100.0);
	setAsFloat(850,0.001);
	setAsFloat(851,100);
	setAsFloat(852,100);
	setAsFloat(853,110.0);
	setAsFloat(854,20);
	setAsFloat(855,30.0);
	setAsFloat(856,100.0);
	setAsFloat(857,1.50);
	setAsFloat(858,170);
	setAsFloat(859,170);
	setAsFloat(860,10);
	setAsShort(861,1);
	setAsShort(862,4);
	setAsShort(863,1);
	setAsShort(864,4);
	setAsShort(865,4);
	setAsShort(866,4);
	setAsShort(867,4);
	setAsBool(868,0);
	setAsFloat(869,159.99);
	setAsFloat(870,0.002375);
	setAsFloat(871,0.000877);
	setAsFloat(872,0.001675);
	setAsFloat(873,2.5);
	setAsFloat(874,30);
	setAsFloat(875,30);
	setAsFloat(876,0.05);
	setAsFloat(877,0.05);
	setAsFloat(878,160.0);
	setAsFloat(879,-141.21);
	setAsFloat(880,71.40565);
	setAsFloat(881,0.271145);
	setAsFloat(882,24.93556615);
	setAsFloat(883,0.1268);
	setAsFloat(884,0.1567);
	setAsFloat(885,0.1858);
	setAsFloat(886,0.2066);
	setAsFloat(887,0.2646);
	setAsFloat(888,0.2995);
	setAsFloat(889,0.839554030);
	setAsFloat(890,0.78859401);
	setAsFloat(891,0.765962);
	setAsFloat(892,0.67256403);
	setAsFloat(893,0.42476001);
	setAsFloat(894,0.25501999);
	setAsFloat(895,3600.0);
	setAsFloat(896,0.935);
	setAsFloat(897,0.1);
	setAsFloat(898,0.006792308);
	setAsFloat(899,0.000418877);
	setAsFloat(900,0.001);
	setAsFloat(901,0.20);
	setAsFloat(902,0.5);
	setAsFloat(903,2.0);
	setAsFloat(904,0.005);
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
uspaint8 InternalBuf[9697];

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
ssint iRM_13_ = {13,0}; /* N-число входов */ 
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
ssint iRM_14_ = {14,0}; /* n - N-размерность массива входных параметров */ 
ssfloat fRM_1_0 = {1.0,0}; /* tz - ширина импульса, sek */ 
ssfloat fRM_1_ = {1,0}; /*  */ 

uspaint8 SpaEEPROMBuf[806];

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
ssfloat var14;
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
ssint var232;
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
ssint var358;
ssbool var359;
ssbool var360;
ssint var361;
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
ssfloat var406;
ssbool var407;
ssbool var408;
ssbool var409;
ssbool var410;
ssbool var411;
ssbool var412;
ssbool var413;
ssbool var414;
ssbool var415;
ssfloat var416;
ssfloat var417;
ssbool var418;
ssbool var419;
ssbool var420;
ssfloat var421;
ssbool var422;
ssbool var423;
ssfloat var424;
ssbool var425;
ssbool var426;
ssbool var427;
ssbool var428;
ssbool var429;
ssbool var430;
ssbool var431;
ssbool var432;
ssfloat var433;
ssfloat var434;
ssfloat var435;
ssfloat var436;
ssbool var437;
ssfloat var438;
ssfloat var439;
ssint var440;
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
ssfloat var531;
ssbool var532;
ssbool var533;
ssbool var534;
ssfloat var535;
ssbool var536;
ssbool var537;
ssbool var538;
ssfloat var539;
ssbool var540;
ssbool var541;
ssbool var542;
ssfloat var543;
ssbool var544;
ssbool var545;
ssbool var546;
ssfloat var547;
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
ssfloat var634;
ssfloat var635;
ssbool var636;
ssfloat var637;
ssfloat var638;
ssbool var639;
ssfloat var640;
ssfloat var641;
ssbool var642;
ssfloat var643;
ssfloat var644;
ssbool var645;
ssbool var646;
ssfloat var647;
ssfloat var648;
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
sslong var778;
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
ssbool var1186;
ssbool var1187;
ssfloat var1188;
ssbool var1189;
ssfloat var1190;
ssbool var1191;
ssfloat var1192;
ssbool var1193;
ssbool var1194;
ssbool var1195;
ssbool var1196;
ssfloat var1197;
ssfloat var1198;
ssfloat var1199;
ssfloat var1200;
ssfloat var1201;
ssfloat var1202;
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
ssint var1258;
ssint var1259;
ssbool var1260;
ssbool var1261;
ssbool var1262;
ssbool var1263;
ssbool var1264;
ssbool var1265;
sslong var1266;
ssbool var1267;
ssbool var1268;
ssbool var1269;
ssint var1270;
ssbool var1271;
ssbool var1272;
ssbool var1273;
ssbool var1274;
ssbool var1275;
ssbool var1276;
ssbool var1277;
ssbool var1278;
ssbool var1279;
ssint var1280;
ssint var1281;
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
ssbool var1319;
ssbool var1320;
sslong var1321;
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
ssbool var1338;
ssbool var1339;
ssfloat var1340;
ssbool var1341;
ssbool var1342;
ssbool var1343;
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
ssbool var1359;
ssint var1360;
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
ssbool var1383;
ssbool var1384;
ssfloat var1385;
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

/* Объявление массивов */
psbool  array_m179_x_2[13] = {&R0IE02LDU,&R0IE01LDU,&R1IE01LDU,&R2IE01LDU,&A5IE02LDU,&B5IE01LDU,&A6IE01LDU,&R6IS61LDU,&R6IS67LZZ,&R6IS68LZZ,&B6IE01LDU,&A8IE01LDU,&R6IS66LZZ};
psbool  array_m166_x_2[6] = {&var1857,&var1856,&var1855,&var1854,&var1853,&var1852};
psbool  array_m138_x_2[6] = {&var1863,&var1862,&var1861,&var1860,&var1859,&var1858};
psbool  array_m254_x_2[6] = {&var1922,&var1914,&var1928,&B0VT71LZ1,&B0VT71LZ2,&var1873};
psbool  array_m243_x_2[6] = {&var1923,&var1916,&var1929,&A0VT71LZ1,&A0VT71LZ2,&var1873};
psbool  array_m266_x_2[6] = {&var1907,&B0VP71LZ1,&B0VP71LZ2,&var1878,&var1877,&var1876};
psbool  array_m245_x_2[6] = {&var1908,&A0VP71LZ1,&A0VP71LZ2,&var1881,&var1880,&var1879};
psbool  array_m124_x_2[8] = {&var1940,&var1962,&var1958,&var1955,&var1952,&var1949,&var1943,&var1946};
psbool  array_m2506_x_1[6] = {&var229,&var228,&R0DE36LDU,&R0DE37LDU,&R0DE38LDU,&R0DE39LDU};
psint  array_m2488_x_1[14] = {&R0DE0DLDU,&R0DE0FLDU,&R0DE02LDU,&R0DE03LDU,&R0DE04LDU,&R0DE05LDU,&R0DE07LDU,&R0DE08LDU,&R0DE09LDU,&R0DE0ALDU,&R0DE0BLDU,&R0DE0CLDU,&R0DE01LDU,&R0DE06LDU};
psbool  array_m893_x_1[6] = {&var808,&var1442,&var1418,&var1407,&var1213,&var308};
psbool  array_m1332_x_1[6] = {&var807,&var1422,&var235,&var1444,&var1213,&var328};
psbool  array_m661_x_1[6] = {&var1003,&var1312,&var1729,&var1273,&var1688,&var1306};
psbool  array_m660_x_1[6] = {&var1003,&var1313,&var1729,&var1273,&var1688,&var1305};
psfloat  array_m2396_a_1[6] = {&fEM_R0UN70LDU,&fEM_R0UN71LDU,&fEM_R0UN72LDU,&fEM_R0UN73LDU,&fEM_R0UN74LDU,&fEM_R0UN75LDU};
psfloat  array_m2396_b_1[6] = {&fEM_R0UN80LDU,&fEM_R0UN81LDU,&fEM_R0UN82LDU,&fEM_R0UN83LDU,&fEM_R0UN84LDU,&fEM_R0UN85LDU};
psfloat  array_m2408_x_1[4] = {&B0CT01IZ1,&A0CT01IZ1,&B0CT01IZ2,&A0CT01IZ2};
psbool  array_m2398_x_1[14] = {&var420,&var393,&var1037,&var453,&var455,&var391,&var1851,&var1431,&var1429,&var1874,&var419,&var408,&var404,&var427};
psbool  array_m1_x_1[47] = {&var1394,&lRM_0_,&var552,&var283,&var692,&var1598,&var926,&R0MD34LP1,&var840,&R0MD34LP1,&var899,&R0MD34LP1,&var1133,&R0MD34LP1,&var953,&R0MD34LP1,&var1131,&var1625,&A2IS12LDU,&var609,&var1425,&var1320,&var1318,&var1231,&var1046,&R0MD34LP1,&var629,&var670,&var1469,&var1779,&R0MD34LP1,&var5,&var776,&var731,&B3IS35LDU,&B3IS35LDU,&var474,&var281,&var703,&var521,&var1830,&var1788,&var1815,&var1152,&var1802,&R2IS21LDU,&var394};
psfloat  array_m1641_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psbool  array_m1593_x_1[5] = {&var5,&var4,&var3,&var2,&var1};
psbool  array_m611_x_1[12] = {&var951,&var957,&var958,&var949,&var950,&var1135,&var1136,&var447,&var946,&var947,&var945,&var953};
psfloat  array_m88_x_1[2] = {&R0VN11RZ2,&R0VN11RZ1};
psfloat  array_m90_x_1[8] = {&fEM_R0UN01RDU,&fEM_R0UN02RDU,&fEM_R0UN03RDU,&fEM_R0UN04RDU,&fEM_R0UN05RDU,&fEM_R0UN06RDU,&fEM_R0UN07RDU,&fEM_R0UN08RDU};
psfloat  array_m1186_x_1[2] = {&R0VN11RZ2,&R0VN11RZ1};
psfloat  array_m1339_x_1[8] = {&var1690,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m903_x_1[8] = {&var1649,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m999_x_1[8] = {&var1540,&var417,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m1455_x_1[8] = {&var1508,&var416,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m543_x_1[8] = {&var1569,&var543,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m170_x_1[8] = {&var1602,&var547,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m351_Tpr_1[10] = {&fRM_6_0,&fRM_126_0,&fRM_246_0,&fRM_366_0,&fRM_486_0,&fRM_606_0,&fRM_726_0,&fRM_846_0,&fRM_966_0,&fRM_1200_0};
pschar  array_m351_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m351_rz_1[10];
psbool  array_m355_x_1[5] = {&var1261,&var1262,&var1263,&var1264,&var1265};
psbool  array_m289_x_1[7] = {&var1037,&var449,&var1240,&var1237,&var455,&var453,&var451};
psfloat  array_m293_Tpr_1[10] = {&fRM_10_0,&fRM_30_0,&fRM_50_0,&fRM_70_0,&fRM_90_0,&fRM_110_0,&fRM_130_0,&fRM_150_0,&fRM_170_0,&fRM_200_0};
pschar  array_m293_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m293_rz_1[10];
psfloat  array_m1573_Tpr_1[6] = {&fRM_0_5,&fRM_3_5,&fRM_6_5,&fRM_9_5,&fRM_12_5,&fRM_15_5};
pschar  array_m1573_type_1[6] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_6_};
pschar  array_m1573_rz_1[6];
psbool  array_m309_x_1[5] = {&var1283,&var1284,&var1285,&var1286,&var1287};
psbool  array_m1313_x_1[5] = {&var1406,&var1020,&var1761,&var1411,&var465};
psbool  array_m1301_x_1[4] = {&var1317,&var1359,&var1233,&var1409};
psfloat  array_m1625_x_1[16] = {&var634,&var643,&fRM_0_,&var640,&fRM_0_,&fRM_0_,&fRM_0_,&var637,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&var647};
psbool  array_m1957_x_1[17] = {&var714,&var715,&var721,&var716,&var712,&var713,&var1170,&var717,&var718,&var1458,&var719,&var720,&var1450,&var1451,&var1460,&var459,&var460};
psbool  array_m1576_x_1[5] = {&var626,&var749,&var766,&var767,&var656};
psint  array_m328_x_1[3] = {&var1259,&iRM_0_,&var1281};
psint  array_m319_x_1[3] = {&var1258,&iRM_0_,&var1280};
psbool  array_m663_x_1[5] = {&var986,&var1728,&var1495,&var1214,&var425};
psbool  array_m1527_x_1[8] = {&var870,&var871,&var872,&var867,&var866,&var865,&var1131,&var863};
psbool  array_m1454_x_1[3] = {&var310,&lRM_0_,&var309};
psfloat  array_m1456_Lt_fw_1[1] = {&fEM_A3UC81RDU};
psint  array_m1456_Vr_fw_1[1] = {&iEM_A3UV01IDU};
psfloat  array_m1456_Lt_bw_1[1] = {&fEM_A3UC82RDU};
psint  array_m1456_Vr_bw_1[1] = {&iEM_A3UV02IDU};
psfloat  array_m1482_x0_1[60];
psfloat  array_m1482_tim0_1[60];
psbool  array_m1077_x_1[8] = {&var885,&var887,&var888,&var880,&var886,&var882,&var1133,&var624};
psbool  array_m998_x_1[3] = {&var336,&lRM_0_,&var331};
psfloat  array_m1000_Lt_fw_1[1] = {&fEM_A3UC81RDU};
psint  array_m1000_Vr_fw_1[1] = {&iEM_A3UV01IDU};
psfloat  array_m1000_Lt_bw_1[1] = {&fEM_A3UC82RDU};
psint  array_m1000_Vr_bw_1[1] = {&iEM_A3UV02IDU};
psfloat  array_m1030_x0_1[60];
psfloat  array_m1030_tim0_1[60];
psbool  array_m542_x_1[3] = {&var962,&lRM_0_,&var963};
psfloat  array_m545_Lt_fw_1[2] = {&fEM_A1UC81RDU,&fEM_A1UC82RDU};
psint  array_m545_Vr_fw_1[2] = {&iEM_A1UV01IDU,&iEM_A1UV02IDU};
psfloat  array_m545_Lt_bw_1[1] = {&fEM_A1UC83RDU};
psint  array_m545_Vr_bw_1[1] = {&iEM_A1UV03IDU};
psfloat  array_m568_x0_1[150];
psfloat  array_m568_tim0_1[150];
psbool  array_m245_x_1[12] = {&var931,&var933,&var932,&var929,&var927,&var926,&var925,&var1139,&var1138,&var920,&var923,&var448};
psbool  array_m172_x_1[3] = {&var1109,&lRM_0_,&var1110};
psfloat  array_m175_Lt_fw_1[2] = {&fEM_A1UC81RDU,&fEM_A1UC82RDU};
psint  array_m175_Vr_fw_1[2] = {&iEM_A1UV01IDU,&iEM_A1UV02IDU};
psfloat  array_m175_Lt_bw_1[1] = {&fEM_A1UC83RDU};
psint  array_m175_Vr_bw_1[1] = {&iEM_A1UV03IDU};
psfloat  array_m200_x0_1[150];
psfloat  array_m200_tim0_1[150];
psbool  array_m962_x_1[10] = {&var897,&var898,&var904,&var905,&var903,&var901,&var900,&var1141,&var1140,&var899};
psbool  array_m902_x_1[3] = {&var312,&var915,&var311};
psfloat  array_m904_Lt_fw_1[2] = {&fEM_A2UC81RDU,&fEM_A2UC82RDU};
psint  array_m904_Vr_fw_1[2] = {&iEM_A2UV01IDU,&iEM_A2UV02IDU};
psfloat  array_m904_Lt_bw_1[1] = {&fEM_A2UC83RDU};
psint  array_m904_Vr_bw_1[1] = {&iEM_A2UV03CDU};
psfloat  array_m922_x0_1[80];
psfloat  array_m922_tim0_1[80];
psfloat  array_m1773_Lt_fw_1[1] = {&fRM_1000_};
psint  array_m1773_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1773_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1773_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1423_x_1[10] = {&var836,&var837,&var839,&var838,&var840,&var842,&var844,&var841,&var843,&var845};
psbool  array_m153_x_1[5] = {&A1IS21LDU,&A3IS21LDU,&A2IS21LDU,&var1156,&var1155};
psfloat  array_m1246_Lt_fw_1[1] = {&fRM_2000_};
psint  array_m1246_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1246_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1246_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1342_x_1[3] = {&var340,&var830,&var327};
psfloat  array_m1343_Lt_fw_1[2] = {&fEM_A2UC81RDU,&fEM_A2UC82RDU};
psint  array_m1343_Vr_fw_1[2] = {&iEM_A2UV01IDU,&iEM_A2UV02IDU};
psfloat  array_m1343_Lt_bw_1[1] = {&fEM_A2UC83RDU};
psint  array_m1343_Vr_bw_1[1] = {&iEM_A2UV03CDU};
psfloat  array_m1378_x0_1[80];
psfloat  array_m1378_tim0_1[80];
psfloat  array_m1795_x0_1[20];
psfloat  array_m1795_tim0_1[20];
psbool  array_m1209_x_1[8] = {&var1047,&var1044,&var1045,&var1046,&var1043,&var1042,&var1041,&var1040};
psbool  array_m664_x_1[18] = {&R0MD31LP1,&var739,&var1061,&var741,&var1059,&var831,&var966,&var914,&var941,&var961,&var890,&var855,&var1117,&var564,&var563,&var821,&var481,&var418};
psfloat  array_m1273_x0_1[20];
psfloat  array_m1273_tim0_1[20];
psbool  array_m476_x_1[7] = {&var1162,&var1161,&var1160,&var1159,&var1832,&var1151,&var593};
psbool  array_m454_x_1[7] = {&var1164,&var1832,&var1152,&var1165,&var1163,&var1150,&var364};
psbool  array_m849_x_1[17] = {&var1062,&var1107,&var1106,&var1103,&var1102,&var1099,&var1064,&var1101,&var1069,&var1098,&var1094,&var1096,&var1095,&var1066,&var1060,&var1149,&var917};
psbool  array_m139_x_1[21] = {&var940,&var960,&var1205,&var913,&var1204,&var1203,&var1766,&var1775,&var1793,&var1784,&var1820,&var1811,&var692,&var594,&var1195,&var1196,&var1472,&var1466,&var1630,&var1621,&var1802};

/* Объявление структур */
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
_S_or3  S_or3_161_2 = {&var1888,&var1025,&var1882,&var1889};
_S_and4  S_and4_136_2 = {&A0EE03LZ1,&A0EE01LZ1,&A0EE01LZ2,&A0EE03LZ2,&var1890};
_S_or3  S_or3_135_2 = {&var1890,&var1883,&var1025,&var1891};
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
_S_and2  S_and2_265_2 = {&var616,&var1884,&var1907};
_S_and2  S_and2_244_2 = {&var616,&var1885,&var1908};
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
_S_or2  S_or2_1599_1 = {&var1833,&var1294,&var1};
_S_or2  S_or2_1592_1 = {&var1834,&var1293,&var2};
_S_or2  S_or2_1587_1 = {&var1835,&var1292,&var3};
_S_or2  S_or2_1583_1 = {&var1836,&var1291,&var4};
_S_or2  S_or2_1578_1 = {&var1837,&var1290,&var5};
_S_noto  S_noto_56_1 = {&var601,&var6};
_S_and2  S_and2_1586_1 = {&var1835,&R0MD11LP2,&var7};
_S_and2  S_and2_1591_1 = {&var1834,&R0MD11LP2,&var8};
_S_and2  S_and2_1582_1 = {&var1836,&R0MD11LP2,&var9};
_S_and2  S_and2_1598_1 = {&var1833,&R0MD11LP2,&var10};
_S_and2  S_and2_1577_1 = {&var1837,&R0MD11LP2,&var11};
_S_and2  S_and2_1602_1 = {&var1288,&var1294,&var12};
_S_or2  S_or2_2056_1 = {&R8AD22LDU,&var629,&var13};
_S_period  S_period_78_1 = {&var1188,&lRM_1_,&iRM_5_,&fEM_R0UL01RSS,&fEM_R0UL02RSS,&fEM_R0UN03RSS,&var14,&internal1_m78_flst,&internal1_m78_chsr,&internal1_m78_chizm,&internal1_m78_sumtim,&internal1_m78_W1,&internal1_m78_W2,&internal1_m78_Wmin,&internal1_m78_Wmax,&internal1_m78_Wlast,&internal1_m78_y0,&internal1_m78_MyFirstEnterFlag};
_S_ovbsb  S_ovbsb_2035_1 = {&var594,&var15,&internal1_m2035_tx};
_S_ovbsb  S_ovbsb_2034_1 = {&var692,&var16,&internal1_m2034_tx};
_S_ovbsb  S_ovbsb_780_1 = {&var1093,&var17,&internal1_m780_tx};
_S_ovbsb  S_ovbsb_737_1 = {&var1092,&var18,&internal1_m737_tx};
_S_ovbsb  S_ovbsb_790_1 = {&var1095,&var19,&internal1_m790_tx};
_S_ovbsb  S_ovbsb_792_1 = {&var1094,&var20,&internal1_m792_tx};
_S_ovbsb  S_ovbsb_791_1 = {&var1096,&var21,&internal1_m791_tx};
_S_ovbsb  S_ovbsb_746_1 = {&var1064,&var22,&internal1_m746_tx};
_S_ovbsb  S_ovbsb_730_1 = {&var1069,&var23,&internal1_m730_tx};
_S_ovbsb  S_ovbsb_741_1 = {&var1066,&var24,&internal1_m741_tx};
_S_ovbsb  S_ovbsb_772_1 = {&var1099,&var25,&internal1_m772_tx};
_S_ovbsb  S_ovbsb_789_1 = {&var1098,&var26,&internal1_m789_tx};
_S_ovbsb  S_ovbsb_762_1 = {&var1102,&var27,&internal1_m762_tx};
_S_ovbsb  S_ovbsb_393_1 = {&var1804,&var28,&internal1_m393_tx};
_S_ovbsb  S_ovbsb_392_1 = {&var1803,&var29,&internal1_m392_tx};
_S_ovbsb  S_ovbsb_391_1 = {&var1805,&var30,&internal1_m391_tx};
_S_ovbsb  S_ovbsb_390_1 = {&var1802,&var31,&internal1_m390_tx};
_S_ovbsb  S_ovbsb_761_1 = {&var1103,&var32,&internal1_m761_tx};
_S_ovbsb  S_ovbsb_756_1 = {&var1106,&var33,&internal1_m756_tx};
_S_ovbsb  S_ovbsb_764_1 = {&var1107,&var34,&internal1_m764_tx};
_S_ovbsb  S_ovbsb_770_1 = {&var1101,&var35,&internal1_m770_tx};
_S_ovbsb  S_ovbsb_526_1 = {&var1623,&var36,&internal1_m526_tx};
_S_ovbsb  S_ovbsb_525_1 = {&var1622,&var37,&internal1_m525_tx};
_S_ovbsb  S_ovbsb_524_1 = {&var1624,&var38,&internal1_m524_tx};
_S_ovbsb  S_ovbsb_520_1 = {&var1621,&var39,&internal1_m520_tx};
_S_ovbsb  S_ovbsb_497_1 = {&var1632,&var40,&internal1_m497_tx};
_S_ovbsb  S_ovbsb_496_1 = {&var1631,&var41,&internal1_m496_tx};
_S_ovbsb  S_ovbsb_495_1 = {&var1633,&var42,&internal1_m495_tx};
_S_ovbsb  S_ovbsb_498_1 = {&var1630,&var43,&internal1_m498_tx};
_S_ovbsb  S_ovbsb_2437_1 = {&var418,&var44,&internal1_m2437_tx};
_S_ovbsb  S_ovbsb_2149_1 = {&var402,&var45,&internal1_m2149_tx};
_S_ovbsb  S_ovbsb_2436_1 = {&var422,&var46,&internal1_m2436_tx};
_S_ovbsb  S_ovbsb_2435_1 = {&var429,&var47,&internal1_m2435_tx};
_S_ovbsb  S_ovbsb_2433_1 = {&var430,&var48,&internal1_m2433_tx};
_S_ovbsb  S_ovbsb_108_1 = {&var550,&var49,&internal1_m108_tx};
_S_ovbsb  S_ovbsb_1144_1 = {&var821,&var50,&internal1_m1144_tx};
_S_ovbsb  S_ovbsb_2295_1 = {&var1467,&var51,&internal1_m2295_tx};
_S_ovbsb  S_ovbsb_2294_1 = {&var1468,&var52,&internal1_m2294_tx};
_S_ovbsb  S_ovbsb_2293_1 = {&var1466,&var53,&internal1_m2293_tx};
_S_ovbsb  S_ovbsb_1234_1 = {&var1041,&var54,&internal1_m1234_tx};
_S_ovbsb  S_ovbsb_1233_1 = {&var1042,&var55,&internal1_m1233_tx};
_S_ovbsb  S_ovbsb_1228_1 = {&var1043,&var56,&internal1_m1228_tx};
_S_ovbsb  S_ovbsb_1221_1 = {&var1047,&var57,&internal1_m1221_tx};
_S_ovbsb  S_ovbsb_1219_1 = {&var1044,&var58,&internal1_m1219_tx};
_S_ovbsb  S_ovbsb_1217_1 = {&var1045,&var59,&internal1_m1217_tx};
_S_ovbsb  S_ovbsb_1215_1 = {&var1046,&var60,&internal1_m1215_tx};
_S_ovbsb  S_ovbsb_1258_1 = {&var1722,&var61,&internal1_m1258_tx};
_S_ovbsb  S_ovbsb_1265_1 = {&var1723,&var62,&internal1_m1265_tx};
_S_ovbsb  S_ovbsb_1270_1 = {&var1736,&var63,&internal1_m1270_tx};
_S_ovbsb  S_ovbsb_1276_1 = {&var1196,&var64,&internal1_m1276_tx};
_S_ovbsb  S_ovbsb_1236_1 = {&var1040,&var65,&internal1_m1236_tx};
_S_ovbsb  S_ovbsb_1257_1 = {&var1730,&var66,&internal1_m1257_tx};
_S_ovbsb  S_ovbsb_1271_1 = {&var1731,&var67,&internal1_m1271_tx};
_S_ovbsb  S_ovbsb_475_1 = {&var1162,&var68,&internal1_m475_tx};
_S_ovbsb  S_ovbsb_469_1 = {&var1161,&var69,&internal1_m469_tx};
_S_ovbsb  S_ovbsb_471_1 = {&var1160,&var70,&internal1_m471_tx};
_S_ovbsb  S_ovbsb_473_1 = {&var1159,&var71,&internal1_m473_tx};
_S_ovbsb  S_ovbsb_480_1 = {&var593,&var72,&internal1_m480_tx};
_S_ovbsb  S_ovbsb_434_1 = {&var1813,&var73,&internal1_m434_tx};
_S_ovbsb  S_ovbsb_432_1 = {&var1814,&var74,&internal1_m432_tx};
_S_ovbsb  S_ovbsb_433_1 = {&var1812,&var75,&internal1_m433_tx};
_S_ovbsb  S_ovbsb_426_1 = {&var1811,&var76,&internal1_m426_tx};
_S_ovbsb  S_ovbsb_888_1 = {&var1786,&var77,&internal1_m888_tx};
_S_ovbsb  S_ovbsb_887_1 = {&var1785,&var78,&internal1_m887_tx};
_S_ovbsb  S_ovbsb_886_1 = {&var1787,&var79,&internal1_m886_tx};
_S_ovbsb  S_ovbsb_882_1 = {&var1784,&var80,&internal1_m882_tx};
_S_ovbsb  S_ovbsb_1322_1 = {&var1767,&var81,&internal1_m1322_tx};
_S_ovbsb  S_ovbsb_1321_1 = {&var1768,&var82,&internal1_m1321_tx};
_S_ovbsb  S_ovbsb_1320_1 = {&var1766,&var83,&internal1_m1320_tx};
_S_ovbsb  S_ovbsb_1533_1 = {&var863,&var84,&internal1_m1533_tx};
_S_ovbsb  S_ovbsb_1546_1 = {&var856,&var85,&internal1_m1546_tx};
_S_ovbsb  S_ovbsb_1545_1 = {&var857,&var86,&internal1_m1545_tx};
_S_ovbsb  S_ovbsb_1544_1 = {&var860,&var87,&internal1_m1544_tx};
_S_ovbsb  S_ovbsb_1535_1 = {&var1131,&var88,&internal1_m1535_tx};
_S_ovbsb  S_ovbsb_2267_1 = {&var352,&var89,&internal1_m2267_tx};
_S_ovbsb  S_ovbsb_2250_1 = {&var370,&var90,&internal1_m2250_tx};
_S_ovbsb  S_ovbsb_2227_1 = {&var365,&var91,&internal1_m2227_tx};
_S_ovbsb  S_ovbsb_1543_1 = {&var861,&var92,&internal1_m1543_tx};
_S_ovbsb  S_ovbsb_1524_1 = {&var865,&var93,&internal1_m1524_tx};
_S_ovbsb  S_ovbsb_1523_1 = {&var866,&var94,&internal1_m1523_tx};
_S_ovbsb  S_ovbsb_1520_1 = {&var867,&var95,&internal1_m1520_tx};
_S_ovbsb  S_ovbsb_1542_1 = {&var862,&var96,&internal1_m1542_tx};
_S_ovbsb  S_ovbsb_1508_1 = {&var871,&var97,&internal1_m1508_tx};
_S_ovbsb  S_ovbsb_1510_1 = {&var870,&var98,&internal1_m1510_tx};
_S_ovbsb  S_ovbsb_1507_1 = {&var872,&var99,&internal1_m1507_tx};
_S_ovbsb  S_ovbsb_1480_1 = {&var1519,&var100,&internal1_m1480_tx};
_S_ovbsb  S_ovbsb_1479_1 = {&var1518,&var101,&internal1_m1479_tx};
_S_ovbsb  S_ovbsb_1488_1 = {&var1524,&var102,&internal1_m1488_tx};
_S_ovbsb  S_ovbsb_1492_1 = {&var1203,&var103,&internal1_m1492_tx};
_S_ovbsb  S_ovbsb_981_1 = {&var896,&var104,&internal1_m981_tx};
_S_ovbsb  S_ovbsb_984_1 = {&var895,&var105,&internal1_m984_tx};
_S_ovbsb  S_ovbsb_2218_1 = {&var563,&var106,&internal1_m2218_tx};
_S_ovbsb  S_ovbsb_974_1 = {&var1140,&var107,&internal1_m974_tx};
_S_ovbsb  S_ovbsb_972_1 = {&var1141,&var108,&internal1_m972_tx};
_S_ovbsb  S_ovbsb_980_1 = {&var897,&var109,&internal1_m980_tx};
_S_ovbsb  S_ovbsb_966_1 = {&var901,&var110,&internal1_m966_tx};
_S_ovbsb  S_ovbsb_959_1 = {&var900,&var111,&internal1_m959_tx};
_S_ovbsb  S_ovbsb_958_1 = {&var899,&var112,&internal1_m958_tx};
_S_ovbsb  S_ovbsb_979_1 = {&var898,&var113,&internal1_m979_tx};
_S_ovbsb  S_ovbsb_946_1 = {&var905,&var114,&internal1_m946_tx};
_S_ovbsb  S_ovbsb_947_1 = {&var904,&var115,&internal1_m947_tx};
_S_ovbsb  S_ovbsb_944_1 = {&var903,&var116,&internal1_m944_tx};
_S_ovbsb  S_ovbsb_632_1 = {&var947,&var117,&internal1_m632_tx};
_S_ovbsb  S_ovbsb_635_1 = {&var1116,&var118,&internal1_m635_tx};
_S_ovbsb  S_ovbsb_634_1 = {&var1115,&var119,&internal1_m634_tx};
_S_ovbsb  S_ovbsb_624_1 = {&var447,&var120,&internal1_m624_tx};
_S_ovbsb  S_ovbsb_621_1 = {&var1135,&var121,&internal1_m621_tx};
_S_ovbsb  S_ovbsb_617_1 = {&var1136,&var122,&internal1_m617_tx};
_S_ovbsb  S_ovbsb_630_1 = {&var945,&var123,&internal1_m630_tx};
_S_ovbsb  S_ovbsb_607_1 = {&var949,&var124,&internal1_m607_tx};
_S_ovbsb  S_ovbsb_606_1 = {&var950,&var125,&internal1_m606_tx};
_S_ovbsb  S_ovbsb_602_1 = {&var953,&var126,&internal1_m602_tx};
_S_ovbsb  S_ovbsb_633_1 = {&var946,&var127,&internal1_m633_tx};
_S_ovbsb  S_ovbsb_590_1 = {&var951,&var128,&internal1_m590_tx};
_S_ovbsb  S_ovbsb_589_1 = {&var957,&var129,&internal1_m589_tx};
_S_ovbsb  S_ovbsb_592_1 = {&var958,&var130,&internal1_m592_tx};
_S_ovbsb  S_ovbsb_569_1 = {&var1579,&var131,&internal1_m569_tx};
_S_ovbsb  S_ovbsb_570_1 = {&var1580,&var132,&internal1_m570_tx};
_S_ovbsb  S_ovbsb_571_1 = {&var1585,&var133,&internal1_m571_tx};
_S_ovbsb  S_ovbsb_576_1 = {&var960,&var134,&internal1_m576_tx};
_S_ovbsb  S_ovbsb_2278_1 = {&var1472,&var135,&internal1_m2278_tx};
_S_ovbsb  S_ovbsb_2279_1 = {&var1474,&var136,&internal1_m2279_tx};
_S_ovbsb  S_ovbsb_2280_1 = {&var1473,&var137,&internal1_m2280_tx};
_S_ovbsb  S_ovbsb_1761_1 = {&var724,&var138,&internal1_m1761_tx};
_S_ovbsb  S_ovbsb_1760_1 = {&var725,&var139,&internal1_m1760_tx};
_S_ovbsb  S_ovbsb_1755_1 = {&var727,&var140,&internal1_m1755_tx};
_S_ovbsb  S_ovbsb_1746_1 = {&var728,&var141,&internal1_m1746_tx};
_S_ovbsb  S_ovbsb_1744_1 = {&var729,&var142,&internal1_m1744_tx};
_S_ovbsb  S_ovbsb_1742_1 = {&var730,&var143,&internal1_m1742_tx};
_S_ovbsb  S_ovbsb_1741_1 = {&var731,&var144,&internal1_m1741_tx};
_S_ovbsb  S_ovbsb_1782_1 = {&var1711,&var145,&internal1_m1782_tx};
_S_ovbsb  S_ovbsb_1790_1 = {&var1712,&var146,&internal1_m1790_tx};
_S_ovbsb  S_ovbsb_1797_1 = {&var1719,&var147,&internal1_m1797_tx};
_S_ovbsb  S_ovbsb_1798_1 = {&var1195,&var148,&internal1_m1798_tx};
_S_ovbsb  S_ovbsb_1788_1 = {&var1714,&var149,&internal1_m1788_tx};
_S_ovbsb  S_ovbsb_1763_1 = {&var723,&var150,&internal1_m1763_tx};
_S_ovbsb  S_ovbsb_1777_1 = {&var1713,&var151,&internal1_m1777_tx};
_S_ovbsb  S_ovbsb_452_1 = {&var1164,&var152,&internal1_m452_tx};
_S_ovbsb  S_ovbsb_443_1 = {&var1150,&var153,&internal1_m443_tx};
_S_ovbsb  S_ovbsb_444_1 = {&var364,&var154,&internal1_m444_tx};
_S_ovbsb  S_ovbsb_446_1 = {&var1165,&var155,&internal1_m446_tx};
_S_ovbsb  S_ovbsb_460_1 = {&var1163,&var156,&internal1_m460_tx};
_S_ovbsb  S_ovbsb_410_1 = {&var1820,&var157,&internal1_m410_tx};
_S_ovbsb  S_ovbsb_407_1 = {&var1822,&var158,&internal1_m407_tx};
_S_ovbsb  S_ovbsb_406_1 = {&var1821,&var159,&internal1_m406_tx};
_S_ovbsb  S_ovbsb_405_1 = {&var1823,&var160,&internal1_m405_tx};
_S_ovbsb  S_ovbsb_865_1 = {&var1793,&var161,&internal1_m865_tx};
_S_ovbsb  S_ovbsb_861_1 = {&var1795,&var162,&internal1_m861_tx};
_S_ovbsb  S_ovbsb_860_1 = {&var1794,&var163,&internal1_m860_tx};
_S_ovbsb  S_ovbsb_859_1 = {&var1796,&var164,&internal1_m859_tx};
_S_ovbsb  S_ovbsb_1303_1 = {&var1775,&var165,&internal1_m1303_tx};
_S_ovbsb  S_ovbsb_1300_1 = {&var1776,&var166,&internal1_m1300_tx};
_S_ovbsb  S_ovbsb_1299_1 = {&var1777,&var167,&internal1_m1299_tx};
_S_ovbsb  S_ovbsb_1082_1 = {&var624,&var168,&internal1_m1082_tx};
_S_ovbsb  S_ovbsb_2239_1 = {&var371,&var169,&internal1_m2239_tx};
_S_ovbsb  S_ovbsb_1093_1 = {&var877,&var170,&internal1_m1093_tx};
_S_ovbsb  S_ovbsb_1095_1 = {&var875,&var171,&internal1_m1095_tx};
_S_ovbsb  S_ovbsb_1094_1 = {&var874,&var172,&internal1_m1094_tx};
_S_ovbsb  S_ovbsb_2233_1 = {&var366,&var173,&internal1_m2233_tx};
_S_ovbsb  S_ovbsb_1084_1 = {&var1133,&var174,&internal1_m1084_tx};
_S_ovbsb  S_ovbsb_2238_1 = {&var355,&var175,&internal1_m2238_tx};
_S_ovbsb  S_ovbsb_1092_1 = {&var878,&var176,&internal1_m1092_tx};
_S_ovbsb  S_ovbsb_1074_1 = {&var882,&var177,&internal1_m1074_tx};
_S_ovbsb  S_ovbsb_1073_1 = {&var886,&var178,&internal1_m1073_tx};
_S_ovbsb  S_ovbsb_1069_1 = {&var880,&var179,&internal1_m1069_tx};
_S_ovbsb  S_ovbsb_1091_1 = {&var879,&var180,&internal1_m1091_tx};
_S_ovbsb  S_ovbsb_1059_1 = {&var885,&var181,&internal1_m1059_tx};
_S_ovbsb  S_ovbsb_1057_1 = {&var887,&var182,&internal1_m1057_tx};
_S_ovbsb  S_ovbsb_1056_1 = {&var888,&var183,&internal1_m1056_tx};
_S_ovbsb  S_ovbsb_1035_1 = {&var1550,&var184,&internal1_m1035_tx};
_S_ovbsb  S_ovbsb_1034_1 = {&var1551,&var185,&internal1_m1034_tx};
_S_ovbsb  S_ovbsb_1024_1 = {&var1556,&var186,&internal1_m1024_tx};
_S_ovbsb  S_ovbsb_1041_1 = {&var1204,&var187,&internal1_m1041_tx};
_S_ovbsb  S_ovbsb_1438_1 = {&var834,&var188,&internal1_m1438_tx};
_S_ovbsb  S_ovbsb_1437_1 = {&var835,&var189,&internal1_m1437_tx};
_S_ovbsb  S_ovbsb_2185_1 = {&var564,&var190,&internal1_m2185_tx};
_S_ovbsb  S_ovbsb_1428_1 = {&var838,&var191,&internal1_m1428_tx};
_S_ovbsb  S_ovbsb_1429_1 = {&var839,&var192,&internal1_m1429_tx};
_S_ovbsb  S_ovbsb_1436_1 = {&var836,&var193,&internal1_m1436_tx};
_S_ovbsb  S_ovbsb_1419_1 = {&var844,&var194,&internal1_m1419_tx};
_S_ovbsb  S_ovbsb_1418_1 = {&var842,&var195,&internal1_m1418_tx};
_S_ovbsb  S_ovbsb_1414_1 = {&var840,&var196,&internal1_m1414_tx};
_S_ovbsb  S_ovbsb_1435_1 = {&var837,&var197,&internal1_m1435_tx};
_S_ovbsb  S_ovbsb_1401_1 = {&var845,&var198,&internal1_m1401_tx};
_S_ovbsb  S_ovbsb_1399_1 = {&var843,&var199,&internal1_m1399_tx};
_S_ovbsb  S_ovbsb_1405_1 = {&var841,&var200,&internal1_m1405_tx};
_S_ovbsb  S_ovbsb_250_1 = {&var448,&var201,&internal1_m250_tx};
_S_ovbsb  S_ovbsb_265_1 = {&var923,&var202,&internal1_m265_tx};
_S_ovbsb  S_ovbsb_272_1 = {&var922,&var203,&internal1_m272_tx};
_S_ovbsb  S_ovbsb_271_1 = {&var924,&var204,&internal1_m271_tx};
_S_ovbsb  S_ovbsb_257_1 = {&var1138,&var205,&internal1_m257_tx};
_S_ovbsb  S_ovbsb_253_1 = {&var1139,&var206,&internal1_m253_tx};
_S_ovbsb  S_ovbsb_269_1 = {&var920,&var207,&internal1_m269_tx};
_S_ovbsb  S_ovbsb_241_1 = {&var929,&var208,&internal1_m241_tx};
_S_ovbsb  S_ovbsb_240_1 = {&var927,&var209,&internal1_m240_tx};
_S_ovbsb  S_ovbsb_236_1 = {&var926,&var210,&internal1_m236_tx};
_S_ovbsb  S_ovbsb_268_1 = {&var925,&var211,&internal1_m268_tx};
_S_ovbsb  S_ovbsb_225_1 = {&var933,&var212,&internal1_m225_tx};
_S_ovbsb  S_ovbsb_227_1 = {&var931,&var213,&internal1_m227_tx};
_S_ovbsb  S_ovbsb_224_1 = {&var932,&var214,&internal1_m224_tx};
_S_ovbsb  S_ovbsb_203_1 = {&var1616,&var215,&internal1_m203_tx};
_S_ovbsb  S_ovbsb_202_1 = {&var1617,&var216,&internal1_m202_tx};
_S_ovbsb  S_ovbsb_201_1 = {&var1618,&var217,&internal1_m201_tx};
_S_ovbsb  S_ovbsb_209_1 = {&var940,&var218,&internal1_m209_tx};
_S_ovbsb  S_ovbsb_1381_1 = {&var1706,&var219,&internal1_m1381_tx};
_S_ovbsb  S_ovbsb_1363_1 = {&var1701,&var220,&internal1_m1363_tx};
_S_ovbsb  S_ovbsb_1368_1 = {&var1700,&var221,&internal1_m1368_tx};
_S_ovbsb  S_ovbsb_1383_1 = {&var1205,&var222,&internal1_m1383_tx};
_S_ovbsb  S_ovbsb_924_1 = {&var1663,&var223,&internal1_m924_tx};
_S_ovbsb  S_ovbsb_929_1 = {&var913,&var224,&internal1_m929_tx};
_S_ovbsb  S_ovbsb_919_1 = {&var912,&var225,&internal1_m919_tx};
_S_ovbsb  S_ovbsb_920_1 = {&var911,&var226,&internal1_m920_tx};
_S_or3  S_or3_2507_1 = {&var227,&var230,&var231,&vainSBool};
_S_orn  S_orn_2506_1 = {array_m2506_x_1,&iRM_6_,&var227};
_S_or2  S_or2_2511_1 = {&R0DEB3LDU,&R0DEB4LDU,&var228};
_S_or2  S_or2_2504_1 = {&R0DEB1LDU,&R0DEB2LDU,&var229};
_S_and2  S_and2_2495_1 = {&R0DE31LDU,&R0DE32LDU,&var230};
_S_diagndev  S_diagndev_2488_1 = {array_m2488_x_1,&iRM_14_,&var231,&var232,&vainSFloat,&internal1_m2488_sttlf};
_S_or2  S_or2_1883_1 = {&var467,&var281,&var233};
_S_and2  S_and2_1873_1 = {&var523,&var1415,&var234};
_S_rs  S_rs_1882_1 = {&var233,&var234,&var235,&vainSBool,&internal1_m1882_q0};
_S_or2  S_or2_1877_1 = {&var523,&var470,&var236};
_S_or2  S_or2_1820_1 = {&var1465,&var523,&var237};
_S_or2  S_or2_1848_1 = {&var522,&var281,&var238};
_S_or2  S_or2_1850_1 = {&var351,&var281,&var239};
_S_or2  S_or2_2327_1 = {&var467,&var277,&var240};
_S_or2  S_or2_2325_1 = {&var277,&var474,&var241};
_S_or2  S_or2_2323_1 = {&var290,&var277,&var242};
_S_and2  S_and2_2306_1 = {&var1412,&var521,&var243};
_S_or2  S_or2_2321_1 = {&var521,&var277,&var244};
_S_noto  S_noto_2329_1 = {&B3IS11LDU,&var245};
_S_or2  S_or2_2356_1 = {&var281,&var474,&var246};
_S_and2  S_and2_2336_1 = {&var1412,&var522,&var247};
_S_noto  S_noto_2360_1 = {&A3IS11LDU,&var248};
_S_or2  S_or2_2358_1 = {&var467,&var281,&var249};
_S_or2  S_or2_2354_1 = {&var281,&var291,&var250};
_S_or2  S_or2_2352_1 = {&var281,&var522,&var251};
_S_or2  S_or2_1828_1 = {&var467,&var281,&var252};
_S_or2  S_or2_1832_1 = {&var467,&var277,&var253};
_S_or2  S_or2_1823_1 = {&var523,&var1465,&var254};
_S_or2  S_or2_1858_1 = {&var277,&var350,&var255};
_S_or2  S_or2_1856_1 = {&var521,&var277,&var256};
_S_or2  S_or2_1899_1 = {&var474,&var277,&var257};
_S_or2  S_or2_1896_1 = {&var474,&var281,&var258};
_S_or2  S_or2_1928_1 = {&var480,&var277,&var259};
_S_or2  S_or2_1925_1 = {&var480,&var281,&var260};
_S_or2  S_or2_1885_1 = {&var467,&var277,&var261};
_S_or2  S_or2_1852_1 = {&var467,&var281,&var262};
_S_or2  S_or2_1860_1 = {&var467,&var277,&var263};
_S_or3  S_or3_2317_1 = {&var474,&var521,&var277,&var264};
_S_or3  S_or3_2319_1 = {&var524,&var521,&var277,&var265};
_S_or3  S_or3_2350_1 = {&var281,&var525,&var522,&var266};
_S_or3  S_or3_2348_1 = {&var474,&var281,&var522,&var267};
_S_or3  S_or3_2315_1 = {&var521,&var467,&var277,&var268};
_S_or3  S_or3_2346_1 = {&var467,&var522,&var281,&var269};
_S_or3  S_or3_1826_1 = {&var467,&var522,&var281,&var270};
_S_or3  S_or3_1830_1 = {&var521,&var467,&var277,&var271};
_S_or3  S_or3_1846_1 = {&var467,&var522,&var281,&var272};
_S_or3  S_or3_1854_1 = {&var467,&var521,&var277,&var273};
_S_or3  S_or3_1881_1 = {&var467,&var523,&var277,&var274};
_S_or3  S_or3_1879_1 = {&var467,&var281,&var523,&var275};
_S_or3  S_or3_1927_1 = {&var277,&var521,&var480,&var276};
_S_noto  S_noto_1922_1 = {&var1122,&var277};
_S_or3  S_or3_1898_1 = {&var277,&var474,&var521,&var278};
_S_or3  S_or3_1895_1 = {&var474,&var281,&var522,&var279};
_S_or3  S_or3_1924_1 = {&var480,&var281,&var522,&var280};
_S_noto  S_noto_1921_1 = {&var1121,&var281};
_S_regch  S_regch_132_1 = {&R0MW12IP1,&var1111,&var282};
_S_or2  S_or2_135_1 = {&var284,&var282,&var283};
_S_or2  S_or2_134_1 = {&R0VZ71LZ1,&R0VZ71LZ2,&var284};
_S_and3  S_and3_1568_1 = {&R0MD11LP2,&var1170,&var288,&var285};
_S_and2  S_and2_812_1 = {&R4MD21LP2,&var288,&var286};
_S_and2  S_and2_809_1 = {&R4MD11LP2,&var288,&var287};
_S_noto  S_noto_114_1 = {&var1842,&var288};
_S_and2  S_and2_112_1 = {&R0MD11LP1,&var288,&var289};
_S_noto  S_noto_2330_1 = {&B3IS22LDU,&var290};
_S_noto  S_noto_2361_1 = {&A3IS22LDU,&var291};
_S_and2  S_and2_2248_1 = {&var688,&var1394,&var292};
_S_or3  S_or3_2241_1 = {&var687,&var394,&var332,&var293};
_S_and2  S_and2_2230_1 = {&var684,&var1394,&var294};
_S_or3  S_or3_2226_1 = {&var394,&var685,&var315,&var295};
_S_or2  S_or2_1644_1 = {&var1483,&var1412,&var296};
_S_or2  S_or2_1613_1 = {&var1342,&var1412,&var297};
_S_rs  S_rs_2320_1 = {&var244,&var301,&var298,&vainSBool,&internal1_m2320_q0};
_S_rs  S_rs_2304_1 = {&var245,&var320,&var299,&vainSBool,&internal1_m2304_q0};
_S_noto  S_noto_2328_1 = {&var1934,&var300};
_S_and2  S_and2_2311_1 = {&var300,&var299,&var301};
_S_rs  S_rs_2351_1 = {&var251,&var304,&var302,&vainSBool,&internal1_m2351_q0};
_S_noto  S_noto_2359_1 = {&var1937,&var303};
_S_and2  S_and2_2342_1 = {&var305,&var303,&var304};
_S_rs  S_rs_2335_1 = {&var248,&var338,&var305,&vainSBool,&internal1_m2335_q0};
_S_and4  S_and4_1514_1 = {&var1170,&var1412,&var485,&var1457,&var306};
_S_and4  S_and4_1063_1 = {&var1170,&var1412,&var485,&var1457,&var307};
_S_rs  S_rs_2326_1 = {&var240,&var313,&var308,&vainSBool,&internal1_m2326_q0};
_S_or4  S_or4_1444_1 = {&var806,&var507,&var1209,&var315,&var309};
_S_or4  S_or4_1453_1 = {&var383,&var510,&var982,&var321,&var310};
_S_orn  S_orn_893_1 = {array_m893_x_1,&iRM_6_,&var311};
_S_or3  S_or3_905_1 = {&var1001,&var1408,&var324,&var312};
_S_and2  S_and2_2313_1 = {&var474,&var314,&var313};
_S_rs  S_rs_2307_1 = {&var240,&var316,&var314,&vainSBool,&internal1_m2307_q0};
_S_rs  S_rs_2324_1 = {&var241,&var316,&var315,&vainSBool,&internal1_m2324_q0};
_S_and2  S_and2_2312_1 = {&var317,&var290,&var316};
_S_rs  S_rs_2305_1 = {&var241,&var243,&var317,&vainSBool,&internal1_m2305_q0};
_S_rs  S_rs_2303_1 = {&var300,&var322,&var318,&vainSBool,&internal1_m2303_q0};
_S_rs  S_rs_2302_1 = {&var264,&var323,&var319,&vainSBool,&internal1_m2302_q0};
_S_and2  S_and2_2310_1 = {&var474,&var318,&var320};
_S_rs  S_rs_2316_1 = {&var264,&var322,&var321,&vainSBool,&internal1_m2316_q0};
_S_and2  S_and2_2309_1 = {&var319,&var467,&var322};
_S_and2  S_and2_2308_1 = {&var524,&var1412,&var323};
_S_rs  S_rs_2314_1 = {&var268,&var323,&var324,&vainSBool,&internal1_m2314_q0};
_S_rs  S_rs_2322_1 = {&var242,&var243,&var325,&vainSBool,&internal1_m2322_q0};
_S_rs  S_rs_2318_1 = {&var265,&var320,&var326,&vainSBool,&internal1_m2318_q0};
_S_orn  S_orn_1332_1 = {array_m1332_x_1,&iRM_6_,&var327};
_S_rs  S_rs_2357_1 = {&var249,&var329,&var328,&vainSBool,&internal1_m2357_q0};
_S_and2  S_and2_2344_1 = {&var474,&var330,&var329};
_S_rs  S_rs_2338_1 = {&var249,&var333,&var330,&vainSBool,&internal1_m2338_q0};
_S_or4  S_or4_988_1 = {&var805,&var511,&var1209,&var332,&var331};
_S_rs  S_rs_2355_1 = {&var246,&var333,&var332,&vainSBool,&internal1_m2355_q0};
_S_and2  S_and2_2343_1 = {&var334,&var291,&var333};
_S_rs  S_rs_2337_1 = {&var246,&var247,&var334,&vainSBool,&internal1_m2337_q0};
_S_rs  S_rs_2334_1 = {&var303,&var341,&var335,&vainSBool,&internal1_m2334_q0};
_S_or4  S_or4_997_1 = {&var1405,&var383,&var992,&var339,&var336};
_S_rs  S_rs_2333_1 = {&var267,&var342,&var337,&vainSBool,&internal1_m2333_q0};
_S_and2  S_and2_2341_1 = {&var474,&var335,&var338};
_S_rs  S_rs_2347_1 = {&var267,&var341,&var339,&vainSBool,&internal1_m2347_q0};
_S_or3  S_or3_1344_1 = {&var1000,&var1410,&var343,&var340};
_S_and2  S_and2_2340_1 = {&var337,&var467,&var341};
_S_and2  S_and2_2339_1 = {&var525,&var1412,&var342};
_S_rs  S_rs_2345_1 = {&var269,&var342,&var343,&vainSBool,&internal1_m2345_q0};
_S_or2  S_or2_2208_1 = {&var385,&var1241,&var344};
_S_ovbs  S_ovbs_2210_1 = {&var443,&fRM_2_0,&var345,&internal1_m2210_tx};
_S_or2  S_or2_2211_1 = {&var1421,&var345,&var346};
_S_ovbs  S_ovbs_2189_1 = {&var444,&fRM_2_0,&var347,&internal1_m2189_tx};
_S_or2  S_or2_2187_1 = {&var386,&var1242,&var348};
_S_or2  S_or2_2190_1 = {&var1441,&var347,&var349};
_S_noto  S_noto_1862_1 = {&B2IS21LDU,&var350};
_S_noto  S_noto_1861_1 = {&A2IS21LDU,&var351};
_S_and2  S_and2_2268_1 = {&var1934,&var689,&var352};
_S_or5  S_or5_2271_1 = {&var863,&var1851,&var369,&var325,&var352,&var353};
_S_or5  S_or5_2270_1 = {&var624,&var1403,&var691,&var1851,&var355,&var354};
_S_and2  S_and2_2243_1 = {&var1937,&var690,&var355};
_S_nocnm  S_nocnm_1905_1 = {&R5IS21LDU,&R5IS11LDU,&var356,&var357,&var358,&internal1_m1905_Pv0,&internal1_m1905_Zv0,&internal1_m1905_MyFirstEnterFlag,&bFirstEnterFlag};
_S_nocnm  S_nocnm_1903_1 = {&R3IS11LDU,&R3IS21LDU,&var359,&var360,&var361,&internal1_m1903_Pv0,&internal1_m1903_Zv0,&internal1_m1903_MyFirstEnterFlag,&bFirstEnterFlag};
_S_or5  S_or5_2157_1 = {&var1205,&var913,&C2MD31LP1,&var1204,&var1203,&var362};
_S_or4  S_or4_2132_1 = {&C1MD31LP2,&C1MD31LP1,&var940,&var960,&var363};
_S_and3  S_and3_449_1 = {&B8IS22LDU,&B8IS21LDU,&var1824,&var364};
_S_and2  S_and2_2228_1 = {&var683,&var394,&var365};
_S_and2  S_and2_2234_1 = {&var686,&var394,&var366};
_S_or4  S_or4_1104_1 = {&var1530,&var875,&var874,&var877,&var367};
_S_or4  S_or4_1556_1 = {&var1498,&var857,&var856,&var860,&var368};
_S_and2  S_and2_2272_1 = {&var614,&var1394,&var369};
_S_and2  S_and2_2257_1 = {&var689,&var1851,&var370};
_S_and2  S_and2_2244_1 = {&var690,&var1851,&var371};
_S_or2  S_or2_613_1 = {&B1VP41LZ2,&B1VP41LZ1,&var372};
_S_or2  S_or2_247_1 = {&A1VP41LZ2,&A1VP41LZ1,&var373};
_S_or2  S_or2_1250_1 = {&B8IS22LDU,&B8IS21LDU,&var374};
_S_or2  S_or2_1243_1 = {&B8IS11LDU,&B8IS12LDU,&var375};
_S_or2  S_or2_375_1 = {&R4IS11LDU,&R4IS12LDU,&var376};
_S_or2  S_or2_388_1 = {&R4IS21LDU,&R4IS22LDU,&var377};
_S_or2  S_or2_1194_1 = {&var1212,&R0MD34LP1,&var378};
_S_or2  S_or2_1197_1 = {&var1210,&R0MD34LP1,&var379};
_S_or2  S_or2_1200_1 = {&var1208,&R0MD34LP1,&var380};
_S_or2  S_or2_1203_1 = {&var1206,&R0MD34LP1,&var381};
_S_noto  S_noto_2386_1 = {&var1851,&var382};
_S_zzfs  S_zzfs_2374_1 = {&var400,&fRM_0_5,&var383,&internal1_m2374_tx,&internal1_m2374_y0};
_S_or2  S_or2_2409_1 = {&var575,&var1214,&var384};
_S_andn  S_andn_661_1 = {array_m661_x_1,&iRM_6_,&var385};
_S_andn  S_andn_660_1 = {array_m660_x_1,&iRM_6_,&var386};
_S_or2  S_or2_2425_1 = {&var890,&var855,&var387};
_S_noto  S_noto_2371_1 = {&var1240,&var388};
_S_noto  S_noto_2370_1 = {&var1237,&var389};
_S_zpfs  S_zpfs_2379_1 = {&var388,&fRM_30_0,&var390,&internal1_m2379_tx,&internal1_m2379_y0};
_S_noto  S_noto_2384_1 = {&var390,&var391};
_S_zpfs  S_zpfs_2378_1 = {&var389,&fRM_30_0,&var392,&internal1_m2378_tx,&internal1_m2378_y0};
_S_noto  S_noto_2383_1 = {&var392,&var393};
_S_and3  S_and3_2376_1 = {&var432,&var413,&lRM_1_,&var394};
_S_and2  S_and2_1017_1 = {&var1556,&var396,&var395};
_S_noto  S_noto_1005_1 = {&var383,&var396};
_S_and2  S_and2_1470_1 = {&var1524,&var398,&var397};
_S_noto  S_noto_1467_1 = {&var383,&var398};
_S_or2  S_or2_2419_1 = {&var409,&var410,&var399};
_S_and2  S_and2_2373_1 = {&var401,&var394,&var400};
_S_abs_subf  S_abs_subf_2366_1 = {&var1950,&var433,&fEM_A3UC08RDU,&vainSFloat,&var401};
_S_and2  S_and2_2421_1 = {&var394,&var409,&var402};
_S_or4  S_or4_2158_1 = {&var362,&var1018,&var1128,&var402,&var403};
_S_noto  S_noto_2424_1 = {&var387,&var404};
_S_or2  S_or2_2399_1 = {&var426,&var437,&var405};
_S_inf  S_inf_2396_1 = {&var435,array_m2396_a_1,array_m2396_b_1,&iRM_6_,&var406,&vainSInt};
_S_or3  S_or3_2423_1 = {&var422,&var429,&var430,&var407};
_S_noto  S_noto_2422_1 = {&var407,&var408};
_S_noto  S_noto_2420_1 = {&var432,&var409};
_S_ovbs  S_ovbs_2415_1 = {&var412,&fRM_15_0,&var410,&internal1_m2415_tx};
_S_zpfs  S_zpfs_2413_1 = {&var413,&fRM_10_0,&var411,&internal1_m2413_tx,&internal1_m2413_y0};
_S_and2  S_and2_2414_1 = {&var411,&R0MW17LP1,&var412};
_S_rs  S_rs_2418_1 = {&var399,&R0MW17LP1,&var413,&vainSBool,&internal1_m2418_q0};
_S_rs  S_rs_2385_1 = {&var426,&var394,&var414,&vainSBool,&internal1_m2385_q0};
_S_and3  S_and3_2392_1 = {&var428,&var382,&var414,&var415};
_S_ml  S_ml_1447_1 = {&var433,&var535,&var383,&var416};
_S_ml  S_ml_991_1 = {&var433,&var539,&var383,&var417};
_S_and2  S_and2_2445_1 = {&var394,&var552,&var418};
_S_noto  S_noto_2407_1 = {&var384,&var419};
_S_noto  S_noto_2390_1 = {&var1495,&var420};
_S_sr  S_sr_2408_1 = {array_m2408_x_1,&iRM_4_,&var421};
_S_and2  S_and2_2443_1 = {&var423,&var394,&var422};
_S_abs_subf  S_abs_subf_2438_1 = {&B3MC01RP1,&A3MC01RP1,&fRM_0_01,&vainSFloat,&var423};
_S_fsumo  S_fsumo_86_1 = {&var1190,&fEM_R0UN11RDU,&var424};
_S_or3  S_or3_133_1 = {&var363,&var283,&var405,&var425};
_S_ovbs  S_ovbs_2393_1 = {&var415,&fRM_1_0,&var426,&internal1_m2393_tx};
_S_noto  S_noto_2402_1 = {&var405,&var427};
_S_rs  S_rs_2391_1 = {&var426,&var1851,&var428,&vainSBool,&internal1_m2391_q0};
_S_and2  S_and2_2441_1 = {&var437,&var394,&var429};
_S_and2  S_and2_2439_1 = {&var431,&var394,&var430};
_S_bol  S_bol_2430_1 = {&fEM_R0UN09RDU,&var14,&var431};
_S_andn  S_andn_2398_1 = {array_m2398_x_1,&iRM_14_,&var432};
_S_irm  S_irm_2377_1 = {&var1190,&var1188,&B3MC01RP1,&var1950,&var14,&var421,&var394,&var1214,&fEM_R0UN12RDU,&fEM_R0UN13RDU,&fEM_R0UN14RDU,&fEM_R0UT20RDU,&var406,&fEM_R0UN15RDU,&fEM_R0UN25RDU,&fEM_R0UN16RDU,&fEM_R0UN17RDU,&fEM_R0UN18RDU,&fEM_R0UN19RDU,&fEM_R0UN27RDU,&fEM_R0UN26RDU,&fEM_R0UN24RDU,&var433,&var434,&var435,&var436,&var437,&var438,&var439,&var440};
_S_noto  S_noto_2217_1 = {&var563,&var441};
_S_noto  S_noto_2186_1 = {&var564,&var442};
_S_and4  S_and4_2209_1 = {&var586,&var344,&var556,&var441,&var443};
_S_and4  S_and4_2188_1 = {&var587,&var348,&var556,&var442,&var444};
_S_zpfs  S_zpfs_2204_1 = {&var570,&fRM_210_0,&var445,&internal1_m2204_tx,&internal1_m2204_y0};
_S_zpfs  S_zpfs_2196_1 = {&var571,&fRM_210_0,&var446,&internal1_m2196_tx,&internal1_m2196_y0};
_S_and2  S_and2_616_1 = {&var1571,&var618,&var447};
_S_and2  S_and2_251_1 = {&var618,&var1604,&var448};
_S_noto  S_noto_1733_1 = {&var450,&var449};
_S_abs_subf  S_abs_subf_1725_1 = {&var1947,&var535,&fEM_A3UC07RDU,&vainSFloat,&var450};
_S_noto  S_noto_1714_1 = {&var452,&var451};
_S_abs_subf  S_abs_subf_1702_1 = {&var539,&var1950,&fEM_A3UC07RDU,&vainSFloat,&var452};
_S_noto  S_noto_1729_1 = {&var454,&var453};
_S_abs_subf  S_abs_subf_1723_1 = {&var543,&var1960,&fEM_A1UC07RDU,&vainSFloat,&var454};
_S_noto  S_noto_1712_1 = {&var456,&var455};
_S_abs_subf  S_abs_subf_1701_1 = {&var547,&var1938,&fEM_A1UC07RDU,&vainSFloat,&var456};
_S_bol  S_bol_1466_1 = {&var1947,&fEM_A3UC09RDU,&var457};
_S_bol  S_bol_1013_1 = {&var1950,&fEM_A3UC09RDU,&var458};
_S_noto  S_noto_1969_1 = {&var463,&var459};
_S_noto  S_noto_1958_1 = {&var461,&var460};
_S_and3  S_and3_1951_1 = {&var1122,&var462,&var1412,&var461};
_S_bol  S_bol_1943_1 = {&fRM_55_0,&var535,&var462};
_S_and3  S_and3_1970_1 = {&var464,&var1121,&var1412,&var463};
_S_bol  S_bol_1979_1 = {&fRM_55_0,&var539,&var464};
_S_and4  S_and4_45_1 = {&var1842,&var1120,&var1299,&var1394,&var465};
_S_noto  S_noto_1366_1 = {&var1170,&var466};
_S_and2  S_and2_1369_1 = {&var1671,&var1170,&var467};
_S_and2  S_and2_1367_1 = {&var1671,&var466,&var468};
_S_noto  S_noto_1310_1 = {&var1170,&var469};
_S_and2  S_and2_1317_1 = {&var1170,&var1745,&var470};
_S_and2  S_and2_1311_1 = {&var1745,&var469,&var471};
_S_noto  S_noto_1020_1 = {&var1170,&var472};
_S_and2  S_and2_1021_1 = {&var472,&var1527,&var473};
_S_and2  S_and2_1018_1 = {&var1527,&var1170,&var474};
_S_noto  S_noto_513_1 = {&var1170,&var475};
_S_and2  S_and2_514_1 = {&var475,&var1620,&var476};
_S_and2  S_and2_517_1 = {&var1620,&var1170,&var477};
_S_noto  S_noto_194_1 = {&var1170,&var478};
_S_and2  S_and2_195_1 = {&var478,&var1590,&var479};
_S_and2  S_and2_197_1 = {&var1170,&var1590,&var480};
_S_and2  S_and2_128_1 = {&var483,&var608,&var481};
_S_and2  S_and2_129_1 = {&var1170,&var608,&var482};
_S_noto  S_noto_123_1 = {&var1170,&var483};
_S_and2  S_and2_124_1 = {&var483,&var607,&var484};
_S_and2  S_and2_125_1 = {&var1170,&var607,&var485};
_S_and2  S_and2_1818_1 = {&var521,&var1416,&var486};
_S_and2  S_and2_1817_1 = {&var524,&var1416,&var487};
_S_and2  S_and2_1816_1 = {&var522,&var1416,&var488};
_S_and2  S_and2_1815_1 = {&var1416,&var525,&var489};
_S_and2  S_and2_1814_1 = {&var732,&var523,&var490};
_S_and2  S_and2_1813_1 = {&var732,&var526,&var491};
_S_and2  S_and2_1812_1 = {&var733,&var523,&var492};
_S_and2  S_and2_1811_1 = {&var733,&var526,&var493};
_S_and2  S_and2_1844_1 = {&var255,&var1375,&var494};
_S_and2  S_and2_1843_1 = {&var521,&var1417,&var495};
_S_and2  S_and2_1842_1 = {&var1376,&var467,&var496};
_S_and2  S_and2_1841_1 = {&var1417,&var524,&var497};
_S_and2  S_and2_1840_1 = {&var351,&var1377,&var498};
_S_and2  S_and2_1839_1 = {&var1417,&var522,&var499};
_S_and2  S_and2_1838_1 = {&var1378,&var467,&var500};
_S_and2  S_and2_1837_1 = {&var1417,&var525,&var501};
_S_and2  S_and2_1875_1 = {&var467,&var1379,&var502};
_S_and2  S_and2_1874_1 = {&var523,&var1415,&var503};
_S_and2  S_and2_1872_1 = {&var1380,&var470,&var504};
_S_and2  S_and2_1871_1 = {&var1381,&var470,&var505};
_S_and2  S_and2_1870_1 = {&var526,&var1415,&var506};
_S_rs  S_rs_1892_1 = {&var257,&var508,&var507,&vainSBool,&internal1_m1892_q0};
_S_and2  S_and2_1891_1 = {&var1413,&var521,&var508};
_S_and2  S_and2_1890_1 = {&var1413,&var524,&var509};
_S_rs  S_rs_1897_1 = {&var278,&var509,&var510,&vainSBool,&internal1_m1897_q0};
_S_rs  S_rs_1889_1 = {&var258,&var512,&var511,&vainSBool,&internal1_m1889_q0};
_S_and2  S_and2_1888_1 = {&var522,&var1413,&var512};
_S_and2  S_and2_1887_1 = {&var1413,&var525,&var513};
_S_and2  S_and2_1920_1 = {&var523,&var1844,&var514};
_S_rs  S_rs_1931_1 = {&var477,&var514,&var515,&vainSBool,&internal1_m1931_q0};
_S_and2  S_and2_1919_1 = {&var1844,&var526,&var516};
_S_and2  S_and2_1917_1 = {&var521,&var1401,&var517};
_S_and2  S_and2_1916_1 = {&var1401,&var524,&var518};
_S_and2  S_and2_1914_1 = {&var522,&var1401,&var519};
_S_and2  S_and2_1913_1 = {&var1401,&var525,&var520};
_S_and2  S_and2_1933_1 = {&var1122,&var523,&var521};
_S_and2  S_and2_1912_1 = {&var1121,&var523,&var522};
_S_and2  S_and2_1935_1 = {&var482,&var1457,&var523};
_S_and2  S_and2_1932_1 = {&var526,&var1122,&var524};
_S_and2  S_and2_1911_1 = {&var526,&var1121,&var525};
_S_and2  S_and2_1934_1 = {&var485,&var1457,&var526};
_S_zpfs  S_zpfs_829_1 = {&var1086,&fRM_3_,&var527,&internal1_m829_tx,&internal1_m829_y0};
_S_or4  S_or4_1748_1 = {&var723,&var724,&var725,&var727,&var528};
_S_or5  S_or5_1735_1 = {&var731,&var730,&var729,&var728,&var528,&var529};
_S_andn  S_andn_1_1 = {array_m1_x_1,&iRM_47_,&vainSBool};
_S_or2  S_or2_1715_1 = {&var532,&var533,&var530};
_S_ml  S_ml_1704_1 = {&fRM_1500_0,&B8MC01RP2,&var530,&var531};
_S_bol  S_bol_1709_1 = {&B8MC01RP2,&fRM_1500_0001,&var532};
_S_bol  S_bol_1718_1 = {&fRM_389_99,&B8MC01RP2,&var533};
_S_or2  S_or2_1731_1 = {&var536,&var537,&var534};
_S_ml  S_ml_1722_1 = {&fRM_0_0,&B3MC01RP1,&var534,&var535};
_S_bol  S_bol_1724_1 = {&B3MC01RP1,&fRM_160_00001,&var536};
_S_bol  S_bol_1732_1 = {&fRM_0_0001,&B3MC01RP1,&var537};
_S_or2  S_or2_1708_1 = {&var540,&var541,&var538};
_S_ml  S_ml_1700_1 = {&fRM_0_0,&A3MC01RP1,&var538,&var539};
_S_bol  S_bol_1706_1 = {&A3MC01RP1,&fRM_160_0001,&var540};
_S_bol  S_bol_1713_1 = {&fRM_0_0001,&A3MC01RP1,&var541};
_S_or2  S_or2_1728_1 = {&var544,&var545,&var542};
_S_ml  S_ml_1720_1 = {&fRM_100_0,&B1MC01RP1,&var542,&var543};
_S_bol  S_bol_1726_1 = {&B1MC01RP1,&fRM_100_0001,&var544};
_S_bol  S_bol_1734_1 = {&fRM_0_0001,&B1MC01RP1,&var545};
_S_or2  S_or2_1711_1 = {&var548,&var549,&var546};
_S_ml  S_ml_1698_1 = {&fRM_100_0,&A1MC01RP1,&var546,&var547};
_S_bol  S_bol_1705_1 = {&A1MC01RP1,&fRM_100_0001,&var548};
_S_bol  S_bol_1716_1 = {&fRM_0_0001,&A1MC01RP1,&var549};
_S_and2  S_and2_109_1 = {&var289,&var376,&var550};
_S_noto  S_noto_110_1 = {&var376,&var551};
_S_and2  S_and2_113_1 = {&var289,&var551,&var552};
_S_and2  S_and2_2174_1 = {&var554,&var555,&var553};
_S_or3  S_or3_2173_1 = {&var1419,&var676,&var403,&var554};
_S_noto  S_noto_2212_1 = {&var346,&var555};
_S_noto  S_noto_2201_1 = {&var557,&var556};
_S_ovbs  S_ovbs_2200_1 = {&var1311,&fRM_2_0,&var557,&internal1_m2200_tx};
_S_noto  S_noto_2191_1 = {&var349,&var558};
_S_and2  S_and2_2160_1 = {&var560,&var558,&var559};
_S_or3  S_or3_2159_1 = {&var403,&var1423,&var676,&var560};
_S_noto  S_noto_2206_1 = {&var568,&var561};
_S_and2  S_and2_2207_1 = {&var1394,&var561,&var562};
_S_and2  S_and2_2215_1 = {&var562,&var344,&var563};
_S_and2  S_and2_2194_1 = {&var565,&var348,&var564};
_S_and2  S_and2_2199_1 = {&var566,&var1394,&var565};
_S_noto  S_noto_2198_1 = {&var1113,&var566};
_S_noto  S_noto_2214_1 = {&var570,&var567};
_S_or2  S_or2_2205_1 = {&var445,&var567,&var568};
_S_noto  S_noto_2193_1 = {&var571,&var569};
_S_rs  S_rs_2203_1 = {&var445,&var576,&var570,&vainSBool,&internal1_m2203_q0};
_S_rs  S_rs_2195_1 = {&var446,&var577,&var571,&vainSBool,&internal1_m2195_q0};
_S_and2  S_and2_2183_1 = {&var574,&var581,&var572};
_S_and2  S_and2_2171_1 = {&var574,&var578,&var573};
_S_noto  S_noto_2165_1 = {&var575,&var574};
_S_ovbs  S_ovbs_2164_1 = {&var403,&fRM_10_0,&var575,&internal1_m2164_tx};
_S_ovbs  S_ovbs_2175_1 = {&var553,&fRM_2_0,&var576,&internal1_m2175_tx};
_S_ovbs  S_ovbs_2161_1 = {&var559,&fRM_2_0,&var577,&internal1_m2161_tx};
_S_or2  S_or2_2170_1 = {&var609,&var1175,&var578};
_S_or2  S_or2_2166_1 = {&var610,&var559,&var579};
_S_or2  S_or2_2178_1 = {&var610,&var553,&var580};
_S_or2  S_or2_2182_1 = {&var609,&var1172,&var581};
_S_rs  S_rs_2167_1 = {&var573,&var579,&var582,&vainSBool,&internal1_m2167_q0};
_S_noto  S_noto_2180_1 = {&var584,&var583};
_S_rs  S_rs_2179_1 = {&var572,&var580,&var584,&vainSBool,&internal1_m2179_q0};
_S_noto  S_noto_2168_1 = {&var582,&var585};
_S_noto  S_noto_2176_1 = {&var576,&var586};
_S_noto  S_noto_2162_1 = {&var577,&var587};
_S_and2  S_and2_2155_1 = {&var590,&var682,&var588};
_S_and2  S_and2_2143_1 = {&var590,&var679,&var589};
_S_noto  S_noto_2137_1 = {&var591,&var590};
_S_ovbs  S_ovbs_2136_1 = {&var363,&fRM_3_0,&var591,&internal1_m2136_tx};
_S_or2  S_or2_1655_1 = {&var1345,&lRM_0_,&var592};
_S_and2  S_and2_481_1 = {&var1816,&var1758,&var593};
_S_and2  S_and2_2032_1 = {&var1370,&B7AS31LDU,&var594};
_S_and2  S_and2_493_1 = {&var1121,&var967,&var595};
_S_and2  S_and2_484_1 = {&var968,&var1121,&var596};
_S_and2  S_and2_527_1 = {&var967,&var1122,&var597};
_S_and2  S_and2_522_1 = {&var968,&var1122,&var598};
_S_or2  S_or2_386_1 = {&var1829,&var1093,&var599};
_S_or2  S_or2_382_1 = {&var1829,&var1092,&var600};
_S_ovbs  S_ovbs_51_1 = {&var1841,&fRM_15_0,&var601,&internal1_m51_tx};
_S_ovbs  S_ovbs_363_1 = {&var1318,&fRM_0_02,&var602,&internal1_m363_tx};
_S_ovbs  S_ovbs_317_1 = {&var1320,&fRM_0_02,&var603,&internal1_m317_tx};
_S_ovbs  S_ovbs_830_1 = {&var527,&fRM_0_2,&var604,&internal1_m830_tx};
_S_ovbs  S_ovbs_1600_1 = {&R0MD31LP1,&fRM_10_0,&var605,&internal1_m1600_tx};
_S_ovbs  S_ovbs_120_1 = {&R0MD31LP1,&fRM_0_15,&var606,&internal1_m120_tx};
_S_ovbs  S_ovbs_122_1 = {&var552,&fRM_0_02,&var607,&internal1_m122_tx};
_S_ovbs  S_ovbs_127_1 = {&R0MD32LP1,&fRM_0_02,&var608,&internal1_m127_tx};
_S_ovbs  S_ovbs_21_1 = {&var1394,&fRM_3_0,&var609,&internal1_m21_tx};
_S_ovbs  S_ovbs_13_1 = {&var1170,&fRM_3_0,&var610,&internal1_m13_tx};
_S_ovbs  S_ovbs_2146_1 = {&var363,&fRM_2_0,&var611,&internal1_m2146_tx};
_S_ovbs  S_ovbs_2133_1 = {&var363,&fRM_2_0,&var612,&internal1_m2133_tx};
_S_ovbs  S_ovbs_2251_1 = {&var1403,&fRM_2_0,&var613,&internal1_m2251_tx};
_S_ovbs  S_ovbs_2253_1 = {&var325,&fRM_2_0,&var614,&internal1_m2253_tx};
_S_ovbs  S_ovbs_82_1 = {&R0MW13LP2,&fRM_10_0,&var615,&internal1_m82_tx};
_S_zpfs  S_zpfs_334_1 = {&var1024,&fRM_10_0,&var616,&internal1_m334_tx,&internal1_m334_y0};
_S_or2  S_or2_1153_1 = {&var1231,&var794,&var617};
_S_or2  S_or2_252_1 = {&A1VN71LZ1,&A1VN71LZ2,&var618};
_S_or2  S_or2_273_1 = {&var919,&var1187,&var619};
_S_or5  S_or5_155_1 = {&B1IS21LDU,&B3IS21LDU,&B2IS21LDU,&var1157,&var1158,&var620};
_S_and2  S_and2_1150_1 = {&var1666,&var1302,&var621};
_S_or3  S_or3_1107_1 = {&var367,&var879,&var878,&var622};
_S_or3  S_or3_1558_1 = {&var862,&var861,&var368,&var623};
_S_and2  S_and2_1081_1 = {&var1431,&var1216,&var624};
_S_and3  S_and3_2054_1 = {&var633,&var13,&var626,&var625};
_S_or2  S_or2_2043_1 = {&var1335,&var1334,&var626};
_S_or3  S_or3_2047_1 = {&var631,&var1334,&var629,&var627};
_S_and2  S_and2_2053_1 = {&var1335,&var13,&var628};
_S_and2  S_and2_2046_1 = {&var1326,&var630,&var629};
_S_zpfs  S_zpfs_2045_1 = {&var1335,&fEM_R0UL04RDU,&var630,&internal1_m2045_tx,&internal1_m2045_y0};
_S_and2  S_and2_2039_1 = {&var1329,&var779,&var631};
_S_or3  S_or3_2040_1 = {&var1283,&var785,&var1261,&var632};
_S_abs_subf  S_abs_subf_2060_1 = {&fEM_R0UL02RDU,&var634,&fEM_R0UL16RDU,&vainSFloat,&var633};
_S_rsfn  S_rsfn_2059_1 = {&var776,&var635,&var634,&internal1_m2059_q0};
_S_lk  S_lk_2057_1 = {&var1486,&var13,&var635};
_S_abs_subf  S_abs_subf_1629_1 = {&fEM_R0UL05RDU,&var637,&fEM_R0UL18RDU,&vainSFloat,&var636};
_S_rsfn  S_rsfn_1620_1 = {&var776,&var638,&var637,&internal1_m1620_q0};
_S_lk  S_lk_1624_1 = {&var1340,&var763,&var638};
_S_abs_subf  S_abs_subf_1671_1 = {&fEM_R0UL07RDU,&var640,&fEM_R0UL20RDU,&vainSFloat,&var639};
_S_rsfn  S_rsfn_1659_1 = {&var776,&var641,&var640,&internal1_m1659_q0};
_S_lk  S_lk_1662_1 = {&var1346,&var753,&var641};
_S_ma  S_ma_1641_1 = {array_m1641_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_abs_subf  S_abs_subf_1676_1 = {&fEM_R0UL25RDU,&var643,&fEM_R0UL19RDU,&vainSFloat,&var642};
_S_rsfn  S_rsfn_1656_1 = {&var776,&var644,&var643,&internal1_m1656_q0};
_S_lk  S_lk_1665_1 = {&var1484,&var744,&var644};
_S_and3  S_and3_2103_1 = {&var646,&var649,&var656,&var645};
_S_abs_subf  S_abs_subf_2100_1 = {&var647,&fEM_R0UL03RDU,&fEM_R0UL17RDU,&vainSFloat,&var646};
_S_rsfn  S_rsfn_2098_1 = {&var776,&var648,&var647,&internal1_m2098_q0};
_S_lk  S_lk_2093_1 = {&var1485,&var649,&var648};
_S_or3  S_or3_2092_1 = {&var654,&var660,&var659,&var649};
_S_and4  S_and4_2097_1 = {&var659,&var1491,&var672,&var670,&var650};
_S_and4  S_and4_2095_1 = {&var660,&var1491,&var672,&var670,&var651};
_S_and2  S_and2_2087_1 = {&var1338,&var649,&var652};
_S_and2  S_and2_2073_1 = {&var779,&var1328,&var653};
_S_and2  S_and2_2077_1 = {&var657,&var1327,&var654};
_S_or3  S_or3_2078_1 = {&var654,&var653,&var1337,&var655};
_S_or2  S_or2_2069_1 = {&var1338,&var1337,&var656};
_S_zpfs  S_zpfs_2076_1 = {&var1338,&fEM_R0UL21RDU,&var657,&internal1_m2076_tx,&internal1_m2076_y0};
_S_or3  S_or3_2066_1 = {&var781,&var1287,&var1265,&var658};
_S_zpfs  S_zpfs_2091_1 = {&var662,&fEM_R0UL03RDU,&var659,&internal1_m2091_tx,&internal1_m2091_y0};
_S_zpfs  S_zpfs_2088_1 = {&var663,&fEM_R0UL03RDU,&var660,&internal1_m2088_tx,&internal1_m2088_y0};
_S_or2  S_or2_2084_1 = {&var663,&var662,&var661};
_S_or2  S_or2_2085_1 = {&var664,&var1338,&var662};
_S_or2  S_or2_2083_1 = {&var665,&var1338,&var663};
_S_and4  S_and4_2081_1 = {&var1392,&var1122,&B2IS12LDU,&var666,&var664};
_S_and4  S_and4_2075_1 = {&var1393,&A2IS12LDU,&var1121,&var666,&var665};
_S_and2  S_and2_2074_1 = {&var1144,&var670,&var666};
_S_and3  S_and3_2112_1 = {&var1122,&var1249,&var669,&var667};
_S_and3  S_and3_2111_1 = {&var1121,&var1250,&var669,&var668};
_S_and4  S_and4_2110_1 = {&var1215,&var1014,&var1016,&var670,&var669};
_S_and2  S_and2_2104_1 = {&var1027,&var1216,&var670};
_S_or2  S_or2_2106_1 = {&var1495,&var1214,&var671};
_S_or3  S_or3_2115_1 = {&var675,&var674,&var677,&var672};
_S_and2  S_and2_2105_1 = {&var1253,&A2IS12LDU,&var673};
_S_and2  S_and2_2109_1 = {&var1154,&var673,&var674};
_S_and3  S_and3_2114_1 = {&var1490,&var678,&var673,&var675};
_S_or2  S_or2_2123_1 = {&lRM_0_,&var671,&var676};
_S_and2  S_and2_2120_1 = {&var1169,&var678,&var677};
_S_and2  S_and2_2122_1 = {&var1252,&B2IS12LDU,&var678};
_S_or2  S_or2_2142_1 = {&var1174,&var609,&var679};
_S_or2  S_or2_2138_1 = {&var610,&var363,&var680};
_S_or2  S_or2_2150_1 = {&var363,&var610,&var681};
_S_or2  S_or2_2154_1 = {&var609,&var1173,&var682};
_S_or2  S_or2_2219_1 = {&var1022,&var1404,&var683};
_S_or2  S_or2_2229_1 = {&var1216,&var1425,&var684};
_S_zpfs  S_zpfs_2231_1 = {&var294,&fRM_15_0,&var685,&internal1_m2231_tx,&internal1_m2231_y0};
_S_or2  S_or2_2235_1 = {&var1021,&var326,&var686};
_S_zpfs  S_zpfs_2242_1 = {&var292,&fRM_15_0,&var687,&internal1_m2242_tx,&internal1_m2242_y0};
_S_or2  S_or2_2247_1 = {&var1216,&var1424,&var688};
_S_or2  S_or2_2263_1 = {&var298,&var650,&var689};
_S_or2  S_or2_2258_1 = {&var651,&var302,&var690};
_S_and2  S_and2_2269_1 = {&var1394,&var613,&var691};
_S_and2  S_and2_2031_1 = {&var1371,&A7AS31LDU,&var692};
_S_or3  S_or3_2004_1 = {&var697,&var701,&var699,&var693};
_S_or3  S_or3_2008_1 = {&var700,&var699,&var696,&var694};
_S_or2  S_or2_2018_1 = {&B0VT71LZ1,&B0VT71LZ2,&var695};
_S_and2  S_and2_2009_1 = {&var702,&var695,&var696};
_S_and2  S_and2_2003_1 = {&var702,&var698,&var697};
_S_or2  S_or2_2002_1 = {&A0VT71LZ1,&A0VT71LZ2,&var698};
_S_zpfs  S_zpfs_1999_1 = {&var1388,&fRM_2_5,&var699,&internal1_m1999_tx,&internal1_m1999_y0};
_S_zpfs  S_zpfs_1998_1 = {&var1389,&fRM_2_5,&var700,&internal1_m1998_tx,&internal1_m1998_y0};
_S_zpfs  S_zpfs_1997_1 = {&var1390,&fRM_2_5,&var701,&internal1_m1997_tx,&internal1_m1997_y0};
_S_zpfs  S_zpfs_1996_1 = {&var1391,&fRM_2_5,&var702,&internal1_m1996_tx,&internal1_m1996_y0};
_S_or2  S_or2_2027_1 = {&R0VP73LZ2,&R0VP73LZ1,&var703};
_S_and2  S_and2_2022_1 = {&var325,&var1372,&var704};
_S_or2  S_or2_2017_1 = {&var707,&var704,&var705};
_S_or2  S_or2_2019_1 = {&var298,&var325,&var706};
_S_and2  S_and2_2016_1 = {&var298,&var1362,&var707};
_S_and2  S_and2_2000_1 = {&var1403,&var1373,&var708};
_S_or2  S_or2_2001_1 = {&var711,&var708,&var709};
_S_or2  S_or2_1994_1 = {&var302,&var1403,&var710};
_S_and2  S_and2_1993_1 = {&var302,&var1363,&var711};
_S_or3  S_or3_1963_1 = {&var1454,&var1412,&var1413,&var712};
_S_or3  S_or3_1964_1 = {&var1452,&var1412,&var1413,&var713};
_S_or2  S_or2_1955_1 = {&var1447,&var1412,&var714};
_S_or2  S_or2_1956_1 = {&var1446,&var1412,&var715};
_S_or2  S_or2_1962_1 = {&var1456,&var1415,&var716};
_S_or4  S_or4_1960_1 = {&var1415,&var1453,&var1416,&var1417,&var717};
_S_or4  S_or4_1959_1 = {&var1415,&var1459,&var1416,&var1417,&var718};
_S_or2  S_or2_1953_1 = {&var1448,&var1417,&var719};
_S_or2  S_or2_1952_1 = {&var1449,&var1417,&var720};
_S_or2  S_or2_1961_1 = {&var1415,&var1455,&var721};
_S_or2  S_or2_1930_1 = {&var477,&var523,&var722};
_S_and2  S_and2_1753_1 = {&var1709,&var1667,&var723};
_S_and2  S_and2_1752_1 = {&var1832,&var1667,&var724};
_S_and2  S_and2_1751_1 = {&var1111,&var1667,&var725};
_S_or2  S_or2_1750_1 = {&B4IS11LDU,&A4IS11LDU,&var726};
_S_and2  S_and2_1749_1 = {&var726,&var1667,&var727};
_S_and2  S_and2_1739_1 = {&var1887,&var1667,&var728};
_S_and2  S_and2_1738_1 = {&var376,&var1667,&var729};
_S_and2  S_and2_1737_1 = {&var1100,&var1667,&var730};
_S_and2  S_and2_1736_1 = {&R3IS21LDU,&var1667,&var731};
_S_or2  S_or2_1810_1 = {&var1845,&var1846,&var732};
_S_or2  S_or2_1809_1 = {&var1847,&var1845,&var733};
_S_or2  S_or2_2286_1 = {&var1193,&R0MD34LP1,&var734};
_S_or3  S_or3_2292_1 = {&var1466,&var1468,&var1467,&var735};
_S_or3  S_or3_2283_1 = {&var1472,&var1474,&var1473,&var736};
_S_or2  S_or2_1794_1 = {&var1945,&var1667,&var737};
_S_or2  S_or2_1766_1 = {&var1710,&var1302,&var738};
_S_or5  S_or5_1256_1 = {&var1725,&var740,&var1736,&var1722,&var1723,&var739};
_S_or3  S_or3_1260_1 = {&var1730,&var1731,&var1196,&var740};
_S_or5  S_or5_1781_1 = {&var529,&var742,&var1719,&var1711,&var1712,&var741};
_S_or3  S_or3_1784_1 = {&var1195,&var1714,&var1713,&var742};
_S_and3  S_and3_1683_1 = {&var744,&var749,&var642,&var743};
_S_and2  S_and2_1688_1 = {&var745,&var1483,&var744};
_S_or3  S_or3_1687_1 = {&A3VZ13LZ2,&A3VZ13LZ1,&var748,&var745};
_S_zpfs  S_zpfs_1672_1 = {&var1483,&fRM_0_2,&var746,&internal1_m1672_tx,&internal1_m1672_y0};
_S_or3  S_or3_1674_1 = {&var1348,&var748,&var750,&var747};
_S_and2  S_and2_1673_1 = {&var1325,&var746,&var748};
_S_or2  S_or2_1663_1 = {&var1483,&var1348,&var749};
_S_and2  S_and2_1651_1 = {&var1330,&var779,&var750};
_S_or3  S_or3_1660_1 = {&var1262,&var1284,&var784,&var751};
_S_or3  S_or3_1685_1 = {&R0AD14LZ1,&R0AD14LZ2,&var755,&var752};
_S_and2  S_and2_1686_1 = {&var752,&var1345,&var753};
_S_zpfs  S_zpfs_1666_1 = {&var1345,&fEM_R0UL06RDU,&var754,&internal1_m1666_tx,&internal1_m1666_y0};
_S_and2  S_and2_1667_1 = {&var754,&var1324,&var755};
_S_or3  S_or3_1668_1 = {&var1343,&var755,&var758,&var756};
_S_or3  S_or3_1643_1 = {&var783,&var1285,&var1263,&var757};
_S_and2  S_and2_1646_1 = {&var1331,&var779,&var758};
_S_and3  S_and3_1682_1 = {&var639,&var753,&var766,&var759};
_S_zpfs  S_zpfs_1616_1 = {&var1342,&fEM_R0UL04RDU,&var760,&internal1_m1616_tx,&internal1_m1616_y0};
_S_and2  S_and2_1617_1 = {&var760,&var1323,&var761};
_S_and3  S_and3_1633_1 = {&var636,&var763,&var767,&var762};
_S_and2  S_and2_1627_1 = {&var764,&var1342,&var763};
_S_or3  S_or3_1626_1 = {&A3VZ15LZ1,&A3VZ15LZ2,&var761,&var764};
_S_or3  S_or3_1618_1 = {&var768,&var761,&var1341,&var765};
_S_or2  S_or2_1657_1 = {&var1345,&var1343,&var766};
_S_or2  S_or2_1614_1 = {&var1342,&var1341,&var767};
_S_and2  S_and2_1606_1 = {&var1332,&var779,&var768};
_S_or3  S_or3_1604_1 = {&var1264,&var1286,&var782,&var769};
_S_or2  S_or2_1567_1 = {&var1838,&var771,&var770};
_S_and2  S_and2_1566_1 = {&var772,&var1386,&var771};
_S_or2  S_or2_1565_1 = {&var1167,&var1119,&var772};
_S_or2  S_or2_1562_1 = {&var1257,&var1279,&var773};
_S_and2  S_and2_1560_1 = {&var1351,&var1352,&var774};
_S_and2  S_and2_1563_1 = {&var773,&var772,&var775};
_S_or5  S_or5_1564_1 = {&var603,&var602,&var774,&var775,&R0MD34LP1,&var776};
_S_orni  S_orni_1593_1 = {array_m1593_x_1,&iRM_5_,&var777,&var778};
_S_or5  S_or5_1595_1 = {&var1347,&var1322,&var776,&var1267,&var605,&var779};
_S_and2  S_and2_1594_1 = {&var777,&var1478,&var780};
_S_or2  S_or2_1603_1 = {&var10,&var12,&var781};
_S_or2  S_or2_1597_1 = {&var8,&var786,&var782};
_S_or2  S_or2_1589_1 = {&var7,&var787,&var783};
_S_or2  S_or2_1585_1 = {&var9,&var788,&var784};
_S_or2  S_or2_1581_1 = {&var11,&var789,&var785};
_S_and2  S_and2_1596_1 = {&var1293,&var1288,&var786};
_S_and2  S_and2_1588_1 = {&var1292,&var1288,&var787};
_S_and2  S_and2_1584_1 = {&var1288,&var1291,&var788};
_S_and2  S_and2_1580_1 = {&var1290,&var1288,&var789};
_S_and2  S_and2_1571_1 = {&var1838,&var285,&var790};
_S_and3  S_and3_1183_1 = {&var471,&var795,&var813,&var791};
_S_or2  S_or2_1149_1 = {&var1304,&var1300,&var792};
_S_or2  S_or2_1174_1 = {&var1300,&var1234,&var793};
_S_and2  S_and2_1141_1 = {&var1676,&var1301,&var794};
_S_and2  S_and2_1136_1 = {&var1495,&var815,&var795};
_S_or3  S_or3_1146_1 = {&var1300,&var1230,&var1303,&var796};
_S_and2  S_and2_1143_1 = {&var468,&var1495,&var797};
_S_and2  S_and2_1166_1 = {&var479,&var1495,&var798};
_S_and2  S_and2_1182_1 = {&var473,&var1495,&var799};
_S_and2  S_and2_1189_1 = {&var476,&var1495,&var800};
_S_and3  S_and3_1131_1 = {&var803,&var1219,&var1495,&var801};
_S_and3  S_and3_1125_1 = {&var804,&var1219,&var1495,&var802};
_S_and2  S_and2_1133_1 = {&var1121,&var1494,&var803};
_S_and2  S_and2_1123_1 = {&var1122,&var1494,&var804};
_S_and4  S_and4_1132_1 = {&var803,&var1495,&var1227,&var1217,&var805};
_S_and4  S_and4_1126_1 = {&var804,&var1495,&var1227,&var1217,&var806};
_S_and4  S_and4_1130_1 = {&var1495,&var803,&var811,&var1218,&var807};
_S_and4  S_and4_1124_1 = {&var1495,&var804,&var811,&var1218,&var808};
_S_and2  S_and2_1117_1 = {&var1228,&var1495,&var809};
_S_or4  S_or4_1120_1 = {&R0MD31LP1,&var1729,&var484,&var822,&var810};
_S_and3  S_and3_1167_1 = {&var1229,&var1228,&var1227,&var811};
_S_and2  S_and2_1154_1 = {&var813,&var617,&var812};
_S_and2  S_and2_1157_1 = {&var1226,&var811,&var813};
_S_or2  S_or2_1168_1 = {&var1296,&var1238,&var814};
_S_and2  S_and2_1176_1 = {&var816,&var814,&var815};
_S_or2  S_or2_1169_1 = {&var1237,&var1239,&var816};
_S_or2  S_or2_1170_1 = {&var1236,&var1237,&var817};
_S_or2  S_or2_1172_1 = {&var1235,&var1240,&var818};
_S_and2  S_and2_1173_1 = {&var817,&var818,&var819};
_S_or2  S_or2_1160_1 = {&var1296,&var1295,&var820};
_S_and2  S_and2_1161_1 = {&var820,&var1232,&var821};
_S_and5  S_and5_1113_1 = {&var823,&var1316,&var1237,&var1296,&var812,&var822};
_S_and2  S_and2_1114_1 = {&var1271,&var1272,&var823};
_S_and2  S_and2_1382_1 = {&var1365,&var825,&var824};
_S_or2  S_or2_1377_1 = {&A2MD12LP1,&var826,&var825};
_S_and2  S_and2_1365_1 = {&A2MD11LP1,&var1382,&var826};
_S_or2  S_or2_1358_1 = {&var829,&B2MD12LP1,&var827};
_S_and2  S_and2_1362_1 = {&var827,&var1365,&var828};
_S_and2  S_and2_1352_1 = {&B2MD11LP1,&var1383,&var829};
_S_or3  S_or3_1341_1 = {&var1445,&var1440,&var985,&var830};
_S_or5  S_or5_1356_1 = {&var833,&var1205,&var1706,&var1701,&var1700,&var831};
_S_or2  S_or2_1376_1 = {&var1957,&var1691,&var832};
_S_or3  S_or3_1443_1 = {&var1672,&var834,&var835,&var833};
_S_and2  S_and2_1434_1 = {&var1691,&var1168,&var834};
_S_and2  S_and2_1433_1 = {&var1118,&var1691,&var835};
_S_and3  S_and3_1432_1 = {&var620,&var1154,&var850,&var836};
_S_and2  S_and2_1431_1 = {&var376,&var850,&var837};
_S_and3  S_and3_1425_1 = {&var1143,&var1189,&var850,&var838};
_S_and2  S_and2_1424_1 = {&var703,&var850,&var839};
_S_and2  S_and2_1409_1 = {&var1682,&var850,&var840};
_S_and2  S_and2_1393_1 = {&var1887,&var850,&var841};
_S_and2  S_and2_1411_1 = {&var283,&var850,&var842};
_S_and2  S_and2_1394_1 = {&R3IS21LDU,&var850,&var843};
_S_and2  S_and2_1412_1 = {&var846,&var850,&var844};
_S_and3  S_and3_1395_1 = {&var847,&var1681,&var850,&var845};
_S_or2  S_or2_1413_1 = {&var1674,&var1675,&var846};
_S_or2  S_or2_1396_1 = {&A4IS11LDU,&B4IS11LDU,&var847};
_S_and3  S_and3_1403_1 = {&var1415,&var485,&var1170,&var848};
_S_and3  S_and3_1402_1 = {&var1417,&var485,&var1170,&var849};
_S_or3  S_or3_1398_1 = {&var1692,&var849,&var848,&var850};
_S_and2  S_and2_1490_1 = {&var852,&var1365,&var851};
_S_or2  S_or2_1489_1 = {&var853,&B3MD12LP1,&var852};
_S_and2  S_and2_1476_1 = {&B3MD11LP1,&var1361,&var853};
_S_or2  S_or2_1481_1 = {&var1948,&var1509,&var854};
_S_or5  S_or5_1469_1 = {&var623,&var1518,&var1519,&var397,&var1203,&var855};
_S_and2  S_and2_1541_1 = {&var1509,&var1168,&var856};
_S_and2  S_and2_1540_1 = {&var1509,&var1118,&var857};
_S_and2  S_and2_1554_1 = {&var1184,&var1497,&var858};
_S_or2  S_or2_1547_1 = {&var858,&var1185,&var859};
_S_and3  S_and3_1539_1 = {&var1374,&var859,&var868,&var860};
_S_and3  S_and3_1538_1 = {&var620,&var1169,&var868,&var861};
_S_and2  S_and2_1537_1 = {&var376,&var868,&var862};
_S_and2  S_and2_1532_1 = {&var1429,&var1216,&var863};
_S_or2  S_or2_1519_1 = {&var1500,&var1499,&var864};
_S_and2  S_and2_1518_1 = {&var864,&var868,&var865};
_S_and2  S_and2_1517_1 = {&var283,&var868,&var866};
_S_and2  S_and2_1515_1 = {&var1502,&var868,&var867};
_S_or2  S_or2_1504_1 = {&var1511,&var306,&var868};
_S_or2  S_or2_1505_1 = {&B4IS11LDU,&A4IS11LDU,&var869};
_S_and3  S_and3_1502_1 = {&var1501,&var869,&var868,&var870};
_S_and2  S_and2_1501_1 = {&R3IS21LDU,&var868,&var871};
_S_and2  S_and2_1500_1 = {&var1887,&var868,&var872};
_S_and2  S_and2_1100_1 = {&var1182,&var1529,&var873};
_S_and2  S_and2_1089_1 = {&var1118,&var1541,&var874};
_S_and2  S_and2_1090_1 = {&var1168,&var1541,&var875};
_S_or2  S_or2_1096_1 = {&var1183,&var873,&var876};
_S_and3  S_and3_1088_1 = {&var1374,&var876,&var883,&var877};
_S_and3  S_and3_1087_1 = {&var1154,&var620,&var883,&var878};
_S_and2  S_and2_1086_1 = {&var376,&var883,&var879};
_S_and2  S_and2_1064_1 = {&var1534,&var883,&var880};
_S_or2  S_or2_1068_1 = {&var1532,&var1531,&var881};
_S_and2  S_and2_1067_1 = {&var881,&var883,&var882};
_S_or2  S_or2_1052_1 = {&var1543,&var307,&var883};
_S_or2  S_or2_1053_1 = {&B4IS11LDU,&A4IS11LDU,&var884};
_S_and3  S_and3_1051_1 = {&var884,&var1533,&var883,&var885};
_S_and2  S_and2_1066_1 = {&var283,&var883,&var886};
_S_and2  S_and2_1050_1 = {&R3IS21LDU,&var883,&var887};
_S_and2  S_and2_1049_1 = {&var1887,&var883,&var888};
_S_or2  S_or2_1029_1 = {&var1541,&var1951,&var889};
_S_or5  S_or5_1016_1 = {&var622,&var1204,&var395,&var1550,&var1551,&var890};
_S_and2  S_and2_1042_1 = {&var1365,&var892,&var891};
_S_or2  S_or2_1037_1 = {&var893,&A3MD12LP1,&var892};
_S_and2  S_and2_1026_1 = {&A3MD11LP1,&var1414,&var893};
_S_or3  S_or3_987_1 = {&var1639,&var896,&var895,&var894};
_S_and2  S_and2_977_1 = {&var1650,&var1118,&var895};
_S_and2  S_and2_978_1 = {&var1650,&var1168,&var896};
_S_and3  S_and3_976_1 = {&var1673,&var1169,&var908,&var897};
_S_and2  S_and2_975_1 = {&var376,&var908,&var898};
_S_and2  S_and2_953_1 = {&var1643,&var908,&var899};
_S_and2  S_and2_955_1 = {&var283,&var908,&var900};
_S_and2  S_and2_956_1 = {&var902,&var908,&var901};
_S_or2  S_or2_957_1 = {&var1641,&var1640,&var902};
_S_and2  S_and2_937_1 = {&var1887,&var908,&var903};
_S_and3  S_and3_939_1 = {&var1642,&var909,&var908,&var904};
_S_and2  S_and2_938_1 = {&R3IS21LDU,&var908,&var905};
_S_and3  S_and3_952_1 = {&var1415,&var485,&var1170,&var906};
_S_and3  S_and3_951_1 = {&var485,&var1417,&var1170,&var907};
_S_or3  S_or3_941_1 = {&var1651,&var906,&var907,&var908};
_S_or2  S_or2_942_1 = {&B4IS11LDU,&A4IS11LDU,&var909};
_S_or2  S_or2_921_1 = {&var1954,&var1650,&var910};
_S_zpfs  S_zpfs_917_1 = {&var1664,&fRM_3_0,&var911,&internal1_m917_tx,&internal1_m917_y0};
_S_zpfs  S_zpfs_916_1 = {&var1665,&fRM_2_0,&var912,&internal1_m916_tx,&internal1_m916_y0};
_S_zpfs  S_zpfs_934_1 = {&var1662,&fEM_A2UL83RDU,&var913,&internal1_m934_tx,&internal1_m934_y0};
_S_or5  S_or5_913_1 = {&var894,&var913,&var1663,&var912,&var911,&var914};
_S_or3  S_or3_901_1 = {&var1420,&var1443,&var980,&var915};
_S_or4  S_or4_881_1 = {&var1786,&var1784,&var1785,&var1787,&var916};
_S_or2  S_or2_873_1 = {&var918,&var916,&var917};
_S_or4  S_or4_866_1 = {&var1795,&var1794,&var1793,&var1796,&var918};
_S_and2  S_and2_277_1 = {&var1186,&var1589,&var919};
_S_and3  S_and3_263_1 = {&var1154,&var620,&var1604,&var920};
_S_or3  S_or3_281_1 = {&var922,&var924,&var1592,&var921};
_S_and2  S_and2_267_1 = {&var1603,&var1168,&var922};
_S_and3  S_and3_264_1 = {&var619,&var1374,&var1604,&var923};
_S_and2  S_and2_266_1 = {&var1118,&var1603,&var924};
_S_and2  S_and2_262_1 = {&var376,&var1604,&var925};
_S_and2  S_and2_231_1 = {&var1596,&var1604,&var926};
_S_and2  S_and2_233_1 = {&var283,&var1604,&var927};
_S_or2  S_or2_235_1 = {&var1593,&var1594,&var928};
_S_and2  S_and2_234_1 = {&var928,&var1604,&var929};
_S_or2  S_or2_221_1 = {&B4IS11LDU,&A4IS11LDU,&var930};
_S_and3  S_and3_220_1 = {&var1595,&var930,&var1604,&var931};
_S_and2  S_and2_218_1 = {&var1887,&var1604,&var932};
_S_and2  S_and2_219_1 = {&R3IS21LDU,&var1604,&var933};
_S_and2  S_and2_190_1 = {&var1365,&var936,&var934};
_S_and2  S_and2_183_1 = {&A1MD11LP1,&var1402,&var935};
_S_or2  S_or2_189_1 = {&A1MD12LP1,&var935,&var936};
_S_or2  S_or2_199_1 = {&var1603,&var1939,&var937};
_S_zpfs  S_zpfs_193_1 = {&var1618,&fRM_2_0,&var938,&internal1_m193_tx,&internal1_m193_y0};
_S_zpfs  S_zpfs_192_1 = {&var1617,&fRM_2_0,&var939,&internal1_m192_tx,&internal1_m192_y0};
_S_zpfs  S_zpfs_214_1 = {&var1615,&fEM_A1UL03RDU,&var940,&internal1_m214_tx,&internal1_m214_y0};
_S_or5  S_or5_187_1 = {&var921,&var940,&var939,&var938,&var1616,&var941};
_S_orn  S_orn_611_1 = {array_m611_x_1,&iRM_12_,&var942};
_S_and2  S_and2_640_1 = {&var1559,&var1181,&var943};
_S_or2  S_or2_636_1 = {&var1180,&var943,&var944};
_S_and3  S_and3_626_1 = {&var1169,&var1673,&var1571,&var945};
_S_and2  S_and2_625_1 = {&var376,&var1571,&var946};
_S_and3  S_and3_627_1 = {&var1374,&var1571,&var944,&var947};
_S_or2  S_or2_601_1 = {&var1561,&var1560,&var948};
_S_and2  S_and2_600_1 = {&var948,&var1571,&var949};
_S_and2  S_and2_599_1 = {&var1571,&var283,&var950};
_S_and3  S_and3_586_1 = {&var1562,&var952,&var1571,&var951};
_S_or2  S_or2_587_1 = {&B4IS11LDU,&A4IS11LDU,&var952};
_S_and2  S_and2_597_1 = {&var1571,&var1563,&var953};
_S_or2  S_or2_560_1 = {&B1MD12LP1,&var956,&var954};
_S_and2  S_and2_562_1 = {&var1365,&var954,&var955};
_S_and2  S_and2_553_1 = {&B1MD11LP1,&var1384,&var956};
_S_and2  S_and2_585_1 = {&var1571,&R3IS21LDU,&var957};
_S_and2  S_and2_584_1 = {&var1571,&var1887,&var958};
_S_or2  S_or2_567_1 = {&var1570,&var1961,&var959};
_S_zpfs  S_zpfs_583_1 = {&var1584,&fEM_A1UL03RDU,&var960,&internal1_m583_tx,&internal1_m583_y0};
_S_or5  S_or5_556_1 = {&var1114,&var960,&var1585,&var1579,&var1580,&var961};
_S_or2  S_or2_544_1 = {&var1398,&var981,&var962};
_S_or3  S_or3_534_1 = {&var802,&var1397,&var1211,&var963};
_S_or4  S_or4_521_1 = {&var1624,&var1621,&var1623,&var1622,&var964};
_S_or4  S_or4_502_1 = {&var1632,&var1630,&var1631,&var1633,&var965};
_S_or2  S_or2_509_1 = {&var965,&var964,&var966};
_S_and3  S_and3_491_1 = {&var969,&var1365,&R0MD33LP1,&var967};
_S_and3  S_and3_492_1 = {&var1365,&var970,&R0MD33LP1,&var968};
_S_or3  S_or3_482_1 = {&var515,&var1220,&var1207,&var969};
_S_or2  S_or2_483_1 = {&var1619,&var1396,&var970};
_S_or2  S_or2_832_1 = {&var1754,&var1755,&var971};
_S_and2  S_and2_353_1 = {&var1256,&var1318,&var972};
_S_or2  S_or2_372_1 = {&B4IS21LDU,&A4IS21LDU,&var973};
_S_or2  S_or2_367_1 = {&A2IS21LDU,&B2IS21LDU,&var974};
_S_or2  S_or2_362_1 = {&var977,&var1260,&var975};
_S_and3  S_and3_360_1 = {&var1319,&var1314,&var1315,&var976};
_S_or4  S_or4_358_1 = {&var1245,&var425,&R0MD31LP1,&var1255,&var977};
_S_and4  S_and4_354_1 = {&var1167,&var1035,&var484,&var1125,&var978};
_S_or2  S_or2_349_1 = {&R0MD34LP1,&var1255,&var979};
_S_and3  S_and3_671_1 = {&var1002,&var1496,&B2IS12LDU,&var980};
_S_and2  S_and2_670_1 = {&var1002,&var1528,&var981};
_S_and2  S_and2_669_1 = {&var1002,&var1591,&var982};
_S_or2  S_or2_713_1 = {&A2IS12LDU,&B2IS12LDU,&var983};
_S_or2  S_or2_690_1 = {&var1726,&var1354,&var984};
_S_and3  S_and3_681_1 = {&A2IS12LDU,&var1496,&var1003,&var985};
_S_and2  S_and2_712_1 = {&var987,&var1496,&var986};
_S_or2  S_or2_714_1 = {&var1297,&var468,&var987};
_S_or2  S_or2_695_1 = {&var1726,&var1353,&var988};
_S_or2  S_or2_693_1 = {&var990,&var1726,&var989};
_S_and2  S_and2_705_1 = {&var1528,&var479,&var990};
_S_and2  S_and2_680_1 = {&var1003,&var1528,&var991};
_S_and2  S_and2_679_1 = {&var1003,&var1591,&var992};
_S_and2  S_and2_704_1 = {&var473,&var1591,&var993};
_S_and2  S_and2_720_1 = {&var476,&var1619,&var994};
_S_or2  S_or2_716_1 = {&var1726,&var1355,&var995};
_S_or2  S_or2_711_1 = {&var997,&var994,&var996};
_S_and2  S_and2_703_1 = {&var1005,&var1588,&var997};
_S_and2  S_and2_709_1 = {&var1005,&R0MD33LP1,&var998};
_S_or2  S_or2_659_1 = {&var1178,&var1179,&var999};
_S_and4  S_and4_678_1 = {&var1178,&var1003,&var1688,&A2IS12LDU,&var1000};
_S_and4  S_and4_668_1 = {&var1002,&var1179,&var1688,&B2IS12LDU,&var1001};
_S_and2  S_and2_667_1 = {&var1122,&var1686,&var1002};
_S_and2  S_and2_677_1 = {&var1121,&var1686,&var1003};
_S_or2  S_or2_708_1 = {&var1298,&var468,&var1004};
_S_and2  S_and2_701_1 = {&var1004,&var1688,&var1005};
_S_or2  S_or2_688_1 = {&var1726,&var1356,&var1006};
_S_or2  S_or2_700_1 = {&var1666,&var1311,&var1007};
_S_and2  S_and2_699_1 = {&var1007,&var1710,&var1008};
_S_or2  S_or2_685_1 = {&var1726,&var1357,&var1009};
_S_and2  S_and2_698_1 = {&var1727,&var1676,&var1010};
_S_or2  S_or2_683_1 = {&var1726,&var1358,&var1011};
_S_and2  S_and2_696_1 = {&var471,&var1729,&var1012};
_S_or2  S_or2_675_1 = {&var1366,&var1726,&var1013};
_S_and2  S_and2_327_1 = {&var1426,&var1016,&var1014};
_S_and2  S_and2_315_1 = {&var1016,&var1243,&var1015};
_S_or2  S_or2_310_1 = {&var1257,&var1279,&var1016};
_S_and3  S_and3_306_1 = {&var1492,&var1314,&var1315,&var1017};
_S_and3  S_and3_321_1 = {&var974,&var1244,&var1019,&var1018};
_S_or2  S_or2_311_1 = {&var1492,&var1319,&var1019};
_S_and2  S_and2_320_1 = {&var973,&var1019,&var1020};
_S_and2  S_and2_341_1 = {&var1025,&var1122,&var1021};
_S_and2  S_and2_342_1 = {&var1121,&var1025,&var1022};
_S_and2  S_and2_347_1 = {&var1216,&var1014,&var1023};
_S_and2  S_and2_335_1 = {&var1025,&var1216,&var1024};
_S_and2  S_and2_340_1 = {&var1394,&var1026,&var1025};
_S_or2  S_or2_336_1 = {&var1027,&var972,&var1026};
_S_or2  S_or2_337_1 = {&var1028,&var972,&var1027};
_S_and4  S_and4_338_1 = {&var1320,&var1268,&var1269,&var1119,&var1028};
_S_or2  S_or2_323_1 = {&var1320,&var1318,&var1029};
_S_and2  S_and2_308_1 = {&var1282,&var1251,&var1030};
_S_or2  S_or2_314_1 = {&var1033,&var1030,&var1031};
_S_or2  S_or2_288_1 = {&R0MD34LP1,&var1254,&var1032};
_S_or4  S_or4_305_1 = {&var1245,&R0MD31LP1,&var425,&var1254,&var1033};
_S_and3  S_and3_298_1 = {&var1035,&var1124,&var484,&var1034};
_S_or2  S_or2_297_1 = {&var1273,&var1457,&var1035};
_S_and3  S_and3_300_1 = {&var1274,&var1276,&var1275,&var1036};
_S_or2  S_or2_290_1 = {&var1038,&var1036,&var1037};
_S_and3  S_and3_284_1 = {&R0MD33LP1,&var1278,&var1277,&var1038};
_S_or2  S_or2_1223_1 = {&B4IS11LDU,&A4IS11LDU,&var1039};
_S_and2  S_and2_1226_1 = {&var1677,&var1724,&var1040};
_S_and2  S_and2_1225_1 = {&var1677,&var1832,&var1041};
_S_and2  S_and2_1224_1 = {&var1677,&var1111,&var1042};
_S_and2  S_and2_1222_1 = {&var1677,&var1039,&var1043};
_S_and2  S_and2_1212_1 = {&var1677,&var376,&var1044};
_S_and2  S_and2_1211_1 = {&var1100,&var1677,&var1045};
_S_and2  S_and2_1210_1 = {&var1677,&R3IS21LDU,&var1046};
_S_and2  S_and2_1213_1 = {&var1677,&var1887,&var1047};
_S_and2  S_and2_1205_1 = {&var468,&var1213,&var1048};
_S_and2  S_and2_1206_1 = {&var479,&var1211,&var1049};
_S_and2  S_and2_1207_1 = {&var473,&var1209,&var1050};
_S_and2  S_and2_1208_1 = {&var476,&var1207,&var1051};
_S_or2  S_or2_1190_1 = {&R0MD31LP1,&var1053,&var1052};
_S_and4  S_and4_1191_1 = {&var381,&var380,&var379,&var378,&var1053};
_S_or2  S_or2_1272_1 = {&var1677,&var1942,&var1054};
_S_or2  S_or2_1245_1 = {&var1727,&var1301,&var1055};
_S_or2  S_or2_1319_1 = {&var1768,&var1767,&var1056};
_S_or2  S_or2_1305_1 = {&var1777,&var1776,&var1057};
_S_or2  S_or2_1315_1 = {&var1194,&R0MD34LP1,&var1058};
_S_or2  S_or2_1289_1 = {&var1056,&var1832,&var1059};
_S_or2  S_or2_1287_1 = {&var1061,&var1059,&var1060};
_S_or2  S_or2_1288_1 = {&var1057,&var1832,&var1061};
_S_or4  S_or4_384_1 = {&var1804,&var1803,&var1805,&var1802,&var1062};
_S_or2  S_or2_735_1 = {&B5IS11LDU,&A5IS11LDU,&var1063};
_S_and2  S_and2_734_1 = {&var1068,&var1063,&var1064};
_S_or2  S_or2_733_1 = {&B6IS11LDU,&A6IS11LDU,&var1065};
_S_and2  S_and2_732_1 = {&var1068,&var1065,&var1066};
_S_or2  S_or2_731_1 = {&A4IS11LDU,&B4IS11LDU,&var1067};
_S_or2  S_or2_722_1 = {&var1070,&var1071,&var1068};
_S_and2  S_and2_728_1 = {&var1068,&var1067,&var1069};
_S_and2  S_and2_725_1 = {&var376,&var1081,&var1070};
_S_and2  S_and2_721_1 = {&var377,&var1074,&var1071};
_S_and2  S_and2_852_1 = {&var1830,&var1748,&var1072};
_S_and2  S_and2_848_1 = {&var1830,&var1749,&var1073};
_S_and3  S_and3_843_1 = {&var1830,&var377,&var1755,&var1074};
_S_or2  S_or2_851_1 = {&var1750,&var1744,&var1075};
_S_or2  S_or2_846_1 = {&var1748,&var1750,&var1076};
_S_or2  S_or2_842_1 = {&var1750,&var1749,&var1077};
_S_and2  S_and2_824_1 = {&var1744,&var1830,&var1078};
_S_or2  S_or2_815_1 = {&var1751,&var1752,&var1079};
_S_or2  S_or2_811_1 = {&var1809,&var1751,&var1080};
_S_and2  S_and2_808_1 = {&var1752,&var1831,&var1081};
_S_and2  S_and2_807_1 = {&var1809,&var1831,&var1082};
_S_and2  S_and2_836_1 = {&var471,&var1830,&var1083};
_S_and2  S_and2_817_1 = {&var471,&var1761,&var1084};
_S_and2  S_and2_834_1 = {&var1831,&var471,&var1085};
_S_or2  S_or2_828_1 = {&var1831,&var1830,&var1086};
_S_or3  S_or3_821_1 = {&var287,&var1089,&var1090,&var1087};
_S_or4  S_or4_820_1 = {&var1089,&var286,&var1091,&var1740,&var1088};
_S_or3  S_or3_810_1 = {&R4MD31LP2,&var1078,&var1082,&var1089};
_S_or2  S_or2_840_1 = {&var1829,&var1093,&var1090};
_S_or2  S_or2_839_1 = {&var1829,&var1092,&var1091};
_S_and2  S_and2_745_1 = {&var287,&var1743,&var1092};
_S_and3  S_and3_783_1 = {&var1742,&var1756,&var286,&var1093};
_S_and2  S_and2_788_1 = {&R5IS11LDU,&var1108,&var1094};
_S_and3  S_and3_786_1 = {&var1394,&R3IS21LDU,&var1108,&var1095};
_S_and2  S_and2_787_1 = {&R6IS21LDU,&var1108,&var1096};
_S_or2  S_or2_785_1 = {&B8IS22LDU,&A8IS22LDU,&var1097};
_S_and2  S_and2_784_1 = {&var1097,&var1108,&var1098};
_S_and2  S_and2_767_1 = {&var1108,&var1100,&var1099};
_S_or4  S_or4_768_1 = {&A0VN71LZ1,&B0VN71LZ1,&B0VN71LZ2,&A0VN71LZ2,&var1100};
_S_and2  S_and2_765_1 = {&var1105,&var1108,&var1101};
_S_and2  S_and2_753_1 = {&var1111,&var1108,&var1102};
_S_and2  S_and2_752_1 = {&var1832,&var1108,&var1103};
_S_or3  S_or3_751_1 = {&R0NE01LDU,&R0NE02LDU,&R0NE08LDU,&var1104};
_S_or2  S_or2_766_1 = {&R1IS21LDU,&R2IS21LDU,&var1105};
_S_and2  S_and2_750_1 = {&var1108,&var1104,&var1106};
_S_and2  S_and2_748_1 = {&var1810,&var1108,&var1107};
_S_or2  S_or2_738_1 = {&var1831,&var1830,&var1108};
_S_or2  S_or2_173_1 = {&var1400,&var991,&var1109};
_S_or3  S_or3_163_1 = {&var801,&var1399,&var1211,&var1110};
_S_or2  S_or2_154_1 = {&var1673,&var620,&var1111};
_S_or3  S_or3_115_1 = {&var1364,&var607,&var608,&var1112};
_S_or2  S_or2_2197_1 = {&var569,&var446,&var1113};
_S_or3  S_or3_644_1 = {&var1115,&var1116,&var942,&var1114};
_S_and2  S_and2_628_1 = {&var1570,&var1118,&var1115};
_S_and2  S_and2_629_1 = {&var1570,&var1168,&var1116};
_S_or2  S_or2_61_1 = {&var1168,&var1118,&var1117};
_S_and2  S_and2_64_1 = {&var1119,&var1247,&var1118};
_S_and2  S_and2_63_1 = {&var1839,&var1248,&var1119};
_S_or2  S_or2_48_1 = {&A4IS21LDU,&B4IS21LDU,&var1120};
_S_or2  S_or2_35_1 = {&var1490,&var1487,&var1121};
_S_or2  S_or2_39_1 = {&var1490,&var1489,&var1122};
_S_or2  S_or2_20_1 = {&var1394,&var1349,&var1123};
_S_or2  S_or2_8_1 = {&var1849,&var1170,&var1124};
_S_or2  S_or2_14_1 = {&var1170,&var1850,&var1125};
_S_and3  S_and3_1112_1 = {&var481,&var1843,&var1145,&var1126};
_S_and3  S_and3_657_1 = {&var1145,&var484,&var1843,&var1127};
_S_and2  S_and2_1179_1 = {&var1191,&var1129,&var1128};
_S_or2  S_or2_1185_1 = {&var1850,&var1849,&var1129};
_S_or2  S_or2_1531_1 = {&var1851,&var1849,&var1130};
_S_and3  S_and3_1530_1 = {&var1189,&var1130,&var868,&var1131};
_S_or2  S_or2_1080_1 = {&var1851,&var1849,&var1132};
_S_and3  S_and3_1079_1 = {&var1189,&var1132,&var883,&var1133};
_S_or2  S_or2_615_1 = {&var1851,&var1849,&var1134};
_S_and3  S_and3_614_1 = {&var1189,&var1134,&var1571,&var1135};
_S_and2  S_and2_612_1 = {&var372,&var1571,&var1136};
_S_or2  S_or2_249_1 = {&var1851,&var1849,&var1137};
_S_and3  S_and3_248_1 = {&var1189,&var1137,&var1604,&var1138};
_S_and2  S_and2_246_1 = {&var1604,&var373,&var1139};
_S_and3  S_and3_969_1 = {&var1189,&var1142,&var908,&var1140};
_S_and2  S_and2_968_1 = {&var703,&var908,&var1141};
_S_or2  S_or2_970_1 = {&var1851,&var1849,&var1142};
_S_or2  S_or2_1426_1 = {&var1851,&var1849,&var1143};
_S_or2  S_or2_6_1 = {&var1850,&var1849,&var1144};
_S_or3  S_or3_5_1 = {&var1851,&var1850,&var1849,&var1145};
_S_or2  S_or2_827_1 = {&var1751,&var1753,&var1146};
_S_or2  S_or2_478_1 = {&var1832,&var1151,&var1147};
_S_or2  S_or2_456_1 = {&var1832,&var1152,&var1148};
_S_or4  S_or4_457_1 = {&var1148,&var1760,&var1759,&var1147,&var1149};
_S_and2  S_and2_448_1 = {&A8IS22LDU,&var1824,&var1150};
_S_or3  S_or3_428_1 = {&var1814,&var1812,&var1813,&var1151};
_S_or3  S_or3_412_1 = {&var1822,&var1821,&var1823,&var1152};
_S_and2  S_and2_814_1 = {&var1831,&var1753,&var1153};
_S_and2  S_and2_38_1 = {&var1487,&var1488,&var1154};
_S_and2  S_and2_149_1 = {&var1763,&var1387,&var1155};
_S_and2  S_and2_157_1 = {&var1765,&var1387,&var1156};
_S_and2  S_and2_160_1 = {&var1762,&var1387,&var1157};
_S_and2  S_and2_152_1 = {&var1387,&var1764,&var1158};
_S_and2  S_and2_474_1 = {&var1111,&var1816,&var1159};
_S_and2  S_and2_472_1 = {&B8IS22LDU,&var1816,&var1160};
_S_and2  S_and2_470_1 = {&A8IS22LDU,&var1816,&var1161};
_S_and2  S_and2_468_1 = {&R5IS11LDU,&var1816,&var1162};
_S_and2  S_and2_459_1 = {&var1758,&var1824,&var1163};
_S_and2  S_and2_447_1 = {&R5IS11LDU,&var1824,&var1164};
_S_and2  S_and2_451_1 = {&var1111,&var1824,&var1165};
_S_and2  S_and2_119_1 = {&var1170,&var606,&var1166};
_S_and2  S_and2_59_1 = {&var1840,&var1248,&var1167};
_S_and2  S_and2_60_1 = {&var1167,&var1246,&var1168};
_S_and2  S_and2_42_1 = {&var1488,&var1489,&var1169};
_S_and2  S_and2_11_1 = {&var1848,&var1480,&var1170};
_S_and2  S_and2_31_1 = {&var1411,&var470,&var1171};
_S_and2  S_and2_30_1 = {&var1307,&var1394,&var1172};
_S_and2  S_and2_29_1 = {&var1308,&var1394,&var1173};
_S_and2  S_and2_28_1 = {&var1309,&var1394,&var1174};
_S_and2  S_and2_27_1 = {&var1310,&var1394,&var1175};
_S_and2  S_and2_841_1 = {&var1747,&var1755,&var1176};
_S_and2  S_and2_823_1 = {&var1754,&var1831,&var1177};
_S_bol  S_bol_658_1 = {&var1956,&fRM_20_0,&var1178};
_S_bol  S_bol_652_1 = {&var1953,&fRM_20_0,&var1179};
_S_bol  S_bol_643_1 = {&var1953,&fRM_20_03,&var1180};
_S_bol  S_bol_639_1 = {&var1956,&fRM_20_03,&var1181};
_S_bol  S_bol_1099_1 = {&var1953,&fRM_20_03,&var1182};
_S_bol  S_bol_1106_1 = {&var1956,&fRM_20_03,&var1183};
_S_bol  S_bol_1553_1 = {&var1956,&fRM_20_03,&var1184};
_S_bol  S_bol_1555_1 = {&var1953,&fRM_20_03,&var1185};
_S_bol  S_bol_276_1 = {&var1953,&fRM_20_03,&var1186};
_S_bol  S_bol_280_1 = {&var1956,&fRM_20_03,&var1187};
_S_sr  S_sr_88_1 = {array_m88_x_1,&iRM_2_,&var1188};
_S_bol  S_bol_87_1 = {&var1188,&var424,&var1189};
_S_ma  S_ma_90_1 = {array_m90_x_1,&R0MW15IP1,&iRM_8_,&var1190};
_S_bol  S_bol_1180_1 = {&var1192,&fEM_R0UN80RDU,&var1191};
_S_sr  S_sr_1186_1 = {array_m1186_x_1,&iRM_2_,&var1192};
_S_ovbs  S_ovbs_2285_1 = {&lRM_1_,&fEM_A9UZ04RDU,&var1193,&internal1_m2285_tx};
_S_ovbs  S_ovbs_1314_1 = {&lRM_1_,&fEM_A4UZ04RDU,&var1194,&internal1_m1314_tx};
_S_zpfs  S_zpfs_1801_1 = {&var1718,&fEM_B8UL03RDU,&var1195,&internal1_m1801_tx,&internal1_m1801_y0};
_S_zpfs  S_zpfs_1278_1 = {&var1735,&fEM_B8UL03RDU,&var1196,&internal1_m1278_tx,&internal1_m1278_y0};
_S_ma  S_ma_1339_1 = {array_m1339_x_1,&var1687,&iRM_8_,&var1197};
_S_ma  S_ma_903_1 = {array_m903_x_1,&var1647,&iRM_8_,&var1198};
_S_ma  S_ma_999_1 = {array_m999_x_1,&var1538,&iRM_8_,&var1199};
_S_ma  S_ma_1455_1 = {array_m1455_x_1,&var1506,&iRM_8_,&var1200};
_S_ma  S_ma_543_1 = {array_m543_x_1,&var1567,&iRM_8_,&var1201};
_S_ma  S_ma_170_1 = {array_m170_x_1,&var1600,&iRM_8_,&var1202};
_S_zpfs  S_zpfs_1498_1 = {&var1523,&fEM_A3UL03RDU,&var1203,&internal1_m1498_tx,&internal1_m1498_y0};
_S_zpfs  S_zpfs_1047_1 = {&var1555,&fEM_A3UL03RDU,&var1204,&internal1_m1047_tx,&internal1_m1047_y0};
_S_zpfs  S_zpfs_1388_1 = {&var1705,&fEM_A2UL03RDU,&var1205,&internal1_m1388_tx,&internal1_m1388_y0};
_S_rs  S_rs_1204_1 = {&var1052,&var1051,&var1206,&vainSBool,&internal1_m1204_q0};
_S_rs  S_rs_1202_1 = {&var381,&var1214,&var1207,&vainSBool,&internal1_m1202_q0};
_S_rs  S_rs_1201_1 = {&var1052,&var1050,&var1208,&vainSBool,&internal1_m1201_q0};
_S_rs  S_rs_1199_1 = {&var380,&var1214,&var1209,&vainSBool,&internal1_m1199_q0};
_S_rs  S_rs_1198_1 = {&var1052,&var1049,&var1210,&vainSBool,&internal1_m1198_q0};
_S_rs  S_rs_1196_1 = {&var379,&var1214,&var1211,&vainSBool,&internal1_m1196_q0};
_S_rs  S_rs_1195_1 = {&var1052,&var1048,&var1212,&vainSBool,&internal1_m1195_q0};
_S_rs  S_rs_1193_1 = {&var378,&var1214,&var1213,&vainSBool,&internal1_m1193_q0};
_S_rs  S_rs_1192_1 = {&var1052,&var425,&var1214,&vainSBool,&internal1_m1192_q0};
_S_noto  S_noto_2107_1 = {&var671,&var1215};
_S_swtakt  S_swtakt_52_1 = {&var601,&var6,&var1216,&internal1_m52_x0,&internal1_m52_LastSwitch};
_S_noto  S_noto_1178_1 = {&var1228,&var1217};
_S_noto  S_noto_1152_1 = {&var1226,&var1218};
_S_noto  S_noto_1164_1 = {&var1227,&var1219};
_S_rs  S_rs_1111_1 = {&var1229,&var809,&var1220,&vainSBool,&internal1_m1111_q0};
_S_swtakt  S_swtakt_1609_1 = {&var769,&var763,&var1221,&internal1_m1609_x0,&internal1_m1609_LastSwitch};
_S_swtakt  S_swtakt_1653_1 = {&var757,&var753,&var1222,&internal1_m1653_x0,&internal1_m1653_LastSwitch};
_S_swtakt  S_swtakt_1649_1 = {&var751,&var744,&var1223,&internal1_m1649_x0,&internal1_m1649_LastSwitch};
_S_swtakt  S_swtakt_2067_1 = {&var658,&var649,&var1224,&internal1_m2067_x0,&internal1_m2067_LastSwitch};
_S_swtakt  S_swtakt_2041_1 = {&var632,&var13,&var1225,&internal1_m2041_x0,&internal1_m2041_LastSwitch};
_S_rs  S_rs_1151_1 = {&var1300,&var797,&var1226,&vainSBool,&internal1_m1151_q0};
_S_rs  S_rs_1163_1 = {&var1300,&var798,&var1227,&vainSBool,&internal1_m1163_q0};
_S_rs  S_rs_1175_1 = {&var1300,&var799,&var1228,&vainSBool,&internal1_m1175_q0};
_S_rs  S_rs_1184_1 = {&var1300,&var800,&var1229,&vainSBool,&internal1_m1184_q0};
_S_noto  S_noto_1138_1 = {&var815,&var1230};
_S_noto  S_noto_1165_1 = {&var815,&var1231};
_S_noto  S_noto_1171_1 = {&var819,&var1232};
_S_rs  S_rs_1162_1 = {&var793,&var795,&var1233,&vainSBool,&internal1_m1162_q0};
_S_rs  S_rs_1177_1 = {&var1300,&var791,&var1234,&vainSBool,&internal1_m1177_q0};
_S_bol  S_bol_1159_1 = {&var1941,&var531,&var1235};
_S_bol  S_bol_1158_1 = {&var1944,&var531,&var1236};
_S_noto  S_noto_1118_1 = {&var1295,&var1237};
_S_bol  S_bol_1156_1 = {&var531,&var1941,&var1238};
_S_bol  S_bol_1155_1 = {&var531,&var1944,&var1239};
_S_noto  S_noto_1142_1 = {&var1296,&var1240};
_S_rs  S_rs_2125_1 = {&var676,&var667,&var1241,&vainSBool,&internal1_m2125_q0};
_S_rs  S_rs_2124_1 = {&var676,&var668,&var1242,&vainSBool,&internal1_m2124_q0};
_S_noto  S_noto_348_1 = {&var1023,&var1243};
_S_noto  S_noto_330_1 = {&var1016,&var1244};
_S_noto  S_noto_299_1 = {&var1035,&var1245};
_S_noto  S_noto_57_1 = {&var1257,&var1246};
_S_noto  S_noto_68_1 = {&var1279,&var1247};
_S_noto  S_noto_67_1 = {&var1214,&var1248};
_S_noto  S_noto_2119_1 = {&B2IS11LDU,&var1249};
_S_noto  S_noto_2117_1 = {&A2IS11LDU,&var1250};
_S_noto  S_noto_307_1 = {&var484,&var1251};
_S_noto  S_noto_2126_1 = {&B2IS11LDU,&var1252};
_S_noto  S_noto_2101_1 = {&A2IS11LDU,&var1253};
_S_noto  S_noto_294_1 = {&var1119,&var1254};
_S_noto  S_noto_352_1 = {&var1167,&var1255};
_S_bolz  S_bolz_356_1 = {&iRM_2_,&var1258,&var1256};
_S_provsbr  S_provsbr_351_1 = {&var1318,&var979,&var1333,&var1350,&var1344,&var1339,&var1336,&var1334,&var1348,&var1343,&var1341,&var1337,&iRM_10_,array_m351_Tpr_1,array_m351_type_1,&var1257,&var1258,&var1259,&var1260,&var1261,&var1262,&var1263,&var1264,&var1265,&internal1_m351_Step,array_m351_rz_1,&internal1_m351_TimS,&internal1_m351_FinPr0,&internal1_m351_ErrPr0,&internal1_m351_sbINI0,&internal1_m351_sbVuIS0,&internal1_m351_sb2UR0,&internal1_m351_sbNupIS0,&internal1_m351_sbVuRB0,&internal1_m351_MyFirstEnterFlag};
_S_orni  S_orni_355_1 = {array_m355_x_1,&iRM_5_,&vainSBool,&var1266};
_S_cntch  S_cntch_359_1 = {&var1266,&var1267,&internal1_m359_x0};
_S_bolz  S_bolz_333_1 = {&iRM_20_,&var1281,&var1268};
_S_equz_p  S_equz_p_332_1 = {&var1280,&iRM_0_,&var1269};
_S_decatron  S_decatron_316_1 = {&var1015,&var1270,&internal1_m316_TimS};
_S_noto  S_noto_1115_1 = {&R2IS21LDU,&var1271};
_S_noto  S_noto_1109_1 = {&R1IS21LDU,&var1272};
_S_andn  S_andn_289_1 = {array_m289_x_1,&iRM_7_,&var1273};
_S_noto  S_noto_291_1 = {&R0MD33LP1,&var1274};
_S_noto  S_noto_301_1 = {&R2IS21LDU,&var1275};
_S_noto  S_noto_295_1 = {&R1IS21LDU,&var1276};
_S_noto  S_noto_286_1 = {&R1IS11LDU,&var1277};
_S_noto  S_noto_283_1 = {&R2IS11LDU,&var1278};
_S_provsbr  S_provsbr_293_1 = {&var1320,&var1032,&var1333,&var1350,&var1344,&var1339,&var1336,&var1334,&var1348,&var1343,&var1341,&var1337,&iRM_10_,array_m293_Tpr_1,array_m293_type_1,&var1279,&var1280,&var1281,&var1282,&var1283,&var1284,&var1285,&var1286,&var1287,&internal1_m293_Step,array_m293_rz_1,&internal1_m293_TimS,&internal1_m293_FinPr0,&internal1_m293_ErrPr0,&internal1_m293_sbINI0,&internal1_m293_sbVuIS0,&internal1_m293_sb2UR0,&internal1_m293_sbNupIS0,&internal1_m293_sbVuRB0,&internal1_m293_MyFirstEnterFlag};
_S_rs  S_rs_1572_1 = {&var1289,&var790,&var1288,&vainSBool,&internal1_m1572_q0};
_S_provsbr  S_provsbr_1573_1 = {&var1288,&R0MD34LP1,&var1333,&var1350,&var1344,&var1339,&var1336,&var1334,&var1348,&var1343,&var1341,&var1337,&iRM_6_,array_m1573_Tpr_1,array_m1573_type_1,&var1289,&vainSInt,&vainSInt,&vainSBool,&var1290,&var1291,&var1292,&var1293,&var1294,&internal1_m1573_Step,array_m1573_rz_1,&internal1_m1573_TimS,&internal1_m1573_FinPr0,&internal1_m1573_ErrPr0,&internal1_m1573_sbINI0,&internal1_m1573_sbVuIS0,&internal1_m1573_sb2UR0,&internal1_m1573_sbNupIS0,&internal1_m1573_sbVuRB0,&internal1_m1573_MyFirstEnterFlag};
_S_abs_subf  S_abs_subf_1121_1 = {&var531,&var1944,&fEM_B8UC01RDU,&vainSFloat,&var1295};
_S_abs_subf  S_abs_subf_1134_1 = {&var1941,&var531,&fEM_B8UC01RDU,&vainSFloat,&var1296};
_S_noto  S_noto_718_1 = {&var983,&var1297};
_S_noto  S_noto_665_1 = {&var999,&var1298};
_S_noto  S_noto_49_1 = {&var527,&var1299};
_S_noto  S_noto_1139_1 = {&var1495,&var1300};
_S_rs  S_rs_1148_1 = {&var792,&var621,&var1301,&vainSBool,&internal1_m1148_q0};
_S_rs  S_rs_1145_1 = {&var796,&var791,&var1302,&vainSBool,&internal1_m1145_q0};
_S_rs  S_rs_1147_1 = {&var1300,&var621,&var1303,&vainSBool,&internal1_m1147_q0};
_S_rs  S_rs_1140_1 = {&var1300,&var794,&var1304,&vainSBool,&internal1_m1140_q0};
_S_noto  S_noto_654_1 = {&A2IS21LDU,&var1305};
_S_noto  S_noto_656_1 = {&B2IS21LDU,&var1306};
_S_noto  S_noto_25_1 = {&B2IS21LDU,&var1307};
_S_noto  S_noto_24_1 = {&B1IS21LDU,&var1308};
_S_noto  S_noto_23_1 = {&A1IS21LDU,&var1309};
_S_noto  S_noto_22_1 = {&A2IS21LDU,&var1310};
_S_newstage  S_newstage_666_1 = {&var349,&var346,&A2IS12LDU,&B2IS12LDU,&var1311};
_S_noto  S_noto_655_1 = {&B2IS12LDU,&var1312};
_S_noto  S_noto_653_1 = {&A2IS12LDU,&var1313};
_S_noto  S_noto_365_1 = {&var974,&var1314};
_S_noto  S_noto_369_1 = {&var973,&var1315};
_S_noto  S_noto_1108_1 = {&var1111,&var1316};
_S_rs  S_rs_831_1 = {&var971,&var604,&var1317,&vainSBool,&internal1_m831_q0};
_S_rs  S_rs_361_1 = {&var975,&var976,&var1318,&vainSBool,&internal1_m361_q0};
_S_rs  S_rs_357_1 = {&var977,&var978,&var1319,&vainSBool,&internal1_m357_q0};
_S_rs  S_rs_313_1 = {&var1031,&var1017,&var1320,&vainSBool,&internal1_m313_q0};
_S_orni  S_orni_309_1 = {array_m309_x_1,&iRM_5_,&vainSBool,&var1321};
_S_cntch  S_cntch_312_1 = {&var1321,&var1322,&internal1_m312_x0};
_S_noto  S_noto_1622_1 = {&var1341,&var1323};
_S_noto  S_noto_1678_1 = {&var1343,&var1324};
_S_noto  S_noto_1680_1 = {&var1348,&var1325};
_S_noto  S_noto_2052_1 = {&var1334,&var1326};
_S_noto  S_noto_2082_1 = {&var1337,&var1327};
_S_noto  S_noto_2063_1 = {&var1224,&var1328};
_S_noto  S_noto_2038_1 = {&var1225,&var1329};
_S_noto  S_noto_1650_1 = {&var1223,&var1330};
_S_noto  S_noto_1645_1 = {&var1222,&var1331};
_S_noto  S_noto_1605_1 = {&var1221,&var1332};
_S_rs  S_rs_2055_1 = {&var776,&var625,&var1333,&vainSBool,&internal1_m2055_q0};
_S_rs  S_rs_2048_1 = {&var631,&var628,&var1334,&vainSBool,&internal1_m2048_q0};
_S_rs  S_rs_2042_1 = {&var627,&var1225,&var1335,&vainSBool,&internal1_m2042_q0};
_S_rs  S_rs_2108_1 = {&var776,&var645,&var1336,&vainSBool,&internal1_m2108_q0};
_S_rs  S_rs_2079_1 = {&var653,&var652,&var1337,&vainSBool,&internal1_m2079_q0};
_S_rs  S_rs_2068_1 = {&var655,&var1224,&var1338,&vainSBool,&internal1_m2068_q0};
_S_rs  S_rs_1636_1 = {&var776,&var762,&var1339,&vainSBool,&internal1_m1636_q0};
_S_kvf  S_kvf_1623_1 = {&var1342,&var763,&fRM_0_0,&var1340,&vainSInt,&vainSInt,&internal1_m1623_x0,&internal1_m1623_y0,&bFirstEnterFlag};
_S_rs  S_rs_1619_1 = {&var768,&var763,&var1341,&vainSBool,&internal1_m1619_q0};
_S_rs  S_rs_1610_1 = {&var765,&var1221,&var1342,&vainSBool,&internal1_m1610_q0};
_S_rs  S_rs_1669_1 = {&var758,&var753,&var1343,&vainSBool,&internal1_m1669_q0};
_S_rs  S_rs_1689_1 = {&var776,&var759,&var1344,&vainSBool,&internal1_m1689_q0};
_S_rs  S_rs_1654_1 = {&var756,&var1222,&var1345,&vainSBool,&internal1_m1654_q0};
_S_kvf  S_kvf_1670_1 = {&var1345,&var753,&fRM_0_0,&var1346,&vainSInt,&vainSInt,&internal1_m1670_x0,&internal1_m1670_y0,&bFirstEnterFlag};
_S_cntch  S_cntch_1590_1 = {&var778,&var1347,&internal1_m1590_x0};
_S_rs  S_rs_1675_1 = {&var750,&var744,&var1348,&vainSBool,&internal1_m1675_q0};
_S_rs  S_rs_26_1 = {&var1394,&var1171,&var1349,&vainSBool,&internal1_m26_q0};
_S_rs  S_rs_1690_1 = {&var776,&var743,&var1350,&vainSBool,&internal1_m1690_q0};
_S_noto  S_noto_1561_1 = {&var772,&var1351};
_S_noto  S_noto_1559_1 = {&var1170,&var1352};
_S_rs  S_rs_706_1 = {&var1726,&var986,&var1353,&vainSBool,&internal1_m706_q0};
_S_rs  S_rs_691_1 = {&var1726,&var993,&var1354,&vainSBool,&internal1_m691_q0};
_S_rs  S_rs_719_1 = {&var1726,&var994,&var1355,&vainSBool,&internal1_m719_q0};
_S_rs  S_rs_702_1 = {&var1726,&var1005,&var1356,&vainSBool,&internal1_m702_q0};
_S_rs  S_rs_686_1 = {&var1726,&var1008,&var1357,&vainSBool,&internal1_m686_q0};
_S_rs  S_rs_684_1 = {&var1726,&var1010,&var1358,&vainSBool,&internal1_m684_q0};
_S_rs  S_rs_672_1 = {&var1013,&var1729,&var1359,&vainSBool,&internal1_m672_q0};
_S_rsun  S_rsun_1575_1 = {&var776,&var1479,&vainSLong,&var1360,&internal1_m1575_q0};
_S_noto  S_noto_1483_1 = {&B3MD12LP1,&var1361};
_S_noto  S_noto_2012_1 = {&B3IS11LDU,&var1362};
_S_noto  S_noto_1986_1 = {&A3IS11LDU,&var1363};
_S_noto  S_noto_118_1 = {&var1170,&var1364};
_S_noto  S_noto_117_1 = {&var1369,&var1365};
_S_rs  S_rs_682_1 = {&var1726,&var1012,&var1366,&vainSBool,&internal1_m682_q0};
_S_orni  S_orni_1313_1 = {array_m1313_x_1,&iRM_5_,&var1367,&vainSLong};
_S_orni  S_orni_1301_1 = {array_m1301_x_1,&iRM_4_,&var1368,&vainSLong};
_S_rs  S_rs_116_1 = {&var1112,&var1166,&var1369,&vainSBool,&internal1_m116_q0};
_S_noto  S_noto_2015_1 = {&var694,&var1370};
_S_noto  S_noto_2014_1 = {&var693,&var1371};
_S_noto  S_noto_2026_1 = {&B3IS22LDU,&var1372};
_S_noto  S_noto_2006_1 = {&A3IS22LDU,&var1373};
_S_newstage  S_newstage_2010_1 = {&var710,&var706,&var709,&var705,&vainSBool};
_S_noto  S_noto_1954_1 = {&var1457,&var1374};
_S_rs  S_rs_1836_1 = {&var263,&var495,&var1375,&vainSBool,&internal1_m1836_q0};
_S_rs  S_rs_1835_1 = {&var256,&var497,&var1376,&vainSBool,&internal1_m1835_q0};
_S_rs  S_rs_1834_1 = {&var262,&var499,&var1377,&vainSBool,&internal1_m1834_q0};
_S_rs  S_rs_1833_1 = {&var238,&var501,&var1378,&vainSBool,&internal1_m1833_q0};
_S_rs  S_rs_1869_1 = {&var470,&var503,&var1379,&vainSBool,&internal1_m1869_q0};
_S_rs  S_rs_1868_1 = {&var274,&var506,&var1380,&vainSBool,&internal1_m1868_q0};
_S_rs  S_rs_1867_1 = {&var275,&var506,&var1381,&vainSBool,&internal1_m1867_q0};
_S_noto  S_noto_1373_1 = {&A2MD12LP1,&var1382};
_S_noto  S_noto_1354_1 = {&B2MD12LP1,&var1383};
_S_noto  S_noto_558_1 = {&B1MD12LP1,&var1384};
_S_ma  S_ma_1625_1 = {array_m1625_x_1,&var1360,&iRM_16_,&var1385};
_S_noto  S_noto_1569_1 = {&var1027,&var1386};
_S_noto  S_noto_147_1 = {&var1170,&var1387};
_S_equz_p  S_equz_p_1992_1 = {&R0MW14IP2,&iRM_5_,&var1388};
_S_equz_p  S_equz_p_1991_1 = {&R0MW14IP2,&iRM_4_,&var1389};
_S_equz_p  S_equz_p_1990_1 = {&R0MW14IP2,&iRM_3_,&var1390};
_S_equz_p  S_equz_p_1988_1 = {&R0MW14IP2,&iRM_1_,&vainSBool};
_S_equz_p  S_equz_p_1989_1 = {&R0MW14IP2,&iRM_2_,&var1391};
_S_noto  S_noto_2072_1 = {&B2IS11LDU,&var1392};
_S_noto  S_noto_2080_1 = {&A2IS11LDU,&var1393};
_S_noto  S_noto_12_1 = {&var1848,&var1394};
_S_rs  S_rs_2139_1 = {&var589,&var680,&var1395,&vainSBool,&internal1_m2139_q0};
_S_rs  S_rs_1929_1 = {&var722,&var516,&var1396,&vainSBool,&internal1_m1929_q0};
_S_rs  S_rs_1918_1 = {&var259,&var517,&var1397,&vainSBool,&internal1_m1918_q0};
_S_rs  S_rs_1926_1 = {&var276,&var518,&var1398,&vainSBool,&internal1_m1926_q0};
_S_rs  S_rs_1915_1 = {&var260,&var519,&var1399,&vainSBool,&internal1_m1915_q0};
_S_rs  S_rs_1923_1 = {&var280,&var520,&var1400,&vainSBool,&internal1_m1923_q0};
_S_equz_p  S_equz_p_105_1 = {&R0MW16IP1,&iRM_10_,&var1401};
_S_noto  S_noto_185_1 = {&A1MD12LP1,&var1402};
_S_rs  S_rs_2353_1 = {&var250,&var247,&var1403,&vainSBool,&internal1_m2353_q0};
_S_rs  S_rs_2349_1 = {&var266,&var338,&var1404,&vainSBool,&internal1_m2349_q0};
_S_rs  S_rs_1894_1 = {&var279,&var513,&var1405,&vainSBool,&internal1_m1894_q0};
_S_rs  S_rs_1886_1 = {&var470,&var502,&var1406,&vainSBool,&internal1_m1886_q0};
_S_rs  S_rs_1884_1 = {&var261,&var503,&var1407,&vainSBool,&internal1_m1884_q0};
_S_rs  S_rs_1880_1 = {&var274,&var504,&var1408,&vainSBool,&internal1_m1880_q0};
_S_rs  S_rs_1876_1 = {&var236,&var506,&var1409,&vainSBool,&internal1_m1876_q0};
_S_rs  S_rs_1878_1 = {&var275,&var505,&var1410,&vainSBool,&internal1_m1878_q0};
_S_rs  S_rs_19_1 = {&var1123,&var610,&var1411,&vainSBool,&internal1_m19_q0};
_S_equz_p  S_equz_p_104_1 = {&R0MW16IP1,&iRM_9_,&var1412};
_S_equz_p  S_equz_p_103_1 = {&R0MW16IP1,&iRM_8_,&var1413};
_S_noto  S_noto_1032_1 = {&A3MD12LP1,&var1414};
_S_equz_p  S_equz_p_102_1 = {&R0MW16IP1,&iRM_7_,&var1415};
_S_equz_p  S_equz_p_101_1 = {&R0MW16IP1,&iRM_6_,&var1416};
_S_equz_p  S_equz_p_100_1 = {&R0MW16IP1,&iRM_5_,&var1417};
_S_rs  S_rs_1859_1 = {&var263,&var494,&var1418,&vainSBool,&internal1_m1859_q0};
_S_rs  S_rs_1857_1 = {&var255,&var495,&var1419,&vainSBool,&internal1_m1857_q0};
_S_rs  S_rs_1853_1 = {&var273,&var497,&var1420,&vainSBool,&internal1_m1853_q0};
_S_rs  S_rs_1855_1 = {&var256,&var496,&var1421,&vainSBool,&internal1_m1855_q0};
_S_rs  S_rs_1851_1 = {&var262,&var498,&var1422,&vainSBool,&internal1_m1851_q0};
_S_rs  S_rs_1849_1 = {&var239,&var499,&var1423,&vainSBool,&internal1_m1849_q0};
_S_rs  S_rs_2264_1 = {&var353,&var689,&var1424,&vainSBool,&internal1_m2264_q0};
_S_rs  S_rs_2259_1 = {&var354,&var690,&var1425,&vainSBool,&internal1_m2259_q0};
_S_equz_p  S_equz_p_322_1 = {&var1270,&iRM_0_,&var1426};
_S_noto  S_noto_2265_1 = {&var1424,&var1427};
_S_noto  S_noto_2254_1 = {&var614,&var1428};
_S_noto  S_noto_2237_1 = {&var1430,&var1429};
_S_rs  S_rs_2236_1 = {&var293,&var686,&var1430,&vainSBool,&internal1_m2236_q0};
_S_noto  S_noto_2221_1 = {&var1432,&var1431};
_S_rs  S_rs_2220_1 = {&var295,&var683,&var1432,&vainSBool,&internal1_m2220_q0};
_S_noto  S_noto_2260_1 = {&var1425,&var1433};
_S_noto  S_noto_2252_1 = {&var613,&var1434};
_S_noto  S_noto_2152_1 = {&var1436,&var1435};
_S_rs  S_rs_2151_1 = {&var588,&var681,&var1436,&vainSBool,&internal1_m2151_q0};
_S_noto  S_noto_2140_1 = {&var1395,&var1437};
_S_noto  S_noto_2147_1 = {&var611,&var1438};
_S_noto  S_noto_2134_1 = {&var612,&var1439};
_S_rs  S_rs_1845_1 = {&var272,&var501,&var1440,&vainSBool,&internal1_m1845_q0};
_S_rs  S_rs_1847_1 = {&var238,&var500,&var1441,&vainSBool,&internal1_m1847_q0};
_S_rs  S_rs_1831_1 = {&var253,&var486,&var1442,&vainSBool,&internal1_m1831_q0};
_S_rs  S_rs_1829_1 = {&var271,&var487,&var1443,&vainSBool,&internal1_m1829_q0};
_S_rs  S_rs_1827_1 = {&var252,&var488,&var1444,&vainSBool,&internal1_m1827_q0};
_S_rs  S_rs_1825_1 = {&var270,&var489,&var1445,&vainSBool,&internal1_m1825_q0};
_S_noto  S_noto_1949_1 = {&B3IS22LDU,&var1446};
_S_noto  S_noto_1948_1 = {&A3IS22LDU,&var1447};
_S_noto  S_noto_1947_1 = {&B2IS12LDU,&var1448};
_S_noto  S_noto_1946_1 = {&A2IS12LDU,&var1449};
_S_noto  S_noto_1945_1 = {&B1IS12LDU,&var1450};
_S_noto  S_noto_1944_1 = {&A1IS12LDU,&var1451};
_S_noto  S_noto_1974_1 = {&B3IS21LDU,&var1452};
_S_noto  S_noto_1968_1 = {&B2IS21LDU,&var1453};
_S_noto  S_noto_1973_1 = {&A3IS21LDU,&var1454};
_S_noto  S_noto_1971_1 = {&B4IS21LDU,&var1455};
_S_noto  S_noto_1972_1 = {&A4IS21LDU,&var1456};
_S_andn  S_andn_1957_1 = {array_m1957_x_1,&iRM_17_,&var1457};
_S_noto  S_noto_1966_1 = {&B1IS21LDU,&var1458};
_S_noto  S_noto_1967_1 = {&A2IS21LDU,&var1459};
_S_noto  S_noto_1965_1 = {&A1IS21LDU,&var1460};
_S_rs  S_rs_1824_1 = {&var1465,&var490,&var1461,&vainSBool,&internal1_m1824_q0};
_S_rs  S_rs_1822_1 = {&var254,&var491,&var1462,&vainSBool,&internal1_m1822_q0};
_S_rs  S_rs_1821_1 = {&var1465,&var492,&var1463,&vainSBool,&internal1_m1821_q0};
_S_rs  S_rs_1819_1 = {&var237,&var493,&var1464,&vainSBool,&internal1_m1819_q0};
_S_newstage  S_newstage_2288_1 = {&var1477,&var1471,&var1476,&var1470,&var1465};
_S_samhd  S_samhd_2290_1 = {&var734,&var735,&var735,&var1462,&var1461,&var1462,&var1461,&B9IS11LDU,&B9IS11LDU,&B9IS21LDU,&B9IS21LDU,&bRM_1_,&fEM_A9UZ05RDU,&fEM_A9UZ03RDU,&fEM_A9UZ04RDU,&var1466,&var1467,&var1468,&vainSBool,&var1469,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1470,&var1471,&internal1_m2290_DvUp0,&internal1_m2290_DvDw0,&internal1_m2290_FDvUp0,&internal1_m2290_FDvDw0,&internal1_m2290_BlDv0,&internal1_m2290_Pkv0,&internal1_m2290_Pkav0,&internal1_m2290_Zkv0,&internal1_m2290_Zkav0,&internal1_m2290_txNm,&internal1_m2290_txSm,&internal1_m2290_txHr,&internal1_m2290_txLd,&internal1_m2290_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_2284_1 = {&var734,&var736,&var736,&var1464,&var1463,&var1464,&var1463,&A9IS11LDU,&A9IS11LDU,&A9IS21LDU,&A9IS21LDU,&bRM_1_,&fEM_A9UZ05RDU,&fEM_A9UZ03RDU,&fEM_A9UZ04RDU,&var1472,&var1473,&var1474,&vainSBool,&var1475,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1476,&var1477,&internal1_m2284_DvUp0,&internal1_m2284_DvDw0,&internal1_m2284_FDvUp0,&internal1_m2284_FDvDw0,&internal1_m2284_BlDv0,&internal1_m2284_Pkv0,&internal1_m2284_Pkav0,&internal1_m2284_Zkv0,&internal1_m2284_Zkav0,&internal1_m2284_txNm,&internal1_m2284_txSm,&internal1_m2284_txHr,&internal1_m2284_txLd,&internal1_m2284_fef,&bFirstEnterFlag};
_S_orni  S_orni_1576_1 = {array_m1576_x_1,&iRM_5_,&var1478,&var1479};
_S_noto  S_noto_83_1 = {&var615,&var1480};
_S_maz  S_maz_328_1 = {array_m328_x_1,&R0MW12IP1,&iRM_3_,&var1481};
_S_maz  S_maz_319_1 = {array_m319_x_1,&R0MW12IP1,&iRM_3_,&var1482};
_S_rs  S_rs_1661_1 = {&var747,&var1223,&var1483,&vainSBool,&internal1_m1661_q0};
_S_kvf  S_kvf_1664_1 = {&var1483,&var744,&fRM_0_0,&var1484,&vainSInt,&vainSInt,&internal1_m1664_x0,&internal1_m1664_y0,&bFirstEnterFlag};
_S_kvf  S_kvf_2090_1 = {&var661,&var649,&fRM_0_0,&var1485,&vainSInt,&vainSInt,&internal1_m2090_x0,&internal1_m2090_y0,&bFirstEnterFlag};
_S_kvf  S_kvf_2050_1 = {&var1335,&var13,&fRM_0_0,&var1486,&vainSInt,&vainSInt,&internal1_m2050_x0,&internal1_m2050_y0,&bFirstEnterFlag};
_S_equz_p  S_equz_p_37_1 = {&R0MW13IP1,&iRM_1_,&var1487};
_S_noto  S_noto_34_1 = {&var1490,&var1488};
_S_equz_p  S_equz_p_41_1 = {&R0MW13IP1,&iRM_2_,&var1489};
_S_equz_p  S_equz_p_32_1 = {&R0MW13IP1,&iRM_3_,&var1490};
_S_noto  S_noto_2094_1 = {&var1338,&var1491};
_S_rs  S_rs_304_1 = {&var1033,&var1034,&var1492,&vainSBool,&internal1_m304_q0};
_S_orn  S_orn_663_1 = {array_m663_x_1,&iRM_5_,&var1493};
_S_noto  S_noto_1128_1 = {&lEM_R0MD01LC1,&var1494};
_S_rs  S_rs_1119_1 = {&var810,&var1126,&var1495,&vainSBool,&internal1_m1119_q0};
_S_rs  S_rs_694_1 = {&var988,&var990,&var1496,&vainSBool,&internal1_m694_q0};
_S_noto  S_noto_1557_1 = {&var1169,&var1497};
_S_orn  S_orn_1527_1 = {array_m1527_x_1,&iRM_8_,&var1498};
_S_noto  S_noto_1526_1 = {&var1666,&var1499};
_S_noto  S_noto_1525_1 = {&var1676,&var1500};
_S_noto  S_noto_1503_1 = {&var1170,&var1501};
_S_noto  S_noto_1516_1 = {&R8IS11LDU,&var1502};
_S_charint  S_charint_1445_1 = {&var1505,&var1503};
_S_ornc  S_ornc_1454_1 = {array_m1454_x_1,&iRM_3_,&var1504,&var1505};
_S_fsumz  S_fsumz_1446_1 = {&var1503,&iRM_1_,&var1506};
_S_cnshd  S_cnshd_1456_1 = {&R0MD34LP1,&var1947,&var1200,&var535,&var1504,&var855,&var851,&iRM_1_,array_m1456_Lt_fw_1,array_m1456_Vr_fw_1,&iRM_1_,array_m1456_Lt_bw_1,array_m1456_Vr_bw_1,&fEM_A3UC08RDU,&fEM_A3UC07RDU,&fEM_A3UL01RDU,&fEM_A3UC02RDU,&var1507,&vainSBool,&var1508,&var1509,&var1510,&var1511,&var1512,&var1513,&var1514,&var1515,&var1516,&var1517,&internal1_m1456_X0,&internal1_m1456_t0,&internal1_m1456_BLDv0};
_S_zpfs  S_zpfs_1473_1 = {&var1526,&fRM_2_0,&var1518,&internal1_m1473_tx,&internal1_m1473_y0};
_S_zpfs  S_zpfs_1474_1 = {&var1525,&fRM_3_0,&var1519,&internal1_m1474_tx,&internal1_m1474_y0};
_S_fnapb  S_fnapb_1482_1 = {&var1947,&var1200,&var854,&R0MD34LP1,&var1509,&var1516,&fEM_B8UV04RDU,&fEM_A3UV01RDU,&fEM_A3UV02RDU,&fEM_A3UC06RDU,&fEM_A3UC05RDU,&iRM_60_,&fEM_A3UL04RDU,&fEM_A3UL05RDU,&fEM_A3UL03RDU,&var1520,&var1521,&var1522,&var1523,&var1524,&var1525,&var1526,&vainSFloat,&internal1_m1482_xptr,array_m1482_x0_1,array_m1482_tim0_1,&internal1_m1482_sumtim,&internal1_m1482_StSpeed,&internal1_m1482_Vz0,&internal1_m1482_flRazg,&internal1_m1482_DelSp,&internal1_m1482_z0,&internal1_m1482_txZS,&internal1_m1482_tx,&internal1_m1482_txd,&internal1_m1482_txMBl,&internal1_m1482_txBl,&internal1_m1482_Speed0,&internal1_m1482_xz0,&internal1_m1482_tz0,&internal1_m1482_Shift0,&internal1_m1482_ShCntlSp0,&internal1_m1482_ShiftControl,&bFirstEnterFlag};
_S_newstage  S_newstage_1012_1 = {&var1536,&var1504,&var1539,&var1507,&var1527};
_S_rs  S_rs_692_1 = {&var989,&var993,&var1528,&vainSBool,&internal1_m692_q0};
_S_noto  S_noto_1105_1 = {&var1154,&var1529};
_S_orn  S_orn_1077_1 = {array_m1077_x_1,&iRM_8_,&var1530};
_S_noto  S_noto_1076_1 = {&var1666,&var1531};
_S_noto  S_noto_1075_1 = {&var1676,&var1532};
_S_noto  S_noto_1054_1 = {&var1170,&var1533};
_S_noto  S_noto_1065_1 = {&R8IS11LDU,&var1534};
_S_charint  S_charint_989_1 = {&var1537,&var1535};
_S_ornc  S_ornc_998_1 = {array_m998_x_1,&iRM_3_,&var1536,&var1537};
_S_fsumz  S_fsumz_990_1 = {&var1535,&iRM_1_,&var1538};
_S_cnshd  S_cnshd_1000_1 = {&R0MD34LP1,&var1950,&var1199,&var539,&var1536,&var890,&var891,&iRM_1_,array_m1000_Lt_fw_1,array_m1000_Vr_fw_1,&iRM_1_,array_m1000_Lt_bw_1,array_m1000_Vr_bw_1,&fEM_A3UC08RDU,&fEM_A3UC07RDU,&fEM_A3UL01RDU,&fEM_A3UC02RDU,&var1539,&vainSBool,&var1540,&var1541,&var1542,&var1543,&var1544,&var1545,&var1546,&var1547,&var1548,&var1549,&internal1_m1000_X0,&internal1_m1000_t0,&internal1_m1000_BLDv0};
_S_zpfs  S_zpfs_1023_1 = {&var1558,&fRM_2_0,&var1550,&internal1_m1023_tx,&internal1_m1023_y0};
_S_zpfs  S_zpfs_1022_1 = {&var1557,&fRM_3_0,&var1551,&internal1_m1022_tx,&internal1_m1022_y0};
_S_fnapb  S_fnapb_1030_1 = {&var1950,&var1199,&var889,&R0MD34LP1,&var1541,&var1548,&fEM_B8UV04RDU,&fEM_A3UV01RDU,&fEM_A3UV02RDU,&fEM_A3UC06RDU,&fEM_A3UC05RDU,&iRM_60_,&fEM_A3UL04RDU,&fEM_A3UL05RDU,&fEM_A3UL03RDU,&var1552,&var1553,&var1554,&var1555,&var1556,&var1557,&var1558,&vainSFloat,&internal1_m1030_xptr,array_m1030_x0_1,array_m1030_tim0_1,&internal1_m1030_sumtim,&internal1_m1030_StSpeed,&internal1_m1030_Vz0,&internal1_m1030_flRazg,&internal1_m1030_DelSp,&internal1_m1030_z0,&internal1_m1030_txZS,&internal1_m1030_tx,&internal1_m1030_txd,&internal1_m1030_txMBl,&internal1_m1030_txBl,&internal1_m1030_Speed0,&internal1_m1030_xz0,&internal1_m1030_tz0,&internal1_m1030_Shift0,&internal1_m1030_ShCntlSp0,&internal1_m1030_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_645_1 = {&var1169,&var1559};
_S_noto  S_noto_610_1 = {&var1666,&var1560};
_S_noto  S_noto_609_1 = {&var1676,&var1561};
_S_noto  S_noto_588_1 = {&var1170,&var1562};
_S_noto  S_noto_598_1 = {&R8IS11LDU,&var1563};
_S_charint  S_charint_536_1 = {&var1566,&var1564};
_S_ornc  S_ornc_542_1 = {array_m542_x_1,&iRM_3_,&var1565,&var1566};
_S_fsumz  S_fsumz_537_1 = {&var1564,&iRM_1_,&var1567};
_S_cnshd  S_cnshd_545_1 = {&R0MD34LP1,&var1960,&var1201,&var543,&var1565,&var961,&var955,&iRM_2_,array_m545_Lt_fw_1,array_m545_Vr_fw_1,&iRM_1_,array_m545_Lt_bw_1,array_m545_Vr_bw_1,&fEM_A1UC08RDU,&fEM_A1UC07RDU,&fEM_A1UL01RDU,&fEM_A1UC02RDU,&var1568,&vainSBool,&var1569,&var1570,&var1571,&var1572,&var1573,&var1574,&var1575,&var1576,&var1577,&var1578,&internal1_m545_X0,&internal1_m545_t0,&internal1_m545_BLDv0};
_S_zpfs  S_zpfs_564_1 = {&var1587,&fRM_2_0,&var1579,&internal1_m564_tx,&internal1_m564_y0};
_S_zpfs  S_zpfs_563_1 = {&var1586,&fRM_3_0,&var1580,&internal1_m563_tx,&internal1_m563_y0};
_S_fnapb  S_fnapb_568_1 = {&var1960,&var1201,&var959,&R0MD34LP1,&var1570,&var1577,&fEM_B8UV04RDU,&fEM_A1UV01RDU,&fEM_A1UV02RDU,&fEM_A1UC06RDU,&fEM_A1UC05RDU,&iRM_150_,&fEM_A1UL04RDU,&fEM_A1UL05RDU,&fEM_A1UL03RDU,&var1581,&var1582,&var1583,&var1584,&var1585,&var1586,&var1587,&vainSFloat,&internal1_m568_xptr,array_m568_x0_1,array_m568_tim0_1,&internal1_m568_sumtim,&internal1_m568_StSpeed,&internal1_m568_Vz0,&internal1_m568_flRazg,&internal1_m568_DelSp,&internal1_m568_z0,&internal1_m568_txZS,&internal1_m568_tx,&internal1_m568_txd,&internal1_m568_txMBl,&internal1_m568_txBl,&internal1_m568_Speed0,&internal1_m568_xz0,&internal1_m568_tz0,&internal1_m568_Shift0,&internal1_m568_ShCntlSp0,&internal1_m568_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_710_1 = {&R0MD33LP1,&var1588};
_S_noto  S_noto_282_1 = {&var1154,&var1589};
_S_newstage  S_newstage_210_1 = {&var1598,&var1565,&var1601,&var1568,&var1590};
_S_rs  S_rs_689_1 = {&var984,&var996,&var1591,&vainSBool,&internal1_m689_q0};
_S_orn  S_orn_245_1 = {array_m245_x_1,&iRM_12_,&var1592};
_S_noto  S_noto_244_1 = {&var1666,&var1593};
_S_noto  S_noto_243_1 = {&var1676,&var1594};
_S_noto  S_noto_222_1 = {&var1170,&var1595};
_S_noto  S_noto_232_1 = {&R8IS11LDU,&var1596};
_S_charint  S_charint_164_1 = {&var1599,&var1597};
_S_ornc  S_ornc_172_1 = {array_m172_x_1,&iRM_3_,&var1598,&var1599};
_S_fsumz  S_fsumz_165_1 = {&var1597,&iRM_1_,&var1600};
_S_cnshd  S_cnshd_175_1 = {&R0MD34LP1,&var1938,&var1202,&var547,&var1598,&var941,&var934,&iRM_2_,array_m175_Lt_fw_1,array_m175_Vr_fw_1,&iRM_1_,array_m175_Lt_bw_1,array_m175_Vr_bw_1,&fEM_A1UC08RDU,&fEM_A1UC07RDU,&fEM_A1UL01RDU,&fEM_A1UC02RDU,&var1601,&vainSBool,&var1602,&var1603,&var1604,&var1605,&var1606,&var1607,&var1608,&var1609,&var1610,&var1611,&internal1_m175_X0,&internal1_m175_t0,&internal1_m175_BLDv0};
_S_fnapb  S_fnapb_200_1 = {&var1938,&var1202,&var937,&R0MD34LP1,&var1603,&var1610,&fEM_B8UV04RDU,&fEM_A1UV01RDU,&fEM_A1UV02RDU,&fEM_A1UC06RDU,&fEM_A1UC05RDU,&iRM_150_,&fEM_A1UL04RDU,&fEM_A1UL05RDU,&fEM_A1UL03RDU,&var1612,&var1613,&var1614,&var1615,&var1616,&var1617,&var1618,&vainSFloat,&internal1_m200_xptr,array_m200_x0_1,array_m200_tim0_1,&internal1_m200_sumtim,&internal1_m200_StSpeed,&internal1_m200_Vz0,&internal1_m200_flRazg,&internal1_m200_DelSp,&internal1_m200_z0,&internal1_m200_txZS,&internal1_m200_tx,&internal1_m200_txd,&internal1_m200_txMBl,&internal1_m200_txBl,&internal1_m200_Speed0,&internal1_m200_xz0,&internal1_m200_tz0,&internal1_m200_Shift0,&internal1_m200_ShCntlSp0,&internal1_m200_ShiftControl,&bFirstEnterFlag};
_S_rs  S_rs_715_1 = {&var995,&var998,&var1619,&vainSBool,&internal1_m715_q0};
_S_newstage  S_newstage_508_1 = {&var1638,&var1629,&var1637,&var1628,&var1620};
_S_samhd  S_samhd_512_1 = {&R0MD34LP1,&var964,&var964,&var598,&var597,&R2VS12LDU,&R2VS22LDU,&R2IS11LDU,&R2IS11LDU,&R2IS21LDU,&R2IS21LDU,&bRM_0_,&fEM_R1UZ05RDU,&fEM_R1UZ03RDU,&fEM_R1UZ04RDU,&var1621,&var1622,&var1623,&var1624,&var1625,&var1626,&vainSBool,&vainSBool,&var1627,&var1628,&var1629,&internal1_m512_DvUp0,&internal1_m512_DvDw0,&internal1_m512_FDvUp0,&internal1_m512_FDvDw0,&internal1_m512_BlDv0,&internal1_m512_Pkv0,&internal1_m512_Pkav0,&internal1_m512_Zkv0,&internal1_m512_Zkav0,&internal1_m512_txNm,&internal1_m512_txSm,&internal1_m512_txHr,&internal1_m512_txLd,&internal1_m512_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_506_1 = {&R0MD34LP1,&var965,&var965,&var596,&var595,&R1VS12LDU,&R1VS22LDU,&R1IS11LDU,&R1IS11LDU,&R1IS21LDU,&R1IS21LDU,&bRM_0_,&fEM_R1UZ05RDU,&fEM_R1UZ03RDU,&fEM_R1UZ04RDU,&var1630,&var1631,&var1632,&var1633,&var1634,&var1635,&vainSBool,&vainSBool,&var1636,&var1637,&var1638,&internal1_m506_DvUp0,&internal1_m506_DvDw0,&internal1_m506_FDvUp0,&internal1_m506_FDvDw0,&internal1_m506_BlDv0,&internal1_m506_Pkv0,&internal1_m506_Pkav0,&internal1_m506_Zkv0,&internal1_m506_Zkav0,&internal1_m506_txNm,&internal1_m506_txSm,&internal1_m506_txHr,&internal1_m506_txLd,&internal1_m506_fef,&bFirstEnterFlag};
_S_orn  S_orn_962_1 = {array_m962_x_1,&iRM_10_,&var1639};
_S_noto  S_noto_961_1 = {&var1666,&var1640};
_S_noto  S_noto_960_1 = {&var1676,&var1641};
_S_noto  S_noto_940_1 = {&var1170,&var1642};
_S_noto  S_noto_954_1 = {&R8IS11LDU,&var1643};
_S_charint  S_charint_894_1 = {&var1646,&var1644};
_S_ornc  S_ornc_902_1 = {array_m902_x_1,&iRM_3_,&var1645,&var1646};
_S_fsumz  S_fsumz_895_1 = {&var1644,&iRM_1_,&var1647};
_S_cnshd  S_cnshd_904_1 = {&R0MD34LP1,&var1953,&var1198,&var1198,&var1645,&var914,&var828,&iRM_2_,array_m904_Lt_fw_1,array_m904_Vr_fw_1,&iRM_1_,array_m904_Lt_bw_1,array_m904_Vr_bw_1,&fEM_A2UC08RDU,&fEM_A2UC07RDU,&fEM_A2UL01RDU,&fEM_A2UC02RDU,&var1648,&vainSBool,&var1649,&var1650,&var1651,&var1652,&var1653,&var1654,&var1655,&var1656,&var1657,&var1658,&internal1_m904_X0,&internal1_m904_t0,&internal1_m904_BLDv0};
_S_fnapb  S_fnapb_922_1 = {&var1953,&var1198,&var910,&R0MD34LP1,&var1650,&var1657,&fEM_B8UV04RDU,&fEM_A2UV01RDU,&fEM_A2UV02RDU,&fEM_A2UC06RDU,&fEM_A2UC05RDU,&iRM_80_,&fEM_A2UL04RDU,&fEM_A2UL05RDU,&fEM_A2UL83RDU,&var1659,&var1660,&var1661,&var1662,&var1663,&var1664,&var1665,&vainSFloat,&internal1_m922_xptr,array_m922_x0_1,array_m922_tim0_1,&internal1_m922_sumtim,&internal1_m922_StSpeed,&internal1_m922_Vz0,&internal1_m922_flRazg,&internal1_m922_DelSp,&internal1_m922_z0,&internal1_m922_txZS,&internal1_m922_tx,&internal1_m922_txd,&internal1_m922_txMBl,&internal1_m922_txBl,&internal1_m922_Speed0,&internal1_m922_xz0,&internal1_m922_tz0,&internal1_m922_Shift0,&internal1_m922_ShCntlSp0,&internal1_m922_ShiftControl,&bFirstEnterFlag};
_S_cnshd  S_cnshd_1773_1 = {&R0MD34LP1,&var1944,&var531,&var531,&var738,&var741,&lRM_1_,&iRM_1_,array_m1773_Lt_fw_1,array_m1773_Vr_fw_1,&iRM_1_,array_m1773_Lt_bw_1,array_m1773_Vr_bw_1,&fEM_B8UC01RDU,&fEM_B8UC02RDU,&fEM_B8UL01RDU,&fRM_0_0,&var1666,&vainSBool,&vainSFloat,&var1667,&var1668,&var1669,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1670,&internal1_m1773_X0,&internal1_m1773_t0,&internal1_m1773_BLDv0};
_S_newstage  S_newstage_1384_1 = {&var1684,&var1645,&var1689,&var1648,&var1671};
_S_orn  S_orn_1423_1 = {array_m1423_x_1,&iRM_10_,&var1672};
_S_orn  S_orn_153_1 = {array_m153_x_1,&iRM_5_,&var1673};
_S_noto  S_noto_1422_1 = {&var1666,&var1674};
_S_noto  S_noto_1421_1 = {&var1676,&var1675};
_S_cnshd  S_cnshd_1246_1 = {&R0MD34LP1,&var1941,&var531,&var531,&var1055,&var739,&lRM_1_,&iRM_1_,array_m1246_Lt_fw_1,array_m1246_Vr_fw_1,&iRM_1_,array_m1246_Lt_bw_1,array_m1246_Vr_bw_1,&fEM_B8UC01RDU,&fEM_B8UC02RDU,&fEM_B8UL01RDU,&fRM_0_0,&var1676,&vainSBool,&vainSFloat,&var1677,&var1678,&var1679,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1680,&internal1_m1246_X0,&internal1_m1246_t0,&internal1_m1246_BLDv0};
_S_noto  S_noto_1397_1 = {&var1170,&var1681};
_S_noto  S_noto_1410_1 = {&R8IS11LDU,&var1682};
_S_charint  S_charint_1333_1 = {&var1685,&var1683};
_S_ornc  S_ornc_1342_1 = {array_m1342_x_1,&iRM_3_,&var1684,&var1685};
_S_noto  S_noto_674_1 = {&lEM_R0MD01LC1,&var1686};
_S_fsumz  S_fsumz_1334_1 = {&var1683,&iRM_1_,&var1687};
_S_rs  S_rs_687_1 = {&var1006,&var1008,&var1688,&vainSBool,&internal1_m687_q0};
_S_cnshd  S_cnshd_1343_1 = {&R0MD34LP1,&var1956,&var1197,&var1197,&var1684,&var831,&var824,&iRM_2_,array_m1343_Lt_fw_1,array_m1343_Vr_fw_1,&iRM_1_,array_m1343_Lt_bw_1,array_m1343_Vr_bw_1,&fEM_A2UC08RDU,&fEM_A2UC07RDU,&fEM_A2UL01RDU,&fEM_A2UC02RDU,&var1689,&vainSBool,&var1690,&var1691,&var1692,&var1693,&var1694,&var1695,&var1696,&var1697,&var1698,&var1699,&internal1_m1343_X0,&internal1_m1343_t0,&internal1_m1343_BLDv0};
_S_zpfs  S_zpfs_1371_1 = {&var1708,&fRM_2_0,&var1700,&internal1_m1371_tx,&internal1_m1371_y0};
_S_zpfs  S_zpfs_1370_1 = {&var1707,&fRM_3_0,&var1701,&internal1_m1370_tx,&internal1_m1370_y0};
_S_fnapb  S_fnapb_1378_1 = {&var1956,&var1197,&var832,&R0MD34LP1,&var1691,&var1698,&fEM_B8UV04RDU,&fEM_A2UV01RDU,&fEM_A2UV02RDU,&fEM_A2UC06RDU,&fEM_A2UC05RDU,&iRM_80_,&fEM_A2UL04RDU,&fEM_A2UL05RDU,&fEM_A2UL03RDU,&var1702,&var1703,&var1704,&var1705,&var1706,&var1707,&var1708,&vainSFloat,&internal1_m1378_xptr,array_m1378_x0_1,array_m1378_tim0_1,&internal1_m1378_sumtim,&internal1_m1378_StSpeed,&internal1_m1378_Vz0,&internal1_m1378_flRazg,&internal1_m1378_DelSp,&internal1_m1378_z0,&internal1_m1378_txZS,&internal1_m1378_tx,&internal1_m1378_txd,&internal1_m1378_txMBl,&internal1_m1378_txBl,&internal1_m1378_Speed0,&internal1_m1378_xz0,&internal1_m1378_tz0,&internal1_m1378_Shift0,&internal1_m1378_ShCntlSp0,&internal1_m1378_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_1754_1 = {&R8IS11LDU,&var1709};
_S_rs  S_rs_707_1 = {&var1009,&var1010,&var1710,&vainSBool,&internal1_m707_q0};
_S_zpfs  S_zpfs_1787_1 = {&var1721,&fRM_2_0,&var1711,&internal1_m1787_tx,&internal1_m1787_y0};
_S_zpfs  S_zpfs_1791_1 = {&var1720,&fRM_3_0,&var1712,&internal1_m1791_tx,&internal1_m1791_y0};
_S_samhd  S_samhd_1776_1 = {&R0MD34LP1,&var741,&var741,&var1668,&var1669,&var1715,&var1716,&A8IS12LDU,&A8IS12LDU,&A8IS22LDU,&A8IS22LDU,&bRM_3_,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&fEM_B8UL07RDU,&var1713,&var1714,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,&internal1_m1776_DvUp0,&internal1_m1776_DvDw0,&internal1_m1776_FDvUp0,&internal1_m1776_FDvDw0,&internal1_m1776_BlDv0,&internal1_m1776_Pkv0,&internal1_m1776_Pkav0,&internal1_m1776_Zkv0,&internal1_m1776_Zkav0,&internal1_m1776_txNm,&internal1_m1776_txSm,&internal1_m1776_txHr,&internal1_m1776_txLd,&internal1_m1776_fef,&bFirstEnterFlag};
_S_fnapb  S_fnapb_1795_1 = {&var1944,&var531,&var737,&R0MD34LP1,&var1667,&fEM_B8UV03RDU,&fEM_B8UV04RDU,&fEM_B8UV01RDU,&fEM_B8UV02RDU,&fEM_B8UC06RDU,&fEM_B8UC05RDU,&iRM_20_,&fEM_B8UL04RDU,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&var1715,&var1716,&var1717,&var1718,&var1719,&var1720,&var1721,&vainSFloat,&internal1_m1795_xptr,array_m1795_x0_1,array_m1795_tim0_1,&internal1_m1795_sumtim,&internal1_m1795_StSpeed,&internal1_m1795_Vz0,&internal1_m1795_flRazg,&internal1_m1795_DelSp,&internal1_m1795_z0,&internal1_m1795_txZS,&internal1_m1795_tx,&internal1_m1795_txd,&internal1_m1795_txMBl,&internal1_m1795_txBl,&internal1_m1795_Speed0,&internal1_m1795_xz0,&internal1_m1795_tz0,&internal1_m1795_Shift0,&internal1_m1795_ShCntlSp0,&internal1_m1795_ShiftControl,&bFirstEnterFlag};
_S_zpfs  S_zpfs_1263_1 = {&var1738,&fRM_2_0,&var1722,&internal1_m1263_tx,&internal1_m1263_y0};
_S_zpfs  S_zpfs_1267_1 = {&var1737,&fRM_3_0,&var1723,&internal1_m1267_tx,&internal1_m1267_y0};
_S_noto  S_noto_1227_1 = {&R8IS11LDU,&var1724};
_S_orn  S_orn_1209_1 = {array_m1209_x_1,&iRM_8_,&var1725};
_S_noto  S_noto_676_1 = {&var1729,&var1726};
_S_rs  S_rs_697_1 = {&var1011,&var1012,&var1727,&vainSBool,&internal1_m697_q0};
_S_orn  S_orn_664_1 = {array_m664_x_1,&iRM_18_,&var1728};
_S_rs  S_rs_662_1 = {&var1493,&var1127,&var1729,&vainSBool,&internal1_m662_q0};
_S_samhd  S_samhd_1253_1 = {&R0MD34LP1,&var739,&var739,&var1678,&var1679,&var1732,&var1733,&var375,&var375,&var374,&var374,&bRM_3_,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&fEM_B8UL07RDU,&vainSBool,&vainSBool,&var1730,&var1731,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,&internal1_m1253_DvUp0,&internal1_m1253_DvDw0,&internal1_m1253_FDvUp0,&internal1_m1253_FDvDw0,&internal1_m1253_BlDv0,&internal1_m1253_Pkv0,&internal1_m1253_Pkav0,&internal1_m1253_Zkv0,&internal1_m1253_Zkav0,&internal1_m1253_txNm,&internal1_m1253_txSm,&internal1_m1253_txHr,&internal1_m1253_txLd,&internal1_m1253_fef,&bFirstEnterFlag};
_S_fnapb  S_fnapb_1273_1 = {&var1941,&var531,&var1054,&R0MD34LP1,&var1677,&fEM_B8UV03RDU,&fEM_B8UV04RDU,&fEM_B8UV01RDU,&fEM_B8UV02RDU,&fEM_B8UC06RDU,&fEM_B8UC05RDU,&iRM_20_,&fEM_B8UL04RDU,&fEM_B8UL06RDU,&fEM_B8UL03RDU,&var1732,&var1733,&var1734,&var1735,&var1736,&var1737,&var1738,&vainSFloat,&internal1_m1273_xptr,array_m1273_x0_1,array_m1273_tim0_1,&internal1_m1273_sumtim,&internal1_m1273_StSpeed,&internal1_m1273_Vz0,&internal1_m1273_flRazg,&internal1_m1273_DelSp,&internal1_m1273_z0,&internal1_m1273_txZS,&internal1_m1273_tx,&internal1_m1273_txd,&internal1_m1273_txMBl,&internal1_m1273_txBl,&internal1_m1273_Speed0,&internal1_m1273_xz0,&internal1_m1273_tz0,&internal1_m1273_Shift0,&internal1_m1273_ShCntlSp0,&internal1_m1273_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_802_1 = {&A5IS21LDU,&var1739};
_S_vmemb  S_vmemb_825_1 = {&var1741,&var1740,&internal1_m825_x0};
_S_noto  S_noto_833_1 = {&var376,&var1741};
_S_vmemb  S_vmemb_794_1 = {&var1739,&var1742,&internal1_m794_x0};
_S_vmemb  S_vmemb_736_1 = {&var1757,&var1743,&internal1_m736_x0};
_S_newstage  S_newstage_872_1 = {&var1801,&var1792,&var1800,&var1791,&var1744};
_S_newstage  S_newstage_1309_1 = {&var1783,&var1774,&var1782,&var1773,&var1745};
_S_newstage  S_newstage_419_1 = {&var1828,&var1819,&var1827,&var1818,&var1746};
_S_noto  S_noto_844_1 = {&var377,&var1747};
_S_rs  S_rs_850_1 = {&var1075,&var1746,&var1748,&vainSBool,&internal1_m850_q0};
_S_rs  S_rs_845_1 = {&var1076,&var1176,&var1749,&vainSBool,&internal1_m845_q0};
_S_noto  S_noto_837_1 = {&var1830,&var1750};
_S_noto  S_noto_835_1 = {&var1831,&var1751};
_S_rs  S_rs_813_1 = {&var1080,&var1746,&var1752,&vainSBool,&internal1_m813_q0};
_S_rs  S_rs_818_1 = {&var1079,&var1744,&var1753,&vainSBool,&internal1_m818_q0};
_S_rs  S_rs_826_1 = {&var1146,&var1085,&var1754,&vainSBool,&internal1_m826_q0};
_S_rs  S_rs_838_1 = {&var1077,&var1083,&var1755,&vainSBool,&internal1_m838_q0};
_S_noto  S_noto_793_1 = {&var377,&var1756};
_S_noto  S_noto_729_1 = {&var376,&var1757};
_S_noto  S_noto_458_1 = {&R8IS11LDU,&var1758};
_S_orn  S_orn_476_1 = {array_m476_x_1,&iRM_7_,&var1759};
_S_orn  S_orn_454_1 = {array_m454_x_1,&iRM_7_,&var1760};
_S_rs  S_rs_816_1 = {&var1084,&var1089,&var1761,&vainSBool,&internal1_m816_q0};
_S_noto  S_noto_161_1 = {&B2IS12LDU,&var1762};
_S_noto  S_noto_150_1 = {&A2IS12LDU,&var1763};
_S_noto  S_noto_151_1 = {&B1IS12LDU,&var1764};
_S_noto  S_noto_159_1 = {&A1IS12LDU,&var1765};
_S_samhd  S_samhd_1316_1 = {&var1058,&var1059,&var1059,&var1368,&var1367,&var1368,&var1367,&B4IS11LDU,&B4IS11LDU,&B4IS21LDU,&B4IS21LDU,&bRM_1_,&fEM_A4UZ05RDU,&fEM_A4UZ03RDU,&fEM_A4UZ04RDU,&var1766,&var1767,&var1768,&vainSBool,&var1769,&vainSBool,&var1770,&var1771,&var1772,&var1773,&var1774,&internal1_m1316_DvUp0,&internal1_m1316_DvDw0,&internal1_m1316_FDvUp0,&internal1_m1316_FDvDw0,&internal1_m1316_BlDv0,&internal1_m1316_Pkv0,&internal1_m1316_Pkav0,&internal1_m1316_Zkv0,&internal1_m1316_Zkav0,&internal1_m1316_txNm,&internal1_m1316_txSm,&internal1_m1316_txHr,&internal1_m1316_txLd,&internal1_m1316_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_1306_1 = {&var1058,&var1061,&var1061,&var1368,&var1367,&var1368,&var1367,&A4IS11LDU,&A4IS11LDU,&A4IS21LDU,&A4IS21LDU,&bRM_1_,&fEM_A4UZ05RDU,&fEM_A4UZ03RDU,&fEM_A4UZ04RDU,&var1775,&var1776,&var1777,&vainSBool,&var1778,&vainSBool,&var1779,&var1780,&var1781,&var1782,&var1783,&internal1_m1306_DvUp0,&internal1_m1306_DvDw0,&internal1_m1306_FDvUp0,&internal1_m1306_FDvDw0,&internal1_m1306_BlDv0,&internal1_m1306_Pkv0,&internal1_m1306_Pkav0,&internal1_m1306_Zkv0,&internal1_m1306_Zkav0,&internal1_m1306_txNm,&internal1_m1306_txSm,&internal1_m1306_txHr,&internal1_m1306_txLd,&internal1_m1306_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_874_1 = {&R0MD34LP1,&var916,&var916,&var1177,&var1072,&B5VS12LDU,&B5VS22LDU,&B5IS11LDU,&B5IS11LDU,&B5IS21LDU,&B5IS21LDU,&bRM_0_,&fEM_A5UZ05RDU,&fEM_A5UZ03RDU,&fEM_A5UZ04RDU,&var1784,&var1785,&var1786,&var1787,&var1788,&var1789,&vainSBool,&vainSBool,&var1790,&var1791,&var1792,&internal1_m874_DvUp0,&internal1_m874_DvDw0,&internal1_m874_FDvUp0,&internal1_m874_FDvDw0,&internal1_m874_BlDv0,&internal1_m874_Pkv0,&internal1_m874_Pkav0,&internal1_m874_Zkv0,&internal1_m874_Zkav0,&internal1_m874_txNm,&internal1_m874_txSm,&internal1_m874_txHr,&internal1_m874_txLd,&internal1_m874_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_870_1 = {&R0MD34LP1,&var918,&var918,&var1177,&var1072,&A5VS12LDU,&A5VS22LDU,&A5IS11LDU,&A5IS11LDU,&A5IS21LDU,&A5IS21LDU,&bRM_0_,&fEM_A5UZ05RDU,&fEM_A5UZ03RDU,&fEM_A5UZ04RDU,&var1793,&var1794,&var1795,&var1796,&var1797,&var1798,&vainSBool,&vainSBool,&var1799,&var1800,&var1801,&internal1_m870_DvUp0,&internal1_m870_DvDw0,&internal1_m870_FDvUp0,&internal1_m870_FDvDw0,&internal1_m870_BlDv0,&internal1_m870_Pkv0,&internal1_m870_Pkav0,&internal1_m870_Zkv0,&internal1_m870_Zkav0,&internal1_m870_txNm,&internal1_m870_txSm,&internal1_m870_txHr,&internal1_m870_txLd,&internal1_m870_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_385_1 = {&R0MD34LP1,&var600,&var599,&var1081,&var1074,&R4VS12LDU,&R4VS22LDU,&R4IS11LDU,&R4IS12LDU,&R4IS21LDU,&R4IS22LDU,&bRM_0_,&fEM_R4UZ05RDU,&fEM_R4UZ03RDU,&fEM_R4UZ04RDU,&var1802,&var1803,&var1804,&var1805,&var1806,&var1807,&vainSBool,&vainSBool,&var1808,&var1809,&vainSBool,&internal1_m385_DvUp0,&internal1_m385_DvDw0,&internal1_m385_FDvUp0,&internal1_m385_FDvDw0,&internal1_m385_BlDv0,&internal1_m385_Pkv0,&internal1_m385_Pkav0,&internal1_m385_Zkv0,&internal1_m385_Zkav0,&internal1_m385_txNm,&internal1_m385_txSm,&internal1_m385_txHr,&internal1_m385_txLd,&internal1_m385_fef,&bFirstEnterFlag};
_S_noto  S_noto_749_1 = {&R8IS11LDU,&var1810};
_S_samhd  S_samhd_422_1 = {&R0MD34LP1,&var1759,&var1147,&var1153,&var1073,&B6VS12LDU,&B6VS22LDU,&B6IS11LDU,&B6IS11LDU,&B6IS21LDU,&B6IS21LDU,&bRM_0_,&fEM_A6UZ05RDU,&fEM_A6UZ03RDU,&fEM_A6UZ04RDU,&var1811,&var1812,&var1813,&var1814,&var1815,&var1816,&vainSBool,&vainSBool,&var1817,&var1818,&var1819,&internal1_m422_DvUp0,&internal1_m422_DvDw0,&internal1_m422_FDvUp0,&internal1_m422_FDvDw0,&internal1_m422_BlDv0,&internal1_m422_Pkv0,&internal1_m422_Pkav0,&internal1_m422_Zkv0,&internal1_m422_Zkav0,&internal1_m422_txNm,&internal1_m422_txSm,&internal1_m422_txHr,&internal1_m422_txLd,&internal1_m422_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_416_1 = {&R0MD34LP1,&var1760,&var1148,&var1153,&var1073,&A6VS12LDU,&A6VS22LDU,&A6IS11LDU,&A6IS11LDU,&A6IS21LDU,&A6IS21LDU,&bRM_0_,&fEM_A6UZ05RDU,&fEM_A6UZ03RDU,&fEM_A6UZ04RDU,&var1820,&var1821,&var1822,&var1823,&var1824,&var1825,&vainSBool,&vainSBool,&var1826,&var1827,&var1828,&internal1_m416_DvUp0,&internal1_m416_DvDw0,&internal1_m416_FDvUp0,&internal1_m416_FDvDw0,&internal1_m416_BlDv0,&internal1_m416_Pkv0,&internal1_m416_Pkav0,&internal1_m416_Zkv0,&internal1_m416_Zkav0,&internal1_m416_txNm,&internal1_m416_txSm,&internal1_m416_txHr,&internal1_m416_txLd,&internal1_m416_fef,&bFirstEnterFlag};
_S_orn  S_orn_849_1 = {array_m849_x_1,&iRM_17_,&var1829};
_S_rs  S_rs_822_1 = {&var1087,&var286,&var1830,&vainSBool,&internal1_m822_q0};
_S_rs  S_rs_819_1 = {&var1088,&var287,&var1831,&vainSBool,&internal1_m819_q0};
_S_orni  S_orni_139_1 = {array_m139_x_1,&iRM_21_,&var1832,&vainSLong};
_S_equz_p  S_equz_p_79_1 = {&R0MW11IP2,&iRM_6_,&var1833};
_S_equz_p  S_equz_p_76_1 = {&R0MW11IP2,&iRM_5_,&var1834};
_S_equz_p  S_equz_p_74_1 = {&R0MW11IP2,&iRM_4_,&var1835};
_S_equz_p  S_equz_p_70_1 = {&R0MW11IP2,&iRM_3_,&var1836};
_S_equz_p  S_equz_p_69_1 = {&R0MW11IP2,&iRM_2_,&var1837};
_S_equz_p  S_equz_p_66_1 = {&R0MW11IP2,&iRM_1_,&var1838};
_S_equz_p  S_equz_p_62_1 = {&R0MW14IP1,&iRM_3_,&var1839};
_S_equz_p  S_equz_p_55_1 = {&R0MW14IP1,&iRM_1_,&vainSBool};
_S_equz_p  S_equz_p_58_1 = {&R0MW14IP1,&iRM_2_,&var1840};
_S_equz_p  S_equz_p_50_1 = {&R0MW11IP1,&iRM_3_,&var1841};
_S_equz_p  S_equz_p_43_1 = {&R0MW11IP1,&iRM_1_,&var1842};
_S_equz_p  S_equz_p_46_1 = {&R0MW11IP1,&iRM_2_,&var1843};
_S_equz_p  S_equz_p_106_1 = {&R0MW16IP1,&iRM_11_,&var1844};
_S_equz_p  S_equz_p_99_1 = {&R0MW16IP1,&iRM_4_,&var1845};
_S_equz_p  S_equz_p_98_1 = {&R0MW16IP1,&iRM_3_,&var1846};
_S_equz_p  S_equz_p_97_1 = {&R0MW16IP1,&iRM_2_,&var1847};
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
   var14.f=0.0;
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
   var218.b=0;
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
   var232.i=0;
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
   var358.i=0;
   var359.b=0;
   var360.b=0;
   var361.i=0;
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
   var406.f=0.0;
   var407.b=0;
   var408.b=0;
   var409.b=0;
   var410.b=0;
   var411.b=0;
   var412.b=0;
   var413.b=0;
   var414.b=0;
   var415.b=0;
   var416.f=0.0;
   var417.f=0.0;
   var418.b=0;
   var419.b=0;
   var420.b=0;
   var421.f=0.0;
   var422.b=0;
   var423.b=0;
   var424.f=0.0;
   var425.b=0;
   var426.b=0;
   var427.b=0;
   var428.b=0;
   var429.b=0;
   var430.b=0;
   var431.b=0;
   var432.b=0;
   var433.f=0.0;
   var434.f=0.0;
   var435.f=0.0;
   var436.f=0.0;
   var437.b=0;
   var438.f=0.0;
   var439.f=0.0;
   var440.i=0;
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
   var531.f=0.0;
   var532.b=0;
   var533.b=0;
   var534.b=0;
   var535.f=0.0;
   var536.b=0;
   var537.b=0;
   var538.b=0;
   var539.f=0.0;
   var540.b=0;
   var541.b=0;
   var542.b=0;
   var543.f=0.0;
   var544.b=0;
   var545.b=0;
   var546.b=0;
   var547.f=0.0;
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
   var631.b=0;
   var632.b=0;
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
   var643.f=0.0;
   var644.f=0.0;
   var645.b=0;
   var646.b=0;
   var647.f=0.0;
   var648.f=0.0;
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
   var778.l=0L;
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
   var1186.b=0;
   var1187.b=0;
   var1188.f=0.0;
   var1189.b=0;
   var1190.f=0.0;
   var1191.b=0;
   var1192.f=0.0;
   var1193.b=0;
   var1194.b=0;
   var1195.b=0;
   var1196.b=0;
   var1197.f=0.0;
   var1198.f=0.0;
   var1199.f=0.0;
   var1200.f=0.0;
   var1201.f=0.0;
   var1202.f=0.0;
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
   var1258.i=0;
   var1259.i=0;
   var1260.b=0;
   var1261.b=0;
   var1262.b=0;
   var1263.b=0;
   var1264.b=0;
   var1265.b=0;
   var1266.l=0L;
   var1267.b=0;
   var1268.b=0;
   var1269.b=0;
   var1270.i=0;
   var1271.b=0;
   var1272.b=0;
   var1273.b=0;
   var1274.b=0;
   var1275.b=0;
   var1276.b=0;
   var1277.b=0;
   var1278.b=0;
   var1279.b=0;
   var1280.i=0;
   var1281.i=0;
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
   var1319.b=0;
   var1320.b=0;
   var1321.l=0L;
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
   var1338.b=0;
   var1339.b=0;
   var1340.f=0.0;
   var1341.b=0;
   var1342.b=0;
   var1343.b=0;
   var1344.b=0;
   var1345.b=0;
   var1346.f=0.0;
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
   var1358.b=0;
   var1359.b=0;
   var1360.i=0;
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
   var1383.b=0;
   var1384.b=0;
   var1385.f=0.0;
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
  setData(idR0EE02LDU,&var1025);
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
  equz_p(&S_equz_p_97_1);
  equz_p(&S_equz_p_98_1);
  equz_p(&S_equz_p_99_1);
  equz_p(&S_equz_p_106_1);
  equz_p(&S_equz_p_46_1);
  equz_p(&S_equz_p_43_1);
  equz_p(&S_equz_p_50_1);
  equz_p(&S_equz_p_58_1);
  equz_p(&S_equz_p_55_1);
  equz_p(&S_equz_p_62_1);
  equz_p(&S_equz_p_66_1);
  equz_p(&S_equz_p_69_1);
  equz_p(&S_equz_p_70_1);
  equz_p(&S_equz_p_74_1);
  equz_p(&S_equz_p_76_1);
  equz_p(&S_equz_p_79_1);
  noto(&S_noto_151_1);
  noto(&S_noto_150_1);
  noto(&S_noto_161_1);
  noto(&S_noto_835_1);
  noto(&S_noto_802_1);
  noto(&S_noto_1227_1);
  noto(&S_noto_1754_1);
  noto(&S_noto_1410_1);
  noto(&S_noto_954_1);
  noto(&S_noto_232_1);
  noto(&S_noto_598_1);
  noto(&S_noto_1065_1);
  rs(&S_rs_692_1);
  noto(&S_noto_1516_1);
  equz_p(&S_equz_p_32_1);
  equz_p(&S_equz_p_41_1);
  noto(&S_noto_34_1);
  equz_p(&S_equz_p_37_1);
  rs(&S_rs_1661_1);
  noto(&S_noto_1967_1);
  noto(&S_noto_1966_1);
  noto(&S_noto_1972_1);
  noto(&S_noto_1968_1);
  noto(&S_noto_1974_1);
  noto(&S_noto_1945_1);
  noto(&S_noto_1946_1);
  noto(&S_noto_1947_1);
  noto(&S_noto_1948_1);
  noto(&S_noto_1949_1);
  noto(&S_noto_2260_1);
  equz_p(&S_equz_p_100_1);
  equz_p(&S_equz_p_101_1);
  equz_p(&S_equz_p_102_1);
  noto(&S_noto_1032_1);
  equz_p(&S_equz_p_103_1);
  equz_p(&S_equz_p_104_1);
  noto(&S_noto_185_1);
  equz_p(&S_equz_p_105_1);
  noto(&S_noto_12_1);
  equz_p(&S_equz_p_1989_1);
  equz_p(&S_equz_p_1988_1);
  equz_p(&S_equz_p_1990_1);
  equz_p(&S_equz_p_1991_1);
  equz_p(&S_equz_p_1992_1);
  noto(&S_noto_1954_1);
  noto(&S_noto_2006_1);
  noto(&S_noto_2026_1);
  rs(&S_rs_682_1);
  noto(&S_noto_1986_1);
  noto(&S_noto_2012_1);
  noto(&S_noto_1483_1);
  rsun(&S_rsun_1575_1);
  rs(&S_rs_684_1);
  rs(&S_rs_686_1);
  rs(&S_rs_702_1);
  rs(&S_rs_719_1);
  rs(&S_rs_691_1);
  rs(&S_rs_706_1);
  rs(&S_rs_26_1);
  rs(&S_rs_1654_1);
  rs(&S_rs_1610_1);
  kvf(&S_kvf_1623_1);
  rs(&S_rs_2068_1);
  noto(&S_noto_1605_1);
  noto(&S_noto_1645_1);
  noto(&S_noto_1650_1);
  noto(&S_noto_2038_1);
  noto(&S_noto_2063_1);
  noto(&S_noto_2082_1);
  noto(&S_noto_2052_1);
  noto(&S_noto_653_1);
  noto(&S_noto_22_1);
  noto(&S_noto_23_1);
  noto(&S_noto_24_1);
  noto(&S_noto_25_1);
  noto(&S_noto_656_1);
  noto(&S_noto_654_1);
  noto(&S_noto_49_1);
  noto(&S_noto_283_1);
  noto(&S_noto_286_1);
  noto(&S_noto_295_1);
  noto(&S_noto_301_1);
  noto(&S_noto_291_1);
  noto(&S_noto_1109_1);
  noto(&S_noto_1115_1);
  noto(&S_noto_2117_1);
  noto(&S_noto_2119_1);
  rs(&S_rs_1193_1);
  rs(&S_rs_1196_1);
  rs(&S_rs_1199_1);
  rs(&S_rs_1202_1);
  ovbs(&S_ovbs_1314_1);
  ovbs(&S_ovbs_2285_1);
  sr(&S_sr_1186_1);
  bol(&S_bol_1180_1);
  ma(&S_ma_90_1);
  sr(&S_sr_88_1);
  bol(&S_bol_280_1);
  bol(&S_bol_276_1);
  bol(&S_bol_1555_1);
  bol(&S_bol_1553_1);
  bol(&S_bol_1106_1);
  bol(&S_bol_1099_1);
  bol(&S_bol_639_1);
  bol(&S_bol_643_1);
  bol(&S_bol_652_1);
  bol(&S_bol_658_1);
  and2(&S_and2_823_1);
  and2(&S_and2_27_1);
  and2(&S_and2_28_1);
  and2(&S_and2_29_1);
  and2(&S_and2_30_1);
  and2(&S_and2_42_1);
  and2(&S_and2_38_1);
  and2(&S_and2_814_1);
  or4(&S_or4_457_1);
  or2(&S_or2_827_1);
  or3(&S_or3_5_1);
  or2(&S_or2_6_1);
  or2(&S_or2_1426_1);
  or2(&S_or2_970_1);
  or2(&S_or2_249_1);
  or2(&S_or2_615_1);
  or2(&S_or2_1080_1);
  or2(&S_or2_1531_1);
  or2(&S_or2_1185_1);
  and2(&S_and2_1179_1);
  or2(&S_or2_20_1);
  or2(&S_or2_39_1);
  or2(&S_or2_35_1);
  or2(&S_or2_48_1);
  or2(&S_or2_766_1);
  or3(&S_or3_751_1);
  or4(&S_or4_768_1);
  or2(&S_or2_785_1);
  or3(&S_or3_810_1);
  and2(&S_and2_834_1);
  and2(&S_and2_808_1);
  or2(&S_or2_815_1);
  or2(&S_or2_731_1);
  or2(&S_or2_733_1);
  or2(&S_or2_735_1);
  or2(&S_or2_1287_1);
  or2(&S_or2_1315_1);
  and4(&S_and4_1191_1);
  or2(&S_or2_1190_1);
  and2(&S_and2_1205_1);
  or2(&S_or2_1223_1);
  and3(&S_and3_284_1);
  and3(&S_and3_300_1);
  or2(&S_or2_675_1);
  or2(&S_or2_683_1);
  or2(&S_or2_685_1);
  or2(&S_or2_688_1);
  or2(&S_or2_659_1);
  and2(&S_and2_709_1);
  or2(&S_or2_716_1);
  and2(&S_and2_680_1);
  or2(&S_or2_695_1);
  or2(&S_or2_690_1);
  or2(&S_or2_713_1);
  and2(&S_and2_670_1);
  or2(&S_or2_367_1);
  or2(&S_or2_372_1);
  or2(&S_or2_832_1);
  or2(&S_or2_509_1);
  and2(&S_and2_584_1);
  and2(&S_and2_585_1);
  and2(&S_and2_597_1);
  or2(&S_or2_587_1);
  and2(&S_and2_183_1);
  and2(&S_and2_219_1);
  and2(&S_and2_218_1);
  or2(&S_or2_221_1);
  and2(&S_and2_231_1);
  or2(&S_or2_873_1);
  or2(&S_or2_942_1);
  and2(&S_and2_1026_1);
  or2(&S_or2_1037_1);
  or2(&S_or2_1053_1);
  or2(&S_or2_1505_1);
  and2(&S_and2_1476_1);
  or2(&S_or2_1489_1);
  or2(&S_or2_1396_1);
  and2(&S_and2_1114_1);
  and2(&S_and2_1606_1);
  zpfs(&S_zpfs_1616_1);
  and2(&S_and2_1646_1);
  zpfs(&S_zpfs_1666_1);
  and2(&S_and2_1651_1);
  zpfs(&S_zpfs_1672_1);
  and2(&S_and2_1688_1);
  or2(&S_or2_2286_1);
  or2(&S_or2_1809_1);
  or2(&S_or2_1810_1);
  or2(&S_or2_1750_1);
  or2(&S_or2_1952_1);
  or2(&S_or2_1953_1);
  or4(&S_or4_1959_1);
  or4(&S_or4_1960_1);
  or2(&S_or2_1962_1);
  or2(&S_or2_1956_1);
  or2(&S_or2_1955_1);
  or3(&S_or3_1964_1);
  and2(&S_and2_1993_1);
  or2(&S_or2_1994_1);
  and2(&S_and2_2000_1);
  and2(&S_and2_2016_1);
  or2(&S_or2_2027_1);
  zpfs(&S_zpfs_1996_1);
  zpfs(&S_zpfs_1997_1);
  zpfs(&S_zpfs_1998_1);
  zpfs(&S_zpfs_1999_1);
  or2(&S_or2_2002_1);
  and2(&S_and2_2003_1);
  or2(&S_or2_2018_1);
  or3(&S_or3_2004_1);
  or2(&S_or2_2069_1);
  and2(&S_and2_2087_1);
  ma(&S_ma_1641_1);
  lk(&S_lk_1624_1);
  rsfn(&S_rsfn_1620_1);
  abs_subf(&S_abs_subf_1629_1);
  zpfs(&S_zpfs_2045_1);
  and2(&S_and2_2046_1);
  or2(&S_or2_2043_1);
  or2(&S_or2_252_1);
  ovbs(&S_ovbs_82_1);
  ovbs(&S_ovbs_21_1);
  ovbs(&S_ovbs_127_1);
  ovbs(&S_ovbs_120_1);
  ovbs(&S_ovbs_1600_1);
  ovbs(&S_ovbs_830_1);
  ovbs(&S_ovbs_317_1);
  ovbs(&S_ovbs_363_1);
  ovbs(&S_ovbs_51_1);
  or2(&S_or2_2182_1);
  or2(&S_or2_2170_1);
  noto(&S_noto_2201_1);
  bol(&S_bol_1734_1);
  bol(&S_bol_1726_1);
  or2(&S_or2_1728_1);
  bol(&S_bol_1713_1);
  bol(&S_bol_1706_1);
  or2(&S_or2_1708_1);
  bol(&S_bol_1732_1);
  bol(&S_bol_1724_1);
  or2(&S_or2_1731_1);
  bol(&S_bol_1718_1);
  bol(&S_bol_1709_1);
  or2(&S_or2_1715_1);
  and4(&S_and4_45_1);
  abs_subf(&S_abs_subf_1723_1);
  noto(&S_noto_1729_1);
  and2(&S_and2_251_1);
  and2(&S_and2_616_1);
  and2(&S_and2_2441_1);
  rs(&S_rs_2391_1);
  sr(&S_sr_2408_1);
  rs(&S_rs_2385_1);
  zpfs(&S_zpfs_2413_1);
  or2(&S_or2_2399_1);
  abs_subf(&S_abs_subf_2366_1);
  and2(&S_and2_2373_1);
  noto(&S_noto_1005_1);
  or2(&S_or2_2425_1);
  zzfs(&S_zzfs_2374_1);
  noto(&S_noto_2386_1);
  or2(&S_or2_1203_1);
  or2(&S_or2_388_1);
  or2(&S_or2_375_1);
  or2(&S_or2_1243_1);
  or2(&S_or2_1250_1);
  or2(&S_or2_247_1);
  or2(&S_or2_613_1);
  nocnm(&S_nocnm_1903_1);
  nocnm(&S_nocnm_1905_1);
  noto(&S_noto_1861_1);
  noto(&S_noto_1862_1);
  noto(&S_noto_2359_1);
  noto(&S_noto_2328_1);
  or2(&S_or2_1613_1);
  or2(&S_or2_1644_1);
  noto(&S_noto_2361_1);
  noto(&S_noto_2330_1);
  noto(&S_noto_114_1);
  and2(&S_and2_809_1);
  and2(&S_and2_812_1);
  or2(&S_or2_134_1);
  noto(&S_noto_1921_1);
  noto(&S_noto_1922_1);
  or2(&S_or2_1885_1);
  or2(&S_or2_1925_1);
  or2(&S_or2_1928_1);
  or2(&S_or2_1896_1);
  or2(&S_or2_1899_1);
  or2(&S_or2_1858_1);
  or2(&S_or2_1832_1);
  or2(&S_or2_1828_1);
  or2(&S_or2_2354_1);
  or2(&S_or2_2358_1);
  or2(&S_or2_2356_1);
  or2(&S_or2_2323_1);
  or2(&S_or2_2325_1);
  or2(&S_or2_2327_1);
  or2(&S_or2_1850_1);
  or2(&S_or2_1883_1);
  and2(&S_and2_2495_1);
  or2(&S_or2_2504_1);
  or2(&S_or2_2511_1);
  orn(&S_orn_2506_1);
  ovbsb(&S_ovbsb_224_1);
  ovbsb(&S_ovbsb_225_1);
  ovbsb(&S_ovbsb_236_1);
  ovbsb(&S_ovbsb_250_1);
  ovbsb(&S_ovbsb_592_1);
  ovbsb(&S_ovbsb_589_1);
  ovbsb(&S_ovbsb_602_1);
  ovbsb(&S_ovbsb_624_1);
  ovbsb(&S_ovbsb_2435_1);
  ovbsb(&S_ovbsb_390_1);
  or2(&S_or2_2056_1);
  and2(&S_and2_1577_1);
  and2(&S_and2_1598_1);
  and2(&S_and2_1582_1);
  and2(&S_and2_1591_1);
  and2(&S_and2_1586_1);
  noto(&S_noto_56_1);
  noto(&S_noto_749_1);
  noto(&S_noto_159_1);
  rs(&S_rs_816_1);
  noto(&S_noto_458_1);
  noto(&S_noto_729_1);
  noto(&S_noto_793_1);
  rs(&S_rs_826_1);
  noto(&S_noto_844_1);
  vmemb(&S_vmemb_736_1);
  vmemb(&S_vmemb_794_1);
  noto(&S_noto_833_1);
  vmemb(&S_vmemb_825_1);
  rs(&S_rs_697_1);
  rs(&S_rs_707_1);
  rs(&S_rs_687_1);
  noto(&S_noto_674_1);
  rs(&S_rs_715_1);
  noto(&S_noto_282_1);
  noto(&S_noto_710_1);
  noto(&S_noto_645_1);
  noto(&S_noto_1105_1);
  noto(&S_noto_1557_1);
  noto(&S_noto_1128_1);
  noto(&S_noto_2094_1);
  kvf(&S_kvf_2050_1);
  kvf(&S_kvf_1664_1);
  noto(&S_noto_83_1);
  samhd(&S_samhd_2284_1);
  samhd(&S_samhd_2290_1);
  newstage(&S_newstage_2288_1);
  noto(&S_noto_1965_1);
  noto(&S_noto_1971_1);
  noto(&S_noto_1973_1);
  noto(&S_noto_1944_1);
  noto(&S_noto_2080_1);
  noto(&S_noto_2072_1);
  noto(&S_noto_558_1);
  noto(&S_noto_1354_1);
  noto(&S_noto_1373_1);
  noto(&S_noto_2014_1);
  rs(&S_rs_1675_1);
  kvf(&S_kvf_1670_1);
  rs(&S_rs_1669_1);
  rs(&S_rs_1619_1);
  noto(&S_noto_1680_1);
  noto(&S_noto_1678_1);
  noto(&S_noto_1622_1);
  rs(&S_rs_831_1);
  noto(&S_noto_369_1);
  noto(&S_noto_365_1);
  noto(&S_noto_655_1);
  noto(&S_noto_665_1);
  noto(&S_noto_718_1);
  noto(&S_noto_2101_1);
  noto(&S_noto_2126_1);
  swtakt(&S_swtakt_52_1);
  rs(&S_rs_1195_1);
  and2(&S_and2_841_1);
  and2(&S_and2_11_1);
  and2(&S_and2_119_1);
  and2(&S_and2_246_1);
  and2(&S_and2_612_1);
  or2(&S_or2_14_1);
  or2(&S_or2_8_1);
  or2(&S_or2_173_1);
  and3(&S_and3_783_1);
  and2(&S_and2_745_1);
  or3(&S_or3_821_1);
  and2(&S_and2_817_1);
  and2(&S_and2_725_1);
  or2(&S_or2_290_1);
  and3(&S_and3_306_1);
  or2(&S_or2_708_1);
  and2(&S_and2_677_1);
  and2(&S_and2_667_1);
  and4(&S_and4_668_1);
  and4(&S_and4_678_1);
  and2(&S_and2_703_1);
  or2(&S_or2_711_1);
  or2(&S_or2_714_1);
  and3(&S_and3_360_1);
  and2(&S_and2_553_1);
  or2(&S_or2_560_1);
  and2(&S_and2_625_1);
  and2(&S_and2_640_1);
  or2(&S_or2_189_1);
  and2(&S_and2_262_1);
  and2(&S_and2_277_1);
  and2(&S_and2_1100_1);
  and2(&S_and2_1532_1);
  and2(&S_and2_1554_1);
  and2(&S_and2_1352_1);
  or2(&S_or2_1358_1);
  and2(&S_and2_1365_1);
  or2(&S_or2_1377_1);
  and2(&S_and2_1123_1);
  and2(&S_and2_1133_1);
  or2(&S_or2_1614_1);
  or2(&S_or2_1657_1);
  and3(&S_and3_1633_1);
  and2(&S_and2_1617_1);
  and2(&S_and2_1667_1);
  or3(&S_or3_1685_1);
  or2(&S_or2_1663_1);
  and2(&S_and2_1673_1);
  or3(&S_or3_1674_1);
  or3(&S_or3_1687_1);
  or3(&S_or3_2283_1);
  or3(&S_or3_2292_1);
  or2(&S_or2_1961_1);
  or3(&S_or3_1963_1);
  or2(&S_or2_2001_1);
  and2(&S_and2_2009_1);
  or3(&S_or3_2008_1);
  and2(&S_and2_2031_1);
  or2(&S_or2_2229_1);
  or2(&S_or2_2154_1);
  or2(&S_or2_2142_1);
  and2(&S_and2_2122_1);
  and2(&S_and2_2120_1);
  and2(&S_and2_2105_1);
  and2(&S_and2_2104_1);
  and2(&S_and2_2074_1);
  and4(&S_and4_2075_1);
  and4(&S_and4_2081_1);
  or2(&S_or2_2083_1);
  or2(&S_or2_2085_1);
  or2(&S_or2_2084_1);
  zpfs(&S_zpfs_2088_1);
  zpfs(&S_zpfs_2091_1);
  zpfs(&S_zpfs_2076_1);
  and2(&S_and2_2077_1);
  or3(&S_or3_2092_1);
  lk(&S_lk_1665_1);
  rsfn(&S_rsfn_1656_1);
  abs_subf(&S_abs_subf_1676_1);
  lk(&S_lk_1662_1);
  rsfn(&S_rsfn_1659_1);
  abs_subf(&S_abs_subf_1671_1);
  lk(&S_lk_2057_1);
  rsfn(&S_rsfn_2059_1);
  abs_subf(&S_abs_subf_2060_1);
  and2(&S_and2_2053_1);
  and3(&S_and3_2054_1);
  and2(&S_and2_1081_1);
  or2(&S_or2_273_1);
  ovbs(&S_ovbs_13_1);
  or2(&S_or2_1655_1);
  noto(&S_noto_110_1);
  bol(&S_bol_1716_1);
  bol(&S_bol_1705_1);
  or2(&S_or2_1711_1);
  ml(&S_ml_1720_1);
  ml(&S_ml_1700_1);
  ml(&S_ml_1722_1);
  ml(&S_ml_1704_1);
  and2(&S_and2_125_1);
  noto(&S_noto_123_1);
  and2(&S_and2_129_1);
  and2(&S_and2_128_1);
  noto(&S_noto_194_1);
  noto(&S_noto_513_1);
  noto(&S_noto_1020_1);
  noto(&S_noto_1310_1);
  noto(&S_noto_1366_1);
  bol(&S_bol_1979_1);
  and3(&S_and3_1970_1);
  bol(&S_bol_1943_1);
  and3(&S_and3_1951_1);
  noto(&S_noto_1958_1);
  noto(&S_noto_1969_1);
  bol(&S_bol_1013_1);
  bol(&S_bol_1466_1);
  abs_subf(&S_abs_subf_1702_1);
  noto(&S_noto_1714_1);
  abs_subf(&S_abs_subf_1725_1);
  noto(&S_noto_1733_1);
  noto(&S_noto_2402_1);
  fsumo(&S_fsumo_86_1);
  abs_subf(&S_abs_subf_2438_1);
  and2(&S_and2_2443_1);
  and3(&S_and3_2392_1);
  and2(&S_and2_2414_1);
  ovbs(&S_ovbs_2415_1);
  inf(&S_inf_2396_1);
  noto(&S_noto_2424_1);
  noto(&S_noto_1467_1);
  or2(&S_or2_1194_1);
  and2(&S_and2_2230_1);
  and2(&S_and2_112_1);
  and3(&S_and3_1568_1);
  noto(&S_noto_2360_1);
  noto(&S_noto_2329_1);
  diagndev(&S_diagndev_2488_1);
  or3(&S_or3_2507_1);
  ovbsb(&S_ovbsb_268_1);
  ovbsb(&S_ovbsb_253_1);
  ovbsb(&S_ovbsb_1082_1);
  ovbsb(&S_ovbsb_2280_1);
  ovbsb(&S_ovbsb_2279_1);
  ovbsb(&S_ovbsb_2278_1);
  ovbsb(&S_ovbsb_633_1);
  ovbsb(&S_ovbsb_617_1);
  ovbsb(&S_ovbsb_1533_1);
  ovbsb(&S_ovbsb_2293_1);
  ovbsb(&S_ovbsb_2294_1);
  ovbsb(&S_ovbsb_2295_1);
  ovbsb(&S_ovbsb_2436_1);
  ovbsb(&S_ovbsb_737_1);
  ovbsb(&S_ovbsb_780_1);
  ovbsb(&S_ovbsb_2034_1);
  period(&S_period_78_1);
  rs(&S_rs_822_1);
  noto(&S_noto_837_1);
  noto(&S_noto_1397_1);
  noto(&S_noto_940_1);
  noto(&S_noto_222_1);
  rs(&S_rs_689_1);
  noto(&S_noto_588_1);
  noto(&S_noto_1054_1);
  noto(&S_noto_1503_1);
  kvf(&S_kvf_2090_1);
  orni(&S_orni_1576_1);
  andn(&S_andn_1957_1);
  rs(&S_rs_19_1);
  noto(&S_noto_147_1);
  noto(&S_noto_2015_1);
  noto(&S_noto_118_1);
  noto(&S_noto_1559_1);
  rs(&S_rs_1636_1);
  rs(&S_rs_2055_1);
  abs_subf(&S_abs_subf_1134_1);
  abs_subf(&S_abs_subf_1121_1);
  noto(&S_noto_1142_1);
  bol(&S_bol_1155_1);
  bol(&S_bol_1156_1);
  noto(&S_noto_1118_1);
  bol(&S_bol_1158_1);
  bol(&S_bol_1159_1);
  bol(&S_bol_87_1);
  and2(&S_and2_31_1);
  and2(&S_and2_152_1);
  and2(&S_and2_160_1);
  and2(&S_and2_157_1);
  and2(&S_and2_149_1);
  and3(&S_and3_248_1);
  and3(&S_and3_614_1);
  and3(&S_and3_1112_1);
  or3(&S_or3_115_1);
  or2(&S_or2_738_1);
  and2(&S_and2_748_1);
  and2(&S_and2_750_1);
  and2(&S_and2_765_1);
  and2(&S_and2_767_1);
  and2(&S_and2_784_1);
  and2(&S_and2_787_1);
  and3(&S_and3_786_1);
  and2(&S_and2_788_1);
  or2(&S_or2_828_1);
  and2(&S_and2_836_1);
  or2(&S_or2_842_1);
  or2(&S_or2_846_1);
  and3(&S_and3_843_1);
  and2(&S_and2_848_1);
  and2(&S_and2_852_1);
  and2(&S_and2_721_1);
  or2(&S_or2_722_1);
  and2(&S_and2_732_1);
  and2(&S_and2_734_1);
  and2(&S_and2_701_1);
  and2(&S_and2_679_1);
  and2(&S_and2_669_1);
  and3(&S_and3_586_1);
  or2(&S_or2_636_1);
  and3(&S_and3_220_1);
  and3(&S_and3_264_1);
  and3(&S_and3_951_1);
  and3(&S_and3_952_1);
  or2(&S_or2_1096_1);
  or2(&S_or2_1547_1);
  and3(&S_and3_1402_1);
  and3(&S_and3_1403_1);
  or2(&S_or2_1160_1);
  or2(&S_or2_1172_1);
  or2(&S_or2_1170_1);
  or2(&S_or2_1169_1);
  or2(&S_or2_1168_1);
  and2(&S_and2_1571_1);
  or3(&S_or3_1618_1);
  or3(&S_or3_1626_1);
  and2(&S_and2_1627_1);
  and3(&S_and3_1682_1);
  or3(&S_or3_1668_1);
  and2(&S_and2_1686_1);
  and3(&S_and3_1683_1);
  zpfs(&S_zpfs_2231_1);
  and3(&S_and3_2114_1);
  and2(&S_and2_2109_1);
  or3(&S_or3_2115_1);
  and4(&S_and4_2095_1);
  and4(&S_and4_2097_1);
  lk(&S_lk_2093_1);
  rsfn(&S_rsfn_2098_1);
  abs_subf(&S_abs_subf_2100_1);
  and3(&S_and3_2103_1);
  or5(&S_or5_155_1);
  and2(&S_and2_2032_1);
  and2(&S_and2_113_1);
  and2(&S_and2_109_1);
  ml(&S_ml_1698_1);
  zpfs(&S_zpfs_829_1);
  and2(&S_and2_1934_1);
  and2(&S_and2_1911_1);
  and2(&S_and2_1932_1);
  and2(&S_and2_1935_1);
  and2(&S_and2_1912_1);
  and2(&S_and2_1933_1);
  and2(&S_and2_1913_1);
  and2(&S_and2_1914_1);
  and2(&S_and2_1916_1);
  and2(&S_and2_1917_1);
  and2(&S_and2_1919_1);
  and2(&S_and2_1920_1);
  and2(&S_and2_1887_1);
  and2(&S_and2_1888_1);
  rs(&S_rs_1889_1);
  and2(&S_and2_1890_1);
  and2(&S_and2_1891_1);
  rs(&S_rs_1892_1);
  and2(&S_and2_1870_1);
  and2(&S_and2_1874_1);
  and2(&S_and2_1837_1);
  and2(&S_and2_1839_1);
  and2(&S_and2_1841_1);
  and2(&S_and2_1843_1);
  and2(&S_and2_1811_1);
  and2(&S_and2_1812_1);
  and2(&S_and2_1813_1);
  and2(&S_and2_1814_1);
  and2(&S_and2_1815_1);
  and2(&S_and2_1816_1);
  and2(&S_and2_1817_1);
  and2(&S_and2_1818_1);
  and2(&S_and2_124_1);
  abs_subf(&S_abs_subf_1701_1);
  noto(&S_noto_1712_1);
  bol(&S_bol_2430_1);
  and2(&S_and2_2439_1);
  ovbs(&S_ovbs_2393_1);
  and2(&S_and2_2445_1);
  or3(&S_or3_2423_1);
  noto(&S_noto_2370_1);
  noto(&S_noto_2371_1);
  and2(&S_and2_2339_1);
  or4(&S_or4_997_1);
  and2(&S_and2_2308_1);
  or4(&S_or4_1453_1);
  and4(&S_and4_1063_1);
  and4(&S_and4_1514_1);
  or3(&S_or3_1924_1);
  or3(&S_or3_1895_1);
  or3(&S_or3_1898_1);
  or3(&S_or3_1927_1);
  or3(&S_or3_1879_1);
  or3(&S_or3_1881_1);
  or3(&S_or3_1830_1);
  or3(&S_or3_1826_1);
  or3(&S_or3_2346_1);
  or3(&S_or3_2315_1);
  or3(&S_or3_2348_1);
  or3(&S_or3_2350_1);
  or3(&S_or3_2319_1);
  or3(&S_or3_2317_1);
  or2(&S_or2_1856_1);
  or2(&S_or2_1823_1);
  or2(&S_or2_2352_1);
  and2(&S_and2_2336_1);
  or2(&S_or2_2321_1);
  and2(&S_and2_2306_1);
  or2(&S_or2_1848_1);
  or2(&S_or2_1820_1);
  or2(&S_or2_1877_1);
  and2(&S_and2_1873_1);
  ovbsb(&S_ovbsb_227_1);
  ovbsb(&S_ovbsb_257_1);
  ovbsb(&S_ovbsb_265_1);
  ovbsb(&S_ovbsb_590_1);
  ovbsb(&S_ovbsb_621_1);
  ovbsb(&S_ovbsb_108_1);
  ovbsb(&S_ovbsb_2433_1);
  ovbsb(&S_ovbsb_2437_1);
  ovbsb(&S_ovbsb_770_1);
  ovbsb(&S_ovbsb_764_1);
  ovbsb(&S_ovbsb_756_1);
  ovbsb(&S_ovbsb_789_1);
  ovbsb(&S_ovbsb_772_1);
  ovbsb(&S_ovbsb_741_1);
  ovbsb(&S_ovbsb_746_1);
  ovbsb(&S_ovbsb_791_1);
  ovbsb(&S_ovbsb_792_1);
  ovbsb(&S_ovbsb_790_1);
  ovbsb(&S_ovbsb_2035_1);
  samhd(&S_samhd_416_1);
  samhd(&S_samhd_422_1);
  samhd(&S_samhd_870_1);
  samhd(&S_samhd_874_1);
  rs(&S_rs_838_1);
  rs(&S_rs_845_1);
  newstage(&S_newstage_419_1);
  newstage(&S_newstage_872_1);
  orn(&S_orn_153_1);
  rs(&S_rs_1819_1);
  rs(&S_rs_1821_1);
  rs(&S_rs_1822_1);
  rs(&S_rs_1824_1);
  rs(&S_rs_1825_1);
  rs(&S_rs_1827_1);
  rs(&S_rs_1829_1);
  rs(&S_rs_1831_1);
  rs(&S_rs_1849_1);
  rs(&S_rs_1857_1);
  rs(&S_rs_1876_1);
  rs(&S_rs_1884_1);
  rs(&S_rs_1894_1);
  rs(&S_rs_2353_1);
  rs(&S_rs_1923_1);
  rs(&S_rs_1915_1);
  rs(&S_rs_1926_1);
  rs(&S_rs_1918_1);
  rs(&S_rs_1929_1);
  ma(&S_ma_1625_1);
  rs(&S_rs_1867_1);
  rs(&S_rs_1868_1);
  rs(&S_rs_1869_1);
  rs(&S_rs_1833_1);
  rs(&S_rs_1834_1);
  rs(&S_rs_1835_1);
  rs(&S_rs_1836_1);
  rs(&S_rs_116_1);
  noto(&S_noto_117_1);
  rs(&S_rs_1690_1);
  rs(&S_rs_1689_1);
  rs(&S_rs_2108_1);
  provsbr(&S_provsbr_1573_1);
  rs(&S_rs_1572_1);
  andn(&S_andn_289_1);
  noto(&S_noto_307_1);
  and2(&S_and2_447_1);
  and2(&S_and2_459_1);
  and2(&S_and2_468_1);
  and2(&S_and2_470_1);
  and2(&S_and2_472_1);
  or3(&S_or3_412_1);
  or3(&S_or3_428_1);
  and2(&S_and2_448_1);
  and3(&S_and3_657_1);
  or2(&S_or2_154_1);
  and2(&S_and2_753_1);
  and2(&S_and2_824_1);
  or2(&S_or2_851_1);
  and2(&S_and2_728_1);
  or2(&S_or2_297_1);
  and3(&S_and3_298_1);
  or2(&S_or2_483_1);
  and3(&S_and3_492_1);
  or2(&S_or2_544_1);
  and2(&S_and2_562_1);
  and3(&S_and3_627_1);
  and3(&S_and3_626_1);
  and2(&S_and2_190_1);
  and3(&S_and3_263_1);
  or4(&S_or4_866_1);
  or4(&S_or4_881_1);
  or3(&S_or3_941_1);
  and2(&S_and2_938_1);
  and3(&S_and3_939_1);
  and2(&S_and2_937_1);
  and2(&S_and2_953_1);
  and2(&S_and2_975_1);
  and3(&S_and3_976_1);
  and2(&S_and2_1042_1);
  or2(&S_or2_1052_1);
  and2(&S_and2_1064_1);
  and2(&S_and2_1086_1);
  and3(&S_and3_1087_1);
  and3(&S_and3_1088_1);
  or2(&S_or2_1504_1);
  and2(&S_and2_1515_1);
  and2(&S_and2_1537_1);
  and3(&S_and3_1538_1);
  and3(&S_and3_1539_1);
  and2(&S_and2_1490_1);
  or3(&S_or3_1398_1);
  and3(&S_and3_1395_1);
  and2(&S_and2_1394_1);
  and2(&S_and2_1393_1);
  and2(&S_and2_1409_1);
  and2(&S_and2_1424_1);
  and3(&S_and3_1425_1);
  and2(&S_and2_1431_1);
  and3(&S_and3_1432_1);
  and2(&S_and2_1362_1);
  and2(&S_and2_1382_1);
  and2(&S_and2_1173_1);
  and2(&S_and2_1176_1);
  and2(&S_and2_1580_1);
  and2(&S_and2_1584_1);
  and2(&S_and2_1588_1);
  and2(&S_and2_1596_1);
  or2(&S_or2_1581_1);
  or2(&S_or2_1585_1);
  or2(&S_or2_1589_1);
  or2(&S_or2_1597_1);
  or2(&S_or2_1930_1);
  or2(&S_or2_2258_1);
  ovbs(&S_ovbs_2251_1);
  ovbs(&S_ovbs_122_1);
  and2(&S_and2_522_1);
  and2(&S_and2_484_1);
  and2(&S_and2_481_1);
  rs(&S_rs_1931_1);
  rs(&S_rs_1897_1);
  and2(&S_and2_1871_1);
  and2(&S_and2_1872_1);
  and2(&S_and2_1875_1);
  and2(&S_and2_1840_1);
  and2(&S_and2_1844_1);
  noto(&S_noto_2422_1);
  zpfs(&S_zpfs_2378_1);
  zpfs(&S_zpfs_2379_1);
  and2(&S_and2_2244_1);
  and3(&S_and3_449_1);
  and2(&S_and2_2243_1);
  rs(&S_rs_2345_1);
  rs(&S_rs_2333_1);
  rs(&S_rs_2337_1);
  and2(&S_and2_2343_1);
  rs(&S_rs_2355_1);
  rs(&S_rs_2338_1);
  and2(&S_and2_2344_1);
  rs(&S_rs_2357_1);
  rs(&S_rs_2322_1);
  rs(&S_rs_2314_1);
  rs(&S_rs_2302_1);
  rs(&S_rs_2305_1);
  and2(&S_and2_2312_1);
  rs(&S_rs_2324_1);
  rs(&S_rs_2307_1);
  and2(&S_and2_2313_1);
  rs(&S_rs_2326_1);
  regch(&S_regch_132_1);
  rs(&S_rs_1882_1);
  ovbsb(&S_ovbsb_269_1);
  ovbsb(&S_ovbsb_1405_1);
  ovbsb(&S_ovbsb_1399_1);
  ovbsb(&S_ovbsb_1401_1);
  ovbsb(&S_ovbsb_1435_1);
  ovbsb(&S_ovbsb_1414_1);
  ovbsb(&S_ovbsb_1436_1);
  ovbsb(&S_ovbsb_1429_1);
  ovbsb(&S_ovbsb_1428_1);
  ovbsb(&S_ovbsb_1091_1);
  ovbsb(&S_ovbsb_1069_1);
  ovbsb(&S_ovbsb_1092_1);
  ovbsb(&S_ovbsb_2238_1);
  ovbsb(&S_ovbsb_1093_1);
  ovbsb(&S_ovbsb_2239_1);
  ovbsb(&S_ovbsb_859_1);
  ovbsb(&S_ovbsb_860_1);
  ovbsb(&S_ovbsb_861_1);
  ovbsb(&S_ovbsb_865_1);
  ovbsb(&S_ovbsb_405_1);
  ovbsb(&S_ovbsb_406_1);
  ovbsb(&S_ovbsb_407_1);
  ovbsb(&S_ovbsb_410_1);
  ovbsb(&S_ovbsb_460_1);
  ovbsb(&S_ovbsb_444_1);
  ovbsb(&S_ovbsb_443_1);
  ovbsb(&S_ovbsb_452_1);
  ovbsb(&S_ovbsb_630_1);
  ovbsb(&S_ovbsb_632_1);
  ovbsb(&S_ovbsb_944_1);
  ovbsb(&S_ovbsb_947_1);
  ovbsb(&S_ovbsb_946_1);
  ovbsb(&S_ovbsb_979_1);
  ovbsb(&S_ovbsb_958_1);
  ovbsb(&S_ovbsb_980_1);
  ovbsb(&S_ovbsb_1542_1);
  ovbsb(&S_ovbsb_1520_1);
  ovbsb(&S_ovbsb_1543_1);
  ovbsb(&S_ovbsb_1544_1);
  ovbsb(&S_ovbsb_882_1);
  ovbsb(&S_ovbsb_886_1);
  ovbsb(&S_ovbsb_887_1);
  ovbsb(&S_ovbsb_888_1);
  ovbsb(&S_ovbsb_426_1);
  ovbsb(&S_ovbsb_433_1);
  ovbsb(&S_ovbsb_432_1);
  ovbsb(&S_ovbsb_434_1);
  ovbsb(&S_ovbsb_480_1);
  ovbsb(&S_ovbsb_471_1);
  ovbsb(&S_ovbsb_469_1);
  ovbsb(&S_ovbsb_475_1);
  ovbsb(&S_ovbsb_762_1);
  ovbsb(&S_ovbsb_730_1);
  and2(&S_and2_1602_1);
  or2(&S_or2_1578_1);
  or2(&S_or2_1583_1);
  or2(&S_or2_1587_1);
  or2(&S_or2_1592_1);
  or2(&S_or2_1599_1);
  rs(&S_rs_818_1);
  rs(&S_rs_850_1);
  rs(&S_rs_662_1);
  noto(&S_noto_676_1);
  noto(&S_noto_2252_1);
  rs(&S_rs_1851_1);
  rs(&S_rs_1859_1);
  rs(&S_rs_1878_1);
  rs(&S_rs_1880_1);
  rs(&S_rs_1886_1);
  rs(&S_rs_672_1);
  noto(&S_noto_1108_1);
  noto(&S_noto_299_1);
  noto(&S_noto_1171_1);
  noto(&S_noto_1165_1);
  noto(&S_noto_1138_1);
  and2(&S_and2_451_1);
  and2(&S_and2_474_1);
  and2(&S_and2_968_1);
  and3(&S_and3_969_1);
  and3(&S_and3_1079_1);
  and3(&S_and3_1530_1);
  and2(&S_and2_696_1);
  and2(&S_and2_1049_1);
  and2(&S_and2_1050_1);
  and3(&S_and3_1051_1);
  and2(&S_and2_1500_1);
  and2(&S_and2_1501_1);
  and3(&S_and3_1502_1);
  and5(&S_and5_1113_1);
  and2(&S_and2_1161_1);
  or4(&S_or4_1120_1);
  or2(&S_or2_1603_1);
  orni(&S_orni_1593_1);
  or2(&S_or2_2019_1);
  and2(&S_and2_2022_1);
  and2(&S_and2_2269_1);
  ovbs(&S_ovbs_2253_1);
  noto(&S_noto_2383_1);
  noto(&S_noto_2384_1);
  andn(&S_andn_660_1);
  andn(&S_andn_661_1);
  and2(&S_and2_2272_1);
  or5(&S_or5_2270_1);
  and2(&S_and2_2340_1);
  or3(&S_or3_1344_1);
  rs(&S_rs_2347_1);
  rs(&S_rs_2334_1);
  and2(&S_and2_2309_1);
  rs(&S_rs_2316_1);
  rs(&S_rs_2303_1);
  or3(&S_or3_905_1);
  or2(&S_or2_135_1);
  ovbsb(&S_ovbsb_1056_1);
  ovbsb(&S_ovbsb_1057_1);
  ovbsb(&S_ovbsb_1059_1);
  ovbsb(&S_ovbsb_1084_1);
  ovbsb(&S_ovbsb_446_1);
  ovbsb(&S_ovbsb_972_1);
  ovbsb(&S_ovbsb_974_1);
  ovbsb(&S_ovbsb_1507_1);
  ovbsb(&S_ovbsb_1510_1);
  ovbsb(&S_ovbsb_1508_1);
  ovbsb(&S_ovbsb_1535_1);
  ovbsb(&S_ovbsb_473_1);
  ovbsb(&S_ovbsb_1144_1);
  rs(&S_rs_1119_1);
  noto(&S_noto_2254_1);
  rs(&S_rs_2259_1);
  cntch(&S_cntch_1590_1);
  noto(&S_noto_1139_1);
  and2(&S_and2_599_1);
  and2(&S_and2_233_1);
  and2(&S_and2_955_1);
  and2(&S_and2_1066_1);
  and2(&S_and2_1517_1);
  and2(&S_and2_1411_1);
  and3(&S_and3_1125_1);
  and3(&S_and3_1131_1);
  and2(&S_and2_1143_1);
  and2(&S_and2_1136_1);
  and3(&S_and3_1183_1);
  and2(&S_and2_1594_1);
  or2(&S_or2_2017_1);
  noto(&S_noto_2390_1);
  and2(&S_and2_2341_1);
  and2(&S_and2_2310_1);
  rs(&S_rs_2335_1);
  and2(&S_and2_2342_1);
  rs(&S_rs_2351_1);
  rs(&S_rs_2304_1);
  ovbsb(&S_ovbsb_240_1);
  ovbsb(&S_ovbsb_1418_1);
  ovbsb(&S_ovbsb_1073_1);
  ovbsb(&S_ovbsb_606_1);
  ovbsb(&S_ovbsb_959_1);
  ovbsb(&S_ovbsb_1523_1);
  rs(&S_rs_2349_1);
  newstage(&S_newstage_2010_1);
  rs(&S_rs_1145_1);
  rs(&S_rs_1177_1);
  rs(&S_rs_1151_1);
  noto(&S_noto_1152_1);
  or3(&S_or3_163_1);
  or3(&S_or3_534_1);
  or2(&S_or2_1174_1);
  or2(&S_or2_1766_1);
  andn(&S_andn_2398_1);
  noto(&S_noto_2420_1);
  and2(&S_and2_2421_1);
  or2(&S_or2_2419_1);
  and3(&S_and3_2376_1);
  rs(&S_rs_2318_1);
  and2(&S_and2_2311_1);
  rs(&S_rs_2320_1);
  or3(&S_or3_2226_1);
  ovbsb(&S_ovbsb_2149_1);
  cnshd(&S_cnshd_1773_1);
  noto(&S_noto_961_1);
  ornc(&S_ornc_172_1);
  charint(&S_charint_164_1);
  noto(&S_noto_244_1);
  ornc(&S_ornc_542_1);
  charint(&S_charint_536_1);
  noto(&S_noto_610_1);
  noto(&S_noto_1076_1);
  noto(&S_noto_1526_1);
  rs(&S_rs_1162_1);
  or2(&S_or2_1794_1);
  and2(&S_and2_1736_1);
  and2(&S_and2_1737_1);
  and2(&S_and2_1738_1);
  and2(&S_and2_1739_1);
  and2(&S_and2_1749_1);
  and2(&S_and2_1751_1);
  and2(&S_and2_1753_1);
  or2(&S_or2_2263_1);
  and2(&S_and2_1150_1);
  rs(&S_rs_2418_1);
  and2(&S_and2_2257_1);
  and2(&S_and2_2268_1);
  ovbsb(&S_ovbsb_1763_1);
  ovbsb(&S_ovbsb_1741_1);
  ovbsb(&S_ovbsb_1742_1);
  ovbsb(&S_ovbsb_1744_1);
  ovbsb(&S_ovbsb_1746_1);
  ovbsb(&S_ovbsb_1755_1);
  ovbsb(&S_ovbsb_1760_1);
  ovbsb(&S_ovbsb_2250_1);
  ovbsb(&S_ovbsb_2267_1);
  fnapb(&S_fnapb_1795_1);
  samhd(&S_samhd_1776_1);
  zpfs(&S_zpfs_1791_1);
  zpfs(&S_zpfs_1787_1);
  noto(&S_noto_1422_1);
  fsumz(&S_fsumz_165_1);
  fsumz(&S_fsumz_537_1);
  orni(&S_orni_1301_1);
  rs(&S_rs_1147_1);
  rs(&S_rs_1148_1);
  ma(&S_ma_170_1);
  ma(&S_ma_543_1);
  zpfs(&S_zpfs_1801_1);
  or2(&S_or2_1245_1);
  or3(&S_or3_1146_1);
  or3(&S_or3_1784_1);
  or5(&S_or5_2271_1);
  ovbsb(&S_ovbsb_1777_1);
  ovbsb(&S_ovbsb_1788_1);
  ovbsb(&S_ovbsb_1798_1);
  ovbsb(&S_ovbsb_1797_1);
  ovbsb(&S_ovbsb_1790_1);
  ovbsb(&S_ovbsb_1782_1);
  samhd(&S_samhd_1306_1);
  samhd(&S_samhd_1316_1);
  newstage(&S_newstage_1309_1);
  cnshd(&S_cnshd_1246_1);
  noto(&S_noto_1421_1);
  noto(&S_noto_960_1);
  cnshd(&S_cnshd_175_1);
  noto(&S_noto_243_1);
  cnshd(&S_cnshd_545_1);
  noto(&S_noto_609_1);
  noto(&S_noto_1075_1);
  noto(&S_noto_1525_1);
  rs(&S_rs_2264_1);
  or2(&S_or2_1305_1);
  or2(&S_or2_1319_1);
  or2(&S_or2_1272_1);
  and2(&S_and2_1213_1);
  and2(&S_and2_1210_1);
  and2(&S_and2_1211_1);
  and2(&S_and2_1212_1);
  and2(&S_and2_1222_1);
  and2(&S_and2_1224_1);
  and2(&S_and2_1226_1);
  and2(&S_and2_698_1);
  or2(&S_or2_567_1);
  or2(&S_or2_601_1);
  or2(&S_or2_199_1);
  or2(&S_or2_235_1);
  or2(&S_or2_957_1);
  and2(&S_and2_956_1);
  or2(&S_or2_1068_1);
  or2(&S_or2_1519_1);
  or2(&S_or2_1413_1);
  and2(&S_and2_1412_1);
  and2(&S_and2_1141_1);
  or2(&S_or2_2247_1);
  or2(&S_or2_1153_1);
  and2(&S_and2_1311_1);
  and2(&S_and2_1317_1);
  and2(&S_and2_2248_1);
  ovbsb(&S_ovbsb_1419_1);
  ovbsb(&S_ovbsb_1299_1);
  ovbsb(&S_ovbsb_1300_1);
  ovbsb(&S_ovbsb_1303_1);
  ovbsb(&S_ovbsb_966_1);
  ovbsb(&S_ovbsb_1320_1);
  ovbsb(&S_ovbsb_1321_1);
  ovbsb(&S_ovbsb_1322_1);
  ovbsb(&S_ovbsb_1236_1);
  ovbsb(&S_ovbsb_1215_1);
  ovbsb(&S_ovbsb_1217_1);
  ovbsb(&S_ovbsb_1219_1);
  ovbsb(&S_ovbsb_1221_1);
  ovbsb(&S_ovbsb_1228_1);
  ovbsb(&S_ovbsb_1233_1);
  fnapb(&S_fnapb_1273_1);
  samhd(&S_samhd_1253_1);
  zpfs(&S_zpfs_1267_1);
  zpfs(&S_zpfs_1263_1);
  orn(&S_orn_1423_1);
  orn(&S_orn_962_1);
  fnapb(&S_fnapb_200_1);
  newstage(&S_newstage_210_1);
  fnapb(&S_fnapb_568_1);
  zpfs(&S_zpfs_563_1);
  zpfs(&S_zpfs_564_1);
  noto(&S_noto_2265_1);
  rs(&S_rs_1140_1);
  zpfs(&S_zpfs_1278_1);
  zpfs(&S_zpfs_583_1);
  and2(&S_and2_600_1);
  orn(&S_orn_611_1);
  zpfs(&S_zpfs_214_1);
  zpfs(&S_zpfs_192_1);
  zpfs(&S_zpfs_193_1);
  and2(&S_and2_234_1);
  and2(&S_and2_1067_1);
  and2(&S_and2_1518_1);
  and2(&S_and2_1154_1);
  or2(&S_or2_1149_1);
  or3(&S_or3_1260_1);
  zpfs(&S_zpfs_2242_1);
  and2(&S_and2_197_1);
  and2(&S_and2_195_1);
  or4(&S_or4_2132_1);
  or3(&S_or3_2241_1);
  ovbsb(&S_ovbsb_209_1);
  ovbsb(&S_ovbsb_201_1);
  ovbsb(&S_ovbsb_202_1);
  ovbsb(&S_ovbsb_203_1);
  ovbsb(&S_ovbsb_241_1);
  ovbsb(&S_ovbsb_1074_1);
  ovbsb(&S_ovbsb_576_1);
  ovbsb(&S_ovbsb_571_1);
  ovbsb(&S_ovbsb_570_1);
  ovbsb(&S_ovbsb_569_1);
  ovbsb(&S_ovbsb_607_1);
  ovbsb(&S_ovbsb_1524_1);
  ovbsb(&S_ovbsb_1271_1);
  ovbsb(&S_ovbsb_1257_1);
  ovbsb(&S_ovbsb_1276_1);
  ovbsb(&S_ovbsb_1270_1);
  ovbsb(&S_ovbsb_1265_1);
  ovbsb(&S_ovbsb_1258_1);
  orn(&S_orn_245_1);
  orn(&S_orn_1077_1);
  orn(&S_orn_1527_1);
  and2(&S_and2_1206_1);
  and2(&S_and2_705_1);
  or2(&S_or2_693_1);
  and2(&S_and2_1166_1);
  or2(&S_or2_2150_1);
  or2(&S_or2_2138_1);
  ovbs(&S_ovbs_2133_1);
  ovbs(&S_ovbs_2146_1);
  ovbs(&S_ovbs_2136_1);
  noto(&S_noto_2137_1);
  and2(&S_and2_2143_1);
  and2(&S_and2_2155_1);
  or3(&S_or3_133_1);
  rs(&S_rs_694_1);
  noto(&S_noto_2134_1);
  noto(&S_noto_2147_1);
  rs(&S_rs_2151_1);
  noto(&S_noto_2152_1);
  rs(&S_rs_2139_1);
  rs(&S_rs_1163_1);
  noto(&S_noto_1164_1);
  rs(&S_rs_1192_1);
  rs(&S_rs_1198_1);
  and2(&S_and2_712_1);
  and3(&S_and3_681_1);
  and3(&S_and3_671_1);
  or3(&S_or3_901_1);
  or3(&S_or3_1341_1);
  and4(&S_and4_1126_1);
  and4(&S_and4_1132_1);
  or2(&S_or2_2106_1);
  irm(&S_irm_2377_1);
  ml(&S_ml_991_1);
  ml(&S_ml_1447_1);
  or2(&S_or2_1197_1);
  or4(&S_or4_988_1);
  or4(&S_or4_1444_1);
  ornc(&S_ornc_998_1);
  charint(&S_charint_989_1);
  ornc(&S_ornc_1454_1);
  charint(&S_charint_1445_1);
  noto(&S_noto_2140_1);
  noto(&S_noto_67_1);
  noto(&S_noto_2107_1);
  and2(&S_and2_59_1);
  and2(&S_and2_63_1);
  and4(&S_and4_354_1);
  or2(&S_or2_1565_1);
  or2(&S_or2_2123_1);
  fsumz(&S_fsumz_990_1);
  fsumz(&S_fsumz_1446_1);
  noto(&S_noto_1561_1);
  rs(&S_rs_357_1);
  noto(&S_noto_352_1);
  noto(&S_noto_294_1);
  rs(&S_rs_2124_1);
  rs(&S_rs_2125_1);
  ma(&S_ma_1455_1);
  ma(&S_ma_999_1);
  or4(&S_or4_305_1);
  or2(&S_or2_288_1);
  or2(&S_or2_311_1);
  or2(&S_or2_349_1);
  or4(&S_or4_358_1);
  and2(&S_and2_1560_1);
  or2(&S_or2_2187_1);
  or2(&S_or2_2208_1);
  cnshd(&S_cnshd_1000_1);
  cnshd(&S_cnshd_1456_1);
  rs(&S_rs_304_1);
  provsbr(&S_provsbr_293_1);
  equz_p(&S_equz_p_332_1);
  bolz(&S_bolz_333_1);
  provsbr(&S_provsbr_351_1);
  bolz(&S_bolz_356_1);
  noto(&S_noto_68_1);
  noto(&S_noto_57_1);
  and2(&S_and2_60_1);
  and2(&S_and2_64_1);
  or2(&S_or2_61_1);
  and2(&S_and2_629_1);
  and2(&S_and2_628_1);
  or3(&S_or3_644_1);
  and2(&S_and2_308_1);
  and4(&S_and4_338_1);
  and2(&S_and2_320_1);
  or2(&S_or2_310_1);
  and2(&S_and2_315_1);
  or2(&S_or2_362_1);
  and2(&S_and2_353_1);
  or5(&S_or5_556_1);
  and2(&S_and2_266_1);
  and2(&S_and2_267_1);
  or3(&S_or3_281_1);
  or2(&S_or2_1029_1);
  and2(&S_and2_1090_1);
  and2(&S_and2_1089_1);
  and2(&S_and2_1540_1);
  and2(&S_and2_1541_1);
  or2(&S_or2_1481_1);
  or2(&S_or2_1562_1);
  or3(&S_or3_1604_1);
  or3(&S_or3_1643_1);
  or3(&S_or3_1660_1);
  or3(&S_or3_2066_1);
  or3(&S_or3_2040_1);
  or4(&S_or4_1556_1);
  or4(&S_or4_1104_1);
  ovbsb(&S_ovbsb_271_1);
  ovbsb(&S_ovbsb_272_1);
  ovbsb(&S_ovbsb_1094_1);
  ovbsb(&S_ovbsb_1095_1);
  ovbsb(&S_ovbsb_634_1);
  ovbsb(&S_ovbsb_635_1);
  ovbsb(&S_ovbsb_1545_1);
  ovbsb(&S_ovbsb_1546_1);
  fnapb(&S_fnapb_1030_1);
  zpfs(&S_zpfs_1022_1);
  zpfs(&S_zpfs_1023_1);
  newstage(&S_newstage_1012_1);
  fnapb(&S_fnapb_1482_1);
  zpfs(&S_zpfs_1474_1);
  zpfs(&S_zpfs_1473_1);
  maz(&S_maz_319_1);
  maz(&S_maz_328_1);
  orni(&S_orni_1313_1);
  orni(&S_orni_309_1);
  rs(&S_rs_361_1);
  decatron(&S_decatron_316_1);
  orni(&S_orni_355_1);
  noto(&S_noto_330_1);
  swtakt(&S_swtakt_2041_1);
  swtakt(&S_swtakt_2067_1);
  swtakt(&S_swtakt_1649_1);
  swtakt(&S_swtakt_1653_1);
  swtakt(&S_swtakt_1609_1);
  zpfs(&S_zpfs_1047_1);
  zpfs(&S_zpfs_1498_1);
  or2(&S_or2_314_1);
  or2(&S_or2_323_1);
  or2(&S_or2_337_1);
  or2(&S_or2_336_1);
  and2(&S_and2_340_1);
  and2(&S_and2_335_1);
  and2(&S_and2_342_1);
  and2(&S_and2_341_1);
  and3(&S_and3_321_1);
  or5(&S_or5_187_1);
  and2(&S_and2_1563_1);
  or2(&S_or2_2235_1);
  or2(&S_or2_2219_1);
  or3(&S_or3_1558_1);
  or3(&S_or3_1107_1);
  zpfs(&S_zpfs_334_1);
  and2(&S_and2_1018_1);
  and2(&S_and2_1021_1);
  and2(&S_and2_1470_1);
  and2(&S_and2_1017_1);
  and2(&S_and2_2234_1);
  and2(&S_and2_2228_1);
  ovbsb(&S_ovbsb_1041_1);
  ovbsb(&S_ovbsb_1024_1);
  ovbsb(&S_ovbsb_1034_1);
  ovbsb(&S_ovbsb_1035_1);
  ovbsb(&S_ovbsb_2233_1);
  ovbsb(&S_ovbsb_1492_1);
  ovbsb(&S_ovbsb_1488_1);
  ovbsb(&S_ovbsb_1479_1);
  ovbsb(&S_ovbsb_1480_1);
  ovbsb(&S_ovbsb_2227_1);
  rs(&S_rs_2220_1);
  noto(&S_noto_2221_1);
  rs(&S_rs_2236_1);
  noto(&S_noto_2237_1);
  equz_p(&S_equz_p_322_1);
  noto(&S_noto_1569_1);
  cntch(&S_cntch_312_1);
  rs(&S_rs_313_1);
  cntch(&S_cntch_359_1);
  and2(&S_and2_1207_1);
  and2(&S_and2_327_1);
  and2(&S_and2_704_1);
  or5(&S_or5_1016_1);
  or5(&S_or5_1469_1);
  and2(&S_and2_1182_1);
  or5(&S_or5_1595_1);
  or5(&S_or5_1564_1);
  and2(&S_and2_1566_1);
  or2(&S_or2_1567_1);
  and4(&S_and4_2110_1);
  and3(&S_and3_2111_1);
  and3(&S_and3_2112_1);
  and2(&S_and2_2073_1);
  and2(&S_and2_2039_1);
  or3(&S_or3_2047_1);
  rs(&S_rs_2079_1);
  rs(&S_rs_2042_1);
  rs(&S_rs_2048_1);
  rs(&S_rs_1175_1);
  noto(&S_noto_1178_1);
  rs(&S_rs_1201_1);
  and2(&S_and2_347_1);
  and3(&S_and3_1167_1);
  and2(&S_and2_1117_1);
  and4(&S_and4_1124_1);
  and4(&S_and4_1130_1);
  or3(&S_or3_2078_1);
  or2(&S_or2_1200_1);
  orn(&S_orn_1332_1);
  orn(&S_orn_893_1);
  ornc(&S_ornc_1342_1);
  charint(&S_charint_1333_1);
  ornc(&S_ornc_902_1);
  charint(&S_charint_894_1);
  noto(&S_noto_348_1);
  rs(&S_rs_1111_1);
  or3(&S_or3_482_1);
  and3(&S_and3_491_1);
  and2(&S_and2_1157_1);
  and2(&S_and2_527_1);
  and2(&S_and2_493_1);
  fsumz(&S_fsumz_1334_1);
  fsumz(&S_fsumz_895_1);
  samhd(&S_samhd_506_1);
  samhd(&S_samhd_512_1);
  newstage(&S_newstage_508_1);
  ma(&S_ma_903_1);
  ma(&S_ma_1339_1);
  or4(&S_or4_502_1);
  or4(&S_or4_521_1);
  andn(&S_andn_1_1);
  and2(&S_and2_517_1);
  and2(&S_and2_514_1);
  ovbsb(&S_ovbsb_498_1);
  ovbsb(&S_ovbsb_495_1);
  ovbsb(&S_ovbsb_496_1);
  ovbsb(&S_ovbsb_497_1);
  ovbsb(&S_ovbsb_520_1);
  ovbsb(&S_ovbsb_524_1);
  ovbsb(&S_ovbsb_525_1);
  ovbsb(&S_ovbsb_526_1);
  cnshd(&S_cnshd_1343_1);
  cnshd(&S_cnshd_904_1);
  and2(&S_and2_1208_1);
  and2(&S_and2_720_1);
  or2(&S_or2_921_1);
  and2(&S_and2_978_1);
  and2(&S_and2_977_1);
  or3(&S_or3_987_1);
  and2(&S_and2_1433_1);
  and2(&S_and2_1434_1);
  or3(&S_or3_1443_1);
  or2(&S_or2_1376_1);
  and2(&S_and2_1189_1);
  ovbsb(&S_ovbsb_1437_1);
  ovbsb(&S_ovbsb_1438_1);
  ovbsb(&S_ovbsb_984_1);
  ovbsb(&S_ovbsb_981_1);
  fnapb(&S_fnapb_1378_1);
  zpfs(&S_zpfs_1370_1);
  zpfs(&S_zpfs_1371_1);
  newstage(&S_newstage_1384_1);
  fnapb(&S_fnapb_922_1);
  rs(&S_rs_1184_1);
  rs(&S_rs_1204_1);
  zpfs(&S_zpfs_1388_1);
  zpfs(&S_zpfs_934_1);
  zpfs(&S_zpfs_916_1);
  zpfs(&S_zpfs_917_1);
  or5(&S_or5_1356_1);
  and2(&S_and2_1367_1);
  and2(&S_and2_1369_1);
  or5(&S_or5_2157_1);
  or3(&S_or3_1854_1);
  or3(&S_or3_1846_1);
  or2(&S_or2_1860_1);
  or2(&S_or2_1852_1);
  ovbsb(&S_ovbsb_920_1);
  ovbsb(&S_ovbsb_919_1);
  ovbsb(&S_ovbsb_929_1);
  ovbsb(&S_ovbsb_924_1);
  ovbsb(&S_ovbsb_1383_1);
  ovbsb(&S_ovbsb_1368_1);
  ovbsb(&S_ovbsb_1363_1);
  ovbsb(&S_ovbsb_1381_1);
  orni(&S_orni_139_1);
  orn(&S_orn_454_1);
  orn(&S_orn_476_1);
  rs(&S_rs_1845_1);
  rs(&S_rs_1853_1);
  or2(&S_or2_456_1);
  or2(&S_or2_478_1);
  and2(&S_and2_752_1);
  or2(&S_or2_1288_1);
  or2(&S_or2_1289_1);
  and2(&S_and2_1225_1);
  or5(&S_or5_913_1);
  and2(&S_and2_1752_1);
  or4(&S_or4_1748_1);
  and2(&S_and2_1838_1);
  and2(&S_and2_1842_1);
  or4(&S_or4_2158_1);
  ovbsb(&S_ovbsb_1761_1);
  ovbsb(&S_ovbsb_1234_1);
  ovbsb(&S_ovbsb_761_1);
  orn(&S_orn_849_1);
  orn(&S_orn_1209_1);
  rs(&S_rs_1847_1);
  rs(&S_rs_1855_1);
  or2(&S_or2_839_1);
  or2(&S_or2_840_1);
  or4(&S_or4_820_1);
  or5(&S_or5_1256_1);
  or2(&S_or2_382_1);
  or2(&S_or2_386_1);
  ovbs(&S_ovbs_2164_1);
  noto(&S_noto_2165_1);
  and2(&S_and2_2171_1);
  and2(&S_and2_2183_1);
  or3(&S_or3_2159_1);
  and2(&S_and2_2160_1);
  or3(&S_or3_2173_1);
  and2(&S_and2_2174_1);
  or5(&S_or5_1735_1);
  or2(&S_or2_2409_1);
  rs(&S_rs_819_1);
  samhd(&S_samhd_385_1);
  and2(&S_and2_807_1);
  or2(&S_or2_811_1);
  or4(&S_or4_384_1);
  or5(&S_or5_1781_1);
  or2(&S_or2_2178_1);
  or2(&S_or2_2166_1);
  ovbs(&S_ovbs_2161_1);
  ovbs(&S_ovbs_2175_1);
  rs(&S_rs_2195_1);
  rs(&S_rs_2203_1);
  noto(&S_noto_2193_1);
  noto(&S_noto_2214_1);
  zpfs(&S_zpfs_2196_1);
  zpfs(&S_zpfs_2204_1);
  noto(&S_noto_2407_1);
  ovbsb(&S_ovbsb_391_1);
  ovbsb(&S_ovbsb_392_1);
  ovbsb(&S_ovbsb_393_1);
  rs(&S_rs_813_1);
  or2(&S_or2_2197_1);
  noto(&S_noto_2162_1);
  noto(&S_noto_2176_1);
  rs(&S_rs_2179_1);
  noto(&S_noto_2180_1);
  rs(&S_rs_2167_1);
  or2(&S_or2_2205_1);
  noto(&S_noto_2198_1);
  and2(&S_and2_2199_1);
  and2(&S_and2_2194_1);
  noto(&S_noto_2206_1);
  noto(&S_noto_2186_1);
  ovbsb(&S_ovbsb_2185_1);
  noto(&S_noto_2168_1);
  and2(&S_and2_2207_1);
  and4(&S_and4_2188_1);
  ovbs(&S_ovbs_2189_1);
  and2(&S_and2_2215_1);
  noto(&S_noto_2217_1);
  or2(&S_or2_2190_1);
  ovbsb(&S_ovbsb_2218_1);
  orn(&S_orn_664_1);
  orn(&S_orn_663_1);
  noto(&S_noto_2191_1);
  and4(&S_and4_2209_1);
  ovbs(&S_ovbs_2210_1);
  or2(&S_or2_2211_1);
  newstage(&S_newstage_666_1);
  or2(&S_or2_700_1);
  ovbs(&S_ovbs_2200_1);
  noto(&S_noto_2212_1);
  and2(&S_and2_699_1);
  setData(idR8AD21LDU,&var1335);
  setData(idR0VN15RDU,&var14);
  setData(idB3CV01RDU,&var1522);
  setData(idR0DE3CLDU,&var229);
  setData(idR0DE3DLDU,&var228);
  setData(idTTLDU,&var232);
  setData(idB3AB13LDU,&var89);
  setData(idA3AB13LDU,&var175);
  setData(idR3VS01IDU,&var361);
  setData(idR3VS12LDU,&var359);
  setData(idR3VS22LDU,&var360);
  setData(idR5VS01IDU,&var358);
  setData(idR5VS12LDU,&var356);
  setData(idR5VS22LDU,&var357);
  setData(idB3AB15LDU,&var91);
  setData(idB3EE03LDU,&var1021);
  setData(idA3EE03LDU,&var1022);
  setData(idB3AB19LDU,&var90);
  setData(idA3AB19LDU,&var169);
  setData(idR0VL23LDU,&var1257);
  setData(idR0VL22LDU,&var1279);
  setData(idR0AD05LZ2,&var297);
  setData(idR0AD05LZ1,&var297);
  setData(idR0AD04LZ2,&var592);
  setData(idR0AD04LZ1,&var592);
  setData(idR0AD03LZ2,&var296);
  setData(idR0AD03LZ1,&var296);
  setData(idR0CN95LDU,&var440);
  setData(idR0CN94LDU,&var439);
  setData(idR0CN93LDU,&var438);
  setData(idR0AB19LDU,&var45);
  setData(idR0VN12RDU,&var1190);
  setData(idR0VN11RDU,&var1188);
  setData(idR0CN92LDU,&var406);
  setData(idR0AB20LDU,&var44);
  setData(idA3AB15LDU,&var173);
  setData(idA3MC03RDU,&var436);
  setData(idR0CN91LDU,&var435);
  setData(idA3MC02RDU,&var434);
  setData(idA3MC01RDU,&var433);
  setData(idR0AB18LDU,&var46);
  setData(idR0AB17LDU,&var47);
  setData(idR0AB16LDU,&var48);
  setData(idB1AB19LDU,&var120);
  setData(idA3ZAV,&var1527);
  setData(idA1ZAV,&var1590);
  setData(idB3IS12LDU,&var457);
  setData(idA3IS12LDU,&var458);
  setData(idR0AB15LDU,&var463);
  setData(idR0AB14LDU,&var461);
  setData(idA4DW,&var1367);
  setData(idA4UP,&var1368);
  setData(idR4ABL,&var1829);
  setData(idA9ZAV,&var1465);
  setData(idA8ZAV,&var1666);
  setData(idA2ZAV,&var1671);
  setData(idB8ZAV,&var1676);
  setData(idA5ZAV,&var1744);
  setData(idR2ZAV,&var1620);
  setData(idA6ZAV,&var1746);
  setData(idA4ZAV,&var1745);
  setData(idR0AB13LDU,&var530);
  setData(idR0AB12LDU,&var534);
  setData(idR0AB11LDU,&var538);
  setData(idR0AB10LDU,&var542);
  setData(idR0AB09LDU,&var546);
  setData(idR0AB08LDU,&var49);
  setData(idB6AB05LDU,&var72);
  setData(idR0VS11LDU,&var1887);
  setData(idA8VS01IDU,&var1670);
  setData(idB8VS01IDU,&var1680);
  setData(idR2AD10LDU,&var1625);
  setData(idR2AD20LDU,&var1626);
  setData(idB6VS01IDU,&var1817);
  setData(idR0AD16LDU,&lRM_0_);
  setData(idR0AB07LDU,&var50);
  setData(idR0EE03LDU,&var616);
  setData(idR0VX02LDU,&var1027);
  setData(idR0AD21LDU,&var1025);
  setData(idB2AB15LDU,&var106);
  setData(idA2AB15LDU,&var190);
  setData(idR0AB05LDU,&var1339);
  setData(idR0AB03LDU,&var1350);
  setData(idA1AB19LDU,&var201);
  setData(idR0VZ71LDU,&var283);
  setData(idR0VL01RDU,&var1385);
  setData(idB7AZ03LDU,&var15);
  setData(idA7AZ03LDU,&var16);
  setData(idB2VS01IDU,&var1658);
  setData(idB2VS21LDU,&var1660);
  setData(idB2VS11LDU,&var1659);
  setData(idR0VP73LDU,&var703);
  setData(idR0VS18LDU,&var780);
  setData(idB3VX01LDU,&var650);
  setData(idA3VX01LDU,&var651);
  setData(idB2VS32LDU,&var576);
  setData(idA2VS32LDU,&var577);
  setData(idR0VS17LDU,&var770);
  setData(idR0VX09LDU,&var394);
  moveData(idR0VX08IDU,idR0MW12IP1);
  setData(idR0VW23LDU,&var1122);
  setData(idR0VW13LDU,&var1121);
  setData(idB7AP31LDU,&var1370);
  setData(idA7AP31LDU,&var1371);
  setData(idB3AD31LDU,&var1428);
  setData(idB3AD34LDU,&var1429);
  setData(idA3AD31LDU,&var1434);
  setData(idA3AD34LDU,&var1431);
  setData(idA3AD33LDU,&var1433);
  setData(idB2AD33LDU,&var555);
  setData(idA2AD33LDU,&var558);
  setData(idR0AB01LDU,&var1457);
  setData(idB9AB02LDU,&var51);
  setData(idB9AB01LDU,&var52);
  setData(idB9AZ03LDU,&var53);
  setData(idA9AB02LDU,&var137);
  setData(idA9AB01LDU,&var136);
  setData(idA9AZ03LDU,&var135);
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
  setData(idR0VS21IDU,&var1360);
  setData(idR0VX03LDU,&var972);
  setData(idR0VL21IDU,&var1270);
  setData(idR0VL05RDU,&var637);
  setData(idR0VL03RDU,&var643);
  setData(idR0AB02LDU,&var1333);
  setData(idR0AB06LDU,&var1336);
  setData(idR0AB04LDU,&var1344);
  setData(idR0VL04RDU,&var640);
  setData(idR0AD14LDU,&var592);
  setData(idR0VL02RDU,&var634);
  setData(idB3AD33LDU,&var1427);
  setData(idR0VL06RDU,&var647);
  setData(idR0VL11IDU,&var1481);
  setData(idR0VL01IDU,&var1482);
  setData(idR0VX01LDU,&var1029);
  setData(idB1AD32LDU,&var1435);
  setData(idA1AD32LDU,&var1437);
  setData(idB2AD32LDU,&var583);
  setData(idA2AD32LDU,&var585);
  setData(idB1AD31LDU,&var1438);
  setData(idA1AD31LDU,&var1439);
  setData(idB2AD31LDU,&var586);
  setData(idA2AD31LDU,&var587);
  setData(idB3AB20LDU,&var84);
  setData(idB3AB18LDU,&var87);
  setData(idB3AB17LDU,&var85);
  setData(idB3AB16LDU,&var86);
  setData(idB3AB14LDU,&var88);
  setData(idB3AB12LDU,&var92);
  setData(idB3AB11LDU,&var93);
  setData(idB3AB10LDU,&var94);
  setData(idB3AB09LDU,&var95);
  setData(idB3AB06LDU,&var98);
  setData(idB3AB05LDU,&var99);
  setData(idB3AB08LDU,&var96);
  setData(idB3AB07LDU,&var97);
  setData(idB3CV02RDU,&var1516);
  setData(idB3AD01LDU,&var1509);
  setData(idB3AD05LDU,&var1515);
  setData(idB3AD04LDU,&var1514);
  setData(idB3AD03LDU,&var1513);
  setData(idB3AD02LDU,&var1512);
  setData(idB3AD21LDU,&var1510);
  setData(idB3AD11LDU,&var1511);
  setData(idB3AZ03LDU,&var103);
  setData(idB3VS22LDU,&var1520);
  setData(idB3AB01LDU,&var101);
  setData(idB3AB02LDU,&var100);
  setData(idB3AB04LDU,&var102);
  setData(idB3VS12LDU,&var1521);
  setData(idA3AB20LDU,&var168);
  setData(idA3AB18LDU,&var170);
  setData(idA3AB17LDU,&var171);
  setData(idA3AB16LDU,&var172);
  setData(idA3AB14LDU,&var174);
  setData(idA3AB12LDU,&var176);
  setData(idA3AB11LDU,&var177);
  setData(idA3AB10LDU,&var178);
  setData(idA3AB09LDU,&var179);
  setData(idA3AB06LDU,&var181);
  setData(idA3AB05LDU,&var183);
  setData(idA3AB08LDU,&var180);
  setData(idA3AB07LDU,&var182);
  setData(idA3CV02RDU,&var1548);
  setData(idA3AD01LDU,&var1541);
  setData(idA3AD05LDU,&var1547);
  setData(idA3AD04LDU,&var1546);
  setData(idA3AD03LDU,&var1545);
  setData(idA3AD02LDU,&var1544);
  setData(idA3AD21LDU,&var1542);
  setData(idA3AD11LDU,&var1543);
  setData(idA3AZ03LDU,&var187);
  setData(idA3VS22LDU,&var1552);
  setData(idA3AB01LDU,&var184);
  setData(idA3AB02LDU,&var185);
  setData(idA3AB04LDU,&var186);
  setData(idA3CV01RDU,&var1554);
  setData(idA3VS12LDU,&var1553);
  setData(idB1AB18LDU,&var117);
  setData(idB1AB17LDU,&var118);
  setData(idB1AB16LDU,&var119);
  setData(idB1AB14LDU,&var121);
  setData(idB1AB13LDU,&var122);
  setData(idB1AB12LDU,&var123);
  setData(idB1AB11LDU,&var124);
  setData(idB1AB10LDU,&var125);
  setData(idB1AB09LDU,&var126);
  setData(idB1AB06LDU,&var128);
  setData(idB1AB05LDU,&var130);
  setData(idB1AB08LDU,&var127);
  setData(idB1AB07LDU,&var129);
  setData(idB1CV02RDU,&var1577);
  setData(idB1AD01LDU,&var1570);
  setData(idB1AD05LDU,&var1576);
  setData(idB1AD04LDU,&var1575);
  setData(idB1AD03LDU,&var1574);
  setData(idB1AD02LDU,&var1573);
  setData(idB1AD21LDU,&var1572);
  setData(idB1AD11LDU,&var1571);
  setData(idB1AZ03LDU,&var134);
  setData(idB1VS22LDU,&var1582);
  setData(idB1AB01LDU,&var131);
  setData(idB1AB02LDU,&var132);
  setData(idB1AB04LDU,&var133);
  setData(idB1CV01RDU,&var1583);
  setData(idB1VS12LDU,&var1581);
  setData(idA1AB18LDU,&var202);
  setData(idA1AB17LDU,&var203);
  setData(idA1AB16LDU,&var204);
  setData(idA1AB14LDU,&var205);
  setData(idA1AB13LDU,&var206);
  setData(idA1AB12LDU,&var207);
  setData(idA1AB11LDU,&var208);
  setData(idA1AB10LDU,&var209);
  setData(idA1AB09LDU,&var210);
  setData(idA1AB06LDU,&var213);
  setData(idA1AB05LDU,&var214);
  setData(idA1AB08LDU,&var211);
  setData(idA1AB07LDU,&var212);
  setData(idA1CV02RDU,&var1610);
  setData(idA1AD01LDU,&var1603);
  setData(idA1AD05LDU,&var1609);
  setData(idA1AD04LDU,&var1608);
  setData(idA1AD03LDU,&var1607);
  setData(idA1AD02LDU,&var1606);
  setData(idA1AD21LDU,&var1605);
  setData(idA1AD11LDU,&var1604);
  setData(idA1AZ03LDU,&var218);
  setData(idA1VS22LDU,&var1613);
  setData(idA1AB01LDU,&var217);
  setData(idA1AB02LDU,&var216);
  setData(idA1AB04LDU,&var215);
  setData(idA1CV01RDU,&var1614);
  setData(idA1VS12LDU,&var1612);
  setData(idR1AD20LDU,&var1635);
  setData(idR1AD10LDU,&var1634);
  setData(idR2AB04LDU,&var36);
  setData(idR1AB04LDU,&var40);
  setData(idR2AB02LDU,&var37);
  setData(idR2AB01LDU,&var38);
  setData(idR2AZ03LDU,&var39);
  setData(idR1AB02LDU,&var41);
  setData(idR1AB01LDU,&var42);
  setData(idR1AZ03LDU,&var43);
  setData(idB2AB17LDU,&var104);
  setData(idB2AB16LDU,&var105);
  setData(idB2AB14LDU,&var107);
  setData(idB2AB13LDU,&var108);
  setData(idB2AB12LDU,&var109);
  setData(idB2AB11LDU,&var110);
  setData(idB2AB10LDU,&var111);
  setData(idB2AB09LDU,&var112);
  setData(idB2AB06LDU,&var115);
  setData(idB2AB05LDU,&var116);
  setData(idB2AB08LDU,&var113);
  setData(idB2AB07LDU,&var114);
  setData(idB2CV02RDU,&var1657);
  setData(idB2AD01LDU,&var1650);
  setData(idB2AD05LDU,&var1656);
  setData(idB2AD04LDU,&var1655);
  setData(idB2AD03LDU,&var1654);
  setData(idB2AD02LDU,&var1653);
  setData(idB2AD21LDU,&var1652);
  setData(idB2AD11LDU,&var1651);
  setData(idB2AZ03LDU,&var224);
  setData(idB2AB01LDU,&var225);
  setData(idB2AB02LDU,&var226);
  setData(idB2AB04LDU,&var223);
  setData(idB2CV01RDU,&var1661);
  setData(idA2CV02RDU,&var1698);
  setData(idA2AD01LDU,&var1691);
  setData(idA2AB17LDU,&var188);
  setData(idA2AB16LDU,&var189);
  setData(idA2AB14LDU,&var191);
  setData(idA2AB13LDU,&var192);
  setData(idA2AB12LDU,&var193);
  setData(idA2AB11LDU,&var194);
  setData(idA2AB10LDU,&var195);
  setData(idA2AB09LDU,&var196);
  setData(idA2AB06LDU,&var198);
  setData(idA2AB05LDU,&var200);
  setData(idA2AB08LDU,&var197);
  setData(idA2AB07LDU,&var199);
  setData(idA2AD05LDU,&var1697);
  setData(idA2AD04LDU,&var1696);
  setData(idA2AD03LDU,&var1695);
  setData(idA2AD02LDU,&var1694);
  setData(idA2AD21LDU,&var1693);
  setData(idA2AD11LDU,&var1692);
  setData(idA2AZ03LDU,&var222);
  setData(idA2VS21LDU,&var1703);
  setData(idA2AB01LDU,&var221);
  setData(idA2AB02LDU,&var220);
  setData(idA2AB04LDU,&var219);
  setData(idA2CV01RDU,&var1704);
  setData(idA2VS11LDU,&var1702);
  setData(idA8AB01LDU,&var151);
  setData(idA8AB02LDU,&var150);
  setData(idA8AB14LDU,&var138);
  setData(idA8AB13LDU,&var139);
  setData(idA8AB12LDU,&var140);
  setData(idA8AB11LDU,&var141);
  setData(idA8AB10LDU,&var142);
  setData(idA8AB09LDU,&var143);
  setData(idA8AB08LDU,&var144);
  setData(idA8AB04LDU,&var149);
  setData(idA8AD20LDU,&var1669);
  setData(idA8AD10LDU,&var1668);
  setData(idA8AZ03LDU,&var148);
  setData(idA8VS22LDU,&var1716);
  setData(idA8AB05LDU,&var145);
  setData(idA8AB07LDU,&var146);
  setData(idA8AB06LDU,&var147);
  setData(idA8CV01RDU,&var1717);
  setData(idA8VS12LDU,&var1715);
  setData(idB8AB02LDU,&var65);
  setData(idB8AB14LDU,&var54);
  setData(idB8AB13LDU,&var55);
  setData(idB8AB12LDU,&var56);
  setData(idB8AB11LDU,&var57);
  setData(idB8AB10LDU,&var58);
  setData(idB8AB09LDU,&var59);
  setData(idB8AB08LDU,&var60);
  setData(idB8AB04LDU,&var66);
  setData(idB8AB01LDU,&var67);
  setData(idB8AD20LDU,&var1679);
  setData(idB8AD10LDU,&var1678);
  setData(idB8AZ03LDU,&var64);
  setData(idB8VS22LDU,&var1733);
  setData(idB8AB05LDU,&var61);
  setData(idB8AB07LDU,&var62);
  setData(idB8AB06LDU,&var63);
  setData(idB8CV01RDU,&var1734);
  setData(idB8VS12LDU,&var1732);
  setData(idA6AB05LDU,&var156);
  setData(idB6AB09LDU,&var68);
  setData(idB6AB08LDU,&var69);
  setData(idB6AB07LDU,&var70);
  setData(idB6AB06LDU,&var71);
  setData(idA6AB09LDU,&var152);
  setData(idA6AB08LDU,&var153);
  setData(idA6AB07LDU,&var154);
  setData(idA6AB06LDU,&var155);
  setData(idB5AB04LDU,&var77);
  setData(idA5AB04LDU,&var162);
  setData(idB4AB02LDU,&var81);
  setData(idB4AB01LDU,&var82);
  setData(idB4AZ03LDU,&var83);
  setData(idA4AB02LDU,&var166);
  setData(idA4AB01LDU,&var167);
  setData(idA4AZ03LDU,&var165);
  setData(idA4AD10LDU,&var1778);
  setData(idB4AD10LDU,&var1769);
  setData(idB5AB02LDU,&var78);
  setData(idB5AB01LDU,&var79);
  setData(idB5AZ03LDU,&var80);
  setData(idA5AB02LDU,&var163);
  setData(idA5AB01LDU,&var164);
  setData(idA5AZ03LDU,&var161);
  setData(idA5AD20LDU,&var1798);
  setData(idA5AD10LDU,&var1797);
  setData(idB5AD20LDU,&var1789);
  setData(idB5AD10LDU,&var1788);
  setData(idR4AD20LDU,&var1807);
  setData(idR4AD10LDU,&var1806);
  setData(idR4AB18LDU,&var17);
  setData(idR4AB17LDU,&var18);
  setData(idR4AB16LDU,&var19);
  setData(idR4AB15LDU,&var20);
  setData(idR4AB14LDU,&var21);
  setData(idR4AB13LDU,&var22);
  setData(idR4AB12LDU,&var23);
  setData(idR4AB11LDU,&var35);
  setData(idR4AB10LDU,&var24);
  setData(idR4AB09LDU,&var25);
  setData(idR4AB08LDU,&var26);
  setData(idR4AB07LDU,&var27);
  setData(idR4AB06LDU,&var28);
  setData(idR4AB05LDU,&var29);
  setData(idR4AB04LDU,&var30);
  setData(idR4AB03LDU,&var32);
  setData(idR4AZ03LDU,&var31);
  setData(idR4AB02LDU,&var33);
  setData(idR4AB01LDU,&var34);
  setData(idB6AB04LDU,&var73);
  setData(idA6AB04LDU,&var158);
  setData(idB6AB02LDU,&var75);
  setData(idB6AB01LDU,&var74);
  setData(idB6AZ03LDU,&var76);
  setData(idA6AB02LDU,&var159);
  setData(idA6AB01LDU,&var160);
  setData(idA6AZ03LDU,&var157);
  setData(idB6AD20LDU,&var1816);
  setData(idB6AD10LDU,&var1815);
  setData(idA6AD20LDU,&var1825);
  setData(idA6AD10LDU,&var1824);
  setData(idR0ES01LDU,&var1111);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
  for( i=0;i<10;i++ )
    array_m351_rz_1[i] = &(&internal1_m351_rz)[i*1];
  for( i=0;i<10;i++ )
    array_m293_rz_1[i] = &(&internal1_m293_rz)[i*1];
  for( i=0;i<6;i++ )
    array_m1573_rz_1[i] = &(&internal1_m1573_rz)[i*1];
  for( i=0;i<60;i++ )
    array_m1482_x0_1[i] = &(&internal1_m1482_x0)[i*5];
  for( i=0;i<60;i++ )
    array_m1482_tim0_1[i] = &(&internal1_m1482_tim0)[i*5];
  for( i=0;i<60;i++ )
    array_m1030_x0_1[i] = &(&internal1_m1030_x0)[i*5];
  for( i=0;i<60;i++ )
    array_m1030_tim0_1[i] = &(&internal1_m1030_tim0)[i*5];
  for( i=0;i<150;i++ )
    array_m568_x0_1[i] = &(&internal1_m568_x0)[i*5];
  for( i=0;i<150;i++ )
    array_m568_tim0_1[i] = &(&internal1_m568_tim0)[i*5];
  for( i=0;i<150;i++ )
    array_m200_x0_1[i] = &(&internal1_m200_x0)[i*5];
  for( i=0;i<150;i++ )
    array_m200_tim0_1[i] = &(&internal1_m200_tim0)[i*5];
  for( i=0;i<80;i++ )
    array_m922_x0_1[i] = &(&internal1_m922_x0)[i*5];
  for( i=0;i<80;i++ )
    array_m922_tim0_1[i] = &(&internal1_m922_tim0)[i*5];
  for( i=0;i<80;i++ )
    array_m1378_x0_1[i] = &(&internal1_m1378_x0)[i*5];
  for( i=0;i<80;i++ )
    array_m1378_tim0_1[i] = &(&internal1_m1378_tim0)[i*5];
  for( i=0;i<20;i++ )
    array_m1795_x0_1[i] = &(&internal1_m1795_x0)[i*5];
  for( i=0;i<20;i++ )
    array_m1795_tim0_1[i] = &(&internal1_m1795_tim0)[i*5];
  for( i=0;i<20;i++ )
    array_m1273_x0_1[i] = &(&internal1_m1273_x0)[i*5];
  for( i=0;i<20;i++ )
    array_m1273_tim0_1[i] = &(&internal1_m1273_tim0)[i*5];
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
