#ifndef DU_H
#define DU_H
// Подсистема  DU:DU
static char SimulOn=0;
static short CodeSub=2;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 //Время цикла мс
float takt,taktScheme=0,taktSS=0;
#define SIZE_BUFFER 12294
static char BUFFER[SIZE_BUFFER];
#include <fp8/UDPTransport.h>
SetupUDP setUDP ={"192.168.10.50\0",5432,"192.168.10.150\0",5432,BUFFER,sizeof(BUFFER),};
int master=1,nomer=1;
#define A0CT01IZ1	BUFFER[0]	// ( - , MDuBz1) Температура АЗ1-1
#define idA0CT01IZ1	1	// ( - , MDuBz1) Температура АЗ1-1
#define A0CT01IZ2	BUFFER[5]	// ( - , MDuBz2) Температура АЗ1-2
#define idA0CT01IZ2	2	// ( - , MDuBz2) Температура АЗ1-2
#define A0EE01LZ1	BUFFER[10]	// ( - , MDuBz1) Исправность АКНП1
#define idA0EE01LZ1	3	// ( - , MDuBz1) Исправность АКНП1
#define A0EE01LZ2	BUFFER[12]	// ( - , MDuBz2) Исправность АКНП1
#define idA0EE01LZ2	4	// ( - , MDuBz2) Исправность АКНП1
#define A0EE02LZ1	BUFFER[14]	// ( - , MDuBz1) Исправность АКНП2
#define idA0EE02LZ1	5	// ( - , MDuBz1) Исправность АКНП2
#define A0EE02LZ2	BUFFER[16]	// ( - , MDuBz2) Исправность АКНП2
#define idA0EE02LZ2	6	// ( - , MDuBz2) Исправность АКНП2
#define A0EE03LZ1	BUFFER[18]	// ( - , MDuBz1) Исправность АКНП3
#define idA0EE03LZ1	7	// ( - , MDuBz1) Исправность АКНП3
#define A0EE03LZ2	BUFFER[20]	// ( - , MDuBz2) Исправность АКНП3
#define idA0EE03LZ2	8	// ( - , MDuBz2) Исправность АКНП3
#define A0EE04LZ1	BUFFER[22]	// ( - , MDuBz1) Исправность АКНП4
#define idA0EE04LZ1	9	// ( - , MDuBz1) Исправность АКНП4
#define A0EE04LZ2	BUFFER[24]	// ( - , MDuBz2) Исправность АКНП4
#define idA0EE04LZ2	10	// ( - , MDuBz2) Исправность АКНП4
#define A0VE01LDU	BUFFER[26]	// ( - , DU) Напряжение в системы АЗ1 подано
#define idA0VE01LDU	11	// ( - , DU) Напряжение в системы АЗ1 подано
#define A0VN01LDU	BUFFER[28]	// ( - , DU) Каналы АЗ1 проверены
#define idA0VN01LDU	12	// ( - , DU) Каналы АЗ1 проверены
#define A0VN71LZ1	BUFFER[30]	// ( - , MDuBz1) АЗ по АС мощности для АЗ1
#define idA0VN71LZ1	13	// ( - , MDuBz1) АЗ по АС мощности для АЗ1
#define A0VN71LZ2	BUFFER[32]	// ( - , MDuBz2) АЗ по АС мощности для АЗ1
#define idA0VN71LZ2	14	// ( - , MDuBz2) АЗ по АС мощности для АЗ1
#define A0VP01LDU	BUFFER[34]	// ( - , DU) Давление в системы АЗ1 подано
#define idA0VP01LDU	15	// ( - , DU) Давление в системы АЗ1 подано
#define A0VP71LZ1	BUFFER[36]	// ( - , MDuBz1) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ1	16	// ( - , MDuBz1) АЗ по АС любого давления для АЗ1
#define A0VP71LZ2	BUFFER[38]	// ( - , MDuBz2) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ2	17	// ( - , MDuBz2) АЗ по АС любого давления для АЗ1
#define A0VS11LDU	BUFFER[40]	// ( - , DU) АЗ1 готова к работе
#define idA0VS11LDU	18	// ( - , DU) АЗ1 готова к работе
#define A0VT71LZ1	BUFFER[42]	// ( - , MDuBz1) АС по температуре в АЗ1
#define idA0VT71LZ1	19	// ( - , MDuBz1) АС по температуре в АЗ1
#define A0VT71LZ2	BUFFER[44]	// ( - , MDuBz2) АС по температуре в АЗ1
#define idA0VT71LZ2	20	// ( - , MDuBz2) АС по температуре в АЗ1
#define A1AB01LDU	BUFFER[46]	// ( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
#define idA1AB01LDU	21	// ( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
#define A1AB02LDU	BUFFER[48]	// ( - , DU) Блокировка движения ББ1: превышение заданной скорости
#define idA1AB02LDU	22	// ( - , DU) Блокировка движения ББ1: превышение заданной скорости
#define A1AB04LDU	BUFFER[50]	// ( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
#define idA1AB04LDU	23	// ( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
#define A1AB05LDU	BUFFER[52]	// ( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
#define idA1AB05LDU	24	// ( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
#define A1AB06LDU	BUFFER[54]	// ( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
#define idA1AB06LDU	25	// ( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
#define A1AB07LDU	BUFFER[56]	// ( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
#define idA1AB07LDU	26	// ( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
#define A1AB08LDU	BUFFER[58]	// ( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
#define idA1AB08LDU	27	// ( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
#define A1AB09LDU	BUFFER[60]	// ( - , DU) Блокировка подъёма ББ1- АНИ не установлен
#define idA1AB09LDU	28	// ( - , DU) Блокировка подъёма ББ1- АНИ не установлен
#define A1AB10LDU	BUFFER[62]	// ( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
#define idA1AB10LDU	29	// ( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
#define A1AB11LDU	BUFFER[64]	// ( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
#define idA1AB11LDU	30	// ( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
#define A1AB12LDU	BUFFER[66]	// ( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA1AB12LDU	31	// ( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A1AB13LDU	BUFFER[68]	// ( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
#define idA1AB13LDU	32	// ( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
#define A1AB14LDU	BUFFER[70]	// ( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
#define idA1AB14LDU	33	// ( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
#define A1AB16LDU	BUFFER[72]	// ( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
#define idA1AB16LDU	34	// ( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
#define A1AB17LDU	BUFFER[74]	// ( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
#define idA1AB17LDU	35	// ( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
#define A1AB18LDU	BUFFER[76]	// ( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
#define idA1AB18LDU	36	// ( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
#define A1AB19LDU	BUFFER[78]	// ( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
#define idA1AB19LDU	37	// ( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
#define A1AD01LDU	BUFFER[80]	// (fds16:08 - K03FDSR, - ) Разрешение движения ББ1
#define idA1AD01LDU	38	// (fds16:08 - K03FDSR, - ) Разрешение движения ББ1
#define A1AD02LDU	BUFFER[82]	// (fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
#define idA1AD02LDU	39	// (fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
#define A1AD03LDU	BUFFER[84]	// (fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
#define idA1AD03LDU	40	// (fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
#define A1AD04LDU	BUFFER[86]	// (fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
#define idA1AD04LDU	41	// (fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
#define A1AD05LDU	BUFFER[88]	// (fds16:08 - K07FDSR, - ) паритет команды на ББ1
#define idA1AD05LDU	42	// (fds16:08 - K07FDSR, - ) паритет команды на ББ1
#define A1AD11LDU	BUFFER[90]	// (fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	43	// (fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
#define A1AD21LDU	BUFFER[92]	// (fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	44	// (fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
#define A1AD31LDU	BUFFER[94]	// (fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
#define idA1AD31LDU	45	// (fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
#define A1AD32LDU	BUFFER[96]	// (fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
#define idA1AD32LDU	46	// (fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
#define A1AZ03LDU	BUFFER[98]	// ( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
#define idA1AZ03LDU	47	// ( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
#define A1CV01RDU	BUFFER[100]	// ( - , DU) Измеренная скорость перемещения ББ1
#define idA1CV01RDU	48	// ( - , DU) Измеренная скорость перемещения ББ1
#define A1CV02RDU	BUFFER[105]	// ( - , DU) Заданная скорость перемещения ББ1
#define idA1CV02RDU	49	// ( - , DU) Заданная скорость перемещения ББ1
#define A1IC01UDU	BUFFER[110]	// ( - , MDuS) Координата штока ББ1 (дел.энк)
#define idA1IC01UDU	50	// ( - , MDuS) Координата штока ББ1 (дел.энк)
#define A1IE01LDU	BUFFER[115]	// (vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
#define idA1IE01LDU	51	// (vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
#define A1IE02LDU	BUFFER[117]	// (vds32:05 - K01VDSR, - ) Исправность ИП ББ1
#define idA1IE02LDU	52	// (vds32:05 - K01VDSR, - ) Исправность ИП ББ1
#define A1IE03LDU	BUFFER[119]	// (vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
#define idA1IE03LDU	53	// (vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
#define A1IE04LDU	BUFFER[121]	// (vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
#define idA1IE04LDU	54	// (vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
#define A1IS11LDU	BUFFER[123]	// (vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
#define idA1IS11LDU	55	// (vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
#define A1IS12LDU	BUFFER[125]	// (vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
#define idA1IS12LDU	56	// (vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
#define A1IS21LDU	BUFFER[127]	// (vds32:03 - K09VDSR, DU) Приход на НУ ББ1
#define idA1IS21LDU	57	// (vds32:03 - K09VDSR, DU) Приход на НУ ББ1
#define A1MC01LC1	BUFFER[129]	// ( - , DU) Настроить энкодер ББ1
#define idA1MC01LC1	58	// ( - , DU) Настроить энкодер ББ1
#define A1MC01LC2	BUFFER[131]	// ( - , DU) Настроить энкодер ББ1
#define idA1MC01LC2	59	// ( - , DU) Настроить энкодер ББ1
#define A1MC01RP1	BUFFER[133]	// ( - , DU) Заданная координата положения ББ1 мм
#define idA1MC01RP1	60	// ( - , DU) Заданная координата положения ББ1 мм
#define A1MD11LP1	BUFFER[138]	// ( - , DU) Кнопка ПУСК ББ1
#define idA1MD11LP1	61	// ( - , DU) Кнопка ПУСК ББ1
#define A1MD12LP1	BUFFER[140]	// ( - , DU) Переключатель РАЗРЕШИТЬ ББ1
#define idA1MD12LP1	62	// ( - , DU) Переключатель РАЗРЕШИТЬ ББ1
#define A1VC01RDU	BUFFER[142]	// ( - , DU) Координата ББ1, мм
#define idA1VC01RDU	63	// ( - , DU) Координата ББ1, мм
#define A1VN71LZ1	BUFFER[147]	// (vds32:02 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define idA1VN71LZ1	64	// (vds32:02 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define A1VN71LZ2	BUFFER[149]	// (vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define idA1VN71LZ2	65	// (vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define A1VP41LZ1	BUFFER[151]	// ( - , MDuBz1) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ1	66	// ( - , MDuBz1) Давление СБРОС ББ1 ниже АС
#define A1VP41LZ2	BUFFER[153]	// ( - , MDuBz2) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ2	67	// ( - , MDuBz2) Давление СБРОС ББ1 ниже АС
#define A1VS01IDU	BUFFER[155]	// ( - , DU) Готовность к управлению ББ1
#define idA1VS01IDU	68	// ( - , DU) Готовность к управлению ББ1
#define A1VS12LDU	BUFFER[158]	// ( - , DU) Движение ББ1 в сторону ВУ
#define idA1VS12LDU	69	// ( - , DU) Движение ББ1 в сторону ВУ
#define A1VS22LDU	BUFFER[160]	// ( - , DU) Движение ББ1 в сторону НУ
#define idA1VS22LDU	70	// ( - , DU) Движение ББ1 в сторону НУ
#define A1ZAV	BUFFER[162]	// ( - , DU) 
#define idA1ZAV	71	// ( - , DU) 
#define A2AB01LDU	BUFFER[164]	// ( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
#define idA2AB01LDU	72	// ( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
#define A2AB02LDU	BUFFER[166]	// ( - , DU) Блокировка движения РБ1: превышение заданной скорости
#define idA2AB02LDU	73	// ( - , DU) Блокировка движения РБ1: превышение заданной скорости
#define A2AB04LDU	BUFFER[168]	// ( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
#define idA2AB04LDU	74	// ( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
#define A2AB05LDU	BUFFER[170]	// ( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
#define idA2AB05LDU	75	// ( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
#define A2AB06LDU	BUFFER[172]	// ( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
#define idA2AB06LDU	76	// ( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
#define A2AB07LDU	BUFFER[174]	// ( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
#define idA2AB07LDU	77	// ( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
#define A2AB08LDU	BUFFER[176]	// ( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
#define idA2AB08LDU	78	// ( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
#define A2AB09LDU	BUFFER[178]	// ( - , DU) Блокировка подъёма РБ1- АНИ не установлен
#define idA2AB09LDU	79	// ( - , DU) Блокировка подъёма РБ1- АНИ не установлен
#define A2AB10LDU	BUFFER[180]	// ( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
#define idA2AB10LDU	80	// ( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
#define A2AB11LDU	BUFFER[182]	// ( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
#define idA2AB11LDU	81	// ( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
#define A2AB12LDU	BUFFER[184]	// ( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA2AB12LDU	82	// ( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A2AB13LDU	BUFFER[186]	// ( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
#define idA2AB13LDU	83	// ( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
#define A2AB14LDU	BUFFER[188]	// ( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
#define idA2AB14LDU	84	// ( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
#define A2AB15LDU	BUFFER[190]	// ( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define idA2AB15LDU	85	// ( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define A2AB16LDU	BUFFER[192]	// ( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
#define idA2AB16LDU	86	// ( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
#define A2AB17LDU	BUFFER[194]	// ( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
#define idA2AB17LDU	87	// ( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
#define A2AD01LDU	BUFFER[196]	// (fds16:07 - K03FDSR, - ) Разрешение движения РБ1
#define idA2AD01LDU	88	// (fds16:07 - K03FDSR, - ) Разрешение движения РБ1
#define A2AD02LDU	BUFFER[198]	// (fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
#define idA2AD02LDU	89	// (fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
#define A2AD03LDU	BUFFER[200]	// (fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
#define idA2AD03LDU	90	// (fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
#define A2AD04LDU	BUFFER[202]	// (fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
#define idA2AD04LDU	91	// (fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
#define A2AD05LDU	BUFFER[204]	// (fds16:07 - K07FDSR, - ) паритет команды на РБ1
#define idA2AD05LDU	92	// (fds16:07 - K07FDSR, - ) паритет команды на РБ1
#define A2AD11LDU	BUFFER[206]	// (fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	93	// (fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
#define A2AD21LDU	BUFFER[208]	// (fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	94	// (fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
#define A2AD31LDU	BUFFER[210]	// (fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
#define idA2AD31LDU	95	// (fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
#define A2AD32LDU	BUFFER[212]	// (fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
#define idA2AD32LDU	96	// (fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
#define A2AD33LDU	BUFFER[214]	// (fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
#define idA2AD33LDU	97	// (fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
#define A2AZ03LDU	BUFFER[216]	// ( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
#define idA2AZ03LDU	98	// ( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
#define A2CV01RDU	BUFFER[218]	// ( - , DU) Измеренная скорость перемещения РБ1
#define idA2CV01RDU	99	// ( - , DU) Измеренная скорость перемещения РБ1
#define A2CV02RDU	BUFFER[223]	// ( - , DU) Заданная скорость перемещения РБ1
#define idA2CV02RDU	100	// ( - , DU) Заданная скорость перемещения РБ1
#define A2IC01UDU	BUFFER[228]	// ( - , MDuS) Координата штока РБ1 (дел.энк)
#define idA2IC01UDU	101	// ( - , MDuS) Координата штока РБ1 (дел.энк)
#define A2IE01LDU	BUFFER[233]	// (vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
#define idA2IE01LDU	102	// (vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
#define A2IE02LDU	BUFFER[235]	// (vds32:05 - K05VDSR, - ) Исправность ИП РБ1
#define idA2IE02LDU	103	// (vds32:05 - K05VDSR, - ) Исправность ИП РБ1
#define A2IE03LDU	BUFFER[237]	// (vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
#define idA2IE03LDU	104	// (vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
#define A2IE04LDU	BUFFER[239]	// (vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
#define idA2IE04LDU	105	// (vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
#define A2IS11LDU	BUFFER[241]	// (vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
#define idA2IS11LDU	106	// (vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
#define A2IS12LDU	BUFFER[243]	// (vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
#define idA2IS12LDU	107	// (vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
#define A2IS21LDU	BUFFER[245]	// (vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
#define idA2IS21LDU	108	// (vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
#define A2IS33LDU	BUFFER[247]	// (vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
#define idA2IS33LDU	109	// (vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
#define A2MC01LC1	BUFFER[249]	// ( - , DU) Настроить энкодер РБ1
#define idA2MC01LC1	110	// ( - , DU) Настроить энкодер РБ1
#define A2MC01LC2	BUFFER[251]	// ( - , DU) Настроить энкодер РБ1
#define idA2MC01LC2	111	// ( - , DU) Настроить энкодер РБ1
#define A2MD11LP1	BUFFER[253]	// ( - , DU) Кнопка ПУСК РБ1
#define idA2MD11LP1	112	// ( - , DU) Кнопка ПУСК РБ1
#define A2MD12LP1	BUFFER[255]	// ( - , DU) Переключатель РАЗРЕШИТЬ РБ1
#define idA2MD12LP1	113	// ( - , DU) Переключатель РАЗРЕШИТЬ РБ1
#define A2VC01RDU	BUFFER[257]	// ( - , DU) Координата РБ1, мм
#define idA2VC01RDU	114	// ( - , DU) Координата РБ1, мм
#define A2VP82LDU	BUFFER[262]	// ( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	115	// ( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define A2VS01IDU	BUFFER[264]	// ( - , DU) Готовность к управлению РБ1
#define idA2VS01IDU	116	// ( - , DU) Готовность к управлению РБ1
#define A2VS11LDU	BUFFER[267]	// ( - , DU) Движение РБ1 в сторону ВУ
#define idA2VS11LDU	117	// ( - , DU) Движение РБ1 в сторону ВУ
#define A2VS21LDU	BUFFER[269]	// ( - , DU) Движение РБ1 в сторону НУ
#define idA2VS21LDU	118	// ( - , DU) Движение РБ1 в сторону НУ
#define A2VS32LDU	BUFFER[271]	// ( - , DU) Индикация  СБРОС РБ1
#define idA2VS32LDU	119	// ( - , DU) Индикация  СБРОС РБ1
#define A2ZAV	BUFFER[273]	// ( - , DU) Завершение РБ1,2
#define idA2ZAV	120	// ( - , DU) Завершение РБ1,2
#define A3AB01LDU	BUFFER[275]	// ( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
#define idA3AB01LDU	121	// ( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
#define A3AB02LDU	BUFFER[277]	// ( - , DU) Блокировка движения ИС1: превышение заданной скорости
#define idA3AB02LDU	122	// ( - , DU) Блокировка движения ИС1: превышение заданной скорости
#define A3AB04LDU	BUFFER[279]	// ( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
#define idA3AB04LDU	123	// ( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
#define A3AB05LDU	BUFFER[281]	// ( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
#define idA3AB05LDU	124	// ( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
#define A3AB06LDU	BUFFER[283]	// ( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
#define idA3AB06LDU	125	// ( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
#define A3AB07LDU	BUFFER[285]	// ( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
#define idA3AB07LDU	126	// ( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
#define A3AB08LDU	BUFFER[287]	// ( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
#define idA3AB08LDU	127	// ( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
#define A3AB09LDU	BUFFER[289]	// ( - , DU) Блокировка подъёма ИС1- АНИ не установлен
#define idA3AB09LDU	128	// ( - , DU) Блокировка подъёма ИС1- АНИ не установлен
#define A3AB10LDU	BUFFER[291]	// ( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
#define idA3AB10LDU	129	// ( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
#define A3AB11LDU	BUFFER[293]	// ( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
#define idA3AB11LDU	130	// ( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
#define A3AB12LDU	BUFFER[295]	// ( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA3AB12LDU	131	// ( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A3AB13LDU	BUFFER[297]	// ( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
#define idA3AB13LDU	132	// ( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
#define A3AB14LDU	BUFFER[299]	// ( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
#define idA3AB14LDU	133	// ( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
#define A3AB15LDU	BUFFER[301]	// ( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
#define idA3AB15LDU	134	// ( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
#define A3AB16LDU	BUFFER[303]	// ( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
#define idA3AB16LDU	135	// ( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
#define A3AB17LDU	BUFFER[305]	// ( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
#define idA3AB17LDU	136	// ( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
#define A3AB18LDU	BUFFER[307]	// ( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
#define idA3AB18LDU	137	// ( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
#define A3AB19LDU	BUFFER[309]	// ( - , DU) Блокировка пневматического подъема ИС1: режим статический
#define idA3AB19LDU	138	// ( - , DU) Блокировка пневматического подъема ИС1: режим статический
#define A3AB20LDU	BUFFER[311]	// ( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
#define idA3AB20LDU	139	// ( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
#define A3AD01LDU	BUFFER[313]	// (fds16:0b - K03FDSR, - ) Разрешение движения ИС1
#define idA3AD01LDU	140	// (fds16:0b - K03FDSR, - ) Разрешение движения ИС1
#define A3AD02LDU	BUFFER[315]	// (fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
#define idA3AD02LDU	141	// (fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
#define A3AD03LDU	BUFFER[317]	// (fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
#define idA3AD03LDU	142	// (fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
#define A3AD04LDU	BUFFER[319]	// (fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
#define idA3AD04LDU	143	// (fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
#define A3AD05LDU	BUFFER[321]	// (fds16:0b - K07FDSR, - ) паритет команды на ИС1
#define idA3AD05LDU	144	// (fds16:0b - K07FDSR, - ) паритет команды на ИС1
#define A3AD11LDU	BUFFER[323]	// (fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	145	// (fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
#define A3AD21LDU	BUFFER[325]	// (fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	146	// (fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
#define A3AD31LDU	BUFFER[327]	// (fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
#define idA3AD31LDU	147	// (fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
#define A3AD33LDU	BUFFER[329]	// (fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
#define idA3AD33LDU	148	// (fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
#define A3AD34LDU	BUFFER[331]	// (fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
#define idA3AD34LDU	149	// (fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
#define A3AZ03LDU	BUFFER[333]	// ( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
#define idA3AZ03LDU	150	// ( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
#define A3CP02RDU	BUFFER[335]	// ( - , DU) Текущее давление ВЫСТРЕЛ ИС1
#define idA3CP02RDU	151	// ( - , DU) Текущее давление ВЫСТРЕЛ ИС1
#define A3CV01RDU	BUFFER[340]	// ( - , DU) Измеренная скорость перемещения ИС1
#define idA3CV01RDU	152	// ( - , DU) Измеренная скорость перемещения ИС1
#define A3CV02RDU	BUFFER[345]	// ( - , DU) Заданная скорость перемещения ИС1
#define idA3CV02RDU	153	// ( - , DU) Заданная скорость перемещения ИС1
#define A3EE03LDU	BUFFER[350]	// ( - , DU) ВПИС ИС1
#define idA3EE03LDU	154	// ( - , DU) ВПИС ИС1
#define A3IC01UDU	BUFFER[352]	// ( - , MDuS) Координата штока ИС1 (дел.энк)
#define idA3IC01UDU	155	// ( - , MDuS) Координата штока ИС1 (дел.энк)
#define A3IE01LDU	BUFFER[357]	// (vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
#define idA3IE01LDU	156	// (vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
#define A3IE02LDU	BUFFER[359]	// (vds32:05 - K09VDSR, - ) Исправность ИП ИС1
#define idA3IE02LDU	157	// (vds32:05 - K09VDSR, - ) Исправность ИП ИС1
#define A3IE03LDU	BUFFER[361]	// (vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
#define idA3IE03LDU	158	// (vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
#define A3IE04LDU	BUFFER[363]	// (vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
#define idA3IE04LDU	159	// (vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
#define A3IP02IDU	BUFFER[365]	// (vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	160	// (vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
#define A3IS11LDU	BUFFER[368]	// (vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
#define idA3IS11LDU	161	// (vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
#define A3IS12LDU	BUFFER[370]	// ( - , DU) Приход на ВУ штока ИС1
#define idA3IS12LDU	162	// ( - , DU) Приход на ВУ штока ИС1
#define A3IS21LDU	BUFFER[372]	// (vds32:03 - K13VDSR, DU) Приход на НУ ИС1
#define idA3IS21LDU	163	// (vds32:03 - K13VDSR, DU) Приход на НУ ИС1
#define A3IS22LDU	BUFFER[374]	// (vds32:04 - K02VDSR, DU) Приход на НУП ИС1
#define idA3IS22LDU	164	// (vds32:04 - K02VDSR, DU) Приход на НУП ИС1
#define A3IS31LDU	BUFFER[376]	// (vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
#define idA3IS31LDU	165	// (vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
#define A3IS33LDU	BUFFER[378]	// (vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
#define idA3IS33LDU	166	// (vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
#define A3IS35LDU	BUFFER[380]	// (vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
#define idA3IS35LDU	167	// (vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
#define A3MC01LC1	BUFFER[382]	// ( - , DU) Настроить энкодер ИС1
#define idA3MC01LC1	168	// ( - , DU) Настроить энкодер ИС1
#define A3MC01LC2	BUFFER[384]	// ( - , DU) Настроить энкодер ИС1
#define idA3MC01LC2	169	// ( - , DU) Настроить энкодер ИС1
#define A3MC01RDU	BUFFER[386]	// ( - , DU) Заданная координата положения ИС от регулятора мм
#define idA3MC01RDU	170	// ( - , DU) Заданная координата положения ИС от регулятора мм
#define A3MC01RP1	BUFFER[391]	// ( - , DU) Заданная координата положения ИС1 мм
#define idA3MC01RP1	171	// ( - , DU) Заданная координата положения ИС1 мм
#define A3MC02RDU	BUFFER[396]	// ( - , DU) Температурная корректировка координаты ИМ
#define idA3MC02RDU	172	// ( - , DU) Температурная корректировка координаты ИМ
#define A3MC03RDU	BUFFER[401]	// ( - , DU) Координата положения ИМ 0-й реактивности
#define idA3MC03RDU	173	// ( - , DU) Координата положения ИМ 0-й реактивности
#define A3MD11LP1	BUFFER[406]	// ( - , DU) Кнопка ПУСК ИС1
#define idA3MD11LP1	174	// ( - , DU) Кнопка ПУСК ИС1
#define A3MD12LP1	BUFFER[408]	// ( - , DU) Переключатель РАЗРЕШИТЬ ИС1
#define idA3MD12LP1	175	// ( - , DU) Переключатель РАЗРЕШИТЬ ИС1
#define A3VC01RDU	BUFFER[410]	// ( - , DU) Координата ИС1, мм
#define idA3VC01RDU	176	// ( - , DU) Координата ИС1, мм
#define A3VP42LDU	BUFFER[415]	// ( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
#define idA3VP42LDU	177	// ( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
#define A3VP52LDU	BUFFER[417]	// ( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define idA3VP52LDU	178	// ( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define A3VP81LDU	BUFFER[419]	// ( - , - ) Давление СПУСК ИС1 в норме
#define idA3VP81LDU	179	// ( - , - ) Давление СПУСК ИС1 в норме
#define A3VP82LDU	BUFFER[421]	// ( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
#define idA3VP82LDU	180	// ( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
#define A3VS01IDU	BUFFER[423]	// ( - , DU) Готовность к управлению ИС1
#define idA3VS01IDU	181	// ( - , DU) Готовность к управлению ИС1
#define A3VS12LDU	BUFFER[426]	// ( - , DU) Движение ИС1 в сторону ВУ
#define idA3VS12LDU	182	// ( - , DU) Движение ИС1 в сторону ВУ
#define A3VS22LDU	BUFFER[428]	// ( - , DU) Движение ИС1 в сторону НУ
#define idA3VS22LDU	183	// ( - , DU) Движение ИС1 в сторону НУ
#define A3VX01LDU	BUFFER[430]	// ( - , DU) Индикация Выстрел ИС1
#define idA3VX01LDU	184	// ( - , DU) Индикация Выстрел ИС1
#define A3VZ13LZ1	BUFFER[432]	// (vds32:02 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ1	185	// (vds32:02 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define A3VZ13LZ2	BUFFER[434]	// (vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ2	186	// (vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define A3VZ15LZ1	BUFFER[436]	// (vds32:02 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ1	187	// (vds32:02 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define A3VZ15LZ2	BUFFER[438]	// (vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ2	188	// (vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define A3ZAV	BUFFER[440]	// ( - , DU) 
#define idA3ZAV	189	// ( - , DU) 
#define A4AB01LDU	BUFFER[442]	// ( - , DU) Блокировка движения НИ1 - Превышение времени движения
#define idA4AB01LDU	190	// ( - , DU) Блокировка движения НИ1 - Превышение времени движения
#define A4AB02LDU	BUFFER[444]	// ( - , DU) Блокировка движения НИ1 - Нет перемещения
#define idA4AB02LDU	191	// ( - , DU) Блокировка движения НИ1 - Нет перемещения
#define A4AD10LDU	BUFFER[446]	// (fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
#define idA4AD10LDU	192	// (fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
#define A4AZ03LDU	BUFFER[448]	// ( - , DU) Несанкционированное перемещение НИ1
#define idA4AZ03LDU	193	// ( - , DU) Несанкционированное перемещение НИ1
#define A4DW	BUFFER[450]	// ( - , DU) 
#define idA4DW	194	// ( - , DU) 
#define A4IS10LDU	BUFFER[452]	// (vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
#define idA4IS10LDU	195	// (vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
#define A4IS11LDU	BUFFER[454]	// (vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
#define idA4IS11LDU	196	// (vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
#define A4IS21LDU	BUFFER[456]	// (vds32:03 - K15VDSR, DU) Приход на НУ НИ1
#define idA4IS21LDU	197	// (vds32:03 - K15VDSR, DU) Приход на НУ НИ1
#define A4UP	BUFFER[458]	// ( - , DU) 
#define idA4UP	198	// ( - , DU) 
#define A4VP82LDU	BUFFER[460]	// ( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	199	// ( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define A4VS01IDU	BUFFER[462]	// ( - , DU) Готовность к управлению НИ1
#define idA4VS01IDU	200	// ( - , DU) Готовность к управлению НИ1
#define A4VS12LDU	BUFFER[465]	// ( - , DU) Движение НИ1 в сторону ВУ
#define idA4VS12LDU	201	// ( - , DU) Движение НИ1 в сторону ВУ
#define A4VS22LDU	BUFFER[467]	// ( - , DU) Движение НИ1 в сторону НУ
#define idA4VS22LDU	202	// ( - , DU) Движение НИ1 в сторону НУ
#define A4ZAV	BUFFER[469]	// ( - , DU) 
#define idA4ZAV	203	// ( - , DU) 
#define A5AB01LDU	BUFFER[471]	// ( - , DU) Блокировка движения НЛ1 - Превышение времени движения
#define idA5AB01LDU	204	// ( - , DU) Блокировка движения НЛ1 - Превышение времени движения
#define A5AB02LDU	BUFFER[473]	// ( - , DU) Блокировка движения НЛ1 - Нет перемещения
#define idA5AB02LDU	205	// ( - , DU) Блокировка движения НЛ1 - Нет перемещения
#define A5AB04LDU	BUFFER[475]	// ( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
#define idA5AB04LDU	206	// ( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
#define A5AD10LDU	BUFFER[477]	// (fds16:0a - K11FDSR, - ) Поднять НЛ1
#define idA5AD10LDU	207	// (fds16:0a - K11FDSR, - ) Поднять НЛ1
#define A5AD20LDU	BUFFER[479]	// (fds16:0a - K12FDSR, - ) Опустить НЛ1
#define idA5AD20LDU	208	// (fds16:0a - K12FDSR, - ) Опустить НЛ1
#define A5AZ03LDU	BUFFER[481]	// ( - , DU) Несанкционированное перемещение НЛ1
#define idA5AZ03LDU	209	// ( - , DU) Несанкционированное перемещение НЛ1
#define A5IE02LDU	BUFFER[483]	// (vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
#define idA5IE02LDU	210	// (vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
#define A5IS11LDU	BUFFER[485]	// (vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
#define idA5IS11LDU	211	// (vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
#define A5IS21LDU	BUFFER[487]	// (vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
#define idA5IS21LDU	212	// (vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
#define A5VS01IDU	BUFFER[489]	// ( - , DU) Готовность к управлению НЛ1
#define idA5VS01IDU	213	// ( - , DU) Готовность к управлению НЛ1
#define A5VS12LDU	BUFFER[492]	// (vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
#define idA5VS12LDU	214	// (vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
#define A5VS22LDU	BUFFER[494]	// (vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
#define idA5VS22LDU	215	// (vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
#define A5ZAV	BUFFER[496]	// ( - , DU) 
#define idA5ZAV	216	// ( - , DU) 
#define A6AB01LDU	BUFFER[498]	// ( - , DU) Блокировка движения БЗ1 - Превышение времени движения
#define idA6AB01LDU	217	// ( - , DU) Блокировка движения БЗ1 - Превышение времени движения
#define A6AB02LDU	BUFFER[500]	// ( - , DU) Блокировка движения БЗ1 - Нет перемещения
#define idA6AB02LDU	218	// ( - , DU) Блокировка движения БЗ1 - Нет перемещения
#define A6AB04LDU	BUFFER[502]	// ( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
#define idA6AB04LDU	219	// ( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
#define A6AB05LDU	BUFFER[504]	// ( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
#define idA6AB05LDU	220	// ( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
#define A6AB06LDU	BUFFER[506]	// ( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
#define idA6AB06LDU	221	// ( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
#define A6AB07LDU	BUFFER[508]	// ( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
#define idA6AB07LDU	222	// ( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
#define A6AB08LDU	BUFFER[510]	// ( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
#define idA6AB08LDU	223	// ( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
#define A6AB09LDU	BUFFER[512]	// ( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
#define idA6AB09LDU	224	// ( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
#define A6AD10LDU	BUFFER[514]	// (fds16:09 - K09FDSR, - ) Открыть БЗ1
#define idA6AD10LDU	225	// (fds16:09 - K09FDSR, - ) Открыть БЗ1
#define A6AD20LDU	BUFFER[516]	// (fds16:09 - K10FDSR, - ) Закрыть БЗ1
#define idA6AD20LDU	226	// (fds16:09 - K10FDSR, - ) Закрыть БЗ1
#define A6AZ03LDU	BUFFER[518]	// ( - , DU) Несанкционированное перемещение БЗ1
#define idA6AZ03LDU	227	// ( - , DU) Несанкционированное перемещение БЗ1
#define A6IE01LDU	BUFFER[520]	// (vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
#define idA6IE01LDU	228	// (vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
#define A6IS11LDU	BUFFER[522]	// (vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
#define idA6IS11LDU	229	// (vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
#define A6IS21LDU	BUFFER[524]	// (vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
#define idA6IS21LDU	230	// (vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
#define A6VS01IDU	BUFFER[526]	// ( - , DU) Готовность к управлению БЗ1
#define idA6VS01IDU	231	// ( - , DU) Готовность к управлению БЗ1
#define A6VS12LDU	BUFFER[529]	// (vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
#define idA6VS12LDU	232	// (vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
#define A6VS22LDU	BUFFER[531]	// (vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
#define idA6VS22LDU	233	// (vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
#define A6ZAV	BUFFER[533]	// ( - , DU) 
#define idA6ZAV	234	// ( - , DU) 
#define A7AP31LDU	BUFFER[535]	// (fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
#define idA7AP31LDU	235	// (fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
#define A7AS31LDU	BUFFER[537]	// (vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
#define idA7AS31LDU	236	// (vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
#define A7AZ03LDU	BUFFER[539]	// ( - , DU) Несанкционированное включение обдува АЗ1
#define idA7AZ03LDU	237	// ( - , DU) Несанкционированное включение обдува АЗ1
#define A8AB01LDU	BUFFER[541]	// ( - , DU) Блокировка ДС2 -Превышение времени перемещения
#define idA8AB01LDU	238	// ( - , DU) Блокировка ДС2 -Превышение времени перемещения
#define A8AB02LDU	BUFFER[543]	// ( - , DU) Блокировка движения ДС2- АНИ не установлен
#define idA8AB02LDU	239	// ( - , DU) Блокировка движения ДС2- АНИ не установлен
#define A8AB04LDU	BUFFER[545]	// ( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
#define idA8AB04LDU	240	// ( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
#define A8AB05LDU	BUFFER[547]	// ( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
#define idA8AB05LDU	241	// ( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
#define A8AB06LDU	BUFFER[549]	// ( - , DU) Блокировка движения ДС2 нет перемещения ДС2
#define idA8AB06LDU	242	// ( - , DU) Блокировка движения ДС2 нет перемещения ДС2
#define A8AB07LDU	BUFFER[551]	// ( - , DU) Блокировка движения ДС2: превышение заданной скорости
#define idA8AB07LDU	243	// ( - , DU) Блокировка движения ДС2: превышение заданной скорости
#define A8AB08LDU	BUFFER[553]	// ( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define idA8AB08LDU	244	// ( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define A8AB09LDU	BUFFER[555]	// ( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
#define idA8AB09LDU	245	// ( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
#define A8AB10LDU	BUFFER[557]	// ( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
#define idA8AB10LDU	246	// ( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
#define A8AB11LDU	BUFFER[559]	// ( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
#define idA8AB11LDU	247	// ( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
#define A8AB12LDU	BUFFER[561]	// ( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
#define idA8AB12LDU	248	// ( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
#define A8AB13LDU	BUFFER[563]	// ( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
#define idA8AB13LDU	249	// ( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
#define A8AB14LDU	BUFFER[565]	// ( - , DU) Блокировка движения ДС2 - Самоход любого механизма
#define idA8AB14LDU	250	// ( - , DU) Блокировка движения ДС2 - Самоход любого механизма
#define A8AD10LDU	BUFFER[567]	// (fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
#define idA8AD10LDU	251	// (fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
#define A8AD20LDU	BUFFER[569]	// (fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
#define idA8AD20LDU	252	// (fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
#define A8AZ03LDU	BUFFER[571]	// ( - , DU) Несанкционированное перемещение ДС2
#define idA8AZ03LDU	253	// ( - , DU) Несанкционированное перемещение ДС2
#define A8CV01RDU	BUFFER[573]	// ( - , DU) Измеренная скорость перемещения ДС2
#define idA8CV01RDU	254	// ( - , DU) Измеренная скорость перемещения ДС2
#define A8IC01UDU	BUFFER[578]	// ( - , MDuS) Координата ДС2 (дел.энк)
#define idA8IC01UDU	255	// ( - , MDuS) Координата ДС2 (дел.энк)
#define A8IE01LDU	BUFFER[583]	// (vds32:0d - K04VDSR, - ) Исправность ИП ДС2
#define idA8IE01LDU	256	// (vds32:0d - K04VDSR, - ) Исправность ИП ДС2
#define A8IS12LDU	BUFFER[585]	// (vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
#define idA8IS12LDU	257	// (vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
#define A8IS22LDU	BUFFER[587]	// (vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
#define idA8IS22LDU	258	// (vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
#define A8MC01LC1	BUFFER[589]	// ( - , DU) Настроить энкодер ДС2
#define idA8MC01LC1	259	// ( - , DU) Настроить энкодер ДС2
#define A8MC01LC2	BUFFER[591]	// ( - , DU) Настроить энкодер ДС2
#define idA8MC01LC2	260	// ( - , DU) Настроить энкодер ДС2
#define A8VC01RDU	BUFFER[593]	// ( - , DU) Координата ДС2, мм
#define idA8VC01RDU	261	// ( - , DU) Координата ДС2, мм
#define A8VS01IDU	BUFFER[598]	// ( - , DU) Готовность к управлению ДС2
#define idA8VS01IDU	262	// ( - , DU) Готовность к управлению ДС2
#define A8VS12LDU	BUFFER[601]	// ( - , DU) Движение ДС2 в сторону ВУ
#define idA8VS12LDU	263	// ( - , DU) Движение ДС2 в сторону ВУ
#define A8VS22LDU	BUFFER[603]	// ( - , DU) Движение ДС2 в сторону НУ
#define idA8VS22LDU	264	// ( - , DU) Движение ДС2 в сторону НУ
#define A8ZAV	BUFFER[605]	// ( - , DU) 
#define idA8ZAV	265	// ( - , DU) 
#define A9AB01LDU	BUFFER[607]	// ( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
#define idA9AB01LDU	266	// ( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
#define A9AB02LDU	BUFFER[609]	// ( - , DU) Блокировка НИ ДС1 - Нет перемещения
#define idA9AB02LDU	267	// ( - , DU) Блокировка НИ ДС1 - Нет перемещения
#define A9AD10LDU	BUFFER[611]	// (fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
#define idA9AD10LDU	268	// (fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
#define A9AZ03LDU	BUFFER[613]	// ( - , DU) Несанкционированное перемещение НИ ДС1
#define idA9AZ03LDU	269	// ( - , DU) Несанкционированное перемещение НИ ДС1
#define A9IS11LDU	BUFFER[615]	// (vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
#define idA9IS11LDU	270	// (vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
#define A9IS21LDU	BUFFER[617]	// (vds32:02 - K24VDSR, DU) Приход на НУ НИ ДС1
#define idA9IS21LDU	271	// (vds32:02 - K24VDSR, DU) Приход на НУ НИ ДС1
#define A9ZAV	BUFFER[619]	// ( - , DU) Завершение НИ ДС1(2)
#define idA9ZAV	272	// ( - , DU) Завершение НИ ДС1(2)
#define B0CT01IZ1	BUFFER[621]	// ( - , MDuBz1) Температура АЗ2-1
#define idB0CT01IZ1	273	// ( - , MDuBz1) Температура АЗ2-1
#define B0CT01IZ2	BUFFER[626]	// ( - , MDuBz2) Температура АЗ2-2
#define idB0CT01IZ2	274	// ( - , MDuBz2) Температура АЗ2-2
#define B0VE01LDU	BUFFER[631]	// ( - , DU) Напряжение в системы АЗ2 подано
#define idB0VE01LDU	275	// ( - , DU) Напряжение в системы АЗ2 подано
#define B0VN01LDU	BUFFER[633]	// ( - , DU) Каналы АЗ2 проверены
#define idB0VN01LDU	276	// ( - , DU) Каналы АЗ2 проверены
#define B0VN71LZ1	BUFFER[635]	// ( - , MDuBz1) АЗ по АС мощности для АЗ2
#define idB0VN71LZ1	277	// ( - , MDuBz1) АЗ по АС мощности для АЗ2
#define B0VN71LZ2	BUFFER[637]	// ( - , MDuBz2) АЗ по АС мощности для АЗ2
#define idB0VN71LZ2	278	// ( - , MDuBz2) АЗ по АС мощности для АЗ2
#define B0VP01LDU	BUFFER[639]	// ( - , DU) Давление в системы АЗ2 подано
#define idB0VP01LDU	279	// ( - , DU) Давление в системы АЗ2 подано
#define B0VP71LZ1	BUFFER[641]	// ( - , MDuBz1) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ1	280	// ( - , MDuBz1) АЗ по АС любого давления для АЗ2
#define B0VP71LZ2	BUFFER[643]	// ( - , MDuBz2) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ2	281	// ( - , MDuBz2) АЗ по АС любого давления для АЗ2
#define B0VS11LDU	BUFFER[645]	// ( - , DU) АЗ2 готова к работе
#define idB0VS11LDU	282	// ( - , DU) АЗ2 готова к работе
#define B0VT71LZ1	BUFFER[647]	// ( - , MDuBz1) АС по температуре в АЗ2
#define idB0VT71LZ1	283	// ( - , MDuBz1) АС по температуре в АЗ2
#define B0VT71LZ2	BUFFER[649]	// ( - , MDuBz2) АС по температуре в АЗ2
#define idB0VT71LZ2	284	// ( - , MDuBz2) АС по температуре в АЗ2
#define B1AB01LDU	BUFFER[651]	// ( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
#define idB1AB01LDU	285	// ( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
#define B1AB02LDU	BUFFER[653]	// ( - , DU) Блокировка движения ББ2: превышение заданной скорости
#define idB1AB02LDU	286	// ( - , DU) Блокировка движения ББ2: превышение заданной скорости
#define B1AB04LDU	BUFFER[655]	// ( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
#define idB1AB04LDU	287	// ( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
#define B1AB05LDU	BUFFER[657]	// ( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
#define idB1AB05LDU	288	// ( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
#define B1AB06LDU	BUFFER[659]	// ( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
#define idB1AB06LDU	289	// ( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
#define B1AB07LDU	BUFFER[661]	// ( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
#define idB1AB07LDU	290	// ( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
#define B1AB08LDU	BUFFER[663]	// ( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
#define idB1AB08LDU	291	// ( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
#define B1AB09LDU	BUFFER[665]	// ( - , DU) Блокировка подъёма ББ2- АНИ не установлен
#define idB1AB09LDU	292	// ( - , DU) Блокировка подъёма ББ2- АНИ не установлен
#define B1AB10LDU	BUFFER[667]	// ( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
#define idB1AB10LDU	293	// ( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
#define B1AB11LDU	BUFFER[669]	// ( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
#define idB1AB11LDU	294	// ( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
#define B1AB12LDU	BUFFER[671]	// ( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idB1AB12LDU	295	// ( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define B1AB13LDU	BUFFER[673]	// ( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
#define idB1AB13LDU	296	// ( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
#define B1AB14LDU	BUFFER[675]	// ( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
#define idB1AB14LDU	297	// ( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
#define B1AB16LDU	BUFFER[677]	// ( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
#define idB1AB16LDU	298	// ( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
#define B1AB17LDU	BUFFER[679]	// ( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
#define idB1AB17LDU	299	// ( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
#define B1AB18LDU	BUFFER[681]	// ( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
#define idB1AB18LDU	300	// ( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
#define B1AB19LDU	BUFFER[683]	// ( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
#define idB1AB19LDU	301	// ( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
#define B1AD01LDU	BUFFER[685]	// (fds16:08 - K10FDSR, - ) Разрешение движения ББ2
#define idB1AD01LDU	302	// (fds16:08 - K10FDSR, - ) Разрешение движения ББ2
#define B1AD02LDU	BUFFER[687]	// (fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
#define idB1AD02LDU	303	// (fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
#define B1AD03LDU	BUFFER[689]	// (fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
#define idB1AD03LDU	304	// (fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
#define B1AD04LDU	BUFFER[691]	// (fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
#define idB1AD04LDU	305	// (fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
#define B1AD05LDU	BUFFER[693]	// (fds16:08 - K14FDSR, - ) паритет команды на ББ2
#define idB1AD05LDU	306	// (fds16:08 - K14FDSR, - ) паритет команды на ББ2
#define B1AD11LDU	BUFFER[695]	// (fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	307	// (fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
#define B1AD21LDU	BUFFER[697]	// (fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	308	// (fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
#define B1AD31LDU	BUFFER[699]	// (fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
#define idB1AD31LDU	309	// (fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
#define B1AD32LDU	BUFFER[701]	// (fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
#define idB1AD32LDU	310	// (fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
#define B1AZ03LDU	BUFFER[703]	// ( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
#define idB1AZ03LDU	311	// ( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
#define B1CV01RDU	BUFFER[705]	// ( - , DU) Измеренная скорость перемещения ББ2
#define idB1CV01RDU	312	// ( - , DU) Измеренная скорость перемещения ББ2
#define B1CV02RDU	BUFFER[710]	// ( - , DU) Заданная скорость перемещения ББ2
#define idB1CV02RDU	313	// ( - , DU) Заданная скорость перемещения ББ2
#define B1IC01UDU	BUFFER[715]	// ( - , MDuS) Координата штока ББ2 (дел.энк)
#define idB1IC01UDU	314	// ( - , MDuS) Координата штока ББ2 (дел.энк)
#define B1IE01LDU	BUFFER[720]	// (vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
#define idB1IE01LDU	315	// (vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
#define B1IE02LDU	BUFFER[722]	// (vds32:05 - K13VDSR, - ) Исправность ИП ББ2
#define idB1IE02LDU	316	// (vds32:05 - K13VDSR, - ) Исправность ИП ББ2
#define B1IE03LDU	BUFFER[724]	// (vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
#define idB1IE03LDU	317	// (vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
#define B1IE04LDU	BUFFER[726]	// (vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
#define idB1IE04LDU	318	// (vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
#define B1IS11LDU	BUFFER[728]	// (vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
#define idB1IS11LDU	319	// (vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
#define B1IS12LDU	BUFFER[730]	// (vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
#define idB1IS12LDU	320	// (vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
#define B1IS21LDU	BUFFER[732]	// (vds32:02 - K09VDSR, DU) Приход на НУ ББ2
#define idB1IS21LDU	321	// (vds32:02 - K09VDSR, DU) Приход на НУ ББ2
#define B1MC01LC1	BUFFER[734]	// ( - , DU) Настроить энкодер ББ2
#define idB1MC01LC1	322	// ( - , DU) Настроить энкодер ББ2
#define B1MC01LC2	BUFFER[736]	// ( - , DU) Настроить энкодер ББ2
#define idB1MC01LC2	323	// ( - , DU) Настроить энкодер ББ2
#define B1MC01RP1	BUFFER[738]	// ( - , DU) Заданная координата положения ББ2  мм
#define idB1MC01RP1	324	// ( - , DU) Заданная координата положения ББ2  мм
#define B1MD11LP1	BUFFER[743]	// ( - , DU) Кнопка ПУСК ББ2
#define idB1MD11LP1	325	// ( - , DU) Кнопка ПУСК ББ2
#define B1MD12LP1	BUFFER[745]	// ( - , DU) Переключатель РАЗРЕШИТЬ ББ2
#define idB1MD12LP1	326	// ( - , DU) Переключатель РАЗРЕШИТЬ ББ2
#define B1VC01RDU	BUFFER[747]	// ( - , DU) Координата ББ2, мм
#define idB1VC01RDU	327	// ( - , DU) Координата ББ2, мм
#define B1VP41LZ1	BUFFER[752]	// ( - , MDuBz1) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ1	328	// ( - , MDuBz1) Давление СБРОС ББ2 ниже АС
#define B1VP41LZ2	BUFFER[754]	// ( - , MDuBz2) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ2	329	// ( - , MDuBz2) Давление СБРОС ББ2 ниже АС
#define B1VS01IDU	BUFFER[756]	// ( - , DU) Готовность к управлению ББ2
#define idB1VS01IDU	330	// ( - , DU) Готовность к управлению ББ2
#define B1VS12LDU	BUFFER[759]	// ( - , DU) Движение ББ2 в сторону ВУ
#define idB1VS12LDU	331	// ( - , DU) Движение ББ2 в сторону ВУ
#define B1VS22LDU	BUFFER[761]	// ( - , DU) Движение ББ2 в сторону НУ
#define idB1VS22LDU	332	// ( - , DU) Движение ББ2 в сторону НУ
#define B2AB01LDU	BUFFER[763]	// ( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
#define idB2AB01LDU	333	// ( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
#define B2AB02LDU	BUFFER[765]	// ( - , DU) Блокировка движения РБ2: превышение заданной скорости
#define idB2AB02LDU	334	// ( - , DU) Блокировка движения РБ2: превышение заданной скорости
#define B2AB04LDU	BUFFER[767]	// ( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
#define idB2AB04LDU	335	// ( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
#define B2AB05LDU	BUFFER[769]	// ( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
#define idB2AB05LDU	336	// ( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
#define B2AB06LDU	BUFFER[771]	// ( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
#define idB2AB06LDU	337	// ( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
#define B2AB07LDU	BUFFER[773]	// ( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
#define idB2AB07LDU	338	// ( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
#define B2AB08LDU	BUFFER[775]	// ( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
#define idB2AB08LDU	339	// ( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
#define B2AB09LDU	BUFFER[777]	// ( - , DU) Блокировка подъёма РБ2- АНИ не установлен
#define idB2AB09LDU	340	// ( - , DU) Блокировка подъёма РБ2- АНИ не установлен
#define B2AB10LDU	BUFFER[779]	// ( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
#define idB2AB10LDU	341	// ( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
#define B2AB11LDU	BUFFER[781]	// ( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
#define idB2AB11LDU	342	// ( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
#define B2AB12LDU	BUFFER[783]	// ( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define idB2AB12LDU	343	// ( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define B2AB13LDU	BUFFER[785]	// ( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
#define idB2AB13LDU	344	// ( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
#define B2AB14LDU	BUFFER[787]	// ( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
#define idB2AB14LDU	345	// ( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
#define B2AB15LDU	BUFFER[789]	// ( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define idB2AB15LDU	346	// ( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define B2AB16LDU	BUFFER[791]	// ( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
#define idB2AB16LDU	347	// ( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
#define B2AB17LDU	BUFFER[793]	// ( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
#define idB2AB17LDU	348	// ( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
#define B2AD01LDU	BUFFER[795]	// (fds16:07 - K10FDSR, - ) Разрешение движения РБ2
#define idB2AD01LDU	349	// (fds16:07 - K10FDSR, - ) Разрешение движения РБ2
#define B2AD02LDU	BUFFER[797]	// (fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
#define idB2AD02LDU	350	// (fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
#define B2AD03LDU	BUFFER[799]	// (fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
#define idB2AD03LDU	351	// (fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
#define B2AD04LDU	BUFFER[801]	// (fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
#define idB2AD04LDU	352	// (fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
#define B2AD05LDU	BUFFER[803]	// (fds16:07 - K14FDSR, - ) паритет команды на РБ2
#define idB2AD05LDU	353	// (fds16:07 - K14FDSR, - ) паритет команды на РБ2
#define B2AD11LDU	BUFFER[805]	// (fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	354	// (fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
#define B2AD21LDU	BUFFER[807]	// (fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	355	// (fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
#define B2AD31LDU	BUFFER[809]	// (fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
#define idB2AD31LDU	356	// (fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
#define B2AD32LDU	BUFFER[811]	// (fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
#define idB2AD32LDU	357	// (fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
#define B2AD33LDU	BUFFER[813]	// (fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
#define idB2AD33LDU	358	// (fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
#define B2AZ03LDU	BUFFER[815]	// ( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
#define idB2AZ03LDU	359	// ( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
#define B2CV01RDU	BUFFER[817]	// ( - , DU) Измеренная скорость перемещения РБ2
#define idB2CV01RDU	360	// ( - , DU) Измеренная скорость перемещения РБ2
#define B2CV02RDU	BUFFER[822]	// ( - , DU) Заданная скорость перемещения РБ2
#define idB2CV02RDU	361	// ( - , DU) Заданная скорость перемещения РБ2
#define B2IC01UDU	BUFFER[827]	// ( - , MDuS) Координата штока РБ2 (дел.энк)
#define idB2IC01UDU	362	// ( - , MDuS) Координата штока РБ2 (дел.энк)
#define B2IE01LDU	BUFFER[832]	// (vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
#define idB2IE01LDU	363	// (vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
#define B2IE02LDU	BUFFER[834]	// (vds32:05 - K17VDSR, - ) Исправность ИП РБ2
#define idB2IE02LDU	364	// (vds32:05 - K17VDSR, - ) Исправность ИП РБ2
#define B2IE03LDU	BUFFER[836]	// (vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
#define idB2IE03LDU	365	// (vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
#define B2IE04LDU	BUFFER[838]	// (vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
#define idB2IE04LDU	366	// (vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
#define B2IS11LDU	BUFFER[840]	// (vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
#define idB2IS11LDU	367	// (vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
#define B2IS12LDU	BUFFER[842]	// (vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
#define idB2IS12LDU	368	// (vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
#define B2IS21LDU	BUFFER[844]	// (vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
#define idB2IS21LDU	369	// (vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
#define B2IS33LDU	BUFFER[846]	// (vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
#define idB2IS33LDU	370	// (vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
#define B2MC01LC1	BUFFER[848]	// ( - , DU) Настроить энкодер РБ2
#define idB2MC01LC1	371	// ( - , DU) Настроить энкодер РБ2
#define B2MC01LC2	BUFFER[850]	// ( - , DU) Настроить энкодер РБ2
#define idB2MC01LC2	372	// ( - , DU) Настроить энкодер РБ2
#define B2MD11LP1	BUFFER[852]	// ( - , DU) Кнопка ПУСК РБ2
#define idB2MD11LP1	373	// ( - , DU) Кнопка ПУСК РБ2
#define B2MD12LP1	BUFFER[854]	// ( - , DU) Переключатель РАЗРЕШИТЬ РБ2
#define idB2MD12LP1	374	// ( - , DU) Переключатель РАЗРЕШИТЬ РБ2
#define B2VC01RDU	BUFFER[856]	// ( - , DU) Координата РБ2, мм
#define idB2VC01RDU	375	// ( - , DU) Координата РБ2, мм
#define B2VP82LDU	BUFFER[861]	// ( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define idB2VP82LDU	376	// ( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define B2VS01IDU	BUFFER[863]	// ( - , DU) Готовность к управлению РБ2
#define idB2VS01IDU	377	// ( - , DU) Готовность к управлению РБ2
#define B2VS11LDU	BUFFER[866]	// ( - , DU) Движение РБ2 в сторону ВУ
#define idB2VS11LDU	378	// ( - , DU) Движение РБ2 в сторону ВУ
#define B2VS21LDU	BUFFER[868]	// ( - , DU) Движение РБ2 в сторону НУ
#define idB2VS21LDU	379	// ( - , DU) Движение РБ2 в сторону НУ
#define B2VS32LDU	BUFFER[870]	// ( - , DU) Индикация  СБРОС РБ2
#define idB2VS32LDU	380	// ( - , DU) Индикация  СБРОС РБ2
#define B3AB01LDU	BUFFER[872]	// ( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
#define idB3AB01LDU	381	// ( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
#define B3AB02LDU	BUFFER[874]	// ( - , DU) Блокировка движения ИС2: превышение заданной скорости
#define idB3AB02LDU	382	// ( - , DU) Блокировка движения ИС2: превышение заданной скорости
#define B3AB04LDU	BUFFER[876]	// ( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
#define idB3AB04LDU	383	// ( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
#define B3AB05LDU	BUFFER[878]	// ( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
#define idB3AB05LDU	384	// ( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
#define B3AB06LDU	BUFFER[880]	// ( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
#define idB3AB06LDU	385	// ( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
#define B3AB07LDU	BUFFER[882]	// ( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
#define idB3AB07LDU	386	// ( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
#define B3AB08LDU	BUFFER[884]	// ( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
#define idB3AB08LDU	387	// ( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
#define B3AB09LDU	BUFFER[886]	// ( - , DU) Блокировка подъёма ИС2- АНИ не установлен
#define idB3AB09LDU	388	// ( - , DU) Блокировка подъёма ИС2- АНИ не установлен
#define B3AB10LDU	BUFFER[888]	// ( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
#define idB3AB10LDU	389	// ( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
#define B3AB11LDU	BUFFER[890]	// ( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
#define idB3AB11LDU	390	// ( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
#define B3AB12LDU	BUFFER[892]	// ( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define idB3AB12LDU	391	// ( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define B3AB13LDU	BUFFER[894]	// ( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define idB3AB13LDU	392	// ( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define B3AB14LDU	BUFFER[896]	// ( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
#define idB3AB14LDU	393	// ( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
#define B3AB15LDU	BUFFER[898]	// ( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
#define idB3AB15LDU	394	// ( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
#define B3AB16LDU	BUFFER[900]	// ( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
#define idB3AB16LDU	395	// ( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
#define B3AB17LDU	BUFFER[902]	// ( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
#define idB3AB17LDU	396	// ( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
#define B3AB18LDU	BUFFER[904]	// ( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
#define idB3AB18LDU	397	// ( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
#define B3AB19LDU	BUFFER[906]	// ( - , DU) Блокировка пневматического подъема ИС2: режим статический
#define idB3AB19LDU	398	// ( - , DU) Блокировка пневматического подъема ИС2: режим статический
#define B3AB20LDU	BUFFER[908]	// ( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
#define idB3AB20LDU	399	// ( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
#define B3AD01LDU	BUFFER[910]	// (fds16:0b - K10FDSR, - ) Разрешение движения ИС2
#define idB3AD01LDU	400	// (fds16:0b - K10FDSR, - ) Разрешение движения ИС2
#define B3AD02LDU	BUFFER[912]	// (fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
#define idB3AD02LDU	401	// (fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
#define B3AD03LDU	BUFFER[914]	// (fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
#define idB3AD03LDU	402	// (fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
#define B3AD04LDU	BUFFER[916]	// (fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
#define idB3AD04LDU	403	// (fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
#define B3AD05LDU	BUFFER[918]	// (fds16:0b - K14FDSR, - ) паритет команды на ИС2
#define idB3AD05LDU	404	// (fds16:0b - K14FDSR, - ) паритет команды на ИС2
#define B3AD11LDU	BUFFER[920]	// (fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	405	// (fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
#define B3AD21LDU	BUFFER[922]	// (fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	406	// (fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
#define B3AD31LDU	BUFFER[924]	// (fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
#define idB3AD31LDU	407	// (fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
#define B3AD33LDU	BUFFER[926]	// (fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define idB3AD33LDU	408	// (fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define B3AD34LDU	BUFFER[928]	// (fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
#define idB3AD34LDU	409	// (fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
#define B3AZ03LDU	BUFFER[930]	// ( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
#define idB3AZ03LDU	410	// ( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
#define B3CP02RDU	BUFFER[932]	// ( - , DU) Текущее давление ВЫСТРЕЛ ИС2
#define idB3CP02RDU	411	// ( - , DU) Текущее давление ВЫСТРЕЛ ИС2
#define B3CV01RDU	BUFFER[937]	// ( - , DU) Измеренная скорость перемещения ИС2
#define idB3CV01RDU	412	// ( - , DU) Измеренная скорость перемещения ИС2
#define B3CV02RDU	BUFFER[942]	// ( - , DU) Заданная скорость перемещения ИС2
#define idB3CV02RDU	413	// ( - , DU) Заданная скорость перемещения ИС2
#define B3EE03LDU	BUFFER[947]	// ( - , DU) ВПИС ИС2
#define idB3EE03LDU	414	// ( - , DU) ВПИС ИС2
#define B3IC01UDU	BUFFER[949]	// ( - , MDuS) Координата штока ИС2 (дел.энк)
#define idB3IC01UDU	415	// ( - , MDuS) Координата штока ИС2 (дел.энк)
#define B3IE01LDU	BUFFER[954]	// (vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
#define idB3IE01LDU	416	// (vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
#define B3IE02LDU	BUFFER[956]	// (vds32:05 - K21VDSR, - ) Исправность ИП ИС2
#define idB3IE02LDU	417	// (vds32:05 - K21VDSR, - ) Исправность ИП ИС2
#define B3IE03LDU	BUFFER[958]	// (vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
#define idB3IE03LDU	418	// (vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
#define B3IE04LDU	BUFFER[960]	// (vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
#define idB3IE04LDU	419	// (vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
#define B3IP02IDU	BUFFER[962]	// (vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
#define idB3IP02IDU	420	// (vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
#define B3IS11LDU	BUFFER[965]	// (vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
#define idB3IS11LDU	421	// (vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
#define B3IS12LDU	BUFFER[967]	// ( - , DU) Приход на ВУ штока ИС2
#define idB3IS12LDU	422	// ( - , DU) Приход на ВУ штока ИС2
#define B3IS21LDU	BUFFER[969]	// (vds32:02 - K13VDSR, DU) Приход на НУ ИС2
#define idB3IS21LDU	423	// (vds32:02 - K13VDSR, DU) Приход на НУ ИС2
#define B3IS22LDU	BUFFER[971]	// (vds32:04 - K04VDSR, DU) Приход на НУП ИС2
#define idB3IS22LDU	424	// (vds32:04 - K04VDSR, DU) Приход на НУП ИС2
#define B3IS31LDU	BUFFER[973]	// (vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
#define idB3IS31LDU	425	// (vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
#define B3IS33LDU	BUFFER[975]	// (vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
#define idB3IS33LDU	426	// (vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
#define B3IS35LDU	BUFFER[977]	// (vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
#define idB3IS35LDU	427	// (vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
#define B3MC01LC1	BUFFER[979]	// ( - , DU) Настроить энкодер ИС2
#define idB3MC01LC1	428	// ( - , DU) Настроить энкодер ИС2
#define B3MC01LC2	BUFFER[981]	// ( - , DU) Настроить энкодер ИС2
#define idB3MC01LC2	429	// ( - , DU) Настроить энкодер ИС2
#define B3MC01RP1	BUFFER[983]	// ( - , DU) Заданная координата положения ИС2 мм
#define idB3MC01RP1	430	// ( - , DU) Заданная координата положения ИС2 мм
#define B3MD11LP1	BUFFER[988]	// ( - , DU) Кнопка ПУСК ИС2
#define idB3MD11LP1	431	// ( - , DU) Кнопка ПУСК ИС2
#define B3MD12LP1	BUFFER[990]	// ( - , DU) Переключатель РАЗРЕШИТЬ ИС2
#define idB3MD12LP1	432	// ( - , DU) Переключатель РАЗРЕШИТЬ ИС2
#define B3VC01RDU	BUFFER[992]	// ( - , DU) Координата ИС2, мм
#define idB3VC01RDU	433	// ( - , DU) Координата ИС2, мм
#define B3VP42LDU	BUFFER[997]	// ( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
#define idB3VP42LDU	434	// ( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
#define B3VP52LDU	BUFFER[999]	// ( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define idB3VP52LDU	435	// ( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define B3VP81LDU	BUFFER[1001]	// ( - , - ) Давление СПУСК ИС2 в норме
#define idB3VP81LDU	436	// ( - , - ) Давление СПУСК ИС2 в норме
#define B3VP82LDU	BUFFER[1003]	// ( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
#define idB3VP82LDU	437	// ( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
#define B3VS01IDU	BUFFER[1005]	// ( - , DU) Готовность к управлению ИС2
#define idB3VS01IDU	438	// ( - , DU) Готовность к управлению ИС2
#define B3VS12LDU	BUFFER[1008]	// ( - , DU) Движение ИС2 в сторону ВУ
#define idB3VS12LDU	439	// ( - , DU) Движение ИС2 в сторону ВУ
#define B3VS22LDU	BUFFER[1010]	// ( - , DU) Движение ИС2 в сторону НУ
#define idB3VS22LDU	440	// ( - , DU) Движение ИС2 в сторону НУ
#define B3VX01LDU	BUFFER[1012]	// ( - , DU) Индикация Выстрел ИС2
#define idB3VX01LDU	441	// ( - , DU) Индикация Выстрел ИС2
#define B4AB01LDU	BUFFER[1014]	// ( - , DU) Блокировка движения НИ2 - Превышение времени движения
#define idB4AB01LDU	442	// ( - , DU) Блокировка движения НИ2 - Превышение времени движения
#define B4AB02LDU	BUFFER[1016]	// ( - , DU) Блокировка движения НИ2 - Нет перемещения
#define idB4AB02LDU	443	// ( - , DU) Блокировка движения НИ2 - Нет перемещения
#define B4AD10LDU	BUFFER[1018]	// (fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
#define idB4AD10LDU	444	// (fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
#define B4AZ03LDU	BUFFER[1020]	// ( - , DU) Несанкционированное перемещение НИ2
#define idB4AZ03LDU	445	// ( - , DU) Несанкционированное перемещение НИ2
#define B4IS10LDU	BUFFER[1022]	// (vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
#define idB4IS10LDU	446	// (vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
#define B4IS11LDU	BUFFER[1024]	// (vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
#define idB4IS11LDU	447	// (vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
#define B4IS21LDU	BUFFER[1026]	// (vds32:02 - K32VDSR, DU) Приход на НУ НИ2
#define idB4IS21LDU	448	// (vds32:02 - K32VDSR, DU) Приход на НУ НИ2
#define B4VP82LDU	BUFFER[1028]	// ( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	449	// ( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define B4VS01IDU	BUFFER[1030]	// ( - , DU) Готовность к управлению НИ2
#define idB4VS01IDU	450	// ( - , DU) Готовность к управлению НИ2
#define B4VS12LDU	BUFFER[1033]	// ( - , DU) Движение НИ2 в сторону ВУ
#define idB4VS12LDU	451	// ( - , DU) Движение НИ2 в сторону ВУ
#define B4VS22LDU	BUFFER[1035]	// ( - , DU) Движение НИ2 в сторону НУ
#define idB4VS22LDU	452	// ( - , DU) Движение НИ2 в сторону НУ
#define B5AB01LDU	BUFFER[1037]	// ( - , DU) Блокировка движения НЛ2 - Превышение времени движения
#define idB5AB01LDU	453	// ( - , DU) Блокировка движения НЛ2 - Превышение времени движения
#define B5AB02LDU	BUFFER[1039]	// ( - , DU) Блокировка движения НЛ2 - Нет перемещения
#define idB5AB02LDU	454	// ( - , DU) Блокировка движения НЛ2 - Нет перемещения
#define B5AB04LDU	BUFFER[1041]	// ( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
#define idB5AB04LDU	455	// ( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
#define B5AD10LDU	BUFFER[1043]	// (fds16:0a - K13FDSR, - ) Поднять НЛ2
#define idB5AD10LDU	456	// (fds16:0a - K13FDSR, - ) Поднять НЛ2
#define B5AD20LDU	BUFFER[1045]	// (fds16:0a - K14FDSR, - ) Опустить НЛ2
#define idB5AD20LDU	457	// (fds16:0a - K14FDSR, - ) Опустить НЛ2
#define B5AZ03LDU	BUFFER[1047]	// ( - , DU) Несанкционированное перемещение НЛ2
#define idB5AZ03LDU	458	// ( - , DU) Несанкционированное перемещение НЛ2
#define B5IE01LDU	BUFFER[1049]	// (vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
#define idB5IE01LDU	459	// (vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
#define B5IS11LDU	BUFFER[1051]	// (vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
#define idB5IS11LDU	460	// (vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
#define B5IS21LDU	BUFFER[1053]	// (vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
#define idB5IS21LDU	461	// (vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
#define B5VS01IDU	BUFFER[1055]	// ( - , DU) Готовность к управлению НЛ2
#define idB5VS01IDU	462	// ( - , DU) Готовность к управлению НЛ2
#define B5VS12LDU	BUFFER[1058]	// (vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
#define idB5VS12LDU	463	// (vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
#define B5VS22LDU	BUFFER[1060]	// (vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
#define idB5VS22LDU	464	// (vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
#define B6AB01LDU	BUFFER[1062]	// ( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
#define idB6AB01LDU	465	// ( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
#define B6AB02LDU	BUFFER[1064]	// ( - , DU) Блокировка движения БЗ2 - Нет перемещения
#define idB6AB02LDU	466	// ( - , DU) Блокировка движения БЗ2 - Нет перемещения
#define B6AB04LDU	BUFFER[1066]	// ( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
#define idB6AB04LDU	467	// ( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
#define B6AB05LDU	BUFFER[1068]	// ( - , DU) Блокировка открытия БЗ2- АНИ не установлен
#define idB6AB05LDU	468	// ( - , DU) Блокировка открытия БЗ2- АНИ не установлен
#define B6AB06LDU	BUFFER[1070]	// ( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
#define idB6AB06LDU	469	// ( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
#define B6AB07LDU	BUFFER[1072]	// ( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
#define idB6AB07LDU	470	// ( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
#define B6AB08LDU	BUFFER[1074]	// ( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
#define idB6AB08LDU	471	// ( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
#define B6AB09LDU	BUFFER[1076]	// ( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
#define idB6AB09LDU	472	// ( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
#define B6AD10LDU	BUFFER[1078]	// (fds16:09 - K11FDSR, - ) Открыть БЗ2
#define idB6AD10LDU	473	// (fds16:09 - K11FDSR, - ) Открыть БЗ2
#define B6AD20LDU	BUFFER[1080]	// (fds16:09 - K12FDSR, - ) Закрыть БЗ2
#define idB6AD20LDU	474	// (fds16:09 - K12FDSR, - ) Закрыть БЗ2
#define B6AZ03LDU	BUFFER[1082]	// ( - , DU) Несанкционированное перемещение БЗ2
#define idB6AZ03LDU	475	// ( - , DU) Несанкционированное перемещение БЗ2
#define B6IE01LDU	BUFFER[1084]	// (vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
#define idB6IE01LDU	476	// (vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
#define B6IS11LDU	BUFFER[1086]	// (vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
#define idB6IS11LDU	477	// (vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
#define B6IS21LDU	BUFFER[1088]	// (vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
#define idB6IS21LDU	478	// (vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
#define B6VS01IDU	BUFFER[1090]	// ( - , DU) Готовность к управлению БЗ2
#define idB6VS01IDU	479	// ( - , DU) Готовность к управлению БЗ2
#define B6VS12LDU	BUFFER[1093]	// (vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
#define idB6VS12LDU	480	// (vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
#define B6VS22LDU	BUFFER[1095]	// (vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
#define idB6VS22LDU	481	// (vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
#define B7AP31LDU	BUFFER[1097]	// (fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
#define idB7AP31LDU	482	// (fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
#define B7AS31LDU	BUFFER[1099]	// (vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
#define idB7AS31LDU	483	// (vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
#define B7AZ03LDU	BUFFER[1101]	// ( - , DU) Несанкционированное включение обдува АЗ2
#define idB7AZ03LDU	484	// ( - , DU) Несанкционированное включение обдува АЗ2
#define B8AB01LDU	BUFFER[1103]	// ( - , DU) Блокировка движения АЗ2 - Превышение времени движения
#define idB8AB01LDU	485	// ( - , DU) Блокировка движения АЗ2 - Превышение времени движения
#define B8AB02LDU	BUFFER[1105]	// ( - , DU) Блокировка движения АЗ2- АНИ не установлен
#define idB8AB02LDU	486	// ( - , DU) Блокировка движения АЗ2- АНИ не установлен
#define B8AB04LDU	BUFFER[1107]	// ( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
#define idB8AB04LDU	487	// ( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
#define B8AB05LDU	BUFFER[1109]	// ( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
#define idB8AB05LDU	488	// ( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
#define B8AB06LDU	BUFFER[1111]	// ( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
#define idB8AB06LDU	489	// ( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
#define B8AB07LDU	BUFFER[1113]	// ( - , DU) Блокировка движения АЗ2: превышение заданной скорости
#define idB8AB07LDU	490	// ( - , DU) Блокировка движения АЗ2: превышение заданной скорости
#define B8AB08LDU	BUFFER[1115]	// ( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
#define idB8AB08LDU	491	// ( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
#define B8AB09LDU	BUFFER[1117]	// ( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
#define idB8AB09LDU	492	// ( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
#define B8AB10LDU	BUFFER[1119]	// ( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
#define idB8AB10LDU	493	// ( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
#define B8AB11LDU	BUFFER[1121]	// ( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
#define idB8AB11LDU	494	// ( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
#define B8AB12LDU	BUFFER[1123]	// ( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
#define idB8AB12LDU	495	// ( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
#define B8AB13LDU	BUFFER[1125]	// ( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
#define idB8AB13LDU	496	// ( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
#define B8AB14LDU	BUFFER[1127]	// ( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
#define idB8AB14LDU	497	// ( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
#define B8AD10LDU	BUFFER[1129]	// (fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
#define idB8AD10LDU	498	// (fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
#define B8AD20LDU	BUFFER[1131]	// (fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
#define idB8AD20LDU	499	// (fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
#define B8AZ03LDU	BUFFER[1133]	// ( - , DU) Несанкционированное перемещение АЗ2
#define idB8AZ03LDU	500	// ( - , DU) Несанкционированное перемещение АЗ2
#define B8CV01RDU	BUFFER[1135]	// ( - , DU) Измеренная скорость перемещения АЗ2
#define idB8CV01RDU	501	// ( - , DU) Измеренная скорость перемещения АЗ2
#define B8IC01UDU	BUFFER[1140]	// ( - , MDuS) Координата АЗ2 (дел.энк)
#define idB8IC01UDU	502	// ( - , MDuS) Координата АЗ2 (дел.энк)
#define B8IS11LDU	BUFFER[1145]	// (vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
#define idB8IS11LDU	503	// (vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
#define B8IS12LDU	BUFFER[1147]	// (vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
#define idB8IS12LDU	504	// (vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
#define B8IS21LDU	BUFFER[1149]	// (vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
#define idB8IS21LDU	505	// (vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
#define B8IS22LDU	BUFFER[1151]	// (vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
#define idB8IS22LDU	506	// (vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
#define B8MC01LC1	BUFFER[1153]	// ( - , DU) Настроить энкодер АЗ2
#define idB8MC01LC1	507	// ( - , DU) Настроить энкодер АЗ2
#define B8MC01LC2	BUFFER[1155]	// ( - , DU) Настроить энкодер АЗ2
#define idB8MC01LC2	508	// ( - , DU) Настроить энкодер АЗ2
#define B8MC01RP2	BUFFER[1157]	// ( - , DU) Заданная координата АЗ2 мм
#define idB8MC01RP2	509	// ( - , DU) Заданная координата АЗ2 мм
#define B8VC01RDU	BUFFER[1162]	// ( - , DU, MDuBz1, MDuBz2) Координата АЗ2, мм
#define idB8VC01RDU	510	// ( - , DU, MDuBz1, MDuBz2) Координата АЗ2, мм
#define B8VS01IDU	BUFFER[1167]	// ( - , DU) Готовность к управлению АЗ2
#define idB8VS01IDU	511	// ( - , DU) Готовность к управлению АЗ2
#define B8VS12LDU	BUFFER[1170]	// ( - , DU) Движение АЗ2 в сторону ВУ
#define idB8VS12LDU	512	// ( - , DU) Движение АЗ2 в сторону ВУ
#define B8VS22LDU	BUFFER[1172]	// ( - , DU) Движение АЗ2 в сторону НУ
#define idB8VS22LDU	513	// ( - , DU) Движение АЗ2 в сторону НУ
#define B8ZAV	BUFFER[1174]	// ( - , DU) 
#define idB8ZAV	514	// ( - , DU) 
#define B9AB01LDU	BUFFER[1176]	// ( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
#define idB9AB01LDU	515	// ( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
#define B9AB02LDU	BUFFER[1178]	// ( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
#define idB9AB02LDU	516	// ( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
#define B9AD10LDU	BUFFER[1180]	// (fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
#define idB9AD10LDU	517	// (fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
#define B9AZ03LDU	BUFFER[1182]	// ( - , DU) Несанкционированное перемещение НИ ДС2
#define idB9AZ03LDU	518	// ( - , DU) Несанкционированное перемещение НИ ДС2
#define B9IS11LDU	BUFFER[1184]	// (vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
#define idB9IS11LDU	519	// (vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
#define B9IS21LDU	BUFFER[1186]	// (vds32:02 - K26VDSR, DU) Приход на НУ НИ ДС2
#define idB9IS21LDU	520	// (vds32:02 - K26VDSR, DU) Приход на НУ НИ ДС2
#define C1MD31LP1	BUFFER[1188]	// ( - , DU) Кнопка СБРОС ББ
#define idC1MD31LP1	521	// ( - , DU) Кнопка СБРОС ББ
#define C1MD31LP2	BUFFER[1190]	// ( - , DU) Кнопка СБРОС ББ
#define idC1MD31LP2	522	// ( - , DU) Кнопка СБРОС ББ
#define C2MD31LP1	BUFFER[1192]	// ( - , DU) Кнопка СБРОС РБ
#define idC2MD31LP1	523	// ( - , DU) Кнопка СБРОС РБ
#define R0AB01LDU	BUFFER[1194]	// ( - , DU) Режим проверки разрешён
#define idR0AB01LDU	524	// ( - , DU) Режим проверки разрешён
#define R0AB02LDU	BUFFER[1196]	// ( - , DU) Нарушение времени задержки ИНИ
#define idR0AB02LDU	525	// ( - , DU) Нарушение времени задержки ИНИ
#define R0AB03LDU	BUFFER[1198]	// ( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
#define idR0AB03LDU	526	// ( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
#define R0AB04LDU	BUFFER[1200]	// ( - , DU) Нарушение времени срабатывания верхней АС II УР
#define idR0AB04LDU	527	// ( - , DU) Нарушение времени срабатывания верхней АС II УР
#define R0AB05LDU	BUFFER[1202]	// ( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
#define idR0AB05LDU	528	// ( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
#define R0AB06LDU	BUFFER[1204]	// ( - , DU) Нарушение времени задержки от ВУ РБ
#define idR0AB06LDU	529	// ( - , DU) Нарушение времени задержки от ВУ РБ
#define R0AB07LDU	BUFFER[1206]	// ( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
#define idR0AB07LDU	530	// ( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
#define R0AB08LDU	BUFFER[1208]	// ( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
#define idR0AB08LDU	531	// ( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
#define R0AB09LDU	BUFFER[1210]	// ( - , DU) Ошибка в заданной координате ББ1
#define idR0AB09LDU	532	// ( - , DU) Ошибка в заданной координате ББ1
#define R0AB10LDU	BUFFER[1212]	// ( - , DU) Ошибка в заданной координате ББ2
#define idR0AB10LDU	533	// ( - , DU) Ошибка в заданной координате ББ2
#define R0AB11LDU	BUFFER[1214]	// ( - , DU) Ошибка в заданной координате  ИС1
#define idR0AB11LDU	534	// ( - , DU) Ошибка в заданной координате  ИС1
#define R0AB12LDU	BUFFER[1216]	// ( - , DU) Ошибка в заданной координате  ИС2
#define idR0AB12LDU	535	// ( - , DU) Ошибка в заданной координате  ИС2
#define R0AB13LDU	BUFFER[1218]	// ( - , DU) Ошибка в заданной координате  АЗ2
#define idR0AB13LDU	536	// ( - , DU) Ошибка в заданной координате  АЗ2
#define R0AB14LDU	BUFFER[1220]	// ( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
#define idR0AB14LDU	537	// ( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
#define R0AB15LDU	BUFFER[1222]	// ( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
#define idR0AB15LDU	538	// ( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
#define R0AB16LDU	BUFFER[1224]	// ( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
#define idR0AB16LDU	539	// ( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
#define R0AB17LDU	BUFFER[1226]	// ( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
#define idR0AB17LDU	540	// ( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
#define R0AB18LDU	BUFFER[1228]	// ( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
#define idR0AB18LDU	541	// ( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
#define R0AB19LDU	BUFFER[1230]	// ( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
#define idR0AB19LDU	542	// ( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
#define R0AB20LDU	BUFFER[1232]	// ( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
#define idR0AB20LDU	543	// ( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
#define R0AD03LZ1	BUFFER[1234]	// (fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
#define idR0AD03LZ1	544	// (fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
#define R0AD03LZ2	BUFFER[1236]	// (fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
#define idR0AD03LZ2	545	// (fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
#define R0AD04LZ1	BUFFER[1238]	// (fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define idR0AD04LZ1	546	// (fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define R0AD04LZ2	BUFFER[1240]	// (fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define idR0AD04LZ2	547	// (fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define R0AD05LZ1	BUFFER[1242]	// (fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
#define idR0AD05LZ1	548	// (fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
#define R0AD05LZ2	BUFFER[1244]	// (fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
#define idR0AD05LZ2	549	// (fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
#define R0AD14LZ1	BUFFER[1246]	// (vds32:02 - K20VDSR, DU) Имитация срабатывания АЗ от II УР
#define idR0AD14LZ1	550	// (vds32:02 - K20VDSR, DU) Имитация срабатывания АЗ от II УР
#define R0AD14LZ2	BUFFER[1248]	// (vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
#define idR0AD14LZ2	551	// (vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
#define R0AD16LDU	BUFFER[1250]	// (fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
#define idR0AD16LDU	552	// (fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
#define R0AD21LDU	BUFFER[1252]	// ( - , MDuBz1, MDuBz2) Подключить защиту от II УР
#define idR0AD21LDU	553	// ( - , MDuBz1, MDuBz2) Подключить защиту от II УР
#define R0CN91LDU	BUFFER[1254]	// ( - , DU) Рассчётная реактивность от регулятора
#define idR0CN91LDU	554	// ( - , DU) Рассчётная реактивность от регулятора
#define R0CN93LDU	BUFFER[1259]	// ( - , DU) время работы на мощности более 100Вт, сек
#define idR0CN93LDU	555	// ( - , DU) время работы на мощности более 100Вт, сек
#define R0CN95LDU	BUFFER[1264]	// ( - , DU) Этап 0 - не начинали, 54 - выход в 0 реакт, 59 - доводка, 55 - в зоне нечувст
#define idR0CN95LDU	556	// ( - , DU) Этап 0 - не начинали, 54 - выход в 0 реакт, 59 - доводка, 55 - в зоне нечувст
#define R0DE01LDU	BUFFER[1267]	// (vencf8l:01 - DiagnVDS, DiagnDU) диагностика модуля ДУ на 1 месте
#define idR0DE01LDU	557	// (vencf8l:01 - DiagnVDS, DiagnDU) диагностика модуля ДУ на 1 месте
#define R0DE02LDU	BUFFER[1270]	// (vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
#define idR0DE02LDU	558	// (vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
#define R0DE03LDU	BUFFER[1273]	// (vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
#define idR0DE03LDU	559	// (vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
#define R0DE04LDU	BUFFER[1276]	// (vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
#define idR0DE04LDU	560	// (vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
#define R0DE05LDU	BUFFER[1279]	// (vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
#define idR0DE05LDU	561	// (vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
#define R0DE06LDU	BUFFER[1282]	// (vencf8l:01 - DiagnFDS, DiagnDU) диагностика модуля ДУ на 6 месте
#define idR0DE06LDU	562	// (vencf8l:01 - DiagnFDS, DiagnDU) диагностика модуля ДУ на 6 месте
#define R0DE07LDU	BUFFER[1285]	// (fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
#define idR0DE07LDU	563	// (fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
#define R0DE08LDU	BUFFER[1288]	// (fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
#define idR0DE08LDU	564	// (fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
#define R0DE09LDU	BUFFER[1291]	// (fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
#define idR0DE09LDU	565	// (fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
#define R0DE0ALDU	BUFFER[1294]	// (fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
#define idR0DE0ALDU	566	// (fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
#define R0DE0BLDU	BUFFER[1297]	// (fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
#define idR0DE0BLDU	567	// (fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
#define R0DE0CLDU	BUFFER[1300]	// (vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
#define idR0DE0CLDU	568	// (vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
#define R0DE0DLDU	BUFFER[1303]	// (vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
#define idR0DE0DLDU	569	// (vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
#define R0DE0FLDU	BUFFER[1306]	// (fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
#define idR0DE0FLDU	570	// (fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
#define R0DE3CLDU	BUFFER[1309]	// ( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
#define idR0DE3CLDU	571	// ( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
#define R0DE3DLDU	BUFFER[1311]	// ( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
#define idR0DE3DLDU	572	// ( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
#define R0DEB1LDU	BUFFER[1313]	// (sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
#define idR0DEB1LDU	573	// (sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
#define R0DEB2LDU	BUFFER[1315]	// (sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
#define idR0DEB2LDU	574	// (sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
#define R0DEB3LDU	BUFFER[1317]	// (sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
#define idR0DEB3LDU	575	// (sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
#define R0DEB4LDU	BUFFER[1319]	// (sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
#define idR0DEB4LDU	576	// (sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
#define R0EE02LDU	BUFFER[1321]	// ( - , DU) Питание  АКНП  отключить
#define idR0EE02LDU	577	// ( - , DU) Питание  АКНП  отключить
#define R0EE03LDU	BUFFER[1323]	// ( - , DU) ВПИС ИС
#define idR0EE03LDU	578	// ( - , DU) ВПИС ИС
#define R0ES01LDU	BUFFER[1325]	// ( - , DU) ОРР не в исходном состоянии
#define idR0ES01LDU	579	// ( - , DU) ОРР не в исходном состоянии
#define R0IE01LDU	BUFFER[1327]	// (vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
#define idR0IE01LDU	580	// (vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
#define R0IE02LDU	BUFFER[1329]	// (vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
#define idR0IE02LDU	581	// (vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
#define R0IS01LDU	BUFFER[1331]	// (vds32:03 - K29VDSR, DU) Признак работы с имитатором
#define idR0IS01LDU	582	// (vds32:03 - K29VDSR, DU) Признак работы с имитатором
#define R0IS02LDU	BUFFER[1333]	// (vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
#define idR0IS02LDU	583	// (vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
#define R0MD11LP1	BUFFER[1335]	// ( - , DU) Кнопка ПУСК
#define idR0MD11LP1	584	// ( - , DU) Кнопка ПУСК
#define R0MD11LP2	BUFFER[1337]	// ( - , DU) Кнопка Пуск проверки схем сброса
#define idR0MD11LP2	585	// ( - , DU) Кнопка Пуск проверки схем сброса
#define R0MD31LP1	BUFFER[1339]	// ( - , DU) Кнопка СТОП
#define idR0MD31LP1	586	// ( - , DU) Кнопка СТОП
#define R0MD32LP1	BUFFER[1341]	// ( - , DU) Кнопка СПУСК
#define idR0MD32LP1	587	// ( - , DU) Кнопка СПУСК
#define R0MD33LP1	BUFFER[1343]	// ( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
#define idR0MD33LP1	588	// ( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
#define R0MD34LP1	BUFFER[1345]	// ( - , DU) Кнопка КВИТИРОВАТЬ
#define idR0MD34LP1	589	// ( - , DU) Кнопка КВИТИРОВАТЬ
#define R0MW11IP1	BUFFER[1347]	// ( - , DU) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	590	// ( - , DU) Переключатель ВЫСТРЕЛ
#define R0MW11IP2	BUFFER[1350]	// ( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
#define idR0MW11IP2	591	// ( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
#define R0MW12IP1	BUFFER[1353]	// ( - , DU) Переключатель РЕЖИМ РАБОТЫ
#define idR0MW12IP1	592	// ( - , DU) Переключатель РЕЖИМ РАБОТЫ
#define R0MW12IP2	BUFFER[1356]	// ( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define idR0MW12IP2	593	// ( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define R0MW13IP1	BUFFER[1359]	// ( - , DU) Переключатель ВЫБОР ЗОН
#define idR0MW13IP1	594	// ( - , DU) Переключатель ВЫБОР ЗОН
#define R0MW13LP2	BUFFER[1362]	// ( - , DU) Переключатель СЕТЬ
#define idR0MW13LP2	595	// ( - , DU) Переключатель СЕТЬ
#define R0MW14IP1	BUFFER[1364]	// ( - , DU) Переключатель ПРОГРАММЫ
#define idR0MW14IP1	596	// ( - , DU) Переключатель ПРОГРАММЫ
#define R0MW14IP2	BUFFER[1367]	// ( - , DU) Переключатель ОБДУВ
#define idR0MW14IP2	597	// ( - , DU) Переключатель ОБДУВ
#define R0MW15IP1	BUFFER[1370]	// ( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
#define idR0MW15IP1	598	// ( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
#define R0MW16IP1	BUFFER[1373]	// ( - , DU) Переключатель ВИД ПРОВЕРКИ
#define idR0MW16IP1	599	// ( - , DU) Переключатель ВИД ПРОВЕРКИ
#define R0MW17LP1	BUFFER[1376]	// ( - , DU) Переключатель АВТ/Р
#define idR0MW17LP1	600	// ( - , DU) Переключатель АВТ/Р
#define R0NE01LDU	BUFFER[1378]	// ( - , DU) Потеря связи с БАЗ1
#define idR0NE01LDU	601	// ( - , DU) Потеря связи с БАЗ1
#define R0NE02LDU	BUFFER[1380]	// ( - , DU) Потеря связи с БАЗ2
#define idR0NE02LDU	602	// ( - , DU) Потеря связи с БАЗ2
#define R0NE08LDU	BUFFER[1382]	// ( - , DU) Потеря связи с ОПУ
#define idR0NE08LDU	603	// ( - , DU) Потеря связи с ОПУ
#define R0S01LDU	BUFFER[1384]	// ( - , - ) Отключение сетевых передач ДУ
#define idR0S01LDU	604	// ( - , - ) Отключение сетевых передач ДУ
#define R0S01LIM	BUFFER[1386]	// (fds16:08 - K15FDSR, - ) Отключение сетевых передач ПТИ
#define idR0S01LIM	605	// (fds16:08 - K15FDSR, - ) Отключение сетевых передач ПТИ
#define R0S01LZ1	BUFFER[1388]	// (fds16:07 - K15FDSR, - ) Отключение сетевых передач в Баз1
#define idR0S01LZ1	606	// (fds16:07 - K15FDSR, - ) Отключение сетевых передач в Баз1
#define R0S01LZ2	BUFFER[1390]	// (fds16:07 - K16FDSR, - ) Отключение сетевых передач в Баз2
#define idR0S01LZ2	607	// (fds16:07 - K16FDSR, - ) Отключение сетевых передач в Баз2
#define R0VL01IDU	BUFFER[1392]	// ( - , DU) До импульса минут
#define idR0VL01IDU	608	// ( - , DU) До импульса минут
#define R0VL01RDU	BUFFER[1395]	// ( - , DU) Индикация Время задержки
#define idR0VL01RDU	609	// ( - , DU) Индикация Время задержки
#define R0VL02RDU	BUFFER[1400]	// ( - , DU) Индикация (Время задержки ИНИ)
#define idR0VL02RDU	610	// ( - , DU) Индикация (Время задержки ИНИ)
#define R0VL03RDU	BUFFER[1405]	// ( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define idR0VL03RDU	611	// ( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define R0VL04RDU	BUFFER[1410]	// ( - , DU) Индикация (Время срабатывания верхней АС II УР)
#define idR0VL04RDU	612	// ( - , DU) Индикация (Время срабатывания верхней АС II УР)
#define R0VL05RDU	BUFFER[1415]	// ( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
#define idR0VL05RDU	613	// ( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
#define R0VL06RDU	BUFFER[1420]	// ( - , DU) Индикация (Время задержки от ВУ РБ)
#define idR0VL06RDU	614	// ( - , DU) Индикация (Время задержки от ВУ РБ)
#define R0VL11IDU	BUFFER[1425]	// ( - , DU) До импульса секунд
#define idR0VL11IDU	615	// ( - , DU) До импульса секунд
#define R0VL21IDU	BUFFER[1428]	// ( - , DU) Декатрон
#define idR0VL21IDU	616	// ( - , DU) Декатрон
#define R0VL22LDU	BUFFER[1431]	// ( - , DU) Конец программы 200сек
#define idR0VL22LDU	617	// ( - , DU) Конец программы 200сек
#define R0VL23LDU	BUFFER[1433]	// ( - , DU) Конец программы 20мин
#define idR0VL23LDU	618	// ( - , DU) Конец программы 20мин
#define R0VN11RDU	BUFFER[1435]	// ( - , DU) Текущая мощность РУ
#define idR0VN11RDU	619	// ( - , DU) Текущая мощность РУ
#define R0VN11RZ1	BUFFER[1440]	// ( - , MDuBz1) Средняя мощность по BAZ1
#define idR0VN11RZ1	620	// ( - , MDuBz1) Средняя мощность по BAZ1
#define R0VN11RZ2	BUFFER[1445]	// ( - , MDuBz2) Средняя мощность по BAZ2
#define idR0VN11RZ2	621	// ( - , MDuBz2) Средняя мощность по BAZ2
#define R0VN12RDU	BUFFER[1450]	// ( - , DU) Заданная мощность РУ
#define idR0VN12RDU	622	// ( - , DU) Заданная мощность РУ
#define R0VN15RDU	BUFFER[1455]	// ( - , DU) Период разгона РУ
#define idR0VN15RDU	623	// ( - , DU) Период разгона РУ
#define R0VP73LDU	BUFFER[1460]	// ( - , DU) ПС давления для РУ
#define idR0VP73LDU	624	// ( - , DU) ПС давления для РУ
#define R0VP73LZ1	BUFFER[1462]	// ( - , MDuBz1) ПС давления для РУ
#define idR0VP73LZ1	625	// ( - , MDuBz1) ПС давления для РУ
#define R0VP73LZ2	BUFFER[1464]	// ( - , MDuBz2) ПС давления для РУ
#define idR0VP73LZ2	626	// ( - , MDuBz2) ПС давления для РУ
#define R0VS11LDU	BUFFER[1466]	// ( - , DU) РУ не готова к работе
#define idR0VS11LDU	627	// ( - , DU) РУ не готова к работе
#define R0VS17LDU	BUFFER[1468]	// ( - , DU) Индикация выбора АВТОМАТ
#define idR0VS17LDU	628	// ( - , DU) Индикация выбора АВТОМАТ
#define R0VS18LDU	BUFFER[1470]	// ( - , DU) Индикация  Проверка схем сброса
#define idR0VS18LDU	629	// ( - , DU) Индикация  Проверка схем сброса
#define R0VS21IDU	BUFFER[1472]	// ( - , DU) Индикация ВИД ПРОВЕРКИ
#define idR0VS21IDU	630	// ( - , DU) Индикация ВИД ПРОВЕРКИ
#define R0VW13LDU	BUFFER[1475]	// ( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
#define idR0VW13LDU	631	// ( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
#define R0VW23LDU	BUFFER[1477]	// ( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
#define idR0VW23LDU	632	// ( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
#define R0VX01LDU	BUFFER[1479]	// ( - , DU) ДО ИМПУЛЬСА
#define idR0VX01LDU	633	// ( - , DU) ДО ИМПУЛЬСА
#define R0VX02LDU	BUFFER[1481]	// ( - , DU) Импульс разрешен
#define idR0VX02LDU	634	// ( - , DU) Импульс разрешен
#define R0VX03LDU	BUFFER[1483]	// ( - , DU) Готовность 2 мин
#define idR0VX03LDU	635	// ( - , DU) Готовность 2 мин
#define R0VX08IDU	BUFFER[1485]	// ( - , DU) Индикация Режим
#define idR0VX08IDU	636	// ( - , DU) Индикация Режим
#define R0VX09LDU	BUFFER[1488]	// ( - , DU) Индикация регулятор мощности включен/отключен
#define idR0VX09LDU	637	// ( - , DU) Индикация регулятор мощности включен/отключен
#define R0VZ71LDU	BUFFER[1490]	// ( - , DU) Обобщенный сигнал АЗ
#define idR0VZ71LDU	638	// ( - , DU) Обобщенный сигнал АЗ
#define R0VZ71LZ1	BUFFER[1492]	// (vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
#define idR0VZ71LZ1	639	// (vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
#define R0VZ71LZ2	BUFFER[1494]	// (vds32:03 - K22VDSR, - ) Обобщенный сигнал АЗ 2 канала
#define idR0VZ71LZ2	640	// (vds32:03 - K22VDSR, - ) Обобщенный сигнал АЗ 2 канала
#define R1AB01LDU	BUFFER[1496]	// ( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
#define idR1AB01LDU	641	// ( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
#define R1AB02LDU	BUFFER[1498]	// ( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
#define idR1AB02LDU	642	// ( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
#define R1AB04LDU	BUFFER[1500]	// ( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
#define idR1AB04LDU	643	// ( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
#define R1AD10LDU	BUFFER[1502]	// (fds16:0a - K07FDSR, - ) Опустить МДЗ1
#define idR1AD10LDU	644	// (fds16:0a - K07FDSR, - ) Опустить МДЗ1
#define R1AD20LDU	BUFFER[1504]	// (fds16:0a - K08FDSR, - ) Поднять МДЗ1
#define idR1AD20LDU	645	// (fds16:0a - K08FDSR, - ) Поднять МДЗ1
#define R1AZ03LDU	BUFFER[1506]	// ( - , DU) Несанкционированное перемещение МДЗ1
#define idR1AZ03LDU	646	// ( - , DU) Несанкционированное перемещение МДЗ1
#define R1IE01LDU	BUFFER[1508]	// (vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
#define idR1IE01LDU	647	// (vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
#define R1IS11LDU	BUFFER[1510]	// (vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
#define idR1IS11LDU	648	// (vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
#define R1IS21LDU	BUFFER[1512]	// (vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
#define idR1IS21LDU	649	// (vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
#define R1VS01IDU	BUFFER[1514]	// ( - , DU) Готовность к управлению МДЗ1
#define idR1VS01IDU	650	// ( - , DU) Готовность к управлению МДЗ1
#define R1VS12LDU	BUFFER[1517]	// (vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	651	// (vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
#define R1VS22LDU	BUFFER[1519]	// (vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	652	// (vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
#define R2AB01LDU	BUFFER[1521]	// ( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
#define idR2AB01LDU	653	// ( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
#define R2AB02LDU	BUFFER[1523]	// ( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
#define idR2AB02LDU	654	// ( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
#define R2AB04LDU	BUFFER[1525]	// ( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
#define idR2AB04LDU	655	// ( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
#define R2AD10LDU	BUFFER[1527]	// (fds16:0a - K09FDSR, - ) Опустить МДЗ2
#define idR2AD10LDU	656	// (fds16:0a - K09FDSR, - ) Опустить МДЗ2
#define R2AD20LDU	BUFFER[1529]	// (fds16:0a - K10FDSR, - ) Поднять МДЗ2
#define idR2AD20LDU	657	// (fds16:0a - K10FDSR, - ) Поднять МДЗ2
#define R2AZ03LDU	BUFFER[1531]	// ( - , DU) Несанкционированное перемещение МДЗ2
#define idR2AZ03LDU	658	// ( - , DU) Несанкционированное перемещение МДЗ2
#define R2IE01LDU	BUFFER[1533]	// (vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
#define idR2IE01LDU	659	// (vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
#define R2IS11LDU	BUFFER[1535]	// (vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
#define idR2IS11LDU	660	// (vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
#define R2IS21LDU	BUFFER[1537]	// (vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
#define idR2IS21LDU	661	// (vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
#define R2VS01IDU	BUFFER[1539]	// ( - , DU) Готовность к управлению МДЗ2
#define idR2VS01IDU	662	// ( - , DU) Готовность к управлению МДЗ2
#define R2VS12LDU	BUFFER[1542]	// (vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	663	// (vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
#define R2VS22LDU	BUFFER[1544]	// (vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	664	// (vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
#define R2ZAV	BUFFER[1546]	// ( - , DU) 
#define idR2ZAV	665	// ( - , DU) 
#define R3IS11LDU	BUFFER[1548]	// (vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
#define idR3IS11LDU	666	// (vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
#define R3IS21LDU	BUFFER[1550]	// (vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
#define idR3IS21LDU	667	// (vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
#define R3VS01IDU	BUFFER[1552]	// ( - , DU) Готовность к управлению гомогенных дверей
#define idR3VS01IDU	668	// ( - , DU) Готовность к управлению гомогенных дверей
#define R3VS12LDU	BUFFER[1555]	// ( - , DU) Движение гомогенных дверей к открыты
#define idR3VS12LDU	669	// ( - , DU) Движение гомогенных дверей к открыты
#define R3VS22LDU	BUFFER[1557]	// ( - , DU) Движение гомогенных дверей к закрыты
#define idR3VS22LDU	670	// ( - , DU) Движение гомогенных дверей к закрыты
#define R4AB01LDU	BUFFER[1559]	// ( - , DU) Блокировка движения тележки - АНИ не установлен
#define idR4AB01LDU	671	// ( - , DU) Блокировка движения тележки - АНИ не установлен
#define R4AB02LDU	BUFFER[1561]	// ( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
#define idR4AB02LDU	672	// ( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
#define R4AB03LDU	BUFFER[1563]	// ( - , DU) Блокировка движения тележки - Самоход любого механизма
#define idR4AB03LDU	673	// ( - , DU) Блокировка движения тележки - Самоход любого механизма
#define R4AB04LDU	BUFFER[1565]	// ( - , DU) Блокировка движения тележки - Превышение времени движения
#define idR4AB04LDU	674	// ( - , DU) Блокировка движения тележки - Превышение времени движения
#define R4AB05LDU	BUFFER[1567]	// ( - , DU) Блокировка движения  тележки - Нет перемещения тележки
#define idR4AB05LDU	675	// ( - , DU) Блокировка движения  тележки - Нет перемещения тележки
#define R4AB06LDU	BUFFER[1569]	// ( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
#define idR4AB06LDU	676	// ( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
#define R4AB07LDU	BUFFER[1571]	// ( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
#define idR4AB07LDU	677	// ( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
#define R4AB08LDU	BUFFER[1573]	// ( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define idR4AB08LDU	678	// ( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define R4AB09LDU	BUFFER[1575]	// ( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
#define idR4AB09LDU	679	// ( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
#define R4AB10LDU	BUFFER[1577]	// ( - , DU) Блокировка тележки - не открыта биологическая защита
#define idR4AB10LDU	680	// ( - , DU) Блокировка тележки - не открыта биологическая защита
#define R4AB11LDU	BUFFER[1579]	// ( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
#define idR4AB11LDU	681	// ( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
#define R4AB12LDU	BUFFER[1581]	// ( - , DU) Блокировка движения тележки - НИ не в положении ВУ
#define idR4AB12LDU	682	// ( - , DU) Блокировка движения тележки - НИ не в положении ВУ
#define R4AB13LDU	BUFFER[1583]	// ( - , DU) Блокировка тележки - НЛ не в положении ВУ
#define idR4AB13LDU	683	// ( - , DU) Блокировка тележки - НЛ не в положении ВУ
#define R4AB14LDU	BUFFER[1585]	// ( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
#define idR4AB14LDU	684	// ( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
#define R4AB15LDU	BUFFER[1587]	// ( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
#define idR4AB15LDU	685	// ( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
#define R4AB16LDU	BUFFER[1589]	// ( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
#define idR4AB16LDU	686	// ( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
#define R4AB17LDU	BUFFER[1591]	// ( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define idR4AB17LDU	687	// ( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define R4AB18LDU	BUFFER[1593]	// ( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define idR4AB18LDU	688	// ( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define R4ABL	BUFFER[1595]	// ( - , DU) Блокировка тележки -
#define idR4ABL	689	// ( - , DU) Блокировка тележки -
#define R4AD10LDU	BUFFER[1597]	// (fds16:09 - K13FDSR, - ) Перемещение тележки вперед
#define idR4AD10LDU	690	// (fds16:09 - K13FDSR, - ) Перемещение тележки вперед
#define R4AD20LDU	BUFFER[1599]	// (fds16:09 - K14FDSR, DU) Перемещение тележки назад
#define idR4AD20LDU	691	// (fds16:09 - K14FDSR, DU) Перемещение тележки назад
#define R4AZ03LDU	BUFFER[1601]	// ( - , DU) Несанкционированное перемещение тележки
#define idR4AZ03LDU	692	// ( - , DU) Несанкционированное перемещение тележки
#define R4IS11LDU	BUFFER[1603]	// (vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
#define idR4IS11LDU	693	// (vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
#define R4IS12LDU	BUFFER[1605]	// (vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
#define idR4IS12LDU	694	// (vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
#define R4IS21LDU	BUFFER[1607]	// (vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
#define idR4IS21LDU	695	// (vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
#define R4IS22LDU	BUFFER[1609]	// (vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
#define idR4IS22LDU	696	// (vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
#define R4MD11LP2	BUFFER[1611]	// ( - , DU) Кнопка ВПЕРЁД  (тележки)
#define idR4MD11LP2	697	// ( - , DU) Кнопка ВПЕРЁД  (тележки)
#define R4MD21LP2	BUFFER[1613]	// ( - , DU) Кнопка НАЗАД  (тележки)
#define idR4MD21LP2	698	// ( - , DU) Кнопка НАЗАД  (тележки)
#define R4MD31LP2	BUFFER[1615]	// ( - , DU) Кнопка СТОП  (тележки)
#define idR4MD31LP2	699	// ( - , DU) Кнопка СТОП  (тележки)
#define R4VS01IDU	BUFFER[1617]	// ( - , DU) Готовность к управлению тележкой реактора
#define idR4VS01IDU	700	// ( - , DU) Готовность к управлению тележкой реактора
#define R4VS12LDU	BUFFER[1620]	// (vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
#define idR4VS12LDU	701	// (vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
#define R4VS22LDU	BUFFER[1622]	// (vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
#define idR4VS22LDU	702	// (vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
#define R5IS11LDU	BUFFER[1624]	// (vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	703	// (vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
#define R5IS21LDU	BUFFER[1626]	// (vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	704	// (vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
#define R5VS01IDU	BUFFER[1628]	// ( - , DU) Готовность к управлению ворот отстойной зоны
#define idR5VS01IDU	705	// ( - , DU) Готовность к управлению ворот отстойной зоны
#define R5VS12LDU	BUFFER[1631]	// ( - , DU) Движение ворот отстойной зоны к открыты
#define idR5VS12LDU	706	// ( - , DU) Движение ворот отстойной зоны к открыты
#define R5VS22LDU	BUFFER[1633]	// ( - , DU) Движение ворот отстойной зоны к закрыты
#define idR5VS22LDU	707	// ( - , DU) Движение ворот отстойной зоны к закрыты
#define R6IS21LDU	BUFFER[1635]	// (vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
#define idR6IS21LDU	708	// (vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
#define R6IS31LDU	BUFFER[1637]	// (vds32:05 - K25VDSR, - ) контроль задней двери ШС
#define idR6IS31LDU	709	// (vds32:05 - K25VDSR, - ) контроль задней двери ШС
#define R6IS32LDU	BUFFER[1639]	// (vds32:05 - K26VDSR, - ) контроль передней двери ШС
#define idR6IS32LDU	710	// (vds32:05 - K26VDSR, - ) контроль передней двери ШС
#define R6IS41LDU	BUFFER[1641]	// (vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
#define idR6IS41LDU	711	// (vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
#define R6IS42LDU	BUFFER[1643]	// (vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
#define idR6IS42LDU	712	// (vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
#define R6IS51LDU	BUFFER[1645]	// (vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
#define idR6IS51LDU	713	// (vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
#define R6IS52LDU	BUFFER[1647]	// (vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
#define idR6IS52LDU	714	// (vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
#define R6IS61LDU	BUFFER[1649]	// (vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
#define idR6IS61LDU	715	// (vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
#define R6IS66LZZ	BUFFER[1651]	// ( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	716	// ( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	BUFFER[1653]	// ( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	717	// ( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	BUFFER[1655]	// ( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	718	// ( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define R8AD21LDU	BUFFER[1657]	// (fds16:0f - K12FDSR, - ) Запуск системы инициирования
#define idR8AD21LDU	719	// (fds16:0f - K12FDSR, - ) Запуск системы инициирования
#define R8AD22LDU	BUFFER[1659]	// (vds32:02 - K15VDSR, - ) Сигнал синхронизации с импульсом
#define idR8AD22LDU	720	// (vds32:02 - K15VDSR, - ) Сигнал синхронизации с импульсом
#define R8IS11LDU	BUFFER[1661]	// (vds32:02 - K14VDSR, DU) Аварийный НИ установлен
#define idR8IS11LDU	721	// (vds32:02 - K14VDSR, DU) Аварийный НИ установлен
#define TTLDU	BUFFER[1663]	// ( - , DU) ttl
#define idTTLDU	722	// ( - , DU) ttl
#define TestDiagnDU	BUFFER[1666]	// ( - , DU) Неисправность от
#define idTestDiagnDU	723	// ( - , DU) Неисправность от
#define bFirstEnterFlag	BUFFER[1668]	// (bFirstEnterFlag) 
#define idbFirstEnterFlag	724	// (bFirstEnterFlag) 
#define dEM_A1UC05UDU	BUFFER[1670]	// (A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC05UDU	725	// (A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define dEM_A1UC06UDU	BUFFER[1675]	// (A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC06UDU	726	// (A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define dEM_A2UC05UDU	BUFFER[1680]	// (A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC05UDU	727	// (A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define dEM_A2UC06UDU	BUFFER[1685]	// (A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC06UDU	728	// (A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define dEM_A3UC05UDU	BUFFER[1690]	// (A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC05UDU	729	// (A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define dEM_A3UC06UDU	BUFFER[1695]	// (A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC06UDU	730	// (A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define dEM_A8UC05UDU	BUFFER[1700]	// (A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define iddEM_A8UC05UDU	731	// (A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define dEM_A8UC06UDU	BUFFER[1705]	// (A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define iddEM_A8UC06UDU	732	// (A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define fEM_A1UC02RDU	BUFFER[1710]	// (A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define idfEM_A1UC02RDU	733	// (A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define fEM_A1UC03RDU	BUFFER[1715]	// (A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define idfEM_A1UC03RDU	734	// (A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define fEM_A1UC05RDU	BUFFER[1720]	// (A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A1UC05RDU	735	// (A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A1UC06RDU	BUFFER[1725]	// (A1UC06RDU) Уставка определения самохода ББ  мм
#define idfEM_A1UC06RDU	736	// (A1UC06RDU) Уставка определения самохода ББ  мм
#define fEM_A1UC07RDU	BUFFER[1730]	// (A1UC07RDU) Зона возврата при наведении ББ мм
#define idfEM_A1UC07RDU	737	// (A1UC07RDU) Зона возврата при наведении ББ мм
#define fEM_A1UC08RDU	BUFFER[1735]	// (A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define idfEM_A1UC08RDU	738	// (A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define fEM_A1UC81RDU	BUFFER[1740]	// (A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC81RDU	739	// (A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define fEM_A1UC82RDU	BUFFER[1745]	// (A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC82RDU	740	// (A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define fEM_A1UC83RDU	BUFFER[1750]	// (A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define idfEM_A1UC83RDU	741	// (A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define fEM_A1UL01RDU	BUFFER[1755]	// (A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A1UL01RDU	742	// (A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A1UL03RDU	BUFFER[1760]	// (A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define idfEM_A1UL03RDU	743	// (A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define fEM_A1UL04RDU	BUFFER[1765]	// (A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define idfEM_A1UL04RDU	744	// (A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define fEM_A1UL05RDU	BUFFER[1770]	// (A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define idfEM_A1UL05RDU	745	// (A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define fEM_A1UR01RDU	BUFFER[1775]	// (A1UR01RDU) коэффициент реактивности от координаты ББ
#define idfEM_A1UR01RDU	746	// (A1UR01RDU) коэффициент реактивности от координаты ББ
#define fEM_A1UV01RDU	BUFFER[1780]	// (A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define idfEM_A1UV01RDU	747	// (A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define fEM_A1UV02RDU	BUFFER[1785]	// (A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define idfEM_A1UV02RDU	748	// (A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define fEM_A2UC02RDU	BUFFER[1790]	// (A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define idfEM_A2UC02RDU	749	// (A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define fEM_A2UC03RDU	BUFFER[1795]	// (A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define idfEM_A2UC03RDU	750	// (A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define fEM_A2UC05RDU	BUFFER[1800]	// (A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A2UC05RDU	751	// (A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A2UC06RDU	BUFFER[1805]	// (A2UC06RDU) Уставка определения самохода РБ  мм
#define idfEM_A2UC06RDU	752	// (A2UC06RDU) Уставка определения самохода РБ  мм
#define fEM_A2UC07RDU	BUFFER[1810]	// (A2UC07RDU) Зона возврата при наведении РБ  мм
#define idfEM_A2UC07RDU	753	// (A2UC07RDU) Зона возврата при наведении РБ  мм
#define fEM_A2UC08RDU	BUFFER[1815]	// (A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define idfEM_A2UC08RDU	754	// (A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define fEM_A2UC81RDU	BUFFER[1820]	// (A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC81RDU	755	// (A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define fEM_A2UC82RDU	BUFFER[1825]	// (A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC82RDU	756	// (A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define fEM_A2UC83RDU	BUFFER[1830]	// (A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define idfEM_A2UC83RDU	757	// (A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define fEM_A2UL01RDU	BUFFER[1835]	// (A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A2UL01RDU	758	// (A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A2UL03RDU	BUFFER[1840]	// (A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL03RDU	759	// (A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A2UL04RDU	BUFFER[1845]	// (A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define idfEM_A2UL04RDU	760	// (A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define fEM_A2UL05RDU	BUFFER[1850]	// (A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define idfEM_A2UL05RDU	761	// (A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define fEM_A2UL83RDU	BUFFER[1855]	// (A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL83RDU	762	// (A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A2UV01RDU	BUFFER[1860]	// (A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define idfEM_A2UV01RDU	763	// (A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define fEM_A2UV02RDU	BUFFER[1865]	// (A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define idfEM_A2UV02RDU	764	// (A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define fEM_A3UC02RDU	BUFFER[1870]	// (A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define idfEM_A3UC02RDU	765	// (A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define fEM_A3UC03RDU	BUFFER[1875]	// (A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define idfEM_A3UC03RDU	766	// (A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define fEM_A3UC05RDU	BUFFER[1880]	// (A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A3UC05RDU	767	// (A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define fEM_A3UC06RDU	BUFFER[1885]	// (A3UC06RDU) Уставка определения самохода ИС1  мм
#define idfEM_A3UC06RDU	768	// (A3UC06RDU) Уставка определения самохода ИС1  мм
#define fEM_A3UC07RDU	BUFFER[1890]	// (A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define idfEM_A3UC07RDU	769	// (A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define fEM_A3UC08RDU	BUFFER[1895]	// (A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define idfEM_A3UC08RDU	770	// (A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define fEM_A3UC09RDU	BUFFER[1900]	// (A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC09RDU	771	// (A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define fEM_A3UC81RDU	BUFFER[1905]	// (A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define idfEM_A3UC81RDU	772	// (A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define fEM_A3UC82RDU	BUFFER[1910]	// (A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define idfEM_A3UC82RDU	773	// (A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define fEM_A3UL01RDU	BUFFER[1915]	// (A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A3UL01RDU	774	// (A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A3UL03RDU	BUFFER[1920]	// (A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define idfEM_A3UL03RDU	775	// (A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define fEM_A3UL04RDU	BUFFER[1925]	// (A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define idfEM_A3UL04RDU	776	// (A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define fEM_A3UL05RDU	BUFFER[1930]	// (A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define idfEM_A3UL05RDU	777	// (A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define fEM_A3UP03RDU	BUFFER[1935]	// (A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	778	// (A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	BUFFER[1940]	// (A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	779	// (A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP43RDU	BUFFER[1945]	// (A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define idfEM_A3UP43RDU	780	// (A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define fEM_A3UP44RDU	BUFFER[1950]	// (A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP44RDU	781	// (A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP53RDU	BUFFER[1955]	// (A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP53RDU	782	// (A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP54RDU	BUFFER[1960]	// (A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define idfEM_A3UP54RDU	783	// (A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define fEM_A3UP85RDU	BUFFER[1965]	// (A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP85RDU	784	// (A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP86RDU	BUFFER[1970]	// (A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP86RDU	785	// (A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP87RDU	BUFFER[1975]	// (A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP87RDU	786	// (A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP88RDU	BUFFER[1980]	// (A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP88RDU	787	// (A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UR01RDU	BUFFER[1985]	// (A3UR01RDU) коэффициент реактивности от координаты ИС
#define idfEM_A3UR01RDU	788	// (A3UR01RDU) коэффициент реактивности от координаты ИС
#define fEM_A3UV01RDU	BUFFER[1990]	// (A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
#define idfEM_A3UV01RDU	789	// (A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
#define fEM_A3UV02RDU	BUFFER[1995]	// (A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
#define idfEM_A3UV02RDU	790	// (A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
#define fEM_A4UZ03RDU	BUFFER[2000]	// (A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
#define idfEM_A4UZ03RDU	791	// (A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
#define fEM_A4UZ04RDU	BUFFER[2005]	// (A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
#define idfEM_A4UZ04RDU	792	// (A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
#define fEM_A4UZ05RDU	BUFFER[2010]	// (A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
#define idfEM_A4UZ05RDU	793	// (A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
#define fEM_A5UZ03RDU	BUFFER[2015]	// (A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
#define idfEM_A5UZ03RDU	794	// (A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
#define fEM_A5UZ04RDU	BUFFER[2020]	// (A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
#define idfEM_A5UZ04RDU	795	// (A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
#define fEM_A5UZ05RDU	BUFFER[2025]	// (A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
#define idfEM_A5UZ05RDU	796	// (A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
#define fEM_A6UZ03RDU	BUFFER[2030]	// (A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
#define idfEM_A6UZ03RDU	797	// (A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
#define fEM_A6UZ04RDU	BUFFER[2035]	// (A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
#define idfEM_A6UZ04RDU	798	// (A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
#define fEM_A6UZ05RDU	BUFFER[2040]	// (A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
#define idfEM_A6UZ05RDU	799	// (A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
#define fEM_A8UC03RDU	BUFFER[2045]	// (A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
#define idfEM_A8UC03RDU	800	// (A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
#define fEM_A9UZ03RDU	BUFFER[2050]	// (A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
#define idfEM_A9UZ03RDU	801	// (A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
#define fEM_A9UZ04RDU	BUFFER[2055]	// (A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
#define idfEM_A9UZ04RDU	802	// (A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
#define fEM_A9UZ05RDU	BUFFER[2060]	// (A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
#define idfEM_A9UZ05RDU	803	// (A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
#define fEM_B8UC01RDU	BUFFER[2065]	// (B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
#define idfEM_B8UC01RDU	804	// (B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
#define fEM_B8UC02RDU	BUFFER[2070]	// (B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
#define idfEM_B8UC02RDU	805	// (B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
#define fEM_B8UC05RDU	BUFFER[2075]	// (B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
#define idfEM_B8UC05RDU	806	// (B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
#define fEM_B8UC06RDU	BUFFER[2080]	// (B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
#define idfEM_B8UC06RDU	807	// (B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
#define fEM_B8UL01RDU	BUFFER[2085]	// (B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_B8UL01RDU	808	// (B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_B8UL03RDU	BUFFER[2090]	// (B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
#define idfEM_B8UL03RDU	809	// (B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
#define fEM_B8UL04RDU	BUFFER[2095]	// (B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
#define idfEM_B8UL04RDU	810	// (B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
#define fEM_B8UL05RDU	BUFFER[2100]	// (B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
#define idfEM_B8UL05RDU	811	// (B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
#define fEM_B8UL06RDU	BUFFER[2105]	// (B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
#define idfEM_B8UL06RDU	812	// (B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
#define fEM_B8UL07RDU	BUFFER[2110]	// (B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
#define idfEM_B8UL07RDU	813	// (B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
#define fEM_B8UV01RDU	BUFFER[2115]	// (B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
#define idfEM_B8UV01RDU	814	// (B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
#define fEM_B8UV02RDU	BUFFER[2120]	// (B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
#define idfEM_B8UV02RDU	815	// (B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
#define fEM_B8UV03RDU	BUFFER[2125]	// (B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
#define idfEM_B8UV03RDU	816	// (B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
#define fEM_B8UV04RDU	BUFFER[2130]	// (B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
#define idfEM_B8UV04RDU	817	// (B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
#define fEM_R0UL00RDU	BUFFER[2135]	// (R0UL00RDU) Время ожидания передачи  сигнала отключения сети
#define idfEM_R0UL00RDU	818	// (R0UL00RDU) Время ожидания передачи  сигнала отключения сети
#define fEM_R0UL01RSS	BUFFER[2140]	// (R0UL01RSS) Шаг измерения периода (сек)
#define idfEM_R0UL01RSS	819	// (R0UL01RSS) Шаг измерения периода (сек)
#define fEM_R0UL02RDU	BUFFER[2145]	// (R0UL02RDU) Время задержки  ИНИ
#define idfEM_R0UL02RDU	820	// (R0UL02RDU) Время задержки  ИНИ
#define fEM_R0UL02RSS	BUFFER[2150]	// (R0UL02RSS) Tф-постоянная времени, с
#define idfEM_R0UL02RSS	821	// (R0UL02RSS) Tф-постоянная времени, с
#define fEM_R0UL03RDU	BUFFER[2155]	// (R0UL03RDU) Время срабатывания сброса от ВУ РБ
#define idfEM_R0UL03RDU	822	// (R0UL03RDU) Время срабатывания сброса от ВУ РБ
#define fEM_R0UL04RDU	BUFFER[2160]	// (R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
#define idfEM_R0UL04RDU	823	// (R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
#define fEM_R0UL05RDU	BUFFER[2165]	// (R0UL05RDU) Время срабатывания сброса от НУП ИС
#define idfEM_R0UL05RDU	824	// (R0UL05RDU) Время срабатывания сброса от НУП ИС
#define fEM_R0UL06RDU	BUFFER[2170]	// (R0UL06RDU) Предельное время срабатывания верхней АС II УР
#define idfEM_R0UL06RDU	825	// (R0UL06RDU) Предельное время срабатывания верхней АС II УР
#define fEM_R0UL07RDU	BUFFER[2175]	// (R0UL07RDU) Время срабатывания верхней АС II УР
#define idfEM_R0UL07RDU	826	// (R0UL07RDU) Время срабатывания верхней АС II УР
#define fEM_R0UL16RDU	BUFFER[2180]	// (R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
#define idfEM_R0UL16RDU	827	// (R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
#define fEM_R0UL17RDU	BUFFER[2185]	// (R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
#define idfEM_R0UL17RDU	828	// (R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
#define fEM_R0UL18RDU	BUFFER[2190]	// (R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
#define idfEM_R0UL18RDU	829	// (R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
#define fEM_R0UL19RDU	BUFFER[2195]	// (R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define idfEM_R0UL19RDU	830	// (R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define fEM_R0UL20RDU	BUFFER[2200]	// (R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
#define idfEM_R0UL20RDU	831	// (R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
#define fEM_R0UL21RDU	BUFFER[2205]	// (R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
#define idfEM_R0UL21RDU	832	// (R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
#define fEM_R0UL25RDU	BUFFER[2210]	// (R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define idfEM_R0UL25RDU	833	// (R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define fEM_R0UN01RDU	BUFFER[2215]	// (R0UN01RDU) 1-я заданная мощность
#define idfEM_R0UN01RDU	834	// (R0UN01RDU) 1-я заданная мощность
#define fEM_R0UN02RDU	BUFFER[2220]	// (R0UN02RDU) 2-я заданная мощность
#define idfEM_R0UN02RDU	835	// (R0UN02RDU) 2-я заданная мощность
#define fEM_R0UN03RDU	BUFFER[2225]	// (R0UN03RDU) Ограничение 3 по мощности
#define idfEM_R0UN03RDU	836	// (R0UN03RDU) Ограничение 3 по мощности
#define fEM_R0UN03RSS	BUFFER[2230]	// (R0UN03RSS) нижняя граница мощности для индикации периода  (ватт)
#define idfEM_R0UN03RSS	837	// (R0UN03RSS) нижняя граница мощности для индикации периода  (ватт)
#define fEM_R0UN04RDU	BUFFER[2235]	// (R0UN04RDU) 4-я заданная мощность
#define idfEM_R0UN04RDU	838	// (R0UN04RDU) 4-я заданная мощность
#define fEM_R0UN05RDU	BUFFER[2240]	// (R0UN05RDU) 5-я заданная мощность
#define idfEM_R0UN05RDU	839	// (R0UN05RDU) 5-я заданная мощность
#define fEM_R0UN06RDU	BUFFER[2245]	// (R0UN06RDU) 6-я заданная мощность
#define idfEM_R0UN06RDU	840	// (R0UN06RDU) 6-я заданная мощность
#define fEM_R0UN07RDU	BUFFER[2250]	// (R0UN07RDU) 7-я заданная мощность
#define idfEM_R0UN07RDU	841	// (R0UN07RDU) 7-я заданная мощность
#define fEM_R0UN08RDU	BUFFER[2255]	// (R0UN08RDU) 8-я заданная мощность
#define idfEM_R0UN08RDU	842	// (R0UN08RDU) 8-я заданная мощность
#define fEM_R0UN09RDU	BUFFER[2260]	// (R0UN09RDU) Минимальный период при регулировании мощности
#define idfEM_R0UN09RDU	843	// (R0UN09RDU) Минимальный период при регулировании мощности
#define fEM_R0UN11RDU	BUFFER[2265]	// (R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
#define idfEM_R0UN11RDU	844	// (R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
#define fEM_R0UN12RDU	BUFFER[2270]	// (R0UN12RDU) Зона нечувствительности при регулировании мощности %
#define idfEM_R0UN12RDU	845	// (R0UN12RDU) Зона нечувствительности при регулировании мощности %
#define fEM_R0UN14RDU	BUFFER[2275]	// (R0UN14RDU) Максимальная координата штока ИС, мм
#define idfEM_R0UN14RDU	846	// (R0UN14RDU) Максимальная координата штока ИС, мм
#define fEM_R0UN15RDU	BUFFER[2280]	// (R0UN15RDU) Минимальная координата штока ББ, мм
#define idfEM_R0UN15RDU	847	// (R0UN15RDU) Минимальная координата штока ББ, мм
#define fEM_R0UN16RDU	BUFFER[2285]	// (R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN16RDU	848	// (R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN17RDU	BUFFER[2290]	// (R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN17RDU	849	// (R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN18RDU	BUFFER[2295]	// (R0UN18RDU) Коэффициент температурной корректировки реактивности(долл)
#define idfEM_R0UN18RDU	850	// (R0UN18RDU) Коэффициент температурной корректировки реактивности(долл)
#define fEM_R0UN19RDU	BUFFER[2300]	// (R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define idfEM_R0UN19RDU	851	// (R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define fEM_R0UN70LDU	BUFFER[2305]	// (R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN70LDU	852	// (R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN71LDU	BUFFER[2310]	// (R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN71LDU	853	// (R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN72LDU	BUFFER[2315]	// (R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN72LDU	854	// (R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN73LDU	BUFFER[2320]	// (R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN73LDU	855	// (R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN74LDU	BUFFER[2325]	// (R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN74LDU	856	// (R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN75LDU	BUFFER[2330]	// (R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN75LDU	857	// (R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN80LDU	BUFFER[2335]	// (R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN80LDU	858	// (R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define fEM_R0UN80RDU	BUFFER[2340]	// (R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define idfEM_R0UN80RDU	859	// (R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define fEM_R0UN81LDU	BUFFER[2345]	// (R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN81LDU	860	// (R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define fEM_R0UN82LDU	BUFFER[2350]	// (R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN82LDU	861	// (R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define fEM_R0UN83LDU	BUFFER[2355]	// (R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN83LDU	862	// (R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define fEM_R0UN84LDU	BUFFER[2360]	// (R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN84LDU	863	// (R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define fEM_R0UN85LDU	BUFFER[2365]	// (R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN85LDU	864	// (R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define fEM_R0UT20RDU	BUFFER[2370]	// (R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define idfEM_R0UT20RDU	865	// (R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define fEM_R0UV81RDU	BUFFER[2375]	// (R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	866	// (R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	BUFFER[2380]	// (R0UV82RDU) 2-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	867	// (R0UV82RDU) 2-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	BUFFER[2385]	// (R0UV83RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	868	// (R0UV83RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	BUFFER[2390]	// (R0UV84RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	869	// (R0UV84RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV85RDU	BUFFER[2395]	// (R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	870	// (R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV86RDU	BUFFER[2400]	// (R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	871	// (R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV87RDU	BUFFER[2405]	// (R0UV87RDU) 8-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	872	// (R0UV87RDU) 8-я скорость перемещения ББ (шагов/секунду)
#define fEM_R1UZ03RDU	BUFFER[2410]	// (R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define idfEM_R1UZ03RDU	873	// (R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define fEM_R1UZ04RDU	BUFFER[2415]	// (R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define idfEM_R1UZ04RDU	874	// (R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define fEM_R1UZ05RDU	BUFFER[2420]	// (R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define idfEM_R1UZ05RDU	875	// (R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define fEM_R4UZ03RDU	BUFFER[2425]	// (R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define idfEM_R4UZ03RDU	876	// (R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define fEM_R4UZ04RDU	BUFFER[2430]	// (R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define idfEM_R4UZ04RDU	877	// (R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define fEM_R4UZ05RDU	BUFFER[2435]	// (R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define idfEM_R4UZ05RDU	878	// (R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define fEM_R7UI76RDU	BUFFER[2440]	// (R7UI76RDU) Время срабатывания сигнала II УР при имитации
#define idfEM_R7UI76RDU	879	// (R7UI76RDU) Время срабатывания сигнала II УР при имитации
#define iEM_A1UV01IDU	BUFFER[2445]	// (A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV01IDU	880	// (A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define iEM_A1UV02IDU	BUFFER[2448]	// (A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV02IDU	881	// (A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define iEM_A1UV03IDU	BUFFER[2451]	// (A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define idiEM_A1UV03IDU	882	// (A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define iEM_A2UV01IDU	BUFFER[2454]	// (A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV01IDU	883	// (A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define iEM_A2UV02IDU	BUFFER[2457]	// (A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV02IDU	884	// (A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define iEM_A2UV03CDU	BUFFER[2460]	// (A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define idiEM_A2UV03CDU	885	// (A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define iEM_A3UV01IDU	BUFFER[2463]	// (A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define idiEM_A3UV01IDU	886	// (A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define iEM_A3UV02IDU	BUFFER[2466]	// (A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define idiEM_A3UV02IDU	887	// (A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define internal1_m1007_BLDv0	BUFFER[2469]	// (internal1_m1007_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1007_BLDv0	888	// (internal1_m1007_BLDv0) BlDv - Блокировка движения
#define internal1_m1007_X0	BUFFER[2471]	// (internal1_m1007_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1007_X0	889	// (internal1_m1007_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1007_t0	BUFFER[2476]	// (internal1_m1007_t0) время нахождения в зоне возврата
#define idinternal1_m1007_t0	890	// (internal1_m1007_t0) время нахождения в зоне возврата
#define internal1_m1029_tx	BUFFER[2481]	// (internal1_m1029_tx) tx - время накопленное сек
#define idinternal1_m1029_tx	891	// (internal1_m1029_tx) tx - время накопленное сек
#define internal1_m1029_y0	BUFFER[2486]	// (internal1_m1029_y0) y0
#define idinternal1_m1029_y0	892	// (internal1_m1029_y0) y0
#define internal1_m1030_tx	BUFFER[2488]	// (internal1_m1030_tx) tx - время накопленное сек
#define idinternal1_m1030_tx	893	// (internal1_m1030_tx) tx - время накопленное сек
#define internal1_m1030_y0	BUFFER[2493]	// (internal1_m1030_y0) y0
#define idinternal1_m1030_y0	894	// (internal1_m1030_y0) y0
#define internal1_m1031_tx	BUFFER[2495]	// (internal1_m1031_tx) tx - внутренний параметр
#define idinternal1_m1031_tx	895	// (internal1_m1031_tx) tx - внутренний параметр
#define internal1_m1037_DelSp	BUFFER[2500]	// (internal1_m1037_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1037_DelSp	896	// (internal1_m1037_DelSp) DelSp - время переключения скоростей
#define internal1_m1037_ShCntlSp0	BUFFER[2505]	// (internal1_m1037_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1037_ShCntlSp0	897	// (internal1_m1037_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1037_Shift0	BUFFER[2507]	// (internal1_m1037_Shift0) Shift0 - признак самохода
#define idinternal1_m1037_Shift0	898	// (internal1_m1037_Shift0) Shift0 - признак самохода
#define internal1_m1037_ShiftControl	BUFFER[2509]	// (internal1_m1037_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1037_ShiftControl	899	// (internal1_m1037_ShiftControl) ShiftControl - признак самохода
#define internal1_m1037_Speed0	BUFFER[2511]	// (internal1_m1037_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1037_Speed0	900	// (internal1_m1037_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1037_StSpeed	BUFFER[2516]	// (internal1_m1037_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1037_StSpeed	901	// (internal1_m1037_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1037_Vz0	BUFFER[2521]	// (internal1_m1037_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1037_Vz0	902	// (internal1_m1037_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1037_flRazg	BUFFER[2526]	// (internal1_m1037_flRazg) признак разгона/торможения
#define idinternal1_m1037_flRazg	903	// (internal1_m1037_flRazg) признак разгона/торможения
#define internal1_m1037_sumtim	BUFFER[2529]	// (internal1_m1037_sumtim) sumtim - время в пути
#define idinternal1_m1037_sumtim	904	// (internal1_m1037_sumtim) sumtim - время в пути
#define internal1_m1037_tim0	BUFFER[2534]	// (internal1_m1037_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1037_tim0	905	// (internal1_m1037_tim0) tim0 - массив значений времени цикла
#define internal1_m1037_tx	BUFFER[2834]	// (internal1_m1037_tx) tx
#define idinternal1_m1037_tx	906	// (internal1_m1037_tx) tx
#define internal1_m1037_txBl	BUFFER[2839]	// (internal1_m1037_txBl) tx
#define idinternal1_m1037_txBl	907	// (internal1_m1037_txBl) tx
#define internal1_m1037_txMBl	BUFFER[2844]	// (internal1_m1037_txMBl) tx
#define idinternal1_m1037_txMBl	908	// (internal1_m1037_txMBl) tx
#define internal1_m1037_txZS	BUFFER[2849]	// (internal1_m1037_txZS) txZS
#define idinternal1_m1037_txZS	909	// (internal1_m1037_txZS) txZS
#define internal1_m1037_txd	BUFFER[2854]	// (internal1_m1037_txd) txd
#define idinternal1_m1037_txd	910	// (internal1_m1037_txd) txd
#define internal1_m1037_tz0	BUFFER[2859]	// (internal1_m1037_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1037_tz0	911	// (internal1_m1037_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1037_x0	BUFFER[2864]	// (internal1_m1037_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1037_x0	912	// (internal1_m1037_x0) x0 - массив мгновенных значений координат
#define internal1_m1037_xptr	BUFFER[3164]	// (internal1_m1037_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1037_xptr	913	// (internal1_m1037_xptr) указатель текущей позиции в массиве координат
#define internal1_m1037_xz0	BUFFER[3167]	// (internal1_m1037_xz0) xz0 - новое задание мм
#define idinternal1_m1037_xz0	914	// (internal1_m1037_xz0) xz0 - новое задание мм
#define internal1_m1037_z0	BUFFER[3172]	// (internal1_m1037_z0) z0 - точка прекращения движения
#define idinternal1_m1037_z0	915	// (internal1_m1037_z0) z0 - точка прекращения движения
#define internal1_m1041_tx	BUFFER[3177]	// (internal1_m1041_tx) tx - внутренний параметр
#define idinternal1_m1041_tx	916	// (internal1_m1041_tx) tx - внутренний параметр
#define internal1_m1042_tx	BUFFER[3182]	// (internal1_m1042_tx) tx - внутренний параметр
#define idinternal1_m1042_tx	917	// (internal1_m1042_tx) tx - внутренний параметр
#define internal1_m1048_tx	BUFFER[3187]	// (internal1_m1048_tx) tx - внутренний параметр
#define idinternal1_m1048_tx	918	// (internal1_m1048_tx) tx - внутренний параметр
#define internal1_m1054_tx	BUFFER[3192]	// (internal1_m1054_tx) tx - время накопленное сек
#define idinternal1_m1054_tx	919	// (internal1_m1054_tx) tx - время накопленное сек
#define internal1_m1054_y0	BUFFER[3197]	// (internal1_m1054_y0) y0
#define idinternal1_m1054_y0	920	// (internal1_m1054_y0) y0
#define internal1_m1063_tx	BUFFER[3199]	// (internal1_m1063_tx) tx - внутренний параметр
#define idinternal1_m1063_tx	921	// (internal1_m1063_tx) tx - внутренний параметр
#define internal1_m1064_tx	BUFFER[3204]	// (internal1_m1064_tx) tx - внутренний параметр
#define idinternal1_m1064_tx	922	// (internal1_m1064_tx) tx - внутренний параметр
#define internal1_m1066_tx	BUFFER[3209]	// (internal1_m1066_tx) tx - внутренний параметр
#define idinternal1_m1066_tx	923	// (internal1_m1066_tx) tx - внутренний параметр
#define internal1_m1076_tx	BUFFER[3214]	// (internal1_m1076_tx) tx - внутренний параметр
#define idinternal1_m1076_tx	924	// (internal1_m1076_tx) tx - внутренний параметр
#define internal1_m1079_tx	BUFFER[3219]	// (internal1_m1079_tx) tx - внутренний параметр
#define idinternal1_m1079_tx	925	// (internal1_m1079_tx) tx - внутренний параметр
#define internal1_m1080_tx	BUFFER[3224]	// (internal1_m1080_tx) tx - внутренний параметр
#define idinternal1_m1080_tx	926	// (internal1_m1080_tx) tx - внутренний параметр
#define internal1_m1089_tx	BUFFER[3229]	// (internal1_m1089_tx) tx - внутренний параметр
#define idinternal1_m1089_tx	927	// (internal1_m1089_tx) tx - внутренний параметр
#define internal1_m1091_tx	BUFFER[3234]	// (internal1_m1091_tx) tx - внутренний параметр
#define idinternal1_m1091_tx	928	// (internal1_m1091_tx) tx - внутренний параметр
#define internal1_m1098_tx	BUFFER[3239]	// (internal1_m1098_tx) tx - внутренний параметр
#define idinternal1_m1098_tx	929	// (internal1_m1098_tx) tx - внутренний параметр
#define internal1_m1099_tx	BUFFER[3244]	// (internal1_m1099_tx) tx - внутренний параметр
#define idinternal1_m1099_tx	930	// (internal1_m1099_tx) tx - внутренний параметр
#define internal1_m1100_tx	BUFFER[3249]	// (internal1_m1100_tx) tx - внутренний параметр
#define idinternal1_m1100_tx	931	// (internal1_m1100_tx) tx - внутренний параметр
#define internal1_m1101_tx	BUFFER[3254]	// (internal1_m1101_tx) tx - внутренний параметр
#define idinternal1_m1101_tx	932	// (internal1_m1101_tx) tx - внутренний параметр
#define internal1_m1102_tx	BUFFER[3259]	// (internal1_m1102_tx) tx - внутренний параметр
#define idinternal1_m1102_tx	933	// (internal1_m1102_tx) tx - внутренний параметр
#define internal1_m110_tx	BUFFER[3264]	// (internal1_m110_tx) tx - внутренний параметр
#define idinternal1_m110_tx	934	// (internal1_m110_tx) tx - внутренний параметр
#define internal1_m1118_q0	BUFFER[3269]	// (internal1_m1118_q0) q0 - внутренний параметр
#define idinternal1_m1118_q0	935	// (internal1_m1118_q0) q0 - внутренний параметр
#define internal1_m1126_q0	BUFFER[3271]	// (internal1_m1126_q0) q0 - внутренний параметр
#define idinternal1_m1126_q0	936	// (internal1_m1126_q0) q0 - внутренний параметр
#define internal1_m1147_q0	BUFFER[3273]	// (internal1_m1147_q0) q0 - внутренний параметр
#define idinternal1_m1147_q0	937	// (internal1_m1147_q0) q0 - внутренний параметр
#define internal1_m1150_tx	BUFFER[3275]	// (internal1_m1150_tx) tx - внутренний параметр
#define idinternal1_m1150_tx	938	// (internal1_m1150_tx) tx - внутренний параметр
#define internal1_m1151_q0	BUFFER[3280]	// (internal1_m1151_q0) q0 - внутренний параметр
#define idinternal1_m1151_q0	939	// (internal1_m1151_q0) q0 - внутренний параметр
#define internal1_m1153_q0	BUFFER[3282]	// (internal1_m1153_q0) q0 - внутренний параметр
#define idinternal1_m1153_q0	940	// (internal1_m1153_q0) q0 - внутренний параметр
#define internal1_m1154_q0	BUFFER[3284]	// (internal1_m1154_q0) q0 - внутренний параметр
#define idinternal1_m1154_q0	941	// (internal1_m1154_q0) q0 - внутренний параметр
#define internal1_m1158_q0	BUFFER[3286]	// (internal1_m1158_q0) q0 - внутренний параметр
#define idinternal1_m1158_q0	942	// (internal1_m1158_q0) q0 - внутренний параметр
#define internal1_m1169_q0	BUFFER[3288]	// (internal1_m1169_q0) q0 - внутренний параметр
#define idinternal1_m1169_q0	943	// (internal1_m1169_q0) q0 - внутренний параметр
#define internal1_m1170_q0	BUFFER[3290]	// (internal1_m1170_q0) q0 - внутренний параметр
#define idinternal1_m1170_q0	944	// (internal1_m1170_q0) q0 - внутренний параметр
#define internal1_m1182_q0	BUFFER[3292]	// (internal1_m1182_q0) q0 - внутренний параметр
#define idinternal1_m1182_q0	945	// (internal1_m1182_q0) q0 - внутренний параметр
#define internal1_m1184_q0	BUFFER[3294]	// (internal1_m1184_q0) q0 - внутренний параметр
#define idinternal1_m1184_q0	946	// (internal1_m1184_q0) q0 - внутренний параметр
#define internal1_m118_q0	BUFFER[3296]	// (internal1_m118_q0) q0 - внутренний параметр
#define idinternal1_m118_q0	947	// (internal1_m118_q0) q0 - внутренний параметр
#define internal1_m1191_q0	BUFFER[3298]	// (internal1_m1191_q0) q0 - внутренний параметр
#define idinternal1_m1191_q0	948	// (internal1_m1191_q0) q0 - внутренний параметр
#define internal1_m1199_q0	BUFFER[3300]	// (internal1_m1199_q0) q0 - внутренний параметр
#define idinternal1_m1199_q0	949	// (internal1_m1199_q0) q0 - внутренний параметр
#define internal1_m1200_q0	BUFFER[3302]	// (internal1_m1200_q0) q0 - внутренний параметр
#define idinternal1_m1200_q0	950	// (internal1_m1200_q0) q0 - внутренний параметр
#define internal1_m1202_q0	BUFFER[3304]	// (internal1_m1202_q0) q0 - внутренний параметр
#define idinternal1_m1202_q0	951	// (internal1_m1202_q0) q0 - внутренний параметр
#define internal1_m1203_q0	BUFFER[3306]	// (internal1_m1203_q0) q0 - внутренний параметр
#define idinternal1_m1203_q0	952	// (internal1_m1203_q0) q0 - внутренний параметр
#define internal1_m1205_q0	BUFFER[3308]	// (internal1_m1205_q0) q0 - внутренний параметр
#define idinternal1_m1205_q0	953	// (internal1_m1205_q0) q0 - внутренний параметр
#define internal1_m1206_q0	BUFFER[3310]	// (internal1_m1206_q0) q0 - внутренний параметр
#define idinternal1_m1206_q0	954	// (internal1_m1206_q0) q0 - внутренний параметр
#define internal1_m1208_q0	BUFFER[3312]	// (internal1_m1208_q0) q0 - внутренний параметр
#define idinternal1_m1208_q0	955	// (internal1_m1208_q0) q0 - внутренний параметр
#define internal1_m1209_q0	BUFFER[3314]	// (internal1_m1209_q0) q0 - внутренний параметр
#define idinternal1_m1209_q0	956	// (internal1_m1209_q0) q0 - внутренний параметр
#define internal1_m1211_q0	BUFFER[3316]	// (internal1_m1211_q0) q0 - внутренний параметр
#define idinternal1_m1211_q0	957	// (internal1_m1211_q0) q0 - внутренний параметр
#define internal1_m122_tx	BUFFER[3318]	// (internal1_m122_tx) tx - внутренний параметр
#define idinternal1_m122_tx	958	// (internal1_m122_tx) tx - внутренний параметр
#define internal1_m1244_tx	BUFFER[3323]	// (internal1_m1244_tx) tx - внутренний параметр
#define idinternal1_m1244_tx	959	// (internal1_m1244_tx) tx - внутренний параметр
#define internal1_m1246_tx	BUFFER[3328]	// (internal1_m1246_tx) tx - внутренний параметр
#define idinternal1_m1246_tx	960	// (internal1_m1246_tx) tx - внутренний параметр
#define internal1_m1248_tx	BUFFER[3333]	// (internal1_m1248_tx) tx - внутренний параметр
#define idinternal1_m1248_tx	961	// (internal1_m1248_tx) tx - внутренний параметр
#define internal1_m124_tx	BUFFER[3338]	// (internal1_m124_tx) tx - внутренний параметр
#define idinternal1_m124_tx	962	// (internal1_m124_tx) tx - внутренний параметр
#define internal1_m1250_tx	BUFFER[3343]	// (internal1_m1250_tx) tx - внутренний параметр
#define idinternal1_m1250_tx	963	// (internal1_m1250_tx) tx - внутренний параметр
#define internal1_m1257_tx	BUFFER[3348]	// (internal1_m1257_tx) tx - внутренний параметр
#define idinternal1_m1257_tx	964	// (internal1_m1257_tx) tx - внутренний параметр
#define internal1_m1258_tx	BUFFER[3353]	// (internal1_m1258_tx) tx - внутренний параметр
#define idinternal1_m1258_tx	965	// (internal1_m1258_tx) tx - внутренний параметр
#define internal1_m1259_tx	BUFFER[3358]	// (internal1_m1259_tx) tx - внутренний параметр
#define idinternal1_m1259_tx	966	// (internal1_m1259_tx) tx - внутренний параметр
#define internal1_m1265_tx	BUFFER[3363]	// (internal1_m1265_tx) tx - внутренний параметр
#define idinternal1_m1265_tx	967	// (internal1_m1265_tx) tx - внутренний параметр
#define internal1_m1277_BLDv0	BUFFER[3368]	// (internal1_m1277_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1277_BLDv0	968	// (internal1_m1277_BLDv0) BlDv - Блокировка движения
#define internal1_m1277_X0	BUFFER[3370]	// (internal1_m1277_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1277_X0	969	// (internal1_m1277_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1277_t0	BUFFER[3375]	// (internal1_m1277_t0) время нахождения в зоне возврата
#define idinternal1_m1277_t0	970	// (internal1_m1277_t0) время нахождения в зоне возврата
#define internal1_m1281_BlDv0	BUFFER[3380]	// (internal1_m1281_BlDv0) - была блокировка
#define idinternal1_m1281_BlDv0	971	// (internal1_m1281_BlDv0) - была блокировка
#define internal1_m1281_DvDw0	BUFFER[3382]	// (internal1_m1281_DvDw0) - есть команда на движение назад
#define idinternal1_m1281_DvDw0	972	// (internal1_m1281_DvDw0) - есть команда на движение назад
#define internal1_m1281_DvUp0	BUFFER[3384]	// (internal1_m1281_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1281_DvUp0	973	// (internal1_m1281_DvUp0) - есть команда на движение вперёд
#define internal1_m1281_FDvDw0	BUFFER[3386]	// (internal1_m1281_FDvDw0) - есть команда на движение назад
#define idinternal1_m1281_FDvDw0	974	// (internal1_m1281_FDvDw0) - есть команда на движение назад
#define internal1_m1281_FDvUp0	BUFFER[3388]	// (internal1_m1281_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1281_FDvUp0	975	// (internal1_m1281_FDvUp0) - есть команда на движение вперёд
#define internal1_m1281_Pkav0	BUFFER[3390]	// (internal1_m1281_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1281_Pkav0	976	// (internal1_m1281_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1281_Pkv0	BUFFER[3392]	// (internal1_m1281_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1281_Pkv0	977	// (internal1_m1281_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1281_Zkav0	BUFFER[3394]	// (internal1_m1281_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1281_Zkav0	978	// (internal1_m1281_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1281_Zkv0	BUFFER[3396]	// (internal1_m1281_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1281_Zkv0	979	// (internal1_m1281_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1281_fef	BUFFER[3398]	// (internal1_m1281_fef) fef
#define idinternal1_m1281_fef	980	// (internal1_m1281_fef) fef
#define internal1_m1281_txHr	BUFFER[3400]	// (internal1_m1281_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1281_txHr	981	// (internal1_m1281_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1281_txLd	BUFFER[3405]	// (internal1_m1281_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1281_txLd	982	// (internal1_m1281_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1281_txNm	BUFFER[3410]	// (internal1_m1281_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1281_txNm	983	// (internal1_m1281_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1281_txSm	BUFFER[3415]	// (internal1_m1281_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1281_txSm	984	// (internal1_m1281_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1286_tx	BUFFER[3420]	// (internal1_m1286_tx) tx - внутренний параметр
#define idinternal1_m1286_tx	985	// (internal1_m1286_tx) tx - внутренний параметр
#define internal1_m1287_tx	BUFFER[3425]	// (internal1_m1287_tx) tx - внутренний параметр
#define idinternal1_m1287_tx	986	// (internal1_m1287_tx) tx - внутренний параметр
#define internal1_m1292_tx	BUFFER[3430]	// (internal1_m1292_tx) tx - время накопленное сек
#define idinternal1_m1292_tx	987	// (internal1_m1292_tx) tx - время накопленное сек
#define internal1_m1292_y0	BUFFER[3435]	// (internal1_m1292_y0) y0
#define idinternal1_m1292_y0	988	// (internal1_m1292_y0) y0
#define internal1_m1294_tx	BUFFER[3437]	// (internal1_m1294_tx) tx - внутренний параметр
#define idinternal1_m1294_tx	989	// (internal1_m1294_tx) tx - внутренний параметр
#define internal1_m1296_tx	BUFFER[3442]	// (internal1_m1296_tx) tx - время накопленное сек
#define idinternal1_m1296_tx	990	// (internal1_m1296_tx) tx - время накопленное сек
#define internal1_m1296_y0	BUFFER[3447]	// (internal1_m1296_y0) y0
#define idinternal1_m1296_y0	991	// (internal1_m1296_y0) y0
#define internal1_m1299_tx	BUFFER[3449]	// (internal1_m1299_tx) tx - внутренний параметр
#define idinternal1_m1299_tx	992	// (internal1_m1299_tx) tx - внутренний параметр
#define internal1_m129_tx	BUFFER[3454]	// (internal1_m129_tx) tx - внутренний параметр
#define idinternal1_m129_tx	993	// (internal1_m129_tx) tx - внутренний параметр
#define internal1_m1300_tx	BUFFER[3459]	// (internal1_m1300_tx) tx - внутренний параметр
#define idinternal1_m1300_tx	994	// (internal1_m1300_tx) tx - внутренний параметр
#define internal1_m1302_DelSp	BUFFER[3464]	// (internal1_m1302_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1302_DelSp	995	// (internal1_m1302_DelSp) DelSp - время переключения скоростей
#define internal1_m1302_ShCntlSp0	BUFFER[3469]	// (internal1_m1302_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1302_ShCntlSp0	996	// (internal1_m1302_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1302_Shift0	BUFFER[3471]	// (internal1_m1302_Shift0) Shift0 - признак самохода
#define idinternal1_m1302_Shift0	997	// (internal1_m1302_Shift0) Shift0 - признак самохода
#define internal1_m1302_ShiftControl	BUFFER[3473]	// (internal1_m1302_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1302_ShiftControl	998	// (internal1_m1302_ShiftControl) ShiftControl - признак самохода
#define internal1_m1302_Speed0	BUFFER[3475]	// (internal1_m1302_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1302_Speed0	999	// (internal1_m1302_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1302_StSpeed	BUFFER[3480]	// (internal1_m1302_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1302_StSpeed	1000	// (internal1_m1302_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1302_Vz0	BUFFER[3485]	// (internal1_m1302_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1302_Vz0	1001	// (internal1_m1302_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1302_flRazg	BUFFER[3490]	// (internal1_m1302_flRazg) признак разгона/торможения
#define idinternal1_m1302_flRazg	1002	// (internal1_m1302_flRazg) признак разгона/торможения
#define internal1_m1302_sumtim	BUFFER[3493]	// (internal1_m1302_sumtim) sumtim - время в пути
#define idinternal1_m1302_sumtim	1003	// (internal1_m1302_sumtim) sumtim - время в пути
#define internal1_m1302_tim0	BUFFER[3498]	// (internal1_m1302_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1302_tim0	1004	// (internal1_m1302_tim0) tim0 - массив значений времени цикла
#define internal1_m1302_tx	BUFFER[3598]	// (internal1_m1302_tx) tx
#define idinternal1_m1302_tx	1005	// (internal1_m1302_tx) tx
#define internal1_m1302_txBl	BUFFER[3603]	// (internal1_m1302_txBl) tx
#define idinternal1_m1302_txBl	1006	// (internal1_m1302_txBl) tx
#define internal1_m1302_txMBl	BUFFER[3608]	// (internal1_m1302_txMBl) tx
#define idinternal1_m1302_txMBl	1007	// (internal1_m1302_txMBl) tx
#define internal1_m1302_txZS	BUFFER[3613]	// (internal1_m1302_txZS) txZS
#define idinternal1_m1302_txZS	1008	// (internal1_m1302_txZS) txZS
#define internal1_m1302_txd	BUFFER[3618]	// (internal1_m1302_txd) txd
#define idinternal1_m1302_txd	1009	// (internal1_m1302_txd) txd
#define internal1_m1302_tz0	BUFFER[3623]	// (internal1_m1302_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1302_tz0	1010	// (internal1_m1302_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1302_x0	BUFFER[3628]	// (internal1_m1302_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1302_x0	1011	// (internal1_m1302_x0) x0 - массив мгновенных значений координат
#define internal1_m1302_xptr	BUFFER[3728]	// (internal1_m1302_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1302_xptr	1012	// (internal1_m1302_xptr) указатель текущей позиции в массиве координат
#define internal1_m1302_xz0	BUFFER[3731]	// (internal1_m1302_xz0) xz0 - новое задание мм
#define idinternal1_m1302_xz0	1013	// (internal1_m1302_xz0) xz0 - новое задание мм
#define internal1_m1302_z0	BUFFER[3736]	// (internal1_m1302_z0) z0 - точка прекращения движения
#define idinternal1_m1302_z0	1014	// (internal1_m1302_z0) z0 - точка прекращения движения
#define internal1_m1305_tx	BUFFER[3741]	// (internal1_m1305_tx) tx - внутренний параметр
#define idinternal1_m1305_tx	1015	// (internal1_m1305_tx) tx - внутренний параметр
#define internal1_m1307_tx	BUFFER[3746]	// (internal1_m1307_tx) tx - время накопленное сек
#define idinternal1_m1307_tx	1016	// (internal1_m1307_tx) tx - время накопленное сек
#define internal1_m1307_y0	BUFFER[3751]	// (internal1_m1307_y0) y0
#define idinternal1_m1307_y0	1017	// (internal1_m1307_y0) y0
#define internal1_m1328_tx	BUFFER[3753]	// (internal1_m1328_tx) tx - внутренний параметр
#define idinternal1_m1328_tx	1018	// (internal1_m1328_tx) tx - внутренний параметр
#define internal1_m1329_tx	BUFFER[3758]	// (internal1_m1329_tx) tx - внутренний параметр
#define idinternal1_m1329_tx	1019	// (internal1_m1329_tx) tx - внутренний параметр
#define internal1_m1332_tx	BUFFER[3763]	// (internal1_m1332_tx) tx - внутренний параметр
#define idinternal1_m1332_tx	1020	// (internal1_m1332_tx) tx - внутренний параметр
#define internal1_m1335_BlDv0	BUFFER[3768]	// (internal1_m1335_BlDv0) - была блокировка
#define idinternal1_m1335_BlDv0	1021	// (internal1_m1335_BlDv0) - была блокировка
#define internal1_m1335_DvDw0	BUFFER[3770]	// (internal1_m1335_DvDw0) - есть команда на движение назад
#define idinternal1_m1335_DvDw0	1022	// (internal1_m1335_DvDw0) - есть команда на движение назад
#define internal1_m1335_DvUp0	BUFFER[3772]	// (internal1_m1335_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1335_DvUp0	1023	// (internal1_m1335_DvUp0) - есть команда на движение вперёд
#define internal1_m1335_FDvDw0	BUFFER[3774]	// (internal1_m1335_FDvDw0) - есть команда на движение назад
#define idinternal1_m1335_FDvDw0	1024	// (internal1_m1335_FDvDw0) - есть команда на движение назад
#define internal1_m1335_FDvUp0	BUFFER[3776]	// (internal1_m1335_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1335_FDvUp0	1025	// (internal1_m1335_FDvUp0) - есть команда на движение вперёд
#define internal1_m1335_Pkav0	BUFFER[3778]	// (internal1_m1335_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1335_Pkav0	1026	// (internal1_m1335_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1335_Pkv0	BUFFER[3780]	// (internal1_m1335_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1335_Pkv0	1027	// (internal1_m1335_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1335_Zkav0	BUFFER[3782]	// (internal1_m1335_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1335_Zkav0	1028	// (internal1_m1335_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1335_Zkv0	BUFFER[3784]	// (internal1_m1335_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1335_Zkv0	1029	// (internal1_m1335_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1335_fef	BUFFER[3786]	// (internal1_m1335_fef) fef
#define idinternal1_m1335_fef	1030	// (internal1_m1335_fef) fef
#define internal1_m1335_txHr	BUFFER[3788]	// (internal1_m1335_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1335_txHr	1031	// (internal1_m1335_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1335_txLd	BUFFER[3793]	// (internal1_m1335_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1335_txLd	1032	// (internal1_m1335_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1335_txNm	BUFFER[3798]	// (internal1_m1335_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1335_txNm	1033	// (internal1_m1335_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1335_txSm	BUFFER[3803]	// (internal1_m1335_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1335_txSm	1034	// (internal1_m1335_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1343_tx	BUFFER[3808]	// (internal1_m1343_tx) tx - внутренний параметр
#define idinternal1_m1343_tx	1035	// (internal1_m1343_tx) tx - внутренний параметр
#define internal1_m1345_BlDv0	BUFFER[3813]	// (internal1_m1345_BlDv0) - была блокировка
#define idinternal1_m1345_BlDv0	1036	// (internal1_m1345_BlDv0) - была блокировка
#define internal1_m1345_DvDw0	BUFFER[3815]	// (internal1_m1345_DvDw0) - есть команда на движение назад
#define idinternal1_m1345_DvDw0	1037	// (internal1_m1345_DvDw0) - есть команда на движение назад
#define internal1_m1345_DvUp0	BUFFER[3817]	// (internal1_m1345_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1345_DvUp0	1038	// (internal1_m1345_DvUp0) - есть команда на движение вперёд
#define internal1_m1345_FDvDw0	BUFFER[3819]	// (internal1_m1345_FDvDw0) - есть команда на движение назад
#define idinternal1_m1345_FDvDw0	1039	// (internal1_m1345_FDvDw0) - есть команда на движение назад
#define internal1_m1345_FDvUp0	BUFFER[3821]	// (internal1_m1345_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1345_FDvUp0	1040	// (internal1_m1345_FDvUp0) - есть команда на движение вперёд
#define internal1_m1345_Pkav0	BUFFER[3823]	// (internal1_m1345_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1345_Pkav0	1041	// (internal1_m1345_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1345_Pkv0	BUFFER[3825]	// (internal1_m1345_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1345_Pkv0	1042	// (internal1_m1345_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1345_Zkav0	BUFFER[3827]	// (internal1_m1345_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1345_Zkav0	1043	// (internal1_m1345_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1345_Zkv0	BUFFER[3829]	// (internal1_m1345_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1345_Zkv0	1044	// (internal1_m1345_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1345_fef	BUFFER[3831]	// (internal1_m1345_fef) fef
#define idinternal1_m1345_fef	1045	// (internal1_m1345_fef) fef
#define internal1_m1345_txHr	BUFFER[3833]	// (internal1_m1345_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1345_txHr	1046	// (internal1_m1345_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1345_txLd	BUFFER[3838]	// (internal1_m1345_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1345_txLd	1047	// (internal1_m1345_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1345_txNm	BUFFER[3843]	// (internal1_m1345_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1345_txNm	1048	// (internal1_m1345_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1345_txSm	BUFFER[3848]	// (internal1_m1345_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1345_txSm	1049	// (internal1_m1345_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1349_tx	BUFFER[3853]	// (internal1_m1349_tx) tx - внутренний параметр
#define idinternal1_m1349_tx	1050	// (internal1_m1349_tx) tx - внутренний параметр
#define internal1_m1350_tx	BUFFER[3858]	// (internal1_m1350_tx) tx - внутренний параметр
#define idinternal1_m1350_tx	1051	// (internal1_m1350_tx) tx - внутренний параметр
#define internal1_m1351_tx	BUFFER[3863]	// (internal1_m1351_tx) tx - внутренний параметр
#define idinternal1_m1351_tx	1052	// (internal1_m1351_tx) tx - внутренний параметр
#define internal1_m1372_BLDv0	BUFFER[3868]	// (internal1_m1372_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1372_BLDv0	1053	// (internal1_m1372_BLDv0) BlDv - Блокировка движения
#define internal1_m1372_X0	BUFFER[3870]	// (internal1_m1372_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1372_X0	1054	// (internal1_m1372_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1372_t0	BUFFER[3875]	// (internal1_m1372_t0) время нахождения в зоне возврата
#define idinternal1_m1372_t0	1055	// (internal1_m1372_t0) время нахождения в зоне возврата
#define internal1_m1392_tx	BUFFER[3880]	// (internal1_m1392_tx) tx - внутренний параметр
#define idinternal1_m1392_tx	1056	// (internal1_m1392_tx) tx - внутренний параметр
#define internal1_m1395_tx	BUFFER[3885]	// (internal1_m1395_tx) tx - внутренний параметр
#define idinternal1_m1395_tx	1057	// (internal1_m1395_tx) tx - внутренний параметр
#define internal1_m1399_tx	BUFFER[3890]	// (internal1_m1399_tx) tx - время накопленное сек
#define idinternal1_m1399_tx	1058	// (internal1_m1399_tx) tx - время накопленное сек
#define internal1_m1399_y0	BUFFER[3895]	// (internal1_m1399_y0) y0
#define idinternal1_m1399_y0	1059	// (internal1_m1399_y0) y0
#define internal1_m13_tx	BUFFER[3897]	// (internal1_m13_tx) tx - внутренний параметр
#define idinternal1_m13_tx	1060	// (internal1_m13_tx) tx - внутренний параметр
#define internal1_m1400_tx	BUFFER[3902]	// (internal1_m1400_tx) tx - время накопленное сек
#define idinternal1_m1400_tx	1061	// (internal1_m1400_tx) tx - время накопленное сек
#define internal1_m1400_y0	BUFFER[3907]	// (internal1_m1400_y0) y0
#define idinternal1_m1400_y0	1062	// (internal1_m1400_y0) y0
#define internal1_m1407_DelSp	BUFFER[3909]	// (internal1_m1407_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1407_DelSp	1063	// (internal1_m1407_DelSp) DelSp - время переключения скоростей
#define internal1_m1407_ShCntlSp0	BUFFER[3914]	// (internal1_m1407_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1407_ShCntlSp0	1064	// (internal1_m1407_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1407_Shift0	BUFFER[3916]	// (internal1_m1407_Shift0) Shift0 - признак самохода
#define idinternal1_m1407_Shift0	1065	// (internal1_m1407_Shift0) Shift0 - признак самохода
#define internal1_m1407_ShiftControl	BUFFER[3918]	// (internal1_m1407_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1407_ShiftControl	1066	// (internal1_m1407_ShiftControl) ShiftControl - признак самохода
#define internal1_m1407_Speed0	BUFFER[3920]	// (internal1_m1407_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1407_Speed0	1067	// (internal1_m1407_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1407_StSpeed	BUFFER[3925]	// (internal1_m1407_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1407_StSpeed	1068	// (internal1_m1407_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1407_Vz0	BUFFER[3930]	// (internal1_m1407_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1407_Vz0	1069	// (internal1_m1407_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1407_flRazg	BUFFER[3935]	// (internal1_m1407_flRazg) признак разгона/торможения
#define idinternal1_m1407_flRazg	1070	// (internal1_m1407_flRazg) признак разгона/торможения
#define internal1_m1407_sumtim	BUFFER[3938]	// (internal1_m1407_sumtim) sumtim - время в пути
#define idinternal1_m1407_sumtim	1071	// (internal1_m1407_sumtim) sumtim - время в пути
#define internal1_m1407_tim0	BUFFER[3943]	// (internal1_m1407_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1407_tim0	1072	// (internal1_m1407_tim0) tim0 - массив значений времени цикла
#define internal1_m1407_tx	BUFFER[4343]	// (internal1_m1407_tx) tx
#define idinternal1_m1407_tx	1073	// (internal1_m1407_tx) tx
#define internal1_m1407_txBl	BUFFER[4348]	// (internal1_m1407_txBl) tx
#define idinternal1_m1407_txBl	1074	// (internal1_m1407_txBl) tx
#define internal1_m1407_txMBl	BUFFER[4353]	// (internal1_m1407_txMBl) tx
#define idinternal1_m1407_txMBl	1075	// (internal1_m1407_txMBl) tx
#define internal1_m1407_txZS	BUFFER[4358]	// (internal1_m1407_txZS) txZS
#define idinternal1_m1407_txZS	1076	// (internal1_m1407_txZS) txZS
#define internal1_m1407_txd	BUFFER[4363]	// (internal1_m1407_txd) txd
#define idinternal1_m1407_txd	1077	// (internal1_m1407_txd) txd
#define internal1_m1407_tz0	BUFFER[4368]	// (internal1_m1407_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1407_tz0	1078	// (internal1_m1407_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1407_x0	BUFFER[4373]	// (internal1_m1407_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1407_x0	1079	// (internal1_m1407_x0) x0 - массив мгновенных значений координат
#define internal1_m1407_xptr	BUFFER[4773]	// (internal1_m1407_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1407_xptr	1080	// (internal1_m1407_xptr) указатель текущей позиции в массиве координат
#define internal1_m1407_xz0	BUFFER[4776]	// (internal1_m1407_xz0) xz0 - новое задание мм
#define idinternal1_m1407_xz0	1081	// (internal1_m1407_xz0) xz0 - новое задание мм
#define internal1_m1407_z0	BUFFER[4781]	// (internal1_m1407_z0) z0 - точка прекращения движения
#define idinternal1_m1407_z0	1082	// (internal1_m1407_z0) z0 - точка прекращения движения
#define internal1_m1410_tx	BUFFER[4786]	// (internal1_m1410_tx) tx - внутренний параметр
#define idinternal1_m1410_tx	1083	// (internal1_m1410_tx) tx - внутренний параметр
#define internal1_m1413_tx	BUFFER[4791]	// (internal1_m1413_tx) tx - внутренний параметр
#define idinternal1_m1413_tx	1084	// (internal1_m1413_tx) tx - внутренний параметр
#define internal1_m1417_tx	BUFFER[4796]	// (internal1_m1417_tx) tx - время накопленное сек
#define idinternal1_m1417_tx	1085	// (internal1_m1417_tx) tx - время накопленное сек
#define internal1_m1417_y0	BUFFER[4801]	// (internal1_m1417_y0) y0
#define idinternal1_m1417_y0	1086	// (internal1_m1417_y0) y0
#define internal1_m1428_tx	BUFFER[4803]	// (internal1_m1428_tx) tx - внутренний параметр
#define idinternal1_m1428_tx	1087	// (internal1_m1428_tx) tx - внутренний параметр
#define internal1_m1430_tx	BUFFER[4808]	// (internal1_m1430_tx) tx - внутренний параметр
#define idinternal1_m1430_tx	1088	// (internal1_m1430_tx) tx - внутренний параметр
#define internal1_m1432_tx	BUFFER[4813]	// (internal1_m1432_tx) tx - внутренний параметр
#define idinternal1_m1432_tx	1089	// (internal1_m1432_tx) tx - внутренний параметр
#define internal1_m1443_tx	BUFFER[4818]	// (internal1_m1443_tx) tx - внутренний параметр
#define idinternal1_m1443_tx	1090	// (internal1_m1443_tx) tx - внутренний параметр
#define internal1_m1447_tx	BUFFER[4823]	// (internal1_m1447_tx) tx - внутренний параметр
#define idinternal1_m1447_tx	1091	// (internal1_m1447_tx) tx - внутренний параметр
#define internal1_m1448_tx	BUFFER[4828]	// (internal1_m1448_tx) tx - внутренний параметр
#define idinternal1_m1448_tx	1092	// (internal1_m1448_tx) tx - внутренний параметр
#define internal1_m1457_tx	BUFFER[4833]	// (internal1_m1457_tx) tx - внутренний параметр
#define idinternal1_m1457_tx	1093	// (internal1_m1457_tx) tx - внутренний параметр
#define internal1_m1458_tx	BUFFER[4838]	// (internal1_m1458_tx) tx - внутренний параметр
#define idinternal1_m1458_tx	1094	// (internal1_m1458_tx) tx - внутренний параметр
#define internal1_m1464_tx	BUFFER[4843]	// (internal1_m1464_tx) tx - внутренний параметр
#define idinternal1_m1464_tx	1095	// (internal1_m1464_tx) tx - внутренний параметр
#define internal1_m1465_tx	BUFFER[4848]	// (internal1_m1465_tx) tx - внутренний параметр
#define idinternal1_m1465_tx	1096	// (internal1_m1465_tx) tx - внутренний параметр
#define internal1_m1466_tx	BUFFER[4853]	// (internal1_m1466_tx) tx - внутренний параметр
#define idinternal1_m1466_tx	1097	// (internal1_m1466_tx) tx - внутренний параметр
#define internal1_m1467_tx	BUFFER[4858]	// (internal1_m1467_tx) tx - внутренний параметр
#define idinternal1_m1467_tx	1098	// (internal1_m1467_tx) tx - внутренний параметр
#define internal1_m1485_BLDv0	BUFFER[4863]	// (internal1_m1485_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1485_BLDv0	1099	// (internal1_m1485_BLDv0) BlDv - Блокировка движения
#define internal1_m1485_X0	BUFFER[4865]	// (internal1_m1485_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1485_X0	1100	// (internal1_m1485_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1485_t0	BUFFER[4870]	// (internal1_m1485_t0) время нахождения в зоне возврата
#define idinternal1_m1485_t0	1101	// (internal1_m1485_t0) время нахождения в зоне возврата
#define internal1_m1502_tx	BUFFER[4875]	// (internal1_m1502_tx) tx - время накопленное сек
#define idinternal1_m1502_tx	1102	// (internal1_m1502_tx) tx - время накопленное сек
#define internal1_m1502_y0	BUFFER[4880]	// (internal1_m1502_y0) y0
#define idinternal1_m1502_y0	1103	// (internal1_m1502_y0) y0
#define internal1_m1503_tx	BUFFER[4882]	// (internal1_m1503_tx) tx - время накопленное сек
#define idinternal1_m1503_tx	1104	// (internal1_m1503_tx) tx - время накопленное сек
#define internal1_m1503_y0	BUFFER[4887]	// (internal1_m1503_y0) y0
#define idinternal1_m1503_y0	1105	// (internal1_m1503_y0) y0
#define internal1_m1508_tx	BUFFER[4889]	// (internal1_m1508_tx) tx - внутренний параметр
#define idinternal1_m1508_tx	1106	// (internal1_m1508_tx) tx - внутренний параметр
#define internal1_m1509_tx	BUFFER[4894]	// (internal1_m1509_tx) tx - внутренний параметр
#define idinternal1_m1509_tx	1107	// (internal1_m1509_tx) tx - внутренний параметр
#define internal1_m1511_DelSp	BUFFER[4899]	// (internal1_m1511_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1511_DelSp	1108	// (internal1_m1511_DelSp) DelSp - время переключения скоростей
#define internal1_m1511_ShCntlSp0	BUFFER[4904]	// (internal1_m1511_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1511_ShCntlSp0	1109	// (internal1_m1511_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1511_Shift0	BUFFER[4906]	// (internal1_m1511_Shift0) Shift0 - признак самохода
#define idinternal1_m1511_Shift0	1110	// (internal1_m1511_Shift0) Shift0 - признак самохода
#define internal1_m1511_ShiftControl	BUFFER[4908]	// (internal1_m1511_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1511_ShiftControl	1111	// (internal1_m1511_ShiftControl) ShiftControl - признак самохода
#define internal1_m1511_Speed0	BUFFER[4910]	// (internal1_m1511_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1511_Speed0	1112	// (internal1_m1511_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1511_StSpeed	BUFFER[4915]	// (internal1_m1511_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1511_StSpeed	1113	// (internal1_m1511_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1511_Vz0	BUFFER[4920]	// (internal1_m1511_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1511_Vz0	1114	// (internal1_m1511_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1511_flRazg	BUFFER[4925]	// (internal1_m1511_flRazg) признак разгона/торможения
#define idinternal1_m1511_flRazg	1115	// (internal1_m1511_flRazg) признак разгона/торможения
#define internal1_m1511_sumtim	BUFFER[4928]	// (internal1_m1511_sumtim) sumtim - время в пути
#define idinternal1_m1511_sumtim	1116	// (internal1_m1511_sumtim) sumtim - время в пути
#define internal1_m1511_tim0	BUFFER[4933]	// (internal1_m1511_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1511_tim0	1117	// (internal1_m1511_tim0) tim0 - массив значений времени цикла
#define internal1_m1511_tx	BUFFER[5233]	// (internal1_m1511_tx) tx
#define idinternal1_m1511_tx	1118	// (internal1_m1511_tx) tx
#define internal1_m1511_txBl	BUFFER[5238]	// (internal1_m1511_txBl) tx
#define idinternal1_m1511_txBl	1119	// (internal1_m1511_txBl) tx
#define internal1_m1511_txMBl	BUFFER[5243]	// (internal1_m1511_txMBl) tx
#define idinternal1_m1511_txMBl	1120	// (internal1_m1511_txMBl) tx
#define internal1_m1511_txZS	BUFFER[5248]	// (internal1_m1511_txZS) txZS
#define idinternal1_m1511_txZS	1121	// (internal1_m1511_txZS) txZS
#define internal1_m1511_txd	BUFFER[5253]	// (internal1_m1511_txd) txd
#define idinternal1_m1511_txd	1122	// (internal1_m1511_txd) txd
#define internal1_m1511_tz0	BUFFER[5258]	// (internal1_m1511_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1511_tz0	1123	// (internal1_m1511_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1511_x0	BUFFER[5263]	// (internal1_m1511_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1511_x0	1124	// (internal1_m1511_x0) x0 - массив мгновенных значений координат
#define internal1_m1511_xptr	BUFFER[5563]	// (internal1_m1511_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1511_xptr	1125	// (internal1_m1511_xptr) указатель текущей позиции в массиве координат
#define internal1_m1511_xz0	BUFFER[5566]	// (internal1_m1511_xz0) xz0 - новое задание мм
#define idinternal1_m1511_xz0	1126	// (internal1_m1511_xz0) xz0 - новое задание мм
#define internal1_m1511_z0	BUFFER[5571]	// (internal1_m1511_z0) z0 - точка прекращения движения
#define idinternal1_m1511_z0	1127	// (internal1_m1511_z0) z0 - точка прекращения движения
#define internal1_m1518_tx	BUFFER[5576]	// (internal1_m1518_tx) tx - внутренний параметр
#define idinternal1_m1518_tx	1128	// (internal1_m1518_tx) tx - внутренний параметр
#define internal1_m1521_tx	BUFFER[5581]	// (internal1_m1521_tx) tx - внутренний параметр
#define idinternal1_m1521_tx	1129	// (internal1_m1521_tx) tx - внутренний параметр
#define internal1_m1527_tx	BUFFER[5586]	// (internal1_m1527_tx) tx - время накопленное сек
#define idinternal1_m1527_tx	1130	// (internal1_m1527_tx) tx - время накопленное сек
#define internal1_m1527_y0	BUFFER[5591]	// (internal1_m1527_y0) y0
#define idinternal1_m1527_y0	1131	// (internal1_m1527_y0) y0
#define internal1_m1536_tx	BUFFER[5593]	// (internal1_m1536_tx) tx - внутренний параметр
#define idinternal1_m1536_tx	1132	// (internal1_m1536_tx) tx - внутренний параметр
#define internal1_m1537_tx	BUFFER[5598]	// (internal1_m1537_tx) tx - внутренний параметр
#define idinternal1_m1537_tx	1133	// (internal1_m1537_tx) tx - внутренний параметр
#define internal1_m1539_tx	BUFFER[5603]	// (internal1_m1539_tx) tx - внутренний параметр
#define idinternal1_m1539_tx	1134	// (internal1_m1539_tx) tx - внутренний параметр
#define internal1_m1549_tx	BUFFER[5608]	// (internal1_m1549_tx) tx - внутренний параметр
#define idinternal1_m1549_tx	1135	// (internal1_m1549_tx) tx - внутренний параметр
#define internal1_m1551_tx	BUFFER[5613]	// (internal1_m1551_tx) tx - внутренний параметр
#define idinternal1_m1551_tx	1136	// (internal1_m1551_tx) tx - внутренний параметр
#define internal1_m1552_tx	BUFFER[5618]	// (internal1_m1552_tx) tx - внутренний параметр
#define idinternal1_m1552_tx	1137	// (internal1_m1552_tx) tx - внутренний параметр
#define internal1_m1562_tx	BUFFER[5623]	// (internal1_m1562_tx) tx - внутренний параметр
#define idinternal1_m1562_tx	1138	// (internal1_m1562_tx) tx - внутренний параметр
#define internal1_m1564_tx	BUFFER[5628]	// (internal1_m1564_tx) tx - внутренний параметр
#define idinternal1_m1564_tx	1139	// (internal1_m1564_tx) tx - внутренний параметр
#define internal1_m1571_tx	BUFFER[5633]	// (internal1_m1571_tx) tx - внутренний параметр
#define idinternal1_m1571_tx	1140	// (internal1_m1571_tx) tx - внутренний параметр
#define internal1_m1572_tx	BUFFER[5638]	// (internal1_m1572_tx) tx - внутренний параметр
#define idinternal1_m1572_tx	1141	// (internal1_m1572_tx) tx - внутренний параметр
#define internal1_m1573_tx	BUFFER[5643]	// (internal1_m1573_tx) tx - внутренний параметр
#define idinternal1_m1573_tx	1142	// (internal1_m1573_tx) tx - внутренний параметр
#define internal1_m1574_tx	BUFFER[5648]	// (internal1_m1574_tx) tx - внутренний параметр
#define idinternal1_m1574_tx	1143	// (internal1_m1574_tx) tx - внутренний параметр
#define internal1_m1575_tx	BUFFER[5653]	// (internal1_m1575_tx) tx - внутренний параметр
#define idinternal1_m1575_tx	1144	// (internal1_m1575_tx) tx - внутренний параметр
#define internal1_m1601_q0	BUFFER[5658]	// (internal1_m1601_q0) q0 - внутренний параметр
#define idinternal1_m1601_q0	1145	// (internal1_m1601_q0) q0 - внутренний параметр
#define internal1_m1602_ErrPr0	BUFFER[5660]	// (internal1_m1602_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m1602_ErrPr0	1146	// (internal1_m1602_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m1602_FinPr0	BUFFER[5662]	// (internal1_m1602_FinPr0) FinPr - конец программы
#define idinternal1_m1602_FinPr0	1147	// (internal1_m1602_FinPr0) FinPr - конец программы
#define internal1_m1602_MyFirstEnterFlag	BUFFER[5664]	// (internal1_m1602_MyFirstEnterFlag)  
#define idinternal1_m1602_MyFirstEnterFlag	1148	// (internal1_m1602_MyFirstEnterFlag)  
#define internal1_m1602_Step	BUFFER[5666]	// (internal1_m1602_Step)  - текущий шаг программы
#define idinternal1_m1602_Step	1149	// (internal1_m1602_Step)  - текущий шаг программы
#define internal1_m1602_TimS	BUFFER[5669]	// (internal1_m1602_TimS) Время от старта программы
#define idinternal1_m1602_TimS	1150	// (internal1_m1602_TimS) Время от старта программы
#define internal1_m1602_rz	BUFFER[5674]	// (internal1_m1602_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m1602_rz	1151	// (internal1_m1602_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m1602_sb2UR0	BUFFER[5686]	// (internal1_m1602_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m1602_sb2UR0	1152	// (internal1_m1602_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m1602_sbINI0	BUFFER[5688]	// (internal1_m1602_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m1602_sbINI0	1153	// (internal1_m1602_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m1602_sbNupIS0	BUFFER[5690]	// (internal1_m1602_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m1602_sbNupIS0	1154	// (internal1_m1602_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m1602_sbVuIS0	BUFFER[5692]	// (internal1_m1602_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m1602_sbVuIS0	1155	// (internal1_m1602_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m1602_sbVuRB0	BUFFER[5694]	// (internal1_m1602_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m1602_sbVuRB0	1156	// (internal1_m1602_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m1604_q0	BUFFER[5696]	// (internal1_m1604_q0) q0 - внутренний параметр
#define idinternal1_m1604_q0	1157	// (internal1_m1604_q0) q0 - внутренний параметр
#define internal1_m1619_x0	BUFFER[5701]	// (internal1_m1619_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1619_x0	1158	// (internal1_m1619_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1629_tx	BUFFER[5706]	// (internal1_m1629_tx) tx - внутренний параметр
#define idinternal1_m1629_tx	1159	// (internal1_m1629_tx) tx - внутренний параметр
#define internal1_m1638_q0	BUFFER[5711]	// (internal1_m1638_q0) q0 - внутренний параметр
#define idinternal1_m1638_q0	1160	// (internal1_m1638_q0) q0 - внутренний параметр
#define internal1_m1639_tim	BUFFER[5713]	// (internal1_m1639_tim) - время задержки выходного сигнала
#define idinternal1_m1639_tim	1161	// (internal1_m1639_tim) - время задержки выходного сигнала
#define internal1_m1639_x0	BUFFER[5718]	// (internal1_m1639_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m1639_x0	1162	// (internal1_m1639_x0) - значение входного параметра на предыдущем шаге
#define internal1_m1645_tx	BUFFER[5720]	// (internal1_m1645_tx) tx - время накопленное сек
#define idinternal1_m1645_tx	1163	// (internal1_m1645_tx) tx - время накопленное сек
#define internal1_m1645_y0	BUFFER[5725]	// (internal1_m1645_y0) y0
#define idinternal1_m1645_y0	1164	// (internal1_m1645_y0) y0
#define internal1_m1648_q0	BUFFER[5727]	// (internal1_m1648_q0) q0 - внутренний параметр
#define idinternal1_m1648_q0	1165	// (internal1_m1648_q0) q0 - внутренний параметр
#define internal1_m1650_q0	BUFFER[5729]	// (internal1_m1650_q0) q0 - внутренний параметр
#define idinternal1_m1650_q0	1166	// (internal1_m1650_q0) q0 - внутренний параметр
#define internal1_m1653_fef	BUFFER[5734]	// (internal1_m1653_fef) FirstEnterFlag
#define idinternal1_m1653_fef	1167	// (internal1_m1653_fef) FirstEnterFlag
#define internal1_m1653_x0	BUFFER[5736]	// (internal1_m1653_x0) был приход сигнала x1
#define idinternal1_m1653_x0	1168	// (internal1_m1653_x0) был приход сигнала x1
#define internal1_m1653_y0	BUFFER[5738]	// (internal1_m1653_y0) интервал между сигналами х1 и х2
#define idinternal1_m1653_y0	1169	// (internal1_m1653_y0) интервал между сигналами х1 и х2
#define internal1_m1666_q0	BUFFER[5743]	// (internal1_m1666_q0) q0 - внутренний параметр
#define idinternal1_m1666_q0	1170	// (internal1_m1666_q0) q0 - внутренний параметр
#define internal1_m1679_tx	BUFFER[5745]	// (internal1_m1679_tx) tx - время накопленное сек
#define idinternal1_m1679_tx	1171	// (internal1_m1679_tx) tx - время накопленное сек
#define internal1_m1679_y0	BUFFER[5750]	// (internal1_m1679_y0) y0
#define idinternal1_m1679_y0	1172	// (internal1_m1679_y0) y0
#define internal1_m1681_q0	BUFFER[5752]	// (internal1_m1681_q0) q0 - внутренний параметр
#define idinternal1_m1681_q0	1173	// (internal1_m1681_q0) q0 - внутренний параметр
#define internal1_m1686_q0	BUFFER[5754]	// (internal1_m1686_q0) q0 - внутренний параметр
#define idinternal1_m1686_q0	1174	// (internal1_m1686_q0) q0 - внутренний параметр
#define internal1_m1687_tim	BUFFER[5756]	// (internal1_m1687_tim) - время задержки выходного сигнала
#define idinternal1_m1687_tim	1175	// (internal1_m1687_tim) - время задержки выходного сигнала
#define internal1_m1687_x0	BUFFER[5761]	// (internal1_m1687_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m1687_x0	1176	// (internal1_m1687_x0) - значение входного параметра на предыдущем шаге
#define internal1_m1690_q0	BUFFER[5763]	// (internal1_m1690_q0) q0 - внутренний параметр
#define idinternal1_m1690_q0	1177	// (internal1_m1690_q0) q0 - внутренний параметр
#define internal1_m1692_tim	BUFFER[5768]	// (internal1_m1692_tim) - время задержки выходного сигнала
#define idinternal1_m1692_tim	1178	// (internal1_m1692_tim) - время задержки выходного сигнала
#define internal1_m1692_x0	BUFFER[5773]	// (internal1_m1692_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m1692_x0	1179	// (internal1_m1692_x0) - значение входного параметра на предыдущем шаге
#define internal1_m1693_q0	BUFFER[5775]	// (internal1_m1693_q0) q0 - внутренний параметр
#define idinternal1_m1693_q0	1180	// (internal1_m1693_q0) q0 - внутренний параметр
#define internal1_m1698_tx	BUFFER[5780]	// (internal1_m1698_tx) tx - время накопленное сек
#define idinternal1_m1698_tx	1181	// (internal1_m1698_tx) tx - время накопленное сек
#define internal1_m1698_y0	BUFFER[5785]	// (internal1_m1698_y0) y0
#define idinternal1_m1698_y0	1182	// (internal1_m1698_y0) y0
#define internal1_m1701_q0	BUFFER[5787]	// (internal1_m1701_q0) q0 - внутренний параметр
#define idinternal1_m1701_q0	1183	// (internal1_m1701_q0) q0 - внутренний параметр
#define internal1_m1702_fef	BUFFER[5789]	// (internal1_m1702_fef) FirstEnterFlag
#define idinternal1_m1702_fef	1184	// (internal1_m1702_fef) FirstEnterFlag
#define internal1_m1702_x0	BUFFER[5791]	// (internal1_m1702_x0) был приход сигнала x1
#define idinternal1_m1702_x0	1185	// (internal1_m1702_x0) был приход сигнала x1
#define internal1_m1702_y0	BUFFER[5793]	// (internal1_m1702_y0) интервал между сигналами х1 и х2
#define idinternal1_m1702_y0	1186	// (internal1_m1702_y0) интервал между сигналами х1 и х2
#define internal1_m1704_tx	BUFFER[5798]	// (internal1_m1704_tx) tx - время накопленное сек
#define idinternal1_m1704_tx	1187	// (internal1_m1704_tx) tx - время накопленное сек
#define internal1_m1704_y0	BUFFER[5803]	// (internal1_m1704_y0) y0
#define idinternal1_m1704_y0	1188	// (internal1_m1704_y0) y0
#define internal1_m1707_fef	BUFFER[5805]	// (internal1_m1707_fef) FirstEnterFlag
#define idinternal1_m1707_fef	1189	// (internal1_m1707_fef) FirstEnterFlag
#define internal1_m1707_x0	BUFFER[5807]	// (internal1_m1707_x0) был приход сигнала x1
#define idinternal1_m1707_x0	1190	// (internal1_m1707_x0) был приход сигнала x1
#define internal1_m1707_y0	BUFFER[5809]	// (internal1_m1707_y0) интервал между сигналами х1 и х2
#define idinternal1_m1707_y0	1191	// (internal1_m1707_y0) интервал между сигналами х1 и х2
#define internal1_m1708_q0	BUFFER[5814]	// (internal1_m1708_q0) q0 - внутренний параметр
#define idinternal1_m1708_q0	1192	// (internal1_m1708_q0) q0 - внутренний параметр
#define internal1_m1722_q0	BUFFER[5816]	// (internal1_m1722_q0) q0 - внутренний параметр
#define idinternal1_m1722_q0	1193	// (internal1_m1722_q0) q0 - внутренний параметр
#define internal1_m1723_q0	BUFFER[5818]	// (internal1_m1723_q0) q0 - внутренний параметр
#define idinternal1_m1723_q0	1194	// (internal1_m1723_q0) q0 - внутренний параметр
#define internal1_m1774_tx	BUFFER[5820]	// (internal1_m1774_tx) tx - внутренний параметр
#define idinternal1_m1774_tx	1195	// (internal1_m1774_tx) tx - внутренний параметр
#define internal1_m1775_tx	BUFFER[5825]	// (internal1_m1775_tx) tx - внутренний параметр
#define idinternal1_m1775_tx	1196	// (internal1_m1775_tx) tx - внутренний параметр
#define internal1_m1777_tx	BUFFER[5830]	// (internal1_m1777_tx) tx - внутренний параметр
#define idinternal1_m1777_tx	1197	// (internal1_m1777_tx) tx - внутренний параметр
#define internal1_m1779_tx	BUFFER[5835]	// (internal1_m1779_tx) tx - внутренний параметр
#define idinternal1_m1779_tx	1198	// (internal1_m1779_tx) tx - внутренний параметр
#define internal1_m1788_tx	BUFFER[5840]	// (internal1_m1788_tx) tx - внутренний параметр
#define idinternal1_m1788_tx	1199	// (internal1_m1788_tx) tx - внутренний параметр
#define internal1_m178_BLDv0	BUFFER[5845]	// (internal1_m178_BLDv0) BlDv - Блокировка движения
#define idinternal1_m178_BLDv0	1200	// (internal1_m178_BLDv0) BlDv - Блокировка движения
#define internal1_m178_X0	BUFFER[5847]	// (internal1_m178_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m178_X0	1201	// (internal1_m178_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m178_t0	BUFFER[5852]	// (internal1_m178_t0) время нахождения в зоне возврата
#define idinternal1_m178_t0	1202	// (internal1_m178_t0) время нахождения в зоне возврата
#define internal1_m1793_tx	BUFFER[5857]	// (internal1_m1793_tx) tx - внутренний параметр
#define idinternal1_m1793_tx	1203	// (internal1_m1793_tx) tx - внутренний параметр
#define internal1_m1794_tx	BUFFER[5862]	// (internal1_m1794_tx) tx - внутренний параметр
#define idinternal1_m1794_tx	1204	// (internal1_m1794_tx) tx - внутренний параметр
#define internal1_m1796_tx	BUFFER[5867]	// (internal1_m1796_tx) tx - внутренний параметр
#define idinternal1_m1796_tx	1205	// (internal1_m1796_tx) tx - внутренний параметр
#define internal1_m1806_BLDv0	BUFFER[5872]	// (internal1_m1806_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1806_BLDv0	1206	// (internal1_m1806_BLDv0) BlDv - Блокировка движения
#define internal1_m1806_X0	BUFFER[5874]	// (internal1_m1806_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1806_X0	1207	// (internal1_m1806_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1806_t0	BUFFER[5879]	// (internal1_m1806_t0) время нахождения в зоне возврата
#define idinternal1_m1806_t0	1208	// (internal1_m1806_t0) время нахождения в зоне возврата
#define internal1_m1809_BlDv0	BUFFER[5884]	// (internal1_m1809_BlDv0) - была блокировка
#define idinternal1_m1809_BlDv0	1209	// (internal1_m1809_BlDv0) - была блокировка
#define internal1_m1809_DvDw0	BUFFER[5886]	// (internal1_m1809_DvDw0) - есть команда на движение назад
#define idinternal1_m1809_DvDw0	1210	// (internal1_m1809_DvDw0) - есть команда на движение назад
#define internal1_m1809_DvUp0	BUFFER[5888]	// (internal1_m1809_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1809_DvUp0	1211	// (internal1_m1809_DvUp0) - есть команда на движение вперёд
#define internal1_m1809_FDvDw0	BUFFER[5890]	// (internal1_m1809_FDvDw0) - есть команда на движение назад
#define idinternal1_m1809_FDvDw0	1212	// (internal1_m1809_FDvDw0) - есть команда на движение назад
#define internal1_m1809_FDvUp0	BUFFER[5892]	// (internal1_m1809_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1809_FDvUp0	1213	// (internal1_m1809_FDvUp0) - есть команда на движение вперёд
#define internal1_m1809_Pkav0	BUFFER[5894]	// (internal1_m1809_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1809_Pkav0	1214	// (internal1_m1809_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1809_Pkv0	BUFFER[5896]	// (internal1_m1809_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1809_Pkv0	1215	// (internal1_m1809_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1809_Zkav0	BUFFER[5898]	// (internal1_m1809_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1809_Zkav0	1216	// (internal1_m1809_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1809_Zkv0	BUFFER[5900]	// (internal1_m1809_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1809_Zkv0	1217	// (internal1_m1809_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1809_fef	BUFFER[5902]	// (internal1_m1809_fef) fef
#define idinternal1_m1809_fef	1218	// (internal1_m1809_fef) fef
#define internal1_m1809_txHr	BUFFER[5904]	// (internal1_m1809_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1809_txHr	1219	// (internal1_m1809_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1809_txLd	BUFFER[5909]	// (internal1_m1809_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1809_txLd	1220	// (internal1_m1809_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1809_txNm	BUFFER[5914]	// (internal1_m1809_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1809_txNm	1221	// (internal1_m1809_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1809_txSm	BUFFER[5919]	// (internal1_m1809_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1809_txSm	1222	// (internal1_m1809_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1810_tx	BUFFER[5924]	// (internal1_m1810_tx) tx - внутренний параметр
#define idinternal1_m1810_tx	1223	// (internal1_m1810_tx) tx - внутренний параметр
#define internal1_m1815_tx	BUFFER[5929]	// (internal1_m1815_tx) tx - внутренний параметр
#define idinternal1_m1815_tx	1224	// (internal1_m1815_tx) tx - внутренний параметр
#define internal1_m1820_tx	BUFFER[5934]	// (internal1_m1820_tx) tx - время накопленное сек
#define idinternal1_m1820_tx	1225	// (internal1_m1820_tx) tx - время накопленное сек
#define internal1_m1820_y0	BUFFER[5939]	// (internal1_m1820_y0) y0
#define idinternal1_m1820_y0	1226	// (internal1_m1820_y0) y0
#define internal1_m1821_tx	BUFFER[5941]	// (internal1_m1821_tx) tx - внутренний параметр
#define idinternal1_m1821_tx	1227	// (internal1_m1821_tx) tx - внутренний параметр
#define internal1_m1823_tx	BUFFER[5946]	// (internal1_m1823_tx) tx - внутренний параметр
#define idinternal1_m1823_tx	1228	// (internal1_m1823_tx) tx - внутренний параметр
#define internal1_m1824_tx	BUFFER[5951]	// (internal1_m1824_tx) tx - время накопленное сек
#define idinternal1_m1824_tx	1229	// (internal1_m1824_tx) tx - время накопленное сек
#define internal1_m1824_y0	BUFFER[5956]	// (internal1_m1824_y0) y0
#define idinternal1_m1824_y0	1230	// (internal1_m1824_y0) y0
#define internal1_m1828_DelSp	BUFFER[5958]	// (internal1_m1828_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1828_DelSp	1231	// (internal1_m1828_DelSp) DelSp - время переключения скоростей
#define internal1_m1828_ShCntlSp0	BUFFER[5963]	// (internal1_m1828_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1828_ShCntlSp0	1232	// (internal1_m1828_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1828_Shift0	BUFFER[5965]	// (internal1_m1828_Shift0) Shift0 - признак самохода
#define idinternal1_m1828_Shift0	1233	// (internal1_m1828_Shift0) Shift0 - признак самохода
#define internal1_m1828_ShiftControl	BUFFER[5967]	// (internal1_m1828_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1828_ShiftControl	1234	// (internal1_m1828_ShiftControl) ShiftControl - признак самохода
#define internal1_m1828_Speed0	BUFFER[5969]	// (internal1_m1828_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1828_Speed0	1235	// (internal1_m1828_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1828_StSpeed	BUFFER[5974]	// (internal1_m1828_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1828_StSpeed	1236	// (internal1_m1828_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1828_Vz0	BUFFER[5979]	// (internal1_m1828_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1828_Vz0	1237	// (internal1_m1828_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1828_flRazg	BUFFER[5984]	// (internal1_m1828_flRazg) признак разгона/торможения
#define idinternal1_m1828_flRazg	1238	// (internal1_m1828_flRazg) признак разгона/торможения
#define internal1_m1828_sumtim	BUFFER[5987]	// (internal1_m1828_sumtim) sumtim - время в пути
#define idinternal1_m1828_sumtim	1239	// (internal1_m1828_sumtim) sumtim - время в пути
#define internal1_m1828_tim0	BUFFER[5992]	// (internal1_m1828_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1828_tim0	1240	// (internal1_m1828_tim0) tim0 - массив значений времени цикла
#define internal1_m1828_tx	BUFFER[6092]	// (internal1_m1828_tx) tx
#define idinternal1_m1828_tx	1241	// (internal1_m1828_tx) tx
#define internal1_m1828_txBl	BUFFER[6097]	// (internal1_m1828_txBl) tx
#define idinternal1_m1828_txBl	1242	// (internal1_m1828_txBl) tx
#define internal1_m1828_txMBl	BUFFER[6102]	// (internal1_m1828_txMBl) tx
#define idinternal1_m1828_txMBl	1243	// (internal1_m1828_txMBl) tx
#define internal1_m1828_txZS	BUFFER[6107]	// (internal1_m1828_txZS) txZS
#define idinternal1_m1828_txZS	1244	// (internal1_m1828_txZS) txZS
#define internal1_m1828_txd	BUFFER[6112]	// (internal1_m1828_txd) txd
#define idinternal1_m1828_txd	1245	// (internal1_m1828_txd) txd
#define internal1_m1828_tz0	BUFFER[6117]	// (internal1_m1828_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1828_tz0	1246	// (internal1_m1828_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1828_x0	BUFFER[6122]	// (internal1_m1828_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1828_x0	1247	// (internal1_m1828_x0) x0 - массив мгновенных значений координат
#define internal1_m1828_xptr	BUFFER[6222]	// (internal1_m1828_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1828_xptr	1248	// (internal1_m1828_xptr) указатель текущей позиции в массиве координат
#define internal1_m1828_xz0	BUFFER[6225]	// (internal1_m1828_xz0) xz0 - новое задание мм
#define idinternal1_m1828_xz0	1249	// (internal1_m1828_xz0) xz0 - новое задание мм
#define internal1_m1828_z0	BUFFER[6230]	// (internal1_m1828_z0) z0 - точка прекращения движения
#define idinternal1_m1828_z0	1250	// (internal1_m1828_z0) z0 - точка прекращения движения
#define internal1_m1830_tx	BUFFER[6235]	// (internal1_m1830_tx) tx - внутренний параметр
#define idinternal1_m1830_tx	1251	// (internal1_m1830_tx) tx - внутренний параметр
#define internal1_m1831_tx	BUFFER[6240]	// (internal1_m1831_tx) tx - внутренний параметр
#define idinternal1_m1831_tx	1252	// (internal1_m1831_tx) tx - внутренний параметр
#define internal1_m1834_tx	BUFFER[6245]	// (internal1_m1834_tx) tx - время накопленное сек
#define idinternal1_m1834_tx	1253	// (internal1_m1834_tx) tx - время накопленное сек
#define internal1_m1834_y0	BUFFER[6250]	// (internal1_m1834_y0) y0
#define idinternal1_m1834_y0	1254	// (internal1_m1834_y0) y0
#define internal1_m1852_q0	BUFFER[6252]	// (internal1_m1852_q0) q0 - внутренний параметр
#define idinternal1_m1852_q0	1255	// (internal1_m1852_q0) q0 - внутренний параметр
#define internal1_m1854_q0	BUFFER[6254]	// (internal1_m1854_q0) q0 - внутренний параметр
#define idinternal1_m1854_q0	1256	// (internal1_m1854_q0) q0 - внутренний параметр
#define internal1_m1855_q0	BUFFER[6256]	// (internal1_m1855_q0) q0 - внутренний параметр
#define idinternal1_m1855_q0	1257	// (internal1_m1855_q0) q0 - внутренний параметр
#define internal1_m1857_q0	BUFFER[6258]	// (internal1_m1857_q0) q0 - внутренний параметр
#define idinternal1_m1857_q0	1258	// (internal1_m1857_q0) q0 - внутренний параметр
#define internal1_m1858_q0	BUFFER[6260]	// (internal1_m1858_q0) q0 - внутренний параметр
#define idinternal1_m1858_q0	1259	// (internal1_m1858_q0) q0 - внутренний параметр
#define internal1_m1860_q0	BUFFER[6262]	// (internal1_m1860_q0) q0 - внутренний параметр
#define idinternal1_m1860_q0	1260	// (internal1_m1860_q0) q0 - внутренний параметр
#define internal1_m1862_q0	BUFFER[6264]	// (internal1_m1862_q0) q0 - внутренний параметр
#define idinternal1_m1862_q0	1261	// (internal1_m1862_q0) q0 - внутренний параметр
#define internal1_m1864_q0	BUFFER[6266]	// (internal1_m1864_q0) q0 - внутренний параметр
#define idinternal1_m1864_q0	1262	// (internal1_m1864_q0) q0 - внутренний параметр
#define internal1_m1866_q0	BUFFER[6268]	// (internal1_m1866_q0) q0 - внутренний параметр
#define idinternal1_m1866_q0	1263	// (internal1_m1866_q0) q0 - внутренний параметр
#define internal1_m1867_q0	BUFFER[6270]	// (internal1_m1867_q0) q0 - внутренний параметр
#define idinternal1_m1867_q0	1264	// (internal1_m1867_q0) q0 - внутренний параметр
#define internal1_m1868_q0	BUFFER[6272]	// (internal1_m1868_q0) q0 - внутренний параметр
#define idinternal1_m1868_q0	1265	// (internal1_m1868_q0) q0 - внутренний параметр
#define internal1_m1869_q0	BUFFER[6274]	// (internal1_m1869_q0) q0 - внутренний параметр
#define idinternal1_m1869_q0	1266	// (internal1_m1869_q0) q0 - внутренний параметр
#define internal1_m1878_q0	BUFFER[6276]	// (internal1_m1878_q0) q0 - внутренний параметр
#define idinternal1_m1878_q0	1267	// (internal1_m1878_q0) q0 - внутренний параметр
#define internal1_m1880_q0	BUFFER[6278]	// (internal1_m1880_q0) q0 - внутренний параметр
#define idinternal1_m1880_q0	1268	// (internal1_m1880_q0) q0 - внутренний параметр
#define internal1_m1882_q0	BUFFER[6280]	// (internal1_m1882_q0) q0 - внутренний параметр
#define idinternal1_m1882_q0	1269	// (internal1_m1882_q0) q0 - внутренний параметр
#define internal1_m1884_q0	BUFFER[6282]	// (internal1_m1884_q0) q0 - внутренний параметр
#define idinternal1_m1884_q0	1270	// (internal1_m1884_q0) q0 - внутренний параметр
#define internal1_m1886_q0	BUFFER[6284]	// (internal1_m1886_q0) q0 - внутренний параметр
#define idinternal1_m1886_q0	1271	// (internal1_m1886_q0) q0 - внутренний параметр
#define internal1_m1888_q0	BUFFER[6286]	// (internal1_m1888_q0) q0 - внутренний параметр
#define idinternal1_m1888_q0	1272	// (internal1_m1888_q0) q0 - внутренний параметр
#define internal1_m1890_q0	BUFFER[6288]	// (internal1_m1890_q0) q0 - внутренний параметр
#define idinternal1_m1890_q0	1273	// (internal1_m1890_q0) q0 - внутренний параметр
#define internal1_m1892_q0	BUFFER[6290]	// (internal1_m1892_q0) q0 - внутренний параметр
#define idinternal1_m1892_q0	1274	// (internal1_m1892_q0) q0 - внутренний параметр
#define internal1_m1900_q0	BUFFER[6292]	// (internal1_m1900_q0) q0 - внутренний параметр
#define idinternal1_m1900_q0	1275	// (internal1_m1900_q0) q0 - внутренний параметр
#define internal1_m1901_q0	BUFFER[6294]	// (internal1_m1901_q0) q0 - внутренний параметр
#define idinternal1_m1901_q0	1276	// (internal1_m1901_q0) q0 - внутренний параметр
#define internal1_m1902_q0	BUFFER[6296]	// (internal1_m1902_q0) q0 - внутренний параметр
#define idinternal1_m1902_q0	1277	// (internal1_m1902_q0) q0 - внутренний параметр
#define internal1_m1909_q0	BUFFER[6298]	// (internal1_m1909_q0) q0 - внутренний параметр
#define idinternal1_m1909_q0	1278	// (internal1_m1909_q0) q0 - внутренний параметр
#define internal1_m1911_q0	BUFFER[6300]	// (internal1_m1911_q0) q0 - внутренний параметр
#define idinternal1_m1911_q0	1279	// (internal1_m1911_q0) q0 - внутренний параметр
#define internal1_m1913_q0	BUFFER[6302]	// (internal1_m1913_q0) q0 - внутренний параметр
#define idinternal1_m1913_q0	1280	// (internal1_m1913_q0) q0 - внутренний параметр
#define internal1_m1915_q0	BUFFER[6304]	// (internal1_m1915_q0) q0 - внутренний параметр
#define idinternal1_m1915_q0	1281	// (internal1_m1915_q0) q0 - внутренний параметр
#define internal1_m1917_q0	BUFFER[6306]	// (internal1_m1917_q0) q0 - внутренний параметр
#define idinternal1_m1917_q0	1282	// (internal1_m1917_q0) q0 - внутренний параметр
#define internal1_m1919_q0	BUFFER[6308]	// (internal1_m1919_q0) q0 - внутренний параметр
#define idinternal1_m1919_q0	1283	// (internal1_m1919_q0) q0 - внутренний параметр
#define internal1_m1922_q0	BUFFER[6310]	// (internal1_m1922_q0) q0 - внутренний параметр
#define idinternal1_m1922_q0	1284	// (internal1_m1922_q0) q0 - внутренний параметр
#define internal1_m1925_q0	BUFFER[6312]	// (internal1_m1925_q0) q0 - внутренний параметр
#define idinternal1_m1925_q0	1285	// (internal1_m1925_q0) q0 - внутренний параметр
#define internal1_m1927_q0	BUFFER[6314]	// (internal1_m1927_q0) q0 - внутренний параметр
#define idinternal1_m1927_q0	1286	// (internal1_m1927_q0) q0 - внутренний параметр
#define internal1_m1930_q0	BUFFER[6316]	// (internal1_m1930_q0) q0 - внутренний параметр
#define idinternal1_m1930_q0	1287	// (internal1_m1930_q0) q0 - внутренний параметр
#define internal1_m1936_MyFirstEnterFlag	BUFFER[6318]	// (internal1_m1936_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1936_MyFirstEnterFlag	1288	// (internal1_m1936_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m1936_Pv0	BUFFER[6320]	// (internal1_m1936_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1936_Pv0	1289	// (internal1_m1936_Pv0)  - Пер. выключатель механизма
#define internal1_m1936_Zv0	BUFFER[6322]	// (internal1_m1936_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1936_Zv0	1290	// (internal1_m1936_Zv0)  - Зад. выключатель механизма
#define internal1_m1937_MyFirstEnterFlag	BUFFER[6324]	// (internal1_m1937_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1937_MyFirstEnterFlag	1291	// (internal1_m1937_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m1937_Pv0	BUFFER[6326]	// (internal1_m1937_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1937_Pv0	1292	// (internal1_m1937_Pv0)  - Пер. выключатель механизма
#define internal1_m1937_Zv0	BUFFER[6328]	// (internal1_m1937_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1937_Zv0	1293	// (internal1_m1937_Zv0)  - Зад. выключатель механизма
#define internal1_m1949_q0	BUFFER[6330]	// (internal1_m1949_q0) q0 - внутренний параметр
#define idinternal1_m1949_q0	1294	// (internal1_m1949_q0) q0 - внутренний параметр
#define internal1_m1952_q0	BUFFER[6332]	// (internal1_m1952_q0) q0 - внутренний параметр
#define idinternal1_m1952_q0	1295	// (internal1_m1952_q0) q0 - внутренний параметр
#define internal1_m1956_q0	BUFFER[6334]	// (internal1_m1956_q0) q0 - внутренний параметр
#define idinternal1_m1956_q0	1296	// (internal1_m1956_q0) q0 - внутренний параметр
#define internal1_m1959_q0	BUFFER[6336]	// (internal1_m1959_q0) q0 - внутренний параметр
#define idinternal1_m1959_q0	1297	// (internal1_m1959_q0) q0 - внутренний параметр
#define internal1_m195_tx	BUFFER[6338]	// (internal1_m195_tx) tx - время накопленное сек
#define idinternal1_m195_tx	1298	// (internal1_m195_tx) tx - время накопленное сек
#define internal1_m195_y0	BUFFER[6343]	// (internal1_m195_y0) y0
#define idinternal1_m195_y0	1299	// (internal1_m195_y0) y0
#define internal1_m1962_q0	BUFFER[6345]	// (internal1_m1962_q0) q0 - внутренний параметр
#define idinternal1_m1962_q0	1300	// (internal1_m1962_q0) q0 - внутренний параметр
#define internal1_m1964_q0	BUFFER[6347]	// (internal1_m1964_q0) q0 - внутренний параметр
#define idinternal1_m1964_q0	1301	// (internal1_m1964_q0) q0 - внутренний параметр
#define internal1_m196_tx	BUFFER[6349]	// (internal1_m196_tx) tx - время накопленное сек
#define idinternal1_m196_tx	1302	// (internal1_m196_tx) tx - время накопленное сек
#define internal1_m196_y0	BUFFER[6354]	// (internal1_m196_y0) y0
#define idinternal1_m196_y0	1303	// (internal1_m196_y0) y0
#define internal1_m19_q0	BUFFER[6356]	// (internal1_m19_q0) q0 - внутренний параметр
#define idinternal1_m19_q0	1304	// (internal1_m19_q0) q0 - внутренний параметр
#define internal1_m2029_tx	BUFFER[6358]	// (internal1_m2029_tx) tx - время накопленное сек
#define idinternal1_m2029_tx	1305	// (internal1_m2029_tx) tx - время накопленное сек
#define internal1_m2029_y0	BUFFER[6363]	// (internal1_m2029_y0) y0
#define idinternal1_m2029_y0	1306	// (internal1_m2029_y0) y0
#define internal1_m2030_tx	BUFFER[6365]	// (internal1_m2030_tx) tx - время накопленное сек
#define idinternal1_m2030_tx	1307	// (internal1_m2030_tx) tx - время накопленное сек
#define internal1_m2030_y0	BUFFER[6370]	// (internal1_m2030_y0) y0
#define idinternal1_m2030_y0	1308	// (internal1_m2030_y0) y0
#define internal1_m2031_tx	BUFFER[6372]	// (internal1_m2031_tx) tx - время накопленное сек
#define idinternal1_m2031_tx	1309	// (internal1_m2031_tx) tx - время накопленное сек
#define internal1_m2031_y0	BUFFER[6377]	// (internal1_m2031_y0) y0
#define idinternal1_m2031_y0	1310	// (internal1_m2031_y0) y0
#define internal1_m2032_tx	BUFFER[6379]	// (internal1_m2032_tx) tx - время накопленное сек
#define idinternal1_m2032_tx	1311	// (internal1_m2032_tx) tx - время накопленное сек
#define internal1_m2032_y0	BUFFER[6384]	// (internal1_m2032_y0) y0
#define idinternal1_m2032_y0	1312	// (internal1_m2032_y0) y0
#define internal1_m203_DelSp	BUFFER[6386]	// (internal1_m203_DelSp) DelSp - время переключения скоростей
#define idinternal1_m203_DelSp	1313	// (internal1_m203_DelSp) DelSp - время переключения скоростей
#define internal1_m203_ShCntlSp0	BUFFER[6391]	// (internal1_m203_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m203_ShCntlSp0	1314	// (internal1_m203_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m203_Shift0	BUFFER[6393]	// (internal1_m203_Shift0) Shift0 - признак самохода
#define idinternal1_m203_Shift0	1315	// (internal1_m203_Shift0) Shift0 - признак самохода
#define internal1_m203_ShiftControl	BUFFER[6395]	// (internal1_m203_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m203_ShiftControl	1316	// (internal1_m203_ShiftControl) ShiftControl - признак самохода
#define internal1_m203_Speed0	BUFFER[6397]	// (internal1_m203_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m203_Speed0	1317	// (internal1_m203_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m203_StSpeed	BUFFER[6402]	// (internal1_m203_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m203_StSpeed	1318	// (internal1_m203_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m203_Vz0	BUFFER[6407]	// (internal1_m203_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m203_Vz0	1319	// (internal1_m203_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m203_flRazg	BUFFER[6412]	// (internal1_m203_flRazg) признак разгона/торможения
#define idinternal1_m203_flRazg	1320	// (internal1_m203_flRazg) признак разгона/торможения
#define internal1_m203_sumtim	BUFFER[6415]	// (internal1_m203_sumtim) sumtim - время в пути
#define idinternal1_m203_sumtim	1321	// (internal1_m203_sumtim) sumtim - время в пути
#define internal1_m203_tim0	BUFFER[6420]	// (internal1_m203_tim0) tim0 - массив значений времени цикла
#define idinternal1_m203_tim0	1322	// (internal1_m203_tim0) tim0 - массив значений времени цикла
#define internal1_m203_tx	BUFFER[7170]	// (internal1_m203_tx) tx
#define idinternal1_m203_tx	1323	// (internal1_m203_tx) tx
#define internal1_m203_txBl	BUFFER[7175]	// (internal1_m203_txBl) tx
#define idinternal1_m203_txBl	1324	// (internal1_m203_txBl) tx
#define internal1_m203_txMBl	BUFFER[7180]	// (internal1_m203_txMBl) tx
#define idinternal1_m203_txMBl	1325	// (internal1_m203_txMBl) tx
#define internal1_m203_txZS	BUFFER[7185]	// (internal1_m203_txZS) txZS
#define idinternal1_m203_txZS	1326	// (internal1_m203_txZS) txZS
#define internal1_m203_txd	BUFFER[7190]	// (internal1_m203_txd) txd
#define idinternal1_m203_txd	1327	// (internal1_m203_txd) txd
#define internal1_m203_tz0	BUFFER[7195]	// (internal1_m203_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m203_tz0	1328	// (internal1_m203_tz0) tz0 - время защиты от нового задания сек
#define internal1_m203_x0	BUFFER[7200]	// (internal1_m203_x0) x0 - массив мгновенных значений координат
#define idinternal1_m203_x0	1329	// (internal1_m203_x0) x0 - массив мгновенных значений координат
#define internal1_m203_xptr	BUFFER[7950]	// (internal1_m203_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m203_xptr	1330	// (internal1_m203_xptr) указатель текущей позиции в массиве координат
#define internal1_m203_xz0	BUFFER[7953]	// (internal1_m203_xz0) xz0 - новое задание мм
#define idinternal1_m203_xz0	1331	// (internal1_m203_xz0) xz0 - новое задание мм
#define internal1_m203_z0	BUFFER[7958]	// (internal1_m203_z0) z0 - точка прекращения движения
#define idinternal1_m203_z0	1332	// (internal1_m203_z0) z0 - точка прекращения движения
#define internal1_m204_tx	BUFFER[7963]	// (internal1_m204_tx) tx - внутренний параметр
#define idinternal1_m204_tx	1333	// (internal1_m204_tx) tx - внутренний параметр
#define internal1_m205_tx	BUFFER[7968]	// (internal1_m205_tx) tx - внутренний параметр
#define idinternal1_m205_tx	1334	// (internal1_m205_tx) tx - внутренний параметр
#define internal1_m2067_tx	BUFFER[7973]	// (internal1_m2067_tx) tx - внутренний параметр
#define idinternal1_m2067_tx	1335	// (internal1_m2067_tx) tx - внутренний параметр
#define internal1_m2068_tx	BUFFER[7978]	// (internal1_m2068_tx) tx - внутренний параметр
#define idinternal1_m2068_tx	1336	// (internal1_m2068_tx) tx - внутренний параметр
#define internal1_m206_tx	BUFFER[7983]	// (internal1_m206_tx) tx - внутренний параметр
#define idinternal1_m206_tx	1337	// (internal1_m206_tx) tx - внутренний параметр
#define internal1_m2074_tim	BUFFER[7988]	// (internal1_m2074_tim) - время задержки выходного сигнала
#define idinternal1_m2074_tim	1338	// (internal1_m2074_tim) - время задержки выходного сигнала
#define internal1_m2074_x0	BUFFER[7993]	// (internal1_m2074_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m2074_x0	1339	// (internal1_m2074_x0) - значение входного параметра на предыдущем шаге
#define internal1_m2076_q0	BUFFER[7995]	// (internal1_m2076_q0) q0 - внутренний параметр
#define idinternal1_m2076_q0	1340	// (internal1_m2076_q0) q0 - внутренний параметр
#define internal1_m2079_tx	BUFFER[7997]	// (internal1_m2079_tx) tx - время накопленное сек
#define idinternal1_m2079_tx	1341	// (internal1_m2079_tx) tx - время накопленное сек
#define internal1_m2079_y0	BUFFER[8002]	// (internal1_m2079_y0) y0
#define idinternal1_m2079_y0	1342	// (internal1_m2079_y0) y0
#define internal1_m2082_q0	BUFFER[8004]	// (internal1_m2082_q0) q0 - внутренний параметр
#define idinternal1_m2082_q0	1343	// (internal1_m2082_q0) q0 - внутренний параметр
#define internal1_m2084_fef	BUFFER[8006]	// (internal1_m2084_fef) FirstEnterFlag
#define idinternal1_m2084_fef	1344	// (internal1_m2084_fef) FirstEnterFlag
#define internal1_m2084_x0	BUFFER[8008]	// (internal1_m2084_x0) был приход сигнала x1
#define idinternal1_m2084_x0	1345	// (internal1_m2084_x0) был приход сигнала x1
#define internal1_m2084_y0	BUFFER[8010]	// (internal1_m2084_y0) интервал между сигналами х1 и х2
#define idinternal1_m2084_y0	1346	// (internal1_m2084_y0) интервал между сигналами х1 и х2
#define internal1_m2089_q0	BUFFER[8015]	// (internal1_m2089_q0) q0 - внутренний параметр
#define idinternal1_m2089_q0	1347	// (internal1_m2089_q0) q0 - внутренний параметр
#define internal1_m2093_q0	BUFFER[8017]	// (internal1_m2093_q0) q0 - внутренний параметр
#define idinternal1_m2093_q0	1348	// (internal1_m2093_q0) q0 - внутренний параметр
#define internal1_m2102_q0	BUFFER[8022]	// (internal1_m2102_q0) q0 - внутренний параметр
#define idinternal1_m2102_q0	1349	// (internal1_m2102_q0) q0 - внутренний параметр
#define internal1_m2103_tim	BUFFER[8024]	// (internal1_m2103_tim) - время задержки выходного сигнала
#define idinternal1_m2103_tim	1350	// (internal1_m2103_tim) - время задержки выходного сигнала
#define internal1_m2103_x0	BUFFER[8029]	// (internal1_m2103_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m2103_x0	1351	// (internal1_m2103_x0) - значение входного параметра на предыдущем шаге
#define internal1_m2111_tx	BUFFER[8031]	// (internal1_m2111_tx) tx - время накопленное сек
#define idinternal1_m2111_tx	1352	// (internal1_m2111_tx) tx - время накопленное сек
#define internal1_m2111_y0	BUFFER[8036]	// (internal1_m2111_y0) y0
#define idinternal1_m2111_y0	1353	// (internal1_m2111_y0) y0
#define internal1_m2114_q0	BUFFER[8038]	// (internal1_m2114_q0) q0 - внутренний параметр
#define idinternal1_m2114_q0	1354	// (internal1_m2114_q0) q0 - внутренний параметр
#define internal1_m2123_tx	BUFFER[8040]	// (internal1_m2123_tx) tx - время накопленное сек
#define idinternal1_m2123_tx	1355	// (internal1_m2123_tx) tx - время накопленное сек
#define internal1_m2123_y0	BUFFER[8045]	// (internal1_m2123_y0) y0
#define idinternal1_m2123_y0	1356	// (internal1_m2123_y0) y0
#define internal1_m2125_fef	BUFFER[8047]	// (internal1_m2125_fef) FirstEnterFlag
#define idinternal1_m2125_fef	1357	// (internal1_m2125_fef) FirstEnterFlag
#define internal1_m2125_x0	BUFFER[8049]	// (internal1_m2125_x0) был приход сигнала x1
#define idinternal1_m2125_x0	1358	// (internal1_m2125_x0) был приход сигнала x1
#define internal1_m2125_y0	BUFFER[8051]	// (internal1_m2125_y0) интервал между сигналами х1 и х2
#define idinternal1_m2125_y0	1359	// (internal1_m2125_y0) интервал между сигналами х1 и х2
#define internal1_m2126_tx	BUFFER[8056]	// (internal1_m2126_tx) tx - время накопленное сек
#define idinternal1_m2126_tx	1360	// (internal1_m2126_tx) tx - время накопленное сек
#define internal1_m2126_y0	BUFFER[8061]	// (internal1_m2126_y0) y0
#define idinternal1_m2126_y0	1361	// (internal1_m2126_y0) y0
#define internal1_m212_tx	BUFFER[8063]	// (internal1_m212_tx) tx - внутренний параметр
#define idinternal1_m212_tx	1362	// (internal1_m212_tx) tx - внутренний параметр
#define internal1_m2133_q0	BUFFER[8068]	// (internal1_m2133_q0) q0 - внутренний параметр
#define idinternal1_m2133_q0	1363	// (internal1_m2133_q0) q0 - внутренний параметр
#define internal1_m2143_q0	BUFFER[8073]	// (internal1_m2143_q0) q0 - внутренний параметр
#define idinternal1_m2143_q0	1364	// (internal1_m2143_q0) q0 - внутренний параметр
#define internal1_m2159_q0	BUFFER[8075]	// (internal1_m2159_q0) q0 - внутренний параметр
#define idinternal1_m2159_q0	1365	// (internal1_m2159_q0) q0 - внутренний параметр
#define internal1_m2160_q0	BUFFER[8077]	// (internal1_m2160_q0) q0 - внутренний параметр
#define idinternal1_m2160_q0	1366	// (internal1_m2160_q0) q0 - внутренний параметр
#define internal1_m2168_tx	BUFFER[8079]	// (internal1_m2168_tx) tx - внутренний параметр
#define idinternal1_m2168_tx	1367	// (internal1_m2168_tx) tx - внутренний параметр
#define internal1_m2171_tx	BUFFER[8084]	// (internal1_m2171_tx) tx - внутренний параметр
#define idinternal1_m2171_tx	1368	// (internal1_m2171_tx) tx - внутренний параметр
#define internal1_m2174_q0	BUFFER[8089]	// (internal1_m2174_q0) q0 - внутренний параметр
#define idinternal1_m2174_q0	1369	// (internal1_m2174_q0) q0 - внутренний параметр
#define internal1_m217_tx	BUFFER[8091]	// (internal1_m217_tx) tx - время накопленное сек
#define idinternal1_m217_tx	1370	// (internal1_m217_tx) tx - время накопленное сек
#define internal1_m217_y0	BUFFER[8096]	// (internal1_m217_y0) y0
#define idinternal1_m217_y0	1371	// (internal1_m217_y0) y0
#define internal1_m2181_tx	BUFFER[8098]	// (internal1_m2181_tx) tx - внутренний параметр
#define idinternal1_m2181_tx	1372	// (internal1_m2181_tx) tx - внутренний параметр
#define internal1_m2184_tx	BUFFER[8103]	// (internal1_m2184_tx) tx - внутренний параметр
#define idinternal1_m2184_tx	1373	// (internal1_m2184_tx) tx - внутренний параметр
#define internal1_m2186_q0	BUFFER[8108]	// (internal1_m2186_q0) q0 - внутренний параметр
#define idinternal1_m2186_q0	1374	// (internal1_m2186_q0) q0 - внутренний параметр
#define internal1_m2196_tx	BUFFER[8110]	// (internal1_m2196_tx) tx - внутренний параметр
#define idinternal1_m2196_tx	1375	// (internal1_m2196_tx) tx - внутренний параметр
#define internal1_m2199_tx	BUFFER[8115]	// (internal1_m2199_tx) tx - внутренний параметр
#define idinternal1_m2199_tx	1376	// (internal1_m2199_tx) tx - внутренний параметр
#define internal1_m21_tx	BUFFER[8120]	// (internal1_m21_tx) tx - внутренний параметр
#define idinternal1_m21_tx	1377	// (internal1_m21_tx) tx - внутренний параметр
#define internal1_m2202_q0	BUFFER[8125]	// (internal1_m2202_q0) q0 - внутренний параметр
#define idinternal1_m2202_q0	1378	// (internal1_m2202_q0) q0 - внутренний параметр
#define internal1_m2210_tx	BUFFER[8127]	// (internal1_m2210_tx) tx - внутренний параметр
#define idinternal1_m2210_tx	1379	// (internal1_m2210_tx) tx - внутренний параметр
#define internal1_m2214_q0	BUFFER[8132]	// (internal1_m2214_q0) q0 - внутренний параметр
#define idinternal1_m2214_q0	1380	// (internal1_m2214_q0) q0 - внутренний параметр
#define internal1_m2220_tx	BUFFER[8134]	// (internal1_m2220_tx) tx - внутренний параметр
#define idinternal1_m2220_tx	1381	// (internal1_m2220_tx) tx - внутренний параметр
#define internal1_m2224_tx	BUFFER[8139]	// (internal1_m2224_tx) tx - внутренний параметр
#define idinternal1_m2224_tx	1382	// (internal1_m2224_tx) tx - внутренний параметр
#define internal1_m222_tx	BUFFER[8144]	// (internal1_m222_tx) tx - внутренний параметр
#define idinternal1_m222_tx	1383	// (internal1_m222_tx) tx - внутренний параметр
#define internal1_m2230_q0	BUFFER[8149]	// (internal1_m2230_q0) q0 - внутренний параметр
#define idinternal1_m2230_q0	1384	// (internal1_m2230_q0) q0 - внутренний параметр
#define internal1_m2231_tx	BUFFER[8151]	// (internal1_m2231_tx) tx - время накопленное сек
#define idinternal1_m2231_tx	1385	// (internal1_m2231_tx) tx - время накопленное сек
#define internal1_m2231_y0	BUFFER[8156]	// (internal1_m2231_y0) y0
#define idinternal1_m2231_y0	1386	// (internal1_m2231_y0) y0
#define internal1_m2235_tx	BUFFER[8158]	// (internal1_m2235_tx) tx - внутренний параметр
#define idinternal1_m2235_tx	1387	// (internal1_m2235_tx) tx - внутренний параметр
#define internal1_m2238_q0	BUFFER[8163]	// (internal1_m2238_q0) q0 - внутренний параметр
#define idinternal1_m2238_q0	1388	// (internal1_m2238_q0) q0 - внутренний параметр
#define internal1_m2239_tx	BUFFER[8165]	// (internal1_m2239_tx) tx - время накопленное сек
#define idinternal1_m2239_tx	1389	// (internal1_m2239_tx) tx - время накопленное сек
#define internal1_m2239_y0	BUFFER[8170]	// (internal1_m2239_y0) y0
#define idinternal1_m2239_y0	1390	// (internal1_m2239_y0) y0
#define internal1_m223_tx	BUFFER[8172]	// (internal1_m223_tx) tx - время накопленное сек
#define idinternal1_m223_tx	1391	// (internal1_m223_tx) tx - время накопленное сек
#define internal1_m223_y0	BUFFER[8177]	// (internal1_m223_y0) y0
#define idinternal1_m223_y0	1392	// (internal1_m223_y0) y0
#define internal1_m2245_tx	BUFFER[8179]	// (internal1_m2245_tx) tx - внутренний параметр
#define idinternal1_m2245_tx	1393	// (internal1_m2245_tx) tx - внутренний параметр
#define internal1_m2253_tx	BUFFER[8184]	// (internal1_m2253_tx) tx - внутренний параметр
#define idinternal1_m2253_tx	1394	// (internal1_m2253_tx) tx - внутренний параметр
#define internal1_m2255_q0	BUFFER[8189]	// (internal1_m2255_q0) q0 - внутренний параметр
#define idinternal1_m2255_q0	1395	// (internal1_m2255_q0) q0 - внутренний параметр
#define internal1_m2262_tx	BUFFER[8191]	// (internal1_m2262_tx) tx - внутренний параметр
#define idinternal1_m2262_tx	1396	// (internal1_m2262_tx) tx - внутренний параметр
#define internal1_m2266_tx	BUFFER[8196]	// (internal1_m2266_tx) tx - время накопленное сек
#define idinternal1_m2266_tx	1397	// (internal1_m2266_tx) tx - время накопленное сек
#define internal1_m2266_y0	BUFFER[8201]	// (internal1_m2266_y0) y0
#define idinternal1_m2266_y0	1398	// (internal1_m2266_y0) y0
#define internal1_m2268_tx	BUFFER[8203]	// (internal1_m2268_tx) tx - внутренний параметр
#define idinternal1_m2268_tx	1399	// (internal1_m2268_tx) tx - внутренний параметр
#define internal1_m2271_q0	BUFFER[8208]	// (internal1_m2271_q0) q0 - внутренний параметр
#define idinternal1_m2271_q0	1400	// (internal1_m2271_q0) q0 - внутренний параметр
#define internal1_m2273_tx	BUFFER[8210]	// (internal1_m2273_tx) tx - внутренний параметр
#define idinternal1_m2273_tx	1401	// (internal1_m2273_tx) tx - внутренний параметр
#define internal1_m2274_tx	BUFFER[8215]	// (internal1_m2274_tx) tx - внутренний параметр
#define idinternal1_m2274_tx	1402	// (internal1_m2274_tx) tx - внутренний параметр
#define internal1_m2277_tx	BUFFER[8220]	// (internal1_m2277_tx) tx - время накопленное сек
#define idinternal1_m2277_tx	1403	// (internal1_m2277_tx) tx - время накопленное сек
#define internal1_m2277_y0	BUFFER[8225]	// (internal1_m2277_y0) y0
#define idinternal1_m2277_y0	1404	// (internal1_m2277_y0) y0
#define internal1_m2285_tx	BUFFER[8227]	// (internal1_m2285_tx) tx - внутренний параметр
#define idinternal1_m2285_tx	1405	// (internal1_m2285_tx) tx - внутренний параметр
#define internal1_m2286_tx	BUFFER[8232]	// (internal1_m2286_tx) tx - внутренний параметр
#define idinternal1_m2286_tx	1406	// (internal1_m2286_tx) tx - внутренний параметр
#define internal1_m2288_tx	BUFFER[8237]	// (internal1_m2288_tx) tx - внутренний параметр
#define idinternal1_m2288_tx	1407	// (internal1_m2288_tx) tx - внутренний параметр
#define internal1_m2294_q0	BUFFER[8242]	// (internal1_m2294_q0) q0 - внутренний параметр
#define idinternal1_m2294_q0	1408	// (internal1_m2294_q0) q0 - внутренний параметр
#define internal1_m2299_q0	BUFFER[8244]	// (internal1_m2299_q0) q0 - внутренний параметр
#define idinternal1_m2299_q0	1409	// (internal1_m2299_q0) q0 - внутренний параметр
#define internal1_m2302_tx	BUFFER[8246]	// (internal1_m2302_tx) tx - внутренний параметр
#define idinternal1_m2302_tx	1410	// (internal1_m2302_tx) tx - внутренний параметр
#define internal1_m230_tx	BUFFER[8251]	// (internal1_m230_tx) tx - внутренний параметр
#define idinternal1_m230_tx	1411	// (internal1_m230_tx) tx - внутренний параметр
#define internal1_m2315_tx	BUFFER[8256]	// (internal1_m2315_tx) tx - внутренний параметр
#define idinternal1_m2315_tx	1412	// (internal1_m2315_tx) tx - внутренний параметр
#define internal1_m2316_tx	BUFFER[8261]	// (internal1_m2316_tx) tx - внутренний параметр
#define idinternal1_m2316_tx	1413	// (internal1_m2316_tx) tx - внутренний параметр
#define internal1_m2317_tx	BUFFER[8266]	// (internal1_m2317_tx) tx - внутренний параметр
#define idinternal1_m2317_tx	1414	// (internal1_m2317_tx) tx - внутренний параметр
#define internal1_m2321_BlDv0	BUFFER[8271]	// (internal1_m2321_BlDv0) - была блокировка
#define idinternal1_m2321_BlDv0	1415	// (internal1_m2321_BlDv0) - была блокировка
#define internal1_m2321_DvDw0	BUFFER[8273]	// (internal1_m2321_DvDw0) - есть команда на движение назад
#define idinternal1_m2321_DvDw0	1416	// (internal1_m2321_DvDw0) - есть команда на движение назад
#define internal1_m2321_DvUp0	BUFFER[8275]	// (internal1_m2321_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2321_DvUp0	1417	// (internal1_m2321_DvUp0) - есть команда на движение вперёд
#define internal1_m2321_FDvDw0	BUFFER[8277]	// (internal1_m2321_FDvDw0) - есть команда на движение назад
#define idinternal1_m2321_FDvDw0	1418	// (internal1_m2321_FDvDw0) - есть команда на движение назад
#define internal1_m2321_FDvUp0	BUFFER[8279]	// (internal1_m2321_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2321_FDvUp0	1419	// (internal1_m2321_FDvUp0) - есть команда на движение вперёд
#define internal1_m2321_Pkav0	BUFFER[8281]	// (internal1_m2321_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2321_Pkav0	1420	// (internal1_m2321_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2321_Pkv0	BUFFER[8283]	// (internal1_m2321_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2321_Pkv0	1421	// (internal1_m2321_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2321_Zkav0	BUFFER[8285]	// (internal1_m2321_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2321_Zkav0	1422	// (internal1_m2321_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2321_Zkv0	BUFFER[8287]	// (internal1_m2321_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2321_Zkv0	1423	// (internal1_m2321_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2321_fef	BUFFER[8289]	// (internal1_m2321_fef) fef
#define idinternal1_m2321_fef	1424	// (internal1_m2321_fef) fef
#define internal1_m2321_txHr	BUFFER[8291]	// (internal1_m2321_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2321_txHr	1425	// (internal1_m2321_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2321_txLd	BUFFER[8296]	// (internal1_m2321_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2321_txLd	1426	// (internal1_m2321_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2321_txNm	BUFFER[8301]	// (internal1_m2321_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2321_txNm	1427	// (internal1_m2321_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2321_txSm	BUFFER[8306]	// (internal1_m2321_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2321_txSm	1428	// (internal1_m2321_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2322_tx	BUFFER[8311]	// (internal1_m2322_tx) tx - внутренний параметр
#define idinternal1_m2322_tx	1429	// (internal1_m2322_tx) tx - внутренний параметр
#define internal1_m2327_BlDv0	BUFFER[8316]	// (internal1_m2327_BlDv0) - была блокировка
#define idinternal1_m2327_BlDv0	1430	// (internal1_m2327_BlDv0) - была блокировка
#define internal1_m2327_DvDw0	BUFFER[8318]	// (internal1_m2327_DvDw0) - есть команда на движение назад
#define idinternal1_m2327_DvDw0	1431	// (internal1_m2327_DvDw0) - есть команда на движение назад
#define internal1_m2327_DvUp0	BUFFER[8320]	// (internal1_m2327_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2327_DvUp0	1432	// (internal1_m2327_DvUp0) - есть команда на движение вперёд
#define internal1_m2327_FDvDw0	BUFFER[8322]	// (internal1_m2327_FDvDw0) - есть команда на движение назад
#define idinternal1_m2327_FDvDw0	1433	// (internal1_m2327_FDvDw0) - есть команда на движение назад
#define internal1_m2327_FDvUp0	BUFFER[8324]	// (internal1_m2327_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2327_FDvUp0	1434	// (internal1_m2327_FDvUp0) - есть команда на движение вперёд
#define internal1_m2327_Pkav0	BUFFER[8326]	// (internal1_m2327_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2327_Pkav0	1435	// (internal1_m2327_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2327_Pkv0	BUFFER[8328]	// (internal1_m2327_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2327_Pkv0	1436	// (internal1_m2327_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2327_Zkav0	BUFFER[8330]	// (internal1_m2327_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2327_Zkav0	1437	// (internal1_m2327_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2327_Zkv0	BUFFER[8332]	// (internal1_m2327_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2327_Zkv0	1438	// (internal1_m2327_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2327_fef	BUFFER[8334]	// (internal1_m2327_fef) fef
#define idinternal1_m2327_fef	1439	// (internal1_m2327_fef) fef
#define internal1_m2327_txHr	BUFFER[8336]	// (internal1_m2327_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2327_txHr	1440	// (internal1_m2327_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2327_txLd	BUFFER[8341]	// (internal1_m2327_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2327_txLd	1441	// (internal1_m2327_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2327_txNm	BUFFER[8346]	// (internal1_m2327_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2327_txNm	1442	// (internal1_m2327_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2327_txSm	BUFFER[8351]	// (internal1_m2327_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2327_txSm	1443	// (internal1_m2327_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m232_tx	BUFFER[8356]	// (internal1_m232_tx) tx - внутренний параметр
#define idinternal1_m232_tx	1444	// (internal1_m232_tx) tx - внутренний параметр
#define internal1_m2330_tx	BUFFER[8361]	// (internal1_m2330_tx) tx - внутренний параметр
#define idinternal1_m2330_tx	1445	// (internal1_m2330_tx) tx - внутренний параметр
#define internal1_m2331_tx	BUFFER[8366]	// (internal1_m2331_tx) tx - внутренний параметр
#define idinternal1_m2331_tx	1446	// (internal1_m2331_tx) tx - внутренний параметр
#define internal1_m2332_tx	BUFFER[8371]	// (internal1_m2332_tx) tx - внутренний параметр
#define idinternal1_m2332_tx	1447	// (internal1_m2332_tx) tx - внутренний параметр
#define internal1_m2339_q0	BUFFER[8376]	// (internal1_m2339_q0) q0 - внутренний параметр
#define idinternal1_m2339_q0	1448	// (internal1_m2339_q0) q0 - внутренний параметр
#define internal1_m2340_q0	BUFFER[8378]	// (internal1_m2340_q0) q0 - внутренний параметр
#define idinternal1_m2340_q0	1449	// (internal1_m2340_q0) q0 - внутренний параметр
#define internal1_m2341_q0	BUFFER[8380]	// (internal1_m2341_q0) q0 - внутренний параметр
#define idinternal1_m2341_q0	1450	// (internal1_m2341_q0) q0 - внутренний параметр
#define internal1_m2342_q0	BUFFER[8382]	// (internal1_m2342_q0) q0 - внутренний параметр
#define idinternal1_m2342_q0	1451	// (internal1_m2342_q0) q0 - внутренний параметр
#define internal1_m2344_q0	BUFFER[8384]	// (internal1_m2344_q0) q0 - внутренний параметр
#define idinternal1_m2344_q0	1452	// (internal1_m2344_q0) q0 - внутренний параметр
#define internal1_m234_tx	BUFFER[8386]	// (internal1_m234_tx) tx - внутренний параметр
#define idinternal1_m234_tx	1453	// (internal1_m234_tx) tx - внутренний параметр
#define internal1_m2351_q0	BUFFER[8391]	// (internal1_m2351_q0) q0 - внутренний параметр
#define idinternal1_m2351_q0	1454	// (internal1_m2351_q0) q0 - внутренний параметр
#define internal1_m2353_q0	BUFFER[8393]	// (internal1_m2353_q0) q0 - внутренний параметр
#define idinternal1_m2353_q0	1455	// (internal1_m2353_q0) q0 - внутренний параметр
#define internal1_m2355_q0	BUFFER[8395]	// (internal1_m2355_q0) q0 - внутренний параметр
#define idinternal1_m2355_q0	1456	// (internal1_m2355_q0) q0 - внутренний параметр
#define internal1_m2357_q0	BUFFER[8397]	// (internal1_m2357_q0) q0 - внутренний параметр
#define idinternal1_m2357_q0	1457	// (internal1_m2357_q0) q0 - внутренний параметр
#define internal1_m2359_q0	BUFFER[8399]	// (internal1_m2359_q0) q0 - внутренний параметр
#define idinternal1_m2359_q0	1458	// (internal1_m2359_q0) q0 - внутренний параметр
#define internal1_m2361_q0	BUFFER[8401]	// (internal1_m2361_q0) q0 - внутренний параметр
#define idinternal1_m2361_q0	1459	// (internal1_m2361_q0) q0 - внутренний параметр
#define internal1_m2363_q0	BUFFER[8403]	// (internal1_m2363_q0) q0 - внутренний параметр
#define idinternal1_m2363_q0	1460	// (internal1_m2363_q0) q0 - внутренний параметр
#define internal1_m2370_q0	BUFFER[8405]	// (internal1_m2370_q0) q0 - внутренний параметр
#define idinternal1_m2370_q0	1461	// (internal1_m2370_q0) q0 - внутренний параметр
#define internal1_m2371_q0	BUFFER[8407]	// (internal1_m2371_q0) q0 - внутренний параметр
#define idinternal1_m2371_q0	1462	// (internal1_m2371_q0) q0 - внутренний параметр
#define internal1_m2372_q0	BUFFER[8409]	// (internal1_m2372_q0) q0 - внутренний параметр
#define idinternal1_m2372_q0	1463	// (internal1_m2372_q0) q0 - внутренний параметр
#define internal1_m2374_q0	BUFFER[8411]	// (internal1_m2374_q0) q0 - внутренний параметр
#define idinternal1_m2374_q0	1464	// (internal1_m2374_q0) q0 - внутренний параметр
#define internal1_m2375_q0	BUFFER[8413]	// (internal1_m2375_q0) q0 - внутренний параметр
#define idinternal1_m2375_q0	1465	// (internal1_m2375_q0) q0 - внутренний параметр
#define internal1_m2382_q0	BUFFER[8415]	// (internal1_m2382_q0) q0 - внутренний параметр
#define idinternal1_m2382_q0	1466	// (internal1_m2382_q0) q0 - внутренний параметр
#define internal1_m2384_q0	BUFFER[8417]	// (internal1_m2384_q0) q0 - внутренний параметр
#define idinternal1_m2384_q0	1467	// (internal1_m2384_q0) q0 - внутренний параметр
#define internal1_m2386_q0	BUFFER[8419]	// (internal1_m2386_q0) q0 - внутренний параметр
#define idinternal1_m2386_q0	1468	// (internal1_m2386_q0) q0 - внутренний параметр
#define internal1_m2388_q0	BUFFER[8421]	// (internal1_m2388_q0) q0 - внутренний параметр
#define idinternal1_m2388_q0	1469	// (internal1_m2388_q0) q0 - внутренний параметр
#define internal1_m2390_q0	BUFFER[8423]	// (internal1_m2390_q0) q0 - внутренний параметр
#define idinternal1_m2390_q0	1470	// (internal1_m2390_q0) q0 - внутренний параметр
#define internal1_m2392_q0	BUFFER[8425]	// (internal1_m2392_q0) q0 - внутренний параметр
#define idinternal1_m2392_q0	1471	// (internal1_m2392_q0) q0 - внутренний параметр
#define internal1_m2394_q0	BUFFER[8427]	// (internal1_m2394_q0) q0 - внутренний параметр
#define idinternal1_m2394_q0	1472	// (internal1_m2394_q0) q0 - внутренний параметр
#define internal1_m2410_tx	BUFFER[8429]	// (internal1_m2410_tx) tx - время накопленное сек
#define idinternal1_m2410_tx	1473	// (internal1_m2410_tx) tx - время накопленное сек
#define internal1_m2410_y0	BUFFER[8434]	// (internal1_m2410_y0) y0
#define idinternal1_m2410_y0	1474	// (internal1_m2410_y0) y0
#define internal1_m2413_FlPar	BUFFER[8436]	// (internal1_m2413_FlPar) - стартовый этап регулирования
#define idinternal1_m2413_FlPar	1475	// (internal1_m2413_FlPar) - стартовый этап регулирования
#define internal1_m2413_ZerCoun	BUFFER[8439]	// (internal1_m2413_ZerCoun) - флаг направления изменения мощности
#define idinternal1_m2413_ZerCoun	1476	// (internal1_m2413_ZerCoun) - флаг направления изменения мощности
#define internal1_m2413_fRct	BUFFER[8442]	// (internal1_m2413_fRct)  - текущая реактивность регулятора 
#define idinternal1_m2413_fRct	1477	// (internal1_m2413_fRct)  - текущая реактивность регулятора 
#define internal1_m2413_fStw0	BUFFER[8447]	// (internal1_m2413_fStw0)  - исходное положение ИС для изменения задания 
#define idinternal1_m2413_fStw0	1478	// (internal1_m2413_fStw0)  - исходное положение ИС для изменения задания 
#define internal1_m2413_fTk0	BUFFER[8452]	// (internal1_m2413_fTk0)  - последняя температура 
#define idinternal1_m2413_fTk0	1479	// (internal1_m2413_fTk0)  - последняя температура 
#define internal1_m2413_fef	BUFFER[8457]	// (internal1_m2413_fef)  - первый вход
#define idinternal1_m2413_fef	1480	// (internal1_m2413_fef)  - первый вход
#define internal1_m2413_fkizm	BUFFER[8459]	// (internal1_m2413_fkizm)  - стартовая координата положения ИМ 0-й реактивности 
#define idinternal1_m2413_fkizm	1481	// (internal1_m2413_fkizm)  - стартовая координата положения ИМ 0-й реактивности 
#define internal1_m2413_fwt0	BUFFER[8464]	// (internal1_m2413_fwt0)  - мощность на предыдущем шаге 
#define idinternal1_m2413_fwt0	1482	// (internal1_m2413_fwt0)  - мощность на предыдущем шаге 
#define internal1_m2413_fwz0	BUFFER[8469]	// (internal1_m2413_fwz0)  - заданная мощность на предыдущем шаге 
#define idinternal1_m2413_fwz0	1483	// (internal1_m2413_fwz0)  - заданная мощность на предыдущем шаге 
#define internal1_m2414_tx	BUFFER[8474]	// (internal1_m2414_tx) tx - время накопленное сек
#define idinternal1_m2414_tx	1484	// (internal1_m2414_tx) tx - время накопленное сек
#define internal1_m2414_y0	BUFFER[8479]	// (internal1_m2414_y0) y0
#define idinternal1_m2414_y0	1485	// (internal1_m2414_y0) y0
#define internal1_m2415_tx	BUFFER[8481]	// (internal1_m2415_tx) tx - время накопленное сек
#define idinternal1_m2415_tx	1486	// (internal1_m2415_tx) tx - время накопленное сек
#define internal1_m2415_y0	BUFFER[8486]	// (internal1_m2415_y0) y0
#define idinternal1_m2415_y0	1487	// (internal1_m2415_y0) y0
#define internal1_m2421_q0	BUFFER[8488]	// (internal1_m2421_q0) q0 - внутренний параметр
#define idinternal1_m2421_q0	1488	// (internal1_m2421_q0) q0 - внутренний параметр
#define internal1_m2427_q0	BUFFER[8490]	// (internal1_m2427_q0) q0 - внутренний параметр
#define idinternal1_m2427_q0	1489	// (internal1_m2427_q0) q0 - внутренний параметр
#define internal1_m2429_tx	BUFFER[8492]	// (internal1_m2429_tx) tx - внутренний параметр
#define idinternal1_m2429_tx	1490	// (internal1_m2429_tx) tx - внутренний параметр
#define internal1_m243_tx	BUFFER[8497]	// (internal1_m243_tx) tx - внутренний параметр
#define idinternal1_m243_tx	1491	// (internal1_m243_tx) tx - внутренний параметр
#define internal1_m2444_tx	BUFFER[8502]	// (internal1_m2444_tx) tx - время накопленное сек
#define idinternal1_m2444_tx	1492	// (internal1_m2444_tx) tx - время накопленное сек
#define internal1_m2444_y0	BUFFER[8507]	// (internal1_m2444_y0) y0
#define idinternal1_m2444_y0	1493	// (internal1_m2444_y0) y0
#define internal1_m2446_tx	BUFFER[8509]	// (internal1_m2446_tx) tx - внутренний параметр
#define idinternal1_m2446_tx	1494	// (internal1_m2446_tx) tx - внутренний параметр
#define internal1_m2449_q0	BUFFER[8514]	// (internal1_m2449_q0) q0 - внутренний параметр
#define idinternal1_m2449_q0	1495	// (internal1_m2449_q0) q0 - внутренний параметр
#define internal1_m2461_tx	BUFFER[8516]	// (internal1_m2461_tx) tx - внутренний параметр
#define idinternal1_m2461_tx	1496	// (internal1_m2461_tx) tx - внутренний параметр
#define internal1_m2465_tx	BUFFER[8521]	// (internal1_m2465_tx) tx - внутренний параметр
#define idinternal1_m2465_tx	1497	// (internal1_m2465_tx) tx - внутренний параметр
#define internal1_m2466_tx	BUFFER[8526]	// (internal1_m2466_tx) tx - внутренний параметр
#define idinternal1_m2466_tx	1498	// (internal1_m2466_tx) tx - внутренний параметр
#define internal1_m2467_tx	BUFFER[8531]	// (internal1_m2467_tx) tx - внутренний параметр
#define idinternal1_m2467_tx	1499	// (internal1_m2467_tx) tx - внутренний параметр
#define internal1_m247_tx	BUFFER[8536]	// (internal1_m247_tx) tx - внутренний параметр
#define idinternal1_m247_tx	1500	// (internal1_m247_tx) tx - внутренний параметр
#define internal1_m248_tx	BUFFER[8541]	// (internal1_m248_tx) tx - внутренний параметр
#define idinternal1_m248_tx	1501	// (internal1_m248_tx) tx - внутренний параметр
#define internal1_m257_tx	BUFFER[8546]	// (internal1_m257_tx) tx - внутренний параметр
#define idinternal1_m257_tx	1502	// (internal1_m257_tx) tx - внутренний параметр
#define internal1_m260_tx	BUFFER[8551]	// (internal1_m260_tx) tx - внутренний параметр
#define idinternal1_m260_tx	1503	// (internal1_m260_tx) tx - внутренний параметр
#define internal1_m265_tx	BUFFER[8556]	// (internal1_m265_tx) tx - внутренний параметр
#define idinternal1_m265_tx	1504	// (internal1_m265_tx) tx - внутренний параметр
#define internal1_m26_q0	BUFFER[8561]	// (internal1_m26_q0) q0 - внутренний параметр
#define idinternal1_m26_q0	1505	// (internal1_m26_q0) q0 - внутренний параметр
#define internal1_m272_tx	BUFFER[8563]	// (internal1_m272_tx) tx - внутренний параметр
#define idinternal1_m272_tx	1506	// (internal1_m272_tx) tx - внутренний параметр
#define internal1_m275_tx	BUFFER[8568]	// (internal1_m275_tx) tx - внутренний параметр
#define idinternal1_m275_tx	1507	// (internal1_m275_tx) tx - внутренний параметр
#define internal1_m276_tx	BUFFER[8573]	// (internal1_m276_tx) tx - внутренний параметр
#define idinternal1_m276_tx	1508	// (internal1_m276_tx) tx - внутренний параметр
#define internal1_m278_tx	BUFFER[8578]	// (internal1_m278_tx) tx - внутренний параметр
#define idinternal1_m278_tx	1509	// (internal1_m278_tx) tx - внутренний параметр
#define internal1_m279_tx	BUFFER[8583]	// (internal1_m279_tx) tx - внутренний параметр
#define idinternal1_m279_tx	1510	// (internal1_m279_tx) tx - внутренний параметр
#define internal1_m300_ErrPr0	BUFFER[8588]	// (internal1_m300_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m300_ErrPr0	1511	// (internal1_m300_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m300_FinPr0	BUFFER[8590]	// (internal1_m300_FinPr0) FinPr - конец программы
#define idinternal1_m300_FinPr0	1512	// (internal1_m300_FinPr0) FinPr - конец программы
#define internal1_m300_MyFirstEnterFlag	BUFFER[8592]	// (internal1_m300_MyFirstEnterFlag)  
#define idinternal1_m300_MyFirstEnterFlag	1513	// (internal1_m300_MyFirstEnterFlag)  
#define internal1_m300_Step	BUFFER[8594]	// (internal1_m300_Step)  - текущий шаг программы
#define idinternal1_m300_Step	1514	// (internal1_m300_Step)  - текущий шаг программы
#define internal1_m300_TimS	BUFFER[8597]	// (internal1_m300_TimS) Время от старта программы
#define idinternal1_m300_TimS	1515	// (internal1_m300_TimS) Время от старта программы
#define internal1_m300_rz	BUFFER[8602]	// (internal1_m300_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m300_rz	1516	// (internal1_m300_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m300_sb2UR0	BUFFER[8622]	// (internal1_m300_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m300_sb2UR0	1517	// (internal1_m300_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m300_sbINI0	BUFFER[8624]	// (internal1_m300_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m300_sbINI0	1518	// (internal1_m300_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m300_sbNupIS0	BUFFER[8626]	// (internal1_m300_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m300_sbNupIS0	1519	// (internal1_m300_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m300_sbVuIS0	BUFFER[8628]	// (internal1_m300_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m300_sbVuIS0	1520	// (internal1_m300_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m300_sbVuRB0	BUFFER[8630]	// (internal1_m300_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m300_sbVuRB0	1521	// (internal1_m300_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m311_q0	BUFFER[8632]	// (internal1_m311_q0) q0 - внутренний параметр
#define idinternal1_m311_q0	1522	// (internal1_m311_q0) q0 - внутренний параметр
#define internal1_m319_x0	BUFFER[8634]	// (internal1_m319_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m319_x0	1523	// (internal1_m319_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m320_q0	BUFFER[8639]	// (internal1_m320_q0) q0 - внутренний параметр
#define idinternal1_m320_q0	1524	// (internal1_m320_q0) q0 - внутренний параметр
#define internal1_m323_tx	BUFFER[8641]	// (internal1_m323_tx) tx - внутренний параметр
#define idinternal1_m323_tx	1525	// (internal1_m323_tx) tx - внутренний параметр
#define internal1_m325_TimS	BUFFER[8646]	// (internal1_m325_TimS) Время до нулевого отсчета
#define idinternal1_m325_TimS	1526	// (internal1_m325_TimS) Время до нулевого отсчета
#define internal1_m325_pusk0	BUFFER[8651]	// (internal1_m325_pusk0) pusk - разрешение выполнения программы
#define idinternal1_m325_pusk0	1527	// (internal1_m325_pusk0) pusk - разрешение выполнения программы
#define internal1_m341_tx	BUFFER[8653]	// (internal1_m341_tx) tx - время накопленное сек
#define idinternal1_m341_tx	1528	// (internal1_m341_tx) tx - время накопленное сек
#define internal1_m341_y0	BUFFER[8658]	// (internal1_m341_y0) y0
#define idinternal1_m341_y0	1529	// (internal1_m341_y0) y0
#define internal1_m358_ErrPr0	BUFFER[8660]	// (internal1_m358_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m358_ErrPr0	1530	// (internal1_m358_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m358_FinPr0	BUFFER[8662]	// (internal1_m358_FinPr0) FinPr - конец программы
#define idinternal1_m358_FinPr0	1531	// (internal1_m358_FinPr0) FinPr - конец программы
#define internal1_m358_MyFirstEnterFlag	BUFFER[8664]	// (internal1_m358_MyFirstEnterFlag)  
#define idinternal1_m358_MyFirstEnterFlag	1532	// (internal1_m358_MyFirstEnterFlag)  
#define internal1_m358_Step	BUFFER[8666]	// (internal1_m358_Step)  - текущий шаг программы
#define idinternal1_m358_Step	1533	// (internal1_m358_Step)  - текущий шаг программы
#define internal1_m358_TimS	BUFFER[8669]	// (internal1_m358_TimS) Время от старта программы
#define idinternal1_m358_TimS	1534	// (internal1_m358_TimS) Время от старта программы
#define internal1_m358_rz	BUFFER[8674]	// (internal1_m358_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m358_rz	1535	// (internal1_m358_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m358_sb2UR0	BUFFER[8694]	// (internal1_m358_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m358_sb2UR0	1536	// (internal1_m358_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m358_sbINI0	BUFFER[8696]	// (internal1_m358_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m358_sbINI0	1537	// (internal1_m358_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m358_sbNupIS0	BUFFER[8698]	// (internal1_m358_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m358_sbNupIS0	1538	// (internal1_m358_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m358_sbVuIS0	BUFFER[8700]	// (internal1_m358_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m358_sbVuIS0	1539	// (internal1_m358_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m358_sbVuRB0	BUFFER[8702]	// (internal1_m358_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m358_sbVuRB0	1540	// (internal1_m358_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m364_q0	BUFFER[8704]	// (internal1_m364_q0) q0 - внутренний параметр
#define idinternal1_m364_q0	1541	// (internal1_m364_q0) q0 - внутренний параметр
#define internal1_m366_x0	BUFFER[8706]	// (internal1_m366_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m366_x0	1542	// (internal1_m366_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m368_q0	BUFFER[8711]	// (internal1_m368_q0) q0 - внутренний параметр
#define idinternal1_m368_q0	1543	// (internal1_m368_q0) q0 - внутренний параметр
#define internal1_m370_tx	BUFFER[8713]	// (internal1_m370_tx) tx - внутренний параметр
#define idinternal1_m370_tx	1544	// (internal1_m370_tx) tx - внутренний параметр
#define internal1_m392_BlDv0	BUFFER[8718]	// (internal1_m392_BlDv0) - была блокировка
#define idinternal1_m392_BlDv0	1545	// (internal1_m392_BlDv0) - была блокировка
#define internal1_m392_DvDw0	BUFFER[8720]	// (internal1_m392_DvDw0) - есть команда на движение назад
#define idinternal1_m392_DvDw0	1546	// (internal1_m392_DvDw0) - есть команда на движение назад
#define internal1_m392_DvUp0	BUFFER[8722]	// (internal1_m392_DvUp0) - есть команда на движение вперёд
#define idinternal1_m392_DvUp0	1547	// (internal1_m392_DvUp0) - есть команда на движение вперёд
#define internal1_m392_FDvDw0	BUFFER[8724]	// (internal1_m392_FDvDw0) - есть команда на движение назад
#define idinternal1_m392_FDvDw0	1548	// (internal1_m392_FDvDw0) - есть команда на движение назад
#define internal1_m392_FDvUp0	BUFFER[8726]	// (internal1_m392_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m392_FDvUp0	1549	// (internal1_m392_FDvUp0) - есть команда на движение вперёд
#define internal1_m392_Pkav0	BUFFER[8728]	// (internal1_m392_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m392_Pkav0	1550	// (internal1_m392_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m392_Pkv0	BUFFER[8730]	// (internal1_m392_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m392_Pkv0	1551	// (internal1_m392_Pkv0) Pkv - передний конечный выключатель
#define internal1_m392_Zkav0	BUFFER[8732]	// (internal1_m392_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m392_Zkav0	1552	// (internal1_m392_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m392_Zkv0	BUFFER[8734]	// (internal1_m392_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m392_Zkv0	1553	// (internal1_m392_Zkv0) Zkv - задний конечный выключатель
#define internal1_m392_fef	BUFFER[8736]	// (internal1_m392_fef) fef
#define idinternal1_m392_fef	1554	// (internal1_m392_fef) fef
#define internal1_m392_txHr	BUFFER[8738]	// (internal1_m392_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m392_txHr	1555	// (internal1_m392_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m392_txLd	BUFFER[8743]	// (internal1_m392_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m392_txLd	1556	// (internal1_m392_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m392_txNm	BUFFER[8748]	// (internal1_m392_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m392_txNm	1557	// (internal1_m392_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m392_txSm	BUFFER[8753]	// (internal1_m392_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m392_txSm	1558	// (internal1_m392_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m397_tx	BUFFER[8758]	// (internal1_m397_tx) tx - внутренний параметр
#define idinternal1_m397_tx	1559	// (internal1_m397_tx) tx - внутренний параметр
#define internal1_m398_tx	BUFFER[8763]	// (internal1_m398_tx) tx - внутренний параметр
#define idinternal1_m398_tx	1560	// (internal1_m398_tx) tx - внутренний параметр
#define internal1_m399_tx	BUFFER[8768]	// (internal1_m399_tx) tx - внутренний параметр
#define idinternal1_m399_tx	1561	// (internal1_m399_tx) tx - внутренний параметр
#define internal1_m400_tx	BUFFER[8773]	// (internal1_m400_tx) tx - внутренний параметр
#define idinternal1_m400_tx	1562	// (internal1_m400_tx) tx - внутренний параметр
#define internal1_m412_tx	BUFFER[8778]	// (internal1_m412_tx) tx - внутренний параметр
#define idinternal1_m412_tx	1563	// (internal1_m412_tx) tx - внутренний параметр
#define internal1_m413_tx	BUFFER[8783]	// (internal1_m413_tx) tx - внутренний параметр
#define idinternal1_m413_tx	1564	// (internal1_m413_tx) tx - внутренний параметр
#define internal1_m414_tx	BUFFER[8788]	// (internal1_m414_tx) tx - внутренний параметр
#define idinternal1_m414_tx	1565	// (internal1_m414_tx) tx - внутренний параметр
#define internal1_m417_tx	BUFFER[8793]	// (internal1_m417_tx) tx - внутренний параметр
#define idinternal1_m417_tx	1566	// (internal1_m417_tx) tx - внутренний параметр
#define internal1_m423_BlDv0	BUFFER[8798]	// (internal1_m423_BlDv0) - была блокировка
#define idinternal1_m423_BlDv0	1567	// (internal1_m423_BlDv0) - была блокировка
#define internal1_m423_DvDw0	BUFFER[8800]	// (internal1_m423_DvDw0) - есть команда на движение назад
#define idinternal1_m423_DvDw0	1568	// (internal1_m423_DvDw0) - есть команда на движение назад
#define internal1_m423_DvUp0	BUFFER[8802]	// (internal1_m423_DvUp0) - есть команда на движение вперёд
#define idinternal1_m423_DvUp0	1569	// (internal1_m423_DvUp0) - есть команда на движение вперёд
#define internal1_m423_FDvDw0	BUFFER[8804]	// (internal1_m423_FDvDw0) - есть команда на движение назад
#define idinternal1_m423_FDvDw0	1570	// (internal1_m423_FDvDw0) - есть команда на движение назад
#define internal1_m423_FDvUp0	BUFFER[8806]	// (internal1_m423_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m423_FDvUp0	1571	// (internal1_m423_FDvUp0) - есть команда на движение вперёд
#define internal1_m423_Pkav0	BUFFER[8808]	// (internal1_m423_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m423_Pkav0	1572	// (internal1_m423_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m423_Pkv0	BUFFER[8810]	// (internal1_m423_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m423_Pkv0	1573	// (internal1_m423_Pkv0) Pkv - передний конечный выключатель
#define internal1_m423_Zkav0	BUFFER[8812]	// (internal1_m423_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m423_Zkav0	1574	// (internal1_m423_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m423_Zkv0	BUFFER[8814]	// (internal1_m423_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m423_Zkv0	1575	// (internal1_m423_Zkv0) Zkv - задний конечный выключатель
#define internal1_m423_fef	BUFFER[8816]	// (internal1_m423_fef) fef
#define idinternal1_m423_fef	1576	// (internal1_m423_fef) fef
#define internal1_m423_txHr	BUFFER[8818]	// (internal1_m423_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m423_txHr	1577	// (internal1_m423_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m423_txLd	BUFFER[8823]	// (internal1_m423_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m423_txLd	1578	// (internal1_m423_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m423_txNm	BUFFER[8828]	// (internal1_m423_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m423_txNm	1579	// (internal1_m423_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m423_txSm	BUFFER[8833]	// (internal1_m423_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m423_txSm	1580	// (internal1_m423_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m429_BlDv0	BUFFER[8838]	// (internal1_m429_BlDv0) - была блокировка
#define idinternal1_m429_BlDv0	1581	// (internal1_m429_BlDv0) - была блокировка
#define internal1_m429_DvDw0	BUFFER[8840]	// (internal1_m429_DvDw0) - есть команда на движение назад
#define idinternal1_m429_DvDw0	1582	// (internal1_m429_DvDw0) - есть команда на движение назад
#define internal1_m429_DvUp0	BUFFER[8842]	// (internal1_m429_DvUp0) - есть команда на движение вперёд
#define idinternal1_m429_DvUp0	1583	// (internal1_m429_DvUp0) - есть команда на движение вперёд
#define internal1_m429_FDvDw0	BUFFER[8844]	// (internal1_m429_FDvDw0) - есть команда на движение назад
#define idinternal1_m429_FDvDw0	1584	// (internal1_m429_FDvDw0) - есть команда на движение назад
#define internal1_m429_FDvUp0	BUFFER[8846]	// (internal1_m429_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m429_FDvUp0	1585	// (internal1_m429_FDvUp0) - есть команда на движение вперёд
#define internal1_m429_Pkav0	BUFFER[8848]	// (internal1_m429_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m429_Pkav0	1586	// (internal1_m429_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m429_Pkv0	BUFFER[8850]	// (internal1_m429_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m429_Pkv0	1587	// (internal1_m429_Pkv0) Pkv - передний конечный выключатель
#define internal1_m429_Zkav0	BUFFER[8852]	// (internal1_m429_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m429_Zkav0	1588	// (internal1_m429_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m429_Zkv0	BUFFER[8854]	// (internal1_m429_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m429_Zkv0	1589	// (internal1_m429_Zkv0) Zkv - задний конечный выключатель
#define internal1_m429_fef	BUFFER[8856]	// (internal1_m429_fef) fef
#define idinternal1_m429_fef	1590	// (internal1_m429_fef) fef
#define internal1_m429_txHr	BUFFER[8858]	// (internal1_m429_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m429_txHr	1591	// (internal1_m429_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m429_txLd	BUFFER[8863]	// (internal1_m429_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m429_txLd	1592	// (internal1_m429_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m429_txNm	BUFFER[8868]	// (internal1_m429_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m429_txNm	1593	// (internal1_m429_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m429_txSm	BUFFER[8873]	// (internal1_m429_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m429_txSm	1594	// (internal1_m429_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m433_tx	BUFFER[8878]	// (internal1_m433_tx) tx - внутренний параметр
#define idinternal1_m433_tx	1595	// (internal1_m433_tx) tx - внутренний параметр
#define internal1_m439_tx	BUFFER[8883]	// (internal1_m439_tx) tx - внутренний параметр
#define idinternal1_m439_tx	1596	// (internal1_m439_tx) tx - внутренний параметр
#define internal1_m440_tx	BUFFER[8888]	// (internal1_m440_tx) tx - внутренний параметр
#define idinternal1_m440_tx	1597	// (internal1_m440_tx) tx - внутренний параметр
#define internal1_m441_tx	BUFFER[8893]	// (internal1_m441_tx) tx - внутренний параметр
#define idinternal1_m441_tx	1598	// (internal1_m441_tx) tx - внутренний параметр
#define internal1_m450_tx	BUFFER[8898]	// (internal1_m450_tx) tx - внутренний параметр
#define idinternal1_m450_tx	1599	// (internal1_m450_tx) tx - внутренний параметр
#define internal1_m451_tx	BUFFER[8903]	// (internal1_m451_tx) tx - внутренний параметр
#define idinternal1_m451_tx	1600	// (internal1_m451_tx) tx - внутренний параметр
#define internal1_m453_tx	BUFFER[8908]	// (internal1_m453_tx) tx - внутренний параметр
#define idinternal1_m453_tx	1601	// (internal1_m453_tx) tx - внутренний параметр
#define internal1_m459_tx	BUFFER[8913]	// (internal1_m459_tx) tx - внутренний параметр
#define idinternal1_m459_tx	1602	// (internal1_m459_tx) tx - внутренний параметр
#define internal1_m467_tx	BUFFER[8918]	// (internal1_m467_tx) tx - внутренний параметр
#define idinternal1_m467_tx	1603	// (internal1_m467_tx) tx - внутренний параметр
#define internal1_m476_tx	BUFFER[8923]	// (internal1_m476_tx) tx - внутренний параметр
#define idinternal1_m476_tx	1604	// (internal1_m476_tx) tx - внутренний параметр
#define internal1_m478_tx	BUFFER[8928]	// (internal1_m478_tx) tx - внутренний параметр
#define idinternal1_m478_tx	1605	// (internal1_m478_tx) tx - внутренний параметр
#define internal1_m480_tx	BUFFER[8933]	// (internal1_m480_tx) tx - внутренний параметр
#define idinternal1_m480_tx	1606	// (internal1_m480_tx) tx - внутренний параметр
#define internal1_m482_tx	BUFFER[8938]	// (internal1_m482_tx) tx - внутренний параметр
#define idinternal1_m482_tx	1607	// (internal1_m482_tx) tx - внутренний параметр
#define internal1_m487_tx	BUFFER[8943]	// (internal1_m487_tx) tx - внутренний параметр
#define idinternal1_m487_tx	1608	// (internal1_m487_tx) tx - внутренний параметр
#define internal1_m502_tx	BUFFER[8948]	// (internal1_m502_tx) tx - внутренний параметр
#define idinternal1_m502_tx	1609	// (internal1_m502_tx) tx - внутренний параметр
#define internal1_m503_tx	BUFFER[8953]	// (internal1_m503_tx) tx - внутренний параметр
#define idinternal1_m503_tx	1610	// (internal1_m503_tx) tx - внутренний параметр
#define internal1_m504_tx	BUFFER[8958]	// (internal1_m504_tx) tx - внутренний параметр
#define idinternal1_m504_tx	1611	// (internal1_m504_tx) tx - внутренний параметр
#define internal1_m505_tx	BUFFER[8963]	// (internal1_m505_tx) tx - внутренний параметр
#define idinternal1_m505_tx	1612	// (internal1_m505_tx) tx - внутренний параметр
#define internal1_m513_BlDv0	BUFFER[8968]	// (internal1_m513_BlDv0) - была блокировка
#define idinternal1_m513_BlDv0	1613	// (internal1_m513_BlDv0) - была блокировка
#define internal1_m513_DvDw0	BUFFER[8970]	// (internal1_m513_DvDw0) - есть команда на движение назад
#define idinternal1_m513_DvDw0	1614	// (internal1_m513_DvDw0) - есть команда на движение назад
#define internal1_m513_DvUp0	BUFFER[8972]	// (internal1_m513_DvUp0) - есть команда на движение вперёд
#define idinternal1_m513_DvUp0	1615	// (internal1_m513_DvUp0) - есть команда на движение вперёд
#define internal1_m513_FDvDw0	BUFFER[8974]	// (internal1_m513_FDvDw0) - есть команда на движение назад
#define idinternal1_m513_FDvDw0	1616	// (internal1_m513_FDvDw0) - есть команда на движение назад
#define internal1_m513_FDvUp0	BUFFER[8976]	// (internal1_m513_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m513_FDvUp0	1617	// (internal1_m513_FDvUp0) - есть команда на движение вперёд
#define internal1_m513_Pkav0	BUFFER[8978]	// (internal1_m513_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m513_Pkav0	1618	// (internal1_m513_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m513_Pkv0	BUFFER[8980]	// (internal1_m513_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m513_Pkv0	1619	// (internal1_m513_Pkv0) Pkv - передний конечный выключатель
#define internal1_m513_Zkav0	BUFFER[8982]	// (internal1_m513_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m513_Zkav0	1620	// (internal1_m513_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m513_Zkv0	BUFFER[8984]	// (internal1_m513_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m513_Zkv0	1621	// (internal1_m513_Zkv0) Zkv - задний конечный выключатель
#define internal1_m513_fef	BUFFER[8986]	// (internal1_m513_fef) fef
#define idinternal1_m513_fef	1622	// (internal1_m513_fef) fef
#define internal1_m513_txHr	BUFFER[8988]	// (internal1_m513_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m513_txHr	1623	// (internal1_m513_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m513_txLd	BUFFER[8993]	// (internal1_m513_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m513_txLd	1624	// (internal1_m513_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m513_txNm	BUFFER[8998]	// (internal1_m513_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m513_txNm	1625	// (internal1_m513_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m513_txSm	BUFFER[9003]	// (internal1_m513_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m513_txSm	1626	// (internal1_m513_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m519_BlDv0	BUFFER[9008]	// (internal1_m519_BlDv0) - была блокировка
#define idinternal1_m519_BlDv0	1627	// (internal1_m519_BlDv0) - была блокировка
#define internal1_m519_DvDw0	BUFFER[9010]	// (internal1_m519_DvDw0) - есть команда на движение назад
#define idinternal1_m519_DvDw0	1628	// (internal1_m519_DvDw0) - есть команда на движение назад
#define internal1_m519_DvUp0	BUFFER[9012]	// (internal1_m519_DvUp0) - есть команда на движение вперёд
#define idinternal1_m519_DvUp0	1629	// (internal1_m519_DvUp0) - есть команда на движение вперёд
#define internal1_m519_FDvDw0	BUFFER[9014]	// (internal1_m519_FDvDw0) - есть команда на движение назад
#define idinternal1_m519_FDvDw0	1630	// (internal1_m519_FDvDw0) - есть команда на движение назад
#define internal1_m519_FDvUp0	BUFFER[9016]	// (internal1_m519_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m519_FDvUp0	1631	// (internal1_m519_FDvUp0) - есть команда на движение вперёд
#define internal1_m519_Pkav0	BUFFER[9018]	// (internal1_m519_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m519_Pkav0	1632	// (internal1_m519_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m519_Pkv0	BUFFER[9020]	// (internal1_m519_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m519_Pkv0	1633	// (internal1_m519_Pkv0) Pkv - передний конечный выключатель
#define internal1_m519_Zkav0	BUFFER[9022]	// (internal1_m519_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m519_Zkav0	1634	// (internal1_m519_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m519_Zkv0	BUFFER[9024]	// (internal1_m519_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m519_Zkv0	1635	// (internal1_m519_Zkv0) Zkv - задний конечный выключатель
#define internal1_m519_fef	BUFFER[9026]	// (internal1_m519_fef) fef
#define idinternal1_m519_fef	1636	// (internal1_m519_fef) fef
#define internal1_m519_txHr	BUFFER[9028]	// (internal1_m519_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m519_txHr	1637	// (internal1_m519_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m519_txLd	BUFFER[9033]	// (internal1_m519_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m519_txLd	1638	// (internal1_m519_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m519_txNm	BUFFER[9038]	// (internal1_m519_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m519_txNm	1639	// (internal1_m519_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m519_txSm	BUFFER[9043]	// (internal1_m519_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m519_txSm	1640	// (internal1_m519_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m527_tx	BUFFER[9048]	// (internal1_m527_tx) tx - внутренний параметр
#define idinternal1_m527_tx	1641	// (internal1_m527_tx) tx - внутренний параметр
#define internal1_m52_tx	BUFFER[9053]	// (internal1_m52_tx) tx - внутренний параметр
#define idinternal1_m52_tx	1642	// (internal1_m52_tx) tx - внутренний параметр
#define internal1_m531_tx	BUFFER[9058]	// (internal1_m531_tx) tx - внутренний параметр
#define idinternal1_m531_tx	1643	// (internal1_m531_tx) tx - внутренний параметр
#define internal1_m532_tx	BUFFER[9063]	// (internal1_m532_tx) tx - внутренний параметр
#define idinternal1_m532_tx	1644	// (internal1_m532_tx) tx - внутренний параметр
#define internal1_m533_tx	BUFFER[9068]	// (internal1_m533_tx) tx - внутренний параметр
#define idinternal1_m533_tx	1645	// (internal1_m533_tx) tx - внутренний параметр
#define internal1_m54_tim	BUFFER[9073]	// (internal1_m54_tim) - время задержки выходного сигнала
#define idinternal1_m54_tim	1646	// (internal1_m54_tim) - время задержки выходного сигнала
#define internal1_m54_x0	BUFFER[9078]	// (internal1_m54_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m54_x0	1647	// (internal1_m54_x0) - значение входного параметра на предыдущем шаге
#define internal1_m552_BLDv0	BUFFER[9080]	// (internal1_m552_BLDv0) BlDv - Блокировка движения
#define idinternal1_m552_BLDv0	1648	// (internal1_m552_BLDv0) BlDv - Блокировка движения
#define internal1_m552_X0	BUFFER[9082]	// (internal1_m552_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m552_X0	1649	// (internal1_m552_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m552_t0	BUFFER[9087]	// (internal1_m552_t0) время нахождения в зоне возврата
#define idinternal1_m552_t0	1650	// (internal1_m552_t0) время нахождения в зоне возврата
#define internal1_m570_tx	BUFFER[9092]	// (internal1_m570_tx) tx - время накопленное сек
#define idinternal1_m570_tx	1651	// (internal1_m570_tx) tx - время накопленное сек
#define internal1_m570_y0	BUFFER[9097]	// (internal1_m570_y0) y0
#define idinternal1_m570_y0	1652	// (internal1_m570_y0) y0
#define internal1_m571_tx	BUFFER[9099]	// (internal1_m571_tx) tx - время накопленное сек
#define idinternal1_m571_tx	1653	// (internal1_m571_tx) tx - время накопленное сек
#define internal1_m571_y0	BUFFER[9104]	// (internal1_m571_y0) y0
#define idinternal1_m571_y0	1654	// (internal1_m571_y0) y0
#define internal1_m575_DelSp	BUFFER[9106]	// (internal1_m575_DelSp) DelSp - время переключения скоростей
#define idinternal1_m575_DelSp	1655	// (internal1_m575_DelSp) DelSp - время переключения скоростей
#define internal1_m575_ShCntlSp0	BUFFER[9111]	// (internal1_m575_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m575_ShCntlSp0	1656	// (internal1_m575_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m575_Shift0	BUFFER[9113]	// (internal1_m575_Shift0) Shift0 - признак самохода
#define idinternal1_m575_Shift0	1657	// (internal1_m575_Shift0) Shift0 - признак самохода
#define internal1_m575_ShiftControl	BUFFER[9115]	// (internal1_m575_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m575_ShiftControl	1658	// (internal1_m575_ShiftControl) ShiftControl - признак самохода
#define internal1_m575_Speed0	BUFFER[9117]	// (internal1_m575_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m575_Speed0	1659	// (internal1_m575_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m575_StSpeed	BUFFER[9122]	// (internal1_m575_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m575_StSpeed	1660	// (internal1_m575_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m575_Vz0	BUFFER[9127]	// (internal1_m575_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m575_Vz0	1661	// (internal1_m575_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m575_flRazg	BUFFER[9132]	// (internal1_m575_flRazg) признак разгона/торможения
#define idinternal1_m575_flRazg	1662	// (internal1_m575_flRazg) признак разгона/торможения
#define internal1_m575_sumtim	BUFFER[9135]	// (internal1_m575_sumtim) sumtim - время в пути
#define idinternal1_m575_sumtim	1663	// (internal1_m575_sumtim) sumtim - время в пути
#define internal1_m575_tim0	BUFFER[9140]	// (internal1_m575_tim0) tim0 - массив значений времени цикла
#define idinternal1_m575_tim0	1664	// (internal1_m575_tim0) tim0 - массив значений времени цикла
#define internal1_m575_tx	BUFFER[9890]	// (internal1_m575_tx) tx
#define idinternal1_m575_tx	1665	// (internal1_m575_tx) tx
#define internal1_m575_txBl	BUFFER[9895]	// (internal1_m575_txBl) tx
#define idinternal1_m575_txBl	1666	// (internal1_m575_txBl) tx
#define internal1_m575_txMBl	BUFFER[9900]	// (internal1_m575_txMBl) tx
#define idinternal1_m575_txMBl	1667	// (internal1_m575_txMBl) tx
#define internal1_m575_txZS	BUFFER[9905]	// (internal1_m575_txZS) txZS
#define idinternal1_m575_txZS	1668	// (internal1_m575_txZS) txZS
#define internal1_m575_txd	BUFFER[9910]	// (internal1_m575_txd) txd
#define idinternal1_m575_txd	1669	// (internal1_m575_txd) txd
#define internal1_m575_tz0	BUFFER[9915]	// (internal1_m575_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m575_tz0	1670	// (internal1_m575_tz0) tz0 - время защиты от нового задания сек
#define internal1_m575_x0	BUFFER[9920]	// (internal1_m575_x0) x0 - массив мгновенных значений координат
#define idinternal1_m575_x0	1671	// (internal1_m575_x0) x0 - массив мгновенных значений координат
#define internal1_m575_xptr	BUFFER[10670]	// (internal1_m575_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m575_xptr	1672	// (internal1_m575_xptr) указатель текущей позиции в массиве координат
#define internal1_m575_xz0	BUFFER[10673]	// (internal1_m575_xz0) xz0 - новое задание мм
#define idinternal1_m575_xz0	1673	// (internal1_m575_xz0) xz0 - новое задание мм
#define internal1_m575_z0	BUFFER[10678]	// (internal1_m575_z0) z0 - точка прекращения движения
#define idinternal1_m575_z0	1674	// (internal1_m575_z0) z0 - точка прекращения движения
#define internal1_m576_tx	BUFFER[10683]	// (internal1_m576_tx) tx - внутренний параметр
#define idinternal1_m576_tx	1675	// (internal1_m576_tx) tx - внутренний параметр
#define internal1_m577_tx	BUFFER[10688]	// (internal1_m577_tx) tx - внутренний параметр
#define idinternal1_m577_tx	1676	// (internal1_m577_tx) tx - внутренний параметр
#define internal1_m578_tx	BUFFER[10693]	// (internal1_m578_tx) tx - внутренний параметр
#define idinternal1_m578_tx	1677	// (internal1_m578_tx) tx - внутренний параметр
#define internal1_m583_tx	BUFFER[10698]	// (internal1_m583_tx) tx - внутренний параметр
#define idinternal1_m583_tx	1678	// (internal1_m583_tx) tx - внутренний параметр
#define internal1_m590_tx	BUFFER[10703]	// (internal1_m590_tx) tx - время накопленное сек
#define idinternal1_m590_tx	1679	// (internal1_m590_tx) tx - время накопленное сек
#define internal1_m590_y0	BUFFER[10708]	// (internal1_m590_y0) y0
#define idinternal1_m590_y0	1680	// (internal1_m590_y0) y0
#define internal1_m596_tx	BUFFER[10710]	// (internal1_m596_tx) tx - внутренний параметр
#define idinternal1_m596_tx	1681	// (internal1_m596_tx) tx - внутренний параметр
#define internal1_m598_tx	BUFFER[10715]	// (internal1_m598_tx) tx - внутренний параметр
#define idinternal1_m598_tx	1682	// (internal1_m598_tx) tx - внутренний параметр
#define internal1_m600_tx	BUFFER[10720]	// (internal1_m600_tx) tx - внутренний параметр
#define idinternal1_m600_tx	1683	// (internal1_m600_tx) tx - внутренний параметр
#define internal1_m609_tx	BUFFER[10725]	// (internal1_m609_tx) tx - внутренний параметр
#define idinternal1_m609_tx	1684	// (internal1_m609_tx) tx - внутренний параметр
#define internal1_m613_tx	BUFFER[10730]	// (internal1_m613_tx) tx - внутренний параметр
#define idinternal1_m613_tx	1685	// (internal1_m613_tx) tx - внутренний параметр
#define internal1_m614_tx	BUFFER[10735]	// (internal1_m614_tx) tx - внутренний параметр
#define idinternal1_m614_tx	1686	// (internal1_m614_tx) tx - внутренний параметр
#define internal1_m624_tx	BUFFER[10740]	// (internal1_m624_tx) tx - внутренний параметр
#define idinternal1_m624_tx	1687	// (internal1_m624_tx) tx - внутренний параметр
#define internal1_m628_tx	BUFFER[10745]	// (internal1_m628_tx) tx - внутренний параметр
#define idinternal1_m628_tx	1688	// (internal1_m628_tx) tx - внутренний параметр
#define internal1_m630_tx	BUFFER[10750]	// (internal1_m630_tx) tx - внутренний параметр
#define idinternal1_m630_tx	1689	// (internal1_m630_tx) tx - внутренний параметр
#define internal1_m637_tx	BUFFER[10755]	// (internal1_m637_tx) tx - внутренний параметр
#define idinternal1_m637_tx	1690	// (internal1_m637_tx) tx - внутренний параметр
#define internal1_m638_tx	BUFFER[10760]	// (internal1_m638_tx) tx - внутренний параметр
#define idinternal1_m638_tx	1691	// (internal1_m638_tx) tx - внутренний параметр
#define internal1_m639_tx	BUFFER[10765]	// (internal1_m639_tx) tx - внутренний параметр
#define idinternal1_m639_tx	1692	// (internal1_m639_tx) tx - внутренний параметр
#define internal1_m641_tx	BUFFER[10770]	// (internal1_m641_tx) tx - внутренний параметр
#define idinternal1_m641_tx	1693	// (internal1_m641_tx) tx - внутренний параметр
#define internal1_m642_tx	BUFFER[10775]	// (internal1_m642_tx) tx - внутренний параметр
#define idinternal1_m642_tx	1694	// (internal1_m642_tx) tx - внутренний параметр
#define internal1_m669_q0	BUFFER[10780]	// (internal1_m669_q0) q0 - внутренний параметр
#define idinternal1_m669_q0	1695	// (internal1_m669_q0) q0 - внутренний параметр
#define internal1_m679_q0	BUFFER[10782]	// (internal1_m679_q0) q0 - внутренний параметр
#define idinternal1_m679_q0	1696	// (internal1_m679_q0) q0 - внутренний параметр
#define internal1_m689_q0	BUFFER[10784]	// (internal1_m689_q0) q0 - внутренний параметр
#define idinternal1_m689_q0	1697	// (internal1_m689_q0) q0 - внутренний параметр
#define internal1_m691_q0	BUFFER[10786]	// (internal1_m691_q0) q0 - внутренний параметр
#define idinternal1_m691_q0	1698	// (internal1_m691_q0) q0 - внутренний параметр
#define internal1_m693_q0	BUFFER[10788]	// (internal1_m693_q0) q0 - внутренний параметр
#define idinternal1_m693_q0	1699	// (internal1_m693_q0) q0 - внутренний параметр
#define internal1_m694_q0	BUFFER[10790]	// (internal1_m694_q0) q0 - внутренний параметр
#define idinternal1_m694_q0	1700	// (internal1_m694_q0) q0 - внутренний параметр
#define internal1_m696_q0	BUFFER[10792]	// (internal1_m696_q0) q0 - внутренний параметр
#define idinternal1_m696_q0	1701	// (internal1_m696_q0) q0 - внутренний параметр
#define internal1_m698_q0	BUFFER[10794]	// (internal1_m698_q0) q0 - внутренний параметр
#define idinternal1_m698_q0	1702	// (internal1_m698_q0) q0 - внутренний параметр
#define internal1_m699_q0	BUFFER[10796]	// (internal1_m699_q0) q0 - внутренний параметр
#define idinternal1_m699_q0	1703	// (internal1_m699_q0) q0 - внутренний параметр
#define internal1_m701_q0	BUFFER[10798]	// (internal1_m701_q0) q0 - внутренний параметр
#define idinternal1_m701_q0	1704	// (internal1_m701_q0) q0 - внутренний параметр
#define internal1_m704_q0	BUFFER[10800]	// (internal1_m704_q0) q0 - внутренний параметр
#define idinternal1_m704_q0	1705	// (internal1_m704_q0) q0 - внутренний параметр
#define internal1_m709_q0	BUFFER[10802]	// (internal1_m709_q0) q0 - внутренний параметр
#define idinternal1_m709_q0	1706	// (internal1_m709_q0) q0 - внутренний параметр
#define internal1_m713_q0	BUFFER[10804]	// (internal1_m713_q0) q0 - внутренний параметр
#define idinternal1_m713_q0	1707	// (internal1_m713_q0) q0 - внутренний параметр
#define internal1_m714_q0	BUFFER[10806]	// (internal1_m714_q0) q0 - внутренний параметр
#define idinternal1_m714_q0	1708	// (internal1_m714_q0) q0 - внутренний параметр
#define internal1_m722_q0	BUFFER[10808]	// (internal1_m722_q0) q0 - внутренний параметр
#define idinternal1_m722_q0	1709	// (internal1_m722_q0) q0 - внутренний параметр
#define internal1_m726_q0	BUFFER[10810]	// (internal1_m726_q0) q0 - внутренний параметр
#define idinternal1_m726_q0	1710	// (internal1_m726_q0) q0 - внутренний параметр
#define internal1_m737_tx	BUFFER[10812]	// (internal1_m737_tx) tx - внутренний параметр
#define idinternal1_m737_tx	1711	// (internal1_m737_tx) tx - внутренний параметр
#define internal1_m743_x0	BUFFER[10817]	// (internal1_m743_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m743_x0	1712	// (internal1_m743_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m744_tx	BUFFER[10819]	// (internal1_m744_tx) tx - внутренний параметр
#define idinternal1_m744_tx	1713	// (internal1_m744_tx) tx - внутренний параметр
#define internal1_m748_tx	BUFFER[10824]	// (internal1_m748_tx) tx - внутренний параметр
#define idinternal1_m748_tx	1714	// (internal1_m748_tx) tx - внутренний параметр
#define internal1_m753_tx	BUFFER[10829]	// (internal1_m753_tx) tx - внутренний параметр
#define idinternal1_m753_tx	1715	// (internal1_m753_tx) tx - внутренний параметр
#define internal1_m763_tx	BUFFER[10834]	// (internal1_m763_tx) tx - внутренний параметр
#define idinternal1_m763_tx	1716	// (internal1_m763_tx) tx - внутренний параметр
#define internal1_m768_tx	BUFFER[10839]	// (internal1_m768_tx) tx - внутренний параметр
#define idinternal1_m768_tx	1717	// (internal1_m768_tx) tx - внутренний параметр
#define internal1_m769_tx	BUFFER[10844]	// (internal1_m769_tx) tx - внутренний параметр
#define idinternal1_m769_tx	1718	// (internal1_m769_tx) tx - внутренний параметр
#define internal1_m772_tx	BUFFER[10849]	// (internal1_m772_tx) tx - внутренний параметр
#define idinternal1_m772_tx	1719	// (internal1_m772_tx) tx - внутренний параметр
#define internal1_m777_tx	BUFFER[10854]	// (internal1_m777_tx) tx - внутренний параметр
#define idinternal1_m777_tx	1720	// (internal1_m777_tx) tx - внутренний параметр
#define internal1_m779_tx	BUFFER[10859]	// (internal1_m779_tx) tx - внутренний параметр
#define idinternal1_m779_tx	1721	// (internal1_m779_tx) tx - внутренний параметр
#define internal1_m787_tx	BUFFER[10864]	// (internal1_m787_tx) tx - внутренний параметр
#define idinternal1_m787_tx	1722	// (internal1_m787_tx) tx - внутренний параметр
#define internal1_m796_tx	BUFFER[10869]	// (internal1_m796_tx) tx - внутренний параметр
#define idinternal1_m796_tx	1723	// (internal1_m796_tx) tx - внутренний параметр
#define internal1_m797_tx	BUFFER[10874]	// (internal1_m797_tx) tx - внутренний параметр
#define idinternal1_m797_tx	1724	// (internal1_m797_tx) tx - внутренний параметр
#define internal1_m798_tx	BUFFER[10879]	// (internal1_m798_tx) tx - внутренний параметр
#define idinternal1_m798_tx	1725	// (internal1_m798_tx) tx - внутренний параметр
#define internal1_m79_MyFirstEnterFlag	BUFFER[10884]	// (internal1_m79_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m79_MyFirstEnterFlag	1726	// (internal1_m79_MyFirstEnterFlag)  FirstEnterFlag
#define internal1_m79_W1	BUFFER[10886]	// (internal1_m79_W1)  мощность на старте измерения
#define idinternal1_m79_W1	1727	// (internal1_m79_W1)  мощность на старте измерения
#define internal1_m79_W2	BUFFER[10891]	// (internal1_m79_W2)  мощность в конце измерения
#define idinternal1_m79_W2	1728	// (internal1_m79_W2)  мощность в конце измерения
#define internal1_m79_Wlast	BUFFER[10896]	// (internal1_m79_Wlast)  последнее растущее измерение
#define idinternal1_m79_Wlast	1729	// (internal1_m79_Wlast)  последнее растущее измерение
#define internal1_m79_Wmax	BUFFER[10901]	// (internal1_m79_Wmax)  максимальное измерение в серии
#define idinternal1_m79_Wmax	1730	// (internal1_m79_Wmax)  максимальное измерение в серии
#define internal1_m79_Wmin	BUFFER[10906]	// (internal1_m79_Wmin)  минимальное измерение в серии
#define idinternal1_m79_Wmin	1731	// (internal1_m79_Wmin)  минимальное измерение в серии
#define internal1_m79_chizm	BUFFER[10911]	// (internal1_m79_chizm)  счетчик уменьшения мощности
#define idinternal1_m79_chizm	1732	// (internal1_m79_chizm)  счетчик уменьшения мощности
#define internal1_m79_chsr	BUFFER[10914]	// (internal1_m79_chsr)  счетчик усреднения
#define idinternal1_m79_chsr	1733	// (internal1_m79_chsr)  счетчик усреднения
#define internal1_m79_flst	BUFFER[10917]	// (internal1_m79_flst)  флаг старта измерения
#define idinternal1_m79_flst	1734	// (internal1_m79_flst)  флаг старта измерения
#define internal1_m79_sumtim	BUFFER[10920]	// (internal1_m79_sumtim)  время измерения мощности
#define idinternal1_m79_sumtim	1735	// (internal1_m79_sumtim)  время измерения мощности
#define internal1_m79_y0	BUFFER[10925]	// (internal1_m79_y0) y0 - внутренний параметр
#define idinternal1_m79_y0	1736	// (internal1_m79_y0) y0 - внутренний параметр
#define internal1_m800_x0	BUFFER[10930]	// (internal1_m800_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m800_x0	1737	// (internal1_m800_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m801_tx	BUFFER[10932]	// (internal1_m801_tx) tx - внутренний параметр
#define idinternal1_m801_tx	1738	// (internal1_m801_tx) tx - внутренний параметр
#define internal1_m820_q0	BUFFER[10937]	// (internal1_m820_q0) q0 - внутренний параметр
#define idinternal1_m820_q0	1739	// (internal1_m820_q0) q0 - внутренний параметр
#define internal1_m823_q0	BUFFER[10939]	// (internal1_m823_q0) q0 - внутренний параметр
#define idinternal1_m823_q0	1740	// (internal1_m823_q0) q0 - внутренний параметр
#define internal1_m825_q0	BUFFER[10941]	// (internal1_m825_q0) q0 - внутренний параметр
#define idinternal1_m825_q0	1741	// (internal1_m825_q0) q0 - внутренний параметр
#define internal1_m826_q0	BUFFER[10943]	// (internal1_m826_q0) q0 - внутренний параметр
#define idinternal1_m826_q0	1742	// (internal1_m826_q0) q0 - внутренний параметр
#define internal1_m829_q0	BUFFER[10945]	// (internal1_m829_q0) q0 - внутренний параметр
#define idinternal1_m829_q0	1743	// (internal1_m829_q0) q0 - внутренний параметр
#define internal1_m82_tx	BUFFER[10947]	// (internal1_m82_tx) tx - внутренний параметр
#define idinternal1_m82_tx	1744	// (internal1_m82_tx) tx - внутренний параметр
#define internal1_m832_x0	BUFFER[10952]	// (internal1_m832_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m832_x0	1745	// (internal1_m832_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m833_q0	BUFFER[10954]	// (internal1_m833_q0) q0 - внутренний параметр
#define idinternal1_m833_q0	1746	// (internal1_m833_q0) q0 - внутренний параметр
#define internal1_m836_tx	BUFFER[10956]	// (internal1_m836_tx) tx - время накопленное сек
#define idinternal1_m836_tx	1747	// (internal1_m836_tx) tx - время накопленное сек
#define internal1_m836_y0	BUFFER[10961]	// (internal1_m836_y0) y0
#define idinternal1_m836_y0	1748	// (internal1_m836_y0) y0
#define internal1_m837_tx	BUFFER[10963]	// (internal1_m837_tx) tx - внутренний параметр
#define idinternal1_m837_tx	1749	// (internal1_m837_tx) tx - внутренний параметр
#define internal1_m838_q0	BUFFER[10968]	// (internal1_m838_q0) q0 - внутренний параметр
#define idinternal1_m838_q0	1750	// (internal1_m838_q0) q0 - внутренний параметр
#define internal1_m845_q0	BUFFER[10970]	// (internal1_m845_q0) q0 - внутренний параметр
#define idinternal1_m845_q0	1751	// (internal1_m845_q0) q0 - внутренний параметр
#define internal1_m852_q0	BUFFER[10972]	// (internal1_m852_q0) q0 - внутренний параметр
#define idinternal1_m852_q0	1752	// (internal1_m852_q0) q0 - внутренний параметр
#define internal1_m857_q0	BUFFER[10974]	// (internal1_m857_q0) q0 - внутренний параметр
#define idinternal1_m857_q0	1753	// (internal1_m857_q0) q0 - внутренний параметр
#define internal1_m866_tx	BUFFER[10976]	// (internal1_m866_tx) tx - внутренний параметр
#define idinternal1_m866_tx	1754	// (internal1_m866_tx) tx - внутренний параметр
#define internal1_m867_tx	BUFFER[10981]	// (internal1_m867_tx) tx - внутренний параметр
#define idinternal1_m867_tx	1755	// (internal1_m867_tx) tx - внутренний параметр
#define internal1_m868_tx	BUFFER[10986]	// (internal1_m868_tx) tx - внутренний параметр
#define idinternal1_m868_tx	1756	// (internal1_m868_tx) tx - внутренний параметр
#define internal1_m872_tx	BUFFER[10991]	// (internal1_m872_tx) tx - внутренний параметр
#define idinternal1_m872_tx	1757	// (internal1_m872_tx) tx - внутренний параметр
#define internal1_m877_BlDv0	BUFFER[10996]	// (internal1_m877_BlDv0) - была блокировка
#define idinternal1_m877_BlDv0	1758	// (internal1_m877_BlDv0) - была блокировка
#define internal1_m877_DvDw0	BUFFER[10998]	// (internal1_m877_DvDw0) - есть команда на движение назад
#define idinternal1_m877_DvDw0	1759	// (internal1_m877_DvDw0) - есть команда на движение назад
#define internal1_m877_DvUp0	BUFFER[11000]	// (internal1_m877_DvUp0) - есть команда на движение вперёд
#define idinternal1_m877_DvUp0	1760	// (internal1_m877_DvUp0) - есть команда на движение вперёд
#define internal1_m877_FDvDw0	BUFFER[11002]	// (internal1_m877_FDvDw0) - есть команда на движение назад
#define idinternal1_m877_FDvDw0	1761	// (internal1_m877_FDvDw0) - есть команда на движение назад
#define internal1_m877_FDvUp0	BUFFER[11004]	// (internal1_m877_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m877_FDvUp0	1762	// (internal1_m877_FDvUp0) - есть команда на движение вперёд
#define internal1_m877_Pkav0	BUFFER[11006]	// (internal1_m877_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m877_Pkav0	1763	// (internal1_m877_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m877_Pkv0	BUFFER[11008]	// (internal1_m877_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m877_Pkv0	1764	// (internal1_m877_Pkv0) Pkv - передний конечный выключатель
#define internal1_m877_Zkav0	BUFFER[11010]	// (internal1_m877_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m877_Zkav0	1765	// (internal1_m877_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m877_Zkv0	BUFFER[11012]	// (internal1_m877_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m877_Zkv0	1766	// (internal1_m877_Zkv0) Zkv - задний конечный выключатель
#define internal1_m877_fef	BUFFER[11014]	// (internal1_m877_fef) fef
#define idinternal1_m877_fef	1767	// (internal1_m877_fef) fef
#define internal1_m877_txHr	BUFFER[11016]	// (internal1_m877_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m877_txHr	1768	// (internal1_m877_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m877_txLd	BUFFER[11021]	// (internal1_m877_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m877_txLd	1769	// (internal1_m877_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m877_txNm	BUFFER[11026]	// (internal1_m877_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m877_txNm	1770	// (internal1_m877_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m877_txSm	BUFFER[11031]	// (internal1_m877_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m877_txSm	1771	// (internal1_m877_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m881_BlDv0	BUFFER[11036]	// (internal1_m881_BlDv0) - была блокировка
#define idinternal1_m881_BlDv0	1772	// (internal1_m881_BlDv0) - была блокировка
#define internal1_m881_DvDw0	BUFFER[11038]	// (internal1_m881_DvDw0) - есть команда на движение назад
#define idinternal1_m881_DvDw0	1773	// (internal1_m881_DvDw0) - есть команда на движение назад
#define internal1_m881_DvUp0	BUFFER[11040]	// (internal1_m881_DvUp0) - есть команда на движение вперёд
#define idinternal1_m881_DvUp0	1774	// (internal1_m881_DvUp0) - есть команда на движение вперёд
#define internal1_m881_FDvDw0	BUFFER[11042]	// (internal1_m881_FDvDw0) - есть команда на движение назад
#define idinternal1_m881_FDvDw0	1775	// (internal1_m881_FDvDw0) - есть команда на движение назад
#define internal1_m881_FDvUp0	BUFFER[11044]	// (internal1_m881_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m881_FDvUp0	1776	// (internal1_m881_FDvUp0) - есть команда на движение вперёд
#define internal1_m881_Pkav0	BUFFER[11046]	// (internal1_m881_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m881_Pkav0	1777	// (internal1_m881_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m881_Pkv0	BUFFER[11048]	// (internal1_m881_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m881_Pkv0	1778	// (internal1_m881_Pkv0) Pkv - передний конечный выключатель
#define internal1_m881_Zkav0	BUFFER[11050]	// (internal1_m881_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m881_Zkav0	1779	// (internal1_m881_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m881_Zkv0	BUFFER[11052]	// (internal1_m881_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m881_Zkv0	1780	// (internal1_m881_Zkv0) Zkv - задний конечный выключатель
#define internal1_m881_fef	BUFFER[11054]	// (internal1_m881_fef) fef
#define idinternal1_m881_fef	1781	// (internal1_m881_fef) fef
#define internal1_m881_txHr	BUFFER[11056]	// (internal1_m881_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m881_txHr	1782	// (internal1_m881_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m881_txLd	BUFFER[11061]	// (internal1_m881_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m881_txLd	1783	// (internal1_m881_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m881_txNm	BUFFER[11066]	// (internal1_m881_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m881_txNm	1784	// (internal1_m881_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m881_txSm	BUFFER[11071]	// (internal1_m881_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m881_txSm	1785	// (internal1_m881_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m889_tx	BUFFER[11076]	// (internal1_m889_tx) tx - внутренний параметр
#define idinternal1_m889_tx	1786	// (internal1_m889_tx) tx - внутренний параметр
#define internal1_m893_tx	BUFFER[11081]	// (internal1_m893_tx) tx - внутренний параметр
#define idinternal1_m893_tx	1787	// (internal1_m893_tx) tx - внутренний параметр
#define internal1_m894_tx	BUFFER[11086]	// (internal1_m894_tx) tx - внутренний параметр
#define idinternal1_m894_tx	1788	// (internal1_m894_tx) tx - внутренний параметр
#define internal1_m895_tx	BUFFER[11091]	// (internal1_m895_tx) tx - внутренний параметр
#define idinternal1_m895_tx	1789	// (internal1_m895_tx) tx - внутренний параметр
#define internal1_m911_BLDv0	BUFFER[11096]	// (internal1_m911_BLDv0) BlDv - Блокировка движения
#define idinternal1_m911_BLDv0	1790	// (internal1_m911_BLDv0) BlDv - Блокировка движения
#define internal1_m911_X0	BUFFER[11098]	// (internal1_m911_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m911_X0	1791	// (internal1_m911_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m911_t0	BUFFER[11103]	// (internal1_m911_t0) время нахождения в зоне возврата
#define idinternal1_m911_t0	1792	// (internal1_m911_t0) время нахождения в зоне возврата
#define internal1_m923_tx	BUFFER[11108]	// (internal1_m923_tx) tx - время накопленное сек
#define idinternal1_m923_tx	1793	// (internal1_m923_tx) tx - время накопленное сек
#define internal1_m923_y0	BUFFER[11113]	// (internal1_m923_y0) y0
#define idinternal1_m923_y0	1794	// (internal1_m923_y0) y0
#define internal1_m924_tx	BUFFER[11115]	// (internal1_m924_tx) tx - время накопленное сек
#define idinternal1_m924_tx	1795	// (internal1_m924_tx) tx - время накопленное сек
#define internal1_m924_y0	BUFFER[11120]	// (internal1_m924_y0) y0
#define idinternal1_m924_y0	1796	// (internal1_m924_y0) y0
#define internal1_m926_tx	BUFFER[11122]	// (internal1_m926_tx) tx - внутренний параметр
#define idinternal1_m926_tx	1797	// (internal1_m926_tx) tx - внутренний параметр
#define internal1_m927_tx	BUFFER[11127]	// (internal1_m927_tx) tx - внутренний параметр
#define idinternal1_m927_tx	1798	// (internal1_m927_tx) tx - внутренний параметр
#define internal1_m929_DelSp	BUFFER[11132]	// (internal1_m929_DelSp) DelSp - время переключения скоростей
#define idinternal1_m929_DelSp	1799	// (internal1_m929_DelSp) DelSp - время переключения скоростей
#define internal1_m929_ShCntlSp0	BUFFER[11137]	// (internal1_m929_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m929_ShCntlSp0	1800	// (internal1_m929_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m929_Shift0	BUFFER[11139]	// (internal1_m929_Shift0) Shift0 - признак самохода
#define idinternal1_m929_Shift0	1801	// (internal1_m929_Shift0) Shift0 - признак самохода
#define internal1_m929_ShiftControl	BUFFER[11141]	// (internal1_m929_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m929_ShiftControl	1802	// (internal1_m929_ShiftControl) ShiftControl - признак самохода
#define internal1_m929_Speed0	BUFFER[11143]	// (internal1_m929_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m929_Speed0	1803	// (internal1_m929_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m929_StSpeed	BUFFER[11148]	// (internal1_m929_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m929_StSpeed	1804	// (internal1_m929_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m929_Vz0	BUFFER[11153]	// (internal1_m929_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m929_Vz0	1805	// (internal1_m929_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m929_flRazg	BUFFER[11158]	// (internal1_m929_flRazg) признак разгона/торможения
#define idinternal1_m929_flRazg	1806	// (internal1_m929_flRazg) признак разгона/торможения
#define internal1_m929_sumtim	BUFFER[11161]	// (internal1_m929_sumtim) sumtim - время в пути
#define idinternal1_m929_sumtim	1807	// (internal1_m929_sumtim) sumtim - время в пути
#define internal1_m929_tim0	BUFFER[11166]	// (internal1_m929_tim0) tim0 - массив значений времени цикла
#define idinternal1_m929_tim0	1808	// (internal1_m929_tim0) tim0 - массив значений времени цикла
#define internal1_m929_tx	BUFFER[11566]	// (internal1_m929_tx) tx
#define idinternal1_m929_tx	1809	// (internal1_m929_tx) tx
#define internal1_m929_txBl	BUFFER[11571]	// (internal1_m929_txBl) tx
#define idinternal1_m929_txBl	1810	// (internal1_m929_txBl) tx
#define internal1_m929_txMBl	BUFFER[11576]	// (internal1_m929_txMBl) tx
#define idinternal1_m929_txMBl	1811	// (internal1_m929_txMBl) tx
#define internal1_m929_txZS	BUFFER[11581]	// (internal1_m929_txZS) txZS
#define idinternal1_m929_txZS	1812	// (internal1_m929_txZS) txZS
#define internal1_m929_txd	BUFFER[11586]	// (internal1_m929_txd) txd
#define idinternal1_m929_txd	1813	// (internal1_m929_txd) txd
#define internal1_m929_tz0	BUFFER[11591]	// (internal1_m929_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m929_tz0	1814	// (internal1_m929_tz0) tz0 - время защиты от нового задания сек
#define internal1_m929_x0	BUFFER[11596]	// (internal1_m929_x0) x0 - массив мгновенных значений координат
#define idinternal1_m929_x0	1815	// (internal1_m929_x0) x0 - массив мгновенных значений координат
#define internal1_m929_xptr	BUFFER[11996]	// (internal1_m929_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m929_xptr	1816	// (internal1_m929_xptr) указатель текущей позиции в массиве координат
#define internal1_m929_xz0	BUFFER[11999]	// (internal1_m929_xz0) xz0 - новое задание мм
#define idinternal1_m929_xz0	1817	// (internal1_m929_xz0) xz0 - новое задание мм
#define internal1_m929_z0	BUFFER[12004]	// (internal1_m929_z0) z0 - точка прекращения движения
#define idinternal1_m929_z0	1818	// (internal1_m929_z0) z0 - точка прекращения движения
#define internal1_m931_tx	BUFFER[12009]	// (internal1_m931_tx) tx - внутренний параметр
#define idinternal1_m931_tx	1819	// (internal1_m931_tx) tx - внутренний параметр
#define internal1_m936_tx	BUFFER[12014]	// (internal1_m936_tx) tx - внутренний параметр
#define idinternal1_m936_tx	1820	// (internal1_m936_tx) tx - внутренний параметр
#define internal1_m941_tx	BUFFER[12019]	// (internal1_m941_tx) tx - время накопленное сек
#define idinternal1_m941_tx	1821	// (internal1_m941_tx) tx - время накопленное сек
#define internal1_m941_y0	BUFFER[12024]	// (internal1_m941_y0) y0
#define idinternal1_m941_y0	1822	// (internal1_m941_y0) y0
#define internal1_m951_tx	BUFFER[12026]	// (internal1_m951_tx) tx - внутренний параметр
#define idinternal1_m951_tx	1823	// (internal1_m951_tx) tx - внутренний параметр
#define internal1_m952_tx	BUFFER[12031]	// (internal1_m952_tx) tx - внутренний параметр
#define idinternal1_m952_tx	1824	// (internal1_m952_tx) tx - внутренний параметр
#define internal1_m954_tx	BUFFER[12036]	// (internal1_m954_tx) tx - внутренний параметр
#define idinternal1_m954_tx	1825	// (internal1_m954_tx) tx - внутренний параметр
#define internal1_m965_tx	BUFFER[12041]	// (internal1_m965_tx) tx - внутренний параметр
#define idinternal1_m965_tx	1826	// (internal1_m965_tx) tx - внутренний параметр
#define internal1_m969_tx	BUFFER[12046]	// (internal1_m969_tx) tx - внутренний параметр
#define idinternal1_m969_tx	1827	// (internal1_m969_tx) tx - внутренний параметр
#define internal1_m973_tx	BUFFER[12051]	// (internal1_m973_tx) tx - внутренний параметр
#define idinternal1_m973_tx	1828	// (internal1_m973_tx) tx - внутренний параметр
#define internal1_m979_tx	BUFFER[12056]	// (internal1_m979_tx) tx - внутренний параметр
#define idinternal1_m979_tx	1829	// (internal1_m979_tx) tx - внутренний параметр
#define internal1_m981_tx	BUFFER[12061]	// (internal1_m981_tx) tx - внутренний параметр
#define idinternal1_m981_tx	1830	// (internal1_m981_tx) tx - внутренний параметр
#define internal1_m986_tx	BUFFER[12066]	// (internal1_m986_tx) tx - внутренний параметр
#define idinternal1_m986_tx	1831	// (internal1_m986_tx) tx - внутренний параметр
#define internal1_m987_tx	BUFFER[12071]	// (internal1_m987_tx) tx - внутренний параметр
#define idinternal1_m987_tx	1832	// (internal1_m987_tx) tx - внутренний параметр
#define internal1_m988_tx	BUFFER[12076]	// (internal1_m988_tx) tx - внутренний параметр
#define idinternal1_m988_tx	1833	// (internal1_m988_tx) tx - внутренний параметр
#define internal1_m991_tx	BUFFER[12081]	// (internal1_m991_tx) tx - внутренний параметр
#define idinternal1_m991_tx	1834	// (internal1_m991_tx) tx - внутренний параметр
#define internal2_m106_Nk0	BUFFER[12086]	// (internal2_m106_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m106_Nk0	1835	// (internal2_m106_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m106_SetFlag	BUFFER[12091]	// (internal2_m106_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m106_SetFlag	1836	// (internal2_m106_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m110_Nk0	BUFFER[12093]	// (internal2_m110_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m110_Nk0	1837	// (internal2_m110_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m110_SetFlag	BUFFER[12098]	// (internal2_m110_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m110_SetFlag	1838	// (internal2_m110_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m127_tx	BUFFER[12100]	// (internal2_m127_tx) tx - время накопленное сек
#define idinternal2_m127_tx	1839	// (internal2_m127_tx) tx - время накопленное сек
#define internal2_m127_y0	BUFFER[12105]	// (internal2_m127_y0) y0
#define idinternal2_m127_y0	1840	// (internal2_m127_y0) y0
#define internal2_m132_tx	BUFFER[12107]	// (internal2_m132_tx) tx - время накопленное сек
#define idinternal2_m132_tx	1841	// (internal2_m132_tx) tx - время накопленное сек
#define internal2_m132_y0	BUFFER[12112]	// (internal2_m132_y0) y0
#define idinternal2_m132_y0	1842	// (internal2_m132_y0) y0
#define internal2_m134_tx	BUFFER[12114]	// (internal2_m134_tx) tx - время накопленное сек
#define idinternal2_m134_tx	1843	// (internal2_m134_tx) tx - время накопленное сек
#define internal2_m134_y0	BUFFER[12119]	// (internal2_m134_y0) y0
#define idinternal2_m134_y0	1844	// (internal2_m134_y0) y0
#define internal2_m141_tx	BUFFER[12121]	// (internal2_m141_tx) tx - время накопленное сек
#define idinternal2_m141_tx	1845	// (internal2_m141_tx) tx - время накопленное сек
#define internal2_m141_y0	BUFFER[12126]	// (internal2_m141_y0) y0
#define idinternal2_m141_y0	1846	// (internal2_m141_y0) y0
#define internal2_m144_tx	BUFFER[12128]	// (internal2_m144_tx) tx - время накопленное сек
#define idinternal2_m144_tx	1847	// (internal2_m144_tx) tx - время накопленное сек
#define internal2_m144_y0	BUFFER[12133]	// (internal2_m144_y0) y0
#define idinternal2_m144_y0	1848	// (internal2_m144_y0) y0
#define internal2_m149_tx	BUFFER[12135]	// (internal2_m149_tx) tx - время накопленное сек
#define idinternal2_m149_tx	1849	// (internal2_m149_tx) tx - время накопленное сек
#define internal2_m149_y0	BUFFER[12140]	// (internal2_m149_y0) y0
#define idinternal2_m149_y0	1850	// (internal2_m149_y0) y0
#define internal2_m155_tx	BUFFER[12142]	// (internal2_m155_tx) tx - время накопленное сек
#define idinternal2_m155_tx	1851	// (internal2_m155_tx) tx - время накопленное сек
#define internal2_m155_y0	BUFFER[12147]	// (internal2_m155_y0) y0
#define idinternal2_m155_y0	1852	// (internal2_m155_y0) y0
#define internal2_m158_tx	BUFFER[12149]	// (internal2_m158_tx) tx - время накопленное сек
#define idinternal2_m158_tx	1853	// (internal2_m158_tx) tx - время накопленное сек
#define internal2_m158_y0	BUFFER[12154]	// (internal2_m158_y0) y0
#define idinternal2_m158_y0	1854	// (internal2_m158_y0) y0
#define internal2_m15_Nk0	BUFFER[12156]	// (internal2_m15_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m15_Nk0	1855	// (internal2_m15_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m15_SetFlag	BUFFER[12161]	// (internal2_m15_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m15_SetFlag	1856	// (internal2_m15_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m165_tx	BUFFER[12163]	// (internal2_m165_tx) tx - время накопленное сек
#define idinternal2_m165_tx	1857	// (internal2_m165_tx) tx - время накопленное сек
#define internal2_m165_y0	BUFFER[12168]	// (internal2_m165_y0) y0
#define idinternal2_m165_y0	1858	// (internal2_m165_y0) y0
#define internal2_m173_tx	BUFFER[12170]	// (internal2_m173_tx) tx - время накопленное сек
#define idinternal2_m173_tx	1859	// (internal2_m173_tx) tx - время накопленное сек
#define internal2_m173_y0	BUFFER[12175]	// (internal2_m173_y0) y0
#define idinternal2_m173_y0	1860	// (internal2_m173_y0) y0
#define internal2_m176_tx	BUFFER[12177]	// (internal2_m176_tx) tx - время накопленное сек
#define idinternal2_m176_tx	1861	// (internal2_m176_tx) tx - время накопленное сек
#define internal2_m176_y0	BUFFER[12182]	// (internal2_m176_y0) y0
#define idinternal2_m176_y0	1862	// (internal2_m176_y0) y0
#define internal2_m17_Nk0	BUFFER[12184]	// (internal2_m17_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m17_Nk0	1863	// (internal2_m17_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m17_SetFlag	BUFFER[12189]	// (internal2_m17_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m17_SetFlag	1864	// (internal2_m17_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m182_tx	BUFFER[12191]	// (internal2_m182_tx) tx - время накопленное сек
#define idinternal2_m182_tx	1865	// (internal2_m182_tx) tx - время накопленное сек
#define internal2_m182_y0	BUFFER[12196]	// (internal2_m182_y0) y0
#define idinternal2_m182_y0	1866	// (internal2_m182_y0) y0
#define internal2_m193_y0	BUFFER[12198]	// (internal2_m193_y0) y0
#define idinternal2_m193_y0	1867	// (internal2_m193_y0) y0
#define internal2_m195_y0	BUFFER[12203]	// (internal2_m195_y0) y0
#define idinternal2_m195_y0	1868	// (internal2_m195_y0) y0
#define internal2_m198_y1	BUFFER[12208]	// (internal2_m198_y1) y1 - внутренний параметр
#define idinternal2_m198_y1	1869	// (internal2_m198_y1) y1 - внутренний параметр
#define internal2_m205_y1	BUFFER[12210]	// (internal2_m205_y1) y1 - внутренний параметр
#define idinternal2_m205_y1	1870	// (internal2_m205_y1) y1 - внутренний параметр
#define internal2_m208_y1	BUFFER[12212]	// (internal2_m208_y1) y1 - внутренний параметр
#define idinternal2_m208_y1	1871	// (internal2_m208_y1) y1 - внутренний параметр
#define internal2_m214_y1	BUFFER[12214]	// (internal2_m214_y1) y1 - внутренний параметр
#define idinternal2_m214_y1	1872	// (internal2_m214_y1) y1 - внутренний параметр
#define internal2_m220_y0	BUFFER[12216]	// (internal2_m220_y0) state
#define idinternal2_m220_y0	1873	// (internal2_m220_y0) state
#define internal2_m228_y0	BUFFER[12218]	// (internal2_m228_y0) state
#define idinternal2_m228_y0	1874	// (internal2_m228_y0) state
#define internal2_m49_Nk0	BUFFER[12220]	// (internal2_m49_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m49_Nk0	1875	// (internal2_m49_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m49_SetFlag	BUFFER[12225]	// (internal2_m49_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m49_SetFlag	1876	// (internal2_m49_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m53_Nk0	BUFFER[12227]	// (internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m53_Nk0	1877	// (internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m53_SetFlag	BUFFER[12232]	// (internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m53_SetFlag	1878	// (internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m75_Nk0	BUFFER[12234]	// (internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m75_Nk0	1879	// (internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m75_SetFlag	BUFFER[12239]	// (internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m75_SetFlag	1880	// (internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m77_Nk0	BUFFER[12241]	// (internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m77_Nk0	1881	// (internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m77_SetFlag	BUFFER[12246]	// (internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m77_SetFlag	1882	// (internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define lEM_R0MD01LC1	BUFFER[12248]	// (R0MD01LC1) Ручное управление ОРР
#define idlEM_R0MD01LC1	1883	// (R0MD01LC1) Ручное управление ОРР
#define psb1	BUFFER[12250]	// ( - , DU) ру не готова
#define idpsb1	1884	// ( - , DU) ру не готова
#define psb2	BUFFER[12252]	// ( - , DU) движение бб
#define idpsb2	1885	// ( - , DU) движение бб
#define venc01	BUFFER[12254]	// (vencf8l:01 - venc01, - ) заначение реального энкодера ББ1
#define idvenc01	1886	// (vencf8l:01 - venc01, - ) заначение реального энкодера ББ1
#define venc02	BUFFER[12259]	// (vencf8l:01 - venc02, - ) заначение реального энкодера РБ1
#define idvenc02	1887	// (vencf8l:01 - venc02, - ) заначение реального энкодера РБ1
#define venc03	BUFFER[12264]	// (vencf8l:01 - venc03, - ) заначение реального энкодера Ис1
#define idvenc03	1888	// (vencf8l:01 - venc03, - ) заначение реального энкодера Ис1
#define venc04	BUFFER[12269]	// (vencf8l:01 - venc04, - ) заначение реального энкодера ДС1
#define idvenc04	1889	// (vencf8l:01 - venc04, - ) заначение реального энкодера ДС1
#define venc05	BUFFER[12274]	// (vencf8l:01 - venc05, - ) заначение реального энкодера ББ2
#define idvenc05	1890	// (vencf8l:01 - venc05, - ) заначение реального энкодера ББ2
#define venc06	BUFFER[12279]	// (vencf8l:01 - venc06, - ) заначение реального энкодера РБ2
#define idvenc06	1891	// (vencf8l:01 - venc06, - ) заначение реального энкодера РБ2
#define venc07	BUFFER[12284]	// (vencf8l:01 - venc07, - ) заначение реального энкодера ИС2
#define idvenc07	1892	// (vencf8l:01 - venc07, - ) заначение реального энкодера ИС2
#define venc08	BUFFER[12289]	// (vencf8l:01 - venc08, - ) заначение реального энкодера АЗ2
#define idvenc08	1893	// (vencf8l:01 - venc08, - ) заначение реального энкодера АЗ2
#pragma pack(push,1)
static VarCtrl allVariables[]={ 			 //Описание всех переменных
	{1	,8	,1	,&A0CT01IZ1},	//( - , MDuBz1) Температура АЗ1-1
	{2	,8	,1	,&A0CT01IZ2},	//( - , MDuBz2) Температура АЗ1-2
	{3	,1	,1	,&A0EE01LZ1},	//( - , MDuBz1) Исправность АКНП1
	{4	,1	,1	,&A0EE01LZ2},	//( - , MDuBz2) Исправность АКНП1
	{5	,1	,1	,&A0EE02LZ1},	//( - , MDuBz1) Исправность АКНП2
	{6	,1	,1	,&A0EE02LZ2},	//( - , MDuBz2) Исправность АКНП2
	{7	,1	,1	,&A0EE03LZ1},	//( - , MDuBz1) Исправность АКНП3
	{8	,1	,1	,&A0EE03LZ2},	//( - , MDuBz2) Исправность АКНП3
	{9	,1	,1	,&A0EE04LZ1},	//( - , MDuBz1) Исправность АКНП4
	{10	,1	,1	,&A0EE04LZ2},	//( - , MDuBz2) Исправность АКНП4
	{11	,1	,1	,&A0VE01LDU},	//( - , DU) Напряжение в системы АЗ1 подано
	{12	,1	,1	,&A0VN01LDU},	//( - , DU) Каналы АЗ1 проверены
	{13	,1	,1	,&A0VN71LZ1},	//( - , MDuBz1) АЗ по АС мощности для АЗ1
	{14	,1	,1	,&A0VN71LZ2},	//( - , MDuBz2) АЗ по АС мощности для АЗ1
	{15	,1	,1	,&A0VP01LDU},	//( - , DU) Давление в системы АЗ1 подано
	{16	,1	,1	,&A0VP71LZ1},	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
	{17	,1	,1	,&A0VP71LZ2},	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
	{18	,1	,1	,&A0VS11LDU},	//( - , DU) АЗ1 готова к работе
	{19	,1	,1	,&A0VT71LZ1},	//( - , MDuBz1) АС по температуре в АЗ1
	{20	,1	,1	,&A0VT71LZ2},	//( - , MDuBz2) АС по температуре в АЗ1
	{21	,1	,1	,&A1AB01LDU},	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
	{22	,1	,1	,&A1AB02LDU},	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
	{23	,1	,1	,&A1AB04LDU},	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
	{24	,1	,1	,&A1AB05LDU},	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
	{25	,1	,1	,&A1AB06LDU},	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
	{26	,1	,1	,&A1AB07LDU},	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
	{27	,1	,1	,&A1AB08LDU},	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
	{28	,1	,1	,&A1AB09LDU},	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
	{29	,1	,1	,&A1AB10LDU},	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
	{30	,1	,1	,&A1AB11LDU},	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
	{31	,1	,1	,&A1AB12LDU},	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{32	,1	,1	,&A1AB13LDU},	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
	{33	,1	,1	,&A1AB14LDU},	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
	{34	,1	,1	,&A1AB16LDU},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
	{35	,1	,1	,&A1AB17LDU},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
	{36	,1	,1	,&A1AB18LDU},	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
	{37	,1	,1	,&A1AB19LDU},	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
	{38	,1	,1	,&A1AD01LDU},	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
	{39	,1	,1	,&A1AD02LDU},	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
	{40	,1	,1	,&A1AD03LDU},	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
	{41	,1	,1	,&A1AD04LDU},	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
	{42	,1	,1	,&A1AD05LDU},	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
	{43	,1	,1	,&A1AD11LDU},	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
	{44	,1	,1	,&A1AD21LDU},	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
	{45	,1	,1	,&A1AD31LDU},	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
	{46	,1	,1	,&A1AD32LDU},	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
	{47	,1	,1	,&A1AZ03LDU},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
	{48	,8	,1	,&A1CV01RDU},	//( - , DU) Измеренная скорость перемещения ББ1
	{49	,8	,1	,&A1CV02RDU},	//( - , DU) Заданная скорость перемещения ББ1
	{50	,5	,1	,&A1IC01UDU},	//( - , MDuS) Координата штока ББ1 (дел.энк)
	{51	,1	,1	,&A1IE01LDU},	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
	{52	,1	,1	,&A1IE02LDU},	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
	{53	,1	,1	,&A1IE03LDU},	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
	{54	,1	,1	,&A1IE04LDU},	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
	{55	,1	,1	,&A1IS11LDU},	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
	{56	,1	,1	,&A1IS12LDU},	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
	{57	,1	,1	,&A1IS21LDU},	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
	{58	,1	,1	,&A1MC01LC1},	//( - , DU) Настроить энкодер ББ1
	{59	,1	,1	,&A1MC01LC2},	//( - , DU) Настроить энкодер ББ1
	{60	,8	,1	,&A1MC01RP1},	//( - , DU) Заданная координата положения ББ1 мм
	{61	,1	,1	,&A1MD11LP1},	//( - , DU) Кнопка ПУСК ББ1
	{62	,1	,1	,&A1MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
	{63	,8	,1	,&A1VC01RDU},	//( - , DU) Координата ББ1, мм
	{64	,1	,1	,&A1VN71LZ1},	//(vds32:02 - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{65	,1	,1	,&A1VN71LZ2},	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{66	,1	,1	,&A1VP41LZ1},	//( - , MDuBz1) Давление СБРОС ББ1 ниже АС
	{67	,1	,1	,&A1VP41LZ2},	//( - , MDuBz2) Давление СБРОС ББ1 ниже АС
	{68	,3	,1	,&A1VS01IDU},	//( - , DU) Готовность к управлению ББ1
	{69	,1	,1	,&A1VS12LDU},	//( - , DU) Движение ББ1 в сторону ВУ
	{70	,1	,1	,&A1VS22LDU},	//( - , DU) Движение ББ1 в сторону НУ
	{71	,1	,1	,&A1ZAV},	//( - , DU) 
	{72	,1	,1	,&A2AB01LDU},	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
	{73	,1	,1	,&A2AB02LDU},	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
	{74	,1	,1	,&A2AB04LDU},	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
	{75	,1	,1	,&A2AB05LDU},	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
	{76	,1	,1	,&A2AB06LDU},	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
	{77	,1	,1	,&A2AB07LDU},	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
	{78	,1	,1	,&A2AB08LDU},	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
	{79	,1	,1	,&A2AB09LDU},	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
	{80	,1	,1	,&A2AB10LDU},	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
	{81	,1	,1	,&A2AB11LDU},	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
	{82	,1	,1	,&A2AB12LDU},	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{83	,1	,1	,&A2AB13LDU},	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
	{84	,1	,1	,&A2AB14LDU},	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
	{85	,1	,1	,&A2AB15LDU},	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{86	,1	,1	,&A2AB16LDU},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
	{87	,1	,1	,&A2AB17LDU},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
	{88	,1	,1	,&A2AD01LDU},	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
	{89	,1	,1	,&A2AD02LDU},	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
	{90	,1	,1	,&A2AD03LDU},	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
	{91	,1	,1	,&A2AD04LDU},	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
	{92	,1	,1	,&A2AD05LDU},	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
	{93	,1	,1	,&A2AD11LDU},	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
	{94	,1	,1	,&A2AD21LDU},	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
	{95	,1	,1	,&A2AD31LDU},	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
	{96	,1	,1	,&A2AD32LDU},	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
	{97	,1	,1	,&A2AD33LDU},	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
	{98	,1	,1	,&A2AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
	{99	,8	,1	,&A2CV01RDU},	//( - , DU) Измеренная скорость перемещения РБ1
	{100	,8	,1	,&A2CV02RDU},	//( - , DU) Заданная скорость перемещения РБ1
	{101	,5	,1	,&A2IC01UDU},	//( - , MDuS) Координата штока РБ1 (дел.энк)
	{102	,1	,1	,&A2IE01LDU},	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
	{103	,1	,1	,&A2IE02LDU},	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
	{104	,1	,1	,&A2IE03LDU},	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
	{105	,1	,1	,&A2IE04LDU},	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
	{106	,1	,1	,&A2IS11LDU},	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
	{107	,1	,1	,&A2IS12LDU},	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
	{108	,1	,1	,&A2IS21LDU},	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
	{109	,1	,1	,&A2IS33LDU},	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
	{110	,1	,1	,&A2MC01LC1},	//( - , DU) Настроить энкодер РБ1
	{111	,1	,1	,&A2MC01LC2},	//( - , DU) Настроить энкодер РБ1
	{112	,1	,1	,&A2MD11LP1},	//( - , DU) Кнопка ПУСК РБ1
	{113	,1	,1	,&A2MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
	{114	,8	,1	,&A2VC01RDU},	//( - , DU) Координата РБ1, мм
	{115	,1	,1	,&A2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
	{116	,3	,1	,&A2VS01IDU},	//( - , DU) Готовность к управлению РБ1
	{117	,1	,1	,&A2VS11LDU},	//( - , DU) Движение РБ1 в сторону ВУ
	{118	,1	,1	,&A2VS21LDU},	//( - , DU) Движение РБ1 в сторону НУ
	{119	,1	,1	,&A2VS32LDU},	//( - , DU) Индикация  СБРОС РБ1
	{120	,1	,1	,&A2ZAV},	//( - , DU) Завершение РБ1,2
	{121	,1	,1	,&A3AB01LDU},	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
	{122	,1	,1	,&A3AB02LDU},	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
	{123	,1	,1	,&A3AB04LDU},	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
	{124	,1	,1	,&A3AB05LDU},	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
	{125	,1	,1	,&A3AB06LDU},	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
	{126	,1	,1	,&A3AB07LDU},	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
	{127	,1	,1	,&A3AB08LDU},	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
	{128	,1	,1	,&A3AB09LDU},	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
	{129	,1	,1	,&A3AB10LDU},	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
	{130	,1	,1	,&A3AB11LDU},	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
	{131	,1	,1	,&A3AB12LDU},	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{132	,1	,1	,&A3AB13LDU},	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
	{133	,1	,1	,&A3AB14LDU},	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
	{134	,1	,1	,&A3AB15LDU},	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
	{135	,1	,1	,&A3AB16LDU},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
	{136	,1	,1	,&A3AB17LDU},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
	{137	,1	,1	,&A3AB18LDU},	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
	{138	,1	,1	,&A3AB19LDU},	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
	{139	,1	,1	,&A3AB20LDU},	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
	{140	,1	,1	,&A3AD01LDU},	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
	{141	,1	,1	,&A3AD02LDU},	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
	{142	,1	,1	,&A3AD03LDU},	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
	{143	,1	,1	,&A3AD04LDU},	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
	{144	,1	,1	,&A3AD05LDU},	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
	{145	,1	,1	,&A3AD11LDU},	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
	{146	,1	,1	,&A3AD21LDU},	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
	{147	,1	,1	,&A3AD31LDU},	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
	{148	,1	,1	,&A3AD33LDU},	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
	{149	,1	,1	,&A3AD34LDU},	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
	{150	,1	,1	,&A3AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
	{151	,8	,1	,&A3CP02RDU},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
	{152	,8	,1	,&A3CV01RDU},	//( - , DU) Измеренная скорость перемещения ИС1
	{153	,8	,1	,&A3CV02RDU},	//( - , DU) Заданная скорость перемещения ИС1
	{154	,1	,1	,&A3EE03LDU},	//( - , DU) ВПИС ИС1
	{155	,5	,1	,&A3IC01UDU},	//( - , MDuS) Координата штока ИС1 (дел.энк)
	{156	,1	,1	,&A3IE01LDU},	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
	{157	,1	,1	,&A3IE02LDU},	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
	{158	,1	,1	,&A3IE03LDU},	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
	{159	,1	,1	,&A3IE04LDU},	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
	{160	,3	,1	,&A3IP02IDU},	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
	{161	,1	,1	,&A3IS11LDU},	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
	{162	,1	,1	,&A3IS12LDU},	//( - , DU) Приход на ВУ штока ИС1
	{163	,1	,1	,&A3IS21LDU},	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
	{164	,1	,1	,&A3IS22LDU},	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
	{165	,1	,1	,&A3IS31LDU},	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
	{166	,1	,1	,&A3IS33LDU},	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
	{167	,1	,1	,&A3IS35LDU},	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
	{168	,1	,1	,&A3MC01LC1},	//( - , DU) Настроить энкодер ИС1
	{169	,1	,1	,&A3MC01LC2},	//( - , DU) Настроить энкодер ИС1
	{170	,8	,1	,&A3MC01RDU},	//( - , DU) Заданная координата положения ИС от регулятора мм
	{171	,8	,1	,&A3MC01RP1},	//( - , DU) Заданная координата положения ИС1 мм
	{172	,8	,1	,&A3MC02RDU},	//( - , DU) Температурная корректировка координаты ИМ
	{173	,8	,1	,&A3MC03RDU},	//( - , DU) Координата положения ИМ 0-й реактивности
	{174	,1	,1	,&A3MD11LP1},	//( - , DU) Кнопка ПУСК ИС1
	{175	,1	,1	,&A3MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
	{176	,8	,1	,&A3VC01RDU},	//( - , DU) Координата ИС1, мм
	{177	,1	,1	,&A3VP42LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
	{178	,1	,1	,&A3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
	{179	,1	,1	,&A3VP81LDU},	//( - , - ) Давление СПУСК ИС1 в норме
	{180	,1	,1	,&A3VP82LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
	{181	,3	,1	,&A3VS01IDU},	//( - , DU) Готовность к управлению ИС1
	{182	,1	,1	,&A3VS12LDU},	//( - , DU) Движение ИС1 в сторону ВУ
	{183	,1	,1	,&A3VS22LDU},	//( - , DU) Движение ИС1 в сторону НУ
	{184	,1	,1	,&A3VX01LDU},	//( - , DU) Индикация Выстрел ИС1
	{185	,1	,1	,&A3VZ13LZ1},	//(vds32:02 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{186	,1	,1	,&A3VZ13LZ2},	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{187	,1	,1	,&A3VZ15LZ1},	//(vds32:02 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{188	,1	,1	,&A3VZ15LZ2},	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{189	,1	,1	,&A3ZAV},	//( - , DU) 
	{190	,1	,1	,&A4AB01LDU},	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
	{191	,1	,1	,&A4AB02LDU},	//( - , DU) Блокировка движения НИ1 - Нет перемещения
	{192	,1	,1	,&A4AD10LDU},	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
	{193	,1	,1	,&A4AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ1
	{194	,1	,1	,&A4DW},	//( - , DU) 
	{195	,1	,1	,&A4IS10LDU},	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
	{196	,1	,1	,&A4IS11LDU},	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
	{197	,1	,1	,&A4IS21LDU},	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
	{198	,1	,1	,&A4UP},	//( - , DU) 
	{199	,1	,1	,&A4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
	{200	,3	,1	,&A4VS01IDU},	//( - , DU) Готовность к управлению НИ1
	{201	,1	,1	,&A4VS12LDU},	//( - , DU) Движение НИ1 в сторону ВУ
	{202	,1	,1	,&A4VS22LDU},	//( - , DU) Движение НИ1 в сторону НУ
	{203	,1	,1	,&A4ZAV},	//( - , DU) 
	{204	,1	,1	,&A5AB01LDU},	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
	{205	,1	,1	,&A5AB02LDU},	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
	{206	,1	,1	,&A5AB04LDU},	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
	{207	,1	,1	,&A5AD10LDU},	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
	{208	,1	,1	,&A5AD20LDU},	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
	{209	,1	,1	,&A5AZ03LDU},	//( - , DU) Несанкционированное перемещение НЛ1
	{210	,1	,1	,&A5IE02LDU},	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
	{211	,1	,1	,&A5IS11LDU},	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
	{212	,1	,1	,&A5IS21LDU},	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
	{213	,3	,1	,&A5VS01IDU},	//( - , DU) Готовность к управлению НЛ1
	{214	,1	,1	,&A5VS12LDU},	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
	{215	,1	,1	,&A5VS22LDU},	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
	{216	,1	,1	,&A5ZAV},	//( - , DU) 
	{217	,1	,1	,&A6AB01LDU},	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
	{218	,1	,1	,&A6AB02LDU},	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
	{219	,1	,1	,&A6AB04LDU},	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
	{220	,1	,1	,&A6AB05LDU},	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
	{221	,1	,1	,&A6AB06LDU},	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
	{222	,1	,1	,&A6AB07LDU},	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
	{223	,1	,1	,&A6AB08LDU},	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
	{224	,1	,1	,&A6AB09LDU},	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
	{225	,1	,1	,&A6AD10LDU},	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
	{226	,1	,1	,&A6AD20LDU},	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
	{227	,1	,1	,&A6AZ03LDU},	//( - , DU) Несанкционированное перемещение БЗ1
	{228	,1	,1	,&A6IE01LDU},	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
	{229	,1	,1	,&A6IS11LDU},	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
	{230	,1	,1	,&A6IS21LDU},	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
	{231	,3	,1	,&A6VS01IDU},	//( - , DU) Готовность к управлению БЗ1
	{232	,1	,1	,&A6VS12LDU},	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
	{233	,1	,1	,&A6VS22LDU},	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
	{234	,1	,1	,&A6ZAV},	//( - , DU) 
	{235	,1	,1	,&A7AP31LDU},	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
	{236	,1	,1	,&A7AS31LDU},	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
	{237	,1	,1	,&A7AZ03LDU},	//( - , DU) Несанкционированное включение обдува АЗ1
	{238	,1	,1	,&A8AB01LDU},	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
	{239	,1	,1	,&A8AB02LDU},	//( - , DU) Блокировка движения ДС2- АНИ не установлен
	{240	,1	,1	,&A8AB04LDU},	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
	{241	,1	,1	,&A8AB05LDU},	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
	{242	,1	,1	,&A8AB06LDU},	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
	{243	,1	,1	,&A8AB07LDU},	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
	{244	,1	,1	,&A8AB08LDU},	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
	{245	,1	,1	,&A8AB09LDU},	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
	{246	,1	,1	,&A8AB10LDU},	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
	{247	,1	,1	,&A8AB11LDU},	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
	{248	,1	,1	,&A8AB12LDU},	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
	{249	,1	,1	,&A8AB13LDU},	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
	{250	,1	,1	,&A8AB14LDU},	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
	{251	,1	,1	,&A8AD10LDU},	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
	{252	,1	,1	,&A8AD20LDU},	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
	{253	,1	,1	,&A8AZ03LDU},	//( - , DU) Несанкционированное перемещение ДС2
	{254	,8	,1	,&A8CV01RDU},	//( - , DU) Измеренная скорость перемещения ДС2
	{255	,5	,1	,&A8IC01UDU},	//( - , MDuS) Координата ДС2 (дел.энк)
	{256	,1	,1	,&A8IE01LDU},	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
	{257	,1	,1	,&A8IS12LDU},	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
	{258	,1	,1	,&A8IS22LDU},	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
	{259	,1	,1	,&A8MC01LC1},	//( - , DU) Настроить энкодер ДС2
	{260	,1	,1	,&A8MC01LC2},	//( - , DU) Настроить энкодер ДС2
	{261	,8	,1	,&A8VC01RDU},	//( - , DU) Координата ДС2, мм
	{262	,3	,1	,&A8VS01IDU},	//( - , DU) Готовность к управлению ДС2
	{263	,1	,1	,&A8VS12LDU},	//( - , DU) Движение ДС2 в сторону ВУ
	{264	,1	,1	,&A8VS22LDU},	//( - , DU) Движение ДС2 в сторону НУ
	{265	,1	,1	,&A8ZAV},	//( - , DU) 
	{266	,1	,1	,&A9AB01LDU},	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
	{267	,1	,1	,&A9AB02LDU},	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
	{268	,1	,1	,&A9AD10LDU},	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
	{269	,1	,1	,&A9AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ ДС1
	{270	,1	,1	,&A9IS11LDU},	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
	{271	,1	,1	,&A9IS21LDU},	//(vds32:02 - K24VDSR, DU) Приход на НУ НИ ДС1
	{272	,1	,1	,&A9ZAV},	//( - , DU) Завершение НИ ДС1(2)
	{273	,8	,1	,&B0CT01IZ1},	//( - , MDuBz1) Температура АЗ2-1
	{274	,8	,1	,&B0CT01IZ2},	//( - , MDuBz2) Температура АЗ2-2
	{275	,1	,1	,&B0VE01LDU},	//( - , DU) Напряжение в системы АЗ2 подано
	{276	,1	,1	,&B0VN01LDU},	//( - , DU) Каналы АЗ2 проверены
	{277	,1	,1	,&B0VN71LZ1},	//( - , MDuBz1) АЗ по АС мощности для АЗ2
	{278	,1	,1	,&B0VN71LZ2},	//( - , MDuBz2) АЗ по АС мощности для АЗ2
	{279	,1	,1	,&B0VP01LDU},	//( - , DU) Давление в системы АЗ2 подано
	{280	,1	,1	,&B0VP71LZ1},	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
	{281	,1	,1	,&B0VP71LZ2},	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
	{282	,1	,1	,&B0VS11LDU},	//( - , DU) АЗ2 готова к работе
	{283	,1	,1	,&B0VT71LZ1},	//( - , MDuBz1) АС по температуре в АЗ2
	{284	,1	,1	,&B0VT71LZ2},	//( - , MDuBz2) АС по температуре в АЗ2
	{285	,1	,1	,&B1AB01LDU},	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
	{286	,1	,1	,&B1AB02LDU},	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
	{287	,1	,1	,&B1AB04LDU},	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
	{288	,1	,1	,&B1AB05LDU},	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
	{289	,1	,1	,&B1AB06LDU},	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
	{290	,1	,1	,&B1AB07LDU},	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
	{291	,1	,1	,&B1AB08LDU},	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
	{292	,1	,1	,&B1AB09LDU},	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
	{293	,1	,1	,&B1AB10LDU},	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
	{294	,1	,1	,&B1AB11LDU},	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
	{295	,1	,1	,&B1AB12LDU},	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{296	,1	,1	,&B1AB13LDU},	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
	{297	,1	,1	,&B1AB14LDU},	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
	{298	,1	,1	,&B1AB16LDU},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
	{299	,1	,1	,&B1AB17LDU},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
	{300	,1	,1	,&B1AB18LDU},	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
	{301	,1	,1	,&B1AB19LDU},	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
	{302	,1	,1	,&B1AD01LDU},	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
	{303	,1	,1	,&B1AD02LDU},	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
	{304	,1	,1	,&B1AD03LDU},	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
	{305	,1	,1	,&B1AD04LDU},	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
	{306	,1	,1	,&B1AD05LDU},	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
	{307	,1	,1	,&B1AD11LDU},	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
	{308	,1	,1	,&B1AD21LDU},	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
	{309	,1	,1	,&B1AD31LDU},	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
	{310	,1	,1	,&B1AD32LDU},	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
	{311	,1	,1	,&B1AZ03LDU},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
	{312	,8	,1	,&B1CV01RDU},	//( - , DU) Измеренная скорость перемещения ББ2
	{313	,8	,1	,&B1CV02RDU},	//( - , DU) Заданная скорость перемещения ББ2
	{314	,5	,1	,&B1IC01UDU},	//( - , MDuS) Координата штока ББ2 (дел.энк)
	{315	,1	,1	,&B1IE01LDU},	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
	{316	,1	,1	,&B1IE02LDU},	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
	{317	,1	,1	,&B1IE03LDU},	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
	{318	,1	,1	,&B1IE04LDU},	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
	{319	,1	,1	,&B1IS11LDU},	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
	{320	,1	,1	,&B1IS12LDU},	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
	{321	,1	,1	,&B1IS21LDU},	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
	{322	,1	,1	,&B1MC01LC1},	//( - , DU) Настроить энкодер ББ2
	{323	,1	,1	,&B1MC01LC2},	//( - , DU) Настроить энкодер ББ2
	{324	,8	,1	,&B1MC01RP1},	//( - , DU) Заданная координата положения ББ2  мм
	{325	,1	,1	,&B1MD11LP1},	//( - , DU) Кнопка ПУСК ББ2
	{326	,1	,1	,&B1MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
	{327	,8	,1	,&B1VC01RDU},	//( - , DU) Координата ББ2, мм
	{328	,1	,1	,&B1VP41LZ1},	//( - , MDuBz1) Давление СБРОС ББ2 ниже АС
	{329	,1	,1	,&B1VP41LZ2},	//( - , MDuBz2) Давление СБРОС ББ2 ниже АС
	{330	,3	,1	,&B1VS01IDU},	//( - , DU) Готовность к управлению ББ2
	{331	,1	,1	,&B1VS12LDU},	//( - , DU) Движение ББ2 в сторону ВУ
	{332	,1	,1	,&B1VS22LDU},	//( - , DU) Движение ББ2 в сторону НУ
	{333	,1	,1	,&B2AB01LDU},	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
	{334	,1	,1	,&B2AB02LDU},	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
	{335	,1	,1	,&B2AB04LDU},	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
	{336	,1	,1	,&B2AB05LDU},	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
	{337	,1	,1	,&B2AB06LDU},	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
	{338	,1	,1	,&B2AB07LDU},	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
	{339	,1	,1	,&B2AB08LDU},	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
	{340	,1	,1	,&B2AB09LDU},	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
	{341	,1	,1	,&B2AB10LDU},	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
	{342	,1	,1	,&B2AB11LDU},	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
	{343	,1	,1	,&B2AB12LDU},	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{344	,1	,1	,&B2AB13LDU},	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
	{345	,1	,1	,&B2AB14LDU},	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
	{346	,1	,1	,&B2AB15LDU},	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{347	,1	,1	,&B2AB16LDU},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
	{348	,1	,1	,&B2AB17LDU},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
	{349	,1	,1	,&B2AD01LDU},	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
	{350	,1	,1	,&B2AD02LDU},	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
	{351	,1	,1	,&B2AD03LDU},	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
	{352	,1	,1	,&B2AD04LDU},	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
	{353	,1	,1	,&B2AD05LDU},	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
	{354	,1	,1	,&B2AD11LDU},	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
	{355	,1	,1	,&B2AD21LDU},	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
	{356	,1	,1	,&B2AD31LDU},	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
	{357	,1	,1	,&B2AD32LDU},	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
	{358	,1	,1	,&B2AD33LDU},	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
	{359	,1	,1	,&B2AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
	{360	,8	,1	,&B2CV01RDU},	//( - , DU) Измеренная скорость перемещения РБ2
	{361	,8	,1	,&B2CV02RDU},	//( - , DU) Заданная скорость перемещения РБ2
	{362	,5	,1	,&B2IC01UDU},	//( - , MDuS) Координата штока РБ2 (дел.энк)
	{363	,1	,1	,&B2IE01LDU},	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
	{364	,1	,1	,&B2IE02LDU},	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
	{365	,1	,1	,&B2IE03LDU},	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
	{366	,1	,1	,&B2IE04LDU},	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
	{367	,1	,1	,&B2IS11LDU},	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
	{368	,1	,1	,&B2IS12LDU},	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
	{369	,1	,1	,&B2IS21LDU},	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
	{370	,1	,1	,&B2IS33LDU},	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
	{371	,1	,1	,&B2MC01LC1},	//( - , DU) Настроить энкодер РБ2
	{372	,1	,1	,&B2MC01LC2},	//( - , DU) Настроить энкодер РБ2
	{373	,1	,1	,&B2MD11LP1},	//( - , DU) Кнопка ПУСК РБ2
	{374	,1	,1	,&B2MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
	{375	,8	,1	,&B2VC01RDU},	//( - , DU) Координата РБ2, мм
	{376	,1	,1	,&B2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
	{377	,3	,1	,&B2VS01IDU},	//( - , DU) Готовность к управлению РБ2
	{378	,1	,1	,&B2VS11LDU},	//( - , DU) Движение РБ2 в сторону ВУ
	{379	,1	,1	,&B2VS21LDU},	//( - , DU) Движение РБ2 в сторону НУ
	{380	,1	,1	,&B2VS32LDU},	//( - , DU) Индикация  СБРОС РБ2
	{381	,1	,1	,&B3AB01LDU},	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
	{382	,1	,1	,&B3AB02LDU},	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
	{383	,1	,1	,&B3AB04LDU},	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
	{384	,1	,1	,&B3AB05LDU},	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
	{385	,1	,1	,&B3AB06LDU},	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
	{386	,1	,1	,&B3AB07LDU},	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
	{387	,1	,1	,&B3AB08LDU},	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
	{388	,1	,1	,&B3AB09LDU},	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
	{389	,1	,1	,&B3AB10LDU},	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
	{390	,1	,1	,&B3AB11LDU},	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
	{391	,1	,1	,&B3AB12LDU},	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{392	,1	,1	,&B3AB13LDU},	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
	{393	,1	,1	,&B3AB14LDU},	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
	{394	,1	,1	,&B3AB15LDU},	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
	{395	,1	,1	,&B3AB16LDU},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
	{396	,1	,1	,&B3AB17LDU},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
	{397	,1	,1	,&B3AB18LDU},	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
	{398	,1	,1	,&B3AB19LDU},	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
	{399	,1	,1	,&B3AB20LDU},	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
	{400	,1	,1	,&B3AD01LDU},	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
	{401	,1	,1	,&B3AD02LDU},	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
	{402	,1	,1	,&B3AD03LDU},	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
	{403	,1	,1	,&B3AD04LDU},	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
	{404	,1	,1	,&B3AD05LDU},	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
	{405	,1	,1	,&B3AD11LDU},	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
	{406	,1	,1	,&B3AD21LDU},	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
	{407	,1	,1	,&B3AD31LDU},	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
	{408	,1	,1	,&B3AD33LDU},	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
	{409	,1	,1	,&B3AD34LDU},	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
	{410	,1	,1	,&B3AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
	{411	,8	,1	,&B3CP02RDU},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
	{412	,8	,1	,&B3CV01RDU},	//( - , DU) Измеренная скорость перемещения ИС2
	{413	,8	,1	,&B3CV02RDU},	//( - , DU) Заданная скорость перемещения ИС2
	{414	,1	,1	,&B3EE03LDU},	//( - , DU) ВПИС ИС2
	{415	,5	,1	,&B3IC01UDU},	//( - , MDuS) Координата штока ИС2 (дел.энк)
	{416	,1	,1	,&B3IE01LDU},	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
	{417	,1	,1	,&B3IE02LDU},	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
	{418	,1	,1	,&B3IE03LDU},	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
	{419	,1	,1	,&B3IE04LDU},	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
	{420	,3	,1	,&B3IP02IDU},	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
	{421	,1	,1	,&B3IS11LDU},	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
	{422	,1	,1	,&B3IS12LDU},	//( - , DU) Приход на ВУ штока ИС2
	{423	,1	,1	,&B3IS21LDU},	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
	{424	,1	,1	,&B3IS22LDU},	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
	{425	,1	,1	,&B3IS31LDU},	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
	{426	,1	,1	,&B3IS33LDU},	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
	{427	,1	,1	,&B3IS35LDU},	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
	{428	,1	,1	,&B3MC01LC1},	//( - , DU) Настроить энкодер ИС2
	{429	,1	,1	,&B3MC01LC2},	//( - , DU) Настроить энкодер ИС2
	{430	,8	,1	,&B3MC01RP1},	//( - , DU) Заданная координата положения ИС2 мм
	{431	,1	,1	,&B3MD11LP1},	//( - , DU) Кнопка ПУСК ИС2
	{432	,1	,1	,&B3MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
	{433	,8	,1	,&B3VC01RDU},	//( - , DU) Координата ИС2, мм
	{434	,1	,1	,&B3VP42LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
	{435	,1	,1	,&B3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
	{436	,1	,1	,&B3VP81LDU},	//( - , - ) Давление СПУСК ИС2 в норме
	{437	,1	,1	,&B3VP82LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
	{438	,3	,1	,&B3VS01IDU},	//( - , DU) Готовность к управлению ИС2
	{439	,1	,1	,&B3VS12LDU},	//( - , DU) Движение ИС2 в сторону ВУ
	{440	,1	,1	,&B3VS22LDU},	//( - , DU) Движение ИС2 в сторону НУ
	{441	,1	,1	,&B3VX01LDU},	//( - , DU) Индикация Выстрел ИС2
	{442	,1	,1	,&B4AB01LDU},	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
	{443	,1	,1	,&B4AB02LDU},	//( - , DU) Блокировка движения НИ2 - Нет перемещения
	{444	,1	,1	,&B4AD10LDU},	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
	{445	,1	,1	,&B4AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ2
	{446	,1	,1	,&B4IS10LDU},	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
	{447	,1	,1	,&B4IS11LDU},	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
	{448	,1	,1	,&B4IS21LDU},	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
	{449	,1	,1	,&B4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
	{450	,3	,1	,&B4VS01IDU},	//( - , DU) Готовность к управлению НИ2
	{451	,1	,1	,&B4VS12LDU},	//( - , DU) Движение НИ2 в сторону ВУ
	{452	,1	,1	,&B4VS22LDU},	//( - , DU) Движение НИ2 в сторону НУ
	{453	,1	,1	,&B5AB01LDU},	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
	{454	,1	,1	,&B5AB02LDU},	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
	{455	,1	,1	,&B5AB04LDU},	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
	{456	,1	,1	,&B5AD10LDU},	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
	{457	,1	,1	,&B5AD20LDU},	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
	{458	,1	,1	,&B5AZ03LDU},	//( - , DU) Несанкционированное перемещение НЛ2
	{459	,1	,1	,&B5IE01LDU},	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
	{460	,1	,1	,&B5IS11LDU},	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
	{461	,1	,1	,&B5IS21LDU},	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
	{462	,3	,1	,&B5VS01IDU},	//( - , DU) Готовность к управлению НЛ2
	{463	,1	,1	,&B5VS12LDU},	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
	{464	,1	,1	,&B5VS22LDU},	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
	{465	,1	,1	,&B6AB01LDU},	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
	{466	,1	,1	,&B6AB02LDU},	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
	{467	,1	,1	,&B6AB04LDU},	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
	{468	,1	,1	,&B6AB05LDU},	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
	{469	,1	,1	,&B6AB06LDU},	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
	{470	,1	,1	,&B6AB07LDU},	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
	{471	,1	,1	,&B6AB08LDU},	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
	{472	,1	,1	,&B6AB09LDU},	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
	{473	,1	,1	,&B6AD10LDU},	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
	{474	,1	,1	,&B6AD20LDU},	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
	{475	,1	,1	,&B6AZ03LDU},	//( - , DU) Несанкционированное перемещение БЗ2
	{476	,1	,1	,&B6IE01LDU},	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
	{477	,1	,1	,&B6IS11LDU},	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
	{478	,1	,1	,&B6IS21LDU},	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
	{479	,3	,1	,&B6VS01IDU},	//( - , DU) Готовность к управлению БЗ2
	{480	,1	,1	,&B6VS12LDU},	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
	{481	,1	,1	,&B6VS22LDU},	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
	{482	,1	,1	,&B7AP31LDU},	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
	{483	,1	,1	,&B7AS31LDU},	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
	{484	,1	,1	,&B7AZ03LDU},	//( - , DU) Несанкционированное включение обдува АЗ2
	{485	,1	,1	,&B8AB01LDU},	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
	{486	,1	,1	,&B8AB02LDU},	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
	{487	,1	,1	,&B8AB04LDU},	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
	{488	,1	,1	,&B8AB05LDU},	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
	{489	,1	,1	,&B8AB06LDU},	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
	{490	,1	,1	,&B8AB07LDU},	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
	{491	,1	,1	,&B8AB08LDU},	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
	{492	,1	,1	,&B8AB09LDU},	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
	{493	,1	,1	,&B8AB10LDU},	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
	{494	,1	,1	,&B8AB11LDU},	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
	{495	,1	,1	,&B8AB12LDU},	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
	{496	,1	,1	,&B8AB13LDU},	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
	{497	,1	,1	,&B8AB14LDU},	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
	{498	,1	,1	,&B8AD10LDU},	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
	{499	,1	,1	,&B8AD20LDU},	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
	{500	,1	,1	,&B8AZ03LDU},	//( - , DU) Несанкционированное перемещение АЗ2
	{501	,8	,1	,&B8CV01RDU},	//( - , DU) Измеренная скорость перемещения АЗ2
	{502	,5	,1	,&B8IC01UDU},	//( - , MDuS) Координата АЗ2 (дел.энк)
	{503	,1	,1	,&B8IS11LDU},	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
	{504	,1	,1	,&B8IS12LDU},	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
	{505	,1	,1	,&B8IS21LDU},	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
	{506	,1	,1	,&B8IS22LDU},	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
	{507	,1	,1	,&B8MC01LC1},	//( - , DU) Настроить энкодер АЗ2
	{508	,1	,1	,&B8MC01LC2},	//( - , DU) Настроить энкодер АЗ2
	{509	,8	,1	,&B8MC01RP2},	//( - , DU) Заданная координата АЗ2 мм
	{510	,8	,1	,&B8VC01RDU},	//( - , DU, MDuBz1, MDuBz2) Координата АЗ2, мм
	{511	,3	,1	,&B8VS01IDU},	//( - , DU) Готовность к управлению АЗ2
	{512	,1	,1	,&B8VS12LDU},	//( - , DU) Движение АЗ2 в сторону ВУ
	{513	,1	,1	,&B8VS22LDU},	//( - , DU) Движение АЗ2 в сторону НУ
	{514	,1	,1	,&B8ZAV},	//( - , DU) 
	{515	,1	,1	,&B9AB01LDU},	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
	{516	,1	,1	,&B9AB02LDU},	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
	{517	,1	,1	,&B9AD10LDU},	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
	{518	,1	,1	,&B9AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ ДС2
	{519	,1	,1	,&B9IS11LDU},	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
	{520	,1	,1	,&B9IS21LDU},	//(vds32:02 - K26VDSR, DU) Приход на НУ НИ ДС2
	{521	,1	,1	,&C1MD31LP1},	//( - , DU) Кнопка СБРОС ББ
	{522	,1	,1	,&C1MD31LP2},	//( - , DU) Кнопка СБРОС ББ
	{523	,1	,1	,&C2MD31LP1},	//( - , DU) Кнопка СБРОС РБ
	{524	,1	,1	,&R0AB01LDU},	//( - , DU) Режим проверки разрешён
	{525	,1	,1	,&R0AB02LDU},	//( - , DU) Нарушение времени задержки ИНИ
	{526	,1	,1	,&R0AB03LDU},	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
	{527	,1	,1	,&R0AB04LDU},	//( - , DU) Нарушение времени срабатывания верхней АС II УР
	{528	,1	,1	,&R0AB05LDU},	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
	{529	,1	,1	,&R0AB06LDU},	//( - , DU) Нарушение времени задержки от ВУ РБ
	{530	,1	,1	,&R0AB07LDU},	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
	{531	,1	,1	,&R0AB08LDU},	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
	{532	,1	,1	,&R0AB09LDU},	//( - , DU) Ошибка в заданной координате ББ1
	{533	,1	,1	,&R0AB10LDU},	//( - , DU) Ошибка в заданной координате ББ2
	{534	,1	,1	,&R0AB11LDU},	//( - , DU) Ошибка в заданной координате  ИС1
	{535	,1	,1	,&R0AB12LDU},	//( - , DU) Ошибка в заданной координате  ИС2
	{536	,1	,1	,&R0AB13LDU},	//( - , DU) Ошибка в заданной координате  АЗ2
	{537	,1	,1	,&R0AB14LDU},	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
	{538	,1	,1	,&R0AB15LDU},	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
	{539	,1	,1	,&R0AB16LDU},	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
	{540	,1	,1	,&R0AB17LDU},	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
	{541	,1	,1	,&R0AB18LDU},	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
	{542	,1	,1	,&R0AB19LDU},	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
	{543	,1	,1	,&R0AB20LDU},	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
	{544	,1	,1	,&R0AD03LZ1},	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
	{545	,1	,1	,&R0AD03LZ2},	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
	{546	,1	,1	,&R0AD04LZ1},	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
	{547	,1	,1	,&R0AD04LZ2},	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
	{548	,1	,1	,&R0AD05LZ1},	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
	{549	,1	,1	,&R0AD05LZ2},	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
	{550	,1	,1	,&R0AD14LZ1},	//(vds32:02 - K20VDSR, DU) Имитация срабатывания АЗ от II УР
	{551	,1	,1	,&R0AD14LZ2},	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
	{552	,1	,1	,&R0AD16LDU},	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
	{553	,1	,1	,&R0AD21LDU},	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
	{554	,8	,1	,&R0CN91LDU},	//( - , DU) Рассчётная реактивность от регулятора
	{555	,8	,1	,&R0CN93LDU},	//( - , DU) время работы на мощности более 100Вт, сек
	{556	,3	,1	,&R0CN95LDU},	//( - , DU) Этап 0 - не начинали, 54 - выход в 0 реакт, 59 - доводка, 55 - в зоне нечувст
	{557	,3	,1	,&R0DE01LDU},	//(vencf8l:01 - DiagnVDS, DiagnDU) диагностика модуля ДУ на 1 месте
	{558	,3	,1	,&R0DE02LDU},	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
	{559	,3	,1	,&R0DE03LDU},	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
	{560	,3	,1	,&R0DE04LDU},	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
	{561	,3	,1	,&R0DE05LDU},	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
	{562	,3	,1	,&R0DE06LDU},	//(vencf8l:01 - DiagnFDS, DiagnDU) диагностика модуля ДУ на 6 месте
	{563	,3	,1	,&R0DE07LDU},	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
	{564	,3	,1	,&R0DE08LDU},	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
	{565	,3	,1	,&R0DE09LDU},	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
	{566	,3	,1	,&R0DE0ALDU},	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
	{567	,3	,1	,&R0DE0BLDU},	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
	{568	,3	,1	,&R0DE0CLDU},	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
	{569	,3	,1	,&R0DE0DLDU},	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
	{570	,3	,1	,&R0DE0FLDU},	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
	{571	,1	,1	,&R0DE3CLDU},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
	{572	,1	,1	,&R0DE3DLDU},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
	{573	,1	,1	,&R0DEB1LDU},	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
	{574	,1	,1	,&R0DEB2LDU},	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
	{575	,1	,1	,&R0DEB3LDU},	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
	{576	,1	,1	,&R0DEB4LDU},	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
	{577	,1	,1	,&R0EE02LDU},	//( - , DU) Питание  АКНП  отключить
	{578	,1	,1	,&R0EE03LDU},	//( - , DU) ВПИС ИС
	{579	,1	,1	,&R0ES01LDU},	//( - , DU) ОРР не в исходном состоянии
	{580	,1	,1	,&R0IE01LDU},	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
	{581	,1	,1	,&R0IE02LDU},	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
	{582	,1	,1	,&R0IS01LDU},	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
	{583	,1	,1	,&R0IS02LDU},	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
	{584	,1	,1	,&R0MD11LP1},	//( - , DU) Кнопка ПУСК
	{585	,1	,1	,&R0MD11LP2},	//( - , DU) Кнопка Пуск проверки схем сброса
	{586	,1	,1	,&R0MD31LP1},	//( - , DU) Кнопка СТОП
	{587	,1	,1	,&R0MD32LP1},	//( - , DU) Кнопка СПУСК
	{588	,1	,1	,&R0MD33LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
	{589	,1	,1	,&R0MD34LP1},	//( - , DU) Кнопка КВИТИРОВАТЬ
	{590	,3	,1	,&R0MW11IP1},	//( - , DU) Переключатель ВЫСТРЕЛ
	{591	,3	,1	,&R0MW11IP2},	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
	{592	,3	,1	,&R0MW12IP1},	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
	{593	,3	,1	,&R0MW12IP2},	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
	{594	,3	,1	,&R0MW13IP1},	//( - , DU) Переключатель ВЫБОР ЗОН
	{595	,1	,1	,&R0MW13LP2},	//( - , DU) Переключатель СЕТЬ
	{596	,3	,1	,&R0MW14IP1},	//( - , DU) Переключатель ПРОГРАММЫ
	{597	,3	,1	,&R0MW14IP2},	//( - , DU) Переключатель ОБДУВ
	{598	,3	,1	,&R0MW15IP1},	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
	{599	,3	,1	,&R0MW16IP1},	//( - , DU) Переключатель ВИД ПРОВЕРКИ
	{600	,1	,1	,&R0MW17LP1},	//( - , DU) Переключатель АВТ/Р
	{601	,1	,1	,&R0NE01LDU},	//( - , DU) Потеря связи с БАЗ1
	{602	,1	,1	,&R0NE02LDU},	//( - , DU) Потеря связи с БАЗ2
	{603	,1	,1	,&R0NE08LDU},	//( - , DU) Потеря связи с ОПУ
	{604	,1	,1	,&R0S01LDU},	//( - , - ) Отключение сетевых передач ДУ
	{605	,1	,1	,&R0S01LIM},	//(fds16:08 - K15FDSR, - ) Отключение сетевых передач ПТИ
	{606	,1	,1	,&R0S01LZ1},	//(fds16:07 - K15FDSR, - ) Отключение сетевых передач в Баз1
	{607	,1	,1	,&R0S01LZ2},	//(fds16:07 - K16FDSR, - ) Отключение сетевых передач в Баз2
	{608	,3	,1	,&R0VL01IDU},	//( - , DU) До импульса минут
	{609	,8	,1	,&R0VL01RDU},	//( - , DU) Индикация Время задержки
	{610	,8	,1	,&R0VL02RDU},	//( - , DU) Индикация (Время задержки ИНИ)
	{611	,8	,1	,&R0VL03RDU},	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
	{612	,8	,1	,&R0VL04RDU},	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
	{613	,8	,1	,&R0VL05RDU},	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
	{614	,8	,1	,&R0VL06RDU},	//( - , DU) Индикация (Время задержки от ВУ РБ)
	{615	,3	,1	,&R0VL11IDU},	//( - , DU) До импульса секунд
	{616	,3	,1	,&R0VL21IDU},	//( - , DU) Декатрон
	{617	,1	,1	,&R0VL22LDU},	//( - , DU) Конец программы 200сек
	{618	,1	,1	,&R0VL23LDU},	//( - , DU) Конец программы 20мин
	{619	,8	,1	,&R0VN11RDU},	//( - , DU) Текущая мощность РУ
	{620	,8	,1	,&R0VN11RZ1},	//( - , MDuBz1) Средняя мощность по BAZ1
	{621	,8	,1	,&R0VN11RZ2},	//( - , MDuBz2) Средняя мощность по BAZ2
	{622	,8	,1	,&R0VN12RDU},	//( - , DU) Заданная мощность РУ
	{623	,8	,1	,&R0VN15RDU},	//( - , DU) Период разгона РУ
	{624	,1	,1	,&R0VP73LDU},	//( - , DU) ПС давления для РУ
	{625	,1	,1	,&R0VP73LZ1},	//( - , MDuBz1) ПС давления для РУ
	{626	,1	,1	,&R0VP73LZ2},	//( - , MDuBz2) ПС давления для РУ
	{627	,1	,1	,&R0VS11LDU},	//( - , DU) РУ не готова к работе
	{628	,1	,1	,&R0VS17LDU},	//( - , DU) Индикация выбора АВТОМАТ
	{629	,1	,1	,&R0VS18LDU},	//( - , DU) Индикация  Проверка схем сброса
	{630	,3	,1	,&R0VS21IDU},	//( - , DU) Индикация ВИД ПРОВЕРКИ
	{631	,1	,1	,&R0VW13LDU},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
	{632	,1	,1	,&R0VW23LDU},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
	{633	,1	,1	,&R0VX01LDU},	//( - , DU) ДО ИМПУЛЬСА
	{634	,1	,1	,&R0VX02LDU},	//( - , DU) Импульс разрешен
	{635	,1	,1	,&R0VX03LDU},	//( - , DU) Готовность 2 мин
	{636	,3	,1	,&R0VX08IDU},	//( - , DU) Индикация Режим
	{637	,1	,1	,&R0VX09LDU},	//( - , DU) Индикация регулятор мощности включен/отключен
	{638	,1	,1	,&R0VZ71LDU},	//( - , DU) Обобщенный сигнал АЗ
	{639	,1	,1	,&R0VZ71LZ1},	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
	{640	,1	,1	,&R0VZ71LZ2},	//(vds32:03 - K22VDSR, - ) Обобщенный сигнал АЗ 2 канала
	{641	,1	,1	,&R1AB01LDU},	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
	{642	,1	,1	,&R1AB02LDU},	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
	{643	,1	,1	,&R1AB04LDU},	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
	{644	,1	,1	,&R1AD10LDU},	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
	{645	,1	,1	,&R1AD20LDU},	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
	{646	,1	,1	,&R1AZ03LDU},	//( - , DU) Несанкционированное перемещение МДЗ1
	{647	,1	,1	,&R1IE01LDU},	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
	{648	,1	,1	,&R1IS11LDU},	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
	{649	,1	,1	,&R1IS21LDU},	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
	{650	,3	,1	,&R1VS01IDU},	//( - , DU) Готовность к управлению МДЗ1
	{651	,1	,1	,&R1VS12LDU},	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
	{652	,1	,1	,&R1VS22LDU},	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
	{653	,1	,1	,&R2AB01LDU},	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
	{654	,1	,1	,&R2AB02LDU},	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
	{655	,1	,1	,&R2AB04LDU},	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
	{656	,1	,1	,&R2AD10LDU},	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
	{657	,1	,1	,&R2AD20LDU},	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
	{658	,1	,1	,&R2AZ03LDU},	//( - , DU) Несанкционированное перемещение МДЗ2
	{659	,1	,1	,&R2IE01LDU},	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
	{660	,1	,1	,&R2IS11LDU},	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
	{661	,1	,1	,&R2IS21LDU},	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
	{662	,3	,1	,&R2VS01IDU},	//( - , DU) Готовность к управлению МДЗ2
	{663	,1	,1	,&R2VS12LDU},	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
	{664	,1	,1	,&R2VS22LDU},	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
	{665	,1	,1	,&R2ZAV},	//( - , DU) 
	{666	,1	,1	,&R3IS11LDU},	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
	{667	,1	,1	,&R3IS21LDU},	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
	{668	,3	,1	,&R3VS01IDU},	//( - , DU) Готовность к управлению гомогенных дверей
	{669	,1	,1	,&R3VS12LDU},	//( - , DU) Движение гомогенных дверей к открыты
	{670	,1	,1	,&R3VS22LDU},	//( - , DU) Движение гомогенных дверей к закрыты
	{671	,1	,1	,&R4AB01LDU},	//( - , DU) Блокировка движения тележки - АНИ не установлен
	{672	,1	,1	,&R4AB02LDU},	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
	{673	,1	,1	,&R4AB03LDU},	//( - , DU) Блокировка движения тележки - Самоход любого механизма
	{674	,1	,1	,&R4AB04LDU},	//( - , DU) Блокировка движения тележки - Превышение времени движения
	{675	,1	,1	,&R4AB05LDU},	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
	{676	,1	,1	,&R4AB06LDU},	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
	{677	,1	,1	,&R4AB07LDU},	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
	{678	,1	,1	,&R4AB08LDU},	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
	{679	,1	,1	,&R4AB09LDU},	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
	{680	,1	,1	,&R4AB10LDU},	//( - , DU) Блокировка тележки - не открыта биологическая защита
	{681	,1	,1	,&R4AB11LDU},	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
	{682	,1	,1	,&R4AB12LDU},	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
	{683	,1	,1	,&R4AB13LDU},	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
	{684	,1	,1	,&R4AB14LDU},	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
	{685	,1	,1	,&R4AB15LDU},	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
	{686	,1	,1	,&R4AB16LDU},	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
	{687	,1	,1	,&R4AB17LDU},	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
	{688	,1	,1	,&R4AB18LDU},	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
	{689	,1	,1	,&R4ABL},	//( - , DU) Блокировка тележки -
	{690	,1	,1	,&R4AD10LDU},	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
	{691	,1	,1	,&R4AD20LDU},	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
	{692	,1	,1	,&R4AZ03LDU},	//( - , DU) Несанкционированное перемещение тележки
	{693	,1	,1	,&R4IS11LDU},	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
	{694	,1	,1	,&R4IS12LDU},	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
	{695	,1	,1	,&R4IS21LDU},	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
	{696	,1	,1	,&R4IS22LDU},	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
	{697	,1	,1	,&R4MD11LP2},	//( - , DU) Кнопка ВПЕРЁД  (тележки)
	{698	,1	,1	,&R4MD21LP2},	//( - , DU) Кнопка НАЗАД  (тележки)
	{699	,1	,1	,&R4MD31LP2},	//( - , DU) Кнопка СТОП  (тележки)
	{700	,3	,1	,&R4VS01IDU},	//( - , DU) Готовность к управлению тележкой реактора
	{701	,1	,1	,&R4VS12LDU},	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
	{702	,1	,1	,&R4VS22LDU},	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
	{703	,1	,1	,&R5IS11LDU},	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
	{704	,1	,1	,&R5IS21LDU},	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
	{705	,3	,1	,&R5VS01IDU},	//( - , DU) Готовность к управлению ворот отстойной зоны
	{706	,1	,1	,&R5VS12LDU},	//( - , DU) Движение ворот отстойной зоны к открыты
	{707	,1	,1	,&R5VS22LDU},	//( - , DU) Движение ворот отстойной зоны к закрыты
	{708	,1	,1	,&R6IS21LDU},	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
	{709	,1	,1	,&R6IS31LDU},	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
	{710	,1	,1	,&R6IS32LDU},	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
	{711	,1	,1	,&R6IS41LDU},	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
	{712	,1	,1	,&R6IS42LDU},	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
	{713	,1	,1	,&R6IS51LDU},	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
	{714	,1	,1	,&R6IS52LDU},	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
	{715	,1	,1	,&R6IS61LDU},	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
	{716	,1	,1	,&R6IS66LZZ},	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{717	,1	,1	,&R6IS67LZZ},	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{718	,1	,1	,&R6IS68LZZ},	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
	{719	,1	,1	,&R8AD21LDU},	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
	{720	,1	,1	,&R8AD22LDU},	//(vds32:02 - K15VDSR, - ) Сигнал синхронизации с импульсом
	{721	,1	,1	,&R8IS11LDU},	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
	{722	,3	,1	,&TTLDU},	//( - , DU) ttl
	{723	,1	,1	,&TestDiagnDU},	//( - , DU) Неисправность от
	{724	,1	,1	,&bFirstEnterFlag},	//(bFirstEnterFlag) 
	{725	,5	,1	,&dEM_A1UC05UDU},	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
	{726	,5	,1	,&dEM_A1UC06UDU},	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
	{727	,5	,1	,&dEM_A2UC05UDU},	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
	{728	,5	,1	,&dEM_A2UC06UDU},	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
	{729	,5	,1	,&dEM_A3UC05UDU},	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
	{730	,5	,1	,&dEM_A3UC06UDU},	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
	{731	,5	,1	,&dEM_A8UC05UDU},	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
	{732	,5	,1	,&dEM_A8UC06UDU},	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
	{733	,8	,1	,&fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
	{734	,8	,1	,&fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
	{735	,8	,1	,&fEM_A1UC05RDU},	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
	{736	,8	,1	,&fEM_A1UC06RDU},	//(A1UC06RDU) Уставка определения самохода ББ  мм
	{737	,8	,1	,&fEM_A1UC07RDU},	//(A1UC07RDU) Зона возврата при наведении ББ мм
	{738	,8	,1	,&fEM_A1UC08RDU},	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
	{739	,8	,1	,&fEM_A1UC81RDU},	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
	{740	,8	,1	,&fEM_A1UC82RDU},	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
	{741	,8	,1	,&fEM_A1UC83RDU},	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
	{742	,8	,1	,&fEM_A1UL01RDU},	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{743	,8	,1	,&fEM_A1UL03RDU},	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
	{744	,8	,1	,&fEM_A1UL04RDU},	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
	{745	,8	,1	,&fEM_A1UL05RDU},	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
	{746	,8	,1	,&fEM_A1UR01RDU},	//(A1UR01RDU) коэффициент реактивности от координаты ББ
	{747	,8	,1	,&fEM_A1UV01RDU},	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
	{748	,8	,1	,&fEM_A1UV02RDU},	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
	{749	,8	,1	,&fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
	{750	,8	,1	,&fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
	{751	,8	,1	,&fEM_A2UC05RDU},	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
	{752	,8	,1	,&fEM_A2UC06RDU},	//(A2UC06RDU) Уставка определения самохода РБ  мм
	{753	,8	,1	,&fEM_A2UC07RDU},	//(A2UC07RDU) Зона возврата при наведении РБ  мм
	{754	,8	,1	,&fEM_A2UC08RDU},	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
	{755	,8	,1	,&fEM_A2UC81RDU},	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
	{756	,8	,1	,&fEM_A2UC82RDU},	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
	{757	,8	,1	,&fEM_A2UC83RDU},	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
	{758	,8	,1	,&fEM_A2UL01RDU},	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{759	,8	,1	,&fEM_A2UL03RDU},	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{760	,8	,1	,&fEM_A2UL04RDU},	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
	{761	,8	,1	,&fEM_A2UL05RDU},	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
	{762	,8	,1	,&fEM_A2UL83RDU},	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{763	,8	,1	,&fEM_A2UV01RDU},	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
	{764	,8	,1	,&fEM_A2UV02RDU},	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
	{765	,8	,1	,&fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
	{766	,8	,1	,&fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
	{767	,8	,1	,&fEM_A3UC05RDU},	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
	{768	,8	,1	,&fEM_A3UC06RDU},	//(A3UC06RDU) Уставка определения самохода ИС1  мм
	{769	,8	,1	,&fEM_A3UC07RDU},	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
	{770	,8	,1	,&fEM_A3UC08RDU},	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
	{771	,8	,1	,&fEM_A3UC09RDU},	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
	{772	,8	,1	,&fEM_A3UC81RDU},	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
	{773	,8	,1	,&fEM_A3UC82RDU},	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
	{774	,8	,1	,&fEM_A3UL01RDU},	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{775	,8	,1	,&fEM_A3UL03RDU},	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
	{776	,8	,1	,&fEM_A3UL04RDU},	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
	{777	,8	,1	,&fEM_A3UL05RDU},	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
	{778	,8	,1	,&fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{779	,8	,1	,&fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{780	,8	,1	,&fEM_A3UP43RDU},	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
	{781	,8	,1	,&fEM_A3UP44RDU},	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
	{782	,8	,1	,&fEM_A3UP53RDU},	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
	{783	,8	,1	,&fEM_A3UP54RDU},	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
	{784	,8	,1	,&fEM_A3UP85RDU},	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{785	,8	,1	,&fEM_A3UP86RDU},	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{786	,8	,1	,&fEM_A3UP87RDU},	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{787	,8	,1	,&fEM_A3UP88RDU},	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{788	,8	,1	,&fEM_A3UR01RDU},	//(A3UR01RDU) коэффициент реактивности от координаты ИС
	{789	,8	,1	,&fEM_A3UV01RDU},	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
	{790	,8	,1	,&fEM_A3UV02RDU},	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
	{791	,8	,1	,&fEM_A4UZ03RDU},	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
	{792	,8	,1	,&fEM_A4UZ04RDU},	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
	{793	,8	,1	,&fEM_A4UZ05RDU},	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
	{794	,8	,1	,&fEM_A5UZ03RDU},	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
	{795	,8	,1	,&fEM_A5UZ04RDU},	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
	{796	,8	,1	,&fEM_A5UZ05RDU},	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
	{797	,8	,1	,&fEM_A6UZ03RDU},	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
	{798	,8	,1	,&fEM_A6UZ04RDU},	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
	{799	,8	,1	,&fEM_A6UZ05RDU},	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
	{800	,8	,1	,&fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
	{801	,8	,1	,&fEM_A9UZ03RDU},	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
	{802	,8	,1	,&fEM_A9UZ04RDU},	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
	{803	,8	,1	,&fEM_A9UZ05RDU},	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
	{804	,8	,1	,&fEM_B8UC01RDU},	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
	{805	,8	,1	,&fEM_B8UC02RDU},	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
	{806	,8	,1	,&fEM_B8UC05RDU},	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
	{807	,8	,1	,&fEM_B8UC06RDU},	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
	{808	,8	,1	,&fEM_B8UL01RDU},	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{809	,8	,1	,&fEM_B8UL03RDU},	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
	{810	,8	,1	,&fEM_B8UL04RDU},	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
	{811	,8	,1	,&fEM_B8UL05RDU},	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
	{812	,8	,1	,&fEM_B8UL06RDU},	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
	{813	,8	,1	,&fEM_B8UL07RDU},	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
	{814	,8	,1	,&fEM_B8UV01RDU},	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
	{815	,8	,1	,&fEM_B8UV02RDU},	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
	{816	,8	,1	,&fEM_B8UV03RDU},	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
	{817	,8	,1	,&fEM_B8UV04RDU},	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
	{818	,8	,1	,&fEM_R0UL00RDU},	//(R0UL00RDU) Время ожидания передачи  сигнала отключения сети
	{819	,8	,1	,&fEM_R0UL01RSS},	//(R0UL01RSS) Шаг измерения периода (сек)
	{820	,8	,1	,&fEM_R0UL02RDU},	//(R0UL02RDU) Время задержки  ИНИ
	{821	,8	,1	,&fEM_R0UL02RSS},	//(R0UL02RSS) Tф-постоянная времени, с
	{822	,8	,1	,&fEM_R0UL03RDU},	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
	{823	,8	,1	,&fEM_R0UL04RDU},	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
	{824	,8	,1	,&fEM_R0UL05RDU},	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
	{825	,8	,1	,&fEM_R0UL06RDU},	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
	{826	,8	,1	,&fEM_R0UL07RDU},	//(R0UL07RDU) Время срабатывания верхней АС II УР
	{827	,8	,1	,&fEM_R0UL16RDU},	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
	{828	,8	,1	,&fEM_R0UL17RDU},	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
	{829	,8	,1	,&fEM_R0UL18RDU},	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
	{830	,8	,1	,&fEM_R0UL19RDU},	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{831	,8	,1	,&fEM_R0UL20RDU},	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
	{832	,8	,1	,&fEM_R0UL21RDU},	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
	{833	,8	,1	,&fEM_R0UL25RDU},	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{834	,8	,1	,&fEM_R0UN01RDU},	//(R0UN01RDU) 1-я заданная мощность
	{835	,8	,1	,&fEM_R0UN02RDU},	//(R0UN02RDU) 2-я заданная мощность
	{836	,8	,1	,&fEM_R0UN03RDU},	//(R0UN03RDU) Ограничение 3 по мощности
	{837	,8	,1	,&fEM_R0UN03RSS},	//(R0UN03RSS) нижняя граница мощности для индикации периода  (ватт)
	{838	,8	,1	,&fEM_R0UN04RDU},	//(R0UN04RDU) 4-я заданная мощность
	{839	,8	,1	,&fEM_R0UN05RDU},	//(R0UN05RDU) 5-я заданная мощность
	{840	,8	,1	,&fEM_R0UN06RDU},	//(R0UN06RDU) 6-я заданная мощность
	{841	,8	,1	,&fEM_R0UN07RDU},	//(R0UN07RDU) 7-я заданная мощность
	{842	,8	,1	,&fEM_R0UN08RDU},	//(R0UN08RDU) 8-я заданная мощность
	{843	,8	,1	,&fEM_R0UN09RDU},	//(R0UN09RDU) Минимальный период при регулировании мощности
	{844	,8	,1	,&fEM_R0UN11RDU},	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
	{845	,8	,1	,&fEM_R0UN12RDU},	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
	{846	,8	,1	,&fEM_R0UN14RDU},	//(R0UN14RDU) Максимальная координата штока ИС, мм
	{847	,8	,1	,&fEM_R0UN15RDU},	//(R0UN15RDU) Минимальная координата штока ББ, мм
	{848	,8	,1	,&fEM_R0UN16RDU},	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
	{849	,8	,1	,&fEM_R0UN17RDU},	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
	{850	,8	,1	,&fEM_R0UN18RDU},	//(R0UN18RDU) Коэффициент температурной корректировки реактивности(долл)
	{851	,8	,1	,&fEM_R0UN19RDU},	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
	{852	,8	,1	,&fEM_R0UN70LDU},	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
	{853	,8	,1	,&fEM_R0UN71LDU},	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
	{854	,8	,1	,&fEM_R0UN72LDU},	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
	{855	,8	,1	,&fEM_R0UN73LDU},	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
	{856	,8	,1	,&fEM_R0UN74LDU},	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
	{857	,8	,1	,&fEM_R0UN75LDU},	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
	{858	,8	,1	,&fEM_R0UN80LDU},	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
	{859	,8	,1	,&fEM_R0UN80RDU},	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
	{860	,8	,1	,&fEM_R0UN81LDU},	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
	{861	,8	,1	,&fEM_R0UN82LDU},	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
	{862	,8	,1	,&fEM_R0UN83LDU},	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
	{863	,8	,1	,&fEM_R0UN84LDU},	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
	{864	,8	,1	,&fEM_R0UN85LDU},	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
	{865	,8	,1	,&fEM_R0UT20RDU},	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
	{866	,8	,1	,&fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{867	,8	,1	,&fEM_R0UV82RDU},	//(R0UV82RDU) 2-я частота двигателя (шагов/секунду)
	{868	,8	,1	,&fEM_R0UV83RDU},	//(R0UV83RDU) 3-я частота двигателя (шагов/секунду)
	{869	,8	,1	,&fEM_R0UV84RDU},	//(R0UV84RDU) 4-я частота двигателя (шагов/секунду)
	{870	,8	,1	,&fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{871	,8	,1	,&fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{872	,8	,1	,&fEM_R0UV87RDU},	//(R0UV87RDU) 8-я скорость перемещения ББ (шагов/секунду)
	{873	,8	,1	,&fEM_R1UZ03RDU},	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
	{874	,8	,1	,&fEM_R1UZ04RDU},	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
	{875	,8	,1	,&fEM_R1UZ05RDU},	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
	{876	,8	,1	,&fEM_R4UZ03RDU},	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
	{877	,8	,1	,&fEM_R4UZ04RDU},	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
	{878	,8	,1	,&fEM_R4UZ05RDU},	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
	{879	,8	,1	,&fEM_R7UI76RDU},	//(R7UI76RDU) Время срабатывания сигнала II УР при имитации
	{880	,3	,1	,&iEM_A1UV01IDU},	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
	{881	,3	,1	,&iEM_A1UV02IDU},	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
	{882	,3	,1	,&iEM_A1UV03IDU},	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
	{883	,3	,1	,&iEM_A2UV01IDU},	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
	{884	,3	,1	,&iEM_A2UV02IDU},	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
	{885	,3	,1	,&iEM_A2UV03CDU},	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
	{886	,3	,1	,&iEM_A3UV01IDU},	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
	{887	,3	,1	,&iEM_A3UV02IDU},	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
	{888	,18	,1	,&internal1_m1007_BLDv0},	//(internal1_m1007_BLDv0) BlDv - Блокировка движения
	{889	,8	,1	,&internal1_m1007_X0},	//(internal1_m1007_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{890	,8	,1	,&internal1_m1007_t0},	//(internal1_m1007_t0) время нахождения в зоне возврата
	{891	,8	,1	,&internal1_m1029_tx},	//(internal1_m1029_tx) tx - время накопленное сек
	{892	,18	,1	,&internal1_m1029_y0},	//(internal1_m1029_y0) y0
	{893	,8	,1	,&internal1_m1030_tx},	//(internal1_m1030_tx) tx - время накопленное сек
	{894	,18	,1	,&internal1_m1030_y0},	//(internal1_m1030_y0) y0
	{895	,8	,1	,&internal1_m1031_tx},	//(internal1_m1031_tx) tx - внутренний параметр
	{896	,8	,1	,&internal1_m1037_DelSp},	//(internal1_m1037_DelSp) DelSp - время переключения скоростей
	{897	,1	,1	,&internal1_m1037_ShCntlSp0},	//(internal1_m1037_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{898	,1	,1	,&internal1_m1037_Shift0},	//(internal1_m1037_Shift0) Shift0 - признак самохода
	{899	,1	,1	,&internal1_m1037_ShiftControl},	//(internal1_m1037_ShiftControl) ShiftControl - признак самохода
	{900	,8	,1	,&internal1_m1037_Speed0},	//(internal1_m1037_Speed0) Speed0 - предыдущее значение скорости перемещения
	{901	,8	,1	,&internal1_m1037_StSpeed},	//(internal1_m1037_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{902	,8	,1	,&internal1_m1037_Vz0},	//(internal1_m1037_Vz0) Vz0 - предыдущая заданная скорость
	{903	,3	,1	,&internal1_m1037_flRazg},	//(internal1_m1037_flRazg) признак разгона/торможения
	{904	,8	,1	,&internal1_m1037_sumtim},	//(internal1_m1037_sumtim) sumtim - время в пути
	{905	,8	,60	,&internal1_m1037_tim0},	//(internal1_m1037_tim0) tim0 - массив значений времени цикла
	{906	,8	,1	,&internal1_m1037_tx},	//(internal1_m1037_tx) tx
	{907	,8	,1	,&internal1_m1037_txBl},	//(internal1_m1037_txBl) tx
	{908	,8	,1	,&internal1_m1037_txMBl},	//(internal1_m1037_txMBl) tx
	{909	,8	,1	,&internal1_m1037_txZS},	//(internal1_m1037_txZS) txZS
	{910	,8	,1	,&internal1_m1037_txd},	//(internal1_m1037_txd) txd
	{911	,8	,1	,&internal1_m1037_tz0},	//(internal1_m1037_tz0) tz0 - время защиты от нового задания сек
	{912	,8	,60	,&internal1_m1037_x0},	//(internal1_m1037_x0) x0 - массив мгновенных значений координат
	{913	,3	,1	,&internal1_m1037_xptr},	//(internal1_m1037_xptr) указатель текущей позиции в массиве координат
	{914	,8	,1	,&internal1_m1037_xz0},	//(internal1_m1037_xz0) xz0 - новое задание мм
	{915	,8	,1	,&internal1_m1037_z0},	//(internal1_m1037_z0) z0 - точка прекращения движения
	{916	,8	,1	,&internal1_m1041_tx},	//(internal1_m1041_tx) tx - внутренний параметр
	{917	,8	,1	,&internal1_m1042_tx},	//(internal1_m1042_tx) tx - внутренний параметр
	{918	,8	,1	,&internal1_m1048_tx},	//(internal1_m1048_tx) tx - внутренний параметр
	{919	,8	,1	,&internal1_m1054_tx},	//(internal1_m1054_tx) tx - время накопленное сек
	{920	,18	,1	,&internal1_m1054_y0},	//(internal1_m1054_y0) y0
	{921	,8	,1	,&internal1_m1063_tx},	//(internal1_m1063_tx) tx - внутренний параметр
	{922	,8	,1	,&internal1_m1064_tx},	//(internal1_m1064_tx) tx - внутренний параметр
	{923	,8	,1	,&internal1_m1066_tx},	//(internal1_m1066_tx) tx - внутренний параметр
	{924	,8	,1	,&internal1_m1076_tx},	//(internal1_m1076_tx) tx - внутренний параметр
	{925	,8	,1	,&internal1_m1079_tx},	//(internal1_m1079_tx) tx - внутренний параметр
	{926	,8	,1	,&internal1_m1080_tx},	//(internal1_m1080_tx) tx - внутренний параметр
	{927	,8	,1	,&internal1_m1089_tx},	//(internal1_m1089_tx) tx - внутренний параметр
	{928	,8	,1	,&internal1_m1091_tx},	//(internal1_m1091_tx) tx - внутренний параметр
	{929	,8	,1	,&internal1_m1098_tx},	//(internal1_m1098_tx) tx - внутренний параметр
	{930	,8	,1	,&internal1_m1099_tx},	//(internal1_m1099_tx) tx - внутренний параметр
	{931	,8	,1	,&internal1_m1100_tx},	//(internal1_m1100_tx) tx - внутренний параметр
	{932	,8	,1	,&internal1_m1101_tx},	//(internal1_m1101_tx) tx - внутренний параметр
	{933	,8	,1	,&internal1_m1102_tx},	//(internal1_m1102_tx) tx - внутренний параметр
	{934	,8	,1	,&internal1_m110_tx},	//(internal1_m110_tx) tx - внутренний параметр
	{935	,1	,1	,&internal1_m1118_q0},	//(internal1_m1118_q0) q0 - внутренний параметр
	{936	,1	,1	,&internal1_m1126_q0},	//(internal1_m1126_q0) q0 - внутренний параметр
	{937	,1	,1	,&internal1_m1147_q0},	//(internal1_m1147_q0) q0 - внутренний параметр
	{938	,8	,1	,&internal1_m1150_tx},	//(internal1_m1150_tx) tx - внутренний параметр
	{939	,1	,1	,&internal1_m1151_q0},	//(internal1_m1151_q0) q0 - внутренний параметр
	{940	,1	,1	,&internal1_m1153_q0},	//(internal1_m1153_q0) q0 - внутренний параметр
	{941	,1	,1	,&internal1_m1154_q0},	//(internal1_m1154_q0) q0 - внутренний параметр
	{942	,1	,1	,&internal1_m1158_q0},	//(internal1_m1158_q0) q0 - внутренний параметр
	{943	,1	,1	,&internal1_m1169_q0},	//(internal1_m1169_q0) q0 - внутренний параметр
	{944	,1	,1	,&internal1_m1170_q0},	//(internal1_m1170_q0) q0 - внутренний параметр
	{945	,1	,1	,&internal1_m1182_q0},	//(internal1_m1182_q0) q0 - внутренний параметр
	{946	,1	,1	,&internal1_m1184_q0},	//(internal1_m1184_q0) q0 - внутренний параметр
	{947	,1	,1	,&internal1_m118_q0},	//(internal1_m118_q0) q0 - внутренний параметр
	{948	,1	,1	,&internal1_m1191_q0},	//(internal1_m1191_q0) q0 - внутренний параметр
	{949	,1	,1	,&internal1_m1199_q0},	//(internal1_m1199_q0) q0 - внутренний параметр
	{950	,1	,1	,&internal1_m1200_q0},	//(internal1_m1200_q0) q0 - внутренний параметр
	{951	,1	,1	,&internal1_m1202_q0},	//(internal1_m1202_q0) q0 - внутренний параметр
	{952	,1	,1	,&internal1_m1203_q0},	//(internal1_m1203_q0) q0 - внутренний параметр
	{953	,1	,1	,&internal1_m1205_q0},	//(internal1_m1205_q0) q0 - внутренний параметр
	{954	,1	,1	,&internal1_m1206_q0},	//(internal1_m1206_q0) q0 - внутренний параметр
	{955	,1	,1	,&internal1_m1208_q0},	//(internal1_m1208_q0) q0 - внутренний параметр
	{956	,1	,1	,&internal1_m1209_q0},	//(internal1_m1209_q0) q0 - внутренний параметр
	{957	,1	,1	,&internal1_m1211_q0},	//(internal1_m1211_q0) q0 - внутренний параметр
	{958	,8	,1	,&internal1_m122_tx},	//(internal1_m122_tx) tx - внутренний параметр
	{959	,8	,1	,&internal1_m1244_tx},	//(internal1_m1244_tx) tx - внутренний параметр
	{960	,8	,1	,&internal1_m1246_tx},	//(internal1_m1246_tx) tx - внутренний параметр
	{961	,8	,1	,&internal1_m1248_tx},	//(internal1_m1248_tx) tx - внутренний параметр
	{962	,8	,1	,&internal1_m124_tx},	//(internal1_m124_tx) tx - внутренний параметр
	{963	,8	,1	,&internal1_m1250_tx},	//(internal1_m1250_tx) tx - внутренний параметр
	{964	,8	,1	,&internal1_m1257_tx},	//(internal1_m1257_tx) tx - внутренний параметр
	{965	,8	,1	,&internal1_m1258_tx},	//(internal1_m1258_tx) tx - внутренний параметр
	{966	,8	,1	,&internal1_m1259_tx},	//(internal1_m1259_tx) tx - внутренний параметр
	{967	,8	,1	,&internal1_m1265_tx},	//(internal1_m1265_tx) tx - внутренний параметр
	{968	,18	,1	,&internal1_m1277_BLDv0},	//(internal1_m1277_BLDv0) BlDv - Блокировка движения
	{969	,8	,1	,&internal1_m1277_X0},	//(internal1_m1277_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{970	,8	,1	,&internal1_m1277_t0},	//(internal1_m1277_t0) время нахождения в зоне возврата
	{971	,18	,1	,&internal1_m1281_BlDv0},	//(internal1_m1281_BlDv0) - была блокировка
	{972	,18	,1	,&internal1_m1281_DvDw0},	//(internal1_m1281_DvDw0) - есть команда на движение назад
	{973	,18	,1	,&internal1_m1281_DvUp0},	//(internal1_m1281_DvUp0) - есть команда на движение вперёд
	{974	,18	,1	,&internal1_m1281_FDvDw0},	//(internal1_m1281_FDvDw0) - есть команда на движение назад
	{975	,18	,1	,&internal1_m1281_FDvUp0},	//(internal1_m1281_FDvUp0) - есть команда на движение вперёд
	{976	,18	,1	,&internal1_m1281_Pkav0},	//(internal1_m1281_Pkav0) Pkav - передний конечный аварийный выключатель
	{977	,18	,1	,&internal1_m1281_Pkv0},	//(internal1_m1281_Pkv0) Pkv - передний конечный выключатель
	{978	,18	,1	,&internal1_m1281_Zkav0},	//(internal1_m1281_Zkav0) Zkav - задний конечный аварийный выключатель
	{979	,18	,1	,&internal1_m1281_Zkv0},	//(internal1_m1281_Zkv0) Zkv - задний конечный выключатель
	{980	,18	,1	,&internal1_m1281_fef},	//(internal1_m1281_fef) fef
	{981	,8	,1	,&internal1_m1281_txHr},	//(internal1_m1281_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{982	,8	,1	,&internal1_m1281_txLd},	//(internal1_m1281_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{983	,8	,1	,&internal1_m1281_txNm},	//(internal1_m1281_txNm) txNm - счётчик задержки сигнализации недвижения
	{984	,8	,1	,&internal1_m1281_txSm},	//(internal1_m1281_txSm) txSm - счётчик задержки сигнализации самохода
	{985	,8	,1	,&internal1_m1286_tx},	//(internal1_m1286_tx) tx - внутренний параметр
	{986	,8	,1	,&internal1_m1287_tx},	//(internal1_m1287_tx) tx - внутренний параметр
	{987	,8	,1	,&internal1_m1292_tx},	//(internal1_m1292_tx) tx - время накопленное сек
	{988	,18	,1	,&internal1_m1292_y0},	//(internal1_m1292_y0) y0
	{989	,8	,1	,&internal1_m1294_tx},	//(internal1_m1294_tx) tx - внутренний параметр
	{990	,8	,1	,&internal1_m1296_tx},	//(internal1_m1296_tx) tx - время накопленное сек
	{991	,18	,1	,&internal1_m1296_y0},	//(internal1_m1296_y0) y0
	{992	,8	,1	,&internal1_m1299_tx},	//(internal1_m1299_tx) tx - внутренний параметр
	{993	,8	,1	,&internal1_m129_tx},	//(internal1_m129_tx) tx - внутренний параметр
	{994	,8	,1	,&internal1_m1300_tx},	//(internal1_m1300_tx) tx - внутренний параметр
	{995	,8	,1	,&internal1_m1302_DelSp},	//(internal1_m1302_DelSp) DelSp - время переключения скоростей
	{996	,1	,1	,&internal1_m1302_ShCntlSp0},	//(internal1_m1302_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{997	,1	,1	,&internal1_m1302_Shift0},	//(internal1_m1302_Shift0) Shift0 - признак самохода
	{998	,1	,1	,&internal1_m1302_ShiftControl},	//(internal1_m1302_ShiftControl) ShiftControl - признак самохода
	{999	,8	,1	,&internal1_m1302_Speed0},	//(internal1_m1302_Speed0) Speed0 - предыдущее значение скорости перемещения
	{1000	,8	,1	,&internal1_m1302_StSpeed},	//(internal1_m1302_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{1001	,8	,1	,&internal1_m1302_Vz0},	//(internal1_m1302_Vz0) Vz0 - предыдущая заданная скорость
	{1002	,3	,1	,&internal1_m1302_flRazg},	//(internal1_m1302_flRazg) признак разгона/торможения
	{1003	,8	,1	,&internal1_m1302_sumtim},	//(internal1_m1302_sumtim) sumtim - время в пути
	{1004	,8	,20	,&internal1_m1302_tim0},	//(internal1_m1302_tim0) tim0 - массив значений времени цикла
	{1005	,8	,1	,&internal1_m1302_tx},	//(internal1_m1302_tx) tx
	{1006	,8	,1	,&internal1_m1302_txBl},	//(internal1_m1302_txBl) tx
	{1007	,8	,1	,&internal1_m1302_txMBl},	//(internal1_m1302_txMBl) tx
	{1008	,8	,1	,&internal1_m1302_txZS},	//(internal1_m1302_txZS) txZS
	{1009	,8	,1	,&internal1_m1302_txd},	//(internal1_m1302_txd) txd
	{1010	,8	,1	,&internal1_m1302_tz0},	//(internal1_m1302_tz0) tz0 - время защиты от нового задания сек
	{1011	,8	,20	,&internal1_m1302_x0},	//(internal1_m1302_x0) x0 - массив мгновенных значений координат
	{1012	,3	,1	,&internal1_m1302_xptr},	//(internal1_m1302_xptr) указатель текущей позиции в массиве координат
	{1013	,8	,1	,&internal1_m1302_xz0},	//(internal1_m1302_xz0) xz0 - новое задание мм
	{1014	,8	,1	,&internal1_m1302_z0},	//(internal1_m1302_z0) z0 - точка прекращения движения
	{1015	,8	,1	,&internal1_m1305_tx},	//(internal1_m1305_tx) tx - внутренний параметр
	{1016	,8	,1	,&internal1_m1307_tx},	//(internal1_m1307_tx) tx - время накопленное сек
	{1017	,18	,1	,&internal1_m1307_y0},	//(internal1_m1307_y0) y0
	{1018	,8	,1	,&internal1_m1328_tx},	//(internal1_m1328_tx) tx - внутренний параметр
	{1019	,8	,1	,&internal1_m1329_tx},	//(internal1_m1329_tx) tx - внутренний параметр
	{1020	,8	,1	,&internal1_m1332_tx},	//(internal1_m1332_tx) tx - внутренний параметр
	{1021	,18	,1	,&internal1_m1335_BlDv0},	//(internal1_m1335_BlDv0) - была блокировка
	{1022	,18	,1	,&internal1_m1335_DvDw0},	//(internal1_m1335_DvDw0) - есть команда на движение назад
	{1023	,18	,1	,&internal1_m1335_DvUp0},	//(internal1_m1335_DvUp0) - есть команда на движение вперёд
	{1024	,18	,1	,&internal1_m1335_FDvDw0},	//(internal1_m1335_FDvDw0) - есть команда на движение назад
	{1025	,18	,1	,&internal1_m1335_FDvUp0},	//(internal1_m1335_FDvUp0) - есть команда на движение вперёд
	{1026	,18	,1	,&internal1_m1335_Pkav0},	//(internal1_m1335_Pkav0) Pkav - передний конечный аварийный выключатель
	{1027	,18	,1	,&internal1_m1335_Pkv0},	//(internal1_m1335_Pkv0) Pkv - передний конечный выключатель
	{1028	,18	,1	,&internal1_m1335_Zkav0},	//(internal1_m1335_Zkav0) Zkav - задний конечный аварийный выключатель
	{1029	,18	,1	,&internal1_m1335_Zkv0},	//(internal1_m1335_Zkv0) Zkv - задний конечный выключатель
	{1030	,18	,1	,&internal1_m1335_fef},	//(internal1_m1335_fef) fef
	{1031	,8	,1	,&internal1_m1335_txHr},	//(internal1_m1335_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{1032	,8	,1	,&internal1_m1335_txLd},	//(internal1_m1335_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{1033	,8	,1	,&internal1_m1335_txNm},	//(internal1_m1335_txNm) txNm - счётчик задержки сигнализации недвижения
	{1034	,8	,1	,&internal1_m1335_txSm},	//(internal1_m1335_txSm) txSm - счётчик задержки сигнализации самохода
	{1035	,8	,1	,&internal1_m1343_tx},	//(internal1_m1343_tx) tx - внутренний параметр
	{1036	,18	,1	,&internal1_m1345_BlDv0},	//(internal1_m1345_BlDv0) - была блокировка
	{1037	,18	,1	,&internal1_m1345_DvDw0},	//(internal1_m1345_DvDw0) - есть команда на движение назад
	{1038	,18	,1	,&internal1_m1345_DvUp0},	//(internal1_m1345_DvUp0) - есть команда на движение вперёд
	{1039	,18	,1	,&internal1_m1345_FDvDw0},	//(internal1_m1345_FDvDw0) - есть команда на движение назад
	{1040	,18	,1	,&internal1_m1345_FDvUp0},	//(internal1_m1345_FDvUp0) - есть команда на движение вперёд
	{1041	,18	,1	,&internal1_m1345_Pkav0},	//(internal1_m1345_Pkav0) Pkav - передний конечный аварийный выключатель
	{1042	,18	,1	,&internal1_m1345_Pkv0},	//(internal1_m1345_Pkv0) Pkv - передний конечный выключатель
	{1043	,18	,1	,&internal1_m1345_Zkav0},	//(internal1_m1345_Zkav0) Zkav - задний конечный аварийный выключатель
	{1044	,18	,1	,&internal1_m1345_Zkv0},	//(internal1_m1345_Zkv0) Zkv - задний конечный выключатель
	{1045	,18	,1	,&internal1_m1345_fef},	//(internal1_m1345_fef) fef
	{1046	,8	,1	,&internal1_m1345_txHr},	//(internal1_m1345_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{1047	,8	,1	,&internal1_m1345_txLd},	//(internal1_m1345_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{1048	,8	,1	,&internal1_m1345_txNm},	//(internal1_m1345_txNm) txNm - счётчик задержки сигнализации недвижения
	{1049	,8	,1	,&internal1_m1345_txSm},	//(internal1_m1345_txSm) txSm - счётчик задержки сигнализации самохода
	{1050	,8	,1	,&internal1_m1349_tx},	//(internal1_m1349_tx) tx - внутренний параметр
	{1051	,8	,1	,&internal1_m1350_tx},	//(internal1_m1350_tx) tx - внутренний параметр
	{1052	,8	,1	,&internal1_m1351_tx},	//(internal1_m1351_tx) tx - внутренний параметр
	{1053	,18	,1	,&internal1_m1372_BLDv0},	//(internal1_m1372_BLDv0) BlDv - Блокировка движения
	{1054	,8	,1	,&internal1_m1372_X0},	//(internal1_m1372_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{1055	,8	,1	,&internal1_m1372_t0},	//(internal1_m1372_t0) время нахождения в зоне возврата
	{1056	,8	,1	,&internal1_m1392_tx},	//(internal1_m1392_tx) tx - внутренний параметр
	{1057	,8	,1	,&internal1_m1395_tx},	//(internal1_m1395_tx) tx - внутренний параметр
	{1058	,8	,1	,&internal1_m1399_tx},	//(internal1_m1399_tx) tx - время накопленное сек
	{1059	,18	,1	,&internal1_m1399_y0},	//(internal1_m1399_y0) y0
	{1060	,8	,1	,&internal1_m13_tx},	//(internal1_m13_tx) tx - внутренний параметр
	{1061	,8	,1	,&internal1_m1400_tx},	//(internal1_m1400_tx) tx - время накопленное сек
	{1062	,18	,1	,&internal1_m1400_y0},	//(internal1_m1400_y0) y0
	{1063	,8	,1	,&internal1_m1407_DelSp},	//(internal1_m1407_DelSp) DelSp - время переключения скоростей
	{1064	,1	,1	,&internal1_m1407_ShCntlSp0},	//(internal1_m1407_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{1065	,1	,1	,&internal1_m1407_Shift0},	//(internal1_m1407_Shift0) Shift0 - признак самохода
	{1066	,1	,1	,&internal1_m1407_ShiftControl},	//(internal1_m1407_ShiftControl) ShiftControl - признак самохода
	{1067	,8	,1	,&internal1_m1407_Speed0},	//(internal1_m1407_Speed0) Speed0 - предыдущее значение скорости перемещения
	{1068	,8	,1	,&internal1_m1407_StSpeed},	//(internal1_m1407_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{1069	,8	,1	,&internal1_m1407_Vz0},	//(internal1_m1407_Vz0) Vz0 - предыдущая заданная скорость
	{1070	,3	,1	,&internal1_m1407_flRazg},	//(internal1_m1407_flRazg) признак разгона/торможения
	{1071	,8	,1	,&internal1_m1407_sumtim},	//(internal1_m1407_sumtim) sumtim - время в пути
	{1072	,8	,80	,&internal1_m1407_tim0},	//(internal1_m1407_tim0) tim0 - массив значений времени цикла
	{1073	,8	,1	,&internal1_m1407_tx},	//(internal1_m1407_tx) tx
	{1074	,8	,1	,&internal1_m1407_txBl},	//(internal1_m1407_txBl) tx
	{1075	,8	,1	,&internal1_m1407_txMBl},	//(internal1_m1407_txMBl) tx
	{1076	,8	,1	,&internal1_m1407_txZS},	//(internal1_m1407_txZS) txZS
	{1077	,8	,1	,&internal1_m1407_txd},	//(internal1_m1407_txd) txd
	{1078	,8	,1	,&internal1_m1407_tz0},	//(internal1_m1407_tz0) tz0 - время защиты от нового задания сек
	{1079	,8	,80	,&internal1_m1407_x0},	//(internal1_m1407_x0) x0 - массив мгновенных значений координат
	{1080	,3	,1	,&internal1_m1407_xptr},	//(internal1_m1407_xptr) указатель текущей позиции в массиве координат
	{1081	,8	,1	,&internal1_m1407_xz0},	//(internal1_m1407_xz0) xz0 - новое задание мм
	{1082	,8	,1	,&internal1_m1407_z0},	//(internal1_m1407_z0) z0 - точка прекращения движения
	{1083	,8	,1	,&internal1_m1410_tx},	//(internal1_m1410_tx) tx - внутренний параметр
	{1084	,8	,1	,&internal1_m1413_tx},	//(internal1_m1413_tx) tx - внутренний параметр
	{1085	,8	,1	,&internal1_m1417_tx},	//(internal1_m1417_tx) tx - время накопленное сек
	{1086	,18	,1	,&internal1_m1417_y0},	//(internal1_m1417_y0) y0
	{1087	,8	,1	,&internal1_m1428_tx},	//(internal1_m1428_tx) tx - внутренний параметр
	{1088	,8	,1	,&internal1_m1430_tx},	//(internal1_m1430_tx) tx - внутренний параметр
	{1089	,8	,1	,&internal1_m1432_tx},	//(internal1_m1432_tx) tx - внутренний параметр
	{1090	,8	,1	,&internal1_m1443_tx},	//(internal1_m1443_tx) tx - внутренний параметр
	{1091	,8	,1	,&internal1_m1447_tx},	//(internal1_m1447_tx) tx - внутренний параметр
	{1092	,8	,1	,&internal1_m1448_tx},	//(internal1_m1448_tx) tx - внутренний параметр
	{1093	,8	,1	,&internal1_m1457_tx},	//(internal1_m1457_tx) tx - внутренний параметр
	{1094	,8	,1	,&internal1_m1458_tx},	//(internal1_m1458_tx) tx - внутренний параметр
	{1095	,8	,1	,&internal1_m1464_tx},	//(internal1_m1464_tx) tx - внутренний параметр
	{1096	,8	,1	,&internal1_m1465_tx},	//(internal1_m1465_tx) tx - внутренний параметр
	{1097	,8	,1	,&internal1_m1466_tx},	//(internal1_m1466_tx) tx - внутренний параметр
	{1098	,8	,1	,&internal1_m1467_tx},	//(internal1_m1467_tx) tx - внутренний параметр
	{1099	,18	,1	,&internal1_m1485_BLDv0},	//(internal1_m1485_BLDv0) BlDv - Блокировка движения
	{1100	,8	,1	,&internal1_m1485_X0},	//(internal1_m1485_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{1101	,8	,1	,&internal1_m1485_t0},	//(internal1_m1485_t0) время нахождения в зоне возврата
	{1102	,8	,1	,&internal1_m1502_tx},	//(internal1_m1502_tx) tx - время накопленное сек
	{1103	,18	,1	,&internal1_m1502_y0},	//(internal1_m1502_y0) y0
	{1104	,8	,1	,&internal1_m1503_tx},	//(internal1_m1503_tx) tx - время накопленное сек
	{1105	,18	,1	,&internal1_m1503_y0},	//(internal1_m1503_y0) y0
	{1106	,8	,1	,&internal1_m1508_tx},	//(internal1_m1508_tx) tx - внутренний параметр
	{1107	,8	,1	,&internal1_m1509_tx},	//(internal1_m1509_tx) tx - внутренний параметр
	{1108	,8	,1	,&internal1_m1511_DelSp},	//(internal1_m1511_DelSp) DelSp - время переключения скоростей
	{1109	,1	,1	,&internal1_m1511_ShCntlSp0},	//(internal1_m1511_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{1110	,1	,1	,&internal1_m1511_Shift0},	//(internal1_m1511_Shift0) Shift0 - признак самохода
	{1111	,1	,1	,&internal1_m1511_ShiftControl},	//(internal1_m1511_ShiftControl) ShiftControl - признак самохода
	{1112	,8	,1	,&internal1_m1511_Speed0},	//(internal1_m1511_Speed0) Speed0 - предыдущее значение скорости перемещения
	{1113	,8	,1	,&internal1_m1511_StSpeed},	//(internal1_m1511_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{1114	,8	,1	,&internal1_m1511_Vz0},	//(internal1_m1511_Vz0) Vz0 - предыдущая заданная скорость
	{1115	,3	,1	,&internal1_m1511_flRazg},	//(internal1_m1511_flRazg) признак разгона/торможения
	{1116	,8	,1	,&internal1_m1511_sumtim},	//(internal1_m1511_sumtim) sumtim - время в пути
	{1117	,8	,60	,&internal1_m1511_tim0},	//(internal1_m1511_tim0) tim0 - массив значений времени цикла
	{1118	,8	,1	,&internal1_m1511_tx},	//(internal1_m1511_tx) tx
	{1119	,8	,1	,&internal1_m1511_txBl},	//(internal1_m1511_txBl) tx
	{1120	,8	,1	,&internal1_m1511_txMBl},	//(internal1_m1511_txMBl) tx
	{1121	,8	,1	,&internal1_m1511_txZS},	//(internal1_m1511_txZS) txZS
	{1122	,8	,1	,&internal1_m1511_txd},	//(internal1_m1511_txd) txd
	{1123	,8	,1	,&internal1_m1511_tz0},	//(internal1_m1511_tz0) tz0 - время защиты от нового задания сек
	{1124	,8	,60	,&internal1_m1511_x0},	//(internal1_m1511_x0) x0 - массив мгновенных значений координат
	{1125	,3	,1	,&internal1_m1511_xptr},	//(internal1_m1511_xptr) указатель текущей позиции в массиве координат
	{1126	,8	,1	,&internal1_m1511_xz0},	//(internal1_m1511_xz0) xz0 - новое задание мм
	{1127	,8	,1	,&internal1_m1511_z0},	//(internal1_m1511_z0) z0 - точка прекращения движения
	{1128	,8	,1	,&internal1_m1518_tx},	//(internal1_m1518_tx) tx - внутренний параметр
	{1129	,8	,1	,&internal1_m1521_tx},	//(internal1_m1521_tx) tx - внутренний параметр
	{1130	,8	,1	,&internal1_m1527_tx},	//(internal1_m1527_tx) tx - время накопленное сек
	{1131	,18	,1	,&internal1_m1527_y0},	//(internal1_m1527_y0) y0
	{1132	,8	,1	,&internal1_m1536_tx},	//(internal1_m1536_tx) tx - внутренний параметр
	{1133	,8	,1	,&internal1_m1537_tx},	//(internal1_m1537_tx) tx - внутренний параметр
	{1134	,8	,1	,&internal1_m1539_tx},	//(internal1_m1539_tx) tx - внутренний параметр
	{1135	,8	,1	,&internal1_m1549_tx},	//(internal1_m1549_tx) tx - внутренний параметр
	{1136	,8	,1	,&internal1_m1551_tx},	//(internal1_m1551_tx) tx - внутренний параметр
	{1137	,8	,1	,&internal1_m1552_tx},	//(internal1_m1552_tx) tx - внутренний параметр
	{1138	,8	,1	,&internal1_m1562_tx},	//(internal1_m1562_tx) tx - внутренний параметр
	{1139	,8	,1	,&internal1_m1564_tx},	//(internal1_m1564_tx) tx - внутренний параметр
	{1140	,8	,1	,&internal1_m1571_tx},	//(internal1_m1571_tx) tx - внутренний параметр
	{1141	,8	,1	,&internal1_m1572_tx},	//(internal1_m1572_tx) tx - внутренний параметр
	{1142	,8	,1	,&internal1_m1573_tx},	//(internal1_m1573_tx) tx - внутренний параметр
	{1143	,8	,1	,&internal1_m1574_tx},	//(internal1_m1574_tx) tx - внутренний параметр
	{1144	,8	,1	,&internal1_m1575_tx},	//(internal1_m1575_tx) tx - внутренний параметр
	{1145	,1	,1	,&internal1_m1601_q0},	//(internal1_m1601_q0) q0 - внутренний параметр
	{1146	,1	,1	,&internal1_m1602_ErrPr0},	//(internal1_m1602_ErrPr0) ErrPr - Приостановка программы по ошибке
	{1147	,1	,1	,&internal1_m1602_FinPr0},	//(internal1_m1602_FinPr0) FinPr - конец программы
	{1148	,1	,1	,&internal1_m1602_MyFirstEnterFlag},	//(internal1_m1602_MyFirstEnterFlag)  
	{1149	,3	,1	,&internal1_m1602_Step},	//(internal1_m1602_Step)  - текущий шаг программы
	{1150	,8	,1	,&internal1_m1602_TimS},	//(internal1_m1602_TimS) Время от старта программы
	{1151	,18	,6	,&internal1_m1602_rz},	//(internal1_m1602_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{1152	,1	,1	,&internal1_m1602_sb2UR0},	//(internal1_m1602_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{1153	,1	,1	,&internal1_m1602_sbINI0},	//(internal1_m1602_sbINI0) sbINI - запуск проверки ИНИ
	{1154	,1	,1	,&internal1_m1602_sbNupIS0},	//(internal1_m1602_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{1155	,1	,1	,&internal1_m1602_sbVuIS0},	//(internal1_m1602_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{1156	,1	,1	,&internal1_m1602_sbVuRB0},	//(internal1_m1602_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{1157	,5	,1	,&internal1_m1604_q0},	//(internal1_m1604_q0) q0 - внутренний параметр
	{1158	,5	,1	,&internal1_m1619_x0},	//(internal1_m1619_x0) x0 - значение входного параметра на предыдущем шаге
	{1159	,8	,1	,&internal1_m1629_tx},	//(internal1_m1629_tx) tx - внутренний параметр
	{1160	,1	,1	,&internal1_m1638_q0},	//(internal1_m1638_q0) q0 - внутренний параметр
	{1161	,8	,1	,&internal1_m1639_tim},	//(internal1_m1639_tim) - время задержки выходного сигнала
	{1162	,1	,1	,&internal1_m1639_x0},	//(internal1_m1639_x0) - значение входного параметра на предыдущем шаге
	{1163	,8	,1	,&internal1_m1645_tx},	//(internal1_m1645_tx) tx - время накопленное сек
	{1164	,18	,1	,&internal1_m1645_y0},	//(internal1_m1645_y0) y0
	{1165	,1	,1	,&internal1_m1648_q0},	//(internal1_m1648_q0) q0 - внутренний параметр
	{1166	,8	,1	,&internal1_m1650_q0},	//(internal1_m1650_q0) q0 - внутренний параметр
	{1167	,1	,1	,&internal1_m1653_fef},	//(internal1_m1653_fef) FirstEnterFlag
	{1168	,1	,1	,&internal1_m1653_x0},	//(internal1_m1653_x0) был приход сигнала x1
	{1169	,8	,1	,&internal1_m1653_y0},	//(internal1_m1653_y0) интервал между сигналами х1 и х2
	{1170	,1	,1	,&internal1_m1666_q0},	//(internal1_m1666_q0) q0 - внутренний параметр
	{1171	,8	,1	,&internal1_m1679_tx},	//(internal1_m1679_tx) tx - время накопленное сек
	{1172	,18	,1	,&internal1_m1679_y0},	//(internal1_m1679_y0) y0
	{1173	,1	,1	,&internal1_m1681_q0},	//(internal1_m1681_q0) q0 - внутренний параметр
	{1174	,1	,1	,&internal1_m1686_q0},	//(internal1_m1686_q0) q0 - внутренний параметр
	{1175	,8	,1	,&internal1_m1687_tim},	//(internal1_m1687_tim) - время задержки выходного сигнала
	{1176	,1	,1	,&internal1_m1687_x0},	//(internal1_m1687_x0) - значение входного параметра на предыдущем шаге
	{1177	,8	,1	,&internal1_m1690_q0},	//(internal1_m1690_q0) q0 - внутренний параметр
	{1178	,8	,1	,&internal1_m1692_tim},	//(internal1_m1692_tim) - время задержки выходного сигнала
	{1179	,1	,1	,&internal1_m1692_x0},	//(internal1_m1692_x0) - значение входного параметра на предыдущем шаге
	{1180	,8	,1	,&internal1_m1693_q0},	//(internal1_m1693_q0) q0 - внутренний параметр
	{1181	,8	,1	,&internal1_m1698_tx},	//(internal1_m1698_tx) tx - время накопленное сек
	{1182	,18	,1	,&internal1_m1698_y0},	//(internal1_m1698_y0) y0
	{1183	,1	,1	,&internal1_m1701_q0},	//(internal1_m1701_q0) q0 - внутренний параметр
	{1184	,1	,1	,&internal1_m1702_fef},	//(internal1_m1702_fef) FirstEnterFlag
	{1185	,1	,1	,&internal1_m1702_x0},	//(internal1_m1702_x0) был приход сигнала x1
	{1186	,8	,1	,&internal1_m1702_y0},	//(internal1_m1702_y0) интервал между сигналами х1 и х2
	{1187	,8	,1	,&internal1_m1704_tx},	//(internal1_m1704_tx) tx - время накопленное сек
	{1188	,18	,1	,&internal1_m1704_y0},	//(internal1_m1704_y0) y0
	{1189	,1	,1	,&internal1_m1707_fef},	//(internal1_m1707_fef) FirstEnterFlag
	{1190	,1	,1	,&internal1_m1707_x0},	//(internal1_m1707_x0) был приход сигнала x1
	{1191	,8	,1	,&internal1_m1707_y0},	//(internal1_m1707_y0) интервал между сигналами х1 и х2
	{1192	,1	,1	,&internal1_m1708_q0},	//(internal1_m1708_q0) q0 - внутренний параметр
	{1193	,1	,1	,&internal1_m1722_q0},	//(internal1_m1722_q0) q0 - внутренний параметр
	{1194	,1	,1	,&internal1_m1723_q0},	//(internal1_m1723_q0) q0 - внутренний параметр
	{1195	,8	,1	,&internal1_m1774_tx},	//(internal1_m1774_tx) tx - внутренний параметр
	{1196	,8	,1	,&internal1_m1775_tx},	//(internal1_m1775_tx) tx - внутренний параметр
	{1197	,8	,1	,&internal1_m1777_tx},	//(internal1_m1777_tx) tx - внутренний параметр
	{1198	,8	,1	,&internal1_m1779_tx},	//(internal1_m1779_tx) tx - внутренний параметр
	{1199	,8	,1	,&internal1_m1788_tx},	//(internal1_m1788_tx) tx - внутренний параметр
	{1200	,18	,1	,&internal1_m178_BLDv0},	//(internal1_m178_BLDv0) BlDv - Блокировка движения
	{1201	,8	,1	,&internal1_m178_X0},	//(internal1_m178_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{1202	,8	,1	,&internal1_m178_t0},	//(internal1_m178_t0) время нахождения в зоне возврата
	{1203	,8	,1	,&internal1_m1793_tx},	//(internal1_m1793_tx) tx - внутренний параметр
	{1204	,8	,1	,&internal1_m1794_tx},	//(internal1_m1794_tx) tx - внутренний параметр
	{1205	,8	,1	,&internal1_m1796_tx},	//(internal1_m1796_tx) tx - внутренний параметр
	{1206	,18	,1	,&internal1_m1806_BLDv0},	//(internal1_m1806_BLDv0) BlDv - Блокировка движения
	{1207	,8	,1	,&internal1_m1806_X0},	//(internal1_m1806_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{1208	,8	,1	,&internal1_m1806_t0},	//(internal1_m1806_t0) время нахождения в зоне возврата
	{1209	,18	,1	,&internal1_m1809_BlDv0},	//(internal1_m1809_BlDv0) - была блокировка
	{1210	,18	,1	,&internal1_m1809_DvDw0},	//(internal1_m1809_DvDw0) - есть команда на движение назад
	{1211	,18	,1	,&internal1_m1809_DvUp0},	//(internal1_m1809_DvUp0) - есть команда на движение вперёд
	{1212	,18	,1	,&internal1_m1809_FDvDw0},	//(internal1_m1809_FDvDw0) - есть команда на движение назад
	{1213	,18	,1	,&internal1_m1809_FDvUp0},	//(internal1_m1809_FDvUp0) - есть команда на движение вперёд
	{1214	,18	,1	,&internal1_m1809_Pkav0},	//(internal1_m1809_Pkav0) Pkav - передний конечный аварийный выключатель
	{1215	,18	,1	,&internal1_m1809_Pkv0},	//(internal1_m1809_Pkv0) Pkv - передний конечный выключатель
	{1216	,18	,1	,&internal1_m1809_Zkav0},	//(internal1_m1809_Zkav0) Zkav - задний конечный аварийный выключатель
	{1217	,18	,1	,&internal1_m1809_Zkv0},	//(internal1_m1809_Zkv0) Zkv - задний конечный выключатель
	{1218	,18	,1	,&internal1_m1809_fef},	//(internal1_m1809_fef) fef
	{1219	,8	,1	,&internal1_m1809_txHr},	//(internal1_m1809_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{1220	,8	,1	,&internal1_m1809_txLd},	//(internal1_m1809_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{1221	,8	,1	,&internal1_m1809_txNm},	//(internal1_m1809_txNm) txNm - счётчик задержки сигнализации недвижения
	{1222	,8	,1	,&internal1_m1809_txSm},	//(internal1_m1809_txSm) txSm - счётчик задержки сигнализации самохода
	{1223	,8	,1	,&internal1_m1810_tx},	//(internal1_m1810_tx) tx - внутренний параметр
	{1224	,8	,1	,&internal1_m1815_tx},	//(internal1_m1815_tx) tx - внутренний параметр
	{1225	,8	,1	,&internal1_m1820_tx},	//(internal1_m1820_tx) tx - время накопленное сек
	{1226	,18	,1	,&internal1_m1820_y0},	//(internal1_m1820_y0) y0
	{1227	,8	,1	,&internal1_m1821_tx},	//(internal1_m1821_tx) tx - внутренний параметр
	{1228	,8	,1	,&internal1_m1823_tx},	//(internal1_m1823_tx) tx - внутренний параметр
	{1229	,8	,1	,&internal1_m1824_tx},	//(internal1_m1824_tx) tx - время накопленное сек
	{1230	,18	,1	,&internal1_m1824_y0},	//(internal1_m1824_y0) y0
	{1231	,8	,1	,&internal1_m1828_DelSp},	//(internal1_m1828_DelSp) DelSp - время переключения скоростей
	{1232	,1	,1	,&internal1_m1828_ShCntlSp0},	//(internal1_m1828_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{1233	,1	,1	,&internal1_m1828_Shift0},	//(internal1_m1828_Shift0) Shift0 - признак самохода
	{1234	,1	,1	,&internal1_m1828_ShiftControl},	//(internal1_m1828_ShiftControl) ShiftControl - признак самохода
	{1235	,8	,1	,&internal1_m1828_Speed0},	//(internal1_m1828_Speed0) Speed0 - предыдущее значение скорости перемещения
	{1236	,8	,1	,&internal1_m1828_StSpeed},	//(internal1_m1828_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{1237	,8	,1	,&internal1_m1828_Vz0},	//(internal1_m1828_Vz0) Vz0 - предыдущая заданная скорость
	{1238	,3	,1	,&internal1_m1828_flRazg},	//(internal1_m1828_flRazg) признак разгона/торможения
	{1239	,8	,1	,&internal1_m1828_sumtim},	//(internal1_m1828_sumtim) sumtim - время в пути
	{1240	,8	,20	,&internal1_m1828_tim0},	//(internal1_m1828_tim0) tim0 - массив значений времени цикла
	{1241	,8	,1	,&internal1_m1828_tx},	//(internal1_m1828_tx) tx
	{1242	,8	,1	,&internal1_m1828_txBl},	//(internal1_m1828_txBl) tx
	{1243	,8	,1	,&internal1_m1828_txMBl},	//(internal1_m1828_txMBl) tx
	{1244	,8	,1	,&internal1_m1828_txZS},	//(internal1_m1828_txZS) txZS
	{1245	,8	,1	,&internal1_m1828_txd},	//(internal1_m1828_txd) txd
	{1246	,8	,1	,&internal1_m1828_tz0},	//(internal1_m1828_tz0) tz0 - время защиты от нового задания сек
	{1247	,8	,20	,&internal1_m1828_x0},	//(internal1_m1828_x0) x0 - массив мгновенных значений координат
	{1248	,3	,1	,&internal1_m1828_xptr},	//(internal1_m1828_xptr) указатель текущей позиции в массиве координат
	{1249	,8	,1	,&internal1_m1828_xz0},	//(internal1_m1828_xz0) xz0 - новое задание мм
	{1250	,8	,1	,&internal1_m1828_z0},	//(internal1_m1828_z0) z0 - точка прекращения движения
	{1251	,8	,1	,&internal1_m1830_tx},	//(internal1_m1830_tx) tx - внутренний параметр
	{1252	,8	,1	,&internal1_m1831_tx},	//(internal1_m1831_tx) tx - внутренний параметр
	{1253	,8	,1	,&internal1_m1834_tx},	//(internal1_m1834_tx) tx - время накопленное сек
	{1254	,18	,1	,&internal1_m1834_y0},	//(internal1_m1834_y0) y0
	{1255	,1	,1	,&internal1_m1852_q0},	//(internal1_m1852_q0) q0 - внутренний параметр
	{1256	,1	,1	,&internal1_m1854_q0},	//(internal1_m1854_q0) q0 - внутренний параметр
	{1257	,1	,1	,&internal1_m1855_q0},	//(internal1_m1855_q0) q0 - внутренний параметр
	{1258	,1	,1	,&internal1_m1857_q0},	//(internal1_m1857_q0) q0 - внутренний параметр
	{1259	,1	,1	,&internal1_m1858_q0},	//(internal1_m1858_q0) q0 - внутренний параметр
	{1260	,1	,1	,&internal1_m1860_q0},	//(internal1_m1860_q0) q0 - внутренний параметр
	{1261	,1	,1	,&internal1_m1862_q0},	//(internal1_m1862_q0) q0 - внутренний параметр
	{1262	,1	,1	,&internal1_m1864_q0},	//(internal1_m1864_q0) q0 - внутренний параметр
	{1263	,1	,1	,&internal1_m1866_q0},	//(internal1_m1866_q0) q0 - внутренний параметр
	{1264	,1	,1	,&internal1_m1867_q0},	//(internal1_m1867_q0) q0 - внутренний параметр
	{1265	,1	,1	,&internal1_m1868_q0},	//(internal1_m1868_q0) q0 - внутренний параметр
	{1266	,1	,1	,&internal1_m1869_q0},	//(internal1_m1869_q0) q0 - внутренний параметр
	{1267	,1	,1	,&internal1_m1878_q0},	//(internal1_m1878_q0) q0 - внутренний параметр
	{1268	,1	,1	,&internal1_m1880_q0},	//(internal1_m1880_q0) q0 - внутренний параметр
	{1269	,1	,1	,&internal1_m1882_q0},	//(internal1_m1882_q0) q0 - внутренний параметр
	{1270	,1	,1	,&internal1_m1884_q0},	//(internal1_m1884_q0) q0 - внутренний параметр
	{1271	,1	,1	,&internal1_m1886_q0},	//(internal1_m1886_q0) q0 - внутренний параметр
	{1272	,1	,1	,&internal1_m1888_q0},	//(internal1_m1888_q0) q0 - внутренний параметр
	{1273	,1	,1	,&internal1_m1890_q0},	//(internal1_m1890_q0) q0 - внутренний параметр
	{1274	,1	,1	,&internal1_m1892_q0},	//(internal1_m1892_q0) q0 - внутренний параметр
	{1275	,1	,1	,&internal1_m1900_q0},	//(internal1_m1900_q0) q0 - внутренний параметр
	{1276	,1	,1	,&internal1_m1901_q0},	//(internal1_m1901_q0) q0 - внутренний параметр
	{1277	,1	,1	,&internal1_m1902_q0},	//(internal1_m1902_q0) q0 - внутренний параметр
	{1278	,1	,1	,&internal1_m1909_q0},	//(internal1_m1909_q0) q0 - внутренний параметр
	{1279	,1	,1	,&internal1_m1911_q0},	//(internal1_m1911_q0) q0 - внутренний параметр
	{1280	,1	,1	,&internal1_m1913_q0},	//(internal1_m1913_q0) q0 - внутренний параметр
	{1281	,1	,1	,&internal1_m1915_q0},	//(internal1_m1915_q0) q0 - внутренний параметр
	{1282	,1	,1	,&internal1_m1917_q0},	//(internal1_m1917_q0) q0 - внутренний параметр
	{1283	,1	,1	,&internal1_m1919_q0},	//(internal1_m1919_q0) q0 - внутренний параметр
	{1284	,1	,1	,&internal1_m1922_q0},	//(internal1_m1922_q0) q0 - внутренний параметр
	{1285	,1	,1	,&internal1_m1925_q0},	//(internal1_m1925_q0) q0 - внутренний параметр
	{1286	,1	,1	,&internal1_m1927_q0},	//(internal1_m1927_q0) q0 - внутренний параметр
	{1287	,1	,1	,&internal1_m1930_q0},	//(internal1_m1930_q0) q0 - внутренний параметр
	{1288	,1	,1	,&internal1_m1936_MyFirstEnterFlag},	//(internal1_m1936_MyFirstEnterFlag) MyFirstEnterFlag
	{1289	,1	,1	,&internal1_m1936_Pv0},	//(internal1_m1936_Pv0)  - Пер. выключатель механизма
	{1290	,1	,1	,&internal1_m1936_Zv0},	//(internal1_m1936_Zv0)  - Зад. выключатель механизма
	{1291	,1	,1	,&internal1_m1937_MyFirstEnterFlag},	//(internal1_m1937_MyFirstEnterFlag) MyFirstEnterFlag
	{1292	,1	,1	,&internal1_m1937_Pv0},	//(internal1_m1937_Pv0)  - Пер. выключатель механизма
	{1293	,1	,1	,&internal1_m1937_Zv0},	//(internal1_m1937_Zv0)  - Зад. выключатель механизма
	{1294	,1	,1	,&internal1_m1949_q0},	//(internal1_m1949_q0) q0 - внутренний параметр
	{1295	,1	,1	,&internal1_m1952_q0},	//(internal1_m1952_q0) q0 - внутренний параметр
	{1296	,1	,1	,&internal1_m1956_q0},	//(internal1_m1956_q0) q0 - внутренний параметр
	{1297	,1	,1	,&internal1_m1959_q0},	//(internal1_m1959_q0) q0 - внутренний параметр
	{1298	,8	,1	,&internal1_m195_tx},	//(internal1_m195_tx) tx - время накопленное сек
	{1299	,18	,1	,&internal1_m195_y0},	//(internal1_m195_y0) y0
	{1300	,1	,1	,&internal1_m1962_q0},	//(internal1_m1962_q0) q0 - внутренний параметр
	{1301	,1	,1	,&internal1_m1964_q0},	//(internal1_m1964_q0) q0 - внутренний параметр
	{1302	,8	,1	,&internal1_m196_tx},	//(internal1_m196_tx) tx - время накопленное сек
	{1303	,18	,1	,&internal1_m196_y0},	//(internal1_m196_y0) y0
	{1304	,1	,1	,&internal1_m19_q0},	//(internal1_m19_q0) q0 - внутренний параметр
	{1305	,8	,1	,&internal1_m2029_tx},	//(internal1_m2029_tx) tx - время накопленное сек
	{1306	,18	,1	,&internal1_m2029_y0},	//(internal1_m2029_y0) y0
	{1307	,8	,1	,&internal1_m2030_tx},	//(internal1_m2030_tx) tx - время накопленное сек
	{1308	,18	,1	,&internal1_m2030_y0},	//(internal1_m2030_y0) y0
	{1309	,8	,1	,&internal1_m2031_tx},	//(internal1_m2031_tx) tx - время накопленное сек
	{1310	,18	,1	,&internal1_m2031_y0},	//(internal1_m2031_y0) y0
	{1311	,8	,1	,&internal1_m2032_tx},	//(internal1_m2032_tx) tx - время накопленное сек
	{1312	,18	,1	,&internal1_m2032_y0},	//(internal1_m2032_y0) y0
	{1313	,8	,1	,&internal1_m203_DelSp},	//(internal1_m203_DelSp) DelSp - время переключения скоростей
	{1314	,1	,1	,&internal1_m203_ShCntlSp0},	//(internal1_m203_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{1315	,1	,1	,&internal1_m203_Shift0},	//(internal1_m203_Shift0) Shift0 - признак самохода
	{1316	,1	,1	,&internal1_m203_ShiftControl},	//(internal1_m203_ShiftControl) ShiftControl - признак самохода
	{1317	,8	,1	,&internal1_m203_Speed0},	//(internal1_m203_Speed0) Speed0 - предыдущее значение скорости перемещения
	{1318	,8	,1	,&internal1_m203_StSpeed},	//(internal1_m203_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{1319	,8	,1	,&internal1_m203_Vz0},	//(internal1_m203_Vz0) Vz0 - предыдущая заданная скорость
	{1320	,3	,1	,&internal1_m203_flRazg},	//(internal1_m203_flRazg) признак разгона/торможения
	{1321	,8	,1	,&internal1_m203_sumtim},	//(internal1_m203_sumtim) sumtim - время в пути
	{1322	,8	,150	,&internal1_m203_tim0},	//(internal1_m203_tim0) tim0 - массив значений времени цикла
	{1323	,8	,1	,&internal1_m203_tx},	//(internal1_m203_tx) tx
	{1324	,8	,1	,&internal1_m203_txBl},	//(internal1_m203_txBl) tx
	{1325	,8	,1	,&internal1_m203_txMBl},	//(internal1_m203_txMBl) tx
	{1326	,8	,1	,&internal1_m203_txZS},	//(internal1_m203_txZS) txZS
	{1327	,8	,1	,&internal1_m203_txd},	//(internal1_m203_txd) txd
	{1328	,8	,1	,&internal1_m203_tz0},	//(internal1_m203_tz0) tz0 - время защиты от нового задания сек
	{1329	,8	,150	,&internal1_m203_x0},	//(internal1_m203_x0) x0 - массив мгновенных значений координат
	{1330	,3	,1	,&internal1_m203_xptr},	//(internal1_m203_xptr) указатель текущей позиции в массиве координат
	{1331	,8	,1	,&internal1_m203_xz0},	//(internal1_m203_xz0) xz0 - новое задание мм
	{1332	,8	,1	,&internal1_m203_z0},	//(internal1_m203_z0) z0 - точка прекращения движения
	{1333	,8	,1	,&internal1_m204_tx},	//(internal1_m204_tx) tx - внутренний параметр
	{1334	,8	,1	,&internal1_m205_tx},	//(internal1_m205_tx) tx - внутренний параметр
	{1335	,8	,1	,&internal1_m2067_tx},	//(internal1_m2067_tx) tx - внутренний параметр
	{1336	,8	,1	,&internal1_m2068_tx},	//(internal1_m2068_tx) tx - внутренний параметр
	{1337	,8	,1	,&internal1_m206_tx},	//(internal1_m206_tx) tx - внутренний параметр
	{1338	,8	,1	,&internal1_m2074_tim},	//(internal1_m2074_tim) - время задержки выходного сигнала
	{1339	,1	,1	,&internal1_m2074_x0},	//(internal1_m2074_x0) - значение входного параметра на предыдущем шаге
	{1340	,1	,1	,&internal1_m2076_q0},	//(internal1_m2076_q0) q0 - внутренний параметр
	{1341	,8	,1	,&internal1_m2079_tx},	//(internal1_m2079_tx) tx - время накопленное сек
	{1342	,18	,1	,&internal1_m2079_y0},	//(internal1_m2079_y0) y0
	{1343	,1	,1	,&internal1_m2082_q0},	//(internal1_m2082_q0) q0 - внутренний параметр
	{1344	,1	,1	,&internal1_m2084_fef},	//(internal1_m2084_fef) FirstEnterFlag
	{1345	,1	,1	,&internal1_m2084_x0},	//(internal1_m2084_x0) был приход сигнала x1
	{1346	,8	,1	,&internal1_m2084_y0},	//(internal1_m2084_y0) интервал между сигналами х1 и х2
	{1347	,1	,1	,&internal1_m2089_q0},	//(internal1_m2089_q0) q0 - внутренний параметр
	{1348	,8	,1	,&internal1_m2093_q0},	//(internal1_m2093_q0) q0 - внутренний параметр
	{1349	,1	,1	,&internal1_m2102_q0},	//(internal1_m2102_q0) q0 - внутренний параметр
	{1350	,8	,1	,&internal1_m2103_tim},	//(internal1_m2103_tim) - время задержки выходного сигнала
	{1351	,1	,1	,&internal1_m2103_x0},	//(internal1_m2103_x0) - значение входного параметра на предыдущем шаге
	{1352	,8	,1	,&internal1_m2111_tx},	//(internal1_m2111_tx) tx - время накопленное сек
	{1353	,18	,1	,&internal1_m2111_y0},	//(internal1_m2111_y0) y0
	{1354	,1	,1	,&internal1_m2114_q0},	//(internal1_m2114_q0) q0 - внутренний параметр
	{1355	,8	,1	,&internal1_m2123_tx},	//(internal1_m2123_tx) tx - время накопленное сек
	{1356	,18	,1	,&internal1_m2123_y0},	//(internal1_m2123_y0) y0
	{1357	,1	,1	,&internal1_m2125_fef},	//(internal1_m2125_fef) FirstEnterFlag
	{1358	,1	,1	,&internal1_m2125_x0},	//(internal1_m2125_x0) был приход сигнала x1
	{1359	,8	,1	,&internal1_m2125_y0},	//(internal1_m2125_y0) интервал между сигналами х1 и х2
	{1360	,8	,1	,&internal1_m2126_tx},	//(internal1_m2126_tx) tx - время накопленное сек
	{1361	,18	,1	,&internal1_m2126_y0},	//(internal1_m2126_y0) y0
	{1362	,8	,1	,&internal1_m212_tx},	//(internal1_m212_tx) tx - внутренний параметр
	{1363	,8	,1	,&internal1_m2133_q0},	//(internal1_m2133_q0) q0 - внутренний параметр
	{1364	,1	,1	,&internal1_m2143_q0},	//(internal1_m2143_q0) q0 - внутренний параметр
	{1365	,1	,1	,&internal1_m2159_q0},	//(internal1_m2159_q0) q0 - внутренний параметр
	{1366	,1	,1	,&internal1_m2160_q0},	//(internal1_m2160_q0) q0 - внутренний параметр
	{1367	,8	,1	,&internal1_m2168_tx},	//(internal1_m2168_tx) tx - внутренний параметр
	{1368	,8	,1	,&internal1_m2171_tx},	//(internal1_m2171_tx) tx - внутренний параметр
	{1369	,1	,1	,&internal1_m2174_q0},	//(internal1_m2174_q0) q0 - внутренний параметр
	{1370	,8	,1	,&internal1_m217_tx},	//(internal1_m217_tx) tx - время накопленное сек
	{1371	,18	,1	,&internal1_m217_y0},	//(internal1_m217_y0) y0
	{1372	,8	,1	,&internal1_m2181_tx},	//(internal1_m2181_tx) tx - внутренний параметр
	{1373	,8	,1	,&internal1_m2184_tx},	//(internal1_m2184_tx) tx - внутренний параметр
	{1374	,1	,1	,&internal1_m2186_q0},	//(internal1_m2186_q0) q0 - внутренний параметр
	{1375	,8	,1	,&internal1_m2196_tx},	//(internal1_m2196_tx) tx - внутренний параметр
	{1376	,8	,1	,&internal1_m2199_tx},	//(internal1_m2199_tx) tx - внутренний параметр
	{1377	,8	,1	,&internal1_m21_tx},	//(internal1_m21_tx) tx - внутренний параметр
	{1378	,1	,1	,&internal1_m2202_q0},	//(internal1_m2202_q0) q0 - внутренний параметр
	{1379	,8	,1	,&internal1_m2210_tx},	//(internal1_m2210_tx) tx - внутренний параметр
	{1380	,1	,1	,&internal1_m2214_q0},	//(internal1_m2214_q0) q0 - внутренний параметр
	{1381	,8	,1	,&internal1_m2220_tx},	//(internal1_m2220_tx) tx - внутренний параметр
	{1382	,8	,1	,&internal1_m2224_tx},	//(internal1_m2224_tx) tx - внутренний параметр
	{1383	,8	,1	,&internal1_m222_tx},	//(internal1_m222_tx) tx - внутренний параметр
	{1384	,1	,1	,&internal1_m2230_q0},	//(internal1_m2230_q0) q0 - внутренний параметр
	{1385	,8	,1	,&internal1_m2231_tx},	//(internal1_m2231_tx) tx - время накопленное сек
	{1386	,18	,1	,&internal1_m2231_y0},	//(internal1_m2231_y0) y0
	{1387	,8	,1	,&internal1_m2235_tx},	//(internal1_m2235_tx) tx - внутренний параметр
	{1388	,1	,1	,&internal1_m2238_q0},	//(internal1_m2238_q0) q0 - внутренний параметр
	{1389	,8	,1	,&internal1_m2239_tx},	//(internal1_m2239_tx) tx - время накопленное сек
	{1390	,18	,1	,&internal1_m2239_y0},	//(internal1_m2239_y0) y0
	{1391	,8	,1	,&internal1_m223_tx},	//(internal1_m223_tx) tx - время накопленное сек
	{1392	,18	,1	,&internal1_m223_y0},	//(internal1_m223_y0) y0
	{1393	,8	,1	,&internal1_m2245_tx},	//(internal1_m2245_tx) tx - внутренний параметр
	{1394	,8	,1	,&internal1_m2253_tx},	//(internal1_m2253_tx) tx - внутренний параметр
	{1395	,1	,1	,&internal1_m2255_q0},	//(internal1_m2255_q0) q0 - внутренний параметр
	{1396	,8	,1	,&internal1_m2262_tx},	//(internal1_m2262_tx) tx - внутренний параметр
	{1397	,8	,1	,&internal1_m2266_tx},	//(internal1_m2266_tx) tx - время накопленное сек
	{1398	,18	,1	,&internal1_m2266_y0},	//(internal1_m2266_y0) y0
	{1399	,8	,1	,&internal1_m2268_tx},	//(internal1_m2268_tx) tx - внутренний параметр
	{1400	,1	,1	,&internal1_m2271_q0},	//(internal1_m2271_q0) q0 - внутренний параметр
	{1401	,8	,1	,&internal1_m2273_tx},	//(internal1_m2273_tx) tx - внутренний параметр
	{1402	,8	,1	,&internal1_m2274_tx},	//(internal1_m2274_tx) tx - внутренний параметр
	{1403	,8	,1	,&internal1_m2277_tx},	//(internal1_m2277_tx) tx - время накопленное сек
	{1404	,18	,1	,&internal1_m2277_y0},	//(internal1_m2277_y0) y0
	{1405	,8	,1	,&internal1_m2285_tx},	//(internal1_m2285_tx) tx - внутренний параметр
	{1406	,8	,1	,&internal1_m2286_tx},	//(internal1_m2286_tx) tx - внутренний параметр
	{1407	,8	,1	,&internal1_m2288_tx},	//(internal1_m2288_tx) tx - внутренний параметр
	{1408	,1	,1	,&internal1_m2294_q0},	//(internal1_m2294_q0) q0 - внутренний параметр
	{1409	,1	,1	,&internal1_m2299_q0},	//(internal1_m2299_q0) q0 - внутренний параметр
	{1410	,8	,1	,&internal1_m2302_tx},	//(internal1_m2302_tx) tx - внутренний параметр
	{1411	,8	,1	,&internal1_m230_tx},	//(internal1_m230_tx) tx - внутренний параметр
	{1412	,8	,1	,&internal1_m2315_tx},	//(internal1_m2315_tx) tx - внутренний параметр
	{1413	,8	,1	,&internal1_m2316_tx},	//(internal1_m2316_tx) tx - внутренний параметр
	{1414	,8	,1	,&internal1_m2317_tx},	//(internal1_m2317_tx) tx - внутренний параметр
	{1415	,18	,1	,&internal1_m2321_BlDv0},	//(internal1_m2321_BlDv0) - была блокировка
	{1416	,18	,1	,&internal1_m2321_DvDw0},	//(internal1_m2321_DvDw0) - есть команда на движение назад
	{1417	,18	,1	,&internal1_m2321_DvUp0},	//(internal1_m2321_DvUp0) - есть команда на движение вперёд
	{1418	,18	,1	,&internal1_m2321_FDvDw0},	//(internal1_m2321_FDvDw0) - есть команда на движение назад
	{1419	,18	,1	,&internal1_m2321_FDvUp0},	//(internal1_m2321_FDvUp0) - есть команда на движение вперёд
	{1420	,18	,1	,&internal1_m2321_Pkav0},	//(internal1_m2321_Pkav0) Pkav - передний конечный аварийный выключатель
	{1421	,18	,1	,&internal1_m2321_Pkv0},	//(internal1_m2321_Pkv0) Pkv - передний конечный выключатель
	{1422	,18	,1	,&internal1_m2321_Zkav0},	//(internal1_m2321_Zkav0) Zkav - задний конечный аварийный выключатель
	{1423	,18	,1	,&internal1_m2321_Zkv0},	//(internal1_m2321_Zkv0) Zkv - задний конечный выключатель
	{1424	,18	,1	,&internal1_m2321_fef},	//(internal1_m2321_fef) fef
	{1425	,8	,1	,&internal1_m2321_txHr},	//(internal1_m2321_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{1426	,8	,1	,&internal1_m2321_txLd},	//(internal1_m2321_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{1427	,8	,1	,&internal1_m2321_txNm},	//(internal1_m2321_txNm) txNm - счётчик задержки сигнализации недвижения
	{1428	,8	,1	,&internal1_m2321_txSm},	//(internal1_m2321_txSm) txSm - счётчик задержки сигнализации самохода
	{1429	,8	,1	,&internal1_m2322_tx},	//(internal1_m2322_tx) tx - внутренний параметр
	{1430	,18	,1	,&internal1_m2327_BlDv0},	//(internal1_m2327_BlDv0) - была блокировка
	{1431	,18	,1	,&internal1_m2327_DvDw0},	//(internal1_m2327_DvDw0) - есть команда на движение назад
	{1432	,18	,1	,&internal1_m2327_DvUp0},	//(internal1_m2327_DvUp0) - есть команда на движение вперёд
	{1433	,18	,1	,&internal1_m2327_FDvDw0},	//(internal1_m2327_FDvDw0) - есть команда на движение назад
	{1434	,18	,1	,&internal1_m2327_FDvUp0},	//(internal1_m2327_FDvUp0) - есть команда на движение вперёд
	{1435	,18	,1	,&internal1_m2327_Pkav0},	//(internal1_m2327_Pkav0) Pkav - передний конечный аварийный выключатель
	{1436	,18	,1	,&internal1_m2327_Pkv0},	//(internal1_m2327_Pkv0) Pkv - передний конечный выключатель
	{1437	,18	,1	,&internal1_m2327_Zkav0},	//(internal1_m2327_Zkav0) Zkav - задний конечный аварийный выключатель
	{1438	,18	,1	,&internal1_m2327_Zkv0},	//(internal1_m2327_Zkv0) Zkv - задний конечный выключатель
	{1439	,18	,1	,&internal1_m2327_fef},	//(internal1_m2327_fef) fef
	{1440	,8	,1	,&internal1_m2327_txHr},	//(internal1_m2327_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{1441	,8	,1	,&internal1_m2327_txLd},	//(internal1_m2327_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{1442	,8	,1	,&internal1_m2327_txNm},	//(internal1_m2327_txNm) txNm - счётчик задержки сигнализации недвижения
	{1443	,8	,1	,&internal1_m2327_txSm},	//(internal1_m2327_txSm) txSm - счётчик задержки сигнализации самохода
	{1444	,8	,1	,&internal1_m232_tx},	//(internal1_m232_tx) tx - внутренний параметр
	{1445	,8	,1	,&internal1_m2330_tx},	//(internal1_m2330_tx) tx - внутренний параметр
	{1446	,8	,1	,&internal1_m2331_tx},	//(internal1_m2331_tx) tx - внутренний параметр
	{1447	,8	,1	,&internal1_m2332_tx},	//(internal1_m2332_tx) tx - внутренний параметр
	{1448	,1	,1	,&internal1_m2339_q0},	//(internal1_m2339_q0) q0 - внутренний параметр
	{1449	,1	,1	,&internal1_m2340_q0},	//(internal1_m2340_q0) q0 - внутренний параметр
	{1450	,1	,1	,&internal1_m2341_q0},	//(internal1_m2341_q0) q0 - внутренний параметр
	{1451	,1	,1	,&internal1_m2342_q0},	//(internal1_m2342_q0) q0 - внутренний параметр
	{1452	,1	,1	,&internal1_m2344_q0},	//(internal1_m2344_q0) q0 - внутренний параметр
	{1453	,8	,1	,&internal1_m234_tx},	//(internal1_m234_tx) tx - внутренний параметр
	{1454	,1	,1	,&internal1_m2351_q0},	//(internal1_m2351_q0) q0 - внутренний параметр
	{1455	,1	,1	,&internal1_m2353_q0},	//(internal1_m2353_q0) q0 - внутренний параметр
	{1456	,1	,1	,&internal1_m2355_q0},	//(internal1_m2355_q0) q0 - внутренний параметр
	{1457	,1	,1	,&internal1_m2357_q0},	//(internal1_m2357_q0) q0 - внутренний параметр
	{1458	,1	,1	,&internal1_m2359_q0},	//(internal1_m2359_q0) q0 - внутренний параметр
	{1459	,1	,1	,&internal1_m2361_q0},	//(internal1_m2361_q0) q0 - внутренний параметр
	{1460	,1	,1	,&internal1_m2363_q0},	//(internal1_m2363_q0) q0 - внутренний параметр
	{1461	,1	,1	,&internal1_m2370_q0},	//(internal1_m2370_q0) q0 - внутренний параметр
	{1462	,1	,1	,&internal1_m2371_q0},	//(internal1_m2371_q0) q0 - внутренний параметр
	{1463	,1	,1	,&internal1_m2372_q0},	//(internal1_m2372_q0) q0 - внутренний параметр
	{1464	,1	,1	,&internal1_m2374_q0},	//(internal1_m2374_q0) q0 - внутренний параметр
	{1465	,1	,1	,&internal1_m2375_q0},	//(internal1_m2375_q0) q0 - внутренний параметр
	{1466	,1	,1	,&internal1_m2382_q0},	//(internal1_m2382_q0) q0 - внутренний параметр
	{1467	,1	,1	,&internal1_m2384_q0},	//(internal1_m2384_q0) q0 - внутренний параметр
	{1468	,1	,1	,&internal1_m2386_q0},	//(internal1_m2386_q0) q0 - внутренний параметр
	{1469	,1	,1	,&internal1_m2388_q0},	//(internal1_m2388_q0) q0 - внутренний параметр
	{1470	,1	,1	,&internal1_m2390_q0},	//(internal1_m2390_q0) q0 - внутренний параметр
	{1471	,1	,1	,&internal1_m2392_q0},	//(internal1_m2392_q0) q0 - внутренний параметр
	{1472	,1	,1	,&internal1_m2394_q0},	//(internal1_m2394_q0) q0 - внутренний параметр
	{1473	,8	,1	,&internal1_m2410_tx},	//(internal1_m2410_tx) tx - время накопленное сек
	{1474	,18	,1	,&internal1_m2410_y0},	//(internal1_m2410_y0) y0
	{1475	,3	,1	,&internal1_m2413_FlPar},	//(internal1_m2413_FlPar) - стартовый этап регулирования
	{1476	,3	,1	,&internal1_m2413_ZerCoun},	//(internal1_m2413_ZerCoun) - флаг направления изменения мощности
	{1477	,8	,1	,&internal1_m2413_fRct},	//(internal1_m2413_fRct)  - текущая реактивность регулятора 
	{1478	,8	,1	,&internal1_m2413_fStw0},	//(internal1_m2413_fStw0)  - исходное положение ИС для изменения задания 
	{1479	,8	,1	,&internal1_m2413_fTk0},	//(internal1_m2413_fTk0)  - последняя температура 
	{1480	,1	,1	,&internal1_m2413_fef},	//(internal1_m2413_fef)  - первый вход
	{1481	,8	,1	,&internal1_m2413_fkizm},	//(internal1_m2413_fkizm)  - стартовая координата положения ИМ 0-й реактивности 
	{1482	,8	,1	,&internal1_m2413_fwt0},	//(internal1_m2413_fwt0)  - мощность на предыдущем шаге 
	{1483	,8	,1	,&internal1_m2413_fwz0},	//(internal1_m2413_fwz0)  - заданная мощность на предыдущем шаге 
	{1484	,8	,1	,&internal1_m2414_tx},	//(internal1_m2414_tx) tx - время накопленное сек
	{1485	,18	,1	,&internal1_m2414_y0},	//(internal1_m2414_y0) y0
	{1486	,8	,1	,&internal1_m2415_tx},	//(internal1_m2415_tx) tx - время накопленное сек
	{1487	,18	,1	,&internal1_m2415_y0},	//(internal1_m2415_y0) y0
	{1488	,1	,1	,&internal1_m2421_q0},	//(internal1_m2421_q0) q0 - внутренний параметр
	{1489	,1	,1	,&internal1_m2427_q0},	//(internal1_m2427_q0) q0 - внутренний параметр
	{1490	,8	,1	,&internal1_m2429_tx},	//(internal1_m2429_tx) tx - внутренний параметр
	{1491	,8	,1	,&internal1_m243_tx},	//(internal1_m243_tx) tx - внутренний параметр
	{1492	,8	,1	,&internal1_m2444_tx},	//(internal1_m2444_tx) tx - время накопленное сек
	{1493	,18	,1	,&internal1_m2444_y0},	//(internal1_m2444_y0) y0
	{1494	,8	,1	,&internal1_m2446_tx},	//(internal1_m2446_tx) tx - внутренний параметр
	{1495	,1	,1	,&internal1_m2449_q0},	//(internal1_m2449_q0) q0 - внутренний параметр
	{1496	,8	,1	,&internal1_m2461_tx},	//(internal1_m2461_tx) tx - внутренний параметр
	{1497	,8	,1	,&internal1_m2465_tx},	//(internal1_m2465_tx) tx - внутренний параметр
	{1498	,8	,1	,&internal1_m2466_tx},	//(internal1_m2466_tx) tx - внутренний параметр
	{1499	,8	,1	,&internal1_m2467_tx},	//(internal1_m2467_tx) tx - внутренний параметр
	{1500	,8	,1	,&internal1_m247_tx},	//(internal1_m247_tx) tx - внутренний параметр
	{1501	,8	,1	,&internal1_m248_tx},	//(internal1_m248_tx) tx - внутренний параметр
	{1502	,8	,1	,&internal1_m257_tx},	//(internal1_m257_tx) tx - внутренний параметр
	{1503	,8	,1	,&internal1_m260_tx},	//(internal1_m260_tx) tx - внутренний параметр
	{1504	,8	,1	,&internal1_m265_tx},	//(internal1_m265_tx) tx - внутренний параметр
	{1505	,1	,1	,&internal1_m26_q0},	//(internal1_m26_q0) q0 - внутренний параметр
	{1506	,8	,1	,&internal1_m272_tx},	//(internal1_m272_tx) tx - внутренний параметр
	{1507	,8	,1	,&internal1_m275_tx},	//(internal1_m275_tx) tx - внутренний параметр
	{1508	,8	,1	,&internal1_m276_tx},	//(internal1_m276_tx) tx - внутренний параметр
	{1509	,8	,1	,&internal1_m278_tx},	//(internal1_m278_tx) tx - внутренний параметр
	{1510	,8	,1	,&internal1_m279_tx},	//(internal1_m279_tx) tx - внутренний параметр
	{1511	,1	,1	,&internal1_m300_ErrPr0},	//(internal1_m300_ErrPr0) ErrPr - Приостановка программы по ошибке
	{1512	,1	,1	,&internal1_m300_FinPr0},	//(internal1_m300_FinPr0) FinPr - конец программы
	{1513	,1	,1	,&internal1_m300_MyFirstEnterFlag},	//(internal1_m300_MyFirstEnterFlag)  
	{1514	,3	,1	,&internal1_m300_Step},	//(internal1_m300_Step)  - текущий шаг программы
	{1515	,8	,1	,&internal1_m300_TimS},	//(internal1_m300_TimS) Время от старта программы
	{1516	,18	,10	,&internal1_m300_rz},	//(internal1_m300_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{1517	,1	,1	,&internal1_m300_sb2UR0},	//(internal1_m300_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{1518	,1	,1	,&internal1_m300_sbINI0},	//(internal1_m300_sbINI0) sbINI - запуск проверки ИНИ
	{1519	,1	,1	,&internal1_m300_sbNupIS0},	//(internal1_m300_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{1520	,1	,1	,&internal1_m300_sbVuIS0},	//(internal1_m300_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{1521	,1	,1	,&internal1_m300_sbVuRB0},	//(internal1_m300_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{1522	,1	,1	,&internal1_m311_q0},	//(internal1_m311_q0) q0 - внутренний параметр
	{1523	,5	,1	,&internal1_m319_x0},	//(internal1_m319_x0) x0 - значение входного параметра на предыдущем шаге
	{1524	,1	,1	,&internal1_m320_q0},	//(internal1_m320_q0) q0 - внутренний параметр
	{1525	,8	,1	,&internal1_m323_tx},	//(internal1_m323_tx) tx - внутренний параметр
	{1526	,8	,1	,&internal1_m325_TimS},	//(internal1_m325_TimS) Время до нулевого отсчета
	{1527	,1	,1	,&internal1_m325_pusk0},	//(internal1_m325_pusk0) pusk - разрешение выполнения программы
	{1528	,8	,1	,&internal1_m341_tx},	//(internal1_m341_tx) tx - время накопленное сек
	{1529	,18	,1	,&internal1_m341_y0},	//(internal1_m341_y0) y0
	{1530	,1	,1	,&internal1_m358_ErrPr0},	//(internal1_m358_ErrPr0) ErrPr - Приостановка программы по ошибке
	{1531	,1	,1	,&internal1_m358_FinPr0},	//(internal1_m358_FinPr0) FinPr - конец программы
	{1532	,1	,1	,&internal1_m358_MyFirstEnterFlag},	//(internal1_m358_MyFirstEnterFlag)  
	{1533	,3	,1	,&internal1_m358_Step},	//(internal1_m358_Step)  - текущий шаг программы
	{1534	,8	,1	,&internal1_m358_TimS},	//(internal1_m358_TimS) Время от старта программы
	{1535	,18	,10	,&internal1_m358_rz},	//(internal1_m358_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{1536	,1	,1	,&internal1_m358_sb2UR0},	//(internal1_m358_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{1537	,1	,1	,&internal1_m358_sbINI0},	//(internal1_m358_sbINI0) sbINI - запуск проверки ИНИ
	{1538	,1	,1	,&internal1_m358_sbNupIS0},	//(internal1_m358_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{1539	,1	,1	,&internal1_m358_sbVuIS0},	//(internal1_m358_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{1540	,1	,1	,&internal1_m358_sbVuRB0},	//(internal1_m358_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{1541	,1	,1	,&internal1_m364_q0},	//(internal1_m364_q0) q0 - внутренний параметр
	{1542	,5	,1	,&internal1_m366_x0},	//(internal1_m366_x0) x0 - значение входного параметра на предыдущем шаге
	{1543	,1	,1	,&internal1_m368_q0},	//(internal1_m368_q0) q0 - внутренний параметр
	{1544	,8	,1	,&internal1_m370_tx},	//(internal1_m370_tx) tx - внутренний параметр
	{1545	,18	,1	,&internal1_m392_BlDv0},	//(internal1_m392_BlDv0) - была блокировка
	{1546	,18	,1	,&internal1_m392_DvDw0},	//(internal1_m392_DvDw0) - есть команда на движение назад
	{1547	,18	,1	,&internal1_m392_DvUp0},	//(internal1_m392_DvUp0) - есть команда на движение вперёд
	{1548	,18	,1	,&internal1_m392_FDvDw0},	//(internal1_m392_FDvDw0) - есть команда на движение назад
	{1549	,18	,1	,&internal1_m392_FDvUp0},	//(internal1_m392_FDvUp0) - есть команда на движение вперёд
	{1550	,18	,1	,&internal1_m392_Pkav0},	//(internal1_m392_Pkav0) Pkav - передний конечный аварийный выключатель
	{1551	,18	,1	,&internal1_m392_Pkv0},	//(internal1_m392_Pkv0) Pkv - передний конечный выключатель
	{1552	,18	,1	,&internal1_m392_Zkav0},	//(internal1_m392_Zkav0) Zkav - задний конечный аварийный выключатель
	{1553	,18	,1	,&internal1_m392_Zkv0},	//(internal1_m392_Zkv0) Zkv - задний конечный выключатель
	{1554	,18	,1	,&internal1_m392_fef},	//(internal1_m392_fef) fef
	{1555	,8	,1	,&internal1_m392_txHr},	//(internal1_m392_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{1556	,8	,1	,&internal1_m392_txLd},	//(internal1_m392_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{1557	,8	,1	,&internal1_m392_txNm},	//(internal1_m392_txNm) txNm - счётчик задержки сигнализации недвижения
	{1558	,8	,1	,&internal1_m392_txSm},	//(internal1_m392_txSm) txSm - счётчик задержки сигнализации самохода
	{1559	,8	,1	,&internal1_m397_tx},	//(internal1_m397_tx) tx - внутренний параметр
	{1560	,8	,1	,&internal1_m398_tx},	//(internal1_m398_tx) tx - внутренний параметр
	{1561	,8	,1	,&internal1_m399_tx},	//(internal1_m399_tx) tx - внутренний параметр
	{1562	,8	,1	,&internal1_m400_tx},	//(internal1_m400_tx) tx - внутренний параметр
	{1563	,8	,1	,&internal1_m412_tx},	//(internal1_m412_tx) tx - внутренний параметр
	{1564	,8	,1	,&internal1_m413_tx},	//(internal1_m413_tx) tx - внутренний параметр
	{1565	,8	,1	,&internal1_m414_tx},	//(internal1_m414_tx) tx - внутренний параметр
	{1566	,8	,1	,&internal1_m417_tx},	//(internal1_m417_tx) tx - внутренний параметр
	{1567	,18	,1	,&internal1_m423_BlDv0},	//(internal1_m423_BlDv0) - была блокировка
	{1568	,18	,1	,&internal1_m423_DvDw0},	//(internal1_m423_DvDw0) - есть команда на движение назад
	{1569	,18	,1	,&internal1_m423_DvUp0},	//(internal1_m423_DvUp0) - есть команда на движение вперёд
	{1570	,18	,1	,&internal1_m423_FDvDw0},	//(internal1_m423_FDvDw0) - есть команда на движение назад
	{1571	,18	,1	,&internal1_m423_FDvUp0},	//(internal1_m423_FDvUp0) - есть команда на движение вперёд
	{1572	,18	,1	,&internal1_m423_Pkav0},	//(internal1_m423_Pkav0) Pkav - передний конечный аварийный выключатель
	{1573	,18	,1	,&internal1_m423_Pkv0},	//(internal1_m423_Pkv0) Pkv - передний конечный выключатель
	{1574	,18	,1	,&internal1_m423_Zkav0},	//(internal1_m423_Zkav0) Zkav - задний конечный аварийный выключатель
	{1575	,18	,1	,&internal1_m423_Zkv0},	//(internal1_m423_Zkv0) Zkv - задний конечный выключатель
	{1576	,18	,1	,&internal1_m423_fef},	//(internal1_m423_fef) fef
	{1577	,8	,1	,&internal1_m423_txHr},	//(internal1_m423_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{1578	,8	,1	,&internal1_m423_txLd},	//(internal1_m423_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{1579	,8	,1	,&internal1_m423_txNm},	//(internal1_m423_txNm) txNm - счётчик задержки сигнализации недвижения
	{1580	,8	,1	,&internal1_m423_txSm},	//(internal1_m423_txSm) txSm - счётчик задержки сигнализации самохода
	{1581	,18	,1	,&internal1_m429_BlDv0},	//(internal1_m429_BlDv0) - была блокировка
	{1582	,18	,1	,&internal1_m429_DvDw0},	//(internal1_m429_DvDw0) - есть команда на движение назад
	{1583	,18	,1	,&internal1_m429_DvUp0},	//(internal1_m429_DvUp0) - есть команда на движение вперёд
	{1584	,18	,1	,&internal1_m429_FDvDw0},	//(internal1_m429_FDvDw0) - есть команда на движение назад
	{1585	,18	,1	,&internal1_m429_FDvUp0},	//(internal1_m429_FDvUp0) - есть команда на движение вперёд
	{1586	,18	,1	,&internal1_m429_Pkav0},	//(internal1_m429_Pkav0) Pkav - передний конечный аварийный выключатель
	{1587	,18	,1	,&internal1_m429_Pkv0},	//(internal1_m429_Pkv0) Pkv - передний конечный выключатель
	{1588	,18	,1	,&internal1_m429_Zkav0},	//(internal1_m429_Zkav0) Zkav - задний конечный аварийный выключатель
	{1589	,18	,1	,&internal1_m429_Zkv0},	//(internal1_m429_Zkv0) Zkv - задний конечный выключатель
	{1590	,18	,1	,&internal1_m429_fef},	//(internal1_m429_fef) fef
	{1591	,8	,1	,&internal1_m429_txHr},	//(internal1_m429_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{1592	,8	,1	,&internal1_m429_txLd},	//(internal1_m429_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{1593	,8	,1	,&internal1_m429_txNm},	//(internal1_m429_txNm) txNm - счётчик задержки сигнализации недвижения
	{1594	,8	,1	,&internal1_m429_txSm},	//(internal1_m429_txSm) txSm - счётчик задержки сигнализации самохода
	{1595	,8	,1	,&internal1_m433_tx},	//(internal1_m433_tx) tx - внутренний параметр
	{1596	,8	,1	,&internal1_m439_tx},	//(internal1_m439_tx) tx - внутренний параметр
	{1597	,8	,1	,&internal1_m440_tx},	//(internal1_m440_tx) tx - внутренний параметр
	{1598	,8	,1	,&internal1_m441_tx},	//(internal1_m441_tx) tx - внутренний параметр
	{1599	,8	,1	,&internal1_m450_tx},	//(internal1_m450_tx) tx - внутренний параметр
	{1600	,8	,1	,&internal1_m451_tx},	//(internal1_m451_tx) tx - внутренний параметр
	{1601	,8	,1	,&internal1_m453_tx},	//(internal1_m453_tx) tx - внутренний параметр
	{1602	,8	,1	,&internal1_m459_tx},	//(internal1_m459_tx) tx - внутренний параметр
	{1603	,8	,1	,&internal1_m467_tx},	//(internal1_m467_tx) tx - внутренний параметр
	{1604	,8	,1	,&internal1_m476_tx},	//(internal1_m476_tx) tx - внутренний параметр
	{1605	,8	,1	,&internal1_m478_tx},	//(internal1_m478_tx) tx - внутренний параметр
	{1606	,8	,1	,&internal1_m480_tx},	//(internal1_m480_tx) tx - внутренний параметр
	{1607	,8	,1	,&internal1_m482_tx},	//(internal1_m482_tx) tx - внутренний параметр
	{1608	,8	,1	,&internal1_m487_tx},	//(internal1_m487_tx) tx - внутренний параметр
	{1609	,8	,1	,&internal1_m502_tx},	//(internal1_m502_tx) tx - внутренний параметр
	{1610	,8	,1	,&internal1_m503_tx},	//(internal1_m503_tx) tx - внутренний параметр
	{1611	,8	,1	,&internal1_m504_tx},	//(internal1_m504_tx) tx - внутренний параметр
	{1612	,8	,1	,&internal1_m505_tx},	//(internal1_m505_tx) tx - внутренний параметр
	{1613	,18	,1	,&internal1_m513_BlDv0},	//(internal1_m513_BlDv0) - была блокировка
	{1614	,18	,1	,&internal1_m513_DvDw0},	//(internal1_m513_DvDw0) - есть команда на движение назад
	{1615	,18	,1	,&internal1_m513_DvUp0},	//(internal1_m513_DvUp0) - есть команда на движение вперёд
	{1616	,18	,1	,&internal1_m513_FDvDw0},	//(internal1_m513_FDvDw0) - есть команда на движение назад
	{1617	,18	,1	,&internal1_m513_FDvUp0},	//(internal1_m513_FDvUp0) - есть команда на движение вперёд
	{1618	,18	,1	,&internal1_m513_Pkav0},	//(internal1_m513_Pkav0) Pkav - передний конечный аварийный выключатель
	{1619	,18	,1	,&internal1_m513_Pkv0},	//(internal1_m513_Pkv0) Pkv - передний конечный выключатель
	{1620	,18	,1	,&internal1_m513_Zkav0},	//(internal1_m513_Zkav0) Zkav - задний конечный аварийный выключатель
	{1621	,18	,1	,&internal1_m513_Zkv0},	//(internal1_m513_Zkv0) Zkv - задний конечный выключатель
	{1622	,18	,1	,&internal1_m513_fef},	//(internal1_m513_fef) fef
	{1623	,8	,1	,&internal1_m513_txHr},	//(internal1_m513_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{1624	,8	,1	,&internal1_m513_txLd},	//(internal1_m513_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{1625	,8	,1	,&internal1_m513_txNm},	//(internal1_m513_txNm) txNm - счётчик задержки сигнализации недвижения
	{1626	,8	,1	,&internal1_m513_txSm},	//(internal1_m513_txSm) txSm - счётчик задержки сигнализации самохода
	{1627	,18	,1	,&internal1_m519_BlDv0},	//(internal1_m519_BlDv0) - была блокировка
	{1628	,18	,1	,&internal1_m519_DvDw0},	//(internal1_m519_DvDw0) - есть команда на движение назад
	{1629	,18	,1	,&internal1_m519_DvUp0},	//(internal1_m519_DvUp0) - есть команда на движение вперёд
	{1630	,18	,1	,&internal1_m519_FDvDw0},	//(internal1_m519_FDvDw0) - есть команда на движение назад
	{1631	,18	,1	,&internal1_m519_FDvUp0},	//(internal1_m519_FDvUp0) - есть команда на движение вперёд
	{1632	,18	,1	,&internal1_m519_Pkav0},	//(internal1_m519_Pkav0) Pkav - передний конечный аварийный выключатель
	{1633	,18	,1	,&internal1_m519_Pkv0},	//(internal1_m519_Pkv0) Pkv - передний конечный выключатель
	{1634	,18	,1	,&internal1_m519_Zkav0},	//(internal1_m519_Zkav0) Zkav - задний конечный аварийный выключатель
	{1635	,18	,1	,&internal1_m519_Zkv0},	//(internal1_m519_Zkv0) Zkv - задний конечный выключатель
	{1636	,18	,1	,&internal1_m519_fef},	//(internal1_m519_fef) fef
	{1637	,8	,1	,&internal1_m519_txHr},	//(internal1_m519_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{1638	,8	,1	,&internal1_m519_txLd},	//(internal1_m519_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{1639	,8	,1	,&internal1_m519_txNm},	//(internal1_m519_txNm) txNm - счётчик задержки сигнализации недвижения
	{1640	,8	,1	,&internal1_m519_txSm},	//(internal1_m519_txSm) txSm - счётчик задержки сигнализации самохода
	{1641	,8	,1	,&internal1_m527_tx},	//(internal1_m527_tx) tx - внутренний параметр
	{1642	,8	,1	,&internal1_m52_tx},	//(internal1_m52_tx) tx - внутренний параметр
	{1643	,8	,1	,&internal1_m531_tx},	//(internal1_m531_tx) tx - внутренний параметр
	{1644	,8	,1	,&internal1_m532_tx},	//(internal1_m532_tx) tx - внутренний параметр
	{1645	,8	,1	,&internal1_m533_tx},	//(internal1_m533_tx) tx - внутренний параметр
	{1646	,8	,1	,&internal1_m54_tim},	//(internal1_m54_tim) - время задержки выходного сигнала
	{1647	,1	,1	,&internal1_m54_x0},	//(internal1_m54_x0) - значение входного параметра на предыдущем шаге
	{1648	,18	,1	,&internal1_m552_BLDv0},	//(internal1_m552_BLDv0) BlDv - Блокировка движения
	{1649	,8	,1	,&internal1_m552_X0},	//(internal1_m552_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{1650	,8	,1	,&internal1_m552_t0},	//(internal1_m552_t0) время нахождения в зоне возврата
	{1651	,8	,1	,&internal1_m570_tx},	//(internal1_m570_tx) tx - время накопленное сек
	{1652	,18	,1	,&internal1_m570_y0},	//(internal1_m570_y0) y0
	{1653	,8	,1	,&internal1_m571_tx},	//(internal1_m571_tx) tx - время накопленное сек
	{1654	,18	,1	,&internal1_m571_y0},	//(internal1_m571_y0) y0
	{1655	,8	,1	,&internal1_m575_DelSp},	//(internal1_m575_DelSp) DelSp - время переключения скоростей
	{1656	,1	,1	,&internal1_m575_ShCntlSp0},	//(internal1_m575_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{1657	,1	,1	,&internal1_m575_Shift0},	//(internal1_m575_Shift0) Shift0 - признак самохода
	{1658	,1	,1	,&internal1_m575_ShiftControl},	//(internal1_m575_ShiftControl) ShiftControl - признак самохода
	{1659	,8	,1	,&internal1_m575_Speed0},	//(internal1_m575_Speed0) Speed0 - предыдущее значение скорости перемещения
	{1660	,8	,1	,&internal1_m575_StSpeed},	//(internal1_m575_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{1661	,8	,1	,&internal1_m575_Vz0},	//(internal1_m575_Vz0) Vz0 - предыдущая заданная скорость
	{1662	,3	,1	,&internal1_m575_flRazg},	//(internal1_m575_flRazg) признак разгона/торможения
	{1663	,8	,1	,&internal1_m575_sumtim},	//(internal1_m575_sumtim) sumtim - время в пути
	{1664	,8	,150	,&internal1_m575_tim0},	//(internal1_m575_tim0) tim0 - массив значений времени цикла
	{1665	,8	,1	,&internal1_m575_tx},	//(internal1_m575_tx) tx
	{1666	,8	,1	,&internal1_m575_txBl},	//(internal1_m575_txBl) tx
	{1667	,8	,1	,&internal1_m575_txMBl},	//(internal1_m575_txMBl) tx
	{1668	,8	,1	,&internal1_m575_txZS},	//(internal1_m575_txZS) txZS
	{1669	,8	,1	,&internal1_m575_txd},	//(internal1_m575_txd) txd
	{1670	,8	,1	,&internal1_m575_tz0},	//(internal1_m575_tz0) tz0 - время защиты от нового задания сек
	{1671	,8	,150	,&internal1_m575_x0},	//(internal1_m575_x0) x0 - массив мгновенных значений координат
	{1672	,3	,1	,&internal1_m575_xptr},	//(internal1_m575_xptr) указатель текущей позиции в массиве координат
	{1673	,8	,1	,&internal1_m575_xz0},	//(internal1_m575_xz0) xz0 - новое задание мм
	{1674	,8	,1	,&internal1_m575_z0},	//(internal1_m575_z0) z0 - точка прекращения движения
	{1675	,8	,1	,&internal1_m576_tx},	//(internal1_m576_tx) tx - внутренний параметр
	{1676	,8	,1	,&internal1_m577_tx},	//(internal1_m577_tx) tx - внутренний параметр
	{1677	,8	,1	,&internal1_m578_tx},	//(internal1_m578_tx) tx - внутренний параметр
	{1678	,8	,1	,&internal1_m583_tx},	//(internal1_m583_tx) tx - внутренний параметр
	{1679	,8	,1	,&internal1_m590_tx},	//(internal1_m590_tx) tx - время накопленное сек
	{1680	,18	,1	,&internal1_m590_y0},	//(internal1_m590_y0) y0
	{1681	,8	,1	,&internal1_m596_tx},	//(internal1_m596_tx) tx - внутренний параметр
	{1682	,8	,1	,&internal1_m598_tx},	//(internal1_m598_tx) tx - внутренний параметр
	{1683	,8	,1	,&internal1_m600_tx},	//(internal1_m600_tx) tx - внутренний параметр
	{1684	,8	,1	,&internal1_m609_tx},	//(internal1_m609_tx) tx - внутренний параметр
	{1685	,8	,1	,&internal1_m613_tx},	//(internal1_m613_tx) tx - внутренний параметр
	{1686	,8	,1	,&internal1_m614_tx},	//(internal1_m614_tx) tx - внутренний параметр
	{1687	,8	,1	,&internal1_m624_tx},	//(internal1_m624_tx) tx - внутренний параметр
	{1688	,8	,1	,&internal1_m628_tx},	//(internal1_m628_tx) tx - внутренний параметр
	{1689	,8	,1	,&internal1_m630_tx},	//(internal1_m630_tx) tx - внутренний параметр
	{1690	,8	,1	,&internal1_m637_tx},	//(internal1_m637_tx) tx - внутренний параметр
	{1691	,8	,1	,&internal1_m638_tx},	//(internal1_m638_tx) tx - внутренний параметр
	{1692	,8	,1	,&internal1_m639_tx},	//(internal1_m639_tx) tx - внутренний параметр
	{1693	,8	,1	,&internal1_m641_tx},	//(internal1_m641_tx) tx - внутренний параметр
	{1694	,8	,1	,&internal1_m642_tx},	//(internal1_m642_tx) tx - внутренний параметр
	{1695	,1	,1	,&internal1_m669_q0},	//(internal1_m669_q0) q0 - внутренний параметр
	{1696	,1	,1	,&internal1_m679_q0},	//(internal1_m679_q0) q0 - внутренний параметр
	{1697	,1	,1	,&internal1_m689_q0},	//(internal1_m689_q0) q0 - внутренний параметр
	{1698	,1	,1	,&internal1_m691_q0},	//(internal1_m691_q0) q0 - внутренний параметр
	{1699	,1	,1	,&internal1_m693_q0},	//(internal1_m693_q0) q0 - внутренний параметр
	{1700	,1	,1	,&internal1_m694_q0},	//(internal1_m694_q0) q0 - внутренний параметр
	{1701	,1	,1	,&internal1_m696_q0},	//(internal1_m696_q0) q0 - внутренний параметр
	{1702	,1	,1	,&internal1_m698_q0},	//(internal1_m698_q0) q0 - внутренний параметр
	{1703	,1	,1	,&internal1_m699_q0},	//(internal1_m699_q0) q0 - внутренний параметр
	{1704	,1	,1	,&internal1_m701_q0},	//(internal1_m701_q0) q0 - внутренний параметр
	{1705	,1	,1	,&internal1_m704_q0},	//(internal1_m704_q0) q0 - внутренний параметр
	{1706	,1	,1	,&internal1_m709_q0},	//(internal1_m709_q0) q0 - внутренний параметр
	{1707	,1	,1	,&internal1_m713_q0},	//(internal1_m713_q0) q0 - внутренний параметр
	{1708	,1	,1	,&internal1_m714_q0},	//(internal1_m714_q0) q0 - внутренний параметр
	{1709	,1	,1	,&internal1_m722_q0},	//(internal1_m722_q0) q0 - внутренний параметр
	{1710	,1	,1	,&internal1_m726_q0},	//(internal1_m726_q0) q0 - внутренний параметр
	{1711	,8	,1	,&internal1_m737_tx},	//(internal1_m737_tx) tx - внутренний параметр
	{1712	,1	,1	,&internal1_m743_x0},	//(internal1_m743_x0) x0 - значение входного параметра на предыдущем шаге
	{1713	,8	,1	,&internal1_m744_tx},	//(internal1_m744_tx) tx - внутренний параметр
	{1714	,8	,1	,&internal1_m748_tx},	//(internal1_m748_tx) tx - внутренний параметр
	{1715	,8	,1	,&internal1_m753_tx},	//(internal1_m753_tx) tx - внутренний параметр
	{1716	,8	,1	,&internal1_m763_tx},	//(internal1_m763_tx) tx - внутренний параметр
	{1717	,8	,1	,&internal1_m768_tx},	//(internal1_m768_tx) tx - внутренний параметр
	{1718	,8	,1	,&internal1_m769_tx},	//(internal1_m769_tx) tx - внутренний параметр
	{1719	,8	,1	,&internal1_m772_tx},	//(internal1_m772_tx) tx - внутренний параметр
	{1720	,8	,1	,&internal1_m777_tx},	//(internal1_m777_tx) tx - внутренний параметр
	{1721	,8	,1	,&internal1_m779_tx},	//(internal1_m779_tx) tx - внутренний параметр
	{1722	,8	,1	,&internal1_m787_tx},	//(internal1_m787_tx) tx - внутренний параметр
	{1723	,8	,1	,&internal1_m796_tx},	//(internal1_m796_tx) tx - внутренний параметр
	{1724	,8	,1	,&internal1_m797_tx},	//(internal1_m797_tx) tx - внутренний параметр
	{1725	,8	,1	,&internal1_m798_tx},	//(internal1_m798_tx) tx - внутренний параметр
	{1726	,1	,1	,&internal1_m79_MyFirstEnterFlag},	//(internal1_m79_MyFirstEnterFlag)  FirstEnterFlag
	{1727	,8	,1	,&internal1_m79_W1},	//(internal1_m79_W1)  мощность на старте измерения
	{1728	,8	,1	,&internal1_m79_W2},	//(internal1_m79_W2)  мощность в конце измерения
	{1729	,8	,1	,&internal1_m79_Wlast},	//(internal1_m79_Wlast)  последнее растущее измерение
	{1730	,8	,1	,&internal1_m79_Wmax},	//(internal1_m79_Wmax)  максимальное измерение в серии
	{1731	,8	,1	,&internal1_m79_Wmin},	//(internal1_m79_Wmin)  минимальное измерение в серии
	{1732	,3	,1	,&internal1_m79_chizm},	//(internal1_m79_chizm)  счетчик уменьшения мощности
	{1733	,3	,1	,&internal1_m79_chsr},	//(internal1_m79_chsr)  счетчик усреднения
	{1734	,3	,1	,&internal1_m79_flst},	//(internal1_m79_flst)  флаг старта измерения
	{1735	,8	,1	,&internal1_m79_sumtim},	//(internal1_m79_sumtim)  время измерения мощности
	{1736	,8	,1	,&internal1_m79_y0},	//(internal1_m79_y0) y0 - внутренний параметр
	{1737	,1	,1	,&internal1_m800_x0},	//(internal1_m800_x0) x0 - значение входного параметра на предыдущем шаге
	{1738	,8	,1	,&internal1_m801_tx},	//(internal1_m801_tx) tx - внутренний параметр
	{1739	,1	,1	,&internal1_m820_q0},	//(internal1_m820_q0) q0 - внутренний параметр
	{1740	,1	,1	,&internal1_m823_q0},	//(internal1_m823_q0) q0 - внутренний параметр
	{1741	,1	,1	,&internal1_m825_q0},	//(internal1_m825_q0) q0 - внутренний параметр
	{1742	,1	,1	,&internal1_m826_q0},	//(internal1_m826_q0) q0 - внутренний параметр
	{1743	,1	,1	,&internal1_m829_q0},	//(internal1_m829_q0) q0 - внутренний параметр
	{1744	,8	,1	,&internal1_m82_tx},	//(internal1_m82_tx) tx - внутренний параметр
	{1745	,1	,1	,&internal1_m832_x0},	//(internal1_m832_x0) x0 - значение входного параметра на предыдущем шаге
	{1746	,1	,1	,&internal1_m833_q0},	//(internal1_m833_q0) q0 - внутренний параметр
	{1747	,8	,1	,&internal1_m836_tx},	//(internal1_m836_tx) tx - время накопленное сек
	{1748	,18	,1	,&internal1_m836_y0},	//(internal1_m836_y0) y0
	{1749	,8	,1	,&internal1_m837_tx},	//(internal1_m837_tx) tx - внутренний параметр
	{1750	,1	,1	,&internal1_m838_q0},	//(internal1_m838_q0) q0 - внутренний параметр
	{1751	,1	,1	,&internal1_m845_q0},	//(internal1_m845_q0) q0 - внутренний параметр
	{1752	,1	,1	,&internal1_m852_q0},	//(internal1_m852_q0) q0 - внутренний параметр
	{1753	,1	,1	,&internal1_m857_q0},	//(internal1_m857_q0) q0 - внутренний параметр
	{1754	,8	,1	,&internal1_m866_tx},	//(internal1_m866_tx) tx - внутренний параметр
	{1755	,8	,1	,&internal1_m867_tx},	//(internal1_m867_tx) tx - внутренний параметр
	{1756	,8	,1	,&internal1_m868_tx},	//(internal1_m868_tx) tx - внутренний параметр
	{1757	,8	,1	,&internal1_m872_tx},	//(internal1_m872_tx) tx - внутренний параметр
	{1758	,18	,1	,&internal1_m877_BlDv0},	//(internal1_m877_BlDv0) - была блокировка
	{1759	,18	,1	,&internal1_m877_DvDw0},	//(internal1_m877_DvDw0) - есть команда на движение назад
	{1760	,18	,1	,&internal1_m877_DvUp0},	//(internal1_m877_DvUp0) - есть команда на движение вперёд
	{1761	,18	,1	,&internal1_m877_FDvDw0},	//(internal1_m877_FDvDw0) - есть команда на движение назад
	{1762	,18	,1	,&internal1_m877_FDvUp0},	//(internal1_m877_FDvUp0) - есть команда на движение вперёд
	{1763	,18	,1	,&internal1_m877_Pkav0},	//(internal1_m877_Pkav0) Pkav - передний конечный аварийный выключатель
	{1764	,18	,1	,&internal1_m877_Pkv0},	//(internal1_m877_Pkv0) Pkv - передний конечный выключатель
	{1765	,18	,1	,&internal1_m877_Zkav0},	//(internal1_m877_Zkav0) Zkav - задний конечный аварийный выключатель
	{1766	,18	,1	,&internal1_m877_Zkv0},	//(internal1_m877_Zkv0) Zkv - задний конечный выключатель
	{1767	,18	,1	,&internal1_m877_fef},	//(internal1_m877_fef) fef
	{1768	,8	,1	,&internal1_m877_txHr},	//(internal1_m877_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{1769	,8	,1	,&internal1_m877_txLd},	//(internal1_m877_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{1770	,8	,1	,&internal1_m877_txNm},	//(internal1_m877_txNm) txNm - счётчик задержки сигнализации недвижения
	{1771	,8	,1	,&internal1_m877_txSm},	//(internal1_m877_txSm) txSm - счётчик задержки сигнализации самохода
	{1772	,18	,1	,&internal1_m881_BlDv0},	//(internal1_m881_BlDv0) - была блокировка
	{1773	,18	,1	,&internal1_m881_DvDw0},	//(internal1_m881_DvDw0) - есть команда на движение назад
	{1774	,18	,1	,&internal1_m881_DvUp0},	//(internal1_m881_DvUp0) - есть команда на движение вперёд
	{1775	,18	,1	,&internal1_m881_FDvDw0},	//(internal1_m881_FDvDw0) - есть команда на движение назад
	{1776	,18	,1	,&internal1_m881_FDvUp0},	//(internal1_m881_FDvUp0) - есть команда на движение вперёд
	{1777	,18	,1	,&internal1_m881_Pkav0},	//(internal1_m881_Pkav0) Pkav - передний конечный аварийный выключатель
	{1778	,18	,1	,&internal1_m881_Pkv0},	//(internal1_m881_Pkv0) Pkv - передний конечный выключатель
	{1779	,18	,1	,&internal1_m881_Zkav0},	//(internal1_m881_Zkav0) Zkav - задний конечный аварийный выключатель
	{1780	,18	,1	,&internal1_m881_Zkv0},	//(internal1_m881_Zkv0) Zkv - задний конечный выключатель
	{1781	,18	,1	,&internal1_m881_fef},	//(internal1_m881_fef) fef
	{1782	,8	,1	,&internal1_m881_txHr},	//(internal1_m881_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{1783	,8	,1	,&internal1_m881_txLd},	//(internal1_m881_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{1784	,8	,1	,&internal1_m881_txNm},	//(internal1_m881_txNm) txNm - счётчик задержки сигнализации недвижения
	{1785	,8	,1	,&internal1_m881_txSm},	//(internal1_m881_txSm) txSm - счётчик задержки сигнализации самохода
	{1786	,8	,1	,&internal1_m889_tx},	//(internal1_m889_tx) tx - внутренний параметр
	{1787	,8	,1	,&internal1_m893_tx},	//(internal1_m893_tx) tx - внутренний параметр
	{1788	,8	,1	,&internal1_m894_tx},	//(internal1_m894_tx) tx - внутренний параметр
	{1789	,8	,1	,&internal1_m895_tx},	//(internal1_m895_tx) tx - внутренний параметр
	{1790	,18	,1	,&internal1_m911_BLDv0},	//(internal1_m911_BLDv0) BlDv - Блокировка движения
	{1791	,8	,1	,&internal1_m911_X0},	//(internal1_m911_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{1792	,8	,1	,&internal1_m911_t0},	//(internal1_m911_t0) время нахождения в зоне возврата
	{1793	,8	,1	,&internal1_m923_tx},	//(internal1_m923_tx) tx - время накопленное сек
	{1794	,18	,1	,&internal1_m923_y0},	//(internal1_m923_y0) y0
	{1795	,8	,1	,&internal1_m924_tx},	//(internal1_m924_tx) tx - время накопленное сек
	{1796	,18	,1	,&internal1_m924_y0},	//(internal1_m924_y0) y0
	{1797	,8	,1	,&internal1_m926_tx},	//(internal1_m926_tx) tx - внутренний параметр
	{1798	,8	,1	,&internal1_m927_tx},	//(internal1_m927_tx) tx - внутренний параметр
	{1799	,8	,1	,&internal1_m929_DelSp},	//(internal1_m929_DelSp) DelSp - время переключения скоростей
	{1800	,1	,1	,&internal1_m929_ShCntlSp0},	//(internal1_m929_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{1801	,1	,1	,&internal1_m929_Shift0},	//(internal1_m929_Shift0) Shift0 - признак самохода
	{1802	,1	,1	,&internal1_m929_ShiftControl},	//(internal1_m929_ShiftControl) ShiftControl - признак самохода
	{1803	,8	,1	,&internal1_m929_Speed0},	//(internal1_m929_Speed0) Speed0 - предыдущее значение скорости перемещения
	{1804	,8	,1	,&internal1_m929_StSpeed},	//(internal1_m929_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{1805	,8	,1	,&internal1_m929_Vz0},	//(internal1_m929_Vz0) Vz0 - предыдущая заданная скорость
	{1806	,3	,1	,&internal1_m929_flRazg},	//(internal1_m929_flRazg) признак разгона/торможения
	{1807	,8	,1	,&internal1_m929_sumtim},	//(internal1_m929_sumtim) sumtim - время в пути
	{1808	,8	,80	,&internal1_m929_tim0},	//(internal1_m929_tim0) tim0 - массив значений времени цикла
	{1809	,8	,1	,&internal1_m929_tx},	//(internal1_m929_tx) tx
	{1810	,8	,1	,&internal1_m929_txBl},	//(internal1_m929_txBl) tx
	{1811	,8	,1	,&internal1_m929_txMBl},	//(internal1_m929_txMBl) tx
	{1812	,8	,1	,&internal1_m929_txZS},	//(internal1_m929_txZS) txZS
	{1813	,8	,1	,&internal1_m929_txd},	//(internal1_m929_txd) txd
	{1814	,8	,1	,&internal1_m929_tz0},	//(internal1_m929_tz0) tz0 - время защиты от нового задания сек
	{1815	,8	,80	,&internal1_m929_x0},	//(internal1_m929_x0) x0 - массив мгновенных значений координат
	{1816	,3	,1	,&internal1_m929_xptr},	//(internal1_m929_xptr) указатель текущей позиции в массиве координат
	{1817	,8	,1	,&internal1_m929_xz0},	//(internal1_m929_xz0) xz0 - новое задание мм
	{1818	,8	,1	,&internal1_m929_z0},	//(internal1_m929_z0) z0 - точка прекращения движения
	{1819	,8	,1	,&internal1_m931_tx},	//(internal1_m931_tx) tx - внутренний параметр
	{1820	,8	,1	,&internal1_m936_tx},	//(internal1_m936_tx) tx - внутренний параметр
	{1821	,8	,1	,&internal1_m941_tx},	//(internal1_m941_tx) tx - время накопленное сек
	{1822	,18	,1	,&internal1_m941_y0},	//(internal1_m941_y0) y0
	{1823	,8	,1	,&internal1_m951_tx},	//(internal1_m951_tx) tx - внутренний параметр
	{1824	,8	,1	,&internal1_m952_tx},	//(internal1_m952_tx) tx - внутренний параметр
	{1825	,8	,1	,&internal1_m954_tx},	//(internal1_m954_tx) tx - внутренний параметр
	{1826	,8	,1	,&internal1_m965_tx},	//(internal1_m965_tx) tx - внутренний параметр
	{1827	,8	,1	,&internal1_m969_tx},	//(internal1_m969_tx) tx - внутренний параметр
	{1828	,8	,1	,&internal1_m973_tx},	//(internal1_m973_tx) tx - внутренний параметр
	{1829	,8	,1	,&internal1_m979_tx},	//(internal1_m979_tx) tx - внутренний параметр
	{1830	,8	,1	,&internal1_m981_tx},	//(internal1_m981_tx) tx - внутренний параметр
	{1831	,8	,1	,&internal1_m986_tx},	//(internal1_m986_tx) tx - внутренний параметр
	{1832	,8	,1	,&internal1_m987_tx},	//(internal1_m987_tx) tx - внутренний параметр
	{1833	,8	,1	,&internal1_m988_tx},	//(internal1_m988_tx) tx - внутренний параметр
	{1834	,8	,1	,&internal1_m991_tx},	//(internal1_m991_tx) tx - внутренний параметр
	{1835	,5	,1	,&internal2_m106_Nk0},	//(internal2_m106_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{1836	,1	,1	,&internal2_m106_SetFlag},	//(internal2_m106_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{1837	,5	,1	,&internal2_m110_Nk0},	//(internal2_m110_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{1838	,1	,1	,&internal2_m110_SetFlag},	//(internal2_m110_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{1839	,8	,1	,&internal2_m127_tx},	//(internal2_m127_tx) tx - время накопленное сек
	{1840	,18	,1	,&internal2_m127_y0},	//(internal2_m127_y0) y0
	{1841	,8	,1	,&internal2_m132_tx},	//(internal2_m132_tx) tx - время накопленное сек
	{1842	,18	,1	,&internal2_m132_y0},	//(internal2_m132_y0) y0
	{1843	,8	,1	,&internal2_m134_tx},	//(internal2_m134_tx) tx - время накопленное сек
	{1844	,18	,1	,&internal2_m134_y0},	//(internal2_m134_y0) y0
	{1845	,8	,1	,&internal2_m141_tx},	//(internal2_m141_tx) tx - время накопленное сек
	{1846	,18	,1	,&internal2_m141_y0},	//(internal2_m141_y0) y0
	{1847	,8	,1	,&internal2_m144_tx},	//(internal2_m144_tx) tx - время накопленное сек
	{1848	,18	,1	,&internal2_m144_y0},	//(internal2_m144_y0) y0
	{1849	,8	,1	,&internal2_m149_tx},	//(internal2_m149_tx) tx - время накопленное сек
	{1850	,18	,1	,&internal2_m149_y0},	//(internal2_m149_y0) y0
	{1851	,8	,1	,&internal2_m155_tx},	//(internal2_m155_tx) tx - время накопленное сек
	{1852	,18	,1	,&internal2_m155_y0},	//(internal2_m155_y0) y0
	{1853	,8	,1	,&internal2_m158_tx},	//(internal2_m158_tx) tx - время накопленное сек
	{1854	,18	,1	,&internal2_m158_y0},	//(internal2_m158_y0) y0
	{1855	,5	,1	,&internal2_m15_Nk0},	//(internal2_m15_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{1856	,1	,1	,&internal2_m15_SetFlag},	//(internal2_m15_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{1857	,8	,1	,&internal2_m165_tx},	//(internal2_m165_tx) tx - время накопленное сек
	{1858	,18	,1	,&internal2_m165_y0},	//(internal2_m165_y0) y0
	{1859	,8	,1	,&internal2_m173_tx},	//(internal2_m173_tx) tx - время накопленное сек
	{1860	,18	,1	,&internal2_m173_y0},	//(internal2_m173_y0) y0
	{1861	,8	,1	,&internal2_m176_tx},	//(internal2_m176_tx) tx - время накопленное сек
	{1862	,18	,1	,&internal2_m176_y0},	//(internal2_m176_y0) y0
	{1863	,5	,1	,&internal2_m17_Nk0},	//(internal2_m17_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{1864	,1	,1	,&internal2_m17_SetFlag},	//(internal2_m17_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{1865	,8	,1	,&internal2_m182_tx},	//(internal2_m182_tx) tx - время накопленное сек
	{1866	,18	,1	,&internal2_m182_y0},	//(internal2_m182_y0) y0
	{1867	,8	,1	,&internal2_m193_y0},	//(internal2_m193_y0) y0
	{1868	,8	,1	,&internal2_m195_y0},	//(internal2_m195_y0) y0
	{1869	,1	,1	,&internal2_m198_y1},	//(internal2_m198_y1) y1 - внутренний параметр
	{1870	,1	,1	,&internal2_m205_y1},	//(internal2_m205_y1) y1 - внутренний параметр
	{1871	,1	,1	,&internal2_m208_y1},	//(internal2_m208_y1) y1 - внутренний параметр
	{1872	,1	,1	,&internal2_m214_y1},	//(internal2_m214_y1) y1 - внутренний параметр
	{1873	,1	,1	,&internal2_m220_y0},	//(internal2_m220_y0) state
	{1874	,1	,1	,&internal2_m228_y0},	//(internal2_m228_y0) state
	{1875	,5	,1	,&internal2_m49_Nk0},	//(internal2_m49_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{1876	,1	,1	,&internal2_m49_SetFlag},	//(internal2_m49_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{1877	,5	,1	,&internal2_m53_Nk0},	//(internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{1878	,1	,1	,&internal2_m53_SetFlag},	//(internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{1879	,5	,1	,&internal2_m75_Nk0},	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{1880	,1	,1	,&internal2_m75_SetFlag},	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{1881	,5	,1	,&internal2_m77_Nk0},	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{1882	,1	,1	,&internal2_m77_SetFlag},	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{1883	,1	,1	,&lEM_R0MD01LC1},	//(R0MD01LC1) Ручное управление ОРР
	{1884	,1	,1	,&psb1},	//( - , DU) ру не готова
	{1885	,1	,1	,&psb2},	//( - , DU) движение бб
	{1886	,5	,1	,&venc01},	//(vencf8l:01 - venc01, - ) заначение реального энкодера ББ1
	{1887	,5	,1	,&venc02},	//(vencf8l:01 - venc02, - ) заначение реального энкодера РБ1
	{1888	,5	,1	,&venc03},	//(vencf8l:01 - venc03, - ) заначение реального энкодера Ис1
	{1889	,5	,1	,&venc04},	//(vencf8l:01 - venc04, - ) заначение реального энкодера ДС1
	{1890	,5	,1	,&venc05},	//(vencf8l:01 - venc05, - ) заначение реального энкодера ББ2
	{1891	,5	,1	,&venc06},	//(vencf8l:01 - venc06, - ) заначение реального энкодера РБ2
	{1892	,5	,1	,&venc07},	//(vencf8l:01 - venc07, - ) заначение реального энкодера ИС2
	{1893	,5	,1	,&venc08},	//(vencf8l:01 - venc08, - ) заначение реального энкодера АЗ2
	{-1,0,NULL},
};
static char NameSaveFile[]="du.bin\0"; //Имя файла сохранения переменных
#pragma pop
static VarSaveCtrl saveVariables[]={	//Id переменных для сохранения
	{725,"dEM_A1UC05UDU\0"},	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
	{726,"dEM_A1UC06UDU\0"},	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
	{727,"dEM_A2UC05UDU\0"},	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
	{728,"dEM_A2UC06UDU\0"},	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
	{729,"dEM_A3UC05UDU\0"},	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
	{730,"dEM_A3UC06UDU\0"},	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
	{731,"dEM_A8UC05UDU\0"},	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
	{732,"dEM_A8UC06UDU\0"},	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
	{733,"fEM_A1UC02RDU\0"},	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
	{734,"fEM_A1UC03RDU\0"},	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
	{735,"fEM_A1UC05RDU\0"},	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
	{736,"fEM_A1UC06RDU\0"},	//(A1UC06RDU) Уставка определения самохода ББ  мм
	{737,"fEM_A1UC07RDU\0"},	//(A1UC07RDU) Зона возврата при наведении ББ мм
	{738,"fEM_A1UC08RDU\0"},	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
	{739,"fEM_A1UC81RDU\0"},	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
	{740,"fEM_A1UC82RDU\0"},	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
	{741,"fEM_A1UC83RDU\0"},	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
	{742,"fEM_A1UL01RDU\0"},	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{743,"fEM_A1UL03RDU\0"},	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
	{744,"fEM_A1UL04RDU\0"},	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
	{745,"fEM_A1UL05RDU\0"},	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
	{746,"fEM_A1UR01RDU\0"},	//(A1UR01RDU) коэффициент реактивности от координаты ББ
	{747,"fEM_A1UV01RDU\0"},	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
	{748,"fEM_A1UV02RDU\0"},	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
	{749,"fEM_A2UC02RDU\0"},	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
	{750,"fEM_A2UC03RDU\0"},	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
	{751,"fEM_A2UC05RDU\0"},	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
	{752,"fEM_A2UC06RDU\0"},	//(A2UC06RDU) Уставка определения самохода РБ  мм
	{753,"fEM_A2UC07RDU\0"},	//(A2UC07RDU) Зона возврата при наведении РБ  мм
	{754,"fEM_A2UC08RDU\0"},	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
	{755,"fEM_A2UC81RDU\0"},	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
	{756,"fEM_A2UC82RDU\0"},	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
	{757,"fEM_A2UC83RDU\0"},	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
	{758,"fEM_A2UL01RDU\0"},	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{759,"fEM_A2UL03RDU\0"},	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{760,"fEM_A2UL04RDU\0"},	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
	{761,"fEM_A2UL05RDU\0"},	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
	{762,"fEM_A2UL83RDU\0"},	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{763,"fEM_A2UV01RDU\0"},	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
	{764,"fEM_A2UV02RDU\0"},	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
	{765,"fEM_A3UC02RDU\0"},	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
	{766,"fEM_A3UC03RDU\0"},	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
	{767,"fEM_A3UC05RDU\0"},	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
	{768,"fEM_A3UC06RDU\0"},	//(A3UC06RDU) Уставка определения самохода ИС1  мм
	{769,"fEM_A3UC07RDU\0"},	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
	{770,"fEM_A3UC08RDU\0"},	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
	{771,"fEM_A3UC09RDU\0"},	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
	{772,"fEM_A3UC81RDU\0"},	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
	{773,"fEM_A3UC82RDU\0"},	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
	{774,"fEM_A3UL01RDU\0"},	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{775,"fEM_A3UL03RDU\0"},	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
	{776,"fEM_A3UL04RDU\0"},	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
	{777,"fEM_A3UL05RDU\0"},	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
	{778,"fEM_A3UP03RDU\0"},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{779,"fEM_A3UP04RDU\0"},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{780,"fEM_A3UP43RDU\0"},	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
	{781,"fEM_A3UP44RDU\0"},	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
	{782,"fEM_A3UP53RDU\0"},	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
	{783,"fEM_A3UP54RDU\0"},	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
	{784,"fEM_A3UP85RDU\0"},	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{785,"fEM_A3UP86RDU\0"},	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{786,"fEM_A3UP87RDU\0"},	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{787,"fEM_A3UP88RDU\0"},	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{788,"fEM_A3UR01RDU\0"},	//(A3UR01RDU) коэффициент реактивности от координаты ИС
	{789,"fEM_A3UV01RDU\0"},	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
	{790,"fEM_A3UV02RDU\0"},	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
	{791,"fEM_A4UZ03RDU\0"},	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
	{792,"fEM_A4UZ04RDU\0"},	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
	{793,"fEM_A4UZ05RDU\0"},	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
	{794,"fEM_A5UZ03RDU\0"},	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
	{795,"fEM_A5UZ04RDU\0"},	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
	{796,"fEM_A5UZ05RDU\0"},	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
	{797,"fEM_A6UZ03RDU\0"},	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
	{798,"fEM_A6UZ04RDU\0"},	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
	{799,"fEM_A6UZ05RDU\0"},	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
	{800,"fEM_A8UC03RDU\0"},	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
	{801,"fEM_A9UZ03RDU\0"},	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
	{802,"fEM_A9UZ04RDU\0"},	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
	{803,"fEM_A9UZ05RDU\0"},	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
	{804,"fEM_B8UC01RDU\0"},	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
	{805,"fEM_B8UC02RDU\0"},	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
	{806,"fEM_B8UC05RDU\0"},	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
	{807,"fEM_B8UC06RDU\0"},	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
	{808,"fEM_B8UL01RDU\0"},	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{809,"fEM_B8UL03RDU\0"},	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
	{810,"fEM_B8UL04RDU\0"},	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
	{811,"fEM_B8UL05RDU\0"},	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
	{812,"fEM_B8UL06RDU\0"},	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
	{813,"fEM_B8UL07RDU\0"},	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
	{814,"fEM_B8UV01RDU\0"},	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
	{815,"fEM_B8UV02RDU\0"},	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
	{816,"fEM_B8UV03RDU\0"},	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
	{817,"fEM_B8UV04RDU\0"},	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
	{818,"fEM_R0UL00RDU\0"},	//(R0UL00RDU) Время ожидания передачи  сигнала отключения сети
	{819,"fEM_R0UL01RSS\0"},	//(R0UL01RSS) Шаг измерения периода (сек)
	{820,"fEM_R0UL02RDU\0"},	//(R0UL02RDU) Время задержки  ИНИ
	{821,"fEM_R0UL02RSS\0"},	//(R0UL02RSS) Tф-постоянная времени, с
	{822,"fEM_R0UL03RDU\0"},	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
	{823,"fEM_R0UL04RDU\0"},	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
	{824,"fEM_R0UL05RDU\0"},	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
	{825,"fEM_R0UL06RDU\0"},	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
	{826,"fEM_R0UL07RDU\0"},	//(R0UL07RDU) Время срабатывания верхней АС II УР
	{827,"fEM_R0UL16RDU\0"},	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
	{828,"fEM_R0UL17RDU\0"},	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
	{829,"fEM_R0UL18RDU\0"},	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
	{830,"fEM_R0UL19RDU\0"},	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{831,"fEM_R0UL20RDU\0"},	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
	{832,"fEM_R0UL21RDU\0"},	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
	{833,"fEM_R0UL25RDU\0"},	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{834,"fEM_R0UN01RDU\0"},	//(R0UN01RDU) 1-я заданная мощность
	{835,"fEM_R0UN02RDU\0"},	//(R0UN02RDU) 2-я заданная мощность
	{836,"fEM_R0UN03RDU\0"},	//(R0UN03RDU) Ограничение 3 по мощности
	{837,"fEM_R0UN03RSS\0"},	//(R0UN03RSS) нижняя граница мощности для индикации периода  (ватт)
	{838,"fEM_R0UN04RDU\0"},	//(R0UN04RDU) 4-я заданная мощность
	{839,"fEM_R0UN05RDU\0"},	//(R0UN05RDU) 5-я заданная мощность
	{840,"fEM_R0UN06RDU\0"},	//(R0UN06RDU) 6-я заданная мощность
	{841,"fEM_R0UN07RDU\0"},	//(R0UN07RDU) 7-я заданная мощность
	{842,"fEM_R0UN08RDU\0"},	//(R0UN08RDU) 8-я заданная мощность
	{843,"fEM_R0UN09RDU\0"},	//(R0UN09RDU) Минимальный период при регулировании мощности
	{844,"fEM_R0UN11RDU\0"},	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
	{845,"fEM_R0UN12RDU\0"},	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
	{846,"fEM_R0UN14RDU\0"},	//(R0UN14RDU) Максимальная координата штока ИС, мм
	{847,"fEM_R0UN15RDU\0"},	//(R0UN15RDU) Минимальная координата штока ББ, мм
	{848,"fEM_R0UN16RDU\0"},	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
	{849,"fEM_R0UN17RDU\0"},	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
	{850,"fEM_R0UN18RDU\0"},	//(R0UN18RDU) Коэффициент температурной корректировки реактивности(долл)
	{851,"fEM_R0UN19RDU\0"},	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
	{852,"fEM_R0UN70LDU\0"},	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
	{853,"fEM_R0UN71LDU\0"},	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
	{854,"fEM_R0UN72LDU\0"},	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
	{855,"fEM_R0UN73LDU\0"},	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
	{856,"fEM_R0UN74LDU\0"},	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
	{857,"fEM_R0UN75LDU\0"},	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
	{858,"fEM_R0UN80LDU\0"},	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
	{859,"fEM_R0UN80RDU\0"},	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
	{860,"fEM_R0UN81LDU\0"},	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
	{861,"fEM_R0UN82LDU\0"},	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
	{862,"fEM_R0UN83LDU\0"},	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
	{863,"fEM_R0UN84LDU\0"},	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
	{864,"fEM_R0UN85LDU\0"},	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
	{865,"fEM_R0UT20RDU\0"},	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
	{866,"fEM_R0UV81RDU\0"},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{867,"fEM_R0UV82RDU\0"},	//(R0UV82RDU) 2-я частота двигателя (шагов/секунду)
	{868,"fEM_R0UV83RDU\0"},	//(R0UV83RDU) 3-я частота двигателя (шагов/секунду)
	{869,"fEM_R0UV84RDU\0"},	//(R0UV84RDU) 4-я частота двигателя (шагов/секунду)
	{870,"fEM_R0UV85RDU\0"},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{871,"fEM_R0UV86RDU\0"},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{872,"fEM_R0UV87RDU\0"},	//(R0UV87RDU) 8-я скорость перемещения ББ (шагов/секунду)
	{873,"fEM_R1UZ03RDU\0"},	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
	{874,"fEM_R1UZ04RDU\0"},	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
	{875,"fEM_R1UZ05RDU\0"},	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
	{876,"fEM_R4UZ03RDU\0"},	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
	{877,"fEM_R4UZ04RDU\0"},	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
	{878,"fEM_R4UZ05RDU\0"},	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
	{879,"fEM_R7UI76RDU\0"},	//(R7UI76RDU) Время срабатывания сигнала II УР при имитации
	{880,"iEM_A1UV01IDU\0"},	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
	{881,"iEM_A1UV02IDU\0"},	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
	{882,"iEM_A1UV03IDU\0"},	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
	{883,"iEM_A2UV01IDU\0"},	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
	{884,"iEM_A2UV02IDU\0"},	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
	{885,"iEM_A2UV03CDU\0"},	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
	{886,"iEM_A3UV01IDU\0"},	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
	{887,"iEM_A3UV02IDU\0"},	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
	{1883,"lEM_R0MD01LC1\0"},	//(R0MD01LC1) Ручное управление ОРР
	{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_DU[]={
	{&B2MD12LP1,1,0},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
	{&B2MD11LP1,1,1},	//( - , DU) Кнопка ПУСК РБ2
	{&B1MD12LP1,1,2},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
	{&B1MD11LP1,1,3},	//( - , DU) Кнопка ПУСК ББ2
	{&R0MW17LP1,1,4},	//( - , DU) Переключатель АВТ/Р
	{&A1MD11LP1,1,5},	//( - , DU) Кнопка ПУСК ББ1
	{&A1MD12LP1,1,6},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
	{&R0MD33LP1,1,7},	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
	{&A3MD11LP1,1,8},	//( - , DU) Кнопка ПУСК ИС1
	{&A3MD12LP1,1,9},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
	{&A2MD11LP1,1,10},	//( - , DU) Кнопка ПУСК РБ1
	{&A2MD12LP1,1,11},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
	{&R0MD34LP1,1,12},	//( - , DU) Кнопка КВИТИРОВАТЬ
	{&B3MD12LP1,1,13},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
	{&B3MD11LP1,1,14},	//( - , DU) Кнопка ПУСК ИС2
	{&R0MD11LP2,1,15},	//( - , DU) Кнопка Пуск проверки схем сброса
	{&C1MD31LP2,1,16},	//( - , DU) Кнопка СБРОС ББ
	{&C1MD31LP1,1,17},	//( - , DU) Кнопка СБРОС ББ
	{&B9IS21LDU,1,18},	//( - K26VDSR, DU) Приход на НУ НИ ДС2
	{&A1MC01LC2,1,19},	//( - , DU) Настроить энкодер ББ1
	{&A1MC01LC1,1,20},	//( - , DU) Настроить энкодер ББ1
	{&B1MC01LC2,1,21},	//( - , DU) Настроить энкодер ББ2
	{&B1MC01LC1,1,22},	//( - , DU) Настроить энкодер ББ2
	{&B2MC01LC1,1,23},	//( - , DU) Настроить энкодер РБ2
	{&B2MC01LC2,1,24},	//( - , DU) Настроить энкодер РБ2
	{&A2MC01LC1,1,25},	//( - , DU) Настроить энкодер РБ1
	{&A2MC01LC2,1,26},	//( - , DU) Настроить энкодер РБ1
	{&B3MC01LC1,1,27},	//( - , DU) Настроить энкодер ИС2
	{&B3MC01LC2,1,28},	//( - , DU) Настроить энкодер ИС2
	{&A3MC01LC1,1,29},	//( - , DU) Настроить энкодер ИС1
	{&A3MC01LC2,1,30},	//( - , DU) Настроить энкодер ИС1
	{&B8MC01LC1,1,31},	//( - , DU) Настроить энкодер АЗ2
	{&B8MC01LC2,1,32},	//( - , DU) Настроить энкодер АЗ2
	{&A8MC01LC1,1,33},	//( - , DU) Настроить энкодер ДС2
	{&A8MC01LC2,1,34},	//( - , DU) Настроить энкодер ДС2
	{&C2MD31LP1,1,35},	//( - , DU) Кнопка СБРОС РБ
	{&R0MD11LP1,1,36},	//( - , DU) Кнопка ПУСК
	{&R4MD21LP2,1,37},	//( - , DU) Кнопка НАЗАД  (тележки)
	{&R4MD31LP2,1,38},	//( - , DU) Кнопка СТОП  (тележки)
	{&R4MD11LP2,1,39},	//( - , DU) Кнопка ВПЕРЁД  (тележки)
	{&R0MD31LP1,1,40},	//( - , DU) Кнопка СТОП
	{&R0MD32LP1,1,41},	//( - , DU) Кнопка СПУСК
	{&R0MW13LP2,1,42},	//( - , DU) Переключатель СЕТЬ
	{&R0NE01LDU,1,43},	//( - , DU) Потеря связи с БАЗ1
	{&R0NE02LDU,1,44},	//( - , DU) Потеря связи с БАЗ2
	{&R0NE08LDU,1,45},	//( - , DU) Потеря связи с ОПУ
	{&lEM_R0MD01LC1,1,46},	//( - , DU) Ручное управление ОРР
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DU[]={
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
	{&A9AB01LDU,1,18},	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
	{&A3VZ15LZ2,1,19},	//( - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{&A3VZ15LZ1,1,20},	//( - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{&A3VZ13LZ1,1,21},	//( - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{&A3VZ13LZ2,1,22},	//( - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{&R0AD14LZ2,1,23},	//( - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
	{&R0AD14LZ1,1,24},	//( - K20VDSR, DU) Имитация срабатывания АЗ от II УР
	{&A1AB19LDU,1,25},	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
	{&A1VN71LZ2,1,26},	//( - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{&A1VN71LZ1,1,27},	//( - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{&A4IS10LDU,1,28},	//( - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
	{&A3IS35LDU,1,29},	//( - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
	{&A3IS33LDU,1,30},	//( - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
	{&A3IS31LDU,1,31},	//( - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
	{&A2IS33LDU,1,32},	//( - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
	{&R0VZ71LDU,1,33},	//( - , DU) Обобщенный сигнал АЗ
	{&B3IS11LDU,1,34},	//( - K03VDSR, DU) Приход на ВУ ИС2
	{&A3IS11LDU,1,35},	//( - K01VDSR, DU) Приход на ВУ ИС1
	{&R0IS01LDU,1,36},	//( - K29VDSR, DU) Признак работы с имитатором
	{&R0IS02LDU,1,37},	//( - K30VDSR, DU) Разрешение ввода от имитатора
	{&R0VP73LDU,1,38},	//( - , DU) ПС давления для РУ
	{&B2VS11LDU,1,39},	//( - , DU) Движение РБ2 в сторону ВУ
	{&B2VS21LDU,1,40},	//( - , DU) Движение РБ2 в сторону НУ
	{&A7AS31LDU,1,41},	//( - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
	{&B7AS31LDU,1,42},	//( - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
	{&A7AZ03LDU,1,43},	//( - , DU) Несанкционированное включение обдува АЗ1
	{&B7AZ03LDU,1,44},	//( - , DU) Несанкционированное включение обдува АЗ2
	{&R0VX01LDU,1,45},	//( - , DU) ДО ИМПУЛЬСА
	{&B1AD31LDU,1,46},	//( - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
	{&A1AD31LDU,1,47},	//( - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
	{&B2AD31LDU,1,48},	//( - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
	{&A2AD31LDU,1,49},	//( - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
	{&B3AB20LDU,1,50},	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
	{&B3AB18LDU,1,51},	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
	{&B3AB17LDU,1,52},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
	{&B3AB16LDU,1,53},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
	{&B3AB14LDU,1,54},	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
	{&B3AB12LDU,1,55},	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{&B3AB11LDU,1,56},	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
	{&B3AB10LDU,1,57},	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
	{&B3AB09LDU,1,58},	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
	{&B3AB06LDU,1,59},	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
	{&B3AB05LDU,1,60},	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
	{&B3AB08LDU,1,61},	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
	{&B3AB07LDU,1,62},	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
	{&B3AZ03LDU,1,63},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
	{&B3VS22LDU,1,64},	//( - , DU) Движение ИС2 в сторону НУ
	{&B3AB01LDU,1,65},	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
	{&B3AB02LDU,1,66},	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
	{&B3AB04LDU,1,67},	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
	{&B3VS12LDU,1,68},	//( - , DU) Движение ИС2 в сторону ВУ
	{&A3AB20LDU,1,69},	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
	{&A3AB18LDU,1,70},	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
	{&A9AZ03LDU,1,71},	//( - , DU) Несанкционированное перемещение НИ ДС1
	{&B9IS11LDU,1,72},	//( - K25VDSR, DU) Приход на ВУ НИ ДС2
	{&A9IS21LDU,1,73},	//( - K24VDSR, DU) Приход на НУ НИ ДС1
	{&A9IS11LDU,1,74},	//( - K23VDSR, DU) Приход на ВУ НИ ДС1
	{&B4VS22LDU,1,75},	//( - , DU) Движение НИ2 в сторону НУ
	{&B4VS12LDU,1,76},	//( - , DU) Движение НИ2 в сторону ВУ
	{&A4VS22LDU,1,77},	//( - , DU) Движение НИ1 в сторону НУ
	{&A4VS12LDU,1,78},	//( - , DU) Движение НИ1 в сторону ВУ
	{&R0AB04LDU,1,79},	//( - , DU) Нарушение времени срабатывания верхней АС II УР
	{&R0AB06LDU,1,80},	//( - , DU) Нарушение времени задержки от ВУ РБ
	{&R0AB02LDU,1,81},	//( - , DU) Нарушение времени задержки ИНИ
	{&R0VX03LDU,1,82},	//( - , DU) Готовность 2 мин
	{&A1IS11LDU,1,83},	//( - K08VDSR, DU) Приход на ВУ ББ1
	{&B1IS11LDU,1,84},	//( - K08VDSR, DU) Приход на ВУ ББ2
	{&psb2,1,85},	//( - , DU) движение бб
	{&psb1,1,86},	//( - , DU) ру не готова
	{&TestDiagnDU,1,87},	//( - , DU) Неисправность от
	{&B3AB13LDU,1,88},	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
	{&A3AB13LDU,1,89},	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
	{&R3VS12LDU,1,90},	//( - , DU) Движение гомогенных дверей к открыты
	{&R3VS22LDU,1,91},	//( - , DU) Движение гомогенных дверей к закрыты
	{&R5VS12LDU,1,92},	//( - , DU) Движение ворот отстойной зоны к открыты
	{&R5VS22LDU,1,93},	//( - , DU) Движение ворот отстойной зоны к закрыты
	{&R5IS21LDU,1,94},	//( - K26VDSR, DU) Приход на НУ ворот отстойной зоны
	{&B3AB15LDU,1,95},	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
	{&B3EE03LDU,1,96},	//( - , DU) ВПИС ИС2
	{&A3EE03LDU,1,97},	//( - , DU) ВПИС ИС1
	{&B3AB19LDU,1,98},	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
	{&A3AB19LDU,1,99},	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
	{&R0VL23LDU,1,100},	//( - , DU) Конец программы 20мин
	{&R0VL22LDU,1,101},	//( - , DU) Конец программы 200сек
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
	{&B8IS21LDU,1,140},	//( - K20VDSR, DU) Приход на НУ1 АЗ2
	{&B8IS12LDU,1,141},	//( - K21VDSR, DU) Приход на ВУ2 АЗ2
	{&R0AB19LDU,1,142},	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
	{&R0AB20LDU,1,143},	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
	{&A3AB15LDU,1,144},	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
	{&R0AB18LDU,1,145},	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
	{&R0AB17LDU,1,146},	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
	{&R0AB16LDU,1,147},	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
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
	{&B1AB19LDU,1,164},	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
	{&B1IS12LDU,1,165},	//( - K07VDSR, DU) Магнит ББ2 зацеплен
	{&A2IS12LDU,1,166},	//( - K10VDSR, DU) Магнит РБ1 зацеплен
	{&A1IS12LDU,1,167},	//( - K07VDSR, DU) Магнит ББ1 зацеплен
	{&B5AB04LDU,1,168},	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
	{&A5AB04LDU,1,169},	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
	{&B4AB02LDU,1,170},	//( - , DU) Блокировка движения НИ2 - Нет перемещения
	{&B4AB01LDU,1,171},	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
	{&B4AZ03LDU,1,172},	//( - , DU) Несанкционированное перемещение НИ2
	{&A4AB02LDU,1,173},	//( - , DU) Блокировка движения НИ1 - Нет перемещения
	{&A4AB01LDU,1,174},	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
	{&A4AZ03LDU,1,175},	//( - , DU) Несанкционированное перемещение НИ1
	{&B4IS21LDU,1,176},	//( - K32VDSR, DU) Приход на НУ НИ2
	{&A4IS21LDU,1,177},	//( - K15VDSR, DU) Приход на НУ НИ1
	{&B5AB02LDU,1,178},	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
	{&B5AB01LDU,1,179},	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
	{&B5AZ03LDU,1,180},	//( - , DU) Несанкционированное перемещение НЛ2
	{&A5AB02LDU,1,181},	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
	{&A5AB01LDU,1,182},	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
	{&A5AZ03LDU,1,183},	//( - , DU) Несанкционированное перемещение НЛ1
	{&B5IS21LDU,1,184},	//( - K16VDSR, DU) Приход на НУ НЛ2
	{&B5IS11LDU,1,185},	//( - K15VDSR, DU) Приход на ВУ НЛ2
	{&A5IS21LDU,1,186},	//( - K12VDSR, DU) Приход на НУ НЛ1
	{&A5IS11LDU,1,187},	//( - K11VDSR, DU) Приход на ВУ НЛ1
	{&B5VS12LDU,1,188},	//( - K14VDSR, DU) Движение НЛ2 в сторону ВУ
	{&B5VS22LDU,1,189},	//( - K15VDSR, DU) Движение НЛ2 в сторону НУ
	{&A5VS12LDU,1,190},	//( - K11VDSR, DU) Движение НЛ1 в сторону ВУ
	{&A5VS22LDU,1,191},	//( - K12VDSR, DU) Движение НЛ1 в сторону НУ
	{&R4AD20LDU,1,192},	//( - K14FDSR, DU) Перемещение тележки назад
	{&R4AB18LDU,1,193},	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
	{&R4AB17LDU,1,194},	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
	{&R4AB16LDU,1,195},	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
	{&R5IS11LDU,1,196},	//( - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
	{&A8AB06LDU,1,197},	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
	{&A8VS12LDU,1,198},	//( - , DU) Движение ДС2 в сторону ВУ
	{&B8AB02LDU,1,199},	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
	{&B8AB14LDU,1,200},	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
	{&B8AB13LDU,1,201},	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
	{&B8AB12LDU,1,202},	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
	{&B8AB11LDU,1,203},	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
	{&B8AB10LDU,1,204},	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
	{&B8AB09LDU,1,205},	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
	{&B8AB08LDU,1,206},	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
	{&B8AB04LDU,1,207},	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
	{&B8AB01LDU,1,208},	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
	{&B8IS11LDU,1,209},	//( - K19VDSR, DU) Приход на ВУ1 АЗ2
	{&B8AZ03LDU,1,210},	//( - , DU) Несанкционированное перемещение АЗ2
	{&B2IS12LDU,1,211},	//( - K10VDSR, DU) Магнит РБ2 зацеплен
	{&R4IS11LDU,1,212},	//( - K05VDSR, DU) Приход на ВУ1 тележки
	{&A6AB06LDU,1,213},	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
	{&A6AB07LDU,1,214},	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
	{&A6AB08LDU,1,215},	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
	{&A6AB09LDU,1,216},	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
	{&B6AB06LDU,1,217},	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
	{&B6AB07LDU,1,218},	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
	{&B6AB08LDU,1,219},	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
	{&B6AB09LDU,1,220},	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
	{&A6AB05LDU,1,221},	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
	{&B8VS12LDU,1,222},	//( - , DU) Движение АЗ2 в сторону ВУ
	{&B8AB06LDU,1,223},	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
	{&B8AB07LDU,1,224},	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
	{&B8AB05LDU,1,225},	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
	{&B8VS22LDU,1,226},	//( - , DU) Движение АЗ2 в сторону НУ
	{&B6AZ03LDU,1,227},	//( - , DU) Несанкционированное перемещение БЗ2
	{&A6AB02LDU,1,228},	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
	{&A6AB01LDU,1,229},	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
	{&A6AZ03LDU,1,230},	//( - , DU) Несанкционированное перемещение БЗ1
	{&B6VS12LDU,1,231},	//( - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
	{&B6VS22LDU,1,232},	//( - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
	{&A6VS12LDU,1,233},	//( - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
	{&A6VS22LDU,1,234},	//( - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
	{&B6IS21LDU,1,235},	//( - K14VDSR, DU) Приход на НУ БЗ2
	{&B6IS11LDU,1,236},	//( - K13VDSR, DU) Приход на ВУ БЗ2
	{&A6IS21LDU,1,237},	//( - K10VDSR, DU) Приход на НУ БЗ1
	{&A6IS11LDU,1,238},	//( - K09VDSR, DU) Приход на ВУ БЗ1
	{&R0ES01LDU,1,239},	//( - , DU) ОРР не в исходном состоянии
	{&B3IS21LDU,1,240},	//( - K13VDSR, DU) Приход на НУ ИС2
	{&B2IS21LDU,1,241},	//( - K12VDSR, DU) Приход на НУ РБ2-СС
	{&B1IS21LDU,1,242},	//( - K09VDSR, DU) Приход на НУ ББ2
	{&A3IS21LDU,1,243},	//( - K13VDSR, DU) Приход на НУ ИС1
	{&A2IS21LDU,1,244},	//( - K12VDSR, DU) Приход на НУ РБ1-СС
	{&A1IS21LDU,1,245},	//( - K09VDSR, DU) Приход на НУ ББ1
	{&R4AB15LDU,1,246},	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
	{&R4AB14LDU,1,247},	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
	{&R4AB13LDU,1,248},	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
	{&B4IS11LDU,1,249},	//( - K31VDSR, DU) Приход на ВУ НИ2
	{&A4IS11LDU,1,250},	//( - K14VDSR, DU) Приход на ВУ НИ1
	{&R4AB12LDU,1,251},	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
	{&R4AB11LDU,1,252},	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
	{&R4AB10LDU,1,253},	//( - , DU) Блокировка тележки - не открыта биологическая защита
	{&R4AB09LDU,1,254},	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
	{&R4AB08LDU,1,255},	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
	{&R4AB07LDU,1,256},	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
	{&R4AB06LDU,1,257},	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
	{&R4AB05LDU,1,258},	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
	{&R4AB04LDU,1,259},	//( - , DU) Блокировка движения тележки - Превышение времени движения
	{&R2IS21LDU,1,260},	//( - K30VDSR, DU) Приход на НУ МДЗ2
	{&R1IS21LDU,1,261},	//( - K28VDSR, DU) Приход на НУ МДЗ1
	{&B6AB01LDU,1,262},	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
	{&B6AB02LDU,1,263},	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
	{&A6AB04LDU,1,264},	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
	{&B6AB04LDU,1,265},	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
	{&R4AB01LDU,1,266},	//( - , DU) Блокировка движения тележки - АНИ не установлен
	{&R8IS11LDU,1,267},	//( - K14VDSR, DU) Аварийный НИ установлен
	{&R4AB02LDU,1,268},	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
	{&R4IS21LDU,1,269},	//( - K07VDSR, DU) Приход на НУ1 тележки
	{&R4IS22LDU,1,270},	//( - K08VDSR, DU) Приход на НУ2 тележки
	{&R4IS12LDU,1,271},	//( - K06VDSR, DU) Приход на ВУ2 тележки
	{&R4VS22LDU,1,272},	//( - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
	{&R4VS12LDU,1,273},	//( - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
	{&R4AZ03LDU,1,274},	//( - , DU) Несанкционированное перемещение тележки
	{&R4AB03LDU,1,275},	//( - , DU) Блокировка движения тележки - Самоход любого механизма
	{&B1AZ03LDU,1,276},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
	{&B1VS22LDU,1,277},	//( - , DU) Движение ББ2 в сторону НУ
	{&B1AB01LDU,1,278},	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
	{&B1AB02LDU,1,279},	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
	{&B1AB04LDU,1,280},	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
	{&B1VS12LDU,1,281},	//( - , DU) Движение ББ2 в сторону ВУ
	{&A1AB18LDU,1,282},	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
	{&A1AB17LDU,1,283},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
	{&A1AB16LDU,1,284},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
	{&A1AB14LDU,1,285},	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
	{&A1AB13LDU,1,286},	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
	{&A1AB12LDU,1,287},	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&A1AB11LDU,1,288},	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
	{&A1AB10LDU,1,289},	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
	{&A1AB09LDU,1,290},	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
	{&A1AB06LDU,1,291},	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
	{&A1AB05LDU,1,292},	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
	{&A1AB08LDU,1,293},	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
	{&A1AB07LDU,1,294},	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
	{&A1AZ03LDU,1,295},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
	{&A1VS22LDU,1,296},	//( - , DU) Движение ББ1 в сторону НУ
	{&A1AB01LDU,1,297},	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
	{&A1AB02LDU,1,298},	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
	{&A1AB04LDU,1,299},	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
	{&A1VS12LDU,1,300},	//( - , DU) Движение ББ1 в сторону ВУ
	{&R2IS11LDU,1,301},	//( - K29VDSR, DU) Приход на ВУ МДЗ2
	{&R1VS12LDU,1,302},	//( - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
	{&R2VS12LDU,1,303},	//( - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
	{&R2VS22LDU,1,304},	//( - K09VDSR, DU) Движение МДЗ2 в сторону НУ
	{&A3AB17LDU,1,305},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
	{&A3AB16LDU,1,306},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
	{&A3AB14LDU,1,307},	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
	{&A3AB12LDU,1,308},	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&A3AB11LDU,1,309},	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
	{&A3AB10LDU,1,310},	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
	{&A3AB09LDU,1,311},	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
	{&A3AB06LDU,1,312},	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
	{&A3AB05LDU,1,313},	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
	{&A3AB08LDU,1,314},	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
	{&A3AB07LDU,1,315},	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
	{&A3AZ03LDU,1,316},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
	{&A3VS22LDU,1,317},	//( - , DU) Движение ИС1 в сторону НУ
	{&A3AB01LDU,1,318},	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
	{&A3AB02LDU,1,319},	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
	{&B1AB07LDU,1,320},	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
	{&B1AB08LDU,1,321},	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
	{&B1AB05LDU,1,322},	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
	{&B1AB06LDU,1,323},	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
	{&B1AB09LDU,1,324},	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
	{&B1AB10LDU,1,325},	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
	{&B1AB11LDU,1,326},	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
	{&B1AB12LDU,1,327},	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&B1AB13LDU,1,328},	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
	{&B1AB14LDU,1,329},	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
	{&B1AB16LDU,1,330},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
	{&B1AB17LDU,1,331},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
	{&B1AB18LDU,1,332},	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
	{&A3VS12LDU,1,333},	//( - , DU) Движение ИС1 в сторону ВУ
	{&A3AB04LDU,1,334},	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
	{&A2AB12LDU,1,335},	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&A2AB11LDU,1,336},	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
	{&A2AB10LDU,1,337},	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
	{&A2AB09LDU,1,338},	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
	{&A2AB06LDU,1,339},	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
	{&A2AB05LDU,1,340},	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
	{&A2AB08LDU,1,341},	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
	{&A2AB07LDU,1,342},	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
	{&A2AZ03LDU,1,343},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
	{&A2VS21LDU,1,344},	//( - , DU) Движение РБ1 в сторону НУ
	{&A2AB01LDU,1,345},	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
	{&A2AB02LDU,1,346},	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
	{&A2AB04LDU,1,347},	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
	{&A2VS11LDU,1,348},	//( - , DU) Движение РБ1 в сторону ВУ
	{&A8AB01LDU,1,349},	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
	{&A8AB02LDU,1,350},	//( - , DU) Блокировка движения ДС2- АНИ не установлен
	{&A8AB14LDU,1,351},	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
	{&A8AB13LDU,1,352},	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
	{&A8AB12LDU,1,353},	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
	{&A8AB11LDU,1,354},	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
	{&A8AB10LDU,1,355},	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
	{&A8AB09LDU,1,356},	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
	{&A8AB08LDU,1,357},	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
	{&A8IS22LDU,1,358},	//( - K31VDSR, DU) Приход на механический НУ ДС2
	{&A8AB04LDU,1,359},	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
	{&A8IS12LDU,1,360},	//( - K30VDSR, DU) Приход на механический ВУ ДС2
	{&B8IS22LDU,1,361},	//( - K22VDSR, DU) Приход на НУ2 АЗ2
	{&A8AZ03LDU,1,362},	//( - , DU) Несанкционированное перемещение ДС2
	{&A8VS22LDU,1,363},	//( - , DU) Движение ДС2 в сторону НУ
	{&A8AB05LDU,1,364},	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
	{&A8AB07LDU,1,365},	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
	{&R1VS22LDU,1,366},	//( - K06VDSR, DU) Движение МДЗ1 в сторону НУ
	{&R1IS11LDU,1,367},	//( - K27VDSR, DU) Приход на ВУ МДЗ1
	{&R2AB04LDU,1,368},	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
	{&R1AB04LDU,1,369},	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
	{&R2AB02LDU,1,370},	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
	{&R2AB01LDU,1,371},	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
	{&R2AZ03LDU,1,372},	//( - , DU) Несанкционированное перемещение МДЗ2
	{&R1AB02LDU,1,373},	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
	{&R1AB01LDU,1,374},	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
	{&R1AZ03LDU,1,375},	//( - , DU) Несанкционированное перемещение МДЗ1
	{&B2AB17LDU,1,376},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
	{&B2AB16LDU,1,377},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
	{&B2AB14LDU,1,378},	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
	{&B2AB13LDU,1,379},	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
	{&B2AB12LDU,1,380},	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{&B2AB11LDU,1,381},	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
	{&A2AB13LDU,1,382},	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
	{&A2AB14LDU,1,383},	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
	{&A2AB16LDU,1,384},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
	{&A2AB17LDU,1,385},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
	{&B2AB04LDU,1,386},	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
	{&B2AB02LDU,1,387},	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
	{&B2AB01LDU,1,388},	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
	{&B2AZ03LDU,1,389},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
	{&B2AB07LDU,1,390},	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
	{&B2AB08LDU,1,391},	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
	{&B2AB05LDU,1,392},	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
	{&B2AB06LDU,1,393},	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
	{&B2AB09LDU,1,394},	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
	{&B2AB10LDU,1,395},	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DU[]={
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
	{&R0VL06RDU,8,15},	//( - , DU) Индикация (Время задержки от ВУ РБ)
	{&R0VL02RDU,8,17},	//( - , DU) Индикация (Время задержки ИНИ)
	{&R0VL04RDU,8,19},	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
	{&R0VL03RDU,8,21},	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
	{&R0VL05RDU,8,23},	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
	{&R0VL21IDU,3,25},	//( - , DU) Декатрон
	{&R0VS21IDU,3,26},	//( - , DU) Индикация ВИД ПРОВЕРКИ
	{&A1VS01IDU,3,27},	//( - , DU) Готовность к управлению ББ1
	{&B1VS01IDU,3,28},	//( - , DU) Готовность к управлению ББ2
	{&A3VS01IDU,3,29},	//( - , DU) Готовность к управлению ИС1
	{&B3VS01IDU,3,30},	//( - , DU) Готовность к управлению ИС2
	{&A2VS01IDU,3,31},	//( - , DU) Готовность к управлению РБ1
	{&A4VS01IDU,3,32},	//( - , DU) Готовность к управлению НИ1
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
	{&R0CN95LDU,3,63},	//( - , DU) Этап 0 - не начинали, 54 - выход в 0 реакт, 59 - доводка, 55 - в зоне нечувст
	{&R0CN93LDU,8,64},	//( - , DU) время работы на мощности более 100Вт, сек
	{&R0VN12RDU,8,66},	//( - , DU) Заданная мощность РУ
	{&R0VN11RDU,8,68},	//( - , DU) Текущая мощность РУ
	{&A3MC03RDU,8,70},	//( - , DU) Координата положения ИМ 0-й реактивности
	{&R0CN91LDU,8,72},	//( - , DU) Рассчётная реактивность от регулятора
	{&A3MC02RDU,8,74},	//( - , DU) Температурная корректировка координаты ИМ
	{&A3MC01RDU,8,76},	//( - , DU) Заданная координата положения ИС от регулятора мм
	{&A8CV01RDU,8,78},	//( - , DU) Измеренная скорость перемещения ДС2
	{&B8CV01RDU,8,80},	//( - , DU) Измеренная скорость перемещения АЗ2
	{&B1CV01RDU,8,82},	//( - , DU) Измеренная скорость перемещения ББ2
	{&A1CV02RDU,8,84},	//( - , DU) Заданная скорость перемещения ББ1
	{&A1CV01RDU,8,86},	//( - , DU) Измеренная скорость перемещения ББ1
	{&A3CV02RDU,8,88},	//( - , DU) Заданная скорость перемещения ИС1
	{&B1CV02RDU,8,90},	//( - , DU) Заданная скорость перемещения ББ2
	{&A3CV01RDU,8,92},	//( - , DU) Измеренная скорость перемещения ИС1
	{&A2CV01RDU,8,94},	//( - , DU) Измеренная скорость перемещения РБ1
	{&A2CV02RDU,8,96},	//( - , DU) Заданная скорость перемещения РБ1
	{&B2CV01RDU,8,98},	//( - , DU) Измеренная скорость перемещения РБ2
	{&B2CV02RDU,8,100},	//( - , DU) Заданная скорость перемещения РБ2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DU[]={
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
	{&fEM_R0UN14RDU,8,283},	//( - , DU) Максимальная координата штока ИС, мм
	{&fEM_R0UN16RDU,8,285},	//( - , DU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
	{&fEM_R0UN17RDU,8,287},	//( - , DU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
	{&fEM_R0UN18RDU,8,289},	//( - , DU) Коэффициент температурной корректировки реактивности(долл)
	{&fEM_R0UN19RDU,8,291},	//( - , DU) Коэффициент t0 ф-ции температурной корректировки ИМ
	{&fEM_R0UN70LDU,8,293},	//( - , DU) 0 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_R0UN71LDU,8,295},	//( - , DU) 1 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_R0UN72LDU,8,297},	//( - , DU) 2 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_R0UN73LDU,8,299},	//( - , DU) 3 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_R0UN74LDU,8,301},	//( - , DU) 4 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_R0UN75LDU,8,303},	//( - , DU) 5 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_R0UN80LDU,8,305},	//( - , DU) 0 - Коэффициент  опережения старта ИМ
	{&fEM_R0UN81LDU,8,307},	//( - , DU) 1 - Коэффициент  опережения старта ИМ
	{&fEM_R0UN82LDU,8,309},	//( - , DU) 2 - Коэффициент  опережения старта ИМ
	{&fEM_R0UN83LDU,8,311},	//( - , DU) 3 - Коэффициент  опережения старта ИМ
	{&fEM_R0UN84LDU,8,313},	//( - , DU) 4 - Коэффициент  опережения старта ИМ
	{&fEM_R0UN85LDU,8,315},	//( - , DU) 5 - Коэффициент  опережения старта ИМ
	{&fEM_R0UT20RDU,8,317},	//( - , DU) Предельное время работы на мощности более 100 Вт, сек
	{&fEM_R0UL25RDU,8,319},	//( - , DU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{&fEM_R0UL01RSS,8,321},	//( - , DU) Шаг измерения периода (сек)
	{&fEM_R0UL02RSS,8,323},	//( - , DU) Tф-постоянная времени, с
	{&fEM_R0UN03RSS,8,325},	//( - , DU) нижняя граница мощности для индикации периода  (ватт)
	{&fEM_R7UI76RDU,8,327},	//( - , DU) Время срабатывания сигнала II УР при имитации
	{&fEM_R0UL00RDU,8,329},	//( - , DU) Время ожидания передачи  сигнала отключения сети
	{&fEM_R0UN15RDU,8,331},	//( - , DU) Минимальная координата штока ББ, мм
	{&fEM_A1UR01RDU,8,333},	//( - , DU) коэффициент реактивности от координаты ББ
	{&fEM_A3UR01RDU,8,335},	//( - , DU) коэффициент реактивности от координаты ИС
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_MDuS[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MDuS[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MDuS[]={
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
static ModbusRegister hr_MDuS[]={
	{NULL,0,0},
};
#pragma pop
static char MDuS_ip1[]={"192.168.10.60\0"};
static char MDuS_ip2[]={"192.168.10.160\0"};
#pragma pack(push,1)
static ModbusRegister coil_DiagnDU[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DiagnDU[]={
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
static ModbusRegister ir_DiagnDU[]={
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
static ModbusRegister hr_DiagnDU[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_MDuBz2[]={
	{&R0AD21LDU,1,0},	//( - , SBz2DU) Подключить защиту от II УР
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MDuBz2[]={
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
static ModbusRegister ir_MDuBz2[]={
	{&B0CT01IZ2,8,0},	//( - , Baz2, SBz2DU) Температура АЗ2-1
	{&R0VN11RZ2,8,2},	//( - , Baz2, SBz2DU) Средняя мощность по БАЗ2
	{&A0CT01IZ2,8,4},	//( - , Baz2, SBz2DU) Температура АЗ1-1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MDuBz2[]={
	{&B8VC01RDU,8,0},	//( - , SBz2DU, MBz2A1, MBz2A2, MBz2A3, MBz2A4) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
static char MDuBz2_ip1[]={"192.168.10.54\0"};
static char MDuBz2_ip2[]={"192.168.10.154\0"};
#pragma pack(push,1)
static ModbusRegister coil_MDuBz1[]={
	{&R0AD21LDU,1,0},	//( - , SBz1DU) Подключить защиту от II УР
	{&R0VW23LDU,1,1},	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,1,2},	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MDuBz1[]={
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
static ModbusRegister ir_MDuBz1[]={
	{&B0CT01IZ1,8,0},	//( - , Baz1, SBz1DU) Температура АЗ2-1
	{&R0VN11RZ1,8,2},	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
	{&A0CT01IZ1,8,4},	//( - , Baz1, SBz1DU) Температура АЗ1-1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MDuBz1[]={
	{&B8VC01RDU,8,0},	//( - , SBz1DU, MBz1A1, MBz1A2, MBz1A3, MBz1A4) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
static char MDuBz1_ip1[]={"192.168.10.52\0"};
static char MDuBz1_ip2[]={"192.168.10.152\0"};
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_DU[0],&di_DU[0],&ir_DU[0],&hr_DU[0],NULL,NULL,NULL,0},	//Общий слэйв
	{1,5005,&coil_MDuS[0],&di_MDuS[0],&ir_MDuS[0],&hr_MDuS[0],NULL,MDuS_ip1,MDuS_ip2,10},	//Мастер ДУ в SCM
	{0,5006,&coil_DiagnDU[0],&di_DiagnDU[0],&ir_DiagnDU[0],&hr_DiagnDU[0],NULL,NULL,NULL,0},	//Диагностика DU
	{1,5009,&coil_MDuBz2[0],&di_MDuBz2[0],&ir_MDuBz2[0],&hr_MDuBz2[0],NULL,MDuBz2_ip1,MDuBz2_ip2,100},	//Мастер ДУ в Баз2
	{1,5010,&coil_MDuBz1[0],&di_MDuBz1[0],&ir_MDuBz1[0],&hr_MDuBz1[0],NULL,MDuBz1_ip1,MDuBz1_ip2,100},	//Мастер ДУ в Баз1
	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS1607[104];	//FDS1607
static fds16r_inipar ini_FDS1607={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1607={0,0,&ini_FDS1607,buf_FDS1607,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1607[]={
	{&A2AD11LDU,1,0},
	{&A2AD21LDU,1,2},
	{&A2AD01LDU,1,4},
	{&A2AD02LDU,1,6},
	{&A2AD03LDU,1,8},
	{&A2AD04LDU,1,10},
	{&A2AD05LDU,1,12},
	{&B2AD11LDU,1,14},
	{&B2AD21LDU,1,16},
	{&B2AD01LDU,1,18},
	{&B2AD02LDU,1,20},
	{&B2AD03LDU,1,22},
	{&B2AD04LDU,1,24},
	{&B2AD05LDU,1,26},
	{&R0S01LZ1,1,28},
	{&R0S01LZ2,1,30},
	{&R0DE07LDU,3,38},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS1608[104];	//FDS1608
static fds16r_inipar ini_FDS1608={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1608={0,0,&ini_FDS1608,buf_FDS1608,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1608[]={
	{&A1AD11LDU,1,0},
	{&A1AD21LDU,1,2},
	{&A1AD01LDU,1,4},
	{&A1AD02LDU,1,6},
	{&A1AD03LDU,1,8},
	{&A1AD04LDU,1,10},
	{&A1AD05LDU,1,12},
	{&B1AD11LDU,1,14},
	{&B1AD21LDU,1,16},
	{&B1AD01LDU,1,18},
	{&B1AD02LDU,1,20},
	{&B1AD03LDU,1,22},
	{&B1AD04LDU,1,24},
	{&B1AD05LDU,1,26},
	{&R0S01LIM,1,28},
	{&R0DE08LDU,3,38},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS1609[104];	//FDS1609
static fds16r_inipar ini_FDS1609={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1609={0,0,&ini_FDS1609,buf_FDS1609,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1609[]={
	{&B3AD34LDU,1,0},
	{&B3AD33LDU,1,2},
	{&B2AD33LDU,1,4},
	{&B4AD10LDU,1,6},
	{&B3AD31LDU,1,8},
	{&B7AP31LDU,1,10},
	{&A8AD10LDU,1,12},
	{&A8AD20LDU,1,14},
	{&A6AD10LDU,1,16},
	{&A6AD20LDU,1,18},
	{&B6AD10LDU,1,20},
	{&B6AD20LDU,1,22},
	{&R4AD10LDU,1,24},
	{&R4AD20LDU,1,26},
	{&B8AD10LDU,1,28},
	{&B8AD20LDU,1,30},
	{&R0DE09LDU,3,38},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS1610[104];	//FDS1610
static fds16r_inipar ini_FDS1610={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1610={0,0,&ini_FDS1610,buf_FDS1610,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1610[]={
	{&A3AD34LDU,1,0},
	{&A3AD33LDU,1,2},
	{&A2AD33LDU,1,4},
	{&A4AD10LDU,1,6},
	{&A3AD31LDU,1,8},
	{&A7AP31LDU,1,10},
	{&R1AD10LDU,1,12},
	{&R1AD20LDU,1,14},
	{&R2AD10LDU,1,16},
	{&R2AD20LDU,1,18},
	{&A5AD10LDU,1,20},
	{&A5AD20LDU,1,22},
	{&B5AD10LDU,1,24},
	{&B5AD20LDU,1,26},
	{&R0DE0ALDU,3,38},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS1611[104];	//FDS1611
static fds16r_inipar ini_FDS1611={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1611={0,0,&ini_FDS1611,buf_FDS1611,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1611[]={
	{&A3AD11LDU,1,0},
	{&A3AD21LDU,1,2},
	{&A3AD01LDU,1,4},
	{&A3AD02LDU,1,6},
	{&A3AD03LDU,1,8},
	{&A3AD04LDU,1,10},
	{&A3AD05LDU,1,12},
	{&B3AD11LDU,1,14},
	{&B3AD21LDU,1,16},
	{&B3AD01LDU,1,18},
	{&B3AD02LDU,1,20},
	{&B3AD03LDU,1,22},
	{&B3AD04LDU,1,24},
	{&B3AD05LDU,1,26},
	{&A9AD10LDU,1,28},
	{&B9AD10LDU,1,30},
	{&R0DE0BLDU,3,38},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS1615[104];	//FDS1615
static fds16r_inipar ini_FDS1615={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1615={0,0,&ini_FDS1615,buf_FDS1615,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1615[]={
	{&A1AD32LDU,1,0},
	{&A1AD31LDU,1,2},
	{&A2AD32LDU,1,4},
	{&A2AD31LDU,1,6},
	{&B1AD32LDU,1,8},
	{&B1AD31LDU,1,10},
	{&B2AD32LDU,1,12},
	{&B2AD31LDU,1,14},
	{&R0AD03LZ1,1,16},
	{&R0AD04LZ1,1,18},
	{&R0AD05LZ1,1,20},
	{&R8AD21LDU,1,22},
	{&R0AD16LDU,1,24},
	{&R0AD03LZ2,1,26},
	{&R0AD04LZ2,1,28},
	{&R0AD05LZ2,1,30},
	{&R0DE0FLDU,3,38},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/sbkfp7.h>
static char buf_SBKFP[90];	//SBKFP
static sbk_inipar ini_SBKFP={0xcc,0xff,8,8,0,0,0,};
#pragma pack(push,1)
static table_drv table_SBKFP={0,0,&ini_SBKFP,buf_SBKFP,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_SBKFP[]={
	{&R0DEB1LDU,1,18},
	{&R0DEB2LDU,1,20},
	{&R0DEB3LDU,1,22},
	{&R0DEB4LDU,1,24},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vas84r.h>
static char buf_VAS8412[64];	//VAS8412
static vas84r_inipar ini_VAS8412={0xc6,255,1,8,0xff,0,16,0,0,0,};
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
static char buf_VDS3202[194];	//VDS3202
static vds32r_inipar ini_VDS3202={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3202={0,0,&ini_VDS3202,buf_VDS3202,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3202[]={
	{&B3IS35LDU,1,0},
	{&B3IS33LDU,1,2},
	{&B2IS33LDU,1,4},
	{&B4IS10LDU,1,6},
	{&B3IS31LDU,1,8},
	{&B7AS31LDU,1,10},
	{&B1IS12LDU,1,12},
	{&B1IS11LDU,1,14},
	{&B1IS21LDU,1,16},
	{&B2IS12LDU,1,18},
	{&B2IS11LDU,1,20},
	{&B2IS21LDU,1,22},
	{&B3IS21LDU,1,24},
	{&R8IS11LDU,1,26},
	{&R8AD22LDU,1,28},
	{&A3VZ13LZ1,1,34},
	{&A3VZ15LZ1,1,36},
	{&R0AD14LZ1,1,38},
	{&A1VN71LZ1,1,40},
	{&R0VZ71LZ1,1,42},
	{&A9IS11LDU,1,44},
	{&A9IS21LDU,1,46},
	{&B9IS11LDU,1,48},
	{&B9IS21LDU,1,50},
	{&R1IS11LDU,1,52},
	{&R1IS21LDU,1,54},
	{&R2IS11LDU,1,56},
	{&R2IS21LDU,1,58},
	{&B4IS11LDU,1,60},
	{&B4IS21LDU,1,62},
	{&R0DE02LDU,3,64},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3203[194];	//VDS3203
static vds32r_inipar ini_VDS3203={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3203={0,0,&ini_VDS3203,buf_VDS3203,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3203[]={
	{&A3IS35LDU,1,0},
	{&A3IS33LDU,1,2},
	{&A2IS33LDU,1,4},
	{&A4IS10LDU,1,6},
	{&A3IS31LDU,1,8},
	{&A7AS31LDU,1,10},
	{&A1IS12LDU,1,12},
	{&A1IS11LDU,1,14},
	{&A1IS21LDU,1,16},
	{&A2IS12LDU,1,18},
	{&A2IS11LDU,1,20},
	{&A2IS21LDU,1,22},
	{&A3IS21LDU,1,24},
	{&A4IS11LDU,1,26},
	{&A4IS21LDU,1,28},
	{&A3VZ13LZ2,1,34},
	{&A3VZ15LZ2,1,36},
	{&R0AD14LZ2,1,38},
	{&A1VN71LZ2,1,40},
	{&R0VZ71LZ2,1,42},
	{&R0IS01LDU,1,56},
	{&R0IS02LDU,1,58},
	{&R0DE03LDU,3,64},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3204[194];	//VDS3204
static vds32r_inipar ini_VDS3204={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3204={0,0,&ini_VDS3204,buf_VDS3204,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3204[]={
	{&A3IS11LDU,1,0},
	{&A3IS22LDU,1,2},
	{&B3IS11LDU,1,4},
	{&B3IS22LDU,1,6},
	{&R4IS11LDU,1,8},
	{&R4IS12LDU,1,10},
	{&R4IS21LDU,1,12},
	{&R4IS22LDU,1,14},
	{&A6IS11LDU,1,16},
	{&A6IS21LDU,1,18},
	{&A5IS11LDU,1,20},
	{&A5IS21LDU,1,22},
	{&B6IS11LDU,1,24},
	{&B6IS21LDU,1,26},
	{&B5IS11LDU,1,28},
	{&B5IS21LDU,1,30},
	{&R3IS11LDU,1,32},
	{&R3IS21LDU,1,34},
	{&B8IS11LDU,1,36},
	{&B8IS21LDU,1,38},
	{&B8IS12LDU,1,40},
	{&B8IS22LDU,1,42},
	{&R5IS11LDU,1,48},
	{&R5IS21LDU,1,50},
	{&R6IS21LDU,1,56},
	{&A8IS12LDU,1,58},
	{&A8IS22LDU,1,60},
	{&R0DE04LDU,3,64},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3205[194];	//VDS3205
static vds32r_inipar ini_VDS3205={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3205={0,0,&ini_VDS3205,buf_VDS3205,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3205[]={
	{&A1IE02LDU,1,0},
	{&A1IE01LDU,1,2},
	{&A1IE03LDU,1,4},
	{&A1IE04LDU,1,6},
	{&A2IE02LDU,1,8},
	{&A2IE01LDU,1,10},
	{&A2IE03LDU,1,12},
	{&A2IE04LDU,1,14},
	{&A3IE02LDU,1,16},
	{&A3IE01LDU,1,18},
	{&A3IE03LDU,1,20},
	{&A3IE04LDU,1,22},
	{&B1IE02LDU,1,24},
	{&B1IE01LDU,1,26},
	{&B1IE03LDU,1,28},
	{&B1IE04LDU,1,30},
	{&B2IE02LDU,1,32},
	{&B2IE01LDU,1,34},
	{&B2IE03LDU,1,36},
	{&B2IE04LDU,1,38},
	{&B3IE02LDU,1,40},
	{&B3IE01LDU,1,42},
	{&B3IE03LDU,1,44},
	{&B3IE04LDU,1,46},
	{&R6IS31LDU,1,48},
	{&R6IS32LDU,1,50},
	{&R6IS41LDU,1,52},
	{&R6IS42LDU,1,54},
	{&R6IS51LDU,1,56},
	{&R6IS52LDU,1,58},
	{&R0DE05LDU,3,64},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3213[194];	//VDS3213
static vds32r_inipar ini_VDS3213={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3213={0,0,&ini_VDS3213,buf_VDS3213,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3213[]={
	{&R6IS61LDU,1,0},
	{&R4VS12LDU,1,2},
	{&R4VS22LDU,1,4},
	{&A8IE01LDU,1,6},
	{&R1VS12LDU,1,8},
	{&R1VS22LDU,1,10},
	{&R1IE01LDU,1,12},
	{&R2VS12LDU,1,14},
	{&R2VS22LDU,1,16},
	{&R2IE01LDU,1,18},
	{&A5VS12LDU,1,20},
	{&A5VS22LDU,1,22},
	{&A5IE02LDU,1,24},
	{&B5VS12LDU,1,26},
	{&B5VS22LDU,1,28},
	{&B5IE01LDU,1,30},
	{&A6VS12LDU,1,32},
	{&A6VS22LDU,1,34},
	{&A6IE01LDU,1,36},
	{&B6VS12LDU,1,38},
	{&B6VS22LDU,1,40},
	{&B6IE01LDU,1,42},
	{&R0IE02LDU,1,44},
	{&R0IE01LDU,1,46},
	{&R0DE0DLDU,3,64},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vencf8l.h>
static char buf_VENCF[150];	//VENCF
static vencf8_inipar ini_VENCF={0xc2,0xff,0,0x6,0x96,0,};
#pragma pack(push,1)
static table_drv table_VENCF={0,0,&ini_VENCF,buf_VENCF,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VENCF[]={
	{&venc01,5,40},
	{&venc02,5,45},
	{&venc03,5,50},
	{&venc04,5,55},
	{&venc05,5,60},
	{&venc06,5,65},
	{&venc07,5,70},
	{&venc08,5,75},
	{&R0DE06LDU,3,80},
	{&R0DE01LDU,3,82},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0x96,0x07,23,104,def_buf_FDS1607,&table_FDS1607},	//FDS16-07
	{0x96,0x08,23,104,def_buf_FDS1608,&table_FDS1608},	//FDS16-08
	{0x96,0x09,23,104,def_buf_FDS1609,&table_FDS1609},	//FDS16-09
	{0x96,0x0a,23,104,def_buf_FDS1610,&table_FDS1610},	//FDS16-10
	{0x96,0x0b,23,104,def_buf_FDS1611,&table_FDS1611},	//FDS16-11
	{0x96,0x0f,23,104,def_buf_FDS1615,&table_FDS1615},	//FDS16-15
	{0xcc,0x20,7,90,def_buf_SBKFP,&table_SBKFP},	//SBKFP
	{0xc6,0x0c,10,64,def_buf_VAS8412,&table_VAS8412},	//VAS84-12
	{0xc2,0x02,19,194,def_buf_VDS3202,&table_VDS3202},	//VDS32-02
	{0xc2,0x03,19,194,def_buf_VDS3203,&table_VDS3203},	//VDS32-03
	{0xc2,0x04,19,194,def_buf_VDS3204,&table_VDS3204},	//VDS32-04
	{0xc2,0x05,19,194,def_buf_VDS3205,&table_VDS3205},	//VDS32-05
	{0xc2,0x0d,19,194,def_buf_VDS3213,&table_VDS3213},	//VDS32-13
	{0x02,0x01,6,150,def_buf_VENCF,&table_VENCF},	//VENCF
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){	//Инициализация переменных для хранения
	setAsInt(725,1024200);
	setAsInt(726,-200);
	setAsInt(727,1024200);
	setAsInt(728,-200);
	setAsInt(729,1689599);
	setAsInt(730,-200);
	setAsInt(731,1536200);
	setAsInt(732,-200);
	setAsFloat(733,0.000877);
	setAsFloat(734,0.00009765625);
	setAsFloat(735,0.04);
	setAsFloat(736,0.03);
	setAsFloat(737,0.006);
	setAsFloat(738,0.004);
	setAsFloat(739,30.0);
	setAsFloat(740,100.0);
	setAsFloat(741,110.0);
	setAsFloat(742,1.0);
	setAsFloat(743,1.50);
	setAsFloat(744,3);
	setAsFloat(745,3);
	setAsFloat(746,0.21);
	setAsFloat(747,0.4);
	setAsFloat(748,0.4);
	setAsFloat(749,0.002375);
	setAsFloat(750,0.00009765625);
	setAsFloat(751,0.05);
	setAsFloat(752,0.04);
	setAsFloat(753,0.01);
	setAsFloat(754,0.008);
	setAsFloat(755,20);
	setAsFloat(756,100);
	setAsFloat(757,100);
	setAsFloat(758,1);
	setAsFloat(759,1.50);
	setAsFloat(760,3);
	setAsFloat(761,3);
	setAsFloat(762,1.50);
	setAsFloat(763,0.4);
	setAsFloat(764,0.4);
	setAsFloat(765,0.001675);
	setAsFloat(766,0.00009765625);
	setAsFloat(767,0.04);
	setAsFloat(768,0.07);
	setAsFloat(769,0.01);
	setAsFloat(770,0.006);
	setAsFloat(771,159.99);
	setAsFloat(772,170);
	setAsFloat(773,170);
	setAsFloat(774,1);
	setAsFloat(775,1.50);
	setAsFloat(776,3);
	setAsFloat(777,2);
	setAsFloat(778,2.5);
	setAsFloat(779,0);
	setAsFloat(780,0.46);
	setAsFloat(781,0.49);
	setAsFloat(782,0.52);
	setAsFloat(783,0.55);
	setAsFloat(784,0.53);
	setAsFloat(785,0.56);
	setAsFloat(786,0.64);
	setAsFloat(787,0.67);
	setAsFloat(788,0.0096);
	setAsFloat(789,0.4);
	setAsFloat(790,0.4);
	setAsFloat(791,1.0);
	setAsFloat(792,16.0);
	setAsFloat(793,3.0);
	setAsFloat(794,1.0);
	setAsFloat(795,6.0);
	setAsFloat(796,0.50);
	setAsFloat(797,1.0);
	setAsFloat(798,60.0);
	setAsFloat(799,0.50);
	setAsFloat(800,0.0009765625);
	setAsFloat(801,1);
	setAsFloat(802,15);
	setAsFloat(803,0.50);
	setAsFloat(804,0.4);
	setAsFloat(805,0.6);
	setAsFloat(806,0.3);
	setAsFloat(807,2);
	setAsFloat(808,1);
	setAsFloat(809,1.50);
	setAsFloat(810,3);
	setAsFloat(811,2);
	setAsFloat(812,2.0);
	setAsFloat(813,120);
	setAsFloat(814,4);
	setAsFloat(815,4);
	setAsFloat(816,10.91);
	setAsFloat(817,0.1);
	setAsFloat(818,0.100);
	setAsFloat(819,0.5);
	setAsFloat(820,0.015);
	setAsFloat(821,2.0);
	setAsFloat(822,1.5);
	setAsFloat(823,2.0);
	setAsFloat(824,0.190);
	setAsFloat(825,2.0);
	setAsFloat(826,0.150);
	setAsFloat(827,0.045);
	setAsFloat(828,0.045);
	setAsFloat(829,0.045);
	setAsFloat(830,0.045);
	setAsFloat(831,0.045);
	setAsFloat(832,2.5);
	setAsFloat(833,0.190);
	setAsFloat(834,0.001);
	setAsFloat(835,0.05);
	setAsFloat(836,100);
	setAsFloat(837,0.05);
	setAsFloat(838,500.0);
	setAsFloat(839,1000);
	setAsFloat(840,2500);
	setAsFloat(841,5000);
	setAsFloat(842,10000);
	setAsFloat(843,30);
	setAsFloat(844,500);
	setAsFloat(845,0.02);
	setAsFloat(846,155.0);
	setAsFloat(847,2.0);
	setAsFloat(848,-141.03307);
	setAsFloat(849,71.40719);
	setAsFloat(850,-0.13679034);
	setAsFloat(851,24.93556615);
	setAsFloat(852,0.1268);
	setAsFloat(853,0.1567);
	setAsFloat(854,0.1858);
	setAsFloat(855,0.2066);
	setAsFloat(856,0.2646);
	setAsFloat(857,0.2995);
	setAsFloat(858,0.839554030);
	setAsFloat(859,10);
	setAsFloat(860,0.78859401);
	setAsFloat(861,0.765962);
	setAsFloat(862,0.67256403);
	setAsFloat(863,0.42476001);
	setAsFloat(864,0.25501999);
	setAsFloat(865,3600.0);
	setAsFloat(866,100);
	setAsFloat(867,200);
	setAsFloat(868,300);
	setAsFloat(869,400);
	setAsFloat(870,500);
	setAsFloat(871,600);
	setAsFloat(872,750);
	setAsFloat(873,1.0);
	setAsFloat(874,20.0);
	setAsFloat(875,1);
	setAsFloat(876,1);
	setAsFloat(877,360);
	setAsFloat(878,2);
	setAsFloat(879,0.08);
	setAsShort(880,1);
	setAsShort(881,4);
	setAsShort(882,4);
	setAsShort(883,1);
	setAsShort(884,4);
	setAsShort(885,4);
	setAsShort(886,4);
	setAsShort(887,4);
	setAsBool(1883,0);
	setAsBool(115,1);
	setAsBool(179,1);
	setAsBool(199,1);
	setAsBool(376,1);
	setAsBool(436,1);
	setAsBool(449,1);
	setAsBool(716,1);
	setAsBool(717,1);
	setAsBool(718,1);
}
int freebuff=0;
int delay=0;
void Scheme(void){}

void InitInternalParametr(void){}

void MainCycle(void){
	if ((getAsShort(idR0MW11IP1) == 2) || (getAsShort(idR0MW11IP1) == 3)) {
		if(delay++<(4000/20)) return;
		delay=delay>32000?32000:delay;
		freebuff = 0;
		Scheme();
	} else {
		delay=0;
		if (freebuff) return;
		freebuff = 1;
		memset(BUFFER, 0, SIZE_BUFFER);
		InitSetConst();
		if (SimulOn) initAllSimul(CodeSub, drivers, SimulIP, SimulPort);
		else initAllDrivers(drivers);
	}
}
#endif