#ifndef DU_H
#define DU_H
// Подсистема DU:DU
static char SimulOn=0;
static short CodeSub=2;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 10866
static char BUFFER[10866];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.50\0", 5432, "192.168.10.150\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0AB07LDU	 BUFFER[0]	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
#define idR0AB07LDU	 1	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
#define R0AD16LDU	 BUFFER[2]	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
#define idR0AD16LDU	 2	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
#define C2MD31LP1	 BUFFER[4]	//( - , DU) Кнопка СБРОС РБ
#define idC2MD31LP1	 3	//( - , DU) Кнопка СБРОС РБ
#define B6VS01IDU	 BUFFER[6]	//( - , DU) Готовность к управлению БЗ2
#define idB6VS01IDU	 4	//( - , DU) Готовность к управлению БЗ2
#define R2AD20LDU	 BUFFER[9]	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
#define idR2AD20LDU	 5	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
#define R2AD10LDU	 BUFFER[11]	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
#define idR2AD10LDU	 6	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
#define B8VS01IDU	 BUFFER[13]	//( - , DU) Готовность к управлению АЗ2
#define idB8VS01IDU	 7	//( - , DU) Готовность к управлению АЗ2
#define A8VS01IDU	 BUFFER[16]	//( - , DU) Готовность к управлению ДС2
#define idA8VS01IDU	 8	//( - , DU) Готовность к управлению ДС2
#define A1IE03LDU	 BUFFER[19]	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
#define idA1IE03LDU	 9	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
#define A1IE04LDU	 BUFFER[21]	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
#define idA1IE04LDU	 10	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
#define A2IE03LDU	 BUFFER[23]	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
#define idA2IE03LDU	 11	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
#define A2IE04LDU	 BUFFER[25]	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
#define idA2IE04LDU	 12	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
#define A3IE03LDU	 BUFFER[27]	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
#define idA3IE03LDU	 13	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
#define A3IE04LDU	 BUFFER[29]	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
#define idA3IE04LDU	 14	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
#define B1IE03LDU	 BUFFER[31]	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
#define idB1IE03LDU	 15	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
#define B1IE04LDU	 BUFFER[33]	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
#define idB1IE04LDU	 16	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
#define B2IE03LDU	 BUFFER[35]	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
#define idB2IE03LDU	 17	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
#define B2IE04LDU	 BUFFER[37]	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
#define idB2IE04LDU	 18	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
#define B3IE03LDU	 BUFFER[39]	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
#define idB3IE03LDU	 19	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
#define B3IE04LDU	 BUFFER[41]	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
#define idB3IE04LDU	 20	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
#define R0VS11LDU	 BUFFER[43]	//( - , DU) РУ не готова к работе
#define idR0VS11LDU	 21	//( - , DU) РУ не готова к работе
#define B6AB05LDU	 BUFFER[45]	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
#define idB6AB05LDU	 22	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
#define R0AB08LDU	 BUFFER[47]	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
#define idR0AB08LDU	 23	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
#define A3VZ15LZ1	 BUFFER[49]	//(vds32:02 - K19VDSR, - ) Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ1	 24	//(vds32:02 - K19VDSR, - ) Имитация срабатывания АЗ от НУП ИС
#define A3VZ15LZ2	 BUFFER[51]	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ2	 25	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define B2IS33LDU	 BUFFER[53]	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
#define idB2IS33LDU	 26	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
#define B3IS31LDU	 BUFFER[55]	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
#define idB3IS31LDU	 27	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
#define B3IS33LDU	 BUFFER[57]	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
#define idB3IS33LDU	 28	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
#define B3IS35LDU	 BUFFER[59]	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
#define idB3IS35LDU	 29	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
#define B4IS10LDU	 BUFFER[61]	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
#define idB4IS10LDU	 30	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
#define R6IS31LDU	 BUFFER[63]	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
#define idR6IS31LDU	 31	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
#define R6IS32LDU	 BUFFER[65]	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
#define idR6IS32LDU	 32	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
#define R6IS42LDU	 BUFFER[67]	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
#define idR6IS42LDU	 33	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
#define R6IS41LDU	 BUFFER[69]	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
#define idR6IS41LDU	 34	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
#define R6IS52LDU	 BUFFER[71]	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
#define idR6IS52LDU	 35	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
#define R6IS51LDU	 BUFFER[73]	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
#define idR6IS51LDU	 36	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
#define R3IS11LDU	 BUFFER[75]	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
#define idR3IS11LDU	 37	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
#define R3IS21LDU	 BUFFER[77]	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
#define idR3IS21LDU	 38	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
#define R0AB03LDU	 BUFFER[79]	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
#define idR0AB03LDU	 39	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
#define R0AB05LDU	 BUFFER[81]	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
#define idR0AB05LDU	 40	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
#define R0VN11RZ1	 BUFFER[83]	//( - , MDuBz1) Средняя мощность по BAZ1
#define idR0VN11RZ1	 41	//( - , MDuBz1) Средняя мощность по BAZ1
#define R0VN11RZ2	 BUFFER[88]	//( - , MDuBz2) Средняя мощность по BAZ2
#define idR0VN11RZ2	 42	//( - , MDuBz2) Средняя мощность по BAZ2
#define A2AB15LDU	 BUFFER[93]	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define idA2AB15LDU	 43	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define B2AB15LDU	 BUFFER[95]	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define idB2AB15LDU	 44	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define R0AD21LDU	 BUFFER[97]	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
#define idR0AD21LDU	 45	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
#define R0VX02LDU	 BUFFER[99]	//( - , DU) Импульс разрешен
#define idR0VX02LDU	 46	//( - , DU) Импульс разрешен
#define R0EE03LDU	 BUFFER[101]	//( - , DU) ВПИС ИС
#define idR0EE03LDU	 47	//( - , DU) ВПИС ИС
#define B3IS12LDU	 BUFFER[103]	//( - , DU) Приход на ВУ штока ИС2
#define idB3IS12LDU	 48	//( - , DU) Приход на ВУ штока ИС2
#define A1ZAV	 BUFFER[105]	//( - , DU) 
#define idA1ZAV	 49	//( - , DU) 
#define A3ZAV	 BUFFER[107]	//( - , DU) 
#define idA3ZAV	 50	//( - , DU) 
#define B1AB19LDU	 BUFFER[109]	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
#define idB1AB19LDU	 51	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
#define R0VN09RZ2	 BUFFER[111]	//( - , MDuBz2) Усредненный период разгона
#define idR0VN09RZ2	 52	//( - , MDuBz2) Усредненный период разгона
#define R0VN09RZ1	 BUFFER[116]	//( - , MDuBz1) Усредненный период разгона
#define idR0VN09RZ1	 53	//( - , MDuBz1) Усредненный период разгона
#define R0AB16LDU	 BUFFER[121]	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
#define idR0AB16LDU	 54	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
#define R0AB17LDU	 BUFFER[123]	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
#define idR0AB17LDU	 55	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
#define R0AB18LDU	 BUFFER[125]	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
#define idR0AB18LDU	 56	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
#define A0CT01IZ1	 BUFFER[127]	//( - , MDuBz1) Температура АЗ1-1
#define idA0CT01IZ1	 57	//( - , MDuBz1) Температура АЗ1-1
#define B0CT01IZ1	 BUFFER[132]	//( - , MDuBz1) Температура АЗ2-1
#define idB0CT01IZ1	 58	//( - , MDuBz1) Температура АЗ2-1
#define A0CT01IZ2	 BUFFER[137]	//( - , MDuBz2) Температура АЗ1-2
#define idA0CT01IZ2	 59	//( - , MDuBz2) Температура АЗ1-2
#define B0CT01IZ2	 BUFFER[142]	//( - , MDuBz2) Температура АЗ2-2
#define idB0CT01IZ2	 60	//( - , MDuBz2) Температура АЗ2-2
#define A3MC01RDU	 BUFFER[147]	//( - , DU) Заданная координата положения ИС от регулятора мм
#define idA3MC01RDU	 61	//( - , DU) Заданная координата положения ИС от регулятора мм
#define A3MC02RDU	 BUFFER[152]	//( - , DU) Температурная корректировка координаты ИМ
#define idA3MC02RDU	 62	//( - , DU) Температурная корректировка координаты ИМ
#define R0CN91LDU	 BUFFER[157]	//( - , DU) Рассчётная реактивность от регулятора
#define idR0CN91LDU	 63	//( - , DU) Рассчётная реактивность от регулятора
#define A3MC03RDU	 BUFFER[162]	//( - , DU) Координата положения ИМ 0-й реактивности
#define idA3MC03RDU	 64	//( - , DU) Координата положения ИМ 0-й реактивности
#define A3AB15LDU	 BUFFER[167]	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
#define idA3AB15LDU	 65	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
#define R0AB20LDU	 BUFFER[169]	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
#define idR0AB20LDU	 66	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
#define R0CN92LDU	 BUFFER[171]	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
#define idR0CN92LDU	 67	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
#define R0VN11RDU	 BUFFER[176]	//( - , DU) Текущая мощность РУ
#define idR0VN11RDU	 68	//( - , DU) Текущая мощность РУ
#define R0VN12RDU	 BUFFER[181]	//( - , DU) Заданная мощность РУ
#define idR0VN12RDU	 69	//( - , DU) Заданная мощность РУ
#define R0AB19LDU	 BUFFER[186]	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
#define idR0AB19LDU	 70	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
#define R0CN93LDU	 BUFFER[188]	//( - , DU) время работы на мощности более 100Вт, сек
#define idR0CN93LDU	 71	//( - , DU) время работы на мощности более 100Вт, сек
#define A1MC01RP1	 BUFFER[193]	//( - , DU) Заданная координата положения ББ1 мм
#define idA1MC01RP1	 72	//( - , DU) Заданная координата положения ББ1 мм
#define B1MC01RP1	 BUFFER[198]	//( - , DU) Заданная координата положения ББ2  мм
#define idB1MC01RP1	 73	//( - , DU) Заданная координата положения ББ2  мм
#define A3MC01RP1	 BUFFER[203]	//( - , DU) Заданная координата положения ИС1 мм
#define idA3MC01RP1	 74	//( - , DU) Заданная координата положения ИС1 мм
#define B3MC01RP1	 BUFFER[208]	//( - , DU) Заданная координата положения ИС2 мм
#define idB3MC01RP1	 75	//( - , DU) Заданная координата положения ИС2 мм
#define B8MC01RP2	 BUFFER[213]	//( - , DU) Заданная координата АЗ2 мм
#define idB8MC01RP2	 76	//( - , DU) Заданная координата АЗ2 мм
#define R0AB09LDU	 BUFFER[218]	//( - , DU) Ошибка в заданной координате ББ1
#define idR0AB09LDU	 77	//( - , DU) Ошибка в заданной координате ББ1
#define R0AB10LDU	 BUFFER[220]	//( - , DU) Ошибка в заданной координате ББ2
#define idR0AB10LDU	 78	//( - , DU) Ошибка в заданной координате ББ2
#define R0AB11LDU	 BUFFER[222]	//( - , DU) Ошибка в заданной координате  ИС1
#define idR0AB11LDU	 79	//( - , DU) Ошибка в заданной координате  ИС1
#define R0AB12LDU	 BUFFER[224]	//( - , DU) Ошибка в заданной координате  ИС2
#define idR0AB12LDU	 80	//( - , DU) Ошибка в заданной координате  ИС2
#define R0AB13LDU	 BUFFER[226]	//( - , DU) Ошибка в заданной координате  АЗ2
#define idR0AB13LDU	 81	//( - , DU) Ошибка в заданной координате  АЗ2
#define A4ZAV	 BUFFER[228]	//( - , DU) 
#define idA4ZAV	 82	//( - , DU) 
#define A6ZAV	 BUFFER[230]	//( - , DU) 
#define idA6ZAV	 83	//( - , DU) 
#define R2ZAV	 BUFFER[232]	//( - , DU) 
#define idR2ZAV	 84	//( - , DU) 
#define A5ZAV	 BUFFER[234]	//( - , DU) 
#define idA5ZAV	 85	//( - , DU) 
#define B8ZAV	 BUFFER[236]	//( - , DU) 
#define idB8ZAV	 86	//( - , DU) 
#define A2ZAV	 BUFFER[238]	//( - , DU) Завершение РБ1,2
#define idA2ZAV	 87	//( - , DU) Завершение РБ1,2
#define A8ZAV	 BUFFER[240]	//( - , DU) 
#define idA8ZAV	 88	//( - , DU) 
#define A9ZAV	 BUFFER[242]	//( - , DU) Завершение НИ ДС1(2)
#define idA9ZAV	 89	//( - , DU) Завершение НИ ДС1(2)
#define R4ABL	 BUFFER[244]	//( - , DU) Блокировка тележки -
#define idR4ABL	 90	//( - , DU) Блокировка тележки -
#define A4UP	 BUFFER[246]	//( - , DU) 
#define idA4UP	 91	//( - , DU) 
#define A4DW	 BUFFER[248]	//( - , DU) 
#define idA4DW	 92	//( - , DU) 
#define R0AB14LDU	 BUFFER[250]	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
#define idR0AB14LDU	 93	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
#define R0AB15LDU	 BUFFER[252]	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
#define idR0AB15LDU	 94	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
#define A3IS12LDU	 BUFFER[254]	//( - , DU) Приход на ВУ штока ИС1
#define idA3IS12LDU	 95	//( - , DU) Приход на ВУ штока ИС1
#define B3IS22LDU	 BUFFER[256]	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
#define idB3IS22LDU	 96	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
#define A2AD33LDU	 BUFFER[258]	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
#define idA2AD33LDU	 97	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
#define B2AD33LDU	 BUFFER[260]	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
#define idB2AD33LDU	 98	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
#define A3AD33LDU	 BUFFER[262]	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
#define idA3AD33LDU	 99	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
#define A3AD34LDU	 BUFFER[264]	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
#define idA3AD34LDU	 100	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
#define A3AD31LDU	 BUFFER[266]	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
#define idA3AD31LDU	 101	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
#define B3AD34LDU	 BUFFER[268]	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
#define idB3AD34LDU	 102	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
#define B3AD31LDU	 BUFFER[270]	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
#define idB3AD31LDU	 103	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
#define A2IS11LDU	 BUFFER[272]	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
#define idA2IS11LDU	 104	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
#define B2IS11LDU	 BUFFER[274]	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
#define idB2IS11LDU	 105	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
#define A3MD12LP1	 BUFFER[276]	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
#define idA3MD12LP1	 106	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
#define A3MD11LP1	 BUFFER[278]	//( - , DU) Кнопка ПУСК ИС1
#define idA3MD11LP1	 107	//( - , DU) Кнопка ПУСК ИС1
#define R0MD33LP1	 BUFFER[280]	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
#define idR0MD33LP1	 108	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
#define A1MD12LP1	 BUFFER[282]	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
#define idA1MD12LP1	 109	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
#define A1MD11LP1	 BUFFER[284]	//( - , DU) Кнопка ПУСК ББ1
#define idA1MD11LP1	 110	//( - , DU) Кнопка ПУСК ББ1
#define R0MW14IP2	 BUFFER[286]	//( - , DU) Переключатель ОБДУВ
#define idR0MW14IP2	 111	//( - , DU) Переключатель ОБДУВ
#define A7AP31LDU	 BUFFER[289]	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
#define idA7AP31LDU	 112	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
#define B7AP31LDU	 BUFFER[291]	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
#define idB7AP31LDU	 113	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
#define R0MW12IP2	 BUFFER[293]	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define idR0MW12IP2	 114	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define R0MW17LP1	 BUFFER[296]	//( - , DU) Переключатель АВТ/Р
#define idR0MW17LP1	 115	//( - , DU) Переключатель АВТ/Р
#define R0VW13LDU	 BUFFER[298]	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
#define idR0VW13LDU	 116	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
#define R0VW23LDU	 BUFFER[300]	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
#define idR0VW23LDU	 117	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
#define R0VX08IDU	 BUFFER[302]	//( - , DU) Индикация Режим
#define idR0VX08IDU	 118	//( - , DU) Индикация Режим
#define R0VX09LDU	 BUFFER[305]	//( - , DU) Индикация регулятор мощности включен/отключен
#define idR0VX09LDU	 119	//( - , DU) Индикация регулятор мощности включен/отключен
#define A4VS22LDU	 BUFFER[307]	//( - , DU) Движение НИ1 в сторону НУ
#define idA4VS22LDU	 120	//( - , DU) Движение НИ1 в сторону НУ
#define B4VS01IDU	 BUFFER[309]	//( - , DU) Готовность к управлению НИ2
#define idB4VS01IDU	 121	//( - , DU) Готовность к управлению НИ2
#define B4VS12LDU	 BUFFER[312]	//( - , DU) Движение НИ2 в сторону ВУ
#define idB4VS12LDU	 122	//( - , DU) Движение НИ2 в сторону ВУ
#define B4VS22LDU	 BUFFER[314]	//( - , DU) Движение НИ2 в сторону НУ
#define idB4VS22LDU	 123	//( - , DU) Движение НИ2 в сторону НУ
#define A5VS01IDU	 BUFFER[316]	//( - , DU) Готовность к управлению НЛ1
#define idA5VS01IDU	 124	//( - , DU) Готовность к управлению НЛ1
#define B5VS01IDU	 BUFFER[319]	//( - , DU) Готовность к управлению НЛ2
#define idB5VS01IDU	 125	//( - , DU) Готовность к управлению НЛ2
#define A6VS01IDU	 BUFFER[322]	//( - , DU) Готовность к управлению БЗ1
#define idA6VS01IDU	 126	//( - , DU) Готовность к управлению БЗ1
#define R4VS01IDU	 BUFFER[325]	//( - , DU) Готовность к управлению тележкой реактора
#define idR4VS01IDU	 127	//( - , DU) Готовность к управлению тележкой реактора
#define R2VS01IDU	 BUFFER[328]	//( - , DU) Готовность к управлению МДЗ2
#define idR2VS01IDU	 128	//( - , DU) Готовность к управлению МДЗ2
#define R1VS01IDU	 BUFFER[331]	//( - , DU) Готовность к управлению МДЗ1
#define idR1VS01IDU	 129	//( - , DU) Готовность к управлению МДЗ1
#define A9IS11LDU	 BUFFER[334]	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
#define idA9IS11LDU	 130	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
#define A9IS21LDU	 BUFFER[336]	//(vds32:02 - K24VDSR, - ) Приход на НУ НИ ДС1
#define idA9IS21LDU	 131	//(vds32:02 - K24VDSR, - ) Приход на НУ НИ ДС1
#define B9IS11LDU	 BUFFER[338]	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
#define idB9IS11LDU	 132	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
#define B9IS21LDU	 BUFFER[340]	//(vds32:02 - K26VDSR, - ) Приход на НУ НИ ДС2
#define idB9IS21LDU	 133	//(vds32:02 - K26VDSR, - ) Приход на НУ НИ ДС2
#define B9AD10LDU	 BUFFER[342]	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
#define idB9AD10LDU	 134	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
#define A9AD10LDU	 BUFFER[344]	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
#define idA9AD10LDU	 135	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
#define A9AZ03LDU	 BUFFER[346]	//( - , DU) Несанкционированное перемещение НИ ДС1
#define idA9AZ03LDU	 136	//( - , DU) Несанкционированное перемещение НИ ДС1
#define A9AB01LDU	 BUFFER[348]	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
#define idA9AB01LDU	 137	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
#define A9AB02LDU	 BUFFER[350]	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
#define idA9AB02LDU	 138	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
#define B9AZ03LDU	 BUFFER[352]	//( - , DU) Несанкционированное перемещение НИ ДС2
#define idB9AZ03LDU	 139	//( - , DU) Несанкционированное перемещение НИ ДС2
#define B9AB01LDU	 BUFFER[354]	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
#define idB9AB01LDU	 140	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
#define B9AB02LDU	 BUFFER[356]	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
#define idB9AB02LDU	 141	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
#define R0AB01LDU	 BUFFER[358]	//( - , DU) Режим проверки разрешён
#define idR0AB01LDU	 142	//( - , DU) Режим проверки разрешён
#define A3IS22LDU	 BUFFER[360]	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
#define idA3IS22LDU	 143	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
#define B2VS21LDU	 BUFFER[362]	//( - , DU) Движение РБ2 в сторону НУ
#define idB2VS21LDU	 144	//( - , DU) Движение РБ2 в сторону НУ
#define B2VS01IDU	 BUFFER[364]	//( - , DU) Готовность к управлению РБ2
#define idB2VS01IDU	 145	//( - , DU) Готовность к управлению РБ2
#define A7AS31LDU	 BUFFER[367]	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
#define idA7AS31LDU	 146	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
#define B7AS31LDU	 BUFFER[369]	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
#define idB7AS31LDU	 147	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
#define A7AZ03LDU	 BUFFER[371]	//( - , DU) Несанкционированное включение обдува АЗ1
#define idA7AZ03LDU	 148	//( - , DU) Несанкционированное включение обдува АЗ1
#define B7AZ03LDU	 BUFFER[373]	//( - , DU) Несанкционированное включение обдува АЗ2
#define idB7AZ03LDU	 149	//( - , DU) Несанкционированное включение обдува АЗ2
#define B3MD12LP1	 BUFFER[375]	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
#define idB3MD12LP1	 150	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
#define B3MD11LP1	 BUFFER[377]	//( - , DU) Кнопка ПУСК ИС2
#define idB3MD11LP1	 151	//( - , DU) Кнопка ПУСК ИС2
#define R0VL01RDU	 BUFFER[379]	//( - , DU) Индикация Время задержки
#define idR0VL01RDU	 152	//( - , DU) Индикация Время задержки
#define R0VZ71LZ2	 BUFFER[384]	//(vds32:03 - K22VDSR, DU) Обобщенный сигнал АЗ 2 канала
#define idR0VZ71LZ2	 153	//(vds32:03 - K22VDSR, DU) Обобщенный сигнал АЗ 2 канала
#define R0VZ71LZ1	 BUFFER[386]	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
#define idR0VZ71LZ1	 154	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
#define R0VZ71LDU	 BUFFER[388]	//( - , DU) Обобщенный сигнал АЗ
#define idR0VZ71LDU	 155	//( - , DU) Обобщенный сигнал АЗ
#define A2IS33LDU	 BUFFER[390]	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
#define idA2IS33LDU	 156	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
#define A3IS31LDU	 BUFFER[392]	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
#define idA3IS31LDU	 157	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
#define A3IS33LDU	 BUFFER[394]	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
#define idA3IS33LDU	 158	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
#define A3IS35LDU	 BUFFER[396]	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
#define idA3IS35LDU	 159	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
#define A4IS10LDU	 BUFFER[398]	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
#define idA4IS10LDU	 160	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
#define A1VN71LZ1	 BUFFER[400]	//(vds32:02 - K21VDSR, - ) Блокировка автоматического подъёма ББ
#define idA1VN71LZ1	 161	//(vds32:02 - K21VDSR, - ) Блокировка автоматического подъёма ББ
#define A1VN71LZ2	 BUFFER[402]	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define idA1VN71LZ2	 162	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define A1AB19LDU	 BUFFER[404]	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
#define idA1AB19LDU	 163	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
#define R0AD14LZ1	 BUFFER[406]	//(vds32:02 - K20VDSR, - ) Имитация срабатывания АЗ от II УР
#define idR0AD14LZ1	 164	//(vds32:02 - K20VDSR, - ) Имитация срабатывания АЗ от II УР
#define R0AD14LZ2	 BUFFER[408]	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
#define idR0AD14LZ2	 165	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
#define A3VZ13LZ2	 BUFFER[410]	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ2	 166	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define A3VZ13LZ1	 BUFFER[412]	//(vds32:02 - K18VDSR, - ) Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ1	 167	//(vds32:02 - K18VDSR, - ) Имитация срабатывания АЗ от ВУ ИС
#define R0VS17LDU	 BUFFER[414]	//( - , DU) Индикация выбора АВТОМАТ
#define idR0VS17LDU	 168	//( - , DU) Индикация выбора АВТОМАТ
#define A2VS32LDU	 BUFFER[416]	//( - , DU) Индикация  СБРОС РБ1
#define idA2VS32LDU	 169	//( - , DU) Индикация  СБРОС РБ1
#define B2VS32LDU	 BUFFER[418]	//( - , DU) Индикация  СБРОС РБ2
#define idB2VS32LDU	 170	//( - , DU) Индикация  СБРОС РБ2
#define A3VX01LDU	 BUFFER[420]	//( - , DU) Индикация Выстрел ИС1
#define idA3VX01LDU	 171	//( - , DU) Индикация Выстрел ИС1
#define A3IS11LDU	 BUFFER[422]	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
#define idA3IS11LDU	 172	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
#define B3VX01LDU	 BUFFER[424]	//( - , DU) Индикация Выстрел ИС2
#define idB3VX01LDU	 173	//( - , DU) Индикация Выстрел ИС2
#define R0VS18LDU	 BUFFER[426]	//( - , DU) Индикация  Проверка схем сброса
#define idR0VS18LDU	 174	//( - , DU) Индикация  Проверка схем сброса
#define B1MD11LP1	 BUFFER[428]	//( - , DU) Кнопка ПУСК ББ2
#define idB1MD11LP1	 175	//( - , DU) Кнопка ПУСК ББ2
#define B1MD12LP1	 BUFFER[430]	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
#define idB1MD12LP1	 176	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
#define B2MD11LP1	 BUFFER[432]	//( - , DU) Кнопка ПУСК РБ2
#define idB2MD11LP1	 177	//( - , DU) Кнопка ПУСК РБ2
#define B2MD12LP1	 BUFFER[434]	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
#define idB2MD12LP1	 178	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
#define A2MD11LP1	 BUFFER[436]	//( - , DU) Кнопка ПУСК РБ1
#define idA2MD11LP1	 179	//( - , DU) Кнопка ПУСК РБ1
#define A2MD12LP1	 BUFFER[438]	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
#define idA2MD12LP1	 180	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
#define R0IS01LDU	 BUFFER[440]	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
#define idR0IS01LDU	 181	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
#define R0IS02LDU	 BUFFER[442]	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
#define idR0IS02LDU	 182	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
#define R0VP73LZ1	 BUFFER[444]	//( - , MDuBz1) ПС давления для РУ
#define idR0VP73LZ1	 183	//( - , MDuBz1) ПС давления для РУ
#define R0VP73LZ2	 BUFFER[446]	//( - , MDuBz2) ПС давления для РУ
#define idR0VP73LZ2	 184	//( - , MDuBz2) ПС давления для РУ
#define R0VP73LDU	 BUFFER[448]	//( - , DU) ПС давления для РУ
#define idR0VP73LDU	 185	//( - , DU) ПС давления для РУ
#define R0MD34LP1	 BUFFER[450]	//( - , DU) Кнопка КВИТИРОВАТЬ
#define idR0MD34LP1	 186	//( - , DU) Кнопка КВИТИРОВАТЬ
#define A0VT71LZ1	 BUFFER[452]	//( - , MDuBz1) АС по температуре в АЗ1
#define idA0VT71LZ1	 187	//( - , MDuBz1) АС по температуре в АЗ1
#define B0VT71LZ1	 BUFFER[454]	//( - , MDuBz1) АС по температуре в АЗ2
#define idB0VT71LZ1	 188	//( - , MDuBz1) АС по температуре в АЗ2
#define A0VT71LZ2	 BUFFER[456]	//( - , MDuBz2) АС по температуре в АЗ1
#define idA0VT71LZ2	 189	//( - , MDuBz2) АС по температуре в АЗ1
#define B0VT71LZ2	 BUFFER[458]	//( - , MDuBz2) АС по температуре в АЗ2
#define idB0VT71LZ2	 190	//( - , MDuBz2) АС по температуре в АЗ2
#define B2VS11LDU	 BUFFER[460]	//( - , DU) Движение РБ2 в сторону ВУ
#define idB2VS11LDU	 191	//( - , DU) Движение РБ2 в сторону ВУ
#define B3VP42LDU	 BUFFER[462]	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
#define idB3VP42LDU	 192	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
#define B3CP02RDU	 BUFFER[464]	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
#define idB3CP02RDU	 193	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
#define B3VP52LDU	 BUFFER[469]	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define idB3VP52LDU	 194	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define B3VP82LDU	 BUFFER[471]	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
#define idB3VP82LDU	 195	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
#define A3VP82LDU	 BUFFER[473]	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
#define idA3VP82LDU	 196	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
#define A3IP02IDU	 BUFFER[475]	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	 197	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
#define B3IP02IDU	 BUFFER[478]	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
#define idB3IP02IDU	 198	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
#define A0VE01LDU	 BUFFER[481]	//( - , DU) Напряжение в системы АЗ1 подано
#define idA0VE01LDU	 199	//( - , DU) Напряжение в системы АЗ1 подано
#define B0VE01LDU	 BUFFER[483]	//( - , DU) Напряжение в системы АЗ2 подано
#define idB0VE01LDU	 200	//( - , DU) Напряжение в системы АЗ2 подано
#define A0VP01LDU	 BUFFER[485]	//( - , DU) Давление в системы АЗ1 подано
#define idA0VP01LDU	 201	//( - , DU) Давление в системы АЗ1 подано
#define B0VP01LDU	 BUFFER[487]	//( - , DU) Давление в системы АЗ2 подано
#define idB0VP01LDU	 202	//( - , DU) Давление в системы АЗ2 подано
#define A0EE01LZ1	 BUFFER[489]	//( - , MDuBz1) Исправность АКНП1
#define idA0EE01LZ1	 203	//( - , MDuBz1) Исправность АКНП1
#define A0EE03LZ1	 BUFFER[491]	//( - , MDuBz1) Исправность АКНП3
#define idA0EE03LZ1	 204	//( - , MDuBz1) Исправность АКНП3
#define A0EE02LZ1	 BUFFER[493]	//( - , MDuBz1) Исправность АКНП2
#define idA0EE02LZ1	 205	//( - , MDuBz1) Исправность АКНП2
#define A0EE04LZ1	 BUFFER[495]	//( - , MDuBz1) Исправность АКНП4
#define idA0EE04LZ1	 206	//( - , MDuBz1) Исправность АКНП4
#define A0VN01LDU	 BUFFER[497]	//( - , DU) Каналы АЗ1 проверены
#define idA0VN01LDU	 207	//( - , DU) Каналы АЗ1 проверены
#define B0VN01LDU	 BUFFER[499]	//( - , DU) Каналы АЗ2 проверены
#define idB0VN01LDU	 208	//( - , DU) Каналы АЗ2 проверены
#define A0EE01LZ2	 BUFFER[501]	//( - , MDuBz2) Исправность АКНП1
#define idA0EE01LZ2	 209	//( - , MDuBz2) Исправность АКНП1
#define A0EE03LZ2	 BUFFER[503]	//( - , MDuBz2) Исправность АКНП3
#define idA0EE03LZ2	 210	//( - , MDuBz2) Исправность АКНП3
#define A0EE02LZ2	 BUFFER[505]	//( - , MDuBz2) Исправность АКНП2
#define idA0EE02LZ2	 211	//( - , MDuBz2) Исправность АКНП2
#define A0EE04LZ2	 BUFFER[507]	//( - , MDuBz2) Исправность АКНП4
#define idA0EE04LZ2	 212	//( - , MDuBz2) Исправность АКНП4
#define A0VP71LZ1	 BUFFER[509]	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ1	 213	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
#define A0VP71LZ2	 BUFFER[511]	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ2	 214	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
#define A8VC01RDU	 BUFFER[513]	//( - , DU) Координата ДС2, мм
#define idA8VC01RDU	 215	//( - , DU) Координата ДС2, мм
#define B8IC01UDU	 BUFFER[518]	//( - , MDuS) Координата АЗ2 (дел.энк)
#define idB8IC01UDU	 216	//( - , MDuS) Координата АЗ2 (дел.энк)
#define A1IC01UDU	 BUFFER[523]	//( - , MDuS) Координата штока ББ1 (дел.энк)
#define idA1IC01UDU	 217	//( - , MDuS) Координата штока ББ1 (дел.энк)
#define A1VC01RDU	 BUFFER[528]	//( - , DU) Координата ББ1, мм
#define idA1VC01RDU	 218	//( - , DU) Координата ББ1, мм
#define A1IS11LDU	 BUFFER[533]	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
#define idA1IS11LDU	 219	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
#define B1MC01LC1	 BUFFER[535]	//( - , DU) Настроить энкодер ББ2
#define idB1MC01LC1	 220	//( - , DU) Настроить энкодер ББ2
#define B1MC01LC2	 BUFFER[537]	//( - , DU) Настроить энкодер ББ2
#define idB1MC01LC2	 221	//( - , DU) Настроить энкодер ББ2
#define A1MC01LC1	 BUFFER[539]	//( - , DU) Настроить энкодер ББ1
#define idA1MC01LC1	 222	//( - , DU) Настроить энкодер ББ1
#define A1MC01LC2	 BUFFER[541]	//( - , DU) Настроить энкодер ББ1
#define idA1MC01LC2	 223	//( - , DU) Настроить энкодер ББ1
#define B2MC01LC1	 BUFFER[543]	//( - , DU) Настроить энкодер РБ2
#define idB2MC01LC1	 224	//( - , DU) Настроить энкодер РБ2
#define B2MC01LC2	 BUFFER[545]	//( - , DU) Настроить энкодер РБ2
#define idB2MC01LC2	 225	//( - , DU) Настроить энкодер РБ2
#define A2MC01LC1	 BUFFER[547]	//( - , DU) Настроить энкодер РБ1
#define idA2MC01LC1	 226	//( - , DU) Настроить энкодер РБ1
#define A2MC01LC2	 BUFFER[549]	//( - , DU) Настроить энкодер РБ1
#define idA2MC01LC2	 227	//( - , DU) Настроить энкодер РБ1
#define B3MC01LC1	 BUFFER[551]	//( - , DU) Настроить энкодер ИС2
#define idB3MC01LC1	 228	//( - , DU) Настроить энкодер ИС2
#define B3MC01LC2	 BUFFER[553]	//( - , DU) Настроить энкодер ИС2
#define idB3MC01LC2	 229	//( - , DU) Настроить энкодер ИС2
#define A3MC01LC1	 BUFFER[555]	//( - , DU) Настроить энкодер ИС1
#define idA3MC01LC1	 230	//( - , DU) Настроить энкодер ИС1
#define A3MC01LC2	 BUFFER[557]	//( - , DU) Настроить энкодер ИС1
#define idA3MC01LC2	 231	//( - , DU) Настроить энкодер ИС1
#define B8MC01LC1	 BUFFER[559]	//( - , DU) Настроить энкодер АЗ2
#define idB8MC01LC1	 232	//( - , DU) Настроить энкодер АЗ2
#define B8MC01LC2	 BUFFER[561]	//( - , DU) Настроить энкодер АЗ2
#define idB8MC01LC2	 233	//( - , DU) Настроить энкодер АЗ2
#define A8MC01LC1	 BUFFER[563]	//( - , DU) Настроить энкодер ДС2
#define idA8MC01LC1	 234	//( - , DU) Настроить энкодер ДС2
#define A8MC01LC2	 BUFFER[565]	//( - , DU) Настроить энкодер ДС2
#define idA8MC01LC2	 235	//( - , DU) Настроить энкодер ДС2
#define A3VP42LDU	 BUFFER[567]	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
#define idA3VP42LDU	 236	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
#define A3CP02RDU	 BUFFER[569]	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
#define idA3CP02RDU	 237	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
#define A3VP52LDU	 BUFFER[574]	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define idA3VP52LDU	 238	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define R2IE01LDU	 BUFFER[576]	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
#define idR2IE01LDU	 239	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
#define R6IS61LDU	 BUFFER[578]	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
#define idR6IS61LDU	 240	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
#define R6IS64LDU	 BUFFER[580]	//( - , MDuS) Исправность ВИП ССДИ-35 1канал
#define idR6IS64LDU	 241	//( - , MDuS) Исправность ВИП ССДИ-35 1канал
#define R6IS65LDU	 BUFFER[582]	//( - , MDuS) Исправность ВИП ССДИ-35 2канал
#define idR6IS65LDU	 242	//( - , MDuS) Исправность ВИП ССДИ-35 2канал
#define R6IS62LDU	 BUFFER[584]	//( - , MDuS) Исправность ВИП ССДИ-39 1канал
#define idR6IS62LDU	 243	//( - , MDuS) Исправность ВИП ССДИ-39 1канал
#define R6IS63LDU	 BUFFER[586]	//( - , MDuS) Исправность ВИП ССДИ-39 2канал
#define idR6IS63LDU	 244	//( - , MDuS) Исправность ВИП ССДИ-39 2канал
#define R6IS66LZZ	 BUFFER[588]	//( - , MDuS) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 245	//( - , MDuS) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	 BUFFER[590]	//( - , MDuS) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 246	//( - , MDuS) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	 BUFFER[592]	//( - , MDuS) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 247	//( - , MDuS) Исправность ВИП 4,0 (№7) ССДИ-2
#define syn_R0EE03LDU	 BUFFER[594]	//( - , DU) ВПИС ИС
#define idsyn_R0EE03LDU	 248	//( - , DU) ВПИС ИС
#define A3VC01RDU	 BUFFER[596]	//( - , DU) Координата ИС1, мм
#define idA3VC01RDU	 249	//( - , DU) Координата ИС1, мм
#define A2VC01RDU	 BUFFER[601]	//( - , DU) Координата РБ1, мм
#define idA2VC01RDU	 250	//( - , DU) Координата РБ1, мм
#define B2VC01RDU	 BUFFER[606]	//( - , DU) Координата РБ2, мм
#define idB2VC01RDU	 251	//( - , DU) Координата РБ2, мм
#define B8VC01RDU	 BUFFER[611]	//( - , DU) Координата АЗ2, мм
#define idB8VC01RDU	 252	//( - , DU) Координата АЗ2, мм
#define A4VP82LDU	 BUFFER[616]	//( - , MDuS) Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	 253	//( - , MDuS) Давление ПОДЪЁМ НИ1 в норме
#define B4VP82LDU	 BUFFER[618]	//( - , MDuS) Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	 254	//( - , MDuS) Давление ПОДЪЁМ НИ2 в норме
#define A2VP82LDU	 BUFFER[620]	//( - , MDuS) Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	 255	//( - , MDuS) Давление ПОДЪЁМ РБ1 в норме
#define B2VP82LDU	 BUFFER[622]	//( - , MDuS) Давление ПОДЪЁМ РБ2 в норме
#define idB2VP82LDU	 256	//( - , MDuS) Давление ПОДЪЁМ РБ2 в норме
#define A3VP81LDU	 BUFFER[624]	//( - , MDuS) Давление СПУСК ИС1 в норме
#define idA3VP81LDU	 257	//( - , MDuS) Давление СПУСК ИС1 в норме
#define B3VP81LDU	 BUFFER[626]	//( - , MDuS) Давление СПУСК ИС2 в норме
#define idB3VP81LDU	 258	//( - , MDuS) Давление СПУСК ИС2 в норме
#define R0EE02LDU	 BUFFER[628]	//( - , DU) Питание  АКНП  отключить
#define idR0EE02LDU	 259	//( - , DU) Питание  АКНП  отключить
#define a1abf1	 BUFFER[630]	//( - , - ) признак изменения скорости
#define ida1abf1	 260	//( - , - ) признак изменения скорости
#define a1abf2	 BUFFER[632]	//( - , - ) положение механизма
#define ida1abf2	 261	//( - , - ) положение механизма
#define a1abf3	 BUFFER[637]	//( - , - ) текущее положение
#define ida1abf3	 262	//( - , - ) текущее положение
#define B0VP71LZ1	 BUFFER[642]	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ1	 263	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
#define B0VP71LZ2	 BUFFER[644]	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ2	 264	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
#define A0VS11LDU	 BUFFER[646]	//( - , DU) АЗ1 готова к работе
#define idA0VS11LDU	 265	//( - , DU) АЗ1 готова к работе
#define B0VS11LDU	 BUFFER[648]	//( - , DU) АЗ2 готова к работе
#define idB0VS11LDU	 266	//( - , DU) АЗ2 готова к работе
#define A1IE01LDU	 BUFFER[650]	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
#define idA1IE01LDU	 267	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
#define A3IE01LDU	 BUFFER[652]	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
#define idA3IE01LDU	 268	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
#define A2IE01LDU	 BUFFER[654]	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
#define idA2IE01LDU	 269	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
#define A1IE02LDU	 BUFFER[656]	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
#define idA1IE02LDU	 270	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
#define A3IE02LDU	 BUFFER[658]	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
#define idA3IE02LDU	 271	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
#define A2IE02LDU	 BUFFER[660]	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
#define idA2IE02LDU	 272	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
#define B1IE01LDU	 BUFFER[662]	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
#define idB1IE01LDU	 273	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
#define B2IE01LDU	 BUFFER[664]	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
#define idB2IE01LDU	 274	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
#define B3IE01LDU	 BUFFER[666]	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
#define idB3IE01LDU	 275	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
#define B1IE02LDU	 BUFFER[668]	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
#define idB1IE02LDU	 276	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
#define B3IE02LDU	 BUFFER[670]	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
#define idB3IE02LDU	 277	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
#define B2IE02LDU	 BUFFER[672]	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
#define idB2IE02LDU	 278	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
#define R0IE02LDU	 BUFFER[674]	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
#define idR0IE02LDU	 279	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
#define R0IE01LDU	 BUFFER[676]	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
#define idR0IE01LDU	 280	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
#define A6IE01LDU	 BUFFER[678]	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
#define idA6IE01LDU	 281	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
#define B6IE01LDU	 BUFFER[680]	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
#define idB6IE01LDU	 282	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
#define A8IE01LDU	 BUFFER[682]	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
#define idA8IE01LDU	 283	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
#define B5IE01LDU	 BUFFER[684]	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
#define idB5IE01LDU	 284	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
#define A5IE02LDU	 BUFFER[686]	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
#define idA5IE02LDU	 285	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
#define R1IE01LDU	 BUFFER[688]	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
#define idR1IE01LDU	 286	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
#define R5VS01IDU	 BUFFER[690]	//( - , DU) Готовность к управлению ворот отстойной зоны
#define idR5VS01IDU	 287	//( - , DU) Готовность к управлению ворот отстойной зоны
#define R3VS22LDU	 BUFFER[693]	//( - , DU) Движение гомогенных дверей к закрыты
#define idR3VS22LDU	 288	//( - , DU) Движение гомогенных дверей к закрыты
#define R3VS12LDU	 BUFFER[695]	//( - , DU) Движение гомогенных дверей к открыты
#define idR3VS12LDU	 289	//( - , DU) Движение гомогенных дверей к открыты
#define R3VS01IDU	 BUFFER[697]	//( - , DU) Готовность к управлению гомогенных дверей
#define idR3VS01IDU	 290	//( - , DU) Готовность к управлению гомогенных дверей
#define A3AB13LDU	 BUFFER[700]	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
#define idA3AB13LDU	 291	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
#define syn_A3VP52LDU	 BUFFER[702]	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define idsyn_A3VP52LDU	 292	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define B3AB13LDU	 BUFFER[704]	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define idB3AB13LDU	 293	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define syn_B3VP52LDU	 BUFFER[706]	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define idsyn_B3VP52LDU	 294	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define R0DE02LDU	 BUFFER[708]	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
#define idR0DE02LDU	 295	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
#define R0DE03LDU	 BUFFER[711]	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
#define idR0DE03LDU	 296	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
#define R0DE04LDU	 BUFFER[714]	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
#define idR0DE04LDU	 297	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
#define R0DE08LDU	 BUFFER[717]	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
#define idR0DE08LDU	 298	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
#define R0DE05LDU	 BUFFER[720]	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
#define idR0DE05LDU	 299	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
#define R0DE09LDU	 BUFFER[723]	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
#define idR0DE09LDU	 300	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
#define R0DE0ALDU	 BUFFER[726]	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
#define idR0DE0ALDU	 301	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
#define R0DE07LDU	 BUFFER[729]	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
#define idR0DE07LDU	 302	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
#define R0DE0CLDU	 BUFFER[732]	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
#define idR0DE0CLDU	 303	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
#define R0DE0BLDU	 BUFFER[735]	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
#define idR0DE0BLDU	 304	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
#define R0DE0DLDU	 BUFFER[738]	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
#define idR0DE0DLDU	 305	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
#define R0DE0FLDU	 BUFFER[741]	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
#define idR0DE0FLDU	 306	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
#define R0DE31LDU	 BUFFER[744]	//(sbk:20 - S01SBK, DiagnDU) диагностика шкафа ДУ сеть 1
#define idR0DE31LDU	 307	//(sbk:20 - S01SBK, DiagnDU) диагностика шкафа ДУ сеть 1
#define TTLDU	 BUFFER[746]	//( - , DU) ttl
#define idTTLDU	 308	//( - , DU) ttl
#define R0DE32LDU	 BUFFER[749]	//(sbk:20 - S02SBK, DiagnDU) диагностика шкафа ДУ сеть 2
#define idR0DE32LDU	 309	//(sbk:20 - S02SBK, DiagnDU) диагностика шкафа ДУ сеть 2
#define R0DE33LDU	 BUFFER[751]	//(sbk:20 - S03SBK, DiagnDU) диагностика шкафа ДУ двери
#define idR0DE33LDU	 310	//(sbk:20 - S03SBK, DiagnDU) диагностика шкафа ДУ двери
#define R0CN94LDU	 BUFFER[753]	//( - , DU) Скорость изменения мощности
#define idR0CN94LDU	 311	//( - , DU) Скорость изменения мощности
#define R0CN95LDU	 BUFFER[758]	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
#define idR0CN95LDU	 312	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
#define R0AD03LZ1	 BUFFER[761]	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
#define idR0AD03LZ1	 313	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
#define R0AD03LZ2	 BUFFER[763]	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
#define idR0AD03LZ2	 314	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
#define R0AD04LZ1	 BUFFER[765]	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define idR0AD04LZ1	 315	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define R0AD04LZ2	 BUFFER[767]	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define idR0AD04LZ2	 316	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define R0AD05LZ1	 BUFFER[769]	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
#define idR0AD05LZ1	 317	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
#define R0AD05LZ2	 BUFFER[771]	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
#define idR0AD05LZ2	 318	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
#define B8IS12LDU	 BUFFER[773]	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
#define idB8IS12LDU	 319	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
#define B8IS21LDU	 BUFFER[775]	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
#define idB8IS21LDU	 320	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
#define A1VP41LZ1	 BUFFER[777]	//( - , DU) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ1	 321	//( - , DU) Давление СБРОС ББ1 ниже АС
#define A1VP41LZ2	 BUFFER[779]	//( - , DU) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ2	 322	//( - , DU) Давление СБРОС ББ1 ниже АС
#define R0VL22LDU	 BUFFER[781]	//( - , DU) Конец программы 200сек
#define idR0VL22LDU	 323	//( - , DU) Конец программы 200сек
#define R0VL23LDU	 BUFFER[783]	//( - , DU) Конец программы 20мин
#define idR0VL23LDU	 324	//( - , DU) Конец программы 20мин
#define B1VP41LZ1	 BUFFER[785]	//( - , DU) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ1	 325	//( - , DU) Давление СБРОС ББ2 ниже АС
#define B1VP41LZ2	 BUFFER[787]	//( - , DU) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ2	 326	//( - , DU) Давление СБРОС ББ2 ниже АС
#define A3AB19LDU	 BUFFER[789]	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
#define idA3AB19LDU	 327	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
#define B3AB19LDU	 BUFFER[791]	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
#define idB3AB19LDU	 328	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
#define A3EE03LDU	 BUFFER[793]	//( - , DU) ВПИС ИС1
#define idA3EE03LDU	 329	//( - , DU) ВПИС ИС1
#define B3EE03LDU	 BUFFER[795]	//( - , DU) ВПИС ИС2
#define idB3EE03LDU	 330	//( - , DU) ВПИС ИС2
#define B3AB15LDU	 BUFFER[797]	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
#define idB3AB15LDU	 331	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
#define R5IS21LDU	 BUFFER[799]	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	 332	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
#define R5VS22LDU	 BUFFER[801]	//( - , DU) Движение ворот отстойной зоны к закрыты
#define idR5VS22LDU	 333	//( - , DU) Движение ворот отстойной зоны к закрыты
#define R5VS12LDU	 BUFFER[803]	//( - , DU) Движение ворот отстойной зоны к открыты
#define idR5VS12LDU	 334	//( - , DU) Движение ворот отстойной зоны к открыты
#define hz3	 BUFFER[805]	//( - , - ) 
#define idhz3	 335	//( - , - ) 
#define hz4	 BUFFER[807]	//( - , - ) 
#define idhz4	 336	//( - , - ) 
#define hz5	 BUFFER[809]	//( - , - ) 
#define idhz5	 337	//( - , - ) 
#define hz6	 BUFFER[811]	//( - , - ) 
#define idhz6	 338	//( - , - ) 
#define bd1	 BUFFER[813]	//( - , - ) 
#define idbd1	 339	//( - , - ) 
#define bd2	 BUFFER[815]	//( - , - ) 
#define idbd2	 340	//( - , - ) 
#define bd3	 BUFFER[817]	//( - , - ) 
#define idbd3	 341	//( - , - ) 
#define bd4	 BUFFER[819]	//( - , - ) 
#define idbd4	 342	//( - , - ) 
#define bd5	 BUFFER[821]	//( - , - ) 
#define idbd5	 343	//( - , - ) 
#define bd6	 BUFFER[823]	//( - , - ) 
#define idbd6	 344	//( - , - ) 
#define a1ab1	 BUFFER[825]	//( - , - ) 
#define ida1ab1	 345	//( - , - ) 
#define a1ab2	 BUFFER[827]	//( - , - ) 
#define ida1ab2	 346	//( - , - ) 
#define a1ab3	 BUFFER[829]	//( - , - ) 
#define ida1ab3	 347	//( - , - ) 
#define a1ab4	 BUFFER[831]	//( - , - ) 
#define ida1ab4	 348	//( - , - ) 
#define a1ab5	 BUFFER[833]	//( - , - ) 
#define ida1ab5	 349	//( - , - ) 
#define B1IC01UDU	 BUFFER[835]	//( - , MDuS) Координата штока ББ2 (дел.энк)
#define idB1IC01UDU	 350	//( - , MDuS) Координата штока ББ2 (дел.энк)
#define B1VC01RDU	 BUFFER[840]	//( - , DU) Координата ББ2, мм
#define idB1VC01RDU	 351	//( - , DU) Координата ББ2, мм
#define B1IS11LDU	 BUFFER[845]	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
#define idB1IS11LDU	 352	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
#define A2IC01UDU	 BUFFER[847]	//( - , MDuS) Координата штока РБ1 (дел.энк)
#define idA2IC01UDU	 353	//( - , MDuS) Координата штока РБ1 (дел.энк)
#define B2IC01UDU	 BUFFER[852]	//( - , MDuS) Координата штока РБ2 (дел.энк)
#define idB2IC01UDU	 354	//( - , MDuS) Координата штока РБ2 (дел.энк)
#define A3IC01UDU	 BUFFER[857]	//( - , MDuS) Координата штока ИС1 (дел.энк)
#define idA3IC01UDU	 355	//( - , MDuS) Координата штока ИС1 (дел.энк)
#define B3IC01UDU	 BUFFER[862]	//( - , MDuS) Координата штока ИС2 (дел.энк)
#define idB3IC01UDU	 356	//( - , MDuS) Координата штока ИС2 (дел.энк)
#define B3VC01RDU	 BUFFER[867]	//( - , DU) Координата ИС2, мм
#define idB3VC01RDU	 357	//( - , DU) Координата ИС2, мм
#define A8IC01UDU	 BUFFER[872]	//( - , MDuS) Координата ДС2 (дел.энк)
#define idA8IC01UDU	 358	//( - , MDuS) Координата ДС2 (дел.энк)
#define R0DE34LDU	 BUFFER[877]	//(sbk:20 - S04SBK, DiagnDU) диагностика шкафа ДУ температура меньше 43
#define idR0DE34LDU	 359	//(sbk:20 - S04SBK, DiagnDU) диагностика шкафа ДУ температура меньше 43
#define R0DE35LDU	 BUFFER[879]	//(sbk:20 - S05SBK, DiagnDU) диагностика шкафа ДУ температура больше 53
#define idR0DE35LDU	 360	//(sbk:20 - S05SBK, DiagnDU) диагностика шкафа ДУ температура больше 53
#define R0DE36LDU	 BUFFER[881]	//(sbk:20 - S06SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 1
#define idR0DE36LDU	 361	//(sbk:20 - S06SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 1
#define R0DE37LDU	 BUFFER[883]	//(sbk:20 - S07SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 2
#define idR0DE37LDU	 362	//(sbk:20 - S07SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 2
#define R0DE38LDU	 BUFFER[885]	//(sbk:20 - S08SBK, DiagnDU) диагностика шкафа ДУ МП15-3 место 3
#define idR0DE38LDU	 363	//(sbk:20 - S08SBK, DiagnDU) диагностика шкафа ДУ МП15-3 место 3
#define R0DE39LDU	 BUFFER[887]	//(sbk:20 - S09SBK, DiagnDU) диагностика шкафа ДУ МП24-2 место 4
#define idR0DE39LDU	 364	//(sbk:20 - S09SBK, DiagnDU) диагностика шкафа ДУ МП24-2 место 4
#define R0DEB3LDU	 BUFFER[889]	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
#define idR0DEB3LDU	 365	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
#define R0DEB2LDU	 BUFFER[891]	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
#define idR0DEB2LDU	 366	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
#define R0DEB1LDU	 BUFFER[893]	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
#define idR0DEB1LDU	 367	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
#define R0DEB4LDU	 BUFFER[895]	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
#define idR0DEB4LDU	 368	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
#define R0DE3DLDU	 BUFFER[897]	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
#define idR0DE3DLDU	 369	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
#define R0DE3CLDU	 BUFFER[899]	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
#define idR0DE3CLDU	 370	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
#define TestDiagnDU	 BUFFER[901]	//( - , DU) Неисправность от
#define idTestDiagnDU	 371	//( - , DU) Неисправность от
#define KKL1	 BUFFER[903]	//( - , - ) 
#define idKKL1	 372	//( - , - ) 
#define KKL2	 BUFFER[905]	//( - , - ) 
#define idKKL2	 373	//( - , - ) 
#define KKL3	 BUFFER[907]	//( - , - ) 
#define idKKL3	 374	//( - , - ) 
#define KKL4	 BUFFER[909]	//( - , - ) 
#define idKKL4	 375	//( - , - ) 
#define KKL5	 BUFFER[911]	//( - , - ) 
#define idKKL5	 376	//( - , - ) 
#define KKL6	 BUFFER[913]	//( - , - ) 
#define idKKL6	 377	//( - , - ) 
#define KKL7	 BUFFER[915]	//( - , - ) 
#define idKKL7	 378	//( - , - ) 
#define KKL8	 BUFFER[917]	//( - , - ) 
#define idKKL8	 379	//( - , - ) 
#define KKL9	 BUFFER[919]	//( - , - ) 
#define idKKL9	 380	//( - , - ) 
#define hz1	 BUFFER[921]	//( - , - ) 
#define idhz1	 381	//( - , - ) 
#define hz2	 BUFFER[923]	//( - , - ) 
#define idhz2	 382	//( - , - ) 
#define B6AB07LDU	 BUFFER[925]	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
#define idB6AB07LDU	 383	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
#define B6AB08LDU	 BUFFER[927]	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
#define idB6AB08LDU	 384	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
#define B6AB09LDU	 BUFFER[929]	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
#define idB6AB09LDU	 385	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
#define A6AB05LDU	 BUFFER[931]	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
#define idA6AB05LDU	 386	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
#define B8VS12LDU	 BUFFER[933]	//( - , DU) Движение АЗ2 в сторону ВУ
#define idB8VS12LDU	 387	//( - , DU) Движение АЗ2 в сторону ВУ
#define B8CV01RDU	 BUFFER[935]	//( - , DU) Измеренная скорость перемещения АЗ2
#define idB8CV01RDU	 388	//( - , DU) Измеренная скорость перемещения АЗ2
#define B8AB06LDU	 BUFFER[940]	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
#define idB8AB06LDU	 389	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
#define B8AB07LDU	 BUFFER[942]	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
#define idB8AB07LDU	 390	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
#define B8AB05LDU	 BUFFER[944]	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
#define idB8AB05LDU	 391	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
#define B8VS22LDU	 BUFFER[946]	//( - , DU) Движение АЗ2 в сторону НУ
#define idB8VS22LDU	 392	//( - , DU) Движение АЗ2 в сторону НУ
#define B8AZ03LDU	 BUFFER[948]	//( - , DU) Несанкционированное перемещение АЗ2
#define idB8AZ03LDU	 393	//( - , DU) Несанкционированное перемещение АЗ2
#define R0MD11LP1	 BUFFER[950]	//( - , DU) Кнопка ПУСК
#define idR0MD11LP1	 394	//( - , DU) Кнопка ПУСК
#define B8AD10LDU	 BUFFER[952]	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
#define idB8AD10LDU	 395	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
#define B8AD20LDU	 BUFFER[954]	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
#define idB8AD20LDU	 396	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
#define B8IS11LDU	 BUFFER[956]	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
#define idB8IS11LDU	 397	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
#define B8AB01LDU	 BUFFER[958]	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
#define idB8AB01LDU	 398	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
#define B8AB04LDU	 BUFFER[960]	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
#define idB8AB04LDU	 399	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
#define B8AB08LDU	 BUFFER[962]	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
#define idB8AB08LDU	 400	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
#define B8AB09LDU	 BUFFER[964]	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
#define idB8AB09LDU	 401	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
#define B8AB10LDU	 BUFFER[966]	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
#define idB8AB10LDU	 402	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
#define B8AB11LDU	 BUFFER[968]	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
#define idB8AB11LDU	 403	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
#define B8AB12LDU	 BUFFER[970]	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
#define idB8AB12LDU	 404	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
#define B8AB13LDU	 BUFFER[972]	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
#define idB8AB13LDU	 405	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
#define B5AB01LDU	 BUFFER[974]	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
#define idB5AB01LDU	 406	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
#define B5AB02LDU	 BUFFER[976]	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
#define idB5AB02LDU	 407	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
#define A4IS21LDU	 BUFFER[978]	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
#define idA4IS21LDU	 408	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
#define B4IS21LDU	 BUFFER[980]	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
#define idB4IS21LDU	 409	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
#define B4AD10LDU	 BUFFER[982]	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
#define idB4AD10LDU	 410	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
#define A4AD10LDU	 BUFFER[984]	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
#define idA4AD10LDU	 411	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
#define A4AZ03LDU	 BUFFER[986]	//( - , DU) Несанкционированное перемещение НИ1
#define idA4AZ03LDU	 412	//( - , DU) Несанкционированное перемещение НИ1
#define A4AB01LDU	 BUFFER[988]	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
#define idA4AB01LDU	 413	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
#define A4AB02LDU	 BUFFER[990]	//( - , DU) Блокировка движения НИ1 - Нет перемещения
#define idA4AB02LDU	 414	//( - , DU) Блокировка движения НИ1 - Нет перемещения
#define B4AZ03LDU	 BUFFER[992]	//( - , DU) Несанкционированное перемещение НИ2
#define idB4AZ03LDU	 415	//( - , DU) Несанкционированное перемещение НИ2
#define B4AB01LDU	 BUFFER[994]	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
#define idB4AB01LDU	 416	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
#define B4AB02LDU	 BUFFER[996]	//( - , DU) Блокировка движения НИ2 - Нет перемещения
#define idB4AB02LDU	 417	//( - , DU) Блокировка движения НИ2 - Нет перемещения
#define A5AB04LDU	 BUFFER[998]	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
#define idA5AB04LDU	 418	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
#define B5AB04LDU	 BUFFER[1000]	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
#define idB5AB04LDU	 419	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
#define A1IS12LDU	 BUFFER[1002]	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
#define idA1IS12LDU	 420	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
#define A2IS12LDU	 BUFFER[1004]	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
#define idA2IS12LDU	 421	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
#define B1IS12LDU	 BUFFER[1006]	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
#define idB1IS12LDU	 422	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
#define B2IS12LDU	 BUFFER[1008]	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
#define idB2IS12LDU	 423	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
#define R4IS11LDU	 BUFFER[1010]	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
#define idR4IS11LDU	 424	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
#define A6AB06LDU	 BUFFER[1012]	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
#define idA6AB06LDU	 425	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
#define A6AB07LDU	 BUFFER[1014]	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
#define idA6AB07LDU	 426	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
#define A6AB08LDU	 BUFFER[1016]	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
#define idA6AB08LDU	 427	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
#define A6AB09LDU	 BUFFER[1018]	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
#define idA6AB09LDU	 428	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
#define B6AB06LDU	 BUFFER[1020]	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
#define idB6AB06LDU	 429	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
#define A2VS11LDU	 BUFFER[1022]	//( - , DU) Движение РБ1 в сторону ВУ
#define idA2VS11LDU	 430	//( - , DU) Движение РБ1 в сторону ВУ
#define A2CV01RDU	 BUFFER[1024]	//( - , DU) Измеренная скорость перемещения РБ1
#define idA2CV01RDU	 431	//( - , DU) Измеренная скорость перемещения РБ1
#define A2AB04LDU	 BUFFER[1029]	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
#define idA2AB04LDU	 432	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
#define A2AB02LDU	 BUFFER[1031]	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
#define idA2AB02LDU	 433	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
#define A2AB01LDU	 BUFFER[1033]	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
#define idA2AB01LDU	 434	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
#define A2VS21LDU	 BUFFER[1035]	//( - , DU) Движение РБ1 в сторону НУ
#define idA2VS21LDU	 435	//( - , DU) Движение РБ1 в сторону НУ
#define A2AZ03LDU	 BUFFER[1037]	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
#define idA2AZ03LDU	 436	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
#define A2AD11LDU	 BUFFER[1039]	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	 437	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
#define A2AD21LDU	 BUFFER[1041]	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	 438	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
#define A2AD02LDU	 BUFFER[1043]	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
#define idA2AD02LDU	 439	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
#define A2AD03LDU	 BUFFER[1045]	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
#define idA2AD03LDU	 440	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
#define A2AD04LDU	 BUFFER[1047]	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
#define idA2AD04LDU	 441	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
#define A2AD05LDU	 BUFFER[1049]	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
#define idA2AD05LDU	 442	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
#define A2AB07LDU	 BUFFER[1051]	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
#define idA2AB07LDU	 443	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
#define A2AB08LDU	 BUFFER[1053]	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
#define idA2AB08LDU	 444	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
#define A2AB05LDU	 BUFFER[1055]	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
#define idA2AB05LDU	 445	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
#define A2AB06LDU	 BUFFER[1057]	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
#define idA2AB06LDU	 446	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
#define A2AB09LDU	 BUFFER[1059]	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
#define idA2AB09LDU	 447	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
#define A2AB10LDU	 BUFFER[1061]	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
#define idA2AB10LDU	 448	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
#define A2AB11LDU	 BUFFER[1063]	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
#define idA2AB11LDU	 449	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
#define A2AB12LDU	 BUFFER[1065]	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA2AB12LDU	 450	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A2AB13LDU	 BUFFER[1067]	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
#define idA2AB13LDU	 451	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
#define A2AB14LDU	 BUFFER[1069]	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
#define idA2AB14LDU	 452	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
#define A2AB16LDU	 BUFFER[1071]	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
#define idA2AB16LDU	 453	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
#define B8AB14LDU	 BUFFER[1073]	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
#define idB8AB14LDU	 454	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
#define B8AB02LDU	 BUFFER[1075]	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
#define idB8AB02LDU	 455	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
#define A8VS12LDU	 BUFFER[1077]	//( - , DU) Движение ДС2 в сторону ВУ
#define idA8VS12LDU	 456	//( - , DU) Движение ДС2 в сторону ВУ
#define A8CV01RDU	 BUFFER[1079]	//( - , DU) Измеренная скорость перемещения ДС2
#define idA8CV01RDU	 457	//( - , DU) Измеренная скорость перемещения ДС2
#define A8AB06LDU	 BUFFER[1084]	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
#define idA8AB06LDU	 458	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
#define A8AB07LDU	 BUFFER[1086]	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
#define idA8AB07LDU	 459	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
#define A8AB05LDU	 BUFFER[1088]	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
#define idA8AB05LDU	 460	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
#define A8VS22LDU	 BUFFER[1090]	//( - , DU) Движение ДС2 в сторону НУ
#define idA8VS22LDU	 461	//( - , DU) Движение ДС2 в сторону НУ
#define A8AZ03LDU	 BUFFER[1092]	//( - , DU) Несанкционированное перемещение ДС2
#define idA8AZ03LDU	 462	//( - , DU) Несанкционированное перемещение ДС2
#define A8AD10LDU	 BUFFER[1094]	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
#define idA8AD10LDU	 463	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
#define A8AD20LDU	 BUFFER[1096]	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
#define idA8AD20LDU	 464	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
#define B8IS22LDU	 BUFFER[1098]	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
#define idB8IS22LDU	 465	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
#define A8IS12LDU	 BUFFER[1100]	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
#define idA8IS12LDU	 466	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
#define A8AB04LDU	 BUFFER[1102]	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
#define idA8AB04LDU	 467	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
#define A8IS22LDU	 BUFFER[1104]	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
#define idA8IS22LDU	 468	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
#define A8AB08LDU	 BUFFER[1106]	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define idA8AB08LDU	 469	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define A8AB09LDU	 BUFFER[1108]	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
#define idA8AB09LDU	 470	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
#define A8AB10LDU	 BUFFER[1110]	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
#define idA8AB10LDU	 471	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
#define A8AB11LDU	 BUFFER[1112]	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
#define idA8AB11LDU	 472	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
#define A8AB12LDU	 BUFFER[1114]	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
#define idA8AB12LDU	 473	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
#define A8AB13LDU	 BUFFER[1116]	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
#define idA8AB13LDU	 474	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
#define A8AB14LDU	 BUFFER[1118]	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
#define idA8AB14LDU	 475	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
#define A8AB02LDU	 BUFFER[1120]	//( - , DU) Блокировка движения ДС2- АНИ не установлен
#define idA8AB02LDU	 476	//( - , DU) Блокировка движения ДС2- АНИ не установлен
#define A8AB01LDU	 BUFFER[1122]	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
#define idA8AB01LDU	 477	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
#define A6VS22LDU	 BUFFER[1124]	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
#define idA6VS22LDU	 478	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
#define A6VS12LDU	 BUFFER[1126]	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
#define idA6VS12LDU	 479	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
#define B6VS22LDU	 BUFFER[1128]	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
#define idB6VS22LDU	 480	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
#define B6VS12LDU	 BUFFER[1130]	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
#define idB6VS12LDU	 481	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
#define A6AD10LDU	 BUFFER[1132]	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
#define idA6AD10LDU	 482	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
#define A6AD20LDU	 BUFFER[1134]	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
#define idA6AD20LDU	 483	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
#define B6AD10LDU	 BUFFER[1136]	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
#define idB6AD10LDU	 484	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
#define B6AD20LDU	 BUFFER[1138]	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
#define idB6AD20LDU	 485	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
#define A6AZ03LDU	 BUFFER[1140]	//( - , DU) Несанкционированное перемещение БЗ1
#define idA6AZ03LDU	 486	//( - , DU) Несанкционированное перемещение БЗ1
#define A6AB01LDU	 BUFFER[1142]	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
#define idA6AB01LDU	 487	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
#define A6AB02LDU	 BUFFER[1144]	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
#define idA6AB02LDU	 488	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
#define B6AZ03LDU	 BUFFER[1146]	//( - , DU) Несанкционированное перемещение БЗ2
#define idB6AZ03LDU	 489	//( - , DU) Несанкционированное перемещение БЗ2
#define B6AB01LDU	 BUFFER[1148]	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
#define idB6AB01LDU	 490	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
#define B6AB02LDU	 BUFFER[1150]	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
#define idB6AB02LDU	 491	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
#define A6AB04LDU	 BUFFER[1152]	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
#define idA6AB04LDU	 492	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
#define B6AB04LDU	 BUFFER[1154]	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
#define idB6AB04LDU	 493	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
#define R4AB01LDU	 BUFFER[1156]	//( - , DU) Блокировка движения тележки - АНИ не установлен
#define idR4AB01LDU	 494	//( - , DU) Блокировка движения тележки - АНИ не установлен
#define R8IS11LDU	 BUFFER[1158]	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
#define idR8IS11LDU	 495	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
#define R6IS21LDU	 BUFFER[1160]	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
#define idR6IS21LDU	 496	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
#define A0VN71LZ2	 BUFFER[1162]	//( - , MDuBz2) АЗ по АС мощности для АЗ1
#define idA0VN71LZ2	 497	//( - , MDuBz2) АЗ по АС мощности для АЗ1
#define A0VN71LZ1	 BUFFER[1164]	//( - , MDuBz1) АЗ по АС мощности для АЗ1
#define idA0VN71LZ1	 498	//( - , MDuBz1) АЗ по АС мощности для АЗ1
#define R0NE01LDU	 BUFFER[1166]	//( - , DU) Потеря связи с БАЗ1
#define idR0NE01LDU	 499	//( - , DU) Потеря связи с БАЗ1
#define R0NE02LDU	 BUFFER[1168]	//( - , DU) Потеря связи с БАЗ2
#define idR0NE02LDU	 500	//( - , DU) Потеря связи с БАЗ2
#define R4AB02LDU	 BUFFER[1170]	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
#define idR4AB02LDU	 501	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
#define R0MW15IP1	 BUFFER[1172]	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
#define idR0MW15IP1	 502	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
#define R0MW14IP1	 BUFFER[1175]	//( - , DU) Переключатель ПРОГРАММЫ
#define idR0MW14IP1	 503	//( - , DU) Переключатель ПРОГРАММЫ
#define R0MW12IP1	 BUFFER[1178]	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
#define idR0MW12IP1	 504	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
#define R0MW13IP1	 BUFFER[1181]	//( - , DU) Переключатель ВЫБОР ЗОН
#define idR0MW13IP1	 505	//( - , DU) Переключатель ВЫБОР ЗОН
#define R0MW16IP1	 BUFFER[1184]	//( - , DU) Переключатель ВИД ПРОВЕРКИ
#define idR0MW16IP1	 506	//( - , DU) Переключатель ВИД ПРОВЕРКИ
#define R0MW11IP1	 BUFFER[1187]	//( - , DU) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	 507	//( - , DU) Переключатель ВЫСТРЕЛ
#define R0MW11IP2	 BUFFER[1190]	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
#define idR0MW11IP2	 508	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
#define R0MW13LP2	 BUFFER[1193]	//( - , DU) Переключатель СЕТЬ
#define idR0MW13LP2	 509	//( - , DU) Переключатель СЕТЬ
#define R0MD32LP1	 BUFFER[1195]	//( - , DU) Кнопка СПУСК
#define idR0MD32LP1	 510	//( - , DU) Кнопка СПУСК
#define R0MD31LP1	 BUFFER[1197]	//( - , DU) Кнопка СТОП
#define idR0MD31LP1	 511	//( - , DU) Кнопка СТОП
#define A1IS21LDU	 BUFFER[1199]	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
#define idA1IS21LDU	 512	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
#define A2IS21LDU	 BUFFER[1201]	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
#define idA2IS21LDU	 513	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
#define A3IS21LDU	 BUFFER[1203]	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
#define idA3IS21LDU	 514	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
#define B1IS21LDU	 BUFFER[1205]	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
#define idB1IS21LDU	 515	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
#define B2IS21LDU	 BUFFER[1207]	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
#define idB2IS21LDU	 516	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
#define B3IS21LDU	 BUFFER[1209]	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
#define idB3IS21LDU	 517	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
#define R0ES01LDU	 BUFFER[1211]	//( - , DU) ОРР не в исходном состоянии
#define idR0ES01LDU	 518	//( - , DU) ОРР не в исходном состоянии
#define R4MD11LP2	 BUFFER[1213]	//( - , DU) Кнопка ВПЕРЁД  (тележки)
#define idR4MD11LP2	 519	//( - , DU) Кнопка ВПЕРЁД  (тележки)
#define R4MD31LP2	 BUFFER[1215]	//( - , DU) Кнопка СТОП  (тележки)
#define idR4MD31LP2	 520	//( - , DU) Кнопка СТОП  (тележки)
#define R4MD21LP2	 BUFFER[1217]	//( - , DU) Кнопка НАЗАД  (тележки)
#define idR4MD21LP2	 521	//( - , DU) Кнопка НАЗАД  (тележки)
#define A6IS11LDU	 BUFFER[1219]	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
#define idA6IS11LDU	 522	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
#define A6IS21LDU	 BUFFER[1221]	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
#define idA6IS21LDU	 523	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
#define B6IS11LDU	 BUFFER[1223]	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
#define idB6IS11LDU	 524	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
#define B6IS21LDU	 BUFFER[1225]	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
#define idB6IS21LDU	 525	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
#define R4AB14LDU	 BUFFER[1227]	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
#define idR4AB14LDU	 526	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
#define R4AB15LDU	 BUFFER[1229]	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
#define idR4AB15LDU	 527	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
#define R5IS11LDU	 BUFFER[1231]	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	 528	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
#define R4AB16LDU	 BUFFER[1233]	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
#define idR4AB16LDU	 529	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
#define R4AB17LDU	 BUFFER[1235]	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define idR4AB17LDU	 530	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define R4AB18LDU	 BUFFER[1237]	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define idR4AB18LDU	 531	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define R4AD10LDU	 BUFFER[1239]	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
#define idR4AD10LDU	 532	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
#define R4AD20LDU	 BUFFER[1241]	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
#define idR4AD20LDU	 533	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
#define A5VS22LDU	 BUFFER[1243]	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
#define idA5VS22LDU	 534	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
#define A5VS12LDU	 BUFFER[1245]	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
#define idA5VS12LDU	 535	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
#define B5VS22LDU	 BUFFER[1247]	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
#define idB5VS22LDU	 536	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
#define B5VS12LDU	 BUFFER[1249]	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
#define idB5VS12LDU	 537	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
#define B5AD10LDU	 BUFFER[1251]	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
#define idB5AD10LDU	 538	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
#define B5AD20LDU	 BUFFER[1253]	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
#define idB5AD20LDU	 539	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
#define A5AD10LDU	 BUFFER[1255]	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
#define idA5AD10LDU	 540	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
#define A5AD20LDU	 BUFFER[1257]	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
#define idA5AD20LDU	 541	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
#define A5IS11LDU	 BUFFER[1259]	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
#define idA5IS11LDU	 542	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
#define A5IS21LDU	 BUFFER[1261]	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
#define idA5IS21LDU	 543	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
#define B5IS11LDU	 BUFFER[1263]	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
#define idB5IS11LDU	 544	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
#define B5IS21LDU	 BUFFER[1265]	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
#define idB5IS21LDU	 545	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
#define A5AZ03LDU	 BUFFER[1267]	//( - , DU) Несанкционированное перемещение НЛ1
#define idA5AZ03LDU	 546	//( - , DU) Несанкционированное перемещение НЛ1
#define A5AB01LDU	 BUFFER[1269]	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
#define idA5AB01LDU	 547	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
#define A5AB02LDU	 BUFFER[1271]	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
#define idA5AB02LDU	 548	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
#define B5AZ03LDU	 BUFFER[1273]	//( - , DU) Несанкционированное перемещение НЛ2
#define idB5AZ03LDU	 549	//( - , DU) Несанкционированное перемещение НЛ2
#define R0NE08LDU	 BUFFER[1275]	//( - , DU) Потеря связи с ОПУ
#define idR0NE08LDU	 550	//( - , DU) Потеря связи с ОПУ
#define R4IS21LDU	 BUFFER[1277]	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
#define idR4IS21LDU	 551	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
#define R4IS22LDU	 BUFFER[1279]	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
#define idR4IS22LDU	 552	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
#define R4IS12LDU	 BUFFER[1281]	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
#define idR4IS12LDU	 553	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
#define R4VS22LDU	 BUFFER[1283]	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
#define idR4VS22LDU	 554	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
#define R4VS12LDU	 BUFFER[1285]	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
#define idR4VS12LDU	 555	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
#define R4AZ03LDU	 BUFFER[1287]	//( - , DU) Несанкционированное перемещение тележки
#define idR4AZ03LDU	 556	//( - , DU) Несанкционированное перемещение тележки
#define R4AB03LDU	 BUFFER[1289]	//( - , DU) Блокировка движения тележки - Самоход любого механизма
#define idR4AB03LDU	 557	//( - , DU) Блокировка движения тележки - Самоход любого механизма
#define R1IS21LDU	 BUFFER[1291]	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
#define idR1IS21LDU	 558	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
#define R2IS21LDU	 BUFFER[1293]	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
#define idR2IS21LDU	 559	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
#define R4AB04LDU	 BUFFER[1295]	//( - , DU) Блокировка движения тележки - Превышение времени движения
#define idR4AB04LDU	 560	//( - , DU) Блокировка движения тележки - Превышение времени движения
#define R4AB05LDU	 BUFFER[1297]	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
#define idR4AB05LDU	 561	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
#define R4AB06LDU	 BUFFER[1299]	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
#define idR4AB06LDU	 562	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
#define R4AB07LDU	 BUFFER[1301]	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
#define idR4AB07LDU	 563	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
#define R4AB08LDU	 BUFFER[1303]	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define idR4AB08LDU	 564	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define R4AB09LDU	 BUFFER[1305]	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
#define idR4AB09LDU	 565	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
#define B0VN71LZ1	 BUFFER[1307]	//( - , MDuBz1) АЗ по АС мощности для АЗ2
#define idB0VN71LZ1	 566	//( - , MDuBz1) АЗ по АС мощности для АЗ2
#define B0VN71LZ2	 BUFFER[1309]	//( - , MDuBz2) АЗ по АС мощности для АЗ2
#define idB0VN71LZ2	 567	//( - , MDuBz2) АЗ по АС мощности для АЗ2
#define R4AB10LDU	 BUFFER[1311]	//( - , DU) Блокировка тележки - не открыта биологическая защита
#define idR4AB10LDU	 568	//( - , DU) Блокировка тележки - не открыта биологическая защита
#define R4AB11LDU	 BUFFER[1313]	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
#define idR4AB11LDU	 569	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
#define R4AB12LDU	 BUFFER[1315]	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
#define idR4AB12LDU	 570	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
#define A4IS11LDU	 BUFFER[1317]	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
#define idA4IS11LDU	 571	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
#define B4IS11LDU	 BUFFER[1319]	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
#define idB4IS11LDU	 572	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
#define R4AB13LDU	 BUFFER[1321]	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
#define idR4AB13LDU	 573	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
#define A3AB10LDU	 BUFFER[1323]	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
#define idA3AB10LDU	 574	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
#define A3AB11LDU	 BUFFER[1325]	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
#define idA3AB11LDU	 575	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
#define A3AB12LDU	 BUFFER[1327]	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA3AB12LDU	 576	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A3AB14LDU	 BUFFER[1329]	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
#define idA3AB14LDU	 577	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
#define A3AB16LDU	 BUFFER[1331]	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
#define idA3AB16LDU	 578	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
#define A3AB17LDU	 BUFFER[1333]	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
#define idA3AB17LDU	 579	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
#define A3AB18LDU	 BUFFER[1335]	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
#define idA3AB18LDU	 580	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
#define A3AB20LDU	 BUFFER[1337]	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
#define idA3AB20LDU	 581	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
#define B3VS12LDU	 BUFFER[1339]	//( - , DU) Движение ИС2 в сторону ВУ
#define idB3VS12LDU	 582	//( - , DU) Движение ИС2 в сторону ВУ
#define B3CV01RDU	 BUFFER[1341]	//( - , DU) Измеренная скорость перемещения ИС2
#define idB3CV01RDU	 583	//( - , DU) Измеренная скорость перемещения ИС2
#define B3AB04LDU	 BUFFER[1346]	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
#define idB3AB04LDU	 584	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
#define B3AB02LDU	 BUFFER[1348]	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
#define idB3AB02LDU	 585	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
#define B3AB01LDU	 BUFFER[1350]	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
#define idB3AB01LDU	 586	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
#define B3VS22LDU	 BUFFER[1352]	//( - , DU) Движение ИС2 в сторону НУ
#define idB3VS22LDU	 587	//( - , DU) Движение ИС2 в сторону НУ
#define B3AZ03LDU	 BUFFER[1354]	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
#define idB3AZ03LDU	 588	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
#define B3AD11LDU	 BUFFER[1356]	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	 589	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
#define B3AD21LDU	 BUFFER[1358]	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	 590	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
#define B3AD02LDU	 BUFFER[1360]	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
#define idB3AD02LDU	 591	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
#define B3AD03LDU	 BUFFER[1362]	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
#define idB3AD03LDU	 592	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
#define B3AD04LDU	 BUFFER[1364]	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
#define idB3AD04LDU	 593	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
#define B3AD05LDU	 BUFFER[1366]	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
#define idB3AD05LDU	 594	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
#define B3AD01LDU	 BUFFER[1368]	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
#define idB3AD01LDU	 595	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
#define B3CV02RDU	 BUFFER[1370]	//( - , DU) Заданная скорость перемещения ИС2
#define idB3CV02RDU	 596	//( - , DU) Заданная скорость перемещения ИС2
#define B3AB07LDU	 BUFFER[1375]	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
#define idB3AB07LDU	 597	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
#define B1AB14LDU	 BUFFER[1377]	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
#define idB1AB14LDU	 598	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
#define B1AB16LDU	 BUFFER[1379]	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
#define idB1AB16LDU	 599	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
#define B1AB17LDU	 BUFFER[1381]	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
#define idB1AB17LDU	 600	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
#define B1AB18LDU	 BUFFER[1383]	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
#define idB1AB18LDU	 601	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
#define A3VS12LDU	 BUFFER[1385]	//( - , DU) Движение ИС1 в сторону ВУ
#define idA3VS12LDU	 602	//( - , DU) Движение ИС1 в сторону ВУ
#define A3CV01RDU	 BUFFER[1387]	//( - , DU) Измеренная скорость перемещения ИС1
#define idA3CV01RDU	 603	//( - , DU) Измеренная скорость перемещения ИС1
#define A3AB04LDU	 BUFFER[1392]	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
#define idA3AB04LDU	 604	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
#define A3AB02LDU	 BUFFER[1394]	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
#define idA3AB02LDU	 605	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
#define A3AB01LDU	 BUFFER[1396]	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
#define idA3AB01LDU	 606	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
#define A3VS22LDU	 BUFFER[1398]	//( - , DU) Движение ИС1 в сторону НУ
#define idA3VS22LDU	 607	//( - , DU) Движение ИС1 в сторону НУ
#define A3AZ03LDU	 BUFFER[1400]	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
#define idA3AZ03LDU	 608	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
#define A3AD11LDU	 BUFFER[1402]	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	 609	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
#define A3AD21LDU	 BUFFER[1404]	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	 610	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
#define A3AD02LDU	 BUFFER[1406]	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
#define idA3AD02LDU	 611	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
#define A3AD03LDU	 BUFFER[1408]	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
#define idA3AD03LDU	 612	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
#define A3AD04LDU	 BUFFER[1410]	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
#define idA3AD04LDU	 613	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
#define A3AD05LDU	 BUFFER[1412]	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
#define idA3AD05LDU	 614	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
#define A3AD01LDU	 BUFFER[1414]	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
#define idA3AD01LDU	 615	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
#define A3CV02RDU	 BUFFER[1416]	//( - , DU) Заданная скорость перемещения ИС1
#define idA3CV02RDU	 616	//( - , DU) Заданная скорость перемещения ИС1
#define A3AB07LDU	 BUFFER[1421]	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
#define idA3AB07LDU	 617	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
#define A3AB08LDU	 BUFFER[1423]	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
#define idA3AB08LDU	 618	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
#define A3AB05LDU	 BUFFER[1425]	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
#define idA3AB05LDU	 619	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
#define A3AB06LDU	 BUFFER[1427]	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
#define idA3AB06LDU	 620	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
#define A3AB09LDU	 BUFFER[1429]	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
#define idA3AB09LDU	 621	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
#define R0VL01IDU	 BUFFER[1431]	//( - , DU) До импульса минут
#define idR0VL01IDU	 622	//( - , DU) До импульса минут
#define R0VL11IDU	 BUFFER[1434]	//( - , DU) До импульса секунд
#define idR0VL11IDU	 623	//( - , DU) До импульса секунд
#define R0VL06RDU	 BUFFER[1437]	//( - , DU) Индикация (Время задержки от ВУ РБ)
#define idR0VL06RDU	 624	//( - , DU) Индикация (Время задержки от ВУ РБ)
#define B3AD33LDU	 BUFFER[1442]	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 закрыть (обесточить)
#define idB3AD33LDU	 625	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 закрыть (обесточить)
#define B3IS11LDU	 BUFFER[1444]	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
#define idB3IS11LDU	 626	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
#define R0VL02RDU	 BUFFER[1446]	//( - , DU) Индикация (Время задержки ИНИ)
#define idR0VL02RDU	 627	//( - , DU) Индикация (Время задержки ИНИ)
#define R8AD21LDU	 BUFFER[1451]	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
#define idR8AD21LDU	 628	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
#define R0AD14LDU	 BUFFER[1453]	//( - , DU) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 629	//( - , DU) Имитация срабатывания верхней АС II УР
#define R0VL04RDU	 BUFFER[1455]	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
#define idR0VL04RDU	 630	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
#define R0AB04LDU	 BUFFER[1460]	//( - , DU) Нарушение времени срабатывания верхней АС II УР
#define idR0AB04LDU	 631	//( - , DU) Нарушение времени срабатывания верхней АС II УР
#define R0AB06LDU	 BUFFER[1462]	//( - , DU) Нарушение времени задержки от ВУ РБ
#define idR0AB06LDU	 632	//( - , DU) Нарушение времени задержки от ВУ РБ
#define R0AB02LDU	 BUFFER[1464]	//( - , DU) Нарушение времени задержки ИНИ
#define idR0AB02LDU	 633	//( - , DU) Нарушение времени задержки ИНИ
#define R0VL03RDU	 BUFFER[1466]	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define idR0VL03RDU	 634	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define R0VL05RDU	 BUFFER[1471]	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
#define idR0VL05RDU	 635	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
#define R0VL21IDU	 BUFFER[1476]	//( - , DU) Декатрон
#define idR0VL21IDU	 636	//( - , DU) Декатрон
#define R0VX03LDU	 BUFFER[1479]	//( - , DU) Готовность 2 мин
#define idR0VX03LDU	 637	//( - , DU) Готовность 2 мин
#define R0VS21IDU	 BUFFER[1481]	//( - , DU) Индикация ВИД ПРОВЕРКИ
#define idR0VS21IDU	 638	//( - , DU) Индикация ВИД ПРОВЕРКИ
#define A1VS01IDU	 BUFFER[1484]	//( - , DU) Готовность к управлению ББ1
#define idA1VS01IDU	 639	//( - , DU) Готовность к управлению ББ1
#define B1VS01IDU	 BUFFER[1487]	//( - , DU) Готовность к управлению ББ2
#define idB1VS01IDU	 640	//( - , DU) Готовность к управлению ББ2
#define A3VS01IDU	 BUFFER[1490]	//( - , DU) Готовность к управлению ИС1
#define idA3VS01IDU	 641	//( - , DU) Готовность к управлению ИС1
#define B3VS01IDU	 BUFFER[1493]	//( - , DU) Готовность к управлению ИС2
#define idB3VS01IDU	 642	//( - , DU) Готовность к управлению ИС2
#define A2VS01IDU	 BUFFER[1496]	//( - , DU) Готовность к управлению РБ1
#define idA2VS01IDU	 643	//( - , DU) Готовность к управлению РБ1
#define A4VS01IDU	 BUFFER[1499]	//( - , DU) Готовность к управлению НИ1
#define idA4VS01IDU	 644	//( - , DU) Готовность к управлению НИ1
#define A4VS12LDU	 BUFFER[1502]	//( - , DU) Движение НИ1 в сторону ВУ
#define idA4VS12LDU	 645	//( - , DU) Движение НИ1 в сторону ВУ
#define B3AB08LDU	 BUFFER[1504]	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
#define idB3AB08LDU	 646	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
#define B3AB05LDU	 BUFFER[1506]	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
#define idB3AB05LDU	 647	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
#define B3AB06LDU	 BUFFER[1508]	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
#define idB3AB06LDU	 648	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
#define B3AB09LDU	 BUFFER[1510]	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
#define idB3AB09LDU	 649	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
#define B3AB10LDU	 BUFFER[1512]	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
#define idB3AB10LDU	 650	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
#define B3AB11LDU	 BUFFER[1514]	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
#define idB3AB11LDU	 651	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
#define B3AB12LDU	 BUFFER[1516]	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define idB3AB12LDU	 652	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define B3AB14LDU	 BUFFER[1518]	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
#define idB3AB14LDU	 653	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
#define B3AB16LDU	 BUFFER[1520]	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
#define idB3AB16LDU	 654	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
#define B3AB17LDU	 BUFFER[1522]	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
#define idB3AB17LDU	 655	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
#define B3AB18LDU	 BUFFER[1524]	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
#define idB3AB18LDU	 656	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
#define B3AB20LDU	 BUFFER[1526]	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
#define idB3AB20LDU	 657	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
#define C1MD31LP1	 BUFFER[1528]	//( - , DU) Кнопка СБРОС ББ
#define idC1MD31LP1	 658	//( - , DU) Кнопка СБРОС ББ
#define C1MD31LP2	 BUFFER[1530]	//( - , DU) Кнопка СБРОС ББ
#define idC1MD31LP2	 659	//( - , DU) Кнопка СБРОС ББ
#define A2AD31LDU	 BUFFER[1532]	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
#define idA2AD31LDU	 660	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
#define B2AD31LDU	 BUFFER[1534]	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
#define idB2AD31LDU	 661	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
#define A1AD31LDU	 BUFFER[1536]	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
#define idA1AD31LDU	 662	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
#define B1AD31LDU	 BUFFER[1538]	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
#define idB1AD31LDU	 663	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
#define A2AD32LDU	 BUFFER[1540]	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
#define idA2AD32LDU	 664	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
#define B2AD32LDU	 BUFFER[1542]	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
#define idB2AD32LDU	 665	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
#define A1AD32LDU	 BUFFER[1544]	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
#define idA1AD32LDU	 666	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
#define B1AD32LDU	 BUFFER[1546]	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
#define idB1AD32LDU	 667	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
#define R0MD11LP2	 BUFFER[1548]	//( - , DU) Кнопка Пуск проверки схем сброса
#define idR0MD11LP2	 668	//( - , DU) Кнопка Пуск проверки схем сброса
#define R0VX01LDU	 BUFFER[1550]	//( - , DU) ДО ИМПУЛЬСА
#define idR0VX01LDU	 669	//( - , DU) ДО ИМПУЛЬСА
#define B2AB13LDU	 BUFFER[1552]	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
#define idB2AB13LDU	 670	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
#define B2AB14LDU	 BUFFER[1554]	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
#define idB2AB14LDU	 671	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
#define B2AB16LDU	 BUFFER[1556]	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
#define idB2AB16LDU	 672	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
#define B2AB17LDU	 BUFFER[1558]	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
#define idB2AB17LDU	 673	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
#define R1AZ03LDU	 BUFFER[1560]	//( - , DU) Несанкционированное перемещение МДЗ1
#define idR1AZ03LDU	 674	//( - , DU) Несанкционированное перемещение МДЗ1
#define R1AB01LDU	 BUFFER[1562]	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
#define idR1AB01LDU	 675	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
#define R1AB02LDU	 BUFFER[1564]	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
#define idR1AB02LDU	 676	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
#define R2AZ03LDU	 BUFFER[1566]	//( - , DU) Несанкционированное перемещение МДЗ2
#define idR2AZ03LDU	 677	//( - , DU) Несанкционированное перемещение МДЗ2
#define R2AB01LDU	 BUFFER[1568]	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
#define idR2AB01LDU	 678	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
#define R2AB02LDU	 BUFFER[1570]	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
#define idR2AB02LDU	 679	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
#define R1AB04LDU	 BUFFER[1572]	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
#define idR1AB04LDU	 680	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
#define R2AB04LDU	 BUFFER[1574]	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
#define idR2AB04LDU	 681	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
#define R1AD10LDU	 BUFFER[1576]	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
#define idR1AD10LDU	 682	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
#define R1AD20LDU	 BUFFER[1578]	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
#define idR1AD20LDU	 683	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
#define R1IS11LDU	 BUFFER[1580]	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
#define idR1IS11LDU	 684	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
#define R1VS22LDU	 BUFFER[1582]	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	 685	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
#define R2VS22LDU	 BUFFER[1584]	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	 686	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
#define R2VS12LDU	 BUFFER[1586]	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	 687	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
#define R1VS12LDU	 BUFFER[1588]	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	 688	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
#define R2IS11LDU	 BUFFER[1590]	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
#define idR2IS11LDU	 689	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
#define A1VS12LDU	 BUFFER[1592]	//( - , DU) Движение ББ1 в сторону ВУ
#define idA1VS12LDU	 690	//( - , DU) Движение ББ1 в сторону ВУ
#define A1CV01RDU	 BUFFER[1594]	//( - , DU) Измеренная скорость перемещения ББ1
#define idA1CV01RDU	 691	//( - , DU) Измеренная скорость перемещения ББ1
#define A1AB04LDU	 BUFFER[1599]	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
#define idA1AB04LDU	 692	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
#define A1AB02LDU	 BUFFER[1601]	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
#define idA1AB02LDU	 693	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
#define A2AB17LDU	 BUFFER[1603]	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
#define idA2AB17LDU	 694	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
#define A2AD01LDU	 BUFFER[1605]	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
#define idA2AD01LDU	 695	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
#define A2CV02RDU	 BUFFER[1607]	//( - , DU) Заданная скорость перемещения РБ1
#define idA2CV02RDU	 696	//( - , DU) Заданная скорость перемещения РБ1
#define B2CV01RDU	 BUFFER[1612]	//( - , DU) Измеренная скорость перемещения РБ2
#define idB2CV01RDU	 697	//( - , DU) Измеренная скорость перемещения РБ2
#define B2AB04LDU	 BUFFER[1617]	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
#define idB2AB04LDU	 698	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
#define B2AB02LDU	 BUFFER[1619]	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
#define idB2AB02LDU	 699	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
#define B2AB01LDU	 BUFFER[1621]	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
#define idB2AB01LDU	 700	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
#define B2AZ03LDU	 BUFFER[1623]	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
#define idB2AZ03LDU	 701	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
#define B2AD11LDU	 BUFFER[1625]	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	 702	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
#define B2AD21LDU	 BUFFER[1627]	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	 703	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
#define B2AD02LDU	 BUFFER[1629]	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
#define idB2AD02LDU	 704	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
#define B2AD03LDU	 BUFFER[1631]	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
#define idB2AD03LDU	 705	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
#define B2AD04LDU	 BUFFER[1633]	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
#define idB2AD04LDU	 706	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
#define B2AD05LDU	 BUFFER[1635]	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
#define idB2AD05LDU	 707	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
#define B2AD01LDU	 BUFFER[1637]	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
#define idB2AD01LDU	 708	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
#define B2CV02RDU	 BUFFER[1639]	//( - , DU) Заданная скорость перемещения РБ2
#define idB2CV02RDU	 709	//( - , DU) Заданная скорость перемещения РБ2
#define B2AB07LDU	 BUFFER[1644]	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
#define idB2AB07LDU	 710	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
#define B2AB08LDU	 BUFFER[1646]	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
#define idB2AB08LDU	 711	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
#define B2AB05LDU	 BUFFER[1648]	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
#define idB2AB05LDU	 712	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
#define B2AB06LDU	 BUFFER[1650]	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
#define idB2AB06LDU	 713	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
#define B2AB09LDU	 BUFFER[1652]	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
#define idB2AB09LDU	 714	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
#define B2AB10LDU	 BUFFER[1654]	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
#define idB2AB10LDU	 715	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
#define B2AB11LDU	 BUFFER[1656]	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
#define idB2AB11LDU	 716	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
#define B2AB12LDU	 BUFFER[1658]	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define idB2AB12LDU	 717	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define B1VS12LDU	 BUFFER[1660]	//( - , DU) Движение ББ2 в сторону ВУ
#define idB1VS12LDU	 718	//( - , DU) Движение ББ2 в сторону ВУ
#define B1CV01RDU	 BUFFER[1662]	//( - , DU) Измеренная скорость перемещения ББ2
#define idB1CV01RDU	 719	//( - , DU) Измеренная скорость перемещения ББ2
#define B1AB04LDU	 BUFFER[1667]	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
#define idB1AB04LDU	 720	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
#define B1AB02LDU	 BUFFER[1669]	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
#define idB1AB02LDU	 721	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
#define B1AB01LDU	 BUFFER[1671]	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
#define idB1AB01LDU	 722	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
#define B1VS22LDU	 BUFFER[1673]	//( - , DU) Движение ББ2 в сторону НУ
#define idB1VS22LDU	 723	//( - , DU) Движение ББ2 в сторону НУ
#define B1AZ03LDU	 BUFFER[1675]	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
#define idB1AZ03LDU	 724	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
#define B1AD11LDU	 BUFFER[1677]	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	 725	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
#define B1AD21LDU	 BUFFER[1679]	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	 726	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
#define B1AD02LDU	 BUFFER[1681]	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
#define idB1AD02LDU	 727	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
#define B1AD03LDU	 BUFFER[1683]	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
#define idB1AD03LDU	 728	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
#define B1AD04LDU	 BUFFER[1685]	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
#define idB1AD04LDU	 729	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
#define B1AD05LDU	 BUFFER[1687]	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
#define idB1AD05LDU	 730	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
#define B1AD01LDU	 BUFFER[1689]	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
#define idB1AD01LDU	 731	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
#define B1CV02RDU	 BUFFER[1691]	//( - , DU) Заданная скорость перемещения ББ2
#define idB1CV02RDU	 732	//( - , DU) Заданная скорость перемещения ББ2
#define B1AB07LDU	 BUFFER[1696]	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
#define idB1AB07LDU	 733	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
#define B1AB08LDU	 BUFFER[1698]	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
#define idB1AB08LDU	 734	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
#define B1AB05LDU	 BUFFER[1700]	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
#define idB1AB05LDU	 735	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
#define B1AB06LDU	 BUFFER[1702]	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
#define idB1AB06LDU	 736	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
#define B1AB09LDU	 BUFFER[1704]	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
#define idB1AB09LDU	 737	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
#define B1AB10LDU	 BUFFER[1706]	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
#define idB1AB10LDU	 738	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
#define B1AB11LDU	 BUFFER[1708]	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
#define idB1AB11LDU	 739	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
#define B1AB12LDU	 BUFFER[1710]	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idB1AB12LDU	 740	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define B1AB13LDU	 BUFFER[1712]	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
#define idB1AB13LDU	 741	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
#define A1AB01LDU	 BUFFER[1714]	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
#define idA1AB01LDU	 742	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
#define A1VS22LDU	 BUFFER[1716]	//( - , DU) Движение ББ1 в сторону НУ
#define idA1VS22LDU	 743	//( - , DU) Движение ББ1 в сторону НУ
#define A1AZ03LDU	 BUFFER[1718]	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
#define idA1AZ03LDU	 744	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
#define A1AD11LDU	 BUFFER[1720]	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	 745	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
#define A1AD21LDU	 BUFFER[1722]	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	 746	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
#define A1AD02LDU	 BUFFER[1724]	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
#define idA1AD02LDU	 747	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
#define A1AD03LDU	 BUFFER[1726]	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
#define idA1AD03LDU	 748	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
#define A1AD04LDU	 BUFFER[1728]	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
#define idA1AD04LDU	 749	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
#define A1AD05LDU	 BUFFER[1730]	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
#define idA1AD05LDU	 750	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
#define A1AD01LDU	 BUFFER[1732]	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
#define idA1AD01LDU	 751	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
#define A1CV02RDU	 BUFFER[1734]	//( - , DU) Заданная скорость перемещения ББ1
#define idA1CV02RDU	 752	//( - , DU) Заданная скорость перемещения ББ1
#define A1AB07LDU	 BUFFER[1739]	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
#define idA1AB07LDU	 753	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
#define A1AB08LDU	 BUFFER[1741]	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
#define idA1AB08LDU	 754	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
#define A1AB05LDU	 BUFFER[1743]	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
#define idA1AB05LDU	 755	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
#define A1AB06LDU	 BUFFER[1745]	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
#define idA1AB06LDU	 756	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
#define A1AB09LDU	 BUFFER[1747]	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
#define idA1AB09LDU	 757	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
#define A1AB10LDU	 BUFFER[1749]	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
#define idA1AB10LDU	 758	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
#define A1AB11LDU	 BUFFER[1751]	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
#define idA1AB11LDU	 759	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
#define A1AB12LDU	 BUFFER[1753]	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA1AB12LDU	 760	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A1AB13LDU	 BUFFER[1755]	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
#define idA1AB13LDU	 761	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
#define A1AB14LDU	 BUFFER[1757]	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
#define idA1AB14LDU	 762	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
#define A1AB16LDU	 BUFFER[1759]	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
#define idA1AB16LDU	 763	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
#define A1AB17LDU	 BUFFER[1761]	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
#define idA1AB17LDU	 764	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
#define A1AB18LDU	 BUFFER[1763]	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
#define idA1AB18LDU	 765	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
#define fEM_A1UC03RDU	 BUFFER[1765]	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define idfEM_A1UC03RDU	 766	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define dEM_A1UC05UDU	 BUFFER[1770]	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC05UDU	 767	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define dEM_A1UC06UDU	 BUFFER[1775]	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC06UDU	 768	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define dEM_A2UC06UDU	 BUFFER[1780]	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC06UDU	 769	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define dEM_A2UC05UDU	 BUFFER[1785]	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC05UDU	 770	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define fEM_A2UC03RDU	 BUFFER[1790]	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define idfEM_A2UC03RDU	 771	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define dEM_A3UC06UDU	 BUFFER[1795]	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC06UDU	 772	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define dEM_A3UC05UDU	 BUFFER[1800]	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC05UDU	 773	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define fEM_A3UC03RDU	 BUFFER[1805]	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define idfEM_A3UC03RDU	 774	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define dEM_A8UC06UDU	 BUFFER[1810]	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define iddEM_A8UC06UDU	 775	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define fEM_A8UC03RDU	 BUFFER[1815]	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
#define idfEM_A8UC03RDU	 776	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
#define dEM_A8UC05UDU	 BUFFER[1820]	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define iddEM_A8UC05UDU	 777	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define fEM_R0UV81RDU	 BUFFER[1825]	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	 778	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	 BUFFER[1830]	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	 779	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	 BUFFER[1835]	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	 780	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	 BUFFER[1840]	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	 781	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define fEM_R0UV86RDU	 BUFFER[1845]	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	 782	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV85RDU	 BUFFER[1850]	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	 783	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV87RDU	 BUFFER[1855]	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	 784	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_A3UP03RDU	 BUFFER[1860]	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	 785	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	 BUFFER[1865]	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	 786	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP43RDU	 BUFFER[1870]	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define idfEM_A3UP43RDU	 787	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define fEM_A3UP44RDU	 BUFFER[1875]	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP44RDU	 788	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP53RDU	 BUFFER[1880]	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP53RDU	 789	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP85RDU	 BUFFER[1885]	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP85RDU	 790	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP88RDU	 BUFFER[1890]	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP88RDU	 791	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP86RDU	 BUFFER[1895]	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP86RDU	 792	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_B8UV01RDU	 BUFFER[1900]	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
#define idfEM_B8UV01RDU	 793	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
#define fEM_B8UV02RDU	 BUFFER[1905]	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
#define idfEM_B8UV02RDU	 794	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
#define fEM_B8UV03RDU	 BUFFER[1910]	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
#define idfEM_B8UV03RDU	 795	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
#define fEM_B8UL04RDU	 BUFFER[1915]	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
#define idfEM_B8UL04RDU	 796	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
#define iEM_A2UV03CDU	 BUFFER[1920]	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define idiEM_A2UV03CDU	 797	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define fEM_A2UV01RDU	 BUFFER[1923]	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define idfEM_A2UV01RDU	 798	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define fEM_A2UV02RDU	 BUFFER[1928]	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define idfEM_A2UV02RDU	 799	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define fEM_A1UV01RDU	 BUFFER[1933]	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define idfEM_A1UV01RDU	 800	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define fEM_A1UV02RDU	 BUFFER[1938]	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define idfEM_A1UV02RDU	 801	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define fEM_A1UC06RDU	 BUFFER[1943]	//(A1UC06RDU) Уставка определения самохода ББ  мм
#define idfEM_A1UC06RDU	 802	//(A1UC06RDU) Уставка определения самохода ББ  мм
#define fEM_A1UC05RDU	 BUFFER[1948]	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A1UC05RDU	 803	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A1UL04RDU	 BUFFER[1953]	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define idfEM_A1UL04RDU	 804	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define fEM_A3UV01RDU	 BUFFER[1958]	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
#define idfEM_A3UV01RDU	 805	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
#define fEM_A3UV02RDU	 BUFFER[1963]	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
#define idfEM_A3UV02RDU	 806	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
#define fEM_A3UC06RDU	 BUFFER[1968]	//(A3UC06RDU) Уставка определения самохода ИС1  мм
#define idfEM_A3UC06RDU	 807	//(A3UC06RDU) Уставка определения самохода ИС1  мм
#define fEM_A3UC05RDU	 BUFFER[1973]	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A3UC05RDU	 808	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define fEM_A3UL04RDU	 BUFFER[1978]	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define idfEM_A3UL04RDU	 809	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define fEM_A3UP54RDU	 BUFFER[1983]	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define idfEM_A3UP54RDU	 810	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define fEM_A3UP87RDU	 BUFFER[1988]	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP87RDU	 811	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_R0UL05RDU	 BUFFER[1993]	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
#define idfEM_R0UL05RDU	 812	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
#define fEM_R0UL20RDU	 BUFFER[1998]	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
#define idfEM_R0UL20RDU	 813	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
#define fEM_B8UV04RDU	 BUFFER[2003]	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
#define idfEM_B8UV04RDU	 814	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
#define fEM_B8UC06RDU	 BUFFER[2008]	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
#define idfEM_B8UC06RDU	 815	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
#define fEM_B8UC05RDU	 BUFFER[2013]	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
#define idfEM_B8UC05RDU	 816	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
#define fEM_A2UL05RDU	 BUFFER[2018]	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define idfEM_A2UL05RDU	 817	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define fEM_A2UL03RDU	 BUFFER[2023]	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL03RDU	 818	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A2UC06RDU	 BUFFER[2028]	//(A2UC06RDU) Уставка определения самохода РБ  мм
#define idfEM_A2UC06RDU	 819	//(A2UC06RDU) Уставка определения самохода РБ  мм
#define fEM_A2UC05RDU	 BUFFER[2033]	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A2UC05RDU	 820	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A2UL04RDU	 BUFFER[2038]	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define idfEM_A2UL04RDU	 821	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define fEM_A1UL03RDU	 BUFFER[2043]	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define idfEM_A1UL03RDU	 822	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define fEM_A1UL05RDU	 BUFFER[2048]	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define idfEM_A1UL05RDU	 823	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define fEM_A3UL03RDU	 BUFFER[2053]	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define idfEM_A3UL03RDU	 824	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define fEM_A3UL05RDU	 BUFFER[2058]	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define idfEM_A3UL05RDU	 825	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define fEM_A1UC08RDU	 BUFFER[2063]	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define idfEM_A1UC08RDU	 826	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define fEM_A3UC08RDU	 BUFFER[2068]	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define idfEM_A3UC08RDU	 827	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define fEM_A1UC07RDU	 BUFFER[2073]	//(A1UC07RDU) Зона возврата при наведении ББ мм
#define idfEM_A1UC07RDU	 828	//(A1UC07RDU) Зона возврата при наведении ББ мм
#define fEM_A1UL01RDU	 BUFFER[2078]	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A1UL01RDU	 829	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A3UC07RDU	 BUFFER[2083]	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define idfEM_A3UC07RDU	 830	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define fEM_A3UL01RDU	 BUFFER[2088]	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A3UL01RDU	 831	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A2UC08RDU	 BUFFER[2093]	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define idfEM_A2UC08RDU	 832	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define fEM_A2UC07RDU	 BUFFER[2098]	//(A2UC07RDU) Зона возврата при наведении РБ  мм
#define idfEM_A2UC07RDU	 833	//(A2UC07RDU) Зона возврата при наведении РБ  мм
#define fEM_A2UL01RDU	 BUFFER[2103]	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A2UL01RDU	 834	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_B8UC01RDU	 BUFFER[2108]	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
#define idfEM_B8UC01RDU	 835	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
#define fEM_B8UL07RDU	 BUFFER[2113]	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
#define idfEM_B8UL07RDU	 836	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
#define fEM_B8UC02RDU	 BUFFER[2118]	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
#define idfEM_B8UC02RDU	 837	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
#define fEM_B8UL01RDU	 BUFFER[2123]	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_B8UL01RDU	 838	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_B8UL05RDU	 BUFFER[2128]	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
#define idfEM_B8UL05RDU	 839	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
#define fEM_B8UL03RDU	 BUFFER[2133]	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
#define idfEM_B8UL03RDU	 840	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
#define fEM_B8UL06RDU	 BUFFER[2138]	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
#define idfEM_B8UL06RDU	 841	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
#define fEM_A9UZ03RDU	 BUFFER[2143]	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
#define idfEM_A9UZ03RDU	 842	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
#define fEM_A9UZ04RDU	 BUFFER[2148]	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
#define idfEM_A9UZ04RDU	 843	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
#define fEM_A9UZ05RDU	 BUFFER[2153]	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
#define idfEM_A9UZ05RDU	 844	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
#define fEM_R4UZ04RDU	 BUFFER[2158]	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define idfEM_R4UZ04RDU	 845	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define fEM_R4UZ03RDU	 BUFFER[2163]	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define idfEM_R4UZ03RDU	 846	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define fEM_R4UZ05RDU	 BUFFER[2168]	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define idfEM_R4UZ05RDU	 847	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define fEM_A5UZ03RDU	 BUFFER[2173]	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
#define idfEM_A5UZ03RDU	 848	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
#define fEM_A5UZ04RDU	 BUFFER[2178]	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
#define idfEM_A5UZ04RDU	 849	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
#define fEM_A5UZ05RDU	 BUFFER[2183]	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
#define idfEM_A5UZ05RDU	 850	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
#define fEM_A4UZ03RDU	 BUFFER[2188]	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
#define idfEM_A4UZ03RDU	 851	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
#define fEM_A4UZ04RDU	 BUFFER[2193]	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
#define idfEM_A4UZ04RDU	 852	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
#define fEM_A4UZ05RDU	 BUFFER[2198]	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
#define idfEM_A4UZ05RDU	 853	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
#define fEM_A6UZ03RDU	 BUFFER[2203]	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
#define idfEM_A6UZ03RDU	 854	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
#define fEM_A6UZ04RDU	 BUFFER[2208]	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
#define idfEM_A6UZ04RDU	 855	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
#define fEM_A6UZ05RDU	 BUFFER[2213]	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
#define idfEM_A6UZ05RDU	 856	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
#define fEM_R1UZ03RDU	 BUFFER[2218]	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define idfEM_R1UZ03RDU	 857	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define fEM_R1UZ04RDU	 BUFFER[2223]	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define idfEM_R1UZ04RDU	 858	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define fEM_R1UZ05RDU	 BUFFER[2228]	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define idfEM_R1UZ05RDU	 859	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define fEM_R0UL04RDU	 BUFFER[2233]	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
#define idfEM_R0UL04RDU	 860	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
#define fEM_R0UL06RDU	 BUFFER[2238]	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
#define idfEM_R0UL06RDU	 861	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
#define fEM_R0UL03RDU	 BUFFER[2243]	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
#define idfEM_R0UL03RDU	 862	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
#define fEM_R0UL17RDU	 BUFFER[2248]	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
#define idfEM_R0UL17RDU	 863	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
#define fEM_R0UL19RDU	 BUFFER[2253]	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define idfEM_R0UL19RDU	 864	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define fEM_R0UL07RDU	 BUFFER[2258]	//(R0UL07RDU) Время срабатывания верхней АС II УР
#define idfEM_R0UL07RDU	 865	//(R0UL07RDU) Время срабатывания верхней АС II УР
#define fEM_R0UL18RDU	 BUFFER[2263]	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
#define idfEM_R0UL18RDU	 866	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
#define fEM_R0UL16RDU	 BUFFER[2268]	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
#define idfEM_R0UL16RDU	 867	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
#define fEM_R0UL02RDU	 BUFFER[2273]	//(R0UL02RDU) Время задержки  ИНИ
#define idfEM_R0UL02RDU	 868	//(R0UL02RDU) Время задержки  ИНИ
#define fEM_R0UN08RDU	 BUFFER[2278]	//(R0UN08RDU) 8-я заданная мощность
#define idfEM_R0UN08RDU	 869	//(R0UN08RDU) 8-я заданная мощность
#define fEM_R0UN07RDU	 BUFFER[2283]	//(R0UN07RDU) 7-я заданная мощность
#define idfEM_R0UN07RDU	 870	//(R0UN07RDU) 7-я заданная мощность
#define fEM_R0UN06RDU	 BUFFER[2288]	//(R0UN06RDU) 6-я заданная мощность
#define idfEM_R0UN06RDU	 871	//(R0UN06RDU) 6-я заданная мощность
#define fEM_R0UN05RDU	 BUFFER[2293]	//(R0UN05RDU) 5-я заданная мощность
#define idfEM_R0UN05RDU	 872	//(R0UN05RDU) 5-я заданная мощность
#define fEM_R0UN04RDU	 BUFFER[2298]	//(R0UN04RDU) 4-я заданная мощность
#define idfEM_R0UN04RDU	 873	//(R0UN04RDU) 4-я заданная мощность
#define fEM_R0UN03RDU	 BUFFER[2303]	//(R0UN03RDU) Ограничение 3 по мощности
#define idfEM_R0UN03RDU	 874	//(R0UN03RDU) Ограничение 3 по мощности
#define fEM_R0UN02RDU	 BUFFER[2308]	//(R0UN02RDU) 2-я заданная мощность
#define idfEM_R0UN02RDU	 875	//(R0UN02RDU) 2-я заданная мощность
#define fEM_R0UN01RDU	 BUFFER[2313]	//(R0UN01RDU) 1-я заданная мощность
#define idfEM_R0UN01RDU	 876	//(R0UN01RDU) 1-я заданная мощность
#define fEM_A2UC82RDU	 BUFFER[2318]	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC82RDU	 877	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define fEM_A2UC83RDU	 BUFFER[2323]	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define idfEM_A2UC83RDU	 878	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define fEM_A1UC83RDU	 BUFFER[2328]	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define idfEM_A1UC83RDU	 879	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define fEM_A2UC81RDU	 BUFFER[2333]	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC81RDU	 880	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define fEM_A1UC81RDU	 BUFFER[2338]	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC81RDU	 881	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define fEM_A1UC82RDU	 BUFFER[2343]	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC82RDU	 882	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define fEM_A2UL83RDU	 BUFFER[2348]	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL83RDU	 883	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A3UC81RDU	 BUFFER[2353]	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define idfEM_A3UC81RDU	 884	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define fEM_A3UC82RDU	 BUFFER[2358]	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define idfEM_A3UC82RDU	 885	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define fEM_R0UN80RDU	 BUFFER[2363]	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define idfEM_R0UN80RDU	 886	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define iEM_A2UV01IDU	 BUFFER[2368]	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV01IDU	 887	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define iEM_A2UV02IDU	 BUFFER[2371]	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV02IDU	 888	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define iEM_A1UV01IDU	 BUFFER[2374]	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV01IDU	 889	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define iEM_A1UV02IDU	 BUFFER[2377]	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV02IDU	 890	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define iEM_A1UV03IDU	 BUFFER[2380]	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define idiEM_A1UV03IDU	 891	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define iEM_A3UV01IDU	 BUFFER[2383]	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define idiEM_A3UV01IDU	 892	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define iEM_A3UV02IDU	 BUFFER[2386]	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define idiEM_A3UV02IDU	 893	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define lEM_R0MD01LC1	 BUFFER[2389]	//(R0MD01LC1) Ручное управление ОРР
#define idlEM_R0MD01LC1	 894	//(R0MD01LC1) Ручное управление ОРР
#define fEM_A3UC09RDU	 BUFFER[2391]	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC09RDU	 895	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define fEM_A2UC02RDU	 BUFFER[2396]	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define idfEM_A2UC02RDU	 896	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define fEM_A1UC02RDU	 BUFFER[2401]	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define idfEM_A1UC02RDU	 897	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define fEM_A3UC02RDU	 BUFFER[2406]	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define idfEM_A3UC02RDU	 898	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define fEM_R0UL21RDU	 BUFFER[2411]	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
#define idfEM_R0UL21RDU	 899	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
#define fEM_R0UN09RDU	 BUFFER[2416]	//(R0UN09RDU) Минимальный период при регулировании мощности
#define idfEM_R0UN09RDU	 900	//(R0UN09RDU) Минимальный период при регулировании мощности
#define fEM_R0UN11RDU	 BUFFER[2421]	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
#define idfEM_R0UN11RDU	 901	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
#define fEM_R0UN12RDU	 BUFFER[2426]	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
#define idfEM_R0UN12RDU	 902	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
#define fEM_R0UN13RDU	 BUFFER[2431]	//(R0UN13RDU) Минимальное изменение координаты, мм
#define idfEM_R0UN13RDU	 903	//(R0UN13RDU) Минимальное изменение координаты, мм
#define fEM_R0UN14RDU	 BUFFER[2436]	//(R0UN14RDU) Максимальная координата штока ИМ, мм
#define idfEM_R0UN14RDU	 904	//(R0UN14RDU) Максимальная координата штока ИМ, мм
#define fEM_R0UN16RDU	 BUFFER[2441]	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN16RDU	 905	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN17RDU	 BUFFER[2446]	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN17RDU	 906	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN18RDU	 BUFFER[2451]	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
#define idfEM_R0UN18RDU	 907	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
#define fEM_R0UN19RDU	 BUFFER[2456]	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define idfEM_R0UN19RDU	 908	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define fEM_R0UN70LDU	 BUFFER[2461]	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN70LDU	 909	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN71LDU	 BUFFER[2466]	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN71LDU	 910	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN72LDU	 BUFFER[2471]	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN72LDU	 911	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN73LDU	 BUFFER[2476]	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN73LDU	 912	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN74LDU	 BUFFER[2481]	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN74LDU	 913	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN75LDU	 BUFFER[2486]	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN75LDU	 914	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN80LDU	 BUFFER[2491]	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN80LDU	 915	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define fEM_R0UN81LDU	 BUFFER[2496]	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN81LDU	 916	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define fEM_R0UN82LDU	 BUFFER[2501]	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN82LDU	 917	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define fEM_R0UN83LDU	 BUFFER[2506]	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN83LDU	 918	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define fEM_R0UN84LDU	 BUFFER[2511]	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN84LDU	 919	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define fEM_R0UN85LDU	 BUFFER[2516]	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN85LDU	 920	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define fEM_R0UT20RDU	 BUFFER[2521]	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define idfEM_R0UT20RDU	 921	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define fEM_R0UN25RDU	 BUFFER[2526]	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
#define idfEM_R0UN25RDU	 922	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
#define fEM_R0UN15RDU	 BUFFER[2531]	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
#define idfEM_R0UN15RDU	 923	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
#define fEM_R0UN26RDU	 BUFFER[2536]	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
#define idfEM_R0UN26RDU	 924	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
#define fEM_R0UN27RDU	 BUFFER[2541]	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
#define idfEM_R0UN27RDU	 925	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
#define fEM_R0UN24RDU	 BUFFER[2546]	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN24RDU	 926	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
#define fEM_R0UL25RDU	 BUFFER[2551]	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define idfEM_R0UL25RDU	 927	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define bFirstEnterFlag	 BUFFER[2556]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 928	//(bFirstEnterFlag) 
#define internal2_m186_y0	 BUFFER[2558]	//(internal2_m186_y0) y0
#define idinternal2_m186_y0	 929	//(internal2_m186_y0) y0
#define internal2_m184_y0	 BUFFER[2563]	//(internal2_m184_y0) y0
#define idinternal2_m184_y0	 930	//(internal2_m184_y0) y0
#define internal2_m216_y0	 BUFFER[2568]	//(internal2_m216_y0) state
#define idinternal2_m216_y0	 931	//(internal2_m216_y0) state
#define internal2_m210_y0	 BUFFER[2570]	//(internal2_m210_y0) state
#define idinternal2_m210_y0	 932	//(internal2_m210_y0) state
#define internal2_m199_y1	 BUFFER[2572]	//(internal2_m199_y1) y1 - внутренний параметр
#define idinternal2_m199_y1	 933	//(internal2_m199_y1) y1 - внутренний параметр
#define internal2_m206_y1	 BUFFER[2574]	//(internal2_m206_y1) y1 - внутренний параметр
#define idinternal2_m206_y1	 934	//(internal2_m206_y1) y1 - внутренний параметр
#define internal2_m189_y1	 BUFFER[2576]	//(internal2_m189_y1) y1 - внутренний параметр
#define idinternal2_m189_y1	 935	//(internal2_m189_y1) y1 - внутренний параметр
#define internal2_m196_y1	 BUFFER[2578]	//(internal2_m196_y1) y1 - внутренний параметр
#define idinternal2_m196_y1	 936	//(internal2_m196_y1) y1 - внутренний параметр
#define internal2_m16_Nk0	 BUFFER[2580]	//(internal2_m16_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m16_Nk0	 937	//(internal2_m16_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m16_SetFlag	 BUFFER[2585]	//(internal2_m16_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m16_SetFlag	 938	//(internal2_m16_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m108_Nk0	 BUFFER[2587]	//(internal2_m108_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m108_Nk0	 939	//(internal2_m108_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m108_SetFlag	 BUFFER[2592]	//(internal2_m108_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m108_SetFlag	 940	//(internal2_m108_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m112_Nk0	 BUFFER[2594]	//(internal2_m112_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m112_Nk0	 941	//(internal2_m112_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m112_SetFlag	 BUFFER[2599]	//(internal2_m112_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m112_SetFlag	 942	//(internal2_m112_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m75_Nk0	 BUFFER[2601]	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m75_Nk0	 943	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m75_SetFlag	 BUFFER[2606]	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m75_SetFlag	 944	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m77_Nk0	 BUFFER[2608]	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m77_Nk0	 945	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m77_SetFlag	 BUFFER[2613]	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m77_SetFlag	 946	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m47_Nk0	 BUFFER[2615]	//(internal2_m47_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m47_Nk0	 947	//(internal2_m47_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m47_SetFlag	 BUFFER[2620]	//(internal2_m47_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m47_SetFlag	 948	//(internal2_m47_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m51_Nk0	 BUFFER[2622]	//(internal2_m51_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m51_Nk0	 949	//(internal2_m51_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m51_SetFlag	 BUFFER[2627]	//(internal2_m51_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m51_SetFlag	 950	//(internal2_m51_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m21_Nk0	 BUFFER[2629]	//(internal2_m21_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m21_Nk0	 951	//(internal2_m21_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m21_SetFlag	 BUFFER[2634]	//(internal2_m21_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m21_SetFlag	 952	//(internal2_m21_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal1_m198_s	 BUFFER[2636]	//(internal1_m198_s) s - запомнили значение
#define idinternal1_m198_s	 953	//(internal1_m198_s) s - запомнили значение
#define internal1_m195_s	 BUFFER[2638]	//(internal1_m195_s) s - запомнили значение
#define idinternal1_m195_s	 954	//(internal1_m195_s) s - запомнили значение
#define internal1_m188_s	 BUFFER[2640]	//(internal1_m188_s) s - запомнили значение
#define idinternal1_m188_s	 955	//(internal1_m188_s) s - запомнили значение
#define internal1_m183_s	 BUFFER[2642]	//(internal1_m183_s) s - запомнили значение
#define idinternal1_m183_s	 956	//(internal1_m183_s) s - запомнили значение
#define internal1_m179_s	 BUFFER[2644]	//(internal1_m179_s) s - запомнили значение
#define idinternal1_m179_s	 957	//(internal1_m179_s) s - запомнили значение
#define internal1_m1710_q0	 BUFFER[2646]	//(internal1_m1710_q0) q0 - внутренний параметр
#define idinternal1_m1710_q0	 958	//(internal1_m1710_q0) q0 - внутренний параметр
#define internal1_m2145_q0	 BUFFER[2648]	//(internal1_m2145_q0) q0 - внутренний параметр
#define idinternal1_m2145_q0	 959	//(internal1_m2145_q0) q0 - внутренний параметр
#define internal1_m2129_q0	 BUFFER[2650]	//(internal1_m2129_q0) q0 - внутренний параметр
#define idinternal1_m2129_q0	 960	//(internal1_m2129_q0) q0 - внутренний параметр
#define internal1_m2177_q0	 BUFFER[2652]	//(internal1_m2177_q0) q0 - внутренний параметр
#define idinternal1_m2177_q0	 961	//(internal1_m2177_q0) q0 - внутренний параметр
#define internal1_m2161_q0	 BUFFER[2654]	//(internal1_m2161_q0) q0 - внутренний параметр
#define idinternal1_m2161_q0	 962	//(internal1_m2161_q0) q0 - внутренний параметр
#define internal1_m2151_q0	 BUFFER[2656]	//(internal1_m2151_q0) q0 - внутренний параметр
#define idinternal1_m2151_q0	 963	//(internal1_m2151_q0) q0 - внутренний параметр
#define internal1_m2132_q0	 BUFFER[2658]	//(internal1_m2132_q0) q0 - внутренний параметр
#define idinternal1_m2132_q0	 964	//(internal1_m2132_q0) q0 - внутренний параметр
#define internal1_m2149_q0	 BUFFER[2660]	//(internal1_m2149_q0) q0 - внутренний параметр
#define idinternal1_m2149_q0	 965	//(internal1_m2149_q0) q0 - внутренний параметр
#define internal1_m2130_q0	 BUFFER[2662]	//(internal1_m2130_q0) q0 - внутренний параметр
#define idinternal1_m2130_q0	 966	//(internal1_m2130_q0) q0 - внутренний параметр
#define internal1_m2128_q0	 BUFFER[2664]	//(internal1_m2128_q0) q0 - внутренний параметр
#define idinternal1_m2128_q0	 967	//(internal1_m2128_q0) q0 - внутренний параметр
#define internal1_m2127_q0	 BUFFER[2666]	//(internal1_m2127_q0) q0 - внутренний параметр
#define idinternal1_m2127_q0	 968	//(internal1_m2127_q0) q0 - внутренний параметр
#define internal1_m2141_q0	 BUFFER[2668]	//(internal1_m2141_q0) q0 - внутренний параметр
#define idinternal1_m2141_q0	 969	//(internal1_m2141_q0) q0 - внутренний параметр
#define internal1_m2139_q0	 BUFFER[2670]	//(internal1_m2139_q0) q0 - внутренний параметр
#define idinternal1_m2139_q0	 970	//(internal1_m2139_q0) q0 - внутренний параметр
#define internal1_m2147_q0	 BUFFER[2672]	//(internal1_m2147_q0) q0 - внутренний параметр
#define idinternal1_m2147_q0	 971	//(internal1_m2147_q0) q0 - внутренний параметр
#define internal1_m2143_q0	 BUFFER[2674]	//(internal1_m2143_q0) q0 - внутренний параметр
#define idinternal1_m2143_q0	 972	//(internal1_m2143_q0) q0 - внутренний параметр
#define internal1_m2183_q0	 BUFFER[2676]	//(internal1_m2183_q0) q0 - внутренний параметр
#define idinternal1_m2183_q0	 973	//(internal1_m2183_q0) q0 - внутренний параметр
#define internal1_m2164_q0	 BUFFER[2678]	//(internal1_m2164_q0) q0 - внутренний параметр
#define idinternal1_m2164_q0	 974	//(internal1_m2164_q0) q0 - внутренний параметр
#define internal1_m2181_q0	 BUFFER[2680]	//(internal1_m2181_q0) q0 - внутренний параметр
#define idinternal1_m2181_q0	 975	//(internal1_m2181_q0) q0 - внутренний параметр
#define internal1_m2163_q0	 BUFFER[2682]	//(internal1_m2163_q0) q0 - внутренний параметр
#define idinternal1_m2163_q0	 976	//(internal1_m2163_q0) q0 - внутренний параметр
#define internal1_m2160_q0	 BUFFER[2684]	//(internal1_m2160_q0) q0 - внутренний параметр
#define idinternal1_m2160_q0	 977	//(internal1_m2160_q0) q0 - внутренний параметр
#define internal1_m2159_q0	 BUFFER[2686]	//(internal1_m2159_q0) q0 - внутренний параметр
#define idinternal1_m2159_q0	 978	//(internal1_m2159_q0) q0 - внутренний параметр
#define internal1_m2173_q0	 BUFFER[2688]	//(internal1_m2173_q0) q0 - внутренний параметр
#define idinternal1_m2173_q0	 979	//(internal1_m2173_q0) q0 - внутренний параметр
#define internal1_m2171_q0	 BUFFER[2690]	//(internal1_m2171_q0) q0 - внутренний параметр
#define idinternal1_m2171_q0	 980	//(internal1_m2171_q0) q0 - внутренний параметр
#define internal1_m2048_tx	 BUFFER[2692]	//(internal1_m2048_tx) tx - внутренний параметр
#define idinternal1_m2048_tx	 981	//(internal1_m2048_tx) tx - внутренний параметр
#define internal1_m2027_tx	 BUFFER[2697]	//(internal1_m2027_tx) tx - внутренний параметр
#define idinternal1_m2027_tx	 982	//(internal1_m2027_tx) tx - внутренний параметр
#define internal1_m1734_Pv0	 BUFFER[2702]	//(internal1_m1734_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1734_Pv0	 983	//(internal1_m1734_Pv0)  - Пер. выключатель механизма
#define internal1_m1734_Zv0	 BUFFER[2704]	//(internal1_m1734_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1734_Zv0	 984	//(internal1_m1734_Zv0)  - Зад. выключатель механизма
#define internal1_m1734_MyFirstEnterFlag	 BUFFER[2706]	//(internal1_m1734_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1734_MyFirstEnterFlag	 985	//(internal1_m1734_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m1731_Pv0	 BUFFER[2708]	//(internal1_m1731_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1731_Pv0	 986	//(internal1_m1731_Pv0)  - Пер. выключатель механизма
#define internal1_m1731_Zv0	 BUFFER[2710]	//(internal1_m1731_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1731_Zv0	 987	//(internal1_m1731_Zv0)  - Зад. выключатель механизма
#define internal1_m1731_MyFirstEnterFlag	 BUFFER[2712]	//(internal1_m1731_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1731_MyFirstEnterFlag	 988	//(internal1_m1731_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m2202_tx	 BUFFER[2714]	//(internal1_m2202_tx) tx - время накопленное сек
#define idinternal1_m2202_tx	 989	//(internal1_m2202_tx) tx - время накопленное сек
#define internal1_m2202_y0	 BUFFER[2719]	//(internal1_m2202_y0) y0
#define idinternal1_m2202_y0	 990	//(internal1_m2202_y0) y0
#define internal1_m2206_tx	 BUFFER[2720]	//(internal1_m2206_tx) tx - время накопленное сек
#define idinternal1_m2206_tx	 991	//(internal1_m2206_tx) tx - время накопленное сек
#define internal1_m2206_y0	 BUFFER[2725]	//(internal1_m2206_y0) y0
#define idinternal1_m2206_y0	 992	//(internal1_m2206_y0) y0
#define internal1_m2205_tx	 BUFFER[2726]	//(internal1_m2205_tx) tx - время накопленное сек
#define idinternal1_m2205_tx	 993	//(internal1_m2205_tx) tx - время накопленное сек
#define internal1_m2205_y0	 BUFFER[2731]	//(internal1_m2205_y0) y0
#define idinternal1_m2205_y0	 994	//(internal1_m2205_y0) y0
#define internal1_m2242_tx	 BUFFER[2732]	//(internal1_m2242_tx) tx - внутренний параметр
#define idinternal1_m2242_tx	 995	//(internal1_m2242_tx) tx - внутренний параметр
#define internal1_m2240_tx	 BUFFER[2737]	//(internal1_m2240_tx) tx - время накопленное сек
#define idinternal1_m2240_tx	 996	//(internal1_m2240_tx) tx - время накопленное сек
#define internal1_m2240_y0	 BUFFER[2742]	//(internal1_m2240_y0) y0
#define idinternal1_m2240_y0	 997	//(internal1_m2240_y0) y0
#define internal1_m2245_q0	 BUFFER[2743]	//(internal1_m2245_q0) q0 - внутренний параметр
#define idinternal1_m2245_q0	 998	//(internal1_m2245_q0) q0 - внутренний параметр
#define internal1_m2212_q0	 BUFFER[2745]	//(internal1_m2212_q0) q0 - внутренний параметр
#define idinternal1_m2212_q0	 999	//(internal1_m2212_q0) q0 - внутренний параметр
#define internal1_m2220_tx	 BUFFER[2747]	//(internal1_m2220_tx) tx - внутренний параметр
#define idinternal1_m2220_tx	 1000	//(internal1_m2220_tx) tx - внутренний параметр
#define internal1_m2218_q0	 BUFFER[2752]	//(internal1_m2218_q0) q0 - внутренний параметр
#define idinternal1_m2218_q0	 1001	//(internal1_m2218_q0) q0 - внутренний параметр
#define internal1_m2042_tx	 BUFFER[2754]	//(internal1_m2042_tx) tx - время накопленное сек
#define idinternal1_m2042_tx	 1002	//(internal1_m2042_tx) tx - время накопленное сек
#define internal1_m2042_y0	 BUFFER[2759]	//(internal1_m2042_y0) y0
#define idinternal1_m2042_y0	 1003	//(internal1_m2042_y0) y0
#define internal1_m2034_tx	 BUFFER[2760]	//(internal1_m2034_tx) tx - время накопленное сек
#define idinternal1_m2034_tx	 1004	//(internal1_m2034_tx) tx - время накопленное сек
#define internal1_m2034_y0	 BUFFER[2765]	//(internal1_m2034_y0) y0
#define idinternal1_m2034_y0	 1005	//(internal1_m2034_y0) y0
#define internal1_m1720_q0	 BUFFER[2766]	//(internal1_m1720_q0) q0 - внутренний параметр
#define idinternal1_m1720_q0	 1006	//(internal1_m1720_q0) q0 - внутренний параметр
#define internal1_m1725_q0	 BUFFER[2768]	//(internal1_m1725_q0) q0 - внутренний параметр
#define idinternal1_m1725_q0	 1007	//(internal1_m1725_q0) q0 - внутренний параметр
#define internal1_m1717_q0	 BUFFER[2770]	//(internal1_m1717_q0) q0 - внутренний параметр
#define idinternal1_m1717_q0	 1008	//(internal1_m1717_q0) q0 - внутренний параметр
#define internal1_m1759_q0	 BUFFER[2772]	//(internal1_m1759_q0) q0 - внутренний параметр
#define idinternal1_m1759_q0	 1009	//(internal1_m1759_q0) q0 - внутренний параметр
#define internal1_m759_tx	 BUFFER[2774]	//(internal1_m759_tx) tx - время накопленное сек
#define idinternal1_m759_tx	 1010	//(internal1_m759_tx) tx - время накопленное сек
#define internal1_m759_y0	 BUFFER[2779]	//(internal1_m759_y0) y0
#define idinternal1_m759_y0	 1011	//(internal1_m759_y0) y0
#define internal1_m2038_tx	 BUFFER[2780]	//(internal1_m2038_tx) tx - внутренний параметр
#define idinternal1_m2038_tx	 1012	//(internal1_m2038_tx) tx - внутренний параметр
#define internal1_m2041_q0	 BUFFER[2785]	//(internal1_m2041_q0) q0 - внутренний параметр
#define idinternal1_m2041_q0	 1013	//(internal1_m2041_q0) q0 - внутренний параметр
#define internal1_m2033_q0	 BUFFER[2787]	//(internal1_m2033_q0) q0 - внутренний параметр
#define idinternal1_m2033_q0	 1014	//(internal1_m2033_q0) q0 - внутренний параметр
#define internal1_m2003_tx	 BUFFER[2789]	//(internal1_m2003_tx) tx - внутренний параметр
#define idinternal1_m2003_tx	 1015	//(internal1_m2003_tx) tx - внутренний параметр
#define internal1_m2014_tx	 BUFFER[2794]	//(internal1_m2014_tx) tx - внутренний параметр
#define idinternal1_m2014_tx	 1016	//(internal1_m2014_tx) tx - внутренний параметр
#define internal1_m2000_tx	 BUFFER[2799]	//(internal1_m2000_tx) tx - внутренний параметр
#define idinternal1_m2000_tx	 1017	//(internal1_m2000_tx) tx - внутренний параметр
#define internal1_m2006_q0	 BUFFER[2804]	//(internal1_m2006_q0) q0 - внутренний параметр
#define idinternal1_m2006_q0	 1018	//(internal1_m2006_q0) q0 - внутренний параметр
#define internal1_m2018_q0	 BUFFER[2806]	//(internal1_m2018_q0) q0 - внутренний параметр
#define idinternal1_m2018_q0	 1019	//(internal1_m2018_q0) q0 - внутренний параметр
#define internal1_m1976_tx	 BUFFER[2808]	//(internal1_m1976_tx) tx - внутренний параметр
#define idinternal1_m1976_tx	 1020	//(internal1_m1976_tx) tx - внутренний параметр
#define internal1_m57_tx	 BUFFER[2813]	//(internal1_m57_tx) tx - внутренний параметр
#define idinternal1_m57_tx	 1021	//(internal1_m57_tx) tx - внутренний параметр
#define internal1_m356_tx	 BUFFER[2818]	//(internal1_m356_tx) tx - внутренний параметр
#define idinternal1_m356_tx	 1022	//(internal1_m356_tx) tx - внутренний параметр
#define internal1_m312_tx	 BUFFER[2823]	//(internal1_m312_tx) tx - внутренний параметр
#define idinternal1_m312_tx	 1023	//(internal1_m312_tx) tx - внутренний параметр
#define internal1_m760_tx	 BUFFER[2828]	//(internal1_m760_tx) tx - внутренний параметр
#define idinternal1_m760_tx	 1024	//(internal1_m760_tx) tx - внутренний параметр
#define internal1_m1440_tx	 BUFFER[2833]	//(internal1_m1440_tx) tx - внутренний параметр
#define idinternal1_m1440_tx	 1025	//(internal1_m1440_tx) tx - внутренний параметр
#define internal1_m119_tx	 BUFFER[2838]	//(internal1_m119_tx) tx - внутренний параметр
#define idinternal1_m119_tx	 1026	//(internal1_m119_tx) tx - внутренний параметр
#define internal1_m121_tx	 BUFFER[2843]	//(internal1_m121_tx) tx - внутренний параметр
#define idinternal1_m121_tx	 1027	//(internal1_m121_tx) tx - внутренний параметр
#define internal1_m126_tx	 BUFFER[2848]	//(internal1_m126_tx) tx - внутренний параметр
#define idinternal1_m126_tx	 1028	//(internal1_m126_tx) tx - внутренний параметр
#define internal1_m24_tx	 BUFFER[2853]	//(internal1_m24_tx) tx - внутренний параметр
#define idinternal1_m24_tx	 1029	//(internal1_m24_tx) tx - внутренний параметр
#define internal1_m16_tx	 BUFFER[2858]	//(internal1_m16_tx) tx - внутренний параметр
#define idinternal1_m16_tx	 1030	//(internal1_m16_tx) tx - внутренний параметр
#define internal1_m1985_tx	 BUFFER[2863]	//(internal1_m1985_tx) tx - внутренний параметр
#define idinternal1_m1985_tx	 1031	//(internal1_m1985_tx) tx - внутренний параметр
#define internal1_m1973_tx	 BUFFER[2868]	//(internal1_m1973_tx) tx - внутренний параметр
#define idinternal1_m1973_tx	 1032	//(internal1_m1973_tx) tx - внутренний параметр
#define internal1_m2081_tx	 BUFFER[2873]	//(internal1_m2081_tx) tx - внутренний параметр
#define idinternal1_m2081_tx	 1033	//(internal1_m2081_tx) tx - внутренний параметр
#define internal1_m2085_tx	 BUFFER[2878]	//(internal1_m2085_tx) tx - внутренний параметр
#define idinternal1_m2085_tx	 1034	//(internal1_m2085_tx) tx - внутренний параметр
#define internal1_m1898_tx	 BUFFER[2883]	//(internal1_m1898_tx) tx - внутренний параметр
#define idinternal1_m1898_tx	 1035	//(internal1_m1898_tx) tx - внутренний параметр
#define internal1_m83_tx	 BUFFER[2888]	//(internal1_m83_tx) tx - внутренний параметр
#define idinternal1_m83_tx	 1036	//(internal1_m83_tx) tx - внутренний параметр
#define internal1_m325_tx	 BUFFER[2893]	//(internal1_m325_tx) tx - время накопленное сек
#define idinternal1_m325_tx	 1037	//(internal1_m325_tx) tx - время накопленное сек
#define internal1_m325_y0	 BUFFER[2898]	//(internal1_m325_y0) y0
#define idinternal1_m325_y0	 1038	//(internal1_m325_y0) y0
#define internal1_m1892_tx	 BUFFER[2899]	//(internal1_m1892_tx) tx - время накопленное сек
#define idinternal1_m1892_tx	 1039	//(internal1_m1892_tx) tx - время накопленное сек
#define internal1_m1892_y0	 BUFFER[2904]	//(internal1_m1892_y0) y0
#define idinternal1_m1892_y0	 1040	//(internal1_m1892_y0) y0
#define internal1_m1890_tx	 BUFFER[2905]	//(internal1_m1890_tx) tx - время накопленное сек
#define idinternal1_m1890_tx	 1041	//(internal1_m1890_tx) tx - время накопленное сек
#define internal1_m1890_y0	 BUFFER[2910]	//(internal1_m1890_y0) y0
#define idinternal1_m1890_y0	 1042	//(internal1_m1890_y0) y0
#define internal1_m1879_tx	 BUFFER[2911]	//(internal1_m1879_tx) tx - время накопленное сек
#define idinternal1_m1879_tx	 1043	//(internal1_m1879_tx) tx - время накопленное сек
#define internal1_m1879_y0	 BUFFER[2916]	//(internal1_m1879_y0) y0
#define idinternal1_m1879_y0	 1044	//(internal1_m1879_y0) y0
#define internal1_m1899_q0	 BUFFER[2917]	//(internal1_m1899_q0) q0 - внутренний параметр
#define idinternal1_m1899_q0	 1045	//(internal1_m1899_q0) q0 - внутренний параметр
#define internal1_m1460_q0	 BUFFER[2922]	//(internal1_m1460_q0) q0 - внутренний параметр
#define idinternal1_m1460_q0	 1046	//(internal1_m1460_q0) q0 - внутренний параметр
#define internal1_m1499_q0	 BUFFER[2927]	//(internal1_m1499_q0) q0 - внутренний параметр
#define idinternal1_m1499_q0	 1047	//(internal1_m1499_q0) q0 - внутренний параметр
#define internal1_m1497_q0	 BUFFER[2932]	//(internal1_m1497_q0) q0 - внутренний параметр
#define idinternal1_m1497_q0	 1048	//(internal1_m1497_q0) q0 - внутренний параметр
#define internal1_m1938_q0	 BUFFER[2937]	//(internal1_m1938_q0) q0 - внутренний параметр
#define idinternal1_m1938_q0	 1049	//(internal1_m1938_q0) q0 - внутренний параметр
#define internal1_m1916_tx	 BUFFER[2942]	//(internal1_m1916_tx) tx - время накопленное сек
#define idinternal1_m1916_tx	 1050	//(internal1_m1916_tx) tx - время накопленное сек
#define internal1_m1916_y0	 BUFFER[2947]	//(internal1_m1916_y0) y0
#define idinternal1_m1916_y0	 1051	//(internal1_m1916_y0) y0
#define internal1_m1931_tx	 BUFFER[2948]	//(internal1_m1931_tx) tx - время накопленное сек
#define idinternal1_m1931_tx	 1052	//(internal1_m1931_tx) tx - время накопленное сек
#define internal1_m1931_y0	 BUFFER[2953]	//(internal1_m1931_y0) y0
#define idinternal1_m1931_y0	 1053	//(internal1_m1931_y0) y0
#define internal1_m1928_tx	 BUFFER[2954]	//(internal1_m1928_tx) tx - время накопленное сек
#define idinternal1_m1928_tx	 1054	//(internal1_m1928_tx) tx - время накопленное сек
#define internal1_m1928_y0	 BUFFER[2959]	//(internal1_m1928_y0) y0
#define idinternal1_m1928_y0	 1055	//(internal1_m1928_y0) y0
#define internal1_m2064_tx	 BUFFER[2960]	//(internal1_m2064_tx) tx - время накопленное сек
#define idinternal1_m2064_tx	 1056	//(internal1_m2064_tx) tx - время накопленное сек
#define internal1_m2064_y0	 BUFFER[2965]	//(internal1_m2064_y0) y0
#define idinternal1_m2064_y0	 1057	//(internal1_m2064_y0) y0
#define internal1_m2075_tx	 BUFFER[2966]	//(internal1_m2075_tx) tx - время накопленное сек
#define idinternal1_m2075_tx	 1058	//(internal1_m2075_tx) tx - время накопленное сек
#define internal1_m2075_y0	 BUFFER[2971]	//(internal1_m2075_y0) y0
#define idinternal1_m2075_y0	 1059	//(internal1_m2075_y0) y0
#define internal1_m1827_tx	 BUFFER[2972]	//(internal1_m1827_tx) tx - время накопленное сек
#define idinternal1_m1827_tx	 1060	//(internal1_m1827_tx) tx - время накопленное сек
#define internal1_m1827_y0	 BUFFER[2977]	//(internal1_m1827_y0) y0
#define idinternal1_m1827_y0	 1061	//(internal1_m1827_y0) y0
#define internal1_m1826_tx	 BUFFER[2978]	//(internal1_m1826_tx) tx - время накопленное сек
#define idinternal1_m1826_tx	 1062	//(internal1_m1826_tx) tx - время накопленное сек
#define internal1_m1826_y0	 BUFFER[2983]	//(internal1_m1826_y0) y0
#define idinternal1_m1826_y0	 1063	//(internal1_m1826_y0) y0
#define internal1_m1825_tx	 BUFFER[2984]	//(internal1_m1825_tx) tx - время накопленное сек
#define idinternal1_m1825_tx	 1064	//(internal1_m1825_tx) tx - время накопленное сек
#define internal1_m1825_y0	 BUFFER[2989]	//(internal1_m1825_y0) y0
#define idinternal1_m1825_y0	 1065	//(internal1_m1825_y0) y0
#define internal1_m1824_tx	 BUFFER[2990]	//(internal1_m1824_tx) tx - время накопленное сек
#define idinternal1_m1824_tx	 1066	//(internal1_m1824_tx) tx - время накопленное сек
#define internal1_m1824_y0	 BUFFER[2995]	//(internal1_m1824_y0) y0
#define idinternal1_m1824_y0	 1067	//(internal1_m1824_y0) y0
#define internal1_m1512_tx	 BUFFER[2996]	//(internal1_m1512_tx) tx - время накопленное сек
#define idinternal1_m1512_tx	 1068	//(internal1_m1512_tx) tx - время накопленное сек
#define internal1_m1512_y0	 BUFFER[3001]	//(internal1_m1512_y0) y0
#define idinternal1_m1512_y0	 1069	//(internal1_m1512_y0) y0
#define internal1_m1506_tx	 BUFFER[3002]	//(internal1_m1506_tx) tx - время накопленное сек
#define idinternal1_m1506_tx	 1070	//(internal1_m1506_tx) tx - время накопленное сек
#define internal1_m1506_y0	 BUFFER[3007]	//(internal1_m1506_y0) y0
#define idinternal1_m1506_y0	 1071	//(internal1_m1506_y0) y0
#define internal1_m1456_tx	 BUFFER[3008]	//(internal1_m1456_tx) tx - время накопленное сек
#define idinternal1_m1456_tx	 1072	//(internal1_m1456_tx) tx - время накопленное сек
#define internal1_m1456_y0	 BUFFER[3013]	//(internal1_m1456_y0) y0
#define idinternal1_m1456_y0	 1073	//(internal1_m1456_y0) y0
#define internal1_m842_tx	 BUFFER[3014]	//(internal1_m842_tx) tx - время накопленное сек
#define idinternal1_m842_tx	 1074	//(internal1_m842_tx) tx - время накопленное сек
#define internal1_m842_y0	 BUFFER[3019]	//(internal1_m842_y0) y0
#define idinternal1_m842_y0	 1075	//(internal1_m842_y0) y0
#define internal1_m840_tx	 BUFFER[3020]	//(internal1_m840_tx) tx - время накопленное сек
#define idinternal1_m840_tx	 1076	//(internal1_m840_tx) tx - время накопленное сек
#define internal1_m840_y0	 BUFFER[3025]	//(internal1_m840_y0) y0
#define idinternal1_m840_y0	 1077	//(internal1_m840_y0) y0
#define internal1_m847_tx	 BUFFER[3026]	//(internal1_m847_tx) tx - время накопленное сек
#define idinternal1_m847_tx	 1078	//(internal1_m847_tx) tx - время накопленное сек
#define internal1_m847_y0	 BUFFER[3031]	//(internal1_m847_y0) y0
#define idinternal1_m847_y0	 1079	//(internal1_m847_y0) y0
#define internal1_m203_tx	 BUFFER[3032]	//(internal1_m203_tx) tx - время накопленное сек
#define idinternal1_m203_tx	 1080	//(internal1_m203_tx) tx - время накопленное сек
#define internal1_m203_y0	 BUFFER[3037]	//(internal1_m203_y0) y0
#define idinternal1_m203_y0	 1081	//(internal1_m203_y0) y0
#define internal1_m204_tx	 BUFFER[3038]	//(internal1_m204_tx) tx - время накопленное сек
#define idinternal1_m204_tx	 1082	//(internal1_m204_tx) tx - время накопленное сек
#define internal1_m204_y0	 BUFFER[3043]	//(internal1_m204_y0) y0
#define idinternal1_m204_y0	 1083	//(internal1_m204_y0) y0
#define internal1_m214_tx	 BUFFER[3044]	//(internal1_m214_tx) tx - время накопленное сек
#define idinternal1_m214_tx	 1084	//(internal1_m214_tx) tx - время накопленное сек
#define internal1_m214_y0	 BUFFER[3049]	//(internal1_m214_y0) y0
#define idinternal1_m214_y0	 1085	//(internal1_m214_y0) y0
#define internal1_m536_tx	 BUFFER[3050]	//(internal1_m536_tx) tx - время накопленное сек
#define idinternal1_m536_tx	 1086	//(internal1_m536_tx) tx - время накопленное сек
#define internal1_m536_y0	 BUFFER[3055]	//(internal1_m536_y0) y0
#define idinternal1_m536_y0	 1087	//(internal1_m536_y0) y0
#define internal1_m2113_tx	 BUFFER[3056]	//(internal1_m2113_tx) tx - внутренний параметр
#define idinternal1_m2113_tx	 1088	//(internal1_m2113_tx) tx - внутренний параметр
#define internal1_m1200_tx	 BUFFER[3061]	//(internal1_m1200_tx) tx - внутренний параметр
#define idinternal1_m1200_tx	 1089	//(internal1_m1200_tx) tx - внутренний параметр
#define internal1_m1626_tx	 BUFFER[3066]	//(internal1_m1626_tx) tx - время накопленное сек
#define idinternal1_m1626_tx	 1090	//(internal1_m1626_tx) tx - время накопленное сек
#define internal1_m1626_y0	 BUFFER[3071]	//(internal1_m1626_y0) y0
#define idinternal1_m1626_y0	 1091	//(internal1_m1626_y0) y0
#define internal1_m1151_tx	 BUFFER[3072]	//(internal1_m1151_tx) tx - время накопленное сек
#define idinternal1_m1151_tx	 1092	//(internal1_m1151_tx) tx - время накопленное сек
#define internal1_m1151_y0	 BUFFER[3077]	//(internal1_m1151_y0) y0
#define idinternal1_m1151_y0	 1093	//(internal1_m1151_y0) y0
#define internal1_m1352_tx	 BUFFER[3078]	//(internal1_m1352_tx) tx - время накопленное сек
#define idinternal1_m1352_tx	 1094	//(internal1_m1352_tx) tx - время накопленное сек
#define internal1_m1352_y0	 BUFFER[3083]	//(internal1_m1352_y0) y0
#define idinternal1_m1352_y0	 1095	//(internal1_m1352_y0) y0
#define internal1_m940_tx	 BUFFER[3084]	//(internal1_m940_tx) tx - время накопленное сек
#define idinternal1_m940_tx	 1096	//(internal1_m940_tx) tx - время накопленное сек
#define internal1_m940_y0	 BUFFER[3089]	//(internal1_m940_y0) y0
#define idinternal1_m940_y0	 1097	//(internal1_m940_y0) y0
#define internal1_m1259_tx	 BUFFER[3090]	//(internal1_m1259_tx) tx - время накопленное сек
#define idinternal1_m1259_tx	 1098	//(internal1_m1259_tx) tx - время накопленное сек
#define internal1_m1259_y0	 BUFFER[3095]	//(internal1_m1259_y0) y0
#define idinternal1_m1259_y0	 1099	//(internal1_m1259_y0) y0
#define internal1_m1092_q0	 BUFFER[3096]	//(internal1_m1092_q0) q0 - внутренний параметр
#define idinternal1_m1092_q0	 1100	//(internal1_m1092_q0) q0 - внутренний параметр
#define internal1_m1090_q0	 BUFFER[3098]	//(internal1_m1090_q0) q0 - внутренний параметр
#define idinternal1_m1090_q0	 1101	//(internal1_m1090_q0) q0 - внутренний параметр
#define internal1_m1089_q0	 BUFFER[3100]	//(internal1_m1089_q0) q0 - внутренний параметр
#define idinternal1_m1089_q0	 1102	//(internal1_m1089_q0) q0 - внутренний параметр
#define internal1_m1087_q0	 BUFFER[3102]	//(internal1_m1087_q0) q0 - внутренний параметр
#define idinternal1_m1087_q0	 1103	//(internal1_m1087_q0) q0 - внутренний параметр
#define internal1_m1086_q0	 BUFFER[3104]	//(internal1_m1086_q0) q0 - внутренний параметр
#define idinternal1_m1086_q0	 1104	//(internal1_m1086_q0) q0 - внутренний параметр
#define internal1_m1084_q0	 BUFFER[3106]	//(internal1_m1084_q0) q0 - внутренний параметр
#define idinternal1_m1084_q0	 1105	//(internal1_m1084_q0) q0 - внутренний параметр
#define internal1_m1083_q0	 BUFFER[3108]	//(internal1_m1083_q0) q0 - внутренний параметр
#define idinternal1_m1083_q0	 1106	//(internal1_m1083_q0) q0 - внутренний параметр
#define internal1_m1081_q0	 BUFFER[3110]	//(internal1_m1081_q0) q0 - внутренний параметр
#define idinternal1_m1081_q0	 1107	//(internal1_m1081_q0) q0 - внутренний параметр
#define internal1_m1080_q0	 BUFFER[3112]	//(internal1_m1080_q0) q0 - внутренний параметр
#define idinternal1_m1080_q0	 1108	//(internal1_m1080_q0) q0 - внутренний параметр
#define internal1_m58_x0	 BUFFER[3114]	//(internal1_m58_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m58_x0	 1109	//(internal1_m58_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1000_q0	 BUFFER[3116]	//(internal1_m1000_q0) q0 - внутренний параметр
#define idinternal1_m1000_q0	 1110	//(internal1_m1000_q0) q0 - внутренний параметр
#define internal1_m1449_x0	 BUFFER[3118]	//(internal1_m1449_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1449_x0	 1111	//(internal1_m1449_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1493_x0	 BUFFER[3120]	//(internal1_m1493_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1493_x0	 1112	//(internal1_m1493_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1489_x0	 BUFFER[3122]	//(internal1_m1489_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1489_x0	 1113	//(internal1_m1489_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1907_x0	 BUFFER[3124]	//(internal1_m1907_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1907_x0	 1114	//(internal1_m1907_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1872_x0	 BUFFER[3126]	//(internal1_m1872_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1872_x0	 1115	//(internal1_m1872_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1039_q0	 BUFFER[3128]	//(internal1_m1039_q0) q0 - внутренний параметр
#define idinternal1_m1039_q0	 1116	//(internal1_m1039_q0) q0 - внутренний параметр
#define internal1_m1051_q0	 BUFFER[3130]	//(internal1_m1051_q0) q0 - внутренний параметр
#define idinternal1_m1051_q0	 1117	//(internal1_m1051_q0) q0 - внутренний параметр
#define internal1_m1063_q0	 BUFFER[3132]	//(internal1_m1063_q0) q0 - внутренний параметр
#define idinternal1_m1063_q0	 1118	//(internal1_m1063_q0) q0 - внутренний параметр
#define internal1_m1075_q0	 BUFFER[3134]	//(internal1_m1075_q0) q0 - внутренний параметр
#define idinternal1_m1075_q0	 1119	//(internal1_m1075_q0) q0 - внутренний параметр
#define internal1_m1050_q0	 BUFFER[3136]	//(internal1_m1050_q0) q0 - внутренний параметр
#define idinternal1_m1050_q0	 1120	//(internal1_m1050_q0) q0 - внутренний параметр
#define internal1_m1065_q0	 BUFFER[3138]	//(internal1_m1065_q0) q0 - внутренний параметр
#define idinternal1_m1065_q0	 1121	//(internal1_m1065_q0) q0 - внутренний параметр
#define internal1_m1965_q0	 BUFFER[3140]	//(internal1_m1965_q0) q0 - внутренний параметр
#define idinternal1_m1965_q0	 1122	//(internal1_m1965_q0) q0 - внутренний параметр
#define internal1_m1964_q0	 BUFFER[3142]	//(internal1_m1964_q0) q0 - внутренний параметр
#define idinternal1_m1964_q0	 1123	//(internal1_m1964_q0) q0 - внутренний параметр
#define internal1_m344_Step	 BUFFER[3144]	//(internal1_m344_Step)  - текущий шаг программы
#define idinternal1_m344_Step	 1124	//(internal1_m344_Step)  - текущий шаг программы
#define internal1_m344_rz	 BUFFER[3147]	//(internal1_m344_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m344_rz	 1125	//(internal1_m344_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m344_TimS	 BUFFER[3157]	//(internal1_m344_TimS) Время от старта программы
#define idinternal1_m344_TimS	 1126	//(internal1_m344_TimS) Время от старта программы
#define internal1_m344_FinPr0	 BUFFER[3162]	//(internal1_m344_FinPr0) FinPr - конец программы
#define idinternal1_m344_FinPr0	 1127	//(internal1_m344_FinPr0) FinPr - конец программы
#define internal1_m344_ErrPr0	 BUFFER[3164]	//(internal1_m344_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m344_ErrPr0	 1128	//(internal1_m344_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m344_sbINI0	 BUFFER[3166]	//(internal1_m344_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m344_sbINI0	 1129	//(internal1_m344_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m344_sbVuIS0	 BUFFER[3168]	//(internal1_m344_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m344_sbVuIS0	 1130	//(internal1_m344_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m344_sb2UR0	 BUFFER[3170]	//(internal1_m344_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m344_sb2UR0	 1131	//(internal1_m344_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m344_sbNupIS0	 BUFFER[3172]	//(internal1_m344_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m344_sbNupIS0	 1132	//(internal1_m344_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m344_sbVuRB0	 BUFFER[3174]	//(internal1_m344_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m344_sbVuRB0	 1133	//(internal1_m344_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m344_MyFirstEnterFlag	 BUFFER[3176]	//(internal1_m344_MyFirstEnterFlag)  
#define idinternal1_m344_MyFirstEnterFlag	 1134	//(internal1_m344_MyFirstEnterFlag)  
#define internal1_m352_x0	 BUFFER[3178]	//(internal1_m352_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m352_x0	 1135	//(internal1_m352_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m311_TimS	 BUFFER[3183]	//(internal1_m311_TimS) Время старта
#define idinternal1_m311_TimS	 1136	//(internal1_m311_TimS) Время старта
#define internal1_m287_Step	 BUFFER[3188]	//(internal1_m287_Step)  - текущий шаг программы
#define idinternal1_m287_Step	 1137	//(internal1_m287_Step)  - текущий шаг программы
#define internal1_m287_rz	 BUFFER[3191]	//(internal1_m287_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m287_rz	 1138	//(internal1_m287_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m287_TimS	 BUFFER[3201]	//(internal1_m287_TimS) Время от старта программы
#define idinternal1_m287_TimS	 1139	//(internal1_m287_TimS) Время от старта программы
#define internal1_m287_FinPr0	 BUFFER[3206]	//(internal1_m287_FinPr0) FinPr - конец программы
#define idinternal1_m287_FinPr0	 1140	//(internal1_m287_FinPr0) FinPr - конец программы
#define internal1_m287_ErrPr0	 BUFFER[3208]	//(internal1_m287_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m287_ErrPr0	 1141	//(internal1_m287_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m287_sbINI0	 BUFFER[3210]	//(internal1_m287_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m287_sbINI0	 1142	//(internal1_m287_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m287_sbVuIS0	 BUFFER[3212]	//(internal1_m287_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m287_sbVuIS0	 1143	//(internal1_m287_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m287_sb2UR0	 BUFFER[3214]	//(internal1_m287_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m287_sb2UR0	 1144	//(internal1_m287_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m287_sbNupIS0	 BUFFER[3216]	//(internal1_m287_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m287_sbNupIS0	 1145	//(internal1_m287_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m287_sbVuRB0	 BUFFER[3218]	//(internal1_m287_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m287_sbVuRB0	 1146	//(internal1_m287_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m287_MyFirstEnterFlag	 BUFFER[3220]	//(internal1_m287_MyFirstEnterFlag)  
#define idinternal1_m287_MyFirstEnterFlag	 1147	//(internal1_m287_MyFirstEnterFlag)  
#define internal1_m1423_q0	 BUFFER[3222]	//(internal1_m1423_q0) q0 - внутренний параметр
#define idinternal1_m1423_q0	 1148	//(internal1_m1423_q0) q0 - внутренний параметр
#define internal1_m1424_Step	 BUFFER[3224]	//(internal1_m1424_Step)  - текущий шаг программы
#define idinternal1_m1424_Step	 1149	//(internal1_m1424_Step)  - текущий шаг программы
#define internal1_m1424_rz	 BUFFER[3227]	//(internal1_m1424_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m1424_rz	 1150	//(internal1_m1424_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m1424_TimS	 BUFFER[3233]	//(internal1_m1424_TimS) Время от старта программы
#define idinternal1_m1424_TimS	 1151	//(internal1_m1424_TimS) Время от старта программы
#define internal1_m1424_FinPr0	 BUFFER[3238]	//(internal1_m1424_FinPr0) FinPr - конец программы
#define idinternal1_m1424_FinPr0	 1152	//(internal1_m1424_FinPr0) FinPr - конец программы
#define internal1_m1424_ErrPr0	 BUFFER[3240]	//(internal1_m1424_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m1424_ErrPr0	 1153	//(internal1_m1424_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m1424_sbINI0	 BUFFER[3242]	//(internal1_m1424_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m1424_sbINI0	 1154	//(internal1_m1424_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m1424_sbVuIS0	 BUFFER[3244]	//(internal1_m1424_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m1424_sbVuIS0	 1155	//(internal1_m1424_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m1424_sb2UR0	 BUFFER[3246]	//(internal1_m1424_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m1424_sb2UR0	 1156	//(internal1_m1424_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m1424_sbNupIS0	 BUFFER[3248]	//(internal1_m1424_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m1424_sbNupIS0	 1157	//(internal1_m1424_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m1424_sbVuRB0	 BUFFER[3250]	//(internal1_m1424_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m1424_sbVuRB0	 1158	//(internal1_m1424_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m1424_MyFirstEnterFlag	 BUFFER[3252]	//(internal1_m1424_MyFirstEnterFlag)  
#define idinternal1_m1424_MyFirstEnterFlag	 1159	//(internal1_m1424_MyFirstEnterFlag)  
#define internal1_m1034_q0	 BUFFER[3254]	//(internal1_m1034_q0) q0 - внутренний параметр
#define idinternal1_m1034_q0	 1160	//(internal1_m1034_q0) q0 - внутренний параметр
#define internal1_m1031_q0	 BUFFER[3256]	//(internal1_m1031_q0) q0 - внутренний параметр
#define idinternal1_m1031_q0	 1161	//(internal1_m1031_q0) q0 - внутренний параметр
#define internal1_m1033_q0	 BUFFER[3258]	//(internal1_m1033_q0) q0 - внутренний параметр
#define idinternal1_m1033_q0	 1162	//(internal1_m1033_q0) q0 - внутренний параметр
#define internal1_m1028_q0	 BUFFER[3260]	//(internal1_m1028_q0) q0 - внутренний параметр
#define idinternal1_m1028_q0	 1163	//(internal1_m1028_q0) q0 - внутренний параметр
#define internal1_m761_q0	 BUFFER[3262]	//(internal1_m761_q0) q0 - внутренний параметр
#define idinternal1_m761_q0	 1164	//(internal1_m761_q0) q0 - внутренний параметр
#define internal1_m354_q0	 BUFFER[3264]	//(internal1_m354_q0) q0 - внутренний параметр
#define idinternal1_m354_q0	 1165	//(internal1_m354_q0) q0 - внутренний параметр
#define internal1_m350_q0	 BUFFER[3266]	//(internal1_m350_q0) q0 - внутренний параметр
#define idinternal1_m350_q0	 1166	//(internal1_m350_q0) q0 - внутренний параметр
#define internal1_m307_q0	 BUFFER[3268]	//(internal1_m307_q0) q0 - внутренний параметр
#define idinternal1_m307_q0	 1167	//(internal1_m307_q0) q0 - внутренний параметр
#define internal1_m306_x0	 BUFFER[3270]	//(internal1_m306_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m306_x0	 1168	//(internal1_m306_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1894_q0	 BUFFER[3275]	//(internal1_m1894_q0) q0 - внутренний параметр
#define idinternal1_m1894_q0	 1169	//(internal1_m1894_q0) q0 - внутренний параметр
#define internal1_m1882_q0	 BUFFER[3277]	//(internal1_m1882_q0) q0 - внутренний параметр
#define idinternal1_m1882_q0	 1170	//(internal1_m1882_q0) q0 - внутренний параметр
#define internal1_m1873_q0	 BUFFER[3279]	//(internal1_m1873_q0) q0 - внутренний параметр
#define idinternal1_m1873_q0	 1171	//(internal1_m1873_q0) q0 - внутренний параметр
#define internal1_m1948_q0	 BUFFER[3281]	//(internal1_m1948_q0) q0 - внутренний параметр
#define idinternal1_m1948_q0	 1172	//(internal1_m1948_q0) q0 - внутренний параметр
#define internal1_m1919_q0	 BUFFER[3283]	//(internal1_m1919_q0) q0 - внутренний параметр
#define idinternal1_m1919_q0	 1173	//(internal1_m1919_q0) q0 - внутренний параметр
#define internal1_m1908_q0	 BUFFER[3285]	//(internal1_m1908_q0) q0 - внутренний параметр
#define idinternal1_m1908_q0	 1174	//(internal1_m1908_q0) q0 - внутренний параметр
#define internal1_m1476_q0	 BUFFER[3287]	//(internal1_m1476_q0) q0 - внутренний параметр
#define idinternal1_m1476_q0	 1175	//(internal1_m1476_q0) q0 - внутренний параметр
#define internal1_m1463_x0	 BUFFER[3289]	//(internal1_m1463_x0) был приход сигнала x1
#define idinternal1_m1463_x0	 1176	//(internal1_m1463_x0) был приход сигнала x1
#define internal1_m1463_y0	 BUFFER[3291]	//(internal1_m1463_y0) интервал между сигналами х1 и х2
#define idinternal1_m1463_y0	 1177	//(internal1_m1463_y0) интервал между сигналами х1 и х2
#define internal1_m1459_q0	 BUFFER[3296]	//(internal1_m1459_q0) q0 - внутренний параметр
#define idinternal1_m1459_q0	 1178	//(internal1_m1459_q0) q0 - внутренний параметр
#define internal1_m1450_q0	 BUFFER[3298]	//(internal1_m1450_q0) q0 - внутренний параметр
#define idinternal1_m1450_q0	 1179	//(internal1_m1450_q0) q0 - внутренний параметр
#define internal1_m1509_q0	 BUFFER[3300]	//(internal1_m1509_q0) q0 - внутренний параметр
#define idinternal1_m1509_q0	 1180	//(internal1_m1509_q0) q0 - внутренний параметр
#define internal1_m1529_q0	 BUFFER[3302]	//(internal1_m1529_q0) q0 - внутренний параметр
#define idinternal1_m1529_q0	 1181	//(internal1_m1529_q0) q0 - внутренний параметр
#define internal1_m1495_q0	 BUFFER[3304]	//(internal1_m1495_q0) q0 - внутренний параметр
#define idinternal1_m1495_q0	 1182	//(internal1_m1495_q0) q0 - внутренний параметр
#define internal1_m1510_x0	 BUFFER[3306]	//(internal1_m1510_x0) был приход сигнала x1
#define idinternal1_m1510_x0	 1183	//(internal1_m1510_x0) был приход сигнала x1
#define internal1_m1510_y0	 BUFFER[3308]	//(internal1_m1510_y0) интервал между сигналами х1 и х2
#define idinternal1_m1510_y0	 1184	//(internal1_m1510_y0) интервал между сигналами х1 и х2
#define internal1_m1434_x0	 BUFFER[3313]	//(internal1_m1434_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1434_x0	 1185	//(internal1_m1434_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1515_q0	 BUFFER[3318]	//(internal1_m1515_q0) q0 - внутренний параметр
#define idinternal1_m1515_q0	 1186	//(internal1_m1515_q0) q0 - внутренний параметр
#define internal1_m29_q0	 BUFFER[3320]	//(internal1_m29_q0) q0 - внутренний параметр
#define idinternal1_m29_q0	 1187	//(internal1_m29_q0) q0 - внутренний параметр
#define internal1_m1530_q0	 BUFFER[3322]	//(internal1_m1530_q0) q0 - внутренний параметр
#define idinternal1_m1530_q0	 1188	//(internal1_m1530_q0) q0 - внутренний параметр
#define internal1_m651_q0	 BUFFER[3324]	//(internal1_m651_q0) q0 - внутренний параметр
#define idinternal1_m651_q0	 1189	//(internal1_m651_q0) q0 - внутренний параметр
#define internal1_m636_q0	 BUFFER[3326]	//(internal1_m636_q0) q0 - внутренний параметр
#define idinternal1_m636_q0	 1190	//(internal1_m636_q0) q0 - внутренний параметр
#define internal1_m662_q0	 BUFFER[3328]	//(internal1_m662_q0) q0 - внутренний параметр
#define idinternal1_m662_q0	 1191	//(internal1_m662_q0) q0 - внутренний параметр
#define internal1_m647_q0	 BUFFER[3330]	//(internal1_m647_q0) q0 - внутренний параметр
#define idinternal1_m647_q0	 1192	//(internal1_m647_q0) q0 - внутренний параметр
#define internal1_m631_q0	 BUFFER[3332]	//(internal1_m631_q0) q0 - внутренний параметр
#define idinternal1_m631_q0	 1193	//(internal1_m631_q0) q0 - внутренний параметр
#define internal1_m629_q0	 BUFFER[3334]	//(internal1_m629_q0) q0 - внутренний параметр
#define idinternal1_m629_q0	 1194	//(internal1_m629_q0) q0 - внутренний параметр
#define internal1_m617_q0	 BUFFER[3336]	//(internal1_m617_q0) q0 - внутренний параметр
#define idinternal1_m617_q0	 1195	//(internal1_m617_q0) q0 - внутренний параметр
#define internal1_m1426_q0	 BUFFER[3338]	//(internal1_m1426_q0) q0 - внутренний параметр
#define idinternal1_m1426_q0	 1196	//(internal1_m1426_q0) q0 - внутренний параметр
#define internal1_m627_q0	 BUFFER[3343]	//(internal1_m627_q0) q0 - внутренний параметр
#define idinternal1_m627_q0	 1197	//(internal1_m627_q0) q0 - внутренний параметр
#define internal1_m115_q0	 BUFFER[3345]	//(internal1_m115_q0) q0 - внутренний параметр
#define idinternal1_m115_q0	 1198	//(internal1_m115_q0) q0 - внутренний параметр
#define internal1_m1662_q0	 BUFFER[3347]	//(internal1_m1662_q0) q0 - внутренний параметр
#define idinternal1_m1662_q0	 1199	//(internal1_m1662_q0) q0 - внутренний параметр
#define internal1_m1661_q0	 BUFFER[3349]	//(internal1_m1661_q0) q0 - внутренний параметр
#define idinternal1_m1661_q0	 1200	//(internal1_m1661_q0) q0 - внутренний параметр
#define internal1_m1660_q0	 BUFFER[3351]	//(internal1_m1660_q0) q0 - внутренний параметр
#define idinternal1_m1660_q0	 1201	//(internal1_m1660_q0) q0 - внутренний параметр
#define internal1_m1659_q0	 BUFFER[3353]	//(internal1_m1659_q0) q0 - внутренний параметр
#define idinternal1_m1659_q0	 1202	//(internal1_m1659_q0) q0 - внутренний параметр
#define internal1_m1697_q0	 BUFFER[3355]	//(internal1_m1697_q0) q0 - внутренний параметр
#define idinternal1_m1697_q0	 1203	//(internal1_m1697_q0) q0 - внутренний параметр
#define internal1_m1696_q0	 BUFFER[3357]	//(internal1_m1696_q0) q0 - внутренний параметр
#define idinternal1_m1696_q0	 1204	//(internal1_m1696_q0) q0 - внутренний параметр
#define internal1_m1695_q0	 BUFFER[3359]	//(internal1_m1695_q0) q0 - внутренний параметр
#define idinternal1_m1695_q0	 1205	//(internal1_m1695_q0) q0 - внутренний параметр
#define internal1_m1979_q0	 BUFFER[3361]	//(internal1_m1979_q0) q0 - внутренний параметр
#define idinternal1_m1979_q0	 1206	//(internal1_m1979_q0) q0 - внутренний параметр
#define internal1_m1757_q0	 BUFFER[3363]	//(internal1_m1757_q0) q0 - внутренний параметр
#define idinternal1_m1757_q0	 1207	//(internal1_m1757_q0) q0 - внутренний параметр
#define internal1_m1746_q0	 BUFFER[3365]	//(internal1_m1746_q0) q0 - внутренний параметр
#define idinternal1_m1746_q0	 1208	//(internal1_m1746_q0) q0 - внутренний параметр
#define internal1_m1754_q0	 BUFFER[3367]	//(internal1_m1754_q0) q0 - внутренний параметр
#define idinternal1_m1754_q0	 1209	//(internal1_m1754_q0) q0 - внутренний параметр
#define internal1_m1743_q0	 BUFFER[3369]	//(internal1_m1743_q0) q0 - внутренний параметр
#define idinternal1_m1743_q0	 1210	//(internal1_m1743_q0) q0 - внутренний параметр
#define internal1_m1751_q0	 BUFFER[3371]	//(internal1_m1751_q0) q0 - внутренний параметр
#define idinternal1_m1751_q0	 1211	//(internal1_m1751_q0) q0 - внутренний параметр
#define internal1_m2179_q0	 BUFFER[3373]	//(internal1_m2179_q0) q0 - внутренний параметр
#define idinternal1_m2179_q0	 1212	//(internal1_m2179_q0) q0 - внутренний параметр
#define internal1_m2175_q0	 BUFFER[3375]	//(internal1_m2175_q0) q0 - внутренний параметр
#define idinternal1_m2175_q0	 1213	//(internal1_m2175_q0) q0 - внутренний параметр
#define internal1_m1722_q0	 BUFFER[3377]	//(internal1_m1722_q0) q0 - внутренний параметр
#define idinternal1_m1722_q0	 1214	//(internal1_m1722_q0) q0 - внутренний параметр
#define internal1_m1714_q0	 BUFFER[3379]	//(internal1_m1714_q0) q0 - внутренний параметр
#define idinternal1_m1714_q0	 1215	//(internal1_m1714_q0) q0 - внутренний параметр
#define internal1_m1712_q0	 BUFFER[3381]	//(internal1_m1712_q0) q0 - внутренний параметр
#define idinternal1_m1712_q0	 1216	//(internal1_m1712_q0) q0 - внутренний параметр
#define internal1_m1708_q0	 BUFFER[3383]	//(internal1_m1708_q0) q0 - внутренний параметр
#define idinternal1_m1708_q0	 1217	//(internal1_m1708_q0) q0 - внутренний параметр
#define internal1_m1704_q0	 BUFFER[3385]	//(internal1_m1704_q0) q0 - внутренний параметр
#define idinternal1_m1704_q0	 1218	//(internal1_m1704_q0) q0 - внутренний параметр
#define internal1_m1706_q0	 BUFFER[3387]	//(internal1_m1706_q0) q0 - внутренний параметр
#define idinternal1_m1706_q0	 1219	//(internal1_m1706_q0) q0 - внутренний параметр
#define internal1_m22_q0	 BUFFER[3389]	//(internal1_m22_q0) q0 - внутренний параметр
#define idinternal1_m22_q0	 1220	//(internal1_m22_q0) q0 - внутренний параметр
#define internal1_m1685_q0	 BUFFER[3391]	//(internal1_m1685_q0) q0 - внутренний параметр
#define idinternal1_m1685_q0	 1221	//(internal1_m1685_q0) q0 - внутренний параметр
#define internal1_m1683_q0	 BUFFER[3393]	//(internal1_m1683_q0) q0 - внутренний параметр
#define idinternal1_m1683_q0	 1222	//(internal1_m1683_q0) q0 - внутренний параметр
#define internal1_m1679_q0	 BUFFER[3395]	//(internal1_m1679_q0) q0 - внутренний параметр
#define idinternal1_m1679_q0	 1223	//(internal1_m1679_q0) q0 - внутренний параметр
#define internal1_m1681_q0	 BUFFER[3397]	//(internal1_m1681_q0) q0 - внутренний параметр
#define idinternal1_m1681_q0	 1224	//(internal1_m1681_q0) q0 - внутренний параметр
#define internal1_m1677_q0	 BUFFER[3399]	//(internal1_m1677_q0) q0 - внутренний параметр
#define idinternal1_m1677_q0	 1225	//(internal1_m1677_q0) q0 - внутренний параметр
#define internal1_m1675_q0	 BUFFER[3401]	//(internal1_m1675_q0) q0 - внутренний параметр
#define idinternal1_m1675_q0	 1226	//(internal1_m1675_q0) q0 - внутренний параметр
#define internal1_m2095_q0	 BUFFER[3403]	//(internal1_m2095_q0) q0 - внутренний параметр
#define idinternal1_m2095_q0	 1227	//(internal1_m2095_q0) q0 - внутренний параметр
#define internal1_m2090_q0	 BUFFER[3405]	//(internal1_m2090_q0) q0 - внутренний параметр
#define idinternal1_m2090_q0	 1228	//(internal1_m2090_q0) q0 - внутренний параметр
#define internal1_m2069_q0	 BUFFER[3407]	//(internal1_m2069_q0) q0 - внутренний параметр
#define idinternal1_m2069_q0	 1229	//(internal1_m2069_q0) q0 - внутренний параметр
#define internal1_m2057_q0	 BUFFER[3409]	//(internal1_m2057_q0) q0 - внутренний параметр
#define idinternal1_m2057_q0	 1230	//(internal1_m2057_q0) q0 - внутренний параметр
#define internal1_m1990_q0	 BUFFER[3411]	//(internal1_m1990_q0) q0 - внутренний параметр
#define idinternal1_m1990_q0	 1231	//(internal1_m1990_q0) q0 - внутренний параметр
#define internal1_m1671_q0	 BUFFER[3413]	//(internal1_m1671_q0) q0 - внутренний параметр
#define idinternal1_m1671_q0	 1232	//(internal1_m1671_q0) q0 - внутренний параметр
#define internal1_m1673_q0	 BUFFER[3415]	//(internal1_m1673_q0) q0 - внутренний параметр
#define idinternal1_m1673_q0	 1233	//(internal1_m1673_q0) q0 - внутренний параметр
#define internal1_m1657_q0	 BUFFER[3417]	//(internal1_m1657_q0) q0 - внутренний параметр
#define idinternal1_m1657_q0	 1234	//(internal1_m1657_q0) q0 - внутренний параметр
#define internal1_m1655_q0	 BUFFER[3419]	//(internal1_m1655_q0) q0 - внутренний параметр
#define idinternal1_m1655_q0	 1235	//(internal1_m1655_q0) q0 - внутренний параметр
#define internal1_m1653_q0	 BUFFER[3421]	//(internal1_m1653_q0) q0 - внутренний параметр
#define idinternal1_m1653_q0	 1236	//(internal1_m1653_q0) q0 - внутренний параметр
#define internal1_m1651_q0	 BUFFER[3423]	//(internal1_m1651_q0) q0 - внутренний параметр
#define idinternal1_m1651_q0	 1237	//(internal1_m1651_q0) q0 - внутренний параметр
#define internal1_m1650_q0	 BUFFER[3425]	//(internal1_m1650_q0) q0 - внутренний параметр
#define idinternal1_m1650_q0	 1238	//(internal1_m1650_q0) q0 - внутренний параметр
#define internal1_m1648_q0	 BUFFER[3427]	//(internal1_m1648_q0) q0 - внутренний параметр
#define idinternal1_m1648_q0	 1239	//(internal1_m1648_q0) q0 - внутренний параметр
#define internal1_m1647_q0	 BUFFER[3429]	//(internal1_m1647_q0) q0 - внутренний параметр
#define idinternal1_m1647_q0	 1240	//(internal1_m1647_q0) q0 - внутренний параметр
#define internal1_m1645_q0	 BUFFER[3431]	//(internal1_m1645_q0) q0 - внутренний параметр
#define idinternal1_m1645_q0	 1241	//(internal1_m1645_q0) q0 - внутренний параметр
#define internal1_m2118_DvUp0	 BUFFER[3433]	//(internal1_m2118_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2118_DvUp0	 1242	//(internal1_m2118_DvUp0) - есть команда на движение вперёд
#define internal1_m2118_DvDw0	 BUFFER[3434]	//(internal1_m2118_DvDw0) - есть команда на движение назад
#define idinternal1_m2118_DvDw0	 1243	//(internal1_m2118_DvDw0) - есть команда на движение назад
#define internal1_m2118_FDvUp0	 BUFFER[3435]	//(internal1_m2118_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2118_FDvUp0	 1244	//(internal1_m2118_FDvUp0) - есть команда на движение вперёд
#define internal1_m2118_FDvDw0	 BUFFER[3436]	//(internal1_m2118_FDvDw0) - есть команда на движение назад
#define idinternal1_m2118_FDvDw0	 1245	//(internal1_m2118_FDvDw0) - есть команда на движение назад
#define internal1_m2118_BlDv0	 BUFFER[3437]	//(internal1_m2118_BlDv0) - была блокировка
#define idinternal1_m2118_BlDv0	 1246	//(internal1_m2118_BlDv0) - была блокировка
#define internal1_m2118_Pkv0	 BUFFER[3438]	//(internal1_m2118_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2118_Pkv0	 1247	//(internal1_m2118_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2118_Pkav0	 BUFFER[3439]	//(internal1_m2118_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2118_Pkav0	 1248	//(internal1_m2118_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2118_Zkv0	 BUFFER[3440]	//(internal1_m2118_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2118_Zkv0	 1249	//(internal1_m2118_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2118_Zkav0	 BUFFER[3441]	//(internal1_m2118_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2118_Zkav0	 1250	//(internal1_m2118_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2118_txNm	 BUFFER[3442]	//(internal1_m2118_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2118_txNm	 1251	//(internal1_m2118_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2118_txSm	 BUFFER[3447]	//(internal1_m2118_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2118_txSm	 1252	//(internal1_m2118_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2118_txHr	 BUFFER[3452]	//(internal1_m2118_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2118_txHr	 1253	//(internal1_m2118_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2118_txLd	 BUFFER[3457]	//(internal1_m2118_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2118_txLd	 1254	//(internal1_m2118_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2118_fef	 BUFFER[3462]	//(internal1_m2118_fef) fef
#define idinternal1_m2118_fef	 1255	//(internal1_m2118_fef) fef
#define internal1_m2112_DvUp0	 BUFFER[3463]	//(internal1_m2112_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2112_DvUp0	 1256	//(internal1_m2112_DvUp0) - есть команда на движение вперёд
#define internal1_m2112_DvDw0	 BUFFER[3464]	//(internal1_m2112_DvDw0) - есть команда на движение назад
#define idinternal1_m2112_DvDw0	 1257	//(internal1_m2112_DvDw0) - есть команда на движение назад
#define internal1_m2112_FDvUp0	 BUFFER[3465]	//(internal1_m2112_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2112_FDvUp0	 1258	//(internal1_m2112_FDvUp0) - есть команда на движение вперёд
#define internal1_m2112_FDvDw0	 BUFFER[3466]	//(internal1_m2112_FDvDw0) - есть команда на движение назад
#define idinternal1_m2112_FDvDw0	 1259	//(internal1_m2112_FDvDw0) - есть команда на движение назад
#define internal1_m2112_BlDv0	 BUFFER[3467]	//(internal1_m2112_BlDv0) - была блокировка
#define idinternal1_m2112_BlDv0	 1260	//(internal1_m2112_BlDv0) - была блокировка
#define internal1_m2112_Pkv0	 BUFFER[3468]	//(internal1_m2112_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2112_Pkv0	 1261	//(internal1_m2112_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2112_Pkav0	 BUFFER[3469]	//(internal1_m2112_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2112_Pkav0	 1262	//(internal1_m2112_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2112_Zkv0	 BUFFER[3470]	//(internal1_m2112_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2112_Zkv0	 1263	//(internal1_m2112_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2112_Zkav0	 BUFFER[3471]	//(internal1_m2112_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2112_Zkav0	 1264	//(internal1_m2112_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2112_txNm	 BUFFER[3472]	//(internal1_m2112_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2112_txNm	 1265	//(internal1_m2112_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2112_txSm	 BUFFER[3477]	//(internal1_m2112_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2112_txSm	 1266	//(internal1_m2112_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2112_txHr	 BUFFER[3482]	//(internal1_m2112_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2112_txHr	 1267	//(internal1_m2112_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2112_txLd	 BUFFER[3487]	//(internal1_m2112_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2112_txLd	 1268	//(internal1_m2112_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2112_fef	 BUFFER[3492]	//(internal1_m2112_fef) fef
#define idinternal1_m2112_fef	 1269	//(internal1_m2112_fef) fef
#define internal1_m1501_q0	 BUFFER[3493]	//(internal1_m1501_q0) q0 - внутренний параметр
#define idinternal1_m1501_q0	 1270	//(internal1_m1501_q0) q0 - внутренний параметр
#define internal1_m1504_x0	 BUFFER[3495]	//(internal1_m1504_x0) был приход сигнала x1
#define idinternal1_m1504_x0	 1271	//(internal1_m1504_x0) был приход сигнала x1
#define internal1_m1504_y0	 BUFFER[3497]	//(internal1_m1504_y0) интервал между сигналами х1 и х2
#define idinternal1_m1504_y0	 1272	//(internal1_m1504_y0) интервал между сигналами х1 и х2
#define internal1_m1930_x0	 BUFFER[3502]	//(internal1_m1930_x0) был приход сигнала x1
#define idinternal1_m1930_x0	 1273	//(internal1_m1930_x0) был приход сигнала x1
#define internal1_m1930_y0	 BUFFER[3504]	//(internal1_m1930_y0) интервал между сигналами х1 и х2
#define idinternal1_m1930_y0	 1274	//(internal1_m1930_y0) интервал между сигналами х1 и х2
#define internal1_m1891_x0	 BUFFER[3509]	//(internal1_m1891_x0) был приход сигнала x1
#define idinternal1_m1891_x0	 1275	//(internal1_m1891_x0) был приход сигнала x1
#define internal1_m1891_y0	 BUFFER[3511]	//(internal1_m1891_y0) интервал между сигналами х1 и х2
#define idinternal1_m1891_y0	 1276	//(internal1_m1891_y0) интервал между сигналами х1 и х2
#define internal1_m298_q0	 BUFFER[3516]	//(internal1_m298_q0) q0 - внутренний параметр
#define idinternal1_m298_q0	 1277	//(internal1_m298_q0) q0 - внутренний параметр
#define internal1_m1008_q0	 BUFFER[3518]	//(internal1_m1008_q0) q0 - внутренний параметр
#define idinternal1_m1008_q0	 1278	//(internal1_m1008_q0) q0 - внутренний параметр
#define internal1_m639_q0	 BUFFER[3520]	//(internal1_m639_q0) q0 - внутренний параметр
#define idinternal1_m639_q0	 1279	//(internal1_m639_q0) q0 - внутренний параметр
#define internal1_m1323_X0	 BUFFER[3522]	//(internal1_m1323_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1323_X0	 1280	//(internal1_m1323_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1323_t0	 BUFFER[3527]	//(internal1_m1323_t0) время нахождения в зоне возврата
#define idinternal1_m1323_t0	 1281	//(internal1_m1323_t0) время нахождения в зоне возврата
#define internal1_m1323_BLDv0	 BUFFER[3532]	//(internal1_m1323_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1323_BLDv0	 1282	//(internal1_m1323_BLDv0) BlDv - Блокировка движения
#define internal1_m1342_tx	 BUFFER[3533]	//(internal1_m1342_tx) tx - время накопленное сек
#define idinternal1_m1342_tx	 1283	//(internal1_m1342_tx) tx - время накопленное сек
#define internal1_m1342_y0	 BUFFER[3538]	//(internal1_m1342_y0) y0
#define idinternal1_m1342_y0	 1284	//(internal1_m1342_y0) y0
#define internal1_m1343_tx	 BUFFER[3539]	//(internal1_m1343_tx) tx - время накопленное сек
#define idinternal1_m1343_tx	 1285	//(internal1_m1343_tx) tx - время накопленное сек
#define internal1_m1343_y0	 BUFFER[3544]	//(internal1_m1343_y0) y0
#define idinternal1_m1343_y0	 1286	//(internal1_m1343_y0) y0
#define internal1_m1351_xptr	 BUFFER[3545]	//(internal1_m1351_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1351_xptr	 1287	//(internal1_m1351_xptr) указатель текущей позиции в массиве координат
#define internal1_m1351_x0	 BUFFER[3548]	//(internal1_m1351_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1351_x0	 1288	//(internal1_m1351_x0) x0 - массив мгновенных значений координат
#define internal1_m1351_tim0	 BUFFER[3848]	//(internal1_m1351_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1351_tim0	 1289	//(internal1_m1351_tim0) tim0 - массив значений времени цикла
#define internal1_m1351_sumtim	 BUFFER[4148]	//(internal1_m1351_sumtim) sumtim - время в пути
#define idinternal1_m1351_sumtim	 1290	//(internal1_m1351_sumtim) sumtim - время в пути
#define internal1_m1351_StSpeed	 BUFFER[4153]	//(internal1_m1351_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1351_StSpeed	 1291	//(internal1_m1351_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1351_Vz0	 BUFFER[4158]	//(internal1_m1351_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1351_Vz0	 1292	//(internal1_m1351_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1351_flRazg	 BUFFER[4163]	//(internal1_m1351_flRazg) признак разгона/торможения
#define idinternal1_m1351_flRazg	 1293	//(internal1_m1351_flRazg) признак разгона/торможения
#define internal1_m1351_DelSp	 BUFFER[4166]	//(internal1_m1351_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1351_DelSp	 1294	//(internal1_m1351_DelSp) DelSp - время переключения скоростей
#define internal1_m1351_z0	 BUFFER[4171]	//(internal1_m1351_z0) z0 - точка прекращения движения
#define idinternal1_m1351_z0	 1295	//(internal1_m1351_z0) z0 - точка прекращения движения
#define internal1_m1351_txZS	 BUFFER[4176]	//(internal1_m1351_txZS) txZS
#define idinternal1_m1351_txZS	 1296	//(internal1_m1351_txZS) txZS
#define internal1_m1351_tx	 BUFFER[4181]	//(internal1_m1351_tx) tx
#define idinternal1_m1351_tx	 1297	//(internal1_m1351_tx) tx
#define internal1_m1351_txd	 BUFFER[4186]	//(internal1_m1351_txd) txd
#define idinternal1_m1351_txd	 1298	//(internal1_m1351_txd) txd
#define internal1_m1351_txMBl	 BUFFER[4191]	//(internal1_m1351_txMBl) tx
#define idinternal1_m1351_txMBl	 1299	//(internal1_m1351_txMBl) tx
#define internal1_m1351_txBl	 BUFFER[4196]	//(internal1_m1351_txBl) tx
#define idinternal1_m1351_txBl	 1300	//(internal1_m1351_txBl) tx
#define internal1_m1351_Speed0	 BUFFER[4201]	//(internal1_m1351_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1351_Speed0	 1301	//(internal1_m1351_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1351_xz0	 BUFFER[4206]	//(internal1_m1351_xz0) xz0 - новое задание мм
#define idinternal1_m1351_xz0	 1302	//(internal1_m1351_xz0) xz0 - новое задание мм
#define internal1_m1351_tz0	 BUFFER[4211]	//(internal1_m1351_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1351_tz0	 1303	//(internal1_m1351_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1351_Shift0	 BUFFER[4216]	//(internal1_m1351_Shift0) Shift0 - признак самохода
#define idinternal1_m1351_Shift0	 1304	//(internal1_m1351_Shift0) Shift0 - признак самохода
#define internal1_m1351_ShCntlSp0	 BUFFER[4218]	//(internal1_m1351_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1351_ShCntlSp0	 1305	//(internal1_m1351_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1351_ShiftControl	 BUFFER[4220]	//(internal1_m1351_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1351_ShiftControl	 1306	//(internal1_m1351_ShiftControl) ShiftControl - признак самохода
#define internal1_m637_q0	 BUFFER[4222]	//(internal1_m637_q0) q0 - внутренний параметр
#define idinternal1_m637_q0	 1307	//(internal1_m637_q0) q0 - внутренний параметр
#define internal1_m906_X0	 BUFFER[4224]	//(internal1_m906_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m906_X0	 1308	//(internal1_m906_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m906_t0	 BUFFER[4229]	//(internal1_m906_t0) время нахождения в зоне возврата
#define idinternal1_m906_t0	 1309	//(internal1_m906_t0) время нахождения в зоне возврата
#define internal1_m906_BLDv0	 BUFFER[4234]	//(internal1_m906_BLDv0) BlDv - Блокировка движения
#define idinternal1_m906_BLDv0	 1310	//(internal1_m906_BLDv0) BlDv - Блокировка движения
#define internal1_m930_tx	 BUFFER[4235]	//(internal1_m930_tx) tx - время накопленное сек
#define idinternal1_m930_tx	 1311	//(internal1_m930_tx) tx - время накопленное сек
#define internal1_m930_y0	 BUFFER[4240]	//(internal1_m930_y0) y0
#define idinternal1_m930_y0	 1312	//(internal1_m930_y0) y0
#define internal1_m931_tx	 BUFFER[4241]	//(internal1_m931_tx) tx - время накопленное сек
#define idinternal1_m931_tx	 1313	//(internal1_m931_tx) tx - время накопленное сек
#define internal1_m931_y0	 BUFFER[4246]	//(internal1_m931_y0) y0
#define idinternal1_m931_y0	 1314	//(internal1_m931_y0) y0
#define internal1_m939_xptr	 BUFFER[4247]	//(internal1_m939_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m939_xptr	 1315	//(internal1_m939_xptr) указатель текущей позиции в массиве координат
#define internal1_m939_x0	 BUFFER[4250]	//(internal1_m939_x0) x0 - массив мгновенных значений координат
#define idinternal1_m939_x0	 1316	//(internal1_m939_x0) x0 - массив мгновенных значений координат
#define internal1_m939_tim0	 BUFFER[4550]	//(internal1_m939_tim0) tim0 - массив значений времени цикла
#define idinternal1_m939_tim0	 1317	//(internal1_m939_tim0) tim0 - массив значений времени цикла
#define internal1_m939_sumtim	 BUFFER[4850]	//(internal1_m939_sumtim) sumtim - время в пути
#define idinternal1_m939_sumtim	 1318	//(internal1_m939_sumtim) sumtim - время в пути
#define internal1_m939_StSpeed	 BUFFER[4855]	//(internal1_m939_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m939_StSpeed	 1319	//(internal1_m939_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m939_Vz0	 BUFFER[4860]	//(internal1_m939_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m939_Vz0	 1320	//(internal1_m939_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m939_flRazg	 BUFFER[4865]	//(internal1_m939_flRazg) признак разгона/торможения
#define idinternal1_m939_flRazg	 1321	//(internal1_m939_flRazg) признак разгона/торможения
#define internal1_m939_DelSp	 BUFFER[4868]	//(internal1_m939_DelSp) DelSp - время переключения скоростей
#define idinternal1_m939_DelSp	 1322	//(internal1_m939_DelSp) DelSp - время переключения скоростей
#define internal1_m939_z0	 BUFFER[4873]	//(internal1_m939_z0) z0 - точка прекращения движения
#define idinternal1_m939_z0	 1323	//(internal1_m939_z0) z0 - точка прекращения движения
#define internal1_m939_txZS	 BUFFER[4878]	//(internal1_m939_txZS) txZS
#define idinternal1_m939_txZS	 1324	//(internal1_m939_txZS) txZS
#define internal1_m939_tx	 BUFFER[4883]	//(internal1_m939_tx) tx
#define idinternal1_m939_tx	 1325	//(internal1_m939_tx) tx
#define internal1_m939_txd	 BUFFER[4888]	//(internal1_m939_txd) txd
#define idinternal1_m939_txd	 1326	//(internal1_m939_txd) txd
#define internal1_m939_txMBl	 BUFFER[4893]	//(internal1_m939_txMBl) tx
#define idinternal1_m939_txMBl	 1327	//(internal1_m939_txMBl) tx
#define internal1_m939_txBl	 BUFFER[4898]	//(internal1_m939_txBl) tx
#define idinternal1_m939_txBl	 1328	//(internal1_m939_txBl) tx
#define internal1_m939_Speed0	 BUFFER[4903]	//(internal1_m939_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m939_Speed0	 1329	//(internal1_m939_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m939_xz0	 BUFFER[4908]	//(internal1_m939_xz0) xz0 - новое задание мм
#define idinternal1_m939_xz0	 1330	//(internal1_m939_xz0) xz0 - новое задание мм
#define internal1_m939_tz0	 BUFFER[4913]	//(internal1_m939_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m939_tz0	 1331	//(internal1_m939_tz0) tz0 - время защиты от нового задания сек
#define internal1_m939_Shift0	 BUFFER[4918]	//(internal1_m939_Shift0) Shift0 - признак самохода
#define idinternal1_m939_Shift0	 1332	//(internal1_m939_Shift0) Shift0 - признак самохода
#define internal1_m939_ShCntlSp0	 BUFFER[4920]	//(internal1_m939_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m939_ShCntlSp0	 1333	//(internal1_m939_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m939_ShiftControl	 BUFFER[4922]	//(internal1_m939_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m939_ShiftControl	 1334	//(internal1_m939_ShiftControl) ShiftControl - признак самохода
#define internal1_m508_X0	 BUFFER[4924]	//(internal1_m508_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m508_X0	 1335	//(internal1_m508_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m508_t0	 BUFFER[4929]	//(internal1_m508_t0) время нахождения в зоне возврата
#define idinternal1_m508_t0	 1336	//(internal1_m508_t0) время нахождения в зоне возврата
#define internal1_m508_BLDv0	 BUFFER[4934]	//(internal1_m508_BLDv0) BlDv - Блокировка движения
#define idinternal1_m508_BLDv0	 1337	//(internal1_m508_BLDv0) BlDv - Блокировка движения
#define internal1_m528_tx	 BUFFER[4935]	//(internal1_m528_tx) tx - время накопленное сек
#define idinternal1_m528_tx	 1338	//(internal1_m528_tx) tx - время накопленное сек
#define internal1_m528_y0	 BUFFER[4940]	//(internal1_m528_y0) y0
#define idinternal1_m528_y0	 1339	//(internal1_m528_y0) y0
#define internal1_m529_tx	 BUFFER[4941]	//(internal1_m529_tx) tx - время накопленное сек
#define idinternal1_m529_tx	 1340	//(internal1_m529_tx) tx - время накопленное сек
#define internal1_m529_y0	 BUFFER[4946]	//(internal1_m529_y0) y0
#define idinternal1_m529_y0	 1341	//(internal1_m529_y0) y0
#define internal1_m535_xptr	 BUFFER[4947]	//(internal1_m535_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m535_xptr	 1342	//(internal1_m535_xptr) указатель текущей позиции в массиве координат
#define internal1_m535_x0	 BUFFER[4950]	//(internal1_m535_x0) x0 - массив мгновенных значений координат
#define idinternal1_m535_x0	 1343	//(internal1_m535_x0) x0 - массив мгновенных значений координат
#define internal1_m535_tim0	 BUFFER[5700]	//(internal1_m535_tim0) tim0 - массив значений времени цикла
#define idinternal1_m535_tim0	 1344	//(internal1_m535_tim0) tim0 - массив значений времени цикла
#define internal1_m535_sumtim	 BUFFER[6450]	//(internal1_m535_sumtim) sumtim - время в пути
#define idinternal1_m535_sumtim	 1345	//(internal1_m535_sumtim) sumtim - время в пути
#define internal1_m535_StSpeed	 BUFFER[6455]	//(internal1_m535_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m535_StSpeed	 1346	//(internal1_m535_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m535_Vz0	 BUFFER[6460]	//(internal1_m535_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m535_Vz0	 1347	//(internal1_m535_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m535_flRazg	 BUFFER[6465]	//(internal1_m535_flRazg) признак разгона/торможения
#define idinternal1_m535_flRazg	 1348	//(internal1_m535_flRazg) признак разгона/торможения
#define internal1_m535_DelSp	 BUFFER[6468]	//(internal1_m535_DelSp) DelSp - время переключения скоростей
#define idinternal1_m535_DelSp	 1349	//(internal1_m535_DelSp) DelSp - время переключения скоростей
#define internal1_m535_z0	 BUFFER[6473]	//(internal1_m535_z0) z0 - точка прекращения движения
#define idinternal1_m535_z0	 1350	//(internal1_m535_z0) z0 - точка прекращения движения
#define internal1_m535_txZS	 BUFFER[6478]	//(internal1_m535_txZS) txZS
#define idinternal1_m535_txZS	 1351	//(internal1_m535_txZS) txZS
#define internal1_m535_tx	 BUFFER[6483]	//(internal1_m535_tx) tx
#define idinternal1_m535_tx	 1352	//(internal1_m535_tx) tx
#define internal1_m535_txd	 BUFFER[6488]	//(internal1_m535_txd) txd
#define idinternal1_m535_txd	 1353	//(internal1_m535_txd) txd
#define internal1_m535_txMBl	 BUFFER[6493]	//(internal1_m535_txMBl) tx
#define idinternal1_m535_txMBl	 1354	//(internal1_m535_txMBl) tx
#define internal1_m535_txBl	 BUFFER[6498]	//(internal1_m535_txBl) tx
#define idinternal1_m535_txBl	 1355	//(internal1_m535_txBl) tx
#define internal1_m535_Speed0	 BUFFER[6503]	//(internal1_m535_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m535_Speed0	 1356	//(internal1_m535_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m535_xz0	 BUFFER[6508]	//(internal1_m535_xz0) xz0 - новое задание мм
#define idinternal1_m535_xz0	 1357	//(internal1_m535_xz0) xz0 - новое задание мм
#define internal1_m535_tz0	 BUFFER[6513]	//(internal1_m535_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m535_tz0	 1358	//(internal1_m535_tz0) tz0 - время защиты от нового задания сек
#define internal1_m535_Shift0	 BUFFER[6518]	//(internal1_m535_Shift0) Shift0 - признак самохода
#define idinternal1_m535_Shift0	 1359	//(internal1_m535_Shift0) Shift0 - признак самохода
#define internal1_m535_ShCntlSp0	 BUFFER[6520]	//(internal1_m535_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m535_ShCntlSp0	 1360	//(internal1_m535_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m535_ShiftControl	 BUFFER[6522]	//(internal1_m535_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m535_ShiftControl	 1361	//(internal1_m535_ShiftControl) ShiftControl - признак самохода
#define internal1_m634_q0	 BUFFER[6524]	//(internal1_m634_q0) q0 - внутренний параметр
#define idinternal1_m634_q0	 1362	//(internal1_m634_q0) q0 - внутренний параметр
#define internal1_m174_X0	 BUFFER[6526]	//(internal1_m174_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m174_X0	 1363	//(internal1_m174_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m174_t0	 BUFFER[6531]	//(internal1_m174_t0) время нахождения в зоне возврата
#define idinternal1_m174_t0	 1364	//(internal1_m174_t0) время нахождения в зоне возврата
#define internal1_m174_BLDv0	 BUFFER[6536]	//(internal1_m174_BLDv0) BlDv - Блокировка движения
#define idinternal1_m174_BLDv0	 1365	//(internal1_m174_BLDv0) BlDv - Блокировка движения
#define internal1_m213_xptr	 BUFFER[6537]	//(internal1_m213_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m213_xptr	 1366	//(internal1_m213_xptr) указатель текущей позиции в массиве координат
#define internal1_m213_x0	 BUFFER[6540]	//(internal1_m213_x0) x0 - массив мгновенных значений координат
#define idinternal1_m213_x0	 1367	//(internal1_m213_x0) x0 - массив мгновенных значений координат
#define internal1_m213_tim0	 BUFFER[7290]	//(internal1_m213_tim0) tim0 - массив значений времени цикла
#define idinternal1_m213_tim0	 1368	//(internal1_m213_tim0) tim0 - массив значений времени цикла
#define internal1_m213_sumtim	 BUFFER[8040]	//(internal1_m213_sumtim) sumtim - время в пути
#define idinternal1_m213_sumtim	 1369	//(internal1_m213_sumtim) sumtim - время в пути
#define internal1_m213_StSpeed	 BUFFER[8045]	//(internal1_m213_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m213_StSpeed	 1370	//(internal1_m213_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m213_Vz0	 BUFFER[8050]	//(internal1_m213_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m213_Vz0	 1371	//(internal1_m213_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m213_flRazg	 BUFFER[8055]	//(internal1_m213_flRazg) признак разгона/торможения
#define idinternal1_m213_flRazg	 1372	//(internal1_m213_flRazg) признак разгона/торможения
#define internal1_m213_DelSp	 BUFFER[8058]	//(internal1_m213_DelSp) DelSp - время переключения скоростей
#define idinternal1_m213_DelSp	 1373	//(internal1_m213_DelSp) DelSp - время переключения скоростей
#define internal1_m213_z0	 BUFFER[8063]	//(internal1_m213_z0) z0 - точка прекращения движения
#define idinternal1_m213_z0	 1374	//(internal1_m213_z0) z0 - точка прекращения движения
#define internal1_m213_txZS	 BUFFER[8068]	//(internal1_m213_txZS) txZS
#define idinternal1_m213_txZS	 1375	//(internal1_m213_txZS) txZS
#define internal1_m213_tx	 BUFFER[8073]	//(internal1_m213_tx) tx
#define idinternal1_m213_tx	 1376	//(internal1_m213_tx) tx
#define internal1_m213_txd	 BUFFER[8078]	//(internal1_m213_txd) txd
#define idinternal1_m213_txd	 1377	//(internal1_m213_txd) txd
#define internal1_m213_txMBl	 BUFFER[8083]	//(internal1_m213_txMBl) tx
#define idinternal1_m213_txMBl	 1378	//(internal1_m213_txMBl) tx
#define internal1_m213_txBl	 BUFFER[8088]	//(internal1_m213_txBl) tx
#define idinternal1_m213_txBl	 1379	//(internal1_m213_txBl) tx
#define internal1_m213_Speed0	 BUFFER[8093]	//(internal1_m213_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m213_Speed0	 1380	//(internal1_m213_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m213_xz0	 BUFFER[8098]	//(internal1_m213_xz0) xz0 - новое задание мм
#define idinternal1_m213_xz0	 1381	//(internal1_m213_xz0) xz0 - новое задание мм
#define internal1_m213_tz0	 BUFFER[8103]	//(internal1_m213_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m213_tz0	 1382	//(internal1_m213_tz0) tz0 - время защиты от нового задания сек
#define internal1_m213_Shift0	 BUFFER[8108]	//(internal1_m213_Shift0) Shift0 - признак самохода
#define idinternal1_m213_Shift0	 1383	//(internal1_m213_Shift0) Shift0 - признак самохода
#define internal1_m213_ShCntlSp0	 BUFFER[8110]	//(internal1_m213_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m213_ShCntlSp0	 1384	//(internal1_m213_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m213_ShiftControl	 BUFFER[8112]	//(internal1_m213_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m213_ShiftControl	 1385	//(internal1_m213_ShiftControl) ShiftControl - признак самохода
#define internal1_m660_q0	 BUFFER[8114]	//(internal1_m660_q0) q0 - внутренний параметр
#define idinternal1_m660_q0	 1386	//(internal1_m660_q0) q0 - внутренний параметр
#define internal1_m479_DvUp0	 BUFFER[8116]	//(internal1_m479_DvUp0) - есть команда на движение вперёд
#define idinternal1_m479_DvUp0	 1387	//(internal1_m479_DvUp0) - есть команда на движение вперёд
#define internal1_m479_DvDw0	 BUFFER[8117]	//(internal1_m479_DvDw0) - есть команда на движение назад
#define idinternal1_m479_DvDw0	 1388	//(internal1_m479_DvDw0) - есть команда на движение назад
#define internal1_m479_FDvUp0	 BUFFER[8118]	//(internal1_m479_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m479_FDvUp0	 1389	//(internal1_m479_FDvUp0) - есть команда на движение вперёд
#define internal1_m479_FDvDw0	 BUFFER[8119]	//(internal1_m479_FDvDw0) - есть команда на движение назад
#define idinternal1_m479_FDvDw0	 1390	//(internal1_m479_FDvDw0) - есть команда на движение назад
#define internal1_m479_BlDv0	 BUFFER[8120]	//(internal1_m479_BlDv0) - была блокировка
#define idinternal1_m479_BlDv0	 1391	//(internal1_m479_BlDv0) - была блокировка
#define internal1_m479_Pkv0	 BUFFER[8121]	//(internal1_m479_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m479_Pkv0	 1392	//(internal1_m479_Pkv0) Pkv - передний конечный выключатель
#define internal1_m479_Pkav0	 BUFFER[8122]	//(internal1_m479_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m479_Pkav0	 1393	//(internal1_m479_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m479_Zkv0	 BUFFER[8123]	//(internal1_m479_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m479_Zkv0	 1394	//(internal1_m479_Zkv0) Zkv - задний конечный выключатель
#define internal1_m479_Zkav0	 BUFFER[8124]	//(internal1_m479_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m479_Zkav0	 1395	//(internal1_m479_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m479_txNm	 BUFFER[8125]	//(internal1_m479_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m479_txNm	 1396	//(internal1_m479_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m479_txSm	 BUFFER[8130]	//(internal1_m479_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m479_txSm	 1397	//(internal1_m479_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m479_txHr	 BUFFER[8135]	//(internal1_m479_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m479_txHr	 1398	//(internal1_m479_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m479_txLd	 BUFFER[8140]	//(internal1_m479_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m479_txLd	 1399	//(internal1_m479_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m479_fef	 BUFFER[8145]	//(internal1_m479_fef) fef
#define idinternal1_m479_fef	 1400	//(internal1_m479_fef) fef
#define internal1_m473_DvUp0	 BUFFER[8146]	//(internal1_m473_DvUp0) - есть команда на движение вперёд
#define idinternal1_m473_DvUp0	 1401	//(internal1_m473_DvUp0) - есть команда на движение вперёд
#define internal1_m473_DvDw0	 BUFFER[8147]	//(internal1_m473_DvDw0) - есть команда на движение назад
#define idinternal1_m473_DvDw0	 1402	//(internal1_m473_DvDw0) - есть команда на движение назад
#define internal1_m473_FDvUp0	 BUFFER[8148]	//(internal1_m473_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m473_FDvUp0	 1403	//(internal1_m473_FDvUp0) - есть команда на движение вперёд
#define internal1_m473_FDvDw0	 BUFFER[8149]	//(internal1_m473_FDvDw0) - есть команда на движение назад
#define idinternal1_m473_FDvDw0	 1404	//(internal1_m473_FDvDw0) - есть команда на движение назад
#define internal1_m473_BlDv0	 BUFFER[8150]	//(internal1_m473_BlDv0) - была блокировка
#define idinternal1_m473_BlDv0	 1405	//(internal1_m473_BlDv0) - была блокировка
#define internal1_m473_Pkv0	 BUFFER[8151]	//(internal1_m473_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m473_Pkv0	 1406	//(internal1_m473_Pkv0) Pkv - передний конечный выключатель
#define internal1_m473_Pkav0	 BUFFER[8152]	//(internal1_m473_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m473_Pkav0	 1407	//(internal1_m473_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m473_Zkv0	 BUFFER[8153]	//(internal1_m473_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m473_Zkv0	 1408	//(internal1_m473_Zkv0) Zkv - задний конечный выключатель
#define internal1_m473_Zkav0	 BUFFER[8154]	//(internal1_m473_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m473_Zkav0	 1409	//(internal1_m473_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m473_txNm	 BUFFER[8155]	//(internal1_m473_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m473_txNm	 1410	//(internal1_m473_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m473_txSm	 BUFFER[8160]	//(internal1_m473_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m473_txSm	 1411	//(internal1_m473_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m473_txHr	 BUFFER[8165]	//(internal1_m473_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m473_txHr	 1412	//(internal1_m473_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m473_txLd	 BUFFER[8170]	//(internal1_m473_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m473_txLd	 1413	//(internal1_m473_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m473_fef	 BUFFER[8175]	//(internal1_m473_fef) fef
#define idinternal1_m473_fef	 1414	//(internal1_m473_fef) fef
#define internal1_m826_X0	 BUFFER[8176]	//(internal1_m826_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m826_X0	 1415	//(internal1_m826_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m826_t0	 BUFFER[8181]	//(internal1_m826_t0) время нахождения в зоне возврата
#define idinternal1_m826_t0	 1416	//(internal1_m826_t0) время нахождения в зоне возврата
#define internal1_m826_BLDv0	 BUFFER[8186]	//(internal1_m826_BLDv0) BlDv - Блокировка движения
#define idinternal1_m826_BLDv0	 1417	//(internal1_m826_BLDv0) BlDv - Блокировка движения
#define internal1_m846_xptr	 BUFFER[8187]	//(internal1_m846_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m846_xptr	 1418	//(internal1_m846_xptr) указатель текущей позиции в массиве координат
#define internal1_m846_x0	 BUFFER[8190]	//(internal1_m846_x0) x0 - массив мгновенных значений координат
#define idinternal1_m846_x0	 1419	//(internal1_m846_x0) x0 - массив мгновенных значений координат
#define internal1_m846_tim0	 BUFFER[8590]	//(internal1_m846_tim0) tim0 - массив значений времени цикла
#define idinternal1_m846_tim0	 1420	//(internal1_m846_tim0) tim0 - массив значений времени цикла
#define internal1_m846_sumtim	 BUFFER[8990]	//(internal1_m846_sumtim) sumtim - время в пути
#define idinternal1_m846_sumtim	 1421	//(internal1_m846_sumtim) sumtim - время в пути
#define internal1_m846_StSpeed	 BUFFER[8995]	//(internal1_m846_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m846_StSpeed	 1422	//(internal1_m846_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m846_Vz0	 BUFFER[9000]	//(internal1_m846_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m846_Vz0	 1423	//(internal1_m846_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m846_flRazg	 BUFFER[9005]	//(internal1_m846_flRazg) признак разгона/торможения
#define idinternal1_m846_flRazg	 1424	//(internal1_m846_flRazg) признак разгона/торможения
#define internal1_m846_DelSp	 BUFFER[9008]	//(internal1_m846_DelSp) DelSp - время переключения скоростей
#define idinternal1_m846_DelSp	 1425	//(internal1_m846_DelSp) DelSp - время переключения скоростей
#define internal1_m846_z0	 BUFFER[9013]	//(internal1_m846_z0) z0 - точка прекращения движения
#define idinternal1_m846_z0	 1426	//(internal1_m846_z0) z0 - точка прекращения движения
#define internal1_m846_txZS	 BUFFER[9018]	//(internal1_m846_txZS) txZS
#define idinternal1_m846_txZS	 1427	//(internal1_m846_txZS) txZS
#define internal1_m846_tx	 BUFFER[9023]	//(internal1_m846_tx) tx
#define idinternal1_m846_tx	 1428	//(internal1_m846_tx) tx
#define internal1_m846_txd	 BUFFER[9028]	//(internal1_m846_txd) txd
#define idinternal1_m846_txd	 1429	//(internal1_m846_txd) txd
#define internal1_m846_txMBl	 BUFFER[9033]	//(internal1_m846_txMBl) tx
#define idinternal1_m846_txMBl	 1430	//(internal1_m846_txMBl) tx
#define internal1_m846_txBl	 BUFFER[9038]	//(internal1_m846_txBl) tx
#define idinternal1_m846_txBl	 1431	//(internal1_m846_txBl) tx
#define internal1_m846_Speed0	 BUFFER[9043]	//(internal1_m846_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m846_Speed0	 1432	//(internal1_m846_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m846_xz0	 BUFFER[9048]	//(internal1_m846_xz0) xz0 - новое задание мм
#define idinternal1_m846_xz0	 1433	//(internal1_m846_xz0) xz0 - новое задание мм
#define internal1_m846_tz0	 BUFFER[9053]	//(internal1_m846_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m846_tz0	 1434	//(internal1_m846_tz0) tz0 - время защиты от нового задания сек
#define internal1_m846_Shift0	 BUFFER[9058]	//(internal1_m846_Shift0) Shift0 - признак самохода
#define idinternal1_m846_Shift0	 1435	//(internal1_m846_Shift0) Shift0 - признак самохода
#define internal1_m846_ShCntlSp0	 BUFFER[9060]	//(internal1_m846_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m846_ShCntlSp0	 1436	//(internal1_m846_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m846_ShiftControl	 BUFFER[9062]	//(internal1_m846_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m846_ShiftControl	 1437	//(internal1_m846_ShiftControl) ShiftControl - признак самохода
#define internal1_m1605_X0	 BUFFER[9064]	//(internal1_m1605_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1605_X0	 1438	//(internal1_m1605_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1605_t0	 BUFFER[9069]	//(internal1_m1605_t0) время нахождения в зоне возврата
#define idinternal1_m1605_t0	 1439	//(internal1_m1605_t0) время нахождения в зоне возврата
#define internal1_m1605_BLDv0	 BUFFER[9074]	//(internal1_m1605_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1605_BLDv0	 1440	//(internal1_m1605_BLDv0) BlDv - Блокировка движения
#define internal1_m1126_X0	 BUFFER[9075]	//(internal1_m1126_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1126_X0	 1441	//(internal1_m1126_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1126_t0	 BUFFER[9080]	//(internal1_m1126_t0) время нахождения в зоне возврата
#define idinternal1_m1126_t0	 1442	//(internal1_m1126_t0) время нахождения в зоне возврата
#define internal1_m1126_BLDv0	 BUFFER[9085]	//(internal1_m1126_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1126_BLDv0	 1443	//(internal1_m1126_BLDv0) BlDv - Блокировка движения
#define internal1_m632_q0	 BUFFER[9086]	//(internal1_m632_q0) q0 - внутренний параметр
#define idinternal1_m632_q0	 1444	//(internal1_m632_q0) q0 - внутренний параметр
#define internal1_m1226_X0	 BUFFER[9088]	//(internal1_m1226_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1226_X0	 1445	//(internal1_m1226_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1226_t0	 BUFFER[9093]	//(internal1_m1226_t0) время нахождения в зоне возврата
#define idinternal1_m1226_t0	 1446	//(internal1_m1226_t0) время нахождения в зоне возврата
#define internal1_m1226_BLDv0	 BUFFER[9098]	//(internal1_m1226_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1226_BLDv0	 1447	//(internal1_m1226_BLDv0) BlDv - Блокировка движения
#define internal1_m1246_tx	 BUFFER[9099]	//(internal1_m1246_tx) tx - время накопленное сек
#define idinternal1_m1246_tx	 1448	//(internal1_m1246_tx) tx - время накопленное сек
#define internal1_m1246_y0	 BUFFER[9104]	//(internal1_m1246_y0) y0
#define idinternal1_m1246_y0	 1449	//(internal1_m1246_y0) y0
#define internal1_m1255_tx	 BUFFER[9105]	//(internal1_m1255_tx) tx - время накопленное сек
#define idinternal1_m1255_tx	 1450	//(internal1_m1255_tx) tx - время накопленное сек
#define internal1_m1255_y0	 BUFFER[9110]	//(internal1_m1255_y0) y0
#define idinternal1_m1255_y0	 1451	//(internal1_m1255_y0) y0
#define internal1_m1261_xptr	 BUFFER[9111]	//(internal1_m1261_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1261_xptr	 1452	//(internal1_m1261_xptr) указатель текущей позиции в массиве координат
#define internal1_m1261_x0	 BUFFER[9114]	//(internal1_m1261_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1261_x0	 1453	//(internal1_m1261_x0) x0 - массив мгновенных значений координат
#define internal1_m1261_tim0	 BUFFER[9514]	//(internal1_m1261_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1261_tim0	 1454	//(internal1_m1261_tim0) tim0 - массив значений времени цикла
#define internal1_m1261_sumtim	 BUFFER[9914]	//(internal1_m1261_sumtim) sumtim - время в пути
#define idinternal1_m1261_sumtim	 1455	//(internal1_m1261_sumtim) sumtim - время в пути
#define internal1_m1261_StSpeed	 BUFFER[9919]	//(internal1_m1261_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1261_StSpeed	 1456	//(internal1_m1261_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1261_Vz0	 BUFFER[9924]	//(internal1_m1261_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1261_Vz0	 1457	//(internal1_m1261_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1261_flRazg	 BUFFER[9929]	//(internal1_m1261_flRazg) признак разгона/торможения
#define idinternal1_m1261_flRazg	 1458	//(internal1_m1261_flRazg) признак разгона/торможения
#define internal1_m1261_DelSp	 BUFFER[9932]	//(internal1_m1261_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1261_DelSp	 1459	//(internal1_m1261_DelSp) DelSp - время переключения скоростей
#define internal1_m1261_z0	 BUFFER[9937]	//(internal1_m1261_z0) z0 - точка прекращения движения
#define idinternal1_m1261_z0	 1460	//(internal1_m1261_z0) z0 - точка прекращения движения
#define internal1_m1261_txZS	 BUFFER[9942]	//(internal1_m1261_txZS) txZS
#define idinternal1_m1261_txZS	 1461	//(internal1_m1261_txZS) txZS
#define internal1_m1261_tx	 BUFFER[9947]	//(internal1_m1261_tx) tx
#define idinternal1_m1261_tx	 1462	//(internal1_m1261_tx) tx
#define internal1_m1261_txd	 BUFFER[9952]	//(internal1_m1261_txd) txd
#define idinternal1_m1261_txd	 1463	//(internal1_m1261_txd) txd
#define internal1_m1261_txMBl	 BUFFER[9957]	//(internal1_m1261_txMBl) tx
#define idinternal1_m1261_txMBl	 1464	//(internal1_m1261_txMBl) tx
#define internal1_m1261_txBl	 BUFFER[9962]	//(internal1_m1261_txBl) tx
#define idinternal1_m1261_txBl	 1465	//(internal1_m1261_txBl) tx
#define internal1_m1261_Speed0	 BUFFER[9967]	//(internal1_m1261_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1261_Speed0	 1466	//(internal1_m1261_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1261_xz0	 BUFFER[9972]	//(internal1_m1261_xz0) xz0 - новое задание мм
#define idinternal1_m1261_xz0	 1467	//(internal1_m1261_xz0) xz0 - новое задание мм
#define internal1_m1261_tz0	 BUFFER[9977]	//(internal1_m1261_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1261_tz0	 1468	//(internal1_m1261_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1261_Shift0	 BUFFER[9982]	//(internal1_m1261_Shift0) Shift0 - признак самохода
#define idinternal1_m1261_Shift0	 1469	//(internal1_m1261_Shift0) Shift0 - признак самохода
#define internal1_m1261_ShCntlSp0	 BUFFER[9984]	//(internal1_m1261_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1261_ShCntlSp0	 1470	//(internal1_m1261_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1261_ShiftControl	 BUFFER[9986]	//(internal1_m1261_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1261_ShiftControl	 1471	//(internal1_m1261_ShiftControl) ShiftControl - признак самохода
#define internal1_m652_q0	 BUFFER[9988]	//(internal1_m652_q0) q0 - внутренний параметр
#define idinternal1_m652_q0	 1472	//(internal1_m652_q0) q0 - внутренний параметр
#define internal1_m1618_tx	 BUFFER[9990]	//(internal1_m1618_tx) tx - время накопленное сек
#define idinternal1_m1618_tx	 1473	//(internal1_m1618_tx) tx - время накопленное сек
#define internal1_m1618_y0	 BUFFER[9995]	//(internal1_m1618_y0) y0
#define idinternal1_m1618_y0	 1474	//(internal1_m1618_y0) y0
#define internal1_m1622_tx	 BUFFER[9996]	//(internal1_m1622_tx) tx - время накопленное сек
#define idinternal1_m1622_tx	 1475	//(internal1_m1622_tx) tx - время накопленное сек
#define internal1_m1622_y0	 BUFFER[10001]	//(internal1_m1622_y0) y0
#define idinternal1_m1622_y0	 1476	//(internal1_m1622_y0) y0
#define internal1_m1608_DvUp0	 BUFFER[10002]	//(internal1_m1608_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1608_DvUp0	 1477	//(internal1_m1608_DvUp0) - есть команда на движение вперёд
#define internal1_m1608_DvDw0	 BUFFER[10003]	//(internal1_m1608_DvDw0) - есть команда на движение назад
#define idinternal1_m1608_DvDw0	 1478	//(internal1_m1608_DvDw0) - есть команда на движение назад
#define internal1_m1608_FDvUp0	 BUFFER[10004]	//(internal1_m1608_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1608_FDvUp0	 1479	//(internal1_m1608_FDvUp0) - есть команда на движение вперёд
#define internal1_m1608_FDvDw0	 BUFFER[10005]	//(internal1_m1608_FDvDw0) - есть команда на движение назад
#define idinternal1_m1608_FDvDw0	 1480	//(internal1_m1608_FDvDw0) - есть команда на движение назад
#define internal1_m1608_BlDv0	 BUFFER[10006]	//(internal1_m1608_BlDv0) - была блокировка
#define idinternal1_m1608_BlDv0	 1481	//(internal1_m1608_BlDv0) - была блокировка
#define internal1_m1608_Pkv0	 BUFFER[10007]	//(internal1_m1608_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1608_Pkv0	 1482	//(internal1_m1608_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1608_Pkav0	 BUFFER[10008]	//(internal1_m1608_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1608_Pkav0	 1483	//(internal1_m1608_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1608_Zkv0	 BUFFER[10009]	//(internal1_m1608_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1608_Zkv0	 1484	//(internal1_m1608_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1608_Zkav0	 BUFFER[10010]	//(internal1_m1608_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1608_Zkav0	 1485	//(internal1_m1608_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1608_txNm	 BUFFER[10011]	//(internal1_m1608_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1608_txNm	 1486	//(internal1_m1608_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1608_txSm	 BUFFER[10016]	//(internal1_m1608_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1608_txSm	 1487	//(internal1_m1608_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1608_txHr	 BUFFER[10021]	//(internal1_m1608_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1608_txHr	 1488	//(internal1_m1608_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1608_txLd	 BUFFER[10026]	//(internal1_m1608_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1608_txLd	 1489	//(internal1_m1608_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1608_fef	 BUFFER[10031]	//(internal1_m1608_fef) fef
#define idinternal1_m1608_fef	 1490	//(internal1_m1608_fef) fef
#define internal1_m1625_xptr	 BUFFER[10032]	//(internal1_m1625_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1625_xptr	 1491	//(internal1_m1625_xptr) указатель текущей позиции в массиве координат
#define internal1_m1625_x0	 BUFFER[10035]	//(internal1_m1625_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1625_x0	 1492	//(internal1_m1625_x0) x0 - массив мгновенных значений координат
#define internal1_m1625_tim0	 BUFFER[10135]	//(internal1_m1625_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1625_tim0	 1493	//(internal1_m1625_tim0) tim0 - массив значений времени цикла
#define internal1_m1625_sumtim	 BUFFER[10235]	//(internal1_m1625_sumtim) sumtim - время в пути
#define idinternal1_m1625_sumtim	 1494	//(internal1_m1625_sumtim) sumtim - время в пути
#define internal1_m1625_StSpeed	 BUFFER[10240]	//(internal1_m1625_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1625_StSpeed	 1495	//(internal1_m1625_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1625_Vz0	 BUFFER[10245]	//(internal1_m1625_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1625_Vz0	 1496	//(internal1_m1625_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1625_flRazg	 BUFFER[10250]	//(internal1_m1625_flRazg) признак разгона/торможения
#define idinternal1_m1625_flRazg	 1497	//(internal1_m1625_flRazg) признак разгона/торможения
#define internal1_m1625_DelSp	 BUFFER[10253]	//(internal1_m1625_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1625_DelSp	 1498	//(internal1_m1625_DelSp) DelSp - время переключения скоростей
#define internal1_m1625_z0	 BUFFER[10258]	//(internal1_m1625_z0) z0 - точка прекращения движения
#define idinternal1_m1625_z0	 1499	//(internal1_m1625_z0) z0 - точка прекращения движения
#define internal1_m1625_txZS	 BUFFER[10263]	//(internal1_m1625_txZS) txZS
#define idinternal1_m1625_txZS	 1500	//(internal1_m1625_txZS) txZS
#define internal1_m1625_tx	 BUFFER[10268]	//(internal1_m1625_tx) tx
#define idinternal1_m1625_tx	 1501	//(internal1_m1625_tx) tx
#define internal1_m1625_txd	 BUFFER[10273]	//(internal1_m1625_txd) txd
#define idinternal1_m1625_txd	 1502	//(internal1_m1625_txd) txd
#define internal1_m1625_txMBl	 BUFFER[10278]	//(internal1_m1625_txMBl) tx
#define idinternal1_m1625_txMBl	 1503	//(internal1_m1625_txMBl) tx
#define internal1_m1625_txBl	 BUFFER[10283]	//(internal1_m1625_txBl) tx
#define idinternal1_m1625_txBl	 1504	//(internal1_m1625_txBl) tx
#define internal1_m1625_Speed0	 BUFFER[10288]	//(internal1_m1625_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1625_Speed0	 1505	//(internal1_m1625_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1625_xz0	 BUFFER[10293]	//(internal1_m1625_xz0) xz0 - новое задание мм
#define idinternal1_m1625_xz0	 1506	//(internal1_m1625_xz0) xz0 - новое задание мм
#define internal1_m1625_tz0	 BUFFER[10298]	//(internal1_m1625_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1625_tz0	 1507	//(internal1_m1625_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1625_Shift0	 BUFFER[10303]	//(internal1_m1625_Shift0) Shift0 - признак самохода
#define idinternal1_m1625_Shift0	 1508	//(internal1_m1625_Shift0) Shift0 - признак самохода
#define internal1_m1625_ShCntlSp0	 BUFFER[10305]	//(internal1_m1625_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1625_ShCntlSp0	 1509	//(internal1_m1625_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1625_ShiftControl	 BUFFER[10307]	//(internal1_m1625_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1625_ShiftControl	 1510	//(internal1_m1625_ShiftControl) ShiftControl - признак самохода
#define internal1_m1142_tx	 BUFFER[10309]	//(internal1_m1142_tx) tx - время накопленное сек
#define idinternal1_m1142_tx	 1511	//(internal1_m1142_tx) tx - время накопленное сек
#define internal1_m1142_y0	 BUFFER[10314]	//(internal1_m1142_y0) y0
#define idinternal1_m1142_y0	 1512	//(internal1_m1142_y0) y0
#define internal1_m1147_tx	 BUFFER[10315]	//(internal1_m1147_tx) tx - время накопленное сек
#define idinternal1_m1147_tx	 1513	//(internal1_m1147_tx) tx - время накопленное сек
#define internal1_m1147_y0	 BUFFER[10320]	//(internal1_m1147_y0) y0
#define idinternal1_m1147_y0	 1514	//(internal1_m1147_y0) y0
#define internal1_m642_q0	 BUFFER[10321]	//(internal1_m642_q0) q0 - внутренний параметр
#define idinternal1_m642_q0	 1515	//(internal1_m642_q0) q0 - внутренний параметр
#define internal1_m607_q0	 BUFFER[10323]	//(internal1_m607_q0) q0 - внутренний параметр
#define idinternal1_m607_q0	 1516	//(internal1_m607_q0) q0 - внутренний параметр
#define internal1_m1132_DvUp0	 BUFFER[10325]	//(internal1_m1132_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1132_DvUp0	 1517	//(internal1_m1132_DvUp0) - есть команда на движение вперёд
#define internal1_m1132_DvDw0	 BUFFER[10326]	//(internal1_m1132_DvDw0) - есть команда на движение назад
#define idinternal1_m1132_DvDw0	 1518	//(internal1_m1132_DvDw0) - есть команда на движение назад
#define internal1_m1132_FDvUp0	 BUFFER[10327]	//(internal1_m1132_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1132_FDvUp0	 1519	//(internal1_m1132_FDvUp0) - есть команда на движение вперёд
#define internal1_m1132_FDvDw0	 BUFFER[10328]	//(internal1_m1132_FDvDw0) - есть команда на движение назад
#define idinternal1_m1132_FDvDw0	 1520	//(internal1_m1132_FDvDw0) - есть команда на движение назад
#define internal1_m1132_BlDv0	 BUFFER[10329]	//(internal1_m1132_BlDv0) - была блокировка
#define idinternal1_m1132_BlDv0	 1521	//(internal1_m1132_BlDv0) - была блокировка
#define internal1_m1132_Pkv0	 BUFFER[10330]	//(internal1_m1132_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1132_Pkv0	 1522	//(internal1_m1132_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1132_Pkav0	 BUFFER[10331]	//(internal1_m1132_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1132_Pkav0	 1523	//(internal1_m1132_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1132_Zkv0	 BUFFER[10332]	//(internal1_m1132_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1132_Zkv0	 1524	//(internal1_m1132_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1132_Zkav0	 BUFFER[10333]	//(internal1_m1132_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1132_Zkav0	 1525	//(internal1_m1132_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1132_txNm	 BUFFER[10334]	//(internal1_m1132_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1132_txNm	 1526	//(internal1_m1132_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1132_txSm	 BUFFER[10339]	//(internal1_m1132_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1132_txSm	 1527	//(internal1_m1132_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1132_txHr	 BUFFER[10344]	//(internal1_m1132_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1132_txHr	 1528	//(internal1_m1132_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1132_txLd	 BUFFER[10349]	//(internal1_m1132_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1132_txLd	 1529	//(internal1_m1132_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1132_fef	 BUFFER[10354]	//(internal1_m1132_fef) fef
#define idinternal1_m1132_fef	 1530	//(internal1_m1132_fef) fef
#define internal1_m1150_xptr	 BUFFER[10355]	//(internal1_m1150_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1150_xptr	 1531	//(internal1_m1150_xptr) указатель текущей позиции в массиве координат
#define internal1_m1150_x0	 BUFFER[10358]	//(internal1_m1150_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1150_x0	 1532	//(internal1_m1150_x0) x0 - массив мгновенных значений координат
#define internal1_m1150_tim0	 BUFFER[10458]	//(internal1_m1150_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1150_tim0	 1533	//(internal1_m1150_tim0) tim0 - массив значений времени цикла
#define internal1_m1150_sumtim	 BUFFER[10558]	//(internal1_m1150_sumtim) sumtim - время в пути
#define idinternal1_m1150_sumtim	 1534	//(internal1_m1150_sumtim) sumtim - время в пути
#define internal1_m1150_StSpeed	 BUFFER[10563]	//(internal1_m1150_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1150_StSpeed	 1535	//(internal1_m1150_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1150_Vz0	 BUFFER[10568]	//(internal1_m1150_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1150_Vz0	 1536	//(internal1_m1150_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1150_flRazg	 BUFFER[10573]	//(internal1_m1150_flRazg) признак разгона/торможения
#define idinternal1_m1150_flRazg	 1537	//(internal1_m1150_flRazg) признак разгона/торможения
#define internal1_m1150_DelSp	 BUFFER[10576]	//(internal1_m1150_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1150_DelSp	 1538	//(internal1_m1150_DelSp) DelSp - время переключения скоростей
#define internal1_m1150_z0	 BUFFER[10581]	//(internal1_m1150_z0) z0 - точка прекращения движения
#define idinternal1_m1150_z0	 1539	//(internal1_m1150_z0) z0 - точка прекращения движения
#define internal1_m1150_txZS	 BUFFER[10586]	//(internal1_m1150_txZS) txZS
#define idinternal1_m1150_txZS	 1540	//(internal1_m1150_txZS) txZS
#define internal1_m1150_tx	 BUFFER[10591]	//(internal1_m1150_tx) tx
#define idinternal1_m1150_tx	 1541	//(internal1_m1150_tx) tx
#define internal1_m1150_txd	 BUFFER[10596]	//(internal1_m1150_txd) txd
#define idinternal1_m1150_txd	 1542	//(internal1_m1150_txd) txd
#define internal1_m1150_txMBl	 BUFFER[10601]	//(internal1_m1150_txMBl) tx
#define idinternal1_m1150_txMBl	 1543	//(internal1_m1150_txMBl) tx
#define internal1_m1150_txBl	 BUFFER[10606]	//(internal1_m1150_txBl) tx
#define idinternal1_m1150_txBl	 1544	//(internal1_m1150_txBl) tx
#define internal1_m1150_Speed0	 BUFFER[10611]	//(internal1_m1150_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1150_Speed0	 1545	//(internal1_m1150_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1150_xz0	 BUFFER[10616]	//(internal1_m1150_xz0) xz0 - новое задание мм
#define idinternal1_m1150_xz0	 1546	//(internal1_m1150_xz0) xz0 - новое задание мм
#define internal1_m1150_tz0	 BUFFER[10621]	//(internal1_m1150_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1150_tz0	 1547	//(internal1_m1150_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1150_Shift0	 BUFFER[10626]	//(internal1_m1150_Shift0) Shift0 - признак самохода
#define idinternal1_m1150_Shift0	 1548	//(internal1_m1150_Shift0) Shift0 - признак самохода
#define internal1_m1150_ShCntlSp0	 BUFFER[10628]	//(internal1_m1150_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1150_ShCntlSp0	 1549	//(internal1_m1150_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1150_ShiftControl	 BUFFER[10630]	//(internal1_m1150_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1150_ShiftControl	 1550	//(internal1_m1150_ShiftControl) ShiftControl - признак самохода
#define internal1_m755_x0	 BUFFER[10632]	//(internal1_m755_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m755_x0	 1551	//(internal1_m755_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m724_x0	 BUFFER[10634]	//(internal1_m724_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m724_x0	 1552	//(internal1_m724_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m688_x0	 BUFFER[10636]	//(internal1_m688_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m688_x0	 1553	//(internal1_m688_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m780_q0	 BUFFER[10638]	//(internal1_m780_q0) q0 - внутренний параметр
#define idinternal1_m780_q0	 1554	//(internal1_m780_q0) q0 - внутренний параметр
#define internal1_m775_q0	 BUFFER[10640]	//(internal1_m775_q0) q0 - внутренний параметр
#define idinternal1_m775_q0	 1555	//(internal1_m775_q0) q0 - внутренний параметр
#define internal1_m743_q0	 BUFFER[10642]	//(internal1_m743_q0) q0 - внутренний параметр
#define idinternal1_m743_q0	 1556	//(internal1_m743_q0) q0 - внутренний параметр
#define internal1_m747_q0	 BUFFER[10644]	//(internal1_m747_q0) q0 - внутренний параметр
#define idinternal1_m747_q0	 1557	//(internal1_m747_q0) q0 - внутренний параметр
#define internal1_m756_q0	 BUFFER[10646]	//(internal1_m756_q0) q0 - внутренний параметр
#define idinternal1_m756_q0	 1558	//(internal1_m756_q0) q0 - внутренний параметр
#define internal1_m768_q0	 BUFFER[10648]	//(internal1_m768_q0) q0 - внутренний параметр
#define idinternal1_m768_q0	 1559	//(internal1_m768_q0) q0 - внутренний параметр
#define internal1_m745_q0	 BUFFER[10650]	//(internal1_m745_q0) q0 - внутренний параметр
#define idinternal1_m745_q0	 1560	//(internal1_m745_q0) q0 - внутренний параметр
#define internal1_m1202_DvUp0	 BUFFER[10652]	//(internal1_m1202_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1202_DvUp0	 1561	//(internal1_m1202_DvUp0) - есть команда на движение вперёд
#define internal1_m1202_DvDw0	 BUFFER[10653]	//(internal1_m1202_DvDw0) - есть команда на движение назад
#define idinternal1_m1202_DvDw0	 1562	//(internal1_m1202_DvDw0) - есть команда на движение назад
#define internal1_m1202_FDvUp0	 BUFFER[10654]	//(internal1_m1202_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1202_FDvUp0	 1563	//(internal1_m1202_FDvUp0) - есть команда на движение вперёд
#define internal1_m1202_FDvDw0	 BUFFER[10655]	//(internal1_m1202_FDvDw0) - есть команда на движение назад
#define idinternal1_m1202_FDvDw0	 1564	//(internal1_m1202_FDvDw0) - есть команда на движение назад
#define internal1_m1202_BlDv0	 BUFFER[10656]	//(internal1_m1202_BlDv0) - была блокировка
#define idinternal1_m1202_BlDv0	 1565	//(internal1_m1202_BlDv0) - была блокировка
#define internal1_m1202_Pkv0	 BUFFER[10657]	//(internal1_m1202_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1202_Pkv0	 1566	//(internal1_m1202_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1202_Pkav0	 BUFFER[10658]	//(internal1_m1202_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1202_Pkav0	 1567	//(internal1_m1202_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1202_Zkv0	 BUFFER[10659]	//(internal1_m1202_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1202_Zkv0	 1568	//(internal1_m1202_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1202_Zkav0	 BUFFER[10660]	//(internal1_m1202_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1202_Zkav0	 1569	//(internal1_m1202_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1202_txNm	 BUFFER[10661]	//(internal1_m1202_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1202_txNm	 1570	//(internal1_m1202_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1202_txSm	 BUFFER[10666]	//(internal1_m1202_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1202_txSm	 1571	//(internal1_m1202_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1202_txHr	 BUFFER[10671]	//(internal1_m1202_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1202_txHr	 1572	//(internal1_m1202_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1202_txLd	 BUFFER[10676]	//(internal1_m1202_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1202_txLd	 1573	//(internal1_m1202_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1202_fef	 BUFFER[10681]	//(internal1_m1202_fef) fef
#define idinternal1_m1202_fef	 1574	//(internal1_m1202_fef) fef
#define internal1_m1192_DvUp0	 BUFFER[10682]	//(internal1_m1192_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1192_DvUp0	 1575	//(internal1_m1192_DvUp0) - есть команда на движение вперёд
#define internal1_m1192_DvDw0	 BUFFER[10683]	//(internal1_m1192_DvDw0) - есть команда на движение назад
#define idinternal1_m1192_DvDw0	 1576	//(internal1_m1192_DvDw0) - есть команда на движение назад
#define internal1_m1192_FDvUp0	 BUFFER[10684]	//(internal1_m1192_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1192_FDvUp0	 1577	//(internal1_m1192_FDvUp0) - есть команда на движение вперёд
#define internal1_m1192_FDvDw0	 BUFFER[10685]	//(internal1_m1192_FDvDw0) - есть команда на движение назад
#define idinternal1_m1192_FDvDw0	 1578	//(internal1_m1192_FDvDw0) - есть команда на движение назад
#define internal1_m1192_BlDv0	 BUFFER[10686]	//(internal1_m1192_BlDv0) - была блокировка
#define idinternal1_m1192_BlDv0	 1579	//(internal1_m1192_BlDv0) - была блокировка
#define internal1_m1192_Pkv0	 BUFFER[10687]	//(internal1_m1192_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1192_Pkv0	 1580	//(internal1_m1192_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1192_Pkav0	 BUFFER[10688]	//(internal1_m1192_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1192_Pkav0	 1581	//(internal1_m1192_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1192_Zkv0	 BUFFER[10689]	//(internal1_m1192_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1192_Zkv0	 1582	//(internal1_m1192_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1192_Zkav0	 BUFFER[10690]	//(internal1_m1192_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1192_Zkav0	 1583	//(internal1_m1192_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1192_txNm	 BUFFER[10691]	//(internal1_m1192_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1192_txNm	 1584	//(internal1_m1192_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1192_txSm	 BUFFER[10696]	//(internal1_m1192_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1192_txSm	 1585	//(internal1_m1192_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1192_txHr	 BUFFER[10701]	//(internal1_m1192_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1192_txHr	 1586	//(internal1_m1192_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1192_txLd	 BUFFER[10706]	//(internal1_m1192_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1192_txLd	 1587	//(internal1_m1192_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1192_fef	 BUFFER[10711]	//(internal1_m1192_fef) fef
#define idinternal1_m1192_fef	 1588	//(internal1_m1192_fef) fef
#define internal1_m800_DvUp0	 BUFFER[10712]	//(internal1_m800_DvUp0) - есть команда на движение вперёд
#define idinternal1_m800_DvUp0	 1589	//(internal1_m800_DvUp0) - есть команда на движение вперёд
#define internal1_m800_DvDw0	 BUFFER[10713]	//(internal1_m800_DvDw0) - есть команда на движение назад
#define idinternal1_m800_DvDw0	 1590	//(internal1_m800_DvDw0) - есть команда на движение назад
#define internal1_m800_FDvUp0	 BUFFER[10714]	//(internal1_m800_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m800_FDvUp0	 1591	//(internal1_m800_FDvUp0) - есть команда на движение вперёд
#define internal1_m800_FDvDw0	 BUFFER[10715]	//(internal1_m800_FDvDw0) - есть команда на движение назад
#define idinternal1_m800_FDvDw0	 1592	//(internal1_m800_FDvDw0) - есть команда на движение назад
#define internal1_m800_BlDv0	 BUFFER[10716]	//(internal1_m800_BlDv0) - была блокировка
#define idinternal1_m800_BlDv0	 1593	//(internal1_m800_BlDv0) - была блокировка
#define internal1_m800_Pkv0	 BUFFER[10717]	//(internal1_m800_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m800_Pkv0	 1594	//(internal1_m800_Pkv0) Pkv - передний конечный выключатель
#define internal1_m800_Pkav0	 BUFFER[10718]	//(internal1_m800_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m800_Pkav0	 1595	//(internal1_m800_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m800_Zkv0	 BUFFER[10719]	//(internal1_m800_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m800_Zkv0	 1596	//(internal1_m800_Zkv0) Zkv - задний конечный выключатель
#define internal1_m800_Zkav0	 BUFFER[10720]	//(internal1_m800_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m800_Zkav0	 1597	//(internal1_m800_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m800_txNm	 BUFFER[10721]	//(internal1_m800_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m800_txNm	 1598	//(internal1_m800_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m800_txSm	 BUFFER[10726]	//(internal1_m800_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m800_txSm	 1599	//(internal1_m800_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m800_txHr	 BUFFER[10731]	//(internal1_m800_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m800_txHr	 1600	//(internal1_m800_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m800_txLd	 BUFFER[10736]	//(internal1_m800_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m800_txLd	 1601	//(internal1_m800_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m800_fef	 BUFFER[10741]	//(internal1_m800_fef) fef
#define idinternal1_m800_fef	 1602	//(internal1_m800_fef) fef
#define internal1_m796_DvUp0	 BUFFER[10742]	//(internal1_m796_DvUp0) - есть команда на движение вперёд
#define idinternal1_m796_DvUp0	 1603	//(internal1_m796_DvUp0) - есть команда на движение вперёд
#define internal1_m796_DvDw0	 BUFFER[10743]	//(internal1_m796_DvDw0) - есть команда на движение назад
#define idinternal1_m796_DvDw0	 1604	//(internal1_m796_DvDw0) - есть команда на движение назад
#define internal1_m796_FDvUp0	 BUFFER[10744]	//(internal1_m796_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m796_FDvUp0	 1605	//(internal1_m796_FDvUp0) - есть команда на движение вперёд
#define internal1_m796_FDvDw0	 BUFFER[10745]	//(internal1_m796_FDvDw0) - есть команда на движение назад
#define idinternal1_m796_FDvDw0	 1606	//(internal1_m796_FDvDw0) - есть команда на движение назад
#define internal1_m796_BlDv0	 BUFFER[10746]	//(internal1_m796_BlDv0) - была блокировка
#define idinternal1_m796_BlDv0	 1607	//(internal1_m796_BlDv0) - была блокировка
#define internal1_m796_Pkv0	 BUFFER[10747]	//(internal1_m796_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m796_Pkv0	 1608	//(internal1_m796_Pkv0) Pkv - передний конечный выключатель
#define internal1_m796_Pkav0	 BUFFER[10748]	//(internal1_m796_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m796_Pkav0	 1609	//(internal1_m796_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m796_Zkv0	 BUFFER[10749]	//(internal1_m796_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m796_Zkv0	 1610	//(internal1_m796_Zkv0) Zkv - задний конечный выключатель
#define internal1_m796_Zkav0	 BUFFER[10750]	//(internal1_m796_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m796_Zkav0	 1611	//(internal1_m796_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m796_txNm	 BUFFER[10751]	//(internal1_m796_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m796_txNm	 1612	//(internal1_m796_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m796_txSm	 BUFFER[10756]	//(internal1_m796_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m796_txSm	 1613	//(internal1_m796_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m796_txHr	 BUFFER[10761]	//(internal1_m796_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m796_txHr	 1614	//(internal1_m796_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m796_txLd	 BUFFER[10766]	//(internal1_m796_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m796_txLd	 1615	//(internal1_m796_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m796_fef	 BUFFER[10771]	//(internal1_m796_fef) fef
#define idinternal1_m796_fef	 1616	//(internal1_m796_fef) fef
#define internal1_m378_DvUp0	 BUFFER[10772]	//(internal1_m378_DvUp0) - есть команда на движение вперёд
#define idinternal1_m378_DvUp0	 1617	//(internal1_m378_DvUp0) - есть команда на движение вперёд
#define internal1_m378_DvDw0	 BUFFER[10773]	//(internal1_m378_DvDw0) - есть команда на движение назад
#define idinternal1_m378_DvDw0	 1618	//(internal1_m378_DvDw0) - есть команда на движение назад
#define internal1_m378_FDvUp0	 BUFFER[10774]	//(internal1_m378_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m378_FDvUp0	 1619	//(internal1_m378_FDvUp0) - есть команда на движение вперёд
#define internal1_m378_FDvDw0	 BUFFER[10775]	//(internal1_m378_FDvDw0) - есть команда на движение назад
#define idinternal1_m378_FDvDw0	 1620	//(internal1_m378_FDvDw0) - есть команда на движение назад
#define internal1_m378_BlDv0	 BUFFER[10776]	//(internal1_m378_BlDv0) - была блокировка
#define idinternal1_m378_BlDv0	 1621	//(internal1_m378_BlDv0) - была блокировка
#define internal1_m378_Pkv0	 BUFFER[10777]	//(internal1_m378_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m378_Pkv0	 1622	//(internal1_m378_Pkv0) Pkv - передний конечный выключатель
#define internal1_m378_Pkav0	 BUFFER[10778]	//(internal1_m378_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m378_Pkav0	 1623	//(internal1_m378_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m378_Zkv0	 BUFFER[10779]	//(internal1_m378_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m378_Zkv0	 1624	//(internal1_m378_Zkv0) Zkv - задний конечный выключатель
#define internal1_m378_Zkav0	 BUFFER[10780]	//(internal1_m378_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m378_Zkav0	 1625	//(internal1_m378_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m378_txNm	 BUFFER[10781]	//(internal1_m378_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m378_txNm	 1626	//(internal1_m378_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m378_txSm	 BUFFER[10786]	//(internal1_m378_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m378_txSm	 1627	//(internal1_m378_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m378_txHr	 BUFFER[10791]	//(internal1_m378_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m378_txHr	 1628	//(internal1_m378_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m378_txLd	 BUFFER[10796]	//(internal1_m378_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m378_txLd	 1629	//(internal1_m378_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m378_fef	 BUFFER[10801]	//(internal1_m378_fef) fef
#define idinternal1_m378_fef	 1630	//(internal1_m378_fef) fef
#define internal1_m407_DvUp0	 BUFFER[10802]	//(internal1_m407_DvUp0) - есть команда на движение вперёд
#define idinternal1_m407_DvUp0	 1631	//(internal1_m407_DvUp0) - есть команда на движение вперёд
#define internal1_m407_DvDw0	 BUFFER[10803]	//(internal1_m407_DvDw0) - есть команда на движение назад
#define idinternal1_m407_DvDw0	 1632	//(internal1_m407_DvDw0) - есть команда на движение назад
#define internal1_m407_FDvUp0	 BUFFER[10804]	//(internal1_m407_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m407_FDvUp0	 1633	//(internal1_m407_FDvUp0) - есть команда на движение вперёд
#define internal1_m407_FDvDw0	 BUFFER[10805]	//(internal1_m407_FDvDw0) - есть команда на движение назад
#define idinternal1_m407_FDvDw0	 1634	//(internal1_m407_FDvDw0) - есть команда на движение назад
#define internal1_m407_BlDv0	 BUFFER[10806]	//(internal1_m407_BlDv0) - была блокировка
#define idinternal1_m407_BlDv0	 1635	//(internal1_m407_BlDv0) - была блокировка
#define internal1_m407_Pkv0	 BUFFER[10807]	//(internal1_m407_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m407_Pkv0	 1636	//(internal1_m407_Pkv0) Pkv - передний конечный выключатель
#define internal1_m407_Pkav0	 BUFFER[10808]	//(internal1_m407_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m407_Pkav0	 1637	//(internal1_m407_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m407_Zkv0	 BUFFER[10809]	//(internal1_m407_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m407_Zkv0	 1638	//(internal1_m407_Zkv0) Zkv - задний конечный выключатель
#define internal1_m407_Zkav0	 BUFFER[10810]	//(internal1_m407_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m407_Zkav0	 1639	//(internal1_m407_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m407_txNm	 BUFFER[10811]	//(internal1_m407_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m407_txNm	 1640	//(internal1_m407_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m407_txSm	 BUFFER[10816]	//(internal1_m407_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m407_txSm	 1641	//(internal1_m407_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m407_txHr	 BUFFER[10821]	//(internal1_m407_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m407_txHr	 1642	//(internal1_m407_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m407_txLd	 BUFFER[10826]	//(internal1_m407_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m407_txLd	 1643	//(internal1_m407_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m407_fef	 BUFFER[10831]	//(internal1_m407_fef) fef
#define idinternal1_m407_fef	 1644	//(internal1_m407_fef) fef
#define internal1_m401_DvUp0	 BUFFER[10832]	//(internal1_m401_DvUp0) - есть команда на движение вперёд
#define idinternal1_m401_DvUp0	 1645	//(internal1_m401_DvUp0) - есть команда на движение вперёд
#define internal1_m401_DvDw0	 BUFFER[10833]	//(internal1_m401_DvDw0) - есть команда на движение назад
#define idinternal1_m401_DvDw0	 1646	//(internal1_m401_DvDw0) - есть команда на движение назад
#define internal1_m401_FDvUp0	 BUFFER[10834]	//(internal1_m401_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m401_FDvUp0	 1647	//(internal1_m401_FDvUp0) - есть команда на движение вперёд
#define internal1_m401_FDvDw0	 BUFFER[10835]	//(internal1_m401_FDvDw0) - есть команда на движение назад
#define idinternal1_m401_FDvDw0	 1648	//(internal1_m401_FDvDw0) - есть команда на движение назад
#define internal1_m401_BlDv0	 BUFFER[10836]	//(internal1_m401_BlDv0) - была блокировка
#define idinternal1_m401_BlDv0	 1649	//(internal1_m401_BlDv0) - была блокировка
#define internal1_m401_Pkv0	 BUFFER[10837]	//(internal1_m401_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m401_Pkv0	 1650	//(internal1_m401_Pkv0) Pkv - передний конечный выключатель
#define internal1_m401_Pkav0	 BUFFER[10838]	//(internal1_m401_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m401_Pkav0	 1651	//(internal1_m401_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m401_Zkv0	 BUFFER[10839]	//(internal1_m401_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m401_Zkv0	 1652	//(internal1_m401_Zkv0) Zkv - задний конечный выключатель
#define internal1_m401_Zkav0	 BUFFER[10840]	//(internal1_m401_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m401_Zkav0	 1653	//(internal1_m401_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m401_txNm	 BUFFER[10841]	//(internal1_m401_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m401_txNm	 1654	//(internal1_m401_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m401_txSm	 BUFFER[10846]	//(internal1_m401_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m401_txSm	 1655	//(internal1_m401_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m401_txHr	 BUFFER[10851]	//(internal1_m401_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m401_txHr	 1656	//(internal1_m401_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m401_txLd	 BUFFER[10856]	//(internal1_m401_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m401_txLd	 1657	//(internal1_m401_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m401_fef	 BUFFER[10861]	//(internal1_m401_fef) fef
#define idinternal1_m401_fef	 1658	//(internal1_m401_fef) fef
#define internal1_m752_q0	 BUFFER[10862]	//(internal1_m752_q0) q0 - внутренний параметр
#define idinternal1_m752_q0	 1659	//(internal1_m752_q0) q0 - внутренний параметр
#define internal1_m749_q0	 BUFFER[10864]	//(internal1_m749_q0) q0 - внутренний параметр
#define idinternal1_m749_q0	 1660	//(internal1_m749_q0) q0 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &R0AB07LDU},	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
	{ 2	,1	,1	, &R0AD16LDU},	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
	{ 3	,1	,1	, &C2MD31LP1},	//( - , DU) Кнопка СБРОС РБ
	{ 4	,3	,1	, &B6VS01IDU},	//( - , DU) Готовность к управлению БЗ2
	{ 5	,1	,1	, &R2AD20LDU},	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
	{ 6	,1	,1	, &R2AD10LDU},	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
	{ 7	,3	,1	, &B8VS01IDU},	//( - , DU) Готовность к управлению АЗ2
	{ 8	,3	,1	, &A8VS01IDU},	//( - , DU) Готовность к управлению ДС2
	{ 9	,1	,1	, &A1IE03LDU},	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
	{ 10	,1	,1	, &A1IE04LDU},	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
	{ 11	,1	,1	, &A2IE03LDU},	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
	{ 12	,1	,1	, &A2IE04LDU},	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
	{ 13	,1	,1	, &A3IE03LDU},	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
	{ 14	,1	,1	, &A3IE04LDU},	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
	{ 15	,1	,1	, &B1IE03LDU},	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
	{ 16	,1	,1	, &B1IE04LDU},	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
	{ 17	,1	,1	, &B2IE03LDU},	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
	{ 18	,1	,1	, &B2IE04LDU},	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
	{ 19	,1	,1	, &B3IE03LDU},	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
	{ 20	,1	,1	, &B3IE04LDU},	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
	{ 21	,1	,1	, &R0VS11LDU},	//( - , DU) РУ не готова к работе
	{ 22	,1	,1	, &B6AB05LDU},	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
	{ 23	,1	,1	, &R0AB08LDU},	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
	{ 24	,1	,1	, &A3VZ15LZ1},	//(vds32:02 - K19VDSR, - ) Имитация срабатывания АЗ от НУП ИС
	{ 25	,1	,1	, &A3VZ15LZ2},	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{ 26	,1	,1	, &B2IS33LDU},	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
	{ 27	,1	,1	, &B3IS31LDU},	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
	{ 28	,1	,1	, &B3IS33LDU},	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
	{ 29	,1	,1	, &B3IS35LDU},	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
	{ 30	,1	,1	, &B4IS10LDU},	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
	{ 31	,1	,1	, &R6IS31LDU},	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
	{ 32	,1	,1	, &R6IS32LDU},	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
	{ 33	,1	,1	, &R6IS42LDU},	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
	{ 34	,1	,1	, &R6IS41LDU},	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
	{ 35	,1	,1	, &R6IS52LDU},	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
	{ 36	,1	,1	, &R6IS51LDU},	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
	{ 37	,1	,1	, &R3IS11LDU},	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
	{ 38	,1	,1	, &R3IS21LDU},	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
	{ 39	,1	,1	, &R0AB03LDU},	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
	{ 40	,1	,1	, &R0AB05LDU},	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
	{ 41	,8	,1	, &R0VN11RZ1},	//( - , MDuBz1) Средняя мощность по BAZ1
	{ 42	,8	,1	, &R0VN11RZ2},	//( - , MDuBz2) Средняя мощность по BAZ2
	{ 43	,1	,1	, &A2AB15LDU},	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{ 44	,1	,1	, &B2AB15LDU},	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{ 45	,1	,1	, &R0AD21LDU},	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
	{ 46	,1	,1	, &R0VX02LDU},	//( - , DU) Импульс разрешен
	{ 47	,1	,1	, &R0EE03LDU},	//( - , DU) ВПИС ИС
	{ 48	,1	,1	, &B3IS12LDU},	//( - , DU) Приход на ВУ штока ИС2
	{ 49	,1	,1	, &A1ZAV},	//( - , DU) 
	{ 50	,1	,1	, &A3ZAV},	//( - , DU) 
	{ 51	,1	,1	, &B1AB19LDU},	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
	{ 52	,8	,1	, &R0VN09RZ2},	//( - , MDuBz2) Усредненный период разгона
	{ 53	,8	,1	, &R0VN09RZ1},	//( - , MDuBz1) Усредненный период разгона
	{ 54	,1	,1	, &R0AB16LDU},	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
	{ 55	,1	,1	, &R0AB17LDU},	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
	{ 56	,1	,1	, &R0AB18LDU},	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
	{ 57	,8	,1	, &A0CT01IZ1},	//( - , MDuBz1) Температура АЗ1-1
	{ 58	,8	,1	, &B0CT01IZ1},	//( - , MDuBz1) Температура АЗ2-1
	{ 59	,8	,1	, &A0CT01IZ2},	//( - , MDuBz2) Температура АЗ1-2
	{ 60	,8	,1	, &B0CT01IZ2},	//( - , MDuBz2) Температура АЗ2-2
	{ 61	,8	,1	, &A3MC01RDU},	//( - , DU) Заданная координата положения ИС от регулятора мм
	{ 62	,8	,1	, &A3MC02RDU},	//( - , DU) Температурная корректировка координаты ИМ
	{ 63	,8	,1	, &R0CN91LDU},	//( - , DU) Рассчётная реактивность от регулятора
	{ 64	,8	,1	, &A3MC03RDU},	//( - , DU) Координата положения ИМ 0-й реактивности
	{ 65	,1	,1	, &A3AB15LDU},	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
	{ 66	,1	,1	, &R0AB20LDU},	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
	{ 67	,8	,1	, &R0CN92LDU},	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
	{ 68	,8	,1	, &R0VN11RDU},	//( - , DU) Текущая мощность РУ
	{ 69	,8	,1	, &R0VN12RDU},	//( - , DU) Заданная мощность РУ
	{ 70	,1	,1	, &R0AB19LDU},	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
	{ 71	,8	,1	, &R0CN93LDU},	//( - , DU) время работы на мощности более 100Вт, сек
	{ 72	,8	,1	, &A1MC01RP1},	//( - , DU) Заданная координата положения ББ1 мм
	{ 73	,8	,1	, &B1MC01RP1},	//( - , DU) Заданная координата положения ББ2  мм
	{ 74	,8	,1	, &A3MC01RP1},	//( - , DU) Заданная координата положения ИС1 мм
	{ 75	,8	,1	, &B3MC01RP1},	//( - , DU) Заданная координата положения ИС2 мм
	{ 76	,8	,1	, &B8MC01RP2},	//( - , DU) Заданная координата АЗ2 мм
	{ 77	,1	,1	, &R0AB09LDU},	//( - , DU) Ошибка в заданной координате ББ1
	{ 78	,1	,1	, &R0AB10LDU},	//( - , DU) Ошибка в заданной координате ББ2
	{ 79	,1	,1	, &R0AB11LDU},	//( - , DU) Ошибка в заданной координате  ИС1
	{ 80	,1	,1	, &R0AB12LDU},	//( - , DU) Ошибка в заданной координате  ИС2
	{ 81	,1	,1	, &R0AB13LDU},	//( - , DU) Ошибка в заданной координате  АЗ2
	{ 82	,1	,1	, &A4ZAV},	//( - , DU) 
	{ 83	,1	,1	, &A6ZAV},	//( - , DU) 
	{ 84	,1	,1	, &R2ZAV},	//( - , DU) 
	{ 85	,1	,1	, &A5ZAV},	//( - , DU) 
	{ 86	,1	,1	, &B8ZAV},	//( - , DU) 
	{ 87	,1	,1	, &A2ZAV},	//( - , DU) Завершение РБ1,2
	{ 88	,1	,1	, &A8ZAV},	//( - , DU) 
	{ 89	,1	,1	, &A9ZAV},	//( - , DU) Завершение НИ ДС1(2)
	{ 90	,1	,1	, &R4ABL},	//( - , DU) Блокировка тележки -
	{ 91	,1	,1	, &A4UP},	//( - , DU) 
	{ 92	,1	,1	, &A4DW},	//( - , DU) 
	{ 93	,1	,1	, &R0AB14LDU},	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
	{ 94	,1	,1	, &R0AB15LDU},	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
	{ 95	,1	,1	, &A3IS12LDU},	//( - , DU) Приход на ВУ штока ИС1
	{ 96	,1	,1	, &B3IS22LDU},	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
	{ 97	,1	,1	, &A2AD33LDU},	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
	{ 98	,1	,1	, &B2AD33LDU},	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
	{ 99	,1	,1	, &A3AD33LDU},	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
	{ 100	,1	,1	, &A3AD34LDU},	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
	{ 101	,1	,1	, &A3AD31LDU},	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
	{ 102	,1	,1	, &B3AD34LDU},	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
	{ 103	,1	,1	, &B3AD31LDU},	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
	{ 104	,1	,1	, &A2IS11LDU},	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
	{ 105	,1	,1	, &B2IS11LDU},	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
	{ 106	,1	,1	, &A3MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
	{ 107	,1	,1	, &A3MD11LP1},	//( - , DU) Кнопка ПУСК ИС1
	{ 108	,1	,1	, &R0MD33LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
	{ 109	,1	,1	, &A1MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
	{ 110	,1	,1	, &A1MD11LP1},	//( - , DU) Кнопка ПУСК ББ1
	{ 111	,3	,1	, &R0MW14IP2},	//( - , DU) Переключатель ОБДУВ
	{ 112	,1	,1	, &A7AP31LDU},	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
	{ 113	,1	,1	, &B7AP31LDU},	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
	{ 114	,3	,1	, &R0MW12IP2},	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
	{ 115	,1	,1	, &R0MW17LP1},	//( - , DU) Переключатель АВТ/Р
	{ 116	,1	,1	, &R0VW13LDU},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
	{ 117	,1	,1	, &R0VW23LDU},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
	{ 118	,3	,1	, &R0VX08IDU},	//( - , DU) Индикация Режим
	{ 119	,1	,1	, &R0VX09LDU},	//( - , DU) Индикация регулятор мощности включен/отключен
	{ 120	,1	,1	, &A4VS22LDU},	//( - , DU) Движение НИ1 в сторону НУ
	{ 121	,3	,1	, &B4VS01IDU},	//( - , DU) Готовность к управлению НИ2
	{ 122	,1	,1	, &B4VS12LDU},	//( - , DU) Движение НИ2 в сторону ВУ
	{ 123	,1	,1	, &B4VS22LDU},	//( - , DU) Движение НИ2 в сторону НУ
	{ 124	,3	,1	, &A5VS01IDU},	//( - , DU) Готовность к управлению НЛ1
	{ 125	,3	,1	, &B5VS01IDU},	//( - , DU) Готовность к управлению НЛ2
	{ 126	,3	,1	, &A6VS01IDU},	//( - , DU) Готовность к управлению БЗ1
	{ 127	,3	,1	, &R4VS01IDU},	//( - , DU) Готовность к управлению тележкой реактора
	{ 128	,3	,1	, &R2VS01IDU},	//( - , DU) Готовность к управлению МДЗ2
	{ 129	,3	,1	, &R1VS01IDU},	//( - , DU) Готовность к управлению МДЗ1
	{ 130	,1	,1	, &A9IS11LDU},	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
	{ 131	,1	,1	, &A9IS21LDU},	//(vds32:02 - K24VDSR, - ) Приход на НУ НИ ДС1
	{ 132	,1	,1	, &B9IS11LDU},	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
	{ 133	,1	,1	, &B9IS21LDU},	//(vds32:02 - K26VDSR, - ) Приход на НУ НИ ДС2
	{ 134	,1	,1	, &B9AD10LDU},	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
	{ 135	,1	,1	, &A9AD10LDU},	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
	{ 136	,1	,1	, &A9AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ ДС1
	{ 137	,1	,1	, &A9AB01LDU},	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
	{ 138	,1	,1	, &A9AB02LDU},	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
	{ 139	,1	,1	, &B9AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ ДС2
	{ 140	,1	,1	, &B9AB01LDU},	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
	{ 141	,1	,1	, &B9AB02LDU},	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
	{ 142	,1	,1	, &R0AB01LDU},	//( - , DU) Режим проверки разрешён
	{ 143	,1	,1	, &A3IS22LDU},	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
	{ 144	,1	,1	, &B2VS21LDU},	//( - , DU) Движение РБ2 в сторону НУ
	{ 145	,3	,1	, &B2VS01IDU},	//( - , DU) Готовность к управлению РБ2
	{ 146	,1	,1	, &A7AS31LDU},	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
	{ 147	,1	,1	, &B7AS31LDU},	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
	{ 148	,1	,1	, &A7AZ03LDU},	//( - , DU) Несанкционированное включение обдува АЗ1
	{ 149	,1	,1	, &B7AZ03LDU},	//( - , DU) Несанкционированное включение обдува АЗ2
	{ 150	,1	,1	, &B3MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
	{ 151	,1	,1	, &B3MD11LP1},	//( - , DU) Кнопка ПУСК ИС2
	{ 152	,8	,1	, &R0VL01RDU},	//( - , DU) Индикация Время задержки
	{ 153	,1	,1	, &R0VZ71LZ2},	//(vds32:03 - K22VDSR, DU) Обобщенный сигнал АЗ 2 канала
	{ 154	,1	,1	, &R0VZ71LZ1},	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
	{ 155	,1	,1	, &R0VZ71LDU},	//( - , DU) Обобщенный сигнал АЗ
	{ 156	,1	,1	, &A2IS33LDU},	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
	{ 157	,1	,1	, &A3IS31LDU},	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
	{ 158	,1	,1	, &A3IS33LDU},	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
	{ 159	,1	,1	, &A3IS35LDU},	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
	{ 160	,1	,1	, &A4IS10LDU},	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
	{ 161	,1	,1	, &A1VN71LZ1},	//(vds32:02 - K21VDSR, - ) Блокировка автоматического подъёма ББ
	{ 162	,1	,1	, &A1VN71LZ2},	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{ 163	,1	,1	, &A1AB19LDU},	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
	{ 164	,1	,1	, &R0AD14LZ1},	//(vds32:02 - K20VDSR, - ) Имитация срабатывания АЗ от II УР
	{ 165	,1	,1	, &R0AD14LZ2},	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
	{ 166	,1	,1	, &A3VZ13LZ2},	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{ 167	,1	,1	, &A3VZ13LZ1},	//(vds32:02 - K18VDSR, - ) Имитация срабатывания АЗ от ВУ ИС
	{ 168	,1	,1	, &R0VS17LDU},	//( - , DU) Индикация выбора АВТОМАТ
	{ 169	,1	,1	, &A2VS32LDU},	//( - , DU) Индикация  СБРОС РБ1
	{ 170	,1	,1	, &B2VS32LDU},	//( - , DU) Индикация  СБРОС РБ2
	{ 171	,1	,1	, &A3VX01LDU},	//( - , DU) Индикация Выстрел ИС1
	{ 172	,1	,1	, &A3IS11LDU},	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
	{ 173	,1	,1	, &B3VX01LDU},	//( - , DU) Индикация Выстрел ИС2
	{ 174	,1	,1	, &R0VS18LDU},	//( - , DU) Индикация  Проверка схем сброса
	{ 175	,1	,1	, &B1MD11LP1},	//( - , DU) Кнопка ПУСК ББ2
	{ 176	,1	,1	, &B1MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
	{ 177	,1	,1	, &B2MD11LP1},	//( - , DU) Кнопка ПУСК РБ2
	{ 178	,1	,1	, &B2MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
	{ 179	,1	,1	, &A2MD11LP1},	//( - , DU) Кнопка ПУСК РБ1
	{ 180	,1	,1	, &A2MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
	{ 181	,1	,1	, &R0IS01LDU},	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
	{ 182	,1	,1	, &R0IS02LDU},	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
	{ 183	,1	,1	, &R0VP73LZ1},	//( - , MDuBz1) ПС давления для РУ
	{ 184	,1	,1	, &R0VP73LZ2},	//( - , MDuBz2) ПС давления для РУ
	{ 185	,1	,1	, &R0VP73LDU},	//( - , DU) ПС давления для РУ
	{ 186	,1	,1	, &R0MD34LP1},	//( - , DU) Кнопка КВИТИРОВАТЬ
	{ 187	,1	,1	, &A0VT71LZ1},	//( - , MDuBz1) АС по температуре в АЗ1
	{ 188	,1	,1	, &B0VT71LZ1},	//( - , MDuBz1) АС по температуре в АЗ2
	{ 189	,1	,1	, &A0VT71LZ2},	//( - , MDuBz2) АС по температуре в АЗ1
	{ 190	,1	,1	, &B0VT71LZ2},	//( - , MDuBz2) АС по температуре в АЗ2
	{ 191	,1	,1	, &B2VS11LDU},	//( - , DU) Движение РБ2 в сторону ВУ
	{ 192	,1	,1	, &B3VP42LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
	{ 193	,8	,1	, &B3CP02RDU},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
	{ 194	,1	,1	, &B3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
	{ 195	,1	,1	, &B3VP82LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
	{ 196	,1	,1	, &A3VP82LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
	{ 197	,3	,1	, &A3IP02IDU},	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
	{ 198	,3	,1	, &B3IP02IDU},	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
	{ 199	,1	,1	, &A0VE01LDU},	//( - , DU) Напряжение в системы АЗ1 подано
	{ 200	,1	,1	, &B0VE01LDU},	//( - , DU) Напряжение в системы АЗ2 подано
	{ 201	,1	,1	, &A0VP01LDU},	//( - , DU) Давление в системы АЗ1 подано
	{ 202	,1	,1	, &B0VP01LDU},	//( - , DU) Давление в системы АЗ2 подано
	{ 203	,1	,1	, &A0EE01LZ1},	//( - , MDuBz1) Исправность АКНП1
	{ 204	,1	,1	, &A0EE03LZ1},	//( - , MDuBz1) Исправность АКНП3
	{ 205	,1	,1	, &A0EE02LZ1},	//( - , MDuBz1) Исправность АКНП2
	{ 206	,1	,1	, &A0EE04LZ1},	//( - , MDuBz1) Исправность АКНП4
	{ 207	,1	,1	, &A0VN01LDU},	//( - , DU) Каналы АЗ1 проверены
	{ 208	,1	,1	, &B0VN01LDU},	//( - , DU) Каналы АЗ2 проверены
	{ 209	,1	,1	, &A0EE01LZ2},	//( - , MDuBz2) Исправность АКНП1
	{ 210	,1	,1	, &A0EE03LZ2},	//( - , MDuBz2) Исправность АКНП3
	{ 211	,1	,1	, &A0EE02LZ2},	//( - , MDuBz2) Исправность АКНП2
	{ 212	,1	,1	, &A0EE04LZ2},	//( - , MDuBz2) Исправность АКНП4
	{ 213	,1	,1	, &A0VP71LZ1},	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
	{ 214	,1	,1	, &A0VP71LZ2},	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
	{ 215	,8	,1	, &A8VC01RDU},	//( - , DU) Координата ДС2, мм
	{ 216	,5	,1	, &B8IC01UDU},	//( - , MDuS) Координата АЗ2 (дел.энк)
	{ 217	,5	,1	, &A1IC01UDU},	//( - , MDuS) Координата штока ББ1 (дел.энк)
	{ 218	,8	,1	, &A1VC01RDU},	//( - , DU) Координата ББ1, мм
	{ 219	,1	,1	, &A1IS11LDU},	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
	{ 220	,1	,1	, &B1MC01LC1},	//( - , DU) Настроить энкодер ББ2
	{ 221	,1	,1	, &B1MC01LC2},	//( - , DU) Настроить энкодер ББ2
	{ 222	,1	,1	, &A1MC01LC1},	//( - , DU) Настроить энкодер ББ1
	{ 223	,1	,1	, &A1MC01LC2},	//( - , DU) Настроить энкодер ББ1
	{ 224	,1	,1	, &B2MC01LC1},	//( - , DU) Настроить энкодер РБ2
	{ 225	,1	,1	, &B2MC01LC2},	//( - , DU) Настроить энкодер РБ2
	{ 226	,1	,1	, &A2MC01LC1},	//( - , DU) Настроить энкодер РБ1
	{ 227	,1	,1	, &A2MC01LC2},	//( - , DU) Настроить энкодер РБ1
	{ 228	,1	,1	, &B3MC01LC1},	//( - , DU) Настроить энкодер ИС2
	{ 229	,1	,1	, &B3MC01LC2},	//( - , DU) Настроить энкодер ИС2
	{ 230	,1	,1	, &A3MC01LC1},	//( - , DU) Настроить энкодер ИС1
	{ 231	,1	,1	, &A3MC01LC2},	//( - , DU) Настроить энкодер ИС1
	{ 232	,1	,1	, &B8MC01LC1},	//( - , DU) Настроить энкодер АЗ2
	{ 233	,1	,1	, &B8MC01LC2},	//( - , DU) Настроить энкодер АЗ2
	{ 234	,1	,1	, &A8MC01LC1},	//( - , DU) Настроить энкодер ДС2
	{ 235	,1	,1	, &A8MC01LC2},	//( - , DU) Настроить энкодер ДС2
	{ 236	,1	,1	, &A3VP42LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
	{ 237	,8	,1	, &A3CP02RDU},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
	{ 238	,1	,1	, &A3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
	{ 239	,1	,1	, &R2IE01LDU},	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
	{ 240	,1	,1	, &R6IS61LDU},	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
	{ 241	,1	,1	, &R6IS64LDU},	//( - , MDuS) Исправность ВИП ССДИ-35 1канал
	{ 242	,1	,1	, &R6IS65LDU},	//( - , MDuS) Исправность ВИП ССДИ-35 2канал
	{ 243	,1	,1	, &R6IS62LDU},	//( - , MDuS) Исправность ВИП ССДИ-39 1канал
	{ 244	,1	,1	, &R6IS63LDU},	//( - , MDuS) Исправность ВИП ССДИ-39 2канал
	{ 245	,1	,1	, &R6IS66LZZ},	//( - , MDuS) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 246	,1	,1	, &R6IS67LZZ},	//( - , MDuS) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 247	,1	,1	, &R6IS68LZZ},	//( - , MDuS) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 248	,1	,1	, &syn_R0EE03LDU},	//( - , DU) ВПИС ИС
	{ 249	,8	,1	, &A3VC01RDU},	//( - , DU) Координата ИС1, мм
	{ 250	,8	,1	, &A2VC01RDU},	//( - , DU) Координата РБ1, мм
	{ 251	,8	,1	, &B2VC01RDU},	//( - , DU) Координата РБ2, мм
	{ 252	,8	,1	, &B8VC01RDU},	//( - , DU) Координата АЗ2, мм
	{ 253	,1	,1	, &A4VP82LDU},	//( - , MDuS) Давление ПОДЪЁМ НИ1 в норме
	{ 254	,1	,1	, &B4VP82LDU},	//( - , MDuS) Давление ПОДЪЁМ НИ2 в норме
	{ 255	,1	,1	, &A2VP82LDU},	//( - , MDuS) Давление ПОДЪЁМ РБ1 в норме
	{ 256	,1	,1	, &B2VP82LDU},	//( - , MDuS) Давление ПОДЪЁМ РБ2 в норме
	{ 257	,1	,1	, &A3VP81LDU},	//( - , MDuS) Давление СПУСК ИС1 в норме
	{ 258	,1	,1	, &B3VP81LDU},	//( - , MDuS) Давление СПУСК ИС2 в норме
	{ 259	,1	,1	, &R0EE02LDU},	//( - , DU) Питание  АКНП  отключить
	{ 260	,1	,1	, &a1abf1},	//( - , - ) признак изменения скорости
	{ 261	,8	,1	, &a1abf2},	//( - , - ) положение механизма
	{ 262	,8	,1	, &a1abf3},	//( - , - ) текущее положение
	{ 263	,1	,1	, &B0VP71LZ1},	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
	{ 264	,1	,1	, &B0VP71LZ2},	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
	{ 265	,1	,1	, &A0VS11LDU},	//( - , DU) АЗ1 готова к работе
	{ 266	,1	,1	, &B0VS11LDU},	//( - , DU) АЗ2 готова к работе
	{ 267	,1	,1	, &A1IE01LDU},	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
	{ 268	,1	,1	, &A3IE01LDU},	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
	{ 269	,1	,1	, &A2IE01LDU},	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
	{ 270	,1	,1	, &A1IE02LDU},	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
	{ 271	,1	,1	, &A3IE02LDU},	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
	{ 272	,1	,1	, &A2IE02LDU},	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
	{ 273	,1	,1	, &B1IE01LDU},	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
	{ 274	,1	,1	, &B2IE01LDU},	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
	{ 275	,1	,1	, &B3IE01LDU},	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
	{ 276	,1	,1	, &B1IE02LDU},	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
	{ 277	,1	,1	, &B3IE02LDU},	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
	{ 278	,1	,1	, &B2IE02LDU},	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
	{ 279	,1	,1	, &R0IE02LDU},	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
	{ 280	,1	,1	, &R0IE01LDU},	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
	{ 281	,1	,1	, &A6IE01LDU},	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
	{ 282	,1	,1	, &B6IE01LDU},	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
	{ 283	,1	,1	, &A8IE01LDU},	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
	{ 284	,1	,1	, &B5IE01LDU},	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
	{ 285	,1	,1	, &A5IE02LDU},	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
	{ 286	,1	,1	, &R1IE01LDU},	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
	{ 287	,3	,1	, &R5VS01IDU},	//( - , DU) Готовность к управлению ворот отстойной зоны
	{ 288	,1	,1	, &R3VS22LDU},	//( - , DU) Движение гомогенных дверей к закрыты
	{ 289	,1	,1	, &R3VS12LDU},	//( - , DU) Движение гомогенных дверей к открыты
	{ 290	,3	,1	, &R3VS01IDU},	//( - , DU) Готовность к управлению гомогенных дверей
	{ 291	,1	,1	, &A3AB13LDU},	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
	{ 292	,1	,1	, &syn_A3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
	{ 293	,1	,1	, &B3AB13LDU},	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
	{ 294	,1	,1	, &syn_B3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
	{ 295	,3	,1	, &R0DE02LDU},	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
	{ 296	,3	,1	, &R0DE03LDU},	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
	{ 297	,3	,1	, &R0DE04LDU},	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
	{ 298	,3	,1	, &R0DE08LDU},	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
	{ 299	,3	,1	, &R0DE05LDU},	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
	{ 300	,3	,1	, &R0DE09LDU},	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
	{ 301	,3	,1	, &R0DE0ALDU},	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
	{ 302	,3	,1	, &R0DE07LDU},	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
	{ 303	,3	,1	, &R0DE0CLDU},	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
	{ 304	,3	,1	, &R0DE0BLDU},	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
	{ 305	,3	,1	, &R0DE0DLDU},	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
	{ 306	,3	,1	, &R0DE0FLDU},	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
	{ 307	,1	,1	, &R0DE31LDU},	//(sbk:20 - S01SBK, DiagnDU) диагностика шкафа ДУ сеть 1
	{ 308	,3	,1	, &TTLDU},	//( - , DU) ttl
	{ 309	,1	,1	, &R0DE32LDU},	//(sbk:20 - S02SBK, DiagnDU) диагностика шкафа ДУ сеть 2
	{ 310	,1	,1	, &R0DE33LDU},	//(sbk:20 - S03SBK, DiagnDU) диагностика шкафа ДУ двери
	{ 311	,8	,1	, &R0CN94LDU},	//( - , DU) Скорость изменения мощности
	{ 312	,3	,1	, &R0CN95LDU},	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
	{ 313	,1	,1	, &R0AD03LZ1},	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
	{ 314	,1	,1	, &R0AD03LZ2},	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
	{ 315	,1	,1	, &R0AD04LZ1},	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
	{ 316	,1	,1	, &R0AD04LZ2},	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
	{ 317	,1	,1	, &R0AD05LZ1},	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
	{ 318	,1	,1	, &R0AD05LZ2},	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
	{ 319	,1	,1	, &B8IS12LDU},	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
	{ 320	,1	,1	, &B8IS21LDU},	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
	{ 321	,1	,1	, &A1VP41LZ1},	//( - , DU) Давление СБРОС ББ1 ниже АС
	{ 322	,1	,1	, &A1VP41LZ2},	//( - , DU) Давление СБРОС ББ1 ниже АС
	{ 323	,1	,1	, &R0VL22LDU},	//( - , DU) Конец программы 200сек
	{ 324	,1	,1	, &R0VL23LDU},	//( - , DU) Конец программы 20мин
	{ 325	,1	,1	, &B1VP41LZ1},	//( - , DU) Давление СБРОС ББ2 ниже АС
	{ 326	,1	,1	, &B1VP41LZ2},	//( - , DU) Давление СБРОС ББ2 ниже АС
	{ 327	,1	,1	, &A3AB19LDU},	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
	{ 328	,1	,1	, &B3AB19LDU},	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
	{ 329	,1	,1	, &A3EE03LDU},	//( - , DU) ВПИС ИС1
	{ 330	,1	,1	, &B3EE03LDU},	//( - , DU) ВПИС ИС2
	{ 331	,1	,1	, &B3AB15LDU},	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
	{ 332	,1	,1	, &R5IS21LDU},	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
	{ 333	,1	,1	, &R5VS22LDU},	//( - , DU) Движение ворот отстойной зоны к закрыты
	{ 334	,1	,1	, &R5VS12LDU},	//( - , DU) Движение ворот отстойной зоны к открыты
	{ 335	,1	,1	, &hz3},	//( - , - ) 
	{ 336	,1	,1	, &hz4},	//( - , - ) 
	{ 337	,1	,1	, &hz5},	//( - , - ) 
	{ 338	,1	,1	, &hz6},	//( - , - ) 
	{ 339	,1	,1	, &bd1},	//( - , - ) 
	{ 340	,1	,1	, &bd2},	//( - , - ) 
	{ 341	,1	,1	, &bd3},	//( - , - ) 
	{ 342	,1	,1	, &bd4},	//( - , - ) 
	{ 343	,1	,1	, &bd5},	//( - , - ) 
	{ 344	,1	,1	, &bd6},	//( - , - ) 
	{ 345	,1	,1	, &a1ab1},	//( - , - ) 
	{ 346	,1	,1	, &a1ab2},	//( - , - ) 
	{ 347	,1	,1	, &a1ab3},	//( - , - ) 
	{ 348	,1	,1	, &a1ab4},	//( - , - ) 
	{ 349	,1	,1	, &a1ab5},	//( - , - ) 
	{ 350	,5	,1	, &B1IC01UDU},	//( - , MDuS) Координата штока ББ2 (дел.энк)
	{ 351	,8	,1	, &B1VC01RDU},	//( - , DU) Координата ББ2, мм
	{ 352	,1	,1	, &B1IS11LDU},	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
	{ 353	,5	,1	, &A2IC01UDU},	//( - , MDuS) Координата штока РБ1 (дел.энк)
	{ 354	,5	,1	, &B2IC01UDU},	//( - , MDuS) Координата штока РБ2 (дел.энк)
	{ 355	,5	,1	, &A3IC01UDU},	//( - , MDuS) Координата штока ИС1 (дел.энк)
	{ 356	,5	,1	, &B3IC01UDU},	//( - , MDuS) Координата штока ИС2 (дел.энк)
	{ 357	,8	,1	, &B3VC01RDU},	//( - , DU) Координата ИС2, мм
	{ 358	,5	,1	, &A8IC01UDU},	//( - , MDuS) Координата ДС2 (дел.энк)
	{ 359	,1	,1	, &R0DE34LDU},	//(sbk:20 - S04SBK, DiagnDU) диагностика шкафа ДУ температура меньше 43
	{ 360	,1	,1	, &R0DE35LDU},	//(sbk:20 - S05SBK, DiagnDU) диагностика шкафа ДУ температура больше 53
	{ 361	,1	,1	, &R0DE36LDU},	//(sbk:20 - S06SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 1
	{ 362	,1	,1	, &R0DE37LDU},	//(sbk:20 - S07SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 2
	{ 363	,1	,1	, &R0DE38LDU},	//(sbk:20 - S08SBK, DiagnDU) диагностика шкафа ДУ МП15-3 место 3
	{ 364	,1	,1	, &R0DE39LDU},	//(sbk:20 - S09SBK, DiagnDU) диагностика шкафа ДУ МП24-2 место 4
	{ 365	,1	,1	, &R0DEB3LDU},	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
	{ 366	,1	,1	, &R0DEB2LDU},	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
	{ 367	,1	,1	, &R0DEB1LDU},	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
	{ 368	,1	,1	, &R0DEB4LDU},	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
	{ 369	,1	,1	, &R0DE3DLDU},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
	{ 370	,1	,1	, &R0DE3CLDU},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
	{ 371	,1	,1	, &TestDiagnDU},	//( - , DU) Неисправность от
	{ 372	,1	,1	, &KKL1},	//( - , - ) 
	{ 373	,1	,1	, &KKL2},	//( - , - ) 
	{ 374	,1	,1	, &KKL3},	//( - , - ) 
	{ 375	,1	,1	, &KKL4},	//( - , - ) 
	{ 376	,1	,1	, &KKL5},	//( - , - ) 
	{ 377	,1	,1	, &KKL6},	//( - , - ) 
	{ 378	,1	,1	, &KKL7},	//( - , - ) 
	{ 379	,1	,1	, &KKL8},	//( - , - ) 
	{ 380	,1	,1	, &KKL9},	//( - , - ) 
	{ 381	,1	,1	, &hz1},	//( - , - ) 
	{ 382	,1	,1	, &hz2},	//( - , - ) 
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
	{ 405	,1	,1	, &B8AB13LDU},	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
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
	{ 429	,1	,1	, &B6AB06LDU},	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
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
	{ 453	,1	,1	, &A2AB16LDU},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
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
	{ 477	,1	,1	, &A8AB01LDU},	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
	{ 478	,1	,1	, &A6VS22LDU},	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
	{ 479	,1	,1	, &A6VS12LDU},	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
	{ 480	,1	,1	, &B6VS22LDU},	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
	{ 481	,1	,1	, &B6VS12LDU},	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
	{ 482	,1	,1	, &A6AD10LDU},	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
	{ 483	,1	,1	, &A6AD20LDU},	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
	{ 484	,1	,1	, &B6AD10LDU},	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
	{ 485	,1	,1	, &B6AD20LDU},	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
	{ 486	,1	,1	, &A6AZ03LDU},	//( - , DU) Несанкционированное перемещение БЗ1
	{ 487	,1	,1	, &A6AB01LDU},	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
	{ 488	,1	,1	, &A6AB02LDU},	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
	{ 489	,1	,1	, &B6AZ03LDU},	//( - , DU) Несанкционированное перемещение БЗ2
	{ 490	,1	,1	, &B6AB01LDU},	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
	{ 491	,1	,1	, &B6AB02LDU},	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
	{ 492	,1	,1	, &A6AB04LDU},	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
	{ 493	,1	,1	, &B6AB04LDU},	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
	{ 494	,1	,1	, &R4AB01LDU},	//( - , DU) Блокировка движения тележки - АНИ не установлен
	{ 495	,1	,1	, &R8IS11LDU},	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
	{ 496	,1	,1	, &R6IS21LDU},	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
	{ 497	,1	,1	, &A0VN71LZ2},	//( - , MDuBz2) АЗ по АС мощности для АЗ1
	{ 498	,1	,1	, &A0VN71LZ1},	//( - , MDuBz1) АЗ по АС мощности для АЗ1
	{ 499	,1	,1	, &R0NE01LDU},	//( - , DU) Потеря связи с БАЗ1
	{ 500	,1	,1	, &R0NE02LDU},	//( - , DU) Потеря связи с БАЗ2
	{ 501	,1	,1	, &R4AB02LDU},	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
	{ 502	,3	,1	, &R0MW15IP1},	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
	{ 503	,3	,1	, &R0MW14IP1},	//( - , DU) Переключатель ПРОГРАММЫ
	{ 504	,3	,1	, &R0MW12IP1},	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
	{ 505	,3	,1	, &R0MW13IP1},	//( - , DU) Переключатель ВЫБОР ЗОН
	{ 506	,3	,1	, &R0MW16IP1},	//( - , DU) Переключатель ВИД ПРОВЕРКИ
	{ 507	,3	,1	, &R0MW11IP1},	//( - , DU) Переключатель ВЫСТРЕЛ
	{ 508	,3	,1	, &R0MW11IP2},	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
	{ 509	,1	,1	, &R0MW13LP2},	//( - , DU) Переключатель СЕТЬ
	{ 510	,1	,1	, &R0MD32LP1},	//( - , DU) Кнопка СПУСК
	{ 511	,1	,1	, &R0MD31LP1},	//( - , DU) Кнопка СТОП
	{ 512	,1	,1	, &A1IS21LDU},	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
	{ 513	,1	,1	, &A2IS21LDU},	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
	{ 514	,1	,1	, &A3IS21LDU},	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
	{ 515	,1	,1	, &B1IS21LDU},	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
	{ 516	,1	,1	, &B2IS21LDU},	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
	{ 517	,1	,1	, &B3IS21LDU},	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
	{ 518	,1	,1	, &R0ES01LDU},	//( - , DU) ОРР не в исходном состоянии
	{ 519	,1	,1	, &R4MD11LP2},	//( - , DU) Кнопка ВПЕРЁД  (тележки)
	{ 520	,1	,1	, &R4MD31LP2},	//( - , DU) Кнопка СТОП  (тележки)
	{ 521	,1	,1	, &R4MD21LP2},	//( - , DU) Кнопка НАЗАД  (тележки)
	{ 522	,1	,1	, &A6IS11LDU},	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
	{ 523	,1	,1	, &A6IS21LDU},	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
	{ 524	,1	,1	, &B6IS11LDU},	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
	{ 525	,1	,1	, &B6IS21LDU},	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
	{ 526	,1	,1	, &R4AB14LDU},	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
	{ 527	,1	,1	, &R4AB15LDU},	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
	{ 528	,1	,1	, &R5IS11LDU},	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
	{ 529	,1	,1	, &R4AB16LDU},	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
	{ 530	,1	,1	, &R4AB17LDU},	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
	{ 531	,1	,1	, &R4AB18LDU},	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
	{ 532	,1	,1	, &R4AD10LDU},	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
	{ 533	,1	,1	, &R4AD20LDU},	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
	{ 534	,1	,1	, &A5VS22LDU},	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
	{ 535	,1	,1	, &A5VS12LDU},	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
	{ 536	,1	,1	, &B5VS22LDU},	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
	{ 537	,1	,1	, &B5VS12LDU},	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
	{ 538	,1	,1	, &B5AD10LDU},	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
	{ 539	,1	,1	, &B5AD20LDU},	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
	{ 540	,1	,1	, &A5AD10LDU},	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
	{ 541	,1	,1	, &A5AD20LDU},	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
	{ 542	,1	,1	, &A5IS11LDU},	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
	{ 543	,1	,1	, &A5IS21LDU},	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
	{ 544	,1	,1	, &B5IS11LDU},	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
	{ 545	,1	,1	, &B5IS21LDU},	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
	{ 546	,1	,1	, &A5AZ03LDU},	//( - , DU) Несанкционированное перемещение НЛ1
	{ 547	,1	,1	, &A5AB01LDU},	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
	{ 548	,1	,1	, &A5AB02LDU},	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
	{ 549	,1	,1	, &B5AZ03LDU},	//( - , DU) Несанкционированное перемещение НЛ2
	{ 550	,1	,1	, &R0NE08LDU},	//( - , DU) Потеря связи с ОПУ
	{ 551	,1	,1	, &R4IS21LDU},	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
	{ 552	,1	,1	, &R4IS22LDU},	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
	{ 553	,1	,1	, &R4IS12LDU},	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
	{ 554	,1	,1	, &R4VS22LDU},	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
	{ 555	,1	,1	, &R4VS12LDU},	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
	{ 556	,1	,1	, &R4AZ03LDU},	//( - , DU) Несанкционированное перемещение тележки
	{ 557	,1	,1	, &R4AB03LDU},	//( - , DU) Блокировка движения тележки - Самоход любого механизма
	{ 558	,1	,1	, &R1IS21LDU},	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
	{ 559	,1	,1	, &R2IS21LDU},	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
	{ 560	,1	,1	, &R4AB04LDU},	//( - , DU) Блокировка движения тележки - Превышение времени движения
	{ 561	,1	,1	, &R4AB05LDU},	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
	{ 562	,1	,1	, &R4AB06LDU},	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
	{ 563	,1	,1	, &R4AB07LDU},	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
	{ 564	,1	,1	, &R4AB08LDU},	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
	{ 565	,1	,1	, &R4AB09LDU},	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
	{ 566	,1	,1	, &B0VN71LZ1},	//( - , MDuBz1) АЗ по АС мощности для АЗ2
	{ 567	,1	,1	, &B0VN71LZ2},	//( - , MDuBz2) АЗ по АС мощности для АЗ2
	{ 568	,1	,1	, &R4AB10LDU},	//( - , DU) Блокировка тележки - не открыта биологическая защита
	{ 569	,1	,1	, &R4AB11LDU},	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
	{ 570	,1	,1	, &R4AB12LDU},	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
	{ 571	,1	,1	, &A4IS11LDU},	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
	{ 572	,1	,1	, &B4IS11LDU},	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
	{ 573	,1	,1	, &R4AB13LDU},	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
	{ 574	,1	,1	, &A3AB10LDU},	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
	{ 575	,1	,1	, &A3AB11LDU},	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
	{ 576	,1	,1	, &A3AB12LDU},	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 577	,1	,1	, &A3AB14LDU},	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
	{ 578	,1	,1	, &A3AB16LDU},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
	{ 579	,1	,1	, &A3AB17LDU},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
	{ 580	,1	,1	, &A3AB18LDU},	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
	{ 581	,1	,1	, &A3AB20LDU},	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
	{ 582	,1	,1	, &B3VS12LDU},	//( - , DU) Движение ИС2 в сторону ВУ
	{ 583	,8	,1	, &B3CV01RDU},	//( - , DU) Измеренная скорость перемещения ИС2
	{ 584	,1	,1	, &B3AB04LDU},	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
	{ 585	,1	,1	, &B3AB02LDU},	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
	{ 586	,1	,1	, &B3AB01LDU},	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
	{ 587	,1	,1	, &B3VS22LDU},	//( - , DU) Движение ИС2 в сторону НУ
	{ 588	,1	,1	, &B3AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
	{ 589	,1	,1	, &B3AD11LDU},	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
	{ 590	,1	,1	, &B3AD21LDU},	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
	{ 591	,1	,1	, &B3AD02LDU},	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
	{ 592	,1	,1	, &B3AD03LDU},	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
	{ 593	,1	,1	, &B3AD04LDU},	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
	{ 594	,1	,1	, &B3AD05LDU},	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
	{ 595	,1	,1	, &B3AD01LDU},	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
	{ 596	,8	,1	, &B3CV02RDU},	//( - , DU) Заданная скорость перемещения ИС2
	{ 597	,1	,1	, &B3AB07LDU},	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
	{ 598	,1	,1	, &B1AB14LDU},	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
	{ 599	,1	,1	, &B1AB16LDU},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
	{ 600	,1	,1	, &B1AB17LDU},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
	{ 601	,1	,1	, &B1AB18LDU},	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
	{ 602	,1	,1	, &A3VS12LDU},	//( - , DU) Движение ИС1 в сторону ВУ
	{ 603	,8	,1	, &A3CV01RDU},	//( - , DU) Измеренная скорость перемещения ИС1
	{ 604	,1	,1	, &A3AB04LDU},	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
	{ 605	,1	,1	, &A3AB02LDU},	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
	{ 606	,1	,1	, &A3AB01LDU},	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
	{ 607	,1	,1	, &A3VS22LDU},	//( - , DU) Движение ИС1 в сторону НУ
	{ 608	,1	,1	, &A3AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
	{ 609	,1	,1	, &A3AD11LDU},	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
	{ 610	,1	,1	, &A3AD21LDU},	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
	{ 611	,1	,1	, &A3AD02LDU},	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
	{ 612	,1	,1	, &A3AD03LDU},	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
	{ 613	,1	,1	, &A3AD04LDU},	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
	{ 614	,1	,1	, &A3AD05LDU},	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
	{ 615	,1	,1	, &A3AD01LDU},	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
	{ 616	,8	,1	, &A3CV02RDU},	//( - , DU) Заданная скорость перемещения ИС1
	{ 617	,1	,1	, &A3AB07LDU},	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
	{ 618	,1	,1	, &A3AB08LDU},	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
	{ 619	,1	,1	, &A3AB05LDU},	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
	{ 620	,1	,1	, &A3AB06LDU},	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
	{ 621	,1	,1	, &A3AB09LDU},	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
	{ 622	,3	,1	, &R0VL01IDU},	//( - , DU) До импульса минут
	{ 623	,3	,1	, &R0VL11IDU},	//( - , DU) До импульса секунд
	{ 624	,8	,1	, &R0VL06RDU},	//( - , DU) Индикация (Время задержки от ВУ РБ)
	{ 625	,1	,1	, &B3AD33LDU},	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 закрыть (обесточить)
	{ 626	,1	,1	, &B3IS11LDU},	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
	{ 627	,8	,1	, &R0VL02RDU},	//( - , DU) Индикация (Время задержки ИНИ)
	{ 628	,1	,1	, &R8AD21LDU},	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
	{ 629	,1	,1	, &R0AD14LDU},	//( - , DU) Имитация срабатывания верхней АС II УР
	{ 630	,8	,1	, &R0VL04RDU},	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
	{ 631	,1	,1	, &R0AB04LDU},	//( - , DU) Нарушение времени срабатывания верхней АС II УР
	{ 632	,1	,1	, &R0AB06LDU},	//( - , DU) Нарушение времени задержки от ВУ РБ
	{ 633	,1	,1	, &R0AB02LDU},	//( - , DU) Нарушение времени задержки ИНИ
	{ 634	,8	,1	, &R0VL03RDU},	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
	{ 635	,8	,1	, &R0VL05RDU},	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
	{ 636	,3	,1	, &R0VL21IDU},	//( - , DU) Декатрон
	{ 637	,1	,1	, &R0VX03LDU},	//( - , DU) Готовность 2 мин
	{ 638	,3	,1	, &R0VS21IDU},	//( - , DU) Индикация ВИД ПРОВЕРКИ
	{ 639	,3	,1	, &A1VS01IDU},	//( - , DU) Готовность к управлению ББ1
	{ 640	,3	,1	, &B1VS01IDU},	//( - , DU) Готовность к управлению ББ2
	{ 641	,3	,1	, &A3VS01IDU},	//( - , DU) Готовность к управлению ИС1
	{ 642	,3	,1	, &B3VS01IDU},	//( - , DU) Готовность к управлению ИС2
	{ 643	,3	,1	, &A2VS01IDU},	//( - , DU) Готовность к управлению РБ1
	{ 644	,3	,1	, &A4VS01IDU},	//( - , DU) Готовность к управлению НИ1
	{ 645	,1	,1	, &A4VS12LDU},	//( - , DU) Движение НИ1 в сторону ВУ
	{ 646	,1	,1	, &B3AB08LDU},	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
	{ 647	,1	,1	, &B3AB05LDU},	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
	{ 648	,1	,1	, &B3AB06LDU},	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
	{ 649	,1	,1	, &B3AB09LDU},	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
	{ 650	,1	,1	, &B3AB10LDU},	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
	{ 651	,1	,1	, &B3AB11LDU},	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
	{ 652	,1	,1	, &B3AB12LDU},	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{ 653	,1	,1	, &B3AB14LDU},	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
	{ 654	,1	,1	, &B3AB16LDU},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
	{ 655	,1	,1	, &B3AB17LDU},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
	{ 656	,1	,1	, &B3AB18LDU},	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
	{ 657	,1	,1	, &B3AB20LDU},	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
	{ 658	,1	,1	, &C1MD31LP1},	//( - , DU) Кнопка СБРОС ББ
	{ 659	,1	,1	, &C1MD31LP2},	//( - , DU) Кнопка СБРОС ББ
	{ 660	,1	,1	, &A2AD31LDU},	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
	{ 661	,1	,1	, &B2AD31LDU},	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
	{ 662	,1	,1	, &A1AD31LDU},	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
	{ 663	,1	,1	, &B1AD31LDU},	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
	{ 664	,1	,1	, &A2AD32LDU},	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
	{ 665	,1	,1	, &B2AD32LDU},	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
	{ 666	,1	,1	, &A1AD32LDU},	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
	{ 667	,1	,1	, &B1AD32LDU},	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
	{ 668	,1	,1	, &R0MD11LP2},	//( - , DU) Кнопка Пуск проверки схем сброса
	{ 669	,1	,1	, &R0VX01LDU},	//( - , DU) ДО ИМПУЛЬСА
	{ 670	,1	,1	, &B2AB13LDU},	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
	{ 671	,1	,1	, &B2AB14LDU},	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
	{ 672	,1	,1	, &B2AB16LDU},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
	{ 673	,1	,1	, &B2AB17LDU},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
	{ 674	,1	,1	, &R1AZ03LDU},	//( - , DU) Несанкционированное перемещение МДЗ1
	{ 675	,1	,1	, &R1AB01LDU},	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
	{ 676	,1	,1	, &R1AB02LDU},	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
	{ 677	,1	,1	, &R2AZ03LDU},	//( - , DU) Несанкционированное перемещение МДЗ2
	{ 678	,1	,1	, &R2AB01LDU},	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
	{ 679	,1	,1	, &R2AB02LDU},	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
	{ 680	,1	,1	, &R1AB04LDU},	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
	{ 681	,1	,1	, &R2AB04LDU},	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
	{ 682	,1	,1	, &R1AD10LDU},	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
	{ 683	,1	,1	, &R1AD20LDU},	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
	{ 684	,1	,1	, &R1IS11LDU},	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
	{ 685	,1	,1	, &R1VS22LDU},	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
	{ 686	,1	,1	, &R2VS22LDU},	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
	{ 687	,1	,1	, &R2VS12LDU},	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
	{ 688	,1	,1	, &R1VS12LDU},	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
	{ 689	,1	,1	, &R2IS11LDU},	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
	{ 690	,1	,1	, &A1VS12LDU},	//( - , DU) Движение ББ1 в сторону ВУ
	{ 691	,8	,1	, &A1CV01RDU},	//( - , DU) Измеренная скорость перемещения ББ1
	{ 692	,1	,1	, &A1AB04LDU},	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
	{ 693	,1	,1	, &A1AB02LDU},	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
	{ 694	,1	,1	, &A2AB17LDU},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
	{ 695	,1	,1	, &A2AD01LDU},	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
	{ 696	,8	,1	, &A2CV02RDU},	//( - , DU) Заданная скорость перемещения РБ1
	{ 697	,8	,1	, &B2CV01RDU},	//( - , DU) Измеренная скорость перемещения РБ2
	{ 698	,1	,1	, &B2AB04LDU},	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
	{ 699	,1	,1	, &B2AB02LDU},	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
	{ 700	,1	,1	, &B2AB01LDU},	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
	{ 701	,1	,1	, &B2AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
	{ 702	,1	,1	, &B2AD11LDU},	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
	{ 703	,1	,1	, &B2AD21LDU},	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
	{ 704	,1	,1	, &B2AD02LDU},	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
	{ 705	,1	,1	, &B2AD03LDU},	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
	{ 706	,1	,1	, &B2AD04LDU},	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
	{ 707	,1	,1	, &B2AD05LDU},	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
	{ 708	,1	,1	, &B2AD01LDU},	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
	{ 709	,8	,1	, &B2CV02RDU},	//( - , DU) Заданная скорость перемещения РБ2
	{ 710	,1	,1	, &B2AB07LDU},	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
	{ 711	,1	,1	, &B2AB08LDU},	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
	{ 712	,1	,1	, &B2AB05LDU},	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
	{ 713	,1	,1	, &B2AB06LDU},	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
	{ 714	,1	,1	, &B2AB09LDU},	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
	{ 715	,1	,1	, &B2AB10LDU},	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
	{ 716	,1	,1	, &B2AB11LDU},	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
	{ 717	,1	,1	, &B2AB12LDU},	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{ 718	,1	,1	, &B1VS12LDU},	//( - , DU) Движение ББ2 в сторону ВУ
	{ 719	,8	,1	, &B1CV01RDU},	//( - , DU) Измеренная скорость перемещения ББ2
	{ 720	,1	,1	, &B1AB04LDU},	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
	{ 721	,1	,1	, &B1AB02LDU},	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
	{ 722	,1	,1	, &B1AB01LDU},	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
	{ 723	,1	,1	, &B1VS22LDU},	//( - , DU) Движение ББ2 в сторону НУ
	{ 724	,1	,1	, &B1AZ03LDU},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
	{ 725	,1	,1	, &B1AD11LDU},	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
	{ 726	,1	,1	, &B1AD21LDU},	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
	{ 727	,1	,1	, &B1AD02LDU},	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
	{ 728	,1	,1	, &B1AD03LDU},	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
	{ 729	,1	,1	, &B1AD04LDU},	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
	{ 730	,1	,1	, &B1AD05LDU},	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
	{ 731	,1	,1	, &B1AD01LDU},	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
	{ 732	,8	,1	, &B1CV02RDU},	//( - , DU) Заданная скорость перемещения ББ2
	{ 733	,1	,1	, &B1AB07LDU},	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
	{ 734	,1	,1	, &B1AB08LDU},	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
	{ 735	,1	,1	, &B1AB05LDU},	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
	{ 736	,1	,1	, &B1AB06LDU},	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
	{ 737	,1	,1	, &B1AB09LDU},	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
	{ 738	,1	,1	, &B1AB10LDU},	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
	{ 739	,1	,1	, &B1AB11LDU},	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
	{ 740	,1	,1	, &B1AB12LDU},	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 741	,1	,1	, &B1AB13LDU},	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
	{ 742	,1	,1	, &A1AB01LDU},	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
	{ 743	,1	,1	, &A1VS22LDU},	//( - , DU) Движение ББ1 в сторону НУ
	{ 744	,1	,1	, &A1AZ03LDU},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
	{ 745	,1	,1	, &A1AD11LDU},	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
	{ 746	,1	,1	, &A1AD21LDU},	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
	{ 747	,1	,1	, &A1AD02LDU},	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
	{ 748	,1	,1	, &A1AD03LDU},	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
	{ 749	,1	,1	, &A1AD04LDU},	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
	{ 750	,1	,1	, &A1AD05LDU},	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
	{ 751	,1	,1	, &A1AD01LDU},	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
	{ 752	,8	,1	, &A1CV02RDU},	//( - , DU) Заданная скорость перемещения ББ1
	{ 753	,1	,1	, &A1AB07LDU},	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
	{ 754	,1	,1	, &A1AB08LDU},	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
	{ 755	,1	,1	, &A1AB05LDU},	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
	{ 756	,1	,1	, &A1AB06LDU},	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
	{ 757	,1	,1	, &A1AB09LDU},	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
	{ 758	,1	,1	, &A1AB10LDU},	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
	{ 759	,1	,1	, &A1AB11LDU},	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
	{ 760	,1	,1	, &A1AB12LDU},	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 761	,1	,1	, &A1AB13LDU},	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
	{ 762	,1	,1	, &A1AB14LDU},	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
	{ 763	,1	,1	, &A1AB16LDU},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
	{ 764	,1	,1	, &A1AB17LDU},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
	{ 765	,1	,1	, &A1AB18LDU},	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
	{ 766	,8	,1	, &fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
	{ 767	,5	,1	, &dEM_A1UC05UDU},	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
	{ 768	,5	,1	, &dEM_A1UC06UDU},	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
	{ 769	,5	,1	, &dEM_A2UC06UDU},	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
	{ 770	,5	,1	, &dEM_A2UC05UDU},	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
	{ 771	,8	,1	, &fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
	{ 772	,5	,1	, &dEM_A3UC06UDU},	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
	{ 773	,5	,1	, &dEM_A3UC05UDU},	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
	{ 774	,8	,1	, &fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
	{ 775	,5	,1	, &dEM_A8UC06UDU},	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
	{ 776	,8	,1	, &fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
	{ 777	,5	,1	, &dEM_A8UC05UDU},	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
	{ 778	,8	,1	, &fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{ 779	,8	,1	, &fEM_R0UV82RDU},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{ 780	,8	,1	, &fEM_R0UV83RDU},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{ 781	,8	,1	, &fEM_R0UV84RDU},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{ 782	,8	,1	, &fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 783	,8	,1	, &fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{ 784	,8	,1	, &fEM_R0UV87RDU},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 785	,8	,1	, &fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{ 786	,8	,1	, &fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{ 787	,8	,1	, &fEM_A3UP43RDU},	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
	{ 788	,8	,1	, &fEM_A3UP44RDU},	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
	{ 789	,8	,1	, &fEM_A3UP53RDU},	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
	{ 790	,8	,1	, &fEM_A3UP85RDU},	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 791	,8	,1	, &fEM_A3UP88RDU},	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 792	,8	,1	, &fEM_A3UP86RDU},	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 793	,8	,1	, &fEM_B8UV01RDU},	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
	{ 794	,8	,1	, &fEM_B8UV02RDU},	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
	{ 795	,8	,1	, &fEM_B8UV03RDU},	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
	{ 796	,8	,1	, &fEM_B8UL04RDU},	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
	{ 797	,3	,1	, &iEM_A2UV03CDU},	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
	{ 798	,8	,1	, &fEM_A2UV01RDU},	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
	{ 799	,8	,1	, &fEM_A2UV02RDU},	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
	{ 800	,8	,1	, &fEM_A1UV01RDU},	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
	{ 801	,8	,1	, &fEM_A1UV02RDU},	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
	{ 802	,8	,1	, &fEM_A1UC06RDU},	//(A1UC06RDU) Уставка определения самохода ББ  мм
	{ 803	,8	,1	, &fEM_A1UC05RDU},	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
	{ 804	,8	,1	, &fEM_A1UL04RDU},	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
	{ 805	,8	,1	, &fEM_A3UV01RDU},	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
	{ 806	,8	,1	, &fEM_A3UV02RDU},	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
	{ 807	,8	,1	, &fEM_A3UC06RDU},	//(A3UC06RDU) Уставка определения самохода ИС1  мм
	{ 808	,8	,1	, &fEM_A3UC05RDU},	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
	{ 809	,8	,1	, &fEM_A3UL04RDU},	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
	{ 810	,8	,1	, &fEM_A3UP54RDU},	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
	{ 811	,8	,1	, &fEM_A3UP87RDU},	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 812	,8	,1	, &fEM_R0UL05RDU},	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
	{ 813	,8	,1	, &fEM_R0UL20RDU},	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
	{ 814	,8	,1	, &fEM_B8UV04RDU},	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
	{ 815	,8	,1	, &fEM_B8UC06RDU},	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
	{ 816	,8	,1	, &fEM_B8UC05RDU},	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
	{ 817	,8	,1	, &fEM_A2UL05RDU},	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
	{ 818	,8	,1	, &fEM_A2UL03RDU},	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{ 819	,8	,1	, &fEM_A2UC06RDU},	//(A2UC06RDU) Уставка определения самохода РБ  мм
	{ 820	,8	,1	, &fEM_A2UC05RDU},	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
	{ 821	,8	,1	, &fEM_A2UL04RDU},	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
	{ 822	,8	,1	, &fEM_A1UL03RDU},	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
	{ 823	,8	,1	, &fEM_A1UL05RDU},	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
	{ 824	,8	,1	, &fEM_A3UL03RDU},	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
	{ 825	,8	,1	, &fEM_A3UL05RDU},	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
	{ 826	,8	,1	, &fEM_A1UC08RDU},	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
	{ 827	,8	,1	, &fEM_A3UC08RDU},	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
	{ 828	,8	,1	, &fEM_A1UC07RDU},	//(A1UC07RDU) Зона возврата при наведении ББ мм
	{ 829	,8	,1	, &fEM_A1UL01RDU},	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 830	,8	,1	, &fEM_A3UC07RDU},	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
	{ 831	,8	,1	, &fEM_A3UL01RDU},	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 832	,8	,1	, &fEM_A2UC08RDU},	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
	{ 833	,8	,1	, &fEM_A2UC07RDU},	//(A2UC07RDU) Зона возврата при наведении РБ  мм
	{ 834	,8	,1	, &fEM_A2UL01RDU},	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 835	,8	,1	, &fEM_B8UC01RDU},	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
	{ 836	,8	,1	, &fEM_B8UL07RDU},	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
	{ 837	,8	,1	, &fEM_B8UC02RDU},	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
	{ 838	,8	,1	, &fEM_B8UL01RDU},	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 839	,8	,1	, &fEM_B8UL05RDU},	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
	{ 840	,8	,1	, &fEM_B8UL03RDU},	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
	{ 841	,8	,1	, &fEM_B8UL06RDU},	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
	{ 842	,8	,1	, &fEM_A9UZ03RDU},	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
	{ 843	,8	,1	, &fEM_A9UZ04RDU},	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
	{ 844	,8	,1	, &fEM_A9UZ05RDU},	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
	{ 845	,8	,1	, &fEM_R4UZ04RDU},	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
	{ 846	,8	,1	, &fEM_R4UZ03RDU},	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
	{ 847	,8	,1	, &fEM_R4UZ05RDU},	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
	{ 848	,8	,1	, &fEM_A5UZ03RDU},	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
	{ 849	,8	,1	, &fEM_A5UZ04RDU},	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
	{ 850	,8	,1	, &fEM_A5UZ05RDU},	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
	{ 851	,8	,1	, &fEM_A4UZ03RDU},	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
	{ 852	,8	,1	, &fEM_A4UZ04RDU},	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
	{ 853	,8	,1	, &fEM_A4UZ05RDU},	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
	{ 854	,8	,1	, &fEM_A6UZ03RDU},	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
	{ 855	,8	,1	, &fEM_A6UZ04RDU},	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
	{ 856	,8	,1	, &fEM_A6UZ05RDU},	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
	{ 857	,8	,1	, &fEM_R1UZ03RDU},	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
	{ 858	,8	,1	, &fEM_R1UZ04RDU},	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
	{ 859	,8	,1	, &fEM_R1UZ05RDU},	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
	{ 860	,8	,1	, &fEM_R0UL04RDU},	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
	{ 861	,8	,1	, &fEM_R0UL06RDU},	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
	{ 862	,8	,1	, &fEM_R0UL03RDU},	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
	{ 863	,8	,1	, &fEM_R0UL17RDU},	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
	{ 864	,8	,1	, &fEM_R0UL19RDU},	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{ 865	,8	,1	, &fEM_R0UL07RDU},	//(R0UL07RDU) Время срабатывания верхней АС II УР
	{ 866	,8	,1	, &fEM_R0UL18RDU},	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
	{ 867	,8	,1	, &fEM_R0UL16RDU},	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
	{ 868	,8	,1	, &fEM_R0UL02RDU},	//(R0UL02RDU) Время задержки  ИНИ
	{ 869	,8	,1	, &fEM_R0UN08RDU},	//(R0UN08RDU) 8-я заданная мощность
	{ 870	,8	,1	, &fEM_R0UN07RDU},	//(R0UN07RDU) 7-я заданная мощность
	{ 871	,8	,1	, &fEM_R0UN06RDU},	//(R0UN06RDU) 6-я заданная мощность
	{ 872	,8	,1	, &fEM_R0UN05RDU},	//(R0UN05RDU) 5-я заданная мощность
	{ 873	,8	,1	, &fEM_R0UN04RDU},	//(R0UN04RDU) 4-я заданная мощность
	{ 874	,8	,1	, &fEM_R0UN03RDU},	//(R0UN03RDU) Ограничение 3 по мощности
	{ 875	,8	,1	, &fEM_R0UN02RDU},	//(R0UN02RDU) 2-я заданная мощность
	{ 876	,8	,1	, &fEM_R0UN01RDU},	//(R0UN01RDU) 1-я заданная мощность
	{ 877	,8	,1	, &fEM_A2UC82RDU},	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
	{ 878	,8	,1	, &fEM_A2UC83RDU},	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
	{ 879	,8	,1	, &fEM_A1UC83RDU},	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
	{ 880	,8	,1	, &fEM_A2UC81RDU},	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
	{ 881	,8	,1	, &fEM_A1UC81RDU},	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
	{ 882	,8	,1	, &fEM_A1UC82RDU},	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
	{ 883	,8	,1	, &fEM_A2UL83RDU},	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{ 884	,8	,1	, &fEM_A3UC81RDU},	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
	{ 885	,8	,1	, &fEM_A3UC82RDU},	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
	{ 886	,8	,1	, &fEM_R0UN80RDU},	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
	{ 887	,3	,1	, &iEM_A2UV01IDU},	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
	{ 888	,3	,1	, &iEM_A2UV02IDU},	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
	{ 889	,3	,1	, &iEM_A1UV01IDU},	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
	{ 890	,3	,1	, &iEM_A1UV02IDU},	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
	{ 891	,3	,1	, &iEM_A1UV03IDU},	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
	{ 892	,3	,1	, &iEM_A3UV01IDU},	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
	{ 893	,3	,1	, &iEM_A3UV02IDU},	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
	{ 894	,1	,1	, &lEM_R0MD01LC1},	//(R0MD01LC1) Ручное управление ОРР
	{ 895	,8	,1	, &fEM_A3UC09RDU},	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
	{ 896	,8	,1	, &fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
	{ 897	,8	,1	, &fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
	{ 898	,8	,1	, &fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
	{ 899	,8	,1	, &fEM_R0UL21RDU},	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
	{ 900	,8	,1	, &fEM_R0UN09RDU},	//(R0UN09RDU) Минимальный период при регулировании мощности
	{ 901	,8	,1	, &fEM_R0UN11RDU},	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
	{ 902	,8	,1	, &fEM_R0UN12RDU},	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
	{ 903	,8	,1	, &fEM_R0UN13RDU},	//(R0UN13RDU) Минимальное изменение координаты, мм
	{ 904	,8	,1	, &fEM_R0UN14RDU},	//(R0UN14RDU) Максимальная координата штока ИМ, мм
	{ 905	,8	,1	, &fEM_R0UN16RDU},	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
	{ 906	,8	,1	, &fEM_R0UN17RDU},	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
	{ 907	,8	,1	, &fEM_R0UN18RDU},	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
	{ 908	,8	,1	, &fEM_R0UN19RDU},	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
	{ 909	,8	,1	, &fEM_R0UN70LDU},	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
	{ 910	,8	,1	, &fEM_R0UN71LDU},	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
	{ 911	,8	,1	, &fEM_R0UN72LDU},	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
	{ 912	,8	,1	, &fEM_R0UN73LDU},	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
	{ 913	,8	,1	, &fEM_R0UN74LDU},	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
	{ 914	,8	,1	, &fEM_R0UN75LDU},	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
	{ 915	,8	,1	, &fEM_R0UN80LDU},	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
	{ 916	,8	,1	, &fEM_R0UN81LDU},	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
	{ 917	,8	,1	, &fEM_R0UN82LDU},	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
	{ 918	,8	,1	, &fEM_R0UN83LDU},	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
	{ 919	,8	,1	, &fEM_R0UN84LDU},	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
	{ 920	,8	,1	, &fEM_R0UN85LDU},	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
	{ 921	,8	,1	, &fEM_R0UT20RDU},	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
	{ 922	,8	,1	, &fEM_R0UN25RDU},	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
	{ 923	,8	,1	, &fEM_R0UN15RDU},	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
	{ 924	,8	,1	, &fEM_R0UN26RDU},	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
	{ 925	,8	,1	, &fEM_R0UN27RDU},	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
	{ 926	,8	,1	, &fEM_R0UN24RDU},	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 927	,8	,1	, &fEM_R0UL25RDU},	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{ 928	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 929	,8	,1	, &internal2_m186_y0},	//(internal2_m186_y0) y0
	{ 930	,8	,1	, &internal2_m184_y0},	//(internal2_m184_y0) y0
	{ 931	,1	,1	, &internal2_m216_y0},	//(internal2_m216_y0) state
	{ 932	,1	,1	, &internal2_m210_y0},	//(internal2_m210_y0) state
	{ 933	,1	,1	, &internal2_m199_y1},	//(internal2_m199_y1) y1 - внутренний параметр
	{ 934	,1	,1	, &internal2_m206_y1},	//(internal2_m206_y1) y1 - внутренний параметр
	{ 935	,1	,1	, &internal2_m189_y1},	//(internal2_m189_y1) y1 - внутренний параметр
	{ 936	,1	,1	, &internal2_m196_y1},	//(internal2_m196_y1) y1 - внутренний параметр
	{ 937	,5	,1	, &internal2_m16_Nk0},	//(internal2_m16_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 938	,1	,1	, &internal2_m16_SetFlag},	//(internal2_m16_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 939	,5	,1	, &internal2_m108_Nk0},	//(internal2_m108_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 940	,1	,1	, &internal2_m108_SetFlag},	//(internal2_m108_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 941	,5	,1	, &internal2_m112_Nk0},	//(internal2_m112_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 942	,1	,1	, &internal2_m112_SetFlag},	//(internal2_m112_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 943	,5	,1	, &internal2_m75_Nk0},	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 944	,1	,1	, &internal2_m75_SetFlag},	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 945	,5	,1	, &internal2_m77_Nk0},	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 946	,1	,1	, &internal2_m77_SetFlag},	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 947	,5	,1	, &internal2_m47_Nk0},	//(internal2_m47_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 948	,1	,1	, &internal2_m47_SetFlag},	//(internal2_m47_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 949	,5	,1	, &internal2_m51_Nk0},	//(internal2_m51_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 950	,1	,1	, &internal2_m51_SetFlag},	//(internal2_m51_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 951	,5	,1	, &internal2_m21_Nk0},	//(internal2_m21_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 952	,1	,1	, &internal2_m21_SetFlag},	//(internal2_m21_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 953	,1	,1	, &internal1_m198_s},	//(internal1_m198_s) s - запомнили значение
	{ 954	,1	,1	, &internal1_m195_s},	//(internal1_m195_s) s - запомнили значение
	{ 955	,1	,1	, &internal1_m188_s},	//(internal1_m188_s) s - запомнили значение
	{ 956	,1	,1	, &internal1_m183_s},	//(internal1_m183_s) s - запомнили значение
	{ 957	,1	,1	, &internal1_m179_s},	//(internal1_m179_s) s - запомнили значение
	{ 958	,1	,1	, &internal1_m1710_q0},	//(internal1_m1710_q0) q0 - внутренний параметр
	{ 959	,1	,1	, &internal1_m2145_q0},	//(internal1_m2145_q0) q0 - внутренний параметр
	{ 960	,1	,1	, &internal1_m2129_q0},	//(internal1_m2129_q0) q0 - внутренний параметр
	{ 961	,1	,1	, &internal1_m2177_q0},	//(internal1_m2177_q0) q0 - внутренний параметр
	{ 962	,1	,1	, &internal1_m2161_q0},	//(internal1_m2161_q0) q0 - внутренний параметр
	{ 963	,1	,1	, &internal1_m2151_q0},	//(internal1_m2151_q0) q0 - внутренний параметр
	{ 964	,1	,1	, &internal1_m2132_q0},	//(internal1_m2132_q0) q0 - внутренний параметр
	{ 965	,1	,1	, &internal1_m2149_q0},	//(internal1_m2149_q0) q0 - внутренний параметр
	{ 966	,1	,1	, &internal1_m2130_q0},	//(internal1_m2130_q0) q0 - внутренний параметр
	{ 967	,1	,1	, &internal1_m2128_q0},	//(internal1_m2128_q0) q0 - внутренний параметр
	{ 968	,1	,1	, &internal1_m2127_q0},	//(internal1_m2127_q0) q0 - внутренний параметр
	{ 969	,1	,1	, &internal1_m2141_q0},	//(internal1_m2141_q0) q0 - внутренний параметр
	{ 970	,1	,1	, &internal1_m2139_q0},	//(internal1_m2139_q0) q0 - внутренний параметр
	{ 971	,1	,1	, &internal1_m2147_q0},	//(internal1_m2147_q0) q0 - внутренний параметр
	{ 972	,1	,1	, &internal1_m2143_q0},	//(internal1_m2143_q0) q0 - внутренний параметр
	{ 973	,1	,1	, &internal1_m2183_q0},	//(internal1_m2183_q0) q0 - внутренний параметр
	{ 974	,1	,1	, &internal1_m2164_q0},	//(internal1_m2164_q0) q0 - внутренний параметр
	{ 975	,1	,1	, &internal1_m2181_q0},	//(internal1_m2181_q0) q0 - внутренний параметр
	{ 976	,1	,1	, &internal1_m2163_q0},	//(internal1_m2163_q0) q0 - внутренний параметр
	{ 977	,1	,1	, &internal1_m2160_q0},	//(internal1_m2160_q0) q0 - внутренний параметр
	{ 978	,1	,1	, &internal1_m2159_q0},	//(internal1_m2159_q0) q0 - внутренний параметр
	{ 979	,1	,1	, &internal1_m2173_q0},	//(internal1_m2173_q0) q0 - внутренний параметр
	{ 980	,1	,1	, &internal1_m2171_q0},	//(internal1_m2171_q0) q0 - внутренний параметр
	{ 981	,8	,1	, &internal1_m2048_tx},	//(internal1_m2048_tx) tx - внутренний параметр
	{ 982	,8	,1	, &internal1_m2027_tx},	//(internal1_m2027_tx) tx - внутренний параметр
	{ 983	,1	,1	, &internal1_m1734_Pv0},	//(internal1_m1734_Pv0)  - Пер. выключатель механизма
	{ 984	,1	,1	, &internal1_m1734_Zv0},	//(internal1_m1734_Zv0)  - Зад. выключатель механизма
	{ 985	,1	,1	, &internal1_m1734_MyFirstEnterFlag},	//(internal1_m1734_MyFirstEnterFlag) MyFirstEnterFlag
	{ 986	,1	,1	, &internal1_m1731_Pv0},	//(internal1_m1731_Pv0)  - Пер. выключатель механизма
	{ 987	,1	,1	, &internal1_m1731_Zv0},	//(internal1_m1731_Zv0)  - Зад. выключатель механизма
	{ 988	,1	,1	, &internal1_m1731_MyFirstEnterFlag},	//(internal1_m1731_MyFirstEnterFlag) MyFirstEnterFlag
	{ 989	,8	,1	, &internal1_m2202_tx},	//(internal1_m2202_tx) tx - время накопленное сек
	{ 990	,18	,1	, &internal1_m2202_y0},	//(internal1_m2202_y0) y0
	{ 991	,8	,1	, &internal1_m2206_tx},	//(internal1_m2206_tx) tx - время накопленное сек
	{ 992	,18	,1	, &internal1_m2206_y0},	//(internal1_m2206_y0) y0
	{ 993	,8	,1	, &internal1_m2205_tx},	//(internal1_m2205_tx) tx - время накопленное сек
	{ 994	,18	,1	, &internal1_m2205_y0},	//(internal1_m2205_y0) y0
	{ 995	,8	,1	, &internal1_m2242_tx},	//(internal1_m2242_tx) tx - внутренний параметр
	{ 996	,8	,1	, &internal1_m2240_tx},	//(internal1_m2240_tx) tx - время накопленное сек
	{ 997	,18	,1	, &internal1_m2240_y0},	//(internal1_m2240_y0) y0
	{ 998	,1	,1	, &internal1_m2245_q0},	//(internal1_m2245_q0) q0 - внутренний параметр
	{ 999	,1	,1	, &internal1_m2212_q0},	//(internal1_m2212_q0) q0 - внутренний параметр
	{ 1000	,8	,1	, &internal1_m2220_tx},	//(internal1_m2220_tx) tx - внутренний параметр
	{ 1001	,1	,1	, &internal1_m2218_q0},	//(internal1_m2218_q0) q0 - внутренний параметр
	{ 1002	,8	,1	, &internal1_m2042_tx},	//(internal1_m2042_tx) tx - время накопленное сек
	{ 1003	,18	,1	, &internal1_m2042_y0},	//(internal1_m2042_y0) y0
	{ 1004	,8	,1	, &internal1_m2034_tx},	//(internal1_m2034_tx) tx - время накопленное сек
	{ 1005	,18	,1	, &internal1_m2034_y0},	//(internal1_m2034_y0) y0
	{ 1006	,1	,1	, &internal1_m1720_q0},	//(internal1_m1720_q0) q0 - внутренний параметр
	{ 1007	,1	,1	, &internal1_m1725_q0},	//(internal1_m1725_q0) q0 - внутренний параметр
	{ 1008	,1	,1	, &internal1_m1717_q0},	//(internal1_m1717_q0) q0 - внутренний параметр
	{ 1009	,1	,1	, &internal1_m1759_q0},	//(internal1_m1759_q0) q0 - внутренний параметр
	{ 1010	,8	,1	, &internal1_m759_tx},	//(internal1_m759_tx) tx - время накопленное сек
	{ 1011	,18	,1	, &internal1_m759_y0},	//(internal1_m759_y0) y0
	{ 1012	,8	,1	, &internal1_m2038_tx},	//(internal1_m2038_tx) tx - внутренний параметр
	{ 1013	,1	,1	, &internal1_m2041_q0},	//(internal1_m2041_q0) q0 - внутренний параметр
	{ 1014	,1	,1	, &internal1_m2033_q0},	//(internal1_m2033_q0) q0 - внутренний параметр
	{ 1015	,8	,1	, &internal1_m2003_tx},	//(internal1_m2003_tx) tx - внутренний параметр
	{ 1016	,8	,1	, &internal1_m2014_tx},	//(internal1_m2014_tx) tx - внутренний параметр
	{ 1017	,8	,1	, &internal1_m2000_tx},	//(internal1_m2000_tx) tx - внутренний параметр
	{ 1018	,1	,1	, &internal1_m2006_q0},	//(internal1_m2006_q0) q0 - внутренний параметр
	{ 1019	,1	,1	, &internal1_m2018_q0},	//(internal1_m2018_q0) q0 - внутренний параметр
	{ 1020	,8	,1	, &internal1_m1976_tx},	//(internal1_m1976_tx) tx - внутренний параметр
	{ 1021	,8	,1	, &internal1_m57_tx},	//(internal1_m57_tx) tx - внутренний параметр
	{ 1022	,8	,1	, &internal1_m356_tx},	//(internal1_m356_tx) tx - внутренний параметр
	{ 1023	,8	,1	, &internal1_m312_tx},	//(internal1_m312_tx) tx - внутренний параметр
	{ 1024	,8	,1	, &internal1_m760_tx},	//(internal1_m760_tx) tx - внутренний параметр
	{ 1025	,8	,1	, &internal1_m1440_tx},	//(internal1_m1440_tx) tx - внутренний параметр
	{ 1026	,8	,1	, &internal1_m119_tx},	//(internal1_m119_tx) tx - внутренний параметр
	{ 1027	,8	,1	, &internal1_m121_tx},	//(internal1_m121_tx) tx - внутренний параметр
	{ 1028	,8	,1	, &internal1_m126_tx},	//(internal1_m126_tx) tx - внутренний параметр
	{ 1029	,8	,1	, &internal1_m24_tx},	//(internal1_m24_tx) tx - внутренний параметр
	{ 1030	,8	,1	, &internal1_m16_tx},	//(internal1_m16_tx) tx - внутренний параметр
	{ 1031	,8	,1	, &internal1_m1985_tx},	//(internal1_m1985_tx) tx - внутренний параметр
	{ 1032	,8	,1	, &internal1_m1973_tx},	//(internal1_m1973_tx) tx - внутренний параметр
	{ 1033	,8	,1	, &internal1_m2081_tx},	//(internal1_m2081_tx) tx - внутренний параметр
	{ 1034	,8	,1	, &internal1_m2085_tx},	//(internal1_m2085_tx) tx - внутренний параметр
	{ 1035	,8	,1	, &internal1_m1898_tx},	//(internal1_m1898_tx) tx - внутренний параметр
	{ 1036	,8	,1	, &internal1_m83_tx},	//(internal1_m83_tx) tx - внутренний параметр
	{ 1037	,8	,1	, &internal1_m325_tx},	//(internal1_m325_tx) tx - время накопленное сек
	{ 1038	,18	,1	, &internal1_m325_y0},	//(internal1_m325_y0) y0
	{ 1039	,8	,1	, &internal1_m1892_tx},	//(internal1_m1892_tx) tx - время накопленное сек
	{ 1040	,18	,1	, &internal1_m1892_y0},	//(internal1_m1892_y0) y0
	{ 1041	,8	,1	, &internal1_m1890_tx},	//(internal1_m1890_tx) tx - время накопленное сек
	{ 1042	,18	,1	, &internal1_m1890_y0},	//(internal1_m1890_y0) y0
	{ 1043	,8	,1	, &internal1_m1879_tx},	//(internal1_m1879_tx) tx - время накопленное сек
	{ 1044	,18	,1	, &internal1_m1879_y0},	//(internal1_m1879_y0) y0
	{ 1045	,8	,1	, &internal1_m1899_q0},	//(internal1_m1899_q0) q0 - внутренний параметр
	{ 1046	,8	,1	, &internal1_m1460_q0},	//(internal1_m1460_q0) q0 - внутренний параметр
	{ 1047	,8	,1	, &internal1_m1499_q0},	//(internal1_m1499_q0) q0 - внутренний параметр
	{ 1048	,8	,1	, &internal1_m1497_q0},	//(internal1_m1497_q0) q0 - внутренний параметр
	{ 1049	,8	,1	, &internal1_m1938_q0},	//(internal1_m1938_q0) q0 - внутренний параметр
	{ 1050	,8	,1	, &internal1_m1916_tx},	//(internal1_m1916_tx) tx - время накопленное сек
	{ 1051	,18	,1	, &internal1_m1916_y0},	//(internal1_m1916_y0) y0
	{ 1052	,8	,1	, &internal1_m1931_tx},	//(internal1_m1931_tx) tx - время накопленное сек
	{ 1053	,18	,1	, &internal1_m1931_y0},	//(internal1_m1931_y0) y0
	{ 1054	,8	,1	, &internal1_m1928_tx},	//(internal1_m1928_tx) tx - время накопленное сек
	{ 1055	,18	,1	, &internal1_m1928_y0},	//(internal1_m1928_y0) y0
	{ 1056	,8	,1	, &internal1_m2064_tx},	//(internal1_m2064_tx) tx - время накопленное сек
	{ 1057	,18	,1	, &internal1_m2064_y0},	//(internal1_m2064_y0) y0
	{ 1058	,8	,1	, &internal1_m2075_tx},	//(internal1_m2075_tx) tx - время накопленное сек
	{ 1059	,18	,1	, &internal1_m2075_y0},	//(internal1_m2075_y0) y0
	{ 1060	,8	,1	, &internal1_m1827_tx},	//(internal1_m1827_tx) tx - время накопленное сек
	{ 1061	,18	,1	, &internal1_m1827_y0},	//(internal1_m1827_y0) y0
	{ 1062	,8	,1	, &internal1_m1826_tx},	//(internal1_m1826_tx) tx - время накопленное сек
	{ 1063	,18	,1	, &internal1_m1826_y0},	//(internal1_m1826_y0) y0
	{ 1064	,8	,1	, &internal1_m1825_tx},	//(internal1_m1825_tx) tx - время накопленное сек
	{ 1065	,18	,1	, &internal1_m1825_y0},	//(internal1_m1825_y0) y0
	{ 1066	,8	,1	, &internal1_m1824_tx},	//(internal1_m1824_tx) tx - время накопленное сек
	{ 1067	,18	,1	, &internal1_m1824_y0},	//(internal1_m1824_y0) y0
	{ 1068	,8	,1	, &internal1_m1512_tx},	//(internal1_m1512_tx) tx - время накопленное сек
	{ 1069	,18	,1	, &internal1_m1512_y0},	//(internal1_m1512_y0) y0
	{ 1070	,8	,1	, &internal1_m1506_tx},	//(internal1_m1506_tx) tx - время накопленное сек
	{ 1071	,18	,1	, &internal1_m1506_y0},	//(internal1_m1506_y0) y0
	{ 1072	,8	,1	, &internal1_m1456_tx},	//(internal1_m1456_tx) tx - время накопленное сек
	{ 1073	,18	,1	, &internal1_m1456_y0},	//(internal1_m1456_y0) y0
	{ 1074	,8	,1	, &internal1_m842_tx},	//(internal1_m842_tx) tx - время накопленное сек
	{ 1075	,18	,1	, &internal1_m842_y0},	//(internal1_m842_y0) y0
	{ 1076	,8	,1	, &internal1_m840_tx},	//(internal1_m840_tx) tx - время накопленное сек
	{ 1077	,18	,1	, &internal1_m840_y0},	//(internal1_m840_y0) y0
	{ 1078	,8	,1	, &internal1_m847_tx},	//(internal1_m847_tx) tx - время накопленное сек
	{ 1079	,18	,1	, &internal1_m847_y0},	//(internal1_m847_y0) y0
	{ 1080	,8	,1	, &internal1_m203_tx},	//(internal1_m203_tx) tx - время накопленное сек
	{ 1081	,18	,1	, &internal1_m203_y0},	//(internal1_m203_y0) y0
	{ 1082	,8	,1	, &internal1_m204_tx},	//(internal1_m204_tx) tx - время накопленное сек
	{ 1083	,18	,1	, &internal1_m204_y0},	//(internal1_m204_y0) y0
	{ 1084	,8	,1	, &internal1_m214_tx},	//(internal1_m214_tx) tx - время накопленное сек
	{ 1085	,18	,1	, &internal1_m214_y0},	//(internal1_m214_y0) y0
	{ 1086	,8	,1	, &internal1_m536_tx},	//(internal1_m536_tx) tx - время накопленное сек
	{ 1087	,18	,1	, &internal1_m536_y0},	//(internal1_m536_y0) y0
	{ 1088	,8	,1	, &internal1_m2113_tx},	//(internal1_m2113_tx) tx - внутренний параметр
	{ 1089	,8	,1	, &internal1_m1200_tx},	//(internal1_m1200_tx) tx - внутренний параметр
	{ 1090	,8	,1	, &internal1_m1626_tx},	//(internal1_m1626_tx) tx - время накопленное сек
	{ 1091	,18	,1	, &internal1_m1626_y0},	//(internal1_m1626_y0) y0
	{ 1092	,8	,1	, &internal1_m1151_tx},	//(internal1_m1151_tx) tx - время накопленное сек
	{ 1093	,18	,1	, &internal1_m1151_y0},	//(internal1_m1151_y0) y0
	{ 1094	,8	,1	, &internal1_m1352_tx},	//(internal1_m1352_tx) tx - время накопленное сек
	{ 1095	,18	,1	, &internal1_m1352_y0},	//(internal1_m1352_y0) y0
	{ 1096	,8	,1	, &internal1_m940_tx},	//(internal1_m940_tx) tx - время накопленное сек
	{ 1097	,18	,1	, &internal1_m940_y0},	//(internal1_m940_y0) y0
	{ 1098	,8	,1	, &internal1_m1259_tx},	//(internal1_m1259_tx) tx - время накопленное сек
	{ 1099	,18	,1	, &internal1_m1259_y0},	//(internal1_m1259_y0) y0
	{ 1100	,1	,1	, &internal1_m1092_q0},	//(internal1_m1092_q0) q0 - внутренний параметр
	{ 1101	,1	,1	, &internal1_m1090_q0},	//(internal1_m1090_q0) q0 - внутренний параметр
	{ 1102	,1	,1	, &internal1_m1089_q0},	//(internal1_m1089_q0) q0 - внутренний параметр
	{ 1103	,1	,1	, &internal1_m1087_q0},	//(internal1_m1087_q0) q0 - внутренний параметр
	{ 1104	,1	,1	, &internal1_m1086_q0},	//(internal1_m1086_q0) q0 - внутренний параметр
	{ 1105	,1	,1	, &internal1_m1084_q0},	//(internal1_m1084_q0) q0 - внутренний параметр
	{ 1106	,1	,1	, &internal1_m1083_q0},	//(internal1_m1083_q0) q0 - внутренний параметр
	{ 1107	,1	,1	, &internal1_m1081_q0},	//(internal1_m1081_q0) q0 - внутренний параметр
	{ 1108	,1	,1	, &internal1_m1080_q0},	//(internal1_m1080_q0) q0 - внутренний параметр
	{ 1109	,1	,1	, &internal1_m58_x0},	//(internal1_m58_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1110	,1	,1	, &internal1_m1000_q0},	//(internal1_m1000_q0) q0 - внутренний параметр
	{ 1111	,1	,1	, &internal1_m1449_x0},	//(internal1_m1449_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1112	,1	,1	, &internal1_m1493_x0},	//(internal1_m1493_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1113	,1	,1	, &internal1_m1489_x0},	//(internal1_m1489_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1114	,1	,1	, &internal1_m1907_x0},	//(internal1_m1907_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1115	,1	,1	, &internal1_m1872_x0},	//(internal1_m1872_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1116	,1	,1	, &internal1_m1039_q0},	//(internal1_m1039_q0) q0 - внутренний параметр
	{ 1117	,1	,1	, &internal1_m1051_q0},	//(internal1_m1051_q0) q0 - внутренний параметр
	{ 1118	,1	,1	, &internal1_m1063_q0},	//(internal1_m1063_q0) q0 - внутренний параметр
	{ 1119	,1	,1	, &internal1_m1075_q0},	//(internal1_m1075_q0) q0 - внутренний параметр
	{ 1120	,1	,1	, &internal1_m1050_q0},	//(internal1_m1050_q0) q0 - внутренний параметр
	{ 1121	,1	,1	, &internal1_m1065_q0},	//(internal1_m1065_q0) q0 - внутренний параметр
	{ 1122	,1	,1	, &internal1_m1965_q0},	//(internal1_m1965_q0) q0 - внутренний параметр
	{ 1123	,1	,1	, &internal1_m1964_q0},	//(internal1_m1964_q0) q0 - внутренний параметр
	{ 1124	,3	,1	, &internal1_m344_Step},	//(internal1_m344_Step)  - текущий шаг программы
	{ 1125	,18	,10	, &internal1_m344_rz},	//(internal1_m344_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1126	,8	,1	, &internal1_m344_TimS},	//(internal1_m344_TimS) Время от старта программы
	{ 1127	,1	,1	, &internal1_m344_FinPr0},	//(internal1_m344_FinPr0) FinPr - конец программы
	{ 1128	,1	,1	, &internal1_m344_ErrPr0},	//(internal1_m344_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1129	,1	,1	, &internal1_m344_sbINI0},	//(internal1_m344_sbINI0) sbINI - запуск проверки ИНИ
	{ 1130	,1	,1	, &internal1_m344_sbVuIS0},	//(internal1_m344_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1131	,1	,1	, &internal1_m344_sb2UR0},	//(internal1_m344_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1132	,1	,1	, &internal1_m344_sbNupIS0},	//(internal1_m344_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1133	,1	,1	, &internal1_m344_sbVuRB0},	//(internal1_m344_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1134	,1	,1	, &internal1_m344_MyFirstEnterFlag},	//(internal1_m344_MyFirstEnterFlag)  
	{ 1135	,5	,1	, &internal1_m352_x0},	//(internal1_m352_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1136	,5	,1	, &internal1_m311_TimS},	//(internal1_m311_TimS) Время старта
	{ 1137	,3	,1	, &internal1_m287_Step},	//(internal1_m287_Step)  - текущий шаг программы
	{ 1138	,18	,10	, &internal1_m287_rz},	//(internal1_m287_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1139	,8	,1	, &internal1_m287_TimS},	//(internal1_m287_TimS) Время от старта программы
	{ 1140	,1	,1	, &internal1_m287_FinPr0},	//(internal1_m287_FinPr0) FinPr - конец программы
	{ 1141	,1	,1	, &internal1_m287_ErrPr0},	//(internal1_m287_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1142	,1	,1	, &internal1_m287_sbINI0},	//(internal1_m287_sbINI0) sbINI - запуск проверки ИНИ
	{ 1143	,1	,1	, &internal1_m287_sbVuIS0},	//(internal1_m287_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1144	,1	,1	, &internal1_m287_sb2UR0},	//(internal1_m287_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1145	,1	,1	, &internal1_m287_sbNupIS0},	//(internal1_m287_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1146	,1	,1	, &internal1_m287_sbVuRB0},	//(internal1_m287_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1147	,1	,1	, &internal1_m287_MyFirstEnterFlag},	//(internal1_m287_MyFirstEnterFlag)  
	{ 1148	,1	,1	, &internal1_m1423_q0},	//(internal1_m1423_q0) q0 - внутренний параметр
	{ 1149	,3	,1	, &internal1_m1424_Step},	//(internal1_m1424_Step)  - текущий шаг программы
	{ 1150	,18	,6	, &internal1_m1424_rz},	//(internal1_m1424_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1151	,8	,1	, &internal1_m1424_TimS},	//(internal1_m1424_TimS) Время от старта программы
	{ 1152	,1	,1	, &internal1_m1424_FinPr0},	//(internal1_m1424_FinPr0) FinPr - конец программы
	{ 1153	,1	,1	, &internal1_m1424_ErrPr0},	//(internal1_m1424_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1154	,1	,1	, &internal1_m1424_sbINI0},	//(internal1_m1424_sbINI0) sbINI - запуск проверки ИНИ
	{ 1155	,1	,1	, &internal1_m1424_sbVuIS0},	//(internal1_m1424_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1156	,1	,1	, &internal1_m1424_sb2UR0},	//(internal1_m1424_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1157	,1	,1	, &internal1_m1424_sbNupIS0},	//(internal1_m1424_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1158	,1	,1	, &internal1_m1424_sbVuRB0},	//(internal1_m1424_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1159	,1	,1	, &internal1_m1424_MyFirstEnterFlag},	//(internal1_m1424_MyFirstEnterFlag)  
	{ 1160	,1	,1	, &internal1_m1034_q0},	//(internal1_m1034_q0) q0 - внутренний параметр
	{ 1161	,1	,1	, &internal1_m1031_q0},	//(internal1_m1031_q0) q0 - внутренний параметр
	{ 1162	,1	,1	, &internal1_m1033_q0},	//(internal1_m1033_q0) q0 - внутренний параметр
	{ 1163	,1	,1	, &internal1_m1028_q0},	//(internal1_m1028_q0) q0 - внутренний параметр
	{ 1164	,1	,1	, &internal1_m761_q0},	//(internal1_m761_q0) q0 - внутренний параметр
	{ 1165	,1	,1	, &internal1_m354_q0},	//(internal1_m354_q0) q0 - внутренний параметр
	{ 1166	,1	,1	, &internal1_m350_q0},	//(internal1_m350_q0) q0 - внутренний параметр
	{ 1167	,1	,1	, &internal1_m307_q0},	//(internal1_m307_q0) q0 - внутренний параметр
	{ 1168	,5	,1	, &internal1_m306_x0},	//(internal1_m306_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1169	,1	,1	, &internal1_m1894_q0},	//(internal1_m1894_q0) q0 - внутренний параметр
	{ 1170	,1	,1	, &internal1_m1882_q0},	//(internal1_m1882_q0) q0 - внутренний параметр
	{ 1171	,1	,1	, &internal1_m1873_q0},	//(internal1_m1873_q0) q0 - внутренний параметр
	{ 1172	,1	,1	, &internal1_m1948_q0},	//(internal1_m1948_q0) q0 - внутренний параметр
	{ 1173	,1	,1	, &internal1_m1919_q0},	//(internal1_m1919_q0) q0 - внутренний параметр
	{ 1174	,1	,1	, &internal1_m1908_q0},	//(internal1_m1908_q0) q0 - внутренний параметр
	{ 1175	,1	,1	, &internal1_m1476_q0},	//(internal1_m1476_q0) q0 - внутренний параметр
	{ 1176	,1	,1	, &internal1_m1463_x0},	//(internal1_m1463_x0) был приход сигнала x1
	{ 1177	,8	,1	, &internal1_m1463_y0},	//(internal1_m1463_y0) интервал между сигналами х1 и х2
	{ 1178	,1	,1	, &internal1_m1459_q0},	//(internal1_m1459_q0) q0 - внутренний параметр
	{ 1179	,1	,1	, &internal1_m1450_q0},	//(internal1_m1450_q0) q0 - внутренний параметр
	{ 1180	,1	,1	, &internal1_m1509_q0},	//(internal1_m1509_q0) q0 - внутренний параметр
	{ 1181	,1	,1	, &internal1_m1529_q0},	//(internal1_m1529_q0) q0 - внутренний параметр
	{ 1182	,1	,1	, &internal1_m1495_q0},	//(internal1_m1495_q0) q0 - внутренний параметр
	{ 1183	,1	,1	, &internal1_m1510_x0},	//(internal1_m1510_x0) был приход сигнала x1
	{ 1184	,8	,1	, &internal1_m1510_y0},	//(internal1_m1510_y0) интервал между сигналами х1 и х2
	{ 1185	,5	,1	, &internal1_m1434_x0},	//(internal1_m1434_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1186	,1	,1	, &internal1_m1515_q0},	//(internal1_m1515_q0) q0 - внутренний параметр
	{ 1187	,1	,1	, &internal1_m29_q0},	//(internal1_m29_q0) q0 - внутренний параметр
	{ 1188	,1	,1	, &internal1_m1530_q0},	//(internal1_m1530_q0) q0 - внутренний параметр
	{ 1189	,1	,1	, &internal1_m651_q0},	//(internal1_m651_q0) q0 - внутренний параметр
	{ 1190	,1	,1	, &internal1_m636_q0},	//(internal1_m636_q0) q0 - внутренний параметр
	{ 1191	,1	,1	, &internal1_m662_q0},	//(internal1_m662_q0) q0 - внутренний параметр
	{ 1192	,1	,1	, &internal1_m647_q0},	//(internal1_m647_q0) q0 - внутренний параметр
	{ 1193	,1	,1	, &internal1_m631_q0},	//(internal1_m631_q0) q0 - внутренний параметр
	{ 1194	,1	,1	, &internal1_m629_q0},	//(internal1_m629_q0) q0 - внутренний параметр
	{ 1195	,1	,1	, &internal1_m617_q0},	//(internal1_m617_q0) q0 - внутренний параметр
	{ 1196	,5	,1	, &internal1_m1426_q0},	//(internal1_m1426_q0) q0 - внутренний параметр
	{ 1197	,1	,1	, &internal1_m627_q0},	//(internal1_m627_q0) q0 - внутренний параметр
	{ 1198	,1	,1	, &internal1_m115_q0},	//(internal1_m115_q0) q0 - внутренний параметр
	{ 1199	,1	,1	, &internal1_m1662_q0},	//(internal1_m1662_q0) q0 - внутренний параметр
	{ 1200	,1	,1	, &internal1_m1661_q0},	//(internal1_m1661_q0) q0 - внутренний параметр
	{ 1201	,1	,1	, &internal1_m1660_q0},	//(internal1_m1660_q0) q0 - внутренний параметр
	{ 1202	,1	,1	, &internal1_m1659_q0},	//(internal1_m1659_q0) q0 - внутренний параметр
	{ 1203	,1	,1	, &internal1_m1697_q0},	//(internal1_m1697_q0) q0 - внутренний параметр
	{ 1204	,1	,1	, &internal1_m1696_q0},	//(internal1_m1696_q0) q0 - внутренний параметр
	{ 1205	,1	,1	, &internal1_m1695_q0},	//(internal1_m1695_q0) q0 - внутренний параметр
	{ 1206	,1	,1	, &internal1_m1979_q0},	//(internal1_m1979_q0) q0 - внутренний параметр
	{ 1207	,1	,1	, &internal1_m1757_q0},	//(internal1_m1757_q0) q0 - внутренний параметр
	{ 1208	,1	,1	, &internal1_m1746_q0},	//(internal1_m1746_q0) q0 - внутренний параметр
	{ 1209	,1	,1	, &internal1_m1754_q0},	//(internal1_m1754_q0) q0 - внутренний параметр
	{ 1210	,1	,1	, &internal1_m1743_q0},	//(internal1_m1743_q0) q0 - внутренний параметр
	{ 1211	,1	,1	, &internal1_m1751_q0},	//(internal1_m1751_q0) q0 - внутренний параметр
	{ 1212	,1	,1	, &internal1_m2179_q0},	//(internal1_m2179_q0) q0 - внутренний параметр
	{ 1213	,1	,1	, &internal1_m2175_q0},	//(internal1_m2175_q0) q0 - внутренний параметр
	{ 1214	,1	,1	, &internal1_m1722_q0},	//(internal1_m1722_q0) q0 - внутренний параметр
	{ 1215	,1	,1	, &internal1_m1714_q0},	//(internal1_m1714_q0) q0 - внутренний параметр
	{ 1216	,1	,1	, &internal1_m1712_q0},	//(internal1_m1712_q0) q0 - внутренний параметр
	{ 1217	,1	,1	, &internal1_m1708_q0},	//(internal1_m1708_q0) q0 - внутренний параметр
	{ 1218	,1	,1	, &internal1_m1704_q0},	//(internal1_m1704_q0) q0 - внутренний параметр
	{ 1219	,1	,1	, &internal1_m1706_q0},	//(internal1_m1706_q0) q0 - внутренний параметр
	{ 1220	,1	,1	, &internal1_m22_q0},	//(internal1_m22_q0) q0 - внутренний параметр
	{ 1221	,1	,1	, &internal1_m1685_q0},	//(internal1_m1685_q0) q0 - внутренний параметр
	{ 1222	,1	,1	, &internal1_m1683_q0},	//(internal1_m1683_q0) q0 - внутренний параметр
	{ 1223	,1	,1	, &internal1_m1679_q0},	//(internal1_m1679_q0) q0 - внутренний параметр
	{ 1224	,1	,1	, &internal1_m1681_q0},	//(internal1_m1681_q0) q0 - внутренний параметр
	{ 1225	,1	,1	, &internal1_m1677_q0},	//(internal1_m1677_q0) q0 - внутренний параметр
	{ 1226	,1	,1	, &internal1_m1675_q0},	//(internal1_m1675_q0) q0 - внутренний параметр
	{ 1227	,1	,1	, &internal1_m2095_q0},	//(internal1_m2095_q0) q0 - внутренний параметр
	{ 1228	,1	,1	, &internal1_m2090_q0},	//(internal1_m2090_q0) q0 - внутренний параметр
	{ 1229	,1	,1	, &internal1_m2069_q0},	//(internal1_m2069_q0) q0 - внутренний параметр
	{ 1230	,1	,1	, &internal1_m2057_q0},	//(internal1_m2057_q0) q0 - внутренний параметр
	{ 1231	,1	,1	, &internal1_m1990_q0},	//(internal1_m1990_q0) q0 - внутренний параметр
	{ 1232	,1	,1	, &internal1_m1671_q0},	//(internal1_m1671_q0) q0 - внутренний параметр
	{ 1233	,1	,1	, &internal1_m1673_q0},	//(internal1_m1673_q0) q0 - внутренний параметр
	{ 1234	,1	,1	, &internal1_m1657_q0},	//(internal1_m1657_q0) q0 - внутренний параметр
	{ 1235	,1	,1	, &internal1_m1655_q0},	//(internal1_m1655_q0) q0 - внутренний параметр
	{ 1236	,1	,1	, &internal1_m1653_q0},	//(internal1_m1653_q0) q0 - внутренний параметр
	{ 1237	,1	,1	, &internal1_m1651_q0},	//(internal1_m1651_q0) q0 - внутренний параметр
	{ 1238	,1	,1	, &internal1_m1650_q0},	//(internal1_m1650_q0) q0 - внутренний параметр
	{ 1239	,1	,1	, &internal1_m1648_q0},	//(internal1_m1648_q0) q0 - внутренний параметр
	{ 1240	,1	,1	, &internal1_m1647_q0},	//(internal1_m1647_q0) q0 - внутренний параметр
	{ 1241	,1	,1	, &internal1_m1645_q0},	//(internal1_m1645_q0) q0 - внутренний параметр
	{ 1242	,18	,1	, &internal1_m2118_DvUp0},	//(internal1_m2118_DvUp0) - есть команда на движение вперёд
	{ 1243	,18	,1	, &internal1_m2118_DvDw0},	//(internal1_m2118_DvDw0) - есть команда на движение назад
	{ 1244	,18	,1	, &internal1_m2118_FDvUp0},	//(internal1_m2118_FDvUp0) - есть команда на движение вперёд
	{ 1245	,18	,1	, &internal1_m2118_FDvDw0},	//(internal1_m2118_FDvDw0) - есть команда на движение назад
	{ 1246	,18	,1	, &internal1_m2118_BlDv0},	//(internal1_m2118_BlDv0) - была блокировка
	{ 1247	,18	,1	, &internal1_m2118_Pkv0},	//(internal1_m2118_Pkv0) Pkv - передний конечный выключатель
	{ 1248	,18	,1	, &internal1_m2118_Pkav0},	//(internal1_m2118_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1249	,18	,1	, &internal1_m2118_Zkv0},	//(internal1_m2118_Zkv0) Zkv - задний конечный выключатель
	{ 1250	,18	,1	, &internal1_m2118_Zkav0},	//(internal1_m2118_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1251	,8	,1	, &internal1_m2118_txNm},	//(internal1_m2118_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1252	,8	,1	, &internal1_m2118_txSm},	//(internal1_m2118_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1253	,8	,1	, &internal1_m2118_txHr},	//(internal1_m2118_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1254	,8	,1	, &internal1_m2118_txLd},	//(internal1_m2118_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1255	,18	,1	, &internal1_m2118_fef},	//(internal1_m2118_fef) fef
	{ 1256	,18	,1	, &internal1_m2112_DvUp0},	//(internal1_m2112_DvUp0) - есть команда на движение вперёд
	{ 1257	,18	,1	, &internal1_m2112_DvDw0},	//(internal1_m2112_DvDw0) - есть команда на движение назад
	{ 1258	,18	,1	, &internal1_m2112_FDvUp0},	//(internal1_m2112_FDvUp0) - есть команда на движение вперёд
	{ 1259	,18	,1	, &internal1_m2112_FDvDw0},	//(internal1_m2112_FDvDw0) - есть команда на движение назад
	{ 1260	,18	,1	, &internal1_m2112_BlDv0},	//(internal1_m2112_BlDv0) - была блокировка
	{ 1261	,18	,1	, &internal1_m2112_Pkv0},	//(internal1_m2112_Pkv0) Pkv - передний конечный выключатель
	{ 1262	,18	,1	, &internal1_m2112_Pkav0},	//(internal1_m2112_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1263	,18	,1	, &internal1_m2112_Zkv0},	//(internal1_m2112_Zkv0) Zkv - задний конечный выключатель
	{ 1264	,18	,1	, &internal1_m2112_Zkav0},	//(internal1_m2112_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1265	,8	,1	, &internal1_m2112_txNm},	//(internal1_m2112_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1266	,8	,1	, &internal1_m2112_txSm},	//(internal1_m2112_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1267	,8	,1	, &internal1_m2112_txHr},	//(internal1_m2112_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1268	,8	,1	, &internal1_m2112_txLd},	//(internal1_m2112_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1269	,18	,1	, &internal1_m2112_fef},	//(internal1_m2112_fef) fef
	{ 1270	,1	,1	, &internal1_m1501_q0},	//(internal1_m1501_q0) q0 - внутренний параметр
	{ 1271	,1	,1	, &internal1_m1504_x0},	//(internal1_m1504_x0) был приход сигнала x1
	{ 1272	,8	,1	, &internal1_m1504_y0},	//(internal1_m1504_y0) интервал между сигналами х1 и х2
	{ 1273	,1	,1	, &internal1_m1930_x0},	//(internal1_m1930_x0) был приход сигнала x1
	{ 1274	,8	,1	, &internal1_m1930_y0},	//(internal1_m1930_y0) интервал между сигналами х1 и х2
	{ 1275	,1	,1	, &internal1_m1891_x0},	//(internal1_m1891_x0) был приход сигнала x1
	{ 1276	,8	,1	, &internal1_m1891_y0},	//(internal1_m1891_y0) интервал между сигналами х1 и х2
	{ 1277	,1	,1	, &internal1_m298_q0},	//(internal1_m298_q0) q0 - внутренний параметр
	{ 1278	,1	,1	, &internal1_m1008_q0},	//(internal1_m1008_q0) q0 - внутренний параметр
	{ 1279	,1	,1	, &internal1_m639_q0},	//(internal1_m639_q0) q0 - внутренний параметр
	{ 1280	,8	,1	, &internal1_m1323_X0},	//(internal1_m1323_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1281	,8	,1	, &internal1_m1323_t0},	//(internal1_m1323_t0) время нахождения в зоне возврата
	{ 1282	,18	,1	, &internal1_m1323_BLDv0},	//(internal1_m1323_BLDv0) BlDv - Блокировка движения
	{ 1283	,8	,1	, &internal1_m1342_tx},	//(internal1_m1342_tx) tx - время накопленное сек
	{ 1284	,18	,1	, &internal1_m1342_y0},	//(internal1_m1342_y0) y0
	{ 1285	,8	,1	, &internal1_m1343_tx},	//(internal1_m1343_tx) tx - время накопленное сек
	{ 1286	,18	,1	, &internal1_m1343_y0},	//(internal1_m1343_y0) y0
	{ 1287	,3	,1	, &internal1_m1351_xptr},	//(internal1_m1351_xptr) указатель текущей позиции в массиве координат
	{ 1288	,8	,60	, &internal1_m1351_x0},	//(internal1_m1351_x0) x0 - массив мгновенных значений координат
	{ 1289	,8	,60	, &internal1_m1351_tim0},	//(internal1_m1351_tim0) tim0 - массив значений времени цикла
	{ 1290	,8	,1	, &internal1_m1351_sumtim},	//(internal1_m1351_sumtim) sumtim - время в пути
	{ 1291	,8	,1	, &internal1_m1351_StSpeed},	//(internal1_m1351_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1292	,8	,1	, &internal1_m1351_Vz0},	//(internal1_m1351_Vz0) Vz0 - предыдущая заданная скорость
	{ 1293	,3	,1	, &internal1_m1351_flRazg},	//(internal1_m1351_flRazg) признак разгона/торможения
	{ 1294	,8	,1	, &internal1_m1351_DelSp},	//(internal1_m1351_DelSp) DelSp - время переключения скоростей
	{ 1295	,8	,1	, &internal1_m1351_z0},	//(internal1_m1351_z0) z0 - точка прекращения движения
	{ 1296	,8	,1	, &internal1_m1351_txZS},	//(internal1_m1351_txZS) txZS
	{ 1297	,8	,1	, &internal1_m1351_tx},	//(internal1_m1351_tx) tx
	{ 1298	,8	,1	, &internal1_m1351_txd},	//(internal1_m1351_txd) txd
	{ 1299	,8	,1	, &internal1_m1351_txMBl},	//(internal1_m1351_txMBl) tx
	{ 1300	,8	,1	, &internal1_m1351_txBl},	//(internal1_m1351_txBl) tx
	{ 1301	,8	,1	, &internal1_m1351_Speed0},	//(internal1_m1351_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1302	,8	,1	, &internal1_m1351_xz0},	//(internal1_m1351_xz0) xz0 - новое задание мм
	{ 1303	,8	,1	, &internal1_m1351_tz0},	//(internal1_m1351_tz0) tz0 - время защиты от нового задания сек
	{ 1304	,1	,1	, &internal1_m1351_Shift0},	//(internal1_m1351_Shift0) Shift0 - признак самохода
	{ 1305	,1	,1	, &internal1_m1351_ShCntlSp0},	//(internal1_m1351_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1306	,1	,1	, &internal1_m1351_ShiftControl},	//(internal1_m1351_ShiftControl) ShiftControl - признак самохода
	{ 1307	,1	,1	, &internal1_m637_q0},	//(internal1_m637_q0) q0 - внутренний параметр
	{ 1308	,8	,1	, &internal1_m906_X0},	//(internal1_m906_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1309	,8	,1	, &internal1_m906_t0},	//(internal1_m906_t0) время нахождения в зоне возврата
	{ 1310	,18	,1	, &internal1_m906_BLDv0},	//(internal1_m906_BLDv0) BlDv - Блокировка движения
	{ 1311	,8	,1	, &internal1_m930_tx},	//(internal1_m930_tx) tx - время накопленное сек
	{ 1312	,18	,1	, &internal1_m930_y0},	//(internal1_m930_y0) y0
	{ 1313	,8	,1	, &internal1_m931_tx},	//(internal1_m931_tx) tx - время накопленное сек
	{ 1314	,18	,1	, &internal1_m931_y0},	//(internal1_m931_y0) y0
	{ 1315	,3	,1	, &internal1_m939_xptr},	//(internal1_m939_xptr) указатель текущей позиции в массиве координат
	{ 1316	,8	,60	, &internal1_m939_x0},	//(internal1_m939_x0) x0 - массив мгновенных значений координат
	{ 1317	,8	,60	, &internal1_m939_tim0},	//(internal1_m939_tim0) tim0 - массив значений времени цикла
	{ 1318	,8	,1	, &internal1_m939_sumtim},	//(internal1_m939_sumtim) sumtim - время в пути
	{ 1319	,8	,1	, &internal1_m939_StSpeed},	//(internal1_m939_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1320	,8	,1	, &internal1_m939_Vz0},	//(internal1_m939_Vz0) Vz0 - предыдущая заданная скорость
	{ 1321	,3	,1	, &internal1_m939_flRazg},	//(internal1_m939_flRazg) признак разгона/торможения
	{ 1322	,8	,1	, &internal1_m939_DelSp},	//(internal1_m939_DelSp) DelSp - время переключения скоростей
	{ 1323	,8	,1	, &internal1_m939_z0},	//(internal1_m939_z0) z0 - точка прекращения движения
	{ 1324	,8	,1	, &internal1_m939_txZS},	//(internal1_m939_txZS) txZS
	{ 1325	,8	,1	, &internal1_m939_tx},	//(internal1_m939_tx) tx
	{ 1326	,8	,1	, &internal1_m939_txd},	//(internal1_m939_txd) txd
	{ 1327	,8	,1	, &internal1_m939_txMBl},	//(internal1_m939_txMBl) tx
	{ 1328	,8	,1	, &internal1_m939_txBl},	//(internal1_m939_txBl) tx
	{ 1329	,8	,1	, &internal1_m939_Speed0},	//(internal1_m939_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1330	,8	,1	, &internal1_m939_xz0},	//(internal1_m939_xz0) xz0 - новое задание мм
	{ 1331	,8	,1	, &internal1_m939_tz0},	//(internal1_m939_tz0) tz0 - время защиты от нового задания сек
	{ 1332	,1	,1	, &internal1_m939_Shift0},	//(internal1_m939_Shift0) Shift0 - признак самохода
	{ 1333	,1	,1	, &internal1_m939_ShCntlSp0},	//(internal1_m939_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1334	,1	,1	, &internal1_m939_ShiftControl},	//(internal1_m939_ShiftControl) ShiftControl - признак самохода
	{ 1335	,8	,1	, &internal1_m508_X0},	//(internal1_m508_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1336	,8	,1	, &internal1_m508_t0},	//(internal1_m508_t0) время нахождения в зоне возврата
	{ 1337	,18	,1	, &internal1_m508_BLDv0},	//(internal1_m508_BLDv0) BlDv - Блокировка движения
	{ 1338	,8	,1	, &internal1_m528_tx},	//(internal1_m528_tx) tx - время накопленное сек
	{ 1339	,18	,1	, &internal1_m528_y0},	//(internal1_m528_y0) y0
	{ 1340	,8	,1	, &internal1_m529_tx},	//(internal1_m529_tx) tx - время накопленное сек
	{ 1341	,18	,1	, &internal1_m529_y0},	//(internal1_m529_y0) y0
	{ 1342	,3	,1	, &internal1_m535_xptr},	//(internal1_m535_xptr) указатель текущей позиции в массиве координат
	{ 1343	,8	,150	, &internal1_m535_x0},	//(internal1_m535_x0) x0 - массив мгновенных значений координат
	{ 1344	,8	,150	, &internal1_m535_tim0},	//(internal1_m535_tim0) tim0 - массив значений времени цикла
	{ 1345	,8	,1	, &internal1_m535_sumtim},	//(internal1_m535_sumtim) sumtim - время в пути
	{ 1346	,8	,1	, &internal1_m535_StSpeed},	//(internal1_m535_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1347	,8	,1	, &internal1_m535_Vz0},	//(internal1_m535_Vz0) Vz0 - предыдущая заданная скорость
	{ 1348	,3	,1	, &internal1_m535_flRazg},	//(internal1_m535_flRazg) признак разгона/торможения
	{ 1349	,8	,1	, &internal1_m535_DelSp},	//(internal1_m535_DelSp) DelSp - время переключения скоростей
	{ 1350	,8	,1	, &internal1_m535_z0},	//(internal1_m535_z0) z0 - точка прекращения движения
	{ 1351	,8	,1	, &internal1_m535_txZS},	//(internal1_m535_txZS) txZS
	{ 1352	,8	,1	, &internal1_m535_tx},	//(internal1_m535_tx) tx
	{ 1353	,8	,1	, &internal1_m535_txd},	//(internal1_m535_txd) txd
	{ 1354	,8	,1	, &internal1_m535_txMBl},	//(internal1_m535_txMBl) tx
	{ 1355	,8	,1	, &internal1_m535_txBl},	//(internal1_m535_txBl) tx
	{ 1356	,8	,1	, &internal1_m535_Speed0},	//(internal1_m535_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1357	,8	,1	, &internal1_m535_xz0},	//(internal1_m535_xz0) xz0 - новое задание мм
	{ 1358	,8	,1	, &internal1_m535_tz0},	//(internal1_m535_tz0) tz0 - время защиты от нового задания сек
	{ 1359	,1	,1	, &internal1_m535_Shift0},	//(internal1_m535_Shift0) Shift0 - признак самохода
	{ 1360	,1	,1	, &internal1_m535_ShCntlSp0},	//(internal1_m535_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1361	,1	,1	, &internal1_m535_ShiftControl},	//(internal1_m535_ShiftControl) ShiftControl - признак самохода
	{ 1362	,1	,1	, &internal1_m634_q0},	//(internal1_m634_q0) q0 - внутренний параметр
	{ 1363	,8	,1	, &internal1_m174_X0},	//(internal1_m174_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1364	,8	,1	, &internal1_m174_t0},	//(internal1_m174_t0) время нахождения в зоне возврата
	{ 1365	,18	,1	, &internal1_m174_BLDv0},	//(internal1_m174_BLDv0) BlDv - Блокировка движения
	{ 1366	,3	,1	, &internal1_m213_xptr},	//(internal1_m213_xptr) указатель текущей позиции в массиве координат
	{ 1367	,8	,150	, &internal1_m213_x0},	//(internal1_m213_x0) x0 - массив мгновенных значений координат
	{ 1368	,8	,150	, &internal1_m213_tim0},	//(internal1_m213_tim0) tim0 - массив значений времени цикла
	{ 1369	,8	,1	, &internal1_m213_sumtim},	//(internal1_m213_sumtim) sumtim - время в пути
	{ 1370	,8	,1	, &internal1_m213_StSpeed},	//(internal1_m213_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1371	,8	,1	, &internal1_m213_Vz0},	//(internal1_m213_Vz0) Vz0 - предыдущая заданная скорость
	{ 1372	,3	,1	, &internal1_m213_flRazg},	//(internal1_m213_flRazg) признак разгона/торможения
	{ 1373	,8	,1	, &internal1_m213_DelSp},	//(internal1_m213_DelSp) DelSp - время переключения скоростей
	{ 1374	,8	,1	, &internal1_m213_z0},	//(internal1_m213_z0) z0 - точка прекращения движения
	{ 1375	,8	,1	, &internal1_m213_txZS},	//(internal1_m213_txZS) txZS
	{ 1376	,8	,1	, &internal1_m213_tx},	//(internal1_m213_tx) tx
	{ 1377	,8	,1	, &internal1_m213_txd},	//(internal1_m213_txd) txd
	{ 1378	,8	,1	, &internal1_m213_txMBl},	//(internal1_m213_txMBl) tx
	{ 1379	,8	,1	, &internal1_m213_txBl},	//(internal1_m213_txBl) tx
	{ 1380	,8	,1	, &internal1_m213_Speed0},	//(internal1_m213_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1381	,8	,1	, &internal1_m213_xz0},	//(internal1_m213_xz0) xz0 - новое задание мм
	{ 1382	,8	,1	, &internal1_m213_tz0},	//(internal1_m213_tz0) tz0 - время защиты от нового задания сек
	{ 1383	,1	,1	, &internal1_m213_Shift0},	//(internal1_m213_Shift0) Shift0 - признак самохода
	{ 1384	,1	,1	, &internal1_m213_ShCntlSp0},	//(internal1_m213_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1385	,1	,1	, &internal1_m213_ShiftControl},	//(internal1_m213_ShiftControl) ShiftControl - признак самохода
	{ 1386	,1	,1	, &internal1_m660_q0},	//(internal1_m660_q0) q0 - внутренний параметр
	{ 1387	,18	,1	, &internal1_m479_DvUp0},	//(internal1_m479_DvUp0) - есть команда на движение вперёд
	{ 1388	,18	,1	, &internal1_m479_DvDw0},	//(internal1_m479_DvDw0) - есть команда на движение назад
	{ 1389	,18	,1	, &internal1_m479_FDvUp0},	//(internal1_m479_FDvUp0) - есть команда на движение вперёд
	{ 1390	,18	,1	, &internal1_m479_FDvDw0},	//(internal1_m479_FDvDw0) - есть команда на движение назад
	{ 1391	,18	,1	, &internal1_m479_BlDv0},	//(internal1_m479_BlDv0) - была блокировка
	{ 1392	,18	,1	, &internal1_m479_Pkv0},	//(internal1_m479_Pkv0) Pkv - передний конечный выключатель
	{ 1393	,18	,1	, &internal1_m479_Pkav0},	//(internal1_m479_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1394	,18	,1	, &internal1_m479_Zkv0},	//(internal1_m479_Zkv0) Zkv - задний конечный выключатель
	{ 1395	,18	,1	, &internal1_m479_Zkav0},	//(internal1_m479_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1396	,8	,1	, &internal1_m479_txNm},	//(internal1_m479_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1397	,8	,1	, &internal1_m479_txSm},	//(internal1_m479_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1398	,8	,1	, &internal1_m479_txHr},	//(internal1_m479_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1399	,8	,1	, &internal1_m479_txLd},	//(internal1_m479_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1400	,18	,1	, &internal1_m479_fef},	//(internal1_m479_fef) fef
	{ 1401	,18	,1	, &internal1_m473_DvUp0},	//(internal1_m473_DvUp0) - есть команда на движение вперёд
	{ 1402	,18	,1	, &internal1_m473_DvDw0},	//(internal1_m473_DvDw0) - есть команда на движение назад
	{ 1403	,18	,1	, &internal1_m473_FDvUp0},	//(internal1_m473_FDvUp0) - есть команда на движение вперёд
	{ 1404	,18	,1	, &internal1_m473_FDvDw0},	//(internal1_m473_FDvDw0) - есть команда на движение назад
	{ 1405	,18	,1	, &internal1_m473_BlDv0},	//(internal1_m473_BlDv0) - была блокировка
	{ 1406	,18	,1	, &internal1_m473_Pkv0},	//(internal1_m473_Pkv0) Pkv - передний конечный выключатель
	{ 1407	,18	,1	, &internal1_m473_Pkav0},	//(internal1_m473_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1408	,18	,1	, &internal1_m473_Zkv0},	//(internal1_m473_Zkv0) Zkv - задний конечный выключатель
	{ 1409	,18	,1	, &internal1_m473_Zkav0},	//(internal1_m473_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1410	,8	,1	, &internal1_m473_txNm},	//(internal1_m473_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1411	,8	,1	, &internal1_m473_txSm},	//(internal1_m473_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1412	,8	,1	, &internal1_m473_txHr},	//(internal1_m473_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1413	,8	,1	, &internal1_m473_txLd},	//(internal1_m473_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1414	,18	,1	, &internal1_m473_fef},	//(internal1_m473_fef) fef
	{ 1415	,8	,1	, &internal1_m826_X0},	//(internal1_m826_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1416	,8	,1	, &internal1_m826_t0},	//(internal1_m826_t0) время нахождения в зоне возврата
	{ 1417	,18	,1	, &internal1_m826_BLDv0},	//(internal1_m826_BLDv0) BlDv - Блокировка движения
	{ 1418	,3	,1	, &internal1_m846_xptr},	//(internal1_m846_xptr) указатель текущей позиции в массиве координат
	{ 1419	,8	,80	, &internal1_m846_x0},	//(internal1_m846_x0) x0 - массив мгновенных значений координат
	{ 1420	,8	,80	, &internal1_m846_tim0},	//(internal1_m846_tim0) tim0 - массив значений времени цикла
	{ 1421	,8	,1	, &internal1_m846_sumtim},	//(internal1_m846_sumtim) sumtim - время в пути
	{ 1422	,8	,1	, &internal1_m846_StSpeed},	//(internal1_m846_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1423	,8	,1	, &internal1_m846_Vz0},	//(internal1_m846_Vz0) Vz0 - предыдущая заданная скорость
	{ 1424	,3	,1	, &internal1_m846_flRazg},	//(internal1_m846_flRazg) признак разгона/торможения
	{ 1425	,8	,1	, &internal1_m846_DelSp},	//(internal1_m846_DelSp) DelSp - время переключения скоростей
	{ 1426	,8	,1	, &internal1_m846_z0},	//(internal1_m846_z0) z0 - точка прекращения движения
	{ 1427	,8	,1	, &internal1_m846_txZS},	//(internal1_m846_txZS) txZS
	{ 1428	,8	,1	, &internal1_m846_tx},	//(internal1_m846_tx) tx
	{ 1429	,8	,1	, &internal1_m846_txd},	//(internal1_m846_txd) txd
	{ 1430	,8	,1	, &internal1_m846_txMBl},	//(internal1_m846_txMBl) tx
	{ 1431	,8	,1	, &internal1_m846_txBl},	//(internal1_m846_txBl) tx
	{ 1432	,8	,1	, &internal1_m846_Speed0},	//(internal1_m846_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1433	,8	,1	, &internal1_m846_xz0},	//(internal1_m846_xz0) xz0 - новое задание мм
	{ 1434	,8	,1	, &internal1_m846_tz0},	//(internal1_m846_tz0) tz0 - время защиты от нового задания сек
	{ 1435	,1	,1	, &internal1_m846_Shift0},	//(internal1_m846_Shift0) Shift0 - признак самохода
	{ 1436	,1	,1	, &internal1_m846_ShCntlSp0},	//(internal1_m846_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1437	,1	,1	, &internal1_m846_ShiftControl},	//(internal1_m846_ShiftControl) ShiftControl - признак самохода
	{ 1438	,8	,1	, &internal1_m1605_X0},	//(internal1_m1605_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1439	,8	,1	, &internal1_m1605_t0},	//(internal1_m1605_t0) время нахождения в зоне возврата
	{ 1440	,18	,1	, &internal1_m1605_BLDv0},	//(internal1_m1605_BLDv0) BlDv - Блокировка движения
	{ 1441	,8	,1	, &internal1_m1126_X0},	//(internal1_m1126_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1442	,8	,1	, &internal1_m1126_t0},	//(internal1_m1126_t0) время нахождения в зоне возврата
	{ 1443	,18	,1	, &internal1_m1126_BLDv0},	//(internal1_m1126_BLDv0) BlDv - Блокировка движения
	{ 1444	,1	,1	, &internal1_m632_q0},	//(internal1_m632_q0) q0 - внутренний параметр
	{ 1445	,8	,1	, &internal1_m1226_X0},	//(internal1_m1226_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1446	,8	,1	, &internal1_m1226_t0},	//(internal1_m1226_t0) время нахождения в зоне возврата
	{ 1447	,18	,1	, &internal1_m1226_BLDv0},	//(internal1_m1226_BLDv0) BlDv - Блокировка движения
	{ 1448	,8	,1	, &internal1_m1246_tx},	//(internal1_m1246_tx) tx - время накопленное сек
	{ 1449	,18	,1	, &internal1_m1246_y0},	//(internal1_m1246_y0) y0
	{ 1450	,8	,1	, &internal1_m1255_tx},	//(internal1_m1255_tx) tx - время накопленное сек
	{ 1451	,18	,1	, &internal1_m1255_y0},	//(internal1_m1255_y0) y0
	{ 1452	,3	,1	, &internal1_m1261_xptr},	//(internal1_m1261_xptr) указатель текущей позиции в массиве координат
	{ 1453	,8	,80	, &internal1_m1261_x0},	//(internal1_m1261_x0) x0 - массив мгновенных значений координат
	{ 1454	,8	,80	, &internal1_m1261_tim0},	//(internal1_m1261_tim0) tim0 - массив значений времени цикла
	{ 1455	,8	,1	, &internal1_m1261_sumtim},	//(internal1_m1261_sumtim) sumtim - время в пути
	{ 1456	,8	,1	, &internal1_m1261_StSpeed},	//(internal1_m1261_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1457	,8	,1	, &internal1_m1261_Vz0},	//(internal1_m1261_Vz0) Vz0 - предыдущая заданная скорость
	{ 1458	,3	,1	, &internal1_m1261_flRazg},	//(internal1_m1261_flRazg) признак разгона/торможения
	{ 1459	,8	,1	, &internal1_m1261_DelSp},	//(internal1_m1261_DelSp) DelSp - время переключения скоростей
	{ 1460	,8	,1	, &internal1_m1261_z0},	//(internal1_m1261_z0) z0 - точка прекращения движения
	{ 1461	,8	,1	, &internal1_m1261_txZS},	//(internal1_m1261_txZS) txZS
	{ 1462	,8	,1	, &internal1_m1261_tx},	//(internal1_m1261_tx) tx
	{ 1463	,8	,1	, &internal1_m1261_txd},	//(internal1_m1261_txd) txd
	{ 1464	,8	,1	, &internal1_m1261_txMBl},	//(internal1_m1261_txMBl) tx
	{ 1465	,8	,1	, &internal1_m1261_txBl},	//(internal1_m1261_txBl) tx
	{ 1466	,8	,1	, &internal1_m1261_Speed0},	//(internal1_m1261_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1467	,8	,1	, &internal1_m1261_xz0},	//(internal1_m1261_xz0) xz0 - новое задание мм
	{ 1468	,8	,1	, &internal1_m1261_tz0},	//(internal1_m1261_tz0) tz0 - время защиты от нового задания сек
	{ 1469	,1	,1	, &internal1_m1261_Shift0},	//(internal1_m1261_Shift0) Shift0 - признак самохода
	{ 1470	,1	,1	, &internal1_m1261_ShCntlSp0},	//(internal1_m1261_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1471	,1	,1	, &internal1_m1261_ShiftControl},	//(internal1_m1261_ShiftControl) ShiftControl - признак самохода
	{ 1472	,1	,1	, &internal1_m652_q0},	//(internal1_m652_q0) q0 - внутренний параметр
	{ 1473	,8	,1	, &internal1_m1618_tx},	//(internal1_m1618_tx) tx - время накопленное сек
	{ 1474	,18	,1	, &internal1_m1618_y0},	//(internal1_m1618_y0) y0
	{ 1475	,8	,1	, &internal1_m1622_tx},	//(internal1_m1622_tx) tx - время накопленное сек
	{ 1476	,18	,1	, &internal1_m1622_y0},	//(internal1_m1622_y0) y0
	{ 1477	,18	,1	, &internal1_m1608_DvUp0},	//(internal1_m1608_DvUp0) - есть команда на движение вперёд
	{ 1478	,18	,1	, &internal1_m1608_DvDw0},	//(internal1_m1608_DvDw0) - есть команда на движение назад
	{ 1479	,18	,1	, &internal1_m1608_FDvUp0},	//(internal1_m1608_FDvUp0) - есть команда на движение вперёд
	{ 1480	,18	,1	, &internal1_m1608_FDvDw0},	//(internal1_m1608_FDvDw0) - есть команда на движение назад
	{ 1481	,18	,1	, &internal1_m1608_BlDv0},	//(internal1_m1608_BlDv0) - была блокировка
	{ 1482	,18	,1	, &internal1_m1608_Pkv0},	//(internal1_m1608_Pkv0) Pkv - передний конечный выключатель
	{ 1483	,18	,1	, &internal1_m1608_Pkav0},	//(internal1_m1608_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1484	,18	,1	, &internal1_m1608_Zkv0},	//(internal1_m1608_Zkv0) Zkv - задний конечный выключатель
	{ 1485	,18	,1	, &internal1_m1608_Zkav0},	//(internal1_m1608_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1486	,8	,1	, &internal1_m1608_txNm},	//(internal1_m1608_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1487	,8	,1	, &internal1_m1608_txSm},	//(internal1_m1608_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1488	,8	,1	, &internal1_m1608_txHr},	//(internal1_m1608_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1489	,8	,1	, &internal1_m1608_txLd},	//(internal1_m1608_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1490	,18	,1	, &internal1_m1608_fef},	//(internal1_m1608_fef) fef
	{ 1491	,3	,1	, &internal1_m1625_xptr},	//(internal1_m1625_xptr) указатель текущей позиции в массиве координат
	{ 1492	,8	,20	, &internal1_m1625_x0},	//(internal1_m1625_x0) x0 - массив мгновенных значений координат
	{ 1493	,8	,20	, &internal1_m1625_tim0},	//(internal1_m1625_tim0) tim0 - массив значений времени цикла
	{ 1494	,8	,1	, &internal1_m1625_sumtim},	//(internal1_m1625_sumtim) sumtim - время в пути
	{ 1495	,8	,1	, &internal1_m1625_StSpeed},	//(internal1_m1625_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1496	,8	,1	, &internal1_m1625_Vz0},	//(internal1_m1625_Vz0) Vz0 - предыдущая заданная скорость
	{ 1497	,3	,1	, &internal1_m1625_flRazg},	//(internal1_m1625_flRazg) признак разгона/торможения
	{ 1498	,8	,1	, &internal1_m1625_DelSp},	//(internal1_m1625_DelSp) DelSp - время переключения скоростей
	{ 1499	,8	,1	, &internal1_m1625_z0},	//(internal1_m1625_z0) z0 - точка прекращения движения
	{ 1500	,8	,1	, &internal1_m1625_txZS},	//(internal1_m1625_txZS) txZS
	{ 1501	,8	,1	, &internal1_m1625_tx},	//(internal1_m1625_tx) tx
	{ 1502	,8	,1	, &internal1_m1625_txd},	//(internal1_m1625_txd) txd
	{ 1503	,8	,1	, &internal1_m1625_txMBl},	//(internal1_m1625_txMBl) tx
	{ 1504	,8	,1	, &internal1_m1625_txBl},	//(internal1_m1625_txBl) tx
	{ 1505	,8	,1	, &internal1_m1625_Speed0},	//(internal1_m1625_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1506	,8	,1	, &internal1_m1625_xz0},	//(internal1_m1625_xz0) xz0 - новое задание мм
	{ 1507	,8	,1	, &internal1_m1625_tz0},	//(internal1_m1625_tz0) tz0 - время защиты от нового задания сек
	{ 1508	,1	,1	, &internal1_m1625_Shift0},	//(internal1_m1625_Shift0) Shift0 - признак самохода
	{ 1509	,1	,1	, &internal1_m1625_ShCntlSp0},	//(internal1_m1625_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1510	,1	,1	, &internal1_m1625_ShiftControl},	//(internal1_m1625_ShiftControl) ShiftControl - признак самохода
	{ 1511	,8	,1	, &internal1_m1142_tx},	//(internal1_m1142_tx) tx - время накопленное сек
	{ 1512	,18	,1	, &internal1_m1142_y0},	//(internal1_m1142_y0) y0
	{ 1513	,8	,1	, &internal1_m1147_tx},	//(internal1_m1147_tx) tx - время накопленное сек
	{ 1514	,18	,1	, &internal1_m1147_y0},	//(internal1_m1147_y0) y0
	{ 1515	,1	,1	, &internal1_m642_q0},	//(internal1_m642_q0) q0 - внутренний параметр
	{ 1516	,1	,1	, &internal1_m607_q0},	//(internal1_m607_q0) q0 - внутренний параметр
	{ 1517	,18	,1	, &internal1_m1132_DvUp0},	//(internal1_m1132_DvUp0) - есть команда на движение вперёд
	{ 1518	,18	,1	, &internal1_m1132_DvDw0},	//(internal1_m1132_DvDw0) - есть команда на движение назад
	{ 1519	,18	,1	, &internal1_m1132_FDvUp0},	//(internal1_m1132_FDvUp0) - есть команда на движение вперёд
	{ 1520	,18	,1	, &internal1_m1132_FDvDw0},	//(internal1_m1132_FDvDw0) - есть команда на движение назад
	{ 1521	,18	,1	, &internal1_m1132_BlDv0},	//(internal1_m1132_BlDv0) - была блокировка
	{ 1522	,18	,1	, &internal1_m1132_Pkv0},	//(internal1_m1132_Pkv0) Pkv - передний конечный выключатель
	{ 1523	,18	,1	, &internal1_m1132_Pkav0},	//(internal1_m1132_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1524	,18	,1	, &internal1_m1132_Zkv0},	//(internal1_m1132_Zkv0) Zkv - задний конечный выключатель
	{ 1525	,18	,1	, &internal1_m1132_Zkav0},	//(internal1_m1132_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1526	,8	,1	, &internal1_m1132_txNm},	//(internal1_m1132_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1527	,8	,1	, &internal1_m1132_txSm},	//(internal1_m1132_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1528	,8	,1	, &internal1_m1132_txHr},	//(internal1_m1132_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1529	,8	,1	, &internal1_m1132_txLd},	//(internal1_m1132_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1530	,18	,1	, &internal1_m1132_fef},	//(internal1_m1132_fef) fef
	{ 1531	,3	,1	, &internal1_m1150_xptr},	//(internal1_m1150_xptr) указатель текущей позиции в массиве координат
	{ 1532	,8	,20	, &internal1_m1150_x0},	//(internal1_m1150_x0) x0 - массив мгновенных значений координат
	{ 1533	,8	,20	, &internal1_m1150_tim0},	//(internal1_m1150_tim0) tim0 - массив значений времени цикла
	{ 1534	,8	,1	, &internal1_m1150_sumtim},	//(internal1_m1150_sumtim) sumtim - время в пути
	{ 1535	,8	,1	, &internal1_m1150_StSpeed},	//(internal1_m1150_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1536	,8	,1	, &internal1_m1150_Vz0},	//(internal1_m1150_Vz0) Vz0 - предыдущая заданная скорость
	{ 1537	,3	,1	, &internal1_m1150_flRazg},	//(internal1_m1150_flRazg) признак разгона/торможения
	{ 1538	,8	,1	, &internal1_m1150_DelSp},	//(internal1_m1150_DelSp) DelSp - время переключения скоростей
	{ 1539	,8	,1	, &internal1_m1150_z0},	//(internal1_m1150_z0) z0 - точка прекращения движения
	{ 1540	,8	,1	, &internal1_m1150_txZS},	//(internal1_m1150_txZS) txZS
	{ 1541	,8	,1	, &internal1_m1150_tx},	//(internal1_m1150_tx) tx
	{ 1542	,8	,1	, &internal1_m1150_txd},	//(internal1_m1150_txd) txd
	{ 1543	,8	,1	, &internal1_m1150_txMBl},	//(internal1_m1150_txMBl) tx
	{ 1544	,8	,1	, &internal1_m1150_txBl},	//(internal1_m1150_txBl) tx
	{ 1545	,8	,1	, &internal1_m1150_Speed0},	//(internal1_m1150_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1546	,8	,1	, &internal1_m1150_xz0},	//(internal1_m1150_xz0) xz0 - новое задание мм
	{ 1547	,8	,1	, &internal1_m1150_tz0},	//(internal1_m1150_tz0) tz0 - время защиты от нового задания сек
	{ 1548	,1	,1	, &internal1_m1150_Shift0},	//(internal1_m1150_Shift0) Shift0 - признак самохода
	{ 1549	,1	,1	, &internal1_m1150_ShCntlSp0},	//(internal1_m1150_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1550	,1	,1	, &internal1_m1150_ShiftControl},	//(internal1_m1150_ShiftControl) ShiftControl - признак самохода
	{ 1551	,1	,1	, &internal1_m755_x0},	//(internal1_m755_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1552	,1	,1	, &internal1_m724_x0},	//(internal1_m724_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1553	,1	,1	, &internal1_m688_x0},	//(internal1_m688_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1554	,1	,1	, &internal1_m780_q0},	//(internal1_m780_q0) q0 - внутренний параметр
	{ 1555	,1	,1	, &internal1_m775_q0},	//(internal1_m775_q0) q0 - внутренний параметр
	{ 1556	,1	,1	, &internal1_m743_q0},	//(internal1_m743_q0) q0 - внутренний параметр
	{ 1557	,1	,1	, &internal1_m747_q0},	//(internal1_m747_q0) q0 - внутренний параметр
	{ 1558	,1	,1	, &internal1_m756_q0},	//(internal1_m756_q0) q0 - внутренний параметр
	{ 1559	,1	,1	, &internal1_m768_q0},	//(internal1_m768_q0) q0 - внутренний параметр
	{ 1560	,1	,1	, &internal1_m745_q0},	//(internal1_m745_q0) q0 - внутренний параметр
	{ 1561	,18	,1	, &internal1_m1202_DvUp0},	//(internal1_m1202_DvUp0) - есть команда на движение вперёд
	{ 1562	,18	,1	, &internal1_m1202_DvDw0},	//(internal1_m1202_DvDw0) - есть команда на движение назад
	{ 1563	,18	,1	, &internal1_m1202_FDvUp0},	//(internal1_m1202_FDvUp0) - есть команда на движение вперёд
	{ 1564	,18	,1	, &internal1_m1202_FDvDw0},	//(internal1_m1202_FDvDw0) - есть команда на движение назад
	{ 1565	,18	,1	, &internal1_m1202_BlDv0},	//(internal1_m1202_BlDv0) - была блокировка
	{ 1566	,18	,1	, &internal1_m1202_Pkv0},	//(internal1_m1202_Pkv0) Pkv - передний конечный выключатель
	{ 1567	,18	,1	, &internal1_m1202_Pkav0},	//(internal1_m1202_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1568	,18	,1	, &internal1_m1202_Zkv0},	//(internal1_m1202_Zkv0) Zkv - задний конечный выключатель
	{ 1569	,18	,1	, &internal1_m1202_Zkav0},	//(internal1_m1202_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1570	,8	,1	, &internal1_m1202_txNm},	//(internal1_m1202_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1571	,8	,1	, &internal1_m1202_txSm},	//(internal1_m1202_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1572	,8	,1	, &internal1_m1202_txHr},	//(internal1_m1202_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1573	,8	,1	, &internal1_m1202_txLd},	//(internal1_m1202_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1574	,18	,1	, &internal1_m1202_fef},	//(internal1_m1202_fef) fef
	{ 1575	,18	,1	, &internal1_m1192_DvUp0},	//(internal1_m1192_DvUp0) - есть команда на движение вперёд
	{ 1576	,18	,1	, &internal1_m1192_DvDw0},	//(internal1_m1192_DvDw0) - есть команда на движение назад
	{ 1577	,18	,1	, &internal1_m1192_FDvUp0},	//(internal1_m1192_FDvUp0) - есть команда на движение вперёд
	{ 1578	,18	,1	, &internal1_m1192_FDvDw0},	//(internal1_m1192_FDvDw0) - есть команда на движение назад
	{ 1579	,18	,1	, &internal1_m1192_BlDv0},	//(internal1_m1192_BlDv0) - была блокировка
	{ 1580	,18	,1	, &internal1_m1192_Pkv0},	//(internal1_m1192_Pkv0) Pkv - передний конечный выключатель
	{ 1581	,18	,1	, &internal1_m1192_Pkav0},	//(internal1_m1192_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1582	,18	,1	, &internal1_m1192_Zkv0},	//(internal1_m1192_Zkv0) Zkv - задний конечный выключатель
	{ 1583	,18	,1	, &internal1_m1192_Zkav0},	//(internal1_m1192_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1584	,8	,1	, &internal1_m1192_txNm},	//(internal1_m1192_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1585	,8	,1	, &internal1_m1192_txSm},	//(internal1_m1192_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1586	,8	,1	, &internal1_m1192_txHr},	//(internal1_m1192_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1587	,8	,1	, &internal1_m1192_txLd},	//(internal1_m1192_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1588	,18	,1	, &internal1_m1192_fef},	//(internal1_m1192_fef) fef
	{ 1589	,18	,1	, &internal1_m800_DvUp0},	//(internal1_m800_DvUp0) - есть команда на движение вперёд
	{ 1590	,18	,1	, &internal1_m800_DvDw0},	//(internal1_m800_DvDw0) - есть команда на движение назад
	{ 1591	,18	,1	, &internal1_m800_FDvUp0},	//(internal1_m800_FDvUp0) - есть команда на движение вперёд
	{ 1592	,18	,1	, &internal1_m800_FDvDw0},	//(internal1_m800_FDvDw0) - есть команда на движение назад
	{ 1593	,18	,1	, &internal1_m800_BlDv0},	//(internal1_m800_BlDv0) - была блокировка
	{ 1594	,18	,1	, &internal1_m800_Pkv0},	//(internal1_m800_Pkv0) Pkv - передний конечный выключатель
	{ 1595	,18	,1	, &internal1_m800_Pkav0},	//(internal1_m800_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1596	,18	,1	, &internal1_m800_Zkv0},	//(internal1_m800_Zkv0) Zkv - задний конечный выключатель
	{ 1597	,18	,1	, &internal1_m800_Zkav0},	//(internal1_m800_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1598	,8	,1	, &internal1_m800_txNm},	//(internal1_m800_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1599	,8	,1	, &internal1_m800_txSm},	//(internal1_m800_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1600	,8	,1	, &internal1_m800_txHr},	//(internal1_m800_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1601	,8	,1	, &internal1_m800_txLd},	//(internal1_m800_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1602	,18	,1	, &internal1_m800_fef},	//(internal1_m800_fef) fef
	{ 1603	,18	,1	, &internal1_m796_DvUp0},	//(internal1_m796_DvUp0) - есть команда на движение вперёд
	{ 1604	,18	,1	, &internal1_m796_DvDw0},	//(internal1_m796_DvDw0) - есть команда на движение назад
	{ 1605	,18	,1	, &internal1_m796_FDvUp0},	//(internal1_m796_FDvUp0) - есть команда на движение вперёд
	{ 1606	,18	,1	, &internal1_m796_FDvDw0},	//(internal1_m796_FDvDw0) - есть команда на движение назад
	{ 1607	,18	,1	, &internal1_m796_BlDv0},	//(internal1_m796_BlDv0) - была блокировка
	{ 1608	,18	,1	, &internal1_m796_Pkv0},	//(internal1_m796_Pkv0) Pkv - передний конечный выключатель
	{ 1609	,18	,1	, &internal1_m796_Pkav0},	//(internal1_m796_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1610	,18	,1	, &internal1_m796_Zkv0},	//(internal1_m796_Zkv0) Zkv - задний конечный выключатель
	{ 1611	,18	,1	, &internal1_m796_Zkav0},	//(internal1_m796_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1612	,8	,1	, &internal1_m796_txNm},	//(internal1_m796_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1613	,8	,1	, &internal1_m796_txSm},	//(internal1_m796_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1614	,8	,1	, &internal1_m796_txHr},	//(internal1_m796_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1615	,8	,1	, &internal1_m796_txLd},	//(internal1_m796_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1616	,18	,1	, &internal1_m796_fef},	//(internal1_m796_fef) fef
	{ 1617	,18	,1	, &internal1_m378_DvUp0},	//(internal1_m378_DvUp0) - есть команда на движение вперёд
	{ 1618	,18	,1	, &internal1_m378_DvDw0},	//(internal1_m378_DvDw0) - есть команда на движение назад
	{ 1619	,18	,1	, &internal1_m378_FDvUp0},	//(internal1_m378_FDvUp0) - есть команда на движение вперёд
	{ 1620	,18	,1	, &internal1_m378_FDvDw0},	//(internal1_m378_FDvDw0) - есть команда на движение назад
	{ 1621	,18	,1	, &internal1_m378_BlDv0},	//(internal1_m378_BlDv0) - была блокировка
	{ 1622	,18	,1	, &internal1_m378_Pkv0},	//(internal1_m378_Pkv0) Pkv - передний конечный выключатель
	{ 1623	,18	,1	, &internal1_m378_Pkav0},	//(internal1_m378_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1624	,18	,1	, &internal1_m378_Zkv0},	//(internal1_m378_Zkv0) Zkv - задний конечный выключатель
	{ 1625	,18	,1	, &internal1_m378_Zkav0},	//(internal1_m378_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1626	,8	,1	, &internal1_m378_txNm},	//(internal1_m378_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1627	,8	,1	, &internal1_m378_txSm},	//(internal1_m378_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1628	,8	,1	, &internal1_m378_txHr},	//(internal1_m378_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1629	,8	,1	, &internal1_m378_txLd},	//(internal1_m378_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1630	,18	,1	, &internal1_m378_fef},	//(internal1_m378_fef) fef
	{ 1631	,18	,1	, &internal1_m407_DvUp0},	//(internal1_m407_DvUp0) - есть команда на движение вперёд
	{ 1632	,18	,1	, &internal1_m407_DvDw0},	//(internal1_m407_DvDw0) - есть команда на движение назад
	{ 1633	,18	,1	, &internal1_m407_FDvUp0},	//(internal1_m407_FDvUp0) - есть команда на движение вперёд
	{ 1634	,18	,1	, &internal1_m407_FDvDw0},	//(internal1_m407_FDvDw0) - есть команда на движение назад
	{ 1635	,18	,1	, &internal1_m407_BlDv0},	//(internal1_m407_BlDv0) - была блокировка
	{ 1636	,18	,1	, &internal1_m407_Pkv0},	//(internal1_m407_Pkv0) Pkv - передний конечный выключатель
	{ 1637	,18	,1	, &internal1_m407_Pkav0},	//(internal1_m407_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1638	,18	,1	, &internal1_m407_Zkv0},	//(internal1_m407_Zkv0) Zkv - задний конечный выключатель
	{ 1639	,18	,1	, &internal1_m407_Zkav0},	//(internal1_m407_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1640	,8	,1	, &internal1_m407_txNm},	//(internal1_m407_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1641	,8	,1	, &internal1_m407_txSm},	//(internal1_m407_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1642	,8	,1	, &internal1_m407_txHr},	//(internal1_m407_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1643	,8	,1	, &internal1_m407_txLd},	//(internal1_m407_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1644	,18	,1	, &internal1_m407_fef},	//(internal1_m407_fef) fef
	{ 1645	,18	,1	, &internal1_m401_DvUp0},	//(internal1_m401_DvUp0) - есть команда на движение вперёд
	{ 1646	,18	,1	, &internal1_m401_DvDw0},	//(internal1_m401_DvDw0) - есть команда на движение назад
	{ 1647	,18	,1	, &internal1_m401_FDvUp0},	//(internal1_m401_FDvUp0) - есть команда на движение вперёд
	{ 1648	,18	,1	, &internal1_m401_FDvDw0},	//(internal1_m401_FDvDw0) - есть команда на движение назад
	{ 1649	,18	,1	, &internal1_m401_BlDv0},	//(internal1_m401_BlDv0) - была блокировка
	{ 1650	,18	,1	, &internal1_m401_Pkv0},	//(internal1_m401_Pkv0) Pkv - передний конечный выключатель
	{ 1651	,18	,1	, &internal1_m401_Pkav0},	//(internal1_m401_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1652	,18	,1	, &internal1_m401_Zkv0},	//(internal1_m401_Zkv0) Zkv - задний конечный выключатель
	{ 1653	,18	,1	, &internal1_m401_Zkav0},	//(internal1_m401_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1654	,8	,1	, &internal1_m401_txNm},	//(internal1_m401_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1655	,8	,1	, &internal1_m401_txSm},	//(internal1_m401_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1656	,8	,1	, &internal1_m401_txHr},	//(internal1_m401_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1657	,8	,1	, &internal1_m401_txLd},	//(internal1_m401_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1658	,18	,1	, &internal1_m401_fef},	//(internal1_m401_fef) fef
	{ 1659	,1	,1	, &internal1_m752_q0},	//(internal1_m752_q0) q0 - внутренний параметр
	{ 1660	,1	,1	, &internal1_m749_q0},	//(internal1_m749_q0) q0 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="du.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{766,"fEM_A1UC03RDU\0"}, 
{767,"dEM_A1UC05UDU\0"}, 
{768,"dEM_A1UC06UDU\0"}, 
{769,"dEM_A2UC06UDU\0"}, 
{770,"dEM_A2UC05UDU\0"}, 
{771,"fEM_A2UC03RDU\0"}, 
{772,"dEM_A3UC06UDU\0"}, 
{773,"dEM_A3UC05UDU\0"}, 
{774,"fEM_A3UC03RDU\0"}, 
{775,"dEM_A8UC06UDU\0"}, 
{776,"fEM_A8UC03RDU\0"}, 
{777,"dEM_A8UC05UDU\0"}, 
{778,"fEM_R0UV81RDU\0"}, 
{779,"fEM_R0UV82RDU\0"}, 
{780,"fEM_R0UV83RDU\0"}, 
{781,"fEM_R0UV84RDU\0"}, 
{782,"fEM_R0UV86RDU\0"}, 
{783,"fEM_R0UV85RDU\0"}, 
{784,"fEM_R0UV87RDU\0"}, 
{785,"fEM_A3UP03RDU\0"}, 
{786,"fEM_A3UP04RDU\0"}, 
{787,"fEM_A3UP43RDU\0"}, 
{788,"fEM_A3UP44RDU\0"}, 
{789,"fEM_A3UP53RDU\0"}, 
{790,"fEM_A3UP85RDU\0"}, 
{791,"fEM_A3UP88RDU\0"}, 
{792,"fEM_A3UP86RDU\0"}, 
{793,"fEM_B8UV01RDU\0"}, 
{794,"fEM_B8UV02RDU\0"}, 
{795,"fEM_B8UV03RDU\0"}, 
{796,"fEM_B8UL04RDU\0"}, 
{797,"iEM_A2UV03CDU\0"}, 
{798,"fEM_A2UV01RDU\0"}, 
{799,"fEM_A2UV02RDU\0"}, 
{800,"fEM_A1UV01RDU\0"}, 
{801,"fEM_A1UV02RDU\0"}, 
{802,"fEM_A1UC06RDU\0"}, 
{803,"fEM_A1UC05RDU\0"}, 
{804,"fEM_A1UL04RDU\0"}, 
{805,"fEM_A3UV01RDU\0"}, 
{806,"fEM_A3UV02RDU\0"}, 
{807,"fEM_A3UC06RDU\0"}, 
{808,"fEM_A3UC05RDU\0"}, 
{809,"fEM_A3UL04RDU\0"}, 
{810,"fEM_A3UP54RDU\0"}, 
{811,"fEM_A3UP87RDU\0"}, 
{812,"fEM_R0UL05RDU\0"}, 
{813,"fEM_R0UL20RDU\0"}, 
{814,"fEM_B8UV04RDU\0"}, 
{815,"fEM_B8UC06RDU\0"}, 
{816,"fEM_B8UC05RDU\0"}, 
{817,"fEM_A2UL05RDU\0"}, 
{818,"fEM_A2UL03RDU\0"}, 
{819,"fEM_A2UC06RDU\0"}, 
{820,"fEM_A2UC05RDU\0"}, 
{821,"fEM_A2UL04RDU\0"}, 
{822,"fEM_A1UL03RDU\0"}, 
{823,"fEM_A1UL05RDU\0"}, 
{824,"fEM_A3UL03RDU\0"}, 
{825,"fEM_A3UL05RDU\0"}, 
{826,"fEM_A1UC08RDU\0"}, 
{827,"fEM_A3UC08RDU\0"}, 
{828,"fEM_A1UC07RDU\0"}, 
{829,"fEM_A1UL01RDU\0"}, 
{830,"fEM_A3UC07RDU\0"}, 
{831,"fEM_A3UL01RDU\0"}, 
{832,"fEM_A2UC08RDU\0"}, 
{833,"fEM_A2UC07RDU\0"}, 
{834,"fEM_A2UL01RDU\0"}, 
{835,"fEM_B8UC01RDU\0"}, 
{836,"fEM_B8UL07RDU\0"}, 
{837,"fEM_B8UC02RDU\0"}, 
{838,"fEM_B8UL01RDU\0"}, 
{839,"fEM_B8UL05RDU\0"}, 
{840,"fEM_B8UL03RDU\0"}, 
{841,"fEM_B8UL06RDU\0"}, 
{842,"fEM_A9UZ03RDU\0"}, 
{843,"fEM_A9UZ04RDU\0"}, 
{844,"fEM_A9UZ05RDU\0"}, 
{845,"fEM_R4UZ04RDU\0"}, 
{846,"fEM_R4UZ03RDU\0"}, 
{847,"fEM_R4UZ05RDU\0"}, 
{848,"fEM_A5UZ03RDU\0"}, 
{849,"fEM_A5UZ04RDU\0"}, 
{850,"fEM_A5UZ05RDU\0"}, 
{851,"fEM_A4UZ03RDU\0"}, 
{852,"fEM_A4UZ04RDU\0"}, 
{853,"fEM_A4UZ05RDU\0"}, 
{854,"fEM_A6UZ03RDU\0"}, 
{855,"fEM_A6UZ04RDU\0"}, 
{856,"fEM_A6UZ05RDU\0"}, 
{857,"fEM_R1UZ03RDU\0"}, 
{858,"fEM_R1UZ04RDU\0"}, 
{859,"fEM_R1UZ05RDU\0"}, 
{860,"fEM_R0UL04RDU\0"}, 
{861,"fEM_R0UL06RDU\0"}, 
{862,"fEM_R0UL03RDU\0"}, 
{863,"fEM_R0UL17RDU\0"}, 
{864,"fEM_R0UL19RDU\0"}, 
{865,"fEM_R0UL07RDU\0"}, 
{866,"fEM_R0UL18RDU\0"}, 
{867,"fEM_R0UL16RDU\0"}, 
{868,"fEM_R0UL02RDU\0"}, 
{869,"fEM_R0UN08RDU\0"}, 
{870,"fEM_R0UN07RDU\0"}, 
{871,"fEM_R0UN06RDU\0"}, 
{872,"fEM_R0UN05RDU\0"}, 
{873,"fEM_R0UN04RDU\0"}, 
{874,"fEM_R0UN03RDU\0"}, 
{875,"fEM_R0UN02RDU\0"}, 
{876,"fEM_R0UN01RDU\0"}, 
{877,"fEM_A2UC82RDU\0"}, 
{878,"fEM_A2UC83RDU\0"}, 
{879,"fEM_A1UC83RDU\0"}, 
{880,"fEM_A2UC81RDU\0"}, 
{881,"fEM_A1UC81RDU\0"}, 
{882,"fEM_A1UC82RDU\0"}, 
{883,"fEM_A2UL83RDU\0"}, 
{884,"fEM_A3UC81RDU\0"}, 
{885,"fEM_A3UC82RDU\0"}, 
{886,"fEM_R0UN80RDU\0"}, 
{887,"iEM_A2UV01IDU\0"}, 
{888,"iEM_A2UV02IDU\0"}, 
{889,"iEM_A1UV01IDU\0"}, 
{890,"iEM_A1UV02IDU\0"}, 
{891,"iEM_A1UV03IDU\0"}, 
{892,"iEM_A3UV01IDU\0"}, 
{893,"iEM_A3UV02IDU\0"}, 
{894,"lEM_R0MD01LC1\0"}, 
{895,"fEM_A3UC09RDU\0"}, 
{896,"fEM_A2UC02RDU\0"}, 
{897,"fEM_A1UC02RDU\0"}, 
{898,"fEM_A3UC02RDU\0"}, 
{899,"fEM_R0UL21RDU\0"}, 
{900,"fEM_R0UN09RDU\0"}, 
{901,"fEM_R0UN11RDU\0"}, 
{902,"fEM_R0UN12RDU\0"}, 
{903,"fEM_R0UN13RDU\0"}, 
{904,"fEM_R0UN14RDU\0"}, 
{905,"fEM_R0UN16RDU\0"}, 
{906,"fEM_R0UN17RDU\0"}, 
{907,"fEM_R0UN18RDU\0"}, 
{908,"fEM_R0UN19RDU\0"}, 
{909,"fEM_R0UN70LDU\0"}, 
{910,"fEM_R0UN71LDU\0"}, 
{911,"fEM_R0UN72LDU\0"}, 
{912,"fEM_R0UN73LDU\0"}, 
{913,"fEM_R0UN74LDU\0"}, 
{914,"fEM_R0UN75LDU\0"}, 
{915,"fEM_R0UN80LDU\0"}, 
{916,"fEM_R0UN81LDU\0"}, 
{917,"fEM_R0UN82LDU\0"}, 
{918,"fEM_R0UN83LDU\0"}, 
{919,"fEM_R0UN84LDU\0"}, 
{920,"fEM_R0UN85LDU\0"}, 
{921,"fEM_R0UT20RDU\0"}, 
{922,"fEM_R0UN25RDU\0"}, 
{923,"fEM_R0UN15RDU\0"}, 
{924,"fEM_R0UN26RDU\0"}, 
{925,"fEM_R0UN27RDU\0"}, 
{926,"fEM_R0UN24RDU\0"}, 
{927,"fEM_R0UL25RDU\0"}, 
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
	{&R8IS11LDU,1,26},
	{&B1IS21LDU,1,16},
	{&B1IS11LDU,1,14},
	{&B9IS21LDU,1,50},
	{&B9IS11LDU,1,48},
	{&A9IS21LDU,1,46},
	{&A9IS11LDU,1,44},
	{&B1IS12LDU,1,12},
	{&B2IS12LDU,1,18},
	{&R2IS21LDU,1,58},
	{&R1IS21LDU,1,54},
	{&B3IS35LDU,1,0},
	{&B3IS33LDU,1,2},
	{&R0VZ71LZ1,1,42},
	{&B3IS31LDU,1,8},
	{&B2IS33LDU,1,4},
	{&B2IS11LDU,1,20},
	{&A3VZ15LZ1,1,36},
	{&B4IS21LDU,1,62},
	{&B4IS10LDU,1,6},
	{&A1VN71LZ1,1,40},
	{&B7AS31LDU,1,10},
	{&A3VZ13LZ1,1,34},
	{&B4IS11LDU,1,60},
	{&R0AD14LZ1,1,38},
	{&R2IS11LDU,1,56},
	{&R1IS11LDU,1,52},
	{&B3IS21LDU,1,24},
	{&B2IS21LDU,1,22},
	{&R0DE02LDU,3,64},
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
	{&A1IS12LDU,1,12},
	{&A1IS11LDU,1,14},
	{&A3VZ15LZ2,1,36},
	{&A2IS12LDU,1,18},
	{&R0DE03LDU,3,64},
	{&R0IS02LDU,1,58},
	{&A4IS11LDU,1,26},
	{&R0IS01LDU,1,56},
	{&A3VZ13LZ2,1,34},
	{&A7AS31LDU,1,10},
	{&A2IS11LDU,1,20},
	{&A4IS21LDU,1,28},
	{&R0VZ71LZ2,1,42},
	{&A1IS21LDU,1,16},
	{&A2IS33LDU,1,4},
	{&A3IS31LDU,1,8},
	{&A3IS33LDU,1,2},
	{&A3IS35LDU,1,0},
	{&A3IS21LDU,1,24},
	{&R0AD14LZ2,1,38},
	{&A2IS21LDU,1,22},
	{&A1VN71LZ2,1,40},
	{&A4IS10LDU,1,6},
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
	{&B8IS11LDU,1,36},
	{&A3IS22LDU,1,2},
	{&R4IS11LDU,1,8},
	{&A6IS11LDU,1,16},
	{&R6IS21LDU,1,56},
	{&A6IS21LDU,1,18},
	{&B8IS21LDU,1,38},
	{&R3IS21LDU,1,34},
	{&R3IS11LDU,1,32},
	{&B6IS11LDU,1,24},
	{&R4IS12LDU,1,10},
	{&R4IS22LDU,1,14},
	{&R4IS21LDU,1,12},
	{&B6IS21LDU,1,26},
	{&R5IS11LDU,1,48},
	{&B5IS21LDU,1,30},
	{&B5IS11LDU,1,28},
	{&A5IS21LDU,1,22},
	{&A5IS11LDU,1,20},
	{&B8IS12LDU,1,40},
	{&A3IS11LDU,1,0},
	{&R0DE04LDU,3,64},
	{&A8IS22LDU,1,60},
	{&A8IS12LDU,1,58},
	{&B8IS22LDU,1,42},
	{&R5IS21LDU,1,50},
	{&B3IS11LDU,1,4},
	{&B3IS22LDU,1,6},
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
	{&A1IE02LDU,1,0},
	{&A3IE02LDU,1,16},
	{&A2IE02LDU,1,8},
	{&B1IE01LDU,1,26},
	{&B2IE01LDU,1,34},
	{&A3IE04LDU,1,22},
	{&B2IE02LDU,1,32},
	{&B3IE04LDU,1,46},
	{&B3IE03LDU,1,44},
	{&B2IE04LDU,1,38},
	{&B2IE03LDU,1,36},
	{&B1IE04LDU,1,30},
	{&B1IE03LDU,1,28},
	{&B3IE02LDU,1,40},
	{&B3IE01LDU,1,42},
	{&B1IE02LDU,1,24},
	{&A1IE01LDU,1,2},
	{&R0DE05LDU,3,64},
	{&R6IS51LDU,1,56},
	{&R6IS52LDU,1,58},
	{&R6IS41LDU,1,52},
	{&R6IS42LDU,1,54},
	{&R6IS32LDU,1,50},
	{&R6IS31LDU,1,48},
	{&A1IE03LDU,1,4},
	{&A1IE04LDU,1,6},
	{&A2IE03LDU,1,12},
	{&A2IE04LDU,1,14},
	{&A3IE03LDU,1,20},
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
	{&A2AD01LDU,1,4},
	{&R0DE07LDU,3,38},
	{&A2AD04LDU,1,10},
	{&B2AD01LDU,1,18},
	{&B2AD05LDU,1,26},
	{&B2AD04LDU,1,24},
	{&B2AD03LDU,1,22},
	{&A2AD03LDU,1,8},
	{&A2AD02LDU,1,6},
	{&A2AD21LDU,1,2},
	{&A2AD11LDU,1,0},
	{&B2AD02LDU,1,20},
	{&B2AD21LDU,1,16},
	{&B2AD11LDU,1,14},
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
	{&B1AD11LDU,1,14},
	{&B1AD21LDU,1,16},
	{&B1AD02LDU,1,20},
	{&B1AD03LDU,1,22},
	{&B1AD04LDU,1,24},
	{&B1AD05LDU,1,26},
	{&B1AD01LDU,1,18},
	{&A1AD03LDU,1,8},
	{&R0DE08LDU,3,38},
	{&A1AD04LDU,1,10},
	{&A1AD05LDU,1,12},
	{&A1AD01LDU,1,4},
	{&A1AD11LDU,1,0},
	{&A1AD21LDU,1,2},
	{&A1AD02LDU,1,6},
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
	{&A6AD10LDU,1,16},
	{&B4AD10LDU,1,6},
	{&B7AP31LDU,1,10},
	{&B2AD33LDU,1,4},
	{&R4AD10LDU,1,24},
	{&R4AD20LDU,1,26},
	{&B3AD34LDU,1,0},
	{&B3AD31LDU,1,8},
	{&B3AD33LDU,1,2},
	{&A8AD20LDU,1,14},
	{&A8AD10LDU,1,12},
	{&B8AD20LDU,1,30},
	{&R0DE09LDU,3,38},
	{&B8AD10LDU,1,28},
	{&B6AD20LDU,1,22},
	{&B6AD10LDU,1,20},
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
	{&A3AD34LDU,1,0},
	{&A3AD33LDU,1,2},
	{&A2AD33LDU,1,4},
	{&R1AD20LDU,1,14},
	{&R1AD10LDU,1,12},
	{&A3AD31LDU,1,8},
	{&A7AP31LDU,1,10},
	{&B5AD20LDU,1,26},
	{&A5AD10LDU,1,20},
	{&A4AD10LDU,1,6},
	{&A5AD20LDU,1,22},
	{&R0DE0ALDU,3,38},
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
	{&B3AD03LDU,1,22},
	{&B3AD04LDU,1,24},
	{&B3AD05LDU,1,26},
	{&A3AD01LDU,1,4},
	{&B3AD01LDU,1,18},
	{&R0DE0BLDU,3,38},
	{&A3AD05LDU,1,12},
	{&A3AD04LDU,1,10},
	{&A3AD03LDU,1,8},
	{&A3AD02LDU,1,6},
	{&A3AD21LDU,1,2},
	{&A3AD11LDU,1,0},
	{&A9AD10LDU,1,28},
	{&B9AD10LDU,1,30},
	{&B3AD11LDU,1,14},
	{&B3AD21LDU,1,16},
	{&B3AD02LDU,1,20},
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
	{&A3IP02IDU,3,0},
	{&R0DE0CLDU,3,26},
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
	{&R1IE01LDU,1,12},
	{&R0IE02LDU,1,44},
	{&A5IE02LDU,1,24},
	{&B5IE01LDU,1,30},
	{&R0IE01LDU,1,46},
	{&A6IE01LDU,1,36},
	{&B6IE01LDU,1,42},
	{&A8IE01LDU,1,6},
	{&A6VS12LDU,1,32},
	{&A6VS22LDU,1,34},
	{&B6VS22LDU,1,40},
	{&B6VS12LDU,1,38},
	{&R0DE0DLDU,3,64},
	{&R6IS61LDU,1,0},
	{&R1VS12LDU,1,8},
	{&R4VS12LDU,1,2},
	{&R4VS22LDU,1,4},
	{&R2VS12LDU,1,14},
	{&R2VS22LDU,1,16},
	{&R1VS22LDU,1,10},
	{&R2IE01LDU,1,18},
	{&B5VS12LDU,1,26},
	{&B5VS22LDU,1,28},
	{&A5VS12LDU,1,20},
	{&A5VS22LDU,1,22},
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
	{&R0AD05LZ2,1,30},
	{&R0AD05LZ1,1,20},
	{&R0AD04LZ2,1,28},
	{&R0AD04LZ1,1,18},
	{&R0AD03LZ2,1,26},
	{&R8AD21LDU,1,22},
	{&R0AD03LZ1,1,16},
	{&R0AD16LDU,1,24},
	{&B1AD32LDU,1,8},
	{&A1AD32LDU,1,0},
	{&B2AD32LDU,1,12},
	{&A2AD32LDU,1,4},
	{&A2AD31LDU,1,6},
	{&B2AD31LDU,1,14},
	{&A1AD31LDU,1,2},
	{&B1AD31LDU,1,10},
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
	{&R0DEB4LDU,1,24},
	{&R0DEB1LDU,1,18},
	{&R0DEB2LDU,1,20},
	{&R0DEB3LDU,1,22},
	{&R0DE39LDU,1,16},
	{&R0DE38LDU,1,14},
	{&R0DE37LDU,1,12},
	{&R0DE32LDU,1,2},
	{&R0DE33LDU,1,4},
	{&R0DE36LDU,1,10},
	{&R0DE35LDU,1,8},
	{&R0DE34LDU,1,6},
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
	setAsFloat(766,0.0000976563);
	setAsInt(767,1024200);
	setAsInt(768,-200);
	setAsInt(769,-200);
	setAsInt(770,1024200);
	setAsFloat(771,0.0000976563);
	setAsInt(772,-200);
	setAsInt(773,1689599);
	setAsFloat(774,0.00009765625);
	setAsInt(775,-200);
	setAsFloat(776,0.0009765625);
	setAsInt(777,1536200);
	setAsFloat(778,100);
	setAsFloat(779,200);
	setAsFloat(780,300);
	setAsFloat(781,400);
	setAsFloat(782,600);
	setAsFloat(783,500);
	setAsFloat(784,750);
	setAsFloat(785,2.5);
	setAsFloat(786,0);
	setAsFloat(787,0.46);
	setAsFloat(788,0.49);
	setAsFloat(789,0.52);
	setAsFloat(790,0.53);
	setAsFloat(791,0.67);
	setAsFloat(792,0.56);
	setAsFloat(793,4);
	setAsFloat(794,4);
	setAsFloat(795,10.91);
	setAsFloat(796,3);
	setAsShort(797,4);
	setAsFloat(798,0.15);
	setAsFloat(799,0.15);
	setAsFloat(800,0.4);
	setAsFloat(801,0.4);
	setAsFloat(802,0.03);
	setAsFloat(803,0.04);
	setAsFloat(804,3);
	setAsFloat(805,0.3);
	setAsFloat(806,0.3);
	setAsFloat(807,0.07);
	setAsFloat(808,0.04);
	setAsFloat(809,3);
	setAsFloat(810,0.55);
	setAsFloat(811,0.64);
	setAsFloat(812,0.180);
	setAsFloat(813,0.025);
	setAsFloat(814,0.1);
	setAsFloat(815,2);
	setAsFloat(816,0.3);
	setAsFloat(817,3);
	setAsFloat(818,1.50);
	setAsFloat(819,0.04);
	setAsFloat(820,0.05);
	setAsFloat(821,3);
	setAsFloat(822,1.50);
	setAsFloat(823,3);
	setAsFloat(824,1.50);
	setAsFloat(825,2);
	setAsFloat(826,0.004);
	setAsFloat(827,0.006);
	setAsFloat(828,0.006);
	setAsFloat(829,1.0);
	setAsFloat(830,0.01);
	setAsFloat(831,1);
	setAsFloat(832,0.008);
	setAsFloat(833,0.01);
	setAsFloat(834,1);
	setAsFloat(835,0.4);
	setAsFloat(836,120);
	setAsFloat(837,0.6);
	setAsFloat(838,1);
	setAsFloat(839,2);
	setAsFloat(840,1.50);
	setAsFloat(841,2.0);
	setAsFloat(842,1);
	setAsFloat(843,15);
	setAsFloat(844,0.50);
	setAsFloat(845,360);
	setAsFloat(846,1);
	setAsFloat(847,2);
	setAsFloat(848,1.0);
	setAsFloat(849,6.0);
	setAsFloat(850,0.50);
	setAsFloat(851,1.0);
	setAsFloat(852,16.0);
	setAsFloat(853,3.0);
	setAsFloat(854,1.0);
	setAsFloat(855,60.0);
	setAsFloat(856,0.50);
	setAsFloat(857,1.0);
	setAsFloat(858,20.0);
	setAsFloat(859,0.50);
	setAsFloat(860,2.0);
	setAsFloat(861,2.0);
	setAsFloat(862,1.5);
	setAsFloat(863,0.06);
	setAsFloat(864,0.01);
	setAsFloat(865,0.045);
	setAsFloat(866,0.040);
	setAsFloat(867,0.007);
	setAsFloat(868,0.014);
	setAsFloat(869,2000.0);
	setAsFloat(870,1500.0);
	setAsFloat(871,1000.0);
	setAsFloat(872,800.0);
	setAsFloat(873,500.0);
	setAsFloat(874,200.0);
	setAsFloat(875,100.0);
	setAsFloat(876,0.001);
	setAsFloat(877,100);
	setAsFloat(878,100);
	setAsFloat(879,110.0);
	setAsFloat(880,20);
	setAsFloat(881,30.0);
	setAsFloat(882,100.0);
	setAsFloat(883,1.50);
	setAsFloat(884,170);
	setAsFloat(885,170);
	setAsFloat(886,10);
	setAsShort(887,1);
	setAsShort(888,4);
	setAsShort(889,1);
	setAsShort(890,4);
	setAsShort(891,4);
	setAsShort(892,4);
	setAsShort(893,4);
	setAsBool(894,0);
	setAsFloat(895,159.99);
	setAsFloat(896,0.002375);
	setAsFloat(897,0.000877);
	setAsFloat(898,0.001675);
	setAsFloat(899,2.5);
	setAsFloat(900,30);
	setAsFloat(901,30);
	setAsFloat(902,0.05);
	setAsFloat(903,0.05);
	setAsFloat(904,160.0);
	setAsFloat(905,-170.11);
	setAsFloat(906,76.25088);
	setAsFloat(907,0.271145);
	setAsFloat(908,24.93556615);
	setAsFloat(909,0.1268);
	setAsFloat(910,0.1567);
	setAsFloat(911,0.1858);
	setAsFloat(912,0.2066);
	setAsFloat(913,0.2646);
	setAsFloat(914,0.2995);
	setAsFloat(915,0.721275);
	setAsFloat(916,0.700575);
	setAsFloat(917,0.6681);
	setAsFloat(918,0.61515);
	setAsFloat(919,0.3885);
	setAsFloat(920,0.23325);
	setAsFloat(921,3600.0);
	setAsFloat(922,0.935);
	setAsFloat(923,0.1);
	setAsFloat(924,0.006792308);
	setAsFloat(925,0.000418877);
	setAsFloat(926,0.0015);
	setAsFloat(927,0.30);
}
uspaint8 InternalBuf[8521];

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
ssbool var7;
ssbool var8;
ssbool var9;
ssbool var10;
ssbool var11;
ssbool var12;
ssbool var13;
ssint var14;
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
ssint var142;
ssbool var143;
ssbool var144;
ssint var145;
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
ssfloat var190;
ssbool var191;
ssbool var192;
ssbool var193;
ssbool var194;
ssbool var195;
ssbool var196;
ssbool var197;
ssbool var198;
ssbool var199;
ssfloat var200;
ssfloat var201;
ssbool var202;
ssbool var203;
ssbool var204;
ssfloat var205;
ssfloat var206;
ssbool var207;
ssbool var208;
ssfloat var209;
ssbool var210;
ssbool var211;
ssbool var212;
ssbool var213;
ssbool var214;
ssbool var215;
ssbool var216;
ssbool var217;
ssfloat var218;
ssfloat var219;
ssfloat var220;
ssfloat var221;
ssbool var222;
ssfloat var223;
ssfloat var224;
ssint var225;
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
ssfloat var316;
ssbool var317;
ssbool var318;
ssbool var319;
ssfloat var320;
ssbool var321;
ssbool var322;
ssbool var323;
ssfloat var324;
ssbool var325;
ssbool var326;
ssbool var327;
ssfloat var328;
ssbool var329;
ssbool var330;
ssbool var331;
ssfloat var332;
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
ssfloat var429;
ssfloat var430;
ssbool var431;
ssfloat var432;
ssfloat var433;
ssbool var434;
ssfloat var435;
ssfloat var436;
ssbool var437;
ssfloat var438;
ssfloat var439;
ssbool var440;
ssbool var441;
ssfloat var442;
ssfloat var443;
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
ssbool var572;
sslong var573;
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
ssbool var983;
ssfloat var984;
ssbool var985;
ssfloat var986;
ssbool var987;
ssfloat var988;
ssbool var989;
ssbool var990;
ssbool var991;
ssbool var992;
ssfloat var993;
ssfloat var994;
ssfloat var995;
ssfloat var996;
ssfloat var997;
ssfloat var998;
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
ssint var1054;
ssint var1055;
ssbool var1056;
ssbool var1057;
ssbool var1058;
ssbool var1059;
ssbool var1060;
ssbool var1061;
sslong var1062;
ssbool var1063;
ssbool var1064;
ssbool var1065;
ssint var1066;
ssbool var1067;
ssbool var1068;
ssbool var1069;
ssbool var1070;
ssbool var1071;
ssbool var1072;
ssbool var1073;
ssbool var1074;
ssbool var1075;
ssint var1076;
ssint var1077;
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
sslong var1117;
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
ssfloat var1136;
ssbool var1137;
ssbool var1138;
ssbool var1139;
ssbool var1140;
ssbool var1141;
ssfloat var1142;
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
ssint var1156;
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
ssfloat var1181;
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
ssbool var1276;
sslong var1277;
ssbool var1278;
ssint var1279;
ssint var1280;
ssbool var1281;
ssfloat var1282;
ssfloat var1283;
ssfloat var1284;
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
ssint var1301;
ssbool var1302;
sschar var1303;
ssint var1304;
ssbool var1305;
ssfloat var1306;
ssbool var1307;
ssbool var1308;
ssbool var1309;
ssbool var1310;
ssbool var1311;
ssbool var1312;
ssbool var1313;
ssfloat var1314;
sschar var1315;
ssbool var1316;
ssbool var1317;
ssbool var1318;
ssbool var1319;
ssfloat var1320;
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
ssint var1333;
ssbool var1334;
sschar var1335;
ssint var1336;
ssbool var1337;
ssfloat var1338;
ssbool var1339;
ssbool var1340;
ssbool var1341;
ssbool var1342;
ssbool var1343;
ssbool var1344;
ssbool var1345;
ssfloat var1346;
sschar var1347;
ssbool var1348;
ssbool var1349;
ssbool var1350;
ssbool var1351;
ssfloat var1352;
ssbool var1353;
ssbool var1354;
ssbool var1355;
ssbool var1356;
ssbool var1357;
ssbool var1358;
ssbool var1359;
ssbool var1360;
ssbool var1361;
ssint var1362;
ssbool var1363;
sschar var1364;
ssint var1365;
ssbool var1366;
ssfloat var1367;
ssbool var1368;
ssbool var1369;
ssbool var1370;
ssbool var1371;
ssbool var1372;
ssbool var1373;
ssbool var1374;
ssfloat var1375;
sschar var1376;
ssbool var1377;
ssbool var1378;
ssbool var1379;
ssbool var1380;
ssfloat var1381;
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
ssbool var1394;
ssint var1395;
ssbool var1396;
sschar var1397;
ssint var1398;
ssbool var1399;
ssfloat var1400;
ssbool var1401;
ssbool var1402;
ssbool var1403;
ssbool var1404;
ssbool var1405;
ssbool var1406;
ssbool var1407;
ssfloat var1408;
sschar var1409;
ssbool var1410;
ssbool var1411;
ssfloat var1412;
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
ssint var1425;
ssbool var1426;
ssbool var1427;
ssbool var1428;
ssbool var1429;
ssbool var1430;
ssbool var1431;
ssbool var1432;
ssbool var1433;
ssint var1434;
ssbool var1435;
ssbool var1436;
ssbool var1437;
ssbool var1438;
ssbool var1439;
ssbool var1440;
ssbool var1441;
ssint var1442;
ssbool var1443;
sschar var1444;
ssint var1445;
ssbool var1446;
ssfloat var1447;
ssbool var1448;
ssbool var1449;
ssbool var1450;
ssbool var1451;
ssbool var1452;
ssbool var1453;
ssbool var1454;
ssfloat var1455;
sschar var1456;
ssbool var1457;
ssbool var1458;
ssfloat var1459;
ssbool var1460;
ssbool var1461;
ssbool var1462;
ssbool var1463;
ssbool var1464;
ssbool var1465;
ssbool var1466;
ssbool var1467;
sschar var1468;
ssbool var1469;
ssbool var1470;
ssbool var1471;
ssbool var1472;
ssbool var1473;
ssbool var1474;
ssbool var1475;
ssbool var1476;
ssbool var1477;
sschar var1478;
ssbool var1479;
ssbool var1480;
ssint var1481;
ssbool var1482;
sschar var1483;
ssbool var1484;
ssint var1485;
ssbool var1486;
ssbool var1487;
ssfloat var1488;
ssbool var1489;
ssbool var1490;
ssbool var1491;
ssbool var1492;
ssbool var1493;
ssbool var1494;
ssbool var1495;
ssfloat var1496;
sschar var1497;
ssbool var1498;
ssbool var1499;
ssbool var1500;
ssbool var1501;
ssfloat var1502;
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
ssbool var1514;
ssfloat var1515;
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
ssbool var1531;
ssfloat var1532;
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
ssbool var1569;
ssint var1570;
ssbool var1571;
ssbool var1572;
ssbool var1573;
ssbool var1574;
ssbool var1575;
ssbool var1576;
ssbool var1577;
ssbool var1578;
ssint var1579;
ssbool var1580;
ssbool var1581;
ssbool var1582;
ssbool var1583;
ssbool var1584;
ssbool var1585;
ssbool var1586;
ssbool var1587;
ssint var1588;
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
ssbool var1599;
ssbool var1600;
ssbool var1601;
ssbool var1602;
ssbool var1603;
ssbool var1604;
ssbool var1605;
ssint var1606;
ssbool var1607;
ssbool var1608;
ssbool var1609;
ssbool var1610;
ssbool var1611;
ssbool var1612;
ssbool var1613;
ssbool var1614;
ssint var1615;
ssbool var1616;
ssbool var1617;
ssbool var1618;
ssbool var1619;
ssbool var1620;
ssbool var1621;
ssbool var1622;
ssbool var1623;
ssint var1624;
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
ssbool var1695;
ssfloat var1696;
ssfloat var1697;
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
ssbool var1723;
ssfloat var1724;
ssbool var1725;
ssbool var1726;
ssfloat var1727;
ssbool var1728;
ssbool var1729;
ssfloat var1730;
ssbool var1731;
ssbool var1732;
ssfloat var1733;
ssbool var1734;
ssbool var1735;
ssfloat var1736;
ssbool var1737;
ssbool var1738;
ssfloat var1739;
ssbool var1740;
ssbool var1741;
ssfloat var1742;
ssbool var1743;
ssbool var1744;
ssbool var1745;
ssfloat var1746;
ssbool var1747;
ssbool var1748;
ssbool var1749;
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
psbool  array_m243_x_2[6] = {&var1708,&var1700,&var1714,&B0VT71LZ1,&B0VT71LZ2,&var1659};
psbool  array_m232_x_2[6] = {&var1709,&var1702,&var1715,&A0VT71LZ1,&A0VT71LZ2,&var1659};
psbool  array_m255_x_2[6] = {&var1693,&B0VP71LZ1,&B0VP71LZ2,&var1664,&var1663,&var1662};
psbool  array_m234_x_2[6] = {&var1694,&A0VP71LZ1,&A0VP71LZ2,&var1667,&var1666,&var1665};
psbool  array_m124_x_2[8] = {&var1726,&var1748,&var1744,&var1741,&var1738,&var1735,&var1729,&var1732};
psbool  array_m2330_x_1[6] = {&var11,&var10,&R0DE36LDU,&R0DE37LDU,&R0DE38LDU,&R0DE39LDU};
psint  array_m2314_x_1[12] = {&R0DE0DLDU,&R0DE0FLDU,&R0DE02LDU,&R0DE03LDU,&R0DE04LDU,&R0DE05LDU,&R0DE07LDU,&R0DE08LDU,&R0DE09LDU,&R0DE0ALDU,&R0DE0BLDU,&R0DE0CLDU};
psbool  array_m815_x_1[6] = {&var604,&var1240,&var1216,&var1205,&var1009,&var92};
psbool  array_m1215_x_1[6] = {&var603,&var1220,&var17,&var1242,&var1009,&var112};
psbool  array_m606_x_1[6] = {&var799,&var1108,&var1527,&var1069,&var1486,&var1102};
psbool  array_m605_x_1[6] = {&var799,&var1109,&var1527,&var1069,&var1486,&var1101};
psfloat  array_m2221_a_1[6] = {&fEM_R0UN70LDU,&fEM_R0UN71LDU,&fEM_R0UN72LDU,&fEM_R0UN73LDU,&fEM_R0UN74LDU,&fEM_R0UN75LDU};
psfloat  array_m2221_b_1[6] = {&fEM_R0UN80LDU,&fEM_R0UN81LDU,&fEM_R0UN82LDU,&fEM_R0UN83LDU,&fEM_R0UN84LDU,&fEM_R0UN85LDU};
psfloat  array_m2234_x_1[4] = {&B0CT01IZ1,&A0CT01IZ1,&B0CT01IZ2,&A0CT01IZ2};
psfloat  array_m2256_x_1[2] = {&R0VN09RZ1,&R0VN09RZ2};
psbool  array_m2225_x_1[14] = {&var204,&var177,&var833,&var238,&var240,&var175,&var1649,&var1229,&var1227,&var1660,&var203,&var192,&var188,&var212};
psbool  array_m1_x_1[47] = {&var1192,&lRM_0_,&var337,&var67,&var487,&var1396,&var722,&R0MD34LP1,&var636,&R0MD34LP1,&var695,&R0MD34LP1,&var929,&R0MD34LP1,&var749,&R0MD34LP1,&var927,&var1423,&A2IS12LDU,&var394,&var1223,&var1116,&var1114,&var1027,&var842,&R0MD34LP1,&var424,&var465,&var1267,&var1577,&R0MD34LP1,&var580,&var571,&var526,&B3IS35LDU,&B3IS35LDU,&var259,&var65,&var498,&var306,&var1628,&var1586,&var1613,&var948,&var1600,&R2IS21LDU,&var178};
psfloat  array_m1481_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psbool  array_m1435_x_1[5] = {&var580,&var579,&var578,&var577,&var576};
psbool  array_m564_x_1[14] = {&var747,&var753,&var754,&var745,&var746,&var931,&var932,&var912,&var911,&var743,&var741,&var749,&var742,&var232};
psfloat  array_m88_x_1[2] = {&R0VN11RZ2,&R0VN11RZ1};
psfloat  array_m90_x_1[8] = {&fEM_R0UN01RDU,&fEM_R0UN02RDU,&fEM_R0UN03RDU,&fEM_R0UN04RDU,&fEM_R0UN05RDU,&fEM_R0UN06RDU,&fEM_R0UN07RDU,&fEM_R0UN08RDU};
psfloat  array_m1073_x_1[2] = {&R0VN11RZ2,&R0VN11RZ1};
psfloat  array_m1225_x_1[8] = {&var1488,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m823_x_1[8] = {&var1447,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m905_x_1[8] = {&var1338,&var201,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m1322_x_1[8] = {&var1306,&var200,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m506_x_1[8] = {&var1367,&var328,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m171_x_1[8] = {&var1400,&var332,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m344_Tpr_1[10] = {&fRM_6_0,&fRM_126_0,&fRM_246_0,&fRM_366_0,&fRM_486_0,&fRM_606_0,&fRM_726_0,&fRM_846_0,&fRM_966_0,&fRM_1200_0};
pschar  array_m344_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m344_rz_1[10];
psbool  array_m348_x_1[5] = {&var1057,&var1058,&var1059,&var1060,&var1061};
psbool  array_m283_x_1[7] = {&var833,&var234,&var1036,&var1033,&var240,&var238,&var236};
psfloat  array_m287_Tpr_1[10] = {&fRM_10_0,&fRM_30_0,&fRM_50_0,&fRM_70_0,&fRM_90_0,&fRM_110_0,&fRM_130_0,&fRM_150_0,&fRM_170_0,&fRM_200_0};
pschar  array_m287_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m287_rz_1[10];
psfloat  array_m1424_Tpr_1[6] = {&fRM_0_5,&fRM_3_5,&fRM_6_5,&fRM_9_5,&fRM_12_5,&fRM_15_5};
pschar  array_m1424_type_1[6] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_6_};
pschar  array_m1424_rz_1[6];
psbool  array_m303_x_1[5] = {&var1079,&var1080,&var1081,&var1082,&var1083};
psbool  array_m1199_x_1[5] = {&var1204,&var816,&var1559,&var1209,&var250};
psbool  array_m1187_x_1[4] = {&var1113,&var1155,&var1029,&var1207};
psfloat  array_m1465_x_1[16] = {&var429,&var438,&fRM_0_,&var435,&fRM_0_,&fRM_0_,&fRM_0_,&var432,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&var442};
psbool  array_m1785_x_1[17] = {&var509,&var510,&var516,&var511,&var507,&var508,&var966,&var512,&var513,&var1256,&var514,&var515,&var1248,&var1249,&var1258,&var244,&var245};
psbool  array_m1427_x_1[5] = {&var421,&var544,&var561,&var562,&var451};
psint  array_m322_x_1[3] = {&var1055,&iRM_0_,&var1077};
psint  array_m313_x_1[3] = {&var1054,&iRM_0_,&var1076};
psbool  array_m608_x_1[5] = {&var782,&var1526,&var1293,&var1010,&var210};
psbool  array_m1386_x_1[8] = {&var666,&var667,&var668,&var663,&var662,&var661,&var927,&var659};
psbool  array_m1321_x_1[3] = {&var94,&lRM_0_,&var93};
psfloat  array_m1323_Lt_fw_1[1] = {&fEM_A3UC81RDU};
psint  array_m1323_Vr_fw_1[1] = {&iEM_A3UV01IDU};
psfloat  array_m1323_Lt_bw_1[1] = {&fEM_A3UC82RDU};
psint  array_m1323_Vr_bw_1[1] = {&iEM_A3UV02IDU};
psfloat  array_m1351_x0_1[60];
psfloat  array_m1351_tim0_1[60];
psbool  array_m974_x_1[8] = {&var681,&var683,&var684,&var676,&var682,&var678,&var929,&var410};
psbool  array_m904_x_1[3] = {&var120,&lRM_0_,&var115};
psfloat  array_m906_Lt_fw_1[1] = {&fEM_A3UC81RDU};
psint  array_m906_Vr_fw_1[1] = {&iEM_A3UV01IDU};
psfloat  array_m906_Lt_bw_1[1] = {&fEM_A3UC82RDU};
psint  array_m906_Vr_bw_1[1] = {&iEM_A3UV02IDU};
psfloat  array_m939_x0_1[60];
psfloat  array_m939_tim0_1[60];
psbool  array_m505_x_1[3] = {&var758,&lRM_0_,&var759};
psfloat  array_m508_Lt_fw_1[2] = {&fEM_A1UC81RDU,&fEM_A1UC82RDU};
psint  array_m508_Vr_fw_1[2] = {&iEM_A1UV01IDU,&iEM_A1UV02IDU};
psfloat  array_m508_Lt_bw_1[1] = {&fEM_A1UC83RDU};
psint  array_m508_Vr_bw_1[1] = {&iEM_A1UV03IDU};
psfloat  array_m535_x0_1[150];
psfloat  array_m535_tim0_1[150];
psbool  array_m247_x_1[12] = {&var727,&var729,&var728,&var725,&var723,&var722,&var721,&var935,&var934,&var716,&var719,&var233};
psbool  array_m170_x_1[3] = {&var905,&lRM_0_,&var906};
psfloat  array_m174_Lt_fw_1[2] = {&fEM_A1UC81RDU,&fEM_A1UC82RDU};
psint  array_m174_Vr_fw_1[2] = {&iEM_A1UV01IDU,&iEM_A1UV02IDU};
psfloat  array_m174_Lt_bw_1[1] = {&fEM_A1UC83RDU};
psint  array_m174_Vr_bw_1[1] = {&iEM_A1UV03IDU};
psfloat  array_m213_x0_1[150];
psfloat  array_m213_tim0_1[150];
psbool  array_m879_x_1[10] = {&var693,&var694,&var700,&var701,&var699,&var697,&var696,&var937,&var936,&var695};
psbool  array_m822_x_1[3] = {&var96,&var711,&var95};
psfloat  array_m826_Lt_fw_1[2] = {&fEM_A2UC81RDU,&fEM_A2UC82RDU};
psint  array_m826_Vr_fw_1[2] = {&iEM_A2UV01IDU,&iEM_A2UV02IDU};
psfloat  array_m826_Lt_bw_1[1] = {&fEM_A2UC83RDU};
psint  array_m826_Vr_bw_1[1] = {&iEM_A2UV03CDU};
psfloat  array_m846_x0_1[80];
psfloat  array_m846_tim0_1[80];
psfloat  array_m1605_Lt_fw_1[1] = {&fRM_1000_};
psint  array_m1605_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1605_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1605_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1296_x_1[10] = {&var632,&var633,&var635,&var634,&var636,&var638,&var640,&var637,&var639,&var641};
psbool  array_m152_x_1[5] = {&A1IS21LDU,&A3IS21LDU,&A2IS21LDU,&var952,&var951};
psfloat  array_m1126_Lt_fw_1[1] = {&fRM_2000_};
psint  array_m1126_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1126_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1126_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1224_x_1[3] = {&var124,&var626,&var111};
psfloat  array_m1226_Lt_fw_1[2] = {&fEM_A2UC81RDU,&fEM_A2UC82RDU};
psint  array_m1226_Vr_fw_1[2] = {&iEM_A2UV01IDU,&iEM_A2UV02IDU};
psfloat  array_m1226_Lt_bw_1[1] = {&fEM_A2UC83RDU};
psint  array_m1226_Vr_bw_1[1] = {&iEM_A2UV03CDU};
psfloat  array_m1261_x0_1[80];
psfloat  array_m1261_tim0_1[80];
psfloat  array_m1625_x0_1[20];
psfloat  array_m1625_tim0_1[20];
psbool  array_m1097_x_1[8] = {&var843,&var840,&var841,&var842,&var839,&var838,&var837,&var836};
psbool  array_m609_x_1[18] = {&R0MD31LP1,&var534,&var857,&var536,&var855,&var627,&var762,&var710,&var737,&var757,&var686,&var651,&var913,&var349,&var348,&var617,&var266,&var202};
psfloat  array_m1150_x0_1[20];
psfloat  array_m1150_tim0_1[20];
psbool  array_m449_x_1[7] = {&var958,&var957,&var956,&var955,&var1630,&var947,&var378};
psbool  array_m431_x_1[7] = {&var960,&var1630,&var948,&var961,&var959,&var946,&var148};
psbool  array_m779_x_1[17] = {&var858,&var903,&var902,&var899,&var898,&var895,&var860,&var897,&var865,&var894,&var890,&var892,&var891,&var862,&var856,&var945,&var713};
psbool  array_m138_x_1[21] = {&var736,&var756,&var1001,&var709,&var1000,&var999,&var1564,&var1573,&var1591,&var1582,&var1618,&var1609,&var487,&var379,&var991,&var992,&var1270,&var1264,&var1428,&var1419,&var1600};

/* Объявление структур */
_S_and4  S_and4_106_2 = {&var1745,&var1680,&B8IS11LDU,&B8IS12LDU,&var1650};
_S_lkb  S_lkb_111_2 = {&lRM_1_,&var1678,&var1651};
_S_lkb  S_lkb_107_2 = {&lRM_1_,&var1650,&var1652};
_S_lkb  S_lkb_80_2 = {&lRM_1_,&var1681,&var1653};
_S_lkb  S_lkb_50_2 = {&lRM_1_,&var1686,&var1654};
_S_lkb  S_lkb_83_2 = {&lRM_1_,&var1684,&var1655};
_S_lkb  S_lkb_46_2 = {&lRM_1_,&var1690,&var1656};
_S_lkb  S_lkb_24_2 = {&lRM_1_,&var1688,&var1657};
_S_lkb  S_lkb_20_2 = {&lRM_1_,&var1692,&var1658};
_S_or2  S_or2_258_2 = {&var1749,&var1698,&var1659};
_S_bol  S_bol_223_2 = {&fRM_0_5,&var1661,&var1660};
_S_fsumo  S_fsumo_222_2 = {&var1697,&var1696,&var1661};
_S_noto  S_noto_251_2 = {&B3VP81LDU,&var1662};
_S_noto  S_noto_250_2 = {&B2VP82LDU,&var1663};
_S_noto  S_noto_249_2 = {&B4VP82LDU,&var1664};
_S_noto  S_noto_231_2 = {&A3VP81LDU,&var1665};
_S_noto  S_noto_230_2 = {&A2VP82LDU,&var1666};
_S_noto  S_noto_229_2 = {&A4VP82LDU,&var1667};
_S_schl24  S_schl24_149_2 = {&A0EE02LZ1,&A0EE03LZ1,&A0EE01LZ1,&A0EE04LZ1,&var1668};
_S_schl24  S_schl24_143_2 = {&A0EE03LZ2,&A0EE01LZ2,&A0EE02LZ2,&A0EE04LZ2,&var1669};
_S_or2  S_or2_198_2 = {&var1718,&var1719,&var1670};
_S_or2  S_or2_195_2 = {&var1721,&var1722,&var1671};
_S_and2  S_and2_213_2 = {&var1706,&var1717,&var1672};
_S_or2  S_or2_244_2 = {&var1713,&var1712,&var1673};
_S_and4  S_and4_159_2 = {&A0EE02LZ1,&A0EE04LZ1,&A0EE02LZ2,&A0EE04LZ2,&var1674};
_S_or3  S_or3_158_2 = {&var1674,&var821,&var1668,&var1675};
_S_and4  S_and4_136_2 = {&A0EE03LZ1,&A0EE01LZ1,&A0EE01LZ2,&A0EE03LZ2,&var1676};
_S_or3  S_or3_135_2 = {&var1676,&var1669,&var821,&var1677};
_S_and3  S_and3_110_2 = {&var1679,&var1745,&A8IS12LDU,&var1678};
_S_or2  S_or2_104_2 = {&A8MC01LC2,&A8MC01LC1,&var1679};
_S_or2  S_or2_103_2 = {&B8MC01LC2,&B8MC01LC1,&var1680};
_S_and3  S_and3_79_2 = {&var1745,&B3IS11LDU,&var1682,&var1681};
_S_or2  S_or2_71_2 = {&B3MC01LC2,&B3MC01LC1,&var1682};
_S_or2  S_or2_74_2 = {&A3MC01LC2,&A3MC01LC1,&var1683};
_S_and3  S_and3_82_2 = {&var1745,&var1683,&A3IS11LDU,&var1684};
_S_or2  S_or2_43_2 = {&A2MC01LC2,&A2MC01LC1,&var1685};
_S_and3  S_and3_49_2 = {&var1745,&A2IS11LDU,&var1685,&var1686};
_S_or2  S_or2_13_2 = {&A1MC01LC2,&A1MC01LC1,&var1687};
_S_and3  S_and3_23_2 = {&var1687,&var1745,&A1IS11LDU,&var1688};
_S_or2  S_or2_42_2 = {&B2MC01LC1,&B2MC01LC2,&var1689};
_S_and3  S_and3_45_2 = {&var1745,&B2IS11LDU,&var1689,&var1690};
_S_or2  S_or2_11_2 = {&B1MC01LC2,&B1MC01LC1,&var1691};
_S_and3  S_and3_19_2 = {&var1745,&B1IS11LDU,&var1691,&var1692};
_S_and2  S_and2_254_2 = {&syn_R0EE03LDU,&var1670,&var1693};
_S_and2  S_and2_233_2 = {&syn_R0EE03LDU,&var1671,&var1694};
_S_and2  S_and2_219_2 = {&var1707,&var1716,&var1695};
_S_scalzz  S_scalzz_186_2 = {&B3IP02IDU,&iRM_3276_,&iRM_16383_,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&var1696,&internal2_m186_y0};
_S_scalzz  S_scalzz_184_2 = {&A3IP02IDU,&iRM_3276_,&iRM_16383_,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&var1697,&internal2_m184_y0};
_S_noto  S_noto_171_2 = {&var1699,&var1698};
_S_andn  S_andn_170_2 = {array_m170_x_2,&iRM_17_,&var1699};
_S_noto  S_noto_153_2 = {&var1701,&var1700};
_S_andn  S_andn_150_2 = {array_m150_x_2,&iRM_6_,&var1701};
_S_noto  S_noto_134_2 = {&var1703,&var1702};
_S_andn  S_andn_131_2 = {array_m131_x_2,&iRM_6_,&var1703};
_S_noto  S_noto_253_2 = {&var1712,&var1704};
_S_noto  S_noto_235_2 = {&var1713,&var1705};
_S_noto  S_noto_212_2 = {&var1721,&var1706};
_S_noto  S_noto_220_2 = {&var1718,&var1707};
_S_noto  S_noto_157_2 = {&var1675,&var1708};
_S_noto  S_noto_141_2 = {&var1677,&var1709};
_S_noto  S_noto_256_2 = {&var1714,&var1710};
_S_noto  S_noto_240_2 = {&var1715,&var1711};
_S_ornc  S_ornc_243_2 = {array_m243_x_2,&iRM_6_,&var1712,&vainSChar};
_S_ornc  S_ornc_232_2 = {array_m232_x_2,&iRM_6_,&var1713,&vainSChar};
_S_ornc  S_ornc_255_2 = {array_m255_x_2,&iRM_6_,&var1714,&vainSChar};
_S_ornc  S_ornc_234_2 = {array_m234_x_2,&iRM_6_,&var1715,&vainSChar};
_S_tprg  S_tprg_216_2 = {&var1696,&fEM_A3UP85RDU,&fEM_A3UP86RDU,&fEM_A3UP87RDU,&fEM_A3UP88RDU,&var1716,&internal2_m216_y0};
_S_tprg  S_tprg_210_2 = {&var1697,&fEM_A3UP85RDU,&fEM_A3UP86RDU,&fEM_A3UP87RDU,&fEM_A3UP88RDU,&var1717,&internal2_m210_y0};
_S_geterr  S_geterr_191_2 = {&var1696,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var1718};
_S_drg  S_drg_199_2 = {&var1696,&lRM_1_,&lRM_0_,&fEM_A3UP43RDU,&fEM_A3UP44RDU,&var1719,&internal2_m199_y1};
_S_drg  S_drg_206_2 = {&var1696,&lRM_1_,&lRM_0_,&fEM_A3UP53RDU,&fEM_A3UP54RDU,&var1720,&internal2_m206_y1};
_S_geterr  S_geterr_188_2 = {&var1697,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var1721};
_S_drg  S_drg_189_2 = {&var1697,&lRM_1_,&lRM_0_,&fEM_A3UP43RDU,&fEM_A3UP44RDU,&var1722,&internal2_m189_y1};
_S_drg  S_drg_196_2 = {&var1697,&lRM_1_,&lRM_0_,&fEM_A3UP53RDU,&fEM_A3UP54RDU,&var1723,&internal2_m196_y1};
_S_enctkb  S_enctkb_16_2 = {&var1657,&fRM_0_0,&A1IC01UDU,&dEM_A1UC06UDU,&dEM_A1UC05UDU,&fEM_A1UC03RDU,&fRM_100_,&dRM_0_,&var1724,&var1725,&var1726,&internal2_m16_Nk0,&internal2_m16_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_108_2 = {&var1652,&fRM_390_,&B8IC01UDU,&dEM_A8UC06UDU,&dEM_A8UC05UDU,&fEM_A8UC03RDU,&fRM_1500_0,&dRM_0_,&var1727,&var1728,&var1729,&internal2_m108_Nk0,&internal2_m108_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_112_2 = {&var1651,&fRM_390_0,&A8IC01UDU,&dEM_A8UC06UDU,&dEM_A8UC05UDU,&fEM_A8UC03RDU,&fRM_1500_0,&dRM_0_,&var1730,&var1731,&var1732,&internal2_m112_Nk0,&internal2_m112_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_75_2 = {&var1653,&fRM_0_,&B3IC01UDU,&dEM_A3UC06UDU,&dEM_A3UC05UDU,&fEM_A3UC03RDU,&fRM_0_0,&dRM_0_,&var1733,&var1734,&var1735,&internal2_m75_Nk0,&internal2_m75_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_77_2 = {&var1655,&fRM_0_0,&A3IC01UDU,&dEM_A3UC06UDU,&dEM_A3UC05UDU,&fEM_A3UC03RDU,&fRM_0_0,&dRM_0_,&var1736,&var1737,&var1738,&internal2_m77_Nk0,&internal2_m77_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_47_2 = {&var1656,&fRM_0_0,&B2IC01UDU,&dEM_A2UC06UDU,&dEM_A2UC05UDU,&fEM_A2UC03RDU,&fRM_100_,&dRM_0_,&var1739,&var1740,&var1741,&internal2_m47_Nk0,&internal2_m47_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_51_2 = {&var1654,&fRM_0_0,&A2IC01UDU,&dEM_A2UC06UDU,&dEM_A2UC05UDU,&fEM_A2UC03RDU,&fRM_100_,&dRM_0_,&var1742,&var1743,&var1744,&internal2_m51_Nk0,&internal2_m51_SetFlag,&bFirstEnterFlag};
_S_equz_p  S_equz_p_18_2 = {&R0MW12IP1,&iRM_4_,&var1745};
_S_enctkb  S_enctkb_21_2 = {&var1658,&fRM_0_0,&B1IC01UDU,&dEM_A1UC06UDU,&dEM_A1UC05UDU,&fEM_A1UC03RDU,&fRM_100_,&dRM_0_,&var1746,&var1747,&var1748,&internal2_m21_Nk0,&internal2_m21_SetFlag,&bFirstEnterFlag};
_S_ornc  S_ornc_124_2 = {array_m124_x_2,&iRM_8_,&var1749,&vainSChar};
_S_zapomni  S_zapomni_198_1 = {&var735,&internal1_m198_s,&var1};
_S_zapomni  S_zapomni_195_1 = {&var734,&internal1_m195_s,&var2};
_S_zapomni  S_zapomni_188_1 = {&var1414,&internal1_m188_s,&var3};
_S_zapomni  S_zapomni_183_1 = {&var736,&internal1_m183_s,&var4};
_S_zapomni  S_zapomni_179_1 = {&var717,&internal1_m179_s,&var5};
_S_noto  S_noto_1862_1 = {&B7AS31LDU,&var6};
_S_noto  S_noto_1859_1 = {&A7AS31LDU,&var7};
_S_or3  S_or3_2331_1 = {&var9,&var12,&var13,&var8};
_S_orn  S_orn_2330_1 = {array_m2330_x_1,&iRM_6_,&var9};
_S_or2  S_or2_2335_1 = {&R0DEB3LDU,&R0DEB4LDU,&var10};
_S_or2  S_or2_2328_1 = {&R0DEB1LDU,&R0DEB2LDU,&var11};
_S_and2  S_and2_2319_1 = {&R0DE31LDU,&R0DE32LDU,&var12};
_S_diagndev  S_diagndev_2314_1 = {array_m2314_x_1,&iRM_12_,&var13,&var14};
_S_or2  S_or2_1711_1 = {&var252,&var65,&var15};
_S_and2  S_and2_1701_1 = {&var308,&var1213,&var16};
_S_rs  S_rs_1710_1 = {&var15,&var16,&var17,&vainSBool,&internal1_m1710_q0};
_S_or2  S_or2_1705_1 = {&var308,&var255,&var18};
_S_or2  S_or2_1646_1 = {&var1263,&var308,&var19};
_S_noto  S_noto_1689_1 = {&B2IS11LDU,&var20};
_S_or2  S_or2_1674_1 = {&var23,&var65,&var21};
_S_or2  S_or2_1676_1 = {&var135,&var65,&var22};
_S_noto  S_noto_1687_1 = {&A2IS11LDU,&var23};
_S_or2  S_or2_2152_1 = {&var252,&var61,&var24};
_S_or2  S_or2_2150_1 = {&var61,&var259,&var25};
_S_or2  S_or2_2148_1 = {&var74,&var61,&var26};
_S_and2  S_and2_2131_1 = {&var1210,&var306,&var27};
_S_or2  S_or2_2146_1 = {&var29,&var61,&var28};
_S_noto  S_noto_2155_1 = {&B3IS11LDU,&var29};
_S_or2  S_or2_2182_1 = {&var65,&var259,&var30};
_S_and2  S_and2_2162_1 = {&var1210,&var307,&var31};
_S_noto  S_noto_2187_1 = {&A3IS11LDU,&var32};
_S_or2  S_or2_2184_1 = {&var252,&var65,&var33};
_S_or2  S_or2_2180_1 = {&var65,&var75,&var34};
_S_or2  S_or2_2178_1 = {&var65,&var32,&var35};
_S_or2  S_or2_1654_1 = {&var252,&var65,&var36};
_S_or2  S_or2_1658_1 = {&var252,&var61,&var37};
_S_or2  S_or2_1649_1 = {&var308,&var1263,&var38};
_S_or2  S_or2_1684_1 = {&var61,&var134,&var39};
_S_or2  S_or2_1682_1 = {&var20,&var61,&var40};
_S_or2  S_or2_1727_1 = {&var259,&var61,&var41};
_S_or2  S_or2_1724_1 = {&var259,&var65,&var42};
_S_or2  S_or2_1756_1 = {&var265,&var61,&var43};
_S_or2  S_or2_1753_1 = {&var265,&var65,&var44};
_S_or2  S_or2_1713_1 = {&var252,&var61,&var45};
_S_or2  S_or2_1678_1 = {&var252,&var65,&var46};
_S_or2  S_or2_1686_1 = {&var252,&var61,&var47};
_S_or3  S_or3_2142_1 = {&var259,&var306,&var61,&var48};
_S_or3  S_or3_2144_1 = {&var84,&var306,&var61,&var49};
_S_or3  S_or3_2176_1 = {&var65,&var87,&var307,&var50};
_S_or3  S_or3_2174_1 = {&var259,&var65,&var307,&var51};
_S_or3  S_or3_2140_1 = {&var306,&var252,&var61,&var52};
_S_or3  S_or3_2172_1 = {&var252,&var307,&var65,&var53};
_S_or3  S_or3_1652_1 = {&var252,&var307,&var65,&var54};
_S_or3  S_or3_1656_1 = {&var306,&var252,&var61,&var55};
_S_or3  S_or3_1672_1 = {&var252,&var307,&var65,&var56};
_S_or3  S_or3_1680_1 = {&var252,&var306,&var61,&var57};
_S_or3  S_or3_1709_1 = {&var252,&var308,&var61,&var58};
_S_or3  S_or3_1707_1 = {&var252,&var65,&var308,&var59};
_S_or3  S_or3_1755_1 = {&var61,&var306,&var265,&var60};
_S_noto  S_noto_1750_1 = {&var918,&var61};
_S_or3  S_or3_1726_1 = {&var61,&var259,&var306,&var62};
_S_or3  S_or3_1723_1 = {&var259,&var65,&var307,&var63};
_S_or3  S_or3_1752_1 = {&var265,&var65,&var307,&var64};
_S_noto  S_noto_1749_1 = {&var917,&var65};
_S_regch  S_regch_131_1 = {&R0MW12IP1,&var907,&var66};
_S_or2  S_or2_134_1 = {&var68,&var66,&var67};
_S_or2  S_or2_133_1 = {&R0VZ71LZ1,&R0VZ71LZ2,&var68};
_S_and3  S_and3_1419_1 = {&R0MD11LP2,&var966,&var72,&var69};
_S_and2  S_and2_742_1 = {&R4MD21LP2,&var72,&var70};
_S_and2  S_and2_740_1 = {&R4MD11LP2,&var72,&var71};
_S_noto  S_noto_113_1 = {&var1640,&var72};
_S_and2  S_and2_111_1 = {&R0MD11LP1,&var72,&var73};
_S_noto  S_noto_2156_1 = {&B3IS22LDU,&var74};
_S_noto  S_noto_2188_1 = {&A3IS22LDU,&var75};
_S_and2  S_and2_2079_1 = {&var483,&var1192,&var76};
_S_or3  S_or3_2074_1 = {&var482,&var178,&var116,&var77};
_S_and2  S_and2_2063_1 = {&var479,&var1192,&var78};
_S_or3  S_or3_2060_1 = {&var178,&var480,&var99,&var79};
_S_or2  S_or2_1484_1 = {&var1281,&var1210,&var80};
_S_or2  S_or2_1453_1 = {&var1138,&var1210,&var81};
_S_rs  S_rs_2145_1 = {&var28,&var85,&var82,&vainSBool,&internal1_m2145_q0};
_S_rs  S_rs_2129_1 = {&var28,&var104,&var83,&vainSBool,&internal1_m2129_q0};
_S_noto  S_noto_2153_1 = {&syn_B3VP52LDU,&var84};
_S_and2  S_and2_2136_1 = {&var84,&var83,&var85};
_S_rs  S_rs_2177_1 = {&var35,&var88,&var86,&vainSBool,&internal1_m2177_q0};
_S_noto  S_noto_2185_1 = {&syn_A3VP52LDU,&var87};
_S_and2  S_and2_2168_1 = {&var89,&var87,&var88};
_S_rs  S_rs_2161_1 = {&var35,&var122,&var89,&vainSBool,&internal1_m2161_q0};
_S_and4  S_and4_1374_1 = {&var966,&var1210,&var270,&var1255,&var90};
_S_and4  S_and4_962_1 = {&var966,&var1210,&var270,&var1255,&var91};
_S_rs  S_rs_2151_1 = {&var24,&var97,&var92,&vainSBool,&internal1_m2151_q0};
_S_or4  S_or4_1311_1 = {&var602,&var292,&var1005,&var99,&var93};
_S_or4  S_or4_1320_1 = {&var167,&var295,&var778,&var105,&var94};
_S_orn  S_orn_815_1 = {array_m815_x_1,&iRM_6_,&var95};
_S_or3  S_or3_827_1 = {&var797,&var1206,&var108,&var96};
_S_and2  S_and2_2138_1 = {&var259,&var98,&var97};
_S_rs  S_rs_2132_1 = {&var24,&var100,&var98,&vainSBool,&internal1_m2132_q0};
_S_rs  S_rs_2149_1 = {&var100,&var25,&var99,&vainSBool,&internal1_m2149_q0};
_S_and2  S_and2_2137_1 = {&var101,&var74,&var100};
_S_rs  S_rs_2130_1 = {&var25,&var27,&var101,&vainSBool,&internal1_m2130_q0};
_S_rs  S_rs_2128_1 = {&var49,&var106,&var102,&vainSBool,&internal1_m2128_q0};
_S_rs  S_rs_2127_1 = {&var48,&var107,&var103,&vainSBool,&internal1_m2127_q0};
_S_and2  S_and2_2135_1 = {&var259,&var102,&var104};
_S_rs  S_rs_2141_1 = {&var48,&var106,&var105,&vainSBool,&internal1_m2141_q0};
_S_and2  S_and2_2134_1 = {&var103,&var252,&var106};
_S_and2  S_and2_2133_1 = {&var309,&var1210,&var107};
_S_rs  S_rs_2139_1 = {&var52,&var107,&var108,&vainSBool,&internal1_m2139_q0};
_S_rs  S_rs_2147_1 = {&var27,&var26,&var109,&vainSBool,&internal1_m2147_q0};
_S_rs  S_rs_2143_1 = {&var49,&var104,&var110,&vainSBool,&internal1_m2143_q0};
_S_orn  S_orn_1215_1 = {array_m1215_x_1,&iRM_6_,&var111};
_S_rs  S_rs_2183_1 = {&var33,&var113,&var112,&vainSBool,&internal1_m2183_q0};
_S_and2  S_and2_2170_1 = {&var259,&var114,&var113};
_S_rs  S_rs_2164_1 = {&var33,&var117,&var114,&vainSBool,&internal1_m2164_q0};
_S_or4  S_or4_894_1 = {&var601,&var296,&var1005,&var116,&var115};
_S_rs  S_rs_2181_1 = {&var30,&var117,&var116,&vainSBool,&internal1_m2181_q0};
_S_and2  S_and2_2169_1 = {&var118,&var75,&var117};
_S_rs  S_rs_2163_1 = {&var30,&var31,&var118,&vainSBool,&internal1_m2163_q0};
_S_rs  S_rs_2160_1 = {&var50,&var125,&var119,&vainSBool,&internal1_m2160_q0};
_S_or4  S_or4_903_1 = {&var1203,&var167,&var788,&var123,&var120};
_S_rs  S_rs_2159_1 = {&var51,&var126,&var121,&vainSBool,&internal1_m2159_q0};
_S_and2  S_and2_2167_1 = {&var259,&var119,&var122};
_S_rs  S_rs_2173_1 = {&var51,&var125,&var123,&vainSBool,&internal1_m2173_q0};
_S_or3  S_or3_1227_1 = {&var796,&var1208,&var127,&var124};
_S_and2  S_and2_2166_1 = {&var121,&var252,&var125};
_S_and2  S_and2_2165_1 = {&var310,&var1210,&var126};
_S_rs  S_rs_2171_1 = {&var53,&var126,&var127,&vainSBool,&internal1_m2171_q0};
_S_or2  S_or2_2046_1 = {&var169,&var1037,&var128};
_S_ovbs  S_ovbs_2048_1 = {&var228,&fRM_2_0,&var129,&internal1_m2048_tx};
_S_or2  S_or2_2049_1 = {&var1219,&var129,&var130};
_S_ovbs  S_ovbs_2027_1 = {&var229,&fRM_2_0,&var131,&internal1_m2027_tx};
_S_or2  S_or2_2025_1 = {&var170,&var1038,&var132};
_S_or2  S_or2_2028_1 = {&var1239,&var131,&var133};
_S_noto  S_noto_1690_1 = {&B2IS21LDU,&var134};
_S_noto  S_noto_1688_1 = {&A2IS21LDU,&var135};
_S_and2  S_and2_2099_1 = {&syn_B3VP52LDU,&var484,&var136};
_S_or5  S_or5_2102_1 = {&var659,&var1649,&var153,&var109,&var136,&var137};
_S_or5  S_or5_2101_1 = {&var410,&var1201,&var486,&var1649,&syn_A3VP52LDU,&var138};
_S_and2  S_and2_2076_1 = {&syn_A3VP52LDU,&var485,&var139};
_S_nocnm  S_nocnm_1734_1 = {&R5IS21LDU,&R5IS11LDU,&var140,&var141,&var142,&internal1_m1734_Pv0,&internal1_m1734_Zv0,&internal1_m1734_MyFirstEnterFlag,&bFirstEnterFlag};
_S_nocnm  S_nocnm_1731_1 = {&R3IS11LDU,&R3IS21LDU,&var143,&var144,&var145,&internal1_m1731_Pv0,&internal1_m1731_Zv0,&internal1_m1731_MyFirstEnterFlag,&bFirstEnterFlag};
_S_or5  S_or5_1996_1 = {&var1001,&var709,&C2MD31LP1,&var1000,&var999,&var146};
_S_or4  S_or4_1972_1 = {&C1MD31LP2,&C1MD31LP1,&var736,&var756,&var147};
_S_and3  S_and3_427_1 = {&B8IS22LDU,&B8IS21LDU,&var1622,&var148};
_S_and2  S_and2_2065_1 = {&var478,&var178,&var149};
_S_and2  S_and2_2073_1 = {&var481,&var178,&var150};
_S_or4  S_or4_994_1 = {&var1328,&var671,&var670,&var673,&var151};
_S_or4  S_or4_1406_1 = {&var1296,&var652,&var653,&var656,&var152};
_S_and2  S_and2_2103_1 = {&var399,&var1192,&var153};
_S_and2  S_and2_2088_1 = {&var484,&var1649,&var154};
_S_and2  S_and2_2077_1 = {&var485,&var1649,&var155};
_S_or2  S_or2_566_1 = {&B1VP41LZ2,&B1VP41LZ1,&var156};
_S_or2  S_or2_249_1 = {&A1VP41LZ2,&A1VP41LZ1,&var157};
_S_or2  S_or2_1130_1 = {&B8IS22LDU,&B8IS21LDU,&var158};
_S_or2  S_or2_1123_1 = {&B8IS11LDU,&B8IS12LDU,&var159};
_S_or2  S_or2_368_1 = {&R4IS11LDU,&R4IS12LDU,&var160};
_S_or2  S_or2_385_1 = {&R4IS21LDU,&R4IS22LDU,&var161};
_S_or2  S_or2_1082_1 = {&var1008,&R0MD34LP1,&var162};
_S_or2  S_or2_1085_1 = {&var1006,&R0MD34LP1,&var163};
_S_or2  S_or2_1088_1 = {&var1004,&R0MD34LP1,&var164};
_S_or2  S_or2_1091_1 = {&var1002,&R0MD34LP1,&var165};
_S_noto  S_noto_2213_1 = {&var1649,&var166};
_S_zzfs  S_zzfs_2202_1 = {&var184,&fRM_0_5,&var167,&internal1_m2202_tx,&internal1_m2202_y0};
_S_or2  S_or2_2236_1 = {&var360,&var1010,&var168};
_S_andn  S_andn_606_1 = {array_m606_x_1,&iRM_6_,&var169};
_S_andn  S_andn_605_1 = {array_m605_x_1,&iRM_6_,&var170};
_S_or2  S_or2_2250_1 = {&var686,&var651,&var171};
_S_noto  S_noto_2198_1 = {&var1036,&var172};
_S_noto  S_noto_2197_1 = {&var1033,&var173};
_S_zpfs  S_zpfs_2206_1 = {&var172,&fRM_30_0,&var174,&internal1_m2206_tx,&internal1_m2206_y0};
_S_noto  S_noto_2211_1 = {&var174,&var175};
_S_zpfs  S_zpfs_2205_1 = {&var173,&fRM_30_0,&var176,&internal1_m2205_tx,&internal1_m2205_y0};
_S_noto  S_noto_2210_1 = {&var176,&var177};
_S_and3  S_and3_2204_1 = {&var217,&var197,&lRM_1_,&var178};
_S_and2  S_and2_923_1 = {&var1354,&var180,&var179};
_S_noto  S_noto_909_1 = {&var167,&var180};
_S_and2  S_and2_1337_1 = {&var1322,&var182,&var181};
_S_noto  S_noto_1334_1 = {&var167,&var182};
_S_or2  S_or2_2246_1 = {&var193,&var194,&var183};
_S_and2  S_and2_2201_1 = {&var185,&var178,&var184};
_S_abs_subf  S_abs_subf_2193_1 = {&var1736,&var218,&fEM_A3UC08RDU,&vainSFloat,&var185};
_S_and2  S_and2_2248_1 = {&var178,&var193,&var186};
_S_or4  S_or4_1997_1 = {&var146,&var814,&var924,&var186,&var187};
_S_noto  S_noto_2249_1 = {&var171,&var188};
_S_or2  S_or2_2227_1 = {&var211,&var222,&var189};
_S_inf  S_inf_2221_1 = {&var220,array_m2221_a_1,array_m2221_b_1,&iRM_6_,&var190,&vainSInt};
_S_or3  S_or3_2254_1 = {&var207,&var214,&var215,&var191};
_S_noto  S_noto_2253_1 = {&var191,&var192};
_S_noto  S_noto_2247_1 = {&var217,&var193};
_S_ovbs  S_ovbs_2242_1 = {&var196,&fRM_15_0,&var194,&internal1_m2242_tx};
_S_zpfs  S_zpfs_2240_1 = {&var197,&fRM_10_0,&var195,&internal1_m2240_tx,&internal1_m2240_y0};
_S_and2  S_and2_2241_1 = {&var195,&R0MW17LP1,&var196};
_S_rs  S_rs_2245_1 = {&var183,&R0MW17LP1,&var197,&vainSBool,&internal1_m2245_q0};
_S_rs  S_rs_2212_1 = {&var211,&var178,&var198,&vainSBool,&internal1_m2212_q0};
_S_and3  S_and3_2219_1 = {&var213,&var166,&var198,&var199};
_S_ml  S_ml_1314_1 = {&var218,&var320,&var167,&var200};
_S_ml  S_ml_898_1 = {&var218,&var324,&var167,&var201};
_S_and2  S_and2_2266_1 = {&var178,&var337,&var202};
_S_noto  S_noto_2233_1 = {&var168,&var203};
_S_noto  S_noto_2217_1 = {&var1293,&var204};
_S_sr  S_sr_2234_1 = {array_m2234_x_1,&iRM_4_,&var205};
_S_sr  S_sr_2256_1 = {array_m2256_x_1,&iRM_2_,&var206};
_S_and2  S_and2_2270_1 = {&var208,&var178,&var207};
_S_abs_subf  S_abs_subf_2265_1 = {&B3MC01RP1,&A3MC01RP1,&fRM_0_01,&vainSFloat,&var208};
_S_fsumo  S_fsumo_86_1 = {&var986,&fEM_R0UN11RDU,&var209};
_S_or3  S_or3_132_1 = {&var147,&var67,&var189,&var210};
_S_ovbs  S_ovbs_2220_1 = {&var199,&fRM_1_0,&var211,&internal1_m2220_tx};
_S_noto  S_noto_2226_1 = {&var189,&var212};
_S_rs  S_rs_2218_1 = {&var211,&var1649,&var213,&vainSBool,&internal1_m2218_q0};
_S_and2  S_and2_2269_1 = {&var222,&var178,&var214};
_S_and2  S_and2_2268_1 = {&var216,&var178,&var215};
_S_bol  S_bol_2258_1 = {&fEM_R0UN09RDU,&var206,&var216};
_S_andn  S_andn_2225_1 = {array_m2225_x_1,&iRM_14_,&var217};
_S_irm  S_irm_2200_1 = {&var986,&var984,&B3MC01RP1,&var1736,&var206,&var205,&var178,&var1010,&fEM_R0UN12RDU,&fEM_R0UN13RDU,&fEM_R0UN14RDU,&fEM_R0UT20RDU,&var190,&fEM_R0UN15RDU,&fEM_R0UN25RDU,&fEM_R0UN16RDU,&fEM_R0UN17RDU,&fEM_R0UN18RDU,&fEM_R0UN19RDU,&fEM_R0UN27RDU,&fEM_R0UN26RDU,&fEM_R0UN24RDU,&var218,&var219,&var220,&var221,&var222,&var223,&var224,&var225};
_S_noto  S_noto_2054_1 = {&var348,&var226};
_S_noto  S_noto_2024_1 = {&var349,&var227};
_S_and4  S_and4_2047_1 = {&var371,&var128,&var341,&var226,&var228};
_S_and4  S_and4_2026_1 = {&var372,&var132,&var341,&var227,&var229};
_S_zpfs  S_zpfs_2042_1 = {&var355,&fRM_210_0,&var230,&internal1_m2042_tx,&internal1_m2042_y0};
_S_zpfs  S_zpfs_2034_1 = {&var356,&fRM_210_0,&var231,&internal1_m2034_tx,&internal1_m2034_y0};
_S_and2  S_and2_569_1 = {&var1369,&var404,&var232};
_S_and2  S_and2_252_1 = {&var404,&var1402,&var233};
_S_noto  S_noto_1573_1 = {&var235,&var234};
_S_abs_subf  S_abs_subf_1565_1 = {&var1733,&var320,&fEM_A3UC07RDU,&vainSFloat,&var235};
_S_noto  S_noto_1555_1 = {&var237,&var236};
_S_abs_subf  S_abs_subf_1546_1 = {&var324,&var1736,&fEM_A3UC07RDU,&vainSFloat,&var237};
_S_noto  S_noto_1569_1 = {&var239,&var238};
_S_abs_subf  S_abs_subf_1563_1 = {&var328,&var1746,&fEM_A1UC07RDU,&vainSFloat,&var239};
_S_noto  S_noto_1550_1 = {&var241,&var240};
_S_abs_subf  S_abs_subf_1543_1 = {&var332,&var1724,&fEM_A1UC07RDU,&vainSFloat,&var241};
_S_bol  S_bol_1333_1 = {&var1733,&fEM_A3UC09RDU,&var242};
_S_bol  S_bol_919_1 = {&var1736,&fEM_A3UC09RDU,&var243};
_S_noto  S_noto_1797_1 = {&var248,&var244};
_S_noto  S_noto_1786_1 = {&var246,&var245};
_S_and3  S_and3_1779_1 = {&var918,&var247,&var1210,&var246};
_S_bol  S_bol_1771_1 = {&fRM_55_0,&var320,&var247};
_S_and3  S_and3_1798_1 = {&var249,&var917,&var1210,&var248};
_S_bol  S_bol_1807_1 = {&fRM_55_0,&var324,&var249};
_S_and4  S_and4_51_1 = {&var1640,&var916,&var1095,&var1192,&var250};
_S_noto  S_noto_1248_1 = {&var966,&var251};
_S_and2  S_and2_1254_1 = {&var1469,&var966,&var252};
_S_and2  S_and2_1249_1 = {&var1469,&var251,&var253};
_S_noto  S_noto_1195_1 = {&var966,&var254};
_S_and2  S_and2_1203_1 = {&var966,&var1543,&var255};
_S_and2  S_and2_1196_1 = {&var1543,&var254,&var256};
_S_noto  S_noto_928_1 = {&var966,&var257};
_S_and2  S_and2_929_1 = {&var257,&var1325,&var258};
_S_and2  S_and2_925_1 = {&var1325,&var966,&var259};
_S_noto  S_noto_482_1 = {&var966,&var260};
_S_and2  S_and2_483_1 = {&var260,&var1418,&var261};
_S_and2  S_and2_484_1 = {&var1418,&var966,&var262};
_S_noto  S_noto_207_1 = {&var966,&var263};
_S_and2  S_and2_208_1 = {&var263,&var1388,&var264};
_S_and2  S_and2_210_1 = {&var966,&var1388,&var265};
_S_and2  S_and2_127_1 = {&var268,&var393,&var266};
_S_and2  S_and2_128_1 = {&var966,&var393,&var267};
_S_noto  S_noto_122_1 = {&var966,&var268};
_S_and2  S_and2_123_1 = {&var268,&var392,&var269};
_S_and2  S_and2_124_1 = {&var966,&var392,&var270};
_S_and2  S_and2_1644_1 = {&var306,&var1214,&var271};
_S_and2  S_and2_1643_1 = {&var309,&var1214,&var272};
_S_and2  S_and2_1642_1 = {&var307,&var1214,&var273};
_S_and2  S_and2_1641_1 = {&var1214,&var310,&var274};
_S_and2  S_and2_1640_1 = {&var527,&var308,&var275};
_S_and2  S_and2_1639_1 = {&var527,&var311,&var276};
_S_and2  S_and2_1638_1 = {&var528,&var308,&var277};
_S_and2  S_and2_1637_1 = {&var528,&var311,&var278};
_S_and2  S_and2_1670_1 = {&var39,&var1171,&var279};
_S_and2  S_and2_1669_1 = {&var306,&var1215,&var280};
_S_and2  S_and2_1668_1 = {&var1172,&var306,&var281};
_S_and2  S_and2_1667_1 = {&var1215,&var309,&var282};
_S_and2  S_and2_1666_1 = {&var135,&var1173,&var283};
_S_and2  S_and2_1665_1 = {&var1215,&var307,&var284};
_S_and2  S_and2_1664_1 = {&var1174,&var252,&var285};
_S_and2  S_and2_1663_1 = {&var1215,&var310,&var286};
_S_and2  S_and2_1703_1 = {&var252,&var1175,&var287};
_S_and2  S_and2_1702_1 = {&var308,&var1213,&var288};
_S_and2  S_and2_1700_1 = {&var1176,&var255,&var289};
_S_and2  S_and2_1699_1 = {&var1177,&var255,&var290};
_S_and2  S_and2_1698_1 = {&var311,&var1213,&var291};
_S_rs  S_rs_1720_1 = {&var41,&var293,&var292,&vainSBool,&internal1_m1720_q0};
_S_and2  S_and2_1719_1 = {&var1211,&var306,&var293};
_S_and2  S_and2_1718_1 = {&var1211,&var309,&var294};
_S_rs  S_rs_1725_1 = {&var62,&var294,&var295,&vainSBool,&internal1_m1725_q0};
_S_rs  S_rs_1717_1 = {&var42,&var297,&var296,&vainSBool,&internal1_m1717_q0};
_S_and2  S_and2_1716_1 = {&var307,&var1211,&var297};
_S_and2  S_and2_1715_1 = {&var1211,&var310,&var298};
_S_and2  S_and2_1748_1 = {&var308,&var1642,&var299};
_S_rs  S_rs_1759_1 = {&var262,&var299,&var300,&vainSBool,&internal1_m1759_q0};
_S_and2  S_and2_1747_1 = {&var1642,&var311,&var301};
_S_and2  S_and2_1745_1 = {&var306,&var1199,&var302};
_S_and2  S_and2_1744_1 = {&var1199,&var309,&var303};
_S_and2  S_and2_1742_1 = {&var307,&var1199,&var304};
_S_and2  S_and2_1741_1 = {&var1199,&var310,&var305};
_S_and2  S_and2_1761_1 = {&var918,&var308,&var306};
_S_and2  S_and2_1740_1 = {&var917,&var308,&var307};
_S_and2  S_and2_1763_1 = {&var267,&var1255,&var308};
_S_and2  S_and2_1760_1 = {&var311,&var918,&var309};
_S_and2  S_and2_1739_1 = {&var311,&var917,&var310};
_S_and2  S_and2_1762_1 = {&var270,&var1255,&var311};
_S_zpfs  S_zpfs_759_1 = {&var882,&fRM_3_,&var312,&internal1_m759_tx,&internal1_m759_y0};
_S_or4  S_or4_1584_1 = {&var518,&var519,&var520,&var522,&var313};
_S_or5  S_or5_1575_1 = {&var526,&var525,&var524,&var523,&var313,&var314};
_S_andn  S_andn_1_1 = {array_m1_x_1,&iRM_47_,&vainSBool};
_S_or2  S_or2_1557_1 = {&var317,&var318,&var315};
_S_ml  S_ml_1542_1 = {&fRM_1500_0,&B8MC01RP2,&var315,&var316};
_S_bol  S_bol_1547_1 = {&B8MC01RP2,&fRM_1500_0001,&var317};
_S_bol  S_bol_1558_1 = {&fRM_389_99,&B8MC01RP2,&var318};
_S_or2  S_or2_1571_1 = {&var321,&var322,&var319};
_S_ml  S_ml_1562_1 = {&fRM_0_0,&B3MC01RP1,&var319,&var320};
_S_bol  S_bol_1564_1 = {&B3MC01RP1,&fRM_160_00001,&var321};
_S_bol  S_bol_1572_1 = {&fRM_0_0001,&B3MC01RP1,&var322};
_S_or2  S_or2_1552_1 = {&var325,&var326,&var323};
_S_ml  S_ml_1540_1 = {&fRM_0_0,&A3MC01RP1,&var323,&var324};
_S_bol  S_bol_1545_1 = {&A3MC01RP1,&fRM_160_0001,&var325};
_S_bol  S_bol_1554_1 = {&fRM_0_0001,&A3MC01RP1,&var326};
_S_or2  S_or2_1568_1 = {&var329,&var330,&var327};
_S_ml  S_ml_1560_1 = {&fRM_100_0,&B1MC01RP1,&var327,&var328};
_S_bol  S_bol_1566_1 = {&B1MC01RP1,&fRM_100_0001,&var329};
_S_bol  S_bol_1574_1 = {&fRM_0_0001,&B1MC01RP1,&var330};
_S_or2  S_or2_1549_1 = {&var333,&var334,&var331};
_S_ml  S_ml_1538_1 = {&fRM_100_0,&A1MC01RP1,&var331,&var332};
_S_bol  S_bol_1544_1 = {&A1MC01RP1,&fRM_100_0001,&var333};
_S_bol  S_bol_1553_1 = {&fRM_0_0001,&A1MC01RP1,&var334};
_S_and2  S_and2_108_1 = {&var73,&var160,&var335};
_S_noto  S_noto_109_1 = {&var160,&var336};
_S_and2  S_and2_112_1 = {&var73,&var336,&var337};
_S_and2  S_and2_2013_1 = {&var339,&var340,&var338};
_S_or3  S_or3_2012_1 = {&var1217,&var471,&var187,&var339};
_S_noto  S_noto_2050_1 = {&var130,&var340};
_S_noto  S_noto_2039_1 = {&var342,&var341};
_S_ovbs  S_ovbs_2038_1 = {&var1107,&fRM_2_0,&var342,&internal1_m2038_tx};
_S_noto  S_noto_2029_1 = {&var133,&var343};
_S_and2  S_and2_1999_1 = {&var345,&var343,&var344};
_S_or3  S_or3_1998_1 = {&var187,&var1221,&var471,&var345};
_S_noto  S_noto_2044_1 = {&var353,&var346};
_S_and2  S_and2_2045_1 = {&var1192,&var346,&var347};
_S_and2  S_and2_2053_1 = {&var347,&var128,&var348};
_S_and2  S_and2_2032_1 = {&var350,&var132,&var349};
_S_and2  S_and2_2037_1 = {&var351,&var1192,&var350};
_S_noto  S_noto_2036_1 = {&var909,&var351};
_S_noto  S_noto_2052_1 = {&var355,&var352};
_S_or2  S_or2_2043_1 = {&var230,&var352,&var353};
_S_noto  S_noto_2031_1 = {&var356,&var354};
_S_rs  S_rs_2041_1 = {&var230,&var361,&var355,&vainSBool,&internal1_m2041_q0};
_S_rs  S_rs_2033_1 = {&var231,&var362,&var356,&vainSBool,&internal1_m2033_q0};
_S_and2  S_and2_2022_1 = {&var359,&var366,&var357};
_S_and2  S_and2_2010_1 = {&var359,&var363,&var358};
_S_noto  S_noto_2004_1 = {&var360,&var359};
_S_ovbs  S_ovbs_2003_1 = {&var187,&fRM_10_0,&var360,&internal1_m2003_tx};
_S_ovbs  S_ovbs_2014_1 = {&var338,&fRM_2_0,&var361,&internal1_m2014_tx};
_S_ovbs  S_ovbs_2000_1 = {&var344,&fRM_2_0,&var362,&internal1_m2000_tx};
_S_or2  S_or2_2009_1 = {&var394,&var971,&var363};
_S_or2  S_or2_2005_1 = {&var395,&var344,&var364};
_S_or2  S_or2_2017_1 = {&var395,&var338,&var365};
_S_or2  S_or2_2021_1 = {&var394,&var968,&var366};
_S_rs  S_rs_2006_1 = {&var358,&var364,&var367,&vainSBool,&internal1_m2006_q0};
_S_noto  S_noto_2019_1 = {&var369,&var368};
_S_rs  S_rs_2018_1 = {&var357,&var365,&var369,&vainSBool,&internal1_m2018_q0};
_S_noto  S_noto_2007_1 = {&var367,&var370};
_S_noto  S_noto_2015_1 = {&var361,&var371};
_S_noto  S_noto_2001_1 = {&var362,&var372};
_S_and2  S_and2_1994_1 = {&var375,&var477,&var373};
_S_and2  S_and2_1983_1 = {&var375,&var474,&var374};
_S_noto  S_noto_1977_1 = {&var376,&var375};
_S_ovbs  S_ovbs_1976_1 = {&var147,&fRM_3_0,&var376,&internal1_m1976_tx};
_S_or2  S_or2_1496_1 = {&var1141,&lRM_0_,&var377};
_S_and2  S_and2_452_1 = {&var1614,&var1556,&var378};
_S_and2  S_and2_1861_1 = {&var1166,&var6,&var379};
_S_and2  S_and2_463_1 = {&var917,&var763,&var380};
_S_and2  S_and2_455_1 = {&var764,&var917,&var381};
_S_and2  S_and2_492_1 = {&var763,&var918,&var382};
_S_and2  S_and2_488_1 = {&var764,&var918,&var383};
_S_or2  S_or2_379_1 = {&var1627,&var889,&var384};
_S_or2  S_or2_375_1 = {&var1627,&var888,&var385};
_S_ovbs  S_ovbs_57_1 = {&var1639,&fRM_15_0,&var386,&internal1_m57_tx};
_S_ovbs  S_ovbs_356_1 = {&var1114,&fRM_0_02,&var387,&internal1_m356_tx};
_S_ovbs  S_ovbs_312_1 = {&var1116,&fRM_0_02,&var388,&internal1_m312_tx};
_S_ovbs  S_ovbs_760_1 = {&var312,&fRM_0_2,&var389,&internal1_m760_tx};
_S_ovbs  S_ovbs_1440_1 = {&R0MD31LP1,&fRM_10_0,&var390,&internal1_m1440_tx};
_S_ovbs  S_ovbs_119_1 = {&R0MD31LP1,&fRM_0_15,&var391,&internal1_m119_tx};
_S_ovbs  S_ovbs_121_1 = {&var337,&fRM_0_02,&var392,&internal1_m121_tx};
_S_ovbs  S_ovbs_126_1 = {&R0MD32LP1,&fRM_0_02,&var393,&internal1_m126_tx};
_S_ovbs  S_ovbs_24_1 = {&var1192,&fRM_3_0,&var394,&internal1_m24_tx};
_S_ovbs  S_ovbs_16_1 = {&var966,&fRM_3_0,&var395,&internal1_m16_tx};
_S_ovbs  S_ovbs_1985_1 = {&var147,&fRM_2_0,&var396,&internal1_m1985_tx};
_S_ovbs  S_ovbs_1973_1 = {&var147,&fRM_2_0,&var397,&internal1_m1973_tx};
_S_ovbs  S_ovbs_2081_1 = {&var1201,&fRM_2_0,&var398,&internal1_m2081_tx};
_S_ovbs  S_ovbs_2085_1 = {&var109,&fRM_2_0,&var399,&internal1_m2085_tx};
_S_ovbs  S_ovbs_1898_1 = {&var412,&fRM_0_01,&var400,&internal1_m1898_tx};
_S_ovbs  S_ovbs_83_1 = {&R0MW13LP2,&fRM_10_0,&var401,&internal1_m83_tx};
_S_zpfs  S_zpfs_325_1 = {&var820,&fRM_10_0,&var402,&internal1_m325_tx,&internal1_m325_y0};
_S_or2  S_or2_1041_1 = {&var1027,&var590,&var403};
_S_or2  S_or2_253_1 = {&A1VN71LZ1,&A1VN71LZ2,&var404};
_S_or2  S_or2_268_1 = {&var715,&var983,&var405};
_S_or5  S_or5_154_1 = {&B1IS21LDU,&B3IS21LDU,&B2IS21LDU,&var953,&var954,&var406};
_S_and2  S_and2_1038_1 = {&var1464,&var1098,&var407};
_S_or3  S_or3_996_1 = {&var151,&var675,&var674,&var408};
_S_or3  S_or3_1408_1 = {&var658,&var657,&var152,&var409};
_S_and2  S_and2_977_1 = {&var1229,&var1012,&var410};
_S_and3  S_and3_1893_1 = {&var428,&var413,&var421,&var411};
_S_or2  S_or2_1897_1 = {&var415,&var414,&var412};
_S_or3  S_or3_1895_1 = {&var415,&var414,&var424,&var413};
_S_zpfs  S_zpfs_1892_1 = {&var417,&fEM_R0UL02RDU,&var414,&internal1_m1892_tx,&internal1_m1892_y0};
_S_zpfs  S_zpfs_1890_1 = {&var418,&fEM_R0UL02RDU,&var415,&internal1_m1890_tx,&internal1_m1890_y0};
_S_or2  S_or2_1884_1 = {&var418,&var417,&var416};
_S_or2  S_or2_1885_1 = {&var419,&var1131,&var417};
_S_or2  S_or2_1883_1 = {&var420,&var1131,&var418};
_S_and3  S_and3_1877_1 = {&var1188,&var940,&var918,&var419};
_S_and3  S_and3_1876_1 = {&var1189,&var917,&var940,&var420};
_S_or2  S_or2_1874_1 = {&var1131,&var1130,&var421};
_S_or3  S_or3_1881_1 = {&var426,&var1130,&var424,&var422};
_S_and2  S_and2_1889_1 = {&var1131,&var413,&var423};
_S_and2  S_and2_1880_1 = {&var1122,&var425,&var424};
_S_zpfs  S_zpfs_1879_1 = {&var1131,&fEM_R0UL04RDU,&var425,&internal1_m1879_tx,&internal1_m1879_y0};
_S_and2  S_and2_1867_1 = {&var1125,&var574,&var426};
_S_or3  S_or3_1868_1 = {&var1079,&var580,&var1057,&var427};
_S_abs_subf  S_abs_subf_1901_1 = {&fEM_R0UL02RDU,&var429,&fEM_R0UL16RDU,&vainSFloat,&var428};
_S_rsfn  S_rsfn_1899_1 = {&var571,&var430,&var429,&internal1_m1899_q0};
_S_lk  S_lk_1896_1 = {&var1284,&var413,&var430};
_S_abs_subf  S_abs_subf_1469_1 = {&fEM_R0UL05RDU,&var432,&fEM_R0UL18RDU,&vainSFloat,&var431};
_S_rsfn  S_rsfn_1460_1 = {&var571,&var433,&var432,&internal1_m1460_q0};
_S_lk  S_lk_1464_1 = {&var1136,&var558,&var433};
_S_abs_subf  S_abs_subf_1511_1 = {&fEM_R0UL07RDU,&var435,&fEM_R0UL20RDU,&vainSFloat,&var434};
_S_rsfn  S_rsfn_1499_1 = {&var571,&var436,&var435,&internal1_m1499_q0};
_S_lk  S_lk_1502_1 = {&var1142,&var548,&var436};
_S_ma  S_ma_1481_1 = {array_m1481_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_abs_subf  S_abs_subf_1516_1 = {&fEM_R0UL25RDU,&var438,&fEM_R0UL19RDU,&vainSFloat,&var437};
_S_rsfn  S_rsfn_1497_1 = {&var571,&var439,&var438,&internal1_m1497_q0};
_S_lk  S_lk_1505_1 = {&var1282,&var539,&var439};
_S_and3  S_and3_1943_1 = {&var441,&var444,&var451,&var440};
_S_abs_subf  S_abs_subf_1940_1 = {&var442,&fEM_R0UL03RDU,&fEM_R0UL17RDU,&vainSFloat,&var441};
_S_rsfn  S_rsfn_1938_1 = {&var571,&var443,&var442,&internal1_m1938_q0};
_S_lk  S_lk_1934_1 = {&var1283,&var444,&var443};
_S_or3  S_or3_1933_1 = {&var449,&var455,&var454,&var444};
_S_and4  S_and4_1937_1 = {&var454,&var1289,&var467,&var465,&var445};
_S_and4  S_and4_1935_1 = {&var455,&var1289,&var467,&var465,&var446};
_S_and2  S_and2_1927_1 = {&var1134,&var444,&var447};
_S_and2  S_and2_1913_1 = {&var574,&var1124,&var448};
_S_and2  S_and2_1917_1 = {&var452,&var1123,&var449};
_S_or3  S_or3_1918_1 = {&var449,&var448,&var1133,&var450};
_S_or2  S_or2_1909_1 = {&var1134,&var1133,&var451};
_S_zpfs  S_zpfs_1916_1 = {&var1134,&fEM_R0UL21RDU,&var452,&internal1_m1916_tx,&internal1_m1916_y0};
_S_or3  S_or3_1906_1 = {&var576,&var1083,&var1061,&var453};
_S_zpfs  S_zpfs_1931_1 = {&var457,&fEM_R0UL03RDU,&var454,&internal1_m1931_tx,&internal1_m1931_y0};
_S_zpfs  S_zpfs_1928_1 = {&var458,&fEM_R0UL03RDU,&var455,&internal1_m1928_tx,&internal1_m1928_y0};
_S_or2  S_or2_1924_1 = {&var458,&var457,&var456};
_S_or2  S_or2_1925_1 = {&var459,&var1134,&var457};
_S_or2  S_or2_1923_1 = {&var460,&var1134,&var458};
_S_and4  S_and4_1921_1 = {&var1190,&var918,&B2IS12LDU,&var461,&var459};
_S_and4  S_and4_1915_1 = {&var1191,&A2IS12LDU,&var917,&var461,&var460};
_S_and2  S_and2_1914_1 = {&var940,&var465,&var461};
_S_and3  S_and3_1952_1 = {&var918,&var1045,&var464,&var462};
_S_and3  S_and3_1951_1 = {&var917,&var1046,&var464,&var463};
_S_and4  S_and4_1950_1 = {&var1011,&var810,&var812,&var465,&var464};
_S_and2  S_and2_1944_1 = {&var823,&var1012,&var465};
_S_or2  S_or2_1946_1 = {&var1293,&var1010,&var466};
_S_or3  S_or3_1955_1 = {&var470,&var469,&var472,&var467};
_S_and2  S_and2_1945_1 = {&var1049,&A2IS12LDU,&var468};
_S_and2  S_and2_1949_1 = {&var950,&var468,&var469};
_S_and3  S_and3_1954_1 = {&var1288,&var473,&var468,&var470};
_S_or2  S_or2_1963_1 = {&lRM_0_,&var466,&var471};
_S_and2  S_and2_1960_1 = {&var965,&var473,&var472};
_S_and2  S_and2_1962_1 = {&var1048,&B2IS12LDU,&var473};
_S_or2  S_or2_1982_1 = {&var970,&var394,&var474};
_S_or2  S_or2_1978_1 = {&var395,&var147,&var475};
_S_or2  S_or2_1989_1 = {&var147,&var395,&var476};
_S_or2  S_or2_1993_1 = {&var394,&var969,&var477};
_S_or2  S_or2_2056_1 = {&var818,&var1202,&var478};
_S_or2  S_or2_2062_1 = {&var1012,&var1223,&var479};
_S_zpfs  S_zpfs_2064_1 = {&var78,&fRM_15_0,&var480,&internal1_m2064_tx,&internal1_m2064_y0};
_S_or2  S_or2_2068_1 = {&var817,&var110,&var481};
_S_zpfs  S_zpfs_2075_1 = {&var76,&fRM_15_0,&var482,&internal1_m2075_tx,&internal1_m2075_y0};
_S_or2  S_or2_2078_1 = {&var1012,&var1222,&var483};
_S_or2  S_or2_2094_1 = {&var82,&var445,&var484};
_S_or2  S_or2_2089_1 = {&var446,&var86,&var485};
_S_and2  S_and2_2100_1 = {&var1192,&var398,&var486};
_S_and2  S_and2_1860_1 = {&var1167,&var7,&var487};
_S_or3  S_or3_1832_1 = {&var492,&var496,&var494,&var488};
_S_or3  S_or3_1836_1 = {&var495,&var494,&var491,&var489};
_S_or2  S_or2_1846_1 = {&B0VT71LZ1,&B0VT71LZ2,&var490};
_S_and2  S_and2_1837_1 = {&var497,&var490,&var491};
_S_and2  S_and2_1831_1 = {&var497,&var493,&var492};
_S_or2  S_or2_1830_1 = {&A0VT71LZ1,&A0VT71LZ2,&var493};
_S_zpfs  S_zpfs_1827_1 = {&var1184,&fRM_2_5,&var494,&internal1_m1827_tx,&internal1_m1827_y0};
_S_zpfs  S_zpfs_1826_1 = {&var1185,&fRM_2_5,&var495,&internal1_m1826_tx,&internal1_m1826_y0};
_S_zpfs  S_zpfs_1825_1 = {&var1186,&fRM_2_5,&var496,&internal1_m1825_tx,&internal1_m1825_y0};
_S_zpfs  S_zpfs_1824_1 = {&var1187,&fRM_2_5,&var497,&internal1_m1824_tx,&internal1_m1824_y0};
_S_or2  S_or2_1855_1 = {&R0VP73LZ2,&R0VP73LZ1,&var498};
_S_and2  S_and2_1850_1 = {&var109,&var1168,&var499};
_S_or2  S_or2_1845_1 = {&var502,&var499,&var500};
_S_or2  S_or2_1847_1 = {&var82,&var109,&var501};
_S_and2  S_and2_1844_1 = {&var82,&var1158,&var502};
_S_and2  S_and2_1828_1 = {&var1201,&var1169,&var503};
_S_or2  S_or2_1829_1 = {&var506,&var503,&var504};
_S_or2  S_or2_1822_1 = {&var86,&var1201,&var505};
_S_and2  S_and2_1821_1 = {&var86,&var1159,&var506};
_S_or3  S_or3_1791_1 = {&var1252,&var1210,&var1211,&var507};
_S_or3  S_or3_1792_1 = {&var1250,&var1210,&var1211,&var508};
_S_or2  S_or2_1783_1 = {&var1245,&var1210,&var509};
_S_or2  S_or2_1784_1 = {&var1244,&var1210,&var510};
_S_or2  S_or2_1790_1 = {&var1254,&var1213,&var511};
_S_or4  S_or4_1788_1 = {&var1213,&var1251,&var1214,&var1215,&var512};
_S_or4  S_or4_1787_1 = {&var1213,&var1257,&var1214,&var1215,&var513};
_S_or2  S_or2_1781_1 = {&var1246,&var1215,&var514};
_S_or2  S_or2_1780_1 = {&var1247,&var1215,&var515};
_S_or2  S_or2_1789_1 = {&var1213,&var1253,&var516};
_S_or2  S_or2_1758_1 = {&var262,&var308,&var517};
_S_and2  S_and2_1589_1 = {&var1507,&var1465,&var518};
_S_and2  S_and2_1588_1 = {&var1630,&var1465,&var519};
_S_and2  S_and2_1587_1 = {&var907,&var1465,&var520};
_S_or2  S_or2_1586_1 = {&B4IS11LDU,&A4IS11LDU,&var521};
_S_and2  S_and2_1585_1 = {&var521,&var1465,&var522};
_S_and2  S_and2_1579_1 = {&var1673,&var1465,&var523};
_S_and2  S_and2_1578_1 = {&var160,&var1465,&var524};
_S_and2  S_and2_1577_1 = {&var896,&var1465,&var525};
_S_and2  S_and2_1576_1 = {&R3IS21LDU,&var1465,&var526};
_S_or2  S_or2_1636_1 = {&var1643,&var1644,&var527};
_S_or2  S_or2_1635_1 = {&var1645,&var1643,&var528};
_S_or2  S_or2_2114_1 = {&var989,&R0MD34LP1,&var529};
_S_or3  S_or3_2120_1 = {&var1264,&var1266,&var1265,&var530};
_S_or3  S_or3_2111_1 = {&var1270,&var1272,&var1271,&var531};
_S_or2  S_or2_1624_1 = {&var1731,&var1465,&var532};
_S_or2  S_or2_1598_1 = {&var1508,&var1098,&var533};
_S_or5  S_or5_1135_1 = {&var1523,&var535,&var1534,&var1520,&var1521,&var534};
_S_or3  S_or3_1139_1 = {&var1528,&var1529,&var992,&var535};
_S_or5  S_or5_1612_1 = {&var314,&var537,&var1517,&var1509,&var1510,&var536};
_S_or3  S_or3_1615_1 = {&var991,&var1511,&var1512,&var537};
_S_and3  S_and3_1525_1 = {&var539,&var544,&var437,&var538};
_S_and2  S_and2_1528_1 = {&var540,&var1281,&var539};
_S_or3  S_or3_1527_1 = {&A3VZ13LZ2,&A3VZ13LZ1,&var543,&var540};
_S_zpfs  S_zpfs_1512_1 = {&var1281,&fRM_0_2,&var541,&internal1_m1512_tx,&internal1_m1512_y0};
_S_or3  S_or3_1514_1 = {&var1144,&var543,&var545,&var542};
_S_and2  S_and2_1513_1 = {&var1121,&var541,&var543};
_S_or2  S_or2_1503_1 = {&var1281,&var1144,&var544};
_S_and2  S_and2_1491_1 = {&var1126,&var574,&var545};
_S_or3  S_or3_1500_1 = {&var1058,&var1080,&var579,&var546};
_S_or3  S_or3_1521_1 = {&R0AD14LZ1,&R0AD14LZ2,&var550,&var547};
_S_and2  S_and2_1522_1 = {&var547,&var1141,&var548};
_S_zpfs  S_zpfs_1506_1 = {&var1141,&fEM_R0UL06RDU,&var549,&internal1_m1506_tx,&internal1_m1506_y0};
_S_and2  S_and2_1507_1 = {&var549,&var1120,&var550};
_S_or3  S_or3_1508_1 = {&var1139,&var550,&var553,&var551};
_S_or3  S_or3_1483_1 = {&var578,&var1081,&var1059,&var552};
_S_and2  S_and2_1486_1 = {&var1127,&var574,&var553};
_S_and3  S_and3_1524_1 = {&var434,&var548,&var561,&var554};
_S_zpfs  S_zpfs_1456_1 = {&var1138,&fEM_R0UL04RDU,&var555,&internal1_m1456_tx,&internal1_m1456_y0};
_S_and2  S_and2_1457_1 = {&var555,&var1119,&var556};
_S_and3  S_and3_1473_1 = {&var431,&var558,&var562,&var557};
_S_and2  S_and2_1467_1 = {&var559,&var1138,&var558};
_S_or3  S_or3_1466_1 = {&A3VZ15LZ1,&A3VZ15LZ2,&var556,&var559};
_S_or3  S_or3_1458_1 = {&var563,&var556,&var1137,&var560};
_S_or2  S_or2_1494_1 = {&var1141,&var1139,&var561};
_S_or2  S_or2_1454_1 = {&var1138,&var1137,&var562};
_S_and2  S_and2_1446_1 = {&var1128,&var574,&var563};
_S_or3  S_or3_1444_1 = {&var1060,&var1082,&var577,&var564};
_S_or2  S_or2_1418_1 = {&var1636,&var566,&var565};
_S_and2  S_and2_1417_1 = {&var567,&var1182,&var566};
_S_or2  S_or2_1416_1 = {&var963,&var915,&var567};
_S_or2  S_or2_1413_1 = {&var1053,&var1075,&var568};
_S_and2  S_and2_1411_1 = {&var1147,&var1148,&var569};
_S_and2  S_and2_1414_1 = {&var568,&var567,&var570};
_S_or5  S_or5_1415_1 = {&var388,&var387,&var569,&var570,&R0MD34LP1,&var571};
_S_orni  S_orni_1435_1 = {array_m1435_x_1,&iRM_5_,&var572,&var573};
_S_or5  S_or5_1437_1 = {&var1143,&var1118,&var571,&var1063,&var390,&var574};
_S_and2  S_and2_1436_1 = {&var572,&var1276,&var575};
_S_or2  S_or2_1443_1 = {&var1090,&var581,&var576};
_S_or2  S_or2_1439_1 = {&var1089,&var582,&var577};
_S_or2  S_or2_1433_1 = {&var1088,&var583,&var578};
_S_or2  S_or2_1431_1 = {&var1087,&var584,&var579};
_S_or2  S_or2_1429_1 = {&var1086,&var585,&var580};
_S_and2  S_and2_1442_1 = {&var1631,&var586,&var581};
_S_and2  S_and2_1438_1 = {&var1632,&var586,&var582};
_S_and2  S_and2_1432_1 = {&var1633,&var586,&var583};
_S_and2  S_and2_1430_1 = {&var1634,&var586,&var584};
_S_and2  S_and2_1428_1 = {&var1635,&var586,&var585};
_S_and2  S_and2_1422_1 = {&var1636,&var69,&var586};
_S_and3  S_and3_1071_1 = {&var256,&var591,&var609,&var587};
_S_or2  S_or2_1035_1 = {&var1100,&var1096,&var588};
_S_or2  S_or2_1062_1 = {&var1096,&var1030,&var589};
_S_and2  S_and2_1029_1 = {&var1474,&var1097,&var590};
_S_and2  S_and2_1025_1 = {&var1293,&var611,&var591};
_S_or3  S_or3_1032_1 = {&var1096,&var1026,&var1099,&var592};
_S_and2  S_and2_1036_1 = {&var253,&var1293,&var593};
_S_and2  S_and2_1054_1 = {&var264,&var1293,&var594};
_S_and2  S_and2_1070_1 = {&var258,&var1293,&var595};
_S_and2  S_and2_1077_1 = {&var261,&var1293,&var596};
_S_and3  S_and3_1020_1 = {&var599,&var1015,&var1293,&var597};
_S_and3  S_and3_1014_1 = {&var600,&var1015,&var1293,&var598};
_S_and2  S_and2_1022_1 = {&var917,&var1292,&var599};
_S_and2  S_and2_1012_1 = {&var918,&var1292,&var600};
_S_and4  S_and4_1021_1 = {&var599,&var1293,&var1023,&var1013,&var601};
_S_and4  S_and4_1015_1 = {&var600,&var1293,&var1023,&var1013,&var602};
_S_and4  S_and4_1019_1 = {&var1293,&var599,&var607,&var1014,&var603};
_S_and4  S_and4_1013_1 = {&var1293,&var600,&var607,&var1014,&var604};
_S_and2  S_and2_1006_1 = {&var1024,&var1293,&var605};
_S_or4  S_or4_1009_1 = {&R0MD31LP1,&var1527,&var269,&var618,&var606};
_S_and3  S_and3_1055_1 = {&var1025,&var1024,&var1023,&var607};
_S_and2  S_and2_1042_1 = {&var609,&var403,&var608};
_S_and2  S_and2_1045_1 = {&var1022,&var607,&var609};
_S_or2  S_or2_1056_1 = {&var1092,&var1034,&var610};
_S_and2  S_and2_1064_1 = {&var612,&var610,&var611};
_S_or2  S_or2_1057_1 = {&var1033,&var1035,&var612};
_S_or2  S_or2_1058_1 = {&var1032,&var1033,&var613};
_S_or2  S_or2_1060_1 = {&var1031,&var1036,&var614};
_S_and2  S_and2_1061_1 = {&var613,&var614,&var615};
_S_or2  S_or2_1048_1 = {&var1092,&var1091,&var616};
_S_and2  S_and2_1049_1 = {&var616,&var1028,&var617};
_S_and5  S_and5_1002_1 = {&var619,&var1112,&var1033,&var1092,&var608,&var618};
_S_and2  S_and2_1003_1 = {&var1067,&var1068,&var619};
_S_and2  S_and2_1265_1 = {&var1161,&var621,&var620};
_S_or2  S_or2_1260_1 = {&A2MD12LP1,&var622,&var621};
_S_and2  S_and2_1247_1 = {&A2MD11LP1,&var1178,&var622};
_S_or2  S_or2_1241_1 = {&var625,&B2MD12LP1,&var623};
_S_and2  S_and2_1243_1 = {&var623,&var1161,&var624};
_S_and2  S_and2_1235_1 = {&B2MD11LP1,&var1179,&var625};
_S_or3  S_or3_1223_1 = {&var1243,&var1238,&var781,&var626};
_S_or5  S_or5_1239_1 = {&var629,&var1001,&var1504,&var1498,&var1499,&var627};
_S_or2  S_or2_1258_1 = {&var1743,&var1489,&var628};
_S_or3  S_or3_1310_1 = {&var1470,&var630,&var631,&var629};
_S_and2  S_and2_1305_1 = {&var1489,&var964,&var630};
_S_and2  S_and2_1304_1 = {&var914,&var1489,&var631};
_S_and3  S_and3_1303_1 = {&var406,&var950,&var646,&var632};
_S_and2  S_and2_1302_1 = {&var160,&var646,&var633};
_S_and3  S_and3_1298_1 = {&var939,&var985,&var646,&var634};
_S_and2  S_and2_1297_1 = {&var498,&var646,&var635};
_S_and2  S_and2_1285_1 = {&var1480,&var646,&var636};
_S_and2  S_and2_1272_1 = {&var1673,&var646,&var637};
_S_and2  S_and2_1287_1 = {&var67,&var646,&var638};
_S_and2  S_and2_1273_1 = {&R3IS21LDU,&var646,&var639};
_S_and2  S_and2_1288_1 = {&var642,&var646,&var640};
_S_and3  S_and3_1274_1 = {&var643,&var1479,&var646,&var641};
_S_or2  S_or2_1289_1 = {&var1472,&var1473,&var642};
_S_or2  S_or2_1275_1 = {&A4IS11LDU,&B4IS11LDU,&var643};
_S_and3  S_and3_1284_1 = {&var1213,&var270,&var966,&var644};
_S_and3  S_and3_1283_1 = {&var1215,&var270,&var966,&var645};
_S_or3  S_or3_1277_1 = {&var1490,&var645,&var644,&var646};
_S_and2  S_and2_1362_1 = {&var648,&var1161,&var647};
_S_or2  S_or2_1358_1 = {&var649,&B3MD12LP1,&var648};
_S_and2  S_and2_1347_1 = {&B3MD11LP1,&var1157,&var649};
_S_or2  S_or2_1350_1 = {&var1734,&var1307,&var650};
_S_or5  S_or5_1336_1 = {&var409,&var1317,&var1316,&var181,&var999,&var651};
_S_and2  S_and2_1396_1 = {&var1307,&var964,&var652};
_S_and2  S_and2_1395_1 = {&var1307,&var914,&var653};
_S_and2  S_and2_1404_1 = {&var980,&var1295,&var654};
_S_or2  S_or2_1399_1 = {&var654,&var981,&var655};
_S_and3  S_and3_1394_1 = {&var1170,&var655,&var664,&var656};
_S_and3  S_and3_1393_1 = {&var406,&var965,&var664,&var657};
_S_and2  S_and2_1392_1 = {&var160,&var664,&var658};
_S_and2  S_and2_1389_1 = {&var1227,&var1012,&var659};
_S_or2  S_or2_1379_1 = {&var1298,&var1297,&var660};
_S_and2  S_and2_1378_1 = {&var660,&var664,&var661};
_S_and2  S_and2_1377_1 = {&var67,&var664,&var662};
_S_and2  S_and2_1375_1 = {&var1300,&var664,&var663};
_S_or2  S_or2_1367_1 = {&var1309,&var90,&var664};
_S_or2  S_or2_1368_1 = {&B4IS11LDU,&A4IS11LDU,&var665};
_S_and3  S_and3_1365_1 = {&var1299,&var665,&var664,&var666};
_S_and2  S_and2_1364_1 = {&R3IS21LDU,&var664,&var667};
_S_and2  S_and2_1363_1 = {&var1673,&var664,&var668};
_S_and2  S_and2_992_1 = {&var978,&var1327,&var669};
_S_and2  S_and2_983_1 = {&var914,&var1339,&var670};
_S_and2  S_and2_984_1 = {&var964,&var1339,&var671};
_S_or2  S_or2_987_1 = {&var979,&var669,&var672};
_S_and3  S_and3_982_1 = {&var1170,&var672,&var679,&var673};
_S_and3  S_and3_981_1 = {&var950,&var406,&var679,&var674};
_S_and2  S_and2_980_1 = {&var160,&var679,&var675};
_S_and2  S_and2_963_1 = {&var1332,&var679,&var676};
_S_or2  S_or2_967_1 = {&var1330,&var1329,&var677};
_S_and2  S_and2_966_1 = {&var677,&var679,&var678};
_S_or2  S_or2_955_1 = {&var1341,&var91,&var679};
_S_or2  S_or2_956_1 = {&B4IS11LDU,&A4IS11LDU,&var680};
_S_and3  S_and3_953_1 = {&var680,&var1331,&var679,&var681};
_S_and2  S_and2_965_1 = {&var67,&var679,&var682};
_S_and2  S_and2_952_1 = {&R3IS21LDU,&var679,&var683};
_S_and2  S_and2_951_1 = {&var1673,&var679,&var684};
_S_or2  S_or2_938_1 = {&var1339,&var1737,&var685};
_S_or5  S_or5_922_1 = {&var408,&var1000,&var179,&var1348,&var1349,&var686};
_S_and2  S_and2_948_1 = {&var1161,&var688,&var687};
_S_or2  S_or2_946_1 = {&var689,&A3MD12LP1,&var688};
_S_and2  S_and2_935_1 = {&A3MD11LP1,&var1212,&var689};
_S_or3  S_or3_893_1 = {&var1437,&var692,&var691,&var690};
_S_and2  S_and2_887_1 = {&var1448,&var914,&var691};
_S_and2  S_and2_888_1 = {&var1448,&var964,&var692};
_S_and3  S_and3_886_1 = {&var1471,&var965,&var704,&var693};
_S_and2  S_and2_885_1 = {&var160,&var704,&var694};
_S_and2  S_and2_868_1 = {&var1441,&var704,&var695};
_S_and2  S_and2_870_1 = {&var67,&var704,&var696};
_S_and2  S_and2_871_1 = {&var698,&var704,&var697};
_S_or2  S_or2_872_1 = {&var1439,&var1438,&var698};
_S_and2  S_and2_855_1 = {&var1673,&var704,&var699};
_S_and3  S_and3_857_1 = {&var1440,&var705,&var704,&var700};
_S_and2  S_and2_856_1 = {&R3IS21LDU,&var704,&var701};
_S_and3  S_and3_867_1 = {&var1213,&var270,&var966,&var702};
_S_and3  S_and3_866_1 = {&var270,&var1215,&var966,&var703};
_S_or3  S_or3_859_1 = {&var1449,&var702,&var703,&var704};
_S_or2  S_or2_860_1 = {&B4IS11LDU,&A4IS11LDU,&var705};
_S_or2  S_or2_845_1 = {&var1740,&var1448,&var706};
_S_zpfs  S_zpfs_842_1 = {&var1462,&fRM_3_0,&var707,&internal1_m842_tx,&internal1_m842_y0};
_S_zpfs  S_zpfs_840_1 = {&var1463,&fRM_2_0,&var708,&internal1_m840_tx,&internal1_m840_y0};
_S_zpfs  S_zpfs_847_1 = {&var1460,&fEM_A2UL83RDU,&var709,&internal1_m847_tx,&internal1_m847_y0};
_S_or5  S_or5_835_1 = {&var690,&var709,&var1461,&var708,&var707,&var710};
_S_or3  S_or3_825_1 = {&var1218,&var1241,&var776,&var711};
_S_or4  S_or4_808_1 = {&var1584,&var1582,&var1583,&var1585,&var712};
_S_or2  S_or2_799_1 = {&var714,&var712,&var713};
_S_or4  S_or4_792_1 = {&var1593,&var1592,&var1591,&var1594,&var714};
_S_and2  S_and2_273_1 = {&var982,&var1387,&var715};
_S_and3  S_and3_262_1 = {&var950,&var406,&var1402,&var716};
_S_or3  S_or3_275_1 = {&var720,&var718,&var1390,&var717};
_S_and2  S_and2_265_1 = {&var1401,&var964,&var718};
_S_and3  S_and3_263_1 = {&var405,&var1170,&var1402,&var719};
_S_and2  S_and2_264_1 = {&var914,&var1401,&var720};
_S_and2  S_and2_261_1 = {&var160,&var1402,&var721};
_S_and2  S_and2_236_1 = {&var1394,&var1402,&var722};
_S_and2  S_and2_238_1 = {&var67,&var1402,&var723};
_S_or2  S_or2_240_1 = {&var1391,&var1392,&var724};
_S_and2  S_and2_239_1 = {&var724,&var1402,&var725};
_S_or2  S_or2_229_1 = {&B4IS11LDU,&A4IS11LDU,&var726};
_S_and3  S_and3_228_1 = {&var1393,&var726,&var1402,&var727};
_S_and2  S_and2_226_1 = {&var1673,&var1402,&var728};
_S_and2  S_and2_227_1 = {&R3IS21LDU,&var1402,&var729};
_S_and2  S_and2_202_1 = {&var1161,&var732,&var730};
_S_and2  S_and2_181_1 = {&A1MD11LP1,&var1200,&var731};
_S_or2  S_or2_196_1 = {&A1MD12LP1,&var731,&var732};
_S_or2  S_or2_212_1 = {&var1401,&var1725,&var733};
_S_zpfs  S_zpfs_203_1 = {&var1416,&fRM_2_0,&var734,&internal1_m203_tx,&internal1_m203_y0};
_S_zpfs  S_zpfs_204_1 = {&var1415,&fRM_2_0,&var735,&internal1_m204_tx,&internal1_m204_y0};
_S_zpfs  S_zpfs_214_1 = {&var1413,&fEM_A1UL03RDU,&var736,&internal1_m214_tx,&internal1_m214_y0};
_S_or5  S_or5_192_1 = {&var717,&var736,&var735,&var734,&var1414,&var737};
_S_orn  S_orn_564_1 = {array_m564_x_1,&iRM_14_,&var738};
_S_and2  S_and2_587_1 = {&var1357,&var977,&var739};
_S_or2  S_or2_582_1 = {&var976,&var739,&var740};
_S_and3  S_and3_576_1 = {&var965,&var1471,&var1369,&var741};
_S_and2  S_and2_575_1 = {&var160,&var1369,&var742};
_S_and3  S_and3_577_1 = {&var1170,&var1369,&var740,&var743};
_S_or2  S_or2_557_1 = {&var1359,&var1358,&var744};
_S_and2  S_and2_556_1 = {&var744,&var1369,&var745};
_S_and2  S_and2_555_1 = {&var1369,&var67,&var746};
_S_and3  S_and3_545_1 = {&var1360,&var748,&var1369,&var747};
_S_or2  S_or2_546_1 = {&B4IS11LDU,&A4IS11LDU,&var748};
_S_and2  S_and2_553_1 = {&var1369,&var1361,&var749};
_S_or2  S_or2_523_1 = {&B1MD12LP1,&var752,&var750};
_S_and2  S_and2_527_1 = {&var1161,&var750,&var751};
_S_and2  S_and2_516_1 = {&B1MD11LP1,&var1180,&var752};
_S_and2  S_and2_544_1 = {&var1369,&R3IS21LDU,&var753};
_S_and2  S_and2_543_1 = {&var1369,&var1673,&var754};
_S_or2  S_or2_534_1 = {&var1368,&var1747,&var755};
_S_zpfs  S_zpfs_536_1 = {&var1382,&fEM_A1UL03RDU,&var756,&internal1_m536_tx,&internal1_m536_y0};
_S_or5  S_or5_519_1 = {&var910,&var756,&var1383,&var1377,&var1378,&var757};
_S_or2  S_or2_507_1 = {&var1196,&var777,&var758};
_S_or3  S_or3_497_1 = {&var598,&var1195,&var1007,&var759};
_S_or4  S_or4_487_1 = {&var1421,&var1419,&var1421,&var1420,&var760};
_S_or4  S_or4_469_1 = {&var1430,&var1428,&var1429,&var1431,&var761};
_S_or2  S_or2_476_1 = {&var761,&var760,&var762};
_S_and3  S_and3_460_1 = {&var765,&var1161,&R0MD33LP1,&var763};
_S_and3  S_and3_461_1 = {&var1161,&var766,&R0MD33LP1,&var764};
_S_or3  S_or3_453_1 = {&var300,&var1016,&var1003,&var765};
_S_or2  S_or2_454_1 = {&var1417,&var1194,&var766};
_S_or2  S_or2_762_1 = {&var1552,&var1553,&var767};
_S_and2  S_and2_346_1 = {&var1052,&var1114,&var768};
_S_or2  S_or2_365_1 = {&B4IS21LDU,&A4IS21LDU,&var769};
_S_or2  S_or2_360_1 = {&A2IS21LDU,&B2IS21LDU,&var770};
_S_or2  S_or2_355_1 = {&var773,&var1056,&var771};
_S_and3  S_and3_353_1 = {&var1115,&var1110,&var1111,&var772};
_S_or4  S_or4_351_1 = {&var1041,&var210,&R0MD31LP1,&var1051,&var773};
_S_and4  S_and4_347_1 = {&var963,&var831,&var269,&var921,&var774};
_S_or2  S_or2_342_1 = {&R0MD34LP1,&var1051,&var775};
_S_and3  S_and3_616_1 = {&var798,&var1294,&B2IS12LDU,&var776};
_S_and2  S_and2_615_1 = {&var798,&var1326,&var777};
_S_and2  S_and2_614_1 = {&var798,&var1389,&var778};
_S_or2  S_or2_658_1 = {&A2IS12LDU,&B2IS12LDU,&var779};
_S_or2  S_or2_635_1 = {&var1524,&var1150,&var780};
_S_and3  S_and3_626_1 = {&A2IS12LDU,&var1294,&var799,&var781};
_S_and2  S_and2_657_1 = {&var783,&var1294,&var782};
_S_or2  S_or2_659_1 = {&var1093,&var253,&var783};
_S_or2  S_or2_640_1 = {&var1524,&var1149,&var784};
_S_or2  S_or2_638_1 = {&var786,&var1524,&var785};
_S_and2  S_and2_650_1 = {&var1326,&var264,&var786};
_S_and2  S_and2_625_1 = {&var799,&var1326,&var787};
_S_and2  S_and2_624_1 = {&var799,&var1389,&var788};
_S_and2  S_and2_649_1 = {&var258,&var1389,&var789};
_S_and2  S_and2_665_1 = {&var261,&var1417,&var790};
_S_or2  S_or2_661_1 = {&var1524,&var1151,&var791};
_S_or2  S_or2_656_1 = {&var793,&var790,&var792};
_S_and2  S_and2_648_1 = {&var801,&var1386,&var793};
_S_and2  S_and2_654_1 = {&var801,&R0MD33LP1,&var794};
_S_or2  S_or2_604_1 = {&var974,&var975,&var795};
_S_and4  S_and4_623_1 = {&var974,&var799,&var1486,&A2IS12LDU,&var796};
_S_and4  S_and4_613_1 = {&var798,&var975,&var1486,&B2IS12LDU,&var797};
_S_and2  S_and2_612_1 = {&var918,&var1484,&var798};
_S_and2  S_and2_622_1 = {&var917,&var1484,&var799};
_S_or2  S_or2_653_1 = {&var1094,&var253,&var800};
_S_and2  S_and2_646_1 = {&var800,&var1486,&var801};
_S_or2  S_or2_633_1 = {&var1524,&var1152,&var802};
_S_or2  S_or2_645_1 = {&var1464,&var1107,&var803};
_S_and2  S_and2_644_1 = {&var803,&var1508,&var804};
_S_or2  S_or2_630_1 = {&var1524,&var1153,&var805};
_S_and2  S_and2_643_1 = {&var1525,&var1474,&var806};
_S_or2  S_or2_628_1 = {&var1524,&var1154,&var807};
_S_and2  S_and2_641_1 = {&var256,&var1527,&var808};
_S_or2  S_or2_620_1 = {&var1162,&var1524,&var809};
_S_and2  S_and2_321_1 = {&var1224,&var812,&var810};
_S_and2  S_and2_309_1 = {&var812,&var1039,&var811};
_S_or2  S_or2_304_1 = {&var1053,&var1075,&var812};
_S_and3  S_and3_300_1 = {&var1290,&var1110,&var1111,&var813};
_S_and3  S_and3_315_1 = {&var770,&var1040,&var815,&var814};
_S_or2  S_or2_305_1 = {&var1290,&var1115,&var815};
_S_and2  S_and2_314_1 = {&var769,&var815,&var816};
_S_and2  S_and2_334_1 = {&var821,&var918,&var817};
_S_and2  S_and2_335_1 = {&var917,&var821,&var818};
_S_and2  S_and2_340_1 = {&var1012,&var810,&var819};
_S_and2  S_and2_328_1 = {&var821,&var1012,&var820};
_S_and2  S_and2_333_1 = {&var1192,&var822,&var821};
_S_or2  S_or2_329_1 = {&var823,&var768,&var822};
_S_or2  S_or2_330_1 = {&var824,&var768,&var823};
_S_and4  S_and4_331_1 = {&var1116,&var1064,&var1065,&var915,&var824};
_S_or2  S_or2_317_1 = {&var1116,&var1114,&var825};
_S_and2  S_and2_302_1 = {&var1078,&var1047,&var826};
_S_or2  S_or2_308_1 = {&var829,&var826,&var827};
_S_or2  S_or2_282_1 = {&R0MD34LP1,&var1050,&var828};
_S_or4  S_or4_299_1 = {&var1041,&R0MD31LP1,&var210,&var1050,&var829};
_S_and3  S_and3_292_1 = {&var831,&var920,&var269,&var830};
_S_or2  S_or2_291_1 = {&var1069,&var1255,&var831};
_S_and3  S_and3_293_1 = {&var1070,&var1072,&var1071,&var832};
_S_or2  S_or2_284_1 = {&var834,&var832,&var833};
_S_and3  S_and3_278_1 = {&R0MD33LP1,&var1074,&var1073,&var834};
_S_or2  S_or2_1107_1 = {&B4IS11LDU,&A4IS11LDU,&var835};
_S_and2  S_and2_1110_1 = {&var1475,&var1522,&var836};
_S_and2  S_and2_1109_1 = {&var1475,&var1630,&var837};
_S_and2  S_and2_1108_1 = {&var1475,&var907,&var838};
_S_and2  S_and2_1106_1 = {&var1475,&var835,&var839};
_S_and2  S_and2_1100_1 = {&var1475,&var160,&var840};
_S_and2  S_and2_1099_1 = {&var896,&var1475,&var841};
_S_and2  S_and2_1098_1 = {&var1475,&R3IS21LDU,&var842};
_S_and2  S_and2_1101_1 = {&var1475,&var1673,&var843};
_S_and2  S_and2_1093_1 = {&var253,&var1009,&var844};
_S_and2  S_and2_1094_1 = {&var264,&var1007,&var845};
_S_and2  S_and2_1095_1 = {&var258,&var1005,&var846};
_S_and2  S_and2_1096_1 = {&var261,&var1003,&var847};
_S_or2  S_or2_1078_1 = {&R0MD31LP1,&var849,&var848};
_S_and4  S_and4_1079_1 = {&var165,&var164,&var163,&var162,&var849};
_S_or2  S_or2_1149_1 = {&var1475,&var1728,&var850};
_S_or2  S_or2_1125_1 = {&var1525,&var1097,&var851};
_S_or2  S_or2_1205_1 = {&var1566,&var1565,&var852};
_S_or2  S_or2_1191_1 = {&var1575,&var1574,&var853};
_S_or2  S_or2_1201_1 = {&var990,&R0MD34LP1,&var854};
_S_or2  S_or2_1172_1 = {&var852,&var1630,&var855};
_S_or2  S_or2_1168_1 = {&var857,&var855,&var856};
_S_or2  S_or2_1171_1 = {&var853,&var1630,&var857};
_S_or4  S_or4_377_1 = {&var1602,&var1601,&var1603,&var1600,&var858};
_S_or2  S_or2_678_1 = {&B5IS11LDU,&A5IS11LDU,&var859};
_S_and2  S_and2_677_1 = {&var864,&var859,&var860};
_S_or2  S_or2_676_1 = {&B6IS11LDU,&A6IS11LDU,&var861};
_S_and2  S_and2_675_1 = {&var864,&var861,&var862};
_S_or2  S_or2_674_1 = {&A4IS11LDU,&B4IS11LDU,&var863};
_S_or2  S_or2_667_1 = {&var866,&var867,&var864};
_S_and2  S_and2_673_1 = {&var864,&var863,&var865};
_S_and2  S_and2_670_1 = {&var160,&var877,&var866};
_S_and2  S_and2_666_1 = {&var161,&var870,&var867};
_S_and2  S_and2_782_1 = {&var1628,&var1546,&var868};
_S_and2  S_and2_778_1 = {&var1628,&var1547,&var869};
_S_and3  S_and3_773_1 = {&var1628,&var161,&var1553,&var870};
_S_or2  S_or2_781_1 = {&var1548,&var1542,&var871};
_S_or2  S_or2_776_1 = {&var1546,&var1548,&var872};
_S_or2  S_or2_772_1 = {&var1548,&var1547,&var873};
_S_and2  S_and2_754_1 = {&var1542,&var1628,&var874};
_S_or2  S_or2_748_1 = {&var1549,&var1550,&var875};
_S_or2  S_or2_739_1 = {&var1607,&var1549,&var876};
_S_and2  S_and2_738_1 = {&var1550,&var1629,&var877};
_S_and2  S_and2_737_1 = {&var1607,&var1629,&var878};
_S_and2  S_and2_766_1 = {&var256,&var1628,&var879};
_S_and2  S_and2_746_1 = {&var256,&var1559,&var880};
_S_and2  S_and2_764_1 = {&var1629,&var256,&var881};
_S_or2  S_or2_758_1 = {&var1629,&var1628,&var882};
_S_or3  S_or3_751_1 = {&var71,&var885,&var886,&var883};
_S_or4  S_or4_750_1 = {&var885,&var70,&var887,&var1538,&var884};
_S_or3  S_or3_741_1 = {&R4MD31LP2,&var874,&var878,&var885};
_S_or2  S_or2_770_1 = {&var1627,&var889,&var886};
_S_or2  S_or2_769_1 = {&var1627,&var888,&var887};
_S_and2  S_and2_684_1 = {&var71,&var1541,&var888};
_S_and3  S_and3_717_1 = {&var1540,&var1554,&var70,&var889};
_S_and2  S_and2_722_1 = {&R5IS11LDU,&var904,&var890};
_S_and3  S_and3_720_1 = {&var1192,&R3IS21LDU,&var904,&var891};
_S_and2  S_and2_721_1 = {&R6IS21LDU,&var904,&var892};
_S_or2  S_or2_719_1 = {&B8IS22LDU,&A8IS22LDU,&var893};
_S_and2  S_and2_718_1 = {&var893,&var904,&var894};
_S_and2  S_and2_705_1 = {&var904,&var896,&var895};
_S_or4  S_or4_706_1 = {&A0VN71LZ1,&B0VN71LZ1,&B0VN71LZ2,&A0VN71LZ2,&var896};
_S_and2  S_and2_703_1 = {&var901,&var904,&var897};
_S_and2  S_and2_694_1 = {&var907,&var904,&var898};
_S_and2  S_and2_693_1 = {&var1630,&var904,&var899};
_S_or3  S_or3_692_1 = {&R0NE01LDU,&R0NE02LDU,&R0NE08LDU,&var900};
_S_or2  S_or2_704_1 = {&R1IS21LDU,&R2IS21LDU,&var901};
_S_and2  S_and2_691_1 = {&var904,&var900,&var902};
_S_and2  S_and2_689_1 = {&var1608,&var904,&var903};
_S_or2  S_or2_680_1 = {&var1629,&var1628,&var904};
_S_or2  S_or2_172_1 = {&var1198,&var787,&var905};
_S_or3  S_or3_162_1 = {&var597,&var1197,&var1007,&var906};
_S_or2  S_or2_153_1 = {&var1471,&var406,&var907};
_S_or3  S_or3_114_1 = {&var1160,&var392,&var393,&var908};
_S_or2  S_or2_2035_1 = {&var354,&var231,&var909};
_S_or3  S_or3_589_1 = {&var911,&var912,&var738,&var910};
_S_and2  S_and2_578_1 = {&var1368,&var914,&var911};
_S_and2  S_and2_579_1 = {&var1368,&var964,&var912};
_S_or2  S_or2_66_1 = {&var964,&var914,&var913};
_S_and2  S_and2_69_1 = {&var915,&var1043,&var914};
_S_and2  S_and2_68_1 = {&var1637,&var1044,&var915};
_S_or2  S_or2_54_1 = {&A4IS21LDU,&B4IS21LDU,&var916};
_S_or2  S_or2_41_1 = {&var1288,&var1285,&var917};
_S_or2  S_or2_45_1 = {&var1288,&var1287,&var918};
_S_or2  S_or2_23_1 = {&var1192,&var1145,&var919};
_S_or2  S_or2_8_1 = {&var1647,&var966,&var920};
_S_or2  S_or2_17_1 = {&var966,&var1648,&var921};
_S_and3  S_and3_1001_1 = {&var266,&var1641,&var941,&var922};
_S_and3  S_and3_602_1 = {&var941,&var269,&var1641,&var923};
_S_and2  S_and2_1067_1 = {&var987,&var925,&var924};
_S_or2  S_or2_1072_1 = {&var1648,&var1647,&var925};
_S_or2  S_or2_1388_1 = {&var1649,&var1647,&var926};
_S_and3  S_and3_1387_1 = {&var985,&var926,&var664,&var927};
_S_or2  S_or2_976_1 = {&var1649,&var1647,&var928};
_S_and3  S_and3_975_1 = {&var985,&var928,&var679,&var929};
_S_or2  S_or2_568_1 = {&var1649,&var1647,&var930};
_S_and3  S_and3_567_1 = {&var985,&var930,&var1369,&var931};
_S_and2  S_and2_565_1 = {&var156,&var1369,&var932};
_S_or2  S_or2_251_1 = {&var1649,&var1647,&var933};
_S_and3  S_and3_250_1 = {&var985,&var933,&var1402,&var934};
_S_and2  S_and2_248_1 = {&var1402,&var157,&var935};
_S_and3  S_and3_881_1 = {&var985,&var938,&var704,&var936};
_S_and2  S_and2_880_1 = {&var498,&var704,&var937};
_S_or2  S_or2_882_1 = {&var1649,&var1647,&var938};
_S_or2  S_or2_1299_1 = {&var1649,&var1647,&var939};
_S_or2  S_or2_6_1 = {&var1648,&var1647,&var940};
_S_or3  S_or3_5_1 = {&var1649,&var1648,&var1647,&var941};
_S_or2  S_or2_757_1 = {&var1549,&var1551,&var942};
_S_or2  S_or2_450_1 = {&var1630,&var947,&var943};
_S_or2  S_or2_433_1 = {&var1630,&var948,&var944};
_S_or4  S_or4_434_1 = {&var944,&var1558,&var1557,&var943,&var945};
_S_and2  S_and2_426_1 = {&A8IS22LDU,&var1622,&var946};
_S_or3  S_or3_412_1 = {&var1612,&var1610,&var1611,&var947};
_S_or3  S_or3_397_1 = {&var1620,&var1619,&var1621,&var948};
_S_and2  S_and2_744_1 = {&var1629,&var1551,&var949};
_S_and2  S_and2_44_1 = {&var1285,&var1286,&var950};
_S_and2  S_and2_148_1 = {&var1561,&var1183,&var951};
_S_and2  S_and2_156_1 = {&var1563,&var1183,&var952};
_S_and2  S_and2_159_1 = {&var1560,&var1183,&var953};
_S_and2  S_and2_151_1 = {&var1183,&var1562,&var954};
_S_and2  S_and2_447_1 = {&var907,&var1614,&var955};
_S_and2  S_and2_446_1 = {&B8IS22LDU,&var1614,&var956};
_S_and2  S_and2_445_1 = {&A8IS22LDU,&var1614,&var957};
_S_and2  S_and2_444_1 = {&R5IS11LDU,&var1614,&var958};
_S_and2  S_and2_436_1 = {&var1556,&var1622,&var959};
_S_and2  S_and2_425_1 = {&R5IS11LDU,&var1622,&var960};
_S_and2  S_and2_429_1 = {&var907,&var1622,&var961};
_S_and2  S_and2_118_1 = {&var966,&var391,&var962};
_S_and2  S_and2_64_1 = {&var1638,&var1044,&var963};
_S_and2  S_and2_65_1 = {&var963,&var1042,&var964};
_S_and2  S_and2_48_1 = {&var1286,&var1287,&var965};
_S_and2  S_and2_11_1 = {&var1646,&var1278,&var966};
_S_and2  S_and2_34_1 = {&var1209,&var255,&var967};
_S_and2  S_and2_33_1 = {&var1103,&var1192,&var968};
_S_and2  S_and2_32_1 = {&var1104,&var1192,&var969};
_S_and2  S_and2_31_1 = {&var1105,&var1192,&var970};
_S_and2  S_and2_30_1 = {&var1106,&var1192,&var971};
_S_and2  S_and2_771_1 = {&var1545,&var1553,&var972};
_S_and2  S_and2_753_1 = {&var1552,&var1629,&var973};
_S_bol  S_bol_603_1 = {&var1742,&fRM_20_0,&var974};
_S_bol  S_bol_597_1 = {&var1739,&fRM_20_0,&var975};
_S_bol  S_bol_588_1 = {&var1739,&fRM_20_03,&var976};
_S_bol  S_bol_586_1 = {&var1742,&fRM_20_03,&var977};
_S_bol  S_bol_991_1 = {&var1739,&fRM_20_03,&var978};
_S_bol  S_bol_993_1 = {&var1742,&fRM_20_03,&var979};
_S_bol  S_bol_1403_1 = {&var1742,&fRM_20_03,&var980};
_S_bol  S_bol_1405_1 = {&var1739,&fRM_20_03,&var981};
_S_bol  S_bol_272_1 = {&var1739,&fRM_20_03,&var982};
_S_bol  S_bol_274_1 = {&var1742,&fRM_20_03,&var983};
_S_sr  S_sr_88_1 = {array_m88_x_1,&iRM_2_,&var984};
_S_bol  S_bol_87_1 = {&var984,&var209,&var985};
_S_ma  S_ma_90_1 = {array_m90_x_1,&R0MW15IP1,&iRM_8_,&var986};
_S_bol  S_bol_1068_1 = {&var988,&fEM_R0UN80RDU,&var987};
_S_sr  S_sr_1073_1 = {array_m1073_x_1,&iRM_2_,&var988};
_S_ovbs  S_ovbs_2113_1 = {&lRM_1_,&fEM_A9UZ04RDU,&var989,&internal1_m2113_tx};
_S_ovbs  S_ovbs_1200_1 = {&lRM_1_,&fEM_A4UZ04RDU,&var990,&internal1_m1200_tx};
_S_zpfs  S_zpfs_1626_1 = {&var1516,&fEM_B8UL03RDU,&var991,&internal1_m1626_tx,&internal1_m1626_y0};
_S_zpfs  S_zpfs_1151_1 = {&var1533,&fEM_B8UL03RDU,&var992,&internal1_m1151_tx,&internal1_m1151_y0};
_S_ma  S_ma_1225_1 = {array_m1225_x_1,&var1485,&iRM_8_,&var993};
_S_ma  S_ma_823_1 = {array_m823_x_1,&var1445,&iRM_8_,&var994};
_S_ma  S_ma_905_1 = {array_m905_x_1,&var1336,&iRM_8_,&var995};
_S_ma  S_ma_1322_1 = {array_m1322_x_1,&var1304,&iRM_8_,&var996};
_S_ma  S_ma_506_1 = {array_m506_x_1,&var1365,&iRM_8_,&var997};
_S_ma  S_ma_171_1 = {array_m171_x_1,&var1398,&iRM_8_,&var998};
_S_zpfs  S_zpfs_1352_1 = {&var1321,&fEM_A3UL03RDU,&var999,&internal1_m1352_tx,&internal1_m1352_y0};
_S_zpfs  S_zpfs_940_1 = {&var1353,&fEM_A3UL03RDU,&var1000,&internal1_m940_tx,&internal1_m940_y0};
_S_zpfs  S_zpfs_1259_1 = {&var1503,&fEM_A2UL03RDU,&var1001,&internal1_m1259_tx,&internal1_m1259_y0};
_S_rs  S_rs_1092_1 = {&var848,&var847,&var1002,&vainSBool,&internal1_m1092_q0};
_S_rs  S_rs_1090_1 = {&var165,&var1010,&var1003,&vainSBool,&internal1_m1090_q0};
_S_rs  S_rs_1089_1 = {&var848,&var846,&var1004,&vainSBool,&internal1_m1089_q0};
_S_rs  S_rs_1087_1 = {&var164,&var1010,&var1005,&vainSBool,&internal1_m1087_q0};
_S_rs  S_rs_1086_1 = {&var848,&var845,&var1006,&vainSBool,&internal1_m1086_q0};
_S_rs  S_rs_1084_1 = {&var163,&var1010,&var1007,&vainSBool,&internal1_m1084_q0};
_S_rs  S_rs_1083_1 = {&var848,&var844,&var1008,&vainSBool,&internal1_m1083_q0};
_S_rs  S_rs_1081_1 = {&var162,&var1010,&var1009,&vainSBool,&internal1_m1081_q0};
_S_rs  S_rs_1080_1 = {&var848,&var210,&var1010,&vainSBool,&internal1_m1080_q0};
_S_noto  S_noto_1947_1 = {&var466,&var1011};
_S_swtakt  S_swtakt_58_1 = {&var386,&var1012,&internal1_m58_x0};
_S_noto  S_noto_1066_1 = {&var1024,&var1013};
_S_noto  S_noto_1040_1 = {&var1022,&var1014};
_S_noto  S_noto_1052_1 = {&var1023,&var1015};
_S_rs  S_rs_1000_1 = {&var1025,&var605,&var1016,&vainSBool,&internal1_m1000_q0};
_S_swtakt  S_swtakt_1449_1 = {&var564,&var1017,&internal1_m1449_x0};
_S_swtakt  S_swtakt_1493_1 = {&var552,&var1018,&internal1_m1493_x0};
_S_swtakt  S_swtakt_1489_1 = {&var546,&var1019,&internal1_m1489_x0};
_S_swtakt  S_swtakt_1907_1 = {&var453,&var1020,&internal1_m1907_x0};
_S_swtakt  S_swtakt_1872_1 = {&var427,&var1021,&internal1_m1872_x0};
_S_rs  S_rs_1039_1 = {&var1096,&var593,&var1022,&vainSBool,&internal1_m1039_q0};
_S_rs  S_rs_1051_1 = {&var1096,&var594,&var1023,&vainSBool,&internal1_m1051_q0};
_S_rs  S_rs_1063_1 = {&var1096,&var595,&var1024,&vainSBool,&internal1_m1063_q0};
_S_rs  S_rs_1075_1 = {&var1096,&var596,&var1025,&vainSBool,&internal1_m1075_q0};
_S_noto  S_noto_1026_1 = {&var611,&var1026};
_S_noto  S_noto_1053_1 = {&var611,&var1027};
_S_noto  S_noto_1059_1 = {&var615,&var1028};
_S_rs  S_rs_1050_1 = {&var589,&var591,&var1029,&vainSBool,&internal1_m1050_q0};
_S_rs  S_rs_1065_1 = {&var1096,&var587,&var1030,&vainSBool,&internal1_m1065_q0};
_S_bol  S_bol_1047_1 = {&var1727,&var316,&var1031};
_S_bol  S_bol_1046_1 = {&var1730,&var316,&var1032};
_S_noto  S_noto_1007_1 = {&var1091,&var1033};
_S_bol  S_bol_1044_1 = {&var316,&var1727,&var1034};
_S_bol  S_bol_1043_1 = {&var316,&var1730,&var1035};
_S_noto  S_noto_1030_1 = {&var1092,&var1036};
_S_rs  S_rs_1965_1 = {&var471,&var462,&var1037,&vainSBool,&internal1_m1965_q0};
_S_rs  S_rs_1964_1 = {&var471,&var463,&var1038,&vainSBool,&internal1_m1964_q0};
_S_noto  S_noto_341_1 = {&var819,&var1039};
_S_noto  S_noto_323_1 = {&var812,&var1040};
_S_noto  S_noto_296_1 = {&var831,&var1041};
_S_noto  S_noto_62_1 = {&var1053,&var1042};
_S_noto  S_noto_73_1 = {&var1075,&var1043};
_S_noto  S_noto_72_1 = {&var1010,&var1044};
_S_noto  S_noto_1959_1 = {&B2IS11LDU,&var1045};
_S_noto  S_noto_1957_1 = {&A2IS11LDU,&var1046};
_S_noto  S_noto_301_1 = {&var269,&var1047};
_S_noto  S_noto_1966_1 = {&B2IS11LDU,&var1048};
_S_noto  S_noto_1941_1 = {&A2IS11LDU,&var1049};
_S_noto  S_noto_288_1 = {&var915,&var1050};
_S_noto  S_noto_345_1 = {&var963,&var1051};
_S_bolz  S_bolz_349_1 = {&iRM_2_,&var1054,&var1052};
_S_provsbr  S_provsbr_344_1 = {&var1114,&var775,&var1129,&var1146,&var1140,&var1135,&var1132,&var1130,&var1144,&var1139,&var1137,&var1133,&iRM_10_,array_m344_Tpr_1,array_m344_type_1,&var1053,&var1054,&var1055,&var1056,&var1057,&var1058,&var1059,&var1060,&var1061,&internal1_m344_Step,array_m344_rz_1,&internal1_m344_TimS,&internal1_m344_FinPr0,&internal1_m344_ErrPr0,&internal1_m344_sbINI0,&internal1_m344_sbVuIS0,&internal1_m344_sb2UR0,&internal1_m344_sbNupIS0,&internal1_m344_sbVuRB0,&internal1_m344_MyFirstEnterFlag};
_S_orni  S_orni_348_1 = {array_m348_x_1,&iRM_5_,&vainSBool,&var1062};
_S_cntch  S_cntch_352_1 = {&var1062,&var1063,&internal1_m352_x0};
_S_bolz  S_bolz_327_1 = {&iRM_20_,&var1077,&var1064};
_S_equz_p  S_equz_p_326_1 = {&var1076,&iRM_0_,&var1065};
_S_decatron  S_decatron_311_1 = {&var811,&var1066,&internal1_m311_TimS};
_S_noto  S_noto_1004_1 = {&R2IS21LDU,&var1067};
_S_noto  S_noto_998_1 = {&R1IS21LDU,&var1068};
_S_andn  S_andn_283_1 = {array_m283_x_1,&iRM_7_,&var1069};
_S_noto  S_noto_285_1 = {&R0MD33LP1,&var1070};
_S_noto  S_noto_294_1 = {&R2IS21LDU,&var1071};
_S_noto  S_noto_289_1 = {&R1IS21LDU,&var1072};
_S_noto  S_noto_280_1 = {&R1IS11LDU,&var1073};
_S_noto  S_noto_277_1 = {&R2IS11LDU,&var1074};
_S_provsbr  S_provsbr_287_1 = {&var1116,&var828,&var1129,&var1146,&var1140,&var1135,&var1132,&var1130,&var1144,&var1139,&var1137,&var1133,&iRM_10_,array_m287_Tpr_1,array_m287_type_1,&var1075,&var1076,&var1077,&var1078,&var1079,&var1080,&var1081,&var1082,&var1083,&internal1_m287_Step,array_m287_rz_1,&internal1_m287_TimS,&internal1_m287_FinPr0,&internal1_m287_ErrPr0,&internal1_m287_sbINI0,&internal1_m287_sbVuIS0,&internal1_m287_sb2UR0,&internal1_m287_sbNupIS0,&internal1_m287_sbVuRB0,&internal1_m287_MyFirstEnterFlag};
_S_rs  S_rs_1423_1 = {&var1085,&var586,&var1084,&vainSBool,&internal1_m1423_q0};
_S_provsbr  S_provsbr_1424_1 = {&var1084,&R0MD34LP1,&var1129,&var1146,&var1140,&var1135,&var1132,&var1130,&var1144,&var1139,&var1137,&var1133,&iRM_6_,array_m1424_Tpr_1,array_m1424_type_1,&var1085,&vainSInt,&vainSInt,&vainSBool,&var1086,&var1087,&var1088,&var1089,&var1090,&internal1_m1424_Step,array_m1424_rz_1,&internal1_m1424_TimS,&internal1_m1424_FinPr0,&internal1_m1424_ErrPr0,&internal1_m1424_sbINI0,&internal1_m1424_sbVuIS0,&internal1_m1424_sb2UR0,&internal1_m1424_sbNupIS0,&internal1_m1424_sbVuRB0,&internal1_m1424_MyFirstEnterFlag};
_S_abs_subf  S_abs_subf_1010_1 = {&var316,&var1730,&fEM_B8UC01RDU,&vainSFloat,&var1091};
_S_abs_subf  S_abs_subf_1023_1 = {&var1727,&var316,&fEM_B8UC01RDU,&vainSFloat,&var1092};
_S_noto  S_noto_664_1 = {&var779,&var1093};
_S_noto  S_noto_610_1 = {&var795,&var1094};
_S_noto  S_noto_55_1 = {&var312,&var1095};
_S_noto  S_noto_1027_1 = {&var1293,&var1096};
_S_rs  S_rs_1034_1 = {&var588,&var407,&var1097,&vainSBool,&internal1_m1034_q0};
_S_rs  S_rs_1031_1 = {&var592,&var587,&var1098,&vainSBool,&internal1_m1031_q0};
_S_rs  S_rs_1033_1 = {&var1096,&var407,&var1099,&vainSBool,&internal1_m1033_q0};
_S_rs  S_rs_1028_1 = {&var1096,&var590,&var1100,&vainSBool,&internal1_m1028_q0};
_S_noto  S_noto_599_1 = {&A2IS21LDU,&var1101};
_S_noto  S_noto_601_1 = {&B2IS21LDU,&var1102};
_S_noto  S_noto_28_1 = {&B2IS21LDU,&var1103};
_S_noto  S_noto_27_1 = {&B1IS21LDU,&var1104};
_S_noto  S_noto_26_1 = {&A1IS21LDU,&var1105};
_S_noto  S_noto_25_1 = {&A2IS21LDU,&var1106};
_S_newstage  S_newstage_611_1 = {&var133,&var130,&A2IS12LDU,&B2IS12LDU,&var1107};
_S_noto  S_noto_600_1 = {&B2IS12LDU,&var1108};
_S_noto  S_noto_598_1 = {&A2IS12LDU,&var1109};
_S_noto  S_noto_358_1 = {&var770,&var1110};
_S_noto  S_noto_362_1 = {&var769,&var1111};
_S_noto  S_noto_997_1 = {&var907,&var1112};
_S_rs  S_rs_761_1 = {&var767,&var389,&var1113,&vainSBool,&internal1_m761_q0};
_S_rs  S_rs_354_1 = {&var771,&var772,&var1114,&vainSBool,&internal1_m354_q0};
_S_rs  S_rs_350_1 = {&var773,&var774,&var1115,&vainSBool,&internal1_m350_q0};
_S_rs  S_rs_307_1 = {&var827,&var813,&var1116,&vainSBool,&internal1_m307_q0};
_S_orni  S_orni_303_1 = {array_m303_x_1,&iRM_5_,&vainSBool,&var1117};
_S_cntch  S_cntch_306_1 = {&var1117,&var1118,&internal1_m306_x0};
_S_noto  S_noto_1462_1 = {&var1137,&var1119};
_S_noto  S_noto_1518_1 = {&var1139,&var1120};
_S_noto  S_noto_1520_1 = {&var1144,&var1121};
_S_noto  S_noto_1888_1 = {&var1130,&var1122};
_S_noto  S_noto_1922_1 = {&var1133,&var1123};
_S_noto  S_noto_1903_1 = {&var1020,&var1124};
_S_noto  S_noto_1866_1 = {&var1021,&var1125};
_S_noto  S_noto_1490_1 = {&var1019,&var1126};
_S_noto  S_noto_1485_1 = {&var1018,&var1127};
_S_noto  S_noto_1445_1 = {&var1017,&var1128};
_S_rs  S_rs_1894_1 = {&var571,&var411,&var1129,&vainSBool,&internal1_m1894_q0};
_S_rs  S_rs_1882_1 = {&var426,&var423,&var1130,&vainSBool,&internal1_m1882_q0};
_S_rs  S_rs_1873_1 = {&var422,&var1021,&var1131,&vainSBool,&internal1_m1873_q0};
_S_rs  S_rs_1948_1 = {&var571,&var440,&var1132,&vainSBool,&internal1_m1948_q0};
_S_rs  S_rs_1919_1 = {&var448,&var447,&var1133,&vainSBool,&internal1_m1919_q0};
_S_rs  S_rs_1908_1 = {&var450,&var1020,&var1134,&vainSBool,&internal1_m1908_q0};
_S_rs  S_rs_1476_1 = {&var571,&var557,&var1135,&vainSBool,&internal1_m1476_q0};
_S_kvf  S_kvf_1463_1 = {&var1138,&var558,&fRM_0_0,&var1136,&vainSInt,&vainSInt,&internal1_m1463_x0,&internal1_m1463_y0,&bFirstEnterFlag};
_S_rs  S_rs_1459_1 = {&var563,&var558,&var1137,&vainSBool,&internal1_m1459_q0};
_S_rs  S_rs_1450_1 = {&var560,&var1017,&var1138,&vainSBool,&internal1_m1450_q0};
_S_rs  S_rs_1509_1 = {&var553,&var548,&var1139,&vainSBool,&internal1_m1509_q0};
_S_rs  S_rs_1529_1 = {&var571,&var554,&var1140,&vainSBool,&internal1_m1529_q0};
_S_rs  S_rs_1495_1 = {&var551,&var1018,&var1141,&vainSBool,&internal1_m1495_q0};
_S_kvf  S_kvf_1510_1 = {&var1141,&var548,&fRM_0_0,&var1142,&vainSInt,&vainSInt,&internal1_m1510_x0,&internal1_m1510_y0,&bFirstEnterFlag};
_S_cntch  S_cntch_1434_1 = {&var573,&var1143,&internal1_m1434_x0};
_S_rs  S_rs_1515_1 = {&var545,&var539,&var1144,&vainSBool,&internal1_m1515_q0};
_S_rs  S_rs_29_1 = {&var1192,&var967,&var1145,&vainSBool,&internal1_m29_q0};
_S_rs  S_rs_1530_1 = {&var571,&var538,&var1146,&vainSBool,&internal1_m1530_q0};
_S_noto  S_noto_1412_1 = {&var567,&var1147};
_S_noto  S_noto_1410_1 = {&var966,&var1148};
_S_rs  S_rs_651_1 = {&var1524,&var782,&var1149,&vainSBool,&internal1_m651_q0};
_S_rs  S_rs_636_1 = {&var1524,&var789,&var1150,&vainSBool,&internal1_m636_q0};
_S_rs  S_rs_662_1 = {&var1524,&var790,&var1151,&vainSBool,&internal1_m662_q0};
_S_rs  S_rs_647_1 = {&var1524,&var801,&var1152,&vainSBool,&internal1_m647_q0};
_S_rs  S_rs_631_1 = {&var1524,&var804,&var1153,&vainSBool,&internal1_m631_q0};
_S_rs  S_rs_629_1 = {&var1524,&var806,&var1154,&vainSBool,&internal1_m629_q0};
_S_rs  S_rs_617_1 = {&var809,&var1527,&var1155,&vainSBool,&internal1_m617_q0};
_S_rsun  S_rsun_1426_1 = {&var571,&var1277,&vainSLong,&var1156,&internal1_m1426_q0};
_S_noto  S_noto_1353_1 = {&B3MD12LP1,&var1157};
_S_noto  S_noto_1840_1 = {&B3IS11LDU,&var1158};
_S_noto  S_noto_1814_1 = {&A3IS11LDU,&var1159};
_S_noto  S_noto_117_1 = {&var966,&var1160};
_S_noto  S_noto_116_1 = {&var1165,&var1161};
_S_rs  S_rs_627_1 = {&var1524,&var808,&var1162,&vainSBool,&internal1_m627_q0};
_S_orni  S_orni_1199_1 = {array_m1199_x_1,&iRM_5_,&var1163,&vainSLong};
_S_orni  S_orni_1187_1 = {array_m1187_x_1,&iRM_4_,&var1164,&vainSLong};
_S_rs  S_rs_115_1 = {&var908,&var962,&var1165,&vainSBool,&internal1_m115_q0};
_S_noto  S_noto_1843_1 = {&var489,&var1166};
_S_noto  S_noto_1842_1 = {&var488,&var1167};
_S_noto  S_noto_1854_1 = {&B3IS22LDU,&var1168};
_S_noto  S_noto_1834_1 = {&A3IS22LDU,&var1169};
_S_newstage  S_newstage_1838_1 = {&var505,&var501,&var504,&var500,&vainSBool};
_S_noto  S_noto_1782_1 = {&var1255,&var1170};
_S_rs  S_rs_1662_1 = {&var47,&var280,&var1171,&vainSBool,&internal1_m1662_q0};
_S_rs  S_rs_1661_1 = {&var40,&var282,&var1172,&vainSBool,&internal1_m1661_q0};
_S_rs  S_rs_1660_1 = {&var46,&var284,&var1173,&vainSBool,&internal1_m1660_q0};
_S_rs  S_rs_1659_1 = {&var21,&var286,&var1174,&vainSBool,&internal1_m1659_q0};
_S_rs  S_rs_1697_1 = {&var255,&var288,&var1175,&vainSBool,&internal1_m1697_q0};
_S_rs  S_rs_1696_1 = {&var58,&var291,&var1176,&vainSBool,&internal1_m1696_q0};
_S_rs  S_rs_1695_1 = {&var59,&var291,&var1177,&vainSBool,&internal1_m1695_q0};
_S_noto  S_noto_1253_1 = {&A2MD12LP1,&var1178};
_S_noto  S_noto_1237_1 = {&B2MD12LP1,&var1179};
_S_noto  S_noto_521_1 = {&B1MD12LP1,&var1180};
_S_ma  S_ma_1465_1 = {array_m1465_x_1,&var1156,&iRM_16_,&var1181};
_S_noto  S_noto_1420_1 = {&var823,&var1182};
_S_noto  S_noto_146_1 = {&var966,&var1183};
_S_equz_p  S_equz_p_1820_1 = {&R0MW14IP2,&iRM_5_,&var1184};
_S_equz_p  S_equz_p_1819_1 = {&R0MW14IP2,&iRM_4_,&var1185};
_S_equz_p  S_equz_p_1818_1 = {&R0MW14IP2,&iRM_3_,&var1186};
_S_equz_p  S_equz_p_1816_1 = {&R0MW14IP2,&iRM_1_,&vainSBool};
_S_equz_p  S_equz_p_1817_1 = {&R0MW14IP2,&iRM_2_,&var1187};
_S_noto  S_noto_1875_1 = {&B3IS11LDU,&var1188};
_S_noto  S_noto_1870_1 = {&A3IS11LDU,&var1189};
_S_noto  S_noto_1912_1 = {&B2IS11LDU,&var1190};
_S_noto  S_noto_1920_1 = {&A2IS11LDU,&var1191};
_S_noto  S_noto_12_1 = {&var1646,&var1192};
_S_rs  S_rs_1979_1 = {&var374,&var475,&var1193,&vainSBool,&internal1_m1979_q0};
_S_rs  S_rs_1757_1 = {&var517,&var301,&var1194,&vainSBool,&internal1_m1757_q0};
_S_rs  S_rs_1746_1 = {&var43,&var302,&var1195,&vainSBool,&internal1_m1746_q0};
_S_rs  S_rs_1754_1 = {&var60,&var303,&var1196,&vainSBool,&internal1_m1754_q0};
_S_rs  S_rs_1743_1 = {&var44,&var304,&var1197,&vainSBool,&internal1_m1743_q0};
_S_rs  S_rs_1751_1 = {&var64,&var305,&var1198,&vainSBool,&internal1_m1751_q0};
_S_equz_p  S_equz_p_105_1 = {&R0MW16IP1,&iRM_10_,&var1199};
_S_noto  S_noto_190_1 = {&A1MD12LP1,&var1200};
_S_rs  S_rs_2179_1 = {&var34,&var31,&var1201,&vainSBool,&internal1_m2179_q0};
_S_rs  S_rs_2175_1 = {&var50,&var122,&var1202,&vainSBool,&internal1_m2175_q0};
_S_rs  S_rs_1722_1 = {&var63,&var298,&var1203,&vainSBool,&internal1_m1722_q0};
_S_rs  S_rs_1714_1 = {&var255,&var287,&var1204,&vainSBool,&internal1_m1714_q0};
_S_rs  S_rs_1712_1 = {&var45,&var288,&var1205,&vainSBool,&internal1_m1712_q0};
_S_rs  S_rs_1708_1 = {&var58,&var289,&var1206,&vainSBool,&internal1_m1708_q0};
_S_rs  S_rs_1704_1 = {&var18,&var291,&var1207,&vainSBool,&internal1_m1704_q0};
_S_rs  S_rs_1706_1 = {&var59,&var290,&var1208,&vainSBool,&internal1_m1706_q0};
_S_rs  S_rs_22_1 = {&var919,&var395,&var1209,&vainSBool,&internal1_m22_q0};
_S_equz_p  S_equz_p_104_1 = {&R0MW16IP1,&iRM_9_,&var1210};
_S_equz_p  S_equz_p_103_1 = {&R0MW16IP1,&iRM_8_,&var1211};
_S_noto  S_noto_941_1 = {&A3MD12LP1,&var1212};
_S_equz_p  S_equz_p_102_1 = {&R0MW16IP1,&iRM_7_,&var1213};
_S_equz_p  S_equz_p_101_1 = {&R0MW16IP1,&iRM_6_,&var1214};
_S_equz_p  S_equz_p_100_1 = {&R0MW16IP1,&iRM_5_,&var1215};
_S_rs  S_rs_1685_1 = {&var47,&var279,&var1216,&vainSBool,&internal1_m1685_q0};
_S_rs  S_rs_1683_1 = {&var39,&var280,&var1217,&vainSBool,&internal1_m1683_q0};
_S_rs  S_rs_1679_1 = {&var57,&var282,&var1218,&vainSBool,&internal1_m1679_q0};
_S_rs  S_rs_1681_1 = {&var40,&var281,&var1219,&vainSBool,&internal1_m1681_q0};
_S_rs  S_rs_1677_1 = {&var46,&var283,&var1220,&vainSBool,&internal1_m1677_q0};
_S_rs  S_rs_1675_1 = {&var22,&var284,&var1221,&vainSBool,&internal1_m1675_q0};
_S_rs  S_rs_2095_1 = {&var137,&var484,&var1222,&vainSBool,&internal1_m2095_q0};
_S_rs  S_rs_2090_1 = {&var138,&var485,&var1223,&vainSBool,&internal1_m2090_q0};
_S_equz_p  S_equz_p_316_1 = {&var1066,&iRM_0_,&var1224};
_S_noto  S_noto_2096_1 = {&var1222,&var1225};
_S_noto  S_noto_2086_1 = {&var399,&var1226};
_S_noto  S_noto_2070_1 = {&var1228,&var1227};
_S_rs  S_rs_2069_1 = {&var77,&var481,&var1228,&vainSBool,&internal1_m2069_q0};
_S_noto  S_noto_2058_1 = {&var1230,&var1229};
_S_rs  S_rs_2057_1 = {&var79,&var478,&var1230,&vainSBool,&internal1_m2057_q0};
_S_noto  S_noto_2091_1 = {&var1223,&var1231};
_S_noto  S_noto_2082_1 = {&var398,&var1232};
_S_noto  S_noto_1991_1 = {&var1234,&var1233};
_S_rs  S_rs_1990_1 = {&var373,&var476,&var1234,&vainSBool,&internal1_m1990_q0};
_S_noto  S_noto_1980_1 = {&var1193,&var1235};
_S_noto  S_noto_1986_1 = {&var396,&var1236};
_S_noto  S_noto_1974_1 = {&var397,&var1237};
_S_rs  S_rs_1671_1 = {&var56,&var286,&var1238,&vainSBool,&internal1_m1671_q0};
_S_rs  S_rs_1673_1 = {&var21,&var285,&var1239,&vainSBool,&internal1_m1673_q0};
_S_rs  S_rs_1657_1 = {&var37,&var271,&var1240,&vainSBool,&internal1_m1657_q0};
_S_rs  S_rs_1655_1 = {&var55,&var272,&var1241,&vainSBool,&internal1_m1655_q0};
_S_rs  S_rs_1653_1 = {&var36,&var273,&var1242,&vainSBool,&internal1_m1653_q0};
_S_rs  S_rs_1651_1 = {&var54,&var274,&var1243,&vainSBool,&internal1_m1651_q0};
_S_noto  S_noto_1777_1 = {&B3IS22LDU,&var1244};
_S_noto  S_noto_1776_1 = {&A3IS22LDU,&var1245};
_S_noto  S_noto_1775_1 = {&B2IS12LDU,&var1246};
_S_noto  S_noto_1774_1 = {&A2IS12LDU,&var1247};
_S_noto  S_noto_1773_1 = {&B1IS12LDU,&var1248};
_S_noto  S_noto_1772_1 = {&A1IS12LDU,&var1249};
_S_noto  S_noto_1802_1 = {&B3IS21LDU,&var1250};
_S_noto  S_noto_1796_1 = {&B2IS21LDU,&var1251};
_S_noto  S_noto_1801_1 = {&A3IS21LDU,&var1252};
_S_noto  S_noto_1799_1 = {&B4IS21LDU,&var1253};
_S_noto  S_noto_1800_1 = {&A4IS21LDU,&var1254};
_S_andn  S_andn_1785_1 = {array_m1785_x_1,&iRM_17_,&var1255};
_S_noto  S_noto_1794_1 = {&B1IS21LDU,&var1256};
_S_noto  S_noto_1795_1 = {&A2IS21LDU,&var1257};
_S_noto  S_noto_1793_1 = {&A1IS21LDU,&var1258};
_S_rs  S_rs_1650_1 = {&var1263,&var275,&var1259,&vainSBool,&internal1_m1650_q0};
_S_rs  S_rs_1648_1 = {&var38,&var276,&var1260,&vainSBool,&internal1_m1648_q0};
_S_rs  S_rs_1647_1 = {&var1263,&var277,&var1261,&vainSBool,&internal1_m1647_q0};
_S_rs  S_rs_1645_1 = {&var19,&var278,&var1262,&vainSBool,&internal1_m1645_q0};
_S_newstage  S_newstage_2116_1 = {&var1275,&var1269,&var1274,&var1268,&var1263};
_S_samhd  S_samhd_2118_1 = {&var529,&var530,&var530,&var1260,&var1259,&var1260,&var1259,&B9IS11LDU,&B9IS11LDU,&B9IS21LDU,&B9IS21LDU,&bRM_1_,&fEM_A9UZ05RDU,&fEM_A9UZ03RDU,&fEM_A9UZ04RDU,&var1264,&var1265,&vainSBool,&var1266,&var1267,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1268,&var1269,&internal1_m2118_DvUp0,&internal1_m2118_DvDw0,&internal1_m2118_FDvUp0,&internal1_m2118_FDvDw0,&internal1_m2118_BlDv0,&internal1_m2118_Pkv0,&internal1_m2118_Pkav0,&internal1_m2118_Zkv0,&internal1_m2118_Zkav0,&internal1_m2118_txNm,&internal1_m2118_txSm,&internal1_m2118_txHr,&internal1_m2118_txLd,&internal1_m2118_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_2112_1 = {&var529,&var531,&var531,&var1262,&var1261,&var1262,&var1261,&A9IS11LDU,&A9IS11LDU,&A9IS21LDU,&A9IS21LDU,&bRM_1_,&fEM_A9UZ05RDU,&fEM_A9UZ03RDU,&fEM_A9UZ04RDU,&var1270,&var1271,&vainSBool,&var1272,&var1273,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1274,&var1275,&internal1_m2112_DvUp0,&internal1_m2112_DvDw0,&internal1_m2112_FDvUp0,&internal1_m2112_FDvDw0,&internal1_m2112_BlDv0,&internal1_m2112_Pkv0,&internal1_m2112_Pkav0,&internal1_m2112_Zkv0,&internal1_m2112_Zkav0,&internal1_m2112_txNm,&internal1_m2112_txSm,&internal1_m2112_txHr,&internal1_m2112_txLd,&internal1_m2112_fef,&bFirstEnterFlag};
_S_orni  S_orni_1427_1 = {array_m1427_x_1,&iRM_5_,&var1276,&var1277};
_S_noto  S_noto_84_1 = {&var401,&var1278};
_S_maz  S_maz_322_1 = {array_m322_x_1,&R0MW12IP1,&iRM_3_,&var1279};
_S_maz  S_maz_313_1 = {array_m313_x_1,&R0MW12IP1,&iRM_3_,&var1280};
_S_rs  S_rs_1501_1 = {&var542,&var1019,&var1281,&vainSBool,&internal1_m1501_q0};
_S_kvf  S_kvf_1504_1 = {&var1281,&var539,&fRM_0_0,&var1282,&vainSInt,&vainSInt,&internal1_m1504_x0,&internal1_m1504_y0,&bFirstEnterFlag};
_S_kvf  S_kvf_1930_1 = {&var456,&var444,&fRM_0_0,&var1283,&vainSInt,&vainSInt,&internal1_m1930_x0,&internal1_m1930_y0,&bFirstEnterFlag};
_S_kvf  S_kvf_1891_1 = {&var416,&var413,&fRM_0_0,&var1284,&vainSInt,&vainSInt,&internal1_m1891_x0,&internal1_m1891_y0,&bFirstEnterFlag};
_S_equz_p  S_equz_p_43_1 = {&R0MW13IP1,&iRM_1_,&var1285};
_S_noto  S_noto_40_1 = {&var1288,&var1286};
_S_equz_p  S_equz_p_47_1 = {&R0MW13IP1,&iRM_2_,&var1287};
_S_equz_p  S_equz_p_38_1 = {&R0MW13IP1,&iRM_3_,&var1288};
_S_noto  S_noto_1932_1 = {&var1134,&var1289};
_S_rs  S_rs_298_1 = {&var829,&var830,&var1290,&vainSBool,&internal1_m298_q0};
_S_orn  S_orn_608_1 = {array_m608_x_1,&iRM_5_,&var1291};
_S_noto  S_noto_1017_1 = {&lEM_R0MD01LC1,&var1292};
_S_rs  S_rs_1008_1 = {&var606,&var922,&var1293,&vainSBool,&internal1_m1008_q0};
_S_rs  S_rs_639_1 = {&var784,&var786,&var1294,&vainSBool,&internal1_m639_q0};
_S_noto  S_noto_1407_1 = {&var965,&var1295};
_S_orn  S_orn_1386_1 = {array_m1386_x_1,&iRM_8_,&var1296};
_S_noto  S_noto_1385_1 = {&var1464,&var1297};
_S_noto  S_noto_1384_1 = {&var1474,&var1298};
_S_noto  S_noto_1366_1 = {&var966,&var1299};
_S_noto  S_noto_1376_1 = {&R8IS11LDU,&var1300};
_S_charint  S_charint_1312_1 = {&var1303,&var1301};
_S_ornc  S_ornc_1321_1 = {array_m1321_x_1,&iRM_3_,&var1302,&var1303};
_S_fsumz  S_fsumz_1313_1 = {&var1301,&iRM_1_,&var1304};
_S_cnshd  S_cnshd_1323_1 = {&R0MD34LP1,&var1733,&var996,&var320,&var1302,&var651,&var647,&iRM_1_,array_m1323_Lt_fw_1,array_m1323_Vr_fw_1,&iRM_1_,array_m1323_Lt_bw_1,array_m1323_Vr_bw_1,&fEM_A3UC08RDU,&fEM_A3UC07RDU,&fEM_A3UL01RDU,&fEM_A3UC02RDU,&var1305,&vainSBool,&var1306,&var1307,&var1308,&var1309,&var1310,&var1311,&var1312,&var1313,&var1314,&var1315,&internal1_m1323_X0,&internal1_m1323_t0,&internal1_m1323_BLDv0};
_S_zpfs  S_zpfs_1342_1 = {&var1324,&fRM_2_0,&var1316,&internal1_m1342_tx,&internal1_m1342_y0};
_S_zpfs  S_zpfs_1343_1 = {&var1323,&fRM_3_0,&var1317,&internal1_m1343_tx,&internal1_m1343_y0};
_S_fnapb  S_fnapb_1351_1 = {&var1733,&var996,&var650,&R0MD34LP1,&var1307,&var1314,&fEM_B8UV04RDU,&fEM_A3UV01RDU,&fEM_A3UV02RDU,&fEM_A3UC06RDU,&fEM_A3UC05RDU,&iRM_60_,&fEM_A3UL04RDU,&fEM_A3UL05RDU,&fEM_A3UL03RDU,&var1318,&var1319,&var1320,&var1321,&var1322,&var1323,&var1324,&vainSFloat,&internal1_m1351_xptr,array_m1351_x0_1,array_m1351_tim0_1,&internal1_m1351_sumtim,&internal1_m1351_StSpeed,&internal1_m1351_Vz0,&internal1_m1351_flRazg,&internal1_m1351_DelSp,&internal1_m1351_z0,&internal1_m1351_txZS,&internal1_m1351_tx,&internal1_m1351_txd,&internal1_m1351_txMBl,&internal1_m1351_txBl,&internal1_m1351_Speed0,&internal1_m1351_xz0,&internal1_m1351_tz0,&internal1_m1351_Shift0,&internal1_m1351_ShCntlSp0,&internal1_m1351_ShiftControl,&bFirstEnterFlag};
_S_newstage  S_newstage_918_1 = {&var1334,&var1302,&var1337,&var1305,&var1325};
_S_rs  S_rs_637_1 = {&var785,&var789,&var1326,&vainSBool,&internal1_m637_q0};
_S_noto  S_noto_995_1 = {&var950,&var1327};
_S_orn  S_orn_974_1 = {array_m974_x_1,&iRM_8_,&var1328};
_S_noto  S_noto_973_1 = {&var1464,&var1329};
_S_noto  S_noto_972_1 = {&var1474,&var1330};
_S_noto  S_noto_954_1 = {&var966,&var1331};
_S_noto  S_noto_964_1 = {&R8IS11LDU,&var1332};
_S_charint  S_charint_896_1 = {&var1335,&var1333};
_S_ornc  S_ornc_904_1 = {array_m904_x_1,&iRM_3_,&var1334,&var1335};
_S_fsumz  S_fsumz_897_1 = {&var1333,&iRM_1_,&var1336};
_S_cnshd  S_cnshd_906_1 = {&R0MD34LP1,&var1736,&var995,&var324,&var1334,&var686,&var687,&iRM_1_,array_m906_Lt_fw_1,array_m906_Vr_fw_1,&iRM_1_,array_m906_Lt_bw_1,array_m906_Vr_bw_1,&fEM_A3UC08RDU,&fEM_A3UC07RDU,&fEM_A3UL01RDU,&fEM_A3UC02RDU,&var1337,&vainSBool,&var1338,&var1339,&var1340,&var1341,&var1342,&var1343,&var1344,&var1345,&var1346,&var1347,&internal1_m906_X0,&internal1_m906_t0,&internal1_m906_BLDv0};
_S_zpfs  S_zpfs_930_1 = {&var1356,&fRM_2_0,&var1348,&internal1_m930_tx,&internal1_m930_y0};
_S_zpfs  S_zpfs_931_1 = {&var1355,&fRM_3_0,&var1349,&internal1_m931_tx,&internal1_m931_y0};
_S_fnapb  S_fnapb_939_1 = {&var1736,&var995,&var685,&R0MD34LP1,&var1339,&var1346,&fEM_B8UV04RDU,&fEM_A3UV01RDU,&fEM_A3UV02RDU,&fEM_A3UC06RDU,&fEM_A3UC05RDU,&iRM_60_,&fEM_A3UL04RDU,&fEM_A3UL05RDU,&fEM_A3UL03RDU,&var1350,&var1351,&var1352,&var1353,&var1354,&var1355,&var1356,&vainSFloat,&internal1_m939_xptr,array_m939_x0_1,array_m939_tim0_1,&internal1_m939_sumtim,&internal1_m939_StSpeed,&internal1_m939_Vz0,&internal1_m939_flRazg,&internal1_m939_DelSp,&internal1_m939_z0,&internal1_m939_txZS,&internal1_m939_tx,&internal1_m939_txd,&internal1_m939_txMBl,&internal1_m939_txBl,&internal1_m939_Speed0,&internal1_m939_xz0,&internal1_m939_tz0,&internal1_m939_Shift0,&internal1_m939_ShCntlSp0,&internal1_m939_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_590_1 = {&var965,&var1357};
_S_noto  S_noto_563_1 = {&var1464,&var1358};
_S_noto  S_noto_562_1 = {&var1474,&var1359};
_S_noto  S_noto_547_1 = {&var966,&var1360};
_S_noto  S_noto_554_1 = {&R8IS11LDU,&var1361};
_S_charint  S_charint_499_1 = {&var1364,&var1362};
_S_ornc  S_ornc_505_1 = {array_m505_x_1,&iRM_3_,&var1363,&var1364};
_S_fsumz  S_fsumz_500_1 = {&var1362,&iRM_1_,&var1365};
_S_cnshd  S_cnshd_508_1 = {&R0MD34LP1,&var1746,&var997,&var328,&var1363,&var757,&var751,&iRM_2_,array_m508_Lt_fw_1,array_m508_Vr_fw_1,&iRM_1_,array_m508_Lt_bw_1,array_m508_Vr_bw_1,&fEM_A1UC08RDU,&fEM_A1UC07RDU,&fEM_A1UL01RDU,&fEM_A1UC02RDU,&var1366,&vainSBool,&var1367,&var1368,&var1369,&var1370,&var1371,&var1372,&var1373,&var1374,&var1375,&var1376,&internal1_m508_X0,&internal1_m508_t0,&internal1_m508_BLDv0};
_S_zpfs  S_zpfs_528_1 = {&var1385,&fRM_2_0,&var1377,&internal1_m528_tx,&internal1_m528_y0};
_S_zpfs  S_zpfs_529_1 = {&var1384,&fRM_3_0,&var1378,&internal1_m529_tx,&internal1_m529_y0};
_S_fnapb  S_fnapb_535_1 = {&var1746,&var997,&var755,&R0MD34LP1,&var1368,&var1375,&fEM_B8UV04RDU,&fEM_A1UV01RDU,&fEM_A1UV02RDU,&fEM_A1UC06RDU,&fEM_A1UC05RDU,&iRM_150_,&fEM_A1UL04RDU,&fEM_A1UL05RDU,&fEM_A1UL03RDU,&var1379,&var1380,&var1381,&var1382,&var1383,&var1384,&var1385,&vainSFloat,&internal1_m535_xptr,array_m535_x0_1,array_m535_tim0_1,&internal1_m535_sumtim,&internal1_m535_StSpeed,&internal1_m535_Vz0,&internal1_m535_flRazg,&internal1_m535_DelSp,&internal1_m535_z0,&internal1_m535_txZS,&internal1_m535_tx,&internal1_m535_txd,&internal1_m535_txMBl,&internal1_m535_txBl,&internal1_m535_Speed0,&internal1_m535_xz0,&internal1_m535_tz0,&internal1_m535_Shift0,&internal1_m535_ShCntlSp0,&internal1_m535_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_655_1 = {&R0MD33LP1,&var1386};
_S_noto  S_noto_276_1 = {&var950,&var1387};
_S_newstage  S_newstage_221_1 = {&var1396,&var1363,&var1399,&var1366,&var1388};
_S_rs  S_rs_634_1 = {&var780,&var792,&var1389,&vainSBool,&internal1_m634_q0};
_S_orn  S_orn_247_1 = {array_m247_x_1,&iRM_12_,&var1390};
_S_noto  S_noto_246_1 = {&var1464,&var1391};
_S_noto  S_noto_245_1 = {&var1474,&var1392};
_S_noto  S_noto_230_1 = {&var966,&var1393};
_S_noto  S_noto_237_1 = {&R8IS11LDU,&var1394};
_S_charint  S_charint_163_1 = {&var1397,&var1395};
_S_ornc  S_ornc_170_1 = {array_m170_x_1,&iRM_3_,&var1396,&var1397};
_S_fsumz  S_fsumz_164_1 = {&var1395,&iRM_1_,&var1398};
_S_cnshd  S_cnshd_174_1 = {&R0MD34LP1,&var1724,&var998,&var332,&var1396,&var737,&var730,&iRM_2_,array_m174_Lt_fw_1,array_m174_Vr_fw_1,&iRM_1_,array_m174_Lt_bw_1,array_m174_Vr_bw_1,&fEM_A1UC08RDU,&fEM_A1UC07RDU,&fEM_A1UL01RDU,&fEM_A1UC02RDU,&var1399,&vainSBool,&var1400,&var1401,&var1402,&var1403,&var1404,&var1405,&var1406,&var1407,&var1408,&var1409,&internal1_m174_X0,&internal1_m174_t0,&internal1_m174_BLDv0};
_S_fnapb  S_fnapb_213_1 = {&var1724,&var998,&var733,&R0MD34LP1,&var1401,&var1408,&fEM_B8UV04RDU,&fEM_A1UV01RDU,&fEM_A1UV02RDU,&fEM_A1UC06RDU,&fEM_A1UC05RDU,&iRM_150_,&fEM_A1UL04RDU,&fEM_A1UL05RDU,&fEM_A1UL03RDU,&var1410,&var1411,&var1412,&var1413,&var1414,&var1415,&var1416,&vainSFloat,&internal1_m213_xptr,array_m213_x0_1,array_m213_tim0_1,&internal1_m213_sumtim,&internal1_m213_StSpeed,&internal1_m213_Vz0,&internal1_m213_flRazg,&internal1_m213_DelSp,&internal1_m213_z0,&internal1_m213_txZS,&internal1_m213_tx,&internal1_m213_txd,&internal1_m213_txMBl,&internal1_m213_txBl,&internal1_m213_Speed0,&internal1_m213_xz0,&internal1_m213_tz0,&internal1_m213_Shift0,&internal1_m213_ShCntlSp0,&internal1_m213_ShiftControl,&bFirstEnterFlag};
_S_rs  S_rs_660_1 = {&var791,&var794,&var1417,&vainSBool,&internal1_m660_q0};
_S_newstage  S_newstage_475_1 = {&var1436,&var1427,&var1435,&var1426,&var1418};
_S_samhd  S_samhd_479_1 = {&R0MD34LP1,&var760,&var760,&var383,&var382,&R2VS12LDU,&R2VS22LDU,&R2IS11LDU,&R2IS11LDU,&R2IS21LDU,&R2IS21LDU,&bRM_0_,&fEM_R1UZ05RDU,&fEM_R1UZ03RDU,&fEM_R1UZ04RDU,&var1419,&var1420,&var1421,&var1422,&var1423,&var1424,&vainSBool,&vainSBool,&var1425,&var1426,&var1427,&internal1_m479_DvUp0,&internal1_m479_DvDw0,&internal1_m479_FDvUp0,&internal1_m479_FDvDw0,&internal1_m479_BlDv0,&internal1_m479_Pkv0,&internal1_m479_Pkav0,&internal1_m479_Zkv0,&internal1_m479_Zkav0,&internal1_m479_txNm,&internal1_m479_txSm,&internal1_m479_txHr,&internal1_m479_txLd,&internal1_m479_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_473_1 = {&R0MD34LP1,&var761,&var761,&var381,&var380,&R1VS12LDU,&R1VS22LDU,&R1IS11LDU,&R1IS11LDU,&R1IS21LDU,&R1IS21LDU,&bRM_0_,&fEM_R1UZ05RDU,&fEM_R1UZ03RDU,&fEM_R1UZ04RDU,&var1428,&var1429,&var1430,&var1431,&var1432,&var1433,&vainSBool,&vainSBool,&var1434,&var1435,&var1436,&internal1_m473_DvUp0,&internal1_m473_DvDw0,&internal1_m473_FDvUp0,&internal1_m473_FDvDw0,&internal1_m473_BlDv0,&internal1_m473_Pkv0,&internal1_m473_Pkav0,&internal1_m473_Zkv0,&internal1_m473_Zkav0,&internal1_m473_txNm,&internal1_m473_txSm,&internal1_m473_txHr,&internal1_m473_txLd,&internal1_m473_fef,&bFirstEnterFlag};
_S_orn  S_orn_879_1 = {array_m879_x_1,&iRM_10_,&var1437};
_S_noto  S_noto_878_1 = {&var1464,&var1438};
_S_noto  S_noto_877_1 = {&var1474,&var1439};
_S_noto  S_noto_858_1 = {&var966,&var1440};
_S_noto  S_noto_869_1 = {&R8IS11LDU,&var1441};
_S_charint  S_charint_816_1 = {&var1444,&var1442};
_S_ornc  S_ornc_822_1 = {array_m822_x_1,&iRM_3_,&var1443,&var1444};
_S_fsumz  S_fsumz_817_1 = {&var1442,&iRM_1_,&var1445};
_S_cnshd  S_cnshd_826_1 = {&R0MD34LP1,&var1739,&var994,&var994,&var1443,&var710,&var624,&iRM_2_,array_m826_Lt_fw_1,array_m826_Vr_fw_1,&iRM_1_,array_m826_Lt_bw_1,array_m826_Vr_bw_1,&fEM_A2UC08RDU,&fEM_A2UC07RDU,&fEM_A2UL01RDU,&fEM_A2UC02RDU,&var1446,&vainSBool,&var1447,&var1448,&var1449,&var1450,&var1451,&var1452,&var1453,&var1454,&var1455,&var1456,&internal1_m826_X0,&internal1_m826_t0,&internal1_m826_BLDv0};
_S_fnapb  S_fnapb_846_1 = {&var1739,&var994,&var706,&R0MD34LP1,&var1448,&var1455,&fEM_B8UV04RDU,&fEM_A2UV01RDU,&fEM_A2UV02RDU,&fEM_A2UC06RDU,&fEM_A2UC05RDU,&iRM_80_,&fEM_A2UL04RDU,&fEM_A2UL05RDU,&fEM_A2UL83RDU,&var1457,&var1458,&var1459,&var1460,&var1461,&var1462,&var1463,&vainSFloat,&internal1_m846_xptr,array_m846_x0_1,array_m846_tim0_1,&internal1_m846_sumtim,&internal1_m846_StSpeed,&internal1_m846_Vz0,&internal1_m846_flRazg,&internal1_m846_DelSp,&internal1_m846_z0,&internal1_m846_txZS,&internal1_m846_tx,&internal1_m846_txd,&internal1_m846_txMBl,&internal1_m846_txBl,&internal1_m846_Speed0,&internal1_m846_xz0,&internal1_m846_tz0,&internal1_m846_Shift0,&internal1_m846_ShCntlSp0,&internal1_m846_ShiftControl,&bFirstEnterFlag};
_S_cnshd  S_cnshd_1605_1 = {&R0MD34LP1,&var1730,&var316,&var316,&var533,&var536,&lRM_1_,&iRM_1_,array_m1605_Lt_fw_1,array_m1605_Vr_fw_1,&iRM_1_,array_m1605_Lt_bw_1,array_m1605_Vr_bw_1,&fEM_B8UC01RDU,&fEM_B8UC02RDU,&fEM_B8UL01RDU,&fRM_0_0,&var1464,&vainSBool,&vainSFloat,&var1465,&var1466,&var1467,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1468,&internal1_m1605_X0,&internal1_m1605_t0,&internal1_m1605_BLDv0};
_S_newstage  S_newstage_1266_1 = {&var1482,&var1443,&var1487,&var1446,&var1469};
_S_orn  S_orn_1296_1 = {array_m1296_x_1,&iRM_10_,&var1470};
_S_orn  S_orn_152_1 = {array_m152_x_1,&iRM_5_,&var1471};
_S_noto  S_noto_1295_1 = {&var1464,&var1472};
_S_noto  S_noto_1294_1 = {&var1474,&var1473};
_S_cnshd  S_cnshd_1126_1 = {&R0MD34LP1,&var1727,&var316,&var316,&var851,&var534,&lRM_1_,&iRM_1_,array_m1126_Lt_fw_1,array_m1126_Vr_fw_1,&iRM_1_,array_m1126_Lt_bw_1,array_m1126_Vr_bw_1,&fEM_B8UC01RDU,&fEM_B8UC02RDU,&fEM_B8UL01RDU,&fRM_0_0,&var1474,&vainSBool,&vainSFloat,&var1475,&var1476,&var1477,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1478,&internal1_m1126_X0,&internal1_m1126_t0,&internal1_m1126_BLDv0};
_S_noto  S_noto_1276_1 = {&var966,&var1479};
_S_noto  S_noto_1286_1 = {&R8IS11LDU,&var1480};
_S_charint  S_charint_1216_1 = {&var1483,&var1481};
_S_ornc  S_ornc_1224_1 = {array_m1224_x_1,&iRM_3_,&var1482,&var1483};
_S_noto  S_noto_619_1 = {&lEM_R0MD01LC1,&var1484};
_S_fsumz  S_fsumz_1217_1 = {&var1481,&iRM_1_,&var1485};
_S_rs  S_rs_632_1 = {&var802,&var804,&var1486,&vainSBool,&internal1_m632_q0};
_S_cnshd  S_cnshd_1226_1 = {&R0MD34LP1,&var1742,&var993,&var993,&var1482,&var627,&var620,&iRM_2_,array_m1226_Lt_fw_1,array_m1226_Vr_fw_1,&iRM_1_,array_m1226_Lt_bw_1,array_m1226_Vr_bw_1,&fEM_A2UC08RDU,&fEM_A2UC07RDU,&fEM_A2UL01RDU,&fEM_A2UC02RDU,&var1487,&vainSBool,&var1488,&var1489,&var1490,&var1491,&var1492,&var1493,&var1494,&var1495,&var1496,&var1497,&internal1_m1226_X0,&internal1_m1226_t0,&internal1_m1226_BLDv0};
_S_zpfs  S_zpfs_1246_1 = {&var1506,&fRM_2_0,&var1498,&internal1_m1246_tx,&internal1_m1246_y0};
_S_zpfs  S_zpfs_1255_1 = {&var1505,&fRM_3_0,&var1499,&internal1_m1255_tx,&internal1_m1255_y0};
_S_fnapb  S_fnapb_1261_1 = {&var1742,&var993,&var628,&R0MD34LP1,&var1489,&var1496,&fEM_B8UV04RDU,&fEM_A2UV01RDU,&fEM_A2UV02RDU,&fEM_A2UC06RDU,&fEM_A2UC05RDU,&iRM_80_,&fEM_A2UL04RDU,&fEM_A2UL05RDU,&fEM_A2UL03RDU,&var1500,&var1501,&var1502,&var1503,&var1504,&var1505,&var1506,&vainSFloat,&internal1_m1261_xptr,array_m1261_x0_1,array_m1261_tim0_1,&internal1_m1261_sumtim,&internal1_m1261_StSpeed,&internal1_m1261_Vz0,&internal1_m1261_flRazg,&internal1_m1261_DelSp,&internal1_m1261_z0,&internal1_m1261_txZS,&internal1_m1261_tx,&internal1_m1261_txd,&internal1_m1261_txMBl,&internal1_m1261_txBl,&internal1_m1261_Speed0,&internal1_m1261_xz0,&internal1_m1261_tz0,&internal1_m1261_Shift0,&internal1_m1261_ShCntlSp0,&internal1_m1261_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_1590_1 = {&R8IS11LDU,&var1507};
_S_rs  S_rs_652_1 = {&var805,&var806,&var1508,&vainSBool,&internal1_m652_q0};
_S_zpfs  S_zpfs_1618_1 = {&var1519,&fRM_2_0,&var1509,&internal1_m1618_tx,&internal1_m1618_y0};
_S_zpfs  S_zpfs_1622_1 = {&var1518,&fRM_3_0,&var1510,&internal1_m1622_tx,&internal1_m1622_y0};
_S_samhd  S_samhd_1608_1 = {&R0MD34LP1,&var536,&var536,&var1466,&var1467,&var1513,&var1514,&A8IS12LDU,&A8IS12LDU,&A8IS22LDU,&A8IS22LDU,&bRM_3_,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&fEM_B8UL07RDU,&vainSBool,&vainSBool,&var1511,&var1512,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,&internal1_m1608_DvUp0,&internal1_m1608_DvDw0,&internal1_m1608_FDvUp0,&internal1_m1608_FDvDw0,&internal1_m1608_BlDv0,&internal1_m1608_Pkv0,&internal1_m1608_Pkav0,&internal1_m1608_Zkv0,&internal1_m1608_Zkav0,&internal1_m1608_txNm,&internal1_m1608_txSm,&internal1_m1608_txHr,&internal1_m1608_txLd,&internal1_m1608_fef,&bFirstEnterFlag};
_S_fnapb  S_fnapb_1625_1 = {&var1730,&var316,&var532,&R0MD34LP1,&var1465,&fEM_B8UV03RDU,&fEM_B8UV04RDU,&fEM_B8UV01RDU,&fEM_B8UV02RDU,&fEM_B8UC06RDU,&fEM_B8UC05RDU,&iRM_20_,&fEM_B8UL04RDU,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&var1513,&var1514,&var1515,&var1516,&var1517,&var1518,&var1519,&vainSFloat,&internal1_m1625_xptr,array_m1625_x0_1,array_m1625_tim0_1,&internal1_m1625_sumtim,&internal1_m1625_StSpeed,&internal1_m1625_Vz0,&internal1_m1625_flRazg,&internal1_m1625_DelSp,&internal1_m1625_z0,&internal1_m1625_txZS,&internal1_m1625_tx,&internal1_m1625_txd,&internal1_m1625_txMBl,&internal1_m1625_txBl,&internal1_m1625_Speed0,&internal1_m1625_xz0,&internal1_m1625_tz0,&internal1_m1625_Shift0,&internal1_m1625_ShCntlSp0,&internal1_m1625_ShiftControl,&bFirstEnterFlag};
_S_zpfs  S_zpfs_1142_1 = {&var1536,&fRM_2_0,&var1520,&internal1_m1142_tx,&internal1_m1142_y0};
_S_zpfs  S_zpfs_1147_1 = {&var1535,&fRM_3_0,&var1521,&internal1_m1147_tx,&internal1_m1147_y0};
_S_noto  S_noto_1111_1 = {&R8IS11LDU,&var1522};
_S_orn  S_orn_1097_1 = {array_m1097_x_1,&iRM_8_,&var1523};
_S_noto  S_noto_621_1 = {&var1527,&var1524};
_S_rs  S_rs_642_1 = {&var807,&var808,&var1525,&vainSBool,&internal1_m642_q0};
_S_orn  S_orn_609_1 = {array_m609_x_1,&iRM_18_,&var1526};
_S_rs  S_rs_607_1 = {&var1291,&var923,&var1527,&vainSBool,&internal1_m607_q0};
_S_samhd  S_samhd_1132_1 = {&R0MD34LP1,&var534,&var534,&var1476,&var1477,&var1530,&var1531,&var159,&var159,&var158,&var158,&bRM_3_,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&fEM_B8UL07RDU,&vainSBool,&vainSBool,&var1528,&var1529,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,&internal1_m1132_DvUp0,&internal1_m1132_DvDw0,&internal1_m1132_FDvUp0,&internal1_m1132_FDvDw0,&internal1_m1132_BlDv0,&internal1_m1132_Pkv0,&internal1_m1132_Pkav0,&internal1_m1132_Zkv0,&internal1_m1132_Zkav0,&internal1_m1132_txNm,&internal1_m1132_txSm,&internal1_m1132_txHr,&internal1_m1132_txLd,&internal1_m1132_fef,&bFirstEnterFlag};
_S_fnapb  S_fnapb_1150_1 = {&var1727,&var316,&var850,&R0MD34LP1,&var1475,&fEM_B8UV03RDU,&fEM_B8UV04RDU,&fEM_B8UV01RDU,&fEM_B8UV02RDU,&fEM_B8UC06RDU,&fEM_B8UC05RDU,&iRM_20_,&fEM_B8UL04RDU,&fEM_B8UL06RDU,&fEM_B8UL03RDU,&var1530,&var1531,&var1532,&var1533,&var1534,&var1535,&var1536,&vainSFloat,&internal1_m1150_xptr,array_m1150_x0_1,array_m1150_tim0_1,&internal1_m1150_sumtim,&internal1_m1150_StSpeed,&internal1_m1150_Vz0,&internal1_m1150_flRazg,&internal1_m1150_DelSp,&internal1_m1150_z0,&internal1_m1150_txZS,&internal1_m1150_tx,&internal1_m1150_txd,&internal1_m1150_txMBl,&internal1_m1150_txBl,&internal1_m1150_Speed0,&internal1_m1150_xz0,&internal1_m1150_tz0,&internal1_m1150_Shift0,&internal1_m1150_ShCntlSp0,&internal1_m1150_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_732_1 = {&A5IS21LDU,&var1537};
_S_vmemb  S_vmemb_755_1 = {&var1539,&var1538,&internal1_m755_x0};
_S_noto  S_noto_763_1 = {&var160,&var1539};
_S_vmemb  S_vmemb_724_1 = {&var1537,&var1540,&internal1_m724_x0};
_S_vmemb  S_vmemb_688_1 = {&var1555,&var1541,&internal1_m688_x0};
_S_newstage  S_newstage_798_1 = {&var1599,&var1590,&var1598,&var1589,&var1542};
_S_newstage  S_newstage_1198_1 = {&var1581,&var1572,&var1580,&var1571,&var1543};
_S_newstage  S_newstage_404_1 = {&var1626,&var1617,&var1625,&var1616,&var1544};
_S_noto  S_noto_774_1 = {&var161,&var1545};
_S_rs  S_rs_780_1 = {&var871,&var1544,&var1546,&vainSBool,&internal1_m780_q0};
_S_rs  S_rs_775_1 = {&var872,&var972,&var1547,&vainSBool,&internal1_m775_q0};
_S_noto  S_noto_767_1 = {&var1628,&var1548};
_S_noto  S_noto_765_1 = {&var1629,&var1549};
_S_rs  S_rs_743_1 = {&var876,&var1544,&var1550,&vainSBool,&internal1_m743_q0};
_S_rs  S_rs_747_1 = {&var875,&var1542,&var1551,&vainSBool,&internal1_m747_q0};
_S_rs  S_rs_756_1 = {&var942,&var881,&var1552,&vainSBool,&internal1_m756_q0};
_S_rs  S_rs_768_1 = {&var873,&var879,&var1553,&vainSBool,&internal1_m768_q0};
_S_noto  S_noto_723_1 = {&var161,&var1554};
_S_noto  S_noto_679_1 = {&var160,&var1555};
_S_noto  S_noto_435_1 = {&R8IS11LDU,&var1556};
_S_orn  S_orn_449_1 = {array_m449_x_1,&iRM_7_,&var1557};
_S_orn  S_orn_431_1 = {array_m431_x_1,&iRM_7_,&var1558};
_S_rs  S_rs_745_1 = {&var880,&var885,&var1559,&vainSBool,&internal1_m745_q0};
_S_noto  S_noto_160_1 = {&B2IS12LDU,&var1560};
_S_noto  S_noto_149_1 = {&A2IS12LDU,&var1561};
_S_noto  S_noto_150_1 = {&B1IS12LDU,&var1562};
_S_noto  S_noto_158_1 = {&A1IS12LDU,&var1563};
_S_samhd  S_samhd_1202_1 = {&var854,&var855,&var855,&var1164,&var1163,&var1164,&var1163,&B4IS11LDU,&B4IS11LDU,&B4IS21LDU,&B4IS21LDU,&bRM_1_,&fEM_A4UZ05RDU,&fEM_A4UZ03RDU,&fEM_A4UZ04RDU,&var1564,&var1565,&vainSBool,&var1566,&var1567,&vainSBool,&var1568,&var1569,&var1570,&var1571,&var1572,&internal1_m1202_DvUp0,&internal1_m1202_DvDw0,&internal1_m1202_FDvUp0,&internal1_m1202_FDvDw0,&internal1_m1202_BlDv0,&internal1_m1202_Pkv0,&internal1_m1202_Pkav0,&internal1_m1202_Zkv0,&internal1_m1202_Zkav0,&internal1_m1202_txNm,&internal1_m1202_txSm,&internal1_m1202_txHr,&internal1_m1202_txLd,&internal1_m1202_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_1192_1 = {&var854,&var857,&var857,&var1164,&var1163,&var1164,&var1163,&A4IS11LDU,&A4IS11LDU,&A4IS21LDU,&A4IS21LDU,&bRM_1_,&fEM_A4UZ05RDU,&fEM_A4UZ03RDU,&fEM_A4UZ04RDU,&var1573,&var1574,&vainSBool,&var1575,&var1576,&vainSBool,&var1577,&var1578,&var1579,&var1580,&var1581,&internal1_m1192_DvUp0,&internal1_m1192_DvDw0,&internal1_m1192_FDvUp0,&internal1_m1192_FDvDw0,&internal1_m1192_BlDv0,&internal1_m1192_Pkv0,&internal1_m1192_Pkav0,&internal1_m1192_Zkv0,&internal1_m1192_Zkav0,&internal1_m1192_txNm,&internal1_m1192_txSm,&internal1_m1192_txHr,&internal1_m1192_txLd,&internal1_m1192_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_800_1 = {&R0MD34LP1,&var712,&var712,&var973,&var868,&B5VS12LDU,&B5VS22LDU,&B5IS11LDU,&B5IS11LDU,&B5IS21LDU,&B5IS21LDU,&bRM_0_,&fEM_A5UZ05RDU,&fEM_A5UZ03RDU,&fEM_A5UZ04RDU,&var1582,&var1583,&var1584,&var1585,&var1586,&var1587,&vainSBool,&vainSBool,&var1588,&var1589,&var1590,&internal1_m800_DvUp0,&internal1_m800_DvDw0,&internal1_m800_FDvUp0,&internal1_m800_FDvDw0,&internal1_m800_BlDv0,&internal1_m800_Pkv0,&internal1_m800_Pkav0,&internal1_m800_Zkv0,&internal1_m800_Zkav0,&internal1_m800_txNm,&internal1_m800_txSm,&internal1_m800_txHr,&internal1_m800_txLd,&internal1_m800_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_796_1 = {&R0MD34LP1,&var714,&var714,&var973,&var868,&A5VS12LDU,&A5VS22LDU,&A5IS11LDU,&A5IS11LDU,&A5IS21LDU,&A5IS21LDU,&bRM_0_,&fEM_A5UZ05RDU,&fEM_A5UZ03RDU,&fEM_A5UZ04RDU,&var1591,&var1592,&var1593,&var1594,&var1595,&var1596,&vainSBool,&vainSBool,&var1597,&var1598,&var1599,&internal1_m796_DvUp0,&internal1_m796_DvDw0,&internal1_m796_FDvUp0,&internal1_m796_FDvDw0,&internal1_m796_BlDv0,&internal1_m796_Pkv0,&internal1_m796_Pkav0,&internal1_m796_Zkv0,&internal1_m796_Zkav0,&internal1_m796_txNm,&internal1_m796_txSm,&internal1_m796_txHr,&internal1_m796_txLd,&internal1_m796_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_378_1 = {&R0MD34LP1,&var385,&var384,&var877,&var870,&R4VS12LDU,&R4VS22LDU,&R4IS11LDU,&R4IS12LDU,&R4IS21LDU,&R4IS22LDU,&bRM_0_,&fEM_R4UZ05RDU,&fEM_R4UZ03RDU,&fEM_R4UZ04RDU,&var1600,&var1601,&var1602,&var1603,&var1604,&var1605,&vainSBool,&vainSBool,&var1606,&var1607,&vainSBool,&internal1_m378_DvUp0,&internal1_m378_DvDw0,&internal1_m378_FDvUp0,&internal1_m378_FDvDw0,&internal1_m378_BlDv0,&internal1_m378_Pkv0,&internal1_m378_Pkav0,&internal1_m378_Zkv0,&internal1_m378_Zkav0,&internal1_m378_txNm,&internal1_m378_txSm,&internal1_m378_txHr,&internal1_m378_txLd,&internal1_m378_fef,&bFirstEnterFlag};
_S_noto  S_noto_690_1 = {&R8IS11LDU,&var1608};
_S_samhd  S_samhd_407_1 = {&R0MD34LP1,&var1557,&var943,&var949,&var869,&B6VS12LDU,&B6VS22LDU,&B6IS11LDU,&B6IS11LDU,&B6IS21LDU,&B6IS21LDU,&bRM_0_,&fEM_A6UZ05RDU,&fEM_A6UZ03RDU,&fEM_A6UZ04RDU,&var1609,&var1610,&var1611,&var1612,&var1613,&var1614,&vainSBool,&vainSBool,&var1615,&var1616,&var1617,&internal1_m407_DvUp0,&internal1_m407_DvDw0,&internal1_m407_FDvUp0,&internal1_m407_FDvDw0,&internal1_m407_BlDv0,&internal1_m407_Pkv0,&internal1_m407_Pkav0,&internal1_m407_Zkv0,&internal1_m407_Zkav0,&internal1_m407_txNm,&internal1_m407_txSm,&internal1_m407_txHr,&internal1_m407_txLd,&internal1_m407_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_401_1 = {&R0MD34LP1,&var1558,&var944,&var949,&var869,&A6VS12LDU,&A6VS22LDU,&A6IS11LDU,&A6IS11LDU,&A6IS21LDU,&A6IS21LDU,&bRM_0_,&fEM_A6UZ05RDU,&fEM_A6UZ03RDU,&fEM_A6UZ04RDU,&var1618,&var1619,&var1620,&var1621,&var1622,&var1623,&vainSBool,&vainSBool,&var1624,&var1625,&var1626,&internal1_m401_DvUp0,&internal1_m401_DvDw0,&internal1_m401_FDvUp0,&internal1_m401_FDvDw0,&internal1_m401_BlDv0,&internal1_m401_Pkv0,&internal1_m401_Pkav0,&internal1_m401_Zkv0,&internal1_m401_Zkav0,&internal1_m401_txNm,&internal1_m401_txSm,&internal1_m401_txHr,&internal1_m401_txLd,&internal1_m401_fef,&bFirstEnterFlag};
_S_orn  S_orn_779_1 = {array_m779_x_1,&iRM_17_,&var1627};
_S_rs  S_rs_752_1 = {&var883,&var70,&var1628,&vainSBool,&internal1_m752_q0};
_S_rs  S_rs_749_1 = {&var884,&var71,&var1629,&vainSBool,&internal1_m749_q0};
_S_orni  S_orni_138_1 = {array_m138_x_1,&iRM_21_,&var1630,&vainSLong};
_S_equz_p  S_equz_p_80_1 = {&R0MW11IP2,&iRM_6_,&var1631};
_S_equz_p  S_equz_p_78_1 = {&R0MW11IP2,&iRM_5_,&var1632};
_S_equz_p  S_equz_p_76_1 = {&R0MW11IP2,&iRM_4_,&var1633};
_S_equz_p  S_equz_p_75_1 = {&R0MW11IP2,&iRM_3_,&var1634};
_S_equz_p  S_equz_p_74_1 = {&R0MW11IP2,&iRM_2_,&var1635};
_S_equz_p  S_equz_p_71_1 = {&R0MW11IP2,&iRM_1_,&var1636};
_S_equz_p  S_equz_p_67_1 = {&R0MW14IP1,&iRM_3_,&var1637};
_S_equz_p  S_equz_p_61_1 = {&R0MW14IP1,&iRM_1_,&vainSBool};
_S_equz_p  S_equz_p_63_1 = {&R0MW14IP1,&iRM_2_,&var1638};
_S_equz_p  S_equz_p_56_1 = {&R0MW11IP1,&iRM_3_,&var1639};
_S_equz_p  S_equz_p_49_1 = {&R0MW11IP1,&iRM_1_,&var1640};
_S_equz_p  S_equz_p_52_1 = {&R0MW11IP1,&iRM_2_,&var1641};
_S_equz_p  S_equz_p_106_1 = {&R0MW16IP1,&iRM_11_,&var1642};
_S_equz_p  S_equz_p_99_1 = {&R0MW16IP1,&iRM_4_,&var1643};
_S_equz_p  S_equz_p_98_1 = {&R0MW16IP1,&iRM_3_,&var1644};
_S_equz_p  S_equz_p_97_1 = {&R0MW16IP1,&iRM_2_,&var1645};
_S_equz_p  S_equz_p_10_1 = {&R0MW12IP1,&iRM_4_,&var1646};
_S_equz_p  S_equz_p_7_1 = {&R0MW12IP1,&iRM_3_,&var1647};
_S_equz_p  S_equz_p_2_1 = {&R0MW12IP1,&iRM_1_,&var1648};
_S_equz_p  S_equz_p_4_1 = {&R0MW12IP1,&iRM_2_,&var1649};


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
  setData(idR0EE02LDU,&var821);
  setData(idB8VC01RDU,&var1727);
  setData(idB2VC01RDU,&var1739);
  setData(idA2VC01RDU,&var1742);
  setData(idA3VC01RDU,&var1736);
  setData(idB0VS11LDU,&var1704);
  setData(idA0VS11LDU,&var1705);
  setData(idB0VN01LDU,&var1674);
  setData(idA0VN01LDU,&var1676);
  setData(idB0VP01LDU,&var1710);
  setData(idA0VP01LDU,&var1711);
  setData(idB0VE01LDU,&var1701);
  setData(idA0VE01LDU,&var1703);
  setData(idA3VP82LDU,&var1672);
  setData(idB3VP82LDU,&var1695);
  setData(idB3VP52LDU,&var1720);
  setData(idB3CP02RDU,&var1696);
  setData(idB3VP42LDU,&var1670);
  setData(idA3VP52LDU,&var1723);
  setData(idA3CP02RDU,&var1697);
  setData(idA3VP42LDU,&var1671);
  setData(idA1VC01RDU,&var1724);
  setData(idA8VC01RDU,&var1730);
  setData(idB3VC01RDU,&var1733);
  setData(idB1VC01RDU,&var1746);
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
  noto(&S_noto_765_1);
  noto(&S_noto_732_1);
  noto(&S_noto_1111_1);
  noto(&S_noto_1590_1);
  noto(&S_noto_1286_1);
  noto(&S_noto_869_1);
  noto(&S_noto_237_1);
  noto(&S_noto_554_1);
  noto(&S_noto_964_1);
  rs(&S_rs_637_1);
  noto(&S_noto_1376_1);
  equz_p(&S_equz_p_38_1);
  equz_p(&S_equz_p_47_1);
  noto(&S_noto_40_1);
  equz_p(&S_equz_p_43_1);
  rs(&S_rs_1501_1);
  noto(&S_noto_1795_1);
  noto(&S_noto_1794_1);
  noto(&S_noto_1800_1);
  noto(&S_noto_1796_1);
  noto(&S_noto_1802_1);
  noto(&S_noto_1773_1);
  noto(&S_noto_1774_1);
  noto(&S_noto_1775_1);
  noto(&S_noto_1776_1);
  noto(&S_noto_1777_1);
  noto(&S_noto_2091_1);
  equz_p(&S_equz_p_100_1);
  equz_p(&S_equz_p_101_1);
  equz_p(&S_equz_p_102_1);
  noto(&S_noto_941_1);
  equz_p(&S_equz_p_103_1);
  equz_p(&S_equz_p_104_1);
  noto(&S_noto_190_1);
  equz_p(&S_equz_p_105_1);
  noto(&S_noto_12_1);
  noto(&S_noto_1875_1);
  equz_p(&S_equz_p_1817_1);
  equz_p(&S_equz_p_1816_1);
  equz_p(&S_equz_p_1818_1);
  equz_p(&S_equz_p_1819_1);
  equz_p(&S_equz_p_1820_1);
  noto(&S_noto_1782_1);
  noto(&S_noto_1834_1);
  noto(&S_noto_1854_1);
  rs(&S_rs_627_1);
  noto(&S_noto_1814_1);
  noto(&S_noto_1840_1);
  noto(&S_noto_1353_1);
  rsun(&S_rsun_1426_1);
  rs(&S_rs_629_1);
  rs(&S_rs_631_1);
  rs(&S_rs_647_1);
  rs(&S_rs_662_1);
  rs(&S_rs_636_1);
  rs(&S_rs_651_1);
  rs(&S_rs_29_1);
  rs(&S_rs_1495_1);
  rs(&S_rs_1450_1);
  rs(&S_rs_1908_1);
  noto(&S_noto_1445_1);
  noto(&S_noto_1485_1);
  noto(&S_noto_1490_1);
  noto(&S_noto_1866_1);
  noto(&S_noto_1903_1);
  noto(&S_noto_1922_1);
  noto(&S_noto_1888_1);
  noto(&S_noto_598_1);
  noto(&S_noto_25_1);
  noto(&S_noto_26_1);
  noto(&S_noto_27_1);
  noto(&S_noto_28_1);
  noto(&S_noto_601_1);
  noto(&S_noto_599_1);
  noto(&S_noto_55_1);
  noto(&S_noto_277_1);
  noto(&S_noto_280_1);
  noto(&S_noto_289_1);
  noto(&S_noto_294_1);
  noto(&S_noto_285_1);
  noto(&S_noto_998_1);
  noto(&S_noto_1004_1);
  noto(&S_noto_1957_1);
  noto(&S_noto_1959_1);
  rs(&S_rs_1081_1);
  rs(&S_rs_1084_1);
  rs(&S_rs_1087_1);
  rs(&S_rs_1090_1);
  ovbs(&S_ovbs_1200_1);
  ovbs(&S_ovbs_2113_1);
  sr(&S_sr_1073_1);
  bol(&S_bol_1068_1);
  ma(&S_ma_90_1);
  sr(&S_sr_88_1);
  bol(&S_bol_274_1);
  bol(&S_bol_272_1);
  bol(&S_bol_1405_1);
  bol(&S_bol_1403_1);
  bol(&S_bol_993_1);
  bol(&S_bol_991_1);
  bol(&S_bol_586_1);
  bol(&S_bol_588_1);
  bol(&S_bol_597_1);
  bol(&S_bol_603_1);
  and2(&S_and2_753_1);
  and2(&S_and2_30_1);
  and2(&S_and2_31_1);
  and2(&S_and2_32_1);
  and2(&S_and2_33_1);
  and2(&S_and2_48_1);
  and2(&S_and2_44_1);
  and2(&S_and2_744_1);
  or4(&S_or4_434_1);
  or2(&S_or2_757_1);
  or3(&S_or3_5_1);
  or2(&S_or2_6_1);
  or2(&S_or2_1299_1);
  or2(&S_or2_882_1);
  or2(&S_or2_251_1);
  or2(&S_or2_568_1);
  or2(&S_or2_976_1);
  or2(&S_or2_1388_1);
  or2(&S_or2_1072_1);
  and2(&S_and2_1067_1);
  or2(&S_or2_23_1);
  or2(&S_or2_45_1);
  or2(&S_or2_41_1);
  or2(&S_or2_54_1);
  or2(&S_or2_704_1);
  or3(&S_or3_692_1);
  or4(&S_or4_706_1);
  or2(&S_or2_719_1);
  or3(&S_or3_741_1);
  and2(&S_and2_764_1);
  and2(&S_and2_738_1);
  or2(&S_or2_748_1);
  or2(&S_or2_674_1);
  or2(&S_or2_676_1);
  or2(&S_or2_678_1);
  or2(&S_or2_1168_1);
  or2(&S_or2_1201_1);
  and4(&S_and4_1079_1);
  or2(&S_or2_1078_1);
  and2(&S_and2_1093_1);
  or2(&S_or2_1107_1);
  and3(&S_and3_278_1);
  and3(&S_and3_293_1);
  or2(&S_or2_620_1);
  or2(&S_or2_628_1);
  or2(&S_or2_630_1);
  or2(&S_or2_633_1);
  or2(&S_or2_604_1);
  and2(&S_and2_654_1);
  or2(&S_or2_661_1);
  and2(&S_and2_625_1);
  or2(&S_or2_640_1);
  or2(&S_or2_635_1);
  or2(&S_or2_658_1);
  and2(&S_and2_615_1);
  or2(&S_or2_360_1);
  or2(&S_or2_365_1);
  or2(&S_or2_762_1);
  or2(&S_or2_476_1);
  or2(&S_or2_534_1);
  and2(&S_and2_543_1);
  and2(&S_and2_544_1);
  and2(&S_and2_553_1);
  or2(&S_or2_546_1);
  or2(&S_or2_212_1);
  and2(&S_and2_181_1);
  and2(&S_and2_227_1);
  and2(&S_and2_226_1);
  or2(&S_or2_229_1);
  and2(&S_and2_236_1);
  or2(&S_or2_799_1);
  or2(&S_or2_845_1);
  or2(&S_or2_860_1);
  and2(&S_and2_935_1);
  or2(&S_or2_946_1);
  or2(&S_or2_938_1);
  or2(&S_or2_956_1);
  or2(&S_or2_1368_1);
  or2(&S_or2_1350_1);
  and2(&S_and2_1347_1);
  or2(&S_or2_1358_1);
  or2(&S_or2_1275_1);
  or2(&S_or2_1258_1);
  and2(&S_and2_1003_1);
  and2(&S_and2_1446_1);
  zpfs(&S_zpfs_1456_1);
  and2(&S_and2_1486_1);
  zpfs(&S_zpfs_1506_1);
  and2(&S_and2_1491_1);
  zpfs(&S_zpfs_1512_1);
  and2(&S_and2_1528_1);
  or2(&S_or2_2114_1);
  or2(&S_or2_1635_1);
  or2(&S_or2_1636_1);
  or2(&S_or2_1586_1);
  or2(&S_or2_1780_1);
  or2(&S_or2_1781_1);
  or4(&S_or4_1787_1);
  or4(&S_or4_1788_1);
  or2(&S_or2_1790_1);
  or2(&S_or2_1784_1);
  or2(&S_or2_1783_1);
  or3(&S_or3_1792_1);
  and2(&S_and2_1821_1);
  or2(&S_or2_1822_1);
  and2(&S_and2_1828_1);
  and2(&S_and2_1844_1);
  or2(&S_or2_1855_1);
  zpfs(&S_zpfs_1824_1);
  zpfs(&S_zpfs_1825_1);
  zpfs(&S_zpfs_1826_1);
  zpfs(&S_zpfs_1827_1);
  or2(&S_or2_1830_1);
  and2(&S_and2_1831_1);
  or2(&S_or2_1846_1);
  or3(&S_or3_1832_1);
  or2(&S_or2_1909_1);
  ma(&S_ma_1481_1);
  zpfs(&S_zpfs_1879_1);
  and2(&S_and2_1880_1);
  or2(&S_or2_1874_1);
  and3(&S_and3_1877_1);
  or2(&S_or2_1885_1);
  or2(&S_or2_253_1);
  ovbs(&S_ovbs_83_1);
  ovbs(&S_ovbs_24_1);
  ovbs(&S_ovbs_126_1);
  ovbs(&S_ovbs_119_1);
  ovbs(&S_ovbs_1440_1);
  ovbs(&S_ovbs_760_1);
  ovbs(&S_ovbs_312_1);
  ovbs(&S_ovbs_356_1);
  ovbs(&S_ovbs_57_1);
  or2(&S_or2_2021_1);
  or2(&S_or2_2009_1);
  noto(&S_noto_2039_1);
  bol(&S_bol_1574_1);
  bol(&S_bol_1566_1);
  or2(&S_or2_1568_1);
  bol(&S_bol_1554_1);
  bol(&S_bol_1545_1);
  or2(&S_or2_1552_1);
  bol(&S_bol_1572_1);
  bol(&S_bol_1564_1);
  or2(&S_or2_1571_1);
  bol(&S_bol_1558_1);
  bol(&S_bol_1547_1);
  or2(&S_or2_1557_1);
  and4(&S_and4_51_1);
  abs_subf(&S_abs_subf_1563_1);
  noto(&S_noto_1569_1);
  and2(&S_and2_252_1);
  and2(&S_and2_569_1);
  and2(&S_and2_2269_1);
  rs(&S_rs_2218_1);
  sr(&S_sr_2256_1);
  sr(&S_sr_2234_1);
  rs(&S_rs_2212_1);
  zpfs(&S_zpfs_2240_1);
  or2(&S_or2_2227_1);
  abs_subf(&S_abs_subf_2193_1);
  and2(&S_and2_2201_1);
  noto(&S_noto_909_1);
  zzfs(&S_zzfs_2202_1);
  noto(&S_noto_2213_1);
  or2(&S_or2_1091_1);
  or2(&S_or2_385_1);
  or2(&S_or2_368_1);
  or2(&S_or2_1123_1);
  or2(&S_or2_1130_1);
  or2(&S_or2_249_1);
  or2(&S_or2_566_1);
  nocnm(&S_nocnm_1731_1);
  nocnm(&S_nocnm_1734_1);
  noto(&S_noto_1688_1);
  noto(&S_noto_1690_1);
  noto(&S_noto_2185_1);
  noto(&S_noto_2153_1);
  or2(&S_or2_1453_1);
  or2(&S_or2_1484_1);
  noto(&S_noto_2188_1);
  noto(&S_noto_2156_1);
  noto(&S_noto_113_1);
  and2(&S_and2_740_1);
  and2(&S_and2_742_1);
  or2(&S_or2_133_1);
  noto(&S_noto_1749_1);
  noto(&S_noto_1750_1);
  or2(&S_or2_1713_1);
  or2(&S_or2_1753_1);
  or2(&S_or2_1756_1);
  or2(&S_or2_1724_1);
  or2(&S_or2_1727_1);
  or2(&S_or2_1684_1);
  or2(&S_or2_1658_1);
  or2(&S_or2_1654_1);
  or2(&S_or2_2180_1);
  or2(&S_or2_2184_1);
  or2(&S_or2_2182_1);
  or2(&S_or2_2148_1);
  or2(&S_or2_2150_1);
  or2(&S_or2_2152_1);
  noto(&S_noto_1687_1);
  or2(&S_or2_1676_1);
  or2(&S_or2_1674_1);
  noto(&S_noto_1689_1);
  or2(&S_or2_1711_1);
  diagndev(&S_diagndev_2314_1);
  and2(&S_and2_2319_1);
  or2(&S_or2_2328_1);
  or2(&S_or2_2335_1);
  orn(&S_orn_2330_1);
  or3(&S_or3_2331_1);
  noto(&S_noto_1859_1);
  noto(&S_noto_1862_1);
  noto(&S_noto_690_1);
  noto(&S_noto_158_1);
  rs(&S_rs_745_1);
  noto(&S_noto_435_1);
  noto(&S_noto_679_1);
  noto(&S_noto_723_1);
  rs(&S_rs_756_1);
  noto(&S_noto_774_1);
  vmemb(&S_vmemb_688_1);
  vmemb(&S_vmemb_724_1);
  noto(&S_noto_763_1);
  vmemb(&S_vmemb_755_1);
  rs(&S_rs_642_1);
  rs(&S_rs_652_1);
  rs(&S_rs_632_1);
  noto(&S_noto_619_1);
  rs(&S_rs_660_1);
  noto(&S_noto_276_1);
  noto(&S_noto_655_1);
  noto(&S_noto_590_1);
  noto(&S_noto_995_1);
  noto(&S_noto_1407_1);
  noto(&S_noto_1017_1);
  noto(&S_noto_1932_1);
  kvf(&S_kvf_1504_1);
  noto(&S_noto_84_1);
  samhd(&S_samhd_2112_1);
  samhd(&S_samhd_2118_1);
  newstage(&S_newstage_2116_1);
  noto(&S_noto_1793_1);
  noto(&S_noto_1799_1);
  noto(&S_noto_1801_1);
  noto(&S_noto_1772_1);
  noto(&S_noto_1920_1);
  noto(&S_noto_1912_1);
  noto(&S_noto_1870_1);
  noto(&S_noto_521_1);
  noto(&S_noto_1237_1);
  noto(&S_noto_1253_1);
  noto(&S_noto_1842_1);
  rs(&S_rs_1515_1);
  kvf(&S_kvf_1510_1);
  rs(&S_rs_1509_1);
  noto(&S_noto_1520_1);
  noto(&S_noto_1518_1);
  rs(&S_rs_761_1);
  noto(&S_noto_362_1);
  noto(&S_noto_358_1);
  noto(&S_noto_600_1);
  noto(&S_noto_610_1);
  noto(&S_noto_664_1);
  noto(&S_noto_1941_1);
  noto(&S_noto_1966_1);
  swtakt(&S_swtakt_58_1);
  rs(&S_rs_1083_1);
  and2(&S_and2_771_1);
  and2(&S_and2_11_1);
  and2(&S_and2_118_1);
  and2(&S_and2_248_1);
  and2(&S_and2_565_1);
  or2(&S_or2_17_1);
  or2(&S_or2_8_1);
  or2(&S_or2_172_1);
  and3(&S_and3_717_1);
  and2(&S_and2_684_1);
  or3(&S_or3_751_1);
  and2(&S_and2_746_1);
  and2(&S_and2_670_1);
  or2(&S_or2_284_1);
  and3(&S_and3_300_1);
  or2(&S_or2_653_1);
  and2(&S_and2_622_1);
  and2(&S_and2_612_1);
  and4(&S_and4_613_1);
  and4(&S_and4_623_1);
  and2(&S_and2_648_1);
  or2(&S_or2_656_1);
  or2(&S_or2_659_1);
  and3(&S_and3_353_1);
  and2(&S_and2_516_1);
  or2(&S_or2_523_1);
  and2(&S_and2_575_1);
  and2(&S_and2_587_1);
  or2(&S_or2_196_1);
  and2(&S_and2_261_1);
  and2(&S_and2_273_1);
  and2(&S_and2_992_1);
  and2(&S_and2_1389_1);
  and2(&S_and2_1404_1);
  and2(&S_and2_1235_1);
  or2(&S_or2_1241_1);
  and2(&S_and2_1247_1);
  or2(&S_or2_1260_1);
  and2(&S_and2_1012_1);
  and2(&S_and2_1022_1);
  or2(&S_or2_1494_1);
  and2(&S_and2_1457_1);
  and2(&S_and2_1507_1);
  or3(&S_or3_1521_1);
  or2(&S_or2_1503_1);
  and2(&S_and2_1513_1);
  or3(&S_or3_1514_1);
  or3(&S_or3_1527_1);
  or3(&S_or3_2111_1);
  or3(&S_or3_2120_1);
  or2(&S_or2_1789_1);
  or3(&S_or3_1791_1);
  or2(&S_or2_1829_1);
  and2(&S_and2_1837_1);
  or3(&S_or3_1836_1);
  and2(&S_and2_1860_1);
  or2(&S_or2_2062_1);
  or2(&S_or2_1993_1);
  or2(&S_or2_1982_1);
  and2(&S_and2_1962_1);
  and2(&S_and2_1960_1);
  and2(&S_and2_1945_1);
  and2(&S_and2_1944_1);
  and2(&S_and2_1914_1);
  and4(&S_and4_1915_1);
  and4(&S_and4_1921_1);
  or2(&S_or2_1923_1);
  or2(&S_or2_1925_1);
  or2(&S_or2_1924_1);
  zpfs(&S_zpfs_1928_1);
  zpfs(&S_zpfs_1931_1);
  zpfs(&S_zpfs_1916_1);
  and2(&S_and2_1917_1);
  or3(&S_or3_1933_1);
  lk(&S_lk_1505_1);
  rsfn(&S_rsfn_1497_1);
  abs_subf(&S_abs_subf_1516_1);
  lk(&S_lk_1502_1);
  rsfn(&S_rsfn_1499_1);
  abs_subf(&S_abs_subf_1511_1);
  and3(&S_and3_1876_1);
  or2(&S_or2_1883_1);
  or2(&S_or2_1884_1);
  zpfs(&S_zpfs_1890_1);
  zpfs(&S_zpfs_1892_1);
  or3(&S_or3_1895_1);
  or2(&S_or2_1897_1);
  and2(&S_and2_977_1);
  or2(&S_or2_268_1);
  ovbs(&S_ovbs_1898_1);
  ovbs(&S_ovbs_16_1);
  or2(&S_or2_1496_1);
  noto(&S_noto_109_1);
  bol(&S_bol_1553_1);
  bol(&S_bol_1544_1);
  or2(&S_or2_1549_1);
  ml(&S_ml_1560_1);
  ml(&S_ml_1540_1);
  ml(&S_ml_1562_1);
  ml(&S_ml_1542_1);
  and2(&S_and2_124_1);
  noto(&S_noto_122_1);
  and2(&S_and2_128_1);
  and2(&S_and2_127_1);
  noto(&S_noto_207_1);
  noto(&S_noto_482_1);
  noto(&S_noto_928_1);
  noto(&S_noto_1195_1);
  noto(&S_noto_1248_1);
  bol(&S_bol_1807_1);
  and3(&S_and3_1798_1);
  bol(&S_bol_1771_1);
  and3(&S_and3_1779_1);
  noto(&S_noto_1786_1);
  noto(&S_noto_1797_1);
  bol(&S_bol_919_1);
  bol(&S_bol_1333_1);
  abs_subf(&S_abs_subf_1546_1);
  noto(&S_noto_1555_1);
  abs_subf(&S_abs_subf_1565_1);
  noto(&S_noto_1573_1);
  bol(&S_bol_2258_1);
  and2(&S_and2_2268_1);
  noto(&S_noto_2226_1);
  fsumo(&S_fsumo_86_1);
  abs_subf(&S_abs_subf_2265_1);
  and2(&S_and2_2270_1);
  and3(&S_and3_2219_1);
  and2(&S_and2_2241_1);
  ovbs(&S_ovbs_2242_1);
  or3(&S_or3_2254_1);
  inf(&S_inf_2221_1);
  noto(&S_noto_1334_1);
  or2(&S_or2_1082_1);
  and2(&S_and2_2063_1);
  and2(&S_and2_111_1);
  and3(&S_and3_1419_1);
  or2(&S_or2_1682_1);
  noto(&S_noto_2187_1);
  noto(&S_noto_2155_1);
  or2(&S_or2_2146_1);
  rs(&S_rs_752_1);
  noto(&S_noto_767_1);
  noto(&S_noto_1276_1);
  noto(&S_noto_858_1);
  noto(&S_noto_230_1);
  rs(&S_rs_634_1);
  noto(&S_noto_547_1);
  noto(&S_noto_954_1);
  noto(&S_noto_1366_1);
  kvf(&S_kvf_1891_1);
  kvf(&S_kvf_1930_1);
  andn(&S_andn_1785_1);
  rs(&S_rs_22_1);
  noto(&S_noto_146_1);
  noto(&S_noto_1843_1);
  noto(&S_noto_117_1);
  noto(&S_noto_1410_1);
  abs_subf(&S_abs_subf_1023_1);
  abs_subf(&S_abs_subf_1010_1);
  noto(&S_noto_1030_1);
  bol(&S_bol_1043_1);
  bol(&S_bol_1044_1);
  noto(&S_noto_1007_1);
  bol(&S_bol_1046_1);
  bol(&S_bol_1047_1);
  bol(&S_bol_87_1);
  and2(&S_and2_34_1);
  and2(&S_and2_151_1);
  and2(&S_and2_159_1);
  and2(&S_and2_156_1);
  and2(&S_and2_148_1);
  and3(&S_and3_250_1);
  and3(&S_and3_567_1);
  and3(&S_and3_1001_1);
  or3(&S_or3_114_1);
  or2(&S_or2_680_1);
  and2(&S_and2_689_1);
  and2(&S_and2_691_1);
  and2(&S_and2_703_1);
  and2(&S_and2_705_1);
  and2(&S_and2_718_1);
  and2(&S_and2_721_1);
  and3(&S_and3_720_1);
  and2(&S_and2_722_1);
  or2(&S_or2_758_1);
  and2(&S_and2_766_1);
  or2(&S_or2_772_1);
  or2(&S_or2_776_1);
  and3(&S_and3_773_1);
  and2(&S_and2_778_1);
  and2(&S_and2_782_1);
  and2(&S_and2_666_1);
  or2(&S_or2_667_1);
  and2(&S_and2_675_1);
  and2(&S_and2_677_1);
  and2(&S_and2_646_1);
  and2(&S_and2_624_1);
  and2(&S_and2_614_1);
  and3(&S_and3_545_1);
  or2(&S_or2_582_1);
  and3(&S_and3_228_1);
  and3(&S_and3_263_1);
  and3(&S_and3_866_1);
  and3(&S_and3_867_1);
  or2(&S_or2_987_1);
  or2(&S_or2_1399_1);
  and3(&S_and3_1283_1);
  and3(&S_and3_1284_1);
  or2(&S_or2_1048_1);
  or2(&S_or2_1060_1);
  or2(&S_or2_1058_1);
  or2(&S_or2_1057_1);
  or2(&S_or2_1056_1);
  and2(&S_and2_1422_1);
  and2(&S_and2_1428_1);
  and2(&S_and2_1430_1);
  and2(&S_and2_1432_1);
  and2(&S_and2_1438_1);
  and2(&S_and2_1442_1);
  or3(&S_or3_1466_1);
  and2(&S_and2_1467_1);
  and3(&S_and3_1524_1);
  or3(&S_or3_1508_1);
  and2(&S_and2_1522_1);
  and3(&S_and3_1525_1);
  zpfs(&S_zpfs_2064_1);
  and3(&S_and3_1954_1);
  and2(&S_and2_1949_1);
  or3(&S_or3_1955_1);
  and2(&S_and2_1927_1);
  and4(&S_and4_1935_1);
  and4(&S_and4_1937_1);
  lk(&S_lk_1934_1);
  rsfn(&S_rsfn_1938_1);
  abs_subf(&S_abs_subf_1940_1);
  and3(&S_and3_1943_1);
  lk(&S_lk_1896_1);
  rsfn(&S_rsfn_1899_1);
  abs_subf(&S_abs_subf_1901_1);
  and2(&S_and2_1889_1);
  and3(&S_and3_1893_1);
  or5(&S_or5_154_1);
  and2(&S_and2_1861_1);
  and2(&S_and2_112_1);
  and2(&S_and2_108_1);
  ml(&S_ml_1538_1);
  zpfs(&S_zpfs_759_1);
  and2(&S_and2_1762_1);
  and2(&S_and2_1739_1);
  and2(&S_and2_1760_1);
  and2(&S_and2_1763_1);
  and2(&S_and2_1740_1);
  and2(&S_and2_1761_1);
  and2(&S_and2_1741_1);
  and2(&S_and2_1742_1);
  and2(&S_and2_1744_1);
  and2(&S_and2_1745_1);
  and2(&S_and2_1747_1);
  and2(&S_and2_1748_1);
  and2(&S_and2_1715_1);
  and2(&S_and2_1716_1);
  rs(&S_rs_1717_1);
  and2(&S_and2_1718_1);
  and2(&S_and2_1719_1);
  rs(&S_rs_1720_1);
  and2(&S_and2_1698_1);
  and2(&S_and2_1702_1);
  and2(&S_and2_1663_1);
  and2(&S_and2_1665_1);
  and2(&S_and2_1667_1);
  and2(&S_and2_1669_1);
  and2(&S_and2_1637_1);
  and2(&S_and2_1638_1);
  and2(&S_and2_1639_1);
  and2(&S_and2_1640_1);
  and2(&S_and2_1641_1);
  and2(&S_and2_1642_1);
  and2(&S_and2_1643_1);
  and2(&S_and2_1644_1);
  and2(&S_and2_123_1);
  abs_subf(&S_abs_subf_1543_1);
  noto(&S_noto_1550_1);
  ovbs(&S_ovbs_2220_1);
  and2(&S_and2_2266_1);
  noto(&S_noto_2253_1);
  noto(&S_noto_2197_1);
  noto(&S_noto_2198_1);
  and2(&S_and2_2165_1);
  or4(&S_or4_903_1);
  and2(&S_and2_2133_1);
  or4(&S_or4_1320_1);
  and4(&S_and4_962_1);
  and4(&S_and4_1374_1);
  or3(&S_or3_1752_1);
  or3(&S_or3_1723_1);
  or3(&S_or3_1726_1);
  or3(&S_or3_1755_1);
  or3(&S_or3_1707_1);
  or3(&S_or3_1709_1);
  or3(&S_or3_1656_1);
  or3(&S_or3_1652_1);
  or3(&S_or3_2172_1);
  or3(&S_or3_2140_1);
  or3(&S_or3_2174_1);
  or3(&S_or3_2176_1);
  or3(&S_or3_2144_1);
  or3(&S_or3_2142_1);
  or2(&S_or2_1649_1);
  or2(&S_or2_2178_1);
  and2(&S_and2_2162_1);
  and2(&S_and2_2131_1);
  or2(&S_or2_1646_1);
  or2(&S_or2_1705_1);
  and2(&S_and2_1701_1);
  samhd(&S_samhd_401_1);
  samhd(&S_samhd_407_1);
  samhd(&S_samhd_796_1);
  samhd(&S_samhd_800_1);
  rs(&S_rs_768_1);
  rs(&S_rs_775_1);
  newstage(&S_newstage_404_1);
  newstage(&S_newstage_798_1);
  orn(&S_orn_152_1);
  rs(&S_rs_1645_1);
  rs(&S_rs_1647_1);
  rs(&S_rs_1648_1);
  rs(&S_rs_1650_1);
  rs(&S_rs_1651_1);
  rs(&S_rs_1653_1);
  rs(&S_rs_1655_1);
  rs(&S_rs_1657_1);
  rs(&S_rs_1675_1);
  rs(&S_rs_1683_1);
  rs(&S_rs_1704_1);
  rs(&S_rs_1712_1);
  rs(&S_rs_1722_1);
  rs(&S_rs_2179_1);
  rs(&S_rs_1751_1);
  rs(&S_rs_1743_1);
  rs(&S_rs_1754_1);
  rs(&S_rs_1746_1);
  rs(&S_rs_1757_1);
  rs(&S_rs_1695_1);
  rs(&S_rs_1696_1);
  rs(&S_rs_1697_1);
  rs(&S_rs_1659_1);
  rs(&S_rs_1660_1);
  rs(&S_rs_1661_1);
  rs(&S_rs_1662_1);
  rs(&S_rs_115_1);
  noto(&S_noto_116_1);
  rs(&S_rs_1530_1);
  rs(&S_rs_1529_1);
  rs(&S_rs_1459_1);
  kvf(&S_kvf_1463_1);
  rs(&S_rs_1948_1);
  rs(&S_rs_1894_1);
  noto(&S_noto_1462_1);
  andn(&S_andn_283_1);
  noto(&S_noto_301_1);
  and2(&S_and2_425_1);
  and2(&S_and2_436_1);
  and2(&S_and2_444_1);
  and2(&S_and2_445_1);
  and2(&S_and2_446_1);
  or3(&S_or3_397_1);
  or3(&S_or3_412_1);
  and2(&S_and2_426_1);
  and3(&S_and3_602_1);
  or2(&S_or2_153_1);
  and2(&S_and2_694_1);
  and2(&S_and2_754_1);
  or2(&S_or2_781_1);
  and2(&S_and2_673_1);
  or2(&S_or2_291_1);
  and3(&S_and3_292_1);
  or2(&S_or2_454_1);
  and3(&S_and3_461_1);
  or2(&S_or2_507_1);
  and2(&S_and2_527_1);
  and3(&S_and3_577_1);
  and3(&S_and3_576_1);
  and2(&S_and2_202_1);
  and3(&S_and3_262_1);
  or4(&S_or4_792_1);
  or4(&S_or4_808_1);
  or3(&S_or3_859_1);
  and2(&S_and2_856_1);
  and3(&S_and3_857_1);
  and2(&S_and2_855_1);
  and2(&S_and2_868_1);
  and2(&S_and2_885_1);
  and3(&S_and3_886_1);
  and2(&S_and2_948_1);
  or2(&S_or2_955_1);
  and2(&S_and2_963_1);
  and2(&S_and2_980_1);
  and3(&S_and3_981_1);
  and3(&S_and3_982_1);
  or2(&S_or2_1367_1);
  and2(&S_and2_1375_1);
  and2(&S_and2_1392_1);
  and3(&S_and3_1393_1);
  and3(&S_and3_1394_1);
  and2(&S_and2_1362_1);
  or3(&S_or3_1277_1);
  and3(&S_and3_1274_1);
  and2(&S_and2_1273_1);
  and2(&S_and2_1272_1);
  and2(&S_and2_1285_1);
  and2(&S_and2_1297_1);
  and3(&S_and3_1298_1);
  and2(&S_and2_1302_1);
  and3(&S_and3_1303_1);
  and2(&S_and2_1243_1);
  and2(&S_and2_1265_1);
  and2(&S_and2_1061_1);
  and2(&S_and2_1064_1);
  or2(&S_or2_1454_1);
  or3(&S_or3_1458_1);
  or2(&S_or2_1758_1);
  or2(&S_or2_2089_1);
  or2(&S_or2_2094_1);
  lk(&S_lk_1464_1);
  rsfn(&S_rsfn_1460_1);
  abs_subf(&S_abs_subf_1469_1);
  ovbs(&S_ovbs_2081_1);
  ovbs(&S_ovbs_121_1);
  and2(&S_and2_488_1);
  and2(&S_and2_455_1);
  and2(&S_and2_452_1);
  rs(&S_rs_1759_1);
  rs(&S_rs_1725_1);
  and2(&S_and2_1699_1);
  and2(&S_and2_1700_1);
  and2(&S_and2_1703_1);
  and2(&S_and2_1666_1);
  and2(&S_and2_1668_1);
  and2(&S_and2_1670_1);
  zpfs(&S_zpfs_2205_1);
  zpfs(&S_zpfs_2206_1);
  and2(&S_and2_2077_1);
  and2(&S_and2_2088_1);
  and3(&S_and3_427_1);
  and2(&S_and2_2076_1);
  and2(&S_and2_2099_1);
  rs(&S_rs_2171_1);
  rs(&S_rs_2159_1);
  rs(&S_rs_2163_1);
  and2(&S_and2_2169_1);
  rs(&S_rs_2181_1);
  rs(&S_rs_2164_1);
  and2(&S_and2_2170_1);
  rs(&S_rs_2183_1);
  rs(&S_rs_2147_1);
  rs(&S_rs_2139_1);
  rs(&S_rs_2127_1);
  rs(&S_rs_2130_1);
  and2(&S_and2_2137_1);
  rs(&S_rs_2149_1);
  rs(&S_rs_2132_1);
  and2(&S_and2_2138_1);
  rs(&S_rs_2151_1);
  regch(&S_regch_131_1);
  rs(&S_rs_1710_1);
  rs(&S_rs_747_1);
  rs(&S_rs_780_1);
  rs(&S_rs_607_1);
  noto(&S_noto_621_1);
  orni(&S_orni_1427_1);
  noto(&S_noto_2082_1);
  rs(&S_rs_1677_1);
  rs(&S_rs_1681_1);
  rs(&S_rs_1685_1);
  rs(&S_rs_1706_1);
  rs(&S_rs_1708_1);
  rs(&S_rs_1714_1);
  ma(&S_ma_1465_1);
  rs(&S_rs_617_1);
  noto(&S_noto_997_1);
  noto(&S_noto_296_1);
  noto(&S_noto_1059_1);
  noto(&S_noto_1053_1);
  noto(&S_noto_1026_1);
  and2(&S_and2_429_1);
  and2(&S_and2_447_1);
  and2(&S_and2_880_1);
  and3(&S_and3_881_1);
  and3(&S_and3_975_1);
  and3(&S_and3_1387_1);
  and2(&S_and2_641_1);
  and2(&S_and2_951_1);
  and2(&S_and2_952_1);
  and3(&S_and3_953_1);
  and2(&S_and2_1363_1);
  and2(&S_and2_1364_1);
  and3(&S_and3_1365_1);
  and5(&S_and5_1002_1);
  and2(&S_and2_1049_1);
  or4(&S_or4_1009_1);
  and3(&S_and3_1473_1);
  or2(&S_or2_1847_1);
  and2(&S_and2_1850_1);
  and2(&S_and2_2100_1);
  ovbs(&S_ovbs_2085_1);
  noto(&S_noto_2210_1);
  noto(&S_noto_2211_1);
  andn(&S_andn_605_1);
  andn(&S_andn_606_1);
  and2(&S_and2_2103_1);
  or5(&S_or5_2101_1);
  or5(&S_or5_2102_1);
  and2(&S_and2_2166_1);
  or3(&S_or3_1227_1);
  rs(&S_rs_2173_1);
  rs(&S_rs_2160_1);
  and2(&S_and2_2134_1);
  rs(&S_rs_2141_1);
  rs(&S_rs_2128_1);
  or3(&S_or3_827_1);
  or2(&S_or2_134_1);
  rs(&S_rs_1008_1);
  noto(&S_noto_2086_1);
  rs(&S_rs_2090_1);
  rs(&S_rs_2095_1);
  rs(&S_rs_1476_1);
  noto(&S_noto_1027_1);
  provsbr(&S_provsbr_1424_1);
  rs(&S_rs_1423_1);
  and2(&S_and2_555_1);
  and2(&S_and2_238_1);
  and2(&S_and2_870_1);
  and2(&S_and2_965_1);
  and2(&S_and2_1377_1);
  and2(&S_and2_1287_1);
  and3(&S_and3_1014_1);
  and3(&S_and3_1020_1);
  and2(&S_and2_1036_1);
  and2(&S_and2_1025_1);
  and3(&S_and3_1071_1);
  or2(&S_or2_1429_1);
  or2(&S_or2_1431_1);
  or2(&S_or2_1433_1);
  or2(&S_or2_1439_1);
  or2(&S_or2_1443_1);
  orni(&S_orni_1435_1);
  or2(&S_or2_1845_1);
  or2(&S_or2_2078_1);
  noto(&S_noto_2217_1);
  and2(&S_and2_2167_1);
  and2(&S_and2_2135_1);
  rs(&S_rs_2161_1);
  and2(&S_and2_2168_1);
  rs(&S_rs_2177_1);
  rs(&S_rs_2129_1);
  and2(&S_and2_2079_1);
  noto(&S_noto_2096_1);
  rs(&S_rs_2175_1);
  newstage(&S_newstage_1838_1);
  cntch(&S_cntch_1434_1);
  rs(&S_rs_1031_1);
  rs(&S_rs_1065_1);
  rs(&S_rs_1039_1);
  noto(&S_noto_1040_1);
  or3(&S_or3_162_1);
  or3(&S_or3_497_1);
  or2(&S_or2_1062_1);
  and2(&S_and2_1436_1);
  or2(&S_or2_1598_1);
  zpfs(&S_zpfs_2075_1);
  rs(&S_rs_2143_1);
  and2(&S_and2_2136_1);
  rs(&S_rs_2145_1);
  cnshd(&S_cnshd_1605_1);
  noto(&S_noto_878_1);
  ornc(&S_ornc_170_1);
  charint(&S_charint_163_1);
  noto(&S_noto_246_1);
  ornc(&S_ornc_505_1);
  charint(&S_charint_499_1);
  noto(&S_noto_563_1);
  noto(&S_noto_973_1);
  noto(&S_noto_1385_1);
  rs(&S_rs_1050_1);
  or2(&S_or2_1624_1);
  and2(&S_and2_1576_1);
  and2(&S_and2_1577_1);
  and2(&S_and2_1578_1);
  and2(&S_and2_1579_1);
  and2(&S_and2_1585_1);
  and2(&S_and2_1587_1);
  and2(&S_and2_1589_1);
  and2(&S_and2_1038_1);
  fnapb(&S_fnapb_1625_1);
  samhd(&S_samhd_1608_1);
  zpfs(&S_zpfs_1622_1);
  zpfs(&S_zpfs_1618_1);
  noto(&S_noto_1295_1);
  fsumz(&S_fsumz_164_1);
  fsumz(&S_fsumz_500_1);
  orni(&S_orni_1187_1);
  rs(&S_rs_1033_1);
  rs(&S_rs_1034_1);
  ma(&S_ma_171_1);
  ma(&S_ma_506_1);
  zpfs(&S_zpfs_1626_1);
  or2(&S_or2_1125_1);
  or3(&S_or3_1032_1);
  or3(&S_or3_1615_1);
  samhd(&S_samhd_1192_1);
  samhd(&S_samhd_1202_1);
  newstage(&S_newstage_1198_1);
  cnshd(&S_cnshd_1126_1);
  noto(&S_noto_1294_1);
  noto(&S_noto_877_1);
  fnapb(&S_fnapb_213_1);
  noto(&S_noto_245_1);
  fnapb(&S_fnapb_535_1);
  zpfs(&S_zpfs_529_1);
  zpfs(&S_zpfs_528_1);
  noto(&S_noto_562_1);
  noto(&S_noto_972_1);
  noto(&S_noto_1384_1);
  or2(&S_or2_1191_1);
  or2(&S_or2_1205_1);
  or2(&S_or2_1149_1);
  and2(&S_and2_1101_1);
  and2(&S_and2_1098_1);
  and2(&S_and2_1099_1);
  and2(&S_and2_1100_1);
  and2(&S_and2_1106_1);
  and2(&S_and2_1108_1);
  and2(&S_and2_1110_1);
  and2(&S_and2_643_1);
  zpfs(&S_zpfs_536_1);
  or2(&S_or2_557_1);
  zpfs(&S_zpfs_214_1);
  zpfs(&S_zpfs_204_1);
  zpfs(&S_zpfs_203_1);
  or2(&S_or2_240_1);
  or2(&S_or2_872_1);
  and2(&S_and2_871_1);
  or2(&S_or2_967_1);
  or2(&S_or2_1379_1);
  or2(&S_or2_1289_1);
  and2(&S_and2_1288_1);
  and2(&S_and2_1029_1);
  or2(&S_or2_1041_1);
  and2(&S_and2_1196_1);
  and2(&S_and2_1203_1);
  or4(&S_or4_1972_1);
  zapomni(&S_zapomni_183_1);
  zapomni(&S_zapomni_188_1);
  zapomni(&S_zapomni_195_1);
  zapomni(&S_zapomni_198_1);
  fnapb(&S_fnapb_1150_1);
  samhd(&S_samhd_1132_1);
  zpfs(&S_zpfs_1147_1);
  zpfs(&S_zpfs_1142_1);
  orn(&S_orn_1296_1);
  orn(&S_orn_879_1);
  rs(&S_rs_1028_1);
  zpfs(&S_zpfs_1151_1);
  and2(&S_and2_556_1);
  and2(&S_and2_239_1);
  and2(&S_and2_966_1);
  and2(&S_and2_1378_1);
  and2(&S_and2_1042_1);
  or2(&S_or2_1035_1);
  or3(&S_or3_1139_1);
  or2(&S_or2_1989_1);
  or2(&S_or2_1978_1);
  ovbs(&S_ovbs_1973_1);
  ovbs(&S_ovbs_1985_1);
  ovbs(&S_ovbs_1976_1);
  noto(&S_noto_1977_1);
  and2(&S_and2_1983_1);
  and2(&S_and2_1994_1);
  or3(&S_or3_132_1);
  orn(&S_orn_247_1);
  orn(&S_orn_974_1);
  orn(&S_orn_1386_1);
  noto(&S_noto_1974_1);
  noto(&S_noto_1986_1);
  rs(&S_rs_1990_1);
  noto(&S_noto_1991_1);
  rs(&S_rs_1979_1);
  rs(&S_rs_1080_1);
  or2(&S_or2_1946_1);
  irm(&S_irm_2200_1);
  ml(&S_ml_898_1);
  ml(&S_ml_1314_1);
  noto(&S_noto_1980_1);
  noto(&S_noto_72_1);
  noto(&S_noto_1947_1);
  and2(&S_and2_64_1);
  and2(&S_and2_68_1);
  and4(&S_and4_347_1);
  or2(&S_or2_1416_1);
  or2(&S_or2_1963_1);
  noto(&S_noto_1412_1);
  rs(&S_rs_350_1);
  noto(&S_noto_345_1);
  noto(&S_noto_288_1);
  rs(&S_rs_1964_1);
  rs(&S_rs_1965_1);
  or4(&S_or4_299_1);
  or2(&S_or2_282_1);
  or2(&S_or2_305_1);
  or2(&S_or2_342_1);
  or4(&S_or4_351_1);
  and2(&S_and2_1411_1);
  or2(&S_or2_2025_1);
  or2(&S_or2_2046_1);
  rs(&S_rs_298_1);
  provsbr(&S_provsbr_287_1);
  equz_p(&S_equz_p_326_1);
  bolz(&S_bolz_327_1);
  provsbr(&S_provsbr_344_1);
  bolz(&S_bolz_349_1);
  noto(&S_noto_73_1);
  noto(&S_noto_62_1);
  and2(&S_and2_65_1);
  and2(&S_and2_69_1);
  or2(&S_or2_66_1);
  and2(&S_and2_579_1);
  and2(&S_and2_578_1);
  and2(&S_and2_302_1);
  and4(&S_and4_331_1);
  and2(&S_and2_314_1);
  or2(&S_or2_304_1);
  and2(&S_and2_309_1);
  or2(&S_or2_355_1);
  and2(&S_and2_346_1);
  orn(&S_orn_564_1);
  and2(&S_and2_264_1);
  and2(&S_and2_265_1);
  or3(&S_or3_275_1);
  and2(&S_and2_888_1);
  and2(&S_and2_887_1);
  or3(&S_or3_893_1);
  and2(&S_and2_984_1);
  and2(&S_and2_983_1);
  and2(&S_and2_1395_1);
  and2(&S_and2_1396_1);
  and2(&S_and2_1304_1);
  and2(&S_and2_1305_1);
  or3(&S_or3_1310_1);
  or2(&S_or2_1413_1);
  or3(&S_or3_1444_1);
  or3(&S_or3_1483_1);
  or3(&S_or3_1500_1);
  or3(&S_or3_1906_1);
  or3(&S_or3_1868_1);
  or4(&S_or4_1406_1);
  or4(&S_or4_994_1);
  zapomni(&S_zapomni_179_1);
  maz(&S_maz_313_1);
  maz(&S_maz_322_1);
  orni(&S_orni_1199_1);
  orni(&S_orni_303_1);
  rs(&S_rs_354_1);
  decatron(&S_decatron_311_1);
  orni(&S_orni_348_1);
  noto(&S_noto_323_1);
  swtakt(&S_swtakt_1872_1);
  swtakt(&S_swtakt_1907_1);
  swtakt(&S_swtakt_1489_1);
  swtakt(&S_swtakt_1493_1);
  swtakt(&S_swtakt_1449_1);
  or3(&S_or3_589_1);
  or2(&S_or2_308_1);
  or2(&S_or2_317_1);
  or2(&S_or2_330_1);
  or2(&S_or2_329_1);
  and2(&S_and2_333_1);
  and2(&S_and2_328_1);
  and2(&S_and2_335_1);
  and2(&S_and2_334_1);
  and3(&S_and3_315_1);
  or5(&S_or5_519_1);
  or5(&S_or5_192_1);
  and2(&S_and2_1414_1);
  or2(&S_or2_2068_1);
  or2(&S_or2_2056_1);
  or3(&S_or3_1408_1);
  or3(&S_or3_996_1);
  zpfs(&S_zpfs_325_1);
  cnshd(&S_cnshd_174_1);
  cnshd(&S_cnshd_508_1);
  equz_p(&S_equz_p_316_1);
  noto(&S_noto_1420_1);
  cntch(&S_cntch_306_1);
  rs(&S_rs_307_1);
  cntch(&S_cntch_352_1);
  and2(&S_and2_321_1);
  or5(&S_or5_1437_1);
  or5(&S_or5_1415_1);
  and2(&S_and2_1417_1);
  or2(&S_or2_1418_1);
  and4(&S_and4_1950_1);
  and3(&S_and3_1951_1);
  and3(&S_and3_1952_1);
  and2(&S_and2_1913_1);
  and2(&S_and2_1867_1);
  or3(&S_or3_1881_1);
  newstage(&S_newstage_221_1);
  rs(&S_rs_1919_1);
  rs(&S_rs_1873_1);
  rs(&S_rs_1882_1);
  and2(&S_and2_340_1);
  or3(&S_or3_1918_1);
  and2(&S_and2_210_1);
  and2(&S_and2_208_1);
  noto(&S_noto_341_1);
  and2(&S_and2_1094_1);
  and2(&S_and2_650_1);
  or2(&S_or2_638_1);
  and2(&S_and2_1054_1);
  rs(&S_rs_639_1);
  rs(&S_rs_1051_1);
  noto(&S_noto_1052_1);
  rs(&S_rs_1086_1);
  and2(&S_and2_657_1);
  and3(&S_and3_626_1);
  and3(&S_and3_616_1);
  or3(&S_or3_825_1);
  or3(&S_or3_1223_1);
  and4(&S_and4_1015_1);
  and4(&S_and4_1021_1);
  or2(&S_or2_1085_1);
  or4(&S_or4_894_1);
  or4(&S_or4_1311_1);
  ornc(&S_ornc_904_1);
  charint(&S_charint_896_1);
  ornc(&S_ornc_1321_1);
  charint(&S_charint_1312_1);
  fsumz(&S_fsumz_897_1);
  fsumz(&S_fsumz_1313_1);
  ma(&S_ma_1322_1);
  ma(&S_ma_905_1);
  fnapb(&S_fnapb_939_1);
  zpfs(&S_zpfs_931_1);
  zpfs(&S_zpfs_930_1);
  fnapb(&S_fnapb_1351_1);
  zpfs(&S_zpfs_1343_1);
  zpfs(&S_zpfs_1342_1);
  zpfs(&S_zpfs_940_1);
  zpfs(&S_zpfs_1352_1);
  and2(&S_and2_1337_1);
  and2(&S_and2_923_1);
  or5(&S_or5_922_1);
  or5(&S_or5_1336_1);
  or2(&S_or2_2250_1);
  cnshd(&S_cnshd_906_1);
  cnshd(&S_cnshd_1323_1);
  noto(&S_noto_2249_1);
  newstage(&S_newstage_918_1);
  and2(&S_and2_925_1);
  and2(&S_and2_929_1);
  andn(&S_andn_2225_1);
  noto(&S_noto_2247_1);
  and2(&S_and2_2248_1);
  or2(&S_or2_2246_1);
  and3(&S_and3_2204_1);
  and2(&S_and2_2073_1);
  and2(&S_and2_2065_1);
  or3(&S_or3_2060_1);
  or3(&S_or3_2074_1);
  rs(&S_rs_2057_1);
  noto(&S_noto_2058_1);
  rs(&S_rs_2069_1);
  noto(&S_noto_2070_1);
  and2(&S_and2_1095_1);
  and2(&S_and2_649_1);
  and2(&S_and2_1070_1);
  rs(&S_rs_2245_1);
  rs(&S_rs_1063_1);
  noto(&S_noto_1066_1);
  rs(&S_rs_1089_1);
  and3(&S_and3_1055_1);
  and2(&S_and2_1006_1);
  and4(&S_and4_1013_1);
  and4(&S_and4_1019_1);
  or2(&S_or2_1088_1);
  orn(&S_orn_1215_1);
  orn(&S_orn_815_1);
  ornc(&S_ornc_1224_1);
  charint(&S_charint_1216_1);
  ornc(&S_ornc_822_1);
  charint(&S_charint_816_1);
  rs(&S_rs_1000_1);
  or3(&S_or3_453_1);
  and3(&S_and3_460_1);
  and2(&S_and2_1045_1);
  and2(&S_and2_492_1);
  and2(&S_and2_463_1);
  fsumz(&S_fsumz_1217_1);
  fsumz(&S_fsumz_817_1);
  samhd(&S_samhd_473_1);
  samhd(&S_samhd_479_1);
  newstage(&S_newstage_475_1);
  ma(&S_ma_823_1);
  ma(&S_ma_1225_1);
  or4(&S_or4_469_1);
  or4(&S_or4_487_1);
  and2(&S_and2_484_1);
  and2(&S_and2_483_1);
  fnapb(&S_fnapb_1261_1);
  zpfs(&S_zpfs_1255_1);
  zpfs(&S_zpfs_1246_1);
  fnapb(&S_fnapb_846_1);
  zpfs(&S_zpfs_1259_1);
  and2(&S_and2_1096_1);
  and2(&S_and2_665_1);
  zpfs(&S_zpfs_847_1);
  zpfs(&S_zpfs_840_1);
  zpfs(&S_zpfs_842_1);
  or5(&S_or5_1239_1);
  and2(&S_and2_1077_1);
  or5(&S_or5_1996_1);
  orni(&S_orni_138_1);
  orn(&S_orn_431_1);
  orn(&S_orn_449_1);
  cnshd(&S_cnshd_1226_1);
  rs(&S_rs_1075_1);
  rs(&S_rs_1092_1);
  or2(&S_or2_433_1);
  or2(&S_or2_450_1);
  and2(&S_and2_693_1);
  or2(&S_or2_1171_1);
  or2(&S_or2_1172_1);
  and2(&S_and2_1109_1);
  or5(&S_or5_835_1);
  and2(&S_and2_1588_1);
  or4(&S_or4_1584_1);
  or4(&S_or4_1997_1);
  orn(&S_orn_779_1);
  orn(&S_orn_1097_1);
  cnshd(&S_cnshd_826_1);
  or2(&S_or2_769_1);
  or2(&S_or2_770_1);
  or4(&S_or4_750_1);
  or5(&S_or5_1135_1);
  or2(&S_or2_375_1);
  or2(&S_or2_379_1);
  ovbs(&S_ovbs_2003_1);
  noto(&S_noto_2004_1);
  and2(&S_and2_2010_1);
  and2(&S_and2_2022_1);
  or3(&S_or3_1998_1);
  and2(&S_and2_1999_1);
  or3(&S_or3_2012_1);
  and2(&S_and2_2013_1);
  or5(&S_or5_1575_1);
  or2(&S_or2_2236_1);
  rs(&S_rs_749_1);
  samhd(&S_samhd_378_1);
  newstage(&S_newstage_1266_1);
  and2(&S_and2_737_1);
  or2(&S_or2_739_1);
  or4(&S_or4_377_1);
  or5(&S_or5_1612_1);
  or2(&S_or2_2017_1);
  or2(&S_or2_2005_1);
  ovbs(&S_ovbs_2000_1);
  ovbs(&S_ovbs_2014_1);
  rs(&S_rs_2033_1);
  rs(&S_rs_2041_1);
  noto(&S_noto_2031_1);
  noto(&S_noto_2052_1);
  andn(&S_andn_1_1);
  and2(&S_and2_1249_1);
  and2(&S_and2_1254_1);
  zpfs(&S_zpfs_2034_1);
  zpfs(&S_zpfs_2042_1);
  noto(&S_noto_2233_1);
  or3(&S_or3_1680_1);
  or3(&S_or3_1672_1);
  or2(&S_or2_1686_1);
  or2(&S_or2_1678_1);
  rs(&S_rs_743_1);
  rs(&S_rs_1671_1);
  rs(&S_rs_1679_1);
  or2(&S_or2_2035_1);
  noto(&S_noto_2001_1);
  noto(&S_noto_2015_1);
  rs(&S_rs_2018_1);
  noto(&S_noto_2019_1);
  rs(&S_rs_2006_1);
  or2(&S_or2_2043_1);
  noto(&S_noto_2036_1);
  and2(&S_and2_2037_1);
  and2(&S_and2_2032_1);
  noto(&S_noto_2044_1);
  and2(&S_and2_1664_1);
  noto(&S_noto_2024_1);
  rs(&S_rs_1673_1);
  noto(&S_noto_2007_1);
  and2(&S_and2_2045_1);
  and4(&S_and4_2026_1);
  ovbs(&S_ovbs_2027_1);
  and2(&S_and2_2053_1);
  noto(&S_noto_2054_1);
  or2(&S_or2_2028_1);
  orn(&S_orn_609_1);
  orn(&S_orn_608_1);
  noto(&S_noto_2029_1);
  and4(&S_and4_2047_1);
  ovbs(&S_ovbs_2048_1);
  or2(&S_or2_2049_1);
  newstage(&S_newstage_611_1);
  or2(&S_or2_645_1);
  ovbs(&S_ovbs_2038_1);
  noto(&S_noto_2050_1);
  and2(&S_and2_644_1);
  setData(ida1abf3,&var1724);
  setData(ida1abf2,&var998);
  setData(ida1abf1,&var733);
  setData(ida1ab5,&var1);
  setData(ida1ab4,&var2);
  setData(ida1ab3,&var3);
  setData(ida1ab2,&var4);
  setData(ida1ab1,&var5);
  setData(idbd6,&var855);
  setData(idbd5,&var856);
  setData(idbd4,&var857);
  setData(idbd3,&var1630);
  setData(idbd2,&var852);
  setData(idbd1,&var853);
  setData(idhz6,&var1209);
  setData(idhz5,&var919);
  setData(idhz4,&var395);
  setData(idhz3,&var966);
  setData(idhz2,&var255);
  setData(idhz1,&var1278);
  setData(idKKL9,&var1207);
  setData(idKKL8,&var1155);
  setData(idKKL7,&var1113);
  setData(idKKL6,&var1029);
  setData(idKKL5,&var1209);
  setData(idKKL4,&var1559);
  setData(idKKL3,&var816);
  setData(idKKL2,&var1204);
  setData(idKKL1,&var250);
  setData(idTestDiagnDU,&var8);
  setData(idR0DE3CLDU,&var11);
  setData(idR0DE3DLDU,&var10);
  setData(idTTLDU,&var14);
  setData(idB3AB13LDU,&var136);
  setData(idA3AB13LDU,&var139);
  setData(idR3VS01IDU,&var145);
  setData(idR3VS12LDU,&var143);
  setData(idR3VS22LDU,&var144);
  setData(idR5VS01IDU,&var142);
  setData(idR5VS12LDU,&var140);
  setData(idR5VS22LDU,&var141);
  setData(idB3AB15LDU,&var149);
  setData(idB3EE03LDU,&var817);
  setData(idA3EE03LDU,&var818);
  setData(idB3AB19LDU,&var154);
  setData(idA3AB19LDU,&var155);
  setData(idR0VL23LDU,&var1053);
  setData(idR0VL22LDU,&var1075);
  setData(idR0AD05LZ2,&var81);
  setData(idR0AD05LZ1,&var81);
  setData(idR0AD04LZ2,&var377);
  setData(idR0AD04LZ1,&var377);
  setData(idR0AD03LZ2,&var80);
  setData(idR0AD03LZ1,&var80);
  setData(idR0CN95LDU,&var225);
  setData(idR0CN94LDU,&var224);
  setData(idR0CN93LDU,&var223);
  setData(idR0AB19LDU,&var186);
  setData(idR0VN12RDU,&var986);
  setData(idR0VN11RDU,&var984);
  setData(idR0CN92LDU,&var190);
  setData(idR0AB20LDU,&var202);
  setData(idA3AB15LDU,&var150);
  setData(idA3MC03RDU,&var221);
  setData(idR0CN91LDU,&var220);
  setData(idA3MC02RDU,&var219);
  setData(idA3MC01RDU,&var218);
  setData(idR0AB18LDU,&var207);
  setData(idR0AB17LDU,&var214);
  setData(idR0AB16LDU,&var215);
  setData(idB1AB19LDU,&var232);
  setData(idA3ZAV,&var1325);
  setData(idA1ZAV,&var1388);
  setData(idB3IS12LDU,&var242);
  setData(idA3IS12LDU,&var243);
  setData(idR0AB15LDU,&var248);
  setData(idR0AB14LDU,&var246);
  setData(idA4DW,&var1163);
  setData(idA4UP,&var1164);
  setData(idR4ABL,&var1627);
  setData(idA9ZAV,&var1263);
  setData(idA8ZAV,&var1464);
  setData(idA2ZAV,&var1469);
  setData(idB8ZAV,&var1474);
  setData(idA5ZAV,&var1542);
  setData(idR2ZAV,&var1418);
  setData(idA6ZAV,&var1544);
  setData(idA4ZAV,&var1543);
  setData(idR0AB13LDU,&var315);
  setData(idR0AB12LDU,&var319);
  setData(idR0AB11LDU,&var323);
  setData(idR0AB10LDU,&var327);
  setData(idR0AB09LDU,&var331);
  setData(idR0AB08LDU,&var335);
  setData(idB6AB05LDU,&var378);
  setData(idR0VS11LDU,&var1673);
  setData(idA8VS01IDU,&var1468);
  setData(idB8VS01IDU,&var1478);
  setData(idR2AD10LDU,&var1423);
  setData(idR2AD20LDU,&var1424);
  setData(idB6VS01IDU,&var1615);
  setData(idR0AD16LDU,&lRM_0_);
  setData(idR0AB07LDU,&var617);
  setData(idR0EE03LDU,&var402);
  setData(idR0VX02LDU,&var823);
  setData(idR0AD21LDU,&var821);
  setData(idB2AB15LDU,&var348);
  setData(idA2AB15LDU,&var349);
  setData(idR0AB05LDU,&var1135);
  setData(idR0AB03LDU,&var1146);
  setData(idA1AB19LDU,&var233);
  setData(idR0VZ71LDU,&var67);
  setData(idR0VL01RDU,&var1181);
  setData(idB7AZ03LDU,&var379);
  setData(idA7AZ03LDU,&var487);
  setData(idB2VS01IDU,&var1456);
  setData(idB2VS21LDU,&var1458);
  setData(idB2VS11LDU,&var1457);
  setData(idR0VP73LDU,&var498);
  setData(idR0VS18LDU,&var575);
  setData(idB3VX01LDU,&var445);
  setData(idA3VX01LDU,&var446);
  setData(idB2VS32LDU,&var361);
  setData(idA2VS32LDU,&var362);
  setData(idR0VS17LDU,&var565);
  setData(idR0VX09LDU,&var178);
  moveData(idR0VX08IDU,idR0MW12IP1);
  setData(idR0VW23LDU,&var918);
  setData(idR0VW13LDU,&var917);
  setData(idB7AP31LDU,&var1166);
  setData(idA7AP31LDU,&var1167);
  setData(idB3AD31LDU,&var1226);
  setData(idB3AD34LDU,&var1227);
  setData(idA3AD31LDU,&var1232);
  setData(idA3AD34LDU,&var1229);
  setData(idA3AD33LDU,&var1231);
  setData(idB2AD33LDU,&var340);
  setData(idA2AD33LDU,&var343);
  setData(idR0AB01LDU,&var1255);
  setData(idB9AB02LDU,&var1265);
  setData(idB9AB01LDU,&var1266);
  setData(idB9AZ03LDU,&var1264);
  setData(idA9AB02LDU,&var1271);
  setData(idA9AB01LDU,&var1272);
  setData(idA9AZ03LDU,&var1270);
  setData(idA9AD10LDU,&var1273);
  setData(idB9AD10LDU,&var1267);
  setData(idR1VS01IDU,&var1434);
  setData(idR2VS01IDU,&var1425);
  setData(idR4VS01IDU,&var1606);
  setData(idA6VS01IDU,&var1624);
  setData(idB5VS01IDU,&var1588);
  setData(idA5VS01IDU,&var1597);
  setData(idB4VS22LDU,&var1569);
  setData(idB4VS12LDU,&var1568);
  setData(idB4VS01IDU,&var1570);
  setData(idA4VS22LDU,&var1578);
  setData(idA4VS12LDU,&var1577);
  setData(idA4VS01IDU,&var1579);
  setData(idA2VS01IDU,&var1497);
  setData(idB3VS01IDU,&var1315);
  setData(idA3VS01IDU,&var1347);
  setData(idB1VS01IDU,&var1376);
  setData(idA1VS01IDU,&var1409);
  setData(idR0VS21IDU,&var1156);
  setData(idR0VX03LDU,&var768);
  setData(idR0VL21IDU,&var1066);
  setData(idR0VL05RDU,&var432);
  setData(idR0VL03RDU,&var438);
  setData(idR0AB02LDU,&var1129);
  setData(idR0AB06LDU,&var1132);
  setData(idR0AB04LDU,&var1140);
  setData(idR0VL04RDU,&var435);
  setData(idR0AD14LDU,&var377);
  setData(idR8AD21LDU,&var400);
  setData(idR0VL02RDU,&var429);
  setData(idB3AD33LDU,&var1225);
  setData(idR0VL06RDU,&var442);
  setData(idR0VL11IDU,&var1279);
  setData(idR0VL01IDU,&var1280);
  setData(idR0VX01LDU,&var825);
  setData(idB1AD32LDU,&var1233);
  setData(idA1AD32LDU,&var1235);
  setData(idB2AD32LDU,&var368);
  setData(idA2AD32LDU,&var370);
  setData(idB1AD31LDU,&var1236);
  setData(idA1AD31LDU,&var1237);
  setData(idB2AD31LDU,&var371);
  setData(idA2AD31LDU,&var372);
  setData(idB3AB20LDU,&var659);
  setData(idB3AB18LDU,&var656);
  setData(idB3AB17LDU,&var652);
  setData(idB3AB16LDU,&var653);
  setData(idB3AB14LDU,&var927);
  setData(idB3AB12LDU,&var657);
  setData(idB3AB11LDU,&var661);
  setData(idB3AB10LDU,&var662);
  setData(idB3AB09LDU,&var663);
  setData(idB3AB06LDU,&var666);
  setData(idB3AB05LDU,&var668);
  setData(idB3AB08LDU,&var658);
  setData(idB3AB07LDU,&var667);
  setData(idB3CV02RDU,&var1314);
  setData(idB3AD01LDU,&var1307);
  setData(idB3AD05LDU,&var1313);
  setData(idB3AD04LDU,&var1312);
  setData(idB3AD03LDU,&var1311);
  setData(idB3AD02LDU,&var1310);
  setData(idB3AD21LDU,&var1308);
  setData(idB3AD11LDU,&var1309);
  setData(idB3AZ03LDU,&var999);
  setData(idB3VS22LDU,&var1318);
  setData(idB3AB01LDU,&var1316);
  setData(idB3AB02LDU,&var1317);
  setData(idB3AB04LDU,&var1322);
  setData(idB3CV01RDU,&var1320);
  setData(idB3VS12LDU,&var1319);
  setData(idA3AB20LDU,&var410);
  setData(idA3AB18LDU,&var673);
  setData(idA3AB17LDU,&var671);
  setData(idA3AB16LDU,&var670);
  setData(idA3AB14LDU,&var929);
  setData(idA3AB12LDU,&var674);
  setData(idA3AB11LDU,&var678);
  setData(idA3AB10LDU,&var682);
  setData(idA3AB09LDU,&var676);
  setData(idA3AB06LDU,&var681);
  setData(idA3AB05LDU,&var684);
  setData(idA3AB08LDU,&var675);
  setData(idA3AB07LDU,&var683);
  setData(idA3CV02RDU,&var1346);
  setData(idA3AD01LDU,&var1339);
  setData(idA3AD05LDU,&var1345);
  setData(idA3AD04LDU,&var1344);
  setData(idA3AD03LDU,&var1343);
  setData(idA3AD02LDU,&var1342);
  setData(idA3AD21LDU,&var1340);
  setData(idA3AD11LDU,&var1341);
  setData(idA3AZ03LDU,&var1000);
  setData(idA3VS22LDU,&var1350);
  setData(idA3AB01LDU,&var1348);
  setData(idA3AB02LDU,&var1349);
  setData(idA3AB04LDU,&var1354);
  setData(idA3CV01RDU,&var1352);
  setData(idA3VS12LDU,&var1351);
  setData(idB1AB18LDU,&var743);
  setData(idB1AB17LDU,&var912);
  setData(idB1AB16LDU,&var911);
  setData(idB1AB14LDU,&var931);
  setData(idB1AB13LDU,&var932);
  setData(idB1AB12LDU,&var741);
  setData(idB1AB11LDU,&var745);
  setData(idB1AB10LDU,&var746);
  setData(idB1AB09LDU,&var749);
  setData(idB1AB06LDU,&var747);
  setData(idB1AB05LDU,&var754);
  setData(idB1AB08LDU,&var742);
  setData(idB1AB07LDU,&var753);
  setData(idB1CV02RDU,&var1375);
  setData(idB1AD01LDU,&var1368);
  setData(idB1AD05LDU,&var1374);
  setData(idB1AD04LDU,&var1373);
  setData(idB1AD03LDU,&var1372);
  setData(idB1AD02LDU,&var1371);
  setData(idB1AD21LDU,&var1370);
  setData(idB1AD11LDU,&var1369);
  setData(idB1AZ03LDU,&var756);
  setData(idB1VS22LDU,&var1380);
  setData(idB1AB01LDU,&var1377);
  setData(idB1AB02LDU,&var1378);
  setData(idB1AB04LDU,&var1383);
  setData(idB1CV01RDU,&var1381);
  setData(idB1VS12LDU,&var1379);
  setData(idA1AB18LDU,&var719);
  setData(idA1AB17LDU,&var718);
  setData(idA1AB16LDU,&var720);
  setData(idA1AB14LDU,&var934);
  setData(idA1AB13LDU,&var935);
  setData(idA1AB12LDU,&var716);
  setData(idA1AB11LDU,&var725);
  setData(idA1AB10LDU,&var723);
  setData(idA1AB09LDU,&var722);
  setData(idA1AB06LDU,&var727);
  setData(idA1AB05LDU,&var728);
  setData(idA1AB08LDU,&var721);
  setData(idA1AB07LDU,&var729);
  setData(idA1CV02RDU,&var1408);
  setData(idA1AD01LDU,&var1401);
  setData(idA1AD05LDU,&var1407);
  setData(idA1AD04LDU,&var1406);
  setData(idA1AD03LDU,&var1405);
  setData(idA1AD02LDU,&var1404);
  setData(idA1AD21LDU,&var1403);
  setData(idA1AD11LDU,&var1402);
  setData(idA1AZ03LDU,&var736);
  setData(idA1VS22LDU,&var1411);
  setData(idA1AB01LDU,&var734);
  setData(idA1AB02LDU,&var735);
  setData(idA1AB04LDU,&var1414);
  setData(idA1CV01RDU,&var1412);
  setData(idA1VS12LDU,&var1410);
  setData(idR1AD20LDU,&var1433);
  setData(idR1AD10LDU,&var1432);
  setData(idR2AB04LDU,&var1421);
  setData(idR1AB04LDU,&var1430);
  setData(idR2AB02LDU,&var1420);
  setData(idR2AB01LDU,&var1422);
  setData(idR2AZ03LDU,&var1419);
  setData(idR1AB02LDU,&var1429);
  setData(idR1AB01LDU,&var1431);
  setData(idR1AZ03LDU,&var1428);
  setData(idB2AB17LDU,&var692);
  setData(idB2AB16LDU,&var691);
  setData(idB2AB14LDU,&var936);
  setData(idB2AB13LDU,&var937);
  setData(idB2AB12LDU,&var693);
  setData(idB2AB11LDU,&var697);
  setData(idB2AB10LDU,&var696);
  setData(idB2AB09LDU,&var695);
  setData(idB2AB06LDU,&var700);
  setData(idB2AB05LDU,&var699);
  setData(idB2AB08LDU,&var694);
  setData(idB2AB07LDU,&var701);
  setData(idB2CV02RDU,&var1455);
  setData(idB2AD01LDU,&var1448);
  setData(idB2AD05LDU,&var1454);
  setData(idB2AD04LDU,&var1453);
  setData(idB2AD03LDU,&var1452);
  setData(idB2AD02LDU,&var1451);
  setData(idB2AD21LDU,&var1450);
  setData(idB2AD11LDU,&var1449);
  setData(idB2AZ03LDU,&var709);
  setData(idB2AB01LDU,&var708);
  setData(idB2AB02LDU,&var707);
  setData(idB2AB04LDU,&var1461);
  setData(idB2CV01RDU,&var1459);
  setData(idA2CV02RDU,&var1496);
  setData(idA2AD01LDU,&var1489);
  setData(idA2AB17LDU,&var630);
  setData(idA2AB16LDU,&var631);
  setData(idA2AB14LDU,&var634);
  setData(idA2AB13LDU,&var635);
  setData(idA2AB12LDU,&var632);
  setData(idA2AB11LDU,&var640);
  setData(idA2AB10LDU,&var638);
  setData(idA2AB09LDU,&var636);
  setData(idA2AB06LDU,&var641);
  setData(idA2AB05LDU,&var637);
  setData(idA2AB08LDU,&var633);
  setData(idA2AB07LDU,&var639);
  setData(idA2AD05LDU,&var1495);
  setData(idA2AD04LDU,&var1494);
  setData(idA2AD03LDU,&var1493);
  setData(idA2AD02LDU,&var1492);
  setData(idA2AD21LDU,&var1491);
  setData(idA2AD11LDU,&var1490);
  setData(idA2AZ03LDU,&var1001);
  setData(idA2VS21LDU,&var1501);
  setData(idA2AB01LDU,&var1498);
  setData(idA2AB02LDU,&var1499);
  setData(idA2AB04LDU,&var1504);
  setData(idA2CV01RDU,&var1502);
  setData(idA2VS11LDU,&var1500);
  setData(idA8AB01LDU,&var1512);
  setData(idA8AB02LDU,&var518);
  setData(idA8AB14LDU,&var519);
  setData(idA8AB13LDU,&var520);
  setData(idA8AB12LDU,&var522);
  setData(idA8AB11LDU,&var523);
  setData(idA8AB10LDU,&var524);
  setData(idA8AB09LDU,&var525);
  setData(idA8AB08LDU,&var526);
  setData(idA8AB04LDU,&var1511);
  setData(idA8AD20LDU,&var1467);
  setData(idA8AD10LDU,&var1466);
  setData(idA8AZ03LDU,&var991);
  setData(idA8VS22LDU,&var1514);
  setData(idA8AB05LDU,&var1509);
  setData(idA8AB07LDU,&var1510);
  setData(idA8AB06LDU,&var1517);
  setData(idA8CV01RDU,&var1515);
  setData(idA8VS12LDU,&var1513);
  setData(idB8AB02LDU,&var836);
  setData(idB8AB14LDU,&var837);
  setData(idB8AB13LDU,&var838);
  setData(idB8AB12LDU,&var839);
  setData(idB8AB11LDU,&var843);
  setData(idB8AB10LDU,&var840);
  setData(idB8AB09LDU,&var841);
  setData(idB8AB08LDU,&var842);
  setData(idB8AB04LDU,&var1528);
  setData(idB8AB01LDU,&var1529);
  setData(idB8AD20LDU,&var1477);
  setData(idB8AD10LDU,&var1476);
  setData(idB8AZ03LDU,&var992);
  setData(idB8VS22LDU,&var1531);
  setData(idB8AB05LDU,&var1520);
  setData(idB8AB07LDU,&var1521);
  setData(idB8AB06LDU,&var1534);
  setData(idB8CV01RDU,&var1532);
  setData(idB8VS12LDU,&var1530);
  setData(idA6AB05LDU,&var959);
  setData(idB6AB09LDU,&var958);
  setData(idB6AB08LDU,&var957);
  setData(idB6AB07LDU,&var956);
  setData(idB6AB06LDU,&var955);
  setData(idA6AB09LDU,&var960);
  setData(idA6AB08LDU,&var946);
  setData(idA6AB07LDU,&var148);
  setData(idA6AB06LDU,&var961);
  setData(idB5AB04LDU,&var1584);
  setData(idA5AB04LDU,&var1593);
  setData(idB4AB02LDU,&var1565);
  setData(idB4AB01LDU,&var1566);
  setData(idB4AZ03LDU,&var1564);
  setData(idA4AB02LDU,&var1574);
  setData(idA4AB01LDU,&var1575);
  setData(idA4AZ03LDU,&var1573);
  setData(idA4AD10LDU,&var1576);
  setData(idB4AD10LDU,&var1567);
  setData(idB5AB02LDU,&var1583);
  setData(idB5AB01LDU,&var1585);
  setData(idB5AZ03LDU,&var1582);
  setData(idA5AB02LDU,&var1592);
  setData(idA5AB01LDU,&var1594);
  setData(idA5AZ03LDU,&var1591);
  setData(idA5AD20LDU,&var1596);
  setData(idA5AD10LDU,&var1595);
  setData(idB5AD20LDU,&var1587);
  setData(idB5AD10LDU,&var1586);
  setData(idR4AD20LDU,&var1605);
  setData(idR4AD10LDU,&var1604);
  setData(idR4AB18LDU,&var889);
  setData(idR4AB17LDU,&var888);
  setData(idR4AB16LDU,&var891);
  setData(idR4AB15LDU,&var890);
  setData(idR4AB14LDU,&var892);
  setData(idR4AB13LDU,&var860);
  setData(idR4AB12LDU,&var865);
  setData(idR4AB11LDU,&var897);
  setData(idR4AB10LDU,&var862);
  setData(idR4AB09LDU,&var895);
  setData(idR4AB08LDU,&var894);
  setData(idR4AB07LDU,&var898);
  setData(idR4AB06LDU,&var1602);
  setData(idR4AB05LDU,&var1601);
  setData(idR4AB04LDU,&var1603);
  setData(idR4AB03LDU,&var899);
  setData(idR4AZ03LDU,&var1600);
  setData(idR4AB02LDU,&var902);
  setData(idR4AB01LDU,&var903);
  setData(idB6AB04LDU,&var1611);
  setData(idA6AB04LDU,&var1620);
  setData(idB6AB02LDU,&var1610);
  setData(idB6AB01LDU,&var1612);
  setData(idB6AZ03LDU,&var1609);
  setData(idA6AB02LDU,&var1619);
  setData(idA6AB01LDU,&var1621);
  setData(idA6AZ03LDU,&var1618);
  setData(idB6AD20LDU,&var1614);
  setData(idB6AD10LDU,&var1613);
  setData(idA6AD20LDU,&var1623);
  setData(idA6AD10LDU,&var1622);
  setData(idR0ES01LDU,&var907);

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
    array_m344_rz_1[i] = &(&internal1_m344_rz)[i*1];
  for( i=0;i<10;i++ )
    array_m287_rz_1[i] = &(&internal1_m287_rz)[i*1];
  for( i=0;i<6;i++ )
    array_m1424_rz_1[i] = &(&internal1_m1424_rz)[i*1];
  for( i=0;i<60;i++ )
    array_m1351_x0_1[i] = &(&internal1_m1351_x0)[i*5];
  for( i=0;i<60;i++ )
    array_m1351_tim0_1[i] = &(&internal1_m1351_tim0)[i*5];
  for( i=0;i<60;i++ )
    array_m939_x0_1[i] = &(&internal1_m939_x0)[i*5];
  for( i=0;i<60;i++ )
    array_m939_tim0_1[i] = &(&internal1_m939_tim0)[i*5];
  for( i=0;i<150;i++ )
    array_m535_x0_1[i] = &(&internal1_m535_x0)[i*5];
  for( i=0;i<150;i++ )
    array_m535_tim0_1[i] = &(&internal1_m535_tim0)[i*5];
  for( i=0;i<150;i++ )
    array_m213_x0_1[i] = &(&internal1_m213_x0)[i*5];
  for( i=0;i<150;i++ )
    array_m213_tim0_1[i] = &(&internal1_m213_tim0)[i*5];
  for( i=0;i<80;i++ )
    array_m846_x0_1[i] = &(&internal1_m846_x0)[i*5];
  for( i=0;i<80;i++ )
    array_m846_tim0_1[i] = &(&internal1_m846_tim0)[i*5];
  for( i=0;i<80;i++ )
    array_m1261_x0_1[i] = &(&internal1_m1261_x0)[i*5];
  for( i=0;i<80;i++ )
    array_m1261_tim0_1[i] = &(&internal1_m1261_tim0)[i*5];
  for( i=0;i<20;i++ )
    array_m1625_x0_1[i] = &(&internal1_m1625_x0)[i*5];
  for( i=0;i<20;i++ )
    array_m1625_tim0_1[i] = &(&internal1_m1625_tim0)[i*5];
  for( i=0;i<20;i++ )
    array_m1150_x0_1[i] = &(&internal1_m1150_x0)[i*5];
  for( i=0;i<20;i++ )
    array_m1150_tim0_1[i] = &(&internal1_m1150_tim0)[i*5];
}

#endif
