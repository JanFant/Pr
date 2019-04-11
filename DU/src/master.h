#ifndef DU_H
#define DU_H
// Подсистема DU:DU
static char SimulOn=0;
static short CodeSub=2;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 10854
static char BUFFER[10854];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.50\0", 5432, "192.168.10.150\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0AD21LDU	 BUFFER[0]	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
#define idR0AD21LDU	 1	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
#define R0VX02LDU	 BUFFER[2]	//( - , DU) Импульс разрешен
#define idR0VX02LDU	 2	//( - , DU) Импульс разрешен
#define R0EE03LDU	 BUFFER[4]	//( - , DU) ВПИС ИС
#define idR0EE03LDU	 3	//( - , DU) ВПИС ИС
#define R0AB07LDU	 BUFFER[6]	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
#define idR0AB07LDU	 4	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
#define R0AD16LDU	 BUFFER[8]	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
#define idR0AD16LDU	 5	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
#define C2MD31LP1	 BUFFER[10]	//( - , DU) Кнопка СБРОС РБ
#define idC2MD31LP1	 6	//( - , DU) Кнопка СБРОС РБ
#define B6VS01IDU	 BUFFER[12]	//( - , DU) Готовность к управлению БЗ2
#define idB6VS01IDU	 7	//( - , DU) Готовность к управлению БЗ2
#define R2AD20LDU	 BUFFER[15]	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
#define idR2AD20LDU	 8	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
#define R2AD10LDU	 BUFFER[17]	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
#define idR2AD10LDU	 9	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
#define B8VS01IDU	 BUFFER[19]	//( - , DU) Готовность к управлению АЗ2
#define idB8VS01IDU	 10	//( - , DU) Готовность к управлению АЗ2
#define A8VS01IDU	 BUFFER[22]	//( - , DU) Готовность к управлению ДС2
#define idA8VS01IDU	 11	//( - , DU) Готовность к управлению ДС2
#define A1IE03LDU	 BUFFER[25]	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
#define idA1IE03LDU	 12	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
#define A1IE04LDU	 BUFFER[27]	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
#define idA1IE04LDU	 13	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
#define A2IE03LDU	 BUFFER[29]	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
#define idA2IE03LDU	 14	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
#define A2IE04LDU	 BUFFER[31]	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
#define idA2IE04LDU	 15	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
#define A3IE03LDU	 BUFFER[33]	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
#define idA3IE03LDU	 16	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
#define A3IE04LDU	 BUFFER[35]	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
#define idA3IE04LDU	 17	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
#define B1IE03LDU	 BUFFER[37]	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
#define idB1IE03LDU	 18	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
#define B1IE04LDU	 BUFFER[39]	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
#define idB1IE04LDU	 19	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
#define B2IE03LDU	 BUFFER[41]	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
#define idB2IE03LDU	 20	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
#define B2IE04LDU	 BUFFER[43]	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
#define idB2IE04LDU	 21	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
#define B3IE03LDU	 BUFFER[45]	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
#define idB3IE03LDU	 22	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
#define B3IE04LDU	 BUFFER[47]	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
#define idB3IE04LDU	 23	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
#define R0AD14LZ2	 BUFFER[49]	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
#define idR0AD14LZ2	 24	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
#define A3VZ13LZ2	 BUFFER[51]	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ2	 25	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define A3VZ13LZ1	 BUFFER[53]	//(vds32:02 - K18VDSR, - ) Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ1	 26	//(vds32:02 - K18VDSR, - ) Имитация срабатывания АЗ от ВУ ИС
#define A3VZ15LZ1	 BUFFER[55]	//(vds32:02 - K19VDSR, - ) Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ1	 27	//(vds32:02 - K19VDSR, - ) Имитация срабатывания АЗ от НУП ИС
#define A3VZ15LZ2	 BUFFER[57]	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ2	 28	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define B2IS33LDU	 BUFFER[59]	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
#define idB2IS33LDU	 29	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
#define B3IS31LDU	 BUFFER[61]	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
#define idB3IS31LDU	 30	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
#define B3IS33LDU	 BUFFER[63]	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
#define idB3IS33LDU	 31	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
#define B3IS35LDU	 BUFFER[65]	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
#define idB3IS35LDU	 32	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
#define B4IS10LDU	 BUFFER[67]	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
#define idB4IS10LDU	 33	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
#define R6IS31LDU	 BUFFER[69]	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
#define idR6IS31LDU	 34	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
#define R6IS32LDU	 BUFFER[71]	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
#define idR6IS32LDU	 35	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
#define R6IS42LDU	 BUFFER[73]	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
#define idR6IS42LDU	 36	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
#define R6IS41LDU	 BUFFER[75]	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
#define idR6IS41LDU	 37	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
#define R6IS52LDU	 BUFFER[77]	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
#define idR6IS52LDU	 38	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
#define R6IS51LDU	 BUFFER[79]	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
#define idR6IS51LDU	 39	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
#define R3IS11LDU	 BUFFER[81]	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
#define idR3IS11LDU	 40	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
#define R3IS21LDU	 BUFFER[83]	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
#define idR3IS21LDU	 41	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
#define R0AB03LDU	 BUFFER[85]	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
#define idR0AB03LDU	 42	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
#define R0AB05LDU	 BUFFER[87]	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
#define idR0AB05LDU	 43	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
#define R0VN11RZ1	 BUFFER[89]	//( - , MDuBz1) Средняя мощность по BAZ1
#define idR0VN11RZ1	 44	//( - , MDuBz1) Средняя мощность по BAZ1
#define R0VN11RZ2	 BUFFER[94]	//( - , MDuBz2) Средняя мощность по BAZ2
#define idR0VN11RZ2	 45	//( - , MDuBz2) Средняя мощность по BAZ2
#define A2AB15LDU	 BUFFER[99]	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define idA2AB15LDU	 46	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define B2AB15LDU	 BUFFER[101]	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define idB2AB15LDU	 47	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define R0AB14LDU	 BUFFER[103]	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
#define idR0AB14LDU	 48	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
#define R0AB15LDU	 BUFFER[105]	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
#define idR0AB15LDU	 49	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
#define A3IS12LDU	 BUFFER[107]	//( - , DU) Приход на ВУ штока ИС1
#define idA3IS12LDU	 50	//( - , DU) Приход на ВУ штока ИС1
#define B3IS12LDU	 BUFFER[109]	//( - , DU) Приход на ВУ штока ИС2
#define idB3IS12LDU	 51	//( - , DU) Приход на ВУ штока ИС2
#define A1ZAV	 BUFFER[111]	//( - , DU) 
#define idA1ZAV	 52	//( - , DU) 
#define A3ZAV	 BUFFER[113]	//( - , DU) 
#define idA3ZAV	 53	//( - , DU) 
#define B1AB19LDU	 BUFFER[115]	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
#define idB1AB19LDU	 54	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
#define R0VN09RZ2	 BUFFER[117]	//( - , MDuBz2) Усредненный период разгона
#define idR0VN09RZ2	 55	//( - , MDuBz2) Усредненный период разгона
#define R0VN09RZ1	 BUFFER[122]	//( - , MDuBz1) Усредненный период разгона
#define idR0VN09RZ1	 56	//( - , MDuBz1) Усредненный период разгона
#define R0AB16LDU	 BUFFER[127]	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
#define idR0AB16LDU	 57	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
#define R0AB17LDU	 BUFFER[129]	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
#define idR0AB17LDU	 58	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
#define R0AB18LDU	 BUFFER[131]	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
#define idR0AB18LDU	 59	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
#define A0CT01IZ1	 BUFFER[133]	//( - , MDuBz1) Температура АЗ1-1
#define idA0CT01IZ1	 60	//( - , MDuBz1) Температура АЗ1-1
#define B0CT01IZ1	 BUFFER[138]	//( - , MDuBz1) Температура АЗ2-1
#define idB0CT01IZ1	 61	//( - , MDuBz1) Температура АЗ2-1
#define A0CT01IZ2	 BUFFER[143]	//( - , MDuBz2) Температура АЗ1-2
#define idA0CT01IZ2	 62	//( - , MDuBz2) Температура АЗ1-2
#define B0CT01IZ2	 BUFFER[148]	//( - , MDuBz2) Температура АЗ2-2
#define idB0CT01IZ2	 63	//( - , MDuBz2) Температура АЗ2-2
#define A3MC01RDU	 BUFFER[153]	//( - , DU) Заданная координата положения ИС от регулятора мм
#define idA3MC01RDU	 64	//( - , DU) Заданная координата положения ИС от регулятора мм
#define A3MC02RDU	 BUFFER[158]	//( - , DU) Температурная корректировка координаты ИМ
#define idA3MC02RDU	 65	//( - , DU) Температурная корректировка координаты ИМ
#define R0CN91LDU	 BUFFER[163]	//( - , DU) Рассчётная реактивность от регулятора
#define idR0CN91LDU	 66	//( - , DU) Рассчётная реактивность от регулятора
#define A3MC03RDU	 BUFFER[168]	//( - , DU) Координата положения ИМ 0-й реактивности
#define idA3MC03RDU	 67	//( - , DU) Координата положения ИМ 0-й реактивности
#define A3AB15LDU	 BUFFER[173]	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
#define idA3AB15LDU	 68	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
#define R0AB20LDU	 BUFFER[175]	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
#define idR0AB20LDU	 69	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
#define R0CN92LDU	 BUFFER[177]	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
#define idR0CN92LDU	 70	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
#define R0VN11RDU	 BUFFER[182]	//( - , DU) Текущая мощность РУ
#define idR0VN11RDU	 71	//( - , DU) Текущая мощность РУ
#define R0VS11LDU	 BUFFER[187]	//( - , DU) РУ не готова к работе
#define idR0VS11LDU	 72	//( - , DU) РУ не готова к работе
#define B6AB05LDU	 BUFFER[189]	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
#define idB6AB05LDU	 73	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
#define R0AB08LDU	 BUFFER[191]	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
#define idR0AB08LDU	 74	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
#define A1MC01RP1	 BUFFER[193]	//( - , DU) Заданная координата положения ББ1 мм
#define idA1MC01RP1	 75	//( - , DU) Заданная координата положения ББ1 мм
#define B1MC01RP1	 BUFFER[198]	//( - , DU) Заданная координата положения ББ2  мм
#define idB1MC01RP1	 76	//( - , DU) Заданная координата положения ББ2  мм
#define A3MC01RP1	 BUFFER[203]	//( - , DU) Заданная координата положения ИС1 мм
#define idA3MC01RP1	 77	//( - , DU) Заданная координата положения ИС1 мм
#define B3MC01RP1	 BUFFER[208]	//( - , DU) Заданная координата положения ИС2 мм
#define idB3MC01RP1	 78	//( - , DU) Заданная координата положения ИС2 мм
#define B8MC01RP2	 BUFFER[213]	//( - , DU) Заданная координата АЗ2 мм
#define idB8MC01RP2	 79	//( - , DU) Заданная координата АЗ2 мм
#define R0AB09LDU	 BUFFER[218]	//( - , DU) Ошибка в заданной координате ББ1
#define idR0AB09LDU	 80	//( - , DU) Ошибка в заданной координате ББ1
#define R0AB10LDU	 BUFFER[220]	//( - , DU) Ошибка в заданной координате ББ2
#define idR0AB10LDU	 81	//( - , DU) Ошибка в заданной координате ББ2
#define R0AB11LDU	 BUFFER[222]	//( - , DU) Ошибка в заданной координате  ИС1
#define idR0AB11LDU	 82	//( - , DU) Ошибка в заданной координате  ИС1
#define R0AB12LDU	 BUFFER[224]	//( - , DU) Ошибка в заданной координате  ИС2
#define idR0AB12LDU	 83	//( - , DU) Ошибка в заданной координате  ИС2
#define R0AB13LDU	 BUFFER[226]	//( - , DU) Ошибка в заданной координате  АЗ2
#define idR0AB13LDU	 84	//( - , DU) Ошибка в заданной координате  АЗ2
#define A4ZAV	 BUFFER[228]	//( - , DU) 
#define idA4ZAV	 85	//( - , DU) 
#define A6ZAV	 BUFFER[230]	//( - , DU) 
#define idA6ZAV	 86	//( - , DU) 
#define R2ZAV	 BUFFER[232]	//( - , DU) 
#define idR2ZAV	 87	//( - , DU) 
#define A5ZAV	 BUFFER[234]	//( - , DU) 
#define idA5ZAV	 88	//( - , DU) 
#define B8ZAV	 BUFFER[236]	//( - , DU) 
#define idB8ZAV	 89	//( - , DU) 
#define A2ZAV	 BUFFER[238]	//( - , DU) Завершение РБ1,2
#define idA2ZAV	 90	//( - , DU) Завершение РБ1,2
#define A8ZAV	 BUFFER[240]	//( - , DU) 
#define idA8ZAV	 91	//( - , DU) 
#define A9ZAV	 BUFFER[242]	//( - , DU) Завершение НИ ДС1(2)
#define idA9ZAV	 92	//( - , DU) Завершение НИ ДС1(2)
#define R4ABL	 BUFFER[244]	//( - , DU) Блокировка тележки -
#define idR4ABL	 93	//( - , DU) Блокировка тележки -
#define A4UP	 BUFFER[246]	//( - , DU) 
#define idA4UP	 94	//( - , DU) 
#define A4DW	 BUFFER[248]	//( - , DU) 
#define idA4DW	 95	//( - , DU) 
#define R0AB01LDU	 BUFFER[250]	//( - , DU) Режим проверки разрешён
#define idR0AB01LDU	 96	//( - , DU) Режим проверки разрешён
#define A3IS22LDU	 BUFFER[252]	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
#define idA3IS22LDU	 97	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
#define B3IS22LDU	 BUFFER[254]	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
#define idB3IS22LDU	 98	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
#define A2AD33LDU	 BUFFER[256]	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
#define idA2AD33LDU	 99	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
#define B2AD33LDU	 BUFFER[258]	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
#define idB2AD33LDU	 100	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
#define A3AD33LDU	 BUFFER[260]	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
#define idA3AD33LDU	 101	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
#define A3AD34LDU	 BUFFER[262]	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
#define idA3AD34LDU	 102	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
#define A3AD31LDU	 BUFFER[264]	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
#define idA3AD31LDU	 103	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
#define B3AD34LDU	 BUFFER[266]	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
#define idB3AD34LDU	 104	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
#define B3AD31LDU	 BUFFER[268]	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
#define idB3AD31LDU	 105	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
#define A2IS11LDU	 BUFFER[270]	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
#define idA2IS11LDU	 106	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
#define B2IS11LDU	 BUFFER[272]	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
#define idB2IS11LDU	 107	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
#define A3MD12LP1	 BUFFER[274]	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
#define idA3MD12LP1	 108	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
#define A3MD11LP1	 BUFFER[276]	//( - , DU) Кнопка ПУСК ИС1
#define idA3MD11LP1	 109	//( - , DU) Кнопка ПУСК ИС1
#define R0MD33LP1	 BUFFER[278]	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
#define idR0MD33LP1	 110	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
#define A1MD12LP1	 BUFFER[280]	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
#define idA1MD12LP1	 111	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
#define A1MD11LP1	 BUFFER[282]	//( - , DU) Кнопка ПУСК ББ1
#define idA1MD11LP1	 112	//( - , DU) Кнопка ПУСК ББ1
#define R0MW14IP2	 BUFFER[284]	//( - , DU) Переключатель ОБДУВ
#define idR0MW14IP2	 113	//( - , DU) Переключатель ОБДУВ
#define A7AP31LDU	 BUFFER[287]	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
#define idA7AP31LDU	 114	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
#define B7AP31LDU	 BUFFER[289]	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
#define idB7AP31LDU	 115	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
#define R0MW12IP2	 BUFFER[291]	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define idR0MW12IP2	 116	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define R0MW17LP1	 BUFFER[294]	//( - , DU) Переключатель АВТ/Р
#define idR0MW17LP1	 117	//( - , DU) Переключатель АВТ/Р
#define R0VW13LDU	 BUFFER[296]	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
#define idR0VW13LDU	 118	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
#define A4VS01IDU	 BUFFER[298]	//( - , DU) Готовность к управлению НИ1
#define idA4VS01IDU	 119	//( - , DU) Готовность к управлению НИ1
#define A4VS12LDU	 BUFFER[301]	//( - , DU) Движение НИ1 в сторону ВУ
#define idA4VS12LDU	 120	//( - , DU) Движение НИ1 в сторону ВУ
#define A4VS22LDU	 BUFFER[303]	//( - , DU) Движение НИ1 в сторону НУ
#define idA4VS22LDU	 121	//( - , DU) Движение НИ1 в сторону НУ
#define B4VS01IDU	 BUFFER[305]	//( - , DU) Готовность к управлению НИ2
#define idB4VS01IDU	 122	//( - , DU) Готовность к управлению НИ2
#define B4VS12LDU	 BUFFER[308]	//( - , DU) Движение НИ2 в сторону ВУ
#define idB4VS12LDU	 123	//( - , DU) Движение НИ2 в сторону ВУ
#define B4VS22LDU	 BUFFER[310]	//( - , DU) Движение НИ2 в сторону НУ
#define idB4VS22LDU	 124	//( - , DU) Движение НИ2 в сторону НУ
#define A5VS01IDU	 BUFFER[312]	//( - , DU) Готовность к управлению НЛ1
#define idA5VS01IDU	 125	//( - , DU) Готовность к управлению НЛ1
#define B5VS01IDU	 BUFFER[315]	//( - , DU) Готовность к управлению НЛ2
#define idB5VS01IDU	 126	//( - , DU) Готовность к управлению НЛ2
#define A6VS01IDU	 BUFFER[318]	//( - , DU) Готовность к управлению БЗ1
#define idA6VS01IDU	 127	//( - , DU) Готовность к управлению БЗ1
#define R4VS01IDU	 BUFFER[321]	//( - , DU) Готовность к управлению тележкой реактора
#define idR4VS01IDU	 128	//( - , DU) Готовность к управлению тележкой реактора
#define R2VS01IDU	 BUFFER[324]	//( - , DU) Готовность к управлению МДЗ2
#define idR2VS01IDU	 129	//( - , DU) Готовность к управлению МДЗ2
#define R1VS01IDU	 BUFFER[327]	//( - , DU) Готовность к управлению МДЗ1
#define idR1VS01IDU	 130	//( - , DU) Готовность к управлению МДЗ1
#define A9IS11LDU	 BUFFER[330]	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
#define idA9IS11LDU	 131	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
#define A9IS21LDU	 BUFFER[332]	//(vds32:02 - K24VDSR, - ) Приход на НУ НИ ДС1
#define idA9IS21LDU	 132	//(vds32:02 - K24VDSR, - ) Приход на НУ НИ ДС1
#define B9IS11LDU	 BUFFER[334]	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
#define idB9IS11LDU	 133	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
#define B9IS21LDU	 BUFFER[336]	//(vds32:02 - K26VDSR, - ) Приход на НУ НИ ДС2
#define idB9IS21LDU	 134	//(vds32:02 - K26VDSR, - ) Приход на НУ НИ ДС2
#define B9AD10LDU	 BUFFER[338]	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
#define idB9AD10LDU	 135	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
#define A9AD10LDU	 BUFFER[340]	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
#define idA9AD10LDU	 136	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
#define A9AZ03LDU	 BUFFER[342]	//( - , DU) Несанкционированное перемещение НИ ДС1
#define idA9AZ03LDU	 137	//( - , DU) Несанкционированное перемещение НИ ДС1
#define A9AB01LDU	 BUFFER[344]	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
#define idA9AB01LDU	 138	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
#define A9AB02LDU	 BUFFER[346]	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
#define idA9AB02LDU	 139	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
#define B9AZ03LDU	 BUFFER[348]	//( - , DU) Несанкционированное перемещение НИ ДС2
#define idB9AZ03LDU	 140	//( - , DU) Несанкционированное перемещение НИ ДС2
#define B9AB01LDU	 BUFFER[350]	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
#define idB9AB01LDU	 141	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
#define B9AB02LDU	 BUFFER[352]	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
#define idB9AB02LDU	 142	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
#define A0VT71LZ2	 BUFFER[354]	//( - , MDuBz2) АС по температуре в АЗ1
#define idA0VT71LZ2	 143	//( - , MDuBz2) АС по температуре в АЗ1
#define B0VT71LZ2	 BUFFER[356]	//( - , MDuBz2) АС по температуре в АЗ2
#define idB0VT71LZ2	 144	//( - , MDuBz2) АС по температуре в АЗ2
#define B2VS11LDU	 BUFFER[358]	//( - , DU) Движение РБ2 в сторону ВУ
#define idB2VS11LDU	 145	//( - , DU) Движение РБ2 в сторону ВУ
#define B2VS21LDU	 BUFFER[360]	//( - , DU) Движение РБ2 в сторону НУ
#define idB2VS21LDU	 146	//( - , DU) Движение РБ2 в сторону НУ
#define B2VS01IDU	 BUFFER[362]	//( - , DU) Готовность к управлению РБ2
#define idB2VS01IDU	 147	//( - , DU) Готовность к управлению РБ2
#define A7AS31LDU	 BUFFER[365]	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
#define idA7AS31LDU	 148	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
#define B7AS31LDU	 BUFFER[367]	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
#define idB7AS31LDU	 149	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
#define A7AZ03LDU	 BUFFER[369]	//( - , DU) Несанкционированное включение обдува АЗ1
#define idA7AZ03LDU	 150	//( - , DU) Несанкционированное включение обдува АЗ1
#define B7AZ03LDU	 BUFFER[371]	//( - , DU) Несанкционированное включение обдува АЗ2
#define idB7AZ03LDU	 151	//( - , DU) Несанкционированное включение обдува АЗ2
#define B3MD12LP1	 BUFFER[373]	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
#define idB3MD12LP1	 152	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
#define B3MD11LP1	 BUFFER[375]	//( - , DU) Кнопка ПУСК ИС2
#define idB3MD11LP1	 153	//( - , DU) Кнопка ПУСК ИС2
#define R0VL01RDU	 BUFFER[377]	//( - , DU) Индикация Время задержки
#define idR0VL01RDU	 154	//( - , DU) Индикация Время задержки
#define R0VZ71LZ2	 BUFFER[382]	//(vds32:03 - K22VDSR, DU) Обобщенный сигнал АЗ 2 канала
#define idR0VZ71LZ2	 155	//(vds32:03 - K22VDSR, DU) Обобщенный сигнал АЗ 2 канала
#define R0VZ71LZ1	 BUFFER[384]	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
#define idR0VZ71LZ1	 156	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
#define R0VZ71LDU	 BUFFER[386]	//( - , DU) Обобщенный сигнал АЗ
#define idR0VZ71LDU	 157	//( - , DU) Обобщенный сигнал АЗ
#define A2IS33LDU	 BUFFER[388]	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
#define idA2IS33LDU	 158	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
#define A3IS31LDU	 BUFFER[390]	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
#define idA3IS31LDU	 159	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
#define A3IS33LDU	 BUFFER[392]	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
#define idA3IS33LDU	 160	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
#define A3IS35LDU	 BUFFER[394]	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
#define idA3IS35LDU	 161	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
#define A4IS10LDU	 BUFFER[396]	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
#define idA4IS10LDU	 162	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
#define A1VN71LZ1	 BUFFER[398]	//(vds32:02 - K21VDSR, - ) Блокировка автоматического подъёма ББ
#define idA1VN71LZ1	 163	//(vds32:02 - K21VDSR, - ) Блокировка автоматического подъёма ББ
#define A1VN71LZ2	 BUFFER[400]	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define idA1VN71LZ2	 164	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define A1AB19LDU	 BUFFER[402]	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
#define idA1AB19LDU	 165	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
#define R0AD14LZ1	 BUFFER[404]	//(vds32:02 - K20VDSR, - ) Имитация срабатывания АЗ от II УР
#define idR0AD14LZ1	 166	//(vds32:02 - K20VDSR, - ) Имитация срабатывания АЗ от II УР
#define R0VW23LDU	 BUFFER[406]	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
#define idR0VW23LDU	 167	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
#define R0VX08IDU	 BUFFER[408]	//( - , DU) Индикация Режим
#define idR0VX08IDU	 168	//( - , DU) Индикация Режим
#define R0VX09LDU	 BUFFER[411]	//( - , DU) Индикация регулятор мощности включен/отключен
#define idR0VX09LDU	 169	//( - , DU) Индикация регулятор мощности включен/отключен
#define R0VS17LDU	 BUFFER[413]	//( - , DU) Индикация выбора АВТОМАТ
#define idR0VS17LDU	 170	//( - , DU) Индикация выбора АВТОМАТ
#define A2VS32LDU	 BUFFER[415]	//( - , DU) Индикация  СБРОС РБ1
#define idA2VS32LDU	 171	//( - , DU) Индикация  СБРОС РБ1
#define B2VS32LDU	 BUFFER[417]	//( - , DU) Индикация  СБРОС РБ2
#define idB2VS32LDU	 172	//( - , DU) Индикация  СБРОС РБ2
#define A3VX01LDU	 BUFFER[419]	//( - , DU) Индикация Выстрел ИС1
#define idA3VX01LDU	 173	//( - , DU) Индикация Выстрел ИС1
#define A3IS11LDU	 BUFFER[421]	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
#define idA3IS11LDU	 174	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
#define B3VX01LDU	 BUFFER[423]	//( - , DU) Индикация Выстрел ИС2
#define idB3VX01LDU	 175	//( - , DU) Индикация Выстрел ИС2
#define R0VS18LDU	 BUFFER[425]	//( - , DU) Индикация  Проверка схем сброса
#define idR0VS18LDU	 176	//( - , DU) Индикация  Проверка схем сброса
#define B1MD11LP1	 BUFFER[427]	//( - , DU) Кнопка ПУСК ББ2
#define idB1MD11LP1	 177	//( - , DU) Кнопка ПУСК ББ2
#define B1MD12LP1	 BUFFER[429]	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
#define idB1MD12LP1	 178	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
#define B2MD11LP1	 BUFFER[431]	//( - , DU) Кнопка ПУСК РБ2
#define idB2MD11LP1	 179	//( - , DU) Кнопка ПУСК РБ2
#define B2MD12LP1	 BUFFER[433]	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
#define idB2MD12LP1	 180	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
#define A2MD11LP1	 BUFFER[435]	//( - , DU) Кнопка ПУСК РБ1
#define idA2MD11LP1	 181	//( - , DU) Кнопка ПУСК РБ1
#define A2MD12LP1	 BUFFER[437]	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
#define idA2MD12LP1	 182	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
#define R0IS01LDU	 BUFFER[439]	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
#define idR0IS01LDU	 183	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
#define R0IS02LDU	 BUFFER[441]	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
#define idR0IS02LDU	 184	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
#define R0VP73LZ1	 BUFFER[443]	//( - , MDuBz1) ПС давления для РУ
#define idR0VP73LZ1	 185	//( - , MDuBz1) ПС давления для РУ
#define R0VP73LZ2	 BUFFER[445]	//( - , MDuBz2) ПС давления для РУ
#define idR0VP73LZ2	 186	//( - , MDuBz2) ПС давления для РУ
#define R0VP73LDU	 BUFFER[447]	//( - , DU) ПС давления для РУ
#define idR0VP73LDU	 187	//( - , DU) ПС давления для РУ
#define R0MD34LP1	 BUFFER[449]	//( - , DU) Кнопка КВИТИРОВАТЬ
#define idR0MD34LP1	 188	//( - , DU) Кнопка КВИТИРОВАТЬ
#define A0VT71LZ1	 BUFFER[451]	//( - , MDuBz1) АС по температуре в АЗ1
#define idA0VT71LZ1	 189	//( - , MDuBz1) АС по температуре в АЗ1
#define B0VT71LZ1	 BUFFER[453]	//( - , MDuBz1) АС по температуре в АЗ2
#define idB0VT71LZ1	 190	//( - , MDuBz1) АС по температуре в АЗ2
#define A3VP42LDU	 BUFFER[455]	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
#define idA3VP42LDU	 191	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
#define A3CP02RDU	 BUFFER[457]	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
#define idA3CP02RDU	 192	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
#define A3VP52LDU	 BUFFER[462]	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define idA3VP52LDU	 193	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define B3VP42LDU	 BUFFER[464]	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
#define idB3VP42LDU	 194	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
#define B3CP02RDU	 BUFFER[466]	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
#define idB3CP02RDU	 195	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
#define B3VP52LDU	 BUFFER[471]	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define idB3VP52LDU	 196	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define B3VP82LDU	 BUFFER[473]	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
#define idB3VP82LDU	 197	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
#define A3VP82LDU	 BUFFER[475]	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
#define idA3VP82LDU	 198	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
#define A3IP02IDU	 BUFFER[477]	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	 199	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
#define B3IP02IDU	 BUFFER[480]	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
#define idB3IP02IDU	 200	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
#define A0VE01LDU	 BUFFER[483]	//( - , DU) Напряжение в системы АЗ1 подано
#define idA0VE01LDU	 201	//( - , DU) Напряжение в системы АЗ1 подано
#define B0VE01LDU	 BUFFER[485]	//( - , DU) Напряжение в системы АЗ2 подано
#define idB0VE01LDU	 202	//( - , DU) Напряжение в системы АЗ2 подано
#define A0VP01LDU	 BUFFER[487]	//( - , DU) Давление в системы АЗ1 подано
#define idA0VP01LDU	 203	//( - , DU) Давление в системы АЗ1 подано
#define B0VP01LDU	 BUFFER[489]	//( - , DU) Давление в системы АЗ2 подано
#define idB0VP01LDU	 204	//( - , DU) Давление в системы АЗ2 подано
#define A0EE01LZ1	 BUFFER[491]	//( - , MDuBz1) Исправность АКНП1
#define idA0EE01LZ1	 205	//( - , MDuBz1) Исправность АКНП1
#define A0EE03LZ1	 BUFFER[493]	//( - , MDuBz1) Исправность АКНП3
#define idA0EE03LZ1	 206	//( - , MDuBz1) Исправность АКНП3
#define A0EE02LZ1	 BUFFER[495]	//( - , MDuBz1) Исправность АКНП2
#define idA0EE02LZ1	 207	//( - , MDuBz1) Исправность АКНП2
#define A0EE04LZ1	 BUFFER[497]	//( - , MDuBz1) Исправность АКНП4
#define idA0EE04LZ1	 208	//( - , MDuBz1) Исправность АКНП4
#define A0VN01LDU	 BUFFER[499]	//( - , DU) Каналы АЗ1 проверены
#define idA0VN01LDU	 209	//( - , DU) Каналы АЗ1 проверены
#define B0VN01LDU	 BUFFER[501]	//( - , DU) Каналы АЗ2 проверены
#define idB0VN01LDU	 210	//( - , DU) Каналы АЗ2 проверены
#define A0EE01LZ2	 BUFFER[503]	//( - , MDuBz2) Исправность АКНП1
#define idA0EE01LZ2	 211	//( - , MDuBz2) Исправность АКНП1
#define A0EE03LZ2	 BUFFER[505]	//( - , MDuBz2) Исправность АКНП3
#define idA0EE03LZ2	 212	//( - , MDuBz2) Исправность АКНП3
#define A0EE02LZ2	 BUFFER[507]	//( - , MDuBz2) Исправность АКНП2
#define idA0EE02LZ2	 213	//( - , MDuBz2) Исправность АКНП2
#define B3IC01UDU	 BUFFER[509]	//( - , MDuS) Координата штока ИС2 (дел.энк)
#define idB3IC01UDU	 214	//( - , MDuS) Координата штока ИС2 (дел.энк)
#define B3VC01RDU	 BUFFER[514]	//( - , DU) Координата ИС2, мм
#define idB3VC01RDU	 215	//( - , DU) Координата ИС2, мм
#define A8IC01UDU	 BUFFER[519]	//( - , MDuS) Координата ДС2 (дел.энк)
#define idA8IC01UDU	 216	//( - , MDuS) Координата ДС2 (дел.энк)
#define A8VC01RDU	 BUFFER[524]	//( - , DU) Координата ДС2, мм
#define idA8VC01RDU	 217	//( - , DU) Координата ДС2, мм
#define B8IC01UDU	 BUFFER[529]	//( - , MDuS) Координата АЗ2 (дел.энк)
#define idB8IC01UDU	 218	//( - , MDuS) Координата АЗ2 (дел.энк)
#define A1IC01UDU	 BUFFER[534]	//( - , MDuS) Координата штока ББ1 (дел.энк)
#define idA1IC01UDU	 219	//( - , MDuS) Координата штока ББ1 (дел.энк)
#define A1VC01RDU	 BUFFER[539]	//( - , DU) Координата ББ1, мм
#define idA1VC01RDU	 220	//( - , DU) Координата ББ1, мм
#define A1IS11LDU	 BUFFER[544]	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
#define idA1IS11LDU	 221	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
#define B1MC01LC1	 BUFFER[546]	//( - , DU) Настроить энкодер ББ2
#define idB1MC01LC1	 222	//( - , DU) Настроить энкодер ББ2
#define B1MC01LC2	 BUFFER[548]	//( - , DU) Настроить энкодер ББ2
#define idB1MC01LC2	 223	//( - , DU) Настроить энкодер ББ2
#define A1MC01LC1	 BUFFER[550]	//( - , DU) Настроить энкодер ББ1
#define idA1MC01LC1	 224	//( - , DU) Настроить энкодер ББ1
#define A1MC01LC2	 BUFFER[552]	//( - , DU) Настроить энкодер ББ1
#define idA1MC01LC2	 225	//( - , DU) Настроить энкодер ББ1
#define B2MC01LC1	 BUFFER[554]	//( - , DU) Настроить энкодер РБ2
#define idB2MC01LC1	 226	//( - , DU) Настроить энкодер РБ2
#define B2MC01LC2	 BUFFER[556]	//( - , DU) Настроить энкодер РБ2
#define idB2MC01LC2	 227	//( - , DU) Настроить энкодер РБ2
#define A2MC01LC1	 BUFFER[558]	//( - , DU) Настроить энкодер РБ1
#define idA2MC01LC1	 228	//( - , DU) Настроить энкодер РБ1
#define A2MC01LC2	 BUFFER[560]	//( - , DU) Настроить энкодер РБ1
#define idA2MC01LC2	 229	//( - , DU) Настроить энкодер РБ1
#define B3MC01LC1	 BUFFER[562]	//( - , DU) Настроить энкодер ИС2
#define idB3MC01LC1	 230	//( - , DU) Настроить энкодер ИС2
#define B3MC01LC2	 BUFFER[564]	//( - , DU) Настроить энкодер ИС2
#define idB3MC01LC2	 231	//( - , DU) Настроить энкодер ИС2
#define A3MC01LC1	 BUFFER[566]	//( - , DU) Настроить энкодер ИС1
#define idA3MC01LC1	 232	//( - , DU) Настроить энкодер ИС1
#define A3MC01LC2	 BUFFER[568]	//( - , DU) Настроить энкодер ИС1
#define idA3MC01LC2	 233	//( - , DU) Настроить энкодер ИС1
#define B8MC01LC1	 BUFFER[570]	//( - , DU) Настроить энкодер АЗ2
#define idB8MC01LC1	 234	//( - , DU) Настроить энкодер АЗ2
#define B8MC01LC2	 BUFFER[572]	//( - , DU) Настроить энкодер АЗ2
#define idB8MC01LC2	 235	//( - , DU) Настроить энкодер АЗ2
#define A8MC01LC1	 BUFFER[574]	//( - , DU) Настроить энкодер ДС2
#define idA8MC01LC1	 236	//( - , DU) Настроить энкодер ДС2
#define A8MC01LC2	 BUFFER[576]	//( - , DU) Настроить энкодер ДС2
#define idA8MC01LC2	 237	//( - , DU) Настроить энкодер ДС2
#define B5IE01LDU	 BUFFER[578]	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
#define idB5IE01LDU	 238	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
#define A5IE02LDU	 BUFFER[580]	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
#define idA5IE02LDU	 239	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
#define R1IE01LDU	 BUFFER[582]	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
#define idR1IE01LDU	 240	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
#define R2IE01LDU	 BUFFER[584]	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
#define idR2IE01LDU	 241	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
#define R6IS61LDU	 BUFFER[586]	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
#define idR6IS61LDU	 242	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
#define R6IS64LDU	 BUFFER[588]	//( - , MDuS) Исправность ВИП ССДИ-35 1канал
#define idR6IS64LDU	 243	//( - , MDuS) Исправность ВИП ССДИ-35 1канал
#define R6IS65LDU	 BUFFER[590]	//( - , MDuS) Исправность ВИП ССДИ-35 2канал
#define idR6IS65LDU	 244	//( - , MDuS) Исправность ВИП ССДИ-35 2канал
#define R6IS62LDU	 BUFFER[592]	//( - , MDuS) Исправность ВИП ССДИ-39 1канал
#define idR6IS62LDU	 245	//( - , MDuS) Исправность ВИП ССДИ-39 1канал
#define R6IS63LDU	 BUFFER[594]	//( - , MDuS) Исправность ВИП ССДИ-39 2канал
#define idR6IS63LDU	 246	//( - , MDuS) Исправность ВИП ССДИ-39 2канал
#define R6IS66LZZ	 BUFFER[596]	//( - , MDuS) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 247	//( - , MDuS) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	 BUFFER[598]	//( - , MDuS) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 248	//( - , MDuS) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	 BUFFER[600]	//( - , MDuS) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 249	//( - , MDuS) Исправность ВИП 4,0 (№7) ССДИ-2
#define syn_R0EE03LDU	 BUFFER[602]	//( - , DU) ВПИС ИС
#define idsyn_R0EE03LDU	 250	//( - , DU) ВПИС ИС
#define A3VC01RDU	 BUFFER[604]	//( - , DU) Координата ИС1, мм
#define idA3VC01RDU	 251	//( - , DU) Координата ИС1, мм
#define A2VC01RDU	 BUFFER[609]	//( - , DU) Координата РБ1, мм
#define idA2VC01RDU	 252	//( - , DU) Координата РБ1, мм
#define B2VC01RDU	 BUFFER[614]	//( - , DU) Координата РБ2, мм
#define idB2VC01RDU	 253	//( - , DU) Координата РБ2, мм
#define B8VC01RDU	 BUFFER[619]	//( - , DU) Координата АЗ2, мм
#define idB8VC01RDU	 254	//( - , DU) Координата АЗ2, мм
#define A4VP82LDU	 BUFFER[624]	//( - , MDuS) Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	 255	//( - , MDuS) Давление ПОДЪЁМ НИ1 в норме
#define B4VP82LDU	 BUFFER[626]	//( - , MDuS) Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	 256	//( - , MDuS) Давление ПОДЪЁМ НИ2 в норме
#define A2VP82LDU	 BUFFER[628]	//( - , MDuS) Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	 257	//( - , MDuS) Давление ПОДЪЁМ РБ1 в норме
#define B2VP82LDU	 BUFFER[630]	//( - , MDuS) Давление ПОДЪЁМ РБ2 в норме
#define idB2VP82LDU	 258	//( - , MDuS) Давление ПОДЪЁМ РБ2 в норме
#define A3VP81LDU	 BUFFER[632]	//( - , MDuS) Давление СПУСК ИС1 в норме
#define idA3VP81LDU	 259	//( - , MDuS) Давление СПУСК ИС1 в норме
#define B3VP81LDU	 BUFFER[634]	//( - , MDuS) Давление СПУСК ИС2 в норме
#define idB3VP81LDU	 260	//( - , MDuS) Давление СПУСК ИС2 в норме
#define R0EE02LDU	 BUFFER[636]	//( - , DU) Питание  АКНП  отключить
#define idR0EE02LDU	 261	//( - , DU) Питание  АКНП  отключить
#define A0EE04LZ2	 BUFFER[638]	//( - , MDuBz2) Исправность АКНП4
#define idA0EE04LZ2	 262	//( - , MDuBz2) Исправность АКНП4
#define A0VP71LZ1	 BUFFER[640]	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ1	 263	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
#define A0VP71LZ2	 BUFFER[642]	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ2	 264	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
#define B0VP71LZ1	 BUFFER[644]	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ1	 265	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
#define B0VP71LZ2	 BUFFER[646]	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ2	 266	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
#define A0VS11LDU	 BUFFER[648]	//( - , DU) АЗ1 готова к работе
#define idA0VS11LDU	 267	//( - , DU) АЗ1 готова к работе
#define B0VS11LDU	 BUFFER[650]	//( - , DU) АЗ2 готова к работе
#define idB0VS11LDU	 268	//( - , DU) АЗ2 готова к работе
#define A1IE01LDU	 BUFFER[652]	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
#define idA1IE01LDU	 269	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
#define A3IE01LDU	 BUFFER[654]	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
#define idA3IE01LDU	 270	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
#define A2IE01LDU	 BUFFER[656]	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
#define idA2IE01LDU	 271	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
#define A1IE02LDU	 BUFFER[658]	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
#define idA1IE02LDU	 272	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
#define A3IE02LDU	 BUFFER[660]	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
#define idA3IE02LDU	 273	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
#define A2IE02LDU	 BUFFER[662]	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
#define idA2IE02LDU	 274	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
#define B1IE01LDU	 BUFFER[664]	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
#define idB1IE01LDU	 275	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
#define B2IE01LDU	 BUFFER[666]	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
#define idB2IE01LDU	 276	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
#define B3IE01LDU	 BUFFER[668]	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
#define idB3IE01LDU	 277	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
#define B1IE02LDU	 BUFFER[670]	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
#define idB1IE02LDU	 278	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
#define B3IE02LDU	 BUFFER[672]	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
#define idB3IE02LDU	 279	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
#define B2IE02LDU	 BUFFER[674]	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
#define idB2IE02LDU	 280	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
#define R0IE02LDU	 BUFFER[676]	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
#define idR0IE02LDU	 281	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
#define R0IE01LDU	 BUFFER[678]	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
#define idR0IE01LDU	 282	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
#define A6IE01LDU	 BUFFER[680]	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
#define idA6IE01LDU	 283	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
#define B6IE01LDU	 BUFFER[682]	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
#define idB6IE01LDU	 284	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
#define A8IE01LDU	 BUFFER[684]	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
#define idA8IE01LDU	 285	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
#define R5IS21LDU	 BUFFER[686]	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	 286	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
#define R5VS22LDU	 BUFFER[688]	//( - , DU) Движение ворот отстойной зоны к закрыты
#define idR5VS22LDU	 287	//( - , DU) Движение ворот отстойной зоны к закрыты
#define R5VS12LDU	 BUFFER[690]	//( - , DU) Движение ворот отстойной зоны к открыты
#define idR5VS12LDU	 288	//( - , DU) Движение ворот отстойной зоны к открыты
#define R5VS01IDU	 BUFFER[692]	//( - , DU) Готовность к управлению ворот отстойной зоны
#define idR5VS01IDU	 289	//( - , DU) Готовность к управлению ворот отстойной зоны
#define R3VS22LDU	 BUFFER[695]	//( - , DU) Движение гомогенных дверей к закрыты
#define idR3VS22LDU	 290	//( - , DU) Движение гомогенных дверей к закрыты
#define R3VS12LDU	 BUFFER[697]	//( - , DU) Движение гомогенных дверей к открыты
#define idR3VS12LDU	 291	//( - , DU) Движение гомогенных дверей к открыты
#define R3VS01IDU	 BUFFER[699]	//( - , DU) Готовность к управлению гомогенных дверей
#define idR3VS01IDU	 292	//( - , DU) Готовность к управлению гомогенных дверей
#define A3AB13LDU	 BUFFER[702]	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
#define idA3AB13LDU	 293	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
#define syn_A3VP52LDU	 BUFFER[704]	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define idsyn_A3VP52LDU	 294	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define B3AB13LDU	 BUFFER[706]	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define idB3AB13LDU	 295	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define syn_B3VP52LDU	 BUFFER[708]	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define idsyn_B3VP52LDU	 296	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define R0DE02LDU	 BUFFER[710]	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
#define idR0DE02LDU	 297	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
#define R0DE03LDU	 BUFFER[713]	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
#define idR0DE03LDU	 298	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
#define R0DE04LDU	 BUFFER[716]	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
#define idR0DE04LDU	 299	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
#define R0DE08LDU	 BUFFER[719]	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
#define idR0DE08LDU	 300	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
#define R0DE05LDU	 BUFFER[722]	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
#define idR0DE05LDU	 301	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
#define R0DE09LDU	 BUFFER[725]	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
#define idR0DE09LDU	 302	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
#define R0DE0ALDU	 BUFFER[728]	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
#define idR0DE0ALDU	 303	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
#define R0DE07LDU	 BUFFER[731]	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
#define idR0DE07LDU	 304	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
#define R0DE0CLDU	 BUFFER[734]	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
#define idR0DE0CLDU	 305	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
#define R0DE0BLDU	 BUFFER[737]	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
#define idR0DE0BLDU	 306	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
#define R0DE0DLDU	 BUFFER[740]	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
#define idR0DE0DLDU	 307	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
#define R0DE0FLDU	 BUFFER[743]	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
#define idR0DE0FLDU	 308	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
#define R0DE31LDU	 BUFFER[746]	//(sbk:20 - S01SBK, DiagnDU) диагностика шкафа ДУ сеть 1
#define idR0DE31LDU	 309	//(sbk:20 - S01SBK, DiagnDU) диагностика шкафа ДУ сеть 1
#define R0VN12RDU	 BUFFER[748]	//( - , DU) Заданная мощность РУ
#define idR0VN12RDU	 310	//( - , DU) Заданная мощность РУ
#define R0AB19LDU	 BUFFER[753]	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
#define idR0AB19LDU	 311	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
#define R0CN93LDU	 BUFFER[755]	//( - , DU) время работы на мощности более 100Вт, сек
#define idR0CN93LDU	 312	//( - , DU) время работы на мощности более 100Вт, сек
#define R0CN94LDU	 BUFFER[760]	//( - , DU) Скорость изменения мощности
#define idR0CN94LDU	 313	//( - , DU) Скорость изменения мощности
#define R0CN95LDU	 BUFFER[765]	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
#define idR0CN95LDU	 314	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
#define R0AD03LZ1	 BUFFER[768]	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
#define idR0AD03LZ1	 315	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
#define R0AD03LZ2	 BUFFER[770]	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
#define idR0AD03LZ2	 316	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
#define R0AD04LZ1	 BUFFER[772]	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define idR0AD04LZ1	 317	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define R0AD04LZ2	 BUFFER[774]	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define idR0AD04LZ2	 318	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define R0AD05LZ1	 BUFFER[776]	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
#define idR0AD05LZ1	 319	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
#define R0AD05LZ2	 BUFFER[778]	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
#define idR0AD05LZ2	 320	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
#define B8IS12LDU	 BUFFER[780]	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
#define idB8IS12LDU	 321	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
#define B8IS21LDU	 BUFFER[782]	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
#define idB8IS21LDU	 322	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
#define A1VP41LZ1	 BUFFER[784]	//( - , DU) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ1	 323	//( - , DU) Давление СБРОС ББ1 ниже АС
#define A1VP41LZ2	 BUFFER[786]	//( - , DU) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ2	 324	//( - , DU) Давление СБРОС ББ1 ниже АС
#define R0VL22LDU	 BUFFER[788]	//( - , DU) Конец программы 200сек
#define idR0VL22LDU	 325	//( - , DU) Конец программы 200сек
#define R0VL23LDU	 BUFFER[790]	//( - , DU) Конец программы 20мин
#define idR0VL23LDU	 326	//( - , DU) Конец программы 20мин
#define B1VP41LZ1	 BUFFER[792]	//( - , DU) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ1	 327	//( - , DU) Давление СБРОС ББ2 ниже АС
#define B1VP41LZ2	 BUFFER[794]	//( - , DU) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ2	 328	//( - , DU) Давление СБРОС ББ2 ниже АС
#define A3AB19LDU	 BUFFER[796]	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
#define idA3AB19LDU	 329	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
#define B3AB19LDU	 BUFFER[798]	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
#define idB3AB19LDU	 330	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
#define A3EE03LDU	 BUFFER[800]	//( - , DU) ВПИС ИС1
#define idA3EE03LDU	 331	//( - , DU) ВПИС ИС1
#define B3EE03LDU	 BUFFER[802]	//( - , DU) ВПИС ИС2
#define idB3EE03LDU	 332	//( - , DU) ВПИС ИС2
#define B3AB15LDU	 BUFFER[804]	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
#define idB3AB15LDU	 333	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
#define KKL9	 BUFFER[806]	//( - , - ) 
#define idKKL9	 334	//( - , - ) 
#define hz1	 BUFFER[808]	//( - , - ) 
#define idhz1	 335	//( - , - ) 
#define hz2	 BUFFER[810]	//( - , - ) 
#define idhz2	 336	//( - , - ) 
#define hz3	 BUFFER[812]	//( - , - ) 
#define idhz3	 337	//( - , - ) 
#define hz4	 BUFFER[814]	//( - , - ) 
#define idhz4	 338	//( - , - ) 
#define hz5	 BUFFER[816]	//( - , - ) 
#define idhz5	 339	//( - , - ) 
#define hz6	 BUFFER[818]	//( - , - ) 
#define idhz6	 340	//( - , - ) 
#define bd1	 BUFFER[820]	//( - , - ) 
#define idbd1	 341	//( - , - ) 
#define bd2	 BUFFER[822]	//( - , - ) 
#define idbd2	 342	//( - , - ) 
#define bd3	 BUFFER[824]	//( - , - ) 
#define idbd3	 343	//( - , - ) 
#define bd4	 BUFFER[826]	//( - , - ) 
#define idbd4	 344	//( - , - ) 
#define bd5	 BUFFER[828]	//( - , - ) 
#define idbd5	 345	//( - , - ) 
#define bd6	 BUFFER[830]	//( - , - ) 
#define idbd6	 346	//( - , - ) 
#define a1ab1	 BUFFER[832]	//( - , - ) 
#define ida1ab1	 347	//( - , - ) 
#define a1ab2	 BUFFER[834]	//( - , - ) 
#define ida1ab2	 348	//( - , - ) 
#define a1ab3	 BUFFER[836]	//( - , - ) 
#define ida1ab3	 349	//( - , - ) 
#define a1ab4	 BUFFER[838]	//( - , - ) 
#define ida1ab4	 350	//( - , - ) 
#define a1ab5	 BUFFER[840]	//( - , - ) 
#define ida1ab5	 351	//( - , - ) 
#define B1IC01UDU	 BUFFER[842]	//( - , MDuS) Координата штока ББ2 (дел.энк)
#define idB1IC01UDU	 352	//( - , MDuS) Координата штока ББ2 (дел.энк)
#define B1VC01RDU	 BUFFER[847]	//( - , DU) Координата ББ2, мм
#define idB1VC01RDU	 353	//( - , DU) Координата ББ2, мм
#define B1IS11LDU	 BUFFER[852]	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
#define idB1IS11LDU	 354	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
#define A2IC01UDU	 BUFFER[854]	//( - , MDuS) Координата штока РБ1 (дел.энк)
#define idA2IC01UDU	 355	//( - , MDuS) Координата штока РБ1 (дел.энк)
#define B2IC01UDU	 BUFFER[859]	//( - , MDuS) Координата штока РБ2 (дел.энк)
#define idB2IC01UDU	 356	//( - , MDuS) Координата штока РБ2 (дел.энк)
#define A3IC01UDU	 BUFFER[864]	//( - , MDuS) Координата штока ИС1 (дел.энк)
#define idA3IC01UDU	 357	//( - , MDuS) Координата штока ИС1 (дел.энк)
#define TTLDU	 BUFFER[869]	//( - , DU) ttl
#define idTTLDU	 358	//( - , DU) ttl
#define R0DE32LDU	 BUFFER[872]	//(sbk:20 - S02SBK, DiagnDU) диагностика шкафа ДУ сеть 2
#define idR0DE32LDU	 359	//(sbk:20 - S02SBK, DiagnDU) диагностика шкафа ДУ сеть 2
#define R0DE33LDU	 BUFFER[874]	//(sbk:20 - S03SBK, DiagnDU) диагностика шкафа ДУ двери
#define idR0DE33LDU	 360	//(sbk:20 - S03SBK, DiagnDU) диагностика шкафа ДУ двери
#define R0DE34LDU	 BUFFER[876]	//(sbk:20 - S04SBK, DiagnDU) диагностика шкафа ДУ температура меньше 43
#define idR0DE34LDU	 361	//(sbk:20 - S04SBK, DiagnDU) диагностика шкафа ДУ температура меньше 43
#define R0DE35LDU	 BUFFER[878]	//(sbk:20 - S05SBK, DiagnDU) диагностика шкафа ДУ температура больше 53
#define idR0DE35LDU	 362	//(sbk:20 - S05SBK, DiagnDU) диагностика шкафа ДУ температура больше 53
#define R0DE36LDU	 BUFFER[880]	//(sbk:20 - S06SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 1
#define idR0DE36LDU	 363	//(sbk:20 - S06SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 1
#define R0DE37LDU	 BUFFER[882]	//(sbk:20 - S07SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 2
#define idR0DE37LDU	 364	//(sbk:20 - S07SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 2
#define R0DE38LDU	 BUFFER[884]	//(sbk:20 - S08SBK, DiagnDU) диагностика шкафа ДУ МП15-3 место 3
#define idR0DE38LDU	 365	//(sbk:20 - S08SBK, DiagnDU) диагностика шкафа ДУ МП15-3 место 3
#define R0DE39LDU	 BUFFER[886]	//(sbk:20 - S09SBK, DiagnDU) диагностика шкафа ДУ МП24-2 место 4
#define idR0DE39LDU	 366	//(sbk:20 - S09SBK, DiagnDU) диагностика шкафа ДУ МП24-2 место 4
#define R0DEB3LDU	 BUFFER[888]	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
#define idR0DEB3LDU	 367	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
#define R0DEB2LDU	 BUFFER[890]	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
#define idR0DEB2LDU	 368	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
#define R0DEB1LDU	 BUFFER[892]	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
#define idR0DEB1LDU	 369	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
#define R0DEB4LDU	 BUFFER[894]	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
#define idR0DEB4LDU	 370	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
#define R0DE3DLDU	 BUFFER[896]	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
#define idR0DE3DLDU	 371	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
#define R0DE3CLDU	 BUFFER[898]	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
#define idR0DE3CLDU	 372	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
#define TestDiagnDU	 BUFFER[900]	//( - , DU) Неисправность от
#define idTestDiagnDU	 373	//( - , DU) Неисправность от
#define KKL1	 BUFFER[902]	//( - , - ) 
#define idKKL1	 374	//( - , - ) 
#define KKL2	 BUFFER[904]	//( - , - ) 
#define idKKL2	 375	//( - , - ) 
#define KKL3	 BUFFER[906]	//( - , - ) 
#define idKKL3	 376	//( - , - ) 
#define KKL4	 BUFFER[908]	//( - , - ) 
#define idKKL4	 377	//( - , - ) 
#define KKL5	 BUFFER[910]	//( - , - ) 
#define idKKL5	 378	//( - , - ) 
#define KKL6	 BUFFER[912]	//( - , - ) 
#define idKKL6	 379	//( - , - ) 
#define KKL7	 BUFFER[914]	//( - , - ) 
#define idKKL7	 380	//( - , - ) 
#define KKL8	 BUFFER[916]	//( - , - ) 
#define idKKL8	 381	//( - , - ) 
#define B6AB06LDU	 BUFFER[918]	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
#define idB6AB06LDU	 382	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
#define B6AB07LDU	 BUFFER[920]	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
#define idB6AB07LDU	 383	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
#define B6AB08LDU	 BUFFER[922]	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
#define idB6AB08LDU	 384	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
#define B6AB09LDU	 BUFFER[924]	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
#define idB6AB09LDU	 385	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
#define A6AB05LDU	 BUFFER[926]	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
#define idA6AB05LDU	 386	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
#define B8VS12LDU	 BUFFER[928]	//( - , DU) Движение АЗ2 в сторону ВУ
#define idB8VS12LDU	 387	//( - , DU) Движение АЗ2 в сторону ВУ
#define B8CV01RDU	 BUFFER[930]	//( - , DU) Измеренная скорость перемещения АЗ2
#define idB8CV01RDU	 388	//( - , DU) Измеренная скорость перемещения АЗ2
#define B8AB06LDU	 BUFFER[935]	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
#define idB8AB06LDU	 389	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
#define B8AB07LDU	 BUFFER[937]	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
#define idB8AB07LDU	 390	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
#define B8AB05LDU	 BUFFER[939]	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
#define idB8AB05LDU	 391	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
#define B8VS22LDU	 BUFFER[941]	//( - , DU) Движение АЗ2 в сторону НУ
#define idB8VS22LDU	 392	//( - , DU) Движение АЗ2 в сторону НУ
#define B8AZ03LDU	 BUFFER[943]	//( - , DU) Несанкционированное перемещение АЗ2
#define idB8AZ03LDU	 393	//( - , DU) Несанкционированное перемещение АЗ2
#define R0MD11LP1	 BUFFER[945]	//( - , DU) Кнопка ПУСК
#define idR0MD11LP1	 394	//( - , DU) Кнопка ПУСК
#define B8AD10LDU	 BUFFER[947]	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
#define idB8AD10LDU	 395	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
#define B8AD20LDU	 BUFFER[949]	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
#define idB8AD20LDU	 396	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
#define B8IS11LDU	 BUFFER[951]	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
#define idB8IS11LDU	 397	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
#define B8AB01LDU	 BUFFER[953]	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
#define idB8AB01LDU	 398	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
#define B8AB04LDU	 BUFFER[955]	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
#define idB8AB04LDU	 399	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
#define B8AB08LDU	 BUFFER[957]	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
#define idB8AB08LDU	 400	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
#define B8AB09LDU	 BUFFER[959]	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
#define idB8AB09LDU	 401	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
#define B8AB10LDU	 BUFFER[961]	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
#define idB8AB10LDU	 402	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
#define B8AB11LDU	 BUFFER[963]	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
#define idB8AB11LDU	 403	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
#define B8AB12LDU	 BUFFER[965]	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
#define idB8AB12LDU	 404	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
#define B5AZ03LDU	 BUFFER[967]	//( - , DU) Несанкционированное перемещение НЛ2
#define idB5AZ03LDU	 405	//( - , DU) Несанкционированное перемещение НЛ2
#define B5AB01LDU	 BUFFER[969]	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
#define idB5AB01LDU	 406	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
#define B5AB02LDU	 BUFFER[971]	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
#define idB5AB02LDU	 407	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
#define A4IS21LDU	 BUFFER[973]	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
#define idA4IS21LDU	 408	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
#define B4IS21LDU	 BUFFER[975]	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
#define idB4IS21LDU	 409	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
#define B4AD10LDU	 BUFFER[977]	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
#define idB4AD10LDU	 410	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
#define A4AD10LDU	 BUFFER[979]	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
#define idA4AD10LDU	 411	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
#define A4AZ03LDU	 BUFFER[981]	//( - , DU) Несанкционированное перемещение НИ1
#define idA4AZ03LDU	 412	//( - , DU) Несанкционированное перемещение НИ1
#define A4AB01LDU	 BUFFER[983]	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
#define idA4AB01LDU	 413	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
#define A4AB02LDU	 BUFFER[985]	//( - , DU) Блокировка движения НИ1 - Нет перемещения
#define idA4AB02LDU	 414	//( - , DU) Блокировка движения НИ1 - Нет перемещения
#define B4AZ03LDU	 BUFFER[987]	//( - , DU) Несанкционированное перемещение НИ2
#define idB4AZ03LDU	 415	//( - , DU) Несанкционированное перемещение НИ2
#define B4AB01LDU	 BUFFER[989]	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
#define idB4AB01LDU	 416	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
#define B4AB02LDU	 BUFFER[991]	//( - , DU) Блокировка движения НИ2 - Нет перемещения
#define idB4AB02LDU	 417	//( - , DU) Блокировка движения НИ2 - Нет перемещения
#define A5AB04LDU	 BUFFER[993]	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
#define idA5AB04LDU	 418	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
#define B5AB04LDU	 BUFFER[995]	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
#define idB5AB04LDU	 419	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
#define A1IS12LDU	 BUFFER[997]	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
#define idA1IS12LDU	 420	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
#define A2IS12LDU	 BUFFER[999]	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
#define idA2IS12LDU	 421	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
#define B1IS12LDU	 BUFFER[1001]	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
#define idB1IS12LDU	 422	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
#define B2IS12LDU	 BUFFER[1003]	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
#define idB2IS12LDU	 423	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
#define R4IS11LDU	 BUFFER[1005]	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
#define idR4IS11LDU	 424	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
#define A6AB06LDU	 BUFFER[1007]	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
#define idA6AB06LDU	 425	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
#define A6AB07LDU	 BUFFER[1009]	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
#define idA6AB07LDU	 426	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
#define A6AB08LDU	 BUFFER[1011]	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
#define idA6AB08LDU	 427	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
#define A6AB09LDU	 BUFFER[1013]	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
#define idA6AB09LDU	 428	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
#define A8AB01LDU	 BUFFER[1015]	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
#define idA8AB01LDU	 429	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
#define A2VS11LDU	 BUFFER[1017]	//( - , DU) Движение РБ1 в сторону ВУ
#define idA2VS11LDU	 430	//( - , DU) Движение РБ1 в сторону ВУ
#define A2CV01RDU	 BUFFER[1019]	//( - , DU) Измеренная скорость перемещения РБ1
#define idA2CV01RDU	 431	//( - , DU) Измеренная скорость перемещения РБ1
#define A2AB04LDU	 BUFFER[1024]	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
#define idA2AB04LDU	 432	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
#define A2AB02LDU	 BUFFER[1026]	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
#define idA2AB02LDU	 433	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
#define A2AB01LDU	 BUFFER[1028]	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
#define idA2AB01LDU	 434	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
#define A2VS21LDU	 BUFFER[1030]	//( - , DU) Движение РБ1 в сторону НУ
#define idA2VS21LDU	 435	//( - , DU) Движение РБ1 в сторону НУ
#define A2AZ03LDU	 BUFFER[1032]	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
#define idA2AZ03LDU	 436	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
#define A2AD11LDU	 BUFFER[1034]	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	 437	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
#define A2AD21LDU	 BUFFER[1036]	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	 438	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
#define A2AD02LDU	 BUFFER[1038]	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
#define idA2AD02LDU	 439	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
#define A2AD03LDU	 BUFFER[1040]	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
#define idA2AD03LDU	 440	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
#define A2AD04LDU	 BUFFER[1042]	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
#define idA2AD04LDU	 441	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
#define A2AD05LDU	 BUFFER[1044]	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
#define idA2AD05LDU	 442	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
#define A2AB07LDU	 BUFFER[1046]	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
#define idA2AB07LDU	 443	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
#define A2AB08LDU	 BUFFER[1048]	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
#define idA2AB08LDU	 444	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
#define A2AB05LDU	 BUFFER[1050]	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
#define idA2AB05LDU	 445	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
#define A2AB06LDU	 BUFFER[1052]	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
#define idA2AB06LDU	 446	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
#define A2AB09LDU	 BUFFER[1054]	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
#define idA2AB09LDU	 447	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
#define A2AB10LDU	 BUFFER[1056]	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
#define idA2AB10LDU	 448	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
#define A2AB11LDU	 BUFFER[1058]	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
#define idA2AB11LDU	 449	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
#define A2AB12LDU	 BUFFER[1060]	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA2AB12LDU	 450	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A2AB13LDU	 BUFFER[1062]	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
#define idA2AB13LDU	 451	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
#define A2AB14LDU	 BUFFER[1064]	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
#define idA2AB14LDU	 452	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
#define B8AB13LDU	 BUFFER[1066]	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
#define idB8AB13LDU	 453	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
#define B8AB14LDU	 BUFFER[1068]	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
#define idB8AB14LDU	 454	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
#define B8AB02LDU	 BUFFER[1070]	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
#define idB8AB02LDU	 455	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
#define A8VS12LDU	 BUFFER[1072]	//( - , DU) Движение ДС2 в сторону ВУ
#define idA8VS12LDU	 456	//( - , DU) Движение ДС2 в сторону ВУ
#define A8CV01RDU	 BUFFER[1074]	//( - , DU) Измеренная скорость перемещения ДС2
#define idA8CV01RDU	 457	//( - , DU) Измеренная скорость перемещения ДС2
#define A8AB06LDU	 BUFFER[1079]	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
#define idA8AB06LDU	 458	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
#define A8AB07LDU	 BUFFER[1081]	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
#define idA8AB07LDU	 459	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
#define A8AB05LDU	 BUFFER[1083]	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
#define idA8AB05LDU	 460	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
#define A8VS22LDU	 BUFFER[1085]	//( - , DU) Движение ДС2 в сторону НУ
#define idA8VS22LDU	 461	//( - , DU) Движение ДС2 в сторону НУ
#define A8AZ03LDU	 BUFFER[1087]	//( - , DU) Несанкционированное перемещение ДС2
#define idA8AZ03LDU	 462	//( - , DU) Несанкционированное перемещение ДС2
#define A8AD10LDU	 BUFFER[1089]	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
#define idA8AD10LDU	 463	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
#define A8AD20LDU	 BUFFER[1091]	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
#define idA8AD20LDU	 464	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
#define B8IS22LDU	 BUFFER[1093]	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
#define idB8IS22LDU	 465	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
#define A8IS12LDU	 BUFFER[1095]	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
#define idA8IS12LDU	 466	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
#define A8AB04LDU	 BUFFER[1097]	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
#define idA8AB04LDU	 467	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
#define A8IS22LDU	 BUFFER[1099]	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
#define idA8IS22LDU	 468	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
#define A8AB08LDU	 BUFFER[1101]	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define idA8AB08LDU	 469	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define A8AB09LDU	 BUFFER[1103]	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
#define idA8AB09LDU	 470	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
#define A8AB10LDU	 BUFFER[1105]	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
#define idA8AB10LDU	 471	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
#define A8AB11LDU	 BUFFER[1107]	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
#define idA8AB11LDU	 472	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
#define A8AB12LDU	 BUFFER[1109]	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
#define idA8AB12LDU	 473	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
#define A8AB13LDU	 BUFFER[1111]	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
#define idA8AB13LDU	 474	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
#define A8AB14LDU	 BUFFER[1113]	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
#define idA8AB14LDU	 475	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
#define A8AB02LDU	 BUFFER[1115]	//( - , DU) Блокировка движения ДС2- АНИ не установлен
#define idA8AB02LDU	 476	//( - , DU) Блокировка движения ДС2- АНИ не установлен
#define A6VS22LDU	 BUFFER[1117]	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
#define idA6VS22LDU	 477	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
#define A6VS12LDU	 BUFFER[1119]	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
#define idA6VS12LDU	 478	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
#define B6VS22LDU	 BUFFER[1121]	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
#define idB6VS22LDU	 479	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
#define B6VS12LDU	 BUFFER[1123]	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
#define idB6VS12LDU	 480	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
#define A6AD10LDU	 BUFFER[1125]	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
#define idA6AD10LDU	 481	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
#define A6AD20LDU	 BUFFER[1127]	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
#define idA6AD20LDU	 482	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
#define B6AD10LDU	 BUFFER[1129]	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
#define idB6AD10LDU	 483	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
#define B6AD20LDU	 BUFFER[1131]	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
#define idB6AD20LDU	 484	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
#define A6AZ03LDU	 BUFFER[1133]	//( - , DU) Несанкционированное перемещение БЗ1
#define idA6AZ03LDU	 485	//( - , DU) Несанкционированное перемещение БЗ1
#define A6AB01LDU	 BUFFER[1135]	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
#define idA6AB01LDU	 486	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
#define A6AB02LDU	 BUFFER[1137]	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
#define idA6AB02LDU	 487	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
#define B6AZ03LDU	 BUFFER[1139]	//( - , DU) Несанкционированное перемещение БЗ2
#define idB6AZ03LDU	 488	//( - , DU) Несанкционированное перемещение БЗ2
#define B6AB01LDU	 BUFFER[1141]	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
#define idB6AB01LDU	 489	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
#define B6AB02LDU	 BUFFER[1143]	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
#define idB6AB02LDU	 490	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
#define A6AB04LDU	 BUFFER[1145]	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
#define idA6AB04LDU	 491	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
#define B6AB04LDU	 BUFFER[1147]	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
#define idB6AB04LDU	 492	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
#define R4AB01LDU	 BUFFER[1149]	//( - , DU) Блокировка движения тележки - АНИ не установлен
#define idR4AB01LDU	 493	//( - , DU) Блокировка движения тележки - АНИ не установлен
#define R8IS11LDU	 BUFFER[1151]	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
#define idR8IS11LDU	 494	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
#define R6IS21LDU	 BUFFER[1153]	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
#define idR6IS21LDU	 495	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
#define A0VN71LZ2	 BUFFER[1155]	//( - , MDuBz2) АЗ по АС мощности для АЗ1
#define idA0VN71LZ2	 496	//( - , MDuBz2) АЗ по АС мощности для АЗ1
#define A0VN71LZ1	 BUFFER[1157]	//( - , MDuBz1) АЗ по АС мощности для АЗ1
#define idA0VN71LZ1	 497	//( - , MDuBz1) АЗ по АС мощности для АЗ1
#define R0NE01LDU	 BUFFER[1159]	//( - , DU) Потеря связи с БАЗ1
#define idR0NE01LDU	 498	//( - , DU) Потеря связи с БАЗ1
#define R0NE02LDU	 BUFFER[1161]	//( - , DU) Потеря связи с БАЗ2
#define idR0NE02LDU	 499	//( - , DU) Потеря связи с БАЗ2
#define R0MW15IP1	 BUFFER[1163]	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
#define idR0MW15IP1	 500	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
#define R0MW14IP1	 BUFFER[1166]	//( - , DU) Переключатель ПРОГРАММЫ
#define idR0MW14IP1	 501	//( - , DU) Переключатель ПРОГРАММЫ
#define R0MW12IP1	 BUFFER[1169]	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
#define idR0MW12IP1	 502	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
#define R0MW13IP1	 BUFFER[1172]	//( - , DU) Переключатель ВЫБОР ЗОН
#define idR0MW13IP1	 503	//( - , DU) Переключатель ВЫБОР ЗОН
#define R0MW16IP1	 BUFFER[1175]	//( - , DU) Переключатель ВИД ПРОВЕРКИ
#define idR0MW16IP1	 504	//( - , DU) Переключатель ВИД ПРОВЕРКИ
#define R0MW11IP1	 BUFFER[1178]	//( - , DU) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	 505	//( - , DU) Переключатель ВЫСТРЕЛ
#define R0MW11IP2	 BUFFER[1181]	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
#define idR0MW11IP2	 506	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
#define R0MW13LP2	 BUFFER[1184]	//( - , DU) Переключатель СЕТЬ
#define idR0MW13LP2	 507	//( - , DU) Переключатель СЕТЬ
#define R0MD32LP1	 BUFFER[1186]	//( - , DU) Кнопка СПУСК
#define idR0MD32LP1	 508	//( - , DU) Кнопка СПУСК
#define R0MD31LP1	 BUFFER[1188]	//( - , DU) Кнопка СТОП
#define idR0MD31LP1	 509	//( - , DU) Кнопка СТОП
#define A1IS21LDU	 BUFFER[1190]	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
#define idA1IS21LDU	 510	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
#define A2IS21LDU	 BUFFER[1192]	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
#define idA2IS21LDU	 511	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
#define A3IS21LDU	 BUFFER[1194]	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
#define idA3IS21LDU	 512	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
#define B1IS21LDU	 BUFFER[1196]	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
#define idB1IS21LDU	 513	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
#define B2IS21LDU	 BUFFER[1198]	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
#define idB2IS21LDU	 514	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
#define B3IS21LDU	 BUFFER[1200]	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
#define idB3IS21LDU	 515	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
#define R0ES01LDU	 BUFFER[1202]	//( - , DU) ОРР не в исходном состоянии
#define idR0ES01LDU	 516	//( - , DU) ОРР не в исходном состоянии
#define R4MD11LP2	 BUFFER[1204]	//( - , DU) Кнопка ВПЕРЁД  (тележки)
#define idR4MD11LP2	 517	//( - , DU) Кнопка ВПЕРЁД  (тележки)
#define R4MD31LP2	 BUFFER[1206]	//( - , DU) Кнопка СТОП  (тележки)
#define idR4MD31LP2	 518	//( - , DU) Кнопка СТОП  (тележки)
#define R4MD21LP2	 BUFFER[1208]	//( - , DU) Кнопка НАЗАД  (тележки)
#define idR4MD21LP2	 519	//( - , DU) Кнопка НАЗАД  (тележки)
#define A6IS11LDU	 BUFFER[1210]	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
#define idA6IS11LDU	 520	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
#define A6IS21LDU	 BUFFER[1212]	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
#define idA6IS21LDU	 521	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
#define B6IS11LDU	 BUFFER[1214]	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
#define idB6IS11LDU	 522	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
#define B6IS21LDU	 BUFFER[1216]	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
#define idB6IS21LDU	 523	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
#define R4AB13LDU	 BUFFER[1218]	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
#define idR4AB13LDU	 524	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
#define R4AB14LDU	 BUFFER[1220]	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
#define idR4AB14LDU	 525	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
#define R4AB15LDU	 BUFFER[1222]	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
#define idR4AB15LDU	 526	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
#define R5IS11LDU	 BUFFER[1224]	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	 527	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
#define R4AB16LDU	 BUFFER[1226]	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
#define idR4AB16LDU	 528	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
#define R4AB17LDU	 BUFFER[1228]	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define idR4AB17LDU	 529	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define R4AB18LDU	 BUFFER[1230]	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define idR4AB18LDU	 530	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define R4AD10LDU	 BUFFER[1232]	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
#define idR4AD10LDU	 531	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
#define R4AD20LDU	 BUFFER[1234]	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
#define idR4AD20LDU	 532	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
#define A5VS22LDU	 BUFFER[1236]	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
#define idA5VS22LDU	 533	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
#define A5VS12LDU	 BUFFER[1238]	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
#define idA5VS12LDU	 534	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
#define B5VS22LDU	 BUFFER[1240]	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
#define idB5VS22LDU	 535	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
#define B5VS12LDU	 BUFFER[1242]	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
#define idB5VS12LDU	 536	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
#define B5AD10LDU	 BUFFER[1244]	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
#define idB5AD10LDU	 537	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
#define B5AD20LDU	 BUFFER[1246]	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
#define idB5AD20LDU	 538	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
#define A5AD10LDU	 BUFFER[1248]	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
#define idA5AD10LDU	 539	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
#define A5AD20LDU	 BUFFER[1250]	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
#define idA5AD20LDU	 540	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
#define A5IS11LDU	 BUFFER[1252]	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
#define idA5IS11LDU	 541	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
#define A5IS21LDU	 BUFFER[1254]	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
#define idA5IS21LDU	 542	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
#define B5IS11LDU	 BUFFER[1256]	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
#define idB5IS11LDU	 543	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
#define B5IS21LDU	 BUFFER[1258]	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
#define idB5IS21LDU	 544	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
#define A5AZ03LDU	 BUFFER[1260]	//( - , DU) Несанкционированное перемещение НЛ1
#define idA5AZ03LDU	 545	//( - , DU) Несанкционированное перемещение НЛ1
#define A5AB01LDU	 BUFFER[1262]	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
#define idA5AB01LDU	 546	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
#define A5AB02LDU	 BUFFER[1264]	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
#define idA5AB02LDU	 547	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
#define R4AB02LDU	 BUFFER[1266]	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
#define idR4AB02LDU	 548	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
#define R0NE08LDU	 BUFFER[1268]	//( - , DU) Потеря связи с ОПУ
#define idR0NE08LDU	 549	//( - , DU) Потеря связи с ОПУ
#define R4IS21LDU	 BUFFER[1270]	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
#define idR4IS21LDU	 550	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
#define R4IS22LDU	 BUFFER[1272]	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
#define idR4IS22LDU	 551	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
#define R4IS12LDU	 BUFFER[1274]	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
#define idR4IS12LDU	 552	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
#define R4VS22LDU	 BUFFER[1276]	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
#define idR4VS22LDU	 553	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
#define R4VS12LDU	 BUFFER[1278]	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
#define idR4VS12LDU	 554	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
#define R4AZ03LDU	 BUFFER[1280]	//( - , DU) Несанкционированное перемещение тележки
#define idR4AZ03LDU	 555	//( - , DU) Несанкционированное перемещение тележки
#define R4AB03LDU	 BUFFER[1282]	//( - , DU) Блокировка движения тележки - Самоход любого механизма
#define idR4AB03LDU	 556	//( - , DU) Блокировка движения тележки - Самоход любого механизма
#define R1IS21LDU	 BUFFER[1284]	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
#define idR1IS21LDU	 557	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
#define R2IS21LDU	 BUFFER[1286]	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
#define idR2IS21LDU	 558	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
#define R4AB04LDU	 BUFFER[1288]	//( - , DU) Блокировка движения тележки - Превышение времени движения
#define idR4AB04LDU	 559	//( - , DU) Блокировка движения тележки - Превышение времени движения
#define R4AB05LDU	 BUFFER[1290]	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
#define idR4AB05LDU	 560	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
#define R4AB06LDU	 BUFFER[1292]	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
#define idR4AB06LDU	 561	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
#define R4AB07LDU	 BUFFER[1294]	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
#define idR4AB07LDU	 562	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
#define R4AB08LDU	 BUFFER[1296]	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define idR4AB08LDU	 563	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define R4AB09LDU	 BUFFER[1298]	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
#define idR4AB09LDU	 564	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
#define B0VN71LZ1	 BUFFER[1300]	//( - , MDuBz1) АЗ по АС мощности для АЗ2
#define idB0VN71LZ1	 565	//( - , MDuBz1) АЗ по АС мощности для АЗ2
#define B0VN71LZ2	 BUFFER[1302]	//( - , MDuBz2) АЗ по АС мощности для АЗ2
#define idB0VN71LZ2	 566	//( - , MDuBz2) АЗ по АС мощности для АЗ2
#define R4AB10LDU	 BUFFER[1304]	//( - , DU) Блокировка тележки - не открыта биологическая защита
#define idR4AB10LDU	 567	//( - , DU) Блокировка тележки - не открыта биологическая защита
#define R4AB11LDU	 BUFFER[1306]	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
#define idR4AB11LDU	 568	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
#define R4AB12LDU	 BUFFER[1308]	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
#define idR4AB12LDU	 569	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
#define A4IS11LDU	 BUFFER[1310]	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
#define idA4IS11LDU	 570	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
#define B4IS11LDU	 BUFFER[1312]	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
#define idB4IS11LDU	 571	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
#define A3AB09LDU	 BUFFER[1314]	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
#define idA3AB09LDU	 572	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
#define A3AB10LDU	 BUFFER[1316]	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
#define idA3AB10LDU	 573	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
#define A3AB11LDU	 BUFFER[1318]	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
#define idA3AB11LDU	 574	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
#define A3AB12LDU	 BUFFER[1320]	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA3AB12LDU	 575	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A3AB14LDU	 BUFFER[1322]	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
#define idA3AB14LDU	 576	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
#define A3AB16LDU	 BUFFER[1324]	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
#define idA3AB16LDU	 577	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
#define A3AB17LDU	 BUFFER[1326]	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
#define idA3AB17LDU	 578	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
#define A3AB18LDU	 BUFFER[1328]	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
#define idA3AB18LDU	 579	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
#define A3AB20LDU	 BUFFER[1330]	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
#define idA3AB20LDU	 580	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
#define B3VS12LDU	 BUFFER[1332]	//( - , DU) Движение ИС2 в сторону ВУ
#define idB3VS12LDU	 581	//( - , DU) Движение ИС2 в сторону ВУ
#define B3CV01RDU	 BUFFER[1334]	//( - , DU) Измеренная скорость перемещения ИС2
#define idB3CV01RDU	 582	//( - , DU) Измеренная скорость перемещения ИС2
#define B3AB04LDU	 BUFFER[1339]	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
#define idB3AB04LDU	 583	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
#define B3AB02LDU	 BUFFER[1341]	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
#define idB3AB02LDU	 584	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
#define B3AB01LDU	 BUFFER[1343]	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
#define idB3AB01LDU	 585	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
#define B3VS22LDU	 BUFFER[1345]	//( - , DU) Движение ИС2 в сторону НУ
#define idB3VS22LDU	 586	//( - , DU) Движение ИС2 в сторону НУ
#define B3AZ03LDU	 BUFFER[1347]	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
#define idB3AZ03LDU	 587	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
#define B3AD11LDU	 BUFFER[1349]	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	 588	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
#define B3AD21LDU	 BUFFER[1351]	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	 589	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
#define B3AD02LDU	 BUFFER[1353]	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
#define idB3AD02LDU	 590	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
#define B3AD03LDU	 BUFFER[1355]	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
#define idB3AD03LDU	 591	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
#define B3AD04LDU	 BUFFER[1357]	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
#define idB3AD04LDU	 592	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
#define B3AD05LDU	 BUFFER[1359]	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
#define idB3AD05LDU	 593	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
#define B3AD01LDU	 BUFFER[1361]	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
#define idB3AD01LDU	 594	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
#define B1AB13LDU	 BUFFER[1363]	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
#define idB1AB13LDU	 595	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
#define B1AB14LDU	 BUFFER[1365]	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
#define idB1AB14LDU	 596	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
#define B1AB16LDU	 BUFFER[1367]	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
#define idB1AB16LDU	 597	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
#define B1AB17LDU	 BUFFER[1369]	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
#define idB1AB17LDU	 598	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
#define B1AB18LDU	 BUFFER[1371]	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
#define idB1AB18LDU	 599	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
#define A3VS12LDU	 BUFFER[1373]	//( - , DU) Движение ИС1 в сторону ВУ
#define idA3VS12LDU	 600	//( - , DU) Движение ИС1 в сторону ВУ
#define A3CV01RDU	 BUFFER[1375]	//( - , DU) Измеренная скорость перемещения ИС1
#define idA3CV01RDU	 601	//( - , DU) Измеренная скорость перемещения ИС1
#define A3AB04LDU	 BUFFER[1380]	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
#define idA3AB04LDU	 602	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
#define A3AB02LDU	 BUFFER[1382]	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
#define idA3AB02LDU	 603	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
#define A3AB01LDU	 BUFFER[1384]	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
#define idA3AB01LDU	 604	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
#define A3VS22LDU	 BUFFER[1386]	//( - , DU) Движение ИС1 в сторону НУ
#define idA3VS22LDU	 605	//( - , DU) Движение ИС1 в сторону НУ
#define A3AZ03LDU	 BUFFER[1388]	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
#define idA3AZ03LDU	 606	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
#define A3AD11LDU	 BUFFER[1390]	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	 607	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
#define A3AD21LDU	 BUFFER[1392]	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	 608	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
#define A3AD02LDU	 BUFFER[1394]	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
#define idA3AD02LDU	 609	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
#define A3AD03LDU	 BUFFER[1396]	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
#define idA3AD03LDU	 610	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
#define A3AD04LDU	 BUFFER[1398]	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
#define idA3AD04LDU	 611	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
#define A3AD05LDU	 BUFFER[1400]	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
#define idA3AD05LDU	 612	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
#define A3AD01LDU	 BUFFER[1402]	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
#define idA3AD01LDU	 613	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
#define A3CV02RDU	 BUFFER[1404]	//( - , DU) Заданная скорость перемещения ИС1
#define idA3CV02RDU	 614	//( - , DU) Заданная скорость перемещения ИС1
#define A3AB07LDU	 BUFFER[1409]	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
#define idA3AB07LDU	 615	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
#define A3AB08LDU	 BUFFER[1411]	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
#define idA3AB08LDU	 616	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
#define A3AB05LDU	 BUFFER[1413]	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
#define idA3AB05LDU	 617	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
#define A3AB06LDU	 BUFFER[1415]	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
#define idA3AB06LDU	 618	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
#define R0MD11LP2	 BUFFER[1417]	//( - , DU) Кнопка Пуск проверки схем сброса
#define idR0MD11LP2	 619	//( - , DU) Кнопка Пуск проверки схем сброса
#define R0VX01LDU	 BUFFER[1419]	//( - , DU) ДО ИМПУЛЬСА
#define idR0VX01LDU	 620	//( - , DU) ДО ИМПУЛЬСА
#define R0VL01IDU	 BUFFER[1421]	//( - , DU) До импульса минут
#define idR0VL01IDU	 621	//( - , DU) До импульса минут
#define R0VL11IDU	 BUFFER[1424]	//( - , DU) До импульса секунд
#define idR0VL11IDU	 622	//( - , DU) До импульса секунд
#define R0VL06RDU	 BUFFER[1427]	//( - , DU) Индикация (Время задержки от ВУ РБ)
#define idR0VL06RDU	 623	//( - , DU) Индикация (Время задержки от ВУ РБ)
#define B3AD33LDU	 BUFFER[1432]	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 закрыть (обесточить)
#define idB3AD33LDU	 624	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 закрыть (обесточить)
#define B3IS11LDU	 BUFFER[1434]	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
#define idB3IS11LDU	 625	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
#define R0VL02RDU	 BUFFER[1436]	//( - , DU) Индикация (Время задержки ИНИ)
#define idR0VL02RDU	 626	//( - , DU) Индикация (Время задержки ИНИ)
#define R8AD21LDU	 BUFFER[1441]	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
#define idR8AD21LDU	 627	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
#define R0AD14LDU	 BUFFER[1443]	//( - , DU) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 628	//( - , DU) Имитация срабатывания верхней АС II УР
#define R0VL04RDU	 BUFFER[1445]	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
#define idR0VL04RDU	 629	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
#define R0AB04LDU	 BUFFER[1450]	//( - , DU) Нарушение времени срабатывания верхней АС II УР
#define idR0AB04LDU	 630	//( - , DU) Нарушение времени срабатывания верхней АС II УР
#define R0AB06LDU	 BUFFER[1452]	//( - , DU) Нарушение времени задержки от ВУ РБ
#define idR0AB06LDU	 631	//( - , DU) Нарушение времени задержки от ВУ РБ
#define R0AB02LDU	 BUFFER[1454]	//( - , DU) Нарушение времени задержки ИНИ
#define idR0AB02LDU	 632	//( - , DU) Нарушение времени задержки ИНИ
#define R0VL03RDU	 BUFFER[1456]	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define idR0VL03RDU	 633	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define R0VL05RDU	 BUFFER[1461]	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
#define idR0VL05RDU	 634	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
#define R0VL21IDU	 BUFFER[1466]	//( - , DU) Декатрон
#define idR0VL21IDU	 635	//( - , DU) Декатрон
#define R0VX03LDU	 BUFFER[1469]	//( - , DU) Готовность 2 мин
#define idR0VX03LDU	 636	//( - , DU) Готовность 2 мин
#define R0VS21IDU	 BUFFER[1471]	//( - , DU) Индикация ВИД ПРОВЕРКИ
#define idR0VS21IDU	 637	//( - , DU) Индикация ВИД ПРОВЕРКИ
#define A1VS01IDU	 BUFFER[1474]	//( - , DU) Готовность к управлению ББ1
#define idA1VS01IDU	 638	//( - , DU) Готовность к управлению ББ1
#define B1VS01IDU	 BUFFER[1477]	//( - , DU) Готовность к управлению ББ2
#define idB1VS01IDU	 639	//( - , DU) Готовность к управлению ББ2
#define A3VS01IDU	 BUFFER[1480]	//( - , DU) Готовность к управлению ИС1
#define idA3VS01IDU	 640	//( - , DU) Готовность к управлению ИС1
#define B3VS01IDU	 BUFFER[1483]	//( - , DU) Готовность к управлению ИС2
#define idB3VS01IDU	 641	//( - , DU) Готовность к управлению ИС2
#define A2VS01IDU	 BUFFER[1486]	//( - , DU) Готовность к управлению РБ1
#define idA2VS01IDU	 642	//( - , DU) Готовность к управлению РБ1
#define B3CV02RDU	 BUFFER[1489]	//( - , DU) Заданная скорость перемещения ИС2
#define idB3CV02RDU	 643	//( - , DU) Заданная скорость перемещения ИС2
#define B3AB07LDU	 BUFFER[1494]	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
#define idB3AB07LDU	 644	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
#define B3AB08LDU	 BUFFER[1496]	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
#define idB3AB08LDU	 645	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
#define B3AB05LDU	 BUFFER[1498]	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
#define idB3AB05LDU	 646	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
#define B3AB06LDU	 BUFFER[1500]	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
#define idB3AB06LDU	 647	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
#define B3AB09LDU	 BUFFER[1502]	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
#define idB3AB09LDU	 648	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
#define B3AB10LDU	 BUFFER[1504]	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
#define idB3AB10LDU	 649	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
#define B3AB11LDU	 BUFFER[1506]	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
#define idB3AB11LDU	 650	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
#define B3AB12LDU	 BUFFER[1508]	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define idB3AB12LDU	 651	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define B3AB14LDU	 BUFFER[1510]	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
#define idB3AB14LDU	 652	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
#define B3AB16LDU	 BUFFER[1512]	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
#define idB3AB16LDU	 653	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
#define B3AB17LDU	 BUFFER[1514]	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
#define idB3AB17LDU	 654	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
#define B3AB18LDU	 BUFFER[1516]	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
#define idB3AB18LDU	 655	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
#define B3AB20LDU	 BUFFER[1518]	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
#define idB3AB20LDU	 656	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
#define C1MD31LP1	 BUFFER[1520]	//( - , DU) Кнопка СБРОС ББ
#define idC1MD31LP1	 657	//( - , DU) Кнопка СБРОС ББ
#define C1MD31LP2	 BUFFER[1522]	//( - , DU) Кнопка СБРОС ББ
#define idC1MD31LP2	 658	//( - , DU) Кнопка СБРОС ББ
#define A2AD31LDU	 BUFFER[1524]	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
#define idA2AD31LDU	 659	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
#define B2AD31LDU	 BUFFER[1526]	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
#define idB2AD31LDU	 660	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
#define A1AD31LDU	 BUFFER[1528]	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
#define idA1AD31LDU	 661	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
#define B1AD31LDU	 BUFFER[1530]	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
#define idB1AD31LDU	 662	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
#define A2AD32LDU	 BUFFER[1532]	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
#define idA2AD32LDU	 663	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
#define B2AD32LDU	 BUFFER[1534]	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
#define idB2AD32LDU	 664	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
#define A1AD32LDU	 BUFFER[1536]	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
#define idA1AD32LDU	 665	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
#define B1AD32LDU	 BUFFER[1538]	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
#define idB1AD32LDU	 666	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
#define B2AB12LDU	 BUFFER[1540]	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define idB2AB12LDU	 667	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define B2AB13LDU	 BUFFER[1542]	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
#define idB2AB13LDU	 668	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
#define B2AB14LDU	 BUFFER[1544]	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
#define idB2AB14LDU	 669	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
#define B2AB16LDU	 BUFFER[1546]	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
#define idB2AB16LDU	 670	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
#define B2AB17LDU	 BUFFER[1548]	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
#define idB2AB17LDU	 671	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
#define R1AZ03LDU	 BUFFER[1550]	//( - , DU) Несанкционированное перемещение МДЗ1
#define idR1AZ03LDU	 672	//( - , DU) Несанкционированное перемещение МДЗ1
#define R1AB01LDU	 BUFFER[1552]	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
#define idR1AB01LDU	 673	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
#define R1AB02LDU	 BUFFER[1554]	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
#define idR1AB02LDU	 674	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
#define R2AZ03LDU	 BUFFER[1556]	//( - , DU) Несанкционированное перемещение МДЗ2
#define idR2AZ03LDU	 675	//( - , DU) Несанкционированное перемещение МДЗ2
#define R2AB01LDU	 BUFFER[1558]	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
#define idR2AB01LDU	 676	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
#define R2AB02LDU	 BUFFER[1560]	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
#define idR2AB02LDU	 677	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
#define R1AB04LDU	 BUFFER[1562]	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
#define idR1AB04LDU	 678	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
#define R2AB04LDU	 BUFFER[1564]	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
#define idR2AB04LDU	 679	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
#define R1AD10LDU	 BUFFER[1566]	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
#define idR1AD10LDU	 680	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
#define R1AD20LDU	 BUFFER[1568]	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
#define idR1AD20LDU	 681	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
#define R1IS11LDU	 BUFFER[1570]	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
#define idR1IS11LDU	 682	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
#define R1VS22LDU	 BUFFER[1572]	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	 683	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
#define R2VS22LDU	 BUFFER[1574]	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	 684	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
#define R2VS12LDU	 BUFFER[1576]	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	 685	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
#define R1VS12LDU	 BUFFER[1578]	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	 686	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
#define R2IS11LDU	 BUFFER[1580]	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
#define idR2IS11LDU	 687	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
#define A1VS12LDU	 BUFFER[1582]	//( - , DU) Движение ББ1 в сторону ВУ
#define idA1VS12LDU	 688	//( - , DU) Движение ББ1 в сторону ВУ
#define A1CV01RDU	 BUFFER[1584]	//( - , DU) Измеренная скорость перемещения ББ1
#define idA1CV01RDU	 689	//( - , DU) Измеренная скорость перемещения ББ1
#define A1AB04LDU	 BUFFER[1589]	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
#define idA1AB04LDU	 690	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
#define A2AB16LDU	 BUFFER[1591]	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
#define idA2AB16LDU	 691	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
#define A2AB17LDU	 BUFFER[1593]	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
#define idA2AB17LDU	 692	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
#define A2AD01LDU	 BUFFER[1595]	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
#define idA2AD01LDU	 693	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
#define A2CV02RDU	 BUFFER[1597]	//( - , DU) Заданная скорость перемещения РБ1
#define idA2CV02RDU	 694	//( - , DU) Заданная скорость перемещения РБ1
#define B2CV01RDU	 BUFFER[1602]	//( - , DU) Измеренная скорость перемещения РБ2
#define idB2CV01RDU	 695	//( - , DU) Измеренная скорость перемещения РБ2
#define B2AB04LDU	 BUFFER[1607]	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
#define idB2AB04LDU	 696	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
#define B2AB02LDU	 BUFFER[1609]	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
#define idB2AB02LDU	 697	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
#define B2AB01LDU	 BUFFER[1611]	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
#define idB2AB01LDU	 698	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
#define B2AZ03LDU	 BUFFER[1613]	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
#define idB2AZ03LDU	 699	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
#define B2AD11LDU	 BUFFER[1615]	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	 700	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
#define B2AD21LDU	 BUFFER[1617]	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	 701	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
#define B2AD02LDU	 BUFFER[1619]	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
#define idB2AD02LDU	 702	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
#define B2AD03LDU	 BUFFER[1621]	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
#define idB2AD03LDU	 703	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
#define B2AD04LDU	 BUFFER[1623]	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
#define idB2AD04LDU	 704	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
#define B2AD05LDU	 BUFFER[1625]	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
#define idB2AD05LDU	 705	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
#define B2AD01LDU	 BUFFER[1627]	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
#define idB2AD01LDU	 706	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
#define B2CV02RDU	 BUFFER[1629]	//( - , DU) Заданная скорость перемещения РБ2
#define idB2CV02RDU	 707	//( - , DU) Заданная скорость перемещения РБ2
#define B2AB07LDU	 BUFFER[1634]	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
#define idB2AB07LDU	 708	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
#define B2AB08LDU	 BUFFER[1636]	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
#define idB2AB08LDU	 709	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
#define B2AB05LDU	 BUFFER[1638]	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
#define idB2AB05LDU	 710	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
#define B2AB06LDU	 BUFFER[1640]	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
#define idB2AB06LDU	 711	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
#define B2AB09LDU	 BUFFER[1642]	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
#define idB2AB09LDU	 712	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
#define B2AB10LDU	 BUFFER[1644]	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
#define idB2AB10LDU	 713	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
#define B2AB11LDU	 BUFFER[1646]	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
#define idB2AB11LDU	 714	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
#define A1AB18LDU	 BUFFER[1648]	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
#define idA1AB18LDU	 715	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
#define B1VS12LDU	 BUFFER[1650]	//( - , DU) Движение ББ2 в сторону ВУ
#define idB1VS12LDU	 716	//( - , DU) Движение ББ2 в сторону ВУ
#define B1CV01RDU	 BUFFER[1652]	//( - , DU) Измеренная скорость перемещения ББ2
#define idB1CV01RDU	 717	//( - , DU) Измеренная скорость перемещения ББ2
#define B1AB04LDU	 BUFFER[1657]	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
#define idB1AB04LDU	 718	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
#define B1AB02LDU	 BUFFER[1659]	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
#define idB1AB02LDU	 719	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
#define B1AB01LDU	 BUFFER[1661]	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
#define idB1AB01LDU	 720	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
#define B1VS22LDU	 BUFFER[1663]	//( - , DU) Движение ББ2 в сторону НУ
#define idB1VS22LDU	 721	//( - , DU) Движение ББ2 в сторону НУ
#define B1AZ03LDU	 BUFFER[1665]	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
#define idB1AZ03LDU	 722	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
#define B1AD11LDU	 BUFFER[1667]	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	 723	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
#define B1AD21LDU	 BUFFER[1669]	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	 724	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
#define B1AD02LDU	 BUFFER[1671]	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
#define idB1AD02LDU	 725	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
#define B1AD03LDU	 BUFFER[1673]	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
#define idB1AD03LDU	 726	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
#define B1AD04LDU	 BUFFER[1675]	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
#define idB1AD04LDU	 727	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
#define B1AD05LDU	 BUFFER[1677]	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
#define idB1AD05LDU	 728	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
#define B1AD01LDU	 BUFFER[1679]	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
#define idB1AD01LDU	 729	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
#define B1CV02RDU	 BUFFER[1681]	//( - , DU) Заданная скорость перемещения ББ2
#define idB1CV02RDU	 730	//( - , DU) Заданная скорость перемещения ББ2
#define B1AB07LDU	 BUFFER[1686]	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
#define idB1AB07LDU	 731	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
#define B1AB08LDU	 BUFFER[1688]	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
#define idB1AB08LDU	 732	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
#define B1AB05LDU	 BUFFER[1690]	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
#define idB1AB05LDU	 733	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
#define B1AB06LDU	 BUFFER[1692]	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
#define idB1AB06LDU	 734	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
#define B1AB09LDU	 BUFFER[1694]	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
#define idB1AB09LDU	 735	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
#define B1AB10LDU	 BUFFER[1696]	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
#define idB1AB10LDU	 736	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
#define B1AB11LDU	 BUFFER[1698]	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
#define idB1AB11LDU	 737	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
#define B1AB12LDU	 BUFFER[1700]	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idB1AB12LDU	 738	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A1AB02LDU	 BUFFER[1702]	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
#define idA1AB02LDU	 739	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
#define A1AB01LDU	 BUFFER[1704]	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
#define idA1AB01LDU	 740	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
#define A1VS22LDU	 BUFFER[1706]	//( - , DU) Движение ББ1 в сторону НУ
#define idA1VS22LDU	 741	//( - , DU) Движение ББ1 в сторону НУ
#define A1AZ03LDU	 BUFFER[1708]	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
#define idA1AZ03LDU	 742	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
#define A1AD11LDU	 BUFFER[1710]	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	 743	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
#define A1AD21LDU	 BUFFER[1712]	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	 744	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
#define A1AD02LDU	 BUFFER[1714]	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
#define idA1AD02LDU	 745	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
#define A1AD03LDU	 BUFFER[1716]	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
#define idA1AD03LDU	 746	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
#define A1AD04LDU	 BUFFER[1718]	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
#define idA1AD04LDU	 747	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
#define A1AD05LDU	 BUFFER[1720]	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
#define idA1AD05LDU	 748	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
#define A1AD01LDU	 BUFFER[1722]	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
#define idA1AD01LDU	 749	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
#define A1CV02RDU	 BUFFER[1724]	//( - , DU) Заданная скорость перемещения ББ1
#define idA1CV02RDU	 750	//( - , DU) Заданная скорость перемещения ББ1
#define A1AB07LDU	 BUFFER[1729]	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
#define idA1AB07LDU	 751	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
#define A1AB08LDU	 BUFFER[1731]	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
#define idA1AB08LDU	 752	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
#define A1AB05LDU	 BUFFER[1733]	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
#define idA1AB05LDU	 753	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
#define A1AB06LDU	 BUFFER[1735]	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
#define idA1AB06LDU	 754	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
#define A1AB09LDU	 BUFFER[1737]	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
#define idA1AB09LDU	 755	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
#define A1AB10LDU	 BUFFER[1739]	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
#define idA1AB10LDU	 756	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
#define A1AB11LDU	 BUFFER[1741]	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
#define idA1AB11LDU	 757	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
#define A1AB12LDU	 BUFFER[1743]	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA1AB12LDU	 758	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A1AB13LDU	 BUFFER[1745]	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
#define idA1AB13LDU	 759	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
#define A1AB14LDU	 BUFFER[1747]	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
#define idA1AB14LDU	 760	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
#define A1AB16LDU	 BUFFER[1749]	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
#define idA1AB16LDU	 761	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
#define A1AB17LDU	 BUFFER[1751]	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
#define idA1AB17LDU	 762	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
#define fEM_A1UC03RDU	 BUFFER[1753]	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define idfEM_A1UC03RDU	 763	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define dEM_A1UC05UDU	 BUFFER[1758]	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC05UDU	 764	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define dEM_A1UC06UDU	 BUFFER[1763]	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC06UDU	 765	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define dEM_A2UC06UDU	 BUFFER[1768]	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC06UDU	 766	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define dEM_A2UC05UDU	 BUFFER[1773]	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC05UDU	 767	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define fEM_A2UC03RDU	 BUFFER[1778]	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define idfEM_A2UC03RDU	 768	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define dEM_A3UC06UDU	 BUFFER[1783]	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC06UDU	 769	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define dEM_A3UC05UDU	 BUFFER[1788]	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC05UDU	 770	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define fEM_A3UC03RDU	 BUFFER[1793]	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define idfEM_A3UC03RDU	 771	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define dEM_A8UC06UDU	 BUFFER[1798]	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define iddEM_A8UC06UDU	 772	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define fEM_A8UC03RDU	 BUFFER[1803]	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
#define idfEM_A8UC03RDU	 773	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
#define dEM_A8UC05UDU	 BUFFER[1808]	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define iddEM_A8UC05UDU	 774	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define fEM_R0UV81RDU	 BUFFER[1813]	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	 775	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	 BUFFER[1818]	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	 776	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	 BUFFER[1823]	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	 777	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	 BUFFER[1828]	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	 778	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define fEM_R0UV86RDU	 BUFFER[1833]	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	 779	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV85RDU	 BUFFER[1838]	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	 780	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV87RDU	 BUFFER[1843]	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	 781	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_A3UP03RDU	 BUFFER[1848]	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	 782	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	 BUFFER[1853]	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	 783	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP43RDU	 BUFFER[1858]	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define idfEM_A3UP43RDU	 784	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define fEM_A3UP44RDU	 BUFFER[1863]	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP44RDU	 785	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP53RDU	 BUFFER[1868]	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP53RDU	 786	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP85RDU	 BUFFER[1873]	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP85RDU	 787	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP88RDU	 BUFFER[1878]	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP88RDU	 788	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP86RDU	 BUFFER[1883]	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP86RDU	 789	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_B8UV01RDU	 BUFFER[1888]	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
#define idfEM_B8UV01RDU	 790	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
#define fEM_B8UV02RDU	 BUFFER[1893]	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
#define idfEM_B8UV02RDU	 791	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
#define fEM_B8UV03RDU	 BUFFER[1898]	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
#define idfEM_B8UV03RDU	 792	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
#define fEM_B8UL04RDU	 BUFFER[1903]	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
#define idfEM_B8UL04RDU	 793	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
#define iEM_A2UV03CDU	 BUFFER[1908]	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define idiEM_A2UV03CDU	 794	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define fEM_A2UV01RDU	 BUFFER[1911]	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define idfEM_A2UV01RDU	 795	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define fEM_A2UV02RDU	 BUFFER[1916]	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define idfEM_A2UV02RDU	 796	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define fEM_A1UV01RDU	 BUFFER[1921]	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define idfEM_A1UV01RDU	 797	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define fEM_A1UV02RDU	 BUFFER[1926]	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define idfEM_A1UV02RDU	 798	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define fEM_A1UC06RDU	 BUFFER[1931]	//(A1UC06RDU) Уставка определения самохода ББ  мм
#define idfEM_A1UC06RDU	 799	//(A1UC06RDU) Уставка определения самохода ББ  мм
#define fEM_A1UC05RDU	 BUFFER[1936]	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A1UC05RDU	 800	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A1UL04RDU	 BUFFER[1941]	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define idfEM_A1UL04RDU	 801	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define fEM_A3UV01RDU	 BUFFER[1946]	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
#define idfEM_A3UV01RDU	 802	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
#define fEM_A3UV02RDU	 BUFFER[1951]	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
#define idfEM_A3UV02RDU	 803	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
#define fEM_A3UC06RDU	 BUFFER[1956]	//(A3UC06RDU) Уставка определения самохода ИС1  мм
#define idfEM_A3UC06RDU	 804	//(A3UC06RDU) Уставка определения самохода ИС1  мм
#define fEM_A3UC05RDU	 BUFFER[1961]	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A3UC05RDU	 805	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define fEM_A3UL04RDU	 BUFFER[1966]	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define idfEM_A3UL04RDU	 806	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define fEM_A3UP54RDU	 BUFFER[1971]	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define idfEM_A3UP54RDU	 807	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define fEM_A3UP87RDU	 BUFFER[1976]	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP87RDU	 808	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_R0UL05RDU	 BUFFER[1981]	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
#define idfEM_R0UL05RDU	 809	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
#define fEM_R0UL20RDU	 BUFFER[1986]	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
#define idfEM_R0UL20RDU	 810	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
#define fEM_B8UV04RDU	 BUFFER[1991]	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
#define idfEM_B8UV04RDU	 811	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
#define fEM_B8UC06RDU	 BUFFER[1996]	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
#define idfEM_B8UC06RDU	 812	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
#define fEM_B8UC05RDU	 BUFFER[2001]	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
#define idfEM_B8UC05RDU	 813	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
#define fEM_A2UL05RDU	 BUFFER[2006]	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define idfEM_A2UL05RDU	 814	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define fEM_A2UL03RDU	 BUFFER[2011]	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL03RDU	 815	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A2UC06RDU	 BUFFER[2016]	//(A2UC06RDU) Уставка определения самохода РБ  мм
#define idfEM_A2UC06RDU	 816	//(A2UC06RDU) Уставка определения самохода РБ  мм
#define fEM_A2UC05RDU	 BUFFER[2021]	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A2UC05RDU	 817	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A2UL04RDU	 BUFFER[2026]	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define idfEM_A2UL04RDU	 818	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define fEM_A1UL03RDU	 BUFFER[2031]	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define idfEM_A1UL03RDU	 819	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define fEM_A1UL05RDU	 BUFFER[2036]	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define idfEM_A1UL05RDU	 820	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define fEM_A3UL03RDU	 BUFFER[2041]	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define idfEM_A3UL03RDU	 821	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define fEM_A3UL05RDU	 BUFFER[2046]	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define idfEM_A3UL05RDU	 822	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define fEM_A1UC08RDU	 BUFFER[2051]	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define idfEM_A1UC08RDU	 823	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define fEM_A3UC08RDU	 BUFFER[2056]	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define idfEM_A3UC08RDU	 824	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define fEM_A1UC07RDU	 BUFFER[2061]	//(A1UC07RDU) Зона возврата при наведении ББ мм
#define idfEM_A1UC07RDU	 825	//(A1UC07RDU) Зона возврата при наведении ББ мм
#define fEM_A1UL01RDU	 BUFFER[2066]	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A1UL01RDU	 826	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A3UC07RDU	 BUFFER[2071]	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define idfEM_A3UC07RDU	 827	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define fEM_A3UL01RDU	 BUFFER[2076]	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A3UL01RDU	 828	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A2UC08RDU	 BUFFER[2081]	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define idfEM_A2UC08RDU	 829	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define fEM_A2UC07RDU	 BUFFER[2086]	//(A2UC07RDU) Зона возврата при наведении РБ  мм
#define idfEM_A2UC07RDU	 830	//(A2UC07RDU) Зона возврата при наведении РБ  мм
#define fEM_A2UL01RDU	 BUFFER[2091]	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A2UL01RDU	 831	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_B8UC01RDU	 BUFFER[2096]	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
#define idfEM_B8UC01RDU	 832	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
#define fEM_B8UL07RDU	 BUFFER[2101]	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
#define idfEM_B8UL07RDU	 833	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
#define fEM_B8UC02RDU	 BUFFER[2106]	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
#define idfEM_B8UC02RDU	 834	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
#define fEM_B8UL01RDU	 BUFFER[2111]	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_B8UL01RDU	 835	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_B8UL05RDU	 BUFFER[2116]	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
#define idfEM_B8UL05RDU	 836	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
#define fEM_B8UL03RDU	 BUFFER[2121]	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
#define idfEM_B8UL03RDU	 837	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
#define fEM_B8UL06RDU	 BUFFER[2126]	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
#define idfEM_B8UL06RDU	 838	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
#define fEM_A9UZ03RDU	 BUFFER[2131]	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
#define idfEM_A9UZ03RDU	 839	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
#define fEM_A9UZ04RDU	 BUFFER[2136]	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
#define idfEM_A9UZ04RDU	 840	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
#define fEM_A9UZ05RDU	 BUFFER[2141]	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
#define idfEM_A9UZ05RDU	 841	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
#define fEM_R4UZ04RDU	 BUFFER[2146]	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define idfEM_R4UZ04RDU	 842	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define fEM_R4UZ03RDU	 BUFFER[2151]	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define idfEM_R4UZ03RDU	 843	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define fEM_R4UZ05RDU	 BUFFER[2156]	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define idfEM_R4UZ05RDU	 844	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define fEM_A5UZ03RDU	 BUFFER[2161]	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
#define idfEM_A5UZ03RDU	 845	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
#define fEM_A5UZ04RDU	 BUFFER[2166]	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
#define idfEM_A5UZ04RDU	 846	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
#define fEM_A5UZ05RDU	 BUFFER[2171]	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
#define idfEM_A5UZ05RDU	 847	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
#define fEM_A4UZ03RDU	 BUFFER[2176]	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
#define idfEM_A4UZ03RDU	 848	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
#define fEM_A4UZ04RDU	 BUFFER[2181]	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
#define idfEM_A4UZ04RDU	 849	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
#define fEM_A4UZ05RDU	 BUFFER[2186]	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
#define idfEM_A4UZ05RDU	 850	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
#define fEM_A6UZ03RDU	 BUFFER[2191]	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
#define idfEM_A6UZ03RDU	 851	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
#define fEM_A6UZ04RDU	 BUFFER[2196]	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
#define idfEM_A6UZ04RDU	 852	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
#define fEM_A6UZ05RDU	 BUFFER[2201]	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
#define idfEM_A6UZ05RDU	 853	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
#define fEM_R1UZ03RDU	 BUFFER[2206]	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define idfEM_R1UZ03RDU	 854	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define fEM_R1UZ04RDU	 BUFFER[2211]	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define idfEM_R1UZ04RDU	 855	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define fEM_R1UZ05RDU	 BUFFER[2216]	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define idfEM_R1UZ05RDU	 856	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define fEM_R0UL04RDU	 BUFFER[2221]	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
#define idfEM_R0UL04RDU	 857	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
#define fEM_R0UL06RDU	 BUFFER[2226]	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
#define idfEM_R0UL06RDU	 858	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
#define fEM_R0UL03RDU	 BUFFER[2231]	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
#define idfEM_R0UL03RDU	 859	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
#define fEM_R0UL17RDU	 BUFFER[2236]	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
#define idfEM_R0UL17RDU	 860	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
#define fEM_R0UL19RDU	 BUFFER[2241]	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define idfEM_R0UL19RDU	 861	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define fEM_R0UL07RDU	 BUFFER[2246]	//(R0UL07RDU) Время срабатывания верхней АС II УР
#define idfEM_R0UL07RDU	 862	//(R0UL07RDU) Время срабатывания верхней АС II УР
#define fEM_R0UL18RDU	 BUFFER[2251]	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
#define idfEM_R0UL18RDU	 863	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
#define fEM_R0UL16RDU	 BUFFER[2256]	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
#define idfEM_R0UL16RDU	 864	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
#define fEM_R0UL02RDU	 BUFFER[2261]	//(R0UL02RDU) Время задержки  ИНИ
#define idfEM_R0UL02RDU	 865	//(R0UL02RDU) Время задержки  ИНИ
#define fEM_R0UN08RDU	 BUFFER[2266]	//(R0UN08RDU) 8-я заданная мощность
#define idfEM_R0UN08RDU	 866	//(R0UN08RDU) 8-я заданная мощность
#define fEM_R0UN07RDU	 BUFFER[2271]	//(R0UN07RDU) 7-я заданная мощность
#define idfEM_R0UN07RDU	 867	//(R0UN07RDU) 7-я заданная мощность
#define fEM_R0UN06RDU	 BUFFER[2276]	//(R0UN06RDU) 6-я заданная мощность
#define idfEM_R0UN06RDU	 868	//(R0UN06RDU) 6-я заданная мощность
#define fEM_R0UN05RDU	 BUFFER[2281]	//(R0UN05RDU) 5-я заданная мощность
#define idfEM_R0UN05RDU	 869	//(R0UN05RDU) 5-я заданная мощность
#define fEM_R0UN04RDU	 BUFFER[2286]	//(R0UN04RDU) 4-я заданная мощность
#define idfEM_R0UN04RDU	 870	//(R0UN04RDU) 4-я заданная мощность
#define fEM_R0UN03RDU	 BUFFER[2291]	//(R0UN03RDU) Ограничение 3 по мощности
#define idfEM_R0UN03RDU	 871	//(R0UN03RDU) Ограничение 3 по мощности
#define fEM_R0UN02RDU	 BUFFER[2296]	//(R0UN02RDU) 2-я заданная мощность
#define idfEM_R0UN02RDU	 872	//(R0UN02RDU) 2-я заданная мощность
#define fEM_R0UN01RDU	 BUFFER[2301]	//(R0UN01RDU) 1-я заданная мощность
#define idfEM_R0UN01RDU	 873	//(R0UN01RDU) 1-я заданная мощность
#define fEM_A2UC82RDU	 BUFFER[2306]	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC82RDU	 874	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define fEM_A2UC83RDU	 BUFFER[2311]	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define idfEM_A2UC83RDU	 875	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define fEM_A1UC83RDU	 BUFFER[2316]	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define idfEM_A1UC83RDU	 876	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define fEM_A2UC81RDU	 BUFFER[2321]	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC81RDU	 877	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define fEM_A1UC81RDU	 BUFFER[2326]	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC81RDU	 878	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define fEM_A1UC82RDU	 BUFFER[2331]	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC82RDU	 879	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define fEM_A2UL83RDU	 BUFFER[2336]	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL83RDU	 880	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A3UC81RDU	 BUFFER[2341]	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define idfEM_A3UC81RDU	 881	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define fEM_A3UC82RDU	 BUFFER[2346]	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define idfEM_A3UC82RDU	 882	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define fEM_R0UN80RDU	 BUFFER[2351]	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define idfEM_R0UN80RDU	 883	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define iEM_A2UV01IDU	 BUFFER[2356]	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV01IDU	 884	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define iEM_A2UV02IDU	 BUFFER[2359]	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV02IDU	 885	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define iEM_A1UV01IDU	 BUFFER[2362]	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV01IDU	 886	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define iEM_A1UV02IDU	 BUFFER[2365]	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV02IDU	 887	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define iEM_A1UV03IDU	 BUFFER[2368]	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define idiEM_A1UV03IDU	 888	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define iEM_A3UV01IDU	 BUFFER[2371]	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define idiEM_A3UV01IDU	 889	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define iEM_A3UV02IDU	 BUFFER[2374]	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define idiEM_A3UV02IDU	 890	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define lEM_R0MD01LC1	 BUFFER[2377]	//(R0MD01LC1) Ручное управление ОРР
#define idlEM_R0MD01LC1	 891	//(R0MD01LC1) Ручное управление ОРР
#define fEM_A3UC09RDU	 BUFFER[2379]	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC09RDU	 892	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define fEM_A2UC02RDU	 BUFFER[2384]	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define idfEM_A2UC02RDU	 893	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define fEM_A1UC02RDU	 BUFFER[2389]	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define idfEM_A1UC02RDU	 894	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define fEM_A3UC02RDU	 BUFFER[2394]	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define idfEM_A3UC02RDU	 895	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define fEM_R0UL21RDU	 BUFFER[2399]	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
#define idfEM_R0UL21RDU	 896	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
#define fEM_R0UN09RDU	 BUFFER[2404]	//(R0UN09RDU) Минимальный период при регулировании мощности
#define idfEM_R0UN09RDU	 897	//(R0UN09RDU) Минимальный период при регулировании мощности
#define fEM_R0UN11RDU	 BUFFER[2409]	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
#define idfEM_R0UN11RDU	 898	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
#define fEM_R0UN12RDU	 BUFFER[2414]	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
#define idfEM_R0UN12RDU	 899	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
#define fEM_R0UN13RDU	 BUFFER[2419]	//(R0UN13RDU) Минимальное изменение координаты, мм
#define idfEM_R0UN13RDU	 900	//(R0UN13RDU) Минимальное изменение координаты, мм
#define fEM_R0UN14RDU	 BUFFER[2424]	//(R0UN14RDU) Максимальная координата штока ИМ, мм
#define idfEM_R0UN14RDU	 901	//(R0UN14RDU) Максимальная координата штока ИМ, мм
#define fEM_R0UN16RDU	 BUFFER[2429]	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN16RDU	 902	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN17RDU	 BUFFER[2434]	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN17RDU	 903	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN18RDU	 BUFFER[2439]	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
#define idfEM_R0UN18RDU	 904	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
#define fEM_R0UN19RDU	 BUFFER[2444]	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define idfEM_R0UN19RDU	 905	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define fEM_R0UN70LDU	 BUFFER[2449]	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN70LDU	 906	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN71LDU	 BUFFER[2454]	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN71LDU	 907	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN72LDU	 BUFFER[2459]	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN72LDU	 908	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN73LDU	 BUFFER[2464]	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN73LDU	 909	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN74LDU	 BUFFER[2469]	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN74LDU	 910	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN75LDU	 BUFFER[2474]	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN75LDU	 911	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN80LDU	 BUFFER[2479]	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN80LDU	 912	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define fEM_R0UN81LDU	 BUFFER[2484]	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN81LDU	 913	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define fEM_R0UN82LDU	 BUFFER[2489]	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN82LDU	 914	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define fEM_R0UN83LDU	 BUFFER[2494]	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN83LDU	 915	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define fEM_R0UN84LDU	 BUFFER[2499]	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN84LDU	 916	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define fEM_R0UN85LDU	 BUFFER[2504]	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN85LDU	 917	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define fEM_R0UT20RDU	 BUFFER[2509]	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define idfEM_R0UT20RDU	 918	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define fEM_R0UN25RDU	 BUFFER[2514]	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
#define idfEM_R0UN25RDU	 919	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
#define fEM_R0UN15RDU	 BUFFER[2519]	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
#define idfEM_R0UN15RDU	 920	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
#define fEM_R0UN26RDU	 BUFFER[2524]	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
#define idfEM_R0UN26RDU	 921	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
#define fEM_R0UN27RDU	 BUFFER[2529]	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
#define idfEM_R0UN27RDU	 922	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
#define fEM_R0UN24RDU	 BUFFER[2534]	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN24RDU	 923	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
#define fEM_R0UL25RDU	 BUFFER[2539]	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define idfEM_R0UL25RDU	 924	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define bFirstEnterFlag	 BUFFER[2544]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 925	//(bFirstEnterFlag) 
#define internal2_m186_y0	 BUFFER[2546]	//(internal2_m186_y0) y0
#define idinternal2_m186_y0	 926	//(internal2_m186_y0) y0
#define internal2_m184_y0	 BUFFER[2551]	//(internal2_m184_y0) y0
#define idinternal2_m184_y0	 927	//(internal2_m184_y0) y0
#define internal2_m216_y0	 BUFFER[2556]	//(internal2_m216_y0) state
#define idinternal2_m216_y0	 928	//(internal2_m216_y0) state
#define internal2_m210_y0	 BUFFER[2558]	//(internal2_m210_y0) state
#define idinternal2_m210_y0	 929	//(internal2_m210_y0) state
#define internal2_m199_y1	 BUFFER[2560]	//(internal2_m199_y1) y1 - внутренний параметр
#define idinternal2_m199_y1	 930	//(internal2_m199_y1) y1 - внутренний параметр
#define internal2_m206_y1	 BUFFER[2562]	//(internal2_m206_y1) y1 - внутренний параметр
#define idinternal2_m206_y1	 931	//(internal2_m206_y1) y1 - внутренний параметр
#define internal2_m189_y1	 BUFFER[2564]	//(internal2_m189_y1) y1 - внутренний параметр
#define idinternal2_m189_y1	 932	//(internal2_m189_y1) y1 - внутренний параметр
#define internal2_m196_y1	 BUFFER[2566]	//(internal2_m196_y1) y1 - внутренний параметр
#define idinternal2_m196_y1	 933	//(internal2_m196_y1) y1 - внутренний параметр
#define internal2_m16_Nk0	 BUFFER[2568]	//(internal2_m16_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m16_Nk0	 934	//(internal2_m16_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m16_SetFlag	 BUFFER[2573]	//(internal2_m16_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m16_SetFlag	 935	//(internal2_m16_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m108_Nk0	 BUFFER[2575]	//(internal2_m108_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m108_Nk0	 936	//(internal2_m108_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m108_SetFlag	 BUFFER[2580]	//(internal2_m108_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m108_SetFlag	 937	//(internal2_m108_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m112_Nk0	 BUFFER[2582]	//(internal2_m112_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m112_Nk0	 938	//(internal2_m112_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m112_SetFlag	 BUFFER[2587]	//(internal2_m112_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m112_SetFlag	 939	//(internal2_m112_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m75_Nk0	 BUFFER[2589]	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m75_Nk0	 940	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m75_SetFlag	 BUFFER[2594]	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m75_SetFlag	 941	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m77_Nk0	 BUFFER[2596]	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m77_Nk0	 942	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m77_SetFlag	 BUFFER[2601]	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m77_SetFlag	 943	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m47_Nk0	 BUFFER[2603]	//(internal2_m47_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m47_Nk0	 944	//(internal2_m47_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m47_SetFlag	 BUFFER[2608]	//(internal2_m47_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m47_SetFlag	 945	//(internal2_m47_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m51_Nk0	 BUFFER[2610]	//(internal2_m51_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m51_Nk0	 946	//(internal2_m51_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m51_SetFlag	 BUFFER[2615]	//(internal2_m51_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m51_SetFlag	 947	//(internal2_m51_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m21_Nk0	 BUFFER[2617]	//(internal2_m21_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m21_Nk0	 948	//(internal2_m21_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m21_SetFlag	 BUFFER[2622]	//(internal2_m21_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m21_SetFlag	 949	//(internal2_m21_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal1_m198_s	 BUFFER[2624]	//(internal1_m198_s) s - запомнили значение
#define idinternal1_m198_s	 950	//(internal1_m198_s) s - запомнили значение
#define internal1_m195_s	 BUFFER[2626]	//(internal1_m195_s) s - запомнили значение
#define idinternal1_m195_s	 951	//(internal1_m195_s) s - запомнили значение
#define internal1_m189_s	 BUFFER[2628]	//(internal1_m189_s) s - запомнили значение
#define idinternal1_m189_s	 952	//(internal1_m189_s) s - запомнили значение
#define internal1_m182_s	 BUFFER[2630]	//(internal1_m182_s) s - запомнили значение
#define idinternal1_m182_s	 953	//(internal1_m182_s) s - запомнили значение
#define internal1_m179_s	 BUFFER[2632]	//(internal1_m179_s) s - запомнили значение
#define idinternal1_m179_s	 954	//(internal1_m179_s) s - запомнили значение
#define internal1_m1707_q0	 BUFFER[2634]	//(internal1_m1707_q0) q0 - внутренний параметр
#define idinternal1_m1707_q0	 955	//(internal1_m1707_q0) q0 - внутренний параметр
#define internal1_m2140_q0	 BUFFER[2636]	//(internal1_m2140_q0) q0 - внутренний параметр
#define idinternal1_m2140_q0	 956	//(internal1_m2140_q0) q0 - внутренний параметр
#define internal1_m2124_q0	 BUFFER[2638]	//(internal1_m2124_q0) q0 - внутренний параметр
#define idinternal1_m2124_q0	 957	//(internal1_m2124_q0) q0 - внутренний параметр
#define internal1_m2172_q0	 BUFFER[2640]	//(internal1_m2172_q0) q0 - внутренний параметр
#define idinternal1_m2172_q0	 958	//(internal1_m2172_q0) q0 - внутренний параметр
#define internal1_m2156_q0	 BUFFER[2642]	//(internal1_m2156_q0) q0 - внутренний параметр
#define idinternal1_m2156_q0	 959	//(internal1_m2156_q0) q0 - внутренний параметр
#define internal1_m2146_q0	 BUFFER[2644]	//(internal1_m2146_q0) q0 - внутренний параметр
#define idinternal1_m2146_q0	 960	//(internal1_m2146_q0) q0 - внутренний параметр
#define internal1_m2127_q0	 BUFFER[2646]	//(internal1_m2127_q0) q0 - внутренний параметр
#define idinternal1_m2127_q0	 961	//(internal1_m2127_q0) q0 - внутренний параметр
#define internal1_m2144_q0	 BUFFER[2648]	//(internal1_m2144_q0) q0 - внутренний параметр
#define idinternal1_m2144_q0	 962	//(internal1_m2144_q0) q0 - внутренний параметр
#define internal1_m2125_q0	 BUFFER[2650]	//(internal1_m2125_q0) q0 - внутренний параметр
#define idinternal1_m2125_q0	 963	//(internal1_m2125_q0) q0 - внутренний параметр
#define internal1_m2123_q0	 BUFFER[2652]	//(internal1_m2123_q0) q0 - внутренний параметр
#define idinternal1_m2123_q0	 964	//(internal1_m2123_q0) q0 - внутренний параметр
#define internal1_m2122_q0	 BUFFER[2654]	//(internal1_m2122_q0) q0 - внутренний параметр
#define idinternal1_m2122_q0	 965	//(internal1_m2122_q0) q0 - внутренний параметр
#define internal1_m2136_q0	 BUFFER[2656]	//(internal1_m2136_q0) q0 - внутренний параметр
#define idinternal1_m2136_q0	 966	//(internal1_m2136_q0) q0 - внутренний параметр
#define internal1_m2134_q0	 BUFFER[2658]	//(internal1_m2134_q0) q0 - внутренний параметр
#define idinternal1_m2134_q0	 967	//(internal1_m2134_q0) q0 - внутренний параметр
#define internal1_m2142_q0	 BUFFER[2660]	//(internal1_m2142_q0) q0 - внутренний параметр
#define idinternal1_m2142_q0	 968	//(internal1_m2142_q0) q0 - внутренний параметр
#define internal1_m2138_q0	 BUFFER[2662]	//(internal1_m2138_q0) q0 - внутренний параметр
#define idinternal1_m2138_q0	 969	//(internal1_m2138_q0) q0 - внутренний параметр
#define internal1_m2178_q0	 BUFFER[2664]	//(internal1_m2178_q0) q0 - внутренний параметр
#define idinternal1_m2178_q0	 970	//(internal1_m2178_q0) q0 - внутренний параметр
#define internal1_m2159_q0	 BUFFER[2666]	//(internal1_m2159_q0) q0 - внутренний параметр
#define idinternal1_m2159_q0	 971	//(internal1_m2159_q0) q0 - внутренний параметр
#define internal1_m2176_q0	 BUFFER[2668]	//(internal1_m2176_q0) q0 - внутренний параметр
#define idinternal1_m2176_q0	 972	//(internal1_m2176_q0) q0 - внутренний параметр
#define internal1_m2158_q0	 BUFFER[2670]	//(internal1_m2158_q0) q0 - внутренний параметр
#define idinternal1_m2158_q0	 973	//(internal1_m2158_q0) q0 - внутренний параметр
#define internal1_m2155_q0	 BUFFER[2672]	//(internal1_m2155_q0) q0 - внутренний параметр
#define idinternal1_m2155_q0	 974	//(internal1_m2155_q0) q0 - внутренний параметр
#define internal1_m2154_q0	 BUFFER[2674]	//(internal1_m2154_q0) q0 - внутренний параметр
#define idinternal1_m2154_q0	 975	//(internal1_m2154_q0) q0 - внутренний параметр
#define internal1_m2168_q0	 BUFFER[2676]	//(internal1_m2168_q0) q0 - внутренний параметр
#define idinternal1_m2168_q0	 976	//(internal1_m2168_q0) q0 - внутренний параметр
#define internal1_m2166_q0	 BUFFER[2678]	//(internal1_m2166_q0) q0 - внутренний параметр
#define idinternal1_m2166_q0	 977	//(internal1_m2166_q0) q0 - внутренний параметр
#define internal1_m2043_tx	 BUFFER[2680]	//(internal1_m2043_tx) tx - внутренний параметр
#define idinternal1_m2043_tx	 978	//(internal1_m2043_tx) tx - внутренний параметр
#define internal1_m2022_tx	 BUFFER[2685]	//(internal1_m2022_tx) tx - внутренний параметр
#define idinternal1_m2022_tx	 979	//(internal1_m2022_tx) tx - внутренний параметр
#define internal1_m1729_Pv0	 BUFFER[2690]	//(internal1_m1729_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1729_Pv0	 980	//(internal1_m1729_Pv0)  - Пер. выключатель механизма
#define internal1_m1729_Zv0	 BUFFER[2692]	//(internal1_m1729_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1729_Zv0	 981	//(internal1_m1729_Zv0)  - Зад. выключатель механизма
#define internal1_m1729_MyFirstEnterFlag	 BUFFER[2694]	//(internal1_m1729_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1729_MyFirstEnterFlag	 982	//(internal1_m1729_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m1728_Pv0	 BUFFER[2696]	//(internal1_m1728_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1728_Pv0	 983	//(internal1_m1728_Pv0)  - Пер. выключатель механизма
#define internal1_m1728_Zv0	 BUFFER[2698]	//(internal1_m1728_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1728_Zv0	 984	//(internal1_m1728_Zv0)  - Зад. выключатель механизма
#define internal1_m1728_MyFirstEnterFlag	 BUFFER[2700]	//(internal1_m1728_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1728_MyFirstEnterFlag	 985	//(internal1_m1728_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m2198_tx	 BUFFER[2702]	//(internal1_m2198_tx) tx - время накопленное сек
#define idinternal1_m2198_tx	 986	//(internal1_m2198_tx) tx - время накопленное сек
#define internal1_m2198_y0	 BUFFER[2707]	//(internal1_m2198_y0) y0
#define idinternal1_m2198_y0	 987	//(internal1_m2198_y0) y0
#define internal1_m2201_tx	 BUFFER[2708]	//(internal1_m2201_tx) tx - время накопленное сек
#define idinternal1_m2201_tx	 988	//(internal1_m2201_tx) tx - время накопленное сек
#define internal1_m2201_y0	 BUFFER[2713]	//(internal1_m2201_y0) y0
#define idinternal1_m2201_y0	 989	//(internal1_m2201_y0) y0
#define internal1_m2200_tx	 BUFFER[2714]	//(internal1_m2200_tx) tx - время накопленное сек
#define idinternal1_m2200_tx	 990	//(internal1_m2200_tx) tx - время накопленное сек
#define internal1_m2200_y0	 BUFFER[2719]	//(internal1_m2200_y0) y0
#define idinternal1_m2200_y0	 991	//(internal1_m2200_y0) y0
#define internal1_m2237_tx	 BUFFER[2720]	//(internal1_m2237_tx) tx - внутренний параметр
#define idinternal1_m2237_tx	 992	//(internal1_m2237_tx) tx - внутренний параметр
#define internal1_m2235_tx	 BUFFER[2725]	//(internal1_m2235_tx) tx - время накопленное сек
#define idinternal1_m2235_tx	 993	//(internal1_m2235_tx) tx - время накопленное сек
#define internal1_m2235_y0	 BUFFER[2730]	//(internal1_m2235_y0) y0
#define idinternal1_m2235_y0	 994	//(internal1_m2235_y0) y0
#define internal1_m2240_q0	 BUFFER[2731]	//(internal1_m2240_q0) q0 - внутренний параметр
#define idinternal1_m2240_q0	 995	//(internal1_m2240_q0) q0 - внутренний параметр
#define internal1_m2207_q0	 BUFFER[2733]	//(internal1_m2207_q0) q0 - внутренний параметр
#define idinternal1_m2207_q0	 996	//(internal1_m2207_q0) q0 - внутренний параметр
#define internal1_m2215_tx	 BUFFER[2735]	//(internal1_m2215_tx) tx - внутренний параметр
#define idinternal1_m2215_tx	 997	//(internal1_m2215_tx) tx - внутренний параметр
#define internal1_m2213_q0	 BUFFER[2740]	//(internal1_m2213_q0) q0 - внутренний параметр
#define idinternal1_m2213_q0	 998	//(internal1_m2213_q0) q0 - внутренний параметр
#define internal1_m2037_tx	 BUFFER[2742]	//(internal1_m2037_tx) tx - время накопленное сек
#define idinternal1_m2037_tx	 999	//(internal1_m2037_tx) tx - время накопленное сек
#define internal1_m2037_y0	 BUFFER[2747]	//(internal1_m2037_y0) y0
#define idinternal1_m2037_y0	 1000	//(internal1_m2037_y0) y0
#define internal1_m2029_tx	 BUFFER[2748]	//(internal1_m2029_tx) tx - время накопленное сек
#define idinternal1_m2029_tx	 1001	//(internal1_m2029_tx) tx - время накопленное сек
#define internal1_m2029_y0	 BUFFER[2753]	//(internal1_m2029_y0) y0
#define idinternal1_m2029_y0	 1002	//(internal1_m2029_y0) y0
#define internal1_m1717_q0	 BUFFER[2754]	//(internal1_m1717_q0) q0 - внутренний параметр
#define idinternal1_m1717_q0	 1003	//(internal1_m1717_q0) q0 - внутренний параметр
#define internal1_m1722_q0	 BUFFER[2756]	//(internal1_m1722_q0) q0 - внутренний параметр
#define idinternal1_m1722_q0	 1004	//(internal1_m1722_q0) q0 - внутренний параметр
#define internal1_m1714_q0	 BUFFER[2758]	//(internal1_m1714_q0) q0 - внутренний параметр
#define idinternal1_m1714_q0	 1005	//(internal1_m1714_q0) q0 - внутренний параметр
#define internal1_m1756_q0	 BUFFER[2760]	//(internal1_m1756_q0) q0 - внутренний параметр
#define idinternal1_m1756_q0	 1006	//(internal1_m1756_q0) q0 - внутренний параметр
#define internal1_m756_tx	 BUFFER[2762]	//(internal1_m756_tx) tx - время накопленное сек
#define idinternal1_m756_tx	 1007	//(internal1_m756_tx) tx - время накопленное сек
#define internal1_m756_y0	 BUFFER[2767]	//(internal1_m756_y0) y0
#define idinternal1_m756_y0	 1008	//(internal1_m756_y0) y0
#define internal1_m2033_tx	 BUFFER[2768]	//(internal1_m2033_tx) tx - внутренний параметр
#define idinternal1_m2033_tx	 1009	//(internal1_m2033_tx) tx - внутренний параметр
#define internal1_m2036_q0	 BUFFER[2773]	//(internal1_m2036_q0) q0 - внутренний параметр
#define idinternal1_m2036_q0	 1010	//(internal1_m2036_q0) q0 - внутренний параметр
#define internal1_m2028_q0	 BUFFER[2775]	//(internal1_m2028_q0) q0 - внутренний параметр
#define idinternal1_m2028_q0	 1011	//(internal1_m2028_q0) q0 - внутренний параметр
#define internal1_m1998_tx	 BUFFER[2777]	//(internal1_m1998_tx) tx - внутренний параметр
#define idinternal1_m1998_tx	 1012	//(internal1_m1998_tx) tx - внутренний параметр
#define internal1_m2009_tx	 BUFFER[2782]	//(internal1_m2009_tx) tx - внутренний параметр
#define idinternal1_m2009_tx	 1013	//(internal1_m2009_tx) tx - внутренний параметр
#define internal1_m1995_tx	 BUFFER[2787]	//(internal1_m1995_tx) tx - внутренний параметр
#define idinternal1_m1995_tx	 1014	//(internal1_m1995_tx) tx - внутренний параметр
#define internal1_m2001_q0	 BUFFER[2792]	//(internal1_m2001_q0) q0 - внутренний параметр
#define idinternal1_m2001_q0	 1015	//(internal1_m2001_q0) q0 - внутренний параметр
#define internal1_m2013_q0	 BUFFER[2794]	//(internal1_m2013_q0) q0 - внутренний параметр
#define idinternal1_m2013_q0	 1016	//(internal1_m2013_q0) q0 - внутренний параметр
#define internal1_m1971_tx	 BUFFER[2796]	//(internal1_m1971_tx) tx - внутренний параметр
#define idinternal1_m1971_tx	 1017	//(internal1_m1971_tx) tx - внутренний параметр
#define internal1_m57_tx	 BUFFER[2801]	//(internal1_m57_tx) tx - внутренний параметр
#define idinternal1_m57_tx	 1018	//(internal1_m57_tx) tx - внутренний параметр
#define internal1_m353_tx	 BUFFER[2806]	//(internal1_m353_tx) tx - внутренний параметр
#define idinternal1_m353_tx	 1019	//(internal1_m353_tx) tx - внутренний параметр
#define internal1_m307_tx	 BUFFER[2811]	//(internal1_m307_tx) tx - внутренний параметр
#define idinternal1_m307_tx	 1020	//(internal1_m307_tx) tx - внутренний параметр
#define internal1_m757_tx	 BUFFER[2816]	//(internal1_m757_tx) tx - внутренний параметр
#define idinternal1_m757_tx	 1021	//(internal1_m757_tx) tx - внутренний параметр
#define internal1_m1437_tx	 BUFFER[2821]	//(internal1_m1437_tx) tx - внутренний параметр
#define idinternal1_m1437_tx	 1022	//(internal1_m1437_tx) tx - внутренний параметр
#define internal1_m119_tx	 BUFFER[2826]	//(internal1_m119_tx) tx - внутренний параметр
#define idinternal1_m119_tx	 1023	//(internal1_m119_tx) tx - внутренний параметр
#define internal1_m121_tx	 BUFFER[2831]	//(internal1_m121_tx) tx - внутренний параметр
#define idinternal1_m121_tx	 1024	//(internal1_m121_tx) tx - внутренний параметр
#define internal1_m126_tx	 BUFFER[2836]	//(internal1_m126_tx) tx - внутренний параметр
#define idinternal1_m126_tx	 1025	//(internal1_m126_tx) tx - внутренний параметр
#define internal1_m24_tx	 BUFFER[2841]	//(internal1_m24_tx) tx - внутренний параметр
#define idinternal1_m24_tx	 1026	//(internal1_m24_tx) tx - внутренний параметр
#define internal1_m16_tx	 BUFFER[2846]	//(internal1_m16_tx) tx - внутренний параметр
#define idinternal1_m16_tx	 1027	//(internal1_m16_tx) tx - внутренний параметр
#define internal1_m1980_tx	 BUFFER[2851]	//(internal1_m1980_tx) tx - внутренний параметр
#define idinternal1_m1980_tx	 1028	//(internal1_m1980_tx) tx - внутренний параметр
#define internal1_m1968_tx	 BUFFER[2856]	//(internal1_m1968_tx) tx - внутренний параметр
#define idinternal1_m1968_tx	 1029	//(internal1_m1968_tx) tx - внутренний параметр
#define internal1_m2076_tx	 BUFFER[2861]	//(internal1_m2076_tx) tx - внутренний параметр
#define idinternal1_m2076_tx	 1030	//(internal1_m2076_tx) tx - внутренний параметр
#define internal1_m2080_tx	 BUFFER[2866]	//(internal1_m2080_tx) tx - внутренний параметр
#define idinternal1_m2080_tx	 1031	//(internal1_m2080_tx) tx - внутренний параметр
#define internal1_m1893_tx	 BUFFER[2871]	//(internal1_m1893_tx) tx - внутренний параметр
#define idinternal1_m1893_tx	 1032	//(internal1_m1893_tx) tx - внутренний параметр
#define internal1_m83_tx	 BUFFER[2876]	//(internal1_m83_tx) tx - внутренний параметр
#define idinternal1_m83_tx	 1033	//(internal1_m83_tx) tx - внутренний параметр
#define internal1_m322_tx	 BUFFER[2881]	//(internal1_m322_tx) tx - время накопленное сек
#define idinternal1_m322_tx	 1034	//(internal1_m322_tx) tx - время накопленное сек
#define internal1_m322_y0	 BUFFER[2886]	//(internal1_m322_y0) y0
#define idinternal1_m322_y0	 1035	//(internal1_m322_y0) y0
#define internal1_m1887_tx	 BUFFER[2887]	//(internal1_m1887_tx) tx - время накопленное сек
#define idinternal1_m1887_tx	 1036	//(internal1_m1887_tx) tx - время накопленное сек
#define internal1_m1887_y0	 BUFFER[2892]	//(internal1_m1887_y0) y0
#define idinternal1_m1887_y0	 1037	//(internal1_m1887_y0) y0
#define internal1_m1885_tx	 BUFFER[2893]	//(internal1_m1885_tx) tx - время накопленное сек
#define idinternal1_m1885_tx	 1038	//(internal1_m1885_tx) tx - время накопленное сек
#define internal1_m1885_y0	 BUFFER[2898]	//(internal1_m1885_y0) y0
#define idinternal1_m1885_y0	 1039	//(internal1_m1885_y0) y0
#define internal1_m1874_tx	 BUFFER[2899]	//(internal1_m1874_tx) tx - время накопленное сек
#define idinternal1_m1874_tx	 1040	//(internal1_m1874_tx) tx - время накопленное сек
#define internal1_m1874_y0	 BUFFER[2904]	//(internal1_m1874_y0) y0
#define idinternal1_m1874_y0	 1041	//(internal1_m1874_y0) y0
#define internal1_m1894_q0	 BUFFER[2905]	//(internal1_m1894_q0) q0 - внутренний параметр
#define idinternal1_m1894_q0	 1042	//(internal1_m1894_q0) q0 - внутренний параметр
#define internal1_m1457_q0	 BUFFER[2910]	//(internal1_m1457_q0) q0 - внутренний параметр
#define idinternal1_m1457_q0	 1043	//(internal1_m1457_q0) q0 - внутренний параметр
#define internal1_m1496_q0	 BUFFER[2915]	//(internal1_m1496_q0) q0 - внутренний параметр
#define idinternal1_m1496_q0	 1044	//(internal1_m1496_q0) q0 - внутренний параметр
#define internal1_m1494_q0	 BUFFER[2920]	//(internal1_m1494_q0) q0 - внутренний параметр
#define idinternal1_m1494_q0	 1045	//(internal1_m1494_q0) q0 - внутренний параметр
#define internal1_m1933_q0	 BUFFER[2925]	//(internal1_m1933_q0) q0 - внутренний параметр
#define idinternal1_m1933_q0	 1046	//(internal1_m1933_q0) q0 - внутренний параметр
#define internal1_m1911_tx	 BUFFER[2930]	//(internal1_m1911_tx) tx - время накопленное сек
#define idinternal1_m1911_tx	 1047	//(internal1_m1911_tx) tx - время накопленное сек
#define internal1_m1911_y0	 BUFFER[2935]	//(internal1_m1911_y0) y0
#define idinternal1_m1911_y0	 1048	//(internal1_m1911_y0) y0
#define internal1_m1926_tx	 BUFFER[2936]	//(internal1_m1926_tx) tx - время накопленное сек
#define idinternal1_m1926_tx	 1049	//(internal1_m1926_tx) tx - время накопленное сек
#define internal1_m1926_y0	 BUFFER[2941]	//(internal1_m1926_y0) y0
#define idinternal1_m1926_y0	 1050	//(internal1_m1926_y0) y0
#define internal1_m1923_tx	 BUFFER[2942]	//(internal1_m1923_tx) tx - время накопленное сек
#define idinternal1_m1923_tx	 1051	//(internal1_m1923_tx) tx - время накопленное сек
#define internal1_m1923_y0	 BUFFER[2947]	//(internal1_m1923_y0) y0
#define idinternal1_m1923_y0	 1052	//(internal1_m1923_y0) y0
#define internal1_m2060_tx	 BUFFER[2948]	//(internal1_m2060_tx) tx - время накопленное сек
#define idinternal1_m2060_tx	 1053	//(internal1_m2060_tx) tx - время накопленное сек
#define internal1_m2060_y0	 BUFFER[2953]	//(internal1_m2060_y0) y0
#define idinternal1_m2060_y0	 1054	//(internal1_m2060_y0) y0
#define internal1_m2070_tx	 BUFFER[2954]	//(internal1_m2070_tx) tx - время накопленное сек
#define idinternal1_m2070_tx	 1055	//(internal1_m2070_tx) tx - время накопленное сек
#define internal1_m2070_y0	 BUFFER[2959]	//(internal1_m2070_y0) y0
#define idinternal1_m2070_y0	 1056	//(internal1_m2070_y0) y0
#define internal1_m1824_tx	 BUFFER[2960]	//(internal1_m1824_tx) tx - время накопленное сек
#define idinternal1_m1824_tx	 1057	//(internal1_m1824_tx) tx - время накопленное сек
#define internal1_m1824_y0	 BUFFER[2965]	//(internal1_m1824_y0) y0
#define idinternal1_m1824_y0	 1058	//(internal1_m1824_y0) y0
#define internal1_m1823_tx	 BUFFER[2966]	//(internal1_m1823_tx) tx - время накопленное сек
#define idinternal1_m1823_tx	 1059	//(internal1_m1823_tx) tx - время накопленное сек
#define internal1_m1823_y0	 BUFFER[2971]	//(internal1_m1823_y0) y0
#define idinternal1_m1823_y0	 1060	//(internal1_m1823_y0) y0
#define internal1_m1822_tx	 BUFFER[2972]	//(internal1_m1822_tx) tx - время накопленное сек
#define idinternal1_m1822_tx	 1061	//(internal1_m1822_tx) tx - время накопленное сек
#define internal1_m1822_y0	 BUFFER[2977]	//(internal1_m1822_y0) y0
#define idinternal1_m1822_y0	 1062	//(internal1_m1822_y0) y0
#define internal1_m1821_tx	 BUFFER[2978]	//(internal1_m1821_tx) tx - время накопленное сек
#define idinternal1_m1821_tx	 1063	//(internal1_m1821_tx) tx - время накопленное сек
#define internal1_m1821_y0	 BUFFER[2983]	//(internal1_m1821_y0) y0
#define idinternal1_m1821_y0	 1064	//(internal1_m1821_y0) y0
#define internal1_m1509_tx	 BUFFER[2984]	//(internal1_m1509_tx) tx - время накопленное сек
#define idinternal1_m1509_tx	 1065	//(internal1_m1509_tx) tx - время накопленное сек
#define internal1_m1509_y0	 BUFFER[2989]	//(internal1_m1509_y0) y0
#define idinternal1_m1509_y0	 1066	//(internal1_m1509_y0) y0
#define internal1_m1503_tx	 BUFFER[2990]	//(internal1_m1503_tx) tx - время накопленное сек
#define idinternal1_m1503_tx	 1067	//(internal1_m1503_tx) tx - время накопленное сек
#define internal1_m1503_y0	 BUFFER[2995]	//(internal1_m1503_y0) y0
#define idinternal1_m1503_y0	 1068	//(internal1_m1503_y0) y0
#define internal1_m1453_tx	 BUFFER[2996]	//(internal1_m1453_tx) tx - время накопленное сек
#define idinternal1_m1453_tx	 1069	//(internal1_m1453_tx) tx - время накопленное сек
#define internal1_m1453_y0	 BUFFER[3001]	//(internal1_m1453_y0) y0
#define idinternal1_m1453_y0	 1070	//(internal1_m1453_y0) y0
#define internal1_m838_tx	 BUFFER[3002]	//(internal1_m838_tx) tx - время накопленное сек
#define idinternal1_m838_tx	 1071	//(internal1_m838_tx) tx - время накопленное сек
#define internal1_m838_y0	 BUFFER[3007]	//(internal1_m838_y0) y0
#define idinternal1_m838_y0	 1072	//(internal1_m838_y0) y0
#define internal1_m837_tx	 BUFFER[3008]	//(internal1_m837_tx) tx - время накопленное сек
#define idinternal1_m837_tx	 1073	//(internal1_m837_tx) tx - время накопленное сек
#define internal1_m837_y0	 BUFFER[3013]	//(internal1_m837_y0) y0
#define idinternal1_m837_y0	 1074	//(internal1_m837_y0) y0
#define internal1_m844_tx	 BUFFER[3014]	//(internal1_m844_tx) tx - время накопленное сек
#define idinternal1_m844_tx	 1075	//(internal1_m844_tx) tx - время накопленное сек
#define internal1_m844_y0	 BUFFER[3019]	//(internal1_m844_y0) y0
#define idinternal1_m844_y0	 1076	//(internal1_m844_y0) y0
#define internal1_m203_tx	 BUFFER[3020]	//(internal1_m203_tx) tx - время накопленное сек
#define idinternal1_m203_tx	 1077	//(internal1_m203_tx) tx - время накопленное сек
#define internal1_m203_y0	 BUFFER[3025]	//(internal1_m203_y0) y0
#define idinternal1_m203_y0	 1078	//(internal1_m203_y0) y0
#define internal1_m207_tx	 BUFFER[3026]	//(internal1_m207_tx) tx - время накопленное сек
#define idinternal1_m207_tx	 1079	//(internal1_m207_tx) tx - время накопленное сек
#define internal1_m207_y0	 BUFFER[3031]	//(internal1_m207_y0) y0
#define idinternal1_m207_y0	 1080	//(internal1_m207_y0) y0
#define internal1_m214_tx	 BUFFER[3032]	//(internal1_m214_tx) tx - время накопленное сек
#define idinternal1_m214_tx	 1081	//(internal1_m214_tx) tx - время накопленное сек
#define internal1_m214_y0	 BUFFER[3037]	//(internal1_m214_y0) y0
#define idinternal1_m214_y0	 1082	//(internal1_m214_y0) y0
#define internal1_m533_tx	 BUFFER[3038]	//(internal1_m533_tx) tx - время накопленное сек
#define idinternal1_m533_tx	 1083	//(internal1_m533_tx) tx - время накопленное сек
#define internal1_m533_y0	 BUFFER[3043]	//(internal1_m533_y0) y0
#define idinternal1_m533_y0	 1084	//(internal1_m533_y0) y0
#define internal1_m2108_tx	 BUFFER[3044]	//(internal1_m2108_tx) tx - внутренний параметр
#define idinternal1_m2108_tx	 1085	//(internal1_m2108_tx) tx - внутренний параметр
#define internal1_m1198_tx	 BUFFER[3049]	//(internal1_m1198_tx) tx - внутренний параметр
#define idinternal1_m1198_tx	 1086	//(internal1_m1198_tx) tx - внутренний параметр
#define internal1_m1623_tx	 BUFFER[3054]	//(internal1_m1623_tx) tx - время накопленное сек
#define idinternal1_m1623_tx	 1087	//(internal1_m1623_tx) tx - время накопленное сек
#define internal1_m1623_y0	 BUFFER[3059]	//(internal1_m1623_y0) y0
#define idinternal1_m1623_y0	 1088	//(internal1_m1623_y0) y0
#define internal1_m1148_tx	 BUFFER[3060]	//(internal1_m1148_tx) tx - время накопленное сек
#define idinternal1_m1148_tx	 1089	//(internal1_m1148_tx) tx - время накопленное сек
#define internal1_m1148_y0	 BUFFER[3065]	//(internal1_m1148_y0) y0
#define idinternal1_m1148_y0	 1090	//(internal1_m1148_y0) y0
#define internal1_m1349_tx	 BUFFER[3066]	//(internal1_m1349_tx) tx - время накопленное сек
#define idinternal1_m1349_tx	 1091	//(internal1_m1349_tx) tx - время накопленное сек
#define internal1_m1349_y0	 BUFFER[3071]	//(internal1_m1349_y0) y0
#define idinternal1_m1349_y0	 1092	//(internal1_m1349_y0) y0
#define internal1_m937_tx	 BUFFER[3072]	//(internal1_m937_tx) tx - время накопленное сек
#define idinternal1_m937_tx	 1093	//(internal1_m937_tx) tx - время накопленное сек
#define internal1_m937_y0	 BUFFER[3077]	//(internal1_m937_y0) y0
#define idinternal1_m937_y0	 1094	//(internal1_m937_y0) y0
#define internal1_m1258_tx	 BUFFER[3078]	//(internal1_m1258_tx) tx - время накопленное сек
#define idinternal1_m1258_tx	 1095	//(internal1_m1258_tx) tx - время накопленное сек
#define internal1_m1258_y0	 BUFFER[3083]	//(internal1_m1258_y0) y0
#define idinternal1_m1258_y0	 1096	//(internal1_m1258_y0) y0
#define internal1_m1089_q0	 BUFFER[3084]	//(internal1_m1089_q0) q0 - внутренний параметр
#define idinternal1_m1089_q0	 1097	//(internal1_m1089_q0) q0 - внутренний параметр
#define internal1_m1087_q0	 BUFFER[3086]	//(internal1_m1087_q0) q0 - внутренний параметр
#define idinternal1_m1087_q0	 1098	//(internal1_m1087_q0) q0 - внутренний параметр
#define internal1_m1086_q0	 BUFFER[3088]	//(internal1_m1086_q0) q0 - внутренний параметр
#define idinternal1_m1086_q0	 1099	//(internal1_m1086_q0) q0 - внутренний параметр
#define internal1_m1084_q0	 BUFFER[3090]	//(internal1_m1084_q0) q0 - внутренний параметр
#define idinternal1_m1084_q0	 1100	//(internal1_m1084_q0) q0 - внутренний параметр
#define internal1_m1083_q0	 BUFFER[3092]	//(internal1_m1083_q0) q0 - внутренний параметр
#define idinternal1_m1083_q0	 1101	//(internal1_m1083_q0) q0 - внутренний параметр
#define internal1_m1081_q0	 BUFFER[3094]	//(internal1_m1081_q0) q0 - внутренний параметр
#define idinternal1_m1081_q0	 1102	//(internal1_m1081_q0) q0 - внутренний параметр
#define internal1_m1080_q0	 BUFFER[3096]	//(internal1_m1080_q0) q0 - внутренний параметр
#define idinternal1_m1080_q0	 1103	//(internal1_m1080_q0) q0 - внутренний параметр
#define internal1_m1078_q0	 BUFFER[3098]	//(internal1_m1078_q0) q0 - внутренний параметр
#define idinternal1_m1078_q0	 1104	//(internal1_m1078_q0) q0 - внутренний параметр
#define internal1_m1077_q0	 BUFFER[3100]	//(internal1_m1077_q0) q0 - внутренний параметр
#define idinternal1_m1077_q0	 1105	//(internal1_m1077_q0) q0 - внутренний параметр
#define internal1_m58_x0	 BUFFER[3102]	//(internal1_m58_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m58_x0	 1106	//(internal1_m58_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m997_q0	 BUFFER[3104]	//(internal1_m997_q0) q0 - внутренний параметр
#define idinternal1_m997_q0	 1107	//(internal1_m997_q0) q0 - внутренний параметр
#define internal1_m1446_x0	 BUFFER[3106]	//(internal1_m1446_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1446_x0	 1108	//(internal1_m1446_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1490_x0	 BUFFER[3108]	//(internal1_m1490_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1490_x0	 1109	//(internal1_m1490_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1486_x0	 BUFFER[3110]	//(internal1_m1486_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1486_x0	 1110	//(internal1_m1486_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1902_x0	 BUFFER[3112]	//(internal1_m1902_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1902_x0	 1111	//(internal1_m1902_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1867_x0	 BUFFER[3114]	//(internal1_m1867_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1867_x0	 1112	//(internal1_m1867_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1036_q0	 BUFFER[3116]	//(internal1_m1036_q0) q0 - внутренний параметр
#define idinternal1_m1036_q0	 1113	//(internal1_m1036_q0) q0 - внутренний параметр
#define internal1_m1048_q0	 BUFFER[3118]	//(internal1_m1048_q0) q0 - внутренний параметр
#define idinternal1_m1048_q0	 1114	//(internal1_m1048_q0) q0 - внутренний параметр
#define internal1_m1060_q0	 BUFFER[3120]	//(internal1_m1060_q0) q0 - внутренний параметр
#define idinternal1_m1060_q0	 1115	//(internal1_m1060_q0) q0 - внутренний параметр
#define internal1_m1070_q0	 BUFFER[3122]	//(internal1_m1070_q0) q0 - внутренний параметр
#define idinternal1_m1070_q0	 1116	//(internal1_m1070_q0) q0 - внутренний параметр
#define internal1_m1047_q0	 BUFFER[3124]	//(internal1_m1047_q0) q0 - внутренний параметр
#define idinternal1_m1047_q0	 1117	//(internal1_m1047_q0) q0 - внутренний параметр
#define internal1_m1062_q0	 BUFFER[3126]	//(internal1_m1062_q0) q0 - внутренний параметр
#define idinternal1_m1062_q0	 1118	//(internal1_m1062_q0) q0 - внутренний параметр
#define internal1_m1960_q0	 BUFFER[3128]	//(internal1_m1960_q0) q0 - внутренний параметр
#define idinternal1_m1960_q0	 1119	//(internal1_m1960_q0) q0 - внутренний параметр
#define internal1_m1959_q0	 BUFFER[3130]	//(internal1_m1959_q0) q0 - внутренний параметр
#define idinternal1_m1959_q0	 1120	//(internal1_m1959_q0) q0 - внутренний параметр
#define internal1_m341_Step	 BUFFER[3132]	//(internal1_m341_Step)  - текущий шаг программы
#define idinternal1_m341_Step	 1121	//(internal1_m341_Step)  - текущий шаг программы
#define internal1_m341_rz	 BUFFER[3135]	//(internal1_m341_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m341_rz	 1122	//(internal1_m341_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m341_TimS	 BUFFER[3145]	//(internal1_m341_TimS) Время от старта программы
#define idinternal1_m341_TimS	 1123	//(internal1_m341_TimS) Время от старта программы
#define internal1_m341_FinPr0	 BUFFER[3150]	//(internal1_m341_FinPr0) FinPr - конец программы
#define idinternal1_m341_FinPr0	 1124	//(internal1_m341_FinPr0) FinPr - конец программы
#define internal1_m341_ErrPr0	 BUFFER[3152]	//(internal1_m341_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m341_ErrPr0	 1125	//(internal1_m341_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m341_sbINI0	 BUFFER[3154]	//(internal1_m341_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m341_sbINI0	 1126	//(internal1_m341_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m341_sbVuIS0	 BUFFER[3156]	//(internal1_m341_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m341_sbVuIS0	 1127	//(internal1_m341_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m341_sb2UR0	 BUFFER[3158]	//(internal1_m341_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m341_sb2UR0	 1128	//(internal1_m341_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m341_sbNupIS0	 BUFFER[3160]	//(internal1_m341_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m341_sbNupIS0	 1129	//(internal1_m341_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m341_sbVuRB0	 BUFFER[3162]	//(internal1_m341_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m341_sbVuRB0	 1130	//(internal1_m341_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m341_MyFirstEnterFlag	 BUFFER[3164]	//(internal1_m341_MyFirstEnterFlag)  
#define idinternal1_m341_MyFirstEnterFlag	 1131	//(internal1_m341_MyFirstEnterFlag)  
#define internal1_m349_x0	 BUFFER[3166]	//(internal1_m349_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m349_x0	 1132	//(internal1_m349_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m309_TimS	 BUFFER[3171]	//(internal1_m309_TimS) Время старта
#define idinternal1_m309_TimS	 1133	//(internal1_m309_TimS) Время старта
#define internal1_m284_Step	 BUFFER[3176]	//(internal1_m284_Step)  - текущий шаг программы
#define idinternal1_m284_Step	 1134	//(internal1_m284_Step)  - текущий шаг программы
#define internal1_m284_rz	 BUFFER[3179]	//(internal1_m284_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m284_rz	 1135	//(internal1_m284_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m284_TimS	 BUFFER[3189]	//(internal1_m284_TimS) Время от старта программы
#define idinternal1_m284_TimS	 1136	//(internal1_m284_TimS) Время от старта программы
#define internal1_m284_FinPr0	 BUFFER[3194]	//(internal1_m284_FinPr0) FinPr - конец программы
#define idinternal1_m284_FinPr0	 1137	//(internal1_m284_FinPr0) FinPr - конец программы
#define internal1_m284_ErrPr0	 BUFFER[3196]	//(internal1_m284_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m284_ErrPr0	 1138	//(internal1_m284_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m284_sbINI0	 BUFFER[3198]	//(internal1_m284_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m284_sbINI0	 1139	//(internal1_m284_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m284_sbVuIS0	 BUFFER[3200]	//(internal1_m284_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m284_sbVuIS0	 1140	//(internal1_m284_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m284_sb2UR0	 BUFFER[3202]	//(internal1_m284_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m284_sb2UR0	 1141	//(internal1_m284_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m284_sbNupIS0	 BUFFER[3204]	//(internal1_m284_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m284_sbNupIS0	 1142	//(internal1_m284_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m284_sbVuRB0	 BUFFER[3206]	//(internal1_m284_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m284_sbVuRB0	 1143	//(internal1_m284_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m284_MyFirstEnterFlag	 BUFFER[3208]	//(internal1_m284_MyFirstEnterFlag)  
#define idinternal1_m284_MyFirstEnterFlag	 1144	//(internal1_m284_MyFirstEnterFlag)  
#define internal1_m1420_q0	 BUFFER[3210]	//(internal1_m1420_q0) q0 - внутренний параметр
#define idinternal1_m1420_q0	 1145	//(internal1_m1420_q0) q0 - внутренний параметр
#define internal1_m1421_Step	 BUFFER[3212]	//(internal1_m1421_Step)  - текущий шаг программы
#define idinternal1_m1421_Step	 1146	//(internal1_m1421_Step)  - текущий шаг программы
#define internal1_m1421_rz	 BUFFER[3215]	//(internal1_m1421_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m1421_rz	 1147	//(internal1_m1421_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m1421_TimS	 BUFFER[3221]	//(internal1_m1421_TimS) Время от старта программы
#define idinternal1_m1421_TimS	 1148	//(internal1_m1421_TimS) Время от старта программы
#define internal1_m1421_FinPr0	 BUFFER[3226]	//(internal1_m1421_FinPr0) FinPr - конец программы
#define idinternal1_m1421_FinPr0	 1149	//(internal1_m1421_FinPr0) FinPr - конец программы
#define internal1_m1421_ErrPr0	 BUFFER[3228]	//(internal1_m1421_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m1421_ErrPr0	 1150	//(internal1_m1421_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m1421_sbINI0	 BUFFER[3230]	//(internal1_m1421_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m1421_sbINI0	 1151	//(internal1_m1421_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m1421_sbVuIS0	 BUFFER[3232]	//(internal1_m1421_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m1421_sbVuIS0	 1152	//(internal1_m1421_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m1421_sb2UR0	 BUFFER[3234]	//(internal1_m1421_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m1421_sb2UR0	 1153	//(internal1_m1421_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m1421_sbNupIS0	 BUFFER[3236]	//(internal1_m1421_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m1421_sbNupIS0	 1154	//(internal1_m1421_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m1421_sbVuRB0	 BUFFER[3238]	//(internal1_m1421_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m1421_sbVuRB0	 1155	//(internal1_m1421_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m1421_MyFirstEnterFlag	 BUFFER[3240]	//(internal1_m1421_MyFirstEnterFlag)  
#define idinternal1_m1421_MyFirstEnterFlag	 1156	//(internal1_m1421_MyFirstEnterFlag)  
#define internal1_m1032_q0	 BUFFER[3242]	//(internal1_m1032_q0) q0 - внутренний параметр
#define idinternal1_m1032_q0	 1157	//(internal1_m1032_q0) q0 - внутренний параметр
#define internal1_m1029_q0	 BUFFER[3244]	//(internal1_m1029_q0) q0 - внутренний параметр
#define idinternal1_m1029_q0	 1158	//(internal1_m1029_q0) q0 - внутренний параметр
#define internal1_m1031_q0	 BUFFER[3246]	//(internal1_m1031_q0) q0 - внутренний параметр
#define idinternal1_m1031_q0	 1159	//(internal1_m1031_q0) q0 - внутренний параметр
#define internal1_m1025_q0	 BUFFER[3248]	//(internal1_m1025_q0) q0 - внутренний параметр
#define idinternal1_m1025_q0	 1160	//(internal1_m1025_q0) q0 - внутренний параметр
#define internal1_m758_q0	 BUFFER[3250]	//(internal1_m758_q0) q0 - внутренний параметр
#define idinternal1_m758_q0	 1161	//(internal1_m758_q0) q0 - внутренний параметр
#define internal1_m351_q0	 BUFFER[3252]	//(internal1_m351_q0) q0 - внутренний параметр
#define idinternal1_m351_q0	 1162	//(internal1_m351_q0) q0 - внутренний параметр
#define internal1_m347_q0	 BUFFER[3254]	//(internal1_m347_q0) q0 - внутренний параметр
#define idinternal1_m347_q0	 1163	//(internal1_m347_q0) q0 - внутренний параметр
#define internal1_m304_q0	 BUFFER[3256]	//(internal1_m304_q0) q0 - внутренний параметр
#define idinternal1_m304_q0	 1164	//(internal1_m304_q0) q0 - внутренний параметр
#define internal1_m303_x0	 BUFFER[3258]	//(internal1_m303_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m303_x0	 1165	//(internal1_m303_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1889_q0	 BUFFER[3263]	//(internal1_m1889_q0) q0 - внутренний параметр
#define idinternal1_m1889_q0	 1166	//(internal1_m1889_q0) q0 - внутренний параметр
#define internal1_m1877_q0	 BUFFER[3265]	//(internal1_m1877_q0) q0 - внутренний параметр
#define idinternal1_m1877_q0	 1167	//(internal1_m1877_q0) q0 - внутренний параметр
#define internal1_m1868_q0	 BUFFER[3267]	//(internal1_m1868_q0) q0 - внутренний параметр
#define idinternal1_m1868_q0	 1168	//(internal1_m1868_q0) q0 - внутренний параметр
#define internal1_m1943_q0	 BUFFER[3269]	//(internal1_m1943_q0) q0 - внутренний параметр
#define idinternal1_m1943_q0	 1169	//(internal1_m1943_q0) q0 - внутренний параметр
#define internal1_m1914_q0	 BUFFER[3271]	//(internal1_m1914_q0) q0 - внутренний параметр
#define idinternal1_m1914_q0	 1170	//(internal1_m1914_q0) q0 - внутренний параметр
#define internal1_m1903_q0	 BUFFER[3273]	//(internal1_m1903_q0) q0 - внутренний параметр
#define idinternal1_m1903_q0	 1171	//(internal1_m1903_q0) q0 - внутренний параметр
#define internal1_m1473_q0	 BUFFER[3275]	//(internal1_m1473_q0) q0 - внутренний параметр
#define idinternal1_m1473_q0	 1172	//(internal1_m1473_q0) q0 - внутренний параметр
#define internal1_m1460_x0	 BUFFER[3277]	//(internal1_m1460_x0) был приход сигнала x1
#define idinternal1_m1460_x0	 1173	//(internal1_m1460_x0) был приход сигнала x1
#define internal1_m1460_y0	 BUFFER[3279]	//(internal1_m1460_y0) интервал между сигналами х1 и х2
#define idinternal1_m1460_y0	 1174	//(internal1_m1460_y0) интервал между сигналами х1 и х2
#define internal1_m1456_q0	 BUFFER[3284]	//(internal1_m1456_q0) q0 - внутренний параметр
#define idinternal1_m1456_q0	 1175	//(internal1_m1456_q0) q0 - внутренний параметр
#define internal1_m1447_q0	 BUFFER[3286]	//(internal1_m1447_q0) q0 - внутренний параметр
#define idinternal1_m1447_q0	 1176	//(internal1_m1447_q0) q0 - внутренний параметр
#define internal1_m1506_q0	 BUFFER[3288]	//(internal1_m1506_q0) q0 - внутренний параметр
#define idinternal1_m1506_q0	 1177	//(internal1_m1506_q0) q0 - внутренний параметр
#define internal1_m1526_q0	 BUFFER[3290]	//(internal1_m1526_q0) q0 - внутренний параметр
#define idinternal1_m1526_q0	 1178	//(internal1_m1526_q0) q0 - внутренний параметр
#define internal1_m1492_q0	 BUFFER[3292]	//(internal1_m1492_q0) q0 - внутренний параметр
#define idinternal1_m1492_q0	 1179	//(internal1_m1492_q0) q0 - внутренний параметр
#define internal1_m1507_x0	 BUFFER[3294]	//(internal1_m1507_x0) был приход сигнала x1
#define idinternal1_m1507_x0	 1180	//(internal1_m1507_x0) был приход сигнала x1
#define internal1_m1507_y0	 BUFFER[3296]	//(internal1_m1507_y0) интервал между сигналами х1 и х2
#define idinternal1_m1507_y0	 1181	//(internal1_m1507_y0) интервал между сигналами х1 и х2
#define internal1_m1431_x0	 BUFFER[3301]	//(internal1_m1431_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1431_x0	 1182	//(internal1_m1431_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1512_q0	 BUFFER[3306]	//(internal1_m1512_q0) q0 - внутренний параметр
#define idinternal1_m1512_q0	 1183	//(internal1_m1512_q0) q0 - внутренний параметр
#define internal1_m29_q0	 BUFFER[3308]	//(internal1_m29_q0) q0 - внутренний параметр
#define idinternal1_m29_q0	 1184	//(internal1_m29_q0) q0 - внутренний параметр
#define internal1_m1527_q0	 BUFFER[3310]	//(internal1_m1527_q0) q0 - внутренний параметр
#define idinternal1_m1527_q0	 1185	//(internal1_m1527_q0) q0 - внутренний параметр
#define internal1_m648_q0	 BUFFER[3312]	//(internal1_m648_q0) q0 - внутренний параметр
#define idinternal1_m648_q0	 1186	//(internal1_m648_q0) q0 - внутренний параметр
#define internal1_m633_q0	 BUFFER[3314]	//(internal1_m633_q0) q0 - внутренний параметр
#define idinternal1_m633_q0	 1187	//(internal1_m633_q0) q0 - внутренний параметр
#define internal1_m661_q0	 BUFFER[3316]	//(internal1_m661_q0) q0 - внутренний параметр
#define idinternal1_m661_q0	 1188	//(internal1_m661_q0) q0 - внутренний параметр
#define internal1_m644_q0	 BUFFER[3318]	//(internal1_m644_q0) q0 - внутренний параметр
#define idinternal1_m644_q0	 1189	//(internal1_m644_q0) q0 - внутренний параметр
#define internal1_m628_q0	 BUFFER[3320]	//(internal1_m628_q0) q0 - внутренний параметр
#define idinternal1_m628_q0	 1190	//(internal1_m628_q0) q0 - внутренний параметр
#define internal1_m626_q0	 BUFFER[3322]	//(internal1_m626_q0) q0 - внутренний параметр
#define idinternal1_m626_q0	 1191	//(internal1_m626_q0) q0 - внутренний параметр
#define internal1_m614_q0	 BUFFER[3324]	//(internal1_m614_q0) q0 - внутренний параметр
#define idinternal1_m614_q0	 1192	//(internal1_m614_q0) q0 - внутренний параметр
#define internal1_m1423_q0	 BUFFER[3326]	//(internal1_m1423_q0) q0 - внутренний параметр
#define idinternal1_m1423_q0	 1193	//(internal1_m1423_q0) q0 - внутренний параметр
#define internal1_m624_q0	 BUFFER[3331]	//(internal1_m624_q0) q0 - внутренний параметр
#define idinternal1_m624_q0	 1194	//(internal1_m624_q0) q0 - внутренний параметр
#define internal1_m115_q0	 BUFFER[3333]	//(internal1_m115_q0) q0 - внутренний параметр
#define idinternal1_m115_q0	 1195	//(internal1_m115_q0) q0 - внутренний параметр
#define internal1_m1659_q0	 BUFFER[3335]	//(internal1_m1659_q0) q0 - внутренний параметр
#define idinternal1_m1659_q0	 1196	//(internal1_m1659_q0) q0 - внутренний параметр
#define internal1_m1658_q0	 BUFFER[3337]	//(internal1_m1658_q0) q0 - внутренний параметр
#define idinternal1_m1658_q0	 1197	//(internal1_m1658_q0) q0 - внутренний параметр
#define internal1_m1657_q0	 BUFFER[3339]	//(internal1_m1657_q0) q0 - внутренний параметр
#define idinternal1_m1657_q0	 1198	//(internal1_m1657_q0) q0 - внутренний параметр
#define internal1_m1656_q0	 BUFFER[3341]	//(internal1_m1656_q0) q0 - внутренний параметр
#define idinternal1_m1656_q0	 1199	//(internal1_m1656_q0) q0 - внутренний параметр
#define internal1_m1694_q0	 BUFFER[3343]	//(internal1_m1694_q0) q0 - внутренний параметр
#define idinternal1_m1694_q0	 1200	//(internal1_m1694_q0) q0 - внутренний параметр
#define internal1_m1693_q0	 BUFFER[3345]	//(internal1_m1693_q0) q0 - внутренний параметр
#define idinternal1_m1693_q0	 1201	//(internal1_m1693_q0) q0 - внутренний параметр
#define internal1_m1692_q0	 BUFFER[3347]	//(internal1_m1692_q0) q0 - внутренний параметр
#define idinternal1_m1692_q0	 1202	//(internal1_m1692_q0) q0 - внутренний параметр
#define internal1_m1974_q0	 BUFFER[3349]	//(internal1_m1974_q0) q0 - внутренний параметр
#define idinternal1_m1974_q0	 1203	//(internal1_m1974_q0) q0 - внутренний параметр
#define internal1_m1754_q0	 BUFFER[3351]	//(internal1_m1754_q0) q0 - внутренний параметр
#define idinternal1_m1754_q0	 1204	//(internal1_m1754_q0) q0 - внутренний параметр
#define internal1_m1743_q0	 BUFFER[3353]	//(internal1_m1743_q0) q0 - внутренний параметр
#define idinternal1_m1743_q0	 1205	//(internal1_m1743_q0) q0 - внутренний параметр
#define internal1_m1751_q0	 BUFFER[3355]	//(internal1_m1751_q0) q0 - внутренний параметр
#define idinternal1_m1751_q0	 1206	//(internal1_m1751_q0) q0 - внутренний параметр
#define internal1_m1740_q0	 BUFFER[3357]	//(internal1_m1740_q0) q0 - внутренний параметр
#define idinternal1_m1740_q0	 1207	//(internal1_m1740_q0) q0 - внутренний параметр
#define internal1_m1748_q0	 BUFFER[3359]	//(internal1_m1748_q0) q0 - внутренний параметр
#define idinternal1_m1748_q0	 1208	//(internal1_m1748_q0) q0 - внутренний параметр
#define internal1_m2174_q0	 BUFFER[3361]	//(internal1_m2174_q0) q0 - внутренний параметр
#define idinternal1_m2174_q0	 1209	//(internal1_m2174_q0) q0 - внутренний параметр
#define internal1_m2170_q0	 BUFFER[3363]	//(internal1_m2170_q0) q0 - внутренний параметр
#define idinternal1_m2170_q0	 1210	//(internal1_m2170_q0) q0 - внутренний параметр
#define internal1_m1719_q0	 BUFFER[3365]	//(internal1_m1719_q0) q0 - внутренний параметр
#define idinternal1_m1719_q0	 1211	//(internal1_m1719_q0) q0 - внутренний параметр
#define internal1_m1711_q0	 BUFFER[3367]	//(internal1_m1711_q0) q0 - внутренний параметр
#define idinternal1_m1711_q0	 1212	//(internal1_m1711_q0) q0 - внутренний параметр
#define internal1_m1709_q0	 BUFFER[3369]	//(internal1_m1709_q0) q0 - внутренний параметр
#define idinternal1_m1709_q0	 1213	//(internal1_m1709_q0) q0 - внутренний параметр
#define internal1_m1705_q0	 BUFFER[3371]	//(internal1_m1705_q0) q0 - внутренний параметр
#define idinternal1_m1705_q0	 1214	//(internal1_m1705_q0) q0 - внутренний параметр
#define internal1_m1701_q0	 BUFFER[3373]	//(internal1_m1701_q0) q0 - внутренний параметр
#define idinternal1_m1701_q0	 1215	//(internal1_m1701_q0) q0 - внутренний параметр
#define internal1_m1703_q0	 BUFFER[3375]	//(internal1_m1703_q0) q0 - внутренний параметр
#define idinternal1_m1703_q0	 1216	//(internal1_m1703_q0) q0 - внутренний параметр
#define internal1_m22_q0	 BUFFER[3377]	//(internal1_m22_q0) q0 - внутренний параметр
#define idinternal1_m22_q0	 1217	//(internal1_m22_q0) q0 - внутренний параметр
#define internal1_m1682_q0	 BUFFER[3379]	//(internal1_m1682_q0) q0 - внутренний параметр
#define idinternal1_m1682_q0	 1218	//(internal1_m1682_q0) q0 - внутренний параметр
#define internal1_m1680_q0	 BUFFER[3381]	//(internal1_m1680_q0) q0 - внутренний параметр
#define idinternal1_m1680_q0	 1219	//(internal1_m1680_q0) q0 - внутренний параметр
#define internal1_m1676_q0	 BUFFER[3383]	//(internal1_m1676_q0) q0 - внутренний параметр
#define idinternal1_m1676_q0	 1220	//(internal1_m1676_q0) q0 - внутренний параметр
#define internal1_m1678_q0	 BUFFER[3385]	//(internal1_m1678_q0) q0 - внутренний параметр
#define idinternal1_m1678_q0	 1221	//(internal1_m1678_q0) q0 - внутренний параметр
#define internal1_m1674_q0	 BUFFER[3387]	//(internal1_m1674_q0) q0 - внутренний параметр
#define idinternal1_m1674_q0	 1222	//(internal1_m1674_q0) q0 - внутренний параметр
#define internal1_m1672_q0	 BUFFER[3389]	//(internal1_m1672_q0) q0 - внутренний параметр
#define idinternal1_m1672_q0	 1223	//(internal1_m1672_q0) q0 - внутренний параметр
#define internal1_m2090_q0	 BUFFER[3391]	//(internal1_m2090_q0) q0 - внутренний параметр
#define idinternal1_m2090_q0	 1224	//(internal1_m2090_q0) q0 - внутренний параметр
#define internal1_m2085_q0	 BUFFER[3393]	//(internal1_m2085_q0) q0 - внутренний параметр
#define idinternal1_m2085_q0	 1225	//(internal1_m2085_q0) q0 - внутренний параметр
#define internal1_m2064_q0	 BUFFER[3395]	//(internal1_m2064_q0) q0 - внутренний параметр
#define idinternal1_m2064_q0	 1226	//(internal1_m2064_q0) q0 - внутренний параметр
#define internal1_m2052_q0	 BUFFER[3397]	//(internal1_m2052_q0) q0 - внутренний параметр
#define idinternal1_m2052_q0	 1227	//(internal1_m2052_q0) q0 - внутренний параметр
#define internal1_m1985_q0	 BUFFER[3399]	//(internal1_m1985_q0) q0 - внутренний параметр
#define idinternal1_m1985_q0	 1228	//(internal1_m1985_q0) q0 - внутренний параметр
#define internal1_m1668_q0	 BUFFER[3401]	//(internal1_m1668_q0) q0 - внутренний параметр
#define idinternal1_m1668_q0	 1229	//(internal1_m1668_q0) q0 - внутренний параметр
#define internal1_m1670_q0	 BUFFER[3403]	//(internal1_m1670_q0) q0 - внутренний параметр
#define idinternal1_m1670_q0	 1230	//(internal1_m1670_q0) q0 - внутренний параметр
#define internal1_m1654_q0	 BUFFER[3405]	//(internal1_m1654_q0) q0 - внутренний параметр
#define idinternal1_m1654_q0	 1231	//(internal1_m1654_q0) q0 - внутренний параметр
#define internal1_m1652_q0	 BUFFER[3407]	//(internal1_m1652_q0) q0 - внутренний параметр
#define idinternal1_m1652_q0	 1232	//(internal1_m1652_q0) q0 - внутренний параметр
#define internal1_m1650_q0	 BUFFER[3409]	//(internal1_m1650_q0) q0 - внутренний параметр
#define idinternal1_m1650_q0	 1233	//(internal1_m1650_q0) q0 - внутренний параметр
#define internal1_m1648_q0	 BUFFER[3411]	//(internal1_m1648_q0) q0 - внутренний параметр
#define idinternal1_m1648_q0	 1234	//(internal1_m1648_q0) q0 - внутренний параметр
#define internal1_m1647_q0	 BUFFER[3413]	//(internal1_m1647_q0) q0 - внутренний параметр
#define idinternal1_m1647_q0	 1235	//(internal1_m1647_q0) q0 - внутренний параметр
#define internal1_m1645_q0	 BUFFER[3415]	//(internal1_m1645_q0) q0 - внутренний параметр
#define idinternal1_m1645_q0	 1236	//(internal1_m1645_q0) q0 - внутренний параметр
#define internal1_m1644_q0	 BUFFER[3417]	//(internal1_m1644_q0) q0 - внутренний параметр
#define idinternal1_m1644_q0	 1237	//(internal1_m1644_q0) q0 - внутренний параметр
#define internal1_m1642_q0	 BUFFER[3419]	//(internal1_m1642_q0) q0 - внутренний параметр
#define idinternal1_m1642_q0	 1238	//(internal1_m1642_q0) q0 - внутренний параметр
#define internal1_m2113_DvUp0	 BUFFER[3421]	//(internal1_m2113_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2113_DvUp0	 1239	//(internal1_m2113_DvUp0) - есть команда на движение вперёд
#define internal1_m2113_DvDw0	 BUFFER[3422]	//(internal1_m2113_DvDw0) - есть команда на движение назад
#define idinternal1_m2113_DvDw0	 1240	//(internal1_m2113_DvDw0) - есть команда на движение назад
#define internal1_m2113_FDvUp0	 BUFFER[3423]	//(internal1_m2113_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2113_FDvUp0	 1241	//(internal1_m2113_FDvUp0) - есть команда на движение вперёд
#define internal1_m2113_FDvDw0	 BUFFER[3424]	//(internal1_m2113_FDvDw0) - есть команда на движение назад
#define idinternal1_m2113_FDvDw0	 1242	//(internal1_m2113_FDvDw0) - есть команда на движение назад
#define internal1_m2113_BlDv0	 BUFFER[3425]	//(internal1_m2113_BlDv0) - была блокировка
#define idinternal1_m2113_BlDv0	 1243	//(internal1_m2113_BlDv0) - была блокировка
#define internal1_m2113_Pkv0	 BUFFER[3426]	//(internal1_m2113_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2113_Pkv0	 1244	//(internal1_m2113_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2113_Pkav0	 BUFFER[3427]	//(internal1_m2113_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2113_Pkav0	 1245	//(internal1_m2113_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2113_Zkv0	 BUFFER[3428]	//(internal1_m2113_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2113_Zkv0	 1246	//(internal1_m2113_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2113_Zkav0	 BUFFER[3429]	//(internal1_m2113_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2113_Zkav0	 1247	//(internal1_m2113_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2113_txNm	 BUFFER[3430]	//(internal1_m2113_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2113_txNm	 1248	//(internal1_m2113_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2113_txSm	 BUFFER[3435]	//(internal1_m2113_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2113_txSm	 1249	//(internal1_m2113_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2113_txHr	 BUFFER[3440]	//(internal1_m2113_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2113_txHr	 1250	//(internal1_m2113_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2113_txLd	 BUFFER[3445]	//(internal1_m2113_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2113_txLd	 1251	//(internal1_m2113_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2113_fef	 BUFFER[3450]	//(internal1_m2113_fef) fef
#define idinternal1_m2113_fef	 1252	//(internal1_m2113_fef) fef
#define internal1_m2107_DvUp0	 BUFFER[3451]	//(internal1_m2107_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2107_DvUp0	 1253	//(internal1_m2107_DvUp0) - есть команда на движение вперёд
#define internal1_m2107_DvDw0	 BUFFER[3452]	//(internal1_m2107_DvDw0) - есть команда на движение назад
#define idinternal1_m2107_DvDw0	 1254	//(internal1_m2107_DvDw0) - есть команда на движение назад
#define internal1_m2107_FDvUp0	 BUFFER[3453]	//(internal1_m2107_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2107_FDvUp0	 1255	//(internal1_m2107_FDvUp0) - есть команда на движение вперёд
#define internal1_m2107_FDvDw0	 BUFFER[3454]	//(internal1_m2107_FDvDw0) - есть команда на движение назад
#define idinternal1_m2107_FDvDw0	 1256	//(internal1_m2107_FDvDw0) - есть команда на движение назад
#define internal1_m2107_BlDv0	 BUFFER[3455]	//(internal1_m2107_BlDv0) - была блокировка
#define idinternal1_m2107_BlDv0	 1257	//(internal1_m2107_BlDv0) - была блокировка
#define internal1_m2107_Pkv0	 BUFFER[3456]	//(internal1_m2107_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2107_Pkv0	 1258	//(internal1_m2107_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2107_Pkav0	 BUFFER[3457]	//(internal1_m2107_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2107_Pkav0	 1259	//(internal1_m2107_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2107_Zkv0	 BUFFER[3458]	//(internal1_m2107_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2107_Zkv0	 1260	//(internal1_m2107_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2107_Zkav0	 BUFFER[3459]	//(internal1_m2107_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2107_Zkav0	 1261	//(internal1_m2107_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2107_txNm	 BUFFER[3460]	//(internal1_m2107_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2107_txNm	 1262	//(internal1_m2107_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2107_txSm	 BUFFER[3465]	//(internal1_m2107_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2107_txSm	 1263	//(internal1_m2107_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2107_txHr	 BUFFER[3470]	//(internal1_m2107_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2107_txHr	 1264	//(internal1_m2107_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2107_txLd	 BUFFER[3475]	//(internal1_m2107_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2107_txLd	 1265	//(internal1_m2107_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2107_fef	 BUFFER[3480]	//(internal1_m2107_fef) fef
#define idinternal1_m2107_fef	 1266	//(internal1_m2107_fef) fef
#define internal1_m1498_q0	 BUFFER[3481]	//(internal1_m1498_q0) q0 - внутренний параметр
#define idinternal1_m1498_q0	 1267	//(internal1_m1498_q0) q0 - внутренний параметр
#define internal1_m1501_x0	 BUFFER[3483]	//(internal1_m1501_x0) был приход сигнала x1
#define idinternal1_m1501_x0	 1268	//(internal1_m1501_x0) был приход сигнала x1
#define internal1_m1501_y0	 BUFFER[3485]	//(internal1_m1501_y0) интервал между сигналами х1 и х2
#define idinternal1_m1501_y0	 1269	//(internal1_m1501_y0) интервал между сигналами х1 и х2
#define internal1_m1925_x0	 BUFFER[3490]	//(internal1_m1925_x0) был приход сигнала x1
#define idinternal1_m1925_x0	 1270	//(internal1_m1925_x0) был приход сигнала x1
#define internal1_m1925_y0	 BUFFER[3492]	//(internal1_m1925_y0) интервал между сигналами х1 и х2
#define idinternal1_m1925_y0	 1271	//(internal1_m1925_y0) интервал между сигналами х1 и х2
#define internal1_m1886_x0	 BUFFER[3497]	//(internal1_m1886_x0) был приход сигнала x1
#define idinternal1_m1886_x0	 1272	//(internal1_m1886_x0) был приход сигнала x1
#define internal1_m1886_y0	 BUFFER[3499]	//(internal1_m1886_y0) интервал между сигналами х1 и х2
#define idinternal1_m1886_y0	 1273	//(internal1_m1886_y0) интервал между сигналами х1 и х2
#define internal1_m295_q0	 BUFFER[3504]	//(internal1_m295_q0) q0 - внутренний параметр
#define idinternal1_m295_q0	 1274	//(internal1_m295_q0) q0 - внутренний параметр
#define internal1_m1005_q0	 BUFFER[3506]	//(internal1_m1005_q0) q0 - внутренний параметр
#define idinternal1_m1005_q0	 1275	//(internal1_m1005_q0) q0 - внутренний параметр
#define internal1_m636_q0	 BUFFER[3508]	//(internal1_m636_q0) q0 - внутренний параметр
#define idinternal1_m636_q0	 1276	//(internal1_m636_q0) q0 - внутренний параметр
#define internal1_m1320_X0	 BUFFER[3510]	//(internal1_m1320_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1320_X0	 1277	//(internal1_m1320_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1320_t0	 BUFFER[3515]	//(internal1_m1320_t0) время нахождения в зоне возврата
#define idinternal1_m1320_t0	 1278	//(internal1_m1320_t0) время нахождения в зоне возврата
#define internal1_m1320_BLDv0	 BUFFER[3520]	//(internal1_m1320_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1320_BLDv0	 1279	//(internal1_m1320_BLDv0) BlDv - Блокировка движения
#define internal1_m1339_tx	 BUFFER[3521]	//(internal1_m1339_tx) tx - время накопленное сек
#define idinternal1_m1339_tx	 1280	//(internal1_m1339_tx) tx - время накопленное сек
#define internal1_m1339_y0	 BUFFER[3526]	//(internal1_m1339_y0) y0
#define idinternal1_m1339_y0	 1281	//(internal1_m1339_y0) y0
#define internal1_m1341_tx	 BUFFER[3527]	//(internal1_m1341_tx) tx - время накопленное сек
#define idinternal1_m1341_tx	 1282	//(internal1_m1341_tx) tx - время накопленное сек
#define internal1_m1341_y0	 BUFFER[3532]	//(internal1_m1341_y0) y0
#define idinternal1_m1341_y0	 1283	//(internal1_m1341_y0) y0
#define internal1_m1348_xptr	 BUFFER[3533]	//(internal1_m1348_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1348_xptr	 1284	//(internal1_m1348_xptr) указатель текущей позиции в массиве координат
#define internal1_m1348_x0	 BUFFER[3536]	//(internal1_m1348_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1348_x0	 1285	//(internal1_m1348_x0) x0 - массив мгновенных значений координат
#define internal1_m1348_tim0	 BUFFER[3836]	//(internal1_m1348_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1348_tim0	 1286	//(internal1_m1348_tim0) tim0 - массив значений времени цикла
#define internal1_m1348_sumtim	 BUFFER[4136]	//(internal1_m1348_sumtim) sumtim - время в пути
#define idinternal1_m1348_sumtim	 1287	//(internal1_m1348_sumtim) sumtim - время в пути
#define internal1_m1348_StSpeed	 BUFFER[4141]	//(internal1_m1348_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1348_StSpeed	 1288	//(internal1_m1348_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1348_Vz0	 BUFFER[4146]	//(internal1_m1348_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1348_Vz0	 1289	//(internal1_m1348_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1348_flRazg	 BUFFER[4151]	//(internal1_m1348_flRazg) признак разгона/торможения
#define idinternal1_m1348_flRazg	 1290	//(internal1_m1348_flRazg) признак разгона/торможения
#define internal1_m1348_DelSp	 BUFFER[4154]	//(internal1_m1348_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1348_DelSp	 1291	//(internal1_m1348_DelSp) DelSp - время переключения скоростей
#define internal1_m1348_z0	 BUFFER[4159]	//(internal1_m1348_z0) z0 - точка прекращения движения
#define idinternal1_m1348_z0	 1292	//(internal1_m1348_z0) z0 - точка прекращения движения
#define internal1_m1348_txZS	 BUFFER[4164]	//(internal1_m1348_txZS) txZS
#define idinternal1_m1348_txZS	 1293	//(internal1_m1348_txZS) txZS
#define internal1_m1348_tx	 BUFFER[4169]	//(internal1_m1348_tx) tx
#define idinternal1_m1348_tx	 1294	//(internal1_m1348_tx) tx
#define internal1_m1348_txd	 BUFFER[4174]	//(internal1_m1348_txd) txd
#define idinternal1_m1348_txd	 1295	//(internal1_m1348_txd) txd
#define internal1_m1348_txMBl	 BUFFER[4179]	//(internal1_m1348_txMBl) tx
#define idinternal1_m1348_txMBl	 1296	//(internal1_m1348_txMBl) tx
#define internal1_m1348_txBl	 BUFFER[4184]	//(internal1_m1348_txBl) tx
#define idinternal1_m1348_txBl	 1297	//(internal1_m1348_txBl) tx
#define internal1_m1348_Speed0	 BUFFER[4189]	//(internal1_m1348_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1348_Speed0	 1298	//(internal1_m1348_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1348_xz0	 BUFFER[4194]	//(internal1_m1348_xz0) xz0 - новое задание мм
#define idinternal1_m1348_xz0	 1299	//(internal1_m1348_xz0) xz0 - новое задание мм
#define internal1_m1348_tz0	 BUFFER[4199]	//(internal1_m1348_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1348_tz0	 1300	//(internal1_m1348_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1348_Shift0	 BUFFER[4204]	//(internal1_m1348_Shift0) Shift0 - признак самохода
#define idinternal1_m1348_Shift0	 1301	//(internal1_m1348_Shift0) Shift0 - признак самохода
#define internal1_m1348_ShCntlSp0	 BUFFER[4206]	//(internal1_m1348_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1348_ShCntlSp0	 1302	//(internal1_m1348_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1348_ShiftControl	 BUFFER[4208]	//(internal1_m1348_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1348_ShiftControl	 1303	//(internal1_m1348_ShiftControl) ShiftControl - признак самохода
#define internal1_m634_q0	 BUFFER[4210]	//(internal1_m634_q0) q0 - внутренний параметр
#define idinternal1_m634_q0	 1304	//(internal1_m634_q0) q0 - внутренний параметр
#define internal1_m903_X0	 BUFFER[4212]	//(internal1_m903_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m903_X0	 1305	//(internal1_m903_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m903_t0	 BUFFER[4217]	//(internal1_m903_t0) время нахождения в зоне возврата
#define idinternal1_m903_t0	 1306	//(internal1_m903_t0) время нахождения в зоне возврата
#define internal1_m903_BLDv0	 BUFFER[4222]	//(internal1_m903_BLDv0) BlDv - Блокировка движения
#define idinternal1_m903_BLDv0	 1307	//(internal1_m903_BLDv0) BlDv - Блокировка движения
#define internal1_m927_tx	 BUFFER[4223]	//(internal1_m927_tx) tx - время накопленное сек
#define idinternal1_m927_tx	 1308	//(internal1_m927_tx) tx - время накопленное сек
#define internal1_m927_y0	 BUFFER[4228]	//(internal1_m927_y0) y0
#define idinternal1_m927_y0	 1309	//(internal1_m927_y0) y0
#define internal1_m930_tx	 BUFFER[4229]	//(internal1_m930_tx) tx - время накопленное сек
#define idinternal1_m930_tx	 1310	//(internal1_m930_tx) tx - время накопленное сек
#define internal1_m930_y0	 BUFFER[4234]	//(internal1_m930_y0) y0
#define idinternal1_m930_y0	 1311	//(internal1_m930_y0) y0
#define internal1_m936_xptr	 BUFFER[4235]	//(internal1_m936_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m936_xptr	 1312	//(internal1_m936_xptr) указатель текущей позиции в массиве координат
#define internal1_m936_x0	 BUFFER[4238]	//(internal1_m936_x0) x0 - массив мгновенных значений координат
#define idinternal1_m936_x0	 1313	//(internal1_m936_x0) x0 - массив мгновенных значений координат
#define internal1_m936_tim0	 BUFFER[4538]	//(internal1_m936_tim0) tim0 - массив значений времени цикла
#define idinternal1_m936_tim0	 1314	//(internal1_m936_tim0) tim0 - массив значений времени цикла
#define internal1_m936_sumtim	 BUFFER[4838]	//(internal1_m936_sumtim) sumtim - время в пути
#define idinternal1_m936_sumtim	 1315	//(internal1_m936_sumtim) sumtim - время в пути
#define internal1_m936_StSpeed	 BUFFER[4843]	//(internal1_m936_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m936_StSpeed	 1316	//(internal1_m936_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m936_Vz0	 BUFFER[4848]	//(internal1_m936_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m936_Vz0	 1317	//(internal1_m936_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m936_flRazg	 BUFFER[4853]	//(internal1_m936_flRazg) признак разгона/торможения
#define idinternal1_m936_flRazg	 1318	//(internal1_m936_flRazg) признак разгона/торможения
#define internal1_m936_DelSp	 BUFFER[4856]	//(internal1_m936_DelSp) DelSp - время переключения скоростей
#define idinternal1_m936_DelSp	 1319	//(internal1_m936_DelSp) DelSp - время переключения скоростей
#define internal1_m936_z0	 BUFFER[4861]	//(internal1_m936_z0) z0 - точка прекращения движения
#define idinternal1_m936_z0	 1320	//(internal1_m936_z0) z0 - точка прекращения движения
#define internal1_m936_txZS	 BUFFER[4866]	//(internal1_m936_txZS) txZS
#define idinternal1_m936_txZS	 1321	//(internal1_m936_txZS) txZS
#define internal1_m936_tx	 BUFFER[4871]	//(internal1_m936_tx) tx
#define idinternal1_m936_tx	 1322	//(internal1_m936_tx) tx
#define internal1_m936_txd	 BUFFER[4876]	//(internal1_m936_txd) txd
#define idinternal1_m936_txd	 1323	//(internal1_m936_txd) txd
#define internal1_m936_txMBl	 BUFFER[4881]	//(internal1_m936_txMBl) tx
#define idinternal1_m936_txMBl	 1324	//(internal1_m936_txMBl) tx
#define internal1_m936_txBl	 BUFFER[4886]	//(internal1_m936_txBl) tx
#define idinternal1_m936_txBl	 1325	//(internal1_m936_txBl) tx
#define internal1_m936_Speed0	 BUFFER[4891]	//(internal1_m936_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m936_Speed0	 1326	//(internal1_m936_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m936_xz0	 BUFFER[4896]	//(internal1_m936_xz0) xz0 - новое задание мм
#define idinternal1_m936_xz0	 1327	//(internal1_m936_xz0) xz0 - новое задание мм
#define internal1_m936_tz0	 BUFFER[4901]	//(internal1_m936_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m936_tz0	 1328	//(internal1_m936_tz0) tz0 - время защиты от нового задания сек
#define internal1_m936_Shift0	 BUFFER[4906]	//(internal1_m936_Shift0) Shift0 - признак самохода
#define idinternal1_m936_Shift0	 1329	//(internal1_m936_Shift0) Shift0 - признак самохода
#define internal1_m936_ShCntlSp0	 BUFFER[4908]	//(internal1_m936_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m936_ShCntlSp0	 1330	//(internal1_m936_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m936_ShiftControl	 BUFFER[4910]	//(internal1_m936_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m936_ShiftControl	 1331	//(internal1_m936_ShiftControl) ShiftControl - признак самохода
#define internal1_m505_X0	 BUFFER[4912]	//(internal1_m505_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m505_X0	 1332	//(internal1_m505_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m505_t0	 BUFFER[4917]	//(internal1_m505_t0) время нахождения в зоне возврата
#define idinternal1_m505_t0	 1333	//(internal1_m505_t0) время нахождения в зоне возврата
#define internal1_m505_BLDv0	 BUFFER[4922]	//(internal1_m505_BLDv0) BlDv - Блокировка движения
#define idinternal1_m505_BLDv0	 1334	//(internal1_m505_BLDv0) BlDv - Блокировка движения
#define internal1_m525_tx	 BUFFER[4923]	//(internal1_m525_tx) tx - время накопленное сек
#define idinternal1_m525_tx	 1335	//(internal1_m525_tx) tx - время накопленное сек
#define internal1_m525_y0	 BUFFER[4928]	//(internal1_m525_y0) y0
#define idinternal1_m525_y0	 1336	//(internal1_m525_y0) y0
#define internal1_m526_tx	 BUFFER[4929]	//(internal1_m526_tx) tx - время накопленное сек
#define idinternal1_m526_tx	 1337	//(internal1_m526_tx) tx - время накопленное сек
#define internal1_m526_y0	 BUFFER[4934]	//(internal1_m526_y0) y0
#define idinternal1_m526_y0	 1338	//(internal1_m526_y0) y0
#define internal1_m532_xptr	 BUFFER[4935]	//(internal1_m532_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m532_xptr	 1339	//(internal1_m532_xptr) указатель текущей позиции в массиве координат
#define internal1_m532_x0	 BUFFER[4938]	//(internal1_m532_x0) x0 - массив мгновенных значений координат
#define idinternal1_m532_x0	 1340	//(internal1_m532_x0) x0 - массив мгновенных значений координат
#define internal1_m532_tim0	 BUFFER[5688]	//(internal1_m532_tim0) tim0 - массив значений времени цикла
#define idinternal1_m532_tim0	 1341	//(internal1_m532_tim0) tim0 - массив значений времени цикла
#define internal1_m532_sumtim	 BUFFER[6438]	//(internal1_m532_sumtim) sumtim - время в пути
#define idinternal1_m532_sumtim	 1342	//(internal1_m532_sumtim) sumtim - время в пути
#define internal1_m532_StSpeed	 BUFFER[6443]	//(internal1_m532_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m532_StSpeed	 1343	//(internal1_m532_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m532_Vz0	 BUFFER[6448]	//(internal1_m532_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m532_Vz0	 1344	//(internal1_m532_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m532_flRazg	 BUFFER[6453]	//(internal1_m532_flRazg) признак разгона/торможения
#define idinternal1_m532_flRazg	 1345	//(internal1_m532_flRazg) признак разгона/торможения
#define internal1_m532_DelSp	 BUFFER[6456]	//(internal1_m532_DelSp) DelSp - время переключения скоростей
#define idinternal1_m532_DelSp	 1346	//(internal1_m532_DelSp) DelSp - время переключения скоростей
#define internal1_m532_z0	 BUFFER[6461]	//(internal1_m532_z0) z0 - точка прекращения движения
#define idinternal1_m532_z0	 1347	//(internal1_m532_z0) z0 - точка прекращения движения
#define internal1_m532_txZS	 BUFFER[6466]	//(internal1_m532_txZS) txZS
#define idinternal1_m532_txZS	 1348	//(internal1_m532_txZS) txZS
#define internal1_m532_tx	 BUFFER[6471]	//(internal1_m532_tx) tx
#define idinternal1_m532_tx	 1349	//(internal1_m532_tx) tx
#define internal1_m532_txd	 BUFFER[6476]	//(internal1_m532_txd) txd
#define idinternal1_m532_txd	 1350	//(internal1_m532_txd) txd
#define internal1_m532_txMBl	 BUFFER[6481]	//(internal1_m532_txMBl) tx
#define idinternal1_m532_txMBl	 1351	//(internal1_m532_txMBl) tx
#define internal1_m532_txBl	 BUFFER[6486]	//(internal1_m532_txBl) tx
#define idinternal1_m532_txBl	 1352	//(internal1_m532_txBl) tx
#define internal1_m532_Speed0	 BUFFER[6491]	//(internal1_m532_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m532_Speed0	 1353	//(internal1_m532_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m532_xz0	 BUFFER[6496]	//(internal1_m532_xz0) xz0 - новое задание мм
#define idinternal1_m532_xz0	 1354	//(internal1_m532_xz0) xz0 - новое задание мм
#define internal1_m532_tz0	 BUFFER[6501]	//(internal1_m532_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m532_tz0	 1355	//(internal1_m532_tz0) tz0 - время защиты от нового задания сек
#define internal1_m532_Shift0	 BUFFER[6506]	//(internal1_m532_Shift0) Shift0 - признак самохода
#define idinternal1_m532_Shift0	 1356	//(internal1_m532_Shift0) Shift0 - признак самохода
#define internal1_m532_ShCntlSp0	 BUFFER[6508]	//(internal1_m532_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m532_ShCntlSp0	 1357	//(internal1_m532_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m532_ShiftControl	 BUFFER[6510]	//(internal1_m532_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m532_ShiftControl	 1358	//(internal1_m532_ShiftControl) ShiftControl - признак самохода
#define internal1_m631_q0	 BUFFER[6512]	//(internal1_m631_q0) q0 - внутренний параметр
#define idinternal1_m631_q0	 1359	//(internal1_m631_q0) q0 - внутренний параметр
#define internal1_m174_X0	 BUFFER[6514]	//(internal1_m174_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m174_X0	 1360	//(internal1_m174_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m174_t0	 BUFFER[6519]	//(internal1_m174_t0) время нахождения в зоне возврата
#define idinternal1_m174_t0	 1361	//(internal1_m174_t0) время нахождения в зоне возврата
#define internal1_m174_BLDv0	 BUFFER[6524]	//(internal1_m174_BLDv0) BlDv - Блокировка движения
#define idinternal1_m174_BLDv0	 1362	//(internal1_m174_BLDv0) BlDv - Блокировка движения
#define internal1_m213_xptr	 BUFFER[6525]	//(internal1_m213_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m213_xptr	 1363	//(internal1_m213_xptr) указатель текущей позиции в массиве координат
#define internal1_m213_x0	 BUFFER[6528]	//(internal1_m213_x0) x0 - массив мгновенных значений координат
#define idinternal1_m213_x0	 1364	//(internal1_m213_x0) x0 - массив мгновенных значений координат
#define internal1_m213_tim0	 BUFFER[7278]	//(internal1_m213_tim0) tim0 - массив значений времени цикла
#define idinternal1_m213_tim0	 1365	//(internal1_m213_tim0) tim0 - массив значений времени цикла
#define internal1_m213_sumtim	 BUFFER[8028]	//(internal1_m213_sumtim) sumtim - время в пути
#define idinternal1_m213_sumtim	 1366	//(internal1_m213_sumtim) sumtim - время в пути
#define internal1_m213_StSpeed	 BUFFER[8033]	//(internal1_m213_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m213_StSpeed	 1367	//(internal1_m213_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m213_Vz0	 BUFFER[8038]	//(internal1_m213_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m213_Vz0	 1368	//(internal1_m213_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m213_flRazg	 BUFFER[8043]	//(internal1_m213_flRazg) признак разгона/торможения
#define idinternal1_m213_flRazg	 1369	//(internal1_m213_flRazg) признак разгона/торможения
#define internal1_m213_DelSp	 BUFFER[8046]	//(internal1_m213_DelSp) DelSp - время переключения скоростей
#define idinternal1_m213_DelSp	 1370	//(internal1_m213_DelSp) DelSp - время переключения скоростей
#define internal1_m213_z0	 BUFFER[8051]	//(internal1_m213_z0) z0 - точка прекращения движения
#define idinternal1_m213_z0	 1371	//(internal1_m213_z0) z0 - точка прекращения движения
#define internal1_m213_txZS	 BUFFER[8056]	//(internal1_m213_txZS) txZS
#define idinternal1_m213_txZS	 1372	//(internal1_m213_txZS) txZS
#define internal1_m213_tx	 BUFFER[8061]	//(internal1_m213_tx) tx
#define idinternal1_m213_tx	 1373	//(internal1_m213_tx) tx
#define internal1_m213_txd	 BUFFER[8066]	//(internal1_m213_txd) txd
#define idinternal1_m213_txd	 1374	//(internal1_m213_txd) txd
#define internal1_m213_txMBl	 BUFFER[8071]	//(internal1_m213_txMBl) tx
#define idinternal1_m213_txMBl	 1375	//(internal1_m213_txMBl) tx
#define internal1_m213_txBl	 BUFFER[8076]	//(internal1_m213_txBl) tx
#define idinternal1_m213_txBl	 1376	//(internal1_m213_txBl) tx
#define internal1_m213_Speed0	 BUFFER[8081]	//(internal1_m213_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m213_Speed0	 1377	//(internal1_m213_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m213_xz0	 BUFFER[8086]	//(internal1_m213_xz0) xz0 - новое задание мм
#define idinternal1_m213_xz0	 1378	//(internal1_m213_xz0) xz0 - новое задание мм
#define internal1_m213_tz0	 BUFFER[8091]	//(internal1_m213_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m213_tz0	 1379	//(internal1_m213_tz0) tz0 - время защиты от нового задания сек
#define internal1_m213_Shift0	 BUFFER[8096]	//(internal1_m213_Shift0) Shift0 - признак самохода
#define idinternal1_m213_Shift0	 1380	//(internal1_m213_Shift0) Shift0 - признак самохода
#define internal1_m213_ShCntlSp0	 BUFFER[8098]	//(internal1_m213_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m213_ShCntlSp0	 1381	//(internal1_m213_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m213_ShiftControl	 BUFFER[8100]	//(internal1_m213_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m213_ShiftControl	 1382	//(internal1_m213_ShiftControl) ShiftControl - признак самохода
#define internal1_m657_q0	 BUFFER[8102]	//(internal1_m657_q0) q0 - внутренний параметр
#define idinternal1_m657_q0	 1383	//(internal1_m657_q0) q0 - внутренний параметр
#define internal1_m476_DvUp0	 BUFFER[8104]	//(internal1_m476_DvUp0) - есть команда на движение вперёд
#define idinternal1_m476_DvUp0	 1384	//(internal1_m476_DvUp0) - есть команда на движение вперёд
#define internal1_m476_DvDw0	 BUFFER[8105]	//(internal1_m476_DvDw0) - есть команда на движение назад
#define idinternal1_m476_DvDw0	 1385	//(internal1_m476_DvDw0) - есть команда на движение назад
#define internal1_m476_FDvUp0	 BUFFER[8106]	//(internal1_m476_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m476_FDvUp0	 1386	//(internal1_m476_FDvUp0) - есть команда на движение вперёд
#define internal1_m476_FDvDw0	 BUFFER[8107]	//(internal1_m476_FDvDw0) - есть команда на движение назад
#define idinternal1_m476_FDvDw0	 1387	//(internal1_m476_FDvDw0) - есть команда на движение назад
#define internal1_m476_BlDv0	 BUFFER[8108]	//(internal1_m476_BlDv0) - была блокировка
#define idinternal1_m476_BlDv0	 1388	//(internal1_m476_BlDv0) - была блокировка
#define internal1_m476_Pkv0	 BUFFER[8109]	//(internal1_m476_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m476_Pkv0	 1389	//(internal1_m476_Pkv0) Pkv - передний конечный выключатель
#define internal1_m476_Pkav0	 BUFFER[8110]	//(internal1_m476_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m476_Pkav0	 1390	//(internal1_m476_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m476_Zkv0	 BUFFER[8111]	//(internal1_m476_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m476_Zkv0	 1391	//(internal1_m476_Zkv0) Zkv - задний конечный выключатель
#define internal1_m476_Zkav0	 BUFFER[8112]	//(internal1_m476_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m476_Zkav0	 1392	//(internal1_m476_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m476_txNm	 BUFFER[8113]	//(internal1_m476_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m476_txNm	 1393	//(internal1_m476_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m476_txSm	 BUFFER[8118]	//(internal1_m476_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m476_txSm	 1394	//(internal1_m476_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m476_txHr	 BUFFER[8123]	//(internal1_m476_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m476_txHr	 1395	//(internal1_m476_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m476_txLd	 BUFFER[8128]	//(internal1_m476_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m476_txLd	 1396	//(internal1_m476_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m476_fef	 BUFFER[8133]	//(internal1_m476_fef) fef
#define idinternal1_m476_fef	 1397	//(internal1_m476_fef) fef
#define internal1_m470_DvUp0	 BUFFER[8134]	//(internal1_m470_DvUp0) - есть команда на движение вперёд
#define idinternal1_m470_DvUp0	 1398	//(internal1_m470_DvUp0) - есть команда на движение вперёд
#define internal1_m470_DvDw0	 BUFFER[8135]	//(internal1_m470_DvDw0) - есть команда на движение назад
#define idinternal1_m470_DvDw0	 1399	//(internal1_m470_DvDw0) - есть команда на движение назад
#define internal1_m470_FDvUp0	 BUFFER[8136]	//(internal1_m470_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m470_FDvUp0	 1400	//(internal1_m470_FDvUp0) - есть команда на движение вперёд
#define internal1_m470_FDvDw0	 BUFFER[8137]	//(internal1_m470_FDvDw0) - есть команда на движение назад
#define idinternal1_m470_FDvDw0	 1401	//(internal1_m470_FDvDw0) - есть команда на движение назад
#define internal1_m470_BlDv0	 BUFFER[8138]	//(internal1_m470_BlDv0) - была блокировка
#define idinternal1_m470_BlDv0	 1402	//(internal1_m470_BlDv0) - была блокировка
#define internal1_m470_Pkv0	 BUFFER[8139]	//(internal1_m470_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m470_Pkv0	 1403	//(internal1_m470_Pkv0) Pkv - передний конечный выключатель
#define internal1_m470_Pkav0	 BUFFER[8140]	//(internal1_m470_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m470_Pkav0	 1404	//(internal1_m470_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m470_Zkv0	 BUFFER[8141]	//(internal1_m470_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m470_Zkv0	 1405	//(internal1_m470_Zkv0) Zkv - задний конечный выключатель
#define internal1_m470_Zkav0	 BUFFER[8142]	//(internal1_m470_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m470_Zkav0	 1406	//(internal1_m470_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m470_txNm	 BUFFER[8143]	//(internal1_m470_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m470_txNm	 1407	//(internal1_m470_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m470_txSm	 BUFFER[8148]	//(internal1_m470_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m470_txSm	 1408	//(internal1_m470_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m470_txHr	 BUFFER[8153]	//(internal1_m470_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m470_txHr	 1409	//(internal1_m470_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m470_txLd	 BUFFER[8158]	//(internal1_m470_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m470_txLd	 1410	//(internal1_m470_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m470_fef	 BUFFER[8163]	//(internal1_m470_fef) fef
#define idinternal1_m470_fef	 1411	//(internal1_m470_fef) fef
#define internal1_m823_X0	 BUFFER[8164]	//(internal1_m823_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m823_X0	 1412	//(internal1_m823_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m823_t0	 BUFFER[8169]	//(internal1_m823_t0) время нахождения в зоне возврата
#define idinternal1_m823_t0	 1413	//(internal1_m823_t0) время нахождения в зоне возврата
#define internal1_m823_BLDv0	 BUFFER[8174]	//(internal1_m823_BLDv0) BlDv - Блокировка движения
#define idinternal1_m823_BLDv0	 1414	//(internal1_m823_BLDv0) BlDv - Блокировка движения
#define internal1_m843_xptr	 BUFFER[8175]	//(internal1_m843_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m843_xptr	 1415	//(internal1_m843_xptr) указатель текущей позиции в массиве координат
#define internal1_m843_x0	 BUFFER[8178]	//(internal1_m843_x0) x0 - массив мгновенных значений координат
#define idinternal1_m843_x0	 1416	//(internal1_m843_x0) x0 - массив мгновенных значений координат
#define internal1_m843_tim0	 BUFFER[8578]	//(internal1_m843_tim0) tim0 - массив значений времени цикла
#define idinternal1_m843_tim0	 1417	//(internal1_m843_tim0) tim0 - массив значений времени цикла
#define internal1_m843_sumtim	 BUFFER[8978]	//(internal1_m843_sumtim) sumtim - время в пути
#define idinternal1_m843_sumtim	 1418	//(internal1_m843_sumtim) sumtim - время в пути
#define internal1_m843_StSpeed	 BUFFER[8983]	//(internal1_m843_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m843_StSpeed	 1419	//(internal1_m843_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m843_Vz0	 BUFFER[8988]	//(internal1_m843_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m843_Vz0	 1420	//(internal1_m843_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m843_flRazg	 BUFFER[8993]	//(internal1_m843_flRazg) признак разгона/торможения
#define idinternal1_m843_flRazg	 1421	//(internal1_m843_flRazg) признак разгона/торможения
#define internal1_m843_DelSp	 BUFFER[8996]	//(internal1_m843_DelSp) DelSp - время переключения скоростей
#define idinternal1_m843_DelSp	 1422	//(internal1_m843_DelSp) DelSp - время переключения скоростей
#define internal1_m843_z0	 BUFFER[9001]	//(internal1_m843_z0) z0 - точка прекращения движения
#define idinternal1_m843_z0	 1423	//(internal1_m843_z0) z0 - точка прекращения движения
#define internal1_m843_txZS	 BUFFER[9006]	//(internal1_m843_txZS) txZS
#define idinternal1_m843_txZS	 1424	//(internal1_m843_txZS) txZS
#define internal1_m843_tx	 BUFFER[9011]	//(internal1_m843_tx) tx
#define idinternal1_m843_tx	 1425	//(internal1_m843_tx) tx
#define internal1_m843_txd	 BUFFER[9016]	//(internal1_m843_txd) txd
#define idinternal1_m843_txd	 1426	//(internal1_m843_txd) txd
#define internal1_m843_txMBl	 BUFFER[9021]	//(internal1_m843_txMBl) tx
#define idinternal1_m843_txMBl	 1427	//(internal1_m843_txMBl) tx
#define internal1_m843_txBl	 BUFFER[9026]	//(internal1_m843_txBl) tx
#define idinternal1_m843_txBl	 1428	//(internal1_m843_txBl) tx
#define internal1_m843_Speed0	 BUFFER[9031]	//(internal1_m843_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m843_Speed0	 1429	//(internal1_m843_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m843_xz0	 BUFFER[9036]	//(internal1_m843_xz0) xz0 - новое задание мм
#define idinternal1_m843_xz0	 1430	//(internal1_m843_xz0) xz0 - новое задание мм
#define internal1_m843_tz0	 BUFFER[9041]	//(internal1_m843_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m843_tz0	 1431	//(internal1_m843_tz0) tz0 - время защиты от нового задания сек
#define internal1_m843_Shift0	 BUFFER[9046]	//(internal1_m843_Shift0) Shift0 - признак самохода
#define idinternal1_m843_Shift0	 1432	//(internal1_m843_Shift0) Shift0 - признак самохода
#define internal1_m843_ShCntlSp0	 BUFFER[9048]	//(internal1_m843_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m843_ShCntlSp0	 1433	//(internal1_m843_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m843_ShiftControl	 BUFFER[9050]	//(internal1_m843_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m843_ShiftControl	 1434	//(internal1_m843_ShiftControl) ShiftControl - признак самохода
#define internal1_m1602_X0	 BUFFER[9052]	//(internal1_m1602_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1602_X0	 1435	//(internal1_m1602_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1602_t0	 BUFFER[9057]	//(internal1_m1602_t0) время нахождения в зоне возврата
#define idinternal1_m1602_t0	 1436	//(internal1_m1602_t0) время нахождения в зоне возврата
#define internal1_m1602_BLDv0	 BUFFER[9062]	//(internal1_m1602_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1602_BLDv0	 1437	//(internal1_m1602_BLDv0) BlDv - Блокировка движения
#define internal1_m1123_X0	 BUFFER[9063]	//(internal1_m1123_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1123_X0	 1438	//(internal1_m1123_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1123_t0	 BUFFER[9068]	//(internal1_m1123_t0) время нахождения в зоне возврата
#define idinternal1_m1123_t0	 1439	//(internal1_m1123_t0) время нахождения в зоне возврата
#define internal1_m1123_BLDv0	 BUFFER[9073]	//(internal1_m1123_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1123_BLDv0	 1440	//(internal1_m1123_BLDv0) BlDv - Блокировка движения
#define internal1_m629_q0	 BUFFER[9074]	//(internal1_m629_q0) q0 - внутренний параметр
#define idinternal1_m629_q0	 1441	//(internal1_m629_q0) q0 - внутренний параметр
#define internal1_m1223_X0	 BUFFER[9076]	//(internal1_m1223_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1223_X0	 1442	//(internal1_m1223_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1223_t0	 BUFFER[9081]	//(internal1_m1223_t0) время нахождения в зоне возврата
#define idinternal1_m1223_t0	 1443	//(internal1_m1223_t0) время нахождения в зоне возврата
#define internal1_m1223_BLDv0	 BUFFER[9086]	//(internal1_m1223_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1223_BLDv0	 1444	//(internal1_m1223_BLDv0) BlDv - Блокировка движения
#define internal1_m1243_tx	 BUFFER[9087]	//(internal1_m1243_tx) tx - время накопленное сек
#define idinternal1_m1243_tx	 1445	//(internal1_m1243_tx) tx - время накопленное сек
#define internal1_m1243_y0	 BUFFER[9092]	//(internal1_m1243_y0) y0
#define idinternal1_m1243_y0	 1446	//(internal1_m1243_y0) y0
#define internal1_m1251_tx	 BUFFER[9093]	//(internal1_m1251_tx) tx - время накопленное сек
#define idinternal1_m1251_tx	 1447	//(internal1_m1251_tx) tx - время накопленное сек
#define internal1_m1251_y0	 BUFFER[9098]	//(internal1_m1251_y0) y0
#define idinternal1_m1251_y0	 1448	//(internal1_m1251_y0) y0
#define internal1_m1257_xptr	 BUFFER[9099]	//(internal1_m1257_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1257_xptr	 1449	//(internal1_m1257_xptr) указатель текущей позиции в массиве координат
#define internal1_m1257_x0	 BUFFER[9102]	//(internal1_m1257_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1257_x0	 1450	//(internal1_m1257_x0) x0 - массив мгновенных значений координат
#define internal1_m1257_tim0	 BUFFER[9502]	//(internal1_m1257_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1257_tim0	 1451	//(internal1_m1257_tim0) tim0 - массив значений времени цикла
#define internal1_m1257_sumtim	 BUFFER[9902]	//(internal1_m1257_sumtim) sumtim - время в пути
#define idinternal1_m1257_sumtim	 1452	//(internal1_m1257_sumtim) sumtim - время в пути
#define internal1_m1257_StSpeed	 BUFFER[9907]	//(internal1_m1257_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1257_StSpeed	 1453	//(internal1_m1257_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1257_Vz0	 BUFFER[9912]	//(internal1_m1257_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1257_Vz0	 1454	//(internal1_m1257_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1257_flRazg	 BUFFER[9917]	//(internal1_m1257_flRazg) признак разгона/торможения
#define idinternal1_m1257_flRazg	 1455	//(internal1_m1257_flRazg) признак разгона/торможения
#define internal1_m1257_DelSp	 BUFFER[9920]	//(internal1_m1257_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1257_DelSp	 1456	//(internal1_m1257_DelSp) DelSp - время переключения скоростей
#define internal1_m1257_z0	 BUFFER[9925]	//(internal1_m1257_z0) z0 - точка прекращения движения
#define idinternal1_m1257_z0	 1457	//(internal1_m1257_z0) z0 - точка прекращения движения
#define internal1_m1257_txZS	 BUFFER[9930]	//(internal1_m1257_txZS) txZS
#define idinternal1_m1257_txZS	 1458	//(internal1_m1257_txZS) txZS
#define internal1_m1257_tx	 BUFFER[9935]	//(internal1_m1257_tx) tx
#define idinternal1_m1257_tx	 1459	//(internal1_m1257_tx) tx
#define internal1_m1257_txd	 BUFFER[9940]	//(internal1_m1257_txd) txd
#define idinternal1_m1257_txd	 1460	//(internal1_m1257_txd) txd
#define internal1_m1257_txMBl	 BUFFER[9945]	//(internal1_m1257_txMBl) tx
#define idinternal1_m1257_txMBl	 1461	//(internal1_m1257_txMBl) tx
#define internal1_m1257_txBl	 BUFFER[9950]	//(internal1_m1257_txBl) tx
#define idinternal1_m1257_txBl	 1462	//(internal1_m1257_txBl) tx
#define internal1_m1257_Speed0	 BUFFER[9955]	//(internal1_m1257_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1257_Speed0	 1463	//(internal1_m1257_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1257_xz0	 BUFFER[9960]	//(internal1_m1257_xz0) xz0 - новое задание мм
#define idinternal1_m1257_xz0	 1464	//(internal1_m1257_xz0) xz0 - новое задание мм
#define internal1_m1257_tz0	 BUFFER[9965]	//(internal1_m1257_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1257_tz0	 1465	//(internal1_m1257_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1257_Shift0	 BUFFER[9970]	//(internal1_m1257_Shift0) Shift0 - признак самохода
#define idinternal1_m1257_Shift0	 1466	//(internal1_m1257_Shift0) Shift0 - признак самохода
#define internal1_m1257_ShCntlSp0	 BUFFER[9972]	//(internal1_m1257_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1257_ShCntlSp0	 1467	//(internal1_m1257_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1257_ShiftControl	 BUFFER[9974]	//(internal1_m1257_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1257_ShiftControl	 1468	//(internal1_m1257_ShiftControl) ShiftControl - признак самохода
#define internal1_m649_q0	 BUFFER[9976]	//(internal1_m649_q0) q0 - внутренний параметр
#define idinternal1_m649_q0	 1469	//(internal1_m649_q0) q0 - внутренний параметр
#define internal1_m1615_tx	 BUFFER[9978]	//(internal1_m1615_tx) tx - время накопленное сек
#define idinternal1_m1615_tx	 1470	//(internal1_m1615_tx) tx - время накопленное сек
#define internal1_m1615_y0	 BUFFER[9983]	//(internal1_m1615_y0) y0
#define idinternal1_m1615_y0	 1471	//(internal1_m1615_y0) y0
#define internal1_m1617_tx	 BUFFER[9984]	//(internal1_m1617_tx) tx - время накопленное сек
#define idinternal1_m1617_tx	 1472	//(internal1_m1617_tx) tx - время накопленное сек
#define internal1_m1617_y0	 BUFFER[9989]	//(internal1_m1617_y0) y0
#define idinternal1_m1617_y0	 1473	//(internal1_m1617_y0) y0
#define internal1_m1605_DvUp0	 BUFFER[9990]	//(internal1_m1605_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1605_DvUp0	 1474	//(internal1_m1605_DvUp0) - есть команда на движение вперёд
#define internal1_m1605_DvDw0	 BUFFER[9991]	//(internal1_m1605_DvDw0) - есть команда на движение назад
#define idinternal1_m1605_DvDw0	 1475	//(internal1_m1605_DvDw0) - есть команда на движение назад
#define internal1_m1605_FDvUp0	 BUFFER[9992]	//(internal1_m1605_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1605_FDvUp0	 1476	//(internal1_m1605_FDvUp0) - есть команда на движение вперёд
#define internal1_m1605_FDvDw0	 BUFFER[9993]	//(internal1_m1605_FDvDw0) - есть команда на движение назад
#define idinternal1_m1605_FDvDw0	 1477	//(internal1_m1605_FDvDw0) - есть команда на движение назад
#define internal1_m1605_BlDv0	 BUFFER[9994]	//(internal1_m1605_BlDv0) - была блокировка
#define idinternal1_m1605_BlDv0	 1478	//(internal1_m1605_BlDv0) - была блокировка
#define internal1_m1605_Pkv0	 BUFFER[9995]	//(internal1_m1605_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1605_Pkv0	 1479	//(internal1_m1605_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1605_Pkav0	 BUFFER[9996]	//(internal1_m1605_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1605_Pkav0	 1480	//(internal1_m1605_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1605_Zkv0	 BUFFER[9997]	//(internal1_m1605_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1605_Zkv0	 1481	//(internal1_m1605_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1605_Zkav0	 BUFFER[9998]	//(internal1_m1605_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1605_Zkav0	 1482	//(internal1_m1605_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1605_txNm	 BUFFER[9999]	//(internal1_m1605_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1605_txNm	 1483	//(internal1_m1605_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1605_txSm	 BUFFER[10004]	//(internal1_m1605_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1605_txSm	 1484	//(internal1_m1605_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1605_txHr	 BUFFER[10009]	//(internal1_m1605_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1605_txHr	 1485	//(internal1_m1605_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1605_txLd	 BUFFER[10014]	//(internal1_m1605_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1605_txLd	 1486	//(internal1_m1605_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1605_fef	 BUFFER[10019]	//(internal1_m1605_fef) fef
#define idinternal1_m1605_fef	 1487	//(internal1_m1605_fef) fef
#define internal1_m1622_xptr	 BUFFER[10020]	//(internal1_m1622_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1622_xptr	 1488	//(internal1_m1622_xptr) указатель текущей позиции в массиве координат
#define internal1_m1622_x0	 BUFFER[10023]	//(internal1_m1622_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1622_x0	 1489	//(internal1_m1622_x0) x0 - массив мгновенных значений координат
#define internal1_m1622_tim0	 BUFFER[10123]	//(internal1_m1622_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1622_tim0	 1490	//(internal1_m1622_tim0) tim0 - массив значений времени цикла
#define internal1_m1622_sumtim	 BUFFER[10223]	//(internal1_m1622_sumtim) sumtim - время в пути
#define idinternal1_m1622_sumtim	 1491	//(internal1_m1622_sumtim) sumtim - время в пути
#define internal1_m1622_StSpeed	 BUFFER[10228]	//(internal1_m1622_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1622_StSpeed	 1492	//(internal1_m1622_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1622_Vz0	 BUFFER[10233]	//(internal1_m1622_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1622_Vz0	 1493	//(internal1_m1622_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1622_flRazg	 BUFFER[10238]	//(internal1_m1622_flRazg) признак разгона/торможения
#define idinternal1_m1622_flRazg	 1494	//(internal1_m1622_flRazg) признак разгона/торможения
#define internal1_m1622_DelSp	 BUFFER[10241]	//(internal1_m1622_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1622_DelSp	 1495	//(internal1_m1622_DelSp) DelSp - время переключения скоростей
#define internal1_m1622_z0	 BUFFER[10246]	//(internal1_m1622_z0) z0 - точка прекращения движения
#define idinternal1_m1622_z0	 1496	//(internal1_m1622_z0) z0 - точка прекращения движения
#define internal1_m1622_txZS	 BUFFER[10251]	//(internal1_m1622_txZS) txZS
#define idinternal1_m1622_txZS	 1497	//(internal1_m1622_txZS) txZS
#define internal1_m1622_tx	 BUFFER[10256]	//(internal1_m1622_tx) tx
#define idinternal1_m1622_tx	 1498	//(internal1_m1622_tx) tx
#define internal1_m1622_txd	 BUFFER[10261]	//(internal1_m1622_txd) txd
#define idinternal1_m1622_txd	 1499	//(internal1_m1622_txd) txd
#define internal1_m1622_txMBl	 BUFFER[10266]	//(internal1_m1622_txMBl) tx
#define idinternal1_m1622_txMBl	 1500	//(internal1_m1622_txMBl) tx
#define internal1_m1622_txBl	 BUFFER[10271]	//(internal1_m1622_txBl) tx
#define idinternal1_m1622_txBl	 1501	//(internal1_m1622_txBl) tx
#define internal1_m1622_Speed0	 BUFFER[10276]	//(internal1_m1622_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1622_Speed0	 1502	//(internal1_m1622_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1622_xz0	 BUFFER[10281]	//(internal1_m1622_xz0) xz0 - новое задание мм
#define idinternal1_m1622_xz0	 1503	//(internal1_m1622_xz0) xz0 - новое задание мм
#define internal1_m1622_tz0	 BUFFER[10286]	//(internal1_m1622_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1622_tz0	 1504	//(internal1_m1622_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1622_Shift0	 BUFFER[10291]	//(internal1_m1622_Shift0) Shift0 - признак самохода
#define idinternal1_m1622_Shift0	 1505	//(internal1_m1622_Shift0) Shift0 - признак самохода
#define internal1_m1622_ShCntlSp0	 BUFFER[10293]	//(internal1_m1622_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1622_ShCntlSp0	 1506	//(internal1_m1622_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1622_ShiftControl	 BUFFER[10295]	//(internal1_m1622_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1622_ShiftControl	 1507	//(internal1_m1622_ShiftControl) ShiftControl - признак самохода
#define internal1_m1139_tx	 BUFFER[10297]	//(internal1_m1139_tx) tx - время накопленное сек
#define idinternal1_m1139_tx	 1508	//(internal1_m1139_tx) tx - время накопленное сек
#define internal1_m1139_y0	 BUFFER[10302]	//(internal1_m1139_y0) y0
#define idinternal1_m1139_y0	 1509	//(internal1_m1139_y0) y0
#define internal1_m1143_tx	 BUFFER[10303]	//(internal1_m1143_tx) tx - время накопленное сек
#define idinternal1_m1143_tx	 1510	//(internal1_m1143_tx) tx - время накопленное сек
#define internal1_m1143_y0	 BUFFER[10308]	//(internal1_m1143_y0) y0
#define idinternal1_m1143_y0	 1511	//(internal1_m1143_y0) y0
#define internal1_m639_q0	 BUFFER[10309]	//(internal1_m639_q0) q0 - внутренний параметр
#define idinternal1_m639_q0	 1512	//(internal1_m639_q0) q0 - внутренний параметр
#define internal1_m604_q0	 BUFFER[10311]	//(internal1_m604_q0) q0 - внутренний параметр
#define idinternal1_m604_q0	 1513	//(internal1_m604_q0) q0 - внутренний параметр
#define internal1_m1130_DvUp0	 BUFFER[10313]	//(internal1_m1130_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1130_DvUp0	 1514	//(internal1_m1130_DvUp0) - есть команда на движение вперёд
#define internal1_m1130_DvDw0	 BUFFER[10314]	//(internal1_m1130_DvDw0) - есть команда на движение назад
#define idinternal1_m1130_DvDw0	 1515	//(internal1_m1130_DvDw0) - есть команда на движение назад
#define internal1_m1130_FDvUp0	 BUFFER[10315]	//(internal1_m1130_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1130_FDvUp0	 1516	//(internal1_m1130_FDvUp0) - есть команда на движение вперёд
#define internal1_m1130_FDvDw0	 BUFFER[10316]	//(internal1_m1130_FDvDw0) - есть команда на движение назад
#define idinternal1_m1130_FDvDw0	 1517	//(internal1_m1130_FDvDw0) - есть команда на движение назад
#define internal1_m1130_BlDv0	 BUFFER[10317]	//(internal1_m1130_BlDv0) - была блокировка
#define idinternal1_m1130_BlDv0	 1518	//(internal1_m1130_BlDv0) - была блокировка
#define internal1_m1130_Pkv0	 BUFFER[10318]	//(internal1_m1130_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1130_Pkv0	 1519	//(internal1_m1130_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1130_Pkav0	 BUFFER[10319]	//(internal1_m1130_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1130_Pkav0	 1520	//(internal1_m1130_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1130_Zkv0	 BUFFER[10320]	//(internal1_m1130_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1130_Zkv0	 1521	//(internal1_m1130_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1130_Zkav0	 BUFFER[10321]	//(internal1_m1130_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1130_Zkav0	 1522	//(internal1_m1130_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1130_txNm	 BUFFER[10322]	//(internal1_m1130_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1130_txNm	 1523	//(internal1_m1130_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1130_txSm	 BUFFER[10327]	//(internal1_m1130_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1130_txSm	 1524	//(internal1_m1130_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1130_txHr	 BUFFER[10332]	//(internal1_m1130_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1130_txHr	 1525	//(internal1_m1130_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1130_txLd	 BUFFER[10337]	//(internal1_m1130_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1130_txLd	 1526	//(internal1_m1130_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1130_fef	 BUFFER[10342]	//(internal1_m1130_fef) fef
#define idinternal1_m1130_fef	 1527	//(internal1_m1130_fef) fef
#define internal1_m1147_xptr	 BUFFER[10343]	//(internal1_m1147_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1147_xptr	 1528	//(internal1_m1147_xptr) указатель текущей позиции в массиве координат
#define internal1_m1147_x0	 BUFFER[10346]	//(internal1_m1147_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1147_x0	 1529	//(internal1_m1147_x0) x0 - массив мгновенных значений координат
#define internal1_m1147_tim0	 BUFFER[10446]	//(internal1_m1147_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1147_tim0	 1530	//(internal1_m1147_tim0) tim0 - массив значений времени цикла
#define internal1_m1147_sumtim	 BUFFER[10546]	//(internal1_m1147_sumtim) sumtim - время в пути
#define idinternal1_m1147_sumtim	 1531	//(internal1_m1147_sumtim) sumtim - время в пути
#define internal1_m1147_StSpeed	 BUFFER[10551]	//(internal1_m1147_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1147_StSpeed	 1532	//(internal1_m1147_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1147_Vz0	 BUFFER[10556]	//(internal1_m1147_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1147_Vz0	 1533	//(internal1_m1147_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1147_flRazg	 BUFFER[10561]	//(internal1_m1147_flRazg) признак разгона/торможения
#define idinternal1_m1147_flRazg	 1534	//(internal1_m1147_flRazg) признак разгона/торможения
#define internal1_m1147_DelSp	 BUFFER[10564]	//(internal1_m1147_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1147_DelSp	 1535	//(internal1_m1147_DelSp) DelSp - время переключения скоростей
#define internal1_m1147_z0	 BUFFER[10569]	//(internal1_m1147_z0) z0 - точка прекращения движения
#define idinternal1_m1147_z0	 1536	//(internal1_m1147_z0) z0 - точка прекращения движения
#define internal1_m1147_txZS	 BUFFER[10574]	//(internal1_m1147_txZS) txZS
#define idinternal1_m1147_txZS	 1537	//(internal1_m1147_txZS) txZS
#define internal1_m1147_tx	 BUFFER[10579]	//(internal1_m1147_tx) tx
#define idinternal1_m1147_tx	 1538	//(internal1_m1147_tx) tx
#define internal1_m1147_txd	 BUFFER[10584]	//(internal1_m1147_txd) txd
#define idinternal1_m1147_txd	 1539	//(internal1_m1147_txd) txd
#define internal1_m1147_txMBl	 BUFFER[10589]	//(internal1_m1147_txMBl) tx
#define idinternal1_m1147_txMBl	 1540	//(internal1_m1147_txMBl) tx
#define internal1_m1147_txBl	 BUFFER[10594]	//(internal1_m1147_txBl) tx
#define idinternal1_m1147_txBl	 1541	//(internal1_m1147_txBl) tx
#define internal1_m1147_Speed0	 BUFFER[10599]	//(internal1_m1147_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1147_Speed0	 1542	//(internal1_m1147_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1147_xz0	 BUFFER[10604]	//(internal1_m1147_xz0) xz0 - новое задание мм
#define idinternal1_m1147_xz0	 1543	//(internal1_m1147_xz0) xz0 - новое задание мм
#define internal1_m1147_tz0	 BUFFER[10609]	//(internal1_m1147_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1147_tz0	 1544	//(internal1_m1147_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1147_Shift0	 BUFFER[10614]	//(internal1_m1147_Shift0) Shift0 - признак самохода
#define idinternal1_m1147_Shift0	 1545	//(internal1_m1147_Shift0) Shift0 - признак самохода
#define internal1_m1147_ShCntlSp0	 BUFFER[10616]	//(internal1_m1147_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1147_ShCntlSp0	 1546	//(internal1_m1147_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1147_ShiftControl	 BUFFER[10618]	//(internal1_m1147_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1147_ShiftControl	 1547	//(internal1_m1147_ShiftControl) ShiftControl - признак самохода
#define internal1_m752_x0	 BUFFER[10620]	//(internal1_m752_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m752_x0	 1548	//(internal1_m752_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m721_x0	 BUFFER[10622]	//(internal1_m721_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m721_x0	 1549	//(internal1_m721_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m684_x0	 BUFFER[10624]	//(internal1_m684_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m684_x0	 1550	//(internal1_m684_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m777_q0	 BUFFER[10626]	//(internal1_m777_q0) q0 - внутренний параметр
#define idinternal1_m777_q0	 1551	//(internal1_m777_q0) q0 - внутренний параметр
#define internal1_m772_q0	 BUFFER[10628]	//(internal1_m772_q0) q0 - внутренний параметр
#define idinternal1_m772_q0	 1552	//(internal1_m772_q0) q0 - внутренний параметр
#define internal1_m740_q0	 BUFFER[10630]	//(internal1_m740_q0) q0 - внутренний параметр
#define idinternal1_m740_q0	 1553	//(internal1_m740_q0) q0 - внутренний параметр
#define internal1_m745_q0	 BUFFER[10632]	//(internal1_m745_q0) q0 - внутренний параметр
#define idinternal1_m745_q0	 1554	//(internal1_m745_q0) q0 - внутренний параметр
#define internal1_m753_q0	 BUFFER[10634]	//(internal1_m753_q0) q0 - внутренний параметр
#define idinternal1_m753_q0	 1555	//(internal1_m753_q0) q0 - внутренний параметр
#define internal1_m765_q0	 BUFFER[10636]	//(internal1_m765_q0) q0 - внутренний параметр
#define idinternal1_m765_q0	 1556	//(internal1_m765_q0) q0 - внутренний параметр
#define internal1_m743_q0	 BUFFER[10638]	//(internal1_m743_q0) q0 - внутренний параметр
#define idinternal1_m743_q0	 1557	//(internal1_m743_q0) q0 - внутренний параметр
#define internal1_m1200_DvUp0	 BUFFER[10640]	//(internal1_m1200_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1200_DvUp0	 1558	//(internal1_m1200_DvUp0) - есть команда на движение вперёд
#define internal1_m1200_DvDw0	 BUFFER[10641]	//(internal1_m1200_DvDw0) - есть команда на движение назад
#define idinternal1_m1200_DvDw0	 1559	//(internal1_m1200_DvDw0) - есть команда на движение назад
#define internal1_m1200_FDvUp0	 BUFFER[10642]	//(internal1_m1200_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1200_FDvUp0	 1560	//(internal1_m1200_FDvUp0) - есть команда на движение вперёд
#define internal1_m1200_FDvDw0	 BUFFER[10643]	//(internal1_m1200_FDvDw0) - есть команда на движение назад
#define idinternal1_m1200_FDvDw0	 1561	//(internal1_m1200_FDvDw0) - есть команда на движение назад
#define internal1_m1200_BlDv0	 BUFFER[10644]	//(internal1_m1200_BlDv0) - была блокировка
#define idinternal1_m1200_BlDv0	 1562	//(internal1_m1200_BlDv0) - была блокировка
#define internal1_m1200_Pkv0	 BUFFER[10645]	//(internal1_m1200_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1200_Pkv0	 1563	//(internal1_m1200_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1200_Pkav0	 BUFFER[10646]	//(internal1_m1200_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1200_Pkav0	 1564	//(internal1_m1200_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1200_Zkv0	 BUFFER[10647]	//(internal1_m1200_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1200_Zkv0	 1565	//(internal1_m1200_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1200_Zkav0	 BUFFER[10648]	//(internal1_m1200_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1200_Zkav0	 1566	//(internal1_m1200_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1200_txNm	 BUFFER[10649]	//(internal1_m1200_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1200_txNm	 1567	//(internal1_m1200_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1200_txSm	 BUFFER[10654]	//(internal1_m1200_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1200_txSm	 1568	//(internal1_m1200_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1200_txHr	 BUFFER[10659]	//(internal1_m1200_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1200_txHr	 1569	//(internal1_m1200_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1200_txLd	 BUFFER[10664]	//(internal1_m1200_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1200_txLd	 1570	//(internal1_m1200_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1200_fef	 BUFFER[10669]	//(internal1_m1200_fef) fef
#define idinternal1_m1200_fef	 1571	//(internal1_m1200_fef) fef
#define internal1_m1189_DvUp0	 BUFFER[10670]	//(internal1_m1189_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1189_DvUp0	 1572	//(internal1_m1189_DvUp0) - есть команда на движение вперёд
#define internal1_m1189_DvDw0	 BUFFER[10671]	//(internal1_m1189_DvDw0) - есть команда на движение назад
#define idinternal1_m1189_DvDw0	 1573	//(internal1_m1189_DvDw0) - есть команда на движение назад
#define internal1_m1189_FDvUp0	 BUFFER[10672]	//(internal1_m1189_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1189_FDvUp0	 1574	//(internal1_m1189_FDvUp0) - есть команда на движение вперёд
#define internal1_m1189_FDvDw0	 BUFFER[10673]	//(internal1_m1189_FDvDw0) - есть команда на движение назад
#define idinternal1_m1189_FDvDw0	 1575	//(internal1_m1189_FDvDw0) - есть команда на движение назад
#define internal1_m1189_BlDv0	 BUFFER[10674]	//(internal1_m1189_BlDv0) - была блокировка
#define idinternal1_m1189_BlDv0	 1576	//(internal1_m1189_BlDv0) - была блокировка
#define internal1_m1189_Pkv0	 BUFFER[10675]	//(internal1_m1189_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1189_Pkv0	 1577	//(internal1_m1189_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1189_Pkav0	 BUFFER[10676]	//(internal1_m1189_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1189_Pkav0	 1578	//(internal1_m1189_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1189_Zkv0	 BUFFER[10677]	//(internal1_m1189_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1189_Zkv0	 1579	//(internal1_m1189_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1189_Zkav0	 BUFFER[10678]	//(internal1_m1189_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1189_Zkav0	 1580	//(internal1_m1189_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1189_txNm	 BUFFER[10679]	//(internal1_m1189_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1189_txNm	 1581	//(internal1_m1189_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1189_txSm	 BUFFER[10684]	//(internal1_m1189_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1189_txSm	 1582	//(internal1_m1189_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1189_txHr	 BUFFER[10689]	//(internal1_m1189_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1189_txHr	 1583	//(internal1_m1189_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1189_txLd	 BUFFER[10694]	//(internal1_m1189_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1189_txLd	 1584	//(internal1_m1189_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1189_fef	 BUFFER[10699]	//(internal1_m1189_fef) fef
#define idinternal1_m1189_fef	 1585	//(internal1_m1189_fef) fef
#define internal1_m797_DvUp0	 BUFFER[10700]	//(internal1_m797_DvUp0) - есть команда на движение вперёд
#define idinternal1_m797_DvUp0	 1586	//(internal1_m797_DvUp0) - есть команда на движение вперёд
#define internal1_m797_DvDw0	 BUFFER[10701]	//(internal1_m797_DvDw0) - есть команда на движение назад
#define idinternal1_m797_DvDw0	 1587	//(internal1_m797_DvDw0) - есть команда на движение назад
#define internal1_m797_FDvUp0	 BUFFER[10702]	//(internal1_m797_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m797_FDvUp0	 1588	//(internal1_m797_FDvUp0) - есть команда на движение вперёд
#define internal1_m797_FDvDw0	 BUFFER[10703]	//(internal1_m797_FDvDw0) - есть команда на движение назад
#define idinternal1_m797_FDvDw0	 1589	//(internal1_m797_FDvDw0) - есть команда на движение назад
#define internal1_m797_BlDv0	 BUFFER[10704]	//(internal1_m797_BlDv0) - была блокировка
#define idinternal1_m797_BlDv0	 1590	//(internal1_m797_BlDv0) - была блокировка
#define internal1_m797_Pkv0	 BUFFER[10705]	//(internal1_m797_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m797_Pkv0	 1591	//(internal1_m797_Pkv0) Pkv - передний конечный выключатель
#define internal1_m797_Pkav0	 BUFFER[10706]	//(internal1_m797_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m797_Pkav0	 1592	//(internal1_m797_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m797_Zkv0	 BUFFER[10707]	//(internal1_m797_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m797_Zkv0	 1593	//(internal1_m797_Zkv0) Zkv - задний конечный выключатель
#define internal1_m797_Zkav0	 BUFFER[10708]	//(internal1_m797_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m797_Zkav0	 1594	//(internal1_m797_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m797_txNm	 BUFFER[10709]	//(internal1_m797_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m797_txNm	 1595	//(internal1_m797_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m797_txSm	 BUFFER[10714]	//(internal1_m797_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m797_txSm	 1596	//(internal1_m797_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m797_txHr	 BUFFER[10719]	//(internal1_m797_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m797_txHr	 1597	//(internal1_m797_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m797_txLd	 BUFFER[10724]	//(internal1_m797_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m797_txLd	 1598	//(internal1_m797_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m797_fef	 BUFFER[10729]	//(internal1_m797_fef) fef
#define idinternal1_m797_fef	 1599	//(internal1_m797_fef) fef
#define internal1_m793_DvUp0	 BUFFER[10730]	//(internal1_m793_DvUp0) - есть команда на движение вперёд
#define idinternal1_m793_DvUp0	 1600	//(internal1_m793_DvUp0) - есть команда на движение вперёд
#define internal1_m793_DvDw0	 BUFFER[10731]	//(internal1_m793_DvDw0) - есть команда на движение назад
#define idinternal1_m793_DvDw0	 1601	//(internal1_m793_DvDw0) - есть команда на движение назад
#define internal1_m793_FDvUp0	 BUFFER[10732]	//(internal1_m793_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m793_FDvUp0	 1602	//(internal1_m793_FDvUp0) - есть команда на движение вперёд
#define internal1_m793_FDvDw0	 BUFFER[10733]	//(internal1_m793_FDvDw0) - есть команда на движение назад
#define idinternal1_m793_FDvDw0	 1603	//(internal1_m793_FDvDw0) - есть команда на движение назад
#define internal1_m793_BlDv0	 BUFFER[10734]	//(internal1_m793_BlDv0) - была блокировка
#define idinternal1_m793_BlDv0	 1604	//(internal1_m793_BlDv0) - была блокировка
#define internal1_m793_Pkv0	 BUFFER[10735]	//(internal1_m793_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m793_Pkv0	 1605	//(internal1_m793_Pkv0) Pkv - передний конечный выключатель
#define internal1_m793_Pkav0	 BUFFER[10736]	//(internal1_m793_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m793_Pkav0	 1606	//(internal1_m793_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m793_Zkv0	 BUFFER[10737]	//(internal1_m793_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m793_Zkv0	 1607	//(internal1_m793_Zkv0) Zkv - задний конечный выключатель
#define internal1_m793_Zkav0	 BUFFER[10738]	//(internal1_m793_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m793_Zkav0	 1608	//(internal1_m793_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m793_txNm	 BUFFER[10739]	//(internal1_m793_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m793_txNm	 1609	//(internal1_m793_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m793_txSm	 BUFFER[10744]	//(internal1_m793_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m793_txSm	 1610	//(internal1_m793_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m793_txHr	 BUFFER[10749]	//(internal1_m793_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m793_txHr	 1611	//(internal1_m793_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m793_txLd	 BUFFER[10754]	//(internal1_m793_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m793_txLd	 1612	//(internal1_m793_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m793_fef	 BUFFER[10759]	//(internal1_m793_fef) fef
#define idinternal1_m793_fef	 1613	//(internal1_m793_fef) fef
#define internal1_m375_DvUp0	 BUFFER[10760]	//(internal1_m375_DvUp0) - есть команда на движение вперёд
#define idinternal1_m375_DvUp0	 1614	//(internal1_m375_DvUp0) - есть команда на движение вперёд
#define internal1_m375_DvDw0	 BUFFER[10761]	//(internal1_m375_DvDw0) - есть команда на движение назад
#define idinternal1_m375_DvDw0	 1615	//(internal1_m375_DvDw0) - есть команда на движение назад
#define internal1_m375_FDvUp0	 BUFFER[10762]	//(internal1_m375_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m375_FDvUp0	 1616	//(internal1_m375_FDvUp0) - есть команда на движение вперёд
#define internal1_m375_FDvDw0	 BUFFER[10763]	//(internal1_m375_FDvDw0) - есть команда на движение назад
#define idinternal1_m375_FDvDw0	 1617	//(internal1_m375_FDvDw0) - есть команда на движение назад
#define internal1_m375_BlDv0	 BUFFER[10764]	//(internal1_m375_BlDv0) - была блокировка
#define idinternal1_m375_BlDv0	 1618	//(internal1_m375_BlDv0) - была блокировка
#define internal1_m375_Pkv0	 BUFFER[10765]	//(internal1_m375_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m375_Pkv0	 1619	//(internal1_m375_Pkv0) Pkv - передний конечный выключатель
#define internal1_m375_Pkav0	 BUFFER[10766]	//(internal1_m375_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m375_Pkav0	 1620	//(internal1_m375_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m375_Zkv0	 BUFFER[10767]	//(internal1_m375_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m375_Zkv0	 1621	//(internal1_m375_Zkv0) Zkv - задний конечный выключатель
#define internal1_m375_Zkav0	 BUFFER[10768]	//(internal1_m375_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m375_Zkav0	 1622	//(internal1_m375_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m375_txNm	 BUFFER[10769]	//(internal1_m375_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m375_txNm	 1623	//(internal1_m375_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m375_txSm	 BUFFER[10774]	//(internal1_m375_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m375_txSm	 1624	//(internal1_m375_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m375_txHr	 BUFFER[10779]	//(internal1_m375_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m375_txHr	 1625	//(internal1_m375_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m375_txLd	 BUFFER[10784]	//(internal1_m375_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m375_txLd	 1626	//(internal1_m375_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m375_fef	 BUFFER[10789]	//(internal1_m375_fef) fef
#define idinternal1_m375_fef	 1627	//(internal1_m375_fef) fef
#define internal1_m404_DvUp0	 BUFFER[10790]	//(internal1_m404_DvUp0) - есть команда на движение вперёд
#define idinternal1_m404_DvUp0	 1628	//(internal1_m404_DvUp0) - есть команда на движение вперёд
#define internal1_m404_DvDw0	 BUFFER[10791]	//(internal1_m404_DvDw0) - есть команда на движение назад
#define idinternal1_m404_DvDw0	 1629	//(internal1_m404_DvDw0) - есть команда на движение назад
#define internal1_m404_FDvUp0	 BUFFER[10792]	//(internal1_m404_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m404_FDvUp0	 1630	//(internal1_m404_FDvUp0) - есть команда на движение вперёд
#define internal1_m404_FDvDw0	 BUFFER[10793]	//(internal1_m404_FDvDw0) - есть команда на движение назад
#define idinternal1_m404_FDvDw0	 1631	//(internal1_m404_FDvDw0) - есть команда на движение назад
#define internal1_m404_BlDv0	 BUFFER[10794]	//(internal1_m404_BlDv0) - была блокировка
#define idinternal1_m404_BlDv0	 1632	//(internal1_m404_BlDv0) - была блокировка
#define internal1_m404_Pkv0	 BUFFER[10795]	//(internal1_m404_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m404_Pkv0	 1633	//(internal1_m404_Pkv0) Pkv - передний конечный выключатель
#define internal1_m404_Pkav0	 BUFFER[10796]	//(internal1_m404_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m404_Pkav0	 1634	//(internal1_m404_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m404_Zkv0	 BUFFER[10797]	//(internal1_m404_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m404_Zkv0	 1635	//(internal1_m404_Zkv0) Zkv - задний конечный выключатель
#define internal1_m404_Zkav0	 BUFFER[10798]	//(internal1_m404_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m404_Zkav0	 1636	//(internal1_m404_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m404_txNm	 BUFFER[10799]	//(internal1_m404_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m404_txNm	 1637	//(internal1_m404_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m404_txSm	 BUFFER[10804]	//(internal1_m404_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m404_txSm	 1638	//(internal1_m404_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m404_txHr	 BUFFER[10809]	//(internal1_m404_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m404_txHr	 1639	//(internal1_m404_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m404_txLd	 BUFFER[10814]	//(internal1_m404_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m404_txLd	 1640	//(internal1_m404_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m404_fef	 BUFFER[10819]	//(internal1_m404_fef) fef
#define idinternal1_m404_fef	 1641	//(internal1_m404_fef) fef
#define internal1_m398_DvUp0	 BUFFER[10820]	//(internal1_m398_DvUp0) - есть команда на движение вперёд
#define idinternal1_m398_DvUp0	 1642	//(internal1_m398_DvUp0) - есть команда на движение вперёд
#define internal1_m398_DvDw0	 BUFFER[10821]	//(internal1_m398_DvDw0) - есть команда на движение назад
#define idinternal1_m398_DvDw0	 1643	//(internal1_m398_DvDw0) - есть команда на движение назад
#define internal1_m398_FDvUp0	 BUFFER[10822]	//(internal1_m398_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m398_FDvUp0	 1644	//(internal1_m398_FDvUp0) - есть команда на движение вперёд
#define internal1_m398_FDvDw0	 BUFFER[10823]	//(internal1_m398_FDvDw0) - есть команда на движение назад
#define idinternal1_m398_FDvDw0	 1645	//(internal1_m398_FDvDw0) - есть команда на движение назад
#define internal1_m398_BlDv0	 BUFFER[10824]	//(internal1_m398_BlDv0) - была блокировка
#define idinternal1_m398_BlDv0	 1646	//(internal1_m398_BlDv0) - была блокировка
#define internal1_m398_Pkv0	 BUFFER[10825]	//(internal1_m398_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m398_Pkv0	 1647	//(internal1_m398_Pkv0) Pkv - передний конечный выключатель
#define internal1_m398_Pkav0	 BUFFER[10826]	//(internal1_m398_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m398_Pkav0	 1648	//(internal1_m398_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m398_Zkv0	 BUFFER[10827]	//(internal1_m398_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m398_Zkv0	 1649	//(internal1_m398_Zkv0) Zkv - задний конечный выключатель
#define internal1_m398_Zkav0	 BUFFER[10828]	//(internal1_m398_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m398_Zkav0	 1650	//(internal1_m398_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m398_txNm	 BUFFER[10829]	//(internal1_m398_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m398_txNm	 1651	//(internal1_m398_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m398_txSm	 BUFFER[10834]	//(internal1_m398_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m398_txSm	 1652	//(internal1_m398_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m398_txHr	 BUFFER[10839]	//(internal1_m398_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m398_txHr	 1653	//(internal1_m398_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m398_txLd	 BUFFER[10844]	//(internal1_m398_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m398_txLd	 1654	//(internal1_m398_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m398_fef	 BUFFER[10849]	//(internal1_m398_fef) fef
#define idinternal1_m398_fef	 1655	//(internal1_m398_fef) fef
#define internal1_m749_q0	 BUFFER[10850]	//(internal1_m749_q0) q0 - внутренний параметр
#define idinternal1_m749_q0	 1656	//(internal1_m749_q0) q0 - внутренний параметр
#define internal1_m746_q0	 BUFFER[10852]	//(internal1_m746_q0) q0 - внутренний параметр
#define idinternal1_m746_q0	 1657	//(internal1_m746_q0) q0 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &R0AD21LDU},	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
	{ 2	,1	,1	, &R0VX02LDU},	//( - , DU) Импульс разрешен
	{ 3	,1	,1	, &R0EE03LDU},	//( - , DU) ВПИС ИС
	{ 4	,1	,1	, &R0AB07LDU},	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
	{ 5	,1	,1	, &R0AD16LDU},	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
	{ 6	,1	,1	, &C2MD31LP1},	//( - , DU) Кнопка СБРОС РБ
	{ 7	,3	,1	, &B6VS01IDU},	//( - , DU) Готовность к управлению БЗ2
	{ 8	,1	,1	, &R2AD20LDU},	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
	{ 9	,1	,1	, &R2AD10LDU},	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
	{ 10	,3	,1	, &B8VS01IDU},	//( - , DU) Готовность к управлению АЗ2
	{ 11	,3	,1	, &A8VS01IDU},	//( - , DU) Готовность к управлению ДС2
	{ 12	,1	,1	, &A1IE03LDU},	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
	{ 13	,1	,1	, &A1IE04LDU},	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
	{ 14	,1	,1	, &A2IE03LDU},	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
	{ 15	,1	,1	, &A2IE04LDU},	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
	{ 16	,1	,1	, &A3IE03LDU},	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
	{ 17	,1	,1	, &A3IE04LDU},	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
	{ 18	,1	,1	, &B1IE03LDU},	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
	{ 19	,1	,1	, &B1IE04LDU},	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
	{ 20	,1	,1	, &B2IE03LDU},	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
	{ 21	,1	,1	, &B2IE04LDU},	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
	{ 22	,1	,1	, &B3IE03LDU},	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
	{ 23	,1	,1	, &B3IE04LDU},	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
	{ 24	,1	,1	, &R0AD14LZ2},	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
	{ 25	,1	,1	, &A3VZ13LZ2},	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{ 26	,1	,1	, &A3VZ13LZ1},	//(vds32:02 - K18VDSR, - ) Имитация срабатывания АЗ от ВУ ИС
	{ 27	,1	,1	, &A3VZ15LZ1},	//(vds32:02 - K19VDSR, - ) Имитация срабатывания АЗ от НУП ИС
	{ 28	,1	,1	, &A3VZ15LZ2},	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{ 29	,1	,1	, &B2IS33LDU},	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
	{ 30	,1	,1	, &B3IS31LDU},	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
	{ 31	,1	,1	, &B3IS33LDU},	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
	{ 32	,1	,1	, &B3IS35LDU},	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
	{ 33	,1	,1	, &B4IS10LDU},	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
	{ 34	,1	,1	, &R6IS31LDU},	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
	{ 35	,1	,1	, &R6IS32LDU},	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
	{ 36	,1	,1	, &R6IS42LDU},	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
	{ 37	,1	,1	, &R6IS41LDU},	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
	{ 38	,1	,1	, &R6IS52LDU},	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
	{ 39	,1	,1	, &R6IS51LDU},	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
	{ 40	,1	,1	, &R3IS11LDU},	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
	{ 41	,1	,1	, &R3IS21LDU},	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
	{ 42	,1	,1	, &R0AB03LDU},	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
	{ 43	,1	,1	, &R0AB05LDU},	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
	{ 44	,8	,1	, &R0VN11RZ1},	//( - , MDuBz1) Средняя мощность по BAZ1
	{ 45	,8	,1	, &R0VN11RZ2},	//( - , MDuBz2) Средняя мощность по BAZ2
	{ 46	,1	,1	, &A2AB15LDU},	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{ 47	,1	,1	, &B2AB15LDU},	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{ 48	,1	,1	, &R0AB14LDU},	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
	{ 49	,1	,1	, &R0AB15LDU},	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
	{ 50	,1	,1	, &A3IS12LDU},	//( - , DU) Приход на ВУ штока ИС1
	{ 51	,1	,1	, &B3IS12LDU},	//( - , DU) Приход на ВУ штока ИС2
	{ 52	,1	,1	, &A1ZAV},	//( - , DU) 
	{ 53	,1	,1	, &A3ZAV},	//( - , DU) 
	{ 54	,1	,1	, &B1AB19LDU},	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
	{ 55	,8	,1	, &R0VN09RZ2},	//( - , MDuBz2) Усредненный период разгона
	{ 56	,8	,1	, &R0VN09RZ1},	//( - , MDuBz1) Усредненный период разгона
	{ 57	,1	,1	, &R0AB16LDU},	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
	{ 58	,1	,1	, &R0AB17LDU},	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
	{ 59	,1	,1	, &R0AB18LDU},	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
	{ 60	,8	,1	, &A0CT01IZ1},	//( - , MDuBz1) Температура АЗ1-1
	{ 61	,8	,1	, &B0CT01IZ1},	//( - , MDuBz1) Температура АЗ2-1
	{ 62	,8	,1	, &A0CT01IZ2},	//( - , MDuBz2) Температура АЗ1-2
	{ 63	,8	,1	, &B0CT01IZ2},	//( - , MDuBz2) Температура АЗ2-2
	{ 64	,8	,1	, &A3MC01RDU},	//( - , DU) Заданная координата положения ИС от регулятора мм
	{ 65	,8	,1	, &A3MC02RDU},	//( - , DU) Температурная корректировка координаты ИМ
	{ 66	,8	,1	, &R0CN91LDU},	//( - , DU) Рассчётная реактивность от регулятора
	{ 67	,8	,1	, &A3MC03RDU},	//( - , DU) Координата положения ИМ 0-й реактивности
	{ 68	,1	,1	, &A3AB15LDU},	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
	{ 69	,1	,1	, &R0AB20LDU},	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
	{ 70	,8	,1	, &R0CN92LDU},	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
	{ 71	,8	,1	, &R0VN11RDU},	//( - , DU) Текущая мощность РУ
	{ 72	,1	,1	, &R0VS11LDU},	//( - , DU) РУ не готова к работе
	{ 73	,1	,1	, &B6AB05LDU},	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
	{ 74	,1	,1	, &R0AB08LDU},	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
	{ 75	,8	,1	, &A1MC01RP1},	//( - , DU) Заданная координата положения ББ1 мм
	{ 76	,8	,1	, &B1MC01RP1},	//( - , DU) Заданная координата положения ББ2  мм
	{ 77	,8	,1	, &A3MC01RP1},	//( - , DU) Заданная координата положения ИС1 мм
	{ 78	,8	,1	, &B3MC01RP1},	//( - , DU) Заданная координата положения ИС2 мм
	{ 79	,8	,1	, &B8MC01RP2},	//( - , DU) Заданная координата АЗ2 мм
	{ 80	,1	,1	, &R0AB09LDU},	//( - , DU) Ошибка в заданной координате ББ1
	{ 81	,1	,1	, &R0AB10LDU},	//( - , DU) Ошибка в заданной координате ББ2
	{ 82	,1	,1	, &R0AB11LDU},	//( - , DU) Ошибка в заданной координате  ИС1
	{ 83	,1	,1	, &R0AB12LDU},	//( - , DU) Ошибка в заданной координате  ИС2
	{ 84	,1	,1	, &R0AB13LDU},	//( - , DU) Ошибка в заданной координате  АЗ2
	{ 85	,1	,1	, &A4ZAV},	//( - , DU) 
	{ 86	,1	,1	, &A6ZAV},	//( - , DU) 
	{ 87	,1	,1	, &R2ZAV},	//( - , DU) 
	{ 88	,1	,1	, &A5ZAV},	//( - , DU) 
	{ 89	,1	,1	, &B8ZAV},	//( - , DU) 
	{ 90	,1	,1	, &A2ZAV},	//( - , DU) Завершение РБ1,2
	{ 91	,1	,1	, &A8ZAV},	//( - , DU) 
	{ 92	,1	,1	, &A9ZAV},	//( - , DU) Завершение НИ ДС1(2)
	{ 93	,1	,1	, &R4ABL},	//( - , DU) Блокировка тележки -
	{ 94	,1	,1	, &A4UP},	//( - , DU) 
	{ 95	,1	,1	, &A4DW},	//( - , DU) 
	{ 96	,1	,1	, &R0AB01LDU},	//( - , DU) Режим проверки разрешён
	{ 97	,1	,1	, &A3IS22LDU},	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
	{ 98	,1	,1	, &B3IS22LDU},	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
	{ 99	,1	,1	, &A2AD33LDU},	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
	{ 100	,1	,1	, &B2AD33LDU},	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
	{ 101	,1	,1	, &A3AD33LDU},	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
	{ 102	,1	,1	, &A3AD34LDU},	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
	{ 103	,1	,1	, &A3AD31LDU},	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
	{ 104	,1	,1	, &B3AD34LDU},	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
	{ 105	,1	,1	, &B3AD31LDU},	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
	{ 106	,1	,1	, &A2IS11LDU},	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
	{ 107	,1	,1	, &B2IS11LDU},	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
	{ 108	,1	,1	, &A3MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
	{ 109	,1	,1	, &A3MD11LP1},	//( - , DU) Кнопка ПУСК ИС1
	{ 110	,1	,1	, &R0MD33LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
	{ 111	,1	,1	, &A1MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
	{ 112	,1	,1	, &A1MD11LP1},	//( - , DU) Кнопка ПУСК ББ1
	{ 113	,3	,1	, &R0MW14IP2},	//( - , DU) Переключатель ОБДУВ
	{ 114	,1	,1	, &A7AP31LDU},	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
	{ 115	,1	,1	, &B7AP31LDU},	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
	{ 116	,3	,1	, &R0MW12IP2},	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
	{ 117	,1	,1	, &R0MW17LP1},	//( - , DU) Переключатель АВТ/Р
	{ 118	,1	,1	, &R0VW13LDU},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
	{ 119	,3	,1	, &A4VS01IDU},	//( - , DU) Готовность к управлению НИ1
	{ 120	,1	,1	, &A4VS12LDU},	//( - , DU) Движение НИ1 в сторону ВУ
	{ 121	,1	,1	, &A4VS22LDU},	//( - , DU) Движение НИ1 в сторону НУ
	{ 122	,3	,1	, &B4VS01IDU},	//( - , DU) Готовность к управлению НИ2
	{ 123	,1	,1	, &B4VS12LDU},	//( - , DU) Движение НИ2 в сторону ВУ
	{ 124	,1	,1	, &B4VS22LDU},	//( - , DU) Движение НИ2 в сторону НУ
	{ 125	,3	,1	, &A5VS01IDU},	//( - , DU) Готовность к управлению НЛ1
	{ 126	,3	,1	, &B5VS01IDU},	//( - , DU) Готовность к управлению НЛ2
	{ 127	,3	,1	, &A6VS01IDU},	//( - , DU) Готовность к управлению БЗ1
	{ 128	,3	,1	, &R4VS01IDU},	//( - , DU) Готовность к управлению тележкой реактора
	{ 129	,3	,1	, &R2VS01IDU},	//( - , DU) Готовность к управлению МДЗ2
	{ 130	,3	,1	, &R1VS01IDU},	//( - , DU) Готовность к управлению МДЗ1
	{ 131	,1	,1	, &A9IS11LDU},	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
	{ 132	,1	,1	, &A9IS21LDU},	//(vds32:02 - K24VDSR, - ) Приход на НУ НИ ДС1
	{ 133	,1	,1	, &B9IS11LDU},	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
	{ 134	,1	,1	, &B9IS21LDU},	//(vds32:02 - K26VDSR, - ) Приход на НУ НИ ДС2
	{ 135	,1	,1	, &B9AD10LDU},	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
	{ 136	,1	,1	, &A9AD10LDU},	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
	{ 137	,1	,1	, &A9AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ ДС1
	{ 138	,1	,1	, &A9AB01LDU},	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
	{ 139	,1	,1	, &A9AB02LDU},	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
	{ 140	,1	,1	, &B9AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ ДС2
	{ 141	,1	,1	, &B9AB01LDU},	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
	{ 142	,1	,1	, &B9AB02LDU},	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
	{ 143	,1	,1	, &A0VT71LZ2},	//( - , MDuBz2) АС по температуре в АЗ1
	{ 144	,1	,1	, &B0VT71LZ2},	//( - , MDuBz2) АС по температуре в АЗ2
	{ 145	,1	,1	, &B2VS11LDU},	//( - , DU) Движение РБ2 в сторону ВУ
	{ 146	,1	,1	, &B2VS21LDU},	//( - , DU) Движение РБ2 в сторону НУ
	{ 147	,3	,1	, &B2VS01IDU},	//( - , DU) Готовность к управлению РБ2
	{ 148	,1	,1	, &A7AS31LDU},	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
	{ 149	,1	,1	, &B7AS31LDU},	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
	{ 150	,1	,1	, &A7AZ03LDU},	//( - , DU) Несанкционированное включение обдува АЗ1
	{ 151	,1	,1	, &B7AZ03LDU},	//( - , DU) Несанкционированное включение обдува АЗ2
	{ 152	,1	,1	, &B3MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
	{ 153	,1	,1	, &B3MD11LP1},	//( - , DU) Кнопка ПУСК ИС2
	{ 154	,8	,1	, &R0VL01RDU},	//( - , DU) Индикация Время задержки
	{ 155	,1	,1	, &R0VZ71LZ2},	//(vds32:03 - K22VDSR, DU) Обобщенный сигнал АЗ 2 канала
	{ 156	,1	,1	, &R0VZ71LZ1},	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
	{ 157	,1	,1	, &R0VZ71LDU},	//( - , DU) Обобщенный сигнал АЗ
	{ 158	,1	,1	, &A2IS33LDU},	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
	{ 159	,1	,1	, &A3IS31LDU},	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
	{ 160	,1	,1	, &A3IS33LDU},	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
	{ 161	,1	,1	, &A3IS35LDU},	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
	{ 162	,1	,1	, &A4IS10LDU},	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
	{ 163	,1	,1	, &A1VN71LZ1},	//(vds32:02 - K21VDSR, - ) Блокировка автоматического подъёма ББ
	{ 164	,1	,1	, &A1VN71LZ2},	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{ 165	,1	,1	, &A1AB19LDU},	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
	{ 166	,1	,1	, &R0AD14LZ1},	//(vds32:02 - K20VDSR, - ) Имитация срабатывания АЗ от II УР
	{ 167	,1	,1	, &R0VW23LDU},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
	{ 168	,3	,1	, &R0VX08IDU},	//( - , DU) Индикация Режим
	{ 169	,1	,1	, &R0VX09LDU},	//( - , DU) Индикация регулятор мощности включен/отключен
	{ 170	,1	,1	, &R0VS17LDU},	//( - , DU) Индикация выбора АВТОМАТ
	{ 171	,1	,1	, &A2VS32LDU},	//( - , DU) Индикация  СБРОС РБ1
	{ 172	,1	,1	, &B2VS32LDU},	//( - , DU) Индикация  СБРОС РБ2
	{ 173	,1	,1	, &A3VX01LDU},	//( - , DU) Индикация Выстрел ИС1
	{ 174	,1	,1	, &A3IS11LDU},	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
	{ 175	,1	,1	, &B3VX01LDU},	//( - , DU) Индикация Выстрел ИС2
	{ 176	,1	,1	, &R0VS18LDU},	//( - , DU) Индикация  Проверка схем сброса
	{ 177	,1	,1	, &B1MD11LP1},	//( - , DU) Кнопка ПУСК ББ2
	{ 178	,1	,1	, &B1MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
	{ 179	,1	,1	, &B2MD11LP1},	//( - , DU) Кнопка ПУСК РБ2
	{ 180	,1	,1	, &B2MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
	{ 181	,1	,1	, &A2MD11LP1},	//( - , DU) Кнопка ПУСК РБ1
	{ 182	,1	,1	, &A2MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
	{ 183	,1	,1	, &R0IS01LDU},	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
	{ 184	,1	,1	, &R0IS02LDU},	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
	{ 185	,1	,1	, &R0VP73LZ1},	//( - , MDuBz1) ПС давления для РУ
	{ 186	,1	,1	, &R0VP73LZ2},	//( - , MDuBz2) ПС давления для РУ
	{ 187	,1	,1	, &R0VP73LDU},	//( - , DU) ПС давления для РУ
	{ 188	,1	,1	, &R0MD34LP1},	//( - , DU) Кнопка КВИТИРОВАТЬ
	{ 189	,1	,1	, &A0VT71LZ1},	//( - , MDuBz1) АС по температуре в АЗ1
	{ 190	,1	,1	, &B0VT71LZ1},	//( - , MDuBz1) АС по температуре в АЗ2
	{ 191	,1	,1	, &A3VP42LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
	{ 192	,8	,1	, &A3CP02RDU},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
	{ 193	,1	,1	, &A3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
	{ 194	,1	,1	, &B3VP42LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
	{ 195	,8	,1	, &B3CP02RDU},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
	{ 196	,1	,1	, &B3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
	{ 197	,1	,1	, &B3VP82LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
	{ 198	,1	,1	, &A3VP82LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
	{ 199	,3	,1	, &A3IP02IDU},	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
	{ 200	,3	,1	, &B3IP02IDU},	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
	{ 201	,1	,1	, &A0VE01LDU},	//( - , DU) Напряжение в системы АЗ1 подано
	{ 202	,1	,1	, &B0VE01LDU},	//( - , DU) Напряжение в системы АЗ2 подано
	{ 203	,1	,1	, &A0VP01LDU},	//( - , DU) Давление в системы АЗ1 подано
	{ 204	,1	,1	, &B0VP01LDU},	//( - , DU) Давление в системы АЗ2 подано
	{ 205	,1	,1	, &A0EE01LZ1},	//( - , MDuBz1) Исправность АКНП1
	{ 206	,1	,1	, &A0EE03LZ1},	//( - , MDuBz1) Исправность АКНП3
	{ 207	,1	,1	, &A0EE02LZ1},	//( - , MDuBz1) Исправность АКНП2
	{ 208	,1	,1	, &A0EE04LZ1},	//( - , MDuBz1) Исправность АКНП4
	{ 209	,1	,1	, &A0VN01LDU},	//( - , DU) Каналы АЗ1 проверены
	{ 210	,1	,1	, &B0VN01LDU},	//( - , DU) Каналы АЗ2 проверены
	{ 211	,1	,1	, &A0EE01LZ2},	//( - , MDuBz2) Исправность АКНП1
	{ 212	,1	,1	, &A0EE03LZ2},	//( - , MDuBz2) Исправность АКНП3
	{ 213	,1	,1	, &A0EE02LZ2},	//( - , MDuBz2) Исправность АКНП2
	{ 214	,5	,1	, &B3IC01UDU},	//( - , MDuS) Координата штока ИС2 (дел.энк)
	{ 215	,8	,1	, &B3VC01RDU},	//( - , DU) Координата ИС2, мм
	{ 216	,5	,1	, &A8IC01UDU},	//( - , MDuS) Координата ДС2 (дел.энк)
	{ 217	,8	,1	, &A8VC01RDU},	//( - , DU) Координата ДС2, мм
	{ 218	,5	,1	, &B8IC01UDU},	//( - , MDuS) Координата АЗ2 (дел.энк)
	{ 219	,5	,1	, &A1IC01UDU},	//( - , MDuS) Координата штока ББ1 (дел.энк)
	{ 220	,8	,1	, &A1VC01RDU},	//( - , DU) Координата ББ1, мм
	{ 221	,1	,1	, &A1IS11LDU},	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
	{ 222	,1	,1	, &B1MC01LC1},	//( - , DU) Настроить энкодер ББ2
	{ 223	,1	,1	, &B1MC01LC2},	//( - , DU) Настроить энкодер ББ2
	{ 224	,1	,1	, &A1MC01LC1},	//( - , DU) Настроить энкодер ББ1
	{ 225	,1	,1	, &A1MC01LC2},	//( - , DU) Настроить энкодер ББ1
	{ 226	,1	,1	, &B2MC01LC1},	//( - , DU) Настроить энкодер РБ2
	{ 227	,1	,1	, &B2MC01LC2},	//( - , DU) Настроить энкодер РБ2
	{ 228	,1	,1	, &A2MC01LC1},	//( - , DU) Настроить энкодер РБ1
	{ 229	,1	,1	, &A2MC01LC2},	//( - , DU) Настроить энкодер РБ1
	{ 230	,1	,1	, &B3MC01LC1},	//( - , DU) Настроить энкодер ИС2
	{ 231	,1	,1	, &B3MC01LC2},	//( - , DU) Настроить энкодер ИС2
	{ 232	,1	,1	, &A3MC01LC1},	//( - , DU) Настроить энкодер ИС1
	{ 233	,1	,1	, &A3MC01LC2},	//( - , DU) Настроить энкодер ИС1
	{ 234	,1	,1	, &B8MC01LC1},	//( - , DU) Настроить энкодер АЗ2
	{ 235	,1	,1	, &B8MC01LC2},	//( - , DU) Настроить энкодер АЗ2
	{ 236	,1	,1	, &A8MC01LC1},	//( - , DU) Настроить энкодер ДС2
	{ 237	,1	,1	, &A8MC01LC2},	//( - , DU) Настроить энкодер ДС2
	{ 238	,1	,1	, &B5IE01LDU},	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
	{ 239	,1	,1	, &A5IE02LDU},	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
	{ 240	,1	,1	, &R1IE01LDU},	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
	{ 241	,1	,1	, &R2IE01LDU},	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
	{ 242	,1	,1	, &R6IS61LDU},	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
	{ 243	,1	,1	, &R6IS64LDU},	//( - , MDuS) Исправность ВИП ССДИ-35 1канал
	{ 244	,1	,1	, &R6IS65LDU},	//( - , MDuS) Исправность ВИП ССДИ-35 2канал
	{ 245	,1	,1	, &R6IS62LDU},	//( - , MDuS) Исправность ВИП ССДИ-39 1канал
	{ 246	,1	,1	, &R6IS63LDU},	//( - , MDuS) Исправность ВИП ССДИ-39 2канал
	{ 247	,1	,1	, &R6IS66LZZ},	//( - , MDuS) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 248	,1	,1	, &R6IS67LZZ},	//( - , MDuS) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 249	,1	,1	, &R6IS68LZZ},	//( - , MDuS) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 250	,1	,1	, &syn_R0EE03LDU},	//( - , DU) ВПИС ИС
	{ 251	,8	,1	, &A3VC01RDU},	//( - , DU) Координата ИС1, мм
	{ 252	,8	,1	, &A2VC01RDU},	//( - , DU) Координата РБ1, мм
	{ 253	,8	,1	, &B2VC01RDU},	//( - , DU) Координата РБ2, мм
	{ 254	,8	,1	, &B8VC01RDU},	//( - , DU) Координата АЗ2, мм
	{ 255	,1	,1	, &A4VP82LDU},	//( - , MDuS) Давление ПОДЪЁМ НИ1 в норме
	{ 256	,1	,1	, &B4VP82LDU},	//( - , MDuS) Давление ПОДЪЁМ НИ2 в норме
	{ 257	,1	,1	, &A2VP82LDU},	//( - , MDuS) Давление ПОДЪЁМ РБ1 в норме
	{ 258	,1	,1	, &B2VP82LDU},	//( - , MDuS) Давление ПОДЪЁМ РБ2 в норме
	{ 259	,1	,1	, &A3VP81LDU},	//( - , MDuS) Давление СПУСК ИС1 в норме
	{ 260	,1	,1	, &B3VP81LDU},	//( - , MDuS) Давление СПУСК ИС2 в норме
	{ 261	,1	,1	, &R0EE02LDU},	//( - , DU) Питание  АКНП  отключить
	{ 262	,1	,1	, &A0EE04LZ2},	//( - , MDuBz2) Исправность АКНП4
	{ 263	,1	,1	, &A0VP71LZ1},	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
	{ 264	,1	,1	, &A0VP71LZ2},	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
	{ 265	,1	,1	, &B0VP71LZ1},	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
	{ 266	,1	,1	, &B0VP71LZ2},	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
	{ 267	,1	,1	, &A0VS11LDU},	//( - , DU) АЗ1 готова к работе
	{ 268	,1	,1	, &B0VS11LDU},	//( - , DU) АЗ2 готова к работе
	{ 269	,1	,1	, &A1IE01LDU},	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
	{ 270	,1	,1	, &A3IE01LDU},	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
	{ 271	,1	,1	, &A2IE01LDU},	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
	{ 272	,1	,1	, &A1IE02LDU},	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
	{ 273	,1	,1	, &A3IE02LDU},	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
	{ 274	,1	,1	, &A2IE02LDU},	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
	{ 275	,1	,1	, &B1IE01LDU},	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
	{ 276	,1	,1	, &B2IE01LDU},	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
	{ 277	,1	,1	, &B3IE01LDU},	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
	{ 278	,1	,1	, &B1IE02LDU},	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
	{ 279	,1	,1	, &B3IE02LDU},	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
	{ 280	,1	,1	, &B2IE02LDU},	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
	{ 281	,1	,1	, &R0IE02LDU},	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
	{ 282	,1	,1	, &R0IE01LDU},	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
	{ 283	,1	,1	, &A6IE01LDU},	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
	{ 284	,1	,1	, &B6IE01LDU},	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
	{ 285	,1	,1	, &A8IE01LDU},	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
	{ 286	,1	,1	, &R5IS21LDU},	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
	{ 287	,1	,1	, &R5VS22LDU},	//( - , DU) Движение ворот отстойной зоны к закрыты
	{ 288	,1	,1	, &R5VS12LDU},	//( - , DU) Движение ворот отстойной зоны к открыты
	{ 289	,3	,1	, &R5VS01IDU},	//( - , DU) Готовность к управлению ворот отстойной зоны
	{ 290	,1	,1	, &R3VS22LDU},	//( - , DU) Движение гомогенных дверей к закрыты
	{ 291	,1	,1	, &R3VS12LDU},	//( - , DU) Движение гомогенных дверей к открыты
	{ 292	,3	,1	, &R3VS01IDU},	//( - , DU) Готовность к управлению гомогенных дверей
	{ 293	,1	,1	, &A3AB13LDU},	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
	{ 294	,1	,1	, &syn_A3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
	{ 295	,1	,1	, &B3AB13LDU},	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
	{ 296	,1	,1	, &syn_B3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
	{ 297	,3	,1	, &R0DE02LDU},	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
	{ 298	,3	,1	, &R0DE03LDU},	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
	{ 299	,3	,1	, &R0DE04LDU},	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
	{ 300	,3	,1	, &R0DE08LDU},	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
	{ 301	,3	,1	, &R0DE05LDU},	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
	{ 302	,3	,1	, &R0DE09LDU},	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
	{ 303	,3	,1	, &R0DE0ALDU},	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
	{ 304	,3	,1	, &R0DE07LDU},	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
	{ 305	,3	,1	, &R0DE0CLDU},	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
	{ 306	,3	,1	, &R0DE0BLDU},	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
	{ 307	,3	,1	, &R0DE0DLDU},	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
	{ 308	,3	,1	, &R0DE0FLDU},	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
	{ 309	,1	,1	, &R0DE31LDU},	//(sbk:20 - S01SBK, DiagnDU) диагностика шкафа ДУ сеть 1
	{ 310	,8	,1	, &R0VN12RDU},	//( - , DU) Заданная мощность РУ
	{ 311	,1	,1	, &R0AB19LDU},	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
	{ 312	,8	,1	, &R0CN93LDU},	//( - , DU) время работы на мощности более 100Вт, сек
	{ 313	,8	,1	, &R0CN94LDU},	//( - , DU) Скорость изменения мощности
	{ 314	,3	,1	, &R0CN95LDU},	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
	{ 315	,1	,1	, &R0AD03LZ1},	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
	{ 316	,1	,1	, &R0AD03LZ2},	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
	{ 317	,1	,1	, &R0AD04LZ1},	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
	{ 318	,1	,1	, &R0AD04LZ2},	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
	{ 319	,1	,1	, &R0AD05LZ1},	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
	{ 320	,1	,1	, &R0AD05LZ2},	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
	{ 321	,1	,1	, &B8IS12LDU},	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
	{ 322	,1	,1	, &B8IS21LDU},	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
	{ 323	,1	,1	, &A1VP41LZ1},	//( - , DU) Давление СБРОС ББ1 ниже АС
	{ 324	,1	,1	, &A1VP41LZ2},	//( - , DU) Давление СБРОС ББ1 ниже АС
	{ 325	,1	,1	, &R0VL22LDU},	//( - , DU) Конец программы 200сек
	{ 326	,1	,1	, &R0VL23LDU},	//( - , DU) Конец программы 20мин
	{ 327	,1	,1	, &B1VP41LZ1},	//( - , DU) Давление СБРОС ББ2 ниже АС
	{ 328	,1	,1	, &B1VP41LZ2},	//( - , DU) Давление СБРОС ББ2 ниже АС
	{ 329	,1	,1	, &A3AB19LDU},	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
	{ 330	,1	,1	, &B3AB19LDU},	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
	{ 331	,1	,1	, &A3EE03LDU},	//( - , DU) ВПИС ИС1
	{ 332	,1	,1	, &B3EE03LDU},	//( - , DU) ВПИС ИС2
	{ 333	,1	,1	, &B3AB15LDU},	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
	{ 334	,1	,1	, &KKL9},	//( - , - ) 
	{ 335	,1	,1	, &hz1},	//( - , - ) 
	{ 336	,1	,1	, &hz2},	//( - , - ) 
	{ 337	,1	,1	, &hz3},	//( - , - ) 
	{ 338	,1	,1	, &hz4},	//( - , - ) 
	{ 339	,1	,1	, &hz5},	//( - , - ) 
	{ 340	,1	,1	, &hz6},	//( - , - ) 
	{ 341	,1	,1	, &bd1},	//( - , - ) 
	{ 342	,1	,1	, &bd2},	//( - , - ) 
	{ 343	,1	,1	, &bd3},	//( - , - ) 
	{ 344	,1	,1	, &bd4},	//( - , - ) 
	{ 345	,1	,1	, &bd5},	//( - , - ) 
	{ 346	,1	,1	, &bd6},	//( - , - ) 
	{ 347	,1	,1	, &a1ab1},	//( - , - ) 
	{ 348	,1	,1	, &a1ab2},	//( - , - ) 
	{ 349	,1	,1	, &a1ab3},	//( - , - ) 
	{ 350	,1	,1	, &a1ab4},	//( - , - ) 
	{ 351	,1	,1	, &a1ab5},	//( - , - ) 
	{ 352	,5	,1	, &B1IC01UDU},	//( - , MDuS) Координата штока ББ2 (дел.энк)
	{ 353	,8	,1	, &B1VC01RDU},	//( - , DU) Координата ББ2, мм
	{ 354	,1	,1	, &B1IS11LDU},	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
	{ 355	,5	,1	, &A2IC01UDU},	//( - , MDuS) Координата штока РБ1 (дел.энк)
	{ 356	,5	,1	, &B2IC01UDU},	//( - , MDuS) Координата штока РБ2 (дел.энк)
	{ 357	,5	,1	, &A3IC01UDU},	//( - , MDuS) Координата штока ИС1 (дел.энк)
	{ 358	,3	,1	, &TTLDU},	//( - , DU) ttl
	{ 359	,1	,1	, &R0DE32LDU},	//(sbk:20 - S02SBK, DiagnDU) диагностика шкафа ДУ сеть 2
	{ 360	,1	,1	, &R0DE33LDU},	//(sbk:20 - S03SBK, DiagnDU) диагностика шкафа ДУ двери
	{ 361	,1	,1	, &R0DE34LDU},	//(sbk:20 - S04SBK, DiagnDU) диагностика шкафа ДУ температура меньше 43
	{ 362	,1	,1	, &R0DE35LDU},	//(sbk:20 - S05SBK, DiagnDU) диагностика шкафа ДУ температура больше 53
	{ 363	,1	,1	, &R0DE36LDU},	//(sbk:20 - S06SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 1
	{ 364	,1	,1	, &R0DE37LDU},	//(sbk:20 - S07SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 2
	{ 365	,1	,1	, &R0DE38LDU},	//(sbk:20 - S08SBK, DiagnDU) диагностика шкафа ДУ МП15-3 место 3
	{ 366	,1	,1	, &R0DE39LDU},	//(sbk:20 - S09SBK, DiagnDU) диагностика шкафа ДУ МП24-2 место 4
	{ 367	,1	,1	, &R0DEB3LDU},	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
	{ 368	,1	,1	, &R0DEB2LDU},	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
	{ 369	,1	,1	, &R0DEB1LDU},	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
	{ 370	,1	,1	, &R0DEB4LDU},	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
	{ 371	,1	,1	, &R0DE3DLDU},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
	{ 372	,1	,1	, &R0DE3CLDU},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
	{ 373	,1	,1	, &TestDiagnDU},	//( - , DU) Неисправность от
	{ 374	,1	,1	, &KKL1},	//( - , - ) 
	{ 375	,1	,1	, &KKL2},	//( - , - ) 
	{ 376	,1	,1	, &KKL3},	//( - , - ) 
	{ 377	,1	,1	, &KKL4},	//( - , - ) 
	{ 378	,1	,1	, &KKL5},	//( - , - ) 
	{ 379	,1	,1	, &KKL6},	//( - , - ) 
	{ 380	,1	,1	, &KKL7},	//( - , - ) 
	{ 381	,1	,1	, &KKL8},	//( - , - ) 
	{ 382	,1	,1	, &B6AB06LDU},	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
	{ 383	,1	,1	, &B6AB07LDU},	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
	{ 384	,1	,1	, &B6AB08LDU},	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
	{ 385	,1	,1	, &B6AB09LDU},	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
	{ 386	,1	,1	, &A6AB05LDU},	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
	{ 387	,1	,1	, &B8VS12LDU},	//( - , DU) Движение АЗ2 в сторону ВУ
	{ 388	,8	,1	, &B8CV01RDU},	//( - , DU) Измеренная скорость перемещения АЗ2
	{ 389	,1	,1	, &B8AB06LDU},	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
	{ 390	,1	,1	, &B8AB07LDU},	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
	{ 391	,1	,1	, &B8AB05LDU},	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
	{ 392	,1	,1	, &B8VS22LDU},	//( - , DU) Движение АЗ2 в сторону НУ
	{ 393	,1	,1	, &B8AZ03LDU},	//( - , DU) Несанкционированное перемещение АЗ2
	{ 394	,1	,1	, &R0MD11LP1},	//( - , DU) Кнопка ПУСК
	{ 395	,1	,1	, &B8AD10LDU},	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
	{ 396	,1	,1	, &B8AD20LDU},	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
	{ 397	,1	,1	, &B8IS11LDU},	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
	{ 398	,1	,1	, &B8AB01LDU},	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
	{ 399	,1	,1	, &B8AB04LDU},	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
	{ 400	,1	,1	, &B8AB08LDU},	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
	{ 401	,1	,1	, &B8AB09LDU},	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
	{ 402	,1	,1	, &B8AB10LDU},	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
	{ 403	,1	,1	, &B8AB11LDU},	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
	{ 404	,1	,1	, &B8AB12LDU},	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
	{ 405	,1	,1	, &B5AZ03LDU},	//( - , DU) Несанкционированное перемещение НЛ2
	{ 406	,1	,1	, &B5AB01LDU},	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
	{ 407	,1	,1	, &B5AB02LDU},	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
	{ 408	,1	,1	, &A4IS21LDU},	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
	{ 409	,1	,1	, &B4IS21LDU},	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
	{ 410	,1	,1	, &B4AD10LDU},	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
	{ 411	,1	,1	, &A4AD10LDU},	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
	{ 412	,1	,1	, &A4AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ1
	{ 413	,1	,1	, &A4AB01LDU},	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
	{ 414	,1	,1	, &A4AB02LDU},	//( - , DU) Блокировка движения НИ1 - Нет перемещения
	{ 415	,1	,1	, &B4AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ2
	{ 416	,1	,1	, &B4AB01LDU},	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
	{ 417	,1	,1	, &B4AB02LDU},	//( - , DU) Блокировка движения НИ2 - Нет перемещения
	{ 418	,1	,1	, &A5AB04LDU},	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
	{ 419	,1	,1	, &B5AB04LDU},	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
	{ 420	,1	,1	, &A1IS12LDU},	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
	{ 421	,1	,1	, &A2IS12LDU},	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
	{ 422	,1	,1	, &B1IS12LDU},	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
	{ 423	,1	,1	, &B2IS12LDU},	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
	{ 424	,1	,1	, &R4IS11LDU},	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
	{ 425	,1	,1	, &A6AB06LDU},	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
	{ 426	,1	,1	, &A6AB07LDU},	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
	{ 427	,1	,1	, &A6AB08LDU},	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
	{ 428	,1	,1	, &A6AB09LDU},	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
	{ 429	,1	,1	, &A8AB01LDU},	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
	{ 430	,1	,1	, &A2VS11LDU},	//( - , DU) Движение РБ1 в сторону ВУ
	{ 431	,8	,1	, &A2CV01RDU},	//( - , DU) Измеренная скорость перемещения РБ1
	{ 432	,1	,1	, &A2AB04LDU},	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
	{ 433	,1	,1	, &A2AB02LDU},	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
	{ 434	,1	,1	, &A2AB01LDU},	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
	{ 435	,1	,1	, &A2VS21LDU},	//( - , DU) Движение РБ1 в сторону НУ
	{ 436	,1	,1	, &A2AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
	{ 437	,1	,1	, &A2AD11LDU},	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
	{ 438	,1	,1	, &A2AD21LDU},	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
	{ 439	,1	,1	, &A2AD02LDU},	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
	{ 440	,1	,1	, &A2AD03LDU},	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
	{ 441	,1	,1	, &A2AD04LDU},	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
	{ 442	,1	,1	, &A2AD05LDU},	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
	{ 443	,1	,1	, &A2AB07LDU},	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
	{ 444	,1	,1	, &A2AB08LDU},	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
	{ 445	,1	,1	, &A2AB05LDU},	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
	{ 446	,1	,1	, &A2AB06LDU},	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
	{ 447	,1	,1	, &A2AB09LDU},	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
	{ 448	,1	,1	, &A2AB10LDU},	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
	{ 449	,1	,1	, &A2AB11LDU},	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
	{ 450	,1	,1	, &A2AB12LDU},	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 451	,1	,1	, &A2AB13LDU},	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
	{ 452	,1	,1	, &A2AB14LDU},	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
	{ 453	,1	,1	, &B8AB13LDU},	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
	{ 454	,1	,1	, &B8AB14LDU},	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
	{ 455	,1	,1	, &B8AB02LDU},	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
	{ 456	,1	,1	, &A8VS12LDU},	//( - , DU) Движение ДС2 в сторону ВУ
	{ 457	,8	,1	, &A8CV01RDU},	//( - , DU) Измеренная скорость перемещения ДС2
	{ 458	,1	,1	, &A8AB06LDU},	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
	{ 459	,1	,1	, &A8AB07LDU},	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
	{ 460	,1	,1	, &A8AB05LDU},	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
	{ 461	,1	,1	, &A8VS22LDU},	//( - , DU) Движение ДС2 в сторону НУ
	{ 462	,1	,1	, &A8AZ03LDU},	//( - , DU) Несанкционированное перемещение ДС2
	{ 463	,1	,1	, &A8AD10LDU},	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
	{ 464	,1	,1	, &A8AD20LDU},	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
	{ 465	,1	,1	, &B8IS22LDU},	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
	{ 466	,1	,1	, &A8IS12LDU},	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
	{ 467	,1	,1	, &A8AB04LDU},	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
	{ 468	,1	,1	, &A8IS22LDU},	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
	{ 469	,1	,1	, &A8AB08LDU},	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
	{ 470	,1	,1	, &A8AB09LDU},	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
	{ 471	,1	,1	, &A8AB10LDU},	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
	{ 472	,1	,1	, &A8AB11LDU},	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
	{ 473	,1	,1	, &A8AB12LDU},	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
	{ 474	,1	,1	, &A8AB13LDU},	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
	{ 475	,1	,1	, &A8AB14LDU},	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
	{ 476	,1	,1	, &A8AB02LDU},	//( - , DU) Блокировка движения ДС2- АНИ не установлен
	{ 477	,1	,1	, &A6VS22LDU},	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
	{ 478	,1	,1	, &A6VS12LDU},	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
	{ 479	,1	,1	, &B6VS22LDU},	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
	{ 480	,1	,1	, &B6VS12LDU},	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
	{ 481	,1	,1	, &A6AD10LDU},	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
	{ 482	,1	,1	, &A6AD20LDU},	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
	{ 483	,1	,1	, &B6AD10LDU},	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
	{ 484	,1	,1	, &B6AD20LDU},	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
	{ 485	,1	,1	, &A6AZ03LDU},	//( - , DU) Несанкционированное перемещение БЗ1
	{ 486	,1	,1	, &A6AB01LDU},	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
	{ 487	,1	,1	, &A6AB02LDU},	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
	{ 488	,1	,1	, &B6AZ03LDU},	//( - , DU) Несанкционированное перемещение БЗ2
	{ 489	,1	,1	, &B6AB01LDU},	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
	{ 490	,1	,1	, &B6AB02LDU},	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
	{ 491	,1	,1	, &A6AB04LDU},	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
	{ 492	,1	,1	, &B6AB04LDU},	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
	{ 493	,1	,1	, &R4AB01LDU},	//( - , DU) Блокировка движения тележки - АНИ не установлен
	{ 494	,1	,1	, &R8IS11LDU},	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
	{ 495	,1	,1	, &R6IS21LDU},	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
	{ 496	,1	,1	, &A0VN71LZ2},	//( - , MDuBz2) АЗ по АС мощности для АЗ1
	{ 497	,1	,1	, &A0VN71LZ1},	//( - , MDuBz1) АЗ по АС мощности для АЗ1
	{ 498	,1	,1	, &R0NE01LDU},	//( - , DU) Потеря связи с БАЗ1
	{ 499	,1	,1	, &R0NE02LDU},	//( - , DU) Потеря связи с БАЗ2
	{ 500	,3	,1	, &R0MW15IP1},	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
	{ 501	,3	,1	, &R0MW14IP1},	//( - , DU) Переключатель ПРОГРАММЫ
	{ 502	,3	,1	, &R0MW12IP1},	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
	{ 503	,3	,1	, &R0MW13IP1},	//( - , DU) Переключатель ВЫБОР ЗОН
	{ 504	,3	,1	, &R0MW16IP1},	//( - , DU) Переключатель ВИД ПРОВЕРКИ
	{ 505	,3	,1	, &R0MW11IP1},	//( - , DU) Переключатель ВЫСТРЕЛ
	{ 506	,3	,1	, &R0MW11IP2},	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
	{ 507	,1	,1	, &R0MW13LP2},	//( - , DU) Переключатель СЕТЬ
	{ 508	,1	,1	, &R0MD32LP1},	//( - , DU) Кнопка СПУСК
	{ 509	,1	,1	, &R0MD31LP1},	//( - , DU) Кнопка СТОП
	{ 510	,1	,1	, &A1IS21LDU},	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
	{ 511	,1	,1	, &A2IS21LDU},	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
	{ 512	,1	,1	, &A3IS21LDU},	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
	{ 513	,1	,1	, &B1IS21LDU},	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
	{ 514	,1	,1	, &B2IS21LDU},	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
	{ 515	,1	,1	, &B3IS21LDU},	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
	{ 516	,1	,1	, &R0ES01LDU},	//( - , DU) ОРР не в исходном состоянии
	{ 517	,1	,1	, &R4MD11LP2},	//( - , DU) Кнопка ВПЕРЁД  (тележки)
	{ 518	,1	,1	, &R4MD31LP2},	//( - , DU) Кнопка СТОП  (тележки)
	{ 519	,1	,1	, &R4MD21LP2},	//( - , DU) Кнопка НАЗАД  (тележки)
	{ 520	,1	,1	, &A6IS11LDU},	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
	{ 521	,1	,1	, &A6IS21LDU},	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
	{ 522	,1	,1	, &B6IS11LDU},	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
	{ 523	,1	,1	, &B6IS21LDU},	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
	{ 524	,1	,1	, &R4AB13LDU},	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
	{ 525	,1	,1	, &R4AB14LDU},	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
	{ 526	,1	,1	, &R4AB15LDU},	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
	{ 527	,1	,1	, &R5IS11LDU},	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
	{ 528	,1	,1	, &R4AB16LDU},	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
	{ 529	,1	,1	, &R4AB17LDU},	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
	{ 530	,1	,1	, &R4AB18LDU},	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
	{ 531	,1	,1	, &R4AD10LDU},	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
	{ 532	,1	,1	, &R4AD20LDU},	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
	{ 533	,1	,1	, &A5VS22LDU},	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
	{ 534	,1	,1	, &A5VS12LDU},	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
	{ 535	,1	,1	, &B5VS22LDU},	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
	{ 536	,1	,1	, &B5VS12LDU},	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
	{ 537	,1	,1	, &B5AD10LDU},	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
	{ 538	,1	,1	, &B5AD20LDU},	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
	{ 539	,1	,1	, &A5AD10LDU},	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
	{ 540	,1	,1	, &A5AD20LDU},	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
	{ 541	,1	,1	, &A5IS11LDU},	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
	{ 542	,1	,1	, &A5IS21LDU},	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
	{ 543	,1	,1	, &B5IS11LDU},	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
	{ 544	,1	,1	, &B5IS21LDU},	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
	{ 545	,1	,1	, &A5AZ03LDU},	//( - , DU) Несанкционированное перемещение НЛ1
	{ 546	,1	,1	, &A5AB01LDU},	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
	{ 547	,1	,1	, &A5AB02LDU},	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
	{ 548	,1	,1	, &R4AB02LDU},	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
	{ 549	,1	,1	, &R0NE08LDU},	//( - , DU) Потеря связи с ОПУ
	{ 550	,1	,1	, &R4IS21LDU},	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
	{ 551	,1	,1	, &R4IS22LDU},	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
	{ 552	,1	,1	, &R4IS12LDU},	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
	{ 553	,1	,1	, &R4VS22LDU},	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
	{ 554	,1	,1	, &R4VS12LDU},	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
	{ 555	,1	,1	, &R4AZ03LDU},	//( - , DU) Несанкционированное перемещение тележки
	{ 556	,1	,1	, &R4AB03LDU},	//( - , DU) Блокировка движения тележки - Самоход любого механизма
	{ 557	,1	,1	, &R1IS21LDU},	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
	{ 558	,1	,1	, &R2IS21LDU},	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
	{ 559	,1	,1	, &R4AB04LDU},	//( - , DU) Блокировка движения тележки - Превышение времени движения
	{ 560	,1	,1	, &R4AB05LDU},	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
	{ 561	,1	,1	, &R4AB06LDU},	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
	{ 562	,1	,1	, &R4AB07LDU},	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
	{ 563	,1	,1	, &R4AB08LDU},	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
	{ 564	,1	,1	, &R4AB09LDU},	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
	{ 565	,1	,1	, &B0VN71LZ1},	//( - , MDuBz1) АЗ по АС мощности для АЗ2
	{ 566	,1	,1	, &B0VN71LZ2},	//( - , MDuBz2) АЗ по АС мощности для АЗ2
	{ 567	,1	,1	, &R4AB10LDU},	//( - , DU) Блокировка тележки - не открыта биологическая защита
	{ 568	,1	,1	, &R4AB11LDU},	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
	{ 569	,1	,1	, &R4AB12LDU},	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
	{ 570	,1	,1	, &A4IS11LDU},	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
	{ 571	,1	,1	, &B4IS11LDU},	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
	{ 572	,1	,1	, &A3AB09LDU},	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
	{ 573	,1	,1	, &A3AB10LDU},	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
	{ 574	,1	,1	, &A3AB11LDU},	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
	{ 575	,1	,1	, &A3AB12LDU},	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 576	,1	,1	, &A3AB14LDU},	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
	{ 577	,1	,1	, &A3AB16LDU},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
	{ 578	,1	,1	, &A3AB17LDU},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
	{ 579	,1	,1	, &A3AB18LDU},	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
	{ 580	,1	,1	, &A3AB20LDU},	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
	{ 581	,1	,1	, &B3VS12LDU},	//( - , DU) Движение ИС2 в сторону ВУ
	{ 582	,8	,1	, &B3CV01RDU},	//( - , DU) Измеренная скорость перемещения ИС2
	{ 583	,1	,1	, &B3AB04LDU},	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
	{ 584	,1	,1	, &B3AB02LDU},	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
	{ 585	,1	,1	, &B3AB01LDU},	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
	{ 586	,1	,1	, &B3VS22LDU},	//( - , DU) Движение ИС2 в сторону НУ
	{ 587	,1	,1	, &B3AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
	{ 588	,1	,1	, &B3AD11LDU},	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
	{ 589	,1	,1	, &B3AD21LDU},	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
	{ 590	,1	,1	, &B3AD02LDU},	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
	{ 591	,1	,1	, &B3AD03LDU},	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
	{ 592	,1	,1	, &B3AD04LDU},	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
	{ 593	,1	,1	, &B3AD05LDU},	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
	{ 594	,1	,1	, &B3AD01LDU},	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
	{ 595	,1	,1	, &B1AB13LDU},	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
	{ 596	,1	,1	, &B1AB14LDU},	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
	{ 597	,1	,1	, &B1AB16LDU},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
	{ 598	,1	,1	, &B1AB17LDU},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
	{ 599	,1	,1	, &B1AB18LDU},	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
	{ 600	,1	,1	, &A3VS12LDU},	//( - , DU) Движение ИС1 в сторону ВУ
	{ 601	,8	,1	, &A3CV01RDU},	//( - , DU) Измеренная скорость перемещения ИС1
	{ 602	,1	,1	, &A3AB04LDU},	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
	{ 603	,1	,1	, &A3AB02LDU},	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
	{ 604	,1	,1	, &A3AB01LDU},	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
	{ 605	,1	,1	, &A3VS22LDU},	//( - , DU) Движение ИС1 в сторону НУ
	{ 606	,1	,1	, &A3AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
	{ 607	,1	,1	, &A3AD11LDU},	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
	{ 608	,1	,1	, &A3AD21LDU},	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
	{ 609	,1	,1	, &A3AD02LDU},	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
	{ 610	,1	,1	, &A3AD03LDU},	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
	{ 611	,1	,1	, &A3AD04LDU},	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
	{ 612	,1	,1	, &A3AD05LDU},	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
	{ 613	,1	,1	, &A3AD01LDU},	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
	{ 614	,8	,1	, &A3CV02RDU},	//( - , DU) Заданная скорость перемещения ИС1
	{ 615	,1	,1	, &A3AB07LDU},	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
	{ 616	,1	,1	, &A3AB08LDU},	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
	{ 617	,1	,1	, &A3AB05LDU},	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
	{ 618	,1	,1	, &A3AB06LDU},	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
	{ 619	,1	,1	, &R0MD11LP2},	//( - , DU) Кнопка Пуск проверки схем сброса
	{ 620	,1	,1	, &R0VX01LDU},	//( - , DU) ДО ИМПУЛЬСА
	{ 621	,3	,1	, &R0VL01IDU},	//( - , DU) До импульса минут
	{ 622	,3	,1	, &R0VL11IDU},	//( - , DU) До импульса секунд
	{ 623	,8	,1	, &R0VL06RDU},	//( - , DU) Индикация (Время задержки от ВУ РБ)
	{ 624	,1	,1	, &B3AD33LDU},	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 закрыть (обесточить)
	{ 625	,1	,1	, &B3IS11LDU},	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
	{ 626	,8	,1	, &R0VL02RDU},	//( - , DU) Индикация (Время задержки ИНИ)
	{ 627	,1	,1	, &R8AD21LDU},	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
	{ 628	,1	,1	, &R0AD14LDU},	//( - , DU) Имитация срабатывания верхней АС II УР
	{ 629	,8	,1	, &R0VL04RDU},	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
	{ 630	,1	,1	, &R0AB04LDU},	//( - , DU) Нарушение времени срабатывания верхней АС II УР
	{ 631	,1	,1	, &R0AB06LDU},	//( - , DU) Нарушение времени задержки от ВУ РБ
	{ 632	,1	,1	, &R0AB02LDU},	//( - , DU) Нарушение времени задержки ИНИ
	{ 633	,8	,1	, &R0VL03RDU},	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
	{ 634	,8	,1	, &R0VL05RDU},	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
	{ 635	,3	,1	, &R0VL21IDU},	//( - , DU) Декатрон
	{ 636	,1	,1	, &R0VX03LDU},	//( - , DU) Готовность 2 мин
	{ 637	,3	,1	, &R0VS21IDU},	//( - , DU) Индикация ВИД ПРОВЕРКИ
	{ 638	,3	,1	, &A1VS01IDU},	//( - , DU) Готовность к управлению ББ1
	{ 639	,3	,1	, &B1VS01IDU},	//( - , DU) Готовность к управлению ББ2
	{ 640	,3	,1	, &A3VS01IDU},	//( - , DU) Готовность к управлению ИС1
	{ 641	,3	,1	, &B3VS01IDU},	//( - , DU) Готовность к управлению ИС2
	{ 642	,3	,1	, &A2VS01IDU},	//( - , DU) Готовность к управлению РБ1
	{ 643	,8	,1	, &B3CV02RDU},	//( - , DU) Заданная скорость перемещения ИС2
	{ 644	,1	,1	, &B3AB07LDU},	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
	{ 645	,1	,1	, &B3AB08LDU},	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
	{ 646	,1	,1	, &B3AB05LDU},	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
	{ 647	,1	,1	, &B3AB06LDU},	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
	{ 648	,1	,1	, &B3AB09LDU},	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
	{ 649	,1	,1	, &B3AB10LDU},	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
	{ 650	,1	,1	, &B3AB11LDU},	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
	{ 651	,1	,1	, &B3AB12LDU},	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{ 652	,1	,1	, &B3AB14LDU},	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
	{ 653	,1	,1	, &B3AB16LDU},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
	{ 654	,1	,1	, &B3AB17LDU},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
	{ 655	,1	,1	, &B3AB18LDU},	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
	{ 656	,1	,1	, &B3AB20LDU},	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
	{ 657	,1	,1	, &C1MD31LP1},	//( - , DU) Кнопка СБРОС ББ
	{ 658	,1	,1	, &C1MD31LP2},	//( - , DU) Кнопка СБРОС ББ
	{ 659	,1	,1	, &A2AD31LDU},	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
	{ 660	,1	,1	, &B2AD31LDU},	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
	{ 661	,1	,1	, &A1AD31LDU},	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
	{ 662	,1	,1	, &B1AD31LDU},	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
	{ 663	,1	,1	, &A2AD32LDU},	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
	{ 664	,1	,1	, &B2AD32LDU},	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
	{ 665	,1	,1	, &A1AD32LDU},	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
	{ 666	,1	,1	, &B1AD32LDU},	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
	{ 667	,1	,1	, &B2AB12LDU},	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{ 668	,1	,1	, &B2AB13LDU},	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
	{ 669	,1	,1	, &B2AB14LDU},	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
	{ 670	,1	,1	, &B2AB16LDU},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
	{ 671	,1	,1	, &B2AB17LDU},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
	{ 672	,1	,1	, &R1AZ03LDU},	//( - , DU) Несанкционированное перемещение МДЗ1
	{ 673	,1	,1	, &R1AB01LDU},	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
	{ 674	,1	,1	, &R1AB02LDU},	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
	{ 675	,1	,1	, &R2AZ03LDU},	//( - , DU) Несанкционированное перемещение МДЗ2
	{ 676	,1	,1	, &R2AB01LDU},	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
	{ 677	,1	,1	, &R2AB02LDU},	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
	{ 678	,1	,1	, &R1AB04LDU},	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
	{ 679	,1	,1	, &R2AB04LDU},	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
	{ 680	,1	,1	, &R1AD10LDU},	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
	{ 681	,1	,1	, &R1AD20LDU},	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
	{ 682	,1	,1	, &R1IS11LDU},	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
	{ 683	,1	,1	, &R1VS22LDU},	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
	{ 684	,1	,1	, &R2VS22LDU},	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
	{ 685	,1	,1	, &R2VS12LDU},	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
	{ 686	,1	,1	, &R1VS12LDU},	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
	{ 687	,1	,1	, &R2IS11LDU},	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
	{ 688	,1	,1	, &A1VS12LDU},	//( - , DU) Движение ББ1 в сторону ВУ
	{ 689	,8	,1	, &A1CV01RDU},	//( - , DU) Измеренная скорость перемещения ББ1
	{ 690	,1	,1	, &A1AB04LDU},	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
	{ 691	,1	,1	, &A2AB16LDU},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
	{ 692	,1	,1	, &A2AB17LDU},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
	{ 693	,1	,1	, &A2AD01LDU},	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
	{ 694	,8	,1	, &A2CV02RDU},	//( - , DU) Заданная скорость перемещения РБ1
	{ 695	,8	,1	, &B2CV01RDU},	//( - , DU) Измеренная скорость перемещения РБ2
	{ 696	,1	,1	, &B2AB04LDU},	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
	{ 697	,1	,1	, &B2AB02LDU},	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
	{ 698	,1	,1	, &B2AB01LDU},	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
	{ 699	,1	,1	, &B2AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
	{ 700	,1	,1	, &B2AD11LDU},	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
	{ 701	,1	,1	, &B2AD21LDU},	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
	{ 702	,1	,1	, &B2AD02LDU},	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
	{ 703	,1	,1	, &B2AD03LDU},	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
	{ 704	,1	,1	, &B2AD04LDU},	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
	{ 705	,1	,1	, &B2AD05LDU},	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
	{ 706	,1	,1	, &B2AD01LDU},	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
	{ 707	,8	,1	, &B2CV02RDU},	//( - , DU) Заданная скорость перемещения РБ2
	{ 708	,1	,1	, &B2AB07LDU},	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
	{ 709	,1	,1	, &B2AB08LDU},	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
	{ 710	,1	,1	, &B2AB05LDU},	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
	{ 711	,1	,1	, &B2AB06LDU},	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
	{ 712	,1	,1	, &B2AB09LDU},	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
	{ 713	,1	,1	, &B2AB10LDU},	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
	{ 714	,1	,1	, &B2AB11LDU},	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
	{ 715	,1	,1	, &A1AB18LDU},	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
	{ 716	,1	,1	, &B1VS12LDU},	//( - , DU) Движение ББ2 в сторону ВУ
	{ 717	,8	,1	, &B1CV01RDU},	//( - , DU) Измеренная скорость перемещения ББ2
	{ 718	,1	,1	, &B1AB04LDU},	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
	{ 719	,1	,1	, &B1AB02LDU},	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
	{ 720	,1	,1	, &B1AB01LDU},	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
	{ 721	,1	,1	, &B1VS22LDU},	//( - , DU) Движение ББ2 в сторону НУ
	{ 722	,1	,1	, &B1AZ03LDU},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
	{ 723	,1	,1	, &B1AD11LDU},	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
	{ 724	,1	,1	, &B1AD21LDU},	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
	{ 725	,1	,1	, &B1AD02LDU},	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
	{ 726	,1	,1	, &B1AD03LDU},	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
	{ 727	,1	,1	, &B1AD04LDU},	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
	{ 728	,1	,1	, &B1AD05LDU},	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
	{ 729	,1	,1	, &B1AD01LDU},	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
	{ 730	,8	,1	, &B1CV02RDU},	//( - , DU) Заданная скорость перемещения ББ2
	{ 731	,1	,1	, &B1AB07LDU},	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
	{ 732	,1	,1	, &B1AB08LDU},	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
	{ 733	,1	,1	, &B1AB05LDU},	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
	{ 734	,1	,1	, &B1AB06LDU},	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
	{ 735	,1	,1	, &B1AB09LDU},	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
	{ 736	,1	,1	, &B1AB10LDU},	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
	{ 737	,1	,1	, &B1AB11LDU},	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
	{ 738	,1	,1	, &B1AB12LDU},	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 739	,1	,1	, &A1AB02LDU},	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
	{ 740	,1	,1	, &A1AB01LDU},	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
	{ 741	,1	,1	, &A1VS22LDU},	//( - , DU) Движение ББ1 в сторону НУ
	{ 742	,1	,1	, &A1AZ03LDU},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
	{ 743	,1	,1	, &A1AD11LDU},	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
	{ 744	,1	,1	, &A1AD21LDU},	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
	{ 745	,1	,1	, &A1AD02LDU},	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
	{ 746	,1	,1	, &A1AD03LDU},	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
	{ 747	,1	,1	, &A1AD04LDU},	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
	{ 748	,1	,1	, &A1AD05LDU},	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
	{ 749	,1	,1	, &A1AD01LDU},	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
	{ 750	,8	,1	, &A1CV02RDU},	//( - , DU) Заданная скорость перемещения ББ1
	{ 751	,1	,1	, &A1AB07LDU},	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
	{ 752	,1	,1	, &A1AB08LDU},	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
	{ 753	,1	,1	, &A1AB05LDU},	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
	{ 754	,1	,1	, &A1AB06LDU},	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
	{ 755	,1	,1	, &A1AB09LDU},	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
	{ 756	,1	,1	, &A1AB10LDU},	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
	{ 757	,1	,1	, &A1AB11LDU},	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
	{ 758	,1	,1	, &A1AB12LDU},	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 759	,1	,1	, &A1AB13LDU},	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
	{ 760	,1	,1	, &A1AB14LDU},	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
	{ 761	,1	,1	, &A1AB16LDU},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
	{ 762	,1	,1	, &A1AB17LDU},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
	{ 763	,8	,1	, &fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
	{ 764	,5	,1	, &dEM_A1UC05UDU},	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
	{ 765	,5	,1	, &dEM_A1UC06UDU},	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
	{ 766	,5	,1	, &dEM_A2UC06UDU},	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
	{ 767	,5	,1	, &dEM_A2UC05UDU},	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
	{ 768	,8	,1	, &fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
	{ 769	,5	,1	, &dEM_A3UC06UDU},	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
	{ 770	,5	,1	, &dEM_A3UC05UDU},	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
	{ 771	,8	,1	, &fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
	{ 772	,5	,1	, &dEM_A8UC06UDU},	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
	{ 773	,8	,1	, &fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
	{ 774	,5	,1	, &dEM_A8UC05UDU},	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
	{ 775	,8	,1	, &fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{ 776	,8	,1	, &fEM_R0UV82RDU},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{ 777	,8	,1	, &fEM_R0UV83RDU},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{ 778	,8	,1	, &fEM_R0UV84RDU},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{ 779	,8	,1	, &fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 780	,8	,1	, &fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{ 781	,8	,1	, &fEM_R0UV87RDU},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 782	,8	,1	, &fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{ 783	,8	,1	, &fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{ 784	,8	,1	, &fEM_A3UP43RDU},	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
	{ 785	,8	,1	, &fEM_A3UP44RDU},	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
	{ 786	,8	,1	, &fEM_A3UP53RDU},	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
	{ 787	,8	,1	, &fEM_A3UP85RDU},	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 788	,8	,1	, &fEM_A3UP88RDU},	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 789	,8	,1	, &fEM_A3UP86RDU},	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 790	,8	,1	, &fEM_B8UV01RDU},	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
	{ 791	,8	,1	, &fEM_B8UV02RDU},	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
	{ 792	,8	,1	, &fEM_B8UV03RDU},	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
	{ 793	,8	,1	, &fEM_B8UL04RDU},	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
	{ 794	,3	,1	, &iEM_A2UV03CDU},	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
	{ 795	,8	,1	, &fEM_A2UV01RDU},	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
	{ 796	,8	,1	, &fEM_A2UV02RDU},	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
	{ 797	,8	,1	, &fEM_A1UV01RDU},	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
	{ 798	,8	,1	, &fEM_A1UV02RDU},	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
	{ 799	,8	,1	, &fEM_A1UC06RDU},	//(A1UC06RDU) Уставка определения самохода ББ  мм
	{ 800	,8	,1	, &fEM_A1UC05RDU},	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
	{ 801	,8	,1	, &fEM_A1UL04RDU},	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
	{ 802	,8	,1	, &fEM_A3UV01RDU},	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
	{ 803	,8	,1	, &fEM_A3UV02RDU},	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
	{ 804	,8	,1	, &fEM_A3UC06RDU},	//(A3UC06RDU) Уставка определения самохода ИС1  мм
	{ 805	,8	,1	, &fEM_A3UC05RDU},	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
	{ 806	,8	,1	, &fEM_A3UL04RDU},	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
	{ 807	,8	,1	, &fEM_A3UP54RDU},	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
	{ 808	,8	,1	, &fEM_A3UP87RDU},	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 809	,8	,1	, &fEM_R0UL05RDU},	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
	{ 810	,8	,1	, &fEM_R0UL20RDU},	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
	{ 811	,8	,1	, &fEM_B8UV04RDU},	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
	{ 812	,8	,1	, &fEM_B8UC06RDU},	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
	{ 813	,8	,1	, &fEM_B8UC05RDU},	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
	{ 814	,8	,1	, &fEM_A2UL05RDU},	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
	{ 815	,8	,1	, &fEM_A2UL03RDU},	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{ 816	,8	,1	, &fEM_A2UC06RDU},	//(A2UC06RDU) Уставка определения самохода РБ  мм
	{ 817	,8	,1	, &fEM_A2UC05RDU},	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
	{ 818	,8	,1	, &fEM_A2UL04RDU},	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
	{ 819	,8	,1	, &fEM_A1UL03RDU},	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
	{ 820	,8	,1	, &fEM_A1UL05RDU},	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
	{ 821	,8	,1	, &fEM_A3UL03RDU},	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
	{ 822	,8	,1	, &fEM_A3UL05RDU},	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
	{ 823	,8	,1	, &fEM_A1UC08RDU},	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
	{ 824	,8	,1	, &fEM_A3UC08RDU},	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
	{ 825	,8	,1	, &fEM_A1UC07RDU},	//(A1UC07RDU) Зона возврата при наведении ББ мм
	{ 826	,8	,1	, &fEM_A1UL01RDU},	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 827	,8	,1	, &fEM_A3UC07RDU},	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
	{ 828	,8	,1	, &fEM_A3UL01RDU},	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 829	,8	,1	, &fEM_A2UC08RDU},	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
	{ 830	,8	,1	, &fEM_A2UC07RDU},	//(A2UC07RDU) Зона возврата при наведении РБ  мм
	{ 831	,8	,1	, &fEM_A2UL01RDU},	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 832	,8	,1	, &fEM_B8UC01RDU},	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
	{ 833	,8	,1	, &fEM_B8UL07RDU},	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
	{ 834	,8	,1	, &fEM_B8UC02RDU},	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
	{ 835	,8	,1	, &fEM_B8UL01RDU},	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 836	,8	,1	, &fEM_B8UL05RDU},	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
	{ 837	,8	,1	, &fEM_B8UL03RDU},	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
	{ 838	,8	,1	, &fEM_B8UL06RDU},	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
	{ 839	,8	,1	, &fEM_A9UZ03RDU},	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
	{ 840	,8	,1	, &fEM_A9UZ04RDU},	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
	{ 841	,8	,1	, &fEM_A9UZ05RDU},	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
	{ 842	,8	,1	, &fEM_R4UZ04RDU},	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
	{ 843	,8	,1	, &fEM_R4UZ03RDU},	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
	{ 844	,8	,1	, &fEM_R4UZ05RDU},	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
	{ 845	,8	,1	, &fEM_A5UZ03RDU},	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
	{ 846	,8	,1	, &fEM_A5UZ04RDU},	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
	{ 847	,8	,1	, &fEM_A5UZ05RDU},	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
	{ 848	,8	,1	, &fEM_A4UZ03RDU},	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
	{ 849	,8	,1	, &fEM_A4UZ04RDU},	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
	{ 850	,8	,1	, &fEM_A4UZ05RDU},	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
	{ 851	,8	,1	, &fEM_A6UZ03RDU},	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
	{ 852	,8	,1	, &fEM_A6UZ04RDU},	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
	{ 853	,8	,1	, &fEM_A6UZ05RDU},	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
	{ 854	,8	,1	, &fEM_R1UZ03RDU},	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
	{ 855	,8	,1	, &fEM_R1UZ04RDU},	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
	{ 856	,8	,1	, &fEM_R1UZ05RDU},	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
	{ 857	,8	,1	, &fEM_R0UL04RDU},	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
	{ 858	,8	,1	, &fEM_R0UL06RDU},	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
	{ 859	,8	,1	, &fEM_R0UL03RDU},	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
	{ 860	,8	,1	, &fEM_R0UL17RDU},	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
	{ 861	,8	,1	, &fEM_R0UL19RDU},	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{ 862	,8	,1	, &fEM_R0UL07RDU},	//(R0UL07RDU) Время срабатывания верхней АС II УР
	{ 863	,8	,1	, &fEM_R0UL18RDU},	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
	{ 864	,8	,1	, &fEM_R0UL16RDU},	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
	{ 865	,8	,1	, &fEM_R0UL02RDU},	//(R0UL02RDU) Время задержки  ИНИ
	{ 866	,8	,1	, &fEM_R0UN08RDU},	//(R0UN08RDU) 8-я заданная мощность
	{ 867	,8	,1	, &fEM_R0UN07RDU},	//(R0UN07RDU) 7-я заданная мощность
	{ 868	,8	,1	, &fEM_R0UN06RDU},	//(R0UN06RDU) 6-я заданная мощность
	{ 869	,8	,1	, &fEM_R0UN05RDU},	//(R0UN05RDU) 5-я заданная мощность
	{ 870	,8	,1	, &fEM_R0UN04RDU},	//(R0UN04RDU) 4-я заданная мощность
	{ 871	,8	,1	, &fEM_R0UN03RDU},	//(R0UN03RDU) Ограничение 3 по мощности
	{ 872	,8	,1	, &fEM_R0UN02RDU},	//(R0UN02RDU) 2-я заданная мощность
	{ 873	,8	,1	, &fEM_R0UN01RDU},	//(R0UN01RDU) 1-я заданная мощность
	{ 874	,8	,1	, &fEM_A2UC82RDU},	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
	{ 875	,8	,1	, &fEM_A2UC83RDU},	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
	{ 876	,8	,1	, &fEM_A1UC83RDU},	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
	{ 877	,8	,1	, &fEM_A2UC81RDU},	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
	{ 878	,8	,1	, &fEM_A1UC81RDU},	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
	{ 879	,8	,1	, &fEM_A1UC82RDU},	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
	{ 880	,8	,1	, &fEM_A2UL83RDU},	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{ 881	,8	,1	, &fEM_A3UC81RDU},	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
	{ 882	,8	,1	, &fEM_A3UC82RDU},	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
	{ 883	,8	,1	, &fEM_R0UN80RDU},	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
	{ 884	,3	,1	, &iEM_A2UV01IDU},	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
	{ 885	,3	,1	, &iEM_A2UV02IDU},	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
	{ 886	,3	,1	, &iEM_A1UV01IDU},	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
	{ 887	,3	,1	, &iEM_A1UV02IDU},	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
	{ 888	,3	,1	, &iEM_A1UV03IDU},	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
	{ 889	,3	,1	, &iEM_A3UV01IDU},	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
	{ 890	,3	,1	, &iEM_A3UV02IDU},	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
	{ 891	,1	,1	, &lEM_R0MD01LC1},	//(R0MD01LC1) Ручное управление ОРР
	{ 892	,8	,1	, &fEM_A3UC09RDU},	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
	{ 893	,8	,1	, &fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
	{ 894	,8	,1	, &fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
	{ 895	,8	,1	, &fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
	{ 896	,8	,1	, &fEM_R0UL21RDU},	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
	{ 897	,8	,1	, &fEM_R0UN09RDU},	//(R0UN09RDU) Минимальный период при регулировании мощности
	{ 898	,8	,1	, &fEM_R0UN11RDU},	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
	{ 899	,8	,1	, &fEM_R0UN12RDU},	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
	{ 900	,8	,1	, &fEM_R0UN13RDU},	//(R0UN13RDU) Минимальное изменение координаты, мм
	{ 901	,8	,1	, &fEM_R0UN14RDU},	//(R0UN14RDU) Максимальная координата штока ИМ, мм
	{ 902	,8	,1	, &fEM_R0UN16RDU},	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
	{ 903	,8	,1	, &fEM_R0UN17RDU},	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
	{ 904	,8	,1	, &fEM_R0UN18RDU},	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
	{ 905	,8	,1	, &fEM_R0UN19RDU},	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
	{ 906	,8	,1	, &fEM_R0UN70LDU},	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
	{ 907	,8	,1	, &fEM_R0UN71LDU},	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
	{ 908	,8	,1	, &fEM_R0UN72LDU},	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
	{ 909	,8	,1	, &fEM_R0UN73LDU},	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
	{ 910	,8	,1	, &fEM_R0UN74LDU},	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
	{ 911	,8	,1	, &fEM_R0UN75LDU},	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
	{ 912	,8	,1	, &fEM_R0UN80LDU},	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
	{ 913	,8	,1	, &fEM_R0UN81LDU},	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
	{ 914	,8	,1	, &fEM_R0UN82LDU},	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
	{ 915	,8	,1	, &fEM_R0UN83LDU},	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
	{ 916	,8	,1	, &fEM_R0UN84LDU},	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
	{ 917	,8	,1	, &fEM_R0UN85LDU},	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
	{ 918	,8	,1	, &fEM_R0UT20RDU},	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
	{ 919	,8	,1	, &fEM_R0UN25RDU},	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
	{ 920	,8	,1	, &fEM_R0UN15RDU},	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
	{ 921	,8	,1	, &fEM_R0UN26RDU},	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
	{ 922	,8	,1	, &fEM_R0UN27RDU},	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
	{ 923	,8	,1	, &fEM_R0UN24RDU},	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 924	,8	,1	, &fEM_R0UL25RDU},	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{ 925	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 926	,8	,1	, &internal2_m186_y0},	//(internal2_m186_y0) y0
	{ 927	,8	,1	, &internal2_m184_y0},	//(internal2_m184_y0) y0
	{ 928	,1	,1	, &internal2_m216_y0},	//(internal2_m216_y0) state
	{ 929	,1	,1	, &internal2_m210_y0},	//(internal2_m210_y0) state
	{ 930	,1	,1	, &internal2_m199_y1},	//(internal2_m199_y1) y1 - внутренний параметр
	{ 931	,1	,1	, &internal2_m206_y1},	//(internal2_m206_y1) y1 - внутренний параметр
	{ 932	,1	,1	, &internal2_m189_y1},	//(internal2_m189_y1) y1 - внутренний параметр
	{ 933	,1	,1	, &internal2_m196_y1},	//(internal2_m196_y1) y1 - внутренний параметр
	{ 934	,5	,1	, &internal2_m16_Nk0},	//(internal2_m16_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 935	,1	,1	, &internal2_m16_SetFlag},	//(internal2_m16_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 936	,5	,1	, &internal2_m108_Nk0},	//(internal2_m108_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 937	,1	,1	, &internal2_m108_SetFlag},	//(internal2_m108_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 938	,5	,1	, &internal2_m112_Nk0},	//(internal2_m112_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 939	,1	,1	, &internal2_m112_SetFlag},	//(internal2_m112_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 940	,5	,1	, &internal2_m75_Nk0},	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 941	,1	,1	, &internal2_m75_SetFlag},	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 942	,5	,1	, &internal2_m77_Nk0},	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 943	,1	,1	, &internal2_m77_SetFlag},	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 944	,5	,1	, &internal2_m47_Nk0},	//(internal2_m47_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 945	,1	,1	, &internal2_m47_SetFlag},	//(internal2_m47_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 946	,5	,1	, &internal2_m51_Nk0},	//(internal2_m51_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 947	,1	,1	, &internal2_m51_SetFlag},	//(internal2_m51_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 948	,5	,1	, &internal2_m21_Nk0},	//(internal2_m21_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 949	,1	,1	, &internal2_m21_SetFlag},	//(internal2_m21_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 950	,1	,1	, &internal1_m198_s},	//(internal1_m198_s) s - запомнили значение
	{ 951	,1	,1	, &internal1_m195_s},	//(internal1_m195_s) s - запомнили значение
	{ 952	,1	,1	, &internal1_m189_s},	//(internal1_m189_s) s - запомнили значение
	{ 953	,1	,1	, &internal1_m182_s},	//(internal1_m182_s) s - запомнили значение
	{ 954	,1	,1	, &internal1_m179_s},	//(internal1_m179_s) s - запомнили значение
	{ 955	,1	,1	, &internal1_m1707_q0},	//(internal1_m1707_q0) q0 - внутренний параметр
	{ 956	,1	,1	, &internal1_m2140_q0},	//(internal1_m2140_q0) q0 - внутренний параметр
	{ 957	,1	,1	, &internal1_m2124_q0},	//(internal1_m2124_q0) q0 - внутренний параметр
	{ 958	,1	,1	, &internal1_m2172_q0},	//(internal1_m2172_q0) q0 - внутренний параметр
	{ 959	,1	,1	, &internal1_m2156_q0},	//(internal1_m2156_q0) q0 - внутренний параметр
	{ 960	,1	,1	, &internal1_m2146_q0},	//(internal1_m2146_q0) q0 - внутренний параметр
	{ 961	,1	,1	, &internal1_m2127_q0},	//(internal1_m2127_q0) q0 - внутренний параметр
	{ 962	,1	,1	, &internal1_m2144_q0},	//(internal1_m2144_q0) q0 - внутренний параметр
	{ 963	,1	,1	, &internal1_m2125_q0},	//(internal1_m2125_q0) q0 - внутренний параметр
	{ 964	,1	,1	, &internal1_m2123_q0},	//(internal1_m2123_q0) q0 - внутренний параметр
	{ 965	,1	,1	, &internal1_m2122_q0},	//(internal1_m2122_q0) q0 - внутренний параметр
	{ 966	,1	,1	, &internal1_m2136_q0},	//(internal1_m2136_q0) q0 - внутренний параметр
	{ 967	,1	,1	, &internal1_m2134_q0},	//(internal1_m2134_q0) q0 - внутренний параметр
	{ 968	,1	,1	, &internal1_m2142_q0},	//(internal1_m2142_q0) q0 - внутренний параметр
	{ 969	,1	,1	, &internal1_m2138_q0},	//(internal1_m2138_q0) q0 - внутренний параметр
	{ 970	,1	,1	, &internal1_m2178_q0},	//(internal1_m2178_q0) q0 - внутренний параметр
	{ 971	,1	,1	, &internal1_m2159_q0},	//(internal1_m2159_q0) q0 - внутренний параметр
	{ 972	,1	,1	, &internal1_m2176_q0},	//(internal1_m2176_q0) q0 - внутренний параметр
	{ 973	,1	,1	, &internal1_m2158_q0},	//(internal1_m2158_q0) q0 - внутренний параметр
	{ 974	,1	,1	, &internal1_m2155_q0},	//(internal1_m2155_q0) q0 - внутренний параметр
	{ 975	,1	,1	, &internal1_m2154_q0},	//(internal1_m2154_q0) q0 - внутренний параметр
	{ 976	,1	,1	, &internal1_m2168_q0},	//(internal1_m2168_q0) q0 - внутренний параметр
	{ 977	,1	,1	, &internal1_m2166_q0},	//(internal1_m2166_q0) q0 - внутренний параметр
	{ 978	,8	,1	, &internal1_m2043_tx},	//(internal1_m2043_tx) tx - внутренний параметр
	{ 979	,8	,1	, &internal1_m2022_tx},	//(internal1_m2022_tx) tx - внутренний параметр
	{ 980	,1	,1	, &internal1_m1729_Pv0},	//(internal1_m1729_Pv0)  - Пер. выключатель механизма
	{ 981	,1	,1	, &internal1_m1729_Zv0},	//(internal1_m1729_Zv0)  - Зад. выключатель механизма
	{ 982	,1	,1	, &internal1_m1729_MyFirstEnterFlag},	//(internal1_m1729_MyFirstEnterFlag) MyFirstEnterFlag
	{ 983	,1	,1	, &internal1_m1728_Pv0},	//(internal1_m1728_Pv0)  - Пер. выключатель механизма
	{ 984	,1	,1	, &internal1_m1728_Zv0},	//(internal1_m1728_Zv0)  - Зад. выключатель механизма
	{ 985	,1	,1	, &internal1_m1728_MyFirstEnterFlag},	//(internal1_m1728_MyFirstEnterFlag) MyFirstEnterFlag
	{ 986	,8	,1	, &internal1_m2198_tx},	//(internal1_m2198_tx) tx - время накопленное сек
	{ 987	,18	,1	, &internal1_m2198_y0},	//(internal1_m2198_y0) y0
	{ 988	,8	,1	, &internal1_m2201_tx},	//(internal1_m2201_tx) tx - время накопленное сек
	{ 989	,18	,1	, &internal1_m2201_y0},	//(internal1_m2201_y0) y0
	{ 990	,8	,1	, &internal1_m2200_tx},	//(internal1_m2200_tx) tx - время накопленное сек
	{ 991	,18	,1	, &internal1_m2200_y0},	//(internal1_m2200_y0) y0
	{ 992	,8	,1	, &internal1_m2237_tx},	//(internal1_m2237_tx) tx - внутренний параметр
	{ 993	,8	,1	, &internal1_m2235_tx},	//(internal1_m2235_tx) tx - время накопленное сек
	{ 994	,18	,1	, &internal1_m2235_y0},	//(internal1_m2235_y0) y0
	{ 995	,1	,1	, &internal1_m2240_q0},	//(internal1_m2240_q0) q0 - внутренний параметр
	{ 996	,1	,1	, &internal1_m2207_q0},	//(internal1_m2207_q0) q0 - внутренний параметр
	{ 997	,8	,1	, &internal1_m2215_tx},	//(internal1_m2215_tx) tx - внутренний параметр
	{ 998	,1	,1	, &internal1_m2213_q0},	//(internal1_m2213_q0) q0 - внутренний параметр
	{ 999	,8	,1	, &internal1_m2037_tx},	//(internal1_m2037_tx) tx - время накопленное сек
	{ 1000	,18	,1	, &internal1_m2037_y0},	//(internal1_m2037_y0) y0
	{ 1001	,8	,1	, &internal1_m2029_tx},	//(internal1_m2029_tx) tx - время накопленное сек
	{ 1002	,18	,1	, &internal1_m2029_y0},	//(internal1_m2029_y0) y0
	{ 1003	,1	,1	, &internal1_m1717_q0},	//(internal1_m1717_q0) q0 - внутренний параметр
	{ 1004	,1	,1	, &internal1_m1722_q0},	//(internal1_m1722_q0) q0 - внутренний параметр
	{ 1005	,1	,1	, &internal1_m1714_q0},	//(internal1_m1714_q0) q0 - внутренний параметр
	{ 1006	,1	,1	, &internal1_m1756_q0},	//(internal1_m1756_q0) q0 - внутренний параметр
	{ 1007	,8	,1	, &internal1_m756_tx},	//(internal1_m756_tx) tx - время накопленное сек
	{ 1008	,18	,1	, &internal1_m756_y0},	//(internal1_m756_y0) y0
	{ 1009	,8	,1	, &internal1_m2033_tx},	//(internal1_m2033_tx) tx - внутренний параметр
	{ 1010	,1	,1	, &internal1_m2036_q0},	//(internal1_m2036_q0) q0 - внутренний параметр
	{ 1011	,1	,1	, &internal1_m2028_q0},	//(internal1_m2028_q0) q0 - внутренний параметр
	{ 1012	,8	,1	, &internal1_m1998_tx},	//(internal1_m1998_tx) tx - внутренний параметр
	{ 1013	,8	,1	, &internal1_m2009_tx},	//(internal1_m2009_tx) tx - внутренний параметр
	{ 1014	,8	,1	, &internal1_m1995_tx},	//(internal1_m1995_tx) tx - внутренний параметр
	{ 1015	,1	,1	, &internal1_m2001_q0},	//(internal1_m2001_q0) q0 - внутренний параметр
	{ 1016	,1	,1	, &internal1_m2013_q0},	//(internal1_m2013_q0) q0 - внутренний параметр
	{ 1017	,8	,1	, &internal1_m1971_tx},	//(internal1_m1971_tx) tx - внутренний параметр
	{ 1018	,8	,1	, &internal1_m57_tx},	//(internal1_m57_tx) tx - внутренний параметр
	{ 1019	,8	,1	, &internal1_m353_tx},	//(internal1_m353_tx) tx - внутренний параметр
	{ 1020	,8	,1	, &internal1_m307_tx},	//(internal1_m307_tx) tx - внутренний параметр
	{ 1021	,8	,1	, &internal1_m757_tx},	//(internal1_m757_tx) tx - внутренний параметр
	{ 1022	,8	,1	, &internal1_m1437_tx},	//(internal1_m1437_tx) tx - внутренний параметр
	{ 1023	,8	,1	, &internal1_m119_tx},	//(internal1_m119_tx) tx - внутренний параметр
	{ 1024	,8	,1	, &internal1_m121_tx},	//(internal1_m121_tx) tx - внутренний параметр
	{ 1025	,8	,1	, &internal1_m126_tx},	//(internal1_m126_tx) tx - внутренний параметр
	{ 1026	,8	,1	, &internal1_m24_tx},	//(internal1_m24_tx) tx - внутренний параметр
	{ 1027	,8	,1	, &internal1_m16_tx},	//(internal1_m16_tx) tx - внутренний параметр
	{ 1028	,8	,1	, &internal1_m1980_tx},	//(internal1_m1980_tx) tx - внутренний параметр
	{ 1029	,8	,1	, &internal1_m1968_tx},	//(internal1_m1968_tx) tx - внутренний параметр
	{ 1030	,8	,1	, &internal1_m2076_tx},	//(internal1_m2076_tx) tx - внутренний параметр
	{ 1031	,8	,1	, &internal1_m2080_tx},	//(internal1_m2080_tx) tx - внутренний параметр
	{ 1032	,8	,1	, &internal1_m1893_tx},	//(internal1_m1893_tx) tx - внутренний параметр
	{ 1033	,8	,1	, &internal1_m83_tx},	//(internal1_m83_tx) tx - внутренний параметр
	{ 1034	,8	,1	, &internal1_m322_tx},	//(internal1_m322_tx) tx - время накопленное сек
	{ 1035	,18	,1	, &internal1_m322_y0},	//(internal1_m322_y0) y0
	{ 1036	,8	,1	, &internal1_m1887_tx},	//(internal1_m1887_tx) tx - время накопленное сек
	{ 1037	,18	,1	, &internal1_m1887_y0},	//(internal1_m1887_y0) y0
	{ 1038	,8	,1	, &internal1_m1885_tx},	//(internal1_m1885_tx) tx - время накопленное сек
	{ 1039	,18	,1	, &internal1_m1885_y0},	//(internal1_m1885_y0) y0
	{ 1040	,8	,1	, &internal1_m1874_tx},	//(internal1_m1874_tx) tx - время накопленное сек
	{ 1041	,18	,1	, &internal1_m1874_y0},	//(internal1_m1874_y0) y0
	{ 1042	,8	,1	, &internal1_m1894_q0},	//(internal1_m1894_q0) q0 - внутренний параметр
	{ 1043	,8	,1	, &internal1_m1457_q0},	//(internal1_m1457_q0) q0 - внутренний параметр
	{ 1044	,8	,1	, &internal1_m1496_q0},	//(internal1_m1496_q0) q0 - внутренний параметр
	{ 1045	,8	,1	, &internal1_m1494_q0},	//(internal1_m1494_q0) q0 - внутренний параметр
	{ 1046	,8	,1	, &internal1_m1933_q0},	//(internal1_m1933_q0) q0 - внутренний параметр
	{ 1047	,8	,1	, &internal1_m1911_tx},	//(internal1_m1911_tx) tx - время накопленное сек
	{ 1048	,18	,1	, &internal1_m1911_y0},	//(internal1_m1911_y0) y0
	{ 1049	,8	,1	, &internal1_m1926_tx},	//(internal1_m1926_tx) tx - время накопленное сек
	{ 1050	,18	,1	, &internal1_m1926_y0},	//(internal1_m1926_y0) y0
	{ 1051	,8	,1	, &internal1_m1923_tx},	//(internal1_m1923_tx) tx - время накопленное сек
	{ 1052	,18	,1	, &internal1_m1923_y0},	//(internal1_m1923_y0) y0
	{ 1053	,8	,1	, &internal1_m2060_tx},	//(internal1_m2060_tx) tx - время накопленное сек
	{ 1054	,18	,1	, &internal1_m2060_y0},	//(internal1_m2060_y0) y0
	{ 1055	,8	,1	, &internal1_m2070_tx},	//(internal1_m2070_tx) tx - время накопленное сек
	{ 1056	,18	,1	, &internal1_m2070_y0},	//(internal1_m2070_y0) y0
	{ 1057	,8	,1	, &internal1_m1824_tx},	//(internal1_m1824_tx) tx - время накопленное сек
	{ 1058	,18	,1	, &internal1_m1824_y0},	//(internal1_m1824_y0) y0
	{ 1059	,8	,1	, &internal1_m1823_tx},	//(internal1_m1823_tx) tx - время накопленное сек
	{ 1060	,18	,1	, &internal1_m1823_y0},	//(internal1_m1823_y0) y0
	{ 1061	,8	,1	, &internal1_m1822_tx},	//(internal1_m1822_tx) tx - время накопленное сек
	{ 1062	,18	,1	, &internal1_m1822_y0},	//(internal1_m1822_y0) y0
	{ 1063	,8	,1	, &internal1_m1821_tx},	//(internal1_m1821_tx) tx - время накопленное сек
	{ 1064	,18	,1	, &internal1_m1821_y0},	//(internal1_m1821_y0) y0
	{ 1065	,8	,1	, &internal1_m1509_tx},	//(internal1_m1509_tx) tx - время накопленное сек
	{ 1066	,18	,1	, &internal1_m1509_y0},	//(internal1_m1509_y0) y0
	{ 1067	,8	,1	, &internal1_m1503_tx},	//(internal1_m1503_tx) tx - время накопленное сек
	{ 1068	,18	,1	, &internal1_m1503_y0},	//(internal1_m1503_y0) y0
	{ 1069	,8	,1	, &internal1_m1453_tx},	//(internal1_m1453_tx) tx - время накопленное сек
	{ 1070	,18	,1	, &internal1_m1453_y0},	//(internal1_m1453_y0) y0
	{ 1071	,8	,1	, &internal1_m838_tx},	//(internal1_m838_tx) tx - время накопленное сек
	{ 1072	,18	,1	, &internal1_m838_y0},	//(internal1_m838_y0) y0
	{ 1073	,8	,1	, &internal1_m837_tx},	//(internal1_m837_tx) tx - время накопленное сек
	{ 1074	,18	,1	, &internal1_m837_y0},	//(internal1_m837_y0) y0
	{ 1075	,8	,1	, &internal1_m844_tx},	//(internal1_m844_tx) tx - время накопленное сек
	{ 1076	,18	,1	, &internal1_m844_y0},	//(internal1_m844_y0) y0
	{ 1077	,8	,1	, &internal1_m203_tx},	//(internal1_m203_tx) tx - время накопленное сек
	{ 1078	,18	,1	, &internal1_m203_y0},	//(internal1_m203_y0) y0
	{ 1079	,8	,1	, &internal1_m207_tx},	//(internal1_m207_tx) tx - время накопленное сек
	{ 1080	,18	,1	, &internal1_m207_y0},	//(internal1_m207_y0) y0
	{ 1081	,8	,1	, &internal1_m214_tx},	//(internal1_m214_tx) tx - время накопленное сек
	{ 1082	,18	,1	, &internal1_m214_y0},	//(internal1_m214_y0) y0
	{ 1083	,8	,1	, &internal1_m533_tx},	//(internal1_m533_tx) tx - время накопленное сек
	{ 1084	,18	,1	, &internal1_m533_y0},	//(internal1_m533_y0) y0
	{ 1085	,8	,1	, &internal1_m2108_tx},	//(internal1_m2108_tx) tx - внутренний параметр
	{ 1086	,8	,1	, &internal1_m1198_tx},	//(internal1_m1198_tx) tx - внутренний параметр
	{ 1087	,8	,1	, &internal1_m1623_tx},	//(internal1_m1623_tx) tx - время накопленное сек
	{ 1088	,18	,1	, &internal1_m1623_y0},	//(internal1_m1623_y0) y0
	{ 1089	,8	,1	, &internal1_m1148_tx},	//(internal1_m1148_tx) tx - время накопленное сек
	{ 1090	,18	,1	, &internal1_m1148_y0},	//(internal1_m1148_y0) y0
	{ 1091	,8	,1	, &internal1_m1349_tx},	//(internal1_m1349_tx) tx - время накопленное сек
	{ 1092	,18	,1	, &internal1_m1349_y0},	//(internal1_m1349_y0) y0
	{ 1093	,8	,1	, &internal1_m937_tx},	//(internal1_m937_tx) tx - время накопленное сек
	{ 1094	,18	,1	, &internal1_m937_y0},	//(internal1_m937_y0) y0
	{ 1095	,8	,1	, &internal1_m1258_tx},	//(internal1_m1258_tx) tx - время накопленное сек
	{ 1096	,18	,1	, &internal1_m1258_y0},	//(internal1_m1258_y0) y0
	{ 1097	,1	,1	, &internal1_m1089_q0},	//(internal1_m1089_q0) q0 - внутренний параметр
	{ 1098	,1	,1	, &internal1_m1087_q0},	//(internal1_m1087_q0) q0 - внутренний параметр
	{ 1099	,1	,1	, &internal1_m1086_q0},	//(internal1_m1086_q0) q0 - внутренний параметр
	{ 1100	,1	,1	, &internal1_m1084_q0},	//(internal1_m1084_q0) q0 - внутренний параметр
	{ 1101	,1	,1	, &internal1_m1083_q0},	//(internal1_m1083_q0) q0 - внутренний параметр
	{ 1102	,1	,1	, &internal1_m1081_q0},	//(internal1_m1081_q0) q0 - внутренний параметр
	{ 1103	,1	,1	, &internal1_m1080_q0},	//(internal1_m1080_q0) q0 - внутренний параметр
	{ 1104	,1	,1	, &internal1_m1078_q0},	//(internal1_m1078_q0) q0 - внутренний параметр
	{ 1105	,1	,1	, &internal1_m1077_q0},	//(internal1_m1077_q0) q0 - внутренний параметр
	{ 1106	,1	,1	, &internal1_m58_x0},	//(internal1_m58_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1107	,1	,1	, &internal1_m997_q0},	//(internal1_m997_q0) q0 - внутренний параметр
	{ 1108	,1	,1	, &internal1_m1446_x0},	//(internal1_m1446_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1109	,1	,1	, &internal1_m1490_x0},	//(internal1_m1490_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1110	,1	,1	, &internal1_m1486_x0},	//(internal1_m1486_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1111	,1	,1	, &internal1_m1902_x0},	//(internal1_m1902_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1112	,1	,1	, &internal1_m1867_x0},	//(internal1_m1867_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1113	,1	,1	, &internal1_m1036_q0},	//(internal1_m1036_q0) q0 - внутренний параметр
	{ 1114	,1	,1	, &internal1_m1048_q0},	//(internal1_m1048_q0) q0 - внутренний параметр
	{ 1115	,1	,1	, &internal1_m1060_q0},	//(internal1_m1060_q0) q0 - внутренний параметр
	{ 1116	,1	,1	, &internal1_m1070_q0},	//(internal1_m1070_q0) q0 - внутренний параметр
	{ 1117	,1	,1	, &internal1_m1047_q0},	//(internal1_m1047_q0) q0 - внутренний параметр
	{ 1118	,1	,1	, &internal1_m1062_q0},	//(internal1_m1062_q0) q0 - внутренний параметр
	{ 1119	,1	,1	, &internal1_m1960_q0},	//(internal1_m1960_q0) q0 - внутренний параметр
	{ 1120	,1	,1	, &internal1_m1959_q0},	//(internal1_m1959_q0) q0 - внутренний параметр
	{ 1121	,3	,1	, &internal1_m341_Step},	//(internal1_m341_Step)  - текущий шаг программы
	{ 1122	,18	,10	, &internal1_m341_rz},	//(internal1_m341_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1123	,8	,1	, &internal1_m341_TimS},	//(internal1_m341_TimS) Время от старта программы
	{ 1124	,1	,1	, &internal1_m341_FinPr0},	//(internal1_m341_FinPr0) FinPr - конец программы
	{ 1125	,1	,1	, &internal1_m341_ErrPr0},	//(internal1_m341_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1126	,1	,1	, &internal1_m341_sbINI0},	//(internal1_m341_sbINI0) sbINI - запуск проверки ИНИ
	{ 1127	,1	,1	, &internal1_m341_sbVuIS0},	//(internal1_m341_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1128	,1	,1	, &internal1_m341_sb2UR0},	//(internal1_m341_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1129	,1	,1	, &internal1_m341_sbNupIS0},	//(internal1_m341_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1130	,1	,1	, &internal1_m341_sbVuRB0},	//(internal1_m341_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1131	,1	,1	, &internal1_m341_MyFirstEnterFlag},	//(internal1_m341_MyFirstEnterFlag)  
	{ 1132	,5	,1	, &internal1_m349_x0},	//(internal1_m349_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1133	,5	,1	, &internal1_m309_TimS},	//(internal1_m309_TimS) Время старта
	{ 1134	,3	,1	, &internal1_m284_Step},	//(internal1_m284_Step)  - текущий шаг программы
	{ 1135	,18	,10	, &internal1_m284_rz},	//(internal1_m284_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1136	,8	,1	, &internal1_m284_TimS},	//(internal1_m284_TimS) Время от старта программы
	{ 1137	,1	,1	, &internal1_m284_FinPr0},	//(internal1_m284_FinPr0) FinPr - конец программы
	{ 1138	,1	,1	, &internal1_m284_ErrPr0},	//(internal1_m284_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1139	,1	,1	, &internal1_m284_sbINI0},	//(internal1_m284_sbINI0) sbINI - запуск проверки ИНИ
	{ 1140	,1	,1	, &internal1_m284_sbVuIS0},	//(internal1_m284_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1141	,1	,1	, &internal1_m284_sb2UR0},	//(internal1_m284_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1142	,1	,1	, &internal1_m284_sbNupIS0},	//(internal1_m284_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1143	,1	,1	, &internal1_m284_sbVuRB0},	//(internal1_m284_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1144	,1	,1	, &internal1_m284_MyFirstEnterFlag},	//(internal1_m284_MyFirstEnterFlag)  
	{ 1145	,1	,1	, &internal1_m1420_q0},	//(internal1_m1420_q0) q0 - внутренний параметр
	{ 1146	,3	,1	, &internal1_m1421_Step},	//(internal1_m1421_Step)  - текущий шаг программы
	{ 1147	,18	,6	, &internal1_m1421_rz},	//(internal1_m1421_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1148	,8	,1	, &internal1_m1421_TimS},	//(internal1_m1421_TimS) Время от старта программы
	{ 1149	,1	,1	, &internal1_m1421_FinPr0},	//(internal1_m1421_FinPr0) FinPr - конец программы
	{ 1150	,1	,1	, &internal1_m1421_ErrPr0},	//(internal1_m1421_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1151	,1	,1	, &internal1_m1421_sbINI0},	//(internal1_m1421_sbINI0) sbINI - запуск проверки ИНИ
	{ 1152	,1	,1	, &internal1_m1421_sbVuIS0},	//(internal1_m1421_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1153	,1	,1	, &internal1_m1421_sb2UR0},	//(internal1_m1421_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1154	,1	,1	, &internal1_m1421_sbNupIS0},	//(internal1_m1421_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1155	,1	,1	, &internal1_m1421_sbVuRB0},	//(internal1_m1421_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1156	,1	,1	, &internal1_m1421_MyFirstEnterFlag},	//(internal1_m1421_MyFirstEnterFlag)  
	{ 1157	,1	,1	, &internal1_m1032_q0},	//(internal1_m1032_q0) q0 - внутренний параметр
	{ 1158	,1	,1	, &internal1_m1029_q0},	//(internal1_m1029_q0) q0 - внутренний параметр
	{ 1159	,1	,1	, &internal1_m1031_q0},	//(internal1_m1031_q0) q0 - внутренний параметр
	{ 1160	,1	,1	, &internal1_m1025_q0},	//(internal1_m1025_q0) q0 - внутренний параметр
	{ 1161	,1	,1	, &internal1_m758_q0},	//(internal1_m758_q0) q0 - внутренний параметр
	{ 1162	,1	,1	, &internal1_m351_q0},	//(internal1_m351_q0) q0 - внутренний параметр
	{ 1163	,1	,1	, &internal1_m347_q0},	//(internal1_m347_q0) q0 - внутренний параметр
	{ 1164	,1	,1	, &internal1_m304_q0},	//(internal1_m304_q0) q0 - внутренний параметр
	{ 1165	,5	,1	, &internal1_m303_x0},	//(internal1_m303_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1166	,1	,1	, &internal1_m1889_q0},	//(internal1_m1889_q0) q0 - внутренний параметр
	{ 1167	,1	,1	, &internal1_m1877_q0},	//(internal1_m1877_q0) q0 - внутренний параметр
	{ 1168	,1	,1	, &internal1_m1868_q0},	//(internal1_m1868_q0) q0 - внутренний параметр
	{ 1169	,1	,1	, &internal1_m1943_q0},	//(internal1_m1943_q0) q0 - внутренний параметр
	{ 1170	,1	,1	, &internal1_m1914_q0},	//(internal1_m1914_q0) q0 - внутренний параметр
	{ 1171	,1	,1	, &internal1_m1903_q0},	//(internal1_m1903_q0) q0 - внутренний параметр
	{ 1172	,1	,1	, &internal1_m1473_q0},	//(internal1_m1473_q0) q0 - внутренний параметр
	{ 1173	,1	,1	, &internal1_m1460_x0},	//(internal1_m1460_x0) был приход сигнала x1
	{ 1174	,8	,1	, &internal1_m1460_y0},	//(internal1_m1460_y0) интервал между сигналами х1 и х2
	{ 1175	,1	,1	, &internal1_m1456_q0},	//(internal1_m1456_q0) q0 - внутренний параметр
	{ 1176	,1	,1	, &internal1_m1447_q0},	//(internal1_m1447_q0) q0 - внутренний параметр
	{ 1177	,1	,1	, &internal1_m1506_q0},	//(internal1_m1506_q0) q0 - внутренний параметр
	{ 1178	,1	,1	, &internal1_m1526_q0},	//(internal1_m1526_q0) q0 - внутренний параметр
	{ 1179	,1	,1	, &internal1_m1492_q0},	//(internal1_m1492_q0) q0 - внутренний параметр
	{ 1180	,1	,1	, &internal1_m1507_x0},	//(internal1_m1507_x0) был приход сигнала x1
	{ 1181	,8	,1	, &internal1_m1507_y0},	//(internal1_m1507_y0) интервал между сигналами х1 и х2
	{ 1182	,5	,1	, &internal1_m1431_x0},	//(internal1_m1431_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1183	,1	,1	, &internal1_m1512_q0},	//(internal1_m1512_q0) q0 - внутренний параметр
	{ 1184	,1	,1	, &internal1_m29_q0},	//(internal1_m29_q0) q0 - внутренний параметр
	{ 1185	,1	,1	, &internal1_m1527_q0},	//(internal1_m1527_q0) q0 - внутренний параметр
	{ 1186	,1	,1	, &internal1_m648_q0},	//(internal1_m648_q0) q0 - внутренний параметр
	{ 1187	,1	,1	, &internal1_m633_q0},	//(internal1_m633_q0) q0 - внутренний параметр
	{ 1188	,1	,1	, &internal1_m661_q0},	//(internal1_m661_q0) q0 - внутренний параметр
	{ 1189	,1	,1	, &internal1_m644_q0},	//(internal1_m644_q0) q0 - внутренний параметр
	{ 1190	,1	,1	, &internal1_m628_q0},	//(internal1_m628_q0) q0 - внутренний параметр
	{ 1191	,1	,1	, &internal1_m626_q0},	//(internal1_m626_q0) q0 - внутренний параметр
	{ 1192	,1	,1	, &internal1_m614_q0},	//(internal1_m614_q0) q0 - внутренний параметр
	{ 1193	,5	,1	, &internal1_m1423_q0},	//(internal1_m1423_q0) q0 - внутренний параметр
	{ 1194	,1	,1	, &internal1_m624_q0},	//(internal1_m624_q0) q0 - внутренний параметр
	{ 1195	,1	,1	, &internal1_m115_q0},	//(internal1_m115_q0) q0 - внутренний параметр
	{ 1196	,1	,1	, &internal1_m1659_q0},	//(internal1_m1659_q0) q0 - внутренний параметр
	{ 1197	,1	,1	, &internal1_m1658_q0},	//(internal1_m1658_q0) q0 - внутренний параметр
	{ 1198	,1	,1	, &internal1_m1657_q0},	//(internal1_m1657_q0) q0 - внутренний параметр
	{ 1199	,1	,1	, &internal1_m1656_q0},	//(internal1_m1656_q0) q0 - внутренний параметр
	{ 1200	,1	,1	, &internal1_m1694_q0},	//(internal1_m1694_q0) q0 - внутренний параметр
	{ 1201	,1	,1	, &internal1_m1693_q0},	//(internal1_m1693_q0) q0 - внутренний параметр
	{ 1202	,1	,1	, &internal1_m1692_q0},	//(internal1_m1692_q0) q0 - внутренний параметр
	{ 1203	,1	,1	, &internal1_m1974_q0},	//(internal1_m1974_q0) q0 - внутренний параметр
	{ 1204	,1	,1	, &internal1_m1754_q0},	//(internal1_m1754_q0) q0 - внутренний параметр
	{ 1205	,1	,1	, &internal1_m1743_q0},	//(internal1_m1743_q0) q0 - внутренний параметр
	{ 1206	,1	,1	, &internal1_m1751_q0},	//(internal1_m1751_q0) q0 - внутренний параметр
	{ 1207	,1	,1	, &internal1_m1740_q0},	//(internal1_m1740_q0) q0 - внутренний параметр
	{ 1208	,1	,1	, &internal1_m1748_q0},	//(internal1_m1748_q0) q0 - внутренний параметр
	{ 1209	,1	,1	, &internal1_m2174_q0},	//(internal1_m2174_q0) q0 - внутренний параметр
	{ 1210	,1	,1	, &internal1_m2170_q0},	//(internal1_m2170_q0) q0 - внутренний параметр
	{ 1211	,1	,1	, &internal1_m1719_q0},	//(internal1_m1719_q0) q0 - внутренний параметр
	{ 1212	,1	,1	, &internal1_m1711_q0},	//(internal1_m1711_q0) q0 - внутренний параметр
	{ 1213	,1	,1	, &internal1_m1709_q0},	//(internal1_m1709_q0) q0 - внутренний параметр
	{ 1214	,1	,1	, &internal1_m1705_q0},	//(internal1_m1705_q0) q0 - внутренний параметр
	{ 1215	,1	,1	, &internal1_m1701_q0},	//(internal1_m1701_q0) q0 - внутренний параметр
	{ 1216	,1	,1	, &internal1_m1703_q0},	//(internal1_m1703_q0) q0 - внутренний параметр
	{ 1217	,1	,1	, &internal1_m22_q0},	//(internal1_m22_q0) q0 - внутренний параметр
	{ 1218	,1	,1	, &internal1_m1682_q0},	//(internal1_m1682_q0) q0 - внутренний параметр
	{ 1219	,1	,1	, &internal1_m1680_q0},	//(internal1_m1680_q0) q0 - внутренний параметр
	{ 1220	,1	,1	, &internal1_m1676_q0},	//(internal1_m1676_q0) q0 - внутренний параметр
	{ 1221	,1	,1	, &internal1_m1678_q0},	//(internal1_m1678_q0) q0 - внутренний параметр
	{ 1222	,1	,1	, &internal1_m1674_q0},	//(internal1_m1674_q0) q0 - внутренний параметр
	{ 1223	,1	,1	, &internal1_m1672_q0},	//(internal1_m1672_q0) q0 - внутренний параметр
	{ 1224	,1	,1	, &internal1_m2090_q0},	//(internal1_m2090_q0) q0 - внутренний параметр
	{ 1225	,1	,1	, &internal1_m2085_q0},	//(internal1_m2085_q0) q0 - внутренний параметр
	{ 1226	,1	,1	, &internal1_m2064_q0},	//(internal1_m2064_q0) q0 - внутренний параметр
	{ 1227	,1	,1	, &internal1_m2052_q0},	//(internal1_m2052_q0) q0 - внутренний параметр
	{ 1228	,1	,1	, &internal1_m1985_q0},	//(internal1_m1985_q0) q0 - внутренний параметр
	{ 1229	,1	,1	, &internal1_m1668_q0},	//(internal1_m1668_q0) q0 - внутренний параметр
	{ 1230	,1	,1	, &internal1_m1670_q0},	//(internal1_m1670_q0) q0 - внутренний параметр
	{ 1231	,1	,1	, &internal1_m1654_q0},	//(internal1_m1654_q0) q0 - внутренний параметр
	{ 1232	,1	,1	, &internal1_m1652_q0},	//(internal1_m1652_q0) q0 - внутренний параметр
	{ 1233	,1	,1	, &internal1_m1650_q0},	//(internal1_m1650_q0) q0 - внутренний параметр
	{ 1234	,1	,1	, &internal1_m1648_q0},	//(internal1_m1648_q0) q0 - внутренний параметр
	{ 1235	,1	,1	, &internal1_m1647_q0},	//(internal1_m1647_q0) q0 - внутренний параметр
	{ 1236	,1	,1	, &internal1_m1645_q0},	//(internal1_m1645_q0) q0 - внутренний параметр
	{ 1237	,1	,1	, &internal1_m1644_q0},	//(internal1_m1644_q0) q0 - внутренний параметр
	{ 1238	,1	,1	, &internal1_m1642_q0},	//(internal1_m1642_q0) q0 - внутренний параметр
	{ 1239	,18	,1	, &internal1_m2113_DvUp0},	//(internal1_m2113_DvUp0) - есть команда на движение вперёд
	{ 1240	,18	,1	, &internal1_m2113_DvDw0},	//(internal1_m2113_DvDw0) - есть команда на движение назад
	{ 1241	,18	,1	, &internal1_m2113_FDvUp0},	//(internal1_m2113_FDvUp0) - есть команда на движение вперёд
	{ 1242	,18	,1	, &internal1_m2113_FDvDw0},	//(internal1_m2113_FDvDw0) - есть команда на движение назад
	{ 1243	,18	,1	, &internal1_m2113_BlDv0},	//(internal1_m2113_BlDv0) - была блокировка
	{ 1244	,18	,1	, &internal1_m2113_Pkv0},	//(internal1_m2113_Pkv0) Pkv - передний конечный выключатель
	{ 1245	,18	,1	, &internal1_m2113_Pkav0},	//(internal1_m2113_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1246	,18	,1	, &internal1_m2113_Zkv0},	//(internal1_m2113_Zkv0) Zkv - задний конечный выключатель
	{ 1247	,18	,1	, &internal1_m2113_Zkav0},	//(internal1_m2113_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1248	,8	,1	, &internal1_m2113_txNm},	//(internal1_m2113_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1249	,8	,1	, &internal1_m2113_txSm},	//(internal1_m2113_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1250	,8	,1	, &internal1_m2113_txHr},	//(internal1_m2113_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1251	,8	,1	, &internal1_m2113_txLd},	//(internal1_m2113_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1252	,18	,1	, &internal1_m2113_fef},	//(internal1_m2113_fef) fef
	{ 1253	,18	,1	, &internal1_m2107_DvUp0},	//(internal1_m2107_DvUp0) - есть команда на движение вперёд
	{ 1254	,18	,1	, &internal1_m2107_DvDw0},	//(internal1_m2107_DvDw0) - есть команда на движение назад
	{ 1255	,18	,1	, &internal1_m2107_FDvUp0},	//(internal1_m2107_FDvUp0) - есть команда на движение вперёд
	{ 1256	,18	,1	, &internal1_m2107_FDvDw0},	//(internal1_m2107_FDvDw0) - есть команда на движение назад
	{ 1257	,18	,1	, &internal1_m2107_BlDv0},	//(internal1_m2107_BlDv0) - была блокировка
	{ 1258	,18	,1	, &internal1_m2107_Pkv0},	//(internal1_m2107_Pkv0) Pkv - передний конечный выключатель
	{ 1259	,18	,1	, &internal1_m2107_Pkav0},	//(internal1_m2107_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1260	,18	,1	, &internal1_m2107_Zkv0},	//(internal1_m2107_Zkv0) Zkv - задний конечный выключатель
	{ 1261	,18	,1	, &internal1_m2107_Zkav0},	//(internal1_m2107_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1262	,8	,1	, &internal1_m2107_txNm},	//(internal1_m2107_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1263	,8	,1	, &internal1_m2107_txSm},	//(internal1_m2107_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1264	,8	,1	, &internal1_m2107_txHr},	//(internal1_m2107_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1265	,8	,1	, &internal1_m2107_txLd},	//(internal1_m2107_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1266	,18	,1	, &internal1_m2107_fef},	//(internal1_m2107_fef) fef
	{ 1267	,1	,1	, &internal1_m1498_q0},	//(internal1_m1498_q0) q0 - внутренний параметр
	{ 1268	,1	,1	, &internal1_m1501_x0},	//(internal1_m1501_x0) был приход сигнала x1
	{ 1269	,8	,1	, &internal1_m1501_y0},	//(internal1_m1501_y0) интервал между сигналами х1 и х2
	{ 1270	,1	,1	, &internal1_m1925_x0},	//(internal1_m1925_x0) был приход сигнала x1
	{ 1271	,8	,1	, &internal1_m1925_y0},	//(internal1_m1925_y0) интервал между сигналами х1 и х2
	{ 1272	,1	,1	, &internal1_m1886_x0},	//(internal1_m1886_x0) был приход сигнала x1
	{ 1273	,8	,1	, &internal1_m1886_y0},	//(internal1_m1886_y0) интервал между сигналами х1 и х2
	{ 1274	,1	,1	, &internal1_m295_q0},	//(internal1_m295_q0) q0 - внутренний параметр
	{ 1275	,1	,1	, &internal1_m1005_q0},	//(internal1_m1005_q0) q0 - внутренний параметр
	{ 1276	,1	,1	, &internal1_m636_q0},	//(internal1_m636_q0) q0 - внутренний параметр
	{ 1277	,8	,1	, &internal1_m1320_X0},	//(internal1_m1320_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1278	,8	,1	, &internal1_m1320_t0},	//(internal1_m1320_t0) время нахождения в зоне возврата
	{ 1279	,18	,1	, &internal1_m1320_BLDv0},	//(internal1_m1320_BLDv0) BlDv - Блокировка движения
	{ 1280	,8	,1	, &internal1_m1339_tx},	//(internal1_m1339_tx) tx - время накопленное сек
	{ 1281	,18	,1	, &internal1_m1339_y0},	//(internal1_m1339_y0) y0
	{ 1282	,8	,1	, &internal1_m1341_tx},	//(internal1_m1341_tx) tx - время накопленное сек
	{ 1283	,18	,1	, &internal1_m1341_y0},	//(internal1_m1341_y0) y0
	{ 1284	,3	,1	, &internal1_m1348_xptr},	//(internal1_m1348_xptr) указатель текущей позиции в массиве координат
	{ 1285	,8	,60	, &internal1_m1348_x0},	//(internal1_m1348_x0) x0 - массив мгновенных значений координат
	{ 1286	,8	,60	, &internal1_m1348_tim0},	//(internal1_m1348_tim0) tim0 - массив значений времени цикла
	{ 1287	,8	,1	, &internal1_m1348_sumtim},	//(internal1_m1348_sumtim) sumtim - время в пути
	{ 1288	,8	,1	, &internal1_m1348_StSpeed},	//(internal1_m1348_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1289	,8	,1	, &internal1_m1348_Vz0},	//(internal1_m1348_Vz0) Vz0 - предыдущая заданная скорость
	{ 1290	,3	,1	, &internal1_m1348_flRazg},	//(internal1_m1348_flRazg) признак разгона/торможения
	{ 1291	,8	,1	, &internal1_m1348_DelSp},	//(internal1_m1348_DelSp) DelSp - время переключения скоростей
	{ 1292	,8	,1	, &internal1_m1348_z0},	//(internal1_m1348_z0) z0 - точка прекращения движения
	{ 1293	,8	,1	, &internal1_m1348_txZS},	//(internal1_m1348_txZS) txZS
	{ 1294	,8	,1	, &internal1_m1348_tx},	//(internal1_m1348_tx) tx
	{ 1295	,8	,1	, &internal1_m1348_txd},	//(internal1_m1348_txd) txd
	{ 1296	,8	,1	, &internal1_m1348_txMBl},	//(internal1_m1348_txMBl) tx
	{ 1297	,8	,1	, &internal1_m1348_txBl},	//(internal1_m1348_txBl) tx
	{ 1298	,8	,1	, &internal1_m1348_Speed0},	//(internal1_m1348_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1299	,8	,1	, &internal1_m1348_xz0},	//(internal1_m1348_xz0) xz0 - новое задание мм
	{ 1300	,8	,1	, &internal1_m1348_tz0},	//(internal1_m1348_tz0) tz0 - время защиты от нового задания сек
	{ 1301	,1	,1	, &internal1_m1348_Shift0},	//(internal1_m1348_Shift0) Shift0 - признак самохода
	{ 1302	,1	,1	, &internal1_m1348_ShCntlSp0},	//(internal1_m1348_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1303	,1	,1	, &internal1_m1348_ShiftControl},	//(internal1_m1348_ShiftControl) ShiftControl - признак самохода
	{ 1304	,1	,1	, &internal1_m634_q0},	//(internal1_m634_q0) q0 - внутренний параметр
	{ 1305	,8	,1	, &internal1_m903_X0},	//(internal1_m903_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1306	,8	,1	, &internal1_m903_t0},	//(internal1_m903_t0) время нахождения в зоне возврата
	{ 1307	,18	,1	, &internal1_m903_BLDv0},	//(internal1_m903_BLDv0) BlDv - Блокировка движения
	{ 1308	,8	,1	, &internal1_m927_tx},	//(internal1_m927_tx) tx - время накопленное сек
	{ 1309	,18	,1	, &internal1_m927_y0},	//(internal1_m927_y0) y0
	{ 1310	,8	,1	, &internal1_m930_tx},	//(internal1_m930_tx) tx - время накопленное сек
	{ 1311	,18	,1	, &internal1_m930_y0},	//(internal1_m930_y0) y0
	{ 1312	,3	,1	, &internal1_m936_xptr},	//(internal1_m936_xptr) указатель текущей позиции в массиве координат
	{ 1313	,8	,60	, &internal1_m936_x0},	//(internal1_m936_x0) x0 - массив мгновенных значений координат
	{ 1314	,8	,60	, &internal1_m936_tim0},	//(internal1_m936_tim0) tim0 - массив значений времени цикла
	{ 1315	,8	,1	, &internal1_m936_sumtim},	//(internal1_m936_sumtim) sumtim - время в пути
	{ 1316	,8	,1	, &internal1_m936_StSpeed},	//(internal1_m936_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1317	,8	,1	, &internal1_m936_Vz0},	//(internal1_m936_Vz0) Vz0 - предыдущая заданная скорость
	{ 1318	,3	,1	, &internal1_m936_flRazg},	//(internal1_m936_flRazg) признак разгона/торможения
	{ 1319	,8	,1	, &internal1_m936_DelSp},	//(internal1_m936_DelSp) DelSp - время переключения скоростей
	{ 1320	,8	,1	, &internal1_m936_z0},	//(internal1_m936_z0) z0 - точка прекращения движения
	{ 1321	,8	,1	, &internal1_m936_txZS},	//(internal1_m936_txZS) txZS
	{ 1322	,8	,1	, &internal1_m936_tx},	//(internal1_m936_tx) tx
	{ 1323	,8	,1	, &internal1_m936_txd},	//(internal1_m936_txd) txd
	{ 1324	,8	,1	, &internal1_m936_txMBl},	//(internal1_m936_txMBl) tx
	{ 1325	,8	,1	, &internal1_m936_txBl},	//(internal1_m936_txBl) tx
	{ 1326	,8	,1	, &internal1_m936_Speed0},	//(internal1_m936_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1327	,8	,1	, &internal1_m936_xz0},	//(internal1_m936_xz0) xz0 - новое задание мм
	{ 1328	,8	,1	, &internal1_m936_tz0},	//(internal1_m936_tz0) tz0 - время защиты от нового задания сек
	{ 1329	,1	,1	, &internal1_m936_Shift0},	//(internal1_m936_Shift0) Shift0 - признак самохода
	{ 1330	,1	,1	, &internal1_m936_ShCntlSp0},	//(internal1_m936_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1331	,1	,1	, &internal1_m936_ShiftControl},	//(internal1_m936_ShiftControl) ShiftControl - признак самохода
	{ 1332	,8	,1	, &internal1_m505_X0},	//(internal1_m505_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1333	,8	,1	, &internal1_m505_t0},	//(internal1_m505_t0) время нахождения в зоне возврата
	{ 1334	,18	,1	, &internal1_m505_BLDv0},	//(internal1_m505_BLDv0) BlDv - Блокировка движения
	{ 1335	,8	,1	, &internal1_m525_tx},	//(internal1_m525_tx) tx - время накопленное сек
	{ 1336	,18	,1	, &internal1_m525_y0},	//(internal1_m525_y0) y0
	{ 1337	,8	,1	, &internal1_m526_tx},	//(internal1_m526_tx) tx - время накопленное сек
	{ 1338	,18	,1	, &internal1_m526_y0},	//(internal1_m526_y0) y0
	{ 1339	,3	,1	, &internal1_m532_xptr},	//(internal1_m532_xptr) указатель текущей позиции в массиве координат
	{ 1340	,8	,150	, &internal1_m532_x0},	//(internal1_m532_x0) x0 - массив мгновенных значений координат
	{ 1341	,8	,150	, &internal1_m532_tim0},	//(internal1_m532_tim0) tim0 - массив значений времени цикла
	{ 1342	,8	,1	, &internal1_m532_sumtim},	//(internal1_m532_sumtim) sumtim - время в пути
	{ 1343	,8	,1	, &internal1_m532_StSpeed},	//(internal1_m532_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1344	,8	,1	, &internal1_m532_Vz0},	//(internal1_m532_Vz0) Vz0 - предыдущая заданная скорость
	{ 1345	,3	,1	, &internal1_m532_flRazg},	//(internal1_m532_flRazg) признак разгона/торможения
	{ 1346	,8	,1	, &internal1_m532_DelSp},	//(internal1_m532_DelSp) DelSp - время переключения скоростей
	{ 1347	,8	,1	, &internal1_m532_z0},	//(internal1_m532_z0) z0 - точка прекращения движения
	{ 1348	,8	,1	, &internal1_m532_txZS},	//(internal1_m532_txZS) txZS
	{ 1349	,8	,1	, &internal1_m532_tx},	//(internal1_m532_tx) tx
	{ 1350	,8	,1	, &internal1_m532_txd},	//(internal1_m532_txd) txd
	{ 1351	,8	,1	, &internal1_m532_txMBl},	//(internal1_m532_txMBl) tx
	{ 1352	,8	,1	, &internal1_m532_txBl},	//(internal1_m532_txBl) tx
	{ 1353	,8	,1	, &internal1_m532_Speed0},	//(internal1_m532_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1354	,8	,1	, &internal1_m532_xz0},	//(internal1_m532_xz0) xz0 - новое задание мм
	{ 1355	,8	,1	, &internal1_m532_tz0},	//(internal1_m532_tz0) tz0 - время защиты от нового задания сек
	{ 1356	,1	,1	, &internal1_m532_Shift0},	//(internal1_m532_Shift0) Shift0 - признак самохода
	{ 1357	,1	,1	, &internal1_m532_ShCntlSp0},	//(internal1_m532_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1358	,1	,1	, &internal1_m532_ShiftControl},	//(internal1_m532_ShiftControl) ShiftControl - признак самохода
	{ 1359	,1	,1	, &internal1_m631_q0},	//(internal1_m631_q0) q0 - внутренний параметр
	{ 1360	,8	,1	, &internal1_m174_X0},	//(internal1_m174_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1361	,8	,1	, &internal1_m174_t0},	//(internal1_m174_t0) время нахождения в зоне возврата
	{ 1362	,18	,1	, &internal1_m174_BLDv0},	//(internal1_m174_BLDv0) BlDv - Блокировка движения
	{ 1363	,3	,1	, &internal1_m213_xptr},	//(internal1_m213_xptr) указатель текущей позиции в массиве координат
	{ 1364	,8	,150	, &internal1_m213_x0},	//(internal1_m213_x0) x0 - массив мгновенных значений координат
	{ 1365	,8	,150	, &internal1_m213_tim0},	//(internal1_m213_tim0) tim0 - массив значений времени цикла
	{ 1366	,8	,1	, &internal1_m213_sumtim},	//(internal1_m213_sumtim) sumtim - время в пути
	{ 1367	,8	,1	, &internal1_m213_StSpeed},	//(internal1_m213_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1368	,8	,1	, &internal1_m213_Vz0},	//(internal1_m213_Vz0) Vz0 - предыдущая заданная скорость
	{ 1369	,3	,1	, &internal1_m213_flRazg},	//(internal1_m213_flRazg) признак разгона/торможения
	{ 1370	,8	,1	, &internal1_m213_DelSp},	//(internal1_m213_DelSp) DelSp - время переключения скоростей
	{ 1371	,8	,1	, &internal1_m213_z0},	//(internal1_m213_z0) z0 - точка прекращения движения
	{ 1372	,8	,1	, &internal1_m213_txZS},	//(internal1_m213_txZS) txZS
	{ 1373	,8	,1	, &internal1_m213_tx},	//(internal1_m213_tx) tx
	{ 1374	,8	,1	, &internal1_m213_txd},	//(internal1_m213_txd) txd
	{ 1375	,8	,1	, &internal1_m213_txMBl},	//(internal1_m213_txMBl) tx
	{ 1376	,8	,1	, &internal1_m213_txBl},	//(internal1_m213_txBl) tx
	{ 1377	,8	,1	, &internal1_m213_Speed0},	//(internal1_m213_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1378	,8	,1	, &internal1_m213_xz0},	//(internal1_m213_xz0) xz0 - новое задание мм
	{ 1379	,8	,1	, &internal1_m213_tz0},	//(internal1_m213_tz0) tz0 - время защиты от нового задания сек
	{ 1380	,1	,1	, &internal1_m213_Shift0},	//(internal1_m213_Shift0) Shift0 - признак самохода
	{ 1381	,1	,1	, &internal1_m213_ShCntlSp0},	//(internal1_m213_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1382	,1	,1	, &internal1_m213_ShiftControl},	//(internal1_m213_ShiftControl) ShiftControl - признак самохода
	{ 1383	,1	,1	, &internal1_m657_q0},	//(internal1_m657_q0) q0 - внутренний параметр
	{ 1384	,18	,1	, &internal1_m476_DvUp0},	//(internal1_m476_DvUp0) - есть команда на движение вперёд
	{ 1385	,18	,1	, &internal1_m476_DvDw0},	//(internal1_m476_DvDw0) - есть команда на движение назад
	{ 1386	,18	,1	, &internal1_m476_FDvUp0},	//(internal1_m476_FDvUp0) - есть команда на движение вперёд
	{ 1387	,18	,1	, &internal1_m476_FDvDw0},	//(internal1_m476_FDvDw0) - есть команда на движение назад
	{ 1388	,18	,1	, &internal1_m476_BlDv0},	//(internal1_m476_BlDv0) - была блокировка
	{ 1389	,18	,1	, &internal1_m476_Pkv0},	//(internal1_m476_Pkv0) Pkv - передний конечный выключатель
	{ 1390	,18	,1	, &internal1_m476_Pkav0},	//(internal1_m476_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1391	,18	,1	, &internal1_m476_Zkv0},	//(internal1_m476_Zkv0) Zkv - задний конечный выключатель
	{ 1392	,18	,1	, &internal1_m476_Zkav0},	//(internal1_m476_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1393	,8	,1	, &internal1_m476_txNm},	//(internal1_m476_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1394	,8	,1	, &internal1_m476_txSm},	//(internal1_m476_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1395	,8	,1	, &internal1_m476_txHr},	//(internal1_m476_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1396	,8	,1	, &internal1_m476_txLd},	//(internal1_m476_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1397	,18	,1	, &internal1_m476_fef},	//(internal1_m476_fef) fef
	{ 1398	,18	,1	, &internal1_m470_DvUp0},	//(internal1_m470_DvUp0) - есть команда на движение вперёд
	{ 1399	,18	,1	, &internal1_m470_DvDw0},	//(internal1_m470_DvDw0) - есть команда на движение назад
	{ 1400	,18	,1	, &internal1_m470_FDvUp0},	//(internal1_m470_FDvUp0) - есть команда на движение вперёд
	{ 1401	,18	,1	, &internal1_m470_FDvDw0},	//(internal1_m470_FDvDw0) - есть команда на движение назад
	{ 1402	,18	,1	, &internal1_m470_BlDv0},	//(internal1_m470_BlDv0) - была блокировка
	{ 1403	,18	,1	, &internal1_m470_Pkv0},	//(internal1_m470_Pkv0) Pkv - передний конечный выключатель
	{ 1404	,18	,1	, &internal1_m470_Pkav0},	//(internal1_m470_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1405	,18	,1	, &internal1_m470_Zkv0},	//(internal1_m470_Zkv0) Zkv - задний конечный выключатель
	{ 1406	,18	,1	, &internal1_m470_Zkav0},	//(internal1_m470_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1407	,8	,1	, &internal1_m470_txNm},	//(internal1_m470_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1408	,8	,1	, &internal1_m470_txSm},	//(internal1_m470_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1409	,8	,1	, &internal1_m470_txHr},	//(internal1_m470_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1410	,8	,1	, &internal1_m470_txLd},	//(internal1_m470_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1411	,18	,1	, &internal1_m470_fef},	//(internal1_m470_fef) fef
	{ 1412	,8	,1	, &internal1_m823_X0},	//(internal1_m823_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1413	,8	,1	, &internal1_m823_t0},	//(internal1_m823_t0) время нахождения в зоне возврата
	{ 1414	,18	,1	, &internal1_m823_BLDv0},	//(internal1_m823_BLDv0) BlDv - Блокировка движения
	{ 1415	,3	,1	, &internal1_m843_xptr},	//(internal1_m843_xptr) указатель текущей позиции в массиве координат
	{ 1416	,8	,80	, &internal1_m843_x0},	//(internal1_m843_x0) x0 - массив мгновенных значений координат
	{ 1417	,8	,80	, &internal1_m843_tim0},	//(internal1_m843_tim0) tim0 - массив значений времени цикла
	{ 1418	,8	,1	, &internal1_m843_sumtim},	//(internal1_m843_sumtim) sumtim - время в пути
	{ 1419	,8	,1	, &internal1_m843_StSpeed},	//(internal1_m843_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1420	,8	,1	, &internal1_m843_Vz0},	//(internal1_m843_Vz0) Vz0 - предыдущая заданная скорость
	{ 1421	,3	,1	, &internal1_m843_flRazg},	//(internal1_m843_flRazg) признак разгона/торможения
	{ 1422	,8	,1	, &internal1_m843_DelSp},	//(internal1_m843_DelSp) DelSp - время переключения скоростей
	{ 1423	,8	,1	, &internal1_m843_z0},	//(internal1_m843_z0) z0 - точка прекращения движения
	{ 1424	,8	,1	, &internal1_m843_txZS},	//(internal1_m843_txZS) txZS
	{ 1425	,8	,1	, &internal1_m843_tx},	//(internal1_m843_tx) tx
	{ 1426	,8	,1	, &internal1_m843_txd},	//(internal1_m843_txd) txd
	{ 1427	,8	,1	, &internal1_m843_txMBl},	//(internal1_m843_txMBl) tx
	{ 1428	,8	,1	, &internal1_m843_txBl},	//(internal1_m843_txBl) tx
	{ 1429	,8	,1	, &internal1_m843_Speed0},	//(internal1_m843_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1430	,8	,1	, &internal1_m843_xz0},	//(internal1_m843_xz0) xz0 - новое задание мм
	{ 1431	,8	,1	, &internal1_m843_tz0},	//(internal1_m843_tz0) tz0 - время защиты от нового задания сек
	{ 1432	,1	,1	, &internal1_m843_Shift0},	//(internal1_m843_Shift0) Shift0 - признак самохода
	{ 1433	,1	,1	, &internal1_m843_ShCntlSp0},	//(internal1_m843_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1434	,1	,1	, &internal1_m843_ShiftControl},	//(internal1_m843_ShiftControl) ShiftControl - признак самохода
	{ 1435	,8	,1	, &internal1_m1602_X0},	//(internal1_m1602_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1436	,8	,1	, &internal1_m1602_t0},	//(internal1_m1602_t0) время нахождения в зоне возврата
	{ 1437	,18	,1	, &internal1_m1602_BLDv0},	//(internal1_m1602_BLDv0) BlDv - Блокировка движения
	{ 1438	,8	,1	, &internal1_m1123_X0},	//(internal1_m1123_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1439	,8	,1	, &internal1_m1123_t0},	//(internal1_m1123_t0) время нахождения в зоне возврата
	{ 1440	,18	,1	, &internal1_m1123_BLDv0},	//(internal1_m1123_BLDv0) BlDv - Блокировка движения
	{ 1441	,1	,1	, &internal1_m629_q0},	//(internal1_m629_q0) q0 - внутренний параметр
	{ 1442	,8	,1	, &internal1_m1223_X0},	//(internal1_m1223_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1443	,8	,1	, &internal1_m1223_t0},	//(internal1_m1223_t0) время нахождения в зоне возврата
	{ 1444	,18	,1	, &internal1_m1223_BLDv0},	//(internal1_m1223_BLDv0) BlDv - Блокировка движения
	{ 1445	,8	,1	, &internal1_m1243_tx},	//(internal1_m1243_tx) tx - время накопленное сек
	{ 1446	,18	,1	, &internal1_m1243_y0},	//(internal1_m1243_y0) y0
	{ 1447	,8	,1	, &internal1_m1251_tx},	//(internal1_m1251_tx) tx - время накопленное сек
	{ 1448	,18	,1	, &internal1_m1251_y0},	//(internal1_m1251_y0) y0
	{ 1449	,3	,1	, &internal1_m1257_xptr},	//(internal1_m1257_xptr) указатель текущей позиции в массиве координат
	{ 1450	,8	,80	, &internal1_m1257_x0},	//(internal1_m1257_x0) x0 - массив мгновенных значений координат
	{ 1451	,8	,80	, &internal1_m1257_tim0},	//(internal1_m1257_tim0) tim0 - массив значений времени цикла
	{ 1452	,8	,1	, &internal1_m1257_sumtim},	//(internal1_m1257_sumtim) sumtim - время в пути
	{ 1453	,8	,1	, &internal1_m1257_StSpeed},	//(internal1_m1257_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1454	,8	,1	, &internal1_m1257_Vz0},	//(internal1_m1257_Vz0) Vz0 - предыдущая заданная скорость
	{ 1455	,3	,1	, &internal1_m1257_flRazg},	//(internal1_m1257_flRazg) признак разгона/торможения
	{ 1456	,8	,1	, &internal1_m1257_DelSp},	//(internal1_m1257_DelSp) DelSp - время переключения скоростей
	{ 1457	,8	,1	, &internal1_m1257_z0},	//(internal1_m1257_z0) z0 - точка прекращения движения
	{ 1458	,8	,1	, &internal1_m1257_txZS},	//(internal1_m1257_txZS) txZS
	{ 1459	,8	,1	, &internal1_m1257_tx},	//(internal1_m1257_tx) tx
	{ 1460	,8	,1	, &internal1_m1257_txd},	//(internal1_m1257_txd) txd
	{ 1461	,8	,1	, &internal1_m1257_txMBl},	//(internal1_m1257_txMBl) tx
	{ 1462	,8	,1	, &internal1_m1257_txBl},	//(internal1_m1257_txBl) tx
	{ 1463	,8	,1	, &internal1_m1257_Speed0},	//(internal1_m1257_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1464	,8	,1	, &internal1_m1257_xz0},	//(internal1_m1257_xz0) xz0 - новое задание мм
	{ 1465	,8	,1	, &internal1_m1257_tz0},	//(internal1_m1257_tz0) tz0 - время защиты от нового задания сек
	{ 1466	,1	,1	, &internal1_m1257_Shift0},	//(internal1_m1257_Shift0) Shift0 - признак самохода
	{ 1467	,1	,1	, &internal1_m1257_ShCntlSp0},	//(internal1_m1257_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1468	,1	,1	, &internal1_m1257_ShiftControl},	//(internal1_m1257_ShiftControl) ShiftControl - признак самохода
	{ 1469	,1	,1	, &internal1_m649_q0},	//(internal1_m649_q0) q0 - внутренний параметр
	{ 1470	,8	,1	, &internal1_m1615_tx},	//(internal1_m1615_tx) tx - время накопленное сек
	{ 1471	,18	,1	, &internal1_m1615_y0},	//(internal1_m1615_y0) y0
	{ 1472	,8	,1	, &internal1_m1617_tx},	//(internal1_m1617_tx) tx - время накопленное сек
	{ 1473	,18	,1	, &internal1_m1617_y0},	//(internal1_m1617_y0) y0
	{ 1474	,18	,1	, &internal1_m1605_DvUp0},	//(internal1_m1605_DvUp0) - есть команда на движение вперёд
	{ 1475	,18	,1	, &internal1_m1605_DvDw0},	//(internal1_m1605_DvDw0) - есть команда на движение назад
	{ 1476	,18	,1	, &internal1_m1605_FDvUp0},	//(internal1_m1605_FDvUp0) - есть команда на движение вперёд
	{ 1477	,18	,1	, &internal1_m1605_FDvDw0},	//(internal1_m1605_FDvDw0) - есть команда на движение назад
	{ 1478	,18	,1	, &internal1_m1605_BlDv0},	//(internal1_m1605_BlDv0) - была блокировка
	{ 1479	,18	,1	, &internal1_m1605_Pkv0},	//(internal1_m1605_Pkv0) Pkv - передний конечный выключатель
	{ 1480	,18	,1	, &internal1_m1605_Pkav0},	//(internal1_m1605_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1481	,18	,1	, &internal1_m1605_Zkv0},	//(internal1_m1605_Zkv0) Zkv - задний конечный выключатель
	{ 1482	,18	,1	, &internal1_m1605_Zkav0},	//(internal1_m1605_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1483	,8	,1	, &internal1_m1605_txNm},	//(internal1_m1605_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1484	,8	,1	, &internal1_m1605_txSm},	//(internal1_m1605_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1485	,8	,1	, &internal1_m1605_txHr},	//(internal1_m1605_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1486	,8	,1	, &internal1_m1605_txLd},	//(internal1_m1605_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1487	,18	,1	, &internal1_m1605_fef},	//(internal1_m1605_fef) fef
	{ 1488	,3	,1	, &internal1_m1622_xptr},	//(internal1_m1622_xptr) указатель текущей позиции в массиве координат
	{ 1489	,8	,20	, &internal1_m1622_x0},	//(internal1_m1622_x0) x0 - массив мгновенных значений координат
	{ 1490	,8	,20	, &internal1_m1622_tim0},	//(internal1_m1622_tim0) tim0 - массив значений времени цикла
	{ 1491	,8	,1	, &internal1_m1622_sumtim},	//(internal1_m1622_sumtim) sumtim - время в пути
	{ 1492	,8	,1	, &internal1_m1622_StSpeed},	//(internal1_m1622_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1493	,8	,1	, &internal1_m1622_Vz0},	//(internal1_m1622_Vz0) Vz0 - предыдущая заданная скорость
	{ 1494	,3	,1	, &internal1_m1622_flRazg},	//(internal1_m1622_flRazg) признак разгона/торможения
	{ 1495	,8	,1	, &internal1_m1622_DelSp},	//(internal1_m1622_DelSp) DelSp - время переключения скоростей
	{ 1496	,8	,1	, &internal1_m1622_z0},	//(internal1_m1622_z0) z0 - точка прекращения движения
	{ 1497	,8	,1	, &internal1_m1622_txZS},	//(internal1_m1622_txZS) txZS
	{ 1498	,8	,1	, &internal1_m1622_tx},	//(internal1_m1622_tx) tx
	{ 1499	,8	,1	, &internal1_m1622_txd},	//(internal1_m1622_txd) txd
	{ 1500	,8	,1	, &internal1_m1622_txMBl},	//(internal1_m1622_txMBl) tx
	{ 1501	,8	,1	, &internal1_m1622_txBl},	//(internal1_m1622_txBl) tx
	{ 1502	,8	,1	, &internal1_m1622_Speed0},	//(internal1_m1622_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1503	,8	,1	, &internal1_m1622_xz0},	//(internal1_m1622_xz0) xz0 - новое задание мм
	{ 1504	,8	,1	, &internal1_m1622_tz0},	//(internal1_m1622_tz0) tz0 - время защиты от нового задания сек
	{ 1505	,1	,1	, &internal1_m1622_Shift0},	//(internal1_m1622_Shift0) Shift0 - признак самохода
	{ 1506	,1	,1	, &internal1_m1622_ShCntlSp0},	//(internal1_m1622_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1507	,1	,1	, &internal1_m1622_ShiftControl},	//(internal1_m1622_ShiftControl) ShiftControl - признак самохода
	{ 1508	,8	,1	, &internal1_m1139_tx},	//(internal1_m1139_tx) tx - время накопленное сек
	{ 1509	,18	,1	, &internal1_m1139_y0},	//(internal1_m1139_y0) y0
	{ 1510	,8	,1	, &internal1_m1143_tx},	//(internal1_m1143_tx) tx - время накопленное сек
	{ 1511	,18	,1	, &internal1_m1143_y0},	//(internal1_m1143_y0) y0
	{ 1512	,1	,1	, &internal1_m639_q0},	//(internal1_m639_q0) q0 - внутренний параметр
	{ 1513	,1	,1	, &internal1_m604_q0},	//(internal1_m604_q0) q0 - внутренний параметр
	{ 1514	,18	,1	, &internal1_m1130_DvUp0},	//(internal1_m1130_DvUp0) - есть команда на движение вперёд
	{ 1515	,18	,1	, &internal1_m1130_DvDw0},	//(internal1_m1130_DvDw0) - есть команда на движение назад
	{ 1516	,18	,1	, &internal1_m1130_FDvUp0},	//(internal1_m1130_FDvUp0) - есть команда на движение вперёд
	{ 1517	,18	,1	, &internal1_m1130_FDvDw0},	//(internal1_m1130_FDvDw0) - есть команда на движение назад
	{ 1518	,18	,1	, &internal1_m1130_BlDv0},	//(internal1_m1130_BlDv0) - была блокировка
	{ 1519	,18	,1	, &internal1_m1130_Pkv0},	//(internal1_m1130_Pkv0) Pkv - передний конечный выключатель
	{ 1520	,18	,1	, &internal1_m1130_Pkav0},	//(internal1_m1130_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1521	,18	,1	, &internal1_m1130_Zkv0},	//(internal1_m1130_Zkv0) Zkv - задний конечный выключатель
	{ 1522	,18	,1	, &internal1_m1130_Zkav0},	//(internal1_m1130_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1523	,8	,1	, &internal1_m1130_txNm},	//(internal1_m1130_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1524	,8	,1	, &internal1_m1130_txSm},	//(internal1_m1130_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1525	,8	,1	, &internal1_m1130_txHr},	//(internal1_m1130_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1526	,8	,1	, &internal1_m1130_txLd},	//(internal1_m1130_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1527	,18	,1	, &internal1_m1130_fef},	//(internal1_m1130_fef) fef
	{ 1528	,3	,1	, &internal1_m1147_xptr},	//(internal1_m1147_xptr) указатель текущей позиции в массиве координат
	{ 1529	,8	,20	, &internal1_m1147_x0},	//(internal1_m1147_x0) x0 - массив мгновенных значений координат
	{ 1530	,8	,20	, &internal1_m1147_tim0},	//(internal1_m1147_tim0) tim0 - массив значений времени цикла
	{ 1531	,8	,1	, &internal1_m1147_sumtim},	//(internal1_m1147_sumtim) sumtim - время в пути
	{ 1532	,8	,1	, &internal1_m1147_StSpeed},	//(internal1_m1147_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1533	,8	,1	, &internal1_m1147_Vz0},	//(internal1_m1147_Vz0) Vz0 - предыдущая заданная скорость
	{ 1534	,3	,1	, &internal1_m1147_flRazg},	//(internal1_m1147_flRazg) признак разгона/торможения
	{ 1535	,8	,1	, &internal1_m1147_DelSp},	//(internal1_m1147_DelSp) DelSp - время переключения скоростей
	{ 1536	,8	,1	, &internal1_m1147_z0},	//(internal1_m1147_z0) z0 - точка прекращения движения
	{ 1537	,8	,1	, &internal1_m1147_txZS},	//(internal1_m1147_txZS) txZS
	{ 1538	,8	,1	, &internal1_m1147_tx},	//(internal1_m1147_tx) tx
	{ 1539	,8	,1	, &internal1_m1147_txd},	//(internal1_m1147_txd) txd
	{ 1540	,8	,1	, &internal1_m1147_txMBl},	//(internal1_m1147_txMBl) tx
	{ 1541	,8	,1	, &internal1_m1147_txBl},	//(internal1_m1147_txBl) tx
	{ 1542	,8	,1	, &internal1_m1147_Speed0},	//(internal1_m1147_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1543	,8	,1	, &internal1_m1147_xz0},	//(internal1_m1147_xz0) xz0 - новое задание мм
	{ 1544	,8	,1	, &internal1_m1147_tz0},	//(internal1_m1147_tz0) tz0 - время защиты от нового задания сек
	{ 1545	,1	,1	, &internal1_m1147_Shift0},	//(internal1_m1147_Shift0) Shift0 - признак самохода
	{ 1546	,1	,1	, &internal1_m1147_ShCntlSp0},	//(internal1_m1147_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1547	,1	,1	, &internal1_m1147_ShiftControl},	//(internal1_m1147_ShiftControl) ShiftControl - признак самохода
	{ 1548	,1	,1	, &internal1_m752_x0},	//(internal1_m752_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1549	,1	,1	, &internal1_m721_x0},	//(internal1_m721_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1550	,1	,1	, &internal1_m684_x0},	//(internal1_m684_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1551	,1	,1	, &internal1_m777_q0},	//(internal1_m777_q0) q0 - внутренний параметр
	{ 1552	,1	,1	, &internal1_m772_q0},	//(internal1_m772_q0) q0 - внутренний параметр
	{ 1553	,1	,1	, &internal1_m740_q0},	//(internal1_m740_q0) q0 - внутренний параметр
	{ 1554	,1	,1	, &internal1_m745_q0},	//(internal1_m745_q0) q0 - внутренний параметр
	{ 1555	,1	,1	, &internal1_m753_q0},	//(internal1_m753_q0) q0 - внутренний параметр
	{ 1556	,1	,1	, &internal1_m765_q0},	//(internal1_m765_q0) q0 - внутренний параметр
	{ 1557	,1	,1	, &internal1_m743_q0},	//(internal1_m743_q0) q0 - внутренний параметр
	{ 1558	,18	,1	, &internal1_m1200_DvUp0},	//(internal1_m1200_DvUp0) - есть команда на движение вперёд
	{ 1559	,18	,1	, &internal1_m1200_DvDw0},	//(internal1_m1200_DvDw0) - есть команда на движение назад
	{ 1560	,18	,1	, &internal1_m1200_FDvUp0},	//(internal1_m1200_FDvUp0) - есть команда на движение вперёд
	{ 1561	,18	,1	, &internal1_m1200_FDvDw0},	//(internal1_m1200_FDvDw0) - есть команда на движение назад
	{ 1562	,18	,1	, &internal1_m1200_BlDv0},	//(internal1_m1200_BlDv0) - была блокировка
	{ 1563	,18	,1	, &internal1_m1200_Pkv0},	//(internal1_m1200_Pkv0) Pkv - передний конечный выключатель
	{ 1564	,18	,1	, &internal1_m1200_Pkav0},	//(internal1_m1200_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1565	,18	,1	, &internal1_m1200_Zkv0},	//(internal1_m1200_Zkv0) Zkv - задний конечный выключатель
	{ 1566	,18	,1	, &internal1_m1200_Zkav0},	//(internal1_m1200_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1567	,8	,1	, &internal1_m1200_txNm},	//(internal1_m1200_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1568	,8	,1	, &internal1_m1200_txSm},	//(internal1_m1200_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1569	,8	,1	, &internal1_m1200_txHr},	//(internal1_m1200_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1570	,8	,1	, &internal1_m1200_txLd},	//(internal1_m1200_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1571	,18	,1	, &internal1_m1200_fef},	//(internal1_m1200_fef) fef
	{ 1572	,18	,1	, &internal1_m1189_DvUp0},	//(internal1_m1189_DvUp0) - есть команда на движение вперёд
	{ 1573	,18	,1	, &internal1_m1189_DvDw0},	//(internal1_m1189_DvDw0) - есть команда на движение назад
	{ 1574	,18	,1	, &internal1_m1189_FDvUp0},	//(internal1_m1189_FDvUp0) - есть команда на движение вперёд
	{ 1575	,18	,1	, &internal1_m1189_FDvDw0},	//(internal1_m1189_FDvDw0) - есть команда на движение назад
	{ 1576	,18	,1	, &internal1_m1189_BlDv0},	//(internal1_m1189_BlDv0) - была блокировка
	{ 1577	,18	,1	, &internal1_m1189_Pkv0},	//(internal1_m1189_Pkv0) Pkv - передний конечный выключатель
	{ 1578	,18	,1	, &internal1_m1189_Pkav0},	//(internal1_m1189_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1579	,18	,1	, &internal1_m1189_Zkv0},	//(internal1_m1189_Zkv0) Zkv - задний конечный выключатель
	{ 1580	,18	,1	, &internal1_m1189_Zkav0},	//(internal1_m1189_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1581	,8	,1	, &internal1_m1189_txNm},	//(internal1_m1189_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1582	,8	,1	, &internal1_m1189_txSm},	//(internal1_m1189_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1583	,8	,1	, &internal1_m1189_txHr},	//(internal1_m1189_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1584	,8	,1	, &internal1_m1189_txLd},	//(internal1_m1189_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1585	,18	,1	, &internal1_m1189_fef},	//(internal1_m1189_fef) fef
	{ 1586	,18	,1	, &internal1_m797_DvUp0},	//(internal1_m797_DvUp0) - есть команда на движение вперёд
	{ 1587	,18	,1	, &internal1_m797_DvDw0},	//(internal1_m797_DvDw0) - есть команда на движение назад
	{ 1588	,18	,1	, &internal1_m797_FDvUp0},	//(internal1_m797_FDvUp0) - есть команда на движение вперёд
	{ 1589	,18	,1	, &internal1_m797_FDvDw0},	//(internal1_m797_FDvDw0) - есть команда на движение назад
	{ 1590	,18	,1	, &internal1_m797_BlDv0},	//(internal1_m797_BlDv0) - была блокировка
	{ 1591	,18	,1	, &internal1_m797_Pkv0},	//(internal1_m797_Pkv0) Pkv - передний конечный выключатель
	{ 1592	,18	,1	, &internal1_m797_Pkav0},	//(internal1_m797_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1593	,18	,1	, &internal1_m797_Zkv0},	//(internal1_m797_Zkv0) Zkv - задний конечный выключатель
	{ 1594	,18	,1	, &internal1_m797_Zkav0},	//(internal1_m797_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1595	,8	,1	, &internal1_m797_txNm},	//(internal1_m797_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1596	,8	,1	, &internal1_m797_txSm},	//(internal1_m797_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1597	,8	,1	, &internal1_m797_txHr},	//(internal1_m797_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1598	,8	,1	, &internal1_m797_txLd},	//(internal1_m797_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1599	,18	,1	, &internal1_m797_fef},	//(internal1_m797_fef) fef
	{ 1600	,18	,1	, &internal1_m793_DvUp0},	//(internal1_m793_DvUp0) - есть команда на движение вперёд
	{ 1601	,18	,1	, &internal1_m793_DvDw0},	//(internal1_m793_DvDw0) - есть команда на движение назад
	{ 1602	,18	,1	, &internal1_m793_FDvUp0},	//(internal1_m793_FDvUp0) - есть команда на движение вперёд
	{ 1603	,18	,1	, &internal1_m793_FDvDw0},	//(internal1_m793_FDvDw0) - есть команда на движение назад
	{ 1604	,18	,1	, &internal1_m793_BlDv0},	//(internal1_m793_BlDv0) - была блокировка
	{ 1605	,18	,1	, &internal1_m793_Pkv0},	//(internal1_m793_Pkv0) Pkv - передний конечный выключатель
	{ 1606	,18	,1	, &internal1_m793_Pkav0},	//(internal1_m793_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1607	,18	,1	, &internal1_m793_Zkv0},	//(internal1_m793_Zkv0) Zkv - задний конечный выключатель
	{ 1608	,18	,1	, &internal1_m793_Zkav0},	//(internal1_m793_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1609	,8	,1	, &internal1_m793_txNm},	//(internal1_m793_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1610	,8	,1	, &internal1_m793_txSm},	//(internal1_m793_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1611	,8	,1	, &internal1_m793_txHr},	//(internal1_m793_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1612	,8	,1	, &internal1_m793_txLd},	//(internal1_m793_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1613	,18	,1	, &internal1_m793_fef},	//(internal1_m793_fef) fef
	{ 1614	,18	,1	, &internal1_m375_DvUp0},	//(internal1_m375_DvUp0) - есть команда на движение вперёд
	{ 1615	,18	,1	, &internal1_m375_DvDw0},	//(internal1_m375_DvDw0) - есть команда на движение назад
	{ 1616	,18	,1	, &internal1_m375_FDvUp0},	//(internal1_m375_FDvUp0) - есть команда на движение вперёд
	{ 1617	,18	,1	, &internal1_m375_FDvDw0},	//(internal1_m375_FDvDw0) - есть команда на движение назад
	{ 1618	,18	,1	, &internal1_m375_BlDv0},	//(internal1_m375_BlDv0) - была блокировка
	{ 1619	,18	,1	, &internal1_m375_Pkv0},	//(internal1_m375_Pkv0) Pkv - передний конечный выключатель
	{ 1620	,18	,1	, &internal1_m375_Pkav0},	//(internal1_m375_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1621	,18	,1	, &internal1_m375_Zkv0},	//(internal1_m375_Zkv0) Zkv - задний конечный выключатель
	{ 1622	,18	,1	, &internal1_m375_Zkav0},	//(internal1_m375_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1623	,8	,1	, &internal1_m375_txNm},	//(internal1_m375_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1624	,8	,1	, &internal1_m375_txSm},	//(internal1_m375_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1625	,8	,1	, &internal1_m375_txHr},	//(internal1_m375_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1626	,8	,1	, &internal1_m375_txLd},	//(internal1_m375_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1627	,18	,1	, &internal1_m375_fef},	//(internal1_m375_fef) fef
	{ 1628	,18	,1	, &internal1_m404_DvUp0},	//(internal1_m404_DvUp0) - есть команда на движение вперёд
	{ 1629	,18	,1	, &internal1_m404_DvDw0},	//(internal1_m404_DvDw0) - есть команда на движение назад
	{ 1630	,18	,1	, &internal1_m404_FDvUp0},	//(internal1_m404_FDvUp0) - есть команда на движение вперёд
	{ 1631	,18	,1	, &internal1_m404_FDvDw0},	//(internal1_m404_FDvDw0) - есть команда на движение назад
	{ 1632	,18	,1	, &internal1_m404_BlDv0},	//(internal1_m404_BlDv0) - была блокировка
	{ 1633	,18	,1	, &internal1_m404_Pkv0},	//(internal1_m404_Pkv0) Pkv - передний конечный выключатель
	{ 1634	,18	,1	, &internal1_m404_Pkav0},	//(internal1_m404_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1635	,18	,1	, &internal1_m404_Zkv0},	//(internal1_m404_Zkv0) Zkv - задний конечный выключатель
	{ 1636	,18	,1	, &internal1_m404_Zkav0},	//(internal1_m404_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1637	,8	,1	, &internal1_m404_txNm},	//(internal1_m404_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1638	,8	,1	, &internal1_m404_txSm},	//(internal1_m404_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1639	,8	,1	, &internal1_m404_txHr},	//(internal1_m404_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1640	,8	,1	, &internal1_m404_txLd},	//(internal1_m404_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1641	,18	,1	, &internal1_m404_fef},	//(internal1_m404_fef) fef
	{ 1642	,18	,1	, &internal1_m398_DvUp0},	//(internal1_m398_DvUp0) - есть команда на движение вперёд
	{ 1643	,18	,1	, &internal1_m398_DvDw0},	//(internal1_m398_DvDw0) - есть команда на движение назад
	{ 1644	,18	,1	, &internal1_m398_FDvUp0},	//(internal1_m398_FDvUp0) - есть команда на движение вперёд
	{ 1645	,18	,1	, &internal1_m398_FDvDw0},	//(internal1_m398_FDvDw0) - есть команда на движение назад
	{ 1646	,18	,1	, &internal1_m398_BlDv0},	//(internal1_m398_BlDv0) - была блокировка
	{ 1647	,18	,1	, &internal1_m398_Pkv0},	//(internal1_m398_Pkv0) Pkv - передний конечный выключатель
	{ 1648	,18	,1	, &internal1_m398_Pkav0},	//(internal1_m398_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1649	,18	,1	, &internal1_m398_Zkv0},	//(internal1_m398_Zkv0) Zkv - задний конечный выключатель
	{ 1650	,18	,1	, &internal1_m398_Zkav0},	//(internal1_m398_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1651	,8	,1	, &internal1_m398_txNm},	//(internal1_m398_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1652	,8	,1	, &internal1_m398_txSm},	//(internal1_m398_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1653	,8	,1	, &internal1_m398_txHr},	//(internal1_m398_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1654	,8	,1	, &internal1_m398_txLd},	//(internal1_m398_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1655	,18	,1	, &internal1_m398_fef},	//(internal1_m398_fef) fef
	{ 1656	,1	,1	, &internal1_m749_q0},	//(internal1_m749_q0) q0 - внутренний параметр
	{ 1657	,1	,1	, &internal1_m746_q0},	//(internal1_m746_q0) q0 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="du.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{763,"fEM_A1UC03RDU\0"}, 
{764,"dEM_A1UC05UDU\0"}, 
{765,"dEM_A1UC06UDU\0"}, 
{766,"dEM_A2UC06UDU\0"}, 
{767,"dEM_A2UC05UDU\0"}, 
{768,"fEM_A2UC03RDU\0"}, 
{769,"dEM_A3UC06UDU\0"}, 
{770,"dEM_A3UC05UDU\0"}, 
{771,"fEM_A3UC03RDU\0"}, 
{772,"dEM_A8UC06UDU\0"}, 
{773,"fEM_A8UC03RDU\0"}, 
{774,"dEM_A8UC05UDU\0"}, 
{775,"fEM_R0UV81RDU\0"}, 
{776,"fEM_R0UV82RDU\0"}, 
{777,"fEM_R0UV83RDU\0"}, 
{778,"fEM_R0UV84RDU\0"}, 
{779,"fEM_R0UV86RDU\0"}, 
{780,"fEM_R0UV85RDU\0"}, 
{781,"fEM_R0UV87RDU\0"}, 
{782,"fEM_A3UP03RDU\0"}, 
{783,"fEM_A3UP04RDU\0"}, 
{784,"fEM_A3UP43RDU\0"}, 
{785,"fEM_A3UP44RDU\0"}, 
{786,"fEM_A3UP53RDU\0"}, 
{787,"fEM_A3UP85RDU\0"}, 
{788,"fEM_A3UP88RDU\0"}, 
{789,"fEM_A3UP86RDU\0"}, 
{790,"fEM_B8UV01RDU\0"}, 
{791,"fEM_B8UV02RDU\0"}, 
{792,"fEM_B8UV03RDU\0"}, 
{793,"fEM_B8UL04RDU\0"}, 
{794,"iEM_A2UV03CDU\0"}, 
{795,"fEM_A2UV01RDU\0"}, 
{796,"fEM_A2UV02RDU\0"}, 
{797,"fEM_A1UV01RDU\0"}, 
{798,"fEM_A1UV02RDU\0"}, 
{799,"fEM_A1UC06RDU\0"}, 
{800,"fEM_A1UC05RDU\0"}, 
{801,"fEM_A1UL04RDU\0"}, 
{802,"fEM_A3UV01RDU\0"}, 
{803,"fEM_A3UV02RDU\0"}, 
{804,"fEM_A3UC06RDU\0"}, 
{805,"fEM_A3UC05RDU\0"}, 
{806,"fEM_A3UL04RDU\0"}, 
{807,"fEM_A3UP54RDU\0"}, 
{808,"fEM_A3UP87RDU\0"}, 
{809,"fEM_R0UL05RDU\0"}, 
{810,"fEM_R0UL20RDU\0"}, 
{811,"fEM_B8UV04RDU\0"}, 
{812,"fEM_B8UC06RDU\0"}, 
{813,"fEM_B8UC05RDU\0"}, 
{814,"fEM_A2UL05RDU\0"}, 
{815,"fEM_A2UL03RDU\0"}, 
{816,"fEM_A2UC06RDU\0"}, 
{817,"fEM_A2UC05RDU\0"}, 
{818,"fEM_A2UL04RDU\0"}, 
{819,"fEM_A1UL03RDU\0"}, 
{820,"fEM_A1UL05RDU\0"}, 
{821,"fEM_A3UL03RDU\0"}, 
{822,"fEM_A3UL05RDU\0"}, 
{823,"fEM_A1UC08RDU\0"}, 
{824,"fEM_A3UC08RDU\0"}, 
{825,"fEM_A1UC07RDU\0"}, 
{826,"fEM_A1UL01RDU\0"}, 
{827,"fEM_A3UC07RDU\0"}, 
{828,"fEM_A3UL01RDU\0"}, 
{829,"fEM_A2UC08RDU\0"}, 
{830,"fEM_A2UC07RDU\0"}, 
{831,"fEM_A2UL01RDU\0"}, 
{832,"fEM_B8UC01RDU\0"}, 
{833,"fEM_B8UL07RDU\0"}, 
{834,"fEM_B8UC02RDU\0"}, 
{835,"fEM_B8UL01RDU\0"}, 
{836,"fEM_B8UL05RDU\0"}, 
{837,"fEM_B8UL03RDU\0"}, 
{838,"fEM_B8UL06RDU\0"}, 
{839,"fEM_A9UZ03RDU\0"}, 
{840,"fEM_A9UZ04RDU\0"}, 
{841,"fEM_A9UZ05RDU\0"}, 
{842,"fEM_R4UZ04RDU\0"}, 
{843,"fEM_R4UZ03RDU\0"}, 
{844,"fEM_R4UZ05RDU\0"}, 
{845,"fEM_A5UZ03RDU\0"}, 
{846,"fEM_A5UZ04RDU\0"}, 
{847,"fEM_A5UZ05RDU\0"}, 
{848,"fEM_A4UZ03RDU\0"}, 
{849,"fEM_A4UZ04RDU\0"}, 
{850,"fEM_A4UZ05RDU\0"}, 
{851,"fEM_A6UZ03RDU\0"}, 
{852,"fEM_A6UZ04RDU\0"}, 
{853,"fEM_A6UZ05RDU\0"}, 
{854,"fEM_R1UZ03RDU\0"}, 
{855,"fEM_R1UZ04RDU\0"}, 
{856,"fEM_R1UZ05RDU\0"}, 
{857,"fEM_R0UL04RDU\0"}, 
{858,"fEM_R0UL06RDU\0"}, 
{859,"fEM_R0UL03RDU\0"}, 
{860,"fEM_R0UL17RDU\0"}, 
{861,"fEM_R0UL19RDU\0"}, 
{862,"fEM_R0UL07RDU\0"}, 
{863,"fEM_R0UL18RDU\0"}, 
{864,"fEM_R0UL16RDU\0"}, 
{865,"fEM_R0UL02RDU\0"}, 
{866,"fEM_R0UN08RDU\0"}, 
{867,"fEM_R0UN07RDU\0"}, 
{868,"fEM_R0UN06RDU\0"}, 
{869,"fEM_R0UN05RDU\0"}, 
{870,"fEM_R0UN04RDU\0"}, 
{871,"fEM_R0UN03RDU\0"}, 
{872,"fEM_R0UN02RDU\0"}, 
{873,"fEM_R0UN01RDU\0"}, 
{874,"fEM_A2UC82RDU\0"}, 
{875,"fEM_A2UC83RDU\0"}, 
{876,"fEM_A1UC83RDU\0"}, 
{877,"fEM_A2UC81RDU\0"}, 
{878,"fEM_A1UC81RDU\0"}, 
{879,"fEM_A1UC82RDU\0"}, 
{880,"fEM_A2UL83RDU\0"}, 
{881,"fEM_A3UC81RDU\0"}, 
{882,"fEM_A3UC82RDU\0"}, 
{883,"fEM_R0UN80RDU\0"}, 
{884,"iEM_A2UV01IDU\0"}, 
{885,"iEM_A2UV02IDU\0"}, 
{886,"iEM_A1UV01IDU\0"}, 
{887,"iEM_A1UV02IDU\0"}, 
{888,"iEM_A1UV03IDU\0"}, 
{889,"iEM_A3UV01IDU\0"}, 
{890,"iEM_A3UV02IDU\0"}, 
{891,"lEM_R0MD01LC1\0"}, 
{892,"fEM_A3UC09RDU\0"}, 
{893,"fEM_A2UC02RDU\0"}, 
{894,"fEM_A1UC02RDU\0"}, 
{895,"fEM_A3UC02RDU\0"}, 
{896,"fEM_R0UL21RDU\0"}, 
{897,"fEM_R0UN09RDU\0"}, 
{898,"fEM_R0UN11RDU\0"}, 
{899,"fEM_R0UN12RDU\0"}, 
{900,"fEM_R0UN13RDU\0"}, 
{901,"fEM_R0UN14RDU\0"}, 
{902,"fEM_R0UN16RDU\0"}, 
{903,"fEM_R0UN17RDU\0"}, 
{904,"fEM_R0UN18RDU\0"}, 
{905,"fEM_R0UN19RDU\0"}, 
{906,"fEM_R0UN70LDU\0"}, 
{907,"fEM_R0UN71LDU\0"}, 
{908,"fEM_R0UN72LDU\0"}, 
{909,"fEM_R0UN73LDU\0"}, 
{910,"fEM_R0UN74LDU\0"}, 
{911,"fEM_R0UN75LDU\0"}, 
{912,"fEM_R0UN80LDU\0"}, 
{913,"fEM_R0UN81LDU\0"}, 
{914,"fEM_R0UN82LDU\0"}, 
{915,"fEM_R0UN83LDU\0"}, 
{916,"fEM_R0UN84LDU\0"}, 
{917,"fEM_R0UN85LDU\0"}, 
{918,"fEM_R0UT20RDU\0"}, 
{919,"fEM_R0UN25RDU\0"}, 
{920,"fEM_R0UN15RDU\0"}, 
{921,"fEM_R0UN26RDU\0"}, 
{922,"fEM_R0UN27RDU\0"}, 
{923,"fEM_R0UN24RDU\0"}, 
{924,"fEM_R0UL25RDU\0"}, 
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
	{1,5005,&coil_MDuS[0],&di_MDuS[0],&ir_MDuS[0],&hr_MDuS[0],NULL,MDuS_ip1,MDuS_ip2,20},	 //Мастер ДУ в SCM
	{0,5006,&coil_DiagnDU[0],&di_DiagnDU[0],&ir_DiagnDU[0],&hr_DiagnDU[0],NULL,NULL,NULL,0},	 //Диагностика DU

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
	{&B3IS35LDU,1,0},
	{&B4IS10LDU,1,6},
	{&B3IS31LDU,1,8},
	{&B2IS33LDU,1,4},
	{&B1IS11LDU,1,14},
	{&A3VZ15LZ1,1,36},
	{&R2IS11LDU,1,56},
	{&R1IS11LDU,1,52},
	{&R0DE02LDU,3,64},
	{&A3VZ13LZ1,1,34},
	{&B4IS21LDU,1,62},
	{&A9IS11LDU,1,44},
	{&A9IS21LDU,1,46},
	{&A1VN71LZ1,1,40},
	{&B9IS11LDU,1,48},
	{&B9IS21LDU,1,50},
	{&B4IS11LDU,1,60},
	{&B3IS21LDU,1,24},
	{&B2IS21LDU,1,22},
	{&B1IS21LDU,1,16},
	{&R0AD14LZ1,1,38},
	{&B2IS11LDU,1,20},
	{&R2IS21LDU,1,58},
	{&B2IS12LDU,1,18},
	{&R8IS11LDU,1,26},
	{&R1IS21LDU,1,54},
	{&B7AS31LDU,1,10},
	{&R0VZ71LZ1,1,42},
	{&B1IS12LDU,1,12},
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
	{&A2IS33LDU,1,4},
	{&A3IS31LDU,1,8},
	{&A3VZ15LZ2,1,36},
	{&A4IS11LDU,1,26},
	{&R0DE03LDU,3,64},
	{&A7AS31LDU,1,10},
	{&R0VZ71LZ2,1,42},
	{&A3IS33LDU,1,2},
	{&A2IS11LDU,1,20},
	{&A4IS21LDU,1,28},
	{&R0IS01LDU,1,56},
	{&R0IS02LDU,1,58},
	{&A1IS21LDU,1,16},
	{&A2IS21LDU,1,22},
	{&A3IS21LDU,1,24},
	{&R0AD14LZ2,1,38},
	{&A3VZ13LZ2,1,34},
	{&A1VN71LZ2,1,40},
	{&A4IS10LDU,1,6},
	{&A3IS35LDU,1,0},
	{&A1IS11LDU,1,14},
	{&A1IS12LDU,1,12},
	{&A2IS12LDU,1,18},
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
	{&B8IS21LDU,1,38},
	{&R3IS21LDU,1,34},
	{&B8IS12LDU,1,40},
	{&A5IS11LDU,1,20},
	{&A5IS21LDU,1,22},
	{&B5IS11LDU,1,28},
	{&B5IS21LDU,1,30},
	{&R3IS11LDU,1,32},
	{&R5IS11LDU,1,48},
	{&B6IS21LDU,1,26},
	{&B6IS11LDU,1,24},
	{&A6IS21LDU,1,18},
	{&A6IS11LDU,1,16},
	{&R4IS11LDU,1,8},
	{&A3IS11LDU,1,0},
	{&R6IS21LDU,1,56},
	{&B8IS22LDU,1,42},
	{&R4IS21LDU,1,12},
	{&R4IS22LDU,1,14},
	{&R4IS12LDU,1,10},
	{&A3IS22LDU,1,2},
	{&B3IS22LDU,1,6},
	{&R0DE04LDU,3,64},
	{&B3IS11LDU,1,4},
	{&A8IS12LDU,1,58},
	{&A8IS22LDU,1,60},
	{&B8IS11LDU,1,36},
	{&R5IS21LDU,1,50},
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
	{&A2IE04LDU,1,14},
	{&A3IE03LDU,1,20},
	{&A3IE04LDU,1,22},
	{&B1IE03LDU,1,28},
	{&B1IE04LDU,1,30},
	{&B2IE03LDU,1,36},
	{&B2IE04LDU,1,38},
	{&B3IE03LDU,1,44},
	{&B3IE04LDU,1,46},
	{&A2IE03LDU,1,12},
	{&B2IE02LDU,1,32},
	{&B3IE02LDU,1,40},
	{&B1IE02LDU,1,24},
	{&B3IE01LDU,1,42},
	{&B2IE01LDU,1,34},
	{&A1IE04LDU,1,6},
	{&A1IE03LDU,1,4},
	{&B1IE01LDU,1,26},
	{&A2IE02LDU,1,8},
	{&A3IE02LDU,1,16},
	{&A1IE02LDU,1,0},
	{&A2IE01LDU,1,10},
	{&A1IE01LDU,1,2},
	{&A3IE01LDU,1,18},
	{&R6IS41LDU,1,52},
	{&R6IS42LDU,1,54},
	{&R0DE05LDU,3,64},
	{&R6IS32LDU,1,50},
	{&R6IS31LDU,1,48},
	{&R6IS52LDU,1,58},
	{&R6IS51LDU,1,56},
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
	{&B2AD01LDU,1,18},
	{&B2AD05LDU,1,26},
	{&B2AD04LDU,1,24},
	{&B2AD03LDU,1,22},
	{&B2AD02LDU,1,20},
	{&B2AD21LDU,1,16},
	{&B2AD11LDU,1,14},
	{&R0DE07LDU,3,38},
	{&A2AD01LDU,1,4},
	{&A2AD05LDU,1,12},
	{&A2AD04LDU,1,10},
	{&A2AD11LDU,1,0},
	{&A2AD21LDU,1,2},
	{&A2AD02LDU,1,6},
	{&A2AD03LDU,1,8},
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
	{&R0DE08LDU,3,38},
	{&A1AD05LDU,1,12},
	{&A1AD01LDU,1,4},
	{&B1AD02LDU,1,20},
	{&B1AD03LDU,1,22},
	{&B1AD21LDU,1,16},
	{&B1AD11LDU,1,14},
	{&B1AD04LDU,1,24},
	{&A1AD04LDU,1,10},
	{&B1AD05LDU,1,26},
	{&A1AD03LDU,1,8},
	{&B1AD01LDU,1,18},
	{&A1AD02LDU,1,6},
	{&A1AD21LDU,1,2},
	{&A1AD11LDU,1,0},
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
	{&A6AD20LDU,1,18},
	{&B8AD10LDU,1,28},
	{&B8AD20LDU,1,30},
	{&A8AD10LDU,1,12},
	{&B6AD10LDU,1,20},
	{&B6AD20LDU,1,22},
	{&A8AD20LDU,1,14},
	{&A6AD10LDU,1,16},
	{&B7AP31LDU,1,10},
	{&R0DE09LDU,3,38},
	{&R4AD20LDU,1,26},
	{&B3AD33LDU,1,2},
	{&R4AD10LDU,1,24},
	{&B2AD33LDU,1,4},
	{&B3AD31LDU,1,8},
	{&B3AD34LDU,1,0},
	{&B4AD10LDU,1,6},
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
	{&A2AD33LDU,1,4},
	{&A7AP31LDU,1,10},
	{&B5AD10LDU,1,24},
	{&B5AD20LDU,1,26},
	{&A5AD10LDU,1,20},
	{&A5AD20LDU,1,22},
	{&R2AD20LDU,1,18},
	{&R2AD10LDU,1,16},
	{&R1AD20LDU,1,14},
	{&R1AD10LDU,1,12},
	{&A4AD10LDU,1,6},
	{&R0DE0ALDU,3,38},
	{&A3AD31LDU,1,8},
	{&A3AD34LDU,1,0},
	{&A3AD33LDU,1,2},
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
	{&A3AD21LDU,1,2},
	{&A3AD02LDU,1,6},
	{&A3AD11LDU,1,0},
	{&A3AD03LDU,1,8},
	{&A3AD04LDU,1,10},
	{&A3AD05LDU,1,12},
	{&B3AD01LDU,1,18},
	{&B3AD05LDU,1,26},
	{&B3AD04LDU,1,24},
	{&B3AD03LDU,1,22},
	{&B3AD02LDU,1,20},
	{&B3AD21LDU,1,16},
	{&B3AD11LDU,1,14},
	{&R0DE0BLDU,3,38},
	{&A9AD10LDU,1,28},
	{&B9AD10LDU,1,30},
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
	{&R0DE0CLDU,3,26},
	{&B3IP02IDU,3,3},
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
	{&R2VS12LDU,1,14},
	{&R1VS12LDU,1,8},
	{&A5VS22LDU,1,22},
	{&A5VS12LDU,1,20},
	{&B5VS22LDU,1,28},
	{&B5VS12LDU,1,26},
	{&R4VS12LDU,1,2},
	{&R4VS22LDU,1,4},
	{&R0DE0DLDU,3,64},
	{&A5IE02LDU,1,24},
	{&B5IE01LDU,1,30},
	{&R0IE02LDU,1,44},
	{&R0IE01LDU,1,46},
	{&R2VS22LDU,1,16},
	{&R1VS22LDU,1,10},
	{&R1IE01LDU,1,12},
	{&R2IE01LDU,1,18},
	{&R6IS61LDU,1,0},
	{&B6VS12LDU,1,38},
	{&B6VS22LDU,1,40},
	{&A6VS12LDU,1,32},
	{&A6VS22LDU,1,34},
	{&A8IE01LDU,1,6},
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
	{&R0AD04LZ2,1,28},
	{&R0AD05LZ1,1,20},
	{&R0AD05LZ2,1,30},
	{&R8AD21LDU,1,22},
	{&R0AD04LZ1,1,18},
	{&R0AD03LZ2,1,26},
	{&A2AD31LDU,1,6},
	{&B2AD31LDU,1,14},
	{&R0DE0FLDU,3,38},
	{&B1AD32LDU,1,8},
	{&A1AD32LDU,1,0},
	{&R0AD16LDU,1,24},
	{&A1AD31LDU,1,2},
	{&B2AD32LDU,1,12},
	{&A2AD32LDU,1,4},
	{&B1AD31LDU,1,10},
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
	{&R0DE33LDU,1,4},
	{&R0DE34LDU,1,6},
	{&R0DE35LDU,1,8},
	{&R0DE36LDU,1,10},
	{&R0DE37LDU,1,12},
	{&R0DEB4LDU,1,24},
	{&R0DEB1LDU,1,18},
	{&R0DE38LDU,1,14},
	{&R0DEB2LDU,1,20},
	{&R0DEB3LDU,1,22},
	{&R0DE39LDU,1,16},
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
	setAsFloat(763,0.0000976563);
	setAsInt(764,1024200);
	setAsInt(765,-200);
	setAsInt(766,-200);
	setAsInt(767,1024200);
	setAsFloat(768,0.0000976563);
	setAsInt(769,-200);
	setAsInt(770,1689599);
	setAsFloat(771,0.00009765625);
	setAsInt(772,-200);
	setAsFloat(773,0.0009765625);
	setAsInt(774,1536200);
	setAsFloat(775,100);
	setAsFloat(776,200);
	setAsFloat(777,300);
	setAsFloat(778,400);
	setAsFloat(779,600);
	setAsFloat(780,500);
	setAsFloat(781,750);
	setAsFloat(782,2.5);
	setAsFloat(783,0);
	setAsFloat(784,0.46);
	setAsFloat(785,0.49);
	setAsFloat(786,0.52);
	setAsFloat(787,0.53);
	setAsFloat(788,0.67);
	setAsFloat(789,0.56);
	setAsFloat(790,4);
	setAsFloat(791,4);
	setAsFloat(792,10.91);
	setAsFloat(793,3);
	setAsShort(794,4);
	setAsFloat(795,0.15);
	setAsFloat(796,0.15);
	setAsFloat(797,0.4);
	setAsFloat(798,0.4);
	setAsFloat(799,0.03);
	setAsFloat(800,0.04);
	setAsFloat(801,3);
	setAsFloat(802,0.3);
	setAsFloat(803,0.3);
	setAsFloat(804,0.07);
	setAsFloat(805,0.04);
	setAsFloat(806,3);
	setAsFloat(807,0.55);
	setAsFloat(808,0.64);
	setAsFloat(809,0.180);
	setAsFloat(810,0.025);
	setAsFloat(811,0.1);
	setAsFloat(812,2);
	setAsFloat(813,0.3);
	setAsFloat(814,3);
	setAsFloat(815,1.50);
	setAsFloat(816,0.04);
	setAsFloat(817,0.05);
	setAsFloat(818,3);
	setAsFloat(819,1.50);
	setAsFloat(820,3);
	setAsFloat(821,1.50);
	setAsFloat(822,2);
	setAsFloat(823,0.004);
	setAsFloat(824,0.006);
	setAsFloat(825,0.006);
	setAsFloat(826,1.0);
	setAsFloat(827,0.01);
	setAsFloat(828,1);
	setAsFloat(829,0.008);
	setAsFloat(830,0.01);
	setAsFloat(831,1);
	setAsFloat(832,0.4);
	setAsFloat(833,120);
	setAsFloat(834,0.6);
	setAsFloat(835,1);
	setAsFloat(836,2);
	setAsFloat(837,1.50);
	setAsFloat(838,2.0);
	setAsFloat(839,1);
	setAsFloat(840,15);
	setAsFloat(841,0.50);
	setAsFloat(842,360);
	setAsFloat(843,1);
	setAsFloat(844,2);
	setAsFloat(845,1.0);
	setAsFloat(846,6.0);
	setAsFloat(847,0.50);
	setAsFloat(848,1.0);
	setAsFloat(849,16.0);
	setAsFloat(850,3.0);
	setAsFloat(851,1.0);
	setAsFloat(852,60.0);
	setAsFloat(853,0.50);
	setAsFloat(854,1.0);
	setAsFloat(855,20.0);
	setAsFloat(856,0.50);
	setAsFloat(857,2.0);
	setAsFloat(858,2.0);
	setAsFloat(859,1.5);
	setAsFloat(860,0.06);
	setAsFloat(861,0.01);
	setAsFloat(862,0.045);
	setAsFloat(863,0.040);
	setAsFloat(864,0.007);
	setAsFloat(865,0.014);
	setAsFloat(866,2000.0);
	setAsFloat(867,1500.0);
	setAsFloat(868,1000.0);
	setAsFloat(869,800.0);
	setAsFloat(870,500.0);
	setAsFloat(871,200.0);
	setAsFloat(872,100.0);
	setAsFloat(873,0.001);
	setAsFloat(874,100);
	setAsFloat(875,100);
	setAsFloat(876,110.0);
	setAsFloat(877,20);
	setAsFloat(878,30.0);
	setAsFloat(879,100.0);
	setAsFloat(880,1.50);
	setAsFloat(881,170);
	setAsFloat(882,170);
	setAsFloat(883,10);
	setAsShort(884,1);
	setAsShort(885,4);
	setAsShort(886,1);
	setAsShort(887,4);
	setAsShort(888,4);
	setAsShort(889,4);
	setAsShort(890,4);
	setAsBool(891,0);
	setAsFloat(892,159.99);
	setAsFloat(893,0.002375);
	setAsFloat(894,0.000877);
	setAsFloat(895,0.001675);
	setAsFloat(896,2.5);
	setAsFloat(897,30);
	setAsFloat(898,30);
	setAsFloat(899,0.05);
	setAsFloat(900,0.05);
	setAsFloat(901,160.0);
	setAsFloat(902,-170.11);
	setAsFloat(903,76.25088);
	setAsFloat(904,0.271145);
	setAsFloat(905,24.93556615);
	setAsFloat(906,0.1268);
	setAsFloat(907,0.1567);
	setAsFloat(908,0.1858);
	setAsFloat(909,0.2066);
	setAsFloat(910,0.2646);
	setAsFloat(911,0.2995);
	setAsFloat(912,0.721275);
	setAsFloat(913,0.700575);
	setAsFloat(914,0.6681);
	setAsFloat(915,0.61515);
	setAsFloat(916,0.3885);
	setAsFloat(917,0.23325);
	setAsFloat(918,3600.0);
	setAsFloat(919,0.935);
	setAsFloat(920,0.1);
	setAsFloat(921,0.006792308);
	setAsFloat(922,0.000418877);
	setAsFloat(923,0.0015);
	setAsFloat(924,0.30);
}

uspaint8 InternalBuf[8521];

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
ssint var12;
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
ssint var140;
ssbool var141;
ssbool var142;
ssint var143;
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
ssfloat var188;
ssbool var189;
ssbool var190;
ssbool var191;
ssbool var192;
ssbool var193;
ssbool var194;
ssbool var195;
ssbool var196;
ssbool var197;
ssfloat var198;
ssfloat var199;
ssbool var200;
ssbool var201;
ssbool var202;
ssfloat var203;
ssfloat var204;
ssbool var205;
ssbool var206;
ssfloat var207;
ssbool var208;
ssbool var209;
ssbool var210;
ssbool var211;
ssbool var212;
ssbool var213;
ssbool var214;
ssbool var215;
ssfloat var216;
ssfloat var217;
ssfloat var218;
ssfloat var219;
ssbool var220;
ssfloat var221;
ssfloat var222;
ssint var223;
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
ssfloat var314;
ssbool var315;
ssbool var316;
ssbool var317;
ssfloat var318;
ssbool var319;
ssbool var320;
ssbool var321;
ssfloat var322;
ssbool var323;
ssbool var324;
ssbool var325;
ssfloat var326;
ssbool var327;
ssbool var328;
ssbool var329;
ssfloat var330;
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
ssfloat var427;
ssfloat var428;
ssbool var429;
ssfloat var430;
ssfloat var431;
ssbool var432;
ssfloat var433;
ssfloat var434;
ssbool var435;
ssfloat var436;
ssfloat var437;
ssbool var438;
ssbool var439;
ssfloat var440;
ssfloat var441;
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
ssbool var566;
ssbool var567;
ssbool var568;
ssbool var569;
ssbool var570;
sslong var571;
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
ssbool var977;
ssbool var978;
ssbool var979;
ssbool var980;
ssbool var981;
ssfloat var982;
ssbool var983;
ssfloat var984;
ssbool var985;
ssfloat var986;
ssbool var987;
ssbool var988;
ssbool var989;
ssbool var990;
ssfloat var991;
ssfloat var992;
ssfloat var993;
ssfloat var994;
ssfloat var995;
ssfloat var996;
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
ssint var1052;
ssint var1053;
ssbool var1054;
ssbool var1055;
ssbool var1056;
ssbool var1057;
ssbool var1058;
ssbool var1059;
sslong var1060;
ssbool var1061;
ssbool var1062;
ssbool var1063;
ssint var1064;
ssbool var1065;
ssbool var1066;
ssbool var1067;
ssbool var1068;
ssbool var1069;
ssbool var1070;
ssbool var1071;
ssbool var1072;
ssbool var1073;
ssint var1074;
ssint var1075;
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
sslong var1115;
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
ssfloat var1134;
ssbool var1135;
ssbool var1136;
ssbool var1137;
ssbool var1138;
ssbool var1139;
ssfloat var1140;
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
ssint var1154;
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
ssfloat var1179;
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
ssbool var1270;
ssbool var1271;
ssbool var1272;
ssbool var1273;
ssbool var1274;
sslong var1275;
ssbool var1276;
ssint var1277;
ssint var1278;
ssbool var1279;
ssfloat var1280;
ssfloat var1281;
ssfloat var1282;
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
ssint var1299;
ssbool var1300;
sschar var1301;
ssint var1302;
ssbool var1303;
ssfloat var1304;
ssbool var1305;
ssbool var1306;
ssbool var1307;
ssbool var1308;
ssbool var1309;
ssbool var1310;
ssbool var1311;
ssfloat var1312;
sschar var1313;
ssbool var1314;
ssbool var1315;
ssbool var1316;
ssbool var1317;
ssfloat var1318;
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
ssbool var1329;
ssbool var1330;
ssint var1331;
ssbool var1332;
sschar var1333;
ssint var1334;
ssbool var1335;
ssfloat var1336;
ssbool var1337;
ssbool var1338;
ssbool var1339;
ssbool var1340;
ssbool var1341;
ssbool var1342;
ssbool var1343;
ssfloat var1344;
sschar var1345;
ssbool var1346;
ssbool var1347;
ssbool var1348;
ssbool var1349;
ssfloat var1350;
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
sschar var1362;
ssint var1363;
ssbool var1364;
ssfloat var1365;
ssbool var1366;
ssbool var1367;
ssbool var1368;
ssbool var1369;
ssbool var1370;
ssbool var1371;
ssbool var1372;
ssfloat var1373;
sschar var1374;
ssbool var1375;
ssbool var1376;
ssbool var1377;
ssbool var1378;
ssfloat var1379;
ssbool var1380;
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
ssint var1393;
ssbool var1394;
sschar var1395;
ssint var1396;
ssbool var1397;
ssfloat var1398;
ssbool var1399;
ssbool var1400;
ssbool var1401;
ssbool var1402;
ssbool var1403;
ssbool var1404;
ssbool var1405;
ssfloat var1406;
sschar var1407;
ssbool var1408;
ssbool var1409;
ssfloat var1410;
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
ssint var1423;
ssbool var1424;
ssbool var1425;
ssbool var1426;
ssbool var1427;
ssbool var1428;
ssbool var1429;
ssbool var1430;
ssbool var1431;
ssint var1432;
ssbool var1433;
ssbool var1434;
ssbool var1435;
ssbool var1436;
ssbool var1437;
ssbool var1438;
ssbool var1439;
ssint var1440;
ssbool var1441;
sschar var1442;
ssint var1443;
ssbool var1444;
ssfloat var1445;
ssbool var1446;
ssbool var1447;
ssbool var1448;
ssbool var1449;
ssbool var1450;
ssbool var1451;
ssbool var1452;
ssfloat var1453;
sschar var1454;
ssbool var1455;
ssbool var1456;
ssfloat var1457;
ssbool var1458;
ssbool var1459;
ssbool var1460;
ssbool var1461;
ssbool var1462;
ssbool var1463;
ssbool var1464;
ssbool var1465;
sschar var1466;
ssbool var1467;
ssbool var1468;
ssbool var1469;
ssbool var1470;
ssbool var1471;
ssbool var1472;
ssbool var1473;
ssbool var1474;
ssbool var1475;
sschar var1476;
ssbool var1477;
ssbool var1478;
ssint var1479;
ssbool var1480;
sschar var1481;
ssbool var1482;
ssint var1483;
ssbool var1484;
ssbool var1485;
ssfloat var1486;
ssbool var1487;
ssbool var1488;
ssbool var1489;
ssbool var1490;
ssbool var1491;
ssbool var1492;
ssbool var1493;
ssfloat var1494;
sschar var1495;
ssbool var1496;
ssbool var1497;
ssbool var1498;
ssbool var1499;
ssfloat var1500;
ssbool var1501;
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
ssfloat var1513;
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
ssbool var1525;
ssbool var1526;
ssbool var1527;
ssbool var1528;
ssbool var1529;
ssfloat var1530;
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
ssbool var1563;
ssbool var1564;
ssbool var1565;
ssbool var1566;
ssbool var1567;
ssint var1568;
ssbool var1569;
ssbool var1570;
ssbool var1571;
ssbool var1572;
ssbool var1573;
ssbool var1574;
ssbool var1575;
ssbool var1576;
ssint var1577;
ssbool var1578;
ssbool var1579;
ssbool var1580;
ssbool var1581;
ssbool var1582;
ssbool var1583;
ssbool var1584;
ssbool var1585;
ssint var1586;
ssbool var1587;
ssbool var1588;
ssbool var1589;
ssbool var1590;
ssbool var1591;
ssbool var1592;
ssbool var1593;
ssbool var1594;
ssint var1595;
ssbool var1596;
ssbool var1597;
ssbool var1598;
ssbool var1599;
ssbool var1600;
ssbool var1601;
ssbool var1602;
ssbool var1603;
ssint var1604;
ssbool var1605;
ssbool var1606;
ssbool var1607;
ssbool var1608;
ssbool var1609;
ssbool var1610;
ssbool var1611;
ssbool var1612;
ssint var1613;
ssbool var1614;
ssbool var1615;
ssbool var1616;
ssbool var1617;
ssbool var1618;
ssbool var1619;
ssbool var1620;
ssbool var1621;
ssint var1622;
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
ssbool var1654;
ssbool var1655;
ssbool var1656;
ssbool var1657;
ssbool var1658;
ssfloat var1659;
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
ssbool var1689;
ssbool var1690;
ssbool var1691;
ssbool var1692;
ssbool var1693;
ssfloat var1694;
ssfloat var1695;
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
ssbool var1717;
ssbool var1718;
ssbool var1719;
ssbool var1720;
ssbool var1721;
ssfloat var1722;
ssbool var1723;
ssbool var1724;
ssfloat var1725;
ssbool var1726;
ssbool var1727;
ssfloat var1728;
ssbool var1729;
ssbool var1730;
ssfloat var1731;
ssbool var1732;
ssbool var1733;
ssfloat var1734;
ssbool var1735;
ssbool var1736;
ssfloat var1737;
ssbool var1738;
ssbool var1739;
ssfloat var1740;
ssbool var1741;
ssbool var1742;
ssbool var1743;
ssfloat var1744;
ssbool var1745;
ssbool var1746;
ssbool var1747;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* ���������� �������� */
psbool  array_m170_x_2[17] = {&R0IE02LDU,&R0IE01LDU,&A8IE01LDU,&B6IE01LDU,&R1IE01LDU,&R2IE01LDU,&A5IE02LDU,&B5IE01LDU,&A6IE01LDU,&R6IS62LDU,&R6IS63LDU,&R6IS64LDU,&R6IS65LDU,&R6IS61LDU,&R6IS68LZZ,&R6IS67LZZ,&R6IS66LZZ};
psbool  array_m150_x_2[6] = {&B3IE02LDU,&B1IE02LDU,&B2IE01LDU,&B1IE01LDU,&B3IE01LDU,&B2IE02LDU};
psbool  array_m131_x_2[6] = {&A1IE02LDU,&A2IE02LDU,&A1IE01LDU,&A2IE01LDU,&A3IE01LDU,&A3IE02LDU};
psbool  array_m243_x_2[6] = {&var1706,&var1698,&var1712,&B0VT71LZ1,&B0VT71LZ2,&var1657};
psbool  array_m232_x_2[6] = {&var1707,&var1700,&var1713,&A0VT71LZ1,&A0VT71LZ2,&var1657};
psbool  array_m255_x_2[6] = {&var1691,&B0VP71LZ1,&B0VP71LZ2,&var1662,&var1661,&var1660};
psbool  array_m234_x_2[6] = {&var1692,&A0VP71LZ1,&A0VP71LZ2,&var1665,&var1664,&var1663};
psbool  array_m124_x_2[8] = {&var1724,&var1746,&var1742,&var1739,&var1736,&var1733,&var1727,&var1730};
psbool  array_m2325_x_1[6] = {&var9,&var8,&R0DE36LDU,&R0DE37LDU,&R0DE38LDU,&R0DE39LDU};
psint  array_m2309_x_1[12] = {&R0DE0DLDU,&R0DE0FLDU,&R0DE02LDU,&R0DE03LDU,&R0DE04LDU,&R0DE05LDU,&R0DE07LDU,&R0DE08LDU,&R0DE09LDU,&R0DE0ALDU,&R0DE0BLDU,&R0DE0CLDU};
psbool  array_m812_x_1[6] = {&var602,&var1238,&var1214,&var1203,&var1007,&var90};
psbool  array_m1212_x_1[6] = {&var601,&var1218,&var15,&var1240,&var1007,&var110};
psbool  array_m603_x_1[6] = {&var797,&var1106,&var1525,&var1067,&var1484,&var1100};
psbool  array_m602_x_1[6] = {&var797,&var1107,&var1525,&var1067,&var1484,&var1099};
psfloat  array_m2218_a_1[6] = {&fEM_R0UN70LDU,&fEM_R0UN71LDU,&fEM_R0UN72LDU,&fEM_R0UN73LDU,&fEM_R0UN74LDU,&fEM_R0UN75LDU};
psfloat  array_m2218_b_1[6] = {&fEM_R0UN80LDU,&fEM_R0UN81LDU,&fEM_R0UN82LDU,&fEM_R0UN83LDU,&fEM_R0UN84LDU,&fEM_R0UN85LDU};
psfloat  array_m2229_x_1[4] = {&B0CT01IZ1,&A0CT01IZ1,&B0CT01IZ2,&A0CT01IZ2};
psfloat  array_m2251_x_1[2] = {&R0VN09RZ1,&R0VN09RZ2};
psbool  array_m2220_x_1[14] = {&var202,&var175,&var831,&var236,&var238,&var173,&var1647,&var1227,&var1225,&var1658,&var201,&var190,&var186,&var210};
psbool  array_m1_x_1[47] = {&var1190,&lRM_0_,&var335,&var65,&var485,&var1394,&var720,&R0MD34LP1,&var634,&R0MD34LP1,&var693,&R0MD34LP1,&var927,&R0MD34LP1,&var747,&R0MD34LP1,&var925,&var1421,&A2IS12LDU,&var392,&var1221,&var1114,&var1112,&var1025,&var840,&R0MD34LP1,&var422,&var463,&var1265,&var1575,&R0MD34LP1,&var578,&var569,&var524,&B3IS35LDU,&B3IS35LDU,&var257,&var63,&var496,&var304,&var1626,&var1584,&var1611,&var946,&var1598,&R2IS21LDU,&var176};
psfloat  array_m1478_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psbool  array_m1432_x_1[5] = {&var578,&var577,&var576,&var575,&var574};
psbool  array_m561_x_1[14] = {&var745,&var751,&var752,&var743,&var744,&var929,&var930,&var910,&var909,&var741,&var739,&var747,&var740,&var230};
psfloat  array_m88_x_1[2] = {&R0VN11RZ2,&R0VN11RZ1};
psfloat  array_m90_x_1[8] = {&fEM_R0UN01RDU,&fEM_R0UN02RDU,&fEM_R0UN03RDU,&fEM_R0UN04RDU,&fEM_R0UN05RDU,&fEM_R0UN06RDU,&fEM_R0UN07RDU,&fEM_R0UN08RDU};
psfloat  array_m1072_x_1[2] = {&R0VN11RZ2,&R0VN11RZ1};
psfloat  array_m1222_x_1[8] = {&var1486,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m822_x_1[8] = {&var1445,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m902_x_1[8] = {&var1336,&var199,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m1319_x_1[8] = {&var1304,&var198,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m503_x_1[8] = {&var1365,&var326,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m170_x_1[8] = {&var1398,&var330,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m341_Tpr_1[10] = {&fRM_6_0,&fRM_126_0,&fRM_246_0,&fRM_366_0,&fRM_486_0,&fRM_606_0,&fRM_726_0,&fRM_846_0,&fRM_966_0,&fRM_1200_0};
pschar  array_m341_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m341_rz_1[10];
psbool  array_m345_x_1[5] = {&var1055,&var1056,&var1057,&var1058,&var1059};
psbool  array_m280_x_1[7] = {&var831,&var232,&var1034,&var1031,&var238,&var236,&var234};
psfloat  array_m284_Tpr_1[10] = {&fRM_10_0,&fRM_30_0,&fRM_50_0,&fRM_70_0,&fRM_90_0,&fRM_110_0,&fRM_130_0,&fRM_150_0,&fRM_170_0,&fRM_200_0};
pschar  array_m284_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m284_rz_1[10];
psfloat  array_m1421_Tpr_1[6] = {&fRM_0_5,&fRM_3_5,&fRM_6_5,&fRM_9_5,&fRM_12_5,&fRM_15_5};
pschar  array_m1421_type_1[6] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_6_};
pschar  array_m1421_rz_1[6];
psbool  array_m300_x_1[5] = {&var1077,&var1078,&var1079,&var1080,&var1081};
psbool  array_m1197_x_1[5] = {&var1202,&var814,&var1557,&var1207,&var248};
psbool  array_m1184_x_1[4] = {&var1111,&var1153,&var1027,&var1205};
psfloat  array_m1462_x_1[16] = {&var427,&var436,&fRM_0_,&var433,&fRM_0_,&fRM_0_,&fRM_0_,&var430,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&var440};
psbool  array_m1782_x_1[17] = {&var507,&var508,&var514,&var509,&var505,&var506,&var964,&var510,&var511,&var1254,&var512,&var513,&var1246,&var1247,&var1256,&var242,&var243};
psbool  array_m1424_x_1[5] = {&var419,&var542,&var559,&var560,&var449};
psint  array_m319_x_1[3] = {&var1053,&iRM_0_,&var1075};
psint  array_m310_x_1[3] = {&var1052,&iRM_0_,&var1074};
psbool  array_m605_x_1[5] = {&var780,&var1524,&var1291,&var1008,&var208};
psbool  array_m1383_x_1[8] = {&var664,&var665,&var666,&var661,&var660,&var659,&var925,&var657};
psbool  array_m1318_x_1[3] = {&var92,&lRM_0_,&var91};
psfloat  array_m1320_Lt_fw_1[1] = {&fEM_A3UC81RDU};
psint  array_m1320_Vr_fw_1[1] = {&iEM_A3UV01IDU};
psfloat  array_m1320_Lt_bw_1[1] = {&fEM_A3UC82RDU};
psint  array_m1320_Vr_bw_1[1] = {&iEM_A3UV02IDU};
psfloat  array_m1348_x0_1[60];
psfloat  array_m1348_tim0_1[60];
psbool  array_m971_x_1[8] = {&var679,&var681,&var682,&var674,&var680,&var676,&var927,&var408};
psbool  array_m901_x_1[3] = {&var118,&lRM_0_,&var113};
psfloat  array_m903_Lt_fw_1[1] = {&fEM_A3UC81RDU};
psint  array_m903_Vr_fw_1[1] = {&iEM_A3UV01IDU};
psfloat  array_m903_Lt_bw_1[1] = {&fEM_A3UC82RDU};
psint  array_m903_Vr_bw_1[1] = {&iEM_A3UV02IDU};
psfloat  array_m936_x0_1[60];
psfloat  array_m936_tim0_1[60];
psbool  array_m502_x_1[3] = {&var756,&lRM_0_,&var757};
psfloat  array_m505_Lt_fw_1[2] = {&fEM_A1UC81RDU,&fEM_A1UC82RDU};
psint  array_m505_Vr_fw_1[2] = {&iEM_A1UV01IDU,&iEM_A1UV02IDU};
psfloat  array_m505_Lt_bw_1[1] = {&fEM_A1UC83RDU};
psint  array_m505_Vr_bw_1[1] = {&iEM_A1UV03IDU};
psfloat  array_m532_x0_1[150];
psfloat  array_m532_tim0_1[150];
psbool  array_m244_x_1[12] = {&var725,&var727,&var726,&var723,&var721,&var720,&var719,&var933,&var932,&var714,&var717,&var231};
psbool  array_m169_x_1[3] = {&var903,&lRM_0_,&var904};
psfloat  array_m174_Lt_fw_1[2] = {&fEM_A1UC81RDU,&fEM_A1UC82RDU};
psint  array_m174_Vr_fw_1[2] = {&iEM_A1UV01IDU,&iEM_A1UV02IDU};
psfloat  array_m174_Lt_bw_1[1] = {&fEM_A1UC83RDU};
psint  array_m174_Vr_bw_1[1] = {&iEM_A1UV03IDU};
psfloat  array_m213_x0_1[150];
psfloat  array_m213_tim0_1[150];
psbool  array_m876_x_1[10] = {&var691,&var692,&var698,&var699,&var697,&var695,&var694,&var935,&var934,&var693};
psbool  array_m821_x_1[3] = {&var94,&var709,&var93};
psfloat  array_m823_Lt_fw_1[2] = {&fEM_A2UC81RDU,&fEM_A2UC82RDU};
psint  array_m823_Vr_fw_1[2] = {&iEM_A2UV01IDU,&iEM_A2UV02IDU};
psfloat  array_m823_Lt_bw_1[1] = {&fEM_A2UC83RDU};
psint  array_m823_Vr_bw_1[1] = {&iEM_A2UV03CDU};
psfloat  array_m843_x0_1[80];
psfloat  array_m843_tim0_1[80];
psfloat  array_m1602_Lt_fw_1[1] = {&fRM_1000_};
psint  array_m1602_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1602_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1602_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1293_x_1[10] = {&var630,&var631,&var633,&var632,&var634,&var636,&var638,&var635,&var637,&var639};
psbool  array_m152_x_1[5] = {&A1IS21LDU,&A3IS21LDU,&A2IS21LDU,&var950,&var949};
psfloat  array_m1123_Lt_fw_1[1] = {&fRM_2000_};
psint  array_m1123_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1123_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1123_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1221_x_1[3] = {&var122,&var624,&var109};
psfloat  array_m1223_Lt_fw_1[2] = {&fEM_A2UC81RDU,&fEM_A2UC82RDU};
psint  array_m1223_Vr_fw_1[2] = {&iEM_A2UV01IDU,&iEM_A2UV02IDU};
psfloat  array_m1223_Lt_bw_1[1] = {&fEM_A2UC83RDU};
psint  array_m1223_Vr_bw_1[1] = {&iEM_A2UV03CDU};
psfloat  array_m1257_x0_1[80];
psfloat  array_m1257_tim0_1[80];
psfloat  array_m1622_x0_1[20];
psfloat  array_m1622_tim0_1[20];
psbool  array_m1094_x_1[8] = {&var841,&var838,&var839,&var840,&var837,&var836,&var835,&var834};
psbool  array_m606_x_1[18] = {&R0MD31LP1,&var532,&var855,&var534,&var853,&var625,&var760,&var708,&var735,&var755,&var684,&var649,&var911,&var347,&var346,&var615,&var264,&var200};
psfloat  array_m1147_x0_1[20];
psfloat  array_m1147_tim0_1[20];
psbool  array_m446_x_1[7] = {&var956,&var955,&var954,&var953,&var1628,&var945,&var376};
psbool  array_m428_x_1[7] = {&var958,&var1628,&var946,&var959,&var957,&var944,&var146};
psbool  array_m776_x_1[17] = {&var856,&var901,&var900,&var897,&var896,&var893,&var858,&var895,&var863,&var892,&var888,&var890,&var889,&var860,&var854,&var943,&var711};
psbool  array_m138_x_1[21] = {&var734,&var754,&var999,&var707,&var998,&var997,&var1562,&var1571,&var1589,&var1580,&var1616,&var1607,&var485,&var377,&var989,&var990,&var1268,&var1262,&var1426,&var1417,&var1598};

/* ���������� �������� */
_S_and4  S_and4_106_2 = {&var1743,&var1678,&B8IS11LDU,&B8IS12LDU,&var1648};
_S_lkb  S_lkb_111_2 = {&lRM_1_,&var1676,&var1649};
_S_lkb  S_lkb_107_2 = {&lRM_1_,&var1648,&var1650};
_S_lkb  S_lkb_80_2 = {&lRM_1_,&var1679,&var1651};
_S_lkb  S_lkb_50_2 = {&lRM_1_,&var1684,&var1652};
_S_lkb  S_lkb_83_2 = {&lRM_1_,&var1682,&var1653};
_S_lkb  S_lkb_46_2 = {&lRM_1_,&var1688,&var1654};
_S_lkb  S_lkb_24_2 = {&lRM_1_,&var1686,&var1655};
_S_lkb  S_lkb_20_2 = {&lRM_1_,&var1690,&var1656};
_S_or2  S_or2_258_2 = {&var1747,&var1696,&var1657};
_S_bol  S_bol_223_2 = {&fRM_0_5,&var1659,&var1658};
_S_fsumo  S_fsumo_222_2 = {&var1695,&var1694,&var1659};
_S_noto  S_noto_251_2 = {&B3VP81LDU,&var1660};
_S_noto  S_noto_250_2 = {&B2VP82LDU,&var1661};
_S_noto  S_noto_249_2 = {&B4VP82LDU,&var1662};
_S_noto  S_noto_231_2 = {&A3VP81LDU,&var1663};
_S_noto  S_noto_230_2 = {&A2VP82LDU,&var1664};
_S_noto  S_noto_229_2 = {&A4VP82LDU,&var1665};
_S_schl24  S_schl24_149_2 = {&A0EE02LZ1,&A0EE03LZ1,&A0EE01LZ1,&A0EE04LZ1,&var1666};
_S_schl24  S_schl24_143_2 = {&A0EE03LZ2,&A0EE01LZ2,&A0EE02LZ2,&A0EE04LZ2,&var1667};
_S_or2  S_or2_198_2 = {&var1716,&var1717,&var1668};
_S_or2  S_or2_195_2 = {&var1719,&var1720,&var1669};
_S_and2  S_and2_213_2 = {&var1704,&var1715,&var1670};
_S_or2  S_or2_244_2 = {&var1711,&var1710,&var1671};
_S_and4  S_and4_159_2 = {&A0EE02LZ1,&A0EE04LZ1,&A0EE02LZ2,&A0EE04LZ2,&var1672};
_S_or3  S_or3_158_2 = {&var1672,&var819,&var1666,&var1673};
_S_and4  S_and4_136_2 = {&A0EE03LZ1,&A0EE01LZ1,&A0EE01LZ2,&A0EE03LZ2,&var1674};
_S_or3  S_or3_135_2 = {&var1674,&var1667,&var819,&var1675};
_S_and3  S_and3_110_2 = {&var1677,&var1743,&A8IS12LDU,&var1676};
_S_or2  S_or2_104_2 = {&A8MC01LC2,&A8MC01LC1,&var1677};
_S_or2  S_or2_103_2 = {&B8MC01LC2,&B8MC01LC1,&var1678};
_S_and3  S_and3_79_2 = {&var1743,&B3IS11LDU,&var1680,&var1679};
_S_or2  S_or2_71_2 = {&B3MC01LC2,&B3MC01LC1,&var1680};
_S_or2  S_or2_74_2 = {&A3MC01LC2,&A3MC01LC1,&var1681};
_S_and3  S_and3_82_2 = {&var1743,&var1681,&A3IS11LDU,&var1682};
_S_or2  S_or2_43_2 = {&A2MC01LC2,&A2MC01LC1,&var1683};
_S_and3  S_and3_49_2 = {&var1743,&A2IS11LDU,&var1683,&var1684};
_S_or2  S_or2_13_2 = {&A1MC01LC2,&A1MC01LC1,&var1685};
_S_and3  S_and3_23_2 = {&var1685,&var1743,&A1IS11LDU,&var1686};
_S_or2  S_or2_42_2 = {&B2MC01LC1,&B2MC01LC2,&var1687};
_S_and3  S_and3_45_2 = {&var1743,&B2IS11LDU,&var1687,&var1688};
_S_or2  S_or2_11_2 = {&B1MC01LC2,&B1MC01LC1,&var1689};
_S_and3  S_and3_19_2 = {&var1743,&B1IS11LDU,&var1689,&var1690};
_S_and2  S_and2_254_2 = {&syn_R0EE03LDU,&var1668,&var1691};
_S_and2  S_and2_233_2 = {&syn_R0EE03LDU,&var1669,&var1692};
_S_and2  S_and2_219_2 = {&var1705,&var1714,&var1693};
_S_scalzz  S_scalzz_186_2 = {&B3IP02IDU,&iRM_3276_,&iRM_16383_,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&var1694,&internal2_m186_y0};
_S_scalzz  S_scalzz_184_2 = {&A3IP02IDU,&iRM_3276_,&iRM_16383_,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&var1695,&internal2_m184_y0};
_S_noto  S_noto_171_2 = {&var1697,&var1696};
_S_andn  S_andn_170_2 = {array_m170_x_2,&iRM_17_,&var1697};
_S_noto  S_noto_153_2 = {&var1699,&var1698};
_S_andn  S_andn_150_2 = {array_m150_x_2,&iRM_6_,&var1699};
_S_noto  S_noto_134_2 = {&var1701,&var1700};
_S_andn  S_andn_131_2 = {array_m131_x_2,&iRM_6_,&var1701};
_S_noto  S_noto_253_2 = {&var1710,&var1702};
_S_noto  S_noto_235_2 = {&var1711,&var1703};
_S_noto  S_noto_212_2 = {&var1719,&var1704};
_S_noto  S_noto_220_2 = {&var1716,&var1705};
_S_noto  S_noto_157_2 = {&var1673,&var1706};
_S_noto  S_noto_141_2 = {&var1675,&var1707};
_S_noto  S_noto_256_2 = {&var1712,&var1708};
_S_noto  S_noto_240_2 = {&var1713,&var1709};
_S_ornc  S_ornc_243_2 = {array_m243_x_2,&iRM_6_,&var1710,&vainSChar};
_S_ornc  S_ornc_232_2 = {array_m232_x_2,&iRM_6_,&var1711,&vainSChar};
_S_ornc  S_ornc_255_2 = {array_m255_x_2,&iRM_6_,&var1712,&vainSChar};
_S_ornc  S_ornc_234_2 = {array_m234_x_2,&iRM_6_,&var1713,&vainSChar};
_S_tprg  S_tprg_216_2 = {&var1694,&fEM_A3UP85RDU,&fEM_A3UP86RDU,&fEM_A3UP87RDU,&fEM_A3UP88RDU,&var1714,&internal2_m216_y0};
_S_tprg  S_tprg_210_2 = {&var1695,&fEM_A3UP85RDU,&fEM_A3UP86RDU,&fEM_A3UP87RDU,&fEM_A3UP88RDU,&var1715,&internal2_m210_y0};
_S_geterr  S_geterr_191_2 = {&var1694,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var1716};
_S_drg  S_drg_199_2 = {&var1694,&lRM_1_,&lRM_0_,&fEM_A3UP43RDU,&fEM_A3UP44RDU,&var1717,&internal2_m199_y1};
_S_drg  S_drg_206_2 = {&var1694,&lRM_1_,&lRM_0_,&fEM_A3UP53RDU,&fEM_A3UP54RDU,&var1718,&internal2_m206_y1};
_S_geterr  S_geterr_188_2 = {&var1695,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var1719};
_S_drg  S_drg_189_2 = {&var1695,&lRM_1_,&lRM_0_,&fEM_A3UP43RDU,&fEM_A3UP44RDU,&var1720,&internal2_m189_y1};
_S_drg  S_drg_196_2 = {&var1695,&lRM_1_,&lRM_0_,&fEM_A3UP53RDU,&fEM_A3UP54RDU,&var1721,&internal2_m196_y1};
_S_enctkb  S_enctkb_16_2 = {&var1655,&fRM_0_0,&A1IC01UDU,&dEM_A1UC06UDU,&dEM_A1UC05UDU,&fEM_A1UC03RDU,&fRM_100_,&dRM_0_,&var1722,&var1723,&var1724,&internal2_m16_Nk0,&internal2_m16_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_108_2 = {&var1650,&fRM_390_,&B8IC01UDU,&dEM_A8UC06UDU,&dEM_A8UC05UDU,&fEM_A8UC03RDU,&fRM_1500_0,&dRM_0_,&var1725,&var1726,&var1727,&internal2_m108_Nk0,&internal2_m108_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_112_2 = {&var1649,&fRM_390_0,&A8IC01UDU,&dEM_A8UC06UDU,&dEM_A8UC05UDU,&fEM_A8UC03RDU,&fRM_1500_0,&dRM_0_,&var1728,&var1729,&var1730,&internal2_m112_Nk0,&internal2_m112_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_75_2 = {&var1651,&fRM_0_,&B3IC01UDU,&dEM_A3UC06UDU,&dEM_A3UC05UDU,&fEM_A3UC03RDU,&fRM_0_0,&dRM_0_,&var1731,&var1732,&var1733,&internal2_m75_Nk0,&internal2_m75_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_77_2 = {&var1653,&fRM_0_0,&A3IC01UDU,&dEM_A3UC06UDU,&dEM_A3UC05UDU,&fEM_A3UC03RDU,&fRM_0_0,&dRM_0_,&var1734,&var1735,&var1736,&internal2_m77_Nk0,&internal2_m77_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_47_2 = {&var1654,&fRM_0_0,&B2IC01UDU,&dEM_A2UC06UDU,&dEM_A2UC05UDU,&fEM_A2UC03RDU,&fRM_100_,&dRM_0_,&var1737,&var1738,&var1739,&internal2_m47_Nk0,&internal2_m47_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_51_2 = {&var1652,&fRM_0_0,&A2IC01UDU,&dEM_A2UC06UDU,&dEM_A2UC05UDU,&fEM_A2UC03RDU,&fRM_100_,&dRM_0_,&var1740,&var1741,&var1742,&internal2_m51_Nk0,&internal2_m51_SetFlag,&bFirstEnterFlag};
_S_equz_p  S_equz_p_18_2 = {&R0MW12IP1,&iRM_4_,&var1743};
_S_enctkb  S_enctkb_21_2 = {&var1656,&fRM_0_0,&B1IC01UDU,&dEM_A1UC06UDU,&dEM_A1UC05UDU,&fEM_A1UC03RDU,&fRM_100_,&dRM_0_,&var1744,&var1745,&var1746,&internal2_m21_Nk0,&internal2_m21_SetFlag,&bFirstEnterFlag};
_S_ornc  S_ornc_124_2 = {array_m124_x_2,&iRM_8_,&var1747,&vainSChar};
_S_zapomni  S_zapomni_198_1 = {&var733,&internal1_m198_s,&var1};
_S_zapomni  S_zapomni_195_1 = {&var732,&internal1_m195_s,&var2};
_S_zapomni  S_zapomni_189_1 = {&var1412,&internal1_m189_s,&var3};
_S_zapomni  S_zapomni_182_1 = {&var734,&internal1_m182_s,&var4};
_S_zapomni  S_zapomni_179_1 = {&var715,&internal1_m179_s,&var5};
_S_or3  S_or3_2326_1 = {&var7,&var10,&var11,&var6};
_S_orn  S_orn_2325_1 = {array_m2325_x_1,&iRM_6_,&var7};
_S_or2  S_or2_2330_1 = {&R0DEB3LDU,&R0DEB4LDU,&var8};
_S_or2  S_or2_2323_1 = {&R0DEB1LDU,&R0DEB2LDU,&var9};
_S_and2  S_and2_2314_1 = {&R0DE31LDU,&R0DE32LDU,&var10};
_S_diagndev  S_diagndev_2309_1 = {array_m2309_x_1,&iRM_12_,&var11,&var12};
_S_or2  S_or2_1708_1 = {&var250,&var63,&var13};
_S_and2  S_and2_1698_1 = {&var306,&var1211,&var14};
_S_rs  S_rs_1707_1 = {&var13,&var14,&var15,&vainSBool,&internal1_m1707_q0};
_S_or2  S_or2_1702_1 = {&var306,&var253,&var16};
_S_or2  S_or2_1643_1 = {&var1261,&var306,&var17};
_S_noto  S_noto_1686_1 = {&B2IS11LDU,&var18};
_S_or2  S_or2_1671_1 = {&var21,&var63,&var19};
_S_or2  S_or2_1673_1 = {&var133,&var63,&var20};
_S_noto  S_noto_1684_1 = {&A2IS11LDU,&var21};
_S_or2  S_or2_2147_1 = {&var250,&var59,&var22};
_S_or2  S_or2_2145_1 = {&var59,&var257,&var23};
_S_or2  S_or2_2143_1 = {&var72,&var59,&var24};
_S_and2  S_and2_2126_1 = {&var1208,&var304,&var25};
_S_or2  S_or2_2141_1 = {&var27,&var59,&var26};
_S_noto  S_noto_2150_1 = {&B3IS11LDU,&var27};
_S_or2  S_or2_2177_1 = {&var63,&var257,&var28};
_S_and2  S_and2_2157_1 = {&var1208,&var305,&var29};
_S_noto  S_noto_2182_1 = {&A3IS11LDU,&var30};
_S_or2  S_or2_2179_1 = {&var250,&var63,&var31};
_S_or2  S_or2_2175_1 = {&var63,&var73,&var32};
_S_or2  S_or2_2173_1 = {&var63,&var30,&var33};
_S_or2  S_or2_1651_1 = {&var250,&var63,&var34};
_S_or2  S_or2_1655_1 = {&var250,&var59,&var35};
_S_or2  S_or2_1646_1 = {&var306,&var1261,&var36};
_S_or2  S_or2_1681_1 = {&var59,&var132,&var37};
_S_or2  S_or2_1679_1 = {&var18,&var59,&var38};
_S_or2  S_or2_1724_1 = {&var257,&var59,&var39};
_S_or2  S_or2_1721_1 = {&var257,&var63,&var40};
_S_or2  S_or2_1753_1 = {&var263,&var59,&var41};
_S_or2  S_or2_1750_1 = {&var263,&var63,&var42};
_S_or2  S_or2_1710_1 = {&var250,&var59,&var43};
_S_or2  S_or2_1675_1 = {&var250,&var63,&var44};
_S_or2  S_or2_1683_1 = {&var250,&var59,&var45};
_S_or3  S_or3_2137_1 = {&var257,&var304,&var59,&var46};
_S_or3  S_or3_2139_1 = {&var82,&var304,&var59,&var47};
_S_or3  S_or3_2171_1 = {&var63,&var85,&var305,&var48};
_S_or3  S_or3_2169_1 = {&var257,&var63,&var305,&var49};
_S_or3  S_or3_2135_1 = {&var304,&var250,&var59,&var50};
_S_or3  S_or3_2167_1 = {&var250,&var305,&var63,&var51};
_S_or3  S_or3_1649_1 = {&var250,&var305,&var63,&var52};
_S_or3  S_or3_1653_1 = {&var304,&var250,&var59,&var53};
_S_or3  S_or3_1669_1 = {&var250,&var305,&var63,&var54};
_S_or3  S_or3_1677_1 = {&var250,&var304,&var59,&var55};
_S_or3  S_or3_1706_1 = {&var250,&var306,&var59,&var56};
_S_or3  S_or3_1704_1 = {&var250,&var63,&var306,&var57};
_S_or3  S_or3_1752_1 = {&var59,&var304,&var263,&var58};
_S_noto  S_noto_1747_1 = {&var916,&var59};
_S_or3  S_or3_1723_1 = {&var59,&var257,&var304,&var60};
_S_or3  S_or3_1720_1 = {&var257,&var63,&var305,&var61};
_S_or3  S_or3_1749_1 = {&var263,&var63,&var305,&var62};
_S_noto  S_noto_1746_1 = {&var915,&var63};
_S_regch  S_regch_131_1 = {&R0MW12IP1,&var905,&var64};
_S_or2  S_or2_134_1 = {&var66,&var64,&var65};
_S_or2  S_or2_133_1 = {&R0VZ71LZ1,&R0VZ71LZ2,&var66};
_S_and3  S_and3_1416_1 = {&R0MD11LP2,&var964,&var70,&var67};
_S_and2  S_and2_739_1 = {&R4MD21LP2,&var70,&var68};
_S_and2  S_and2_736_1 = {&R4MD11LP2,&var70,&var69};
_S_noto  S_noto_113_1 = {&var1638,&var70};
_S_and2  S_and2_111_1 = {&R0MD11LP1,&var70,&var71};
_S_noto  S_noto_2151_1 = {&B3IS22LDU,&var72};
_S_noto  S_noto_2183_1 = {&A3IS22LDU,&var73};
_S_and2  S_and2_2074_1 = {&var481,&var1190,&var74};
_S_or3  S_or3_2069_1 = {&var480,&var176,&var114,&var75};
_S_and2  S_and2_2059_1 = {&var477,&var1190,&var76};
_S_or3  S_or3_2055_1 = {&var176,&var478,&var97,&var77};
_S_or2  S_or2_1481_1 = {&var1279,&var1208,&var78};
_S_or2  S_or2_1450_1 = {&var1136,&var1208,&var79};
_S_rs  S_rs_2140_1 = {&var26,&var83,&var80,&vainSBool,&internal1_m2140_q0};
_S_rs  S_rs_2124_1 = {&var26,&var102,&var81,&vainSBool,&internal1_m2124_q0};
_S_noto  S_noto_2148_1 = {&syn_B3VP52LDU,&var82};
_S_and2  S_and2_2131_1 = {&var82,&var81,&var83};
_S_rs  S_rs_2172_1 = {&var33,&var86,&var84,&vainSBool,&internal1_m2172_q0};
_S_noto  S_noto_2180_1 = {&syn_A3VP52LDU,&var85};
_S_and2  S_and2_2163_1 = {&var87,&var85,&var86};
_S_rs  S_rs_2156_1 = {&var33,&var120,&var87,&vainSBool,&internal1_m2156_q0};
_S_and4  S_and4_1371_1 = {&var964,&var1208,&var268,&var1253,&var88};
_S_and4  S_and4_959_1 = {&var964,&var1208,&var268,&var1253,&var89};
_S_rs  S_rs_2146_1 = {&var22,&var95,&var90,&vainSBool,&internal1_m2146_q0};
_S_or4  S_or4_1308_1 = {&var600,&var290,&var1003,&var97,&var91};
_S_or4  S_or4_1317_1 = {&var165,&var293,&var776,&var103,&var92};
_S_orn  S_orn_812_1 = {array_m812_x_1,&iRM_6_,&var93};
_S_or3  S_or3_824_1 = {&var795,&var1204,&var106,&var94};
_S_and2  S_and2_2133_1 = {&var257,&var96,&var95};
_S_rs  S_rs_2127_1 = {&var22,&var98,&var96,&vainSBool,&internal1_m2127_q0};
_S_rs  S_rs_2144_1 = {&var98,&var23,&var97,&vainSBool,&internal1_m2144_q0};
_S_and2  S_and2_2132_1 = {&var99,&var72,&var98};
_S_rs  S_rs_2125_1 = {&var23,&var25,&var99,&vainSBool,&internal1_m2125_q0};
_S_rs  S_rs_2123_1 = {&var47,&var104,&var100,&vainSBool,&internal1_m2123_q0};
_S_rs  S_rs_2122_1 = {&var46,&var105,&var101,&vainSBool,&internal1_m2122_q0};
_S_and2  S_and2_2130_1 = {&var257,&var100,&var102};
_S_rs  S_rs_2136_1 = {&var46,&var104,&var103,&vainSBool,&internal1_m2136_q0};
_S_and2  S_and2_2129_1 = {&var101,&var250,&var104};
_S_and2  S_and2_2128_1 = {&var307,&var1208,&var105};
_S_rs  S_rs_2134_1 = {&var50,&var105,&var106,&vainSBool,&internal1_m2134_q0};
_S_rs  S_rs_2142_1 = {&var25,&var24,&var107,&vainSBool,&internal1_m2142_q0};
_S_rs  S_rs_2138_1 = {&var47,&var102,&var108,&vainSBool,&internal1_m2138_q0};
_S_orn  S_orn_1212_1 = {array_m1212_x_1,&iRM_6_,&var109};
_S_rs  S_rs_2178_1 = {&var31,&var111,&var110,&vainSBool,&internal1_m2178_q0};
_S_and2  S_and2_2165_1 = {&var257,&var112,&var111};
_S_rs  S_rs_2159_1 = {&var31,&var115,&var112,&vainSBool,&internal1_m2159_q0};
_S_or4  S_or4_891_1 = {&var599,&var294,&var1003,&var114,&var113};
_S_rs  S_rs_2176_1 = {&var28,&var115,&var114,&vainSBool,&internal1_m2176_q0};
_S_and2  S_and2_2164_1 = {&var116,&var73,&var115};
_S_rs  S_rs_2158_1 = {&var28,&var29,&var116,&vainSBool,&internal1_m2158_q0};
_S_rs  S_rs_2155_1 = {&var48,&var123,&var117,&vainSBool,&internal1_m2155_q0};
_S_or4  S_or4_900_1 = {&var1201,&var165,&var786,&var121,&var118};
_S_rs  S_rs_2154_1 = {&var49,&var124,&var119,&vainSBool,&internal1_m2154_q0};
_S_and2  S_and2_2162_1 = {&var257,&var117,&var120};
_S_rs  S_rs_2168_1 = {&var49,&var123,&var121,&vainSBool,&internal1_m2168_q0};
_S_or3  S_or3_1224_1 = {&var794,&var1206,&var125,&var122};
_S_and2  S_and2_2161_1 = {&var119,&var250,&var123};
_S_and2  S_and2_2160_1 = {&var308,&var1208,&var124};
_S_rs  S_rs_2166_1 = {&var51,&var124,&var125,&vainSBool,&internal1_m2166_q0};
_S_or2  S_or2_2041_1 = {&var167,&var1035,&var126};
_S_ovbs  S_ovbs_2043_1 = {&var226,&fRM_2_0,&var127,&internal1_m2043_tx};
_S_or2  S_or2_2044_1 = {&var1217,&var127,&var128};
_S_ovbs  S_ovbs_2022_1 = {&var227,&fRM_2_0,&var129,&internal1_m2022_tx};
_S_or2  S_or2_2020_1 = {&var168,&var1036,&var130};
_S_or2  S_or2_2023_1 = {&var1237,&var129,&var131};
_S_noto  S_noto_1687_1 = {&B2IS21LDU,&var132};
_S_noto  S_noto_1685_1 = {&A2IS21LDU,&var133};
_S_and2  S_and2_2094_1 = {&syn_B3VP52LDU,&var482,&var134};
_S_or5  S_or5_2097_1 = {&var657,&var1647,&var151,&var107,&var134,&var135};
_S_or5  S_or5_2096_1 = {&var408,&var1199,&var484,&var1647,&syn_A3VP52LDU,&var136};
_S_and2  S_and2_2071_1 = {&syn_A3VP52LDU,&var483,&var137};
_S_nocnm  S_nocnm_1729_1 = {&R5IS21LDU,&R5IS11LDU,&var138,&var139,&var140,&internal1_m1729_Pv0,&internal1_m1729_Zv0,&internal1_m1729_MyFirstEnterFlag,&bFirstEnterFlag};
_S_nocnm  S_nocnm_1728_1 = {&R3IS11LDU,&R3IS21LDU,&var141,&var142,&var143,&internal1_m1728_Pv0,&internal1_m1728_Zv0,&internal1_m1728_MyFirstEnterFlag,&bFirstEnterFlag};
_S_or5  S_or5_1991_1 = {&var999,&var707,&C2MD31LP1,&var998,&var997,&var144};
_S_or4  S_or4_1967_1 = {&C1MD31LP2,&C1MD31LP1,&var734,&var754,&var145};
_S_and3  S_and3_424_1 = {&B8IS22LDU,&B8IS21LDU,&var1620,&var146};
_S_and2  S_and2_2057_1 = {&var476,&var176,&var147};
_S_and2  S_and2_2068_1 = {&var479,&var176,&var148};
_S_or4  S_or4_991_1 = {&var1326,&var669,&var668,&var671,&var149};
_S_or4  S_or4_1403_1 = {&var1294,&var650,&var651,&var654,&var150};
_S_and2  S_and2_2098_1 = {&var397,&var1190,&var151};
_S_and2  S_and2_2083_1 = {&var482,&var1647,&var152};
_S_and2  S_and2_2072_1 = {&var483,&var1647,&var153};
_S_or2  S_or2_563_1 = {&B1VP41LZ2,&B1VP41LZ1,&var154};
_S_or2  S_or2_246_1 = {&A1VP41LZ2,&A1VP41LZ1,&var155};
_S_or2  S_or2_1127_1 = {&B8IS22LDU,&B8IS21LDU,&var156};
_S_or2  S_or2_1120_1 = {&B8IS11LDU,&B8IS12LDU,&var157};
_S_or2  S_or2_365_1 = {&R4IS11LDU,&R4IS12LDU,&var158};
_S_or2  S_or2_382_1 = {&R4IS21LDU,&R4IS22LDU,&var159};
_S_or2  S_or2_1079_1 = {&var1006,&R0MD34LP1,&var160};
_S_or2  S_or2_1082_1 = {&var1004,&R0MD34LP1,&var161};
_S_or2  S_or2_1085_1 = {&var1002,&R0MD34LP1,&var162};
_S_or2  S_or2_1088_1 = {&var1000,&R0MD34LP1,&var163};
_S_noto  S_noto_2208_1 = {&var1647,&var164};
_S_zzfs  S_zzfs_2198_1 = {&var182,&fRM_0_5,&var165,&internal1_m2198_tx,&internal1_m2198_y0};
_S_or2  S_or2_2231_1 = {&var358,&var1008,&var166};
_S_andn  S_andn_603_1 = {array_m603_x_1,&iRM_6_,&var167};
_S_andn  S_andn_602_1 = {array_m602_x_1,&iRM_6_,&var168};
_S_or2  S_or2_2247_1 = {&var684,&var649,&var169};
_S_noto  S_noto_2193_1 = {&var1034,&var170};
_S_noto  S_noto_2192_1 = {&var1031,&var171};
_S_zpfs  S_zpfs_2201_1 = {&var170,&fRM_30_0,&var172,&internal1_m2201_tx,&internal1_m2201_y0};
_S_noto  S_noto_2206_1 = {&var172,&var173};
_S_zpfs  S_zpfs_2200_1 = {&var171,&fRM_30_0,&var174,&internal1_m2200_tx,&internal1_m2200_y0};
_S_noto  S_noto_2205_1 = {&var174,&var175};
_S_and3  S_and3_2195_1 = {&var215,&var195,&lRM_1_,&var176};
_S_and2  S_and2_920_1 = {&var1352,&var178,&var177};
_S_noto  S_noto_906_1 = {&var165,&var178};
_S_and2  S_and2_1334_1 = {&var1320,&var180,&var179};
_S_noto  S_noto_1331_1 = {&var165,&var180};
_S_or2  S_or2_2241_1 = {&var191,&var192,&var181};
_S_and2  S_and2_2197_1 = {&var183,&var176,&var182};
_S_abs_subf  S_abs_subf_2188_1 = {&var1734,&var216,&fEM_A3UC08RDU,&vainSFloat,&var183};
_S_and2  S_and2_2243_1 = {&var176,&var191,&var184};
_S_or4  S_or4_1992_1 = {&var144,&var812,&var922,&var184,&var185};
_S_noto  S_noto_2246_1 = {&var169,&var186};
_S_or2  S_or2_2223_1 = {&var209,&var220,&var187};
_S_inf  S_inf_2218_1 = {&var218,array_m2218_a_1,array_m2218_b_1,&iRM_6_,&var188,&vainSInt};
_S_or3  S_or3_2245_1 = {&var205,&var212,&var213,&var189};
_S_noto  S_noto_2244_1 = {&var189,&var190};
_S_noto  S_noto_2242_1 = {&var215,&var191};
_S_ovbs  S_ovbs_2237_1 = {&var194,&fRM_15_0,&var192,&internal1_m2237_tx};
_S_zpfs  S_zpfs_2235_1 = {&var195,&fRM_10_0,&var193,&internal1_m2235_tx,&internal1_m2235_y0};
_S_and2  S_and2_2236_1 = {&var193,&R0MW17LP1,&var194};
_S_rs  S_rs_2240_1 = {&var181,&R0MW17LP1,&var195,&vainSBool,&internal1_m2240_q0};
_S_rs  S_rs_2207_1 = {&var209,&var176,&var196,&vainSBool,&internal1_m2207_q0};
_S_and3  S_and3_2214_1 = {&var211,&var164,&var196,&var197};
_S_ml  S_ml_1312_1 = {&var216,&var318,&var165,&var198};
_S_ml  S_ml_894_1 = {&var216,&var322,&var165,&var199};
_S_and2  S_and2_2261_1 = {&var176,&var335,&var200};
_S_noto  S_noto_2228_1 = {&var166,&var201};
_S_noto  S_noto_2212_1 = {&var1291,&var202};
_S_sr  S_sr_2229_1 = {array_m2229_x_1,&iRM_4_,&var203};
_S_sr  S_sr_2251_1 = {array_m2251_x_1,&iRM_2_,&var204};
_S_and2  S_and2_2265_1 = {&var206,&var176,&var205};
_S_abs_subf  S_abs_subf_2260_1 = {&B3MC01RP1,&A3MC01RP1,&fRM_0_01,&vainSFloat,&var206};
_S_fsumo  S_fsumo_86_1 = {&var984,&fEM_R0UN11RDU,&var207};
_S_or3  S_or3_132_1 = {&var145,&var65,&var187,&var208};
_S_ovbs  S_ovbs_2215_1 = {&var197,&fRM_1_0,&var209,&internal1_m2215_tx};
_S_noto  S_noto_2222_1 = {&var187,&var210};
_S_rs  S_rs_2213_1 = {&var209,&var1647,&var211,&vainSBool,&internal1_m2213_q0};
_S_and2  S_and2_2264_1 = {&var220,&var176,&var212};
_S_and2  S_and2_2263_1 = {&var214,&var176,&var213};
_S_bol  S_bol_2254_1 = {&fEM_R0UN09RDU,&var204,&var214};
_S_andn  S_andn_2220_1 = {array_m2220_x_1,&iRM_14_,&var215};
_S_irm  S_irm_2196_1 = {&var984,&var982,&B3MC01RP1,&var1734,&var204,&var203,&var176,&var1008,&fEM_R0UN12RDU,&fEM_R0UN13RDU,&fEM_R0UN14RDU,&fEM_R0UT20RDU,&var188,&fEM_R0UN15RDU,&fEM_R0UN25RDU,&fEM_R0UN16RDU,&fEM_R0UN17RDU,&fEM_R0UN18RDU,&fEM_R0UN19RDU,&fEM_R0UN27RDU,&fEM_R0UN26RDU,&fEM_R0UN24RDU,&var216,&var217,&var218,&var219,&var220,&var221,&var222,&var223};
_S_noto  S_noto_2049_1 = {&var346,&var224};
_S_noto  S_noto_2019_1 = {&var347,&var225};
_S_and4  S_and4_2042_1 = {&var369,&var126,&var339,&var224,&var226};
_S_and4  S_and4_2021_1 = {&var370,&var130,&var339,&var225,&var227};
_S_zpfs  S_zpfs_2037_1 = {&var353,&fRM_210_0,&var228,&internal1_m2037_tx,&internal1_m2037_y0};
_S_zpfs  S_zpfs_2029_1 = {&var354,&fRM_210_0,&var229,&internal1_m2029_tx,&internal1_m2029_y0};
_S_and2  S_and2_566_1 = {&var1367,&var402,&var230};
_S_and2  S_and2_249_1 = {&var402,&var1400,&var231};
_S_noto  S_noto_1571_1 = {&var233,&var232};
_S_abs_subf  S_abs_subf_1562_1 = {&var1731,&var318,&fEM_A3UC07RDU,&vainSFloat,&var233};
_S_noto  S_noto_1552_1 = {&var235,&var234};
_S_abs_subf  S_abs_subf_1540_1 = {&var322,&var1734,&fEM_A3UC07RDU,&vainSFloat,&var235};
_S_noto  S_noto_1566_1 = {&var237,&var236};
_S_abs_subf  S_abs_subf_1560_1 = {&var326,&var1744,&fEM_A1UC07RDU,&vainSFloat,&var237};
_S_noto  S_noto_1547_1 = {&var239,&var238};
_S_abs_subf  S_abs_subf_1539_1 = {&var330,&var1722,&fEM_A1UC07RDU,&vainSFloat,&var239};
_S_bol  S_bol_1330_1 = {&var1731,&fEM_A3UC09RDU,&var240};
_S_bol  S_bol_916_1 = {&var1734,&fEM_A3UC09RDU,&var241};
_S_noto  S_noto_1794_1 = {&var246,&var242};
_S_noto  S_noto_1783_1 = {&var244,&var243};
_S_and3  S_and3_1776_1 = {&var916,&var245,&var1208,&var244};
_S_bol  S_bol_1768_1 = {&fRM_55_0,&var318,&var245};
_S_and3  S_and3_1795_1 = {&var247,&var915,&var1208,&var246};
_S_bol  S_bol_1804_1 = {&fRM_55_0,&var322,&var247};
_S_and4  S_and4_51_1 = {&var1638,&var914,&var1093,&var1190,&var248};
_S_noto  S_noto_1248_1 = {&var964,&var249};
_S_and2  S_and2_1250_1 = {&var1467,&var964,&var250};
_S_and2  S_and2_1244_1 = {&var1467,&var249,&var251};
_S_noto  S_noto_1193_1 = {&var964,&var252};
_S_and2  S_and2_1196_1 = {&var964,&var1541,&var253};
_S_and2  S_and2_1194_1 = {&var1541,&var252,&var254};
_S_noto  S_noto_925_1 = {&var964,&var255};
_S_and2  S_and2_926_1 = {&var255,&var1323,&var256};
_S_and2  S_and2_922_1 = {&var1323,&var964,&var257};
_S_noto  S_noto_477_1 = {&var964,&var258};
_S_and2  S_and2_478_1 = {&var258,&var1416,&var259};
_S_and2  S_and2_481_1 = {&var1416,&var964,&var260};
_S_noto  S_noto_205_1 = {&var964,&var261};
_S_and2  S_and2_206_1 = {&var261,&var1386,&var262};
_S_and2  S_and2_210_1 = {&var964,&var1386,&var263};
_S_and2  S_and2_127_1 = {&var266,&var391,&var264};
_S_and2  S_and2_128_1 = {&var964,&var391,&var265};
_S_noto  S_noto_122_1 = {&var964,&var266};
_S_and2  S_and2_123_1 = {&var266,&var390,&var267};
_S_and2  S_and2_124_1 = {&var964,&var390,&var268};
_S_and2  S_and2_1641_1 = {&var304,&var1212,&var269};
_S_and2  S_and2_1640_1 = {&var307,&var1212,&var270};
_S_and2  S_and2_1639_1 = {&var305,&var1212,&var271};
_S_and2  S_and2_1638_1 = {&var1212,&var308,&var272};
_S_and2  S_and2_1637_1 = {&var525,&var306,&var273};
_S_and2  S_and2_1636_1 = {&var525,&var309,&var274};
_S_and2  S_and2_1635_1 = {&var526,&var306,&var275};
_S_and2  S_and2_1634_1 = {&var526,&var309,&var276};
_S_and2  S_and2_1667_1 = {&var37,&var1169,&var277};
_S_and2  S_and2_1666_1 = {&var304,&var1213,&var278};
_S_and2  S_and2_1665_1 = {&var1170,&var304,&var279};
_S_and2  S_and2_1664_1 = {&var1213,&var307,&var280};
_S_and2  S_and2_1663_1 = {&var133,&var1171,&var281};
_S_and2  S_and2_1662_1 = {&var1213,&var305,&var282};
_S_and2  S_and2_1661_1 = {&var1172,&var250,&var283};
_S_and2  S_and2_1660_1 = {&var1213,&var308,&var284};
_S_and2  S_and2_1700_1 = {&var250,&var1173,&var285};
_S_and2  S_and2_1699_1 = {&var306,&var1211,&var286};
_S_and2  S_and2_1697_1 = {&var1174,&var253,&var287};
_S_and2  S_and2_1696_1 = {&var1175,&var253,&var288};
_S_and2  S_and2_1695_1 = {&var309,&var1211,&var289};
_S_rs  S_rs_1717_1 = {&var39,&var291,&var290,&vainSBool,&internal1_m1717_q0};
_S_and2  S_and2_1716_1 = {&var1209,&var304,&var291};
_S_and2  S_and2_1715_1 = {&var1209,&var307,&var292};
_S_rs  S_rs_1722_1 = {&var60,&var292,&var293,&vainSBool,&internal1_m1722_q0};
_S_rs  S_rs_1714_1 = {&var40,&var295,&var294,&vainSBool,&internal1_m1714_q0};
_S_and2  S_and2_1713_1 = {&var305,&var1209,&var295};
_S_and2  S_and2_1712_1 = {&var1209,&var308,&var296};
_S_and2  S_and2_1745_1 = {&var306,&var1640,&var297};
_S_rs  S_rs_1756_1 = {&var260,&var297,&var298,&vainSBool,&internal1_m1756_q0};
_S_and2  S_and2_1744_1 = {&var1640,&var309,&var299};
_S_and2  S_and2_1742_1 = {&var304,&var1197,&var300};
_S_and2  S_and2_1741_1 = {&var1197,&var307,&var301};
_S_and2  S_and2_1739_1 = {&var305,&var1197,&var302};
_S_and2  S_and2_1738_1 = {&var1197,&var308,&var303};
_S_and2  S_and2_1758_1 = {&var916,&var306,&var304};
_S_and2  S_and2_1737_1 = {&var915,&var306,&var305};
_S_and2  S_and2_1760_1 = {&var265,&var1253,&var306};
_S_and2  S_and2_1757_1 = {&var309,&var916,&var307};
_S_and2  S_and2_1736_1 = {&var309,&var915,&var308};
_S_and2  S_and2_1759_1 = {&var268,&var1253,&var309};
_S_zpfs  S_zpfs_756_1 = {&var880,&fRM_3_,&var310,&internal1_m756_tx,&internal1_m756_y0};
_S_or4  S_or4_1581_1 = {&var516,&var517,&var518,&var520,&var311};
_S_or5  S_or5_1572_1 = {&var524,&var523,&var522,&var521,&var311,&var312};
_S_andn  S_andn_1_1 = {array_m1_x_1,&iRM_47_,&vainSBool};
_S_or2  S_or2_1554_1 = {&var315,&var316,&var313};
_S_ml  S_ml_1538_1 = {&fRM_1500_0,&B8MC01RP2,&var313,&var314};
_S_bol  S_bol_1544_1 = {&B8MC01RP2,&fRM_1500_0001,&var315};
_S_bol  S_bol_1555_1 = {&fRM_389_99,&B8MC01RP2,&var316};
_S_or2  S_or2_1569_1 = {&var319,&var320,&var317};
_S_ml  S_ml_1559_1 = {&fRM_0_0,&B3MC01RP1,&var317,&var318};
_S_bol  S_bol_1561_1 = {&B3MC01RP1,&fRM_160_00001,&var319};
_S_bol  S_bol_1570_1 = {&fRM_0_0001,&B3MC01RP1,&var320};
_S_or2  S_or2_1550_1 = {&var323,&var324,&var321};
_S_ml  S_ml_1537_1 = {&fRM_0_0,&A3MC01RP1,&var321,&var322};
_S_bol  S_bol_1543_1 = {&A3MC01RP1,&fRM_160_0001,&var323};
_S_bol  S_bol_1551_1 = {&fRM_0_0001,&A3MC01RP1,&var324};
_S_or2  S_or2_1565_1 = {&var327,&var328,&var325};
_S_ml  S_ml_1557_1 = {&fRM_100_0,&B1MC01RP1,&var325,&var326};
_S_bol  S_bol_1563_1 = {&B1MC01RP1,&fRM_100_0001,&var327};
_S_bol  S_bol_1567_1 = {&fRM_0_0001,&B1MC01RP1,&var328};
_S_or2  S_or2_1546_1 = {&var331,&var332,&var329};
_S_ml  S_ml_1535_1 = {&fRM_100_0,&A1MC01RP1,&var329,&var330};
_S_bol  S_bol_1542_1 = {&A1MC01RP1,&fRM_100_0001,&var331};
_S_bol  S_bol_1548_1 = {&fRM_0_0001,&A1MC01RP1,&var332};
_S_and2  S_and2_108_1 = {&var71,&var158,&var333};
_S_noto  S_noto_109_1 = {&var158,&var334};
_S_and2  S_and2_112_1 = {&var71,&var334,&var335};
_S_and2  S_and2_2008_1 = {&var337,&var338,&var336};
_S_or3  S_or3_2007_1 = {&var1215,&var469,&var185,&var337};
_S_noto  S_noto_2045_1 = {&var128,&var338};
_S_noto  S_noto_2034_1 = {&var340,&var339};
_S_ovbs  S_ovbs_2033_1 = {&var1105,&fRM_2_0,&var340,&internal1_m2033_tx};
_S_noto  S_noto_2024_1 = {&var131,&var341};
_S_and2  S_and2_1994_1 = {&var343,&var341,&var342};
_S_or3  S_or3_1993_1 = {&var185,&var1219,&var469,&var343};
_S_noto  S_noto_2039_1 = {&var351,&var344};
_S_and2  S_and2_2040_1 = {&var1190,&var344,&var345};
_S_and2  S_and2_2048_1 = {&var345,&var126,&var346};
_S_and2  S_and2_2027_1 = {&var348,&var130,&var347};
_S_and2  S_and2_2032_1 = {&var349,&var1190,&var348};
_S_noto  S_noto_2031_1 = {&var907,&var349};
_S_noto  S_noto_2047_1 = {&var353,&var350};
_S_or2  S_or2_2038_1 = {&var228,&var350,&var351};
_S_noto  S_noto_2026_1 = {&var354,&var352};
_S_rs  S_rs_2036_1 = {&var228,&var359,&var353,&vainSBool,&internal1_m2036_q0};
_S_rs  S_rs_2028_1 = {&var229,&var360,&var354,&vainSBool,&internal1_m2028_q0};
_S_and2  S_and2_2017_1 = {&var357,&var364,&var355};
_S_and2  S_and2_2005_1 = {&var357,&var361,&var356};
_S_noto  S_noto_1999_1 = {&var358,&var357};
_S_ovbs  S_ovbs_1998_1 = {&var185,&fRM_10_0,&var358,&internal1_m1998_tx};
_S_ovbs  S_ovbs_2009_1 = {&var336,&fRM_2_0,&var359,&internal1_m2009_tx};
_S_ovbs  S_ovbs_1995_1 = {&var342,&fRM_2_0,&var360,&internal1_m1995_tx};
_S_or2  S_or2_2004_1 = {&var392,&var969,&var361};
_S_or2  S_or2_2000_1 = {&var393,&var342,&var362};
_S_or2  S_or2_2012_1 = {&var393,&var336,&var363};
_S_or2  S_or2_2016_1 = {&var392,&var966,&var364};
_S_rs  S_rs_2001_1 = {&var356,&var362,&var365,&vainSBool,&internal1_m2001_q0};
_S_noto  S_noto_2014_1 = {&var367,&var366};
_S_rs  S_rs_2013_1 = {&var355,&var363,&var367,&vainSBool,&internal1_m2013_q0};
_S_noto  S_noto_2002_1 = {&var365,&var368};
_S_noto  S_noto_2010_1 = {&var359,&var369};
_S_noto  S_noto_1996_1 = {&var360,&var370};
_S_and2  S_and2_1989_1 = {&var373,&var475,&var371};
_S_and2  S_and2_1978_1 = {&var373,&var472,&var372};
_S_noto  S_noto_1972_1 = {&var374,&var373};
_S_ovbs  S_ovbs_1971_1 = {&var145,&fRM_3_0,&var374,&internal1_m1971_tx};
_S_or2  S_or2_1493_1 = {&var1139,&lRM_0_,&var375};
_S_and2  S_and2_449_1 = {&var1612,&var1554,&var376};
_S_and2  S_and2_1857_1 = {&var1164,&B7AS31LDU,&var377};
_S_and2  S_and2_460_1 = {&var915,&var761,&var378};
_S_and2  S_and2_456_1 = {&var762,&var915,&var379};
_S_and2  S_and2_489_1 = {&var761,&var916,&var380};
_S_and2  S_and2_485_1 = {&var762,&var916,&var381};
_S_or2  S_or2_376_1 = {&var1625,&var887,&var382};
_S_or2  S_or2_372_1 = {&var1625,&var886,&var383};
_S_ovbs  S_ovbs_57_1 = {&var1637,&fRM_15_0,&var384,&internal1_m57_tx};
_S_ovbs  S_ovbs_353_1 = {&var1112,&fRM_0_02,&var385,&internal1_m353_tx};
_S_ovbs  S_ovbs_307_1 = {&var1114,&fRM_0_02,&var386,&internal1_m307_tx};
_S_ovbs  S_ovbs_757_1 = {&var310,&fRM_0_2,&var387,&internal1_m757_tx};
_S_ovbs  S_ovbs_1437_1 = {&R0MD31LP1,&fRM_10_0,&var388,&internal1_m1437_tx};
_S_ovbs  S_ovbs_119_1 = {&R0MD31LP1,&fRM_0_15,&var389,&internal1_m119_tx};
_S_ovbs  S_ovbs_121_1 = {&var335,&fRM_0_02,&var390,&internal1_m121_tx};
_S_ovbs  S_ovbs_126_1 = {&R0MD32LP1,&fRM_0_02,&var391,&internal1_m126_tx};
_S_ovbs  S_ovbs_24_1 = {&var1190,&fRM_3_0,&var392,&internal1_m24_tx};
_S_ovbs  S_ovbs_16_1 = {&var964,&fRM_3_0,&var393,&internal1_m16_tx};
_S_ovbs  S_ovbs_1980_1 = {&var145,&fRM_2_0,&var394,&internal1_m1980_tx};
_S_ovbs  S_ovbs_1968_1 = {&var145,&fRM_2_0,&var395,&internal1_m1968_tx};
_S_ovbs  S_ovbs_2076_1 = {&var1199,&fRM_2_0,&var396,&internal1_m2076_tx};
_S_ovbs  S_ovbs_2080_1 = {&var107,&fRM_2_0,&var397,&internal1_m2080_tx};
_S_ovbs  S_ovbs_1893_1 = {&var410,&fRM_0_01,&var398,&internal1_m1893_tx};
_S_ovbs  S_ovbs_83_1 = {&R0MW13LP2,&fRM_10_0,&var399,&internal1_m83_tx};
_S_zpfs  S_zpfs_322_1 = {&var818,&fRM_10_0,&var400,&internal1_m322_tx,&internal1_m322_y0};
_S_or2  S_or2_1038_1 = {&var1025,&var588,&var401};
_S_or2  S_or2_250_1 = {&A1VN71LZ1,&A1VN71LZ2,&var402};
_S_or2  S_or2_265_1 = {&var713,&var981,&var403};
_S_or5  S_or5_153_1 = {&B1IS21LDU,&B3IS21LDU,&B2IS21LDU,&var951,&var952,&var404};
_S_and2  S_and2_1035_1 = {&var1462,&var1096,&var405};
_S_or3  S_or3_993_1 = {&var149,&var673,&var672,&var406};
_S_or3  S_or3_1405_1 = {&var656,&var655,&var150,&var407};
_S_and2  S_and2_974_1 = {&var1227,&var1010,&var408};
_S_and3  S_and3_1888_1 = {&var426,&var411,&var419,&var409};
_S_or2  S_or2_1892_1 = {&var413,&var412,&var410};
_S_or3  S_or3_1890_1 = {&var413,&var412,&var422,&var411};
_S_zpfs  S_zpfs_1887_1 = {&var415,&fEM_R0UL02RDU,&var412,&internal1_m1887_tx,&internal1_m1887_y0};
_S_zpfs  S_zpfs_1885_1 = {&var416,&fEM_R0UL02RDU,&var413,&internal1_m1885_tx,&internal1_m1885_y0};
_S_or2  S_or2_1879_1 = {&var416,&var415,&var414};
_S_or2  S_or2_1880_1 = {&var417,&var1129,&var415};
_S_or2  S_or2_1878_1 = {&var418,&var1129,&var416};
_S_and3  S_and3_1872_1 = {&var1186,&var938,&var916,&var417};
_S_and3  S_and3_1871_1 = {&var1187,&var915,&var938,&var418};
_S_or2  S_or2_1869_1 = {&var1129,&var1128,&var419};
_S_or3  S_or3_1876_1 = {&var424,&var1128,&var422,&var420};
_S_and2  S_and2_1884_1 = {&var1129,&var411,&var421};
_S_and2  S_and2_1875_1 = {&var1120,&var423,&var422};
_S_zpfs  S_zpfs_1874_1 = {&var1129,&fEM_R0UL04RDU,&var423,&internal1_m1874_tx,&internal1_m1874_y0};
_S_and2  S_and2_1862_1 = {&var1123,&var572,&var424};
_S_or3  S_or3_1863_1 = {&var1077,&var578,&var1055,&var425};
_S_abs_subf  S_abs_subf_1896_1 = {&fEM_R0UL02RDU,&var427,&fEM_R0UL16RDU,&vainSFloat,&var426};
_S_rsfn  S_rsfn_1894_1 = {&var569,&var428,&var427,&internal1_m1894_q0};
_S_lk  S_lk_1891_1 = {&var1282,&var411,&var428};
_S_abs_subf  S_abs_subf_1466_1 = {&fEM_R0UL05RDU,&var430,&fEM_R0UL18RDU,&vainSFloat,&var429};
_S_rsfn  S_rsfn_1457_1 = {&var569,&var431,&var430,&internal1_m1457_q0};
_S_lk  S_lk_1461_1 = {&var1134,&var556,&var431};
_S_abs_subf  S_abs_subf_1508_1 = {&fEM_R0UL07RDU,&var433,&fEM_R0UL20RDU,&vainSFloat,&var432};
_S_rsfn  S_rsfn_1496_1 = {&var569,&var434,&var433,&internal1_m1496_q0};
_S_lk  S_lk_1499_1 = {&var1140,&var546,&var434};
_S_ma  S_ma_1478_1 = {array_m1478_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_abs_subf  S_abs_subf_1513_1 = {&fEM_R0UL25RDU,&var436,&fEM_R0UL19RDU,&vainSFloat,&var435};
_S_rsfn  S_rsfn_1494_1 = {&var569,&var437,&var436,&internal1_m1494_q0};
_S_lk  S_lk_1502_1 = {&var1280,&var537,&var437};
_S_and3  S_and3_1938_1 = {&var439,&var442,&var449,&var438};
_S_abs_subf  S_abs_subf_1935_1 = {&var440,&fEM_R0UL03RDU,&fEM_R0UL17RDU,&vainSFloat,&var439};
_S_rsfn  S_rsfn_1933_1 = {&var569,&var441,&var440,&internal1_m1933_q0};
_S_lk  S_lk_1928_1 = {&var1281,&var442,&var441};
_S_or3  S_or3_1927_1 = {&var447,&var453,&var452,&var442};
_S_and4  S_and4_1932_1 = {&var452,&var1287,&var465,&var463,&var443};
_S_and4  S_and4_1930_1 = {&var453,&var1287,&var465,&var463,&var444};
_S_and2  S_and2_1922_1 = {&var1132,&var442,&var445};
_S_and2  S_and2_1908_1 = {&var572,&var1122,&var446};
_S_and2  S_and2_1912_1 = {&var450,&var1121,&var447};
_S_or3  S_or3_1913_1 = {&var447,&var446,&var1131,&var448};
_S_or2  S_or2_1904_1 = {&var1132,&var1131,&var449};
_S_zpfs  S_zpfs_1911_1 = {&var1132,&fEM_R0UL21RDU,&var450,&internal1_m1911_tx,&internal1_m1911_y0};
_S_or3  S_or3_1901_1 = {&var574,&var1081,&var1059,&var451};
_S_zpfs  S_zpfs_1926_1 = {&var455,&fEM_R0UL03RDU,&var452,&internal1_m1926_tx,&internal1_m1926_y0};
_S_zpfs  S_zpfs_1923_1 = {&var456,&fEM_R0UL03RDU,&var453,&internal1_m1923_tx,&internal1_m1923_y0};
_S_or2  S_or2_1920_1 = {&var456,&var455,&var454};
_S_or2  S_or2_1921_1 = {&var457,&var1132,&var455};
_S_or2  S_or2_1919_1 = {&var458,&var1132,&var456};
_S_and4  S_and4_1916_1 = {&var1188,&var916,&B2IS12LDU,&var459,&var457};
_S_and4  S_and4_1910_1 = {&var1189,&A2IS12LDU,&var915,&var459,&var458};
_S_and2  S_and2_1909_1 = {&var938,&var463,&var459};
_S_and3  S_and3_1947_1 = {&var916,&var1043,&var462,&var460};
_S_and3  S_and3_1946_1 = {&var915,&var1044,&var462,&var461};
_S_and4  S_and4_1945_1 = {&var1009,&var808,&var810,&var463,&var462};
_S_and2  S_and2_1939_1 = {&var821,&var1010,&var463};
_S_or2  S_or2_1941_1 = {&var1291,&var1008,&var464};
_S_or3  S_or3_1950_1 = {&var468,&var467,&var470,&var465};
_S_and2  S_and2_1940_1 = {&var1047,&A2IS12LDU,&var466};
_S_and2  S_and2_1944_1 = {&var948,&var466,&var467};
_S_and3  S_and3_1949_1 = {&var1286,&var471,&var466,&var468};
_S_or2  S_or2_1958_1 = {&lRM_0_,&var464,&var469};
_S_and2  S_and2_1955_1 = {&var963,&var471,&var470};
_S_and2  S_and2_1957_1 = {&var1046,&B2IS12LDU,&var471};
_S_or2  S_or2_1977_1 = {&var968,&var392,&var472};
_S_or2  S_or2_1973_1 = {&var393,&var145,&var473};
_S_or2  S_or2_1984_1 = {&var145,&var393,&var474};
_S_or2  S_or2_1988_1 = {&var392,&var967,&var475};
_S_or2  S_or2_2051_1 = {&var816,&var1200,&var476};
_S_or2  S_or2_2058_1 = {&var1010,&var1221,&var477};
_S_zpfs  S_zpfs_2060_1 = {&var76,&fRM_15_0,&var478,&internal1_m2060_tx,&internal1_m2060_y0};
_S_or2  S_or2_2063_1 = {&var815,&var108,&var479};
_S_zpfs  S_zpfs_2070_1 = {&var74,&fRM_15_0,&var480,&internal1_m2070_tx,&internal1_m2070_y0};
_S_or2  S_or2_2073_1 = {&var1010,&var1220,&var481};
_S_or2  S_or2_2089_1 = {&var80,&var443,&var482};
_S_or2  S_or2_2084_1 = {&var444,&var84,&var483};
_S_and2  S_and2_2095_1 = {&var1190,&var396,&var484};
_S_and2  S_and2_1856_1 = {&var1165,&A7AS31LDU,&var485};
_S_or3  S_or3_1829_1 = {&var490,&var494,&var492,&var486};
_S_or3  S_or3_1831_1 = {&var493,&var492,&var489,&var487};
_S_or2  S_or2_1843_1 = {&B0VT71LZ1,&B0VT71LZ2,&var488};
_S_and2  S_and2_1834_1 = {&var495,&var488,&var489};
_S_and2  S_and2_1828_1 = {&var495,&var491,&var490};
_S_or2  S_or2_1827_1 = {&A0VT71LZ1,&A0VT71LZ2,&var491};
_S_zpfs  S_zpfs_1824_1 = {&var1182,&fRM_2_5,&var492,&internal1_m1824_tx,&internal1_m1824_y0};
_S_zpfs  S_zpfs_1823_1 = {&var1183,&fRM_2_5,&var493,&internal1_m1823_tx,&internal1_m1823_y0};
_S_zpfs  S_zpfs_1822_1 = {&var1184,&fRM_2_5,&var494,&internal1_m1822_tx,&internal1_m1822_y0};
_S_zpfs  S_zpfs_1821_1 = {&var1185,&fRM_2_5,&var495,&internal1_m1821_tx,&internal1_m1821_y0};
_S_or2  S_or2_1852_1 = {&R0VP73LZ2,&R0VP73LZ1,&var496};
_S_and2  S_and2_1846_1 = {&var107,&var1166,&var497};
_S_or2  S_or2_1842_1 = {&var500,&var497,&var498};
_S_or2  S_or2_1844_1 = {&var80,&var107,&var499};
_S_and2  S_and2_1841_1 = {&var80,&var1156,&var500};
_S_and2  S_and2_1825_1 = {&var1199,&var1167,&var501};
_S_or2  S_or2_1826_1 = {&var504,&var501,&var502};
_S_or2  S_or2_1819_1 = {&var84,&var1199,&var503};
_S_and2  S_and2_1818_1 = {&var84,&var1157,&var504};
_S_or3  S_or3_1788_1 = {&var1250,&var1208,&var1209,&var505};
_S_or3  S_or3_1789_1 = {&var1248,&var1208,&var1209,&var506};
_S_or2  S_or2_1780_1 = {&var1243,&var1208,&var507};
_S_or2  S_or2_1781_1 = {&var1242,&var1208,&var508};
_S_or2  S_or2_1787_1 = {&var1252,&var1211,&var509};
_S_or4  S_or4_1785_1 = {&var1211,&var1249,&var1212,&var1213,&var510};
_S_or4  S_or4_1784_1 = {&var1211,&var1255,&var1212,&var1213,&var511};
_S_or2  S_or2_1778_1 = {&var1244,&var1213,&var512};
_S_or2  S_or2_1777_1 = {&var1245,&var1213,&var513};
_S_or2  S_or2_1786_1 = {&var1211,&var1251,&var514};
_S_or2  S_or2_1755_1 = {&var260,&var306,&var515};
_S_and2  S_and2_1586_1 = {&var1505,&var1463,&var516};
_S_and2  S_and2_1585_1 = {&var1628,&var1463,&var517};
_S_and2  S_and2_1584_1 = {&var905,&var1463,&var518};
_S_or2  S_or2_1583_1 = {&B4IS11LDU,&A4IS11LDU,&var519};
_S_and2  S_and2_1582_1 = {&var519,&var1463,&var520};
_S_and2  S_and2_1576_1 = {&var1671,&var1463,&var521};
_S_and2  S_and2_1575_1 = {&var158,&var1463,&var522};
_S_and2  S_and2_1574_1 = {&var894,&var1463,&var523};
_S_and2  S_and2_1573_1 = {&R3IS21LDU,&var1463,&var524};
_S_or2  S_or2_1633_1 = {&var1641,&var1642,&var525};
_S_or2  S_or2_1632_1 = {&var1643,&var1641,&var526};
_S_or2  S_or2_2109_1 = {&var987,&R0MD34LP1,&var527};
_S_or3  S_or3_2115_1 = {&var1262,&var1264,&var1263,&var528};
_S_or3  S_or3_2106_1 = {&var1268,&var1270,&var1269,&var529};
_S_or2  S_or2_1621_1 = {&var1729,&var1463,&var530};
_S_or2  S_or2_1595_1 = {&var1506,&var1096,&var531};
_S_or5  S_or5_1132_1 = {&var1521,&var533,&var1532,&var1518,&var1519,&var532};
_S_or3  S_or3_1136_1 = {&var1526,&var1527,&var990,&var533};
_S_or5  S_or5_1609_1 = {&var312,&var535,&var1515,&var1507,&var1508,&var534};
_S_or3  S_or3_1612_1 = {&var989,&var1509,&var1510,&var535};
_S_and3  S_and3_1522_1 = {&var537,&var542,&var435,&var536};
_S_and2  S_and2_1525_1 = {&var538,&var1279,&var537};
_S_or3  S_or3_1524_1 = {&A3VZ13LZ2,&A3VZ13LZ1,&var541,&var538};
_S_zpfs  S_zpfs_1509_1 = {&var1279,&fRM_0_2,&var539,&internal1_m1509_tx,&internal1_m1509_y0};
_S_or3  S_or3_1511_1 = {&var1142,&var541,&var543,&var540};
_S_and2  S_and2_1510_1 = {&var1119,&var539,&var541};
_S_or2  S_or2_1500_1 = {&var1279,&var1142,&var542};
_S_and2  S_and2_1488_1 = {&var1124,&var572,&var543};
_S_or3  S_or3_1497_1 = {&var1056,&var1078,&var577,&var544};
_S_or3  S_or3_1518_1 = {&R0AD14LZ1,&R0AD14LZ2,&var548,&var545};
_S_and2  S_and2_1519_1 = {&var545,&var1139,&var546};
_S_zpfs  S_zpfs_1503_1 = {&var1139,&fEM_R0UL06RDU,&var547,&internal1_m1503_tx,&internal1_m1503_y0};
_S_and2  S_and2_1504_1 = {&var547,&var1118,&var548};
_S_or3  S_or3_1505_1 = {&var1137,&var548,&var551,&var549};
_S_or3  S_or3_1480_1 = {&var576,&var1079,&var1057,&var550};
_S_and2  S_and2_1483_1 = {&var1125,&var572,&var551};
_S_and3  S_and3_1521_1 = {&var432,&var546,&var559,&var552};
_S_zpfs  S_zpfs_1453_1 = {&var1136,&fEM_R0UL04RDU,&var553,&internal1_m1453_tx,&internal1_m1453_y0};
_S_and2  S_and2_1454_1 = {&var553,&var1117,&var554};
_S_and3  S_and3_1470_1 = {&var429,&var556,&var560,&var555};
_S_and2  S_and2_1464_1 = {&var557,&var1136,&var556};
_S_or3  S_or3_1463_1 = {&A3VZ15LZ1,&A3VZ15LZ2,&var554,&var557};
_S_or3  S_or3_1455_1 = {&var561,&var554,&var1135,&var558};
_S_or2  S_or2_1491_1 = {&var1139,&var1137,&var559};
_S_or2  S_or2_1451_1 = {&var1136,&var1135,&var560};
_S_and2  S_and2_1443_1 = {&var1126,&var572,&var561};
_S_or3  S_or3_1441_1 = {&var1058,&var1080,&var575,&var562};
_S_or2  S_or2_1415_1 = {&var1634,&var564,&var563};
_S_and2  S_and2_1414_1 = {&var565,&var1180,&var564};
_S_or2  S_or2_1413_1 = {&var961,&var913,&var565};
_S_or2  S_or2_1410_1 = {&var1051,&var1073,&var566};
_S_and2  S_and2_1408_1 = {&var1145,&var1146,&var567};
_S_and2  S_and2_1411_1 = {&var566,&var565,&var568};
_S_or5  S_or5_1412_1 = {&var386,&var385,&var567,&var568,&R0MD34LP1,&var569};
_S_orni  S_orni_1432_1 = {array_m1432_x_1,&iRM_5_,&var570,&var571};
_S_or5  S_or5_1434_1 = {&var1141,&var1116,&var569,&var1061,&var388,&var572};
_S_and2  S_and2_1433_1 = {&var570,&var1274,&var573};
_S_or2  S_or2_1440_1 = {&var1088,&var579,&var574};
_S_or2  S_or2_1436_1 = {&var1087,&var580,&var575};
_S_or2  S_or2_1430_1 = {&var1086,&var581,&var576};
_S_or2  S_or2_1428_1 = {&var1085,&var582,&var577};
_S_or2  S_or2_1426_1 = {&var1084,&var583,&var578};
_S_and2  S_and2_1439_1 = {&var1629,&var584,&var579};
_S_and2  S_and2_1435_1 = {&var1630,&var584,&var580};
_S_and2  S_and2_1429_1 = {&var1631,&var584,&var581};
_S_and2  S_and2_1427_1 = {&var1632,&var584,&var582};
_S_and2  S_and2_1425_1 = {&var1633,&var584,&var583};
_S_and2  S_and2_1419_1 = {&var1634,&var67,&var584};
_S_and3  S_and3_1068_1 = {&var254,&var589,&var607,&var585};
_S_or2  S_or2_1033_1 = {&var1098,&var1094,&var586};
_S_or2  S_or2_1059_1 = {&var1094,&var1028,&var587};
_S_and2  S_and2_1026_1 = {&var1472,&var1095,&var588};
_S_and2  S_and2_1022_1 = {&var1291,&var609,&var589};
_S_or3  S_or3_1030_1 = {&var1094,&var1024,&var1097,&var590};
_S_and2  S_and2_1034_1 = {&var251,&var1291,&var591};
_S_and2  S_and2_1051_1 = {&var262,&var1291,&var592};
_S_and2  S_and2_1067_1 = {&var256,&var1291,&var593};
_S_and2  S_and2_1074_1 = {&var259,&var1291,&var594};
_S_and3  S_and3_1017_1 = {&var597,&var1013,&var1291,&var595};
_S_and3  S_and3_1011_1 = {&var598,&var1013,&var1291,&var596};
_S_and2  S_and2_1019_1 = {&var915,&var1290,&var597};
_S_and2  S_and2_1009_1 = {&var916,&var1290,&var598};
_S_and4  S_and4_1018_1 = {&var597,&var1291,&var1021,&var1011,&var599};
_S_and4  S_and4_1012_1 = {&var598,&var1291,&var1021,&var1011,&var600};
_S_and4  S_and4_1016_1 = {&var1291,&var597,&var605,&var1012,&var601};
_S_and4  S_and4_1010_1 = {&var1291,&var598,&var605,&var1012,&var602};
_S_and2  S_and2_1003_1 = {&var1022,&var1291,&var603};
_S_or4  S_or4_1006_1 = {&R0MD31LP1,&var1525,&var267,&var616,&var604};
_S_and3  S_and3_1052_1 = {&var1023,&var1022,&var1021,&var605};
_S_and2  S_and2_1039_1 = {&var607,&var401,&var606};
_S_and2  S_and2_1042_1 = {&var1020,&var605,&var607};
_S_or2  S_or2_1053_1 = {&var1090,&var1032,&var608};
_S_and2  S_and2_1061_1 = {&var610,&var608,&var609};
_S_or2  S_or2_1054_1 = {&var1031,&var1033,&var610};
_S_or2  S_or2_1055_1 = {&var1030,&var1031,&var611};
_S_or2  S_or2_1057_1 = {&var1029,&var1034,&var612};
_S_and2  S_and2_1058_1 = {&var611,&var612,&var613};
_S_or2  S_or2_1045_1 = {&var1090,&var1089,&var614};
_S_and2  S_and2_1046_1 = {&var614,&var1026,&var615};
_S_and5  S_and5_999_1 = {&var617,&var1110,&var1031,&var1090,&var606,&var616};
_S_and2  S_and2_1000_1 = {&var1065,&var1066,&var617};
_S_and2  S_and2_1262_1 = {&var1159,&var619,&var618};
_S_or2  S_or2_1256_1 = {&A2MD12LP1,&var620,&var619};
_S_and2  S_and2_1247_1 = {&A2MD11LP1,&var1176,&var620};
_S_or2  S_or2_1238_1 = {&var623,&B2MD12LP1,&var621};
_S_and2  S_and2_1242_1 = {&var621,&var1159,&var622};
_S_and2  S_and2_1232_1 = {&B2MD11LP1,&var1177,&var623};
_S_or3  S_or3_1220_1 = {&var1241,&var1236,&var779,&var624};
_S_or5  S_or5_1235_1 = {&var627,&var999,&var1502,&var1496,&var1497,&var625};
_S_or2  S_or2_1255_1 = {&var1741,&var1487,&var626};
_S_or3  S_or3_1307_1 = {&var1468,&var628,&var629,&var627};
_S_and2  S_and2_1302_1 = {&var1487,&var962,&var628};
_S_and2  S_and2_1301_1 = {&var912,&var1487,&var629};
_S_and3  S_and3_1300_1 = {&var404,&var948,&var644,&var630};
_S_and2  S_and2_1299_1 = {&var158,&var644,&var631};
_S_and3  S_and3_1295_1 = {&var937,&var983,&var644,&var632};
_S_and2  S_and2_1294_1 = {&var496,&var644,&var633};
_S_and2  S_and2_1282_1 = {&var1478,&var644,&var634};
_S_and2  S_and2_1269_1 = {&var1671,&var644,&var635};
_S_and2  S_and2_1284_1 = {&var65,&var644,&var636};
_S_and2  S_and2_1270_1 = {&R3IS21LDU,&var644,&var637};
_S_and2  S_and2_1285_1 = {&var640,&var644,&var638};
_S_and3  S_and3_1271_1 = {&var641,&var1477,&var644,&var639};
_S_or2  S_or2_1286_1 = {&var1470,&var1471,&var640};
_S_or2  S_or2_1272_1 = {&A4IS11LDU,&B4IS11LDU,&var641};
_S_and3  S_and3_1281_1 = {&var1211,&var268,&var964,&var642};
_S_and3  S_and3_1280_1 = {&var1213,&var268,&var964,&var643};
_S_or3  S_or3_1274_1 = {&var1488,&var643,&var642,&var644};
_S_and2  S_and2_1357_1 = {&var646,&var1159,&var645};
_S_or2  S_or2_1355_1 = {&var647,&B3MD12LP1,&var646};
_S_and2  S_and2_1344_1 = {&B3MD11LP1,&var1155,&var647};
_S_or2  S_or2_1347_1 = {&var1732,&var1305,&var648};
_S_or5  S_or5_1333_1 = {&var407,&var1315,&var1314,&var179,&var997,&var649};
_S_and2  S_and2_1393_1 = {&var1305,&var962,&var650};
_S_and2  S_and2_1392_1 = {&var1305,&var912,&var651};
_S_and2  S_and2_1401_1 = {&var978,&var1293,&var652};
_S_or2  S_or2_1396_1 = {&var652,&var979,&var653};
_S_and3  S_and3_1391_1 = {&var1168,&var653,&var662,&var654};
_S_and3  S_and3_1390_1 = {&var404,&var963,&var662,&var655};
_S_and2  S_and2_1389_1 = {&var158,&var662,&var656};
_S_and2  S_and2_1386_1 = {&var1225,&var1010,&var657};
_S_or2  S_or2_1376_1 = {&var1296,&var1295,&var658};
_S_and2  S_and2_1375_1 = {&var658,&var662,&var659};
_S_and2  S_and2_1374_1 = {&var65,&var662,&var660};
_S_and2  S_and2_1372_1 = {&var1298,&var662,&var661};
_S_or2  S_or2_1365_1 = {&var1307,&var88,&var662};
_S_or2  S_or2_1363_1 = {&B4IS11LDU,&A4IS11LDU,&var663};
_S_and3  S_and3_1362_1 = {&var1297,&var663,&var662,&var664};
_S_and2  S_and2_1361_1 = {&R3IS21LDU,&var662,&var665};
_S_and2  S_and2_1360_1 = {&var1671,&var662,&var666};
_S_and2  S_and2_989_1 = {&var976,&var1325,&var667};
_S_and2  S_and2_980_1 = {&var912,&var1337,&var668};
_S_and2  S_and2_981_1 = {&var962,&var1337,&var669};
_S_or2  S_or2_984_1 = {&var977,&var667,&var670};
_S_and3  S_and3_979_1 = {&var1168,&var670,&var677,&var671};
_S_and3  S_and3_978_1 = {&var948,&var404,&var677,&var672};
_S_and2  S_and2_977_1 = {&var158,&var677,&var673};
_S_and2  S_and2_960_1 = {&var1330,&var677,&var674};
_S_or2  S_or2_964_1 = {&var1328,&var1327,&var675};
_S_and2  S_and2_963_1 = {&var675,&var677,&var676};
_S_or2  S_or2_951_1 = {&var1339,&var89,&var677};
_S_or2  S_or2_952_1 = {&B4IS11LDU,&A4IS11LDU,&var678};
_S_and3  S_and3_950_1 = {&var678,&var1329,&var677,&var679};
_S_and2  S_and2_962_1 = {&var65,&var677,&var680};
_S_and2  S_and2_949_1 = {&R3IS21LDU,&var677,&var681};
_S_and2  S_and2_948_1 = {&var1671,&var677,&var682};
_S_or2  S_or2_935_1 = {&var1337,&var1735,&var683};
_S_or5  S_or5_919_1 = {&var406,&var998,&var177,&var1346,&var1347,&var684};
_S_and2  S_and2_946_1 = {&var1159,&var686,&var685};
_S_or2  S_or2_943_1 = {&var687,&A3MD12LP1,&var686};
_S_and2  S_and2_932_1 = {&A3MD11LP1,&var1210,&var687};
_S_or3  S_or3_890_1 = {&var1435,&var690,&var689,&var688};
_S_and2  S_and2_884_1 = {&var1446,&var912,&var689};
_S_and2  S_and2_885_1 = {&var1446,&var962,&var690};
_S_and3  S_and3_883_1 = {&var1469,&var963,&var702,&var691};
_S_and2  S_and2_882_1 = {&var158,&var702,&var692};
_S_and2  S_and2_865_1 = {&var1439,&var702,&var693};
_S_and2  S_and2_867_1 = {&var65,&var702,&var694};
_S_and2  S_and2_868_1 = {&var696,&var702,&var695};
_S_or2  S_or2_869_1 = {&var1437,&var1436,&var696};
_S_and2  S_and2_852_1 = {&var1671,&var702,&var697};
_S_and3  S_and3_854_1 = {&var1438,&var703,&var702,&var698};
_S_and2  S_and2_853_1 = {&R3IS21LDU,&var702,&var699};
_S_and3  S_and3_864_1 = {&var1211,&var268,&var964,&var700};
_S_and3  S_and3_863_1 = {&var268,&var1213,&var964,&var701};
_S_or3  S_or3_857_1 = {&var1447,&var700,&var701,&var702};
_S_or2  S_or2_855_1 = {&B4IS11LDU,&A4IS11LDU,&var703};
_S_or2  S_or2_842_1 = {&var1738,&var1446,&var704};
_S_zpfs  S_zpfs_838_1 = {&var1460,&fRM_3_0,&var705,&internal1_m838_tx,&internal1_m838_y0};
_S_zpfs  S_zpfs_837_1 = {&var1461,&fRM_2_0,&var706,&internal1_m837_tx,&internal1_m837_y0};
_S_zpfs  S_zpfs_844_1 = {&var1458,&fEM_A2UL83RDU,&var707,&internal1_m844_tx,&internal1_m844_y0};
_S_or5  S_or5_832_1 = {&var688,&var707,&var1459,&var706,&var705,&var708};
_S_or3  S_or3_820_1 = {&var1216,&var1239,&var774,&var709};
_S_or4  S_or4_805_1 = {&var1582,&var1580,&var1581,&var1583,&var710};
_S_or2  S_or2_796_1 = {&var712,&var710,&var711};
_S_or4  S_or4_789_1 = {&var1591,&var1590,&var1589,&var1592,&var712};
_S_and2  S_and2_270_1 = {&var980,&var1385,&var713};
_S_and3  S_and3_259_1 = {&var948,&var404,&var1400,&var714};
_S_or3  S_or3_272_1 = {&var718,&var716,&var1388,&var715};
_S_and2  S_and2_262_1 = {&var1399,&var962,&var716};
_S_and3  S_and3_260_1 = {&var403,&var1168,&var1400,&var717};
_S_and2  S_and2_261_1 = {&var912,&var1399,&var718};
_S_and2  S_and2_258_1 = {&var158,&var1400,&var719};
_S_and2  S_and2_233_1 = {&var1392,&var1400,&var720};
_S_and2  S_and2_235_1 = {&var65,&var1400,&var721};
_S_or2  S_or2_237_1 = {&var1389,&var1390,&var722};
_S_and2  S_and2_236_1 = {&var722,&var1400,&var723};
_S_or2  S_or2_226_1 = {&B4IS11LDU,&A4IS11LDU,&var724};
_S_and3  S_and3_225_1 = {&var1391,&var724,&var1400,&var725};
_S_and2  S_and2_223_1 = {&var1671,&var1400,&var726};
_S_and2  S_and2_224_1 = {&R3IS21LDU,&var1400,&var727};
_S_and2  S_and2_200_1 = {&var1159,&var730,&var728};
_S_and2  S_and2_186_1 = {&A1MD11LP1,&var1198,&var729};
_S_or2  S_or2_196_1 = {&A1MD12LP1,&var729,&var730};
_S_or2  S_or2_212_1 = {&var1399,&var1723,&var731};
_S_zpfs  S_zpfs_203_1 = {&var1414,&fRM_2_0,&var732,&internal1_m203_tx,&internal1_m203_y0};
_S_zpfs  S_zpfs_207_1 = {&var1413,&fRM_2_0,&var733,&internal1_m207_tx,&internal1_m207_y0};
_S_zpfs  S_zpfs_214_1 = {&var1411,&fEM_A1UL03RDU,&var734,&internal1_m214_tx,&internal1_m214_y0};
_S_or5  S_or5_192_1 = {&var715,&var734,&var733,&var732,&var1412,&var735};
_S_orn  S_orn_561_1 = {array_m561_x_1,&iRM_14_,&var736};
_S_and2  S_and2_584_1 = {&var1355,&var975,&var737};
_S_or2  S_or2_579_1 = {&var974,&var737,&var738};
_S_and3  S_and3_573_1 = {&var963,&var1469,&var1367,&var739};
_S_and2  S_and2_572_1 = {&var158,&var1367,&var740};
_S_and3  S_and3_574_1 = {&var1168,&var1367,&var738,&var741};
_S_or2  S_or2_554_1 = {&var1357,&var1356,&var742};
_S_and2  S_and2_553_1 = {&var742,&var1367,&var743};
_S_and2  S_and2_552_1 = {&var1367,&var65,&var744};
_S_and3  S_and3_542_1 = {&var1358,&var746,&var1367,&var745};
_S_or2  S_or2_543_1 = {&B4IS11LDU,&A4IS11LDU,&var746};
_S_and2  S_and2_550_1 = {&var1367,&var1359,&var747};
_S_or2  S_or2_520_1 = {&B1MD12LP1,&var750,&var748};
_S_and2  S_and2_524_1 = {&var1159,&var748,&var749};
_S_and2  S_and2_513_1 = {&B1MD11LP1,&var1178,&var750};
_S_and2  S_and2_541_1 = {&var1367,&R3IS21LDU,&var751};
_S_and2  S_and2_540_1 = {&var1367,&var1671,&var752};
_S_or2  S_or2_531_1 = {&var1366,&var1745,&var753};
_S_zpfs  S_zpfs_533_1 = {&var1380,&fEM_A1UL03RDU,&var754,&internal1_m533_tx,&internal1_m533_y0};
_S_or5  S_or5_516_1 = {&var908,&var754,&var1381,&var1375,&var1376,&var755};
_S_or2  S_or2_504_1 = {&var1194,&var775,&var756};
_S_or3  S_or3_494_1 = {&var596,&var1193,&var1005,&var757};
_S_or4  S_or4_484_1 = {&var1419,&var1417,&var1419,&var1418,&var758};
_S_or4  S_or4_466_1 = {&var1428,&var1426,&var1427,&var1429,&var759};
_S_or2  S_or2_473_1 = {&var759,&var758,&var760};
_S_and3  S_and3_457_1 = {&var763,&var1159,&R0MD33LP1,&var761};
_S_and3  S_and3_458_1 = {&var1159,&var764,&R0MD33LP1,&var762};
_S_or3  S_or3_450_1 = {&var298,&var1014,&var1001,&var763};
_S_or2  S_or2_451_1 = {&var1415,&var1192,&var764};
_S_or2  S_or2_759_1 = {&var1550,&var1551,&var765};
_S_and2  S_and2_343_1 = {&var1050,&var1112,&var766};
_S_or2  S_or2_362_1 = {&B4IS21LDU,&A4IS21LDU,&var767};
_S_or2  S_or2_357_1 = {&A2IS21LDU,&B2IS21LDU,&var768};
_S_or2  S_or2_352_1 = {&var771,&var1054,&var769};
_S_and3  S_and3_350_1 = {&var1113,&var1108,&var1109,&var770};
_S_or4  S_or4_348_1 = {&var1039,&var208,&R0MD31LP1,&var1049,&var771};
_S_and4  S_and4_344_1 = {&var961,&var829,&var267,&var919,&var772};
_S_or2  S_or2_339_1 = {&R0MD34LP1,&var1049,&var773};
_S_and3  S_and3_613_1 = {&var796,&var1292,&B2IS12LDU,&var774};
_S_and2  S_and2_612_1 = {&var796,&var1324,&var775};
_S_and2  S_and2_611_1 = {&var796,&var1387,&var776};
_S_or2  S_or2_655_1 = {&A2IS12LDU,&B2IS12LDU,&var777};
_S_or2  S_or2_632_1 = {&var1522,&var1148,&var778};
_S_and3  S_and3_623_1 = {&A2IS12LDU,&var1292,&var797,&var779};
_S_and2  S_and2_654_1 = {&var781,&var1292,&var780};
_S_or2  S_or2_656_1 = {&var1091,&var251,&var781};
_S_or2  S_or2_637_1 = {&var1522,&var1147,&var782};
_S_or2  S_or2_635_1 = {&var784,&var1522,&var783};
_S_and2  S_and2_647_1 = {&var1324,&var262,&var784};
_S_and2  S_and2_622_1 = {&var797,&var1324,&var785};
_S_and2  S_and2_621_1 = {&var797,&var1387,&var786};
_S_and2  S_and2_646_1 = {&var256,&var1387,&var787};
_S_and2  S_and2_662_1 = {&var259,&var1415,&var788};
_S_or2  S_or2_658_1 = {&var1522,&var1149,&var789};
_S_or2  S_or2_653_1 = {&var791,&var788,&var790};
_S_and2  S_and2_645_1 = {&var799,&var1384,&var791};
_S_and2  S_and2_651_1 = {&var799,&R0MD33LP1,&var792};
_S_or2  S_or2_601_1 = {&var972,&var973,&var793};
_S_and4  S_and4_620_1 = {&var972,&var797,&var1484,&A2IS12LDU,&var794};
_S_and4  S_and4_610_1 = {&var796,&var973,&var1484,&B2IS12LDU,&var795};
_S_and2  S_and2_609_1 = {&var916,&var1482,&var796};
_S_and2  S_and2_619_1 = {&var915,&var1482,&var797};
_S_or2  S_or2_650_1 = {&var1092,&var251,&var798};
_S_and2  S_and2_643_1 = {&var798,&var1484,&var799};
_S_or2  S_or2_630_1 = {&var1522,&var1150,&var800};
_S_or2  S_or2_642_1 = {&var1462,&var1105,&var801};
_S_and2  S_and2_641_1 = {&var801,&var1506,&var802};
_S_or2  S_or2_627_1 = {&var1522,&var1151,&var803};
_S_and2  S_and2_640_1 = {&var1523,&var1472,&var804};
_S_or2  S_or2_625_1 = {&var1522,&var1152,&var805};
_S_and2  S_and2_638_1 = {&var254,&var1525,&var806};
_S_or2  S_or2_617_1 = {&var1160,&var1522,&var807};
_S_and2  S_and2_318_1 = {&var1222,&var810,&var808};
_S_and2  S_and2_306_1 = {&var810,&var1037,&var809};
_S_or2  S_or2_301_1 = {&var1051,&var1073,&var810};
_S_and3  S_and3_297_1 = {&var1288,&var1108,&var1109,&var811};
_S_and3  S_and3_312_1 = {&var768,&var1038,&var813,&var812};
_S_or2  S_or2_302_1 = {&var1288,&var1113,&var813};
_S_and2  S_and2_311_1 = {&var767,&var813,&var814};
_S_and2  S_and2_331_1 = {&var819,&var916,&var815};
_S_and2  S_and2_332_1 = {&var915,&var819,&var816};
_S_and2  S_and2_337_1 = {&var1010,&var808,&var817};
_S_and2  S_and2_325_1 = {&var819,&var1010,&var818};
_S_and2  S_and2_330_1 = {&var1190,&var820,&var819};
_S_or2  S_or2_326_1 = {&var821,&var766,&var820};
_S_or2  S_or2_327_1 = {&var822,&var766,&var821};
_S_and4  S_and4_328_1 = {&var1114,&var1062,&var1063,&var913,&var822};
_S_or2  S_or2_314_1 = {&var1114,&var1112,&var823};
_S_and2  S_and2_299_1 = {&var1076,&var1045,&var824};
_S_or2  S_or2_305_1 = {&var827,&var824,&var825};
_S_or2  S_or2_279_1 = {&R0MD34LP1,&var1048,&var826};
_S_or4  S_or4_296_1 = {&var1039,&R0MD31LP1,&var208,&var1048,&var827};
_S_and3  S_and3_289_1 = {&var829,&var918,&var267,&var828};
_S_or2  S_or2_288_1 = {&var1067,&var1253,&var829};
_S_and3  S_and3_291_1 = {&var1068,&var1070,&var1069,&var830};
_S_or2  S_or2_281_1 = {&var832,&var830,&var831};
_S_and3  S_and3_275_1 = {&R0MD33LP1,&var1072,&var1071,&var832};
_S_or2  S_or2_1104_1 = {&B4IS11LDU,&A4IS11LDU,&var833};
_S_and2  S_and2_1107_1 = {&var1473,&var1520,&var834};
_S_and2  S_and2_1106_1 = {&var1473,&var1628,&var835};
_S_and2  S_and2_1105_1 = {&var1473,&var905,&var836};
_S_and2  S_and2_1103_1 = {&var1473,&var833,&var837};
_S_and2  S_and2_1097_1 = {&var1473,&var158,&var838};
_S_and2  S_and2_1096_1 = {&var894,&var1473,&var839};
_S_and2  S_and2_1095_1 = {&var1473,&R3IS21LDU,&var840};
_S_and2  S_and2_1098_1 = {&var1473,&var1671,&var841};
_S_and2  S_and2_1090_1 = {&var251,&var1007,&var842};
_S_and2  S_and2_1091_1 = {&var262,&var1005,&var843};
_S_and2  S_and2_1092_1 = {&var256,&var1003,&var844};
_S_and2  S_and2_1093_1 = {&var259,&var1001,&var845};
_S_or2  S_or2_1075_1 = {&R0MD31LP1,&var847,&var846};
_S_and4  S_and4_1076_1 = {&var163,&var162,&var161,&var160,&var847};
_S_or2  S_or2_1146_1 = {&var1473,&var1726,&var848};
_S_or2  S_or2_1122_1 = {&var1523,&var1095,&var849};
_S_or2  S_or2_1202_1 = {&var1564,&var1563,&var850};
_S_or2  S_or2_1188_1 = {&var1573,&var1572,&var851};
_S_or2  S_or2_1199_1 = {&var988,&R0MD34LP1,&var852};
_S_or2  S_or2_1169_1 = {&var850,&var1628,&var853};
_S_or2  S_or2_1165_1 = {&var855,&var853,&var854};
_S_or2  S_or2_1168_1 = {&var851,&var1628,&var855};
_S_or4  S_or4_374_1 = {&var1600,&var1599,&var1601,&var1598,&var856};
_S_or2  S_or2_675_1 = {&B5IS11LDU,&A5IS11LDU,&var857};
_S_and2  S_and2_674_1 = {&var862,&var857,&var858};
_S_or2  S_or2_673_1 = {&B6IS11LDU,&A6IS11LDU,&var859};
_S_and2  S_and2_672_1 = {&var862,&var859,&var860};
_S_or2  S_or2_671_1 = {&A4IS11LDU,&B4IS11LDU,&var861};
_S_or2  S_or2_664_1 = {&var864,&var865,&var862};
_S_and2  S_and2_670_1 = {&var862,&var861,&var863};
_S_and2  S_and2_667_1 = {&var158,&var875,&var864};
_S_and2  S_and2_663_1 = {&var159,&var868,&var865};
_S_and2  S_and2_779_1 = {&var1626,&var1544,&var866};
_S_and2  S_and2_775_1 = {&var1626,&var1545,&var867};
_S_and3  S_and3_770_1 = {&var1626,&var159,&var1551,&var868};
_S_or2  S_or2_778_1 = {&var1546,&var1540,&var869};
_S_or2  S_or2_773_1 = {&var1544,&var1546,&var870};
_S_or2  S_or2_769_1 = {&var1546,&var1545,&var871};
_S_and2  S_and2_751_1 = {&var1540,&var1626,&var872};
_S_or2  S_or2_742_1 = {&var1547,&var1548,&var873};
_S_or2  S_or2_738_1 = {&var1605,&var1547,&var874};
_S_and2  S_and2_735_1 = {&var1548,&var1627,&var875};
_S_and2  S_and2_734_1 = {&var1605,&var1627,&var876};
_S_and2  S_and2_763_1 = {&var254,&var1626,&var877};
_S_and2  S_and2_744_1 = {&var254,&var1557,&var878};
_S_and2  S_and2_761_1 = {&var1627,&var254,&var879};
_S_or2  S_or2_755_1 = {&var1627,&var1626,&var880};
_S_or3  S_or3_748_1 = {&var69,&var883,&var884,&var881};
_S_or4  S_or4_747_1 = {&var883,&var68,&var885,&var1536,&var882};
_S_or3  S_or3_737_1 = {&R4MD31LP2,&var872,&var876,&var883};
_S_or2  S_or2_767_1 = {&var1625,&var887,&var884};
_S_or2  S_or2_766_1 = {&var1625,&var886,&var885};
_S_and2  S_and2_685_1 = {&var69,&var1539,&var886};
_S_and3  S_and3_714_1 = {&var1538,&var1552,&var68,&var887};
_S_and2  S_and2_719_1 = {&R5IS11LDU,&var902,&var888};
_S_and3  S_and3_717_1 = {&var1190,&R3IS21LDU,&var902,&var889};
_S_and2  S_and2_718_1 = {&R6IS21LDU,&var902,&var890};
_S_or2  S_or2_716_1 = {&B8IS22LDU,&A8IS22LDU,&var891};
_S_and2  S_and2_715_1 = {&var891,&var902,&var892};
_S_and2  S_and2_702_1 = {&var902,&var894,&var893};
_S_or4  S_or4_703_1 = {&A0VN71LZ1,&B0VN71LZ1,&B0VN71LZ2,&A0VN71LZ2,&var894};
_S_and2  S_and2_700_1 = {&var899,&var902,&var895};
_S_and2  S_and2_691_1 = {&var905,&var902,&var896};
_S_and2  S_and2_690_1 = {&var1628,&var902,&var897};
_S_or3  S_or3_689_1 = {&R0NE01LDU,&R0NE02LDU,&R0NE08LDU,&var898};
_S_or2  S_or2_701_1 = {&R1IS21LDU,&R2IS21LDU,&var899};
_S_and2  S_and2_688_1 = {&var902,&var898,&var900};
_S_and2  S_and2_686_1 = {&var1606,&var902,&var901};
_S_or2  S_or2_677_1 = {&var1627,&var1626,&var902};
_S_or2  S_or2_172_1 = {&var1196,&var785,&var903};
_S_or3  S_or3_162_1 = {&var595,&var1195,&var1005,&var904};
_S_or2  S_or2_155_1 = {&var1469,&var404,&var905};
_S_or3  S_or3_114_1 = {&var1158,&var390,&var391,&var906};
_S_or2  S_or2_2030_1 = {&var352,&var229,&var907};
_S_or3  S_or3_586_1 = {&var909,&var910,&var736,&var908};
_S_and2  S_and2_575_1 = {&var1366,&var912,&var909};
_S_and2  S_and2_576_1 = {&var1366,&var962,&var910};
_S_or2  S_or2_66_1 = {&var962,&var912,&var911};
_S_and2  S_and2_69_1 = {&var913,&var1041,&var912};
_S_and2  S_and2_68_1 = {&var1635,&var1042,&var913};
_S_or2  S_or2_54_1 = {&A4IS21LDU,&B4IS21LDU,&var914};
_S_or2  S_or2_41_1 = {&var1286,&var1283,&var915};
_S_or2  S_or2_45_1 = {&var1286,&var1285,&var916};
_S_or2  S_or2_23_1 = {&var1190,&var1143,&var917};
_S_or2  S_or2_8_1 = {&var1645,&var964,&var918};
_S_or2  S_or2_17_1 = {&var964,&var1646,&var919};
_S_and3  S_and3_998_1 = {&var264,&var1639,&var939,&var920};
_S_and3  S_and3_599_1 = {&var939,&var267,&var1639,&var921};
_S_and2  S_and2_1064_1 = {&var985,&var923,&var922};
_S_or2  S_or2_1071_1 = {&var1646,&var1645,&var923};
_S_or2  S_or2_1385_1 = {&var1647,&var1645,&var924};
_S_and3  S_and3_1384_1 = {&var983,&var924,&var662,&var925};
_S_or2  S_or2_973_1 = {&var1647,&var1645,&var926};
_S_and3  S_and3_972_1 = {&var983,&var926,&var677,&var927};
_S_or2  S_or2_565_1 = {&var1647,&var1645,&var928};
_S_and3  S_and3_564_1 = {&var983,&var928,&var1367,&var929};
_S_and2  S_and2_562_1 = {&var154,&var1367,&var930};
_S_or2  S_or2_248_1 = {&var1647,&var1645,&var931};
_S_and3  S_and3_247_1 = {&var983,&var931,&var1400,&var932};
_S_and2  S_and2_245_1 = {&var1400,&var155,&var933};
_S_and3  S_and3_878_1 = {&var983,&var936,&var702,&var934};
_S_and2  S_and2_877_1 = {&var496,&var702,&var935};
_S_or2  S_or2_879_1 = {&var1647,&var1645,&var936};
_S_or2  S_or2_1296_1 = {&var1647,&var1645,&var937};
_S_or2  S_or2_6_1 = {&var1646,&var1645,&var938};
_S_or3  S_or3_5_1 = {&var1647,&var1646,&var1645,&var939};
_S_or2  S_or2_754_1 = {&var1547,&var1549,&var940};
_S_or2  S_or2_447_1 = {&var1628,&var945,&var941};
_S_or2  S_or2_430_1 = {&var1628,&var946,&var942};
_S_or4  S_or4_431_1 = {&var942,&var1556,&var1555,&var941,&var943};
_S_and2  S_and2_423_1 = {&A8IS22LDU,&var1620,&var944};
_S_or3  S_or3_409_1 = {&var1610,&var1608,&var1609,&var945};
_S_or3  S_or3_394_1 = {&var1618,&var1617,&var1619,&var946};
_S_and2  S_and2_741_1 = {&var1627,&var1549,&var947};
_S_and2  S_and2_44_1 = {&var1283,&var1284,&var948};
_S_and2  S_and2_148_1 = {&var1559,&var1181,&var949};
_S_and2  S_and2_156_1 = {&var1561,&var1181,&var950};
_S_and2  S_and2_159_1 = {&var1558,&var1181,&var951};
_S_and2  S_and2_151_1 = {&var1181,&var1560,&var952};
_S_and2  S_and2_444_1 = {&var905,&var1612,&var953};
_S_and2  S_and2_443_1 = {&B8IS22LDU,&var1612,&var954};
_S_and2  S_and2_442_1 = {&A8IS22LDU,&var1612,&var955};
_S_and2  S_and2_441_1 = {&R5IS11LDU,&var1612,&var956};
_S_and2  S_and2_433_1 = {&var1554,&var1620,&var957};
_S_and2  S_and2_422_1 = {&R5IS11LDU,&var1620,&var958};
_S_and2  S_and2_426_1 = {&var905,&var1620,&var959};
_S_and2  S_and2_118_1 = {&var964,&var389,&var960};
_S_and2  S_and2_64_1 = {&var1636,&var1042,&var961};
_S_and2  S_and2_65_1 = {&var961,&var1040,&var962};
_S_and2  S_and2_48_1 = {&var1284,&var1285,&var963};
_S_and2  S_and2_11_1 = {&var1644,&var1276,&var964};
_S_and2  S_and2_34_1 = {&var1207,&var253,&var965};
_S_and2  S_and2_33_1 = {&var1101,&var1190,&var966};
_S_and2  S_and2_32_1 = {&var1102,&var1190,&var967};
_S_and2  S_and2_31_1 = {&var1103,&var1190,&var968};
_S_and2  S_and2_30_1 = {&var1104,&var1190,&var969};
_S_and2  S_and2_768_1 = {&var1543,&var1551,&var970};
_S_and2  S_and2_750_1 = {&var1550,&var1627,&var971};
_S_bol  S_bol_600_1 = {&var1740,&fRM_20_0,&var972};
_S_bol  S_bol_594_1 = {&var1737,&fRM_20_0,&var973};
_S_bol  S_bol_585_1 = {&var1737,&fRM_20_03,&var974};
_S_bol  S_bol_583_1 = {&var1740,&fRM_20_03,&var975};
_S_bol  S_bol_988_1 = {&var1737,&fRM_20_03,&var976};
_S_bol  S_bol_990_1 = {&var1740,&fRM_20_03,&var977};
_S_bol  S_bol_1400_1 = {&var1740,&fRM_20_03,&var978};
_S_bol  S_bol_1402_1 = {&var1737,&fRM_20_03,&var979};
_S_bol  S_bol_269_1 = {&var1737,&fRM_20_03,&var980};
_S_bol  S_bol_271_1 = {&var1740,&fRM_20_03,&var981};
_S_sr  S_sr_88_1 = {array_m88_x_1,&iRM_2_,&var982};
_S_bol  S_bol_87_1 = {&var982,&var207,&var983};
_S_ma  S_ma_90_1 = {array_m90_x_1,&R0MW15IP1,&iRM_8_,&var984};
_S_bol  S_bol_1065_1 = {&var986,&fEM_R0UN80RDU,&var985};
_S_sr  S_sr_1072_1 = {array_m1072_x_1,&iRM_2_,&var986};
_S_ovbs  S_ovbs_2108_1 = {&lRM_1_,&fEM_A9UZ04RDU,&var987,&internal1_m2108_tx};
_S_ovbs  S_ovbs_1198_1 = {&lRM_1_,&fEM_A4UZ04RDU,&var988,&internal1_m1198_tx};
_S_zpfs  S_zpfs_1623_1 = {&var1514,&fEM_B8UL03RDU,&var989,&internal1_m1623_tx,&internal1_m1623_y0};
_S_zpfs  S_zpfs_1148_1 = {&var1531,&fEM_B8UL03RDU,&var990,&internal1_m1148_tx,&internal1_m1148_y0};
_S_ma  S_ma_1222_1 = {array_m1222_x_1,&var1483,&iRM_8_,&var991};
_S_ma  S_ma_822_1 = {array_m822_x_1,&var1443,&iRM_8_,&var992};
_S_ma  S_ma_902_1 = {array_m902_x_1,&var1334,&iRM_8_,&var993};
_S_ma  S_ma_1319_1 = {array_m1319_x_1,&var1302,&iRM_8_,&var994};
_S_ma  S_ma_503_1 = {array_m503_x_1,&var1363,&iRM_8_,&var995};
_S_ma  S_ma_170_1 = {array_m170_x_1,&var1396,&iRM_8_,&var996};
_S_zpfs  S_zpfs_1349_1 = {&var1319,&fEM_A3UL03RDU,&var997,&internal1_m1349_tx,&internal1_m1349_y0};
_S_zpfs  S_zpfs_937_1 = {&var1351,&fEM_A3UL03RDU,&var998,&internal1_m937_tx,&internal1_m937_y0};
_S_zpfs  S_zpfs_1258_1 = {&var1501,&fEM_A2UL03RDU,&var999,&internal1_m1258_tx,&internal1_m1258_y0};
_S_rs  S_rs_1089_1 = {&var846,&var845,&var1000,&vainSBool,&internal1_m1089_q0};
_S_rs  S_rs_1087_1 = {&var163,&var1008,&var1001,&vainSBool,&internal1_m1087_q0};
_S_rs  S_rs_1086_1 = {&var846,&var844,&var1002,&vainSBool,&internal1_m1086_q0};
_S_rs  S_rs_1084_1 = {&var162,&var1008,&var1003,&vainSBool,&internal1_m1084_q0};
_S_rs  S_rs_1083_1 = {&var846,&var843,&var1004,&vainSBool,&internal1_m1083_q0};
_S_rs  S_rs_1081_1 = {&var161,&var1008,&var1005,&vainSBool,&internal1_m1081_q0};
_S_rs  S_rs_1080_1 = {&var846,&var842,&var1006,&vainSBool,&internal1_m1080_q0};
_S_rs  S_rs_1078_1 = {&var160,&var1008,&var1007,&vainSBool,&internal1_m1078_q0};
_S_rs  S_rs_1077_1 = {&var846,&var208,&var1008,&vainSBool,&internal1_m1077_q0};
_S_noto  S_noto_1942_1 = {&var464,&var1009};
_S_swtakt  S_swtakt_58_1 = {&var384,&var1010,&internal1_m58_x0};
_S_noto  S_noto_1063_1 = {&var1022,&var1011};
_S_noto  S_noto_1037_1 = {&var1020,&var1012};
_S_noto  S_noto_1049_1 = {&var1021,&var1013};
_S_rs  S_rs_997_1 = {&var1023,&var603,&var1014,&vainSBool,&internal1_m997_q0};
_S_swtakt  S_swtakt_1446_1 = {&var562,&var1015,&internal1_m1446_x0};
_S_swtakt  S_swtakt_1490_1 = {&var550,&var1016,&internal1_m1490_x0};
_S_swtakt  S_swtakt_1486_1 = {&var544,&var1017,&internal1_m1486_x0};
_S_swtakt  S_swtakt_1902_1 = {&var451,&var1018,&internal1_m1902_x0};
_S_swtakt  S_swtakt_1867_1 = {&var425,&var1019,&internal1_m1867_x0};
_S_rs  S_rs_1036_1 = {&var1094,&var591,&var1020,&vainSBool,&internal1_m1036_q0};
_S_rs  S_rs_1048_1 = {&var1094,&var592,&var1021,&vainSBool,&internal1_m1048_q0};
_S_rs  S_rs_1060_1 = {&var1094,&var593,&var1022,&vainSBool,&internal1_m1060_q0};
_S_rs  S_rs_1070_1 = {&var1094,&var594,&var1023,&vainSBool,&internal1_m1070_q0};
_S_noto  S_noto_1023_1 = {&var609,&var1024};
_S_noto  S_noto_1050_1 = {&var609,&var1025};
_S_noto  S_noto_1056_1 = {&var613,&var1026};
_S_rs  S_rs_1047_1 = {&var587,&var589,&var1027,&vainSBool,&internal1_m1047_q0};
_S_rs  S_rs_1062_1 = {&var1094,&var585,&var1028,&vainSBool,&internal1_m1062_q0};
_S_bol  S_bol_1044_1 = {&var1725,&var314,&var1029};
_S_bol  S_bol_1043_1 = {&var1728,&var314,&var1030};
_S_noto  S_noto_1004_1 = {&var1089,&var1031};
_S_bol  S_bol_1041_1 = {&var314,&var1725,&var1032};
_S_bol  S_bol_1040_1 = {&var314,&var1728,&var1033};
_S_noto  S_noto_1027_1 = {&var1090,&var1034};
_S_rs  S_rs_1960_1 = {&var469,&var460,&var1035,&vainSBool,&internal1_m1960_q0};
_S_rs  S_rs_1959_1 = {&var469,&var461,&var1036,&vainSBool,&internal1_m1959_q0};
_S_noto  S_noto_338_1 = {&var817,&var1037};
_S_noto  S_noto_320_1 = {&var810,&var1038};
_S_noto  S_noto_290_1 = {&var829,&var1039};
_S_noto  S_noto_62_1 = {&var1051,&var1040};
_S_noto  S_noto_73_1 = {&var1073,&var1041};
_S_noto  S_noto_72_1 = {&var1008,&var1042};
_S_noto  S_noto_1954_1 = {&B2IS11LDU,&var1043};
_S_noto  S_noto_1952_1 = {&A2IS11LDU,&var1044};
_S_noto  S_noto_298_1 = {&var267,&var1045};
_S_noto  S_noto_1961_1 = {&B2IS11LDU,&var1046};
_S_noto  S_noto_1936_1 = {&A2IS11LDU,&var1047};
_S_noto  S_noto_285_1 = {&var913,&var1048};
_S_noto  S_noto_342_1 = {&var961,&var1049};
_S_bolz  S_bolz_346_1 = {&iRM_2_,&var1052,&var1050};
_S_provsbr  S_provsbr_341_1 = {&var1112,&var773,&var1127,&var1144,&var1138,&var1133,&var1130,&var1128,&var1142,&var1137,&var1135,&var1131,&iRM_10_,array_m341_Tpr_1,array_m341_type_1,&var1051,&var1052,&var1053,&var1054,&var1055,&var1056,&var1057,&var1058,&var1059,&internal1_m341_Step,array_m341_rz_1,&internal1_m341_TimS,&internal1_m341_FinPr0,&internal1_m341_ErrPr0,&internal1_m341_sbINI0,&internal1_m341_sbVuIS0,&internal1_m341_sb2UR0,&internal1_m341_sbNupIS0,&internal1_m341_sbVuRB0,&internal1_m341_MyFirstEnterFlag};
_S_orni  S_orni_345_1 = {array_m345_x_1,&iRM_5_,&vainSBool,&var1060};
_S_cntch  S_cntch_349_1 = {&var1060,&var1061,&internal1_m349_x0};
_S_bolz  S_bolz_324_1 = {&iRM_20_,&var1075,&var1062};
_S_equz_p  S_equz_p_323_1 = {&var1074,&iRM_0_,&var1063};
_S_decatron  S_decatron_309_1 = {&var809,&var1064,&internal1_m309_TimS};
_S_noto  S_noto_1001_1 = {&R2IS21LDU,&var1065};
_S_noto  S_noto_995_1 = {&R1IS21LDU,&var1066};
_S_andn  S_andn_280_1 = {array_m280_x_1,&iRM_7_,&var1067};
_S_noto  S_noto_282_1 = {&R0MD33LP1,&var1068};
_S_noto  S_noto_292_1 = {&R2IS21LDU,&var1069};
_S_noto  S_noto_286_1 = {&R1IS21LDU,&var1070};
_S_noto  S_noto_277_1 = {&R1IS11LDU,&var1071};
_S_noto  S_noto_274_1 = {&R2IS11LDU,&var1072};
_S_provsbr  S_provsbr_284_1 = {&var1114,&var826,&var1127,&var1144,&var1138,&var1133,&var1130,&var1128,&var1142,&var1137,&var1135,&var1131,&iRM_10_,array_m284_Tpr_1,array_m284_type_1,&var1073,&var1074,&var1075,&var1076,&var1077,&var1078,&var1079,&var1080,&var1081,&internal1_m284_Step,array_m284_rz_1,&internal1_m284_TimS,&internal1_m284_FinPr0,&internal1_m284_ErrPr0,&internal1_m284_sbINI0,&internal1_m284_sbVuIS0,&internal1_m284_sb2UR0,&internal1_m284_sbNupIS0,&internal1_m284_sbVuRB0,&internal1_m284_MyFirstEnterFlag};
_S_rs  S_rs_1420_1 = {&var1083,&var584,&var1082,&vainSBool,&internal1_m1420_q0};
_S_provsbr  S_provsbr_1421_1 = {&var1082,&R0MD34LP1,&var1127,&var1144,&var1138,&var1133,&var1130,&var1128,&var1142,&var1137,&var1135,&var1131,&iRM_6_,array_m1421_Tpr_1,array_m1421_type_1,&var1083,&vainSInt,&vainSInt,&vainSBool,&var1084,&var1085,&var1086,&var1087,&var1088,&internal1_m1421_Step,array_m1421_rz_1,&internal1_m1421_TimS,&internal1_m1421_FinPr0,&internal1_m1421_ErrPr0,&internal1_m1421_sbINI0,&internal1_m1421_sbVuIS0,&internal1_m1421_sb2UR0,&internal1_m1421_sbNupIS0,&internal1_m1421_sbVuRB0,&internal1_m1421_MyFirstEnterFlag};
_S_abs_subf  S_abs_subf_1007_1 = {&var314,&var1728,&fEM_B8UC01RDU,&vainSFloat,&var1089};
_S_abs_subf  S_abs_subf_1020_1 = {&var1725,&var314,&fEM_B8UC01RDU,&vainSFloat,&var1090};
_S_noto  S_noto_660_1 = {&var777,&var1091};
_S_noto  S_noto_607_1 = {&var793,&var1092};
_S_noto  S_noto_55_1 = {&var310,&var1093};
_S_noto  S_noto_1024_1 = {&var1291,&var1094};
_S_rs  S_rs_1032_1 = {&var586,&var405,&var1095,&vainSBool,&internal1_m1032_q0};
_S_rs  S_rs_1029_1 = {&var590,&var585,&var1096,&vainSBool,&internal1_m1029_q0};
_S_rs  S_rs_1031_1 = {&var1094,&var405,&var1097,&vainSBool,&internal1_m1031_q0};
_S_rs  S_rs_1025_1 = {&var1094,&var588,&var1098,&vainSBool,&internal1_m1025_q0};
_S_noto  S_noto_596_1 = {&A2IS21LDU,&var1099};
_S_noto  S_noto_598_1 = {&B2IS21LDU,&var1100};
_S_noto  S_noto_28_1 = {&B2IS21LDU,&var1101};
_S_noto  S_noto_27_1 = {&B1IS21LDU,&var1102};
_S_noto  S_noto_26_1 = {&A1IS21LDU,&var1103};
_S_noto  S_noto_25_1 = {&A2IS21LDU,&var1104};
_S_newstage  S_newstage_608_1 = {&var131,&var128,&A2IS12LDU,&B2IS12LDU,&var1105};
_S_noto  S_noto_597_1 = {&B2IS12LDU,&var1106};
_S_noto  S_noto_595_1 = {&A2IS12LDU,&var1107};
_S_noto  S_noto_355_1 = {&var768,&var1108};
_S_noto  S_noto_359_1 = {&var767,&var1109};
_S_noto  S_noto_994_1 = {&var905,&var1110};
_S_rs  S_rs_758_1 = {&var765,&var387,&var1111,&vainSBool,&internal1_m758_q0};
_S_rs  S_rs_351_1 = {&var769,&var770,&var1112,&vainSBool,&internal1_m351_q0};
_S_rs  S_rs_347_1 = {&var771,&var772,&var1113,&vainSBool,&internal1_m347_q0};
_S_rs  S_rs_304_1 = {&var825,&var811,&var1114,&vainSBool,&internal1_m304_q0};
_S_orni  S_orni_300_1 = {array_m300_x_1,&iRM_5_,&vainSBool,&var1115};
_S_cntch  S_cntch_303_1 = {&var1115,&var1116,&internal1_m303_x0};
_S_noto  S_noto_1459_1 = {&var1135,&var1117};
_S_noto  S_noto_1515_1 = {&var1137,&var1118};
_S_noto  S_noto_1517_1 = {&var1142,&var1119};
_S_noto  S_noto_1883_1 = {&var1128,&var1120};
_S_noto  S_noto_1918_1 = {&var1131,&var1121};
_S_noto  S_noto_1898_1 = {&var1018,&var1122};
_S_noto  S_noto_1861_1 = {&var1019,&var1123};
_S_noto  S_noto_1487_1 = {&var1017,&var1124};
_S_noto  S_noto_1482_1 = {&var1016,&var1125};
_S_noto  S_noto_1442_1 = {&var1015,&var1126};
_S_rs  S_rs_1889_1 = {&var569,&var409,&var1127,&vainSBool,&internal1_m1889_q0};
_S_rs  S_rs_1877_1 = {&var424,&var421,&var1128,&vainSBool,&internal1_m1877_q0};
_S_rs  S_rs_1868_1 = {&var420,&var1019,&var1129,&vainSBool,&internal1_m1868_q0};
_S_rs  S_rs_1943_1 = {&var569,&var438,&var1130,&vainSBool,&internal1_m1943_q0};
_S_rs  S_rs_1914_1 = {&var446,&var445,&var1131,&vainSBool,&internal1_m1914_q0};
_S_rs  S_rs_1903_1 = {&var448,&var1018,&var1132,&vainSBool,&internal1_m1903_q0};
_S_rs  S_rs_1473_1 = {&var569,&var555,&var1133,&vainSBool,&internal1_m1473_q0};
_S_kvf  S_kvf_1460_1 = {&var1136,&var556,&fRM_0_0,&var1134,&vainSInt,&vainSInt,&internal1_m1460_x0,&internal1_m1460_y0,&bFirstEnterFlag};
_S_rs  S_rs_1456_1 = {&var561,&var556,&var1135,&vainSBool,&internal1_m1456_q0};
_S_rs  S_rs_1447_1 = {&var558,&var1015,&var1136,&vainSBool,&internal1_m1447_q0};
_S_rs  S_rs_1506_1 = {&var551,&var546,&var1137,&vainSBool,&internal1_m1506_q0};
_S_rs  S_rs_1526_1 = {&var569,&var552,&var1138,&vainSBool,&internal1_m1526_q0};
_S_rs  S_rs_1492_1 = {&var549,&var1016,&var1139,&vainSBool,&internal1_m1492_q0};
_S_kvf  S_kvf_1507_1 = {&var1139,&var546,&fRM_0_0,&var1140,&vainSInt,&vainSInt,&internal1_m1507_x0,&internal1_m1507_y0,&bFirstEnterFlag};
_S_cntch  S_cntch_1431_1 = {&var571,&var1141,&internal1_m1431_x0};
_S_rs  S_rs_1512_1 = {&var543,&var537,&var1142,&vainSBool,&internal1_m1512_q0};
_S_rs  S_rs_29_1 = {&var1190,&var965,&var1143,&vainSBool,&internal1_m29_q0};
_S_rs  S_rs_1527_1 = {&var569,&var536,&var1144,&vainSBool,&internal1_m1527_q0};
_S_noto  S_noto_1409_1 = {&var565,&var1145};
_S_noto  S_noto_1407_1 = {&var964,&var1146};
_S_rs  S_rs_648_1 = {&var1522,&var780,&var1147,&vainSBool,&internal1_m648_q0};
_S_rs  S_rs_633_1 = {&var1522,&var787,&var1148,&vainSBool,&internal1_m633_q0};
_S_rs  S_rs_661_1 = {&var1522,&var788,&var1149,&vainSBool,&internal1_m661_q0};
_S_rs  S_rs_644_1 = {&var1522,&var799,&var1150,&vainSBool,&internal1_m644_q0};
_S_rs  S_rs_628_1 = {&var1522,&var802,&var1151,&vainSBool,&internal1_m628_q0};
_S_rs  S_rs_626_1 = {&var1522,&var804,&var1152,&vainSBool,&internal1_m626_q0};
_S_rs  S_rs_614_1 = {&var807,&var1525,&var1153,&vainSBool,&internal1_m614_q0};
_S_rsun  S_rsun_1423_1 = {&var569,&var1275,&vainSLong,&var1154,&internal1_m1423_q0};
_S_noto  S_noto_1350_1 = {&B3MD12LP1,&var1155};
_S_noto  S_noto_1837_1 = {&B3IS11LDU,&var1156};
_S_noto  S_noto_1811_1 = {&A3IS11LDU,&var1157};
_S_noto  S_noto_117_1 = {&var964,&var1158};
_S_noto  S_noto_116_1 = {&var1163,&var1159};
_S_rs  S_rs_624_1 = {&var1522,&var806,&var1160,&vainSBool,&internal1_m624_q0};
_S_orni  S_orni_1197_1 = {array_m1197_x_1,&iRM_5_,&var1161,&vainSLong};
_S_orni  S_orni_1184_1 = {array_m1184_x_1,&iRM_4_,&var1162,&vainSLong};
_S_rs  S_rs_115_1 = {&var906,&var960,&var1163,&vainSBool,&internal1_m115_q0};
_S_noto  S_noto_1840_1 = {&var487,&var1164};
_S_noto  S_noto_1839_1 = {&var486,&var1165};
_S_noto  S_noto_1851_1 = {&B3IS22LDU,&var1166};
_S_noto  S_noto_1833_1 = {&A3IS22LDU,&var1167};
_S_newstage  S_newstage_1835_1 = {&var503,&var499,&var502,&var498,&vainSBool};
_S_noto  S_noto_1779_1 = {&var1253,&var1168};
_S_rs  S_rs_1659_1 = {&var45,&var278,&var1169,&vainSBool,&internal1_m1659_q0};
_S_rs  S_rs_1658_1 = {&var38,&var280,&var1170,&vainSBool,&internal1_m1658_q0};
_S_rs  S_rs_1657_1 = {&var44,&var282,&var1171,&vainSBool,&internal1_m1657_q0};
_S_rs  S_rs_1656_1 = {&var19,&var284,&var1172,&vainSBool,&internal1_m1656_q0};
_S_rs  S_rs_1694_1 = {&var253,&var286,&var1173,&vainSBool,&internal1_m1694_q0};
_S_rs  S_rs_1693_1 = {&var56,&var289,&var1174,&vainSBool,&internal1_m1693_q0};
_S_rs  S_rs_1692_1 = {&var57,&var289,&var1175,&vainSBool,&internal1_m1692_q0};
_S_noto  S_noto_1249_1 = {&A2MD12LP1,&var1176};
_S_noto  S_noto_1233_1 = {&B2MD12LP1,&var1177};
_S_noto  S_noto_518_1 = {&B1MD12LP1,&var1178};
_S_ma  S_ma_1462_1 = {array_m1462_x_1,&var1154,&iRM_16_,&var1179};
_S_noto  S_noto_1417_1 = {&var821,&var1180};
_S_noto  S_noto_146_1 = {&var964,&var1181};
_S_equz_p  S_equz_p_1817_1 = {&R0MW14IP2,&iRM_5_,&var1182};
_S_equz_p  S_equz_p_1816_1 = {&R0MW14IP2,&iRM_4_,&var1183};
_S_equz_p  S_equz_p_1815_1 = {&R0MW14IP2,&iRM_3_,&var1184};
_S_equz_p  S_equz_p_1813_1 = {&R0MW14IP2,&iRM_1_,&vainSBool};
_S_equz_p  S_equz_p_1814_1 = {&R0MW14IP2,&iRM_2_,&var1185};
_S_noto  S_noto_1870_1 = {&B3IS11LDU,&var1186};
_S_noto  S_noto_1865_1 = {&A3IS11LDU,&var1187};
_S_noto  S_noto_1907_1 = {&B2IS11LDU,&var1188};
_S_noto  S_noto_1915_1 = {&A2IS11LDU,&var1189};
_S_noto  S_noto_12_1 = {&var1644,&var1190};
_S_rs  S_rs_1974_1 = {&var372,&var473,&var1191,&vainSBool,&internal1_m1974_q0};
_S_rs  S_rs_1754_1 = {&var515,&var299,&var1192,&vainSBool,&internal1_m1754_q0};
_S_rs  S_rs_1743_1 = {&var41,&var300,&var1193,&vainSBool,&internal1_m1743_q0};
_S_rs  S_rs_1751_1 = {&var58,&var301,&var1194,&vainSBool,&internal1_m1751_q0};
_S_rs  S_rs_1740_1 = {&var42,&var302,&var1195,&vainSBool,&internal1_m1740_q0};
_S_rs  S_rs_1748_1 = {&var62,&var303,&var1196,&vainSBool,&internal1_m1748_q0};
_S_equz_p  S_equz_p_105_1 = {&R0MW16IP1,&iRM_10_,&var1197};
_S_noto  S_noto_188_1 = {&A1MD12LP1,&var1198};
_S_rs  S_rs_2174_1 = {&var32,&var29,&var1199,&vainSBool,&internal1_m2174_q0};
_S_rs  S_rs_2170_1 = {&var48,&var120,&var1200,&vainSBool,&internal1_m2170_q0};
_S_rs  S_rs_1719_1 = {&var61,&var296,&var1201,&vainSBool,&internal1_m1719_q0};
_S_rs  S_rs_1711_1 = {&var253,&var285,&var1202,&vainSBool,&internal1_m1711_q0};
_S_rs  S_rs_1709_1 = {&var43,&var286,&var1203,&vainSBool,&internal1_m1709_q0};
_S_rs  S_rs_1705_1 = {&var56,&var287,&var1204,&vainSBool,&internal1_m1705_q0};
_S_rs  S_rs_1701_1 = {&var16,&var289,&var1205,&vainSBool,&internal1_m1701_q0};
_S_rs  S_rs_1703_1 = {&var57,&var288,&var1206,&vainSBool,&internal1_m1703_q0};
_S_rs  S_rs_22_1 = {&var917,&var393,&var1207,&vainSBool,&internal1_m22_q0};
_S_equz_p  S_equz_p_104_1 = {&R0MW16IP1,&iRM_9_,&var1208};
_S_equz_p  S_equz_p_103_1 = {&R0MW16IP1,&iRM_8_,&var1209};
_S_noto  S_noto_938_1 = {&A3MD12LP1,&var1210};
_S_equz_p  S_equz_p_102_1 = {&R0MW16IP1,&iRM_7_,&var1211};
_S_equz_p  S_equz_p_101_1 = {&R0MW16IP1,&iRM_6_,&var1212};
_S_equz_p  S_equz_p_100_1 = {&R0MW16IP1,&iRM_5_,&var1213};
_S_rs  S_rs_1682_1 = {&var45,&var277,&var1214,&vainSBool,&internal1_m1682_q0};
_S_rs  S_rs_1680_1 = {&var37,&var278,&var1215,&vainSBool,&internal1_m1680_q0};
_S_rs  S_rs_1676_1 = {&var55,&var280,&var1216,&vainSBool,&internal1_m1676_q0};
_S_rs  S_rs_1678_1 = {&var38,&var279,&var1217,&vainSBool,&internal1_m1678_q0};
_S_rs  S_rs_1674_1 = {&var44,&var281,&var1218,&vainSBool,&internal1_m1674_q0};
_S_rs  S_rs_1672_1 = {&var20,&var282,&var1219,&vainSBool,&internal1_m1672_q0};
_S_rs  S_rs_2090_1 = {&var135,&var482,&var1220,&vainSBool,&internal1_m2090_q0};
_S_rs  S_rs_2085_1 = {&var136,&var483,&var1221,&vainSBool,&internal1_m2085_q0};
_S_equz_p  S_equz_p_313_1 = {&var1064,&iRM_0_,&var1222};
_S_noto  S_noto_2091_1 = {&var1220,&var1223};
_S_noto  S_noto_2081_1 = {&var397,&var1224};
_S_noto  S_noto_2065_1 = {&var1226,&var1225};
_S_rs  S_rs_2064_1 = {&var75,&var479,&var1226,&vainSBool,&internal1_m2064_q0};
_S_noto  S_noto_2053_1 = {&var1228,&var1227};
_S_rs  S_rs_2052_1 = {&var77,&var476,&var1228,&vainSBool,&internal1_m2052_q0};
_S_noto  S_noto_2086_1 = {&var1221,&var1229};
_S_noto  S_noto_2077_1 = {&var396,&var1230};
_S_noto  S_noto_1986_1 = {&var1232,&var1231};
_S_rs  S_rs_1985_1 = {&var371,&var474,&var1232,&vainSBool,&internal1_m1985_q0};
_S_noto  S_noto_1975_1 = {&var1191,&var1233};
_S_noto  S_noto_1981_1 = {&var394,&var1234};
_S_noto  S_noto_1969_1 = {&var395,&var1235};
_S_rs  S_rs_1668_1 = {&var54,&var284,&var1236,&vainSBool,&internal1_m1668_q0};
_S_rs  S_rs_1670_1 = {&var19,&var283,&var1237,&vainSBool,&internal1_m1670_q0};
_S_rs  S_rs_1654_1 = {&var35,&var269,&var1238,&vainSBool,&internal1_m1654_q0};
_S_rs  S_rs_1652_1 = {&var53,&var270,&var1239,&vainSBool,&internal1_m1652_q0};
_S_rs  S_rs_1650_1 = {&var34,&var271,&var1240,&vainSBool,&internal1_m1650_q0};
_S_rs  S_rs_1648_1 = {&var52,&var272,&var1241,&vainSBool,&internal1_m1648_q0};
_S_noto  S_noto_1774_1 = {&B3IS22LDU,&var1242};
_S_noto  S_noto_1773_1 = {&A3IS22LDU,&var1243};
_S_noto  S_noto_1772_1 = {&B2IS12LDU,&var1244};
_S_noto  S_noto_1771_1 = {&A2IS12LDU,&var1245};
_S_noto  S_noto_1770_1 = {&B1IS12LDU,&var1246};
_S_noto  S_noto_1769_1 = {&A1IS12LDU,&var1247};
_S_noto  S_noto_1799_1 = {&B3IS21LDU,&var1248};
_S_noto  S_noto_1793_1 = {&B2IS21LDU,&var1249};
_S_noto  S_noto_1798_1 = {&A3IS21LDU,&var1250};
_S_noto  S_noto_1796_1 = {&B4IS21LDU,&var1251};
_S_noto  S_noto_1797_1 = {&A4IS21LDU,&var1252};
_S_andn  S_andn_1782_1 = {array_m1782_x_1,&iRM_17_,&var1253};
_S_noto  S_noto_1791_1 = {&B1IS21LDU,&var1254};
_S_noto  S_noto_1792_1 = {&A2IS21LDU,&var1255};
_S_noto  S_noto_1790_1 = {&A1IS21LDU,&var1256};
_S_rs  S_rs_1647_1 = {&var1261,&var273,&var1257,&vainSBool,&internal1_m1647_q0};
_S_rs  S_rs_1645_1 = {&var36,&var274,&var1258,&vainSBool,&internal1_m1645_q0};
_S_rs  S_rs_1644_1 = {&var1261,&var275,&var1259,&vainSBool,&internal1_m1644_q0};
_S_rs  S_rs_1642_1 = {&var17,&var276,&var1260,&vainSBool,&internal1_m1642_q0};
_S_newstage  S_newstage_2111_1 = {&var1273,&var1267,&var1272,&var1266,&var1261};
_S_samhd  S_samhd_2113_1 = {&var527,&var528,&var528,&var1258,&var1257,&var1258,&var1257,&B9IS11LDU,&B9IS11LDU,&B9IS21LDU,&B9IS21LDU,&bRM_1_,&fEM_A9UZ05RDU,&fEM_A9UZ03RDU,&fEM_A9UZ04RDU,&var1262,&var1263,&vainSBool,&var1264,&var1265,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1266,&var1267,&internal1_m2113_DvUp0,&internal1_m2113_DvDw0,&internal1_m2113_FDvUp0,&internal1_m2113_FDvDw0,&internal1_m2113_BlDv0,&internal1_m2113_Pkv0,&internal1_m2113_Pkav0,&internal1_m2113_Zkv0,&internal1_m2113_Zkav0,&internal1_m2113_txNm,&internal1_m2113_txSm,&internal1_m2113_txHr,&internal1_m2113_txLd,&internal1_m2113_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_2107_1 = {&var527,&var529,&var529,&var1260,&var1259,&var1260,&var1259,&A9IS11LDU,&A9IS11LDU,&A9IS21LDU,&A9IS21LDU,&bRM_1_,&fEM_A9UZ05RDU,&fEM_A9UZ03RDU,&fEM_A9UZ04RDU,&var1268,&var1269,&vainSBool,&var1270,&var1271,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1272,&var1273,&internal1_m2107_DvUp0,&internal1_m2107_DvDw0,&internal1_m2107_FDvUp0,&internal1_m2107_FDvDw0,&internal1_m2107_BlDv0,&internal1_m2107_Pkv0,&internal1_m2107_Pkav0,&internal1_m2107_Zkv0,&internal1_m2107_Zkav0,&internal1_m2107_txNm,&internal1_m2107_txSm,&internal1_m2107_txHr,&internal1_m2107_txLd,&internal1_m2107_fef,&bFirstEnterFlag};
_S_orni  S_orni_1424_1 = {array_m1424_x_1,&iRM_5_,&var1274,&var1275};
_S_noto  S_noto_84_1 = {&var399,&var1276};
_S_maz  S_maz_319_1 = {array_m319_x_1,&R0MW12IP1,&iRM_3_,&var1277};
_S_maz  S_maz_310_1 = {array_m310_x_1,&R0MW12IP1,&iRM_3_,&var1278};
_S_rs  S_rs_1498_1 = {&var540,&var1017,&var1279,&vainSBool,&internal1_m1498_q0};
_S_kvf  S_kvf_1501_1 = {&var1279,&var537,&fRM_0_0,&var1280,&vainSInt,&vainSInt,&internal1_m1501_x0,&internal1_m1501_y0,&bFirstEnterFlag};
_S_kvf  S_kvf_1925_1 = {&var454,&var442,&fRM_0_0,&var1281,&vainSInt,&vainSInt,&internal1_m1925_x0,&internal1_m1925_y0,&bFirstEnterFlag};
_S_kvf  S_kvf_1886_1 = {&var414,&var411,&fRM_0_0,&var1282,&vainSInt,&vainSInt,&internal1_m1886_x0,&internal1_m1886_y0,&bFirstEnterFlag};
_S_equz_p  S_equz_p_43_1 = {&R0MW13IP1,&iRM_1_,&var1283};
_S_noto  S_noto_40_1 = {&var1286,&var1284};
_S_equz_p  S_equz_p_47_1 = {&R0MW13IP1,&iRM_2_,&var1285};
_S_equz_p  S_equz_p_38_1 = {&R0MW13IP1,&iRM_3_,&var1286};
_S_noto  S_noto_1929_1 = {&var1132,&var1287};
_S_rs  S_rs_295_1 = {&var827,&var828,&var1288,&vainSBool,&internal1_m295_q0};
_S_orn  S_orn_605_1 = {array_m605_x_1,&iRM_5_,&var1289};
_S_noto  S_noto_1014_1 = {&lEM_R0MD01LC1,&var1290};
_S_rs  S_rs_1005_1 = {&var604,&var920,&var1291,&vainSBool,&internal1_m1005_q0};
_S_rs  S_rs_636_1 = {&var782,&var784,&var1292,&vainSBool,&internal1_m636_q0};
_S_noto  S_noto_1404_1 = {&var963,&var1293};
_S_orn  S_orn_1383_1 = {array_m1383_x_1,&iRM_8_,&var1294};
_S_noto  S_noto_1382_1 = {&var1462,&var1295};
_S_noto  S_noto_1381_1 = {&var1472,&var1296};
_S_noto  S_noto_1364_1 = {&var964,&var1297};
_S_noto  S_noto_1373_1 = {&R8IS11LDU,&var1298};
_S_charint  S_charint_1310_1 = {&var1301,&var1299};
_S_ornc  S_ornc_1318_1 = {array_m1318_x_1,&iRM_3_,&var1300,&var1301};
_S_fsumz  S_fsumz_1311_1 = {&var1299,&iRM_1_,&var1302};
_S_cnshd  S_cnshd_1320_1 = {&R0MD34LP1,&var1731,&var994,&var318,&var1300,&var649,&var645,&iRM_1_,array_m1320_Lt_fw_1,array_m1320_Vr_fw_1,&iRM_1_,array_m1320_Lt_bw_1,array_m1320_Vr_bw_1,&fEM_A3UC08RDU,&fEM_A3UC07RDU,&fEM_A3UL01RDU,&fEM_A3UC02RDU,&var1303,&vainSBool,&var1304,&var1305,&var1306,&var1307,&var1308,&var1309,&var1310,&var1311,&var1312,&var1313,&internal1_m1320_X0,&internal1_m1320_t0,&internal1_m1320_BLDv0};
_S_zpfs  S_zpfs_1339_1 = {&var1322,&fRM_2_0,&var1314,&internal1_m1339_tx,&internal1_m1339_y0};
_S_zpfs  S_zpfs_1341_1 = {&var1321,&fRM_3_0,&var1315,&internal1_m1341_tx,&internal1_m1341_y0};
_S_fnapb  S_fnapb_1348_1 = {&var1731,&var994,&var648,&R0MD34LP1,&var1305,&var1312,&fEM_B8UV04RDU,&fEM_A3UV01RDU,&fEM_A3UV02RDU,&fEM_A3UC06RDU,&fEM_A3UC05RDU,&iRM_60_,&fEM_A3UL04RDU,&fEM_A3UL05RDU,&fEM_A3UL03RDU,&var1316,&var1317,&var1318,&var1319,&var1320,&var1321,&var1322,&vainSFloat,&internal1_m1348_xptr,array_m1348_x0_1,array_m1348_tim0_1,&internal1_m1348_sumtim,&internal1_m1348_StSpeed,&internal1_m1348_Vz0,&internal1_m1348_flRazg,&internal1_m1348_DelSp,&internal1_m1348_z0,&internal1_m1348_txZS,&internal1_m1348_tx,&internal1_m1348_txd,&internal1_m1348_txMBl,&internal1_m1348_txBl,&internal1_m1348_Speed0,&internal1_m1348_xz0,&internal1_m1348_tz0,&internal1_m1348_Shift0,&internal1_m1348_ShCntlSp0,&internal1_m1348_ShiftControl,&bFirstEnterFlag};
_S_newstage  S_newstage_915_1 = {&var1332,&var1300,&var1335,&var1303,&var1323};
_S_rs  S_rs_634_1 = {&var783,&var787,&var1324,&vainSBool,&internal1_m634_q0};
_S_noto  S_noto_992_1 = {&var948,&var1325};
_S_orn  S_orn_971_1 = {array_m971_x_1,&iRM_8_,&var1326};
_S_noto  S_noto_970_1 = {&var1462,&var1327};
_S_noto  S_noto_969_1 = {&var1472,&var1328};
_S_noto  S_noto_953_1 = {&var964,&var1329};
_S_noto  S_noto_961_1 = {&R8IS11LDU,&var1330};
_S_charint  S_charint_892_1 = {&var1333,&var1331};
_S_ornc  S_ornc_901_1 = {array_m901_x_1,&iRM_3_,&var1332,&var1333};
_S_fsumz  S_fsumz_893_1 = {&var1331,&iRM_1_,&var1334};
_S_cnshd  S_cnshd_903_1 = {&R0MD34LP1,&var1734,&var993,&var322,&var1332,&var684,&var685,&iRM_1_,array_m903_Lt_fw_1,array_m903_Vr_fw_1,&iRM_1_,array_m903_Lt_bw_1,array_m903_Vr_bw_1,&fEM_A3UC08RDU,&fEM_A3UC07RDU,&fEM_A3UL01RDU,&fEM_A3UC02RDU,&var1335,&vainSBool,&var1336,&var1337,&var1338,&var1339,&var1340,&var1341,&var1342,&var1343,&var1344,&var1345,&internal1_m903_X0,&internal1_m903_t0,&internal1_m903_BLDv0};
_S_zpfs  S_zpfs_927_1 = {&var1354,&fRM_2_0,&var1346,&internal1_m927_tx,&internal1_m927_y0};
_S_zpfs  S_zpfs_930_1 = {&var1353,&fRM_3_0,&var1347,&internal1_m930_tx,&internal1_m930_y0};
_S_fnapb  S_fnapb_936_1 = {&var1734,&var993,&var683,&R0MD34LP1,&var1337,&var1344,&fEM_B8UV04RDU,&fEM_A3UV01RDU,&fEM_A3UV02RDU,&fEM_A3UC06RDU,&fEM_A3UC05RDU,&iRM_60_,&fEM_A3UL04RDU,&fEM_A3UL05RDU,&fEM_A3UL03RDU,&var1348,&var1349,&var1350,&var1351,&var1352,&var1353,&var1354,&vainSFloat,&internal1_m936_xptr,array_m936_x0_1,array_m936_tim0_1,&internal1_m936_sumtim,&internal1_m936_StSpeed,&internal1_m936_Vz0,&internal1_m936_flRazg,&internal1_m936_DelSp,&internal1_m936_z0,&internal1_m936_txZS,&internal1_m936_tx,&internal1_m936_txd,&internal1_m936_txMBl,&internal1_m936_txBl,&internal1_m936_Speed0,&internal1_m936_xz0,&internal1_m936_tz0,&internal1_m936_Shift0,&internal1_m936_ShCntlSp0,&internal1_m936_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_587_1 = {&var963,&var1355};
_S_noto  S_noto_560_1 = {&var1462,&var1356};
_S_noto  S_noto_559_1 = {&var1472,&var1357};
_S_noto  S_noto_544_1 = {&var964,&var1358};
_S_noto  S_noto_551_1 = {&R8IS11LDU,&var1359};
_S_charint  S_charint_496_1 = {&var1362,&var1360};
_S_ornc  S_ornc_502_1 = {array_m502_x_1,&iRM_3_,&var1361,&var1362};
_S_fsumz  S_fsumz_497_1 = {&var1360,&iRM_1_,&var1363};
_S_cnshd  S_cnshd_505_1 = {&R0MD34LP1,&var1744,&var995,&var326,&var1361,&var755,&var749,&iRM_2_,array_m505_Lt_fw_1,array_m505_Vr_fw_1,&iRM_1_,array_m505_Lt_bw_1,array_m505_Vr_bw_1,&fEM_A1UC08RDU,&fEM_A1UC07RDU,&fEM_A1UL01RDU,&fEM_A1UC02RDU,&var1364,&vainSBool,&var1365,&var1366,&var1367,&var1368,&var1369,&var1370,&var1371,&var1372,&var1373,&var1374,&internal1_m505_X0,&internal1_m505_t0,&internal1_m505_BLDv0};
_S_zpfs  S_zpfs_525_1 = {&var1383,&fRM_2_0,&var1375,&internal1_m525_tx,&internal1_m525_y0};
_S_zpfs  S_zpfs_526_1 = {&var1382,&fRM_3_0,&var1376,&internal1_m526_tx,&internal1_m526_y0};
_S_fnapb  S_fnapb_532_1 = {&var1744,&var995,&var753,&R0MD34LP1,&var1366,&var1373,&fEM_B8UV04RDU,&fEM_A1UV01RDU,&fEM_A1UV02RDU,&fEM_A1UC06RDU,&fEM_A1UC05RDU,&iRM_150_,&fEM_A1UL04RDU,&fEM_A1UL05RDU,&fEM_A1UL03RDU,&var1377,&var1378,&var1379,&var1380,&var1381,&var1382,&var1383,&vainSFloat,&internal1_m532_xptr,array_m532_x0_1,array_m532_tim0_1,&internal1_m532_sumtim,&internal1_m532_StSpeed,&internal1_m532_Vz0,&internal1_m532_flRazg,&internal1_m532_DelSp,&internal1_m532_z0,&internal1_m532_txZS,&internal1_m532_tx,&internal1_m532_txd,&internal1_m532_txMBl,&internal1_m532_txBl,&internal1_m532_Speed0,&internal1_m532_xz0,&internal1_m532_tz0,&internal1_m532_Shift0,&internal1_m532_ShCntlSp0,&internal1_m532_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_652_1 = {&R0MD33LP1,&var1384};
_S_noto  S_noto_273_1 = {&var948,&var1385};
_S_newstage  S_newstage_221_1 = {&var1394,&var1361,&var1397,&var1364,&var1386};
_S_rs  S_rs_631_1 = {&var778,&var790,&var1387,&vainSBool,&internal1_m631_q0};
_S_orn  S_orn_244_1 = {array_m244_x_1,&iRM_12_,&var1388};
_S_noto  S_noto_243_1 = {&var1462,&var1389};
_S_noto  S_noto_242_1 = {&var1472,&var1390};
_S_noto  S_noto_227_1 = {&var964,&var1391};
_S_noto  S_noto_234_1 = {&R8IS11LDU,&var1392};
_S_charint  S_charint_163_1 = {&var1395,&var1393};
_S_ornc  S_ornc_169_1 = {array_m169_x_1,&iRM_3_,&var1394,&var1395};
_S_fsumz  S_fsumz_164_1 = {&var1393,&iRM_1_,&var1396};
_S_cnshd  S_cnshd_174_1 = {&R0MD34LP1,&var1722,&var996,&var330,&var1394,&var735,&var728,&iRM_2_,array_m174_Lt_fw_1,array_m174_Vr_fw_1,&iRM_1_,array_m174_Lt_bw_1,array_m174_Vr_bw_1,&fEM_A1UC08RDU,&fEM_A1UC07RDU,&fEM_A1UL01RDU,&fEM_A1UC02RDU,&var1397,&vainSBool,&var1398,&var1399,&var1400,&var1401,&var1402,&var1403,&var1404,&var1405,&var1406,&var1407,&internal1_m174_X0,&internal1_m174_t0,&internal1_m174_BLDv0};
_S_fnapb  S_fnapb_213_1 = {&var1722,&var996,&var731,&R0MD34LP1,&var1399,&var1406,&fEM_B8UV04RDU,&fEM_A1UV01RDU,&fEM_A1UV02RDU,&fEM_A1UC06RDU,&fEM_A1UC05RDU,&iRM_150_,&fEM_A1UL04RDU,&fEM_A1UL05RDU,&fEM_A1UL03RDU,&var1408,&var1409,&var1410,&var1411,&var1412,&var1413,&var1414,&vainSFloat,&internal1_m213_xptr,array_m213_x0_1,array_m213_tim0_1,&internal1_m213_sumtim,&internal1_m213_StSpeed,&internal1_m213_Vz0,&internal1_m213_flRazg,&internal1_m213_DelSp,&internal1_m213_z0,&internal1_m213_txZS,&internal1_m213_tx,&internal1_m213_txd,&internal1_m213_txMBl,&internal1_m213_txBl,&internal1_m213_Speed0,&internal1_m213_xz0,&internal1_m213_tz0,&internal1_m213_Shift0,&internal1_m213_ShCntlSp0,&internal1_m213_ShiftControl,&bFirstEnterFlag};
_S_rs  S_rs_657_1 = {&var789,&var792,&var1415,&vainSBool,&internal1_m657_q0};
_S_newstage  S_newstage_472_1 = {&var1434,&var1425,&var1433,&var1424,&var1416};
_S_samhd  S_samhd_476_1 = {&R0MD34LP1,&var758,&var758,&var381,&var380,&R2VS12LDU,&R2VS22LDU,&R2IS11LDU,&R2IS11LDU,&R2IS21LDU,&R2IS21LDU,&bRM_0_,&fEM_R1UZ05RDU,&fEM_R1UZ03RDU,&fEM_R1UZ04RDU,&var1417,&var1418,&var1419,&var1420,&var1421,&var1422,&vainSBool,&vainSBool,&var1423,&var1424,&var1425,&internal1_m476_DvUp0,&internal1_m476_DvDw0,&internal1_m476_FDvUp0,&internal1_m476_FDvDw0,&internal1_m476_BlDv0,&internal1_m476_Pkv0,&internal1_m476_Pkav0,&internal1_m476_Zkv0,&internal1_m476_Zkav0,&internal1_m476_txNm,&internal1_m476_txSm,&internal1_m476_txHr,&internal1_m476_txLd,&internal1_m476_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_470_1 = {&R0MD34LP1,&var759,&var759,&var379,&var378,&R1VS12LDU,&R1VS22LDU,&R1IS11LDU,&R1IS11LDU,&R1IS21LDU,&R1IS21LDU,&bRM_0_,&fEM_R1UZ05RDU,&fEM_R1UZ03RDU,&fEM_R1UZ04RDU,&var1426,&var1427,&var1428,&var1429,&var1430,&var1431,&vainSBool,&vainSBool,&var1432,&var1433,&var1434,&internal1_m470_DvUp0,&internal1_m470_DvDw0,&internal1_m470_FDvUp0,&internal1_m470_FDvDw0,&internal1_m470_BlDv0,&internal1_m470_Pkv0,&internal1_m470_Pkav0,&internal1_m470_Zkv0,&internal1_m470_Zkav0,&internal1_m470_txNm,&internal1_m470_txSm,&internal1_m470_txHr,&internal1_m470_txLd,&internal1_m470_fef,&bFirstEnterFlag};
_S_orn  S_orn_876_1 = {array_m876_x_1,&iRM_10_,&var1435};
_S_noto  S_noto_875_1 = {&var1462,&var1436};
_S_noto  S_noto_874_1 = {&var1472,&var1437};
_S_noto  S_noto_856_1 = {&var964,&var1438};
_S_noto  S_noto_866_1 = {&R8IS11LDU,&var1439};
_S_charint  S_charint_813_1 = {&var1442,&var1440};
_S_ornc  S_ornc_821_1 = {array_m821_x_1,&iRM_3_,&var1441,&var1442};
_S_fsumz  S_fsumz_814_1 = {&var1440,&iRM_1_,&var1443};
_S_cnshd  S_cnshd_823_1 = {&R0MD34LP1,&var1737,&var992,&var992,&var1441,&var708,&var622,&iRM_2_,array_m823_Lt_fw_1,array_m823_Vr_fw_1,&iRM_1_,array_m823_Lt_bw_1,array_m823_Vr_bw_1,&fEM_A2UC08RDU,&fEM_A2UC07RDU,&fEM_A2UL01RDU,&fEM_A2UC02RDU,&var1444,&vainSBool,&var1445,&var1446,&var1447,&var1448,&var1449,&var1450,&var1451,&var1452,&var1453,&var1454,&internal1_m823_X0,&internal1_m823_t0,&internal1_m823_BLDv0};
_S_fnapb  S_fnapb_843_1 = {&var1737,&var992,&var704,&R0MD34LP1,&var1446,&var1453,&fEM_B8UV04RDU,&fEM_A2UV01RDU,&fEM_A2UV02RDU,&fEM_A2UC06RDU,&fEM_A2UC05RDU,&iRM_80_,&fEM_A2UL04RDU,&fEM_A2UL05RDU,&fEM_A2UL83RDU,&var1455,&var1456,&var1457,&var1458,&var1459,&var1460,&var1461,&vainSFloat,&internal1_m843_xptr,array_m843_x0_1,array_m843_tim0_1,&internal1_m843_sumtim,&internal1_m843_StSpeed,&internal1_m843_Vz0,&internal1_m843_flRazg,&internal1_m843_DelSp,&internal1_m843_z0,&internal1_m843_txZS,&internal1_m843_tx,&internal1_m843_txd,&internal1_m843_txMBl,&internal1_m843_txBl,&internal1_m843_Speed0,&internal1_m843_xz0,&internal1_m843_tz0,&internal1_m843_Shift0,&internal1_m843_ShCntlSp0,&internal1_m843_ShiftControl,&bFirstEnterFlag};
_S_cnshd  S_cnshd_1602_1 = {&R0MD34LP1,&var1728,&var314,&var314,&var531,&var534,&lRM_1_,&iRM_1_,array_m1602_Lt_fw_1,array_m1602_Vr_fw_1,&iRM_1_,array_m1602_Lt_bw_1,array_m1602_Vr_bw_1,&fEM_B8UC01RDU,&fEM_B8UC02RDU,&fEM_B8UL01RDU,&fRM_0_0,&var1462,&vainSBool,&vainSFloat,&var1463,&var1464,&var1465,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1466,&internal1_m1602_X0,&internal1_m1602_t0,&internal1_m1602_BLDv0};
_S_newstage  S_newstage_1263_1 = {&var1480,&var1441,&var1485,&var1444,&var1467};
_S_orn  S_orn_1293_1 = {array_m1293_x_1,&iRM_10_,&var1468};
_S_orn  S_orn_152_1 = {array_m152_x_1,&iRM_5_,&var1469};
_S_noto  S_noto_1292_1 = {&var1462,&var1470};
_S_noto  S_noto_1291_1 = {&var1472,&var1471};
_S_cnshd  S_cnshd_1123_1 = {&R0MD34LP1,&var1725,&var314,&var314,&var849,&var532,&lRM_1_,&iRM_1_,array_m1123_Lt_fw_1,array_m1123_Vr_fw_1,&iRM_1_,array_m1123_Lt_bw_1,array_m1123_Vr_bw_1,&fEM_B8UC01RDU,&fEM_B8UC02RDU,&fEM_B8UL01RDU,&fRM_0_0,&var1472,&vainSBool,&vainSFloat,&var1473,&var1474,&var1475,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1476,&internal1_m1123_X0,&internal1_m1123_t0,&internal1_m1123_BLDv0};
_S_noto  S_noto_1273_1 = {&var964,&var1477};
_S_noto  S_noto_1283_1 = {&R8IS11LDU,&var1478};
_S_charint  S_charint_1213_1 = {&var1481,&var1479};
_S_ornc  S_ornc_1221_1 = {array_m1221_x_1,&iRM_3_,&var1480,&var1481};
_S_noto  S_noto_616_1 = {&lEM_R0MD01LC1,&var1482};
_S_fsumz  S_fsumz_1214_1 = {&var1479,&iRM_1_,&var1483};
_S_rs  S_rs_629_1 = {&var800,&var802,&var1484,&vainSBool,&internal1_m629_q0};
_S_cnshd  S_cnshd_1223_1 = {&R0MD34LP1,&var1740,&var991,&var991,&var1480,&var625,&var618,&iRM_2_,array_m1223_Lt_fw_1,array_m1223_Vr_fw_1,&iRM_1_,array_m1223_Lt_bw_1,array_m1223_Vr_bw_1,&fEM_A2UC08RDU,&fEM_A2UC07RDU,&fEM_A2UL01RDU,&fEM_A2UC02RDU,&var1485,&vainSBool,&var1486,&var1487,&var1488,&var1489,&var1490,&var1491,&var1492,&var1493,&var1494,&var1495,&internal1_m1223_X0,&internal1_m1223_t0,&internal1_m1223_BLDv0};
_S_zpfs  S_zpfs_1243_1 = {&var1504,&fRM_2_0,&var1496,&internal1_m1243_tx,&internal1_m1243_y0};
_S_zpfs  S_zpfs_1251_1 = {&var1503,&fRM_3_0,&var1497,&internal1_m1251_tx,&internal1_m1251_y0};
_S_fnapb  S_fnapb_1257_1 = {&var1740,&var991,&var626,&R0MD34LP1,&var1487,&var1494,&fEM_B8UV04RDU,&fEM_A2UV01RDU,&fEM_A2UV02RDU,&fEM_A2UC06RDU,&fEM_A2UC05RDU,&iRM_80_,&fEM_A2UL04RDU,&fEM_A2UL05RDU,&fEM_A2UL03RDU,&var1498,&var1499,&var1500,&var1501,&var1502,&var1503,&var1504,&vainSFloat,&internal1_m1257_xptr,array_m1257_x0_1,array_m1257_tim0_1,&internal1_m1257_sumtim,&internal1_m1257_StSpeed,&internal1_m1257_Vz0,&internal1_m1257_flRazg,&internal1_m1257_DelSp,&internal1_m1257_z0,&internal1_m1257_txZS,&internal1_m1257_tx,&internal1_m1257_txd,&internal1_m1257_txMBl,&internal1_m1257_txBl,&internal1_m1257_Speed0,&internal1_m1257_xz0,&internal1_m1257_tz0,&internal1_m1257_Shift0,&internal1_m1257_ShCntlSp0,&internal1_m1257_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_1587_1 = {&R8IS11LDU,&var1505};
_S_rs  S_rs_649_1 = {&var803,&var804,&var1506,&vainSBool,&internal1_m649_q0};
_S_zpfs  S_zpfs_1615_1 = {&var1517,&fRM_2_0,&var1507,&internal1_m1615_tx,&internal1_m1615_y0};
_S_zpfs  S_zpfs_1617_1 = {&var1516,&fRM_3_0,&var1508,&internal1_m1617_tx,&internal1_m1617_y0};
_S_samhd  S_samhd_1605_1 = {&R0MD34LP1,&var534,&var534,&var1464,&var1465,&var1511,&var1512,&A8IS12LDU,&A8IS12LDU,&A8IS22LDU,&A8IS22LDU,&bRM_3_,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&fEM_B8UL07RDU,&vainSBool,&vainSBool,&var1509,&var1510,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,&internal1_m1605_DvUp0,&internal1_m1605_DvDw0,&internal1_m1605_FDvUp0,&internal1_m1605_FDvDw0,&internal1_m1605_BlDv0,&internal1_m1605_Pkv0,&internal1_m1605_Pkav0,&internal1_m1605_Zkv0,&internal1_m1605_Zkav0,&internal1_m1605_txNm,&internal1_m1605_txSm,&internal1_m1605_txHr,&internal1_m1605_txLd,&internal1_m1605_fef,&bFirstEnterFlag};
_S_fnapb  S_fnapb_1622_1 = {&var1728,&var314,&var530,&R0MD34LP1,&var1463,&fEM_B8UV03RDU,&fEM_B8UV04RDU,&fEM_B8UV01RDU,&fEM_B8UV02RDU,&fEM_B8UC06RDU,&fEM_B8UC05RDU,&iRM_20_,&fEM_B8UL04RDU,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&var1511,&var1512,&var1513,&var1514,&var1515,&var1516,&var1517,&vainSFloat,&internal1_m1622_xptr,array_m1622_x0_1,array_m1622_tim0_1,&internal1_m1622_sumtim,&internal1_m1622_StSpeed,&internal1_m1622_Vz0,&internal1_m1622_flRazg,&internal1_m1622_DelSp,&internal1_m1622_z0,&internal1_m1622_txZS,&internal1_m1622_tx,&internal1_m1622_txd,&internal1_m1622_txMBl,&internal1_m1622_txBl,&internal1_m1622_Speed0,&internal1_m1622_xz0,&internal1_m1622_tz0,&internal1_m1622_Shift0,&internal1_m1622_ShCntlSp0,&internal1_m1622_ShiftControl,&bFirstEnterFlag};
_S_zpfs  S_zpfs_1139_1 = {&var1534,&fRM_2_0,&var1518,&internal1_m1139_tx,&internal1_m1139_y0};
_S_zpfs  S_zpfs_1143_1 = {&var1533,&fRM_3_0,&var1519,&internal1_m1143_tx,&internal1_m1143_y0};
_S_noto  S_noto_1108_1 = {&R8IS11LDU,&var1520};
_S_orn  S_orn_1094_1 = {array_m1094_x_1,&iRM_8_,&var1521};
_S_noto  S_noto_618_1 = {&var1525,&var1522};
_S_rs  S_rs_639_1 = {&var805,&var806,&var1523,&vainSBool,&internal1_m639_q0};
_S_orn  S_orn_606_1 = {array_m606_x_1,&iRM_18_,&var1524};
_S_rs  S_rs_604_1 = {&var1289,&var921,&var1525,&vainSBool,&internal1_m604_q0};
_S_samhd  S_samhd_1130_1 = {&R0MD34LP1,&var532,&var532,&var1474,&var1475,&var1528,&var1529,&var157,&var157,&var156,&var156,&bRM_3_,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&fEM_B8UL07RDU,&vainSBool,&vainSBool,&var1526,&var1527,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,&internal1_m1130_DvUp0,&internal1_m1130_DvDw0,&internal1_m1130_FDvUp0,&internal1_m1130_FDvDw0,&internal1_m1130_BlDv0,&internal1_m1130_Pkv0,&internal1_m1130_Pkav0,&internal1_m1130_Zkv0,&internal1_m1130_Zkav0,&internal1_m1130_txNm,&internal1_m1130_txSm,&internal1_m1130_txHr,&internal1_m1130_txLd,&internal1_m1130_fef,&bFirstEnterFlag};
_S_fnapb  S_fnapb_1147_1 = {&var1725,&var314,&var848,&R0MD34LP1,&var1473,&fEM_B8UV03RDU,&fEM_B8UV04RDU,&fEM_B8UV01RDU,&fEM_B8UV02RDU,&fEM_B8UC06RDU,&fEM_B8UC05RDU,&iRM_20_,&fEM_B8UL04RDU,&fEM_B8UL06RDU,&fEM_B8UL03RDU,&var1528,&var1529,&var1530,&var1531,&var1532,&var1533,&var1534,&vainSFloat,&internal1_m1147_xptr,array_m1147_x0_1,array_m1147_tim0_1,&internal1_m1147_sumtim,&internal1_m1147_StSpeed,&internal1_m1147_Vz0,&internal1_m1147_flRazg,&internal1_m1147_DelSp,&internal1_m1147_z0,&internal1_m1147_txZS,&internal1_m1147_tx,&internal1_m1147_txd,&internal1_m1147_txMBl,&internal1_m1147_txBl,&internal1_m1147_Speed0,&internal1_m1147_xz0,&internal1_m1147_tz0,&internal1_m1147_Shift0,&internal1_m1147_ShCntlSp0,&internal1_m1147_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_729_1 = {&A5IS21LDU,&var1535};
_S_vmemb  S_vmemb_752_1 = {&var1537,&var1536,&internal1_m752_x0};
_S_noto  S_noto_760_1 = {&var158,&var1537};
_S_vmemb  S_vmemb_721_1 = {&var1535,&var1538,&internal1_m721_x0};
_S_vmemb  S_vmemb_684_1 = {&var1553,&var1539,&internal1_m684_x0};
_S_newstage  S_newstage_795_1 = {&var1597,&var1588,&var1596,&var1587,&var1540};
_S_newstage  S_newstage_1192_1 = {&var1579,&var1570,&var1578,&var1569,&var1541};
_S_newstage  S_newstage_401_1 = {&var1624,&var1615,&var1623,&var1614,&var1542};
_S_noto  S_noto_771_1 = {&var159,&var1543};
_S_rs  S_rs_777_1 = {&var869,&var1542,&var1544,&vainSBool,&internal1_m777_q0};
_S_rs  S_rs_772_1 = {&var870,&var970,&var1545,&vainSBool,&internal1_m772_q0};
_S_noto  S_noto_764_1 = {&var1626,&var1546};
_S_noto  S_noto_762_1 = {&var1627,&var1547};
_S_rs  S_rs_740_1 = {&var874,&var1542,&var1548,&vainSBool,&internal1_m740_q0};
_S_rs  S_rs_745_1 = {&var873,&var1540,&var1549,&vainSBool,&internal1_m745_q0};
_S_rs  S_rs_753_1 = {&var940,&var879,&var1550,&vainSBool,&internal1_m753_q0};
_S_rs  S_rs_765_1 = {&var871,&var877,&var1551,&vainSBool,&internal1_m765_q0};
_S_noto  S_noto_720_1 = {&var159,&var1552};
_S_noto  S_noto_676_1 = {&var158,&var1553};
_S_noto  S_noto_432_1 = {&R8IS11LDU,&var1554};
_S_orn  S_orn_446_1 = {array_m446_x_1,&iRM_7_,&var1555};
_S_orn  S_orn_428_1 = {array_m428_x_1,&iRM_7_,&var1556};
_S_rs  S_rs_743_1 = {&var878,&var883,&var1557,&vainSBool,&internal1_m743_q0};
_S_noto  S_noto_160_1 = {&B2IS12LDU,&var1558};
_S_noto  S_noto_149_1 = {&A2IS12LDU,&var1559};
_S_noto  S_noto_150_1 = {&B1IS12LDU,&var1560};
_S_noto  S_noto_158_1 = {&A1IS12LDU,&var1561};
_S_samhd  S_samhd_1200_1 = {&var852,&var853,&var853,&var1162,&var1161,&var1162,&var1161,&B4IS11LDU,&B4IS11LDU,&B4IS21LDU,&B4IS21LDU,&bRM_1_,&fEM_A4UZ05RDU,&fEM_A4UZ03RDU,&fEM_A4UZ04RDU,&var1562,&var1563,&vainSBool,&var1564,&var1565,&vainSBool,&var1566,&var1567,&var1568,&var1569,&var1570,&internal1_m1200_DvUp0,&internal1_m1200_DvDw0,&internal1_m1200_FDvUp0,&internal1_m1200_FDvDw0,&internal1_m1200_BlDv0,&internal1_m1200_Pkv0,&internal1_m1200_Pkav0,&internal1_m1200_Zkv0,&internal1_m1200_Zkav0,&internal1_m1200_txNm,&internal1_m1200_txSm,&internal1_m1200_txHr,&internal1_m1200_txLd,&internal1_m1200_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_1189_1 = {&var852,&var855,&var855,&var1162,&var1161,&var1162,&var1161,&A4IS11LDU,&A4IS11LDU,&A4IS21LDU,&A4IS21LDU,&bRM_1_,&fEM_A4UZ05RDU,&fEM_A4UZ03RDU,&fEM_A4UZ04RDU,&var1571,&var1572,&vainSBool,&var1573,&var1574,&vainSBool,&var1575,&var1576,&var1577,&var1578,&var1579,&internal1_m1189_DvUp0,&internal1_m1189_DvDw0,&internal1_m1189_FDvUp0,&internal1_m1189_FDvDw0,&internal1_m1189_BlDv0,&internal1_m1189_Pkv0,&internal1_m1189_Pkav0,&internal1_m1189_Zkv0,&internal1_m1189_Zkav0,&internal1_m1189_txNm,&internal1_m1189_txSm,&internal1_m1189_txHr,&internal1_m1189_txLd,&internal1_m1189_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_797_1 = {&R0MD34LP1,&var710,&var710,&var971,&var866,&B5VS12LDU,&B5VS22LDU,&B5IS11LDU,&B5IS11LDU,&B5IS21LDU,&B5IS21LDU,&bRM_0_,&fEM_A5UZ05RDU,&fEM_A5UZ03RDU,&fEM_A5UZ04RDU,&var1580,&var1581,&var1582,&var1583,&var1584,&var1585,&vainSBool,&vainSBool,&var1586,&var1587,&var1588,&internal1_m797_DvUp0,&internal1_m797_DvDw0,&internal1_m797_FDvUp0,&internal1_m797_FDvDw0,&internal1_m797_BlDv0,&internal1_m797_Pkv0,&internal1_m797_Pkav0,&internal1_m797_Zkv0,&internal1_m797_Zkav0,&internal1_m797_txNm,&internal1_m797_txSm,&internal1_m797_txHr,&internal1_m797_txLd,&internal1_m797_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_793_1 = {&R0MD34LP1,&var712,&var712,&var971,&var866,&A5VS12LDU,&A5VS22LDU,&A5IS11LDU,&A5IS11LDU,&A5IS21LDU,&A5IS21LDU,&bRM_0_,&fEM_A5UZ05RDU,&fEM_A5UZ03RDU,&fEM_A5UZ04RDU,&var1589,&var1590,&var1591,&var1592,&var1593,&var1594,&vainSBool,&vainSBool,&var1595,&var1596,&var1597,&internal1_m793_DvUp0,&internal1_m793_DvDw0,&internal1_m793_FDvUp0,&internal1_m793_FDvDw0,&internal1_m793_BlDv0,&internal1_m793_Pkv0,&internal1_m793_Pkav0,&internal1_m793_Zkv0,&internal1_m793_Zkav0,&internal1_m793_txNm,&internal1_m793_txSm,&internal1_m793_txHr,&internal1_m793_txLd,&internal1_m793_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_375_1 = {&R0MD34LP1,&var383,&var382,&var875,&var868,&R4VS12LDU,&R4VS22LDU,&R4IS11LDU,&R4IS12LDU,&R4IS21LDU,&R4IS22LDU,&bRM_0_,&fEM_R4UZ05RDU,&fEM_R4UZ03RDU,&fEM_R4UZ04RDU,&var1598,&var1599,&var1600,&var1601,&var1602,&var1603,&vainSBool,&vainSBool,&var1604,&var1605,&vainSBool,&internal1_m375_DvUp0,&internal1_m375_DvDw0,&internal1_m375_FDvUp0,&internal1_m375_FDvDw0,&internal1_m375_BlDv0,&internal1_m375_Pkv0,&internal1_m375_Pkav0,&internal1_m375_Zkv0,&internal1_m375_Zkav0,&internal1_m375_txNm,&internal1_m375_txSm,&internal1_m375_txHr,&internal1_m375_txLd,&internal1_m375_fef,&bFirstEnterFlag};
_S_noto  S_noto_687_1 = {&R8IS11LDU,&var1606};
_S_samhd  S_samhd_404_1 = {&R0MD34LP1,&var1555,&var941,&var947,&var867,&B6VS12LDU,&B6VS22LDU,&B6IS11LDU,&B6IS11LDU,&B6IS21LDU,&B6IS21LDU,&bRM_0_,&fEM_A6UZ05RDU,&fEM_A6UZ03RDU,&fEM_A6UZ04RDU,&var1607,&var1608,&var1609,&var1610,&var1611,&var1612,&vainSBool,&vainSBool,&var1613,&var1614,&var1615,&internal1_m404_DvUp0,&internal1_m404_DvDw0,&internal1_m404_FDvUp0,&internal1_m404_FDvDw0,&internal1_m404_BlDv0,&internal1_m404_Pkv0,&internal1_m404_Pkav0,&internal1_m404_Zkv0,&internal1_m404_Zkav0,&internal1_m404_txNm,&internal1_m404_txSm,&internal1_m404_txHr,&internal1_m404_txLd,&internal1_m404_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_398_1 = {&R0MD34LP1,&var1556,&var942,&var947,&var867,&A6VS12LDU,&A6VS22LDU,&A6IS11LDU,&A6IS11LDU,&A6IS21LDU,&A6IS21LDU,&bRM_0_,&fEM_A6UZ05RDU,&fEM_A6UZ03RDU,&fEM_A6UZ04RDU,&var1616,&var1617,&var1618,&var1619,&var1620,&var1621,&vainSBool,&vainSBool,&var1622,&var1623,&var1624,&internal1_m398_DvUp0,&internal1_m398_DvDw0,&internal1_m398_FDvUp0,&internal1_m398_FDvDw0,&internal1_m398_BlDv0,&internal1_m398_Pkv0,&internal1_m398_Pkav0,&internal1_m398_Zkv0,&internal1_m398_Zkav0,&internal1_m398_txNm,&internal1_m398_txSm,&internal1_m398_txHr,&internal1_m398_txLd,&internal1_m398_fef,&bFirstEnterFlag};
_S_orn  S_orn_776_1 = {array_m776_x_1,&iRM_17_,&var1625};
_S_rs  S_rs_749_1 = {&var881,&var68,&var1626,&vainSBool,&internal1_m749_q0};
_S_rs  S_rs_746_1 = {&var882,&var69,&var1627,&vainSBool,&internal1_m746_q0};
_S_orni  S_orni_138_1 = {array_m138_x_1,&iRM_21_,&var1628,&vainSLong};
_S_equz_p  S_equz_p_80_1 = {&R0MW11IP2,&iRM_6_,&var1629};
_S_equz_p  S_equz_p_78_1 = {&R0MW11IP2,&iRM_5_,&var1630};
_S_equz_p  S_equz_p_76_1 = {&R0MW11IP2,&iRM_4_,&var1631};
_S_equz_p  S_equz_p_75_1 = {&R0MW11IP2,&iRM_3_,&var1632};
_S_equz_p  S_equz_p_74_1 = {&R0MW11IP2,&iRM_2_,&var1633};
_S_equz_p  S_equz_p_71_1 = {&R0MW11IP2,&iRM_1_,&var1634};
_S_equz_p  S_equz_p_67_1 = {&R0MW14IP1,&iRM_3_,&var1635};
_S_equz_p  S_equz_p_61_1 = {&R0MW14IP1,&iRM_1_,&vainSBool};
_S_equz_p  S_equz_p_63_1 = {&R0MW14IP1,&iRM_2_,&var1636};
_S_equz_p  S_equz_p_56_1 = {&R0MW11IP1,&iRM_3_,&var1637};
_S_equz_p  S_equz_p_49_1 = {&R0MW11IP1,&iRM_1_,&var1638};
_S_equz_p  S_equz_p_52_1 = {&R0MW11IP1,&iRM_2_,&var1639};
_S_equz_p  S_equz_p_106_1 = {&R0MW16IP1,&iRM_11_,&var1640};
_S_equz_p  S_equz_p_99_1 = {&R0MW16IP1,&iRM_4_,&var1641};
_S_equz_p  S_equz_p_98_1 = {&R0MW16IP1,&iRM_3_,&var1642};
_S_equz_p  S_equz_p_97_1 = {&R0MW16IP1,&iRM_2_,&var1643};
_S_equz_p  S_equz_p_10_1 = {&R0MW12IP1,&iRM_4_,&var1644};
_S_equz_p  S_equz_p_7_1 = {&R0MW12IP1,&iRM_3_,&var1645};
_S_equz_p  S_equz_p_2_1 = {&R0MW12IP1,&iRM_1_,&var1646};
_S_equz_p  S_equz_p_4_1 = {&R0MW12IP1,&iRM_2_,&var1647};


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
  setData(idR0EE02LDU,&var819);
  setData(idB8VC01RDU,&var1725);
  setData(idB2VC01RDU,&var1737);
  setData(idA2VC01RDU,&var1740);
  setData(idA3VC01RDU,&var1734);
  setData(idB0VS11LDU,&var1702);
  setData(idA0VS11LDU,&var1703);
  setData(idB0VN01LDU,&var1672);
  setData(idA0VN01LDU,&var1674);
  setData(idB0VP01LDU,&var1708);
  setData(idA0VP01LDU,&var1709);
  setData(idB0VE01LDU,&var1699);
  setData(idA0VE01LDU,&var1701);
  setData(idA3VP82LDU,&var1670);
  setData(idB3VP82LDU,&var1693);
  setData(idB3VP52LDU,&var1718);
  setData(idB3CP02RDU,&var1694);
  setData(idB3VP42LDU,&var1668);
  setData(idA3VP52LDU,&var1721);
  setData(idA3CP02RDU,&var1695);
  setData(idA3VP42LDU,&var1669);
  setData(idA1VC01RDU,&var1722);
  setData(idA8VC01RDU,&var1728);
  setData(idB3VC01RDU,&var1731);
  setData(idB1VC01RDU,&var1744);
  equz_p(&S_equz_p_4_1);
  equz_p(&S_equz_p_2_1);
  equz_p(&S_equz_p_7_1);
  equz_p(&S_equz_p_10_1);
  equz_p(&S_equz_p_97_1);
  equz_p(&S_equz_p_98_1);
  equz_p(&S_equz_p_99_1);
  equz_p(&S_equz_p_106_1);
  equz_p(&S_equz_p_52_1);
  equz_p(&S_equz_p_49_1);
  equz_p(&S_equz_p_56_1);
  equz_p(&S_equz_p_63_1);
  equz_p(&S_equz_p_61_1);
  equz_p(&S_equz_p_67_1);
  equz_p(&S_equz_p_71_1);
  equz_p(&S_equz_p_74_1);
  equz_p(&S_equz_p_75_1);
  equz_p(&S_equz_p_76_1);
  equz_p(&S_equz_p_78_1);
  equz_p(&S_equz_p_80_1);
  noto(&S_noto_150_1);
  noto(&S_noto_149_1);
  noto(&S_noto_160_1);
  noto(&S_noto_762_1);
  noto(&S_noto_729_1);
  noto(&S_noto_1108_1);
  noto(&S_noto_1587_1);
  noto(&S_noto_1283_1);
  noto(&S_noto_866_1);
  noto(&S_noto_234_1);
  noto(&S_noto_551_1);
  noto(&S_noto_961_1);
  rs(&S_rs_634_1);
  noto(&S_noto_1373_1);
  equz_p(&S_equz_p_38_1);
  equz_p(&S_equz_p_47_1);
  noto(&S_noto_40_1);
  equz_p(&S_equz_p_43_1);
  rs(&S_rs_1498_1);
  noto(&S_noto_1792_1);
  noto(&S_noto_1791_1);
  noto(&S_noto_1797_1);
  noto(&S_noto_1793_1);
  noto(&S_noto_1799_1);
  noto(&S_noto_1770_1);
  noto(&S_noto_1771_1);
  noto(&S_noto_1772_1);
  noto(&S_noto_1773_1);
  noto(&S_noto_1774_1);
  noto(&S_noto_2086_1);
  equz_p(&S_equz_p_100_1);
  equz_p(&S_equz_p_101_1);
  equz_p(&S_equz_p_102_1);
  noto(&S_noto_938_1);
  equz_p(&S_equz_p_103_1);
  equz_p(&S_equz_p_104_1);
  noto(&S_noto_188_1);
  equz_p(&S_equz_p_105_1);
  noto(&S_noto_12_1);
  noto(&S_noto_1870_1);
  equz_p(&S_equz_p_1814_1);
  equz_p(&S_equz_p_1813_1);
  equz_p(&S_equz_p_1815_1);
  equz_p(&S_equz_p_1816_1);
  equz_p(&S_equz_p_1817_1);
  noto(&S_noto_1779_1);
  noto(&S_noto_1833_1);
  noto(&S_noto_1851_1);
  rs(&S_rs_624_1);
  noto(&S_noto_1811_1);
  noto(&S_noto_1837_1);
  noto(&S_noto_1350_1);
  rsun(&S_rsun_1423_1);
  rs(&S_rs_626_1);
  rs(&S_rs_628_1);
  rs(&S_rs_644_1);
  rs(&S_rs_661_1);
  rs(&S_rs_633_1);
  rs(&S_rs_648_1);
  rs(&S_rs_29_1);
  rs(&S_rs_1492_1);
  rs(&S_rs_1447_1);
  rs(&S_rs_1903_1);
  noto(&S_noto_1442_1);
  noto(&S_noto_1482_1);
  noto(&S_noto_1487_1);
  noto(&S_noto_1861_1);
  noto(&S_noto_1898_1);
  noto(&S_noto_1918_1);
  noto(&S_noto_1883_1);
  noto(&S_noto_595_1);
  noto(&S_noto_25_1);
  noto(&S_noto_26_1);
  noto(&S_noto_27_1);
  noto(&S_noto_28_1);
  noto(&S_noto_598_1);
  noto(&S_noto_596_1);
  noto(&S_noto_55_1);
  noto(&S_noto_274_1);
  noto(&S_noto_277_1);
  noto(&S_noto_286_1);
  noto(&S_noto_292_1);
  noto(&S_noto_282_1);
  noto(&S_noto_995_1);
  noto(&S_noto_1001_1);
  noto(&S_noto_1952_1);
  noto(&S_noto_1954_1);
  rs(&S_rs_1078_1);
  rs(&S_rs_1081_1);
  rs(&S_rs_1084_1);
  rs(&S_rs_1087_1);
  ovbs(&S_ovbs_1198_1);
  ovbs(&S_ovbs_2108_1);
  sr(&S_sr_1072_1);
  bol(&S_bol_1065_1);
  ma(&S_ma_90_1);
  sr(&S_sr_88_1);
  bol(&S_bol_271_1);
  bol(&S_bol_269_1);
  bol(&S_bol_1402_1);
  bol(&S_bol_1400_1);
  bol(&S_bol_990_1);
  bol(&S_bol_988_1);
  bol(&S_bol_583_1);
  bol(&S_bol_585_1);
  bol(&S_bol_594_1);
  bol(&S_bol_600_1);
  and2(&S_and2_750_1);
  and2(&S_and2_30_1);
  and2(&S_and2_31_1);
  and2(&S_and2_32_1);
  and2(&S_and2_33_1);
  and2(&S_and2_48_1);
  and2(&S_and2_44_1);
  and2(&S_and2_741_1);
  or4(&S_or4_431_1);
  or2(&S_or2_754_1);
  or3(&S_or3_5_1);
  or2(&S_or2_6_1);
  or2(&S_or2_1296_1);
  or2(&S_or2_879_1);
  or2(&S_or2_248_1);
  or2(&S_or2_565_1);
  or2(&S_or2_973_1);
  or2(&S_or2_1385_1);
  or2(&S_or2_1071_1);
  and2(&S_and2_1064_1);
  or2(&S_or2_23_1);
  or2(&S_or2_45_1);
  or2(&S_or2_41_1);
  or2(&S_or2_54_1);
  or2(&S_or2_701_1);
  or3(&S_or3_689_1);
  or4(&S_or4_703_1);
  or2(&S_or2_716_1);
  or3(&S_or3_737_1);
  and2(&S_and2_761_1);
  and2(&S_and2_735_1);
  or2(&S_or2_742_1);
  or2(&S_or2_671_1);
  or2(&S_or2_673_1);
  or2(&S_or2_675_1);
  or2(&S_or2_1165_1);
  or2(&S_or2_1199_1);
  and4(&S_and4_1076_1);
  or2(&S_or2_1075_1);
  and2(&S_and2_1090_1);
  or2(&S_or2_1104_1);
  and3(&S_and3_275_1);
  and3(&S_and3_291_1);
  or2(&S_or2_617_1);
  or2(&S_or2_625_1);
  or2(&S_or2_627_1);
  or2(&S_or2_630_1);
  or2(&S_or2_601_1);
  and2(&S_and2_651_1);
  or2(&S_or2_658_1);
  and2(&S_and2_622_1);
  or2(&S_or2_637_1);
  or2(&S_or2_632_1);
  or2(&S_or2_655_1);
  and2(&S_and2_612_1);
  or2(&S_or2_357_1);
  or2(&S_or2_362_1);
  or2(&S_or2_759_1);
  or2(&S_or2_473_1);
  or2(&S_or2_531_1);
  and2(&S_and2_540_1);
  and2(&S_and2_541_1);
  and2(&S_and2_550_1);
  or2(&S_or2_543_1);
  or2(&S_or2_212_1);
  and2(&S_and2_186_1);
  and2(&S_and2_224_1);
  and2(&S_and2_223_1);
  or2(&S_or2_226_1);
  and2(&S_and2_233_1);
  or2(&S_or2_796_1);
  or2(&S_or2_842_1);
  or2(&S_or2_855_1);
  and2(&S_and2_932_1);
  or2(&S_or2_943_1);
  or2(&S_or2_935_1);
  or2(&S_or2_952_1);
  or2(&S_or2_1363_1);
  or2(&S_or2_1347_1);
  and2(&S_and2_1344_1);
  or2(&S_or2_1355_1);
  or2(&S_or2_1272_1);
  or2(&S_or2_1255_1);
  and2(&S_and2_1000_1);
  and2(&S_and2_1443_1);
  zpfs(&S_zpfs_1453_1);
  and2(&S_and2_1483_1);
  zpfs(&S_zpfs_1503_1);
  and2(&S_and2_1488_1);
  zpfs(&S_zpfs_1509_1);
  and2(&S_and2_1525_1);
  or2(&S_or2_2109_1);
  or2(&S_or2_1632_1);
  or2(&S_or2_1633_1);
  or2(&S_or2_1583_1);
  or2(&S_or2_1777_1);
  or2(&S_or2_1778_1);
  or4(&S_or4_1784_1);
  or4(&S_or4_1785_1);
  or2(&S_or2_1787_1);
  or2(&S_or2_1781_1);
  or2(&S_or2_1780_1);
  or3(&S_or3_1789_1);
  and2(&S_and2_1818_1);
  or2(&S_or2_1819_1);
  and2(&S_and2_1825_1);
  and2(&S_and2_1841_1);
  or2(&S_or2_1852_1);
  zpfs(&S_zpfs_1821_1);
  zpfs(&S_zpfs_1822_1);
  zpfs(&S_zpfs_1823_1);
  zpfs(&S_zpfs_1824_1);
  or2(&S_or2_1827_1);
  and2(&S_and2_1828_1);
  or2(&S_or2_1843_1);
  or3(&S_or3_1829_1);
  or2(&S_or2_1904_1);
  ma(&S_ma_1478_1);
  zpfs(&S_zpfs_1874_1);
  and2(&S_and2_1875_1);
  or2(&S_or2_1869_1);
  and3(&S_and3_1872_1);
  or2(&S_or2_1880_1);
  or2(&S_or2_250_1);
  ovbs(&S_ovbs_83_1);
  ovbs(&S_ovbs_24_1);
  ovbs(&S_ovbs_126_1);
  ovbs(&S_ovbs_119_1);
  ovbs(&S_ovbs_1437_1);
  ovbs(&S_ovbs_757_1);
  ovbs(&S_ovbs_307_1);
  ovbs(&S_ovbs_353_1);
  ovbs(&S_ovbs_57_1);
  or2(&S_or2_2016_1);
  or2(&S_or2_2004_1);
  noto(&S_noto_2034_1);
  bol(&S_bol_1567_1);
  bol(&S_bol_1563_1);
  or2(&S_or2_1565_1);
  bol(&S_bol_1551_1);
  bol(&S_bol_1543_1);
  or2(&S_or2_1550_1);
  bol(&S_bol_1570_1);
  bol(&S_bol_1561_1);
  or2(&S_or2_1569_1);
  bol(&S_bol_1555_1);
  bol(&S_bol_1544_1);
  or2(&S_or2_1554_1);
  and4(&S_and4_51_1);
  abs_subf(&S_abs_subf_1560_1);
  noto(&S_noto_1566_1);
  and2(&S_and2_249_1);
  and2(&S_and2_566_1);
  and2(&S_and2_2264_1);
  rs(&S_rs_2213_1);
  sr(&S_sr_2251_1);
  sr(&S_sr_2229_1);
  rs(&S_rs_2207_1);
  zpfs(&S_zpfs_2235_1);
  or2(&S_or2_2223_1);
  abs_subf(&S_abs_subf_2188_1);
  and2(&S_and2_2197_1);
  noto(&S_noto_906_1);
  zzfs(&S_zzfs_2198_1);
  noto(&S_noto_2208_1);
  or2(&S_or2_1088_1);
  or2(&S_or2_382_1);
  or2(&S_or2_365_1);
  or2(&S_or2_1120_1);
  or2(&S_or2_1127_1);
  or2(&S_or2_246_1);
  or2(&S_or2_563_1);
  nocnm(&S_nocnm_1728_1);
  nocnm(&S_nocnm_1729_1);
  noto(&S_noto_1685_1);
  noto(&S_noto_1687_1);
  noto(&S_noto_2180_1);
  noto(&S_noto_2148_1);
  or2(&S_or2_1450_1);
  or2(&S_or2_1481_1);
  noto(&S_noto_2183_1);
  noto(&S_noto_2151_1);
  noto(&S_noto_113_1);
  and2(&S_and2_736_1);
  and2(&S_and2_739_1);
  or2(&S_or2_133_1);
  noto(&S_noto_1746_1);
  noto(&S_noto_1747_1);
  or2(&S_or2_1710_1);
  or2(&S_or2_1750_1);
  or2(&S_or2_1753_1);
  or2(&S_or2_1721_1);
  or2(&S_or2_1724_1);
  or2(&S_or2_1681_1);
  or2(&S_or2_1655_1);
  or2(&S_or2_1651_1);
  or2(&S_or2_2175_1);
  or2(&S_or2_2179_1);
  or2(&S_or2_2177_1);
  or2(&S_or2_2143_1);
  or2(&S_or2_2145_1);
  or2(&S_or2_2147_1);
  noto(&S_noto_1684_1);
  or2(&S_or2_1673_1);
  or2(&S_or2_1671_1);
  noto(&S_noto_1686_1);
  or2(&S_or2_1708_1);
  diagndev(&S_diagndev_2309_1);
  and2(&S_and2_2314_1);
  or2(&S_or2_2323_1);
  or2(&S_or2_2330_1);
  orn(&S_orn_2325_1);
  or3(&S_or3_2326_1);
  noto(&S_noto_687_1);
  noto(&S_noto_158_1);
  rs(&S_rs_743_1);
  noto(&S_noto_432_1);
  noto(&S_noto_676_1);
  noto(&S_noto_720_1);
  rs(&S_rs_753_1);
  noto(&S_noto_771_1);
  vmemb(&S_vmemb_684_1);
  vmemb(&S_vmemb_721_1);
  noto(&S_noto_760_1);
  vmemb(&S_vmemb_752_1);
  rs(&S_rs_639_1);
  rs(&S_rs_649_1);
  rs(&S_rs_629_1);
  noto(&S_noto_616_1);
  rs(&S_rs_657_1);
  noto(&S_noto_273_1);
  noto(&S_noto_652_1);
  noto(&S_noto_587_1);
  noto(&S_noto_992_1);
  noto(&S_noto_1404_1);
  noto(&S_noto_1014_1);
  noto(&S_noto_1929_1);
  kvf(&S_kvf_1501_1);
  noto(&S_noto_84_1);
  samhd(&S_samhd_2107_1);
  samhd(&S_samhd_2113_1);
  newstage(&S_newstage_2111_1);
  noto(&S_noto_1790_1);
  noto(&S_noto_1796_1);
  noto(&S_noto_1798_1);
  noto(&S_noto_1769_1);
  noto(&S_noto_1915_1);
  noto(&S_noto_1907_1);
  noto(&S_noto_1865_1);
  noto(&S_noto_518_1);
  noto(&S_noto_1233_1);
  noto(&S_noto_1249_1);
  noto(&S_noto_1839_1);
  rs(&S_rs_1512_1);
  kvf(&S_kvf_1507_1);
  rs(&S_rs_1506_1);
  noto(&S_noto_1517_1);
  noto(&S_noto_1515_1);
  rs(&S_rs_758_1);
  noto(&S_noto_359_1);
  noto(&S_noto_355_1);
  noto(&S_noto_597_1);
  noto(&S_noto_607_1);
  noto(&S_noto_660_1);
  noto(&S_noto_1936_1);
  noto(&S_noto_1961_1);
  swtakt(&S_swtakt_58_1);
  rs(&S_rs_1080_1);
  and2(&S_and2_768_1);
  and2(&S_and2_11_1);
  and2(&S_and2_118_1);
  and2(&S_and2_245_1);
  and2(&S_and2_562_1);
  or2(&S_or2_17_1);
  or2(&S_or2_8_1);
  or2(&S_or2_172_1);
  and3(&S_and3_714_1);
  and2(&S_and2_685_1);
  or3(&S_or3_748_1);
  and2(&S_and2_744_1);
  and2(&S_and2_667_1);
  or2(&S_or2_281_1);
  and3(&S_and3_297_1);
  or2(&S_or2_650_1);
  and2(&S_and2_619_1);
  and2(&S_and2_609_1);
  and4(&S_and4_610_1);
  and4(&S_and4_620_1);
  and2(&S_and2_645_1);
  or2(&S_or2_653_1);
  or2(&S_or2_656_1);
  and3(&S_and3_350_1);
  and2(&S_and2_513_1);
  or2(&S_or2_520_1);
  and2(&S_and2_572_1);
  and2(&S_and2_584_1);
  or2(&S_or2_196_1);
  and2(&S_and2_258_1);
  and2(&S_and2_270_1);
  and2(&S_and2_989_1);
  and2(&S_and2_1386_1);
  and2(&S_and2_1401_1);
  and2(&S_and2_1232_1);
  or2(&S_or2_1238_1);
  and2(&S_and2_1247_1);
  or2(&S_or2_1256_1);
  and2(&S_and2_1009_1);
  and2(&S_and2_1019_1);
  or2(&S_or2_1491_1);
  and2(&S_and2_1454_1);
  and2(&S_and2_1504_1);
  or3(&S_or3_1518_1);
  or2(&S_or2_1500_1);
  and2(&S_and2_1510_1);
  or3(&S_or3_1511_1);
  or3(&S_or3_1524_1);
  or3(&S_or3_2106_1);
  or3(&S_or3_2115_1);
  or2(&S_or2_1786_1);
  or3(&S_or3_1788_1);
  or2(&S_or2_1826_1);
  and2(&S_and2_1834_1);
  or3(&S_or3_1831_1);
  and2(&S_and2_1856_1);
  or2(&S_or2_2058_1);
  or2(&S_or2_1988_1);
  or2(&S_or2_1977_1);
  and2(&S_and2_1957_1);
  and2(&S_and2_1955_1);
  and2(&S_and2_1940_1);
  and2(&S_and2_1939_1);
  and2(&S_and2_1909_1);
  and4(&S_and4_1910_1);
  and4(&S_and4_1916_1);
  or2(&S_or2_1919_1);
  or2(&S_or2_1921_1);
  or2(&S_or2_1920_1);
  zpfs(&S_zpfs_1923_1);
  zpfs(&S_zpfs_1926_1);
  zpfs(&S_zpfs_1911_1);
  and2(&S_and2_1912_1);
  or3(&S_or3_1927_1);
  lk(&S_lk_1502_1);
  rsfn(&S_rsfn_1494_1);
  abs_subf(&S_abs_subf_1513_1);
  lk(&S_lk_1499_1);
  rsfn(&S_rsfn_1496_1);
  abs_subf(&S_abs_subf_1508_1);
  and3(&S_and3_1871_1);
  or2(&S_or2_1878_1);
  or2(&S_or2_1879_1);
  zpfs(&S_zpfs_1885_1);
  zpfs(&S_zpfs_1887_1);
  or3(&S_or3_1890_1);
  or2(&S_or2_1892_1);
  and2(&S_and2_974_1);
  or2(&S_or2_265_1);
  ovbs(&S_ovbs_1893_1);
  ovbs(&S_ovbs_16_1);
  or2(&S_or2_1493_1);
  noto(&S_noto_109_1);
  bol(&S_bol_1548_1);
  bol(&S_bol_1542_1);
  or2(&S_or2_1546_1);
  ml(&S_ml_1557_1);
  ml(&S_ml_1537_1);
  ml(&S_ml_1559_1);
  ml(&S_ml_1538_1);
  and2(&S_and2_124_1);
  noto(&S_noto_122_1);
  and2(&S_and2_128_1);
  and2(&S_and2_127_1);
  noto(&S_noto_205_1);
  noto(&S_noto_477_1);
  noto(&S_noto_925_1);
  noto(&S_noto_1193_1);
  noto(&S_noto_1248_1);
  bol(&S_bol_1804_1);
  and3(&S_and3_1795_1);
  bol(&S_bol_1768_1);
  and3(&S_and3_1776_1);
  noto(&S_noto_1783_1);
  noto(&S_noto_1794_1);
  bol(&S_bol_916_1);
  bol(&S_bol_1330_1);
  abs_subf(&S_abs_subf_1540_1);
  noto(&S_noto_1552_1);
  abs_subf(&S_abs_subf_1562_1);
  noto(&S_noto_1571_1);
  bol(&S_bol_2254_1);
  and2(&S_and2_2263_1);
  noto(&S_noto_2222_1);
  fsumo(&S_fsumo_86_1);
  abs_subf(&S_abs_subf_2260_1);
  and2(&S_and2_2265_1);
  and3(&S_and3_2214_1);
  and2(&S_and2_2236_1);
  ovbs(&S_ovbs_2237_1);
  or3(&S_or3_2245_1);
  inf(&S_inf_2218_1);
  noto(&S_noto_1331_1);
  or2(&S_or2_1079_1);
  and2(&S_and2_2059_1);
  and2(&S_and2_111_1);
  and3(&S_and3_1416_1);
  or2(&S_or2_1679_1);
  noto(&S_noto_2182_1);
  noto(&S_noto_2150_1);
  or2(&S_or2_2141_1);
  rs(&S_rs_749_1);
  noto(&S_noto_764_1);
  noto(&S_noto_1273_1);
  noto(&S_noto_856_1);
  noto(&S_noto_227_1);
  rs(&S_rs_631_1);
  noto(&S_noto_544_1);
  noto(&S_noto_953_1);
  noto(&S_noto_1364_1);
  kvf(&S_kvf_1886_1);
  kvf(&S_kvf_1925_1);
  andn(&S_andn_1782_1);
  rs(&S_rs_22_1);
  noto(&S_noto_146_1);
  noto(&S_noto_1840_1);
  noto(&S_noto_117_1);
  noto(&S_noto_1407_1);
  abs_subf(&S_abs_subf_1020_1);
  abs_subf(&S_abs_subf_1007_1);
  noto(&S_noto_1027_1);
  bol(&S_bol_1040_1);
  bol(&S_bol_1041_1);
  noto(&S_noto_1004_1);
  bol(&S_bol_1043_1);
  bol(&S_bol_1044_1);
  bol(&S_bol_87_1);
  and2(&S_and2_34_1);
  and2(&S_and2_151_1);
  and2(&S_and2_159_1);
  and2(&S_and2_156_1);
  and2(&S_and2_148_1);
  and3(&S_and3_247_1);
  and3(&S_and3_564_1);
  and3(&S_and3_998_1);
  or3(&S_or3_114_1);
  or2(&S_or2_677_1);
  and2(&S_and2_686_1);
  and2(&S_and2_688_1);
  and2(&S_and2_700_1);
  and2(&S_and2_702_1);
  and2(&S_and2_715_1);
  and2(&S_and2_718_1);
  and3(&S_and3_717_1);
  and2(&S_and2_719_1);
  or2(&S_or2_755_1);
  and2(&S_and2_763_1);
  or2(&S_or2_769_1);
  or2(&S_or2_773_1);
  and3(&S_and3_770_1);
  and2(&S_and2_775_1);
  and2(&S_and2_779_1);
  and2(&S_and2_663_1);
  or2(&S_or2_664_1);
  and2(&S_and2_672_1);
  and2(&S_and2_674_1);
  and2(&S_and2_643_1);
  and2(&S_and2_621_1);
  and2(&S_and2_611_1);
  and3(&S_and3_542_1);
  or2(&S_or2_579_1);
  and3(&S_and3_225_1);
  and3(&S_and3_260_1);
  and3(&S_and3_863_1);
  and3(&S_and3_864_1);
  or2(&S_or2_984_1);
  or2(&S_or2_1396_1);
  and3(&S_and3_1280_1);
  and3(&S_and3_1281_1);
  or2(&S_or2_1045_1);
  or2(&S_or2_1057_1);
  or2(&S_or2_1055_1);
  or2(&S_or2_1054_1);
  or2(&S_or2_1053_1);
  and2(&S_and2_1419_1);
  and2(&S_and2_1425_1);
  and2(&S_and2_1427_1);
  and2(&S_and2_1429_1);
  and2(&S_and2_1435_1);
  and2(&S_and2_1439_1);
  or3(&S_or3_1463_1);
  and2(&S_and2_1464_1);
  and3(&S_and3_1521_1);
  or3(&S_or3_1505_1);
  and2(&S_and2_1519_1);
  and3(&S_and3_1522_1);
  zpfs(&S_zpfs_2060_1);
  and3(&S_and3_1949_1);
  and2(&S_and2_1944_1);
  or3(&S_or3_1950_1);
  and2(&S_and2_1922_1);
  and4(&S_and4_1930_1);
  and4(&S_and4_1932_1);
  lk(&S_lk_1928_1);
  rsfn(&S_rsfn_1933_1);
  abs_subf(&S_abs_subf_1935_1);
  and3(&S_and3_1938_1);
  lk(&S_lk_1891_1);
  rsfn(&S_rsfn_1894_1);
  abs_subf(&S_abs_subf_1896_1);
  and2(&S_and2_1884_1);
  and3(&S_and3_1888_1);
  or5(&S_or5_153_1);
  and2(&S_and2_1857_1);
  and2(&S_and2_112_1);
  and2(&S_and2_108_1);
  ml(&S_ml_1535_1);
  zpfs(&S_zpfs_756_1);
  and2(&S_and2_1759_1);
  and2(&S_and2_1736_1);
  and2(&S_and2_1757_1);
  and2(&S_and2_1760_1);
  and2(&S_and2_1737_1);
  and2(&S_and2_1758_1);
  and2(&S_and2_1738_1);
  and2(&S_and2_1739_1);
  and2(&S_and2_1741_1);
  and2(&S_and2_1742_1);
  and2(&S_and2_1744_1);
  and2(&S_and2_1745_1);
  and2(&S_and2_1712_1);
  and2(&S_and2_1713_1);
  rs(&S_rs_1714_1);
  and2(&S_and2_1715_1);
  and2(&S_and2_1716_1);
  rs(&S_rs_1717_1);
  and2(&S_and2_1695_1);
  and2(&S_and2_1699_1);
  and2(&S_and2_1660_1);
  and2(&S_and2_1662_1);
  and2(&S_and2_1664_1);
  and2(&S_and2_1666_1);
  and2(&S_and2_1634_1);
  and2(&S_and2_1635_1);
  and2(&S_and2_1636_1);
  and2(&S_and2_1637_1);
  and2(&S_and2_1638_1);
  and2(&S_and2_1639_1);
  and2(&S_and2_1640_1);
  and2(&S_and2_1641_1);
  and2(&S_and2_123_1);
  abs_subf(&S_abs_subf_1539_1);
  noto(&S_noto_1547_1);
  ovbs(&S_ovbs_2215_1);
  and2(&S_and2_2261_1);
  noto(&S_noto_2244_1);
  noto(&S_noto_2192_1);
  noto(&S_noto_2193_1);
  and2(&S_and2_2160_1);
  or4(&S_or4_900_1);
  and2(&S_and2_2128_1);
  or4(&S_or4_1317_1);
  and4(&S_and4_959_1);
  and4(&S_and4_1371_1);
  or3(&S_or3_1749_1);
  or3(&S_or3_1720_1);
  or3(&S_or3_1723_1);
  or3(&S_or3_1752_1);
  or3(&S_or3_1704_1);
  or3(&S_or3_1706_1);
  or3(&S_or3_1653_1);
  or3(&S_or3_1649_1);
  or3(&S_or3_2167_1);
  or3(&S_or3_2135_1);
  or3(&S_or3_2169_1);
  or3(&S_or3_2171_1);
  or3(&S_or3_2139_1);
  or3(&S_or3_2137_1);
  or2(&S_or2_1646_1);
  or2(&S_or2_2173_1);
  and2(&S_and2_2157_1);
  and2(&S_and2_2126_1);
  or2(&S_or2_1643_1);
  or2(&S_or2_1702_1);
  and2(&S_and2_1698_1);
  samhd(&S_samhd_398_1);
  samhd(&S_samhd_404_1);
  samhd(&S_samhd_793_1);
  samhd(&S_samhd_797_1);
  rs(&S_rs_765_1);
  rs(&S_rs_772_1);
  newstage(&S_newstage_401_1);
  newstage(&S_newstage_795_1);
  orn(&S_orn_152_1);
  rs(&S_rs_1642_1);
  rs(&S_rs_1644_1);
  rs(&S_rs_1645_1);
  rs(&S_rs_1647_1);
  rs(&S_rs_1648_1);
  rs(&S_rs_1650_1);
  rs(&S_rs_1652_1);
  rs(&S_rs_1654_1);
  rs(&S_rs_1672_1);
  rs(&S_rs_1680_1);
  rs(&S_rs_1701_1);
  rs(&S_rs_1709_1);
  rs(&S_rs_1719_1);
  rs(&S_rs_2174_1);
  rs(&S_rs_1748_1);
  rs(&S_rs_1740_1);
  rs(&S_rs_1751_1);
  rs(&S_rs_1743_1);
  rs(&S_rs_1754_1);
  rs(&S_rs_1692_1);
  rs(&S_rs_1693_1);
  rs(&S_rs_1694_1);
  rs(&S_rs_1656_1);
  rs(&S_rs_1657_1);
  rs(&S_rs_1658_1);
  rs(&S_rs_1659_1);
  rs(&S_rs_115_1);
  noto(&S_noto_116_1);
  rs(&S_rs_1527_1);
  rs(&S_rs_1526_1);
  rs(&S_rs_1456_1);
  kvf(&S_kvf_1460_1);
  rs(&S_rs_1943_1);
  rs(&S_rs_1889_1);
  noto(&S_noto_1459_1);
  andn(&S_andn_280_1);
  noto(&S_noto_298_1);
  and2(&S_and2_422_1);
  and2(&S_and2_433_1);
  and2(&S_and2_441_1);
  and2(&S_and2_442_1);
  and2(&S_and2_443_1);
  or3(&S_or3_394_1);
  or3(&S_or3_409_1);
  and2(&S_and2_423_1);
  and3(&S_and3_599_1);
  or2(&S_or2_155_1);
  and2(&S_and2_691_1);
  and2(&S_and2_751_1);
  or2(&S_or2_778_1);
  and2(&S_and2_670_1);
  or2(&S_or2_288_1);
  and3(&S_and3_289_1);
  or2(&S_or2_451_1);
  and3(&S_and3_458_1);
  or2(&S_or2_504_1);
  and2(&S_and2_524_1);
  and3(&S_and3_574_1);
  and3(&S_and3_573_1);
  and2(&S_and2_200_1);
  and3(&S_and3_259_1);
  or4(&S_or4_789_1);
  or4(&S_or4_805_1);
  or3(&S_or3_857_1);
  and2(&S_and2_853_1);
  and3(&S_and3_854_1);
  and2(&S_and2_852_1);
  and2(&S_and2_865_1);
  and2(&S_and2_882_1);
  and3(&S_and3_883_1);
  and2(&S_and2_946_1);
  or2(&S_or2_951_1);
  and2(&S_and2_960_1);
  and2(&S_and2_977_1);
  and3(&S_and3_978_1);
  and3(&S_and3_979_1);
  or2(&S_or2_1365_1);
  and2(&S_and2_1372_1);
  and2(&S_and2_1389_1);
  and3(&S_and3_1390_1);
  and3(&S_and3_1391_1);
  and2(&S_and2_1357_1);
  or3(&S_or3_1274_1);
  and3(&S_and3_1271_1);
  and2(&S_and2_1270_1);
  and2(&S_and2_1269_1);
  and2(&S_and2_1282_1);
  and2(&S_and2_1294_1);
  and3(&S_and3_1295_1);
  and2(&S_and2_1299_1);
  and3(&S_and3_1300_1);
  and2(&S_and2_1242_1);
  and2(&S_and2_1262_1);
  and2(&S_and2_1058_1);
  and2(&S_and2_1061_1);
  or2(&S_or2_1451_1);
  or3(&S_or3_1455_1);
  or2(&S_or2_1755_1);
  or2(&S_or2_2084_1);
  or2(&S_or2_2089_1);
  lk(&S_lk_1461_1);
  rsfn(&S_rsfn_1457_1);
  abs_subf(&S_abs_subf_1466_1);
  ovbs(&S_ovbs_2076_1);
  ovbs(&S_ovbs_121_1);
  and2(&S_and2_485_1);
  and2(&S_and2_456_1);
  and2(&S_and2_449_1);
  rs(&S_rs_1756_1);
  rs(&S_rs_1722_1);
  and2(&S_and2_1696_1);
  and2(&S_and2_1697_1);
  and2(&S_and2_1700_1);
  and2(&S_and2_1663_1);
  and2(&S_and2_1665_1);
  and2(&S_and2_1667_1);
  zpfs(&S_zpfs_2200_1);
  zpfs(&S_zpfs_2201_1);
  and2(&S_and2_2072_1);
  and2(&S_and2_2083_1);
  and3(&S_and3_424_1);
  and2(&S_and2_2071_1);
  and2(&S_and2_2094_1);
  rs(&S_rs_2166_1);
  rs(&S_rs_2154_1);
  rs(&S_rs_2158_1);
  and2(&S_and2_2164_1);
  rs(&S_rs_2176_1);
  rs(&S_rs_2159_1);
  and2(&S_and2_2165_1);
  rs(&S_rs_2178_1);
  rs(&S_rs_2142_1);
  rs(&S_rs_2134_1);
  rs(&S_rs_2122_1);
  rs(&S_rs_2125_1);
  and2(&S_and2_2132_1);
  rs(&S_rs_2144_1);
  rs(&S_rs_2127_1);
  and2(&S_and2_2133_1);
  rs(&S_rs_2146_1);
  regch(&S_regch_131_1);
  rs(&S_rs_1707_1);
  rs(&S_rs_745_1);
  rs(&S_rs_777_1);
  rs(&S_rs_604_1);
  noto(&S_noto_618_1);
  orni(&S_orni_1424_1);
  noto(&S_noto_2077_1);
  rs(&S_rs_1674_1);
  rs(&S_rs_1678_1);
  rs(&S_rs_1682_1);
  rs(&S_rs_1703_1);
  rs(&S_rs_1705_1);
  rs(&S_rs_1711_1);
  ma(&S_ma_1462_1);
  rs(&S_rs_614_1);
  noto(&S_noto_994_1);
  noto(&S_noto_290_1);
  noto(&S_noto_1056_1);
  noto(&S_noto_1050_1);
  noto(&S_noto_1023_1);
  and2(&S_and2_426_1);
  and2(&S_and2_444_1);
  and2(&S_and2_877_1);
  and3(&S_and3_878_1);
  and3(&S_and3_972_1);
  and3(&S_and3_1384_1);
  and2(&S_and2_638_1);
  and2(&S_and2_948_1);
  and2(&S_and2_949_1);
  and3(&S_and3_950_1);
  and2(&S_and2_1360_1);
  and2(&S_and2_1361_1);
  and3(&S_and3_1362_1);
  and5(&S_and5_999_1);
  and2(&S_and2_1046_1);
  or4(&S_or4_1006_1);
  and3(&S_and3_1470_1);
  or2(&S_or2_1844_1);
  and2(&S_and2_1846_1);
  and2(&S_and2_2095_1);
  ovbs(&S_ovbs_2080_1);
  noto(&S_noto_2205_1);
  noto(&S_noto_2206_1);
  andn(&S_andn_602_1);
  andn(&S_andn_603_1);
  and2(&S_and2_2098_1);
  or5(&S_or5_2096_1);
  or5(&S_or5_2097_1);
  and2(&S_and2_2161_1);
  or3(&S_or3_1224_1);
  rs(&S_rs_2168_1);
  rs(&S_rs_2155_1);
  and2(&S_and2_2129_1);
  rs(&S_rs_2136_1);
  rs(&S_rs_2123_1);
  or3(&S_or3_824_1);
  or2(&S_or2_134_1);
  rs(&S_rs_1005_1);
  noto(&S_noto_2081_1);
  rs(&S_rs_2085_1);
  rs(&S_rs_2090_1);
  rs(&S_rs_1473_1);
  noto(&S_noto_1024_1);
  provsbr(&S_provsbr_1421_1);
  rs(&S_rs_1420_1);
  and2(&S_and2_552_1);
  and2(&S_and2_235_1);
  and2(&S_and2_867_1);
  and2(&S_and2_962_1);
  and2(&S_and2_1374_1);
  and2(&S_and2_1284_1);
  and3(&S_and3_1011_1);
  and3(&S_and3_1017_1);
  and2(&S_and2_1034_1);
  and2(&S_and2_1022_1);
  and3(&S_and3_1068_1);
  or2(&S_or2_1426_1);
  or2(&S_or2_1428_1);
  or2(&S_or2_1430_1);
  or2(&S_or2_1436_1);
  or2(&S_or2_1440_1);
  orni(&S_orni_1432_1);
  or2(&S_or2_1842_1);
  or2(&S_or2_2073_1);
  noto(&S_noto_2212_1);
  and2(&S_and2_2162_1);
  and2(&S_and2_2130_1);
  rs(&S_rs_2156_1);
  and2(&S_and2_2163_1);
  rs(&S_rs_2172_1);
  rs(&S_rs_2124_1);
  and2(&S_and2_2074_1);
  noto(&S_noto_2091_1);
  rs(&S_rs_2170_1);
  newstage(&S_newstage_1835_1);
  cntch(&S_cntch_1431_1);
  rs(&S_rs_1029_1);
  rs(&S_rs_1062_1);
  rs(&S_rs_1036_1);
  noto(&S_noto_1037_1);
  or3(&S_or3_162_1);
  or3(&S_or3_494_1);
  or2(&S_or2_1059_1);
  and2(&S_and2_1433_1);
  or2(&S_or2_1595_1);
  zpfs(&S_zpfs_2070_1);
  rs(&S_rs_2138_1);
  and2(&S_and2_2131_1);
  rs(&S_rs_2140_1);
  cnshd(&S_cnshd_1602_1);
  noto(&S_noto_875_1);
  ornc(&S_ornc_169_1);
  charint(&S_charint_163_1);
  noto(&S_noto_243_1);
  ornc(&S_ornc_502_1);
  charint(&S_charint_496_1);
  noto(&S_noto_560_1);
  noto(&S_noto_970_1);
  noto(&S_noto_1382_1);
  rs(&S_rs_1047_1);
  or2(&S_or2_1621_1);
  and2(&S_and2_1573_1);
  and2(&S_and2_1574_1);
  and2(&S_and2_1575_1);
  and2(&S_and2_1576_1);
  and2(&S_and2_1582_1);
  and2(&S_and2_1584_1);
  and2(&S_and2_1586_1);
  and2(&S_and2_1035_1);
  fnapb(&S_fnapb_1622_1);
  samhd(&S_samhd_1605_1);
  zpfs(&S_zpfs_1617_1);
  zpfs(&S_zpfs_1615_1);
  noto(&S_noto_1292_1);
  fsumz(&S_fsumz_164_1);
  fsumz(&S_fsumz_497_1);
  orni(&S_orni_1184_1);
  rs(&S_rs_1031_1);
  rs(&S_rs_1032_1);
  ma(&S_ma_170_1);
  ma(&S_ma_503_1);
  zpfs(&S_zpfs_1623_1);
  or2(&S_or2_1122_1);
  or3(&S_or3_1030_1);
  or3(&S_or3_1612_1);
  samhd(&S_samhd_1189_1);
  samhd(&S_samhd_1200_1);
  newstage(&S_newstage_1192_1);
  cnshd(&S_cnshd_1123_1);
  noto(&S_noto_1291_1);
  noto(&S_noto_874_1);
  fnapb(&S_fnapb_213_1);
  noto(&S_noto_242_1);
  fnapb(&S_fnapb_532_1);
  zpfs(&S_zpfs_526_1);
  zpfs(&S_zpfs_525_1);
  noto(&S_noto_559_1);
  noto(&S_noto_969_1);
  noto(&S_noto_1381_1);
  or2(&S_or2_1188_1);
  or2(&S_or2_1202_1);
  or2(&S_or2_1146_1);
  and2(&S_and2_1098_1);
  and2(&S_and2_1095_1);
  and2(&S_and2_1096_1);
  and2(&S_and2_1097_1);
  and2(&S_and2_1103_1);
  and2(&S_and2_1105_1);
  and2(&S_and2_1107_1);
  and2(&S_and2_640_1);
  zpfs(&S_zpfs_533_1);
  or2(&S_or2_554_1);
  zpfs(&S_zpfs_214_1);
  zpfs(&S_zpfs_207_1);
  zpfs(&S_zpfs_203_1);
  or2(&S_or2_237_1);
  or2(&S_or2_869_1);
  and2(&S_and2_868_1);
  or2(&S_or2_964_1);
  or2(&S_or2_1376_1);
  or2(&S_or2_1286_1);
  and2(&S_and2_1285_1);
  and2(&S_and2_1026_1);
  or2(&S_or2_1038_1);
  and2(&S_and2_1194_1);
  and2(&S_and2_1196_1);
  or4(&S_or4_1967_1);
  zapomni(&S_zapomni_182_1);
  zapomni(&S_zapomni_189_1);
  zapomni(&S_zapomni_195_1);
  zapomni(&S_zapomni_198_1);
  fnapb(&S_fnapb_1147_1);
  samhd(&S_samhd_1130_1);
  zpfs(&S_zpfs_1143_1);
  zpfs(&S_zpfs_1139_1);
  orn(&S_orn_1293_1);
  orn(&S_orn_876_1);
  rs(&S_rs_1025_1);
  zpfs(&S_zpfs_1148_1);
  and2(&S_and2_553_1);
  and2(&S_and2_236_1);
  and2(&S_and2_963_1);
  and2(&S_and2_1375_1);
  and2(&S_and2_1039_1);
  or2(&S_or2_1033_1);
  or3(&S_or3_1136_1);
  or2(&S_or2_1984_1);
  or2(&S_or2_1973_1);
  ovbs(&S_ovbs_1968_1);
  ovbs(&S_ovbs_1980_1);
  ovbs(&S_ovbs_1971_1);
  noto(&S_noto_1972_1);
  and2(&S_and2_1978_1);
  and2(&S_and2_1989_1);
  or3(&S_or3_132_1);
  orn(&S_orn_244_1);
  orn(&S_orn_971_1);
  orn(&S_orn_1383_1);
  noto(&S_noto_1969_1);
  noto(&S_noto_1981_1);
  rs(&S_rs_1985_1);
  noto(&S_noto_1986_1);
  rs(&S_rs_1974_1);
  rs(&S_rs_1077_1);
  or2(&S_or2_1941_1);
  irm(&S_irm_2196_1);
  ml(&S_ml_894_1);
  ml(&S_ml_1312_1);
  noto(&S_noto_1975_1);
  noto(&S_noto_72_1);
  noto(&S_noto_1942_1);
  and2(&S_and2_64_1);
  and2(&S_and2_68_1);
  and4(&S_and4_344_1);
  or2(&S_or2_1413_1);
  or2(&S_or2_1958_1);
  noto(&S_noto_1409_1);
  rs(&S_rs_347_1);
  noto(&S_noto_342_1);
  noto(&S_noto_285_1);
  rs(&S_rs_1959_1);
  rs(&S_rs_1960_1);
  or4(&S_or4_296_1);
  or2(&S_or2_279_1);
  or2(&S_or2_302_1);
  or2(&S_or2_339_1);
  or4(&S_or4_348_1);
  and2(&S_and2_1408_1);
  or2(&S_or2_2020_1);
  or2(&S_or2_2041_1);
  rs(&S_rs_295_1);
  provsbr(&S_provsbr_284_1);
  equz_p(&S_equz_p_323_1);
  bolz(&S_bolz_324_1);
  provsbr(&S_provsbr_341_1);
  bolz(&S_bolz_346_1);
  noto(&S_noto_73_1);
  noto(&S_noto_62_1);
  and2(&S_and2_65_1);
  and2(&S_and2_69_1);
  or2(&S_or2_66_1);
  and2(&S_and2_576_1);
  and2(&S_and2_575_1);
  and2(&S_and2_299_1);
  and4(&S_and4_328_1);
  and2(&S_and2_311_1);
  or2(&S_or2_301_1);
  and2(&S_and2_306_1);
  or2(&S_or2_352_1);
  and2(&S_and2_343_1);
  orn(&S_orn_561_1);
  and2(&S_and2_261_1);
  and2(&S_and2_262_1);
  or3(&S_or3_272_1);
  and2(&S_and2_885_1);
  and2(&S_and2_884_1);
  or3(&S_or3_890_1);
  and2(&S_and2_981_1);
  and2(&S_and2_980_1);
  and2(&S_and2_1392_1);
  and2(&S_and2_1393_1);
  and2(&S_and2_1301_1);
  and2(&S_and2_1302_1);
  or3(&S_or3_1307_1);
  or2(&S_or2_1410_1);
  or3(&S_or3_1441_1);
  or3(&S_or3_1480_1);
  or3(&S_or3_1497_1);
  or3(&S_or3_1901_1);
  or3(&S_or3_1863_1);
  or4(&S_or4_1403_1);
  or4(&S_or4_991_1);
  zapomni(&S_zapomni_179_1);
  maz(&S_maz_310_1);
  maz(&S_maz_319_1);
  orni(&S_orni_1197_1);
  orni(&S_orni_300_1);
  rs(&S_rs_351_1);
  decatron(&S_decatron_309_1);
  orni(&S_orni_345_1);
  noto(&S_noto_320_1);
  swtakt(&S_swtakt_1867_1);
  swtakt(&S_swtakt_1902_1);
  swtakt(&S_swtakt_1486_1);
  swtakt(&S_swtakt_1490_1);
  swtakt(&S_swtakt_1446_1);
  or3(&S_or3_586_1);
  or2(&S_or2_305_1);
  or2(&S_or2_314_1);
  or2(&S_or2_327_1);
  or2(&S_or2_326_1);
  and2(&S_and2_330_1);
  and2(&S_and2_325_1);
  and2(&S_and2_332_1);
  and2(&S_and2_331_1);
  and3(&S_and3_312_1);
  or5(&S_or5_516_1);
  or5(&S_or5_192_1);
  and2(&S_and2_1411_1);
  or2(&S_or2_2063_1);
  or2(&S_or2_2051_1);
  or3(&S_or3_1405_1);
  or3(&S_or3_993_1);
  zpfs(&S_zpfs_322_1);
  cnshd(&S_cnshd_174_1);
  cnshd(&S_cnshd_505_1);
  equz_p(&S_equz_p_313_1);
  noto(&S_noto_1417_1);
  cntch(&S_cntch_303_1);
  rs(&S_rs_304_1);
  cntch(&S_cntch_349_1);
  and2(&S_and2_318_1);
  or5(&S_or5_1434_1);
  or5(&S_or5_1412_1);
  and2(&S_and2_1414_1);
  or2(&S_or2_1415_1);
  and4(&S_and4_1945_1);
  and3(&S_and3_1946_1);
  and3(&S_and3_1947_1);
  and2(&S_and2_1908_1);
  and2(&S_and2_1862_1);
  or3(&S_or3_1876_1);
  newstage(&S_newstage_221_1);
  rs(&S_rs_1914_1);
  rs(&S_rs_1868_1);
  rs(&S_rs_1877_1);
  and2(&S_and2_337_1);
  or3(&S_or3_1913_1);
  and2(&S_and2_210_1);
  and2(&S_and2_206_1);
  noto(&S_noto_338_1);
  and2(&S_and2_1091_1);
  and2(&S_and2_647_1);
  or2(&S_or2_635_1);
  and2(&S_and2_1051_1);
  rs(&S_rs_636_1);
  rs(&S_rs_1048_1);
  noto(&S_noto_1049_1);
  rs(&S_rs_1083_1);
  and2(&S_and2_654_1);
  and3(&S_and3_623_1);
  and3(&S_and3_613_1);
  or3(&S_or3_820_1);
  or3(&S_or3_1220_1);
  and4(&S_and4_1012_1);
  and4(&S_and4_1018_1);
  or2(&S_or2_1082_1);
  or4(&S_or4_891_1);
  or4(&S_or4_1308_1);
  ornc(&S_ornc_901_1);
  charint(&S_charint_892_1);
  ornc(&S_ornc_1318_1);
  charint(&S_charint_1310_1);
  fsumz(&S_fsumz_893_1);
  fsumz(&S_fsumz_1311_1);
  ma(&S_ma_1319_1);
  ma(&S_ma_902_1);
  fnapb(&S_fnapb_936_1);
  zpfs(&S_zpfs_930_1);
  zpfs(&S_zpfs_927_1);
  fnapb(&S_fnapb_1348_1);
  zpfs(&S_zpfs_1341_1);
  zpfs(&S_zpfs_1339_1);
  zpfs(&S_zpfs_937_1);
  zpfs(&S_zpfs_1349_1);
  and2(&S_and2_1334_1);
  and2(&S_and2_920_1);
  or5(&S_or5_919_1);
  or5(&S_or5_1333_1);
  or2(&S_or2_2247_1);
  cnshd(&S_cnshd_903_1);
  cnshd(&S_cnshd_1320_1);
  noto(&S_noto_2246_1);
  newstage(&S_newstage_915_1);
  and2(&S_and2_922_1);
  and2(&S_and2_926_1);
  andn(&S_andn_2220_1);
  noto(&S_noto_2242_1);
  and2(&S_and2_2243_1);
  or2(&S_or2_2241_1);
  and3(&S_and3_2195_1);
  and2(&S_and2_2068_1);
  and2(&S_and2_2057_1);
  or3(&S_or3_2055_1);
  or3(&S_or3_2069_1);
  rs(&S_rs_2052_1);
  noto(&S_noto_2053_1);
  rs(&S_rs_2064_1);
  noto(&S_noto_2065_1);
  and2(&S_and2_1092_1);
  and2(&S_and2_646_1);
  and2(&S_and2_1067_1);
  rs(&S_rs_2240_1);
  rs(&S_rs_1060_1);
  noto(&S_noto_1063_1);
  rs(&S_rs_1086_1);
  and3(&S_and3_1052_1);
  and2(&S_and2_1003_1);
  and4(&S_and4_1010_1);
  and4(&S_and4_1016_1);
  or2(&S_or2_1085_1);
  orn(&S_orn_1212_1);
  orn(&S_orn_812_1);
  ornc(&S_ornc_1221_1);
  charint(&S_charint_1213_1);
  ornc(&S_ornc_821_1);
  charint(&S_charint_813_1);
  rs(&S_rs_997_1);
  or3(&S_or3_450_1);
  and3(&S_and3_457_1);
  and2(&S_and2_1042_1);
  and2(&S_and2_489_1);
  and2(&S_and2_460_1);
  fsumz(&S_fsumz_1214_1);
  fsumz(&S_fsumz_814_1);
  samhd(&S_samhd_470_1);
  samhd(&S_samhd_476_1);
  newstage(&S_newstage_472_1);
  ma(&S_ma_822_1);
  ma(&S_ma_1222_1);
  or4(&S_or4_466_1);
  or4(&S_or4_484_1);
  and2(&S_and2_481_1);
  and2(&S_and2_478_1);
  fnapb(&S_fnapb_1257_1);
  zpfs(&S_zpfs_1251_1);
  zpfs(&S_zpfs_1243_1);
  fnapb(&S_fnapb_843_1);
  zpfs(&S_zpfs_1258_1);
  and2(&S_and2_1093_1);
  and2(&S_and2_662_1);
  zpfs(&S_zpfs_844_1);
  zpfs(&S_zpfs_837_1);
  zpfs(&S_zpfs_838_1);
  or5(&S_or5_1235_1);
  and2(&S_and2_1074_1);
  or5(&S_or5_1991_1);
  orni(&S_orni_138_1);
  orn(&S_orn_428_1);
  orn(&S_orn_446_1);
  cnshd(&S_cnshd_1223_1);
  rs(&S_rs_1070_1);
  rs(&S_rs_1089_1);
  or2(&S_or2_430_1);
  or2(&S_or2_447_1);
  and2(&S_and2_690_1);
  or2(&S_or2_1168_1);
  or2(&S_or2_1169_1);
  and2(&S_and2_1106_1);
  or5(&S_or5_832_1);
  and2(&S_and2_1585_1);
  or4(&S_or4_1581_1);
  or4(&S_or4_1992_1);
  orn(&S_orn_776_1);
  orn(&S_orn_1094_1);
  cnshd(&S_cnshd_823_1);
  or2(&S_or2_766_1);
  or2(&S_or2_767_1);
  or4(&S_or4_747_1);
  or5(&S_or5_1132_1);
  or2(&S_or2_372_1);
  or2(&S_or2_376_1);
  ovbs(&S_ovbs_1998_1);
  noto(&S_noto_1999_1);
  and2(&S_and2_2005_1);
  and2(&S_and2_2017_1);
  or3(&S_or3_1993_1);
  and2(&S_and2_1994_1);
  or3(&S_or3_2007_1);
  and2(&S_and2_2008_1);
  or5(&S_or5_1572_1);
  or2(&S_or2_2231_1);
  rs(&S_rs_746_1);
  samhd(&S_samhd_375_1);
  newstage(&S_newstage_1263_1);
  and2(&S_and2_734_1);
  or2(&S_or2_738_1);
  or4(&S_or4_374_1);
  or5(&S_or5_1609_1);
  or2(&S_or2_2012_1);
  or2(&S_or2_2000_1);
  ovbs(&S_ovbs_1995_1);
  ovbs(&S_ovbs_2009_1);
  rs(&S_rs_2028_1);
  rs(&S_rs_2036_1);
  noto(&S_noto_2026_1);
  noto(&S_noto_2047_1);
  andn(&S_andn_1_1);
  and2(&S_and2_1244_1);
  and2(&S_and2_1250_1);
  zpfs(&S_zpfs_2029_1);
  zpfs(&S_zpfs_2037_1);
  noto(&S_noto_2228_1);
  or3(&S_or3_1677_1);
  or3(&S_or3_1669_1);
  or2(&S_or2_1683_1);
  or2(&S_or2_1675_1);
  rs(&S_rs_740_1);
  rs(&S_rs_1668_1);
  rs(&S_rs_1676_1);
  or2(&S_or2_2030_1);
  noto(&S_noto_1996_1);
  noto(&S_noto_2010_1);
  rs(&S_rs_2013_1);
  noto(&S_noto_2014_1);
  rs(&S_rs_2001_1);
  or2(&S_or2_2038_1);
  noto(&S_noto_2031_1);
  and2(&S_and2_2032_1);
  and2(&S_and2_2027_1);
  noto(&S_noto_2039_1);
  and2(&S_and2_1661_1);
  noto(&S_noto_2019_1);
  rs(&S_rs_1670_1);
  noto(&S_noto_2002_1);
  and2(&S_and2_2040_1);
  and4(&S_and4_2021_1);
  ovbs(&S_ovbs_2022_1);
  and2(&S_and2_2048_1);
  noto(&S_noto_2049_1);
  or2(&S_or2_2023_1);
  orn(&S_orn_606_1);
  orn(&S_orn_605_1);
  noto(&S_noto_2024_1);
  and4(&S_and4_2042_1);
  ovbs(&S_ovbs_2043_1);
  or2(&S_or2_2044_1);
  newstage(&S_newstage_608_1);
  or2(&S_or2_642_1);
  ovbs(&S_ovbs_2033_1);
  noto(&S_noto_2045_1);
  and2(&S_and2_641_1);
  setData(ida1ab5,&var1);
  setData(ida1ab4,&var2);
  setData(ida1ab3,&var3);
  setData(ida1ab2,&var4);
  setData(ida1ab1,&var5);
  setData(idbd6,&var853);
  setData(idbd5,&var854);
  setData(idbd4,&var855);
  setData(idbd3,&var1628);
  setData(idbd2,&var850);
  setData(idbd1,&var851);
  setData(idhz6,&var1207);
  setData(idhz5,&var917);
  setData(idhz4,&var393);
  setData(idhz3,&var964);
  setData(idhz2,&var253);
  setData(idhz1,&var1276);
  setData(idKKL9,&var1205);
  setData(idKKL8,&var1153);
  setData(idKKL7,&var1111);
  setData(idKKL6,&var1027);
  setData(idKKL5,&var1207);
  setData(idKKL4,&var1557);
  setData(idKKL3,&var814);
  setData(idKKL2,&var1202);
  setData(idKKL1,&var248);
  setData(idTestDiagnDU,&var6);
  setData(idR0DE3CLDU,&var9);
  setData(idR0DE3DLDU,&var8);
  setData(idTTLDU,&var12);
  setData(idB3AB13LDU,&var134);
  setData(idA3AB13LDU,&var137);
  setData(idR3VS01IDU,&var143);
  setData(idR3VS12LDU,&var141);
  setData(idR3VS22LDU,&var142);
  setData(idR5VS01IDU,&var140);
  setData(idR5VS12LDU,&var138);
  setData(idR5VS22LDU,&var139);
  setData(idB3AB15LDU,&var147);
  setData(idB3EE03LDU,&var815);
  setData(idA3EE03LDU,&var816);
  setData(idB3AB19LDU,&var152);
  setData(idA3AB19LDU,&var153);
  setData(idR0VL23LDU,&var1051);
  setData(idR0VL22LDU,&var1073);
  setData(idR0AD05LZ2,&var79);
  setData(idR0AD05LZ1,&var79);
  setData(idR0AD04LZ2,&var375);
  setData(idR0AD04LZ1,&var375);
  setData(idR0AD03LZ2,&var78);
  setData(idR0AD03LZ1,&var78);
  setData(idR0CN95LDU,&var223);
  setData(idR0CN94LDU,&var222);
  setData(idR0CN93LDU,&var221);
  setData(idR0AB19LDU,&var184);
  setData(idR0VN12RDU,&var984);
  setData(idR0VN11RDU,&var982);
  setData(idR0CN92LDU,&var188);
  setData(idR0AB20LDU,&var200);
  setData(idA3AB15LDU,&var148);
  setData(idA3MC03RDU,&var219);
  setData(idR0CN91LDU,&var218);
  setData(idA3MC02RDU,&var217);
  setData(idA3MC01RDU,&var216);
  setData(idR0AB18LDU,&var205);
  setData(idR0AB17LDU,&var212);
  setData(idR0AB16LDU,&var213);
  setData(idB1AB19LDU,&var230);
  setData(idA3ZAV,&var1323);
  setData(idA1ZAV,&var1386);
  setData(idB3IS12LDU,&var240);
  setData(idA3IS12LDU,&var241);
  setData(idR0AB15LDU,&var246);
  setData(idR0AB14LDU,&var244);
  setData(idA4DW,&var1161);
  setData(idA4UP,&var1162);
  setData(idR4ABL,&var1625);
  setData(idA9ZAV,&var1261);
  setData(idA8ZAV,&var1462);
  setData(idA2ZAV,&var1467);
  setData(idB8ZAV,&var1472);
  setData(idA5ZAV,&var1540);
  setData(idR2ZAV,&var1416);
  setData(idA6ZAV,&var1542);
  setData(idA4ZAV,&var1541);
  setData(idR0AB13LDU,&var313);
  setData(idR0AB12LDU,&var317);
  setData(idR0AB11LDU,&var321);
  setData(idR0AB10LDU,&var325);
  setData(idR0AB09LDU,&var329);
  setData(idR0AB08LDU,&var333);
  setData(idB6AB05LDU,&var376);
  setData(idR0VS11LDU,&var1671);
  setData(idA8VS01IDU,&var1466);
  setData(idB8VS01IDU,&var1476);
  setData(idR2AD10LDU,&var1421);
  setData(idR2AD20LDU,&var1422);
  setData(idB6VS01IDU,&var1613);
  setData(idR0AD16LDU,&lRM_0_);
  setData(idR0AB07LDU,&var615);
  setData(idR0EE03LDU,&var400);
  setData(idR0VX02LDU,&var821);
  setData(idR0AD21LDU,&var819);
  setData(idB2AB15LDU,&var346);
  setData(idA2AB15LDU,&var347);
  setData(idR0AB05LDU,&var1133);
  setData(idR0AB03LDU,&var1144);
  setData(idA1AB19LDU,&var231);
  setData(idR0VZ71LDU,&var65);
  setData(idR0VL01RDU,&var1179);
  setData(idB7AZ03LDU,&var377);
  setData(idA7AZ03LDU,&var485);
  setData(idB2VS01IDU,&var1454);
  setData(idB2VS21LDU,&var1456);
  setData(idB2VS11LDU,&var1455);
  setData(idR0VP73LDU,&var496);
  setData(idR0VS18LDU,&var573);
  setData(idB3VX01LDU,&var443);
  setData(idA3VX01LDU,&var444);
  setData(idB2VS32LDU,&var359);
  setData(idA2VS32LDU,&var360);
  setData(idR0VS17LDU,&var563);
  setData(idR0VX09LDU,&var176);
  moveData(idR0VX08IDU,idR0MW12IP1);
  setData(idR0VW23LDU,&var916);
  setData(idR0VW13LDU,&var915);
  setData(idB7AP31LDU,&var1164);
  setData(idA7AP31LDU,&var1165);
  setData(idB3AD31LDU,&var1224);
  setData(idB3AD34LDU,&var1225);
  setData(idA3AD31LDU,&var1230);
  setData(idA3AD34LDU,&var1227);
  setData(idA3AD33LDU,&var1229);
  setData(idB2AD33LDU,&var338);
  setData(idA2AD33LDU,&var341);
  setData(idR0AB01LDU,&var1253);
  setData(idB9AB02LDU,&var1263);
  setData(idB9AB01LDU,&var1264);
  setData(idB9AZ03LDU,&var1262);
  setData(idA9AB02LDU,&var1269);
  setData(idA9AB01LDU,&var1270);
  setData(idA9AZ03LDU,&var1268);
  setData(idA9AD10LDU,&var1271);
  setData(idB9AD10LDU,&var1265);
  setData(idR1VS01IDU,&var1432);
  setData(idR2VS01IDU,&var1423);
  setData(idR4VS01IDU,&var1604);
  setData(idA6VS01IDU,&var1622);
  setData(idB5VS01IDU,&var1586);
  setData(idA5VS01IDU,&var1595);
  setData(idB4VS22LDU,&var1567);
  setData(idB4VS12LDU,&var1566);
  setData(idB4VS01IDU,&var1568);
  setData(idA4VS22LDU,&var1576);
  setData(idA4VS12LDU,&var1575);
  setData(idA4VS01IDU,&var1577);
  setData(idA2VS01IDU,&var1495);
  setData(idB3VS01IDU,&var1313);
  setData(idA3VS01IDU,&var1345);
  setData(idB1VS01IDU,&var1374);
  setData(idA1VS01IDU,&var1407);
  setData(idR0VS21IDU,&var1154);
  setData(idR0VX03LDU,&var766);
  setData(idR0VL21IDU,&var1064);
  setData(idR0VL05RDU,&var430);
  setData(idR0VL03RDU,&var436);
  setData(idR0AB02LDU,&var1127);
  setData(idR0AB06LDU,&var1130);
  setData(idR0AB04LDU,&var1138);
  setData(idR0VL04RDU,&var433);
  setData(idR0AD14LDU,&var375);
  setData(idR8AD21LDU,&var398);
  setData(idR0VL02RDU,&var427);
  setData(idB3AD33LDU,&var1223);
  setData(idR0VL06RDU,&var440);
  setData(idR0VL11IDU,&var1277);
  setData(idR0VL01IDU,&var1278);
  setData(idR0VX01LDU,&var823);
  setData(idB1AD32LDU,&var1231);
  setData(idA1AD32LDU,&var1233);
  setData(idB2AD32LDU,&var366);
  setData(idA2AD32LDU,&var368);
  setData(idB1AD31LDU,&var1234);
  setData(idA1AD31LDU,&var1235);
  setData(idB2AD31LDU,&var369);
  setData(idA2AD31LDU,&var370);
  setData(idB3AB20LDU,&var657);
  setData(idB3AB18LDU,&var654);
  setData(idB3AB17LDU,&var650);
  setData(idB3AB16LDU,&var651);
  setData(idB3AB14LDU,&var925);
  setData(idB3AB12LDU,&var655);
  setData(idB3AB11LDU,&var659);
  setData(idB3AB10LDU,&var660);
  setData(idB3AB09LDU,&var661);
  setData(idB3AB06LDU,&var664);
  setData(idB3AB05LDU,&var666);
  setData(idB3AB08LDU,&var656);
  setData(idB3AB07LDU,&var665);
  setData(idB3CV02RDU,&var1312);
  setData(idB3AD01LDU,&var1305);
  setData(idB3AD05LDU,&var1311);
  setData(idB3AD04LDU,&var1310);
  setData(idB3AD03LDU,&var1309);
  setData(idB3AD02LDU,&var1308);
  setData(idB3AD21LDU,&var1306);
  setData(idB3AD11LDU,&var1307);
  setData(idB3AZ03LDU,&var997);
  setData(idB3VS22LDU,&var1316);
  setData(idB3AB01LDU,&var1314);
  setData(idB3AB02LDU,&var1315);
  setData(idB3AB04LDU,&var1320);
  setData(idB3CV01RDU,&var1318);
  setData(idB3VS12LDU,&var1317);
  setData(idA3AB20LDU,&var408);
  setData(idA3AB18LDU,&var671);
  setData(idA3AB17LDU,&var669);
  setData(idA3AB16LDU,&var668);
  setData(idA3AB14LDU,&var927);
  setData(idA3AB12LDU,&var672);
  setData(idA3AB11LDU,&var676);
  setData(idA3AB10LDU,&var680);
  setData(idA3AB09LDU,&var674);
  setData(idA3AB06LDU,&var679);
  setData(idA3AB05LDU,&var682);
  setData(idA3AB08LDU,&var673);
  setData(idA3AB07LDU,&var681);
  setData(idA3CV02RDU,&var1344);
  setData(idA3AD01LDU,&var1337);
  setData(idA3AD05LDU,&var1343);
  setData(idA3AD04LDU,&var1342);
  setData(idA3AD03LDU,&var1341);
  setData(idA3AD02LDU,&var1340);
  setData(idA3AD21LDU,&var1338);
  setData(idA3AD11LDU,&var1339);
  setData(idA3AZ03LDU,&var998);
  setData(idA3VS22LDU,&var1348);
  setData(idA3AB01LDU,&var1346);
  setData(idA3AB02LDU,&var1347);
  setData(idA3AB04LDU,&var1352);
  setData(idA3CV01RDU,&var1350);
  setData(idA3VS12LDU,&var1349);
  setData(idB1AB18LDU,&var741);
  setData(idB1AB17LDU,&var910);
  setData(idB1AB16LDU,&var909);
  setData(idB1AB14LDU,&var929);
  setData(idB1AB13LDU,&var930);
  setData(idB1AB12LDU,&var739);
  setData(idB1AB11LDU,&var743);
  setData(idB1AB10LDU,&var744);
  setData(idB1AB09LDU,&var747);
  setData(idB1AB06LDU,&var745);
  setData(idB1AB05LDU,&var752);
  setData(idB1AB08LDU,&var740);
  setData(idB1AB07LDU,&var751);
  setData(idB1CV02RDU,&var1373);
  setData(idB1AD01LDU,&var1366);
  setData(idB1AD05LDU,&var1372);
  setData(idB1AD04LDU,&var1371);
  setData(idB1AD03LDU,&var1370);
  setData(idB1AD02LDU,&var1369);
  setData(idB1AD21LDU,&var1368);
  setData(idB1AD11LDU,&var1367);
  setData(idB1AZ03LDU,&var754);
  setData(idB1VS22LDU,&var1378);
  setData(idB1AB01LDU,&var1375);
  setData(idB1AB02LDU,&var1376);
  setData(idB1AB04LDU,&var1381);
  setData(idB1CV01RDU,&var1379);
  setData(idB1VS12LDU,&var1377);
  setData(idA1AB18LDU,&var717);
  setData(idA1AB17LDU,&var716);
  setData(idA1AB16LDU,&var718);
  setData(idA1AB14LDU,&var932);
  setData(idA1AB13LDU,&var933);
  setData(idA1AB12LDU,&var714);
  setData(idA1AB11LDU,&var723);
  setData(idA1AB10LDU,&var721);
  setData(idA1AB09LDU,&var720);
  setData(idA1AB06LDU,&var725);
  setData(idA1AB05LDU,&var726);
  setData(idA1AB08LDU,&var719);
  setData(idA1AB07LDU,&var727);
  setData(idA1CV02RDU,&var1406);
  setData(idA1AD01LDU,&var1399);
  setData(idA1AD05LDU,&var1405);
  setData(idA1AD04LDU,&var1404);
  setData(idA1AD03LDU,&var1403);
  setData(idA1AD02LDU,&var1402);
  setData(idA1AD21LDU,&var1401);
  setData(idA1AD11LDU,&var1400);
  setData(idA1AZ03LDU,&var734);
  setData(idA1VS22LDU,&var1409);
  setData(idA1AB01LDU,&var732);
  setData(idA1AB02LDU,&var733);
  setData(idA1AB04LDU,&var1412);
  setData(idA1CV01RDU,&var1410);
  setData(idA1VS12LDU,&var1408);
  setData(idR1AD20LDU,&var1431);
  setData(idR1AD10LDU,&var1430);
  setData(idR2AB04LDU,&var1419);
  setData(idR1AB04LDU,&var1428);
  setData(idR2AB02LDU,&var1418);
  setData(idR2AB01LDU,&var1420);
  setData(idR2AZ03LDU,&var1417);
  setData(idR1AB02LDU,&var1427);
  setData(idR1AB01LDU,&var1429);
  setData(idR1AZ03LDU,&var1426);
  setData(idB2AB17LDU,&var690);
  setData(idB2AB16LDU,&var689);
  setData(idB2AB14LDU,&var934);
  setData(idB2AB13LDU,&var935);
  setData(idB2AB12LDU,&var691);
  setData(idB2AB11LDU,&var695);
  setData(idB2AB10LDU,&var694);
  setData(idB2AB09LDU,&var693);
  setData(idB2AB06LDU,&var698);
  setData(idB2AB05LDU,&var697);
  setData(idB2AB08LDU,&var692);
  setData(idB2AB07LDU,&var699);
  setData(idB2CV02RDU,&var1453);
  setData(idB2AD01LDU,&var1446);
  setData(idB2AD05LDU,&var1452);
  setData(idB2AD04LDU,&var1451);
  setData(idB2AD03LDU,&var1450);
  setData(idB2AD02LDU,&var1449);
  setData(idB2AD21LDU,&var1448);
  setData(idB2AD11LDU,&var1447);
  setData(idB2AZ03LDU,&var707);
  setData(idB2AB01LDU,&var706);
  setData(idB2AB02LDU,&var705);
  setData(idB2AB04LDU,&var1459);
  setData(idB2CV01RDU,&var1457);
  setData(idA2CV02RDU,&var1494);
  setData(idA2AD01LDU,&var1487);
  setData(idA2AB17LDU,&var628);
  setData(idA2AB16LDU,&var629);
  setData(idA2AB14LDU,&var632);
  setData(idA2AB13LDU,&var633);
  setData(idA2AB12LDU,&var630);
  setData(idA2AB11LDU,&var638);
  setData(idA2AB10LDU,&var636);
  setData(idA2AB09LDU,&var634);
  setData(idA2AB06LDU,&var639);
  setData(idA2AB05LDU,&var635);
  setData(idA2AB08LDU,&var631);
  setData(idA2AB07LDU,&var637);
  setData(idA2AD05LDU,&var1493);
  setData(idA2AD04LDU,&var1492);
  setData(idA2AD03LDU,&var1491);
  setData(idA2AD02LDU,&var1490);
  setData(idA2AD21LDU,&var1489);
  setData(idA2AD11LDU,&var1488);
  setData(idA2AZ03LDU,&var999);
  setData(idA2VS21LDU,&var1499);
  setData(idA2AB01LDU,&var1496);
  setData(idA2AB02LDU,&var1497);
  setData(idA2AB04LDU,&var1502);
  setData(idA2CV01RDU,&var1500);
  setData(idA2VS11LDU,&var1498);
  setData(idA8AB01LDU,&var1510);
  setData(idA8AB02LDU,&var516);
  setData(idA8AB14LDU,&var517);
  setData(idA8AB13LDU,&var518);
  setData(idA8AB12LDU,&var520);
  setData(idA8AB11LDU,&var521);
  setData(idA8AB10LDU,&var522);
  setData(idA8AB09LDU,&var523);
  setData(idA8AB08LDU,&var524);
  setData(idA8AB04LDU,&var1509);
  setData(idA8AD20LDU,&var1465);
  setData(idA8AD10LDU,&var1464);
  setData(idA8AZ03LDU,&var989);
  setData(idA8VS22LDU,&var1512);
  setData(idA8AB05LDU,&var1507);
  setData(idA8AB07LDU,&var1508);
  setData(idA8AB06LDU,&var1515);
  setData(idA8CV01RDU,&var1513);
  setData(idA8VS12LDU,&var1511);
  setData(idB8AB02LDU,&var834);
  setData(idB8AB14LDU,&var835);
  setData(idB8AB13LDU,&var836);
  setData(idB8AB12LDU,&var837);
  setData(idB8AB11LDU,&var841);
  setData(idB8AB10LDU,&var838);
  setData(idB8AB09LDU,&var839);
  setData(idB8AB08LDU,&var840);
  setData(idB8AB04LDU,&var1526);
  setData(idB8AB01LDU,&var1527);
  setData(idB8AD20LDU,&var1475);
  setData(idB8AD10LDU,&var1474);
  setData(idB8AZ03LDU,&var990);
  setData(idB8VS22LDU,&var1529);
  setData(idB8AB05LDU,&var1518);
  setData(idB8AB07LDU,&var1519);
  setData(idB8AB06LDU,&var1532);
  setData(idB8CV01RDU,&var1530);
  setData(idB8VS12LDU,&var1528);
  setData(idA6AB05LDU,&var957);
  setData(idB6AB09LDU,&var956);
  setData(idB6AB08LDU,&var955);
  setData(idB6AB07LDU,&var954);
  setData(idB6AB06LDU,&var953);
  setData(idA6AB09LDU,&var958);
  setData(idA6AB08LDU,&var944);
  setData(idA6AB07LDU,&var146);
  setData(idA6AB06LDU,&var959);
  setData(idB5AB04LDU,&var1582);
  setData(idA5AB04LDU,&var1591);
  setData(idB4AB02LDU,&var1563);
  setData(idB4AB01LDU,&var1564);
  setData(idB4AZ03LDU,&var1562);
  setData(idA4AB02LDU,&var1572);
  setData(idA4AB01LDU,&var1573);
  setData(idA4AZ03LDU,&var1571);
  setData(idA4AD10LDU,&var1574);
  setData(idB4AD10LDU,&var1565);
  setData(idB5AB02LDU,&var1581);
  setData(idB5AB01LDU,&var1583);
  setData(idB5AZ03LDU,&var1580);
  setData(idA5AB02LDU,&var1590);
  setData(idA5AB01LDU,&var1592);
  setData(idA5AZ03LDU,&var1589);
  setData(idA5AD20LDU,&var1594);
  setData(idA5AD10LDU,&var1593);
  setData(idB5AD20LDU,&var1585);
  setData(idB5AD10LDU,&var1584);
  setData(idR4AD20LDU,&var1603);
  setData(idR4AD10LDU,&var1602);
  setData(idR4AB18LDU,&var887);
  setData(idR4AB17LDU,&var886);
  setData(idR4AB16LDU,&var889);
  setData(idR4AB15LDU,&var888);
  setData(idR4AB14LDU,&var890);
  setData(idR4AB13LDU,&var858);
  setData(idR4AB12LDU,&var863);
  setData(idR4AB11LDU,&var895);
  setData(idR4AB10LDU,&var860);
  setData(idR4AB09LDU,&var893);
  setData(idR4AB08LDU,&var892);
  setData(idR4AB07LDU,&var896);
  setData(idR4AB06LDU,&var1600);
  setData(idR4AB05LDU,&var1599);
  setData(idR4AB04LDU,&var1601);
  setData(idR4AB03LDU,&var897);
  setData(idR4AZ03LDU,&var1598);
  setData(idR4AB02LDU,&var900);
  setData(idR4AB01LDU,&var901);
  setData(idB6AB04LDU,&var1609);
  setData(idA6AB04LDU,&var1618);
  setData(idB6AB02LDU,&var1608);
  setData(idB6AB01LDU,&var1610);
  setData(idB6AZ03LDU,&var1607);
  setData(idA6AB02LDU,&var1617);
  setData(idA6AB01LDU,&var1619);
  setData(idA6AZ03LDU,&var1616);
  setData(idB6AD20LDU,&var1612);
  setData(idB6AD10LDU,&var1611);
  setData(idA6AD20LDU,&var1621);
  setData(idA6AD10LDU,&var1620);
  setData(idR0ES01LDU,&var905);

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
    array_m341_rz_1[i] = &(&internal1_m341_rz)[i*1];
  for( i=0;i<10;i++ )
    array_m284_rz_1[i] = &(&internal1_m284_rz)[i*1];
  for( i=0;i<6;i++ )
    array_m1421_rz_1[i] = &(&internal1_m1421_rz)[i*1];
  for( i=0;i<60;i++ )
    array_m1348_x0_1[i] = &(&internal1_m1348_x0)[i*5];
  for( i=0;i<60;i++ )
    array_m1348_tim0_1[i] = &(&internal1_m1348_tim0)[i*5];
  for( i=0;i<60;i++ )
    array_m936_x0_1[i] = &(&internal1_m936_x0)[i*5];
  for( i=0;i<60;i++ )
    array_m936_tim0_1[i] = &(&internal1_m936_tim0)[i*5];
  for( i=0;i<150;i++ )
    array_m532_x0_1[i] = &(&internal1_m532_x0)[i*5];
  for( i=0;i<150;i++ )
    array_m532_tim0_1[i] = &(&internal1_m532_tim0)[i*5];
  for( i=0;i<150;i++ )
    array_m213_x0_1[i] = &(&internal1_m213_x0)[i*5];
  for( i=0;i<150;i++ )
    array_m213_tim0_1[i] = &(&internal1_m213_tim0)[i*5];
  for( i=0;i<80;i++ )
    array_m843_x0_1[i] = &(&internal1_m843_x0)[i*5];
  for( i=0;i<80;i++ )
    array_m843_tim0_1[i] = &(&internal1_m843_tim0)[i*5];
  for( i=0;i<80;i++ )
    array_m1257_x0_1[i] = &(&internal1_m1257_x0)[i*5];
  for( i=0;i<80;i++ )
    array_m1257_tim0_1[i] = &(&internal1_m1257_tim0)[i*5];
  for( i=0;i<20;i++ )
    array_m1622_x0_1[i] = &(&internal1_m1622_x0)[i*5];
  for( i=0;i<20;i++ )
    array_m1622_tim0_1[i] = &(&internal1_m1622_tim0)[i*5];
  for( i=0;i<20;i++ )
    array_m1147_x0_1[i] = &(&internal1_m1147_x0)[i*5];
  for( i=0;i<20;i++ )
    array_m1147_tim0_1[i] = &(&internal1_m1147_tim0)[i*5];
}

#endif
