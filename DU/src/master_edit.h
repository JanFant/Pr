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
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MDuBz1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MDuBz1[]={  // 
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
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MDuBz2[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MDuBz2[]={  // 
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
// checked_ 0  |  if( not aknp||rpu) AddCodeAknp()
// checked_ 1  | if(ExistFile(Scheme.h)) AddCode_H(  DU\Scheme\Scheme.h
// DU\Scheme\Scheme.h
#endif
