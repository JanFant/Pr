#ifndef DU_H
#define DU_H
// Подсистема DU:DU
static char SimulOn=0;
static short CodeSub=2;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt, taktScheme=0, taktSS=0;
#define SIZE_BUFFER 12262
static char BUFFER[12262];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.50\0", 5432, "192.168.10.150\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0AB05LDU	 BUFFER[0]	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
#define idR0AB05LDU	 1	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
#define R0VN11RZ1	 BUFFER[2]	//( - , MDuBz1) Средняя мощность по BAZ1
#define idR0VN11RZ1	 2	//( - , MDuBz1) Средняя мощность по BAZ1
#define R0VN11RZ2	 BUFFER[7]	//( - , MDuBz2) Средняя мощность по BAZ2
#define idR0VN11RZ2	 3	//( - , MDuBz2) Средняя мощность по BAZ2
#define A2AB15LDU	 BUFFER[12]	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define idA2AB15LDU	 4	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define B2AB15LDU	 BUFFER[14]	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define idB2AB15LDU	 5	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define R0AD21LDU	 BUFFER[16]	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
#define idR0AD21LDU	 6	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
#define R0VX02LDU	 BUFFER[18]	//( - , DU) Импульс разрешен
#define idR0VX02LDU	 7	//( - , DU) Импульс разрешен
#define R0EE03LDU	 BUFFER[20]	//( - , DU) ВПИС ИС
#define idR0EE03LDU	 8	//( - , DU) ВПИС ИС
#define R0AB07LDU	 BUFFER[22]	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
#define idR0AB07LDU	 9	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
#define C2MD31LP1	 BUFFER[24]	//( - , DU) Кнопка СБРОС РБ
#define idC2MD31LP1	 10	//( - , DU) Кнопка СБРОС РБ
#define B6VS01IDU	 BUFFER[26]	//( - , DU) Готовность к управлению БЗ2
#define idB6VS01IDU	 11	//( - , DU) Готовность к управлению БЗ2
#define R2AD20LDU	 BUFFER[29]	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
#define idR2AD20LDU	 12	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
#define R2AD10LDU	 BUFFER[31]	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
#define idR2AD10LDU	 13	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
#define B8VS01IDU	 BUFFER[33]	//( - , DU) Готовность к управлению АЗ2
#define idB8VS01IDU	 14	//( - , DU) Готовность к управлению АЗ2
#define A8VS01IDU	 BUFFER[36]	//( - , DU) Готовность к управлению ДС2
#define idA8VS01IDU	 15	//( - , DU) Готовность к управлению ДС2
#define A1IE03LDU	 BUFFER[39]	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
#define idA1IE03LDU	 16	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
#define A1IE04LDU	 BUFFER[41]	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
#define idA1IE04LDU	 17	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
#define A2IE03LDU	 BUFFER[43]	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
#define idA2IE03LDU	 18	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
#define A2IE04LDU	 BUFFER[45]	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
#define idA2IE04LDU	 19	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
#define A3IE03LDU	 BUFFER[47]	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
#define idA3IE03LDU	 20	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
#define A3IE04LDU	 BUFFER[49]	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
#define idA3IE04LDU	 21	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
#define B1IE03LDU	 BUFFER[51]	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
#define idB1IE03LDU	 22	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
#define B1IE04LDU	 BUFFER[53]	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
#define idB1IE04LDU	 23	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
#define A1VN71LZ1	 BUFFER[55]	//(vds32:02 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define idA1VN71LZ1	 24	//(vds32:02 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define A1VN71LZ2	 BUFFER[57]	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define idA1VN71LZ2	 25	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define A1AB19LDU	 BUFFER[59]	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
#define idA1AB19LDU	 26	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
#define R0AD14LZ1	 BUFFER[61]	//(vds32:02 - K20VDSR, DU) Имитация срабатывания АЗ от II УР
#define idR0AD14LZ1	 27	//(vds32:02 - K20VDSR, DU) Имитация срабатывания АЗ от II УР
#define R0AD14LZ2	 BUFFER[63]	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
#define idR0AD14LZ2	 28	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
#define A3VZ13LZ2	 BUFFER[65]	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ2	 29	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define A3VZ13LZ1	 BUFFER[67]	//(vds32:02 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ1	 30	//(vds32:02 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define A3VZ15LZ1	 BUFFER[69]	//(vds32:02 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ1	 31	//(vds32:02 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define A3VZ15LZ2	 BUFFER[71]	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ2	 32	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define B2IS33LDU	 BUFFER[73]	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
#define idB2IS33LDU	 33	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
#define B3IS31LDU	 BUFFER[75]	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
#define idB3IS31LDU	 34	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
#define B3IS33LDU	 BUFFER[77]	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
#define idB3IS33LDU	 35	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
#define B3IS35LDU	 BUFFER[79]	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
#define idB3IS35LDU	 36	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
#define B4IS10LDU	 BUFFER[81]	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
#define idB4IS10LDU	 37	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
#define R6IS31LDU	 BUFFER[83]	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
#define idR6IS31LDU	 38	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
#define R6IS32LDU	 BUFFER[85]	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
#define idR6IS32LDU	 39	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
#define R6IS42LDU	 BUFFER[87]	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
#define idR6IS42LDU	 40	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
#define R6IS41LDU	 BUFFER[89]	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
#define idR6IS41LDU	 41	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
#define R6IS52LDU	 BUFFER[91]	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
#define idR6IS52LDU	 42	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
#define R6IS51LDU	 BUFFER[93]	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
#define idR6IS51LDU	 43	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
#define R3IS11LDU	 BUFFER[95]	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
#define idR3IS11LDU	 44	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
#define R3IS21LDU	 BUFFER[97]	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
#define idR3IS21LDU	 45	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
#define R0AB03LDU	 BUFFER[99]	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
#define idR0AB03LDU	 46	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
#define A9ZAV	 BUFFER[101]	//( - , DU) Завершение НИ ДС1(2)
#define idA9ZAV	 47	//( - , DU) Завершение НИ ДС1(2)
#define R4ABL	 BUFFER[103]	//( - , DU) Блокировка тележки -
#define idR4ABL	 48	//( - , DU) Блокировка тележки -
#define A4UP	 BUFFER[105]	//( - , DU) 
#define idA4UP	 49	//( - , DU) 
#define A4DW	 BUFFER[107]	//( - , DU) 
#define idA4DW	 50	//( - , DU) 
#define R0AB14LDU	 BUFFER[109]	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
#define idR0AB14LDU	 51	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
#define R0AB15LDU	 BUFFER[111]	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
#define idR0AB15LDU	 52	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
#define A3IS12LDU	 BUFFER[113]	//( - , DU) Приход на ВУ штока ИС1
#define idA3IS12LDU	 53	//( - , DU) Приход на ВУ штока ИС1
#define B3IS12LDU	 BUFFER[115]	//( - , DU) Приход на ВУ штока ИС2
#define idB3IS12LDU	 54	//( - , DU) Приход на ВУ штока ИС2
#define A1ZAV	 BUFFER[117]	//( - , DU) 
#define idA1ZAV	 55	//( - , DU) 
#define A3ZAV	 BUFFER[119]	//( - , DU) 
#define idA3ZAV	 56	//( - , DU) 
#define B1AB19LDU	 BUFFER[121]	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
#define idB1AB19LDU	 57	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
#define R0AB16LDU	 BUFFER[123]	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
#define idR0AB16LDU	 58	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
#define R0AB17LDU	 BUFFER[125]	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
#define idR0AB17LDU	 59	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
#define R0AB18LDU	 BUFFER[127]	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
#define idR0AB18LDU	 60	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
#define A0CT01IZ1	 BUFFER[129]	//( - , MDuBz1) Температура АЗ1-1
#define idA0CT01IZ1	 61	//( - , MDuBz1) Температура АЗ1-1
#define B0CT01IZ1	 BUFFER[134]	//( - , MDuBz1) Температура АЗ2-1
#define idB0CT01IZ1	 62	//( - , MDuBz1) Температура АЗ2-1
#define A0CT01IZ2	 BUFFER[139]	//( - , MDuBz2) Температура АЗ1-2
#define idA0CT01IZ2	 63	//( - , MDuBz2) Температура АЗ1-2
#define B0CT01IZ2	 BUFFER[144]	//( - , MDuBz2) Температура АЗ2-2
#define idB0CT01IZ2	 64	//( - , MDuBz2) Температура АЗ2-2
#define A3MC01RDU	 BUFFER[149]	//( - , DU) Заданная координата положения ИС от регулятора мм
#define idA3MC01RDU	 65	//( - , DU) Заданная координата положения ИС от регулятора мм
#define A3MC02RDU	 BUFFER[154]	//( - , DU) Температурная корректировка координаты ИМ
#define idA3MC02RDU	 66	//( - , DU) Температурная корректировка координаты ИМ
#define R0CN91LDU	 BUFFER[159]	//( - , DU) Рассчётная реактивность от регулятора
#define idR0CN91LDU	 67	//( - , DU) Рассчётная реактивность от регулятора
#define A3MC03RDU	 BUFFER[164]	//( - , DU) Координата положения ИМ 0-й реактивности
#define idA3MC03RDU	 68	//( - , DU) Координата положения ИМ 0-й реактивности
#define A3AB15LDU	 BUFFER[169]	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
#define idA3AB15LDU	 69	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
#define B2IE03LDU	 BUFFER[171]	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
#define idB2IE03LDU	 70	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
#define B2IE04LDU	 BUFFER[173]	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
#define idB2IE04LDU	 71	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
#define B3IE03LDU	 BUFFER[175]	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
#define idB3IE03LDU	 72	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
#define B3IE04LDU	 BUFFER[177]	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
#define idB3IE04LDU	 73	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
#define R0VS11LDU	 BUFFER[179]	//( - , DU) РУ не готова к работе
#define idR0VS11LDU	 74	//( - , DU) РУ не готова к работе
#define B6AB05LDU	 BUFFER[181]	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
#define idB6AB05LDU	 75	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
#define R0AB08LDU	 BUFFER[183]	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
#define idR0AB08LDU	 76	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
#define A1MC01RP1	 BUFFER[185]	//( - , DU) Заданная координата положения ББ1 мм
#define idA1MC01RP1	 77	//( - , DU) Заданная координата положения ББ1 мм
#define B1MC01RP1	 BUFFER[190]	//( - , DU) Заданная координата положения ББ2  мм
#define idB1MC01RP1	 78	//( - , DU) Заданная координата положения ББ2  мм
#define A3MC01RP1	 BUFFER[195]	//( - , DU) Заданная координата положения ИС1 мм
#define idA3MC01RP1	 79	//( - , DU) Заданная координата положения ИС1 мм
#define B3MC01RP1	 BUFFER[200]	//( - , DU) Заданная координата положения ИС2 мм
#define idB3MC01RP1	 80	//( - , DU) Заданная координата положения ИС2 мм
#define B8MC01RP2	 BUFFER[205]	//( - , DU) Заданная координата АЗ2 мм
#define idB8MC01RP2	 81	//( - , DU) Заданная координата АЗ2 мм
#define R0AB09LDU	 BUFFER[210]	//( - , DU) Ошибка в заданной координате ББ1
#define idR0AB09LDU	 82	//( - , DU) Ошибка в заданной координате ББ1
#define R0AB10LDU	 BUFFER[212]	//( - , DU) Ошибка в заданной координате ББ2
#define idR0AB10LDU	 83	//( - , DU) Ошибка в заданной координате ББ2
#define R0AB11LDU	 BUFFER[214]	//( - , DU) Ошибка в заданной координате  ИС1
#define idR0AB11LDU	 84	//( - , DU) Ошибка в заданной координате  ИС1
#define R0AB12LDU	 BUFFER[216]	//( - , DU) Ошибка в заданной координате  ИС2
#define idR0AB12LDU	 85	//( - , DU) Ошибка в заданной координате  ИС2
#define R0AB13LDU	 BUFFER[218]	//( - , DU) Ошибка в заданной координате  АЗ2
#define idR0AB13LDU	 86	//( - , DU) Ошибка в заданной координате  АЗ2
#define A4ZAV	 BUFFER[220]	//( - , DU) 
#define idA4ZAV	 87	//( - , DU) 
#define A6ZAV	 BUFFER[222]	//( - , DU) 
#define idA6ZAV	 88	//( - , DU) 
#define R2ZAV	 BUFFER[224]	//( - , DU) 
#define idR2ZAV	 89	//( - , DU) 
#define A5ZAV	 BUFFER[226]	//( - , DU) 
#define idA5ZAV	 90	//( - , DU) 
#define B8ZAV	 BUFFER[228]	//( - , DU) 
#define idB8ZAV	 91	//( - , DU) 
#define A2ZAV	 BUFFER[230]	//( - , DU) Завершение РБ1,2
#define idA2ZAV	 92	//( - , DU) Завершение РБ1,2
#define A8ZAV	 BUFFER[232]	//( - , DU) 
#define idA8ZAV	 93	//( - , DU) 
#define B9AB01LDU	 BUFFER[234]	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
#define idB9AB01LDU	 94	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
#define B9AB02LDU	 BUFFER[236]	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
#define idB9AB02LDU	 95	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
#define R0AB01LDU	 BUFFER[238]	//( - , DU) Режим проверки разрешён
#define idR0AB01LDU	 96	//( - , DU) Режим проверки разрешён
#define A3IS22LDU	 BUFFER[240]	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
#define idA3IS22LDU	 97	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
#define B3IS22LDU	 BUFFER[242]	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
#define idB3IS22LDU	 98	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
#define A2AD33LDU	 BUFFER[244]	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
#define idA2AD33LDU	 99	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
#define B2AD33LDU	 BUFFER[246]	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
#define idB2AD33LDU	 100	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
#define A3AD33LDU	 BUFFER[248]	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
#define idA3AD33LDU	 101	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
#define A3AD34LDU	 BUFFER[250]	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
#define idA3AD34LDU	 102	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
#define A3AD31LDU	 BUFFER[252]	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
#define idA3AD31LDU	 103	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
#define B3AD34LDU	 BUFFER[254]	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
#define idB3AD34LDU	 104	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
#define B3AD31LDU	 BUFFER[256]	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
#define idB3AD31LDU	 105	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
#define A2IS11LDU	 BUFFER[258]	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
#define idA2IS11LDU	 106	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
#define B2IS11LDU	 BUFFER[260]	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
#define idB2IS11LDU	 107	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
#define A3MD12LP1	 BUFFER[262]	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
#define idA3MD12LP1	 108	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
#define A3MD11LP1	 BUFFER[264]	//( - , DU) Кнопка ПУСК ИС1
#define idA3MD11LP1	 109	//( - , DU) Кнопка ПУСК ИС1
#define R0MD33LP1	 BUFFER[266]	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
#define idR0MD33LP1	 110	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
#define A1MD12LP1	 BUFFER[268]	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
#define idA1MD12LP1	 111	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
#define A1MD11LP1	 BUFFER[270]	//( - , DU) Кнопка ПУСК ББ1
#define idA1MD11LP1	 112	//( - , DU) Кнопка ПУСК ББ1
#define R0MW14IP2	 BUFFER[272]	//( - , DU) Переключатель ОБДУВ
#define idR0MW14IP2	 113	//( - , DU) Переключатель ОБДУВ
#define A7AP31LDU	 BUFFER[275]	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
#define idA7AP31LDU	 114	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
#define B7AP31LDU	 BUFFER[277]	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
#define idB7AP31LDU	 115	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
#define R0MW12IP2	 BUFFER[279]	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define idR0MW12IP2	 116	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define B3VS01IDU	 BUFFER[282]	//( - , DU) Готовность к управлению ИС2
#define idB3VS01IDU	 117	//( - , DU) Готовность к управлению ИС2
#define A2VS01IDU	 BUFFER[285]	//( - , DU) Готовность к управлению РБ1
#define idA2VS01IDU	 118	//( - , DU) Готовность к управлению РБ1
#define A4VS01IDU	 BUFFER[288]	//( - , DU) Готовность к управлению НИ1
#define idA4VS01IDU	 119	//( - , DU) Готовность к управлению НИ1
#define A4VS12LDU	 BUFFER[291]	//( - , DU) Движение НИ1 в сторону ВУ
#define idA4VS12LDU	 120	//( - , DU) Движение НИ1 в сторону ВУ
#define A4VS22LDU	 BUFFER[293]	//( - , DU) Движение НИ1 в сторону НУ
#define idA4VS22LDU	 121	//( - , DU) Движение НИ1 в сторону НУ
#define B4VS01IDU	 BUFFER[295]	//( - , DU) Готовность к управлению НИ2
#define idB4VS01IDU	 122	//( - , DU) Готовность к управлению НИ2
#define B4VS12LDU	 BUFFER[298]	//( - , DU) Движение НИ2 в сторону ВУ
#define idB4VS12LDU	 123	//( - , DU) Движение НИ2 в сторону ВУ
#define B4VS22LDU	 BUFFER[300]	//( - , DU) Движение НИ2 в сторону НУ
#define idB4VS22LDU	 124	//( - , DU) Движение НИ2 в сторону НУ
#define A5VS01IDU	 BUFFER[302]	//( - , DU) Готовность к управлению НЛ1
#define idA5VS01IDU	 125	//( - , DU) Готовность к управлению НЛ1
#define B5VS01IDU	 BUFFER[305]	//( - , DU) Готовность к управлению НЛ2
#define idB5VS01IDU	 126	//( - , DU) Готовность к управлению НЛ2
#define A6VS01IDU	 BUFFER[308]	//( - , DU) Готовность к управлению БЗ1
#define idA6VS01IDU	 127	//( - , DU) Готовность к управлению БЗ1
#define R4VS01IDU	 BUFFER[311]	//( - , DU) Готовность к управлению тележкой реактора
#define idR4VS01IDU	 128	//( - , DU) Готовность к управлению тележкой реактора
#define R2VS01IDU	 BUFFER[314]	//( - , DU) Готовность к управлению МДЗ2
#define idR2VS01IDU	 129	//( - , DU) Готовность к управлению МДЗ2
#define R1VS01IDU	 BUFFER[317]	//( - , DU) Готовность к управлению МДЗ1
#define idR1VS01IDU	 130	//( - , DU) Готовность к управлению МДЗ1
#define A9IS11LDU	 BUFFER[320]	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
#define idA9IS11LDU	 131	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
#define A9IS21LDU	 BUFFER[322]	//(vds32:02 - K24VDSR, DU) Приход на НУ НИ ДС1
#define idA9IS21LDU	 132	//(vds32:02 - K24VDSR, DU) Приход на НУ НИ ДС1
#define B9IS11LDU	 BUFFER[324]	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
#define idB9IS11LDU	 133	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
#define B9IS21LDU	 BUFFER[326]	//(vds32:02 - K26VDSR, DU) Приход на НУ НИ ДС2
#define idB9IS21LDU	 134	//(vds32:02 - K26VDSR, DU) Приход на НУ НИ ДС2
#define B9AD10LDU	 BUFFER[328]	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
#define idB9AD10LDU	 135	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
#define A9AD10LDU	 BUFFER[330]	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
#define idA9AD10LDU	 136	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
#define A9AZ03LDU	 BUFFER[332]	//( - , DU) Несанкционированное перемещение НИ ДС1
#define idA9AZ03LDU	 137	//( - , DU) Несанкционированное перемещение НИ ДС1
#define A9AB01LDU	 BUFFER[334]	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
#define idA9AB01LDU	 138	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
#define A9AB02LDU	 BUFFER[336]	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
#define idA9AB02LDU	 139	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
#define B9AZ03LDU	 BUFFER[338]	//( - , DU) Несанкционированное перемещение НИ ДС2
#define idB9AZ03LDU	 140	//( - , DU) Несанкционированное перемещение НИ ДС2
#define R0MD34LP1	 BUFFER[340]	//( - , DU) Кнопка КВИТИРОВАТЬ
#define idR0MD34LP1	 141	//( - , DU) Кнопка КВИТИРОВАТЬ
#define A0VT71LZ1	 BUFFER[342]	//( - , MDuBz1) АС по температуре в АЗ1
#define idA0VT71LZ1	 142	//( - , MDuBz1) АС по температуре в АЗ1
#define B0VT71LZ1	 BUFFER[344]	//( - , MDuBz1) АС по температуре в АЗ2
#define idB0VT71LZ1	 143	//( - , MDuBz1) АС по температуре в АЗ2
#define A0VT71LZ2	 BUFFER[346]	//( - , MDuBz2) АС по температуре в АЗ1
#define idA0VT71LZ2	 144	//( - , MDuBz2) АС по температуре в АЗ1
#define B0VT71LZ2	 BUFFER[348]	//( - , MDuBz2) АС по температуре в АЗ2
#define idB0VT71LZ2	 145	//( - , MDuBz2) АС по температуре в АЗ2
#define B2VS11LDU	 BUFFER[350]	//( - , DU) Движение РБ2 в сторону ВУ
#define idB2VS11LDU	 146	//( - , DU) Движение РБ2 в сторону ВУ
#define B2VS21LDU	 BUFFER[352]	//( - , DU) Движение РБ2 в сторону НУ
#define idB2VS21LDU	 147	//( - , DU) Движение РБ2 в сторону НУ
#define B2VS01IDU	 BUFFER[354]	//( - , DU) Готовность к управлению РБ2
#define idB2VS01IDU	 148	//( - , DU) Готовность к управлению РБ2
#define A7AS31LDU	 BUFFER[357]	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
#define idA7AS31LDU	 149	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
#define B7AS31LDU	 BUFFER[359]	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
#define idB7AS31LDU	 150	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
#define A7AZ03LDU	 BUFFER[361]	//( - , DU) Несанкционированное включение обдува АЗ1
#define idA7AZ03LDU	 151	//( - , DU) Несанкционированное включение обдува АЗ1
#define B7AZ03LDU	 BUFFER[363]	//( - , DU) Несанкционированное включение обдува АЗ2
#define idB7AZ03LDU	 152	//( - , DU) Несанкционированное включение обдува АЗ2
#define B3MD12LP1	 BUFFER[365]	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
#define idB3MD12LP1	 153	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
#define B3MD11LP1	 BUFFER[367]	//( - , DU) Кнопка ПУСК ИС2
#define idB3MD11LP1	 154	//( - , DU) Кнопка ПУСК ИС2
#define R0VL01RDU	 BUFFER[369]	//( - , DU) Индикация Время задержки
#define idR0VL01RDU	 155	//( - , DU) Индикация Время задержки
#define R0VZ71LZ2	 BUFFER[374]	//(vds32:03 - K22VDSR, - ) Обобщенный сигнал АЗ 2 канала
#define idR0VZ71LZ2	 156	//(vds32:03 - K22VDSR, - ) Обобщенный сигнал АЗ 2 канала
#define R0VZ71LZ1	 BUFFER[376]	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
#define idR0VZ71LZ1	 157	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
#define R0VZ71LDU	 BUFFER[378]	//( - , DU) Обобщенный сигнал АЗ
#define idR0VZ71LDU	 158	//( - , DU) Обобщенный сигнал АЗ
#define A2IS33LDU	 BUFFER[380]	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
#define idA2IS33LDU	 159	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
#define A3IS31LDU	 BUFFER[382]	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
#define idA3IS31LDU	 160	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
#define A3IS33LDU	 BUFFER[384]	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
#define idA3IS33LDU	 161	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
#define A3IS35LDU	 BUFFER[386]	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
#define idA3IS35LDU	 162	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
#define A4IS10LDU	 BUFFER[388]	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
#define idA4IS10LDU	 163	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
#define R0MW17LP1	 BUFFER[390]	//( - , DU) Переключатель АВТ/Р
#define idR0MW17LP1	 164	//( - , DU) Переключатель АВТ/Р
#define R0VW13LDU	 BUFFER[392]	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
#define idR0VW13LDU	 165	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
#define R0VW23LDU	 BUFFER[394]	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
#define idR0VW23LDU	 166	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
#define R0VX08IDU	 BUFFER[396]	//( - , DU) Индикация Режим
#define idR0VX08IDU	 167	//( - , DU) Индикация Режим
#define R0VX09LDU	 BUFFER[399]	//( - , DU) Индикация регулятор мощности включен/отключен
#define idR0VX09LDU	 168	//( - , DU) Индикация регулятор мощности включен/отключен
#define R0VS17LDU	 BUFFER[401]	//( - , DU) Индикация выбора АВТОМАТ
#define idR0VS17LDU	 169	//( - , DU) Индикация выбора АВТОМАТ
#define A2VS32LDU	 BUFFER[403]	//( - , DU) Индикация  СБРОС РБ1
#define idA2VS32LDU	 170	//( - , DU) Индикация  СБРОС РБ1
#define B2VS32LDU	 BUFFER[405]	//( - , DU) Индикация  СБРОС РБ2
#define idB2VS32LDU	 171	//( - , DU) Индикация  СБРОС РБ2
#define A3VX01LDU	 BUFFER[407]	//( - , DU) Индикация Выстрел ИС1
#define idA3VX01LDU	 172	//( - , DU) Индикация Выстрел ИС1
#define B3VX01LDU	 BUFFER[409]	//( - , DU) Индикация Выстрел ИС2
#define idB3VX01LDU	 173	//( - , DU) Индикация Выстрел ИС2
#define R0VS18LDU	 BUFFER[411]	//( - , DU) Индикация  Проверка схем сброса
#define idR0VS18LDU	 174	//( - , DU) Индикация  Проверка схем сброса
#define B1MD11LP1	 BUFFER[413]	//( - , DU) Кнопка ПУСК ББ2
#define idB1MD11LP1	 175	//( - , DU) Кнопка ПУСК ББ2
#define B1MD12LP1	 BUFFER[415]	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
#define idB1MD12LP1	 176	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
#define B2MD11LP1	 BUFFER[417]	//( - , DU) Кнопка ПУСК РБ2
#define idB2MD11LP1	 177	//( - , DU) Кнопка ПУСК РБ2
#define B2MD12LP1	 BUFFER[419]	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
#define idB2MD12LP1	 178	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
#define A2MD11LP1	 BUFFER[421]	//( - , DU) Кнопка ПУСК РБ1
#define idA2MD11LP1	 179	//( - , DU) Кнопка ПУСК РБ1
#define A2MD12LP1	 BUFFER[423]	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
#define idA2MD12LP1	 180	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
#define B3IS11LDU	 BUFFER[425]	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
#define idB3IS11LDU	 181	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
#define A3IS11LDU	 BUFFER[427]	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
#define idA3IS11LDU	 182	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
#define R0IS01LDU	 BUFFER[429]	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
#define idR0IS01LDU	 183	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
#define R0IS02LDU	 BUFFER[431]	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
#define idR0IS02LDU	 184	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
#define R0VP73LZ1	 BUFFER[433]	//( - , MDuBz1) ПС давления для РУ
#define idR0VP73LZ1	 185	//( - , MDuBz1) ПС давления для РУ
#define R0VP73LZ2	 BUFFER[435]	//( - , MDuBz2) ПС давления для РУ
#define idR0VP73LZ2	 186	//( - , MDuBz2) ПС давления для РУ
#define R0VP73LDU	 BUFFER[437]	//( - , DU) ПС давления для РУ
#define idR0VP73LDU	 187	//( - , DU) ПС давления для РУ
#define A3VP82LDU	 BUFFER[439]	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
#define idA3VP82LDU	 188	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
#define A3IP02IDU	 BUFFER[441]	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	 189	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
#define B3IP02IDU	 BUFFER[444]	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
#define idB3IP02IDU	 190	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
#define A0VE01LDU	 BUFFER[447]	//( - , DU) Напряжение в системы АЗ1 подано
#define idA0VE01LDU	 191	//( - , DU) Напряжение в системы АЗ1 подано
#define B0VE01LDU	 BUFFER[449]	//( - , DU) Напряжение в системы АЗ2 подано
#define idB0VE01LDU	 192	//( - , DU) Напряжение в системы АЗ2 подано
#define A0VP01LDU	 BUFFER[451]	//( - , DU) Давление в системы АЗ1 подано
#define idA0VP01LDU	 193	//( - , DU) Давление в системы АЗ1 подано
#define B0VP01LDU	 BUFFER[453]	//( - , DU) Давление в системы АЗ2 подано
#define idB0VP01LDU	 194	//( - , DU) Давление в системы АЗ2 подано
#define A0EE01LZ1	 BUFFER[455]	//( - , MDuBz1) Исправность АКНП1
#define idA0EE01LZ1	 195	//( - , MDuBz1) Исправность АКНП1
#define A0EE03LZ1	 BUFFER[457]	//( - , MDuBz1) Исправность АКНП3
#define idA0EE03LZ1	 196	//( - , MDuBz1) Исправность АКНП3
#define A0EE02LZ1	 BUFFER[459]	//( - , MDuBz1) Исправность АКНП2
#define idA0EE02LZ1	 197	//( - , MDuBz1) Исправность АКНП2
#define A0EE04LZ1	 BUFFER[461]	//( - , MDuBz1) Исправность АКНП4
#define idA0EE04LZ1	 198	//( - , MDuBz1) Исправность АКНП4
#define A0VN01LDU	 BUFFER[463]	//( - , DU) Каналы АЗ1 проверены
#define idA0VN01LDU	 199	//( - , DU) Каналы АЗ1 проверены
#define B0VN01LDU	 BUFFER[465]	//( - , DU) Каналы АЗ2 проверены
#define idB0VN01LDU	 200	//( - , DU) Каналы АЗ2 проверены
#define A0EE01LZ2	 BUFFER[467]	//( - , MDuBz2) Исправность АКНП1
#define idA0EE01LZ2	 201	//( - , MDuBz2) Исправность АКНП1
#define A0EE03LZ2	 BUFFER[469]	//( - , MDuBz2) Исправность АКНП3
#define idA0EE03LZ2	 202	//( - , MDuBz2) Исправность АКНП3
#define A0EE02LZ2	 BUFFER[471]	//( - , MDuBz2) Исправность АКНП2
#define idA0EE02LZ2	 203	//( - , MDuBz2) Исправность АКНП2
#define A0EE04LZ2	 BUFFER[473]	//( - , MDuBz2) Исправность АКНП4
#define idA0EE04LZ2	 204	//( - , MDuBz2) Исправность АКНП4
#define A0VP71LZ1	 BUFFER[475]	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ1	 205	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
#define A0VP71LZ2	 BUFFER[477]	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ2	 206	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
#define B0VP71LZ1	 BUFFER[479]	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ1	 207	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
#define B0VP71LZ2	 BUFFER[481]	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ2	 208	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
#define A0VS11LDU	 BUFFER[483]	//( - , DU) АЗ1 готова к работе
#define idA0VS11LDU	 209	//( - , DU) АЗ1 готова к работе
#define B0VS11LDU	 BUFFER[485]	//( - , DU) АЗ2 готова к работе
#define idB0VS11LDU	 210	//( - , DU) АЗ2 готова к работе
#define A1IS11LDU	 BUFFER[487]	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
#define idA1IS11LDU	 211	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
#define B1MC01LC1	 BUFFER[489]	//( - , DU) Настроить энкодер ББ2
#define idB1MC01LC1	 212	//( - , DU) Настроить энкодер ББ2
#define B1MC01LC2	 BUFFER[491]	//( - , DU) Настроить энкодер ББ2
#define idB1MC01LC2	 213	//( - , DU) Настроить энкодер ББ2
#define A1MC01LC1	 BUFFER[493]	//( - , DU) Настроить энкодер ББ1
#define idA1MC01LC1	 214	//( - , DU) Настроить энкодер ББ1
#define A1MC01LC2	 BUFFER[495]	//( - , DU) Настроить энкодер ББ1
#define idA1MC01LC2	 215	//( - , DU) Настроить энкодер ББ1
#define B2MC01LC1	 BUFFER[497]	//( - , DU) Настроить энкодер РБ2
#define idB2MC01LC1	 216	//( - , DU) Настроить энкодер РБ2
#define B2MC01LC2	 BUFFER[499]	//( - , DU) Настроить энкодер РБ2
#define idB2MC01LC2	 217	//( - , DU) Настроить энкодер РБ2
#define A2MC01LC1	 BUFFER[501]	//( - , DU) Настроить энкодер РБ1
#define idA2MC01LC1	 218	//( - , DU) Настроить энкодер РБ1
#define A2MC01LC2	 BUFFER[503]	//( - , DU) Настроить энкодер РБ1
#define idA2MC01LC2	 219	//( - , DU) Настроить энкодер РБ1
#define B3MC01LC1	 BUFFER[505]	//( - , DU) Настроить энкодер ИС2
#define idB3MC01LC1	 220	//( - , DU) Настроить энкодер ИС2
#define B3MC01LC2	 BUFFER[507]	//( - , DU) Настроить энкодер ИС2
#define idB3MC01LC2	 221	//( - , DU) Настроить энкодер ИС2
#define A3MC01LC1	 BUFFER[509]	//( - , DU) Настроить энкодер ИС1
#define idA3MC01LC1	 222	//( - , DU) Настроить энкодер ИС1
#define A3MC01LC2	 BUFFER[511]	//( - , DU) Настроить энкодер ИС1
#define idA3MC01LC2	 223	//( - , DU) Настроить энкодер ИС1
#define B8MC01LC1	 BUFFER[513]	//( - , DU) Настроить энкодер АЗ2
#define idB8MC01LC1	 224	//( - , DU) Настроить энкодер АЗ2
#define B8MC01LC2	 BUFFER[515]	//( - , DU) Настроить энкодер АЗ2
#define idB8MC01LC2	 225	//( - , DU) Настроить энкодер АЗ2
#define A8MC01LC1	 BUFFER[517]	//( - , DU) Настроить энкодер ДС2
#define idA8MC01LC1	 226	//( - , DU) Настроить энкодер ДС2
#define A8MC01LC2	 BUFFER[519]	//( - , DU) Настроить энкодер ДС2
#define idA8MC01LC2	 227	//( - , DU) Настроить энкодер ДС2
#define A3VP42LDU	 BUFFER[521]	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
#define idA3VP42LDU	 228	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
#define A3CP02RDU	 BUFFER[523]	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
#define idA3CP02RDU	 229	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
#define A3VP52LDU	 BUFFER[528]	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define idA3VP52LDU	 230	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define B3VP42LDU	 BUFFER[530]	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
#define idB3VP42LDU	 231	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
#define B3CP02RDU	 BUFFER[532]	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
#define idB3CP02RDU	 232	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
#define B3VP52LDU	 BUFFER[537]	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define idB3VP52LDU	 233	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define B3VP82LDU	 BUFFER[539]	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
#define idB3VP82LDU	 234	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
#define R6IS68LZZ	 BUFFER[541]	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 235	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define A3VC01RDU	 BUFFER[543]	//( - , DU) Координата ИС1, мм
#define idA3VC01RDU	 236	//( - , DU) Координата ИС1, мм
#define A2VC01RDU	 BUFFER[548]	//( - , DU) Координата РБ1, мм
#define idA2VC01RDU	 237	//( - , DU) Координата РБ1, мм
#define B2VC01RDU	 BUFFER[553]	//( - , DU) Координата РБ2, мм
#define idB2VC01RDU	 238	//( - , DU) Координата РБ2, мм
#define B8VC01RDU	 BUFFER[558]	//( - , DU, MDuBz1, MDuBz2) Координата АЗ2, мм
#define idB8VC01RDU	 239	//( - , DU, MDuBz1, MDuBz2) Координата АЗ2, мм
#define A4VP82LDU	 BUFFER[563]	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	 240	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define B4VP82LDU	 BUFFER[565]	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	 241	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define A2VP82LDU	 BUFFER[567]	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	 242	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define B2VP82LDU	 BUFFER[569]	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define idB2VP82LDU	 243	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define A3VP81LDU	 BUFFER[571]	//( - , - ) Давление СПУСК ИС1 в норме
#define idA3VP81LDU	 244	//( - , - ) Давление СПУСК ИС1 в норме
#define B3VP81LDU	 BUFFER[573]	//( - , - ) Давление СПУСК ИС2 в норме
#define idB3VP81LDU	 245	//( - , - ) Давление СПУСК ИС2 в норме
#define R0EE02LDU	 BUFFER[575]	//( - , DU) Питание  АКНП  отключить
#define idR0EE02LDU	 246	//( - , DU) Питание  АКНП  отключить
#define psaz11	 BUFFER[577]	//( - , DU) каналы
#define idpsaz11	 247	//( - , DU) каналы
#define psaz12	 BUFFER[579]	//( - , DU) напряжение
#define idpsaz12	 248	//( - , DU) напряжение
#define psaz13	 BUFFER[581]	//( - , DU) давление
#define idpsaz13	 249	//( - , DU) давление
#define psaz14	 BUFFER[583]	//( - , DU) ас темп з2
#define idpsaz14	 250	//( - , DU) ас темп з2
#define psaz15	 BUFFER[585]	//( - , DU) ас темп з1
#define idpsaz15	 251	//( - , DU) ас темп з1
#define psaz21	 BUFFER[587]	//( - , DU) каналы
#define idpsaz21	 252	//( - , DU) каналы
#define psaz22	 BUFFER[589]	//( - , DU) напряжение
#define idpsaz22	 253	//( - , DU) напряжение
#define psaz23	 BUFFER[591]	//( - , DU) давление
#define idpsaz23	 254	//( - , DU) давление
#define psaz24	 BUFFER[593]	//( - , DU) ас темп з2
#define idpsaz24	 255	//( - , DU) ас темп з2
#define psaz25	 BUFFER[595]	//( - , DU) питание
#define idpsaz25	 256	//( - , DU) питание
#define psaz3	 BUFFER[597]	//( - , DU) энкодеры
#define idpsaz3	 257	//( - , DU) энкодеры
#define A1IE01LDU	 BUFFER[599]	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
#define idA1IE01LDU	 258	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
#define A3IE01LDU	 BUFFER[601]	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
#define idA3IE01LDU	 259	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
#define A2IE01LDU	 BUFFER[603]	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
#define idA2IE01LDU	 260	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
#define A1IE02LDU	 BUFFER[605]	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
#define idA1IE02LDU	 261	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
#define A3IE02LDU	 BUFFER[607]	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
#define idA3IE02LDU	 262	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
#define A2IE02LDU	 BUFFER[609]	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
#define idA2IE02LDU	 263	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
#define B1IE01LDU	 BUFFER[611]	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
#define idB1IE01LDU	 264	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
#define B2IE01LDU	 BUFFER[613]	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
#define idB2IE01LDU	 265	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
#define B3IE01LDU	 BUFFER[615]	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
#define idB3IE01LDU	 266	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
#define B1IE02LDU	 BUFFER[617]	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
#define idB1IE02LDU	 267	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
#define B3IE02LDU	 BUFFER[619]	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
#define idB3IE02LDU	 268	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
#define B2IE02LDU	 BUFFER[621]	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
#define idB2IE02LDU	 269	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
#define R0IE02LDU	 BUFFER[623]	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
#define idR0IE02LDU	 270	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
#define R0IE01LDU	 BUFFER[625]	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
#define idR0IE01LDU	 271	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
#define A6IE01LDU	 BUFFER[627]	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
#define idA6IE01LDU	 272	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
#define B6IE01LDU	 BUFFER[629]	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
#define idB6IE01LDU	 273	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
#define A8IE01LDU	 BUFFER[631]	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
#define idA8IE01LDU	 274	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
#define B5IE01LDU	 BUFFER[633]	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
#define idB5IE01LDU	 275	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
#define A5IE02LDU	 BUFFER[635]	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
#define idA5IE02LDU	 276	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
#define R1IE01LDU	 BUFFER[637]	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
#define idR1IE01LDU	 277	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
#define R2IE01LDU	 BUFFER[639]	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
#define idR2IE01LDU	 278	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
#define R6IS61LDU	 BUFFER[641]	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
#define idR6IS61LDU	 279	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
#define R6IS66LZZ	 BUFFER[643]	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 280	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	 BUFFER[645]	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 281	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define A3EE03LDU	 BUFFER[647]	//( - , DU) ВПИС ИС1
#define idA3EE03LDU	 282	//( - , DU) ВПИС ИС1
#define B3EE03LDU	 BUFFER[649]	//( - , DU) ВПИС ИС2
#define idB3EE03LDU	 283	//( - , DU) ВПИС ИС2
#define B3AB15LDU	 BUFFER[651]	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
#define idB3AB15LDU	 284	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
#define R5IS21LDU	 BUFFER[653]	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	 285	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
#define R5VS22LDU	 BUFFER[655]	//( - , DU) Движение ворот отстойной зоны к закрыты
#define idR5VS22LDU	 286	//( - , DU) Движение ворот отстойной зоны к закрыты
#define R5VS12LDU	 BUFFER[657]	//( - , DU) Движение ворот отстойной зоны к открыты
#define idR5VS12LDU	 287	//( - , DU) Движение ворот отстойной зоны к открыты
#define R5VS01IDU	 BUFFER[659]	//( - , DU) Готовность к управлению ворот отстойной зоны
#define idR5VS01IDU	 288	//( - , DU) Готовность к управлению ворот отстойной зоны
#define R3VS22LDU	 BUFFER[662]	//( - , DU) Движение гомогенных дверей к закрыты
#define idR3VS22LDU	 289	//( - , DU) Движение гомогенных дверей к закрыты
#define R3VS12LDU	 BUFFER[664]	//( - , DU) Движение гомогенных дверей к открыты
#define idR3VS12LDU	 290	//( - , DU) Движение гомогенных дверей к открыты
#define R3VS01IDU	 BUFFER[666]	//( - , DU) Готовность к управлению гомогенных дверей
#define idR3VS01IDU	 291	//( - , DU) Готовность к управлению гомогенных дверей
#define A3AB13LDU	 BUFFER[669]	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
#define idA3AB13LDU	 292	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
#define B3AB13LDU	 BUFFER[671]	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define idB3AB13LDU	 293	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define R0DE02LDU	 BUFFER[673]	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
#define idR0DE02LDU	 294	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
#define R0DE03LDU	 BUFFER[676]	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
#define idR0DE03LDU	 295	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
#define R0DE04LDU	 BUFFER[679]	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
#define idR0DE04LDU	 296	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
#define R0DE08LDU	 BUFFER[682]	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
#define idR0DE08LDU	 297	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
#define R0DE05LDU	 BUFFER[685]	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
#define idR0DE05LDU	 298	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
#define R0DE09LDU	 BUFFER[688]	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
#define idR0DE09LDU	 299	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
#define R0DE0ALDU	 BUFFER[691]	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
#define idR0DE0ALDU	 300	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
#define R0DE07LDU	 BUFFER[694]	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
#define idR0DE07LDU	 301	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
#define R0DE0CLDU	 BUFFER[697]	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
#define idR0DE0CLDU	 302	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
#define R0DE0BLDU	 BUFFER[700]	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
#define idR0DE0BLDU	 303	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
#define R0DE0DLDU	 BUFFER[703]	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
#define idR0DE0DLDU	 304	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
#define R0AB20LDU	 BUFFER[706]	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
#define idR0AB20LDU	 305	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
#define R0CN92LDU	 BUFFER[708]	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
#define idR0CN92LDU	 306	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
#define R0VN11RDU	 BUFFER[713]	//( - , DU) Текущая мощность РУ
#define idR0VN11RDU	 307	//( - , DU) Текущая мощность РУ
#define R0VN12RDU	 BUFFER[718]	//( - , DU) Заданная мощность РУ
#define idR0VN12RDU	 308	//( - , DU) Заданная мощность РУ
#define R0AB19LDU	 BUFFER[723]	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
#define idR0AB19LDU	 309	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
#define R0CN93LDU	 BUFFER[725]	//( - , DU) время работы на мощности более 100Вт, сек
#define idR0CN93LDU	 310	//( - , DU) время работы на мощности более 100Вт, сек
#define R0CN94LDU	 BUFFER[730]	//( - , DU) Скорость изменения мощности
#define idR0CN94LDU	 311	//( - , DU) Скорость изменения мощности
#define R0CN95LDU	 BUFFER[735]	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
#define idR0CN95LDU	 312	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
#define R0AD03LZ1	 BUFFER[738]	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
#define idR0AD03LZ1	 313	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
#define R0AD03LZ2	 BUFFER[740]	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
#define idR0AD03LZ2	 314	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
#define R0AD04LZ1	 BUFFER[742]	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define idR0AD04LZ1	 315	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define R0AD04LZ2	 BUFFER[744]	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define idR0AD04LZ2	 316	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define R0AD05LZ1	 BUFFER[746]	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
#define idR0AD05LZ1	 317	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
#define R0AD05LZ2	 BUFFER[748]	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
#define idR0AD05LZ2	 318	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
#define B8IS12LDU	 BUFFER[750]	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
#define idB8IS12LDU	 319	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
#define B8IS21LDU	 BUFFER[752]	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
#define idB8IS21LDU	 320	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
#define A1VP41LZ1	 BUFFER[754]	//( - , MDuBz1) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ1	 321	//( - , MDuBz1) Давление СБРОС ББ1 ниже АС
#define A1VP41LZ2	 BUFFER[756]	//( - , MDuBz2) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ2	 322	//( - , MDuBz2) Давление СБРОС ББ1 ниже АС
#define R0VL22LDU	 BUFFER[758]	//( - , DU) Конец программы 200сек
#define idR0VL22LDU	 323	//( - , DU) Конец программы 200сек
#define R0VL23LDU	 BUFFER[760]	//( - , DU) Конец программы 20мин
#define idR0VL23LDU	 324	//( - , DU) Конец программы 20мин
#define B1VP41LZ1	 BUFFER[762]	//( - , MDuBz1) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ1	 325	//( - , MDuBz1) Давление СБРОС ББ2 ниже АС
#define B1VP41LZ2	 BUFFER[764]	//( - , MDuBz2) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ2	 326	//( - , MDuBz2) Давление СБРОС ББ2 ниже АС
#define A3AB19LDU	 BUFFER[766]	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
#define idA3AB19LDU	 327	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
#define B3AB19LDU	 BUFFER[768]	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
#define idB3AB19LDU	 328	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
#define R0S01LZ1	 BUFFER[770]	//(fds16:07 - K15FDSR, - ) Отключение сетевых передач в Баз1
#define idR0S01LZ1	 329	//(fds16:07 - K15FDSR, - ) Отключение сетевых передач в Баз1
#define R0S01LZ2	 BUFFER[772]	//(fds16:07 - K16FDSR, - ) Отключение сетевых передач в Баз2
#define idR0S01LZ2	 330	//(fds16:07 - K16FDSR, - ) Отключение сетевых передач в Баз2
#define R0AD16LDU	 BUFFER[774]	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
#define idR0AD16LDU	 331	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
#define R0S01LIM	 BUFFER[776]	//(fds16:08 - K15FDSR, - ) Отключение сетевых передач ПТИ
#define idR0S01LIM	 332	//(fds16:08 - K15FDSR, - ) Отключение сетевых передач ПТИ
#define psb1	 BUFFER[778]	//( - , DU) ру не готова
#define idpsb1	 333	//( - , DU) ру не готова
#define psb2	 BUFFER[780]	//( - , DU) движение бб
#define idpsb2	 334	//( - , DU) движение бб
#define psrb4	 BUFFER[782]	//( - , DU) кнопка сброс
#define idpsrb4	 335	//( - , DU) кнопка сброс
#define psrb1	 BUFFER[784]	//( - , DU) пневматика по мощности
#define idpsrb1	 336	//( - , DU) пневматика по мощности
#define psrb2	 BUFFER[786]	//( - , DU) пневматика по программам
#define idpsrb2	 337	//( - , DU) пневматика по программам
#define psrb	 BUFFER[788]	//( - , DU) ???
#define idpsrb	 338	//( - , DU) ???
#define B1IC01UDU	 BUFFER[790]	//( - , MDuS) Координата штока ББ2 (дел.энк)
#define idB1IC01UDU	 339	//( - , MDuS) Координата штока ББ2 (дел.энк)
#define B1VC01RDU	 BUFFER[795]	//( - , DU) Координата ББ2, мм
#define idB1VC01RDU	 340	//( - , DU) Координата ББ2, мм
#define B1IS11LDU	 BUFFER[800]	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
#define idB1IS11LDU	 341	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
#define A2IC01UDU	 BUFFER[802]	//( - , MDuS) Координата штока РБ1 (дел.энк)
#define idA2IC01UDU	 342	//( - , MDuS) Координата штока РБ1 (дел.энк)
#define B2IC01UDU	 BUFFER[807]	//( - , MDuS) Координата штока РБ2 (дел.энк)
#define idB2IC01UDU	 343	//( - , MDuS) Координата штока РБ2 (дел.энк)
#define A3IC01UDU	 BUFFER[812]	//( - , MDuS) Координата штока ИС1 (дел.энк)
#define idA3IC01UDU	 344	//( - , MDuS) Координата штока ИС1 (дел.энк)
#define B3IC01UDU	 BUFFER[817]	//( - , MDuS) Координата штока ИС2 (дел.энк)
#define idB3IC01UDU	 345	//( - , MDuS) Координата штока ИС2 (дел.энк)
#define B3VC01RDU	 BUFFER[822]	//( - , DU) Координата ИС2, мм
#define idB3VC01RDU	 346	//( - , DU) Координата ИС2, мм
#define A8IC01UDU	 BUFFER[827]	//( - , MDuS) Координата ДС2 (дел.энк)
#define idA8IC01UDU	 347	//( - , MDuS) Координата ДС2 (дел.энк)
#define A8VC01RDU	 BUFFER[832]	//( - , DU) Координата ДС2, мм
#define idA8VC01RDU	 348	//( - , DU) Координата ДС2, мм
#define B8IC01UDU	 BUFFER[837]	//( - , MDuS) Координата АЗ2 (дел.энк)
#define idB8IC01UDU	 349	//( - , MDuS) Координата АЗ2 (дел.энк)
#define A1IC01UDU	 BUFFER[842]	//( - , MDuS) Координата штока ББ1 (дел.энк)
#define idA1IC01UDU	 350	//( - , MDuS) Координата штока ББ1 (дел.энк)
#define A1VC01RDU	 BUFFER[847]	//( - , DU) Координата ББ1, мм
#define idA1VC01RDU	 351	//( - , DU) Координата ББ1, мм
#define R0DE0FLDU	 BUFFER[852]	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
#define idR0DE0FLDU	 352	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
#define TTLDU	 BUFFER[855]	//( - , DU) ttl
#define idTTLDU	 353	//( - , DU) ttl
#define R0DEB3LDU	 BUFFER[858]	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
#define idR0DEB3LDU	 354	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
#define R0DEB2LDU	 BUFFER[860]	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
#define idR0DEB2LDU	 355	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
#define R0DEB1LDU	 BUFFER[862]	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
#define idR0DEB1LDU	 356	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
#define R0DEB4LDU	 BUFFER[864]	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
#define idR0DEB4LDU	 357	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
#define R0DE3DLDU	 BUFFER[866]	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
#define idR0DE3DLDU	 358	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
#define R0DE3CLDU	 BUFFER[868]	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
#define idR0DE3CLDU	 359	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
#define TestDiagnDU	 BUFFER[870]	//( - , DU) Неисправность от
#define idTestDiagnDU	 360	//( - , DU) Неисправность от
#define B3CV01RDU	 BUFFER[872]	//( - , DU) Измеренная скорость перемещения ИС2
#define idB3CV01RDU	 361	//( - , DU) Измеренная скорость перемещения ИС2
#define R0DE01LDU	 BUFFER[877]	//(vencf8l:01 - DiagnVDS, DiagnDU) диагностика модуля ДУ на 1 месте
#define idR0DE01LDU	 362	//(vencf8l:01 - DiagnVDS, DiagnDU) диагностика модуля ДУ на 1 месте
#define R0DE06LDU	 BUFFER[880]	//(vencf8l:01 - DiagnFDS, DiagnDU) диагностика модуля ДУ на 6 месте
#define idR0DE06LDU	 363	//(vencf8l:01 - DiagnFDS, DiagnDU) диагностика модуля ДУ на 6 месте
#define venc01	 BUFFER[883]	//(vencf8l:01 - venc01, - ) заначение реального энкодера ББ1
#define idvenc01	 364	//(vencf8l:01 - venc01, - ) заначение реального энкодера ББ1
#define venc02	 BUFFER[888]	//(vencf8l:01 - venc02, - ) заначение реального энкодера РБ1
#define idvenc02	 365	//(vencf8l:01 - venc02, - ) заначение реального энкодера РБ1
#define venc03	 BUFFER[893]	//(vencf8l:01 - venc03, - ) заначение реального энкодера Ис1
#define idvenc03	 366	//(vencf8l:01 - venc03, - ) заначение реального энкодера Ис1
#define venc04	 BUFFER[898]	//(vencf8l:01 - venc04, - ) заначение реального энкодера ДС1
#define idvenc04	 367	//(vencf8l:01 - venc04, - ) заначение реального энкодера ДС1
#define venc05	 BUFFER[903]	//(vencf8l:01 - venc05, - ) заначение реального энкодера ББ2
#define idvenc05	 368	//(vencf8l:01 - venc05, - ) заначение реального энкодера ББ2
#define venc06	 BUFFER[908]	//(vencf8l:01 - venc06, - ) заначение реального энкодера РБ2
#define idvenc06	 369	//(vencf8l:01 - venc06, - ) заначение реального энкодера РБ2
#define venc07	 BUFFER[913]	//(vencf8l:01 - venc07, - ) заначение реального энкодера ИС2
#define idvenc07	 370	//(vencf8l:01 - venc07, - ) заначение реального энкодера ИС2
#define venc08	 BUFFER[918]	//(vencf8l:01 - venc08, - ) заначение реального энкодера АЗ2
#define idvenc08	 371	//(vencf8l:01 - venc08, - ) заначение реального энкодера АЗ2
#define R0VN15RDU	 BUFFER[923]	//( - , DU) Период разгона РУ
#define idR0VN15RDU	 372	//( - , DU) Период разгона РУ
#define R8AD21LDU	 BUFFER[928]	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
#define idR8AD21LDU	 373	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
#define R8AD22LDU	 BUFFER[930]	//(vds32:02 - K15VDSR, - ) Сигнал синхронизации с импульсом
#define idR8AD22LDU	 374	//(vds32:02 - K15VDSR, - ) Сигнал синхронизации с импульсом
#define R0S01LDU	 BUFFER[932]	//( - , - ) Отключение сетевых передач ДУ
#define idR0S01LDU	 375	//( - , - ) Отключение сетевых передач ДУ
#define A6AB08LDU	 BUFFER[934]	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
#define idA6AB08LDU	 376	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
#define A6AB09LDU	 BUFFER[936]	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
#define idA6AB09LDU	 377	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
#define B6AB06LDU	 BUFFER[938]	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
#define idB6AB06LDU	 378	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
#define B6AB07LDU	 BUFFER[940]	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
#define idB6AB07LDU	 379	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
#define B6AB08LDU	 BUFFER[942]	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
#define idB6AB08LDU	 380	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
#define B6AB09LDU	 BUFFER[944]	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
#define idB6AB09LDU	 381	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
#define A6AB05LDU	 BUFFER[946]	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
#define idA6AB05LDU	 382	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
#define B8VS12LDU	 BUFFER[948]	//( - , DU) Движение АЗ2 в сторону ВУ
#define idB8VS12LDU	 383	//( - , DU) Движение АЗ2 в сторону ВУ
#define B8CV01RDU	 BUFFER[950]	//( - , DU) Измеренная скорость перемещения АЗ2
#define idB8CV01RDU	 384	//( - , DU) Измеренная скорость перемещения АЗ2
#define B8AB06LDU	 BUFFER[955]	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
#define idB8AB06LDU	 385	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
#define B8AB07LDU	 BUFFER[957]	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
#define idB8AB07LDU	 386	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
#define B8AB05LDU	 BUFFER[959]	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
#define idB8AB05LDU	 387	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
#define B8VS22LDU	 BUFFER[961]	//( - , DU) Движение АЗ2 в сторону НУ
#define idB8VS22LDU	 388	//( - , DU) Движение АЗ2 в сторону НУ
#define B8AZ03LDU	 BUFFER[963]	//( - , DU) Несанкционированное перемещение АЗ2
#define idB8AZ03LDU	 389	//( - , DU) Несанкционированное перемещение АЗ2
#define R0MD11LP1	 BUFFER[965]	//( - , DU) Кнопка ПУСК
#define idR0MD11LP1	 390	//( - , DU) Кнопка ПУСК
#define B8AD10LDU	 BUFFER[967]	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
#define idB8AD10LDU	 391	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
#define B8AD20LDU	 BUFFER[969]	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
#define idB8AD20LDU	 392	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
#define B8IS11LDU	 BUFFER[971]	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
#define idB8IS11LDU	 393	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
#define B8AB01LDU	 BUFFER[973]	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
#define idB8AB01LDU	 394	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
#define B8AB04LDU	 BUFFER[975]	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
#define idB8AB04LDU	 395	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
#define B8AB08LDU	 BUFFER[977]	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
#define idB8AB08LDU	 396	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
#define B8AB09LDU	 BUFFER[979]	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
#define idB8AB09LDU	 397	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
#define B8AB10LDU	 BUFFER[981]	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
#define idB8AB10LDU	 398	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
#define A5AB02LDU	 BUFFER[983]	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
#define idA5AB02LDU	 399	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
#define B5AZ03LDU	 BUFFER[985]	//( - , DU) Несанкционированное перемещение НЛ2
#define idB5AZ03LDU	 400	//( - , DU) Несанкционированное перемещение НЛ2
#define B5AB01LDU	 BUFFER[987]	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
#define idB5AB01LDU	 401	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
#define B5AB02LDU	 BUFFER[989]	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
#define idB5AB02LDU	 402	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
#define A4IS21LDU	 BUFFER[991]	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
#define idA4IS21LDU	 403	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
#define B4IS21LDU	 BUFFER[993]	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
#define idB4IS21LDU	 404	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
#define B4AD10LDU	 BUFFER[995]	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
#define idB4AD10LDU	 405	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
#define A4AD10LDU	 BUFFER[997]	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
#define idA4AD10LDU	 406	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
#define A4AZ03LDU	 BUFFER[999]	//( - , DU) Несанкционированное перемещение НИ1
#define idA4AZ03LDU	 407	//( - , DU) Несанкционированное перемещение НИ1
#define A4AB01LDU	 BUFFER[1001]	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
#define idA4AB01LDU	 408	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
#define A4AB02LDU	 BUFFER[1003]	//( - , DU) Блокировка движения НИ1 - Нет перемещения
#define idA4AB02LDU	 409	//( - , DU) Блокировка движения НИ1 - Нет перемещения
#define B4AZ03LDU	 BUFFER[1005]	//( - , DU) Несанкционированное перемещение НИ2
#define idB4AZ03LDU	 410	//( - , DU) Несанкционированное перемещение НИ2
#define B4AB01LDU	 BUFFER[1007]	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
#define idB4AB01LDU	 411	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
#define B4AB02LDU	 BUFFER[1009]	//( - , DU) Блокировка движения НИ2 - Нет перемещения
#define idB4AB02LDU	 412	//( - , DU) Блокировка движения НИ2 - Нет перемещения
#define A5AB04LDU	 BUFFER[1011]	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
#define idA5AB04LDU	 413	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
#define B5AB04LDU	 BUFFER[1013]	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
#define idB5AB04LDU	 414	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
#define A1IS12LDU	 BUFFER[1015]	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
#define idA1IS12LDU	 415	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
#define A2IS12LDU	 BUFFER[1017]	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
#define idA2IS12LDU	 416	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
#define B1IS12LDU	 BUFFER[1019]	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
#define idB1IS12LDU	 417	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
#define B2IS12LDU	 BUFFER[1021]	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
#define idB2IS12LDU	 418	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
#define R4IS11LDU	 BUFFER[1023]	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
#define idR4IS11LDU	 419	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
#define A6AB06LDU	 BUFFER[1025]	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
#define idA6AB06LDU	 420	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
#define A6AB07LDU	 BUFFER[1027]	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
#define idA6AB07LDU	 421	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
#define A8AB14LDU	 BUFFER[1029]	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
#define idA8AB14LDU	 422	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
#define A8AB02LDU	 BUFFER[1031]	//( - , DU) Блокировка движения ДС2- АНИ не установлен
#define idA8AB02LDU	 423	//( - , DU) Блокировка движения ДС2- АНИ не установлен
#define A8AB01LDU	 BUFFER[1033]	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
#define idA8AB01LDU	 424	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
#define A2VS11LDU	 BUFFER[1035]	//( - , DU) Движение РБ1 в сторону ВУ
#define idA2VS11LDU	 425	//( - , DU) Движение РБ1 в сторону ВУ
#define A2CV01RDU	 BUFFER[1037]	//( - , DU) Измеренная скорость перемещения РБ1
#define idA2CV01RDU	 426	//( - , DU) Измеренная скорость перемещения РБ1
#define A2AB04LDU	 BUFFER[1042]	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
#define idA2AB04LDU	 427	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
#define A2AB02LDU	 BUFFER[1044]	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
#define idA2AB02LDU	 428	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
#define A2AB01LDU	 BUFFER[1046]	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
#define idA2AB01LDU	 429	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
#define A2VS21LDU	 BUFFER[1048]	//( - , DU) Движение РБ1 в сторону НУ
#define idA2VS21LDU	 430	//( - , DU) Движение РБ1 в сторону НУ
#define A2AZ03LDU	 BUFFER[1050]	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
#define idA2AZ03LDU	 431	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
#define A2AD11LDU	 BUFFER[1052]	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	 432	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
#define A2AD21LDU	 BUFFER[1054]	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	 433	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
#define A2AD02LDU	 BUFFER[1056]	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
#define idA2AD02LDU	 434	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
#define A2AD03LDU	 BUFFER[1058]	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
#define idA2AD03LDU	 435	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
#define A2AD04LDU	 BUFFER[1060]	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
#define idA2AD04LDU	 436	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
#define A2AD05LDU	 BUFFER[1062]	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
#define idA2AD05LDU	 437	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
#define A2AB07LDU	 BUFFER[1064]	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
#define idA2AB07LDU	 438	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
#define A2AB08LDU	 BUFFER[1066]	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
#define idA2AB08LDU	 439	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
#define A2AB05LDU	 BUFFER[1068]	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
#define idA2AB05LDU	 440	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
#define A2AB06LDU	 BUFFER[1070]	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
#define idA2AB06LDU	 441	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
#define A2AB09LDU	 BUFFER[1072]	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
#define idA2AB09LDU	 442	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
#define A2AB10LDU	 BUFFER[1074]	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
#define idA2AB10LDU	 443	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
#define A2AB11LDU	 BUFFER[1076]	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
#define idA2AB11LDU	 444	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
#define B8AB11LDU	 BUFFER[1078]	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
#define idB8AB11LDU	 445	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
#define B8AB12LDU	 BUFFER[1080]	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
#define idB8AB12LDU	 446	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
#define B8AB13LDU	 BUFFER[1082]	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
#define idB8AB13LDU	 447	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
#define B8AB14LDU	 BUFFER[1084]	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
#define idB8AB14LDU	 448	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
#define B8AB02LDU	 BUFFER[1086]	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
#define idB8AB02LDU	 449	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
#define A8VS12LDU	 BUFFER[1088]	//( - , DU) Движение ДС2 в сторону ВУ
#define idA8VS12LDU	 450	//( - , DU) Движение ДС2 в сторону ВУ
#define A8CV01RDU	 BUFFER[1090]	//( - , DU) Измеренная скорость перемещения ДС2
#define idA8CV01RDU	 451	//( - , DU) Измеренная скорость перемещения ДС2
#define A8AB06LDU	 BUFFER[1095]	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
#define idA8AB06LDU	 452	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
#define A8AB07LDU	 BUFFER[1097]	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
#define idA8AB07LDU	 453	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
#define A8AB05LDU	 BUFFER[1099]	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
#define idA8AB05LDU	 454	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
#define A8VS22LDU	 BUFFER[1101]	//( - , DU) Движение ДС2 в сторону НУ
#define idA8VS22LDU	 455	//( - , DU) Движение ДС2 в сторону НУ
#define A8AZ03LDU	 BUFFER[1103]	//( - , DU) Несанкционированное перемещение ДС2
#define idA8AZ03LDU	 456	//( - , DU) Несанкционированное перемещение ДС2
#define A8AD10LDU	 BUFFER[1105]	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
#define idA8AD10LDU	 457	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
#define A8AD20LDU	 BUFFER[1107]	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
#define idA8AD20LDU	 458	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
#define B8IS22LDU	 BUFFER[1109]	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
#define idB8IS22LDU	 459	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
#define A8IS12LDU	 BUFFER[1111]	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
#define idA8IS12LDU	 460	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
#define A8AB04LDU	 BUFFER[1113]	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
#define idA8AB04LDU	 461	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
#define A8IS22LDU	 BUFFER[1115]	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
#define idA8IS22LDU	 462	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
#define A8AB08LDU	 BUFFER[1117]	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define idA8AB08LDU	 463	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define A8AB09LDU	 BUFFER[1119]	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
#define idA8AB09LDU	 464	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
#define A8AB10LDU	 BUFFER[1121]	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
#define idA8AB10LDU	 465	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
#define A8AB11LDU	 BUFFER[1123]	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
#define idA8AB11LDU	 466	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
#define A8AB12LDU	 BUFFER[1125]	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
#define idA8AB12LDU	 467	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
#define A8AB13LDU	 BUFFER[1127]	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
#define idA8AB13LDU	 468	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
#define A6VS22LDU	 BUFFER[1129]	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
#define idA6VS22LDU	 469	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
#define A6VS12LDU	 BUFFER[1131]	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
#define idA6VS12LDU	 470	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
#define B6VS22LDU	 BUFFER[1133]	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
#define idB6VS22LDU	 471	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
#define B6VS12LDU	 BUFFER[1135]	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
#define idB6VS12LDU	 472	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
#define A6AD10LDU	 BUFFER[1137]	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
#define idA6AD10LDU	 473	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
#define A6AD20LDU	 BUFFER[1139]	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
#define idA6AD20LDU	 474	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
#define B6AD10LDU	 BUFFER[1141]	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
#define idB6AD10LDU	 475	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
#define B6AD20LDU	 BUFFER[1143]	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
#define idB6AD20LDU	 476	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
#define A6AZ03LDU	 BUFFER[1145]	//( - , DU) Несанкционированное перемещение БЗ1
#define idA6AZ03LDU	 477	//( - , DU) Несанкционированное перемещение БЗ1
#define A6AB01LDU	 BUFFER[1147]	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
#define idA6AB01LDU	 478	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
#define A6AB02LDU	 BUFFER[1149]	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
#define idA6AB02LDU	 479	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
#define B6AZ03LDU	 BUFFER[1151]	//( - , DU) Несанкционированное перемещение БЗ2
#define idB6AZ03LDU	 480	//( - , DU) Несанкционированное перемещение БЗ2
#define B6AB01LDU	 BUFFER[1153]	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
#define idB6AB01LDU	 481	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
#define B6AB02LDU	 BUFFER[1155]	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
#define idB6AB02LDU	 482	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
#define A6AB04LDU	 BUFFER[1157]	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
#define idA6AB04LDU	 483	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
#define B6AB04LDU	 BUFFER[1159]	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
#define idB6AB04LDU	 484	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
#define R4AB01LDU	 BUFFER[1161]	//( - , DU) Блокировка движения тележки - АНИ не установлен
#define idR4AB01LDU	 485	//( - , DU) Блокировка движения тележки - АНИ не установлен
#define R8IS11LDU	 BUFFER[1163]	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
#define idR8IS11LDU	 486	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
#define R6IS21LDU	 BUFFER[1165]	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
#define idR6IS21LDU	 487	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
#define A0VN71LZ2	 BUFFER[1167]	//( - , MDuBz2) АЗ по АС мощности для АЗ1
#define idA0VN71LZ2	 488	//( - , MDuBz2) АЗ по АС мощности для АЗ1
#define A0VN71LZ1	 BUFFER[1169]	//( - , MDuBz1) АЗ по АС мощности для АЗ1
#define idA0VN71LZ1	 489	//( - , MDuBz1) АЗ по АС мощности для АЗ1
#define R0NE01LDU	 BUFFER[1171]	//( - , DU) Потеря связи с БАЗ1
#define idR0NE01LDU	 490	//( - , DU) Потеря связи с БАЗ1
#define R0NE02LDU	 BUFFER[1173]	//( - , DU) Потеря связи с БАЗ2
#define idR0NE02LDU	 491	//( - , DU) Потеря связи с БАЗ2
#define R0MW15IP1	 BUFFER[1175]	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
#define idR0MW15IP1	 492	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
#define R0MW14IP1	 BUFFER[1178]	//( - , DU) Переключатель ПРОГРАММЫ
#define idR0MW14IP1	 493	//( - , DU) Переключатель ПРОГРАММЫ
#define R0MW12IP1	 BUFFER[1181]	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
#define idR0MW12IP1	 494	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
#define R0MW13IP1	 BUFFER[1184]	//( - , DU) Переключатель ВЫБОР ЗОН
#define idR0MW13IP1	 495	//( - , DU) Переключатель ВЫБОР ЗОН
#define R0MW16IP1	 BUFFER[1187]	//( - , DU) Переключатель ВИД ПРОВЕРКИ
#define idR0MW16IP1	 496	//( - , DU) Переключатель ВИД ПРОВЕРКИ
#define R0MW11IP1	 BUFFER[1190]	//( - , DU) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	 497	//( - , DU) Переключатель ВЫСТРЕЛ
#define R0MW11IP2	 BUFFER[1193]	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
#define idR0MW11IP2	 498	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
#define R0MW13LP2	 BUFFER[1196]	//( - , DU) Переключатель СЕТЬ
#define idR0MW13LP2	 499	//( - , DU) Переключатель СЕТЬ
#define R0MD32LP1	 BUFFER[1198]	//( - , DU) Кнопка СПУСК
#define idR0MD32LP1	 500	//( - , DU) Кнопка СПУСК
#define R0MD31LP1	 BUFFER[1200]	//( - , DU) Кнопка СТОП
#define idR0MD31LP1	 501	//( - , DU) Кнопка СТОП
#define A1IS21LDU	 BUFFER[1202]	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
#define idA1IS21LDU	 502	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
#define A2IS21LDU	 BUFFER[1204]	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
#define idA2IS21LDU	 503	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
#define A3IS21LDU	 BUFFER[1206]	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
#define idA3IS21LDU	 504	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
#define B1IS21LDU	 BUFFER[1208]	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
#define idB1IS21LDU	 505	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
#define B2IS21LDU	 BUFFER[1210]	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
#define idB2IS21LDU	 506	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
#define B3IS21LDU	 BUFFER[1212]	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
#define idB3IS21LDU	 507	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
#define R0ES01LDU	 BUFFER[1214]	//( - , DU) ОРР не в исходном состоянии
#define idR0ES01LDU	 508	//( - , DU) ОРР не в исходном состоянии
#define R4MD11LP2	 BUFFER[1216]	//( - , DU) Кнопка ВПЕРЁД  (тележки)
#define idR4MD11LP2	 509	//( - , DU) Кнопка ВПЕРЁД  (тележки)
#define R4MD31LP2	 BUFFER[1218]	//( - , DU) Кнопка СТОП  (тележки)
#define idR4MD31LP2	 510	//( - , DU) Кнопка СТОП  (тележки)
#define R4MD21LP2	 BUFFER[1220]	//( - , DU) Кнопка НАЗАД  (тележки)
#define idR4MD21LP2	 511	//( - , DU) Кнопка НАЗАД  (тележки)
#define A6IS11LDU	 BUFFER[1222]	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
#define idA6IS11LDU	 512	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
#define A6IS21LDU	 BUFFER[1224]	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
#define idA6IS21LDU	 513	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
#define B6IS11LDU	 BUFFER[1226]	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
#define idB6IS11LDU	 514	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
#define B6IS21LDU	 BUFFER[1228]	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
#define idB6IS21LDU	 515	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
#define R4AB13LDU	 BUFFER[1230]	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
#define idR4AB13LDU	 516	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
#define R4AB14LDU	 BUFFER[1232]	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
#define idR4AB14LDU	 517	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
#define R4AB15LDU	 BUFFER[1234]	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
#define idR4AB15LDU	 518	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
#define R5IS11LDU	 BUFFER[1236]	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	 519	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
#define R4AB16LDU	 BUFFER[1238]	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
#define idR4AB16LDU	 520	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
#define R4AB17LDU	 BUFFER[1240]	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define idR4AB17LDU	 521	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define R4AB18LDU	 BUFFER[1242]	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define idR4AB18LDU	 522	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define R4AD10LDU	 BUFFER[1244]	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
#define idR4AD10LDU	 523	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
#define R4AD20LDU	 BUFFER[1246]	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
#define idR4AD20LDU	 524	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
#define A5VS22LDU	 BUFFER[1248]	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
#define idA5VS22LDU	 525	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
#define A5VS12LDU	 BUFFER[1250]	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
#define idA5VS12LDU	 526	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
#define B5VS22LDU	 BUFFER[1252]	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
#define idB5VS22LDU	 527	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
#define B5VS12LDU	 BUFFER[1254]	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
#define idB5VS12LDU	 528	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
#define B5AD10LDU	 BUFFER[1256]	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
#define idB5AD10LDU	 529	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
#define B5AD20LDU	 BUFFER[1258]	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
#define idB5AD20LDU	 530	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
#define A5AD10LDU	 BUFFER[1260]	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
#define idA5AD10LDU	 531	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
#define A5AD20LDU	 BUFFER[1262]	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
#define idA5AD20LDU	 532	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
#define A5IS11LDU	 BUFFER[1264]	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
#define idA5IS11LDU	 533	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
#define A5IS21LDU	 BUFFER[1266]	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
#define idA5IS21LDU	 534	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
#define B5IS11LDU	 BUFFER[1268]	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
#define idB5IS11LDU	 535	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
#define B5IS21LDU	 BUFFER[1270]	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
#define idB5IS21LDU	 536	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
#define A5AZ03LDU	 BUFFER[1272]	//( - , DU) Несанкционированное перемещение НЛ1
#define idA5AZ03LDU	 537	//( - , DU) Несанкционированное перемещение НЛ1
#define A5AB01LDU	 BUFFER[1274]	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
#define idA5AB01LDU	 538	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
#define R4AB02LDU	 BUFFER[1276]	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
#define idR4AB02LDU	 539	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
#define R0NE08LDU	 BUFFER[1278]	//( - , DU) Потеря связи с ОПУ
#define idR0NE08LDU	 540	//( - , DU) Потеря связи с ОПУ
#define R4IS21LDU	 BUFFER[1280]	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
#define idR4IS21LDU	 541	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
#define R4IS22LDU	 BUFFER[1282]	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
#define idR4IS22LDU	 542	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
#define R4IS12LDU	 BUFFER[1284]	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
#define idR4IS12LDU	 543	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
#define R4VS22LDU	 BUFFER[1286]	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
#define idR4VS22LDU	 544	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
#define R4VS12LDU	 BUFFER[1288]	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
#define idR4VS12LDU	 545	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
#define R4AZ03LDU	 BUFFER[1290]	//( - , DU) Несанкционированное перемещение тележки
#define idR4AZ03LDU	 546	//( - , DU) Несанкционированное перемещение тележки
#define R4AB03LDU	 BUFFER[1292]	//( - , DU) Блокировка движения тележки - Самоход любого механизма
#define idR4AB03LDU	 547	//( - , DU) Блокировка движения тележки - Самоход любого механизма
#define R1IS21LDU	 BUFFER[1294]	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
#define idR1IS21LDU	 548	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
#define R2IS21LDU	 BUFFER[1296]	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
#define idR2IS21LDU	 549	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
#define R4AB04LDU	 BUFFER[1298]	//( - , DU) Блокировка движения тележки - Превышение времени движения
#define idR4AB04LDU	 550	//( - , DU) Блокировка движения тележки - Превышение времени движения
#define R4AB05LDU	 BUFFER[1300]	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
#define idR4AB05LDU	 551	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
#define R4AB06LDU	 BUFFER[1302]	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
#define idR4AB06LDU	 552	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
#define R4AB07LDU	 BUFFER[1304]	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
#define idR4AB07LDU	 553	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
#define R4AB08LDU	 BUFFER[1306]	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define idR4AB08LDU	 554	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define R4AB09LDU	 BUFFER[1308]	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
#define idR4AB09LDU	 555	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
#define B0VN71LZ1	 BUFFER[1310]	//( - , MDuBz1) АЗ по АС мощности для АЗ2
#define idB0VN71LZ1	 556	//( - , MDuBz1) АЗ по АС мощности для АЗ2
#define B0VN71LZ2	 BUFFER[1312]	//( - , MDuBz2) АЗ по АС мощности для АЗ2
#define idB0VN71LZ2	 557	//( - , MDuBz2) АЗ по АС мощности для АЗ2
#define R4AB10LDU	 BUFFER[1314]	//( - , DU) Блокировка тележки - не открыта биологическая защита
#define idR4AB10LDU	 558	//( - , DU) Блокировка тележки - не открыта биологическая защита
#define R4AB11LDU	 BUFFER[1316]	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
#define idR4AB11LDU	 559	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
#define R4AB12LDU	 BUFFER[1318]	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
#define idR4AB12LDU	 560	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
#define A4IS11LDU	 BUFFER[1320]	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
#define idA4IS11LDU	 561	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
#define B4IS11LDU	 BUFFER[1322]	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
#define idB4IS11LDU	 562	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
#define A3CV02RDU	 BUFFER[1324]	//( - , DU) Заданная скорость перемещения ИС1
#define idA3CV02RDU	 563	//( - , DU) Заданная скорость перемещения ИС1
#define A3AB07LDU	 BUFFER[1329]	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
#define idA3AB07LDU	 564	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
#define A3AB08LDU	 BUFFER[1331]	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
#define idA3AB08LDU	 565	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
#define A3AB05LDU	 BUFFER[1333]	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
#define idA3AB05LDU	 566	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
#define A3AB06LDU	 BUFFER[1335]	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
#define idA3AB06LDU	 567	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
#define A3AB09LDU	 BUFFER[1337]	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
#define idA3AB09LDU	 568	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
#define A3AB10LDU	 BUFFER[1339]	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
#define idA3AB10LDU	 569	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
#define A3AB11LDU	 BUFFER[1341]	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
#define idA3AB11LDU	 570	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
#define A3AB12LDU	 BUFFER[1343]	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA3AB12LDU	 571	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A3AB14LDU	 BUFFER[1345]	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
#define idA3AB14LDU	 572	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
#define A3AB16LDU	 BUFFER[1347]	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
#define idA3AB16LDU	 573	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
#define A3AB17LDU	 BUFFER[1349]	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
#define idA3AB17LDU	 574	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
#define A3AB18LDU	 BUFFER[1351]	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
#define idA3AB18LDU	 575	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
#define A3AB20LDU	 BUFFER[1353]	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
#define idA3AB20LDU	 576	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
#define B3VS12LDU	 BUFFER[1355]	//( - , DU) Движение ИС2 в сторону ВУ
#define idB3VS12LDU	 577	//( - , DU) Движение ИС2 в сторону ВУ
#define B3AB04LDU	 BUFFER[1357]	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
#define idB3AB04LDU	 578	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
#define B3AB02LDU	 BUFFER[1359]	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
#define idB3AB02LDU	 579	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
#define B3AB01LDU	 BUFFER[1361]	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
#define idB3AB01LDU	 580	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
#define B3VS22LDU	 BUFFER[1363]	//( - , DU) Движение ИС2 в сторону НУ
#define idB3VS22LDU	 581	//( - , DU) Движение ИС2 в сторону НУ
#define B3AZ03LDU	 BUFFER[1365]	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
#define idB3AZ03LDU	 582	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
#define B3AD11LDU	 BUFFER[1367]	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	 583	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
#define B3AD21LDU	 BUFFER[1369]	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	 584	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
#define B3AD02LDU	 BUFFER[1371]	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
#define idB3AD02LDU	 585	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
#define B1AB06LDU	 BUFFER[1373]	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
#define idB1AB06LDU	 586	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
#define B1AB09LDU	 BUFFER[1375]	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
#define idB1AB09LDU	 587	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
#define B1AB10LDU	 BUFFER[1377]	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
#define idB1AB10LDU	 588	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
#define B1AB11LDU	 BUFFER[1379]	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
#define idB1AB11LDU	 589	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
#define B1AB12LDU	 BUFFER[1381]	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idB1AB12LDU	 590	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define B1AB13LDU	 BUFFER[1383]	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
#define idB1AB13LDU	 591	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
#define B1AB14LDU	 BUFFER[1385]	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
#define idB1AB14LDU	 592	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
#define B1AB16LDU	 BUFFER[1387]	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
#define idB1AB16LDU	 593	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
#define B1AB17LDU	 BUFFER[1389]	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
#define idB1AB17LDU	 594	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
#define B1AB18LDU	 BUFFER[1391]	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
#define idB1AB18LDU	 595	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
#define A3VS12LDU	 BUFFER[1393]	//( - , DU) Движение ИС1 в сторону ВУ
#define idA3VS12LDU	 596	//( - , DU) Движение ИС1 в сторону ВУ
#define A3CV01RDU	 BUFFER[1395]	//( - , DU) Измеренная скорость перемещения ИС1
#define idA3CV01RDU	 597	//( - , DU) Измеренная скорость перемещения ИС1
#define A3AB04LDU	 BUFFER[1400]	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
#define idA3AB04LDU	 598	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
#define A3AB02LDU	 BUFFER[1402]	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
#define idA3AB02LDU	 599	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
#define A3AB01LDU	 BUFFER[1404]	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
#define idA3AB01LDU	 600	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
#define A3VS22LDU	 BUFFER[1406]	//( - , DU) Движение ИС1 в сторону НУ
#define idA3VS22LDU	 601	//( - , DU) Движение ИС1 в сторону НУ
#define A3AZ03LDU	 BUFFER[1408]	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
#define idA3AZ03LDU	 602	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
#define A3AD11LDU	 BUFFER[1410]	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	 603	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
#define A3AD21LDU	 BUFFER[1412]	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	 604	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
#define A3AD02LDU	 BUFFER[1414]	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
#define idA3AD02LDU	 605	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
#define A3AD03LDU	 BUFFER[1416]	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
#define idA3AD03LDU	 606	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
#define A3AD04LDU	 BUFFER[1418]	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
#define idA3AD04LDU	 607	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
#define A3AD05LDU	 BUFFER[1420]	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
#define idA3AD05LDU	 608	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
#define A3AD01LDU	 BUFFER[1422]	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
#define idA3AD01LDU	 609	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
#define A2AD32LDU	 BUFFER[1424]	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
#define idA2AD32LDU	 610	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
#define B2AD32LDU	 BUFFER[1426]	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
#define idB2AD32LDU	 611	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
#define A1AD32LDU	 BUFFER[1428]	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
#define idA1AD32LDU	 612	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
#define B1AD32LDU	 BUFFER[1430]	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
#define idB1AD32LDU	 613	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
#define R0MD11LP2	 BUFFER[1432]	//( - , DU) Кнопка Пуск проверки схем сброса
#define idR0MD11LP2	 614	//( - , DU) Кнопка Пуск проверки схем сброса
#define R0VX01LDU	 BUFFER[1434]	//( - , DU) ДО ИМПУЛЬСА
#define idR0VX01LDU	 615	//( - , DU) ДО ИМПУЛЬСА
#define R0VL01IDU	 BUFFER[1436]	//( - , DU) До импульса минут
#define idR0VL01IDU	 616	//( - , DU) До импульса минут
#define R0VL11IDU	 BUFFER[1439]	//( - , DU) До импульса секунд
#define idR0VL11IDU	 617	//( - , DU) До импульса секунд
#define R0VL06RDU	 BUFFER[1442]	//( - , DU) Индикация (Время задержки от ВУ РБ)
#define idR0VL06RDU	 618	//( - , DU) Индикация (Время задержки от ВУ РБ)
#define B3AD33LDU	 BUFFER[1447]	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define idB3AD33LDU	 619	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define R0VL02RDU	 BUFFER[1449]	//( - , DU) Индикация (Время задержки ИНИ)
#define idR0VL02RDU	 620	//( - , DU) Индикация (Время задержки ИНИ)
#define R0VL04RDU	 BUFFER[1454]	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
#define idR0VL04RDU	 621	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
#define R0AB04LDU	 BUFFER[1459]	//( - , DU) Нарушение времени срабатывания верхней АС II УР
#define idR0AB04LDU	 622	//( - , DU) Нарушение времени срабатывания верхней АС II УР
#define R0AB06LDU	 BUFFER[1461]	//( - , DU) Нарушение времени задержки от ВУ РБ
#define idR0AB06LDU	 623	//( - , DU) Нарушение времени задержки от ВУ РБ
#define R0AB02LDU	 BUFFER[1463]	//( - , DU) Нарушение времени задержки ИНИ
#define idR0AB02LDU	 624	//( - , DU) Нарушение времени задержки ИНИ
#define R0VL03RDU	 BUFFER[1465]	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define idR0VL03RDU	 625	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define R0VL05RDU	 BUFFER[1470]	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
#define idR0VL05RDU	 626	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
#define R0VL21IDU	 BUFFER[1475]	//( - , DU) Декатрон
#define idR0VL21IDU	 627	//( - , DU) Декатрон
#define R0VX03LDU	 BUFFER[1478]	//( - , DU) Готовность 2 мин
#define idR0VX03LDU	 628	//( - , DU) Готовность 2 мин
#define R0VS21IDU	 BUFFER[1480]	//( - , DU) Индикация ВИД ПРОВЕРКИ
#define idR0VS21IDU	 629	//( - , DU) Индикация ВИД ПРОВЕРКИ
#define A1VS01IDU	 BUFFER[1483]	//( - , DU) Готовность к управлению ББ1
#define idA1VS01IDU	 630	//( - , DU) Готовность к управлению ББ1
#define B1VS01IDU	 BUFFER[1486]	//( - , DU) Готовность к управлению ББ2
#define idB1VS01IDU	 631	//( - , DU) Готовность к управлению ББ2
#define A3VS01IDU	 BUFFER[1489]	//( - , DU) Готовность к управлению ИС1
#define idA3VS01IDU	 632	//( - , DU) Готовность к управлению ИС1
#define B3AD03LDU	 BUFFER[1492]	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
#define idB3AD03LDU	 633	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
#define B3AD04LDU	 BUFFER[1494]	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
#define idB3AD04LDU	 634	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
#define B3AD05LDU	 BUFFER[1496]	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
#define idB3AD05LDU	 635	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
#define B3AD01LDU	 BUFFER[1498]	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
#define idB3AD01LDU	 636	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
#define B3CV02RDU	 BUFFER[1500]	//( - , DU) Заданная скорость перемещения ИС2
#define idB3CV02RDU	 637	//( - , DU) Заданная скорость перемещения ИС2
#define B3AB07LDU	 BUFFER[1505]	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
#define idB3AB07LDU	 638	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
#define B3AB08LDU	 BUFFER[1507]	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
#define idB3AB08LDU	 639	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
#define B3AB05LDU	 BUFFER[1509]	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
#define idB3AB05LDU	 640	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
#define B3AB06LDU	 BUFFER[1511]	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
#define idB3AB06LDU	 641	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
#define B3AB09LDU	 BUFFER[1513]	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
#define idB3AB09LDU	 642	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
#define B3AB10LDU	 BUFFER[1515]	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
#define idB3AB10LDU	 643	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
#define B3AB11LDU	 BUFFER[1517]	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
#define idB3AB11LDU	 644	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
#define B3AB12LDU	 BUFFER[1519]	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define idB3AB12LDU	 645	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define B3AB14LDU	 BUFFER[1521]	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
#define idB3AB14LDU	 646	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
#define B3AB16LDU	 BUFFER[1523]	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
#define idB3AB16LDU	 647	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
#define B3AB17LDU	 BUFFER[1525]	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
#define idB3AB17LDU	 648	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
#define B3AB18LDU	 BUFFER[1527]	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
#define idB3AB18LDU	 649	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
#define B3AB20LDU	 BUFFER[1529]	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
#define idB3AB20LDU	 650	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
#define C1MD31LP1	 BUFFER[1531]	//( - , DU) Кнопка СБРОС ББ
#define idC1MD31LP1	 651	//( - , DU) Кнопка СБРОС ББ
#define C1MD31LP2	 BUFFER[1533]	//( - , DU) Кнопка СБРОС ББ
#define idC1MD31LP2	 652	//( - , DU) Кнопка СБРОС ББ
#define A2AD31LDU	 BUFFER[1535]	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
#define idA2AD31LDU	 653	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
#define B2AD31LDU	 BUFFER[1537]	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
#define idB2AD31LDU	 654	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
#define A1AD31LDU	 BUFFER[1539]	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
#define idA1AD31LDU	 655	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
#define B1AD31LDU	 BUFFER[1541]	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
#define idB1AD31LDU	 656	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
#define B2AB09LDU	 BUFFER[1543]	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
#define idB2AB09LDU	 657	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
#define B2AB10LDU	 BUFFER[1545]	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
#define idB2AB10LDU	 658	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
#define B2AB11LDU	 BUFFER[1547]	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
#define idB2AB11LDU	 659	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
#define B2AB12LDU	 BUFFER[1549]	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define idB2AB12LDU	 660	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define B2AB13LDU	 BUFFER[1551]	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
#define idB2AB13LDU	 661	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
#define B2AB14LDU	 BUFFER[1553]	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
#define idB2AB14LDU	 662	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
#define B2AB16LDU	 BUFFER[1555]	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
#define idB2AB16LDU	 663	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
#define B2AB17LDU	 BUFFER[1557]	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
#define idB2AB17LDU	 664	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
#define R1AZ03LDU	 BUFFER[1559]	//( - , DU) Несанкционированное перемещение МДЗ1
#define idR1AZ03LDU	 665	//( - , DU) Несанкционированное перемещение МДЗ1
#define R1AB01LDU	 BUFFER[1561]	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
#define idR1AB01LDU	 666	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
#define R1AB02LDU	 BUFFER[1563]	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
#define idR1AB02LDU	 667	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
#define R2AZ03LDU	 BUFFER[1565]	//( - , DU) Несанкционированное перемещение МДЗ2
#define idR2AZ03LDU	 668	//( - , DU) Несанкционированное перемещение МДЗ2
#define R2AB01LDU	 BUFFER[1567]	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
#define idR2AB01LDU	 669	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
#define R2AB02LDU	 BUFFER[1569]	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
#define idR2AB02LDU	 670	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
#define R1AB04LDU	 BUFFER[1571]	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
#define idR1AB04LDU	 671	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
#define R2AB04LDU	 BUFFER[1573]	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
#define idR2AB04LDU	 672	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
#define R1AD10LDU	 BUFFER[1575]	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
#define idR1AD10LDU	 673	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
#define R1AD20LDU	 BUFFER[1577]	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
#define idR1AD20LDU	 674	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
#define R1IS11LDU	 BUFFER[1579]	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
#define idR1IS11LDU	 675	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
#define R1VS22LDU	 BUFFER[1581]	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	 676	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
#define R2VS22LDU	 BUFFER[1583]	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	 677	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
#define R2VS12LDU	 BUFFER[1585]	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	 678	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
#define R1VS12LDU	 BUFFER[1587]	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	 679	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
#define A2AB12LDU	 BUFFER[1589]	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA2AB12LDU	 680	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A2AB13LDU	 BUFFER[1591]	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
#define idA2AB13LDU	 681	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
#define A2AB14LDU	 BUFFER[1593]	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
#define idA2AB14LDU	 682	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
#define A2AB16LDU	 BUFFER[1595]	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
#define idA2AB16LDU	 683	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
#define A2AB17LDU	 BUFFER[1597]	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
#define idA2AB17LDU	 684	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
#define A2AD01LDU	 BUFFER[1599]	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
#define idA2AD01LDU	 685	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
#define A2CV02RDU	 BUFFER[1601]	//( - , DU) Заданная скорость перемещения РБ1
#define idA2CV02RDU	 686	//( - , DU) Заданная скорость перемещения РБ1
#define B2CV01RDU	 BUFFER[1606]	//( - , DU) Измеренная скорость перемещения РБ2
#define idB2CV01RDU	 687	//( - , DU) Измеренная скорость перемещения РБ2
#define B2AB04LDU	 BUFFER[1611]	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
#define idB2AB04LDU	 688	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
#define B2AB02LDU	 BUFFER[1613]	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
#define idB2AB02LDU	 689	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
#define B2AB01LDU	 BUFFER[1615]	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
#define idB2AB01LDU	 690	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
#define B2AZ03LDU	 BUFFER[1617]	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
#define idB2AZ03LDU	 691	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
#define B2AD11LDU	 BUFFER[1619]	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	 692	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
#define B2AD21LDU	 BUFFER[1621]	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	 693	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
#define B2AD02LDU	 BUFFER[1623]	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
#define idB2AD02LDU	 694	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
#define B2AD03LDU	 BUFFER[1625]	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
#define idB2AD03LDU	 695	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
#define B2AD04LDU	 BUFFER[1627]	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
#define idB2AD04LDU	 696	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
#define B2AD05LDU	 BUFFER[1629]	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
#define idB2AD05LDU	 697	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
#define B2AD01LDU	 BUFFER[1631]	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
#define idB2AD01LDU	 698	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
#define B2CV02RDU	 BUFFER[1633]	//( - , DU) Заданная скорость перемещения РБ2
#define idB2CV02RDU	 699	//( - , DU) Заданная скорость перемещения РБ2
#define B2AB07LDU	 BUFFER[1638]	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
#define idB2AB07LDU	 700	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
#define B2AB08LDU	 BUFFER[1640]	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
#define idB2AB08LDU	 701	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
#define B2AB05LDU	 BUFFER[1642]	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
#define idB2AB05LDU	 702	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
#define B2AB06LDU	 BUFFER[1644]	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
#define idB2AB06LDU	 703	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
#define A1AB13LDU	 BUFFER[1646]	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
#define idA1AB13LDU	 704	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
#define A1AB14LDU	 BUFFER[1648]	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
#define idA1AB14LDU	 705	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
#define A1AB16LDU	 BUFFER[1650]	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
#define idA1AB16LDU	 706	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
#define A1AB17LDU	 BUFFER[1652]	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
#define idA1AB17LDU	 707	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
#define A1AB18LDU	 BUFFER[1654]	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
#define idA1AB18LDU	 708	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
#define B1VS12LDU	 BUFFER[1656]	//( - , DU) Движение ББ2 в сторону ВУ
#define idB1VS12LDU	 709	//( - , DU) Движение ББ2 в сторону ВУ
#define B1CV01RDU	 BUFFER[1658]	//( - , DU) Измеренная скорость перемещения ББ2
#define idB1CV01RDU	 710	//( - , DU) Измеренная скорость перемещения ББ2
#define B1AB04LDU	 BUFFER[1663]	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
#define idB1AB04LDU	 711	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
#define B1AB02LDU	 BUFFER[1665]	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
#define idB1AB02LDU	 712	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
#define B1AB01LDU	 BUFFER[1667]	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
#define idB1AB01LDU	 713	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
#define B1VS22LDU	 BUFFER[1669]	//( - , DU) Движение ББ2 в сторону НУ
#define idB1VS22LDU	 714	//( - , DU) Движение ББ2 в сторону НУ
#define B1AZ03LDU	 BUFFER[1671]	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
#define idB1AZ03LDU	 715	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
#define B1AD11LDU	 BUFFER[1673]	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	 716	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
#define B1AD21LDU	 BUFFER[1675]	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	 717	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
#define B1AD02LDU	 BUFFER[1677]	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
#define idB1AD02LDU	 718	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
#define B1AD03LDU	 BUFFER[1679]	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
#define idB1AD03LDU	 719	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
#define B1AD04LDU	 BUFFER[1681]	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
#define idB1AD04LDU	 720	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
#define B1AD05LDU	 BUFFER[1683]	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
#define idB1AD05LDU	 721	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
#define B1AD01LDU	 BUFFER[1685]	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
#define idB1AD01LDU	 722	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
#define B1CV02RDU	 BUFFER[1687]	//( - , DU) Заданная скорость перемещения ББ2
#define idB1CV02RDU	 723	//( - , DU) Заданная скорость перемещения ББ2
#define B1AB07LDU	 BUFFER[1692]	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
#define idB1AB07LDU	 724	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
#define B1AB08LDU	 BUFFER[1694]	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
#define idB1AB08LDU	 725	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
#define B1AB05LDU	 BUFFER[1696]	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
#define idB1AB05LDU	 726	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
#define R2IS11LDU	 BUFFER[1698]	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
#define idR2IS11LDU	 727	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
#define A1VS12LDU	 BUFFER[1700]	//( - , DU) Движение ББ1 в сторону ВУ
#define idA1VS12LDU	 728	//( - , DU) Движение ББ1 в сторону ВУ
#define A1CV01RDU	 BUFFER[1702]	//( - , DU) Измеренная скорость перемещения ББ1
#define idA1CV01RDU	 729	//( - , DU) Измеренная скорость перемещения ББ1
#define A1AB04LDU	 BUFFER[1707]	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
#define idA1AB04LDU	 730	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
#define A1AB02LDU	 BUFFER[1709]	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
#define idA1AB02LDU	 731	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
#define A1AB01LDU	 BUFFER[1711]	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
#define idA1AB01LDU	 732	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
#define A1VS22LDU	 BUFFER[1713]	//( - , DU) Движение ББ1 в сторону НУ
#define idA1VS22LDU	 733	//( - , DU) Движение ББ1 в сторону НУ
#define A1AZ03LDU	 BUFFER[1715]	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
#define idA1AZ03LDU	 734	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
#define A1AD11LDU	 BUFFER[1717]	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	 735	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
#define A1AD21LDU	 BUFFER[1719]	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	 736	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
#define A1AD02LDU	 BUFFER[1721]	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
#define idA1AD02LDU	 737	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
#define A1AD03LDU	 BUFFER[1723]	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
#define idA1AD03LDU	 738	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
#define A1AD04LDU	 BUFFER[1725]	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
#define idA1AD04LDU	 739	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
#define A1AD05LDU	 BUFFER[1727]	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
#define idA1AD05LDU	 740	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
#define A1AD01LDU	 BUFFER[1729]	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
#define idA1AD01LDU	 741	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
#define A1CV02RDU	 BUFFER[1731]	//( - , DU) Заданная скорость перемещения ББ1
#define idA1CV02RDU	 742	//( - , DU) Заданная скорость перемещения ББ1
#define A1AB07LDU	 BUFFER[1736]	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
#define idA1AB07LDU	 743	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
#define A1AB08LDU	 BUFFER[1738]	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
#define idA1AB08LDU	 744	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
#define A1AB05LDU	 BUFFER[1740]	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
#define idA1AB05LDU	 745	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
#define A1AB06LDU	 BUFFER[1742]	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
#define idA1AB06LDU	 746	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
#define A1AB09LDU	 BUFFER[1744]	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
#define idA1AB09LDU	 747	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
#define A1AB10LDU	 BUFFER[1746]	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
#define idA1AB10LDU	 748	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
#define A1AB11LDU	 BUFFER[1748]	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
#define idA1AB11LDU	 749	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
#define A1AB12LDU	 BUFFER[1750]	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA1AB12LDU	 750	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define fEM_A1UC03RDU	 BUFFER[1752]	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define idfEM_A1UC03RDU	 751	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define dEM_A1UC05UDU	 BUFFER[1757]	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC05UDU	 752	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define dEM_A1UC06UDU	 BUFFER[1762]	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC06UDU	 753	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define dEM_A2UC06UDU	 BUFFER[1767]	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC06UDU	 754	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define dEM_A2UC05UDU	 BUFFER[1772]	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC05UDU	 755	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define fEM_A2UC03RDU	 BUFFER[1777]	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define idfEM_A2UC03RDU	 756	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define dEM_A3UC06UDU	 BUFFER[1782]	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC06UDU	 757	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define dEM_A3UC05UDU	 BUFFER[1787]	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC05UDU	 758	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define fEM_A3UC03RDU	 BUFFER[1792]	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define idfEM_A3UC03RDU	 759	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define dEM_A8UC06UDU	 BUFFER[1797]	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define iddEM_A8UC06UDU	 760	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define fEM_A8UC03RDU	 BUFFER[1802]	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
#define idfEM_A8UC03RDU	 761	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
#define dEM_A8UC05UDU	 BUFFER[1807]	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define iddEM_A8UC05UDU	 762	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define fEM_R0UV81RDU	 BUFFER[1812]	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	 763	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	 BUFFER[1817]	//(R0UV82RDU) 2-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	 764	//(R0UV82RDU) 2-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	 BUFFER[1822]	//(R0UV83RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	 765	//(R0UV83RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	 BUFFER[1827]	//(R0UV84RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	 766	//(R0UV84RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV86RDU	 BUFFER[1832]	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	 767	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV85RDU	 BUFFER[1837]	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	 768	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV87RDU	 BUFFER[1842]	//(R0UV87RDU) 8-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	 769	//(R0UV87RDU) 8-я скорость перемещения ББ (шагов/секунду)
#define fEM_A3UP03RDU	 BUFFER[1847]	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	 770	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	 BUFFER[1852]	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	 771	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP43RDU	 BUFFER[1857]	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define idfEM_A3UP43RDU	 772	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define fEM_A3UP44RDU	 BUFFER[1862]	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP44RDU	 773	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP53RDU	 BUFFER[1867]	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP53RDU	 774	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP85RDU	 BUFFER[1872]	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP85RDU	 775	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP88RDU	 BUFFER[1877]	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP88RDU	 776	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP86RDU	 BUFFER[1882]	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP86RDU	 777	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_B8UV01RDU	 BUFFER[1887]	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
#define idfEM_B8UV01RDU	 778	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
#define fEM_B8UV02RDU	 BUFFER[1892]	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
#define idfEM_B8UV02RDU	 779	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
#define fEM_B8UV03RDU	 BUFFER[1897]	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
#define idfEM_B8UV03RDU	 780	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
#define fEM_B8UL04RDU	 BUFFER[1902]	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
#define idfEM_B8UL04RDU	 781	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
#define iEM_A2UV03CDU	 BUFFER[1907]	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define idiEM_A2UV03CDU	 782	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define fEM_A2UV01RDU	 BUFFER[1910]	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define idfEM_A2UV01RDU	 783	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define fEM_A2UV02RDU	 BUFFER[1915]	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define idfEM_A2UV02RDU	 784	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define fEM_A1UV01RDU	 BUFFER[1920]	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define idfEM_A1UV01RDU	 785	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define fEM_A1UV02RDU	 BUFFER[1925]	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define idfEM_A1UV02RDU	 786	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define fEM_A1UC06RDU	 BUFFER[1930]	//(A1UC06RDU) Уставка определения самохода ББ  мм
#define idfEM_A1UC06RDU	 787	//(A1UC06RDU) Уставка определения самохода ББ  мм
#define fEM_A1UC05RDU	 BUFFER[1935]	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A1UC05RDU	 788	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A1UL04RDU	 BUFFER[1940]	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define idfEM_A1UL04RDU	 789	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define fEM_A3UV01RDU	 BUFFER[1945]	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
#define idfEM_A3UV01RDU	 790	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
#define fEM_A3UV02RDU	 BUFFER[1950]	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
#define idfEM_A3UV02RDU	 791	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
#define fEM_A3UC06RDU	 BUFFER[1955]	//(A3UC06RDU) Уставка определения самохода ИС1  мм
#define idfEM_A3UC06RDU	 792	//(A3UC06RDU) Уставка определения самохода ИС1  мм
#define fEM_A3UC05RDU	 BUFFER[1960]	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A3UC05RDU	 793	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define fEM_A3UL04RDU	 BUFFER[1965]	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define idfEM_A3UL04RDU	 794	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define fEM_A3UP54RDU	 BUFFER[1970]	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define idfEM_A3UP54RDU	 795	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define fEM_A3UP87RDU	 BUFFER[1975]	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP87RDU	 796	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_R0UL05RDU	 BUFFER[1980]	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
#define idfEM_R0UL05RDU	 797	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
#define fEM_R0UL20RDU	 BUFFER[1985]	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
#define idfEM_R0UL20RDU	 798	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
#define fEM_B8UV04RDU	 BUFFER[1990]	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
#define idfEM_B8UV04RDU	 799	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
#define fEM_B8UC06RDU	 BUFFER[1995]	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
#define idfEM_B8UC06RDU	 800	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
#define fEM_B8UC05RDU	 BUFFER[2000]	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
#define idfEM_B8UC05RDU	 801	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
#define fEM_A2UL05RDU	 BUFFER[2005]	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define idfEM_A2UL05RDU	 802	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define fEM_A2UL03RDU	 BUFFER[2010]	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL03RDU	 803	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A2UC06RDU	 BUFFER[2015]	//(A2UC06RDU) Уставка определения самохода РБ  мм
#define idfEM_A2UC06RDU	 804	//(A2UC06RDU) Уставка определения самохода РБ  мм
#define fEM_A2UC05RDU	 BUFFER[2020]	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A2UC05RDU	 805	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A2UL04RDU	 BUFFER[2025]	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define idfEM_A2UL04RDU	 806	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define fEM_A1UL03RDU	 BUFFER[2030]	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define idfEM_A1UL03RDU	 807	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define fEM_A1UL05RDU	 BUFFER[2035]	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define idfEM_A1UL05RDU	 808	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define fEM_A3UL03RDU	 BUFFER[2040]	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define idfEM_A3UL03RDU	 809	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define fEM_A3UL05RDU	 BUFFER[2045]	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define idfEM_A3UL05RDU	 810	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define fEM_A1UC08RDU	 BUFFER[2050]	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define idfEM_A1UC08RDU	 811	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define fEM_A3UC08RDU	 BUFFER[2055]	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define idfEM_A3UC08RDU	 812	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define fEM_A1UC07RDU	 BUFFER[2060]	//(A1UC07RDU) Зона возврата при наведении ББ мм
#define idfEM_A1UC07RDU	 813	//(A1UC07RDU) Зона возврата при наведении ББ мм
#define fEM_A1UL01RDU	 BUFFER[2065]	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A1UL01RDU	 814	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A3UC07RDU	 BUFFER[2070]	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define idfEM_A3UC07RDU	 815	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define fEM_A3UL01RDU	 BUFFER[2075]	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A3UL01RDU	 816	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A2UC08RDU	 BUFFER[2080]	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define idfEM_A2UC08RDU	 817	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define fEM_A2UC07RDU	 BUFFER[2085]	//(A2UC07RDU) Зона возврата при наведении РБ  мм
#define idfEM_A2UC07RDU	 818	//(A2UC07RDU) Зона возврата при наведении РБ  мм
#define fEM_A2UL01RDU	 BUFFER[2090]	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A2UL01RDU	 819	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_B8UC01RDU	 BUFFER[2095]	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
#define idfEM_B8UC01RDU	 820	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
#define fEM_B8UL07RDU	 BUFFER[2100]	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
#define idfEM_B8UL07RDU	 821	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
#define fEM_B8UC02RDU	 BUFFER[2105]	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
#define idfEM_B8UC02RDU	 822	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
#define fEM_B8UL01RDU	 BUFFER[2110]	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_B8UL01RDU	 823	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_B8UL05RDU	 BUFFER[2115]	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
#define idfEM_B8UL05RDU	 824	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
#define fEM_B8UL03RDU	 BUFFER[2120]	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
#define idfEM_B8UL03RDU	 825	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
#define fEM_B8UL06RDU	 BUFFER[2125]	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
#define idfEM_B8UL06RDU	 826	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
#define fEM_A9UZ03RDU	 BUFFER[2130]	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
#define idfEM_A9UZ03RDU	 827	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
#define fEM_A9UZ04RDU	 BUFFER[2135]	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
#define idfEM_A9UZ04RDU	 828	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
#define fEM_A9UZ05RDU	 BUFFER[2140]	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
#define idfEM_A9UZ05RDU	 829	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
#define fEM_R4UZ04RDU	 BUFFER[2145]	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define idfEM_R4UZ04RDU	 830	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define fEM_R4UZ03RDU	 BUFFER[2150]	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define idfEM_R4UZ03RDU	 831	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define fEM_R4UZ05RDU	 BUFFER[2155]	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define idfEM_R4UZ05RDU	 832	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define fEM_A5UZ03RDU	 BUFFER[2160]	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
#define idfEM_A5UZ03RDU	 833	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
#define fEM_A5UZ04RDU	 BUFFER[2165]	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
#define idfEM_A5UZ04RDU	 834	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
#define fEM_A5UZ05RDU	 BUFFER[2170]	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
#define idfEM_A5UZ05RDU	 835	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
#define fEM_A4UZ03RDU	 BUFFER[2175]	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
#define idfEM_A4UZ03RDU	 836	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
#define fEM_A4UZ04RDU	 BUFFER[2180]	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
#define idfEM_A4UZ04RDU	 837	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
#define fEM_A4UZ05RDU	 BUFFER[2185]	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
#define idfEM_A4UZ05RDU	 838	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
#define fEM_A6UZ03RDU	 BUFFER[2190]	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
#define idfEM_A6UZ03RDU	 839	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
#define fEM_A6UZ04RDU	 BUFFER[2195]	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
#define idfEM_A6UZ04RDU	 840	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
#define fEM_A6UZ05RDU	 BUFFER[2200]	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
#define idfEM_A6UZ05RDU	 841	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
#define fEM_R1UZ03RDU	 BUFFER[2205]	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define idfEM_R1UZ03RDU	 842	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define fEM_R1UZ04RDU	 BUFFER[2210]	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define idfEM_R1UZ04RDU	 843	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define fEM_R1UZ05RDU	 BUFFER[2215]	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define idfEM_R1UZ05RDU	 844	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define fEM_R0UL04RDU	 BUFFER[2220]	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
#define idfEM_R0UL04RDU	 845	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
#define fEM_R0UL06RDU	 BUFFER[2225]	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
#define idfEM_R0UL06RDU	 846	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
#define fEM_R0UL03RDU	 BUFFER[2230]	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
#define idfEM_R0UL03RDU	 847	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
#define fEM_R0UL17RDU	 BUFFER[2235]	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
#define idfEM_R0UL17RDU	 848	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
#define fEM_R0UL19RDU	 BUFFER[2240]	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define idfEM_R0UL19RDU	 849	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define fEM_R0UL07RDU	 BUFFER[2245]	//(R0UL07RDU) Время срабатывания верхней АС II УР
#define idfEM_R0UL07RDU	 850	//(R0UL07RDU) Время срабатывания верхней АС II УР
#define fEM_R0UL18RDU	 BUFFER[2250]	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
#define idfEM_R0UL18RDU	 851	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
#define fEM_R0UL16RDU	 BUFFER[2255]	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
#define idfEM_R0UL16RDU	 852	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
#define fEM_R0UL02RDU	 BUFFER[2260]	//(R0UL02RDU) Время задержки  ИНИ
#define idfEM_R0UL02RDU	 853	//(R0UL02RDU) Время задержки  ИНИ
#define fEM_R0UN08RDU	 BUFFER[2265]	//(R0UN08RDU) 8-я заданная мощность
#define idfEM_R0UN08RDU	 854	//(R0UN08RDU) 8-я заданная мощность
#define fEM_R0UN07RDU	 BUFFER[2270]	//(R0UN07RDU) 7-я заданная мощность
#define idfEM_R0UN07RDU	 855	//(R0UN07RDU) 7-я заданная мощность
#define fEM_R0UN06RDU	 BUFFER[2275]	//(R0UN06RDU) 6-я заданная мощность
#define idfEM_R0UN06RDU	 856	//(R0UN06RDU) 6-я заданная мощность
#define fEM_R0UN05RDU	 BUFFER[2280]	//(R0UN05RDU) 5-я заданная мощность
#define idfEM_R0UN05RDU	 857	//(R0UN05RDU) 5-я заданная мощность
#define fEM_R0UN04RDU	 BUFFER[2285]	//(R0UN04RDU) 4-я заданная мощность
#define idfEM_R0UN04RDU	 858	//(R0UN04RDU) 4-я заданная мощность
#define fEM_R0UN03RDU	 BUFFER[2290]	//(R0UN03RDU) Ограничение 3 по мощности
#define idfEM_R0UN03RDU	 859	//(R0UN03RDU) Ограничение 3 по мощности
#define fEM_R0UN02RDU	 BUFFER[2295]	//(R0UN02RDU) 2-я заданная мощность
#define idfEM_R0UN02RDU	 860	//(R0UN02RDU) 2-я заданная мощность
#define fEM_R0UN01RDU	 BUFFER[2300]	//(R0UN01RDU) 1-я заданная мощность
#define idfEM_R0UN01RDU	 861	//(R0UN01RDU) 1-я заданная мощность
#define fEM_A2UC82RDU	 BUFFER[2305]	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC82RDU	 862	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define fEM_A2UC83RDU	 BUFFER[2310]	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define idfEM_A2UC83RDU	 863	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define fEM_A1UC83RDU	 BUFFER[2315]	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define idfEM_A1UC83RDU	 864	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define fEM_A2UC81RDU	 BUFFER[2320]	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC81RDU	 865	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define fEM_A1UC81RDU	 BUFFER[2325]	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC81RDU	 866	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define fEM_A1UC82RDU	 BUFFER[2330]	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC82RDU	 867	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define fEM_A2UL83RDU	 BUFFER[2335]	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL83RDU	 868	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A3UC81RDU	 BUFFER[2340]	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define idfEM_A3UC81RDU	 869	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define fEM_A3UC82RDU	 BUFFER[2345]	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define idfEM_A3UC82RDU	 870	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define fEM_R0UN80RDU	 BUFFER[2350]	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define idfEM_R0UN80RDU	 871	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define iEM_A2UV01IDU	 BUFFER[2355]	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV01IDU	 872	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define iEM_A2UV02IDU	 BUFFER[2358]	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV02IDU	 873	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define iEM_A1UV01IDU	 BUFFER[2361]	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV01IDU	 874	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define iEM_A1UV02IDU	 BUFFER[2364]	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV02IDU	 875	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define iEM_A1UV03IDU	 BUFFER[2367]	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define idiEM_A1UV03IDU	 876	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define iEM_A3UV01IDU	 BUFFER[2370]	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define idiEM_A3UV01IDU	 877	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define iEM_A3UV02IDU	 BUFFER[2373]	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define idiEM_A3UV02IDU	 878	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define lEM_R0MD01LC1	 BUFFER[2376]	//(R0MD01LC1) Ручное управление ОРР
#define idlEM_R0MD01LC1	 879	//(R0MD01LC1) Ручное управление ОРР
#define fEM_A3UC09RDU	 BUFFER[2378]	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC09RDU	 880	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define fEM_A2UC02RDU	 BUFFER[2383]	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define idfEM_A2UC02RDU	 881	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define fEM_A1UC02RDU	 BUFFER[2388]	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define idfEM_A1UC02RDU	 882	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define fEM_A3UC02RDU	 BUFFER[2393]	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define idfEM_A3UC02RDU	 883	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define fEM_R0UL21RDU	 BUFFER[2398]	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
#define idfEM_R0UL21RDU	 884	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
#define fEM_R0UN09RDU	 BUFFER[2403]	//(R0UN09RDU) Минимальный период при регулировании мощности
#define idfEM_R0UN09RDU	 885	//(R0UN09RDU) Минимальный период при регулировании мощности
#define fEM_R0UN11RDU	 BUFFER[2408]	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
#define idfEM_R0UN11RDU	 886	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
#define fEM_R0UN12RDU	 BUFFER[2413]	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
#define idfEM_R0UN12RDU	 887	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
#define fEM_R0UN13RDU	 BUFFER[2418]	//(R0UN13RDU) Минимальное изменение координаты, мм
#define idfEM_R0UN13RDU	 888	//(R0UN13RDU) Минимальное изменение координаты, мм
#define fEM_R0UN14RDU	 BUFFER[2423]	//(R0UN14RDU) Максимальная координата штока ИМ, мм
#define idfEM_R0UN14RDU	 889	//(R0UN14RDU) Максимальная координата штока ИМ, мм
#define fEM_R0UN16RDU	 BUFFER[2428]	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN16RDU	 890	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN17RDU	 BUFFER[2433]	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN17RDU	 891	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN18RDU	 BUFFER[2438]	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
#define idfEM_R0UN18RDU	 892	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
#define fEM_R0UN19RDU	 BUFFER[2443]	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define idfEM_R0UN19RDU	 893	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define fEM_R0UN70LDU	 BUFFER[2448]	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN70LDU	 894	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN71LDU	 BUFFER[2453]	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN71LDU	 895	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN72LDU	 BUFFER[2458]	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN72LDU	 896	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN73LDU	 BUFFER[2463]	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN73LDU	 897	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN74LDU	 BUFFER[2468]	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN74LDU	 898	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN75LDU	 BUFFER[2473]	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN75LDU	 899	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN80LDU	 BUFFER[2478]	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN80LDU	 900	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define fEM_R0UN81LDU	 BUFFER[2483]	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN81LDU	 901	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define fEM_R0UN82LDU	 BUFFER[2488]	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN82LDU	 902	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define fEM_R0UN83LDU	 BUFFER[2493]	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN83LDU	 903	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define fEM_R0UN84LDU	 BUFFER[2498]	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN84LDU	 904	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define fEM_R0UN85LDU	 BUFFER[2503]	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN85LDU	 905	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define fEM_R0UT20RDU	 BUFFER[2508]	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define idfEM_R0UT20RDU	 906	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define fEM_R0UN25RDU	 BUFFER[2513]	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
#define idfEM_R0UN25RDU	 907	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
#define fEM_R0UN15RDU	 BUFFER[2518]	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
#define idfEM_R0UN15RDU	 908	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
#define fEM_R0UN26RDU	 BUFFER[2523]	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
#define idfEM_R0UN26RDU	 909	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
#define fEM_R0UN27RDU	 BUFFER[2528]	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
#define idfEM_R0UN27RDU	 910	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
#define fEM_R0UN24RDU	 BUFFER[2533]	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN24RDU	 911	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
#define fEM_R0UL25RDU	 BUFFER[2538]	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define idfEM_R0UL25RDU	 912	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define fEM_R0UL01RSS	 BUFFER[2543]	//(R0UL01RSS) Шаг измерения периода (сек)
#define idfEM_R0UL01RSS	 913	//(R0UL01RSS) Шаг измерения периода (сек)
#define fEM_R0UL02RSS	 BUFFER[2548]	//(R0UL02RSS) Tф-постоянная времени, с
#define idfEM_R0UL02RSS	 914	//(R0UL02RSS) Tф-постоянная времени, с
#define fEM_R0UN03RSS	 BUFFER[2553]	//(R0UN03RSS) нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN03RSS	 915	//(R0UN03RSS) нижняя граница интервала мощности для измерения периода (ватт)
#define fEM_R7UI76RDU	 BUFFER[2558]	//(R7UI76RDU) Время срабатывания сигнала II УР при имитации
#define idfEM_R7UI76RDU	 916	//(R7UI76RDU) Время срабатывания сигнала II УР при имитации
#define fEM_R0UL00RDU	 BUFFER[2563]	//(R0UL00RDU) Время ожидания передачи  сигнала отключения сети
#define idfEM_R0UL00RDU	 917	//(R0UL00RDU) Время ожидания передачи  сигнала отключения сети
#define bFirstEnterFlag	 BUFFER[2568]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 918	//(bFirstEnterFlag) 
#define internal2_m260_tx	 BUFFER[2570]	//(internal2_m260_tx) tx - время накопленное сек
#define idinternal2_m260_tx	 919	//(internal2_m260_tx) tx - время накопленное сек
#define internal2_m260_y0	 BUFFER[2575]	//(internal2_m260_y0) y0
#define idinternal2_m260_y0	 920	//(internal2_m260_y0) y0
#define internal2_m258_tx	 BUFFER[2576]	//(internal2_m258_tx) tx - время накопленное сек
#define idinternal2_m258_tx	 921	//(internal2_m258_tx) tx - время накопленное сек
#define internal2_m258_y0	 BUFFER[2581]	//(internal2_m258_y0) y0
#define idinternal2_m258_y0	 922	//(internal2_m258_y0) y0
#define internal2_m256_tx	 BUFFER[2582]	//(internal2_m256_tx) tx - время накопленное сек
#define idinternal2_m256_tx	 923	//(internal2_m256_tx) tx - время накопленное сек
#define internal2_m256_y0	 BUFFER[2587]	//(internal2_m256_y0) y0
#define idinternal2_m256_y0	 924	//(internal2_m256_y0) y0
#define internal2_m254_tx	 BUFFER[2588]	//(internal2_m254_tx) tx - время накопленное сек
#define idinternal2_m254_tx	 925	//(internal2_m254_tx) tx - время накопленное сек
#define internal2_m254_y0	 BUFFER[2593]	//(internal2_m254_y0) y0
#define idinternal2_m254_y0	 926	//(internal2_m254_y0) y0
#define internal2_m252_tx	 BUFFER[2594]	//(internal2_m252_tx) tx - время накопленное сек
#define idinternal2_m252_tx	 927	//(internal2_m252_tx) tx - время накопленное сек
#define internal2_m252_y0	 BUFFER[2599]	//(internal2_m252_y0) y0
#define idinternal2_m252_y0	 928	//(internal2_m252_y0) y0
#define internal2_m250_tx	 BUFFER[2600]	//(internal2_m250_tx) tx - время накопленное сек
#define idinternal2_m250_tx	 929	//(internal2_m250_tx) tx - время накопленное сек
#define internal2_m250_y0	 BUFFER[2605]	//(internal2_m250_y0) y0
#define idinternal2_m250_y0	 930	//(internal2_m250_y0) y0
#define internal2_m248_tx	 BUFFER[2606]	//(internal2_m248_tx) tx - время накопленное сек
#define idinternal2_m248_tx	 931	//(internal2_m248_tx) tx - время накопленное сек
#define internal2_m248_y0	 BUFFER[2611]	//(internal2_m248_y0) y0
#define idinternal2_m248_y0	 932	//(internal2_m248_y0) y0
#define internal2_m246_tx	 BUFFER[2612]	//(internal2_m246_tx) tx - время накопленное сек
#define idinternal2_m246_tx	 933	//(internal2_m246_tx) tx - время накопленное сек
#define internal2_m246_y0	 BUFFER[2617]	//(internal2_m246_y0) y0
#define idinternal2_m246_y0	 934	//(internal2_m246_y0) y0
#define internal2_m244_tx	 BUFFER[2618]	//(internal2_m244_tx) tx - время накопленное сек
#define idinternal2_m244_tx	 935	//(internal2_m244_tx) tx - время накопленное сек
#define internal2_m244_y0	 BUFFER[2623]	//(internal2_m244_y0) y0
#define idinternal2_m244_y0	 936	//(internal2_m244_y0) y0
#define internal2_m242_tx	 BUFFER[2624]	//(internal2_m242_tx) tx - время накопленное сек
#define idinternal2_m242_tx	 937	//(internal2_m242_tx) tx - время накопленное сек
#define internal2_m242_y0	 BUFFER[2629]	//(internal2_m242_y0) y0
#define idinternal2_m242_y0	 938	//(internal2_m242_y0) y0
#define internal2_m240_tx	 BUFFER[2630]	//(internal2_m240_tx) tx - время накопленное сек
#define idinternal2_m240_tx	 939	//(internal2_m240_tx) tx - время накопленное сек
#define internal2_m240_y0	 BUFFER[2635]	//(internal2_m240_y0) y0
#define idinternal2_m240_y0	 940	//(internal2_m240_y0) y0
#define internal2_m238_tx	 BUFFER[2636]	//(internal2_m238_tx) tx - время накопленное сек
#define idinternal2_m238_tx	 941	//(internal2_m238_tx) tx - время накопленное сек
#define internal2_m238_y0	 BUFFER[2641]	//(internal2_m238_y0) y0
#define idinternal2_m238_y0	 942	//(internal2_m238_y0) y0
#define internal2_m182_tx	 BUFFER[2642]	//(internal2_m182_tx) tx - время накопленное сек
#define idinternal2_m182_tx	 943	//(internal2_m182_tx) tx - время накопленное сек
#define internal2_m182_y0	 BUFFER[2647]	//(internal2_m182_y0) y0
#define idinternal2_m182_y0	 944	//(internal2_m182_y0) y0
#define internal2_m176_tx	 BUFFER[2648]	//(internal2_m176_tx) tx - время накопленное сек
#define idinternal2_m176_tx	 945	//(internal2_m176_tx) tx - время накопленное сек
#define internal2_m176_y0	 BUFFER[2653]	//(internal2_m176_y0) y0
#define idinternal2_m176_y0	 946	//(internal2_m176_y0) y0
#define internal2_m172_tx	 BUFFER[2654]	//(internal2_m172_tx) tx - время накопленное сек
#define idinternal2_m172_tx	 947	//(internal2_m172_tx) tx - время накопленное сек
#define internal2_m172_y0	 BUFFER[2659]	//(internal2_m172_y0) y0
#define idinternal2_m172_y0	 948	//(internal2_m172_y0) y0
#define internal2_m165_tx	 BUFFER[2660]	//(internal2_m165_tx) tx - время накопленное сек
#define idinternal2_m165_tx	 949	//(internal2_m165_tx) tx - время накопленное сек
#define internal2_m165_y0	 BUFFER[2665]	//(internal2_m165_y0) y0
#define idinternal2_m165_y0	 950	//(internal2_m165_y0) y0
#define internal2_m157_tx	 BUFFER[2666]	//(internal2_m157_tx) tx - время накопленное сек
#define idinternal2_m157_tx	 951	//(internal2_m157_tx) tx - время накопленное сек
#define internal2_m157_y0	 BUFFER[2671]	//(internal2_m157_y0) y0
#define idinternal2_m157_y0	 952	//(internal2_m157_y0) y0
#define internal2_m155_tx	 BUFFER[2672]	//(internal2_m155_tx) tx - время накопленное сек
#define idinternal2_m155_tx	 953	//(internal2_m155_tx) tx - время накопленное сек
#define internal2_m155_y0	 BUFFER[2677]	//(internal2_m155_y0) y0
#define idinternal2_m155_y0	 954	//(internal2_m155_y0) y0
#define internal2_m149_tx	 BUFFER[2678]	//(internal2_m149_tx) tx - время накопленное сек
#define idinternal2_m149_tx	 955	//(internal2_m149_tx) tx - время накопленное сек
#define internal2_m149_y0	 BUFFER[2683]	//(internal2_m149_y0) y0
#define idinternal2_m149_y0	 956	//(internal2_m149_y0) y0
#define internal2_m144_tx	 BUFFER[2684]	//(internal2_m144_tx) tx - время накопленное сек
#define idinternal2_m144_tx	 957	//(internal2_m144_tx) tx - время накопленное сек
#define internal2_m144_y0	 BUFFER[2689]	//(internal2_m144_y0) y0
#define idinternal2_m144_y0	 958	//(internal2_m144_y0) y0
#define internal2_m141_tx	 BUFFER[2690]	//(internal2_m141_tx) tx - время накопленное сек
#define idinternal2_m141_tx	 959	//(internal2_m141_tx) tx - время накопленное сек
#define internal2_m141_y0	 BUFFER[2695]	//(internal2_m141_y0) y0
#define idinternal2_m141_y0	 960	//(internal2_m141_y0) y0
#define internal2_m137_tx	 BUFFER[2696]	//(internal2_m137_tx) tx - время накопленное сек
#define idinternal2_m137_tx	 961	//(internal2_m137_tx) tx - время накопленное сек
#define internal2_m137_y0	 BUFFER[2701]	//(internal2_m137_y0) y0
#define idinternal2_m137_y0	 962	//(internal2_m137_y0) y0
#define internal2_m131_tx	 BUFFER[2702]	//(internal2_m131_tx) tx - время накопленное сек
#define idinternal2_m131_tx	 963	//(internal2_m131_tx) tx - время накопленное сек
#define internal2_m131_y0	 BUFFER[2707]	//(internal2_m131_y0) y0
#define idinternal2_m131_y0	 964	//(internal2_m131_y0) y0
#define internal2_m127_tx	 BUFFER[2708]	//(internal2_m127_tx) tx - время накопленное сек
#define idinternal2_m127_tx	 965	//(internal2_m127_tx) tx - время накопленное сек
#define internal2_m127_y0	 BUFFER[2713]	//(internal2_m127_y0) y0
#define idinternal2_m127_y0	 966	//(internal2_m127_y0) y0
#define internal2_m195_y0	 BUFFER[2714]	//(internal2_m195_y0) y0
#define idinternal2_m195_y0	 967	//(internal2_m195_y0) y0
#define internal2_m193_y0	 BUFFER[2719]	//(internal2_m193_y0) y0
#define idinternal2_m193_y0	 968	//(internal2_m193_y0) y0
#define internal2_m226_y0	 BUFFER[2724]	//(internal2_m226_y0) state
#define idinternal2_m226_y0	 969	//(internal2_m226_y0) state
#define internal2_m220_y0	 BUFFER[2726]	//(internal2_m220_y0) state
#define idinternal2_m220_y0	 970	//(internal2_m220_y0) state
#define internal2_m208_y1	 BUFFER[2728]	//(internal2_m208_y1) y1 - внутренний параметр
#define idinternal2_m208_y1	 971	//(internal2_m208_y1) y1 - внутренний параметр
#define internal2_m216_y1	 BUFFER[2730]	//(internal2_m216_y1) y1 - внутренний параметр
#define idinternal2_m216_y1	 972	//(internal2_m216_y1) y1 - внутренний параметр
#define internal2_m198_y1	 BUFFER[2732]	//(internal2_m198_y1) y1 - внутренний параметр
#define idinternal2_m198_y1	 973	//(internal2_m198_y1) y1 - внутренний параметр
#define internal2_m205_y1	 BUFFER[2734]	//(internal2_m205_y1) y1 - внутренний параметр
#define idinternal2_m205_y1	 974	//(internal2_m205_y1) y1 - внутренний параметр
#define internal2_m16_Nk0	 BUFFER[2736]	//(internal2_m16_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m16_Nk0	 975	//(internal2_m16_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m16_SetFlag	 BUFFER[2741]	//(internal2_m16_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m16_SetFlag	 976	//(internal2_m16_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m110_Nk0	 BUFFER[2743]	//(internal2_m110_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m110_Nk0	 977	//(internal2_m110_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m110_SetFlag	 BUFFER[2748]	//(internal2_m110_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m110_SetFlag	 978	//(internal2_m110_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m106_Nk0	 BUFFER[2750]	//(internal2_m106_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m106_Nk0	 979	//(internal2_m106_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m106_SetFlag	 BUFFER[2755]	//(internal2_m106_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m106_SetFlag	 980	//(internal2_m106_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m75_Nk0	 BUFFER[2757]	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m75_Nk0	 981	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m75_SetFlag	 BUFFER[2762]	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m75_SetFlag	 982	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m77_Nk0	 BUFFER[2764]	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m77_Nk0	 983	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m77_SetFlag	 BUFFER[2769]	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m77_SetFlag	 984	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m45_Nk0	 BUFFER[2771]	//(internal2_m45_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m45_Nk0	 985	//(internal2_m45_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m45_SetFlag	 BUFFER[2776]	//(internal2_m45_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m45_SetFlag	 986	//(internal2_m45_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m53_Nk0	 BUFFER[2778]	//(internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m53_Nk0	 987	//(internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m53_SetFlag	 BUFFER[2783]	//(internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m53_SetFlag	 988	//(internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m21_Nk0	 BUFFER[2785]	//(internal2_m21_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m21_Nk0	 989	//(internal2_m21_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m21_SetFlag	 BUFFER[2790]	//(internal2_m21_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m21_SetFlag	 990	//(internal2_m21_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal1_m2556_tx	 BUFFER[2792]	//(internal1_m2556_tx) tx - время накопленное сек
#define idinternal1_m2556_tx	 991	//(internal1_m2556_tx) tx - время накопленное сек
#define internal1_m2556_y0	 BUFFER[2797]	//(internal1_m2556_y0) y0
#define idinternal1_m2556_y0	 992	//(internal1_m2556_y0) y0
#define internal1_m2558_tx	 BUFFER[2798]	//(internal1_m2558_tx) tx - время накопленное сек
#define idinternal1_m2558_tx	 993	//(internal1_m2558_tx) tx - время накопленное сек
#define internal1_m2558_y0	 BUFFER[2803]	//(internal1_m2558_y0) y0
#define idinternal1_m2558_y0	 994	//(internal1_m2558_y0) y0
#define internal1_m2554_tx	 BUFFER[2804]	//(internal1_m2554_tx) tx - время накопленное сек
#define idinternal1_m2554_tx	 995	//(internal1_m2554_tx) tx - время накопленное сек
#define internal1_m2554_y0	 BUFFER[2809]	//(internal1_m2554_y0) y0
#define idinternal1_m2554_y0	 996	//(internal1_m2554_y0) y0
#define internal1_m2552_tx	 BUFFER[2810]	//(internal1_m2552_tx) tx - время накопленное сек
#define idinternal1_m2552_tx	 997	//(internal1_m2552_tx) tx - время накопленное сек
#define internal1_m2552_y0	 BUFFER[2815]	//(internal1_m2552_y0) y0
#define idinternal1_m2552_y0	 998	//(internal1_m2552_y0) y0
#define internal1_m221_tx	 BUFFER[2816]	//(internal1_m221_tx) tx - время накопленное сек
#define idinternal1_m221_tx	 999	//(internal1_m221_tx) tx - время накопленное сек
#define internal1_m221_y0	 BUFFER[2821]	//(internal1_m221_y0) y0
#define idinternal1_m221_y0	 1000	//(internal1_m221_y0) y0
#define internal1_m220_tx	 BUFFER[2822]	//(internal1_m220_tx) tx - внутренний параметр
#define idinternal1_m220_tx	 1001	//(internal1_m220_tx) tx - внутренний параметр
#define internal1_m2101_x0	 BUFFER[2827]	//(internal1_m2101_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m2101_x0	 1002	//(internal1_m2101_x0) - значение входного параметра на предыдущем шаге
#define internal1_m2101_tim	 BUFFER[2829]	//(internal1_m2101_tim) - время задержки выходного сигнала
#define idinternal1_m2101_tim	 1003	//(internal1_m2101_tim) - время задержки выходного сигнала
#define internal1_m1677_tx	 BUFFER[2834]	//(internal1_m1677_tx) tx - время накопленное сек
#define idinternal1_m1677_tx	 1004	//(internal1_m1677_tx) tx - время накопленное сек
#define internal1_m1677_y0	 BUFFER[2839]	//(internal1_m1677_y0) y0
#define idinternal1_m1677_y0	 1005	//(internal1_m1677_y0) y0
#define internal1_m79_flst	 BUFFER[2840]	//(internal1_m79_flst)  флаг старта измерения
#define idinternal1_m79_flst	 1006	//(internal1_m79_flst)  флаг старта измерения
#define internal1_m79_chsr	 BUFFER[2843]	//(internal1_m79_chsr)  счетчик усреднения
#define idinternal1_m79_chsr	 1007	//(internal1_m79_chsr)  счетчик усреднения
#define internal1_m79_chizm	 BUFFER[2846]	//(internal1_m79_chizm)  счетчик уменьшения мощности
#define idinternal1_m79_chizm	 1008	//(internal1_m79_chizm)  счетчик уменьшения мощности
#define internal1_m79_sumtim	 BUFFER[2849]	//(internal1_m79_sumtim)  время измерения мощности
#define idinternal1_m79_sumtim	 1009	//(internal1_m79_sumtim)  время измерения мощности
#define internal1_m79_W1	 BUFFER[2854]	//(internal1_m79_W1)  мощность на старте измерения
#define idinternal1_m79_W1	 1010	//(internal1_m79_W1)  мощность на старте измерения
#define internal1_m79_W2	 BUFFER[2859]	//(internal1_m79_W2)  мощность в конце измерения
#define idinternal1_m79_W2	 1011	//(internal1_m79_W2)  мощность в конце измерения
#define internal1_m79_Wmin	 BUFFER[2864]	//(internal1_m79_Wmin)  минимальное измерение в серии
#define idinternal1_m79_Wmin	 1012	//(internal1_m79_Wmin)  минимальное измерение в серии
#define internal1_m79_Wmax	 BUFFER[2869]	//(internal1_m79_Wmax)  максимальное измерение в серии
#define idinternal1_m79_Wmax	 1013	//(internal1_m79_Wmax)  максимальное измерение в серии
#define internal1_m79_Wlast	 BUFFER[2874]	//(internal1_m79_Wlast)  последнее растущее измерение
#define idinternal1_m79_Wlast	 1014	//(internal1_m79_Wlast)  последнее растущее измерение
#define internal1_m79_y0	 BUFFER[2879]	//(internal1_m79_y0) y0 - внутренний параметр
#define idinternal1_m79_y0	 1015	//(internal1_m79_y0) y0 - внутренний параметр
#define internal1_m79_MyFirstEnterFlag	 BUFFER[2884]	//(internal1_m79_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m79_MyFirstEnterFlag	 1016	//(internal1_m79_MyFirstEnterFlag)  FirstEnterFlag
#define internal1_m2066_tx	 BUFFER[2886]	//(internal1_m2066_tx) tx - внутренний параметр
#define idinternal1_m2066_tx	 1017	//(internal1_m2066_tx) tx - внутренний параметр
#define internal1_m2065_tx	 BUFFER[2891]	//(internal1_m2065_tx) tx - внутренний параметр
#define idinternal1_m2065_tx	 1018	//(internal1_m2065_tx) tx - внутренний параметр
#define internal1_m785_tx	 BUFFER[2896]	//(internal1_m785_tx) tx - внутренний параметр
#define idinternal1_m785_tx	 1019	//(internal1_m785_tx) tx - внутренний параметр
#define internal1_m742_tx	 BUFFER[2901]	//(internal1_m742_tx) tx - внутренний параметр
#define idinternal1_m742_tx	 1020	//(internal1_m742_tx) tx - внутренний параметр
#define internal1_m795_tx	 BUFFER[2906]	//(internal1_m795_tx) tx - внутренний параметр
#define idinternal1_m795_tx	 1021	//(internal1_m795_tx) tx - внутренний параметр
#define internal1_m797_tx	 BUFFER[2911]	//(internal1_m797_tx) tx - внутренний параметр
#define idinternal1_m797_tx	 1022	//(internal1_m797_tx) tx - внутренний параметр
#define internal1_m796_tx	 BUFFER[2916]	//(internal1_m796_tx) tx - внутренний параметр
#define idinternal1_m796_tx	 1023	//(internal1_m796_tx) tx - внутренний параметр
#define internal1_m750_tx	 BUFFER[2921]	//(internal1_m750_tx) tx - внутренний параметр
#define idinternal1_m750_tx	 1024	//(internal1_m750_tx) tx - внутренний параметр
#define internal1_m735_tx	 BUFFER[2926]	//(internal1_m735_tx) tx - внутренний параметр
#define idinternal1_m735_tx	 1025	//(internal1_m735_tx) tx - внутренний параметр
#define internal1_m746_tx	 BUFFER[2931]	//(internal1_m746_tx) tx - внутренний параметр
#define idinternal1_m746_tx	 1026	//(internal1_m746_tx) tx - внутренний параметр
#define internal1_m777_tx	 BUFFER[2936]	//(internal1_m777_tx) tx - внутренний параметр
#define idinternal1_m777_tx	 1027	//(internal1_m777_tx) tx - внутренний параметр
#define internal1_m794_tx	 BUFFER[2941]	//(internal1_m794_tx) tx - внутренний параметр
#define idinternal1_m794_tx	 1028	//(internal1_m794_tx) tx - внутренний параметр
#define internal1_m767_tx	 BUFFER[2946]	//(internal1_m767_tx) tx - внутренний параметр
#define idinternal1_m767_tx	 1029	//(internal1_m767_tx) tx - внутренний параметр
#define internal1_m398_tx	 BUFFER[2951]	//(internal1_m398_tx) tx - внутренний параметр
#define idinternal1_m398_tx	 1030	//(internal1_m398_tx) tx - внутренний параметр
#define internal1_m397_tx	 BUFFER[2956]	//(internal1_m397_tx) tx - внутренний параметр
#define idinternal1_m397_tx	 1031	//(internal1_m397_tx) tx - внутренний параметр
#define internal1_m396_tx	 BUFFER[2961]	//(internal1_m396_tx) tx - внутренний параметр
#define idinternal1_m396_tx	 1032	//(internal1_m396_tx) tx - внутренний параметр
#define internal1_m395_tx	 BUFFER[2966]	//(internal1_m395_tx) tx - внутренний параметр
#define idinternal1_m395_tx	 1033	//(internal1_m395_tx) tx - внутренний параметр
#define internal1_m766_tx	 BUFFER[2971]	//(internal1_m766_tx) tx - внутренний параметр
#define idinternal1_m766_tx	 1034	//(internal1_m766_tx) tx - внутренний параметр
#define internal1_m761_tx	 BUFFER[2976]	//(internal1_m761_tx) tx - внутренний параметр
#define idinternal1_m761_tx	 1035	//(internal1_m761_tx) tx - внутренний параметр
#define internal1_m770_tx	 BUFFER[2981]	//(internal1_m770_tx) tx - внутренний параметр
#define idinternal1_m770_tx	 1036	//(internal1_m770_tx) tx - внутренний параметр
#define internal1_m775_tx	 BUFFER[2986]	//(internal1_m775_tx) tx - внутренний параметр
#define idinternal1_m775_tx	 1037	//(internal1_m775_tx) tx - внутренний параметр
#define internal1_m531_tx	 BUFFER[2991]	//(internal1_m531_tx) tx - внутренний параметр
#define idinternal1_m531_tx	 1038	//(internal1_m531_tx) tx - внутренний параметр
#define internal1_m530_tx	 BUFFER[2996]	//(internal1_m530_tx) tx - внутренний параметр
#define idinternal1_m530_tx	 1039	//(internal1_m530_tx) tx - внутренний параметр
#define internal1_m529_tx	 BUFFER[3001]	//(internal1_m529_tx) tx - внутренний параметр
#define idinternal1_m529_tx	 1040	//(internal1_m529_tx) tx - внутренний параметр
#define internal1_m525_tx	 BUFFER[3006]	//(internal1_m525_tx) tx - внутренний параметр
#define idinternal1_m525_tx	 1041	//(internal1_m525_tx) tx - внутренний параметр
#define internal1_m502_tx	 BUFFER[3011]	//(internal1_m502_tx) tx - внутренний параметр
#define idinternal1_m502_tx	 1042	//(internal1_m502_tx) tx - внутренний параметр
#define internal1_m501_tx	 BUFFER[3016]	//(internal1_m501_tx) tx - внутренний параметр
#define idinternal1_m501_tx	 1043	//(internal1_m501_tx) tx - внутренний параметр
#define internal1_m500_tx	 BUFFER[3021]	//(internal1_m500_tx) tx - внутренний параметр
#define idinternal1_m500_tx	 1044	//(internal1_m500_tx) tx - внутренний параметр
#define internal1_m503_tx	 BUFFER[3026]	//(internal1_m503_tx) tx - внутренний параметр
#define idinternal1_m503_tx	 1045	//(internal1_m503_tx) tx - внутренний параметр
#define internal1_m2472_tx	 BUFFER[3031]	//(internal1_m2472_tx) tx - внутренний параметр
#define idinternal1_m2472_tx	 1046	//(internal1_m2472_tx) tx - внутренний параметр
#define internal1_m2182_tx	 BUFFER[3036]	//(internal1_m2182_tx) tx - внутренний параметр
#define idinternal1_m2182_tx	 1047	//(internal1_m2182_tx) tx - внутренний параметр
#define internal1_m2471_tx	 BUFFER[3041]	//(internal1_m2471_tx) tx - внутренний параметр
#define idinternal1_m2471_tx	 1048	//(internal1_m2471_tx) tx - внутренний параметр
#define internal1_m2470_tx	 BUFFER[3046]	//(internal1_m2470_tx) tx - внутренний параметр
#define idinternal1_m2470_tx	 1049	//(internal1_m2470_tx) tx - внутренний параметр
#define internal1_m2467_tx	 BUFFER[3051]	//(internal1_m2467_tx) tx - внутренний параметр
#define idinternal1_m2467_tx	 1050	//(internal1_m2467_tx) tx - внутренний параметр
#define internal1_m108_tx	 BUFFER[3056]	//(internal1_m108_tx) tx - внутренний параметр
#define idinternal1_m108_tx	 1051	//(internal1_m108_tx) tx - внутренний параметр
#define internal1_m1148_tx	 BUFFER[3061]	//(internal1_m1148_tx) tx - внутренний параметр
#define idinternal1_m1148_tx	 1052	//(internal1_m1148_tx) tx - внутренний параметр
#define internal1_m2330_tx	 BUFFER[3066]	//(internal1_m2330_tx) tx - внутренний параметр
#define idinternal1_m2330_tx	 1053	//(internal1_m2330_tx) tx - внутренний параметр
#define internal1_m2329_tx	 BUFFER[3071]	//(internal1_m2329_tx) tx - внутренний параметр
#define idinternal1_m2329_tx	 1054	//(internal1_m2329_tx) tx - внутренний параметр
#define internal1_m2328_tx	 BUFFER[3076]	//(internal1_m2328_tx) tx - внутренний параметр
#define idinternal1_m2328_tx	 1055	//(internal1_m2328_tx) tx - внутренний параметр
#define internal1_m1260_tx	 BUFFER[3081]	//(internal1_m1260_tx) tx - внутренний параметр
#define idinternal1_m1260_tx	 1056	//(internal1_m1260_tx) tx - внутренний параметр
#define internal1_m1259_tx	 BUFFER[3086]	//(internal1_m1259_tx) tx - внутренний параметр
#define idinternal1_m1259_tx	 1057	//(internal1_m1259_tx) tx - внутренний параметр
#define internal1_m1255_tx	 BUFFER[3091]	//(internal1_m1255_tx) tx - внутренний параметр
#define idinternal1_m1255_tx	 1058	//(internal1_m1255_tx) tx - внутренний параметр
#define internal1_m1248_tx	 BUFFER[3096]	//(internal1_m1248_tx) tx - внутренний параметр
#define idinternal1_m1248_tx	 1059	//(internal1_m1248_tx) tx - внутренний параметр
#define internal1_m1246_tx	 BUFFER[3101]	//(internal1_m1246_tx) tx - внутренний параметр
#define idinternal1_m1246_tx	 1060	//(internal1_m1246_tx) tx - внутренний параметр
#define internal1_m1244_tx	 BUFFER[3106]	//(internal1_m1244_tx) tx - внутренний параметр
#define idinternal1_m1244_tx	 1061	//(internal1_m1244_tx) tx - внутренний параметр
#define internal1_m1242_tx	 BUFFER[3111]	//(internal1_m1242_tx) tx - внутренний параметр
#define idinternal1_m1242_tx	 1062	//(internal1_m1242_tx) tx - внутренний параметр
#define internal1_m1285_tx	 BUFFER[3116]	//(internal1_m1285_tx) tx - внутренний параметр
#define idinternal1_m1285_tx	 1063	//(internal1_m1285_tx) tx - внутренний параметр
#define internal1_m1292_tx	 BUFFER[3121]	//(internal1_m1292_tx) tx - внутренний параметр
#define idinternal1_m1292_tx	 1064	//(internal1_m1292_tx) tx - внутренний параметр
#define internal1_m1297_tx	 BUFFER[3126]	//(internal1_m1297_tx) tx - внутренний параметр
#define idinternal1_m1297_tx	 1065	//(internal1_m1297_tx) tx - внутренний параметр
#define internal1_m1303_tx	 BUFFER[3131]	//(internal1_m1303_tx) tx - внутренний параметр
#define idinternal1_m1303_tx	 1066	//(internal1_m1303_tx) tx - внутренний параметр
#define internal1_m1263_tx	 BUFFER[3136]	//(internal1_m1263_tx) tx - внутренний параметр
#define idinternal1_m1263_tx	 1067	//(internal1_m1263_tx) tx - внутренний параметр
#define internal1_m1284_tx	 BUFFER[3141]	//(internal1_m1284_tx) tx - внутренний параметр
#define idinternal1_m1284_tx	 1068	//(internal1_m1284_tx) tx - внутренний параметр
#define internal1_m1298_tx	 BUFFER[3146]	//(internal1_m1298_tx) tx - внутренний параметр
#define idinternal1_m1298_tx	 1069	//(internal1_m1298_tx) tx - внутренний параметр
#define internal1_m480_tx	 BUFFER[3151]	//(internal1_m480_tx) tx - внутренний параметр
#define idinternal1_m480_tx	 1070	//(internal1_m480_tx) tx - внутренний параметр
#define internal1_m474_tx	 BUFFER[3156]	//(internal1_m474_tx) tx - внутренний параметр
#define idinternal1_m474_tx	 1071	//(internal1_m474_tx) tx - внутренний параметр
#define internal1_m476_tx	 BUFFER[3161]	//(internal1_m476_tx) tx - внутренний параметр
#define idinternal1_m476_tx	 1072	//(internal1_m476_tx) tx - внутренний параметр
#define internal1_m478_tx	 BUFFER[3166]	//(internal1_m478_tx) tx - внутренний параметр
#define idinternal1_m478_tx	 1073	//(internal1_m478_tx) tx - внутренний параметр
#define internal1_m485_tx	 BUFFER[3171]	//(internal1_m485_tx) tx - внутренний параметр
#define idinternal1_m485_tx	 1074	//(internal1_m485_tx) tx - внутренний параметр
#define internal1_m439_tx	 BUFFER[3176]	//(internal1_m439_tx) tx - внутренний параметр
#define idinternal1_m439_tx	 1075	//(internal1_m439_tx) tx - внутренний параметр
#define internal1_m437_tx	 BUFFER[3181]	//(internal1_m437_tx) tx - внутренний параметр
#define idinternal1_m437_tx	 1076	//(internal1_m437_tx) tx - внутренний параметр
#define internal1_m438_tx	 BUFFER[3186]	//(internal1_m438_tx) tx - внутренний параметр
#define idinternal1_m438_tx	 1077	//(internal1_m438_tx) tx - внутренний параметр
#define internal1_m431_tx	 BUFFER[3191]	//(internal1_m431_tx) tx - внутренний параметр
#define idinternal1_m431_tx	 1078	//(internal1_m431_tx) tx - внутренний параметр
#define internal1_m893_tx	 BUFFER[3196]	//(internal1_m893_tx) tx - внутренний параметр
#define idinternal1_m893_tx	 1079	//(internal1_m893_tx) tx - внутренний параметр
#define internal1_m892_tx	 BUFFER[3201]	//(internal1_m892_tx) tx - внутренний параметр
#define idinternal1_m892_tx	 1080	//(internal1_m892_tx) tx - внутренний параметр
#define internal1_m891_tx	 BUFFER[3206]	//(internal1_m891_tx) tx - внутренний параметр
#define idinternal1_m891_tx	 1081	//(internal1_m891_tx) tx - внутренний параметр
#define internal1_m887_tx	 BUFFER[3211]	//(internal1_m887_tx) tx - внутренний параметр
#define idinternal1_m887_tx	 1082	//(internal1_m887_tx) tx - внутренний параметр
#define internal1_m1349_tx	 BUFFER[3216]	//(internal1_m1349_tx) tx - внутренний параметр
#define idinternal1_m1349_tx	 1083	//(internal1_m1349_tx) tx - внутренний параметр
#define internal1_m1348_tx	 BUFFER[3221]	//(internal1_m1348_tx) tx - внутренний параметр
#define idinternal1_m1348_tx	 1084	//(internal1_m1348_tx) tx - внутренний параметр
#define internal1_m1347_tx	 BUFFER[3226]	//(internal1_m1347_tx) tx - внутренний параметр
#define idinternal1_m1347_tx	 1085	//(internal1_m1347_tx) tx - внутренний параметр
#define internal1_m1560_tx	 BUFFER[3231]	//(internal1_m1560_tx) tx - внутренний параметр
#define idinternal1_m1560_tx	 1086	//(internal1_m1560_tx) tx - внутренний параметр
#define internal1_m1573_tx	 BUFFER[3236]	//(internal1_m1573_tx) tx - внутренний параметр
#define idinternal1_m1573_tx	 1087	//(internal1_m1573_tx) tx - внутренний параметр
#define internal1_m1572_tx	 BUFFER[3241]	//(internal1_m1572_tx) tx - внутренний параметр
#define idinternal1_m1572_tx	 1088	//(internal1_m1572_tx) tx - внутренний параметр
#define internal1_m1571_tx	 BUFFER[3246]	//(internal1_m1571_tx) tx - внутренний параметр
#define idinternal1_m1571_tx	 1089	//(internal1_m1571_tx) tx - внутренний параметр
#define internal1_m1562_tx	 BUFFER[3251]	//(internal1_m1562_tx) tx - внутренний параметр
#define idinternal1_m1562_tx	 1090	//(internal1_m1562_tx) tx - внутренний параметр
#define internal1_m2300_tx	 BUFFER[3256]	//(internal1_m2300_tx) tx - внутренний параметр
#define idinternal1_m2300_tx	 1091	//(internal1_m2300_tx) tx - внутренний параметр
#define internal1_m2283_tx	 BUFFER[3261]	//(internal1_m2283_tx) tx - внутренний параметр
#define idinternal1_m2283_tx	 1092	//(internal1_m2283_tx) tx - внутренний параметр
#define internal1_m2260_tx	 BUFFER[3266]	//(internal1_m2260_tx) tx - внутренний параметр
#define idinternal1_m2260_tx	 1093	//(internal1_m2260_tx) tx - внутренний параметр
#define internal1_m1570_tx	 BUFFER[3271]	//(internal1_m1570_tx) tx - внутренний параметр
#define idinternal1_m1570_tx	 1094	//(internal1_m1570_tx) tx - внутренний параметр
#define internal1_m1550_tx	 BUFFER[3276]	//(internal1_m1550_tx) tx - внутренний параметр
#define idinternal1_m1550_tx	 1095	//(internal1_m1550_tx) tx - внутренний параметр
#define internal1_m1549_tx	 BUFFER[3281]	//(internal1_m1549_tx) tx - внутренний параметр
#define idinternal1_m1549_tx	 1096	//(internal1_m1549_tx) tx - внутренний параметр
#define internal1_m1547_tx	 BUFFER[3286]	//(internal1_m1547_tx) tx - внутренний параметр
#define idinternal1_m1547_tx	 1097	//(internal1_m1547_tx) tx - внутренний параметр
#define internal1_m1569_tx	 BUFFER[3291]	//(internal1_m1569_tx) tx - внутренний параметр
#define idinternal1_m1569_tx	 1098	//(internal1_m1569_tx) tx - внутренний параметр
#define internal1_m1535_tx	 BUFFER[3296]	//(internal1_m1535_tx) tx - внутренний параметр
#define idinternal1_m1535_tx	 1099	//(internal1_m1535_tx) tx - внутренний параметр
#define internal1_m1537_tx	 BUFFER[3301]	//(internal1_m1537_tx) tx - внутренний параметр
#define idinternal1_m1537_tx	 1100	//(internal1_m1537_tx) tx - внутренний параметр
#define internal1_m1534_tx	 BUFFER[3306]	//(internal1_m1534_tx) tx - внутренний параметр
#define idinternal1_m1534_tx	 1101	//(internal1_m1534_tx) tx - внутренний параметр
#define internal1_m1507_tx	 BUFFER[3311]	//(internal1_m1507_tx) tx - внутренний параметр
#define idinternal1_m1507_tx	 1102	//(internal1_m1507_tx) tx - внутренний параметр
#define internal1_m1506_tx	 BUFFER[3316]	//(internal1_m1506_tx) tx - внутренний параметр
#define idinternal1_m1506_tx	 1103	//(internal1_m1506_tx) tx - внутренний параметр
#define internal1_m1516_tx	 BUFFER[3321]	//(internal1_m1516_tx) tx - внутренний параметр
#define idinternal1_m1516_tx	 1104	//(internal1_m1516_tx) tx - внутренний параметр
#define internal1_m1519_tx	 BUFFER[3326]	//(internal1_m1519_tx) tx - внутренний параметр
#define idinternal1_m1519_tx	 1105	//(internal1_m1519_tx) tx - внутренний параметр
#define internal1_m986_tx	 BUFFER[3331]	//(internal1_m986_tx) tx - внутренний параметр
#define idinternal1_m986_tx	 1106	//(internal1_m986_tx) tx - внутренний параметр
#define internal1_m989_tx	 BUFFER[3336]	//(internal1_m989_tx) tx - внутренний параметр
#define idinternal1_m989_tx	 1107	//(internal1_m989_tx) tx - внутренний параметр
#define internal1_m2251_tx	 BUFFER[3341]	//(internal1_m2251_tx) tx - внутренний параметр
#define idinternal1_m2251_tx	 1108	//(internal1_m2251_tx) tx - внутренний параметр
#define internal1_m979_tx	 BUFFER[3346]	//(internal1_m979_tx) tx - внутренний параметр
#define idinternal1_m979_tx	 1109	//(internal1_m979_tx) tx - внутренний параметр
#define internal1_m977_tx	 BUFFER[3351]	//(internal1_m977_tx) tx - внутренний параметр
#define idinternal1_m977_tx	 1110	//(internal1_m977_tx) tx - внутренний параметр
#define internal1_m985_tx	 BUFFER[3356]	//(internal1_m985_tx) tx - внутренний параметр
#define idinternal1_m985_tx	 1111	//(internal1_m985_tx) tx - внутренний параметр
#define internal1_m969_tx	 BUFFER[3361]	//(internal1_m969_tx) tx - внутренний параметр
#define idinternal1_m969_tx	 1112	//(internal1_m969_tx) tx - внутренний параметр
#define internal1_m967_tx	 BUFFER[3366]	//(internal1_m967_tx) tx - внутренний параметр
#define idinternal1_m967_tx	 1113	//(internal1_m967_tx) tx - внутренний параметр
#define internal1_m963_tx	 BUFFER[3371]	//(internal1_m963_tx) tx - внутренний параметр
#define idinternal1_m963_tx	 1114	//(internal1_m963_tx) tx - внутренний параметр
#define internal1_m984_tx	 BUFFER[3376]	//(internal1_m984_tx) tx - внутренний параметр
#define idinternal1_m984_tx	 1115	//(internal1_m984_tx) tx - внутренний параметр
#define internal1_m949_tx	 BUFFER[3381]	//(internal1_m949_tx) tx - внутренний параметр
#define idinternal1_m949_tx	 1116	//(internal1_m949_tx) tx - внутренний параметр
#define internal1_m950_tx	 BUFFER[3386]	//(internal1_m950_tx) tx - внутренний параметр
#define idinternal1_m950_tx	 1117	//(internal1_m950_tx) tx - внутренний параметр
#define internal1_m952_tx	 BUFFER[3391]	//(internal1_m952_tx) tx - внутренний параметр
#define idinternal1_m952_tx	 1118	//(internal1_m952_tx) tx - внутренний параметр
#define internal1_m637_tx	 BUFFER[3396]	//(internal1_m637_tx) tx - внутренний параметр
#define idinternal1_m637_tx	 1119	//(internal1_m637_tx) tx - внутренний параметр
#define internal1_m640_tx	 BUFFER[3401]	//(internal1_m640_tx) tx - внутренний параметр
#define idinternal1_m640_tx	 1120	//(internal1_m640_tx) tx - внутренний параметр
#define internal1_m639_tx	 BUFFER[3406]	//(internal1_m639_tx) tx - внутренний параметр
#define idinternal1_m639_tx	 1121	//(internal1_m639_tx) tx - внутренний параметр
#define internal1_m628_tx	 BUFFER[3411]	//(internal1_m628_tx) tx - внутренний параметр
#define idinternal1_m628_tx	 1122	//(internal1_m628_tx) tx - внутренний параметр
#define internal1_m626_tx	 BUFFER[3416]	//(internal1_m626_tx) tx - внутренний параметр
#define idinternal1_m626_tx	 1123	//(internal1_m626_tx) tx - внутренний параметр
#define internal1_m622_tx	 BUFFER[3421]	//(internal1_m622_tx) tx - внутренний параметр
#define idinternal1_m622_tx	 1124	//(internal1_m622_tx) tx - внутренний параметр
#define internal1_m635_tx	 BUFFER[3426]	//(internal1_m635_tx) tx - внутренний параметр
#define idinternal1_m635_tx	 1125	//(internal1_m635_tx) tx - внутренний параметр
#define internal1_m612_tx	 BUFFER[3431]	//(internal1_m612_tx) tx - внутренний параметр
#define idinternal1_m612_tx	 1126	//(internal1_m612_tx) tx - внутренний параметр
#define internal1_m611_tx	 BUFFER[3436]	//(internal1_m611_tx) tx - внутренний параметр
#define idinternal1_m611_tx	 1127	//(internal1_m611_tx) tx - внутренний параметр
#define internal1_m607_tx	 BUFFER[3441]	//(internal1_m607_tx) tx - внутренний параметр
#define idinternal1_m607_tx	 1128	//(internal1_m607_tx) tx - внутренний параметр
#define internal1_m638_tx	 BUFFER[3446]	//(internal1_m638_tx) tx - внутренний параметр
#define idinternal1_m638_tx	 1129	//(internal1_m638_tx) tx - внутренний параметр
#define internal1_m595_tx	 BUFFER[3451]	//(internal1_m595_tx) tx - внутренний параметр
#define idinternal1_m595_tx	 1130	//(internal1_m595_tx) tx - внутренний параметр
#define internal1_m594_tx	 BUFFER[3456]	//(internal1_m594_tx) tx - внутренний параметр
#define idinternal1_m594_tx	 1131	//(internal1_m594_tx) tx - внутренний параметр
#define internal1_m597_tx	 BUFFER[3461]	//(internal1_m597_tx) tx - внутренний параметр
#define idinternal1_m597_tx	 1132	//(internal1_m597_tx) tx - внутренний параметр
#define internal1_m574_tx	 BUFFER[3466]	//(internal1_m574_tx) tx - внутренний параметр
#define idinternal1_m574_tx	 1133	//(internal1_m574_tx) tx - внутренний параметр
#define internal1_m575_tx	 BUFFER[3471]	//(internal1_m575_tx) tx - внутренний параметр
#define idinternal1_m575_tx	 1134	//(internal1_m575_tx) tx - внутренний параметр
#define internal1_m576_tx	 BUFFER[3476]	//(internal1_m576_tx) tx - внутренний параметр
#define idinternal1_m576_tx	 1135	//(internal1_m576_tx) tx - внутренний параметр
#define internal1_m581_tx	 BUFFER[3481]	//(internal1_m581_tx) tx - внутренний параметр
#define idinternal1_m581_tx	 1136	//(internal1_m581_tx) tx - внутренний параметр
#define internal1_m2313_tx	 BUFFER[3486]	//(internal1_m2313_tx) tx - внутренний параметр
#define idinternal1_m2313_tx	 1137	//(internal1_m2313_tx) tx - внутренний параметр
#define internal1_m2314_tx	 BUFFER[3491]	//(internal1_m2314_tx) tx - внутренний параметр
#define idinternal1_m2314_tx	 1138	//(internal1_m2314_tx) tx - внутренний параметр
#define internal1_m2315_tx	 BUFFER[3496]	//(internal1_m2315_tx) tx - внутренний параметр
#define idinternal1_m2315_tx	 1139	//(internal1_m2315_tx) tx - внутренний параметр
#define internal1_m1792_tx	 BUFFER[3501]	//(internal1_m1792_tx) tx - внутренний параметр
#define idinternal1_m1792_tx	 1140	//(internal1_m1792_tx) tx - внутренний параметр
#define internal1_m1791_tx	 BUFFER[3506]	//(internal1_m1791_tx) tx - внутренний параметр
#define idinternal1_m1791_tx	 1141	//(internal1_m1791_tx) tx - внутренний параметр
#define internal1_m1786_tx	 BUFFER[3511]	//(internal1_m1786_tx) tx - внутренний параметр
#define idinternal1_m1786_tx	 1142	//(internal1_m1786_tx) tx - внутренний параметр
#define internal1_m1777_tx	 BUFFER[3516]	//(internal1_m1777_tx) tx - внутренний параметр
#define idinternal1_m1777_tx	 1143	//(internal1_m1777_tx) tx - внутренний параметр
#define internal1_m1775_tx	 BUFFER[3521]	//(internal1_m1775_tx) tx - внутренний параметр
#define idinternal1_m1775_tx	 1144	//(internal1_m1775_tx) tx - внутренний параметр
#define internal1_m1773_tx	 BUFFER[3526]	//(internal1_m1773_tx) tx - внутренний параметр
#define idinternal1_m1773_tx	 1145	//(internal1_m1773_tx) tx - внутренний параметр
#define internal1_m1772_tx	 BUFFER[3531]	//(internal1_m1772_tx) tx - внутренний параметр
#define idinternal1_m1772_tx	 1146	//(internal1_m1772_tx) tx - внутренний параметр
#define internal1_m1813_tx	 BUFFER[3536]	//(internal1_m1813_tx) tx - внутренний параметр
#define idinternal1_m1813_tx	 1147	//(internal1_m1813_tx) tx - внутренний параметр
#define internal1_m1821_tx	 BUFFER[3541]	//(internal1_m1821_tx) tx - внутренний параметр
#define idinternal1_m1821_tx	 1148	//(internal1_m1821_tx) tx - внутренний параметр
#define internal1_m1828_tx	 BUFFER[3546]	//(internal1_m1828_tx) tx - внутренний параметр
#define idinternal1_m1828_tx	 1149	//(internal1_m1828_tx) tx - внутренний параметр
#define internal1_m1829_tx	 BUFFER[3551]	//(internal1_m1829_tx) tx - внутренний параметр
#define idinternal1_m1829_tx	 1150	//(internal1_m1829_tx) tx - внутренний параметр
#define internal1_m1819_tx	 BUFFER[3556]	//(internal1_m1819_tx) tx - внутренний параметр
#define idinternal1_m1819_tx	 1151	//(internal1_m1819_tx) tx - внутренний параметр
#define internal1_m1794_tx	 BUFFER[3561]	//(internal1_m1794_tx) tx - внутренний параметр
#define idinternal1_m1794_tx	 1152	//(internal1_m1794_tx) tx - внутренний параметр
#define internal1_m1808_tx	 BUFFER[3566]	//(internal1_m1808_tx) tx - внутренний параметр
#define idinternal1_m1808_tx	 1153	//(internal1_m1808_tx) tx - внутренний параметр
#define internal1_m457_tx	 BUFFER[3571]	//(internal1_m457_tx) tx - внутренний параметр
#define idinternal1_m457_tx	 1154	//(internal1_m457_tx) tx - внутренний параметр
#define internal1_m448_tx	 BUFFER[3576]	//(internal1_m448_tx) tx - внутренний параметр
#define idinternal1_m448_tx	 1155	//(internal1_m448_tx) tx - внутренний параметр
#define internal1_m449_tx	 BUFFER[3581]	//(internal1_m449_tx) tx - внутренний параметр
#define idinternal1_m449_tx	 1156	//(internal1_m449_tx) tx - внутренний параметр
#define internal1_m451_tx	 BUFFER[3586]	//(internal1_m451_tx) tx - внутренний параметр
#define idinternal1_m451_tx	 1157	//(internal1_m451_tx) tx - внутренний параметр
#define internal1_m465_tx	 BUFFER[3591]	//(internal1_m465_tx) tx - внутренний параметр
#define idinternal1_m465_tx	 1158	//(internal1_m465_tx) tx - внутренний параметр
#define internal1_m415_tx	 BUFFER[3596]	//(internal1_m415_tx) tx - внутренний параметр
#define idinternal1_m415_tx	 1159	//(internal1_m415_tx) tx - внутренний параметр
#define internal1_m412_tx	 BUFFER[3601]	//(internal1_m412_tx) tx - внутренний параметр
#define idinternal1_m412_tx	 1160	//(internal1_m412_tx) tx - внутренний параметр
#define internal1_m411_tx	 BUFFER[3606]	//(internal1_m411_tx) tx - внутренний параметр
#define idinternal1_m411_tx	 1161	//(internal1_m411_tx) tx - внутренний параметр
#define internal1_m410_tx	 BUFFER[3611]	//(internal1_m410_tx) tx - внутренний параметр
#define idinternal1_m410_tx	 1162	//(internal1_m410_tx) tx - внутренний параметр
#define internal1_m870_tx	 BUFFER[3616]	//(internal1_m870_tx) tx - внутренний параметр
#define idinternal1_m870_tx	 1163	//(internal1_m870_tx) tx - внутренний параметр
#define internal1_m866_tx	 BUFFER[3621]	//(internal1_m866_tx) tx - внутренний параметр
#define idinternal1_m866_tx	 1164	//(internal1_m866_tx) tx - внутренний параметр
#define internal1_m865_tx	 BUFFER[3626]	//(internal1_m865_tx) tx - внутренний параметр
#define idinternal1_m865_tx	 1165	//(internal1_m865_tx) tx - внутренний параметр
#define internal1_m864_tx	 BUFFER[3631]	//(internal1_m864_tx) tx - внутренний параметр
#define idinternal1_m864_tx	 1166	//(internal1_m864_tx) tx - внутренний параметр
#define internal1_m1330_tx	 BUFFER[3636]	//(internal1_m1330_tx) tx - внутренний параметр
#define idinternal1_m1330_tx	 1167	//(internal1_m1330_tx) tx - внутренний параметр
#define internal1_m1327_tx	 BUFFER[3641]	//(internal1_m1327_tx) tx - внутренний параметр
#define idinternal1_m1327_tx	 1168	//(internal1_m1327_tx) tx - внутренний параметр
#define internal1_m1326_tx	 BUFFER[3646]	//(internal1_m1326_tx) tx - внутренний параметр
#define idinternal1_m1326_tx	 1169	//(internal1_m1326_tx) tx - внутренний параметр
#define internal1_m1087_tx	 BUFFER[3651]	//(internal1_m1087_tx) tx - внутренний параметр
#define idinternal1_m1087_tx	 1170	//(internal1_m1087_tx) tx - внутренний параметр
#define internal1_m2272_tx	 BUFFER[3656]	//(internal1_m2272_tx) tx - внутренний параметр
#define idinternal1_m2272_tx	 1171	//(internal1_m2272_tx) tx - внутренний параметр
#define internal1_m1098_tx	 BUFFER[3661]	//(internal1_m1098_tx) tx - внутренний параметр
#define idinternal1_m1098_tx	 1172	//(internal1_m1098_tx) tx - внутренний параметр
#define internal1_m1100_tx	 BUFFER[3666]	//(internal1_m1100_tx) tx - внутренний параметр
#define idinternal1_m1100_tx	 1173	//(internal1_m1100_tx) tx - внутренний параметр
#define internal1_m1099_tx	 BUFFER[3671]	//(internal1_m1099_tx) tx - внутренний параметр
#define idinternal1_m1099_tx	 1174	//(internal1_m1099_tx) tx - внутренний параметр
#define internal1_m2266_tx	 BUFFER[3676]	//(internal1_m2266_tx) tx - внутренний параметр
#define idinternal1_m2266_tx	 1175	//(internal1_m2266_tx) tx - внутренний параметр
#define internal1_m1089_tx	 BUFFER[3681]	//(internal1_m1089_tx) tx - внутренний параметр
#define idinternal1_m1089_tx	 1176	//(internal1_m1089_tx) tx - внутренний параметр
#define internal1_m2271_tx	 BUFFER[3686]	//(internal1_m2271_tx) tx - внутренний параметр
#define idinternal1_m2271_tx	 1177	//(internal1_m2271_tx) tx - внутренний параметр
#define internal1_m1097_tx	 BUFFER[3691]	//(internal1_m1097_tx) tx - внутренний параметр
#define idinternal1_m1097_tx	 1178	//(internal1_m1097_tx) tx - внутренний параметр
#define internal1_m1079_tx	 BUFFER[3696]	//(internal1_m1079_tx) tx - внутренний параметр
#define idinternal1_m1079_tx	 1179	//(internal1_m1079_tx) tx - внутренний параметр
#define internal1_m1078_tx	 BUFFER[3701]	//(internal1_m1078_tx) tx - внутренний параметр
#define idinternal1_m1078_tx	 1180	//(internal1_m1078_tx) tx - внутренний параметр
#define internal1_m1074_tx	 BUFFER[3706]	//(internal1_m1074_tx) tx - внутренний параметр
#define idinternal1_m1074_tx	 1181	//(internal1_m1074_tx) tx - внутренний параметр
#define internal1_m1096_tx	 BUFFER[3711]	//(internal1_m1096_tx) tx - внутренний параметр
#define idinternal1_m1096_tx	 1182	//(internal1_m1096_tx) tx - внутренний параметр
#define internal1_m1064_tx	 BUFFER[3716]	//(internal1_m1064_tx) tx - внутренний параметр
#define idinternal1_m1064_tx	 1183	//(internal1_m1064_tx) tx - внутренний параметр
#define internal1_m1062_tx	 BUFFER[3721]	//(internal1_m1062_tx) tx - внутренний параметр
#define idinternal1_m1062_tx	 1184	//(internal1_m1062_tx) tx - внутренний параметр
#define internal1_m1061_tx	 BUFFER[3726]	//(internal1_m1061_tx) tx - внутренний параметр
#define idinternal1_m1061_tx	 1185	//(internal1_m1061_tx) tx - внутренний параметр
#define internal1_m1040_tx	 BUFFER[3731]	//(internal1_m1040_tx) tx - внутренний параметр
#define idinternal1_m1040_tx	 1186	//(internal1_m1040_tx) tx - внутренний параметр
#define internal1_m1039_tx	 BUFFER[3736]	//(internal1_m1039_tx) tx - внутренний параметр
#define idinternal1_m1039_tx	 1187	//(internal1_m1039_tx) tx - внутренний параметр
#define internal1_m1029_tx	 BUFFER[3741]	//(internal1_m1029_tx) tx - внутренний параметр
#define idinternal1_m1029_tx	 1188	//(internal1_m1029_tx) tx - внутренний параметр
#define internal1_m1046_tx	 BUFFER[3746]	//(internal1_m1046_tx) tx - внутренний параметр
#define idinternal1_m1046_tx	 1189	//(internal1_m1046_tx) tx - внутренний параметр
#define internal1_m1465_tx	 BUFFER[3751]	//(internal1_m1465_tx) tx - внутренний параметр
#define idinternal1_m1465_tx	 1190	//(internal1_m1465_tx) tx - внутренний параметр
#define internal1_m1464_tx	 BUFFER[3756]	//(internal1_m1464_tx) tx - внутренний параметр
#define idinternal1_m1464_tx	 1191	//(internal1_m1464_tx) tx - внутренний параметр
#define internal1_m2218_tx	 BUFFER[3761]	//(internal1_m2218_tx) tx - внутренний параметр
#define idinternal1_m2218_tx	 1192	//(internal1_m2218_tx) tx - внутренний параметр
#define internal1_m1455_tx	 BUFFER[3766]	//(internal1_m1455_tx) tx - внутренний параметр
#define idinternal1_m1455_tx	 1193	//(internal1_m1455_tx) tx - внутренний параметр
#define internal1_m1456_tx	 BUFFER[3771]	//(internal1_m1456_tx) tx - внутренний параметр
#define idinternal1_m1456_tx	 1194	//(internal1_m1456_tx) tx - внутренний параметр
#define internal1_m1463_tx	 BUFFER[3776]	//(internal1_m1463_tx) tx - внутренний параметр
#define idinternal1_m1463_tx	 1195	//(internal1_m1463_tx) tx - внутренний параметр
#define internal1_m1446_tx	 BUFFER[3781]	//(internal1_m1446_tx) tx - внутренний параметр
#define idinternal1_m1446_tx	 1196	//(internal1_m1446_tx) tx - внутренний параметр
#define internal1_m1445_tx	 BUFFER[3786]	//(internal1_m1445_tx) tx - внутренний параметр
#define idinternal1_m1445_tx	 1197	//(internal1_m1445_tx) tx - внутренний параметр
#define internal1_m1441_tx	 BUFFER[3791]	//(internal1_m1441_tx) tx - внутренний параметр
#define idinternal1_m1441_tx	 1198	//(internal1_m1441_tx) tx - внутренний параметр
#define internal1_m1462_tx	 BUFFER[3796]	//(internal1_m1462_tx) tx - внутренний параметр
#define idinternal1_m1462_tx	 1199	//(internal1_m1462_tx) tx - внутренний параметр
#define internal1_m1428_tx	 BUFFER[3801]	//(internal1_m1428_tx) tx - внутренний параметр
#define idinternal1_m1428_tx	 1200	//(internal1_m1428_tx) tx - внутренний параметр
#define internal1_m1426_tx	 BUFFER[3806]	//(internal1_m1426_tx) tx - внутренний параметр
#define idinternal1_m1426_tx	 1201	//(internal1_m1426_tx) tx - внутренний параметр
#define internal1_m1435_tx	 BUFFER[3811]	//(internal1_m1435_tx) tx - внутренний параметр
#define idinternal1_m1435_tx	 1202	//(internal1_m1435_tx) tx - внутренний параметр
#define internal1_m255_tx	 BUFFER[3816]	//(internal1_m255_tx) tx - внутренний параметр
#define idinternal1_m255_tx	 1203	//(internal1_m255_tx) tx - внутренний параметр
#define internal1_m270_tx	 BUFFER[3821]	//(internal1_m270_tx) tx - внутренний параметр
#define idinternal1_m270_tx	 1204	//(internal1_m270_tx) tx - внутренний параметр
#define internal1_m278_tx	 BUFFER[3826]	//(internal1_m278_tx) tx - внутренний параметр
#define idinternal1_m278_tx	 1205	//(internal1_m278_tx) tx - внутренний параметр
#define internal1_m277_tx	 BUFFER[3831]	//(internal1_m277_tx) tx - внутренний параметр
#define idinternal1_m277_tx	 1206	//(internal1_m277_tx) tx - внутренний параметр
#define internal1_m261_tx	 BUFFER[3836]	//(internal1_m261_tx) tx - внутренний параметр
#define idinternal1_m261_tx	 1207	//(internal1_m261_tx) tx - внутренний параметр
#define internal1_m258_tx	 BUFFER[3841]	//(internal1_m258_tx) tx - внутренний параметр
#define idinternal1_m258_tx	 1208	//(internal1_m258_tx) tx - внутренний параметр
#define internal1_m274_tx	 BUFFER[3846]	//(internal1_m274_tx) tx - внутренний параметр
#define idinternal1_m274_tx	 1209	//(internal1_m274_tx) tx - внутренний параметр
#define internal1_m246_tx	 BUFFER[3851]	//(internal1_m246_tx) tx - внутренний параметр
#define idinternal1_m246_tx	 1210	//(internal1_m246_tx) tx - внутренний параметр
#define internal1_m245_tx	 BUFFER[3856]	//(internal1_m245_tx) tx - внутренний параметр
#define idinternal1_m245_tx	 1211	//(internal1_m245_tx) tx - внутренний параметр
#define internal1_m241_tx	 BUFFER[3861]	//(internal1_m241_tx) tx - внутренний параметр
#define idinternal1_m241_tx	 1212	//(internal1_m241_tx) tx - внутренний параметр
#define internal1_m273_tx	 BUFFER[3866]	//(internal1_m273_tx) tx - внутренний параметр
#define idinternal1_m273_tx	 1213	//(internal1_m273_tx) tx - внутренний параметр
#define internal1_m230_tx	 BUFFER[3871]	//(internal1_m230_tx) tx - внутренний параметр
#define idinternal1_m230_tx	 1214	//(internal1_m230_tx) tx - внутренний параметр
#define internal1_m232_tx	 BUFFER[3876]	//(internal1_m232_tx) tx - внутренний параметр
#define idinternal1_m232_tx	 1215	//(internal1_m232_tx) tx - внутренний параметр
#define internal1_m228_tx	 BUFFER[3881]	//(internal1_m228_tx) tx - внутренний параметр
#define idinternal1_m228_tx	 1216	//(internal1_m228_tx) tx - внутренний параметр
#define internal1_m204_tx	 BUFFER[3886]	//(internal1_m204_tx) tx - внутренний параметр
#define idinternal1_m204_tx	 1217	//(internal1_m204_tx) tx - внутренний параметр
#define internal1_m203_tx	 BUFFER[3891]	//(internal1_m203_tx) tx - внутренний параметр
#define idinternal1_m203_tx	 1218	//(internal1_m203_tx) tx - внутренний параметр
#define internal1_m202_tx	 BUFFER[3896]	//(internal1_m202_tx) tx - внутренний параметр
#define idinternal1_m202_tx	 1219	//(internal1_m202_tx) tx - внутренний параметр
#define internal1_m210_tx	 BUFFER[3901]	//(internal1_m210_tx) tx - внутренний параметр
#define idinternal1_m210_tx	 1220	//(internal1_m210_tx) tx - внутренний параметр
#define internal1_m1408_tx	 BUFFER[3906]	//(internal1_m1408_tx) tx - внутренний параметр
#define idinternal1_m1408_tx	 1221	//(internal1_m1408_tx) tx - внутренний параметр
#define internal1_m1390_tx	 BUFFER[3911]	//(internal1_m1390_tx) tx - внутренний параметр
#define idinternal1_m1390_tx	 1222	//(internal1_m1390_tx) tx - внутренний параметр
#define internal1_m1393_tx	 BUFFER[3916]	//(internal1_m1393_tx) tx - внутренний параметр
#define idinternal1_m1393_tx	 1223	//(internal1_m1393_tx) tx - внутренний параметр
#define internal1_m1412_tx	 BUFFER[3921]	//(internal1_m1412_tx) tx - внутренний параметр
#define idinternal1_m1412_tx	 1224	//(internal1_m1412_tx) tx - внутренний параметр
#define internal1_m929_tx	 BUFFER[3926]	//(internal1_m929_tx) tx - внутренний параметр
#define idinternal1_m929_tx	 1225	//(internal1_m929_tx) tx - внутренний параметр
#define internal1_m934_tx	 BUFFER[3931]	//(internal1_m934_tx) tx - внутренний параметр
#define idinternal1_m934_tx	 1226	//(internal1_m934_tx) tx - внутренний параметр
#define internal1_m924_tx	 BUFFER[3936]	//(internal1_m924_tx) tx - внутренний параметр
#define idinternal1_m924_tx	 1227	//(internal1_m924_tx) tx - внутренний параметр
#define internal1_m925_tx	 BUFFER[3941]	//(internal1_m925_tx) tx - внутренний параметр
#define idinternal1_m925_tx	 1228	//(internal1_m925_tx) tx - внутренний параметр
#define internal1_m1913_q0	 BUFFER[3946]	//(internal1_m1913_q0) q0 - внутренний параметр
#define idinternal1_m1913_q0	 1229	//(internal1_m1913_q0) q0 - внутренний параметр
#define internal1_m2355_q0	 BUFFER[3948]	//(internal1_m2355_q0) q0 - внутренний параметр
#define idinternal1_m2355_q0	 1230	//(internal1_m2355_q0) q0 - внутренний параметр
#define internal1_m2339_q0	 BUFFER[3950]	//(internal1_m2339_q0) q0 - внутренний параметр
#define idinternal1_m2339_q0	 1231	//(internal1_m2339_q0) q0 - внутренний параметр
#define internal1_m2386_q0	 BUFFER[3952]	//(internal1_m2386_q0) q0 - внутренний параметр
#define idinternal1_m2386_q0	 1232	//(internal1_m2386_q0) q0 - внутренний параметр
#define internal1_m2370_q0	 BUFFER[3954]	//(internal1_m2370_q0) q0 - внутренний параметр
#define idinternal1_m2370_q0	 1233	//(internal1_m2370_q0) q0 - внутренний параметр
#define internal1_m2361_q0	 BUFFER[3956]	//(internal1_m2361_q0) q0 - внутренний параметр
#define idinternal1_m2361_q0	 1234	//(internal1_m2361_q0) q0 - внутренний параметр
#define internal1_m2342_q0	 BUFFER[3958]	//(internal1_m2342_q0) q0 - внутренний параметр
#define idinternal1_m2342_q0	 1235	//(internal1_m2342_q0) q0 - внутренний параметр
#define internal1_m2359_q0	 BUFFER[3960]	//(internal1_m2359_q0) q0 - внутренний параметр
#define idinternal1_m2359_q0	 1236	//(internal1_m2359_q0) q0 - внутренний параметр
#define internal1_m2340_q0	 BUFFER[3962]	//(internal1_m2340_q0) q0 - внутренний параметр
#define idinternal1_m2340_q0	 1237	//(internal1_m2340_q0) q0 - внутренний параметр
#define internal1_m2338_q0	 BUFFER[3964]	//(internal1_m2338_q0) q0 - внутренний параметр
#define idinternal1_m2338_q0	 1238	//(internal1_m2338_q0) q0 - внутренний параметр
#define internal1_m2337_q0	 BUFFER[3966]	//(internal1_m2337_q0) q0 - внутренний параметр
#define idinternal1_m2337_q0	 1239	//(internal1_m2337_q0) q0 - внутренний параметр
#define internal1_m2351_q0	 BUFFER[3968]	//(internal1_m2351_q0) q0 - внутренний параметр
#define idinternal1_m2351_q0	 1240	//(internal1_m2351_q0) q0 - внутренний параметр
#define internal1_m2349_q0	 BUFFER[3970]	//(internal1_m2349_q0) q0 - внутренний параметр
#define idinternal1_m2349_q0	 1241	//(internal1_m2349_q0) q0 - внутренний параметр
#define internal1_m2357_q0	 BUFFER[3972]	//(internal1_m2357_q0) q0 - внутренний параметр
#define idinternal1_m2357_q0	 1242	//(internal1_m2357_q0) q0 - внутренний параметр
#define internal1_m2353_q0	 BUFFER[3974]	//(internal1_m2353_q0) q0 - внутренний параметр
#define idinternal1_m2353_q0	 1243	//(internal1_m2353_q0) q0 - внутренний параметр
#define internal1_m2392_q0	 BUFFER[3976]	//(internal1_m2392_q0) q0 - внутренний параметр
#define idinternal1_m2392_q0	 1244	//(internal1_m2392_q0) q0 - внутренний параметр
#define internal1_m2373_q0	 BUFFER[3978]	//(internal1_m2373_q0) q0 - внутренний параметр
#define idinternal1_m2373_q0	 1245	//(internal1_m2373_q0) q0 - внутренний параметр
#define internal1_m2390_q0	 BUFFER[3980]	//(internal1_m2390_q0) q0 - внутренний параметр
#define idinternal1_m2390_q0	 1246	//(internal1_m2390_q0) q0 - внутренний параметр
#define internal1_m2372_q0	 BUFFER[3982]	//(internal1_m2372_q0) q0 - внутренний параметр
#define idinternal1_m2372_q0	 1247	//(internal1_m2372_q0) q0 - внутренний параметр
#define internal1_m2369_q0	 BUFFER[3984]	//(internal1_m2369_q0) q0 - внутренний параметр
#define idinternal1_m2369_q0	 1248	//(internal1_m2369_q0) q0 - внутренний параметр
#define internal1_m2368_q0	 BUFFER[3986]	//(internal1_m2368_q0) q0 - внутренний параметр
#define idinternal1_m2368_q0	 1249	//(internal1_m2368_q0) q0 - внутренний параметр
#define internal1_m2382_q0	 BUFFER[3988]	//(internal1_m2382_q0) q0 - внутренний параметр
#define idinternal1_m2382_q0	 1250	//(internal1_m2382_q0) q0 - внутренний параметр
#define internal1_m2380_q0	 BUFFER[3990]	//(internal1_m2380_q0) q0 - внутренний параметр
#define idinternal1_m2380_q0	 1251	//(internal1_m2380_q0) q0 - внутренний параметр
#define internal1_m2243_tx	 BUFFER[3992]	//(internal1_m2243_tx) tx - внутренний параметр
#define idinternal1_m2243_tx	 1252	//(internal1_m2243_tx) tx - внутренний параметр
#define internal1_m2222_tx	 BUFFER[3997]	//(internal1_m2222_tx) tx - внутренний параметр
#define idinternal1_m2222_tx	 1253	//(internal1_m2222_tx) tx - внутренний параметр
#define internal1_m1937_Pv0	 BUFFER[4002]	//(internal1_m1937_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1937_Pv0	 1254	//(internal1_m1937_Pv0)  - Пер. выключатель механизма
#define internal1_m1937_Zv0	 BUFFER[4004]	//(internal1_m1937_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1937_Zv0	 1255	//(internal1_m1937_Zv0)  - Зад. выключатель механизма
#define internal1_m1937_MyFirstEnterFlag	 BUFFER[4006]	//(internal1_m1937_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1937_MyFirstEnterFlag	 1256	//(internal1_m1937_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m1934_Pv0	 BUFFER[4008]	//(internal1_m1934_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1934_Pv0	 1257	//(internal1_m1934_Pv0)  - Пер. выключатель механизма
#define internal1_m1934_Zv0	 BUFFER[4010]	//(internal1_m1934_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1934_Zv0	 1258	//(internal1_m1934_Zv0)  - Зад. выключатель механизма
#define internal1_m1934_MyFirstEnterFlag	 BUFFER[4012]	//(internal1_m1934_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1934_MyFirstEnterFlag	 1259	//(internal1_m1934_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m2410_tx	 BUFFER[4014]	//(internal1_m2410_tx) tx - время накопленное сек
#define idinternal1_m2410_tx	 1260	//(internal1_m2410_tx) tx - время накопленное сек
#define internal1_m2410_y0	 BUFFER[4019]	//(internal1_m2410_y0) y0
#define idinternal1_m2410_y0	 1261	//(internal1_m2410_y0) y0
#define internal1_m2414_tx	 BUFFER[4020]	//(internal1_m2414_tx) tx - время накопленное сек
#define idinternal1_m2414_tx	 1262	//(internal1_m2414_tx) tx - время накопленное сек
#define internal1_m2414_y0	 BUFFER[4025]	//(internal1_m2414_y0) y0
#define idinternal1_m2414_y0	 1263	//(internal1_m2414_y0) y0
#define internal1_m2413_tx	 BUFFER[4026]	//(internal1_m2413_tx) tx - время накопленное сек
#define idinternal1_m2413_tx	 1264	//(internal1_m2413_tx) tx - время накопленное сек
#define internal1_m2413_y0	 BUFFER[4031]	//(internal1_m2413_y0) y0
#define idinternal1_m2413_y0	 1265	//(internal1_m2413_y0) y0
#define internal1_m2450_tx	 BUFFER[4032]	//(internal1_m2450_tx) tx - внутренний параметр
#define idinternal1_m2450_tx	 1266	//(internal1_m2450_tx) tx - внутренний параметр
#define internal1_m2448_tx	 BUFFER[4037]	//(internal1_m2448_tx) tx - время накопленное сек
#define idinternal1_m2448_tx	 1267	//(internal1_m2448_tx) tx - время накопленное сек
#define internal1_m2448_y0	 BUFFER[4042]	//(internal1_m2448_y0) y0
#define idinternal1_m2448_y0	 1268	//(internal1_m2448_y0) y0
#define internal1_m2453_q0	 BUFFER[4043]	//(internal1_m2453_q0) q0 - внутренний параметр
#define idinternal1_m2453_q0	 1269	//(internal1_m2453_q0) q0 - внутренний параметр
#define internal1_m2420_q0	 BUFFER[4045]	//(internal1_m2420_q0) q0 - внутренний параметр
#define idinternal1_m2420_q0	 1270	//(internal1_m2420_q0) q0 - внутренний параметр
#define internal1_m2428_tx	 BUFFER[4047]	//(internal1_m2428_tx) tx - внутренний параметр
#define idinternal1_m2428_tx	 1271	//(internal1_m2428_tx) tx - внутренний параметр
#define internal1_m2426_q0	 BUFFER[4052]	//(internal1_m2426_q0) q0 - внутренний параметр
#define idinternal1_m2426_q0	 1272	//(internal1_m2426_q0) q0 - внутренний параметр
#define internal1_m2408_fVf0	 BUFFER[4054]	//(internal1_m2408_fVf0)  - скорость изменения мощности 
#define idinternal1_m2408_fVf0	 1273	//(internal1_m2408_fVf0)  - скорость изменения мощности 
#define internal1_m2408_fRsg	 BUFFER[4059]	//(internal1_m2408_fRsg)  - рассогласование между текущей и заданной мощностью 
#define idinternal1_m2408_fRsg	 1274	//(internal1_m2408_fRsg)  - рассогласование между текущей и заданной мощностью 
#define internal1_m2408_fRct	 BUFFER[4064]	//(internal1_m2408_fRct)  - стартовая реактивность регулятора 
#define idinternal1_m2408_fRct	 1275	//(internal1_m2408_fRct)  - стартовая реактивность регулятора 
#define internal1_m2408_fVfMin	 BUFFER[4069]	//(internal1_m2408_fVfMin)  - минимальная скорость 
#define idinternal1_m2408_fVfMin	 1276	//(internal1_m2408_fVfMin)  - минимальная скорость 
#define internal1_m2408_fStw0	 BUFFER[4074]	//(internal1_m2408_fStw0)  - значение стартовой мощности включения ИМ 
#define idinternal1_m2408_fStw0	 1277	//(internal1_m2408_fStw0)  - значение стартовой мощности включения ИМ 
#define internal1_m2408_fMaxDk	 BUFFER[4079]	//(internal1_m2408_fMaxDk)  - изменение координаты при смене задания 
#define idinternal1_m2408_fMaxDk	 1278	//(internal1_m2408_fMaxDk)  - изменение координаты при смене задания 
#define internal1_m2408_fkizm	 BUFFER[4084]	//(internal1_m2408_fkizm)  - стартовая координата положения ИМ 0-й реактивности 
#define idinternal1_m2408_fkizm	 1279	//(internal1_m2408_fkizm)  - стартовая координата положения ИМ 0-й реактивности 
#define internal1_m2408_fwt0	 BUFFER[4089]	//(internal1_m2408_fwt0)  - мощность на предыдущем шаге 
#define idinternal1_m2408_fwt0	 1280	//(internal1_m2408_fwt0)  - мощность на предыдущем шаге 
#define internal1_m2408_fwz0	 BUFFER[4094]	//(internal1_m2408_fwz0)  - заданная мощность на предыдущем шаге 
#define idinternal1_m2408_fwz0	 1281	//(internal1_m2408_fwz0)  - заданная мощность на предыдущем шаге 
#define internal1_m2408_ftf0	 BUFFER[4099]	//(internal1_m2408_ftf0)  - время от фиксации предыдущей мощности 
#define idinternal1_m2408_ftf0	 1282	//(internal1_m2408_ftf0)  - время от фиксации предыдущей мощности 
#define internal1_m2408_fTk0	 BUFFER[4104]	//(internal1_m2408_fTk0)  - последняя температура 
#define idinternal1_m2408_fTk0	 1283	//(internal1_m2408_fTk0)  - последняя температура 
#define internal1_m2408_FlPar	 BUFFER[4109]	//(internal1_m2408_FlPar) - стартовый этап регулирования
#define idinternal1_m2408_FlPar	 1284	//(internal1_m2408_FlPar) - стартовый этап регулирования
#define internal1_m2408_FlIzm	 BUFFER[4112]	//(internal1_m2408_FlIzm) - флаг изменения направления изменения мощности
#define idinternal1_m2408_FlIzm	 1285	//(internal1_m2408_FlIzm) - флаг изменения направления изменения мощности
#define internal1_m2408_FlCmp	 BUFFER[4115]	//(internal1_m2408_FlCmp) - текущее направление изменения мощности
#define idinternal1_m2408_FlCmp	 1286	//(internal1_m2408_FlCmp) - текущее направление изменения мощности
#define internal1_m2408_StabCoun	 BUFFER[4118]	//(internal1_m2408_StabCoun) - счётчик стабильности
#define idinternal1_m2408_StabCoun	 1287	//(internal1_m2408_StabCoun) - счётчик стабильности
#define internal1_m2408_ZerCoun	 BUFFER[4121]	//(internal1_m2408_ZerCoun) - счётчик полной остановки
#define idinternal1_m2408_ZerCoun	 1288	//(internal1_m2408_ZerCoun) - счётчик полной остановки
#define internal1_m2408_SrCoun	 BUFFER[4124]	//(internal1_m2408_SrCoun)  - счётчик усреднения
#define idinternal1_m2408_SrCoun	 1289	//(internal1_m2408_SrCoun)  - счётчик усреднения
#define internal1_m2408_LastStage	 BUFFER[4127]	//(internal1_m2408_LastStage)  - последний этап
#define idinternal1_m2408_LastStage	 1290	//(internal1_m2408_LastStage)  - последний этап
#define internal1_m2408_fef	 BUFFER[4130]	//(internal1_m2408_fef)  - первый вход
#define idinternal1_m2408_fef	 1291	//(internal1_m2408_fef)  - первый вход
#define internal1_m2237_tx	 BUFFER[4132]	//(internal1_m2237_tx) tx - время накопленное сек
#define idinternal1_m2237_tx	 1292	//(internal1_m2237_tx) tx - время накопленное сек
#define internal1_m2237_y0	 BUFFER[4137]	//(internal1_m2237_y0) y0
#define idinternal1_m2237_y0	 1293	//(internal1_m2237_y0) y0
#define internal1_m2229_tx	 BUFFER[4138]	//(internal1_m2229_tx) tx - время накопленное сек
#define idinternal1_m2229_tx	 1294	//(internal1_m2229_tx) tx - время накопленное сек
#define internal1_m2229_y0	 BUFFER[4143]	//(internal1_m2229_y0) y0
#define idinternal1_m2229_y0	 1295	//(internal1_m2229_y0) y0
#define internal1_m1923_q0	 BUFFER[4144]	//(internal1_m1923_q0) q0 - внутренний параметр
#define idinternal1_m1923_q0	 1296	//(internal1_m1923_q0) q0 - внутренний параметр
#define internal1_m1928_q0	 BUFFER[4146]	//(internal1_m1928_q0) q0 - внутренний параметр
#define idinternal1_m1928_q0	 1297	//(internal1_m1928_q0) q0 - внутренний параметр
#define internal1_m1920_q0	 BUFFER[4148]	//(internal1_m1920_q0) q0 - внутренний параметр
#define idinternal1_m1920_q0	 1298	//(internal1_m1920_q0) q0 - внутренний параметр
#define internal1_m1962_q0	 BUFFER[4150]	//(internal1_m1962_q0) q0 - внутренний параметр
#define idinternal1_m1962_q0	 1299	//(internal1_m1962_q0) q0 - внутренний параметр
#define internal1_m834_tx	 BUFFER[4152]	//(internal1_m834_tx) tx - время накопленное сек
#define idinternal1_m834_tx	 1300	//(internal1_m834_tx) tx - время накопленное сек
#define internal1_m834_y0	 BUFFER[4157]	//(internal1_m834_y0) y0
#define idinternal1_m834_y0	 1301	//(internal1_m834_y0) y0
#define internal1_m2233_tx	 BUFFER[4158]	//(internal1_m2233_tx) tx - внутренний параметр
#define idinternal1_m2233_tx	 1302	//(internal1_m2233_tx) tx - внутренний параметр
#define internal1_m2236_q0	 BUFFER[4163]	//(internal1_m2236_q0) q0 - внутренний параметр
#define idinternal1_m2236_q0	 1303	//(internal1_m2236_q0) q0 - внутренний параметр
#define internal1_m2228_q0	 BUFFER[4165]	//(internal1_m2228_q0) q0 - внутренний параметр
#define idinternal1_m2228_q0	 1304	//(internal1_m2228_q0) q0 - внутренний параметр
#define internal1_m2197_tx	 BUFFER[4167]	//(internal1_m2197_tx) tx - внутренний параметр
#define idinternal1_m2197_tx	 1305	//(internal1_m2197_tx) tx - внутренний параметр
#define internal1_m2208_tx	 BUFFER[4172]	//(internal1_m2208_tx) tx - внутренний параметр
#define idinternal1_m2208_tx	 1306	//(internal1_m2208_tx) tx - внутренний параметр
#define internal1_m2194_tx	 BUFFER[4177]	//(internal1_m2194_tx) tx - внутренний параметр
#define idinternal1_m2194_tx	 1307	//(internal1_m2194_tx) tx - внутренний параметр
#define internal1_m2200_q0	 BUFFER[4182]	//(internal1_m2200_q0) q0 - внутренний параметр
#define idinternal1_m2200_q0	 1308	//(internal1_m2200_q0) q0 - внутренний параметр
#define internal1_m2212_q0	 BUFFER[4184]	//(internal1_m2212_q0) q0 - внутренний параметр
#define idinternal1_m2212_q0	 1309	//(internal1_m2212_q0) q0 - внутренний параметр
#define internal1_m2169_tx	 BUFFER[4186]	//(internal1_m2169_tx) tx - внутренний параметр
#define idinternal1_m2169_tx	 1310	//(internal1_m2169_tx) tx - внутренний параметр
#define internal1_m52_tx	 BUFFER[4191]	//(internal1_m52_tx) tx - внутренний параметр
#define idinternal1_m52_tx	 1311	//(internal1_m52_tx) tx - внутренний параметр
#define internal1_m368_tx	 BUFFER[4196]	//(internal1_m368_tx) tx - внутренний параметр
#define idinternal1_m368_tx	 1312	//(internal1_m368_tx) tx - внутренний параметр
#define internal1_m322_tx	 BUFFER[4201]	//(internal1_m322_tx) tx - внутренний параметр
#define idinternal1_m322_tx	 1313	//(internal1_m322_tx) tx - внутренний параметр
#define internal1_m835_tx	 BUFFER[4206]	//(internal1_m835_tx) tx - внутренний параметр
#define idinternal1_m835_tx	 1314	//(internal1_m835_tx) tx - внутренний параметр
#define internal1_m1627_tx	 BUFFER[4211]	//(internal1_m1627_tx) tx - внутренний параметр
#define idinternal1_m1627_tx	 1315	//(internal1_m1627_tx) tx - внутренний параметр
#define internal1_m120_tx	 BUFFER[4216]	//(internal1_m120_tx) tx - внутренний параметр
#define idinternal1_m120_tx	 1316	//(internal1_m120_tx) tx - внутренний параметр
#define internal1_m122_tx	 BUFFER[4221]	//(internal1_m122_tx) tx - внутренний параметр
#define idinternal1_m122_tx	 1317	//(internal1_m122_tx) tx - внутренний параметр
#define internal1_m127_tx	 BUFFER[4226]	//(internal1_m127_tx) tx - внутренний параметр
#define idinternal1_m127_tx	 1318	//(internal1_m127_tx) tx - внутренний параметр
#define internal1_m21_tx	 BUFFER[4231]	//(internal1_m21_tx) tx - внутренний параметр
#define idinternal1_m21_tx	 1319	//(internal1_m21_tx) tx - внутренний параметр
#define internal1_m13_tx	 BUFFER[4236]	//(internal1_m13_tx) tx - внутренний параметр
#define idinternal1_m13_tx	 1320	//(internal1_m13_tx) tx - внутренний параметр
#define internal1_m2179_tx	 BUFFER[4241]	//(internal1_m2179_tx) tx - внутренний параметр
#define idinternal1_m2179_tx	 1321	//(internal1_m2179_tx) tx - внутренний параметр
#define internal1_m2166_tx	 BUFFER[4246]	//(internal1_m2166_tx) tx - внутренний параметр
#define idinternal1_m2166_tx	 1322	//(internal1_m2166_tx) tx - внутренний параметр
#define internal1_m2284_tx	 BUFFER[4251]	//(internal1_m2284_tx) tx - внутренний параметр
#define idinternal1_m2284_tx	 1323	//(internal1_m2284_tx) tx - внутренний параметр
#define internal1_m2286_tx	 BUFFER[4256]	//(internal1_m2286_tx) tx - внутренний параметр
#define idinternal1_m2286_tx	 1324	//(internal1_m2286_tx) tx - внутренний параметр
#define internal1_m82_tx	 BUFFER[4261]	//(internal1_m82_tx) tx - внутренний параметр
#define idinternal1_m82_tx	 1325	//(internal1_m82_tx) tx - внутренний параметр
#define internal1_m339_tx	 BUFFER[4266]	//(internal1_m339_tx) tx - время накопленное сек
#define idinternal1_m339_tx	 1326	//(internal1_m339_tx) tx - время накопленное сек
#define internal1_m339_y0	 BUFFER[4271]	//(internal1_m339_y0) y0
#define idinternal1_m339_y0	 1327	//(internal1_m339_y0) y0
#define internal1_m2077_tx	 BUFFER[4272]	//(internal1_m2077_tx) tx - время накопленное сек
#define idinternal1_m2077_tx	 1328	//(internal1_m2077_tx) tx - время накопленное сек
#define internal1_m2077_y0	 BUFFER[4277]	//(internal1_m2077_y0) y0
#define idinternal1_m2077_y0	 1329	//(internal1_m2077_y0) y0
#define internal1_m2091_q0	 BUFFER[4278]	//(internal1_m2091_q0) q0 - внутренний параметр
#define idinternal1_m2091_q0	 1330	//(internal1_m2091_q0) q0 - внутренний параметр
#define internal1_m1648_q0	 BUFFER[4283]	//(internal1_m1648_q0) q0 - внутренний параметр
#define idinternal1_m1648_q0	 1331	//(internal1_m1648_q0) q0 - внутренний параметр
#define internal1_m1686_q0	 BUFFER[4288]	//(internal1_m1686_q0) q0 - внутренний параметр
#define idinternal1_m1686_q0	 1332	//(internal1_m1686_q0) q0 - внутренний параметр
#define internal1_m1689_q0	 BUFFER[4293]	//(internal1_m1689_q0) q0 - внутренний параметр
#define idinternal1_m1689_q0	 1333	//(internal1_m1689_q0) q0 - внутренний параметр
#define internal1_m2131_q0	 BUFFER[4298]	//(internal1_m2131_q0) q0 - внутренний параметр
#define idinternal1_m2131_q0	 1334	//(internal1_m2131_q0) q0 - внутренний параметр
#define internal1_m2109_tx	 BUFFER[4303]	//(internal1_m2109_tx) tx - время накопленное сек
#define idinternal1_m2109_tx	 1335	//(internal1_m2109_tx) tx - время накопленное сек
#define internal1_m2109_y0	 BUFFER[4308]	//(internal1_m2109_y0) y0
#define idinternal1_m2109_y0	 1336	//(internal1_m2109_y0) y0
#define internal1_m2124_tx	 BUFFER[4309]	//(internal1_m2124_tx) tx - время накопленное сек
#define idinternal1_m2124_tx	 1337	//(internal1_m2124_tx) tx - время накопленное сек
#define internal1_m2124_y0	 BUFFER[4314]	//(internal1_m2124_y0) y0
#define idinternal1_m2124_y0	 1338	//(internal1_m2124_y0) y0
#define internal1_m2121_tx	 BUFFER[4315]	//(internal1_m2121_tx) tx - время накопленное сек
#define idinternal1_m2121_tx	 1339	//(internal1_m2121_tx) tx - время накопленное сек
#define internal1_m2121_y0	 BUFFER[4320]	//(internal1_m2121_y0) y0
#define idinternal1_m2121_y0	 1340	//(internal1_m2121_y0) y0
#define internal1_m2264_tx	 BUFFER[4321]	//(internal1_m2264_tx) tx - время накопленное сек
#define idinternal1_m2264_tx	 1341	//(internal1_m2264_tx) tx - время накопленное сек
#define internal1_m2264_y0	 BUFFER[4326]	//(internal1_m2264_y0) y0
#define idinternal1_m2264_y0	 1342	//(internal1_m2264_y0) y0
#define internal1_m2275_tx	 BUFFER[4327]	//(internal1_m2275_tx) tx - время накопленное сек
#define idinternal1_m2275_tx	 1343	//(internal1_m2275_tx) tx - время накопленное сек
#define internal1_m2275_y0	 BUFFER[4332]	//(internal1_m2275_y0) y0
#define idinternal1_m2275_y0	 1344	//(internal1_m2275_y0) y0
#define internal1_m2030_tx	 BUFFER[4333]	//(internal1_m2030_tx) tx - время накопленное сек
#define idinternal1_m2030_tx	 1345	//(internal1_m2030_tx) tx - время накопленное сек
#define internal1_m2030_y0	 BUFFER[4338]	//(internal1_m2030_y0) y0
#define idinternal1_m2030_y0	 1346	//(internal1_m2030_y0) y0
#define internal1_m2029_tx	 BUFFER[4339]	//(internal1_m2029_tx) tx - время накопленное сек
#define idinternal1_m2029_tx	 1347	//(internal1_m2029_tx) tx - время накопленное сек
#define internal1_m2029_y0	 BUFFER[4344]	//(internal1_m2029_y0) y0
#define idinternal1_m2029_y0	 1348	//(internal1_m2029_y0) y0
#define internal1_m2028_tx	 BUFFER[4345]	//(internal1_m2028_tx) tx - время накопленное сек
#define idinternal1_m2028_tx	 1349	//(internal1_m2028_tx) tx - время накопленное сек
#define internal1_m2028_y0	 BUFFER[4350]	//(internal1_m2028_y0) y0
#define idinternal1_m2028_y0	 1350	//(internal1_m2028_y0) y0
#define internal1_m2027_tx	 BUFFER[4351]	//(internal1_m2027_tx) tx - время накопленное сек
#define idinternal1_m2027_tx	 1351	//(internal1_m2027_tx) tx - время накопленное сек
#define internal1_m2027_y0	 BUFFER[4356]	//(internal1_m2027_y0) y0
#define idinternal1_m2027_y0	 1352	//(internal1_m2027_y0) y0
#define internal1_m1702_tx	 BUFFER[4357]	//(internal1_m1702_tx) tx - время накопленное сек
#define idinternal1_m1702_tx	 1353	//(internal1_m1702_tx) tx - время накопленное сек
#define internal1_m1702_y0	 BUFFER[4362]	//(internal1_m1702_y0) y0
#define idinternal1_m1702_y0	 1354	//(internal1_m1702_y0) y0
#define internal1_m1696_tx	 BUFFER[4363]	//(internal1_m1696_tx) tx - время накопленное сек
#define idinternal1_m1696_tx	 1355	//(internal1_m1696_tx) tx - время накопленное сек
#define internal1_m1696_y0	 BUFFER[4368]	//(internal1_m1696_y0) y0
#define idinternal1_m1696_y0	 1356	//(internal1_m1696_y0) y0
#define internal1_m1643_tx	 BUFFER[4369]	//(internal1_m1643_tx) tx - время накопленное сек
#define idinternal1_m1643_tx	 1357	//(internal1_m1643_tx) tx - время накопленное сек
#define internal1_m1643_y0	 BUFFER[4374]	//(internal1_m1643_y0) y0
#define idinternal1_m1643_y0	 1358	//(internal1_m1643_y0) y0
#define internal1_m922_tx	 BUFFER[4375]	//(internal1_m922_tx) tx - время накопленное сек
#define idinternal1_m922_tx	 1359	//(internal1_m922_tx) tx - время накопленное сек
#define internal1_m922_y0	 BUFFER[4380]	//(internal1_m922_y0) y0
#define idinternal1_m922_y0	 1360	//(internal1_m922_y0) y0
#define internal1_m921_tx	 BUFFER[4381]	//(internal1_m921_tx) tx - время накопленное сек
#define idinternal1_m921_tx	 1361	//(internal1_m921_tx) tx - время накопленное сек
#define internal1_m921_y0	 BUFFER[4386]	//(internal1_m921_y0) y0
#define idinternal1_m921_y0	 1362	//(internal1_m921_y0) y0
#define internal1_m939_tx	 BUFFER[4387]	//(internal1_m939_tx) tx - время накопленное сек
#define idinternal1_m939_tx	 1363	//(internal1_m939_tx) tx - время накопленное сек
#define internal1_m939_y0	 BUFFER[4392]	//(internal1_m939_y0) y0
#define idinternal1_m939_y0	 1364	//(internal1_m939_y0) y0
#define internal1_m194_tx	 BUFFER[4393]	//(internal1_m194_tx) tx - время накопленное сек
#define idinternal1_m194_tx	 1365	//(internal1_m194_tx) tx - время накопленное сек
#define internal1_m194_y0	 BUFFER[4398]	//(internal1_m194_y0) y0
#define idinternal1_m194_y0	 1366	//(internal1_m194_y0) y0
#define internal1_m193_tx	 BUFFER[4399]	//(internal1_m193_tx) tx - время накопленное сек
#define idinternal1_m193_tx	 1367	//(internal1_m193_tx) tx - время накопленное сек
#define internal1_m193_y0	 BUFFER[4404]	//(internal1_m193_y0) y0
#define idinternal1_m193_y0	 1368	//(internal1_m193_y0) y0
#define internal1_m215_tx	 BUFFER[4405]	//(internal1_m215_tx) tx - время накопленное сек
#define idinternal1_m215_tx	 1369	//(internal1_m215_tx) tx - время накопленное сек
#define internal1_m215_y0	 BUFFER[4410]	//(internal1_m215_y0) y0
#define idinternal1_m215_y0	 1370	//(internal1_m215_y0) y0
#define internal1_m588_tx	 BUFFER[4411]	//(internal1_m588_tx) tx - время накопленное сек
#define idinternal1_m588_tx	 1371	//(internal1_m588_tx) tx - время накопленное сек
#define internal1_m588_y0	 BUFFER[4416]	//(internal1_m588_y0) y0
#define idinternal1_m588_y0	 1372	//(internal1_m588_y0) y0
#define internal1_m2320_tx	 BUFFER[4417]	//(internal1_m2320_tx) tx - внутренний параметр
#define idinternal1_m2320_tx	 1373	//(internal1_m2320_tx) tx - внутренний параметр
#define internal1_m1341_tx	 BUFFER[4422]	//(internal1_m1341_tx) tx - внутренний параметр
#define idinternal1_m1341_tx	 1374	//(internal1_m1341_tx) tx - внутренний параметр
#define internal1_m1832_tx	 BUFFER[4427]	//(internal1_m1832_tx) tx - время накопленное сек
#define idinternal1_m1832_tx	 1375	//(internal1_m1832_tx) tx - время накопленное сек
#define internal1_m1832_y0	 BUFFER[4432]	//(internal1_m1832_y0) y0
#define idinternal1_m1832_y0	 1376	//(internal1_m1832_y0) y0
#define internal1_m1306_tx	 BUFFER[4433]	//(internal1_m1306_tx) tx - время накопленное сек
#define idinternal1_m1306_tx	 1377	//(internal1_m1306_tx) tx - время накопленное сек
#define internal1_m1306_y0	 BUFFER[4438]	//(internal1_m1306_y0) y0
#define idinternal1_m1306_y0	 1378	//(internal1_m1306_y0) y0
#define internal1_m1525_tx	 BUFFER[4439]	//(internal1_m1525_tx) tx - время накопленное сек
#define idinternal1_m1525_tx	 1379	//(internal1_m1525_tx) tx - время накопленное сек
#define internal1_m1525_y0	 BUFFER[4444]	//(internal1_m1525_y0) y0
#define idinternal1_m1525_y0	 1380	//(internal1_m1525_y0) y0
#define internal1_m1052_tx	 BUFFER[4445]	//(internal1_m1052_tx) tx - время накопленное сек
#define idinternal1_m1052_tx	 1381	//(internal1_m1052_tx) tx - время накопленное сек
#define internal1_m1052_y0	 BUFFER[4450]	//(internal1_m1052_y0) y0
#define idinternal1_m1052_y0	 1382	//(internal1_m1052_y0) y0
#define internal1_m1415_tx	 BUFFER[4451]	//(internal1_m1415_tx) tx - время накопленное сек
#define idinternal1_m1415_tx	 1383	//(internal1_m1415_tx) tx - время накопленное сек
#define internal1_m1415_y0	 BUFFER[4456]	//(internal1_m1415_y0) y0
#define idinternal1_m1415_y0	 1384	//(internal1_m1415_y0) y0
#define internal1_m1209_q0	 BUFFER[4457]	//(internal1_m1209_q0) q0 - внутренний параметр
#define idinternal1_m1209_q0	 1385	//(internal1_m1209_q0) q0 - внутренний параметр
#define internal1_m1207_q0	 BUFFER[4459]	//(internal1_m1207_q0) q0 - внутренний параметр
#define idinternal1_m1207_q0	 1386	//(internal1_m1207_q0) q0 - внутренний параметр
#define internal1_m1206_q0	 BUFFER[4461]	//(internal1_m1206_q0) q0 - внутренний параметр
#define idinternal1_m1206_q0	 1387	//(internal1_m1206_q0) q0 - внутренний параметр
#define internal1_m1204_q0	 BUFFER[4463]	//(internal1_m1204_q0) q0 - внутренний параметр
#define idinternal1_m1204_q0	 1388	//(internal1_m1204_q0) q0 - внутренний параметр
#define internal1_m1203_q0	 BUFFER[4465]	//(internal1_m1203_q0) q0 - внутренний параметр
#define idinternal1_m1203_q0	 1389	//(internal1_m1203_q0) q0 - внутренний параметр
#define internal1_m1201_q0	 BUFFER[4467]	//(internal1_m1201_q0) q0 - внутренний параметр
#define idinternal1_m1201_q0	 1390	//(internal1_m1201_q0) q0 - внутренний параметр
#define internal1_m1200_q0	 BUFFER[4469]	//(internal1_m1200_q0) q0 - внутренний параметр
#define idinternal1_m1200_q0	 1391	//(internal1_m1200_q0) q0 - внутренний параметр
#define internal1_m1198_q0	 BUFFER[4471]	//(internal1_m1198_q0) q0 - внутренний параметр
#define idinternal1_m1198_q0	 1392	//(internal1_m1198_q0) q0 - внутренний параметр
#define internal1_m1197_q0	 BUFFER[4473]	//(internal1_m1197_q0) q0 - внутренний параметр
#define idinternal1_m1197_q0	 1393	//(internal1_m1197_q0) q0 - внутренний параметр
#define internal1_m54_x0	 BUFFER[4475]	//(internal1_m54_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m54_x0	 1394	//(internal1_m54_x0) - значение входного параметра на предыдущем шаге
#define internal1_m54_tim	 BUFFER[4477]	//(internal1_m54_tim) - время задержки выходного сигнала
#define idinternal1_m54_tim	 1395	//(internal1_m54_tim) - время задержки выходного сигнала
#define internal1_m1116_q0	 BUFFER[4482]	//(internal1_m1116_q0) q0 - внутренний параметр
#define idinternal1_m1116_q0	 1396	//(internal1_m1116_q0) q0 - внутренний параметр
#define internal1_m1637_x0	 BUFFER[4484]	//(internal1_m1637_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m1637_x0	 1397	//(internal1_m1637_x0) - значение входного параметра на предыдущем шаге
#define internal1_m1637_tim	 BUFFER[4486]	//(internal1_m1637_tim) - время задержки выходного сигнала
#define idinternal1_m1637_tim	 1398	//(internal1_m1637_tim) - время задержки выходного сигнала
#define internal1_m1685_x0	 BUFFER[4491]	//(internal1_m1685_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m1685_x0	 1399	//(internal1_m1685_x0) - значение входного параметра на предыдущем шаге
#define internal1_m1685_tim	 BUFFER[4493]	//(internal1_m1685_tim) - время задержки выходного сигнала
#define idinternal1_m1685_tim	 1400	//(internal1_m1685_tim) - время задержки выходного сигнала
#define internal1_m1688_x0	 BUFFER[4498]	//(internal1_m1688_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m1688_x0	 1401	//(internal1_m1688_x0) - значение входного параметра на предыдущем шаге
#define internal1_m1688_tim	 BUFFER[4500]	//(internal1_m1688_tim) - время задержки выходного сигнала
#define idinternal1_m1688_tim	 1402	//(internal1_m1688_tim) - время задержки выходного сигнала
#define internal1_m2072_x0	 BUFFER[4505]	//(internal1_m2072_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m2072_x0	 1403	//(internal1_m2072_x0) - значение входного параметра на предыдущем шаге
#define internal1_m2072_tim	 BUFFER[4507]	//(internal1_m2072_tim) - время задержки выходного сигнала
#define idinternal1_m2072_tim	 1404	//(internal1_m2072_tim) - время задержки выходного сигнала
#define internal1_m1156_q0	 BUFFER[4512]	//(internal1_m1156_q0) q0 - внутренний параметр
#define idinternal1_m1156_q0	 1405	//(internal1_m1156_q0) q0 - внутренний параметр
#define internal1_m1162_q0	 BUFFER[4514]	//(internal1_m1162_q0) q0 - внутренний параметр
#define idinternal1_m1162_q0	 1406	//(internal1_m1162_q0) q0 - внутренний параметр
#define internal1_m1180_q0	 BUFFER[4516]	//(internal1_m1180_q0) q0 - внутренний параметр
#define idinternal1_m1180_q0	 1407	//(internal1_m1180_q0) q0 - внутренний параметр
#define internal1_m1189_q0	 BUFFER[4518]	//(internal1_m1189_q0) q0 - внутренний параметр
#define idinternal1_m1189_q0	 1408	//(internal1_m1189_q0) q0 - внутренний параметр
#define internal1_m1168_q0	 BUFFER[4520]	//(internal1_m1168_q0) q0 - внутренний параметр
#define idinternal1_m1168_q0	 1409	//(internal1_m1168_q0) q0 - внутренний параметр
#define internal1_m1182_q0	 BUFFER[4522]	//(internal1_m1182_q0) q0 - внутренний параметр
#define idinternal1_m1182_q0	 1410	//(internal1_m1182_q0) q0 - внутренний параметр
#define internal1_m2158_q0	 BUFFER[4524]	//(internal1_m2158_q0) q0 - внутренний параметр
#define idinternal1_m2158_q0	 1411	//(internal1_m2158_q0) q0 - внутренний параметр
#define internal1_m2157_q0	 BUFFER[4526]	//(internal1_m2157_q0) q0 - внутренний параметр
#define idinternal1_m2157_q0	 1412	//(internal1_m2157_q0) q0 - внутренний параметр
#define internal1_m356_Step	 BUFFER[4528]	//(internal1_m356_Step)  - текущий шаг программы
#define idinternal1_m356_Step	 1413	//(internal1_m356_Step)  - текущий шаг программы
#define internal1_m356_rz	 BUFFER[4531]	//(internal1_m356_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m356_rz	 1414	//(internal1_m356_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m356_TimS	 BUFFER[4541]	//(internal1_m356_TimS) Время от старта программы
#define idinternal1_m356_TimS	 1415	//(internal1_m356_TimS) Время от старта программы
#define internal1_m356_FinPr0	 BUFFER[4546]	//(internal1_m356_FinPr0) FinPr - конец программы
#define idinternal1_m356_FinPr0	 1416	//(internal1_m356_FinPr0) FinPr - конец программы
#define internal1_m356_ErrPr0	 BUFFER[4548]	//(internal1_m356_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m356_ErrPr0	 1417	//(internal1_m356_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m356_sbINI0	 BUFFER[4550]	//(internal1_m356_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m356_sbINI0	 1418	//(internal1_m356_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m356_sbVuIS0	 BUFFER[4552]	//(internal1_m356_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m356_sbVuIS0	 1419	//(internal1_m356_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m356_sb2UR0	 BUFFER[4554]	//(internal1_m356_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m356_sb2UR0	 1420	//(internal1_m356_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m356_sbNupIS0	 BUFFER[4556]	//(internal1_m356_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m356_sbNupIS0	 1421	//(internal1_m356_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m356_sbVuRB0	 BUFFER[4558]	//(internal1_m356_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m356_sbVuRB0	 1422	//(internal1_m356_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m356_MyFirstEnterFlag	 BUFFER[4560]	//(internal1_m356_MyFirstEnterFlag)  
#define idinternal1_m356_MyFirstEnterFlag	 1423	//(internal1_m356_MyFirstEnterFlag)  
#define internal1_m364_x0	 BUFFER[4562]	//(internal1_m364_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m364_x0	 1424	//(internal1_m364_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m321_TimS	 BUFFER[4567]	//(internal1_m321_TimS) Время до нулевого отсчета
#define idinternal1_m321_TimS	 1425	//(internal1_m321_TimS) Время до нулевого отсчета
#define internal1_m321_pusk0	 BUFFER[4572]	//(internal1_m321_pusk0) pusk - разрешение выполнения программы
#define idinternal1_m321_pusk0	 1426	//(internal1_m321_pusk0) pusk - разрешение выполнения программы
#define internal1_m298_Step	 BUFFER[4574]	//(internal1_m298_Step)  - текущий шаг программы
#define idinternal1_m298_Step	 1427	//(internal1_m298_Step)  - текущий шаг программы
#define internal1_m298_rz	 BUFFER[4577]	//(internal1_m298_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m298_rz	 1428	//(internal1_m298_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m298_TimS	 BUFFER[4587]	//(internal1_m298_TimS) Время от старта программы
#define idinternal1_m298_TimS	 1429	//(internal1_m298_TimS) Время от старта программы
#define internal1_m298_FinPr0	 BUFFER[4592]	//(internal1_m298_FinPr0) FinPr - конец программы
#define idinternal1_m298_FinPr0	 1430	//(internal1_m298_FinPr0) FinPr - конец программы
#define internal1_m298_ErrPr0	 BUFFER[4594]	//(internal1_m298_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m298_ErrPr0	 1431	//(internal1_m298_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m298_sbINI0	 BUFFER[4596]	//(internal1_m298_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m298_sbINI0	 1432	//(internal1_m298_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m298_sbVuIS0	 BUFFER[4598]	//(internal1_m298_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m298_sbVuIS0	 1433	//(internal1_m298_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m298_sb2UR0	 BUFFER[4600]	//(internal1_m298_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m298_sb2UR0	 1434	//(internal1_m298_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m298_sbNupIS0	 BUFFER[4602]	//(internal1_m298_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m298_sbNupIS0	 1435	//(internal1_m298_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m298_sbVuRB0	 BUFFER[4604]	//(internal1_m298_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m298_sbVuRB0	 1436	//(internal1_m298_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m298_MyFirstEnterFlag	 BUFFER[4606]	//(internal1_m298_MyFirstEnterFlag)  
#define idinternal1_m298_MyFirstEnterFlag	 1437	//(internal1_m298_MyFirstEnterFlag)  
#define internal1_m1599_q0	 BUFFER[4608]	//(internal1_m1599_q0) q0 - внутренний параметр
#define idinternal1_m1599_q0	 1438	//(internal1_m1599_q0) q0 - внутренний параметр
#define internal1_m1600_Step	 BUFFER[4610]	//(internal1_m1600_Step)  - текущий шаг программы
#define idinternal1_m1600_Step	 1439	//(internal1_m1600_Step)  - текущий шаг программы
#define internal1_m1600_rz	 BUFFER[4613]	//(internal1_m1600_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m1600_rz	 1440	//(internal1_m1600_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m1600_TimS	 BUFFER[4619]	//(internal1_m1600_TimS) Время от старта программы
#define idinternal1_m1600_TimS	 1441	//(internal1_m1600_TimS) Время от старта программы
#define internal1_m1600_FinPr0	 BUFFER[4624]	//(internal1_m1600_FinPr0) FinPr - конец программы
#define idinternal1_m1600_FinPr0	 1442	//(internal1_m1600_FinPr0) FinPr - конец программы
#define internal1_m1600_ErrPr0	 BUFFER[4626]	//(internal1_m1600_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m1600_ErrPr0	 1443	//(internal1_m1600_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m1600_sbINI0	 BUFFER[4628]	//(internal1_m1600_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m1600_sbINI0	 1444	//(internal1_m1600_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m1600_sbVuIS0	 BUFFER[4630]	//(internal1_m1600_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m1600_sbVuIS0	 1445	//(internal1_m1600_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m1600_sb2UR0	 BUFFER[4632]	//(internal1_m1600_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m1600_sb2UR0	 1446	//(internal1_m1600_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m1600_sbNupIS0	 BUFFER[4634]	//(internal1_m1600_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m1600_sbNupIS0	 1447	//(internal1_m1600_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m1600_sbVuRB0	 BUFFER[4636]	//(internal1_m1600_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m1600_sbVuRB0	 1448	//(internal1_m1600_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m1600_MyFirstEnterFlag	 BUFFER[4638]	//(internal1_m1600_MyFirstEnterFlag)  
#define idinternal1_m1600_MyFirstEnterFlag	 1449	//(internal1_m1600_MyFirstEnterFlag)  
#define internal1_m1152_q0	 BUFFER[4640]	//(internal1_m1152_q0) q0 - внутренний параметр
#define idinternal1_m1152_q0	 1450	//(internal1_m1152_q0) q0 - внутренний параметр
#define internal1_m1149_q0	 BUFFER[4642]	//(internal1_m1149_q0) q0 - внутренний параметр
#define idinternal1_m1149_q0	 1451	//(internal1_m1149_q0) q0 - внутренний параметр
#define internal1_m1151_q0	 BUFFER[4644]	//(internal1_m1151_q0) q0 - внутренний параметр
#define idinternal1_m1151_q0	 1452	//(internal1_m1151_q0) q0 - внутренний параметр
#define internal1_m1145_q0	 BUFFER[4646]	//(internal1_m1145_q0) q0 - внутренний параметр
#define idinternal1_m1145_q0	 1453	//(internal1_m1145_q0) q0 - внутренний параметр
#define internal1_m836_q0	 BUFFER[4648]	//(internal1_m836_q0) q0 - внутренний параметр
#define idinternal1_m836_q0	 1454	//(internal1_m836_q0) q0 - внутренний параметр
#define internal1_m366_q0	 BUFFER[4650]	//(internal1_m366_q0) q0 - внутренний параметр
#define idinternal1_m366_q0	 1455	//(internal1_m366_q0) q0 - внутренний параметр
#define internal1_m362_q0	 BUFFER[4652]	//(internal1_m362_q0) q0 - внутренний параметр
#define idinternal1_m362_q0	 1456	//(internal1_m362_q0) q0 - внутренний параметр
#define internal1_m318_q0	 BUFFER[4654]	//(internal1_m318_q0) q0 - внутренний параметр
#define idinternal1_m318_q0	 1457	//(internal1_m318_q0) q0 - внутренний параметр
#define internal1_m317_x0	 BUFFER[4656]	//(internal1_m317_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m317_x0	 1458	//(internal1_m317_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m2087_q0	 BUFFER[4661]	//(internal1_m2087_q0) q0 - внутренний параметр
#define idinternal1_m2087_q0	 1459	//(internal1_m2087_q0) q0 - внутренний параметр
#define internal1_m2080_q0	 BUFFER[4663]	//(internal1_m2080_q0) q0 - внутренний параметр
#define idinternal1_m2080_q0	 1460	//(internal1_m2080_q0) q0 - внутренний параметр
#define internal1_m2073_q0	 BUFFER[4665]	//(internal1_m2073_q0) q0 - внутренний параметр
#define idinternal1_m2073_q0	 1461	//(internal1_m2073_q0) q0 - внутренний параметр
#define internal1_m2141_q0	 BUFFER[4667]	//(internal1_m2141_q0) q0 - внутренний параметр
#define idinternal1_m2141_q0	 1462	//(internal1_m2141_q0) q0 - внутренний параметр
#define internal1_m2112_q0	 BUFFER[4669]	//(internal1_m2112_q0) q0 - внутренний параметр
#define idinternal1_m2112_q0	 1463	//(internal1_m2112_q0) q0 - внутренний параметр
#define internal1_m2100_q0	 BUFFER[4671]	//(internal1_m2100_q0) q0 - внутренний параметр
#define idinternal1_m2100_q0	 1464	//(internal1_m2100_q0) q0 - внутренний параметр
#define internal1_m1664_q0	 BUFFER[4673]	//(internal1_m1664_q0) q0 - внутренний параметр
#define idinternal1_m1664_q0	 1465	//(internal1_m1664_q0) q0 - внутренний параметр
#define internal1_m1651_x0	 BUFFER[4675]	//(internal1_m1651_x0) был приход сигнала x1
#define idinternal1_m1651_x0	 1466	//(internal1_m1651_x0) был приход сигнала x1
#define internal1_m1651_y0	 BUFFER[4677]	//(internal1_m1651_y0) интервал между сигналами х1 и х2
#define idinternal1_m1651_y0	 1467	//(internal1_m1651_y0) интервал между сигналами х1 и х2
#define internal1_m1651_fef	 BUFFER[4682]	//(internal1_m1651_fef) FirstEnterFlag
#define idinternal1_m1651_fef	 1468	//(internal1_m1651_fef) FirstEnterFlag
#define internal1_m1646_q0	 BUFFER[4684]	//(internal1_m1646_q0) q0 - внутренний параметр
#define idinternal1_m1646_q0	 1469	//(internal1_m1646_q0) q0 - внутренний параметр
#define internal1_m1636_q0	 BUFFER[4686]	//(internal1_m1636_q0) q0 - внутренний параметр
#define idinternal1_m1636_q0	 1470	//(internal1_m1636_q0) q0 - внутренний параметр
#define internal1_m1699_q0	 BUFFER[4688]	//(internal1_m1699_q0) q0 - внутренний параметр
#define idinternal1_m1699_q0	 1471	//(internal1_m1699_q0) q0 - внутренний параметр
#define internal1_m1720_q0	 BUFFER[4690]	//(internal1_m1720_q0) q0 - внутренний параметр
#define idinternal1_m1720_q0	 1472	//(internal1_m1720_q0) q0 - внутренний параметр
#define internal1_m1684_q0	 BUFFER[4692]	//(internal1_m1684_q0) q0 - внутренний параметр
#define idinternal1_m1684_q0	 1473	//(internal1_m1684_q0) q0 - внутренний параметр
#define internal1_m1700_x0	 BUFFER[4694]	//(internal1_m1700_x0) был приход сигнала x1
#define idinternal1_m1700_x0	 1474	//(internal1_m1700_x0) был приход сигнала x1
#define internal1_m1700_y0	 BUFFER[4696]	//(internal1_m1700_y0) интервал между сигналами х1 и х2
#define idinternal1_m1700_y0	 1475	//(internal1_m1700_y0) интервал между сигналами х1 и х2
#define internal1_m1700_fef	 BUFFER[4701]	//(internal1_m1700_fef) FirstEnterFlag
#define idinternal1_m1700_fef	 1476	//(internal1_m1700_fef) FirstEnterFlag
#define internal1_m1617_x0	 BUFFER[4703]	//(internal1_m1617_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1617_x0	 1477	//(internal1_m1617_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1706_q0	 BUFFER[4708]	//(internal1_m1706_q0) q0 - внутренний параметр
#define idinternal1_m1706_q0	 1478	//(internal1_m1706_q0) q0 - внутренний параметр
#define internal1_m26_q0	 BUFFER[4710]	//(internal1_m26_q0) q0 - внутренний параметр
#define idinternal1_m26_q0	 1479	//(internal1_m26_q0) q0 - внутренний параметр
#define internal1_m1721_q0	 BUFFER[4712]	//(internal1_m1721_q0) q0 - внутренний параметр
#define idinternal1_m1721_q0	 1480	//(internal1_m1721_q0) q0 - внутренний параметр
#define internal1_m711_q0	 BUFFER[4714]	//(internal1_m711_q0) q0 - внутренний параметр
#define idinternal1_m711_q0	 1481	//(internal1_m711_q0) q0 - внутренний параметр
#define internal1_m696_q0	 BUFFER[4716]	//(internal1_m696_q0) q0 - внутренний параметр
#define idinternal1_m696_q0	 1482	//(internal1_m696_q0) q0 - внутренний параметр
#define internal1_m724_q0	 BUFFER[4718]	//(internal1_m724_q0) q0 - внутренний параметр
#define idinternal1_m724_q0	 1483	//(internal1_m724_q0) q0 - внутренний параметр
#define internal1_m707_q0	 BUFFER[4720]	//(internal1_m707_q0) q0 - внутренний параметр
#define idinternal1_m707_q0	 1484	//(internal1_m707_q0) q0 - внутренний параметр
#define internal1_m691_q0	 BUFFER[4722]	//(internal1_m691_q0) q0 - внутренний параметр
#define idinternal1_m691_q0	 1485	//(internal1_m691_q0) q0 - внутренний параметр
#define internal1_m689_q0	 BUFFER[4724]	//(internal1_m689_q0) q0 - внутренний параметр
#define idinternal1_m689_q0	 1486	//(internal1_m689_q0) q0 - внутренний параметр
#define internal1_m677_q0	 BUFFER[4726]	//(internal1_m677_q0) q0 - внутренний параметр
#define idinternal1_m677_q0	 1487	//(internal1_m677_q0) q0 - внутренний параметр
#define internal1_m1602_q0	 BUFFER[4728]	//(internal1_m1602_q0) q0 - внутренний параметр
#define idinternal1_m1602_q0	 1488	//(internal1_m1602_q0) q0 - внутренний параметр
#define internal1_m687_q0	 BUFFER[4733]	//(internal1_m687_q0) q0 - внутренний параметр
#define idinternal1_m687_q0	 1489	//(internal1_m687_q0) q0 - внутренний параметр
#define internal1_m116_q0	 BUFFER[4735]	//(internal1_m116_q0) q0 - внутренний параметр
#define idinternal1_m116_q0	 1490	//(internal1_m116_q0) q0 - внутренний параметр
#define internal1_m1867_q0	 BUFFER[4737]	//(internal1_m1867_q0) q0 - внутренний параметр
#define idinternal1_m1867_q0	 1491	//(internal1_m1867_q0) q0 - внутренний параметр
#define internal1_m1866_q0	 BUFFER[4739]	//(internal1_m1866_q0) q0 - внутренний параметр
#define idinternal1_m1866_q0	 1492	//(internal1_m1866_q0) q0 - внутренний параметр
#define internal1_m1865_q0	 BUFFER[4741]	//(internal1_m1865_q0) q0 - внутренний параметр
#define idinternal1_m1865_q0	 1493	//(internal1_m1865_q0) q0 - внутренний параметр
#define internal1_m1864_q0	 BUFFER[4743]	//(internal1_m1864_q0) q0 - внутренний параметр
#define idinternal1_m1864_q0	 1494	//(internal1_m1864_q0) q0 - внутренний параметр
#define internal1_m1900_q0	 BUFFER[4745]	//(internal1_m1900_q0) q0 - внутренний параметр
#define idinternal1_m1900_q0	 1495	//(internal1_m1900_q0) q0 - внутренний параметр
#define internal1_m1899_q0	 BUFFER[4747]	//(internal1_m1899_q0) q0 - внутренний параметр
#define idinternal1_m1899_q0	 1496	//(internal1_m1899_q0) q0 - внутренний параметр
#define internal1_m1898_q0	 BUFFER[4749]	//(internal1_m1898_q0) q0 - внутренний параметр
#define idinternal1_m1898_q0	 1497	//(internal1_m1898_q0) q0 - внутренний параметр
#define internal1_m2172_q0	 BUFFER[4751]	//(internal1_m2172_q0) q0 - внутренний параметр
#define idinternal1_m2172_q0	 1498	//(internal1_m2172_q0) q0 - внутренний параметр
#define internal1_m1960_q0	 BUFFER[4753]	//(internal1_m1960_q0) q0 - внутренний параметр
#define idinternal1_m1960_q0	 1499	//(internal1_m1960_q0) q0 - внутренний параметр
#define internal1_m1950_q0	 BUFFER[4755]	//(internal1_m1950_q0) q0 - внутренний параметр
#define idinternal1_m1950_q0	 1500	//(internal1_m1950_q0) q0 - внутренний параметр
#define internal1_m1957_q0	 BUFFER[4757]	//(internal1_m1957_q0) q0 - внутренний параметр
#define idinternal1_m1957_q0	 1501	//(internal1_m1957_q0) q0 - внутренний параметр
#define internal1_m1947_q0	 BUFFER[4759]	//(internal1_m1947_q0) q0 - внутренний параметр
#define idinternal1_m1947_q0	 1502	//(internal1_m1947_q0) q0 - внутренний параметр
#define internal1_m1954_q0	 BUFFER[4761]	//(internal1_m1954_q0) q0 - внутренний параметр
#define idinternal1_m1954_q0	 1503	//(internal1_m1954_q0) q0 - внутренний параметр
#define internal1_m2388_q0	 BUFFER[4763]	//(internal1_m2388_q0) q0 - внутренний параметр
#define idinternal1_m2388_q0	 1504	//(internal1_m2388_q0) q0 - внутренний параметр
#define internal1_m2384_q0	 BUFFER[4765]	//(internal1_m2384_q0) q0 - внутренний параметр
#define idinternal1_m2384_q0	 1505	//(internal1_m2384_q0) q0 - внутренний параметр
#define internal1_m1925_q0	 BUFFER[4767]	//(internal1_m1925_q0) q0 - внутренний параметр
#define idinternal1_m1925_q0	 1506	//(internal1_m1925_q0) q0 - внутренний параметр
#define internal1_m1917_q0	 BUFFER[4769]	//(internal1_m1917_q0) q0 - внутренний параметр
#define idinternal1_m1917_q0	 1507	//(internal1_m1917_q0) q0 - внутренний параметр
#define internal1_m1915_q0	 BUFFER[4771]	//(internal1_m1915_q0) q0 - внутренний параметр
#define idinternal1_m1915_q0	 1508	//(internal1_m1915_q0) q0 - внутренний параметр
#define internal1_m1911_q0	 BUFFER[4773]	//(internal1_m1911_q0) q0 - внутренний параметр
#define idinternal1_m1911_q0	 1509	//(internal1_m1911_q0) q0 - внутренний параметр
#define internal1_m1907_q0	 BUFFER[4775]	//(internal1_m1907_q0) q0 - внутренний параметр
#define idinternal1_m1907_q0	 1510	//(internal1_m1907_q0) q0 - внутренний параметр
#define internal1_m1909_q0	 BUFFER[4777]	//(internal1_m1909_q0) q0 - внутренний параметр
#define idinternal1_m1909_q0	 1511	//(internal1_m1909_q0) q0 - внутренний параметр
#define internal1_m19_q0	 BUFFER[4779]	//(internal1_m19_q0) q0 - внутренний параметр
#define idinternal1_m19_q0	 1512	//(internal1_m19_q0) q0 - внутренний параметр
#define internal1_m1890_q0	 BUFFER[4781]	//(internal1_m1890_q0) q0 - внутренний параметр
#define idinternal1_m1890_q0	 1513	//(internal1_m1890_q0) q0 - внутренний параметр
#define internal1_m1888_q0	 BUFFER[4783]	//(internal1_m1888_q0) q0 - внутренний параметр
#define idinternal1_m1888_q0	 1514	//(internal1_m1888_q0) q0 - внутренний параметр
#define internal1_m1884_q0	 BUFFER[4785]	//(internal1_m1884_q0) q0 - внутренний параметр
#define idinternal1_m1884_q0	 1515	//(internal1_m1884_q0) q0 - внутренний параметр
#define internal1_m1886_q0	 BUFFER[4787]	//(internal1_m1886_q0) q0 - внутренний параметр
#define idinternal1_m1886_q0	 1516	//(internal1_m1886_q0) q0 - внутренний параметр
#define internal1_m1882_q0	 BUFFER[4789]	//(internal1_m1882_q0) q0 - внутренний параметр
#define idinternal1_m1882_q0	 1517	//(internal1_m1882_q0) q0 - внутренний параметр
#define internal1_m1880_q0	 BUFFER[4791]	//(internal1_m1880_q0) q0 - внутренний параметр
#define idinternal1_m1880_q0	 1518	//(internal1_m1880_q0) q0 - внутренний параметр
#define internal1_m2294_q0	 BUFFER[4793]	//(internal1_m2294_q0) q0 - внутренний параметр
#define idinternal1_m2294_q0	 1519	//(internal1_m2294_q0) q0 - внутренний параметр
#define internal1_m2292_q0	 BUFFER[4795]	//(internal1_m2292_q0) q0 - внутренний параметр
#define idinternal1_m2292_q0	 1520	//(internal1_m2292_q0) q0 - внутренний параметр
#define internal1_m2269_q0	 BUFFER[4797]	//(internal1_m2269_q0) q0 - внутренний параметр
#define idinternal1_m2269_q0	 1521	//(internal1_m2269_q0) q0 - внутренний параметр
#define internal1_m2253_q0	 BUFFER[4799]	//(internal1_m2253_q0) q0 - внутренний параметр
#define idinternal1_m2253_q0	 1522	//(internal1_m2253_q0) q0 - внутренний параметр
#define internal1_m2184_q0	 BUFFER[4801]	//(internal1_m2184_q0) q0 - внутренний параметр
#define idinternal1_m2184_q0	 1523	//(internal1_m2184_q0) q0 - внутренний параметр
#define internal1_m1876_q0	 BUFFER[4803]	//(internal1_m1876_q0) q0 - внутренний параметр
#define idinternal1_m1876_q0	 1524	//(internal1_m1876_q0) q0 - внутренний параметр
#define internal1_m1878_q0	 BUFFER[4805]	//(internal1_m1878_q0) q0 - внутренний параметр
#define idinternal1_m1878_q0	 1525	//(internal1_m1878_q0) q0 - внутренний параметр
#define internal1_m1862_q0	 BUFFER[4807]	//(internal1_m1862_q0) q0 - внутренний параметр
#define idinternal1_m1862_q0	 1526	//(internal1_m1862_q0) q0 - внутренний параметр
#define internal1_m1860_q0	 BUFFER[4809]	//(internal1_m1860_q0) q0 - внутренний параметр
#define idinternal1_m1860_q0	 1527	//(internal1_m1860_q0) q0 - внутренний параметр
#define internal1_m1858_q0	 BUFFER[4811]	//(internal1_m1858_q0) q0 - внутренний параметр
#define idinternal1_m1858_q0	 1528	//(internal1_m1858_q0) q0 - внутренний параметр
#define internal1_m1856_q0	 BUFFER[4813]	//(internal1_m1856_q0) q0 - внутренний параметр
#define idinternal1_m1856_q0	 1529	//(internal1_m1856_q0) q0 - внутренний параметр
#define internal1_m1855_q0	 BUFFER[4815]	//(internal1_m1855_q0) q0 - внутренний параметр
#define idinternal1_m1855_q0	 1530	//(internal1_m1855_q0) q0 - внутренний параметр
#define internal1_m1853_q0	 BUFFER[4817]	//(internal1_m1853_q0) q0 - внутренний параметр
#define idinternal1_m1853_q0	 1531	//(internal1_m1853_q0) q0 - внутренний параметр
#define internal1_m1852_q0	 BUFFER[4819]	//(internal1_m1852_q0) q0 - внутренний параметр
#define idinternal1_m1852_q0	 1532	//(internal1_m1852_q0) q0 - внутренний параметр
#define internal1_m1850_q0	 BUFFER[4821]	//(internal1_m1850_q0) q0 - внутренний параметр
#define idinternal1_m1850_q0	 1533	//(internal1_m1850_q0) q0 - внутренний параметр
#define internal1_m2325_DvUp0	 BUFFER[4823]	//(internal1_m2325_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2325_DvUp0	 1534	//(internal1_m2325_DvUp0) - есть команда на движение вперёд
#define internal1_m2325_DvDw0	 BUFFER[4824]	//(internal1_m2325_DvDw0) - есть команда на движение назад
#define idinternal1_m2325_DvDw0	 1535	//(internal1_m2325_DvDw0) - есть команда на движение назад
#define internal1_m2325_FDvUp0	 BUFFER[4825]	//(internal1_m2325_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2325_FDvUp0	 1536	//(internal1_m2325_FDvUp0) - есть команда на движение вперёд
#define internal1_m2325_FDvDw0	 BUFFER[4826]	//(internal1_m2325_FDvDw0) - есть команда на движение назад
#define idinternal1_m2325_FDvDw0	 1537	//(internal1_m2325_FDvDw0) - есть команда на движение назад
#define internal1_m2325_BlDv0	 BUFFER[4827]	//(internal1_m2325_BlDv0) - была блокировка
#define idinternal1_m2325_BlDv0	 1538	//(internal1_m2325_BlDv0) - была блокировка
#define internal1_m2325_Pkv0	 BUFFER[4828]	//(internal1_m2325_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2325_Pkv0	 1539	//(internal1_m2325_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2325_Pkav0	 BUFFER[4829]	//(internal1_m2325_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2325_Pkav0	 1540	//(internal1_m2325_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2325_Zkv0	 BUFFER[4830]	//(internal1_m2325_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2325_Zkv0	 1541	//(internal1_m2325_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2325_Zkav0	 BUFFER[4831]	//(internal1_m2325_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2325_Zkav0	 1542	//(internal1_m2325_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2325_txNm	 BUFFER[4832]	//(internal1_m2325_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2325_txNm	 1543	//(internal1_m2325_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2325_txSm	 BUFFER[4837]	//(internal1_m2325_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2325_txSm	 1544	//(internal1_m2325_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2325_txHr	 BUFFER[4842]	//(internal1_m2325_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2325_txHr	 1545	//(internal1_m2325_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2325_txLd	 BUFFER[4847]	//(internal1_m2325_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2325_txLd	 1546	//(internal1_m2325_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2325_fef	 BUFFER[4852]	//(internal1_m2325_fef) fef
#define idinternal1_m2325_fef	 1547	//(internal1_m2325_fef) fef
#define internal1_m2319_DvUp0	 BUFFER[4853]	//(internal1_m2319_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2319_DvUp0	 1548	//(internal1_m2319_DvUp0) - есть команда на движение вперёд
#define internal1_m2319_DvDw0	 BUFFER[4854]	//(internal1_m2319_DvDw0) - есть команда на движение назад
#define idinternal1_m2319_DvDw0	 1549	//(internal1_m2319_DvDw0) - есть команда на движение назад
#define internal1_m2319_FDvUp0	 BUFFER[4855]	//(internal1_m2319_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2319_FDvUp0	 1550	//(internal1_m2319_FDvUp0) - есть команда на движение вперёд
#define internal1_m2319_FDvDw0	 BUFFER[4856]	//(internal1_m2319_FDvDw0) - есть команда на движение назад
#define idinternal1_m2319_FDvDw0	 1551	//(internal1_m2319_FDvDw0) - есть команда на движение назад
#define internal1_m2319_BlDv0	 BUFFER[4857]	//(internal1_m2319_BlDv0) - была блокировка
#define idinternal1_m2319_BlDv0	 1552	//(internal1_m2319_BlDv0) - была блокировка
#define internal1_m2319_Pkv0	 BUFFER[4858]	//(internal1_m2319_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2319_Pkv0	 1553	//(internal1_m2319_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2319_Pkav0	 BUFFER[4859]	//(internal1_m2319_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2319_Pkav0	 1554	//(internal1_m2319_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2319_Zkv0	 BUFFER[4860]	//(internal1_m2319_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2319_Zkv0	 1555	//(internal1_m2319_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2319_Zkav0	 BUFFER[4861]	//(internal1_m2319_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2319_Zkav0	 1556	//(internal1_m2319_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2319_txNm	 BUFFER[4862]	//(internal1_m2319_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2319_txNm	 1557	//(internal1_m2319_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2319_txSm	 BUFFER[4867]	//(internal1_m2319_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2319_txSm	 1558	//(internal1_m2319_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2319_txHr	 BUFFER[4872]	//(internal1_m2319_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2319_txHr	 1559	//(internal1_m2319_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2319_txLd	 BUFFER[4877]	//(internal1_m2319_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2319_txLd	 1560	//(internal1_m2319_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2319_fef	 BUFFER[4882]	//(internal1_m2319_fef) fef
#define idinternal1_m2319_fef	 1561	//(internal1_m2319_fef) fef
#define internal1_m1679_q0	 BUFFER[4883]	//(internal1_m1679_q0) q0 - внутренний параметр
#define idinternal1_m1679_q0	 1562	//(internal1_m1679_q0) q0 - внутренний параметр
#define internal1_m1705_x0	 BUFFER[4885]	//(internal1_m1705_x0) был приход сигнала x1
#define idinternal1_m1705_x0	 1563	//(internal1_m1705_x0) был приход сигнала x1
#define internal1_m1705_y0	 BUFFER[4887]	//(internal1_m1705_y0) интервал между сигналами х1 и х2
#define idinternal1_m1705_y0	 1564	//(internal1_m1705_y0) интервал между сигналами х1 и х2
#define internal1_m1705_fef	 BUFFER[4892]	//(internal1_m1705_fef) FirstEnterFlag
#define idinternal1_m1705_fef	 1565	//(internal1_m1705_fef) FirstEnterFlag
#define internal1_m2123_x0	 BUFFER[4894]	//(internal1_m2123_x0) был приход сигнала x1
#define idinternal1_m2123_x0	 1566	//(internal1_m2123_x0) был приход сигнала x1
#define internal1_m2123_y0	 BUFFER[4896]	//(internal1_m2123_y0) интервал между сигналами х1 и х2
#define idinternal1_m2123_y0	 1567	//(internal1_m2123_y0) интервал между сигналами х1 и х2
#define internal1_m2123_fef	 BUFFER[4901]	//(internal1_m2123_fef) FirstEnterFlag
#define idinternal1_m2123_fef	 1568	//(internal1_m2123_fef) FirstEnterFlag
#define internal1_m2082_x0	 BUFFER[4903]	//(internal1_m2082_x0) был приход сигнала x1
#define idinternal1_m2082_x0	 1569	//(internal1_m2082_x0) был приход сигнала x1
#define internal1_m2082_y0	 BUFFER[4905]	//(internal1_m2082_y0) интервал между сигналами х1 и х2
#define idinternal1_m2082_y0	 1570	//(internal1_m2082_y0) интервал между сигналами х1 и х2
#define internal1_m2082_fef	 BUFFER[4910]	//(internal1_m2082_fef) FirstEnterFlag
#define idinternal1_m2082_fef	 1571	//(internal1_m2082_fef) FirstEnterFlag
#define internal1_m309_q0	 BUFFER[4912]	//(internal1_m309_q0) q0 - внутренний параметр
#define idinternal1_m309_q0	 1572	//(internal1_m309_q0) q0 - внутренний параметр
#define internal1_m1124_q0	 BUFFER[4914]	//(internal1_m1124_q0) q0 - внутренний параметр
#define idinternal1_m1124_q0	 1573	//(internal1_m1124_q0) q0 - внутренний параметр
#define internal1_m699_q0	 BUFFER[4916]	//(internal1_m699_q0) q0 - внутренний параметр
#define idinternal1_m699_q0	 1574	//(internal1_m699_q0) q0 - внутренний параметр
#define internal1_m1483_X0	 BUFFER[4918]	//(internal1_m1483_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1483_X0	 1575	//(internal1_m1483_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1483_t0	 BUFFER[4923]	//(internal1_m1483_t0) время нахождения в зоне возврата
#define idinternal1_m1483_t0	 1576	//(internal1_m1483_t0) время нахождения в зоне возврата
#define internal1_m1483_BLDv0	 BUFFER[4928]	//(internal1_m1483_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1483_BLDv0	 1577	//(internal1_m1483_BLDv0) BlDv - Блокировка движения
#define internal1_m1500_tx	 BUFFER[4929]	//(internal1_m1500_tx) tx - время накопленное сек
#define idinternal1_m1500_tx	 1578	//(internal1_m1500_tx) tx - время накопленное сек
#define internal1_m1500_y0	 BUFFER[4934]	//(internal1_m1500_y0) y0
#define idinternal1_m1500_y0	 1579	//(internal1_m1500_y0) y0
#define internal1_m1501_tx	 BUFFER[4935]	//(internal1_m1501_tx) tx - время накопленное сек
#define idinternal1_m1501_tx	 1580	//(internal1_m1501_tx) tx - время накопленное сек
#define internal1_m1501_y0	 BUFFER[4940]	//(internal1_m1501_y0) y0
#define idinternal1_m1501_y0	 1581	//(internal1_m1501_y0) y0
#define internal1_m1509_xptr	 BUFFER[4941]	//(internal1_m1509_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1509_xptr	 1582	//(internal1_m1509_xptr) указатель текущей позиции в массиве координат
#define internal1_m1509_x0	 BUFFER[4944]	//(internal1_m1509_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1509_x0	 1583	//(internal1_m1509_x0) x0 - массив мгновенных значений координат
#define internal1_m1509_tim0	 BUFFER[5244]	//(internal1_m1509_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1509_tim0	 1584	//(internal1_m1509_tim0) tim0 - массив значений времени цикла
#define internal1_m1509_sumtim	 BUFFER[5544]	//(internal1_m1509_sumtim) sumtim - время в пути
#define idinternal1_m1509_sumtim	 1585	//(internal1_m1509_sumtim) sumtim - время в пути
#define internal1_m1509_StSpeed	 BUFFER[5549]	//(internal1_m1509_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1509_StSpeed	 1586	//(internal1_m1509_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1509_Vz0	 BUFFER[5554]	//(internal1_m1509_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1509_Vz0	 1587	//(internal1_m1509_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1509_flRazg	 BUFFER[5559]	//(internal1_m1509_flRazg) признак разгона/торможения
#define idinternal1_m1509_flRazg	 1588	//(internal1_m1509_flRazg) признак разгона/торможения
#define internal1_m1509_DelSp	 BUFFER[5562]	//(internal1_m1509_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1509_DelSp	 1589	//(internal1_m1509_DelSp) DelSp - время переключения скоростей
#define internal1_m1509_z0	 BUFFER[5567]	//(internal1_m1509_z0) z0 - точка прекращения движения
#define idinternal1_m1509_z0	 1590	//(internal1_m1509_z0) z0 - точка прекращения движения
#define internal1_m1509_txZS	 BUFFER[5572]	//(internal1_m1509_txZS) txZS
#define idinternal1_m1509_txZS	 1591	//(internal1_m1509_txZS) txZS
#define internal1_m1509_tx	 BUFFER[5577]	//(internal1_m1509_tx) tx
#define idinternal1_m1509_tx	 1592	//(internal1_m1509_tx) tx
#define internal1_m1509_txd	 BUFFER[5582]	//(internal1_m1509_txd) txd
#define idinternal1_m1509_txd	 1593	//(internal1_m1509_txd) txd
#define internal1_m1509_txMBl	 BUFFER[5587]	//(internal1_m1509_txMBl) tx
#define idinternal1_m1509_txMBl	 1594	//(internal1_m1509_txMBl) tx
#define internal1_m1509_txBl	 BUFFER[5592]	//(internal1_m1509_txBl) tx
#define idinternal1_m1509_txBl	 1595	//(internal1_m1509_txBl) tx
#define internal1_m1509_Speed0	 BUFFER[5597]	//(internal1_m1509_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1509_Speed0	 1596	//(internal1_m1509_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1509_xz0	 BUFFER[5602]	//(internal1_m1509_xz0) xz0 - новое задание мм
#define idinternal1_m1509_xz0	 1597	//(internal1_m1509_xz0) xz0 - новое задание мм
#define internal1_m1509_tz0	 BUFFER[5607]	//(internal1_m1509_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1509_tz0	 1598	//(internal1_m1509_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1509_Shift0	 BUFFER[5612]	//(internal1_m1509_Shift0) Shift0 - признак самохода
#define idinternal1_m1509_Shift0	 1599	//(internal1_m1509_Shift0) Shift0 - признак самохода
#define internal1_m1509_ShCntlSp0	 BUFFER[5614]	//(internal1_m1509_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1509_ShCntlSp0	 1600	//(internal1_m1509_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1509_ShiftControl	 BUFFER[5616]	//(internal1_m1509_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1509_ShiftControl	 1601	//(internal1_m1509_ShiftControl) ShiftControl - признак самохода
#define internal1_m697_q0	 BUFFER[5618]	//(internal1_m697_q0) q0 - внутренний параметр
#define idinternal1_m697_q0	 1602	//(internal1_m697_q0) q0 - внутренний параметр
#define internal1_m1005_X0	 BUFFER[5620]	//(internal1_m1005_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1005_X0	 1603	//(internal1_m1005_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1005_t0	 BUFFER[5625]	//(internal1_m1005_t0) время нахождения в зоне возврата
#define idinternal1_m1005_t0	 1604	//(internal1_m1005_t0) время нахождения в зоне возврата
#define internal1_m1005_BLDv0	 BUFFER[5630]	//(internal1_m1005_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1005_BLDv0	 1605	//(internal1_m1005_BLDv0) BlDv - Блокировка движения
#define internal1_m1028_tx	 BUFFER[5631]	//(internal1_m1028_tx) tx - время накопленное сек
#define idinternal1_m1028_tx	 1606	//(internal1_m1028_tx) tx - время накопленное сек
#define internal1_m1028_y0	 BUFFER[5636]	//(internal1_m1028_y0) y0
#define idinternal1_m1028_y0	 1607	//(internal1_m1028_y0) y0
#define internal1_m1027_tx	 BUFFER[5637]	//(internal1_m1027_tx) tx - время накопленное сек
#define idinternal1_m1027_tx	 1608	//(internal1_m1027_tx) tx - время накопленное сек
#define internal1_m1027_y0	 BUFFER[5642]	//(internal1_m1027_y0) y0
#define idinternal1_m1027_y0	 1609	//(internal1_m1027_y0) y0
#define internal1_m1035_xptr	 BUFFER[5643]	//(internal1_m1035_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1035_xptr	 1610	//(internal1_m1035_xptr) указатель текущей позиции в массиве координат
#define internal1_m1035_x0	 BUFFER[5646]	//(internal1_m1035_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1035_x0	 1611	//(internal1_m1035_x0) x0 - массив мгновенных значений координат
#define internal1_m1035_tim0	 BUFFER[5946]	//(internal1_m1035_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1035_tim0	 1612	//(internal1_m1035_tim0) tim0 - массив значений времени цикла
#define internal1_m1035_sumtim	 BUFFER[6246]	//(internal1_m1035_sumtim) sumtim - время в пути
#define idinternal1_m1035_sumtim	 1613	//(internal1_m1035_sumtim) sumtim - время в пути
#define internal1_m1035_StSpeed	 BUFFER[6251]	//(internal1_m1035_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1035_StSpeed	 1614	//(internal1_m1035_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1035_Vz0	 BUFFER[6256]	//(internal1_m1035_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1035_Vz0	 1615	//(internal1_m1035_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1035_flRazg	 BUFFER[6261]	//(internal1_m1035_flRazg) признак разгона/торможения
#define idinternal1_m1035_flRazg	 1616	//(internal1_m1035_flRazg) признак разгона/торможения
#define internal1_m1035_DelSp	 BUFFER[6264]	//(internal1_m1035_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1035_DelSp	 1617	//(internal1_m1035_DelSp) DelSp - время переключения скоростей
#define internal1_m1035_z0	 BUFFER[6269]	//(internal1_m1035_z0) z0 - точка прекращения движения
#define idinternal1_m1035_z0	 1618	//(internal1_m1035_z0) z0 - точка прекращения движения
#define internal1_m1035_txZS	 BUFFER[6274]	//(internal1_m1035_txZS) txZS
#define idinternal1_m1035_txZS	 1619	//(internal1_m1035_txZS) txZS
#define internal1_m1035_tx	 BUFFER[6279]	//(internal1_m1035_tx) tx
#define idinternal1_m1035_tx	 1620	//(internal1_m1035_tx) tx
#define internal1_m1035_txd	 BUFFER[6284]	//(internal1_m1035_txd) txd
#define idinternal1_m1035_txd	 1621	//(internal1_m1035_txd) txd
#define internal1_m1035_txMBl	 BUFFER[6289]	//(internal1_m1035_txMBl) tx
#define idinternal1_m1035_txMBl	 1622	//(internal1_m1035_txMBl) tx
#define internal1_m1035_txBl	 BUFFER[6294]	//(internal1_m1035_txBl) tx
#define idinternal1_m1035_txBl	 1623	//(internal1_m1035_txBl) tx
#define internal1_m1035_Speed0	 BUFFER[6299]	//(internal1_m1035_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1035_Speed0	 1624	//(internal1_m1035_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1035_xz0	 BUFFER[6304]	//(internal1_m1035_xz0) xz0 - новое задание мм
#define idinternal1_m1035_xz0	 1625	//(internal1_m1035_xz0) xz0 - новое задание мм
#define internal1_m1035_tz0	 BUFFER[6309]	//(internal1_m1035_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1035_tz0	 1626	//(internal1_m1035_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1035_Shift0	 BUFFER[6314]	//(internal1_m1035_Shift0) Shift0 - признак самохода
#define idinternal1_m1035_Shift0	 1627	//(internal1_m1035_Shift0) Shift0 - признак самохода
#define internal1_m1035_ShCntlSp0	 BUFFER[6316]	//(internal1_m1035_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1035_ShCntlSp0	 1628	//(internal1_m1035_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1035_ShiftControl	 BUFFER[6318]	//(internal1_m1035_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1035_ShiftControl	 1629	//(internal1_m1035_ShiftControl) ShiftControl - признак самохода
#define internal1_m550_X0	 BUFFER[6320]	//(internal1_m550_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m550_X0	 1630	//(internal1_m550_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m550_t0	 BUFFER[6325]	//(internal1_m550_t0) время нахождения в зоне возврата
#define idinternal1_m550_t0	 1631	//(internal1_m550_t0) время нахождения в зоне возврата
#define internal1_m550_BLDv0	 BUFFER[6330]	//(internal1_m550_BLDv0) BlDv - Блокировка движения
#define idinternal1_m550_BLDv0	 1632	//(internal1_m550_BLDv0) BlDv - Блокировка движения
#define internal1_m569_tx	 BUFFER[6331]	//(internal1_m569_tx) tx - время накопленное сек
#define idinternal1_m569_tx	 1633	//(internal1_m569_tx) tx - время накопленное сек
#define internal1_m569_y0	 BUFFER[6336]	//(internal1_m569_y0) y0
#define idinternal1_m569_y0	 1634	//(internal1_m569_y0) y0
#define internal1_m568_tx	 BUFFER[6337]	//(internal1_m568_tx) tx - время накопленное сек
#define idinternal1_m568_tx	 1635	//(internal1_m568_tx) tx - время накопленное сек
#define internal1_m568_y0	 BUFFER[6342]	//(internal1_m568_y0) y0
#define idinternal1_m568_y0	 1636	//(internal1_m568_y0) y0
#define internal1_m573_xptr	 BUFFER[6343]	//(internal1_m573_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m573_xptr	 1637	//(internal1_m573_xptr) указатель текущей позиции в массиве координат
#define internal1_m573_x0	 BUFFER[6346]	//(internal1_m573_x0) x0 - массив мгновенных значений координат
#define idinternal1_m573_x0	 1638	//(internal1_m573_x0) x0 - массив мгновенных значений координат
#define internal1_m573_tim0	 BUFFER[7096]	//(internal1_m573_tim0) tim0 - массив значений времени цикла
#define idinternal1_m573_tim0	 1639	//(internal1_m573_tim0) tim0 - массив значений времени цикла
#define internal1_m573_sumtim	 BUFFER[7846]	//(internal1_m573_sumtim) sumtim - время в пути
#define idinternal1_m573_sumtim	 1640	//(internal1_m573_sumtim) sumtim - время в пути
#define internal1_m573_StSpeed	 BUFFER[7851]	//(internal1_m573_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m573_StSpeed	 1641	//(internal1_m573_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m573_Vz0	 BUFFER[7856]	//(internal1_m573_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m573_Vz0	 1642	//(internal1_m573_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m573_flRazg	 BUFFER[7861]	//(internal1_m573_flRazg) признак разгона/торможения
#define idinternal1_m573_flRazg	 1643	//(internal1_m573_flRazg) признак разгона/торможения
#define internal1_m573_DelSp	 BUFFER[7864]	//(internal1_m573_DelSp) DelSp - время переключения скоростей
#define idinternal1_m573_DelSp	 1644	//(internal1_m573_DelSp) DelSp - время переключения скоростей
#define internal1_m573_z0	 BUFFER[7869]	//(internal1_m573_z0) z0 - точка прекращения движения
#define idinternal1_m573_z0	 1645	//(internal1_m573_z0) z0 - точка прекращения движения
#define internal1_m573_txZS	 BUFFER[7874]	//(internal1_m573_txZS) txZS
#define idinternal1_m573_txZS	 1646	//(internal1_m573_txZS) txZS
#define internal1_m573_tx	 BUFFER[7879]	//(internal1_m573_tx) tx
#define idinternal1_m573_tx	 1647	//(internal1_m573_tx) tx
#define internal1_m573_txd	 BUFFER[7884]	//(internal1_m573_txd) txd
#define idinternal1_m573_txd	 1648	//(internal1_m573_txd) txd
#define internal1_m573_txMBl	 BUFFER[7889]	//(internal1_m573_txMBl) tx
#define idinternal1_m573_txMBl	 1649	//(internal1_m573_txMBl) tx
#define internal1_m573_txBl	 BUFFER[7894]	//(internal1_m573_txBl) tx
#define idinternal1_m573_txBl	 1650	//(internal1_m573_txBl) tx
#define internal1_m573_Speed0	 BUFFER[7899]	//(internal1_m573_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m573_Speed0	 1651	//(internal1_m573_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m573_xz0	 BUFFER[7904]	//(internal1_m573_xz0) xz0 - новое задание мм
#define idinternal1_m573_xz0	 1652	//(internal1_m573_xz0) xz0 - новое задание мм
#define internal1_m573_tz0	 BUFFER[7909]	//(internal1_m573_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m573_tz0	 1653	//(internal1_m573_tz0) tz0 - время защиты от нового задания сек
#define internal1_m573_Shift0	 BUFFER[7914]	//(internal1_m573_Shift0) Shift0 - признак самохода
#define idinternal1_m573_Shift0	 1654	//(internal1_m573_Shift0) Shift0 - признак самохода
#define internal1_m573_ShCntlSp0	 BUFFER[7916]	//(internal1_m573_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m573_ShCntlSp0	 1655	//(internal1_m573_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m573_ShiftControl	 BUFFER[7918]	//(internal1_m573_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m573_ShiftControl	 1656	//(internal1_m573_ShiftControl) ShiftControl - признак самохода
#define internal1_m694_q0	 BUFFER[7920]	//(internal1_m694_q0) q0 - внутренний параметр
#define idinternal1_m694_q0	 1657	//(internal1_m694_q0) q0 - внутренний параметр
#define internal1_m176_X0	 BUFFER[7922]	//(internal1_m176_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m176_X0	 1658	//(internal1_m176_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m176_t0	 BUFFER[7927]	//(internal1_m176_t0) время нахождения в зоне возврата
#define idinternal1_m176_t0	 1659	//(internal1_m176_t0) время нахождения в зоне возврата
#define internal1_m176_BLDv0	 BUFFER[7932]	//(internal1_m176_BLDv0) BlDv - Блокировка движения
#define idinternal1_m176_BLDv0	 1660	//(internal1_m176_BLDv0) BlDv - Блокировка движения
#define internal1_m201_xptr	 BUFFER[7933]	//(internal1_m201_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m201_xptr	 1661	//(internal1_m201_xptr) указатель текущей позиции в массиве координат
#define internal1_m201_x0	 BUFFER[7936]	//(internal1_m201_x0) x0 - массив мгновенных значений координат
#define idinternal1_m201_x0	 1662	//(internal1_m201_x0) x0 - массив мгновенных значений координат
#define internal1_m201_tim0	 BUFFER[8686]	//(internal1_m201_tim0) tim0 - массив значений времени цикла
#define idinternal1_m201_tim0	 1663	//(internal1_m201_tim0) tim0 - массив значений времени цикла
#define internal1_m201_sumtim	 BUFFER[9436]	//(internal1_m201_sumtim) sumtim - время в пути
#define idinternal1_m201_sumtim	 1664	//(internal1_m201_sumtim) sumtim - время в пути
#define internal1_m201_StSpeed	 BUFFER[9441]	//(internal1_m201_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m201_StSpeed	 1665	//(internal1_m201_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m201_Vz0	 BUFFER[9446]	//(internal1_m201_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m201_Vz0	 1666	//(internal1_m201_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m201_flRazg	 BUFFER[9451]	//(internal1_m201_flRazg) признак разгона/торможения
#define idinternal1_m201_flRazg	 1667	//(internal1_m201_flRazg) признак разгона/торможения
#define internal1_m201_DelSp	 BUFFER[9454]	//(internal1_m201_DelSp) DelSp - время переключения скоростей
#define idinternal1_m201_DelSp	 1668	//(internal1_m201_DelSp) DelSp - время переключения скоростей
#define internal1_m201_z0	 BUFFER[9459]	//(internal1_m201_z0) z0 - точка прекращения движения
#define idinternal1_m201_z0	 1669	//(internal1_m201_z0) z0 - точка прекращения движения
#define internal1_m201_txZS	 BUFFER[9464]	//(internal1_m201_txZS) txZS
#define idinternal1_m201_txZS	 1670	//(internal1_m201_txZS) txZS
#define internal1_m201_tx	 BUFFER[9469]	//(internal1_m201_tx) tx
#define idinternal1_m201_tx	 1671	//(internal1_m201_tx) tx
#define internal1_m201_txd	 BUFFER[9474]	//(internal1_m201_txd) txd
#define idinternal1_m201_txd	 1672	//(internal1_m201_txd) txd
#define internal1_m201_txMBl	 BUFFER[9479]	//(internal1_m201_txMBl) tx
#define idinternal1_m201_txMBl	 1673	//(internal1_m201_txMBl) tx
#define internal1_m201_txBl	 BUFFER[9484]	//(internal1_m201_txBl) tx
#define idinternal1_m201_txBl	 1674	//(internal1_m201_txBl) tx
#define internal1_m201_Speed0	 BUFFER[9489]	//(internal1_m201_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m201_Speed0	 1675	//(internal1_m201_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m201_xz0	 BUFFER[9494]	//(internal1_m201_xz0) xz0 - новое задание мм
#define idinternal1_m201_xz0	 1676	//(internal1_m201_xz0) xz0 - новое задание мм
#define internal1_m201_tz0	 BUFFER[9499]	//(internal1_m201_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m201_tz0	 1677	//(internal1_m201_tz0) tz0 - время защиты от нового задания сек
#define internal1_m201_Shift0	 BUFFER[9504]	//(internal1_m201_Shift0) Shift0 - признак самохода
#define idinternal1_m201_Shift0	 1678	//(internal1_m201_Shift0) Shift0 - признак самохода
#define internal1_m201_ShCntlSp0	 BUFFER[9506]	//(internal1_m201_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m201_ShCntlSp0	 1679	//(internal1_m201_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m201_ShiftControl	 BUFFER[9508]	//(internal1_m201_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m201_ShiftControl	 1680	//(internal1_m201_ShiftControl) ShiftControl - признак самохода
#define internal1_m720_q0	 BUFFER[9510]	//(internal1_m720_q0) q0 - внутренний параметр
#define idinternal1_m720_q0	 1681	//(internal1_m720_q0) q0 - внутренний параметр
#define internal1_m517_DvUp0	 BUFFER[9512]	//(internal1_m517_DvUp0) - есть команда на движение вперёд
#define idinternal1_m517_DvUp0	 1682	//(internal1_m517_DvUp0) - есть команда на движение вперёд
#define internal1_m517_DvDw0	 BUFFER[9513]	//(internal1_m517_DvDw0) - есть команда на движение назад
#define idinternal1_m517_DvDw0	 1683	//(internal1_m517_DvDw0) - есть команда на движение назад
#define internal1_m517_FDvUp0	 BUFFER[9514]	//(internal1_m517_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m517_FDvUp0	 1684	//(internal1_m517_FDvUp0) - есть команда на движение вперёд
#define internal1_m517_FDvDw0	 BUFFER[9515]	//(internal1_m517_FDvDw0) - есть команда на движение назад
#define idinternal1_m517_FDvDw0	 1685	//(internal1_m517_FDvDw0) - есть команда на движение назад
#define internal1_m517_BlDv0	 BUFFER[9516]	//(internal1_m517_BlDv0) - была блокировка
#define idinternal1_m517_BlDv0	 1686	//(internal1_m517_BlDv0) - была блокировка
#define internal1_m517_Pkv0	 BUFFER[9517]	//(internal1_m517_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m517_Pkv0	 1687	//(internal1_m517_Pkv0) Pkv - передний конечный выключатель
#define internal1_m517_Pkav0	 BUFFER[9518]	//(internal1_m517_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m517_Pkav0	 1688	//(internal1_m517_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m517_Zkv0	 BUFFER[9519]	//(internal1_m517_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m517_Zkv0	 1689	//(internal1_m517_Zkv0) Zkv - задний конечный выключатель
#define internal1_m517_Zkav0	 BUFFER[9520]	//(internal1_m517_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m517_Zkav0	 1690	//(internal1_m517_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m517_txNm	 BUFFER[9521]	//(internal1_m517_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m517_txNm	 1691	//(internal1_m517_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m517_txSm	 BUFFER[9526]	//(internal1_m517_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m517_txSm	 1692	//(internal1_m517_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m517_txHr	 BUFFER[9531]	//(internal1_m517_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m517_txHr	 1693	//(internal1_m517_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m517_txLd	 BUFFER[9536]	//(internal1_m517_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m517_txLd	 1694	//(internal1_m517_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m517_fef	 BUFFER[9541]	//(internal1_m517_fef) fef
#define idinternal1_m517_fef	 1695	//(internal1_m517_fef) fef
#define internal1_m511_DvUp0	 BUFFER[9542]	//(internal1_m511_DvUp0) - есть команда на движение вперёд
#define idinternal1_m511_DvUp0	 1696	//(internal1_m511_DvUp0) - есть команда на движение вперёд
#define internal1_m511_DvDw0	 BUFFER[9543]	//(internal1_m511_DvDw0) - есть команда на движение назад
#define idinternal1_m511_DvDw0	 1697	//(internal1_m511_DvDw0) - есть команда на движение назад
#define internal1_m511_FDvUp0	 BUFFER[9544]	//(internal1_m511_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m511_FDvUp0	 1698	//(internal1_m511_FDvUp0) - есть команда на движение вперёд
#define internal1_m511_FDvDw0	 BUFFER[9545]	//(internal1_m511_FDvDw0) - есть команда на движение назад
#define idinternal1_m511_FDvDw0	 1699	//(internal1_m511_FDvDw0) - есть команда на движение назад
#define internal1_m511_BlDv0	 BUFFER[9546]	//(internal1_m511_BlDv0) - была блокировка
#define idinternal1_m511_BlDv0	 1700	//(internal1_m511_BlDv0) - была блокировка
#define internal1_m511_Pkv0	 BUFFER[9547]	//(internal1_m511_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m511_Pkv0	 1701	//(internal1_m511_Pkv0) Pkv - передний конечный выключатель
#define internal1_m511_Pkav0	 BUFFER[9548]	//(internal1_m511_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m511_Pkav0	 1702	//(internal1_m511_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m511_Zkv0	 BUFFER[9549]	//(internal1_m511_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m511_Zkv0	 1703	//(internal1_m511_Zkv0) Zkv - задний конечный выключатель
#define internal1_m511_Zkav0	 BUFFER[9550]	//(internal1_m511_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m511_Zkav0	 1704	//(internal1_m511_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m511_txNm	 BUFFER[9551]	//(internal1_m511_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m511_txNm	 1705	//(internal1_m511_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m511_txSm	 BUFFER[9556]	//(internal1_m511_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m511_txSm	 1706	//(internal1_m511_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m511_txHr	 BUFFER[9561]	//(internal1_m511_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m511_txHr	 1707	//(internal1_m511_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m511_txLd	 BUFFER[9566]	//(internal1_m511_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m511_txLd	 1708	//(internal1_m511_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m511_fef	 BUFFER[9571]	//(internal1_m511_fef) fef
#define idinternal1_m511_fef	 1709	//(internal1_m511_fef) fef
#define internal1_m909_X0	 BUFFER[9572]	//(internal1_m909_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m909_X0	 1710	//(internal1_m909_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m909_t0	 BUFFER[9577]	//(internal1_m909_t0) время нахождения в зоне возврата
#define idinternal1_m909_t0	 1711	//(internal1_m909_t0) время нахождения в зоне возврата
#define internal1_m909_BLDv0	 BUFFER[9582]	//(internal1_m909_BLDv0) BlDv - Блокировка движения
#define idinternal1_m909_BLDv0	 1712	//(internal1_m909_BLDv0) BlDv - Блокировка движения
#define internal1_m927_xptr	 BUFFER[9583]	//(internal1_m927_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m927_xptr	 1713	//(internal1_m927_xptr) указатель текущей позиции в массиве координат
#define internal1_m927_x0	 BUFFER[9586]	//(internal1_m927_x0) x0 - массив мгновенных значений координат
#define idinternal1_m927_x0	 1714	//(internal1_m927_x0) x0 - массив мгновенных значений координат
#define internal1_m927_tim0	 BUFFER[9986]	//(internal1_m927_tim0) tim0 - массив значений времени цикла
#define idinternal1_m927_tim0	 1715	//(internal1_m927_tim0) tim0 - массив значений времени цикла
#define internal1_m927_sumtim	 BUFFER[10386]	//(internal1_m927_sumtim) sumtim - время в пути
#define idinternal1_m927_sumtim	 1716	//(internal1_m927_sumtim) sumtim - время в пути
#define internal1_m927_StSpeed	 BUFFER[10391]	//(internal1_m927_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m927_StSpeed	 1717	//(internal1_m927_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m927_Vz0	 BUFFER[10396]	//(internal1_m927_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m927_Vz0	 1718	//(internal1_m927_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m927_flRazg	 BUFFER[10401]	//(internal1_m927_flRazg) признак разгона/торможения
#define idinternal1_m927_flRazg	 1719	//(internal1_m927_flRazg) признак разгона/торможения
#define internal1_m927_DelSp	 BUFFER[10404]	//(internal1_m927_DelSp) DelSp - время переключения скоростей
#define idinternal1_m927_DelSp	 1720	//(internal1_m927_DelSp) DelSp - время переключения скоростей
#define internal1_m927_z0	 BUFFER[10409]	//(internal1_m927_z0) z0 - точка прекращения движения
#define idinternal1_m927_z0	 1721	//(internal1_m927_z0) z0 - точка прекращения движения
#define internal1_m927_txZS	 BUFFER[10414]	//(internal1_m927_txZS) txZS
#define idinternal1_m927_txZS	 1722	//(internal1_m927_txZS) txZS
#define internal1_m927_tx	 BUFFER[10419]	//(internal1_m927_tx) tx
#define idinternal1_m927_tx	 1723	//(internal1_m927_tx) tx
#define internal1_m927_txd	 BUFFER[10424]	//(internal1_m927_txd) txd
#define idinternal1_m927_txd	 1724	//(internal1_m927_txd) txd
#define internal1_m927_txMBl	 BUFFER[10429]	//(internal1_m927_txMBl) tx
#define idinternal1_m927_txMBl	 1725	//(internal1_m927_txMBl) tx
#define internal1_m927_txBl	 BUFFER[10434]	//(internal1_m927_txBl) tx
#define idinternal1_m927_txBl	 1726	//(internal1_m927_txBl) tx
#define internal1_m927_Speed0	 BUFFER[10439]	//(internal1_m927_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m927_Speed0	 1727	//(internal1_m927_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m927_xz0	 BUFFER[10444]	//(internal1_m927_xz0) xz0 - новое задание мм
#define idinternal1_m927_xz0	 1728	//(internal1_m927_xz0) xz0 - новое задание мм
#define internal1_m927_tz0	 BUFFER[10449]	//(internal1_m927_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m927_tz0	 1729	//(internal1_m927_tz0) tz0 - время защиты от нового задания сек
#define internal1_m927_Shift0	 BUFFER[10454]	//(internal1_m927_Shift0) Shift0 - признак самохода
#define idinternal1_m927_Shift0	 1730	//(internal1_m927_Shift0) Shift0 - признак самохода
#define internal1_m927_ShCntlSp0	 BUFFER[10456]	//(internal1_m927_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m927_ShCntlSp0	 1731	//(internal1_m927_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m927_ShiftControl	 BUFFER[10458]	//(internal1_m927_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m927_ShiftControl	 1732	//(internal1_m927_ShiftControl) ShiftControl - признак самохода
#define internal1_m1804_X0	 BUFFER[10460]	//(internal1_m1804_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1804_X0	 1733	//(internal1_m1804_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1804_t0	 BUFFER[10465]	//(internal1_m1804_t0) время нахождения в зоне возврата
#define idinternal1_m1804_t0	 1734	//(internal1_m1804_t0) время нахождения в зоне возврата
#define internal1_m1804_BLDv0	 BUFFER[10470]	//(internal1_m1804_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1804_BLDv0	 1735	//(internal1_m1804_BLDv0) BlDv - Блокировка движения
#define internal1_m1273_X0	 BUFFER[10471]	//(internal1_m1273_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1273_X0	 1736	//(internal1_m1273_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1273_t0	 BUFFER[10476]	//(internal1_m1273_t0) время нахождения в зоне возврата
#define idinternal1_m1273_t0	 1737	//(internal1_m1273_t0) время нахождения в зоне возврата
#define internal1_m1273_BLDv0	 BUFFER[10481]	//(internal1_m1273_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1273_BLDv0	 1738	//(internal1_m1273_BLDv0) BlDv - Блокировка движения
#define internal1_m692_q0	 BUFFER[10482]	//(internal1_m692_q0) q0 - внутренний параметр
#define idinternal1_m692_q0	 1739	//(internal1_m692_q0) q0 - внутренний параметр
#define internal1_m1370_X0	 BUFFER[10484]	//(internal1_m1370_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1370_X0	 1740	//(internal1_m1370_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1370_t0	 BUFFER[10489]	//(internal1_m1370_t0) время нахождения в зоне возврата
#define idinternal1_m1370_t0	 1741	//(internal1_m1370_t0) время нахождения в зоне возврата
#define internal1_m1370_BLDv0	 BUFFER[10494]	//(internal1_m1370_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1370_BLDv0	 1742	//(internal1_m1370_BLDv0) BlDv - Блокировка движения
#define internal1_m1398_tx	 BUFFER[10495]	//(internal1_m1398_tx) tx - время накопленное сек
#define idinternal1_m1398_tx	 1743	//(internal1_m1398_tx) tx - время накопленное сек
#define internal1_m1398_y0	 BUFFER[10500]	//(internal1_m1398_y0) y0
#define idinternal1_m1398_y0	 1744	//(internal1_m1398_y0) y0
#define internal1_m1397_tx	 BUFFER[10501]	//(internal1_m1397_tx) tx - время накопленное сек
#define idinternal1_m1397_tx	 1745	//(internal1_m1397_tx) tx - время накопленное сек
#define internal1_m1397_y0	 BUFFER[10506]	//(internal1_m1397_y0) y0
#define idinternal1_m1397_y0	 1746	//(internal1_m1397_y0) y0
#define internal1_m1405_xptr	 BUFFER[10507]	//(internal1_m1405_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1405_xptr	 1747	//(internal1_m1405_xptr) указатель текущей позиции в массиве координат
#define internal1_m1405_x0	 BUFFER[10510]	//(internal1_m1405_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1405_x0	 1748	//(internal1_m1405_x0) x0 - массив мгновенных значений координат
#define internal1_m1405_tim0	 BUFFER[10910]	//(internal1_m1405_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1405_tim0	 1749	//(internal1_m1405_tim0) tim0 - массив значений времени цикла
#define internal1_m1405_sumtim	 BUFFER[11310]	//(internal1_m1405_sumtim) sumtim - время в пути
#define idinternal1_m1405_sumtim	 1750	//(internal1_m1405_sumtim) sumtim - время в пути
#define internal1_m1405_StSpeed	 BUFFER[11315]	//(internal1_m1405_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1405_StSpeed	 1751	//(internal1_m1405_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1405_Vz0	 BUFFER[11320]	//(internal1_m1405_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1405_Vz0	 1752	//(internal1_m1405_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1405_flRazg	 BUFFER[11325]	//(internal1_m1405_flRazg) признак разгона/торможения
#define idinternal1_m1405_flRazg	 1753	//(internal1_m1405_flRazg) признак разгона/торможения
#define internal1_m1405_DelSp	 BUFFER[11328]	//(internal1_m1405_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1405_DelSp	 1754	//(internal1_m1405_DelSp) DelSp - время переключения скоростей
#define internal1_m1405_z0	 BUFFER[11333]	//(internal1_m1405_z0) z0 - точка прекращения движения
#define idinternal1_m1405_z0	 1755	//(internal1_m1405_z0) z0 - точка прекращения движения
#define internal1_m1405_txZS	 BUFFER[11338]	//(internal1_m1405_txZS) txZS
#define idinternal1_m1405_txZS	 1756	//(internal1_m1405_txZS) txZS
#define internal1_m1405_tx	 BUFFER[11343]	//(internal1_m1405_tx) tx
#define idinternal1_m1405_tx	 1757	//(internal1_m1405_tx) tx
#define internal1_m1405_txd	 BUFFER[11348]	//(internal1_m1405_txd) txd
#define idinternal1_m1405_txd	 1758	//(internal1_m1405_txd) txd
#define internal1_m1405_txMBl	 BUFFER[11353]	//(internal1_m1405_txMBl) tx
#define idinternal1_m1405_txMBl	 1759	//(internal1_m1405_txMBl) tx
#define internal1_m1405_txBl	 BUFFER[11358]	//(internal1_m1405_txBl) tx
#define idinternal1_m1405_txBl	 1760	//(internal1_m1405_txBl) tx
#define internal1_m1405_Speed0	 BUFFER[11363]	//(internal1_m1405_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1405_Speed0	 1761	//(internal1_m1405_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1405_xz0	 BUFFER[11368]	//(internal1_m1405_xz0) xz0 - новое задание мм
#define idinternal1_m1405_xz0	 1762	//(internal1_m1405_xz0) xz0 - новое задание мм
#define internal1_m1405_tz0	 BUFFER[11373]	//(internal1_m1405_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1405_tz0	 1763	//(internal1_m1405_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1405_Shift0	 BUFFER[11378]	//(internal1_m1405_Shift0) Shift0 - признак самохода
#define idinternal1_m1405_Shift0	 1764	//(internal1_m1405_Shift0) Shift0 - признак самохода
#define internal1_m1405_ShCntlSp0	 BUFFER[11380]	//(internal1_m1405_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1405_ShCntlSp0	 1765	//(internal1_m1405_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1405_ShiftControl	 BUFFER[11382]	//(internal1_m1405_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1405_ShiftControl	 1766	//(internal1_m1405_ShiftControl) ShiftControl - признак самохода
#define internal1_m712_q0	 BUFFER[11384]	//(internal1_m712_q0) q0 - внутренний параметр
#define idinternal1_m712_q0	 1767	//(internal1_m712_q0) q0 - внутренний параметр
#define internal1_m1818_tx	 BUFFER[11386]	//(internal1_m1818_tx) tx - время накопленное сек
#define idinternal1_m1818_tx	 1768	//(internal1_m1818_tx) tx - время накопленное сек
#define internal1_m1818_y0	 BUFFER[11391]	//(internal1_m1818_y0) y0
#define idinternal1_m1818_y0	 1769	//(internal1_m1818_y0) y0
#define internal1_m1822_tx	 BUFFER[11392]	//(internal1_m1822_tx) tx - время накопленное сек
#define idinternal1_m1822_tx	 1770	//(internal1_m1822_tx) tx - время накопленное сек
#define internal1_m1822_y0	 BUFFER[11397]	//(internal1_m1822_y0) y0
#define idinternal1_m1822_y0	 1771	//(internal1_m1822_y0) y0
#define internal1_m1807_DvUp0	 BUFFER[11398]	//(internal1_m1807_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1807_DvUp0	 1772	//(internal1_m1807_DvUp0) - есть команда на движение вперёд
#define internal1_m1807_DvDw0	 BUFFER[11399]	//(internal1_m1807_DvDw0) - есть команда на движение назад
#define idinternal1_m1807_DvDw0	 1773	//(internal1_m1807_DvDw0) - есть команда на движение назад
#define internal1_m1807_FDvUp0	 BUFFER[11400]	//(internal1_m1807_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1807_FDvUp0	 1774	//(internal1_m1807_FDvUp0) - есть команда на движение вперёд
#define internal1_m1807_FDvDw0	 BUFFER[11401]	//(internal1_m1807_FDvDw0) - есть команда на движение назад
#define idinternal1_m1807_FDvDw0	 1775	//(internal1_m1807_FDvDw0) - есть команда на движение назад
#define internal1_m1807_BlDv0	 BUFFER[11402]	//(internal1_m1807_BlDv0) - была блокировка
#define idinternal1_m1807_BlDv0	 1776	//(internal1_m1807_BlDv0) - была блокировка
#define internal1_m1807_Pkv0	 BUFFER[11403]	//(internal1_m1807_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1807_Pkv0	 1777	//(internal1_m1807_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1807_Pkav0	 BUFFER[11404]	//(internal1_m1807_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1807_Pkav0	 1778	//(internal1_m1807_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1807_Zkv0	 BUFFER[11405]	//(internal1_m1807_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1807_Zkv0	 1779	//(internal1_m1807_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1807_Zkav0	 BUFFER[11406]	//(internal1_m1807_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1807_Zkav0	 1780	//(internal1_m1807_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1807_txNm	 BUFFER[11407]	//(internal1_m1807_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1807_txNm	 1781	//(internal1_m1807_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1807_txSm	 BUFFER[11412]	//(internal1_m1807_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1807_txSm	 1782	//(internal1_m1807_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1807_txHr	 BUFFER[11417]	//(internal1_m1807_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1807_txHr	 1783	//(internal1_m1807_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1807_txLd	 BUFFER[11422]	//(internal1_m1807_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1807_txLd	 1784	//(internal1_m1807_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1807_fef	 BUFFER[11427]	//(internal1_m1807_fef) fef
#define idinternal1_m1807_fef	 1785	//(internal1_m1807_fef) fef
#define internal1_m1826_xptr	 BUFFER[11428]	//(internal1_m1826_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1826_xptr	 1786	//(internal1_m1826_xptr) указатель текущей позиции в массиве координат
#define internal1_m1826_x0	 BUFFER[11431]	//(internal1_m1826_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1826_x0	 1787	//(internal1_m1826_x0) x0 - массив мгновенных значений координат
#define internal1_m1826_tim0	 BUFFER[11531]	//(internal1_m1826_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1826_tim0	 1788	//(internal1_m1826_tim0) tim0 - массив значений времени цикла
#define internal1_m1826_sumtim	 BUFFER[11631]	//(internal1_m1826_sumtim) sumtim - время в пути
#define idinternal1_m1826_sumtim	 1789	//(internal1_m1826_sumtim) sumtim - время в пути
#define internal1_m1826_StSpeed	 BUFFER[11636]	//(internal1_m1826_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1826_StSpeed	 1790	//(internal1_m1826_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1826_Vz0	 BUFFER[11641]	//(internal1_m1826_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1826_Vz0	 1791	//(internal1_m1826_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1826_flRazg	 BUFFER[11646]	//(internal1_m1826_flRazg) признак разгона/торможения
#define idinternal1_m1826_flRazg	 1792	//(internal1_m1826_flRazg) признак разгона/торможения
#define internal1_m1826_DelSp	 BUFFER[11649]	//(internal1_m1826_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1826_DelSp	 1793	//(internal1_m1826_DelSp) DelSp - время переключения скоростей
#define internal1_m1826_z0	 BUFFER[11654]	//(internal1_m1826_z0) z0 - точка прекращения движения
#define idinternal1_m1826_z0	 1794	//(internal1_m1826_z0) z0 - точка прекращения движения
#define internal1_m1826_txZS	 BUFFER[11659]	//(internal1_m1826_txZS) txZS
#define idinternal1_m1826_txZS	 1795	//(internal1_m1826_txZS) txZS
#define internal1_m1826_tx	 BUFFER[11664]	//(internal1_m1826_tx) tx
#define idinternal1_m1826_tx	 1796	//(internal1_m1826_tx) tx
#define internal1_m1826_txd	 BUFFER[11669]	//(internal1_m1826_txd) txd
#define idinternal1_m1826_txd	 1797	//(internal1_m1826_txd) txd
#define internal1_m1826_txMBl	 BUFFER[11674]	//(internal1_m1826_txMBl) tx
#define idinternal1_m1826_txMBl	 1798	//(internal1_m1826_txMBl) tx
#define internal1_m1826_txBl	 BUFFER[11679]	//(internal1_m1826_txBl) tx
#define idinternal1_m1826_txBl	 1799	//(internal1_m1826_txBl) tx
#define internal1_m1826_Speed0	 BUFFER[11684]	//(internal1_m1826_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1826_Speed0	 1800	//(internal1_m1826_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1826_xz0	 BUFFER[11689]	//(internal1_m1826_xz0) xz0 - новое задание мм
#define idinternal1_m1826_xz0	 1801	//(internal1_m1826_xz0) xz0 - новое задание мм
#define internal1_m1826_tz0	 BUFFER[11694]	//(internal1_m1826_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1826_tz0	 1802	//(internal1_m1826_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1826_Shift0	 BUFFER[11699]	//(internal1_m1826_Shift0) Shift0 - признак самохода
#define idinternal1_m1826_Shift0	 1803	//(internal1_m1826_Shift0) Shift0 - признак самохода
#define internal1_m1826_ShCntlSp0	 BUFFER[11701]	//(internal1_m1826_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1826_ShCntlSp0	 1804	//(internal1_m1826_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1826_ShiftControl	 BUFFER[11703]	//(internal1_m1826_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1826_ShiftControl	 1805	//(internal1_m1826_ShiftControl) ShiftControl - признак самохода
#define internal1_m1290_tx	 BUFFER[11705]	//(internal1_m1290_tx) tx - время накопленное сек
#define idinternal1_m1290_tx	 1806	//(internal1_m1290_tx) tx - время накопленное сек
#define internal1_m1290_y0	 BUFFER[11710]	//(internal1_m1290_y0) y0
#define idinternal1_m1290_y0	 1807	//(internal1_m1290_y0) y0
#define internal1_m1294_tx	 BUFFER[11711]	//(internal1_m1294_tx) tx - время накопленное сек
#define idinternal1_m1294_tx	 1808	//(internal1_m1294_tx) tx - время накопленное сек
#define internal1_m1294_y0	 BUFFER[11716]	//(internal1_m1294_y0) y0
#define idinternal1_m1294_y0	 1809	//(internal1_m1294_y0) y0
#define internal1_m702_q0	 BUFFER[11717]	//(internal1_m702_q0) q0 - внутренний параметр
#define idinternal1_m702_q0	 1810	//(internal1_m702_q0) q0 - внутренний параметр
#define internal1_m667_q0	 BUFFER[11719]	//(internal1_m667_q0) q0 - внутренний параметр
#define idinternal1_m667_q0	 1811	//(internal1_m667_q0) q0 - внутренний параметр
#define internal1_m1281_DvUp0	 BUFFER[11721]	//(internal1_m1281_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1281_DvUp0	 1812	//(internal1_m1281_DvUp0) - есть команда на движение вперёд
#define internal1_m1281_DvDw0	 BUFFER[11722]	//(internal1_m1281_DvDw0) - есть команда на движение назад
#define idinternal1_m1281_DvDw0	 1813	//(internal1_m1281_DvDw0) - есть команда на движение назад
#define internal1_m1281_FDvUp0	 BUFFER[11723]	//(internal1_m1281_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1281_FDvUp0	 1814	//(internal1_m1281_FDvUp0) - есть команда на движение вперёд
#define internal1_m1281_FDvDw0	 BUFFER[11724]	//(internal1_m1281_FDvDw0) - есть команда на движение назад
#define idinternal1_m1281_FDvDw0	 1815	//(internal1_m1281_FDvDw0) - есть команда на движение назад
#define internal1_m1281_BlDv0	 BUFFER[11725]	//(internal1_m1281_BlDv0) - была блокировка
#define idinternal1_m1281_BlDv0	 1816	//(internal1_m1281_BlDv0) - была блокировка
#define internal1_m1281_Pkv0	 BUFFER[11726]	//(internal1_m1281_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1281_Pkv0	 1817	//(internal1_m1281_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1281_Pkav0	 BUFFER[11727]	//(internal1_m1281_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1281_Pkav0	 1818	//(internal1_m1281_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1281_Zkv0	 BUFFER[11728]	//(internal1_m1281_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1281_Zkv0	 1819	//(internal1_m1281_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1281_Zkav0	 BUFFER[11729]	//(internal1_m1281_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1281_Zkav0	 1820	//(internal1_m1281_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1281_txNm	 BUFFER[11730]	//(internal1_m1281_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1281_txNm	 1821	//(internal1_m1281_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1281_txSm	 BUFFER[11735]	//(internal1_m1281_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1281_txSm	 1822	//(internal1_m1281_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1281_txHr	 BUFFER[11740]	//(internal1_m1281_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1281_txHr	 1823	//(internal1_m1281_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1281_txLd	 BUFFER[11745]	//(internal1_m1281_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1281_txLd	 1824	//(internal1_m1281_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1281_fef	 BUFFER[11750]	//(internal1_m1281_fef) fef
#define idinternal1_m1281_fef	 1825	//(internal1_m1281_fef) fef
#define internal1_m1300_xptr	 BUFFER[11751]	//(internal1_m1300_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1300_xptr	 1826	//(internal1_m1300_xptr) указатель текущей позиции в массиве координат
#define internal1_m1300_x0	 BUFFER[11754]	//(internal1_m1300_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1300_x0	 1827	//(internal1_m1300_x0) x0 - массив мгновенных значений координат
#define internal1_m1300_tim0	 BUFFER[11854]	//(internal1_m1300_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1300_tim0	 1828	//(internal1_m1300_tim0) tim0 - массив значений времени цикла
#define internal1_m1300_sumtim	 BUFFER[11954]	//(internal1_m1300_sumtim) sumtim - время в пути
#define idinternal1_m1300_sumtim	 1829	//(internal1_m1300_sumtim) sumtim - время в пути
#define internal1_m1300_StSpeed	 BUFFER[11959]	//(internal1_m1300_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1300_StSpeed	 1830	//(internal1_m1300_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1300_Vz0	 BUFFER[11964]	//(internal1_m1300_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1300_Vz0	 1831	//(internal1_m1300_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1300_flRazg	 BUFFER[11969]	//(internal1_m1300_flRazg) признак разгона/торможения
#define idinternal1_m1300_flRazg	 1832	//(internal1_m1300_flRazg) признак разгона/торможения
#define internal1_m1300_DelSp	 BUFFER[11972]	//(internal1_m1300_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1300_DelSp	 1833	//(internal1_m1300_DelSp) DelSp - время переключения скоростей
#define internal1_m1300_z0	 BUFFER[11977]	//(internal1_m1300_z0) z0 - точка прекращения движения
#define idinternal1_m1300_z0	 1834	//(internal1_m1300_z0) z0 - точка прекращения движения
#define internal1_m1300_txZS	 BUFFER[11982]	//(internal1_m1300_txZS) txZS
#define idinternal1_m1300_txZS	 1835	//(internal1_m1300_txZS) txZS
#define internal1_m1300_tx	 BUFFER[11987]	//(internal1_m1300_tx) tx
#define idinternal1_m1300_tx	 1836	//(internal1_m1300_tx) tx
#define internal1_m1300_txd	 BUFFER[11992]	//(internal1_m1300_txd) txd
#define idinternal1_m1300_txd	 1837	//(internal1_m1300_txd) txd
#define internal1_m1300_txMBl	 BUFFER[11997]	//(internal1_m1300_txMBl) tx
#define idinternal1_m1300_txMBl	 1838	//(internal1_m1300_txMBl) tx
#define internal1_m1300_txBl	 BUFFER[12002]	//(internal1_m1300_txBl) tx
#define idinternal1_m1300_txBl	 1839	//(internal1_m1300_txBl) tx
#define internal1_m1300_Speed0	 BUFFER[12007]	//(internal1_m1300_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1300_Speed0	 1840	//(internal1_m1300_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1300_xz0	 BUFFER[12012]	//(internal1_m1300_xz0) xz0 - новое задание мм
#define idinternal1_m1300_xz0	 1841	//(internal1_m1300_xz0) xz0 - новое задание мм
#define internal1_m1300_tz0	 BUFFER[12017]	//(internal1_m1300_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1300_tz0	 1842	//(internal1_m1300_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1300_Shift0	 BUFFER[12022]	//(internal1_m1300_Shift0) Shift0 - признак самохода
#define idinternal1_m1300_Shift0	 1843	//(internal1_m1300_Shift0) Shift0 - признак самохода
#define internal1_m1300_ShCntlSp0	 BUFFER[12024]	//(internal1_m1300_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1300_ShCntlSp0	 1844	//(internal1_m1300_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1300_ShiftControl	 BUFFER[12026]	//(internal1_m1300_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1300_ShiftControl	 1845	//(internal1_m1300_ShiftControl) ShiftControl - признак самохода
#define internal1_m830_x0	 BUFFER[12028]	//(internal1_m830_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m830_x0	 1846	//(internal1_m830_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m799_x0	 BUFFER[12030]	//(internal1_m799_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m799_x0	 1847	//(internal1_m799_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m741_x0	 BUFFER[12032]	//(internal1_m741_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m741_x0	 1848	//(internal1_m741_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m855_q0	 BUFFER[12034]	//(internal1_m855_q0) q0 - внутренний параметр
#define idinternal1_m855_q0	 1849	//(internal1_m855_q0) q0 - внутренний параметр
#define internal1_m850_q0	 BUFFER[12036]	//(internal1_m850_q0) q0 - внутренний параметр
#define idinternal1_m850_q0	 1850	//(internal1_m850_q0) q0 - внутренний параметр
#define internal1_m818_q0	 BUFFER[12038]	//(internal1_m818_q0) q0 - внутренний параметр
#define idinternal1_m818_q0	 1851	//(internal1_m818_q0) q0 - внутренний параметр
#define internal1_m822_q0	 BUFFER[12040]	//(internal1_m822_q0) q0 - внутренний параметр
#define idinternal1_m822_q0	 1852	//(internal1_m822_q0) q0 - внутренний параметр
#define internal1_m831_q0	 BUFFER[12042]	//(internal1_m831_q0) q0 - внутренний параметр
#define idinternal1_m831_q0	 1853	//(internal1_m831_q0) q0 - внутренний параметр
#define internal1_m843_q0	 BUFFER[12044]	//(internal1_m843_q0) q0 - внутренний параметр
#define idinternal1_m843_q0	 1854	//(internal1_m843_q0) q0 - внутренний параметр
#define internal1_m820_q0	 BUFFER[12046]	//(internal1_m820_q0) q0 - внутренний параметр
#define idinternal1_m820_q0	 1855	//(internal1_m820_q0) q0 - внутренний параметр
#define internal1_m1343_DvUp0	 BUFFER[12048]	//(internal1_m1343_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1343_DvUp0	 1856	//(internal1_m1343_DvUp0) - есть команда на движение вперёд
#define internal1_m1343_DvDw0	 BUFFER[12049]	//(internal1_m1343_DvDw0) - есть команда на движение назад
#define idinternal1_m1343_DvDw0	 1857	//(internal1_m1343_DvDw0) - есть команда на движение назад
#define internal1_m1343_FDvUp0	 BUFFER[12050]	//(internal1_m1343_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1343_FDvUp0	 1858	//(internal1_m1343_FDvUp0) - есть команда на движение вперёд
#define internal1_m1343_FDvDw0	 BUFFER[12051]	//(internal1_m1343_FDvDw0) - есть команда на движение назад
#define idinternal1_m1343_FDvDw0	 1859	//(internal1_m1343_FDvDw0) - есть команда на движение назад
#define internal1_m1343_BlDv0	 BUFFER[12052]	//(internal1_m1343_BlDv0) - была блокировка
#define idinternal1_m1343_BlDv0	 1860	//(internal1_m1343_BlDv0) - была блокировка
#define internal1_m1343_Pkv0	 BUFFER[12053]	//(internal1_m1343_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1343_Pkv0	 1861	//(internal1_m1343_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1343_Pkav0	 BUFFER[12054]	//(internal1_m1343_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1343_Pkav0	 1862	//(internal1_m1343_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1343_Zkv0	 BUFFER[12055]	//(internal1_m1343_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1343_Zkv0	 1863	//(internal1_m1343_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1343_Zkav0	 BUFFER[12056]	//(internal1_m1343_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1343_Zkav0	 1864	//(internal1_m1343_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1343_txNm	 BUFFER[12057]	//(internal1_m1343_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1343_txNm	 1865	//(internal1_m1343_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1343_txSm	 BUFFER[12062]	//(internal1_m1343_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1343_txSm	 1866	//(internal1_m1343_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1343_txHr	 BUFFER[12067]	//(internal1_m1343_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1343_txHr	 1867	//(internal1_m1343_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1343_txLd	 BUFFER[12072]	//(internal1_m1343_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1343_txLd	 1868	//(internal1_m1343_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1343_fef	 BUFFER[12077]	//(internal1_m1343_fef) fef
#define idinternal1_m1343_fef	 1869	//(internal1_m1343_fef) fef
#define internal1_m1333_DvUp0	 BUFFER[12078]	//(internal1_m1333_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1333_DvUp0	 1870	//(internal1_m1333_DvUp0) - есть команда на движение вперёд
#define internal1_m1333_DvDw0	 BUFFER[12079]	//(internal1_m1333_DvDw0) - есть команда на движение назад
#define idinternal1_m1333_DvDw0	 1871	//(internal1_m1333_DvDw0) - есть команда на движение назад
#define internal1_m1333_FDvUp0	 BUFFER[12080]	//(internal1_m1333_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1333_FDvUp0	 1872	//(internal1_m1333_FDvUp0) - есть команда на движение вперёд
#define internal1_m1333_FDvDw0	 BUFFER[12081]	//(internal1_m1333_FDvDw0) - есть команда на движение назад
#define idinternal1_m1333_FDvDw0	 1873	//(internal1_m1333_FDvDw0) - есть команда на движение назад
#define internal1_m1333_BlDv0	 BUFFER[12082]	//(internal1_m1333_BlDv0) - была блокировка
#define idinternal1_m1333_BlDv0	 1874	//(internal1_m1333_BlDv0) - была блокировка
#define internal1_m1333_Pkv0	 BUFFER[12083]	//(internal1_m1333_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1333_Pkv0	 1875	//(internal1_m1333_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1333_Pkav0	 BUFFER[12084]	//(internal1_m1333_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1333_Pkav0	 1876	//(internal1_m1333_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1333_Zkv0	 BUFFER[12085]	//(internal1_m1333_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1333_Zkv0	 1877	//(internal1_m1333_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1333_Zkav0	 BUFFER[12086]	//(internal1_m1333_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1333_Zkav0	 1878	//(internal1_m1333_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1333_txNm	 BUFFER[12087]	//(internal1_m1333_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1333_txNm	 1879	//(internal1_m1333_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1333_txSm	 BUFFER[12092]	//(internal1_m1333_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1333_txSm	 1880	//(internal1_m1333_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1333_txHr	 BUFFER[12097]	//(internal1_m1333_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1333_txHr	 1881	//(internal1_m1333_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1333_txLd	 BUFFER[12102]	//(internal1_m1333_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1333_txLd	 1882	//(internal1_m1333_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1333_fef	 BUFFER[12107]	//(internal1_m1333_fef) fef
#define idinternal1_m1333_fef	 1883	//(internal1_m1333_fef) fef
#define internal1_m879_DvUp0	 BUFFER[12108]	//(internal1_m879_DvUp0) - есть команда на движение вперёд
#define idinternal1_m879_DvUp0	 1884	//(internal1_m879_DvUp0) - есть команда на движение вперёд
#define internal1_m879_DvDw0	 BUFFER[12109]	//(internal1_m879_DvDw0) - есть команда на движение назад
#define idinternal1_m879_DvDw0	 1885	//(internal1_m879_DvDw0) - есть команда на движение назад
#define internal1_m879_FDvUp0	 BUFFER[12110]	//(internal1_m879_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m879_FDvUp0	 1886	//(internal1_m879_FDvUp0) - есть команда на движение вперёд
#define internal1_m879_FDvDw0	 BUFFER[12111]	//(internal1_m879_FDvDw0) - есть команда на движение назад
#define idinternal1_m879_FDvDw0	 1887	//(internal1_m879_FDvDw0) - есть команда на движение назад
#define internal1_m879_BlDv0	 BUFFER[12112]	//(internal1_m879_BlDv0) - была блокировка
#define idinternal1_m879_BlDv0	 1888	//(internal1_m879_BlDv0) - была блокировка
#define internal1_m879_Pkv0	 BUFFER[12113]	//(internal1_m879_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m879_Pkv0	 1889	//(internal1_m879_Pkv0) Pkv - передний конечный выключатель
#define internal1_m879_Pkav0	 BUFFER[12114]	//(internal1_m879_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m879_Pkav0	 1890	//(internal1_m879_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m879_Zkv0	 BUFFER[12115]	//(internal1_m879_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m879_Zkv0	 1891	//(internal1_m879_Zkv0) Zkv - задний конечный выключатель
#define internal1_m879_Zkav0	 BUFFER[12116]	//(internal1_m879_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m879_Zkav0	 1892	//(internal1_m879_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m879_txNm	 BUFFER[12117]	//(internal1_m879_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m879_txNm	 1893	//(internal1_m879_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m879_txSm	 BUFFER[12122]	//(internal1_m879_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m879_txSm	 1894	//(internal1_m879_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m879_txHr	 BUFFER[12127]	//(internal1_m879_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m879_txHr	 1895	//(internal1_m879_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m879_txLd	 BUFFER[12132]	//(internal1_m879_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m879_txLd	 1896	//(internal1_m879_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m879_fef	 BUFFER[12137]	//(internal1_m879_fef) fef
#define idinternal1_m879_fef	 1897	//(internal1_m879_fef) fef
#define internal1_m875_DvUp0	 BUFFER[12138]	//(internal1_m875_DvUp0) - есть команда на движение вперёд
#define idinternal1_m875_DvUp0	 1898	//(internal1_m875_DvUp0) - есть команда на движение вперёд
#define internal1_m875_DvDw0	 BUFFER[12139]	//(internal1_m875_DvDw0) - есть команда на движение назад
#define idinternal1_m875_DvDw0	 1899	//(internal1_m875_DvDw0) - есть команда на движение назад
#define internal1_m875_FDvUp0	 BUFFER[12140]	//(internal1_m875_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m875_FDvUp0	 1900	//(internal1_m875_FDvUp0) - есть команда на движение вперёд
#define internal1_m875_FDvDw0	 BUFFER[12141]	//(internal1_m875_FDvDw0) - есть команда на движение назад
#define idinternal1_m875_FDvDw0	 1901	//(internal1_m875_FDvDw0) - есть команда на движение назад
#define internal1_m875_BlDv0	 BUFFER[12142]	//(internal1_m875_BlDv0) - была блокировка
#define idinternal1_m875_BlDv0	 1902	//(internal1_m875_BlDv0) - была блокировка
#define internal1_m875_Pkv0	 BUFFER[12143]	//(internal1_m875_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m875_Pkv0	 1903	//(internal1_m875_Pkv0) Pkv - передний конечный выключатель
#define internal1_m875_Pkav0	 BUFFER[12144]	//(internal1_m875_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m875_Pkav0	 1904	//(internal1_m875_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m875_Zkv0	 BUFFER[12145]	//(internal1_m875_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m875_Zkv0	 1905	//(internal1_m875_Zkv0) Zkv - задний конечный выключатель
#define internal1_m875_Zkav0	 BUFFER[12146]	//(internal1_m875_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m875_Zkav0	 1906	//(internal1_m875_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m875_txNm	 BUFFER[12147]	//(internal1_m875_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m875_txNm	 1907	//(internal1_m875_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m875_txSm	 BUFFER[12152]	//(internal1_m875_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m875_txSm	 1908	//(internal1_m875_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m875_txHr	 BUFFER[12157]	//(internal1_m875_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m875_txHr	 1909	//(internal1_m875_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m875_txLd	 BUFFER[12162]	//(internal1_m875_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m875_txLd	 1910	//(internal1_m875_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m875_fef	 BUFFER[12167]	//(internal1_m875_fef) fef
#define idinternal1_m875_fef	 1911	//(internal1_m875_fef) fef
#define internal1_m390_DvUp0	 BUFFER[12168]	//(internal1_m390_DvUp0) - есть команда на движение вперёд
#define idinternal1_m390_DvUp0	 1912	//(internal1_m390_DvUp0) - есть команда на движение вперёд
#define internal1_m390_DvDw0	 BUFFER[12169]	//(internal1_m390_DvDw0) - есть команда на движение назад
#define idinternal1_m390_DvDw0	 1913	//(internal1_m390_DvDw0) - есть команда на движение назад
#define internal1_m390_FDvUp0	 BUFFER[12170]	//(internal1_m390_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m390_FDvUp0	 1914	//(internal1_m390_FDvUp0) - есть команда на движение вперёд
#define internal1_m390_FDvDw0	 BUFFER[12171]	//(internal1_m390_FDvDw0) - есть команда на движение назад
#define idinternal1_m390_FDvDw0	 1915	//(internal1_m390_FDvDw0) - есть команда на движение назад
#define internal1_m390_BlDv0	 BUFFER[12172]	//(internal1_m390_BlDv0) - была блокировка
#define idinternal1_m390_BlDv0	 1916	//(internal1_m390_BlDv0) - была блокировка
#define internal1_m390_Pkv0	 BUFFER[12173]	//(internal1_m390_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m390_Pkv0	 1917	//(internal1_m390_Pkv0) Pkv - передний конечный выключатель
#define internal1_m390_Pkav0	 BUFFER[12174]	//(internal1_m390_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m390_Pkav0	 1918	//(internal1_m390_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m390_Zkv0	 BUFFER[12175]	//(internal1_m390_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m390_Zkv0	 1919	//(internal1_m390_Zkv0) Zkv - задний конечный выключатель
#define internal1_m390_Zkav0	 BUFFER[12176]	//(internal1_m390_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m390_Zkav0	 1920	//(internal1_m390_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m390_txNm	 BUFFER[12177]	//(internal1_m390_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m390_txNm	 1921	//(internal1_m390_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m390_txSm	 BUFFER[12182]	//(internal1_m390_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m390_txSm	 1922	//(internal1_m390_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m390_txHr	 BUFFER[12187]	//(internal1_m390_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m390_txHr	 1923	//(internal1_m390_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m390_txLd	 BUFFER[12192]	//(internal1_m390_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m390_txLd	 1924	//(internal1_m390_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m390_fef	 BUFFER[12197]	//(internal1_m390_fef) fef
#define idinternal1_m390_fef	 1925	//(internal1_m390_fef) fef
#define internal1_m427_DvUp0	 BUFFER[12198]	//(internal1_m427_DvUp0) - есть команда на движение вперёд
#define idinternal1_m427_DvUp0	 1926	//(internal1_m427_DvUp0) - есть команда на движение вперёд
#define internal1_m427_DvDw0	 BUFFER[12199]	//(internal1_m427_DvDw0) - есть команда на движение назад
#define idinternal1_m427_DvDw0	 1927	//(internal1_m427_DvDw0) - есть команда на движение назад
#define internal1_m427_FDvUp0	 BUFFER[12200]	//(internal1_m427_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m427_FDvUp0	 1928	//(internal1_m427_FDvUp0) - есть команда на движение вперёд
#define internal1_m427_FDvDw0	 BUFFER[12201]	//(internal1_m427_FDvDw0) - есть команда на движение назад
#define idinternal1_m427_FDvDw0	 1929	//(internal1_m427_FDvDw0) - есть команда на движение назад
#define internal1_m427_BlDv0	 BUFFER[12202]	//(internal1_m427_BlDv0) - была блокировка
#define idinternal1_m427_BlDv0	 1930	//(internal1_m427_BlDv0) - была блокировка
#define internal1_m427_Pkv0	 BUFFER[12203]	//(internal1_m427_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m427_Pkv0	 1931	//(internal1_m427_Pkv0) Pkv - передний конечный выключатель
#define internal1_m427_Pkav0	 BUFFER[12204]	//(internal1_m427_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m427_Pkav0	 1932	//(internal1_m427_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m427_Zkv0	 BUFFER[12205]	//(internal1_m427_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m427_Zkv0	 1933	//(internal1_m427_Zkv0) Zkv - задний конечный выключатель
#define internal1_m427_Zkav0	 BUFFER[12206]	//(internal1_m427_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m427_Zkav0	 1934	//(internal1_m427_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m427_txNm	 BUFFER[12207]	//(internal1_m427_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m427_txNm	 1935	//(internal1_m427_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m427_txSm	 BUFFER[12212]	//(internal1_m427_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m427_txSm	 1936	//(internal1_m427_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m427_txHr	 BUFFER[12217]	//(internal1_m427_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m427_txHr	 1937	//(internal1_m427_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m427_txLd	 BUFFER[12222]	//(internal1_m427_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m427_txLd	 1938	//(internal1_m427_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m427_fef	 BUFFER[12227]	//(internal1_m427_fef) fef
#define idinternal1_m427_fef	 1939	//(internal1_m427_fef) fef
#define internal1_m421_DvUp0	 BUFFER[12228]	//(internal1_m421_DvUp0) - есть команда на движение вперёд
#define idinternal1_m421_DvUp0	 1940	//(internal1_m421_DvUp0) - есть команда на движение вперёд
#define internal1_m421_DvDw0	 BUFFER[12229]	//(internal1_m421_DvDw0) - есть команда на движение назад
#define idinternal1_m421_DvDw0	 1941	//(internal1_m421_DvDw0) - есть команда на движение назад
#define internal1_m421_FDvUp0	 BUFFER[12230]	//(internal1_m421_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m421_FDvUp0	 1942	//(internal1_m421_FDvUp0) - есть команда на движение вперёд
#define internal1_m421_FDvDw0	 BUFFER[12231]	//(internal1_m421_FDvDw0) - есть команда на движение назад
#define idinternal1_m421_FDvDw0	 1943	//(internal1_m421_FDvDw0) - есть команда на движение назад
#define internal1_m421_BlDv0	 BUFFER[12232]	//(internal1_m421_BlDv0) - была блокировка
#define idinternal1_m421_BlDv0	 1944	//(internal1_m421_BlDv0) - была блокировка
#define internal1_m421_Pkv0	 BUFFER[12233]	//(internal1_m421_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m421_Pkv0	 1945	//(internal1_m421_Pkv0) Pkv - передний конечный выключатель
#define internal1_m421_Pkav0	 BUFFER[12234]	//(internal1_m421_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m421_Pkav0	 1946	//(internal1_m421_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m421_Zkv0	 BUFFER[12235]	//(internal1_m421_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m421_Zkv0	 1947	//(internal1_m421_Zkv0) Zkv - задний конечный выключатель
#define internal1_m421_Zkav0	 BUFFER[12236]	//(internal1_m421_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m421_Zkav0	 1948	//(internal1_m421_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m421_txNm	 BUFFER[12237]	//(internal1_m421_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m421_txNm	 1949	//(internal1_m421_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m421_txSm	 BUFFER[12242]	//(internal1_m421_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m421_txSm	 1950	//(internal1_m421_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m421_txHr	 BUFFER[12247]	//(internal1_m421_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m421_txHr	 1951	//(internal1_m421_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m421_txLd	 BUFFER[12252]	//(internal1_m421_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m421_txLd	 1952	//(internal1_m421_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m421_fef	 BUFFER[12257]	//(internal1_m421_fef) fef
#define idinternal1_m421_fef	 1953	//(internal1_m421_fef) fef
#define internal1_m827_q0	 BUFFER[12258]	//(internal1_m827_q0) q0 - внутренний параметр
#define idinternal1_m827_q0	 1954	//(internal1_m827_q0) q0 - внутренний параметр
#define internal1_m824_q0	 BUFFER[12260]	//(internal1_m824_q0) q0 - внутренний параметр
#define idinternal1_m824_q0	 1955	//(internal1_m824_q0) q0 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &R0AB05LDU},	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
	{ 2	,8	,1	, &R0VN11RZ1},	//( - , MDuBz1) Средняя мощность по BAZ1
	{ 3	,8	,1	, &R0VN11RZ2},	//( - , MDuBz2) Средняя мощность по BAZ2
	{ 4	,1	,1	, &A2AB15LDU},	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{ 5	,1	,1	, &B2AB15LDU},	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{ 6	,1	,1	, &R0AD21LDU},	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
	{ 7	,1	,1	, &R0VX02LDU},	//( - , DU) Импульс разрешен
	{ 8	,1	,1	, &R0EE03LDU},	//( - , DU) ВПИС ИС
	{ 9	,1	,1	, &R0AB07LDU},	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
	{ 10	,1	,1	, &C2MD31LP1},	//( - , DU) Кнопка СБРОС РБ
	{ 11	,3	,1	, &B6VS01IDU},	//( - , DU) Готовность к управлению БЗ2
	{ 12	,1	,1	, &R2AD20LDU},	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
	{ 13	,1	,1	, &R2AD10LDU},	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
	{ 14	,3	,1	, &B8VS01IDU},	//( - , DU) Готовность к управлению АЗ2
	{ 15	,3	,1	, &A8VS01IDU},	//( - , DU) Готовность к управлению ДС2
	{ 16	,1	,1	, &A1IE03LDU},	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
	{ 17	,1	,1	, &A1IE04LDU},	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
	{ 18	,1	,1	, &A2IE03LDU},	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
	{ 19	,1	,1	, &A2IE04LDU},	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
	{ 20	,1	,1	, &A3IE03LDU},	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
	{ 21	,1	,1	, &A3IE04LDU},	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
	{ 22	,1	,1	, &B1IE03LDU},	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
	{ 23	,1	,1	, &B1IE04LDU},	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
	{ 24	,1	,1	, &A1VN71LZ1},	//(vds32:02 - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{ 25	,1	,1	, &A1VN71LZ2},	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{ 26	,1	,1	, &A1AB19LDU},	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
	{ 27	,1	,1	, &R0AD14LZ1},	//(vds32:02 - K20VDSR, DU) Имитация срабатывания АЗ от II УР
	{ 28	,1	,1	, &R0AD14LZ2},	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
	{ 29	,1	,1	, &A3VZ13LZ2},	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{ 30	,1	,1	, &A3VZ13LZ1},	//(vds32:02 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{ 31	,1	,1	, &A3VZ15LZ1},	//(vds32:02 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{ 32	,1	,1	, &A3VZ15LZ2},	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{ 33	,1	,1	, &B2IS33LDU},	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
	{ 34	,1	,1	, &B3IS31LDU},	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
	{ 35	,1	,1	, &B3IS33LDU},	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
	{ 36	,1	,1	, &B3IS35LDU},	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
	{ 37	,1	,1	, &B4IS10LDU},	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
	{ 38	,1	,1	, &R6IS31LDU},	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
	{ 39	,1	,1	, &R6IS32LDU},	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
	{ 40	,1	,1	, &R6IS42LDU},	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
	{ 41	,1	,1	, &R6IS41LDU},	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
	{ 42	,1	,1	, &R6IS52LDU},	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
	{ 43	,1	,1	, &R6IS51LDU},	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
	{ 44	,1	,1	, &R3IS11LDU},	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
	{ 45	,1	,1	, &R3IS21LDU},	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
	{ 46	,1	,1	, &R0AB03LDU},	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
	{ 47	,1	,1	, &A9ZAV},	//( - , DU) Завершение НИ ДС1(2)
	{ 48	,1	,1	, &R4ABL},	//( - , DU) Блокировка тележки -
	{ 49	,1	,1	, &A4UP},	//( - , DU) 
	{ 50	,1	,1	, &A4DW},	//( - , DU) 
	{ 51	,1	,1	, &R0AB14LDU},	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
	{ 52	,1	,1	, &R0AB15LDU},	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
	{ 53	,1	,1	, &A3IS12LDU},	//( - , DU) Приход на ВУ штока ИС1
	{ 54	,1	,1	, &B3IS12LDU},	//( - , DU) Приход на ВУ штока ИС2
	{ 55	,1	,1	, &A1ZAV},	//( - , DU) 
	{ 56	,1	,1	, &A3ZAV},	//( - , DU) 
	{ 57	,1	,1	, &B1AB19LDU},	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
	{ 58	,1	,1	, &R0AB16LDU},	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
	{ 59	,1	,1	, &R0AB17LDU},	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
	{ 60	,1	,1	, &R0AB18LDU},	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
	{ 61	,8	,1	, &A0CT01IZ1},	//( - , MDuBz1) Температура АЗ1-1
	{ 62	,8	,1	, &B0CT01IZ1},	//( - , MDuBz1) Температура АЗ2-1
	{ 63	,8	,1	, &A0CT01IZ2},	//( - , MDuBz2) Температура АЗ1-2
	{ 64	,8	,1	, &B0CT01IZ2},	//( - , MDuBz2) Температура АЗ2-2
	{ 65	,8	,1	, &A3MC01RDU},	//( - , DU) Заданная координата положения ИС от регулятора мм
	{ 66	,8	,1	, &A3MC02RDU},	//( - , DU) Температурная корректировка координаты ИМ
	{ 67	,8	,1	, &R0CN91LDU},	//( - , DU) Рассчётная реактивность от регулятора
	{ 68	,8	,1	, &A3MC03RDU},	//( - , DU) Координата положения ИМ 0-й реактивности
	{ 69	,1	,1	, &A3AB15LDU},	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
	{ 70	,1	,1	, &B2IE03LDU},	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
	{ 71	,1	,1	, &B2IE04LDU},	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
	{ 72	,1	,1	, &B3IE03LDU},	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
	{ 73	,1	,1	, &B3IE04LDU},	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
	{ 74	,1	,1	, &R0VS11LDU},	//( - , DU) РУ не готова к работе
	{ 75	,1	,1	, &B6AB05LDU},	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
	{ 76	,1	,1	, &R0AB08LDU},	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
	{ 77	,8	,1	, &A1MC01RP1},	//( - , DU) Заданная координата положения ББ1 мм
	{ 78	,8	,1	, &B1MC01RP1},	//( - , DU) Заданная координата положения ББ2  мм
	{ 79	,8	,1	, &A3MC01RP1},	//( - , DU) Заданная координата положения ИС1 мм
	{ 80	,8	,1	, &B3MC01RP1},	//( - , DU) Заданная координата положения ИС2 мм
	{ 81	,8	,1	, &B8MC01RP2},	//( - , DU) Заданная координата АЗ2 мм
	{ 82	,1	,1	, &R0AB09LDU},	//( - , DU) Ошибка в заданной координате ББ1
	{ 83	,1	,1	, &R0AB10LDU},	//( - , DU) Ошибка в заданной координате ББ2
	{ 84	,1	,1	, &R0AB11LDU},	//( - , DU) Ошибка в заданной координате  ИС1
	{ 85	,1	,1	, &R0AB12LDU},	//( - , DU) Ошибка в заданной координате  ИС2
	{ 86	,1	,1	, &R0AB13LDU},	//( - , DU) Ошибка в заданной координате  АЗ2
	{ 87	,1	,1	, &A4ZAV},	//( - , DU) 
	{ 88	,1	,1	, &A6ZAV},	//( - , DU) 
	{ 89	,1	,1	, &R2ZAV},	//( - , DU) 
	{ 90	,1	,1	, &A5ZAV},	//( - , DU) 
	{ 91	,1	,1	, &B8ZAV},	//( - , DU) 
	{ 92	,1	,1	, &A2ZAV},	//( - , DU) Завершение РБ1,2
	{ 93	,1	,1	, &A8ZAV},	//( - , DU) 
	{ 94	,1	,1	, &B9AB01LDU},	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
	{ 95	,1	,1	, &B9AB02LDU},	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
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
	{ 117	,3	,1	, &B3VS01IDU},	//( - , DU) Готовность к управлению ИС2
	{ 118	,3	,1	, &A2VS01IDU},	//( - , DU) Готовность к управлению РБ1
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
	{ 132	,1	,1	, &A9IS21LDU},	//(vds32:02 - K24VDSR, DU) Приход на НУ НИ ДС1
	{ 133	,1	,1	, &B9IS11LDU},	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
	{ 134	,1	,1	, &B9IS21LDU},	//(vds32:02 - K26VDSR, DU) Приход на НУ НИ ДС2
	{ 135	,1	,1	, &B9AD10LDU},	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
	{ 136	,1	,1	, &A9AD10LDU},	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
	{ 137	,1	,1	, &A9AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ ДС1
	{ 138	,1	,1	, &A9AB01LDU},	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
	{ 139	,1	,1	, &A9AB02LDU},	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
	{ 140	,1	,1	, &B9AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ ДС2
	{ 141	,1	,1	, &R0MD34LP1},	//( - , DU) Кнопка КВИТИРОВАТЬ
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
	{ 156	,1	,1	, &R0VZ71LZ2},	//(vds32:03 - K22VDSR, - ) Обобщенный сигнал АЗ 2 канала
	{ 157	,1	,1	, &R0VZ71LZ1},	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
	{ 158	,1	,1	, &R0VZ71LDU},	//( - , DU) Обобщенный сигнал АЗ
	{ 159	,1	,1	, &A2IS33LDU},	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
	{ 160	,1	,1	, &A3IS31LDU},	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
	{ 161	,1	,1	, &A3IS33LDU},	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
	{ 162	,1	,1	, &A3IS35LDU},	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
	{ 163	,1	,1	, &A4IS10LDU},	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
	{ 164	,1	,1	, &R0MW17LP1},	//( - , DU) Переключатель АВТ/Р
	{ 165	,1	,1	, &R0VW13LDU},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
	{ 166	,1	,1	, &R0VW23LDU},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
	{ 167	,3	,1	, &R0VX08IDU},	//( - , DU) Индикация Режим
	{ 168	,1	,1	, &R0VX09LDU},	//( - , DU) Индикация регулятор мощности включен/отключен
	{ 169	,1	,1	, &R0VS17LDU},	//( - , DU) Индикация выбора АВТОМАТ
	{ 170	,1	,1	, &A2VS32LDU},	//( - , DU) Индикация  СБРОС РБ1
	{ 171	,1	,1	, &B2VS32LDU},	//( - , DU) Индикация  СБРОС РБ2
	{ 172	,1	,1	, &A3VX01LDU},	//( - , DU) Индикация Выстрел ИС1
	{ 173	,1	,1	, &B3VX01LDU},	//( - , DU) Индикация Выстрел ИС2
	{ 174	,1	,1	, &R0VS18LDU},	//( - , DU) Индикация  Проверка схем сброса
	{ 175	,1	,1	, &B1MD11LP1},	//( - , DU) Кнопка ПУСК ББ2
	{ 176	,1	,1	, &B1MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
	{ 177	,1	,1	, &B2MD11LP1},	//( - , DU) Кнопка ПУСК РБ2
	{ 178	,1	,1	, &B2MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
	{ 179	,1	,1	, &A2MD11LP1},	//( - , DU) Кнопка ПУСК РБ1
	{ 180	,1	,1	, &A2MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
	{ 181	,1	,1	, &B3IS11LDU},	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
	{ 182	,1	,1	, &A3IS11LDU},	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
	{ 183	,1	,1	, &R0IS01LDU},	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
	{ 184	,1	,1	, &R0IS02LDU},	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
	{ 185	,1	,1	, &R0VP73LZ1},	//( - , MDuBz1) ПС давления для РУ
	{ 186	,1	,1	, &R0VP73LZ2},	//( - , MDuBz2) ПС давления для РУ
	{ 187	,1	,1	, &R0VP73LDU},	//( - , DU) ПС давления для РУ
	{ 188	,1	,1	, &A3VP82LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
	{ 189	,3	,1	, &A3IP02IDU},	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
	{ 190	,3	,1	, &B3IP02IDU},	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
	{ 191	,1	,1	, &A0VE01LDU},	//( - , DU) Напряжение в системы АЗ1 подано
	{ 192	,1	,1	, &B0VE01LDU},	//( - , DU) Напряжение в системы АЗ2 подано
	{ 193	,1	,1	, &A0VP01LDU},	//( - , DU) Давление в системы АЗ1 подано
	{ 194	,1	,1	, &B0VP01LDU},	//( - , DU) Давление в системы АЗ2 подано
	{ 195	,1	,1	, &A0EE01LZ1},	//( - , MDuBz1) Исправность АКНП1
	{ 196	,1	,1	, &A0EE03LZ1},	//( - , MDuBz1) Исправность АКНП3
	{ 197	,1	,1	, &A0EE02LZ1},	//( - , MDuBz1) Исправность АКНП2
	{ 198	,1	,1	, &A0EE04LZ1},	//( - , MDuBz1) Исправность АКНП4
	{ 199	,1	,1	, &A0VN01LDU},	//( - , DU) Каналы АЗ1 проверены
	{ 200	,1	,1	, &B0VN01LDU},	//( - , DU) Каналы АЗ2 проверены
	{ 201	,1	,1	, &A0EE01LZ2},	//( - , MDuBz2) Исправность АКНП1
	{ 202	,1	,1	, &A0EE03LZ2},	//( - , MDuBz2) Исправность АКНП3
	{ 203	,1	,1	, &A0EE02LZ2},	//( - , MDuBz2) Исправность АКНП2
	{ 204	,1	,1	, &A0EE04LZ2},	//( - , MDuBz2) Исправность АКНП4
	{ 205	,1	,1	, &A0VP71LZ1},	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
	{ 206	,1	,1	, &A0VP71LZ2},	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
	{ 207	,1	,1	, &B0VP71LZ1},	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
	{ 208	,1	,1	, &B0VP71LZ2},	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
	{ 209	,1	,1	, &A0VS11LDU},	//( - , DU) АЗ1 готова к работе
	{ 210	,1	,1	, &B0VS11LDU},	//( - , DU) АЗ2 готова к работе
	{ 211	,1	,1	, &A1IS11LDU},	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
	{ 212	,1	,1	, &B1MC01LC1},	//( - , DU) Настроить энкодер ББ2
	{ 213	,1	,1	, &B1MC01LC2},	//( - , DU) Настроить энкодер ББ2
	{ 214	,1	,1	, &A1MC01LC1},	//( - , DU) Настроить энкодер ББ1
	{ 215	,1	,1	, &A1MC01LC2},	//( - , DU) Настроить энкодер ББ1
	{ 216	,1	,1	, &B2MC01LC1},	//( - , DU) Настроить энкодер РБ2
	{ 217	,1	,1	, &B2MC01LC2},	//( - , DU) Настроить энкодер РБ2
	{ 218	,1	,1	, &A2MC01LC1},	//( - , DU) Настроить энкодер РБ1
	{ 219	,1	,1	, &A2MC01LC2},	//( - , DU) Настроить энкодер РБ1
	{ 220	,1	,1	, &B3MC01LC1},	//( - , DU) Настроить энкодер ИС2
	{ 221	,1	,1	, &B3MC01LC2},	//( - , DU) Настроить энкодер ИС2
	{ 222	,1	,1	, &A3MC01LC1},	//( - , DU) Настроить энкодер ИС1
	{ 223	,1	,1	, &A3MC01LC2},	//( - , DU) Настроить энкодер ИС1
	{ 224	,1	,1	, &B8MC01LC1},	//( - , DU) Настроить энкодер АЗ2
	{ 225	,1	,1	, &B8MC01LC2},	//( - , DU) Настроить энкодер АЗ2
	{ 226	,1	,1	, &A8MC01LC1},	//( - , DU) Настроить энкодер ДС2
	{ 227	,1	,1	, &A8MC01LC2},	//( - , DU) Настроить энкодер ДС2
	{ 228	,1	,1	, &A3VP42LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
	{ 229	,8	,1	, &A3CP02RDU},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
	{ 230	,1	,1	, &A3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
	{ 231	,1	,1	, &B3VP42LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
	{ 232	,8	,1	, &B3CP02RDU},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
	{ 233	,1	,1	, &B3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
	{ 234	,1	,1	, &B3VP82LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
	{ 235	,1	,1	, &R6IS68LZZ},	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 236	,8	,1	, &A3VC01RDU},	//( - , DU) Координата ИС1, мм
	{ 237	,8	,1	, &A2VC01RDU},	//( - , DU) Координата РБ1, мм
	{ 238	,8	,1	, &B2VC01RDU},	//( - , DU) Координата РБ2, мм
	{ 239	,8	,1	, &B8VC01RDU},	//( - , DU, MDuBz1, MDuBz2) Координата АЗ2, мм
	{ 240	,1	,1	, &A4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
	{ 241	,1	,1	, &B4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
	{ 242	,1	,1	, &A2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
	{ 243	,1	,1	, &B2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
	{ 244	,1	,1	, &A3VP81LDU},	//( - , - ) Давление СПУСК ИС1 в норме
	{ 245	,1	,1	, &B3VP81LDU},	//( - , - ) Давление СПУСК ИС2 в норме
	{ 246	,1	,1	, &R0EE02LDU},	//( - , DU) Питание  АКНП  отключить
	{ 247	,1	,1	, &psaz11},	//( - , DU) каналы
	{ 248	,1	,1	, &psaz12},	//( - , DU) напряжение
	{ 249	,1	,1	, &psaz13},	//( - , DU) давление
	{ 250	,1	,1	, &psaz14},	//( - , DU) ас темп з2
	{ 251	,1	,1	, &psaz15},	//( - , DU) ас темп з1
	{ 252	,1	,1	, &psaz21},	//( - , DU) каналы
	{ 253	,1	,1	, &psaz22},	//( - , DU) напряжение
	{ 254	,1	,1	, &psaz23},	//( - , DU) давление
	{ 255	,1	,1	, &psaz24},	//( - , DU) ас темп з2
	{ 256	,1	,1	, &psaz25},	//( - , DU) питание
	{ 257	,1	,1	, &psaz3},	//( - , DU) энкодеры
	{ 258	,1	,1	, &A1IE01LDU},	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
	{ 259	,1	,1	, &A3IE01LDU},	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
	{ 260	,1	,1	, &A2IE01LDU},	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
	{ 261	,1	,1	, &A1IE02LDU},	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
	{ 262	,1	,1	, &A3IE02LDU},	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
	{ 263	,1	,1	, &A2IE02LDU},	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
	{ 264	,1	,1	, &B1IE01LDU},	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
	{ 265	,1	,1	, &B2IE01LDU},	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
	{ 266	,1	,1	, &B3IE01LDU},	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
	{ 267	,1	,1	, &B1IE02LDU},	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
	{ 268	,1	,1	, &B3IE02LDU},	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
	{ 269	,1	,1	, &B2IE02LDU},	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
	{ 270	,1	,1	, &R0IE02LDU},	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
	{ 271	,1	,1	, &R0IE01LDU},	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
	{ 272	,1	,1	, &A6IE01LDU},	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
	{ 273	,1	,1	, &B6IE01LDU},	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
	{ 274	,1	,1	, &A8IE01LDU},	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
	{ 275	,1	,1	, &B5IE01LDU},	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
	{ 276	,1	,1	, &A5IE02LDU},	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
	{ 277	,1	,1	, &R1IE01LDU},	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
	{ 278	,1	,1	, &R2IE01LDU},	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
	{ 279	,1	,1	, &R6IS61LDU},	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
	{ 280	,1	,1	, &R6IS66LZZ},	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 281	,1	,1	, &R6IS67LZZ},	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 282	,1	,1	, &A3EE03LDU},	//( - , DU) ВПИС ИС1
	{ 283	,1	,1	, &B3EE03LDU},	//( - , DU) ВПИС ИС2
	{ 284	,1	,1	, &B3AB15LDU},	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
	{ 285	,1	,1	, &R5IS21LDU},	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
	{ 286	,1	,1	, &R5VS22LDU},	//( - , DU) Движение ворот отстойной зоны к закрыты
	{ 287	,1	,1	, &R5VS12LDU},	//( - , DU) Движение ворот отстойной зоны к открыты
	{ 288	,3	,1	, &R5VS01IDU},	//( - , DU) Готовность к управлению ворот отстойной зоны
	{ 289	,1	,1	, &R3VS22LDU},	//( - , DU) Движение гомогенных дверей к закрыты
	{ 290	,1	,1	, &R3VS12LDU},	//( - , DU) Движение гомогенных дверей к открыты
	{ 291	,3	,1	, &R3VS01IDU},	//( - , DU) Готовность к управлению гомогенных дверей
	{ 292	,1	,1	, &A3AB13LDU},	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
	{ 293	,1	,1	, &B3AB13LDU},	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
	{ 294	,3	,1	, &R0DE02LDU},	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
	{ 295	,3	,1	, &R0DE03LDU},	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
	{ 296	,3	,1	, &R0DE04LDU},	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
	{ 297	,3	,1	, &R0DE08LDU},	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
	{ 298	,3	,1	, &R0DE05LDU},	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
	{ 299	,3	,1	, &R0DE09LDU},	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
	{ 300	,3	,1	, &R0DE0ALDU},	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
	{ 301	,3	,1	, &R0DE07LDU},	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
	{ 302	,3	,1	, &R0DE0CLDU},	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
	{ 303	,3	,1	, &R0DE0BLDU},	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
	{ 304	,3	,1	, &R0DE0DLDU},	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
	{ 305	,1	,1	, &R0AB20LDU},	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
	{ 306	,8	,1	, &R0CN92LDU},	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
	{ 307	,8	,1	, &R0VN11RDU},	//( - , DU) Текущая мощность РУ
	{ 308	,8	,1	, &R0VN12RDU},	//( - , DU) Заданная мощность РУ
	{ 309	,1	,1	, &R0AB19LDU},	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
	{ 310	,8	,1	, &R0CN93LDU},	//( - , DU) время работы на мощности более 100Вт, сек
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
	{ 321	,1	,1	, &A1VP41LZ1},	//( - , MDuBz1) Давление СБРОС ББ1 ниже АС
	{ 322	,1	,1	, &A1VP41LZ2},	//( - , MDuBz2) Давление СБРОС ББ1 ниже АС
	{ 323	,1	,1	, &R0VL22LDU},	//( - , DU) Конец программы 200сек
	{ 324	,1	,1	, &R0VL23LDU},	//( - , DU) Конец программы 20мин
	{ 325	,1	,1	, &B1VP41LZ1},	//( - , MDuBz1) Давление СБРОС ББ2 ниже АС
	{ 326	,1	,1	, &B1VP41LZ2},	//( - , MDuBz2) Давление СБРОС ББ2 ниже АС
	{ 327	,1	,1	, &A3AB19LDU},	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
	{ 328	,1	,1	, &B3AB19LDU},	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
	{ 329	,1	,1	, &R0S01LZ1},	//(fds16:07 - K15FDSR, - ) Отключение сетевых передач в Баз1
	{ 330	,1	,1	, &R0S01LZ2},	//(fds16:07 - K16FDSR, - ) Отключение сетевых передач в Баз2
	{ 331	,1	,1	, &R0AD16LDU},	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
	{ 332	,1	,1	, &R0S01LIM},	//(fds16:08 - K15FDSR, - ) Отключение сетевых передач ПТИ
	{ 333	,1	,1	, &psb1},	//( - , DU) ру не готова
	{ 334	,1	,1	, &psb2},	//( - , DU) движение бб
	{ 335	,1	,1	, &psrb4},	//( - , DU) кнопка сброс
	{ 336	,1	,1	, &psrb1},	//( - , DU) пневматика по мощности
	{ 337	,1	,1	, &psrb2},	//( - , DU) пневматика по программам
	{ 338	,1	,1	, &psrb},	//( - , DU) ???
	{ 339	,5	,1	, &B1IC01UDU},	//( - , MDuS) Координата штока ББ2 (дел.энк)
	{ 340	,8	,1	, &B1VC01RDU},	//( - , DU) Координата ББ2, мм
	{ 341	,1	,1	, &B1IS11LDU},	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
	{ 342	,5	,1	, &A2IC01UDU},	//( - , MDuS) Координата штока РБ1 (дел.энк)
	{ 343	,5	,1	, &B2IC01UDU},	//( - , MDuS) Координата штока РБ2 (дел.энк)
	{ 344	,5	,1	, &A3IC01UDU},	//( - , MDuS) Координата штока ИС1 (дел.энк)
	{ 345	,5	,1	, &B3IC01UDU},	//( - , MDuS) Координата штока ИС2 (дел.энк)
	{ 346	,8	,1	, &B3VC01RDU},	//( - , DU) Координата ИС2, мм
	{ 347	,5	,1	, &A8IC01UDU},	//( - , MDuS) Координата ДС2 (дел.энк)
	{ 348	,8	,1	, &A8VC01RDU},	//( - , DU) Координата ДС2, мм
	{ 349	,5	,1	, &B8IC01UDU},	//( - , MDuS) Координата АЗ2 (дел.энк)
	{ 350	,5	,1	, &A1IC01UDU},	//( - , MDuS) Координата штока ББ1 (дел.энк)
	{ 351	,8	,1	, &A1VC01RDU},	//( - , DU) Координата ББ1, мм
	{ 352	,3	,1	, &R0DE0FLDU},	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
	{ 353	,3	,1	, &TTLDU},	//( - , DU) ttl
	{ 354	,1	,1	, &R0DEB3LDU},	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
	{ 355	,1	,1	, &R0DEB2LDU},	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
	{ 356	,1	,1	, &R0DEB1LDU},	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
	{ 357	,1	,1	, &R0DEB4LDU},	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
	{ 358	,1	,1	, &R0DE3DLDU},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
	{ 359	,1	,1	, &R0DE3CLDU},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
	{ 360	,1	,1	, &TestDiagnDU},	//( - , DU) Неисправность от
	{ 361	,8	,1	, &B3CV01RDU},	//( - , DU) Измеренная скорость перемещения ИС2
	{ 362	,3	,1	, &R0DE01LDU},	//(vencf8l:01 - DiagnVDS, DiagnDU) диагностика модуля ДУ на 1 месте
	{ 363	,3	,1	, &R0DE06LDU},	//(vencf8l:01 - DiagnFDS, DiagnDU) диагностика модуля ДУ на 6 месте
	{ 364	,5	,1	, &venc01},	//(vencf8l:01 - venc01, - ) заначение реального энкодера ББ1
	{ 365	,5	,1	, &venc02},	//(vencf8l:01 - venc02, - ) заначение реального энкодера РБ1
	{ 366	,5	,1	, &venc03},	//(vencf8l:01 - venc03, - ) заначение реального энкодера Ис1
	{ 367	,5	,1	, &venc04},	//(vencf8l:01 - venc04, - ) заначение реального энкодера ДС1
	{ 368	,5	,1	, &venc05},	//(vencf8l:01 - venc05, - ) заначение реального энкодера ББ2
	{ 369	,5	,1	, &venc06},	//(vencf8l:01 - venc06, - ) заначение реального энкодера РБ2
	{ 370	,5	,1	, &venc07},	//(vencf8l:01 - venc07, - ) заначение реального энкодера ИС2
	{ 371	,5	,1	, &venc08},	//(vencf8l:01 - venc08, - ) заначение реального энкодера АЗ2
	{ 372	,8	,1	, &R0VN15RDU},	//( - , DU) Период разгона РУ
	{ 373	,1	,1	, &R8AD21LDU},	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
	{ 374	,1	,1	, &R8AD22LDU},	//(vds32:02 - K15VDSR, - ) Сигнал синхронизации с импульсом
	{ 375	,1	,1	, &R0S01LDU},	//( - , - ) Отключение сетевых передач ДУ
	{ 376	,1	,1	, &A6AB08LDU},	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
	{ 377	,1	,1	, &A6AB09LDU},	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
	{ 378	,1	,1	, &B6AB06LDU},	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
	{ 379	,1	,1	, &B6AB07LDU},	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
	{ 380	,1	,1	, &B6AB08LDU},	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
	{ 381	,1	,1	, &B6AB09LDU},	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
	{ 382	,1	,1	, &A6AB05LDU},	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
	{ 383	,1	,1	, &B8VS12LDU},	//( - , DU) Движение АЗ2 в сторону ВУ
	{ 384	,8	,1	, &B8CV01RDU},	//( - , DU) Измеренная скорость перемещения АЗ2
	{ 385	,1	,1	, &B8AB06LDU},	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
	{ 386	,1	,1	, &B8AB07LDU},	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
	{ 387	,1	,1	, &B8AB05LDU},	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
	{ 388	,1	,1	, &B8VS22LDU},	//( - , DU) Движение АЗ2 в сторону НУ
	{ 389	,1	,1	, &B8AZ03LDU},	//( - , DU) Несанкционированное перемещение АЗ2
	{ 390	,1	,1	, &R0MD11LP1},	//( - , DU) Кнопка ПУСК
	{ 391	,1	,1	, &B8AD10LDU},	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
	{ 392	,1	,1	, &B8AD20LDU},	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
	{ 393	,1	,1	, &B8IS11LDU},	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
	{ 394	,1	,1	, &B8AB01LDU},	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
	{ 395	,1	,1	, &B8AB04LDU},	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
	{ 396	,1	,1	, &B8AB08LDU},	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
	{ 397	,1	,1	, &B8AB09LDU},	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
	{ 398	,1	,1	, &B8AB10LDU},	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
	{ 399	,1	,1	, &A5AB02LDU},	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
	{ 400	,1	,1	, &B5AZ03LDU},	//( - , DU) Несанкционированное перемещение НЛ2
	{ 401	,1	,1	, &B5AB01LDU},	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
	{ 402	,1	,1	, &B5AB02LDU},	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
	{ 403	,1	,1	, &A4IS21LDU},	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
	{ 404	,1	,1	, &B4IS21LDU},	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
	{ 405	,1	,1	, &B4AD10LDU},	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
	{ 406	,1	,1	, &A4AD10LDU},	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
	{ 407	,1	,1	, &A4AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ1
	{ 408	,1	,1	, &A4AB01LDU},	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
	{ 409	,1	,1	, &A4AB02LDU},	//( - , DU) Блокировка движения НИ1 - Нет перемещения
	{ 410	,1	,1	, &B4AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ2
	{ 411	,1	,1	, &B4AB01LDU},	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
	{ 412	,1	,1	, &B4AB02LDU},	//( - , DU) Блокировка движения НИ2 - Нет перемещения
	{ 413	,1	,1	, &A5AB04LDU},	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
	{ 414	,1	,1	, &B5AB04LDU},	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
	{ 415	,1	,1	, &A1IS12LDU},	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
	{ 416	,1	,1	, &A2IS12LDU},	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
	{ 417	,1	,1	, &B1IS12LDU},	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
	{ 418	,1	,1	, &B2IS12LDU},	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
	{ 419	,1	,1	, &R4IS11LDU},	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
	{ 420	,1	,1	, &A6AB06LDU},	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
	{ 421	,1	,1	, &A6AB07LDU},	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
	{ 422	,1	,1	, &A8AB14LDU},	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
	{ 423	,1	,1	, &A8AB02LDU},	//( - , DU) Блокировка движения ДС2- АНИ не установлен
	{ 424	,1	,1	, &A8AB01LDU},	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
	{ 425	,1	,1	, &A2VS11LDU},	//( - , DU) Движение РБ1 в сторону ВУ
	{ 426	,8	,1	, &A2CV01RDU},	//( - , DU) Измеренная скорость перемещения РБ1
	{ 427	,1	,1	, &A2AB04LDU},	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
	{ 428	,1	,1	, &A2AB02LDU},	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
	{ 429	,1	,1	, &A2AB01LDU},	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
	{ 430	,1	,1	, &A2VS21LDU},	//( - , DU) Движение РБ1 в сторону НУ
	{ 431	,1	,1	, &A2AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
	{ 432	,1	,1	, &A2AD11LDU},	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
	{ 433	,1	,1	, &A2AD21LDU},	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
	{ 434	,1	,1	, &A2AD02LDU},	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
	{ 435	,1	,1	, &A2AD03LDU},	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
	{ 436	,1	,1	, &A2AD04LDU},	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
	{ 437	,1	,1	, &A2AD05LDU},	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
	{ 438	,1	,1	, &A2AB07LDU},	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
	{ 439	,1	,1	, &A2AB08LDU},	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
	{ 440	,1	,1	, &A2AB05LDU},	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
	{ 441	,1	,1	, &A2AB06LDU},	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
	{ 442	,1	,1	, &A2AB09LDU},	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
	{ 443	,1	,1	, &A2AB10LDU},	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
	{ 444	,1	,1	, &A2AB11LDU},	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
	{ 445	,1	,1	, &B8AB11LDU},	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
	{ 446	,1	,1	, &B8AB12LDU},	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
	{ 447	,1	,1	, &B8AB13LDU},	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
	{ 448	,1	,1	, &B8AB14LDU},	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
	{ 449	,1	,1	, &B8AB02LDU},	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
	{ 450	,1	,1	, &A8VS12LDU},	//( - , DU) Движение ДС2 в сторону ВУ
	{ 451	,8	,1	, &A8CV01RDU},	//( - , DU) Измеренная скорость перемещения ДС2
	{ 452	,1	,1	, &A8AB06LDU},	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
	{ 453	,1	,1	, &A8AB07LDU},	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
	{ 454	,1	,1	, &A8AB05LDU},	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
	{ 455	,1	,1	, &A8VS22LDU},	//( - , DU) Движение ДС2 в сторону НУ
	{ 456	,1	,1	, &A8AZ03LDU},	//( - , DU) Несанкционированное перемещение ДС2
	{ 457	,1	,1	, &A8AD10LDU},	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
	{ 458	,1	,1	, &A8AD20LDU},	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
	{ 459	,1	,1	, &B8IS22LDU},	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
	{ 460	,1	,1	, &A8IS12LDU},	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
	{ 461	,1	,1	, &A8AB04LDU},	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
	{ 462	,1	,1	, &A8IS22LDU},	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
	{ 463	,1	,1	, &A8AB08LDU},	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
	{ 464	,1	,1	, &A8AB09LDU},	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
	{ 465	,1	,1	, &A8AB10LDU},	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
	{ 466	,1	,1	, &A8AB11LDU},	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
	{ 467	,1	,1	, &A8AB12LDU},	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
	{ 468	,1	,1	, &A8AB13LDU},	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
	{ 469	,1	,1	, &A6VS22LDU},	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
	{ 470	,1	,1	, &A6VS12LDU},	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
	{ 471	,1	,1	, &B6VS22LDU},	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
	{ 472	,1	,1	, &B6VS12LDU},	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
	{ 473	,1	,1	, &A6AD10LDU},	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
	{ 474	,1	,1	, &A6AD20LDU},	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
	{ 475	,1	,1	, &B6AD10LDU},	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
	{ 476	,1	,1	, &B6AD20LDU},	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
	{ 477	,1	,1	, &A6AZ03LDU},	//( - , DU) Несанкционированное перемещение БЗ1
	{ 478	,1	,1	, &A6AB01LDU},	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
	{ 479	,1	,1	, &A6AB02LDU},	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
	{ 480	,1	,1	, &B6AZ03LDU},	//( - , DU) Несанкционированное перемещение БЗ2
	{ 481	,1	,1	, &B6AB01LDU},	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
	{ 482	,1	,1	, &B6AB02LDU},	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
	{ 483	,1	,1	, &A6AB04LDU},	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
	{ 484	,1	,1	, &B6AB04LDU},	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
	{ 485	,1	,1	, &R4AB01LDU},	//( - , DU) Блокировка движения тележки - АНИ не установлен
	{ 486	,1	,1	, &R8IS11LDU},	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
	{ 487	,1	,1	, &R6IS21LDU},	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
	{ 488	,1	,1	, &A0VN71LZ2},	//( - , MDuBz2) АЗ по АС мощности для АЗ1
	{ 489	,1	,1	, &A0VN71LZ1},	//( - , MDuBz1) АЗ по АС мощности для АЗ1
	{ 490	,1	,1	, &R0NE01LDU},	//( - , DU) Потеря связи с БАЗ1
	{ 491	,1	,1	, &R0NE02LDU},	//( - , DU) Потеря связи с БАЗ2
	{ 492	,3	,1	, &R0MW15IP1},	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
	{ 493	,3	,1	, &R0MW14IP1},	//( - , DU) Переключатель ПРОГРАММЫ
	{ 494	,3	,1	, &R0MW12IP1},	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
	{ 495	,3	,1	, &R0MW13IP1},	//( - , DU) Переключатель ВЫБОР ЗОН
	{ 496	,3	,1	, &R0MW16IP1},	//( - , DU) Переключатель ВИД ПРОВЕРКИ
	{ 497	,3	,1	, &R0MW11IP1},	//( - , DU) Переключатель ВЫСТРЕЛ
	{ 498	,3	,1	, &R0MW11IP2},	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
	{ 499	,1	,1	, &R0MW13LP2},	//( - , DU) Переключатель СЕТЬ
	{ 500	,1	,1	, &R0MD32LP1},	//( - , DU) Кнопка СПУСК
	{ 501	,1	,1	, &R0MD31LP1},	//( - , DU) Кнопка СТОП
	{ 502	,1	,1	, &A1IS21LDU},	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
	{ 503	,1	,1	, &A2IS21LDU},	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
	{ 504	,1	,1	, &A3IS21LDU},	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
	{ 505	,1	,1	, &B1IS21LDU},	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
	{ 506	,1	,1	, &B2IS21LDU},	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
	{ 507	,1	,1	, &B3IS21LDU},	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
	{ 508	,1	,1	, &R0ES01LDU},	//( - , DU) ОРР не в исходном состоянии
	{ 509	,1	,1	, &R4MD11LP2},	//( - , DU) Кнопка ВПЕРЁД  (тележки)
	{ 510	,1	,1	, &R4MD31LP2},	//( - , DU) Кнопка СТОП  (тележки)
	{ 511	,1	,1	, &R4MD21LP2},	//( - , DU) Кнопка НАЗАД  (тележки)
	{ 512	,1	,1	, &A6IS11LDU},	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
	{ 513	,1	,1	, &A6IS21LDU},	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
	{ 514	,1	,1	, &B6IS11LDU},	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
	{ 515	,1	,1	, &B6IS21LDU},	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
	{ 516	,1	,1	, &R4AB13LDU},	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
	{ 517	,1	,1	, &R4AB14LDU},	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
	{ 518	,1	,1	, &R4AB15LDU},	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
	{ 519	,1	,1	, &R5IS11LDU},	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
	{ 520	,1	,1	, &R4AB16LDU},	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
	{ 521	,1	,1	, &R4AB17LDU},	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
	{ 522	,1	,1	, &R4AB18LDU},	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
	{ 523	,1	,1	, &R4AD10LDU},	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
	{ 524	,1	,1	, &R4AD20LDU},	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
	{ 525	,1	,1	, &A5VS22LDU},	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
	{ 526	,1	,1	, &A5VS12LDU},	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
	{ 527	,1	,1	, &B5VS22LDU},	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
	{ 528	,1	,1	, &B5VS12LDU},	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
	{ 529	,1	,1	, &B5AD10LDU},	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
	{ 530	,1	,1	, &B5AD20LDU},	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
	{ 531	,1	,1	, &A5AD10LDU},	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
	{ 532	,1	,1	, &A5AD20LDU},	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
	{ 533	,1	,1	, &A5IS11LDU},	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
	{ 534	,1	,1	, &A5IS21LDU},	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
	{ 535	,1	,1	, &B5IS11LDU},	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
	{ 536	,1	,1	, &B5IS21LDU},	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
	{ 537	,1	,1	, &A5AZ03LDU},	//( - , DU) Несанкционированное перемещение НЛ1
	{ 538	,1	,1	, &A5AB01LDU},	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
	{ 539	,1	,1	, &R4AB02LDU},	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
	{ 540	,1	,1	, &R0NE08LDU},	//( - , DU) Потеря связи с ОПУ
	{ 541	,1	,1	, &R4IS21LDU},	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
	{ 542	,1	,1	, &R4IS22LDU},	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
	{ 543	,1	,1	, &R4IS12LDU},	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
	{ 544	,1	,1	, &R4VS22LDU},	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
	{ 545	,1	,1	, &R4VS12LDU},	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
	{ 546	,1	,1	, &R4AZ03LDU},	//( - , DU) Несанкционированное перемещение тележки
	{ 547	,1	,1	, &R4AB03LDU},	//( - , DU) Блокировка движения тележки - Самоход любого механизма
	{ 548	,1	,1	, &R1IS21LDU},	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
	{ 549	,1	,1	, &R2IS21LDU},	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
	{ 550	,1	,1	, &R4AB04LDU},	//( - , DU) Блокировка движения тележки - Превышение времени движения
	{ 551	,1	,1	, &R4AB05LDU},	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
	{ 552	,1	,1	, &R4AB06LDU},	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
	{ 553	,1	,1	, &R4AB07LDU},	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
	{ 554	,1	,1	, &R4AB08LDU},	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
	{ 555	,1	,1	, &R4AB09LDU},	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
	{ 556	,1	,1	, &B0VN71LZ1},	//( - , MDuBz1) АЗ по АС мощности для АЗ2
	{ 557	,1	,1	, &B0VN71LZ2},	//( - , MDuBz2) АЗ по АС мощности для АЗ2
	{ 558	,1	,1	, &R4AB10LDU},	//( - , DU) Блокировка тележки - не открыта биологическая защита
	{ 559	,1	,1	, &R4AB11LDU},	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
	{ 560	,1	,1	, &R4AB12LDU},	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
	{ 561	,1	,1	, &A4IS11LDU},	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
	{ 562	,1	,1	, &B4IS11LDU},	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
	{ 563	,8	,1	, &A3CV02RDU},	//( - , DU) Заданная скорость перемещения ИС1
	{ 564	,1	,1	, &A3AB07LDU},	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
	{ 565	,1	,1	, &A3AB08LDU},	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
	{ 566	,1	,1	, &A3AB05LDU},	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
	{ 567	,1	,1	, &A3AB06LDU},	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
	{ 568	,1	,1	, &A3AB09LDU},	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
	{ 569	,1	,1	, &A3AB10LDU},	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
	{ 570	,1	,1	, &A3AB11LDU},	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
	{ 571	,1	,1	, &A3AB12LDU},	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 572	,1	,1	, &A3AB14LDU},	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
	{ 573	,1	,1	, &A3AB16LDU},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
	{ 574	,1	,1	, &A3AB17LDU},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
	{ 575	,1	,1	, &A3AB18LDU},	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
	{ 576	,1	,1	, &A3AB20LDU},	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
	{ 577	,1	,1	, &B3VS12LDU},	//( - , DU) Движение ИС2 в сторону ВУ
	{ 578	,1	,1	, &B3AB04LDU},	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
	{ 579	,1	,1	, &B3AB02LDU},	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
	{ 580	,1	,1	, &B3AB01LDU},	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
	{ 581	,1	,1	, &B3VS22LDU},	//( - , DU) Движение ИС2 в сторону НУ
	{ 582	,1	,1	, &B3AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
	{ 583	,1	,1	, &B3AD11LDU},	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
	{ 584	,1	,1	, &B3AD21LDU},	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
	{ 585	,1	,1	, &B3AD02LDU},	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
	{ 586	,1	,1	, &B1AB06LDU},	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
	{ 587	,1	,1	, &B1AB09LDU},	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
	{ 588	,1	,1	, &B1AB10LDU},	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
	{ 589	,1	,1	, &B1AB11LDU},	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
	{ 590	,1	,1	, &B1AB12LDU},	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 591	,1	,1	, &B1AB13LDU},	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
	{ 592	,1	,1	, &B1AB14LDU},	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
	{ 593	,1	,1	, &B1AB16LDU},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
	{ 594	,1	,1	, &B1AB17LDU},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
	{ 595	,1	,1	, &B1AB18LDU},	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
	{ 596	,1	,1	, &A3VS12LDU},	//( - , DU) Движение ИС1 в сторону ВУ
	{ 597	,8	,1	, &A3CV01RDU},	//( - , DU) Измеренная скорость перемещения ИС1
	{ 598	,1	,1	, &A3AB04LDU},	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
	{ 599	,1	,1	, &A3AB02LDU},	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
	{ 600	,1	,1	, &A3AB01LDU},	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
	{ 601	,1	,1	, &A3VS22LDU},	//( - , DU) Движение ИС1 в сторону НУ
	{ 602	,1	,1	, &A3AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
	{ 603	,1	,1	, &A3AD11LDU},	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
	{ 604	,1	,1	, &A3AD21LDU},	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
	{ 605	,1	,1	, &A3AD02LDU},	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
	{ 606	,1	,1	, &A3AD03LDU},	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
	{ 607	,1	,1	, &A3AD04LDU},	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
	{ 608	,1	,1	, &A3AD05LDU},	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
	{ 609	,1	,1	, &A3AD01LDU},	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
	{ 610	,1	,1	, &A2AD32LDU},	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
	{ 611	,1	,1	, &B2AD32LDU},	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
	{ 612	,1	,1	, &A1AD32LDU},	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
	{ 613	,1	,1	, &B1AD32LDU},	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
	{ 614	,1	,1	, &R0MD11LP2},	//( - , DU) Кнопка Пуск проверки схем сброса
	{ 615	,1	,1	, &R0VX01LDU},	//( - , DU) ДО ИМПУЛЬСА
	{ 616	,3	,1	, &R0VL01IDU},	//( - , DU) До импульса минут
	{ 617	,3	,1	, &R0VL11IDU},	//( - , DU) До импульса секунд
	{ 618	,8	,1	, &R0VL06RDU},	//( - , DU) Индикация (Время задержки от ВУ РБ)
	{ 619	,1	,1	, &B3AD33LDU},	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
	{ 620	,8	,1	, &R0VL02RDU},	//( - , DU) Индикация (Время задержки ИНИ)
	{ 621	,8	,1	, &R0VL04RDU},	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
	{ 622	,1	,1	, &R0AB04LDU},	//( - , DU) Нарушение времени срабатывания верхней АС II УР
	{ 623	,1	,1	, &R0AB06LDU},	//( - , DU) Нарушение времени задержки от ВУ РБ
	{ 624	,1	,1	, &R0AB02LDU},	//( - , DU) Нарушение времени задержки ИНИ
	{ 625	,8	,1	, &R0VL03RDU},	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
	{ 626	,8	,1	, &R0VL05RDU},	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
	{ 627	,3	,1	, &R0VL21IDU},	//( - , DU) Декатрон
	{ 628	,1	,1	, &R0VX03LDU},	//( - , DU) Готовность 2 мин
	{ 629	,3	,1	, &R0VS21IDU},	//( - , DU) Индикация ВИД ПРОВЕРКИ
	{ 630	,3	,1	, &A1VS01IDU},	//( - , DU) Готовность к управлению ББ1
	{ 631	,3	,1	, &B1VS01IDU},	//( - , DU) Готовность к управлению ББ2
	{ 632	,3	,1	, &A3VS01IDU},	//( - , DU) Готовность к управлению ИС1
	{ 633	,1	,1	, &B3AD03LDU},	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
	{ 634	,1	,1	, &B3AD04LDU},	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
	{ 635	,1	,1	, &B3AD05LDU},	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
	{ 636	,1	,1	, &B3AD01LDU},	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
	{ 637	,8	,1	, &B3CV02RDU},	//( - , DU) Заданная скорость перемещения ИС2
	{ 638	,1	,1	, &B3AB07LDU},	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
	{ 639	,1	,1	, &B3AB08LDU},	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
	{ 640	,1	,1	, &B3AB05LDU},	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
	{ 641	,1	,1	, &B3AB06LDU},	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
	{ 642	,1	,1	, &B3AB09LDU},	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
	{ 643	,1	,1	, &B3AB10LDU},	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
	{ 644	,1	,1	, &B3AB11LDU},	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
	{ 645	,1	,1	, &B3AB12LDU},	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{ 646	,1	,1	, &B3AB14LDU},	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
	{ 647	,1	,1	, &B3AB16LDU},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
	{ 648	,1	,1	, &B3AB17LDU},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
	{ 649	,1	,1	, &B3AB18LDU},	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
	{ 650	,1	,1	, &B3AB20LDU},	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
	{ 651	,1	,1	, &C1MD31LP1},	//( - , DU) Кнопка СБРОС ББ
	{ 652	,1	,1	, &C1MD31LP2},	//( - , DU) Кнопка СБРОС ББ
	{ 653	,1	,1	, &A2AD31LDU},	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
	{ 654	,1	,1	, &B2AD31LDU},	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
	{ 655	,1	,1	, &A1AD31LDU},	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
	{ 656	,1	,1	, &B1AD31LDU},	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
	{ 657	,1	,1	, &B2AB09LDU},	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
	{ 658	,1	,1	, &B2AB10LDU},	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
	{ 659	,1	,1	, &B2AB11LDU},	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
	{ 660	,1	,1	, &B2AB12LDU},	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{ 661	,1	,1	, &B2AB13LDU},	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
	{ 662	,1	,1	, &B2AB14LDU},	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
	{ 663	,1	,1	, &B2AB16LDU},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
	{ 664	,1	,1	, &B2AB17LDU},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
	{ 665	,1	,1	, &R1AZ03LDU},	//( - , DU) Несанкционированное перемещение МДЗ1
	{ 666	,1	,1	, &R1AB01LDU},	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
	{ 667	,1	,1	, &R1AB02LDU},	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
	{ 668	,1	,1	, &R2AZ03LDU},	//( - , DU) Несанкционированное перемещение МДЗ2
	{ 669	,1	,1	, &R2AB01LDU},	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
	{ 670	,1	,1	, &R2AB02LDU},	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
	{ 671	,1	,1	, &R1AB04LDU},	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
	{ 672	,1	,1	, &R2AB04LDU},	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
	{ 673	,1	,1	, &R1AD10LDU},	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
	{ 674	,1	,1	, &R1AD20LDU},	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
	{ 675	,1	,1	, &R1IS11LDU},	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
	{ 676	,1	,1	, &R1VS22LDU},	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
	{ 677	,1	,1	, &R2VS22LDU},	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
	{ 678	,1	,1	, &R2VS12LDU},	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
	{ 679	,1	,1	, &R1VS12LDU},	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
	{ 680	,1	,1	, &A2AB12LDU},	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 681	,1	,1	, &A2AB13LDU},	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
	{ 682	,1	,1	, &A2AB14LDU},	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
	{ 683	,1	,1	, &A2AB16LDU},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
	{ 684	,1	,1	, &A2AB17LDU},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
	{ 685	,1	,1	, &A2AD01LDU},	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
	{ 686	,8	,1	, &A2CV02RDU},	//( - , DU) Заданная скорость перемещения РБ1
	{ 687	,8	,1	, &B2CV01RDU},	//( - , DU) Измеренная скорость перемещения РБ2
	{ 688	,1	,1	, &B2AB04LDU},	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
	{ 689	,1	,1	, &B2AB02LDU},	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
	{ 690	,1	,1	, &B2AB01LDU},	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
	{ 691	,1	,1	, &B2AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
	{ 692	,1	,1	, &B2AD11LDU},	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
	{ 693	,1	,1	, &B2AD21LDU},	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
	{ 694	,1	,1	, &B2AD02LDU},	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
	{ 695	,1	,1	, &B2AD03LDU},	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
	{ 696	,1	,1	, &B2AD04LDU},	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
	{ 697	,1	,1	, &B2AD05LDU},	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
	{ 698	,1	,1	, &B2AD01LDU},	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
	{ 699	,8	,1	, &B2CV02RDU},	//( - , DU) Заданная скорость перемещения РБ2
	{ 700	,1	,1	, &B2AB07LDU},	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
	{ 701	,1	,1	, &B2AB08LDU},	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
	{ 702	,1	,1	, &B2AB05LDU},	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
	{ 703	,1	,1	, &B2AB06LDU},	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
	{ 704	,1	,1	, &A1AB13LDU},	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
	{ 705	,1	,1	, &A1AB14LDU},	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
	{ 706	,1	,1	, &A1AB16LDU},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
	{ 707	,1	,1	, &A1AB17LDU},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
	{ 708	,1	,1	, &A1AB18LDU},	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
	{ 709	,1	,1	, &B1VS12LDU},	//( - , DU) Движение ББ2 в сторону ВУ
	{ 710	,8	,1	, &B1CV01RDU},	//( - , DU) Измеренная скорость перемещения ББ2
	{ 711	,1	,1	, &B1AB04LDU},	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
	{ 712	,1	,1	, &B1AB02LDU},	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
	{ 713	,1	,1	, &B1AB01LDU},	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
	{ 714	,1	,1	, &B1VS22LDU},	//( - , DU) Движение ББ2 в сторону НУ
	{ 715	,1	,1	, &B1AZ03LDU},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
	{ 716	,1	,1	, &B1AD11LDU},	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
	{ 717	,1	,1	, &B1AD21LDU},	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
	{ 718	,1	,1	, &B1AD02LDU},	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
	{ 719	,1	,1	, &B1AD03LDU},	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
	{ 720	,1	,1	, &B1AD04LDU},	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
	{ 721	,1	,1	, &B1AD05LDU},	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
	{ 722	,1	,1	, &B1AD01LDU},	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
	{ 723	,8	,1	, &B1CV02RDU},	//( - , DU) Заданная скорость перемещения ББ2
	{ 724	,1	,1	, &B1AB07LDU},	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
	{ 725	,1	,1	, &B1AB08LDU},	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
	{ 726	,1	,1	, &B1AB05LDU},	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
	{ 727	,1	,1	, &R2IS11LDU},	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
	{ 728	,1	,1	, &A1VS12LDU},	//( - , DU) Движение ББ1 в сторону ВУ
	{ 729	,8	,1	, &A1CV01RDU},	//( - , DU) Измеренная скорость перемещения ББ1
	{ 730	,1	,1	, &A1AB04LDU},	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
	{ 731	,1	,1	, &A1AB02LDU},	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
	{ 732	,1	,1	, &A1AB01LDU},	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
	{ 733	,1	,1	, &A1VS22LDU},	//( - , DU) Движение ББ1 в сторону НУ
	{ 734	,1	,1	, &A1AZ03LDU},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
	{ 735	,1	,1	, &A1AD11LDU},	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
	{ 736	,1	,1	, &A1AD21LDU},	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
	{ 737	,1	,1	, &A1AD02LDU},	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
	{ 738	,1	,1	, &A1AD03LDU},	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
	{ 739	,1	,1	, &A1AD04LDU},	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
	{ 740	,1	,1	, &A1AD05LDU},	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
	{ 741	,1	,1	, &A1AD01LDU},	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
	{ 742	,8	,1	, &A1CV02RDU},	//( - , DU) Заданная скорость перемещения ББ1
	{ 743	,1	,1	, &A1AB07LDU},	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
	{ 744	,1	,1	, &A1AB08LDU},	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
	{ 745	,1	,1	, &A1AB05LDU},	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
	{ 746	,1	,1	, &A1AB06LDU},	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
	{ 747	,1	,1	, &A1AB09LDU},	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
	{ 748	,1	,1	, &A1AB10LDU},	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
	{ 749	,1	,1	, &A1AB11LDU},	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
	{ 750	,1	,1	, &A1AB12LDU},	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 751	,8	,1	, &fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
	{ 752	,5	,1	, &dEM_A1UC05UDU},	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
	{ 753	,5	,1	, &dEM_A1UC06UDU},	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
	{ 754	,5	,1	, &dEM_A2UC06UDU},	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
	{ 755	,5	,1	, &dEM_A2UC05UDU},	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
	{ 756	,8	,1	, &fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
	{ 757	,5	,1	, &dEM_A3UC06UDU},	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
	{ 758	,5	,1	, &dEM_A3UC05UDU},	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
	{ 759	,8	,1	, &fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
	{ 760	,5	,1	, &dEM_A8UC06UDU},	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
	{ 761	,8	,1	, &fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
	{ 762	,5	,1	, &dEM_A8UC05UDU},	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
	{ 763	,8	,1	, &fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{ 764	,8	,1	, &fEM_R0UV82RDU},	//(R0UV82RDU) 2-я частота двигателя (шагов/секунду)
	{ 765	,8	,1	, &fEM_R0UV83RDU},	//(R0UV83RDU) 3-я частота двигателя (шагов/секунду)
	{ 766	,8	,1	, &fEM_R0UV84RDU},	//(R0UV84RDU) 4-я частота двигателя (шагов/секунду)
	{ 767	,8	,1	, &fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 768	,8	,1	, &fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{ 769	,8	,1	, &fEM_R0UV87RDU},	//(R0UV87RDU) 8-я скорость перемещения ББ (шагов/секунду)
	{ 770	,8	,1	, &fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{ 771	,8	,1	, &fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{ 772	,8	,1	, &fEM_A3UP43RDU},	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
	{ 773	,8	,1	, &fEM_A3UP44RDU},	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
	{ 774	,8	,1	, &fEM_A3UP53RDU},	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
	{ 775	,8	,1	, &fEM_A3UP85RDU},	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 776	,8	,1	, &fEM_A3UP88RDU},	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 777	,8	,1	, &fEM_A3UP86RDU},	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 778	,8	,1	, &fEM_B8UV01RDU},	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
	{ 779	,8	,1	, &fEM_B8UV02RDU},	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
	{ 780	,8	,1	, &fEM_B8UV03RDU},	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
	{ 781	,8	,1	, &fEM_B8UL04RDU},	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
	{ 782	,3	,1	, &iEM_A2UV03CDU},	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
	{ 783	,8	,1	, &fEM_A2UV01RDU},	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
	{ 784	,8	,1	, &fEM_A2UV02RDU},	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
	{ 785	,8	,1	, &fEM_A1UV01RDU},	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
	{ 786	,8	,1	, &fEM_A1UV02RDU},	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
	{ 787	,8	,1	, &fEM_A1UC06RDU},	//(A1UC06RDU) Уставка определения самохода ББ  мм
	{ 788	,8	,1	, &fEM_A1UC05RDU},	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
	{ 789	,8	,1	, &fEM_A1UL04RDU},	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
	{ 790	,8	,1	, &fEM_A3UV01RDU},	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
	{ 791	,8	,1	, &fEM_A3UV02RDU},	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
	{ 792	,8	,1	, &fEM_A3UC06RDU},	//(A3UC06RDU) Уставка определения самохода ИС1  мм
	{ 793	,8	,1	, &fEM_A3UC05RDU},	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
	{ 794	,8	,1	, &fEM_A3UL04RDU},	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
	{ 795	,8	,1	, &fEM_A3UP54RDU},	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
	{ 796	,8	,1	, &fEM_A3UP87RDU},	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 797	,8	,1	, &fEM_R0UL05RDU},	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
	{ 798	,8	,1	, &fEM_R0UL20RDU},	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
	{ 799	,8	,1	, &fEM_B8UV04RDU},	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
	{ 800	,8	,1	, &fEM_B8UC06RDU},	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
	{ 801	,8	,1	, &fEM_B8UC05RDU},	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
	{ 802	,8	,1	, &fEM_A2UL05RDU},	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
	{ 803	,8	,1	, &fEM_A2UL03RDU},	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{ 804	,8	,1	, &fEM_A2UC06RDU},	//(A2UC06RDU) Уставка определения самохода РБ  мм
	{ 805	,8	,1	, &fEM_A2UC05RDU},	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
	{ 806	,8	,1	, &fEM_A2UL04RDU},	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
	{ 807	,8	,1	, &fEM_A1UL03RDU},	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
	{ 808	,8	,1	, &fEM_A1UL05RDU},	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
	{ 809	,8	,1	, &fEM_A3UL03RDU},	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
	{ 810	,8	,1	, &fEM_A3UL05RDU},	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
	{ 811	,8	,1	, &fEM_A1UC08RDU},	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
	{ 812	,8	,1	, &fEM_A3UC08RDU},	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
	{ 813	,8	,1	, &fEM_A1UC07RDU},	//(A1UC07RDU) Зона возврата при наведении ББ мм
	{ 814	,8	,1	, &fEM_A1UL01RDU},	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 815	,8	,1	, &fEM_A3UC07RDU},	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
	{ 816	,8	,1	, &fEM_A3UL01RDU},	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 817	,8	,1	, &fEM_A2UC08RDU},	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
	{ 818	,8	,1	, &fEM_A2UC07RDU},	//(A2UC07RDU) Зона возврата при наведении РБ  мм
	{ 819	,8	,1	, &fEM_A2UL01RDU},	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 820	,8	,1	, &fEM_B8UC01RDU},	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
	{ 821	,8	,1	, &fEM_B8UL07RDU},	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
	{ 822	,8	,1	, &fEM_B8UC02RDU},	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
	{ 823	,8	,1	, &fEM_B8UL01RDU},	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 824	,8	,1	, &fEM_B8UL05RDU},	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
	{ 825	,8	,1	, &fEM_B8UL03RDU},	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
	{ 826	,8	,1	, &fEM_B8UL06RDU},	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
	{ 827	,8	,1	, &fEM_A9UZ03RDU},	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
	{ 828	,8	,1	, &fEM_A9UZ04RDU},	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
	{ 829	,8	,1	, &fEM_A9UZ05RDU},	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
	{ 830	,8	,1	, &fEM_R4UZ04RDU},	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
	{ 831	,8	,1	, &fEM_R4UZ03RDU},	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
	{ 832	,8	,1	, &fEM_R4UZ05RDU},	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
	{ 833	,8	,1	, &fEM_A5UZ03RDU},	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
	{ 834	,8	,1	, &fEM_A5UZ04RDU},	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
	{ 835	,8	,1	, &fEM_A5UZ05RDU},	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
	{ 836	,8	,1	, &fEM_A4UZ03RDU},	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
	{ 837	,8	,1	, &fEM_A4UZ04RDU},	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
	{ 838	,8	,1	, &fEM_A4UZ05RDU},	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
	{ 839	,8	,1	, &fEM_A6UZ03RDU},	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
	{ 840	,8	,1	, &fEM_A6UZ04RDU},	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
	{ 841	,8	,1	, &fEM_A6UZ05RDU},	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
	{ 842	,8	,1	, &fEM_R1UZ03RDU},	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
	{ 843	,8	,1	, &fEM_R1UZ04RDU},	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
	{ 844	,8	,1	, &fEM_R1UZ05RDU},	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
	{ 845	,8	,1	, &fEM_R0UL04RDU},	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
	{ 846	,8	,1	, &fEM_R0UL06RDU},	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
	{ 847	,8	,1	, &fEM_R0UL03RDU},	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
	{ 848	,8	,1	, &fEM_R0UL17RDU},	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
	{ 849	,8	,1	, &fEM_R0UL19RDU},	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{ 850	,8	,1	, &fEM_R0UL07RDU},	//(R0UL07RDU) Время срабатывания верхней АС II УР
	{ 851	,8	,1	, &fEM_R0UL18RDU},	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
	{ 852	,8	,1	, &fEM_R0UL16RDU},	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
	{ 853	,8	,1	, &fEM_R0UL02RDU},	//(R0UL02RDU) Время задержки  ИНИ
	{ 854	,8	,1	, &fEM_R0UN08RDU},	//(R0UN08RDU) 8-я заданная мощность
	{ 855	,8	,1	, &fEM_R0UN07RDU},	//(R0UN07RDU) 7-я заданная мощность
	{ 856	,8	,1	, &fEM_R0UN06RDU},	//(R0UN06RDU) 6-я заданная мощность
	{ 857	,8	,1	, &fEM_R0UN05RDU},	//(R0UN05RDU) 5-я заданная мощность
	{ 858	,8	,1	, &fEM_R0UN04RDU},	//(R0UN04RDU) 4-я заданная мощность
	{ 859	,8	,1	, &fEM_R0UN03RDU},	//(R0UN03RDU) Ограничение 3 по мощности
	{ 860	,8	,1	, &fEM_R0UN02RDU},	//(R0UN02RDU) 2-я заданная мощность
	{ 861	,8	,1	, &fEM_R0UN01RDU},	//(R0UN01RDU) 1-я заданная мощность
	{ 862	,8	,1	, &fEM_A2UC82RDU},	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
	{ 863	,8	,1	, &fEM_A2UC83RDU},	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
	{ 864	,8	,1	, &fEM_A1UC83RDU},	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
	{ 865	,8	,1	, &fEM_A2UC81RDU},	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
	{ 866	,8	,1	, &fEM_A1UC81RDU},	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
	{ 867	,8	,1	, &fEM_A1UC82RDU},	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
	{ 868	,8	,1	, &fEM_A2UL83RDU},	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{ 869	,8	,1	, &fEM_A3UC81RDU},	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
	{ 870	,8	,1	, &fEM_A3UC82RDU},	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
	{ 871	,8	,1	, &fEM_R0UN80RDU},	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
	{ 872	,3	,1	, &iEM_A2UV01IDU},	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
	{ 873	,3	,1	, &iEM_A2UV02IDU},	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
	{ 874	,3	,1	, &iEM_A1UV01IDU},	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
	{ 875	,3	,1	, &iEM_A1UV02IDU},	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
	{ 876	,3	,1	, &iEM_A1UV03IDU},	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
	{ 877	,3	,1	, &iEM_A3UV01IDU},	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
	{ 878	,3	,1	, &iEM_A3UV02IDU},	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
	{ 879	,1	,1	, &lEM_R0MD01LC1},	//(R0MD01LC1) Ручное управление ОРР
	{ 880	,8	,1	, &fEM_A3UC09RDU},	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
	{ 881	,8	,1	, &fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
	{ 882	,8	,1	, &fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
	{ 883	,8	,1	, &fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
	{ 884	,8	,1	, &fEM_R0UL21RDU},	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
	{ 885	,8	,1	, &fEM_R0UN09RDU},	//(R0UN09RDU) Минимальный период при регулировании мощности
	{ 886	,8	,1	, &fEM_R0UN11RDU},	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
	{ 887	,8	,1	, &fEM_R0UN12RDU},	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
	{ 888	,8	,1	, &fEM_R0UN13RDU},	//(R0UN13RDU) Минимальное изменение координаты, мм
	{ 889	,8	,1	, &fEM_R0UN14RDU},	//(R0UN14RDU) Максимальная координата штока ИМ, мм
	{ 890	,8	,1	, &fEM_R0UN16RDU},	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
	{ 891	,8	,1	, &fEM_R0UN17RDU},	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
	{ 892	,8	,1	, &fEM_R0UN18RDU},	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
	{ 893	,8	,1	, &fEM_R0UN19RDU},	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
	{ 894	,8	,1	, &fEM_R0UN70LDU},	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
	{ 895	,8	,1	, &fEM_R0UN71LDU},	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
	{ 896	,8	,1	, &fEM_R0UN72LDU},	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
	{ 897	,8	,1	, &fEM_R0UN73LDU},	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
	{ 898	,8	,1	, &fEM_R0UN74LDU},	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
	{ 899	,8	,1	, &fEM_R0UN75LDU},	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
	{ 900	,8	,1	, &fEM_R0UN80LDU},	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
	{ 901	,8	,1	, &fEM_R0UN81LDU},	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
	{ 902	,8	,1	, &fEM_R0UN82LDU},	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
	{ 903	,8	,1	, &fEM_R0UN83LDU},	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
	{ 904	,8	,1	, &fEM_R0UN84LDU},	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
	{ 905	,8	,1	, &fEM_R0UN85LDU},	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
	{ 906	,8	,1	, &fEM_R0UT20RDU},	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
	{ 907	,8	,1	, &fEM_R0UN25RDU},	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
	{ 908	,8	,1	, &fEM_R0UN15RDU},	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
	{ 909	,8	,1	, &fEM_R0UN26RDU},	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
	{ 910	,8	,1	, &fEM_R0UN27RDU},	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
	{ 911	,8	,1	, &fEM_R0UN24RDU},	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 912	,8	,1	, &fEM_R0UL25RDU},	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{ 913	,8	,1	, &fEM_R0UL01RSS},	//(R0UL01RSS) Шаг измерения периода (сек)
	{ 914	,8	,1	, &fEM_R0UL02RSS},	//(R0UL02RSS) Tф-постоянная времени, с
	{ 915	,8	,1	, &fEM_R0UN03RSS},	//(R0UN03RSS) нижняя граница интервала мощности для измерения периода (ватт)
	{ 916	,8	,1	, &fEM_R7UI76RDU},	//(R7UI76RDU) Время срабатывания сигнала II УР при имитации
	{ 917	,8	,1	, &fEM_R0UL00RDU},	//(R0UL00RDU) Время ожидания передачи  сигнала отключения сети
	{ 918	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 919	,8	,1	, &internal2_m260_tx},	//(internal2_m260_tx) tx - время накопленное сек
	{ 920	,18	,1	, &internal2_m260_y0},	//(internal2_m260_y0) y0
	{ 921	,8	,1	, &internal2_m258_tx},	//(internal2_m258_tx) tx - время накопленное сек
	{ 922	,18	,1	, &internal2_m258_y0},	//(internal2_m258_y0) y0
	{ 923	,8	,1	, &internal2_m256_tx},	//(internal2_m256_tx) tx - время накопленное сек
	{ 924	,18	,1	, &internal2_m256_y0},	//(internal2_m256_y0) y0
	{ 925	,8	,1	, &internal2_m254_tx},	//(internal2_m254_tx) tx - время накопленное сек
	{ 926	,18	,1	, &internal2_m254_y0},	//(internal2_m254_y0) y0
	{ 927	,8	,1	, &internal2_m252_tx},	//(internal2_m252_tx) tx - время накопленное сек
	{ 928	,18	,1	, &internal2_m252_y0},	//(internal2_m252_y0) y0
	{ 929	,8	,1	, &internal2_m250_tx},	//(internal2_m250_tx) tx - время накопленное сек
	{ 930	,18	,1	, &internal2_m250_y0},	//(internal2_m250_y0) y0
	{ 931	,8	,1	, &internal2_m248_tx},	//(internal2_m248_tx) tx - время накопленное сек
	{ 932	,18	,1	, &internal2_m248_y0},	//(internal2_m248_y0) y0
	{ 933	,8	,1	, &internal2_m246_tx},	//(internal2_m246_tx) tx - время накопленное сек
	{ 934	,18	,1	, &internal2_m246_y0},	//(internal2_m246_y0) y0
	{ 935	,8	,1	, &internal2_m244_tx},	//(internal2_m244_tx) tx - время накопленное сек
	{ 936	,18	,1	, &internal2_m244_y0},	//(internal2_m244_y0) y0
	{ 937	,8	,1	, &internal2_m242_tx},	//(internal2_m242_tx) tx - время накопленное сек
	{ 938	,18	,1	, &internal2_m242_y0},	//(internal2_m242_y0) y0
	{ 939	,8	,1	, &internal2_m240_tx},	//(internal2_m240_tx) tx - время накопленное сек
	{ 940	,18	,1	, &internal2_m240_y0},	//(internal2_m240_y0) y0
	{ 941	,8	,1	, &internal2_m238_tx},	//(internal2_m238_tx) tx - время накопленное сек
	{ 942	,18	,1	, &internal2_m238_y0},	//(internal2_m238_y0) y0
	{ 943	,8	,1	, &internal2_m182_tx},	//(internal2_m182_tx) tx - время накопленное сек
	{ 944	,18	,1	, &internal2_m182_y0},	//(internal2_m182_y0) y0
	{ 945	,8	,1	, &internal2_m176_tx},	//(internal2_m176_tx) tx - время накопленное сек
	{ 946	,18	,1	, &internal2_m176_y0},	//(internal2_m176_y0) y0
	{ 947	,8	,1	, &internal2_m172_tx},	//(internal2_m172_tx) tx - время накопленное сек
	{ 948	,18	,1	, &internal2_m172_y0},	//(internal2_m172_y0) y0
	{ 949	,8	,1	, &internal2_m165_tx},	//(internal2_m165_tx) tx - время накопленное сек
	{ 950	,18	,1	, &internal2_m165_y0},	//(internal2_m165_y0) y0
	{ 951	,8	,1	, &internal2_m157_tx},	//(internal2_m157_tx) tx - время накопленное сек
	{ 952	,18	,1	, &internal2_m157_y0},	//(internal2_m157_y0) y0
	{ 953	,8	,1	, &internal2_m155_tx},	//(internal2_m155_tx) tx - время накопленное сек
	{ 954	,18	,1	, &internal2_m155_y0},	//(internal2_m155_y0) y0
	{ 955	,8	,1	, &internal2_m149_tx},	//(internal2_m149_tx) tx - время накопленное сек
	{ 956	,18	,1	, &internal2_m149_y0},	//(internal2_m149_y0) y0
	{ 957	,8	,1	, &internal2_m144_tx},	//(internal2_m144_tx) tx - время накопленное сек
	{ 958	,18	,1	, &internal2_m144_y0},	//(internal2_m144_y0) y0
	{ 959	,8	,1	, &internal2_m141_tx},	//(internal2_m141_tx) tx - время накопленное сек
	{ 960	,18	,1	, &internal2_m141_y0},	//(internal2_m141_y0) y0
	{ 961	,8	,1	, &internal2_m137_tx},	//(internal2_m137_tx) tx - время накопленное сек
	{ 962	,18	,1	, &internal2_m137_y0},	//(internal2_m137_y0) y0
	{ 963	,8	,1	, &internal2_m131_tx},	//(internal2_m131_tx) tx - время накопленное сек
	{ 964	,18	,1	, &internal2_m131_y0},	//(internal2_m131_y0) y0
	{ 965	,8	,1	, &internal2_m127_tx},	//(internal2_m127_tx) tx - время накопленное сек
	{ 966	,18	,1	, &internal2_m127_y0},	//(internal2_m127_y0) y0
	{ 967	,8	,1	, &internal2_m195_y0},	//(internal2_m195_y0) y0
	{ 968	,8	,1	, &internal2_m193_y0},	//(internal2_m193_y0) y0
	{ 969	,1	,1	, &internal2_m226_y0},	//(internal2_m226_y0) state
	{ 970	,1	,1	, &internal2_m220_y0},	//(internal2_m220_y0) state
	{ 971	,1	,1	, &internal2_m208_y1},	//(internal2_m208_y1) y1 - внутренний параметр
	{ 972	,1	,1	, &internal2_m216_y1},	//(internal2_m216_y1) y1 - внутренний параметр
	{ 973	,1	,1	, &internal2_m198_y1},	//(internal2_m198_y1) y1 - внутренний параметр
	{ 974	,1	,1	, &internal2_m205_y1},	//(internal2_m205_y1) y1 - внутренний параметр
	{ 975	,5	,1	, &internal2_m16_Nk0},	//(internal2_m16_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 976	,1	,1	, &internal2_m16_SetFlag},	//(internal2_m16_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 977	,5	,1	, &internal2_m110_Nk0},	//(internal2_m110_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 978	,1	,1	, &internal2_m110_SetFlag},	//(internal2_m110_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 979	,5	,1	, &internal2_m106_Nk0},	//(internal2_m106_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 980	,1	,1	, &internal2_m106_SetFlag},	//(internal2_m106_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 981	,5	,1	, &internal2_m75_Nk0},	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 982	,1	,1	, &internal2_m75_SetFlag},	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 983	,5	,1	, &internal2_m77_Nk0},	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 984	,1	,1	, &internal2_m77_SetFlag},	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 985	,5	,1	, &internal2_m45_Nk0},	//(internal2_m45_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 986	,1	,1	, &internal2_m45_SetFlag},	//(internal2_m45_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 987	,5	,1	, &internal2_m53_Nk0},	//(internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 988	,1	,1	, &internal2_m53_SetFlag},	//(internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 989	,5	,1	, &internal2_m21_Nk0},	//(internal2_m21_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 990	,1	,1	, &internal2_m21_SetFlag},	//(internal2_m21_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 991	,8	,1	, &internal1_m2556_tx},	//(internal1_m2556_tx) tx - время накопленное сек
	{ 992	,18	,1	, &internal1_m2556_y0},	//(internal1_m2556_y0) y0
	{ 993	,8	,1	, &internal1_m2558_tx},	//(internal1_m2558_tx) tx - время накопленное сек
	{ 994	,18	,1	, &internal1_m2558_y0},	//(internal1_m2558_y0) y0
	{ 995	,8	,1	, &internal1_m2554_tx},	//(internal1_m2554_tx) tx - время накопленное сек
	{ 996	,18	,1	, &internal1_m2554_y0},	//(internal1_m2554_y0) y0
	{ 997	,8	,1	, &internal1_m2552_tx},	//(internal1_m2552_tx) tx - время накопленное сек
	{ 998	,18	,1	, &internal1_m2552_y0},	//(internal1_m2552_y0) y0
	{ 999	,8	,1	, &internal1_m221_tx},	//(internal1_m221_tx) tx - время накопленное сек
	{ 1000	,18	,1	, &internal1_m221_y0},	//(internal1_m221_y0) y0
	{ 1001	,8	,1	, &internal1_m220_tx},	//(internal1_m220_tx) tx - внутренний параметр
	{ 1002	,1	,1	, &internal1_m2101_x0},	//(internal1_m2101_x0) - значение входного параметра на предыдущем шаге
	{ 1003	,8	,1	, &internal1_m2101_tim},	//(internal1_m2101_tim) - время задержки выходного сигнала
	{ 1004	,8	,1	, &internal1_m1677_tx},	//(internal1_m1677_tx) tx - время накопленное сек
	{ 1005	,18	,1	, &internal1_m1677_y0},	//(internal1_m1677_y0) y0
	{ 1006	,3	,1	, &internal1_m79_flst},	//(internal1_m79_flst)  флаг старта измерения
	{ 1007	,3	,1	, &internal1_m79_chsr},	//(internal1_m79_chsr)  счетчик усреднения
	{ 1008	,3	,1	, &internal1_m79_chizm},	//(internal1_m79_chizm)  счетчик уменьшения мощности
	{ 1009	,8	,1	, &internal1_m79_sumtim},	//(internal1_m79_sumtim)  время измерения мощности
	{ 1010	,8	,1	, &internal1_m79_W1},	//(internal1_m79_W1)  мощность на старте измерения
	{ 1011	,8	,1	, &internal1_m79_W2},	//(internal1_m79_W2)  мощность в конце измерения
	{ 1012	,8	,1	, &internal1_m79_Wmin},	//(internal1_m79_Wmin)  минимальное измерение в серии
	{ 1013	,8	,1	, &internal1_m79_Wmax},	//(internal1_m79_Wmax)  максимальное измерение в серии
	{ 1014	,8	,1	, &internal1_m79_Wlast},	//(internal1_m79_Wlast)  последнее растущее измерение
	{ 1015	,8	,1	, &internal1_m79_y0},	//(internal1_m79_y0) y0 - внутренний параметр
	{ 1016	,1	,1	, &internal1_m79_MyFirstEnterFlag},	//(internal1_m79_MyFirstEnterFlag)  FirstEnterFlag
	{ 1017	,8	,1	, &internal1_m2066_tx},	//(internal1_m2066_tx) tx - внутренний параметр
	{ 1018	,8	,1	, &internal1_m2065_tx},	//(internal1_m2065_tx) tx - внутренний параметр
	{ 1019	,8	,1	, &internal1_m785_tx},	//(internal1_m785_tx) tx - внутренний параметр
	{ 1020	,8	,1	, &internal1_m742_tx},	//(internal1_m742_tx) tx - внутренний параметр
	{ 1021	,8	,1	, &internal1_m795_tx},	//(internal1_m795_tx) tx - внутренний параметр
	{ 1022	,8	,1	, &internal1_m797_tx},	//(internal1_m797_tx) tx - внутренний параметр
	{ 1023	,8	,1	, &internal1_m796_tx},	//(internal1_m796_tx) tx - внутренний параметр
	{ 1024	,8	,1	, &internal1_m750_tx},	//(internal1_m750_tx) tx - внутренний параметр
	{ 1025	,8	,1	, &internal1_m735_tx},	//(internal1_m735_tx) tx - внутренний параметр
	{ 1026	,8	,1	, &internal1_m746_tx},	//(internal1_m746_tx) tx - внутренний параметр
	{ 1027	,8	,1	, &internal1_m777_tx},	//(internal1_m777_tx) tx - внутренний параметр
	{ 1028	,8	,1	, &internal1_m794_tx},	//(internal1_m794_tx) tx - внутренний параметр
	{ 1029	,8	,1	, &internal1_m767_tx},	//(internal1_m767_tx) tx - внутренний параметр
	{ 1030	,8	,1	, &internal1_m398_tx},	//(internal1_m398_tx) tx - внутренний параметр
	{ 1031	,8	,1	, &internal1_m397_tx},	//(internal1_m397_tx) tx - внутренний параметр
	{ 1032	,8	,1	, &internal1_m396_tx},	//(internal1_m396_tx) tx - внутренний параметр
	{ 1033	,8	,1	, &internal1_m395_tx},	//(internal1_m395_tx) tx - внутренний параметр
	{ 1034	,8	,1	, &internal1_m766_tx},	//(internal1_m766_tx) tx - внутренний параметр
	{ 1035	,8	,1	, &internal1_m761_tx},	//(internal1_m761_tx) tx - внутренний параметр
	{ 1036	,8	,1	, &internal1_m770_tx},	//(internal1_m770_tx) tx - внутренний параметр
	{ 1037	,8	,1	, &internal1_m775_tx},	//(internal1_m775_tx) tx - внутренний параметр
	{ 1038	,8	,1	, &internal1_m531_tx},	//(internal1_m531_tx) tx - внутренний параметр
	{ 1039	,8	,1	, &internal1_m530_tx},	//(internal1_m530_tx) tx - внутренний параметр
	{ 1040	,8	,1	, &internal1_m529_tx},	//(internal1_m529_tx) tx - внутренний параметр
	{ 1041	,8	,1	, &internal1_m525_tx},	//(internal1_m525_tx) tx - внутренний параметр
	{ 1042	,8	,1	, &internal1_m502_tx},	//(internal1_m502_tx) tx - внутренний параметр
	{ 1043	,8	,1	, &internal1_m501_tx},	//(internal1_m501_tx) tx - внутренний параметр
	{ 1044	,8	,1	, &internal1_m500_tx},	//(internal1_m500_tx) tx - внутренний параметр
	{ 1045	,8	,1	, &internal1_m503_tx},	//(internal1_m503_tx) tx - внутренний параметр
	{ 1046	,8	,1	, &internal1_m2472_tx},	//(internal1_m2472_tx) tx - внутренний параметр
	{ 1047	,8	,1	, &internal1_m2182_tx},	//(internal1_m2182_tx) tx - внутренний параметр
	{ 1048	,8	,1	, &internal1_m2471_tx},	//(internal1_m2471_tx) tx - внутренний параметр
	{ 1049	,8	,1	, &internal1_m2470_tx},	//(internal1_m2470_tx) tx - внутренний параметр
	{ 1050	,8	,1	, &internal1_m2467_tx},	//(internal1_m2467_tx) tx - внутренний параметр
	{ 1051	,8	,1	, &internal1_m108_tx},	//(internal1_m108_tx) tx - внутренний параметр
	{ 1052	,8	,1	, &internal1_m1148_tx},	//(internal1_m1148_tx) tx - внутренний параметр
	{ 1053	,8	,1	, &internal1_m2330_tx},	//(internal1_m2330_tx) tx - внутренний параметр
	{ 1054	,8	,1	, &internal1_m2329_tx},	//(internal1_m2329_tx) tx - внутренний параметр
	{ 1055	,8	,1	, &internal1_m2328_tx},	//(internal1_m2328_tx) tx - внутренний параметр
	{ 1056	,8	,1	, &internal1_m1260_tx},	//(internal1_m1260_tx) tx - внутренний параметр
	{ 1057	,8	,1	, &internal1_m1259_tx},	//(internal1_m1259_tx) tx - внутренний параметр
	{ 1058	,8	,1	, &internal1_m1255_tx},	//(internal1_m1255_tx) tx - внутренний параметр
	{ 1059	,8	,1	, &internal1_m1248_tx},	//(internal1_m1248_tx) tx - внутренний параметр
	{ 1060	,8	,1	, &internal1_m1246_tx},	//(internal1_m1246_tx) tx - внутренний параметр
	{ 1061	,8	,1	, &internal1_m1244_tx},	//(internal1_m1244_tx) tx - внутренний параметр
	{ 1062	,8	,1	, &internal1_m1242_tx},	//(internal1_m1242_tx) tx - внутренний параметр
	{ 1063	,8	,1	, &internal1_m1285_tx},	//(internal1_m1285_tx) tx - внутренний параметр
	{ 1064	,8	,1	, &internal1_m1292_tx},	//(internal1_m1292_tx) tx - внутренний параметр
	{ 1065	,8	,1	, &internal1_m1297_tx},	//(internal1_m1297_tx) tx - внутренний параметр
	{ 1066	,8	,1	, &internal1_m1303_tx},	//(internal1_m1303_tx) tx - внутренний параметр
	{ 1067	,8	,1	, &internal1_m1263_tx},	//(internal1_m1263_tx) tx - внутренний параметр
	{ 1068	,8	,1	, &internal1_m1284_tx},	//(internal1_m1284_tx) tx - внутренний параметр
	{ 1069	,8	,1	, &internal1_m1298_tx},	//(internal1_m1298_tx) tx - внутренний параметр
	{ 1070	,8	,1	, &internal1_m480_tx},	//(internal1_m480_tx) tx - внутренний параметр
	{ 1071	,8	,1	, &internal1_m474_tx},	//(internal1_m474_tx) tx - внутренний параметр
	{ 1072	,8	,1	, &internal1_m476_tx},	//(internal1_m476_tx) tx - внутренний параметр
	{ 1073	,8	,1	, &internal1_m478_tx},	//(internal1_m478_tx) tx - внутренний параметр
	{ 1074	,8	,1	, &internal1_m485_tx},	//(internal1_m485_tx) tx - внутренний параметр
	{ 1075	,8	,1	, &internal1_m439_tx},	//(internal1_m439_tx) tx - внутренний параметр
	{ 1076	,8	,1	, &internal1_m437_tx},	//(internal1_m437_tx) tx - внутренний параметр
	{ 1077	,8	,1	, &internal1_m438_tx},	//(internal1_m438_tx) tx - внутренний параметр
	{ 1078	,8	,1	, &internal1_m431_tx},	//(internal1_m431_tx) tx - внутренний параметр
	{ 1079	,8	,1	, &internal1_m893_tx},	//(internal1_m893_tx) tx - внутренний параметр
	{ 1080	,8	,1	, &internal1_m892_tx},	//(internal1_m892_tx) tx - внутренний параметр
	{ 1081	,8	,1	, &internal1_m891_tx},	//(internal1_m891_tx) tx - внутренний параметр
	{ 1082	,8	,1	, &internal1_m887_tx},	//(internal1_m887_tx) tx - внутренний параметр
	{ 1083	,8	,1	, &internal1_m1349_tx},	//(internal1_m1349_tx) tx - внутренний параметр
	{ 1084	,8	,1	, &internal1_m1348_tx},	//(internal1_m1348_tx) tx - внутренний параметр
	{ 1085	,8	,1	, &internal1_m1347_tx},	//(internal1_m1347_tx) tx - внутренний параметр
	{ 1086	,8	,1	, &internal1_m1560_tx},	//(internal1_m1560_tx) tx - внутренний параметр
	{ 1087	,8	,1	, &internal1_m1573_tx},	//(internal1_m1573_tx) tx - внутренний параметр
	{ 1088	,8	,1	, &internal1_m1572_tx},	//(internal1_m1572_tx) tx - внутренний параметр
	{ 1089	,8	,1	, &internal1_m1571_tx},	//(internal1_m1571_tx) tx - внутренний параметр
	{ 1090	,8	,1	, &internal1_m1562_tx},	//(internal1_m1562_tx) tx - внутренний параметр
	{ 1091	,8	,1	, &internal1_m2300_tx},	//(internal1_m2300_tx) tx - внутренний параметр
	{ 1092	,8	,1	, &internal1_m2283_tx},	//(internal1_m2283_tx) tx - внутренний параметр
	{ 1093	,8	,1	, &internal1_m2260_tx},	//(internal1_m2260_tx) tx - внутренний параметр
	{ 1094	,8	,1	, &internal1_m1570_tx},	//(internal1_m1570_tx) tx - внутренний параметр
	{ 1095	,8	,1	, &internal1_m1550_tx},	//(internal1_m1550_tx) tx - внутренний параметр
	{ 1096	,8	,1	, &internal1_m1549_tx},	//(internal1_m1549_tx) tx - внутренний параметр
	{ 1097	,8	,1	, &internal1_m1547_tx},	//(internal1_m1547_tx) tx - внутренний параметр
	{ 1098	,8	,1	, &internal1_m1569_tx},	//(internal1_m1569_tx) tx - внутренний параметр
	{ 1099	,8	,1	, &internal1_m1535_tx},	//(internal1_m1535_tx) tx - внутренний параметр
	{ 1100	,8	,1	, &internal1_m1537_tx},	//(internal1_m1537_tx) tx - внутренний параметр
	{ 1101	,8	,1	, &internal1_m1534_tx},	//(internal1_m1534_tx) tx - внутренний параметр
	{ 1102	,8	,1	, &internal1_m1507_tx},	//(internal1_m1507_tx) tx - внутренний параметр
	{ 1103	,8	,1	, &internal1_m1506_tx},	//(internal1_m1506_tx) tx - внутренний параметр
	{ 1104	,8	,1	, &internal1_m1516_tx},	//(internal1_m1516_tx) tx - внутренний параметр
	{ 1105	,8	,1	, &internal1_m1519_tx},	//(internal1_m1519_tx) tx - внутренний параметр
	{ 1106	,8	,1	, &internal1_m986_tx},	//(internal1_m986_tx) tx - внутренний параметр
	{ 1107	,8	,1	, &internal1_m989_tx},	//(internal1_m989_tx) tx - внутренний параметр
	{ 1108	,8	,1	, &internal1_m2251_tx},	//(internal1_m2251_tx) tx - внутренний параметр
	{ 1109	,8	,1	, &internal1_m979_tx},	//(internal1_m979_tx) tx - внутренний параметр
	{ 1110	,8	,1	, &internal1_m977_tx},	//(internal1_m977_tx) tx - внутренний параметр
	{ 1111	,8	,1	, &internal1_m985_tx},	//(internal1_m985_tx) tx - внутренний параметр
	{ 1112	,8	,1	, &internal1_m969_tx},	//(internal1_m969_tx) tx - внутренний параметр
	{ 1113	,8	,1	, &internal1_m967_tx},	//(internal1_m967_tx) tx - внутренний параметр
	{ 1114	,8	,1	, &internal1_m963_tx},	//(internal1_m963_tx) tx - внутренний параметр
	{ 1115	,8	,1	, &internal1_m984_tx},	//(internal1_m984_tx) tx - внутренний параметр
	{ 1116	,8	,1	, &internal1_m949_tx},	//(internal1_m949_tx) tx - внутренний параметр
	{ 1117	,8	,1	, &internal1_m950_tx},	//(internal1_m950_tx) tx - внутренний параметр
	{ 1118	,8	,1	, &internal1_m952_tx},	//(internal1_m952_tx) tx - внутренний параметр
	{ 1119	,8	,1	, &internal1_m637_tx},	//(internal1_m637_tx) tx - внутренний параметр
	{ 1120	,8	,1	, &internal1_m640_tx},	//(internal1_m640_tx) tx - внутренний параметр
	{ 1121	,8	,1	, &internal1_m639_tx},	//(internal1_m639_tx) tx - внутренний параметр
	{ 1122	,8	,1	, &internal1_m628_tx},	//(internal1_m628_tx) tx - внутренний параметр
	{ 1123	,8	,1	, &internal1_m626_tx},	//(internal1_m626_tx) tx - внутренний параметр
	{ 1124	,8	,1	, &internal1_m622_tx},	//(internal1_m622_tx) tx - внутренний параметр
	{ 1125	,8	,1	, &internal1_m635_tx},	//(internal1_m635_tx) tx - внутренний параметр
	{ 1126	,8	,1	, &internal1_m612_tx},	//(internal1_m612_tx) tx - внутренний параметр
	{ 1127	,8	,1	, &internal1_m611_tx},	//(internal1_m611_tx) tx - внутренний параметр
	{ 1128	,8	,1	, &internal1_m607_tx},	//(internal1_m607_tx) tx - внутренний параметр
	{ 1129	,8	,1	, &internal1_m638_tx},	//(internal1_m638_tx) tx - внутренний параметр
	{ 1130	,8	,1	, &internal1_m595_tx},	//(internal1_m595_tx) tx - внутренний параметр
	{ 1131	,8	,1	, &internal1_m594_tx},	//(internal1_m594_tx) tx - внутренний параметр
	{ 1132	,8	,1	, &internal1_m597_tx},	//(internal1_m597_tx) tx - внутренний параметр
	{ 1133	,8	,1	, &internal1_m574_tx},	//(internal1_m574_tx) tx - внутренний параметр
	{ 1134	,8	,1	, &internal1_m575_tx},	//(internal1_m575_tx) tx - внутренний параметр
	{ 1135	,8	,1	, &internal1_m576_tx},	//(internal1_m576_tx) tx - внутренний параметр
	{ 1136	,8	,1	, &internal1_m581_tx},	//(internal1_m581_tx) tx - внутренний параметр
	{ 1137	,8	,1	, &internal1_m2313_tx},	//(internal1_m2313_tx) tx - внутренний параметр
	{ 1138	,8	,1	, &internal1_m2314_tx},	//(internal1_m2314_tx) tx - внутренний параметр
	{ 1139	,8	,1	, &internal1_m2315_tx},	//(internal1_m2315_tx) tx - внутренний параметр
	{ 1140	,8	,1	, &internal1_m1792_tx},	//(internal1_m1792_tx) tx - внутренний параметр
	{ 1141	,8	,1	, &internal1_m1791_tx},	//(internal1_m1791_tx) tx - внутренний параметр
	{ 1142	,8	,1	, &internal1_m1786_tx},	//(internal1_m1786_tx) tx - внутренний параметр
	{ 1143	,8	,1	, &internal1_m1777_tx},	//(internal1_m1777_tx) tx - внутренний параметр
	{ 1144	,8	,1	, &internal1_m1775_tx},	//(internal1_m1775_tx) tx - внутренний параметр
	{ 1145	,8	,1	, &internal1_m1773_tx},	//(internal1_m1773_tx) tx - внутренний параметр
	{ 1146	,8	,1	, &internal1_m1772_tx},	//(internal1_m1772_tx) tx - внутренний параметр
	{ 1147	,8	,1	, &internal1_m1813_tx},	//(internal1_m1813_tx) tx - внутренний параметр
	{ 1148	,8	,1	, &internal1_m1821_tx},	//(internal1_m1821_tx) tx - внутренний параметр
	{ 1149	,8	,1	, &internal1_m1828_tx},	//(internal1_m1828_tx) tx - внутренний параметр
	{ 1150	,8	,1	, &internal1_m1829_tx},	//(internal1_m1829_tx) tx - внутренний параметр
	{ 1151	,8	,1	, &internal1_m1819_tx},	//(internal1_m1819_tx) tx - внутренний параметр
	{ 1152	,8	,1	, &internal1_m1794_tx},	//(internal1_m1794_tx) tx - внутренний параметр
	{ 1153	,8	,1	, &internal1_m1808_tx},	//(internal1_m1808_tx) tx - внутренний параметр
	{ 1154	,8	,1	, &internal1_m457_tx},	//(internal1_m457_tx) tx - внутренний параметр
	{ 1155	,8	,1	, &internal1_m448_tx},	//(internal1_m448_tx) tx - внутренний параметр
	{ 1156	,8	,1	, &internal1_m449_tx},	//(internal1_m449_tx) tx - внутренний параметр
	{ 1157	,8	,1	, &internal1_m451_tx},	//(internal1_m451_tx) tx - внутренний параметр
	{ 1158	,8	,1	, &internal1_m465_tx},	//(internal1_m465_tx) tx - внутренний параметр
	{ 1159	,8	,1	, &internal1_m415_tx},	//(internal1_m415_tx) tx - внутренний параметр
	{ 1160	,8	,1	, &internal1_m412_tx},	//(internal1_m412_tx) tx - внутренний параметр
	{ 1161	,8	,1	, &internal1_m411_tx},	//(internal1_m411_tx) tx - внутренний параметр
	{ 1162	,8	,1	, &internal1_m410_tx},	//(internal1_m410_tx) tx - внутренний параметр
	{ 1163	,8	,1	, &internal1_m870_tx},	//(internal1_m870_tx) tx - внутренний параметр
	{ 1164	,8	,1	, &internal1_m866_tx},	//(internal1_m866_tx) tx - внутренний параметр
	{ 1165	,8	,1	, &internal1_m865_tx},	//(internal1_m865_tx) tx - внутренний параметр
	{ 1166	,8	,1	, &internal1_m864_tx},	//(internal1_m864_tx) tx - внутренний параметр
	{ 1167	,8	,1	, &internal1_m1330_tx},	//(internal1_m1330_tx) tx - внутренний параметр
	{ 1168	,8	,1	, &internal1_m1327_tx},	//(internal1_m1327_tx) tx - внутренний параметр
	{ 1169	,8	,1	, &internal1_m1326_tx},	//(internal1_m1326_tx) tx - внутренний параметр
	{ 1170	,8	,1	, &internal1_m1087_tx},	//(internal1_m1087_tx) tx - внутренний параметр
	{ 1171	,8	,1	, &internal1_m2272_tx},	//(internal1_m2272_tx) tx - внутренний параметр
	{ 1172	,8	,1	, &internal1_m1098_tx},	//(internal1_m1098_tx) tx - внутренний параметр
	{ 1173	,8	,1	, &internal1_m1100_tx},	//(internal1_m1100_tx) tx - внутренний параметр
	{ 1174	,8	,1	, &internal1_m1099_tx},	//(internal1_m1099_tx) tx - внутренний параметр
	{ 1175	,8	,1	, &internal1_m2266_tx},	//(internal1_m2266_tx) tx - внутренний параметр
	{ 1176	,8	,1	, &internal1_m1089_tx},	//(internal1_m1089_tx) tx - внутренний параметр
	{ 1177	,8	,1	, &internal1_m2271_tx},	//(internal1_m2271_tx) tx - внутренний параметр
	{ 1178	,8	,1	, &internal1_m1097_tx},	//(internal1_m1097_tx) tx - внутренний параметр
	{ 1179	,8	,1	, &internal1_m1079_tx},	//(internal1_m1079_tx) tx - внутренний параметр
	{ 1180	,8	,1	, &internal1_m1078_tx},	//(internal1_m1078_tx) tx - внутренний параметр
	{ 1181	,8	,1	, &internal1_m1074_tx},	//(internal1_m1074_tx) tx - внутренний параметр
	{ 1182	,8	,1	, &internal1_m1096_tx},	//(internal1_m1096_tx) tx - внутренний параметр
	{ 1183	,8	,1	, &internal1_m1064_tx},	//(internal1_m1064_tx) tx - внутренний параметр
	{ 1184	,8	,1	, &internal1_m1062_tx},	//(internal1_m1062_tx) tx - внутренний параметр
	{ 1185	,8	,1	, &internal1_m1061_tx},	//(internal1_m1061_tx) tx - внутренний параметр
	{ 1186	,8	,1	, &internal1_m1040_tx},	//(internal1_m1040_tx) tx - внутренний параметр
	{ 1187	,8	,1	, &internal1_m1039_tx},	//(internal1_m1039_tx) tx - внутренний параметр
	{ 1188	,8	,1	, &internal1_m1029_tx},	//(internal1_m1029_tx) tx - внутренний параметр
	{ 1189	,8	,1	, &internal1_m1046_tx},	//(internal1_m1046_tx) tx - внутренний параметр
	{ 1190	,8	,1	, &internal1_m1465_tx},	//(internal1_m1465_tx) tx - внутренний параметр
	{ 1191	,8	,1	, &internal1_m1464_tx},	//(internal1_m1464_tx) tx - внутренний параметр
	{ 1192	,8	,1	, &internal1_m2218_tx},	//(internal1_m2218_tx) tx - внутренний параметр
	{ 1193	,8	,1	, &internal1_m1455_tx},	//(internal1_m1455_tx) tx - внутренний параметр
	{ 1194	,8	,1	, &internal1_m1456_tx},	//(internal1_m1456_tx) tx - внутренний параметр
	{ 1195	,8	,1	, &internal1_m1463_tx},	//(internal1_m1463_tx) tx - внутренний параметр
	{ 1196	,8	,1	, &internal1_m1446_tx},	//(internal1_m1446_tx) tx - внутренний параметр
	{ 1197	,8	,1	, &internal1_m1445_tx},	//(internal1_m1445_tx) tx - внутренний параметр
	{ 1198	,8	,1	, &internal1_m1441_tx},	//(internal1_m1441_tx) tx - внутренний параметр
	{ 1199	,8	,1	, &internal1_m1462_tx},	//(internal1_m1462_tx) tx - внутренний параметр
	{ 1200	,8	,1	, &internal1_m1428_tx},	//(internal1_m1428_tx) tx - внутренний параметр
	{ 1201	,8	,1	, &internal1_m1426_tx},	//(internal1_m1426_tx) tx - внутренний параметр
	{ 1202	,8	,1	, &internal1_m1435_tx},	//(internal1_m1435_tx) tx - внутренний параметр
	{ 1203	,8	,1	, &internal1_m255_tx},	//(internal1_m255_tx) tx - внутренний параметр
	{ 1204	,8	,1	, &internal1_m270_tx},	//(internal1_m270_tx) tx - внутренний параметр
	{ 1205	,8	,1	, &internal1_m278_tx},	//(internal1_m278_tx) tx - внутренний параметр
	{ 1206	,8	,1	, &internal1_m277_tx},	//(internal1_m277_tx) tx - внутренний параметр
	{ 1207	,8	,1	, &internal1_m261_tx},	//(internal1_m261_tx) tx - внутренний параметр
	{ 1208	,8	,1	, &internal1_m258_tx},	//(internal1_m258_tx) tx - внутренний параметр
	{ 1209	,8	,1	, &internal1_m274_tx},	//(internal1_m274_tx) tx - внутренний параметр
	{ 1210	,8	,1	, &internal1_m246_tx},	//(internal1_m246_tx) tx - внутренний параметр
	{ 1211	,8	,1	, &internal1_m245_tx},	//(internal1_m245_tx) tx - внутренний параметр
	{ 1212	,8	,1	, &internal1_m241_tx},	//(internal1_m241_tx) tx - внутренний параметр
	{ 1213	,8	,1	, &internal1_m273_tx},	//(internal1_m273_tx) tx - внутренний параметр
	{ 1214	,8	,1	, &internal1_m230_tx},	//(internal1_m230_tx) tx - внутренний параметр
	{ 1215	,8	,1	, &internal1_m232_tx},	//(internal1_m232_tx) tx - внутренний параметр
	{ 1216	,8	,1	, &internal1_m228_tx},	//(internal1_m228_tx) tx - внутренний параметр
	{ 1217	,8	,1	, &internal1_m204_tx},	//(internal1_m204_tx) tx - внутренний параметр
	{ 1218	,8	,1	, &internal1_m203_tx},	//(internal1_m203_tx) tx - внутренний параметр
	{ 1219	,8	,1	, &internal1_m202_tx},	//(internal1_m202_tx) tx - внутренний параметр
	{ 1220	,8	,1	, &internal1_m210_tx},	//(internal1_m210_tx) tx - внутренний параметр
	{ 1221	,8	,1	, &internal1_m1408_tx},	//(internal1_m1408_tx) tx - внутренний параметр
	{ 1222	,8	,1	, &internal1_m1390_tx},	//(internal1_m1390_tx) tx - внутренний параметр
	{ 1223	,8	,1	, &internal1_m1393_tx},	//(internal1_m1393_tx) tx - внутренний параметр
	{ 1224	,8	,1	, &internal1_m1412_tx},	//(internal1_m1412_tx) tx - внутренний параметр
	{ 1225	,8	,1	, &internal1_m929_tx},	//(internal1_m929_tx) tx - внутренний параметр
	{ 1226	,8	,1	, &internal1_m934_tx},	//(internal1_m934_tx) tx - внутренний параметр
	{ 1227	,8	,1	, &internal1_m924_tx},	//(internal1_m924_tx) tx - внутренний параметр
	{ 1228	,8	,1	, &internal1_m925_tx},	//(internal1_m925_tx) tx - внутренний параметр
	{ 1229	,1	,1	, &internal1_m1913_q0},	//(internal1_m1913_q0) q0 - внутренний параметр
	{ 1230	,1	,1	, &internal1_m2355_q0},	//(internal1_m2355_q0) q0 - внутренний параметр
	{ 1231	,1	,1	, &internal1_m2339_q0},	//(internal1_m2339_q0) q0 - внутренний параметр
	{ 1232	,1	,1	, &internal1_m2386_q0},	//(internal1_m2386_q0) q0 - внутренний параметр
	{ 1233	,1	,1	, &internal1_m2370_q0},	//(internal1_m2370_q0) q0 - внутренний параметр
	{ 1234	,1	,1	, &internal1_m2361_q0},	//(internal1_m2361_q0) q0 - внутренний параметр
	{ 1235	,1	,1	, &internal1_m2342_q0},	//(internal1_m2342_q0) q0 - внутренний параметр
	{ 1236	,1	,1	, &internal1_m2359_q0},	//(internal1_m2359_q0) q0 - внутренний параметр
	{ 1237	,1	,1	, &internal1_m2340_q0},	//(internal1_m2340_q0) q0 - внутренний параметр
	{ 1238	,1	,1	, &internal1_m2338_q0},	//(internal1_m2338_q0) q0 - внутренний параметр
	{ 1239	,1	,1	, &internal1_m2337_q0},	//(internal1_m2337_q0) q0 - внутренний параметр
	{ 1240	,1	,1	, &internal1_m2351_q0},	//(internal1_m2351_q0) q0 - внутренний параметр
	{ 1241	,1	,1	, &internal1_m2349_q0},	//(internal1_m2349_q0) q0 - внутренний параметр
	{ 1242	,1	,1	, &internal1_m2357_q0},	//(internal1_m2357_q0) q0 - внутренний параметр
	{ 1243	,1	,1	, &internal1_m2353_q0},	//(internal1_m2353_q0) q0 - внутренний параметр
	{ 1244	,1	,1	, &internal1_m2392_q0},	//(internal1_m2392_q0) q0 - внутренний параметр
	{ 1245	,1	,1	, &internal1_m2373_q0},	//(internal1_m2373_q0) q0 - внутренний параметр
	{ 1246	,1	,1	, &internal1_m2390_q0},	//(internal1_m2390_q0) q0 - внутренний параметр
	{ 1247	,1	,1	, &internal1_m2372_q0},	//(internal1_m2372_q0) q0 - внутренний параметр
	{ 1248	,1	,1	, &internal1_m2369_q0},	//(internal1_m2369_q0) q0 - внутренний параметр
	{ 1249	,1	,1	, &internal1_m2368_q0},	//(internal1_m2368_q0) q0 - внутренний параметр
	{ 1250	,1	,1	, &internal1_m2382_q0},	//(internal1_m2382_q0) q0 - внутренний параметр
	{ 1251	,1	,1	, &internal1_m2380_q0},	//(internal1_m2380_q0) q0 - внутренний параметр
	{ 1252	,8	,1	, &internal1_m2243_tx},	//(internal1_m2243_tx) tx - внутренний параметр
	{ 1253	,8	,1	, &internal1_m2222_tx},	//(internal1_m2222_tx) tx - внутренний параметр
	{ 1254	,1	,1	, &internal1_m1937_Pv0},	//(internal1_m1937_Pv0)  - Пер. выключатель механизма
	{ 1255	,1	,1	, &internal1_m1937_Zv0},	//(internal1_m1937_Zv0)  - Зад. выключатель механизма
	{ 1256	,1	,1	, &internal1_m1937_MyFirstEnterFlag},	//(internal1_m1937_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1257	,1	,1	, &internal1_m1934_Pv0},	//(internal1_m1934_Pv0)  - Пер. выключатель механизма
	{ 1258	,1	,1	, &internal1_m1934_Zv0},	//(internal1_m1934_Zv0)  - Зад. выключатель механизма
	{ 1259	,1	,1	, &internal1_m1934_MyFirstEnterFlag},	//(internal1_m1934_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1260	,8	,1	, &internal1_m2410_tx},	//(internal1_m2410_tx) tx - время накопленное сек
	{ 1261	,18	,1	, &internal1_m2410_y0},	//(internal1_m2410_y0) y0
	{ 1262	,8	,1	, &internal1_m2414_tx},	//(internal1_m2414_tx) tx - время накопленное сек
	{ 1263	,18	,1	, &internal1_m2414_y0},	//(internal1_m2414_y0) y0
	{ 1264	,8	,1	, &internal1_m2413_tx},	//(internal1_m2413_tx) tx - время накопленное сек
	{ 1265	,18	,1	, &internal1_m2413_y0},	//(internal1_m2413_y0) y0
	{ 1266	,8	,1	, &internal1_m2450_tx},	//(internal1_m2450_tx) tx - внутренний параметр
	{ 1267	,8	,1	, &internal1_m2448_tx},	//(internal1_m2448_tx) tx - время накопленное сек
	{ 1268	,18	,1	, &internal1_m2448_y0},	//(internal1_m2448_y0) y0
	{ 1269	,1	,1	, &internal1_m2453_q0},	//(internal1_m2453_q0) q0 - внутренний параметр
	{ 1270	,1	,1	, &internal1_m2420_q0},	//(internal1_m2420_q0) q0 - внутренний параметр
	{ 1271	,8	,1	, &internal1_m2428_tx},	//(internal1_m2428_tx) tx - внутренний параметр
	{ 1272	,1	,1	, &internal1_m2426_q0},	//(internal1_m2426_q0) q0 - внутренний параметр
	{ 1273	,8	,1	, &internal1_m2408_fVf0},	//(internal1_m2408_fVf0)  - скорость изменения мощности 
	{ 1274	,8	,1	, &internal1_m2408_fRsg},	//(internal1_m2408_fRsg)  - рассогласование между текущей и заданной мощностью 
	{ 1275	,8	,1	, &internal1_m2408_fRct},	//(internal1_m2408_fRct)  - стартовая реактивность регулятора 
	{ 1276	,8	,1	, &internal1_m2408_fVfMin},	//(internal1_m2408_fVfMin)  - минимальная скорость 
	{ 1277	,8	,1	, &internal1_m2408_fStw0},	//(internal1_m2408_fStw0)  - значение стартовой мощности включения ИМ 
	{ 1278	,8	,1	, &internal1_m2408_fMaxDk},	//(internal1_m2408_fMaxDk)  - изменение координаты при смене задания 
	{ 1279	,8	,1	, &internal1_m2408_fkizm},	//(internal1_m2408_fkizm)  - стартовая координата положения ИМ 0-й реактивности 
	{ 1280	,8	,1	, &internal1_m2408_fwt0},	//(internal1_m2408_fwt0)  - мощность на предыдущем шаге 
	{ 1281	,8	,1	, &internal1_m2408_fwz0},	//(internal1_m2408_fwz0)  - заданная мощность на предыдущем шаге 
	{ 1282	,8	,1	, &internal1_m2408_ftf0},	//(internal1_m2408_ftf0)  - время от фиксации предыдущей мощности 
	{ 1283	,8	,1	, &internal1_m2408_fTk0},	//(internal1_m2408_fTk0)  - последняя температура 
	{ 1284	,3	,1	, &internal1_m2408_FlPar},	//(internal1_m2408_FlPar) - стартовый этап регулирования
	{ 1285	,3	,1	, &internal1_m2408_FlIzm},	//(internal1_m2408_FlIzm) - флаг изменения направления изменения мощности
	{ 1286	,3	,1	, &internal1_m2408_FlCmp},	//(internal1_m2408_FlCmp) - текущее направление изменения мощности
	{ 1287	,3	,1	, &internal1_m2408_StabCoun},	//(internal1_m2408_StabCoun) - счётчик стабильности
	{ 1288	,3	,1	, &internal1_m2408_ZerCoun},	//(internal1_m2408_ZerCoun) - счётчик полной остановки
	{ 1289	,3	,1	, &internal1_m2408_SrCoun},	//(internal1_m2408_SrCoun)  - счётчик усреднения
	{ 1290	,3	,1	, &internal1_m2408_LastStage},	//(internal1_m2408_LastStage)  - последний этап
	{ 1291	,1	,1	, &internal1_m2408_fef},	//(internal1_m2408_fef)  - первый вход
	{ 1292	,8	,1	, &internal1_m2237_tx},	//(internal1_m2237_tx) tx - время накопленное сек
	{ 1293	,18	,1	, &internal1_m2237_y0},	//(internal1_m2237_y0) y0
	{ 1294	,8	,1	, &internal1_m2229_tx},	//(internal1_m2229_tx) tx - время накопленное сек
	{ 1295	,18	,1	, &internal1_m2229_y0},	//(internal1_m2229_y0) y0
	{ 1296	,1	,1	, &internal1_m1923_q0},	//(internal1_m1923_q0) q0 - внутренний параметр
	{ 1297	,1	,1	, &internal1_m1928_q0},	//(internal1_m1928_q0) q0 - внутренний параметр
	{ 1298	,1	,1	, &internal1_m1920_q0},	//(internal1_m1920_q0) q0 - внутренний параметр
	{ 1299	,1	,1	, &internal1_m1962_q0},	//(internal1_m1962_q0) q0 - внутренний параметр
	{ 1300	,8	,1	, &internal1_m834_tx},	//(internal1_m834_tx) tx - время накопленное сек
	{ 1301	,18	,1	, &internal1_m834_y0},	//(internal1_m834_y0) y0
	{ 1302	,8	,1	, &internal1_m2233_tx},	//(internal1_m2233_tx) tx - внутренний параметр
	{ 1303	,1	,1	, &internal1_m2236_q0},	//(internal1_m2236_q0) q0 - внутренний параметр
	{ 1304	,1	,1	, &internal1_m2228_q0},	//(internal1_m2228_q0) q0 - внутренний параметр
	{ 1305	,8	,1	, &internal1_m2197_tx},	//(internal1_m2197_tx) tx - внутренний параметр
	{ 1306	,8	,1	, &internal1_m2208_tx},	//(internal1_m2208_tx) tx - внутренний параметр
	{ 1307	,8	,1	, &internal1_m2194_tx},	//(internal1_m2194_tx) tx - внутренний параметр
	{ 1308	,1	,1	, &internal1_m2200_q0},	//(internal1_m2200_q0) q0 - внутренний параметр
	{ 1309	,1	,1	, &internal1_m2212_q0},	//(internal1_m2212_q0) q0 - внутренний параметр
	{ 1310	,8	,1	, &internal1_m2169_tx},	//(internal1_m2169_tx) tx - внутренний параметр
	{ 1311	,8	,1	, &internal1_m52_tx},	//(internal1_m52_tx) tx - внутренний параметр
	{ 1312	,8	,1	, &internal1_m368_tx},	//(internal1_m368_tx) tx - внутренний параметр
	{ 1313	,8	,1	, &internal1_m322_tx},	//(internal1_m322_tx) tx - внутренний параметр
	{ 1314	,8	,1	, &internal1_m835_tx},	//(internal1_m835_tx) tx - внутренний параметр
	{ 1315	,8	,1	, &internal1_m1627_tx},	//(internal1_m1627_tx) tx - внутренний параметр
	{ 1316	,8	,1	, &internal1_m120_tx},	//(internal1_m120_tx) tx - внутренний параметр
	{ 1317	,8	,1	, &internal1_m122_tx},	//(internal1_m122_tx) tx - внутренний параметр
	{ 1318	,8	,1	, &internal1_m127_tx},	//(internal1_m127_tx) tx - внутренний параметр
	{ 1319	,8	,1	, &internal1_m21_tx},	//(internal1_m21_tx) tx - внутренний параметр
	{ 1320	,8	,1	, &internal1_m13_tx},	//(internal1_m13_tx) tx - внутренний параметр
	{ 1321	,8	,1	, &internal1_m2179_tx},	//(internal1_m2179_tx) tx - внутренний параметр
	{ 1322	,8	,1	, &internal1_m2166_tx},	//(internal1_m2166_tx) tx - внутренний параметр
	{ 1323	,8	,1	, &internal1_m2284_tx},	//(internal1_m2284_tx) tx - внутренний параметр
	{ 1324	,8	,1	, &internal1_m2286_tx},	//(internal1_m2286_tx) tx - внутренний параметр
	{ 1325	,8	,1	, &internal1_m82_tx},	//(internal1_m82_tx) tx - внутренний параметр
	{ 1326	,8	,1	, &internal1_m339_tx},	//(internal1_m339_tx) tx - время накопленное сек
	{ 1327	,18	,1	, &internal1_m339_y0},	//(internal1_m339_y0) y0
	{ 1328	,8	,1	, &internal1_m2077_tx},	//(internal1_m2077_tx) tx - время накопленное сек
	{ 1329	,18	,1	, &internal1_m2077_y0},	//(internal1_m2077_y0) y0
	{ 1330	,8	,1	, &internal1_m2091_q0},	//(internal1_m2091_q0) q0 - внутренний параметр
	{ 1331	,8	,1	, &internal1_m1648_q0},	//(internal1_m1648_q0) q0 - внутренний параметр
	{ 1332	,8	,1	, &internal1_m1686_q0},	//(internal1_m1686_q0) q0 - внутренний параметр
	{ 1333	,8	,1	, &internal1_m1689_q0},	//(internal1_m1689_q0) q0 - внутренний параметр
	{ 1334	,8	,1	, &internal1_m2131_q0},	//(internal1_m2131_q0) q0 - внутренний параметр
	{ 1335	,8	,1	, &internal1_m2109_tx},	//(internal1_m2109_tx) tx - время накопленное сек
	{ 1336	,18	,1	, &internal1_m2109_y0},	//(internal1_m2109_y0) y0
	{ 1337	,8	,1	, &internal1_m2124_tx},	//(internal1_m2124_tx) tx - время накопленное сек
	{ 1338	,18	,1	, &internal1_m2124_y0},	//(internal1_m2124_y0) y0
	{ 1339	,8	,1	, &internal1_m2121_tx},	//(internal1_m2121_tx) tx - время накопленное сек
	{ 1340	,18	,1	, &internal1_m2121_y0},	//(internal1_m2121_y0) y0
	{ 1341	,8	,1	, &internal1_m2264_tx},	//(internal1_m2264_tx) tx - время накопленное сек
	{ 1342	,18	,1	, &internal1_m2264_y0},	//(internal1_m2264_y0) y0
	{ 1343	,8	,1	, &internal1_m2275_tx},	//(internal1_m2275_tx) tx - время накопленное сек
	{ 1344	,18	,1	, &internal1_m2275_y0},	//(internal1_m2275_y0) y0
	{ 1345	,8	,1	, &internal1_m2030_tx},	//(internal1_m2030_tx) tx - время накопленное сек
	{ 1346	,18	,1	, &internal1_m2030_y0},	//(internal1_m2030_y0) y0
	{ 1347	,8	,1	, &internal1_m2029_tx},	//(internal1_m2029_tx) tx - время накопленное сек
	{ 1348	,18	,1	, &internal1_m2029_y0},	//(internal1_m2029_y0) y0
	{ 1349	,8	,1	, &internal1_m2028_tx},	//(internal1_m2028_tx) tx - время накопленное сек
	{ 1350	,18	,1	, &internal1_m2028_y0},	//(internal1_m2028_y0) y0
	{ 1351	,8	,1	, &internal1_m2027_tx},	//(internal1_m2027_tx) tx - время накопленное сек
	{ 1352	,18	,1	, &internal1_m2027_y0},	//(internal1_m2027_y0) y0
	{ 1353	,8	,1	, &internal1_m1702_tx},	//(internal1_m1702_tx) tx - время накопленное сек
	{ 1354	,18	,1	, &internal1_m1702_y0},	//(internal1_m1702_y0) y0
	{ 1355	,8	,1	, &internal1_m1696_tx},	//(internal1_m1696_tx) tx - время накопленное сек
	{ 1356	,18	,1	, &internal1_m1696_y0},	//(internal1_m1696_y0) y0
	{ 1357	,8	,1	, &internal1_m1643_tx},	//(internal1_m1643_tx) tx - время накопленное сек
	{ 1358	,18	,1	, &internal1_m1643_y0},	//(internal1_m1643_y0) y0
	{ 1359	,8	,1	, &internal1_m922_tx},	//(internal1_m922_tx) tx - время накопленное сек
	{ 1360	,18	,1	, &internal1_m922_y0},	//(internal1_m922_y0) y0
	{ 1361	,8	,1	, &internal1_m921_tx},	//(internal1_m921_tx) tx - время накопленное сек
	{ 1362	,18	,1	, &internal1_m921_y0},	//(internal1_m921_y0) y0
	{ 1363	,8	,1	, &internal1_m939_tx},	//(internal1_m939_tx) tx - время накопленное сек
	{ 1364	,18	,1	, &internal1_m939_y0},	//(internal1_m939_y0) y0
	{ 1365	,8	,1	, &internal1_m194_tx},	//(internal1_m194_tx) tx - время накопленное сек
	{ 1366	,18	,1	, &internal1_m194_y0},	//(internal1_m194_y0) y0
	{ 1367	,8	,1	, &internal1_m193_tx},	//(internal1_m193_tx) tx - время накопленное сек
	{ 1368	,18	,1	, &internal1_m193_y0},	//(internal1_m193_y0) y0
	{ 1369	,8	,1	, &internal1_m215_tx},	//(internal1_m215_tx) tx - время накопленное сек
	{ 1370	,18	,1	, &internal1_m215_y0},	//(internal1_m215_y0) y0
	{ 1371	,8	,1	, &internal1_m588_tx},	//(internal1_m588_tx) tx - время накопленное сек
	{ 1372	,18	,1	, &internal1_m588_y0},	//(internal1_m588_y0) y0
	{ 1373	,8	,1	, &internal1_m2320_tx},	//(internal1_m2320_tx) tx - внутренний параметр
	{ 1374	,8	,1	, &internal1_m1341_tx},	//(internal1_m1341_tx) tx - внутренний параметр
	{ 1375	,8	,1	, &internal1_m1832_tx},	//(internal1_m1832_tx) tx - время накопленное сек
	{ 1376	,18	,1	, &internal1_m1832_y0},	//(internal1_m1832_y0) y0
	{ 1377	,8	,1	, &internal1_m1306_tx},	//(internal1_m1306_tx) tx - время накопленное сек
	{ 1378	,18	,1	, &internal1_m1306_y0},	//(internal1_m1306_y0) y0
	{ 1379	,8	,1	, &internal1_m1525_tx},	//(internal1_m1525_tx) tx - время накопленное сек
	{ 1380	,18	,1	, &internal1_m1525_y0},	//(internal1_m1525_y0) y0
	{ 1381	,8	,1	, &internal1_m1052_tx},	//(internal1_m1052_tx) tx - время накопленное сек
	{ 1382	,18	,1	, &internal1_m1052_y0},	//(internal1_m1052_y0) y0
	{ 1383	,8	,1	, &internal1_m1415_tx},	//(internal1_m1415_tx) tx - время накопленное сек
	{ 1384	,18	,1	, &internal1_m1415_y0},	//(internal1_m1415_y0) y0
	{ 1385	,1	,1	, &internal1_m1209_q0},	//(internal1_m1209_q0) q0 - внутренний параметр
	{ 1386	,1	,1	, &internal1_m1207_q0},	//(internal1_m1207_q0) q0 - внутренний параметр
	{ 1387	,1	,1	, &internal1_m1206_q0},	//(internal1_m1206_q0) q0 - внутренний параметр
	{ 1388	,1	,1	, &internal1_m1204_q0},	//(internal1_m1204_q0) q0 - внутренний параметр
	{ 1389	,1	,1	, &internal1_m1203_q0},	//(internal1_m1203_q0) q0 - внутренний параметр
	{ 1390	,1	,1	, &internal1_m1201_q0},	//(internal1_m1201_q0) q0 - внутренний параметр
	{ 1391	,1	,1	, &internal1_m1200_q0},	//(internal1_m1200_q0) q0 - внутренний параметр
	{ 1392	,1	,1	, &internal1_m1198_q0},	//(internal1_m1198_q0) q0 - внутренний параметр
	{ 1393	,1	,1	, &internal1_m1197_q0},	//(internal1_m1197_q0) q0 - внутренний параметр
	{ 1394	,1	,1	, &internal1_m54_x0},	//(internal1_m54_x0) - значение входного параметра на предыдущем шаге
	{ 1395	,8	,1	, &internal1_m54_tim},	//(internal1_m54_tim) - время задержки выходного сигнала
	{ 1396	,1	,1	, &internal1_m1116_q0},	//(internal1_m1116_q0) q0 - внутренний параметр
	{ 1397	,1	,1	, &internal1_m1637_x0},	//(internal1_m1637_x0) - значение входного параметра на предыдущем шаге
	{ 1398	,8	,1	, &internal1_m1637_tim},	//(internal1_m1637_tim) - время задержки выходного сигнала
	{ 1399	,1	,1	, &internal1_m1685_x0},	//(internal1_m1685_x0) - значение входного параметра на предыдущем шаге
	{ 1400	,8	,1	, &internal1_m1685_tim},	//(internal1_m1685_tim) - время задержки выходного сигнала
	{ 1401	,1	,1	, &internal1_m1688_x0},	//(internal1_m1688_x0) - значение входного параметра на предыдущем шаге
	{ 1402	,8	,1	, &internal1_m1688_tim},	//(internal1_m1688_tim) - время задержки выходного сигнала
	{ 1403	,1	,1	, &internal1_m2072_x0},	//(internal1_m2072_x0) - значение входного параметра на предыдущем шаге
	{ 1404	,8	,1	, &internal1_m2072_tim},	//(internal1_m2072_tim) - время задержки выходного сигнала
	{ 1405	,1	,1	, &internal1_m1156_q0},	//(internal1_m1156_q0) q0 - внутренний параметр
	{ 1406	,1	,1	, &internal1_m1162_q0},	//(internal1_m1162_q0) q0 - внутренний параметр
	{ 1407	,1	,1	, &internal1_m1180_q0},	//(internal1_m1180_q0) q0 - внутренний параметр
	{ 1408	,1	,1	, &internal1_m1189_q0},	//(internal1_m1189_q0) q0 - внутренний параметр
	{ 1409	,1	,1	, &internal1_m1168_q0},	//(internal1_m1168_q0) q0 - внутренний параметр
	{ 1410	,1	,1	, &internal1_m1182_q0},	//(internal1_m1182_q0) q0 - внутренний параметр
	{ 1411	,1	,1	, &internal1_m2158_q0},	//(internal1_m2158_q0) q0 - внутренний параметр
	{ 1412	,1	,1	, &internal1_m2157_q0},	//(internal1_m2157_q0) q0 - внутренний параметр
	{ 1413	,3	,1	, &internal1_m356_Step},	//(internal1_m356_Step)  - текущий шаг программы
	{ 1414	,18	,10	, &internal1_m356_rz},	//(internal1_m356_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1415	,8	,1	, &internal1_m356_TimS},	//(internal1_m356_TimS) Время от старта программы
	{ 1416	,1	,1	, &internal1_m356_FinPr0},	//(internal1_m356_FinPr0) FinPr - конец программы
	{ 1417	,1	,1	, &internal1_m356_ErrPr0},	//(internal1_m356_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1418	,1	,1	, &internal1_m356_sbINI0},	//(internal1_m356_sbINI0) sbINI - запуск проверки ИНИ
	{ 1419	,1	,1	, &internal1_m356_sbVuIS0},	//(internal1_m356_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1420	,1	,1	, &internal1_m356_sb2UR0},	//(internal1_m356_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1421	,1	,1	, &internal1_m356_sbNupIS0},	//(internal1_m356_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1422	,1	,1	, &internal1_m356_sbVuRB0},	//(internal1_m356_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1423	,1	,1	, &internal1_m356_MyFirstEnterFlag},	//(internal1_m356_MyFirstEnterFlag)  
	{ 1424	,5	,1	, &internal1_m364_x0},	//(internal1_m364_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1425	,8	,1	, &internal1_m321_TimS},	//(internal1_m321_TimS) Время до нулевого отсчета
	{ 1426	,1	,1	, &internal1_m321_pusk0},	//(internal1_m321_pusk0) pusk - разрешение выполнения программы
	{ 1427	,3	,1	, &internal1_m298_Step},	//(internal1_m298_Step)  - текущий шаг программы
	{ 1428	,18	,10	, &internal1_m298_rz},	//(internal1_m298_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1429	,8	,1	, &internal1_m298_TimS},	//(internal1_m298_TimS) Время от старта программы
	{ 1430	,1	,1	, &internal1_m298_FinPr0},	//(internal1_m298_FinPr0) FinPr - конец программы
	{ 1431	,1	,1	, &internal1_m298_ErrPr0},	//(internal1_m298_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1432	,1	,1	, &internal1_m298_sbINI0},	//(internal1_m298_sbINI0) sbINI - запуск проверки ИНИ
	{ 1433	,1	,1	, &internal1_m298_sbVuIS0},	//(internal1_m298_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1434	,1	,1	, &internal1_m298_sb2UR0},	//(internal1_m298_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1435	,1	,1	, &internal1_m298_sbNupIS0},	//(internal1_m298_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1436	,1	,1	, &internal1_m298_sbVuRB0},	//(internal1_m298_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1437	,1	,1	, &internal1_m298_MyFirstEnterFlag},	//(internal1_m298_MyFirstEnterFlag)  
	{ 1438	,1	,1	, &internal1_m1599_q0},	//(internal1_m1599_q0) q0 - внутренний параметр
	{ 1439	,3	,1	, &internal1_m1600_Step},	//(internal1_m1600_Step)  - текущий шаг программы
	{ 1440	,18	,6	, &internal1_m1600_rz},	//(internal1_m1600_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1441	,8	,1	, &internal1_m1600_TimS},	//(internal1_m1600_TimS) Время от старта программы
	{ 1442	,1	,1	, &internal1_m1600_FinPr0},	//(internal1_m1600_FinPr0) FinPr - конец программы
	{ 1443	,1	,1	, &internal1_m1600_ErrPr0},	//(internal1_m1600_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1444	,1	,1	, &internal1_m1600_sbINI0},	//(internal1_m1600_sbINI0) sbINI - запуск проверки ИНИ
	{ 1445	,1	,1	, &internal1_m1600_sbVuIS0},	//(internal1_m1600_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1446	,1	,1	, &internal1_m1600_sb2UR0},	//(internal1_m1600_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1447	,1	,1	, &internal1_m1600_sbNupIS0},	//(internal1_m1600_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1448	,1	,1	, &internal1_m1600_sbVuRB0},	//(internal1_m1600_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1449	,1	,1	, &internal1_m1600_MyFirstEnterFlag},	//(internal1_m1600_MyFirstEnterFlag)  
	{ 1450	,1	,1	, &internal1_m1152_q0},	//(internal1_m1152_q0) q0 - внутренний параметр
	{ 1451	,1	,1	, &internal1_m1149_q0},	//(internal1_m1149_q0) q0 - внутренний параметр
	{ 1452	,1	,1	, &internal1_m1151_q0},	//(internal1_m1151_q0) q0 - внутренний параметр
	{ 1453	,1	,1	, &internal1_m1145_q0},	//(internal1_m1145_q0) q0 - внутренний параметр
	{ 1454	,1	,1	, &internal1_m836_q0},	//(internal1_m836_q0) q0 - внутренний параметр
	{ 1455	,1	,1	, &internal1_m366_q0},	//(internal1_m366_q0) q0 - внутренний параметр
	{ 1456	,1	,1	, &internal1_m362_q0},	//(internal1_m362_q0) q0 - внутренний параметр
	{ 1457	,1	,1	, &internal1_m318_q0},	//(internal1_m318_q0) q0 - внутренний параметр
	{ 1458	,5	,1	, &internal1_m317_x0},	//(internal1_m317_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1459	,1	,1	, &internal1_m2087_q0},	//(internal1_m2087_q0) q0 - внутренний параметр
	{ 1460	,1	,1	, &internal1_m2080_q0},	//(internal1_m2080_q0) q0 - внутренний параметр
	{ 1461	,1	,1	, &internal1_m2073_q0},	//(internal1_m2073_q0) q0 - внутренний параметр
	{ 1462	,1	,1	, &internal1_m2141_q0},	//(internal1_m2141_q0) q0 - внутренний параметр
	{ 1463	,1	,1	, &internal1_m2112_q0},	//(internal1_m2112_q0) q0 - внутренний параметр
	{ 1464	,1	,1	, &internal1_m2100_q0},	//(internal1_m2100_q0) q0 - внутренний параметр
	{ 1465	,1	,1	, &internal1_m1664_q0},	//(internal1_m1664_q0) q0 - внутренний параметр
	{ 1466	,1	,1	, &internal1_m1651_x0},	//(internal1_m1651_x0) был приход сигнала x1
	{ 1467	,8	,1	, &internal1_m1651_y0},	//(internal1_m1651_y0) интервал между сигналами х1 и х2
	{ 1468	,1	,1	, &internal1_m1651_fef},	//(internal1_m1651_fef) FirstEnterFlag
	{ 1469	,1	,1	, &internal1_m1646_q0},	//(internal1_m1646_q0) q0 - внутренний параметр
	{ 1470	,1	,1	, &internal1_m1636_q0},	//(internal1_m1636_q0) q0 - внутренний параметр
	{ 1471	,1	,1	, &internal1_m1699_q0},	//(internal1_m1699_q0) q0 - внутренний параметр
	{ 1472	,1	,1	, &internal1_m1720_q0},	//(internal1_m1720_q0) q0 - внутренний параметр
	{ 1473	,1	,1	, &internal1_m1684_q0},	//(internal1_m1684_q0) q0 - внутренний параметр
	{ 1474	,1	,1	, &internal1_m1700_x0},	//(internal1_m1700_x0) был приход сигнала x1
	{ 1475	,8	,1	, &internal1_m1700_y0},	//(internal1_m1700_y0) интервал между сигналами х1 и х2
	{ 1476	,1	,1	, &internal1_m1700_fef},	//(internal1_m1700_fef) FirstEnterFlag
	{ 1477	,5	,1	, &internal1_m1617_x0},	//(internal1_m1617_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1478	,1	,1	, &internal1_m1706_q0},	//(internal1_m1706_q0) q0 - внутренний параметр
	{ 1479	,1	,1	, &internal1_m26_q0},	//(internal1_m26_q0) q0 - внутренний параметр
	{ 1480	,1	,1	, &internal1_m1721_q0},	//(internal1_m1721_q0) q0 - внутренний параметр
	{ 1481	,1	,1	, &internal1_m711_q0},	//(internal1_m711_q0) q0 - внутренний параметр
	{ 1482	,1	,1	, &internal1_m696_q0},	//(internal1_m696_q0) q0 - внутренний параметр
	{ 1483	,1	,1	, &internal1_m724_q0},	//(internal1_m724_q0) q0 - внутренний параметр
	{ 1484	,1	,1	, &internal1_m707_q0},	//(internal1_m707_q0) q0 - внутренний параметр
	{ 1485	,1	,1	, &internal1_m691_q0},	//(internal1_m691_q0) q0 - внутренний параметр
	{ 1486	,1	,1	, &internal1_m689_q0},	//(internal1_m689_q0) q0 - внутренний параметр
	{ 1487	,1	,1	, &internal1_m677_q0},	//(internal1_m677_q0) q0 - внутренний параметр
	{ 1488	,5	,1	, &internal1_m1602_q0},	//(internal1_m1602_q0) q0 - внутренний параметр
	{ 1489	,1	,1	, &internal1_m687_q0},	//(internal1_m687_q0) q0 - внутренний параметр
	{ 1490	,1	,1	, &internal1_m116_q0},	//(internal1_m116_q0) q0 - внутренний параметр
	{ 1491	,1	,1	, &internal1_m1867_q0},	//(internal1_m1867_q0) q0 - внутренний параметр
	{ 1492	,1	,1	, &internal1_m1866_q0},	//(internal1_m1866_q0) q0 - внутренний параметр
	{ 1493	,1	,1	, &internal1_m1865_q0},	//(internal1_m1865_q0) q0 - внутренний параметр
	{ 1494	,1	,1	, &internal1_m1864_q0},	//(internal1_m1864_q0) q0 - внутренний параметр
	{ 1495	,1	,1	, &internal1_m1900_q0},	//(internal1_m1900_q0) q0 - внутренний параметр
	{ 1496	,1	,1	, &internal1_m1899_q0},	//(internal1_m1899_q0) q0 - внутренний параметр
	{ 1497	,1	,1	, &internal1_m1898_q0},	//(internal1_m1898_q0) q0 - внутренний параметр
	{ 1498	,1	,1	, &internal1_m2172_q0},	//(internal1_m2172_q0) q0 - внутренний параметр
	{ 1499	,1	,1	, &internal1_m1960_q0},	//(internal1_m1960_q0) q0 - внутренний параметр
	{ 1500	,1	,1	, &internal1_m1950_q0},	//(internal1_m1950_q0) q0 - внутренний параметр
	{ 1501	,1	,1	, &internal1_m1957_q0},	//(internal1_m1957_q0) q0 - внутренний параметр
	{ 1502	,1	,1	, &internal1_m1947_q0},	//(internal1_m1947_q0) q0 - внутренний параметр
	{ 1503	,1	,1	, &internal1_m1954_q0},	//(internal1_m1954_q0) q0 - внутренний параметр
	{ 1504	,1	,1	, &internal1_m2388_q0},	//(internal1_m2388_q0) q0 - внутренний параметр
	{ 1505	,1	,1	, &internal1_m2384_q0},	//(internal1_m2384_q0) q0 - внутренний параметр
	{ 1506	,1	,1	, &internal1_m1925_q0},	//(internal1_m1925_q0) q0 - внутренний параметр
	{ 1507	,1	,1	, &internal1_m1917_q0},	//(internal1_m1917_q0) q0 - внутренний параметр
	{ 1508	,1	,1	, &internal1_m1915_q0},	//(internal1_m1915_q0) q0 - внутренний параметр
	{ 1509	,1	,1	, &internal1_m1911_q0},	//(internal1_m1911_q0) q0 - внутренний параметр
	{ 1510	,1	,1	, &internal1_m1907_q0},	//(internal1_m1907_q0) q0 - внутренний параметр
	{ 1511	,1	,1	, &internal1_m1909_q0},	//(internal1_m1909_q0) q0 - внутренний параметр
	{ 1512	,1	,1	, &internal1_m19_q0},	//(internal1_m19_q0) q0 - внутренний параметр
	{ 1513	,1	,1	, &internal1_m1890_q0},	//(internal1_m1890_q0) q0 - внутренний параметр
	{ 1514	,1	,1	, &internal1_m1888_q0},	//(internal1_m1888_q0) q0 - внутренний параметр
	{ 1515	,1	,1	, &internal1_m1884_q0},	//(internal1_m1884_q0) q0 - внутренний параметр
	{ 1516	,1	,1	, &internal1_m1886_q0},	//(internal1_m1886_q0) q0 - внутренний параметр
	{ 1517	,1	,1	, &internal1_m1882_q0},	//(internal1_m1882_q0) q0 - внутренний параметр
	{ 1518	,1	,1	, &internal1_m1880_q0},	//(internal1_m1880_q0) q0 - внутренний параметр
	{ 1519	,1	,1	, &internal1_m2294_q0},	//(internal1_m2294_q0) q0 - внутренний параметр
	{ 1520	,1	,1	, &internal1_m2292_q0},	//(internal1_m2292_q0) q0 - внутренний параметр
	{ 1521	,1	,1	, &internal1_m2269_q0},	//(internal1_m2269_q0) q0 - внутренний параметр
	{ 1522	,1	,1	, &internal1_m2253_q0},	//(internal1_m2253_q0) q0 - внутренний параметр
	{ 1523	,1	,1	, &internal1_m2184_q0},	//(internal1_m2184_q0) q0 - внутренний параметр
	{ 1524	,1	,1	, &internal1_m1876_q0},	//(internal1_m1876_q0) q0 - внутренний параметр
	{ 1525	,1	,1	, &internal1_m1878_q0},	//(internal1_m1878_q0) q0 - внутренний параметр
	{ 1526	,1	,1	, &internal1_m1862_q0},	//(internal1_m1862_q0) q0 - внутренний параметр
	{ 1527	,1	,1	, &internal1_m1860_q0},	//(internal1_m1860_q0) q0 - внутренний параметр
	{ 1528	,1	,1	, &internal1_m1858_q0},	//(internal1_m1858_q0) q0 - внутренний параметр
	{ 1529	,1	,1	, &internal1_m1856_q0},	//(internal1_m1856_q0) q0 - внутренний параметр
	{ 1530	,1	,1	, &internal1_m1855_q0},	//(internal1_m1855_q0) q0 - внутренний параметр
	{ 1531	,1	,1	, &internal1_m1853_q0},	//(internal1_m1853_q0) q0 - внутренний параметр
	{ 1532	,1	,1	, &internal1_m1852_q0},	//(internal1_m1852_q0) q0 - внутренний параметр
	{ 1533	,1	,1	, &internal1_m1850_q0},	//(internal1_m1850_q0) q0 - внутренний параметр
	{ 1534	,18	,1	, &internal1_m2325_DvUp0},	//(internal1_m2325_DvUp0) - есть команда на движение вперёд
	{ 1535	,18	,1	, &internal1_m2325_DvDw0},	//(internal1_m2325_DvDw0) - есть команда на движение назад
	{ 1536	,18	,1	, &internal1_m2325_FDvUp0},	//(internal1_m2325_FDvUp0) - есть команда на движение вперёд
	{ 1537	,18	,1	, &internal1_m2325_FDvDw0},	//(internal1_m2325_FDvDw0) - есть команда на движение назад
	{ 1538	,18	,1	, &internal1_m2325_BlDv0},	//(internal1_m2325_BlDv0) - была блокировка
	{ 1539	,18	,1	, &internal1_m2325_Pkv0},	//(internal1_m2325_Pkv0) Pkv - передний конечный выключатель
	{ 1540	,18	,1	, &internal1_m2325_Pkav0},	//(internal1_m2325_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1541	,18	,1	, &internal1_m2325_Zkv0},	//(internal1_m2325_Zkv0) Zkv - задний конечный выключатель
	{ 1542	,18	,1	, &internal1_m2325_Zkav0},	//(internal1_m2325_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1543	,8	,1	, &internal1_m2325_txNm},	//(internal1_m2325_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1544	,8	,1	, &internal1_m2325_txSm},	//(internal1_m2325_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1545	,8	,1	, &internal1_m2325_txHr},	//(internal1_m2325_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1546	,8	,1	, &internal1_m2325_txLd},	//(internal1_m2325_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1547	,18	,1	, &internal1_m2325_fef},	//(internal1_m2325_fef) fef
	{ 1548	,18	,1	, &internal1_m2319_DvUp0},	//(internal1_m2319_DvUp0) - есть команда на движение вперёд
	{ 1549	,18	,1	, &internal1_m2319_DvDw0},	//(internal1_m2319_DvDw0) - есть команда на движение назад
	{ 1550	,18	,1	, &internal1_m2319_FDvUp0},	//(internal1_m2319_FDvUp0) - есть команда на движение вперёд
	{ 1551	,18	,1	, &internal1_m2319_FDvDw0},	//(internal1_m2319_FDvDw0) - есть команда на движение назад
	{ 1552	,18	,1	, &internal1_m2319_BlDv0},	//(internal1_m2319_BlDv0) - была блокировка
	{ 1553	,18	,1	, &internal1_m2319_Pkv0},	//(internal1_m2319_Pkv0) Pkv - передний конечный выключатель
	{ 1554	,18	,1	, &internal1_m2319_Pkav0},	//(internal1_m2319_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1555	,18	,1	, &internal1_m2319_Zkv0},	//(internal1_m2319_Zkv0) Zkv - задний конечный выключатель
	{ 1556	,18	,1	, &internal1_m2319_Zkav0},	//(internal1_m2319_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1557	,8	,1	, &internal1_m2319_txNm},	//(internal1_m2319_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1558	,8	,1	, &internal1_m2319_txSm},	//(internal1_m2319_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1559	,8	,1	, &internal1_m2319_txHr},	//(internal1_m2319_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1560	,8	,1	, &internal1_m2319_txLd},	//(internal1_m2319_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1561	,18	,1	, &internal1_m2319_fef},	//(internal1_m2319_fef) fef
	{ 1562	,1	,1	, &internal1_m1679_q0},	//(internal1_m1679_q0) q0 - внутренний параметр
	{ 1563	,1	,1	, &internal1_m1705_x0},	//(internal1_m1705_x0) был приход сигнала x1
	{ 1564	,8	,1	, &internal1_m1705_y0},	//(internal1_m1705_y0) интервал между сигналами х1 и х2
	{ 1565	,1	,1	, &internal1_m1705_fef},	//(internal1_m1705_fef) FirstEnterFlag
	{ 1566	,1	,1	, &internal1_m2123_x0},	//(internal1_m2123_x0) был приход сигнала x1
	{ 1567	,8	,1	, &internal1_m2123_y0},	//(internal1_m2123_y0) интервал между сигналами х1 и х2
	{ 1568	,1	,1	, &internal1_m2123_fef},	//(internal1_m2123_fef) FirstEnterFlag
	{ 1569	,1	,1	, &internal1_m2082_x0},	//(internal1_m2082_x0) был приход сигнала x1
	{ 1570	,8	,1	, &internal1_m2082_y0},	//(internal1_m2082_y0) интервал между сигналами х1 и х2
	{ 1571	,1	,1	, &internal1_m2082_fef},	//(internal1_m2082_fef) FirstEnterFlag
	{ 1572	,1	,1	, &internal1_m309_q0},	//(internal1_m309_q0) q0 - внутренний параметр
	{ 1573	,1	,1	, &internal1_m1124_q0},	//(internal1_m1124_q0) q0 - внутренний параметр
	{ 1574	,1	,1	, &internal1_m699_q0},	//(internal1_m699_q0) q0 - внутренний параметр
	{ 1575	,8	,1	, &internal1_m1483_X0},	//(internal1_m1483_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1576	,8	,1	, &internal1_m1483_t0},	//(internal1_m1483_t0) время нахождения в зоне возврата
	{ 1577	,18	,1	, &internal1_m1483_BLDv0},	//(internal1_m1483_BLDv0) BlDv - Блокировка движения
	{ 1578	,8	,1	, &internal1_m1500_tx},	//(internal1_m1500_tx) tx - время накопленное сек
	{ 1579	,18	,1	, &internal1_m1500_y0},	//(internal1_m1500_y0) y0
	{ 1580	,8	,1	, &internal1_m1501_tx},	//(internal1_m1501_tx) tx - время накопленное сек
	{ 1581	,18	,1	, &internal1_m1501_y0},	//(internal1_m1501_y0) y0
	{ 1582	,3	,1	, &internal1_m1509_xptr},	//(internal1_m1509_xptr) указатель текущей позиции в массиве координат
	{ 1583	,8	,60	, &internal1_m1509_x0},	//(internal1_m1509_x0) x0 - массив мгновенных значений координат
	{ 1584	,8	,60	, &internal1_m1509_tim0},	//(internal1_m1509_tim0) tim0 - массив значений времени цикла
	{ 1585	,8	,1	, &internal1_m1509_sumtim},	//(internal1_m1509_sumtim) sumtim - время в пути
	{ 1586	,8	,1	, &internal1_m1509_StSpeed},	//(internal1_m1509_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1587	,8	,1	, &internal1_m1509_Vz0},	//(internal1_m1509_Vz0) Vz0 - предыдущая заданная скорость
	{ 1588	,3	,1	, &internal1_m1509_flRazg},	//(internal1_m1509_flRazg) признак разгона/торможения
	{ 1589	,8	,1	, &internal1_m1509_DelSp},	//(internal1_m1509_DelSp) DelSp - время переключения скоростей
	{ 1590	,8	,1	, &internal1_m1509_z0},	//(internal1_m1509_z0) z0 - точка прекращения движения
	{ 1591	,8	,1	, &internal1_m1509_txZS},	//(internal1_m1509_txZS) txZS
	{ 1592	,8	,1	, &internal1_m1509_tx},	//(internal1_m1509_tx) tx
	{ 1593	,8	,1	, &internal1_m1509_txd},	//(internal1_m1509_txd) txd
	{ 1594	,8	,1	, &internal1_m1509_txMBl},	//(internal1_m1509_txMBl) tx
	{ 1595	,8	,1	, &internal1_m1509_txBl},	//(internal1_m1509_txBl) tx
	{ 1596	,8	,1	, &internal1_m1509_Speed0},	//(internal1_m1509_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1597	,8	,1	, &internal1_m1509_xz0},	//(internal1_m1509_xz0) xz0 - новое задание мм
	{ 1598	,8	,1	, &internal1_m1509_tz0},	//(internal1_m1509_tz0) tz0 - время защиты от нового задания сек
	{ 1599	,1	,1	, &internal1_m1509_Shift0},	//(internal1_m1509_Shift0) Shift0 - признак самохода
	{ 1600	,1	,1	, &internal1_m1509_ShCntlSp0},	//(internal1_m1509_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1601	,1	,1	, &internal1_m1509_ShiftControl},	//(internal1_m1509_ShiftControl) ShiftControl - признак самохода
	{ 1602	,1	,1	, &internal1_m697_q0},	//(internal1_m697_q0) q0 - внутренний параметр
	{ 1603	,8	,1	, &internal1_m1005_X0},	//(internal1_m1005_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1604	,8	,1	, &internal1_m1005_t0},	//(internal1_m1005_t0) время нахождения в зоне возврата
	{ 1605	,18	,1	, &internal1_m1005_BLDv0},	//(internal1_m1005_BLDv0) BlDv - Блокировка движения
	{ 1606	,8	,1	, &internal1_m1028_tx},	//(internal1_m1028_tx) tx - время накопленное сек
	{ 1607	,18	,1	, &internal1_m1028_y0},	//(internal1_m1028_y0) y0
	{ 1608	,8	,1	, &internal1_m1027_tx},	//(internal1_m1027_tx) tx - время накопленное сек
	{ 1609	,18	,1	, &internal1_m1027_y0},	//(internal1_m1027_y0) y0
	{ 1610	,3	,1	, &internal1_m1035_xptr},	//(internal1_m1035_xptr) указатель текущей позиции в массиве координат
	{ 1611	,8	,60	, &internal1_m1035_x0},	//(internal1_m1035_x0) x0 - массив мгновенных значений координат
	{ 1612	,8	,60	, &internal1_m1035_tim0},	//(internal1_m1035_tim0) tim0 - массив значений времени цикла
	{ 1613	,8	,1	, &internal1_m1035_sumtim},	//(internal1_m1035_sumtim) sumtim - время в пути
	{ 1614	,8	,1	, &internal1_m1035_StSpeed},	//(internal1_m1035_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1615	,8	,1	, &internal1_m1035_Vz0},	//(internal1_m1035_Vz0) Vz0 - предыдущая заданная скорость
	{ 1616	,3	,1	, &internal1_m1035_flRazg},	//(internal1_m1035_flRazg) признак разгона/торможения
	{ 1617	,8	,1	, &internal1_m1035_DelSp},	//(internal1_m1035_DelSp) DelSp - время переключения скоростей
	{ 1618	,8	,1	, &internal1_m1035_z0},	//(internal1_m1035_z0) z0 - точка прекращения движения
	{ 1619	,8	,1	, &internal1_m1035_txZS},	//(internal1_m1035_txZS) txZS
	{ 1620	,8	,1	, &internal1_m1035_tx},	//(internal1_m1035_tx) tx
	{ 1621	,8	,1	, &internal1_m1035_txd},	//(internal1_m1035_txd) txd
	{ 1622	,8	,1	, &internal1_m1035_txMBl},	//(internal1_m1035_txMBl) tx
	{ 1623	,8	,1	, &internal1_m1035_txBl},	//(internal1_m1035_txBl) tx
	{ 1624	,8	,1	, &internal1_m1035_Speed0},	//(internal1_m1035_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1625	,8	,1	, &internal1_m1035_xz0},	//(internal1_m1035_xz0) xz0 - новое задание мм
	{ 1626	,8	,1	, &internal1_m1035_tz0},	//(internal1_m1035_tz0) tz0 - время защиты от нового задания сек
	{ 1627	,1	,1	, &internal1_m1035_Shift0},	//(internal1_m1035_Shift0) Shift0 - признак самохода
	{ 1628	,1	,1	, &internal1_m1035_ShCntlSp0},	//(internal1_m1035_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1629	,1	,1	, &internal1_m1035_ShiftControl},	//(internal1_m1035_ShiftControl) ShiftControl - признак самохода
	{ 1630	,8	,1	, &internal1_m550_X0},	//(internal1_m550_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1631	,8	,1	, &internal1_m550_t0},	//(internal1_m550_t0) время нахождения в зоне возврата
	{ 1632	,18	,1	, &internal1_m550_BLDv0},	//(internal1_m550_BLDv0) BlDv - Блокировка движения
	{ 1633	,8	,1	, &internal1_m569_tx},	//(internal1_m569_tx) tx - время накопленное сек
	{ 1634	,18	,1	, &internal1_m569_y0},	//(internal1_m569_y0) y0
	{ 1635	,8	,1	, &internal1_m568_tx},	//(internal1_m568_tx) tx - время накопленное сек
	{ 1636	,18	,1	, &internal1_m568_y0},	//(internal1_m568_y0) y0
	{ 1637	,3	,1	, &internal1_m573_xptr},	//(internal1_m573_xptr) указатель текущей позиции в массиве координат
	{ 1638	,8	,150	, &internal1_m573_x0},	//(internal1_m573_x0) x0 - массив мгновенных значений координат
	{ 1639	,8	,150	, &internal1_m573_tim0},	//(internal1_m573_tim0) tim0 - массив значений времени цикла
	{ 1640	,8	,1	, &internal1_m573_sumtim},	//(internal1_m573_sumtim) sumtim - время в пути
	{ 1641	,8	,1	, &internal1_m573_StSpeed},	//(internal1_m573_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1642	,8	,1	, &internal1_m573_Vz0},	//(internal1_m573_Vz0) Vz0 - предыдущая заданная скорость
	{ 1643	,3	,1	, &internal1_m573_flRazg},	//(internal1_m573_flRazg) признак разгона/торможения
	{ 1644	,8	,1	, &internal1_m573_DelSp},	//(internal1_m573_DelSp) DelSp - время переключения скоростей
	{ 1645	,8	,1	, &internal1_m573_z0},	//(internal1_m573_z0) z0 - точка прекращения движения
	{ 1646	,8	,1	, &internal1_m573_txZS},	//(internal1_m573_txZS) txZS
	{ 1647	,8	,1	, &internal1_m573_tx},	//(internal1_m573_tx) tx
	{ 1648	,8	,1	, &internal1_m573_txd},	//(internal1_m573_txd) txd
	{ 1649	,8	,1	, &internal1_m573_txMBl},	//(internal1_m573_txMBl) tx
	{ 1650	,8	,1	, &internal1_m573_txBl},	//(internal1_m573_txBl) tx
	{ 1651	,8	,1	, &internal1_m573_Speed0},	//(internal1_m573_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1652	,8	,1	, &internal1_m573_xz0},	//(internal1_m573_xz0) xz0 - новое задание мм
	{ 1653	,8	,1	, &internal1_m573_tz0},	//(internal1_m573_tz0) tz0 - время защиты от нового задания сек
	{ 1654	,1	,1	, &internal1_m573_Shift0},	//(internal1_m573_Shift0) Shift0 - признак самохода
	{ 1655	,1	,1	, &internal1_m573_ShCntlSp0},	//(internal1_m573_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1656	,1	,1	, &internal1_m573_ShiftControl},	//(internal1_m573_ShiftControl) ShiftControl - признак самохода
	{ 1657	,1	,1	, &internal1_m694_q0},	//(internal1_m694_q0) q0 - внутренний параметр
	{ 1658	,8	,1	, &internal1_m176_X0},	//(internal1_m176_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1659	,8	,1	, &internal1_m176_t0},	//(internal1_m176_t0) время нахождения в зоне возврата
	{ 1660	,18	,1	, &internal1_m176_BLDv0},	//(internal1_m176_BLDv0) BlDv - Блокировка движения
	{ 1661	,3	,1	, &internal1_m201_xptr},	//(internal1_m201_xptr) указатель текущей позиции в массиве координат
	{ 1662	,8	,150	, &internal1_m201_x0},	//(internal1_m201_x0) x0 - массив мгновенных значений координат
	{ 1663	,8	,150	, &internal1_m201_tim0},	//(internal1_m201_tim0) tim0 - массив значений времени цикла
	{ 1664	,8	,1	, &internal1_m201_sumtim},	//(internal1_m201_sumtim) sumtim - время в пути
	{ 1665	,8	,1	, &internal1_m201_StSpeed},	//(internal1_m201_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1666	,8	,1	, &internal1_m201_Vz0},	//(internal1_m201_Vz0) Vz0 - предыдущая заданная скорость
	{ 1667	,3	,1	, &internal1_m201_flRazg},	//(internal1_m201_flRazg) признак разгона/торможения
	{ 1668	,8	,1	, &internal1_m201_DelSp},	//(internal1_m201_DelSp) DelSp - время переключения скоростей
	{ 1669	,8	,1	, &internal1_m201_z0},	//(internal1_m201_z0) z0 - точка прекращения движения
	{ 1670	,8	,1	, &internal1_m201_txZS},	//(internal1_m201_txZS) txZS
	{ 1671	,8	,1	, &internal1_m201_tx},	//(internal1_m201_tx) tx
	{ 1672	,8	,1	, &internal1_m201_txd},	//(internal1_m201_txd) txd
	{ 1673	,8	,1	, &internal1_m201_txMBl},	//(internal1_m201_txMBl) tx
	{ 1674	,8	,1	, &internal1_m201_txBl},	//(internal1_m201_txBl) tx
	{ 1675	,8	,1	, &internal1_m201_Speed0},	//(internal1_m201_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1676	,8	,1	, &internal1_m201_xz0},	//(internal1_m201_xz0) xz0 - новое задание мм
	{ 1677	,8	,1	, &internal1_m201_tz0},	//(internal1_m201_tz0) tz0 - время защиты от нового задания сек
	{ 1678	,1	,1	, &internal1_m201_Shift0},	//(internal1_m201_Shift0) Shift0 - признак самохода
	{ 1679	,1	,1	, &internal1_m201_ShCntlSp0},	//(internal1_m201_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1680	,1	,1	, &internal1_m201_ShiftControl},	//(internal1_m201_ShiftControl) ShiftControl - признак самохода
	{ 1681	,1	,1	, &internal1_m720_q0},	//(internal1_m720_q0) q0 - внутренний параметр
	{ 1682	,18	,1	, &internal1_m517_DvUp0},	//(internal1_m517_DvUp0) - есть команда на движение вперёд
	{ 1683	,18	,1	, &internal1_m517_DvDw0},	//(internal1_m517_DvDw0) - есть команда на движение назад
	{ 1684	,18	,1	, &internal1_m517_FDvUp0},	//(internal1_m517_FDvUp0) - есть команда на движение вперёд
	{ 1685	,18	,1	, &internal1_m517_FDvDw0},	//(internal1_m517_FDvDw0) - есть команда на движение назад
	{ 1686	,18	,1	, &internal1_m517_BlDv0},	//(internal1_m517_BlDv0) - была блокировка
	{ 1687	,18	,1	, &internal1_m517_Pkv0},	//(internal1_m517_Pkv0) Pkv - передний конечный выключатель
	{ 1688	,18	,1	, &internal1_m517_Pkav0},	//(internal1_m517_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1689	,18	,1	, &internal1_m517_Zkv0},	//(internal1_m517_Zkv0) Zkv - задний конечный выключатель
	{ 1690	,18	,1	, &internal1_m517_Zkav0},	//(internal1_m517_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1691	,8	,1	, &internal1_m517_txNm},	//(internal1_m517_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1692	,8	,1	, &internal1_m517_txSm},	//(internal1_m517_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1693	,8	,1	, &internal1_m517_txHr},	//(internal1_m517_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1694	,8	,1	, &internal1_m517_txLd},	//(internal1_m517_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1695	,18	,1	, &internal1_m517_fef},	//(internal1_m517_fef) fef
	{ 1696	,18	,1	, &internal1_m511_DvUp0},	//(internal1_m511_DvUp0) - есть команда на движение вперёд
	{ 1697	,18	,1	, &internal1_m511_DvDw0},	//(internal1_m511_DvDw0) - есть команда на движение назад
	{ 1698	,18	,1	, &internal1_m511_FDvUp0},	//(internal1_m511_FDvUp0) - есть команда на движение вперёд
	{ 1699	,18	,1	, &internal1_m511_FDvDw0},	//(internal1_m511_FDvDw0) - есть команда на движение назад
	{ 1700	,18	,1	, &internal1_m511_BlDv0},	//(internal1_m511_BlDv0) - была блокировка
	{ 1701	,18	,1	, &internal1_m511_Pkv0},	//(internal1_m511_Pkv0) Pkv - передний конечный выключатель
	{ 1702	,18	,1	, &internal1_m511_Pkav0},	//(internal1_m511_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1703	,18	,1	, &internal1_m511_Zkv0},	//(internal1_m511_Zkv0) Zkv - задний конечный выключатель
	{ 1704	,18	,1	, &internal1_m511_Zkav0},	//(internal1_m511_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1705	,8	,1	, &internal1_m511_txNm},	//(internal1_m511_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1706	,8	,1	, &internal1_m511_txSm},	//(internal1_m511_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1707	,8	,1	, &internal1_m511_txHr},	//(internal1_m511_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1708	,8	,1	, &internal1_m511_txLd},	//(internal1_m511_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1709	,18	,1	, &internal1_m511_fef},	//(internal1_m511_fef) fef
	{ 1710	,8	,1	, &internal1_m909_X0},	//(internal1_m909_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1711	,8	,1	, &internal1_m909_t0},	//(internal1_m909_t0) время нахождения в зоне возврата
	{ 1712	,18	,1	, &internal1_m909_BLDv0},	//(internal1_m909_BLDv0) BlDv - Блокировка движения
	{ 1713	,3	,1	, &internal1_m927_xptr},	//(internal1_m927_xptr) указатель текущей позиции в массиве координат
	{ 1714	,8	,80	, &internal1_m927_x0},	//(internal1_m927_x0) x0 - массив мгновенных значений координат
	{ 1715	,8	,80	, &internal1_m927_tim0},	//(internal1_m927_tim0) tim0 - массив значений времени цикла
	{ 1716	,8	,1	, &internal1_m927_sumtim},	//(internal1_m927_sumtim) sumtim - время в пути
	{ 1717	,8	,1	, &internal1_m927_StSpeed},	//(internal1_m927_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1718	,8	,1	, &internal1_m927_Vz0},	//(internal1_m927_Vz0) Vz0 - предыдущая заданная скорость
	{ 1719	,3	,1	, &internal1_m927_flRazg},	//(internal1_m927_flRazg) признак разгона/торможения
	{ 1720	,8	,1	, &internal1_m927_DelSp},	//(internal1_m927_DelSp) DelSp - время переключения скоростей
	{ 1721	,8	,1	, &internal1_m927_z0},	//(internal1_m927_z0) z0 - точка прекращения движения
	{ 1722	,8	,1	, &internal1_m927_txZS},	//(internal1_m927_txZS) txZS
	{ 1723	,8	,1	, &internal1_m927_tx},	//(internal1_m927_tx) tx
	{ 1724	,8	,1	, &internal1_m927_txd},	//(internal1_m927_txd) txd
	{ 1725	,8	,1	, &internal1_m927_txMBl},	//(internal1_m927_txMBl) tx
	{ 1726	,8	,1	, &internal1_m927_txBl},	//(internal1_m927_txBl) tx
	{ 1727	,8	,1	, &internal1_m927_Speed0},	//(internal1_m927_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1728	,8	,1	, &internal1_m927_xz0},	//(internal1_m927_xz0) xz0 - новое задание мм
	{ 1729	,8	,1	, &internal1_m927_tz0},	//(internal1_m927_tz0) tz0 - время защиты от нового задания сек
	{ 1730	,1	,1	, &internal1_m927_Shift0},	//(internal1_m927_Shift0) Shift0 - признак самохода
	{ 1731	,1	,1	, &internal1_m927_ShCntlSp0},	//(internal1_m927_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1732	,1	,1	, &internal1_m927_ShiftControl},	//(internal1_m927_ShiftControl) ShiftControl - признак самохода
	{ 1733	,8	,1	, &internal1_m1804_X0},	//(internal1_m1804_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1734	,8	,1	, &internal1_m1804_t0},	//(internal1_m1804_t0) время нахождения в зоне возврата
	{ 1735	,18	,1	, &internal1_m1804_BLDv0},	//(internal1_m1804_BLDv0) BlDv - Блокировка движения
	{ 1736	,8	,1	, &internal1_m1273_X0},	//(internal1_m1273_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1737	,8	,1	, &internal1_m1273_t0},	//(internal1_m1273_t0) время нахождения в зоне возврата
	{ 1738	,18	,1	, &internal1_m1273_BLDv0},	//(internal1_m1273_BLDv0) BlDv - Блокировка движения
	{ 1739	,1	,1	, &internal1_m692_q0},	//(internal1_m692_q0) q0 - внутренний параметр
	{ 1740	,8	,1	, &internal1_m1370_X0},	//(internal1_m1370_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1741	,8	,1	, &internal1_m1370_t0},	//(internal1_m1370_t0) время нахождения в зоне возврата
	{ 1742	,18	,1	, &internal1_m1370_BLDv0},	//(internal1_m1370_BLDv0) BlDv - Блокировка движения
	{ 1743	,8	,1	, &internal1_m1398_tx},	//(internal1_m1398_tx) tx - время накопленное сек
	{ 1744	,18	,1	, &internal1_m1398_y0},	//(internal1_m1398_y0) y0
	{ 1745	,8	,1	, &internal1_m1397_tx},	//(internal1_m1397_tx) tx - время накопленное сек
	{ 1746	,18	,1	, &internal1_m1397_y0},	//(internal1_m1397_y0) y0
	{ 1747	,3	,1	, &internal1_m1405_xptr},	//(internal1_m1405_xptr) указатель текущей позиции в массиве координат
	{ 1748	,8	,80	, &internal1_m1405_x0},	//(internal1_m1405_x0) x0 - массив мгновенных значений координат
	{ 1749	,8	,80	, &internal1_m1405_tim0},	//(internal1_m1405_tim0) tim0 - массив значений времени цикла
	{ 1750	,8	,1	, &internal1_m1405_sumtim},	//(internal1_m1405_sumtim) sumtim - время в пути
	{ 1751	,8	,1	, &internal1_m1405_StSpeed},	//(internal1_m1405_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1752	,8	,1	, &internal1_m1405_Vz0},	//(internal1_m1405_Vz0) Vz0 - предыдущая заданная скорость
	{ 1753	,3	,1	, &internal1_m1405_flRazg},	//(internal1_m1405_flRazg) признак разгона/торможения
	{ 1754	,8	,1	, &internal1_m1405_DelSp},	//(internal1_m1405_DelSp) DelSp - время переключения скоростей
	{ 1755	,8	,1	, &internal1_m1405_z0},	//(internal1_m1405_z0) z0 - точка прекращения движения
	{ 1756	,8	,1	, &internal1_m1405_txZS},	//(internal1_m1405_txZS) txZS
	{ 1757	,8	,1	, &internal1_m1405_tx},	//(internal1_m1405_tx) tx
	{ 1758	,8	,1	, &internal1_m1405_txd},	//(internal1_m1405_txd) txd
	{ 1759	,8	,1	, &internal1_m1405_txMBl},	//(internal1_m1405_txMBl) tx
	{ 1760	,8	,1	, &internal1_m1405_txBl},	//(internal1_m1405_txBl) tx
	{ 1761	,8	,1	, &internal1_m1405_Speed0},	//(internal1_m1405_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1762	,8	,1	, &internal1_m1405_xz0},	//(internal1_m1405_xz0) xz0 - новое задание мм
	{ 1763	,8	,1	, &internal1_m1405_tz0},	//(internal1_m1405_tz0) tz0 - время защиты от нового задания сек
	{ 1764	,1	,1	, &internal1_m1405_Shift0},	//(internal1_m1405_Shift0) Shift0 - признак самохода
	{ 1765	,1	,1	, &internal1_m1405_ShCntlSp0},	//(internal1_m1405_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1766	,1	,1	, &internal1_m1405_ShiftControl},	//(internal1_m1405_ShiftControl) ShiftControl - признак самохода
	{ 1767	,1	,1	, &internal1_m712_q0},	//(internal1_m712_q0) q0 - внутренний параметр
	{ 1768	,8	,1	, &internal1_m1818_tx},	//(internal1_m1818_tx) tx - время накопленное сек
	{ 1769	,18	,1	, &internal1_m1818_y0},	//(internal1_m1818_y0) y0
	{ 1770	,8	,1	, &internal1_m1822_tx},	//(internal1_m1822_tx) tx - время накопленное сек
	{ 1771	,18	,1	, &internal1_m1822_y0},	//(internal1_m1822_y0) y0
	{ 1772	,18	,1	, &internal1_m1807_DvUp0},	//(internal1_m1807_DvUp0) - есть команда на движение вперёд
	{ 1773	,18	,1	, &internal1_m1807_DvDw0},	//(internal1_m1807_DvDw0) - есть команда на движение назад
	{ 1774	,18	,1	, &internal1_m1807_FDvUp0},	//(internal1_m1807_FDvUp0) - есть команда на движение вперёд
	{ 1775	,18	,1	, &internal1_m1807_FDvDw0},	//(internal1_m1807_FDvDw0) - есть команда на движение назад
	{ 1776	,18	,1	, &internal1_m1807_BlDv0},	//(internal1_m1807_BlDv0) - была блокировка
	{ 1777	,18	,1	, &internal1_m1807_Pkv0},	//(internal1_m1807_Pkv0) Pkv - передний конечный выключатель
	{ 1778	,18	,1	, &internal1_m1807_Pkav0},	//(internal1_m1807_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1779	,18	,1	, &internal1_m1807_Zkv0},	//(internal1_m1807_Zkv0) Zkv - задний конечный выключатель
	{ 1780	,18	,1	, &internal1_m1807_Zkav0},	//(internal1_m1807_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1781	,8	,1	, &internal1_m1807_txNm},	//(internal1_m1807_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1782	,8	,1	, &internal1_m1807_txSm},	//(internal1_m1807_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1783	,8	,1	, &internal1_m1807_txHr},	//(internal1_m1807_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1784	,8	,1	, &internal1_m1807_txLd},	//(internal1_m1807_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1785	,18	,1	, &internal1_m1807_fef},	//(internal1_m1807_fef) fef
	{ 1786	,3	,1	, &internal1_m1826_xptr},	//(internal1_m1826_xptr) указатель текущей позиции в массиве координат
	{ 1787	,8	,20	, &internal1_m1826_x0},	//(internal1_m1826_x0) x0 - массив мгновенных значений координат
	{ 1788	,8	,20	, &internal1_m1826_tim0},	//(internal1_m1826_tim0) tim0 - массив значений времени цикла
	{ 1789	,8	,1	, &internal1_m1826_sumtim},	//(internal1_m1826_sumtim) sumtim - время в пути
	{ 1790	,8	,1	, &internal1_m1826_StSpeed},	//(internal1_m1826_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1791	,8	,1	, &internal1_m1826_Vz0},	//(internal1_m1826_Vz0) Vz0 - предыдущая заданная скорость
	{ 1792	,3	,1	, &internal1_m1826_flRazg},	//(internal1_m1826_flRazg) признак разгона/торможения
	{ 1793	,8	,1	, &internal1_m1826_DelSp},	//(internal1_m1826_DelSp) DelSp - время переключения скоростей
	{ 1794	,8	,1	, &internal1_m1826_z0},	//(internal1_m1826_z0) z0 - точка прекращения движения
	{ 1795	,8	,1	, &internal1_m1826_txZS},	//(internal1_m1826_txZS) txZS
	{ 1796	,8	,1	, &internal1_m1826_tx},	//(internal1_m1826_tx) tx
	{ 1797	,8	,1	, &internal1_m1826_txd},	//(internal1_m1826_txd) txd
	{ 1798	,8	,1	, &internal1_m1826_txMBl},	//(internal1_m1826_txMBl) tx
	{ 1799	,8	,1	, &internal1_m1826_txBl},	//(internal1_m1826_txBl) tx
	{ 1800	,8	,1	, &internal1_m1826_Speed0},	//(internal1_m1826_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1801	,8	,1	, &internal1_m1826_xz0},	//(internal1_m1826_xz0) xz0 - новое задание мм
	{ 1802	,8	,1	, &internal1_m1826_tz0},	//(internal1_m1826_tz0) tz0 - время защиты от нового задания сек
	{ 1803	,1	,1	, &internal1_m1826_Shift0},	//(internal1_m1826_Shift0) Shift0 - признак самохода
	{ 1804	,1	,1	, &internal1_m1826_ShCntlSp0},	//(internal1_m1826_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1805	,1	,1	, &internal1_m1826_ShiftControl},	//(internal1_m1826_ShiftControl) ShiftControl - признак самохода
	{ 1806	,8	,1	, &internal1_m1290_tx},	//(internal1_m1290_tx) tx - время накопленное сек
	{ 1807	,18	,1	, &internal1_m1290_y0},	//(internal1_m1290_y0) y0
	{ 1808	,8	,1	, &internal1_m1294_tx},	//(internal1_m1294_tx) tx - время накопленное сек
	{ 1809	,18	,1	, &internal1_m1294_y0},	//(internal1_m1294_y0) y0
	{ 1810	,1	,1	, &internal1_m702_q0},	//(internal1_m702_q0) q0 - внутренний параметр
	{ 1811	,1	,1	, &internal1_m667_q0},	//(internal1_m667_q0) q0 - внутренний параметр
	{ 1812	,18	,1	, &internal1_m1281_DvUp0},	//(internal1_m1281_DvUp0) - есть команда на движение вперёд
	{ 1813	,18	,1	, &internal1_m1281_DvDw0},	//(internal1_m1281_DvDw0) - есть команда на движение назад
	{ 1814	,18	,1	, &internal1_m1281_FDvUp0},	//(internal1_m1281_FDvUp0) - есть команда на движение вперёд
	{ 1815	,18	,1	, &internal1_m1281_FDvDw0},	//(internal1_m1281_FDvDw0) - есть команда на движение назад
	{ 1816	,18	,1	, &internal1_m1281_BlDv0},	//(internal1_m1281_BlDv0) - была блокировка
	{ 1817	,18	,1	, &internal1_m1281_Pkv0},	//(internal1_m1281_Pkv0) Pkv - передний конечный выключатель
	{ 1818	,18	,1	, &internal1_m1281_Pkav0},	//(internal1_m1281_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1819	,18	,1	, &internal1_m1281_Zkv0},	//(internal1_m1281_Zkv0) Zkv - задний конечный выключатель
	{ 1820	,18	,1	, &internal1_m1281_Zkav0},	//(internal1_m1281_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1821	,8	,1	, &internal1_m1281_txNm},	//(internal1_m1281_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1822	,8	,1	, &internal1_m1281_txSm},	//(internal1_m1281_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1823	,8	,1	, &internal1_m1281_txHr},	//(internal1_m1281_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1824	,8	,1	, &internal1_m1281_txLd},	//(internal1_m1281_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1825	,18	,1	, &internal1_m1281_fef},	//(internal1_m1281_fef) fef
	{ 1826	,3	,1	, &internal1_m1300_xptr},	//(internal1_m1300_xptr) указатель текущей позиции в массиве координат
	{ 1827	,8	,20	, &internal1_m1300_x0},	//(internal1_m1300_x0) x0 - массив мгновенных значений координат
	{ 1828	,8	,20	, &internal1_m1300_tim0},	//(internal1_m1300_tim0) tim0 - массив значений времени цикла
	{ 1829	,8	,1	, &internal1_m1300_sumtim},	//(internal1_m1300_sumtim) sumtim - время в пути
	{ 1830	,8	,1	, &internal1_m1300_StSpeed},	//(internal1_m1300_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1831	,8	,1	, &internal1_m1300_Vz0},	//(internal1_m1300_Vz0) Vz0 - предыдущая заданная скорость
	{ 1832	,3	,1	, &internal1_m1300_flRazg},	//(internal1_m1300_flRazg) признак разгона/торможения
	{ 1833	,8	,1	, &internal1_m1300_DelSp},	//(internal1_m1300_DelSp) DelSp - время переключения скоростей
	{ 1834	,8	,1	, &internal1_m1300_z0},	//(internal1_m1300_z0) z0 - точка прекращения движения
	{ 1835	,8	,1	, &internal1_m1300_txZS},	//(internal1_m1300_txZS) txZS
	{ 1836	,8	,1	, &internal1_m1300_tx},	//(internal1_m1300_tx) tx
	{ 1837	,8	,1	, &internal1_m1300_txd},	//(internal1_m1300_txd) txd
	{ 1838	,8	,1	, &internal1_m1300_txMBl},	//(internal1_m1300_txMBl) tx
	{ 1839	,8	,1	, &internal1_m1300_txBl},	//(internal1_m1300_txBl) tx
	{ 1840	,8	,1	, &internal1_m1300_Speed0},	//(internal1_m1300_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1841	,8	,1	, &internal1_m1300_xz0},	//(internal1_m1300_xz0) xz0 - новое задание мм
	{ 1842	,8	,1	, &internal1_m1300_tz0},	//(internal1_m1300_tz0) tz0 - время защиты от нового задания сек
	{ 1843	,1	,1	, &internal1_m1300_Shift0},	//(internal1_m1300_Shift0) Shift0 - признак самохода
	{ 1844	,1	,1	, &internal1_m1300_ShCntlSp0},	//(internal1_m1300_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1845	,1	,1	, &internal1_m1300_ShiftControl},	//(internal1_m1300_ShiftControl) ShiftControl - признак самохода
	{ 1846	,1	,1	, &internal1_m830_x0},	//(internal1_m830_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1847	,1	,1	, &internal1_m799_x0},	//(internal1_m799_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1848	,1	,1	, &internal1_m741_x0},	//(internal1_m741_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1849	,1	,1	, &internal1_m855_q0},	//(internal1_m855_q0) q0 - внутренний параметр
	{ 1850	,1	,1	, &internal1_m850_q0},	//(internal1_m850_q0) q0 - внутренний параметр
	{ 1851	,1	,1	, &internal1_m818_q0},	//(internal1_m818_q0) q0 - внутренний параметр
	{ 1852	,1	,1	, &internal1_m822_q0},	//(internal1_m822_q0) q0 - внутренний параметр
	{ 1853	,1	,1	, &internal1_m831_q0},	//(internal1_m831_q0) q0 - внутренний параметр
	{ 1854	,1	,1	, &internal1_m843_q0},	//(internal1_m843_q0) q0 - внутренний параметр
	{ 1855	,1	,1	, &internal1_m820_q0},	//(internal1_m820_q0) q0 - внутренний параметр
	{ 1856	,18	,1	, &internal1_m1343_DvUp0},	//(internal1_m1343_DvUp0) - есть команда на движение вперёд
	{ 1857	,18	,1	, &internal1_m1343_DvDw0},	//(internal1_m1343_DvDw0) - есть команда на движение назад
	{ 1858	,18	,1	, &internal1_m1343_FDvUp0},	//(internal1_m1343_FDvUp0) - есть команда на движение вперёд
	{ 1859	,18	,1	, &internal1_m1343_FDvDw0},	//(internal1_m1343_FDvDw0) - есть команда на движение назад
	{ 1860	,18	,1	, &internal1_m1343_BlDv0},	//(internal1_m1343_BlDv0) - была блокировка
	{ 1861	,18	,1	, &internal1_m1343_Pkv0},	//(internal1_m1343_Pkv0) Pkv - передний конечный выключатель
	{ 1862	,18	,1	, &internal1_m1343_Pkav0},	//(internal1_m1343_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1863	,18	,1	, &internal1_m1343_Zkv0},	//(internal1_m1343_Zkv0) Zkv - задний конечный выключатель
	{ 1864	,18	,1	, &internal1_m1343_Zkav0},	//(internal1_m1343_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1865	,8	,1	, &internal1_m1343_txNm},	//(internal1_m1343_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1866	,8	,1	, &internal1_m1343_txSm},	//(internal1_m1343_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1867	,8	,1	, &internal1_m1343_txHr},	//(internal1_m1343_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1868	,8	,1	, &internal1_m1343_txLd},	//(internal1_m1343_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1869	,18	,1	, &internal1_m1343_fef},	//(internal1_m1343_fef) fef
	{ 1870	,18	,1	, &internal1_m1333_DvUp0},	//(internal1_m1333_DvUp0) - есть команда на движение вперёд
	{ 1871	,18	,1	, &internal1_m1333_DvDw0},	//(internal1_m1333_DvDw0) - есть команда на движение назад
	{ 1872	,18	,1	, &internal1_m1333_FDvUp0},	//(internal1_m1333_FDvUp0) - есть команда на движение вперёд
	{ 1873	,18	,1	, &internal1_m1333_FDvDw0},	//(internal1_m1333_FDvDw0) - есть команда на движение назад
	{ 1874	,18	,1	, &internal1_m1333_BlDv0},	//(internal1_m1333_BlDv0) - была блокировка
	{ 1875	,18	,1	, &internal1_m1333_Pkv0},	//(internal1_m1333_Pkv0) Pkv - передний конечный выключатель
	{ 1876	,18	,1	, &internal1_m1333_Pkav0},	//(internal1_m1333_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1877	,18	,1	, &internal1_m1333_Zkv0},	//(internal1_m1333_Zkv0) Zkv - задний конечный выключатель
	{ 1878	,18	,1	, &internal1_m1333_Zkav0},	//(internal1_m1333_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1879	,8	,1	, &internal1_m1333_txNm},	//(internal1_m1333_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1880	,8	,1	, &internal1_m1333_txSm},	//(internal1_m1333_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1881	,8	,1	, &internal1_m1333_txHr},	//(internal1_m1333_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1882	,8	,1	, &internal1_m1333_txLd},	//(internal1_m1333_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1883	,18	,1	, &internal1_m1333_fef},	//(internal1_m1333_fef) fef
	{ 1884	,18	,1	, &internal1_m879_DvUp0},	//(internal1_m879_DvUp0) - есть команда на движение вперёд
	{ 1885	,18	,1	, &internal1_m879_DvDw0},	//(internal1_m879_DvDw0) - есть команда на движение назад
	{ 1886	,18	,1	, &internal1_m879_FDvUp0},	//(internal1_m879_FDvUp0) - есть команда на движение вперёд
	{ 1887	,18	,1	, &internal1_m879_FDvDw0},	//(internal1_m879_FDvDw0) - есть команда на движение назад
	{ 1888	,18	,1	, &internal1_m879_BlDv0},	//(internal1_m879_BlDv0) - была блокировка
	{ 1889	,18	,1	, &internal1_m879_Pkv0},	//(internal1_m879_Pkv0) Pkv - передний конечный выключатель
	{ 1890	,18	,1	, &internal1_m879_Pkav0},	//(internal1_m879_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1891	,18	,1	, &internal1_m879_Zkv0},	//(internal1_m879_Zkv0) Zkv - задний конечный выключатель
	{ 1892	,18	,1	, &internal1_m879_Zkav0},	//(internal1_m879_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1893	,8	,1	, &internal1_m879_txNm},	//(internal1_m879_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1894	,8	,1	, &internal1_m879_txSm},	//(internal1_m879_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1895	,8	,1	, &internal1_m879_txHr},	//(internal1_m879_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1896	,8	,1	, &internal1_m879_txLd},	//(internal1_m879_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1897	,18	,1	, &internal1_m879_fef},	//(internal1_m879_fef) fef
	{ 1898	,18	,1	, &internal1_m875_DvUp0},	//(internal1_m875_DvUp0) - есть команда на движение вперёд
	{ 1899	,18	,1	, &internal1_m875_DvDw0},	//(internal1_m875_DvDw0) - есть команда на движение назад
	{ 1900	,18	,1	, &internal1_m875_FDvUp0},	//(internal1_m875_FDvUp0) - есть команда на движение вперёд
	{ 1901	,18	,1	, &internal1_m875_FDvDw0},	//(internal1_m875_FDvDw0) - есть команда на движение назад
	{ 1902	,18	,1	, &internal1_m875_BlDv0},	//(internal1_m875_BlDv0) - была блокировка
	{ 1903	,18	,1	, &internal1_m875_Pkv0},	//(internal1_m875_Pkv0) Pkv - передний конечный выключатель
	{ 1904	,18	,1	, &internal1_m875_Pkav0},	//(internal1_m875_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1905	,18	,1	, &internal1_m875_Zkv0},	//(internal1_m875_Zkv0) Zkv - задний конечный выключатель
	{ 1906	,18	,1	, &internal1_m875_Zkav0},	//(internal1_m875_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1907	,8	,1	, &internal1_m875_txNm},	//(internal1_m875_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1908	,8	,1	, &internal1_m875_txSm},	//(internal1_m875_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1909	,8	,1	, &internal1_m875_txHr},	//(internal1_m875_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1910	,8	,1	, &internal1_m875_txLd},	//(internal1_m875_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1911	,18	,1	, &internal1_m875_fef},	//(internal1_m875_fef) fef
	{ 1912	,18	,1	, &internal1_m390_DvUp0},	//(internal1_m390_DvUp0) - есть команда на движение вперёд
	{ 1913	,18	,1	, &internal1_m390_DvDw0},	//(internal1_m390_DvDw0) - есть команда на движение назад
	{ 1914	,18	,1	, &internal1_m390_FDvUp0},	//(internal1_m390_FDvUp0) - есть команда на движение вперёд
	{ 1915	,18	,1	, &internal1_m390_FDvDw0},	//(internal1_m390_FDvDw0) - есть команда на движение назад
	{ 1916	,18	,1	, &internal1_m390_BlDv0},	//(internal1_m390_BlDv0) - была блокировка
	{ 1917	,18	,1	, &internal1_m390_Pkv0},	//(internal1_m390_Pkv0) Pkv - передний конечный выключатель
	{ 1918	,18	,1	, &internal1_m390_Pkav0},	//(internal1_m390_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1919	,18	,1	, &internal1_m390_Zkv0},	//(internal1_m390_Zkv0) Zkv - задний конечный выключатель
	{ 1920	,18	,1	, &internal1_m390_Zkav0},	//(internal1_m390_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1921	,8	,1	, &internal1_m390_txNm},	//(internal1_m390_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1922	,8	,1	, &internal1_m390_txSm},	//(internal1_m390_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1923	,8	,1	, &internal1_m390_txHr},	//(internal1_m390_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1924	,8	,1	, &internal1_m390_txLd},	//(internal1_m390_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1925	,18	,1	, &internal1_m390_fef},	//(internal1_m390_fef) fef
	{ 1926	,18	,1	, &internal1_m427_DvUp0},	//(internal1_m427_DvUp0) - есть команда на движение вперёд
	{ 1927	,18	,1	, &internal1_m427_DvDw0},	//(internal1_m427_DvDw0) - есть команда на движение назад
	{ 1928	,18	,1	, &internal1_m427_FDvUp0},	//(internal1_m427_FDvUp0) - есть команда на движение вперёд
	{ 1929	,18	,1	, &internal1_m427_FDvDw0},	//(internal1_m427_FDvDw0) - есть команда на движение назад
	{ 1930	,18	,1	, &internal1_m427_BlDv0},	//(internal1_m427_BlDv0) - была блокировка
	{ 1931	,18	,1	, &internal1_m427_Pkv0},	//(internal1_m427_Pkv0) Pkv - передний конечный выключатель
	{ 1932	,18	,1	, &internal1_m427_Pkav0},	//(internal1_m427_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1933	,18	,1	, &internal1_m427_Zkv0},	//(internal1_m427_Zkv0) Zkv - задний конечный выключатель
	{ 1934	,18	,1	, &internal1_m427_Zkav0},	//(internal1_m427_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1935	,8	,1	, &internal1_m427_txNm},	//(internal1_m427_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1936	,8	,1	, &internal1_m427_txSm},	//(internal1_m427_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1937	,8	,1	, &internal1_m427_txHr},	//(internal1_m427_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1938	,8	,1	, &internal1_m427_txLd},	//(internal1_m427_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1939	,18	,1	, &internal1_m427_fef},	//(internal1_m427_fef) fef
	{ 1940	,18	,1	, &internal1_m421_DvUp0},	//(internal1_m421_DvUp0) - есть команда на движение вперёд
	{ 1941	,18	,1	, &internal1_m421_DvDw0},	//(internal1_m421_DvDw0) - есть команда на движение назад
	{ 1942	,18	,1	, &internal1_m421_FDvUp0},	//(internal1_m421_FDvUp0) - есть команда на движение вперёд
	{ 1943	,18	,1	, &internal1_m421_FDvDw0},	//(internal1_m421_FDvDw0) - есть команда на движение назад
	{ 1944	,18	,1	, &internal1_m421_BlDv0},	//(internal1_m421_BlDv0) - была блокировка
	{ 1945	,18	,1	, &internal1_m421_Pkv0},	//(internal1_m421_Pkv0) Pkv - передний конечный выключатель
	{ 1946	,18	,1	, &internal1_m421_Pkav0},	//(internal1_m421_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1947	,18	,1	, &internal1_m421_Zkv0},	//(internal1_m421_Zkv0) Zkv - задний конечный выключатель
	{ 1948	,18	,1	, &internal1_m421_Zkav0},	//(internal1_m421_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1949	,8	,1	, &internal1_m421_txNm},	//(internal1_m421_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1950	,8	,1	, &internal1_m421_txSm},	//(internal1_m421_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1951	,8	,1	, &internal1_m421_txHr},	//(internal1_m421_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1952	,8	,1	, &internal1_m421_txLd},	//(internal1_m421_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1953	,18	,1	, &internal1_m421_fef},	//(internal1_m421_fef) fef
	{ 1954	,1	,1	, &internal1_m827_q0},	//(internal1_m827_q0) q0 - внутренний параметр
	{ 1955	,1	,1	, &internal1_m824_q0},	//(internal1_m824_q0) q0 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="du.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{751,"fEM_A1UC03RDU\0"}, 
{752,"dEM_A1UC05UDU\0"}, 
{753,"dEM_A1UC06UDU\0"}, 
{754,"dEM_A2UC06UDU\0"}, 
{755,"dEM_A2UC05UDU\0"}, 
{756,"fEM_A2UC03RDU\0"}, 
{757,"dEM_A3UC06UDU\0"}, 
{758,"dEM_A3UC05UDU\0"}, 
{759,"fEM_A3UC03RDU\0"}, 
{760,"dEM_A8UC06UDU\0"}, 
{761,"fEM_A8UC03RDU\0"}, 
{762,"dEM_A8UC05UDU\0"}, 
{763,"fEM_R0UV81RDU\0"}, 
{764,"fEM_R0UV82RDU\0"}, 
{765,"fEM_R0UV83RDU\0"}, 
{766,"fEM_R0UV84RDU\0"}, 
{767,"fEM_R0UV86RDU\0"}, 
{768,"fEM_R0UV85RDU\0"}, 
{769,"fEM_R0UV87RDU\0"}, 
{770,"fEM_A3UP03RDU\0"}, 
{771,"fEM_A3UP04RDU\0"}, 
{772,"fEM_A3UP43RDU\0"}, 
{773,"fEM_A3UP44RDU\0"}, 
{774,"fEM_A3UP53RDU\0"}, 
{775,"fEM_A3UP85RDU\0"}, 
{776,"fEM_A3UP88RDU\0"}, 
{777,"fEM_A3UP86RDU\0"}, 
{778,"fEM_B8UV01RDU\0"}, 
{779,"fEM_B8UV02RDU\0"}, 
{780,"fEM_B8UV03RDU\0"}, 
{781,"fEM_B8UL04RDU\0"}, 
{782,"iEM_A2UV03CDU\0"}, 
{783,"fEM_A2UV01RDU\0"}, 
{784,"fEM_A2UV02RDU\0"}, 
{785,"fEM_A1UV01RDU\0"}, 
{786,"fEM_A1UV02RDU\0"}, 
{787,"fEM_A1UC06RDU\0"}, 
{788,"fEM_A1UC05RDU\0"}, 
{789,"fEM_A1UL04RDU\0"}, 
{790,"fEM_A3UV01RDU\0"}, 
{791,"fEM_A3UV02RDU\0"}, 
{792,"fEM_A3UC06RDU\0"}, 
{793,"fEM_A3UC05RDU\0"}, 
{794,"fEM_A3UL04RDU\0"}, 
{795,"fEM_A3UP54RDU\0"}, 
{796,"fEM_A3UP87RDU\0"}, 
{797,"fEM_R0UL05RDU\0"}, 
{798,"fEM_R0UL20RDU\0"}, 
{799,"fEM_B8UV04RDU\0"}, 
{800,"fEM_B8UC06RDU\0"}, 
{801,"fEM_B8UC05RDU\0"}, 
{802,"fEM_A2UL05RDU\0"}, 
{803,"fEM_A2UL03RDU\0"}, 
{804,"fEM_A2UC06RDU\0"}, 
{805,"fEM_A2UC05RDU\0"}, 
{806,"fEM_A2UL04RDU\0"}, 
{807,"fEM_A1UL03RDU\0"}, 
{808,"fEM_A1UL05RDU\0"}, 
{809,"fEM_A3UL03RDU\0"}, 
{810,"fEM_A3UL05RDU\0"}, 
{811,"fEM_A1UC08RDU\0"}, 
{812,"fEM_A3UC08RDU\0"}, 
{813,"fEM_A1UC07RDU\0"}, 
{814,"fEM_A1UL01RDU\0"}, 
{815,"fEM_A3UC07RDU\0"}, 
{816,"fEM_A3UL01RDU\0"}, 
{817,"fEM_A2UC08RDU\0"}, 
{818,"fEM_A2UC07RDU\0"}, 
{819,"fEM_A2UL01RDU\0"}, 
{820,"fEM_B8UC01RDU\0"}, 
{821,"fEM_B8UL07RDU\0"}, 
{822,"fEM_B8UC02RDU\0"}, 
{823,"fEM_B8UL01RDU\0"}, 
{824,"fEM_B8UL05RDU\0"}, 
{825,"fEM_B8UL03RDU\0"}, 
{826,"fEM_B8UL06RDU\0"}, 
{827,"fEM_A9UZ03RDU\0"}, 
{828,"fEM_A9UZ04RDU\0"}, 
{829,"fEM_A9UZ05RDU\0"}, 
{830,"fEM_R4UZ04RDU\0"}, 
{831,"fEM_R4UZ03RDU\0"}, 
{832,"fEM_R4UZ05RDU\0"}, 
{833,"fEM_A5UZ03RDU\0"}, 
{834,"fEM_A5UZ04RDU\0"}, 
{835,"fEM_A5UZ05RDU\0"}, 
{836,"fEM_A4UZ03RDU\0"}, 
{837,"fEM_A4UZ04RDU\0"}, 
{838,"fEM_A4UZ05RDU\0"}, 
{839,"fEM_A6UZ03RDU\0"}, 
{840,"fEM_A6UZ04RDU\0"}, 
{841,"fEM_A6UZ05RDU\0"}, 
{842,"fEM_R1UZ03RDU\0"}, 
{843,"fEM_R1UZ04RDU\0"}, 
{844,"fEM_R1UZ05RDU\0"}, 
{845,"fEM_R0UL04RDU\0"}, 
{846,"fEM_R0UL06RDU\0"}, 
{847,"fEM_R0UL03RDU\0"}, 
{848,"fEM_R0UL17RDU\0"}, 
{849,"fEM_R0UL19RDU\0"}, 
{850,"fEM_R0UL07RDU\0"}, 
{851,"fEM_R0UL18RDU\0"}, 
{852,"fEM_R0UL16RDU\0"}, 
{853,"fEM_R0UL02RDU\0"}, 
{854,"fEM_R0UN08RDU\0"}, 
{855,"fEM_R0UN07RDU\0"}, 
{856,"fEM_R0UN06RDU\0"}, 
{857,"fEM_R0UN05RDU\0"}, 
{858,"fEM_R0UN04RDU\0"}, 
{859,"fEM_R0UN03RDU\0"}, 
{860,"fEM_R0UN02RDU\0"}, 
{861,"fEM_R0UN01RDU\0"}, 
{862,"fEM_A2UC82RDU\0"}, 
{863,"fEM_A2UC83RDU\0"}, 
{864,"fEM_A1UC83RDU\0"}, 
{865,"fEM_A2UC81RDU\0"}, 
{866,"fEM_A1UC81RDU\0"}, 
{867,"fEM_A1UC82RDU\0"}, 
{868,"fEM_A2UL83RDU\0"}, 
{869,"fEM_A3UC81RDU\0"}, 
{870,"fEM_A3UC82RDU\0"}, 
{871,"fEM_R0UN80RDU\0"}, 
{872,"iEM_A2UV01IDU\0"}, 
{873,"iEM_A2UV02IDU\0"}, 
{874,"iEM_A1UV01IDU\0"}, 
{875,"iEM_A1UV02IDU\0"}, 
{876,"iEM_A1UV03IDU\0"}, 
{877,"iEM_A3UV01IDU\0"}, 
{878,"iEM_A3UV02IDU\0"}, 
{879,"lEM_R0MD01LC1\0"}, 
{880,"fEM_A3UC09RDU\0"}, 
{881,"fEM_A2UC02RDU\0"}, 
{882,"fEM_A1UC02RDU\0"}, 
{883,"fEM_A3UC02RDU\0"}, 
{884,"fEM_R0UL21RDU\0"}, 
{885,"fEM_R0UN09RDU\0"}, 
{886,"fEM_R0UN11RDU\0"}, 
{887,"fEM_R0UN12RDU\0"}, 
{888,"fEM_R0UN13RDU\0"}, 
{889,"fEM_R0UN14RDU\0"}, 
{890,"fEM_R0UN16RDU\0"}, 
{891,"fEM_R0UN17RDU\0"}, 
{892,"fEM_R0UN18RDU\0"}, 
{893,"fEM_R0UN19RDU\0"}, 
{894,"fEM_R0UN70LDU\0"}, 
{895,"fEM_R0UN71LDU\0"}, 
{896,"fEM_R0UN72LDU\0"}, 
{897,"fEM_R0UN73LDU\0"}, 
{898,"fEM_R0UN74LDU\0"}, 
{899,"fEM_R0UN75LDU\0"}, 
{900,"fEM_R0UN80LDU\0"}, 
{901,"fEM_R0UN81LDU\0"}, 
{902,"fEM_R0UN82LDU\0"}, 
{903,"fEM_R0UN83LDU\0"}, 
{904,"fEM_R0UN84LDU\0"}, 
{905,"fEM_R0UN85LDU\0"}, 
{906,"fEM_R0UT20RDU\0"}, 
{907,"fEM_R0UN25RDU\0"}, 
{908,"fEM_R0UN15RDU\0"}, 
{909,"fEM_R0UN26RDU\0"}, 
{910,"fEM_R0UN27RDU\0"}, 
{911,"fEM_R0UN24RDU\0"}, 
{912,"fEM_R0UL25RDU\0"}, 
{913,"fEM_R0UL01RSS\0"}, 
{914,"fEM_R0UL02RSS\0"}, 
{915,"fEM_R0UN03RSS\0"}, 
{916,"fEM_R7UI76RDU\0"}, 
{917,"fEM_R0UL00RDU\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_DU[]={  // 
	{&R0MD34LP1,1,0},	//( - , DU) Кнопка КВИТИРОВАТЬ
	{&A2MD12LP1,1,1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
	{&A2MD11LP1,1,2},	//( - , DU) Кнопка ПУСК РБ1
	{&B2MD12LP1,1,3},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
	{&B2MD11LP1,1,4},	//( - , DU) Кнопка ПУСК РБ2
	{&B1MD12LP1,1,5},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
	{&B1MD11LP1,1,6},	//( - , DU) Кнопка ПУСК ББ2
	{&A3MD11LP1,1,7},	//( - , DU) Кнопка ПУСК ИС1
	{&R0MD33LP1,1,8},	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
	{&A1MD12LP1,1,9},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
	{&A1MD11LP1,1,10},	//( - , DU) Кнопка ПУСК ББ1
	{&R0MW17LP1,1,11},	//( - , DU) Переключатель АВТ/Р
	{&B3MD12LP1,1,12},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
	{&B3MD11LP1,1,13},	//( - , DU) Кнопка ПУСК ИС2
	{&R0MD11LP2,1,14},	//( - , DU) Кнопка Пуск проверки схем сброса
	{&C1MD31LP1,1,15},	//( - , DU) Кнопка СБРОС ББ
	{&C1MD31LP2,1,16},	//( - , DU) Кнопка СБРОС ББ
	{&B9IS21LDU,1,17},	//( - K26VDSR, DU) Приход на НУ НИ ДС2
	{&A3MD12LP1,1,18},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
	{&B8MC01LC2,1,19},	//( - , DU) Настроить энкодер АЗ2
	{&B8MC01LC1,1,20},	//( - , DU) Настроить энкодер АЗ2
	{&A3MC01LC2,1,21},	//( - , DU) Настроить энкодер ИС1
	{&A3MC01LC1,1,22},	//( - , DU) Настроить энкодер ИС1
	{&B3MC01LC2,1,23},	//( - , DU) Настроить энкодер ИС2
	{&B3MC01LC1,1,24},	//( - , DU) Настроить энкодер ИС2
	{&A2MC01LC2,1,25},	//( - , DU) Настроить энкодер РБ1
	{&A2MC01LC1,1,26},	//( - , DU) Настроить энкодер РБ1
	{&B2MC01LC2,1,27},	//( - , DU) Настроить энкодер РБ2
	{&B2MC01LC1,1,28},	//( - , DU) Настроить энкодер РБ2
	{&A1MC01LC2,1,29},	//( - , DU) Настроить энкодер ББ1
	{&A1MC01LC1,1,30},	//( - , DU) Настроить энкодер ББ1
	{&B1MC01LC2,1,31},	//( - , DU) Настроить энкодер ББ2
	{&B1MC01LC1,1,32},	//( - , DU) Настроить энкодер ББ2
	{&A8MC01LC1,1,33},	//( - , DU) Настроить энкодер ДС2
	{&A8MC01LC2,1,34},	//( - , DU) Настроить энкодер ДС2
	{&C2MD31LP1,1,35},	//( - , DU) Кнопка СБРОС РБ
	{&R0MD11LP1,1,36},	//( - , DU) Кнопка ПУСК
	{&R4MD21LP2,1,37},	//( - , DU) Кнопка НАЗАД  (тележки)
	{&R4MD31LP2,1,38},	//( - , DU) Кнопка СТОП  (тележки)
	{&R4MD11LP2,1,39},	//( - , DU) Кнопка ВПЕРЁД  (тележки)
	{&R0MW13LP2,1,40},	//( - , DU) Переключатель СЕТЬ
	{&R0MD32LP1,1,41},	//( - , DU) Кнопка СПУСК
	{&R0MD31LP1,1,42},	//( - , DU) Кнопка СТОП
	{&R0NE01LDU,1,43},	//( - , DU) Потеря связи с БАЗ1
	{&R0NE02LDU,1,44},	//( - , DU) Потеря связи с БАЗ2
	{&R0NE08LDU,1,45},	//( - , DU) Потеря связи с ОПУ
	{&lEM_R0MD01LC1,1,46},	//( - , DU) Ручное управление ОРР
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DU[]={  // 
	{&A7AS31LDU,1,0},	//( - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
	{&B2VS21LDU,1,1},	//( - , DU) Движение РБ2 в сторону НУ
	{&B2VS11LDU,1,2},	//( - , DU) Движение РБ2 в сторону ВУ
	{&R0VP73LDU,1,3},	//( - , DU) ПС давления для РУ
	{&R0IS02LDU,1,4},	//( - K30VDSR, DU) Разрешение ввода от имитатора
	{&R0IS01LDU,1,5},	//( - K29VDSR, DU) Признак работы с имитатором
	{&A3IS11LDU,1,6},	//( - K01VDSR, DU) Приход на ВУ ИС1
	{&B3IS11LDU,1,7},	//( - K03VDSR, DU) Приход на ВУ ИС2
	{&R0VW13LDU,1,8},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
	{&R0VW23LDU,1,9},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VX09LDU,1,10},	//( - , DU) Индикация регулятор мощности включен/отключен
	{&R0VS17LDU,1,11},	//( - , DU) Индикация выбора АВТОМАТ
	{&A2VS32LDU,1,12},	//( - , DU) Индикация  СБРОС РБ1
	{&B2VS32LDU,1,13},	//( - , DU) Индикация  СБРОС РБ2
	{&A3VX01LDU,1,14},	//( - , DU) Индикация Выстрел ИС1
	{&B3VX01LDU,1,15},	//( - , DU) Индикация Выстрел ИС2
	{&R0VS18LDU,1,16},	//( - , DU) Индикация  Проверка схем сброса
	{&A3VZ13LZ2,1,17},	//( - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{&A3VZ13LZ1,1,18},	//( - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{&A3VZ15LZ1,1,19},	//( - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{&A3VZ15LZ2,1,20},	//( - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{&B2IS33LDU,1,21},	//( - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
	{&B3IS31LDU,1,22},	//( - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
	{&B3IS33LDU,1,23},	//( - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
	{&B3IS35LDU,1,24},	//( - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
	{&B4IS10LDU,1,25},	//( - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
	{&R3IS11LDU,1,26},	//( - K17VDSR, DU) Приход на ВУ гомогенных дверей
	{&R3IS21LDU,1,27},	//( - K18VDSR, DU) Приход на НУ гомогенных дверей
	{&R0AB03LDU,1,28},	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
	{&R0AB05LDU,1,29},	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
	{&A2AB15LDU,1,30},	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{&B2AB15LDU,1,31},	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{&R0VX02LDU,1,32},	//( - , DU) Импульс разрешен
	{&R0EE03LDU,1,33},	//( - , DU) ВПИС ИС
	{&B7AS31LDU,1,34},	//( - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
	{&A7AZ03LDU,1,35},	//( - , DU) Несанкционированное включение обдува АЗ1
	{&B7AZ03LDU,1,36},	//( - , DU) Несанкционированное включение обдува АЗ2
	{&R0VZ71LDU,1,37},	//( - , DU) Обобщенный сигнал АЗ
	{&A2IS33LDU,1,38},	//( - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
	{&A3IS31LDU,1,39},	//( - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
	{&A3IS33LDU,1,40},	//( - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
	{&A3IS35LDU,1,41},	//( - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
	{&A4IS10LDU,1,42},	//( - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
	{&A1VN71LZ1,1,43},	//( - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{&A1VN71LZ2,1,44},	//( - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{&A1AB19LDU,1,45},	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
	{&R0AD14LZ1,1,46},	//( - K20VDSR, DU) Имитация срабатывания АЗ от II УР
	{&R0AD14LZ2,1,47},	//( - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
	{&R0VX03LDU,1,48},	//( - , DU) Готовность 2 мин
	{&R0AB02LDU,1,49},	//( - , DU) Нарушение времени задержки ИНИ
	{&R0AB06LDU,1,50},	//( - , DU) Нарушение времени задержки от ВУ РБ
	{&R0AB04LDU,1,51},	//( - , DU) Нарушение времени срабатывания верхней АС II УР
	{&R0VX01LDU,1,52},	//( - , DU) ДО ИМПУЛЬСА
	{&B1AD31LDU,1,53},	//( - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
	{&A1AD31LDU,1,54},	//( - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
	{&B3AB07LDU,1,55},	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
	{&B3AB08LDU,1,56},	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
	{&B3AB05LDU,1,57},	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
	{&B3AB06LDU,1,58},	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
	{&B3AB09LDU,1,59},	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
	{&B3AB10LDU,1,60},	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
	{&B3AB11LDU,1,61},	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
	{&B3AB12LDU,1,62},	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{&B3AB14LDU,1,63},	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
	{&B3AB16LDU,1,64},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
	{&B3AB17LDU,1,65},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
	{&B3AB18LDU,1,66},	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
	{&B3AB20LDU,1,67},	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
	{&A2AD31LDU,1,68},	//( - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
	{&B2AD31LDU,1,69},	//( - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
	{&A9IS11LDU,1,70},	//( - K23VDSR, DU) Приход на ВУ НИ ДС1
	{&A9IS21LDU,1,71},	//( - K24VDSR, DU) Приход на НУ НИ ДС1
	{&B9IS11LDU,1,72},	//( - K25VDSR, DU) Приход на ВУ НИ ДС2
	{&A9AZ03LDU,1,73},	//( - , DU) Несанкционированное перемещение НИ ДС1
	{&A9AB01LDU,1,74},	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
	{&A9AB02LDU,1,75},	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
	{&B9AZ03LDU,1,76},	//( - , DU) Несанкционированное перемещение НИ ДС2
	{&B9AB01LDU,1,77},	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
	{&B9AB02LDU,1,78},	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
	{&R0AB01LDU,1,79},	//( - , DU) Режим проверки разрешён
	{&A3IS22LDU,1,80},	//( - K02VDSR, DU) Приход на НУП ИС1
	{&B3IS22LDU,1,81},	//( - K04VDSR, DU) Приход на НУП ИС2
	{&A2IS11LDU,1,82},	//( - K11VDSR, DU) Приход на ВУ РБ1-СТР
	{&B2IS11LDU,1,83},	//( - K11VDSR, DU) Приход на ВУ РБ2-СТР
	{&A4VS12LDU,1,84},	//( - , DU) Движение НИ1 в сторону ВУ
	{&A4VS22LDU,1,85},	//( - , DU) Движение НИ1 в сторону НУ
	{&B4VS12LDU,1,86},	//( - , DU) Движение НИ2 в сторону ВУ
	{&B4VS22LDU,1,87},	//( - , DU) Движение НИ2 в сторону НУ
	{&A1IS11LDU,1,88},	//( - K08VDSR, DU) Приход на ВУ ББ1
	{&A3AB13LDU,1,89},	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
	{&B3AB13LDU,1,90},	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
	{&TestDiagnDU,1,91},	//( - , DU) Неисправность от
	{&psb1,1,92},	//( - , DU) ру не готова
	{&psb2,1,93},	//( - , DU) движение бб
	{&psrb4,1,94},	//( - , DU) кнопка сброс
	{&psrb1,1,95},	//( - , DU) пневматика по мощности
	{&psrb2,1,96},	//( - , DU) пневматика по программам
	{&psrb,1,97},	//( - , DU) ???
	{&B1IS11LDU,1,98},	//( - K08VDSR, DU) Приход на ВУ ББ2
	{&B0VS11LDU,1,99},	//( - , DU) АЗ2 готова к работе
	{&R0EE02LDU,1,100},	//( - , DU) Питание  АКНП  отключить
	{&psaz11,1,101},	//( - , DU) каналы
	{&psaz12,1,102},	//( - , DU) напряжение
	{&psaz13,1,103},	//( - , DU) давление
	{&psaz14,1,104},	//( - , DU) ас темп з2
	{&psaz15,1,105},	//( - , DU) ас темп з1
	{&psaz21,1,106},	//( - , DU) каналы
	{&psaz22,1,107},	//( - , DU) напряжение
	{&psaz23,1,108},	//( - , DU) давление
	{&psaz24,1,109},	//( - , DU) ас темп з2
	{&psaz25,1,110},	//( - , DU) питание
	{&psaz3,1,111},	//( - , DU) энкодеры
	{&A3VP42LDU,1,112},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
	{&A3VP52LDU,1,113},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
	{&B3VP42LDU,1,114},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
	{&B3VP52LDU,1,115},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
	{&B3VP82LDU,1,116},	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
	{&A3VP82LDU,1,117},	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
	{&A0VE01LDU,1,118},	//( - , DU) Напряжение в системы АЗ1 подано
	{&B0VE01LDU,1,119},	//( - , DU) Напряжение в системы АЗ2 подано
	{&A0VP01LDU,1,120},	//( - , DU) Давление в системы АЗ1 подано
	{&B0VP01LDU,1,121},	//( - , DU) Давление в системы АЗ2 подано
	{&A0VN01LDU,1,122},	//( - , DU) Каналы АЗ1 проверены
	{&B0VN01LDU,1,123},	//( - , DU) Каналы АЗ2 проверены
	{&A0VS11LDU,1,124},	//( - , DU) АЗ1 готова к работе
	{&B3IS12LDU,1,125},	//( - , DU) Приход на ВУ штока ИС2
	{&A3IS12LDU,1,126},	//( - , DU) Приход на ВУ штока ИС1
	{&R0AB15LDU,1,127},	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
	{&R0AB14LDU,1,128},	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
	{&A4DW,1,129},	//( - , DU) 
	{&A4UP,1,130},	//( - , DU) 
	{&R4ABL,1,131},	//( - , DU) Блокировка тележки -
	{&A9ZAV,1,132},	//( - , DU) Завершение НИ ДС1(2)
	{&A8ZAV,1,133},	//( - , DU) 
	{&A2ZAV,1,134},	//( - , DU) Завершение РБ1,2
	{&B8ZAV,1,135},	//( - , DU) 
	{&A5ZAV,1,136},	//( - , DU) 
	{&R2ZAV,1,137},	//( - , DU) 
	{&A6ZAV,1,138},	//( - , DU) 
	{&A4ZAV,1,139},	//( - , DU) 
	{&R0AB13LDU,1,140},	//( - , DU) Ошибка в заданной координате  АЗ2
	{&R0AB07LDU,1,141},	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
	{&R0VS11LDU,1,142},	//( - , DU) РУ не готова к работе
	{&B6AB05LDU,1,143},	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
	{&R0AB08LDU,1,144},	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
	{&R0AB09LDU,1,145},	//( - , DU) Ошибка в заданной координате ББ1
	{&R0AB10LDU,1,146},	//( - , DU) Ошибка в заданной координате ББ2
	{&R0AB11LDU,1,147},	//( - , DU) Ошибка в заданной координате  ИС1
	{&R0AB12LDU,1,148},	//( - , DU) Ошибка в заданной координате  ИС2
	{&B8IS12LDU,1,149},	//( - K21VDSR, DU) Приход на ВУ2 АЗ2
	{&B8IS21LDU,1,150},	//( - K20VDSR, DU) Приход на НУ1 АЗ2
	{&R0VL22LDU,1,151},	//( - , DU) Конец программы 200сек
	{&R0VL23LDU,1,152},	//( - , DU) Конец программы 20мин
	{&A3AB19LDU,1,153},	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
	{&B3AB19LDU,1,154},	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
	{&A3EE03LDU,1,155},	//( - , DU) ВПИС ИС1
	{&B3EE03LDU,1,156},	//( - , DU) ВПИС ИС2
	{&B3AB15LDU,1,157},	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
	{&R5IS21LDU,1,158},	//( - K26VDSR, DU) Приход на НУ ворот отстойной зоны
	{&R5VS22LDU,1,159},	//( - , DU) Движение ворот отстойной зоны к закрыты
	{&R5VS12LDU,1,160},	//( - , DU) Движение ворот отстойной зоны к открыты
	{&R3VS22LDU,1,161},	//( - , DU) Движение гомогенных дверей к закрыты
	{&R3VS12LDU,1,162},	//( - , DU) Движение гомогенных дверей к открыты
	{&A1ZAV,1,163},	//( - , DU) 
	{&A3ZAV,1,164},	//( - , DU) 
	{&B1AB19LDU,1,165},	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
	{&R0AB16LDU,1,166},	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
	{&R0AB17LDU,1,167},	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
	{&R0AB18LDU,1,168},	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
	{&A3AB15LDU,1,169},	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
	{&R0AB20LDU,1,170},	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
	{&R0AB19LDU,1,171},	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
	{&A6AB06LDU,1,172},	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
	{&R4IS11LDU,1,173},	//( - K05VDSR, DU) Приход на ВУ1 тележки
	{&B2IS12LDU,1,174},	//( - K10VDSR, DU) Магнит РБ2 зацеплен
	{&B1IS12LDU,1,175},	//( - K07VDSR, DU) Магнит ББ2 зацеплен
	{&A2IS12LDU,1,176},	//( - K10VDSR, DU) Магнит РБ1 зацеплен
	{&A1IS12LDU,1,177},	//( - K07VDSR, DU) Магнит ББ1 зацеплен
	{&B5AB04LDU,1,178},	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
	{&A5AB04LDU,1,179},	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
	{&B4AB02LDU,1,180},	//( - , DU) Блокировка движения НИ2 - Нет перемещения
	{&B4AB01LDU,1,181},	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
	{&B4AZ03LDU,1,182},	//( - , DU) Несанкционированное перемещение НИ2
	{&A4AB02LDU,1,183},	//( - , DU) Блокировка движения НИ1 - Нет перемещения
	{&A4AB01LDU,1,184},	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
	{&A4AZ03LDU,1,185},	//( - , DU) Несанкционированное перемещение НИ1
	{&B4IS21LDU,1,186},	//( - K32VDSR, DU) Приход на НУ НИ2
	{&A4IS21LDU,1,187},	//( - K15VDSR, DU) Приход на НУ НИ1
	{&R4AB17LDU,1,188},	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
	{&R4AB18LDU,1,189},	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
	{&R4AD20LDU,1,190},	//( - K14FDSR, DU) Перемещение тележки назад
	{&A5VS22LDU,1,191},	//( - K12VDSR, DU) Движение НЛ1 в сторону НУ
	{&A5VS12LDU,1,192},	//( - K11VDSR, DU) Движение НЛ1 в сторону ВУ
	{&B5VS22LDU,1,193},	//( - K15VDSR, DU) Движение НЛ2 в сторону НУ
	{&B5VS12LDU,1,194},	//( - K14VDSR, DU) Движение НЛ2 в сторону ВУ
	{&A5IS11LDU,1,195},	//( - K11VDSR, DU) Приход на ВУ НЛ1
	{&A5IS21LDU,1,196},	//( - K12VDSR, DU) Приход на НУ НЛ1
	{&B5IS11LDU,1,197},	//( - K15VDSR, DU) Приход на ВУ НЛ2
	{&B5IS21LDU,1,198},	//( - K16VDSR, DU) Приход на НУ НЛ2
	{&A5AZ03LDU,1,199},	//( - , DU) Несанкционированное перемещение НЛ1
	{&A5AB01LDU,1,200},	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
	{&A5AB02LDU,1,201},	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
	{&B5AZ03LDU,1,202},	//( - , DU) Несанкционированное перемещение НЛ2
	{&B5AB01LDU,1,203},	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
	{&B5AB02LDU,1,204},	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
	{&B8AB01LDU,1,205},	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
	{&B8AB04LDU,1,206},	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
	{&B8AB08LDU,1,207},	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
	{&B8AB09LDU,1,208},	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
	{&B8AB10LDU,1,209},	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
	{&B8AB11LDU,1,210},	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
	{&B8AB12LDU,1,211},	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
	{&B8AB13LDU,1,212},	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
	{&B8AB14LDU,1,213},	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
	{&B8AB02LDU,1,214},	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
	{&A8VS12LDU,1,215},	//( - , DU) Движение ДС2 в сторону ВУ
	{&A8AB06LDU,1,216},	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
	{&A8AB07LDU,1,217},	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
	{&A8AB05LDU,1,218},	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
	{&A8VS22LDU,1,219},	//( - , DU) Движение ДС2 в сторону НУ
	{&A8AZ03LDU,1,220},	//( - , DU) Несанкционированное перемещение ДС2
	{&A6AB07LDU,1,221},	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
	{&A6AB08LDU,1,222},	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
	{&A6AB09LDU,1,223},	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
	{&B6AB06LDU,1,224},	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
	{&B6AB07LDU,1,225},	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
	{&B6AB08LDU,1,226},	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
	{&B6AB09LDU,1,227},	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
	{&A6AB05LDU,1,228},	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
	{&B8VS12LDU,1,229},	//( - , DU) Движение АЗ2 в сторону ВУ
	{&B8AB06LDU,1,230},	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
	{&B8AB07LDU,1,231},	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
	{&B8AB05LDU,1,232},	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
	{&B8VS22LDU,1,233},	//( - , DU) Движение АЗ2 в сторону НУ
	{&B8AZ03LDU,1,234},	//( - , DU) Несанкционированное перемещение АЗ2
	{&B8IS11LDU,1,235},	//( - K19VDSR, DU) Приход на ВУ1 АЗ2
	{&B6AB01LDU,1,236},	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
	{&B6AZ03LDU,1,237},	//( - , DU) Несанкционированное перемещение БЗ2
	{&A6AB02LDU,1,238},	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
	{&A6AB01LDU,1,239},	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
	{&A6AZ03LDU,1,240},	//( - , DU) Несанкционированное перемещение БЗ1
	{&B6VS12LDU,1,241},	//( - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
	{&B6VS22LDU,1,242},	//( - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
	{&A6VS12LDU,1,243},	//( - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
	{&A6VS22LDU,1,244},	//( - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
	{&B6IS21LDU,1,245},	//( - K14VDSR, DU) Приход на НУ БЗ2
	{&B6IS11LDU,1,246},	//( - K13VDSR, DU) Приход на ВУ БЗ2
	{&A6IS21LDU,1,247},	//( - K10VDSR, DU) Приход на НУ БЗ1
	{&A6IS11LDU,1,248},	//( - K09VDSR, DU) Приход на ВУ БЗ1
	{&A1IS21LDU,1,249},	//( - K09VDSR, DU) Приход на НУ ББ1
	{&A2IS21LDU,1,250},	//( - K12VDSR, DU) Приход на НУ РБ1-СС
	{&A3IS21LDU,1,251},	//( - K13VDSR, DU) Приход на НУ ИС1
	{&B1IS21LDU,1,252},	//( - K09VDSR, DU) Приход на НУ ББ2
	{&B2IS21LDU,1,253},	//( - K12VDSR, DU) Приход на НУ РБ2-СС
	{&B3IS21LDU,1,254},	//( - K13VDSR, DU) Приход на НУ ИС2
	{&R0ES01LDU,1,255},	//( - , DU) ОРР не в исходном состоянии
	{&R2IS21LDU,1,256},	//( - K30VDSR, DU) Приход на НУ МДЗ2
	{&R4AB04LDU,1,257},	//( - , DU) Блокировка движения тележки - Превышение времени движения
	{&R4AB05LDU,1,258},	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
	{&R4AB06LDU,1,259},	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
	{&R4AB07LDU,1,260},	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
	{&R4AB08LDU,1,261},	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
	{&R4AB09LDU,1,262},	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
	{&R4AB10LDU,1,263},	//( - , DU) Блокировка тележки - не открыта биологическая защита
	{&R4AB11LDU,1,264},	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
	{&R4AB12LDU,1,265},	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
	{&A4IS11LDU,1,266},	//( - K14VDSR, DU) Приход на ВУ НИ1
	{&B4IS11LDU,1,267},	//( - K31VDSR, DU) Приход на ВУ НИ2
	{&R4AB13LDU,1,268},	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
	{&R4AB14LDU,1,269},	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
	{&R4AB15LDU,1,270},	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
	{&R5IS11LDU,1,271},	//( - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
	{&R4AB16LDU,1,272},	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
	{&B6AB02LDU,1,273},	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
	{&A6AB04LDU,1,274},	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
	{&B6AB04LDU,1,275},	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
	{&R4AB01LDU,1,276},	//( - , DU) Блокировка движения тележки - АНИ не установлен
	{&R8IS11LDU,1,277},	//( - K14VDSR, DU) Аварийный НИ установлен
	{&R4AB02LDU,1,278},	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
	{&R4IS21LDU,1,279},	//( - K07VDSR, DU) Приход на НУ1 тележки
	{&R4IS22LDU,1,280},	//( - K08VDSR, DU) Приход на НУ2 тележки
	{&R4IS12LDU,1,281},	//( - K06VDSR, DU) Приход на ВУ2 тележки
	{&R4VS22LDU,1,282},	//( - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
	{&R4VS12LDU,1,283},	//( - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
	{&R4AZ03LDU,1,284},	//( - , DU) Несанкционированное перемещение тележки
	{&R4AB03LDU,1,285},	//( - , DU) Блокировка движения тележки - Самоход любого механизма
	{&R1IS21LDU,1,286},	//( - K28VDSR, DU) Приход на НУ МДЗ1
	{&B1AB11LDU,1,287},	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
	{&B1AB10LDU,1,288},	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
	{&B1AB09LDU,1,289},	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
	{&B1AB06LDU,1,290},	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
	{&B1AB05LDU,1,291},	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
	{&B1AB08LDU,1,292},	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
	{&B1AB07LDU,1,293},	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
	{&B1AZ03LDU,1,294},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
	{&B1VS22LDU,1,295},	//( - , DU) Движение ББ2 в сторону НУ
	{&B1AB01LDU,1,296},	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
	{&B1AB02LDU,1,297},	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
	{&B1AB04LDU,1,298},	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
	{&B1VS12LDU,1,299},	//( - , DU) Движение ББ2 в сторону ВУ
	{&A1AB18LDU,1,300},	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
	{&A1AB02LDU,1,301},	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
	{&A1AB01LDU,1,302},	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
	{&A1VS22LDU,1,303},	//( - , DU) Движение ББ1 в сторону НУ
	{&A1AZ03LDU,1,304},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
	{&A1AB07LDU,1,305},	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
	{&A1AB08LDU,1,306},	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
	{&A1AB05LDU,1,307},	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
	{&A1AB06LDU,1,308},	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
	{&A1AB09LDU,1,309},	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
	{&A1AB10LDU,1,310},	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
	{&A1AB11LDU,1,311},	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
	{&A1AB12LDU,1,312},	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&A1AB13LDU,1,313},	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
	{&A1AB14LDU,1,314},	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
	{&A1AB16LDU,1,315},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
	{&A1AB17LDU,1,316},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
	{&A3AB06LDU,1,317},	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
	{&A3AB09LDU,1,318},	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
	{&A3AB10LDU,1,319},	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
	{&A3AB11LDU,1,320},	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
	{&A3AB12LDU,1,321},	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&A3AB14LDU,1,322},	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
	{&A3AB16LDU,1,323},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
	{&A3AB17LDU,1,324},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
	{&A3AB18LDU,1,325},	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
	{&A3AB20LDU,1,326},	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
	{&B3VS12LDU,1,327},	//( - , DU) Движение ИС2 в сторону ВУ
	{&B3AB04LDU,1,328},	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
	{&B3AB02LDU,1,329},	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
	{&B3AB01LDU,1,330},	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
	{&B3VS22LDU,1,331},	//( - , DU) Движение ИС2 в сторону НУ
	{&B3AZ03LDU,1,332},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
	{&B1AB12LDU,1,333},	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&B1AB13LDU,1,334},	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
	{&B1AB14LDU,1,335},	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
	{&B1AB16LDU,1,336},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
	{&B1AB17LDU,1,337},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
	{&B1AB18LDU,1,338},	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
	{&A3VS12LDU,1,339},	//( - , DU) Движение ИС1 в сторону ВУ
	{&A3AB04LDU,1,340},	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
	{&A3AB02LDU,1,341},	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
	{&A3AB01LDU,1,342},	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
	{&A3VS22LDU,1,343},	//( - , DU) Движение ИС1 в сторону НУ
	{&A3AZ03LDU,1,344},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
	{&A3AB07LDU,1,345},	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
	{&A3AB08LDU,1,346},	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
	{&A3AB05LDU,1,347},	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
	{&A2AB01LDU,1,348},	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
	{&A2VS21LDU,1,349},	//( - , DU) Движение РБ1 в сторону НУ
	{&A2AZ03LDU,1,350},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
	{&A2AB07LDU,1,351},	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
	{&A2AB08LDU,1,352},	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
	{&A2AB05LDU,1,353},	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
	{&A2AB06LDU,1,354},	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
	{&A2AB09LDU,1,355},	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
	{&A2AB10LDU,1,356},	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
	{&A2AB11LDU,1,357},	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
	{&A2AB12LDU,1,358},	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&A2AB13LDU,1,359},	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
	{&A2AB14LDU,1,360},	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
	{&A2AB16LDU,1,361},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
	{&A2AB17LDU,1,362},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
	{&B8IS22LDU,1,363},	//( - K22VDSR, DU) Приход на НУ2 АЗ2
	{&A8IS12LDU,1,364},	//( - K30VDSR, DU) Приход на механический ВУ ДС2
	{&A8AB04LDU,1,365},	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
	{&A8IS22LDU,1,366},	//( - K31VDSR, DU) Приход на механический НУ ДС2
	{&A8AB08LDU,1,367},	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
	{&A8AB09LDU,1,368},	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
	{&A8AB10LDU,1,369},	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
	{&A8AB11LDU,1,370},	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
	{&A8AB12LDU,1,371},	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
	{&A8AB13LDU,1,372},	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
	{&A8AB14LDU,1,373},	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
	{&A8AB02LDU,1,374},	//( - , DU) Блокировка движения ДС2- АНИ не установлен
	{&A8AB01LDU,1,375},	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
	{&A2VS11LDU,1,376},	//( - , DU) Движение РБ1 в сторону ВУ
	{&A2AB04LDU,1,377},	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
	{&A2AB02LDU,1,378},	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
	{&R1AZ03LDU,1,379},	//( - , DU) Несанкционированное перемещение МДЗ1
	{&R1AB01LDU,1,380},	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
	{&R1AB02LDU,1,381},	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
	{&R2AZ03LDU,1,382},	//( - , DU) Несанкционированное перемещение МДЗ2
	{&R2AB01LDU,1,383},	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
	{&R2AB02LDU,1,384},	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
	{&R1AB04LDU,1,385},	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
	{&R2AB04LDU,1,386},	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
	{&R1IS11LDU,1,387},	//( - K27VDSR, DU) Приход на ВУ МДЗ1
	{&R1VS22LDU,1,388},	//( - K06VDSR, DU) Движение МДЗ1 в сторону НУ
	{&R2VS22LDU,1,389},	//( - K09VDSR, DU) Движение МДЗ2 в сторону НУ
	{&R2VS12LDU,1,390},	//( - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
	{&R1VS12LDU,1,391},	//( - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
	{&R2IS11LDU,1,392},	//( - K29VDSR, DU) Приход на ВУ МДЗ2
	{&A1VS12LDU,1,393},	//( - , DU) Движение ББ1 в сторону ВУ
	{&A1AB04LDU,1,394},	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
	{&B2AB04LDU,1,395},	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
	{&B2AB02LDU,1,396},	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
	{&B2AB01LDU,1,397},	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
	{&B2AZ03LDU,1,398},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
	{&B2AB07LDU,1,399},	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
	{&B2AB08LDU,1,400},	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
	{&B2AB05LDU,1,401},	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
	{&B2AB06LDU,1,402},	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
	{&B2AB09LDU,1,403},	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
	{&B2AB10LDU,1,404},	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
	{&B2AB11LDU,1,405},	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
	{&B2AB12LDU,1,406},	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{&B2AB13LDU,1,407},	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
	{&B2AB14LDU,1,408},	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
	{&B2AB16LDU,1,409},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
	{&B2AB17LDU,1,410},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DU[]={  // 
	{&B2VS01IDU,3,0},	//( - , DU) Готовность к управлению РБ2
	{&R0VX08IDU,3,1},	//( - , DU) Индикация Режим
	{&R0VL01RDU,8,2},	//( - , DU) Индикация Время задержки
	{&R0VL21IDU,3,4},	//( - , DU) Декатрон
	{&R0VL05RDU,8,5},	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
	{&R0VL03RDU,8,7},	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
	{&R0VL04RDU,8,9},	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
	{&R0VL02RDU,8,11},	//( - , DU) Индикация (Время задержки ИНИ)
	{&R0VL06RDU,8,13},	//( - , DU) Индикация (Время задержки от ВУ РБ)
	{&R0VL11IDU,3,15},	//( - , DU) До импульса секунд
	{&R0VL01IDU,3,16},	//( - , DU) До импульса минут
	{&R1VS01IDU,3,17},	//( - , DU) Готовность к управлению МДЗ1
	{&R0VS21IDU,3,18},	//( - , DU) Индикация ВИД ПРОВЕРКИ
	{&A1VS01IDU,3,19},	//( - , DU) Готовность к управлению ББ1
	{&B1VS01IDU,3,20},	//( - , DU) Готовность к управлению ББ2
	{&A3VS01IDU,3,21},	//( - , DU) Готовность к управлению ИС1
	{&B3VS01IDU,3,22},	//( - , DU) Готовность к управлению ИС2
	{&A2VS01IDU,3,23},	//( - , DU) Готовность к управлению РБ1
	{&A4VS01IDU,3,24},	//( - , DU) Готовность к управлению НИ1
	{&B4VS01IDU,3,25},	//( - , DU) Готовность к управлению НИ2
	{&A5VS01IDU,3,26},	//( - , DU) Готовность к управлению НЛ1
	{&B5VS01IDU,3,27},	//( - , DU) Готовность к управлению НЛ2
	{&A6VS01IDU,3,28},	//( - , DU) Готовность к управлению БЗ1
	{&R4VS01IDU,3,29},	//( - , DU) Готовность к управлению тележкой реактора
	{&R2VS01IDU,3,30},	//( - , DU) Готовность к управлению МДЗ2
	{&A1VC01RDU,8,31},	//( - , DU) Координата ББ1, мм
	{&R3VS01IDU,3,33},	//( - , DU) Готовность к управлению гомогенных дверей
	{&TTLDU,3,34},	//( - , DU) ttl
	{&B3CV01RDU,8,35},	//( - , DU) Измеренная скорость перемещения ИС2
	{&R0VN15RDU,8,37},	//( - , DU) Период разгона РУ
	{&B1VC01RDU,8,39},	//( - , DU) Координата ББ2, мм
	{&B3VC01RDU,8,41},	//( - , DU) Координата ИС2, мм
	{&A8VC01RDU,8,43},	//( - , DU) Координата ДС2, мм
	{&A3VC01RDU,8,45},	//( - , DU) Координата ИС1, мм
	{&A2VC01RDU,8,47},	//( - , DU) Координата РБ1, мм
	{&B2VC01RDU,8,49},	//( - , DU) Координата РБ2, мм
	{&B8VC01RDU,8,51},	//( - , DU, MDuBz1, MDuBz2) Координата АЗ2, мм
	{&A3CP02RDU,8,53},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
	{&B3CP02RDU,8,55},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
	{&B6VS01IDU,3,57},	//( - , DU) Готовность к управлению БЗ2
	{&B8VS01IDU,3,58},	//( - , DU) Готовность к управлению АЗ2
	{&A8VS01IDU,3,59},	//( - , DU) Готовность к управлению ДС2
	{&R0CN94LDU,8,60},	//( - , DU) Скорость изменения мощности
	{&R0CN95LDU,3,62},	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
	{&R5VS01IDU,3,63},	//( - , DU) Готовность к управлению ворот отстойной зоны
	{&A3MC01RDU,8,64},	//( - , DU) Заданная координата положения ИС от регулятора мм
	{&A3MC02RDU,8,66},	//( - , DU) Температурная корректировка координаты ИМ
	{&R0CN91LDU,8,68},	//( - , DU) Рассчётная реактивность от регулятора
	{&A3MC03RDU,8,70},	//( - , DU) Координата положения ИМ 0-й реактивности
	{&R0CN92LDU,8,72},	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
	{&R0VN11RDU,8,74},	//( - , DU) Текущая мощность РУ
	{&R0VN12RDU,8,76},	//( - , DU) Заданная мощность РУ
	{&R0CN93LDU,8,78},	//( - , DU) время работы на мощности более 100Вт, сек
	{&A8CV01RDU,8,80},	//( - , DU) Измеренная скорость перемещения ДС2
	{&B8CV01RDU,8,82},	//( - , DU) Измеренная скорость перемещения АЗ2
	{&B1CV02RDU,8,84},	//( - , DU) Заданная скорость перемещения ББ2
	{&B1CV01RDU,8,86},	//( - , DU) Измеренная скорость перемещения ББ2
	{&A1CV02RDU,8,88},	//( - , DU) Заданная скорость перемещения ББ1
	{&B3CV02RDU,8,90},	//( - , DU) Заданная скорость перемещения ИС2
	{&A3CV01RDU,8,92},	//( - , DU) Измеренная скорость перемещения ИС1
	{&A3CV02RDU,8,94},	//( - , DU) Заданная скорость перемещения ИС1
	{&A2CV02RDU,8,96},	//( - , DU) Заданная скорость перемещения РБ1
	{&B2CV01RDU,8,98},	//( - , DU) Измеренная скорость перемещения РБ2
	{&A2CV01RDU,8,100},	//( - , DU) Измеренная скорость перемещения РБ1
	{&A1CV01RDU,8,102},	//( - , DU) Измеренная скорость перемещения ББ1
	{&B2CV02RDU,8,104},	//( - , DU) Заданная скорость перемещения РБ2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DU[]={  // 
	{&R0MW14IP2,3,0},	//( - , DU) Переключатель ОБДУВ
	{&R0MW12IP2,3,1},	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
	{&A1MC01RP1,8,2},	//( - , DU) Заданная координата положения ББ1 мм
	{&B1MC01RP1,8,4},	//( - , DU) Заданная координата положения ББ2  мм
	{&A3MC01RP1,8,6},	//( - , DU) Заданная координата положения ИС1 мм
	{&B3MC01RP1,8,8},	//( - , DU) Заданная координата положения ИС2 мм
	{&B8MC01RP2,8,10},	//( - , DU) Заданная координата АЗ2 мм
	{&R0MW15IP1,3,12},	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
	{&R0MW14IP1,3,13},	//( - , DU) Переключатель ПРОГРАММЫ
	{&R0MW12IP1,3,14},	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
	{&R0MW13IP1,3,15},	//( - , DU) Переключатель ВЫБОР ЗОН
	{&R0MW16IP1,3,16},	//( - , DU) Переключатель ВИД ПРОВЕРКИ
	{&R0MW11IP1,3,17},	//( - , DU) Переключатель ВЫСТРЕЛ
	{&R0MW11IP2,3,18},	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
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
	{&fEM_R7UI76RDU,8,339},	//( - , DU) Время срабатывания сигнала II УР при имитации
	{&fEM_R0UL00RDU,8,341},	//( - , DU) Время ожидания передачи  сигнала отключения сети
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
	{&R0VN11RZ2,8,2},	//( - , Baz2, SBz2DU) Средняя мощность по БАЗ2
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
	{&venc08,5,75},
	{&venc07,5,70},
	{&venc06,5,65},
	{&venc05,5,60},
	{&venc04,5,55},
	{&venc03,5,50},
	{&venc02,5,45},
	{&venc01,5,40},
	{&R0DE06LDU,3,80},
	{&R0DE01LDU,3,82},
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
	{&R8AD22LDU,1,28},
	{&B2IS12LDU,1,18},
	{&B1IS12LDU,1,12},
	{&B7AS31LDU,1,10},
	{&R0DE02LDU,3,64},
	{&B4IS21LDU,1,62},
	{&B3IS33LDU,1,2},
	{&B3IS35LDU,1,0},
	{&R8IS11LDU,1,26},
	{&B4IS10LDU,1,6},
	{&B1IS11LDU,1,14},
	{&R1IS11LDU,1,52},
	{&B3IS31LDU,1,8},
	{&B2IS33LDU,1,4},
	{&B1IS21LDU,1,16},
	{&B2IS21LDU,1,22},
	{&B3IS21LDU,1,24},
	{&A3VZ15LZ1,1,36},
	{&A3VZ13LZ1,1,34},
	{&A9IS11LDU,1,44},
	{&A9IS21LDU,1,46},
	{&B9IS11LDU,1,48},
	{&B2IS11LDU,1,20},
	{&B9IS21LDU,1,50},
	{&B4IS11LDU,1,60},
	{&R0AD14LZ1,1,38},
	{&A1VN71LZ1,1,40},
	{&R2IS11LDU,1,56},
	{&R0VZ71LZ1,1,42},
	{&R2IS21LDU,1,58},
	{&R1IS21LDU,1,54},
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
	{&A3VZ13LZ2,1,34},
	{&A3VZ15LZ2,1,36},
	{&R0AD14LZ2,1,38},
	{&A1VN71LZ2,1,40},
	{&R0DE03LDU,3,64},
	{&A2IS11LDU,1,20},
	{&R0IS02LDU,1,58},
	{&R0IS01LDU,1,56},
	{&A7AS31LDU,1,10},
	{&A4IS10LDU,1,6},
	{&A1IS21LDU,1,16},
	{&A2IS21LDU,1,22},
	{&A3IS21LDU,1,24},
	{&A3IS35LDU,1,0},
	{&A3IS33LDU,1,2},
	{&A4IS11LDU,1,26},
	{&A3IS31LDU,1,8},
	{&A1IS11LDU,1,14},
	{&A2IS33LDU,1,4},
	{&R0VZ71LZ2,1,42},
	{&A4IS21LDU,1,28},
	{&A1IS12LDU,1,12},
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
	{&R4IS22LDU,1,14},
	{&R4IS12LDU,1,10},
	{&B6IS11LDU,1,24},
	{&B8IS12LDU,1,40},
	{&B8IS21LDU,1,38},
	{&R3IS21LDU,1,34},
	{&R3IS11LDU,1,32},
	{&R5IS11LDU,1,48},
	{&R5IS21LDU,1,50},
	{&A3IS11LDU,1,0},
	{&B3IS11LDU,1,4},
	{&R6IS21LDU,1,56},
	{&B6IS21LDU,1,26},
	{&A6IS21LDU,1,18},
	{&A6IS11LDU,1,16},
	{&R0DE04LDU,3,64},
	{&B5IS21LDU,1,30},
	{&B5IS11LDU,1,28},
	{&A8IS22LDU,1,60},
	{&A8IS12LDU,1,58},
	{&B8IS22LDU,1,42},
	{&A5IS21LDU,1,22},
	{&A5IS11LDU,1,20},
	{&B8IS11LDU,1,36},
	{&B3IS22LDU,1,6},
	{&A3IS22LDU,1,2},
	{&R4IS21LDU,1,12},
	{&R4IS11LDU,1,8},
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
	{&B3IE04LDU,1,46},
	{&B3IE03LDU,1,44},
	{&B2IE04LDU,1,38},
	{&B2IE03LDU,1,36},
	{&R0DE05LDU,3,64},
	{&A1IE04LDU,1,6},
	{&A2IE03LDU,1,12},
	{&A2IE04LDU,1,14},
	{&A3IE03LDU,1,20},
	{&B1IE03LDU,1,28},
	{&A3IE04LDU,1,22},
	{&A1IE03LDU,1,4},
	{&A3IE02LDU,1,16},
	{&A1IE02LDU,1,0},
	{&A2IE01LDU,1,10},
	{&A2IE02LDU,1,8},
	{&B1IE01LDU,1,26},
	{&B2IE01LDU,1,34},
	{&A3IE01LDU,1,18},
	{&A1IE01LDU,1,2},
	{&B3IE01LDU,1,42},
	{&R6IS51LDU,1,56},
	{&R6IS52LDU,1,58},
	{&R6IS41LDU,1,52},
	{&R6IS42LDU,1,54},
	{&R6IS32LDU,1,50},
	{&R6IS31LDU,1,48},
	{&B1IE02LDU,1,24},
	{&B3IE02LDU,1,40},
	{&B2IE02LDU,1,32},
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
	{&B2AD02LDU,1,20},
	{&B2AD03LDU,1,22},
	{&B2AD04LDU,1,24},
	{&B2AD05LDU,1,26},
	{&R0DE07LDU,3,38},
	{&B2AD01LDU,1,18},
	{&A2AD03LDU,1,8},
	{&A2AD02LDU,1,6},
	{&B2AD21LDU,1,16},
	{&B2AD11LDU,1,14},
	{&A2AD01LDU,1,4},
	{&A2AD04LDU,1,10},
	{&A2AD05LDU,1,12},
	{&A2AD11LDU,1,0},
	{&R0S01LZ1,1,28},
	{&R0S01LZ2,1,30},
	{&A2AD21LDU,1,2},
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
	{&B1AD05LDU,1,26},
	{&B1AD04LDU,1,24},
	{&B1AD03LDU,1,22},
	{&A1AD01LDU,1,4},
	{&B1AD02LDU,1,20},
	{&B1AD21LDU,1,16},
	{&B1AD11LDU,1,14},
	{&A1AD05LDU,1,12},
	{&A1AD04LDU,1,10},
	{&A1AD03LDU,1,8},
	{&A1AD02LDU,1,6},
	{&A1AD21LDU,1,2},
	{&A1AD11LDU,1,0},
	{&R0S01LIM,1,28},
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
	{&B2AD33LDU,1,4},
	{&R4AD10LDU,1,24},
	{&R4AD20LDU,1,26},
	{&B3AD33LDU,1,2},
	{&A8AD20LDU,1,14},
	{&A8AD10LDU,1,12},
	{&B8AD10LDU,1,28},
	{&B8AD20LDU,1,30},
	{&B3AD34LDU,1,0},
	{&B3AD31LDU,1,8},
	{&A6AD10LDU,1,16},
	{&A6AD20LDU,1,18},
	{&B4AD10LDU,1,6},
	{&B6AD10LDU,1,20},
	{&R0DE09LDU,3,38},
	{&B6AD20LDU,1,22},
	{&B7AP31LDU,1,10},
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
	{&R1AD10LDU,1,12},
	{&A3AD31LDU,1,8},
	{&A3AD34LDU,1,0},
	{&A3AD33LDU,1,2},
	{&A7AP31LDU,1,10},
	{&A2AD33LDU,1,4},
	{&R1AD20LDU,1,14},
	{&B5AD10LDU,1,24},
	{&B5AD20LDU,1,26},
	{&R2AD10LDU,1,16},
	{&A5AD10LDU,1,20},
	{&A5AD20LDU,1,22},
	{&R2AD20LDU,1,18},
	{&A4AD10LDU,1,6},
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
	{&B3AD11LDU,1,14},
	{&B3AD21LDU,1,16},
	{&B3AD02LDU,1,20},
	{&B3AD01LDU,1,18},
	{&B3AD05LDU,1,26},
	{&B3AD04LDU,1,24},
	{&B3AD03LDU,1,22},
	{&A3AD01LDU,1,4},
	{&A3AD05LDU,1,12},
	{&A3AD04LDU,1,10},
	{&A3AD11LDU,1,0},
	{&A3AD21LDU,1,2},
	{&A3AD03LDU,1,8},
	{&A3AD02LDU,1,6},
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
	{&B3IP02IDU,3,3},
	{&A3IP02IDU,3,0},
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
	{&B5VS12LDU,1,26},
	{&A5VS22LDU,1,22},
	{&A5VS12LDU,1,20},
	{&R0DE0DLDU,3,64},
	{&R4VS12LDU,1,2},
	{&R4VS22LDU,1,4},
	{&B5VS22LDU,1,28},
	{&A6VS22LDU,1,34},
	{&A6VS12LDU,1,32},
	{&B6VS22LDU,1,40},
	{&B6VS12LDU,1,38},
	{&R1VS22LDU,1,10},
	{&R2VS22LDU,1,16},
	{&R2VS12LDU,1,14},
	{&R1VS12LDU,1,8},
	{&R0IE02LDU,1,44},
	{&R0IE01LDU,1,46},
	{&A6IE01LDU,1,36},
	{&B6IE01LDU,1,42},
	{&A8IE01LDU,1,6},
	{&B5IE01LDU,1,30},
	{&A5IE02LDU,1,24},
	{&R1IE01LDU,1,12},
	{&R2IE01LDU,1,18},
	{&R6IS61LDU,1,0},
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
	{&A2AD32LDU,1,4},
	{&R0AD16LDU,1,24},
	{&B2AD32LDU,1,12},
	{&A1AD32LDU,1,0},
	{&B1AD32LDU,1,8},
	{&B1AD31LDU,1,10},
	{&R0AD05LZ2,1,30},
	{&R0DE0FLDU,3,38},
	{&A1AD31LDU,1,2},
	{&B2AD31LDU,1,14},
	{&A2AD31LDU,1,6},
	{&R0AD03LZ1,1,16},
	{&R0AD03LZ2,1,26},
	{&R0AD04LZ1,1,18},
	{&R8AD21LDU,1,22},
	{&R0AD04LZ2,1,28},
	{&R0AD05LZ1,1,20},
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
	{&R0DEB3LDU,1,22},
	{&R0DEB4LDU,1,24},
	{&R0DEB1LDU,1,18},
	{&R0DEB2LDU,1,20},
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
	setAsFloat(751,0.00009765625);
	setAsInt(752,1024200);
	setAsInt(753,-200);
	setAsInt(754,-200);
	setAsInt(755,1024200);
	setAsFloat(756,0.00009765625);
	setAsInt(757,-200);
	setAsInt(758,1689599);
	setAsFloat(759,0.00009765625);
	setAsInt(760,-200);
	setAsFloat(761,0.0009765625);
	setAsInt(762,1536200);
	setAsFloat(763,100);
	setAsFloat(764,200);
	setAsFloat(765,300);
	setAsFloat(766,400);
	setAsFloat(767,600);
	setAsFloat(768,500);
	setAsFloat(769,750);
	setAsFloat(770,2.5);
	setAsFloat(771,0);
	setAsFloat(772,0.46);
	setAsFloat(773,0.49);
	setAsFloat(774,0.52);
	setAsFloat(775,0.53);
	setAsFloat(776,0.67);
	setAsFloat(777,0.56);
	setAsFloat(778,4);
	setAsFloat(779,4);
	setAsFloat(780,10.91);
	setAsFloat(781,3);
	setAsShort(782,4);
	setAsFloat(783,0.4);
	setAsFloat(784,0.4);
	setAsFloat(785,0.4);
	setAsFloat(786,0.4);
	setAsFloat(787,0.03);
	setAsFloat(788,0.04);
	setAsFloat(789,3);
	setAsFloat(790,0.4);
	setAsFloat(791,0.4);
	setAsFloat(792,0.07);
	setAsFloat(793,0.04);
	setAsFloat(794,3);
	setAsFloat(795,0.55);
	setAsFloat(796,0.64);
	setAsFloat(797,0.190);
	setAsFloat(798,0.045);
	setAsFloat(799,0.1);
	setAsFloat(800,2);
	setAsFloat(801,0.3);
	setAsFloat(802,3);
	setAsFloat(803,1.50);
	setAsFloat(804,0.04);
	setAsFloat(805,0.05);
	setAsFloat(806,3);
	setAsFloat(807,1.50);
	setAsFloat(808,3);
	setAsFloat(809,1.50);
	setAsFloat(810,2);
	setAsFloat(811,0.004);
	setAsFloat(812,0.006);
	setAsFloat(813,0.006);
	setAsFloat(814,1.0);
	setAsFloat(815,0.01);
	setAsFloat(816,1);
	setAsFloat(817,0.008);
	setAsFloat(818,0.01);
	setAsFloat(819,1);
	setAsFloat(820,0.4);
	setAsFloat(821,120);
	setAsFloat(822,0.6);
	setAsFloat(823,1);
	setAsFloat(824,2);
	setAsFloat(825,1.50);
	setAsFloat(826,2.0);
	setAsFloat(827,1);
	setAsFloat(828,15);
	setAsFloat(829,0.50);
	setAsFloat(830,360);
	setAsFloat(831,1);
	setAsFloat(832,2);
	setAsFloat(833,1.0);
	setAsFloat(834,6.0);
	setAsFloat(835,0.50);
	setAsFloat(836,1.0);
	setAsFloat(837,16.0);
	setAsFloat(838,3.0);
	setAsFloat(839,1.0);
	setAsFloat(840,60.0);
	setAsFloat(841,0.50);
	setAsFloat(842,1.0);
	setAsFloat(843,20.0);
	setAsFloat(844,1);
	setAsFloat(845,2.0);
	setAsFloat(846,2.0);
	setAsFloat(847,1.5);
	setAsFloat(848,0.045);
	setAsFloat(849,0.045);
	setAsFloat(850,0.150);
	setAsFloat(851,0.045);
	setAsFloat(852,0.045);
	setAsFloat(853,0.015);
	setAsFloat(854,2000.0);
	setAsFloat(855,1500.0);
	setAsFloat(856,1000.0);
	setAsFloat(857,800.0);
	setAsFloat(858,500.0);
	setAsFloat(859,200.0);
	setAsFloat(860,100.0);
	setAsFloat(861,0.001);
	setAsFloat(862,100);
	setAsFloat(863,100);
	setAsFloat(864,110.0);
	setAsFloat(865,20);
	setAsFloat(866,30.0);
	setAsFloat(867,100.0);
	setAsFloat(868,1.50);
	setAsFloat(869,170);
	setAsFloat(870,170);
	setAsFloat(871,10);
	setAsShort(872,1);
	setAsShort(873,4);
	setAsShort(874,1);
	setAsShort(875,4);
	setAsShort(876,4);
	setAsShort(877,4);
	setAsShort(878,4);
	setAsBool(879,0);
	setAsFloat(880,159.99);
	setAsFloat(881,0.002375);
	setAsFloat(882,0.000877);
	setAsFloat(883,0.001675);
	setAsFloat(884,2.5);
	setAsFloat(885,30);
	setAsFloat(886,500);
	setAsFloat(887,0.01);
	setAsFloat(888,0.05);
	setAsFloat(889,160.0);
	setAsFloat(890,-141.21);
	setAsFloat(891,71.40565);
	setAsFloat(892,0.271145);
	setAsFloat(893,24.93556615);
	setAsFloat(894,0.1268);
	setAsFloat(895,0.1567);
	setAsFloat(896,0.1858);
	setAsFloat(897,0.2066);
	setAsFloat(898,0.2646);
	setAsFloat(899,0.2995);
	setAsFloat(900,0.839554030);
	setAsFloat(901,0.78859401);
	setAsFloat(902,0.765962);
	setAsFloat(903,0.67256403);
	setAsFloat(904,0.42476001);
	setAsFloat(905,0.25501999);
	setAsFloat(906,3600.0);
	setAsFloat(907,0.935);
	setAsFloat(908,0.1);
	setAsFloat(909,0.006792308);
	setAsFloat(910,0.000418877);
	setAsFloat(911,0.001);
	setAsFloat(912,0.190);
	setAsFloat(913,0.5);
	setAsFloat(914,2.0);
	setAsFloat(915,0.005);
	setAsFloat(916,0.08);
	setAsFloat(917,0.100);
	setAsBool(242,1);
	setAsBool(244,1);
	setAsBool(240,1);
	setAsBool(243,1);
	setAsBool(245,1);
	setAsBool(241,1);
	setAsBool(280,1);
	setAsBool(281,1);
	setAsBool(235,1);
}
uspaint8 InternalBuf[9933];

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
ssint iRM_16000_ = {16000,0}; /* b */ 
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

uspaint8 SpaEEPROMBuf[816];

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
ssfloat var45;
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
ssint var262;
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
ssint var388;
ssbool var389;
ssbool var390;
ssint var391;
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
ssfloat var432;
ssbool var433;
ssbool var434;
ssbool var435;
ssbool var436;
ssbool var437;
ssbool var438;
ssbool var439;
ssbool var440;
ssbool var441;
ssfloat var442;
ssfloat var443;
ssbool var444;
ssbool var445;
ssbool var446;
ssfloat var447;
ssbool var448;
ssbool var449;
ssfloat var450;
ssbool var451;
ssbool var452;
ssbool var453;
ssbool var454;
ssbool var455;
ssbool var456;
ssbool var457;
ssbool var458;
ssfloat var459;
ssfloat var460;
ssfloat var461;
ssfloat var462;
ssbool var463;
ssfloat var464;
ssfloat var465;
ssint var466;
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
ssfloat var557;
ssbool var558;
ssbool var559;
ssbool var560;
ssfloat var561;
ssbool var562;
ssbool var563;
ssbool var564;
ssfloat var565;
ssbool var566;
ssbool var567;
ssbool var568;
ssfloat var569;
ssbool var570;
ssbool var571;
ssbool var572;
ssfloat var573;
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
ssfloat var659;
ssfloat var660;
ssbool var661;
ssfloat var662;
ssfloat var663;
ssbool var664;
ssfloat var665;
ssfloat var666;
ssbool var667;
ssfloat var668;
ssfloat var669;
ssbool var670;
ssbool var671;
ssfloat var672;
ssfloat var673;
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
sslong var803;
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
ssfloat var1213;
ssbool var1214;
ssfloat var1215;
ssbool var1216;
ssfloat var1217;
ssbool var1218;
ssbool var1219;
ssbool var1220;
ssbool var1221;
ssfloat var1222;
ssfloat var1223;
ssfloat var1224;
ssfloat var1225;
ssfloat var1226;
ssfloat var1227;
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
ssbool var1277;
ssbool var1278;
ssbool var1279;
ssbool var1280;
ssbool var1281;
ssbool var1282;
ssbool var1283;
ssbool var1284;
ssbool var1285;
ssbool var1286;
ssint var1287;
ssint var1288;
ssbool var1289;
ssbool var1290;
ssbool var1291;
ssbool var1292;
ssbool var1293;
ssbool var1294;
sslong var1295;
ssbool var1296;
ssbool var1297;
ssbool var1298;
ssint var1299;
ssbool var1300;
ssbool var1301;
ssbool var1302;
ssbool var1303;
ssbool var1304;
ssbool var1305;
ssbool var1306;
ssbool var1307;
ssbool var1308;
ssint var1309;
ssint var1310;
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
ssbool var1338;
ssbool var1339;
ssbool var1340;
ssbool var1341;
ssbool var1342;
ssbool var1343;
ssbool var1344;
ssbool var1345;
ssbool var1346;
ssbool var1347;
ssbool var1348;
ssbool var1349;
sslong var1350;
ssbool var1351;
ssbool var1352;
ssbool var1353;
ssbool var1354;
ssbool var1355;
ssbool var1356;
ssbool var1357;
ssbool var1358;
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
ssfloat var1369;
ssbool var1370;
ssbool var1371;
ssbool var1372;
ssbool var1373;
ssbool var1374;
ssfloat var1375;
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
ssbool var1388;
ssint var1389;
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
ssfloat var1414;
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
ssbool var1504;
ssbool var1505;
ssbool var1506;
ssbool var1507;
sslong var1508;
ssbool var1509;
ssint var1510;
ssint var1511;
ssbool var1512;
ssfloat var1513;
ssfloat var1514;
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
ssint var1532;
ssbool var1533;
sschar var1534;
ssint var1535;
ssbool var1536;
ssfloat var1537;
ssbool var1538;
ssbool var1539;
ssbool var1540;
ssbool var1541;
ssbool var1542;
ssbool var1543;
ssbool var1544;
ssfloat var1545;
sschar var1546;
ssbool var1547;
ssbool var1548;
ssbool var1549;
ssbool var1550;
ssfloat var1551;
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
ssint var1593;
ssbool var1594;
sschar var1595;
ssint var1596;
ssbool var1597;
ssfloat var1598;
ssbool var1599;
ssbool var1600;
ssbool var1601;
ssbool var1602;
ssbool var1603;
ssbool var1604;
ssbool var1605;
ssfloat var1606;
sschar var1607;
ssbool var1608;
ssbool var1609;
ssbool var1610;
ssbool var1611;
ssfloat var1612;
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
ssbool var1625;
ssint var1626;
ssbool var1627;
sschar var1628;
ssint var1629;
ssbool var1630;
ssfloat var1631;
ssbool var1632;
ssbool var1633;
ssbool var1634;
ssbool var1635;
ssbool var1636;
ssbool var1637;
ssbool var1638;
ssfloat var1639;
sschar var1640;
ssbool var1641;
ssbool var1642;
ssfloat var1643;
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
ssint var1656;
ssbool var1657;
ssbool var1658;
ssbool var1659;
ssbool var1660;
ssbool var1661;
ssbool var1662;
ssbool var1663;
ssbool var1664;
ssint var1665;
ssbool var1666;
ssbool var1667;
ssbool var1668;
ssbool var1669;
ssbool var1670;
ssbool var1671;
ssbool var1672;
ssint var1673;
ssbool var1674;
sschar var1675;
ssint var1676;
ssbool var1677;
ssfloat var1678;
ssbool var1679;
ssbool var1680;
ssbool var1681;
ssbool var1682;
ssbool var1683;
ssbool var1684;
ssbool var1685;
ssfloat var1686;
sschar var1687;
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
ssbool var1698;
sschar var1699;
ssbool var1700;
ssbool var1701;
ssbool var1702;
ssbool var1703;
ssbool var1704;
ssbool var1705;
ssbool var1706;
ssbool var1707;
ssbool var1708;
sschar var1709;
ssbool var1710;
ssbool var1711;
ssint var1712;
ssbool var1713;
sschar var1714;
ssbool var1715;
ssint var1716;
ssbool var1717;
ssbool var1718;
ssfloat var1719;
ssbool var1720;
ssbool var1721;
ssbool var1722;
ssbool var1723;
ssbool var1724;
ssbool var1725;
ssbool var1726;
ssfloat var1727;
sschar var1728;
ssbool var1729;
ssbool var1730;
ssbool var1731;
ssbool var1732;
ssfloat var1733;
ssbool var1734;
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
ssfloat var1746;
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
ssfloat var1763;
ssbool var1764;
ssbool var1765;
ssbool var1766;
ssbool var1767;
ssbool var1768;
ssbool var1769;
ssbool var1770;
ssbool var1771;
ssbool var1772;
ssbool var1773;
ssbool var1774;
ssbool var1775;
ssbool var1776;
ssbool var1777;
ssbool var1778;
ssbool var1779;
ssbool var1780;
ssbool var1781;
ssbool var1782;
ssbool var1783;
ssbool var1784;
ssbool var1785;
ssbool var1786;
ssbool var1787;
ssbool var1788;
ssbool var1789;
ssbool var1790;
ssbool var1791;
ssbool var1792;
ssbool var1793;
ssbool var1794;
ssbool var1795;
ssbool var1796;
ssbool var1797;
ssbool var1798;
ssbool var1799;
ssbool var1800;
ssint var1801;
ssbool var1802;
ssbool var1803;
ssbool var1804;
ssbool var1805;
ssbool var1806;
ssbool var1807;
ssbool var1808;
ssbool var1809;
ssint var1810;
ssbool var1811;
ssbool var1812;
ssbool var1813;
ssbool var1814;
ssbool var1815;
ssbool var1816;
ssbool var1817;
ssbool var1818;
ssint var1819;
ssbool var1820;
ssbool var1821;
ssbool var1822;
ssbool var1823;
ssbool var1824;
ssbool var1825;
ssbool var1826;
ssbool var1827;
ssint var1828;
ssbool var1829;
ssbool var1830;
ssbool var1831;
ssbool var1832;
ssbool var1833;
ssbool var1834;
ssbool var1835;
ssbool var1836;
ssint var1837;
ssbool var1838;
ssbool var1839;
ssbool var1840;
ssbool var1841;
ssbool var1842;
ssbool var1843;
ssbool var1844;
ssbool var1845;
ssint var1846;
ssbool var1847;
ssbool var1848;
ssbool var1849;
ssbool var1850;
ssbool var1851;
ssbool var1852;
ssbool var1853;
ssbool var1854;
ssint var1855;
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
ssbool var1875;
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
ssbool var1910;
ssbool var1911;
ssbool var1912;
ssbool var1913;
ssbool var1914;
ssbool var1915;
ssfloat var1916;
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
ssbool var1938;
ssbool var1939;
ssbool var1940;
ssbool var1941;
ssbool var1942;
ssbool var1943;
ssbool var1944;
ssbool var1945;
ssbool var1946;
ssbool var1947;
ssbool var1948;
ssbool var1949;
ssbool var1950;
ssfloat var1951;
ssfloat var1952;
ssbool var1953;
ssbool var1954;
ssbool var1955;
ssbool var1956;
ssbool var1957;
ssbool var1958;
ssbool var1959;
ssbool var1960;
ssbool var1961;
ssbool var1962;
ssbool var1963;
ssbool var1964;
ssbool var1965;
ssbool var1966;
ssbool var1967;
ssbool var1968;
ssbool var1969;
ssbool var1970;
ssbool var1971;
ssbool var1972;
ssbool var1973;
ssbool var1974;
ssbool var1975;
ssbool var1976;
ssbool var1977;
ssbool var1978;
ssfloat var1979;
ssbool var1980;
ssbool var1981;
ssfloat var1982;
ssbool var1983;
ssbool var1984;
ssfloat var1985;
ssbool var1986;
ssbool var1987;
ssfloat var1988;
ssbool var1989;
ssbool var1990;
ssfloat var1991;
ssbool var1992;
ssbool var1993;
ssfloat var1994;
ssbool var1995;
ssbool var1996;
ssfloat var1997;
ssbool var1998;
ssbool var1999;
ssbool var2000;
ssfloat var2001;
ssbool var2002;
ssbool var2003;
ssbool var2004;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m179_x_2[13] = {&R0IE02LDU,&R0IE01LDU,&R1IE01LDU,&R2IE01LDU,&A5IE02LDU,&B5IE01LDU,&A6IE01LDU,&R6IS61LDU,&R6IS67LZZ,&R6IS68LZZ,&B6IE01LDU,&A8IE01LDU,&R6IS66LZZ};
psbool  array_m166_x_2[6] = {&var1898,&var1897,&var1896,&var1895,&var1894,&var1893};
psbool  array_m138_x_2[6] = {&var1904,&var1903,&var1902,&var1901,&var1900,&var1899};
psbool  array_m279_x_2[6] = {&var1963,&var1955,&var1969,&B0VT71LZ1,&B0VT71LZ2,&var1914};
psbool  array_m268_x_2[6] = {&var1964,&var1957,&var1970,&A0VT71LZ1,&A0VT71LZ2,&var1914};
psbool  array_m291_x_2[6] = {&var1948,&B0VP71LZ1,&B0VP71LZ2,&var1919,&var1918,&var1917};
psbool  array_m270_x_2[6] = {&var1949,&A0VP71LZ1,&A0VP71LZ2,&var1922,&var1921,&var1920};
psbool  array_m124_x_2[8] = {&var1981,&var2003,&var1999,&var1996,&var1993,&var1990,&var1984,&var1987};
psint  array_m2523_x_1[14] = {&R0DE0DLDU,&R0DE0FLDU,&R0DE02LDU,&R0DE03LDU,&R0DE04LDU,&R0DE05LDU,&R0DE07LDU,&R0DE08LDU,&R0DE09LDU,&R0DE0ALDU,&R0DE0BLDU,&R0DE0CLDU,&R0DE01LDU,&R0DE06LDU};
psbool  array_m898_x_1[6] = {&var833,&var1471,&var1447,&var1436,&var1238,&var338};
psbool  array_m1359_x_1[6] = {&var832,&var1451,&var265,&var1473,&var1238,&var358};
psbool  array_m666_x_1[6] = {&var1028,&var1341,&var1758,&var1302,&var1717,&var1335};
psbool  array_m665_x_1[6] = {&var1028,&var1342,&var1758,&var1302,&var1717,&var1334};
psfloat  array_m2430_a_1[6] = {&fEM_R0UN70LDU,&fEM_R0UN71LDU,&fEM_R0UN72LDU,&fEM_R0UN73LDU,&fEM_R0UN74LDU,&fEM_R0UN75LDU};
psfloat  array_m2430_b_1[6] = {&fEM_R0UN80LDU,&fEM_R0UN81LDU,&fEM_R0UN82LDU,&fEM_R0UN83LDU,&fEM_R0UN84LDU,&fEM_R0UN85LDU};
psfloat  array_m2441_x_1[4] = {&B0CT01IZ1,&A0CT01IZ1,&B0CT01IZ2,&A0CT01IZ2};
psbool  array_m2433_x_1[14] = {&var446,&var419,&var1062,&var479,&var481,&var417,&var1880,&var1460,&var1458,&var1915,&var445,&var434,&var430,&var453};
psbool  array_m1_x_1[47] = {&var1423,&var1863,&var578,&var313,&var717,&var1627,&var951,&R0MD34LP1,&var865,&R0MD34LP1,&var924,&R0MD34LP1,&var1158,&R0MD34LP1,&var978,&R0MD34LP1,&var1156,&var1654,&A2IS12LDU,&var634,&var1454,&var1349,&var1347,&var1260,&var1071,&R0MD34LP1,&var654,&var695,&var1498,&var1808,&R0MD34LP1,&var37,&var801,&var756,&B3IS35LDU,&B3IS35LDU,&var500,&var311,&var728,&var547,&var1859,&var1817,&var1844,&var1177,&var1831,&R2IS21LDU,&var420};
psfloat  array_m1669_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psbool  array_m1620_x_1[5] = {&var37,&var36,&var35,&var34,&var33};
psbool  array_m616_x_1[12] = {&var976,&var982,&var983,&var974,&var975,&var1160,&var1161,&var473,&var971,&var972,&var970,&var978};
psfloat  array_m88_x_1[2] = {&R0VN11RZ2,&R0VN11RZ1};
psfloat  array_m90_x_1[8] = {&fEM_R0UN01RDU,&fEM_R0UN02RDU,&fEM_R0UN03RDU,&fEM_R0UN04RDU,&fEM_R0UN05RDU,&fEM_R0UN06RDU,&fEM_R0UN07RDU,&fEM_R0UN08RDU};
psfloat  array_m1191_x_1[2] = {&R0VN11RZ2,&R0VN11RZ1};
psfloat  array_m1369_x_1[8] = {&var1719,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m906_x_1[8] = {&var1678,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m1004_x_1[8] = {&var1569,&var443,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m1482_x_1[8] = {&var1537,&var442,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m548_x_1[8] = {&var1598,&var569,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m173_x_1[8] = {&var1631,&var573,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m356_Tpr_1[10] = {&fRM_6_0,&fRM_126_0,&fRM_246_0,&fRM_366_0,&fRM_486_0,&fRM_606_0,&fRM_726_0,&fRM_846_0,&fRM_966_0,&fRM_1200_0};
pschar  array_m356_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m356_rz_1[10];
psbool  array_m360_x_1[5] = {&var1290,&var1291,&var1292,&var1293,&var1294};
psbool  array_m294_x_1[7] = {&var1062,&var475,&var1269,&var1266,&var481,&var479,&var477};
psfloat  array_m298_Tpr_1[10] = {&fRM_10_0,&fRM_30_0,&fRM_50_0,&fRM_70_0,&fRM_90_0,&fRM_110_0,&fRM_130_0,&fRM_150_0,&fRM_170_0,&fRM_200_0};
pschar  array_m298_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m298_rz_1[10];
psfloat  array_m1600_Tpr_1[6] = {&fRM_0_5,&fRM_3_5,&fRM_6_5,&fRM_9_5,&fRM_12_5,&fRM_15_5};
pschar  array_m1600_type_1[6] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_6_};
pschar  array_m1600_rz_1[6];
psbool  array_m314_x_1[5] = {&var1312,&var1313,&var1314,&var1315,&var1316};
psbool  array_m1340_x_1[5] = {&var1435,&var1045,&var1790,&var1440,&var491};
psbool  array_m1328_x_1[4] = {&var1346,&var1388,&var1262,&var1438};
psfloat  array_m1653_x_1[16] = {&var659,&var668,&fRM_0_,&var665,&fRM_0_,&fRM_0_,&fRM_0_,&var662,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&var672};
psbool  array_m1988_x_1[17] = {&var739,&var740,&var746,&var741,&var737,&var738,&var1195,&var742,&var743,&var1487,&var744,&var745,&var1479,&var1480,&var1489,&var485,&var486};
psbool  array_m1604_x_1[5] = {&var651,&var774,&var791,&var792,&var681};
psint  array_m333_x_1[3] = {&var1288,&iRM_0_,&var1310};
psint  array_m324_x_1[3] = {&var1287,&iRM_0_,&var1309};
psbool  array_m668_x_1[5] = {&var1011,&var1757,&var1524,&var1239,&var451};
psbool  array_m1553_x_1[8] = {&var895,&var896,&var897,&var892,&var891,&var890,&var1156,&var888};
psbool  array_m1481_x_1[3] = {&var340,&lRM_0_,&var339};
psfloat  array_m1483_Lt_fw_1[1] = {&fEM_A3UC81RDU};
psint  array_m1483_Vr_fw_1[1] = {&iEM_A3UV01IDU};
psfloat  array_m1483_Lt_bw_1[1] = {&fEM_A3UC82RDU};
psint  array_m1483_Vr_bw_1[1] = {&iEM_A3UV02IDU};
psfloat  array_m1509_x0_1[60];
psfloat  array_m1509_tim0_1[60];
psbool  array_m1082_x_1[8] = {&var910,&var912,&var913,&var905,&var911,&var907,&var1158,&var649};
psbool  array_m1003_x_1[3] = {&var366,&lRM_0_,&var361};
psfloat  array_m1005_Lt_fw_1[1] = {&fEM_A3UC81RDU};
psint  array_m1005_Vr_fw_1[1] = {&iEM_A3UV01IDU};
psfloat  array_m1005_Lt_bw_1[1] = {&fEM_A3UC82RDU};
psint  array_m1005_Vr_bw_1[1] = {&iEM_A3UV02IDU};
psfloat  array_m1035_x0_1[60];
psfloat  array_m1035_tim0_1[60];
psbool  array_m547_x_1[3] = {&var987,&lRM_0_,&var988};
psfloat  array_m550_Lt_fw_1[2] = {&fEM_A1UC81RDU,&fEM_A1UC82RDU};
psint  array_m550_Vr_fw_1[2] = {&iEM_A1UV01IDU,&iEM_A1UV02IDU};
psfloat  array_m550_Lt_bw_1[1] = {&fEM_A1UC83RDU};
psint  array_m550_Vr_bw_1[1] = {&iEM_A1UV03IDU};
psfloat  array_m573_x0_1[150];
psfloat  array_m573_tim0_1[150];
psbool  array_m250_x_1[12] = {&var956,&var958,&var957,&var954,&var952,&var951,&var950,&var1164,&var1163,&var945,&var948,&var474};
psbool  array_m172_x_1[3] = {&var1134,&lRM_0_,&var1135};
psfloat  array_m176_Lt_fw_1[2] = {&fEM_A1UC81RDU,&fEM_A1UC82RDU};
psint  array_m176_Vr_fw_1[2] = {&iEM_A1UV01IDU,&iEM_A1UV02IDU};
psfloat  array_m176_Lt_bw_1[1] = {&fEM_A1UC83RDU};
psint  array_m176_Vr_bw_1[1] = {&iEM_A1UV03IDU};
psfloat  array_m201_x0_1[150];
psfloat  array_m201_tim0_1[150];
psbool  array_m968_x_1[10] = {&var922,&var923,&var929,&var930,&var928,&var926,&var925,&var1166,&var1165,&var924};
psbool  array_m905_x_1[3] = {&var342,&var940,&var341};
psfloat  array_m909_Lt_fw_1[2] = {&fEM_A2UC81RDU,&fEM_A2UC82RDU};
psint  array_m909_Vr_fw_1[2] = {&iEM_A2UV01IDU,&iEM_A2UV02IDU};
psfloat  array_m909_Lt_bw_1[1] = {&fEM_A2UC83RDU};
psint  array_m909_Vr_bw_1[1] = {&iEM_A2UV03CDU};
psfloat  array_m927_x0_1[80];
psfloat  array_m927_tim0_1[80];
psfloat  array_m1804_Lt_fw_1[1] = {&fRM_1000_};
psint  array_m1804_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1804_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1804_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1450_x_1[10] = {&var861,&var862,&var864,&var863,&var865,&var867,&var869,&var866,&var868,&var870};
psbool  array_m154_x_1[5] = {&A1IS21LDU,&A3IS21LDU,&A2IS21LDU,&var1181,&var1180};
psfloat  array_m1273_Lt_fw_1[1] = {&fRM_2000_};
psint  array_m1273_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1273_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1273_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1368_x_1[3] = {&var370,&var855,&var357};
psfloat  array_m1370_Lt_fw_1[2] = {&fEM_A2UC81RDU,&fEM_A2UC82RDU};
psint  array_m1370_Vr_fw_1[2] = {&iEM_A2UV01IDU,&iEM_A2UV02IDU};
psfloat  array_m1370_Lt_bw_1[1] = {&fEM_A2UC83RDU};
psint  array_m1370_Vr_bw_1[1] = {&iEM_A2UV03CDU};
psfloat  array_m1405_x0_1[80];
psfloat  array_m1405_tim0_1[80];
psfloat  array_m1826_x0_1[20];
psfloat  array_m1826_tim0_1[20];
psbool  array_m1236_x_1[8] = {&var1072,&var1069,&var1070,&var1071,&var1068,&var1067,&var1066,&var1065};
psbool  array_m669_x_1[18] = {&R0MD31LP1,&var764,&var1086,&var766,&var1084,&var856,&var991,&var939,&var966,&var986,&var915,&var880,&var1142,&var590,&var589,&var846,&var507,&var444};
psfloat  array_m1300_x0_1[20];
psfloat  array_m1300_tim0_1[20];
psbool  array_m481_x_1[7] = {&var1187,&var1186,&var1185,&var1184,&var1861,&var1176,&var618};
psbool  array_m459_x_1[7] = {&var1189,&var1861,&var1177,&var1190,&var1188,&var1175,&var394};
psbool  array_m854_x_1[17] = {&var1087,&var1132,&var1131,&var1128,&var1127,&var1124,&var1089,&var1126,&var1094,&var1123,&var1119,&var1121,&var1120,&var1091,&var1085,&var1174,&var942};
psbool  array_m140_x_1[21] = {&var965,&var985,&var1230,&var938,&var1229,&var1228,&var1795,&var1804,&var1822,&var1813,&var1849,&var1840,&var717,&var619,&var1220,&var1221,&var1501,&var1495,&var1659,&var1650,&var1831};

/* Объявление структур */
_S_zzfs  S_zzfs_260_2 = {&var1953,&fRM_1_,&var1881,&internal2_m260_tx,&internal2_m260_y0};
_S_zzfs  S_zzfs_258_2 = {&var2004,&fRM_1_,&var1882,&internal2_m258_tx,&internal2_m258_y0};
_S_zzfs  S_zzfs_256_2 = {&B0VT71LZ1,&fRM_1_,&var1883,&internal2_m256_tx,&internal2_m256_y0};
_S_zzfs  S_zzfs_254_2 = {&B0VT71LZ2,&fRM_1_,&var1884,&internal2_m254_tx,&internal2_m254_y0};
_S_zzfs  S_zzfs_252_2 = {&var1969,&fRM_1_,&var1885,&internal2_m252_tx,&internal2_m252_y0};
_S_zzfs  S_zzfs_250_2 = {&var1955,&fRM_1_,&var1886,&internal2_m250_tx,&internal2_m250_y0};
_S_zzfs  S_zzfs_248_2 = {&var1963,&fRM_1_,&var1887,&internal2_m248_tx,&internal2_m248_y0};
_S_zzfs  S_zzfs_246_2 = {&A0VT71LZ1,&fRM_1_,&var1888,&internal2_m246_tx,&internal2_m246_y0};
_S_zzfs  S_zzfs_244_2 = {&A0VT71LZ2,&fRM_1_,&var1889,&internal2_m244_tx,&internal2_m244_y0};
_S_zzfs  S_zzfs_242_2 = {&var1970,&fRM_1_,&var1890,&internal2_m242_tx,&internal2_m242_y0};
_S_zzfs  S_zzfs_240_2 = {&var1957,&fRM_1_,&var1891,&internal2_m240_tx,&internal2_m240_y0};
_S_zzfs  S_zzfs_238_2 = {&var1964,&fRM_1_,&var1892,&internal2_m238_tx,&internal2_m238_y0};
_S_zzfs  S_zzfs_182_2 = {&B2IE02LDU,&fRM_1_,&var1893,&internal2_m182_tx,&internal2_m182_y0};
_S_zzfs  S_zzfs_176_2 = {&B3IE01LDU,&fRM_1_,&var1894,&internal2_m176_tx,&internal2_m176_y0};
_S_zzfs  S_zzfs_172_2 = {&B1IE01LDU,&fRM_1_,&var1895,&internal2_m172_tx,&internal2_m172_y0};
_S_zzfs  S_zzfs_165_2 = {&B2IE01LDU,&fRM_1_,&var1896,&internal2_m165_tx,&internal2_m165_y0};
_S_zzfs  S_zzfs_157_2 = {&B1IE02LDU,&fRM_1_,&var1897,&internal2_m157_tx,&internal2_m157_y0};
_S_zzfs  S_zzfs_155_2 = {&B3IE02LDU,&fRM_1_,&var1898,&internal2_m155_tx,&internal2_m155_y0};
_S_zzfs  S_zzfs_149_2 = {&A3IE02LDU,&fRM_1_,&var1899,&internal2_m149_tx,&internal2_m149_y0};
_S_zzfs  S_zzfs_144_2 = {&A3IE01LDU,&fRM_1_,&var1900,&internal2_m144_tx,&internal2_m144_y0};
_S_zzfs  S_zzfs_141_2 = {&A2IE01LDU,&fRM_1_,&var1901,&internal2_m141_tx,&internal2_m141_y0};
_S_zzfs  S_zzfs_137_2 = {&A1IE01LDU,&fRM_1_,&var1902,&internal2_m137_tx,&internal2_m137_y0};
_S_zzfs  S_zzfs_131_2 = {&A2IE02LDU,&fRM_1_,&var1903,&internal2_m131_tx,&internal2_m131_y0};
_S_zzfs  S_zzfs_127_2 = {&A1IE02LDU,&fRM_1_,&var1904,&internal2_m127_tx,&internal2_m127_y0};
_S_and4  S_and4_108_2 = {&var2000,&var1935,&B8IS11LDU,&B8IS12LDU,&var1905};
_S_lkb  S_lkb_112_2 = {&lRM_1_,&var1933,&var1906};
_S_lkb  S_lkb_109_2 = {&lRM_1_,&var1905,&var1907};
_S_lkb  S_lkb_80_2 = {&lRM_1_,&var1936,&var1908};
_S_lkb  S_lkb_52_2 = {&lRM_1_,&var1941,&var1909};
_S_lkb  S_lkb_83_2 = {&lRM_1_,&var1939,&var1910};
_S_lkb  S_lkb_49_2 = {&lRM_1_,&var1945,&var1911};
_S_lkb  S_lkb_24_2 = {&lRM_1_,&var1943,&var1912};
_S_lkb  S_lkb_20_2 = {&lRM_1_,&var1947,&var1913};
_S_or2  S_or2_294_2 = {&var2004,&var1953,&var1914};
_S_bol  S_bol_234_2 = {&fRM_0_5,&var1916,&var1915};
_S_fsumo  S_fsumo_233_2 = {&var1952,&var1951,&var1916};
_S_noto  S_noto_287_2 = {&B3VP81LDU,&var1917};
_S_noto  S_noto_286_2 = {&B2VP82LDU,&var1918};
_S_noto  S_noto_285_2 = {&B4VP82LDU,&var1919};
_S_noto  S_noto_267_2 = {&A3VP81LDU,&var1920};
_S_noto  S_noto_266_2 = {&A2VP82LDU,&var1921};
_S_noto  S_noto_265_2 = {&A4VP82LDU,&var1922};
_S_schl24  S_schl24_151_2 = {&A0EE02LZ1,&A0EE03LZ1,&A0EE01LZ1,&A0EE04LZ1,&var1923};
_S_schl24  S_schl24_147_2 = {&A0EE03LZ2,&A0EE01LZ2,&A0EE02LZ2,&A0EE04LZ2,&var1924};
_S_or2  S_or2_207_2 = {&var1973,&var1974,&var1925};
_S_or2  S_or2_203_2 = {&var1976,&var1977,&var1926};
_S_and2  S_and2_223_2 = {&var1961,&var1972,&var1927};
_S_or2  S_or2_280_2 = {&var1968,&var1967,&var1928};
_S_and4  S_and4_162_2 = {&A0EE02LZ1,&A0EE04LZ1,&A0EE02LZ2,&A0EE04LZ2,&var1929};
_S_or3  S_or3_161_2 = {&var1929,&var1050,&var1923,&var1930};
_S_and4  S_and4_134_2 = {&A0EE03LZ1,&A0EE01LZ1,&A0EE01LZ2,&A0EE03LZ2,&var1931};
_S_or3  S_or3_133_2 = {&var1931,&var1924,&var1050,&var1932};
_S_and3  S_and3_111_2 = {&var1934,&var2000,&A8IS12LDU,&var1933};
_S_or2  S_or2_104_2 = {&A8MC01LC2,&A8MC01LC1,&var1934};
_S_or2  S_or2_103_2 = {&B8MC01LC2,&B8MC01LC1,&var1935};
_S_and3  S_and3_79_2 = {&var2000,&B3IS11LDU,&var1937,&var1936};
_S_or2  S_or2_71_2 = {&B3MC01LC2,&B3MC01LC1,&var1937};
_S_or2  S_or2_74_2 = {&A3MC01LC2,&A3MC01LC1,&var1938};
_S_and3  S_and3_82_2 = {&var2000,&var1938,&A3IS11LDU,&var1939};
_S_or2  S_or2_44_2 = {&A2MC01LC2,&A2MC01LC1,&var1940};
_S_and3  S_and3_51_2 = {&var2000,&A2IS11LDU,&var1940,&var1941};
_S_or2  S_or2_13_2 = {&A1MC01LC2,&A1MC01LC1,&var1942};
_S_and3  S_and3_23_2 = {&var1942,&var2000,&A1IS11LDU,&var1943};
_S_or2  S_or2_43_2 = {&B2MC01LC1,&B2MC01LC2,&var1944};
_S_and3  S_and3_48_2 = {&var2000,&B2IS11LDU,&var1944,&var1945};
_S_or2  S_or2_11_2 = {&B1MC01LC2,&B1MC01LC1,&var1946};
_S_and3  S_and3_19_2 = {&var2000,&B1IS11LDU,&var1946,&var1947};
_S_and2  S_and2_290_2 = {&var641,&var1925,&var1948};
_S_and2  S_and2_269_2 = {&var641,&var1926,&var1949};
_S_and2  S_and2_230_2 = {&var1962,&var1971,&var1950};
_S_scalzz  S_scalzz_195_2 = {&B3IP02IDU,&iRM_3276_,&iRM_16000_,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&var1951,&internal2_m195_y0};
_S_scalzz  S_scalzz_193_2 = {&A3IP02IDU,&iRM_3276_,&iRM_16000_,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&var1952,&internal2_m193_y0};
_S_noto  S_noto_180_2 = {&var1954,&var1953};
_S_andn  S_andn_179_2 = {array_m179_x_2,&iRM_13_,&var1954};
_S_noto  S_noto_177_2 = {&var1956,&var1955};
_S_andn  S_andn_166_2 = {array_m166_x_2,&iRM_6_,&var1956};
_S_noto  S_noto_145_2 = {&var1958,&var1957};
_S_andn  S_andn_138_2 = {array_m138_x_2,&iRM_6_,&var1958};
_S_noto  S_noto_289_2 = {&var1967,&var1959};
_S_noto  S_noto_271_2 = {&var1968,&var1960};
_S_noto  S_noto_222_2 = {&var1976,&var1961};
_S_noto  S_noto_231_2 = {&var1973,&var1962};
_S_noto  S_noto_160_2 = {&var1930,&var1963};
_S_noto  S_noto_142_2 = {&var1932,&var1964};
_S_noto  S_noto_292_2 = {&var1969,&var1965};
_S_noto  S_noto_276_2 = {&var1970,&var1966};
_S_ornc  S_ornc_279_2 = {array_m279_x_2,&iRM_6_,&var1967,&vainSChar};
_S_ornc  S_ornc_268_2 = {array_m268_x_2,&iRM_6_,&var1968,&vainSChar};
_S_ornc  S_ornc_291_2 = {array_m291_x_2,&iRM_6_,&var1969,&vainSChar};
_S_ornc  S_ornc_270_2 = {array_m270_x_2,&iRM_6_,&var1970,&vainSChar};
_S_tprg  S_tprg_226_2 = {&var1951,&fEM_A3UP85RDU,&fEM_A3UP86RDU,&fEM_A3UP87RDU,&fEM_A3UP88RDU,&var1971,&internal2_m226_y0};
_S_tprg  S_tprg_220_2 = {&var1952,&fEM_A3UP85RDU,&fEM_A3UP86RDU,&fEM_A3UP87RDU,&fEM_A3UP88RDU,&var1972,&internal2_m220_y0};
_S_geterr  S_geterr_200_2 = {&var1951,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var1973};
_S_drg  S_drg_208_2 = {&var1951,&lRM_1_,&lRM_0_,&fEM_A3UP43RDU,&fEM_A3UP44RDU,&var1974,&internal2_m208_y1};
_S_drg  S_drg_216_2 = {&var1951,&lRM_1_,&lRM_0_,&fEM_A3UP53RDU,&fEM_A3UP54RDU,&var1975,&internal2_m216_y1};
_S_geterr  S_geterr_197_2 = {&var1952,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var1976};
_S_drg  S_drg_198_2 = {&var1952,&lRM_1_,&lRM_0_,&fEM_A3UP43RDU,&fEM_A3UP44RDU,&var1977,&internal2_m198_y1};
_S_drg  S_drg_205_2 = {&var1952,&lRM_1_,&lRM_0_,&fEM_A3UP53RDU,&fEM_A3UP54RDU,&var1978,&internal2_m205_y1};
_S_enctkb  S_enctkb_16_2 = {&var1912,&fRM_0_0,&A1IC01UDU,&dEM_A1UC06UDU,&dEM_A1UC05UDU,&fEM_A1UC03RDU,&fRM_100_,&dRM_0_,&var1979,&var1980,&var1981,&internal2_m16_Nk0,&internal2_m16_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_110_2 = {&var1907,&fRM_390_,&B8IC01UDU,&dEM_A8UC06UDU,&dEM_A8UC05UDU,&fEM_A8UC03RDU,&fRM_1500_0,&dRM_0_,&var1982,&var1983,&var1984,&internal2_m110_Nk0,&internal2_m110_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_106_2 = {&var1906,&fRM_390_0,&A8IC01UDU,&dEM_A8UC06UDU,&dEM_A8UC05UDU,&fEM_A8UC03RDU,&fRM_1500_0,&dRM_0_,&var1985,&var1986,&var1987,&internal2_m106_Nk0,&internal2_m106_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_75_2 = {&var1908,&fRM_0_,&B3IC01UDU,&dEM_A3UC06UDU,&dEM_A3UC05UDU,&fEM_A3UC03RDU,&fRM_0_0,&dRM_0_,&var1988,&var1989,&var1990,&internal2_m75_Nk0,&internal2_m75_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_77_2 = {&var1910,&fRM_0_0,&A3IC01UDU,&dEM_A3UC06UDU,&dEM_A3UC05UDU,&fEM_A3UC03RDU,&fRM_0_0,&dRM_0_,&var1991,&var1992,&var1993,&internal2_m77_Nk0,&internal2_m77_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_45_2 = {&var1911,&fRM_0_0,&B2IC01UDU,&dEM_A2UC06UDU,&dEM_A2UC05UDU,&fEM_A2UC03RDU,&fRM_100_,&dRM_0_,&var1994,&var1995,&var1996,&internal2_m45_Nk0,&internal2_m45_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_53_2 = {&var1909,&fRM_0_0,&A2IC01UDU,&dEM_A2UC06UDU,&dEM_A2UC05UDU,&fEM_A2UC03RDU,&fRM_100_,&dRM_0_,&var1997,&var1998,&var1999,&internal2_m53_Nk0,&internal2_m53_SetFlag,&bFirstEnterFlag};
_S_equz_p  S_equz_p_18_2 = {&R0MW12IP1,&iRM_4_,&var2000};
_S_enctkb  S_enctkb_21_2 = {&var1913,&fRM_0_0,&B1IC01UDU,&dEM_A1UC06UDU,&dEM_A1UC05UDU,&fEM_A1UC03RDU,&fRM_100_,&dRM_0_,&var2001,&var2002,&var2003,&internal2_m21_Nk0,&internal2_m21_SetFlag,&bFirstEnterFlag};
_S_ornc  S_ornc_124_2 = {array_m124_x_2,&iRM_8_,&var2004,&vainSChar};
_S_zzfs  S_zzfs_2556_1 = {&var392,&fRM_1_,&vainSBool,&internal1_m2556_tx,&internal1_m2556_y0};
_S_zzfs  S_zzfs_2558_1 = {&C2MD31LP1,&fRM_1_,&var1,&internal1_m2558_tx,&internal1_m2558_y0};
_S_zzfs  S_zzfs_2554_1 = {&var1043,&fRM_1_,&var2,&internal1_m2554_tx,&internal1_m2554_y0};
_S_zzfs  S_zzfs_2552_1 = {&var1153,&fRM_1_,&var3,&internal1_m2552_tx,&internal1_m2552_y0};
_S_zpfs  S_zpfs_221_1 = {&var1633,&fRM_1_,&var4,&internal1_m221_tx,&internal1_m221_y0};
_S_ovbsb  S_ovbsb_220_1 = {&var1928,&var5,&internal1_m220_tx};
_S_or2  S_or2_1229_1 = {&R2IS11LDU,&R1IS11LDU,&var6};
_S_or3  S_or3_1227_1 = {&A3IS21LDU,&B3IS21LDU,&var8,&var7};
_S_noto  S_noto_1234_1 = {&var9,&var8};
_S_and2  S_and2_1235_1 = {&var1568,&var1536,&var9};
_S_or3  S_or3_1225_1 = {&A1IS21LDU,&B1IS21LDU,&var11,&var10};
_S_noto  S_noto_1232_1 = {&var12,&var11};
_S_and2  S_and2_1233_1 = {&var1630,&var1597,&var12};
_S_or3  S_or3_1223_1 = {&A2IS21LDU,&B2IS21LDU,&var14,&var13};
_S_noto  S_noto_1230_1 = {&var15,&var14};
_S_and2  S_and2_1231_1 = {&var1718,&var1677,&var15};
_S_noto  S_noto_1221_1 = {&var6,&var16};
_S_or3  S_or3_1208_1 = {&R0MD34LP1,&var16,&var1231,&var17};
_S_noto  S_noto_1219_1 = {&var7,&var18};
_S_or3  S_or3_1205_1 = {&R0MD34LP1,&var18,&var1233,&var19};
_S_noto  S_noto_1217_1 = {&var10,&var20};
_S_or3  S_or3_1202_1 = {&R0MD34LP1,&var20,&var1235,&var21};
_S_noto  S_noto_1215_1 = {&var13,&var22};
_S_or3  S_or3_1199_1 = {&var1237,&var22,&R0MD34LP1,&var23};
_S_noto  S_noto_132_1 = {&var451,&var24};
_S_and2  S_and2_53_1 = {&var626,&var24,&var25};
_S_or2  S_or2_2307_1 = {&var399,&var701,&var26};
_S_or2  S_or2_2306_1 = {&var716,&var701,&var27};
_S_swtakt  S_swtakt_2101_1 = {&var1367,&var28,&fEM_R0UL00RDU,&var29,&internal1_m2101_x0,&internal1_m2101_tim};
_S_zpfs  S_zpfs_1677_1 = {&var1249,&fEM_R7UI76RDU,&var30,&internal1_m1677_tx,&internal1_m1677_y0};
_S_or4  S_or4_2546_1 = {&var1252,&var1247,&var1242,&var1250,&var31};
_S_or3  S_or3_2547_1 = {&var29,&var1254,&var31,&var32};
_S_or2  S_or2_1626_1 = {&var1862,&var1323,&var33};
_S_or2  S_or2_1619_1 = {&var1863,&var1322,&var34};
_S_or2  S_or2_1614_1 = {&var1864,&var1321,&var35};
_S_or2  S_or2_1610_1 = {&var1865,&var1320,&var36};
_S_or2  S_or2_1606_1 = {&var1866,&var1319,&var37};
_S_noto  S_noto_58_1 = {&var626,&vainSBool};
_S_and2  S_and2_1613_1 = {&var1864,&R0MD11LP2,&var38};
_S_and2  S_and2_1618_1 = {&var1863,&R0MD11LP2,&var39};
_S_and2  S_and2_1609_1 = {&var1865,&R0MD11LP2,&var40};
_S_and2  S_and2_1625_1 = {&var1862,&R0MD11LP2,&var41};
_S_and2  S_and2_1605_1 = {&var1866,&R0MD11LP2,&var42};
_S_and2  S_and2_1629_1 = {&var1317,&var1323,&var43};
_S_or2  S_or2_2088_1 = {&R8AD22LDU,&var654,&var44};
_S_period  S_period_79_1 = {&var1213,&lRM_1_,&iRM_5_,&fEM_R0UL01RSS,&fEM_R0UL02RSS,&fEM_R0UN03RSS,&var45,&internal1_m79_flst,&internal1_m79_chsr,&internal1_m79_chizm,&internal1_m79_sumtim,&internal1_m79_W1,&internal1_m79_W2,&internal1_m79_Wmin,&internal1_m79_Wmax,&internal1_m79_Wlast,&internal1_m79_y0,&internal1_m79_MyFirstEnterFlag};
_S_ovbsb  S_ovbsb_2066_1 = {&var619,&var46,&internal1_m2066_tx};
_S_ovbsb  S_ovbsb_2065_1 = {&var717,&var47,&internal1_m2065_tx};
_S_ovbsb  S_ovbsb_785_1 = {&var1118,&var48,&internal1_m785_tx};
_S_ovbsb  S_ovbsb_742_1 = {&var1117,&var49,&internal1_m742_tx};
_S_ovbsb  S_ovbsb_795_1 = {&var1120,&var50,&internal1_m795_tx};
_S_ovbsb  S_ovbsb_797_1 = {&var1119,&var51,&internal1_m797_tx};
_S_ovbsb  S_ovbsb_796_1 = {&var1121,&var52,&internal1_m796_tx};
_S_ovbsb  S_ovbsb_750_1 = {&var1089,&var53,&internal1_m750_tx};
_S_ovbsb  S_ovbsb_735_1 = {&var1094,&var54,&internal1_m735_tx};
_S_ovbsb  S_ovbsb_746_1 = {&var1091,&var55,&internal1_m746_tx};
_S_ovbsb  S_ovbsb_777_1 = {&var1124,&var56,&internal1_m777_tx};
_S_ovbsb  S_ovbsb_794_1 = {&var1123,&var57,&internal1_m794_tx};
_S_ovbsb  S_ovbsb_767_1 = {&var1127,&var58,&internal1_m767_tx};
_S_ovbsb  S_ovbsb_398_1 = {&var1833,&var59,&internal1_m398_tx};
_S_ovbsb  S_ovbsb_397_1 = {&var1832,&var60,&internal1_m397_tx};
_S_ovbsb  S_ovbsb_396_1 = {&var1834,&var61,&internal1_m396_tx};
_S_ovbsb  S_ovbsb_395_1 = {&var1831,&var62,&internal1_m395_tx};
_S_ovbsb  S_ovbsb_766_1 = {&var1128,&var63,&internal1_m766_tx};
_S_ovbsb  S_ovbsb_761_1 = {&var1131,&var64,&internal1_m761_tx};
_S_ovbsb  S_ovbsb_770_1 = {&var1132,&var65,&internal1_m770_tx};
_S_ovbsb  S_ovbsb_775_1 = {&var1126,&var66,&internal1_m775_tx};
_S_ovbsb  S_ovbsb_531_1 = {&var1652,&var67,&internal1_m531_tx};
_S_ovbsb  S_ovbsb_530_1 = {&var1651,&var68,&internal1_m530_tx};
_S_ovbsb  S_ovbsb_529_1 = {&var1653,&var69,&internal1_m529_tx};
_S_ovbsb  S_ovbsb_525_1 = {&var1650,&var70,&internal1_m525_tx};
_S_ovbsb  S_ovbsb_502_1 = {&var1661,&var71,&internal1_m502_tx};
_S_ovbsb  S_ovbsb_501_1 = {&var1660,&var72,&internal1_m501_tx};
_S_ovbsb  S_ovbsb_500_1 = {&var1662,&var73,&internal1_m500_tx};
_S_ovbsb  S_ovbsb_503_1 = {&var1659,&var74,&internal1_m503_tx};
_S_ovbsb  S_ovbsb_2472_1 = {&var444,&var75,&internal1_m2472_tx};
_S_ovbsb  S_ovbsb_2182_1 = {&var428,&var76,&internal1_m2182_tx};
_S_ovbsb  S_ovbsb_2471_1 = {&var448,&var77,&internal1_m2471_tx};
_S_ovbsb  S_ovbsb_2470_1 = {&var455,&var78,&internal1_m2470_tx};
_S_ovbsb  S_ovbsb_2467_1 = {&var456,&var79,&internal1_m2467_tx};
_S_ovbsb  S_ovbsb_108_1 = {&var576,&var80,&internal1_m108_tx};
_S_ovbsb  S_ovbsb_1148_1 = {&var846,&var81,&internal1_m1148_tx};
_S_ovbsb  S_ovbsb_2330_1 = {&var1496,&var82,&internal1_m2330_tx};
_S_ovbsb  S_ovbsb_2329_1 = {&var1497,&var83,&internal1_m2329_tx};
_S_ovbsb  S_ovbsb_2328_1 = {&var1495,&var84,&internal1_m2328_tx};
_S_ovbsb  S_ovbsb_1260_1 = {&var1066,&var85,&internal1_m1260_tx};
_S_ovbsb  S_ovbsb_1259_1 = {&var1067,&var86,&internal1_m1259_tx};
_S_ovbsb  S_ovbsb_1255_1 = {&var1068,&var87,&internal1_m1255_tx};
_S_ovbsb  S_ovbsb_1248_1 = {&var1072,&var88,&internal1_m1248_tx};
_S_ovbsb  S_ovbsb_1246_1 = {&var1069,&var89,&internal1_m1246_tx};
_S_ovbsb  S_ovbsb_1244_1 = {&var1070,&var90,&internal1_m1244_tx};
_S_ovbsb  S_ovbsb_1242_1 = {&var1071,&var91,&internal1_m1242_tx};
_S_ovbsb  S_ovbsb_1285_1 = {&var1751,&var92,&internal1_m1285_tx};
_S_ovbsb  S_ovbsb_1292_1 = {&var1752,&var93,&internal1_m1292_tx};
_S_ovbsb  S_ovbsb_1297_1 = {&var1765,&var94,&internal1_m1297_tx};
_S_ovbsb  S_ovbsb_1303_1 = {&var1221,&var95,&internal1_m1303_tx};
_S_ovbsb  S_ovbsb_1263_1 = {&var1065,&var96,&internal1_m1263_tx};
_S_ovbsb  S_ovbsb_1284_1 = {&var1759,&var97,&internal1_m1284_tx};
_S_ovbsb  S_ovbsb_1298_1 = {&var1760,&var98,&internal1_m1298_tx};
_S_ovbsb  S_ovbsb_480_1 = {&var1187,&var99,&internal1_m480_tx};
_S_ovbsb  S_ovbsb_474_1 = {&var1186,&var100,&internal1_m474_tx};
_S_ovbsb  S_ovbsb_476_1 = {&var1185,&var101,&internal1_m476_tx};
_S_ovbsb  S_ovbsb_478_1 = {&var1184,&var102,&internal1_m478_tx};
_S_ovbsb  S_ovbsb_485_1 = {&var618,&var103,&internal1_m485_tx};
_S_ovbsb  S_ovbsb_439_1 = {&var1842,&var104,&internal1_m439_tx};
_S_ovbsb  S_ovbsb_437_1 = {&var1843,&var105,&internal1_m437_tx};
_S_ovbsb  S_ovbsb_438_1 = {&var1841,&var106,&internal1_m438_tx};
_S_ovbsb  S_ovbsb_431_1 = {&var1840,&var107,&internal1_m431_tx};
_S_ovbsb  S_ovbsb_893_1 = {&var1815,&var108,&internal1_m893_tx};
_S_ovbsb  S_ovbsb_892_1 = {&var1814,&var109,&internal1_m892_tx};
_S_ovbsb  S_ovbsb_891_1 = {&var1816,&var110,&internal1_m891_tx};
_S_ovbsb  S_ovbsb_887_1 = {&var1813,&var111,&internal1_m887_tx};
_S_ovbsb  S_ovbsb_1349_1 = {&var1796,&var112,&internal1_m1349_tx};
_S_ovbsb  S_ovbsb_1348_1 = {&var1797,&var113,&internal1_m1348_tx};
_S_ovbsb  S_ovbsb_1347_1 = {&var1795,&var114,&internal1_m1347_tx};
_S_ovbsb  S_ovbsb_1560_1 = {&var888,&var115,&internal1_m1560_tx};
_S_ovbsb  S_ovbsb_1573_1 = {&var881,&var116,&internal1_m1573_tx};
_S_ovbsb  S_ovbsb_1572_1 = {&var882,&var117,&internal1_m1572_tx};
_S_ovbsb  S_ovbsb_1571_1 = {&var885,&var118,&internal1_m1571_tx};
_S_ovbsb  S_ovbsb_1562_1 = {&var1156,&var119,&internal1_m1562_tx};
_S_ovbsb  S_ovbsb_2300_1 = {&var382,&var120,&internal1_m2300_tx};
_S_ovbsb  S_ovbsb_2283_1 = {&var400,&var121,&internal1_m2283_tx};
_S_ovbsb  S_ovbsb_2260_1 = {&var395,&var122,&internal1_m2260_tx};
_S_ovbsb  S_ovbsb_1570_1 = {&var886,&var123,&internal1_m1570_tx};
_S_ovbsb  S_ovbsb_1550_1 = {&var890,&var124,&internal1_m1550_tx};
_S_ovbsb  S_ovbsb_1549_1 = {&var891,&var125,&internal1_m1549_tx};
_S_ovbsb  S_ovbsb_1547_1 = {&var892,&var126,&internal1_m1547_tx};
_S_ovbsb  S_ovbsb_1569_1 = {&var887,&var127,&internal1_m1569_tx};
_S_ovbsb  S_ovbsb_1535_1 = {&var896,&var128,&internal1_m1535_tx};
_S_ovbsb  S_ovbsb_1537_1 = {&var895,&var129,&internal1_m1537_tx};
_S_ovbsb  S_ovbsb_1534_1 = {&var897,&var130,&internal1_m1534_tx};
_S_ovbsb  S_ovbsb_1507_1 = {&var1548,&var131,&internal1_m1507_tx};
_S_ovbsb  S_ovbsb_1506_1 = {&var1547,&var132,&internal1_m1506_tx};
_S_ovbsb  S_ovbsb_1516_1 = {&var1553,&var133,&internal1_m1516_tx};
_S_ovbsb  S_ovbsb_1519_1 = {&var1228,&var134,&internal1_m1519_tx};
_S_ovbsb  S_ovbsb_986_1 = {&var921,&var135,&internal1_m986_tx};
_S_ovbsb  S_ovbsb_989_1 = {&var920,&var136,&internal1_m989_tx};
_S_ovbsb  S_ovbsb_2251_1 = {&var589,&var137,&internal1_m2251_tx};
_S_ovbsb  S_ovbsb_979_1 = {&var1165,&var138,&internal1_m979_tx};
_S_ovbsb  S_ovbsb_977_1 = {&var1166,&var139,&internal1_m977_tx};
_S_ovbsb  S_ovbsb_985_1 = {&var922,&var140,&internal1_m985_tx};
_S_ovbsb  S_ovbsb_969_1 = {&var926,&var141,&internal1_m969_tx};
_S_ovbsb  S_ovbsb_967_1 = {&var925,&var142,&internal1_m967_tx};
_S_ovbsb  S_ovbsb_963_1 = {&var924,&var143,&internal1_m963_tx};
_S_ovbsb  S_ovbsb_984_1 = {&var923,&var144,&internal1_m984_tx};
_S_ovbsb  S_ovbsb_949_1 = {&var930,&var145,&internal1_m949_tx};
_S_ovbsb  S_ovbsb_950_1 = {&var929,&var146,&internal1_m950_tx};
_S_ovbsb  S_ovbsb_952_1 = {&var928,&var147,&internal1_m952_tx};
_S_ovbsb  S_ovbsb_637_1 = {&var972,&var148,&internal1_m637_tx};
_S_ovbsb  S_ovbsb_640_1 = {&var1141,&var149,&internal1_m640_tx};
_S_ovbsb  S_ovbsb_639_1 = {&var1140,&var150,&internal1_m639_tx};
_S_ovbsb  S_ovbsb_628_1 = {&var473,&var151,&internal1_m628_tx};
_S_ovbsb  S_ovbsb_626_1 = {&var1160,&var152,&internal1_m626_tx};
_S_ovbsb  S_ovbsb_622_1 = {&var1161,&var153,&internal1_m622_tx};
_S_ovbsb  S_ovbsb_635_1 = {&var970,&var154,&internal1_m635_tx};
_S_ovbsb  S_ovbsb_612_1 = {&var974,&var155,&internal1_m612_tx};
_S_ovbsb  S_ovbsb_611_1 = {&var975,&var156,&internal1_m611_tx};
_S_ovbsb  S_ovbsb_607_1 = {&var978,&var157,&internal1_m607_tx};
_S_ovbsb  S_ovbsb_638_1 = {&var971,&var158,&internal1_m638_tx};
_S_ovbsb  S_ovbsb_595_1 = {&var976,&var159,&internal1_m595_tx};
_S_ovbsb  S_ovbsb_594_1 = {&var982,&var160,&internal1_m594_tx};
_S_ovbsb  S_ovbsb_597_1 = {&var983,&var161,&internal1_m597_tx};
_S_ovbsb  S_ovbsb_574_1 = {&var1608,&var162,&internal1_m574_tx};
_S_ovbsb  S_ovbsb_575_1 = {&var1609,&var163,&internal1_m575_tx};
_S_ovbsb  S_ovbsb_576_1 = {&var1614,&var164,&internal1_m576_tx};
_S_ovbsb  S_ovbsb_581_1 = {&var985,&var165,&internal1_m581_tx};
_S_ovbsb  S_ovbsb_2313_1 = {&var1501,&var166,&internal1_m2313_tx};
_S_ovbsb  S_ovbsb_2314_1 = {&var1503,&var167,&internal1_m2314_tx};
_S_ovbsb  S_ovbsb_2315_1 = {&var1502,&var168,&internal1_m2315_tx};
_S_ovbsb  S_ovbsb_1792_1 = {&var749,&var169,&internal1_m1792_tx};
_S_ovbsb  S_ovbsb_1791_1 = {&var750,&var170,&internal1_m1791_tx};
_S_ovbsb  S_ovbsb_1786_1 = {&var752,&var171,&internal1_m1786_tx};
_S_ovbsb  S_ovbsb_1777_1 = {&var753,&var172,&internal1_m1777_tx};
_S_ovbsb  S_ovbsb_1775_1 = {&var754,&var173,&internal1_m1775_tx};
_S_ovbsb  S_ovbsb_1773_1 = {&var755,&var174,&internal1_m1773_tx};
_S_ovbsb  S_ovbsb_1772_1 = {&var756,&var175,&internal1_m1772_tx};
_S_ovbsb  S_ovbsb_1813_1 = {&var1740,&var176,&internal1_m1813_tx};
_S_ovbsb  S_ovbsb_1821_1 = {&var1741,&var177,&internal1_m1821_tx};
_S_ovbsb  S_ovbsb_1828_1 = {&var1748,&var178,&internal1_m1828_tx};
_S_ovbsb  S_ovbsb_1829_1 = {&var1220,&var179,&internal1_m1829_tx};
_S_ovbsb  S_ovbsb_1819_1 = {&var1743,&var180,&internal1_m1819_tx};
_S_ovbsb  S_ovbsb_1794_1 = {&var748,&var181,&internal1_m1794_tx};
_S_ovbsb  S_ovbsb_1808_1 = {&var1742,&var182,&internal1_m1808_tx};
_S_ovbsb  S_ovbsb_457_1 = {&var1189,&var183,&internal1_m457_tx};
_S_ovbsb  S_ovbsb_448_1 = {&var1175,&var184,&internal1_m448_tx};
_S_ovbsb  S_ovbsb_449_1 = {&var394,&var185,&internal1_m449_tx};
_S_ovbsb  S_ovbsb_451_1 = {&var1190,&var186,&internal1_m451_tx};
_S_ovbsb  S_ovbsb_465_1 = {&var1188,&var187,&internal1_m465_tx};
_S_ovbsb  S_ovbsb_415_1 = {&var1849,&var188,&internal1_m415_tx};
_S_ovbsb  S_ovbsb_412_1 = {&var1851,&var189,&internal1_m412_tx};
_S_ovbsb  S_ovbsb_411_1 = {&var1850,&var190,&internal1_m411_tx};
_S_ovbsb  S_ovbsb_410_1 = {&var1852,&var191,&internal1_m410_tx};
_S_ovbsb  S_ovbsb_870_1 = {&var1822,&var192,&internal1_m870_tx};
_S_ovbsb  S_ovbsb_866_1 = {&var1824,&var193,&internal1_m866_tx};
_S_ovbsb  S_ovbsb_865_1 = {&var1823,&var194,&internal1_m865_tx};
_S_ovbsb  S_ovbsb_864_1 = {&var1825,&var195,&internal1_m864_tx};
_S_ovbsb  S_ovbsb_1330_1 = {&var1804,&var196,&internal1_m1330_tx};
_S_ovbsb  S_ovbsb_1327_1 = {&var1805,&var197,&internal1_m1327_tx};
_S_ovbsb  S_ovbsb_1326_1 = {&var1806,&var198,&internal1_m1326_tx};
_S_ovbsb  S_ovbsb_1087_1 = {&var649,&var199,&internal1_m1087_tx};
_S_ovbsb  S_ovbsb_2272_1 = {&var401,&var200,&internal1_m2272_tx};
_S_ovbsb  S_ovbsb_1098_1 = {&var902,&var201,&internal1_m1098_tx};
_S_ovbsb  S_ovbsb_1100_1 = {&var900,&var202,&internal1_m1100_tx};
_S_ovbsb  S_ovbsb_1099_1 = {&var899,&var203,&internal1_m1099_tx};
_S_ovbsb  S_ovbsb_2266_1 = {&var396,&var204,&internal1_m2266_tx};
_S_ovbsb  S_ovbsb_1089_1 = {&var1158,&var205,&internal1_m1089_tx};
_S_ovbsb  S_ovbsb_2271_1 = {&var385,&var206,&internal1_m2271_tx};
_S_ovbsb  S_ovbsb_1097_1 = {&var903,&var207,&internal1_m1097_tx};
_S_ovbsb  S_ovbsb_1079_1 = {&var907,&var208,&internal1_m1079_tx};
_S_ovbsb  S_ovbsb_1078_1 = {&var911,&var209,&internal1_m1078_tx};
_S_ovbsb  S_ovbsb_1074_1 = {&var905,&var210,&internal1_m1074_tx};
_S_ovbsb  S_ovbsb_1096_1 = {&var904,&var211,&internal1_m1096_tx};
_S_ovbsb  S_ovbsb_1064_1 = {&var910,&var212,&internal1_m1064_tx};
_S_ovbsb  S_ovbsb_1062_1 = {&var912,&var213,&internal1_m1062_tx};
_S_ovbsb  S_ovbsb_1061_1 = {&var913,&var214,&internal1_m1061_tx};
_S_ovbsb  S_ovbsb_1040_1 = {&var1579,&var215,&internal1_m1040_tx};
_S_ovbsb  S_ovbsb_1039_1 = {&var1580,&var216,&internal1_m1039_tx};
_S_ovbsb  S_ovbsb_1029_1 = {&var1585,&var217,&internal1_m1029_tx};
_S_ovbsb  S_ovbsb_1046_1 = {&var1229,&var218,&internal1_m1046_tx};
_S_ovbsb  S_ovbsb_1465_1 = {&var859,&var219,&internal1_m1465_tx};
_S_ovbsb  S_ovbsb_1464_1 = {&var860,&var220,&internal1_m1464_tx};
_S_ovbsb  S_ovbsb_2218_1 = {&var590,&var221,&internal1_m2218_tx};
_S_ovbsb  S_ovbsb_1455_1 = {&var863,&var222,&internal1_m1455_tx};
_S_ovbsb  S_ovbsb_1456_1 = {&var864,&var223,&internal1_m1456_tx};
_S_ovbsb  S_ovbsb_1463_1 = {&var861,&var224,&internal1_m1463_tx};
_S_ovbsb  S_ovbsb_1446_1 = {&var869,&var225,&internal1_m1446_tx};
_S_ovbsb  S_ovbsb_1445_1 = {&var867,&var226,&internal1_m1445_tx};
_S_ovbsb  S_ovbsb_1441_1 = {&var865,&var227,&internal1_m1441_tx};
_S_ovbsb  S_ovbsb_1462_1 = {&var862,&var228,&internal1_m1462_tx};
_S_ovbsb  S_ovbsb_1428_1 = {&var870,&var229,&internal1_m1428_tx};
_S_ovbsb  S_ovbsb_1426_1 = {&var868,&var230,&internal1_m1426_tx};
_S_ovbsb  S_ovbsb_1435_1 = {&var866,&var231,&internal1_m1435_tx};
_S_ovbsb  S_ovbsb_255_1 = {&var474,&var232,&internal1_m255_tx};
_S_ovbsb  S_ovbsb_270_1 = {&var948,&var233,&internal1_m270_tx};
_S_ovbsb  S_ovbsb_278_1 = {&var947,&var234,&internal1_m278_tx};
_S_ovbsb  S_ovbsb_277_1 = {&var949,&var235,&internal1_m277_tx};
_S_ovbsb  S_ovbsb_261_1 = {&var1163,&var236,&internal1_m261_tx};
_S_ovbsb  S_ovbsb_258_1 = {&var1164,&var237,&internal1_m258_tx};
_S_ovbsb  S_ovbsb_274_1 = {&var945,&var238,&internal1_m274_tx};
_S_ovbsb  S_ovbsb_246_1 = {&var954,&var239,&internal1_m246_tx};
_S_ovbsb  S_ovbsb_245_1 = {&var952,&var240,&internal1_m245_tx};
_S_ovbsb  S_ovbsb_241_1 = {&var951,&var241,&internal1_m241_tx};
_S_ovbsb  S_ovbsb_273_1 = {&var950,&var242,&internal1_m273_tx};
_S_ovbsb  S_ovbsb_230_1 = {&var958,&var243,&internal1_m230_tx};
_S_ovbsb  S_ovbsb_232_1 = {&var956,&var244,&internal1_m232_tx};
_S_ovbsb  S_ovbsb_228_1 = {&var957,&var245,&internal1_m228_tx};
_S_ovbsb  S_ovbsb_204_1 = {&var1645,&var246,&internal1_m204_tx};
_S_ovbsb  S_ovbsb_203_1 = {&var1646,&var247,&internal1_m203_tx};
_S_ovbsb  S_ovbsb_202_1 = {&var1647,&var248,&internal1_m202_tx};
_S_ovbsb  S_ovbsb_210_1 = {&var965,&var249,&internal1_m210_tx};
_S_ovbsb  S_ovbsb_1408_1 = {&var1735,&var250,&internal1_m1408_tx};
_S_ovbsb  S_ovbsb_1390_1 = {&var1730,&var251,&internal1_m1390_tx};
_S_ovbsb  S_ovbsb_1393_1 = {&var1729,&var252,&internal1_m1393_tx};
_S_ovbsb  S_ovbsb_1412_1 = {&var1230,&var253,&internal1_m1412_tx};
_S_ovbsb  S_ovbsb_929_1 = {&var1692,&var254,&internal1_m929_tx};
_S_ovbsb  S_ovbsb_934_1 = {&var938,&var255,&internal1_m934_tx};
_S_ovbsb  S_ovbsb_924_1 = {&var937,&var256,&internal1_m924_tx};
_S_ovbsb  S_ovbsb_925_1 = {&var936,&var257,&internal1_m925_tx};
_S_or3  S_or3_2531_1 = {&var261,&var260,&var259,&var258};
_S_or2  S_or2_2535_1 = {&R0DEB3LDU,&R0DEB4LDU,&var259};
_S_or2  S_or2_2529_1 = {&R0DEB1LDU,&R0DEB2LDU,&var260};
_S_diagndev  S_diagndev_2523_1 = {array_m2523_x_1,&iRM_14_,&var261,&var262};
_S_or2  S_or2_1914_1 = {&var493,&var311,&var263};
_S_and2  S_and2_1904_1 = {&var549,&var1444,&var264};
_S_rs  S_rs_1913_1 = {&var263,&var264,&var265,&vainSBool,&internal1_m1913_q0};
_S_or2  S_or2_1908_1 = {&var549,&var496,&var266};
_S_or2  S_or2_1851_1 = {&var1494,&var549,&var267};
_S_or2  S_or2_1879_1 = {&var548,&var311,&var268};
_S_or2  S_or2_1881_1 = {&var381,&var311,&var269};
_S_or2  S_or2_2362_1 = {&var493,&var307,&var270};
_S_or2  S_or2_2360_1 = {&var307,&var500,&var271};
_S_or2  S_or2_2358_1 = {&var320,&var307,&var272};
_S_and2  S_and2_2341_1 = {&var1441,&var547,&var273};
_S_or2  S_or2_2356_1 = {&var547,&var307,&var274};
_S_noto  S_noto_2364_1 = {&B3IS11LDU,&var275};
_S_or2  S_or2_2391_1 = {&var311,&var500,&var276};
_S_and2  S_and2_2371_1 = {&var1441,&var548,&var277};
_S_noto  S_noto_2395_1 = {&A3IS11LDU,&var278};
_S_or2  S_or2_2393_1 = {&var493,&var311,&var279};
_S_or2  S_or2_2389_1 = {&var311,&var321,&var280};
_S_or2  S_or2_2387_1 = {&var311,&var548,&var281};
_S_or2  S_or2_1859_1 = {&var493,&var311,&var282};
_S_or2  S_or2_1863_1 = {&var493,&var307,&var283};
_S_or2  S_or2_1854_1 = {&var549,&var1494,&var284};
_S_or2  S_or2_1889_1 = {&var307,&var380,&var285};
_S_or2  S_or2_1887_1 = {&var547,&var307,&var286};
_S_or2  S_or2_1930_1 = {&var500,&var307,&var287};
_S_or2  S_or2_1927_1 = {&var500,&var311,&var288};
_S_or2  S_or2_1959_1 = {&var506,&var307,&var289};
_S_or2  S_or2_1956_1 = {&var506,&var311,&var290};
_S_or2  S_or2_1916_1 = {&var493,&var307,&var291};
_S_or2  S_or2_1883_1 = {&var493,&var311,&var292};
_S_or2  S_or2_1891_1 = {&var493,&var307,&var293};
_S_or3  S_or3_2352_1 = {&var500,&var547,&var307,&var294};
_S_or3  S_or3_2354_1 = {&var550,&var547,&var307,&var295};
_S_or3  S_or3_2385_1 = {&var311,&var551,&var548,&var296};
_S_or3  S_or3_2383_1 = {&var500,&var311,&var548,&var297};
_S_or3  S_or3_2350_1 = {&var547,&var493,&var307,&var298};
_S_or3  S_or3_2381_1 = {&var493,&var548,&var311,&var299};
_S_or3  S_or3_1857_1 = {&var493,&var548,&var311,&var300};
_S_or3  S_or3_1861_1 = {&var547,&var493,&var307,&var301};
_S_or3  S_or3_1877_1 = {&var493,&var548,&var311,&var302};
_S_or3  S_or3_1885_1 = {&var493,&var547,&var307,&var303};
_S_or3  S_or3_1912_1 = {&var493,&var549,&var307,&var304};
_S_or3  S_or3_1910_1 = {&var493,&var311,&var549,&var305};
_S_or3  S_or3_1958_1 = {&var307,&var547,&var506,&var306};
_S_noto  S_noto_1953_1 = {&var1147,&var307};
_S_or3  S_or3_1929_1 = {&var307,&var500,&var547,&var308};
_S_or3  S_or3_1926_1 = {&var500,&var311,&var548,&var309};
_S_or3  S_or3_1955_1 = {&var506,&var311,&var548,&var310};
_S_noto  S_noto_1946_1 = {&var1146,&var311};
_S_regch  S_regch_133_1 = {&R0MW12IP1,&var1136,&var312};
_S_or2  S_or2_136_1 = {&var314,&var312,&var313};
_S_or2  S_or2_135_1 = {&R0VZ71LZ1,&R0VZ71LZ2,&var314};
_S_and3  S_and3_1595_1 = {&R0MD11LP2,&var1195,&var318,&var315};
_S_and2  S_and2_817_1 = {&R4MD21LP2,&var318,&var316};
_S_and2  S_and2_815_1 = {&R4MD11LP2,&var318,&var317};
_S_noto  S_noto_114_1 = {&var1871,&var318};
_S_and2  S_and2_112_1 = {&R0MD11LP1,&var318,&var319};
_S_noto  S_noto_2365_1 = {&B3IS22LDU,&var320};
_S_noto  S_noto_2396_1 = {&A3IS22LDU,&var321};
_S_and2  S_and2_2281_1 = {&var713,&var1423,&var322};
_S_or3  S_or3_2274_1 = {&var712,&var420,&var362,&var323};
_S_and2  S_and2_2263_1 = {&var709,&var1423,&var324};
_S_or3  S_or3_2259_1 = {&var420,&var710,&var345,&var325};
_S_or2  S_or2_1675_1 = {&var1251,&var1441,&var326};
_S_or2  S_or2_1640_1 = {&var1248,&var1441,&var327};
_S_rs  S_rs_2355_1 = {&var274,&var331,&var328,&vainSBool,&internal1_m2355_q0};
_S_rs  S_rs_2339_1 = {&var275,&var350,&var329,&vainSBool,&internal1_m2339_q0};
_S_noto  S_noto_2363_1 = {&var1975,&var330};
_S_and2  S_and2_2346_1 = {&var330,&var329,&var331};
_S_rs  S_rs_2386_1 = {&var281,&var334,&var332,&vainSBool,&internal1_m2386_q0};
_S_noto  S_noto_2394_1 = {&var1978,&var333};
_S_and2  S_and2_2377_1 = {&var335,&var333,&var334};
_S_rs  S_rs_2370_1 = {&var278,&var368,&var335,&vainSBool,&internal1_m2370_q0};
_S_and4  S_and4_1541_1 = {&var1195,&var1441,&var511,&var1486,&var336};
_S_and4  S_and4_1068_1 = {&var1195,&var1441,&var511,&var1486,&var337};
_S_rs  S_rs_2361_1 = {&var270,&var343,&var338,&vainSBool,&internal1_m2361_q0};
_S_or4  S_or4_1471_1 = {&var831,&var533,&var1234,&var345,&var339};
_S_or4  S_or4_1480_1 = {&var409,&var536,&var1007,&var351,&var340};
_S_orn  S_orn_898_1 = {array_m898_x_1,&iRM_6_,&var341};
_S_or3  S_or3_910_1 = {&var1026,&var1437,&var354,&var342};
_S_and2  S_and2_2348_1 = {&var500,&var344,&var343};
_S_rs  S_rs_2342_1 = {&var270,&var346,&var344,&vainSBool,&internal1_m2342_q0};
_S_rs  S_rs_2359_1 = {&var271,&var346,&var345,&vainSBool,&internal1_m2359_q0};
_S_and2  S_and2_2347_1 = {&var347,&var320,&var346};
_S_rs  S_rs_2340_1 = {&var271,&var273,&var347,&vainSBool,&internal1_m2340_q0};
_S_rs  S_rs_2338_1 = {&var330,&var352,&var348,&vainSBool,&internal1_m2338_q0};
_S_rs  S_rs_2337_1 = {&var294,&var353,&var349,&vainSBool,&internal1_m2337_q0};
_S_and2  S_and2_2345_1 = {&var500,&var348,&var350};
_S_rs  S_rs_2351_1 = {&var294,&var352,&var351,&vainSBool,&internal1_m2351_q0};
_S_and2  S_and2_2344_1 = {&var349,&var493,&var352};
_S_and2  S_and2_2343_1 = {&var550,&var1441,&var353};
_S_rs  S_rs_2349_1 = {&var298,&var353,&var354,&vainSBool,&internal1_m2349_q0};
_S_rs  S_rs_2357_1 = {&var272,&var273,&var355,&vainSBool,&internal1_m2357_q0};
_S_rs  S_rs_2353_1 = {&var295,&var350,&var356,&vainSBool,&internal1_m2353_q0};
_S_orn  S_orn_1359_1 = {array_m1359_x_1,&iRM_6_,&var357};
_S_rs  S_rs_2392_1 = {&var279,&var359,&var358,&vainSBool,&internal1_m2392_q0};
_S_and2  S_and2_2379_1 = {&var500,&var360,&var359};
_S_rs  S_rs_2373_1 = {&var279,&var363,&var360,&vainSBool,&internal1_m2373_q0};
_S_or4  S_or4_993_1 = {&var830,&var537,&var1234,&var362,&var361};
_S_rs  S_rs_2390_1 = {&var276,&var363,&var362,&vainSBool,&internal1_m2390_q0};
_S_and2  S_and2_2378_1 = {&var364,&var321,&var363};
_S_rs  S_rs_2372_1 = {&var276,&var277,&var364,&vainSBool,&internal1_m2372_q0};
_S_rs  S_rs_2369_1 = {&var333,&var371,&var365,&vainSBool,&internal1_m2369_q0};
_S_or4  S_or4_1002_1 = {&var1434,&var409,&var1017,&var369,&var366};
_S_rs  S_rs_2368_1 = {&var297,&var372,&var367,&vainSBool,&internal1_m2368_q0};
_S_and2  S_and2_2376_1 = {&var500,&var365,&var368};
_S_rs  S_rs_2382_1 = {&var297,&var371,&var369,&vainSBool,&internal1_m2382_q0};
_S_or3  S_or3_1371_1 = {&var1025,&var1439,&var373,&var370};
_S_and2  S_and2_2375_1 = {&var367,&var493,&var371};
_S_and2  S_and2_2374_1 = {&var551,&var1441,&var372};
_S_rs  S_rs_2380_1 = {&var299,&var372,&var373,&vainSBool,&internal1_m2380_q0};
_S_or2  S_or2_2241_1 = {&var411,&var1270,&var374};
_S_ovbs  S_ovbs_2243_1 = {&var469,&fRM_2_0,&var375,&internal1_m2243_tx};
_S_or2  S_or2_2244_1 = {&var1450,&var375,&var376};
_S_ovbs  S_ovbs_2222_1 = {&var470,&fRM_2_0,&var377,&internal1_m2222_tx};
_S_or2  S_or2_2220_1 = {&var412,&var1271,&var378};
_S_or2  S_or2_2223_1 = {&var1470,&var377,&var379};
_S_noto  S_noto_1893_1 = {&B2IS21LDU,&var380};
_S_noto  S_noto_1892_1 = {&A2IS21LDU,&var381};
_S_and2  S_and2_2301_1 = {&var1975,&var714,&var382};
_S_or5  S_or5_2304_1 = {&var888,&var1880,&var26,&var355,&var382,&var383};
_S_or5  S_or5_2303_1 = {&var649,&var1432,&var27,&var1880,&var385,&var384};
_S_and2  S_and2_2276_1 = {&var1978,&var715,&var385};
_S_nocnm  S_nocnm_1937_1 = {&R5IS21LDU,&R5IS11LDU,&var386,&var387,&var388,&internal1_m1937_Pv0,&internal1_m1937_Zv0,&internal1_m1937_MyFirstEnterFlag,&bFirstEnterFlag};
_S_nocnm  S_nocnm_1934_1 = {&R3IS11LDU,&R3IS21LDU,&var389,&var390,&var391,&internal1_m1934_Pv0,&internal1_m1934_Zv0,&internal1_m1934_MyFirstEnterFlag,&bFirstEnterFlag};
_S_or5  S_or5_2190_1 = {&var1230,&var938,&C2MD31LP1,&var1229,&var1228,&var392};
_S_or4  S_or4_2165_1 = {&C1MD31LP2,&C1MD31LP1,&var965,&var985,&var393};
_S_and3  S_and3_454_1 = {&B8IS22LDU,&B8IS21LDU,&var1853,&var394};
_S_and2  S_and2_2261_1 = {&var708,&var420,&var395};
_S_and2  S_and2_2267_1 = {&var711,&var420,&var396};
_S_or4  S_or4_1109_1 = {&var1559,&var900,&var899,&var902,&var397};
_S_or4  S_or4_1583_1 = {&var1527,&var882,&var881,&var885,&var398};
_S_and2  S_and2_2305_1 = {&var639,&var1423,&var399};
_S_and2  S_and2_2290_1 = {&var714,&var1880,&var400};
_S_and2  S_and2_2277_1 = {&var715,&var1880,&var401};
_S_or2  S_or2_618_1 = {&B1VP41LZ2,&B1VP41LZ1,&var402};
_S_or2  S_or2_252_1 = {&A1VP41LZ2,&A1VP41LZ1,&var403};
_S_or2  S_or2_1276_1 = {&B8IS22LDU,&B8IS21LDU,&var404};
_S_or2  S_or2_1270_1 = {&B8IS11LDU,&B8IS12LDU,&var405};
_S_or2  S_or2_380_1 = {&R4IS11LDU,&R4IS12LDU,&var406};
_S_or2  S_or2_393_1 = {&R4IS21LDU,&R4IS22LDU,&var407};
_S_noto  S_noto_2421_1 = {&var1880,&var408};
_S_zzfs  S_zzfs_2410_1 = {&var426,&fRM_0_5,&var409,&internal1_m2410_tx,&internal1_m2410_y0};
_S_or2  S_or2_2444_1 = {&var601,&var1239,&var410};
_S_andn  S_andn_666_1 = {array_m666_x_1,&iRM_6_,&var411};
_S_andn  S_andn_665_1 = {array_m665_x_1,&iRM_6_,&var412};
_S_or2  S_or2_2458_1 = {&var915,&var880,&var413};
_S_noto  S_noto_2406_1 = {&var1269,&var414};
_S_noto  S_noto_2405_1 = {&var1266,&var415};
_S_zpfs  S_zpfs_2414_1 = {&var414,&fRM_30_0,&var416,&internal1_m2414_tx,&internal1_m2414_y0};
_S_noto  S_noto_2419_1 = {&var416,&var417};
_S_zpfs  S_zpfs_2413_1 = {&var415,&fRM_30_0,&var418,&internal1_m2413_tx,&internal1_m2413_y0};
_S_noto  S_noto_2418_1 = {&var418,&var419};
_S_and3  S_and3_2412_1 = {&var458,&var439,&lRM_1_,&var420};
_S_and2  S_and2_1021_1 = {&var1585,&var422,&var421};
_S_noto  S_noto_1009_1 = {&var409,&var422};
_S_and2  S_and2_1497_1 = {&var1553,&var424,&var423};
_S_noto  S_noto_1494_1 = {&var409,&var424};
_S_or2  S_or2_2454_1 = {&var435,&var436,&var425};
_S_and2  S_and2_2409_1 = {&var427,&var420,&var426};
_S_abs_subf  S_abs_subf_2401_1 = {&var1991,&var459,&fEM_A3UC08RDU,&vainSFloat,&var427};
_S_and2  S_and2_2456_1 = {&var420,&var435,&var428};
_S_or4  S_or4_2191_1 = {&var392,&var1043,&var1153,&var428,&var429};
_S_noto  S_noto_2457_1 = {&var413,&var430};
_S_or2  S_or2_2435_1 = {&var452,&var463,&var431};
_S_inf  S_inf_2430_1 = {&var461,array_m2430_a_1,array_m2430_b_1,&iRM_6_,&var432,&vainSInt};
_S_or3  S_or3_2462_1 = {&var448,&var455,&var456,&var433};
_S_noto  S_noto_2461_1 = {&var433,&var434};
_S_noto  S_noto_2455_1 = {&var458,&var435};
_S_ovbs  S_ovbs_2450_1 = {&var438,&fRM_15_0,&var436,&internal1_m2450_tx};
_S_zpfs  S_zpfs_2448_1 = {&var439,&fRM_10_0,&var437,&internal1_m2448_tx,&internal1_m2448_y0};
_S_and2  S_and2_2449_1 = {&var437,&R0MW17LP1,&var438};
_S_rs  S_rs_2453_1 = {&var425,&R0MW17LP1,&var439,&vainSBool,&internal1_m2453_q0};
_S_rs  S_rs_2420_1 = {&var452,&var420,&var440,&vainSBool,&internal1_m2420_q0};
_S_and3  S_and3_2427_1 = {&var454,&var408,&var440,&var441};
_S_ml  S_ml_1477_1 = {&var459,&var561,&var409,&var442};
_S_ml  S_ml_996_1 = {&var459,&var565,&var409,&var443};
_S_and2  S_and2_2478_1 = {&var420,&var578,&var444};
_S_noto  S_noto_2440_1 = {&var410,&var445};
_S_noto  S_noto_2425_1 = {&var1524,&var446};
_S_sr  S_sr_2441_1 = {array_m2441_x_1,&iRM_4_,&var447};
_S_and2  S_and2_2479_1 = {&var449,&var420,&var448};
_S_abs_subf  S_abs_subf_2475_1 = {&B3MC01RP1,&A3MC01RP1,&fRM_0_01,&vainSFloat,&var449};
_S_fsumo  S_fsumo_86_1 = {&var1215,&fEM_R0UN11RDU,&var450};
_S_or3  S_or3_134_1 = {&var393,&var313,&var431,&var451};
_S_ovbs  S_ovbs_2428_1 = {&var441,&fRM_1_0,&var452,&internal1_m2428_tx};
_S_noto  S_noto_2434_1 = {&var431,&var453};
_S_rs  S_rs_2426_1 = {&var452,&var1880,&var454,&vainSBool,&internal1_m2426_q0};
_S_and2  S_and2_2476_1 = {&var463,&var420,&var455};
_S_and2  S_and2_2473_1 = {&var457,&var420,&var456};
_S_bol  S_bol_2465_1 = {&fEM_R0UN09RDU,&var45,&var457};
_S_andn  S_andn_2433_1 = {array_m2433_x_1,&iRM_14_,&var458};
_S_irm  S_irm_2408_1 = {&var1215,&var1213,&B3MC01RP1,&var1991,&var45,&var447,&var420,&var1239,&fEM_R0UN12RDU,&fEM_R0UN13RDU,&fEM_R0UN14RDU,&fEM_R0UT20RDU,&var432,&fEM_R0UN15RDU,&fEM_R0UN25RDU,&fEM_R0UN16RDU,&fEM_R0UN17RDU,&fEM_R0UN18RDU,&fEM_R0UN19RDU,&fEM_R0UN27RDU,&fEM_R0UN26RDU,&fEM_R0UN24RDU,&var459,&var460,&var461,&var462,&var463,&var464,&var465,&var466,&internal1_m2408_fVf0,&internal1_m2408_fRsg,&internal1_m2408_fRct,&internal1_m2408_fVfMin,&internal1_m2408_fStw0,&internal1_m2408_fMaxDk,&internal1_m2408_fkizm,&internal1_m2408_fwt0,&internal1_m2408_fwz0,&internal1_m2408_ftf0,&internal1_m2408_fTk0,&internal1_m2408_FlPar,&internal1_m2408_FlIzm,&internal1_m2408_FlCmp,&internal1_m2408_StabCoun,&internal1_m2408_ZerCoun,&internal1_m2408_SrCoun,&internal1_m2408_LastStage,&internal1_m2408_fef};
_S_noto  S_noto_2250_1 = {&var589,&var467};
_S_noto  S_noto_2219_1 = {&var590,&var468};
_S_and4  S_and4_2242_1 = {&var612,&var374,&var582,&var467,&var469};
_S_and4  S_and4_2221_1 = {&var613,&var378,&var582,&var468,&var470};
_S_zpfs  S_zpfs_2237_1 = {&var596,&fRM_210_0,&var471,&internal1_m2237_tx,&internal1_m2237_y0};
_S_zpfs  S_zpfs_2229_1 = {&var597,&fRM_210_0,&var472,&internal1_m2229_tx,&internal1_m2229_y0};
_S_and2  S_and2_621_1 = {&var1600,&var643,&var473};
_S_and2  S_and2_256_1 = {&var643,&var1633,&var474};
_S_noto  S_noto_1765_1 = {&var476,&var475};
_S_abs_subf  S_abs_subf_1755_1 = {&var1988,&var561,&fEM_A3UC07RDU,&vainSFloat,&var476};
_S_noto  S_noto_1746_1 = {&var478,&var477};
_S_abs_subf  S_abs_subf_1735_1 = {&var565,&var1991,&fEM_A3UC07RDU,&vainSFloat,&var478};
_S_noto  S_noto_1760_1 = {&var480,&var479};
_S_abs_subf  S_abs_subf_1754_1 = {&var569,&var2001,&fEM_A1UC07RDU,&vainSFloat,&var480};
_S_noto  S_noto_1740_1 = {&var482,&var481};
_S_abs_subf  S_abs_subf_1733_1 = {&var573,&var1979,&fEM_A1UC07RDU,&vainSFloat,&var482};
_S_bol  S_bol_1493_1 = {&var1988,&fEM_A3UC09RDU,&var483};
_S_bol  S_bol_1018_1 = {&var1991,&fEM_A3UC09RDU,&var484};
_S_noto  S_noto_2000_1 = {&var489,&var485};
_S_noto  S_noto_1989_1 = {&var487,&var486};
_S_and3  S_and3_1982_1 = {&var1147,&var488,&var1441,&var487};
_S_bol  S_bol_1974_1 = {&fRM_55_0,&var561,&var488};
_S_and3  S_and3_2001_1 = {&var490,&var1146,&var1441,&var489};
_S_bol  S_bol_2010_1 = {&fRM_55_0,&var565,&var490};
_S_and4  S_and4_45_1 = {&var1871,&var1145,&var1328,&var1423,&var491};
_S_noto  S_noto_1391_1 = {&var1195,&var492};
_S_and2  S_and2_1396_1 = {&var1700,&var1195,&var493};
_S_and2  S_and2_1392_1 = {&var1700,&var492,&var494};
_S_noto  S_noto_1337_1 = {&var1195,&var495};
_S_and2  S_and2_1344_1 = {&var1195,&var1774,&var496};
_S_and2  S_and2_1338_1 = {&var1774,&var495,&var497};
_S_noto  S_noto_1025_1 = {&var1195,&var498};
_S_and2  S_and2_1026_1 = {&var498,&var1556,&var499};
_S_and2  S_and2_1023_1 = {&var1556,&var1195,&var500};
_S_noto  S_noto_518_1 = {&var1195,&var501};
_S_and2  S_and2_519_1 = {&var501,&var1649,&var502};
_S_and2  S_and2_522_1 = {&var1649,&var1195,&var503};
_S_noto  S_noto_195_1 = {&var1195,&var504};
_S_and2  S_and2_196_1 = {&var504,&var1619,&var505};
_S_and2  S_and2_198_1 = {&var1195,&var1619,&var506};
_S_and2  S_and2_128_1 = {&var509,&var633,&var507};
_S_and2  S_and2_129_1 = {&var1195,&var633,&var508};
_S_noto  S_noto_123_1 = {&var1195,&var509};
_S_and2  S_and2_124_1 = {&var509,&var632,&var510};
_S_and2  S_and2_125_1 = {&var1195,&var632,&var511};
_S_and2  S_and2_1849_1 = {&var547,&var1445,&var512};
_S_and2  S_and2_1848_1 = {&var550,&var1445,&var513};
_S_and2  S_and2_1847_1 = {&var548,&var1445,&var514};
_S_and2  S_and2_1846_1 = {&var1445,&var551,&var515};
_S_and2  S_and2_1845_1 = {&var757,&var549,&var516};
_S_and2  S_and2_1844_1 = {&var757,&var552,&var517};
_S_and2  S_and2_1843_1 = {&var758,&var549,&var518};
_S_and2  S_and2_1842_1 = {&var758,&var552,&var519};
_S_and2  S_and2_1875_1 = {&var285,&var1404,&var520};
_S_and2  S_and2_1874_1 = {&var547,&var1446,&var521};
_S_and2  S_and2_1873_1 = {&var1405,&var493,&var522};
_S_and2  S_and2_1872_1 = {&var1446,&var550,&var523};
_S_and2  S_and2_1871_1 = {&var381,&var1406,&var524};
_S_and2  S_and2_1870_1 = {&var1446,&var548,&var525};
_S_and2  S_and2_1869_1 = {&var1407,&var493,&var526};
_S_and2  S_and2_1868_1 = {&var1446,&var551,&var527};
_S_and2  S_and2_1906_1 = {&var493,&var1408,&var528};
_S_and2  S_and2_1905_1 = {&var549,&var1444,&var529};
_S_and2  S_and2_1903_1 = {&var1409,&var496,&var530};
_S_and2  S_and2_1902_1 = {&var1410,&var496,&var531};
_S_and2  S_and2_1901_1 = {&var552,&var1444,&var532};
_S_rs  S_rs_1923_1 = {&var287,&var534,&var533,&vainSBool,&internal1_m1923_q0};
_S_and2  S_and2_1922_1 = {&var1442,&var547,&var534};
_S_and2  S_and2_1921_1 = {&var1442,&var550,&var535};
_S_rs  S_rs_1928_1 = {&var308,&var535,&var536,&vainSBool,&internal1_m1928_q0};
_S_rs  S_rs_1920_1 = {&var288,&var538,&var537,&vainSBool,&internal1_m1920_q0};
_S_and2  S_and2_1919_1 = {&var548,&var1442,&var538};
_S_and2  S_and2_1918_1 = {&var1442,&var551,&var539};
_S_and2  S_and2_1952_1 = {&var549,&var1873,&var540};
_S_rs  S_rs_1962_1 = {&var503,&var540,&var541,&vainSBool,&internal1_m1962_q0};
_S_and2  S_and2_1951_1 = {&var1873,&var552,&var542};
_S_and2  S_and2_1949_1 = {&var547,&var1430,&var543};
_S_and2  S_and2_1948_1 = {&var1430,&var550,&var544};
_S_and2  S_and2_1945_1 = {&var548,&var1430,&var545};
_S_and2  S_and2_1944_1 = {&var1430,&var551,&var546};
_S_and2  S_and2_1964_1 = {&var1147,&var549,&var547};
_S_and2  S_and2_1943_1 = {&var1146,&var549,&var548};
_S_and2  S_and2_1966_1 = {&var508,&var1486,&var549};
_S_and2  S_and2_1963_1 = {&var552,&var1147,&var550};
_S_and2  S_and2_1942_1 = {&var552,&var1146,&var551};
_S_and2  S_and2_1965_1 = {&var511,&var1486,&var552};
_S_zpfs  S_zpfs_834_1 = {&var1111,&fRM_3_,&var553,&internal1_m834_tx,&internal1_m834_y0};
_S_or4  S_or4_1779_1 = {&var748,&var749,&var750,&var752,&var554};
_S_or5  S_or5_1766_1 = {&var756,&var755,&var754,&var753,&var554,&var555};
_S_andn  S_andn_1_1 = {array_m1_x_1,&iRM_47_,&vainSBool};
_S_or2  S_or2_1748_1 = {&var558,&var559,&var556};
_S_ml  S_ml_1732_1 = {&fRM_1500_0,&B8MC01RP2,&var556,&var557};
_S_bol  S_bol_1744_1 = {&B8MC01RP2,&fRM_1500_0001,&var558};
_S_bol  S_bol_1749_1 = {&fRM_389_99,&B8MC01RP2,&var559};
_S_or2  S_or2_1761_1 = {&var562,&var563,&var560};
_S_ml  S_ml_1753_1 = {&fRM_0_0,&B3MC01RP1,&var560,&var561};
_S_bol  S_bol_1757_1 = {&B3MC01RP1,&fRM_160_00001,&var562};
_S_bol  S_bol_1764_1 = {&fRM_0_0001,&B3MC01RP1,&var563};
_S_or2  S_or2_1743_1 = {&var566,&var567,&var564};
_S_ml  S_ml_1731_1 = {&fRM_0_0,&A3MC01RP1,&var564,&var565};
_S_bol  S_bol_1734_1 = {&A3MC01RP1,&fRM_160_0001,&var566};
_S_bol  S_bol_1745_1 = {&fRM_0_0001,&A3MC01RP1,&var567};
_S_or2  S_or2_1759_1 = {&var570,&var571,&var568};
_S_ml  S_ml_1751_1 = {&fRM_100_0,&B1MC01RP1,&var568,&var569};
_S_bol  S_bol_1756_1 = {&B1MC01RP1,&fRM_100_0001,&var570};
_S_bol  S_bol_1762_1 = {&fRM_0_0001,&B1MC01RP1,&var571};
_S_or2  S_or2_1739_1 = {&var574,&var575,&var572};
_S_ml  S_ml_1729_1 = {&fRM_100_0,&A1MC01RP1,&var572,&var573};
_S_bol  S_bol_1737_1 = {&A1MC01RP1,&fRM_100_0001,&var574};
_S_bol  S_bol_1741_1 = {&fRM_0_0001,&A1MC01RP1,&var575};
_S_and2  S_and2_109_1 = {&var319,&var406,&var576};
_S_noto  S_noto_110_1 = {&var406,&var577};
_S_and2  S_and2_113_1 = {&var319,&var577,&var578};
_S_and2  S_and2_2207_1 = {&var580,&var581,&var579};
_S_or3  S_or3_2206_1 = {&var1448,&var701,&var429,&var580};
_S_noto  S_noto_2245_1 = {&var376,&var581};
_S_noto  S_noto_2234_1 = {&var583,&var582};
_S_ovbs  S_ovbs_2233_1 = {&var1340,&fRM_2_0,&var583,&internal1_m2233_tx};
_S_noto  S_noto_2224_1 = {&var379,&var584};
_S_and2  S_and2_2193_1 = {&var586,&var584,&var585};
_S_or3  S_or3_2192_1 = {&var429,&var1452,&var701,&var586};
_S_noto  S_noto_2239_1 = {&var594,&var587};
_S_and2  S_and2_2240_1 = {&var1423,&var587,&var588};
_S_and2  S_and2_2248_1 = {&var588,&var374,&var589};
_S_and2  S_and2_2227_1 = {&var591,&var378,&var590};
_S_and2  S_and2_2232_1 = {&var592,&var1423,&var591};
_S_noto  S_noto_2231_1 = {&var1138,&var592};
_S_noto  S_noto_2247_1 = {&var596,&var593};
_S_or2  S_or2_2238_1 = {&var471,&var593,&var594};
_S_noto  S_noto_2226_1 = {&var597,&var595};
_S_rs  S_rs_2236_1 = {&var471,&var602,&var596,&vainSBool,&internal1_m2236_q0};
_S_rs  S_rs_2228_1 = {&var472,&var603,&var597,&vainSBool,&internal1_m2228_q0};
_S_and2  S_and2_2216_1 = {&var600,&var607,&var598};
_S_and2  S_and2_2204_1 = {&var600,&var604,&var599};
_S_noto  S_noto_2198_1 = {&var601,&var600};
_S_ovbs  S_ovbs_2197_1 = {&var429,&fRM_10_0,&var601,&internal1_m2197_tx};
_S_ovbs  S_ovbs_2208_1 = {&var579,&fRM_2_0,&var602,&internal1_m2208_tx};
_S_ovbs  S_ovbs_2194_1 = {&var585,&fRM_2_0,&var603,&internal1_m2194_tx};
_S_or2  S_or2_2203_1 = {&var634,&var1200,&var604};
_S_or2  S_or2_2199_1 = {&var635,&var585,&var605};
_S_or2  S_or2_2211_1 = {&var635,&var579,&var606};
_S_or2  S_or2_2215_1 = {&var634,&var1197,&var607};
_S_rs  S_rs_2200_1 = {&var599,&var605,&var608,&vainSBool,&internal1_m2200_q0};
_S_noto  S_noto_2213_1 = {&var610,&var609};
_S_rs  S_rs_2212_1 = {&var598,&var606,&var610,&vainSBool,&internal1_m2212_q0};
_S_noto  S_noto_2201_1 = {&var608,&var611};
_S_noto  S_noto_2209_1 = {&var602,&var612};
_S_noto  S_noto_2195_1 = {&var603,&var613};
_S_and2  S_and2_2188_1 = {&var616,&var707,&var614};
_S_and2  S_and2_2177_1 = {&var616,&var704,&var615};
_S_noto  S_noto_2170_1 = {&var617,&var616};
_S_ovbs  S_ovbs_2169_1 = {&var393,&fRM_3_0,&var617,&internal1_m2169_tx};
_S_and2  S_and2_486_1 = {&var1845,&var1787,&var618};
_S_and2  S_and2_2063_1 = {&var1399,&B7AS31LDU,&var619};
_S_and2  S_and2_498_1 = {&var1146,&var992,&var620};
_S_and2  S_and2_489_1 = {&var993,&var1146,&var621};
_S_and2  S_and2_532_1 = {&var992,&var1147,&var622};
_S_and2  S_and2_527_1 = {&var993,&var1147,&var623};
_S_or2  S_or2_391_1 = {&var1858,&var1118,&var624};
_S_or2  S_or2_387_1 = {&var1858,&var1117,&var625};
_S_ovbs  S_ovbs_52_1 = {&var1870,&fRM_15_0,&var626,&internal1_m52_tx};
_S_ovbs  S_ovbs_368_1 = {&var1347,&fRM_0_02,&var627,&internal1_m368_tx};
_S_ovbs  S_ovbs_322_1 = {&var1349,&fRM_0_02,&var628,&internal1_m322_tx};
_S_ovbs  S_ovbs_835_1 = {&var553,&fRM_0_2,&var629,&internal1_m835_tx};
_S_ovbs  S_ovbs_1627_1 = {&R0MD31LP1,&fRM_10_0,&var630,&internal1_m1627_tx};
_S_ovbs  S_ovbs_120_1 = {&R0MD31LP1,&fRM_0_15,&var631,&internal1_m120_tx};
_S_ovbs  S_ovbs_122_1 = {&var578,&fRM_0_02,&var632,&internal1_m122_tx};
_S_ovbs  S_ovbs_127_1 = {&R0MD32LP1,&fRM_0_02,&var633,&internal1_m127_tx};
_S_ovbs  S_ovbs_21_1 = {&var1423,&fRM_3_0,&var634,&internal1_m21_tx};
_S_ovbs  S_ovbs_13_1 = {&var1195,&fRM_3_0,&var635,&internal1_m13_tx};
_S_ovbs  S_ovbs_2179_1 = {&var393,&fRM_2_0,&var636,&internal1_m2179_tx};
_S_ovbs  S_ovbs_2166_1 = {&var393,&fRM_2_0,&var637,&internal1_m2166_tx};
_S_ovbs  S_ovbs_2284_1 = {&var1432,&fRM_2_0,&var638,&internal1_m2284_tx};
_S_ovbs  S_ovbs_2286_1 = {&var355,&fRM_2_0,&var639,&internal1_m2286_tx};
_S_ovbs  S_ovbs_82_1 = {&R0MW13LP2,&fRM_10_0,&var640,&internal1_m82_tx};
_S_zpfs  S_zpfs_339_1 = {&var1049,&fRM_10_0,&var641,&internal1_m339_tx,&internal1_m339_y0};
_S_or2  S_or2_1158_1 = {&var1260,&var819,&var642};
_S_or2  S_or2_257_1 = {&A1VN71LZ1,&A1VN71LZ2,&var643};
_S_or2  S_or2_279_1 = {&var944,&var1212,&var644};
_S_or5  S_or5_155_1 = {&B1IS21LDU,&B3IS21LDU,&B2IS21LDU,&var1182,&var1183,&var645};
_S_and2  S_and2_1155_1 = {&var1695,&var1331,&var646};
_S_or3  S_or3_1112_1 = {&var397,&var904,&var903,&var647};
_S_or3  S_or3_1585_1 = {&var887,&var886,&var398,&var648};
_S_and2  S_and2_1086_1 = {&var1460,&var1241,&var649};
_S_and3  S_and3_2086_1 = {&var658,&var44,&var651,&var650};
_S_or2  S_or2_2074_1 = {&var1253,&var1363,&var651};
_S_or3  S_or3_2079_1 = {&var656,&var1363,&var654,&var652};
_S_and2  S_and2_2085_1 = {&var1253,&var44,&var653};
_S_and2  S_and2_2078_1 = {&var1355,&var655,&var654};
_S_zpfs  S_zpfs_2077_1 = {&var1253,&fEM_R0UL04RDU,&var655,&internal1_m2077_tx,&internal1_m2077_y0};
_S_and2  S_and2_2070_1 = {&var1358,&var804,&var656};
_S_or3  S_or3_2071_1 = {&var1312,&var810,&var1290,&var657};
_S_abs_subf  S_abs_subf_2092_1 = {&fEM_R0UL02RDU,&var659,&fEM_R0UL16RDU,&vainSFloat,&var658};
_S_rsfn  S_rsfn_2091_1 = {&var801,&var660,&var659,&internal1_m2091_q0};
_S_lk  S_lk_2089_1 = {&var1515,&var44,&var660};
_S_abs_subf  S_abs_subf_1657_1 = {&fEM_R0UL05RDU,&var662,&fEM_R0UL18RDU,&vainSFloat,&var661};
_S_rsfn  S_rsfn_1648_1 = {&var801,&var663,&var662,&internal1_m1648_q0};
_S_lk  S_lk_1652_1 = {&var1369,&var788,&var663};
_S_abs_subf  S_abs_subf_1701_1 = {&fEM_R0UL07RDU,&var665,&fEM_R0UL20RDU,&vainSFloat,&var664};
_S_rsfn  S_rsfn_1686_1 = {&var801,&var666,&var665,&internal1_m1686_q0};
_S_lk  S_lk_1693_1 = {&var1375,&var778,&var666};
_S_ma  S_ma_1669_1 = {array_m1669_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_abs_subf  S_abs_subf_1707_1 = {&fEM_R0UL25RDU,&var668,&fEM_R0UL19RDU,&vainSFloat,&var667};
_S_rsfn  S_rsfn_1689_1 = {&var801,&var669,&var668,&internal1_m1689_q0};
_S_lk  S_lk_1695_1 = {&var1513,&var769,&var669};
_S_and3  S_and3_2136_1 = {&var671,&var674,&var681,&var670};
_S_abs_subf  S_abs_subf_2133_1 = {&var672,&fEM_R0UL03RDU,&fEM_R0UL17RDU,&vainSFloat,&var671};
_S_rsfn  S_rsfn_2131_1 = {&var801,&var673,&var672,&internal1_m2131_q0};
_S_lk  S_lk_2127_1 = {&var1514,&var674,&var673};
_S_or3  S_or3_2126_1 = {&var679,&var685,&var684,&var674};
_S_and4  S_and4_2130_1 = {&var684,&var1520,&var697,&var695,&var675};
_S_and4  S_and4_2128_1 = {&var685,&var1520,&var697,&var695,&var676};
_S_and2  S_and2_2120_1 = {&var28,&var674,&var677};
_S_and2  S_and2_2106_1 = {&var804,&var1357,&var678};
_S_and2  S_and2_2110_1 = {&var682,&var1356,&var679};
_S_or3  S_or3_2111_1 = {&var679,&var678,&var1366,&var680};
_S_or2  S_or2_2102_1 = {&var28,&var1366,&var681};
_S_zpfs  S_zpfs_2109_1 = {&var28,&fEM_R0UL21RDU,&var682,&internal1_m2109_tx,&internal1_m2109_y0};
_S_or3  S_or3_2099_1 = {&var806,&var1316,&var1294,&var683};
_S_zpfs  S_zpfs_2124_1 = {&var687,&fEM_R0UL03RDU,&var684,&internal1_m2124_tx,&internal1_m2124_y0};
_S_zpfs  S_zpfs_2121_1 = {&var688,&fEM_R0UL03RDU,&var685,&internal1_m2121_tx,&internal1_m2121_y0};
_S_or2  S_or2_2118_1 = {&var688,&var687,&var686};
_S_or2  S_or2_2119_1 = {&var689,&var28,&var687};
_S_or2  S_or2_2117_1 = {&var690,&var28,&var688};
_S_and4  S_and4_2114_1 = {&var1421,&var1147,&B2IS12LDU,&var691,&var689};
_S_and4  S_and4_2108_1 = {&var1422,&A2IS12LDU,&var1146,&var691,&var690};
_S_and2  S_and2_2107_1 = {&var1169,&var695,&var691};
_S_and3  S_and3_2145_1 = {&var1147,&var1278,&var694,&var692};
_S_and3  S_and3_2144_1 = {&var1146,&var1279,&var694,&var693};
_S_and4  S_and4_2143_1 = {&var1240,&var1039,&var1041,&var695,&var694};
_S_and2  S_and2_2137_1 = {&var1052,&var1241,&var695};
_S_or2  S_or2_2139_1 = {&var1524,&var1239,&var696};
_S_or3  S_or3_2148_1 = {&var700,&var699,&var702,&var697};
_S_and2  S_and2_2138_1 = {&var1282,&A2IS12LDU,&var698};
_S_and2  S_and2_2142_1 = {&var1179,&var698,&var699};
_S_and3  S_and3_2147_1 = {&var1519,&var703,&var698,&var700};
_S_or2  S_or2_2156_1 = {&lRM_0_,&var696,&var701};
_S_and2  S_and2_2153_1 = {&var1194,&var703,&var702};
_S_and2  S_and2_2155_1 = {&var1281,&B2IS12LDU,&var703};
_S_or2  S_or2_2176_1 = {&var1199,&var634,&var704};
_S_or2  S_or2_2171_1 = {&var635,&var393,&var705};
_S_or2  S_or2_2183_1 = {&var393,&var635,&var706};
_S_or2  S_or2_2187_1 = {&var634,&var1198,&var707};
_S_or2  S_or2_2252_1 = {&var1047,&var1433,&var708};
_S_or2  S_or2_2262_1 = {&var1241,&var1454,&var709};
_S_zpfs  S_zpfs_2264_1 = {&var324,&fRM_15_0,&var710,&internal1_m2264_tx,&internal1_m2264_y0};
_S_or2  S_or2_2268_1 = {&var1046,&var356,&var711};
_S_zpfs  S_zpfs_2275_1 = {&var322,&fRM_15_0,&var712,&internal1_m2275_tx,&internal1_m2275_y0};
_S_or2  S_or2_2280_1 = {&var1241,&var1453,&var713};
_S_or2  S_or2_2298_1 = {&var328,&var675,&var714};
_S_or2  S_or2_2291_1 = {&var676,&var332,&var715};
_S_and2  S_and2_2302_1 = {&var1423,&var638,&var716};
_S_and2  S_and2_2062_1 = {&var1400,&A7AS31LDU,&var717};
_S_or3  S_or3_2035_1 = {&var722,&var726,&var724,&var718};
_S_or3  S_or3_2037_1 = {&var725,&var724,&var721,&var719};
_S_or2  S_or2_2049_1 = {&B0VT71LZ1,&B0VT71LZ2,&var720};
_S_and2  S_and2_2040_1 = {&var727,&var720,&var721};
_S_and2  S_and2_2034_1 = {&var727,&var723,&var722};
_S_or2  S_or2_2033_1 = {&A0VT71LZ1,&A0VT71LZ2,&var723};
_S_zpfs  S_zpfs_2030_1 = {&var1417,&fRM_2_5,&var724,&internal1_m2030_tx,&internal1_m2030_y0};
_S_zpfs  S_zpfs_2029_1 = {&var1418,&fRM_2_5,&var725,&internal1_m2029_tx,&internal1_m2029_y0};
_S_zpfs  S_zpfs_2028_1 = {&var1419,&fRM_2_5,&var726,&internal1_m2028_tx,&internal1_m2028_y0};
_S_zpfs  S_zpfs_2027_1 = {&var1420,&fRM_2_5,&var727,&internal1_m2027_tx,&internal1_m2027_y0};
_S_or2  S_or2_2058_1 = {&R0VP73LZ2,&R0VP73LZ1,&var728};
_S_and2  S_and2_2051_1 = {&var355,&var1401,&var729};
_S_or2  S_or2_2048_1 = {&var732,&var729,&var730};
_S_or2  S_or2_2050_1 = {&var328,&var355,&var731};
_S_and2  S_and2_2047_1 = {&var328,&var1391,&var732};
_S_and2  S_and2_2031_1 = {&var1432,&var1402,&var733};
_S_or2  S_or2_2032_1 = {&var736,&var733,&var734};
_S_or2  S_or2_2025_1 = {&var332,&var1432,&var735};
_S_and2  S_and2_2024_1 = {&var332,&var1392,&var736};
_S_or3  S_or3_1994_1 = {&var1483,&var1441,&var1442,&var737};
_S_or3  S_or3_1995_1 = {&var1481,&var1441,&var1442,&var738};
_S_or2  S_or2_1986_1 = {&var1476,&var1441,&var739};
_S_or2  S_or2_1987_1 = {&var1475,&var1441,&var740};
_S_or2  S_or2_1993_1 = {&var1485,&var1444,&var741};
_S_or4  S_or4_1991_1 = {&var1444,&var1482,&var1445,&var1446,&var742};
_S_or4  S_or4_1990_1 = {&var1444,&var1488,&var1445,&var1446,&var743};
_S_or2  S_or2_1984_1 = {&var1477,&var1446,&var744};
_S_or2  S_or2_1983_1 = {&var1478,&var1446,&var745};
_S_or2  S_or2_1992_1 = {&var1444,&var1484,&var746};
_S_or2  S_or2_1961_1 = {&var503,&var549,&var747};
_S_and2  S_and2_1784_1 = {&var1738,&var1696,&var748};
_S_and2  S_and2_1783_1 = {&var1861,&var1696,&var749};
_S_and2  S_and2_1782_1 = {&var1136,&var1696,&var750};
_S_or2  S_or2_1781_1 = {&B4IS11LDU,&A4IS11LDU,&var751};
_S_and2  S_and2_1780_1 = {&var751,&var1696,&var752};
_S_and2  S_and2_1770_1 = {&var1928,&var1696,&var753};
_S_and2  S_and2_1769_1 = {&var406,&var1696,&var754};
_S_and2  S_and2_1768_1 = {&var1125,&var1696,&var755};
_S_and2  S_and2_1767_1 = {&R3IS21LDU,&var1696,&var756};
_S_or2  S_or2_1841_1 = {&var1874,&var1875,&var757};
_S_or2  S_or2_1840_1 = {&var1876,&var1874,&var758};
_S_or2  S_or2_2321_1 = {&var1218,&R0MD34LP1,&var759};
_S_or3  S_or3_2327_1 = {&var1495,&var1497,&var1496,&var760};
_S_or3  S_or3_2318_1 = {&var1501,&var1503,&var1502,&var761};
_S_or2  S_or2_1825_1 = {&var1986,&var1696,&var762};
_S_or2  S_or2_1797_1 = {&var1739,&var1331,&var763};
_S_or5  S_or5_1283_1 = {&var1754,&var765,&var1765,&var1751,&var1752,&var764};
_S_or3  S_or3_1287_1 = {&var1759,&var1760,&var1221,&var765};
_S_or5  S_or5_1812_1 = {&var555,&var767,&var1748,&var1740,&var1741,&var766};
_S_or3  S_or3_1815_1 = {&var1220,&var1743,&var1742,&var767};
_S_and3  S_and3_1716_1 = {&var769,&var774,&var667,&var768};
_S_and2  S_and2_1719_1 = {&var770,&var1251,&var769};
_S_or3  S_or3_1718_1 = {&A3VZ13LZ2,&A3VZ13LZ1,&var773,&var770};
_S_zpfs  S_zpfs_1702_1 = {&var1251,&fRM_0_2,&var771,&internal1_m1702_tx,&internal1_m1702_y0};
_S_or3  S_or3_1704_1 = {&var1377,&var773,&var775,&var772};
_S_and2  S_and2_1703_1 = {&var1354,&var771,&var773};
_S_or2  S_or2_1694_1 = {&var1251,&var1377,&var774};
_S_and2  S_and2_1681_1 = {&var1359,&var804,&var775};
_S_or3  S_or3_1687_1 = {&var1291,&var1313,&var809,&var776};
_S_or3  S_or3_1712_1 = {&R0AD14LZ1,&R0AD14LZ2,&var780,&var777};
_S_and2  S_and2_1713_1 = {&var777,&var1249,&var778};
_S_zpfs  S_zpfs_1696_1 = {&var1249,&fEM_R0UL06RDU,&var779,&internal1_m1696_tx,&internal1_m1696_y0};
_S_and2  S_and2_1697_1 = {&var779,&var1353,&var780};
_S_or3  S_or3_1698_1 = {&var1372,&var780,&var783,&var781};
_S_or3  S_or3_1671_1 = {&var808,&var1314,&var1292,&var782};
_S_and2  S_and2_1676_1 = {&var1360,&var804,&var783};
_S_and3  S_and3_1715_1 = {&var664,&var778,&var791,&var784};
_S_zpfs  S_zpfs_1643_1 = {&var1248,&fEM_R0UL04RDU,&var785,&internal1_m1643_tx,&internal1_m1643_y0};
_S_and2  S_and2_1644_1 = {&var785,&var1352,&var786};
_S_and3  S_and3_1661_1 = {&var661,&var788,&var792,&var787};
_S_and2  S_and2_1655_1 = {&var789,&var1248,&var788};
_S_or3  S_or3_1654_1 = {&A3VZ15LZ1,&A3VZ15LZ2,&var786,&var789};
_S_or3  S_or3_1645_1 = {&var793,&var786,&var1370,&var790};
_S_or2  S_or2_1690_1 = {&var1249,&var1372,&var791};
_S_or2  S_or2_1641_1 = {&var1248,&var1370,&var792};
_S_and2  S_and2_1633_1 = {&var1361,&var804,&var793};
_S_or3  S_or3_1631_1 = {&var1293,&var1315,&var807,&var794};
_S_or2  S_or2_1594_1 = {&var1867,&var796,&var795};
_S_and2  S_and2_1593_1 = {&var797,&var1415,&var796};
_S_or2  S_or2_1592_1 = {&var1192,&var1144,&var797};
_S_or2  S_or2_1589_1 = {&var1286,&var1308,&var798};
_S_and2  S_and2_1587_1 = {&var1380,&var1381,&var799};
_S_and2  S_and2_1590_1 = {&var798,&var797,&var800};
_S_or5  S_or5_1591_1 = {&var628,&var627,&var799,&var800,&R0MD34LP1,&var801};
_S_orni  S_orni_1620_1 = {array_m1620_x_1,&iRM_5_,&var802,&var803};
_S_or5  S_or5_1622_1 = {&var1376,&var1351,&var801,&var1296,&var630,&var804};
_S_and2  S_and2_1621_1 = {&var802,&var1507,&var805};
_S_or2  S_or2_1630_1 = {&var41,&var43,&var806};
_S_or2  S_or2_1624_1 = {&var39,&var811,&var807};
_S_or2  S_or2_1616_1 = {&var38,&var812,&var808};
_S_or2  S_or2_1612_1 = {&var40,&var813,&var809};
_S_or2  S_or2_1608_1 = {&var42,&var814,&var810};
_S_and2  S_and2_1623_1 = {&var1322,&var1317,&var811};
_S_and2  S_and2_1615_1 = {&var1321,&var1317,&var812};
_S_and2  S_and2_1611_1 = {&var1317,&var1320,&var813};
_S_and2  S_and2_1607_1 = {&var1319,&var1317,&var814};
_S_and2  S_and2_1598_1 = {&var1867,&var315,&var815};
_S_and3  S_and3_1188_1 = {&var497,&var820,&var838,&var816};
_S_or2  S_or2_1153_1 = {&var1333,&var1329,&var817};
_S_or2  S_or2_1178_1 = {&var1329,&var1263,&var818};
_S_and2  S_and2_1146_1 = {&var1705,&var1330,&var819};
_S_and2  S_and2_1141_1 = {&var1524,&var840,&var820};
_S_or3  S_or3_1150_1 = {&var1329,&var1259,&var1332,&var821};
_S_and2  S_and2_1154_1 = {&var494,&var1524,&var822};
_S_and2  S_and2_1179_1 = {&var505,&var1524,&var823};
_S_and2  S_and2_1187_1 = {&var499,&var1524,&var824};
_S_and2  S_and2_1194_1 = {&var502,&var1524,&var825};
_S_and3  S_and3_1136_1 = {&var828,&var1245,&var1524,&var826};
_S_and3  S_and3_1130_1 = {&var829,&var1245,&var1524,&var827};
_S_and2  S_and2_1138_1 = {&var1146,&var1523,&var828};
_S_and2  S_and2_1128_1 = {&var1147,&var1523,&var829};
_S_and4  S_and4_1137_1 = {&var828,&var1524,&var1256,&var1243,&var830};
_S_and4  S_and4_1131_1 = {&var829,&var1524,&var1256,&var1243,&var831};
_S_and4  S_and4_1135_1 = {&var1524,&var828,&var836,&var1244,&var832};
_S_and4  S_and4_1129_1 = {&var1524,&var829,&var836,&var1244,&var833};
_S_and2  S_and2_1122_1 = {&var1257,&var1524,&var834};
_S_or4  S_or4_1125_1 = {&R0MD31LP1,&var1758,&var510,&var847,&var835};
_S_and3  S_and3_1175_1 = {&var1258,&var1257,&var1256,&var836};
_S_and2  S_and2_1159_1 = {&var838,&var642,&var837};
_S_and2  S_and2_1163_1 = {&var1255,&var836,&var838};
_S_or2  S_or2_1170_1 = {&var1325,&var1267,&var839};
_S_and2  S_and2_1181_1 = {&var841,&var839,&var840};
_S_or2  S_or2_1171_1 = {&var1266,&var1268,&var841};
_S_or2  S_or2_1172_1 = {&var1265,&var1266,&var842};
_S_or2  S_or2_1176_1 = {&var1264,&var1269,&var843};
_S_and2  S_and2_1177_1 = {&var842,&var843,&var844};
_S_or2  S_or2_1166_1 = {&var1325,&var1324,&var845};
_S_and2  S_and2_1167_1 = {&var845,&var1261,&var846};
_S_and5  S_and5_1118_1 = {&var848,&var1345,&var1266,&var1325,&var837,&var847};
_S_and2  S_and2_1119_1 = {&var1300,&var1301,&var848};
_S_and2  S_and2_1409_1 = {&var1394,&var850,&var849};
_S_or2  S_or2_1404_1 = {&A2MD12LP1,&var851,&var850};
_S_and2  S_and2_1395_1 = {&A2MD11LP1,&var1411,&var851};
_S_or2  S_or2_1385_1 = {&var854,&B2MD12LP1,&var852};
_S_and2  S_and2_1387_1 = {&var852,&var1394,&var853};
_S_and2  S_and2_1379_1 = {&B2MD11LP1,&var1412,&var854};
_S_or3  S_or3_1367_1 = {&var1474,&var1469,&var1010,&var855};
_S_or5  S_or5_1380_1 = {&var858,&var1230,&var1735,&var1730,&var1729,&var856};
_S_or2  S_or2_1403_1 = {&var1998,&var1720,&var857};
_S_or3  S_or3_1470_1 = {&var1701,&var859,&var860,&var858};
_S_and2  S_and2_1461_1 = {&var1720,&var1193,&var859};
_S_and2  S_and2_1460_1 = {&var1143,&var1720,&var860};
_S_and3  S_and3_1459_1 = {&var645,&var1179,&var875,&var861};
_S_and2  S_and2_1458_1 = {&var406,&var875,&var862};
_S_and3  S_and3_1452_1 = {&var1168,&var1214,&var875,&var863};
_S_and2  S_and2_1451_1 = {&var728,&var875,&var864};
_S_and2  S_and2_1436_1 = {&var1711,&var875,&var865};
_S_and2  S_and2_1420_1 = {&var1928,&var875,&var866};
_S_and2  S_and2_1438_1 = {&var313,&var875,&var867};
_S_and2  S_and2_1421_1 = {&R3IS21LDU,&var875,&var868};
_S_and2  S_and2_1439_1 = {&var871,&var875,&var869};
_S_and3  S_and3_1422_1 = {&var872,&var1710,&var875,&var870};
_S_or2  S_or2_1440_1 = {&var1703,&var1704,&var871};
_S_or2  S_or2_1425_1 = {&A4IS11LDU,&B4IS11LDU,&var872};
_S_and3  S_and3_1433_1 = {&var1444,&var511,&var1195,&var873};
_S_and3  S_and3_1432_1 = {&var1446,&var511,&var1195,&var874};
_S_or3  S_or3_1424_1 = {&var1721,&var874,&var873,&var875};
_S_and2  S_and2_1517_1 = {&var877,&var1394,&var876};
_S_or2  S_or2_1513_1 = {&var878,&B3MD12LP1,&var877};
_S_and2  S_and2_1503_1 = {&B3MD11LP1,&var1390,&var878};
_S_or2  S_or2_1508_1 = {&var1989,&var1538,&var879};
_S_or5  S_or5_1496_1 = {&var648,&var1547,&var1548,&var423,&var1228,&var880};
_S_and2  S_and2_1568_1 = {&var1538,&var1193,&var881};
_S_and2  S_and2_1567_1 = {&var1538,&var1143,&var882};
_S_and2  S_and2_1581_1 = {&var1209,&var1526,&var883};
_S_or2  S_or2_1574_1 = {&var883,&var1210,&var884};
_S_and3  S_and3_1566_1 = {&var1403,&var884,&var893,&var885};
_S_and3  S_and3_1565_1 = {&var645,&var1194,&var893,&var886};
_S_and2  S_and2_1564_1 = {&var406,&var893,&var887};
_S_and2  S_and2_1559_1 = {&var1458,&var1241,&var888};
_S_or2  S_or2_1546_1 = {&var1529,&var1528,&var889};
_S_and2  S_and2_1545_1 = {&var889,&var893,&var890};
_S_and2  S_and2_1544_1 = {&var313,&var893,&var891};
_S_and2  S_and2_1542_1 = {&var1531,&var893,&var892};
_S_or2  S_or2_1531_1 = {&var1540,&var336,&var893};
_S_or2  S_or2_1532_1 = {&B4IS11LDU,&A4IS11LDU,&var894};
_S_and3  S_and3_1529_1 = {&var1530,&var894,&var893,&var895};
_S_and2  S_and2_1528_1 = {&R3IS21LDU,&var893,&var896};
_S_and2  S_and2_1527_1 = {&var1928,&var893,&var897};
_S_and2  S_and2_1105_1 = {&var1207,&var1558,&var898};
_S_and2  S_and2_1094_1 = {&var1143,&var1570,&var899};
_S_and2  S_and2_1095_1 = {&var1193,&var1570,&var900};
_S_or2  S_or2_1101_1 = {&var1208,&var898,&var901};
_S_and3  S_and3_1093_1 = {&var1403,&var901,&var908,&var902};
_S_and3  S_and3_1092_1 = {&var1179,&var645,&var908,&var903};
_S_and2  S_and2_1091_1 = {&var406,&var908,&var904};
_S_and2  S_and2_1069_1 = {&var1563,&var908,&var905};
_S_or2  S_or2_1073_1 = {&var1561,&var1560,&var906};
_S_and2  S_and2_1072_1 = {&var906,&var908,&var907};
_S_or2  S_or2_1057_1 = {&var1572,&var337,&var908};
_S_or2  S_or2_1058_1 = {&B4IS11LDU,&A4IS11LDU,&var909};
_S_and3  S_and3_1056_1 = {&var909,&var1562,&var908,&var910};
_S_and2  S_and2_1071_1 = {&var313,&var908,&var911};
_S_and2  S_and2_1055_1 = {&R3IS21LDU,&var908,&var912};
_S_and2  S_and2_1054_1 = {&var1928,&var908,&var913};
_S_or2  S_or2_1034_1 = {&var1570,&var1992,&var914};
_S_or5  S_or5_1020_1 = {&var647,&var1229,&var421,&var1579,&var1580,&var915};
_S_and2  S_and2_1047_1 = {&var1394,&var917,&var916};
_S_or2  S_or2_1042_1 = {&var918,&A3MD12LP1,&var917};
_S_and2  S_and2_1031_1 = {&A3MD11LP1,&var1443,&var918};
_S_or3  S_or3_992_1 = {&var1668,&var921,&var920,&var919};
_S_and2  S_and2_982_1 = {&var1679,&var1143,&var920};
_S_and2  S_and2_983_1 = {&var1679,&var1193,&var921};
_S_and3  S_and3_981_1 = {&var1702,&var1194,&var933,&var922};
_S_and2  S_and2_980_1 = {&var406,&var933,&var923};
_S_and2  S_and2_958_1 = {&var1672,&var933,&var924};
_S_and2  S_and2_960_1 = {&var313,&var933,&var925};
_S_and2  S_and2_961_1 = {&var927,&var933,&var926};
_S_or2  S_or2_962_1 = {&var1670,&var1669,&var927};
_S_and2  S_and2_942_1 = {&var1928,&var933,&var928};
_S_and3  S_and3_944_1 = {&var1671,&var934,&var933,&var929};
_S_and2  S_and2_943_1 = {&R3IS21LDU,&var933,&var930};
_S_and3  S_and3_957_1 = {&var1444,&var511,&var1195,&var931};
_S_and3  S_and3_956_1 = {&var511,&var1446,&var1195,&var932};
_S_or3  S_or3_945_1 = {&var1680,&var931,&var932,&var933};
_S_or2  S_or2_946_1 = {&B4IS11LDU,&A4IS11LDU,&var934};
_S_or2  S_or2_926_1 = {&var1995,&var1679,&var935};
_S_zpfs  S_zpfs_922_1 = {&var1693,&fRM_3_0,&var936,&internal1_m922_tx,&internal1_m922_y0};
_S_zpfs  S_zpfs_921_1 = {&var1694,&fRM_2_0,&var937,&internal1_m921_tx,&internal1_m921_y0};
_S_zpfs  S_zpfs_939_1 = {&var1691,&fEM_A2UL83RDU,&var938,&internal1_m939_tx,&internal1_m939_y0};
_S_or5  S_or5_918_1 = {&var919,&var938,&var1692,&var937,&var936,&var939};
_S_or3  S_or3_904_1 = {&var1449,&var1472,&var1005,&var940};
_S_or4  S_or4_886_1 = {&var1815,&var1813,&var1814,&var1816,&var941};
_S_or2  S_or2_878_1 = {&var943,&var941,&var942};
_S_or4  S_or4_871_1 = {&var1824,&var1823,&var1822,&var1825,&var943};
_S_and2  S_and2_282_1 = {&var1211,&var1618,&var944};
_S_and3  S_and3_268_1 = {&var1179,&var645,&var1633,&var945};
_S_or3  S_or3_286_1 = {&var947,&var949,&var1621,&var946};
_S_and2  S_and2_272_1 = {&var1632,&var1193,&var947};
_S_and3  S_and3_269_1 = {&var644,&var1403,&var1633,&var948};
_S_and2  S_and2_271_1 = {&var1143,&var1632,&var949};
_S_and2  S_and2_267_1 = {&var406,&var1633,&var950};
_S_and2  S_and2_236_1 = {&var1625,&var1633,&var951};
_S_and2  S_and2_238_1 = {&var313,&var1633,&var952};
_S_or2  S_or2_240_1 = {&var1622,&var1623,&var953};
_S_and2  S_and2_239_1 = {&var953,&var1633,&var954};
_S_or2  S_or2_225_1 = {&B4IS11LDU,&A4IS11LDU,&var955};
_S_and3  S_and3_224_1 = {&var1624,&var955,&var1633,&var956};
_S_and2  S_and2_219_1 = {&var1928,&var1633,&var957};
_S_and2  S_and2_223_1 = {&R3IS21LDU,&var1633,&var958};
_S_and2  S_and2_191_1 = {&var1394,&var961,&var959};
_S_and2  S_and2_184_1 = {&A1MD11LP1,&var1431,&var960};
_S_or2  S_or2_190_1 = {&A1MD12LP1,&var960,&var961};
_S_or2  S_or2_200_1 = {&var1632,&var1980,&var962};
_S_zpfs  S_zpfs_194_1 = {&var1647,&fRM_2_0,&var963,&internal1_m194_tx,&internal1_m194_y0};
_S_zpfs  S_zpfs_193_1 = {&var1646,&fRM_2_0,&var964,&internal1_m193_tx,&internal1_m193_y0};
_S_zpfs  S_zpfs_215_1 = {&var1644,&fEM_A1UL03RDU,&var965,&internal1_m215_tx,&internal1_m215_y0};
_S_or5  S_or5_188_1 = {&var946,&var965,&var964,&var963,&var1645,&var966};
_S_orn  S_orn_616_1 = {array_m616_x_1,&iRM_12_,&var967};
_S_and2  S_and2_645_1 = {&var1588,&var1206,&var968};
_S_or2  S_or2_641_1 = {&var1205,&var968,&var969};
_S_and3  S_and3_631_1 = {&var1194,&var1702,&var1600,&var970};
_S_and2  S_and2_630_1 = {&var406,&var1600,&var971};
_S_and3  S_and3_632_1 = {&var1403,&var1600,&var969,&var972};
_S_or2  S_or2_606_1 = {&var1590,&var1589,&var973};
_S_and2  S_and2_605_1 = {&var973,&var1600,&var974};
_S_and2  S_and2_604_1 = {&var1600,&var313,&var975};
_S_and3  S_and3_591_1 = {&var1591,&var977,&var1600,&var976};
_S_or2  S_or2_592_1 = {&B4IS11LDU,&A4IS11LDU,&var977};
_S_and2  S_and2_602_1 = {&var1600,&var1592,&var978};
_S_or2  S_or2_565_1 = {&B1MD12LP1,&var981,&var979};
_S_and2  S_and2_567_1 = {&var1394,&var979,&var980};
_S_and2  S_and2_559_1 = {&B1MD11LP1,&var1413,&var981};
_S_and2  S_and2_590_1 = {&var1600,&R3IS21LDU,&var982};
_S_and2  S_and2_589_1 = {&var1600,&var1928,&var983};
_S_or2  S_or2_572_1 = {&var1599,&var2002,&var984};
_S_zpfs  S_zpfs_588_1 = {&var1613,&fEM_A1UL03RDU,&var985,&internal1_m588_tx,&internal1_m588_y0};
_S_or5  S_or5_561_1 = {&var1139,&var985,&var1614,&var1608,&var1609,&var986};
_S_or2  S_or2_549_1 = {&var1427,&var1006,&var987};
_S_or3  S_or3_539_1 = {&var827,&var1426,&var1236,&var988};
_S_or4  S_or4_526_1 = {&var1653,&var1650,&var1652,&var1651,&var989};
_S_or4  S_or4_507_1 = {&var1661,&var1659,&var1660,&var1662,&var990};
_S_or2  S_or2_514_1 = {&var990,&var989,&var991};
_S_and3  S_and3_496_1 = {&var994,&var1394,&R0MD33LP1,&var992};
_S_and3  S_and3_497_1 = {&var1394,&var995,&R0MD33LP1,&var993};
_S_or3  S_or3_487_1 = {&var541,&var1246,&var1232,&var994};
_S_or2  S_or2_488_1 = {&var1648,&var1425,&var995};
_S_or2  S_or2_837_1 = {&var1783,&var1784,&var996};
_S_and2  S_and2_358_1 = {&var1285,&var1347,&var997};
_S_or2  S_or2_377_1 = {&B4IS21LDU,&A4IS21LDU,&var998};
_S_or2  S_or2_372_1 = {&A2IS21LDU,&B2IS21LDU,&var999};
_S_or2  S_or2_367_1 = {&var1002,&var1289,&var1000};
_S_and3  S_and3_365_1 = {&var1348,&var1343,&var1344,&var1001};
_S_or4  S_or4_363_1 = {&var1274,&var451,&R0MD31LP1,&var1284,&var1002};
_S_and4  S_and4_359_1 = {&var1192,&var1060,&var510,&var1150,&var1003};
_S_or2  S_or2_354_1 = {&R0MD34LP1,&var1284,&var1004};
_S_and3  S_and3_676_1 = {&var1027,&var1525,&B2IS12LDU,&var1005};
_S_and2  S_and2_675_1 = {&var1027,&var1557,&var1006};
_S_and2  S_and2_674_1 = {&var1027,&var1620,&var1007};
_S_or2  S_or2_718_1 = {&A2IS12LDU,&B2IS12LDU,&var1008};
_S_or2  S_or2_695_1 = {&var1755,&var1383,&var1009};
_S_and3  S_and3_686_1 = {&A2IS12LDU,&var1525,&var1028,&var1010};
_S_and2  S_and2_717_1 = {&var1012,&var1525,&var1011};
_S_or2  S_or2_719_1 = {&var1326,&var494,&var1012};
_S_or2  S_or2_700_1 = {&var1755,&var1382,&var1013};
_S_or2  S_or2_698_1 = {&var1015,&var1755,&var1014};
_S_and2  S_and2_710_1 = {&var1557,&var505,&var1015};
_S_and2  S_and2_685_1 = {&var1028,&var1557,&var1016};
_S_and2  S_and2_684_1 = {&var1028,&var1620,&var1017};
_S_and2  S_and2_709_1 = {&var499,&var1620,&var1018};
_S_and2  S_and2_725_1 = {&var502,&var1648,&var1019};
_S_or2  S_or2_721_1 = {&var1755,&var1384,&var1020};
_S_or2  S_or2_716_1 = {&var1022,&var1019,&var1021};
_S_and2  S_and2_708_1 = {&var1030,&var1617,&var1022};
_S_and2  S_and2_714_1 = {&var1030,&R0MD33LP1,&var1023};
_S_or2  S_or2_664_1 = {&var1203,&var1204,&var1024};
_S_and4  S_and4_683_1 = {&var1203,&var1028,&var1717,&A2IS12LDU,&var1025};
_S_and4  S_and4_673_1 = {&var1027,&var1204,&var1717,&B2IS12LDU,&var1026};
_S_and2  S_and2_672_1 = {&var1147,&var1715,&var1027};
_S_and2  S_and2_682_1 = {&var1146,&var1715,&var1028};
_S_or2  S_or2_713_1 = {&var1327,&var494,&var1029};
_S_and2  S_and2_706_1 = {&var1029,&var1717,&var1030};
_S_or2  S_or2_693_1 = {&var1755,&var1385,&var1031};
_S_or2  S_or2_705_1 = {&var1695,&var1340,&var1032};
_S_and2  S_and2_704_1 = {&var1032,&var1739,&var1033};
_S_or2  S_or2_690_1 = {&var1755,&var1386,&var1034};
_S_and2  S_and2_703_1 = {&var1756,&var1705,&var1035};
_S_or2  S_or2_688_1 = {&var1755,&var1387,&var1036};
_S_and2  S_and2_701_1 = {&var497,&var1758,&var1037};
_S_or2  S_or2_680_1 = {&var1395,&var1755,&var1038};
_S_and2  S_and2_332_1 = {&var1455,&var1041,&var1039};
_S_and2  S_and2_320_1 = {&var1041,&var1272,&var1040};
_S_or2  S_or2_315_1 = {&var1286,&var1308,&var1041};
_S_and3  S_and3_311_1 = {&var1521,&var1343,&var1344,&var1042};
_S_and3  S_and3_326_1 = {&var999,&var1273,&var1044,&var1043};
_S_or2  S_or2_316_1 = {&var1521,&var1348,&var1044};
_S_and2  S_and2_325_1 = {&var998,&var1044,&var1045};
_S_and2  S_and2_346_1 = {&var1050,&var1147,&var1046};
_S_and2  S_and2_347_1 = {&var1146,&var1050,&var1047};
_S_and2  S_and2_352_1 = {&var1241,&var1039,&var1048};
_S_and2  S_and2_340_1 = {&var1050,&var1241,&var1049};
_S_and2  S_and2_345_1 = {&var1423,&var1051,&var1050};
_S_or2  S_or2_341_1 = {&var1052,&var997,&var1051};
_S_or2  S_or2_342_1 = {&var1053,&var997,&var1052};
_S_and4  S_and4_343_1 = {&var1349,&var1297,&var1298,&var1144,&var1053};
_S_or2  S_or2_328_1 = {&var1349,&var1347,&var1054};
_S_and2  S_and2_313_1 = {&var1311,&var1280,&var1055};
_S_or2  S_or2_319_1 = {&var1058,&var1055,&var1056};
_S_or2  S_or2_293_1 = {&R0MD34LP1,&var1283,&var1057};
_S_or4  S_or4_310_1 = {&var1274,&R0MD31LP1,&var451,&var1283,&var1058};
_S_and3  S_and3_303_1 = {&var1060,&var1149,&var510,&var1059};
_S_or2  S_or2_302_1 = {&var1302,&var1486,&var1060};
_S_and3  S_and3_305_1 = {&var1303,&var1305,&var1304,&var1061};
_S_or2  S_or2_295_1 = {&var1063,&var1061,&var1062};
_S_and3  S_and3_289_1 = {&R0MD33LP1,&var1307,&var1306,&var1063};
_S_or2  S_or2_1250_1 = {&B4IS11LDU,&A4IS11LDU,&var1064};
_S_and2  S_and2_1253_1 = {&var1706,&var1753,&var1065};
_S_and2  S_and2_1252_1 = {&var1706,&var1861,&var1066};
_S_and2  S_and2_1251_1 = {&var1706,&var1136,&var1067};
_S_and2  S_and2_1249_1 = {&var1706,&var1064,&var1068};
_S_and2  S_and2_1239_1 = {&var1706,&var406,&var1069};
_S_and2  S_and2_1238_1 = {&var1125,&var1706,&var1070};
_S_and2  S_and2_1237_1 = {&var1706,&R3IS21LDU,&var1071};
_S_and2  S_and2_1240_1 = {&var1706,&var1928,&var1072};
_S_and2  S_and2_1210_1 = {&var494,&var1238,&var1073};
_S_and2  S_and2_1211_1 = {&var505,&var1236,&var1074};
_S_and2  S_and2_1212_1 = {&var499,&var1234,&var1075};
_S_and2  S_and2_1213_1 = {&var502,&var1232,&var1076};
_S_or2  S_or2_1195_1 = {&R0MD31LP1,&var1078,&var1077};
_S_and4  S_and4_1196_1 = {&var17,&var21,&var19,&var23,&var1078};
_S_or2  S_or2_1299_1 = {&var1706,&var1983,&var1079};
_S_or2  S_or2_1272_1 = {&var1756,&var1330,&var1080};
_S_or2  S_or2_1346_1 = {&var1797,&var1796,&var1081};
_S_or2  S_or2_1332_1 = {&var1806,&var1805,&var1082};
_S_or2  S_or2_1342_1 = {&var1219,&R0MD34LP1,&var1083};
_S_or2  S_or2_1316_1 = {&var1081,&var1861,&var1084};
_S_or2  S_or2_1314_1 = {&var1086,&var1084,&var1085};
_S_or2  S_or2_1315_1 = {&var1082,&var1861,&var1086};
_S_or4  S_or4_389_1 = {&var1833,&var1832,&var1834,&var1831,&var1087};
_S_or2  S_or2_740_1 = {&B5IS11LDU,&A5IS11LDU,&var1088};
_S_and2  S_and2_739_1 = {&var1093,&var1088,&var1089};
_S_or2  S_or2_738_1 = {&B6IS11LDU,&A6IS11LDU,&var1090};
_S_and2  S_and2_737_1 = {&var1093,&var1090,&var1091};
_S_or2  S_or2_736_1 = {&A4IS11LDU,&B4IS11LDU,&var1092};
_S_or2  S_or2_727_1 = {&var1095,&var1096,&var1093};
_S_and2  S_and2_733_1 = {&var1093,&var1092,&var1094};
_S_and2  S_and2_730_1 = {&var406,&var1106,&var1095};
_S_and2  S_and2_726_1 = {&var407,&var1099,&var1096};
_S_and2  S_and2_857_1 = {&var1859,&var1777,&var1097};
_S_and2  S_and2_853_1 = {&var1859,&var1778,&var1098};
_S_and3  S_and3_848_1 = {&var1859,&var407,&var1784,&var1099};
_S_or2  S_or2_856_1 = {&var1779,&var1773,&var1100};
_S_or2  S_or2_851_1 = {&var1777,&var1779,&var1101};
_S_or2  S_or2_847_1 = {&var1779,&var1778,&var1102};
_S_and2  S_and2_829_1 = {&var1773,&var1859,&var1103};
_S_or2  S_or2_823_1 = {&var1780,&var1781,&var1104};
_S_or2  S_or2_814_1 = {&var1838,&var1780,&var1105};
_S_and2  S_and2_813_1 = {&var1781,&var1860,&var1106};
_S_and2  S_and2_812_1 = {&var1838,&var1860,&var1107};
_S_and2  S_and2_841_1 = {&var497,&var1859,&var1108};
_S_and2  S_and2_821_1 = {&var497,&var1790,&var1109};
_S_and2  S_and2_839_1 = {&var1860,&var497,&var1110};
_S_or2  S_or2_833_1 = {&var1860,&var1859,&var1111};
_S_or3  S_or3_826_1 = {&var317,&var1114,&var1115,&var1112};
_S_or4  S_or4_825_1 = {&var1114,&var316,&var1116,&var1769,&var1113};
_S_or3  S_or3_816_1 = {&R4MD31LP2,&var1103,&var1107,&var1114};
_S_or2  S_or2_845_1 = {&var1858,&var1118,&var1115};
_S_or2  S_or2_844_1 = {&var1858,&var1117,&var1116};
_S_and2  S_and2_752_1 = {&var317,&var1772,&var1117};
_S_and3  S_and3_788_1 = {&var1771,&var1785,&var316,&var1118};
_S_and2  S_and2_793_1 = {&R5IS11LDU,&var1133,&var1119};
_S_and3  S_and3_791_1 = {&var1423,&R3IS21LDU,&var1133,&var1120};
_S_and2  S_and2_792_1 = {&R6IS21LDU,&var1133,&var1121};
_S_or2  S_or2_790_1 = {&B8IS22LDU,&A8IS22LDU,&var1122};
_S_and2  S_and2_789_1 = {&var1122,&var1133,&var1123};
_S_and2  S_and2_772_1 = {&var1133,&var1125,&var1124};
_S_or4  S_or4_773_1 = {&A0VN71LZ1,&B0VN71LZ1,&B0VN71LZ2,&A0VN71LZ2,&var1125};
_S_and2  S_and2_771_1 = {&var1130,&var1133,&var1126};
_S_and2  S_and2_758_1 = {&var1136,&var1133,&var1127};
_S_and2  S_and2_757_1 = {&var1861,&var1133,&var1128};
_S_or3  S_or3_756_1 = {&R0NE01LDU,&R0NE02LDU,&R0NE08LDU,&var1129};
_S_or2  S_or2_769_1 = {&R1IS21LDU,&R2IS21LDU,&var1130};
_S_and2  S_and2_755_1 = {&var1133,&var1129,&var1131};
_S_and2  S_and2_753_1 = {&var1839,&var1133,&var1132};
_S_or2  S_or2_743_1 = {&var1860,&var1859,&var1133};
_S_or2  S_or2_174_1 = {&var1429,&var1016,&var1134};
_S_or3  S_or3_164_1 = {&var826,&var1428,&var1236,&var1135};
_S_or2  S_or2_157_1 = {&var1702,&var645,&var1136};
_S_or3  S_or3_115_1 = {&var1393,&var632,&var633,&var1137};
_S_or2  S_or2_2230_1 = {&var595,&var472,&var1138};
_S_or3  S_or3_649_1 = {&var1140,&var1141,&var967,&var1139};
_S_and2  S_and2_633_1 = {&var1599,&var1143,&var1140};
_S_and2  S_and2_634_1 = {&var1599,&var1193,&var1141};
_S_or2  S_or2_63_1 = {&var1193,&var1143,&var1142};
_S_and2  S_and2_66_1 = {&var1144,&var1276,&var1143};
_S_and2  S_and2_65_1 = {&var1868,&var1277,&var1144};
_S_or2  S_or2_49_1 = {&A4IS21LDU,&B4IS21LDU,&var1145};
_S_or2  S_or2_35_1 = {&var1519,&var1516,&var1146};
_S_or2  S_or2_39_1 = {&var1519,&var1518,&var1147};
_S_or2  S_or2_20_1 = {&var1423,&var1378,&var1148};
_S_or2  S_or2_8_1 = {&var1878,&var1195,&var1149};
_S_or2  S_or2_14_1 = {&var1195,&var1879,&var1150};
_S_and3  S_and3_1117_1 = {&var507,&var1872,&var1170,&var1151};
_S_and3  S_and3_662_1 = {&var1170,&var510,&var1872,&var1152};
_S_and2  S_and2_1184_1 = {&var1216,&var1154,&var1153};
_S_or2  S_or2_1190_1 = {&var1879,&var1878,&var1154};
_S_or2  S_or2_1558_1 = {&var1880,&var1878,&var1155};
_S_and3  S_and3_1557_1 = {&var1214,&var1155,&var893,&var1156};
_S_or2  S_or2_1085_1 = {&var1880,&var1878,&var1157};
_S_and3  S_and3_1084_1 = {&var1214,&var1157,&var908,&var1158};
_S_or2  S_or2_620_1 = {&var1880,&var1878,&var1159};
_S_and3  S_and3_619_1 = {&var1214,&var1159,&var1600,&var1160};
_S_and2  S_and2_617_1 = {&var402,&var1600,&var1161};
_S_or2  S_or2_254_1 = {&var1880,&var1878,&var1162};
_S_and3  S_and3_253_1 = {&var1214,&var1162,&var1633,&var1163};
_S_and2  S_and2_251_1 = {&var1633,&var403,&var1164};
_S_and3  S_and3_974_1 = {&var1214,&var1167,&var933,&var1165};
_S_and2  S_and2_973_1 = {&var728,&var933,&var1166};
_S_or2  S_or2_975_1 = {&var1880,&var1878,&var1167};
_S_or2  S_or2_1453_1 = {&var1880,&var1878,&var1168};
_S_or2  S_or2_6_1 = {&var1879,&var1878,&var1169};
_S_or3  S_or3_5_1 = {&var1880,&var1879,&var1878,&var1170};
_S_or2  S_or2_832_1 = {&var1780,&var1782,&var1171};
_S_or2  S_or2_483_1 = {&var1861,&var1176,&var1172};
_S_or2  S_or2_461_1 = {&var1861,&var1177,&var1173};
_S_or4  S_or4_462_1 = {&var1173,&var1789,&var1788,&var1172,&var1174};
_S_and2  S_and2_453_1 = {&A8IS22LDU,&var1853,&var1175};
_S_or3  S_or3_433_1 = {&var1843,&var1841,&var1842,&var1176};
_S_or3  S_or3_417_1 = {&var1851,&var1850,&var1852,&var1177};
_S_and2  S_and2_819_1 = {&var1860,&var1782,&var1178};
_S_and2  S_and2_38_1 = {&var1516,&var1517,&var1179};
_S_and2  S_and2_150_1 = {&var1792,&var1416,&var1180};
_S_and2  S_and2_158_1 = {&var1794,&var1416,&var1181};
_S_and2  S_and2_161_1 = {&var1791,&var1416,&var1182};
_S_and2  S_and2_153_1 = {&var1416,&var1793,&var1183};
_S_and2  S_and2_479_1 = {&var1136,&var1845,&var1184};
_S_and2  S_and2_477_1 = {&B8IS22LDU,&var1845,&var1185};
_S_and2  S_and2_475_1 = {&A8IS22LDU,&var1845,&var1186};
_S_and2  S_and2_473_1 = {&R5IS11LDU,&var1845,&var1187};
_S_and2  S_and2_464_1 = {&var1787,&var1853,&var1188};
_S_and2  S_and2_452_1 = {&R5IS11LDU,&var1853,&var1189};
_S_and2  S_and2_456_1 = {&var1136,&var1853,&var1190};
_S_and2  S_and2_119_1 = {&var1195,&var631,&var1191};
_S_and2  S_and2_61_1 = {&var1869,&var1277,&var1192};
_S_and2  S_and2_62_1 = {&var1192,&var1275,&var1193};
_S_and2  S_and2_42_1 = {&var1517,&var1518,&var1194};
_S_and2  S_and2_11_1 = {&var1877,&var1509,&var1195};
_S_and2  S_and2_31_1 = {&var1440,&var496,&var1196};
_S_and2  S_and2_30_1 = {&var1336,&var1423,&var1197};
_S_and2  S_and2_29_1 = {&var1337,&var1423,&var1198};
_S_and2  S_and2_28_1 = {&var1338,&var1423,&var1199};
_S_and2  S_and2_27_1 = {&var1339,&var1423,&var1200};
_S_and2  S_and2_846_1 = {&var1776,&var1784,&var1201};
_S_and2  S_and2_828_1 = {&var1783,&var1860,&var1202};
_S_bol  S_bol_663_1 = {&var1997,&fRM_20_0,&var1203};
_S_bol  S_bol_657_1 = {&var1994,&fRM_20_0,&var1204};
_S_bol  S_bol_648_1 = {&var1994,&fRM_20_03,&var1205};
_S_bol  S_bol_644_1 = {&var1997,&fRM_20_03,&var1206};
_S_bol  S_bol_1104_1 = {&var1994,&fRM_20_03,&var1207};
_S_bol  S_bol_1111_1 = {&var1997,&fRM_20_03,&var1208};
_S_bol  S_bol_1580_1 = {&var1997,&fRM_20_03,&var1209};
_S_bol  S_bol_1582_1 = {&var1994,&fRM_20_03,&var1210};
_S_bol  S_bol_281_1 = {&var1994,&fRM_20_03,&var1211};
_S_bol  S_bol_285_1 = {&var1997,&fRM_20_03,&var1212};
_S_sr  S_sr_88_1 = {array_m88_x_1,&iRM_2_,&var1213};
_S_bol  S_bol_87_1 = {&var1213,&var450,&var1214};
_S_ma  S_ma_90_1 = {array_m90_x_1,&R0MW15IP1,&iRM_8_,&var1215};
_S_bol  S_bol_1185_1 = {&var1217,&fEM_R0UN80RDU,&var1216};
_S_sr  S_sr_1191_1 = {array_m1191_x_1,&iRM_2_,&var1217};
_S_ovbs  S_ovbs_2320_1 = {&lRM_1_,&fEM_A9UZ04RDU,&var1218,&internal1_m2320_tx};
_S_ovbs  S_ovbs_1341_1 = {&lRM_1_,&fEM_A4UZ04RDU,&var1219,&internal1_m1341_tx};
_S_zpfs  S_zpfs_1832_1 = {&var1747,&fEM_B8UL03RDU,&var1220,&internal1_m1832_tx,&internal1_m1832_y0};
_S_zpfs  S_zpfs_1306_1 = {&var1764,&fEM_B8UL03RDU,&var1221,&internal1_m1306_tx,&internal1_m1306_y0};
_S_ma  S_ma_1369_1 = {array_m1369_x_1,&var1716,&iRM_8_,&var1222};
_S_ma  S_ma_906_1 = {array_m906_x_1,&var1676,&iRM_8_,&var1223};
_S_ma  S_ma_1004_1 = {array_m1004_x_1,&var1567,&iRM_8_,&var1224};
_S_ma  S_ma_1482_1 = {array_m1482_x_1,&var1535,&iRM_8_,&var1225};
_S_ma  S_ma_548_1 = {array_m548_x_1,&var1596,&iRM_8_,&var1226};
_S_ma  S_ma_173_1 = {array_m173_x_1,&var1629,&iRM_8_,&var1227};
_S_zpfs  S_zpfs_1525_1 = {&var1552,&fEM_A3UL03RDU,&var1228,&internal1_m1525_tx,&internal1_m1525_y0};
_S_zpfs  S_zpfs_1052_1 = {&var1584,&fEM_A3UL03RDU,&var1229,&internal1_m1052_tx,&internal1_m1052_y0};
_S_zpfs  S_zpfs_1415_1 = {&var1734,&fEM_A2UL03RDU,&var1230,&internal1_m1415_tx,&internal1_m1415_y0};
_S_rs  S_rs_1209_1 = {&var1077,&var1076,&var1231,&vainSBool,&internal1_m1209_q0};
_S_rs  S_rs_1207_1 = {&var17,&var1239,&var1232,&vainSBool,&internal1_m1207_q0};
_S_rs  S_rs_1206_1 = {&var1077,&var1075,&var1233,&vainSBool,&internal1_m1206_q0};
_S_rs  S_rs_1204_1 = {&var19,&var1239,&var1234,&vainSBool,&internal1_m1204_q0};
_S_rs  S_rs_1203_1 = {&var1077,&var1074,&var1235,&vainSBool,&internal1_m1203_q0};
_S_rs  S_rs_1201_1 = {&var21,&var1239,&var1236,&vainSBool,&internal1_m1201_q0};
_S_rs  S_rs_1200_1 = {&var1077,&var1073,&var1237,&vainSBool,&internal1_m1200_q0};
_S_rs  S_rs_1198_1 = {&var23,&var1239,&var1238,&vainSBool,&internal1_m1198_q0};
_S_rs  S_rs_1197_1 = {&var1077,&var451,&var1239,&vainSBool,&internal1_m1197_q0};
_S_noto  S_noto_2140_1 = {&var696,&var1240};
_S_swtakt  S_swtakt_54_1 = {&var25,&var1241,&fEM_R0UL00RDU,&var1242,&internal1_m54_x0,&internal1_m54_tim};
_S_noto  S_noto_1183_1 = {&var1257,&var1243};
_S_noto  S_noto_1157_1 = {&var1255,&var1244};
_S_noto  S_noto_1169_1 = {&var1256,&var1245};
_S_rs  S_rs_1116_1 = {&var1258,&var834,&var1246,&vainSBool,&internal1_m1116_q0};
_S_swtakt  S_swtakt_1637_1 = {&var1371,&var1247,&fEM_R0UL00RDU,&var1248,&internal1_m1637_x0,&internal1_m1637_tim};
_S_swtakt  S_swtakt_1685_1 = {&var1374,&var1249,&fEM_R0UL00RDU,&var1250,&internal1_m1685_x0,&internal1_m1685_tim};
_S_swtakt  S_swtakt_1688_1 = {&var1512,&var1251,&fEM_R0UL00RDU,&var1252,&internal1_m1688_x0,&internal1_m1688_tim};
_S_swtakt  S_swtakt_2072_1 = {&var1364,&var1253,&fEM_R0UL00RDU,&var1254,&internal1_m2072_x0,&internal1_m2072_tim};
_S_rs  S_rs_1156_1 = {&var1329,&var822,&var1255,&vainSBool,&internal1_m1156_q0};
_S_rs  S_rs_1162_1 = {&var1329,&var823,&var1256,&vainSBool,&internal1_m1162_q0};
_S_rs  S_rs_1180_1 = {&var1329,&var824,&var1257,&vainSBool,&internal1_m1180_q0};
_S_rs  S_rs_1189_1 = {&var1329,&var825,&var1258,&vainSBool,&internal1_m1189_q0};
_S_noto  S_noto_1143_1 = {&var840,&var1259};
_S_noto  S_noto_1174_1 = {&var840,&var1260};
_S_noto  S_noto_1173_1 = {&var844,&var1261};
_S_rs  S_rs_1168_1 = {&var818,&var820,&var1262,&vainSBool,&internal1_m1168_q0};
_S_rs  S_rs_1182_1 = {&var1329,&var816,&var1263,&vainSBool,&internal1_m1182_q0};
_S_bol  S_bol_1165_1 = {&var1982,&var557,&var1264};
_S_bol  S_bol_1164_1 = {&var1985,&var557,&var1265};
_S_noto  S_noto_1123_1 = {&var1324,&var1266};
_S_bol  S_bol_1161_1 = {&var557,&var1982,&var1267};
_S_bol  S_bol_1160_1 = {&var557,&var1985,&var1268};
_S_noto  S_noto_1147_1 = {&var1325,&var1269};
_S_rs  S_rs_2158_1 = {&var701,&var692,&var1270,&vainSBool,&internal1_m2158_q0};
_S_rs  S_rs_2157_1 = {&var701,&var693,&var1271,&vainSBool,&internal1_m2157_q0};
_S_noto  S_noto_353_1 = {&var1048,&var1272};
_S_noto  S_noto_336_1 = {&var1041,&var1273};
_S_noto  S_noto_304_1 = {&var1060,&var1274};
_S_noto  S_noto_59_1 = {&var1286,&var1275};
_S_noto  S_noto_70_1 = {&var1308,&var1276};
_S_noto  S_noto_69_1 = {&var1239,&var1277};
_S_noto  S_noto_2152_1 = {&B2IS11LDU,&var1278};
_S_noto  S_noto_2150_1 = {&A2IS11LDU,&var1279};
_S_noto  S_noto_312_1 = {&var510,&var1280};
_S_noto  S_noto_2159_1 = {&B2IS11LDU,&var1281};
_S_noto  S_noto_2134_1 = {&A2IS11LDU,&var1282};
_S_noto  S_noto_299_1 = {&var1144,&var1283};
_S_noto  S_noto_357_1 = {&var1192,&var1284};
_S_bolz  S_bolz_361_1 = {&iRM_2_,&var1287,&var1285};
_S_provsbr  S_provsbr_356_1 = {&var1347,&var1004,&var1362,&var1379,&var1373,&var1368,&var1365,&var1363,&var1377,&var1372,&var1370,&var1366,&iRM_10_,array_m356_Tpr_1,array_m356_type_1,&var1286,&var1287,&var1288,&var1289,&var1290,&var1291,&var1292,&var1293,&var1294,&vainSBool,&internal1_m356_Step,array_m356_rz_1,&internal1_m356_TimS,&internal1_m356_FinPr0,&internal1_m356_ErrPr0,&internal1_m356_sbINI0,&internal1_m356_sbVuIS0,&internal1_m356_sb2UR0,&internal1_m356_sbNupIS0,&internal1_m356_sbVuRB0,&internal1_m356_MyFirstEnterFlag};
_S_orni  S_orni_360_1 = {array_m360_x_1,&iRM_5_,&vainSBool,&var1295};
_S_cntch  S_cntch_364_1 = {&var1295,&var1296,&internal1_m364_x0};
_S_bolz  S_bolz_338_1 = {&iRM_20_,&var1310,&var1297};
_S_equz_p  S_equz_p_337_1 = {&var1309,&iRM_0_,&var1298};
_S_decatron  S_decatron_321_1 = {&var1040,&var1299,&internal1_m321_TimS,&internal1_m321_pusk0};
_S_noto  S_noto_1120_1 = {&R2IS21LDU,&var1300};
_S_noto  S_noto_1114_1 = {&R1IS21LDU,&var1301};
_S_andn  S_andn_294_1 = {array_m294_x_1,&iRM_7_,&var1302};
_S_noto  S_noto_296_1 = {&R0MD33LP1,&var1303};
_S_noto  S_noto_306_1 = {&R2IS21LDU,&var1304};
_S_noto  S_noto_300_1 = {&R1IS21LDU,&var1305};
_S_noto  S_noto_291_1 = {&R1IS11LDU,&var1306};
_S_noto  S_noto_288_1 = {&R2IS11LDU,&var1307};
_S_provsbr  S_provsbr_298_1 = {&var1349,&var1057,&var1362,&var1379,&var1373,&var1368,&var1365,&var1363,&var1377,&var1372,&var1370,&var1366,&iRM_10_,array_m298_Tpr_1,array_m298_type_1,&var1308,&var1309,&var1310,&var1311,&var1312,&var1313,&var1314,&var1315,&var1316,&vainSBool,&internal1_m298_Step,array_m298_rz_1,&internal1_m298_TimS,&internal1_m298_FinPr0,&internal1_m298_ErrPr0,&internal1_m298_sbINI0,&internal1_m298_sbVuIS0,&internal1_m298_sb2UR0,&internal1_m298_sbNupIS0,&internal1_m298_sbVuRB0,&internal1_m298_MyFirstEnterFlag};
_S_rs  S_rs_1599_1 = {&var1318,&var815,&var1317,&vainSBool,&internal1_m1599_q0};
_S_provsbr  S_provsbr_1600_1 = {&var1317,&R0MD34LP1,&var1362,&var1379,&var1373,&var1368,&var1365,&var1363,&var1377,&var1372,&var1370,&var1366,&iRM_6_,array_m1600_Tpr_1,array_m1600_type_1,&var1318,&vainSInt,&vainSInt,&vainSBool,&var1319,&var1320,&var1321,&var1322,&var1323,&vainSBool,&internal1_m1600_Step,array_m1600_rz_1,&internal1_m1600_TimS,&internal1_m1600_FinPr0,&internal1_m1600_ErrPr0,&internal1_m1600_sbINI0,&internal1_m1600_sbVuIS0,&internal1_m1600_sb2UR0,&internal1_m1600_sbNupIS0,&internal1_m1600_sbVuRB0,&internal1_m1600_MyFirstEnterFlag};
_S_abs_subf  S_abs_subf_1126_1 = {&var557,&var1985,&fEM_B8UC01RDU,&vainSFloat,&var1324};
_S_abs_subf  S_abs_subf_1139_1 = {&var1982,&var557,&fEM_B8UC01RDU,&vainSFloat,&var1325};
_S_noto  S_noto_723_1 = {&var1008,&var1326};
_S_noto  S_noto_670_1 = {&var1024,&var1327};
_S_noto  S_noto_50_1 = {&var553,&var1328};
_S_noto  S_noto_1144_1 = {&var1524,&var1329};
_S_rs  S_rs_1152_1 = {&var817,&var646,&var1330,&vainSBool,&internal1_m1152_q0};
_S_rs  S_rs_1149_1 = {&var821,&var816,&var1331,&vainSBool,&internal1_m1149_q0};
_S_rs  S_rs_1151_1 = {&var1329,&var646,&var1332,&vainSBool,&internal1_m1151_q0};
_S_rs  S_rs_1145_1 = {&var1329,&var819,&var1333,&vainSBool,&internal1_m1145_q0};
_S_noto  S_noto_659_1 = {&A2IS21LDU,&var1334};
_S_noto  S_noto_661_1 = {&B2IS21LDU,&var1335};
_S_noto  S_noto_25_1 = {&B2IS21LDU,&var1336};
_S_noto  S_noto_24_1 = {&B1IS21LDU,&var1337};
_S_noto  S_noto_23_1 = {&A1IS21LDU,&var1338};
_S_noto  S_noto_22_1 = {&A2IS21LDU,&var1339};
_S_newstage  S_newstage_671_1 = {&var379,&var376,&A2IS12LDU,&B2IS12LDU,&var1340};
_S_noto  S_noto_660_1 = {&B2IS12LDU,&var1341};
_S_noto  S_noto_658_1 = {&A2IS12LDU,&var1342};
_S_noto  S_noto_370_1 = {&var999,&var1343};
_S_noto  S_noto_374_1 = {&var998,&var1344};
_S_noto  S_noto_1113_1 = {&var1136,&var1345};
_S_rs  S_rs_836_1 = {&var996,&var629,&var1346,&vainSBool,&internal1_m836_q0};
_S_rs  S_rs_366_1 = {&var1000,&var1001,&var1347,&vainSBool,&internal1_m366_q0};
_S_rs  S_rs_362_1 = {&var1002,&var1003,&var1348,&vainSBool,&internal1_m362_q0};
_S_rs  S_rs_318_1 = {&var1056,&var1042,&var1349,&vainSBool,&internal1_m318_q0};
_S_orni  S_orni_314_1 = {array_m314_x_1,&iRM_5_,&vainSBool,&var1350};
_S_cntch  S_cntch_317_1 = {&var1350,&var1351,&internal1_m317_x0};
_S_noto  S_noto_1650_1 = {&var1370,&var1352};
_S_noto  S_noto_1709_1 = {&var1372,&var1353};
_S_noto  S_noto_1711_1 = {&var1377,&var1354};
_S_noto  S_noto_2084_1 = {&var1363,&var1355};
_S_noto  S_noto_2116_1 = {&var1366,&var1356};
_S_noto  S_noto_2096_1 = {&var1367,&var1357};
_S_noto  S_noto_2069_1 = {&var1364,&var1358};
_S_noto  S_noto_1680_1 = {&var1512,&var1359};
_S_noto  S_noto_1672_1 = {&var1374,&var1360};
_S_noto  S_noto_1632_1 = {&var1371,&var1361};
_S_rs  S_rs_2087_1 = {&var801,&var650,&var1362,&vainSBool,&internal1_m2087_q0};
_S_rs  S_rs_2080_1 = {&var656,&var653,&var1363,&vainSBool,&internal1_m2080_q0};
_S_rs  S_rs_2073_1 = {&var652,&var657,&var1364,&vainSBool,&internal1_m2073_q0};
_S_rs  S_rs_2141_1 = {&var801,&var670,&var1365,&vainSBool,&internal1_m2141_q0};
_S_rs  S_rs_2112_1 = {&var678,&var677,&var1366,&vainSBool,&internal1_m2112_q0};
_S_rs  S_rs_2100_1 = {&var680,&var683,&var1367,&vainSBool,&internal1_m2100_q0};
_S_rs  S_rs_1664_1 = {&var801,&var787,&var1368,&vainSBool,&internal1_m1664_q0};
_S_kvf  S_kvf_1651_1 = {&var1248,&var788,&fRM_0_0,&var1369,&vainSInt,&vainSInt,&internal1_m1651_x0,&internal1_m1651_y0,&internal1_m1651_fef};
_S_rs  S_rs_1646_1 = {&var793,&var788,&var1370,&vainSBool,&internal1_m1646_q0};
_S_rs  S_rs_1636_1 = {&var790,&var794,&var1371,&vainSBool,&internal1_m1636_q0};
_S_rs  S_rs_1699_1 = {&var783,&var778,&var1372,&vainSBool,&internal1_m1699_q0};
_S_rs  S_rs_1720_1 = {&var801,&var784,&var1373,&vainSBool,&internal1_m1720_q0};
_S_rs  S_rs_1684_1 = {&var781,&var782,&var1374,&vainSBool,&internal1_m1684_q0};
_S_kvf  S_kvf_1700_1 = {&var30,&var778,&fRM_0_0,&var1375,&vainSInt,&vainSInt,&internal1_m1700_x0,&internal1_m1700_y0,&internal1_m1700_fef};
_S_cntch  S_cntch_1617_1 = {&var803,&var1376,&internal1_m1617_x0};
_S_rs  S_rs_1706_1 = {&var775,&var769,&var1377,&vainSBool,&internal1_m1706_q0};
_S_rs  S_rs_26_1 = {&var1423,&var1196,&var1378,&vainSBool,&internal1_m26_q0};
_S_rs  S_rs_1721_1 = {&var801,&var768,&var1379,&vainSBool,&internal1_m1721_q0};
_S_noto  S_noto_1588_1 = {&var797,&var1380};
_S_noto  S_noto_1586_1 = {&var1195,&var1381};
_S_rs  S_rs_711_1 = {&var1755,&var1011,&var1382,&vainSBool,&internal1_m711_q0};
_S_rs  S_rs_696_1 = {&var1755,&var1018,&var1383,&vainSBool,&internal1_m696_q0};
_S_rs  S_rs_724_1 = {&var1755,&var1019,&var1384,&vainSBool,&internal1_m724_q0};
_S_rs  S_rs_707_1 = {&var1755,&var1030,&var1385,&vainSBool,&internal1_m707_q0};
_S_rs  S_rs_691_1 = {&var1755,&var1033,&var1386,&vainSBool,&internal1_m691_q0};
_S_rs  S_rs_689_1 = {&var1755,&var1035,&var1387,&vainSBool,&internal1_m689_q0};
_S_rs  S_rs_677_1 = {&var1038,&var1758,&var1388,&vainSBool,&internal1_m677_q0};
_S_rsun  S_rsun_1602_1 = {&var801,&var1508,&vainSLong,&var1389,&internal1_m1602_q0};
_S_noto  S_noto_1510_1 = {&B3MD12LP1,&var1390};
_S_noto  S_noto_2043_1 = {&B3IS11LDU,&var1391};
_S_noto  S_noto_2017_1 = {&A3IS11LDU,&var1392};
_S_noto  S_noto_118_1 = {&var1195,&var1393};
_S_noto  S_noto_117_1 = {&var1398,&var1394};
_S_rs  S_rs_687_1 = {&var1755,&var1037,&var1395,&vainSBool,&internal1_m687_q0};
_S_orni  S_orni_1340_1 = {array_m1340_x_1,&iRM_5_,&var1396,&vainSLong};
_S_orni  S_orni_1328_1 = {array_m1328_x_1,&iRM_4_,&var1397,&vainSLong};
_S_rs  S_rs_116_1 = {&var1137,&var1191,&var1398,&vainSBool,&internal1_m116_q0};
_S_noto  S_noto_2046_1 = {&var719,&var1399};
_S_noto  S_noto_2045_1 = {&var718,&var1400};
_S_noto  S_noto_2057_1 = {&B3IS22LDU,&var1401};
_S_noto  S_noto_2039_1 = {&A3IS22LDU,&var1402};
_S_newstage  S_newstage_2041_1 = {&var735,&var731,&var734,&var730,&vainSBool};
_S_noto  S_noto_1985_1 = {&var1486,&var1403};
_S_rs  S_rs_1867_1 = {&var293,&var521,&var1404,&vainSBool,&internal1_m1867_q0};
_S_rs  S_rs_1866_1 = {&var286,&var523,&var1405,&vainSBool,&internal1_m1866_q0};
_S_rs  S_rs_1865_1 = {&var292,&var525,&var1406,&vainSBool,&internal1_m1865_q0};
_S_rs  S_rs_1864_1 = {&var268,&var527,&var1407,&vainSBool,&internal1_m1864_q0};
_S_rs  S_rs_1900_1 = {&var496,&var529,&var1408,&vainSBool,&internal1_m1900_q0};
_S_rs  S_rs_1899_1 = {&var304,&var532,&var1409,&vainSBool,&internal1_m1899_q0};
_S_rs  S_rs_1898_1 = {&var305,&var532,&var1410,&vainSBool,&internal1_m1898_q0};
_S_noto  S_noto_1400_1 = {&A2MD12LP1,&var1411};
_S_noto  S_noto_1382_1 = {&B2MD12LP1,&var1412};
_S_noto  S_noto_563_1 = {&B1MD12LP1,&var1413};
_S_ma  S_ma_1653_1 = {array_m1653_x_1,&var1389,&iRM_16_,&var1414};
_S_noto  S_noto_1596_1 = {&var1052,&var1415};
_S_noto  S_noto_148_1 = {&var1195,&var1416};
_S_equz_p  S_equz_p_2023_1 = {&R0MW14IP2,&iRM_5_,&var1417};
_S_equz_p  S_equz_p_2022_1 = {&R0MW14IP2,&iRM_4_,&var1418};
_S_equz_p  S_equz_p_2021_1 = {&R0MW14IP2,&iRM_3_,&var1419};
_S_equz_p  S_equz_p_2019_1 = {&R0MW14IP2,&iRM_1_,&vainSBool};
_S_equz_p  S_equz_p_2020_1 = {&R0MW14IP2,&iRM_2_,&var1420};
_S_noto  S_noto_2105_1 = {&B2IS11LDU,&var1421};
_S_noto  S_noto_2113_1 = {&A2IS11LDU,&var1422};
_S_noto  S_noto_12_1 = {&var1877,&var1423};
_S_rs  S_rs_2172_1 = {&var615,&var705,&var1424,&vainSBool,&internal1_m2172_q0};
_S_rs  S_rs_1960_1 = {&var747,&var542,&var1425,&vainSBool,&internal1_m1960_q0};
_S_rs  S_rs_1950_1 = {&var289,&var543,&var1426,&vainSBool,&internal1_m1950_q0};
_S_rs  S_rs_1957_1 = {&var306,&var544,&var1427,&vainSBool,&internal1_m1957_q0};
_S_rs  S_rs_1947_1 = {&var290,&var545,&var1428,&vainSBool,&internal1_m1947_q0};
_S_rs  S_rs_1954_1 = {&var310,&var546,&var1429,&vainSBool,&internal1_m1954_q0};
_S_equz_p  S_equz_p_105_1 = {&R0MW16IP1,&iRM_10_,&var1430};
_S_noto  S_noto_186_1 = {&A1MD12LP1,&var1431};
_S_rs  S_rs_2388_1 = {&var280,&var277,&var1432,&vainSBool,&internal1_m2388_q0};
_S_rs  S_rs_2384_1 = {&var296,&var368,&var1433,&vainSBool,&internal1_m2384_q0};
_S_rs  S_rs_1925_1 = {&var309,&var539,&var1434,&vainSBool,&internal1_m1925_q0};
_S_rs  S_rs_1917_1 = {&var496,&var528,&var1435,&vainSBool,&internal1_m1917_q0};
_S_rs  S_rs_1915_1 = {&var291,&var529,&var1436,&vainSBool,&internal1_m1915_q0};
_S_rs  S_rs_1911_1 = {&var304,&var530,&var1437,&vainSBool,&internal1_m1911_q0};
_S_rs  S_rs_1907_1 = {&var266,&var532,&var1438,&vainSBool,&internal1_m1907_q0};
_S_rs  S_rs_1909_1 = {&var305,&var531,&var1439,&vainSBool,&internal1_m1909_q0};
_S_rs  S_rs_19_1 = {&var1148,&var635,&var1440,&vainSBool,&internal1_m19_q0};
_S_equz_p  S_equz_p_104_1 = {&R0MW16IP1,&iRM_9_,&var1441};
_S_equz_p  S_equz_p_103_1 = {&R0MW16IP1,&iRM_8_,&var1442};
_S_noto  S_noto_1036_1 = {&A3MD12LP1,&var1443};
_S_equz_p  S_equz_p_102_1 = {&R0MW16IP1,&iRM_7_,&var1444};
_S_equz_p  S_equz_p_101_1 = {&R0MW16IP1,&iRM_6_,&var1445};
_S_equz_p  S_equz_p_100_1 = {&R0MW16IP1,&iRM_5_,&var1446};
_S_rs  S_rs_1890_1 = {&var293,&var520,&var1447,&vainSBool,&internal1_m1890_q0};
_S_rs  S_rs_1888_1 = {&var285,&var521,&var1448,&vainSBool,&internal1_m1888_q0};
_S_rs  S_rs_1884_1 = {&var303,&var523,&var1449,&vainSBool,&internal1_m1884_q0};
_S_rs  S_rs_1886_1 = {&var286,&var522,&var1450,&vainSBool,&internal1_m1886_q0};
_S_rs  S_rs_1882_1 = {&var292,&var524,&var1451,&vainSBool,&internal1_m1882_q0};
_S_rs  S_rs_1880_1 = {&var269,&var525,&var1452,&vainSBool,&internal1_m1880_q0};
_S_rs  S_rs_2294_1 = {&var383,&var714,&var1453,&vainSBool,&internal1_m2294_q0};
_S_rs  S_rs_2292_1 = {&var384,&var715,&var1454,&vainSBool,&internal1_m2292_q0};
_S_equz_p  S_equz_p_327_1 = {&var1299,&iRM_0_,&var1455};
_S_noto  S_noto_2295_1 = {&var1453,&var1456};
_S_noto  S_noto_2287_1 = {&var639,&var1457};
_S_noto  S_noto_2270_1 = {&var1459,&var1458};
_S_rs  S_rs_2269_1 = {&var323,&var711,&var1459,&vainSBool,&internal1_m2269_q0};
_S_noto  S_noto_2254_1 = {&var1461,&var1460};
_S_rs  S_rs_2253_1 = {&var325,&var708,&var1461,&vainSBool,&internal1_m2253_q0};
_S_noto  S_noto_2293_1 = {&var1454,&var1462};
_S_noto  S_noto_2285_1 = {&var638,&var1463};
_S_noto  S_noto_2185_1 = {&var1465,&var1464};
_S_rs  S_rs_2184_1 = {&var614,&var706,&var1465,&vainSBool,&internal1_m2184_q0};
_S_noto  S_noto_2173_1 = {&var1424,&var1466};
_S_noto  S_noto_2180_1 = {&var636,&var1467};
_S_noto  S_noto_2167_1 = {&var637,&var1468};
_S_rs  S_rs_1876_1 = {&var302,&var527,&var1469,&vainSBool,&internal1_m1876_q0};
_S_rs  S_rs_1878_1 = {&var268,&var526,&var1470,&vainSBool,&internal1_m1878_q0};
_S_rs  S_rs_1862_1 = {&var283,&var512,&var1471,&vainSBool,&internal1_m1862_q0};
_S_rs  S_rs_1860_1 = {&var301,&var513,&var1472,&vainSBool,&internal1_m1860_q0};
_S_rs  S_rs_1858_1 = {&var282,&var514,&var1473,&vainSBool,&internal1_m1858_q0};
_S_rs  S_rs_1856_1 = {&var300,&var515,&var1474,&vainSBool,&internal1_m1856_q0};
_S_noto  S_noto_1980_1 = {&B3IS22LDU,&var1475};
_S_noto  S_noto_1979_1 = {&A3IS22LDU,&var1476};
_S_noto  S_noto_1978_1 = {&B2IS12LDU,&var1477};
_S_noto  S_noto_1977_1 = {&A2IS12LDU,&var1478};
_S_noto  S_noto_1976_1 = {&B1IS12LDU,&var1479};
_S_noto  S_noto_1975_1 = {&A1IS12LDU,&var1480};
_S_noto  S_noto_2005_1 = {&B3IS21LDU,&var1481};
_S_noto  S_noto_1999_1 = {&B2IS21LDU,&var1482};
_S_noto  S_noto_2004_1 = {&A3IS21LDU,&var1483};
_S_noto  S_noto_2002_1 = {&B4IS21LDU,&var1484};
_S_noto  S_noto_2003_1 = {&A4IS21LDU,&var1485};
_S_andn  S_andn_1988_1 = {array_m1988_x_1,&iRM_17_,&var1486};
_S_noto  S_noto_1997_1 = {&B1IS21LDU,&var1487};
_S_noto  S_noto_1998_1 = {&A2IS21LDU,&var1488};
_S_noto  S_noto_1996_1 = {&A1IS21LDU,&var1489};
_S_rs  S_rs_1855_1 = {&var1494,&var516,&var1490,&vainSBool,&internal1_m1855_q0};
_S_rs  S_rs_1853_1 = {&var284,&var517,&var1491,&vainSBool,&internal1_m1853_q0};
_S_rs  S_rs_1852_1 = {&var1494,&var518,&var1492,&vainSBool,&internal1_m1852_q0};
_S_rs  S_rs_1850_1 = {&var267,&var519,&var1493,&vainSBool,&internal1_m1850_q0};
_S_newstage  S_newstage_2323_1 = {&var1506,&var1500,&var1505,&var1499,&var1494};
_S_samhd  S_samhd_2325_1 = {&var759,&var760,&var760,&var1491,&var1490,&var1491,&var1490,&B9IS11LDU,&B9IS11LDU,&B9IS21LDU,&B9IS21LDU,&bRM_1_,&fEM_A9UZ05RDU,&fEM_A9UZ03RDU,&fEM_A9UZ04RDU,&var1495,&var1496,&var1497,&vainSBool,&var1498,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1499,&var1500,&internal1_m2325_DvUp0,&internal1_m2325_DvDw0,&internal1_m2325_FDvUp0,&internal1_m2325_FDvDw0,&internal1_m2325_BlDv0,&internal1_m2325_Pkv0,&internal1_m2325_Pkav0,&internal1_m2325_Zkv0,&internal1_m2325_Zkav0,&internal1_m2325_txNm,&internal1_m2325_txSm,&internal1_m2325_txHr,&internal1_m2325_txLd,&internal1_m2325_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_2319_1 = {&var759,&var761,&var761,&var1493,&var1492,&var1493,&var1492,&A9IS11LDU,&A9IS11LDU,&A9IS21LDU,&A9IS21LDU,&bRM_1_,&fEM_A9UZ05RDU,&fEM_A9UZ03RDU,&fEM_A9UZ04RDU,&var1501,&var1502,&var1503,&vainSBool,&var1504,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1505,&var1506,&internal1_m2319_DvUp0,&internal1_m2319_DvDw0,&internal1_m2319_FDvUp0,&internal1_m2319_FDvDw0,&internal1_m2319_BlDv0,&internal1_m2319_Pkv0,&internal1_m2319_Pkav0,&internal1_m2319_Zkv0,&internal1_m2319_Zkav0,&internal1_m2319_txNm,&internal1_m2319_txSm,&internal1_m2319_txHr,&internal1_m2319_txLd,&internal1_m2319_fef,&bFirstEnterFlag};
_S_orni  S_orni_1604_1 = {array_m1604_x_1,&iRM_5_,&var1507,&var1508};
_S_noto  S_noto_83_1 = {&var640,&var1509};
_S_maz  S_maz_333_1 = {array_m333_x_1,&R0MW12IP1,&iRM_3_,&var1510};
_S_maz  S_maz_324_1 = {array_m324_x_1,&R0MW12IP1,&iRM_3_,&var1511};
_S_rs  S_rs_1679_1 = {&var772,&var776,&var1512,&vainSBool,&internal1_m1679_q0};
_S_kvf  S_kvf_1705_1 = {&var1251,&var769,&fRM_0_0,&var1513,&vainSInt,&vainSInt,&internal1_m1705_x0,&internal1_m1705_y0,&internal1_m1705_fef};
_S_kvf  S_kvf_2123_1 = {&var686,&var674,&fRM_0_0,&var1514,&vainSInt,&vainSInt,&internal1_m2123_x0,&internal1_m2123_y0,&internal1_m2123_fef};
_S_kvf  S_kvf_2082_1 = {&var1253,&var44,&fRM_0_0,&var1515,&vainSInt,&vainSInt,&internal1_m2082_x0,&internal1_m2082_y0,&internal1_m2082_fef};
_S_equz_p  S_equz_p_37_1 = {&R0MW13IP1,&iRM_1_,&var1516};
_S_noto  S_noto_34_1 = {&var1519,&var1517};
_S_equz_p  S_equz_p_41_1 = {&R0MW13IP1,&iRM_2_,&var1518};
_S_equz_p  S_equz_p_32_1 = {&R0MW13IP1,&iRM_3_,&var1519};
_S_noto  S_noto_2125_1 = {&var28,&var1520};
_S_rs  S_rs_309_1 = {&var1058,&var1059,&var1521,&vainSBool,&internal1_m309_q0};
_S_orn  S_orn_668_1 = {array_m668_x_1,&iRM_5_,&var1522};
_S_noto  S_noto_1133_1 = {&lEM_R0MD01LC1,&var1523};
_S_rs  S_rs_1124_1 = {&var835,&var1151,&var1524,&vainSBool,&internal1_m1124_q0};
_S_rs  S_rs_699_1 = {&var1013,&var1015,&var1525,&vainSBool,&internal1_m699_q0};
_S_noto  S_noto_1584_1 = {&var1194,&var1526};
_S_orn  S_orn_1553_1 = {array_m1553_x_1,&iRM_8_,&var1527};
_S_noto  S_noto_1552_1 = {&var1695,&var1528};
_S_noto  S_noto_1551_1 = {&var1705,&var1529};
_S_noto  S_noto_1530_1 = {&var1195,&var1530};
_S_noto  S_noto_1543_1 = {&R8IS11LDU,&var1531};
_S_charint  S_charint_1475_1 = {&var1534,&var1532};
_S_ornc  S_ornc_1481_1 = {array_m1481_x_1,&iRM_3_,&var1533,&var1534};
_S_fsumz  S_fsumz_1476_1 = {&var1532,&iRM_1_,&var1535};
_S_cnshd  S_cnshd_1483_1 = {&R0MD34LP1,&var1988,&var1225,&var561,&var1533,&var880,&var876,&iRM_1_,array_m1483_Lt_fw_1,array_m1483_Vr_fw_1,&iRM_1_,array_m1483_Lt_bw_1,array_m1483_Vr_bw_1,&fEM_A3UC08RDU,&fEM_A3UC07RDU,&fEM_A3UL01RDU,&fEM_A3UC02RDU,&var1536,&vainSBool,&var1537,&var1538,&var1539,&var1540,&var1541,&var1542,&var1543,&var1544,&var1545,&var1546,&internal1_m1483_X0,&internal1_m1483_t0,&internal1_m1483_BLDv0};
_S_zpfs  S_zpfs_1500_1 = {&var1555,&fRM_2_0,&var1547,&internal1_m1500_tx,&internal1_m1500_y0};
_S_zpfs  S_zpfs_1501_1 = {&var1554,&fRM_3_0,&var1548,&internal1_m1501_tx,&internal1_m1501_y0};
_S_fnapb  S_fnapb_1509_1 = {&var1988,&var1225,&var879,&R0MD34LP1,&var1538,&var1545,&fEM_B8UV04RDU,&fEM_A3UV01RDU,&fEM_A3UV02RDU,&fEM_A3UC06RDU,&fEM_A3UC05RDU,&iRM_60_,&fEM_A3UL04RDU,&fEM_A3UL05RDU,&fEM_A3UL03RDU,&var1549,&var1550,&var1551,&var1552,&var1553,&var1554,&var1555,&vainSFloat,&internal1_m1509_xptr,array_m1509_x0_1,array_m1509_tim0_1,&internal1_m1509_sumtim,&internal1_m1509_StSpeed,&internal1_m1509_Vz0,&internal1_m1509_flRazg,&internal1_m1509_DelSp,&internal1_m1509_z0,&internal1_m1509_txZS,&internal1_m1509_tx,&internal1_m1509_txd,&internal1_m1509_txMBl,&internal1_m1509_txBl,&internal1_m1509_Speed0,&internal1_m1509_xz0,&internal1_m1509_tz0,&internal1_m1509_Shift0,&internal1_m1509_ShCntlSp0,&internal1_m1509_ShiftControl,&bFirstEnterFlag};
_S_newstage  S_newstage_1017_1 = {&var1565,&var1533,&var1568,&var1536,&var1556};
_S_rs  S_rs_697_1 = {&var1014,&var1018,&var1557,&vainSBool,&internal1_m697_q0};
_S_noto  S_noto_1110_1 = {&var1179,&var1558};
_S_orn  S_orn_1082_1 = {array_m1082_x_1,&iRM_8_,&var1559};
_S_noto  S_noto_1081_1 = {&var1695,&var1560};
_S_noto  S_noto_1080_1 = {&var1705,&var1561};
_S_noto  S_noto_1059_1 = {&var1195,&var1562};
_S_noto  S_noto_1070_1 = {&R8IS11LDU,&var1563};
_S_charint  S_charint_994_1 = {&var1566,&var1564};
_S_ornc  S_ornc_1003_1 = {array_m1003_x_1,&iRM_3_,&var1565,&var1566};
_S_fsumz  S_fsumz_995_1 = {&var1564,&iRM_1_,&var1567};
_S_cnshd  S_cnshd_1005_1 = {&R0MD34LP1,&var1991,&var1224,&var565,&var1565,&var915,&var916,&iRM_1_,array_m1005_Lt_fw_1,array_m1005_Vr_fw_1,&iRM_1_,array_m1005_Lt_bw_1,array_m1005_Vr_bw_1,&fEM_A3UC08RDU,&fEM_A3UC07RDU,&fEM_A3UL01RDU,&fEM_A3UC02RDU,&var1568,&vainSBool,&var1569,&var1570,&var1571,&var1572,&var1573,&var1574,&var1575,&var1576,&var1577,&var1578,&internal1_m1005_X0,&internal1_m1005_t0,&internal1_m1005_BLDv0};
_S_zpfs  S_zpfs_1028_1 = {&var1587,&fRM_2_0,&var1579,&internal1_m1028_tx,&internal1_m1028_y0};
_S_zpfs  S_zpfs_1027_1 = {&var1586,&fRM_3_0,&var1580,&internal1_m1027_tx,&internal1_m1027_y0};
_S_fnapb  S_fnapb_1035_1 = {&var1991,&var1224,&var914,&R0MD34LP1,&var1570,&var1577,&fEM_B8UV04RDU,&fEM_A3UV01RDU,&fEM_A3UV02RDU,&fEM_A3UC06RDU,&fEM_A3UC05RDU,&iRM_60_,&fEM_A3UL04RDU,&fEM_A3UL05RDU,&fEM_A3UL03RDU,&var1581,&var1582,&var1583,&var1584,&var1585,&var1586,&var1587,&vainSFloat,&internal1_m1035_xptr,array_m1035_x0_1,array_m1035_tim0_1,&internal1_m1035_sumtim,&internal1_m1035_StSpeed,&internal1_m1035_Vz0,&internal1_m1035_flRazg,&internal1_m1035_DelSp,&internal1_m1035_z0,&internal1_m1035_txZS,&internal1_m1035_tx,&internal1_m1035_txd,&internal1_m1035_txMBl,&internal1_m1035_txBl,&internal1_m1035_Speed0,&internal1_m1035_xz0,&internal1_m1035_tz0,&internal1_m1035_Shift0,&internal1_m1035_ShCntlSp0,&internal1_m1035_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_650_1 = {&var1194,&var1588};
_S_noto  S_noto_615_1 = {&var1695,&var1589};
_S_noto  S_noto_614_1 = {&var1705,&var1590};
_S_noto  S_noto_593_1 = {&var1195,&var1591};
_S_noto  S_noto_603_1 = {&R8IS11LDU,&var1592};
_S_charint  S_charint_541_1 = {&var1595,&var1593};
_S_ornc  S_ornc_547_1 = {array_m547_x_1,&iRM_3_,&var1594,&var1595};
_S_fsumz  S_fsumz_542_1 = {&var1593,&iRM_1_,&var1596};
_S_cnshd  S_cnshd_550_1 = {&R0MD34LP1,&var2001,&var1226,&var569,&var1594,&var986,&var980,&iRM_2_,array_m550_Lt_fw_1,array_m550_Vr_fw_1,&iRM_1_,array_m550_Lt_bw_1,array_m550_Vr_bw_1,&fEM_A1UC08RDU,&fEM_A1UC07RDU,&fEM_A1UL01RDU,&fEM_A1UC02RDU,&var1597,&vainSBool,&var1598,&var1599,&var1600,&var1601,&var1602,&var1603,&var1604,&var1605,&var1606,&var1607,&internal1_m550_X0,&internal1_m550_t0,&internal1_m550_BLDv0};
_S_zpfs  S_zpfs_569_1 = {&var1616,&fRM_2_0,&var1608,&internal1_m569_tx,&internal1_m569_y0};
_S_zpfs  S_zpfs_568_1 = {&var1615,&fRM_3_0,&var1609,&internal1_m568_tx,&internal1_m568_y0};
_S_fnapb  S_fnapb_573_1 = {&var2001,&var1226,&var984,&R0MD34LP1,&var1599,&var1606,&fEM_B8UV04RDU,&fEM_A1UV01RDU,&fEM_A1UV02RDU,&fEM_A1UC06RDU,&fEM_A1UC05RDU,&iRM_150_,&fEM_A1UL04RDU,&fEM_A1UL05RDU,&fEM_A1UL03RDU,&var1610,&var1611,&var1612,&var1613,&var1614,&var1615,&var1616,&vainSFloat,&internal1_m573_xptr,array_m573_x0_1,array_m573_tim0_1,&internal1_m573_sumtim,&internal1_m573_StSpeed,&internal1_m573_Vz0,&internal1_m573_flRazg,&internal1_m573_DelSp,&internal1_m573_z0,&internal1_m573_txZS,&internal1_m573_tx,&internal1_m573_txd,&internal1_m573_txMBl,&internal1_m573_txBl,&internal1_m573_Speed0,&internal1_m573_xz0,&internal1_m573_tz0,&internal1_m573_Shift0,&internal1_m573_ShCntlSp0,&internal1_m573_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_715_1 = {&R0MD33LP1,&var1617};
_S_noto  S_noto_287_1 = {&var1179,&var1618};
_S_newstage  S_newstage_211_1 = {&var1627,&var1594,&var1630,&var1597,&var1619};
_S_rs  S_rs_694_1 = {&var1009,&var1021,&var1620,&vainSBool,&internal1_m694_q0};
_S_orn  S_orn_250_1 = {array_m250_x_1,&iRM_12_,&var1621};
_S_noto  S_noto_249_1 = {&var1695,&var1622};
_S_noto  S_noto_248_1 = {&var1705,&var1623};
_S_noto  S_noto_226_1 = {&var1195,&var1624};
_S_noto  S_noto_237_1 = {&R8IS11LDU,&var1625};
_S_charint  S_charint_165_1 = {&var1628,&var1626};
_S_ornc  S_ornc_172_1 = {array_m172_x_1,&iRM_3_,&var1627,&var1628};
_S_fsumz  S_fsumz_166_1 = {&var1626,&iRM_1_,&var1629};
_S_cnshd  S_cnshd_176_1 = {&R0MD34LP1,&var1979,&var1227,&var573,&var1627,&var966,&var959,&iRM_2_,array_m176_Lt_fw_1,array_m176_Vr_fw_1,&iRM_1_,array_m176_Lt_bw_1,array_m176_Vr_bw_1,&fEM_A1UC08RDU,&fEM_A1UC07RDU,&fEM_A1UL01RDU,&fEM_A1UC02RDU,&var1630,&vainSBool,&var1631,&var1632,&var1633,&var1634,&var1635,&var1636,&var1637,&var1638,&var1639,&var1640,&internal1_m176_X0,&internal1_m176_t0,&internal1_m176_BLDv0};
_S_fnapb  S_fnapb_201_1 = {&var1979,&var1227,&var962,&R0MD34LP1,&var1632,&var1639,&fEM_B8UV04RDU,&fEM_A1UV01RDU,&fEM_A1UV02RDU,&fEM_A1UC06RDU,&fEM_A1UC05RDU,&iRM_150_,&fEM_A1UL04RDU,&fEM_A1UL05RDU,&fEM_A1UL03RDU,&var1641,&var1642,&var1643,&var1644,&var1645,&var1646,&var1647,&vainSFloat,&internal1_m201_xptr,array_m201_x0_1,array_m201_tim0_1,&internal1_m201_sumtim,&internal1_m201_StSpeed,&internal1_m201_Vz0,&internal1_m201_flRazg,&internal1_m201_DelSp,&internal1_m201_z0,&internal1_m201_txZS,&internal1_m201_tx,&internal1_m201_txd,&internal1_m201_txMBl,&internal1_m201_txBl,&internal1_m201_Speed0,&internal1_m201_xz0,&internal1_m201_tz0,&internal1_m201_Shift0,&internal1_m201_ShCntlSp0,&internal1_m201_ShiftControl,&bFirstEnterFlag};
_S_rs  S_rs_720_1 = {&var1020,&var1023,&var1648,&vainSBool,&internal1_m720_q0};
_S_newstage  S_newstage_513_1 = {&var1667,&var1658,&var1666,&var1657,&var1649};
_S_samhd  S_samhd_517_1 = {&R0MD34LP1,&var989,&var989,&var623,&var622,&R2VS12LDU,&R2VS22LDU,&R2IS11LDU,&R2IS11LDU,&R2IS21LDU,&R2IS21LDU,&bRM_0_,&fEM_R1UZ05RDU,&fEM_R1UZ03RDU,&fEM_R1UZ04RDU,&var1650,&var1651,&var1652,&var1653,&var1654,&var1655,&vainSBool,&vainSBool,&var1656,&var1657,&var1658,&internal1_m517_DvUp0,&internal1_m517_DvDw0,&internal1_m517_FDvUp0,&internal1_m517_FDvDw0,&internal1_m517_BlDv0,&internal1_m517_Pkv0,&internal1_m517_Pkav0,&internal1_m517_Zkv0,&internal1_m517_Zkav0,&internal1_m517_txNm,&internal1_m517_txSm,&internal1_m517_txHr,&internal1_m517_txLd,&internal1_m517_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_511_1 = {&R0MD34LP1,&var990,&var990,&var621,&var620,&R1VS12LDU,&R1VS22LDU,&R1IS11LDU,&R1IS11LDU,&R1IS21LDU,&R1IS21LDU,&bRM_0_,&fEM_R1UZ05RDU,&fEM_R1UZ03RDU,&fEM_R1UZ04RDU,&var1659,&var1660,&var1661,&var1662,&var1663,&var1664,&vainSBool,&vainSBool,&var1665,&var1666,&var1667,&internal1_m511_DvUp0,&internal1_m511_DvDw0,&internal1_m511_FDvUp0,&internal1_m511_FDvDw0,&internal1_m511_BlDv0,&internal1_m511_Pkv0,&internal1_m511_Pkav0,&internal1_m511_Zkv0,&internal1_m511_Zkav0,&internal1_m511_txNm,&internal1_m511_txSm,&internal1_m511_txHr,&internal1_m511_txLd,&internal1_m511_fef,&bFirstEnterFlag};
_S_orn  S_orn_968_1 = {array_m968_x_1,&iRM_10_,&var1668};
_S_noto  S_noto_972_1 = {&var1695,&var1669};
_S_noto  S_noto_971_1 = {&var1705,&var1670};
_S_noto  S_noto_947_1 = {&var1195,&var1671};
_S_noto  S_noto_959_1 = {&R8IS11LDU,&var1672};
_S_charint  S_charint_899_1 = {&var1675,&var1673};
_S_ornc  S_ornc_905_1 = {array_m905_x_1,&iRM_3_,&var1674,&var1675};
_S_fsumz  S_fsumz_900_1 = {&var1673,&iRM_1_,&var1676};
_S_cnshd  S_cnshd_909_1 = {&R0MD34LP1,&var1994,&var1223,&var1223,&var1674,&var939,&var853,&iRM_2_,array_m909_Lt_fw_1,array_m909_Vr_fw_1,&iRM_1_,array_m909_Lt_bw_1,array_m909_Vr_bw_1,&fEM_A2UC08RDU,&fEM_A2UC07RDU,&fEM_A2UL01RDU,&fEM_A2UC02RDU,&var1677,&vainSBool,&var1678,&var1679,&var1680,&var1681,&var1682,&var1683,&var1684,&var1685,&var1686,&var1687,&internal1_m909_X0,&internal1_m909_t0,&internal1_m909_BLDv0};
_S_fnapb  S_fnapb_927_1 = {&var1994,&var1223,&var935,&R0MD34LP1,&var1679,&var1686,&fEM_B8UV04RDU,&fEM_A2UV01RDU,&fEM_A2UV02RDU,&fEM_A2UC06RDU,&fEM_A2UC05RDU,&iRM_80_,&fEM_A2UL04RDU,&fEM_A2UL05RDU,&fEM_A2UL83RDU,&var1688,&var1689,&var1690,&var1691,&var1692,&var1693,&var1694,&vainSFloat,&internal1_m927_xptr,array_m927_x0_1,array_m927_tim0_1,&internal1_m927_sumtim,&internal1_m927_StSpeed,&internal1_m927_Vz0,&internal1_m927_flRazg,&internal1_m927_DelSp,&internal1_m927_z0,&internal1_m927_txZS,&internal1_m927_tx,&internal1_m927_txd,&internal1_m927_txMBl,&internal1_m927_txBl,&internal1_m927_Speed0,&internal1_m927_xz0,&internal1_m927_tz0,&internal1_m927_Shift0,&internal1_m927_ShCntlSp0,&internal1_m927_ShiftControl,&bFirstEnterFlag};
_S_cnshd  S_cnshd_1804_1 = {&R0MD34LP1,&var1985,&var557,&var557,&var763,&var766,&lRM_1_,&iRM_1_,array_m1804_Lt_fw_1,array_m1804_Vr_fw_1,&iRM_1_,array_m1804_Lt_bw_1,array_m1804_Vr_bw_1,&fEM_B8UC01RDU,&fEM_B8UC02RDU,&fEM_B8UL01RDU,&fRM_0_0,&var1695,&vainSBool,&vainSFloat,&var1696,&var1697,&var1698,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1699,&internal1_m1804_X0,&internal1_m1804_t0,&internal1_m1804_BLDv0};
_S_newstage  S_newstage_1410_1 = {&var1713,&var1674,&var1718,&var1677,&var1700};
_S_orn  S_orn_1450_1 = {array_m1450_x_1,&iRM_10_,&var1701};
_S_orn  S_orn_154_1 = {array_m154_x_1,&iRM_5_,&var1702};
_S_noto  S_noto_1449_1 = {&var1695,&var1703};
_S_noto  S_noto_1448_1 = {&var1705,&var1704};
_S_cnshd  S_cnshd_1273_1 = {&R0MD34LP1,&var1982,&var557,&var557,&var1080,&var764,&lRM_1_,&iRM_1_,array_m1273_Lt_fw_1,array_m1273_Vr_fw_1,&iRM_1_,array_m1273_Lt_bw_1,array_m1273_Vr_bw_1,&fEM_B8UC01RDU,&fEM_B8UC02RDU,&fEM_B8UL01RDU,&fRM_0_0,&var1705,&vainSBool,&vainSFloat,&var1706,&var1707,&var1708,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1709,&internal1_m1273_X0,&internal1_m1273_t0,&internal1_m1273_BLDv0};
_S_noto  S_noto_1423_1 = {&var1195,&var1710};
_S_noto  S_noto_1437_1 = {&R8IS11LDU,&var1711};
_S_charint  S_charint_1360_1 = {&var1714,&var1712};
_S_ornc  S_ornc_1368_1 = {array_m1368_x_1,&iRM_3_,&var1713,&var1714};
_S_noto  S_noto_679_1 = {&lEM_R0MD01LC1,&var1715};
_S_fsumz  S_fsumz_1361_1 = {&var1712,&iRM_1_,&var1716};
_S_rs  S_rs_692_1 = {&var1031,&var1033,&var1717,&vainSBool,&internal1_m692_q0};
_S_cnshd  S_cnshd_1370_1 = {&R0MD34LP1,&var1997,&var1222,&var1222,&var1713,&var856,&var849,&iRM_2_,array_m1370_Lt_fw_1,array_m1370_Vr_fw_1,&iRM_1_,array_m1370_Lt_bw_1,array_m1370_Vr_bw_1,&fEM_A2UC08RDU,&fEM_A2UC07RDU,&fEM_A2UL01RDU,&fEM_A2UC02RDU,&var1718,&vainSBool,&var1719,&var1720,&var1721,&var1722,&var1723,&var1724,&var1725,&var1726,&var1727,&var1728,&internal1_m1370_X0,&internal1_m1370_t0,&internal1_m1370_BLDv0};
_S_zpfs  S_zpfs_1398_1 = {&var1737,&fRM_2_0,&var1729,&internal1_m1398_tx,&internal1_m1398_y0};
_S_zpfs  S_zpfs_1397_1 = {&var1736,&fRM_3_0,&var1730,&internal1_m1397_tx,&internal1_m1397_y0};
_S_fnapb  S_fnapb_1405_1 = {&var1997,&var1222,&var857,&R0MD34LP1,&var1720,&var1727,&fEM_B8UV04RDU,&fEM_A2UV01RDU,&fEM_A2UV02RDU,&fEM_A2UC06RDU,&fEM_A2UC05RDU,&iRM_80_,&fEM_A2UL04RDU,&fEM_A2UL05RDU,&fEM_A2UL03RDU,&var1731,&var1732,&var1733,&var1734,&var1735,&var1736,&var1737,&vainSFloat,&internal1_m1405_xptr,array_m1405_x0_1,array_m1405_tim0_1,&internal1_m1405_sumtim,&internal1_m1405_StSpeed,&internal1_m1405_Vz0,&internal1_m1405_flRazg,&internal1_m1405_DelSp,&internal1_m1405_z0,&internal1_m1405_txZS,&internal1_m1405_tx,&internal1_m1405_txd,&internal1_m1405_txMBl,&internal1_m1405_txBl,&internal1_m1405_Speed0,&internal1_m1405_xz0,&internal1_m1405_tz0,&internal1_m1405_Shift0,&internal1_m1405_ShCntlSp0,&internal1_m1405_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_1785_1 = {&R8IS11LDU,&var1738};
_S_rs  S_rs_712_1 = {&var1034,&var1035,&var1739,&vainSBool,&internal1_m712_q0};
_S_zpfs  S_zpfs_1818_1 = {&var1750,&fRM_2_0,&var1740,&internal1_m1818_tx,&internal1_m1818_y0};
_S_zpfs  S_zpfs_1822_1 = {&var1749,&fRM_3_0,&var1741,&internal1_m1822_tx,&internal1_m1822_y0};
_S_samhd  S_samhd_1807_1 = {&R0MD34LP1,&var766,&var766,&var1697,&var1698,&var1744,&var1745,&A8IS12LDU,&A8IS12LDU,&A8IS22LDU,&A8IS22LDU,&bRM_3_,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&fEM_B8UL07RDU,&var1742,&var1743,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,&internal1_m1807_DvUp0,&internal1_m1807_DvDw0,&internal1_m1807_FDvUp0,&internal1_m1807_FDvDw0,&internal1_m1807_BlDv0,&internal1_m1807_Pkv0,&internal1_m1807_Pkav0,&internal1_m1807_Zkv0,&internal1_m1807_Zkav0,&internal1_m1807_txNm,&internal1_m1807_txSm,&internal1_m1807_txHr,&internal1_m1807_txLd,&internal1_m1807_fef,&bFirstEnterFlag};
_S_fnapb  S_fnapb_1826_1 = {&var1985,&var557,&var762,&R0MD34LP1,&var1696,&fEM_B8UV03RDU,&fEM_B8UV04RDU,&fEM_B8UV01RDU,&fEM_B8UV02RDU,&fEM_B8UC06RDU,&fEM_B8UC05RDU,&iRM_20_,&fEM_B8UL04RDU,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&var1744,&var1745,&var1746,&var1747,&var1748,&var1749,&var1750,&vainSFloat,&internal1_m1826_xptr,array_m1826_x0_1,array_m1826_tim0_1,&internal1_m1826_sumtim,&internal1_m1826_StSpeed,&internal1_m1826_Vz0,&internal1_m1826_flRazg,&internal1_m1826_DelSp,&internal1_m1826_z0,&internal1_m1826_txZS,&internal1_m1826_tx,&internal1_m1826_txd,&internal1_m1826_txMBl,&internal1_m1826_txBl,&internal1_m1826_Speed0,&internal1_m1826_xz0,&internal1_m1826_tz0,&internal1_m1826_Shift0,&internal1_m1826_ShCntlSp0,&internal1_m1826_ShiftControl,&bFirstEnterFlag};
_S_zpfs  S_zpfs_1290_1 = {&var1767,&fRM_2_0,&var1751,&internal1_m1290_tx,&internal1_m1290_y0};
_S_zpfs  S_zpfs_1294_1 = {&var1766,&fRM_3_0,&var1752,&internal1_m1294_tx,&internal1_m1294_y0};
_S_noto  S_noto_1254_1 = {&R8IS11LDU,&var1753};
_S_orn  S_orn_1236_1 = {array_m1236_x_1,&iRM_8_,&var1754};
_S_noto  S_noto_681_1 = {&var1758,&var1755};
_S_rs  S_rs_702_1 = {&var1036,&var1037,&var1756,&vainSBool,&internal1_m702_q0};
_S_orn  S_orn_669_1 = {array_m669_x_1,&iRM_18_,&var1757};
_S_rs  S_rs_667_1 = {&var1522,&var1152,&var1758,&vainSBool,&internal1_m667_q0};
_S_samhd  S_samhd_1281_1 = {&R0MD34LP1,&var764,&var764,&var1707,&var1708,&var1761,&var1762,&var405,&var405,&var404,&var404,&bRM_3_,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&fEM_B8UL07RDU,&vainSBool,&vainSBool,&var1759,&var1760,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,&internal1_m1281_DvUp0,&internal1_m1281_DvDw0,&internal1_m1281_FDvUp0,&internal1_m1281_FDvDw0,&internal1_m1281_BlDv0,&internal1_m1281_Pkv0,&internal1_m1281_Pkav0,&internal1_m1281_Zkv0,&internal1_m1281_Zkav0,&internal1_m1281_txNm,&internal1_m1281_txSm,&internal1_m1281_txHr,&internal1_m1281_txLd,&internal1_m1281_fef,&bFirstEnterFlag};
_S_fnapb  S_fnapb_1300_1 = {&var1982,&var557,&var1079,&R0MD34LP1,&var1706,&fEM_B8UV03RDU,&fEM_B8UV04RDU,&fEM_B8UV01RDU,&fEM_B8UV02RDU,&fEM_B8UC06RDU,&fEM_B8UC05RDU,&iRM_20_,&fEM_B8UL04RDU,&fEM_B8UL06RDU,&fEM_B8UL03RDU,&var1761,&var1762,&var1763,&var1764,&var1765,&var1766,&var1767,&vainSFloat,&internal1_m1300_xptr,array_m1300_x0_1,array_m1300_tim0_1,&internal1_m1300_sumtim,&internal1_m1300_StSpeed,&internal1_m1300_Vz0,&internal1_m1300_flRazg,&internal1_m1300_DelSp,&internal1_m1300_z0,&internal1_m1300_txZS,&internal1_m1300_tx,&internal1_m1300_txd,&internal1_m1300_txMBl,&internal1_m1300_txBl,&internal1_m1300_Speed0,&internal1_m1300_xz0,&internal1_m1300_tz0,&internal1_m1300_Shift0,&internal1_m1300_ShCntlSp0,&internal1_m1300_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_807_1 = {&A5IS21LDU,&var1768};
_S_vmemb  S_vmemb_830_1 = {&var1770,&var1769,&internal1_m830_x0};
_S_noto  S_noto_838_1 = {&var406,&var1770};
_S_vmemb  S_vmemb_799_1 = {&var1768,&var1771,&internal1_m799_x0};
_S_vmemb  S_vmemb_741_1 = {&var1786,&var1772,&internal1_m741_x0};
_S_newstage  S_newstage_877_1 = {&var1830,&var1821,&var1829,&var1820,&var1773};
_S_newstage  S_newstage_1336_1 = {&var1812,&var1803,&var1811,&var1802,&var1774};
_S_newstage  S_newstage_424_1 = {&var1857,&var1848,&var1856,&var1847,&var1775};
_S_noto  S_noto_849_1 = {&var407,&var1776};
_S_rs  S_rs_855_1 = {&var1100,&var1775,&var1777,&vainSBool,&internal1_m855_q0};
_S_rs  S_rs_850_1 = {&var1101,&var1201,&var1778,&vainSBool,&internal1_m850_q0};
_S_noto  S_noto_842_1 = {&var1859,&var1779};
_S_noto  S_noto_840_1 = {&var1860,&var1780};
_S_rs  S_rs_818_1 = {&var1105,&var1775,&var1781,&vainSBool,&internal1_m818_q0};
_S_rs  S_rs_822_1 = {&var1104,&var1773,&var1782,&vainSBool,&internal1_m822_q0};
_S_rs  S_rs_831_1 = {&var1171,&var1110,&var1783,&vainSBool,&internal1_m831_q0};
_S_rs  S_rs_843_1 = {&var1102,&var1108,&var1784,&vainSBool,&internal1_m843_q0};
_S_noto  S_noto_798_1 = {&var407,&var1785};
_S_noto  S_noto_734_1 = {&var406,&var1786};
_S_noto  S_noto_463_1 = {&R8IS11LDU,&var1787};
_S_orn  S_orn_481_1 = {array_m481_x_1,&iRM_7_,&var1788};
_S_orn  S_orn_459_1 = {array_m459_x_1,&iRM_7_,&var1789};
_S_rs  S_rs_820_1 = {&var1109,&var1114,&var1790,&vainSBool,&internal1_m820_q0};
_S_noto  S_noto_162_1 = {&B2IS12LDU,&var1791};
_S_noto  S_noto_151_1 = {&A2IS12LDU,&var1792};
_S_noto  S_noto_152_1 = {&B1IS12LDU,&var1793};
_S_noto  S_noto_160_1 = {&A1IS12LDU,&var1794};
_S_samhd  S_samhd_1343_1 = {&var1083,&var1084,&var1084,&var1397,&var1396,&var1397,&var1396,&B4IS11LDU,&B4IS11LDU,&B4IS21LDU,&B4IS21LDU,&bRM_1_,&fEM_A4UZ05RDU,&fEM_A4UZ03RDU,&fEM_A4UZ04RDU,&var1795,&var1796,&var1797,&vainSBool,&var1798,&vainSBool,&var1799,&var1800,&var1801,&var1802,&var1803,&internal1_m1343_DvUp0,&internal1_m1343_DvDw0,&internal1_m1343_FDvUp0,&internal1_m1343_FDvDw0,&internal1_m1343_BlDv0,&internal1_m1343_Pkv0,&internal1_m1343_Pkav0,&internal1_m1343_Zkv0,&internal1_m1343_Zkav0,&internal1_m1343_txNm,&internal1_m1343_txSm,&internal1_m1343_txHr,&internal1_m1343_txLd,&internal1_m1343_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_1333_1 = {&var1083,&var1086,&var1086,&var1397,&var1396,&var1397,&var1396,&A4IS11LDU,&A4IS11LDU,&A4IS21LDU,&A4IS21LDU,&bRM_1_,&fEM_A4UZ05RDU,&fEM_A4UZ03RDU,&fEM_A4UZ04RDU,&var1804,&var1805,&var1806,&vainSBool,&var1807,&vainSBool,&var1808,&var1809,&var1810,&var1811,&var1812,&internal1_m1333_DvUp0,&internal1_m1333_DvDw0,&internal1_m1333_FDvUp0,&internal1_m1333_FDvDw0,&internal1_m1333_BlDv0,&internal1_m1333_Pkv0,&internal1_m1333_Pkav0,&internal1_m1333_Zkv0,&internal1_m1333_Zkav0,&internal1_m1333_txNm,&internal1_m1333_txSm,&internal1_m1333_txHr,&internal1_m1333_txLd,&internal1_m1333_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_879_1 = {&R0MD34LP1,&var941,&var941,&var1202,&var1097,&B5VS12LDU,&B5VS22LDU,&B5IS11LDU,&B5IS11LDU,&B5IS21LDU,&B5IS21LDU,&bRM_0_,&fEM_A5UZ05RDU,&fEM_A5UZ03RDU,&fEM_A5UZ04RDU,&var1813,&var1814,&var1815,&var1816,&var1817,&var1818,&vainSBool,&vainSBool,&var1819,&var1820,&var1821,&internal1_m879_DvUp0,&internal1_m879_DvDw0,&internal1_m879_FDvUp0,&internal1_m879_FDvDw0,&internal1_m879_BlDv0,&internal1_m879_Pkv0,&internal1_m879_Pkav0,&internal1_m879_Zkv0,&internal1_m879_Zkav0,&internal1_m879_txNm,&internal1_m879_txSm,&internal1_m879_txHr,&internal1_m879_txLd,&internal1_m879_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_875_1 = {&R0MD34LP1,&var943,&var943,&var1202,&var1097,&A5VS12LDU,&A5VS22LDU,&A5IS11LDU,&A5IS11LDU,&A5IS21LDU,&A5IS21LDU,&bRM_0_,&fEM_A5UZ05RDU,&fEM_A5UZ03RDU,&fEM_A5UZ04RDU,&var1822,&var1823,&var1824,&var1825,&var1826,&var1827,&vainSBool,&vainSBool,&var1828,&var1829,&var1830,&internal1_m875_DvUp0,&internal1_m875_DvDw0,&internal1_m875_FDvUp0,&internal1_m875_FDvDw0,&internal1_m875_BlDv0,&internal1_m875_Pkv0,&internal1_m875_Pkav0,&internal1_m875_Zkv0,&internal1_m875_Zkav0,&internal1_m875_txNm,&internal1_m875_txSm,&internal1_m875_txHr,&internal1_m875_txLd,&internal1_m875_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_390_1 = {&R0MD34LP1,&var625,&var624,&var1106,&var1099,&R4VS12LDU,&R4VS22LDU,&R4IS11LDU,&R4IS12LDU,&R4IS21LDU,&R4IS22LDU,&bRM_0_,&fEM_R4UZ05RDU,&fEM_R4UZ03RDU,&fEM_R4UZ04RDU,&var1831,&var1832,&var1833,&var1834,&var1835,&var1836,&vainSBool,&vainSBool,&var1837,&var1838,&vainSBool,&internal1_m390_DvUp0,&internal1_m390_DvDw0,&internal1_m390_FDvUp0,&internal1_m390_FDvDw0,&internal1_m390_BlDv0,&internal1_m390_Pkv0,&internal1_m390_Pkav0,&internal1_m390_Zkv0,&internal1_m390_Zkav0,&internal1_m390_txNm,&internal1_m390_txSm,&internal1_m390_txHr,&internal1_m390_txLd,&internal1_m390_fef,&bFirstEnterFlag};
_S_noto  S_noto_754_1 = {&R8IS11LDU,&var1839};
_S_samhd  S_samhd_427_1 = {&R0MD34LP1,&var1788,&var1172,&var1178,&var1098,&B6VS12LDU,&B6VS22LDU,&B6IS11LDU,&B6IS11LDU,&B6IS21LDU,&B6IS21LDU,&bRM_0_,&fEM_A6UZ05RDU,&fEM_A6UZ03RDU,&fEM_A6UZ04RDU,&var1840,&var1841,&var1842,&var1843,&var1844,&var1845,&vainSBool,&vainSBool,&var1846,&var1847,&var1848,&internal1_m427_DvUp0,&internal1_m427_DvDw0,&internal1_m427_FDvUp0,&internal1_m427_FDvDw0,&internal1_m427_BlDv0,&internal1_m427_Pkv0,&internal1_m427_Pkav0,&internal1_m427_Zkv0,&internal1_m427_Zkav0,&internal1_m427_txNm,&internal1_m427_txSm,&internal1_m427_txHr,&internal1_m427_txLd,&internal1_m427_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_421_1 = {&R0MD34LP1,&var1789,&var1173,&var1178,&var1098,&A6VS12LDU,&A6VS22LDU,&A6IS11LDU,&A6IS11LDU,&A6IS21LDU,&A6IS21LDU,&bRM_0_,&fEM_A6UZ05RDU,&fEM_A6UZ03RDU,&fEM_A6UZ04RDU,&var1849,&var1850,&var1851,&var1852,&var1853,&var1854,&vainSBool,&vainSBool,&var1855,&var1856,&var1857,&internal1_m421_DvUp0,&internal1_m421_DvDw0,&internal1_m421_FDvUp0,&internal1_m421_FDvDw0,&internal1_m421_BlDv0,&internal1_m421_Pkv0,&internal1_m421_Pkav0,&internal1_m421_Zkv0,&internal1_m421_Zkav0,&internal1_m421_txNm,&internal1_m421_txSm,&internal1_m421_txHr,&internal1_m421_txLd,&internal1_m421_fef,&bFirstEnterFlag};
_S_orn  S_orn_854_1 = {array_m854_x_1,&iRM_17_,&var1858};
_S_rs  S_rs_827_1 = {&var1112,&var316,&var1859,&vainSBool,&internal1_m827_q0};
_S_rs  S_rs_824_1 = {&var1113,&var317,&var1860,&vainSBool,&internal1_m824_q0};
_S_orni  S_orni_140_1 = {array_m140_x_1,&iRM_21_,&var1861,&vainSLong};
_S_equz_p  S_equz_p_80_1 = {&R0MW11IP2,&iRM_6_,&var1862};
_S_equz_p  S_equz_p_77_1 = {&R0MW11IP2,&iRM_5_,&var1863};
_S_equz_p  S_equz_p_76_1 = {&R0MW11IP2,&iRM_4_,&var1864};
_S_equz_p  S_equz_p_72_1 = {&R0MW11IP2,&iRM_3_,&var1865};
_S_equz_p  S_equz_p_71_1 = {&R0MW11IP2,&iRM_2_,&var1866};
_S_equz_p  S_equz_p_68_1 = {&R0MW11IP2,&iRM_1_,&var1867};
_S_equz_p  S_equz_p_64_1 = {&R0MW14IP1,&iRM_3_,&var1868};
_S_equz_p  S_equz_p_57_1 = {&R0MW14IP1,&iRM_1_,&vainSBool};
_S_equz_p  S_equz_p_60_1 = {&R0MW14IP1,&iRM_2_,&var1869};
_S_equz_p  S_equz_p_51_1 = {&R0MW11IP1,&iRM_3_,&var1870};
_S_equz_p  S_equz_p_43_1 = {&R0MW11IP1,&iRM_1_,&var1871};
_S_equz_p  S_equz_p_46_1 = {&R0MW11IP1,&iRM_2_,&var1872};
_S_equz_p  S_equz_p_106_1 = {&R0MW16IP1,&iRM_11_,&var1873};
_S_equz_p  S_equz_p_99_1 = {&R0MW16IP1,&iRM_4_,&var1874};
_S_equz_p  S_equz_p_98_1 = {&R0MW16IP1,&iRM_3_,&var1875};
_S_equz_p  S_equz_p_97_1 = {&R0MW16IP1,&iRM_2_,&var1876};
_S_equz_p  S_equz_p_10_1 = {&R0MW12IP1,&iRM_4_,&var1877};
_S_equz_p  S_equz_p_7_1 = {&R0MW12IP1,&iRM_3_,&var1878};
_S_equz_p  S_equz_p_2_1 = {&R0MW12IP1,&iRM_1_,&var1879};
_S_equz_p  S_equz_p_4_1 = {&R0MW12IP1,&iRM_2_,&var1880};


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
   var45.f=0.0;
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
   var262.i=0;
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
   var388.i=0;
   var389.b=0;
   var390.b=0;
   var391.i=0;
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
   var428.b=0;
   var429.b=0;
   var430.b=0;
   var431.b=0;
   var432.f=0.0;
   var433.b=0;
   var434.b=0;
   var435.b=0;
   var436.b=0;
   var437.b=0;
   var438.b=0;
   var439.b=0;
   var440.b=0;
   var441.b=0;
   var442.f=0.0;
   var443.f=0.0;
   var444.b=0;
   var445.b=0;
   var446.b=0;
   var447.f=0.0;
   var448.b=0;
   var449.b=0;
   var450.f=0.0;
   var451.b=0;
   var452.b=0;
   var453.b=0;
   var454.b=0;
   var455.b=0;
   var456.b=0;
   var457.b=0;
   var458.b=0;
   var459.f=0.0;
   var460.f=0.0;
   var461.f=0.0;
   var462.f=0.0;
   var463.b=0;
   var464.f=0.0;
   var465.f=0.0;
   var466.i=0;
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
   var557.f=0.0;
   var558.b=0;
   var559.b=0;
   var560.b=0;
   var561.f=0.0;
   var562.b=0;
   var563.b=0;
   var564.b=0;
   var565.f=0.0;
   var566.b=0;
   var567.b=0;
   var568.b=0;
   var569.f=0.0;
   var570.b=0;
   var571.b=0;
   var572.b=0;
   var573.f=0.0;
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
   var659.f=0.0;
   var660.f=0.0;
   var661.b=0;
   var662.f=0.0;
   var663.f=0.0;
   var664.b=0;
   var665.f=0.0;
   var666.f=0.0;
   var667.b=0;
   var668.f=0.0;
   var669.f=0.0;
   var670.b=0;
   var671.b=0;
   var672.f=0.0;
   var673.f=0.0;
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
   var803.l=0L;
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
   var1213.f=0.0;
   var1214.b=0;
   var1215.f=0.0;
   var1216.b=0;
   var1217.f=0.0;
   var1218.b=0;
   var1219.b=0;
   var1220.b=0;
   var1221.b=0;
   var1222.f=0.0;
   var1223.f=0.0;
   var1224.f=0.0;
   var1225.f=0.0;
   var1226.f=0.0;
   var1227.f=0.0;
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
   var1276.b=0;
   var1277.b=0;
   var1278.b=0;
   var1279.b=0;
   var1280.b=0;
   var1281.b=0;
   var1282.b=0;
   var1283.b=0;
   var1284.b=0;
   var1285.b=0;
   var1286.b=0;
   var1287.i=0;
   var1288.i=0;
   var1289.b=0;
   var1290.b=0;
   var1291.b=0;
   var1292.b=0;
   var1293.b=0;
   var1294.b=0;
   var1295.l=0L;
   var1296.b=0;
   var1297.b=0;
   var1298.b=0;
   var1299.i=0;
   var1300.b=0;
   var1301.b=0;
   var1302.b=0;
   var1303.b=0;
   var1304.b=0;
   var1305.b=0;
   var1306.b=0;
   var1307.b=0;
   var1308.b=0;
   var1309.i=0;
   var1310.i=0;
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
   var1338.b=0;
   var1339.b=0;
   var1340.b=0;
   var1341.b=0;
   var1342.b=0;
   var1343.b=0;
   var1344.b=0;
   var1345.b=0;
   var1346.b=0;
   var1347.b=0;
   var1348.b=0;
   var1349.b=0;
   var1350.l=0L;
   var1351.b=0;
   var1352.b=0;
   var1353.b=0;
   var1354.b=0;
   var1355.b=0;
   var1356.b=0;
   var1357.b=0;
   var1358.b=0;
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
   var1369.f=0.0;
   var1370.b=0;
   var1371.b=0;
   var1372.b=0;
   var1373.b=0;
   var1374.b=0;
   var1375.f=0.0;
   var1376.b=0;
   var1377.b=0;
   var1378.b=0;
   var1379.b=0;
   var1380.b=0;
   var1381.b=0;
   var1382.b=0;
   var1383.b=0;
   var1384.b=0;
   var1385.b=0;
   var1386.b=0;
   var1387.b=0;
   var1388.b=0;
   var1389.i=0;
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
   var1414.f=0.0;
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
   var1479.b=0;
   var1480.b=0;
   var1481.b=0;
   var1482.b=0;
   var1483.b=0;
   var1484.b=0;
   var1485.b=0;
   var1486.b=0;
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
   var1503.b=0;
   var1504.b=0;
   var1505.b=0;
   var1506.b=0;
   var1507.b=0;
   var1508.l=0L;
   var1509.b=0;
   var1510.i=0;
   var1511.i=0;
   var1512.b=0;
   var1513.f=0.0;
   var1514.f=0.0;
   var1515.f=0.0;
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
   var1531.b=0;
   var1532.i=0;
   var1533.b=0;
   var1534.c=0;
   var1535.i=0;
   var1536.b=0;
   var1537.f=0.0;
   var1538.b=0;
   var1539.b=0;
   var1540.b=0;
   var1541.b=0;
   var1542.b=0;
   var1543.b=0;
   var1544.b=0;
   var1545.f=0.0;
   var1546.c=0;
   var1547.b=0;
   var1548.b=0;
   var1549.b=0;
   var1550.b=0;
   var1551.f=0.0;
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
   var1593.i=0;
   var1594.b=0;
   var1595.c=0;
   var1596.i=0;
   var1597.b=0;
   var1598.f=0.0;
   var1599.b=0;
   var1600.b=0;
   var1601.b=0;
   var1602.b=0;
   var1603.b=0;
   var1604.b=0;
   var1605.b=0;
   var1606.f=0.0;
   var1607.c=0;
   var1608.b=0;
   var1609.b=0;
   var1610.b=0;
   var1611.b=0;
   var1612.f=0.0;
   var1613.b=0;
   var1614.b=0;
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
   var1626.i=0;
   var1627.b=0;
   var1628.c=0;
   var1629.i=0;
   var1630.b=0;
   var1631.f=0.0;
   var1632.b=0;
   var1633.b=0;
   var1634.b=0;
   var1635.b=0;
   var1636.b=0;
   var1637.b=0;
   var1638.b=0;
   var1639.f=0.0;
   var1640.c=0;
   var1641.b=0;
   var1642.b=0;
   var1643.f=0.0;
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
   var1656.i=0;
   var1657.b=0;
   var1658.b=0;
   var1659.b=0;
   var1660.b=0;
   var1661.b=0;
   var1662.b=0;
   var1663.b=0;
   var1664.b=0;
   var1665.i=0;
   var1666.b=0;
   var1667.b=0;
   var1668.b=0;
   var1669.b=0;
   var1670.b=0;
   var1671.b=0;
   var1672.b=0;
   var1673.i=0;
   var1674.b=0;
   var1675.c=0;
   var1676.i=0;
   var1677.b=0;
   var1678.f=0.0;
   var1679.b=0;
   var1680.b=0;
   var1681.b=0;
   var1682.b=0;
   var1683.b=0;
   var1684.b=0;
   var1685.b=0;
   var1686.f=0.0;
   var1687.c=0;
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
   var1698.b=0;
   var1699.c=0;
   var1700.b=0;
   var1701.b=0;
   var1702.b=0;
   var1703.b=0;
   var1704.b=0;
   var1705.b=0;
   var1706.b=0;
   var1707.b=0;
   var1708.b=0;
   var1709.c=0;
   var1710.b=0;
   var1711.b=0;
   var1712.i=0;
   var1713.b=0;
   var1714.c=0;
   var1715.b=0;
   var1716.i=0;
   var1717.b=0;
   var1718.b=0;
   var1719.f=0.0;
   var1720.b=0;
   var1721.b=0;
   var1722.b=0;
   var1723.b=0;
   var1724.b=0;
   var1725.b=0;
   var1726.b=0;
   var1727.f=0.0;
   var1728.c=0;
   var1729.b=0;
   var1730.b=0;
   var1731.b=0;
   var1732.b=0;
   var1733.f=0.0;
   var1734.b=0;
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
   var1746.f=0.0;
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
   var1763.f=0.0;
   var1764.b=0;
   var1765.b=0;
   var1766.b=0;
   var1767.b=0;
   var1768.b=0;
   var1769.b=0;
   var1770.b=0;
   var1771.b=0;
   var1772.b=0;
   var1773.b=0;
   var1774.b=0;
   var1775.b=0;
   var1776.b=0;
   var1777.b=0;
   var1778.b=0;
   var1779.b=0;
   var1780.b=0;
   var1781.b=0;
   var1782.b=0;
   var1783.b=0;
   var1784.b=0;
   var1785.b=0;
   var1786.b=0;
   var1787.b=0;
   var1788.b=0;
   var1789.b=0;
   var1790.b=0;
   var1791.b=0;
   var1792.b=0;
   var1793.b=0;
   var1794.b=0;
   var1795.b=0;
   var1796.b=0;
   var1797.b=0;
   var1798.b=0;
   var1799.b=0;
   var1800.b=0;
   var1801.i=0;
   var1802.b=0;
   var1803.b=0;
   var1804.b=0;
   var1805.b=0;
   var1806.b=0;
   var1807.b=0;
   var1808.b=0;
   var1809.b=0;
   var1810.i=0;
   var1811.b=0;
   var1812.b=0;
   var1813.b=0;
   var1814.b=0;
   var1815.b=0;
   var1816.b=0;
   var1817.b=0;
   var1818.b=0;
   var1819.i=0;
   var1820.b=0;
   var1821.b=0;
   var1822.b=0;
   var1823.b=0;
   var1824.b=0;
   var1825.b=0;
   var1826.b=0;
   var1827.b=0;
   var1828.i=0;
   var1829.b=0;
   var1830.b=0;
   var1831.b=0;
   var1832.b=0;
   var1833.b=0;
   var1834.b=0;
   var1835.b=0;
   var1836.b=0;
   var1837.i=0;
   var1838.b=0;
   var1839.b=0;
   var1840.b=0;
   var1841.b=0;
   var1842.b=0;
   var1843.b=0;
   var1844.b=0;
   var1845.b=0;
   var1846.i=0;
   var1847.b=0;
   var1848.b=0;
   var1849.b=0;
   var1850.b=0;
   var1851.b=0;
   var1852.b=0;
   var1853.b=0;
   var1854.b=0;
   var1855.i=0;
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
   var1875.b=0;
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
   var1910.b=0;
   var1911.b=0;
   var1912.b=0;
   var1913.b=0;
   var1914.b=0;
   var1915.b=0;
   var1916.f=0.0;
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
   var1938.b=0;
   var1939.b=0;
   var1940.b=0;
   var1941.b=0;
   var1942.b=0;
   var1943.b=0;
   var1944.b=0;
   var1945.b=0;
   var1946.b=0;
   var1947.b=0;
   var1948.b=0;
   var1949.b=0;
   var1950.b=0;
   var1951.f=0.0;
   var1952.f=0.0;
   var1953.b=0;
   var1954.b=0;
   var1955.b=0;
   var1956.b=0;
   var1957.b=0;
   var1958.b=0;
   var1959.b=0;
   var1960.b=0;
   var1961.b=0;
   var1962.b=0;
   var1963.b=0;
   var1964.b=0;
   var1965.b=0;
   var1966.b=0;
   var1967.b=0;
   var1968.b=0;
   var1969.b=0;
   var1970.b=0;
   var1971.b=0;
   var1972.b=0;
   var1973.b=0;
   var1974.b=0;
   var1975.b=0;
   var1976.b=0;
   var1977.b=0;
   var1978.b=0;
   var1979.f=0.0;
   var1980.b=0;
   var1981.b=0;
   var1982.f=0.0;
   var1983.b=0;
   var1984.b=0;
   var1985.f=0.0;
   var1986.b=0;
   var1987.b=0;
   var1988.f=0.0;
   var1989.b=0;
   var1990.b=0;
   var1991.f=0.0;
   var1992.b=0;
   var1993.b=0;
   var1994.f=0.0;
   var1995.b=0;
   var1996.b=0;
   var1997.f=0.0;
   var1998.b=0;
   var1999.b=0;
   var2000.b=0;
   var2001.f=0.0;
   var2002.b=0;
   var2003.b=0;
   var2004.b=0;
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
  equz_p(&S_equz_p_18_2);
  scalzz(&S_scalzz_193_2);
  scalzz(&S_scalzz_195_2);
  or2(&S_or2_11_2);
  or2(&S_or2_43_2);
  or2(&S_or2_13_2);
  or2(&S_or2_44_2);
  or2(&S_or2_74_2);
  or2(&S_or2_71_2);
  and3(&S_and3_79_2);
  or2(&S_or2_103_2);
  or2(&S_or2_104_2);
  and3(&S_and3_111_2);
  and4(&S_and4_134_2);
  and4(&S_and4_162_2);
  schl24(&S_schl24_147_2);
  schl24(&S_schl24_151_2);
  noto(&S_noto_265_2);
  noto(&S_noto_266_2);
  noto(&S_noto_267_2);
  noto(&S_noto_285_2);
  noto(&S_noto_286_2);
  noto(&S_noto_287_2);
  fsumo(&S_fsumo_233_2);
  bol(&S_bol_234_2);
  lkb(&S_lkb_80_2);
  lkb(&S_lkb_112_2);
  and4(&S_and4_108_2);
  zzfs(&S_zzfs_127_2);
  zzfs(&S_zzfs_131_2);
  zzfs(&S_zzfs_137_2);
  zzfs(&S_zzfs_141_2);
  zzfs(&S_zzfs_144_2);
  zzfs(&S_zzfs_149_2);
  zzfs(&S_zzfs_155_2);
  zzfs(&S_zzfs_157_2);
  zzfs(&S_zzfs_165_2);
  zzfs(&S_zzfs_172_2);
  zzfs(&S_zzfs_176_2);
  zzfs(&S_zzfs_182_2);
  enctkb(&S_enctkb_75_2);
  enctkb(&S_enctkb_106_2);
  drg(&S_drg_205_2);
  drg(&S_drg_198_2);
  geterr(&S_geterr_197_2);
  drg(&S_drg_216_2);
  drg(&S_drg_208_2);
  geterr(&S_geterr_200_2);
  tprg(&S_tprg_220_2);
  tprg(&S_tprg_226_2);
  noto(&S_noto_231_2);
  noto(&S_noto_222_2);
  andn(&S_andn_138_2);
  noto(&S_noto_145_2);
  andn(&S_andn_166_2);
  noto(&S_noto_177_2);
  andn(&S_andn_179_2);
  noto(&S_noto_180_2);
  and2(&S_and2_230_2);
  and3(&S_and3_19_2);
  and3(&S_and3_48_2);
  and3(&S_and3_23_2);
  and3(&S_and3_51_2);
  and3(&S_and3_82_2);
  or3(&S_or3_133_2);
  or3(&S_or3_161_2);
  and2(&S_and2_223_2);
  or2(&S_or2_203_2);
  or2(&S_or2_207_2);
  lkb(&S_lkb_20_2);
  lkb(&S_lkb_24_2);
  lkb(&S_lkb_49_2);
  lkb(&S_lkb_83_2);
  lkb(&S_lkb_52_2);
  lkb(&S_lkb_109_2);
  zzfs(&S_zzfs_240_2);
  zzfs(&S_zzfs_244_2);
  zzfs(&S_zzfs_246_2);
  zzfs(&S_zzfs_250_2);
  zzfs(&S_zzfs_254_2);
  zzfs(&S_zzfs_256_2);
  zzfs(&S_zzfs_260_2);
  enctkb(&S_enctkb_21_2);
  enctkb(&S_enctkb_53_2);
  enctkb(&S_enctkb_45_2);
  enctkb(&S_enctkb_77_2);
  enctkb(&S_enctkb_110_2);
  enctkb(&S_enctkb_16_2);
  noto(&S_noto_142_2);
  noto(&S_noto_160_2);
  and2(&S_and2_269_2);
  and2(&S_and2_290_2);
  zzfs(&S_zzfs_238_2);
  zzfs(&S_zzfs_248_2);
  ornc(&S_ornc_124_2);
  ornc(&S_ornc_270_2);
  ornc(&S_ornc_291_2);
  noto(&S_noto_276_2);
  noto(&S_noto_292_2);
  or2(&S_or2_294_2);
  zzfs(&S_zzfs_242_2);
  zzfs(&S_zzfs_252_2);
  zzfs(&S_zzfs_258_2);
  ornc(&S_ornc_268_2);
  ornc(&S_ornc_279_2);
  noto(&S_noto_271_2);
  noto(&S_noto_289_2);
  or2(&S_or2_280_2);
  setData(idpsaz25,&var1881);
  setData(idpsaz3,&var1882);
  setData(idpsaz25,&var1883);
  setData(idpsaz24,&var1884);
  setData(idpsaz23,&var1885);
  setData(idpsaz22,&var1886);
  setData(idpsaz21,&var1887);
  setData(idpsaz15,&var1888);
  setData(idpsaz14,&var1889);
  setData(idpsaz13,&var1890);
  setData(idpsaz12,&var1891);
  setData(idpsaz11,&var1892);
  setData(idR0EE02LDU,&var1050);
  setData(idB8VC01RDU,&var1982);
  setData(idB2VC01RDU,&var1994);
  setData(idA2VC01RDU,&var1997);
  setData(idA3VC01RDU,&var1991);
  setData(idB0VS11LDU,&var1959);
  setData(idA0VS11LDU,&var1960);
  setData(idB0VN01LDU,&var1929);
  setData(idA0VN01LDU,&var1931);
  setData(idB0VP01LDU,&var1965);
  setData(idA0VP01LDU,&var1966);
  setData(idB0VE01LDU,&var1956);
  setData(idA0VE01LDU,&var1958);
  setData(idA3VP82LDU,&var1927);
  setData(idB3VP82LDU,&var1950);
  setData(idB3VP52LDU,&var1975);
  setData(idB3CP02RDU,&var1951);
  setData(idB3VP42LDU,&var1925);
  setData(idA3VP52LDU,&var1978);
  setData(idA3CP02RDU,&var1952);
  setData(idA3VP42LDU,&var1926);
  setData(idA1VC01RDU,&var1979);
  setData(idA8VC01RDU,&var1985);
  setData(idB3VC01RDU,&var1988);
  setData(idB1VC01RDU,&var2001);
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
  equz_p(&S_equz_p_51_1);
  equz_p(&S_equz_p_60_1);
  equz_p(&S_equz_p_57_1);
  equz_p(&S_equz_p_64_1);
  equz_p(&S_equz_p_68_1);
  equz_p(&S_equz_p_71_1);
  equz_p(&S_equz_p_72_1);
  equz_p(&S_equz_p_76_1);
  equz_p(&S_equz_p_77_1);
  equz_p(&S_equz_p_80_1);
  noto(&S_noto_152_1);
  noto(&S_noto_151_1);
  noto(&S_noto_162_1);
  noto(&S_noto_840_1);
  noto(&S_noto_807_1);
  noto(&S_noto_1254_1);
  noto(&S_noto_1785_1);
  noto(&S_noto_1437_1);
  noto(&S_noto_959_1);
  noto(&S_noto_237_1);
  noto(&S_noto_603_1);
  noto(&S_noto_1070_1);
  rs(&S_rs_697_1);
  noto(&S_noto_1543_1);
  equz_p(&S_equz_p_32_1);
  equz_p(&S_equz_p_41_1);
  noto(&S_noto_34_1);
  equz_p(&S_equz_p_37_1);
  noto(&S_noto_1998_1);
  noto(&S_noto_1997_1);
  noto(&S_noto_2003_1);
  noto(&S_noto_1999_1);
  noto(&S_noto_2005_1);
  noto(&S_noto_1976_1);
  noto(&S_noto_1977_1);
  noto(&S_noto_1978_1);
  noto(&S_noto_1979_1);
  noto(&S_noto_1980_1);
  noto(&S_noto_2293_1);
  equz_p(&S_equz_p_100_1);
  equz_p(&S_equz_p_101_1);
  equz_p(&S_equz_p_102_1);
  noto(&S_noto_1036_1);
  equz_p(&S_equz_p_103_1);
  equz_p(&S_equz_p_104_1);
  noto(&S_noto_186_1);
  equz_p(&S_equz_p_105_1);
  noto(&S_noto_12_1);
  equz_p(&S_equz_p_2020_1);
  equz_p(&S_equz_p_2019_1);
  equz_p(&S_equz_p_2021_1);
  equz_p(&S_equz_p_2022_1);
  equz_p(&S_equz_p_2023_1);
  noto(&S_noto_1985_1);
  noto(&S_noto_2039_1);
  noto(&S_noto_2057_1);
  rs(&S_rs_687_1);
  noto(&S_noto_2017_1);
  noto(&S_noto_2043_1);
  noto(&S_noto_1510_1);
  rsun(&S_rsun_1602_1);
  rs(&S_rs_689_1);
  rs(&S_rs_691_1);
  rs(&S_rs_707_1);
  rs(&S_rs_724_1);
  rs(&S_rs_696_1);
  rs(&S_rs_711_1);
  rs(&S_rs_26_1);
  noto(&S_noto_2116_1);
  noto(&S_noto_2084_1);
  noto(&S_noto_1709_1);
  orni(&S_orni_314_1);
  noto(&S_noto_658_1);
  noto(&S_noto_22_1);
  noto(&S_noto_23_1);
  noto(&S_noto_24_1);
  noto(&S_noto_25_1);
  noto(&S_noto_661_1);
  noto(&S_noto_659_1);
  noto(&S_noto_50_1);
  noto(&S_noto_288_1);
  noto(&S_noto_291_1);
  noto(&S_noto_300_1);
  noto(&S_noto_306_1);
  noto(&S_noto_296_1);
  noto(&S_noto_1114_1);
  noto(&S_noto_1120_1);
  orni(&S_orni_360_1);
  noto(&S_noto_2150_1);
  noto(&S_noto_2152_1);
  ovbs(&S_ovbs_1341_1);
  ovbs(&S_ovbs_2320_1);
  sr(&S_sr_1191_1);
  bol(&S_bol_1185_1);
  ma(&S_ma_90_1);
  sr(&S_sr_88_1);
  bol(&S_bol_285_1);
  bol(&S_bol_281_1);
  bol(&S_bol_1582_1);
  bol(&S_bol_1580_1);
  bol(&S_bol_1111_1);
  bol(&S_bol_1104_1);
  bol(&S_bol_644_1);
  bol(&S_bol_648_1);
  bol(&S_bol_657_1);
  bol(&S_bol_663_1);
  and2(&S_and2_828_1);
  and2(&S_and2_27_1);
  and2(&S_and2_28_1);
  and2(&S_and2_29_1);
  and2(&S_and2_30_1);
  and2(&S_and2_42_1);
  and2(&S_and2_38_1);
  and2(&S_and2_819_1);
  or4(&S_or4_462_1);
  or2(&S_or2_832_1);
  or3(&S_or3_5_1);
  or2(&S_or2_6_1);
  or2(&S_or2_1453_1);
  or2(&S_or2_975_1);
  or2(&S_or2_254_1);
  or2(&S_or2_620_1);
  or2(&S_or2_1085_1);
  or2(&S_or2_1558_1);
  or2(&S_or2_1190_1);
  and2(&S_and2_1184_1);
  or2(&S_or2_20_1);
  or2(&S_or2_39_1);
  or2(&S_or2_35_1);
  or2(&S_or2_49_1);
  or2(&S_or2_769_1);
  or3(&S_or3_756_1);
  or4(&S_or4_773_1);
  or2(&S_or2_790_1);
  or3(&S_or3_816_1);
  and2(&S_and2_839_1);
  and2(&S_and2_813_1);
  or2(&S_or2_823_1);
  or2(&S_or2_736_1);
  or2(&S_or2_738_1);
  or2(&S_or2_740_1);
  or2(&S_or2_1314_1);
  or2(&S_or2_1342_1);
  or2(&S_or2_1195_1);
  and2(&S_and2_1210_1);
  or2(&S_or2_1250_1);
  and3(&S_and3_289_1);
  and3(&S_and3_305_1);
  or2(&S_or2_680_1);
  or2(&S_or2_688_1);
  or2(&S_or2_690_1);
  or2(&S_or2_693_1);
  or2(&S_or2_664_1);
  and2(&S_and2_714_1);
  or2(&S_or2_721_1);
  and2(&S_and2_685_1);
  or2(&S_or2_700_1);
  or2(&S_or2_695_1);
  or2(&S_or2_718_1);
  and2(&S_and2_675_1);
  or2(&S_or2_372_1);
  or2(&S_or2_377_1);
  or2(&S_or2_837_1);
  or2(&S_or2_514_1);
  and2(&S_and2_589_1);
  and2(&S_and2_590_1);
  and2(&S_and2_602_1);
  or2(&S_or2_592_1);
  and2(&S_and2_184_1);
  and2(&S_and2_223_1);
  and2(&S_and2_219_1);
  or2(&S_or2_225_1);
  and2(&S_and2_236_1);
  or2(&S_or2_878_1);
  or2(&S_or2_946_1);
  and2(&S_and2_1031_1);
  or2(&S_or2_1042_1);
  or2(&S_or2_1058_1);
  or2(&S_or2_1532_1);
  and2(&S_and2_1503_1);
  or2(&S_or2_1513_1);
  or2(&S_or2_1425_1);
  and2(&S_and2_1119_1);
  or3(&S_or3_1631_1);
  or3(&S_or3_1671_1);
  or3(&S_or3_1687_1);
  or2(&S_or2_2321_1);
  or2(&S_or2_1840_1);
  or2(&S_or2_1841_1);
  or2(&S_or2_1781_1);
  or2(&S_or2_1983_1);
  or2(&S_or2_1984_1);
  or4(&S_or4_1990_1);
  or4(&S_or4_1991_1);
  or2(&S_or2_1993_1);
  or2(&S_or2_1987_1);
  or2(&S_or2_1986_1);
  or3(&S_or3_1995_1);
  and2(&S_and2_2024_1);
  or2(&S_or2_2025_1);
  and2(&S_and2_2031_1);
  and2(&S_and2_2047_1);
  or2(&S_or2_2058_1);
  zpfs(&S_zpfs_2027_1);
  zpfs(&S_zpfs_2028_1);
  zpfs(&S_zpfs_2029_1);
  zpfs(&S_zpfs_2030_1);
  or2(&S_or2_2033_1);
  and2(&S_and2_2034_1);
  or2(&S_or2_2049_1);
  or3(&S_or3_2035_1);
  or3(&S_or3_2099_1);
  ma(&S_ma_1669_1);
  or3(&S_or3_2071_1);
  or2(&S_or2_257_1);
  ovbs(&S_ovbs_82_1);
  ovbs(&S_ovbs_21_1);
  ovbs(&S_ovbs_127_1);
  ovbs(&S_ovbs_120_1);
  ovbs(&S_ovbs_1627_1);
  ovbs(&S_ovbs_835_1);
  ovbs(&S_ovbs_322_1);
  ovbs(&S_ovbs_368_1);
  ovbs(&S_ovbs_52_1);
  or2(&S_or2_2215_1);
  or2(&S_or2_2203_1);
  noto(&S_noto_2234_1);
  bol(&S_bol_1762_1);
  bol(&S_bol_1756_1);
  or2(&S_or2_1759_1);
  bol(&S_bol_1745_1);
  bol(&S_bol_1734_1);
  or2(&S_or2_1743_1);
  bol(&S_bol_1764_1);
  bol(&S_bol_1757_1);
  or2(&S_or2_1761_1);
  bol(&S_bol_1749_1);
  bol(&S_bol_1744_1);
  or2(&S_or2_1748_1);
  and4(&S_and4_45_1);
  abs_subf(&S_abs_subf_1754_1);
  noto(&S_noto_1760_1);
  and2(&S_and2_256_1);
  and2(&S_and2_621_1);
  and2(&S_and2_2476_1);
  rs(&S_rs_2426_1);
  sr(&S_sr_2441_1);
  rs(&S_rs_2420_1);
  zpfs(&S_zpfs_2448_1);
  or2(&S_or2_2435_1);
  abs_subf(&S_abs_subf_2401_1);
  and2(&S_and2_2409_1);
  noto(&S_noto_1009_1);
  or2(&S_or2_2458_1);
  zzfs(&S_zzfs_2410_1);
  noto(&S_noto_2421_1);
  or2(&S_or2_393_1);
  or2(&S_or2_380_1);
  or2(&S_or2_1270_1);
  or2(&S_or2_1276_1);
  or2(&S_or2_252_1);
  or2(&S_or2_618_1);
  nocnm(&S_nocnm_1934_1);
  nocnm(&S_nocnm_1937_1);
  noto(&S_noto_1892_1);
  noto(&S_noto_1893_1);
  noto(&S_noto_2394_1);
  noto(&S_noto_2363_1);
  noto(&S_noto_2396_1);
  noto(&S_noto_2365_1);
  noto(&S_noto_114_1);
  and2(&S_and2_815_1);
  and2(&S_and2_817_1);
  or2(&S_or2_135_1);
  noto(&S_noto_1946_1);
  noto(&S_noto_1953_1);
  or2(&S_or2_1916_1);
  or2(&S_or2_1956_1);
  or2(&S_or2_1959_1);
  or2(&S_or2_1927_1);
  or2(&S_or2_1930_1);
  or2(&S_or2_1889_1);
  or2(&S_or2_1863_1);
  or2(&S_or2_1859_1);
  or2(&S_or2_2389_1);
  or2(&S_or2_2393_1);
  or2(&S_or2_2391_1);
  or2(&S_or2_2358_1);
  or2(&S_or2_2360_1);
  or2(&S_or2_2362_1);
  or2(&S_or2_1881_1);
  or2(&S_or2_1914_1);
  or2(&S_or2_2529_1);
  or2(&S_or2_2535_1);
  ovbsb(&S_ovbsb_228_1);
  ovbsb(&S_ovbsb_230_1);
  ovbsb(&S_ovbsb_241_1);
  ovbsb(&S_ovbsb_255_1);
  ovbsb(&S_ovbsb_597_1);
  ovbsb(&S_ovbsb_594_1);
  ovbsb(&S_ovbsb_607_1);
  ovbsb(&S_ovbsb_628_1);
  ovbsb(&S_ovbsb_2470_1);
  ovbsb(&S_ovbsb_395_1);
  and2(&S_and2_1605_1);
  and2(&S_and2_1625_1);
  and2(&S_and2_1609_1);
  and2(&S_and2_1618_1);
  and2(&S_and2_1613_1);
  noto(&S_noto_58_1);
  or2(&S_or2_1229_1);
  ovbsb(&S_ovbsb_220_1);
  zpfs(&S_zpfs_221_1);
  zzfs(&S_zzfs_2552_1);
  zzfs(&S_zzfs_2558_1);
  noto(&S_noto_754_1);
  noto(&S_noto_160_1);
  rs(&S_rs_820_1);
  noto(&S_noto_463_1);
  noto(&S_noto_734_1);
  noto(&S_noto_798_1);
  rs(&S_rs_831_1);
  noto(&S_noto_849_1);
  vmemb(&S_vmemb_741_1);
  vmemb(&S_vmemb_799_1);
  noto(&S_noto_838_1);
  vmemb(&S_vmemb_830_1);
  rs(&S_rs_702_1);
  rs(&S_rs_712_1);
  rs(&S_rs_692_1);
  noto(&S_noto_679_1);
  rs(&S_rs_720_1);
  noto(&S_noto_287_1);
  noto(&S_noto_715_1);
  noto(&S_noto_650_1);
  noto(&S_noto_1110_1);
  noto(&S_noto_1584_1);
  noto(&S_noto_1133_1);
  rs(&S_rs_1679_1);
  noto(&S_noto_83_1);
  samhd(&S_samhd_2319_1);
  samhd(&S_samhd_2325_1);
  newstage(&S_newstage_2323_1);
  noto(&S_noto_1996_1);
  noto(&S_noto_2002_1);
  noto(&S_noto_2004_1);
  noto(&S_noto_1975_1);
  noto(&S_noto_2113_1);
  noto(&S_noto_2105_1);
  noto(&S_noto_563_1);
  noto(&S_noto_1382_1);
  noto(&S_noto_1400_1);
  noto(&S_noto_2045_1);
  rs(&S_rs_1684_1);
  rs(&S_rs_1636_1);
  rs(&S_rs_2100_1);
  rs(&S_rs_2073_1);
  noto(&S_noto_1632_1);
  noto(&S_noto_1672_1);
  noto(&S_noto_1680_1);
  noto(&S_noto_2069_1);
  noto(&S_noto_2096_1);
  cntch(&S_cntch_317_1);
  rs(&S_rs_836_1);
  noto(&S_noto_374_1);
  noto(&S_noto_370_1);
  noto(&S_noto_660_1);
  noto(&S_noto_670_1);
  noto(&S_noto_723_1);
  cntch(&S_cntch_364_1);
  noto(&S_noto_2134_1);
  noto(&S_noto_2159_1);
  swtakt(&S_swtakt_2072_1);
  swtakt(&S_swtakt_1688_1);
  swtakt(&S_swtakt_1685_1);
  swtakt(&S_swtakt_1637_1);
  rs(&S_rs_1200_1);
  and2(&S_and2_846_1);
  and2(&S_and2_11_1);
  and2(&S_and2_119_1);
  and2(&S_and2_251_1);
  and2(&S_and2_617_1);
  or2(&S_or2_14_1);
  or2(&S_or2_8_1);
  or2(&S_or2_174_1);
  and3(&S_and3_788_1);
  and2(&S_and2_752_1);
  or3(&S_or3_826_1);
  and2(&S_and2_821_1);
  and2(&S_and2_730_1);
  or2(&S_or2_295_1);
  and3(&S_and3_311_1);
  or2(&S_or2_713_1);
  and2(&S_and2_682_1);
  and2(&S_and2_672_1);
  and4(&S_and4_673_1);
  and4(&S_and4_683_1);
  and2(&S_and2_708_1);
  or2(&S_or2_716_1);
  or2(&S_or2_719_1);
  and3(&S_and3_365_1);
  and2(&S_and2_559_1);
  or2(&S_or2_565_1);
  and2(&S_and2_630_1);
  and2(&S_and2_645_1);
  or2(&S_or2_190_1);
  and2(&S_and2_267_1);
  and2(&S_and2_282_1);
  and2(&S_and2_1105_1);
  and2(&S_and2_1581_1);
  and2(&S_and2_1379_1);
  or2(&S_or2_1385_1);
  and2(&S_and2_1395_1);
  or2(&S_or2_1404_1);
  and2(&S_and2_1128_1);
  and2(&S_and2_1138_1);
  and2(&S_and2_1633_1);
  or2(&S_or2_1690_1);
  zpfs(&S_zpfs_1643_1);
  and2(&S_and2_1676_1);
  zpfs(&S_zpfs_1696_1);
  and2(&S_and2_1681_1);
  zpfs(&S_zpfs_1702_1);
  or3(&S_or3_2318_1);
  or3(&S_or3_2327_1);
  or2(&S_or2_1992_1);
  or3(&S_or3_1994_1);
  or2(&S_or2_2032_1);
  and2(&S_and2_2040_1);
  or3(&S_or3_2037_1);
  and2(&S_and2_2062_1);
  or2(&S_or2_2187_1);
  or2(&S_or2_2176_1);
  and2(&S_and2_2155_1);
  and2(&S_and2_2153_1);
  and2(&S_and2_2138_1);
  zpfs(&S_zpfs_2077_1);
  and2(&S_and2_2078_1);
  or2(&S_or2_2074_1);
  or2(&S_or2_279_1);
  ovbs(&S_ovbs_13_1);
  noto(&S_noto_110_1);
  bol(&S_bol_1741_1);
  bol(&S_bol_1737_1);
  or2(&S_or2_1739_1);
  ml(&S_ml_1751_1);
  ml(&S_ml_1731_1);
  ml(&S_ml_1753_1);
  ml(&S_ml_1732_1);
  and2(&S_and2_125_1);
  noto(&S_noto_123_1);
  and2(&S_and2_129_1);
  and2(&S_and2_128_1);
  noto(&S_noto_195_1);
  noto(&S_noto_518_1);
  noto(&S_noto_1025_1);
  noto(&S_noto_1337_1);
  noto(&S_noto_1391_1);
  bol(&S_bol_2010_1);
  and3(&S_and3_2001_1);
  bol(&S_bol_1974_1);
  and3(&S_and3_1982_1);
  noto(&S_noto_1989_1);
  noto(&S_noto_2000_1);
  bol(&S_bol_1018_1);
  bol(&S_bol_1493_1);
  abs_subf(&S_abs_subf_1735_1);
  noto(&S_noto_1746_1);
  abs_subf(&S_abs_subf_1755_1);
  noto(&S_noto_1765_1);
  noto(&S_noto_2434_1);
  fsumo(&S_fsumo_86_1);
  abs_subf(&S_abs_subf_2475_1);
  and2(&S_and2_2479_1);
  ml(&S_ml_996_1);
  ml(&S_ml_1477_1);
  and3(&S_and3_2427_1);
  and2(&S_and2_2449_1);
  ovbs(&S_ovbs_2450_1);
  inf(&S_inf_2430_1);
  noto(&S_noto_2457_1);
  noto(&S_noto_1494_1);
  or2(&S_or2_1640_1);
  or2(&S_or2_1675_1);
  and2(&S_and2_112_1);
  and3(&S_and3_1595_1);
  noto(&S_noto_2395_1);
  noto(&S_noto_2364_1);
  diagndev(&S_diagndev_2523_1);
  or3(&S_or3_2531_1);
  ovbsb(&S_ovbsb_273_1);
  ovbsb(&S_ovbsb_258_1);
  ovbsb(&S_ovbsb_2315_1);
  ovbsb(&S_ovbsb_2314_1);
  ovbsb(&S_ovbsb_2313_1);
  ovbsb(&S_ovbsb_638_1);
  ovbsb(&S_ovbsb_622_1);
  ovbsb(&S_ovbsb_2328_1);
  ovbsb(&S_ovbsb_2329_1);
  ovbsb(&S_ovbsb_2330_1);
  ovbsb(&S_ovbsb_2471_1);
  ovbsb(&S_ovbsb_742_1);
  ovbsb(&S_ovbsb_785_1);
  ovbsb(&S_ovbsb_2065_1);
  period(&S_period_79_1);
  or2(&S_or2_2088_1);
  zpfs(&S_zpfs_1677_1);
  swtakt(&S_swtakt_2101_1);
  noto(&S_noto_1221_1);
  rs(&S_rs_827_1);
  noto(&S_noto_842_1);
  noto(&S_noto_1423_1);
  noto(&S_noto_947_1);
  noto(&S_noto_226_1);
  rs(&S_rs_694_1);
  noto(&S_noto_593_1);
  noto(&S_noto_1059_1);
  noto(&S_noto_1530_1);
  noto(&S_noto_2125_1);
  kvf(&S_kvf_2082_1);
  andn(&S_andn_1988_1);
  rs(&S_rs_19_1);
  noto(&S_noto_148_1);
  noto(&S_noto_2046_1);
  noto(&S_noto_118_1);
  noto(&S_noto_1586_1);
  abs_subf(&S_abs_subf_1139_1);
  abs_subf(&S_abs_subf_1126_1);
  noto(&S_noto_1147_1);
  bol(&S_bol_1160_1);
  bol(&S_bol_1161_1);
  noto(&S_noto_1123_1);
  bol(&S_bol_1164_1);
  bol(&S_bol_1165_1);
  bol(&S_bol_87_1);
  and2(&S_and2_31_1);
  and2(&S_and2_153_1);
  and2(&S_and2_161_1);
  and2(&S_and2_158_1);
  and2(&S_and2_150_1);
  and3(&S_and3_253_1);
  and3(&S_and3_619_1);
  and3(&S_and3_1117_1);
  or3(&S_or3_115_1);
  or2(&S_or2_743_1);
  and2(&S_and2_753_1);
  and2(&S_and2_755_1);
  and2(&S_and2_771_1);
  and2(&S_and2_772_1);
  and2(&S_and2_789_1);
  and2(&S_and2_792_1);
  and3(&S_and3_791_1);
  and2(&S_and2_793_1);
  or2(&S_or2_833_1);
  and2(&S_and2_841_1);
  or2(&S_or2_847_1);
  or2(&S_or2_851_1);
  and3(&S_and3_848_1);
  and2(&S_and2_853_1);
  and2(&S_and2_857_1);
  and2(&S_and2_726_1);
  or2(&S_or2_727_1);
  and2(&S_and2_737_1);
  and2(&S_and2_739_1);
  and2(&S_and2_706_1);
  and2(&S_and2_684_1);
  and2(&S_and2_674_1);
  and3(&S_and3_591_1);
  or2(&S_or2_641_1);
  and3(&S_and3_224_1);
  and3(&S_and3_269_1);
  and3(&S_and3_956_1);
  and3(&S_and3_957_1);
  or2(&S_or2_1101_1);
  or2(&S_or2_1574_1);
  and3(&S_and3_1432_1);
  and3(&S_and3_1433_1);
  or2(&S_or2_1166_1);
  or2(&S_or2_1176_1);
  or2(&S_or2_1172_1);
  or2(&S_or2_1171_1);
  or2(&S_or2_1170_1);
  and2(&S_and2_1598_1);
  and2(&S_and2_1644_1);
  and2(&S_and2_1697_1);
  or3(&S_or3_1712_1);
  and2(&S_and2_1703_1);
  or3(&S_or3_1718_1);
  and2(&S_and2_1719_1);
  and3(&S_and3_2147_1);
  and2(&S_and2_2142_1);
  or3(&S_or3_2148_1);
  zpfs(&S_zpfs_2109_1);
  or2(&S_or2_2102_1);
  and2(&S_and2_2110_1);
  lk(&S_lk_2089_1);
  rsfn(&S_rsfn_2091_1);
  abs_subf(&S_abs_subf_2092_1);
  and2(&S_and2_2085_1);
  and3(&S_and3_2086_1);
  or5(&S_or5_155_1);
  and2(&S_and2_2063_1);
  and2(&S_and2_113_1);
  and2(&S_and2_109_1);
  ml(&S_ml_1729_1);
  zpfs(&S_zpfs_834_1);
  and2(&S_and2_1965_1);
  and2(&S_and2_1942_1);
  and2(&S_and2_1963_1);
  and2(&S_and2_1966_1);
  and2(&S_and2_1943_1);
  and2(&S_and2_1964_1);
  and2(&S_and2_1944_1);
  and2(&S_and2_1945_1);
  and2(&S_and2_1948_1);
  and2(&S_and2_1949_1);
  and2(&S_and2_1951_1);
  and2(&S_and2_1952_1);
  and2(&S_and2_1918_1);
  and2(&S_and2_1919_1);
  rs(&S_rs_1920_1);
  and2(&S_and2_1921_1);
  and2(&S_and2_1922_1);
  rs(&S_rs_1923_1);
  and2(&S_and2_1901_1);
  and2(&S_and2_1905_1);
  and2(&S_and2_1868_1);
  and2(&S_and2_1870_1);
  and2(&S_and2_1872_1);
  and2(&S_and2_1874_1);
  and2(&S_and2_1842_1);
  and2(&S_and2_1843_1);
  and2(&S_and2_1844_1);
  and2(&S_and2_1845_1);
  and2(&S_and2_1846_1);
  and2(&S_and2_1847_1);
  and2(&S_and2_1848_1);
  and2(&S_and2_1849_1);
  and2(&S_and2_124_1);
  abs_subf(&S_abs_subf_1733_1);
  noto(&S_noto_1740_1);
  bol(&S_bol_2465_1);
  and2(&S_and2_2473_1);
  ovbs(&S_ovbs_2428_1);
  and2(&S_and2_2478_1);
  or3(&S_or3_2462_1);
  noto(&S_noto_2405_1);
  noto(&S_noto_2406_1);
  and2(&S_and2_2374_1);
  or4(&S_or4_1002_1);
  and2(&S_and2_2343_1);
  or4(&S_or4_1480_1);
  and4(&S_and4_1068_1);
  and4(&S_and4_1541_1);
  or3(&S_or3_1955_1);
  or3(&S_or3_1926_1);
  or3(&S_or3_1929_1);
  or3(&S_or3_1958_1);
  or3(&S_or3_1910_1);
  or3(&S_or3_1912_1);
  or3(&S_or3_1861_1);
  or3(&S_or3_1857_1);
  or3(&S_or3_2381_1);
  or3(&S_or3_2350_1);
  or3(&S_or3_2383_1);
  or3(&S_or3_2385_1);
  or3(&S_or3_2354_1);
  or3(&S_or3_2352_1);
  or2(&S_or2_1887_1);
  or2(&S_or2_1854_1);
  or2(&S_or2_2387_1);
  and2(&S_and2_2371_1);
  or2(&S_or2_2356_1);
  and2(&S_and2_2341_1);
  or2(&S_or2_1879_1);
  or2(&S_or2_1851_1);
  or2(&S_or2_1908_1);
  and2(&S_and2_1904_1);
  ovbsb(&S_ovbsb_232_1);
  ovbsb(&S_ovbsb_261_1);
  ovbsb(&S_ovbsb_270_1);
  ovbsb(&S_ovbsb_595_1);
  ovbsb(&S_ovbsb_626_1);
  ovbsb(&S_ovbsb_108_1);
  ovbsb(&S_ovbsb_2467_1);
  ovbsb(&S_ovbsb_2472_1);
  ovbsb(&S_ovbsb_775_1);
  ovbsb(&S_ovbsb_770_1);
  ovbsb(&S_ovbsb_761_1);
  ovbsb(&S_ovbsb_794_1);
  ovbsb(&S_ovbsb_777_1);
  ovbsb(&S_ovbsb_746_1);
  ovbsb(&S_ovbsb_750_1);
  ovbsb(&S_ovbsb_796_1);
  ovbsb(&S_ovbsb_797_1);
  ovbsb(&S_ovbsb_795_1);
  ovbsb(&S_ovbsb_2066_1);
  samhd(&S_samhd_421_1);
  samhd(&S_samhd_427_1);
  samhd(&S_samhd_875_1);
  samhd(&S_samhd_879_1);
  rs(&S_rs_843_1);
  rs(&S_rs_850_1);
  newstage(&S_newstage_424_1);
  newstage(&S_newstage_877_1);
  orn(&S_orn_154_1);
  kvf(&S_kvf_1705_1);
  rs(&S_rs_1850_1);
  rs(&S_rs_1852_1);
  rs(&S_rs_1853_1);
  rs(&S_rs_1855_1);
  rs(&S_rs_1856_1);
  rs(&S_rs_1858_1);
  rs(&S_rs_1860_1);
  rs(&S_rs_1862_1);
  rs(&S_rs_1880_1);
  rs(&S_rs_1888_1);
  rs(&S_rs_1907_1);
  rs(&S_rs_1915_1);
  rs(&S_rs_1925_1);
  rs(&S_rs_2388_1);
  rs(&S_rs_1954_1);
  rs(&S_rs_1947_1);
  rs(&S_rs_1957_1);
  rs(&S_rs_1950_1);
  rs(&S_rs_1960_1);
  rs(&S_rs_1898_1);
  rs(&S_rs_1899_1);
  rs(&S_rs_1900_1);
  rs(&S_rs_1864_1);
  rs(&S_rs_1865_1);
  rs(&S_rs_1866_1);
  rs(&S_rs_1867_1);
  rs(&S_rs_116_1);
  noto(&S_noto_117_1);
  rs(&S_rs_1706_1);
  rs(&S_rs_2087_1);
  noto(&S_noto_1711_1);
  andn(&S_andn_294_1);
  noto(&S_noto_312_1);
  and2(&S_and2_452_1);
  and2(&S_and2_464_1);
  and2(&S_and2_473_1);
  and2(&S_and2_475_1);
  and2(&S_and2_477_1);
  or3(&S_or3_417_1);
  or3(&S_or3_433_1);
  and2(&S_and2_453_1);
  and3(&S_and3_662_1);
  or2(&S_or2_157_1);
  and2(&S_and2_758_1);
  and2(&S_and2_829_1);
  or2(&S_or2_856_1);
  and2(&S_and2_733_1);
  or2(&S_or2_302_1);
  and3(&S_and3_303_1);
  or2(&S_or2_488_1);
  and3(&S_and3_497_1);
  or2(&S_or2_549_1);
  and2(&S_and2_567_1);
  and3(&S_and3_632_1);
  and3(&S_and3_631_1);
  and2(&S_and2_191_1);
  and3(&S_and3_268_1);
  or4(&S_or4_871_1);
  or4(&S_or4_886_1);
  or3(&S_or3_945_1);
  and2(&S_and2_943_1);
  and3(&S_and3_944_1);
  and2(&S_and2_942_1);
  and2(&S_and2_958_1);
  and2(&S_and2_980_1);
  and3(&S_and3_981_1);
  and2(&S_and2_1047_1);
  or2(&S_or2_1057_1);
  and2(&S_and2_1069_1);
  and2(&S_and2_1091_1);
  and3(&S_and3_1092_1);
  and3(&S_and3_1093_1);
  or2(&S_or2_1531_1);
  and2(&S_and2_1542_1);
  and2(&S_and2_1564_1);
  and3(&S_and3_1565_1);
  and3(&S_and3_1566_1);
  and2(&S_and2_1517_1);
  or3(&S_or3_1424_1);
  and3(&S_and3_1422_1);
  and2(&S_and2_1421_1);
  and2(&S_and2_1420_1);
  and2(&S_and2_1436_1);
  and2(&S_and2_1451_1);
  and3(&S_and3_1452_1);
  and2(&S_and2_1458_1);
  and3(&S_and3_1459_1);
  and2(&S_and2_1387_1);
  and2(&S_and2_1409_1);
  and2(&S_and2_1177_1);
  and2(&S_and2_1181_1);
  or3(&S_or3_1654_1);
  and2(&S_and2_1655_1);
  or3(&S_or3_1698_1);
  and2(&S_and2_1713_1);
  or2(&S_or2_1694_1);
  or3(&S_or3_1704_1);
  or2(&S_or2_1961_1);
  lk(&S_lk_1695_1);
  rsfn(&S_rsfn_1689_1);
  abs_subf(&S_abs_subf_1707_1);
  ovbs(&S_ovbs_2284_1);
  ovbs(&S_ovbs_122_1);
  and2(&S_and2_527_1);
  and2(&S_and2_489_1);
  and2(&S_and2_486_1);
  rs(&S_rs_1962_1);
  rs(&S_rs_1928_1);
  and2(&S_and2_1902_1);
  and2(&S_and2_1903_1);
  and2(&S_and2_1906_1);
  and2(&S_and2_1871_1);
  and2(&S_and2_1875_1);
  noto(&S_noto_2461_1);
  zpfs(&S_zpfs_2413_1);
  zpfs(&S_zpfs_2414_1);
  and3(&S_and3_454_1);
  rs(&S_rs_2380_1);
  rs(&S_rs_2368_1);
  rs(&S_rs_2372_1);
  and2(&S_and2_2378_1);
  rs(&S_rs_2390_1);
  rs(&S_rs_2373_1);
  and2(&S_and2_2379_1);
  rs(&S_rs_2392_1);
  rs(&S_rs_2357_1);
  rs(&S_rs_2349_1);
  rs(&S_rs_2337_1);
  rs(&S_rs_2340_1);
  and2(&S_and2_2347_1);
  rs(&S_rs_2359_1);
  rs(&S_rs_2342_1);
  and2(&S_and2_2348_1);
  rs(&S_rs_2361_1);
  regch(&S_regch_133_1);
  rs(&S_rs_1913_1);
  ovbsb(&S_ovbsb_274_1);
  ovbsb(&S_ovbsb_1435_1);
  ovbsb(&S_ovbsb_1426_1);
  ovbsb(&S_ovbsb_1428_1);
  ovbsb(&S_ovbsb_1462_1);
  ovbsb(&S_ovbsb_1441_1);
  ovbsb(&S_ovbsb_1463_1);
  ovbsb(&S_ovbsb_1456_1);
  ovbsb(&S_ovbsb_1455_1);
  ovbsb(&S_ovbsb_1096_1);
  ovbsb(&S_ovbsb_1074_1);
  ovbsb(&S_ovbsb_1097_1);
  ovbsb(&S_ovbsb_1098_1);
  ovbsb(&S_ovbsb_864_1);
  ovbsb(&S_ovbsb_865_1);
  ovbsb(&S_ovbsb_866_1);
  ovbsb(&S_ovbsb_870_1);
  ovbsb(&S_ovbsb_410_1);
  ovbsb(&S_ovbsb_411_1);
  ovbsb(&S_ovbsb_412_1);
  ovbsb(&S_ovbsb_415_1);
  ovbsb(&S_ovbsb_465_1);
  ovbsb(&S_ovbsb_449_1);
  ovbsb(&S_ovbsb_448_1);
  ovbsb(&S_ovbsb_457_1);
  ovbsb(&S_ovbsb_635_1);
  ovbsb(&S_ovbsb_637_1);
  ovbsb(&S_ovbsb_952_1);
  ovbsb(&S_ovbsb_950_1);
  ovbsb(&S_ovbsb_949_1);
  ovbsb(&S_ovbsb_984_1);
  ovbsb(&S_ovbsb_963_1);
  ovbsb(&S_ovbsb_985_1);
  ovbsb(&S_ovbsb_1569_1);
  ovbsb(&S_ovbsb_1547_1);
  ovbsb(&S_ovbsb_1570_1);
  ovbsb(&S_ovbsb_1571_1);
  ovbsb(&S_ovbsb_887_1);
  ovbsb(&S_ovbsb_891_1);
  ovbsb(&S_ovbsb_892_1);
  ovbsb(&S_ovbsb_893_1);
  ovbsb(&S_ovbsb_431_1);
  ovbsb(&S_ovbsb_438_1);
  ovbsb(&S_ovbsb_437_1);
  ovbsb(&S_ovbsb_439_1);
  ovbsb(&S_ovbsb_485_1);
  ovbsb(&S_ovbsb_476_1);
  ovbsb(&S_ovbsb_474_1);
  ovbsb(&S_ovbsb_480_1);
  ovbsb(&S_ovbsb_767_1);
  ovbsb(&S_ovbsb_735_1);
  rs(&S_rs_822_1);
  rs(&S_rs_855_1);
  rs(&S_rs_667_1);
  noto(&S_noto_681_1);
  noto(&S_noto_2285_1);
  rs(&S_rs_1882_1);
  rs(&S_rs_1890_1);
  rs(&S_rs_1909_1);
  rs(&S_rs_1911_1);
  rs(&S_rs_1917_1);
  rs(&S_rs_677_1);
  kvf(&S_kvf_1700_1);
  rs(&S_rs_1699_1);
  rs(&S_rs_1646_1);
  kvf(&S_kvf_1651_1);
  noto(&S_noto_1650_1);
  noto(&S_noto_1113_1);
  noto(&S_noto_304_1);
  noto(&S_noto_1173_1);
  noto(&S_noto_1174_1);
  noto(&S_noto_1143_1);
  and2(&S_and2_456_1);
  and2(&S_and2_479_1);
  and2(&S_and2_973_1);
  and3(&S_and3_974_1);
  and3(&S_and3_1084_1);
  and3(&S_and3_1557_1);
  and2(&S_and2_701_1);
  and2(&S_and2_1054_1);
  and2(&S_and2_1055_1);
  and3(&S_and3_1056_1);
  and2(&S_and2_1527_1);
  and2(&S_and2_1528_1);
  and3(&S_and3_1529_1);
  and5(&S_and5_1118_1);
  and2(&S_and2_1167_1);
  or4(&S_or4_1125_1);
  or2(&S_or2_1641_1);
  or3(&S_or3_1645_1);
  and3(&S_and3_1716_1);
  or2(&S_or2_2050_1);
  and2(&S_and2_2051_1);
  and2(&S_and2_2302_1);
  lk(&S_lk_1693_1);
  rsfn(&S_rsfn_1686_1);
  abs_subf(&S_abs_subf_1701_1);
  lk(&S_lk_1652_1);
  rsfn(&S_rsfn_1648_1);
  abs_subf(&S_abs_subf_1657_1);
  ovbs(&S_ovbs_2286_1);
  noto(&S_noto_2418_1);
  noto(&S_noto_2419_1);
  andn(&S_andn_665_1);
  andn(&S_andn_666_1);
  and2(&S_and2_2305_1);
  and2(&S_and2_2375_1);
  or3(&S_or3_1371_1);
  rs(&S_rs_2382_1);
  rs(&S_rs_2369_1);
  and2(&S_and2_2344_1);
  rs(&S_rs_2351_1);
  rs(&S_rs_2338_1);
  or3(&S_or3_910_1);
  or2(&S_or2_136_1);
  ovbsb(&S_ovbsb_1061_1);
  ovbsb(&S_ovbsb_1062_1);
  ovbsb(&S_ovbsb_1064_1);
  ovbsb(&S_ovbsb_1089_1);
  ovbsb(&S_ovbsb_451_1);
  ovbsb(&S_ovbsb_977_1);
  ovbsb(&S_ovbsb_979_1);
  ovbsb(&S_ovbsb_1534_1);
  ovbsb(&S_ovbsb_1537_1);
  ovbsb(&S_ovbsb_1535_1);
  ovbsb(&S_ovbsb_1562_1);
  ovbsb(&S_ovbsb_478_1);
  ovbsb(&S_ovbsb_1148_1);
  rs(&S_rs_1124_1);
  orni(&S_orni_1604_1);
  noto(&S_noto_2287_1);
  rs(&S_rs_1721_1);
  noto(&S_noto_1144_1);
  and2(&S_and2_604_1);
  and2(&S_and2_238_1);
  and2(&S_and2_960_1);
  and2(&S_and2_1071_1);
  and2(&S_and2_1544_1);
  and2(&S_and2_1438_1);
  and3(&S_and3_1130_1);
  and3(&S_and3_1136_1);
  and2(&S_and2_1154_1);
  and2(&S_and2_1141_1);
  and3(&S_and3_1188_1);
  and3(&S_and3_1661_1);
  and3(&S_and3_1715_1);
  or2(&S_or2_2048_1);
  noto(&S_noto_2425_1);
  and2(&S_and2_2376_1);
  and2(&S_and2_2345_1);
  rs(&S_rs_2370_1);
  and2(&S_and2_2377_1);
  rs(&S_rs_2386_1);
  rs(&S_rs_2339_1);
  ovbsb(&S_ovbsb_245_1);
  ovbsb(&S_ovbsb_1445_1);
  ovbsb(&S_ovbsb_1078_1);
  ovbsb(&S_ovbsb_611_1);
  ovbsb(&S_ovbsb_967_1);
  ovbsb(&S_ovbsb_1549_1);
  rs(&S_rs_2384_1);
  newstage(&S_newstage_2041_1);
  rs(&S_rs_1720_1);
  rs(&S_rs_1664_1);
  rs(&S_rs_1149_1);
  rs(&S_rs_1182_1);
  rs(&S_rs_1156_1);
  noto(&S_noto_1157_1);
  or3(&S_or3_164_1);
  or3(&S_or3_539_1);
  or2(&S_or2_1178_1);
  or2(&S_or2_1797_1);
  andn(&S_andn_2433_1);
  noto(&S_noto_2455_1);
  and2(&S_and2_2456_1);
  or2(&S_or2_2454_1);
  and3(&S_and3_2412_1);
  rs(&S_rs_2353_1);
  and2(&S_and2_2346_1);
  rs(&S_rs_2355_1);
  ovbsb(&S_ovbsb_2182_1);
  cnshd(&S_cnshd_1804_1);
  noto(&S_noto_972_1);
  ornc(&S_ornc_172_1);
  charint(&S_charint_165_1);
  noto(&S_noto_249_1);
  ornc(&S_ornc_547_1);
  charint(&S_charint_541_1);
  noto(&S_noto_615_1);
  noto(&S_noto_1081_1);
  noto(&S_noto_1552_1);
  rs(&S_rs_1168_1);
  or2(&S_or2_1825_1);
  and2(&S_and2_1767_1);
  and2(&S_and2_1768_1);
  and2(&S_and2_1769_1);
  and2(&S_and2_1770_1);
  and2(&S_and2_1780_1);
  and2(&S_and2_1782_1);
  and2(&S_and2_1784_1);
  and2(&S_and2_1155_1);
  rs(&S_rs_2453_1);
  ovbsb(&S_ovbsb_1794_1);
  ovbsb(&S_ovbsb_1772_1);
  ovbsb(&S_ovbsb_1773_1);
  ovbsb(&S_ovbsb_1775_1);
  ovbsb(&S_ovbsb_1777_1);
  ovbsb(&S_ovbsb_1786_1);
  ovbsb(&S_ovbsb_1791_1);
  fnapb(&S_fnapb_1826_1);
  samhd(&S_samhd_1807_1);
  zpfs(&S_zpfs_1822_1);
  zpfs(&S_zpfs_1818_1);
  noto(&S_noto_1449_1);
  fsumz(&S_fsumz_166_1);
  fsumz(&S_fsumz_542_1);
  orni(&S_orni_1328_1);
  rs(&S_rs_1151_1);
  rs(&S_rs_1152_1);
  ma(&S_ma_173_1);
  ma(&S_ma_548_1);
  zpfs(&S_zpfs_1832_1);
  or2(&S_or2_1272_1);
  or3(&S_or3_1150_1);
  or3(&S_or3_1815_1);
  ovbsb(&S_ovbsb_1808_1);
  ovbsb(&S_ovbsb_1819_1);
  ovbsb(&S_ovbsb_1829_1);
  ovbsb(&S_ovbsb_1828_1);
  ovbsb(&S_ovbsb_1821_1);
  ovbsb(&S_ovbsb_1813_1);
  samhd(&S_samhd_1333_1);
  samhd(&S_samhd_1343_1);
  newstage(&S_newstage_1336_1);
  cnshd(&S_cnshd_1273_1);
  noto(&S_noto_1448_1);
  noto(&S_noto_971_1);
  cnshd(&S_cnshd_176_1);
  noto(&S_noto_248_1);
  cnshd(&S_cnshd_550_1);
  noto(&S_noto_614_1);
  noto(&S_noto_1080_1);
  noto(&S_noto_1551_1);
  or2(&S_or2_1332_1);
  or2(&S_or2_1346_1);
  or2(&S_or2_1299_1);
  and2(&S_and2_1240_1);
  and2(&S_and2_1237_1);
  and2(&S_and2_1238_1);
  and2(&S_and2_1239_1);
  and2(&S_and2_1249_1);
  and2(&S_and2_1251_1);
  and2(&S_and2_1253_1);
  and2(&S_and2_703_1);
  or2(&S_or2_572_1);
  or2(&S_or2_606_1);
  or2(&S_or2_200_1);
  or2(&S_or2_240_1);
  or2(&S_or2_962_1);
  and2(&S_and2_961_1);
  or2(&S_or2_1073_1);
  or2(&S_or2_1546_1);
  or2(&S_or2_1440_1);
  and2(&S_and2_1439_1);
  and2(&S_and2_1146_1);
  or2(&S_or2_1158_1);
  and2(&S_and2_1338_1);
  and2(&S_and2_1344_1);
  ovbsb(&S_ovbsb_1446_1);
  ovbsb(&S_ovbsb_1326_1);
  ovbsb(&S_ovbsb_1327_1);
  ovbsb(&S_ovbsb_1330_1);
  ovbsb(&S_ovbsb_969_1);
  ovbsb(&S_ovbsb_1347_1);
  ovbsb(&S_ovbsb_1348_1);
  ovbsb(&S_ovbsb_1349_1);
  ovbsb(&S_ovbsb_1263_1);
  ovbsb(&S_ovbsb_1242_1);
  ovbsb(&S_ovbsb_1244_1);
  ovbsb(&S_ovbsb_1246_1);
  ovbsb(&S_ovbsb_1248_1);
  ovbsb(&S_ovbsb_1255_1);
  ovbsb(&S_ovbsb_1259_1);
  and2(&S_and2_1233_1);
  noto(&S_noto_1232_1);
  or3(&S_or3_1225_1);
  fnapb(&S_fnapb_1300_1);
  samhd(&S_samhd_1281_1);
  zpfs(&S_zpfs_1294_1);
  zpfs(&S_zpfs_1290_1);
  orn(&S_orn_1450_1);
  orn(&S_orn_968_1);
  fnapb(&S_fnapb_201_1);
  newstage(&S_newstage_211_1);
  fnapb(&S_fnapb_573_1);
  zpfs(&S_zpfs_568_1);
  zpfs(&S_zpfs_569_1);
  rs(&S_rs_1145_1);
  zpfs(&S_zpfs_1306_1);
  zpfs(&S_zpfs_588_1);
  and2(&S_and2_605_1);
  orn(&S_orn_616_1);
  zpfs(&S_zpfs_215_1);
  zpfs(&S_zpfs_193_1);
  zpfs(&S_zpfs_194_1);
  and2(&S_and2_239_1);
  and2(&S_and2_1072_1);
  and2(&S_and2_1545_1);
  and2(&S_and2_1159_1);
  or2(&S_or2_1153_1);
  or3(&S_or3_1287_1);
  and2(&S_and2_198_1);
  and2(&S_and2_196_1);
  or4(&S_or4_2165_1);
  ovbsb(&S_ovbsb_210_1);
  ovbsb(&S_ovbsb_202_1);
  ovbsb(&S_ovbsb_203_1);
  ovbsb(&S_ovbsb_204_1);
  ovbsb(&S_ovbsb_246_1);
  ovbsb(&S_ovbsb_1079_1);
  ovbsb(&S_ovbsb_581_1);
  ovbsb(&S_ovbsb_576_1);
  ovbsb(&S_ovbsb_575_1);
  ovbsb(&S_ovbsb_574_1);
  ovbsb(&S_ovbsb_612_1);
  ovbsb(&S_ovbsb_1550_1);
  ovbsb(&S_ovbsb_1298_1);
  ovbsb(&S_ovbsb_1284_1);
  ovbsb(&S_ovbsb_1303_1);
  ovbsb(&S_ovbsb_1297_1);
  ovbsb(&S_ovbsb_1292_1);
  ovbsb(&S_ovbsb_1285_1);
  noto(&S_noto_1217_1);
  orn(&S_orn_250_1);
  and2(&S_and2_1211_1);
  and2(&S_and2_710_1);
  or2(&S_or2_698_1);
  and2(&S_and2_1179_1);
  or2(&S_or2_2183_1);
  or2(&S_or2_2171_1);
  ovbs(&S_ovbs_2166_1);
  ovbs(&S_ovbs_2179_1);
  ovbs(&S_ovbs_2169_1);
  noto(&S_noto_2170_1);
  and2(&S_and2_2177_1);
  and2(&S_and2_2188_1);
  or3(&S_or3_134_1);
  noto(&S_noto_132_1);
  rs(&S_rs_699_1);
  noto(&S_noto_2167_1);
  noto(&S_noto_2180_1);
  rs(&S_rs_2184_1);
  noto(&S_noto_2185_1);
  rs(&S_rs_2172_1);
  rs(&S_rs_1162_1);
  noto(&S_noto_1169_1);
  rs(&S_rs_1197_1);
  rs(&S_rs_1203_1);
  and2(&S_and2_717_1);
  and3(&S_and3_686_1);
  and3(&S_and3_676_1);
  or3(&S_or3_904_1);
  or3(&S_or3_1367_1);
  and4(&S_and4_1131_1);
  and4(&S_and4_1137_1);
  or2(&S_or2_2139_1);
  irm(&S_irm_2408_1);
  or4(&S_or4_993_1);
  or4(&S_or4_1471_1);
  and2(&S_and2_53_1);
  or3(&S_or3_1202_1);
  ornc(&S_ornc_1003_1);
  charint(&S_charint_994_1);
  ornc(&S_ornc_1481_1);
  charint(&S_charint_1475_1);
  noto(&S_noto_2173_1);
  noto(&S_noto_69_1);
  swtakt(&S_swtakt_54_1);
  noto(&S_noto_2140_1);
  rs(&S_rs_1201_1);
  and2(&S_and2_61_1);
  and2(&S_and2_65_1);
  and4(&S_and4_359_1);
  and2(&S_and2_1559_1);
  or2(&S_or2_1592_1);
  or2(&S_or2_2262_1);
  or2(&S_or2_2156_1);
  and2(&S_and2_2137_1);
  and2(&S_and2_2107_1);
  and4(&S_and4_2108_1);
  and4(&S_and4_2114_1);
  or2(&S_or2_2117_1);
  or2(&S_or2_2119_1);
  or2(&S_or2_2118_1);
  zpfs(&S_zpfs_2121_1);
  zpfs(&S_zpfs_2124_1);
  and4(&S_and4_2128_1);
  and4(&S_and4_2130_1);
  or3(&S_or3_2126_1);
  and2(&S_and2_1086_1);
  and2(&S_and2_2263_1);
  ovbsb(&S_ovbsb_1087_1);
  ovbsb(&S_ovbsb_1560_1);
  or4(&S_or4_2546_1);
  or2(&S_or2_2306_1);
  or2(&S_or2_2307_1);
  fsumz(&S_fsumz_995_1);
  orn(&S_orn_1082_1);
  fsumz(&S_fsumz_1476_1);
  orn(&S_orn_1553_1);
  kvf(&S_kvf_2123_1);
  noto(&S_noto_1588_1);
  rs(&S_rs_362_1);
  noto(&S_noto_357_1);
  noto(&S_noto_299_1);
  rs(&S_rs_2157_1);
  rs(&S_rs_2158_1);
  ma(&S_ma_1482_1);
  ma(&S_ma_1004_1);
  or4(&S_or4_310_1);
  or2(&S_or2_293_1);
  or2(&S_or2_316_1);
  or2(&S_or2_354_1);
  or4(&S_or4_363_1);
  and2(&S_and2_1587_1);
  or2(&S_or2_2291_1);
  or2(&S_or2_2298_1);
  zpfs(&S_zpfs_2264_1);
  and2(&S_and2_2120_1);
  lk(&S_lk_2127_1);
  rsfn(&S_rsfn_2131_1);
  abs_subf(&S_abs_subf_2133_1);
  and3(&S_and3_2136_1);
  and2(&S_and2_2277_1);
  and2(&S_and2_2290_1);
  and2(&S_and2_2276_1);
  or5(&S_or5_2303_1);
  and2(&S_and2_2301_1);
  or2(&S_or2_2220_1);
  or2(&S_or2_2241_1);
  or3(&S_or3_2259_1);
  ovbsb(&S_ovbsb_2271_1);
  ovbsb(&S_ovbsb_2272_1);
  ovbsb(&S_ovbsb_2283_1);
  ovbsb(&S_ovbsb_2300_1);
  or3(&S_or3_2547_1);
  cnshd(&S_cnshd_1005_1);
  cnshd(&S_cnshd_1483_1);
  rs(&S_rs_309_1);
  rs(&S_rs_2292_1);
  ma(&S_ma_1653_1);
  rs(&S_rs_2141_1);
  provsbr(&S_provsbr_1600_1);
  rs(&S_rs_1599_1);
  provsbr(&S_provsbr_298_1);
  equz_p(&S_equz_p_337_1);
  bolz(&S_bolz_338_1);
  provsbr(&S_provsbr_356_1);
  bolz(&S_bolz_361_1);
  noto(&S_noto_70_1);
  noto(&S_noto_59_1);
  and2(&S_and2_62_1);
  and2(&S_and2_66_1);
  or2(&S_or2_63_1);
  and2(&S_and2_634_1);
  and2(&S_and2_633_1);
  or3(&S_or3_649_1);
  and2(&S_and2_313_1);
  and4(&S_and4_343_1);
  and2(&S_and2_325_1);
  or2(&S_or2_315_1);
  and2(&S_and2_320_1);
  or2(&S_or2_367_1);
  and2(&S_and2_358_1);
  or5(&S_or5_561_1);
  and2(&S_and2_271_1);
  and2(&S_and2_272_1);
  or3(&S_or3_286_1);
  or2(&S_or2_1034_1);
  and2(&S_and2_1095_1);
  and2(&S_and2_1094_1);
  and2(&S_and2_1567_1);
  and2(&S_and2_1568_1);
  or2(&S_or2_1508_1);
  and2(&S_and2_1607_1);
  and2(&S_and2_1611_1);
  and2(&S_and2_1615_1);
  and2(&S_and2_1623_1);
  or2(&S_or2_1608_1);
  or2(&S_or2_1612_1);
  or2(&S_or2_1616_1);
  or2(&S_or2_1624_1);
  or2(&S_or2_1589_1);
  or4(&S_or4_1583_1);
  or4(&S_or4_1109_1);
  or5(&S_or5_2304_1);
  ovbsb(&S_ovbsb_277_1);
  ovbsb(&S_ovbsb_278_1);
  ovbsb(&S_ovbsb_1099_1);
  ovbsb(&S_ovbsb_1100_1);
  ovbsb(&S_ovbsb_639_1);
  ovbsb(&S_ovbsb_640_1);
  ovbsb(&S_ovbsb_1572_1);
  ovbsb(&S_ovbsb_1573_1);
  and2(&S_and2_1629_1);
  or2(&S_or2_1606_1);
  or2(&S_or2_1610_1);
  or2(&S_or2_1614_1);
  or2(&S_or2_1619_1);
  or2(&S_or2_1626_1);
  and2(&S_and2_1235_1);
  noto(&S_noto_1234_1);
  or3(&S_or3_1227_1);
  fnapb(&S_fnapb_1035_1);
  zpfs(&S_zpfs_1027_1);
  zpfs(&S_zpfs_1028_1);
  newstage(&S_newstage_1017_1);
  fnapb(&S_fnapb_1509_1);
  zpfs(&S_zpfs_1501_1);
  zpfs(&S_zpfs_1500_1);
  maz(&S_maz_324_1);
  maz(&S_maz_333_1);
  rs(&S_rs_2294_1);
  orni(&S_orni_1340_1);
  rs(&S_rs_366_1);
  decatron(&S_decatron_321_1);
  noto(&S_noto_336_1);
  zpfs(&S_zpfs_1052_1);
  zpfs(&S_zpfs_1525_1);
  or2(&S_or2_319_1);
  or2(&S_or2_328_1);
  or2(&S_or2_342_1);
  or2(&S_or2_341_1);
  and2(&S_and2_345_1);
  and2(&S_and2_340_1);
  and2(&S_and2_347_1);
  and2(&S_and2_346_1);
  and3(&S_and3_326_1);
  or5(&S_or5_188_1);
  or2(&S_or2_1630_1);
  orni(&S_orni_1620_1);
  and2(&S_and2_1590_1);
  or2(&S_or2_2280_1);
  or2(&S_or2_2268_1);
  or2(&S_or2_2252_1);
  or3(&S_or3_1585_1);
  or3(&S_or3_1112_1);
  zpfs(&S_zpfs_339_1);
  and2(&S_and2_1023_1);
  and2(&S_and2_1026_1);
  and2(&S_and2_1497_1);
  and2(&S_and2_1021_1);
  and2(&S_and2_2267_1);
  and2(&S_and2_2261_1);
  and2(&S_and2_2281_1);
  ovbsb(&S_ovbsb_1046_1);
  ovbsb(&S_ovbsb_1029_1);
  ovbsb(&S_ovbsb_1039_1);
  ovbsb(&S_ovbsb_1040_1);
  ovbsb(&S_ovbsb_2266_1);
  ovbsb(&S_ovbsb_1519_1);
  ovbsb(&S_ovbsb_1516_1);
  ovbsb(&S_ovbsb_1506_1);
  ovbsb(&S_ovbsb_1507_1);
  ovbsb(&S_ovbsb_2260_1);
  noto(&S_noto_1219_1);
  zzfs(&S_zzfs_2554_1);
  rs(&S_rs_2253_1);
  noto(&S_noto_2254_1);
  noto(&S_noto_2295_1);
  equz_p(&S_equz_p_327_1);
  noto(&S_noto_1596_1);
  cntch(&S_cntch_1617_1);
  rs(&S_rs_318_1);
  and2(&S_and2_1212_1);
  and2(&S_and2_332_1);
  and2(&S_and2_709_1);
  or5(&S_or5_1020_1);
  or5(&S_or5_1496_1);
  and2(&S_and2_1187_1);
  and2(&S_and2_1621_1);
  or5(&S_or5_1622_1);
  or5(&S_or5_1591_1);
  and2(&S_and2_1593_1);
  or2(&S_or2_1594_1);
  zpfs(&S_zpfs_2275_1);
  and4(&S_and4_2143_1);
  and3(&S_and3_2144_1);
  and3(&S_and3_2145_1);
  and2(&S_and2_2106_1);
  and2(&S_and2_2070_1);
  or3(&S_or3_2079_1);
  or3(&S_or3_2274_1);
  rs(&S_rs_2269_1);
  noto(&S_noto_2270_1);
  rs(&S_rs_2112_1);
  rs(&S_rs_2080_1);
  rs(&S_rs_1180_1);
  noto(&S_noto_1183_1);
  rs(&S_rs_1206_1);
  and2(&S_and2_352_1);
  and3(&S_and3_1175_1);
  and2(&S_and2_1122_1);
  and4(&S_and4_1129_1);
  and4(&S_and4_1135_1);
  or3(&S_or3_2111_1);
  orn(&S_orn_1359_1);
  orn(&S_orn_898_1);
  or3(&S_or3_1205_1);
  ornc(&S_ornc_1368_1);
  charint(&S_charint_1360_1);
  ornc(&S_ornc_905_1);
  charint(&S_charint_899_1);
  noto(&S_noto_353_1);
  rs(&S_rs_1116_1);
  rs(&S_rs_1204_1);
  or3(&S_or3_487_1);
  and3(&S_and3_496_1);
  and2(&S_and2_1163_1);
  and2(&S_and2_532_1);
  and2(&S_and2_498_1);
  fsumz(&S_fsumz_1361_1);
  fsumz(&S_fsumz_900_1);
  samhd(&S_samhd_511_1);
  samhd(&S_samhd_517_1);
  newstage(&S_newstage_513_1);
  ma(&S_ma_906_1);
  ma(&S_ma_1369_1);
  or4(&S_or4_507_1);
  or4(&S_or4_526_1);
  andn(&S_andn_1_1);
  and2(&S_and2_522_1);
  and2(&S_and2_519_1);
  ovbsb(&S_ovbsb_503_1);
  ovbsb(&S_ovbsb_500_1);
  ovbsb(&S_ovbsb_501_1);
  ovbsb(&S_ovbsb_502_1);
  ovbsb(&S_ovbsb_525_1);
  ovbsb(&S_ovbsb_529_1);
  ovbsb(&S_ovbsb_530_1);
  ovbsb(&S_ovbsb_531_1);
  cnshd(&S_cnshd_1370_1);
  cnshd(&S_cnshd_909_1);
  and2(&S_and2_1213_1);
  and2(&S_and2_725_1);
  or2(&S_or2_926_1);
  and2(&S_and2_983_1);
  and2(&S_and2_982_1);
  or3(&S_or3_992_1);
  and2(&S_and2_1460_1);
  and2(&S_and2_1461_1);
  or3(&S_or3_1470_1);
  or2(&S_or2_1403_1);
  and2(&S_and2_1194_1);
  ovbsb(&S_ovbsb_1464_1);
  ovbsb(&S_ovbsb_1465_1);
  ovbsb(&S_ovbsb_989_1);
  ovbsb(&S_ovbsb_986_1);
  and2(&S_and2_1231_1);
  noto(&S_noto_1230_1);
  or3(&S_or3_1223_1);
  fnapb(&S_fnapb_1405_1);
  zpfs(&S_zpfs_1397_1);
  zpfs(&S_zpfs_1398_1);
  newstage(&S_newstage_1410_1);
  fnapb(&S_fnapb_927_1);
  rs(&S_rs_1189_1);
  rs(&S_rs_1209_1);
  zpfs(&S_zpfs_1415_1);
  zpfs(&S_zpfs_939_1);
  zpfs(&S_zpfs_921_1);
  zpfs(&S_zpfs_922_1);
  or5(&S_or5_1380_1);
  and2(&S_and2_1392_1);
  and2(&S_and2_1396_1);
  or5(&S_or5_2190_1);
  or3(&S_or3_1885_1);
  or3(&S_or3_1877_1);
  or2(&S_or2_1891_1);
  or2(&S_or2_1883_1);
  ovbsb(&S_ovbsb_925_1);
  ovbsb(&S_ovbsb_924_1);
  ovbsb(&S_ovbsb_934_1);
  ovbsb(&S_ovbsb_929_1);
  ovbsb(&S_ovbsb_1412_1);
  ovbsb(&S_ovbsb_1393_1);
  ovbsb(&S_ovbsb_1390_1);
  ovbsb(&S_ovbsb_1408_1);
  noto(&S_noto_1215_1);
  or3(&S_or3_1208_1);
  zzfs(&S_zzfs_2556_1);
  orni(&S_orni_140_1);
  orn(&S_orn_459_1);
  orn(&S_orn_481_1);
  rs(&S_rs_1876_1);
  rs(&S_rs_1884_1);
  rs(&S_rs_1207_1);
  or2(&S_or2_461_1);
  or2(&S_or2_483_1);
  and2(&S_and2_757_1);
  or2(&S_or2_1315_1);
  or2(&S_or2_1316_1);
  and2(&S_and2_1252_1);
  or5(&S_or5_918_1);
  and2(&S_and2_1783_1);
  or4(&S_or4_1779_1);
  and2(&S_and2_1869_1);
  and2(&S_and2_1873_1);
  or4(&S_or4_2191_1);
  ovbsb(&S_ovbsb_1792_1);
  ovbsb(&S_ovbsb_1260_1);
  ovbsb(&S_ovbsb_766_1);
  or3(&S_or3_1199_1);
  orn(&S_orn_854_1);
  orn(&S_orn_1236_1);
  rs(&S_rs_1878_1);
  rs(&S_rs_1886_1);
  rs(&S_rs_1198_1);
  or2(&S_or2_844_1);
  or2(&S_or2_845_1);
  or4(&S_or4_825_1);
  and4(&S_and4_1196_1);
  or5(&S_or5_1283_1);
  or2(&S_or2_387_1);
  or2(&S_or2_391_1);
  ovbs(&S_ovbs_2197_1);
  noto(&S_noto_2198_1);
  and2(&S_and2_2204_1);
  and2(&S_and2_2216_1);
  or3(&S_or3_2192_1);
  and2(&S_and2_2193_1);
  or3(&S_or3_2206_1);
  and2(&S_and2_2207_1);
  or5(&S_or5_1766_1);
  or2(&S_or2_2444_1);
  rs(&S_rs_824_1);
  samhd(&S_samhd_390_1);
  and2(&S_and2_812_1);
  or2(&S_or2_814_1);
  or4(&S_or4_389_1);
  or5(&S_or5_1812_1);
  or2(&S_or2_2211_1);
  or2(&S_or2_2199_1);
  ovbs(&S_ovbs_2194_1);
  ovbs(&S_ovbs_2208_1);
  rs(&S_rs_2228_1);
  rs(&S_rs_2236_1);
  noto(&S_noto_2226_1);
  noto(&S_noto_2247_1);
  zpfs(&S_zpfs_2229_1);
  zpfs(&S_zpfs_2237_1);
  noto(&S_noto_2440_1);
  ovbsb(&S_ovbsb_396_1);
  ovbsb(&S_ovbsb_397_1);
  ovbsb(&S_ovbsb_398_1);
  rs(&S_rs_818_1);
  or2(&S_or2_2230_1);
  noto(&S_noto_2195_1);
  noto(&S_noto_2209_1);
  rs(&S_rs_2212_1);
  noto(&S_noto_2213_1);
  rs(&S_rs_2200_1);
  or2(&S_or2_2238_1);
  noto(&S_noto_2231_1);
  and2(&S_and2_2232_1);
  and2(&S_and2_2227_1);
  noto(&S_noto_2239_1);
  noto(&S_noto_2219_1);
  ovbsb(&S_ovbsb_2218_1);
  noto(&S_noto_2201_1);
  and2(&S_and2_2240_1);
  and4(&S_and4_2221_1);
  ovbs(&S_ovbs_2222_1);
  and2(&S_and2_2248_1);
  noto(&S_noto_2250_1);
  or2(&S_or2_2223_1);
  ovbsb(&S_ovbsb_2251_1);
  orn(&S_orn_669_1);
  orn(&S_orn_668_1);
  noto(&S_noto_2224_1);
  and4(&S_and4_2242_1);
  ovbs(&S_ovbs_2243_1);
  or2(&S_or2_2244_1);
  newstage(&S_newstage_671_1);
  or2(&S_or2_705_1);
  ovbs(&S_ovbs_2233_1);
  noto(&S_noto_2245_1);
  and2(&S_and2_704_1);
  setData(idpsrb2,&var2);
  setData(idpsrb1,&var3);
  setData(idpsrb4,&var1);
  setData(idpsb2,&var4);
  setData(idpsb1,&var5);
  setData(idR0S01LIM,&var1254);
  setData(idR0AD16LDU,&var1249);
  setData(idR0S01LZ2,&var31);
  setData(idR0S01LZ1,&var31);
  setData(idR0S01LDU,&var32);
  setData(idR8AD21LDU,&var1253);
  setData(idR0VN15RDU,&var45);
  setData(idB3CV01RDU,&var1551);
  setData(idTestDiagnDU,&var258);
  setData(idR0DE3CLDU,&var260);
  setData(idR0DE3DLDU,&var259);
  setData(idTTLDU,&var262);
  setData(idB3AB13LDU,&var120);
  setData(idA3AB13LDU,&var206);
  setData(idR3VS01IDU,&var391);
  setData(idR3VS12LDU,&var389);
  setData(idR3VS22LDU,&var390);
  setData(idR5VS01IDU,&var388);
  setData(idR5VS12LDU,&var386);
  setData(idR5VS22LDU,&var387);
  setData(idB3AB15LDU,&var122);
  setData(idB3EE03LDU,&var1046);
  setData(idA3EE03LDU,&var1047);
  setData(idB3AB19LDU,&var121);
  setData(idA3AB19LDU,&var200);
  setData(idR0VL23LDU,&var1286);
  setData(idR0VL22LDU,&var1308);
  setData(idR0AD05LZ2,&var327);
  setData(idR0AD05LZ1,&var327);
  setData(idR0AD04LZ2,&var30);
  setData(idR0AD04LZ1,&var30);
  setData(idR0AD03LZ2,&var326);
  setData(idR0AD03LZ1,&var326);
  setData(idR0CN95LDU,&var466);
  setData(idR0CN94LDU,&var465);
  setData(idR0CN93LDU,&var464);
  setData(idR0AB19LDU,&var76);
  setData(idR0VN12RDU,&var1215);
  setData(idR0VN11RDU,&var1213);
  setData(idR0CN92LDU,&var432);
  setData(idR0AB20LDU,&var75);
  setData(idA3AB15LDU,&var204);
  setData(idA3MC03RDU,&var462);
  setData(idR0CN91LDU,&var461);
  setData(idA3MC02RDU,&var460);
  setData(idA3MC01RDU,&var459);
  setData(idR0AB18LDU,&var77);
  setData(idR0AB17LDU,&var78);
  setData(idR0AB16LDU,&var79);
  setData(idB1AB19LDU,&var151);
  setData(idA3ZAV,&var1556);
  setData(idA1ZAV,&var1619);
  setData(idB3IS12LDU,&var483);
  setData(idA3IS12LDU,&var484);
  setData(idR0AB15LDU,&var489);
  setData(idR0AB14LDU,&var487);
  setData(idA4DW,&var1396);
  setData(idA4UP,&var1397);
  setData(idR4ABL,&var1858);
  setData(idA9ZAV,&var1494);
  setData(idA8ZAV,&var1695);
  setData(idA2ZAV,&var1700);
  setData(idB8ZAV,&var1705);
  setData(idA5ZAV,&var1773);
  setData(idR2ZAV,&var1649);
  setData(idA6ZAV,&var1775);
  setData(idA4ZAV,&var1774);
  setData(idR0AB13LDU,&var556);
  setData(idR0AB12LDU,&var560);
  setData(idR0AB11LDU,&var564);
  setData(idR0AB10LDU,&var568);
  setData(idR0AB09LDU,&var572);
  setData(idR0AB08LDU,&var80);
  setData(idB6AB05LDU,&var103);
  setData(idR0VS11LDU,&var1928);
  setData(idA8VS01IDU,&var1699);
  setData(idB8VS01IDU,&var1709);
  setData(idR2AD10LDU,&var1654);
  setData(idR2AD20LDU,&var1655);
  setData(idB6VS01IDU,&var1846);
  setData(idR0AB07LDU,&var81);
  setData(idR0EE03LDU,&var641);
  setData(idR0VX02LDU,&var1052);
  setData(idR0AD21LDU,&var1050);
  setData(idB2AB15LDU,&var137);
  setData(idA2AB15LDU,&var221);
  setData(idR0AB05LDU,&var1368);
  setData(idR0AB03LDU,&var1379);
  setData(idA1AB19LDU,&var232);
  setData(idR0VZ71LDU,&var313);
  setData(idR0VL01RDU,&var1414);
  setData(idB7AZ03LDU,&var46);
  setData(idA7AZ03LDU,&var47);
  setData(idB2VS01IDU,&var1687);
  setData(idB2VS21LDU,&var1689);
  setData(idB2VS11LDU,&var1688);
  setData(idR0VP73LDU,&var728);
  setData(idR0VS18LDU,&var805);
  setData(idB3VX01LDU,&var675);
  setData(idA3VX01LDU,&var676);
  setData(idB2VS32LDU,&var602);
  setData(idA2VS32LDU,&var603);
  setData(idR0VS17LDU,&var795);
  setData(idR0VX09LDU,&var420);
  moveData(idR0VX08IDU,idR0MW12IP1);
  setData(idR0VW23LDU,&var1147);
  setData(idR0VW13LDU,&var1146);
  setData(idB7AP31LDU,&var1399);
  setData(idA7AP31LDU,&var1400);
  setData(idB3AD31LDU,&var1457);
  setData(idB3AD34LDU,&var1458);
  setData(idA3AD31LDU,&var1463);
  setData(idA3AD34LDU,&var1460);
  setData(idA3AD33LDU,&var1462);
  setData(idB2AD33LDU,&var581);
  setData(idA2AD33LDU,&var584);
  setData(idR0AB01LDU,&var1486);
  setData(idB9AB02LDU,&var82);
  setData(idB9AB01LDU,&var83);
  setData(idB9AZ03LDU,&var84);
  setData(idA9AB02LDU,&var168);
  setData(idA9AB01LDU,&var167);
  setData(idA9AZ03LDU,&var166);
  setData(idA9AD10LDU,&var1504);
  setData(idB9AD10LDU,&var1498);
  setData(idR1VS01IDU,&var1665);
  setData(idR2VS01IDU,&var1656);
  setData(idR4VS01IDU,&var1837);
  setData(idA6VS01IDU,&var1855);
  setData(idB5VS01IDU,&var1819);
  setData(idA5VS01IDU,&var1828);
  setData(idB4VS22LDU,&var1800);
  setData(idB4VS12LDU,&var1799);
  setData(idB4VS01IDU,&var1801);
  setData(idA4VS22LDU,&var1809);
  setData(idA4VS12LDU,&var1808);
  setData(idA4VS01IDU,&var1810);
  setData(idA2VS01IDU,&var1728);
  setData(idB3VS01IDU,&var1546);
  setData(idA3VS01IDU,&var1578);
  setData(idB1VS01IDU,&var1607);
  setData(idA1VS01IDU,&var1640);
  setData(idR0VS21IDU,&var1389);
  setData(idR0VX03LDU,&var997);
  setData(idR0VL21IDU,&var1299);
  setData(idR0VL05RDU,&var662);
  setData(idR0VL03RDU,&var668);
  setData(idR0AB02LDU,&var1362);
  setData(idR0AB06LDU,&var1365);
  setData(idR0AB04LDU,&var1373);
  setData(idR0VL04RDU,&var665);
  setData(idR0VL02RDU,&var659);
  setData(idB3AD33LDU,&var1456);
  setData(idR0VL06RDU,&var672);
  setData(idR0VL11IDU,&var1510);
  setData(idR0VL01IDU,&var1511);
  setData(idR0VX01LDU,&var1054);
  setData(idB1AD32LDU,&var1464);
  setData(idA1AD32LDU,&var1466);
  setData(idB2AD32LDU,&var609);
  setData(idA2AD32LDU,&var611);
  setData(idB1AD31LDU,&var1467);
  setData(idA1AD31LDU,&var1468);
  setData(idB2AD31LDU,&var612);
  setData(idA2AD31LDU,&var613);
  setData(idB3AB20LDU,&var115);
  setData(idB3AB18LDU,&var118);
  setData(idB3AB17LDU,&var116);
  setData(idB3AB16LDU,&var117);
  setData(idB3AB14LDU,&var119);
  setData(idB3AB12LDU,&var123);
  setData(idB3AB11LDU,&var124);
  setData(idB3AB10LDU,&var125);
  setData(idB3AB09LDU,&var126);
  setData(idB3AB06LDU,&var129);
  setData(idB3AB05LDU,&var130);
  setData(idB3AB08LDU,&var127);
  setData(idB3AB07LDU,&var128);
  setData(idB3CV02RDU,&var1545);
  setData(idB3AD01LDU,&var1538);
  setData(idB3AD05LDU,&var1544);
  setData(idB3AD04LDU,&var1543);
  setData(idB3AD03LDU,&var1542);
  setData(idB3AD02LDU,&var1541);
  setData(idB3AD21LDU,&var1539);
  setData(idB3AD11LDU,&var1540);
  setData(idB3AZ03LDU,&var134);
  setData(idB3VS22LDU,&var1549);
  setData(idB3AB01LDU,&var132);
  setData(idB3AB02LDU,&var131);
  setData(idB3AB04LDU,&var133);
  setData(idB3VS12LDU,&var1550);
  setData(idA3AB20LDU,&var199);
  setData(idA3AB18LDU,&var201);
  setData(idA3AB17LDU,&var202);
  setData(idA3AB16LDU,&var203);
  setData(idA3AB14LDU,&var205);
  setData(idA3AB12LDU,&var207);
  setData(idA3AB11LDU,&var208);
  setData(idA3AB10LDU,&var209);
  setData(idA3AB09LDU,&var210);
  setData(idA3AB06LDU,&var212);
  setData(idA3AB05LDU,&var214);
  setData(idA3AB08LDU,&var211);
  setData(idA3AB07LDU,&var213);
  setData(idA3CV02RDU,&var1577);
  setData(idA3AD01LDU,&var1570);
  setData(idA3AD05LDU,&var1576);
  setData(idA3AD04LDU,&var1575);
  setData(idA3AD03LDU,&var1574);
  setData(idA3AD02LDU,&var1573);
  setData(idA3AD21LDU,&var1571);
  setData(idA3AD11LDU,&var1572);
  setData(idA3AZ03LDU,&var218);
  setData(idA3VS22LDU,&var1581);
  setData(idA3AB01LDU,&var215);
  setData(idA3AB02LDU,&var216);
  setData(idA3AB04LDU,&var217);
  setData(idA3CV01RDU,&var1583);
  setData(idA3VS12LDU,&var1582);
  setData(idB1AB18LDU,&var148);
  setData(idB1AB17LDU,&var149);
  setData(idB1AB16LDU,&var150);
  setData(idB1AB14LDU,&var152);
  setData(idB1AB13LDU,&var153);
  setData(idB1AB12LDU,&var154);
  setData(idB1AB11LDU,&var155);
  setData(idB1AB10LDU,&var156);
  setData(idB1AB09LDU,&var157);
  setData(idB1AB06LDU,&var159);
  setData(idB1AB05LDU,&var161);
  setData(idB1AB08LDU,&var158);
  setData(idB1AB07LDU,&var160);
  setData(idB1CV02RDU,&var1606);
  setData(idB1AD01LDU,&var1599);
  setData(idB1AD05LDU,&var1605);
  setData(idB1AD04LDU,&var1604);
  setData(idB1AD03LDU,&var1603);
  setData(idB1AD02LDU,&var1602);
  setData(idB1AD21LDU,&var1601);
  setData(idB1AD11LDU,&var1600);
  setData(idB1AZ03LDU,&var165);
  setData(idB1VS22LDU,&var1611);
  setData(idB1AB01LDU,&var162);
  setData(idB1AB02LDU,&var163);
  setData(idB1AB04LDU,&var164);
  setData(idB1CV01RDU,&var1612);
  setData(idB1VS12LDU,&var1610);
  setData(idA1AB18LDU,&var233);
  setData(idA1AB17LDU,&var234);
  setData(idA1AB16LDU,&var235);
  setData(idA1AB14LDU,&var236);
  setData(idA1AB13LDU,&var237);
  setData(idA1AB12LDU,&var238);
  setData(idA1AB11LDU,&var239);
  setData(idA1AB10LDU,&var240);
  setData(idA1AB09LDU,&var241);
  setData(idA1AB06LDU,&var244);
  setData(idA1AB05LDU,&var245);
  setData(idA1AB08LDU,&var242);
  setData(idA1AB07LDU,&var243);
  setData(idA1CV02RDU,&var1639);
  setData(idA1AD01LDU,&var1632);
  setData(idA1AD05LDU,&var1638);
  setData(idA1AD04LDU,&var1637);
  setData(idA1AD03LDU,&var1636);
  setData(idA1AD02LDU,&var1635);
  setData(idA1AD21LDU,&var1634);
  setData(idA1AD11LDU,&var1633);
  setData(idA1AZ03LDU,&var249);
  setData(idA1VS22LDU,&var1642);
  setData(idA1AB01LDU,&var248);
  setData(idA1AB02LDU,&var247);
  setData(idA1AB04LDU,&var246);
  setData(idA1CV01RDU,&var1643);
  setData(idA1VS12LDU,&var1641);
  setData(idR1AD20LDU,&var1664);
  setData(idR1AD10LDU,&var1663);
  setData(idR2AB04LDU,&var67);
  setData(idR1AB04LDU,&var71);
  setData(idR2AB02LDU,&var68);
  setData(idR2AB01LDU,&var69);
  setData(idR2AZ03LDU,&var70);
  setData(idR1AB02LDU,&var72);
  setData(idR1AB01LDU,&var73);
  setData(idR1AZ03LDU,&var74);
  setData(idB2AB17LDU,&var135);
  setData(idB2AB16LDU,&var136);
  setData(idB2AB14LDU,&var138);
  setData(idB2AB13LDU,&var139);
  setData(idB2AB12LDU,&var140);
  setData(idB2AB11LDU,&var141);
  setData(idB2AB10LDU,&var142);
  setData(idB2AB09LDU,&var143);
  setData(idB2AB06LDU,&var146);
  setData(idB2AB05LDU,&var147);
  setData(idB2AB08LDU,&var144);
  setData(idB2AB07LDU,&var145);
  setData(idB2CV02RDU,&var1686);
  setData(idB2AD01LDU,&var1679);
  setData(idB2AD05LDU,&var1685);
  setData(idB2AD04LDU,&var1684);
  setData(idB2AD03LDU,&var1683);
  setData(idB2AD02LDU,&var1682);
  setData(idB2AD21LDU,&var1681);
  setData(idB2AD11LDU,&var1680);
  setData(idB2AZ03LDU,&var255);
  setData(idB2AB01LDU,&var256);
  setData(idB2AB02LDU,&var257);
  setData(idB2AB04LDU,&var254);
  setData(idB2CV01RDU,&var1690);
  setData(idA2CV02RDU,&var1727);
  setData(idA2AD01LDU,&var1720);
  setData(idA2AB17LDU,&var219);
  setData(idA2AB16LDU,&var220);
  setData(idA2AB14LDU,&var222);
  setData(idA2AB13LDU,&var223);
  setData(idA2AB12LDU,&var224);
  setData(idA2AB11LDU,&var225);
  setData(idA2AB10LDU,&var226);
  setData(idA2AB09LDU,&var227);
  setData(idA2AB06LDU,&var229);
  setData(idA2AB05LDU,&var231);
  setData(idA2AB08LDU,&var228);
  setData(idA2AB07LDU,&var230);
  setData(idA2AD05LDU,&var1726);
  setData(idA2AD04LDU,&var1725);
  setData(idA2AD03LDU,&var1724);
  setData(idA2AD02LDU,&var1723);
  setData(idA2AD21LDU,&var1722);
  setData(idA2AD11LDU,&var1721);
  setData(idA2AZ03LDU,&var253);
  setData(idA2VS21LDU,&var1732);
  setData(idA2AB01LDU,&var252);
  setData(idA2AB02LDU,&var251);
  setData(idA2AB04LDU,&var250);
  setData(idA2CV01RDU,&var1733);
  setData(idA2VS11LDU,&var1731);
  setData(idA8AB01LDU,&var182);
  setData(idA8AB02LDU,&var181);
  setData(idA8AB14LDU,&var169);
  setData(idA8AB13LDU,&var170);
  setData(idA8AB12LDU,&var171);
  setData(idA8AB11LDU,&var172);
  setData(idA8AB10LDU,&var173);
  setData(idA8AB09LDU,&var174);
  setData(idA8AB08LDU,&var175);
  setData(idA8AB04LDU,&var180);
  setData(idA8AD20LDU,&var1698);
  setData(idA8AD10LDU,&var1697);
  setData(idA8AZ03LDU,&var179);
  setData(idA8VS22LDU,&var1745);
  setData(idA8AB05LDU,&var176);
  setData(idA8AB07LDU,&var177);
  setData(idA8AB06LDU,&var178);
  setData(idA8CV01RDU,&var1746);
  setData(idA8VS12LDU,&var1744);
  setData(idB8AB02LDU,&var96);
  setData(idB8AB14LDU,&var85);
  setData(idB8AB13LDU,&var86);
  setData(idB8AB12LDU,&var87);
  setData(idB8AB11LDU,&var88);
  setData(idB8AB10LDU,&var89);
  setData(idB8AB09LDU,&var90);
  setData(idB8AB08LDU,&var91);
  setData(idB8AB04LDU,&var97);
  setData(idB8AB01LDU,&var98);
  setData(idB8AD20LDU,&var1708);
  setData(idB8AD10LDU,&var1707);
  setData(idB8AZ03LDU,&var95);
  setData(idB8VS22LDU,&var1762);
  setData(idB8AB05LDU,&var92);
  setData(idB8AB07LDU,&var93);
  setData(idB8AB06LDU,&var94);
  setData(idB8CV01RDU,&var1763);
  setData(idB8VS12LDU,&var1761);
  setData(idA6AB05LDU,&var187);
  setData(idB6AB09LDU,&var99);
  setData(idB6AB08LDU,&var100);
  setData(idB6AB07LDU,&var101);
  setData(idB6AB06LDU,&var102);
  setData(idA6AB09LDU,&var183);
  setData(idA6AB08LDU,&var184);
  setData(idA6AB07LDU,&var185);
  setData(idA6AB06LDU,&var186);
  setData(idB5AB04LDU,&var108);
  setData(idA5AB04LDU,&var193);
  setData(idB4AB02LDU,&var112);
  setData(idB4AB01LDU,&var113);
  setData(idB4AZ03LDU,&var114);
  setData(idA4AB02LDU,&var197);
  setData(idA4AB01LDU,&var198);
  setData(idA4AZ03LDU,&var196);
  setData(idA4AD10LDU,&var1807);
  setData(idB4AD10LDU,&var1798);
  setData(idB5AB02LDU,&var109);
  setData(idB5AB01LDU,&var110);
  setData(idB5AZ03LDU,&var111);
  setData(idA5AB02LDU,&var194);
  setData(idA5AB01LDU,&var195);
  setData(idA5AZ03LDU,&var192);
  setData(idA5AD20LDU,&var1827);
  setData(idA5AD10LDU,&var1826);
  setData(idB5AD20LDU,&var1818);
  setData(idB5AD10LDU,&var1817);
  setData(idR4AD20LDU,&var1836);
  setData(idR4AD10LDU,&var1835);
  setData(idR4AB18LDU,&var48);
  setData(idR4AB17LDU,&var49);
  setData(idR4AB16LDU,&var50);
  setData(idR4AB15LDU,&var51);
  setData(idR4AB14LDU,&var52);
  setData(idR4AB13LDU,&var53);
  setData(idR4AB12LDU,&var54);
  setData(idR4AB11LDU,&var66);
  setData(idR4AB10LDU,&var55);
  setData(idR4AB09LDU,&var56);
  setData(idR4AB08LDU,&var57);
  setData(idR4AB07LDU,&var58);
  setData(idR4AB06LDU,&var59);
  setData(idR4AB05LDU,&var60);
  setData(idR4AB04LDU,&var61);
  setData(idR4AB03LDU,&var63);
  setData(idR4AZ03LDU,&var62);
  setData(idR4AB02LDU,&var64);
  setData(idR4AB01LDU,&var65);
  setData(idB6AB04LDU,&var104);
  setData(idA6AB04LDU,&var189);
  setData(idB6AB02LDU,&var106);
  setData(idB6AB01LDU,&var105);
  setData(idB6AZ03LDU,&var107);
  setData(idA6AB02LDU,&var190);
  setData(idA6AB01LDU,&var191);
  setData(idA6AZ03LDU,&var188);
  setData(idB6AD20LDU,&var1845);
  setData(idB6AD10LDU,&var1844);
  setData(idA6AD20LDU,&var1854);
  setData(idA6AD10LDU,&var1853);
  setData(idR0ES01LDU,&var1136);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
  for( i=0;i<10;i++ )
    array_m356_rz_1[i] = &(&internal1_m356_rz)[i*1];
  for( i=0;i<10;i++ )
    array_m298_rz_1[i] = &(&internal1_m298_rz)[i*1];
  for( i=0;i<6;i++ )
    array_m1600_rz_1[i] = &(&internal1_m1600_rz)[i*1];
  for( i=0;i<60;i++ )
    array_m1509_x0_1[i] = &(&internal1_m1509_x0)[i*5];
  for( i=0;i<60;i++ )
    array_m1509_tim0_1[i] = &(&internal1_m1509_tim0)[i*5];
  for( i=0;i<60;i++ )
    array_m1035_x0_1[i] = &(&internal1_m1035_x0)[i*5];
  for( i=0;i<60;i++ )
    array_m1035_tim0_1[i] = &(&internal1_m1035_tim0)[i*5];
  for( i=0;i<150;i++ )
    array_m573_x0_1[i] = &(&internal1_m573_x0)[i*5];
  for( i=0;i<150;i++ )
    array_m573_tim0_1[i] = &(&internal1_m573_tim0)[i*5];
  for( i=0;i<150;i++ )
    array_m201_x0_1[i] = &(&internal1_m201_x0)[i*5];
  for( i=0;i<150;i++ )
    array_m201_tim0_1[i] = &(&internal1_m201_tim0)[i*5];
  for( i=0;i<80;i++ )
    array_m927_x0_1[i] = &(&internal1_m927_x0)[i*5];
  for( i=0;i<80;i++ )
    array_m927_tim0_1[i] = &(&internal1_m927_tim0)[i*5];
  for( i=0;i<80;i++ )
    array_m1405_x0_1[i] = &(&internal1_m1405_x0)[i*5];
  for( i=0;i<80;i++ )
    array_m1405_tim0_1[i] = &(&internal1_m1405_tim0)[i*5];
  for( i=0;i<20;i++ )
    array_m1826_x0_1[i] = &(&internal1_m1826_x0)[i*5];
  for( i=0;i<20;i++ )
    array_m1826_tim0_1[i] = &(&internal1_m1826_tim0)[i*5];
  for( i=0;i<20;i++ )
    array_m1300_x0_1[i] = &(&internal1_m1300_x0)[i*5];
  for( i=0;i<20;i++ )
    array_m1300_tim0_1[i] = &(&internal1_m1300_tim0)[i*5];
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
