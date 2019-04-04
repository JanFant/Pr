#ifndef DU_H
#define DU_H
// Подсистема DU:DU
static char SimulOn=0;
static short CodeSub=2;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 10834
static char BUFFER[10834];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.50\0", 5432, "192.168.10.150\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define A2AB15LDU	 BUFFER[0]	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define idA2AB15LDU	 1	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define B2AB15LDU	 BUFFER[2]	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define idB2AB15LDU	 2	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define R0AD21LDU	 BUFFER[4]	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
#define idR0AD21LDU	 3	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
#define R0VX02LDU	 BUFFER[6]	//( - , DU) Импульс разрешен
#define idR0VX02LDU	 4	//( - , DU) Импульс разрешен
#define R0EE03LDU	 BUFFER[8]	//( - , DU) ВПИС ИС
#define idR0EE03LDU	 5	//( - , DU) ВПИС ИС
#define R0AB07LDU	 BUFFER[10]	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
#define idR0AB07LDU	 6	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
#define R0AD16LDU	 BUFFER[12]	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
#define idR0AD16LDU	 7	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
#define C2MD31LP1	 BUFFER[14]	//( - , DU) Кнопка СБРОС РБ
#define idC2MD31LP1	 8	//( - , DU) Кнопка СБРОС РБ
#define B6VS01IDU	 BUFFER[16]	//( - , DU) Готовность к управлению БЗ2
#define idB6VS01IDU	 9	//( - , DU) Готовность к управлению БЗ2
#define R2AD20LDU	 BUFFER[19]	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
#define idR2AD20LDU	 10	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
#define R2AD10LDU	 BUFFER[21]	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
#define idR2AD10LDU	 11	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
#define B8VS01IDU	 BUFFER[23]	//( - , DU) Готовность к управлению АЗ2
#define idB8VS01IDU	 12	//( - , DU) Готовность к управлению АЗ2
#define A8VS01IDU	 BUFFER[26]	//( - , DU) Готовность к управлению ДС2
#define idA8VS01IDU	 13	//( - , DU) Готовность к управлению ДС2
#define A1IE03LDU	 BUFFER[29]	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
#define idA1IE03LDU	 14	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
#define A1IE04LDU	 BUFFER[31]	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
#define idA1IE04LDU	 15	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
#define A2IE03LDU	 BUFFER[33]	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
#define idA2IE03LDU	 16	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
#define A2IE04LDU	 BUFFER[35]	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
#define idA2IE04LDU	 17	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
#define A3IE03LDU	 BUFFER[37]	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
#define idA3IE03LDU	 18	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
#define A3IE04LDU	 BUFFER[39]	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
#define idA3IE04LDU	 19	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
#define B1IE03LDU	 BUFFER[41]	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
#define idB1IE03LDU	 20	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
#define B1IE04LDU	 BUFFER[43]	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
#define idB1IE04LDU	 21	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
#define B2IE03LDU	 BUFFER[45]	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
#define idB2IE03LDU	 22	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
#define B2IE04LDU	 BUFFER[47]	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
#define idB2IE04LDU	 23	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
#define A1AB19LDU	 BUFFER[49]	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
#define idA1AB19LDU	 24	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
#define R0AD14LZ1	 BUFFER[51]	//(vds32:02 - K20VDSR, - ) Имитация срабатывания АЗ от II УР
#define idR0AD14LZ1	 25	//(vds32:02 - K20VDSR, - ) Имитация срабатывания АЗ от II УР
#define R0AD14LZ2	 BUFFER[53]	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
#define idR0AD14LZ2	 26	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
#define A3VZ13LZ2	 BUFFER[55]	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ2	 27	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define A3VZ13LZ1	 BUFFER[57]	//(vds32:02 - K18VDSR, - ) Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ1	 28	//(vds32:02 - K18VDSR, - ) Имитация срабатывания АЗ от ВУ ИС
#define A3VZ15LZ1	 BUFFER[59]	//(vds32:02 - K19VDSR, - ) Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ1	 29	//(vds32:02 - K19VDSR, - ) Имитация срабатывания АЗ от НУП ИС
#define A3VZ15LZ2	 BUFFER[61]	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ2	 30	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define B2IS33LDU	 BUFFER[63]	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
#define idB2IS33LDU	 31	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
#define B3IS31LDU	 BUFFER[65]	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
#define idB3IS31LDU	 32	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
#define B3IS33LDU	 BUFFER[67]	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
#define idB3IS33LDU	 33	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
#define B3IS35LDU	 BUFFER[69]	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
#define idB3IS35LDU	 34	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
#define B4IS10LDU	 BUFFER[71]	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
#define idB4IS10LDU	 35	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
#define R6IS31LDU	 BUFFER[73]	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
#define idR6IS31LDU	 36	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
#define R6IS32LDU	 BUFFER[75]	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
#define idR6IS32LDU	 37	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
#define R6IS42LDU	 BUFFER[77]	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
#define idR6IS42LDU	 38	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
#define R6IS41LDU	 BUFFER[79]	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
#define idR6IS41LDU	 39	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
#define R6IS52LDU	 BUFFER[81]	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
#define idR6IS52LDU	 40	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
#define R6IS51LDU	 BUFFER[83]	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
#define idR6IS51LDU	 41	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
#define R3IS11LDU	 BUFFER[85]	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
#define idR3IS11LDU	 42	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
#define R3IS21LDU	 BUFFER[87]	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
#define idR3IS21LDU	 43	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
#define R0AB03LDU	 BUFFER[89]	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
#define idR0AB03LDU	 44	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
#define R0AB05LDU	 BUFFER[91]	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
#define idR0AB05LDU	 45	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
#define R0VN11RZ1	 BUFFER[93]	//( - , MDuBz1) Средняя мощность по BAZ1
#define idR0VN11RZ1	 46	//( - , MDuBz1) Средняя мощность по BAZ1
#define R0VN11RZ2	 BUFFER[98]	//( - , MDuBz2) Средняя мощность по BAZ2
#define idR0VN11RZ2	 47	//( - , MDuBz2) Средняя мощность по BAZ2
#define A4UP	 BUFFER[103]	//( - , DU) 
#define idA4UP	 48	//( - , DU) 
#define A4DW	 BUFFER[105]	//( - , DU) 
#define idA4DW	 49	//( - , DU) 
#define R0AB14LDU	 BUFFER[107]	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
#define idR0AB14LDU	 50	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
#define R0AB15LDU	 BUFFER[109]	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
#define idR0AB15LDU	 51	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
#define A3IS12LDU	 BUFFER[111]	//( - , DU) Приход на ВУ штока ИС1
#define idA3IS12LDU	 52	//( - , DU) Приход на ВУ штока ИС1
#define B3IS12LDU	 BUFFER[113]	//( - , DU) Приход на ВУ штока ИС2
#define idB3IS12LDU	 53	//( - , DU) Приход на ВУ штока ИС2
#define A1ZAV	 BUFFER[115]	//( - , DU) 
#define idA1ZAV	 54	//( - , DU) 
#define A3ZAV	 BUFFER[117]	//( - , DU) 
#define idA3ZAV	 55	//( - , DU) 
#define B1AB19LDU	 BUFFER[119]	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
#define idB1AB19LDU	 56	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
#define R0VN09RZ2	 BUFFER[121]	//( - , MDuBz2) Усредненный период разгона
#define idR0VN09RZ2	 57	//( - , MDuBz2) Усредненный период разгона
#define R0VN09RZ1	 BUFFER[126]	//( - , MDuBz1) Усредненный период разгона
#define idR0VN09RZ1	 58	//( - , MDuBz1) Усредненный период разгона
#define R0AB16LDU	 BUFFER[131]	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
#define idR0AB16LDU	 59	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
#define R0AB17LDU	 BUFFER[133]	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
#define idR0AB17LDU	 60	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
#define R0AB18LDU	 BUFFER[135]	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
#define idR0AB18LDU	 61	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
#define A0CT01IZ1	 BUFFER[137]	//( - , MDuBz1) Температура АЗ1-1
#define idA0CT01IZ1	 62	//( - , MDuBz1) Температура АЗ1-1
#define B0CT01IZ1	 BUFFER[142]	//( - , MDuBz1) Температура АЗ2-1
#define idB0CT01IZ1	 63	//( - , MDuBz1) Температура АЗ2-1
#define A0CT01IZ2	 BUFFER[147]	//( - , MDuBz2) Температура АЗ1-2
#define idA0CT01IZ2	 64	//( - , MDuBz2) Температура АЗ1-2
#define B0CT01IZ2	 BUFFER[152]	//( - , MDuBz2) Температура АЗ2-2
#define idB0CT01IZ2	 65	//( - , MDuBz2) Температура АЗ2-2
#define A3MC01RDU	 BUFFER[157]	//( - , DU) Заданная координата положения ИС от регулятора мм
#define idA3MC01RDU	 66	//( - , DU) Заданная координата положения ИС от регулятора мм
#define A3MC02RDU	 BUFFER[162]	//( - , DU) Температурная корректировка координаты ИМ
#define idA3MC02RDU	 67	//( - , DU) Температурная корректировка координаты ИМ
#define R0CN91LDU	 BUFFER[167]	//( - , DU) Рассчётная реактивность от регулятора
#define idR0CN91LDU	 68	//( - , DU) Рассчётная реактивность от регулятора
#define A3MC03RDU	 BUFFER[172]	//( - , DU) Координата положения ИМ 0-й реактивности
#define idA3MC03RDU	 69	//( - , DU) Координата положения ИМ 0-й реактивности
#define A3AB15LDU	 BUFFER[177]	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
#define idA3AB15LDU	 70	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
#define B3IE03LDU	 BUFFER[179]	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
#define idB3IE03LDU	 71	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
#define B3IE04LDU	 BUFFER[181]	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
#define idB3IE04LDU	 72	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
#define R0VS11LDU	 BUFFER[183]	//( - , DU) РУ не готова к работе
#define idR0VS11LDU	 73	//( - , DU) РУ не готова к работе
#define B6AB05LDU	 BUFFER[185]	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
#define idB6AB05LDU	 74	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
#define R0AB08LDU	 BUFFER[187]	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
#define idR0AB08LDU	 75	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
#define A1MC01RP1	 BUFFER[189]	//( - , DU) Заданная координата положения ББ1 мм
#define idA1MC01RP1	 76	//( - , DU) Заданная координата положения ББ1 мм
#define B1MC01RP1	 BUFFER[194]	//( - , DU) Заданная координата положения ББ2  мм
#define idB1MC01RP1	 77	//( - , DU) Заданная координата положения ББ2  мм
#define A3MC01RP1	 BUFFER[199]	//( - , DU) Заданная координата положения ИС1 мм
#define idA3MC01RP1	 78	//( - , DU) Заданная координата положения ИС1 мм
#define B3MC01RP1	 BUFFER[204]	//( - , DU) Заданная координата положения ИС2 мм
#define idB3MC01RP1	 79	//( - , DU) Заданная координата положения ИС2 мм
#define B8MC01RP2	 BUFFER[209]	//( - , DU) Заданная координата АЗ2 мм
#define idB8MC01RP2	 80	//( - , DU) Заданная координата АЗ2 мм
#define R0AB09LDU	 BUFFER[214]	//( - , DU) Ошибка в заданной координате ББ1
#define idR0AB09LDU	 81	//( - , DU) Ошибка в заданной координате ББ1
#define R0AB10LDU	 BUFFER[216]	//( - , DU) Ошибка в заданной координате ББ2
#define idR0AB10LDU	 82	//( - , DU) Ошибка в заданной координате ББ2
#define R0AB11LDU	 BUFFER[218]	//( - , DU) Ошибка в заданной координате  ИС1
#define idR0AB11LDU	 83	//( - , DU) Ошибка в заданной координате  ИС1
#define R0AB12LDU	 BUFFER[220]	//( - , DU) Ошибка в заданной координате  ИС2
#define idR0AB12LDU	 84	//( - , DU) Ошибка в заданной координате  ИС2
#define R0AB13LDU	 BUFFER[222]	//( - , DU) Ошибка в заданной координате  АЗ2
#define idR0AB13LDU	 85	//( - , DU) Ошибка в заданной координате  АЗ2
#define A4ZAV	 BUFFER[224]	//( - , DU) 
#define idA4ZAV	 86	//( - , DU) 
#define A6ZAV	 BUFFER[226]	//( - , DU) 
#define idA6ZAV	 87	//( - , DU) 
#define R2ZAV	 BUFFER[228]	//( - , DU) 
#define idR2ZAV	 88	//( - , DU) 
#define A5ZAV	 BUFFER[230]	//( - , DU) 
#define idA5ZAV	 89	//( - , DU) 
#define B8ZAV	 BUFFER[232]	//( - , DU) 
#define idB8ZAV	 90	//( - , DU) 
#define A2ZAV	 BUFFER[234]	//( - , DU) Завершение РБ1,2
#define idA2ZAV	 91	//( - , DU) Завершение РБ1,2
#define A8ZAV	 BUFFER[236]	//( - , DU) 
#define idA8ZAV	 92	//( - , DU) 
#define A9ZAV	 BUFFER[238]	//( - , DU) Завершение НИ ДС1(2)
#define idA9ZAV	 93	//( - , DU) Завершение НИ ДС1(2)
#define R4ABL	 BUFFER[240]	//( - , DU) Блокировка тележки -
#define idR4ABL	 94	//( - , DU) Блокировка тележки -
#define B9AB01LDU	 BUFFER[242]	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
#define idB9AB01LDU	 95	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
#define B9AB02LDU	 BUFFER[244]	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
#define idB9AB02LDU	 96	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
#define R0AB01LDU	 BUFFER[246]	//( - , DU) Режим проверки разрешён
#define idR0AB01LDU	 97	//( - , DU) Режим проверки разрешён
#define A3IS22LDU	 BUFFER[248]	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
#define idA3IS22LDU	 98	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
#define B3IS22LDU	 BUFFER[250]	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
#define idB3IS22LDU	 99	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
#define A2AD33LDU	 BUFFER[252]	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
#define idA2AD33LDU	 100	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
#define B2AD33LDU	 BUFFER[254]	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
#define idB2AD33LDU	 101	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
#define A3AD33LDU	 BUFFER[256]	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
#define idA3AD33LDU	 102	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
#define A3AD34LDU	 BUFFER[258]	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
#define idA3AD34LDU	 103	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
#define A3AD31LDU	 BUFFER[260]	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
#define idA3AD31LDU	 104	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
#define B3AD34LDU	 BUFFER[262]	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
#define idB3AD34LDU	 105	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
#define B3AD31LDU	 BUFFER[264]	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
#define idB3AD31LDU	 106	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
#define A2IS11LDU	 BUFFER[266]	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
#define idA2IS11LDU	 107	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
#define B2IS11LDU	 BUFFER[268]	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
#define idB2IS11LDU	 108	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
#define A3MD12LP1	 BUFFER[270]	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
#define idA3MD12LP1	 109	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
#define A3MD11LP1	 BUFFER[272]	//( - , DU) Кнопка ПУСК ИС1
#define idA3MD11LP1	 110	//( - , DU) Кнопка ПУСК ИС1
#define R0MD33LP1	 BUFFER[274]	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
#define idR0MD33LP1	 111	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
#define A1MD12LP1	 BUFFER[276]	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
#define idA1MD12LP1	 112	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
#define A1MD11LP1	 BUFFER[278]	//( - , DU) Кнопка ПУСК ББ1
#define idA1MD11LP1	 113	//( - , DU) Кнопка ПУСК ББ1
#define R0MW14IP2	 BUFFER[280]	//( - , DU) Переключатель ОБДУВ
#define idR0MW14IP2	 114	//( - , DU) Переключатель ОБДУВ
#define A7AP31LDU	 BUFFER[283]	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
#define idA7AP31LDU	 115	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
#define B7AP31LDU	 BUFFER[285]	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
#define idB7AP31LDU	 116	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
#define R0MW12IP2	 BUFFER[287]	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define idR0MW12IP2	 117	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define B3VS01IDU	 BUFFER[290]	//( - , DU) Готовность к управлению ИС2
#define idB3VS01IDU	 118	//( - , DU) Готовность к управлению ИС2
#define A2VS01IDU	 BUFFER[293]	//( - , DU) Готовность к управлению РБ1
#define idA2VS01IDU	 119	//( - , DU) Готовность к управлению РБ1
#define A4VS01IDU	 BUFFER[296]	//( - , DU) Готовность к управлению НИ1
#define idA4VS01IDU	 120	//( - , DU) Готовность к управлению НИ1
#define A4VS12LDU	 BUFFER[299]	//( - , DU) Движение НИ1 в сторону ВУ
#define idA4VS12LDU	 121	//( - , DU) Движение НИ1 в сторону ВУ
#define A4VS22LDU	 BUFFER[301]	//( - , DU) Движение НИ1 в сторону НУ
#define idA4VS22LDU	 122	//( - , DU) Движение НИ1 в сторону НУ
#define B4VS01IDU	 BUFFER[303]	//( - , DU) Готовность к управлению НИ2
#define idB4VS01IDU	 123	//( - , DU) Готовность к управлению НИ2
#define B4VS12LDU	 BUFFER[306]	//( - , DU) Движение НИ2 в сторону ВУ
#define idB4VS12LDU	 124	//( - , DU) Движение НИ2 в сторону ВУ
#define B4VS22LDU	 BUFFER[308]	//( - , DU) Движение НИ2 в сторону НУ
#define idB4VS22LDU	 125	//( - , DU) Движение НИ2 в сторону НУ
#define A5VS01IDU	 BUFFER[310]	//( - , DU) Готовность к управлению НЛ1
#define idA5VS01IDU	 126	//( - , DU) Готовность к управлению НЛ1
#define B5VS01IDU	 BUFFER[313]	//( - , DU) Готовность к управлению НЛ2
#define idB5VS01IDU	 127	//( - , DU) Готовность к управлению НЛ2
#define A6VS01IDU	 BUFFER[316]	//( - , DU) Готовность к управлению БЗ1
#define idA6VS01IDU	 128	//( - , DU) Готовность к управлению БЗ1
#define R4VS01IDU	 BUFFER[319]	//( - , DU) Готовность к управлению тележкой реактора
#define idR4VS01IDU	 129	//( - , DU) Готовность к управлению тележкой реактора
#define R2VS01IDU	 BUFFER[322]	//( - , DU) Готовность к управлению МДЗ2
#define idR2VS01IDU	 130	//( - , DU) Готовность к управлению МДЗ2
#define R1VS01IDU	 BUFFER[325]	//( - , DU) Готовность к управлению МДЗ1
#define idR1VS01IDU	 131	//( - , DU) Готовность к управлению МДЗ1
#define A9IS11LDU	 BUFFER[328]	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
#define idA9IS11LDU	 132	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
#define A9IS21LDU	 BUFFER[330]	//(vds32:02 - K24VDSR, - ) Приход на НУ НИ ДС1
#define idA9IS21LDU	 133	//(vds32:02 - K24VDSR, - ) Приход на НУ НИ ДС1
#define B9IS11LDU	 BUFFER[332]	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
#define idB9IS11LDU	 134	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
#define B9IS21LDU	 BUFFER[334]	//(vds32:02 - K26VDSR, - ) Приход на НУ НИ ДС2
#define idB9IS21LDU	 135	//(vds32:02 - K26VDSR, - ) Приход на НУ НИ ДС2
#define B9AD10LDU	 BUFFER[336]	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
#define idB9AD10LDU	 136	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
#define A9AD10LDU	 BUFFER[338]	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
#define idA9AD10LDU	 137	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
#define A9AZ03LDU	 BUFFER[340]	//( - , DU) Несанкционированное перемещение НИ ДС1
#define idA9AZ03LDU	 138	//( - , DU) Несанкционированное перемещение НИ ДС1
#define A9AB01LDU	 BUFFER[342]	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
#define idA9AB01LDU	 139	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
#define A9AB02LDU	 BUFFER[344]	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
#define idA9AB02LDU	 140	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
#define B9AZ03LDU	 BUFFER[346]	//( - , DU) Несанкционированное перемещение НИ ДС2
#define idB9AZ03LDU	 141	//( - , DU) Несанкционированное перемещение НИ ДС2
#define A0VT71LZ1	 BUFFER[348]	//( - , MDuBz1) АС по температуре в АЗ1
#define idA0VT71LZ1	 142	//( - , MDuBz1) АС по температуре в АЗ1
#define B0VT71LZ1	 BUFFER[350]	//( - , MDuBz1) АС по температуре в АЗ2
#define idB0VT71LZ1	 143	//( - , MDuBz1) АС по температуре в АЗ2
#define A0VT71LZ2	 BUFFER[352]	//( - , MDuBz2) АС по температуре в АЗ1
#define idA0VT71LZ2	 144	//( - , MDuBz2) АС по температуре в АЗ1
#define B0VT71LZ2	 BUFFER[354]	//( - , MDuBz2) АС по температуре в АЗ2
#define idB0VT71LZ2	 145	//( - , MDuBz2) АС по температуре в АЗ2
#define B2VS11LDU	 BUFFER[356]	//( - , DU) Движение РБ2 в сторону ВУ
#define idB2VS11LDU	 146	//( - , DU) Движение РБ2 в сторону ВУ
#define B2VS21LDU	 BUFFER[358]	//( - , DU) Движение РБ2 в сторону НУ
#define idB2VS21LDU	 147	//( - , DU) Движение РБ2 в сторону НУ
#define B2VS01IDU	 BUFFER[360]	//( - , DU) Готовность к управлению РБ2
#define idB2VS01IDU	 148	//( - , DU) Готовность к управлению РБ2
#define A7AS31LDU	 BUFFER[363]	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
#define idA7AS31LDU	 149	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
#define B7AS31LDU	 BUFFER[365]	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
#define idB7AS31LDU	 150	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
#define A7AZ03LDU	 BUFFER[367]	//( - , DU) Несанкционированное включение обдува АЗ1
#define idA7AZ03LDU	 151	//( - , DU) Несанкционированное включение обдува АЗ1
#define B7AZ03LDU	 BUFFER[369]	//( - , DU) Несанкционированное включение обдува АЗ2
#define idB7AZ03LDU	 152	//( - , DU) Несанкционированное включение обдува АЗ2
#define B3MD12LP1	 BUFFER[371]	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
#define idB3MD12LP1	 153	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
#define B3MD11LP1	 BUFFER[373]	//( - , DU) Кнопка ПУСК ИС2
#define idB3MD11LP1	 154	//( - , DU) Кнопка ПУСК ИС2
#define R0VL01RDU	 BUFFER[375]	//( - , DU) Индикация Время задержки
#define idR0VL01RDU	 155	//( - , DU) Индикация Время задержки
#define R0VZ71LZ2	 BUFFER[380]	//(vds32:03 - K22VDSR, DU) Обобщенный сигнал АЗ 2 канала
#define idR0VZ71LZ2	 156	//(vds32:03 - K22VDSR, DU) Обобщенный сигнал АЗ 2 канала
#define R0VZ71LZ1	 BUFFER[382]	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
#define idR0VZ71LZ1	 157	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
#define R0VZ71LDU	 BUFFER[384]	//( - , DU) Обобщенный сигнал АЗ
#define idR0VZ71LDU	 158	//( - , DU) Обобщенный сигнал АЗ
#define A2IS33LDU	 BUFFER[386]	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
#define idA2IS33LDU	 159	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
#define A3IS31LDU	 BUFFER[388]	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
#define idA3IS31LDU	 160	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
#define A3IS33LDU	 BUFFER[390]	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
#define idA3IS33LDU	 161	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
#define A3IS35LDU	 BUFFER[392]	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
#define idA3IS35LDU	 162	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
#define A4IS10LDU	 BUFFER[394]	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
#define idA4IS10LDU	 163	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
#define A1VN71LZ1	 BUFFER[396]	//(vds32:02 - K21VDSR, - ) Блокировка автоматического подъёма ББ
#define idA1VN71LZ1	 164	//(vds32:02 - K21VDSR, - ) Блокировка автоматического подъёма ББ
#define A1VN71LZ2	 BUFFER[398]	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define idA1VN71LZ2	 165	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define R0MW17LP1	 BUFFER[400]	//( - , DU) Переключатель АВТ/Р
#define idR0MW17LP1	 166	//( - , DU) Переключатель АВТ/Р
#define R0VW13LDU	 BUFFER[402]	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
#define idR0VW13LDU	 167	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
#define R0VW23LDU	 BUFFER[404]	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
#define idR0VW23LDU	 168	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
#define R0VX08IDU	 BUFFER[406]	//( - , DU) Индикация Режим
#define idR0VX08IDU	 169	//( - , DU) Индикация Режим
#define R0VX09LDU	 BUFFER[409]	//( - , DU) Индикация регулятор мощности включен/отключен
#define idR0VX09LDU	 170	//( - , DU) Индикация регулятор мощности включен/отключен
#define R0VS17LDU	 BUFFER[411]	//( - , DU) Индикация выбора АВТОМАТ
#define idR0VS17LDU	 171	//( - , DU) Индикация выбора АВТОМАТ
#define A2VS32LDU	 BUFFER[413]	//( - , DU) Индикация  СБРОС РБ1
#define idA2VS32LDU	 172	//( - , DU) Индикация  СБРОС РБ1
#define B2VS32LDU	 BUFFER[415]	//( - , DU) Индикация  СБРОС РБ2
#define idB2VS32LDU	 173	//( - , DU) Индикация  СБРОС РБ2
#define A3VX01LDU	 BUFFER[417]	//( - , DU) Индикация Выстрел ИС1
#define idA3VX01LDU	 174	//( - , DU) Индикация Выстрел ИС1
#define A3IS11LDU	 BUFFER[419]	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
#define idA3IS11LDU	 175	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
#define B3VX01LDU	 BUFFER[421]	//( - , DU) Индикация Выстрел ИС2
#define idB3VX01LDU	 176	//( - , DU) Индикация Выстрел ИС2
#define R0VS18LDU	 BUFFER[423]	//( - , DU) Индикация  Проверка схем сброса
#define idR0VS18LDU	 177	//( - , DU) Индикация  Проверка схем сброса
#define B1MD11LP1	 BUFFER[425]	//( - , DU) Кнопка ПУСК ББ2
#define idB1MD11LP1	 178	//( - , DU) Кнопка ПУСК ББ2
#define B1MD12LP1	 BUFFER[427]	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
#define idB1MD12LP1	 179	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
#define B2MD11LP1	 BUFFER[429]	//( - , DU) Кнопка ПУСК РБ2
#define idB2MD11LP1	 180	//( - , DU) Кнопка ПУСК РБ2
#define B2MD12LP1	 BUFFER[431]	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
#define idB2MD12LP1	 181	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
#define A2MD11LP1	 BUFFER[433]	//( - , DU) Кнопка ПУСК РБ1
#define idA2MD11LP1	 182	//( - , DU) Кнопка ПУСК РБ1
#define A2MD12LP1	 BUFFER[435]	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
#define idA2MD12LP1	 183	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
#define R0IS01LDU	 BUFFER[437]	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
#define idR0IS01LDU	 184	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
#define R0IS02LDU	 BUFFER[439]	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
#define idR0IS02LDU	 185	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
#define R0VP73LZ1	 BUFFER[441]	//( - , MDuBz1) ПС давления для РУ
#define idR0VP73LZ1	 186	//( - , MDuBz1) ПС давления для РУ
#define R0VP73LZ2	 BUFFER[443]	//( - , MDuBz2) ПС давления для РУ
#define idR0VP73LZ2	 187	//( - , MDuBz2) ПС давления для РУ
#define R0VP73LDU	 BUFFER[445]	//( - , DU) ПС давления для РУ
#define idR0VP73LDU	 188	//( - , DU) ПС давления для РУ
#define R0MD34LP1	 BUFFER[447]	//( - , DU) Кнопка КВИТИРОВАТЬ
#define idR0MD34LP1	 189	//( - , DU) Кнопка КВИТИРОВАТЬ
#define A0EE02LZ2	 BUFFER[449]	//( - , MDuBz2) Исправность АКНП2
#define idA0EE02LZ2	 190	//( - , MDuBz2) Исправность АКНП2
#define A0EE04LZ2	 BUFFER[451]	//( - , MDuBz2) Исправность АКНП4
#define idA0EE04LZ2	 191	//( - , MDuBz2) Исправность АКНП4
#define A0VP71LZ1	 BUFFER[453]	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ1	 192	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
#define A0VP71LZ2	 BUFFER[455]	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ2	 193	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
#define B0VP71LZ1	 BUFFER[457]	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ1	 194	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
#define B0VP71LZ2	 BUFFER[459]	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ2	 195	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
#define A0VS11LDU	 BUFFER[461]	//( - , DU) АЗ1 готова к работе
#define idA0VS11LDU	 196	//( - , DU) АЗ1 готова к работе
#define B0VS11LDU	 BUFFER[463]	//( - , DU) АЗ2 готова к работе
#define idB0VS11LDU	 197	//( - , DU) АЗ2 готова к работе
#define A1IE01LDU	 BUFFER[465]	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
#define idA1IE01LDU	 198	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
#define A3IE01LDU	 BUFFER[467]	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
#define idA3IE01LDU	 199	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
#define A2IE01LDU	 BUFFER[469]	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
#define idA2IE01LDU	 200	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
#define A1IE02LDU	 BUFFER[471]	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
#define idA1IE02LDU	 201	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
#define A3IE02LDU	 BUFFER[473]	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
#define idA3IE02LDU	 202	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
#define A2IE02LDU	 BUFFER[475]	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
#define idA2IE02LDU	 203	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
#define B1IE01LDU	 BUFFER[477]	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
#define idB1IE01LDU	 204	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
#define B2IE01LDU	 BUFFER[479]	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
#define idB2IE01LDU	 205	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
#define B3IE01LDU	 BUFFER[481]	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
#define idB3IE01LDU	 206	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
#define B1IE02LDU	 BUFFER[483]	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
#define idB1IE02LDU	 207	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
#define B3IE02LDU	 BUFFER[485]	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
#define idB3IE02LDU	 208	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
#define B2IE02LDU	 BUFFER[487]	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
#define idB2IE02LDU	 209	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
#define R0IE02LDU	 BUFFER[489]	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
#define idR0IE02LDU	 210	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
#define R0IE01LDU	 BUFFER[491]	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
#define idR0IE01LDU	 211	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
#define A6IE01LDU	 BUFFER[493]	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
#define idA6IE01LDU	 212	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
#define A8MC01LC1	 BUFFER[495]	//( - , DU) Настроить энкодер ДС2
#define idA8MC01LC1	 213	//( - , DU) Настроить энкодер ДС2
#define A8MC01LC2	 BUFFER[497]	//( - , DU) Настроить энкодер ДС2
#define idA8MC01LC2	 214	//( - , DU) Настроить энкодер ДС2
#define A3VP42LDU	 BUFFER[499]	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
#define idA3VP42LDU	 215	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
#define A3CP02RDU	 BUFFER[501]	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
#define idA3CP02RDU	 216	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
#define A3VP52LDU	 BUFFER[506]	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define idA3VP52LDU	 217	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define B3VP42LDU	 BUFFER[508]	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
#define idB3VP42LDU	 218	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
#define B3CP02RDU	 BUFFER[510]	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
#define idB3CP02RDU	 219	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
#define B3VP52LDU	 BUFFER[515]	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define idB3VP52LDU	 220	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define B3VP82LDU	 BUFFER[517]	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
#define idB3VP82LDU	 221	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
#define A3VP82LDU	 BUFFER[519]	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
#define idA3VP82LDU	 222	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
#define A3IP02IDU	 BUFFER[521]	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	 223	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
#define B3IP02IDU	 BUFFER[524]	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
#define idB3IP02IDU	 224	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
#define A0VE01LDU	 BUFFER[527]	//( - , DU) Напряжение в системы АЗ1 подано
#define idA0VE01LDU	 225	//( - , DU) Напряжение в системы АЗ1 подано
#define B0VE01LDU	 BUFFER[529]	//( - , DU) Напряжение в системы АЗ2 подано
#define idB0VE01LDU	 226	//( - , DU) Напряжение в системы АЗ2 подано
#define A0VP01LDU	 BUFFER[531]	//( - , DU) Давление в системы АЗ1 подано
#define idA0VP01LDU	 227	//( - , DU) Давление в системы АЗ1 подано
#define B0VP01LDU	 BUFFER[533]	//( - , DU) Давление в системы АЗ2 подано
#define idB0VP01LDU	 228	//( - , DU) Давление в системы АЗ2 подано
#define A0EE01LZ1	 BUFFER[535]	//( - , MDuBz1) Исправность АКНП1
#define idA0EE01LZ1	 229	//( - , MDuBz1) Исправность АКНП1
#define A0EE03LZ1	 BUFFER[537]	//( - , MDuBz1) Исправность АКНП3
#define idA0EE03LZ1	 230	//( - , MDuBz1) Исправность АКНП3
#define A0EE02LZ1	 BUFFER[539]	//( - , MDuBz1) Исправность АКНП2
#define idA0EE02LZ1	 231	//( - , MDuBz1) Исправность АКНП2
#define A0EE04LZ1	 BUFFER[541]	//( - , MDuBz1) Исправность АКНП4
#define idA0EE04LZ1	 232	//( - , MDuBz1) Исправность АКНП4
#define A0VN01LDU	 BUFFER[543]	//( - , DU) Каналы АЗ1 проверены
#define idA0VN01LDU	 233	//( - , DU) Каналы АЗ1 проверены
#define B0VN01LDU	 BUFFER[545]	//( - , DU) Каналы АЗ2 проверены
#define idB0VN01LDU	 234	//( - , DU) Каналы АЗ2 проверены
#define A0EE01LZ2	 BUFFER[547]	//( - , MDuBz2) Исправность АКНП1
#define idA0EE01LZ2	 235	//( - , MDuBz2) Исправность АКНП1
#define A0EE03LZ2	 BUFFER[549]	//( - , MDuBz2) Исправность АКНП3
#define idA0EE03LZ2	 236	//( - , MDuBz2) Исправность АКНП3
#define B3VP81LDU	 BUFFER[551]	//( - , MDuS) Давление СПУСК ИС2 в норме
#define idB3VP81LDU	 237	//( - , MDuS) Давление СПУСК ИС2 в норме
#define R0EE02LDU	 BUFFER[553]	//( - , DU) Питание  АКНП  отключить
#define idR0EE02LDU	 238	//( - , DU) Питание  АКНП  отключить
#define KKL1	 BUFFER[555]	//( - , - ) 
#define idKKL1	 239	//( - , - ) 
#define KKL2	 BUFFER[557]	//( - , - ) 
#define idKKL2	 240	//( - , - ) 
#define KKL3	 BUFFER[559]	//( - , - ) 
#define idKKL3	 241	//( - , - ) 
#define KKL4	 BUFFER[561]	//( - , - ) 
#define idKKL4	 242	//( - , - ) 
#define KKL5	 BUFFER[563]	//( - , - ) 
#define idKKL5	 243	//( - , - ) 
#define KKL6	 BUFFER[565]	//( - , - ) 
#define idKKL6	 244	//( - , - ) 
#define KKL7	 BUFFER[567]	//( - , - ) 
#define idKKL7	 245	//( - , - ) 
#define KKL8	 BUFFER[569]	//( - , - ) 
#define idKKL8	 246	//( - , - ) 
#define KKL9	 BUFFER[571]	//( - , - ) 
#define idKKL9	 247	//( - , - ) 
#define hz1	 BUFFER[573]	//( - , - ) 
#define idhz1	 248	//( - , - ) 
#define hz2	 BUFFER[575]	//( - , - ) 
#define idhz2	 249	//( - , - ) 
#define hz3	 BUFFER[577]	//( - , - ) 
#define idhz3	 250	//( - , - ) 
#define hz4	 BUFFER[579]	//( - , - ) 
#define idhz4	 251	//( - , - ) 
#define hz5	 BUFFER[581]	//( - , - ) 
#define idhz5	 252	//( - , - ) 
#define hz6	 BUFFER[583]	//( - , - ) 
#define idhz6	 253	//( - , - ) 
#define bd1	 BUFFER[585]	//( - , - ) 
#define idbd1	 254	//( - , - ) 
#define bd2	 BUFFER[587]	//( - , - ) 
#define idbd2	 255	//( - , - ) 
#define bd3	 BUFFER[589]	//( - , - ) 
#define idbd3	 256	//( - , - ) 
#define bd4	 BUFFER[591]	//( - , - ) 
#define idbd4	 257	//( - , - ) 
#define bd5	 BUFFER[593]	//( - , - ) 
#define idbd5	 258	//( - , - ) 
#define bd6	 BUFFER[595]	//( - , - ) 
#define idbd6	 259	//( - , - ) 
#define B6IE01LDU	 BUFFER[597]	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
#define idB6IE01LDU	 260	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
#define A8IE01LDU	 BUFFER[599]	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
#define idA8IE01LDU	 261	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
#define B5IE01LDU	 BUFFER[601]	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
#define idB5IE01LDU	 262	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
#define A5IE02LDU	 BUFFER[603]	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
#define idA5IE02LDU	 263	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
#define R1IE01LDU	 BUFFER[605]	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
#define idR1IE01LDU	 264	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
#define R2IE01LDU	 BUFFER[607]	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
#define idR2IE01LDU	 265	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
#define R6IS61LDU	 BUFFER[609]	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
#define idR6IS61LDU	 266	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
#define R6IS64LDU	 BUFFER[611]	//( - , MDuS) Исправность ВИП ССДИ-35 1канал
#define idR6IS64LDU	 267	//( - , MDuS) Исправность ВИП ССДИ-35 1канал
#define R6IS65LDU	 BUFFER[613]	//( - , MDuS) Исправность ВИП ССДИ-35 2канал
#define idR6IS65LDU	 268	//( - , MDuS) Исправность ВИП ССДИ-35 2канал
#define R6IS62LDU	 BUFFER[615]	//( - , MDuS) Исправность ВИП ССДИ-39 1канал
#define idR6IS62LDU	 269	//( - , MDuS) Исправность ВИП ССДИ-39 1канал
#define R6IS63LDU	 BUFFER[617]	//( - , MDuS) Исправность ВИП ССДИ-39 2канал
#define idR6IS63LDU	 270	//( - , MDuS) Исправность ВИП ССДИ-39 2канал
#define R6IS66LZZ	 BUFFER[619]	//( - , MDuS) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 271	//( - , MDuS) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	 BUFFER[621]	//( - , MDuS) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 272	//( - , MDuS) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	 BUFFER[623]	//( - , MDuS) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 273	//( - , MDuS) Исправность ВИП 4,0 (№7) ССДИ-2
#define syn_R0EE03LDU	 BUFFER[625]	//( - , DU) ВПИС ИС
#define idsyn_R0EE03LDU	 274	//( - , DU) ВПИС ИС
#define A3VC01RDU	 BUFFER[627]	//( - , DU) Координата ИС1, мм
#define idA3VC01RDU	 275	//( - , DU) Координата ИС1, мм
#define A2VC01RDU	 BUFFER[632]	//( - , DU) Координата РБ1, мм
#define idA2VC01RDU	 276	//( - , DU) Координата РБ1, мм
#define B2VC01RDU	 BUFFER[637]	//( - , DU) Координата РБ2, мм
#define idB2VC01RDU	 277	//( - , DU) Координата РБ2, мм
#define B8VC01RDU	 BUFFER[642]	//( - , DU) Координата АЗ2, мм
#define idB8VC01RDU	 278	//( - , DU) Координата АЗ2, мм
#define A4VP82LDU	 BUFFER[647]	//( - , MDuS) Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	 279	//( - , MDuS) Давление ПОДЪЁМ НИ1 в норме
#define B4VP82LDU	 BUFFER[649]	//( - , MDuS) Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	 280	//( - , MDuS) Давление ПОДЪЁМ НИ2 в норме
#define A2VP82LDU	 BUFFER[651]	//( - , MDuS) Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	 281	//( - , MDuS) Давление ПОДЪЁМ РБ1 в норме
#define B2VP82LDU	 BUFFER[653]	//( - , MDuS) Давление ПОДЪЁМ РБ2 в норме
#define idB2VP82LDU	 282	//( - , MDuS) Давление ПОДЪЁМ РБ2 в норме
#define A3VP81LDU	 BUFFER[655]	//( - , MDuS) Давление СПУСК ИС1 в норме
#define idA3VP81LDU	 283	//( - , MDuS) Давление СПУСК ИС1 в норме
#define A3EE03LDU	 BUFFER[657]	//( - , DU) ВПИС ИС1
#define idA3EE03LDU	 284	//( - , DU) ВПИС ИС1
#define B3EE03LDU	 BUFFER[659]	//( - , DU) ВПИС ИС2
#define idB3EE03LDU	 285	//( - , DU) ВПИС ИС2
#define B3AB15LDU	 BUFFER[661]	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
#define idB3AB15LDU	 286	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
#define R5IS21LDU	 BUFFER[663]	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	 287	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
#define R5VS22LDU	 BUFFER[665]	//( - , DU) Движение ворот отстойной зоны к закрыты
#define idR5VS22LDU	 288	//( - , DU) Движение ворот отстойной зоны к закрыты
#define R5VS12LDU	 BUFFER[667]	//( - , DU) Движение ворот отстойной зоны к открыты
#define idR5VS12LDU	 289	//( - , DU) Движение ворот отстойной зоны к открыты
#define R5VS01IDU	 BUFFER[669]	//( - , DU) Готовность к управлению ворот отстойной зоны
#define idR5VS01IDU	 290	//( - , DU) Готовность к управлению ворот отстойной зоны
#define R3VS22LDU	 BUFFER[672]	//( - , DU) Движение гомогенных дверей к закрыты
#define idR3VS22LDU	 291	//( - , DU) Движение гомогенных дверей к закрыты
#define R3VS12LDU	 BUFFER[674]	//( - , DU) Движение гомогенных дверей к открыты
#define idR3VS12LDU	 292	//( - , DU) Движение гомогенных дверей к открыты
#define R3VS01IDU	 BUFFER[676]	//( - , DU) Готовность к управлению гомогенных дверей
#define idR3VS01IDU	 293	//( - , DU) Готовность к управлению гомогенных дверей
#define A3AB13LDU	 BUFFER[679]	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
#define idA3AB13LDU	 294	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
#define syn_A3VP52LDU	 BUFFER[681]	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define idsyn_A3VP52LDU	 295	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define B3AB13LDU	 BUFFER[683]	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define idB3AB13LDU	 296	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define syn_B3VP52LDU	 BUFFER[685]	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define idsyn_B3VP52LDU	 297	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define R0DE02LDU	 BUFFER[687]	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
#define idR0DE02LDU	 298	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
#define R0DE03LDU	 BUFFER[690]	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
#define idR0DE03LDU	 299	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
#define R0DE04LDU	 BUFFER[693]	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
#define idR0DE04LDU	 300	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
#define R0DE08LDU	 BUFFER[696]	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
#define idR0DE08LDU	 301	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
#define R0DE05LDU	 BUFFER[699]	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
#define idR0DE05LDU	 302	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
#define R0DE09LDU	 BUFFER[702]	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
#define idR0DE09LDU	 303	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
#define R0DE0ALDU	 BUFFER[705]	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
#define idR0DE0ALDU	 304	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
#define R0DE07LDU	 BUFFER[708]	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
#define idR0DE07LDU	 305	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
#define R0DE0CLDU	 BUFFER[711]	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
#define idR0DE0CLDU	 306	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
#define R0AB20LDU	 BUFFER[714]	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
#define idR0AB20LDU	 307	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
#define R0CN92LDU	 BUFFER[716]	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
#define idR0CN92LDU	 308	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
#define R0VN11RDU	 BUFFER[721]	//( - , DU) Текущая мощность РУ
#define idR0VN11RDU	 309	//( - , DU) Текущая мощность РУ
#define R0VN12RDU	 BUFFER[726]	//( - , DU) Заданная мощность РУ
#define idR0VN12RDU	 310	//( - , DU) Заданная мощность РУ
#define R0AB19LDU	 BUFFER[731]	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
#define idR0AB19LDU	 311	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
#define R0CN93LDU	 BUFFER[733]	//( - , DU) время работы на мощности более 100Вт, сек
#define idR0CN93LDU	 312	//( - , DU) время работы на мощности более 100Вт, сек
#define R0CN94LDU	 BUFFER[738]	//( - , DU) Скорость изменения мощности
#define idR0CN94LDU	 313	//( - , DU) Скорость изменения мощности
#define R0CN95LDU	 BUFFER[743]	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
#define idR0CN95LDU	 314	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
#define R0AD03LZ1	 BUFFER[746]	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
#define idR0AD03LZ1	 315	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
#define R0AD03LZ2	 BUFFER[748]	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
#define idR0AD03LZ2	 316	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
#define R0AD04LZ1	 BUFFER[750]	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define idR0AD04LZ1	 317	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define R0AD04LZ2	 BUFFER[752]	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define idR0AD04LZ2	 318	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define R0AD05LZ1	 BUFFER[754]	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
#define idR0AD05LZ1	 319	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
#define R0AD05LZ2	 BUFFER[756]	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
#define idR0AD05LZ2	 320	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
#define B8IS12LDU	 BUFFER[758]	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
#define idB8IS12LDU	 321	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
#define B8IS21LDU	 BUFFER[760]	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
#define idB8IS21LDU	 322	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
#define A1VP41LZ1	 BUFFER[762]	//( - , DU) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ1	 323	//( - , DU) Давление СБРОС ББ1 ниже АС
#define A1VP41LZ2	 BUFFER[764]	//( - , DU) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ2	 324	//( - , DU) Давление СБРОС ББ1 ниже АС
#define R0VL22LDU	 BUFFER[766]	//( - , DU) Конец программы 200сек
#define idR0VL22LDU	 325	//( - , DU) Конец программы 200сек
#define R0VL23LDU	 BUFFER[768]	//( - , DU) Конец программы 20мин
#define idR0VL23LDU	 326	//( - , DU) Конец программы 20мин
#define B1VP41LZ1	 BUFFER[770]	//( - , DU) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ1	 327	//( - , DU) Давление СБРОС ББ2 ниже АС
#define B1VP41LZ2	 BUFFER[772]	//( - , DU) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ2	 328	//( - , DU) Давление СБРОС ББ2 ниже АС
#define A3AB19LDU	 BUFFER[774]	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
#define idA3AB19LDU	 329	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
#define B3AB19LDU	 BUFFER[776]	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
#define idB3AB19LDU	 330	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
#define B2IC01UDU	 BUFFER[778]	//( - , MDuS) Координата штока РБ2 (дел.энк)
#define idB2IC01UDU	 331	//( - , MDuS) Координата штока РБ2 (дел.энк)
#define A3IC01UDU	 BUFFER[783]	//( - , MDuS) Координата штока ИС1 (дел.энк)
#define idA3IC01UDU	 332	//( - , MDuS) Координата штока ИС1 (дел.энк)
#define B3IC01UDU	 BUFFER[788]	//( - , MDuS) Координата штока ИС2 (дел.энк)
#define idB3IC01UDU	 333	//( - , MDuS) Координата штока ИС2 (дел.энк)
#define B3VC01RDU	 BUFFER[793]	//( - , DU) Координата ИС2, мм
#define idB3VC01RDU	 334	//( - , DU) Координата ИС2, мм
#define A8IC01UDU	 BUFFER[798]	//( - , MDuS) Координата ДС2 (дел.энк)
#define idA8IC01UDU	 335	//( - , MDuS) Координата ДС2 (дел.энк)
#define A8VC01RDU	 BUFFER[803]	//( - , DU) Координата ДС2, мм
#define idA8VC01RDU	 336	//( - , DU) Координата ДС2, мм
#define B8IC01UDU	 BUFFER[808]	//( - , MDuS) Координата АЗ2 (дел.энк)
#define idB8IC01UDU	 337	//( - , MDuS) Координата АЗ2 (дел.энк)
#define A1IC01UDU	 BUFFER[813]	//( - , MDuS) Координата штока ББ1 (дел.энк)
#define idA1IC01UDU	 338	//( - , MDuS) Координата штока ББ1 (дел.энк)
#define A1VC01RDU	 BUFFER[818]	//( - , DU) Координата ББ1, мм
#define idA1VC01RDU	 339	//( - , DU) Координата ББ1, мм
#define A1IS11LDU	 BUFFER[823]	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
#define idA1IS11LDU	 340	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
#define B1MC01LC1	 BUFFER[825]	//( - , DU) Настроить энкодер ББ2
#define idB1MC01LC1	 341	//( - , DU) Настроить энкодер ББ2
#define B1MC01LC2	 BUFFER[827]	//( - , DU) Настроить энкодер ББ2
#define idB1MC01LC2	 342	//( - , DU) Настроить энкодер ББ2
#define A1MC01LC1	 BUFFER[829]	//( - , DU) Настроить энкодер ББ1
#define idA1MC01LC1	 343	//( - , DU) Настроить энкодер ББ1
#define A1MC01LC2	 BUFFER[831]	//( - , DU) Настроить энкодер ББ1
#define idA1MC01LC2	 344	//( - , DU) Настроить энкодер ББ1
#define B2MC01LC1	 BUFFER[833]	//( - , DU) Настроить энкодер РБ2
#define idB2MC01LC1	 345	//( - , DU) Настроить энкодер РБ2
#define B2MC01LC2	 BUFFER[835]	//( - , DU) Настроить энкодер РБ2
#define idB2MC01LC2	 346	//( - , DU) Настроить энкодер РБ2
#define A2MC01LC1	 BUFFER[837]	//( - , DU) Настроить энкодер РБ1
#define idA2MC01LC1	 347	//( - , DU) Настроить энкодер РБ1
#define A2MC01LC2	 BUFFER[839]	//( - , DU) Настроить энкодер РБ1
#define idA2MC01LC2	 348	//( - , DU) Настроить энкодер РБ1
#define B3MC01LC1	 BUFFER[841]	//( - , DU) Настроить энкодер ИС2
#define idB3MC01LC1	 349	//( - , DU) Настроить энкодер ИС2
#define B3MC01LC2	 BUFFER[843]	//( - , DU) Настроить энкодер ИС2
#define idB3MC01LC2	 350	//( - , DU) Настроить энкодер ИС2
#define A3MC01LC1	 BUFFER[845]	//( - , DU) Настроить энкодер ИС1
#define idA3MC01LC1	 351	//( - , DU) Настроить энкодер ИС1
#define A3MC01LC2	 BUFFER[847]	//( - , DU) Настроить энкодер ИС1
#define idA3MC01LC2	 352	//( - , DU) Настроить энкодер ИС1
#define B8MC01LC1	 BUFFER[849]	//( - , DU) Настроить энкодер АЗ2
#define idB8MC01LC1	 353	//( - , DU) Настроить энкодер АЗ2
#define B8MC01LC2	 BUFFER[851]	//( - , DU) Настроить энкодер АЗ2
#define idB8MC01LC2	 354	//( - , DU) Настроить энкодер АЗ2
#define R0DE0BLDU	 BUFFER[853]	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
#define idR0DE0BLDU	 355	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
#define R0DE0DLDU	 BUFFER[856]	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
#define idR0DE0DLDU	 356	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
#define R0DE0FLDU	 BUFFER[859]	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
#define idR0DE0FLDU	 357	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
#define R0DE31LDU	 BUFFER[862]	//(sbk:20 - S01SBK, DiagnDU) диагностика шкафа ДУ сеть 1
#define idR0DE31LDU	 358	//(sbk:20 - S01SBK, DiagnDU) диагностика шкафа ДУ сеть 1
#define TTLDU	 BUFFER[864]	//( - , DU) ttl
#define idTTLDU	 359	//( - , DU) ttl
#define R0DE32LDU	 BUFFER[867]	//(sbk:20 - S02SBK, DiagnDU) диагностика шкафа ДУ сеть 2
#define idR0DE32LDU	 360	//(sbk:20 - S02SBK, DiagnDU) диагностика шкафа ДУ сеть 2
#define R0DE33LDU	 BUFFER[869]	//(sbk:20 - S03SBK, DiagnDU) диагностика шкафа ДУ двери
#define idR0DE33LDU	 361	//(sbk:20 - S03SBK, DiagnDU) диагностика шкафа ДУ двери
#define R0DE34LDU	 BUFFER[871]	//(sbk:20 - S04SBK, DiagnDU) диагностика шкафа ДУ температура меньше 43
#define idR0DE34LDU	 362	//(sbk:20 - S04SBK, DiagnDU) диагностика шкафа ДУ температура меньше 43
#define R0DE35LDU	 BUFFER[873]	//(sbk:20 - S05SBK, DiagnDU) диагностика шкафа ДУ температура больше 53
#define idR0DE35LDU	 363	//(sbk:20 - S05SBK, DiagnDU) диагностика шкафа ДУ температура больше 53
#define R0DE36LDU	 BUFFER[875]	//(sbk:20 - S06SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 1
#define idR0DE36LDU	 364	//(sbk:20 - S06SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 1
#define R0DE37LDU	 BUFFER[877]	//(sbk:20 - S07SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 2
#define idR0DE37LDU	 365	//(sbk:20 - S07SBK, DiagnDU) диагностика шкафа ДУ МП15-3.1 место 2
#define R0DE38LDU	 BUFFER[879]	//(sbk:20 - S08SBK, DiagnDU) диагностика шкафа ДУ МП15-3 место 3
#define idR0DE38LDU	 366	//(sbk:20 - S08SBK, DiagnDU) диагностика шкафа ДУ МП15-3 место 3
#define R0DE39LDU	 BUFFER[881]	//(sbk:20 - S09SBK, DiagnDU) диагностика шкафа ДУ МП24-2 место 4
#define idR0DE39LDU	 367	//(sbk:20 - S09SBK, DiagnDU) диагностика шкафа ДУ МП24-2 место 4
#define R0DEB3LDU	 BUFFER[883]	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
#define idR0DEB3LDU	 368	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
#define R0DEB2LDU	 BUFFER[885]	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
#define idR0DEB2LDU	 369	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
#define R0DEB1LDU	 BUFFER[887]	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
#define idR0DEB1LDU	 370	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
#define R0DEB4LDU	 BUFFER[889]	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
#define idR0DEB4LDU	 371	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
#define R0DE3DLDU	 BUFFER[891]	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
#define idR0DE3DLDU	 372	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
#define R0DE3CLDU	 BUFFER[893]	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
#define idR0DE3CLDU	 373	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
#define TestDiagnDU	 BUFFER[895]	//( - , DU) Неисправность от
#define idTestDiagnDU	 374	//( - , DU) Неисправность от
#define B1IC01UDU	 BUFFER[897]	//( - , MDuS) Координата штока ББ2 (дел.энк)
#define idB1IC01UDU	 375	//( - , MDuS) Координата штока ББ2 (дел.энк)
#define B1VC01RDU	 BUFFER[902]	//( - , DU) Координата ББ2, мм
#define idB1VC01RDU	 376	//( - , DU) Координата ББ2, мм
#define B1IS11LDU	 BUFFER[907]	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
#define idB1IS11LDU	 377	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
#define A2IC01UDU	 BUFFER[909]	//( - , MDuS) Координата штока РБ1 (дел.энк)
#define idA2IC01UDU	 378	//( - , MDuS) Координата штока РБ1 (дел.энк)
#define B6AB06LDU	 BUFFER[914]	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
#define idB6AB06LDU	 379	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
#define B6AB07LDU	 BUFFER[916]	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
#define idB6AB07LDU	 380	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
#define B6AB08LDU	 BUFFER[918]	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
#define idB6AB08LDU	 381	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
#define B6AB09LDU	 BUFFER[920]	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
#define idB6AB09LDU	 382	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
#define A6AB05LDU	 BUFFER[922]	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
#define idA6AB05LDU	 383	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
#define B8VS12LDU	 BUFFER[924]	//( - , DU) Движение АЗ2 в сторону ВУ
#define idB8VS12LDU	 384	//( - , DU) Движение АЗ2 в сторону ВУ
#define B8CV01RDU	 BUFFER[926]	//( - , DU) Измеренная скорость перемещения АЗ2
#define idB8CV01RDU	 385	//( - , DU) Измеренная скорость перемещения АЗ2
#define B8AB06LDU	 BUFFER[931]	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
#define idB8AB06LDU	 386	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
#define B8AB07LDU	 BUFFER[933]	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
#define idB8AB07LDU	 387	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
#define B8AB05LDU	 BUFFER[935]	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
#define idB8AB05LDU	 388	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
#define B8VS22LDU	 BUFFER[937]	//( - , DU) Движение АЗ2 в сторону НУ
#define idB8VS22LDU	 389	//( - , DU) Движение АЗ2 в сторону НУ
#define B8AZ03LDU	 BUFFER[939]	//( - , DU) Несанкционированное перемещение АЗ2
#define idB8AZ03LDU	 390	//( - , DU) Несанкционированное перемещение АЗ2
#define R0MD11LP1	 BUFFER[941]	//( - , DU) Кнопка ПУСК
#define idR0MD11LP1	 391	//( - , DU) Кнопка ПУСК
#define B8AD10LDU	 BUFFER[943]	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
#define idB8AD10LDU	 392	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
#define B8AD20LDU	 BUFFER[945]	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
#define idB8AD20LDU	 393	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
#define B8IS11LDU	 BUFFER[947]	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
#define idB8IS11LDU	 394	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
#define B8AB01LDU	 BUFFER[949]	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
#define idB8AB01LDU	 395	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
#define B8AB04LDU	 BUFFER[951]	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
#define idB8AB04LDU	 396	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
#define B8AB08LDU	 BUFFER[953]	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
#define idB8AB08LDU	 397	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
#define B8AB09LDU	 BUFFER[955]	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
#define idB8AB09LDU	 398	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
#define B8AB10LDU	 BUFFER[957]	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
#define idB8AB10LDU	 399	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
#define B8AB11LDU	 BUFFER[959]	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
#define idB8AB11LDU	 400	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
#define B8AB12LDU	 BUFFER[961]	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
#define idB8AB12LDU	 401	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
#define B5AZ03LDU	 BUFFER[963]	//( - , DU) Несанкционированное перемещение НЛ2
#define idB5AZ03LDU	 402	//( - , DU) Несанкционированное перемещение НЛ2
#define B5AB01LDU	 BUFFER[965]	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
#define idB5AB01LDU	 403	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
#define B5AB02LDU	 BUFFER[967]	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
#define idB5AB02LDU	 404	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
#define A4IS21LDU	 BUFFER[969]	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
#define idA4IS21LDU	 405	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
#define B4IS21LDU	 BUFFER[971]	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
#define idB4IS21LDU	 406	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
#define B4AD10LDU	 BUFFER[973]	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
#define idB4AD10LDU	 407	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
#define A4AD10LDU	 BUFFER[975]	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
#define idA4AD10LDU	 408	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
#define A4AZ03LDU	 BUFFER[977]	//( - , DU) Несанкционированное перемещение НИ1
#define idA4AZ03LDU	 409	//( - , DU) Несанкционированное перемещение НИ1
#define A4AB01LDU	 BUFFER[979]	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
#define idA4AB01LDU	 410	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
#define A4AB02LDU	 BUFFER[981]	//( - , DU) Блокировка движения НИ1 - Нет перемещения
#define idA4AB02LDU	 411	//( - , DU) Блокировка движения НИ1 - Нет перемещения
#define B4AZ03LDU	 BUFFER[983]	//( - , DU) Несанкционированное перемещение НИ2
#define idB4AZ03LDU	 412	//( - , DU) Несанкционированное перемещение НИ2
#define B4AB01LDU	 BUFFER[985]	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
#define idB4AB01LDU	 413	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
#define B4AB02LDU	 BUFFER[987]	//( - , DU) Блокировка движения НИ2 - Нет перемещения
#define idB4AB02LDU	 414	//( - , DU) Блокировка движения НИ2 - Нет перемещения
#define A5AB04LDU	 BUFFER[989]	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
#define idA5AB04LDU	 415	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
#define B5AB04LDU	 BUFFER[991]	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
#define idB5AB04LDU	 416	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
#define A1IS12LDU	 BUFFER[993]	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
#define idA1IS12LDU	 417	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
#define A2IS12LDU	 BUFFER[995]	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
#define idA2IS12LDU	 418	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
#define B1IS12LDU	 BUFFER[997]	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
#define idB1IS12LDU	 419	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
#define B2IS12LDU	 BUFFER[999]	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
#define idB2IS12LDU	 420	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
#define R4IS11LDU	 BUFFER[1001]	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
#define idR4IS11LDU	 421	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
#define A6AB06LDU	 BUFFER[1003]	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
#define idA6AB06LDU	 422	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
#define A6AB07LDU	 BUFFER[1005]	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
#define idA6AB07LDU	 423	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
#define A6AB08LDU	 BUFFER[1007]	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
#define idA6AB08LDU	 424	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
#define A6AB09LDU	 BUFFER[1009]	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
#define idA6AB09LDU	 425	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
#define A8AB01LDU	 BUFFER[1011]	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
#define idA8AB01LDU	 426	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
#define A2VS11LDU	 BUFFER[1013]	//( - , DU) Движение РБ1 в сторону ВУ
#define idA2VS11LDU	 427	//( - , DU) Движение РБ1 в сторону ВУ
#define A2CV01RDU	 BUFFER[1015]	//( - , DU) Измеренная скорость перемещения РБ1
#define idA2CV01RDU	 428	//( - , DU) Измеренная скорость перемещения РБ1
#define A2AB04LDU	 BUFFER[1020]	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
#define idA2AB04LDU	 429	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
#define A2AB02LDU	 BUFFER[1022]	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
#define idA2AB02LDU	 430	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
#define A2AB01LDU	 BUFFER[1024]	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
#define idA2AB01LDU	 431	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
#define A2VS21LDU	 BUFFER[1026]	//( - , DU) Движение РБ1 в сторону НУ
#define idA2VS21LDU	 432	//( - , DU) Движение РБ1 в сторону НУ
#define A2AZ03LDU	 BUFFER[1028]	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
#define idA2AZ03LDU	 433	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
#define A2AD11LDU	 BUFFER[1030]	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	 434	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
#define A2AD21LDU	 BUFFER[1032]	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	 435	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
#define A2AD02LDU	 BUFFER[1034]	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
#define idA2AD02LDU	 436	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
#define A2AD03LDU	 BUFFER[1036]	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
#define idA2AD03LDU	 437	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
#define A2AD04LDU	 BUFFER[1038]	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
#define idA2AD04LDU	 438	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
#define A2AD05LDU	 BUFFER[1040]	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
#define idA2AD05LDU	 439	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
#define A2AB07LDU	 BUFFER[1042]	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
#define idA2AB07LDU	 440	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
#define A2AB08LDU	 BUFFER[1044]	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
#define idA2AB08LDU	 441	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
#define A2AB05LDU	 BUFFER[1046]	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
#define idA2AB05LDU	 442	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
#define A2AB06LDU	 BUFFER[1048]	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
#define idA2AB06LDU	 443	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
#define A2AB09LDU	 BUFFER[1050]	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
#define idA2AB09LDU	 444	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
#define A2AB10LDU	 BUFFER[1052]	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
#define idA2AB10LDU	 445	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
#define A2AB11LDU	 BUFFER[1054]	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
#define idA2AB11LDU	 446	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
#define A2AB12LDU	 BUFFER[1056]	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA2AB12LDU	 447	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A2AB13LDU	 BUFFER[1058]	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
#define idA2AB13LDU	 448	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
#define B8AB13LDU	 BUFFER[1060]	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
#define idB8AB13LDU	 449	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
#define B8AB14LDU	 BUFFER[1062]	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
#define idB8AB14LDU	 450	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
#define B8AB02LDU	 BUFFER[1064]	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
#define idB8AB02LDU	 451	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
#define A8VS12LDU	 BUFFER[1066]	//( - , DU) Движение ДС2 в сторону ВУ
#define idA8VS12LDU	 452	//( - , DU) Движение ДС2 в сторону ВУ
#define A8CV01RDU	 BUFFER[1068]	//( - , DU) Измеренная скорость перемещения ДС2
#define idA8CV01RDU	 453	//( - , DU) Измеренная скорость перемещения ДС2
#define A8AB06LDU	 BUFFER[1073]	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
#define idA8AB06LDU	 454	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
#define A8AB07LDU	 BUFFER[1075]	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
#define idA8AB07LDU	 455	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
#define A8AB05LDU	 BUFFER[1077]	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
#define idA8AB05LDU	 456	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
#define A8VS22LDU	 BUFFER[1079]	//( - , DU) Движение ДС2 в сторону НУ
#define idA8VS22LDU	 457	//( - , DU) Движение ДС2 в сторону НУ
#define A8AZ03LDU	 BUFFER[1081]	//( - , DU) Несанкционированное перемещение ДС2
#define idA8AZ03LDU	 458	//( - , DU) Несанкционированное перемещение ДС2
#define A8AD10LDU	 BUFFER[1083]	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
#define idA8AD10LDU	 459	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
#define A8AD20LDU	 BUFFER[1085]	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
#define idA8AD20LDU	 460	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
#define B8IS22LDU	 BUFFER[1087]	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
#define idB8IS22LDU	 461	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
#define A8IS12LDU	 BUFFER[1089]	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
#define idA8IS12LDU	 462	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
#define A8AB04LDU	 BUFFER[1091]	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
#define idA8AB04LDU	 463	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
#define A8IS22LDU	 BUFFER[1093]	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
#define idA8IS22LDU	 464	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
#define A8AB08LDU	 BUFFER[1095]	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define idA8AB08LDU	 465	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define A8AB09LDU	 BUFFER[1097]	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
#define idA8AB09LDU	 466	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
#define A8AB10LDU	 BUFFER[1099]	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
#define idA8AB10LDU	 467	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
#define A8AB11LDU	 BUFFER[1101]	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
#define idA8AB11LDU	 468	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
#define A8AB12LDU	 BUFFER[1103]	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
#define idA8AB12LDU	 469	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
#define A8AB13LDU	 BUFFER[1105]	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
#define idA8AB13LDU	 470	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
#define A8AB14LDU	 BUFFER[1107]	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
#define idA8AB14LDU	 471	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
#define A8AB02LDU	 BUFFER[1109]	//( - , DU) Блокировка движения ДС2- АНИ не установлен
#define idA8AB02LDU	 472	//( - , DU) Блокировка движения ДС2- АНИ не установлен
#define A6VS22LDU	 BUFFER[1111]	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
#define idA6VS22LDU	 473	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
#define A6VS12LDU	 BUFFER[1113]	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
#define idA6VS12LDU	 474	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
#define B6VS22LDU	 BUFFER[1115]	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
#define idB6VS22LDU	 475	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
#define B6VS12LDU	 BUFFER[1117]	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
#define idB6VS12LDU	 476	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
#define A6AD10LDU	 BUFFER[1119]	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
#define idA6AD10LDU	 477	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
#define A6AD20LDU	 BUFFER[1121]	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
#define idA6AD20LDU	 478	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
#define B6AD10LDU	 BUFFER[1123]	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
#define idB6AD10LDU	 479	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
#define B6AD20LDU	 BUFFER[1125]	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
#define idB6AD20LDU	 480	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
#define A6AZ03LDU	 BUFFER[1127]	//( - , DU) Несанкционированное перемещение БЗ1
#define idA6AZ03LDU	 481	//( - , DU) Несанкционированное перемещение БЗ1
#define A6AB01LDU	 BUFFER[1129]	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
#define idA6AB01LDU	 482	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
#define A6AB02LDU	 BUFFER[1131]	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
#define idA6AB02LDU	 483	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
#define B6AZ03LDU	 BUFFER[1133]	//( - , DU) Несанкционированное перемещение БЗ2
#define idB6AZ03LDU	 484	//( - , DU) Несанкционированное перемещение БЗ2
#define B6AB01LDU	 BUFFER[1135]	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
#define idB6AB01LDU	 485	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
#define B6AB02LDU	 BUFFER[1137]	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
#define idB6AB02LDU	 486	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
#define A6AB04LDU	 BUFFER[1139]	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
#define idA6AB04LDU	 487	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
#define B6AB04LDU	 BUFFER[1141]	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
#define idB6AB04LDU	 488	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
#define R4AB01LDU	 BUFFER[1143]	//( - , DU) Блокировка движения тележки - АНИ не установлен
#define idR4AB01LDU	 489	//( - , DU) Блокировка движения тележки - АНИ не установлен
#define R8IS11LDU	 BUFFER[1145]	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
#define idR8IS11LDU	 490	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
#define R6IS21LDU	 BUFFER[1147]	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
#define idR6IS21LDU	 491	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
#define A0VN71LZ2	 BUFFER[1149]	//( - , MDuBz2) АЗ по АС мощности для АЗ1
#define idA0VN71LZ2	 492	//( - , MDuBz2) АЗ по АС мощности для АЗ1
#define A0VN71LZ1	 BUFFER[1151]	//( - , MDuBz1) АЗ по АС мощности для АЗ1
#define idA0VN71LZ1	 493	//( - , MDuBz1) АЗ по АС мощности для АЗ1
#define R0NE01LDU	 BUFFER[1153]	//( - , DU) Потеря связи с БАЗ1
#define idR0NE01LDU	 494	//( - , DU) Потеря связи с БАЗ1
#define R0NE02LDU	 BUFFER[1155]	//( - , DU) Потеря связи с БАЗ2
#define idR0NE02LDU	 495	//( - , DU) Потеря связи с БАЗ2
#define R0MW15IP1	 BUFFER[1157]	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
#define idR0MW15IP1	 496	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
#define R0MW14IP1	 BUFFER[1160]	//( - , DU) Переключатель ПРОГРАММЫ
#define idR0MW14IP1	 497	//( - , DU) Переключатель ПРОГРАММЫ
#define R0MW12IP1	 BUFFER[1163]	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
#define idR0MW12IP1	 498	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
#define R0MW13IP1	 BUFFER[1166]	//( - , DU) Переключатель ВЫБОР ЗОН
#define idR0MW13IP1	 499	//( - , DU) Переключатель ВЫБОР ЗОН
#define R0MW16IP1	 BUFFER[1169]	//( - , DU) Переключатель ВИД ПРОВЕРКИ
#define idR0MW16IP1	 500	//( - , DU) Переключатель ВИД ПРОВЕРКИ
#define R0MW11IP1	 BUFFER[1172]	//( - , DU) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	 501	//( - , DU) Переключатель ВЫСТРЕЛ
#define R0MW11IP2	 BUFFER[1175]	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
#define idR0MW11IP2	 502	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
#define R0MW13LP2	 BUFFER[1178]	//( - , DU) Переключатель СЕТЬ
#define idR0MW13LP2	 503	//( - , DU) Переключатель СЕТЬ
#define R0MD32LP1	 BUFFER[1180]	//( - , DU) Кнопка СПУСК
#define idR0MD32LP1	 504	//( - , DU) Кнопка СПУСК
#define R0MD31LP1	 BUFFER[1182]	//( - , DU) Кнопка СТОП
#define idR0MD31LP1	 505	//( - , DU) Кнопка СТОП
#define A1IS21LDU	 BUFFER[1184]	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
#define idA1IS21LDU	 506	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
#define A2IS21LDU	 BUFFER[1186]	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
#define idA2IS21LDU	 507	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
#define A3IS21LDU	 BUFFER[1188]	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
#define idA3IS21LDU	 508	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
#define B1IS21LDU	 BUFFER[1190]	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
#define idB1IS21LDU	 509	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
#define B2IS21LDU	 BUFFER[1192]	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
#define idB2IS21LDU	 510	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
#define B3IS21LDU	 BUFFER[1194]	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
#define idB3IS21LDU	 511	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
#define R0ES01LDU	 BUFFER[1196]	//( - , DU) ОРР не в исходном состоянии
#define idR0ES01LDU	 512	//( - , DU) ОРР не в исходном состоянии
#define R4MD11LP2	 BUFFER[1198]	//( - , DU) Кнопка ВПЕРЁД  (тележки)
#define idR4MD11LP2	 513	//( - , DU) Кнопка ВПЕРЁД  (тележки)
#define R4MD31LP2	 BUFFER[1200]	//( - , DU) Кнопка СТОП  (тележки)
#define idR4MD31LP2	 514	//( - , DU) Кнопка СТОП  (тележки)
#define R4MD21LP2	 BUFFER[1202]	//( - , DU) Кнопка НАЗАД  (тележки)
#define idR4MD21LP2	 515	//( - , DU) Кнопка НАЗАД  (тележки)
#define A6IS11LDU	 BUFFER[1204]	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
#define idA6IS11LDU	 516	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
#define A6IS21LDU	 BUFFER[1206]	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
#define idA6IS21LDU	 517	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
#define B6IS11LDU	 BUFFER[1208]	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
#define idB6IS11LDU	 518	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
#define B6IS21LDU	 BUFFER[1210]	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
#define idB6IS21LDU	 519	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
#define R4AB13LDU	 BUFFER[1212]	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
#define idR4AB13LDU	 520	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
#define R4AB14LDU	 BUFFER[1214]	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
#define idR4AB14LDU	 521	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
#define R4AB15LDU	 BUFFER[1216]	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
#define idR4AB15LDU	 522	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
#define R5IS11LDU	 BUFFER[1218]	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	 523	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
#define R4AB16LDU	 BUFFER[1220]	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
#define idR4AB16LDU	 524	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
#define R4AB17LDU	 BUFFER[1222]	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define idR4AB17LDU	 525	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define R4AB18LDU	 BUFFER[1224]	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define idR4AB18LDU	 526	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define R4AD10LDU	 BUFFER[1226]	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
#define idR4AD10LDU	 527	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
#define R4AD20LDU	 BUFFER[1228]	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
#define idR4AD20LDU	 528	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
#define A5VS22LDU	 BUFFER[1230]	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
#define idA5VS22LDU	 529	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
#define A5VS12LDU	 BUFFER[1232]	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
#define idA5VS12LDU	 530	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
#define B5VS22LDU	 BUFFER[1234]	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
#define idB5VS22LDU	 531	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
#define B5VS12LDU	 BUFFER[1236]	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
#define idB5VS12LDU	 532	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
#define B5AD10LDU	 BUFFER[1238]	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
#define idB5AD10LDU	 533	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
#define B5AD20LDU	 BUFFER[1240]	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
#define idB5AD20LDU	 534	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
#define A5AD10LDU	 BUFFER[1242]	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
#define idA5AD10LDU	 535	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
#define A5AD20LDU	 BUFFER[1244]	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
#define idA5AD20LDU	 536	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
#define A5IS11LDU	 BUFFER[1246]	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
#define idA5IS11LDU	 537	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
#define A5IS21LDU	 BUFFER[1248]	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
#define idA5IS21LDU	 538	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
#define B5IS11LDU	 BUFFER[1250]	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
#define idB5IS11LDU	 539	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
#define B5IS21LDU	 BUFFER[1252]	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
#define idB5IS21LDU	 540	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
#define A5AZ03LDU	 BUFFER[1254]	//( - , DU) Несанкционированное перемещение НЛ1
#define idA5AZ03LDU	 541	//( - , DU) Несанкционированное перемещение НЛ1
#define A5AB01LDU	 BUFFER[1256]	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
#define idA5AB01LDU	 542	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
#define A5AB02LDU	 BUFFER[1258]	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
#define idA5AB02LDU	 543	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
#define R4AB02LDU	 BUFFER[1260]	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
#define idR4AB02LDU	 544	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
#define R0NE08LDU	 BUFFER[1262]	//( - , DU) Потеря связи с ОПУ
#define idR0NE08LDU	 545	//( - , DU) Потеря связи с ОПУ
#define R4IS21LDU	 BUFFER[1264]	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
#define idR4IS21LDU	 546	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
#define R4IS22LDU	 BUFFER[1266]	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
#define idR4IS22LDU	 547	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
#define R4IS12LDU	 BUFFER[1268]	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
#define idR4IS12LDU	 548	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
#define R4VS22LDU	 BUFFER[1270]	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
#define idR4VS22LDU	 549	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
#define R4VS12LDU	 BUFFER[1272]	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
#define idR4VS12LDU	 550	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
#define R4AZ03LDU	 BUFFER[1274]	//( - , DU) Несанкционированное перемещение тележки
#define idR4AZ03LDU	 551	//( - , DU) Несанкционированное перемещение тележки
#define R4AB03LDU	 BUFFER[1276]	//( - , DU) Блокировка движения тележки - Самоход любого механизма
#define idR4AB03LDU	 552	//( - , DU) Блокировка движения тележки - Самоход любого механизма
#define R1IS21LDU	 BUFFER[1278]	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
#define idR1IS21LDU	 553	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
#define R2IS21LDU	 BUFFER[1280]	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
#define idR2IS21LDU	 554	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
#define R4AB04LDU	 BUFFER[1282]	//( - , DU) Блокировка движения тележки - Превышение времени движения
#define idR4AB04LDU	 555	//( - , DU) Блокировка движения тележки - Превышение времени движения
#define R4AB05LDU	 BUFFER[1284]	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
#define idR4AB05LDU	 556	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
#define R4AB06LDU	 BUFFER[1286]	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
#define idR4AB06LDU	 557	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
#define R4AB07LDU	 BUFFER[1288]	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
#define idR4AB07LDU	 558	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
#define R4AB08LDU	 BUFFER[1290]	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define idR4AB08LDU	 559	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define R4AB09LDU	 BUFFER[1292]	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
#define idR4AB09LDU	 560	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
#define B0VN71LZ1	 BUFFER[1294]	//( - , MDuBz1) АЗ по АС мощности для АЗ2
#define idB0VN71LZ1	 561	//( - , MDuBz1) АЗ по АС мощности для АЗ2
#define B0VN71LZ2	 BUFFER[1296]	//( - , MDuBz2) АЗ по АС мощности для АЗ2
#define idB0VN71LZ2	 562	//( - , MDuBz2) АЗ по АС мощности для АЗ2
#define R4AB10LDU	 BUFFER[1298]	//( - , DU) Блокировка тележки - не открыта биологическая защита
#define idR4AB10LDU	 563	//( - , DU) Блокировка тележки - не открыта биологическая защита
#define R4AB11LDU	 BUFFER[1300]	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
#define idR4AB11LDU	 564	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
#define R4AB12LDU	 BUFFER[1302]	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
#define idR4AB12LDU	 565	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
#define A4IS11LDU	 BUFFER[1304]	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
#define idA4IS11LDU	 566	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
#define B4IS11LDU	 BUFFER[1306]	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
#define idB4IS11LDU	 567	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
#define A3AB05LDU	 BUFFER[1308]	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
#define idA3AB05LDU	 568	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
#define A3AB06LDU	 BUFFER[1310]	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
#define idA3AB06LDU	 569	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
#define A3AB09LDU	 BUFFER[1312]	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
#define idA3AB09LDU	 570	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
#define A3AB10LDU	 BUFFER[1314]	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
#define idA3AB10LDU	 571	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
#define A3AB11LDU	 BUFFER[1316]	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
#define idA3AB11LDU	 572	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
#define A3AB12LDU	 BUFFER[1318]	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA3AB12LDU	 573	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A3AB14LDU	 BUFFER[1320]	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
#define idA3AB14LDU	 574	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
#define A3AB16LDU	 BUFFER[1322]	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
#define idA3AB16LDU	 575	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
#define A3AB17LDU	 BUFFER[1324]	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
#define idA3AB17LDU	 576	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
#define A3AB18LDU	 BUFFER[1326]	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
#define idA3AB18LDU	 577	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
#define A3AB20LDU	 BUFFER[1328]	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
#define idA3AB20LDU	 578	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
#define B3VS12LDU	 BUFFER[1330]	//( - , DU) Движение ИС2 в сторону ВУ
#define idB3VS12LDU	 579	//( - , DU) Движение ИС2 в сторону ВУ
#define B3CV01RDU	 BUFFER[1332]	//( - , DU) Измеренная скорость перемещения ИС2
#define idB3CV01RDU	 580	//( - , DU) Измеренная скорость перемещения ИС2
#define B3AB04LDU	 BUFFER[1337]	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
#define idB3AB04LDU	 581	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
#define B3AB02LDU	 BUFFER[1339]	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
#define idB3AB02LDU	 582	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
#define B3AB01LDU	 BUFFER[1341]	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
#define idB3AB01LDU	 583	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
#define B3VS22LDU	 BUFFER[1343]	//( - , DU) Движение ИС2 в сторону НУ
#define idB3VS22LDU	 584	//( - , DU) Движение ИС2 в сторону НУ
#define B3AZ03LDU	 BUFFER[1345]	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
#define idB3AZ03LDU	 585	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
#define B3AD11LDU	 BUFFER[1347]	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	 586	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
#define B3AD21LDU	 BUFFER[1349]	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	 587	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
#define B3AD02LDU	 BUFFER[1351]	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
#define idB3AD02LDU	 588	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
#define B3AD03LDU	 BUFFER[1353]	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
#define idB3AD03LDU	 589	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
#define B3AD04LDU	 BUFFER[1355]	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
#define idB3AD04LDU	 590	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
#define B1AB11LDU	 BUFFER[1357]	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
#define idB1AB11LDU	 591	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
#define B1AB12LDU	 BUFFER[1359]	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idB1AB12LDU	 592	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define B1AB13LDU	 BUFFER[1361]	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
#define idB1AB13LDU	 593	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
#define B1AB14LDU	 BUFFER[1363]	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
#define idB1AB14LDU	 594	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
#define B1AB16LDU	 BUFFER[1365]	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
#define idB1AB16LDU	 595	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
#define B1AB17LDU	 BUFFER[1367]	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
#define idB1AB17LDU	 596	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
#define B1AB18LDU	 BUFFER[1369]	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
#define idB1AB18LDU	 597	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
#define A3VS12LDU	 BUFFER[1371]	//( - , DU) Движение ИС1 в сторону ВУ
#define idA3VS12LDU	 598	//( - , DU) Движение ИС1 в сторону ВУ
#define A3CV01RDU	 BUFFER[1373]	//( - , DU) Измеренная скорость перемещения ИС1
#define idA3CV01RDU	 599	//( - , DU) Измеренная скорость перемещения ИС1
#define A3AB04LDU	 BUFFER[1378]	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
#define idA3AB04LDU	 600	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
#define A3AB02LDU	 BUFFER[1380]	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
#define idA3AB02LDU	 601	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
#define A3AB01LDU	 BUFFER[1382]	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
#define idA3AB01LDU	 602	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
#define A3VS22LDU	 BUFFER[1384]	//( - , DU) Движение ИС1 в сторону НУ
#define idA3VS22LDU	 603	//( - , DU) Движение ИС1 в сторону НУ
#define A3AZ03LDU	 BUFFER[1386]	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
#define idA3AZ03LDU	 604	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
#define A3AD11LDU	 BUFFER[1388]	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	 605	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
#define A3AD21LDU	 BUFFER[1390]	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	 606	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
#define A3AD02LDU	 BUFFER[1392]	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
#define idA3AD02LDU	 607	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
#define A3AD03LDU	 BUFFER[1394]	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
#define idA3AD03LDU	 608	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
#define A3AD04LDU	 BUFFER[1396]	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
#define idA3AD04LDU	 609	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
#define A3AD05LDU	 BUFFER[1398]	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
#define idA3AD05LDU	 610	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
#define A3AD01LDU	 BUFFER[1400]	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
#define idA3AD01LDU	 611	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
#define A3CV02RDU	 BUFFER[1402]	//( - , DU) Заданная скорость перемещения ИС1
#define idA3CV02RDU	 612	//( - , DU) Заданная скорость перемещения ИС1
#define A3AB07LDU	 BUFFER[1407]	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
#define idA3AB07LDU	 613	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
#define A3AB08LDU	 BUFFER[1409]	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
#define idA3AB08LDU	 614	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
#define A1AD32LDU	 BUFFER[1411]	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
#define idA1AD32LDU	 615	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
#define B1AD32LDU	 BUFFER[1413]	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
#define idB1AD32LDU	 616	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
#define R0MD11LP2	 BUFFER[1415]	//( - , DU) Кнопка Пуск проверки схем сброса
#define idR0MD11LP2	 617	//( - , DU) Кнопка Пуск проверки схем сброса
#define R0VX01LDU	 BUFFER[1417]	//( - , DU) ДО ИМПУЛЬСА
#define idR0VX01LDU	 618	//( - , DU) ДО ИМПУЛЬСА
#define R0VL01IDU	 BUFFER[1419]	//( - , DU) До импульса минут
#define idR0VL01IDU	 619	//( - , DU) До импульса минут
#define R0VL11IDU	 BUFFER[1422]	//( - , DU) До импульса секунд
#define idR0VL11IDU	 620	//( - , DU) До импульса секунд
#define R0VL06RDU	 BUFFER[1425]	//( - , DU) Индикация (Время задержки от ВУ РБ)
#define idR0VL06RDU	 621	//( - , DU) Индикация (Время задержки от ВУ РБ)
#define B3AD33LDU	 BUFFER[1430]	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 закрыть (обесточить)
#define idB3AD33LDU	 622	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 закрыть (обесточить)
#define B3IS11LDU	 BUFFER[1432]	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
#define idB3IS11LDU	 623	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
#define R0VL02RDU	 BUFFER[1434]	//( - , DU) Индикация (Время задержки ИНИ)
#define idR0VL02RDU	 624	//( - , DU) Индикация (Время задержки ИНИ)
#define R8AD21LDU	 BUFFER[1439]	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
#define idR8AD21LDU	 625	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
#define R0AD14LDU	 BUFFER[1441]	//( - , DU) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 626	//( - , DU) Имитация срабатывания верхней АС II УР
#define R0VL04RDU	 BUFFER[1443]	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
#define idR0VL04RDU	 627	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
#define R0AB04LDU	 BUFFER[1448]	//( - , DU) Нарушение времени срабатывания верхней АС II УР
#define idR0AB04LDU	 628	//( - , DU) Нарушение времени срабатывания верхней АС II УР
#define R0AB06LDU	 BUFFER[1450]	//( - , DU) Нарушение времени задержки от ВУ РБ
#define idR0AB06LDU	 629	//( - , DU) Нарушение времени задержки от ВУ РБ
#define R0AB02LDU	 BUFFER[1452]	//( - , DU) Нарушение времени задержки ИНИ
#define idR0AB02LDU	 630	//( - , DU) Нарушение времени задержки ИНИ
#define R0VL03RDU	 BUFFER[1454]	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define idR0VL03RDU	 631	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define R0VL05RDU	 BUFFER[1459]	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
#define idR0VL05RDU	 632	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
#define R0VL21IDU	 BUFFER[1464]	//( - , DU) Декатрон
#define idR0VL21IDU	 633	//( - , DU) Декатрон
#define R0VX03LDU	 BUFFER[1467]	//( - , DU) Готовность 2 мин
#define idR0VX03LDU	 634	//( - , DU) Готовность 2 мин
#define R0VS21IDU	 BUFFER[1469]	//( - , DU) Индикация ВИД ПРОВЕРКИ
#define idR0VS21IDU	 635	//( - , DU) Индикация ВИД ПРОВЕРКИ
#define A1VS01IDU	 BUFFER[1472]	//( - , DU) Готовность к управлению ББ1
#define idA1VS01IDU	 636	//( - , DU) Готовность к управлению ББ1
#define B1VS01IDU	 BUFFER[1475]	//( - , DU) Готовность к управлению ББ2
#define idB1VS01IDU	 637	//( - , DU) Готовность к управлению ББ2
#define A3VS01IDU	 BUFFER[1478]	//( - , DU) Готовность к управлению ИС1
#define idA3VS01IDU	 638	//( - , DU) Готовность к управлению ИС1
#define B3AD05LDU	 BUFFER[1481]	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
#define idB3AD05LDU	 639	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
#define B3AD01LDU	 BUFFER[1483]	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
#define idB3AD01LDU	 640	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
#define B3CV02RDU	 BUFFER[1485]	//( - , DU) Заданная скорость перемещения ИС2
#define idB3CV02RDU	 641	//( - , DU) Заданная скорость перемещения ИС2
#define B3AB07LDU	 BUFFER[1490]	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
#define idB3AB07LDU	 642	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
#define B3AB08LDU	 BUFFER[1492]	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
#define idB3AB08LDU	 643	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
#define B3AB05LDU	 BUFFER[1494]	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
#define idB3AB05LDU	 644	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
#define B3AB06LDU	 BUFFER[1496]	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
#define idB3AB06LDU	 645	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
#define B3AB09LDU	 BUFFER[1498]	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
#define idB3AB09LDU	 646	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
#define B3AB10LDU	 BUFFER[1500]	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
#define idB3AB10LDU	 647	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
#define B3AB11LDU	 BUFFER[1502]	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
#define idB3AB11LDU	 648	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
#define B3AB12LDU	 BUFFER[1504]	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define idB3AB12LDU	 649	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define B3AB14LDU	 BUFFER[1506]	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
#define idB3AB14LDU	 650	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
#define B3AB16LDU	 BUFFER[1508]	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
#define idB3AB16LDU	 651	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
#define B3AB17LDU	 BUFFER[1510]	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
#define idB3AB17LDU	 652	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
#define B3AB18LDU	 BUFFER[1512]	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
#define idB3AB18LDU	 653	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
#define B3AB20LDU	 BUFFER[1514]	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
#define idB3AB20LDU	 654	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
#define C1MD31LP1	 BUFFER[1516]	//( - , DU) Кнопка СБРОС ББ
#define idC1MD31LP1	 655	//( - , DU) Кнопка СБРОС ББ
#define C1MD31LP2	 BUFFER[1518]	//( - , DU) Кнопка СБРОС ББ
#define idC1MD31LP2	 656	//( - , DU) Кнопка СБРОС ББ
#define A2AD31LDU	 BUFFER[1520]	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
#define idA2AD31LDU	 657	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
#define B2AD31LDU	 BUFFER[1522]	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
#define idB2AD31LDU	 658	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
#define A1AD31LDU	 BUFFER[1524]	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
#define idA1AD31LDU	 659	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
#define B1AD31LDU	 BUFFER[1526]	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
#define idB1AD31LDU	 660	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
#define A2AD32LDU	 BUFFER[1528]	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
#define idA2AD32LDU	 661	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
#define B2AD32LDU	 BUFFER[1530]	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
#define idB2AD32LDU	 662	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
#define B2AB11LDU	 BUFFER[1532]	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
#define idB2AB11LDU	 663	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
#define B2AB12LDU	 BUFFER[1534]	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define idB2AB12LDU	 664	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define B2AB13LDU	 BUFFER[1536]	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
#define idB2AB13LDU	 665	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
#define B2AB14LDU	 BUFFER[1538]	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
#define idB2AB14LDU	 666	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
#define B2AB16LDU	 BUFFER[1540]	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
#define idB2AB16LDU	 667	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
#define B2AB17LDU	 BUFFER[1542]	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
#define idB2AB17LDU	 668	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
#define R1AZ03LDU	 BUFFER[1544]	//( - , DU) Несанкционированное перемещение МДЗ1
#define idR1AZ03LDU	 669	//( - , DU) Несанкционированное перемещение МДЗ1
#define R1AB01LDU	 BUFFER[1546]	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
#define idR1AB01LDU	 670	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
#define R1AB02LDU	 BUFFER[1548]	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
#define idR1AB02LDU	 671	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
#define R2AZ03LDU	 BUFFER[1550]	//( - , DU) Несанкционированное перемещение МДЗ2
#define idR2AZ03LDU	 672	//( - , DU) Несанкционированное перемещение МДЗ2
#define R2AB01LDU	 BUFFER[1552]	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
#define idR2AB01LDU	 673	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
#define R2AB02LDU	 BUFFER[1554]	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
#define idR2AB02LDU	 674	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
#define R1AB04LDU	 BUFFER[1556]	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
#define idR1AB04LDU	 675	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
#define R2AB04LDU	 BUFFER[1558]	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
#define idR2AB04LDU	 676	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
#define R1AD10LDU	 BUFFER[1560]	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
#define idR1AD10LDU	 677	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
#define R1AD20LDU	 BUFFER[1562]	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
#define idR1AD20LDU	 678	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
#define R1IS11LDU	 BUFFER[1564]	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
#define idR1IS11LDU	 679	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
#define R1VS22LDU	 BUFFER[1566]	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	 680	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
#define R2VS22LDU	 BUFFER[1568]	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	 681	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
#define R2VS12LDU	 BUFFER[1570]	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	 682	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
#define R1VS12LDU	 BUFFER[1572]	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	 683	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
#define R2IS11LDU	 BUFFER[1574]	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
#define idR2IS11LDU	 684	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
#define A1VS12LDU	 BUFFER[1576]	//( - , DU) Движение ББ1 в сторону ВУ
#define idA1VS12LDU	 685	//( - , DU) Движение ББ1 в сторону ВУ
#define A2AB14LDU	 BUFFER[1578]	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
#define idA2AB14LDU	 686	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
#define A2AB16LDU	 BUFFER[1580]	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
#define idA2AB16LDU	 687	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
#define A2AB17LDU	 BUFFER[1582]	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
#define idA2AB17LDU	 688	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
#define A2AD01LDU	 BUFFER[1584]	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
#define idA2AD01LDU	 689	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
#define A2CV02RDU	 BUFFER[1586]	//( - , DU) Заданная скорость перемещения РБ1
#define idA2CV02RDU	 690	//( - , DU) Заданная скорость перемещения РБ1
#define B2CV01RDU	 BUFFER[1591]	//( - , DU) Измеренная скорость перемещения РБ2
#define idB2CV01RDU	 691	//( - , DU) Измеренная скорость перемещения РБ2
#define B2AB04LDU	 BUFFER[1596]	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
#define idB2AB04LDU	 692	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
#define B2AB02LDU	 BUFFER[1598]	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
#define idB2AB02LDU	 693	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
#define B2AB01LDU	 BUFFER[1600]	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
#define idB2AB01LDU	 694	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
#define B2AZ03LDU	 BUFFER[1602]	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
#define idB2AZ03LDU	 695	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
#define B2AD11LDU	 BUFFER[1604]	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	 696	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
#define B2AD21LDU	 BUFFER[1606]	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	 697	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
#define B2AD02LDU	 BUFFER[1608]	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
#define idB2AD02LDU	 698	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
#define B2AD03LDU	 BUFFER[1610]	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
#define idB2AD03LDU	 699	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
#define B2AD04LDU	 BUFFER[1612]	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
#define idB2AD04LDU	 700	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
#define B2AD05LDU	 BUFFER[1614]	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
#define idB2AD05LDU	 701	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
#define B2AD01LDU	 BUFFER[1616]	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
#define idB2AD01LDU	 702	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
#define B2CV02RDU	 BUFFER[1618]	//( - , DU) Заданная скорость перемещения РБ2
#define idB2CV02RDU	 703	//( - , DU) Заданная скорость перемещения РБ2
#define B2AB07LDU	 BUFFER[1623]	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
#define idB2AB07LDU	 704	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
#define B2AB08LDU	 BUFFER[1625]	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
#define idB2AB08LDU	 705	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
#define B2AB05LDU	 BUFFER[1627]	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
#define idB2AB05LDU	 706	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
#define B2AB06LDU	 BUFFER[1629]	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
#define idB2AB06LDU	 707	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
#define B2AB09LDU	 BUFFER[1631]	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
#define idB2AB09LDU	 708	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
#define B2AB10LDU	 BUFFER[1633]	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
#define idB2AB10LDU	 709	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
#define A1AB16LDU	 BUFFER[1635]	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
#define idA1AB16LDU	 710	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
#define A1AB17LDU	 BUFFER[1637]	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
#define idA1AB17LDU	 711	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
#define A1AB18LDU	 BUFFER[1639]	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
#define idA1AB18LDU	 712	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
#define B1VS12LDU	 BUFFER[1641]	//( - , DU) Движение ББ2 в сторону ВУ
#define idB1VS12LDU	 713	//( - , DU) Движение ББ2 в сторону ВУ
#define B1CV01RDU	 BUFFER[1643]	//( - , DU) Измеренная скорость перемещения ББ2
#define idB1CV01RDU	 714	//( - , DU) Измеренная скорость перемещения ББ2
#define B1AB04LDU	 BUFFER[1648]	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
#define idB1AB04LDU	 715	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
#define B1AB02LDU	 BUFFER[1650]	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
#define idB1AB02LDU	 716	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
#define B1AB01LDU	 BUFFER[1652]	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
#define idB1AB01LDU	 717	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
#define B1VS22LDU	 BUFFER[1654]	//( - , DU) Движение ББ2 в сторону НУ
#define idB1VS22LDU	 718	//( - , DU) Движение ББ2 в сторону НУ
#define B1AZ03LDU	 BUFFER[1656]	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
#define idB1AZ03LDU	 719	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
#define B1AD11LDU	 BUFFER[1658]	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	 720	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
#define B1AD21LDU	 BUFFER[1660]	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	 721	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
#define B1AD02LDU	 BUFFER[1662]	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
#define idB1AD02LDU	 722	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
#define B1AD03LDU	 BUFFER[1664]	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
#define idB1AD03LDU	 723	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
#define B1AD04LDU	 BUFFER[1666]	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
#define idB1AD04LDU	 724	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
#define B1AD05LDU	 BUFFER[1668]	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
#define idB1AD05LDU	 725	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
#define B1AD01LDU	 BUFFER[1670]	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
#define idB1AD01LDU	 726	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
#define B1CV02RDU	 BUFFER[1672]	//( - , DU) Заданная скорость перемещения ББ2
#define idB1CV02RDU	 727	//( - , DU) Заданная скорость перемещения ББ2
#define B1AB07LDU	 BUFFER[1677]	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
#define idB1AB07LDU	 728	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
#define B1AB08LDU	 BUFFER[1679]	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
#define idB1AB08LDU	 729	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
#define B1AB05LDU	 BUFFER[1681]	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
#define idB1AB05LDU	 730	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
#define B1AB06LDU	 BUFFER[1683]	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
#define idB1AB06LDU	 731	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
#define B1AB09LDU	 BUFFER[1685]	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
#define idB1AB09LDU	 732	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
#define B1AB10LDU	 BUFFER[1687]	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
#define idB1AB10LDU	 733	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
#define A1CV01RDU	 BUFFER[1689]	//( - , DU) Измеренная скорость перемещения ББ1
#define idA1CV01RDU	 734	//( - , DU) Измеренная скорость перемещения ББ1
#define A1AB04LDU	 BUFFER[1694]	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
#define idA1AB04LDU	 735	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
#define A1AB02LDU	 BUFFER[1696]	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
#define idA1AB02LDU	 736	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
#define A1AB01LDU	 BUFFER[1698]	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
#define idA1AB01LDU	 737	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
#define A1VS22LDU	 BUFFER[1700]	//( - , DU) Движение ББ1 в сторону НУ
#define idA1VS22LDU	 738	//( - , DU) Движение ББ1 в сторону НУ
#define A1AZ03LDU	 BUFFER[1702]	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
#define idA1AZ03LDU	 739	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
#define A1AD11LDU	 BUFFER[1704]	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	 740	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
#define A1AD21LDU	 BUFFER[1706]	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	 741	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
#define A1AD02LDU	 BUFFER[1708]	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
#define idA1AD02LDU	 742	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
#define A1AD03LDU	 BUFFER[1710]	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
#define idA1AD03LDU	 743	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
#define A1AD04LDU	 BUFFER[1712]	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
#define idA1AD04LDU	 744	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
#define A1AD05LDU	 BUFFER[1714]	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
#define idA1AD05LDU	 745	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
#define A1AD01LDU	 BUFFER[1716]	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
#define idA1AD01LDU	 746	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
#define A1CV02RDU	 BUFFER[1718]	//( - , DU) Заданная скорость перемещения ББ1
#define idA1CV02RDU	 747	//( - , DU) Заданная скорость перемещения ББ1
#define A1AB07LDU	 BUFFER[1723]	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
#define idA1AB07LDU	 748	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
#define A1AB08LDU	 BUFFER[1725]	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
#define idA1AB08LDU	 749	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
#define A1AB05LDU	 BUFFER[1727]	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
#define idA1AB05LDU	 750	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
#define A1AB06LDU	 BUFFER[1729]	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
#define idA1AB06LDU	 751	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
#define A1AB09LDU	 BUFFER[1731]	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
#define idA1AB09LDU	 752	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
#define A1AB10LDU	 BUFFER[1733]	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
#define idA1AB10LDU	 753	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
#define A1AB11LDU	 BUFFER[1735]	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
#define idA1AB11LDU	 754	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
#define A1AB12LDU	 BUFFER[1737]	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA1AB12LDU	 755	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A1AB13LDU	 BUFFER[1739]	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
#define idA1AB13LDU	 756	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
#define A1AB14LDU	 BUFFER[1741]	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
#define idA1AB14LDU	 757	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
#define fEM_A1UC03RDU	 BUFFER[1743]	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define idfEM_A1UC03RDU	 758	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define dEM_A1UC05UDU	 BUFFER[1748]	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC05UDU	 759	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define dEM_A1UC06UDU	 BUFFER[1753]	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC06UDU	 760	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define dEM_A2UC06UDU	 BUFFER[1758]	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC06UDU	 761	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define dEM_A2UC05UDU	 BUFFER[1763]	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC05UDU	 762	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define fEM_A2UC03RDU	 BUFFER[1768]	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define idfEM_A2UC03RDU	 763	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define dEM_A3UC06UDU	 BUFFER[1773]	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC06UDU	 764	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define dEM_A3UC05UDU	 BUFFER[1778]	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC05UDU	 765	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define fEM_A3UC03RDU	 BUFFER[1783]	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define idfEM_A3UC03RDU	 766	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define dEM_A8UC06UDU	 BUFFER[1788]	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define iddEM_A8UC06UDU	 767	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define fEM_A8UC03RDU	 BUFFER[1793]	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
#define idfEM_A8UC03RDU	 768	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
#define dEM_A8UC05UDU	 BUFFER[1798]	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define iddEM_A8UC05UDU	 769	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define fEM_R0UV81RDU	 BUFFER[1803]	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	 770	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	 BUFFER[1808]	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	 771	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	 BUFFER[1813]	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	 772	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	 BUFFER[1818]	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	 773	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define fEM_R0UV86RDU	 BUFFER[1823]	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	 774	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV85RDU	 BUFFER[1828]	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	 775	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV87RDU	 BUFFER[1833]	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	 776	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_A3UP03RDU	 BUFFER[1838]	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	 777	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	 BUFFER[1843]	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	 778	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP43RDU	 BUFFER[1848]	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define idfEM_A3UP43RDU	 779	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define fEM_A3UP44RDU	 BUFFER[1853]	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP44RDU	 780	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP53RDU	 BUFFER[1858]	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP53RDU	 781	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP85RDU	 BUFFER[1863]	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP85RDU	 782	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP88RDU	 BUFFER[1868]	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP88RDU	 783	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP86RDU	 BUFFER[1873]	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP86RDU	 784	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_B8UV01RDU	 BUFFER[1878]	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
#define idfEM_B8UV01RDU	 785	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
#define fEM_B8UV02RDU	 BUFFER[1883]	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
#define idfEM_B8UV02RDU	 786	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
#define fEM_B8UV03RDU	 BUFFER[1888]	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
#define idfEM_B8UV03RDU	 787	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
#define fEM_B8UL04RDU	 BUFFER[1893]	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
#define idfEM_B8UL04RDU	 788	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
#define iEM_A2UV03CDU	 BUFFER[1898]	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define idiEM_A2UV03CDU	 789	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define fEM_A2UV01RDU	 BUFFER[1901]	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define idfEM_A2UV01RDU	 790	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define fEM_A2UV02RDU	 BUFFER[1906]	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define idfEM_A2UV02RDU	 791	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define fEM_A1UV01RDU	 BUFFER[1911]	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define idfEM_A1UV01RDU	 792	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define fEM_A1UV02RDU	 BUFFER[1916]	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define idfEM_A1UV02RDU	 793	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define fEM_A1UC06RDU	 BUFFER[1921]	//(A1UC06RDU) Уставка определения самохода ББ  мм
#define idfEM_A1UC06RDU	 794	//(A1UC06RDU) Уставка определения самохода ББ  мм
#define fEM_A1UC05RDU	 BUFFER[1926]	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A1UC05RDU	 795	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A1UL04RDU	 BUFFER[1931]	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define idfEM_A1UL04RDU	 796	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define fEM_A3UV01RDU	 BUFFER[1936]	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
#define idfEM_A3UV01RDU	 797	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
#define fEM_A3UV02RDU	 BUFFER[1941]	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
#define idfEM_A3UV02RDU	 798	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
#define fEM_A3UC06RDU	 BUFFER[1946]	//(A3UC06RDU) Уставка определения самохода ИС1  мм
#define idfEM_A3UC06RDU	 799	//(A3UC06RDU) Уставка определения самохода ИС1  мм
#define fEM_A3UC05RDU	 BUFFER[1951]	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A3UC05RDU	 800	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define fEM_A3UL04RDU	 BUFFER[1956]	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define idfEM_A3UL04RDU	 801	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define fEM_A3UP54RDU	 BUFFER[1961]	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define idfEM_A3UP54RDU	 802	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define fEM_A3UP87RDU	 BUFFER[1966]	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP87RDU	 803	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_R0UL05RDU	 BUFFER[1971]	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
#define idfEM_R0UL05RDU	 804	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
#define fEM_R0UL20RDU	 BUFFER[1976]	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
#define idfEM_R0UL20RDU	 805	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
#define fEM_B8UV04RDU	 BUFFER[1981]	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
#define idfEM_B8UV04RDU	 806	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
#define fEM_B8UC06RDU	 BUFFER[1986]	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
#define idfEM_B8UC06RDU	 807	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
#define fEM_B8UC05RDU	 BUFFER[1991]	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
#define idfEM_B8UC05RDU	 808	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
#define fEM_A2UL05RDU	 BUFFER[1996]	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define idfEM_A2UL05RDU	 809	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define fEM_A2UL03RDU	 BUFFER[2001]	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL03RDU	 810	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A2UC06RDU	 BUFFER[2006]	//(A2UC06RDU) Уставка определения самохода РБ  мм
#define idfEM_A2UC06RDU	 811	//(A2UC06RDU) Уставка определения самохода РБ  мм
#define fEM_A2UC05RDU	 BUFFER[2011]	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A2UC05RDU	 812	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A2UL04RDU	 BUFFER[2016]	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define idfEM_A2UL04RDU	 813	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define fEM_A1UL03RDU	 BUFFER[2021]	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define idfEM_A1UL03RDU	 814	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define fEM_A1UL05RDU	 BUFFER[2026]	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define idfEM_A1UL05RDU	 815	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define fEM_A3UL03RDU	 BUFFER[2031]	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define idfEM_A3UL03RDU	 816	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define fEM_A3UL05RDU	 BUFFER[2036]	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define idfEM_A3UL05RDU	 817	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define fEM_A1UC08RDU	 BUFFER[2041]	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define idfEM_A1UC08RDU	 818	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define fEM_A3UC08RDU	 BUFFER[2046]	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define idfEM_A3UC08RDU	 819	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define fEM_A1UC07RDU	 BUFFER[2051]	//(A1UC07RDU) Зона возврата при наведении ББ мм
#define idfEM_A1UC07RDU	 820	//(A1UC07RDU) Зона возврата при наведении ББ мм
#define fEM_A1UL01RDU	 BUFFER[2056]	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A1UL01RDU	 821	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A3UC07RDU	 BUFFER[2061]	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define idfEM_A3UC07RDU	 822	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define fEM_A3UL01RDU	 BUFFER[2066]	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A3UL01RDU	 823	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A2UC08RDU	 BUFFER[2071]	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define idfEM_A2UC08RDU	 824	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define fEM_A2UC07RDU	 BUFFER[2076]	//(A2UC07RDU) Зона возврата при наведении РБ  мм
#define idfEM_A2UC07RDU	 825	//(A2UC07RDU) Зона возврата при наведении РБ  мм
#define fEM_A2UL01RDU	 BUFFER[2081]	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A2UL01RDU	 826	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_B8UC01RDU	 BUFFER[2086]	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
#define idfEM_B8UC01RDU	 827	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
#define fEM_B8UL07RDU	 BUFFER[2091]	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
#define idfEM_B8UL07RDU	 828	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
#define fEM_B8UC02RDU	 BUFFER[2096]	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
#define idfEM_B8UC02RDU	 829	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
#define fEM_B8UL01RDU	 BUFFER[2101]	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_B8UL01RDU	 830	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_B8UL05RDU	 BUFFER[2106]	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
#define idfEM_B8UL05RDU	 831	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
#define fEM_B8UL03RDU	 BUFFER[2111]	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
#define idfEM_B8UL03RDU	 832	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
#define fEM_B8UL06RDU	 BUFFER[2116]	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
#define idfEM_B8UL06RDU	 833	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
#define fEM_A9UZ03RDU	 BUFFER[2121]	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
#define idfEM_A9UZ03RDU	 834	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
#define fEM_A9UZ04RDU	 BUFFER[2126]	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
#define idfEM_A9UZ04RDU	 835	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
#define fEM_A9UZ05RDU	 BUFFER[2131]	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
#define idfEM_A9UZ05RDU	 836	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
#define fEM_R4UZ04RDU	 BUFFER[2136]	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define idfEM_R4UZ04RDU	 837	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define fEM_R4UZ03RDU	 BUFFER[2141]	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define idfEM_R4UZ03RDU	 838	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define fEM_R4UZ05RDU	 BUFFER[2146]	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define idfEM_R4UZ05RDU	 839	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define fEM_A5UZ03RDU	 BUFFER[2151]	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
#define idfEM_A5UZ03RDU	 840	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
#define fEM_A5UZ04RDU	 BUFFER[2156]	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
#define idfEM_A5UZ04RDU	 841	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
#define fEM_A5UZ05RDU	 BUFFER[2161]	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
#define idfEM_A5UZ05RDU	 842	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
#define fEM_A4UZ03RDU	 BUFFER[2166]	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
#define idfEM_A4UZ03RDU	 843	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
#define fEM_A4UZ04RDU	 BUFFER[2171]	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
#define idfEM_A4UZ04RDU	 844	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
#define fEM_A4UZ05RDU	 BUFFER[2176]	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
#define idfEM_A4UZ05RDU	 845	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
#define fEM_A6UZ03RDU	 BUFFER[2181]	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
#define idfEM_A6UZ03RDU	 846	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
#define fEM_A6UZ04RDU	 BUFFER[2186]	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
#define idfEM_A6UZ04RDU	 847	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
#define fEM_A6UZ05RDU	 BUFFER[2191]	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
#define idfEM_A6UZ05RDU	 848	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
#define fEM_R1UZ03RDU	 BUFFER[2196]	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define idfEM_R1UZ03RDU	 849	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define fEM_R1UZ04RDU	 BUFFER[2201]	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define idfEM_R1UZ04RDU	 850	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define fEM_R1UZ05RDU	 BUFFER[2206]	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define idfEM_R1UZ05RDU	 851	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define fEM_R0UL04RDU	 BUFFER[2211]	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
#define idfEM_R0UL04RDU	 852	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
#define fEM_R0UL06RDU	 BUFFER[2216]	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
#define idfEM_R0UL06RDU	 853	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
#define fEM_R0UL03RDU	 BUFFER[2221]	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
#define idfEM_R0UL03RDU	 854	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
#define fEM_R0UL17RDU	 BUFFER[2226]	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
#define idfEM_R0UL17RDU	 855	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
#define fEM_R0UL19RDU	 BUFFER[2231]	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define idfEM_R0UL19RDU	 856	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define fEM_R0UL07RDU	 BUFFER[2236]	//(R0UL07RDU) Время срабатывания верхней АС II УР
#define idfEM_R0UL07RDU	 857	//(R0UL07RDU) Время срабатывания верхней АС II УР
#define fEM_R0UL18RDU	 BUFFER[2241]	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
#define idfEM_R0UL18RDU	 858	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
#define fEM_R0UL16RDU	 BUFFER[2246]	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
#define idfEM_R0UL16RDU	 859	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
#define fEM_R0UL02RDU	 BUFFER[2251]	//(R0UL02RDU) Время задержки  ИНИ
#define idfEM_R0UL02RDU	 860	//(R0UL02RDU) Время задержки  ИНИ
#define fEM_R0UN08RDU	 BUFFER[2256]	//(R0UN08RDU) 8-я заданная мощность
#define idfEM_R0UN08RDU	 861	//(R0UN08RDU) 8-я заданная мощность
#define fEM_R0UN07RDU	 BUFFER[2261]	//(R0UN07RDU) 7-я заданная мощность
#define idfEM_R0UN07RDU	 862	//(R0UN07RDU) 7-я заданная мощность
#define fEM_R0UN06RDU	 BUFFER[2266]	//(R0UN06RDU) 6-я заданная мощность
#define idfEM_R0UN06RDU	 863	//(R0UN06RDU) 6-я заданная мощность
#define fEM_R0UN05RDU	 BUFFER[2271]	//(R0UN05RDU) 5-я заданная мощность
#define idfEM_R0UN05RDU	 864	//(R0UN05RDU) 5-я заданная мощность
#define fEM_R0UN04RDU	 BUFFER[2276]	//(R0UN04RDU) 4-я заданная мощность
#define idfEM_R0UN04RDU	 865	//(R0UN04RDU) 4-я заданная мощность
#define fEM_R0UN03RDU	 BUFFER[2281]	//(R0UN03RDU) Ограничение 3 по мощности
#define idfEM_R0UN03RDU	 866	//(R0UN03RDU) Ограничение 3 по мощности
#define fEM_R0UN02RDU	 BUFFER[2286]	//(R0UN02RDU) 2-я заданная мощность
#define idfEM_R0UN02RDU	 867	//(R0UN02RDU) 2-я заданная мощность
#define fEM_R0UN01RDU	 BUFFER[2291]	//(R0UN01RDU) 1-я заданная мощность
#define idfEM_R0UN01RDU	 868	//(R0UN01RDU) 1-я заданная мощность
#define fEM_A2UC82RDU	 BUFFER[2296]	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC82RDU	 869	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define fEM_A2UC83RDU	 BUFFER[2301]	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define idfEM_A2UC83RDU	 870	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define fEM_A1UC83RDU	 BUFFER[2306]	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define idfEM_A1UC83RDU	 871	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define fEM_A2UC81RDU	 BUFFER[2311]	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC81RDU	 872	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define fEM_A1UC81RDU	 BUFFER[2316]	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC81RDU	 873	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define fEM_A1UC82RDU	 BUFFER[2321]	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC82RDU	 874	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define fEM_A2UL83RDU	 BUFFER[2326]	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL83RDU	 875	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A3UC81RDU	 BUFFER[2331]	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define idfEM_A3UC81RDU	 876	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define fEM_A3UC82RDU	 BUFFER[2336]	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define idfEM_A3UC82RDU	 877	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define fEM_R0UN80RDU	 BUFFER[2341]	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define idfEM_R0UN80RDU	 878	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define iEM_A2UV01IDU	 BUFFER[2346]	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV01IDU	 879	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define iEM_A2UV02IDU	 BUFFER[2349]	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV02IDU	 880	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define iEM_A1UV01IDU	 BUFFER[2352]	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV01IDU	 881	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define iEM_A1UV02IDU	 BUFFER[2355]	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV02IDU	 882	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define iEM_A1UV03IDU	 BUFFER[2358]	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define idiEM_A1UV03IDU	 883	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define iEM_A3UV01IDU	 BUFFER[2361]	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define idiEM_A3UV01IDU	 884	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define iEM_A3UV02IDU	 BUFFER[2364]	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define idiEM_A3UV02IDU	 885	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define lEM_R0MD01LC1	 BUFFER[2367]	//(R0MD01LC1) Ручное управление ОРР
#define idlEM_R0MD01LC1	 886	//(R0MD01LC1) Ручное управление ОРР
#define fEM_A3UC09RDU	 BUFFER[2369]	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC09RDU	 887	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define fEM_A2UC02RDU	 BUFFER[2374]	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define idfEM_A2UC02RDU	 888	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define fEM_A1UC02RDU	 BUFFER[2379]	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define idfEM_A1UC02RDU	 889	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define fEM_A3UC02RDU	 BUFFER[2384]	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define idfEM_A3UC02RDU	 890	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define fEM_R0UL21RDU	 BUFFER[2389]	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
#define idfEM_R0UL21RDU	 891	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
#define fEM_R0UN09RDU	 BUFFER[2394]	//(R0UN09RDU) Минимальный период при регулировании мощности
#define idfEM_R0UN09RDU	 892	//(R0UN09RDU) Минимальный период при регулировании мощности
#define fEM_R0UN11RDU	 BUFFER[2399]	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
#define idfEM_R0UN11RDU	 893	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
#define fEM_R0UN12RDU	 BUFFER[2404]	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
#define idfEM_R0UN12RDU	 894	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
#define fEM_R0UN13RDU	 BUFFER[2409]	//(R0UN13RDU) Минимальное изменение координаты, мм
#define idfEM_R0UN13RDU	 895	//(R0UN13RDU) Минимальное изменение координаты, мм
#define fEM_R0UN14RDU	 BUFFER[2414]	//(R0UN14RDU) Максимальная координата штока ИМ, мм
#define idfEM_R0UN14RDU	 896	//(R0UN14RDU) Максимальная координата штока ИМ, мм
#define fEM_R0UN16RDU	 BUFFER[2419]	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN16RDU	 897	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN17RDU	 BUFFER[2424]	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN17RDU	 898	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN18RDU	 BUFFER[2429]	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
#define idfEM_R0UN18RDU	 899	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
#define fEM_R0UN19RDU	 BUFFER[2434]	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define idfEM_R0UN19RDU	 900	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define fEM_R0UN70LDU	 BUFFER[2439]	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN70LDU	 901	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN71LDU	 BUFFER[2444]	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN71LDU	 902	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN72LDU	 BUFFER[2449]	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN72LDU	 903	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN73LDU	 BUFFER[2454]	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN73LDU	 904	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN74LDU	 BUFFER[2459]	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN74LDU	 905	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN75LDU	 BUFFER[2464]	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN75LDU	 906	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN80LDU	 BUFFER[2469]	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN80LDU	 907	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define fEM_R0UN81LDU	 BUFFER[2474]	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN81LDU	 908	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define fEM_R0UN82LDU	 BUFFER[2479]	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN82LDU	 909	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define fEM_R0UN83LDU	 BUFFER[2484]	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN83LDU	 910	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define fEM_R0UN84LDU	 BUFFER[2489]	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN84LDU	 911	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define fEM_R0UN85LDU	 BUFFER[2494]	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN85LDU	 912	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define fEM_R0UT20RDU	 BUFFER[2499]	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define idfEM_R0UT20RDU	 913	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define fEM_R0UN25RDU	 BUFFER[2504]	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
#define idfEM_R0UN25RDU	 914	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
#define fEM_R0UN15RDU	 BUFFER[2509]	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
#define idfEM_R0UN15RDU	 915	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
#define fEM_R0UN26RDU	 BUFFER[2514]	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
#define idfEM_R0UN26RDU	 916	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
#define fEM_R0UN27RDU	 BUFFER[2519]	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
#define idfEM_R0UN27RDU	 917	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
#define fEM_R0UN24RDU	 BUFFER[2524]	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN24RDU	 918	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
#define fEM_R0UL25RDU	 BUFFER[2529]	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define idfEM_R0UL25RDU	 919	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define bFirstEnterFlag	 BUFFER[2534]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 920	//(bFirstEnterFlag) 
#define internal2_m186_y0	 BUFFER[2536]	//(internal2_m186_y0) y0
#define idinternal2_m186_y0	 921	//(internal2_m186_y0) y0
#define internal2_m184_y0	 BUFFER[2541]	//(internal2_m184_y0) y0
#define idinternal2_m184_y0	 922	//(internal2_m184_y0) y0
#define internal2_m216_y0	 BUFFER[2546]	//(internal2_m216_y0) state
#define idinternal2_m216_y0	 923	//(internal2_m216_y0) state
#define internal2_m210_y0	 BUFFER[2548]	//(internal2_m210_y0) state
#define idinternal2_m210_y0	 924	//(internal2_m210_y0) state
#define internal2_m199_y1	 BUFFER[2550]	//(internal2_m199_y1) y1 - внутренний параметр
#define idinternal2_m199_y1	 925	//(internal2_m199_y1) y1 - внутренний параметр
#define internal2_m206_y1	 BUFFER[2552]	//(internal2_m206_y1) y1 - внутренний параметр
#define idinternal2_m206_y1	 926	//(internal2_m206_y1) y1 - внутренний параметр
#define internal2_m189_y1	 BUFFER[2554]	//(internal2_m189_y1) y1 - внутренний параметр
#define idinternal2_m189_y1	 927	//(internal2_m189_y1) y1 - внутренний параметр
#define internal2_m196_y1	 BUFFER[2556]	//(internal2_m196_y1) y1 - внутренний параметр
#define idinternal2_m196_y1	 928	//(internal2_m196_y1) y1 - внутренний параметр
#define internal2_m16_Nk0	 BUFFER[2558]	//(internal2_m16_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m16_Nk0	 929	//(internal2_m16_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m16_SetFlag	 BUFFER[2563]	//(internal2_m16_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m16_SetFlag	 930	//(internal2_m16_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m108_Nk0	 BUFFER[2565]	//(internal2_m108_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m108_Nk0	 931	//(internal2_m108_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m108_SetFlag	 BUFFER[2570]	//(internal2_m108_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m108_SetFlag	 932	//(internal2_m108_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m112_Nk0	 BUFFER[2572]	//(internal2_m112_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m112_Nk0	 933	//(internal2_m112_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m112_SetFlag	 BUFFER[2577]	//(internal2_m112_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m112_SetFlag	 934	//(internal2_m112_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m75_Nk0	 BUFFER[2579]	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m75_Nk0	 935	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m75_SetFlag	 BUFFER[2584]	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m75_SetFlag	 936	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m77_Nk0	 BUFFER[2586]	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m77_Nk0	 937	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m77_SetFlag	 BUFFER[2591]	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m77_SetFlag	 938	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m47_Nk0	 BUFFER[2593]	//(internal2_m47_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m47_Nk0	 939	//(internal2_m47_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m47_SetFlag	 BUFFER[2598]	//(internal2_m47_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m47_SetFlag	 940	//(internal2_m47_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m51_Nk0	 BUFFER[2600]	//(internal2_m51_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m51_Nk0	 941	//(internal2_m51_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m51_SetFlag	 BUFFER[2605]	//(internal2_m51_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m51_SetFlag	 942	//(internal2_m51_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m21_Nk0	 BUFFER[2607]	//(internal2_m21_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m21_Nk0	 943	//(internal2_m21_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m21_SetFlag	 BUFFER[2612]	//(internal2_m21_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m21_SetFlag	 944	//(internal2_m21_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal1_m1697_q0	 BUFFER[2614]	//(internal1_m1697_q0) q0 - внутренний параметр
#define idinternal1_m1697_q0	 945	//(internal1_m1697_q0) q0 - внутренний параметр
#define internal1_m2132_q0	 BUFFER[2616]	//(internal1_m2132_q0) q0 - внутренний параметр
#define idinternal1_m2132_q0	 946	//(internal1_m2132_q0) q0 - внутренний параметр
#define internal1_m2116_q0	 BUFFER[2618]	//(internal1_m2116_q0) q0 - внутренний параметр
#define idinternal1_m2116_q0	 947	//(internal1_m2116_q0) q0 - внутренний параметр
#define internal1_m2164_q0	 BUFFER[2620]	//(internal1_m2164_q0) q0 - внутренний параметр
#define idinternal1_m2164_q0	 948	//(internal1_m2164_q0) q0 - внутренний параметр
#define internal1_m2148_q0	 BUFFER[2622]	//(internal1_m2148_q0) q0 - внутренний параметр
#define idinternal1_m2148_q0	 949	//(internal1_m2148_q0) q0 - внутренний параметр
#define internal1_m2138_q0	 BUFFER[2624]	//(internal1_m2138_q0) q0 - внутренний параметр
#define idinternal1_m2138_q0	 950	//(internal1_m2138_q0) q0 - внутренний параметр
#define internal1_m2119_q0	 BUFFER[2626]	//(internal1_m2119_q0) q0 - внутренний параметр
#define idinternal1_m2119_q0	 951	//(internal1_m2119_q0) q0 - внутренний параметр
#define internal1_m2136_q0	 BUFFER[2628]	//(internal1_m2136_q0) q0 - внутренний параметр
#define idinternal1_m2136_q0	 952	//(internal1_m2136_q0) q0 - внутренний параметр
#define internal1_m2117_q0	 BUFFER[2630]	//(internal1_m2117_q0) q0 - внутренний параметр
#define idinternal1_m2117_q0	 953	//(internal1_m2117_q0) q0 - внутренний параметр
#define internal1_m2115_q0	 BUFFER[2632]	//(internal1_m2115_q0) q0 - внутренний параметр
#define idinternal1_m2115_q0	 954	//(internal1_m2115_q0) q0 - внутренний параметр
#define internal1_m2114_q0	 BUFFER[2634]	//(internal1_m2114_q0) q0 - внутренний параметр
#define idinternal1_m2114_q0	 955	//(internal1_m2114_q0) q0 - внутренний параметр
#define internal1_m2128_q0	 BUFFER[2636]	//(internal1_m2128_q0) q0 - внутренний параметр
#define idinternal1_m2128_q0	 956	//(internal1_m2128_q0) q0 - внутренний параметр
#define internal1_m2126_q0	 BUFFER[2638]	//(internal1_m2126_q0) q0 - внутренний параметр
#define idinternal1_m2126_q0	 957	//(internal1_m2126_q0) q0 - внутренний параметр
#define internal1_m2134_q0	 BUFFER[2640]	//(internal1_m2134_q0) q0 - внутренний параметр
#define idinternal1_m2134_q0	 958	//(internal1_m2134_q0) q0 - внутренний параметр
#define internal1_m2130_q0	 BUFFER[2642]	//(internal1_m2130_q0) q0 - внутренний параметр
#define idinternal1_m2130_q0	 959	//(internal1_m2130_q0) q0 - внутренний параметр
#define internal1_m2170_q0	 BUFFER[2644]	//(internal1_m2170_q0) q0 - внутренний параметр
#define idinternal1_m2170_q0	 960	//(internal1_m2170_q0) q0 - внутренний параметр
#define internal1_m2151_q0	 BUFFER[2646]	//(internal1_m2151_q0) q0 - внутренний параметр
#define idinternal1_m2151_q0	 961	//(internal1_m2151_q0) q0 - внутренний параметр
#define internal1_m2168_q0	 BUFFER[2648]	//(internal1_m2168_q0) q0 - внутренний параметр
#define idinternal1_m2168_q0	 962	//(internal1_m2168_q0) q0 - внутренний параметр
#define internal1_m2150_q0	 BUFFER[2650]	//(internal1_m2150_q0) q0 - внутренний параметр
#define idinternal1_m2150_q0	 963	//(internal1_m2150_q0) q0 - внутренний параметр
#define internal1_m2147_q0	 BUFFER[2652]	//(internal1_m2147_q0) q0 - внутренний параметр
#define idinternal1_m2147_q0	 964	//(internal1_m2147_q0) q0 - внутренний параметр
#define internal1_m2146_q0	 BUFFER[2654]	//(internal1_m2146_q0) q0 - внутренний параметр
#define idinternal1_m2146_q0	 965	//(internal1_m2146_q0) q0 - внутренний параметр
#define internal1_m2160_q0	 BUFFER[2656]	//(internal1_m2160_q0) q0 - внутренний параметр
#define idinternal1_m2160_q0	 966	//(internal1_m2160_q0) q0 - внутренний параметр
#define internal1_m2158_q0	 BUFFER[2658]	//(internal1_m2158_q0) q0 - внутренний параметр
#define idinternal1_m2158_q0	 967	//(internal1_m2158_q0) q0 - внутренний параметр
#define internal1_m2035_tx	 BUFFER[2660]	//(internal1_m2035_tx) tx - внутренний параметр
#define idinternal1_m2035_tx	 968	//(internal1_m2035_tx) tx - внутренний параметр
#define internal1_m2014_tx	 BUFFER[2665]	//(internal1_m2014_tx) tx - внутренний параметр
#define idinternal1_m2014_tx	 969	//(internal1_m2014_tx) tx - внутренний параметр
#define internal1_m1720_Pv0	 BUFFER[2670]	//(internal1_m1720_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1720_Pv0	 970	//(internal1_m1720_Pv0)  - Пер. выключатель механизма
#define internal1_m1720_Zv0	 BUFFER[2672]	//(internal1_m1720_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1720_Zv0	 971	//(internal1_m1720_Zv0)  - Зад. выключатель механизма
#define internal1_m1720_MyFirstEnterFlag	 BUFFER[2674]	//(internal1_m1720_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1720_MyFirstEnterFlag	 972	//(internal1_m1720_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m1718_Pv0	 BUFFER[2676]	//(internal1_m1718_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1718_Pv0	 973	//(internal1_m1718_Pv0)  - Пер. выключатель механизма
#define internal1_m1718_Zv0	 BUFFER[2678]	//(internal1_m1718_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1718_Zv0	 974	//(internal1_m1718_Zv0)  - Зад. выключатель механизма
#define internal1_m1718_MyFirstEnterFlag	 BUFFER[2680]	//(internal1_m1718_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1718_MyFirstEnterFlag	 975	//(internal1_m1718_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m2189_tx	 BUFFER[2682]	//(internal1_m2189_tx) tx - время накопленное сек
#define idinternal1_m2189_tx	 976	//(internal1_m2189_tx) tx - время накопленное сек
#define internal1_m2189_y0	 BUFFER[2687]	//(internal1_m2189_y0) y0
#define idinternal1_m2189_y0	 977	//(internal1_m2189_y0) y0
#define internal1_m2193_tx	 BUFFER[2688]	//(internal1_m2193_tx) tx - время накопленное сек
#define idinternal1_m2193_tx	 978	//(internal1_m2193_tx) tx - время накопленное сек
#define internal1_m2193_y0	 BUFFER[2693]	//(internal1_m2193_y0) y0
#define idinternal1_m2193_y0	 979	//(internal1_m2193_y0) y0
#define internal1_m2192_tx	 BUFFER[2694]	//(internal1_m2192_tx) tx - время накопленное сек
#define idinternal1_m2192_tx	 980	//(internal1_m2192_tx) tx - время накопленное сек
#define internal1_m2192_y0	 BUFFER[2699]	//(internal1_m2192_y0) y0
#define idinternal1_m2192_y0	 981	//(internal1_m2192_y0) y0
#define internal1_m2229_tx	 BUFFER[2700]	//(internal1_m2229_tx) tx - внутренний параметр
#define idinternal1_m2229_tx	 982	//(internal1_m2229_tx) tx - внутренний параметр
#define internal1_m2227_tx	 BUFFER[2705]	//(internal1_m2227_tx) tx - время накопленное сек
#define idinternal1_m2227_tx	 983	//(internal1_m2227_tx) tx - время накопленное сек
#define internal1_m2227_y0	 BUFFER[2710]	//(internal1_m2227_y0) y0
#define idinternal1_m2227_y0	 984	//(internal1_m2227_y0) y0
#define internal1_m2232_q0	 BUFFER[2711]	//(internal1_m2232_q0) q0 - внутренний параметр
#define idinternal1_m2232_q0	 985	//(internal1_m2232_q0) q0 - внутренний параметр
#define internal1_m2199_q0	 BUFFER[2713]	//(internal1_m2199_q0) q0 - внутренний параметр
#define idinternal1_m2199_q0	 986	//(internal1_m2199_q0) q0 - внутренний параметр
#define internal1_m2207_tx	 BUFFER[2715]	//(internal1_m2207_tx) tx - внутренний параметр
#define idinternal1_m2207_tx	 987	//(internal1_m2207_tx) tx - внутренний параметр
#define internal1_m2205_q0	 BUFFER[2720]	//(internal1_m2205_q0) q0 - внутренний параметр
#define idinternal1_m2205_q0	 988	//(internal1_m2205_q0) q0 - внутренний параметр
#define internal1_m2029_tx	 BUFFER[2722]	//(internal1_m2029_tx) tx - время накопленное сек
#define idinternal1_m2029_tx	 989	//(internal1_m2029_tx) tx - время накопленное сек
#define internal1_m2029_y0	 BUFFER[2727]	//(internal1_m2029_y0) y0
#define idinternal1_m2029_y0	 990	//(internal1_m2029_y0) y0
#define internal1_m2021_tx	 BUFFER[2728]	//(internal1_m2021_tx) tx - время накопленное сек
#define idinternal1_m2021_tx	 991	//(internal1_m2021_tx) tx - время накопленное сек
#define internal1_m2021_y0	 BUFFER[2733]	//(internal1_m2021_y0) y0
#define idinternal1_m2021_y0	 992	//(internal1_m2021_y0) y0
#define internal1_m1707_q0	 BUFFER[2734]	//(internal1_m1707_q0) q0 - внутренний параметр
#define idinternal1_m1707_q0	 993	//(internal1_m1707_q0) q0 - внутренний параметр
#define internal1_m1712_q0	 BUFFER[2736]	//(internal1_m1712_q0) q0 - внутренний параметр
#define idinternal1_m1712_q0	 994	//(internal1_m1712_q0) q0 - внутренний параметр
#define internal1_m1704_q0	 BUFFER[2738]	//(internal1_m1704_q0) q0 - внутренний параметр
#define idinternal1_m1704_q0	 995	//(internal1_m1704_q0) q0 - внутренний параметр
#define internal1_m1746_q0	 BUFFER[2740]	//(internal1_m1746_q0) q0 - внутренний параметр
#define idinternal1_m1746_q0	 996	//(internal1_m1746_q0) q0 - внутренний параметр
#define internal1_m746_tx	 BUFFER[2742]	//(internal1_m746_tx) tx - время накопленное сек
#define idinternal1_m746_tx	 997	//(internal1_m746_tx) tx - время накопленное сек
#define internal1_m746_y0	 BUFFER[2747]	//(internal1_m746_y0) y0
#define idinternal1_m746_y0	 998	//(internal1_m746_y0) y0
#define internal1_m2025_tx	 BUFFER[2748]	//(internal1_m2025_tx) tx - внутренний параметр
#define idinternal1_m2025_tx	 999	//(internal1_m2025_tx) tx - внутренний параметр
#define internal1_m2028_q0	 BUFFER[2753]	//(internal1_m2028_q0) q0 - внутренний параметр
#define idinternal1_m2028_q0	 1000	//(internal1_m2028_q0) q0 - внутренний параметр
#define internal1_m2020_q0	 BUFFER[2755]	//(internal1_m2020_q0) q0 - внутренний параметр
#define idinternal1_m2020_q0	 1001	//(internal1_m2020_q0) q0 - внутренний параметр
#define internal1_m1990_tx	 BUFFER[2757]	//(internal1_m1990_tx) tx - внутренний параметр
#define idinternal1_m1990_tx	 1002	//(internal1_m1990_tx) tx - внутренний параметр
#define internal1_m2001_tx	 BUFFER[2762]	//(internal1_m2001_tx) tx - внутренний параметр
#define idinternal1_m2001_tx	 1003	//(internal1_m2001_tx) tx - внутренний параметр
#define internal1_m1987_tx	 BUFFER[2767]	//(internal1_m1987_tx) tx - внутренний параметр
#define idinternal1_m1987_tx	 1004	//(internal1_m1987_tx) tx - внутренний параметр
#define internal1_m1993_q0	 BUFFER[2772]	//(internal1_m1993_q0) q0 - внутренний параметр
#define idinternal1_m1993_q0	 1005	//(internal1_m1993_q0) q0 - внутренний параметр
#define internal1_m2005_q0	 BUFFER[2774]	//(internal1_m2005_q0) q0 - внутренний параметр
#define idinternal1_m2005_q0	 1006	//(internal1_m2005_q0) q0 - внутренний параметр
#define internal1_m1963_tx	 BUFFER[2776]	//(internal1_m1963_tx) tx - внутренний параметр
#define idinternal1_m1963_tx	 1007	//(internal1_m1963_tx) tx - внутренний параметр
#define internal1_m57_tx	 BUFFER[2781]	//(internal1_m57_tx) tx - внутренний параметр
#define idinternal1_m57_tx	 1008	//(internal1_m57_tx) tx - внутренний параметр
#define internal1_m343_tx	 BUFFER[2786]	//(internal1_m343_tx) tx - внутренний параметр
#define idinternal1_m343_tx	 1009	//(internal1_m343_tx) tx - внутренний параметр
#define internal1_m298_tx	 BUFFER[2791]	//(internal1_m298_tx) tx - внутренний параметр
#define idinternal1_m298_tx	 1010	//(internal1_m298_tx) tx - внутренний параметр
#define internal1_m747_tx	 BUFFER[2796]	//(internal1_m747_tx) tx - внутренний параметр
#define idinternal1_m747_tx	 1011	//(internal1_m747_tx) tx - внутренний параметр
#define internal1_m1427_tx	 BUFFER[2801]	//(internal1_m1427_tx) tx - внутренний параметр
#define idinternal1_m1427_tx	 1012	//(internal1_m1427_tx) tx - внутренний параметр
#define internal1_m119_tx	 BUFFER[2806]	//(internal1_m119_tx) tx - внутренний параметр
#define idinternal1_m119_tx	 1013	//(internal1_m119_tx) tx - внутренний параметр
#define internal1_m121_tx	 BUFFER[2811]	//(internal1_m121_tx) tx - внутренний параметр
#define idinternal1_m121_tx	 1014	//(internal1_m121_tx) tx - внутренний параметр
#define internal1_m126_tx	 BUFFER[2816]	//(internal1_m126_tx) tx - внутренний параметр
#define idinternal1_m126_tx	 1015	//(internal1_m126_tx) tx - внутренний параметр
#define internal1_m24_tx	 BUFFER[2821]	//(internal1_m24_tx) tx - внутренний параметр
#define idinternal1_m24_tx	 1016	//(internal1_m24_tx) tx - внутренний параметр
#define internal1_m16_tx	 BUFFER[2826]	//(internal1_m16_tx) tx - внутренний параметр
#define idinternal1_m16_tx	 1017	//(internal1_m16_tx) tx - внутренний параметр
#define internal1_m1972_tx	 BUFFER[2831]	//(internal1_m1972_tx) tx - внутренний параметр
#define idinternal1_m1972_tx	 1018	//(internal1_m1972_tx) tx - внутренний параметр
#define internal1_m1960_tx	 BUFFER[2836]	//(internal1_m1960_tx) tx - внутренний параметр
#define idinternal1_m1960_tx	 1019	//(internal1_m1960_tx) tx - внутренний параметр
#define internal1_m2068_tx	 BUFFER[2841]	//(internal1_m2068_tx) tx - внутренний параметр
#define idinternal1_m2068_tx	 1020	//(internal1_m2068_tx) tx - внутренний параметр
#define internal1_m2072_tx	 BUFFER[2846]	//(internal1_m2072_tx) tx - внутренний параметр
#define idinternal1_m2072_tx	 1021	//(internal1_m2072_tx) tx - внутренний параметр
#define internal1_m1885_tx	 BUFFER[2851]	//(internal1_m1885_tx) tx - внутренний параметр
#define idinternal1_m1885_tx	 1022	//(internal1_m1885_tx) tx - внутренний параметр
#define internal1_m83_tx	 BUFFER[2856]	//(internal1_m83_tx) tx - внутренний параметр
#define idinternal1_m83_tx	 1023	//(internal1_m83_tx) tx - внутренний параметр
#define internal1_m312_tx	 BUFFER[2861]	//(internal1_m312_tx) tx - время накопленное сек
#define idinternal1_m312_tx	 1024	//(internal1_m312_tx) tx - время накопленное сек
#define internal1_m312_y0	 BUFFER[2866]	//(internal1_m312_y0) y0
#define idinternal1_m312_y0	 1025	//(internal1_m312_y0) y0
#define internal1_m1879_tx	 BUFFER[2867]	//(internal1_m1879_tx) tx - время накопленное сек
#define idinternal1_m1879_tx	 1026	//(internal1_m1879_tx) tx - время накопленное сек
#define internal1_m1879_y0	 BUFFER[2872]	//(internal1_m1879_y0) y0
#define idinternal1_m1879_y0	 1027	//(internal1_m1879_y0) y0
#define internal1_m1877_tx	 BUFFER[2873]	//(internal1_m1877_tx) tx - время накопленное сек
#define idinternal1_m1877_tx	 1028	//(internal1_m1877_tx) tx - время накопленное сек
#define internal1_m1877_y0	 BUFFER[2878]	//(internal1_m1877_y0) y0
#define idinternal1_m1877_y0	 1029	//(internal1_m1877_y0) y0
#define internal1_m1866_tx	 BUFFER[2879]	//(internal1_m1866_tx) tx - время накопленное сек
#define idinternal1_m1866_tx	 1030	//(internal1_m1866_tx) tx - время накопленное сек
#define internal1_m1866_y0	 BUFFER[2884]	//(internal1_m1866_y0) y0
#define idinternal1_m1866_y0	 1031	//(internal1_m1866_y0) y0
#define internal1_m1886_q0	 BUFFER[2885]	//(internal1_m1886_q0) q0 - внутренний параметр
#define idinternal1_m1886_q0	 1032	//(internal1_m1886_q0) q0 - внутренний параметр
#define internal1_m1447_q0	 BUFFER[2890]	//(internal1_m1447_q0) q0 - внутренний параметр
#define idinternal1_m1447_q0	 1033	//(internal1_m1447_q0) q0 - внутренний параметр
#define internal1_m1485_q0	 BUFFER[2895]	//(internal1_m1485_q0) q0 - внутренний параметр
#define idinternal1_m1485_q0	 1034	//(internal1_m1485_q0) q0 - внутренний параметр
#define internal1_m1488_q0	 BUFFER[2900]	//(internal1_m1488_q0) q0 - внутренний параметр
#define idinternal1_m1488_q0	 1035	//(internal1_m1488_q0) q0 - внутренний параметр
#define internal1_m1925_q0	 BUFFER[2905]	//(internal1_m1925_q0) q0 - внутренний параметр
#define idinternal1_m1925_q0	 1036	//(internal1_m1925_q0) q0 - внутренний параметр
#define internal1_m1903_tx	 BUFFER[2910]	//(internal1_m1903_tx) tx - время накопленное сек
#define idinternal1_m1903_tx	 1037	//(internal1_m1903_tx) tx - время накопленное сек
#define internal1_m1903_y0	 BUFFER[2915]	//(internal1_m1903_y0) y0
#define idinternal1_m1903_y0	 1038	//(internal1_m1903_y0) y0
#define internal1_m1918_tx	 BUFFER[2916]	//(internal1_m1918_tx) tx - время накопленное сек
#define idinternal1_m1918_tx	 1039	//(internal1_m1918_tx) tx - время накопленное сек
#define internal1_m1918_y0	 BUFFER[2921]	//(internal1_m1918_y0) y0
#define idinternal1_m1918_y0	 1040	//(internal1_m1918_y0) y0
#define internal1_m1915_tx	 BUFFER[2922]	//(internal1_m1915_tx) tx - время накопленное сек
#define idinternal1_m1915_tx	 1041	//(internal1_m1915_tx) tx - время накопленное сек
#define internal1_m1915_y0	 BUFFER[2927]	//(internal1_m1915_y0) y0
#define idinternal1_m1915_y0	 1042	//(internal1_m1915_y0) y0
#define internal1_m2051_tx	 BUFFER[2928]	//(internal1_m2051_tx) tx - время накопленное сек
#define idinternal1_m2051_tx	 1043	//(internal1_m2051_tx) tx - время накопленное сек
#define internal1_m2051_y0	 BUFFER[2933]	//(internal1_m2051_y0) y0
#define idinternal1_m2051_y0	 1044	//(internal1_m2051_y0) y0
#define internal1_m2062_tx	 BUFFER[2934]	//(internal1_m2062_tx) tx - время накопленное сек
#define idinternal1_m2062_tx	 1045	//(internal1_m2062_tx) tx - время накопленное сек
#define internal1_m2062_y0	 BUFFER[2939]	//(internal1_m2062_y0) y0
#define idinternal1_m2062_y0	 1046	//(internal1_m2062_y0) y0
#define internal1_m1814_tx	 BUFFER[2940]	//(internal1_m1814_tx) tx - время накопленное сек
#define idinternal1_m1814_tx	 1047	//(internal1_m1814_tx) tx - время накопленное сек
#define internal1_m1814_y0	 BUFFER[2945]	//(internal1_m1814_y0) y0
#define idinternal1_m1814_y0	 1048	//(internal1_m1814_y0) y0
#define internal1_m1813_tx	 BUFFER[2946]	//(internal1_m1813_tx) tx - время накопленное сек
#define idinternal1_m1813_tx	 1049	//(internal1_m1813_tx) tx - время накопленное сек
#define internal1_m1813_y0	 BUFFER[2951]	//(internal1_m1813_y0) y0
#define idinternal1_m1813_y0	 1050	//(internal1_m1813_y0) y0
#define internal1_m1812_tx	 BUFFER[2952]	//(internal1_m1812_tx) tx - время накопленное сек
#define idinternal1_m1812_tx	 1051	//(internal1_m1812_tx) tx - время накопленное сек
#define internal1_m1812_y0	 BUFFER[2957]	//(internal1_m1812_y0) y0
#define idinternal1_m1812_y0	 1052	//(internal1_m1812_y0) y0
#define internal1_m1811_tx	 BUFFER[2958]	//(internal1_m1811_tx) tx - время накопленное сек
#define idinternal1_m1811_tx	 1053	//(internal1_m1811_tx) tx - время накопленное сек
#define internal1_m1811_y0	 BUFFER[2963]	//(internal1_m1811_y0) y0
#define idinternal1_m1811_y0	 1054	//(internal1_m1811_y0) y0
#define internal1_m1499_tx	 BUFFER[2964]	//(internal1_m1499_tx) tx - время накопленное сек
#define idinternal1_m1499_tx	 1055	//(internal1_m1499_tx) tx - время накопленное сек
#define internal1_m1499_y0	 BUFFER[2969]	//(internal1_m1499_y0) y0
#define idinternal1_m1499_y0	 1056	//(internal1_m1499_y0) y0
#define internal1_m1493_tx	 BUFFER[2970]	//(internal1_m1493_tx) tx - время накопленное сек
#define idinternal1_m1493_tx	 1057	//(internal1_m1493_tx) tx - время накопленное сек
#define internal1_m1493_y0	 BUFFER[2975]	//(internal1_m1493_y0) y0
#define idinternal1_m1493_y0	 1058	//(internal1_m1493_y0) y0
#define internal1_m1443_tx	 BUFFER[2976]	//(internal1_m1443_tx) tx - время накопленное сек
#define idinternal1_m1443_tx	 1059	//(internal1_m1443_tx) tx - время накопленное сек
#define internal1_m1443_y0	 BUFFER[2981]	//(internal1_m1443_y0) y0
#define idinternal1_m1443_y0	 1060	//(internal1_m1443_y0) y0
#define internal1_m830_tx	 BUFFER[2982]	//(internal1_m830_tx) tx - время накопленное сек
#define idinternal1_m830_tx	 1061	//(internal1_m830_tx) tx - время накопленное сек
#define internal1_m830_y0	 BUFFER[2987]	//(internal1_m830_y0) y0
#define idinternal1_m830_y0	 1062	//(internal1_m830_y0) y0
#define internal1_m827_tx	 BUFFER[2988]	//(internal1_m827_tx) tx - время накопленное сек
#define idinternal1_m827_tx	 1063	//(internal1_m827_tx) tx - время накопленное сек
#define internal1_m827_y0	 BUFFER[2993]	//(internal1_m827_y0) y0
#define idinternal1_m827_y0	 1064	//(internal1_m827_y0) y0
#define internal1_m834_tx	 BUFFER[2994]	//(internal1_m834_tx) tx - время накопленное сек
#define idinternal1_m834_tx	 1065	//(internal1_m834_tx) tx - время накопленное сек
#define internal1_m834_y0	 BUFFER[2999]	//(internal1_m834_y0) y0
#define idinternal1_m834_y0	 1066	//(internal1_m834_y0) y0
#define internal1_m193_tx	 BUFFER[3000]	//(internal1_m193_tx) tx - время накопленное сек
#define idinternal1_m193_tx	 1067	//(internal1_m193_tx) tx - время накопленное сек
#define internal1_m193_y0	 BUFFER[3005]	//(internal1_m193_y0) y0
#define idinternal1_m193_y0	 1068	//(internal1_m193_y0) y0
#define internal1_m198_tx	 BUFFER[3006]	//(internal1_m198_tx) tx - время накопленное сек
#define idinternal1_m198_tx	 1069	//(internal1_m198_tx) tx - время накопленное сек
#define internal1_m198_y0	 BUFFER[3011]	//(internal1_m198_y0) y0
#define idinternal1_m198_y0	 1070	//(internal1_m198_y0) y0
#define internal1_m204_tx	 BUFFER[3012]	//(internal1_m204_tx) tx - время накопленное сек
#define idinternal1_m204_tx	 1071	//(internal1_m204_tx) tx - время накопленное сек
#define internal1_m204_y0	 BUFFER[3017]	//(internal1_m204_y0) y0
#define idinternal1_m204_y0	 1072	//(internal1_m204_y0) y0
#define internal1_m523_tx	 BUFFER[3018]	//(internal1_m523_tx) tx - время накопленное сек
#define idinternal1_m523_tx	 1073	//(internal1_m523_tx) tx - время накопленное сек
#define internal1_m523_y0	 BUFFER[3023]	//(internal1_m523_y0) y0
#define idinternal1_m523_y0	 1074	//(internal1_m523_y0) y0
#define internal1_m2100_tx	 BUFFER[3024]	//(internal1_m2100_tx) tx - внутренний параметр
#define idinternal1_m2100_tx	 1075	//(internal1_m2100_tx) tx - внутренний параметр
#define internal1_m1188_tx	 BUFFER[3029]	//(internal1_m1188_tx) tx - внутренний параметр
#define idinternal1_m1188_tx	 1076	//(internal1_m1188_tx) tx - внутренний параметр
#define internal1_m1613_tx	 BUFFER[3034]	//(internal1_m1613_tx) tx - время накопленное сек
#define idinternal1_m1613_tx	 1077	//(internal1_m1613_tx) tx - время накопленное сек
#define internal1_m1613_y0	 BUFFER[3039]	//(internal1_m1613_y0) y0
#define idinternal1_m1613_y0	 1078	//(internal1_m1613_y0) y0
#define internal1_m1138_tx	 BUFFER[3040]	//(internal1_m1138_tx) tx - время накопленное сек
#define idinternal1_m1138_tx	 1079	//(internal1_m1138_tx) tx - время накопленное сек
#define internal1_m1138_y0	 BUFFER[3045]	//(internal1_m1138_y0) y0
#define idinternal1_m1138_y0	 1080	//(internal1_m1138_y0) y0
#define internal1_m1339_tx	 BUFFER[3046]	//(internal1_m1339_tx) tx - время накопленное сек
#define idinternal1_m1339_tx	 1081	//(internal1_m1339_tx) tx - время накопленное сек
#define internal1_m1339_y0	 BUFFER[3051]	//(internal1_m1339_y0) y0
#define idinternal1_m1339_y0	 1082	//(internal1_m1339_y0) y0
#define internal1_m927_tx	 BUFFER[3052]	//(internal1_m927_tx) tx - время накопленное сек
#define idinternal1_m927_tx	 1083	//(internal1_m927_tx) tx - время накопленное сек
#define internal1_m927_y0	 BUFFER[3057]	//(internal1_m927_y0) y0
#define idinternal1_m927_y0	 1084	//(internal1_m927_y0) y0
#define internal1_m1246_tx	 BUFFER[3058]	//(internal1_m1246_tx) tx - время накопленное сек
#define idinternal1_m1246_tx	 1085	//(internal1_m1246_tx) tx - время накопленное сек
#define internal1_m1246_y0	 BUFFER[3063]	//(internal1_m1246_y0) y0
#define idinternal1_m1246_y0	 1086	//(internal1_m1246_y0) y0
#define internal1_m1079_q0	 BUFFER[3064]	//(internal1_m1079_q0) q0 - внутренний параметр
#define idinternal1_m1079_q0	 1087	//(internal1_m1079_q0) q0 - внутренний параметр
#define internal1_m1077_q0	 BUFFER[3066]	//(internal1_m1077_q0) q0 - внутренний параметр
#define idinternal1_m1077_q0	 1088	//(internal1_m1077_q0) q0 - внутренний параметр
#define internal1_m1076_q0	 BUFFER[3068]	//(internal1_m1076_q0) q0 - внутренний параметр
#define idinternal1_m1076_q0	 1089	//(internal1_m1076_q0) q0 - внутренний параметр
#define internal1_m1074_q0	 BUFFER[3070]	//(internal1_m1074_q0) q0 - внутренний параметр
#define idinternal1_m1074_q0	 1090	//(internal1_m1074_q0) q0 - внутренний параметр
#define internal1_m1073_q0	 BUFFER[3072]	//(internal1_m1073_q0) q0 - внутренний параметр
#define idinternal1_m1073_q0	 1091	//(internal1_m1073_q0) q0 - внутренний параметр
#define internal1_m1071_q0	 BUFFER[3074]	//(internal1_m1071_q0) q0 - внутренний параметр
#define idinternal1_m1071_q0	 1092	//(internal1_m1071_q0) q0 - внутренний параметр
#define internal1_m1070_q0	 BUFFER[3076]	//(internal1_m1070_q0) q0 - внутренний параметр
#define idinternal1_m1070_q0	 1093	//(internal1_m1070_q0) q0 - внутренний параметр
#define internal1_m1068_q0	 BUFFER[3078]	//(internal1_m1068_q0) q0 - внутренний параметр
#define idinternal1_m1068_q0	 1094	//(internal1_m1068_q0) q0 - внутренний параметр
#define internal1_m1067_q0	 BUFFER[3080]	//(internal1_m1067_q0) q0 - внутренний параметр
#define idinternal1_m1067_q0	 1095	//(internal1_m1067_q0) q0 - внутренний параметр
#define internal1_m58_x0	 BUFFER[3082]	//(internal1_m58_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m58_x0	 1096	//(internal1_m58_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m987_q0	 BUFFER[3084]	//(internal1_m987_q0) q0 - внутренний параметр
#define idinternal1_m987_q0	 1097	//(internal1_m987_q0) q0 - внутренний параметр
#define internal1_m1436_x0	 BUFFER[3086]	//(internal1_m1436_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1436_x0	 1098	//(internal1_m1436_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1480_x0	 BUFFER[3088]	//(internal1_m1480_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1480_x0	 1099	//(internal1_m1480_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1476_x0	 BUFFER[3090]	//(internal1_m1476_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1476_x0	 1100	//(internal1_m1476_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1894_x0	 BUFFER[3092]	//(internal1_m1894_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1894_x0	 1101	//(internal1_m1894_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1859_x0	 BUFFER[3094]	//(internal1_m1859_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1859_x0	 1102	//(internal1_m1859_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1026_q0	 BUFFER[3096]	//(internal1_m1026_q0) q0 - внутренний параметр
#define idinternal1_m1026_q0	 1103	//(internal1_m1026_q0) q0 - внутренний параметр
#define internal1_m1037_q0	 BUFFER[3098]	//(internal1_m1037_q0) q0 - внутренний параметр
#define idinternal1_m1037_q0	 1104	//(internal1_m1037_q0) q0 - внутренний параметр
#define internal1_m1050_q0	 BUFFER[3100]	//(internal1_m1050_q0) q0 - внутренний параметр
#define idinternal1_m1050_q0	 1105	//(internal1_m1050_q0) q0 - внутренний параметр
#define internal1_m1059_q0	 BUFFER[3102]	//(internal1_m1059_q0) q0 - внутренний параметр
#define idinternal1_m1059_q0	 1106	//(internal1_m1059_q0) q0 - внутренний параметр
#define internal1_m1036_q0	 BUFFER[3104]	//(internal1_m1036_q0) q0 - внутренний параметр
#define idinternal1_m1036_q0	 1107	//(internal1_m1036_q0) q0 - внутренний параметр
#define internal1_m1052_q0	 BUFFER[3106]	//(internal1_m1052_q0) q0 - внутренний параметр
#define idinternal1_m1052_q0	 1108	//(internal1_m1052_q0) q0 - внутренний параметр
#define internal1_m1952_q0	 BUFFER[3108]	//(internal1_m1952_q0) q0 - внутренний параметр
#define idinternal1_m1952_q0	 1109	//(internal1_m1952_q0) q0 - внутренний параметр
#define internal1_m1951_q0	 BUFFER[3110]	//(internal1_m1951_q0) q0 - внутренний параметр
#define idinternal1_m1951_q0	 1110	//(internal1_m1951_q0) q0 - внутренний параметр
#define internal1_m331_Step	 BUFFER[3112]	//(internal1_m331_Step)  - текущий шаг программы
#define idinternal1_m331_Step	 1111	//(internal1_m331_Step)  - текущий шаг программы
#define internal1_m331_rz	 BUFFER[3115]	//(internal1_m331_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m331_rz	 1112	//(internal1_m331_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m331_TimS	 BUFFER[3125]	//(internal1_m331_TimS) Время от старта программы
#define idinternal1_m331_TimS	 1113	//(internal1_m331_TimS) Время от старта программы
#define internal1_m331_FinPr0	 BUFFER[3130]	//(internal1_m331_FinPr0) FinPr - конец программы
#define idinternal1_m331_FinPr0	 1114	//(internal1_m331_FinPr0) FinPr - конец программы
#define internal1_m331_ErrPr0	 BUFFER[3132]	//(internal1_m331_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m331_ErrPr0	 1115	//(internal1_m331_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m331_sbINI0	 BUFFER[3134]	//(internal1_m331_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m331_sbINI0	 1116	//(internal1_m331_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m331_sbVuIS0	 BUFFER[3136]	//(internal1_m331_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m331_sbVuIS0	 1117	//(internal1_m331_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m331_sb2UR0	 BUFFER[3138]	//(internal1_m331_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m331_sb2UR0	 1118	//(internal1_m331_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m331_sbNupIS0	 BUFFER[3140]	//(internal1_m331_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m331_sbNupIS0	 1119	//(internal1_m331_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m331_sbVuRB0	 BUFFER[3142]	//(internal1_m331_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m331_sbVuRB0	 1120	//(internal1_m331_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m331_MyFirstEnterFlag	 BUFFER[3144]	//(internal1_m331_MyFirstEnterFlag)  
#define idinternal1_m331_MyFirstEnterFlag	 1121	//(internal1_m331_MyFirstEnterFlag)  
#define internal1_m339_x0	 BUFFER[3146]	//(internal1_m339_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m339_x0	 1122	//(internal1_m339_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m297_TimS	 BUFFER[3151]	//(internal1_m297_TimS) Время старта
#define idinternal1_m297_TimS	 1123	//(internal1_m297_TimS) Время старта
#define internal1_m274_Step	 BUFFER[3156]	//(internal1_m274_Step)  - текущий шаг программы
#define idinternal1_m274_Step	 1124	//(internal1_m274_Step)  - текущий шаг программы
#define internal1_m274_rz	 BUFFER[3159]	//(internal1_m274_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m274_rz	 1125	//(internal1_m274_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m274_TimS	 BUFFER[3169]	//(internal1_m274_TimS) Время от старта программы
#define idinternal1_m274_TimS	 1126	//(internal1_m274_TimS) Время от старта программы
#define internal1_m274_FinPr0	 BUFFER[3174]	//(internal1_m274_FinPr0) FinPr - конец программы
#define idinternal1_m274_FinPr0	 1127	//(internal1_m274_FinPr0) FinPr - конец программы
#define internal1_m274_ErrPr0	 BUFFER[3176]	//(internal1_m274_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m274_ErrPr0	 1128	//(internal1_m274_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m274_sbINI0	 BUFFER[3178]	//(internal1_m274_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m274_sbINI0	 1129	//(internal1_m274_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m274_sbVuIS0	 BUFFER[3180]	//(internal1_m274_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m274_sbVuIS0	 1130	//(internal1_m274_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m274_sb2UR0	 BUFFER[3182]	//(internal1_m274_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m274_sb2UR0	 1131	//(internal1_m274_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m274_sbNupIS0	 BUFFER[3184]	//(internal1_m274_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m274_sbNupIS0	 1132	//(internal1_m274_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m274_sbVuRB0	 BUFFER[3186]	//(internal1_m274_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m274_sbVuRB0	 1133	//(internal1_m274_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m274_MyFirstEnterFlag	 BUFFER[3188]	//(internal1_m274_MyFirstEnterFlag)  
#define idinternal1_m274_MyFirstEnterFlag	 1134	//(internal1_m274_MyFirstEnterFlag)  
#define internal1_m1410_q0	 BUFFER[3190]	//(internal1_m1410_q0) q0 - внутренний параметр
#define idinternal1_m1410_q0	 1135	//(internal1_m1410_q0) q0 - внутренний параметр
#define internal1_m1411_Step	 BUFFER[3192]	//(internal1_m1411_Step)  - текущий шаг программы
#define idinternal1_m1411_Step	 1136	//(internal1_m1411_Step)  - текущий шаг программы
#define internal1_m1411_rz	 BUFFER[3195]	//(internal1_m1411_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m1411_rz	 1137	//(internal1_m1411_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m1411_TimS	 BUFFER[3201]	//(internal1_m1411_TimS) Время от старта программы
#define idinternal1_m1411_TimS	 1138	//(internal1_m1411_TimS) Время от старта программы
#define internal1_m1411_FinPr0	 BUFFER[3206]	//(internal1_m1411_FinPr0) FinPr - конец программы
#define idinternal1_m1411_FinPr0	 1139	//(internal1_m1411_FinPr0) FinPr - конец программы
#define internal1_m1411_ErrPr0	 BUFFER[3208]	//(internal1_m1411_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m1411_ErrPr0	 1140	//(internal1_m1411_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m1411_sbINI0	 BUFFER[3210]	//(internal1_m1411_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m1411_sbINI0	 1141	//(internal1_m1411_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m1411_sbVuIS0	 BUFFER[3212]	//(internal1_m1411_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m1411_sbVuIS0	 1142	//(internal1_m1411_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m1411_sb2UR0	 BUFFER[3214]	//(internal1_m1411_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m1411_sb2UR0	 1143	//(internal1_m1411_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m1411_sbNupIS0	 BUFFER[3216]	//(internal1_m1411_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m1411_sbNupIS0	 1144	//(internal1_m1411_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m1411_sbVuRB0	 BUFFER[3218]	//(internal1_m1411_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m1411_sbVuRB0	 1145	//(internal1_m1411_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m1411_MyFirstEnterFlag	 BUFFER[3220]	//(internal1_m1411_MyFirstEnterFlag)  
#define idinternal1_m1411_MyFirstEnterFlag	 1146	//(internal1_m1411_MyFirstEnterFlag)  
#define internal1_m1021_q0	 BUFFER[3222]	//(internal1_m1021_q0) q0 - внутренний параметр
#define idinternal1_m1021_q0	 1147	//(internal1_m1021_q0) q0 - внутренний параметр
#define internal1_m1018_q0	 BUFFER[3224]	//(internal1_m1018_q0) q0 - внутренний параметр
#define idinternal1_m1018_q0	 1148	//(internal1_m1018_q0) q0 - внутренний параметр
#define internal1_m1020_q0	 BUFFER[3226]	//(internal1_m1020_q0) q0 - внутренний параметр
#define idinternal1_m1020_q0	 1149	//(internal1_m1020_q0) q0 - внутренний параметр
#define internal1_m1015_q0	 BUFFER[3228]	//(internal1_m1015_q0) q0 - внутренний параметр
#define idinternal1_m1015_q0	 1150	//(internal1_m1015_q0) q0 - внутренний параметр
#define internal1_m748_q0	 BUFFER[3230]	//(internal1_m748_q0) q0 - внутренний параметр
#define idinternal1_m748_q0	 1151	//(internal1_m748_q0) q0 - внутренний параметр
#define internal1_m341_q0	 BUFFER[3232]	//(internal1_m341_q0) q0 - внутренний параметр
#define idinternal1_m341_q0	 1152	//(internal1_m341_q0) q0 - внутренний параметр
#define internal1_m337_q0	 BUFFER[3234]	//(internal1_m337_q0) q0 - внутренний параметр
#define idinternal1_m337_q0	 1153	//(internal1_m337_q0) q0 - внутренний параметр
#define internal1_m294_q0	 BUFFER[3236]	//(internal1_m294_q0) q0 - внутренний параметр
#define idinternal1_m294_q0	 1154	//(internal1_m294_q0) q0 - внутренний параметр
#define internal1_m293_x0	 BUFFER[3238]	//(internal1_m293_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m293_x0	 1155	//(internal1_m293_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1881_q0	 BUFFER[3243]	//(internal1_m1881_q0) q0 - внутренний параметр
#define idinternal1_m1881_q0	 1156	//(internal1_m1881_q0) q0 - внутренний параметр
#define internal1_m1869_q0	 BUFFER[3245]	//(internal1_m1869_q0) q0 - внутренний параметр
#define idinternal1_m1869_q0	 1157	//(internal1_m1869_q0) q0 - внутренний параметр
#define internal1_m1860_q0	 BUFFER[3247]	//(internal1_m1860_q0) q0 - внутренний параметр
#define idinternal1_m1860_q0	 1158	//(internal1_m1860_q0) q0 - внутренний параметр
#define internal1_m1935_q0	 BUFFER[3249]	//(internal1_m1935_q0) q0 - внутренний параметр
#define idinternal1_m1935_q0	 1159	//(internal1_m1935_q0) q0 - внутренний параметр
#define internal1_m1906_q0	 BUFFER[3251]	//(internal1_m1906_q0) q0 - внутренний параметр
#define idinternal1_m1906_q0	 1160	//(internal1_m1906_q0) q0 - внутренний параметр
#define internal1_m1895_q0	 BUFFER[3253]	//(internal1_m1895_q0) q0 - внутренний параметр
#define idinternal1_m1895_q0	 1161	//(internal1_m1895_q0) q0 - внутренний параметр
#define internal1_m1463_q0	 BUFFER[3255]	//(internal1_m1463_q0) q0 - внутренний параметр
#define idinternal1_m1463_q0	 1162	//(internal1_m1463_q0) q0 - внутренний параметр
#define internal1_m1450_x0	 BUFFER[3257]	//(internal1_m1450_x0) был приход сигнала x1
#define idinternal1_m1450_x0	 1163	//(internal1_m1450_x0) был приход сигнала x1
#define internal1_m1450_y0	 BUFFER[3259]	//(internal1_m1450_y0) интервал между сигналами х1 и х2
#define idinternal1_m1450_y0	 1164	//(internal1_m1450_y0) интервал между сигналами х1 и х2
#define internal1_m1446_q0	 BUFFER[3264]	//(internal1_m1446_q0) q0 - внутренний параметр
#define idinternal1_m1446_q0	 1165	//(internal1_m1446_q0) q0 - внутренний параметр
#define internal1_m1437_q0	 BUFFER[3266]	//(internal1_m1437_q0) q0 - внутренний параметр
#define idinternal1_m1437_q0	 1166	//(internal1_m1437_q0) q0 - внутренний параметр
#define internal1_m1496_q0	 BUFFER[3268]	//(internal1_m1496_q0) q0 - внутренний параметр
#define idinternal1_m1496_q0	 1167	//(internal1_m1496_q0) q0 - внутренний параметр
#define internal1_m1516_q0	 BUFFER[3270]	//(internal1_m1516_q0) q0 - внутренний параметр
#define idinternal1_m1516_q0	 1168	//(internal1_m1516_q0) q0 - внутренний параметр
#define internal1_m1482_q0	 BUFFER[3272]	//(internal1_m1482_q0) q0 - внутренний параметр
#define idinternal1_m1482_q0	 1169	//(internal1_m1482_q0) q0 - внутренний параметр
#define internal1_m1497_x0	 BUFFER[3274]	//(internal1_m1497_x0) был приход сигнала x1
#define idinternal1_m1497_x0	 1170	//(internal1_m1497_x0) был приход сигнала x1
#define internal1_m1497_y0	 BUFFER[3276]	//(internal1_m1497_y0) интервал между сигналами х1 и х2
#define idinternal1_m1497_y0	 1171	//(internal1_m1497_y0) интервал между сигналами х1 и х2
#define internal1_m1421_x0	 BUFFER[3281]	//(internal1_m1421_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1421_x0	 1172	//(internal1_m1421_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1502_q0	 BUFFER[3286]	//(internal1_m1502_q0) q0 - внутренний параметр
#define idinternal1_m1502_q0	 1173	//(internal1_m1502_q0) q0 - внутренний параметр
#define internal1_m29_q0	 BUFFER[3288]	//(internal1_m29_q0) q0 - внутренний параметр
#define idinternal1_m29_q0	 1174	//(internal1_m29_q0) q0 - внутренний параметр
#define internal1_m1517_q0	 BUFFER[3290]	//(internal1_m1517_q0) q0 - внутренний параметр
#define idinternal1_m1517_q0	 1175	//(internal1_m1517_q0) q0 - внутренний параметр
#define internal1_m638_q0	 BUFFER[3292]	//(internal1_m638_q0) q0 - внутренний параметр
#define idinternal1_m638_q0	 1176	//(internal1_m638_q0) q0 - внутренний параметр
#define internal1_m623_q0	 BUFFER[3294]	//(internal1_m623_q0) q0 - внутренний параметр
#define idinternal1_m623_q0	 1177	//(internal1_m623_q0) q0 - внутренний параметр
#define internal1_m651_q0	 BUFFER[3296]	//(internal1_m651_q0) q0 - внутренний параметр
#define idinternal1_m651_q0	 1178	//(internal1_m651_q0) q0 - внутренний параметр
#define internal1_m634_q0	 BUFFER[3298]	//(internal1_m634_q0) q0 - внутренний параметр
#define idinternal1_m634_q0	 1179	//(internal1_m634_q0) q0 - внутренний параметр
#define internal1_m618_q0	 BUFFER[3300]	//(internal1_m618_q0) q0 - внутренний параметр
#define idinternal1_m618_q0	 1180	//(internal1_m618_q0) q0 - внутренний параметр
#define internal1_m616_q0	 BUFFER[3302]	//(internal1_m616_q0) q0 - внутренний параметр
#define idinternal1_m616_q0	 1181	//(internal1_m616_q0) q0 - внутренний параметр
#define internal1_m604_q0	 BUFFER[3304]	//(internal1_m604_q0) q0 - внутренний параметр
#define idinternal1_m604_q0	 1182	//(internal1_m604_q0) q0 - внутренний параметр
#define internal1_m1413_q0	 BUFFER[3306]	//(internal1_m1413_q0) q0 - внутренний параметр
#define idinternal1_m1413_q0	 1183	//(internal1_m1413_q0) q0 - внутренний параметр
#define internal1_m614_q0	 BUFFER[3311]	//(internal1_m614_q0) q0 - внутренний параметр
#define idinternal1_m614_q0	 1184	//(internal1_m614_q0) q0 - внутренний параметр
#define internal1_m115_q0	 BUFFER[3313]	//(internal1_m115_q0) q0 - внутренний параметр
#define idinternal1_m115_q0	 1185	//(internal1_m115_q0) q0 - внутренний параметр
#define internal1_m1649_q0	 BUFFER[3315]	//(internal1_m1649_q0) q0 - внутренний параметр
#define idinternal1_m1649_q0	 1186	//(internal1_m1649_q0) q0 - внутренний параметр
#define internal1_m1648_q0	 BUFFER[3317]	//(internal1_m1648_q0) q0 - внутренний параметр
#define idinternal1_m1648_q0	 1187	//(internal1_m1648_q0) q0 - внутренний параметр
#define internal1_m1647_q0	 BUFFER[3319]	//(internal1_m1647_q0) q0 - внутренний параметр
#define idinternal1_m1647_q0	 1188	//(internal1_m1647_q0) q0 - внутренний параметр
#define internal1_m1646_q0	 BUFFER[3321]	//(internal1_m1646_q0) q0 - внутренний параметр
#define idinternal1_m1646_q0	 1189	//(internal1_m1646_q0) q0 - внутренний параметр
#define internal1_m1684_q0	 BUFFER[3323]	//(internal1_m1684_q0) q0 - внутренний параметр
#define idinternal1_m1684_q0	 1190	//(internal1_m1684_q0) q0 - внутренний параметр
#define internal1_m1683_q0	 BUFFER[3325]	//(internal1_m1683_q0) q0 - внутренний параметр
#define idinternal1_m1683_q0	 1191	//(internal1_m1683_q0) q0 - внутренний параметр
#define internal1_m1682_q0	 BUFFER[3327]	//(internal1_m1682_q0) q0 - внутренний параметр
#define idinternal1_m1682_q0	 1192	//(internal1_m1682_q0) q0 - внутренний параметр
#define internal1_m1966_q0	 BUFFER[3329]	//(internal1_m1966_q0) q0 - внутренний параметр
#define idinternal1_m1966_q0	 1193	//(internal1_m1966_q0) q0 - внутренний параметр
#define internal1_m1744_q0	 BUFFER[3331]	//(internal1_m1744_q0) q0 - внутренний параметр
#define idinternal1_m1744_q0	 1194	//(internal1_m1744_q0) q0 - внутренний параметр
#define internal1_m1733_q0	 BUFFER[3333]	//(internal1_m1733_q0) q0 - внутренний параметр
#define idinternal1_m1733_q0	 1195	//(internal1_m1733_q0) q0 - внутренний параметр
#define internal1_m1741_q0	 BUFFER[3335]	//(internal1_m1741_q0) q0 - внутренний параметр
#define idinternal1_m1741_q0	 1196	//(internal1_m1741_q0) q0 - внутренний параметр
#define internal1_m1730_q0	 BUFFER[3337]	//(internal1_m1730_q0) q0 - внутренний параметр
#define idinternal1_m1730_q0	 1197	//(internal1_m1730_q0) q0 - внутренний параметр
#define internal1_m1738_q0	 BUFFER[3339]	//(internal1_m1738_q0) q0 - внутренний параметр
#define idinternal1_m1738_q0	 1198	//(internal1_m1738_q0) q0 - внутренний параметр
#define internal1_m2166_q0	 BUFFER[3341]	//(internal1_m2166_q0) q0 - внутренний параметр
#define idinternal1_m2166_q0	 1199	//(internal1_m2166_q0) q0 - внутренний параметр
#define internal1_m2162_q0	 BUFFER[3343]	//(internal1_m2162_q0) q0 - внутренний параметр
#define idinternal1_m2162_q0	 1200	//(internal1_m2162_q0) q0 - внутренний параметр
#define internal1_m1709_q0	 BUFFER[3345]	//(internal1_m1709_q0) q0 - внутренний параметр
#define idinternal1_m1709_q0	 1201	//(internal1_m1709_q0) q0 - внутренний параметр
#define internal1_m1701_q0	 BUFFER[3347]	//(internal1_m1701_q0) q0 - внутренний параметр
#define idinternal1_m1701_q0	 1202	//(internal1_m1701_q0) q0 - внутренний параметр
#define internal1_m1699_q0	 BUFFER[3349]	//(internal1_m1699_q0) q0 - внутренний параметр
#define idinternal1_m1699_q0	 1203	//(internal1_m1699_q0) q0 - внутренний параметр
#define internal1_m1695_q0	 BUFFER[3351]	//(internal1_m1695_q0) q0 - внутренний параметр
#define idinternal1_m1695_q0	 1204	//(internal1_m1695_q0) q0 - внутренний параметр
#define internal1_m1691_q0	 BUFFER[3353]	//(internal1_m1691_q0) q0 - внутренний параметр
#define idinternal1_m1691_q0	 1205	//(internal1_m1691_q0) q0 - внутренний параметр
#define internal1_m1693_q0	 BUFFER[3355]	//(internal1_m1693_q0) q0 - внутренний параметр
#define idinternal1_m1693_q0	 1206	//(internal1_m1693_q0) q0 - внутренний параметр
#define internal1_m22_q0	 BUFFER[3357]	//(internal1_m22_q0) q0 - внутренний параметр
#define idinternal1_m22_q0	 1207	//(internal1_m22_q0) q0 - внутренний параметр
#define internal1_m1672_q0	 BUFFER[3359]	//(internal1_m1672_q0) q0 - внутренний параметр
#define idinternal1_m1672_q0	 1208	//(internal1_m1672_q0) q0 - внутренний параметр
#define internal1_m1670_q0	 BUFFER[3361]	//(internal1_m1670_q0) q0 - внутренний параметр
#define idinternal1_m1670_q0	 1209	//(internal1_m1670_q0) q0 - внутренний параметр
#define internal1_m1666_q0	 BUFFER[3363]	//(internal1_m1666_q0) q0 - внутренний параметр
#define idinternal1_m1666_q0	 1210	//(internal1_m1666_q0) q0 - внутренний параметр
#define internal1_m1668_q0	 BUFFER[3365]	//(internal1_m1668_q0) q0 - внутренний параметр
#define idinternal1_m1668_q0	 1211	//(internal1_m1668_q0) q0 - внутренний параметр
#define internal1_m1664_q0	 BUFFER[3367]	//(internal1_m1664_q0) q0 - внутренний параметр
#define idinternal1_m1664_q0	 1212	//(internal1_m1664_q0) q0 - внутренний параметр
#define internal1_m1662_q0	 BUFFER[3369]	//(internal1_m1662_q0) q0 - внутренний параметр
#define idinternal1_m1662_q0	 1213	//(internal1_m1662_q0) q0 - внутренний параметр
#define internal1_m2082_q0	 BUFFER[3371]	//(internal1_m2082_q0) q0 - внутренний параметр
#define idinternal1_m2082_q0	 1214	//(internal1_m2082_q0) q0 - внутренний параметр
#define internal1_m2077_q0	 BUFFER[3373]	//(internal1_m2077_q0) q0 - внутренний параметр
#define idinternal1_m2077_q0	 1215	//(internal1_m2077_q0) q0 - внутренний параметр
#define internal1_m2056_q0	 BUFFER[3375]	//(internal1_m2056_q0) q0 - внутренний параметр
#define idinternal1_m2056_q0	 1216	//(internal1_m2056_q0) q0 - внутренний параметр
#define internal1_m2044_q0	 BUFFER[3377]	//(internal1_m2044_q0) q0 - внутренний параметр
#define idinternal1_m2044_q0	 1217	//(internal1_m2044_q0) q0 - внутренний параметр
#define internal1_m1977_q0	 BUFFER[3379]	//(internal1_m1977_q0) q0 - внутренний параметр
#define idinternal1_m1977_q0	 1218	//(internal1_m1977_q0) q0 - внутренний параметр
#define internal1_m1658_q0	 BUFFER[3381]	//(internal1_m1658_q0) q0 - внутренний параметр
#define idinternal1_m1658_q0	 1219	//(internal1_m1658_q0) q0 - внутренний параметр
#define internal1_m1660_q0	 BUFFER[3383]	//(internal1_m1660_q0) q0 - внутренний параметр
#define idinternal1_m1660_q0	 1220	//(internal1_m1660_q0) q0 - внутренний параметр
#define internal1_m1644_q0	 BUFFER[3385]	//(internal1_m1644_q0) q0 - внутренний параметр
#define idinternal1_m1644_q0	 1221	//(internal1_m1644_q0) q0 - внутренний параметр
#define internal1_m1642_q0	 BUFFER[3387]	//(internal1_m1642_q0) q0 - внутренний параметр
#define idinternal1_m1642_q0	 1222	//(internal1_m1642_q0) q0 - внутренний параметр
#define internal1_m1640_q0	 BUFFER[3389]	//(internal1_m1640_q0) q0 - внутренний параметр
#define idinternal1_m1640_q0	 1223	//(internal1_m1640_q0) q0 - внутренний параметр
#define internal1_m1638_q0	 BUFFER[3391]	//(internal1_m1638_q0) q0 - внутренний параметр
#define idinternal1_m1638_q0	 1224	//(internal1_m1638_q0) q0 - внутренний параметр
#define internal1_m1637_q0	 BUFFER[3393]	//(internal1_m1637_q0) q0 - внутренний параметр
#define idinternal1_m1637_q0	 1225	//(internal1_m1637_q0) q0 - внутренний параметр
#define internal1_m1635_q0	 BUFFER[3395]	//(internal1_m1635_q0) q0 - внутренний параметр
#define idinternal1_m1635_q0	 1226	//(internal1_m1635_q0) q0 - внутренний параметр
#define internal1_m1634_q0	 BUFFER[3397]	//(internal1_m1634_q0) q0 - внутренний параметр
#define idinternal1_m1634_q0	 1227	//(internal1_m1634_q0) q0 - внутренний параметр
#define internal1_m1632_q0	 BUFFER[3399]	//(internal1_m1632_q0) q0 - внутренний параметр
#define idinternal1_m1632_q0	 1228	//(internal1_m1632_q0) q0 - внутренний параметр
#define internal1_m2105_DvUp0	 BUFFER[3401]	//(internal1_m2105_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2105_DvUp0	 1229	//(internal1_m2105_DvUp0) - есть команда на движение вперёд
#define internal1_m2105_DvDw0	 BUFFER[3402]	//(internal1_m2105_DvDw0) - есть команда на движение назад
#define idinternal1_m2105_DvDw0	 1230	//(internal1_m2105_DvDw0) - есть команда на движение назад
#define internal1_m2105_FDvUp0	 BUFFER[3403]	//(internal1_m2105_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2105_FDvUp0	 1231	//(internal1_m2105_FDvUp0) - есть команда на движение вперёд
#define internal1_m2105_FDvDw0	 BUFFER[3404]	//(internal1_m2105_FDvDw0) - есть команда на движение назад
#define idinternal1_m2105_FDvDw0	 1232	//(internal1_m2105_FDvDw0) - есть команда на движение назад
#define internal1_m2105_BlDv0	 BUFFER[3405]	//(internal1_m2105_BlDv0) - была блокировка
#define idinternal1_m2105_BlDv0	 1233	//(internal1_m2105_BlDv0) - была блокировка
#define internal1_m2105_Pkv0	 BUFFER[3406]	//(internal1_m2105_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2105_Pkv0	 1234	//(internal1_m2105_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2105_Pkav0	 BUFFER[3407]	//(internal1_m2105_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2105_Pkav0	 1235	//(internal1_m2105_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2105_Zkv0	 BUFFER[3408]	//(internal1_m2105_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2105_Zkv0	 1236	//(internal1_m2105_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2105_Zkav0	 BUFFER[3409]	//(internal1_m2105_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2105_Zkav0	 1237	//(internal1_m2105_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2105_txNm	 BUFFER[3410]	//(internal1_m2105_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2105_txNm	 1238	//(internal1_m2105_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2105_txSm	 BUFFER[3415]	//(internal1_m2105_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2105_txSm	 1239	//(internal1_m2105_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2105_txHr	 BUFFER[3420]	//(internal1_m2105_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2105_txHr	 1240	//(internal1_m2105_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2105_txLd	 BUFFER[3425]	//(internal1_m2105_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2105_txLd	 1241	//(internal1_m2105_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2105_fef	 BUFFER[3430]	//(internal1_m2105_fef) fef
#define idinternal1_m2105_fef	 1242	//(internal1_m2105_fef) fef
#define internal1_m2099_DvUp0	 BUFFER[3431]	//(internal1_m2099_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2099_DvUp0	 1243	//(internal1_m2099_DvUp0) - есть команда на движение вперёд
#define internal1_m2099_DvDw0	 BUFFER[3432]	//(internal1_m2099_DvDw0) - есть команда на движение назад
#define idinternal1_m2099_DvDw0	 1244	//(internal1_m2099_DvDw0) - есть команда на движение назад
#define internal1_m2099_FDvUp0	 BUFFER[3433]	//(internal1_m2099_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2099_FDvUp0	 1245	//(internal1_m2099_FDvUp0) - есть команда на движение вперёд
#define internal1_m2099_FDvDw0	 BUFFER[3434]	//(internal1_m2099_FDvDw0) - есть команда на движение назад
#define idinternal1_m2099_FDvDw0	 1246	//(internal1_m2099_FDvDw0) - есть команда на движение назад
#define internal1_m2099_BlDv0	 BUFFER[3435]	//(internal1_m2099_BlDv0) - была блокировка
#define idinternal1_m2099_BlDv0	 1247	//(internal1_m2099_BlDv0) - была блокировка
#define internal1_m2099_Pkv0	 BUFFER[3436]	//(internal1_m2099_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2099_Pkv0	 1248	//(internal1_m2099_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2099_Pkav0	 BUFFER[3437]	//(internal1_m2099_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2099_Pkav0	 1249	//(internal1_m2099_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2099_Zkv0	 BUFFER[3438]	//(internal1_m2099_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2099_Zkv0	 1250	//(internal1_m2099_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2099_Zkav0	 BUFFER[3439]	//(internal1_m2099_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2099_Zkav0	 1251	//(internal1_m2099_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2099_txNm	 BUFFER[3440]	//(internal1_m2099_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2099_txNm	 1252	//(internal1_m2099_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2099_txSm	 BUFFER[3445]	//(internal1_m2099_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2099_txSm	 1253	//(internal1_m2099_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2099_txHr	 BUFFER[3450]	//(internal1_m2099_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2099_txHr	 1254	//(internal1_m2099_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2099_txLd	 BUFFER[3455]	//(internal1_m2099_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2099_txLd	 1255	//(internal1_m2099_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2099_fef	 BUFFER[3460]	//(internal1_m2099_fef) fef
#define idinternal1_m2099_fef	 1256	//(internal1_m2099_fef) fef
#define internal1_m1487_q0	 BUFFER[3461]	//(internal1_m1487_q0) q0 - внутренний параметр
#define idinternal1_m1487_q0	 1257	//(internal1_m1487_q0) q0 - внутренний параметр
#define internal1_m1491_x0	 BUFFER[3463]	//(internal1_m1491_x0) был приход сигнала x1
#define idinternal1_m1491_x0	 1258	//(internal1_m1491_x0) был приход сигнала x1
#define internal1_m1491_y0	 BUFFER[3465]	//(internal1_m1491_y0) интервал между сигналами х1 и х2
#define idinternal1_m1491_y0	 1259	//(internal1_m1491_y0) интервал между сигналами х1 и х2
#define internal1_m1917_x0	 BUFFER[3470]	//(internal1_m1917_x0) был приход сигнала x1
#define idinternal1_m1917_x0	 1260	//(internal1_m1917_x0) был приход сигнала x1
#define internal1_m1917_y0	 BUFFER[3472]	//(internal1_m1917_y0) интервал между сигналами х1 и х2
#define idinternal1_m1917_y0	 1261	//(internal1_m1917_y0) интервал между сигналами х1 и х2
#define internal1_m1878_x0	 BUFFER[3477]	//(internal1_m1878_x0) был приход сигнала x1
#define idinternal1_m1878_x0	 1262	//(internal1_m1878_x0) был приход сигнала x1
#define internal1_m1878_y0	 BUFFER[3479]	//(internal1_m1878_y0) интервал между сигналами х1 и х2
#define idinternal1_m1878_y0	 1263	//(internal1_m1878_y0) интервал между сигналами х1 и х2
#define internal1_m285_q0	 BUFFER[3484]	//(internal1_m285_q0) q0 - внутренний параметр
#define idinternal1_m285_q0	 1264	//(internal1_m285_q0) q0 - внутренний параметр
#define internal1_m995_q0	 BUFFER[3486]	//(internal1_m995_q0) q0 - внутренний параметр
#define idinternal1_m995_q0	 1265	//(internal1_m995_q0) q0 - внутренний параметр
#define internal1_m626_q0	 BUFFER[3488]	//(internal1_m626_q0) q0 - внутренний параметр
#define idinternal1_m626_q0	 1266	//(internal1_m626_q0) q0 - внутренний параметр
#define internal1_m1310_X0	 BUFFER[3490]	//(internal1_m1310_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1310_X0	 1267	//(internal1_m1310_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1310_t0	 BUFFER[3495]	//(internal1_m1310_t0) время нахождения в зоне возврата
#define idinternal1_m1310_t0	 1268	//(internal1_m1310_t0) время нахождения в зоне возврата
#define internal1_m1310_BLDv0	 BUFFER[3500]	//(internal1_m1310_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1310_BLDv0	 1269	//(internal1_m1310_BLDv0) BlDv - Блокировка движения
#define internal1_m1329_tx	 BUFFER[3501]	//(internal1_m1329_tx) tx - время накопленное сек
#define idinternal1_m1329_tx	 1270	//(internal1_m1329_tx) tx - время накопленное сек
#define internal1_m1329_y0	 BUFFER[3506]	//(internal1_m1329_y0) y0
#define idinternal1_m1329_y0	 1271	//(internal1_m1329_y0) y0
#define internal1_m1331_tx	 BUFFER[3507]	//(internal1_m1331_tx) tx - время накопленное сек
#define idinternal1_m1331_tx	 1272	//(internal1_m1331_tx) tx - время накопленное сек
#define internal1_m1331_y0	 BUFFER[3512]	//(internal1_m1331_y0) y0
#define idinternal1_m1331_y0	 1273	//(internal1_m1331_y0) y0
#define internal1_m1338_xptr	 BUFFER[3513]	//(internal1_m1338_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1338_xptr	 1274	//(internal1_m1338_xptr) указатель текущей позиции в массиве координат
#define internal1_m1338_x0	 BUFFER[3516]	//(internal1_m1338_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1338_x0	 1275	//(internal1_m1338_x0) x0 - массив мгновенных значений координат
#define internal1_m1338_tim0	 BUFFER[3816]	//(internal1_m1338_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1338_tim0	 1276	//(internal1_m1338_tim0) tim0 - массив значений времени цикла
#define internal1_m1338_sumtim	 BUFFER[4116]	//(internal1_m1338_sumtim) sumtim - время в пути
#define idinternal1_m1338_sumtim	 1277	//(internal1_m1338_sumtim) sumtim - время в пути
#define internal1_m1338_StSpeed	 BUFFER[4121]	//(internal1_m1338_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1338_StSpeed	 1278	//(internal1_m1338_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1338_Vz0	 BUFFER[4126]	//(internal1_m1338_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1338_Vz0	 1279	//(internal1_m1338_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1338_flRazg	 BUFFER[4131]	//(internal1_m1338_flRazg) признак разгона/торможения
#define idinternal1_m1338_flRazg	 1280	//(internal1_m1338_flRazg) признак разгона/торможения
#define internal1_m1338_DelSp	 BUFFER[4134]	//(internal1_m1338_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1338_DelSp	 1281	//(internal1_m1338_DelSp) DelSp - время переключения скоростей
#define internal1_m1338_z0	 BUFFER[4139]	//(internal1_m1338_z0) z0 - точка прекращения движения
#define idinternal1_m1338_z0	 1282	//(internal1_m1338_z0) z0 - точка прекращения движения
#define internal1_m1338_txZS	 BUFFER[4144]	//(internal1_m1338_txZS) txZS
#define idinternal1_m1338_txZS	 1283	//(internal1_m1338_txZS) txZS
#define internal1_m1338_tx	 BUFFER[4149]	//(internal1_m1338_tx) tx
#define idinternal1_m1338_tx	 1284	//(internal1_m1338_tx) tx
#define internal1_m1338_txd	 BUFFER[4154]	//(internal1_m1338_txd) txd
#define idinternal1_m1338_txd	 1285	//(internal1_m1338_txd) txd
#define internal1_m1338_txMBl	 BUFFER[4159]	//(internal1_m1338_txMBl) tx
#define idinternal1_m1338_txMBl	 1286	//(internal1_m1338_txMBl) tx
#define internal1_m1338_txBl	 BUFFER[4164]	//(internal1_m1338_txBl) tx
#define idinternal1_m1338_txBl	 1287	//(internal1_m1338_txBl) tx
#define internal1_m1338_Speed0	 BUFFER[4169]	//(internal1_m1338_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1338_Speed0	 1288	//(internal1_m1338_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1338_xz0	 BUFFER[4174]	//(internal1_m1338_xz0) xz0 - новое задание мм
#define idinternal1_m1338_xz0	 1289	//(internal1_m1338_xz0) xz0 - новое задание мм
#define internal1_m1338_tz0	 BUFFER[4179]	//(internal1_m1338_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1338_tz0	 1290	//(internal1_m1338_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1338_Shift0	 BUFFER[4184]	//(internal1_m1338_Shift0) Shift0 - признак самохода
#define idinternal1_m1338_Shift0	 1291	//(internal1_m1338_Shift0) Shift0 - признак самохода
#define internal1_m1338_ShCntlSp0	 BUFFER[4186]	//(internal1_m1338_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1338_ShCntlSp0	 1292	//(internal1_m1338_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1338_ShiftControl	 BUFFER[4188]	//(internal1_m1338_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1338_ShiftControl	 1293	//(internal1_m1338_ShiftControl) ShiftControl - признак самохода
#define internal1_m624_q0	 BUFFER[4190]	//(internal1_m624_q0) q0 - внутренний параметр
#define idinternal1_m624_q0	 1294	//(internal1_m624_q0) q0 - внутренний параметр
#define internal1_m893_X0	 BUFFER[4192]	//(internal1_m893_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m893_X0	 1295	//(internal1_m893_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m893_t0	 BUFFER[4197]	//(internal1_m893_t0) время нахождения в зоне возврата
#define idinternal1_m893_t0	 1296	//(internal1_m893_t0) время нахождения в зоне возврата
#define internal1_m893_BLDv0	 BUFFER[4202]	//(internal1_m893_BLDv0) BlDv - Блокировка движения
#define idinternal1_m893_BLDv0	 1297	//(internal1_m893_BLDv0) BlDv - Блокировка движения
#define internal1_m917_tx	 BUFFER[4203]	//(internal1_m917_tx) tx - время накопленное сек
#define idinternal1_m917_tx	 1298	//(internal1_m917_tx) tx - время накопленное сек
#define internal1_m917_y0	 BUFFER[4208]	//(internal1_m917_y0) y0
#define idinternal1_m917_y0	 1299	//(internal1_m917_y0) y0
#define internal1_m919_tx	 BUFFER[4209]	//(internal1_m919_tx) tx - время накопленное сек
#define idinternal1_m919_tx	 1300	//(internal1_m919_tx) tx - время накопленное сек
#define internal1_m919_y0	 BUFFER[4214]	//(internal1_m919_y0) y0
#define idinternal1_m919_y0	 1301	//(internal1_m919_y0) y0
#define internal1_m926_xptr	 BUFFER[4215]	//(internal1_m926_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m926_xptr	 1302	//(internal1_m926_xptr) указатель текущей позиции в массиве координат
#define internal1_m926_x0	 BUFFER[4218]	//(internal1_m926_x0) x0 - массив мгновенных значений координат
#define idinternal1_m926_x0	 1303	//(internal1_m926_x0) x0 - массив мгновенных значений координат
#define internal1_m926_tim0	 BUFFER[4518]	//(internal1_m926_tim0) tim0 - массив значений времени цикла
#define idinternal1_m926_tim0	 1304	//(internal1_m926_tim0) tim0 - массив значений времени цикла
#define internal1_m926_sumtim	 BUFFER[4818]	//(internal1_m926_sumtim) sumtim - время в пути
#define idinternal1_m926_sumtim	 1305	//(internal1_m926_sumtim) sumtim - время в пути
#define internal1_m926_StSpeed	 BUFFER[4823]	//(internal1_m926_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m926_StSpeed	 1306	//(internal1_m926_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m926_Vz0	 BUFFER[4828]	//(internal1_m926_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m926_Vz0	 1307	//(internal1_m926_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m926_flRazg	 BUFFER[4833]	//(internal1_m926_flRazg) признак разгона/торможения
#define idinternal1_m926_flRazg	 1308	//(internal1_m926_flRazg) признак разгона/торможения
#define internal1_m926_DelSp	 BUFFER[4836]	//(internal1_m926_DelSp) DelSp - время переключения скоростей
#define idinternal1_m926_DelSp	 1309	//(internal1_m926_DelSp) DelSp - время переключения скоростей
#define internal1_m926_z0	 BUFFER[4841]	//(internal1_m926_z0) z0 - точка прекращения движения
#define idinternal1_m926_z0	 1310	//(internal1_m926_z0) z0 - точка прекращения движения
#define internal1_m926_txZS	 BUFFER[4846]	//(internal1_m926_txZS) txZS
#define idinternal1_m926_txZS	 1311	//(internal1_m926_txZS) txZS
#define internal1_m926_tx	 BUFFER[4851]	//(internal1_m926_tx) tx
#define idinternal1_m926_tx	 1312	//(internal1_m926_tx) tx
#define internal1_m926_txd	 BUFFER[4856]	//(internal1_m926_txd) txd
#define idinternal1_m926_txd	 1313	//(internal1_m926_txd) txd
#define internal1_m926_txMBl	 BUFFER[4861]	//(internal1_m926_txMBl) tx
#define idinternal1_m926_txMBl	 1314	//(internal1_m926_txMBl) tx
#define internal1_m926_txBl	 BUFFER[4866]	//(internal1_m926_txBl) tx
#define idinternal1_m926_txBl	 1315	//(internal1_m926_txBl) tx
#define internal1_m926_Speed0	 BUFFER[4871]	//(internal1_m926_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m926_Speed0	 1316	//(internal1_m926_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m926_xz0	 BUFFER[4876]	//(internal1_m926_xz0) xz0 - новое задание мм
#define idinternal1_m926_xz0	 1317	//(internal1_m926_xz0) xz0 - новое задание мм
#define internal1_m926_tz0	 BUFFER[4881]	//(internal1_m926_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m926_tz0	 1318	//(internal1_m926_tz0) tz0 - время защиты от нового задания сек
#define internal1_m926_Shift0	 BUFFER[4886]	//(internal1_m926_Shift0) Shift0 - признак самохода
#define idinternal1_m926_Shift0	 1319	//(internal1_m926_Shift0) Shift0 - признак самохода
#define internal1_m926_ShCntlSp0	 BUFFER[4888]	//(internal1_m926_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m926_ShCntlSp0	 1320	//(internal1_m926_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m926_ShiftControl	 BUFFER[4890]	//(internal1_m926_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m926_ShiftControl	 1321	//(internal1_m926_ShiftControl) ShiftControl - признак самохода
#define internal1_m495_X0	 BUFFER[4892]	//(internal1_m495_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m495_X0	 1322	//(internal1_m495_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m495_t0	 BUFFER[4897]	//(internal1_m495_t0) время нахождения в зоне возврата
#define idinternal1_m495_t0	 1323	//(internal1_m495_t0) время нахождения в зоне возврата
#define internal1_m495_BLDv0	 BUFFER[4902]	//(internal1_m495_BLDv0) BlDv - Блокировка движения
#define idinternal1_m495_BLDv0	 1324	//(internal1_m495_BLDv0) BlDv - Блокировка движения
#define internal1_m515_tx	 BUFFER[4903]	//(internal1_m515_tx) tx - время накопленное сек
#define idinternal1_m515_tx	 1325	//(internal1_m515_tx) tx - время накопленное сек
#define internal1_m515_y0	 BUFFER[4908]	//(internal1_m515_y0) y0
#define idinternal1_m515_y0	 1326	//(internal1_m515_y0) y0
#define internal1_m518_tx	 BUFFER[4909]	//(internal1_m518_tx) tx - время накопленное сек
#define idinternal1_m518_tx	 1327	//(internal1_m518_tx) tx - время накопленное сек
#define internal1_m518_y0	 BUFFER[4914]	//(internal1_m518_y0) y0
#define idinternal1_m518_y0	 1328	//(internal1_m518_y0) y0
#define internal1_m522_xptr	 BUFFER[4915]	//(internal1_m522_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m522_xptr	 1329	//(internal1_m522_xptr) указатель текущей позиции в массиве координат
#define internal1_m522_x0	 BUFFER[4918]	//(internal1_m522_x0) x0 - массив мгновенных значений координат
#define idinternal1_m522_x0	 1330	//(internal1_m522_x0) x0 - массив мгновенных значений координат
#define internal1_m522_tim0	 BUFFER[5668]	//(internal1_m522_tim0) tim0 - массив значений времени цикла
#define idinternal1_m522_tim0	 1331	//(internal1_m522_tim0) tim0 - массив значений времени цикла
#define internal1_m522_sumtim	 BUFFER[6418]	//(internal1_m522_sumtim) sumtim - время в пути
#define idinternal1_m522_sumtim	 1332	//(internal1_m522_sumtim) sumtim - время в пути
#define internal1_m522_StSpeed	 BUFFER[6423]	//(internal1_m522_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m522_StSpeed	 1333	//(internal1_m522_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m522_Vz0	 BUFFER[6428]	//(internal1_m522_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m522_Vz0	 1334	//(internal1_m522_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m522_flRazg	 BUFFER[6433]	//(internal1_m522_flRazg) признак разгона/торможения
#define idinternal1_m522_flRazg	 1335	//(internal1_m522_flRazg) признак разгона/торможения
#define internal1_m522_DelSp	 BUFFER[6436]	//(internal1_m522_DelSp) DelSp - время переключения скоростей
#define idinternal1_m522_DelSp	 1336	//(internal1_m522_DelSp) DelSp - время переключения скоростей
#define internal1_m522_z0	 BUFFER[6441]	//(internal1_m522_z0) z0 - точка прекращения движения
#define idinternal1_m522_z0	 1337	//(internal1_m522_z0) z0 - точка прекращения движения
#define internal1_m522_txZS	 BUFFER[6446]	//(internal1_m522_txZS) txZS
#define idinternal1_m522_txZS	 1338	//(internal1_m522_txZS) txZS
#define internal1_m522_tx	 BUFFER[6451]	//(internal1_m522_tx) tx
#define idinternal1_m522_tx	 1339	//(internal1_m522_tx) tx
#define internal1_m522_txd	 BUFFER[6456]	//(internal1_m522_txd) txd
#define idinternal1_m522_txd	 1340	//(internal1_m522_txd) txd
#define internal1_m522_txMBl	 BUFFER[6461]	//(internal1_m522_txMBl) tx
#define idinternal1_m522_txMBl	 1341	//(internal1_m522_txMBl) tx
#define internal1_m522_txBl	 BUFFER[6466]	//(internal1_m522_txBl) tx
#define idinternal1_m522_txBl	 1342	//(internal1_m522_txBl) tx
#define internal1_m522_Speed0	 BUFFER[6471]	//(internal1_m522_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m522_Speed0	 1343	//(internal1_m522_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m522_xz0	 BUFFER[6476]	//(internal1_m522_xz0) xz0 - новое задание мм
#define idinternal1_m522_xz0	 1344	//(internal1_m522_xz0) xz0 - новое задание мм
#define internal1_m522_tz0	 BUFFER[6481]	//(internal1_m522_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m522_tz0	 1345	//(internal1_m522_tz0) tz0 - время защиты от нового задания сек
#define internal1_m522_Shift0	 BUFFER[6486]	//(internal1_m522_Shift0) Shift0 - признак самохода
#define idinternal1_m522_Shift0	 1346	//(internal1_m522_Shift0) Shift0 - признак самохода
#define internal1_m522_ShCntlSp0	 BUFFER[6488]	//(internal1_m522_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m522_ShCntlSp0	 1347	//(internal1_m522_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m522_ShiftControl	 BUFFER[6490]	//(internal1_m522_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m522_ShiftControl	 1348	//(internal1_m522_ShiftControl) ShiftControl - признак самохода
#define internal1_m621_q0	 BUFFER[6492]	//(internal1_m621_q0) q0 - внутренний параметр
#define idinternal1_m621_q0	 1349	//(internal1_m621_q0) q0 - внутренний параметр
#define internal1_m174_X0	 BUFFER[6494]	//(internal1_m174_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m174_X0	 1350	//(internal1_m174_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m174_t0	 BUFFER[6499]	//(internal1_m174_t0) время нахождения в зоне возврата
#define idinternal1_m174_t0	 1351	//(internal1_m174_t0) время нахождения в зоне возврата
#define internal1_m174_BLDv0	 BUFFER[6504]	//(internal1_m174_BLDv0) BlDv - Блокировка движения
#define idinternal1_m174_BLDv0	 1352	//(internal1_m174_BLDv0) BlDv - Блокировка движения
#define internal1_m203_xptr	 BUFFER[6505]	//(internal1_m203_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m203_xptr	 1353	//(internal1_m203_xptr) указатель текущей позиции в массиве координат
#define internal1_m203_x0	 BUFFER[6508]	//(internal1_m203_x0) x0 - массив мгновенных значений координат
#define idinternal1_m203_x0	 1354	//(internal1_m203_x0) x0 - массив мгновенных значений координат
#define internal1_m203_tim0	 BUFFER[7258]	//(internal1_m203_tim0) tim0 - массив значений времени цикла
#define idinternal1_m203_tim0	 1355	//(internal1_m203_tim0) tim0 - массив значений времени цикла
#define internal1_m203_sumtim	 BUFFER[8008]	//(internal1_m203_sumtim) sumtim - время в пути
#define idinternal1_m203_sumtim	 1356	//(internal1_m203_sumtim) sumtim - время в пути
#define internal1_m203_StSpeed	 BUFFER[8013]	//(internal1_m203_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m203_StSpeed	 1357	//(internal1_m203_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m203_Vz0	 BUFFER[8018]	//(internal1_m203_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m203_Vz0	 1358	//(internal1_m203_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m203_flRazg	 BUFFER[8023]	//(internal1_m203_flRazg) признак разгона/торможения
#define idinternal1_m203_flRazg	 1359	//(internal1_m203_flRazg) признак разгона/торможения
#define internal1_m203_DelSp	 BUFFER[8026]	//(internal1_m203_DelSp) DelSp - время переключения скоростей
#define idinternal1_m203_DelSp	 1360	//(internal1_m203_DelSp) DelSp - время переключения скоростей
#define internal1_m203_z0	 BUFFER[8031]	//(internal1_m203_z0) z0 - точка прекращения движения
#define idinternal1_m203_z0	 1361	//(internal1_m203_z0) z0 - точка прекращения движения
#define internal1_m203_txZS	 BUFFER[8036]	//(internal1_m203_txZS) txZS
#define idinternal1_m203_txZS	 1362	//(internal1_m203_txZS) txZS
#define internal1_m203_tx	 BUFFER[8041]	//(internal1_m203_tx) tx
#define idinternal1_m203_tx	 1363	//(internal1_m203_tx) tx
#define internal1_m203_txd	 BUFFER[8046]	//(internal1_m203_txd) txd
#define idinternal1_m203_txd	 1364	//(internal1_m203_txd) txd
#define internal1_m203_txMBl	 BUFFER[8051]	//(internal1_m203_txMBl) tx
#define idinternal1_m203_txMBl	 1365	//(internal1_m203_txMBl) tx
#define internal1_m203_txBl	 BUFFER[8056]	//(internal1_m203_txBl) tx
#define idinternal1_m203_txBl	 1366	//(internal1_m203_txBl) tx
#define internal1_m203_Speed0	 BUFFER[8061]	//(internal1_m203_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m203_Speed0	 1367	//(internal1_m203_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m203_xz0	 BUFFER[8066]	//(internal1_m203_xz0) xz0 - новое задание мм
#define idinternal1_m203_xz0	 1368	//(internal1_m203_xz0) xz0 - новое задание мм
#define internal1_m203_tz0	 BUFFER[8071]	//(internal1_m203_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m203_tz0	 1369	//(internal1_m203_tz0) tz0 - время защиты от нового задания сек
#define internal1_m203_Shift0	 BUFFER[8076]	//(internal1_m203_Shift0) Shift0 - признак самохода
#define idinternal1_m203_Shift0	 1370	//(internal1_m203_Shift0) Shift0 - признак самохода
#define internal1_m203_ShCntlSp0	 BUFFER[8078]	//(internal1_m203_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m203_ShCntlSp0	 1371	//(internal1_m203_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m203_ShiftControl	 BUFFER[8080]	//(internal1_m203_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m203_ShiftControl	 1372	//(internal1_m203_ShiftControl) ShiftControl - признак самохода
#define internal1_m647_q0	 BUFFER[8082]	//(internal1_m647_q0) q0 - внутренний параметр
#define idinternal1_m647_q0	 1373	//(internal1_m647_q0) q0 - внутренний параметр
#define internal1_m466_DvUp0	 BUFFER[8084]	//(internal1_m466_DvUp0) - есть команда на движение вперёд
#define idinternal1_m466_DvUp0	 1374	//(internal1_m466_DvUp0) - есть команда на движение вперёд
#define internal1_m466_DvDw0	 BUFFER[8085]	//(internal1_m466_DvDw0) - есть команда на движение назад
#define idinternal1_m466_DvDw0	 1375	//(internal1_m466_DvDw0) - есть команда на движение назад
#define internal1_m466_FDvUp0	 BUFFER[8086]	//(internal1_m466_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m466_FDvUp0	 1376	//(internal1_m466_FDvUp0) - есть команда на движение вперёд
#define internal1_m466_FDvDw0	 BUFFER[8087]	//(internal1_m466_FDvDw0) - есть команда на движение назад
#define idinternal1_m466_FDvDw0	 1377	//(internal1_m466_FDvDw0) - есть команда на движение назад
#define internal1_m466_BlDv0	 BUFFER[8088]	//(internal1_m466_BlDv0) - была блокировка
#define idinternal1_m466_BlDv0	 1378	//(internal1_m466_BlDv0) - была блокировка
#define internal1_m466_Pkv0	 BUFFER[8089]	//(internal1_m466_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m466_Pkv0	 1379	//(internal1_m466_Pkv0) Pkv - передний конечный выключатель
#define internal1_m466_Pkav0	 BUFFER[8090]	//(internal1_m466_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m466_Pkav0	 1380	//(internal1_m466_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m466_Zkv0	 BUFFER[8091]	//(internal1_m466_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m466_Zkv0	 1381	//(internal1_m466_Zkv0) Zkv - задний конечный выключатель
#define internal1_m466_Zkav0	 BUFFER[8092]	//(internal1_m466_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m466_Zkav0	 1382	//(internal1_m466_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m466_txNm	 BUFFER[8093]	//(internal1_m466_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m466_txNm	 1383	//(internal1_m466_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m466_txSm	 BUFFER[8098]	//(internal1_m466_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m466_txSm	 1384	//(internal1_m466_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m466_txHr	 BUFFER[8103]	//(internal1_m466_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m466_txHr	 1385	//(internal1_m466_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m466_txLd	 BUFFER[8108]	//(internal1_m466_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m466_txLd	 1386	//(internal1_m466_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m466_fef	 BUFFER[8113]	//(internal1_m466_fef) fef
#define idinternal1_m466_fef	 1387	//(internal1_m466_fef) fef
#define internal1_m460_DvUp0	 BUFFER[8114]	//(internal1_m460_DvUp0) - есть команда на движение вперёд
#define idinternal1_m460_DvUp0	 1388	//(internal1_m460_DvUp0) - есть команда на движение вперёд
#define internal1_m460_DvDw0	 BUFFER[8115]	//(internal1_m460_DvDw0) - есть команда на движение назад
#define idinternal1_m460_DvDw0	 1389	//(internal1_m460_DvDw0) - есть команда на движение назад
#define internal1_m460_FDvUp0	 BUFFER[8116]	//(internal1_m460_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m460_FDvUp0	 1390	//(internal1_m460_FDvUp0) - есть команда на движение вперёд
#define internal1_m460_FDvDw0	 BUFFER[8117]	//(internal1_m460_FDvDw0) - есть команда на движение назад
#define idinternal1_m460_FDvDw0	 1391	//(internal1_m460_FDvDw0) - есть команда на движение назад
#define internal1_m460_BlDv0	 BUFFER[8118]	//(internal1_m460_BlDv0) - была блокировка
#define idinternal1_m460_BlDv0	 1392	//(internal1_m460_BlDv0) - была блокировка
#define internal1_m460_Pkv0	 BUFFER[8119]	//(internal1_m460_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m460_Pkv0	 1393	//(internal1_m460_Pkv0) Pkv - передний конечный выключатель
#define internal1_m460_Pkav0	 BUFFER[8120]	//(internal1_m460_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m460_Pkav0	 1394	//(internal1_m460_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m460_Zkv0	 BUFFER[8121]	//(internal1_m460_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m460_Zkv0	 1395	//(internal1_m460_Zkv0) Zkv - задний конечный выключатель
#define internal1_m460_Zkav0	 BUFFER[8122]	//(internal1_m460_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m460_Zkav0	 1396	//(internal1_m460_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m460_txNm	 BUFFER[8123]	//(internal1_m460_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m460_txNm	 1397	//(internal1_m460_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m460_txSm	 BUFFER[8128]	//(internal1_m460_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m460_txSm	 1398	//(internal1_m460_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m460_txHr	 BUFFER[8133]	//(internal1_m460_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m460_txHr	 1399	//(internal1_m460_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m460_txLd	 BUFFER[8138]	//(internal1_m460_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m460_txLd	 1400	//(internal1_m460_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m460_fef	 BUFFER[8143]	//(internal1_m460_fef) fef
#define idinternal1_m460_fef	 1401	//(internal1_m460_fef) fef
#define internal1_m813_X0	 BUFFER[8144]	//(internal1_m813_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m813_X0	 1402	//(internal1_m813_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m813_t0	 BUFFER[8149]	//(internal1_m813_t0) время нахождения в зоне возврата
#define idinternal1_m813_t0	 1403	//(internal1_m813_t0) время нахождения в зоне возврата
#define internal1_m813_BLDv0	 BUFFER[8154]	//(internal1_m813_BLDv0) BlDv - Блокировка движения
#define idinternal1_m813_BLDv0	 1404	//(internal1_m813_BLDv0) BlDv - Блокировка движения
#define internal1_m833_xptr	 BUFFER[8155]	//(internal1_m833_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m833_xptr	 1405	//(internal1_m833_xptr) указатель текущей позиции в массиве координат
#define internal1_m833_x0	 BUFFER[8158]	//(internal1_m833_x0) x0 - массив мгновенных значений координат
#define idinternal1_m833_x0	 1406	//(internal1_m833_x0) x0 - массив мгновенных значений координат
#define internal1_m833_tim0	 BUFFER[8558]	//(internal1_m833_tim0) tim0 - массив значений времени цикла
#define idinternal1_m833_tim0	 1407	//(internal1_m833_tim0) tim0 - массив значений времени цикла
#define internal1_m833_sumtim	 BUFFER[8958]	//(internal1_m833_sumtim) sumtim - время в пути
#define idinternal1_m833_sumtim	 1408	//(internal1_m833_sumtim) sumtim - время в пути
#define internal1_m833_StSpeed	 BUFFER[8963]	//(internal1_m833_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m833_StSpeed	 1409	//(internal1_m833_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m833_Vz0	 BUFFER[8968]	//(internal1_m833_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m833_Vz0	 1410	//(internal1_m833_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m833_flRazg	 BUFFER[8973]	//(internal1_m833_flRazg) признак разгона/торможения
#define idinternal1_m833_flRazg	 1411	//(internal1_m833_flRazg) признак разгона/торможения
#define internal1_m833_DelSp	 BUFFER[8976]	//(internal1_m833_DelSp) DelSp - время переключения скоростей
#define idinternal1_m833_DelSp	 1412	//(internal1_m833_DelSp) DelSp - время переключения скоростей
#define internal1_m833_z0	 BUFFER[8981]	//(internal1_m833_z0) z0 - точка прекращения движения
#define idinternal1_m833_z0	 1413	//(internal1_m833_z0) z0 - точка прекращения движения
#define internal1_m833_txZS	 BUFFER[8986]	//(internal1_m833_txZS) txZS
#define idinternal1_m833_txZS	 1414	//(internal1_m833_txZS) txZS
#define internal1_m833_tx	 BUFFER[8991]	//(internal1_m833_tx) tx
#define idinternal1_m833_tx	 1415	//(internal1_m833_tx) tx
#define internal1_m833_txd	 BUFFER[8996]	//(internal1_m833_txd) txd
#define idinternal1_m833_txd	 1416	//(internal1_m833_txd) txd
#define internal1_m833_txMBl	 BUFFER[9001]	//(internal1_m833_txMBl) tx
#define idinternal1_m833_txMBl	 1417	//(internal1_m833_txMBl) tx
#define internal1_m833_txBl	 BUFFER[9006]	//(internal1_m833_txBl) tx
#define idinternal1_m833_txBl	 1418	//(internal1_m833_txBl) tx
#define internal1_m833_Speed0	 BUFFER[9011]	//(internal1_m833_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m833_Speed0	 1419	//(internal1_m833_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m833_xz0	 BUFFER[9016]	//(internal1_m833_xz0) xz0 - новое задание мм
#define idinternal1_m833_xz0	 1420	//(internal1_m833_xz0) xz0 - новое задание мм
#define internal1_m833_tz0	 BUFFER[9021]	//(internal1_m833_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m833_tz0	 1421	//(internal1_m833_tz0) tz0 - время защиты от нового задания сек
#define internal1_m833_Shift0	 BUFFER[9026]	//(internal1_m833_Shift0) Shift0 - признак самохода
#define idinternal1_m833_Shift0	 1422	//(internal1_m833_Shift0) Shift0 - признак самохода
#define internal1_m833_ShCntlSp0	 BUFFER[9028]	//(internal1_m833_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m833_ShCntlSp0	 1423	//(internal1_m833_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m833_ShiftControl	 BUFFER[9030]	//(internal1_m833_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m833_ShiftControl	 1424	//(internal1_m833_ShiftControl) ShiftControl - признак самохода
#define internal1_m1592_X0	 BUFFER[9032]	//(internal1_m1592_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1592_X0	 1425	//(internal1_m1592_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1592_t0	 BUFFER[9037]	//(internal1_m1592_t0) время нахождения в зоне возврата
#define idinternal1_m1592_t0	 1426	//(internal1_m1592_t0) время нахождения в зоне возврата
#define internal1_m1592_BLDv0	 BUFFER[9042]	//(internal1_m1592_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1592_BLDv0	 1427	//(internal1_m1592_BLDv0) BlDv - Блокировка движения
#define internal1_m1116_X0	 BUFFER[9043]	//(internal1_m1116_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1116_X0	 1428	//(internal1_m1116_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1116_t0	 BUFFER[9048]	//(internal1_m1116_t0) время нахождения в зоне возврата
#define idinternal1_m1116_t0	 1429	//(internal1_m1116_t0) время нахождения в зоне возврата
#define internal1_m1116_BLDv0	 BUFFER[9053]	//(internal1_m1116_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1116_BLDv0	 1430	//(internal1_m1116_BLDv0) BlDv - Блокировка движения
#define internal1_m619_q0	 BUFFER[9054]	//(internal1_m619_q0) q0 - внутренний параметр
#define idinternal1_m619_q0	 1431	//(internal1_m619_q0) q0 - внутренний параметр
#define internal1_m1213_X0	 BUFFER[9056]	//(internal1_m1213_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1213_X0	 1432	//(internal1_m1213_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1213_t0	 BUFFER[9061]	//(internal1_m1213_t0) время нахождения в зоне возврата
#define idinternal1_m1213_t0	 1433	//(internal1_m1213_t0) время нахождения в зоне возврата
#define internal1_m1213_BLDv0	 BUFFER[9066]	//(internal1_m1213_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1213_BLDv0	 1434	//(internal1_m1213_BLDv0) BlDv - Блокировка движения
#define internal1_m1233_tx	 BUFFER[9067]	//(internal1_m1233_tx) tx - время накопленное сек
#define idinternal1_m1233_tx	 1435	//(internal1_m1233_tx) tx - время накопленное сек
#define internal1_m1233_y0	 BUFFER[9072]	//(internal1_m1233_y0) y0
#define idinternal1_m1233_y0	 1436	//(internal1_m1233_y0) y0
#define internal1_m1242_tx	 BUFFER[9073]	//(internal1_m1242_tx) tx - время накопленное сек
#define idinternal1_m1242_tx	 1437	//(internal1_m1242_tx) tx - время накопленное сек
#define internal1_m1242_y0	 BUFFER[9078]	//(internal1_m1242_y0) y0
#define idinternal1_m1242_y0	 1438	//(internal1_m1242_y0) y0
#define internal1_m1248_xptr	 BUFFER[9079]	//(internal1_m1248_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1248_xptr	 1439	//(internal1_m1248_xptr) указатель текущей позиции в массиве координат
#define internal1_m1248_x0	 BUFFER[9082]	//(internal1_m1248_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1248_x0	 1440	//(internal1_m1248_x0) x0 - массив мгновенных значений координат
#define internal1_m1248_tim0	 BUFFER[9482]	//(internal1_m1248_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1248_tim0	 1441	//(internal1_m1248_tim0) tim0 - массив значений времени цикла
#define internal1_m1248_sumtim	 BUFFER[9882]	//(internal1_m1248_sumtim) sumtim - время в пути
#define idinternal1_m1248_sumtim	 1442	//(internal1_m1248_sumtim) sumtim - время в пути
#define internal1_m1248_StSpeed	 BUFFER[9887]	//(internal1_m1248_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1248_StSpeed	 1443	//(internal1_m1248_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1248_Vz0	 BUFFER[9892]	//(internal1_m1248_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1248_Vz0	 1444	//(internal1_m1248_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1248_flRazg	 BUFFER[9897]	//(internal1_m1248_flRazg) признак разгона/торможения
#define idinternal1_m1248_flRazg	 1445	//(internal1_m1248_flRazg) признак разгона/торможения
#define internal1_m1248_DelSp	 BUFFER[9900]	//(internal1_m1248_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1248_DelSp	 1446	//(internal1_m1248_DelSp) DelSp - время переключения скоростей
#define internal1_m1248_z0	 BUFFER[9905]	//(internal1_m1248_z0) z0 - точка прекращения движения
#define idinternal1_m1248_z0	 1447	//(internal1_m1248_z0) z0 - точка прекращения движения
#define internal1_m1248_txZS	 BUFFER[9910]	//(internal1_m1248_txZS) txZS
#define idinternal1_m1248_txZS	 1448	//(internal1_m1248_txZS) txZS
#define internal1_m1248_tx	 BUFFER[9915]	//(internal1_m1248_tx) tx
#define idinternal1_m1248_tx	 1449	//(internal1_m1248_tx) tx
#define internal1_m1248_txd	 BUFFER[9920]	//(internal1_m1248_txd) txd
#define idinternal1_m1248_txd	 1450	//(internal1_m1248_txd) txd
#define internal1_m1248_txMBl	 BUFFER[9925]	//(internal1_m1248_txMBl) tx
#define idinternal1_m1248_txMBl	 1451	//(internal1_m1248_txMBl) tx
#define internal1_m1248_txBl	 BUFFER[9930]	//(internal1_m1248_txBl) tx
#define idinternal1_m1248_txBl	 1452	//(internal1_m1248_txBl) tx
#define internal1_m1248_Speed0	 BUFFER[9935]	//(internal1_m1248_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1248_Speed0	 1453	//(internal1_m1248_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1248_xz0	 BUFFER[9940]	//(internal1_m1248_xz0) xz0 - новое задание мм
#define idinternal1_m1248_xz0	 1454	//(internal1_m1248_xz0) xz0 - новое задание мм
#define internal1_m1248_tz0	 BUFFER[9945]	//(internal1_m1248_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1248_tz0	 1455	//(internal1_m1248_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1248_Shift0	 BUFFER[9950]	//(internal1_m1248_Shift0) Shift0 - признак самохода
#define idinternal1_m1248_Shift0	 1456	//(internal1_m1248_Shift0) Shift0 - признак самохода
#define internal1_m1248_ShCntlSp0	 BUFFER[9952]	//(internal1_m1248_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1248_ShCntlSp0	 1457	//(internal1_m1248_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1248_ShiftControl	 BUFFER[9954]	//(internal1_m1248_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1248_ShiftControl	 1458	//(internal1_m1248_ShiftControl) ShiftControl - признак самохода
#define internal1_m639_q0	 BUFFER[9956]	//(internal1_m639_q0) q0 - внутренний параметр
#define idinternal1_m639_q0	 1459	//(internal1_m639_q0) q0 - внутренний параметр
#define internal1_m1605_tx	 BUFFER[9958]	//(internal1_m1605_tx) tx - время накопленное сек
#define idinternal1_m1605_tx	 1460	//(internal1_m1605_tx) tx - время накопленное сек
#define internal1_m1605_y0	 BUFFER[9963]	//(internal1_m1605_y0) y0
#define idinternal1_m1605_y0	 1461	//(internal1_m1605_y0) y0
#define internal1_m1607_tx	 BUFFER[9964]	//(internal1_m1607_tx) tx - время накопленное сек
#define idinternal1_m1607_tx	 1462	//(internal1_m1607_tx) tx - время накопленное сек
#define internal1_m1607_y0	 BUFFER[9969]	//(internal1_m1607_y0) y0
#define idinternal1_m1607_y0	 1463	//(internal1_m1607_y0) y0
#define internal1_m1595_DvUp0	 BUFFER[9970]	//(internal1_m1595_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1595_DvUp0	 1464	//(internal1_m1595_DvUp0) - есть команда на движение вперёд
#define internal1_m1595_DvDw0	 BUFFER[9971]	//(internal1_m1595_DvDw0) - есть команда на движение назад
#define idinternal1_m1595_DvDw0	 1465	//(internal1_m1595_DvDw0) - есть команда на движение назад
#define internal1_m1595_FDvUp0	 BUFFER[9972]	//(internal1_m1595_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1595_FDvUp0	 1466	//(internal1_m1595_FDvUp0) - есть команда на движение вперёд
#define internal1_m1595_FDvDw0	 BUFFER[9973]	//(internal1_m1595_FDvDw0) - есть команда на движение назад
#define idinternal1_m1595_FDvDw0	 1467	//(internal1_m1595_FDvDw0) - есть команда на движение назад
#define internal1_m1595_BlDv0	 BUFFER[9974]	//(internal1_m1595_BlDv0) - была блокировка
#define idinternal1_m1595_BlDv0	 1468	//(internal1_m1595_BlDv0) - была блокировка
#define internal1_m1595_Pkv0	 BUFFER[9975]	//(internal1_m1595_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1595_Pkv0	 1469	//(internal1_m1595_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1595_Pkav0	 BUFFER[9976]	//(internal1_m1595_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1595_Pkav0	 1470	//(internal1_m1595_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1595_Zkv0	 BUFFER[9977]	//(internal1_m1595_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1595_Zkv0	 1471	//(internal1_m1595_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1595_Zkav0	 BUFFER[9978]	//(internal1_m1595_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1595_Zkav0	 1472	//(internal1_m1595_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1595_txNm	 BUFFER[9979]	//(internal1_m1595_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1595_txNm	 1473	//(internal1_m1595_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1595_txSm	 BUFFER[9984]	//(internal1_m1595_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1595_txSm	 1474	//(internal1_m1595_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1595_txHr	 BUFFER[9989]	//(internal1_m1595_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1595_txHr	 1475	//(internal1_m1595_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1595_txLd	 BUFFER[9994]	//(internal1_m1595_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1595_txLd	 1476	//(internal1_m1595_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1595_fef	 BUFFER[9999]	//(internal1_m1595_fef) fef
#define idinternal1_m1595_fef	 1477	//(internal1_m1595_fef) fef
#define internal1_m1612_xptr	 BUFFER[10000]	//(internal1_m1612_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1612_xptr	 1478	//(internal1_m1612_xptr) указатель текущей позиции в массиве координат
#define internal1_m1612_x0	 BUFFER[10003]	//(internal1_m1612_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1612_x0	 1479	//(internal1_m1612_x0) x0 - массив мгновенных значений координат
#define internal1_m1612_tim0	 BUFFER[10103]	//(internal1_m1612_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1612_tim0	 1480	//(internal1_m1612_tim0) tim0 - массив значений времени цикла
#define internal1_m1612_sumtim	 BUFFER[10203]	//(internal1_m1612_sumtim) sumtim - время в пути
#define idinternal1_m1612_sumtim	 1481	//(internal1_m1612_sumtim) sumtim - время в пути
#define internal1_m1612_StSpeed	 BUFFER[10208]	//(internal1_m1612_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1612_StSpeed	 1482	//(internal1_m1612_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1612_Vz0	 BUFFER[10213]	//(internal1_m1612_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1612_Vz0	 1483	//(internal1_m1612_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1612_flRazg	 BUFFER[10218]	//(internal1_m1612_flRazg) признак разгона/торможения
#define idinternal1_m1612_flRazg	 1484	//(internal1_m1612_flRazg) признак разгона/торможения
#define internal1_m1612_DelSp	 BUFFER[10221]	//(internal1_m1612_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1612_DelSp	 1485	//(internal1_m1612_DelSp) DelSp - время переключения скоростей
#define internal1_m1612_z0	 BUFFER[10226]	//(internal1_m1612_z0) z0 - точка прекращения движения
#define idinternal1_m1612_z0	 1486	//(internal1_m1612_z0) z0 - точка прекращения движения
#define internal1_m1612_txZS	 BUFFER[10231]	//(internal1_m1612_txZS) txZS
#define idinternal1_m1612_txZS	 1487	//(internal1_m1612_txZS) txZS
#define internal1_m1612_tx	 BUFFER[10236]	//(internal1_m1612_tx) tx
#define idinternal1_m1612_tx	 1488	//(internal1_m1612_tx) tx
#define internal1_m1612_txd	 BUFFER[10241]	//(internal1_m1612_txd) txd
#define idinternal1_m1612_txd	 1489	//(internal1_m1612_txd) txd
#define internal1_m1612_txMBl	 BUFFER[10246]	//(internal1_m1612_txMBl) tx
#define idinternal1_m1612_txMBl	 1490	//(internal1_m1612_txMBl) tx
#define internal1_m1612_txBl	 BUFFER[10251]	//(internal1_m1612_txBl) tx
#define idinternal1_m1612_txBl	 1491	//(internal1_m1612_txBl) tx
#define internal1_m1612_Speed0	 BUFFER[10256]	//(internal1_m1612_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1612_Speed0	 1492	//(internal1_m1612_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1612_xz0	 BUFFER[10261]	//(internal1_m1612_xz0) xz0 - новое задание мм
#define idinternal1_m1612_xz0	 1493	//(internal1_m1612_xz0) xz0 - новое задание мм
#define internal1_m1612_tz0	 BUFFER[10266]	//(internal1_m1612_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1612_tz0	 1494	//(internal1_m1612_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1612_Shift0	 BUFFER[10271]	//(internal1_m1612_Shift0) Shift0 - признак самохода
#define idinternal1_m1612_Shift0	 1495	//(internal1_m1612_Shift0) Shift0 - признак самохода
#define internal1_m1612_ShCntlSp0	 BUFFER[10273]	//(internal1_m1612_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1612_ShCntlSp0	 1496	//(internal1_m1612_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1612_ShiftControl	 BUFFER[10275]	//(internal1_m1612_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1612_ShiftControl	 1497	//(internal1_m1612_ShiftControl) ShiftControl - признак самохода
#define internal1_m1129_tx	 BUFFER[10277]	//(internal1_m1129_tx) tx - время накопленное сек
#define idinternal1_m1129_tx	 1498	//(internal1_m1129_tx) tx - время накопленное сек
#define internal1_m1129_y0	 BUFFER[10282]	//(internal1_m1129_y0) y0
#define idinternal1_m1129_y0	 1499	//(internal1_m1129_y0) y0
#define internal1_m1133_tx	 BUFFER[10283]	//(internal1_m1133_tx) tx - время накопленное сек
#define idinternal1_m1133_tx	 1500	//(internal1_m1133_tx) tx - время накопленное сек
#define internal1_m1133_y0	 BUFFER[10288]	//(internal1_m1133_y0) y0
#define idinternal1_m1133_y0	 1501	//(internal1_m1133_y0) y0
#define internal1_m629_q0	 BUFFER[10289]	//(internal1_m629_q0) q0 - внутренний параметр
#define idinternal1_m629_q0	 1502	//(internal1_m629_q0) q0 - внутренний параметр
#define internal1_m594_q0	 BUFFER[10291]	//(internal1_m594_q0) q0 - внутренний параметр
#define idinternal1_m594_q0	 1503	//(internal1_m594_q0) q0 - внутренний параметр
#define internal1_m1119_DvUp0	 BUFFER[10293]	//(internal1_m1119_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1119_DvUp0	 1504	//(internal1_m1119_DvUp0) - есть команда на движение вперёд
#define internal1_m1119_DvDw0	 BUFFER[10294]	//(internal1_m1119_DvDw0) - есть команда на движение назад
#define idinternal1_m1119_DvDw0	 1505	//(internal1_m1119_DvDw0) - есть команда на движение назад
#define internal1_m1119_FDvUp0	 BUFFER[10295]	//(internal1_m1119_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1119_FDvUp0	 1506	//(internal1_m1119_FDvUp0) - есть команда на движение вперёд
#define internal1_m1119_FDvDw0	 BUFFER[10296]	//(internal1_m1119_FDvDw0) - есть команда на движение назад
#define idinternal1_m1119_FDvDw0	 1507	//(internal1_m1119_FDvDw0) - есть команда на движение назад
#define internal1_m1119_BlDv0	 BUFFER[10297]	//(internal1_m1119_BlDv0) - была блокировка
#define idinternal1_m1119_BlDv0	 1508	//(internal1_m1119_BlDv0) - была блокировка
#define internal1_m1119_Pkv0	 BUFFER[10298]	//(internal1_m1119_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1119_Pkv0	 1509	//(internal1_m1119_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1119_Pkav0	 BUFFER[10299]	//(internal1_m1119_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1119_Pkav0	 1510	//(internal1_m1119_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1119_Zkv0	 BUFFER[10300]	//(internal1_m1119_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1119_Zkv0	 1511	//(internal1_m1119_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1119_Zkav0	 BUFFER[10301]	//(internal1_m1119_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1119_Zkav0	 1512	//(internal1_m1119_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1119_txNm	 BUFFER[10302]	//(internal1_m1119_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1119_txNm	 1513	//(internal1_m1119_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1119_txSm	 BUFFER[10307]	//(internal1_m1119_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1119_txSm	 1514	//(internal1_m1119_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1119_txHr	 BUFFER[10312]	//(internal1_m1119_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1119_txHr	 1515	//(internal1_m1119_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1119_txLd	 BUFFER[10317]	//(internal1_m1119_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1119_txLd	 1516	//(internal1_m1119_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1119_fef	 BUFFER[10322]	//(internal1_m1119_fef) fef
#define idinternal1_m1119_fef	 1517	//(internal1_m1119_fef) fef
#define internal1_m1137_xptr	 BUFFER[10323]	//(internal1_m1137_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1137_xptr	 1518	//(internal1_m1137_xptr) указатель текущей позиции в массиве координат
#define internal1_m1137_x0	 BUFFER[10326]	//(internal1_m1137_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1137_x0	 1519	//(internal1_m1137_x0) x0 - массив мгновенных значений координат
#define internal1_m1137_tim0	 BUFFER[10426]	//(internal1_m1137_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1137_tim0	 1520	//(internal1_m1137_tim0) tim0 - массив значений времени цикла
#define internal1_m1137_sumtim	 BUFFER[10526]	//(internal1_m1137_sumtim) sumtim - время в пути
#define idinternal1_m1137_sumtim	 1521	//(internal1_m1137_sumtim) sumtim - время в пути
#define internal1_m1137_StSpeed	 BUFFER[10531]	//(internal1_m1137_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1137_StSpeed	 1522	//(internal1_m1137_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1137_Vz0	 BUFFER[10536]	//(internal1_m1137_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1137_Vz0	 1523	//(internal1_m1137_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1137_flRazg	 BUFFER[10541]	//(internal1_m1137_flRazg) признак разгона/торможения
#define idinternal1_m1137_flRazg	 1524	//(internal1_m1137_flRazg) признак разгона/торможения
#define internal1_m1137_DelSp	 BUFFER[10544]	//(internal1_m1137_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1137_DelSp	 1525	//(internal1_m1137_DelSp) DelSp - время переключения скоростей
#define internal1_m1137_z0	 BUFFER[10549]	//(internal1_m1137_z0) z0 - точка прекращения движения
#define idinternal1_m1137_z0	 1526	//(internal1_m1137_z0) z0 - точка прекращения движения
#define internal1_m1137_txZS	 BUFFER[10554]	//(internal1_m1137_txZS) txZS
#define idinternal1_m1137_txZS	 1527	//(internal1_m1137_txZS) txZS
#define internal1_m1137_tx	 BUFFER[10559]	//(internal1_m1137_tx) tx
#define idinternal1_m1137_tx	 1528	//(internal1_m1137_tx) tx
#define internal1_m1137_txd	 BUFFER[10564]	//(internal1_m1137_txd) txd
#define idinternal1_m1137_txd	 1529	//(internal1_m1137_txd) txd
#define internal1_m1137_txMBl	 BUFFER[10569]	//(internal1_m1137_txMBl) tx
#define idinternal1_m1137_txMBl	 1530	//(internal1_m1137_txMBl) tx
#define internal1_m1137_txBl	 BUFFER[10574]	//(internal1_m1137_txBl) tx
#define idinternal1_m1137_txBl	 1531	//(internal1_m1137_txBl) tx
#define internal1_m1137_Speed0	 BUFFER[10579]	//(internal1_m1137_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1137_Speed0	 1532	//(internal1_m1137_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1137_xz0	 BUFFER[10584]	//(internal1_m1137_xz0) xz0 - новое задание мм
#define idinternal1_m1137_xz0	 1533	//(internal1_m1137_xz0) xz0 - новое задание мм
#define internal1_m1137_tz0	 BUFFER[10589]	//(internal1_m1137_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1137_tz0	 1534	//(internal1_m1137_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1137_Shift0	 BUFFER[10594]	//(internal1_m1137_Shift0) Shift0 - признак самохода
#define idinternal1_m1137_Shift0	 1535	//(internal1_m1137_Shift0) Shift0 - признак самохода
#define internal1_m1137_ShCntlSp0	 BUFFER[10596]	//(internal1_m1137_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1137_ShCntlSp0	 1536	//(internal1_m1137_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1137_ShiftControl	 BUFFER[10598]	//(internal1_m1137_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1137_ShiftControl	 1537	//(internal1_m1137_ShiftControl) ShiftControl - признак самохода
#define internal1_m742_x0	 BUFFER[10600]	//(internal1_m742_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m742_x0	 1538	//(internal1_m742_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m711_x0	 BUFFER[10602]	//(internal1_m711_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m711_x0	 1539	//(internal1_m711_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m675_x0	 BUFFER[10604]	//(internal1_m675_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m675_x0	 1540	//(internal1_m675_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m767_q0	 BUFFER[10606]	//(internal1_m767_q0) q0 - внутренний параметр
#define idinternal1_m767_q0	 1541	//(internal1_m767_q0) q0 - внутренний параметр
#define internal1_m762_q0	 BUFFER[10608]	//(internal1_m762_q0) q0 - внутренний параметр
#define idinternal1_m762_q0	 1542	//(internal1_m762_q0) q0 - внутренний параметр
#define internal1_m730_q0	 BUFFER[10610]	//(internal1_m730_q0) q0 - внутренний параметр
#define idinternal1_m730_q0	 1543	//(internal1_m730_q0) q0 - внутренний параметр
#define internal1_m735_q0	 BUFFER[10612]	//(internal1_m735_q0) q0 - внутренний параметр
#define idinternal1_m735_q0	 1544	//(internal1_m735_q0) q0 - внутренний параметр
#define internal1_m743_q0	 BUFFER[10614]	//(internal1_m743_q0) q0 - внутренний параметр
#define idinternal1_m743_q0	 1545	//(internal1_m743_q0) q0 - внутренний параметр
#define internal1_m755_q0	 BUFFER[10616]	//(internal1_m755_q0) q0 - внутренний параметр
#define idinternal1_m755_q0	 1546	//(internal1_m755_q0) q0 - внутренний параметр
#define internal1_m733_q0	 BUFFER[10618]	//(internal1_m733_q0) q0 - внутренний параметр
#define idinternal1_m733_q0	 1547	//(internal1_m733_q0) q0 - внутренний параметр
#define internal1_m1190_DvUp0	 BUFFER[10620]	//(internal1_m1190_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1190_DvUp0	 1548	//(internal1_m1190_DvUp0) - есть команда на движение вперёд
#define internal1_m1190_DvDw0	 BUFFER[10621]	//(internal1_m1190_DvDw0) - есть команда на движение назад
#define idinternal1_m1190_DvDw0	 1549	//(internal1_m1190_DvDw0) - есть команда на движение назад
#define internal1_m1190_FDvUp0	 BUFFER[10622]	//(internal1_m1190_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1190_FDvUp0	 1550	//(internal1_m1190_FDvUp0) - есть команда на движение вперёд
#define internal1_m1190_FDvDw0	 BUFFER[10623]	//(internal1_m1190_FDvDw0) - есть команда на движение назад
#define idinternal1_m1190_FDvDw0	 1551	//(internal1_m1190_FDvDw0) - есть команда на движение назад
#define internal1_m1190_BlDv0	 BUFFER[10624]	//(internal1_m1190_BlDv0) - была блокировка
#define idinternal1_m1190_BlDv0	 1552	//(internal1_m1190_BlDv0) - была блокировка
#define internal1_m1190_Pkv0	 BUFFER[10625]	//(internal1_m1190_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1190_Pkv0	 1553	//(internal1_m1190_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1190_Pkav0	 BUFFER[10626]	//(internal1_m1190_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1190_Pkav0	 1554	//(internal1_m1190_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1190_Zkv0	 BUFFER[10627]	//(internal1_m1190_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1190_Zkv0	 1555	//(internal1_m1190_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1190_Zkav0	 BUFFER[10628]	//(internal1_m1190_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1190_Zkav0	 1556	//(internal1_m1190_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1190_txNm	 BUFFER[10629]	//(internal1_m1190_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1190_txNm	 1557	//(internal1_m1190_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1190_txSm	 BUFFER[10634]	//(internal1_m1190_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1190_txSm	 1558	//(internal1_m1190_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1190_txHr	 BUFFER[10639]	//(internal1_m1190_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1190_txHr	 1559	//(internal1_m1190_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1190_txLd	 BUFFER[10644]	//(internal1_m1190_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1190_txLd	 1560	//(internal1_m1190_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1190_fef	 BUFFER[10649]	//(internal1_m1190_fef) fef
#define idinternal1_m1190_fef	 1561	//(internal1_m1190_fef) fef
#define internal1_m1179_DvUp0	 BUFFER[10650]	//(internal1_m1179_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1179_DvUp0	 1562	//(internal1_m1179_DvUp0) - есть команда на движение вперёд
#define internal1_m1179_DvDw0	 BUFFER[10651]	//(internal1_m1179_DvDw0) - есть команда на движение назад
#define idinternal1_m1179_DvDw0	 1563	//(internal1_m1179_DvDw0) - есть команда на движение назад
#define internal1_m1179_FDvUp0	 BUFFER[10652]	//(internal1_m1179_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1179_FDvUp0	 1564	//(internal1_m1179_FDvUp0) - есть команда на движение вперёд
#define internal1_m1179_FDvDw0	 BUFFER[10653]	//(internal1_m1179_FDvDw0) - есть команда на движение назад
#define idinternal1_m1179_FDvDw0	 1565	//(internal1_m1179_FDvDw0) - есть команда на движение назад
#define internal1_m1179_BlDv0	 BUFFER[10654]	//(internal1_m1179_BlDv0) - была блокировка
#define idinternal1_m1179_BlDv0	 1566	//(internal1_m1179_BlDv0) - была блокировка
#define internal1_m1179_Pkv0	 BUFFER[10655]	//(internal1_m1179_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1179_Pkv0	 1567	//(internal1_m1179_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1179_Pkav0	 BUFFER[10656]	//(internal1_m1179_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1179_Pkav0	 1568	//(internal1_m1179_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1179_Zkv0	 BUFFER[10657]	//(internal1_m1179_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1179_Zkv0	 1569	//(internal1_m1179_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1179_Zkav0	 BUFFER[10658]	//(internal1_m1179_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1179_Zkav0	 1570	//(internal1_m1179_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1179_txNm	 BUFFER[10659]	//(internal1_m1179_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1179_txNm	 1571	//(internal1_m1179_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1179_txSm	 BUFFER[10664]	//(internal1_m1179_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1179_txSm	 1572	//(internal1_m1179_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1179_txHr	 BUFFER[10669]	//(internal1_m1179_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1179_txHr	 1573	//(internal1_m1179_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1179_txLd	 BUFFER[10674]	//(internal1_m1179_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1179_txLd	 1574	//(internal1_m1179_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1179_fef	 BUFFER[10679]	//(internal1_m1179_fef) fef
#define idinternal1_m1179_fef	 1575	//(internal1_m1179_fef) fef
#define internal1_m787_DvUp0	 BUFFER[10680]	//(internal1_m787_DvUp0) - есть команда на движение вперёд
#define idinternal1_m787_DvUp0	 1576	//(internal1_m787_DvUp0) - есть команда на движение вперёд
#define internal1_m787_DvDw0	 BUFFER[10681]	//(internal1_m787_DvDw0) - есть команда на движение назад
#define idinternal1_m787_DvDw0	 1577	//(internal1_m787_DvDw0) - есть команда на движение назад
#define internal1_m787_FDvUp0	 BUFFER[10682]	//(internal1_m787_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m787_FDvUp0	 1578	//(internal1_m787_FDvUp0) - есть команда на движение вперёд
#define internal1_m787_FDvDw0	 BUFFER[10683]	//(internal1_m787_FDvDw0) - есть команда на движение назад
#define idinternal1_m787_FDvDw0	 1579	//(internal1_m787_FDvDw0) - есть команда на движение назад
#define internal1_m787_BlDv0	 BUFFER[10684]	//(internal1_m787_BlDv0) - была блокировка
#define idinternal1_m787_BlDv0	 1580	//(internal1_m787_BlDv0) - была блокировка
#define internal1_m787_Pkv0	 BUFFER[10685]	//(internal1_m787_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m787_Pkv0	 1581	//(internal1_m787_Pkv0) Pkv - передний конечный выключатель
#define internal1_m787_Pkav0	 BUFFER[10686]	//(internal1_m787_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m787_Pkav0	 1582	//(internal1_m787_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m787_Zkv0	 BUFFER[10687]	//(internal1_m787_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m787_Zkv0	 1583	//(internal1_m787_Zkv0) Zkv - задний конечный выключатель
#define internal1_m787_Zkav0	 BUFFER[10688]	//(internal1_m787_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m787_Zkav0	 1584	//(internal1_m787_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m787_txNm	 BUFFER[10689]	//(internal1_m787_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m787_txNm	 1585	//(internal1_m787_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m787_txSm	 BUFFER[10694]	//(internal1_m787_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m787_txSm	 1586	//(internal1_m787_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m787_txHr	 BUFFER[10699]	//(internal1_m787_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m787_txHr	 1587	//(internal1_m787_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m787_txLd	 BUFFER[10704]	//(internal1_m787_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m787_txLd	 1588	//(internal1_m787_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m787_fef	 BUFFER[10709]	//(internal1_m787_fef) fef
#define idinternal1_m787_fef	 1589	//(internal1_m787_fef) fef
#define internal1_m783_DvUp0	 BUFFER[10710]	//(internal1_m783_DvUp0) - есть команда на движение вперёд
#define idinternal1_m783_DvUp0	 1590	//(internal1_m783_DvUp0) - есть команда на движение вперёд
#define internal1_m783_DvDw0	 BUFFER[10711]	//(internal1_m783_DvDw0) - есть команда на движение назад
#define idinternal1_m783_DvDw0	 1591	//(internal1_m783_DvDw0) - есть команда на движение назад
#define internal1_m783_FDvUp0	 BUFFER[10712]	//(internal1_m783_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m783_FDvUp0	 1592	//(internal1_m783_FDvUp0) - есть команда на движение вперёд
#define internal1_m783_FDvDw0	 BUFFER[10713]	//(internal1_m783_FDvDw0) - есть команда на движение назад
#define idinternal1_m783_FDvDw0	 1593	//(internal1_m783_FDvDw0) - есть команда на движение назад
#define internal1_m783_BlDv0	 BUFFER[10714]	//(internal1_m783_BlDv0) - была блокировка
#define idinternal1_m783_BlDv0	 1594	//(internal1_m783_BlDv0) - была блокировка
#define internal1_m783_Pkv0	 BUFFER[10715]	//(internal1_m783_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m783_Pkv0	 1595	//(internal1_m783_Pkv0) Pkv - передний конечный выключатель
#define internal1_m783_Pkav0	 BUFFER[10716]	//(internal1_m783_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m783_Pkav0	 1596	//(internal1_m783_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m783_Zkv0	 BUFFER[10717]	//(internal1_m783_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m783_Zkv0	 1597	//(internal1_m783_Zkv0) Zkv - задний конечный выключатель
#define internal1_m783_Zkav0	 BUFFER[10718]	//(internal1_m783_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m783_Zkav0	 1598	//(internal1_m783_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m783_txNm	 BUFFER[10719]	//(internal1_m783_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m783_txNm	 1599	//(internal1_m783_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m783_txSm	 BUFFER[10724]	//(internal1_m783_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m783_txSm	 1600	//(internal1_m783_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m783_txHr	 BUFFER[10729]	//(internal1_m783_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m783_txHr	 1601	//(internal1_m783_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m783_txLd	 BUFFER[10734]	//(internal1_m783_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m783_txLd	 1602	//(internal1_m783_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m783_fef	 BUFFER[10739]	//(internal1_m783_fef) fef
#define idinternal1_m783_fef	 1603	//(internal1_m783_fef) fef
#define internal1_m365_DvUp0	 BUFFER[10740]	//(internal1_m365_DvUp0) - есть команда на движение вперёд
#define idinternal1_m365_DvUp0	 1604	//(internal1_m365_DvUp0) - есть команда на движение вперёд
#define internal1_m365_DvDw0	 BUFFER[10741]	//(internal1_m365_DvDw0) - есть команда на движение назад
#define idinternal1_m365_DvDw0	 1605	//(internal1_m365_DvDw0) - есть команда на движение назад
#define internal1_m365_FDvUp0	 BUFFER[10742]	//(internal1_m365_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m365_FDvUp0	 1606	//(internal1_m365_FDvUp0) - есть команда на движение вперёд
#define internal1_m365_FDvDw0	 BUFFER[10743]	//(internal1_m365_FDvDw0) - есть команда на движение назад
#define idinternal1_m365_FDvDw0	 1607	//(internal1_m365_FDvDw0) - есть команда на движение назад
#define internal1_m365_BlDv0	 BUFFER[10744]	//(internal1_m365_BlDv0) - была блокировка
#define idinternal1_m365_BlDv0	 1608	//(internal1_m365_BlDv0) - была блокировка
#define internal1_m365_Pkv0	 BUFFER[10745]	//(internal1_m365_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m365_Pkv0	 1609	//(internal1_m365_Pkv0) Pkv - передний конечный выключатель
#define internal1_m365_Pkav0	 BUFFER[10746]	//(internal1_m365_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m365_Pkav0	 1610	//(internal1_m365_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m365_Zkv0	 BUFFER[10747]	//(internal1_m365_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m365_Zkv0	 1611	//(internal1_m365_Zkv0) Zkv - задний конечный выключатель
#define internal1_m365_Zkav0	 BUFFER[10748]	//(internal1_m365_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m365_Zkav0	 1612	//(internal1_m365_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m365_txNm	 BUFFER[10749]	//(internal1_m365_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m365_txNm	 1613	//(internal1_m365_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m365_txSm	 BUFFER[10754]	//(internal1_m365_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m365_txSm	 1614	//(internal1_m365_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m365_txHr	 BUFFER[10759]	//(internal1_m365_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m365_txHr	 1615	//(internal1_m365_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m365_txLd	 BUFFER[10764]	//(internal1_m365_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m365_txLd	 1616	//(internal1_m365_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m365_fef	 BUFFER[10769]	//(internal1_m365_fef) fef
#define idinternal1_m365_fef	 1617	//(internal1_m365_fef) fef
#define internal1_m394_DvUp0	 BUFFER[10770]	//(internal1_m394_DvUp0) - есть команда на движение вперёд
#define idinternal1_m394_DvUp0	 1618	//(internal1_m394_DvUp0) - есть команда на движение вперёд
#define internal1_m394_DvDw0	 BUFFER[10771]	//(internal1_m394_DvDw0) - есть команда на движение назад
#define idinternal1_m394_DvDw0	 1619	//(internal1_m394_DvDw0) - есть команда на движение назад
#define internal1_m394_FDvUp0	 BUFFER[10772]	//(internal1_m394_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m394_FDvUp0	 1620	//(internal1_m394_FDvUp0) - есть команда на движение вперёд
#define internal1_m394_FDvDw0	 BUFFER[10773]	//(internal1_m394_FDvDw0) - есть команда на движение назад
#define idinternal1_m394_FDvDw0	 1621	//(internal1_m394_FDvDw0) - есть команда на движение назад
#define internal1_m394_BlDv0	 BUFFER[10774]	//(internal1_m394_BlDv0) - была блокировка
#define idinternal1_m394_BlDv0	 1622	//(internal1_m394_BlDv0) - была блокировка
#define internal1_m394_Pkv0	 BUFFER[10775]	//(internal1_m394_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m394_Pkv0	 1623	//(internal1_m394_Pkv0) Pkv - передний конечный выключатель
#define internal1_m394_Pkav0	 BUFFER[10776]	//(internal1_m394_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m394_Pkav0	 1624	//(internal1_m394_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m394_Zkv0	 BUFFER[10777]	//(internal1_m394_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m394_Zkv0	 1625	//(internal1_m394_Zkv0) Zkv - задний конечный выключатель
#define internal1_m394_Zkav0	 BUFFER[10778]	//(internal1_m394_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m394_Zkav0	 1626	//(internal1_m394_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m394_txNm	 BUFFER[10779]	//(internal1_m394_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m394_txNm	 1627	//(internal1_m394_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m394_txSm	 BUFFER[10784]	//(internal1_m394_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m394_txSm	 1628	//(internal1_m394_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m394_txHr	 BUFFER[10789]	//(internal1_m394_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m394_txHr	 1629	//(internal1_m394_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m394_txLd	 BUFFER[10794]	//(internal1_m394_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m394_txLd	 1630	//(internal1_m394_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m394_fef	 BUFFER[10799]	//(internal1_m394_fef) fef
#define idinternal1_m394_fef	 1631	//(internal1_m394_fef) fef
#define internal1_m388_DvUp0	 BUFFER[10800]	//(internal1_m388_DvUp0) - есть команда на движение вперёд
#define idinternal1_m388_DvUp0	 1632	//(internal1_m388_DvUp0) - есть команда на движение вперёд
#define internal1_m388_DvDw0	 BUFFER[10801]	//(internal1_m388_DvDw0) - есть команда на движение назад
#define idinternal1_m388_DvDw0	 1633	//(internal1_m388_DvDw0) - есть команда на движение назад
#define internal1_m388_FDvUp0	 BUFFER[10802]	//(internal1_m388_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m388_FDvUp0	 1634	//(internal1_m388_FDvUp0) - есть команда на движение вперёд
#define internal1_m388_FDvDw0	 BUFFER[10803]	//(internal1_m388_FDvDw0) - есть команда на движение назад
#define idinternal1_m388_FDvDw0	 1635	//(internal1_m388_FDvDw0) - есть команда на движение назад
#define internal1_m388_BlDv0	 BUFFER[10804]	//(internal1_m388_BlDv0) - была блокировка
#define idinternal1_m388_BlDv0	 1636	//(internal1_m388_BlDv0) - была блокировка
#define internal1_m388_Pkv0	 BUFFER[10805]	//(internal1_m388_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m388_Pkv0	 1637	//(internal1_m388_Pkv0) Pkv - передний конечный выключатель
#define internal1_m388_Pkav0	 BUFFER[10806]	//(internal1_m388_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m388_Pkav0	 1638	//(internal1_m388_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m388_Zkv0	 BUFFER[10807]	//(internal1_m388_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m388_Zkv0	 1639	//(internal1_m388_Zkv0) Zkv - задний конечный выключатель
#define internal1_m388_Zkav0	 BUFFER[10808]	//(internal1_m388_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m388_Zkav0	 1640	//(internal1_m388_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m388_txNm	 BUFFER[10809]	//(internal1_m388_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m388_txNm	 1641	//(internal1_m388_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m388_txSm	 BUFFER[10814]	//(internal1_m388_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m388_txSm	 1642	//(internal1_m388_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m388_txHr	 BUFFER[10819]	//(internal1_m388_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m388_txHr	 1643	//(internal1_m388_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m388_txLd	 BUFFER[10824]	//(internal1_m388_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m388_txLd	 1644	//(internal1_m388_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m388_fef	 BUFFER[10829]	//(internal1_m388_fef) fef
#define idinternal1_m388_fef	 1645	//(internal1_m388_fef) fef
#define internal1_m739_q0	 BUFFER[10830]	//(internal1_m739_q0) q0 - внутренний параметр
#define idinternal1_m739_q0	 1646	//(internal1_m739_q0) q0 - внутренний параметр
#define internal1_m736_q0	 BUFFER[10832]	//(internal1_m736_q0) q0 - внутренний параметр
#define idinternal1_m736_q0	 1647	//(internal1_m736_q0) q0 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &A2AB15LDU},	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{ 2	,1	,1	, &B2AB15LDU},	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{ 3	,1	,1	, &R0AD21LDU},	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
	{ 4	,1	,1	, &R0VX02LDU},	//( - , DU) Импульс разрешен
	{ 5	,1	,1	, &R0EE03LDU},	//( - , DU) ВПИС ИС
	{ 6	,1	,1	, &R0AB07LDU},	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
	{ 7	,1	,1	, &R0AD16LDU},	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
	{ 8	,1	,1	, &C2MD31LP1},	//( - , DU) Кнопка СБРОС РБ
	{ 9	,3	,1	, &B6VS01IDU},	//( - , DU) Готовность к управлению БЗ2
	{ 10	,1	,1	, &R2AD20LDU},	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
	{ 11	,1	,1	, &R2AD10LDU},	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
	{ 12	,3	,1	, &B8VS01IDU},	//( - , DU) Готовность к управлению АЗ2
	{ 13	,3	,1	, &A8VS01IDU},	//( - , DU) Готовность к управлению ДС2
	{ 14	,1	,1	, &A1IE03LDU},	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
	{ 15	,1	,1	, &A1IE04LDU},	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
	{ 16	,1	,1	, &A2IE03LDU},	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
	{ 17	,1	,1	, &A2IE04LDU},	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
	{ 18	,1	,1	, &A3IE03LDU},	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
	{ 19	,1	,1	, &A3IE04LDU},	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
	{ 20	,1	,1	, &B1IE03LDU},	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
	{ 21	,1	,1	, &B1IE04LDU},	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
	{ 22	,1	,1	, &B2IE03LDU},	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
	{ 23	,1	,1	, &B2IE04LDU},	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
	{ 24	,1	,1	, &A1AB19LDU},	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
	{ 25	,1	,1	, &R0AD14LZ1},	//(vds32:02 - K20VDSR, - ) Имитация срабатывания АЗ от II УР
	{ 26	,1	,1	, &R0AD14LZ2},	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
	{ 27	,1	,1	, &A3VZ13LZ2},	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{ 28	,1	,1	, &A3VZ13LZ1},	//(vds32:02 - K18VDSR, - ) Имитация срабатывания АЗ от ВУ ИС
	{ 29	,1	,1	, &A3VZ15LZ1},	//(vds32:02 - K19VDSR, - ) Имитация срабатывания АЗ от НУП ИС
	{ 30	,1	,1	, &A3VZ15LZ2},	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{ 31	,1	,1	, &B2IS33LDU},	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
	{ 32	,1	,1	, &B3IS31LDU},	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
	{ 33	,1	,1	, &B3IS33LDU},	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
	{ 34	,1	,1	, &B3IS35LDU},	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
	{ 35	,1	,1	, &B4IS10LDU},	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
	{ 36	,1	,1	, &R6IS31LDU},	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
	{ 37	,1	,1	, &R6IS32LDU},	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
	{ 38	,1	,1	, &R6IS42LDU},	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
	{ 39	,1	,1	, &R6IS41LDU},	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
	{ 40	,1	,1	, &R6IS52LDU},	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
	{ 41	,1	,1	, &R6IS51LDU},	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
	{ 42	,1	,1	, &R3IS11LDU},	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
	{ 43	,1	,1	, &R3IS21LDU},	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
	{ 44	,1	,1	, &R0AB03LDU},	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
	{ 45	,1	,1	, &R0AB05LDU},	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
	{ 46	,8	,1	, &R0VN11RZ1},	//( - , MDuBz1) Средняя мощность по BAZ1
	{ 47	,8	,1	, &R0VN11RZ2},	//( - , MDuBz2) Средняя мощность по BAZ2
	{ 48	,1	,1	, &A4UP},	//( - , DU) 
	{ 49	,1	,1	, &A4DW},	//( - , DU) 
	{ 50	,1	,1	, &R0AB14LDU},	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
	{ 51	,1	,1	, &R0AB15LDU},	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
	{ 52	,1	,1	, &A3IS12LDU},	//( - , DU) Приход на ВУ штока ИС1
	{ 53	,1	,1	, &B3IS12LDU},	//( - , DU) Приход на ВУ штока ИС2
	{ 54	,1	,1	, &A1ZAV},	//( - , DU) 
	{ 55	,1	,1	, &A3ZAV},	//( - , DU) 
	{ 56	,1	,1	, &B1AB19LDU},	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
	{ 57	,8	,1	, &R0VN09RZ2},	//( - , MDuBz2) Усредненный период разгона
	{ 58	,8	,1	, &R0VN09RZ1},	//( - , MDuBz1) Усредненный период разгона
	{ 59	,1	,1	, &R0AB16LDU},	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
	{ 60	,1	,1	, &R0AB17LDU},	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
	{ 61	,1	,1	, &R0AB18LDU},	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
	{ 62	,8	,1	, &A0CT01IZ1},	//( - , MDuBz1) Температура АЗ1-1
	{ 63	,8	,1	, &B0CT01IZ1},	//( - , MDuBz1) Температура АЗ2-1
	{ 64	,8	,1	, &A0CT01IZ2},	//( - , MDuBz2) Температура АЗ1-2
	{ 65	,8	,1	, &B0CT01IZ2},	//( - , MDuBz2) Температура АЗ2-2
	{ 66	,8	,1	, &A3MC01RDU},	//( - , DU) Заданная координата положения ИС от регулятора мм
	{ 67	,8	,1	, &A3MC02RDU},	//( - , DU) Температурная корректировка координаты ИМ
	{ 68	,8	,1	, &R0CN91LDU},	//( - , DU) Рассчётная реактивность от регулятора
	{ 69	,8	,1	, &A3MC03RDU},	//( - , DU) Координата положения ИМ 0-й реактивности
	{ 70	,1	,1	, &A3AB15LDU},	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
	{ 71	,1	,1	, &B3IE03LDU},	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
	{ 72	,1	,1	, &B3IE04LDU},	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
	{ 73	,1	,1	, &R0VS11LDU},	//( - , DU) РУ не готова к работе
	{ 74	,1	,1	, &B6AB05LDU},	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
	{ 75	,1	,1	, &R0AB08LDU},	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
	{ 76	,8	,1	, &A1MC01RP1},	//( - , DU) Заданная координата положения ББ1 мм
	{ 77	,8	,1	, &B1MC01RP1},	//( - , DU) Заданная координата положения ББ2  мм
	{ 78	,8	,1	, &A3MC01RP1},	//( - , DU) Заданная координата положения ИС1 мм
	{ 79	,8	,1	, &B3MC01RP1},	//( - , DU) Заданная координата положения ИС2 мм
	{ 80	,8	,1	, &B8MC01RP2},	//( - , DU) Заданная координата АЗ2 мм
	{ 81	,1	,1	, &R0AB09LDU},	//( - , DU) Ошибка в заданной координате ББ1
	{ 82	,1	,1	, &R0AB10LDU},	//( - , DU) Ошибка в заданной координате ББ2
	{ 83	,1	,1	, &R0AB11LDU},	//( - , DU) Ошибка в заданной координате  ИС1
	{ 84	,1	,1	, &R0AB12LDU},	//( - , DU) Ошибка в заданной координате  ИС2
	{ 85	,1	,1	, &R0AB13LDU},	//( - , DU) Ошибка в заданной координате  АЗ2
	{ 86	,1	,1	, &A4ZAV},	//( - , DU) 
	{ 87	,1	,1	, &A6ZAV},	//( - , DU) 
	{ 88	,1	,1	, &R2ZAV},	//( - , DU) 
	{ 89	,1	,1	, &A5ZAV},	//( - , DU) 
	{ 90	,1	,1	, &B8ZAV},	//( - , DU) 
	{ 91	,1	,1	, &A2ZAV},	//( - , DU) Завершение РБ1,2
	{ 92	,1	,1	, &A8ZAV},	//( - , DU) 
	{ 93	,1	,1	, &A9ZAV},	//( - , DU) Завершение НИ ДС1(2)
	{ 94	,1	,1	, &R4ABL},	//( - , DU) Блокировка тележки -
	{ 95	,1	,1	, &B9AB01LDU},	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
	{ 96	,1	,1	, &B9AB02LDU},	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
	{ 97	,1	,1	, &R0AB01LDU},	//( - , DU) Режим проверки разрешён
	{ 98	,1	,1	, &A3IS22LDU},	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
	{ 99	,1	,1	, &B3IS22LDU},	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
	{ 100	,1	,1	, &A2AD33LDU},	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
	{ 101	,1	,1	, &B2AD33LDU},	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
	{ 102	,1	,1	, &A3AD33LDU},	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
	{ 103	,1	,1	, &A3AD34LDU},	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
	{ 104	,1	,1	, &A3AD31LDU},	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
	{ 105	,1	,1	, &B3AD34LDU},	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
	{ 106	,1	,1	, &B3AD31LDU},	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
	{ 107	,1	,1	, &A2IS11LDU},	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
	{ 108	,1	,1	, &B2IS11LDU},	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
	{ 109	,1	,1	, &A3MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
	{ 110	,1	,1	, &A3MD11LP1},	//( - , DU) Кнопка ПУСК ИС1
	{ 111	,1	,1	, &R0MD33LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
	{ 112	,1	,1	, &A1MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
	{ 113	,1	,1	, &A1MD11LP1},	//( - , DU) Кнопка ПУСК ББ1
	{ 114	,3	,1	, &R0MW14IP2},	//( - , DU) Переключатель ОБДУВ
	{ 115	,1	,1	, &A7AP31LDU},	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
	{ 116	,1	,1	, &B7AP31LDU},	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
	{ 117	,3	,1	, &R0MW12IP2},	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
	{ 118	,3	,1	, &B3VS01IDU},	//( - , DU) Готовность к управлению ИС2
	{ 119	,3	,1	, &A2VS01IDU},	//( - , DU) Готовность к управлению РБ1
	{ 120	,3	,1	, &A4VS01IDU},	//( - , DU) Готовность к управлению НИ1
	{ 121	,1	,1	, &A4VS12LDU},	//( - , DU) Движение НИ1 в сторону ВУ
	{ 122	,1	,1	, &A4VS22LDU},	//( - , DU) Движение НИ1 в сторону НУ
	{ 123	,3	,1	, &B4VS01IDU},	//( - , DU) Готовность к управлению НИ2
	{ 124	,1	,1	, &B4VS12LDU},	//( - , DU) Движение НИ2 в сторону ВУ
	{ 125	,1	,1	, &B4VS22LDU},	//( - , DU) Движение НИ2 в сторону НУ
	{ 126	,3	,1	, &A5VS01IDU},	//( - , DU) Готовность к управлению НЛ1
	{ 127	,3	,1	, &B5VS01IDU},	//( - , DU) Готовность к управлению НЛ2
	{ 128	,3	,1	, &A6VS01IDU},	//( - , DU) Готовность к управлению БЗ1
	{ 129	,3	,1	, &R4VS01IDU},	//( - , DU) Готовность к управлению тележкой реактора
	{ 130	,3	,1	, &R2VS01IDU},	//( - , DU) Готовность к управлению МДЗ2
	{ 131	,3	,1	, &R1VS01IDU},	//( - , DU) Готовность к управлению МДЗ1
	{ 132	,1	,1	, &A9IS11LDU},	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
	{ 133	,1	,1	, &A9IS21LDU},	//(vds32:02 - K24VDSR, - ) Приход на НУ НИ ДС1
	{ 134	,1	,1	, &B9IS11LDU},	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
	{ 135	,1	,1	, &B9IS21LDU},	//(vds32:02 - K26VDSR, - ) Приход на НУ НИ ДС2
	{ 136	,1	,1	, &B9AD10LDU},	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
	{ 137	,1	,1	, &A9AD10LDU},	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
	{ 138	,1	,1	, &A9AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ ДС1
	{ 139	,1	,1	, &A9AB01LDU},	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
	{ 140	,1	,1	, &A9AB02LDU},	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
	{ 141	,1	,1	, &B9AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ ДС2
	{ 142	,1	,1	, &A0VT71LZ1},	//( - , MDuBz1) АС по температуре в АЗ1
	{ 143	,1	,1	, &B0VT71LZ1},	//( - , MDuBz1) АС по температуре в АЗ2
	{ 144	,1	,1	, &A0VT71LZ2},	//( - , MDuBz2) АС по температуре в АЗ1
	{ 145	,1	,1	, &B0VT71LZ2},	//( - , MDuBz2) АС по температуре в АЗ2
	{ 146	,1	,1	, &B2VS11LDU},	//( - , DU) Движение РБ2 в сторону ВУ
	{ 147	,1	,1	, &B2VS21LDU},	//( - , DU) Движение РБ2 в сторону НУ
	{ 148	,3	,1	, &B2VS01IDU},	//( - , DU) Готовность к управлению РБ2
	{ 149	,1	,1	, &A7AS31LDU},	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
	{ 150	,1	,1	, &B7AS31LDU},	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
	{ 151	,1	,1	, &A7AZ03LDU},	//( - , DU) Несанкционированное включение обдува АЗ1
	{ 152	,1	,1	, &B7AZ03LDU},	//( - , DU) Несанкционированное включение обдува АЗ2
	{ 153	,1	,1	, &B3MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
	{ 154	,1	,1	, &B3MD11LP1},	//( - , DU) Кнопка ПУСК ИС2
	{ 155	,8	,1	, &R0VL01RDU},	//( - , DU) Индикация Время задержки
	{ 156	,1	,1	, &R0VZ71LZ2},	//(vds32:03 - K22VDSR, DU) Обобщенный сигнал АЗ 2 канала
	{ 157	,1	,1	, &R0VZ71LZ1},	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
	{ 158	,1	,1	, &R0VZ71LDU},	//( - , DU) Обобщенный сигнал АЗ
	{ 159	,1	,1	, &A2IS33LDU},	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
	{ 160	,1	,1	, &A3IS31LDU},	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
	{ 161	,1	,1	, &A3IS33LDU},	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
	{ 162	,1	,1	, &A3IS35LDU},	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
	{ 163	,1	,1	, &A4IS10LDU},	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
	{ 164	,1	,1	, &A1VN71LZ1},	//(vds32:02 - K21VDSR, - ) Блокировка автоматического подъёма ББ
	{ 165	,1	,1	, &A1VN71LZ2},	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{ 166	,1	,1	, &R0MW17LP1},	//( - , DU) Переключатель АВТ/Р
	{ 167	,1	,1	, &R0VW13LDU},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
	{ 168	,1	,1	, &R0VW23LDU},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
	{ 169	,3	,1	, &R0VX08IDU},	//( - , DU) Индикация Режим
	{ 170	,1	,1	, &R0VX09LDU},	//( - , DU) Индикация регулятор мощности включен/отключен
	{ 171	,1	,1	, &R0VS17LDU},	//( - , DU) Индикация выбора АВТОМАТ
	{ 172	,1	,1	, &A2VS32LDU},	//( - , DU) Индикация  СБРОС РБ1
	{ 173	,1	,1	, &B2VS32LDU},	//( - , DU) Индикация  СБРОС РБ2
	{ 174	,1	,1	, &A3VX01LDU},	//( - , DU) Индикация Выстрел ИС1
	{ 175	,1	,1	, &A3IS11LDU},	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
	{ 176	,1	,1	, &B3VX01LDU},	//( - , DU) Индикация Выстрел ИС2
	{ 177	,1	,1	, &R0VS18LDU},	//( - , DU) Индикация  Проверка схем сброса
	{ 178	,1	,1	, &B1MD11LP1},	//( - , DU) Кнопка ПУСК ББ2
	{ 179	,1	,1	, &B1MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
	{ 180	,1	,1	, &B2MD11LP1},	//( - , DU) Кнопка ПУСК РБ2
	{ 181	,1	,1	, &B2MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
	{ 182	,1	,1	, &A2MD11LP1},	//( - , DU) Кнопка ПУСК РБ1
	{ 183	,1	,1	, &A2MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
	{ 184	,1	,1	, &R0IS01LDU},	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
	{ 185	,1	,1	, &R0IS02LDU},	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
	{ 186	,1	,1	, &R0VP73LZ1},	//( - , MDuBz1) ПС давления для РУ
	{ 187	,1	,1	, &R0VP73LZ2},	//( - , MDuBz2) ПС давления для РУ
	{ 188	,1	,1	, &R0VP73LDU},	//( - , DU) ПС давления для РУ
	{ 189	,1	,1	, &R0MD34LP1},	//( - , DU) Кнопка КВИТИРОВАТЬ
	{ 190	,1	,1	, &A0EE02LZ2},	//( - , MDuBz2) Исправность АКНП2
	{ 191	,1	,1	, &A0EE04LZ2},	//( - , MDuBz2) Исправность АКНП4
	{ 192	,1	,1	, &A0VP71LZ1},	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
	{ 193	,1	,1	, &A0VP71LZ2},	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
	{ 194	,1	,1	, &B0VP71LZ1},	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
	{ 195	,1	,1	, &B0VP71LZ2},	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
	{ 196	,1	,1	, &A0VS11LDU},	//( - , DU) АЗ1 готова к работе
	{ 197	,1	,1	, &B0VS11LDU},	//( - , DU) АЗ2 готова к работе
	{ 198	,1	,1	, &A1IE01LDU},	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
	{ 199	,1	,1	, &A3IE01LDU},	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
	{ 200	,1	,1	, &A2IE01LDU},	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
	{ 201	,1	,1	, &A1IE02LDU},	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
	{ 202	,1	,1	, &A3IE02LDU},	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
	{ 203	,1	,1	, &A2IE02LDU},	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
	{ 204	,1	,1	, &B1IE01LDU},	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
	{ 205	,1	,1	, &B2IE01LDU},	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
	{ 206	,1	,1	, &B3IE01LDU},	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
	{ 207	,1	,1	, &B1IE02LDU},	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
	{ 208	,1	,1	, &B3IE02LDU},	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
	{ 209	,1	,1	, &B2IE02LDU},	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
	{ 210	,1	,1	, &R0IE02LDU},	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
	{ 211	,1	,1	, &R0IE01LDU},	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
	{ 212	,1	,1	, &A6IE01LDU},	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
	{ 213	,1	,1	, &A8MC01LC1},	//( - , DU) Настроить энкодер ДС2
	{ 214	,1	,1	, &A8MC01LC2},	//( - , DU) Настроить энкодер ДС2
	{ 215	,1	,1	, &A3VP42LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
	{ 216	,8	,1	, &A3CP02RDU},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
	{ 217	,1	,1	, &A3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
	{ 218	,1	,1	, &B3VP42LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
	{ 219	,8	,1	, &B3CP02RDU},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
	{ 220	,1	,1	, &B3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
	{ 221	,1	,1	, &B3VP82LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
	{ 222	,1	,1	, &A3VP82LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
	{ 223	,3	,1	, &A3IP02IDU},	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
	{ 224	,3	,1	, &B3IP02IDU},	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
	{ 225	,1	,1	, &A0VE01LDU},	//( - , DU) Напряжение в системы АЗ1 подано
	{ 226	,1	,1	, &B0VE01LDU},	//( - , DU) Напряжение в системы АЗ2 подано
	{ 227	,1	,1	, &A0VP01LDU},	//( - , DU) Давление в системы АЗ1 подано
	{ 228	,1	,1	, &B0VP01LDU},	//( - , DU) Давление в системы АЗ2 подано
	{ 229	,1	,1	, &A0EE01LZ1},	//( - , MDuBz1) Исправность АКНП1
	{ 230	,1	,1	, &A0EE03LZ1},	//( - , MDuBz1) Исправность АКНП3
	{ 231	,1	,1	, &A0EE02LZ1},	//( - , MDuBz1) Исправность АКНП2
	{ 232	,1	,1	, &A0EE04LZ1},	//( - , MDuBz1) Исправность АКНП4
	{ 233	,1	,1	, &A0VN01LDU},	//( - , DU) Каналы АЗ1 проверены
	{ 234	,1	,1	, &B0VN01LDU},	//( - , DU) Каналы АЗ2 проверены
	{ 235	,1	,1	, &A0EE01LZ2},	//( - , MDuBz2) Исправность АКНП1
	{ 236	,1	,1	, &A0EE03LZ2},	//( - , MDuBz2) Исправность АКНП3
	{ 237	,1	,1	, &B3VP81LDU},	//( - , MDuS) Давление СПУСК ИС2 в норме
	{ 238	,1	,1	, &R0EE02LDU},	//( - , DU) Питание  АКНП  отключить
	{ 239	,1	,1	, &KKL1},	//( - , - ) 
	{ 240	,1	,1	, &KKL2},	//( - , - ) 
	{ 241	,1	,1	, &KKL3},	//( - , - ) 
	{ 242	,1	,1	, &KKL4},	//( - , - ) 
	{ 243	,1	,1	, &KKL5},	//( - , - ) 
	{ 244	,1	,1	, &KKL6},	//( - , - ) 
	{ 245	,1	,1	, &KKL7},	//( - , - ) 
	{ 246	,1	,1	, &KKL8},	//( - , - ) 
	{ 247	,1	,1	, &KKL9},	//( - , - ) 
	{ 248	,1	,1	, &hz1},	//( - , - ) 
	{ 249	,1	,1	, &hz2},	//( - , - ) 
	{ 250	,1	,1	, &hz3},	//( - , - ) 
	{ 251	,1	,1	, &hz4},	//( - , - ) 
	{ 252	,1	,1	, &hz5},	//( - , - ) 
	{ 253	,1	,1	, &hz6},	//( - , - ) 
	{ 254	,1	,1	, &bd1},	//( - , - ) 
	{ 255	,1	,1	, &bd2},	//( - , - ) 
	{ 256	,1	,1	, &bd3},	//( - , - ) 
	{ 257	,1	,1	, &bd4},	//( - , - ) 
	{ 258	,1	,1	, &bd5},	//( - , - ) 
	{ 259	,1	,1	, &bd6},	//( - , - ) 
	{ 260	,1	,1	, &B6IE01LDU},	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
	{ 261	,1	,1	, &A8IE01LDU},	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
	{ 262	,1	,1	, &B5IE01LDU},	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
	{ 263	,1	,1	, &A5IE02LDU},	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
	{ 264	,1	,1	, &R1IE01LDU},	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
	{ 265	,1	,1	, &R2IE01LDU},	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
	{ 266	,1	,1	, &R6IS61LDU},	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
	{ 267	,1	,1	, &R6IS64LDU},	//( - , MDuS) Исправность ВИП ССДИ-35 1канал
	{ 268	,1	,1	, &R6IS65LDU},	//( - , MDuS) Исправность ВИП ССДИ-35 2канал
	{ 269	,1	,1	, &R6IS62LDU},	//( - , MDuS) Исправность ВИП ССДИ-39 1канал
	{ 270	,1	,1	, &R6IS63LDU},	//( - , MDuS) Исправность ВИП ССДИ-39 2канал
	{ 271	,1	,1	, &R6IS66LZZ},	//( - , MDuS) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 272	,1	,1	, &R6IS67LZZ},	//( - , MDuS) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 273	,1	,1	, &R6IS68LZZ},	//( - , MDuS) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 274	,1	,1	, &syn_R0EE03LDU},	//( - , DU) ВПИС ИС
	{ 275	,8	,1	, &A3VC01RDU},	//( - , DU) Координата ИС1, мм
	{ 276	,8	,1	, &A2VC01RDU},	//( - , DU) Координата РБ1, мм
	{ 277	,8	,1	, &B2VC01RDU},	//( - , DU) Координата РБ2, мм
	{ 278	,8	,1	, &B8VC01RDU},	//( - , DU) Координата АЗ2, мм
	{ 279	,1	,1	, &A4VP82LDU},	//( - , MDuS) Давление ПОДЪЁМ НИ1 в норме
	{ 280	,1	,1	, &B4VP82LDU},	//( - , MDuS) Давление ПОДЪЁМ НИ2 в норме
	{ 281	,1	,1	, &A2VP82LDU},	//( - , MDuS) Давление ПОДЪЁМ РБ1 в норме
	{ 282	,1	,1	, &B2VP82LDU},	//( - , MDuS) Давление ПОДЪЁМ РБ2 в норме
	{ 283	,1	,1	, &A3VP81LDU},	//( - , MDuS) Давление СПУСК ИС1 в норме
	{ 284	,1	,1	, &A3EE03LDU},	//( - , DU) ВПИС ИС1
	{ 285	,1	,1	, &B3EE03LDU},	//( - , DU) ВПИС ИС2
	{ 286	,1	,1	, &B3AB15LDU},	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
	{ 287	,1	,1	, &R5IS21LDU},	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
	{ 288	,1	,1	, &R5VS22LDU},	//( - , DU) Движение ворот отстойной зоны к закрыты
	{ 289	,1	,1	, &R5VS12LDU},	//( - , DU) Движение ворот отстойной зоны к открыты
	{ 290	,3	,1	, &R5VS01IDU},	//( - , DU) Готовность к управлению ворот отстойной зоны
	{ 291	,1	,1	, &R3VS22LDU},	//( - , DU) Движение гомогенных дверей к закрыты
	{ 292	,1	,1	, &R3VS12LDU},	//( - , DU) Движение гомогенных дверей к открыты
	{ 293	,3	,1	, &R3VS01IDU},	//( - , DU) Готовность к управлению гомогенных дверей
	{ 294	,1	,1	, &A3AB13LDU},	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
	{ 295	,1	,1	, &syn_A3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
	{ 296	,1	,1	, &B3AB13LDU},	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
	{ 297	,1	,1	, &syn_B3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
	{ 298	,3	,1	, &R0DE02LDU},	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
	{ 299	,3	,1	, &R0DE03LDU},	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
	{ 300	,3	,1	, &R0DE04LDU},	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
	{ 301	,3	,1	, &R0DE08LDU},	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
	{ 302	,3	,1	, &R0DE05LDU},	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
	{ 303	,3	,1	, &R0DE09LDU},	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
	{ 304	,3	,1	, &R0DE0ALDU},	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
	{ 305	,3	,1	, &R0DE07LDU},	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
	{ 306	,3	,1	, &R0DE0CLDU},	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
	{ 307	,1	,1	, &R0AB20LDU},	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
	{ 308	,8	,1	, &R0CN92LDU},	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
	{ 309	,8	,1	, &R0VN11RDU},	//( - , DU) Текущая мощность РУ
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
	{ 331	,5	,1	, &B2IC01UDU},	//( - , MDuS) Координата штока РБ2 (дел.энк)
	{ 332	,5	,1	, &A3IC01UDU},	//( - , MDuS) Координата штока ИС1 (дел.энк)
	{ 333	,5	,1	, &B3IC01UDU},	//( - , MDuS) Координата штока ИС2 (дел.энк)
	{ 334	,8	,1	, &B3VC01RDU},	//( - , DU) Координата ИС2, мм
	{ 335	,5	,1	, &A8IC01UDU},	//( - , MDuS) Координата ДС2 (дел.энк)
	{ 336	,8	,1	, &A8VC01RDU},	//( - , DU) Координата ДС2, мм
	{ 337	,5	,1	, &B8IC01UDU},	//( - , MDuS) Координата АЗ2 (дел.энк)
	{ 338	,5	,1	, &A1IC01UDU},	//( - , MDuS) Координата штока ББ1 (дел.энк)
	{ 339	,8	,1	, &A1VC01RDU},	//( - , DU) Координата ББ1, мм
	{ 340	,1	,1	, &A1IS11LDU},	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
	{ 341	,1	,1	, &B1MC01LC1},	//( - , DU) Настроить энкодер ББ2
	{ 342	,1	,1	, &B1MC01LC2},	//( - , DU) Настроить энкодер ББ2
	{ 343	,1	,1	, &A1MC01LC1},	//( - , DU) Настроить энкодер ББ1
	{ 344	,1	,1	, &A1MC01LC2},	//( - , DU) Настроить энкодер ББ1
	{ 345	,1	,1	, &B2MC01LC1},	//( - , DU) Настроить энкодер РБ2
	{ 346	,1	,1	, &B2MC01LC2},	//( - , DU) Настроить энкодер РБ2
	{ 347	,1	,1	, &A2MC01LC1},	//( - , DU) Настроить энкодер РБ1
	{ 348	,1	,1	, &A2MC01LC2},	//( - , DU) Настроить энкодер РБ1
	{ 349	,1	,1	, &B3MC01LC1},	//( - , DU) Настроить энкодер ИС2
	{ 350	,1	,1	, &B3MC01LC2},	//( - , DU) Настроить энкодер ИС2
	{ 351	,1	,1	, &A3MC01LC1},	//( - , DU) Настроить энкодер ИС1
	{ 352	,1	,1	, &A3MC01LC2},	//( - , DU) Настроить энкодер ИС1
	{ 353	,1	,1	, &B8MC01LC1},	//( - , DU) Настроить энкодер АЗ2
	{ 354	,1	,1	, &B8MC01LC2},	//( - , DU) Настроить энкодер АЗ2
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
	{ 370	,1	,1	, &R0DEB1LDU},	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
	{ 371	,1	,1	, &R0DEB4LDU},	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
	{ 372	,1	,1	, &R0DE3DLDU},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
	{ 373	,1	,1	, &R0DE3CLDU},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
	{ 374	,1	,1	, &TestDiagnDU},	//( - , DU) Неисправность от
	{ 375	,5	,1	, &B1IC01UDU},	//( - , MDuS) Координата штока ББ2 (дел.энк)
	{ 376	,8	,1	, &B1VC01RDU},	//( - , DU) Координата ББ2, мм
	{ 377	,1	,1	, &B1IS11LDU},	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
	{ 378	,5	,1	, &A2IC01UDU},	//( - , MDuS) Координата штока РБ1 (дел.энк)
	{ 379	,1	,1	, &B6AB06LDU},	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
	{ 380	,1	,1	, &B6AB07LDU},	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
	{ 381	,1	,1	, &B6AB08LDU},	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
	{ 382	,1	,1	, &B6AB09LDU},	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
	{ 383	,1	,1	, &A6AB05LDU},	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
	{ 384	,1	,1	, &B8VS12LDU},	//( - , DU) Движение АЗ2 в сторону ВУ
	{ 385	,8	,1	, &B8CV01RDU},	//( - , DU) Измеренная скорость перемещения АЗ2
	{ 386	,1	,1	, &B8AB06LDU},	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
	{ 387	,1	,1	, &B8AB07LDU},	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
	{ 388	,1	,1	, &B8AB05LDU},	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
	{ 389	,1	,1	, &B8VS22LDU},	//( - , DU) Движение АЗ2 в сторону НУ
	{ 390	,1	,1	, &B8AZ03LDU},	//( - , DU) Несанкционированное перемещение АЗ2
	{ 391	,1	,1	, &R0MD11LP1},	//( - , DU) Кнопка ПУСК
	{ 392	,1	,1	, &B8AD10LDU},	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
	{ 393	,1	,1	, &B8AD20LDU},	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
	{ 394	,1	,1	, &B8IS11LDU},	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
	{ 395	,1	,1	, &B8AB01LDU},	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
	{ 396	,1	,1	, &B8AB04LDU},	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
	{ 397	,1	,1	, &B8AB08LDU},	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
	{ 398	,1	,1	, &B8AB09LDU},	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
	{ 399	,1	,1	, &B8AB10LDU},	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
	{ 400	,1	,1	, &B8AB11LDU},	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
	{ 401	,1	,1	, &B8AB12LDU},	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
	{ 402	,1	,1	, &B5AZ03LDU},	//( - , DU) Несанкционированное перемещение НЛ2
	{ 403	,1	,1	, &B5AB01LDU},	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
	{ 404	,1	,1	, &B5AB02LDU},	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
	{ 405	,1	,1	, &A4IS21LDU},	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
	{ 406	,1	,1	, &B4IS21LDU},	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
	{ 407	,1	,1	, &B4AD10LDU},	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
	{ 408	,1	,1	, &A4AD10LDU},	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
	{ 409	,1	,1	, &A4AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ1
	{ 410	,1	,1	, &A4AB01LDU},	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
	{ 411	,1	,1	, &A4AB02LDU},	//( - , DU) Блокировка движения НИ1 - Нет перемещения
	{ 412	,1	,1	, &B4AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ2
	{ 413	,1	,1	, &B4AB01LDU},	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
	{ 414	,1	,1	, &B4AB02LDU},	//( - , DU) Блокировка движения НИ2 - Нет перемещения
	{ 415	,1	,1	, &A5AB04LDU},	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
	{ 416	,1	,1	, &B5AB04LDU},	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
	{ 417	,1	,1	, &A1IS12LDU},	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
	{ 418	,1	,1	, &A2IS12LDU},	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
	{ 419	,1	,1	, &B1IS12LDU},	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
	{ 420	,1	,1	, &B2IS12LDU},	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
	{ 421	,1	,1	, &R4IS11LDU},	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
	{ 422	,1	,1	, &A6AB06LDU},	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
	{ 423	,1	,1	, &A6AB07LDU},	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
	{ 424	,1	,1	, &A6AB08LDU},	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
	{ 425	,1	,1	, &A6AB09LDU},	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
	{ 426	,1	,1	, &A8AB01LDU},	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
	{ 427	,1	,1	, &A2VS11LDU},	//( - , DU) Движение РБ1 в сторону ВУ
	{ 428	,8	,1	, &A2CV01RDU},	//( - , DU) Измеренная скорость перемещения РБ1
	{ 429	,1	,1	, &A2AB04LDU},	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
	{ 430	,1	,1	, &A2AB02LDU},	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
	{ 431	,1	,1	, &A2AB01LDU},	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
	{ 432	,1	,1	, &A2VS21LDU},	//( - , DU) Движение РБ1 в сторону НУ
	{ 433	,1	,1	, &A2AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
	{ 434	,1	,1	, &A2AD11LDU},	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
	{ 435	,1	,1	, &A2AD21LDU},	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
	{ 436	,1	,1	, &A2AD02LDU},	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
	{ 437	,1	,1	, &A2AD03LDU},	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
	{ 438	,1	,1	, &A2AD04LDU},	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
	{ 439	,1	,1	, &A2AD05LDU},	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
	{ 440	,1	,1	, &A2AB07LDU},	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
	{ 441	,1	,1	, &A2AB08LDU},	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
	{ 442	,1	,1	, &A2AB05LDU},	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
	{ 443	,1	,1	, &A2AB06LDU},	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
	{ 444	,1	,1	, &A2AB09LDU},	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
	{ 445	,1	,1	, &A2AB10LDU},	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
	{ 446	,1	,1	, &A2AB11LDU},	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
	{ 447	,1	,1	, &A2AB12LDU},	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 448	,1	,1	, &A2AB13LDU},	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
	{ 449	,1	,1	, &B8AB13LDU},	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
	{ 450	,1	,1	, &B8AB14LDU},	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
	{ 451	,1	,1	, &B8AB02LDU},	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
	{ 452	,1	,1	, &A8VS12LDU},	//( - , DU) Движение ДС2 в сторону ВУ
	{ 453	,8	,1	, &A8CV01RDU},	//( - , DU) Измеренная скорость перемещения ДС2
	{ 454	,1	,1	, &A8AB06LDU},	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
	{ 455	,1	,1	, &A8AB07LDU},	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
	{ 456	,1	,1	, &A8AB05LDU},	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
	{ 457	,1	,1	, &A8VS22LDU},	//( - , DU) Движение ДС2 в сторону НУ
	{ 458	,1	,1	, &A8AZ03LDU},	//( - , DU) Несанкционированное перемещение ДС2
	{ 459	,1	,1	, &A8AD10LDU},	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
	{ 460	,1	,1	, &A8AD20LDU},	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
	{ 461	,1	,1	, &B8IS22LDU},	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
	{ 462	,1	,1	, &A8IS12LDU},	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
	{ 463	,1	,1	, &A8AB04LDU},	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
	{ 464	,1	,1	, &A8IS22LDU},	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
	{ 465	,1	,1	, &A8AB08LDU},	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
	{ 466	,1	,1	, &A8AB09LDU},	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
	{ 467	,1	,1	, &A8AB10LDU},	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
	{ 468	,1	,1	, &A8AB11LDU},	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
	{ 469	,1	,1	, &A8AB12LDU},	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
	{ 470	,1	,1	, &A8AB13LDU},	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
	{ 471	,1	,1	, &A8AB14LDU},	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
	{ 472	,1	,1	, &A8AB02LDU},	//( - , DU) Блокировка движения ДС2- АНИ не установлен
	{ 473	,1	,1	, &A6VS22LDU},	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
	{ 474	,1	,1	, &A6VS12LDU},	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
	{ 475	,1	,1	, &B6VS22LDU},	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
	{ 476	,1	,1	, &B6VS12LDU},	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
	{ 477	,1	,1	, &A6AD10LDU},	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
	{ 478	,1	,1	, &A6AD20LDU},	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
	{ 479	,1	,1	, &B6AD10LDU},	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
	{ 480	,1	,1	, &B6AD20LDU},	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
	{ 481	,1	,1	, &A6AZ03LDU},	//( - , DU) Несанкционированное перемещение БЗ1
	{ 482	,1	,1	, &A6AB01LDU},	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
	{ 483	,1	,1	, &A6AB02LDU},	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
	{ 484	,1	,1	, &B6AZ03LDU},	//( - , DU) Несанкционированное перемещение БЗ2
	{ 485	,1	,1	, &B6AB01LDU},	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
	{ 486	,1	,1	, &B6AB02LDU},	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
	{ 487	,1	,1	, &A6AB04LDU},	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
	{ 488	,1	,1	, &B6AB04LDU},	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
	{ 489	,1	,1	, &R4AB01LDU},	//( - , DU) Блокировка движения тележки - АНИ не установлен
	{ 490	,1	,1	, &R8IS11LDU},	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
	{ 491	,1	,1	, &R6IS21LDU},	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
	{ 492	,1	,1	, &A0VN71LZ2},	//( - , MDuBz2) АЗ по АС мощности для АЗ1
	{ 493	,1	,1	, &A0VN71LZ1},	//( - , MDuBz1) АЗ по АС мощности для АЗ1
	{ 494	,1	,1	, &R0NE01LDU},	//( - , DU) Потеря связи с БАЗ1
	{ 495	,1	,1	, &R0NE02LDU},	//( - , DU) Потеря связи с БАЗ2
	{ 496	,3	,1	, &R0MW15IP1},	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
	{ 497	,3	,1	, &R0MW14IP1},	//( - , DU) Переключатель ПРОГРАММЫ
	{ 498	,3	,1	, &R0MW12IP1},	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
	{ 499	,3	,1	, &R0MW13IP1},	//( - , DU) Переключатель ВЫБОР ЗОН
	{ 500	,3	,1	, &R0MW16IP1},	//( - , DU) Переключатель ВИД ПРОВЕРКИ
	{ 501	,3	,1	, &R0MW11IP1},	//( - , DU) Переключатель ВЫСТРЕЛ
	{ 502	,3	,1	, &R0MW11IP2},	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
	{ 503	,1	,1	, &R0MW13LP2},	//( - , DU) Переключатель СЕТЬ
	{ 504	,1	,1	, &R0MD32LP1},	//( - , DU) Кнопка СПУСК
	{ 505	,1	,1	, &R0MD31LP1},	//( - , DU) Кнопка СТОП
	{ 506	,1	,1	, &A1IS21LDU},	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
	{ 507	,1	,1	, &A2IS21LDU},	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
	{ 508	,1	,1	, &A3IS21LDU},	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
	{ 509	,1	,1	, &B1IS21LDU},	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
	{ 510	,1	,1	, &B2IS21LDU},	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
	{ 511	,1	,1	, &B3IS21LDU},	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
	{ 512	,1	,1	, &R0ES01LDU},	//( - , DU) ОРР не в исходном состоянии
	{ 513	,1	,1	, &R4MD11LP2},	//( - , DU) Кнопка ВПЕРЁД  (тележки)
	{ 514	,1	,1	, &R4MD31LP2},	//( - , DU) Кнопка СТОП  (тележки)
	{ 515	,1	,1	, &R4MD21LP2},	//( - , DU) Кнопка НАЗАД  (тележки)
	{ 516	,1	,1	, &A6IS11LDU},	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
	{ 517	,1	,1	, &A6IS21LDU},	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
	{ 518	,1	,1	, &B6IS11LDU},	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
	{ 519	,1	,1	, &B6IS21LDU},	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
	{ 520	,1	,1	, &R4AB13LDU},	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
	{ 521	,1	,1	, &R4AB14LDU},	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
	{ 522	,1	,1	, &R4AB15LDU},	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
	{ 523	,1	,1	, &R5IS11LDU},	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
	{ 524	,1	,1	, &R4AB16LDU},	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
	{ 525	,1	,1	, &R4AB17LDU},	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
	{ 526	,1	,1	, &R4AB18LDU},	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
	{ 527	,1	,1	, &R4AD10LDU},	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
	{ 528	,1	,1	, &R4AD20LDU},	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
	{ 529	,1	,1	, &A5VS22LDU},	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
	{ 530	,1	,1	, &A5VS12LDU},	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
	{ 531	,1	,1	, &B5VS22LDU},	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
	{ 532	,1	,1	, &B5VS12LDU},	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
	{ 533	,1	,1	, &B5AD10LDU},	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
	{ 534	,1	,1	, &B5AD20LDU},	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
	{ 535	,1	,1	, &A5AD10LDU},	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
	{ 536	,1	,1	, &A5AD20LDU},	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
	{ 537	,1	,1	, &A5IS11LDU},	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
	{ 538	,1	,1	, &A5IS21LDU},	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
	{ 539	,1	,1	, &B5IS11LDU},	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
	{ 540	,1	,1	, &B5IS21LDU},	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
	{ 541	,1	,1	, &A5AZ03LDU},	//( - , DU) Несанкционированное перемещение НЛ1
	{ 542	,1	,1	, &A5AB01LDU},	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
	{ 543	,1	,1	, &A5AB02LDU},	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
	{ 544	,1	,1	, &R4AB02LDU},	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
	{ 545	,1	,1	, &R0NE08LDU},	//( - , DU) Потеря связи с ОПУ
	{ 546	,1	,1	, &R4IS21LDU},	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
	{ 547	,1	,1	, &R4IS22LDU},	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
	{ 548	,1	,1	, &R4IS12LDU},	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
	{ 549	,1	,1	, &R4VS22LDU},	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
	{ 550	,1	,1	, &R4VS12LDU},	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
	{ 551	,1	,1	, &R4AZ03LDU},	//( - , DU) Несанкционированное перемещение тележки
	{ 552	,1	,1	, &R4AB03LDU},	//( - , DU) Блокировка движения тележки - Самоход любого механизма
	{ 553	,1	,1	, &R1IS21LDU},	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
	{ 554	,1	,1	, &R2IS21LDU},	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
	{ 555	,1	,1	, &R4AB04LDU},	//( - , DU) Блокировка движения тележки - Превышение времени движения
	{ 556	,1	,1	, &R4AB05LDU},	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
	{ 557	,1	,1	, &R4AB06LDU},	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
	{ 558	,1	,1	, &R4AB07LDU},	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
	{ 559	,1	,1	, &R4AB08LDU},	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
	{ 560	,1	,1	, &R4AB09LDU},	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
	{ 561	,1	,1	, &B0VN71LZ1},	//( - , MDuBz1) АЗ по АС мощности для АЗ2
	{ 562	,1	,1	, &B0VN71LZ2},	//( - , MDuBz2) АЗ по АС мощности для АЗ2
	{ 563	,1	,1	, &R4AB10LDU},	//( - , DU) Блокировка тележки - не открыта биологическая защита
	{ 564	,1	,1	, &R4AB11LDU},	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
	{ 565	,1	,1	, &R4AB12LDU},	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
	{ 566	,1	,1	, &A4IS11LDU},	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
	{ 567	,1	,1	, &B4IS11LDU},	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
	{ 568	,1	,1	, &A3AB05LDU},	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
	{ 569	,1	,1	, &A3AB06LDU},	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
	{ 570	,1	,1	, &A3AB09LDU},	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
	{ 571	,1	,1	, &A3AB10LDU},	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
	{ 572	,1	,1	, &A3AB11LDU},	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
	{ 573	,1	,1	, &A3AB12LDU},	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 574	,1	,1	, &A3AB14LDU},	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
	{ 575	,1	,1	, &A3AB16LDU},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
	{ 576	,1	,1	, &A3AB17LDU},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
	{ 577	,1	,1	, &A3AB18LDU},	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
	{ 578	,1	,1	, &A3AB20LDU},	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
	{ 579	,1	,1	, &B3VS12LDU},	//( - , DU) Движение ИС2 в сторону ВУ
	{ 580	,8	,1	, &B3CV01RDU},	//( - , DU) Измеренная скорость перемещения ИС2
	{ 581	,1	,1	, &B3AB04LDU},	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
	{ 582	,1	,1	, &B3AB02LDU},	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
	{ 583	,1	,1	, &B3AB01LDU},	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
	{ 584	,1	,1	, &B3VS22LDU},	//( - , DU) Движение ИС2 в сторону НУ
	{ 585	,1	,1	, &B3AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
	{ 586	,1	,1	, &B3AD11LDU},	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
	{ 587	,1	,1	, &B3AD21LDU},	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
	{ 588	,1	,1	, &B3AD02LDU},	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
	{ 589	,1	,1	, &B3AD03LDU},	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
	{ 590	,1	,1	, &B3AD04LDU},	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
	{ 591	,1	,1	, &B1AB11LDU},	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
	{ 592	,1	,1	, &B1AB12LDU},	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 593	,1	,1	, &B1AB13LDU},	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
	{ 594	,1	,1	, &B1AB14LDU},	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
	{ 595	,1	,1	, &B1AB16LDU},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
	{ 596	,1	,1	, &B1AB17LDU},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
	{ 597	,1	,1	, &B1AB18LDU},	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
	{ 598	,1	,1	, &A3VS12LDU},	//( - , DU) Движение ИС1 в сторону ВУ
	{ 599	,8	,1	, &A3CV01RDU},	//( - , DU) Измеренная скорость перемещения ИС1
	{ 600	,1	,1	, &A3AB04LDU},	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
	{ 601	,1	,1	, &A3AB02LDU},	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
	{ 602	,1	,1	, &A3AB01LDU},	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
	{ 603	,1	,1	, &A3VS22LDU},	//( - , DU) Движение ИС1 в сторону НУ
	{ 604	,1	,1	, &A3AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
	{ 605	,1	,1	, &A3AD11LDU},	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
	{ 606	,1	,1	, &A3AD21LDU},	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
	{ 607	,1	,1	, &A3AD02LDU},	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
	{ 608	,1	,1	, &A3AD03LDU},	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
	{ 609	,1	,1	, &A3AD04LDU},	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
	{ 610	,1	,1	, &A3AD05LDU},	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
	{ 611	,1	,1	, &A3AD01LDU},	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
	{ 612	,8	,1	, &A3CV02RDU},	//( - , DU) Заданная скорость перемещения ИС1
	{ 613	,1	,1	, &A3AB07LDU},	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
	{ 614	,1	,1	, &A3AB08LDU},	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
	{ 615	,1	,1	, &A1AD32LDU},	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
	{ 616	,1	,1	, &B1AD32LDU},	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
	{ 617	,1	,1	, &R0MD11LP2},	//( - , DU) Кнопка Пуск проверки схем сброса
	{ 618	,1	,1	, &R0VX01LDU},	//( - , DU) ДО ИМПУЛЬСА
	{ 619	,3	,1	, &R0VL01IDU},	//( - , DU) До импульса минут
	{ 620	,3	,1	, &R0VL11IDU},	//( - , DU) До импульса секунд
	{ 621	,8	,1	, &R0VL06RDU},	//( - , DU) Индикация (Время задержки от ВУ РБ)
	{ 622	,1	,1	, &B3AD33LDU},	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 закрыть (обесточить)
	{ 623	,1	,1	, &B3IS11LDU},	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
	{ 624	,8	,1	, &R0VL02RDU},	//( - , DU) Индикация (Время задержки ИНИ)
	{ 625	,1	,1	, &R8AD21LDU},	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
	{ 626	,1	,1	, &R0AD14LDU},	//( - , DU) Имитация срабатывания верхней АС II УР
	{ 627	,8	,1	, &R0VL04RDU},	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
	{ 628	,1	,1	, &R0AB04LDU},	//( - , DU) Нарушение времени срабатывания верхней АС II УР
	{ 629	,1	,1	, &R0AB06LDU},	//( - , DU) Нарушение времени задержки от ВУ РБ
	{ 630	,1	,1	, &R0AB02LDU},	//( - , DU) Нарушение времени задержки ИНИ
	{ 631	,8	,1	, &R0VL03RDU},	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
	{ 632	,8	,1	, &R0VL05RDU},	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
	{ 633	,3	,1	, &R0VL21IDU},	//( - , DU) Декатрон
	{ 634	,1	,1	, &R0VX03LDU},	//( - , DU) Готовность 2 мин
	{ 635	,3	,1	, &R0VS21IDU},	//( - , DU) Индикация ВИД ПРОВЕРКИ
	{ 636	,3	,1	, &A1VS01IDU},	//( - , DU) Готовность к управлению ББ1
	{ 637	,3	,1	, &B1VS01IDU},	//( - , DU) Готовность к управлению ББ2
	{ 638	,3	,1	, &A3VS01IDU},	//( - , DU) Готовность к управлению ИС1
	{ 639	,1	,1	, &B3AD05LDU},	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
	{ 640	,1	,1	, &B3AD01LDU},	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
	{ 641	,8	,1	, &B3CV02RDU},	//( - , DU) Заданная скорость перемещения ИС2
	{ 642	,1	,1	, &B3AB07LDU},	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
	{ 643	,1	,1	, &B3AB08LDU},	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
	{ 644	,1	,1	, &B3AB05LDU},	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
	{ 645	,1	,1	, &B3AB06LDU},	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
	{ 646	,1	,1	, &B3AB09LDU},	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
	{ 647	,1	,1	, &B3AB10LDU},	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
	{ 648	,1	,1	, &B3AB11LDU},	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
	{ 649	,1	,1	, &B3AB12LDU},	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{ 650	,1	,1	, &B3AB14LDU},	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
	{ 651	,1	,1	, &B3AB16LDU},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
	{ 652	,1	,1	, &B3AB17LDU},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
	{ 653	,1	,1	, &B3AB18LDU},	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
	{ 654	,1	,1	, &B3AB20LDU},	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
	{ 655	,1	,1	, &C1MD31LP1},	//( - , DU) Кнопка СБРОС ББ
	{ 656	,1	,1	, &C1MD31LP2},	//( - , DU) Кнопка СБРОС ББ
	{ 657	,1	,1	, &A2AD31LDU},	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
	{ 658	,1	,1	, &B2AD31LDU},	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
	{ 659	,1	,1	, &A1AD31LDU},	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
	{ 660	,1	,1	, &B1AD31LDU},	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
	{ 661	,1	,1	, &A2AD32LDU},	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
	{ 662	,1	,1	, &B2AD32LDU},	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
	{ 663	,1	,1	, &B2AB11LDU},	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
	{ 664	,1	,1	, &B2AB12LDU},	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{ 665	,1	,1	, &B2AB13LDU},	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
	{ 666	,1	,1	, &B2AB14LDU},	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
	{ 667	,1	,1	, &B2AB16LDU},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
	{ 668	,1	,1	, &B2AB17LDU},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
	{ 669	,1	,1	, &R1AZ03LDU},	//( - , DU) Несанкционированное перемещение МДЗ1
	{ 670	,1	,1	, &R1AB01LDU},	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
	{ 671	,1	,1	, &R1AB02LDU},	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
	{ 672	,1	,1	, &R2AZ03LDU},	//( - , DU) Несанкционированное перемещение МДЗ2
	{ 673	,1	,1	, &R2AB01LDU},	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
	{ 674	,1	,1	, &R2AB02LDU},	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
	{ 675	,1	,1	, &R1AB04LDU},	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
	{ 676	,1	,1	, &R2AB04LDU},	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
	{ 677	,1	,1	, &R1AD10LDU},	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
	{ 678	,1	,1	, &R1AD20LDU},	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
	{ 679	,1	,1	, &R1IS11LDU},	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
	{ 680	,1	,1	, &R1VS22LDU},	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
	{ 681	,1	,1	, &R2VS22LDU},	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
	{ 682	,1	,1	, &R2VS12LDU},	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
	{ 683	,1	,1	, &R1VS12LDU},	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
	{ 684	,1	,1	, &R2IS11LDU},	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
	{ 685	,1	,1	, &A1VS12LDU},	//( - , DU) Движение ББ1 в сторону ВУ
	{ 686	,1	,1	, &A2AB14LDU},	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
	{ 687	,1	,1	, &A2AB16LDU},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
	{ 688	,1	,1	, &A2AB17LDU},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
	{ 689	,1	,1	, &A2AD01LDU},	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
	{ 690	,8	,1	, &A2CV02RDU},	//( - , DU) Заданная скорость перемещения РБ1
	{ 691	,8	,1	, &B2CV01RDU},	//( - , DU) Измеренная скорость перемещения РБ2
	{ 692	,1	,1	, &B2AB04LDU},	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
	{ 693	,1	,1	, &B2AB02LDU},	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
	{ 694	,1	,1	, &B2AB01LDU},	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
	{ 695	,1	,1	, &B2AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
	{ 696	,1	,1	, &B2AD11LDU},	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
	{ 697	,1	,1	, &B2AD21LDU},	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
	{ 698	,1	,1	, &B2AD02LDU},	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
	{ 699	,1	,1	, &B2AD03LDU},	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
	{ 700	,1	,1	, &B2AD04LDU},	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
	{ 701	,1	,1	, &B2AD05LDU},	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
	{ 702	,1	,1	, &B2AD01LDU},	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
	{ 703	,8	,1	, &B2CV02RDU},	//( - , DU) Заданная скорость перемещения РБ2
	{ 704	,1	,1	, &B2AB07LDU},	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
	{ 705	,1	,1	, &B2AB08LDU},	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
	{ 706	,1	,1	, &B2AB05LDU},	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
	{ 707	,1	,1	, &B2AB06LDU},	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
	{ 708	,1	,1	, &B2AB09LDU},	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
	{ 709	,1	,1	, &B2AB10LDU},	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
	{ 710	,1	,1	, &A1AB16LDU},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
	{ 711	,1	,1	, &A1AB17LDU},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
	{ 712	,1	,1	, &A1AB18LDU},	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
	{ 713	,1	,1	, &B1VS12LDU},	//( - , DU) Движение ББ2 в сторону ВУ
	{ 714	,8	,1	, &B1CV01RDU},	//( - , DU) Измеренная скорость перемещения ББ2
	{ 715	,1	,1	, &B1AB04LDU},	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
	{ 716	,1	,1	, &B1AB02LDU},	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
	{ 717	,1	,1	, &B1AB01LDU},	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
	{ 718	,1	,1	, &B1VS22LDU},	//( - , DU) Движение ББ2 в сторону НУ
	{ 719	,1	,1	, &B1AZ03LDU},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
	{ 720	,1	,1	, &B1AD11LDU},	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
	{ 721	,1	,1	, &B1AD21LDU},	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
	{ 722	,1	,1	, &B1AD02LDU},	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
	{ 723	,1	,1	, &B1AD03LDU},	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
	{ 724	,1	,1	, &B1AD04LDU},	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
	{ 725	,1	,1	, &B1AD05LDU},	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
	{ 726	,1	,1	, &B1AD01LDU},	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
	{ 727	,8	,1	, &B1CV02RDU},	//( - , DU) Заданная скорость перемещения ББ2
	{ 728	,1	,1	, &B1AB07LDU},	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
	{ 729	,1	,1	, &B1AB08LDU},	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
	{ 730	,1	,1	, &B1AB05LDU},	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
	{ 731	,1	,1	, &B1AB06LDU},	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
	{ 732	,1	,1	, &B1AB09LDU},	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
	{ 733	,1	,1	, &B1AB10LDU},	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
	{ 734	,8	,1	, &A1CV01RDU},	//( - , DU) Измеренная скорость перемещения ББ1
	{ 735	,1	,1	, &A1AB04LDU},	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
	{ 736	,1	,1	, &A1AB02LDU},	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
	{ 737	,1	,1	, &A1AB01LDU},	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
	{ 738	,1	,1	, &A1VS22LDU},	//( - , DU) Движение ББ1 в сторону НУ
	{ 739	,1	,1	, &A1AZ03LDU},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
	{ 740	,1	,1	, &A1AD11LDU},	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
	{ 741	,1	,1	, &A1AD21LDU},	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
	{ 742	,1	,1	, &A1AD02LDU},	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
	{ 743	,1	,1	, &A1AD03LDU},	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
	{ 744	,1	,1	, &A1AD04LDU},	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
	{ 745	,1	,1	, &A1AD05LDU},	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
	{ 746	,1	,1	, &A1AD01LDU},	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
	{ 747	,8	,1	, &A1CV02RDU},	//( - , DU) Заданная скорость перемещения ББ1
	{ 748	,1	,1	, &A1AB07LDU},	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
	{ 749	,1	,1	, &A1AB08LDU},	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
	{ 750	,1	,1	, &A1AB05LDU},	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
	{ 751	,1	,1	, &A1AB06LDU},	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
	{ 752	,1	,1	, &A1AB09LDU},	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
	{ 753	,1	,1	, &A1AB10LDU},	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
	{ 754	,1	,1	, &A1AB11LDU},	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
	{ 755	,1	,1	, &A1AB12LDU},	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 756	,1	,1	, &A1AB13LDU},	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
	{ 757	,1	,1	, &A1AB14LDU},	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
	{ 758	,8	,1	, &fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
	{ 759	,5	,1	, &dEM_A1UC05UDU},	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
	{ 760	,5	,1	, &dEM_A1UC06UDU},	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
	{ 761	,5	,1	, &dEM_A2UC06UDU},	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
	{ 762	,5	,1	, &dEM_A2UC05UDU},	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
	{ 763	,8	,1	, &fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
	{ 764	,5	,1	, &dEM_A3UC06UDU},	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
	{ 765	,5	,1	, &dEM_A3UC05UDU},	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
	{ 766	,8	,1	, &fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
	{ 767	,5	,1	, &dEM_A8UC06UDU},	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
	{ 768	,8	,1	, &fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
	{ 769	,5	,1	, &dEM_A8UC05UDU},	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
	{ 770	,8	,1	, &fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{ 771	,8	,1	, &fEM_R0UV82RDU},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{ 772	,8	,1	, &fEM_R0UV83RDU},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{ 773	,8	,1	, &fEM_R0UV84RDU},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{ 774	,8	,1	, &fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 775	,8	,1	, &fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{ 776	,8	,1	, &fEM_R0UV87RDU},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 777	,8	,1	, &fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{ 778	,8	,1	, &fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{ 779	,8	,1	, &fEM_A3UP43RDU},	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
	{ 780	,8	,1	, &fEM_A3UP44RDU},	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
	{ 781	,8	,1	, &fEM_A3UP53RDU},	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
	{ 782	,8	,1	, &fEM_A3UP85RDU},	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 783	,8	,1	, &fEM_A3UP88RDU},	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 784	,8	,1	, &fEM_A3UP86RDU},	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 785	,8	,1	, &fEM_B8UV01RDU},	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
	{ 786	,8	,1	, &fEM_B8UV02RDU},	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
	{ 787	,8	,1	, &fEM_B8UV03RDU},	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
	{ 788	,8	,1	, &fEM_B8UL04RDU},	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
	{ 789	,3	,1	, &iEM_A2UV03CDU},	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
	{ 790	,8	,1	, &fEM_A2UV01RDU},	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
	{ 791	,8	,1	, &fEM_A2UV02RDU},	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
	{ 792	,8	,1	, &fEM_A1UV01RDU},	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
	{ 793	,8	,1	, &fEM_A1UV02RDU},	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
	{ 794	,8	,1	, &fEM_A1UC06RDU},	//(A1UC06RDU) Уставка определения самохода ББ  мм
	{ 795	,8	,1	, &fEM_A1UC05RDU},	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
	{ 796	,8	,1	, &fEM_A1UL04RDU},	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
	{ 797	,8	,1	, &fEM_A3UV01RDU},	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
	{ 798	,8	,1	, &fEM_A3UV02RDU},	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
	{ 799	,8	,1	, &fEM_A3UC06RDU},	//(A3UC06RDU) Уставка определения самохода ИС1  мм
	{ 800	,8	,1	, &fEM_A3UC05RDU},	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
	{ 801	,8	,1	, &fEM_A3UL04RDU},	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
	{ 802	,8	,1	, &fEM_A3UP54RDU},	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
	{ 803	,8	,1	, &fEM_A3UP87RDU},	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 804	,8	,1	, &fEM_R0UL05RDU},	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
	{ 805	,8	,1	, &fEM_R0UL20RDU},	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
	{ 806	,8	,1	, &fEM_B8UV04RDU},	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
	{ 807	,8	,1	, &fEM_B8UC06RDU},	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
	{ 808	,8	,1	, &fEM_B8UC05RDU},	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
	{ 809	,8	,1	, &fEM_A2UL05RDU},	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
	{ 810	,8	,1	, &fEM_A2UL03RDU},	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{ 811	,8	,1	, &fEM_A2UC06RDU},	//(A2UC06RDU) Уставка определения самохода РБ  мм
	{ 812	,8	,1	, &fEM_A2UC05RDU},	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
	{ 813	,8	,1	, &fEM_A2UL04RDU},	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
	{ 814	,8	,1	, &fEM_A1UL03RDU},	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
	{ 815	,8	,1	, &fEM_A1UL05RDU},	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
	{ 816	,8	,1	, &fEM_A3UL03RDU},	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
	{ 817	,8	,1	, &fEM_A3UL05RDU},	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
	{ 818	,8	,1	, &fEM_A1UC08RDU},	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
	{ 819	,8	,1	, &fEM_A3UC08RDU},	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
	{ 820	,8	,1	, &fEM_A1UC07RDU},	//(A1UC07RDU) Зона возврата при наведении ББ мм
	{ 821	,8	,1	, &fEM_A1UL01RDU},	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 822	,8	,1	, &fEM_A3UC07RDU},	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
	{ 823	,8	,1	, &fEM_A3UL01RDU},	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 824	,8	,1	, &fEM_A2UC08RDU},	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
	{ 825	,8	,1	, &fEM_A2UC07RDU},	//(A2UC07RDU) Зона возврата при наведении РБ  мм
	{ 826	,8	,1	, &fEM_A2UL01RDU},	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 827	,8	,1	, &fEM_B8UC01RDU},	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
	{ 828	,8	,1	, &fEM_B8UL07RDU},	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
	{ 829	,8	,1	, &fEM_B8UC02RDU},	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
	{ 830	,8	,1	, &fEM_B8UL01RDU},	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 831	,8	,1	, &fEM_B8UL05RDU},	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
	{ 832	,8	,1	, &fEM_B8UL03RDU},	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
	{ 833	,8	,1	, &fEM_B8UL06RDU},	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
	{ 834	,8	,1	, &fEM_A9UZ03RDU},	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
	{ 835	,8	,1	, &fEM_A9UZ04RDU},	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
	{ 836	,8	,1	, &fEM_A9UZ05RDU},	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
	{ 837	,8	,1	, &fEM_R4UZ04RDU},	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
	{ 838	,8	,1	, &fEM_R4UZ03RDU},	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
	{ 839	,8	,1	, &fEM_R4UZ05RDU},	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
	{ 840	,8	,1	, &fEM_A5UZ03RDU},	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
	{ 841	,8	,1	, &fEM_A5UZ04RDU},	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
	{ 842	,8	,1	, &fEM_A5UZ05RDU},	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
	{ 843	,8	,1	, &fEM_A4UZ03RDU},	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
	{ 844	,8	,1	, &fEM_A4UZ04RDU},	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
	{ 845	,8	,1	, &fEM_A4UZ05RDU},	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
	{ 846	,8	,1	, &fEM_A6UZ03RDU},	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
	{ 847	,8	,1	, &fEM_A6UZ04RDU},	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
	{ 848	,8	,1	, &fEM_A6UZ05RDU},	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
	{ 849	,8	,1	, &fEM_R1UZ03RDU},	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
	{ 850	,8	,1	, &fEM_R1UZ04RDU},	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
	{ 851	,8	,1	, &fEM_R1UZ05RDU},	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
	{ 852	,8	,1	, &fEM_R0UL04RDU},	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
	{ 853	,8	,1	, &fEM_R0UL06RDU},	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
	{ 854	,8	,1	, &fEM_R0UL03RDU},	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
	{ 855	,8	,1	, &fEM_R0UL17RDU},	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
	{ 856	,8	,1	, &fEM_R0UL19RDU},	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{ 857	,8	,1	, &fEM_R0UL07RDU},	//(R0UL07RDU) Время срабатывания верхней АС II УР
	{ 858	,8	,1	, &fEM_R0UL18RDU},	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
	{ 859	,8	,1	, &fEM_R0UL16RDU},	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
	{ 860	,8	,1	, &fEM_R0UL02RDU},	//(R0UL02RDU) Время задержки  ИНИ
	{ 861	,8	,1	, &fEM_R0UN08RDU},	//(R0UN08RDU) 8-я заданная мощность
	{ 862	,8	,1	, &fEM_R0UN07RDU},	//(R0UN07RDU) 7-я заданная мощность
	{ 863	,8	,1	, &fEM_R0UN06RDU},	//(R0UN06RDU) 6-я заданная мощность
	{ 864	,8	,1	, &fEM_R0UN05RDU},	//(R0UN05RDU) 5-я заданная мощность
	{ 865	,8	,1	, &fEM_R0UN04RDU},	//(R0UN04RDU) 4-я заданная мощность
	{ 866	,8	,1	, &fEM_R0UN03RDU},	//(R0UN03RDU) Ограничение 3 по мощности
	{ 867	,8	,1	, &fEM_R0UN02RDU},	//(R0UN02RDU) 2-я заданная мощность
	{ 868	,8	,1	, &fEM_R0UN01RDU},	//(R0UN01RDU) 1-я заданная мощность
	{ 869	,8	,1	, &fEM_A2UC82RDU},	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
	{ 870	,8	,1	, &fEM_A2UC83RDU},	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
	{ 871	,8	,1	, &fEM_A1UC83RDU},	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
	{ 872	,8	,1	, &fEM_A2UC81RDU},	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
	{ 873	,8	,1	, &fEM_A1UC81RDU},	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
	{ 874	,8	,1	, &fEM_A1UC82RDU},	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
	{ 875	,8	,1	, &fEM_A2UL83RDU},	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{ 876	,8	,1	, &fEM_A3UC81RDU},	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
	{ 877	,8	,1	, &fEM_A3UC82RDU},	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
	{ 878	,8	,1	, &fEM_R0UN80RDU},	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
	{ 879	,3	,1	, &iEM_A2UV01IDU},	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
	{ 880	,3	,1	, &iEM_A2UV02IDU},	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
	{ 881	,3	,1	, &iEM_A1UV01IDU},	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
	{ 882	,3	,1	, &iEM_A1UV02IDU},	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
	{ 883	,3	,1	, &iEM_A1UV03IDU},	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
	{ 884	,3	,1	, &iEM_A3UV01IDU},	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
	{ 885	,3	,1	, &iEM_A3UV02IDU},	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
	{ 886	,1	,1	, &lEM_R0MD01LC1},	//(R0MD01LC1) Ручное управление ОРР
	{ 887	,8	,1	, &fEM_A3UC09RDU},	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
	{ 888	,8	,1	, &fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
	{ 889	,8	,1	, &fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
	{ 890	,8	,1	, &fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
	{ 891	,8	,1	, &fEM_R0UL21RDU},	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
	{ 892	,8	,1	, &fEM_R0UN09RDU},	//(R0UN09RDU) Минимальный период при регулировании мощности
	{ 893	,8	,1	, &fEM_R0UN11RDU},	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
	{ 894	,8	,1	, &fEM_R0UN12RDU},	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
	{ 895	,8	,1	, &fEM_R0UN13RDU},	//(R0UN13RDU) Минимальное изменение координаты, мм
	{ 896	,8	,1	, &fEM_R0UN14RDU},	//(R0UN14RDU) Максимальная координата штока ИМ, мм
	{ 897	,8	,1	, &fEM_R0UN16RDU},	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
	{ 898	,8	,1	, &fEM_R0UN17RDU},	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
	{ 899	,8	,1	, &fEM_R0UN18RDU},	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
	{ 900	,8	,1	, &fEM_R0UN19RDU},	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
	{ 901	,8	,1	, &fEM_R0UN70LDU},	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
	{ 902	,8	,1	, &fEM_R0UN71LDU},	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
	{ 903	,8	,1	, &fEM_R0UN72LDU},	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
	{ 904	,8	,1	, &fEM_R0UN73LDU},	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
	{ 905	,8	,1	, &fEM_R0UN74LDU},	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
	{ 906	,8	,1	, &fEM_R0UN75LDU},	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
	{ 907	,8	,1	, &fEM_R0UN80LDU},	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
	{ 908	,8	,1	, &fEM_R0UN81LDU},	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
	{ 909	,8	,1	, &fEM_R0UN82LDU},	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
	{ 910	,8	,1	, &fEM_R0UN83LDU},	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
	{ 911	,8	,1	, &fEM_R0UN84LDU},	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
	{ 912	,8	,1	, &fEM_R0UN85LDU},	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
	{ 913	,8	,1	, &fEM_R0UT20RDU},	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
	{ 914	,8	,1	, &fEM_R0UN25RDU},	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
	{ 915	,8	,1	, &fEM_R0UN15RDU},	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
	{ 916	,8	,1	, &fEM_R0UN26RDU},	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
	{ 917	,8	,1	, &fEM_R0UN27RDU},	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
	{ 918	,8	,1	, &fEM_R0UN24RDU},	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 919	,8	,1	, &fEM_R0UL25RDU},	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{ 920	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 921	,8	,1	, &internal2_m186_y0},	//(internal2_m186_y0) y0
	{ 922	,8	,1	, &internal2_m184_y0},	//(internal2_m184_y0) y0
	{ 923	,1	,1	, &internal2_m216_y0},	//(internal2_m216_y0) state
	{ 924	,1	,1	, &internal2_m210_y0},	//(internal2_m210_y0) state
	{ 925	,1	,1	, &internal2_m199_y1},	//(internal2_m199_y1) y1 - внутренний параметр
	{ 926	,1	,1	, &internal2_m206_y1},	//(internal2_m206_y1) y1 - внутренний параметр
	{ 927	,1	,1	, &internal2_m189_y1},	//(internal2_m189_y1) y1 - внутренний параметр
	{ 928	,1	,1	, &internal2_m196_y1},	//(internal2_m196_y1) y1 - внутренний параметр
	{ 929	,5	,1	, &internal2_m16_Nk0},	//(internal2_m16_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 930	,1	,1	, &internal2_m16_SetFlag},	//(internal2_m16_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 931	,5	,1	, &internal2_m108_Nk0},	//(internal2_m108_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 932	,1	,1	, &internal2_m108_SetFlag},	//(internal2_m108_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 933	,5	,1	, &internal2_m112_Nk0},	//(internal2_m112_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 934	,1	,1	, &internal2_m112_SetFlag},	//(internal2_m112_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 935	,5	,1	, &internal2_m75_Nk0},	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 936	,1	,1	, &internal2_m75_SetFlag},	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 937	,5	,1	, &internal2_m77_Nk0},	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 938	,1	,1	, &internal2_m77_SetFlag},	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 939	,5	,1	, &internal2_m47_Nk0},	//(internal2_m47_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 940	,1	,1	, &internal2_m47_SetFlag},	//(internal2_m47_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 941	,5	,1	, &internal2_m51_Nk0},	//(internal2_m51_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 942	,1	,1	, &internal2_m51_SetFlag},	//(internal2_m51_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 943	,5	,1	, &internal2_m21_Nk0},	//(internal2_m21_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 944	,1	,1	, &internal2_m21_SetFlag},	//(internal2_m21_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 945	,1	,1	, &internal1_m1697_q0},	//(internal1_m1697_q0) q0 - внутренний параметр
	{ 946	,1	,1	, &internal1_m2132_q0},	//(internal1_m2132_q0) q0 - внутренний параметр
	{ 947	,1	,1	, &internal1_m2116_q0},	//(internal1_m2116_q0) q0 - внутренний параметр
	{ 948	,1	,1	, &internal1_m2164_q0},	//(internal1_m2164_q0) q0 - внутренний параметр
	{ 949	,1	,1	, &internal1_m2148_q0},	//(internal1_m2148_q0) q0 - внутренний параметр
	{ 950	,1	,1	, &internal1_m2138_q0},	//(internal1_m2138_q0) q0 - внутренний параметр
	{ 951	,1	,1	, &internal1_m2119_q0},	//(internal1_m2119_q0) q0 - внутренний параметр
	{ 952	,1	,1	, &internal1_m2136_q0},	//(internal1_m2136_q0) q0 - внутренний параметр
	{ 953	,1	,1	, &internal1_m2117_q0},	//(internal1_m2117_q0) q0 - внутренний параметр
	{ 954	,1	,1	, &internal1_m2115_q0},	//(internal1_m2115_q0) q0 - внутренний параметр
	{ 955	,1	,1	, &internal1_m2114_q0},	//(internal1_m2114_q0) q0 - внутренний параметр
	{ 956	,1	,1	, &internal1_m2128_q0},	//(internal1_m2128_q0) q0 - внутренний параметр
	{ 957	,1	,1	, &internal1_m2126_q0},	//(internal1_m2126_q0) q0 - внутренний параметр
	{ 958	,1	,1	, &internal1_m2134_q0},	//(internal1_m2134_q0) q0 - внутренний параметр
	{ 959	,1	,1	, &internal1_m2130_q0},	//(internal1_m2130_q0) q0 - внутренний параметр
	{ 960	,1	,1	, &internal1_m2170_q0},	//(internal1_m2170_q0) q0 - внутренний параметр
	{ 961	,1	,1	, &internal1_m2151_q0},	//(internal1_m2151_q0) q0 - внутренний параметр
	{ 962	,1	,1	, &internal1_m2168_q0},	//(internal1_m2168_q0) q0 - внутренний параметр
	{ 963	,1	,1	, &internal1_m2150_q0},	//(internal1_m2150_q0) q0 - внутренний параметр
	{ 964	,1	,1	, &internal1_m2147_q0},	//(internal1_m2147_q0) q0 - внутренний параметр
	{ 965	,1	,1	, &internal1_m2146_q0},	//(internal1_m2146_q0) q0 - внутренний параметр
	{ 966	,1	,1	, &internal1_m2160_q0},	//(internal1_m2160_q0) q0 - внутренний параметр
	{ 967	,1	,1	, &internal1_m2158_q0},	//(internal1_m2158_q0) q0 - внутренний параметр
	{ 968	,8	,1	, &internal1_m2035_tx},	//(internal1_m2035_tx) tx - внутренний параметр
	{ 969	,8	,1	, &internal1_m2014_tx},	//(internal1_m2014_tx) tx - внутренний параметр
	{ 970	,1	,1	, &internal1_m1720_Pv0},	//(internal1_m1720_Pv0)  - Пер. выключатель механизма
	{ 971	,1	,1	, &internal1_m1720_Zv0},	//(internal1_m1720_Zv0)  - Зад. выключатель механизма
	{ 972	,1	,1	, &internal1_m1720_MyFirstEnterFlag},	//(internal1_m1720_MyFirstEnterFlag) MyFirstEnterFlag
	{ 973	,1	,1	, &internal1_m1718_Pv0},	//(internal1_m1718_Pv0)  - Пер. выключатель механизма
	{ 974	,1	,1	, &internal1_m1718_Zv0},	//(internal1_m1718_Zv0)  - Зад. выключатель механизма
	{ 975	,1	,1	, &internal1_m1718_MyFirstEnterFlag},	//(internal1_m1718_MyFirstEnterFlag) MyFirstEnterFlag
	{ 976	,8	,1	, &internal1_m2189_tx},	//(internal1_m2189_tx) tx - время накопленное сек
	{ 977	,18	,1	, &internal1_m2189_y0},	//(internal1_m2189_y0) y0
	{ 978	,8	,1	, &internal1_m2193_tx},	//(internal1_m2193_tx) tx - время накопленное сек
	{ 979	,18	,1	, &internal1_m2193_y0},	//(internal1_m2193_y0) y0
	{ 980	,8	,1	, &internal1_m2192_tx},	//(internal1_m2192_tx) tx - время накопленное сек
	{ 981	,18	,1	, &internal1_m2192_y0},	//(internal1_m2192_y0) y0
	{ 982	,8	,1	, &internal1_m2229_tx},	//(internal1_m2229_tx) tx - внутренний параметр
	{ 983	,8	,1	, &internal1_m2227_tx},	//(internal1_m2227_tx) tx - время накопленное сек
	{ 984	,18	,1	, &internal1_m2227_y0},	//(internal1_m2227_y0) y0
	{ 985	,1	,1	, &internal1_m2232_q0},	//(internal1_m2232_q0) q0 - внутренний параметр
	{ 986	,1	,1	, &internal1_m2199_q0},	//(internal1_m2199_q0) q0 - внутренний параметр
	{ 987	,8	,1	, &internal1_m2207_tx},	//(internal1_m2207_tx) tx - внутренний параметр
	{ 988	,1	,1	, &internal1_m2205_q0},	//(internal1_m2205_q0) q0 - внутренний параметр
	{ 989	,8	,1	, &internal1_m2029_tx},	//(internal1_m2029_tx) tx - время накопленное сек
	{ 990	,18	,1	, &internal1_m2029_y0},	//(internal1_m2029_y0) y0
	{ 991	,8	,1	, &internal1_m2021_tx},	//(internal1_m2021_tx) tx - время накопленное сек
	{ 992	,18	,1	, &internal1_m2021_y0},	//(internal1_m2021_y0) y0
	{ 993	,1	,1	, &internal1_m1707_q0},	//(internal1_m1707_q0) q0 - внутренний параметр
	{ 994	,1	,1	, &internal1_m1712_q0},	//(internal1_m1712_q0) q0 - внутренний параметр
	{ 995	,1	,1	, &internal1_m1704_q0},	//(internal1_m1704_q0) q0 - внутренний параметр
	{ 996	,1	,1	, &internal1_m1746_q0},	//(internal1_m1746_q0) q0 - внутренний параметр
	{ 997	,8	,1	, &internal1_m746_tx},	//(internal1_m746_tx) tx - время накопленное сек
	{ 998	,18	,1	, &internal1_m746_y0},	//(internal1_m746_y0) y0
	{ 999	,8	,1	, &internal1_m2025_tx},	//(internal1_m2025_tx) tx - внутренний параметр
	{ 1000	,1	,1	, &internal1_m2028_q0},	//(internal1_m2028_q0) q0 - внутренний параметр
	{ 1001	,1	,1	, &internal1_m2020_q0},	//(internal1_m2020_q0) q0 - внутренний параметр
	{ 1002	,8	,1	, &internal1_m1990_tx},	//(internal1_m1990_tx) tx - внутренний параметр
	{ 1003	,8	,1	, &internal1_m2001_tx},	//(internal1_m2001_tx) tx - внутренний параметр
	{ 1004	,8	,1	, &internal1_m1987_tx},	//(internal1_m1987_tx) tx - внутренний параметр
	{ 1005	,1	,1	, &internal1_m1993_q0},	//(internal1_m1993_q0) q0 - внутренний параметр
	{ 1006	,1	,1	, &internal1_m2005_q0},	//(internal1_m2005_q0) q0 - внутренний параметр
	{ 1007	,8	,1	, &internal1_m1963_tx},	//(internal1_m1963_tx) tx - внутренний параметр
	{ 1008	,8	,1	, &internal1_m57_tx},	//(internal1_m57_tx) tx - внутренний параметр
	{ 1009	,8	,1	, &internal1_m343_tx},	//(internal1_m343_tx) tx - внутренний параметр
	{ 1010	,8	,1	, &internal1_m298_tx},	//(internal1_m298_tx) tx - внутренний параметр
	{ 1011	,8	,1	, &internal1_m747_tx},	//(internal1_m747_tx) tx - внутренний параметр
	{ 1012	,8	,1	, &internal1_m1427_tx},	//(internal1_m1427_tx) tx - внутренний параметр
	{ 1013	,8	,1	, &internal1_m119_tx},	//(internal1_m119_tx) tx - внутренний параметр
	{ 1014	,8	,1	, &internal1_m121_tx},	//(internal1_m121_tx) tx - внутренний параметр
	{ 1015	,8	,1	, &internal1_m126_tx},	//(internal1_m126_tx) tx - внутренний параметр
	{ 1016	,8	,1	, &internal1_m24_tx},	//(internal1_m24_tx) tx - внутренний параметр
	{ 1017	,8	,1	, &internal1_m16_tx},	//(internal1_m16_tx) tx - внутренний параметр
	{ 1018	,8	,1	, &internal1_m1972_tx},	//(internal1_m1972_tx) tx - внутренний параметр
	{ 1019	,8	,1	, &internal1_m1960_tx},	//(internal1_m1960_tx) tx - внутренний параметр
	{ 1020	,8	,1	, &internal1_m2068_tx},	//(internal1_m2068_tx) tx - внутренний параметр
	{ 1021	,8	,1	, &internal1_m2072_tx},	//(internal1_m2072_tx) tx - внутренний параметр
	{ 1022	,8	,1	, &internal1_m1885_tx},	//(internal1_m1885_tx) tx - внутренний параметр
	{ 1023	,8	,1	, &internal1_m83_tx},	//(internal1_m83_tx) tx - внутренний параметр
	{ 1024	,8	,1	, &internal1_m312_tx},	//(internal1_m312_tx) tx - время накопленное сек
	{ 1025	,18	,1	, &internal1_m312_y0},	//(internal1_m312_y0) y0
	{ 1026	,8	,1	, &internal1_m1879_tx},	//(internal1_m1879_tx) tx - время накопленное сек
	{ 1027	,18	,1	, &internal1_m1879_y0},	//(internal1_m1879_y0) y0
	{ 1028	,8	,1	, &internal1_m1877_tx},	//(internal1_m1877_tx) tx - время накопленное сек
	{ 1029	,18	,1	, &internal1_m1877_y0},	//(internal1_m1877_y0) y0
	{ 1030	,8	,1	, &internal1_m1866_tx},	//(internal1_m1866_tx) tx - время накопленное сек
	{ 1031	,18	,1	, &internal1_m1866_y0},	//(internal1_m1866_y0) y0
	{ 1032	,8	,1	, &internal1_m1886_q0},	//(internal1_m1886_q0) q0 - внутренний параметр
	{ 1033	,8	,1	, &internal1_m1447_q0},	//(internal1_m1447_q0) q0 - внутренний параметр
	{ 1034	,8	,1	, &internal1_m1485_q0},	//(internal1_m1485_q0) q0 - внутренний параметр
	{ 1035	,8	,1	, &internal1_m1488_q0},	//(internal1_m1488_q0) q0 - внутренний параметр
	{ 1036	,8	,1	, &internal1_m1925_q0},	//(internal1_m1925_q0) q0 - внутренний параметр
	{ 1037	,8	,1	, &internal1_m1903_tx},	//(internal1_m1903_tx) tx - время накопленное сек
	{ 1038	,18	,1	, &internal1_m1903_y0},	//(internal1_m1903_y0) y0
	{ 1039	,8	,1	, &internal1_m1918_tx},	//(internal1_m1918_tx) tx - время накопленное сек
	{ 1040	,18	,1	, &internal1_m1918_y0},	//(internal1_m1918_y0) y0
	{ 1041	,8	,1	, &internal1_m1915_tx},	//(internal1_m1915_tx) tx - время накопленное сек
	{ 1042	,18	,1	, &internal1_m1915_y0},	//(internal1_m1915_y0) y0
	{ 1043	,8	,1	, &internal1_m2051_tx},	//(internal1_m2051_tx) tx - время накопленное сек
	{ 1044	,18	,1	, &internal1_m2051_y0},	//(internal1_m2051_y0) y0
	{ 1045	,8	,1	, &internal1_m2062_tx},	//(internal1_m2062_tx) tx - время накопленное сек
	{ 1046	,18	,1	, &internal1_m2062_y0},	//(internal1_m2062_y0) y0
	{ 1047	,8	,1	, &internal1_m1814_tx},	//(internal1_m1814_tx) tx - время накопленное сек
	{ 1048	,18	,1	, &internal1_m1814_y0},	//(internal1_m1814_y0) y0
	{ 1049	,8	,1	, &internal1_m1813_tx},	//(internal1_m1813_tx) tx - время накопленное сек
	{ 1050	,18	,1	, &internal1_m1813_y0},	//(internal1_m1813_y0) y0
	{ 1051	,8	,1	, &internal1_m1812_tx},	//(internal1_m1812_tx) tx - время накопленное сек
	{ 1052	,18	,1	, &internal1_m1812_y0},	//(internal1_m1812_y0) y0
	{ 1053	,8	,1	, &internal1_m1811_tx},	//(internal1_m1811_tx) tx - время накопленное сек
	{ 1054	,18	,1	, &internal1_m1811_y0},	//(internal1_m1811_y0) y0
	{ 1055	,8	,1	, &internal1_m1499_tx},	//(internal1_m1499_tx) tx - время накопленное сек
	{ 1056	,18	,1	, &internal1_m1499_y0},	//(internal1_m1499_y0) y0
	{ 1057	,8	,1	, &internal1_m1493_tx},	//(internal1_m1493_tx) tx - время накопленное сек
	{ 1058	,18	,1	, &internal1_m1493_y0},	//(internal1_m1493_y0) y0
	{ 1059	,8	,1	, &internal1_m1443_tx},	//(internal1_m1443_tx) tx - время накопленное сек
	{ 1060	,18	,1	, &internal1_m1443_y0},	//(internal1_m1443_y0) y0
	{ 1061	,8	,1	, &internal1_m830_tx},	//(internal1_m830_tx) tx - время накопленное сек
	{ 1062	,18	,1	, &internal1_m830_y0},	//(internal1_m830_y0) y0
	{ 1063	,8	,1	, &internal1_m827_tx},	//(internal1_m827_tx) tx - время накопленное сек
	{ 1064	,18	,1	, &internal1_m827_y0},	//(internal1_m827_y0) y0
	{ 1065	,8	,1	, &internal1_m834_tx},	//(internal1_m834_tx) tx - время накопленное сек
	{ 1066	,18	,1	, &internal1_m834_y0},	//(internal1_m834_y0) y0
	{ 1067	,8	,1	, &internal1_m193_tx},	//(internal1_m193_tx) tx - время накопленное сек
	{ 1068	,18	,1	, &internal1_m193_y0},	//(internal1_m193_y0) y0
	{ 1069	,8	,1	, &internal1_m198_tx},	//(internal1_m198_tx) tx - время накопленное сек
	{ 1070	,18	,1	, &internal1_m198_y0},	//(internal1_m198_y0) y0
	{ 1071	,8	,1	, &internal1_m204_tx},	//(internal1_m204_tx) tx - время накопленное сек
	{ 1072	,18	,1	, &internal1_m204_y0},	//(internal1_m204_y0) y0
	{ 1073	,8	,1	, &internal1_m523_tx},	//(internal1_m523_tx) tx - время накопленное сек
	{ 1074	,18	,1	, &internal1_m523_y0},	//(internal1_m523_y0) y0
	{ 1075	,8	,1	, &internal1_m2100_tx},	//(internal1_m2100_tx) tx - внутренний параметр
	{ 1076	,8	,1	, &internal1_m1188_tx},	//(internal1_m1188_tx) tx - внутренний параметр
	{ 1077	,8	,1	, &internal1_m1613_tx},	//(internal1_m1613_tx) tx - время накопленное сек
	{ 1078	,18	,1	, &internal1_m1613_y0},	//(internal1_m1613_y0) y0
	{ 1079	,8	,1	, &internal1_m1138_tx},	//(internal1_m1138_tx) tx - время накопленное сек
	{ 1080	,18	,1	, &internal1_m1138_y0},	//(internal1_m1138_y0) y0
	{ 1081	,8	,1	, &internal1_m1339_tx},	//(internal1_m1339_tx) tx - время накопленное сек
	{ 1082	,18	,1	, &internal1_m1339_y0},	//(internal1_m1339_y0) y0
	{ 1083	,8	,1	, &internal1_m927_tx},	//(internal1_m927_tx) tx - время накопленное сек
	{ 1084	,18	,1	, &internal1_m927_y0},	//(internal1_m927_y0) y0
	{ 1085	,8	,1	, &internal1_m1246_tx},	//(internal1_m1246_tx) tx - время накопленное сек
	{ 1086	,18	,1	, &internal1_m1246_y0},	//(internal1_m1246_y0) y0
	{ 1087	,1	,1	, &internal1_m1079_q0},	//(internal1_m1079_q0) q0 - внутренний параметр
	{ 1088	,1	,1	, &internal1_m1077_q0},	//(internal1_m1077_q0) q0 - внутренний параметр
	{ 1089	,1	,1	, &internal1_m1076_q0},	//(internal1_m1076_q0) q0 - внутренний параметр
	{ 1090	,1	,1	, &internal1_m1074_q0},	//(internal1_m1074_q0) q0 - внутренний параметр
	{ 1091	,1	,1	, &internal1_m1073_q0},	//(internal1_m1073_q0) q0 - внутренний параметр
	{ 1092	,1	,1	, &internal1_m1071_q0},	//(internal1_m1071_q0) q0 - внутренний параметр
	{ 1093	,1	,1	, &internal1_m1070_q0},	//(internal1_m1070_q0) q0 - внутренний параметр
	{ 1094	,1	,1	, &internal1_m1068_q0},	//(internal1_m1068_q0) q0 - внутренний параметр
	{ 1095	,1	,1	, &internal1_m1067_q0},	//(internal1_m1067_q0) q0 - внутренний параметр
	{ 1096	,1	,1	, &internal1_m58_x0},	//(internal1_m58_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1097	,1	,1	, &internal1_m987_q0},	//(internal1_m987_q0) q0 - внутренний параметр
	{ 1098	,1	,1	, &internal1_m1436_x0},	//(internal1_m1436_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1099	,1	,1	, &internal1_m1480_x0},	//(internal1_m1480_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1100	,1	,1	, &internal1_m1476_x0},	//(internal1_m1476_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1101	,1	,1	, &internal1_m1894_x0},	//(internal1_m1894_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1102	,1	,1	, &internal1_m1859_x0},	//(internal1_m1859_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1103	,1	,1	, &internal1_m1026_q0},	//(internal1_m1026_q0) q0 - внутренний параметр
	{ 1104	,1	,1	, &internal1_m1037_q0},	//(internal1_m1037_q0) q0 - внутренний параметр
	{ 1105	,1	,1	, &internal1_m1050_q0},	//(internal1_m1050_q0) q0 - внутренний параметр
	{ 1106	,1	,1	, &internal1_m1059_q0},	//(internal1_m1059_q0) q0 - внутренний параметр
	{ 1107	,1	,1	, &internal1_m1036_q0},	//(internal1_m1036_q0) q0 - внутренний параметр
	{ 1108	,1	,1	, &internal1_m1052_q0},	//(internal1_m1052_q0) q0 - внутренний параметр
	{ 1109	,1	,1	, &internal1_m1952_q0},	//(internal1_m1952_q0) q0 - внутренний параметр
	{ 1110	,1	,1	, &internal1_m1951_q0},	//(internal1_m1951_q0) q0 - внутренний параметр
	{ 1111	,3	,1	, &internal1_m331_Step},	//(internal1_m331_Step)  - текущий шаг программы
	{ 1112	,18	,10	, &internal1_m331_rz},	//(internal1_m331_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1113	,8	,1	, &internal1_m331_TimS},	//(internal1_m331_TimS) Время от старта программы
	{ 1114	,1	,1	, &internal1_m331_FinPr0},	//(internal1_m331_FinPr0) FinPr - конец программы
	{ 1115	,1	,1	, &internal1_m331_ErrPr0},	//(internal1_m331_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1116	,1	,1	, &internal1_m331_sbINI0},	//(internal1_m331_sbINI0) sbINI - запуск проверки ИНИ
	{ 1117	,1	,1	, &internal1_m331_sbVuIS0},	//(internal1_m331_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1118	,1	,1	, &internal1_m331_sb2UR0},	//(internal1_m331_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1119	,1	,1	, &internal1_m331_sbNupIS0},	//(internal1_m331_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1120	,1	,1	, &internal1_m331_sbVuRB0},	//(internal1_m331_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1121	,1	,1	, &internal1_m331_MyFirstEnterFlag},	//(internal1_m331_MyFirstEnterFlag)  
	{ 1122	,5	,1	, &internal1_m339_x0},	//(internal1_m339_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1123	,5	,1	, &internal1_m297_TimS},	//(internal1_m297_TimS) Время старта
	{ 1124	,3	,1	, &internal1_m274_Step},	//(internal1_m274_Step)  - текущий шаг программы
	{ 1125	,18	,10	, &internal1_m274_rz},	//(internal1_m274_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1126	,8	,1	, &internal1_m274_TimS},	//(internal1_m274_TimS) Время от старта программы
	{ 1127	,1	,1	, &internal1_m274_FinPr0},	//(internal1_m274_FinPr0) FinPr - конец программы
	{ 1128	,1	,1	, &internal1_m274_ErrPr0},	//(internal1_m274_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1129	,1	,1	, &internal1_m274_sbINI0},	//(internal1_m274_sbINI0) sbINI - запуск проверки ИНИ
	{ 1130	,1	,1	, &internal1_m274_sbVuIS0},	//(internal1_m274_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1131	,1	,1	, &internal1_m274_sb2UR0},	//(internal1_m274_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1132	,1	,1	, &internal1_m274_sbNupIS0},	//(internal1_m274_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1133	,1	,1	, &internal1_m274_sbVuRB0},	//(internal1_m274_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1134	,1	,1	, &internal1_m274_MyFirstEnterFlag},	//(internal1_m274_MyFirstEnterFlag)  
	{ 1135	,1	,1	, &internal1_m1410_q0},	//(internal1_m1410_q0) q0 - внутренний параметр
	{ 1136	,3	,1	, &internal1_m1411_Step},	//(internal1_m1411_Step)  - текущий шаг программы
	{ 1137	,18	,6	, &internal1_m1411_rz},	//(internal1_m1411_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1138	,8	,1	, &internal1_m1411_TimS},	//(internal1_m1411_TimS) Время от старта программы
	{ 1139	,1	,1	, &internal1_m1411_FinPr0},	//(internal1_m1411_FinPr0) FinPr - конец программы
	{ 1140	,1	,1	, &internal1_m1411_ErrPr0},	//(internal1_m1411_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1141	,1	,1	, &internal1_m1411_sbINI0},	//(internal1_m1411_sbINI0) sbINI - запуск проверки ИНИ
	{ 1142	,1	,1	, &internal1_m1411_sbVuIS0},	//(internal1_m1411_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1143	,1	,1	, &internal1_m1411_sb2UR0},	//(internal1_m1411_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1144	,1	,1	, &internal1_m1411_sbNupIS0},	//(internal1_m1411_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1145	,1	,1	, &internal1_m1411_sbVuRB0},	//(internal1_m1411_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1146	,1	,1	, &internal1_m1411_MyFirstEnterFlag},	//(internal1_m1411_MyFirstEnterFlag)  
	{ 1147	,1	,1	, &internal1_m1021_q0},	//(internal1_m1021_q0) q0 - внутренний параметр
	{ 1148	,1	,1	, &internal1_m1018_q0},	//(internal1_m1018_q0) q0 - внутренний параметр
	{ 1149	,1	,1	, &internal1_m1020_q0},	//(internal1_m1020_q0) q0 - внутренний параметр
	{ 1150	,1	,1	, &internal1_m1015_q0},	//(internal1_m1015_q0) q0 - внутренний параметр
	{ 1151	,1	,1	, &internal1_m748_q0},	//(internal1_m748_q0) q0 - внутренний параметр
	{ 1152	,1	,1	, &internal1_m341_q0},	//(internal1_m341_q0) q0 - внутренний параметр
	{ 1153	,1	,1	, &internal1_m337_q0},	//(internal1_m337_q0) q0 - внутренний параметр
	{ 1154	,1	,1	, &internal1_m294_q0},	//(internal1_m294_q0) q0 - внутренний параметр
	{ 1155	,5	,1	, &internal1_m293_x0},	//(internal1_m293_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1156	,1	,1	, &internal1_m1881_q0},	//(internal1_m1881_q0) q0 - внутренний параметр
	{ 1157	,1	,1	, &internal1_m1869_q0},	//(internal1_m1869_q0) q0 - внутренний параметр
	{ 1158	,1	,1	, &internal1_m1860_q0},	//(internal1_m1860_q0) q0 - внутренний параметр
	{ 1159	,1	,1	, &internal1_m1935_q0},	//(internal1_m1935_q0) q0 - внутренний параметр
	{ 1160	,1	,1	, &internal1_m1906_q0},	//(internal1_m1906_q0) q0 - внутренний параметр
	{ 1161	,1	,1	, &internal1_m1895_q0},	//(internal1_m1895_q0) q0 - внутренний параметр
	{ 1162	,1	,1	, &internal1_m1463_q0},	//(internal1_m1463_q0) q0 - внутренний параметр
	{ 1163	,1	,1	, &internal1_m1450_x0},	//(internal1_m1450_x0) был приход сигнала x1
	{ 1164	,8	,1	, &internal1_m1450_y0},	//(internal1_m1450_y0) интервал между сигналами х1 и х2
	{ 1165	,1	,1	, &internal1_m1446_q0},	//(internal1_m1446_q0) q0 - внутренний параметр
	{ 1166	,1	,1	, &internal1_m1437_q0},	//(internal1_m1437_q0) q0 - внутренний параметр
	{ 1167	,1	,1	, &internal1_m1496_q0},	//(internal1_m1496_q0) q0 - внутренний параметр
	{ 1168	,1	,1	, &internal1_m1516_q0},	//(internal1_m1516_q0) q0 - внутренний параметр
	{ 1169	,1	,1	, &internal1_m1482_q0},	//(internal1_m1482_q0) q0 - внутренний параметр
	{ 1170	,1	,1	, &internal1_m1497_x0},	//(internal1_m1497_x0) был приход сигнала x1
	{ 1171	,8	,1	, &internal1_m1497_y0},	//(internal1_m1497_y0) интервал между сигналами х1 и х2
	{ 1172	,5	,1	, &internal1_m1421_x0},	//(internal1_m1421_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1173	,1	,1	, &internal1_m1502_q0},	//(internal1_m1502_q0) q0 - внутренний параметр
	{ 1174	,1	,1	, &internal1_m29_q0},	//(internal1_m29_q0) q0 - внутренний параметр
	{ 1175	,1	,1	, &internal1_m1517_q0},	//(internal1_m1517_q0) q0 - внутренний параметр
	{ 1176	,1	,1	, &internal1_m638_q0},	//(internal1_m638_q0) q0 - внутренний параметр
	{ 1177	,1	,1	, &internal1_m623_q0},	//(internal1_m623_q0) q0 - внутренний параметр
	{ 1178	,1	,1	, &internal1_m651_q0},	//(internal1_m651_q0) q0 - внутренний параметр
	{ 1179	,1	,1	, &internal1_m634_q0},	//(internal1_m634_q0) q0 - внутренний параметр
	{ 1180	,1	,1	, &internal1_m618_q0},	//(internal1_m618_q0) q0 - внутренний параметр
	{ 1181	,1	,1	, &internal1_m616_q0},	//(internal1_m616_q0) q0 - внутренний параметр
	{ 1182	,1	,1	, &internal1_m604_q0},	//(internal1_m604_q0) q0 - внутренний параметр
	{ 1183	,5	,1	, &internal1_m1413_q0},	//(internal1_m1413_q0) q0 - внутренний параметр
	{ 1184	,1	,1	, &internal1_m614_q0},	//(internal1_m614_q0) q0 - внутренний параметр
	{ 1185	,1	,1	, &internal1_m115_q0},	//(internal1_m115_q0) q0 - внутренний параметр
	{ 1186	,1	,1	, &internal1_m1649_q0},	//(internal1_m1649_q0) q0 - внутренний параметр
	{ 1187	,1	,1	, &internal1_m1648_q0},	//(internal1_m1648_q0) q0 - внутренний параметр
	{ 1188	,1	,1	, &internal1_m1647_q0},	//(internal1_m1647_q0) q0 - внутренний параметр
	{ 1189	,1	,1	, &internal1_m1646_q0},	//(internal1_m1646_q0) q0 - внутренний параметр
	{ 1190	,1	,1	, &internal1_m1684_q0},	//(internal1_m1684_q0) q0 - внутренний параметр
	{ 1191	,1	,1	, &internal1_m1683_q0},	//(internal1_m1683_q0) q0 - внутренний параметр
	{ 1192	,1	,1	, &internal1_m1682_q0},	//(internal1_m1682_q0) q0 - внутренний параметр
	{ 1193	,1	,1	, &internal1_m1966_q0},	//(internal1_m1966_q0) q0 - внутренний параметр
	{ 1194	,1	,1	, &internal1_m1744_q0},	//(internal1_m1744_q0) q0 - внутренний параметр
	{ 1195	,1	,1	, &internal1_m1733_q0},	//(internal1_m1733_q0) q0 - внутренний параметр
	{ 1196	,1	,1	, &internal1_m1741_q0},	//(internal1_m1741_q0) q0 - внутренний параметр
	{ 1197	,1	,1	, &internal1_m1730_q0},	//(internal1_m1730_q0) q0 - внутренний параметр
	{ 1198	,1	,1	, &internal1_m1738_q0},	//(internal1_m1738_q0) q0 - внутренний параметр
	{ 1199	,1	,1	, &internal1_m2166_q0},	//(internal1_m2166_q0) q0 - внутренний параметр
	{ 1200	,1	,1	, &internal1_m2162_q0},	//(internal1_m2162_q0) q0 - внутренний параметр
	{ 1201	,1	,1	, &internal1_m1709_q0},	//(internal1_m1709_q0) q0 - внутренний параметр
	{ 1202	,1	,1	, &internal1_m1701_q0},	//(internal1_m1701_q0) q0 - внутренний параметр
	{ 1203	,1	,1	, &internal1_m1699_q0},	//(internal1_m1699_q0) q0 - внутренний параметр
	{ 1204	,1	,1	, &internal1_m1695_q0},	//(internal1_m1695_q0) q0 - внутренний параметр
	{ 1205	,1	,1	, &internal1_m1691_q0},	//(internal1_m1691_q0) q0 - внутренний параметр
	{ 1206	,1	,1	, &internal1_m1693_q0},	//(internal1_m1693_q0) q0 - внутренний параметр
	{ 1207	,1	,1	, &internal1_m22_q0},	//(internal1_m22_q0) q0 - внутренний параметр
	{ 1208	,1	,1	, &internal1_m1672_q0},	//(internal1_m1672_q0) q0 - внутренний параметр
	{ 1209	,1	,1	, &internal1_m1670_q0},	//(internal1_m1670_q0) q0 - внутренний параметр
	{ 1210	,1	,1	, &internal1_m1666_q0},	//(internal1_m1666_q0) q0 - внутренний параметр
	{ 1211	,1	,1	, &internal1_m1668_q0},	//(internal1_m1668_q0) q0 - внутренний параметр
	{ 1212	,1	,1	, &internal1_m1664_q0},	//(internal1_m1664_q0) q0 - внутренний параметр
	{ 1213	,1	,1	, &internal1_m1662_q0},	//(internal1_m1662_q0) q0 - внутренний параметр
	{ 1214	,1	,1	, &internal1_m2082_q0},	//(internal1_m2082_q0) q0 - внутренний параметр
	{ 1215	,1	,1	, &internal1_m2077_q0},	//(internal1_m2077_q0) q0 - внутренний параметр
	{ 1216	,1	,1	, &internal1_m2056_q0},	//(internal1_m2056_q0) q0 - внутренний параметр
	{ 1217	,1	,1	, &internal1_m2044_q0},	//(internal1_m2044_q0) q0 - внутренний параметр
	{ 1218	,1	,1	, &internal1_m1977_q0},	//(internal1_m1977_q0) q0 - внутренний параметр
	{ 1219	,1	,1	, &internal1_m1658_q0},	//(internal1_m1658_q0) q0 - внутренний параметр
	{ 1220	,1	,1	, &internal1_m1660_q0},	//(internal1_m1660_q0) q0 - внутренний параметр
	{ 1221	,1	,1	, &internal1_m1644_q0},	//(internal1_m1644_q0) q0 - внутренний параметр
	{ 1222	,1	,1	, &internal1_m1642_q0},	//(internal1_m1642_q0) q0 - внутренний параметр
	{ 1223	,1	,1	, &internal1_m1640_q0},	//(internal1_m1640_q0) q0 - внутренний параметр
	{ 1224	,1	,1	, &internal1_m1638_q0},	//(internal1_m1638_q0) q0 - внутренний параметр
	{ 1225	,1	,1	, &internal1_m1637_q0},	//(internal1_m1637_q0) q0 - внутренний параметр
	{ 1226	,1	,1	, &internal1_m1635_q0},	//(internal1_m1635_q0) q0 - внутренний параметр
	{ 1227	,1	,1	, &internal1_m1634_q0},	//(internal1_m1634_q0) q0 - внутренний параметр
	{ 1228	,1	,1	, &internal1_m1632_q0},	//(internal1_m1632_q0) q0 - внутренний параметр
	{ 1229	,18	,1	, &internal1_m2105_DvUp0},	//(internal1_m2105_DvUp0) - есть команда на движение вперёд
	{ 1230	,18	,1	, &internal1_m2105_DvDw0},	//(internal1_m2105_DvDw0) - есть команда на движение назад
	{ 1231	,18	,1	, &internal1_m2105_FDvUp0},	//(internal1_m2105_FDvUp0) - есть команда на движение вперёд
	{ 1232	,18	,1	, &internal1_m2105_FDvDw0},	//(internal1_m2105_FDvDw0) - есть команда на движение назад
	{ 1233	,18	,1	, &internal1_m2105_BlDv0},	//(internal1_m2105_BlDv0) - была блокировка
	{ 1234	,18	,1	, &internal1_m2105_Pkv0},	//(internal1_m2105_Pkv0) Pkv - передний конечный выключатель
	{ 1235	,18	,1	, &internal1_m2105_Pkav0},	//(internal1_m2105_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1236	,18	,1	, &internal1_m2105_Zkv0},	//(internal1_m2105_Zkv0) Zkv - задний конечный выключатель
	{ 1237	,18	,1	, &internal1_m2105_Zkav0},	//(internal1_m2105_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1238	,8	,1	, &internal1_m2105_txNm},	//(internal1_m2105_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1239	,8	,1	, &internal1_m2105_txSm},	//(internal1_m2105_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1240	,8	,1	, &internal1_m2105_txHr},	//(internal1_m2105_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1241	,8	,1	, &internal1_m2105_txLd},	//(internal1_m2105_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1242	,18	,1	, &internal1_m2105_fef},	//(internal1_m2105_fef) fef
	{ 1243	,18	,1	, &internal1_m2099_DvUp0},	//(internal1_m2099_DvUp0) - есть команда на движение вперёд
	{ 1244	,18	,1	, &internal1_m2099_DvDw0},	//(internal1_m2099_DvDw0) - есть команда на движение назад
	{ 1245	,18	,1	, &internal1_m2099_FDvUp0},	//(internal1_m2099_FDvUp0) - есть команда на движение вперёд
	{ 1246	,18	,1	, &internal1_m2099_FDvDw0},	//(internal1_m2099_FDvDw0) - есть команда на движение назад
	{ 1247	,18	,1	, &internal1_m2099_BlDv0},	//(internal1_m2099_BlDv0) - была блокировка
	{ 1248	,18	,1	, &internal1_m2099_Pkv0},	//(internal1_m2099_Pkv0) Pkv - передний конечный выключатель
	{ 1249	,18	,1	, &internal1_m2099_Pkav0},	//(internal1_m2099_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1250	,18	,1	, &internal1_m2099_Zkv0},	//(internal1_m2099_Zkv0) Zkv - задний конечный выключатель
	{ 1251	,18	,1	, &internal1_m2099_Zkav0},	//(internal1_m2099_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1252	,8	,1	, &internal1_m2099_txNm},	//(internal1_m2099_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1253	,8	,1	, &internal1_m2099_txSm},	//(internal1_m2099_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1254	,8	,1	, &internal1_m2099_txHr},	//(internal1_m2099_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1255	,8	,1	, &internal1_m2099_txLd},	//(internal1_m2099_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1256	,18	,1	, &internal1_m2099_fef},	//(internal1_m2099_fef) fef
	{ 1257	,1	,1	, &internal1_m1487_q0},	//(internal1_m1487_q0) q0 - внутренний параметр
	{ 1258	,1	,1	, &internal1_m1491_x0},	//(internal1_m1491_x0) был приход сигнала x1
	{ 1259	,8	,1	, &internal1_m1491_y0},	//(internal1_m1491_y0) интервал между сигналами х1 и х2
	{ 1260	,1	,1	, &internal1_m1917_x0},	//(internal1_m1917_x0) был приход сигнала x1
	{ 1261	,8	,1	, &internal1_m1917_y0},	//(internal1_m1917_y0) интервал между сигналами х1 и х2
	{ 1262	,1	,1	, &internal1_m1878_x0},	//(internal1_m1878_x0) был приход сигнала x1
	{ 1263	,8	,1	, &internal1_m1878_y0},	//(internal1_m1878_y0) интервал между сигналами х1 и х2
	{ 1264	,1	,1	, &internal1_m285_q0},	//(internal1_m285_q0) q0 - внутренний параметр
	{ 1265	,1	,1	, &internal1_m995_q0},	//(internal1_m995_q0) q0 - внутренний параметр
	{ 1266	,1	,1	, &internal1_m626_q0},	//(internal1_m626_q0) q0 - внутренний параметр
	{ 1267	,8	,1	, &internal1_m1310_X0},	//(internal1_m1310_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1268	,8	,1	, &internal1_m1310_t0},	//(internal1_m1310_t0) время нахождения в зоне возврата
	{ 1269	,18	,1	, &internal1_m1310_BLDv0},	//(internal1_m1310_BLDv0) BlDv - Блокировка движения
	{ 1270	,8	,1	, &internal1_m1329_tx},	//(internal1_m1329_tx) tx - время накопленное сек
	{ 1271	,18	,1	, &internal1_m1329_y0},	//(internal1_m1329_y0) y0
	{ 1272	,8	,1	, &internal1_m1331_tx},	//(internal1_m1331_tx) tx - время накопленное сек
	{ 1273	,18	,1	, &internal1_m1331_y0},	//(internal1_m1331_y0) y0
	{ 1274	,3	,1	, &internal1_m1338_xptr},	//(internal1_m1338_xptr) указатель текущей позиции в массиве координат
	{ 1275	,8	,60	, &internal1_m1338_x0},	//(internal1_m1338_x0) x0 - массив мгновенных значений координат
	{ 1276	,8	,60	, &internal1_m1338_tim0},	//(internal1_m1338_tim0) tim0 - массив значений времени цикла
	{ 1277	,8	,1	, &internal1_m1338_sumtim},	//(internal1_m1338_sumtim) sumtim - время в пути
	{ 1278	,8	,1	, &internal1_m1338_StSpeed},	//(internal1_m1338_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1279	,8	,1	, &internal1_m1338_Vz0},	//(internal1_m1338_Vz0) Vz0 - предыдущая заданная скорость
	{ 1280	,3	,1	, &internal1_m1338_flRazg},	//(internal1_m1338_flRazg) признак разгона/торможения
	{ 1281	,8	,1	, &internal1_m1338_DelSp},	//(internal1_m1338_DelSp) DelSp - время переключения скоростей
	{ 1282	,8	,1	, &internal1_m1338_z0},	//(internal1_m1338_z0) z0 - точка прекращения движения
	{ 1283	,8	,1	, &internal1_m1338_txZS},	//(internal1_m1338_txZS) txZS
	{ 1284	,8	,1	, &internal1_m1338_tx},	//(internal1_m1338_tx) tx
	{ 1285	,8	,1	, &internal1_m1338_txd},	//(internal1_m1338_txd) txd
	{ 1286	,8	,1	, &internal1_m1338_txMBl},	//(internal1_m1338_txMBl) tx
	{ 1287	,8	,1	, &internal1_m1338_txBl},	//(internal1_m1338_txBl) tx
	{ 1288	,8	,1	, &internal1_m1338_Speed0},	//(internal1_m1338_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1289	,8	,1	, &internal1_m1338_xz0},	//(internal1_m1338_xz0) xz0 - новое задание мм
	{ 1290	,8	,1	, &internal1_m1338_tz0},	//(internal1_m1338_tz0) tz0 - время защиты от нового задания сек
	{ 1291	,1	,1	, &internal1_m1338_Shift0},	//(internal1_m1338_Shift0) Shift0 - признак самохода
	{ 1292	,1	,1	, &internal1_m1338_ShCntlSp0},	//(internal1_m1338_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1293	,1	,1	, &internal1_m1338_ShiftControl},	//(internal1_m1338_ShiftControl) ShiftControl - признак самохода
	{ 1294	,1	,1	, &internal1_m624_q0},	//(internal1_m624_q0) q0 - внутренний параметр
	{ 1295	,8	,1	, &internal1_m893_X0},	//(internal1_m893_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1296	,8	,1	, &internal1_m893_t0},	//(internal1_m893_t0) время нахождения в зоне возврата
	{ 1297	,18	,1	, &internal1_m893_BLDv0},	//(internal1_m893_BLDv0) BlDv - Блокировка движения
	{ 1298	,8	,1	, &internal1_m917_tx},	//(internal1_m917_tx) tx - время накопленное сек
	{ 1299	,18	,1	, &internal1_m917_y0},	//(internal1_m917_y0) y0
	{ 1300	,8	,1	, &internal1_m919_tx},	//(internal1_m919_tx) tx - время накопленное сек
	{ 1301	,18	,1	, &internal1_m919_y0},	//(internal1_m919_y0) y0
	{ 1302	,3	,1	, &internal1_m926_xptr},	//(internal1_m926_xptr) указатель текущей позиции в массиве координат
	{ 1303	,8	,60	, &internal1_m926_x0},	//(internal1_m926_x0) x0 - массив мгновенных значений координат
	{ 1304	,8	,60	, &internal1_m926_tim0},	//(internal1_m926_tim0) tim0 - массив значений времени цикла
	{ 1305	,8	,1	, &internal1_m926_sumtim},	//(internal1_m926_sumtim) sumtim - время в пути
	{ 1306	,8	,1	, &internal1_m926_StSpeed},	//(internal1_m926_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1307	,8	,1	, &internal1_m926_Vz0},	//(internal1_m926_Vz0) Vz0 - предыдущая заданная скорость
	{ 1308	,3	,1	, &internal1_m926_flRazg},	//(internal1_m926_flRazg) признак разгона/торможения
	{ 1309	,8	,1	, &internal1_m926_DelSp},	//(internal1_m926_DelSp) DelSp - время переключения скоростей
	{ 1310	,8	,1	, &internal1_m926_z0},	//(internal1_m926_z0) z0 - точка прекращения движения
	{ 1311	,8	,1	, &internal1_m926_txZS},	//(internal1_m926_txZS) txZS
	{ 1312	,8	,1	, &internal1_m926_tx},	//(internal1_m926_tx) tx
	{ 1313	,8	,1	, &internal1_m926_txd},	//(internal1_m926_txd) txd
	{ 1314	,8	,1	, &internal1_m926_txMBl},	//(internal1_m926_txMBl) tx
	{ 1315	,8	,1	, &internal1_m926_txBl},	//(internal1_m926_txBl) tx
	{ 1316	,8	,1	, &internal1_m926_Speed0},	//(internal1_m926_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1317	,8	,1	, &internal1_m926_xz0},	//(internal1_m926_xz0) xz0 - новое задание мм
	{ 1318	,8	,1	, &internal1_m926_tz0},	//(internal1_m926_tz0) tz0 - время защиты от нового задания сек
	{ 1319	,1	,1	, &internal1_m926_Shift0},	//(internal1_m926_Shift0) Shift0 - признак самохода
	{ 1320	,1	,1	, &internal1_m926_ShCntlSp0},	//(internal1_m926_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1321	,1	,1	, &internal1_m926_ShiftControl},	//(internal1_m926_ShiftControl) ShiftControl - признак самохода
	{ 1322	,8	,1	, &internal1_m495_X0},	//(internal1_m495_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1323	,8	,1	, &internal1_m495_t0},	//(internal1_m495_t0) время нахождения в зоне возврата
	{ 1324	,18	,1	, &internal1_m495_BLDv0},	//(internal1_m495_BLDv0) BlDv - Блокировка движения
	{ 1325	,8	,1	, &internal1_m515_tx},	//(internal1_m515_tx) tx - время накопленное сек
	{ 1326	,18	,1	, &internal1_m515_y0},	//(internal1_m515_y0) y0
	{ 1327	,8	,1	, &internal1_m518_tx},	//(internal1_m518_tx) tx - время накопленное сек
	{ 1328	,18	,1	, &internal1_m518_y0},	//(internal1_m518_y0) y0
	{ 1329	,3	,1	, &internal1_m522_xptr},	//(internal1_m522_xptr) указатель текущей позиции в массиве координат
	{ 1330	,8	,150	, &internal1_m522_x0},	//(internal1_m522_x0) x0 - массив мгновенных значений координат
	{ 1331	,8	,150	, &internal1_m522_tim0},	//(internal1_m522_tim0) tim0 - массив значений времени цикла
	{ 1332	,8	,1	, &internal1_m522_sumtim},	//(internal1_m522_sumtim) sumtim - время в пути
	{ 1333	,8	,1	, &internal1_m522_StSpeed},	//(internal1_m522_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1334	,8	,1	, &internal1_m522_Vz0},	//(internal1_m522_Vz0) Vz0 - предыдущая заданная скорость
	{ 1335	,3	,1	, &internal1_m522_flRazg},	//(internal1_m522_flRazg) признак разгона/торможения
	{ 1336	,8	,1	, &internal1_m522_DelSp},	//(internal1_m522_DelSp) DelSp - время переключения скоростей
	{ 1337	,8	,1	, &internal1_m522_z0},	//(internal1_m522_z0) z0 - точка прекращения движения
	{ 1338	,8	,1	, &internal1_m522_txZS},	//(internal1_m522_txZS) txZS
	{ 1339	,8	,1	, &internal1_m522_tx},	//(internal1_m522_tx) tx
	{ 1340	,8	,1	, &internal1_m522_txd},	//(internal1_m522_txd) txd
	{ 1341	,8	,1	, &internal1_m522_txMBl},	//(internal1_m522_txMBl) tx
	{ 1342	,8	,1	, &internal1_m522_txBl},	//(internal1_m522_txBl) tx
	{ 1343	,8	,1	, &internal1_m522_Speed0},	//(internal1_m522_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1344	,8	,1	, &internal1_m522_xz0},	//(internal1_m522_xz0) xz0 - новое задание мм
	{ 1345	,8	,1	, &internal1_m522_tz0},	//(internal1_m522_tz0) tz0 - время защиты от нового задания сек
	{ 1346	,1	,1	, &internal1_m522_Shift0},	//(internal1_m522_Shift0) Shift0 - признак самохода
	{ 1347	,1	,1	, &internal1_m522_ShCntlSp0},	//(internal1_m522_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1348	,1	,1	, &internal1_m522_ShiftControl},	//(internal1_m522_ShiftControl) ShiftControl - признак самохода
	{ 1349	,1	,1	, &internal1_m621_q0},	//(internal1_m621_q0) q0 - внутренний параметр
	{ 1350	,8	,1	, &internal1_m174_X0},	//(internal1_m174_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1351	,8	,1	, &internal1_m174_t0},	//(internal1_m174_t0) время нахождения в зоне возврата
	{ 1352	,18	,1	, &internal1_m174_BLDv0},	//(internal1_m174_BLDv0) BlDv - Блокировка движения
	{ 1353	,3	,1	, &internal1_m203_xptr},	//(internal1_m203_xptr) указатель текущей позиции в массиве координат
	{ 1354	,8	,150	, &internal1_m203_x0},	//(internal1_m203_x0) x0 - массив мгновенных значений координат
	{ 1355	,8	,150	, &internal1_m203_tim0},	//(internal1_m203_tim0) tim0 - массив значений времени цикла
	{ 1356	,8	,1	, &internal1_m203_sumtim},	//(internal1_m203_sumtim) sumtim - время в пути
	{ 1357	,8	,1	, &internal1_m203_StSpeed},	//(internal1_m203_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1358	,8	,1	, &internal1_m203_Vz0},	//(internal1_m203_Vz0) Vz0 - предыдущая заданная скорость
	{ 1359	,3	,1	, &internal1_m203_flRazg},	//(internal1_m203_flRazg) признак разгона/торможения
	{ 1360	,8	,1	, &internal1_m203_DelSp},	//(internal1_m203_DelSp) DelSp - время переключения скоростей
	{ 1361	,8	,1	, &internal1_m203_z0},	//(internal1_m203_z0) z0 - точка прекращения движения
	{ 1362	,8	,1	, &internal1_m203_txZS},	//(internal1_m203_txZS) txZS
	{ 1363	,8	,1	, &internal1_m203_tx},	//(internal1_m203_tx) tx
	{ 1364	,8	,1	, &internal1_m203_txd},	//(internal1_m203_txd) txd
	{ 1365	,8	,1	, &internal1_m203_txMBl},	//(internal1_m203_txMBl) tx
	{ 1366	,8	,1	, &internal1_m203_txBl},	//(internal1_m203_txBl) tx
	{ 1367	,8	,1	, &internal1_m203_Speed0},	//(internal1_m203_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1368	,8	,1	, &internal1_m203_xz0},	//(internal1_m203_xz0) xz0 - новое задание мм
	{ 1369	,8	,1	, &internal1_m203_tz0},	//(internal1_m203_tz0) tz0 - время защиты от нового задания сек
	{ 1370	,1	,1	, &internal1_m203_Shift0},	//(internal1_m203_Shift0) Shift0 - признак самохода
	{ 1371	,1	,1	, &internal1_m203_ShCntlSp0},	//(internal1_m203_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1372	,1	,1	, &internal1_m203_ShiftControl},	//(internal1_m203_ShiftControl) ShiftControl - признак самохода
	{ 1373	,1	,1	, &internal1_m647_q0},	//(internal1_m647_q0) q0 - внутренний параметр
	{ 1374	,18	,1	, &internal1_m466_DvUp0},	//(internal1_m466_DvUp0) - есть команда на движение вперёд
	{ 1375	,18	,1	, &internal1_m466_DvDw0},	//(internal1_m466_DvDw0) - есть команда на движение назад
	{ 1376	,18	,1	, &internal1_m466_FDvUp0},	//(internal1_m466_FDvUp0) - есть команда на движение вперёд
	{ 1377	,18	,1	, &internal1_m466_FDvDw0},	//(internal1_m466_FDvDw0) - есть команда на движение назад
	{ 1378	,18	,1	, &internal1_m466_BlDv0},	//(internal1_m466_BlDv0) - была блокировка
	{ 1379	,18	,1	, &internal1_m466_Pkv0},	//(internal1_m466_Pkv0) Pkv - передний конечный выключатель
	{ 1380	,18	,1	, &internal1_m466_Pkav0},	//(internal1_m466_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1381	,18	,1	, &internal1_m466_Zkv0},	//(internal1_m466_Zkv0) Zkv - задний конечный выключатель
	{ 1382	,18	,1	, &internal1_m466_Zkav0},	//(internal1_m466_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1383	,8	,1	, &internal1_m466_txNm},	//(internal1_m466_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1384	,8	,1	, &internal1_m466_txSm},	//(internal1_m466_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1385	,8	,1	, &internal1_m466_txHr},	//(internal1_m466_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1386	,8	,1	, &internal1_m466_txLd},	//(internal1_m466_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1387	,18	,1	, &internal1_m466_fef},	//(internal1_m466_fef) fef
	{ 1388	,18	,1	, &internal1_m460_DvUp0},	//(internal1_m460_DvUp0) - есть команда на движение вперёд
	{ 1389	,18	,1	, &internal1_m460_DvDw0},	//(internal1_m460_DvDw0) - есть команда на движение назад
	{ 1390	,18	,1	, &internal1_m460_FDvUp0},	//(internal1_m460_FDvUp0) - есть команда на движение вперёд
	{ 1391	,18	,1	, &internal1_m460_FDvDw0},	//(internal1_m460_FDvDw0) - есть команда на движение назад
	{ 1392	,18	,1	, &internal1_m460_BlDv0},	//(internal1_m460_BlDv0) - была блокировка
	{ 1393	,18	,1	, &internal1_m460_Pkv0},	//(internal1_m460_Pkv0) Pkv - передний конечный выключатель
	{ 1394	,18	,1	, &internal1_m460_Pkav0},	//(internal1_m460_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1395	,18	,1	, &internal1_m460_Zkv0},	//(internal1_m460_Zkv0) Zkv - задний конечный выключатель
	{ 1396	,18	,1	, &internal1_m460_Zkav0},	//(internal1_m460_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1397	,8	,1	, &internal1_m460_txNm},	//(internal1_m460_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1398	,8	,1	, &internal1_m460_txSm},	//(internal1_m460_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1399	,8	,1	, &internal1_m460_txHr},	//(internal1_m460_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1400	,8	,1	, &internal1_m460_txLd},	//(internal1_m460_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1401	,18	,1	, &internal1_m460_fef},	//(internal1_m460_fef) fef
	{ 1402	,8	,1	, &internal1_m813_X0},	//(internal1_m813_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1403	,8	,1	, &internal1_m813_t0},	//(internal1_m813_t0) время нахождения в зоне возврата
	{ 1404	,18	,1	, &internal1_m813_BLDv0},	//(internal1_m813_BLDv0) BlDv - Блокировка движения
	{ 1405	,3	,1	, &internal1_m833_xptr},	//(internal1_m833_xptr) указатель текущей позиции в массиве координат
	{ 1406	,8	,80	, &internal1_m833_x0},	//(internal1_m833_x0) x0 - массив мгновенных значений координат
	{ 1407	,8	,80	, &internal1_m833_tim0},	//(internal1_m833_tim0) tim0 - массив значений времени цикла
	{ 1408	,8	,1	, &internal1_m833_sumtim},	//(internal1_m833_sumtim) sumtim - время в пути
	{ 1409	,8	,1	, &internal1_m833_StSpeed},	//(internal1_m833_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1410	,8	,1	, &internal1_m833_Vz0},	//(internal1_m833_Vz0) Vz0 - предыдущая заданная скорость
	{ 1411	,3	,1	, &internal1_m833_flRazg},	//(internal1_m833_flRazg) признак разгона/торможения
	{ 1412	,8	,1	, &internal1_m833_DelSp},	//(internal1_m833_DelSp) DelSp - время переключения скоростей
	{ 1413	,8	,1	, &internal1_m833_z0},	//(internal1_m833_z0) z0 - точка прекращения движения
	{ 1414	,8	,1	, &internal1_m833_txZS},	//(internal1_m833_txZS) txZS
	{ 1415	,8	,1	, &internal1_m833_tx},	//(internal1_m833_tx) tx
	{ 1416	,8	,1	, &internal1_m833_txd},	//(internal1_m833_txd) txd
	{ 1417	,8	,1	, &internal1_m833_txMBl},	//(internal1_m833_txMBl) tx
	{ 1418	,8	,1	, &internal1_m833_txBl},	//(internal1_m833_txBl) tx
	{ 1419	,8	,1	, &internal1_m833_Speed0},	//(internal1_m833_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1420	,8	,1	, &internal1_m833_xz0},	//(internal1_m833_xz0) xz0 - новое задание мм
	{ 1421	,8	,1	, &internal1_m833_tz0},	//(internal1_m833_tz0) tz0 - время защиты от нового задания сек
	{ 1422	,1	,1	, &internal1_m833_Shift0},	//(internal1_m833_Shift0) Shift0 - признак самохода
	{ 1423	,1	,1	, &internal1_m833_ShCntlSp0},	//(internal1_m833_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1424	,1	,1	, &internal1_m833_ShiftControl},	//(internal1_m833_ShiftControl) ShiftControl - признак самохода
	{ 1425	,8	,1	, &internal1_m1592_X0},	//(internal1_m1592_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1426	,8	,1	, &internal1_m1592_t0},	//(internal1_m1592_t0) время нахождения в зоне возврата
	{ 1427	,18	,1	, &internal1_m1592_BLDv0},	//(internal1_m1592_BLDv0) BlDv - Блокировка движения
	{ 1428	,8	,1	, &internal1_m1116_X0},	//(internal1_m1116_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1429	,8	,1	, &internal1_m1116_t0},	//(internal1_m1116_t0) время нахождения в зоне возврата
	{ 1430	,18	,1	, &internal1_m1116_BLDv0},	//(internal1_m1116_BLDv0) BlDv - Блокировка движения
	{ 1431	,1	,1	, &internal1_m619_q0},	//(internal1_m619_q0) q0 - внутренний параметр
	{ 1432	,8	,1	, &internal1_m1213_X0},	//(internal1_m1213_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1433	,8	,1	, &internal1_m1213_t0},	//(internal1_m1213_t0) время нахождения в зоне возврата
	{ 1434	,18	,1	, &internal1_m1213_BLDv0},	//(internal1_m1213_BLDv0) BlDv - Блокировка движения
	{ 1435	,8	,1	, &internal1_m1233_tx},	//(internal1_m1233_tx) tx - время накопленное сек
	{ 1436	,18	,1	, &internal1_m1233_y0},	//(internal1_m1233_y0) y0
	{ 1437	,8	,1	, &internal1_m1242_tx},	//(internal1_m1242_tx) tx - время накопленное сек
	{ 1438	,18	,1	, &internal1_m1242_y0},	//(internal1_m1242_y0) y0
	{ 1439	,3	,1	, &internal1_m1248_xptr},	//(internal1_m1248_xptr) указатель текущей позиции в массиве координат
	{ 1440	,8	,80	, &internal1_m1248_x0},	//(internal1_m1248_x0) x0 - массив мгновенных значений координат
	{ 1441	,8	,80	, &internal1_m1248_tim0},	//(internal1_m1248_tim0) tim0 - массив значений времени цикла
	{ 1442	,8	,1	, &internal1_m1248_sumtim},	//(internal1_m1248_sumtim) sumtim - время в пути
	{ 1443	,8	,1	, &internal1_m1248_StSpeed},	//(internal1_m1248_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1444	,8	,1	, &internal1_m1248_Vz0},	//(internal1_m1248_Vz0) Vz0 - предыдущая заданная скорость
	{ 1445	,3	,1	, &internal1_m1248_flRazg},	//(internal1_m1248_flRazg) признак разгона/торможения
	{ 1446	,8	,1	, &internal1_m1248_DelSp},	//(internal1_m1248_DelSp) DelSp - время переключения скоростей
	{ 1447	,8	,1	, &internal1_m1248_z0},	//(internal1_m1248_z0) z0 - точка прекращения движения
	{ 1448	,8	,1	, &internal1_m1248_txZS},	//(internal1_m1248_txZS) txZS
	{ 1449	,8	,1	, &internal1_m1248_tx},	//(internal1_m1248_tx) tx
	{ 1450	,8	,1	, &internal1_m1248_txd},	//(internal1_m1248_txd) txd
	{ 1451	,8	,1	, &internal1_m1248_txMBl},	//(internal1_m1248_txMBl) tx
	{ 1452	,8	,1	, &internal1_m1248_txBl},	//(internal1_m1248_txBl) tx
	{ 1453	,8	,1	, &internal1_m1248_Speed0},	//(internal1_m1248_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1454	,8	,1	, &internal1_m1248_xz0},	//(internal1_m1248_xz0) xz0 - новое задание мм
	{ 1455	,8	,1	, &internal1_m1248_tz0},	//(internal1_m1248_tz0) tz0 - время защиты от нового задания сек
	{ 1456	,1	,1	, &internal1_m1248_Shift0},	//(internal1_m1248_Shift0) Shift0 - признак самохода
	{ 1457	,1	,1	, &internal1_m1248_ShCntlSp0},	//(internal1_m1248_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1458	,1	,1	, &internal1_m1248_ShiftControl},	//(internal1_m1248_ShiftControl) ShiftControl - признак самохода
	{ 1459	,1	,1	, &internal1_m639_q0},	//(internal1_m639_q0) q0 - внутренний параметр
	{ 1460	,8	,1	, &internal1_m1605_tx},	//(internal1_m1605_tx) tx - время накопленное сек
	{ 1461	,18	,1	, &internal1_m1605_y0},	//(internal1_m1605_y0) y0
	{ 1462	,8	,1	, &internal1_m1607_tx},	//(internal1_m1607_tx) tx - время накопленное сек
	{ 1463	,18	,1	, &internal1_m1607_y0},	//(internal1_m1607_y0) y0
	{ 1464	,18	,1	, &internal1_m1595_DvUp0},	//(internal1_m1595_DvUp0) - есть команда на движение вперёд
	{ 1465	,18	,1	, &internal1_m1595_DvDw0},	//(internal1_m1595_DvDw0) - есть команда на движение назад
	{ 1466	,18	,1	, &internal1_m1595_FDvUp0},	//(internal1_m1595_FDvUp0) - есть команда на движение вперёд
	{ 1467	,18	,1	, &internal1_m1595_FDvDw0},	//(internal1_m1595_FDvDw0) - есть команда на движение назад
	{ 1468	,18	,1	, &internal1_m1595_BlDv0},	//(internal1_m1595_BlDv0) - была блокировка
	{ 1469	,18	,1	, &internal1_m1595_Pkv0},	//(internal1_m1595_Pkv0) Pkv - передний конечный выключатель
	{ 1470	,18	,1	, &internal1_m1595_Pkav0},	//(internal1_m1595_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1471	,18	,1	, &internal1_m1595_Zkv0},	//(internal1_m1595_Zkv0) Zkv - задний конечный выключатель
	{ 1472	,18	,1	, &internal1_m1595_Zkav0},	//(internal1_m1595_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1473	,8	,1	, &internal1_m1595_txNm},	//(internal1_m1595_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1474	,8	,1	, &internal1_m1595_txSm},	//(internal1_m1595_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1475	,8	,1	, &internal1_m1595_txHr},	//(internal1_m1595_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1476	,8	,1	, &internal1_m1595_txLd},	//(internal1_m1595_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1477	,18	,1	, &internal1_m1595_fef},	//(internal1_m1595_fef) fef
	{ 1478	,3	,1	, &internal1_m1612_xptr},	//(internal1_m1612_xptr) указатель текущей позиции в массиве координат
	{ 1479	,8	,20	, &internal1_m1612_x0},	//(internal1_m1612_x0) x0 - массив мгновенных значений координат
	{ 1480	,8	,20	, &internal1_m1612_tim0},	//(internal1_m1612_tim0) tim0 - массив значений времени цикла
	{ 1481	,8	,1	, &internal1_m1612_sumtim},	//(internal1_m1612_sumtim) sumtim - время в пути
	{ 1482	,8	,1	, &internal1_m1612_StSpeed},	//(internal1_m1612_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1483	,8	,1	, &internal1_m1612_Vz0},	//(internal1_m1612_Vz0) Vz0 - предыдущая заданная скорость
	{ 1484	,3	,1	, &internal1_m1612_flRazg},	//(internal1_m1612_flRazg) признак разгона/торможения
	{ 1485	,8	,1	, &internal1_m1612_DelSp},	//(internal1_m1612_DelSp) DelSp - время переключения скоростей
	{ 1486	,8	,1	, &internal1_m1612_z0},	//(internal1_m1612_z0) z0 - точка прекращения движения
	{ 1487	,8	,1	, &internal1_m1612_txZS},	//(internal1_m1612_txZS) txZS
	{ 1488	,8	,1	, &internal1_m1612_tx},	//(internal1_m1612_tx) tx
	{ 1489	,8	,1	, &internal1_m1612_txd},	//(internal1_m1612_txd) txd
	{ 1490	,8	,1	, &internal1_m1612_txMBl},	//(internal1_m1612_txMBl) tx
	{ 1491	,8	,1	, &internal1_m1612_txBl},	//(internal1_m1612_txBl) tx
	{ 1492	,8	,1	, &internal1_m1612_Speed0},	//(internal1_m1612_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1493	,8	,1	, &internal1_m1612_xz0},	//(internal1_m1612_xz0) xz0 - новое задание мм
	{ 1494	,8	,1	, &internal1_m1612_tz0},	//(internal1_m1612_tz0) tz0 - время защиты от нового задания сек
	{ 1495	,1	,1	, &internal1_m1612_Shift0},	//(internal1_m1612_Shift0) Shift0 - признак самохода
	{ 1496	,1	,1	, &internal1_m1612_ShCntlSp0},	//(internal1_m1612_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1497	,1	,1	, &internal1_m1612_ShiftControl},	//(internal1_m1612_ShiftControl) ShiftControl - признак самохода
	{ 1498	,8	,1	, &internal1_m1129_tx},	//(internal1_m1129_tx) tx - время накопленное сек
	{ 1499	,18	,1	, &internal1_m1129_y0},	//(internal1_m1129_y0) y0
	{ 1500	,8	,1	, &internal1_m1133_tx},	//(internal1_m1133_tx) tx - время накопленное сек
	{ 1501	,18	,1	, &internal1_m1133_y0},	//(internal1_m1133_y0) y0
	{ 1502	,1	,1	, &internal1_m629_q0},	//(internal1_m629_q0) q0 - внутренний параметр
	{ 1503	,1	,1	, &internal1_m594_q0},	//(internal1_m594_q0) q0 - внутренний параметр
	{ 1504	,18	,1	, &internal1_m1119_DvUp0},	//(internal1_m1119_DvUp0) - есть команда на движение вперёд
	{ 1505	,18	,1	, &internal1_m1119_DvDw0},	//(internal1_m1119_DvDw0) - есть команда на движение назад
	{ 1506	,18	,1	, &internal1_m1119_FDvUp0},	//(internal1_m1119_FDvUp0) - есть команда на движение вперёд
	{ 1507	,18	,1	, &internal1_m1119_FDvDw0},	//(internal1_m1119_FDvDw0) - есть команда на движение назад
	{ 1508	,18	,1	, &internal1_m1119_BlDv0},	//(internal1_m1119_BlDv0) - была блокировка
	{ 1509	,18	,1	, &internal1_m1119_Pkv0},	//(internal1_m1119_Pkv0) Pkv - передний конечный выключатель
	{ 1510	,18	,1	, &internal1_m1119_Pkav0},	//(internal1_m1119_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1511	,18	,1	, &internal1_m1119_Zkv0},	//(internal1_m1119_Zkv0) Zkv - задний конечный выключатель
	{ 1512	,18	,1	, &internal1_m1119_Zkav0},	//(internal1_m1119_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1513	,8	,1	, &internal1_m1119_txNm},	//(internal1_m1119_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1514	,8	,1	, &internal1_m1119_txSm},	//(internal1_m1119_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1515	,8	,1	, &internal1_m1119_txHr},	//(internal1_m1119_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1516	,8	,1	, &internal1_m1119_txLd},	//(internal1_m1119_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1517	,18	,1	, &internal1_m1119_fef},	//(internal1_m1119_fef) fef
	{ 1518	,3	,1	, &internal1_m1137_xptr},	//(internal1_m1137_xptr) указатель текущей позиции в массиве координат
	{ 1519	,8	,20	, &internal1_m1137_x0},	//(internal1_m1137_x0) x0 - массив мгновенных значений координат
	{ 1520	,8	,20	, &internal1_m1137_tim0},	//(internal1_m1137_tim0) tim0 - массив значений времени цикла
	{ 1521	,8	,1	, &internal1_m1137_sumtim},	//(internal1_m1137_sumtim) sumtim - время в пути
	{ 1522	,8	,1	, &internal1_m1137_StSpeed},	//(internal1_m1137_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1523	,8	,1	, &internal1_m1137_Vz0},	//(internal1_m1137_Vz0) Vz0 - предыдущая заданная скорость
	{ 1524	,3	,1	, &internal1_m1137_flRazg},	//(internal1_m1137_flRazg) признак разгона/торможения
	{ 1525	,8	,1	, &internal1_m1137_DelSp},	//(internal1_m1137_DelSp) DelSp - время переключения скоростей
	{ 1526	,8	,1	, &internal1_m1137_z0},	//(internal1_m1137_z0) z0 - точка прекращения движения
	{ 1527	,8	,1	, &internal1_m1137_txZS},	//(internal1_m1137_txZS) txZS
	{ 1528	,8	,1	, &internal1_m1137_tx},	//(internal1_m1137_tx) tx
	{ 1529	,8	,1	, &internal1_m1137_txd},	//(internal1_m1137_txd) txd
	{ 1530	,8	,1	, &internal1_m1137_txMBl},	//(internal1_m1137_txMBl) tx
	{ 1531	,8	,1	, &internal1_m1137_txBl},	//(internal1_m1137_txBl) tx
	{ 1532	,8	,1	, &internal1_m1137_Speed0},	//(internal1_m1137_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1533	,8	,1	, &internal1_m1137_xz0},	//(internal1_m1137_xz0) xz0 - новое задание мм
	{ 1534	,8	,1	, &internal1_m1137_tz0},	//(internal1_m1137_tz0) tz0 - время защиты от нового задания сек
	{ 1535	,1	,1	, &internal1_m1137_Shift0},	//(internal1_m1137_Shift0) Shift0 - признак самохода
	{ 1536	,1	,1	, &internal1_m1137_ShCntlSp0},	//(internal1_m1137_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1537	,1	,1	, &internal1_m1137_ShiftControl},	//(internal1_m1137_ShiftControl) ShiftControl - признак самохода
	{ 1538	,1	,1	, &internal1_m742_x0},	//(internal1_m742_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1539	,1	,1	, &internal1_m711_x0},	//(internal1_m711_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1540	,1	,1	, &internal1_m675_x0},	//(internal1_m675_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1541	,1	,1	, &internal1_m767_q0},	//(internal1_m767_q0) q0 - внутренний параметр
	{ 1542	,1	,1	, &internal1_m762_q0},	//(internal1_m762_q0) q0 - внутренний параметр
	{ 1543	,1	,1	, &internal1_m730_q0},	//(internal1_m730_q0) q0 - внутренний параметр
	{ 1544	,1	,1	, &internal1_m735_q0},	//(internal1_m735_q0) q0 - внутренний параметр
	{ 1545	,1	,1	, &internal1_m743_q0},	//(internal1_m743_q0) q0 - внутренний параметр
	{ 1546	,1	,1	, &internal1_m755_q0},	//(internal1_m755_q0) q0 - внутренний параметр
	{ 1547	,1	,1	, &internal1_m733_q0},	//(internal1_m733_q0) q0 - внутренний параметр
	{ 1548	,18	,1	, &internal1_m1190_DvUp0},	//(internal1_m1190_DvUp0) - есть команда на движение вперёд
	{ 1549	,18	,1	, &internal1_m1190_DvDw0},	//(internal1_m1190_DvDw0) - есть команда на движение назад
	{ 1550	,18	,1	, &internal1_m1190_FDvUp0},	//(internal1_m1190_FDvUp0) - есть команда на движение вперёд
	{ 1551	,18	,1	, &internal1_m1190_FDvDw0},	//(internal1_m1190_FDvDw0) - есть команда на движение назад
	{ 1552	,18	,1	, &internal1_m1190_BlDv0},	//(internal1_m1190_BlDv0) - была блокировка
	{ 1553	,18	,1	, &internal1_m1190_Pkv0},	//(internal1_m1190_Pkv0) Pkv - передний конечный выключатель
	{ 1554	,18	,1	, &internal1_m1190_Pkav0},	//(internal1_m1190_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1555	,18	,1	, &internal1_m1190_Zkv0},	//(internal1_m1190_Zkv0) Zkv - задний конечный выключатель
	{ 1556	,18	,1	, &internal1_m1190_Zkav0},	//(internal1_m1190_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1557	,8	,1	, &internal1_m1190_txNm},	//(internal1_m1190_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1558	,8	,1	, &internal1_m1190_txSm},	//(internal1_m1190_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1559	,8	,1	, &internal1_m1190_txHr},	//(internal1_m1190_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1560	,8	,1	, &internal1_m1190_txLd},	//(internal1_m1190_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1561	,18	,1	, &internal1_m1190_fef},	//(internal1_m1190_fef) fef
	{ 1562	,18	,1	, &internal1_m1179_DvUp0},	//(internal1_m1179_DvUp0) - есть команда на движение вперёд
	{ 1563	,18	,1	, &internal1_m1179_DvDw0},	//(internal1_m1179_DvDw0) - есть команда на движение назад
	{ 1564	,18	,1	, &internal1_m1179_FDvUp0},	//(internal1_m1179_FDvUp0) - есть команда на движение вперёд
	{ 1565	,18	,1	, &internal1_m1179_FDvDw0},	//(internal1_m1179_FDvDw0) - есть команда на движение назад
	{ 1566	,18	,1	, &internal1_m1179_BlDv0},	//(internal1_m1179_BlDv0) - была блокировка
	{ 1567	,18	,1	, &internal1_m1179_Pkv0},	//(internal1_m1179_Pkv0) Pkv - передний конечный выключатель
	{ 1568	,18	,1	, &internal1_m1179_Pkav0},	//(internal1_m1179_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1569	,18	,1	, &internal1_m1179_Zkv0},	//(internal1_m1179_Zkv0) Zkv - задний конечный выключатель
	{ 1570	,18	,1	, &internal1_m1179_Zkav0},	//(internal1_m1179_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1571	,8	,1	, &internal1_m1179_txNm},	//(internal1_m1179_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1572	,8	,1	, &internal1_m1179_txSm},	//(internal1_m1179_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1573	,8	,1	, &internal1_m1179_txHr},	//(internal1_m1179_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1574	,8	,1	, &internal1_m1179_txLd},	//(internal1_m1179_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1575	,18	,1	, &internal1_m1179_fef},	//(internal1_m1179_fef) fef
	{ 1576	,18	,1	, &internal1_m787_DvUp0},	//(internal1_m787_DvUp0) - есть команда на движение вперёд
	{ 1577	,18	,1	, &internal1_m787_DvDw0},	//(internal1_m787_DvDw0) - есть команда на движение назад
	{ 1578	,18	,1	, &internal1_m787_FDvUp0},	//(internal1_m787_FDvUp0) - есть команда на движение вперёд
	{ 1579	,18	,1	, &internal1_m787_FDvDw0},	//(internal1_m787_FDvDw0) - есть команда на движение назад
	{ 1580	,18	,1	, &internal1_m787_BlDv0},	//(internal1_m787_BlDv0) - была блокировка
	{ 1581	,18	,1	, &internal1_m787_Pkv0},	//(internal1_m787_Pkv0) Pkv - передний конечный выключатель
	{ 1582	,18	,1	, &internal1_m787_Pkav0},	//(internal1_m787_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1583	,18	,1	, &internal1_m787_Zkv0},	//(internal1_m787_Zkv0) Zkv - задний конечный выключатель
	{ 1584	,18	,1	, &internal1_m787_Zkav0},	//(internal1_m787_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1585	,8	,1	, &internal1_m787_txNm},	//(internal1_m787_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1586	,8	,1	, &internal1_m787_txSm},	//(internal1_m787_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1587	,8	,1	, &internal1_m787_txHr},	//(internal1_m787_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1588	,8	,1	, &internal1_m787_txLd},	//(internal1_m787_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1589	,18	,1	, &internal1_m787_fef},	//(internal1_m787_fef) fef
	{ 1590	,18	,1	, &internal1_m783_DvUp0},	//(internal1_m783_DvUp0) - есть команда на движение вперёд
	{ 1591	,18	,1	, &internal1_m783_DvDw0},	//(internal1_m783_DvDw0) - есть команда на движение назад
	{ 1592	,18	,1	, &internal1_m783_FDvUp0},	//(internal1_m783_FDvUp0) - есть команда на движение вперёд
	{ 1593	,18	,1	, &internal1_m783_FDvDw0},	//(internal1_m783_FDvDw0) - есть команда на движение назад
	{ 1594	,18	,1	, &internal1_m783_BlDv0},	//(internal1_m783_BlDv0) - была блокировка
	{ 1595	,18	,1	, &internal1_m783_Pkv0},	//(internal1_m783_Pkv0) Pkv - передний конечный выключатель
	{ 1596	,18	,1	, &internal1_m783_Pkav0},	//(internal1_m783_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1597	,18	,1	, &internal1_m783_Zkv0},	//(internal1_m783_Zkv0) Zkv - задний конечный выключатель
	{ 1598	,18	,1	, &internal1_m783_Zkav0},	//(internal1_m783_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1599	,8	,1	, &internal1_m783_txNm},	//(internal1_m783_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1600	,8	,1	, &internal1_m783_txSm},	//(internal1_m783_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1601	,8	,1	, &internal1_m783_txHr},	//(internal1_m783_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1602	,8	,1	, &internal1_m783_txLd},	//(internal1_m783_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1603	,18	,1	, &internal1_m783_fef},	//(internal1_m783_fef) fef
	{ 1604	,18	,1	, &internal1_m365_DvUp0},	//(internal1_m365_DvUp0) - есть команда на движение вперёд
	{ 1605	,18	,1	, &internal1_m365_DvDw0},	//(internal1_m365_DvDw0) - есть команда на движение назад
	{ 1606	,18	,1	, &internal1_m365_FDvUp0},	//(internal1_m365_FDvUp0) - есть команда на движение вперёд
	{ 1607	,18	,1	, &internal1_m365_FDvDw0},	//(internal1_m365_FDvDw0) - есть команда на движение назад
	{ 1608	,18	,1	, &internal1_m365_BlDv0},	//(internal1_m365_BlDv0) - была блокировка
	{ 1609	,18	,1	, &internal1_m365_Pkv0},	//(internal1_m365_Pkv0) Pkv - передний конечный выключатель
	{ 1610	,18	,1	, &internal1_m365_Pkav0},	//(internal1_m365_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1611	,18	,1	, &internal1_m365_Zkv0},	//(internal1_m365_Zkv0) Zkv - задний конечный выключатель
	{ 1612	,18	,1	, &internal1_m365_Zkav0},	//(internal1_m365_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1613	,8	,1	, &internal1_m365_txNm},	//(internal1_m365_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1614	,8	,1	, &internal1_m365_txSm},	//(internal1_m365_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1615	,8	,1	, &internal1_m365_txHr},	//(internal1_m365_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1616	,8	,1	, &internal1_m365_txLd},	//(internal1_m365_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1617	,18	,1	, &internal1_m365_fef},	//(internal1_m365_fef) fef
	{ 1618	,18	,1	, &internal1_m394_DvUp0},	//(internal1_m394_DvUp0) - есть команда на движение вперёд
	{ 1619	,18	,1	, &internal1_m394_DvDw0},	//(internal1_m394_DvDw0) - есть команда на движение назад
	{ 1620	,18	,1	, &internal1_m394_FDvUp0},	//(internal1_m394_FDvUp0) - есть команда на движение вперёд
	{ 1621	,18	,1	, &internal1_m394_FDvDw0},	//(internal1_m394_FDvDw0) - есть команда на движение назад
	{ 1622	,18	,1	, &internal1_m394_BlDv0},	//(internal1_m394_BlDv0) - была блокировка
	{ 1623	,18	,1	, &internal1_m394_Pkv0},	//(internal1_m394_Pkv0) Pkv - передний конечный выключатель
	{ 1624	,18	,1	, &internal1_m394_Pkav0},	//(internal1_m394_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1625	,18	,1	, &internal1_m394_Zkv0},	//(internal1_m394_Zkv0) Zkv - задний конечный выключатель
	{ 1626	,18	,1	, &internal1_m394_Zkav0},	//(internal1_m394_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1627	,8	,1	, &internal1_m394_txNm},	//(internal1_m394_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1628	,8	,1	, &internal1_m394_txSm},	//(internal1_m394_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1629	,8	,1	, &internal1_m394_txHr},	//(internal1_m394_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1630	,8	,1	, &internal1_m394_txLd},	//(internal1_m394_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1631	,18	,1	, &internal1_m394_fef},	//(internal1_m394_fef) fef
	{ 1632	,18	,1	, &internal1_m388_DvUp0},	//(internal1_m388_DvUp0) - есть команда на движение вперёд
	{ 1633	,18	,1	, &internal1_m388_DvDw0},	//(internal1_m388_DvDw0) - есть команда на движение назад
	{ 1634	,18	,1	, &internal1_m388_FDvUp0},	//(internal1_m388_FDvUp0) - есть команда на движение вперёд
	{ 1635	,18	,1	, &internal1_m388_FDvDw0},	//(internal1_m388_FDvDw0) - есть команда на движение назад
	{ 1636	,18	,1	, &internal1_m388_BlDv0},	//(internal1_m388_BlDv0) - была блокировка
	{ 1637	,18	,1	, &internal1_m388_Pkv0},	//(internal1_m388_Pkv0) Pkv - передний конечный выключатель
	{ 1638	,18	,1	, &internal1_m388_Pkav0},	//(internal1_m388_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1639	,18	,1	, &internal1_m388_Zkv0},	//(internal1_m388_Zkv0) Zkv - задний конечный выключатель
	{ 1640	,18	,1	, &internal1_m388_Zkav0},	//(internal1_m388_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1641	,8	,1	, &internal1_m388_txNm},	//(internal1_m388_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1642	,8	,1	, &internal1_m388_txSm},	//(internal1_m388_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1643	,8	,1	, &internal1_m388_txHr},	//(internal1_m388_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1644	,8	,1	, &internal1_m388_txLd},	//(internal1_m388_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1645	,18	,1	, &internal1_m388_fef},	//(internal1_m388_fef) fef
	{ 1646	,1	,1	, &internal1_m739_q0},	//(internal1_m739_q0) q0 - внутренний параметр
	{ 1647	,1	,1	, &internal1_m736_q0},	//(internal1_m736_q0) q0 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="du.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{758,"fEM_A1UC03RDU\0"}, 
{759,"dEM_A1UC05UDU\0"}, 
{760,"dEM_A1UC06UDU\0"}, 
{761,"dEM_A2UC06UDU\0"}, 
{762,"dEM_A2UC05UDU\0"}, 
{763,"fEM_A2UC03RDU\0"}, 
{764,"dEM_A3UC06UDU\0"}, 
{765,"dEM_A3UC05UDU\0"}, 
{766,"fEM_A3UC03RDU\0"}, 
{767,"dEM_A8UC06UDU\0"}, 
{768,"fEM_A8UC03RDU\0"}, 
{769,"dEM_A8UC05UDU\0"}, 
{770,"fEM_R0UV81RDU\0"}, 
{771,"fEM_R0UV82RDU\0"}, 
{772,"fEM_R0UV83RDU\0"}, 
{773,"fEM_R0UV84RDU\0"}, 
{774,"fEM_R0UV86RDU\0"}, 
{775,"fEM_R0UV85RDU\0"}, 
{776,"fEM_R0UV87RDU\0"}, 
{777,"fEM_A3UP03RDU\0"}, 
{778,"fEM_A3UP04RDU\0"}, 
{779,"fEM_A3UP43RDU\0"}, 
{780,"fEM_A3UP44RDU\0"}, 
{781,"fEM_A3UP53RDU\0"}, 
{782,"fEM_A3UP85RDU\0"}, 
{783,"fEM_A3UP88RDU\0"}, 
{784,"fEM_A3UP86RDU\0"}, 
{785,"fEM_B8UV01RDU\0"}, 
{786,"fEM_B8UV02RDU\0"}, 
{787,"fEM_B8UV03RDU\0"}, 
{788,"fEM_B8UL04RDU\0"}, 
{789,"iEM_A2UV03CDU\0"}, 
{790,"fEM_A2UV01RDU\0"}, 
{791,"fEM_A2UV02RDU\0"}, 
{792,"fEM_A1UV01RDU\0"}, 
{793,"fEM_A1UV02RDU\0"}, 
{794,"fEM_A1UC06RDU\0"}, 
{795,"fEM_A1UC05RDU\0"}, 
{796,"fEM_A1UL04RDU\0"}, 
{797,"fEM_A3UV01RDU\0"}, 
{798,"fEM_A3UV02RDU\0"}, 
{799,"fEM_A3UC06RDU\0"}, 
{800,"fEM_A3UC05RDU\0"}, 
{801,"fEM_A3UL04RDU\0"}, 
{802,"fEM_A3UP54RDU\0"}, 
{803,"fEM_A3UP87RDU\0"}, 
{804,"fEM_R0UL05RDU\0"}, 
{805,"fEM_R0UL20RDU\0"}, 
{806,"fEM_B8UV04RDU\0"}, 
{807,"fEM_B8UC06RDU\0"}, 
{808,"fEM_B8UC05RDU\0"}, 
{809,"fEM_A2UL05RDU\0"}, 
{810,"fEM_A2UL03RDU\0"}, 
{811,"fEM_A2UC06RDU\0"}, 
{812,"fEM_A2UC05RDU\0"}, 
{813,"fEM_A2UL04RDU\0"}, 
{814,"fEM_A1UL03RDU\0"}, 
{815,"fEM_A1UL05RDU\0"}, 
{816,"fEM_A3UL03RDU\0"}, 
{817,"fEM_A3UL05RDU\0"}, 
{818,"fEM_A1UC08RDU\0"}, 
{819,"fEM_A3UC08RDU\0"}, 
{820,"fEM_A1UC07RDU\0"}, 
{821,"fEM_A1UL01RDU\0"}, 
{822,"fEM_A3UC07RDU\0"}, 
{823,"fEM_A3UL01RDU\0"}, 
{824,"fEM_A2UC08RDU\0"}, 
{825,"fEM_A2UC07RDU\0"}, 
{826,"fEM_A2UL01RDU\0"}, 
{827,"fEM_B8UC01RDU\0"}, 
{828,"fEM_B8UL07RDU\0"}, 
{829,"fEM_B8UC02RDU\0"}, 
{830,"fEM_B8UL01RDU\0"}, 
{831,"fEM_B8UL05RDU\0"}, 
{832,"fEM_B8UL03RDU\0"}, 
{833,"fEM_B8UL06RDU\0"}, 
{834,"fEM_A9UZ03RDU\0"}, 
{835,"fEM_A9UZ04RDU\0"}, 
{836,"fEM_A9UZ05RDU\0"}, 
{837,"fEM_R4UZ04RDU\0"}, 
{838,"fEM_R4UZ03RDU\0"}, 
{839,"fEM_R4UZ05RDU\0"}, 
{840,"fEM_A5UZ03RDU\0"}, 
{841,"fEM_A5UZ04RDU\0"}, 
{842,"fEM_A5UZ05RDU\0"}, 
{843,"fEM_A4UZ03RDU\0"}, 
{844,"fEM_A4UZ04RDU\0"}, 
{845,"fEM_A4UZ05RDU\0"}, 
{846,"fEM_A6UZ03RDU\0"}, 
{847,"fEM_A6UZ04RDU\0"}, 
{848,"fEM_A6UZ05RDU\0"}, 
{849,"fEM_R1UZ03RDU\0"}, 
{850,"fEM_R1UZ04RDU\0"}, 
{851,"fEM_R1UZ05RDU\0"}, 
{852,"fEM_R0UL04RDU\0"}, 
{853,"fEM_R0UL06RDU\0"}, 
{854,"fEM_R0UL03RDU\0"}, 
{855,"fEM_R0UL17RDU\0"}, 
{856,"fEM_R0UL19RDU\0"}, 
{857,"fEM_R0UL07RDU\0"}, 
{858,"fEM_R0UL18RDU\0"}, 
{859,"fEM_R0UL16RDU\0"}, 
{860,"fEM_R0UL02RDU\0"}, 
{861,"fEM_R0UN08RDU\0"}, 
{862,"fEM_R0UN07RDU\0"}, 
{863,"fEM_R0UN06RDU\0"}, 
{864,"fEM_R0UN05RDU\0"}, 
{865,"fEM_R0UN04RDU\0"}, 
{866,"fEM_R0UN03RDU\0"}, 
{867,"fEM_R0UN02RDU\0"}, 
{868,"fEM_R0UN01RDU\0"}, 
{869,"fEM_A2UC82RDU\0"}, 
{870,"fEM_A2UC83RDU\0"}, 
{871,"fEM_A1UC83RDU\0"}, 
{872,"fEM_A2UC81RDU\0"}, 
{873,"fEM_A1UC81RDU\0"}, 
{874,"fEM_A1UC82RDU\0"}, 
{875,"fEM_A2UL83RDU\0"}, 
{876,"fEM_A3UC81RDU\0"}, 
{877,"fEM_A3UC82RDU\0"}, 
{878,"fEM_R0UN80RDU\0"}, 
{879,"iEM_A2UV01IDU\0"}, 
{880,"iEM_A2UV02IDU\0"}, 
{881,"iEM_A1UV01IDU\0"}, 
{882,"iEM_A1UV02IDU\0"}, 
{883,"iEM_A1UV03IDU\0"}, 
{884,"iEM_A3UV01IDU\0"}, 
{885,"iEM_A3UV02IDU\0"}, 
{886,"lEM_R0MD01LC1\0"}, 
{887,"fEM_A3UC09RDU\0"}, 
{888,"fEM_A2UC02RDU\0"}, 
{889,"fEM_A1UC02RDU\0"}, 
{890,"fEM_A3UC02RDU\0"}, 
{891,"fEM_R0UL21RDU\0"}, 
{892,"fEM_R0UN09RDU\0"}, 
{893,"fEM_R0UN11RDU\0"}, 
{894,"fEM_R0UN12RDU\0"}, 
{895,"fEM_R0UN13RDU\0"}, 
{896,"fEM_R0UN14RDU\0"}, 
{897,"fEM_R0UN16RDU\0"}, 
{898,"fEM_R0UN17RDU\0"}, 
{899,"fEM_R0UN18RDU\0"}, 
{900,"fEM_R0UN19RDU\0"}, 
{901,"fEM_R0UN70LDU\0"}, 
{902,"fEM_R0UN71LDU\0"}, 
{903,"fEM_R0UN72LDU\0"}, 
{904,"fEM_R0UN73LDU\0"}, 
{905,"fEM_R0UN74LDU\0"}, 
{906,"fEM_R0UN75LDU\0"}, 
{907,"fEM_R0UN80LDU\0"}, 
{908,"fEM_R0UN81LDU\0"}, 
{909,"fEM_R0UN82LDU\0"}, 
{910,"fEM_R0UN83LDU\0"}, 
{911,"fEM_R0UN84LDU\0"}, 
{912,"fEM_R0UN85LDU\0"}, 
{913,"fEM_R0UT20RDU\0"}, 
{914,"fEM_R0UN25RDU\0"}, 
{915,"fEM_R0UN15RDU\0"}, 
{916,"fEM_R0UN26RDU\0"}, 
{917,"fEM_R0UN27RDU\0"}, 
{918,"fEM_R0UN24RDU\0"}, 
{919,"fEM_R0UL25RDU\0"}, 
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
	{&R0AD14LZ1,1,38},
	{&B2IS11LDU,1,20},
	{&A3VZ13LZ1,1,34},
	{&A3VZ15LZ1,1,36},
	{&B2IS33LDU,1,4},
	{&B3IS31LDU,1,8},
	{&B3IS33LDU,1,2},
	{&B3IS35LDU,1,0},
	{&B4IS10LDU,1,6},
	{&B7AS31LDU,1,10},
	{&R0VZ71LZ1,1,42},
	{&A9IS21LDU,1,46},
	{&R0DE02LDU,3,64},
	{&A9IS11LDU,1,44},
	{&B9IS21LDU,1,50},
	{&B9IS11LDU,1,48},
	{&B1IS11LDU,1,14},
	{&B4IS21LDU,1,62},
	{&R2IS11LDU,1,56},
	{&R2IS21LDU,1,58},
	{&B3IS21LDU,1,24},
	{&B2IS21LDU,1,22},
	{&B1IS21LDU,1,16},
	{&R1IS21LDU,1,54},
	{&R1IS11LDU,1,52},
	{&B4IS11LDU,1,60},
	{&A1VN71LZ1,1,40},
	{&B1IS12LDU,1,12},
	{&R8IS11LDU,1,26},
	{&B2IS12LDU,1,18},
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
	{&A2IS11LDU,1,20},
	{&A1IS12LDU,1,12},
	{&A2IS12LDU,1,18},
	{&A3VZ15LZ2,1,36},
	{&A2IS33LDU,1,4},
	{&A3VZ13LZ2,1,34},
	{&A4IS21LDU,1,28},
	{&A3IS33LDU,1,2},
	{&A3IS35LDU,1,0},
	{&A4IS10LDU,1,6},
	{&A3IS31LDU,1,8},
	{&A3IS21LDU,1,24},
	{&A2IS21LDU,1,22},
	{&A1IS21LDU,1,16},
	{&A1VN71LZ2,1,40},
	{&R0IS01LDU,1,56},
	{&R0IS02LDU,1,58},
	{&R0DE03LDU,3,64},
	{&R0AD14LZ2,1,38},
	{&R0VZ71LZ2,1,42},
	{&A7AS31LDU,1,10},
	{&A4IS11LDU,1,26},
	{&A1IS11LDU,1,14},
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
	{&A5IS11LDU,1,20},
	{&R3IS21LDU,1,34},
	{&R3IS11LDU,1,32},
	{&R5IS21LDU,1,50},
	{&B8IS21LDU,1,38},
	{&B8IS12LDU,1,40},
	{&R4IS12LDU,1,10},
	{&A5IS21LDU,1,22},
	{&R0DE04LDU,3,64},
	{&R4IS22LDU,1,14},
	{&R4IS21LDU,1,12},
	{&B5IS11LDU,1,28},
	{&B5IS21LDU,1,30},
	{&R5IS11LDU,1,48},
	{&B3IS11LDU,1,4},
	{&A3IS11LDU,1,0},
	{&R6IS21LDU,1,56},
	{&A8IS22LDU,1,60},
	{&A8IS12LDU,1,58},
	{&B8IS22LDU,1,42},
	{&A3IS22LDU,1,2},
	{&B3IS22LDU,1,6},
	{&A6IS11LDU,1,16},
	{&A6IS21LDU,1,18},
	{&B6IS11LDU,1,24},
	{&B6IS21LDU,1,26},
	{&B8IS11LDU,1,36},
	{&R4IS11LDU,1,8},
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
	{&A2IE02LDU,1,8},
	{&B2IE04LDU,1,38},
	{&B2IE03LDU,1,36},
	{&B1IE04LDU,1,30},
	{&B1IE03LDU,1,28},
	{&A3IE04LDU,1,22},
	{&A3IE03LDU,1,20},
	{&A2IE04LDU,1,14},
	{&A2IE03LDU,1,12},
	{&A1IE04LDU,1,6},
	{&A1IE03LDU,1,4},
	{&A3IE02LDU,1,16},
	{&A1IE02LDU,1,0},
	{&A2IE01LDU,1,10},
	{&B3IE03LDU,1,44},
	{&B3IE04LDU,1,46},
	{&A3IE01LDU,1,18},
	{&A1IE01LDU,1,2},
	{&R0DE05LDU,3,64},
	{&R6IS52LDU,1,58},
	{&R6IS41LDU,1,52},
	{&R6IS42LDU,1,54},
	{&R6IS32LDU,1,50},
	{&R6IS51LDU,1,56},
	{&R6IS31LDU,1,48},
	{&B2IE02LDU,1,32},
	{&B3IE02LDU,1,40},
	{&B1IE02LDU,1,24},
	{&B3IE01LDU,1,42},
	{&B2IE01LDU,1,34},
	{&B1IE01LDU,1,26},
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
	{&A2AD02LDU,1,6},
	{&A2AD03LDU,1,8},
	{&A2AD04LDU,1,10},
	{&B2AD03LDU,1,22},
	{&A2AD05LDU,1,12},
	{&B2AD02LDU,1,20},
	{&B2AD21LDU,1,16},
	{&B2AD11LDU,1,14},
	{&A2AD21LDU,1,2},
	{&A2AD11LDU,1,0},
	{&B2AD04LDU,1,24},
	{&B2AD05LDU,1,26},
	{&B2AD01LDU,1,18},
	{&A2AD01LDU,1,4},
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
	{&A1AD02LDU,1,6},
	{&A1AD03LDU,1,8},
	{&A1AD04LDU,1,10},
	{&A1AD05LDU,1,12},
	{&A1AD01LDU,1,4},
	{&R0DE08LDU,3,38},
	{&B1AD01LDU,1,18},
	{&B1AD05LDU,1,26},
	{&A1AD11LDU,1,0},
	{&B1AD04LDU,1,24},
	{&B1AD03LDU,1,22},
	{&B1AD02LDU,1,20},
	{&B1AD21LDU,1,16},
	{&B1AD11LDU,1,14},
	{&A1AD21LDU,1,2},
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
	{&B4AD10LDU,1,6},
	{&A8AD20LDU,1,14},
	{&R0DE09LDU,3,38},
	{&A8AD10LDU,1,12},
	{&B8AD10LDU,1,28},
	{&B8AD20LDU,1,30},
	{&A6AD10LDU,1,16},
	{&A6AD20LDU,1,18},
	{&B6AD10LDU,1,20},
	{&B6AD20LDU,1,22},
	{&R4AD10LDU,1,24},
	{&B7AP31LDU,1,10},
	{&B3AD31LDU,1,8},
	{&B3AD33LDU,1,2},
	{&B2AD33LDU,1,4},
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
	{&A7AP31LDU,1,10},
	{&R1AD10LDU,1,12},
	{&A2AD33LDU,1,4},
	{&R1AD20LDU,1,14},
	{&A3AD33LDU,1,2},
	{&A3AD34LDU,1,0},
	{&A3AD31LDU,1,8},
	{&R0DE0ALDU,3,38},
	{&A4AD10LDU,1,6},
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
	{&B3AD11LDU,1,14},
	{&B3AD21LDU,1,16},
	{&B3AD02LDU,1,20},
	{&B3AD03LDU,1,22},
	{&B3AD04LDU,1,24},
	{&A3AD11LDU,1,0},
	{&A3AD21LDU,1,2},
	{&A3AD02LDU,1,6},
	{&A3AD03LDU,1,8},
	{&A3AD04LDU,1,10},
	{&A3AD05LDU,1,12},
	{&A3AD01LDU,1,4},
	{&B3AD05LDU,1,26},
	{&B3AD01LDU,1,18},
	{&R0DE0BLDU,3,38},
	{&B9AD10LDU,1,30},
	{&A9AD10LDU,1,28},
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
	{&R1VS12LDU,1,8},
	{&A5IE02LDU,1,24},
	{&B5IE01LDU,1,30},
	{&A6VS22LDU,1,34},
	{&A6VS12LDU,1,32},
	{&B6VS22LDU,1,40},
	{&B6VS12LDU,1,38},
	{&R0IE02LDU,1,44},
	{&A8IE01LDU,1,6},
	{&R0IE01LDU,1,46},
	{&B6IE01LDU,1,42},
	{&A6IE01LDU,1,36},
	{&R6IS61LDU,1,0},
	{&R2IE01LDU,1,18},
	{&R4VS22LDU,1,4},
	{&R4VS12LDU,1,2},
	{&R1VS22LDU,1,10},
	{&R2VS22LDU,1,16},
	{&R2VS12LDU,1,14},
	{&R0DE0DLDU,3,64},
	{&B5VS12LDU,1,26},
	{&B5VS22LDU,1,28},
	{&R1IE01LDU,1,12},
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
	{&R8AD21LDU,1,22},
	{&A2AD31LDU,1,6},
	{&B2AD31LDU,1,14},
	{&A1AD31LDU,1,2},
	{&B1AD32LDU,1,8},
	{&A1AD32LDU,1,0},
	{&B1AD31LDU,1,10},
	{&A2AD32LDU,1,4},
	{&B2AD32LDU,1,12},
	{&R0AD16LDU,1,24},
	{&R0AD03LZ1,1,16},
	{&R0AD03LZ2,1,26},
	{&R0AD04LZ1,1,18},
	{&R0AD04LZ2,1,28},
	{&R0AD05LZ1,1,20},
	{&R0AD05LZ2,1,30},
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
	{&R0DE31LDU,1,0},
	{&R0DEB4LDU,1,24},
	{&R0DEB1LDU,1,18},
	{&R0DEB2LDU,1,20},
	{&R0DEB3LDU,1,22},
	{&R0DE39LDU,1,16},
	{&R0DE38LDU,1,14},
	{&R0DE37LDU,1,12},
	{&R0DE36LDU,1,10},
	{&R0DE35LDU,1,8},
	{&R0DE34LDU,1,6},
	{&R0DE33LDU,1,4},
	{&R0DE32LDU,1,2},
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
	setAsFloat(758,0.0000976563);
	setAsInt(759,1024200);
	setAsInt(760,-200);
	setAsInt(761,-200);
	setAsInt(762,1024200);
	setAsFloat(763,0.0000976563);
	setAsInt(764,-200);
	setAsInt(765,1689599);
	setAsFloat(766,0.00009765625);
	setAsInt(767,-200);
	setAsFloat(768,0.0009765625);
	setAsInt(769,1536200);
	setAsFloat(770,100);
	setAsFloat(771,200);
	setAsFloat(772,300);
	setAsFloat(773,400);
	setAsFloat(774,600);
	setAsFloat(775,500);
	setAsFloat(776,750);
	setAsFloat(777,2.5);
	setAsFloat(778,0);
	setAsFloat(779,0.46);
	setAsFloat(780,0.49);
	setAsFloat(781,0.52);
	setAsFloat(782,0.53);
	setAsFloat(783,0.67);
	setAsFloat(784,0.56);
	setAsFloat(785,4);
	setAsFloat(786,4);
	setAsFloat(787,10.91);
	setAsFloat(788,3);
	setAsShort(789,4);
	setAsFloat(790,0.15);
	setAsFloat(791,0.15);
	setAsFloat(792,0.4);
	setAsFloat(793,0.4);
	setAsFloat(794,0.03);
	setAsFloat(795,0.04);
	setAsFloat(796,3);
	setAsFloat(797,0.3);
	setAsFloat(798,0.3);
	setAsFloat(799,0.07);
	setAsFloat(800,0.04);
	setAsFloat(801,3);
	setAsFloat(802,0.55);
	setAsFloat(803,0.64);
	setAsFloat(804,0.180);
	setAsFloat(805,0.025);
	setAsFloat(806,0.1);
	setAsFloat(807,2);
	setAsFloat(808,0.3);
	setAsFloat(809,3);
	setAsFloat(810,1.50);
	setAsFloat(811,0.04);
	setAsFloat(812,0.05);
	setAsFloat(813,3);
	setAsFloat(814,1.50);
	setAsFloat(815,3);
	setAsFloat(816,1.50);
	setAsFloat(817,2);
	setAsFloat(818,0.004);
	setAsFloat(819,0.006);
	setAsFloat(820,0.006);
	setAsFloat(821,1.0);
	setAsFloat(822,0.01);
	setAsFloat(823,1);
	setAsFloat(824,0.008);
	setAsFloat(825,0.01);
	setAsFloat(826,1);
	setAsFloat(827,0.4);
	setAsFloat(828,120);
	setAsFloat(829,0.6);
	setAsFloat(830,1);
	setAsFloat(831,2);
	setAsFloat(832,1.50);
	setAsFloat(833,2.0);
	setAsFloat(834,1);
	setAsFloat(835,15);
	setAsFloat(836,0.50);
	setAsFloat(837,360);
	setAsFloat(838,1);
	setAsFloat(839,2);
	setAsFloat(840,1.0);
	setAsFloat(841,6.0);
	setAsFloat(842,0.50);
	setAsFloat(843,1.0);
	setAsFloat(844,16.0);
	setAsFloat(845,3.0);
	setAsFloat(846,1.0);
	setAsFloat(847,60.0);
	setAsFloat(848,0.50);
	setAsFloat(849,1.0);
	setAsFloat(850,20.0);
	setAsFloat(851,0.50);
	setAsFloat(852,2.0);
	setAsFloat(853,2.0);
	setAsFloat(854,1.5);
	setAsFloat(855,0.06);
	setAsFloat(856,0.01);
	setAsFloat(857,0.045);
	setAsFloat(858,0.040);
	setAsFloat(859,0.007);
	setAsFloat(860,0.014);
	setAsFloat(861,2000.0);
	setAsFloat(862,1500.0);
	setAsFloat(863,1000.0);
	setAsFloat(864,800.0);
	setAsFloat(865,500.0);
	setAsFloat(866,200.0);
	setAsFloat(867,100.0);
	setAsFloat(868,0.001);
	setAsFloat(869,100);
	setAsFloat(870,100);
	setAsFloat(871,110.0);
	setAsFloat(872,20);
	setAsFloat(873,30.0);
	setAsFloat(874,100.0);
	setAsFloat(875,1.50);
	setAsFloat(876,170);
	setAsFloat(877,170);
	setAsFloat(878,10);
	setAsShort(879,1);
	setAsShort(880,4);
	setAsShort(881,1);
	setAsShort(882,4);
	setAsShort(883,4);
	setAsShort(884,4);
	setAsShort(885,4);
	setAsBool(886,0);
	setAsFloat(887,159.99);
	setAsFloat(888,0.002375);
	setAsFloat(889,0.000877);
	setAsFloat(890,0.001675);
	setAsFloat(891,2.5);
	setAsFloat(892,30);
	setAsFloat(893,30);
	setAsFloat(894,0.05);
	setAsFloat(895,0.05);
	setAsFloat(896,160.0);
	setAsFloat(897,-170.11);
	setAsFloat(898,76.25088);
	setAsFloat(899,0.271145);
	setAsFloat(900,24.93556615);
	setAsFloat(901,0.1268);
	setAsFloat(902,0.1567);
	setAsFloat(903,0.1858);
	setAsFloat(904,0.2066);
	setAsFloat(905,0.2646);
	setAsFloat(906,0.2995);
	setAsFloat(907,0.721275);
	setAsFloat(908,0.700575);
	setAsFloat(909,0.6681);
	setAsFloat(910,0.61515);
	setAsFloat(911,0.3885);
	setAsFloat(912,0.23325);
	setAsFloat(913,3600.0);
	setAsFloat(914,0.935);
	setAsFloat(915,0.1);
	setAsFloat(916,0.006792308);
	setAsFloat(917,0.000418877);
	setAsFloat(918,0.0015);
	setAsFloat(919,0.30);
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
ssbool var7;
ssbool var8;
ssint var9;
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
ssint var137;
ssbool var138;
ssbool var139;
ssint var140;
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
ssfloat var185;
ssbool var186;
ssbool var187;
ssbool var188;
ssbool var189;
ssbool var190;
ssbool var191;
ssbool var192;
ssbool var193;
ssbool var194;
ssfloat var195;
ssfloat var196;
ssbool var197;
ssbool var198;
ssbool var199;
ssfloat var200;
ssfloat var201;
ssbool var202;
ssbool var203;
ssfloat var204;
ssbool var205;
ssbool var206;
ssbool var207;
ssbool var208;
ssbool var209;
ssbool var210;
ssbool var211;
ssbool var212;
ssfloat var213;
ssfloat var214;
ssfloat var215;
ssfloat var216;
ssbool var217;
ssfloat var218;
ssfloat var219;
ssint var220;
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
ssfloat var311;
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
ssfloat var424;
ssfloat var425;
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
ssbool var436;
ssfloat var437;
ssfloat var438;
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
ssbool var566;
ssbool var567;
sslong var568;
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
ssbool var977;
ssbool var978;
ssfloat var979;
ssbool var980;
ssfloat var981;
ssbool var982;
ssfloat var983;
ssbool var984;
ssbool var985;
ssbool var986;
ssbool var987;
ssfloat var988;
ssfloat var989;
ssfloat var990;
ssfloat var991;
ssfloat var992;
ssfloat var993;
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
ssint var1049;
ssint var1050;
ssbool var1051;
ssbool var1052;
ssbool var1053;
ssbool var1054;
ssbool var1055;
ssbool var1056;
sslong var1057;
ssbool var1058;
ssbool var1059;
ssbool var1060;
ssint var1061;
ssbool var1062;
ssbool var1063;
ssbool var1064;
ssbool var1065;
ssbool var1066;
ssbool var1067;
ssbool var1068;
ssbool var1069;
ssbool var1070;
ssint var1071;
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
sslong var1112;
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
ssfloat var1131;
ssbool var1132;
ssbool var1133;
ssbool var1134;
ssbool var1135;
ssbool var1136;
ssfloat var1137;
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
ssint var1151;
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
ssfloat var1176;
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
ssbool var1270;
ssbool var1271;
sslong var1272;
ssbool var1273;
ssint var1274;
ssint var1275;
ssbool var1276;
ssfloat var1277;
ssfloat var1278;
ssfloat var1279;
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
ssint var1328;
ssbool var1329;
sschar var1330;
ssint var1331;
ssbool var1332;
ssfloat var1333;
ssbool var1334;
ssbool var1335;
ssbool var1336;
ssbool var1337;
ssbool var1338;
ssbool var1339;
ssbool var1340;
ssfloat var1341;
sschar var1342;
ssbool var1343;
ssbool var1344;
ssbool var1345;
ssbool var1346;
ssfloat var1347;
ssbool var1348;
ssbool var1349;
ssbool var1350;
ssbool var1351;
ssbool var1352;
ssbool var1353;
ssbool var1354;
ssbool var1355;
ssbool var1356;
ssint var1357;
ssbool var1358;
sschar var1359;
ssint var1360;
ssbool var1361;
ssfloat var1362;
ssbool var1363;
ssbool var1364;
ssbool var1365;
ssbool var1366;
ssbool var1367;
ssbool var1368;
ssbool var1369;
ssfloat var1370;
sschar var1371;
ssbool var1372;
ssbool var1373;
ssbool var1374;
ssbool var1375;
ssfloat var1376;
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
ssbool var1388;
ssbool var1389;
ssint var1390;
ssbool var1391;
sschar var1392;
ssint var1393;
ssbool var1394;
ssfloat var1395;
ssbool var1396;
ssbool var1397;
ssbool var1398;
ssbool var1399;
ssbool var1400;
ssbool var1401;
ssbool var1402;
ssfloat var1403;
sschar var1404;
ssbool var1405;
ssbool var1406;
ssfloat var1407;
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
ssint var1420;
ssbool var1421;
ssbool var1422;
ssbool var1423;
ssbool var1424;
ssbool var1425;
ssbool var1426;
ssbool var1427;
ssbool var1428;
ssint var1429;
ssbool var1430;
ssbool var1431;
ssbool var1432;
ssbool var1433;
ssbool var1434;
ssbool var1435;
ssbool var1436;
ssint var1437;
ssbool var1438;
sschar var1439;
ssint var1440;
ssbool var1441;
ssfloat var1442;
ssbool var1443;
ssbool var1444;
ssbool var1445;
ssbool var1446;
ssbool var1447;
ssbool var1448;
ssbool var1449;
ssfloat var1450;
sschar var1451;
ssbool var1452;
ssbool var1453;
ssfloat var1454;
ssbool var1455;
ssbool var1456;
ssbool var1457;
ssbool var1458;
ssbool var1459;
ssbool var1460;
ssbool var1461;
ssbool var1462;
sschar var1463;
ssbool var1464;
ssbool var1465;
ssbool var1466;
ssbool var1467;
ssbool var1468;
ssbool var1469;
ssbool var1470;
ssbool var1471;
ssbool var1472;
sschar var1473;
ssbool var1474;
ssbool var1475;
ssint var1476;
ssbool var1477;
sschar var1478;
ssbool var1479;
ssint var1480;
ssbool var1481;
ssbool var1482;
ssfloat var1483;
ssbool var1484;
ssbool var1485;
ssbool var1486;
ssbool var1487;
ssbool var1488;
ssbool var1489;
ssbool var1490;
ssfloat var1491;
sschar var1492;
ssbool var1493;
ssbool var1494;
ssbool var1495;
ssbool var1496;
ssfloat var1497;
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
ssbool var1508;
ssbool var1509;
ssfloat var1510;
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
ssbool var1525;
ssbool var1526;
ssfloat var1527;
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
ssbool var1563;
ssbool var1564;
ssint var1565;
ssbool var1566;
ssbool var1567;
ssbool var1568;
ssbool var1569;
ssbool var1570;
ssbool var1571;
ssbool var1572;
ssbool var1573;
ssint var1574;
ssbool var1575;
ssbool var1576;
ssbool var1577;
ssbool var1578;
ssbool var1579;
ssbool var1580;
ssbool var1581;
ssbool var1582;
ssint var1583;
ssbool var1584;
ssbool var1585;
ssbool var1586;
ssbool var1587;
ssbool var1588;
ssbool var1589;
ssbool var1590;
ssbool var1591;
ssint var1592;
ssbool var1593;
ssbool var1594;
ssbool var1595;
ssbool var1596;
ssbool var1597;
ssbool var1598;
ssbool var1599;
ssbool var1600;
ssint var1601;
ssbool var1602;
ssbool var1603;
ssbool var1604;
ssbool var1605;
ssbool var1606;
ssbool var1607;
ssbool var1608;
ssbool var1609;
ssint var1610;
ssbool var1611;
ssbool var1612;
ssbool var1613;
ssbool var1614;
ssbool var1615;
ssbool var1616;
ssbool var1617;
ssbool var1618;
ssint var1619;
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
ssbool var1654;
ssbool var1655;
ssfloat var1656;
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
ssbool var1689;
ssbool var1690;
ssfloat var1691;
ssfloat var1692;
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
ssbool var1717;
ssbool var1718;
ssfloat var1719;
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
ssbool var1740;
ssfloat var1741;
ssbool var1742;
ssbool var1743;
ssbool var1744;
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
psbool  array_m243_x_2[6] = {&var1703,&var1695,&var1709,&B0VT71LZ1,&B0VT71LZ2,&var1654};
psbool  array_m232_x_2[6] = {&var1704,&var1697,&var1710,&A0VT71LZ1,&A0VT71LZ2,&var1654};
psbool  array_m255_x_2[6] = {&var1688,&B0VP71LZ1,&B0VP71LZ2,&var1659,&var1658,&var1657};
psbool  array_m234_x_2[6] = {&var1689,&A0VP71LZ1,&A0VP71LZ2,&var1662,&var1661,&var1660};
psbool  array_m124_x_2[8] = {&var1721,&var1743,&var1739,&var1736,&var1733,&var1730,&var1724,&var1727};
psbool  array_m2317_x_1[6] = {&var6,&var5,&R0DE36LDU,&R0DE37LDU,&R0DE38LDU,&R0DE39LDU};
psint  array_m2301_x_1[12] = {&R0DE0DLDU,&R0DE0FLDU,&R0DE02LDU,&R0DE03LDU,&R0DE04LDU,&R0DE05LDU,&R0DE07LDU,&R0DE08LDU,&R0DE09LDU,&R0DE0ALDU,&R0DE0BLDU,&R0DE0CLDU};
psbool  array_m802_x_1[6] = {&var599,&var1235,&var1211,&var1200,&var1004,&var87};
psbool  array_m1202_x_1[6] = {&var598,&var1215,&var12,&var1237,&var1004,&var107};
psbool  array_m593_x_1[6] = {&var794,&var1103,&var1522,&var1064,&var1481,&var1097};
psbool  array_m592_x_1[6] = {&var794,&var1104,&var1522,&var1064,&var1481,&var1096};
psfloat  array_m2210_a_1[6] = {&fEM_R0UN70LDU,&fEM_R0UN71LDU,&fEM_R0UN72LDU,&fEM_R0UN73LDU,&fEM_R0UN74LDU,&fEM_R0UN75LDU};
psfloat  array_m2210_b_1[6] = {&fEM_R0UN80LDU,&fEM_R0UN81LDU,&fEM_R0UN82LDU,&fEM_R0UN83LDU,&fEM_R0UN84LDU,&fEM_R0UN85LDU};
psfloat  array_m2222_x_1[4] = {&B0CT01IZ1,&A0CT01IZ1,&B0CT01IZ2,&A0CT01IZ2};
psfloat  array_m2243_x_1[2] = {&R0VN09RZ1,&R0VN09RZ2};
psbool  array_m2212_x_1[14] = {&var199,&var172,&var828,&var233,&var235,&var170,&var1644,&var1224,&var1222,&var1655,&var198,&var187,&var183,&var207};
psbool  array_m1_x_1[47] = {&var1187,&lRM_0_,&var332,&var62,&var482,&var1391,&var717,&R0MD34LP1,&var631,&R0MD34LP1,&var690,&R0MD34LP1,&var924,&R0MD34LP1,&var744,&R0MD34LP1,&var922,&var1418,&A2IS12LDU,&var389,&var1218,&var1111,&var1109,&var1022,&var837,&R0MD34LP1,&var419,&var460,&var1262,&var1572,&R0MD34LP1,&var575,&var566,&var521,&B3IS35LDU,&B3IS35LDU,&var254,&var60,&var493,&var301,&var1623,&var1581,&var1608,&var943,&var1595,&R2IS21LDU,&var173};
psfloat  array_m1468_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psbool  array_m1422_x_1[5] = {&var575,&var574,&var573,&var572,&var571};
psbool  array_m551_x_1[14] = {&var742,&var748,&var749,&var740,&var741,&var926,&var927,&var907,&var906,&var738,&var736,&var744,&var737,&var227};
psfloat  array_m88_x_1[2] = {&R0VN11RZ2,&R0VN11RZ1};
psfloat  array_m90_x_1[8] = {&fEM_R0UN01RDU,&fEM_R0UN02RDU,&fEM_R0UN03RDU,&fEM_R0UN04RDU,&fEM_R0UN05RDU,&fEM_R0UN06RDU,&fEM_R0UN07RDU,&fEM_R0UN08RDU};
psfloat  array_m1061_x_1[2] = {&R0VN11RZ2,&R0VN11RZ1};
psfloat  array_m1212_x_1[8] = {&var1483,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m810_x_1[8] = {&var1442,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m892_x_1[8] = {&var1333,&var196,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m1309_x_1[8] = {&var1301,&var195,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m493_x_1[8] = {&var1362,&var323,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m170_x_1[8] = {&var1395,&var327,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m331_Tpr_1[10] = {&fRM_6_0,&fRM_126_0,&fRM_246_0,&fRM_366_0,&fRM_486_0,&fRM_606_0,&fRM_726_0,&fRM_846_0,&fRM_966_0,&fRM_1200_0};
pschar  array_m331_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m331_rz_1[10];
psbool  array_m335_x_1[5] = {&var1052,&var1053,&var1054,&var1055,&var1056};
psbool  array_m270_x_1[7] = {&var828,&var229,&var1031,&var1028,&var235,&var233,&var231};
psfloat  array_m274_Tpr_1[10] = {&fRM_10_0,&fRM_30_0,&fRM_50_0,&fRM_70_0,&fRM_90_0,&fRM_110_0,&fRM_130_0,&fRM_150_0,&fRM_170_0,&fRM_200_0};
pschar  array_m274_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m274_rz_1[10];
psfloat  array_m1411_Tpr_1[6] = {&fRM_0_5,&fRM_3_5,&fRM_6_5,&fRM_9_5,&fRM_12_5,&fRM_15_5};
pschar  array_m1411_type_1[6] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_6_};
pschar  array_m1411_rz_1[6];
psbool  array_m290_x_1[5] = {&var1074,&var1075,&var1076,&var1077,&var1078};
psbool  array_m1187_x_1[5] = {&var1199,&var811,&var1554,&var1204,&var245};
psbool  array_m1174_x_1[4] = {&var1108,&var1150,&var1024,&var1202};
psfloat  array_m1452_x_1[16] = {&var424,&var433,&fRM_0_,&var430,&fRM_0_,&fRM_0_,&fRM_0_,&var427,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&var437};
psbool  array_m1772_x_1[17] = {&var504,&var505,&var511,&var506,&var502,&var503,&var961,&var507,&var508,&var1251,&var509,&var510,&var1243,&var1244,&var1253,&var239,&var240};
psbool  array_m1414_x_1[5] = {&var416,&var539,&var556,&var557,&var446};
psint  array_m309_x_1[3] = {&var1050,&iRM_0_,&var1072};
psint  array_m300_x_1[3] = {&var1049,&iRM_0_,&var1071};
psbool  array_m595_x_1[5] = {&var777,&var1521,&var1288,&var1005,&var205};
psbool  array_m1373_x_1[8] = {&var661,&var662,&var663,&var658,&var657,&var656,&var922,&var654};
psbool  array_m1308_x_1[3] = {&var89,&lRM_0_,&var88};
psfloat  array_m1310_Lt_fw_1[1] = {&fEM_A3UC81RDU};
psint  array_m1310_Vr_fw_1[1] = {&iEM_A3UV01IDU};
psfloat  array_m1310_Lt_bw_1[1] = {&fEM_A3UC82RDU};
psint  array_m1310_Vr_bw_1[1] = {&iEM_A3UV02IDU};
psfloat  array_m1338_x0_1[60];
psfloat  array_m1338_tim0_1[60];
psbool  array_m961_x_1[8] = {&var676,&var678,&var679,&var671,&var677,&var673,&var924,&var405};
psbool  array_m891_x_1[3] = {&var115,&lRM_0_,&var110};
psfloat  array_m893_Lt_fw_1[1] = {&fEM_A3UC81RDU};
psint  array_m893_Vr_fw_1[1] = {&iEM_A3UV01IDU};
psfloat  array_m893_Lt_bw_1[1] = {&fEM_A3UC82RDU};
psint  array_m893_Vr_bw_1[1] = {&iEM_A3UV02IDU};
psfloat  array_m926_x0_1[60];
psfloat  array_m926_tim0_1[60];
psbool  array_m492_x_1[3] = {&var753,&lRM_0_,&var754};
psfloat  array_m495_Lt_fw_1[2] = {&fEM_A1UC81RDU,&fEM_A1UC82RDU};
psint  array_m495_Vr_fw_1[2] = {&iEM_A1UV01IDU,&iEM_A1UV02IDU};
psfloat  array_m495_Lt_bw_1[1] = {&fEM_A1UC83RDU};
psint  array_m495_Vr_bw_1[1] = {&iEM_A1UV03IDU};
psfloat  array_m522_x0_1[150];
psfloat  array_m522_tim0_1[150];
psbool  array_m234_x_1[12] = {&var722,&var724,&var723,&var720,&var718,&var717,&var716,&var930,&var929,&var711,&var714,&var228};
psbool  array_m169_x_1[3] = {&var900,&lRM_0_,&var901};
psfloat  array_m174_Lt_fw_1[2] = {&fEM_A1UC81RDU,&fEM_A1UC82RDU};
psint  array_m174_Vr_fw_1[2] = {&iEM_A1UV01IDU,&iEM_A1UV02IDU};
psfloat  array_m174_Lt_bw_1[1] = {&fEM_A1UC83RDU};
psint  array_m174_Vr_bw_1[1] = {&iEM_A1UV03IDU};
psfloat  array_m203_x0_1[150];
psfloat  array_m203_tim0_1[150];
psbool  array_m866_x_1[10] = {&var688,&var689,&var695,&var696,&var694,&var692,&var691,&var932,&var931,&var690};
psbool  array_m809_x_1[3] = {&var91,&var706,&var90};
psfloat  array_m813_Lt_fw_1[2] = {&fEM_A2UC81RDU,&fEM_A2UC82RDU};
psint  array_m813_Vr_fw_1[2] = {&iEM_A2UV01IDU,&iEM_A2UV02IDU};
psfloat  array_m813_Lt_bw_1[1] = {&fEM_A2UC83RDU};
psint  array_m813_Vr_bw_1[1] = {&iEM_A2UV03CDU};
psfloat  array_m833_x0_1[80];
psfloat  array_m833_tim0_1[80];
psfloat  array_m1592_Lt_fw_1[1] = {&fRM_1000_};
psint  array_m1592_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1592_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1592_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1283_x_1[10] = {&var627,&var628,&var630,&var629,&var631,&var633,&var635,&var632,&var634,&var636};
psbool  array_m152_x_1[5] = {&A1IS21LDU,&A3IS21LDU,&A2IS21LDU,&var947,&var946};
psfloat  array_m1116_Lt_fw_1[1] = {&fRM_2000_};
psint  array_m1116_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1116_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1116_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1211_x_1[3] = {&var119,&var621,&var106};
psfloat  array_m1213_Lt_fw_1[2] = {&fEM_A2UC81RDU,&fEM_A2UC82RDU};
psint  array_m1213_Vr_fw_1[2] = {&iEM_A2UV01IDU,&iEM_A2UV02IDU};
psfloat  array_m1213_Lt_bw_1[1] = {&fEM_A2UC83RDU};
psint  array_m1213_Vr_bw_1[1] = {&iEM_A2UV03CDU};
psfloat  array_m1248_x0_1[80];
psfloat  array_m1248_tim0_1[80];
psfloat  array_m1612_x0_1[20];
psfloat  array_m1612_tim0_1[20];
psbool  array_m1084_x_1[8] = {&var838,&var835,&var836,&var837,&var834,&var833,&var832,&var831};
psbool  array_m596_x_1[18] = {&R0MD31LP1,&var529,&var852,&var531,&var850,&var622,&var757,&var705,&var732,&var752,&var681,&var646,&var908,&var344,&var343,&var612,&var261,&var197};
psfloat  array_m1137_x0_1[20];
psfloat  array_m1137_tim0_1[20];
psbool  array_m436_x_1[7] = {&var953,&var952,&var951,&var950,&var1625,&var942,&var373};
psbool  array_m418_x_1[7] = {&var955,&var1625,&var943,&var956,&var954,&var941,&var143};
psbool  array_m766_x_1[17] = {&var853,&var898,&var897,&var894,&var893,&var890,&var855,&var892,&var860,&var889,&var885,&var887,&var886,&var857,&var851,&var940,&var708};
psbool  array_m138_x_1[21] = {&var731,&var751,&var996,&var704,&var995,&var994,&var1559,&var1568,&var1586,&var1577,&var1613,&var1604,&var482,&var374,&var986,&var987,&var1265,&var1259,&var1423,&var1414,&var1595};

/* Объявление структур */
_S_and4  S_and4_106_2 = {&var1740,&var1675,&B8IS11LDU,&B8IS12LDU,&var1645};
_S_lkb  S_lkb_111_2 = {&lRM_1_,&var1673,&var1646};
_S_lkb  S_lkb_107_2 = {&lRM_1_,&var1645,&var1647};
_S_lkb  S_lkb_80_2 = {&lRM_1_,&var1676,&var1648};
_S_lkb  S_lkb_50_2 = {&lRM_1_,&var1681,&var1649};
_S_lkb  S_lkb_83_2 = {&lRM_1_,&var1679,&var1650};
_S_lkb  S_lkb_46_2 = {&lRM_1_,&var1685,&var1651};
_S_lkb  S_lkb_24_2 = {&lRM_1_,&var1683,&var1652};
_S_lkb  S_lkb_20_2 = {&lRM_1_,&var1687,&var1653};
_S_or2  S_or2_258_2 = {&var1744,&var1693,&var1654};
_S_bol  S_bol_223_2 = {&fRM_0_5,&var1656,&var1655};
_S_fsumo  S_fsumo_222_2 = {&var1692,&var1691,&var1656};
_S_noto  S_noto_251_2 = {&B3VP81LDU,&var1657};
_S_noto  S_noto_250_2 = {&B2VP82LDU,&var1658};
_S_noto  S_noto_249_2 = {&B4VP82LDU,&var1659};
_S_noto  S_noto_231_2 = {&A3VP81LDU,&var1660};
_S_noto  S_noto_230_2 = {&A2VP82LDU,&var1661};
_S_noto  S_noto_229_2 = {&A4VP82LDU,&var1662};
_S_schl24  S_schl24_149_2 = {&A0EE02LZ1,&A0EE03LZ1,&A0EE01LZ1,&A0EE04LZ1,&var1663};
_S_schl24  S_schl24_143_2 = {&A0EE03LZ2,&A0EE01LZ2,&A0EE02LZ2,&A0EE04LZ2,&var1664};
_S_or2  S_or2_198_2 = {&var1713,&var1714,&var1665};
_S_or2  S_or2_195_2 = {&var1716,&var1717,&var1666};
_S_and2  S_and2_213_2 = {&var1701,&var1712,&var1667};
_S_or2  S_or2_244_2 = {&var1708,&var1707,&var1668};
_S_and4  S_and4_159_2 = {&A0EE02LZ1,&A0EE04LZ1,&A0EE02LZ2,&A0EE04LZ2,&var1669};
_S_or3  S_or3_158_2 = {&var1669,&var816,&var1663,&var1670};
_S_and4  S_and4_136_2 = {&A0EE03LZ1,&A0EE01LZ1,&A0EE01LZ2,&A0EE03LZ2,&var1671};
_S_or3  S_or3_135_2 = {&var1671,&var1664,&var816,&var1672};
_S_and3  S_and3_110_2 = {&var1674,&var1740,&A8IS12LDU,&var1673};
_S_or2  S_or2_104_2 = {&A8MC01LC2,&A8MC01LC1,&var1674};
_S_or2  S_or2_103_2 = {&B8MC01LC2,&B8MC01LC1,&var1675};
_S_and3  S_and3_79_2 = {&var1740,&B3IS11LDU,&var1677,&var1676};
_S_or2  S_or2_71_2 = {&B3MC01LC2,&B3MC01LC1,&var1677};
_S_or2  S_or2_74_2 = {&A3MC01LC2,&A3MC01LC1,&var1678};
_S_and3  S_and3_82_2 = {&var1740,&var1678,&A3IS11LDU,&var1679};
_S_or2  S_or2_43_2 = {&A2MC01LC2,&A2MC01LC1,&var1680};
_S_and3  S_and3_49_2 = {&var1740,&A2IS11LDU,&var1680,&var1681};
_S_or2  S_or2_13_2 = {&A1MC01LC2,&A1MC01LC1,&var1682};
_S_and3  S_and3_23_2 = {&var1682,&var1740,&A1IS11LDU,&var1683};
_S_or2  S_or2_42_2 = {&B2MC01LC1,&B2MC01LC2,&var1684};
_S_and3  S_and3_45_2 = {&var1740,&B2IS11LDU,&var1684,&var1685};
_S_or2  S_or2_11_2 = {&B1MC01LC2,&B1MC01LC1,&var1686};
_S_and3  S_and3_19_2 = {&var1740,&B1IS11LDU,&var1686,&var1687};
_S_and2  S_and2_254_2 = {&syn_R0EE03LDU,&var1665,&var1688};
_S_and2  S_and2_233_2 = {&syn_R0EE03LDU,&var1666,&var1689};
_S_and2  S_and2_219_2 = {&var1702,&var1711,&var1690};
_S_scalzz  S_scalzz_186_2 = {&B3IP02IDU,&iRM_3276_,&iRM_16383_,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&var1691,&internal2_m186_y0};
_S_scalzz  S_scalzz_184_2 = {&A3IP02IDU,&iRM_3276_,&iRM_16383_,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&var1692,&internal2_m184_y0};
_S_noto  S_noto_171_2 = {&var1694,&var1693};
_S_andn  S_andn_170_2 = {array_m170_x_2,&iRM_17_,&var1694};
_S_noto  S_noto_153_2 = {&var1696,&var1695};
_S_andn  S_andn_150_2 = {array_m150_x_2,&iRM_6_,&var1696};
_S_noto  S_noto_134_2 = {&var1698,&var1697};
_S_andn  S_andn_131_2 = {array_m131_x_2,&iRM_6_,&var1698};
_S_noto  S_noto_253_2 = {&var1707,&var1699};
_S_noto  S_noto_235_2 = {&var1708,&var1700};
_S_noto  S_noto_212_2 = {&var1716,&var1701};
_S_noto  S_noto_220_2 = {&var1713,&var1702};
_S_noto  S_noto_157_2 = {&var1670,&var1703};
_S_noto  S_noto_141_2 = {&var1672,&var1704};
_S_noto  S_noto_256_2 = {&var1709,&var1705};
_S_noto  S_noto_240_2 = {&var1710,&var1706};
_S_ornc  S_ornc_243_2 = {array_m243_x_2,&iRM_6_,&var1707,&vainSChar};
_S_ornc  S_ornc_232_2 = {array_m232_x_2,&iRM_6_,&var1708,&vainSChar};
_S_ornc  S_ornc_255_2 = {array_m255_x_2,&iRM_6_,&var1709,&vainSChar};
_S_ornc  S_ornc_234_2 = {array_m234_x_2,&iRM_6_,&var1710,&vainSChar};
_S_tprg  S_tprg_216_2 = {&var1691,&fEM_A3UP85RDU,&fEM_A3UP86RDU,&fEM_A3UP87RDU,&fEM_A3UP88RDU,&var1711,&internal2_m216_y0};
_S_tprg  S_tprg_210_2 = {&var1692,&fEM_A3UP85RDU,&fEM_A3UP86RDU,&fEM_A3UP87RDU,&fEM_A3UP88RDU,&var1712,&internal2_m210_y0};
_S_geterr  S_geterr_191_2 = {&var1691,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var1713};
_S_drg  S_drg_199_2 = {&var1691,&lRM_1_,&lRM_0_,&fEM_A3UP43RDU,&fEM_A3UP44RDU,&var1714,&internal2_m199_y1};
_S_drg  S_drg_206_2 = {&var1691,&lRM_1_,&lRM_0_,&fEM_A3UP53RDU,&fEM_A3UP54RDU,&var1715,&internal2_m206_y1};
_S_geterr  S_geterr_188_2 = {&var1692,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var1716};
_S_drg  S_drg_189_2 = {&var1692,&lRM_1_,&lRM_0_,&fEM_A3UP43RDU,&fEM_A3UP44RDU,&var1717,&internal2_m189_y1};
_S_drg  S_drg_196_2 = {&var1692,&lRM_1_,&lRM_0_,&fEM_A3UP53RDU,&fEM_A3UP54RDU,&var1718,&internal2_m196_y1};
_S_enctkb  S_enctkb_16_2 = {&var1652,&fRM_0_0,&A1IC01UDU,&dEM_A1UC06UDU,&dEM_A1UC05UDU,&fEM_A1UC03RDU,&fRM_100_,&dRM_0_,&var1719,&var1720,&var1721,&internal2_m16_Nk0,&internal2_m16_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_108_2 = {&var1647,&fRM_390_,&B8IC01UDU,&dEM_A8UC06UDU,&dEM_A8UC05UDU,&fEM_A8UC03RDU,&fRM_1500_0,&dRM_0_,&var1722,&var1723,&var1724,&internal2_m108_Nk0,&internal2_m108_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_112_2 = {&var1646,&fRM_390_0,&A8IC01UDU,&dEM_A8UC06UDU,&dEM_A8UC05UDU,&fEM_A8UC03RDU,&fRM_1500_0,&dRM_0_,&var1725,&var1726,&var1727,&internal2_m112_Nk0,&internal2_m112_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_75_2 = {&var1648,&fRM_0_,&B3IC01UDU,&dEM_A3UC06UDU,&dEM_A3UC05UDU,&fEM_A3UC03RDU,&fRM_0_0,&dRM_0_,&var1728,&var1729,&var1730,&internal2_m75_Nk0,&internal2_m75_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_77_2 = {&var1650,&fRM_0_0,&A3IC01UDU,&dEM_A3UC06UDU,&dEM_A3UC05UDU,&fEM_A3UC03RDU,&fRM_0_0,&dRM_0_,&var1731,&var1732,&var1733,&internal2_m77_Nk0,&internal2_m77_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_47_2 = {&var1651,&fRM_0_0,&B2IC01UDU,&dEM_A2UC06UDU,&dEM_A2UC05UDU,&fEM_A2UC03RDU,&fRM_100_,&dRM_0_,&var1734,&var1735,&var1736,&internal2_m47_Nk0,&internal2_m47_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_51_2 = {&var1649,&fRM_0_0,&A2IC01UDU,&dEM_A2UC06UDU,&dEM_A2UC05UDU,&fEM_A2UC03RDU,&fRM_100_,&dRM_0_,&var1737,&var1738,&var1739,&internal2_m51_Nk0,&internal2_m51_SetFlag,&bFirstEnterFlag};
_S_equz_p  S_equz_p_18_2 = {&R0MW12IP1,&iRM_4_,&var1740};
_S_enctkb  S_enctkb_21_2 = {&var1653,&fRM_0_0,&B1IC01UDU,&dEM_A1UC06UDU,&dEM_A1UC05UDU,&fEM_A1UC03RDU,&fRM_100_,&dRM_0_,&var1741,&var1742,&var1743,&internal2_m21_Nk0,&internal2_m21_SetFlag,&bFirstEnterFlag};
_S_ornc  S_ornc_124_2 = {array_m124_x_2,&iRM_8_,&var1744,&vainSChar};
_S_noto  S_noto_1849_1 = {&B7AS31LDU,&var1};
_S_noto  S_noto_1846_1 = {&A7AS31LDU,&var2};
_S_or3  S_or3_2318_1 = {&var4,&var7,&var8,&var3};
_S_orn  S_orn_2317_1 = {array_m2317_x_1,&iRM_6_,&var4};
_S_or2  S_or2_2322_1 = {&R0DEB3LDU,&R0DEB4LDU,&var5};
_S_or2  S_or2_2315_1 = {&R0DEB1LDU,&R0DEB2LDU,&var6};
_S_and2  S_and2_2306_1 = {&R0DE31LDU,&R0DE32LDU,&var7};
_S_diagndev  S_diagndev_2301_1 = {array_m2301_x_1,&iRM_12_,&var8,&var9};
_S_or2  S_or2_1698_1 = {&var247,&var60,&var10};
_S_and2  S_and2_1688_1 = {&var303,&var1208,&var11};
_S_rs  S_rs_1697_1 = {&var10,&var11,&var12,&vainSBool,&internal1_m1697_q0};
_S_or2  S_or2_1692_1 = {&var303,&var250,&var13};
_S_or2  S_or2_1633_1 = {&var1258,&var303,&var14};
_S_noto  S_noto_1676_1 = {&B2IS11LDU,&var15};
_S_or2  S_or2_1661_1 = {&var18,&var60,&var16};
_S_or2  S_or2_1663_1 = {&var130,&var60,&var17};
_S_noto  S_noto_1674_1 = {&A2IS11LDU,&var18};
_S_or2  S_or2_2139_1 = {&var247,&var56,&var19};
_S_or2  S_or2_2137_1 = {&var56,&var254,&var20};
_S_or2  S_or2_2135_1 = {&var69,&var56,&var21};
_S_and2  S_and2_2118_1 = {&var1205,&var301,&var22};
_S_or2  S_or2_2133_1 = {&var24,&var56,&var23};
_S_noto  S_noto_2142_1 = {&B3IS11LDU,&var24};
_S_or2  S_or2_2169_1 = {&var60,&var254,&var25};
_S_and2  S_and2_2149_1 = {&var1205,&var302,&var26};
_S_noto  S_noto_2174_1 = {&A3IS11LDU,&var27};
_S_or2  S_or2_2171_1 = {&var247,&var60,&var28};
_S_or2  S_or2_2167_1 = {&var60,&var70,&var29};
_S_or2  S_or2_2165_1 = {&var60,&var27,&var30};
_S_or2  S_or2_1641_1 = {&var247,&var60,&var31};
_S_or2  S_or2_1645_1 = {&var247,&var56,&var32};
_S_or2  S_or2_1636_1 = {&var303,&var1258,&var33};
_S_or2  S_or2_1671_1 = {&var56,&var129,&var34};
_S_or2  S_or2_1669_1 = {&var15,&var56,&var35};
_S_or2  S_or2_1714_1 = {&var254,&var56,&var36};
_S_or2  S_or2_1711_1 = {&var254,&var60,&var37};
_S_or2  S_or2_1743_1 = {&var260,&var56,&var38};
_S_or2  S_or2_1740_1 = {&var260,&var60,&var39};
_S_or2  S_or2_1700_1 = {&var247,&var56,&var40};
_S_or2  S_or2_1665_1 = {&var247,&var60,&var41};
_S_or2  S_or2_1673_1 = {&var247,&var56,&var42};
_S_or3  S_or3_2129_1 = {&var254,&var301,&var56,&var43};
_S_or3  S_or3_2131_1 = {&var79,&var301,&var56,&var44};
_S_or3  S_or3_2163_1 = {&var60,&var82,&var302,&var45};
_S_or3  S_or3_2161_1 = {&var254,&var60,&var302,&var46};
_S_or3  S_or3_2127_1 = {&var301,&var247,&var56,&var47};
_S_or3  S_or3_2159_1 = {&var247,&var302,&var60,&var48};
_S_or3  S_or3_1639_1 = {&var247,&var302,&var60,&var49};
_S_or3  S_or3_1643_1 = {&var301,&var247,&var56,&var50};
_S_or3  S_or3_1659_1 = {&var247,&var302,&var60,&var51};
_S_or3  S_or3_1667_1 = {&var247,&var301,&var56,&var52};
_S_or3  S_or3_1696_1 = {&var247,&var303,&var56,&var53};
_S_or3  S_or3_1694_1 = {&var247,&var60,&var303,&var54};
_S_or3  S_or3_1742_1 = {&var56,&var301,&var260,&var55};
_S_noto  S_noto_1737_1 = {&var913,&var56};
_S_or3  S_or3_1713_1 = {&var56,&var254,&var301,&var57};
_S_or3  S_or3_1710_1 = {&var254,&var60,&var302,&var58};
_S_or3  S_or3_1739_1 = {&var260,&var60,&var302,&var59};
_S_noto  S_noto_1736_1 = {&var912,&var60};
_S_regch  S_regch_131_1 = {&R0MW12IP1,&var902,&var61};
_S_or2  S_or2_134_1 = {&var63,&var61,&var62};
_S_or2  S_or2_133_1 = {&R0VZ71LZ1,&R0VZ71LZ2,&var63};
_S_and3  S_and3_1406_1 = {&R0MD11LP2,&var961,&var67,&var64};
_S_and2  S_and2_729_1 = {&R4MD21LP2,&var67,&var65};
_S_and2  S_and2_728_1 = {&R4MD11LP2,&var67,&var66};
_S_noto  S_noto_113_1 = {&var1635,&var67};
_S_and2  S_and2_111_1 = {&R0MD11LP1,&var67,&var68};
_S_noto  S_noto_2143_1 = {&B3IS22LDU,&var69};
_S_noto  S_noto_2175_1 = {&A3IS22LDU,&var70};
_S_and2  S_and2_2066_1 = {&var478,&var1187,&var71};
_S_or3  S_or3_2061_1 = {&var477,&var173,&var111,&var72};
_S_and2  S_and2_2050_1 = {&var474,&var1187,&var73};
_S_or3  S_or3_2047_1 = {&var173,&var475,&var94,&var74};
_S_or2  S_or2_1471_1 = {&var1276,&var1205,&var75};
_S_or2  S_or2_1440_1 = {&var1133,&var1205,&var76};
_S_rs  S_rs_2132_1 = {&var23,&var80,&var77,&vainSBool,&internal1_m2132_q0};
_S_rs  S_rs_2116_1 = {&var23,&var99,&var78,&vainSBool,&internal1_m2116_q0};
_S_noto  S_noto_2140_1 = {&syn_B3VP52LDU,&var79};
_S_and2  S_and2_2123_1 = {&var79,&var78,&var80};
_S_rs  S_rs_2164_1 = {&var30,&var83,&var81,&vainSBool,&internal1_m2164_q0};
_S_noto  S_noto_2172_1 = {&syn_A3VP52LDU,&var82};
_S_and2  S_and2_2155_1 = {&var84,&var82,&var83};
_S_rs  S_rs_2148_1 = {&var30,&var117,&var84,&vainSBool,&internal1_m2148_q0};
_S_and4  S_and4_1361_1 = {&var961,&var1205,&var265,&var1250,&var85};
_S_and4  S_and4_949_1 = {&var961,&var1205,&var265,&var1250,&var86};
_S_rs  S_rs_2138_1 = {&var19,&var92,&var87,&vainSBool,&internal1_m2138_q0};
_S_or4  S_or4_1298_1 = {&var597,&var287,&var1000,&var94,&var88};
_S_or4  S_or4_1307_1 = {&var162,&var290,&var773,&var100,&var89};
_S_orn  S_orn_802_1 = {array_m802_x_1,&iRM_6_,&var90};
_S_or3  S_or3_814_1 = {&var792,&var1201,&var103,&var91};
_S_and2  S_and2_2125_1 = {&var254,&var93,&var92};
_S_rs  S_rs_2119_1 = {&var19,&var95,&var93,&vainSBool,&internal1_m2119_q0};
_S_rs  S_rs_2136_1 = {&var95,&var20,&var94,&vainSBool,&internal1_m2136_q0};
_S_and2  S_and2_2124_1 = {&var96,&var69,&var95};
_S_rs  S_rs_2117_1 = {&var20,&var22,&var96,&vainSBool,&internal1_m2117_q0};
_S_rs  S_rs_2115_1 = {&var44,&var101,&var97,&vainSBool,&internal1_m2115_q0};
_S_rs  S_rs_2114_1 = {&var43,&var102,&var98,&vainSBool,&internal1_m2114_q0};
_S_and2  S_and2_2122_1 = {&var254,&var97,&var99};
_S_rs  S_rs_2128_1 = {&var43,&var101,&var100,&vainSBool,&internal1_m2128_q0};
_S_and2  S_and2_2121_1 = {&var98,&var247,&var101};
_S_and2  S_and2_2120_1 = {&var304,&var1205,&var102};
_S_rs  S_rs_2126_1 = {&var47,&var102,&var103,&vainSBool,&internal1_m2126_q0};
_S_rs  S_rs_2134_1 = {&var22,&var21,&var104,&vainSBool,&internal1_m2134_q0};
_S_rs  S_rs_2130_1 = {&var44,&var99,&var105,&vainSBool,&internal1_m2130_q0};
_S_orn  S_orn_1202_1 = {array_m1202_x_1,&iRM_6_,&var106};
_S_rs  S_rs_2170_1 = {&var28,&var108,&var107,&vainSBool,&internal1_m2170_q0};
_S_and2  S_and2_2157_1 = {&var254,&var109,&var108};
_S_rs  S_rs_2151_1 = {&var28,&var112,&var109,&vainSBool,&internal1_m2151_q0};
_S_or4  S_or4_881_1 = {&var596,&var291,&var1000,&var111,&var110};
_S_rs  S_rs_2168_1 = {&var25,&var112,&var111,&vainSBool,&internal1_m2168_q0};
_S_and2  S_and2_2156_1 = {&var113,&var70,&var112};
_S_rs  S_rs_2150_1 = {&var25,&var26,&var113,&vainSBool,&internal1_m2150_q0};
_S_rs  S_rs_2147_1 = {&var45,&var120,&var114,&vainSBool,&internal1_m2147_q0};
_S_or4  S_or4_890_1 = {&var1198,&var162,&var783,&var118,&var115};
_S_rs  S_rs_2146_1 = {&var46,&var121,&var116,&vainSBool,&internal1_m2146_q0};
_S_and2  S_and2_2154_1 = {&var254,&var114,&var117};
_S_rs  S_rs_2160_1 = {&var46,&var120,&var118,&vainSBool,&internal1_m2160_q0};
_S_or3  S_or3_1214_1 = {&var791,&var1203,&var122,&var119};
_S_and2  S_and2_2153_1 = {&var116,&var247,&var120};
_S_and2  S_and2_2152_1 = {&var305,&var1205,&var121};
_S_rs  S_rs_2158_1 = {&var48,&var121,&var122,&vainSBool,&internal1_m2158_q0};
_S_or2  S_or2_2033_1 = {&var164,&var1032,&var123};
_S_ovbs  S_ovbs_2035_1 = {&var223,&fRM_2_0,&var124,&internal1_m2035_tx};
_S_or2  S_or2_2036_1 = {&var1214,&var124,&var125};
_S_ovbs  S_ovbs_2014_1 = {&var224,&fRM_2_0,&var126,&internal1_m2014_tx};
_S_or2  S_or2_2012_1 = {&var165,&var1033,&var127};
_S_or2  S_or2_2015_1 = {&var1234,&var126,&var128};
_S_noto  S_noto_1677_1 = {&B2IS21LDU,&var129};
_S_noto  S_noto_1675_1 = {&A2IS21LDU,&var130};
_S_and2  S_and2_2086_1 = {&syn_B3VP52LDU,&var479,&var131};
_S_or5  S_or5_2089_1 = {&var654,&var1644,&var148,&var104,&var131,&var132};
_S_or5  S_or5_2088_1 = {&var405,&var1196,&var481,&var1644,&syn_A3VP52LDU,&var133};
_S_and2  S_and2_2063_1 = {&syn_A3VP52LDU,&var480,&var134};
_S_nocnm  S_nocnm_1720_1 = {&R5IS21LDU,&R5IS11LDU,&var135,&var136,&var137,&internal1_m1720_Pv0,&internal1_m1720_Zv0,&internal1_m1720_MyFirstEnterFlag,&bFirstEnterFlag};
_S_nocnm  S_nocnm_1718_1 = {&R3IS11LDU,&R3IS21LDU,&var138,&var139,&var140,&internal1_m1718_Pv0,&internal1_m1718_Zv0,&internal1_m1718_MyFirstEnterFlag,&bFirstEnterFlag};
_S_or5  S_or5_1983_1 = {&var996,&var704,&C2MD31LP1,&var995,&var994,&var141};
_S_or4  S_or4_1959_1 = {&C1MD31LP2,&C1MD31LP1,&var731,&var751,&var142};
_S_and3  S_and3_414_1 = {&B8IS22LDU,&B8IS21LDU,&var1617,&var143};
_S_and2  S_and2_2052_1 = {&var473,&var173,&var144};
_S_and2  S_and2_2060_1 = {&var476,&var173,&var145};
_S_or4  S_or4_981_1 = {&var1323,&var666,&var665,&var668,&var146};
_S_or4  S_or4_1393_1 = {&var1291,&var647,&var648,&var651,&var147};
_S_and2  S_and2_2090_1 = {&var394,&var1187,&var148};
_S_and2  S_and2_2075_1 = {&var479,&var1644,&var149};
_S_and2  S_and2_2064_1 = {&var480,&var1644,&var150};
_S_or2  S_or2_553_1 = {&B1VP41LZ2,&B1VP41LZ1,&var151};
_S_or2  S_or2_236_1 = {&A1VP41LZ2,&A1VP41LZ1,&var152};
_S_or2  S_or2_1115_1 = {&B8IS22LDU,&B8IS21LDU,&var153};
_S_or2  S_or2_1110_1 = {&B8IS11LDU,&B8IS12LDU,&var154};
_S_or2  S_or2_355_1 = {&R4IS11LDU,&R4IS12LDU,&var155};
_S_or2  S_or2_372_1 = {&R4IS21LDU,&R4IS22LDU,&var156};
_S_or2  S_or2_1069_1 = {&var1003,&R0MD34LP1,&var157};
_S_or2  S_or2_1072_1 = {&var1001,&R0MD34LP1,&var158};
_S_or2  S_or2_1075_1 = {&var999,&R0MD34LP1,&var159};
_S_or2  S_or2_1078_1 = {&var997,&R0MD34LP1,&var160};
_S_noto  S_noto_2200_1 = {&var1644,&var161};
_S_zzfs  S_zzfs_2189_1 = {&var179,&fRM_0_5,&var162,&internal1_m2189_tx,&internal1_m2189_y0};
_S_or2  S_or2_2223_1 = {&var355,&var1005,&var163};
_S_andn  S_andn_593_1 = {array_m593_x_1,&iRM_6_,&var164};
_S_andn  S_andn_592_1 = {array_m592_x_1,&iRM_6_,&var165};
_S_or2  S_or2_2239_1 = {&var681,&var646,&var166};
_S_noto  S_noto_2185_1 = {&var1031,&var167};
_S_noto  S_noto_2184_1 = {&var1028,&var168};
_S_zpfs  S_zpfs_2193_1 = {&var167,&fRM_30_0,&var169,&internal1_m2193_tx,&internal1_m2193_y0};
_S_noto  S_noto_2198_1 = {&var169,&var170};
_S_zpfs  S_zpfs_2192_1 = {&var168,&fRM_30_0,&var171,&internal1_m2192_tx,&internal1_m2192_y0};
_S_noto  S_noto_2197_1 = {&var171,&var172};
_S_and3  S_and3_2191_1 = {&var212,&var192,&lRM_1_,&var173};
_S_and2  S_and2_909_1 = {&var1349,&var175,&var174};
_S_noto  S_noto_898_1 = {&var162,&var175};
_S_and2  S_and2_1324_1 = {&var1317,&var177,&var176};
_S_noto  S_noto_1321_1 = {&var162,&var177};
_S_or2  S_or2_2233_1 = {&var188,&var189,&var178};
_S_and2  S_and2_2188_1 = {&var180,&var173,&var179};
_S_abs_subf  S_abs_subf_2180_1 = {&var1731,&var213,&fEM_A3UC08RDU,&vainSFloat,&var180};
_S_and2  S_and2_2235_1 = {&var173,&var188,&var181};
_S_or4  S_or4_1984_1 = {&var141,&var809,&var919,&var181,&var182};
_S_noto  S_noto_2238_1 = {&var166,&var183};
_S_or2  S_or2_2214_1 = {&var206,&var217,&var184};
_S_inf  S_inf_2210_1 = {&var215,array_m2210_a_1,array_m2210_b_1,&iRM_6_,&var185,&vainSInt};
_S_or3  S_or3_2237_1 = {&var202,&var209,&var210,&var186};
_S_noto  S_noto_2236_1 = {&var186,&var187};
_S_noto  S_noto_2234_1 = {&var212,&var188};
_S_ovbs  S_ovbs_2229_1 = {&var191,&fRM_15_0,&var189,&internal1_m2229_tx};
_S_zpfs  S_zpfs_2227_1 = {&var192,&fRM_10_0,&var190,&internal1_m2227_tx,&internal1_m2227_y0};
_S_and2  S_and2_2228_1 = {&var190,&R0MW17LP1,&var191};
_S_rs  S_rs_2232_1 = {&var178,&R0MW17LP1,&var192,&vainSBool,&internal1_m2232_q0};
_S_rs  S_rs_2199_1 = {&var206,&var173,&var193,&vainSBool,&internal1_m2199_q0};
_S_and3  S_and3_2206_1 = {&var208,&var161,&var193,&var194};
_S_ml  S_ml_1302_1 = {&var213,&var315,&var162,&var195};
_S_ml  S_ml_885_1 = {&var213,&var319,&var162,&var196};
_S_and2  S_and2_2253_1 = {&var173,&var332,&var197};
_S_noto  S_noto_2221_1 = {&var163,&var198};
_S_noto  S_noto_2204_1 = {&var1288,&var199};
_S_sr  S_sr_2222_1 = {array_m2222_x_1,&iRM_4_,&var200};
_S_sr  S_sr_2243_1 = {array_m2243_x_1,&iRM_2_,&var201};
_S_and2  S_and2_2257_1 = {&var203,&var173,&var202};
_S_abs_subf  S_abs_subf_2252_1 = {&B3MC01RP1,&A3MC01RP1,&fRM_0_01,&vainSFloat,&var203};
_S_fsumo  S_fsumo_86_1 = {&var981,&fEM_R0UN11RDU,&var204};
_S_or3  S_or3_132_1 = {&var142,&var62,&var184,&var205};
_S_ovbs  S_ovbs_2207_1 = {&var194,&fRM_1_0,&var206,&internal1_m2207_tx};
_S_noto  S_noto_2213_1 = {&var184,&var207};
_S_rs  S_rs_2205_1 = {&var206,&var1644,&var208,&vainSBool,&internal1_m2205_q0};
_S_and2  S_and2_2256_1 = {&var217,&var173,&var209};
_S_and2  S_and2_2255_1 = {&var211,&var173,&var210};
_S_bol  S_bol_2246_1 = {&fEM_R0UN09RDU,&var201,&var211};
_S_andn  S_andn_2212_1 = {array_m2212_x_1,&iRM_14_,&var212};
_S_irm  S_irm_2187_1 = {&var981,&var979,&B3MC01RP1,&var1731,&var201,&var200,&var173,&var1005,&fEM_R0UN12RDU,&fEM_R0UN13RDU,&fEM_R0UN14RDU,&fEM_R0UT20RDU,&var185,&fEM_R0UN15RDU,&fEM_R0UN25RDU,&fEM_R0UN16RDU,&fEM_R0UN17RDU,&fEM_R0UN18RDU,&fEM_R0UN19RDU,&fEM_R0UN27RDU,&fEM_R0UN26RDU,&fEM_R0UN24RDU,&var213,&var214,&var215,&var216,&var217,&var218,&var219,&var220};
_S_noto  S_noto_2041_1 = {&var343,&var221};
_S_noto  S_noto_2011_1 = {&var344,&var222};
_S_and4  S_and4_2034_1 = {&var366,&var123,&var336,&var221,&var223};
_S_and4  S_and4_2013_1 = {&var367,&var127,&var336,&var222,&var224};
_S_zpfs  S_zpfs_2029_1 = {&var350,&fRM_210_0,&var225,&internal1_m2029_tx,&internal1_m2029_y0};
_S_zpfs  S_zpfs_2021_1 = {&var351,&fRM_210_0,&var226,&internal1_m2021_tx,&internal1_m2021_y0};
_S_and2  S_and2_556_1 = {&var1364,&var399,&var227};
_S_and2  S_and2_239_1 = {&var399,&var1397,&var228};
_S_noto  S_noto_1560_1 = {&var230,&var229};
_S_abs_subf  S_abs_subf_1551_1 = {&var1728,&var315,&fEM_A3UC07RDU,&vainSFloat,&var230};
_S_noto  S_noto_1542_1 = {&var232,&var231};
_S_abs_subf  S_abs_subf_1531_1 = {&var319,&var1731,&fEM_A3UC07RDU,&vainSFloat,&var232};
_S_noto  S_noto_1556_1 = {&var234,&var233};
_S_abs_subf  S_abs_subf_1550_1 = {&var323,&var1741,&fEM_A1UC07RDU,&vainSFloat,&var234};
_S_noto  S_noto_1537_1 = {&var236,&var235};
_S_abs_subf  S_abs_subf_1529_1 = {&var327,&var1719,&fEM_A1UC07RDU,&vainSFloat,&var236};
_S_bol  S_bol_1320_1 = {&var1728,&fEM_A3UC09RDU,&var237};
_S_bol  S_bol_906_1 = {&var1731,&fEM_A3UC09RDU,&var238};
_S_noto  S_noto_1784_1 = {&var243,&var239};
_S_noto  S_noto_1773_1 = {&var241,&var240};
_S_and3  S_and3_1766_1 = {&var913,&var242,&var1205,&var241};
_S_bol  S_bol_1758_1 = {&fRM_55_0,&var315,&var242};
_S_and3  S_and3_1785_1 = {&var244,&var912,&var1205,&var243};
_S_bol  S_bol_1794_1 = {&fRM_55_0,&var319,&var244};
_S_and4  S_and4_51_1 = {&var1635,&var911,&var1090,&var1187,&var245};
_S_noto  S_noto_1238_1 = {&var961,&var246};
_S_and2  S_and2_1241_1 = {&var1464,&var961,&var247};
_S_and2  S_and2_1234_1 = {&var1464,&var246,&var248};
_S_noto  S_noto_1183_1 = {&var961,&var249};
_S_and2  S_and2_1186_1 = {&var961,&var1538,&var250};
_S_and2  S_and2_1184_1 = {&var1538,&var249,&var251};
_S_noto  S_noto_915_1 = {&var961,&var252};
_S_and2  S_and2_916_1 = {&var252,&var1320,&var253};
_S_and2  S_and2_912_1 = {&var1320,&var961,&var254};
_S_noto  S_noto_468_1 = {&var961,&var255};
_S_and2  S_and2_469_1 = {&var255,&var1413,&var256};
_S_and2  S_and2_471_1 = {&var1413,&var961,&var257};
_S_noto  S_noto_196_1 = {&var961,&var258};
_S_and2  S_and2_197_1 = {&var258,&var1383,&var259};
_S_and2  S_and2_200_1 = {&var961,&var1383,&var260};
_S_and2  S_and2_127_1 = {&var263,&var388,&var261};
_S_and2  S_and2_128_1 = {&var961,&var388,&var262};
_S_noto  S_noto_122_1 = {&var961,&var263};
_S_and2  S_and2_123_1 = {&var263,&var387,&var264};
_S_and2  S_and2_124_1 = {&var961,&var387,&var265};
_S_and2  S_and2_1631_1 = {&var301,&var1209,&var266};
_S_and2  S_and2_1630_1 = {&var304,&var1209,&var267};
_S_and2  S_and2_1629_1 = {&var302,&var1209,&var268};
_S_and2  S_and2_1628_1 = {&var1209,&var305,&var269};
_S_and2  S_and2_1627_1 = {&var522,&var303,&var270};
_S_and2  S_and2_1626_1 = {&var522,&var306,&var271};
_S_and2  S_and2_1625_1 = {&var523,&var303,&var272};
_S_and2  S_and2_1624_1 = {&var523,&var306,&var273};
_S_and2  S_and2_1657_1 = {&var34,&var1166,&var274};
_S_and2  S_and2_1656_1 = {&var301,&var1210,&var275};
_S_and2  S_and2_1655_1 = {&var1167,&var301,&var276};
_S_and2  S_and2_1654_1 = {&var1210,&var304,&var277};
_S_and2  S_and2_1653_1 = {&var130,&var1168,&var278};
_S_and2  S_and2_1652_1 = {&var1210,&var302,&var279};
_S_and2  S_and2_1651_1 = {&var1169,&var247,&var280};
_S_and2  S_and2_1650_1 = {&var1210,&var305,&var281};
_S_and2  S_and2_1690_1 = {&var247,&var1170,&var282};
_S_and2  S_and2_1689_1 = {&var303,&var1208,&var283};
_S_and2  S_and2_1687_1 = {&var1171,&var250,&var284};
_S_and2  S_and2_1686_1 = {&var1172,&var250,&var285};
_S_and2  S_and2_1685_1 = {&var306,&var1208,&var286};
_S_rs  S_rs_1707_1 = {&var36,&var288,&var287,&vainSBool,&internal1_m1707_q0};
_S_and2  S_and2_1706_1 = {&var1206,&var301,&var288};
_S_and2  S_and2_1705_1 = {&var1206,&var304,&var289};
_S_rs  S_rs_1712_1 = {&var57,&var289,&var290,&vainSBool,&internal1_m1712_q0};
_S_rs  S_rs_1704_1 = {&var37,&var292,&var291,&vainSBool,&internal1_m1704_q0};
_S_and2  S_and2_1703_1 = {&var302,&var1206,&var292};
_S_and2  S_and2_1702_1 = {&var1206,&var305,&var293};
_S_and2  S_and2_1735_1 = {&var303,&var1637,&var294};
_S_rs  S_rs_1746_1 = {&var257,&var294,&var295,&vainSBool,&internal1_m1746_q0};
_S_and2  S_and2_1734_1 = {&var1637,&var306,&var296};
_S_and2  S_and2_1732_1 = {&var301,&var1194,&var297};
_S_and2  S_and2_1731_1 = {&var1194,&var304,&var298};
_S_and2  S_and2_1729_1 = {&var302,&var1194,&var299};
_S_and2  S_and2_1728_1 = {&var1194,&var305,&var300};
_S_and2  S_and2_1748_1 = {&var913,&var303,&var301};
_S_and2  S_and2_1727_1 = {&var912,&var303,&var302};
_S_and2  S_and2_1750_1 = {&var262,&var1250,&var303};
_S_and2  S_and2_1747_1 = {&var306,&var913,&var304};
_S_and2  S_and2_1726_1 = {&var306,&var912,&var305};
_S_and2  S_and2_1749_1 = {&var265,&var1250,&var306};
_S_zpfs  S_zpfs_746_1 = {&var877,&fRM_3_,&var307,&internal1_m746_tx,&internal1_m746_y0};
_S_or4  S_or4_1571_1 = {&var513,&var514,&var515,&var517,&var308};
_S_or5  S_or5_1562_1 = {&var521,&var520,&var519,&var518,&var308,&var309};
_S_andn  S_andn_1_1 = {array_m1_x_1,&iRM_47_,&vainSBool};
_S_or2  S_or2_1544_1 = {&var312,&var313,&var310};
_S_ml  S_ml_1528_1 = {&fRM_1500_0,&B8MC01RP2,&var310,&var311};
_S_bol  S_bol_1534_1 = {&B8MC01RP2,&fRM_1500_0001,&var312};
_S_bol  S_bol_1545_1 = {&fRM_389_99,&B8MC01RP2,&var313};
_S_or2  S_or2_1558_1 = {&var316,&var317,&var314};
_S_ml  S_ml_1549_1 = {&fRM_0_0,&B3MC01RP1,&var314,&var315};
_S_bol  S_bol_1553_1 = {&B3MC01RP1,&fRM_160_00001,&var316};
_S_bol  S_bol_1559_1 = {&fRM_0_0001,&B3MC01RP1,&var317};
_S_or2  S_or2_1540_1 = {&var320,&var321,&var318};
_S_ml  S_ml_1527_1 = {&fRM_0_0,&A3MC01RP1,&var318,&var319};
_S_bol  S_bol_1530_1 = {&A3MC01RP1,&fRM_160_0001,&var320};
_S_bol  S_bol_1541_1 = {&fRM_0_0001,&A3MC01RP1,&var321};
_S_or2  S_or2_1555_1 = {&var324,&var325,&var322};
_S_ml  S_ml_1547_1 = {&fRM_100_0,&B1MC01RP1,&var322,&var323};
_S_bol  S_bol_1552_1 = {&B1MC01RP1,&fRM_100_0001,&var324};
_S_bol  S_bol_1561_1 = {&fRM_0_0001,&B1MC01RP1,&var325};
_S_or2  S_or2_1536_1 = {&var328,&var329,&var326};
_S_ml  S_ml_1525_1 = {&fRM_100_0,&A1MC01RP1,&var326,&var327};
_S_bol  S_bol_1533_1 = {&A1MC01RP1,&fRM_100_0001,&var328};
_S_bol  S_bol_1538_1 = {&fRM_0_0001,&A1MC01RP1,&var329};
_S_and2  S_and2_108_1 = {&var68,&var155,&var330};
_S_noto  S_noto_109_1 = {&var155,&var331};
_S_and2  S_and2_112_1 = {&var68,&var331,&var332};
_S_and2  S_and2_2000_1 = {&var334,&var335,&var333};
_S_or3  S_or3_1999_1 = {&var1212,&var466,&var182,&var334};
_S_noto  S_noto_2037_1 = {&var125,&var335};
_S_noto  S_noto_2026_1 = {&var337,&var336};
_S_ovbs  S_ovbs_2025_1 = {&var1102,&fRM_2_0,&var337,&internal1_m2025_tx};
_S_noto  S_noto_2016_1 = {&var128,&var338};
_S_and2  S_and2_1986_1 = {&var340,&var338,&var339};
_S_or3  S_or3_1985_1 = {&var182,&var1216,&var466,&var340};
_S_noto  S_noto_2031_1 = {&var348,&var341};
_S_and2  S_and2_2032_1 = {&var1187,&var341,&var342};
_S_and2  S_and2_2040_1 = {&var342,&var123,&var343};
_S_and2  S_and2_2019_1 = {&var345,&var127,&var344};
_S_and2  S_and2_2024_1 = {&var346,&var1187,&var345};
_S_noto  S_noto_2023_1 = {&var904,&var346};
_S_noto  S_noto_2039_1 = {&var350,&var347};
_S_or2  S_or2_2030_1 = {&var225,&var347,&var348};
_S_noto  S_noto_2018_1 = {&var351,&var349};
_S_rs  S_rs_2028_1 = {&var225,&var356,&var350,&vainSBool,&internal1_m2028_q0};
_S_rs  S_rs_2020_1 = {&var226,&var357,&var351,&vainSBool,&internal1_m2020_q0};
_S_and2  S_and2_2009_1 = {&var354,&var361,&var352};
_S_and2  S_and2_1997_1 = {&var354,&var358,&var353};
_S_noto  S_noto_1991_1 = {&var355,&var354};
_S_ovbs  S_ovbs_1990_1 = {&var182,&fRM_10_0,&var355,&internal1_m1990_tx};
_S_ovbs  S_ovbs_2001_1 = {&var333,&fRM_2_0,&var356,&internal1_m2001_tx};
_S_ovbs  S_ovbs_1987_1 = {&var339,&fRM_2_0,&var357,&internal1_m1987_tx};
_S_or2  S_or2_1996_1 = {&var389,&var966,&var358};
_S_or2  S_or2_1992_1 = {&var390,&var339,&var359};
_S_or2  S_or2_2004_1 = {&var390,&var333,&var360};
_S_or2  S_or2_2008_1 = {&var389,&var963,&var361};
_S_rs  S_rs_1993_1 = {&var353,&var359,&var362,&vainSBool,&internal1_m1993_q0};
_S_noto  S_noto_2006_1 = {&var364,&var363};
_S_rs  S_rs_2005_1 = {&var352,&var360,&var364,&vainSBool,&internal1_m2005_q0};
_S_noto  S_noto_1994_1 = {&var362,&var365};
_S_noto  S_noto_2002_1 = {&var356,&var366};
_S_noto  S_noto_1988_1 = {&var357,&var367};
_S_and2  S_and2_1981_1 = {&var370,&var472,&var368};
_S_and2  S_and2_1970_1 = {&var370,&var469,&var369};
_S_noto  S_noto_1964_1 = {&var371,&var370};
_S_ovbs  S_ovbs_1963_1 = {&var142,&fRM_3_0,&var371,&internal1_m1963_tx};
_S_or2  S_or2_1483_1 = {&var1136,&lRM_0_,&var372};
_S_and2  S_and2_439_1 = {&var1609,&var1551,&var373};
_S_and2  S_and2_1848_1 = {&var1161,&var1,&var374};
_S_and2  S_and2_450_1 = {&var912,&var758,&var375};
_S_and2  S_and2_446_1 = {&var759,&var912,&var376};
_S_and2  S_and2_479_1 = {&var758,&var913,&var377};
_S_and2  S_and2_475_1 = {&var759,&var913,&var378};
_S_or2  S_or2_366_1 = {&var1622,&var884,&var379};
_S_or2  S_or2_362_1 = {&var1622,&var883,&var380};
_S_ovbs  S_ovbs_57_1 = {&var1634,&fRM_15_0,&var381,&internal1_m57_tx};
_S_ovbs  S_ovbs_343_1 = {&var1109,&fRM_0_02,&var382,&internal1_m343_tx};
_S_ovbs  S_ovbs_298_1 = {&var1111,&fRM_0_02,&var383,&internal1_m298_tx};
_S_ovbs  S_ovbs_747_1 = {&var307,&fRM_0_2,&var384,&internal1_m747_tx};
_S_ovbs  S_ovbs_1427_1 = {&R0MD31LP1,&fRM_10_0,&var385,&internal1_m1427_tx};
_S_ovbs  S_ovbs_119_1 = {&R0MD31LP1,&fRM_0_15,&var386,&internal1_m119_tx};
_S_ovbs  S_ovbs_121_1 = {&var332,&fRM_0_02,&var387,&internal1_m121_tx};
_S_ovbs  S_ovbs_126_1 = {&R0MD32LP1,&fRM_0_02,&var388,&internal1_m126_tx};
_S_ovbs  S_ovbs_24_1 = {&var1187,&fRM_3_0,&var389,&internal1_m24_tx};
_S_ovbs  S_ovbs_16_1 = {&var961,&fRM_3_0,&var390,&internal1_m16_tx};
_S_ovbs  S_ovbs_1972_1 = {&var142,&fRM_2_0,&var391,&internal1_m1972_tx};
_S_ovbs  S_ovbs_1960_1 = {&var142,&fRM_2_0,&var392,&internal1_m1960_tx};
_S_ovbs  S_ovbs_2068_1 = {&var1196,&fRM_2_0,&var393,&internal1_m2068_tx};
_S_ovbs  S_ovbs_2072_1 = {&var104,&fRM_2_0,&var394,&internal1_m2072_tx};
_S_ovbs  S_ovbs_1885_1 = {&var407,&fRM_0_01,&var395,&internal1_m1885_tx};
_S_ovbs  S_ovbs_83_1 = {&R0MW13LP2,&fRM_10_0,&var396,&internal1_m83_tx};
_S_zpfs  S_zpfs_312_1 = {&var815,&fRM_10_0,&var397,&internal1_m312_tx,&internal1_m312_y0};
_S_or2  S_or2_1028_1 = {&var1022,&var585,&var398};
_S_or2  S_or2_240_1 = {&A1VN71LZ1,&A1VN71LZ2,&var399};
_S_or2  S_or2_255_1 = {&var710,&var978,&var400};
_S_or5  S_or5_155_1 = {&B1IS21LDU,&B3IS21LDU,&B2IS21LDU,&var948,&var949,&var401};
_S_and2  S_and2_1025_1 = {&var1459,&var1093,&var402};
_S_or3  S_or3_983_1 = {&var146,&var670,&var669,&var403};
_S_or3  S_or3_1395_1 = {&var653,&var652,&var147,&var404};
_S_and2  S_and2_964_1 = {&var1224,&var1007,&var405};
_S_and3  S_and3_1880_1 = {&var423,&var408,&var416,&var406};
_S_or2  S_or2_1884_1 = {&var410,&var409,&var407};
_S_or3  S_or3_1882_1 = {&var410,&var409,&var419,&var408};
_S_zpfs  S_zpfs_1879_1 = {&var412,&fEM_R0UL02RDU,&var409,&internal1_m1879_tx,&internal1_m1879_y0};
_S_zpfs  S_zpfs_1877_1 = {&var413,&fEM_R0UL02RDU,&var410,&internal1_m1877_tx,&internal1_m1877_y0};
_S_or2  S_or2_1871_1 = {&var413,&var412,&var411};
_S_or2  S_or2_1872_1 = {&var414,&var1126,&var412};
_S_or2  S_or2_1870_1 = {&var415,&var1126,&var413};
_S_and3  S_and3_1864_1 = {&var1183,&var935,&var913,&var414};
_S_and3  S_and3_1863_1 = {&var1184,&var912,&var935,&var415};
_S_or2  S_or2_1861_1 = {&var1126,&var1125,&var416};
_S_or3  S_or3_1868_1 = {&var421,&var1125,&var419,&var417};
_S_and2  S_and2_1876_1 = {&var1126,&var408,&var418};
_S_and2  S_and2_1867_1 = {&var1117,&var420,&var419};
_S_zpfs  S_zpfs_1866_1 = {&var1126,&fEM_R0UL04RDU,&var420,&internal1_m1866_tx,&internal1_m1866_y0};
_S_and2  S_and2_1854_1 = {&var1120,&var569,&var421};
_S_or3  S_or3_1855_1 = {&var1074,&var575,&var1052,&var422};
_S_abs_subf  S_abs_subf_1888_1 = {&fEM_R0UL02RDU,&var424,&fEM_R0UL16RDU,&vainSFloat,&var423};
_S_rsfn  S_rsfn_1886_1 = {&var566,&var425,&var424,&internal1_m1886_q0};
_S_lk  S_lk_1883_1 = {&var1279,&var408,&var425};
_S_abs_subf  S_abs_subf_1456_1 = {&fEM_R0UL05RDU,&var427,&fEM_R0UL18RDU,&vainSFloat,&var426};
_S_rsfn  S_rsfn_1447_1 = {&var566,&var428,&var427,&internal1_m1447_q0};
_S_lk  S_lk_1451_1 = {&var1131,&var553,&var428};
_S_abs_subf  S_abs_subf_1498_1 = {&fEM_R0UL07RDU,&var430,&fEM_R0UL20RDU,&vainSFloat,&var429};
_S_rsfn  S_rsfn_1485_1 = {&var566,&var431,&var430,&internal1_m1485_q0};
_S_lk  S_lk_1489_1 = {&var1137,&var543,&var431};
_S_ma  S_ma_1468_1 = {array_m1468_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_abs_subf  S_abs_subf_1503_1 = {&fEM_R0UL25RDU,&var433,&fEM_R0UL19RDU,&vainSFloat,&var432};
_S_rsfn  S_rsfn_1488_1 = {&var566,&var434,&var433,&internal1_m1488_q0};
_S_lk  S_lk_1492_1 = {&var1277,&var534,&var434};
_S_and3  S_and3_1930_1 = {&var436,&var439,&var446,&var435};
_S_abs_subf  S_abs_subf_1927_1 = {&var437,&fEM_R0UL03RDU,&fEM_R0UL17RDU,&vainSFloat,&var436};
_S_rsfn  S_rsfn_1925_1 = {&var566,&var438,&var437,&internal1_m1925_q0};
_S_lk  S_lk_1921_1 = {&var1278,&var439,&var438};
_S_or3  S_or3_1920_1 = {&var444,&var450,&var449,&var439};
_S_and4  S_and4_1924_1 = {&var449,&var1284,&var462,&var460,&var440};
_S_and4  S_and4_1922_1 = {&var450,&var1284,&var462,&var460,&var441};
_S_and2  S_and2_1914_1 = {&var1129,&var439,&var442};
_S_and2  S_and2_1900_1 = {&var569,&var1119,&var443};
_S_and2  S_and2_1904_1 = {&var447,&var1118,&var444};
_S_or3  S_or3_1905_1 = {&var444,&var443,&var1128,&var445};
_S_or2  S_or2_1896_1 = {&var1129,&var1128,&var446};
_S_zpfs  S_zpfs_1903_1 = {&var1129,&fEM_R0UL21RDU,&var447,&internal1_m1903_tx,&internal1_m1903_y0};
_S_or3  S_or3_1893_1 = {&var571,&var1078,&var1056,&var448};
_S_zpfs  S_zpfs_1918_1 = {&var452,&fEM_R0UL03RDU,&var449,&internal1_m1918_tx,&internal1_m1918_y0};
_S_zpfs  S_zpfs_1915_1 = {&var453,&fEM_R0UL03RDU,&var450,&internal1_m1915_tx,&internal1_m1915_y0};
_S_or2  S_or2_1911_1 = {&var453,&var452,&var451};
_S_or2  S_or2_1912_1 = {&var454,&var1129,&var452};
_S_or2  S_or2_1910_1 = {&var455,&var1129,&var453};
_S_and4  S_and4_1908_1 = {&var1185,&var913,&B2IS12LDU,&var456,&var454};
_S_and4  S_and4_1902_1 = {&var1186,&A2IS12LDU,&var912,&var456,&var455};
_S_and2  S_and2_1901_1 = {&var935,&var460,&var456};
_S_and3  S_and3_1939_1 = {&var913,&var1040,&var459,&var457};
_S_and3  S_and3_1938_1 = {&var912,&var1041,&var459,&var458};
_S_and4  S_and4_1937_1 = {&var1006,&var805,&var807,&var460,&var459};
_S_and2  S_and2_1931_1 = {&var818,&var1007,&var460};
_S_or2  S_or2_1933_1 = {&var1288,&var1005,&var461};
_S_or3  S_or3_1942_1 = {&var465,&var464,&var467,&var462};
_S_and2  S_and2_1932_1 = {&var1044,&A2IS12LDU,&var463};
_S_and2  S_and2_1936_1 = {&var945,&var463,&var464};
_S_and3  S_and3_1941_1 = {&var1283,&var468,&var463,&var465};
_S_or2  S_or2_1950_1 = {&lRM_0_,&var461,&var466};
_S_and2  S_and2_1947_1 = {&var960,&var468,&var467};
_S_and2  S_and2_1949_1 = {&var1043,&B2IS12LDU,&var468};
_S_or2  S_or2_1969_1 = {&var965,&var389,&var469};
_S_or2  S_or2_1965_1 = {&var390,&var142,&var470};
_S_or2  S_or2_1976_1 = {&var142,&var390,&var471};
_S_or2  S_or2_1980_1 = {&var389,&var964,&var472};
_S_or2  S_or2_2043_1 = {&var813,&var1197,&var473};
_S_or2  S_or2_2049_1 = {&var1007,&var1218,&var474};
_S_zpfs  S_zpfs_2051_1 = {&var73,&fRM_15_0,&var475,&internal1_m2051_tx,&internal1_m2051_y0};
_S_or2  S_or2_2055_1 = {&var812,&var105,&var476};
_S_zpfs  S_zpfs_2062_1 = {&var71,&fRM_15_0,&var477,&internal1_m2062_tx,&internal1_m2062_y0};
_S_or2  S_or2_2065_1 = {&var1007,&var1217,&var478};
_S_or2  S_or2_2081_1 = {&var77,&var440,&var479};
_S_or2  S_or2_2076_1 = {&var441,&var81,&var480};
_S_and2  S_and2_2087_1 = {&var1187,&var393,&var481};
_S_and2  S_and2_1847_1 = {&var1162,&var2,&var482};
_S_or3  S_or3_1819_1 = {&var487,&var491,&var489,&var483};
_S_or3  S_or3_1820_1 = {&var490,&var489,&var486,&var484};
_S_or2  S_or2_1833_1 = {&B0VT71LZ1,&B0VT71LZ2,&var485};
_S_and2  S_and2_1824_1 = {&var492,&var485,&var486};
_S_and2  S_and2_1818_1 = {&var492,&var488,&var487};
_S_or2  S_or2_1817_1 = {&A0VT71LZ1,&A0VT71LZ2,&var488};
_S_zpfs  S_zpfs_1814_1 = {&var1179,&fRM_2_5,&var489,&internal1_m1814_tx,&internal1_m1814_y0};
_S_zpfs  S_zpfs_1813_1 = {&var1180,&fRM_2_5,&var490,&internal1_m1813_tx,&internal1_m1813_y0};
_S_zpfs  S_zpfs_1812_1 = {&var1181,&fRM_2_5,&var491,&internal1_m1812_tx,&internal1_m1812_y0};
_S_zpfs  S_zpfs_1811_1 = {&var1182,&fRM_2_5,&var492,&internal1_m1811_tx,&internal1_m1811_y0};
_S_or2  S_or2_1842_1 = {&R0VP73LZ2,&R0VP73LZ1,&var493};
_S_and2  S_and2_1837_1 = {&var104,&var1163,&var494};
_S_or2  S_or2_1832_1 = {&var497,&var494,&var495};
_S_or2  S_or2_1834_1 = {&var77,&var104,&var496};
_S_and2  S_and2_1831_1 = {&var77,&var1153,&var497};
_S_and2  S_and2_1815_1 = {&var1196,&var1164,&var498};
_S_or2  S_or2_1816_1 = {&var501,&var498,&var499};
_S_or2  S_or2_1809_1 = {&var81,&var1196,&var500};
_S_and2  S_and2_1808_1 = {&var81,&var1154,&var501};
_S_or3  S_or3_1778_1 = {&var1247,&var1205,&var1206,&var502};
_S_or3  S_or3_1779_1 = {&var1245,&var1205,&var1206,&var503};
_S_or2  S_or2_1770_1 = {&var1240,&var1205,&var504};
_S_or2  S_or2_1771_1 = {&var1239,&var1205,&var505};
_S_or2  S_or2_1777_1 = {&var1249,&var1208,&var506};
_S_or4  S_or4_1775_1 = {&var1208,&var1246,&var1209,&var1210,&var507};
_S_or4  S_or4_1774_1 = {&var1208,&var1252,&var1209,&var1210,&var508};
_S_or2  S_or2_1768_1 = {&var1241,&var1210,&var509};
_S_or2  S_or2_1767_1 = {&var1242,&var1210,&var510};
_S_or2  S_or2_1776_1 = {&var1208,&var1248,&var511};
_S_or2  S_or2_1745_1 = {&var257,&var303,&var512};
_S_and2  S_and2_1576_1 = {&var1502,&var1460,&var513};
_S_and2  S_and2_1575_1 = {&var1625,&var1460,&var514};
_S_and2  S_and2_1574_1 = {&var902,&var1460,&var515};
_S_or2  S_or2_1573_1 = {&B4IS11LDU,&A4IS11LDU,&var516};
_S_and2  S_and2_1572_1 = {&var516,&var1460,&var517};
_S_and2  S_and2_1566_1 = {&var1668,&var1460,&var518};
_S_and2  S_and2_1565_1 = {&var155,&var1460,&var519};
_S_and2  S_and2_1564_1 = {&var891,&var1460,&var520};
_S_and2  S_and2_1563_1 = {&R3IS21LDU,&var1460,&var521};
_S_or2  S_or2_1623_1 = {&var1638,&var1639,&var522};
_S_or2  S_or2_1622_1 = {&var1640,&var1638,&var523};
_S_or2  S_or2_2101_1 = {&var984,&R0MD34LP1,&var524};
_S_or3  S_or3_2107_1 = {&var1259,&var1261,&var1260,&var525};
_S_or3  S_or3_2098_1 = {&var1265,&var1267,&var1266,&var526};
_S_or2  S_or2_1611_1 = {&var1726,&var1460,&var527};
_S_or2  S_or2_1585_1 = {&var1503,&var1093,&var528};
_S_or5  S_or5_1122_1 = {&var1518,&var530,&var1529,&var1515,&var1516,&var529};
_S_or3  S_or3_1126_1 = {&var1523,&var1524,&var987,&var530};
_S_or5  S_or5_1599_1 = {&var309,&var532,&var1512,&var1504,&var1505,&var531};
_S_or3  S_or3_1602_1 = {&var986,&var1506,&var1507,&var532};
_S_and3  S_and3_1513_1 = {&var534,&var539,&var432,&var533};
_S_and2  S_and2_1515_1 = {&var535,&var1276,&var534};
_S_or3  S_or3_1514_1 = {&A3VZ13LZ2,&A3VZ13LZ1,&var538,&var535};
_S_zpfs  S_zpfs_1499_1 = {&var1276,&fRM_0_2,&var536,&internal1_m1499_tx,&internal1_m1499_y0};
_S_or3  S_or3_1501_1 = {&var1139,&var538,&var540,&var537};
_S_and2  S_and2_1500_1 = {&var1116,&var536,&var538};
_S_or2  S_or2_1490_1 = {&var1276,&var1139,&var539};
_S_and2  S_and2_1478_1 = {&var1121,&var569,&var540};
_S_or3  S_or3_1486_1 = {&var1053,&var1075,&var574,&var541};
_S_or3  S_or3_1509_1 = {&R0AD14LZ1,&R0AD14LZ2,&var545,&var542};
_S_and2  S_and2_1510_1 = {&var542,&var1136,&var543};
_S_zpfs  S_zpfs_1493_1 = {&var1136,&fEM_R0UL06RDU,&var544,&internal1_m1493_tx,&internal1_m1493_y0};
_S_and2  S_and2_1494_1 = {&var544,&var1115,&var545};
_S_or3  S_or3_1495_1 = {&var1134,&var545,&var548,&var546};
_S_or3  S_or3_1470_1 = {&var573,&var1076,&var1054,&var547};
_S_and2  S_and2_1473_1 = {&var1122,&var569,&var548};
_S_and3  S_and3_1512_1 = {&var429,&var543,&var556,&var549};
_S_zpfs  S_zpfs_1443_1 = {&var1133,&fEM_R0UL04RDU,&var550,&internal1_m1443_tx,&internal1_m1443_y0};
_S_and2  S_and2_1444_1 = {&var550,&var1114,&var551};
_S_and3  S_and3_1460_1 = {&var426,&var553,&var557,&var552};
_S_and2  S_and2_1454_1 = {&var554,&var1133,&var553};
_S_or3  S_or3_1453_1 = {&A3VZ15LZ1,&A3VZ15LZ2,&var551,&var554};
_S_or3  S_or3_1445_1 = {&var558,&var551,&var1132,&var555};
_S_or2  S_or2_1481_1 = {&var1136,&var1134,&var556};
_S_or2  S_or2_1441_1 = {&var1133,&var1132,&var557};
_S_and2  S_and2_1433_1 = {&var1123,&var569,&var558};
_S_or3  S_or3_1431_1 = {&var1055,&var1077,&var572,&var559};
_S_or2  S_or2_1405_1 = {&var1631,&var561,&var560};
_S_and2  S_and2_1404_1 = {&var562,&var1177,&var561};
_S_or2  S_or2_1403_1 = {&var958,&var910,&var562};
_S_or2  S_or2_1400_1 = {&var1048,&var1070,&var563};
_S_and2  S_and2_1398_1 = {&var1142,&var1143,&var564};
_S_and2  S_and2_1401_1 = {&var563,&var562,&var565};
_S_or5  S_or5_1402_1 = {&var383,&var382,&var564,&var565,&R0MD34LP1,&var566};
_S_orni  S_orni_1422_1 = {array_m1422_x_1,&iRM_5_,&var567,&var568};
_S_or5  S_or5_1424_1 = {&var1138,&var1113,&var566,&var1058,&var385,&var569};
_S_and2  S_and2_1423_1 = {&var567,&var1271,&var570};
_S_or2  S_or2_1430_1 = {&var1085,&var576,&var571};
_S_or2  S_or2_1426_1 = {&var1084,&var577,&var572};
_S_or2  S_or2_1420_1 = {&var1083,&var578,&var573};
_S_or2  S_or2_1418_1 = {&var1082,&var579,&var574};
_S_or2  S_or2_1416_1 = {&var1081,&var580,&var575};
_S_and2  S_and2_1429_1 = {&var1626,&var581,&var576};
_S_and2  S_and2_1425_1 = {&var1627,&var581,&var577};
_S_and2  S_and2_1419_1 = {&var1628,&var581,&var578};
_S_and2  S_and2_1417_1 = {&var1629,&var581,&var579};
_S_and2  S_and2_1415_1 = {&var1630,&var581,&var580};
_S_and2  S_and2_1409_1 = {&var1631,&var64,&var581};
_S_and3  S_and3_1058_1 = {&var251,&var586,&var604,&var582};
_S_or2  S_or2_1022_1 = {&var1095,&var1091,&var583};
_S_or2  S_or2_1049_1 = {&var1091,&var1025,&var584};
_S_and2  S_and2_1016_1 = {&var1469,&var1092,&var585};
_S_and2  S_and2_1012_1 = {&var1288,&var606,&var586};
_S_or3  S_or3_1019_1 = {&var1091,&var1021,&var1094,&var587};
_S_and2  S_and2_1023_1 = {&var248,&var1288,&var588};
_S_and2  S_and2_1042_1 = {&var259,&var1288,&var589};
_S_and2  S_and2_1057_1 = {&var253,&var1288,&var590};
_S_and2  S_and2_1064_1 = {&var256,&var1288,&var591};
_S_and3  S_and3_1007_1 = {&var594,&var1010,&var1288,&var592};
_S_and3  S_and3_1001_1 = {&var595,&var1010,&var1288,&var593};
_S_and2  S_and2_1009_1 = {&var912,&var1287,&var594};
_S_and2  S_and2_999_1 = {&var913,&var1287,&var595};
_S_and4  S_and4_1008_1 = {&var594,&var1288,&var1018,&var1008,&var596};
_S_and4  S_and4_1002_1 = {&var595,&var1288,&var1018,&var1008,&var597};
_S_and4  S_and4_1006_1 = {&var1288,&var594,&var602,&var1009,&var598};
_S_and4  S_and4_1000_1 = {&var1288,&var595,&var602,&var1009,&var599};
_S_and2  S_and2_993_1 = {&var1019,&var1288,&var600};
_S_or4  S_or4_996_1 = {&R0MD31LP1,&var1522,&var264,&var613,&var601};
_S_and3  S_and3_1043_1 = {&var1020,&var1019,&var1018,&var602};
_S_and2  S_and2_1029_1 = {&var604,&var398,&var603};
_S_and2  S_and2_1038_1 = {&var1017,&var602,&var604};
_S_or2  S_or2_1044_1 = {&var1087,&var1029,&var605};
_S_and2  S_and2_1051_1 = {&var607,&var605,&var606};
_S_or2  S_or2_1045_1 = {&var1028,&var1030,&var607};
_S_or2  S_or2_1046_1 = {&var1027,&var1028,&var608};
_S_or2  S_or2_1047_1 = {&var1026,&var1031,&var609};
_S_and2  S_and2_1048_1 = {&var608,&var609,&var610};
_S_or2  S_or2_1034_1 = {&var1087,&var1086,&var611};
_S_and2  S_and2_1035_1 = {&var611,&var1023,&var612};
_S_and5  S_and5_989_1 = {&var614,&var1107,&var1028,&var1087,&var603,&var613};
_S_and2  S_and2_990_1 = {&var1062,&var1063,&var614};
_S_and2  S_and2_1252_1 = {&var1156,&var616,&var615};
_S_or2  S_or2_1247_1 = {&A2MD12LP1,&var617,&var616};
_S_and2  S_and2_1237_1 = {&A2MD11LP1,&var1173,&var617};
_S_or2  S_or2_1228_1 = {&var620,&B2MD12LP1,&var618};
_S_and2  S_and2_1230_1 = {&var618,&var1156,&var619};
_S_and2  S_and2_1222_1 = {&B2MD11LP1,&var1174,&var620};
_S_or3  S_or3_1210_1 = {&var1238,&var1233,&var776,&var621};
_S_or5  S_or5_1226_1 = {&var624,&var996,&var1499,&var1493,&var1494,&var622};
_S_or2  S_or2_1245_1 = {&var1738,&var1484,&var623};
_S_or3  S_or3_1297_1 = {&var1465,&var625,&var626,&var624};
_S_and2  S_and2_1292_1 = {&var1484,&var959,&var625};
_S_and2  S_and2_1291_1 = {&var909,&var1484,&var626};
_S_and3  S_and3_1290_1 = {&var401,&var945,&var641,&var627};
_S_and2  S_and2_1289_1 = {&var155,&var641,&var628};
_S_and3  S_and3_1285_1 = {&var934,&var980,&var641,&var629};
_S_and2  S_and2_1284_1 = {&var493,&var641,&var630};
_S_and2  S_and2_1272_1 = {&var1475,&var641,&var631};
_S_and2  S_and2_1259_1 = {&var1668,&var641,&var632};
_S_and2  S_and2_1274_1 = {&var62,&var641,&var633};
_S_and2  S_and2_1260_1 = {&R3IS21LDU,&var641,&var634};
_S_and2  S_and2_1275_1 = {&var637,&var641,&var635};
_S_and3  S_and3_1261_1 = {&var638,&var1474,&var641,&var636};
_S_or2  S_or2_1276_1 = {&var1467,&var1468,&var637};
_S_or2  S_or2_1263_1 = {&A4IS11LDU,&B4IS11LDU,&var638};
_S_and3  S_and3_1271_1 = {&var1208,&var265,&var961,&var639};
_S_and3  S_and3_1270_1 = {&var1210,&var265,&var961,&var640};
_S_or3  S_or3_1262_1 = {&var1485,&var640,&var639,&var641};
_S_and2  S_and2_1346_1 = {&var643,&var1156,&var642};
_S_or2  S_or2_1345_1 = {&var644,&B3MD12LP1,&var643};
_S_and2  S_and2_1334_1 = {&B3MD11LP1,&var1152,&var644};
_S_or2  S_or2_1337_1 = {&var1729,&var1302,&var645};
_S_or5  S_or5_1323_1 = {&var404,&var1312,&var1311,&var176,&var994,&var646};
_S_and2  S_and2_1383_1 = {&var1302,&var959,&var647};
_S_and2  S_and2_1382_1 = {&var1302,&var909,&var648};
_S_and2  S_and2_1391_1 = {&var975,&var1290,&var649};
_S_or2  S_or2_1386_1 = {&var649,&var976,&var650};
_S_and3  S_and3_1381_1 = {&var1165,&var650,&var659,&var651};
_S_and3  S_and3_1380_1 = {&var401,&var960,&var659,&var652};
_S_and2  S_and2_1379_1 = {&var155,&var659,&var653};
_S_and2  S_and2_1376_1 = {&var1222,&var1007,&var654};
_S_or2  S_or2_1366_1 = {&var1293,&var1292,&var655};
_S_and2  S_and2_1365_1 = {&var655,&var659,&var656};
_S_and2  S_and2_1364_1 = {&var62,&var659,&var657};
_S_and2  S_and2_1362_1 = {&var1295,&var659,&var658};
_S_or2  S_or2_1355_1 = {&var1304,&var85,&var659};
_S_or2  S_or2_1353_1 = {&B4IS11LDU,&A4IS11LDU,&var660};
_S_and3  S_and3_1352_1 = {&var1294,&var660,&var659,&var661};
_S_and2  S_and2_1351_1 = {&R3IS21LDU,&var659,&var662};
_S_and2  S_and2_1350_1 = {&var1668,&var659,&var663};
_S_and2  S_and2_979_1 = {&var973,&var1322,&var664};
_S_and2  S_and2_970_1 = {&var909,&var1334,&var665};
_S_and2  S_and2_971_1 = {&var959,&var1334,&var666};
_S_or2  S_or2_974_1 = {&var974,&var664,&var667};
_S_and3  S_and3_969_1 = {&var1165,&var667,&var674,&var668};
_S_and3  S_and3_968_1 = {&var945,&var401,&var674,&var669};
_S_and2  S_and2_967_1 = {&var155,&var674,&var670};
_S_and2  S_and2_950_1 = {&var1327,&var674,&var671};
_S_or2  S_or2_954_1 = {&var1325,&var1324,&var672};
_S_and2  S_and2_953_1 = {&var672,&var674,&var673};
_S_or2  S_or2_941_1 = {&var1336,&var86,&var674};
_S_or2  S_or2_942_1 = {&B4IS11LDU,&A4IS11LDU,&var675};
_S_and3  S_and3_940_1 = {&var675,&var1326,&var674,&var676};
_S_and2  S_and2_952_1 = {&var62,&var674,&var677};
_S_and2  S_and2_939_1 = {&R3IS21LDU,&var674,&var678};
_S_and2  S_and2_938_1 = {&var1668,&var674,&var679};
_S_or2  S_or2_925_1 = {&var1334,&var1732,&var680};
_S_or5  S_or5_908_1 = {&var403,&var995,&var174,&var1343,&var1344,&var681};
_S_and2  S_and2_935_1 = {&var1156,&var683,&var682};
_S_or2  S_or2_933_1 = {&var684,&A3MD12LP1,&var683};
_S_and2  S_and2_922_1 = {&A3MD11LP1,&var1207,&var684};
_S_or3  S_or3_880_1 = {&var1432,&var687,&var686,&var685};
_S_and2  S_and2_874_1 = {&var1443,&var909,&var686};
_S_and2  S_and2_875_1 = {&var1443,&var959,&var687};
_S_and3  S_and3_873_1 = {&var1466,&var960,&var699,&var688};
_S_and2  S_and2_872_1 = {&var155,&var699,&var689};
_S_and2  S_and2_855_1 = {&var1436,&var699,&var690};
_S_and2  S_and2_857_1 = {&var62,&var699,&var691};
_S_and2  S_and2_858_1 = {&var693,&var699,&var692};
_S_or2  S_or2_859_1 = {&var1434,&var1433,&var693};
_S_and2  S_and2_842_1 = {&var1668,&var699,&var694};
_S_and3  S_and3_844_1 = {&var1435,&var700,&var699,&var695};
_S_and2  S_and2_843_1 = {&R3IS21LDU,&var699,&var696};
_S_and3  S_and3_854_1 = {&var1208,&var265,&var961,&var697};
_S_and3  S_and3_853_1 = {&var265,&var1210,&var961,&var698};
_S_or3  S_or3_847_1 = {&var1444,&var697,&var698,&var699};
_S_or2  S_or2_845_1 = {&B4IS11LDU,&A4IS11LDU,&var700};
_S_or2  S_or2_832_1 = {&var1735,&var1443,&var701};
_S_zpfs  S_zpfs_830_1 = {&var1457,&fRM_3_0,&var702,&internal1_m830_tx,&internal1_m830_y0};
_S_zpfs  S_zpfs_827_1 = {&var1458,&fRM_2_0,&var703,&internal1_m827_tx,&internal1_m827_y0};
_S_zpfs  S_zpfs_834_1 = {&var1455,&fEM_A2UL83RDU,&var704,&internal1_m834_tx,&internal1_m834_y0};
_S_or5  S_or5_822_1 = {&var685,&var704,&var1456,&var703,&var702,&var705};
_S_or3  S_or3_808_1 = {&var1213,&var1236,&var771,&var706};
_S_or4  S_or4_795_1 = {&var1579,&var1577,&var1578,&var1580,&var707};
_S_or2  S_or2_786_1 = {&var709,&var707,&var708};
_S_or4  S_or4_779_1 = {&var1588,&var1587,&var1586,&var1589,&var709};
_S_and2  S_and2_260_1 = {&var977,&var1382,&var710};
_S_and3  S_and3_249_1 = {&var945,&var401,&var1397,&var711};
_S_or3  S_or3_262_1 = {&var715,&var713,&var1385,&var712};
_S_and2  S_and2_252_1 = {&var1396,&var959,&var713};
_S_and3  S_and3_250_1 = {&var400,&var1165,&var1397,&var714};
_S_and2  S_and2_251_1 = {&var909,&var1396,&var715};
_S_and2  S_and2_248_1 = {&var155,&var1397,&var716};
_S_and2  S_and2_223_1 = {&var1389,&var1397,&var717};
_S_and2  S_and2_225_1 = {&var62,&var1397,&var718};
_S_or2  S_or2_227_1 = {&var1386,&var1387,&var719};
_S_and2  S_and2_226_1 = {&var719,&var1397,&var720};
_S_or2  S_or2_216_1 = {&B4IS11LDU,&A4IS11LDU,&var721};
_S_and3  S_and3_215_1 = {&var1388,&var721,&var1397,&var722};
_S_and2  S_and2_213_1 = {&var1668,&var1397,&var723};
_S_and2  S_and2_214_1 = {&R3IS21LDU,&var1397,&var724};
_S_and2  S_and2_190_1 = {&var1156,&var727,&var725};
_S_and2  S_and2_182_1 = {&A1MD11LP1,&var1195,&var726};
_S_or2  S_or2_188_1 = {&A1MD12LP1,&var726,&var727};
_S_or2  S_or2_202_1 = {&var1396,&var1720,&var728};
_S_zpfs  S_zpfs_193_1 = {&var1411,&fRM_2_0,&var729,&internal1_m193_tx,&internal1_m193_y0};
_S_zpfs  S_zpfs_198_1 = {&var1410,&fRM_2_0,&var730,&internal1_m198_tx,&internal1_m198_y0};
_S_zpfs  S_zpfs_204_1 = {&var1408,&fEM_A1UL03RDU,&var731,&internal1_m204_tx,&internal1_m204_y0};
_S_or5  S_or5_186_1 = {&var712,&var731,&var730,&var729,&var1409,&var732};
_S_orn  S_orn_551_1 = {array_m551_x_1,&iRM_14_,&var733};
_S_and2  S_and2_574_1 = {&var1352,&var972,&var734};
_S_or2  S_or2_569_1 = {&var971,&var734,&var735};
_S_and3  S_and3_563_1 = {&var960,&var1466,&var1364,&var736};
_S_and2  S_and2_562_1 = {&var155,&var1364,&var737};
_S_and3  S_and3_564_1 = {&var1165,&var1364,&var735,&var738};
_S_or2  S_or2_544_1 = {&var1354,&var1353,&var739};
_S_and2  S_and2_543_1 = {&var739,&var1364,&var740};
_S_and2  S_and2_542_1 = {&var1364,&var62,&var741};
_S_and3  S_and3_532_1 = {&var1355,&var743,&var1364,&var742};
_S_or2  S_or2_533_1 = {&B4IS11LDU,&A4IS11LDU,&var743};
_S_and2  S_and2_540_1 = {&var1364,&var1356,&var744};
_S_or2  S_or2_510_1 = {&B1MD12LP1,&var747,&var745};
_S_and2  S_and2_514_1 = {&var1156,&var745,&var746};
_S_and2  S_and2_505_1 = {&B1MD11LP1,&var1175,&var747};
_S_and2  S_and2_531_1 = {&var1364,&R3IS21LDU,&var748};
_S_and2  S_and2_530_1 = {&var1364,&var1668,&var749};
_S_or2  S_or2_521_1 = {&var1363,&var1742,&var750};
_S_zpfs  S_zpfs_523_1 = {&var1377,&fEM_A1UL03RDU,&var751,&internal1_m523_tx,&internal1_m523_y0};
_S_or5  S_or5_506_1 = {&var905,&var751,&var1378,&var1372,&var1373,&var752};
_S_or2  S_or2_494_1 = {&var1191,&var772,&var753};
_S_or3  S_or3_484_1 = {&var593,&var1190,&var1002,&var754};
_S_or4  S_or4_474_1 = {&var1416,&var1414,&var1416,&var1415,&var755};
_S_or4  S_or4_456_1 = {&var1425,&var1423,&var1424,&var1426,&var756};
_S_or2  S_or2_463_1 = {&var756,&var755,&var757};
_S_and3  S_and3_447_1 = {&var760,&var1156,&R0MD33LP1,&var758};
_S_and3  S_and3_448_1 = {&var1156,&var761,&R0MD33LP1,&var759};
_S_or3  S_or3_440_1 = {&var295,&var1011,&var998,&var760};
_S_or2  S_or2_441_1 = {&var1412,&var1189,&var761};
_S_or2  S_or2_749_1 = {&var1547,&var1548,&var762};
_S_and2  S_and2_333_1 = {&var1047,&var1109,&var763};
_S_or2  S_or2_352_1 = {&B4IS21LDU,&A4IS21LDU,&var764};
_S_or2  S_or2_347_1 = {&A2IS21LDU,&B2IS21LDU,&var765};
_S_or2  S_or2_342_1 = {&var768,&var1051,&var766};
_S_and3  S_and3_340_1 = {&var1110,&var1105,&var1106,&var767};
_S_or4  S_or4_338_1 = {&var1036,&var205,&R0MD31LP1,&var1046,&var768};
_S_and4  S_and4_334_1 = {&var958,&var826,&var264,&var916,&var769};
_S_or2  S_or2_329_1 = {&R0MD34LP1,&var1046,&var770};
_S_and3  S_and3_603_1 = {&var793,&var1289,&B2IS12LDU,&var771};
_S_and2  S_and2_602_1 = {&var793,&var1321,&var772};
_S_and2  S_and2_601_1 = {&var793,&var1384,&var773};
_S_or2  S_or2_645_1 = {&A2IS12LDU,&B2IS12LDU,&var774};
_S_or2  S_or2_622_1 = {&var1519,&var1145,&var775};
_S_and3  S_and3_613_1 = {&A2IS12LDU,&var1289,&var794,&var776};
_S_and2  S_and2_644_1 = {&var778,&var1289,&var777};
_S_or2  S_or2_646_1 = {&var1088,&var248,&var778};
_S_or2  S_or2_627_1 = {&var1519,&var1144,&var779};
_S_or2  S_or2_625_1 = {&var781,&var1519,&var780};
_S_and2  S_and2_637_1 = {&var1321,&var259,&var781};
_S_and2  S_and2_612_1 = {&var794,&var1321,&var782};
_S_and2  S_and2_611_1 = {&var794,&var1384,&var783};
_S_and2  S_and2_636_1 = {&var253,&var1384,&var784};
_S_and2  S_and2_652_1 = {&var256,&var1412,&var785};
_S_or2  S_or2_648_1 = {&var1519,&var1146,&var786};
_S_or2  S_or2_643_1 = {&var788,&var785,&var787};
_S_and2  S_and2_635_1 = {&var796,&var1381,&var788};
_S_and2  S_and2_641_1 = {&var796,&R0MD33LP1,&var789};
_S_or2  S_or2_591_1 = {&var969,&var970,&var790};
_S_and4  S_and4_610_1 = {&var969,&var794,&var1481,&A2IS12LDU,&var791};
_S_and4  S_and4_600_1 = {&var793,&var970,&var1481,&B2IS12LDU,&var792};
_S_and2  S_and2_599_1 = {&var913,&var1479,&var793};
_S_and2  S_and2_609_1 = {&var912,&var1479,&var794};
_S_or2  S_or2_640_1 = {&var1089,&var248,&var795};
_S_and2  S_and2_633_1 = {&var795,&var1481,&var796};
_S_or2  S_or2_620_1 = {&var1519,&var1147,&var797};
_S_or2  S_or2_632_1 = {&var1459,&var1102,&var798};
_S_and2  S_and2_631_1 = {&var798,&var1503,&var799};
_S_or2  S_or2_617_1 = {&var1519,&var1148,&var800};
_S_and2  S_and2_630_1 = {&var1520,&var1469,&var801};
_S_or2  S_or2_615_1 = {&var1519,&var1149,&var802};
_S_and2  S_and2_628_1 = {&var251,&var1522,&var803};
_S_or2  S_or2_607_1 = {&var1157,&var1519,&var804};
_S_and2  S_and2_308_1 = {&var1219,&var807,&var805};
_S_and2  S_and2_296_1 = {&var807,&var1034,&var806};
_S_or2  S_or2_291_1 = {&var1048,&var1070,&var807};
_S_and3  S_and3_287_1 = {&var1285,&var1105,&var1106,&var808};
_S_and3  S_and3_302_1 = {&var765,&var1035,&var810,&var809};
_S_or2  S_or2_292_1 = {&var1285,&var1110,&var810};
_S_and2  S_and2_301_1 = {&var764,&var810,&var811};
_S_and2  S_and2_321_1 = {&var816,&var913,&var812};
_S_and2  S_and2_322_1 = {&var912,&var816,&var813};
_S_and2  S_and2_327_1 = {&var1007,&var805,&var814};
_S_and2  S_and2_315_1 = {&var816,&var1007,&var815};
_S_and2  S_and2_320_1 = {&var1187,&var817,&var816};
_S_or2  S_or2_316_1 = {&var818,&var763,&var817};
_S_or2  S_or2_317_1 = {&var819,&var763,&var818};
_S_and4  S_and4_318_1 = {&var1111,&var1059,&var1060,&var910,&var819};
_S_or2  S_or2_304_1 = {&var1111,&var1109,&var820};
_S_and2  S_and2_289_1 = {&var1073,&var1042,&var821};
_S_or2  S_or2_295_1 = {&var824,&var821,&var822};
_S_or2  S_or2_269_1 = {&R0MD34LP1,&var1045,&var823};
_S_or4  S_or4_286_1 = {&var1036,&R0MD31LP1,&var205,&var1045,&var824};
_S_and3  S_and3_279_1 = {&var826,&var915,&var264,&var825};
_S_or2  S_or2_278_1 = {&var1064,&var1250,&var826};
_S_and3  S_and3_283_1 = {&var1065,&var1067,&var1066,&var827};
_S_or2  S_or2_271_1 = {&var829,&var827,&var828};
_S_and3  S_and3_265_1 = {&R0MD33LP1,&var1069,&var1068,&var829};
_S_or2  S_or2_1094_1 = {&B4IS11LDU,&A4IS11LDU,&var830};
_S_and2  S_and2_1097_1 = {&var1470,&var1517,&var831};
_S_and2  S_and2_1096_1 = {&var1470,&var1625,&var832};
_S_and2  S_and2_1095_1 = {&var1470,&var902,&var833};
_S_and2  S_and2_1093_1 = {&var1470,&var830,&var834};
_S_and2  S_and2_1087_1 = {&var1470,&var155,&var835};
_S_and2  S_and2_1086_1 = {&var891,&var1470,&var836};
_S_and2  S_and2_1085_1 = {&var1470,&R3IS21LDU,&var837};
_S_and2  S_and2_1088_1 = {&var1470,&var1668,&var838};
_S_and2  S_and2_1080_1 = {&var248,&var1004,&var839};
_S_and2  S_and2_1081_1 = {&var259,&var1002,&var840};
_S_and2  S_and2_1082_1 = {&var253,&var1000,&var841};
_S_and2  S_and2_1083_1 = {&var256,&var998,&var842};
_S_or2  S_or2_1065_1 = {&R0MD31LP1,&var844,&var843};
_S_and4  S_and4_1066_1 = {&var160,&var159,&var158,&var157,&var844};
_S_or2  S_or2_1136_1 = {&var1470,&var1723,&var845};
_S_or2  S_or2_1112_1 = {&var1520,&var1092,&var846};
_S_or2  S_or2_1192_1 = {&var1561,&var1560,&var847};
_S_or2  S_or2_1178_1 = {&var1570,&var1569,&var848};
_S_or2  S_or2_1189_1 = {&var985,&R0MD34LP1,&var849};
_S_or2  S_or2_1159_1 = {&var847,&var1625,&var850};
_S_or2  S_or2_1155_1 = {&var852,&var850,&var851};
_S_or2  S_or2_1158_1 = {&var848,&var1625,&var852};
_S_or4  S_or4_364_1 = {&var1597,&var1596,&var1598,&var1595,&var853};
_S_or2  S_or2_665_1 = {&B5IS11LDU,&A5IS11LDU,&var854};
_S_and2  S_and2_664_1 = {&var859,&var854,&var855};
_S_or2  S_or2_663_1 = {&B6IS11LDU,&A6IS11LDU,&var856};
_S_and2  S_and2_662_1 = {&var859,&var856,&var857};
_S_or2  S_or2_661_1 = {&A4IS11LDU,&B4IS11LDU,&var858};
_S_or2  S_or2_654_1 = {&var861,&var862,&var859};
_S_and2  S_and2_660_1 = {&var859,&var858,&var860};
_S_and2  S_and2_656_1 = {&var155,&var872,&var861};
_S_and2  S_and2_653_1 = {&var156,&var865,&var862};
_S_and2  S_and2_769_1 = {&var1623,&var1541,&var863};
_S_and2  S_and2_765_1 = {&var1623,&var1542,&var864};
_S_and3  S_and3_760_1 = {&var1623,&var156,&var1548,&var865};
_S_or2  S_or2_768_1 = {&var1543,&var1537,&var866};
_S_or2  S_or2_763_1 = {&var1541,&var1543,&var867};
_S_or2  S_or2_759_1 = {&var1543,&var1542,&var868};
_S_and2  S_and2_741_1 = {&var1537,&var1623,&var869};
_S_or2  S_or2_732_1 = {&var1544,&var1545,&var870};
_S_or2  S_or2_727_1 = {&var1602,&var1544,&var871};
_S_and2  S_and2_725_1 = {&var1545,&var1624,&var872};
_S_and2  S_and2_724_1 = {&var1602,&var1624,&var873};
_S_and2  S_and2_753_1 = {&var251,&var1623,&var874};
_S_and2  S_and2_734_1 = {&var251,&var1554,&var875};
_S_and2  S_and2_751_1 = {&var1624,&var251,&var876};
_S_or2  S_or2_745_1 = {&var1624,&var1623,&var877};
_S_or3  S_or3_738_1 = {&var66,&var880,&var881,&var878};
_S_or4  S_or4_737_1 = {&var880,&var65,&var882,&var1533,&var879};
_S_or3  S_or3_726_1 = {&R4MD31LP2,&var869,&var873,&var880};
_S_or2  S_or2_757_1 = {&var1622,&var884,&var881};
_S_or2  S_or2_756_1 = {&var1622,&var883,&var882};
_S_and2  S_and2_671_1 = {&var66,&var1536,&var883};
_S_and3  S_and3_704_1 = {&var1535,&var1549,&var65,&var884};
_S_and2  S_and2_709_1 = {&R5IS11LDU,&var899,&var885};
_S_and3  S_and3_707_1 = {&var1187,&R3IS21LDU,&var899,&var886};
_S_and2  S_and2_708_1 = {&R6IS21LDU,&var899,&var887};
_S_or2  S_or2_706_1 = {&B8IS22LDU,&A8IS22LDU,&var888};
_S_and2  S_and2_705_1 = {&var888,&var899,&var889};
_S_and2  S_and2_692_1 = {&var899,&var891,&var890};
_S_or4  S_or4_693_1 = {&A0VN71LZ1,&B0VN71LZ1,&B0VN71LZ2,&A0VN71LZ2,&var891};
_S_and2  S_and2_690_1 = {&var896,&var899,&var892};
_S_and2  S_and2_681_1 = {&var902,&var899,&var893};
_S_and2  S_and2_680_1 = {&var1625,&var899,&var894};
_S_or3  S_or3_679_1 = {&R0NE01LDU,&R0NE02LDU,&R0NE08LDU,&var895};
_S_or2  S_or2_691_1 = {&R1IS21LDU,&R2IS21LDU,&var896};
_S_and2  S_and2_678_1 = {&var899,&var895,&var897};
_S_and2  S_and2_676_1 = {&var1603,&var899,&var898};
_S_or2  S_or2_667_1 = {&var1624,&var1623,&var899};
_S_or2  S_or2_172_1 = {&var1193,&var782,&var900};
_S_or3  S_or3_162_1 = {&var592,&var1192,&var1002,&var901};
_S_or2  S_or2_154_1 = {&var1466,&var401,&var902};
_S_or3  S_or3_114_1 = {&var1155,&var387,&var388,&var903};
_S_or2  S_or2_2022_1 = {&var349,&var226,&var904};
_S_or3  S_or3_576_1 = {&var906,&var907,&var733,&var905};
_S_and2  S_and2_565_1 = {&var1363,&var909,&var906};
_S_and2  S_and2_566_1 = {&var1363,&var959,&var907};
_S_or2  S_or2_66_1 = {&var959,&var909,&var908};
_S_and2  S_and2_69_1 = {&var910,&var1038,&var909};
_S_and2  S_and2_68_1 = {&var1632,&var1039,&var910};
_S_or2  S_or2_54_1 = {&A4IS21LDU,&B4IS21LDU,&var911};
_S_or2  S_or2_41_1 = {&var1283,&var1280,&var912};
_S_or2  S_or2_45_1 = {&var1283,&var1282,&var913};
_S_or2  S_or2_23_1 = {&var1187,&var1140,&var914};
_S_or2  S_or2_8_1 = {&var1642,&var961,&var915};
_S_or2  S_or2_17_1 = {&var961,&var1643,&var916};
_S_and3  S_and3_988_1 = {&var261,&var1636,&var936,&var917};
_S_and3  S_and3_589_1 = {&var936,&var264,&var1636,&var918};
_S_and2  S_and2_1054_1 = {&var982,&var920,&var919};
_S_or2  S_or2_1060_1 = {&var1643,&var1642,&var920};
_S_or2  S_or2_1375_1 = {&var1644,&var1642,&var921};
_S_and3  S_and3_1374_1 = {&var980,&var921,&var659,&var922};
_S_or2  S_or2_963_1 = {&var1644,&var1642,&var923};
_S_and3  S_and3_962_1 = {&var980,&var923,&var674,&var924};
_S_or2  S_or2_555_1 = {&var1644,&var1642,&var925};
_S_and3  S_and3_554_1 = {&var980,&var925,&var1364,&var926};
_S_and2  S_and2_552_1 = {&var151,&var1364,&var927};
_S_or2  S_or2_238_1 = {&var1644,&var1642,&var928};
_S_and3  S_and3_237_1 = {&var980,&var928,&var1397,&var929};
_S_and2  S_and2_235_1 = {&var1397,&var152,&var930};
_S_and3  S_and3_868_1 = {&var980,&var933,&var699,&var931};
_S_and2  S_and2_867_1 = {&var493,&var699,&var932};
_S_or2  S_or2_869_1 = {&var1644,&var1642,&var933};
_S_or2  S_or2_1286_1 = {&var1644,&var1642,&var934};
_S_or2  S_or2_6_1 = {&var1643,&var1642,&var935};
_S_or3  S_or3_5_1 = {&var1644,&var1643,&var1642,&var936};
_S_or2  S_or2_744_1 = {&var1544,&var1546,&var937};
_S_or2  S_or2_437_1 = {&var1625,&var942,&var938};
_S_or2  S_or2_420_1 = {&var1625,&var943,&var939};
_S_or4  S_or4_421_1 = {&var939,&var1553,&var1552,&var938,&var940};
_S_and2  S_and2_413_1 = {&A8IS22LDU,&var1617,&var941};
_S_or3  S_or3_399_1 = {&var1607,&var1605,&var1606,&var942};
_S_or3  S_or3_384_1 = {&var1615,&var1614,&var1616,&var943};
_S_and2  S_and2_731_1 = {&var1624,&var1546,&var944};
_S_and2  S_and2_44_1 = {&var1280,&var1281,&var945};
_S_and2  S_and2_148_1 = {&var1556,&var1178,&var946};
_S_and2  S_and2_156_1 = {&var1558,&var1178,&var947};
_S_and2  S_and2_159_1 = {&var1555,&var1178,&var948};
_S_and2  S_and2_151_1 = {&var1178,&var1557,&var949};
_S_and2  S_and2_434_1 = {&var902,&var1609,&var950};
_S_and2  S_and2_433_1 = {&B8IS22LDU,&var1609,&var951};
_S_and2  S_and2_432_1 = {&A8IS22LDU,&var1609,&var952};
_S_and2  S_and2_431_1 = {&R5IS11LDU,&var1609,&var953};
_S_and2  S_and2_423_1 = {&var1551,&var1617,&var954};
_S_and2  S_and2_412_1 = {&R5IS11LDU,&var1617,&var955};
_S_and2  S_and2_416_1 = {&var902,&var1617,&var956};
_S_and2  S_and2_118_1 = {&var961,&var386,&var957};
_S_and2  S_and2_64_1 = {&var1633,&var1039,&var958};
_S_and2  S_and2_65_1 = {&var958,&var1037,&var959};
_S_and2  S_and2_48_1 = {&var1281,&var1282,&var960};
_S_and2  S_and2_11_1 = {&var1641,&var1273,&var961};
_S_and2  S_and2_34_1 = {&var1204,&var250,&var962};
_S_and2  S_and2_33_1 = {&var1098,&var1187,&var963};
_S_and2  S_and2_32_1 = {&var1099,&var1187,&var964};
_S_and2  S_and2_31_1 = {&var1100,&var1187,&var965};
_S_and2  S_and2_30_1 = {&var1101,&var1187,&var966};
_S_and2  S_and2_758_1 = {&var1540,&var1548,&var967};
_S_and2  S_and2_740_1 = {&var1547,&var1624,&var968};
_S_bol  S_bol_590_1 = {&var1737,&fRM_20_0,&var969};
_S_bol  S_bol_584_1 = {&var1734,&fRM_20_0,&var970};
_S_bol  S_bol_575_1 = {&var1734,&fRM_20_03,&var971};
_S_bol  S_bol_573_1 = {&var1737,&fRM_20_03,&var972};
_S_bol  S_bol_978_1 = {&var1734,&fRM_20_03,&var973};
_S_bol  S_bol_980_1 = {&var1737,&fRM_20_03,&var974};
_S_bol  S_bol_1390_1 = {&var1737,&fRM_20_03,&var975};
_S_bol  S_bol_1392_1 = {&var1734,&fRM_20_03,&var976};
_S_bol  S_bol_259_1 = {&var1734,&fRM_20_03,&var977};
_S_bol  S_bol_261_1 = {&var1737,&fRM_20_03,&var978};
_S_sr  S_sr_88_1 = {array_m88_x_1,&iRM_2_,&var979};
_S_bol  S_bol_87_1 = {&var979,&var204,&var980};
_S_ma  S_ma_90_1 = {array_m90_x_1,&R0MW15IP1,&iRM_8_,&var981};
_S_bol  S_bol_1055_1 = {&var983,&fEM_R0UN80RDU,&var982};
_S_sr  S_sr_1061_1 = {array_m1061_x_1,&iRM_2_,&var983};
_S_ovbs  S_ovbs_2100_1 = {&lRM_1_,&fEM_A9UZ04RDU,&var984,&internal1_m2100_tx};
_S_ovbs  S_ovbs_1188_1 = {&lRM_1_,&fEM_A4UZ04RDU,&var985,&internal1_m1188_tx};
_S_zpfs  S_zpfs_1613_1 = {&var1511,&fEM_B8UL03RDU,&var986,&internal1_m1613_tx,&internal1_m1613_y0};
_S_zpfs  S_zpfs_1138_1 = {&var1528,&fEM_B8UL03RDU,&var987,&internal1_m1138_tx,&internal1_m1138_y0};
_S_ma  S_ma_1212_1 = {array_m1212_x_1,&var1480,&iRM_8_,&var988};
_S_ma  S_ma_810_1 = {array_m810_x_1,&var1440,&iRM_8_,&var989};
_S_ma  S_ma_892_1 = {array_m892_x_1,&var1331,&iRM_8_,&var990};
_S_ma  S_ma_1309_1 = {array_m1309_x_1,&var1299,&iRM_8_,&var991};
_S_ma  S_ma_493_1 = {array_m493_x_1,&var1360,&iRM_8_,&var992};
_S_ma  S_ma_170_1 = {array_m170_x_1,&var1393,&iRM_8_,&var993};
_S_zpfs  S_zpfs_1339_1 = {&var1316,&fEM_A3UL03RDU,&var994,&internal1_m1339_tx,&internal1_m1339_y0};
_S_zpfs  S_zpfs_927_1 = {&var1348,&fEM_A3UL03RDU,&var995,&internal1_m927_tx,&internal1_m927_y0};
_S_zpfs  S_zpfs_1246_1 = {&var1498,&fEM_A2UL03RDU,&var996,&internal1_m1246_tx,&internal1_m1246_y0};
_S_rs  S_rs_1079_1 = {&var843,&var842,&var997,&vainSBool,&internal1_m1079_q0};
_S_rs  S_rs_1077_1 = {&var160,&var1005,&var998,&vainSBool,&internal1_m1077_q0};
_S_rs  S_rs_1076_1 = {&var843,&var841,&var999,&vainSBool,&internal1_m1076_q0};
_S_rs  S_rs_1074_1 = {&var159,&var1005,&var1000,&vainSBool,&internal1_m1074_q0};
_S_rs  S_rs_1073_1 = {&var843,&var840,&var1001,&vainSBool,&internal1_m1073_q0};
_S_rs  S_rs_1071_1 = {&var158,&var1005,&var1002,&vainSBool,&internal1_m1071_q0};
_S_rs  S_rs_1070_1 = {&var843,&var839,&var1003,&vainSBool,&internal1_m1070_q0};
_S_rs  S_rs_1068_1 = {&var157,&var1005,&var1004,&vainSBool,&internal1_m1068_q0};
_S_rs  S_rs_1067_1 = {&var843,&var205,&var1005,&vainSBool,&internal1_m1067_q0};
_S_noto  S_noto_1934_1 = {&var461,&var1006};
_S_swtakt  S_swtakt_58_1 = {&var381,&var1007,&internal1_m58_x0};
_S_noto  S_noto_1053_1 = {&var1019,&var1008};
_S_noto  S_noto_1027_1 = {&var1017,&var1009};
_S_noto  S_noto_1039_1 = {&var1018,&var1010};
_S_rs  S_rs_987_1 = {&var1020,&var600,&var1011,&vainSBool,&internal1_m987_q0};
_S_swtakt  S_swtakt_1436_1 = {&var559,&var1012,&internal1_m1436_x0};
_S_swtakt  S_swtakt_1480_1 = {&var547,&var1013,&internal1_m1480_x0};
_S_swtakt  S_swtakt_1476_1 = {&var541,&var1014,&internal1_m1476_x0};
_S_swtakt  S_swtakt_1894_1 = {&var448,&var1015,&internal1_m1894_x0};
_S_swtakt  S_swtakt_1859_1 = {&var422,&var1016,&internal1_m1859_x0};
_S_rs  S_rs_1026_1 = {&var1091,&var588,&var1017,&vainSBool,&internal1_m1026_q0};
_S_rs  S_rs_1037_1 = {&var1091,&var589,&var1018,&vainSBool,&internal1_m1037_q0};
_S_rs  S_rs_1050_1 = {&var1091,&var590,&var1019,&vainSBool,&internal1_m1050_q0};
_S_rs  S_rs_1059_1 = {&var1091,&var591,&var1020,&vainSBool,&internal1_m1059_q0};
_S_noto  S_noto_1013_1 = {&var606,&var1021};
_S_noto  S_noto_1041_1 = {&var606,&var1022};
_S_noto  S_noto_1040_1 = {&var610,&var1023};
_S_rs  S_rs_1036_1 = {&var584,&var586,&var1024,&vainSBool,&internal1_m1036_q0};
_S_rs  S_rs_1052_1 = {&var1091,&var582,&var1025,&vainSBool,&internal1_m1052_q0};
_S_bol  S_bol_1033_1 = {&var1722,&var311,&var1026};
_S_bol  S_bol_1032_1 = {&var1725,&var311,&var1027};
_S_noto  S_noto_994_1 = {&var1086,&var1028};
_S_bol  S_bol_1031_1 = {&var311,&var1722,&var1029};
_S_bol  S_bol_1030_1 = {&var311,&var1725,&var1030};
_S_noto  S_noto_1017_1 = {&var1087,&var1031};
_S_rs  S_rs_1952_1 = {&var466,&var457,&var1032,&vainSBool,&internal1_m1952_q0};
_S_rs  S_rs_1951_1 = {&var466,&var458,&var1033,&vainSBool,&internal1_m1951_q0};
_S_noto  S_noto_328_1 = {&var814,&var1034};
_S_noto  S_noto_310_1 = {&var807,&var1035};
_S_noto  S_noto_282_1 = {&var826,&var1036};
_S_noto  S_noto_62_1 = {&var1048,&var1037};
_S_noto  S_noto_73_1 = {&var1070,&var1038};
_S_noto  S_noto_72_1 = {&var1005,&var1039};
_S_noto  S_noto_1946_1 = {&B2IS11LDU,&var1040};
_S_noto  S_noto_1944_1 = {&A2IS11LDU,&var1041};
_S_noto  S_noto_288_1 = {&var264,&var1042};
_S_noto  S_noto_1953_1 = {&B2IS11LDU,&var1043};
_S_noto  S_noto_1928_1 = {&A2IS11LDU,&var1044};
_S_noto  S_noto_275_1 = {&var910,&var1045};
_S_noto  S_noto_332_1 = {&var958,&var1046};
_S_bolz  S_bolz_336_1 = {&iRM_2_,&var1049,&var1047};
_S_provsbr  S_provsbr_331_1 = {&var1109,&var770,&var1124,&var1141,&var1135,&var1130,&var1127,&var1125,&var1139,&var1134,&var1132,&var1128,&iRM_10_,array_m331_Tpr_1,array_m331_type_1,&var1048,&var1049,&var1050,&var1051,&var1052,&var1053,&var1054,&var1055,&var1056,&internal1_m331_Step,array_m331_rz_1,&internal1_m331_TimS,&internal1_m331_FinPr0,&internal1_m331_ErrPr0,&internal1_m331_sbINI0,&internal1_m331_sbVuIS0,&internal1_m331_sb2UR0,&internal1_m331_sbNupIS0,&internal1_m331_sbVuRB0,&internal1_m331_MyFirstEnterFlag};
_S_orni  S_orni_335_1 = {array_m335_x_1,&iRM_5_,&vainSBool,&var1057};
_S_cntch  S_cntch_339_1 = {&var1057,&var1058,&internal1_m339_x0};
_S_bolz  S_bolz_314_1 = {&iRM_20_,&var1072,&var1059};
_S_equz_p  S_equz_p_313_1 = {&var1071,&iRM_0_,&var1060};
_S_decatron  S_decatron_297_1 = {&var806,&var1061,&internal1_m297_TimS};
_S_noto  S_noto_991_1 = {&R2IS21LDU,&var1062};
_S_noto  S_noto_985_1 = {&R1IS21LDU,&var1063};
_S_andn  S_andn_270_1 = {array_m270_x_1,&iRM_7_,&var1064};
_S_noto  S_noto_272_1 = {&R0MD33LP1,&var1065};
_S_noto  S_noto_280_1 = {&R2IS21LDU,&var1066};
_S_noto  S_noto_276_1 = {&R1IS21LDU,&var1067};
_S_noto  S_noto_267_1 = {&R1IS11LDU,&var1068};
_S_noto  S_noto_264_1 = {&R2IS11LDU,&var1069};
_S_provsbr  S_provsbr_274_1 = {&var1111,&var823,&var1124,&var1141,&var1135,&var1130,&var1127,&var1125,&var1139,&var1134,&var1132,&var1128,&iRM_10_,array_m274_Tpr_1,array_m274_type_1,&var1070,&var1071,&var1072,&var1073,&var1074,&var1075,&var1076,&var1077,&var1078,&internal1_m274_Step,array_m274_rz_1,&internal1_m274_TimS,&internal1_m274_FinPr0,&internal1_m274_ErrPr0,&internal1_m274_sbINI0,&internal1_m274_sbVuIS0,&internal1_m274_sb2UR0,&internal1_m274_sbNupIS0,&internal1_m274_sbVuRB0,&internal1_m274_MyFirstEnterFlag};
_S_rs  S_rs_1410_1 = {&var1080,&var581,&var1079,&vainSBool,&internal1_m1410_q0};
_S_provsbr  S_provsbr_1411_1 = {&var1079,&R0MD34LP1,&var1124,&var1141,&var1135,&var1130,&var1127,&var1125,&var1139,&var1134,&var1132,&var1128,&iRM_6_,array_m1411_Tpr_1,array_m1411_type_1,&var1080,&vainSInt,&vainSInt,&vainSBool,&var1081,&var1082,&var1083,&var1084,&var1085,&internal1_m1411_Step,array_m1411_rz_1,&internal1_m1411_TimS,&internal1_m1411_FinPr0,&internal1_m1411_ErrPr0,&internal1_m1411_sbINI0,&internal1_m1411_sbVuIS0,&internal1_m1411_sb2UR0,&internal1_m1411_sbNupIS0,&internal1_m1411_sbVuRB0,&internal1_m1411_MyFirstEnterFlag};
_S_abs_subf  S_abs_subf_997_1 = {&var311,&var1725,&fEM_B8UC01RDU,&vainSFloat,&var1086};
_S_abs_subf  S_abs_subf_1010_1 = {&var1722,&var311,&fEM_B8UC01RDU,&vainSFloat,&var1087};
_S_noto  S_noto_650_1 = {&var774,&var1088};
_S_noto  S_noto_597_1 = {&var790,&var1089};
_S_noto  S_noto_55_1 = {&var307,&var1090};
_S_noto  S_noto_1014_1 = {&var1288,&var1091};
_S_rs  S_rs_1021_1 = {&var583,&var402,&var1092,&vainSBool,&internal1_m1021_q0};
_S_rs  S_rs_1018_1 = {&var587,&var582,&var1093,&vainSBool,&internal1_m1018_q0};
_S_rs  S_rs_1020_1 = {&var1091,&var402,&var1094,&vainSBool,&internal1_m1020_q0};
_S_rs  S_rs_1015_1 = {&var1091,&var585,&var1095,&vainSBool,&internal1_m1015_q0};
_S_noto  S_noto_586_1 = {&A2IS21LDU,&var1096};
_S_noto  S_noto_588_1 = {&B2IS21LDU,&var1097};
_S_noto  S_noto_28_1 = {&B2IS21LDU,&var1098};
_S_noto  S_noto_27_1 = {&B1IS21LDU,&var1099};
_S_noto  S_noto_26_1 = {&A1IS21LDU,&var1100};
_S_noto  S_noto_25_1 = {&A2IS21LDU,&var1101};
_S_newstage  S_newstage_598_1 = {&var128,&var125,&A2IS12LDU,&B2IS12LDU,&var1102};
_S_noto  S_noto_587_1 = {&B2IS12LDU,&var1103};
_S_noto  S_noto_585_1 = {&A2IS12LDU,&var1104};
_S_noto  S_noto_345_1 = {&var765,&var1105};
_S_noto  S_noto_349_1 = {&var764,&var1106};
_S_noto  S_noto_984_1 = {&var902,&var1107};
_S_rs  S_rs_748_1 = {&var762,&var384,&var1108,&vainSBool,&internal1_m748_q0};
_S_rs  S_rs_341_1 = {&var766,&var767,&var1109,&vainSBool,&internal1_m341_q0};
_S_rs  S_rs_337_1 = {&var768,&var769,&var1110,&vainSBool,&internal1_m337_q0};
_S_rs  S_rs_294_1 = {&var822,&var808,&var1111,&vainSBool,&internal1_m294_q0};
_S_orni  S_orni_290_1 = {array_m290_x_1,&iRM_5_,&vainSBool,&var1112};
_S_cntch  S_cntch_293_1 = {&var1112,&var1113,&internal1_m293_x0};
_S_noto  S_noto_1449_1 = {&var1132,&var1114};
_S_noto  S_noto_1505_1 = {&var1134,&var1115};
_S_noto  S_noto_1507_1 = {&var1139,&var1116};
_S_noto  S_noto_1875_1 = {&var1125,&var1117};
_S_noto  S_noto_1909_1 = {&var1128,&var1118};
_S_noto  S_noto_1890_1 = {&var1015,&var1119};
_S_noto  S_noto_1853_1 = {&var1016,&var1120};
_S_noto  S_noto_1477_1 = {&var1014,&var1121};
_S_noto  S_noto_1472_1 = {&var1013,&var1122};
_S_noto  S_noto_1432_1 = {&var1012,&var1123};
_S_rs  S_rs_1881_1 = {&var566,&var406,&var1124,&vainSBool,&internal1_m1881_q0};
_S_rs  S_rs_1869_1 = {&var421,&var418,&var1125,&vainSBool,&internal1_m1869_q0};
_S_rs  S_rs_1860_1 = {&var417,&var1016,&var1126,&vainSBool,&internal1_m1860_q0};
_S_rs  S_rs_1935_1 = {&var566,&var435,&var1127,&vainSBool,&internal1_m1935_q0};
_S_rs  S_rs_1906_1 = {&var443,&var442,&var1128,&vainSBool,&internal1_m1906_q0};
_S_rs  S_rs_1895_1 = {&var445,&var1015,&var1129,&vainSBool,&internal1_m1895_q0};
_S_rs  S_rs_1463_1 = {&var566,&var552,&var1130,&vainSBool,&internal1_m1463_q0};
_S_kvf  S_kvf_1450_1 = {&var1133,&var553,&fRM_0_0,&var1131,&vainSInt,&vainSInt,&internal1_m1450_x0,&internal1_m1450_y0,&bFirstEnterFlag};
_S_rs  S_rs_1446_1 = {&var558,&var553,&var1132,&vainSBool,&internal1_m1446_q0};
_S_rs  S_rs_1437_1 = {&var555,&var1012,&var1133,&vainSBool,&internal1_m1437_q0};
_S_rs  S_rs_1496_1 = {&var548,&var543,&var1134,&vainSBool,&internal1_m1496_q0};
_S_rs  S_rs_1516_1 = {&var566,&var549,&var1135,&vainSBool,&internal1_m1516_q0};
_S_rs  S_rs_1482_1 = {&var546,&var1013,&var1136,&vainSBool,&internal1_m1482_q0};
_S_kvf  S_kvf_1497_1 = {&var1136,&var543,&fRM_0_0,&var1137,&vainSInt,&vainSInt,&internal1_m1497_x0,&internal1_m1497_y0,&bFirstEnterFlag};
_S_cntch  S_cntch_1421_1 = {&var568,&var1138,&internal1_m1421_x0};
_S_rs  S_rs_1502_1 = {&var540,&var534,&var1139,&vainSBool,&internal1_m1502_q0};
_S_rs  S_rs_29_1 = {&var1187,&var962,&var1140,&vainSBool,&internal1_m29_q0};
_S_rs  S_rs_1517_1 = {&var566,&var533,&var1141,&vainSBool,&internal1_m1517_q0};
_S_noto  S_noto_1399_1 = {&var562,&var1142};
_S_noto  S_noto_1397_1 = {&var961,&var1143};
_S_rs  S_rs_638_1 = {&var1519,&var777,&var1144,&vainSBool,&internal1_m638_q0};
_S_rs  S_rs_623_1 = {&var1519,&var784,&var1145,&vainSBool,&internal1_m623_q0};
_S_rs  S_rs_651_1 = {&var1519,&var785,&var1146,&vainSBool,&internal1_m651_q0};
_S_rs  S_rs_634_1 = {&var1519,&var796,&var1147,&vainSBool,&internal1_m634_q0};
_S_rs  S_rs_618_1 = {&var1519,&var799,&var1148,&vainSBool,&internal1_m618_q0};
_S_rs  S_rs_616_1 = {&var1519,&var801,&var1149,&vainSBool,&internal1_m616_q0};
_S_rs  S_rs_604_1 = {&var804,&var1522,&var1150,&vainSBool,&internal1_m604_q0};
_S_rsun  S_rsun_1413_1 = {&var566,&var1272,&vainSLong,&var1151,&internal1_m1413_q0};
_S_noto  S_noto_1340_1 = {&B3MD12LP1,&var1152};
_S_noto  S_noto_1827_1 = {&B3IS11LDU,&var1153};
_S_noto  S_noto_1801_1 = {&A3IS11LDU,&var1154};
_S_noto  S_noto_117_1 = {&var961,&var1155};
_S_noto  S_noto_116_1 = {&var1160,&var1156};
_S_rs  S_rs_614_1 = {&var1519,&var803,&var1157,&vainSBool,&internal1_m614_q0};
_S_orni  S_orni_1187_1 = {array_m1187_x_1,&iRM_5_,&var1158,&vainSLong};
_S_orni  S_orni_1174_1 = {array_m1174_x_1,&iRM_4_,&var1159,&vainSLong};
_S_rs  S_rs_115_1 = {&var903,&var957,&var1160,&vainSBool,&internal1_m115_q0};
_S_noto  S_noto_1830_1 = {&var484,&var1161};
_S_noto  S_noto_1829_1 = {&var483,&var1162};
_S_noto  S_noto_1841_1 = {&B3IS22LDU,&var1163};
_S_noto  S_noto_1822_1 = {&A3IS22LDU,&var1164};
_S_newstage  S_newstage_1825_1 = {&var500,&var496,&var499,&var495,&vainSBool};
_S_noto  S_noto_1769_1 = {&var1250,&var1165};
_S_rs  S_rs_1649_1 = {&var42,&var275,&var1166,&vainSBool,&internal1_m1649_q0};
_S_rs  S_rs_1648_1 = {&var35,&var277,&var1167,&vainSBool,&internal1_m1648_q0};
_S_rs  S_rs_1647_1 = {&var41,&var279,&var1168,&vainSBool,&internal1_m1647_q0};
_S_rs  S_rs_1646_1 = {&var16,&var281,&var1169,&vainSBool,&internal1_m1646_q0};
_S_rs  S_rs_1684_1 = {&var250,&var283,&var1170,&vainSBool,&internal1_m1684_q0};
_S_rs  S_rs_1683_1 = {&var53,&var286,&var1171,&vainSBool,&internal1_m1683_q0};
_S_rs  S_rs_1682_1 = {&var54,&var286,&var1172,&vainSBool,&internal1_m1682_q0};
_S_noto  S_noto_1240_1 = {&A2MD12LP1,&var1173};
_S_noto  S_noto_1224_1 = {&B2MD12LP1,&var1174};
_S_noto  S_noto_508_1 = {&B1MD12LP1,&var1175};
_S_ma  S_ma_1452_1 = {array_m1452_x_1,&var1151,&iRM_16_,&var1176};
_S_noto  S_noto_1407_1 = {&var818,&var1177};
_S_noto  S_noto_146_1 = {&var961,&var1178};
_S_equz_p  S_equz_p_1807_1 = {&R0MW14IP2,&iRM_5_,&var1179};
_S_equz_p  S_equz_p_1806_1 = {&R0MW14IP2,&iRM_4_,&var1180};
_S_equz_p  S_equz_p_1805_1 = {&R0MW14IP2,&iRM_3_,&var1181};
_S_equz_p  S_equz_p_1803_1 = {&R0MW14IP2,&iRM_1_,&vainSBool};
_S_equz_p  S_equz_p_1804_1 = {&R0MW14IP2,&iRM_2_,&var1182};
_S_noto  S_noto_1862_1 = {&B3IS11LDU,&var1183};
_S_noto  S_noto_1857_1 = {&A3IS11LDU,&var1184};
_S_noto  S_noto_1899_1 = {&B2IS11LDU,&var1185};
_S_noto  S_noto_1907_1 = {&A2IS11LDU,&var1186};
_S_noto  S_noto_12_1 = {&var1641,&var1187};
_S_rs  S_rs_1966_1 = {&var369,&var470,&var1188,&vainSBool,&internal1_m1966_q0};
_S_rs  S_rs_1744_1 = {&var512,&var296,&var1189,&vainSBool,&internal1_m1744_q0};
_S_rs  S_rs_1733_1 = {&var38,&var297,&var1190,&vainSBool,&internal1_m1733_q0};
_S_rs  S_rs_1741_1 = {&var55,&var298,&var1191,&vainSBool,&internal1_m1741_q0};
_S_rs  S_rs_1730_1 = {&var39,&var299,&var1192,&vainSBool,&internal1_m1730_q0};
_S_rs  S_rs_1738_1 = {&var59,&var300,&var1193,&vainSBool,&internal1_m1738_q0};
_S_equz_p  S_equz_p_105_1 = {&R0MW16IP1,&iRM_10_,&var1194};
_S_noto  S_noto_184_1 = {&A1MD12LP1,&var1195};
_S_rs  S_rs_2166_1 = {&var29,&var26,&var1196,&vainSBool,&internal1_m2166_q0};
_S_rs  S_rs_2162_1 = {&var45,&var117,&var1197,&vainSBool,&internal1_m2162_q0};
_S_rs  S_rs_1709_1 = {&var58,&var293,&var1198,&vainSBool,&internal1_m1709_q0};
_S_rs  S_rs_1701_1 = {&var250,&var282,&var1199,&vainSBool,&internal1_m1701_q0};
_S_rs  S_rs_1699_1 = {&var40,&var283,&var1200,&vainSBool,&internal1_m1699_q0};
_S_rs  S_rs_1695_1 = {&var53,&var284,&var1201,&vainSBool,&internal1_m1695_q0};
_S_rs  S_rs_1691_1 = {&var13,&var286,&var1202,&vainSBool,&internal1_m1691_q0};
_S_rs  S_rs_1693_1 = {&var54,&var285,&var1203,&vainSBool,&internal1_m1693_q0};
_S_rs  S_rs_22_1 = {&var914,&var390,&var1204,&vainSBool,&internal1_m22_q0};
_S_equz_p  S_equz_p_104_1 = {&R0MW16IP1,&iRM_9_,&var1205};
_S_equz_p  S_equz_p_103_1 = {&R0MW16IP1,&iRM_8_,&var1206};
_S_noto  S_noto_928_1 = {&A3MD12LP1,&var1207};
_S_equz_p  S_equz_p_102_1 = {&R0MW16IP1,&iRM_7_,&var1208};
_S_equz_p  S_equz_p_101_1 = {&R0MW16IP1,&iRM_6_,&var1209};
_S_equz_p  S_equz_p_100_1 = {&R0MW16IP1,&iRM_5_,&var1210};
_S_rs  S_rs_1672_1 = {&var42,&var274,&var1211,&vainSBool,&internal1_m1672_q0};
_S_rs  S_rs_1670_1 = {&var34,&var275,&var1212,&vainSBool,&internal1_m1670_q0};
_S_rs  S_rs_1666_1 = {&var52,&var277,&var1213,&vainSBool,&internal1_m1666_q0};
_S_rs  S_rs_1668_1 = {&var35,&var276,&var1214,&vainSBool,&internal1_m1668_q0};
_S_rs  S_rs_1664_1 = {&var41,&var278,&var1215,&vainSBool,&internal1_m1664_q0};
_S_rs  S_rs_1662_1 = {&var17,&var279,&var1216,&vainSBool,&internal1_m1662_q0};
_S_rs  S_rs_2082_1 = {&var132,&var479,&var1217,&vainSBool,&internal1_m2082_q0};
_S_rs  S_rs_2077_1 = {&var133,&var480,&var1218,&vainSBool,&internal1_m2077_q0};
_S_equz_p  S_equz_p_303_1 = {&var1061,&iRM_0_,&var1219};
_S_noto  S_noto_2083_1 = {&var1217,&var1220};
_S_noto  S_noto_2073_1 = {&var394,&var1221};
_S_noto  S_noto_2057_1 = {&var1223,&var1222};
_S_rs  S_rs_2056_1 = {&var72,&var476,&var1223,&vainSBool,&internal1_m2056_q0};
_S_noto  S_noto_2045_1 = {&var1225,&var1224};
_S_rs  S_rs_2044_1 = {&var74,&var473,&var1225,&vainSBool,&internal1_m2044_q0};
_S_noto  S_noto_2078_1 = {&var1218,&var1226};
_S_noto  S_noto_2069_1 = {&var393,&var1227};
_S_noto  S_noto_1978_1 = {&var1229,&var1228};
_S_rs  S_rs_1977_1 = {&var368,&var471,&var1229,&vainSBool,&internal1_m1977_q0};
_S_noto  S_noto_1967_1 = {&var1188,&var1230};
_S_noto  S_noto_1973_1 = {&var391,&var1231};
_S_noto  S_noto_1961_1 = {&var392,&var1232};
_S_rs  S_rs_1658_1 = {&var51,&var281,&var1233,&vainSBool,&internal1_m1658_q0};
_S_rs  S_rs_1660_1 = {&var16,&var280,&var1234,&vainSBool,&internal1_m1660_q0};
_S_rs  S_rs_1644_1 = {&var32,&var266,&var1235,&vainSBool,&internal1_m1644_q0};
_S_rs  S_rs_1642_1 = {&var50,&var267,&var1236,&vainSBool,&internal1_m1642_q0};
_S_rs  S_rs_1640_1 = {&var31,&var268,&var1237,&vainSBool,&internal1_m1640_q0};
_S_rs  S_rs_1638_1 = {&var49,&var269,&var1238,&vainSBool,&internal1_m1638_q0};
_S_noto  S_noto_1764_1 = {&B3IS22LDU,&var1239};
_S_noto  S_noto_1763_1 = {&A3IS22LDU,&var1240};
_S_noto  S_noto_1762_1 = {&B2IS12LDU,&var1241};
_S_noto  S_noto_1761_1 = {&A2IS12LDU,&var1242};
_S_noto  S_noto_1760_1 = {&B1IS12LDU,&var1243};
_S_noto  S_noto_1759_1 = {&A1IS12LDU,&var1244};
_S_noto  S_noto_1789_1 = {&B3IS21LDU,&var1245};
_S_noto  S_noto_1783_1 = {&B2IS21LDU,&var1246};
_S_noto  S_noto_1788_1 = {&A3IS21LDU,&var1247};
_S_noto  S_noto_1786_1 = {&B4IS21LDU,&var1248};
_S_noto  S_noto_1787_1 = {&A4IS21LDU,&var1249};
_S_andn  S_andn_1772_1 = {array_m1772_x_1,&iRM_17_,&var1250};
_S_noto  S_noto_1781_1 = {&B1IS21LDU,&var1251};
_S_noto  S_noto_1782_1 = {&A2IS21LDU,&var1252};
_S_noto  S_noto_1780_1 = {&A1IS21LDU,&var1253};
_S_rs  S_rs_1637_1 = {&var1258,&var270,&var1254,&vainSBool,&internal1_m1637_q0};
_S_rs  S_rs_1635_1 = {&var33,&var271,&var1255,&vainSBool,&internal1_m1635_q0};
_S_rs  S_rs_1634_1 = {&var1258,&var272,&var1256,&vainSBool,&internal1_m1634_q0};
_S_rs  S_rs_1632_1 = {&var14,&var273,&var1257,&vainSBool,&internal1_m1632_q0};
_S_newstage  S_newstage_2103_1 = {&var1270,&var1264,&var1269,&var1263,&var1258};
_S_samhd  S_samhd_2105_1 = {&var524,&var525,&var525,&var1255,&var1254,&var1255,&var1254,&B9IS11LDU,&B9IS11LDU,&B9IS21LDU,&B9IS21LDU,&bRM_1_,&fEM_A9UZ05RDU,&fEM_A9UZ03RDU,&fEM_A9UZ04RDU,&var1259,&var1260,&vainSBool,&var1261,&var1262,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1263,&var1264,&internal1_m2105_DvUp0,&internal1_m2105_DvDw0,&internal1_m2105_FDvUp0,&internal1_m2105_FDvDw0,&internal1_m2105_BlDv0,&internal1_m2105_Pkv0,&internal1_m2105_Pkav0,&internal1_m2105_Zkv0,&internal1_m2105_Zkav0,&internal1_m2105_txNm,&internal1_m2105_txSm,&internal1_m2105_txHr,&internal1_m2105_txLd,&internal1_m2105_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_2099_1 = {&var524,&var526,&var526,&var1257,&var1256,&var1257,&var1256,&A9IS11LDU,&A9IS11LDU,&A9IS21LDU,&A9IS21LDU,&bRM_1_,&fEM_A9UZ05RDU,&fEM_A9UZ03RDU,&fEM_A9UZ04RDU,&var1265,&var1266,&vainSBool,&var1267,&var1268,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1269,&var1270,&internal1_m2099_DvUp0,&internal1_m2099_DvDw0,&internal1_m2099_FDvUp0,&internal1_m2099_FDvDw0,&internal1_m2099_BlDv0,&internal1_m2099_Pkv0,&internal1_m2099_Pkav0,&internal1_m2099_Zkv0,&internal1_m2099_Zkav0,&internal1_m2099_txNm,&internal1_m2099_txSm,&internal1_m2099_txHr,&internal1_m2099_txLd,&internal1_m2099_fef,&bFirstEnterFlag};
_S_orni  S_orni_1414_1 = {array_m1414_x_1,&iRM_5_,&var1271,&var1272};
_S_noto  S_noto_84_1 = {&var396,&var1273};
_S_maz  S_maz_309_1 = {array_m309_x_1,&R0MW12IP1,&iRM_3_,&var1274};
_S_maz  S_maz_300_1 = {array_m300_x_1,&R0MW12IP1,&iRM_3_,&var1275};
_S_rs  S_rs_1487_1 = {&var537,&var1014,&var1276,&vainSBool,&internal1_m1487_q0};
_S_kvf  S_kvf_1491_1 = {&var1276,&var534,&fRM_0_0,&var1277,&vainSInt,&vainSInt,&internal1_m1491_x0,&internal1_m1491_y0,&bFirstEnterFlag};
_S_kvf  S_kvf_1917_1 = {&var451,&var439,&fRM_0_0,&var1278,&vainSInt,&vainSInt,&internal1_m1917_x0,&internal1_m1917_y0,&bFirstEnterFlag};
_S_kvf  S_kvf_1878_1 = {&var411,&var408,&fRM_0_0,&var1279,&vainSInt,&vainSInt,&internal1_m1878_x0,&internal1_m1878_y0,&bFirstEnterFlag};
_S_equz_p  S_equz_p_43_1 = {&R0MW13IP1,&iRM_1_,&var1280};
_S_noto  S_noto_40_1 = {&var1283,&var1281};
_S_equz_p  S_equz_p_47_1 = {&R0MW13IP1,&iRM_2_,&var1282};
_S_equz_p  S_equz_p_38_1 = {&R0MW13IP1,&iRM_3_,&var1283};
_S_noto  S_noto_1919_1 = {&var1129,&var1284};
_S_rs  S_rs_285_1 = {&var824,&var825,&var1285,&vainSBool,&internal1_m285_q0};
_S_orn  S_orn_595_1 = {array_m595_x_1,&iRM_5_,&var1286};
_S_noto  S_noto_1004_1 = {&lEM_R0MD01LC1,&var1287};
_S_rs  S_rs_995_1 = {&var601,&var917,&var1288,&vainSBool,&internal1_m995_q0};
_S_rs  S_rs_626_1 = {&var779,&var781,&var1289,&vainSBool,&internal1_m626_q0};
_S_noto  S_noto_1394_1 = {&var960,&var1290};
_S_orn  S_orn_1373_1 = {array_m1373_x_1,&iRM_8_,&var1291};
_S_noto  S_noto_1372_1 = {&var1459,&var1292};
_S_noto  S_noto_1371_1 = {&var1469,&var1293};
_S_noto  S_noto_1354_1 = {&var961,&var1294};
_S_noto  S_noto_1363_1 = {&R8IS11LDU,&var1295};
_S_charint  S_charint_1300_1 = {&var1298,&var1296};
_S_ornc  S_ornc_1308_1 = {array_m1308_x_1,&iRM_3_,&var1297,&var1298};
_S_fsumz  S_fsumz_1301_1 = {&var1296,&iRM_1_,&var1299};
_S_cnshd  S_cnshd_1310_1 = {&R0MD34LP1,&var1728,&var991,&var315,&var1297,&var646,&var642,&iRM_1_,array_m1310_Lt_fw_1,array_m1310_Vr_fw_1,&iRM_1_,array_m1310_Lt_bw_1,array_m1310_Vr_bw_1,&fEM_A3UC08RDU,&fEM_A3UC07RDU,&fEM_A3UL01RDU,&fEM_A3UC02RDU,&var1300,&vainSBool,&var1301,&var1302,&var1303,&var1304,&var1305,&var1306,&var1307,&var1308,&var1309,&var1310,&internal1_m1310_X0,&internal1_m1310_t0,&internal1_m1310_BLDv0};
_S_zpfs  S_zpfs_1329_1 = {&var1319,&fRM_2_0,&var1311,&internal1_m1329_tx,&internal1_m1329_y0};
_S_zpfs  S_zpfs_1331_1 = {&var1318,&fRM_3_0,&var1312,&internal1_m1331_tx,&internal1_m1331_y0};
_S_fnapb  S_fnapb_1338_1 = {&var1728,&var991,&var645,&R0MD34LP1,&var1302,&var1309,&fEM_B8UV04RDU,&fEM_A3UV01RDU,&fEM_A3UV02RDU,&fEM_A3UC06RDU,&fEM_A3UC05RDU,&iRM_60_,&fEM_A3UL04RDU,&fEM_A3UL05RDU,&fEM_A3UL03RDU,&var1313,&var1314,&var1315,&var1316,&var1317,&var1318,&var1319,&vainSFloat,&internal1_m1338_xptr,array_m1338_x0_1,array_m1338_tim0_1,&internal1_m1338_sumtim,&internal1_m1338_StSpeed,&internal1_m1338_Vz0,&internal1_m1338_flRazg,&internal1_m1338_DelSp,&internal1_m1338_z0,&internal1_m1338_txZS,&internal1_m1338_tx,&internal1_m1338_txd,&internal1_m1338_txMBl,&internal1_m1338_txBl,&internal1_m1338_Speed0,&internal1_m1338_xz0,&internal1_m1338_tz0,&internal1_m1338_Shift0,&internal1_m1338_ShCntlSp0,&internal1_m1338_ShiftControl,&bFirstEnterFlag};
_S_newstage  S_newstage_905_1 = {&var1329,&var1297,&var1332,&var1300,&var1320};
_S_rs  S_rs_624_1 = {&var780,&var784,&var1321,&vainSBool,&internal1_m624_q0};
_S_noto  S_noto_982_1 = {&var945,&var1322};
_S_orn  S_orn_961_1 = {array_m961_x_1,&iRM_8_,&var1323};
_S_noto  S_noto_960_1 = {&var1459,&var1324};
_S_noto  S_noto_959_1 = {&var1469,&var1325};
_S_noto  S_noto_943_1 = {&var961,&var1326};
_S_noto  S_noto_951_1 = {&R8IS11LDU,&var1327};
_S_charint  S_charint_883_1 = {&var1330,&var1328};
_S_ornc  S_ornc_891_1 = {array_m891_x_1,&iRM_3_,&var1329,&var1330};
_S_fsumz  S_fsumz_884_1 = {&var1328,&iRM_1_,&var1331};
_S_cnshd  S_cnshd_893_1 = {&R0MD34LP1,&var1731,&var990,&var319,&var1329,&var681,&var682,&iRM_1_,array_m893_Lt_fw_1,array_m893_Vr_fw_1,&iRM_1_,array_m893_Lt_bw_1,array_m893_Vr_bw_1,&fEM_A3UC08RDU,&fEM_A3UC07RDU,&fEM_A3UL01RDU,&fEM_A3UC02RDU,&var1332,&vainSBool,&var1333,&var1334,&var1335,&var1336,&var1337,&var1338,&var1339,&var1340,&var1341,&var1342,&internal1_m893_X0,&internal1_m893_t0,&internal1_m893_BLDv0};
_S_zpfs  S_zpfs_917_1 = {&var1351,&fRM_2_0,&var1343,&internal1_m917_tx,&internal1_m917_y0};
_S_zpfs  S_zpfs_919_1 = {&var1350,&fRM_3_0,&var1344,&internal1_m919_tx,&internal1_m919_y0};
_S_fnapb  S_fnapb_926_1 = {&var1731,&var990,&var680,&R0MD34LP1,&var1334,&var1341,&fEM_B8UV04RDU,&fEM_A3UV01RDU,&fEM_A3UV02RDU,&fEM_A3UC06RDU,&fEM_A3UC05RDU,&iRM_60_,&fEM_A3UL04RDU,&fEM_A3UL05RDU,&fEM_A3UL03RDU,&var1345,&var1346,&var1347,&var1348,&var1349,&var1350,&var1351,&vainSFloat,&internal1_m926_xptr,array_m926_x0_1,array_m926_tim0_1,&internal1_m926_sumtim,&internal1_m926_StSpeed,&internal1_m926_Vz0,&internal1_m926_flRazg,&internal1_m926_DelSp,&internal1_m926_z0,&internal1_m926_txZS,&internal1_m926_tx,&internal1_m926_txd,&internal1_m926_txMBl,&internal1_m926_txBl,&internal1_m926_Speed0,&internal1_m926_xz0,&internal1_m926_tz0,&internal1_m926_Shift0,&internal1_m926_ShCntlSp0,&internal1_m926_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_577_1 = {&var960,&var1352};
_S_noto  S_noto_550_1 = {&var1459,&var1353};
_S_noto  S_noto_549_1 = {&var1469,&var1354};
_S_noto  S_noto_534_1 = {&var961,&var1355};
_S_noto  S_noto_541_1 = {&R8IS11LDU,&var1356};
_S_charint  S_charint_486_1 = {&var1359,&var1357};
_S_ornc  S_ornc_492_1 = {array_m492_x_1,&iRM_3_,&var1358,&var1359};
_S_fsumz  S_fsumz_487_1 = {&var1357,&iRM_1_,&var1360};
_S_cnshd  S_cnshd_495_1 = {&R0MD34LP1,&var1741,&var992,&var323,&var1358,&var752,&var746,&iRM_2_,array_m495_Lt_fw_1,array_m495_Vr_fw_1,&iRM_1_,array_m495_Lt_bw_1,array_m495_Vr_bw_1,&fEM_A1UC08RDU,&fEM_A1UC07RDU,&fEM_A1UL01RDU,&fEM_A1UC02RDU,&var1361,&vainSBool,&var1362,&var1363,&var1364,&var1365,&var1366,&var1367,&var1368,&var1369,&var1370,&var1371,&internal1_m495_X0,&internal1_m495_t0,&internal1_m495_BLDv0};
_S_zpfs  S_zpfs_515_1 = {&var1380,&fRM_2_0,&var1372,&internal1_m515_tx,&internal1_m515_y0};
_S_zpfs  S_zpfs_518_1 = {&var1379,&fRM_3_0,&var1373,&internal1_m518_tx,&internal1_m518_y0};
_S_fnapb  S_fnapb_522_1 = {&var1741,&var992,&var750,&R0MD34LP1,&var1363,&var1370,&fEM_B8UV04RDU,&fEM_A1UV01RDU,&fEM_A1UV02RDU,&fEM_A1UC06RDU,&fEM_A1UC05RDU,&iRM_150_,&fEM_A1UL04RDU,&fEM_A1UL05RDU,&fEM_A1UL03RDU,&var1374,&var1375,&var1376,&var1377,&var1378,&var1379,&var1380,&vainSFloat,&internal1_m522_xptr,array_m522_x0_1,array_m522_tim0_1,&internal1_m522_sumtim,&internal1_m522_StSpeed,&internal1_m522_Vz0,&internal1_m522_flRazg,&internal1_m522_DelSp,&internal1_m522_z0,&internal1_m522_txZS,&internal1_m522_tx,&internal1_m522_txd,&internal1_m522_txMBl,&internal1_m522_txBl,&internal1_m522_Speed0,&internal1_m522_xz0,&internal1_m522_tz0,&internal1_m522_Shift0,&internal1_m522_ShCntlSp0,&internal1_m522_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_642_1 = {&R0MD33LP1,&var1381};
_S_noto  S_noto_263_1 = {&var945,&var1382};
_S_newstage  S_newstage_211_1 = {&var1391,&var1358,&var1394,&var1361,&var1383};
_S_rs  S_rs_621_1 = {&var775,&var787,&var1384,&vainSBool,&internal1_m621_q0};
_S_orn  S_orn_234_1 = {array_m234_x_1,&iRM_12_,&var1385};
_S_noto  S_noto_233_1 = {&var1459,&var1386};
_S_noto  S_noto_232_1 = {&var1469,&var1387};
_S_noto  S_noto_217_1 = {&var961,&var1388};
_S_noto  S_noto_224_1 = {&R8IS11LDU,&var1389};
_S_charint  S_charint_163_1 = {&var1392,&var1390};
_S_ornc  S_ornc_169_1 = {array_m169_x_1,&iRM_3_,&var1391,&var1392};
_S_fsumz  S_fsumz_164_1 = {&var1390,&iRM_1_,&var1393};
_S_cnshd  S_cnshd_174_1 = {&R0MD34LP1,&var1719,&var993,&var327,&var1391,&var732,&var725,&iRM_2_,array_m174_Lt_fw_1,array_m174_Vr_fw_1,&iRM_1_,array_m174_Lt_bw_1,array_m174_Vr_bw_1,&fEM_A1UC08RDU,&fEM_A1UC07RDU,&fEM_A1UL01RDU,&fEM_A1UC02RDU,&var1394,&vainSBool,&var1395,&var1396,&var1397,&var1398,&var1399,&var1400,&var1401,&var1402,&var1403,&var1404,&internal1_m174_X0,&internal1_m174_t0,&internal1_m174_BLDv0};
_S_fnapb  S_fnapb_203_1 = {&var1719,&var993,&var728,&R0MD34LP1,&var1396,&var1403,&fEM_B8UV04RDU,&fEM_A1UV01RDU,&fEM_A1UV02RDU,&fEM_A1UC06RDU,&fEM_A1UC05RDU,&iRM_150_,&fEM_A1UL04RDU,&fEM_A1UL05RDU,&fEM_A1UL03RDU,&var1405,&var1406,&var1407,&var1408,&var1409,&var1410,&var1411,&vainSFloat,&internal1_m203_xptr,array_m203_x0_1,array_m203_tim0_1,&internal1_m203_sumtim,&internal1_m203_StSpeed,&internal1_m203_Vz0,&internal1_m203_flRazg,&internal1_m203_DelSp,&internal1_m203_z0,&internal1_m203_txZS,&internal1_m203_tx,&internal1_m203_txd,&internal1_m203_txMBl,&internal1_m203_txBl,&internal1_m203_Speed0,&internal1_m203_xz0,&internal1_m203_tz0,&internal1_m203_Shift0,&internal1_m203_ShCntlSp0,&internal1_m203_ShiftControl,&bFirstEnterFlag};
_S_rs  S_rs_647_1 = {&var786,&var789,&var1412,&vainSBool,&internal1_m647_q0};
_S_newstage  S_newstage_462_1 = {&var1431,&var1422,&var1430,&var1421,&var1413};
_S_samhd  S_samhd_466_1 = {&R0MD34LP1,&var755,&var755,&var378,&var377,&R2VS12LDU,&R2VS22LDU,&R2IS11LDU,&R2IS11LDU,&R2IS21LDU,&R2IS21LDU,&bRM_0_,&fEM_R1UZ05RDU,&fEM_R1UZ03RDU,&fEM_R1UZ04RDU,&var1414,&var1415,&var1416,&var1417,&var1418,&var1419,&vainSBool,&vainSBool,&var1420,&var1421,&var1422,&internal1_m466_DvUp0,&internal1_m466_DvDw0,&internal1_m466_FDvUp0,&internal1_m466_FDvDw0,&internal1_m466_BlDv0,&internal1_m466_Pkv0,&internal1_m466_Pkav0,&internal1_m466_Zkv0,&internal1_m466_Zkav0,&internal1_m466_txNm,&internal1_m466_txSm,&internal1_m466_txHr,&internal1_m466_txLd,&internal1_m466_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_460_1 = {&R0MD34LP1,&var756,&var756,&var376,&var375,&R1VS12LDU,&R1VS22LDU,&R1IS11LDU,&R1IS11LDU,&R1IS21LDU,&R1IS21LDU,&bRM_0_,&fEM_R1UZ05RDU,&fEM_R1UZ03RDU,&fEM_R1UZ04RDU,&var1423,&var1424,&var1425,&var1426,&var1427,&var1428,&vainSBool,&vainSBool,&var1429,&var1430,&var1431,&internal1_m460_DvUp0,&internal1_m460_DvDw0,&internal1_m460_FDvUp0,&internal1_m460_FDvDw0,&internal1_m460_BlDv0,&internal1_m460_Pkv0,&internal1_m460_Pkav0,&internal1_m460_Zkv0,&internal1_m460_Zkav0,&internal1_m460_txNm,&internal1_m460_txSm,&internal1_m460_txHr,&internal1_m460_txLd,&internal1_m460_fef,&bFirstEnterFlag};
_S_orn  S_orn_866_1 = {array_m866_x_1,&iRM_10_,&var1432};
_S_noto  S_noto_865_1 = {&var1459,&var1433};
_S_noto  S_noto_864_1 = {&var1469,&var1434};
_S_noto  S_noto_846_1 = {&var961,&var1435};
_S_noto  S_noto_856_1 = {&R8IS11LDU,&var1436};
_S_charint  S_charint_803_1 = {&var1439,&var1437};
_S_ornc  S_ornc_809_1 = {array_m809_x_1,&iRM_3_,&var1438,&var1439};
_S_fsumz  S_fsumz_804_1 = {&var1437,&iRM_1_,&var1440};
_S_cnshd  S_cnshd_813_1 = {&R0MD34LP1,&var1734,&var989,&var989,&var1438,&var705,&var619,&iRM_2_,array_m813_Lt_fw_1,array_m813_Vr_fw_1,&iRM_1_,array_m813_Lt_bw_1,array_m813_Vr_bw_1,&fEM_A2UC08RDU,&fEM_A2UC07RDU,&fEM_A2UL01RDU,&fEM_A2UC02RDU,&var1441,&vainSBool,&var1442,&var1443,&var1444,&var1445,&var1446,&var1447,&var1448,&var1449,&var1450,&var1451,&internal1_m813_X0,&internal1_m813_t0,&internal1_m813_BLDv0};
_S_fnapb  S_fnapb_833_1 = {&var1734,&var989,&var701,&R0MD34LP1,&var1443,&var1450,&fEM_B8UV04RDU,&fEM_A2UV01RDU,&fEM_A2UV02RDU,&fEM_A2UC06RDU,&fEM_A2UC05RDU,&iRM_80_,&fEM_A2UL04RDU,&fEM_A2UL05RDU,&fEM_A2UL83RDU,&var1452,&var1453,&var1454,&var1455,&var1456,&var1457,&var1458,&vainSFloat,&internal1_m833_xptr,array_m833_x0_1,array_m833_tim0_1,&internal1_m833_sumtim,&internal1_m833_StSpeed,&internal1_m833_Vz0,&internal1_m833_flRazg,&internal1_m833_DelSp,&internal1_m833_z0,&internal1_m833_txZS,&internal1_m833_tx,&internal1_m833_txd,&internal1_m833_txMBl,&internal1_m833_txBl,&internal1_m833_Speed0,&internal1_m833_xz0,&internal1_m833_tz0,&internal1_m833_Shift0,&internal1_m833_ShCntlSp0,&internal1_m833_ShiftControl,&bFirstEnterFlag};
_S_cnshd  S_cnshd_1592_1 = {&R0MD34LP1,&var1725,&var311,&var311,&var528,&var531,&lRM_1_,&iRM_1_,array_m1592_Lt_fw_1,array_m1592_Vr_fw_1,&iRM_1_,array_m1592_Lt_bw_1,array_m1592_Vr_bw_1,&fEM_B8UC01RDU,&fEM_B8UC02RDU,&fEM_B8UL01RDU,&fRM_0_0,&var1459,&vainSBool,&vainSFloat,&var1460,&var1461,&var1462,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1463,&internal1_m1592_X0,&internal1_m1592_t0,&internal1_m1592_BLDv0};
_S_newstage  S_newstage_1253_1 = {&var1477,&var1438,&var1482,&var1441,&var1464};
_S_orn  S_orn_1283_1 = {array_m1283_x_1,&iRM_10_,&var1465};
_S_orn  S_orn_152_1 = {array_m152_x_1,&iRM_5_,&var1466};
_S_noto  S_noto_1282_1 = {&var1459,&var1467};
_S_noto  S_noto_1281_1 = {&var1469,&var1468};
_S_cnshd  S_cnshd_1116_1 = {&R0MD34LP1,&var1722,&var311,&var311,&var846,&var529,&lRM_1_,&iRM_1_,array_m1116_Lt_fw_1,array_m1116_Vr_fw_1,&iRM_1_,array_m1116_Lt_bw_1,array_m1116_Vr_bw_1,&fEM_B8UC01RDU,&fEM_B8UC02RDU,&fEM_B8UL01RDU,&fRM_0_0,&var1469,&vainSBool,&vainSFloat,&var1470,&var1471,&var1472,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1473,&internal1_m1116_X0,&internal1_m1116_t0,&internal1_m1116_BLDv0};
_S_noto  S_noto_1264_1 = {&var961,&var1474};
_S_noto  S_noto_1273_1 = {&R8IS11LDU,&var1475};
_S_charint  S_charint_1203_1 = {&var1478,&var1476};
_S_ornc  S_ornc_1211_1 = {array_m1211_x_1,&iRM_3_,&var1477,&var1478};
_S_noto  S_noto_606_1 = {&lEM_R0MD01LC1,&var1479};
_S_fsumz  S_fsumz_1204_1 = {&var1476,&iRM_1_,&var1480};
_S_rs  S_rs_619_1 = {&var797,&var799,&var1481,&vainSBool,&internal1_m619_q0};
_S_cnshd  S_cnshd_1213_1 = {&R0MD34LP1,&var1737,&var988,&var988,&var1477,&var622,&var615,&iRM_2_,array_m1213_Lt_fw_1,array_m1213_Vr_fw_1,&iRM_1_,array_m1213_Lt_bw_1,array_m1213_Vr_bw_1,&fEM_A2UC08RDU,&fEM_A2UC07RDU,&fEM_A2UL01RDU,&fEM_A2UC02RDU,&var1482,&vainSBool,&var1483,&var1484,&var1485,&var1486,&var1487,&var1488,&var1489,&var1490,&var1491,&var1492,&internal1_m1213_X0,&internal1_m1213_t0,&internal1_m1213_BLDv0};
_S_zpfs  S_zpfs_1233_1 = {&var1501,&fRM_2_0,&var1493,&internal1_m1233_tx,&internal1_m1233_y0};
_S_zpfs  S_zpfs_1242_1 = {&var1500,&fRM_3_0,&var1494,&internal1_m1242_tx,&internal1_m1242_y0};
_S_fnapb  S_fnapb_1248_1 = {&var1737,&var988,&var623,&R0MD34LP1,&var1484,&var1491,&fEM_B8UV04RDU,&fEM_A2UV01RDU,&fEM_A2UV02RDU,&fEM_A2UC06RDU,&fEM_A2UC05RDU,&iRM_80_,&fEM_A2UL04RDU,&fEM_A2UL05RDU,&fEM_A2UL03RDU,&var1495,&var1496,&var1497,&var1498,&var1499,&var1500,&var1501,&vainSFloat,&internal1_m1248_xptr,array_m1248_x0_1,array_m1248_tim0_1,&internal1_m1248_sumtim,&internal1_m1248_StSpeed,&internal1_m1248_Vz0,&internal1_m1248_flRazg,&internal1_m1248_DelSp,&internal1_m1248_z0,&internal1_m1248_txZS,&internal1_m1248_tx,&internal1_m1248_txd,&internal1_m1248_txMBl,&internal1_m1248_txBl,&internal1_m1248_Speed0,&internal1_m1248_xz0,&internal1_m1248_tz0,&internal1_m1248_Shift0,&internal1_m1248_ShCntlSp0,&internal1_m1248_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_1577_1 = {&R8IS11LDU,&var1502};
_S_rs  S_rs_639_1 = {&var800,&var801,&var1503,&vainSBool,&internal1_m639_q0};
_S_zpfs  S_zpfs_1605_1 = {&var1514,&fRM_2_0,&var1504,&internal1_m1605_tx,&internal1_m1605_y0};
_S_zpfs  S_zpfs_1607_1 = {&var1513,&fRM_3_0,&var1505,&internal1_m1607_tx,&internal1_m1607_y0};
_S_samhd  S_samhd_1595_1 = {&R0MD34LP1,&var531,&var531,&var1461,&var1462,&var1508,&var1509,&A8IS12LDU,&A8IS12LDU,&A8IS22LDU,&A8IS22LDU,&bRM_3_,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&fEM_B8UL07RDU,&vainSBool,&vainSBool,&var1506,&var1507,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,&internal1_m1595_DvUp0,&internal1_m1595_DvDw0,&internal1_m1595_FDvUp0,&internal1_m1595_FDvDw0,&internal1_m1595_BlDv0,&internal1_m1595_Pkv0,&internal1_m1595_Pkav0,&internal1_m1595_Zkv0,&internal1_m1595_Zkav0,&internal1_m1595_txNm,&internal1_m1595_txSm,&internal1_m1595_txHr,&internal1_m1595_txLd,&internal1_m1595_fef,&bFirstEnterFlag};
_S_fnapb  S_fnapb_1612_1 = {&var1725,&var311,&var527,&R0MD34LP1,&var1460,&fEM_B8UV03RDU,&fEM_B8UV04RDU,&fEM_B8UV01RDU,&fEM_B8UV02RDU,&fEM_B8UC06RDU,&fEM_B8UC05RDU,&iRM_20_,&fEM_B8UL04RDU,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&var1508,&var1509,&var1510,&var1511,&var1512,&var1513,&var1514,&vainSFloat,&internal1_m1612_xptr,array_m1612_x0_1,array_m1612_tim0_1,&internal1_m1612_sumtim,&internal1_m1612_StSpeed,&internal1_m1612_Vz0,&internal1_m1612_flRazg,&internal1_m1612_DelSp,&internal1_m1612_z0,&internal1_m1612_txZS,&internal1_m1612_tx,&internal1_m1612_txd,&internal1_m1612_txMBl,&internal1_m1612_txBl,&internal1_m1612_Speed0,&internal1_m1612_xz0,&internal1_m1612_tz0,&internal1_m1612_Shift0,&internal1_m1612_ShCntlSp0,&internal1_m1612_ShiftControl,&bFirstEnterFlag};
_S_zpfs  S_zpfs_1129_1 = {&var1531,&fRM_2_0,&var1515,&internal1_m1129_tx,&internal1_m1129_y0};
_S_zpfs  S_zpfs_1133_1 = {&var1530,&fRM_3_0,&var1516,&internal1_m1133_tx,&internal1_m1133_y0};
_S_noto  S_noto_1098_1 = {&R8IS11LDU,&var1517};
_S_orn  S_orn_1084_1 = {array_m1084_x_1,&iRM_8_,&var1518};
_S_noto  S_noto_608_1 = {&var1522,&var1519};
_S_rs  S_rs_629_1 = {&var802,&var803,&var1520,&vainSBool,&internal1_m629_q0};
_S_orn  S_orn_596_1 = {array_m596_x_1,&iRM_18_,&var1521};
_S_rs  S_rs_594_1 = {&var1286,&var918,&var1522,&vainSBool,&internal1_m594_q0};
_S_samhd  S_samhd_1119_1 = {&R0MD34LP1,&var529,&var529,&var1471,&var1472,&var1525,&var1526,&var154,&var154,&var153,&var153,&bRM_3_,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&fEM_B8UL07RDU,&vainSBool,&vainSBool,&var1523,&var1524,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,&internal1_m1119_DvUp0,&internal1_m1119_DvDw0,&internal1_m1119_FDvUp0,&internal1_m1119_FDvDw0,&internal1_m1119_BlDv0,&internal1_m1119_Pkv0,&internal1_m1119_Pkav0,&internal1_m1119_Zkv0,&internal1_m1119_Zkav0,&internal1_m1119_txNm,&internal1_m1119_txSm,&internal1_m1119_txHr,&internal1_m1119_txLd,&internal1_m1119_fef,&bFirstEnterFlag};
_S_fnapb  S_fnapb_1137_1 = {&var1722,&var311,&var845,&R0MD34LP1,&var1470,&fEM_B8UV03RDU,&fEM_B8UV04RDU,&fEM_B8UV01RDU,&fEM_B8UV02RDU,&fEM_B8UC06RDU,&fEM_B8UC05RDU,&iRM_20_,&fEM_B8UL04RDU,&fEM_B8UL06RDU,&fEM_B8UL03RDU,&var1525,&var1526,&var1527,&var1528,&var1529,&var1530,&var1531,&vainSFloat,&internal1_m1137_xptr,array_m1137_x0_1,array_m1137_tim0_1,&internal1_m1137_sumtim,&internal1_m1137_StSpeed,&internal1_m1137_Vz0,&internal1_m1137_flRazg,&internal1_m1137_DelSp,&internal1_m1137_z0,&internal1_m1137_txZS,&internal1_m1137_tx,&internal1_m1137_txd,&internal1_m1137_txMBl,&internal1_m1137_txBl,&internal1_m1137_Speed0,&internal1_m1137_xz0,&internal1_m1137_tz0,&internal1_m1137_Shift0,&internal1_m1137_ShCntlSp0,&internal1_m1137_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_719_1 = {&A5IS21LDU,&var1532};
_S_vmemb  S_vmemb_742_1 = {&var1534,&var1533,&internal1_m742_x0};
_S_noto  S_noto_750_1 = {&var155,&var1534};
_S_vmemb  S_vmemb_711_1 = {&var1532,&var1535,&internal1_m711_x0};
_S_vmemb  S_vmemb_675_1 = {&var1550,&var1536,&internal1_m675_x0};
_S_newstage  S_newstage_785_1 = {&var1594,&var1585,&var1593,&var1584,&var1537};
_S_newstage  S_newstage_1182_1 = {&var1576,&var1567,&var1575,&var1566,&var1538};
_S_newstage  S_newstage_391_1 = {&var1621,&var1612,&var1620,&var1611,&var1539};
_S_noto  S_noto_761_1 = {&var156,&var1540};
_S_rs  S_rs_767_1 = {&var866,&var1539,&var1541,&vainSBool,&internal1_m767_q0};
_S_rs  S_rs_762_1 = {&var867,&var967,&var1542,&vainSBool,&internal1_m762_q0};
_S_noto  S_noto_754_1 = {&var1623,&var1543};
_S_noto  S_noto_752_1 = {&var1624,&var1544};
_S_rs  S_rs_730_1 = {&var871,&var1539,&var1545,&vainSBool,&internal1_m730_q0};
_S_rs  S_rs_735_1 = {&var870,&var1537,&var1546,&vainSBool,&internal1_m735_q0};
_S_rs  S_rs_743_1 = {&var937,&var876,&var1547,&vainSBool,&internal1_m743_q0};
_S_rs  S_rs_755_1 = {&var868,&var874,&var1548,&vainSBool,&internal1_m755_q0};
_S_noto  S_noto_710_1 = {&var156,&var1549};
_S_noto  S_noto_666_1 = {&var155,&var1550};
_S_noto  S_noto_422_1 = {&R8IS11LDU,&var1551};
_S_orn  S_orn_436_1 = {array_m436_x_1,&iRM_7_,&var1552};
_S_orn  S_orn_418_1 = {array_m418_x_1,&iRM_7_,&var1553};
_S_rs  S_rs_733_1 = {&var875,&var880,&var1554,&vainSBool,&internal1_m733_q0};
_S_noto  S_noto_160_1 = {&B2IS12LDU,&var1555};
_S_noto  S_noto_149_1 = {&A2IS12LDU,&var1556};
_S_noto  S_noto_150_1 = {&B1IS12LDU,&var1557};
_S_noto  S_noto_158_1 = {&A1IS12LDU,&var1558};
_S_samhd  S_samhd_1190_1 = {&var849,&var850,&var850,&var1159,&var1158,&var1159,&var1158,&B4IS11LDU,&B4IS11LDU,&B4IS21LDU,&B4IS21LDU,&bRM_1_,&fEM_A4UZ05RDU,&fEM_A4UZ03RDU,&fEM_A4UZ04RDU,&var1559,&var1560,&vainSBool,&var1561,&var1562,&vainSBool,&var1563,&var1564,&var1565,&var1566,&var1567,&internal1_m1190_DvUp0,&internal1_m1190_DvDw0,&internal1_m1190_FDvUp0,&internal1_m1190_FDvDw0,&internal1_m1190_BlDv0,&internal1_m1190_Pkv0,&internal1_m1190_Pkav0,&internal1_m1190_Zkv0,&internal1_m1190_Zkav0,&internal1_m1190_txNm,&internal1_m1190_txSm,&internal1_m1190_txHr,&internal1_m1190_txLd,&internal1_m1190_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_1179_1 = {&var849,&var852,&var852,&var1159,&var1158,&var1159,&var1158,&A4IS11LDU,&A4IS11LDU,&A4IS21LDU,&A4IS21LDU,&bRM_1_,&fEM_A4UZ05RDU,&fEM_A4UZ03RDU,&fEM_A4UZ04RDU,&var1568,&var1569,&vainSBool,&var1570,&var1571,&vainSBool,&var1572,&var1573,&var1574,&var1575,&var1576,&internal1_m1179_DvUp0,&internal1_m1179_DvDw0,&internal1_m1179_FDvUp0,&internal1_m1179_FDvDw0,&internal1_m1179_BlDv0,&internal1_m1179_Pkv0,&internal1_m1179_Pkav0,&internal1_m1179_Zkv0,&internal1_m1179_Zkav0,&internal1_m1179_txNm,&internal1_m1179_txSm,&internal1_m1179_txHr,&internal1_m1179_txLd,&internal1_m1179_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_787_1 = {&R0MD34LP1,&var707,&var707,&var968,&var863,&B5VS12LDU,&B5VS22LDU,&B5IS11LDU,&B5IS11LDU,&B5IS21LDU,&B5IS21LDU,&bRM_0_,&fEM_A5UZ05RDU,&fEM_A5UZ03RDU,&fEM_A5UZ04RDU,&var1577,&var1578,&var1579,&var1580,&var1581,&var1582,&vainSBool,&vainSBool,&var1583,&var1584,&var1585,&internal1_m787_DvUp0,&internal1_m787_DvDw0,&internal1_m787_FDvUp0,&internal1_m787_FDvDw0,&internal1_m787_BlDv0,&internal1_m787_Pkv0,&internal1_m787_Pkav0,&internal1_m787_Zkv0,&internal1_m787_Zkav0,&internal1_m787_txNm,&internal1_m787_txSm,&internal1_m787_txHr,&internal1_m787_txLd,&internal1_m787_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_783_1 = {&R0MD34LP1,&var709,&var709,&var968,&var863,&A5VS12LDU,&A5VS22LDU,&A5IS11LDU,&A5IS11LDU,&A5IS21LDU,&A5IS21LDU,&bRM_0_,&fEM_A5UZ05RDU,&fEM_A5UZ03RDU,&fEM_A5UZ04RDU,&var1586,&var1587,&var1588,&var1589,&var1590,&var1591,&vainSBool,&vainSBool,&var1592,&var1593,&var1594,&internal1_m783_DvUp0,&internal1_m783_DvDw0,&internal1_m783_FDvUp0,&internal1_m783_FDvDw0,&internal1_m783_BlDv0,&internal1_m783_Pkv0,&internal1_m783_Pkav0,&internal1_m783_Zkv0,&internal1_m783_Zkav0,&internal1_m783_txNm,&internal1_m783_txSm,&internal1_m783_txHr,&internal1_m783_txLd,&internal1_m783_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_365_1 = {&R0MD34LP1,&var380,&var379,&var872,&var865,&R4VS12LDU,&R4VS22LDU,&R4IS11LDU,&R4IS12LDU,&R4IS21LDU,&R4IS22LDU,&bRM_0_,&fEM_R4UZ05RDU,&fEM_R4UZ03RDU,&fEM_R4UZ04RDU,&var1595,&var1596,&var1597,&var1598,&var1599,&var1600,&vainSBool,&vainSBool,&var1601,&var1602,&vainSBool,&internal1_m365_DvUp0,&internal1_m365_DvDw0,&internal1_m365_FDvUp0,&internal1_m365_FDvDw0,&internal1_m365_BlDv0,&internal1_m365_Pkv0,&internal1_m365_Pkav0,&internal1_m365_Zkv0,&internal1_m365_Zkav0,&internal1_m365_txNm,&internal1_m365_txSm,&internal1_m365_txHr,&internal1_m365_txLd,&internal1_m365_fef,&bFirstEnterFlag};
_S_noto  S_noto_677_1 = {&R8IS11LDU,&var1603};
_S_samhd  S_samhd_394_1 = {&R0MD34LP1,&var1552,&var938,&var944,&var864,&B6VS12LDU,&B6VS22LDU,&B6IS11LDU,&B6IS11LDU,&B6IS21LDU,&B6IS21LDU,&bRM_0_,&fEM_A6UZ05RDU,&fEM_A6UZ03RDU,&fEM_A6UZ04RDU,&var1604,&var1605,&var1606,&var1607,&var1608,&var1609,&vainSBool,&vainSBool,&var1610,&var1611,&var1612,&internal1_m394_DvUp0,&internal1_m394_DvDw0,&internal1_m394_FDvUp0,&internal1_m394_FDvDw0,&internal1_m394_BlDv0,&internal1_m394_Pkv0,&internal1_m394_Pkav0,&internal1_m394_Zkv0,&internal1_m394_Zkav0,&internal1_m394_txNm,&internal1_m394_txSm,&internal1_m394_txHr,&internal1_m394_txLd,&internal1_m394_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_388_1 = {&R0MD34LP1,&var1553,&var939,&var944,&var864,&A6VS12LDU,&A6VS22LDU,&A6IS11LDU,&A6IS11LDU,&A6IS21LDU,&A6IS21LDU,&bRM_0_,&fEM_A6UZ05RDU,&fEM_A6UZ03RDU,&fEM_A6UZ04RDU,&var1613,&var1614,&var1615,&var1616,&var1617,&var1618,&vainSBool,&vainSBool,&var1619,&var1620,&var1621,&internal1_m388_DvUp0,&internal1_m388_DvDw0,&internal1_m388_FDvUp0,&internal1_m388_FDvDw0,&internal1_m388_BlDv0,&internal1_m388_Pkv0,&internal1_m388_Pkav0,&internal1_m388_Zkv0,&internal1_m388_Zkav0,&internal1_m388_txNm,&internal1_m388_txSm,&internal1_m388_txHr,&internal1_m388_txLd,&internal1_m388_fef,&bFirstEnterFlag};
_S_orn  S_orn_766_1 = {array_m766_x_1,&iRM_17_,&var1622};
_S_rs  S_rs_739_1 = {&var878,&var65,&var1623,&vainSBool,&internal1_m739_q0};
_S_rs  S_rs_736_1 = {&var879,&var66,&var1624,&vainSBool,&internal1_m736_q0};
_S_orni  S_orni_138_1 = {array_m138_x_1,&iRM_21_,&var1625,&vainSLong};
_S_equz_p  S_equz_p_80_1 = {&R0MW11IP2,&iRM_6_,&var1626};
_S_equz_p  S_equz_p_78_1 = {&R0MW11IP2,&iRM_5_,&var1627};
_S_equz_p  S_equz_p_76_1 = {&R0MW11IP2,&iRM_4_,&var1628};
_S_equz_p  S_equz_p_75_1 = {&R0MW11IP2,&iRM_3_,&var1629};
_S_equz_p  S_equz_p_74_1 = {&R0MW11IP2,&iRM_2_,&var1630};
_S_equz_p  S_equz_p_71_1 = {&R0MW11IP2,&iRM_1_,&var1631};
_S_equz_p  S_equz_p_67_1 = {&R0MW14IP1,&iRM_3_,&var1632};
_S_equz_p  S_equz_p_61_1 = {&R0MW14IP1,&iRM_1_,&vainSBool};
_S_equz_p  S_equz_p_63_1 = {&R0MW14IP1,&iRM_2_,&var1633};
_S_equz_p  S_equz_p_56_1 = {&R0MW11IP1,&iRM_3_,&var1634};
_S_equz_p  S_equz_p_49_1 = {&R0MW11IP1,&iRM_1_,&var1635};
_S_equz_p  S_equz_p_52_1 = {&R0MW11IP1,&iRM_2_,&var1636};
_S_equz_p  S_equz_p_106_1 = {&R0MW16IP1,&iRM_11_,&var1637};
_S_equz_p  S_equz_p_99_1 = {&R0MW16IP1,&iRM_4_,&var1638};
_S_equz_p  S_equz_p_98_1 = {&R0MW16IP1,&iRM_3_,&var1639};
_S_equz_p  S_equz_p_97_1 = {&R0MW16IP1,&iRM_2_,&var1640};
_S_equz_p  S_equz_p_10_1 = {&R0MW12IP1,&iRM_4_,&var1641};
_S_equz_p  S_equz_p_7_1 = {&R0MW12IP1,&iRM_3_,&var1642};
_S_equz_p  S_equz_p_2_1 = {&R0MW12IP1,&iRM_1_,&var1643};
_S_equz_p  S_equz_p_4_1 = {&R0MW12IP1,&iRM_2_,&var1644};


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
  setData(idR0EE02LDU,&var816);
  setData(idB8VC01RDU,&var1722);
  setData(idB2VC01RDU,&var1734);
  setData(idA2VC01RDU,&var1737);
  setData(idA3VC01RDU,&var1731);
  setData(idB0VS11LDU,&var1699);
  setData(idA0VS11LDU,&var1700);
  setData(idB0VN01LDU,&var1669);
  setData(idA0VN01LDU,&var1671);
  setData(idB0VP01LDU,&var1705);
  setData(idA0VP01LDU,&var1706);
  setData(idB0VE01LDU,&var1696);
  setData(idA0VE01LDU,&var1698);
  setData(idA3VP82LDU,&var1667);
  setData(idB3VP82LDU,&var1690);
  setData(idB3VP52LDU,&var1715);
  setData(idB3CP02RDU,&var1691);
  setData(idB3VP42LDU,&var1665);
  setData(idA3VP52LDU,&var1718);
  setData(idA3CP02RDU,&var1692);
  setData(idA3VP42LDU,&var1666);
  setData(idA1VC01RDU,&var1719);
  setData(idA8VC01RDU,&var1725);
  setData(idB3VC01RDU,&var1728);
  setData(idB1VC01RDU,&var1741);
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
  noto(&S_noto_752_1);
  noto(&S_noto_719_1);
  noto(&S_noto_1098_1);
  noto(&S_noto_1577_1);
  noto(&S_noto_1273_1);
  noto(&S_noto_856_1);
  noto(&S_noto_224_1);
  noto(&S_noto_541_1);
  noto(&S_noto_951_1);
  rs(&S_rs_624_1);
  noto(&S_noto_1363_1);
  equz_p(&S_equz_p_38_1);
  equz_p(&S_equz_p_47_1);
  noto(&S_noto_40_1);
  equz_p(&S_equz_p_43_1);
  rs(&S_rs_1487_1);
  noto(&S_noto_1782_1);
  noto(&S_noto_1781_1);
  noto(&S_noto_1787_1);
  noto(&S_noto_1783_1);
  noto(&S_noto_1789_1);
  noto(&S_noto_1760_1);
  noto(&S_noto_1761_1);
  noto(&S_noto_1762_1);
  noto(&S_noto_1763_1);
  noto(&S_noto_1764_1);
  noto(&S_noto_2078_1);
  equz_p(&S_equz_p_100_1);
  equz_p(&S_equz_p_101_1);
  equz_p(&S_equz_p_102_1);
  noto(&S_noto_928_1);
  equz_p(&S_equz_p_103_1);
  equz_p(&S_equz_p_104_1);
  noto(&S_noto_184_1);
  equz_p(&S_equz_p_105_1);
  noto(&S_noto_12_1);
  noto(&S_noto_1862_1);
  equz_p(&S_equz_p_1804_1);
  equz_p(&S_equz_p_1803_1);
  equz_p(&S_equz_p_1805_1);
  equz_p(&S_equz_p_1806_1);
  equz_p(&S_equz_p_1807_1);
  noto(&S_noto_1769_1);
  noto(&S_noto_1822_1);
  noto(&S_noto_1841_1);
  rs(&S_rs_614_1);
  noto(&S_noto_1801_1);
  noto(&S_noto_1827_1);
  noto(&S_noto_1340_1);
  rsun(&S_rsun_1413_1);
  rs(&S_rs_616_1);
  rs(&S_rs_618_1);
  rs(&S_rs_634_1);
  rs(&S_rs_651_1);
  rs(&S_rs_623_1);
  rs(&S_rs_638_1);
  rs(&S_rs_29_1);
  rs(&S_rs_1482_1);
  rs(&S_rs_1437_1);
  rs(&S_rs_1895_1);
  noto(&S_noto_1432_1);
  noto(&S_noto_1472_1);
  noto(&S_noto_1477_1);
  noto(&S_noto_1853_1);
  noto(&S_noto_1890_1);
  noto(&S_noto_1909_1);
  noto(&S_noto_1875_1);
  noto(&S_noto_585_1);
  noto(&S_noto_25_1);
  noto(&S_noto_26_1);
  noto(&S_noto_27_1);
  noto(&S_noto_28_1);
  noto(&S_noto_588_1);
  noto(&S_noto_586_1);
  noto(&S_noto_55_1);
  noto(&S_noto_264_1);
  noto(&S_noto_267_1);
  noto(&S_noto_276_1);
  noto(&S_noto_280_1);
  noto(&S_noto_272_1);
  noto(&S_noto_985_1);
  noto(&S_noto_991_1);
  noto(&S_noto_1944_1);
  noto(&S_noto_1946_1);
  rs(&S_rs_1068_1);
  rs(&S_rs_1071_1);
  rs(&S_rs_1074_1);
  rs(&S_rs_1077_1);
  ovbs(&S_ovbs_1188_1);
  ovbs(&S_ovbs_2100_1);
  sr(&S_sr_1061_1);
  bol(&S_bol_1055_1);
  ma(&S_ma_90_1);
  sr(&S_sr_88_1);
  bol(&S_bol_261_1);
  bol(&S_bol_259_1);
  bol(&S_bol_1392_1);
  bol(&S_bol_1390_1);
  bol(&S_bol_980_1);
  bol(&S_bol_978_1);
  bol(&S_bol_573_1);
  bol(&S_bol_575_1);
  bol(&S_bol_584_1);
  bol(&S_bol_590_1);
  and2(&S_and2_740_1);
  and2(&S_and2_30_1);
  and2(&S_and2_31_1);
  and2(&S_and2_32_1);
  and2(&S_and2_33_1);
  and2(&S_and2_48_1);
  and2(&S_and2_44_1);
  and2(&S_and2_731_1);
  or4(&S_or4_421_1);
  or2(&S_or2_744_1);
  or3(&S_or3_5_1);
  or2(&S_or2_6_1);
  or2(&S_or2_1286_1);
  or2(&S_or2_869_1);
  or2(&S_or2_238_1);
  or2(&S_or2_555_1);
  or2(&S_or2_963_1);
  or2(&S_or2_1375_1);
  or2(&S_or2_1060_1);
  and2(&S_and2_1054_1);
  or2(&S_or2_23_1);
  or2(&S_or2_45_1);
  or2(&S_or2_41_1);
  or2(&S_or2_54_1);
  or2(&S_or2_691_1);
  or3(&S_or3_679_1);
  or4(&S_or4_693_1);
  or2(&S_or2_706_1);
  or3(&S_or3_726_1);
  and2(&S_and2_751_1);
  and2(&S_and2_725_1);
  or2(&S_or2_732_1);
  or2(&S_or2_661_1);
  or2(&S_or2_663_1);
  or2(&S_or2_665_1);
  or2(&S_or2_1155_1);
  or2(&S_or2_1189_1);
  and4(&S_and4_1066_1);
  or2(&S_or2_1065_1);
  and2(&S_and2_1080_1);
  or2(&S_or2_1094_1);
  and3(&S_and3_265_1);
  and3(&S_and3_283_1);
  or2(&S_or2_607_1);
  or2(&S_or2_615_1);
  or2(&S_or2_617_1);
  or2(&S_or2_620_1);
  or2(&S_or2_591_1);
  and2(&S_and2_641_1);
  or2(&S_or2_648_1);
  and2(&S_and2_612_1);
  or2(&S_or2_627_1);
  or2(&S_or2_622_1);
  or2(&S_or2_645_1);
  and2(&S_and2_602_1);
  or2(&S_or2_347_1);
  or2(&S_or2_352_1);
  or2(&S_or2_749_1);
  or2(&S_or2_463_1);
  or2(&S_or2_521_1);
  and2(&S_and2_530_1);
  and2(&S_and2_531_1);
  and2(&S_and2_540_1);
  or2(&S_or2_533_1);
  or2(&S_or2_202_1);
  and2(&S_and2_182_1);
  and2(&S_and2_214_1);
  and2(&S_and2_213_1);
  or2(&S_or2_216_1);
  and2(&S_and2_223_1);
  or2(&S_or2_786_1);
  or2(&S_or2_832_1);
  or2(&S_or2_845_1);
  and2(&S_and2_922_1);
  or2(&S_or2_933_1);
  or2(&S_or2_925_1);
  or2(&S_or2_942_1);
  or2(&S_or2_1353_1);
  or2(&S_or2_1337_1);
  and2(&S_and2_1334_1);
  or2(&S_or2_1345_1);
  or2(&S_or2_1263_1);
  or2(&S_or2_1245_1);
  and2(&S_and2_990_1);
  and2(&S_and2_1433_1);
  zpfs(&S_zpfs_1443_1);
  and2(&S_and2_1473_1);
  zpfs(&S_zpfs_1493_1);
  and2(&S_and2_1478_1);
  zpfs(&S_zpfs_1499_1);
  and2(&S_and2_1515_1);
  or2(&S_or2_2101_1);
  or2(&S_or2_1622_1);
  or2(&S_or2_1623_1);
  or2(&S_or2_1573_1);
  or2(&S_or2_1767_1);
  or2(&S_or2_1768_1);
  or4(&S_or4_1774_1);
  or4(&S_or4_1775_1);
  or2(&S_or2_1777_1);
  or2(&S_or2_1771_1);
  or2(&S_or2_1770_1);
  or3(&S_or3_1779_1);
  and2(&S_and2_1808_1);
  or2(&S_or2_1809_1);
  and2(&S_and2_1815_1);
  and2(&S_and2_1831_1);
  or2(&S_or2_1842_1);
  zpfs(&S_zpfs_1811_1);
  zpfs(&S_zpfs_1812_1);
  zpfs(&S_zpfs_1813_1);
  zpfs(&S_zpfs_1814_1);
  or2(&S_or2_1817_1);
  and2(&S_and2_1818_1);
  or2(&S_or2_1833_1);
  or3(&S_or3_1819_1);
  or2(&S_or2_1896_1);
  ma(&S_ma_1468_1);
  zpfs(&S_zpfs_1866_1);
  and2(&S_and2_1867_1);
  or2(&S_or2_1861_1);
  and3(&S_and3_1864_1);
  or2(&S_or2_1872_1);
  or2(&S_or2_240_1);
  ovbs(&S_ovbs_83_1);
  ovbs(&S_ovbs_24_1);
  ovbs(&S_ovbs_126_1);
  ovbs(&S_ovbs_119_1);
  ovbs(&S_ovbs_1427_1);
  ovbs(&S_ovbs_747_1);
  ovbs(&S_ovbs_298_1);
  ovbs(&S_ovbs_343_1);
  ovbs(&S_ovbs_57_1);
  or2(&S_or2_2008_1);
  or2(&S_or2_1996_1);
  noto(&S_noto_2026_1);
  bol(&S_bol_1561_1);
  bol(&S_bol_1552_1);
  or2(&S_or2_1555_1);
  bol(&S_bol_1541_1);
  bol(&S_bol_1530_1);
  or2(&S_or2_1540_1);
  bol(&S_bol_1559_1);
  bol(&S_bol_1553_1);
  or2(&S_or2_1558_1);
  bol(&S_bol_1545_1);
  bol(&S_bol_1534_1);
  or2(&S_or2_1544_1);
  and4(&S_and4_51_1);
  abs_subf(&S_abs_subf_1550_1);
  noto(&S_noto_1556_1);
  and2(&S_and2_239_1);
  and2(&S_and2_556_1);
  and2(&S_and2_2256_1);
  rs(&S_rs_2205_1);
  sr(&S_sr_2243_1);
  sr(&S_sr_2222_1);
  rs(&S_rs_2199_1);
  zpfs(&S_zpfs_2227_1);
  or2(&S_or2_2214_1);
  abs_subf(&S_abs_subf_2180_1);
  and2(&S_and2_2188_1);
  noto(&S_noto_898_1);
  zzfs(&S_zzfs_2189_1);
  noto(&S_noto_2200_1);
  or2(&S_or2_1078_1);
  or2(&S_or2_372_1);
  or2(&S_or2_355_1);
  or2(&S_or2_1110_1);
  or2(&S_or2_1115_1);
  or2(&S_or2_236_1);
  or2(&S_or2_553_1);
  nocnm(&S_nocnm_1718_1);
  nocnm(&S_nocnm_1720_1);
  noto(&S_noto_1675_1);
  noto(&S_noto_1677_1);
  noto(&S_noto_2172_1);
  noto(&S_noto_2140_1);
  or2(&S_or2_1440_1);
  or2(&S_or2_1471_1);
  noto(&S_noto_2175_1);
  noto(&S_noto_2143_1);
  noto(&S_noto_113_1);
  and2(&S_and2_728_1);
  and2(&S_and2_729_1);
  or2(&S_or2_133_1);
  noto(&S_noto_1736_1);
  noto(&S_noto_1737_1);
  or2(&S_or2_1700_1);
  or2(&S_or2_1740_1);
  or2(&S_or2_1743_1);
  or2(&S_or2_1711_1);
  or2(&S_or2_1714_1);
  or2(&S_or2_1671_1);
  or2(&S_or2_1645_1);
  or2(&S_or2_1641_1);
  or2(&S_or2_2167_1);
  or2(&S_or2_2171_1);
  or2(&S_or2_2169_1);
  or2(&S_or2_2135_1);
  or2(&S_or2_2137_1);
  or2(&S_or2_2139_1);
  noto(&S_noto_1674_1);
  or2(&S_or2_1663_1);
  or2(&S_or2_1661_1);
  noto(&S_noto_1676_1);
  or2(&S_or2_1698_1);
  diagndev(&S_diagndev_2301_1);
  and2(&S_and2_2306_1);
  or2(&S_or2_2315_1);
  or2(&S_or2_2322_1);
  orn(&S_orn_2317_1);
  or3(&S_or3_2318_1);
  noto(&S_noto_1846_1);
  noto(&S_noto_1849_1);
  noto(&S_noto_677_1);
  noto(&S_noto_158_1);
  rs(&S_rs_733_1);
  noto(&S_noto_422_1);
  noto(&S_noto_666_1);
  noto(&S_noto_710_1);
  rs(&S_rs_743_1);
  noto(&S_noto_761_1);
  vmemb(&S_vmemb_675_1);
  vmemb(&S_vmemb_711_1);
  noto(&S_noto_750_1);
  vmemb(&S_vmemb_742_1);
  rs(&S_rs_629_1);
  rs(&S_rs_639_1);
  rs(&S_rs_619_1);
  noto(&S_noto_606_1);
  rs(&S_rs_647_1);
  noto(&S_noto_263_1);
  noto(&S_noto_642_1);
  noto(&S_noto_577_1);
  noto(&S_noto_982_1);
  noto(&S_noto_1394_1);
  noto(&S_noto_1004_1);
  noto(&S_noto_1919_1);
  kvf(&S_kvf_1491_1);
  noto(&S_noto_84_1);
  samhd(&S_samhd_2099_1);
  samhd(&S_samhd_2105_1);
  newstage(&S_newstage_2103_1);
  noto(&S_noto_1780_1);
  noto(&S_noto_1786_1);
  noto(&S_noto_1788_1);
  noto(&S_noto_1759_1);
  noto(&S_noto_1907_1);
  noto(&S_noto_1899_1);
  noto(&S_noto_1857_1);
  noto(&S_noto_508_1);
  noto(&S_noto_1224_1);
  noto(&S_noto_1240_1);
  noto(&S_noto_1829_1);
  rs(&S_rs_1502_1);
  kvf(&S_kvf_1497_1);
  rs(&S_rs_1496_1);
  noto(&S_noto_1507_1);
  noto(&S_noto_1505_1);
  rs(&S_rs_748_1);
  noto(&S_noto_349_1);
  noto(&S_noto_345_1);
  noto(&S_noto_587_1);
  noto(&S_noto_597_1);
  noto(&S_noto_650_1);
  noto(&S_noto_1928_1);
  noto(&S_noto_1953_1);
  swtakt(&S_swtakt_58_1);
  rs(&S_rs_1070_1);
  and2(&S_and2_758_1);
  and2(&S_and2_11_1);
  and2(&S_and2_118_1);
  and2(&S_and2_235_1);
  and2(&S_and2_552_1);
  or2(&S_or2_17_1);
  or2(&S_or2_8_1);
  or2(&S_or2_172_1);
  and3(&S_and3_704_1);
  and2(&S_and2_671_1);
  or3(&S_or3_738_1);
  and2(&S_and2_734_1);
  and2(&S_and2_656_1);
  or2(&S_or2_271_1);
  and3(&S_and3_287_1);
  or2(&S_or2_640_1);
  and2(&S_and2_609_1);
  and2(&S_and2_599_1);
  and4(&S_and4_600_1);
  and4(&S_and4_610_1);
  and2(&S_and2_635_1);
  or2(&S_or2_643_1);
  or2(&S_or2_646_1);
  and3(&S_and3_340_1);
  and2(&S_and2_505_1);
  or2(&S_or2_510_1);
  and2(&S_and2_562_1);
  and2(&S_and2_574_1);
  or2(&S_or2_188_1);
  and2(&S_and2_248_1);
  and2(&S_and2_260_1);
  and2(&S_and2_979_1);
  and2(&S_and2_1376_1);
  and2(&S_and2_1391_1);
  and2(&S_and2_1222_1);
  or2(&S_or2_1228_1);
  and2(&S_and2_1237_1);
  or2(&S_or2_1247_1);
  and2(&S_and2_999_1);
  and2(&S_and2_1009_1);
  or2(&S_or2_1481_1);
  and2(&S_and2_1444_1);
  and2(&S_and2_1494_1);
  or3(&S_or3_1509_1);
  or2(&S_or2_1490_1);
  and2(&S_and2_1500_1);
  or3(&S_or3_1501_1);
  or3(&S_or3_1514_1);
  or3(&S_or3_2098_1);
  or3(&S_or3_2107_1);
  or2(&S_or2_1776_1);
  or3(&S_or3_1778_1);
  or2(&S_or2_1816_1);
  and2(&S_and2_1824_1);
  or3(&S_or3_1820_1);
  and2(&S_and2_1847_1);
  or2(&S_or2_2049_1);
  or2(&S_or2_1980_1);
  or2(&S_or2_1969_1);
  and2(&S_and2_1949_1);
  and2(&S_and2_1947_1);
  and2(&S_and2_1932_1);
  and2(&S_and2_1931_1);
  and2(&S_and2_1901_1);
  and4(&S_and4_1902_1);
  and4(&S_and4_1908_1);
  or2(&S_or2_1910_1);
  or2(&S_or2_1912_1);
  or2(&S_or2_1911_1);
  zpfs(&S_zpfs_1915_1);
  zpfs(&S_zpfs_1918_1);
  zpfs(&S_zpfs_1903_1);
  and2(&S_and2_1904_1);
  or3(&S_or3_1920_1);
  lk(&S_lk_1492_1);
  rsfn(&S_rsfn_1488_1);
  abs_subf(&S_abs_subf_1503_1);
  lk(&S_lk_1489_1);
  rsfn(&S_rsfn_1485_1);
  abs_subf(&S_abs_subf_1498_1);
  and3(&S_and3_1863_1);
  or2(&S_or2_1870_1);
  or2(&S_or2_1871_1);
  zpfs(&S_zpfs_1877_1);
  zpfs(&S_zpfs_1879_1);
  or3(&S_or3_1882_1);
  or2(&S_or2_1884_1);
  and2(&S_and2_964_1);
  or2(&S_or2_255_1);
  ovbs(&S_ovbs_1885_1);
  ovbs(&S_ovbs_16_1);
  or2(&S_or2_1483_1);
  noto(&S_noto_109_1);
  bol(&S_bol_1538_1);
  bol(&S_bol_1533_1);
  or2(&S_or2_1536_1);
  ml(&S_ml_1547_1);
  ml(&S_ml_1527_1);
  ml(&S_ml_1549_1);
  ml(&S_ml_1528_1);
  and2(&S_and2_124_1);
  noto(&S_noto_122_1);
  and2(&S_and2_128_1);
  and2(&S_and2_127_1);
  noto(&S_noto_196_1);
  noto(&S_noto_468_1);
  noto(&S_noto_915_1);
  noto(&S_noto_1183_1);
  noto(&S_noto_1238_1);
  bol(&S_bol_1794_1);
  and3(&S_and3_1785_1);
  bol(&S_bol_1758_1);
  and3(&S_and3_1766_1);
  noto(&S_noto_1773_1);
  noto(&S_noto_1784_1);
  bol(&S_bol_906_1);
  bol(&S_bol_1320_1);
  abs_subf(&S_abs_subf_1531_1);
  noto(&S_noto_1542_1);
  abs_subf(&S_abs_subf_1551_1);
  noto(&S_noto_1560_1);
  bol(&S_bol_2246_1);
  and2(&S_and2_2255_1);
  noto(&S_noto_2213_1);
  fsumo(&S_fsumo_86_1);
  abs_subf(&S_abs_subf_2252_1);
  and2(&S_and2_2257_1);
  and3(&S_and3_2206_1);
  and2(&S_and2_2228_1);
  ovbs(&S_ovbs_2229_1);
  or3(&S_or3_2237_1);
  inf(&S_inf_2210_1);
  noto(&S_noto_1321_1);
  or2(&S_or2_1069_1);
  and2(&S_and2_2050_1);
  and2(&S_and2_111_1);
  and3(&S_and3_1406_1);
  or2(&S_or2_1669_1);
  noto(&S_noto_2174_1);
  noto(&S_noto_2142_1);
  or2(&S_or2_2133_1);
  rs(&S_rs_739_1);
  noto(&S_noto_754_1);
  noto(&S_noto_1264_1);
  noto(&S_noto_846_1);
  noto(&S_noto_217_1);
  rs(&S_rs_621_1);
  noto(&S_noto_534_1);
  noto(&S_noto_943_1);
  noto(&S_noto_1354_1);
  kvf(&S_kvf_1878_1);
  kvf(&S_kvf_1917_1);
  andn(&S_andn_1772_1);
  rs(&S_rs_22_1);
  noto(&S_noto_146_1);
  noto(&S_noto_1830_1);
  noto(&S_noto_117_1);
  noto(&S_noto_1397_1);
  abs_subf(&S_abs_subf_1010_1);
  abs_subf(&S_abs_subf_997_1);
  noto(&S_noto_1017_1);
  bol(&S_bol_1030_1);
  bol(&S_bol_1031_1);
  noto(&S_noto_994_1);
  bol(&S_bol_1032_1);
  bol(&S_bol_1033_1);
  bol(&S_bol_87_1);
  and2(&S_and2_34_1);
  and2(&S_and2_151_1);
  and2(&S_and2_159_1);
  and2(&S_and2_156_1);
  and2(&S_and2_148_1);
  and3(&S_and3_237_1);
  and3(&S_and3_554_1);
  and3(&S_and3_988_1);
  or3(&S_or3_114_1);
  or2(&S_or2_667_1);
  and2(&S_and2_676_1);
  and2(&S_and2_678_1);
  and2(&S_and2_690_1);
  and2(&S_and2_692_1);
  and2(&S_and2_705_1);
  and2(&S_and2_708_1);
  and3(&S_and3_707_1);
  and2(&S_and2_709_1);
  or2(&S_or2_745_1);
  and2(&S_and2_753_1);
  or2(&S_or2_759_1);
  or2(&S_or2_763_1);
  and3(&S_and3_760_1);
  and2(&S_and2_765_1);
  and2(&S_and2_769_1);
  and2(&S_and2_653_1);
  or2(&S_or2_654_1);
  and2(&S_and2_662_1);
  and2(&S_and2_664_1);
  and2(&S_and2_633_1);
  and2(&S_and2_611_1);
  and2(&S_and2_601_1);
  and3(&S_and3_532_1);
  or2(&S_or2_569_1);
  and3(&S_and3_215_1);
  and3(&S_and3_250_1);
  and3(&S_and3_853_1);
  and3(&S_and3_854_1);
  or2(&S_or2_974_1);
  or2(&S_or2_1386_1);
  and3(&S_and3_1270_1);
  and3(&S_and3_1271_1);
  or2(&S_or2_1034_1);
  or2(&S_or2_1047_1);
  or2(&S_or2_1046_1);
  or2(&S_or2_1045_1);
  or2(&S_or2_1044_1);
  and2(&S_and2_1409_1);
  and2(&S_and2_1415_1);
  and2(&S_and2_1417_1);
  and2(&S_and2_1419_1);
  and2(&S_and2_1425_1);
  and2(&S_and2_1429_1);
  or3(&S_or3_1453_1);
  and2(&S_and2_1454_1);
  and3(&S_and3_1512_1);
  or3(&S_or3_1495_1);
  and2(&S_and2_1510_1);
  and3(&S_and3_1513_1);
  zpfs(&S_zpfs_2051_1);
  and3(&S_and3_1941_1);
  and2(&S_and2_1936_1);
  or3(&S_or3_1942_1);
  and2(&S_and2_1914_1);
  and4(&S_and4_1922_1);
  and4(&S_and4_1924_1);
  lk(&S_lk_1921_1);
  rsfn(&S_rsfn_1925_1);
  abs_subf(&S_abs_subf_1927_1);
  and3(&S_and3_1930_1);
  lk(&S_lk_1883_1);
  rsfn(&S_rsfn_1886_1);
  abs_subf(&S_abs_subf_1888_1);
  and2(&S_and2_1876_1);
  and3(&S_and3_1880_1);
  or5(&S_or5_155_1);
  and2(&S_and2_1848_1);
  and2(&S_and2_112_1);
  and2(&S_and2_108_1);
  ml(&S_ml_1525_1);
  zpfs(&S_zpfs_746_1);
  and2(&S_and2_1749_1);
  and2(&S_and2_1726_1);
  and2(&S_and2_1747_1);
  and2(&S_and2_1750_1);
  and2(&S_and2_1727_1);
  and2(&S_and2_1748_1);
  and2(&S_and2_1728_1);
  and2(&S_and2_1729_1);
  and2(&S_and2_1731_1);
  and2(&S_and2_1732_1);
  and2(&S_and2_1734_1);
  and2(&S_and2_1735_1);
  and2(&S_and2_1702_1);
  and2(&S_and2_1703_1);
  rs(&S_rs_1704_1);
  and2(&S_and2_1705_1);
  and2(&S_and2_1706_1);
  rs(&S_rs_1707_1);
  and2(&S_and2_1685_1);
  and2(&S_and2_1689_1);
  and2(&S_and2_1650_1);
  and2(&S_and2_1652_1);
  and2(&S_and2_1654_1);
  and2(&S_and2_1656_1);
  and2(&S_and2_1624_1);
  and2(&S_and2_1625_1);
  and2(&S_and2_1626_1);
  and2(&S_and2_1627_1);
  and2(&S_and2_1628_1);
  and2(&S_and2_1629_1);
  and2(&S_and2_1630_1);
  and2(&S_and2_1631_1);
  and2(&S_and2_123_1);
  abs_subf(&S_abs_subf_1529_1);
  noto(&S_noto_1537_1);
  ovbs(&S_ovbs_2207_1);
  and2(&S_and2_2253_1);
  noto(&S_noto_2236_1);
  noto(&S_noto_2184_1);
  noto(&S_noto_2185_1);
  and2(&S_and2_2152_1);
  or4(&S_or4_890_1);
  and2(&S_and2_2120_1);
  or4(&S_or4_1307_1);
  and4(&S_and4_949_1);
  and4(&S_and4_1361_1);
  or3(&S_or3_1739_1);
  or3(&S_or3_1710_1);
  or3(&S_or3_1713_1);
  or3(&S_or3_1742_1);
  or3(&S_or3_1694_1);
  or3(&S_or3_1696_1);
  or3(&S_or3_1643_1);
  or3(&S_or3_1639_1);
  or3(&S_or3_2159_1);
  or3(&S_or3_2127_1);
  or3(&S_or3_2161_1);
  or3(&S_or3_2163_1);
  or3(&S_or3_2131_1);
  or3(&S_or3_2129_1);
  or2(&S_or2_1636_1);
  or2(&S_or2_2165_1);
  and2(&S_and2_2149_1);
  and2(&S_and2_2118_1);
  or2(&S_or2_1633_1);
  or2(&S_or2_1692_1);
  and2(&S_and2_1688_1);
  samhd(&S_samhd_388_1);
  samhd(&S_samhd_394_1);
  samhd(&S_samhd_783_1);
  samhd(&S_samhd_787_1);
  rs(&S_rs_755_1);
  rs(&S_rs_762_1);
  newstage(&S_newstage_391_1);
  newstage(&S_newstage_785_1);
  orn(&S_orn_152_1);
  rs(&S_rs_1632_1);
  rs(&S_rs_1634_1);
  rs(&S_rs_1635_1);
  rs(&S_rs_1637_1);
  rs(&S_rs_1638_1);
  rs(&S_rs_1640_1);
  rs(&S_rs_1642_1);
  rs(&S_rs_1644_1);
  rs(&S_rs_1662_1);
  rs(&S_rs_1670_1);
  rs(&S_rs_1691_1);
  rs(&S_rs_1699_1);
  rs(&S_rs_1709_1);
  rs(&S_rs_2166_1);
  rs(&S_rs_1738_1);
  rs(&S_rs_1730_1);
  rs(&S_rs_1741_1);
  rs(&S_rs_1733_1);
  rs(&S_rs_1744_1);
  rs(&S_rs_1682_1);
  rs(&S_rs_1683_1);
  rs(&S_rs_1684_1);
  rs(&S_rs_1646_1);
  rs(&S_rs_1647_1);
  rs(&S_rs_1648_1);
  rs(&S_rs_1649_1);
  rs(&S_rs_115_1);
  noto(&S_noto_116_1);
  rs(&S_rs_1517_1);
  rs(&S_rs_1516_1);
  rs(&S_rs_1446_1);
  kvf(&S_kvf_1450_1);
  rs(&S_rs_1935_1);
  rs(&S_rs_1881_1);
  noto(&S_noto_1449_1);
  andn(&S_andn_270_1);
  noto(&S_noto_288_1);
  and2(&S_and2_412_1);
  and2(&S_and2_423_1);
  and2(&S_and2_431_1);
  and2(&S_and2_432_1);
  and2(&S_and2_433_1);
  or3(&S_or3_384_1);
  or3(&S_or3_399_1);
  and2(&S_and2_413_1);
  and3(&S_and3_589_1);
  or2(&S_or2_154_1);
  and2(&S_and2_681_1);
  and2(&S_and2_741_1);
  or2(&S_or2_768_1);
  and2(&S_and2_660_1);
  or2(&S_or2_278_1);
  and3(&S_and3_279_1);
  or2(&S_or2_441_1);
  and3(&S_and3_448_1);
  or2(&S_or2_494_1);
  and2(&S_and2_514_1);
  and3(&S_and3_564_1);
  and3(&S_and3_563_1);
  and2(&S_and2_190_1);
  and3(&S_and3_249_1);
  or4(&S_or4_779_1);
  or4(&S_or4_795_1);
  or3(&S_or3_847_1);
  and2(&S_and2_843_1);
  and3(&S_and3_844_1);
  and2(&S_and2_842_1);
  and2(&S_and2_855_1);
  and2(&S_and2_872_1);
  and3(&S_and3_873_1);
  and2(&S_and2_935_1);
  or2(&S_or2_941_1);
  and2(&S_and2_950_1);
  and2(&S_and2_967_1);
  and3(&S_and3_968_1);
  and3(&S_and3_969_1);
  or2(&S_or2_1355_1);
  and2(&S_and2_1362_1);
  and2(&S_and2_1379_1);
  and3(&S_and3_1380_1);
  and3(&S_and3_1381_1);
  and2(&S_and2_1346_1);
  or3(&S_or3_1262_1);
  and3(&S_and3_1261_1);
  and2(&S_and2_1260_1);
  and2(&S_and2_1259_1);
  and2(&S_and2_1272_1);
  and2(&S_and2_1284_1);
  and3(&S_and3_1285_1);
  and2(&S_and2_1289_1);
  and3(&S_and3_1290_1);
  and2(&S_and2_1230_1);
  and2(&S_and2_1252_1);
  and2(&S_and2_1048_1);
  and2(&S_and2_1051_1);
  or2(&S_or2_1441_1);
  or3(&S_or3_1445_1);
  or2(&S_or2_1745_1);
  or2(&S_or2_2076_1);
  or2(&S_or2_2081_1);
  lk(&S_lk_1451_1);
  rsfn(&S_rsfn_1447_1);
  abs_subf(&S_abs_subf_1456_1);
  ovbs(&S_ovbs_2068_1);
  ovbs(&S_ovbs_121_1);
  and2(&S_and2_475_1);
  and2(&S_and2_446_1);
  and2(&S_and2_439_1);
  rs(&S_rs_1746_1);
  rs(&S_rs_1712_1);
  and2(&S_and2_1686_1);
  and2(&S_and2_1687_1);
  and2(&S_and2_1690_1);
  and2(&S_and2_1653_1);
  and2(&S_and2_1655_1);
  and2(&S_and2_1657_1);
  zpfs(&S_zpfs_2192_1);
  zpfs(&S_zpfs_2193_1);
  and2(&S_and2_2064_1);
  and2(&S_and2_2075_1);
  and3(&S_and3_414_1);
  and2(&S_and2_2063_1);
  and2(&S_and2_2086_1);
  rs(&S_rs_2158_1);
  rs(&S_rs_2146_1);
  rs(&S_rs_2150_1);
  and2(&S_and2_2156_1);
  rs(&S_rs_2168_1);
  rs(&S_rs_2151_1);
  and2(&S_and2_2157_1);
  rs(&S_rs_2170_1);
  rs(&S_rs_2134_1);
  rs(&S_rs_2126_1);
  rs(&S_rs_2114_1);
  rs(&S_rs_2117_1);
  and2(&S_and2_2124_1);
  rs(&S_rs_2136_1);
  rs(&S_rs_2119_1);
  and2(&S_and2_2125_1);
  rs(&S_rs_2138_1);
  regch(&S_regch_131_1);
  rs(&S_rs_1697_1);
  rs(&S_rs_735_1);
  rs(&S_rs_767_1);
  rs(&S_rs_594_1);
  noto(&S_noto_608_1);
  orni(&S_orni_1414_1);
  noto(&S_noto_2069_1);
  rs(&S_rs_1664_1);
  rs(&S_rs_1668_1);
  rs(&S_rs_1672_1);
  rs(&S_rs_1693_1);
  rs(&S_rs_1695_1);
  rs(&S_rs_1701_1);
  ma(&S_ma_1452_1);
  rs(&S_rs_604_1);
  noto(&S_noto_984_1);
  noto(&S_noto_282_1);
  noto(&S_noto_1040_1);
  noto(&S_noto_1041_1);
  noto(&S_noto_1013_1);
  and2(&S_and2_416_1);
  and2(&S_and2_434_1);
  and2(&S_and2_867_1);
  and3(&S_and3_868_1);
  and3(&S_and3_962_1);
  and3(&S_and3_1374_1);
  and2(&S_and2_628_1);
  and2(&S_and2_938_1);
  and2(&S_and2_939_1);
  and3(&S_and3_940_1);
  and2(&S_and2_1350_1);
  and2(&S_and2_1351_1);
  and3(&S_and3_1352_1);
  and5(&S_and5_989_1);
  and2(&S_and2_1035_1);
  or4(&S_or4_996_1);
  and3(&S_and3_1460_1);
  or2(&S_or2_1834_1);
  and2(&S_and2_1837_1);
  and2(&S_and2_2087_1);
  ovbs(&S_ovbs_2072_1);
  noto(&S_noto_2197_1);
  noto(&S_noto_2198_1);
  andn(&S_andn_592_1);
  andn(&S_andn_593_1);
  and2(&S_and2_2090_1);
  or5(&S_or5_2088_1);
  or5(&S_or5_2089_1);
  and2(&S_and2_2153_1);
  or3(&S_or3_1214_1);
  rs(&S_rs_2160_1);
  rs(&S_rs_2147_1);
  and2(&S_and2_2121_1);
  rs(&S_rs_2128_1);
  rs(&S_rs_2115_1);
  or3(&S_or3_814_1);
  or2(&S_or2_134_1);
  rs(&S_rs_995_1);
  noto(&S_noto_2073_1);
  rs(&S_rs_2077_1);
  rs(&S_rs_2082_1);
  rs(&S_rs_1463_1);
  noto(&S_noto_1014_1);
  provsbr(&S_provsbr_1411_1);
  rs(&S_rs_1410_1);
  and2(&S_and2_542_1);
  and2(&S_and2_225_1);
  and2(&S_and2_857_1);
  and2(&S_and2_952_1);
  and2(&S_and2_1364_1);
  and2(&S_and2_1274_1);
  and3(&S_and3_1001_1);
  and3(&S_and3_1007_1);
  and2(&S_and2_1023_1);
  and2(&S_and2_1012_1);
  and3(&S_and3_1058_1);
  or2(&S_or2_1416_1);
  or2(&S_or2_1418_1);
  or2(&S_or2_1420_1);
  or2(&S_or2_1426_1);
  or2(&S_or2_1430_1);
  orni(&S_orni_1422_1);
  or2(&S_or2_1832_1);
  or2(&S_or2_2065_1);
  noto(&S_noto_2204_1);
  and2(&S_and2_2154_1);
  and2(&S_and2_2122_1);
  rs(&S_rs_2148_1);
  and2(&S_and2_2155_1);
  rs(&S_rs_2164_1);
  rs(&S_rs_2116_1);
  and2(&S_and2_2066_1);
  noto(&S_noto_2083_1);
  rs(&S_rs_2162_1);
  newstage(&S_newstage_1825_1);
  cntch(&S_cntch_1421_1);
  rs(&S_rs_1018_1);
  rs(&S_rs_1052_1);
  rs(&S_rs_1026_1);
  noto(&S_noto_1027_1);
  or3(&S_or3_162_1);
  or3(&S_or3_484_1);
  or2(&S_or2_1049_1);
  and2(&S_and2_1423_1);
  or2(&S_or2_1585_1);
  zpfs(&S_zpfs_2062_1);
  rs(&S_rs_2130_1);
  and2(&S_and2_2123_1);
  rs(&S_rs_2132_1);
  cnshd(&S_cnshd_1592_1);
  noto(&S_noto_865_1);
  ornc(&S_ornc_169_1);
  charint(&S_charint_163_1);
  noto(&S_noto_233_1);
  ornc(&S_ornc_492_1);
  charint(&S_charint_486_1);
  noto(&S_noto_550_1);
  noto(&S_noto_960_1);
  noto(&S_noto_1372_1);
  rs(&S_rs_1036_1);
  or2(&S_or2_1611_1);
  and2(&S_and2_1563_1);
  and2(&S_and2_1564_1);
  and2(&S_and2_1565_1);
  and2(&S_and2_1566_1);
  and2(&S_and2_1572_1);
  and2(&S_and2_1574_1);
  and2(&S_and2_1576_1);
  and2(&S_and2_1025_1);
  fnapb(&S_fnapb_1612_1);
  samhd(&S_samhd_1595_1);
  zpfs(&S_zpfs_1607_1);
  zpfs(&S_zpfs_1605_1);
  noto(&S_noto_1282_1);
  fsumz(&S_fsumz_164_1);
  fsumz(&S_fsumz_487_1);
  orni(&S_orni_1174_1);
  rs(&S_rs_1020_1);
  rs(&S_rs_1021_1);
  ma(&S_ma_170_1);
  ma(&S_ma_493_1);
  zpfs(&S_zpfs_1613_1);
  or2(&S_or2_1112_1);
  or3(&S_or3_1019_1);
  or3(&S_or3_1602_1);
  samhd(&S_samhd_1179_1);
  samhd(&S_samhd_1190_1);
  newstage(&S_newstage_1182_1);
  cnshd(&S_cnshd_1116_1);
  noto(&S_noto_1281_1);
  noto(&S_noto_864_1);
  fnapb(&S_fnapb_203_1);
  noto(&S_noto_232_1);
  fnapb(&S_fnapb_522_1);
  zpfs(&S_zpfs_518_1);
  zpfs(&S_zpfs_515_1);
  noto(&S_noto_549_1);
  noto(&S_noto_959_1);
  noto(&S_noto_1371_1);
  or2(&S_or2_1178_1);
  or2(&S_or2_1192_1);
  or2(&S_or2_1136_1);
  and2(&S_and2_1088_1);
  and2(&S_and2_1085_1);
  and2(&S_and2_1086_1);
  and2(&S_and2_1087_1);
  and2(&S_and2_1093_1);
  and2(&S_and2_1095_1);
  and2(&S_and2_1097_1);
  and2(&S_and2_630_1);
  zpfs(&S_zpfs_523_1);
  or2(&S_or2_544_1);
  zpfs(&S_zpfs_204_1);
  zpfs(&S_zpfs_198_1);
  zpfs(&S_zpfs_193_1);
  or2(&S_or2_227_1);
  or2(&S_or2_859_1);
  and2(&S_and2_858_1);
  or2(&S_or2_954_1);
  or2(&S_or2_1366_1);
  or2(&S_or2_1276_1);
  and2(&S_and2_1275_1);
  and2(&S_and2_1016_1);
  or2(&S_or2_1028_1);
  and2(&S_and2_1184_1);
  and2(&S_and2_1186_1);
  or4(&S_or4_1959_1);
  fnapb(&S_fnapb_1137_1);
  samhd(&S_samhd_1119_1);
  zpfs(&S_zpfs_1133_1);
  zpfs(&S_zpfs_1129_1);
  orn(&S_orn_1283_1);
  orn(&S_orn_866_1);
  rs(&S_rs_1015_1);
  zpfs(&S_zpfs_1138_1);
  and2(&S_and2_543_1);
  and2(&S_and2_226_1);
  and2(&S_and2_953_1);
  and2(&S_and2_1365_1);
  and2(&S_and2_1029_1);
  or2(&S_or2_1022_1);
  or3(&S_or3_1126_1);
  or2(&S_or2_1976_1);
  or2(&S_or2_1965_1);
  ovbs(&S_ovbs_1960_1);
  ovbs(&S_ovbs_1972_1);
  ovbs(&S_ovbs_1963_1);
  noto(&S_noto_1964_1);
  and2(&S_and2_1970_1);
  and2(&S_and2_1981_1);
  or3(&S_or3_132_1);
  orn(&S_orn_234_1);
  orn(&S_orn_961_1);
  orn(&S_orn_1373_1);
  noto(&S_noto_1961_1);
  noto(&S_noto_1973_1);
  rs(&S_rs_1977_1);
  noto(&S_noto_1978_1);
  rs(&S_rs_1966_1);
  rs(&S_rs_1067_1);
  or2(&S_or2_1933_1);
  irm(&S_irm_2187_1);
  ml(&S_ml_885_1);
  ml(&S_ml_1302_1);
  noto(&S_noto_1967_1);
  noto(&S_noto_72_1);
  noto(&S_noto_1934_1);
  and2(&S_and2_64_1);
  and2(&S_and2_68_1);
  and4(&S_and4_334_1);
  or2(&S_or2_1403_1);
  or2(&S_or2_1950_1);
  noto(&S_noto_1399_1);
  rs(&S_rs_337_1);
  noto(&S_noto_332_1);
  noto(&S_noto_275_1);
  rs(&S_rs_1951_1);
  rs(&S_rs_1952_1);
  or4(&S_or4_286_1);
  or2(&S_or2_269_1);
  or2(&S_or2_292_1);
  or2(&S_or2_329_1);
  or4(&S_or4_338_1);
  and2(&S_and2_1398_1);
  or2(&S_or2_2012_1);
  or2(&S_or2_2033_1);
  rs(&S_rs_285_1);
  provsbr(&S_provsbr_274_1);
  equz_p(&S_equz_p_313_1);
  bolz(&S_bolz_314_1);
  provsbr(&S_provsbr_331_1);
  bolz(&S_bolz_336_1);
  noto(&S_noto_73_1);
  noto(&S_noto_62_1);
  and2(&S_and2_65_1);
  and2(&S_and2_69_1);
  or2(&S_or2_66_1);
  and2(&S_and2_566_1);
  and2(&S_and2_565_1);
  and2(&S_and2_289_1);
  and4(&S_and4_318_1);
  and2(&S_and2_301_1);
  or2(&S_or2_291_1);
  and2(&S_and2_296_1);
  or2(&S_or2_342_1);
  and2(&S_and2_333_1);
  orn(&S_orn_551_1);
  and2(&S_and2_251_1);
  and2(&S_and2_252_1);
  or3(&S_or3_262_1);
  and2(&S_and2_875_1);
  and2(&S_and2_874_1);
  or3(&S_or3_880_1);
  and2(&S_and2_971_1);
  and2(&S_and2_970_1);
  and2(&S_and2_1382_1);
  and2(&S_and2_1383_1);
  and2(&S_and2_1291_1);
  and2(&S_and2_1292_1);
  or3(&S_or3_1297_1);
  or2(&S_or2_1400_1);
  or3(&S_or3_1431_1);
  or3(&S_or3_1470_1);
  or3(&S_or3_1486_1);
  or3(&S_or3_1893_1);
  or3(&S_or3_1855_1);
  or4(&S_or4_1393_1);
  or4(&S_or4_981_1);
  maz(&S_maz_300_1);
  maz(&S_maz_309_1);
  orni(&S_orni_1187_1);
  orni(&S_orni_290_1);
  rs(&S_rs_341_1);
  decatron(&S_decatron_297_1);
  orni(&S_orni_335_1);
  noto(&S_noto_310_1);
  swtakt(&S_swtakt_1859_1);
  swtakt(&S_swtakt_1894_1);
  swtakt(&S_swtakt_1476_1);
  swtakt(&S_swtakt_1480_1);
  swtakt(&S_swtakt_1436_1);
  or3(&S_or3_576_1);
  or2(&S_or2_295_1);
  or2(&S_or2_304_1);
  or2(&S_or2_317_1);
  or2(&S_or2_316_1);
  and2(&S_and2_320_1);
  and2(&S_and2_315_1);
  and2(&S_and2_322_1);
  and2(&S_and2_321_1);
  and3(&S_and3_302_1);
  or5(&S_or5_506_1);
  or5(&S_or5_186_1);
  and2(&S_and2_1401_1);
  or2(&S_or2_2055_1);
  or2(&S_or2_2043_1);
  or3(&S_or3_1395_1);
  or3(&S_or3_983_1);
  zpfs(&S_zpfs_312_1);
  cnshd(&S_cnshd_174_1);
  cnshd(&S_cnshd_495_1);
  equz_p(&S_equz_p_303_1);
  noto(&S_noto_1407_1);
  cntch(&S_cntch_293_1);
  rs(&S_rs_294_1);
  cntch(&S_cntch_339_1);
  and2(&S_and2_308_1);
  or5(&S_or5_1424_1);
  or5(&S_or5_1402_1);
  and2(&S_and2_1404_1);
  or2(&S_or2_1405_1);
  and4(&S_and4_1937_1);
  and3(&S_and3_1938_1);
  and3(&S_and3_1939_1);
  and2(&S_and2_1900_1);
  and2(&S_and2_1854_1);
  or3(&S_or3_1868_1);
  newstage(&S_newstage_211_1);
  rs(&S_rs_1906_1);
  rs(&S_rs_1860_1);
  rs(&S_rs_1869_1);
  and2(&S_and2_327_1);
  or3(&S_or3_1905_1);
  and2(&S_and2_200_1);
  and2(&S_and2_197_1);
  noto(&S_noto_328_1);
  and2(&S_and2_1081_1);
  and2(&S_and2_637_1);
  or2(&S_or2_625_1);
  and2(&S_and2_1042_1);
  rs(&S_rs_626_1);
  rs(&S_rs_1037_1);
  noto(&S_noto_1039_1);
  rs(&S_rs_1073_1);
  and2(&S_and2_644_1);
  and3(&S_and3_613_1);
  and3(&S_and3_603_1);
  or3(&S_or3_808_1);
  or3(&S_or3_1210_1);
  and4(&S_and4_1002_1);
  and4(&S_and4_1008_1);
  or2(&S_or2_1072_1);
  or4(&S_or4_881_1);
  or4(&S_or4_1298_1);
  ornc(&S_ornc_891_1);
  charint(&S_charint_883_1);
  ornc(&S_ornc_1308_1);
  charint(&S_charint_1300_1);
  fsumz(&S_fsumz_884_1);
  fsumz(&S_fsumz_1301_1);
  ma(&S_ma_1309_1);
  ma(&S_ma_892_1);
  fnapb(&S_fnapb_926_1);
  zpfs(&S_zpfs_919_1);
  zpfs(&S_zpfs_917_1);
  fnapb(&S_fnapb_1338_1);
  zpfs(&S_zpfs_1331_1);
  zpfs(&S_zpfs_1329_1);
  zpfs(&S_zpfs_927_1);
  zpfs(&S_zpfs_1339_1);
  and2(&S_and2_1324_1);
  and2(&S_and2_909_1);
  or5(&S_or5_908_1);
  or5(&S_or5_1323_1);
  or2(&S_or2_2239_1);
  cnshd(&S_cnshd_893_1);
  cnshd(&S_cnshd_1310_1);
  noto(&S_noto_2238_1);
  newstage(&S_newstage_905_1);
  and2(&S_and2_912_1);
  and2(&S_and2_916_1);
  andn(&S_andn_2212_1);
  noto(&S_noto_2234_1);
  and2(&S_and2_2235_1);
  or2(&S_or2_2233_1);
  and3(&S_and3_2191_1);
  and2(&S_and2_2060_1);
  and2(&S_and2_2052_1);
  or3(&S_or3_2047_1);
  or3(&S_or3_2061_1);
  rs(&S_rs_2044_1);
  noto(&S_noto_2045_1);
  rs(&S_rs_2056_1);
  noto(&S_noto_2057_1);
  and2(&S_and2_1082_1);
  and2(&S_and2_636_1);
  and2(&S_and2_1057_1);
  rs(&S_rs_2232_1);
  rs(&S_rs_1050_1);
  noto(&S_noto_1053_1);
  rs(&S_rs_1076_1);
  and3(&S_and3_1043_1);
  and2(&S_and2_993_1);
  and4(&S_and4_1000_1);
  and4(&S_and4_1006_1);
  or2(&S_or2_1075_1);
  orn(&S_orn_1202_1);
  orn(&S_orn_802_1);
  ornc(&S_ornc_1211_1);
  charint(&S_charint_1203_1);
  ornc(&S_ornc_809_1);
  charint(&S_charint_803_1);
  rs(&S_rs_987_1);
  or3(&S_or3_440_1);
  and3(&S_and3_447_1);
  and2(&S_and2_1038_1);
  and2(&S_and2_479_1);
  and2(&S_and2_450_1);
  fsumz(&S_fsumz_1204_1);
  fsumz(&S_fsumz_804_1);
  samhd(&S_samhd_460_1);
  samhd(&S_samhd_466_1);
  newstage(&S_newstage_462_1);
  ma(&S_ma_810_1);
  ma(&S_ma_1212_1);
  or4(&S_or4_456_1);
  or4(&S_or4_474_1);
  and2(&S_and2_471_1);
  and2(&S_and2_469_1);
  fnapb(&S_fnapb_1248_1);
  zpfs(&S_zpfs_1242_1);
  zpfs(&S_zpfs_1233_1);
  fnapb(&S_fnapb_833_1);
  zpfs(&S_zpfs_1246_1);
  and2(&S_and2_1083_1);
  and2(&S_and2_652_1);
  zpfs(&S_zpfs_834_1);
  zpfs(&S_zpfs_827_1);
  zpfs(&S_zpfs_830_1);
  or5(&S_or5_1226_1);
  and2(&S_and2_1064_1);
  or5(&S_or5_1983_1);
  orni(&S_orni_138_1);
  orn(&S_orn_418_1);
  orn(&S_orn_436_1);
  cnshd(&S_cnshd_1213_1);
  rs(&S_rs_1059_1);
  rs(&S_rs_1079_1);
  or2(&S_or2_420_1);
  or2(&S_or2_437_1);
  and2(&S_and2_680_1);
  or2(&S_or2_1158_1);
  or2(&S_or2_1159_1);
  and2(&S_and2_1096_1);
  or5(&S_or5_822_1);
  and2(&S_and2_1575_1);
  or4(&S_or4_1571_1);
  or4(&S_or4_1984_1);
  orn(&S_orn_766_1);
  orn(&S_orn_1084_1);
  cnshd(&S_cnshd_813_1);
  or2(&S_or2_756_1);
  or2(&S_or2_757_1);
  or4(&S_or4_737_1);
  or5(&S_or5_1122_1);
  or2(&S_or2_362_1);
  or2(&S_or2_366_1);
  ovbs(&S_ovbs_1990_1);
  noto(&S_noto_1991_1);
  and2(&S_and2_1997_1);
  and2(&S_and2_2009_1);
  or3(&S_or3_1985_1);
  and2(&S_and2_1986_1);
  or3(&S_or3_1999_1);
  and2(&S_and2_2000_1);
  or5(&S_or5_1562_1);
  or2(&S_or2_2223_1);
  rs(&S_rs_736_1);
  samhd(&S_samhd_365_1);
  newstage(&S_newstage_1253_1);
  and2(&S_and2_724_1);
  or2(&S_or2_727_1);
  or4(&S_or4_364_1);
  or5(&S_or5_1599_1);
  or2(&S_or2_2004_1);
  or2(&S_or2_1992_1);
  ovbs(&S_ovbs_1987_1);
  ovbs(&S_ovbs_2001_1);
  rs(&S_rs_2020_1);
  rs(&S_rs_2028_1);
  noto(&S_noto_2018_1);
  noto(&S_noto_2039_1);
  andn(&S_andn_1_1);
  and2(&S_and2_1234_1);
  and2(&S_and2_1241_1);
  zpfs(&S_zpfs_2021_1);
  zpfs(&S_zpfs_2029_1);
  noto(&S_noto_2221_1);
  or3(&S_or3_1667_1);
  or3(&S_or3_1659_1);
  or2(&S_or2_1673_1);
  or2(&S_or2_1665_1);
  rs(&S_rs_730_1);
  rs(&S_rs_1658_1);
  rs(&S_rs_1666_1);
  or2(&S_or2_2022_1);
  noto(&S_noto_1988_1);
  noto(&S_noto_2002_1);
  rs(&S_rs_2005_1);
  noto(&S_noto_2006_1);
  rs(&S_rs_1993_1);
  or2(&S_or2_2030_1);
  noto(&S_noto_2023_1);
  and2(&S_and2_2024_1);
  and2(&S_and2_2019_1);
  noto(&S_noto_2031_1);
  and2(&S_and2_1651_1);
  noto(&S_noto_2011_1);
  rs(&S_rs_1660_1);
  noto(&S_noto_1994_1);
  and2(&S_and2_2032_1);
  and4(&S_and4_2013_1);
  ovbs(&S_ovbs_2014_1);
  and2(&S_and2_2040_1);
  noto(&S_noto_2041_1);
  or2(&S_or2_2015_1);
  orn(&S_orn_596_1);
  orn(&S_orn_595_1);
  noto(&S_noto_2016_1);
  and4(&S_and4_2034_1);
  ovbs(&S_ovbs_2035_1);
  or2(&S_or2_2036_1);
  newstage(&S_newstage_598_1);
  or2(&S_or2_632_1);
  ovbs(&S_ovbs_2025_1);
  noto(&S_noto_2037_1);
  and2(&S_and2_631_1);
  setData(idbd6,&var850);
  setData(idbd5,&var851);
  setData(idbd4,&var852);
  setData(idbd3,&var1625);
  setData(idbd2,&var847);
  setData(idbd1,&var848);
  setData(idhz6,&var1204);
  setData(idhz5,&var914);
  setData(idhz4,&var390);
  setData(idhz3,&var961);
  setData(idhz2,&var250);
  setData(idhz1,&var1273);
  setData(idKKL9,&var1202);
  setData(idKKL8,&var1150);
  setData(idKKL7,&var1108);
  setData(idKKL6,&var1024);
  setData(idKKL5,&var1204);
  setData(idKKL4,&var1554);
  setData(idKKL3,&var811);
  setData(idKKL2,&var1199);
  setData(idKKL1,&var245);
  setData(idTestDiagnDU,&var3);
  setData(idR0DE3CLDU,&var6);
  setData(idR0DE3DLDU,&var5);
  setData(idTTLDU,&var9);
  setData(idB3AB13LDU,&var131);
  setData(idA3AB13LDU,&var134);
  setData(idR3VS01IDU,&var140);
  setData(idR3VS12LDU,&var138);
  setData(idR3VS22LDU,&var139);
  setData(idR5VS01IDU,&var137);
  setData(idR5VS12LDU,&var135);
  setData(idR5VS22LDU,&var136);
  setData(idB3AB15LDU,&var144);
  setData(idB3EE03LDU,&var812);
  setData(idA3EE03LDU,&var813);
  setData(idB3AB19LDU,&var149);
  setData(idA3AB19LDU,&var150);
  setData(idR0VL23LDU,&var1048);
  setData(idR0VL22LDU,&var1070);
  setData(idR0AD05LZ2,&var76);
  setData(idR0AD05LZ1,&var76);
  setData(idR0AD04LZ2,&var372);
  setData(idR0AD04LZ1,&var372);
  setData(idR0AD03LZ2,&var75);
  setData(idR0AD03LZ1,&var75);
  setData(idR0CN95LDU,&var220);
  setData(idR0CN94LDU,&var219);
  setData(idR0CN93LDU,&var218);
  setData(idR0AB19LDU,&var181);
  setData(idR0VN12RDU,&var981);
  setData(idR0VN11RDU,&var979);
  setData(idR0CN92LDU,&var185);
  setData(idR0AB20LDU,&var197);
  setData(idA3AB15LDU,&var145);
  setData(idA3MC03RDU,&var216);
  setData(idR0CN91LDU,&var215);
  setData(idA3MC02RDU,&var214);
  setData(idA3MC01RDU,&var213);
  setData(idR0AB18LDU,&var202);
  setData(idR0AB17LDU,&var209);
  setData(idR0AB16LDU,&var210);
  setData(idB1AB19LDU,&var227);
  setData(idA3ZAV,&var1320);
  setData(idA1ZAV,&var1383);
  setData(idB3IS12LDU,&var237);
  setData(idA3IS12LDU,&var238);
  setData(idR0AB15LDU,&var243);
  setData(idR0AB14LDU,&var241);
  setData(idA4DW,&var1158);
  setData(idA4UP,&var1159);
  setData(idR4ABL,&var1622);
  setData(idA9ZAV,&var1258);
  setData(idA8ZAV,&var1459);
  setData(idA2ZAV,&var1464);
  setData(idB8ZAV,&var1469);
  setData(idA5ZAV,&var1537);
  setData(idR2ZAV,&var1413);
  setData(idA6ZAV,&var1539);
  setData(idA4ZAV,&var1538);
  setData(idR0AB13LDU,&var310);
  setData(idR0AB12LDU,&var314);
  setData(idR0AB11LDU,&var318);
  setData(idR0AB10LDU,&var322);
  setData(idR0AB09LDU,&var326);
  setData(idR0AB08LDU,&var330);
  setData(idB6AB05LDU,&var373);
  setData(idR0VS11LDU,&var1668);
  setData(idA8VS01IDU,&var1463);
  setData(idB8VS01IDU,&var1473);
  setData(idR2AD10LDU,&var1418);
  setData(idR2AD20LDU,&var1419);
  setData(idB6VS01IDU,&var1610);
  setData(idR0AD16LDU,&lRM_0_);
  setData(idR0AB07LDU,&var612);
  setData(idR0EE03LDU,&var397);
  setData(idR0VX02LDU,&var818);
  setData(idR0AD21LDU,&var816);
  setData(idB2AB15LDU,&var343);
  setData(idA2AB15LDU,&var344);
  setData(idR0AB05LDU,&var1130);
  setData(idR0AB03LDU,&var1141);
  setData(idA1AB19LDU,&var228);
  setData(idR0VZ71LDU,&var62);
  setData(idR0VL01RDU,&var1176);
  setData(idB7AZ03LDU,&var374);
  setData(idA7AZ03LDU,&var482);
  setData(idB2VS01IDU,&var1451);
  setData(idB2VS21LDU,&var1453);
  setData(idB2VS11LDU,&var1452);
  setData(idR0VP73LDU,&var493);
  setData(idR0VS18LDU,&var570);
  setData(idB3VX01LDU,&var440);
  setData(idA3VX01LDU,&var441);
  setData(idB2VS32LDU,&var356);
  setData(idA2VS32LDU,&var357);
  setData(idR0VS17LDU,&var560);
  setData(idR0VX09LDU,&var173);
  moveData(idR0VX08IDU,idR0MW12IP1);
  setData(idR0VW23LDU,&var913);
  setData(idR0VW13LDU,&var912);
  setData(idB7AP31LDU,&var1161);
  setData(idA7AP31LDU,&var1162);
  setData(idB3AD31LDU,&var1221);
  setData(idB3AD34LDU,&var1222);
  setData(idA3AD31LDU,&var1227);
  setData(idA3AD34LDU,&var1224);
  setData(idA3AD33LDU,&var1226);
  setData(idB2AD33LDU,&var335);
  setData(idA2AD33LDU,&var338);
  setData(idR0AB01LDU,&var1250);
  setData(idB9AB02LDU,&var1260);
  setData(idB9AB01LDU,&var1261);
  setData(idB9AZ03LDU,&var1259);
  setData(idA9AB02LDU,&var1266);
  setData(idA9AB01LDU,&var1267);
  setData(idA9AZ03LDU,&var1265);
  setData(idA9AD10LDU,&var1268);
  setData(idB9AD10LDU,&var1262);
  setData(idR1VS01IDU,&var1429);
  setData(idR2VS01IDU,&var1420);
  setData(idR4VS01IDU,&var1601);
  setData(idA6VS01IDU,&var1619);
  setData(idB5VS01IDU,&var1583);
  setData(idA5VS01IDU,&var1592);
  setData(idB4VS22LDU,&var1564);
  setData(idB4VS12LDU,&var1563);
  setData(idB4VS01IDU,&var1565);
  setData(idA4VS22LDU,&var1573);
  setData(idA4VS12LDU,&var1572);
  setData(idA4VS01IDU,&var1574);
  setData(idA2VS01IDU,&var1492);
  setData(idB3VS01IDU,&var1310);
  setData(idA3VS01IDU,&var1342);
  setData(idB1VS01IDU,&var1371);
  setData(idA1VS01IDU,&var1404);
  setData(idR0VS21IDU,&var1151);
  setData(idR0VX03LDU,&var763);
  setData(idR0VL21IDU,&var1061);
  setData(idR0VL05RDU,&var427);
  setData(idR0VL03RDU,&var433);
  setData(idR0AB02LDU,&var1124);
  setData(idR0AB06LDU,&var1127);
  setData(idR0AB04LDU,&var1135);
  setData(idR0VL04RDU,&var430);
  setData(idR0AD14LDU,&var372);
  setData(idR8AD21LDU,&var395);
  setData(idR0VL02RDU,&var424);
  setData(idB3AD33LDU,&var1220);
  setData(idR0VL06RDU,&var437);
  setData(idR0VL11IDU,&var1274);
  setData(idR0VL01IDU,&var1275);
  setData(idR0VX01LDU,&var820);
  setData(idB1AD32LDU,&var1228);
  setData(idA1AD32LDU,&var1230);
  setData(idB2AD32LDU,&var363);
  setData(idA2AD32LDU,&var365);
  setData(idB1AD31LDU,&var1231);
  setData(idA1AD31LDU,&var1232);
  setData(idB2AD31LDU,&var366);
  setData(idA2AD31LDU,&var367);
  setData(idB3AB20LDU,&var654);
  setData(idB3AB18LDU,&var651);
  setData(idB3AB17LDU,&var647);
  setData(idB3AB16LDU,&var648);
  setData(idB3AB14LDU,&var922);
  setData(idB3AB12LDU,&var652);
  setData(idB3AB11LDU,&var656);
  setData(idB3AB10LDU,&var657);
  setData(idB3AB09LDU,&var658);
  setData(idB3AB06LDU,&var661);
  setData(idB3AB05LDU,&var663);
  setData(idB3AB08LDU,&var653);
  setData(idB3AB07LDU,&var662);
  setData(idB3CV02RDU,&var1309);
  setData(idB3AD01LDU,&var1302);
  setData(idB3AD05LDU,&var1308);
  setData(idB3AD04LDU,&var1307);
  setData(idB3AD03LDU,&var1306);
  setData(idB3AD02LDU,&var1305);
  setData(idB3AD21LDU,&var1303);
  setData(idB3AD11LDU,&var1304);
  setData(idB3AZ03LDU,&var994);
  setData(idB3VS22LDU,&var1313);
  setData(idB3AB01LDU,&var1311);
  setData(idB3AB02LDU,&var1312);
  setData(idB3AB04LDU,&var1317);
  setData(idB3CV01RDU,&var1315);
  setData(idB3VS12LDU,&var1314);
  setData(idA3AB20LDU,&var405);
  setData(idA3AB18LDU,&var668);
  setData(idA3AB17LDU,&var666);
  setData(idA3AB16LDU,&var665);
  setData(idA3AB14LDU,&var924);
  setData(idA3AB12LDU,&var669);
  setData(idA3AB11LDU,&var673);
  setData(idA3AB10LDU,&var677);
  setData(idA3AB09LDU,&var671);
  setData(idA3AB06LDU,&var676);
  setData(idA3AB05LDU,&var679);
  setData(idA3AB08LDU,&var670);
  setData(idA3AB07LDU,&var678);
  setData(idA3CV02RDU,&var1341);
  setData(idA3AD01LDU,&var1334);
  setData(idA3AD05LDU,&var1340);
  setData(idA3AD04LDU,&var1339);
  setData(idA3AD03LDU,&var1338);
  setData(idA3AD02LDU,&var1337);
  setData(idA3AD21LDU,&var1335);
  setData(idA3AD11LDU,&var1336);
  setData(idA3AZ03LDU,&var995);
  setData(idA3VS22LDU,&var1345);
  setData(idA3AB01LDU,&var1343);
  setData(idA3AB02LDU,&var1344);
  setData(idA3AB04LDU,&var1349);
  setData(idA3CV01RDU,&var1347);
  setData(idA3VS12LDU,&var1346);
  setData(idB1AB18LDU,&var738);
  setData(idB1AB17LDU,&var907);
  setData(idB1AB16LDU,&var906);
  setData(idB1AB14LDU,&var926);
  setData(idB1AB13LDU,&var927);
  setData(idB1AB12LDU,&var736);
  setData(idB1AB11LDU,&var740);
  setData(idB1AB10LDU,&var741);
  setData(idB1AB09LDU,&var744);
  setData(idB1AB06LDU,&var742);
  setData(idB1AB05LDU,&var749);
  setData(idB1AB08LDU,&var737);
  setData(idB1AB07LDU,&var748);
  setData(idB1CV02RDU,&var1370);
  setData(idB1AD01LDU,&var1363);
  setData(idB1AD05LDU,&var1369);
  setData(idB1AD04LDU,&var1368);
  setData(idB1AD03LDU,&var1367);
  setData(idB1AD02LDU,&var1366);
  setData(idB1AD21LDU,&var1365);
  setData(idB1AD11LDU,&var1364);
  setData(idB1AZ03LDU,&var751);
  setData(idB1VS22LDU,&var1375);
  setData(idB1AB01LDU,&var1372);
  setData(idB1AB02LDU,&var1373);
  setData(idB1AB04LDU,&var1378);
  setData(idB1CV01RDU,&var1376);
  setData(idB1VS12LDU,&var1374);
  setData(idA1AB18LDU,&var714);
  setData(idA1AB17LDU,&var713);
  setData(idA1AB16LDU,&var715);
  setData(idA1AB14LDU,&var929);
  setData(idA1AB13LDU,&var930);
  setData(idA1AB12LDU,&var711);
  setData(idA1AB11LDU,&var720);
  setData(idA1AB10LDU,&var718);
  setData(idA1AB09LDU,&var717);
  setData(idA1AB06LDU,&var722);
  setData(idA1AB05LDU,&var723);
  setData(idA1AB08LDU,&var716);
  setData(idA1AB07LDU,&var724);
  setData(idA1CV02RDU,&var1403);
  setData(idA1AD01LDU,&var1396);
  setData(idA1AD05LDU,&var1402);
  setData(idA1AD04LDU,&var1401);
  setData(idA1AD03LDU,&var1400);
  setData(idA1AD02LDU,&var1399);
  setData(idA1AD21LDU,&var1398);
  setData(idA1AD11LDU,&var1397);
  setData(idA1AZ03LDU,&var731);
  setData(idA1VS22LDU,&var1406);
  setData(idA1AB01LDU,&var729);
  setData(idA1AB02LDU,&var730);
  setData(idA1AB04LDU,&var1409);
  setData(idA1CV01RDU,&var1407);
  setData(idA1VS12LDU,&var1405);
  setData(idR1AD20LDU,&var1428);
  setData(idR1AD10LDU,&var1427);
  setData(idR2AB04LDU,&var1416);
  setData(idR1AB04LDU,&var1425);
  setData(idR2AB02LDU,&var1415);
  setData(idR2AB01LDU,&var1417);
  setData(idR2AZ03LDU,&var1414);
  setData(idR1AB02LDU,&var1424);
  setData(idR1AB01LDU,&var1426);
  setData(idR1AZ03LDU,&var1423);
  setData(idB2AB17LDU,&var687);
  setData(idB2AB16LDU,&var686);
  setData(idB2AB14LDU,&var931);
  setData(idB2AB13LDU,&var932);
  setData(idB2AB12LDU,&var688);
  setData(idB2AB11LDU,&var692);
  setData(idB2AB10LDU,&var691);
  setData(idB2AB09LDU,&var690);
  setData(idB2AB06LDU,&var695);
  setData(idB2AB05LDU,&var694);
  setData(idB2AB08LDU,&var689);
  setData(idB2AB07LDU,&var696);
  setData(idB2CV02RDU,&var1450);
  setData(idB2AD01LDU,&var1443);
  setData(idB2AD05LDU,&var1449);
  setData(idB2AD04LDU,&var1448);
  setData(idB2AD03LDU,&var1447);
  setData(idB2AD02LDU,&var1446);
  setData(idB2AD21LDU,&var1445);
  setData(idB2AD11LDU,&var1444);
  setData(idB2AZ03LDU,&var704);
  setData(idB2AB01LDU,&var703);
  setData(idB2AB02LDU,&var702);
  setData(idB2AB04LDU,&var1456);
  setData(idB2CV01RDU,&var1454);
  setData(idA2CV02RDU,&var1491);
  setData(idA2AD01LDU,&var1484);
  setData(idA2AB17LDU,&var625);
  setData(idA2AB16LDU,&var626);
  setData(idA2AB14LDU,&var629);
  setData(idA2AB13LDU,&var630);
  setData(idA2AB12LDU,&var627);
  setData(idA2AB11LDU,&var635);
  setData(idA2AB10LDU,&var633);
  setData(idA2AB09LDU,&var631);
  setData(idA2AB06LDU,&var636);
  setData(idA2AB05LDU,&var632);
  setData(idA2AB08LDU,&var628);
  setData(idA2AB07LDU,&var634);
  setData(idA2AD05LDU,&var1490);
  setData(idA2AD04LDU,&var1489);
  setData(idA2AD03LDU,&var1488);
  setData(idA2AD02LDU,&var1487);
  setData(idA2AD21LDU,&var1486);
  setData(idA2AD11LDU,&var1485);
  setData(idA2AZ03LDU,&var996);
  setData(idA2VS21LDU,&var1496);
  setData(idA2AB01LDU,&var1493);
  setData(idA2AB02LDU,&var1494);
  setData(idA2AB04LDU,&var1499);
  setData(idA2CV01RDU,&var1497);
  setData(idA2VS11LDU,&var1495);
  setData(idA8AB01LDU,&var1507);
  setData(idA8AB02LDU,&var513);
  setData(idA8AB14LDU,&var514);
  setData(idA8AB13LDU,&var515);
  setData(idA8AB12LDU,&var517);
  setData(idA8AB11LDU,&var518);
  setData(idA8AB10LDU,&var519);
  setData(idA8AB09LDU,&var520);
  setData(idA8AB08LDU,&var521);
  setData(idA8AB04LDU,&var1506);
  setData(idA8AD20LDU,&var1462);
  setData(idA8AD10LDU,&var1461);
  setData(idA8AZ03LDU,&var986);
  setData(idA8VS22LDU,&var1509);
  setData(idA8AB05LDU,&var1504);
  setData(idA8AB07LDU,&var1505);
  setData(idA8AB06LDU,&var1512);
  setData(idA8CV01RDU,&var1510);
  setData(idA8VS12LDU,&var1508);
  setData(idB8AB02LDU,&var831);
  setData(idB8AB14LDU,&var832);
  setData(idB8AB13LDU,&var833);
  setData(idB8AB12LDU,&var834);
  setData(idB8AB11LDU,&var838);
  setData(idB8AB10LDU,&var835);
  setData(idB8AB09LDU,&var836);
  setData(idB8AB08LDU,&var837);
  setData(idB8AB04LDU,&var1523);
  setData(idB8AB01LDU,&var1524);
  setData(idB8AD20LDU,&var1472);
  setData(idB8AD10LDU,&var1471);
  setData(idB8AZ03LDU,&var987);
  setData(idB8VS22LDU,&var1526);
  setData(idB8AB05LDU,&var1515);
  setData(idB8AB07LDU,&var1516);
  setData(idB8AB06LDU,&var1529);
  setData(idB8CV01RDU,&var1527);
  setData(idB8VS12LDU,&var1525);
  setData(idA6AB05LDU,&var954);
  setData(idB6AB09LDU,&var953);
  setData(idB6AB08LDU,&var952);
  setData(idB6AB07LDU,&var951);
  setData(idB6AB06LDU,&var950);
  setData(idA6AB09LDU,&var955);
  setData(idA6AB08LDU,&var941);
  setData(idA6AB07LDU,&var143);
  setData(idA6AB06LDU,&var956);
  setData(idB5AB04LDU,&var1579);
  setData(idA5AB04LDU,&var1588);
  setData(idB4AB02LDU,&var1560);
  setData(idB4AB01LDU,&var1561);
  setData(idB4AZ03LDU,&var1559);
  setData(idA4AB02LDU,&var1569);
  setData(idA4AB01LDU,&var1570);
  setData(idA4AZ03LDU,&var1568);
  setData(idA4AD10LDU,&var1571);
  setData(idB4AD10LDU,&var1562);
  setData(idB5AB02LDU,&var1578);
  setData(idB5AB01LDU,&var1580);
  setData(idB5AZ03LDU,&var1577);
  setData(idA5AB02LDU,&var1587);
  setData(idA5AB01LDU,&var1589);
  setData(idA5AZ03LDU,&var1586);
  setData(idA5AD20LDU,&var1591);
  setData(idA5AD10LDU,&var1590);
  setData(idB5AD20LDU,&var1582);
  setData(idB5AD10LDU,&var1581);
  setData(idR4AD20LDU,&var1600);
  setData(idR4AD10LDU,&var1599);
  setData(idR4AB18LDU,&var884);
  setData(idR4AB17LDU,&var883);
  setData(idR4AB16LDU,&var886);
  setData(idR4AB15LDU,&var885);
  setData(idR4AB14LDU,&var887);
  setData(idR4AB13LDU,&var855);
  setData(idR4AB12LDU,&var860);
  setData(idR4AB11LDU,&var892);
  setData(idR4AB10LDU,&var857);
  setData(idR4AB09LDU,&var890);
  setData(idR4AB08LDU,&var889);
  setData(idR4AB07LDU,&var893);
  setData(idR4AB06LDU,&var1597);
  setData(idR4AB05LDU,&var1596);
  setData(idR4AB04LDU,&var1598);
  setData(idR4AB03LDU,&var894);
  setData(idR4AZ03LDU,&var1595);
  setData(idR4AB02LDU,&var897);
  setData(idR4AB01LDU,&var898);
  setData(idB6AB04LDU,&var1606);
  setData(idA6AB04LDU,&var1615);
  setData(idB6AB02LDU,&var1605);
  setData(idB6AB01LDU,&var1607);
  setData(idB6AZ03LDU,&var1604);
  setData(idA6AB02LDU,&var1614);
  setData(idA6AB01LDU,&var1616);
  setData(idA6AZ03LDU,&var1613);
  setData(idB6AD20LDU,&var1609);
  setData(idB6AD10LDU,&var1608);
  setData(idA6AD20LDU,&var1618);
  setData(idA6AD10LDU,&var1617);
  setData(idR0ES01LDU,&var902);

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
    array_m331_rz_1[i] = &(&internal1_m331_rz)[i*1];
  for( i=0;i<10;i++ )
    array_m274_rz_1[i] = &(&internal1_m274_rz)[i*1];
  for( i=0;i<6;i++ )
    array_m1411_rz_1[i] = &(&internal1_m1411_rz)[i*1];
  for( i=0;i<60;i++ )
    array_m1338_x0_1[i] = &(&internal1_m1338_x0)[i*5];
  for( i=0;i<60;i++ )
    array_m1338_tim0_1[i] = &(&internal1_m1338_tim0)[i*5];
  for( i=0;i<60;i++ )
    array_m926_x0_1[i] = &(&internal1_m926_x0)[i*5];
  for( i=0;i<60;i++ )
    array_m926_tim0_1[i] = &(&internal1_m926_tim0)[i*5];
  for( i=0;i<150;i++ )
    array_m522_x0_1[i] = &(&internal1_m522_x0)[i*5];
  for( i=0;i<150;i++ )
    array_m522_tim0_1[i] = &(&internal1_m522_tim0)[i*5];
  for( i=0;i<150;i++ )
    array_m203_x0_1[i] = &(&internal1_m203_x0)[i*5];
  for( i=0;i<150;i++ )
    array_m203_tim0_1[i] = &(&internal1_m203_tim0)[i*5];
  for( i=0;i<80;i++ )
    array_m833_x0_1[i] = &(&internal1_m833_x0)[i*5];
  for( i=0;i<80;i++ )
    array_m833_tim0_1[i] = &(&internal1_m833_tim0)[i*5];
  for( i=0;i<80;i++ )
    array_m1248_x0_1[i] = &(&internal1_m1248_x0)[i*5];
  for( i=0;i<80;i++ )
    array_m1248_tim0_1[i] = &(&internal1_m1248_tim0)[i*5];
  for( i=0;i<20;i++ )
    array_m1612_x0_1[i] = &(&internal1_m1612_x0)[i*5];
  for( i=0;i<20;i++ )
    array_m1612_tim0_1[i] = &(&internal1_m1612_tim0)[i*5];
  for( i=0;i<20;i++ )
    array_m1137_x0_1[i] = &(&internal1_m1137_x0)[i*5];
  for( i=0;i<20;i++ )
    array_m1137_tim0_1[i] = &(&internal1_m1137_tim0)[i*5];
}

#endif
