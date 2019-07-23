#ifndef DU_H
#defile DU_H
// Подсистема  DU:DU
static char SimulOn=0;
static short CodeSub=2;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 //Время цикла мс
float takt,taktScheme=0,taktSS=0;
#define SIZE_BUFFER 16825
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
#define R0CN92LDU	BUFFER[1259]	// ( - , DU) Рассчётный коэффициент  опережения старта ИМ
#define idR0CN92LDU	555	// ( - , DU) Рассчётный коэффициент  опережения старта ИМ
#define R0CN93LDU	BUFFER[1264]	// ( - , DU) время работы на мощности более 100Вт, сек
#define idR0CN93LDU	556	// ( - , DU) время работы на мощности более 100Вт, сек
#define R0CN94LDU	BUFFER[1269]	// ( - , DU) Скорость изменения мощности
#define idR0CN94LDU	557	// ( - , DU) Скорость изменения мощности
#define R0CN95LDU	BUFFER[1274]	// ( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
#define idR0CN95LDU	558	// ( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
#define R0DE01LDU	BUFFER[1277]	// (vencf8l:01 - DiagnVDS, DiagnDU) диагностика модуля ДУ на 1 месте
#define idR0DE01LDU	559	// (vencf8l:01 - DiagnVDS, DiagnDU) диагностика модуля ДУ на 1 месте
#define R0DE02LDU	BUFFER[1280]	// (vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
#define idR0DE02LDU	560	// (vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
#define R0DE03LDU	BUFFER[1283]	// (vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
#define idR0DE03LDU	561	// (vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
#define R0DE04LDU	BUFFER[1286]	// (vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
#define idR0DE04LDU	562	// (vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
#define R0DE05LDU	BUFFER[1289]	// (vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
#define idR0DE05LDU	563	// (vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
#define R0DE06LDU	BUFFER[1292]	// (vencf8l:01 - DiagnFDS, DiagnDU) диагностика модуля ДУ на 6 месте
#define idR0DE06LDU	564	// (vencf8l:01 - DiagnFDS, DiagnDU) диагностика модуля ДУ на 6 месте
#define R0DE07LDU	BUFFER[1295]	// (fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
#define idR0DE07LDU	565	// (fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
#define R0DE08LDU	BUFFER[1298]	// (fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
#define idR0DE08LDU	566	// (fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
#define R0DE09LDU	BUFFER[1301]	// (fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
#define idR0DE09LDU	567	// (fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
#define R0DE0ALDU	BUFFER[1304]	// (fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
#define idR0DE0ALDU	568	// (fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
#define R0DE0BLDU	BUFFER[1307]	// (fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
#define idR0DE0BLDU	569	// (fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
#define R0DE0CLDU	BUFFER[1310]	// (vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
#define idR0DE0CLDU	570	// (vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
#define R0DE0DLDU	BUFFER[1313]	// (vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
#define idR0DE0DLDU	571	// (vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
#define R0DE0FLDU	BUFFER[1316]	// (fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
#define idR0DE0FLDU	572	// (fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
#define R0DE3CLDU	BUFFER[1319]	// ( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
#define idR0DE3CLDU	573	// ( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
#define R0DE3DLDU	BUFFER[1321]	// ( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
#define idR0DE3DLDU	574	// ( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
#define R0DEB1LDU	BUFFER[1323]	// (sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
#define idR0DEB1LDU	575	// (sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
#define R0DEB2LDU	BUFFER[1325]	// (sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
#define idR0DEB2LDU	576	// (sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
#define R0DEB3LDU	BUFFER[1327]	// (sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
#define idR0DEB3LDU	577	// (sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
#define R0DEB4LDU	BUFFER[1329]	// (sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
#define idR0DEB4LDU	578	// (sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
#define R0EE02LDU	BUFFER[1331]	// ( - , DU) Питание  АКНП  отключить
#define idR0EE02LDU	579	// ( - , DU) Питание  АКНП  отключить
#define R0EE03LDU	BUFFER[1333]	// ( - , DU) ВПИС ИС
#define idR0EE03LDU	580	// ( - , DU) ВПИС ИС
#define R0ES01LDU	BUFFER[1335]	// ( - , DU) ОРР не в исходном состоянии
#define idR0ES01LDU	581	// ( - , DU) ОРР не в исходном состоянии
#define R0IE01LDU	BUFFER[1337]	// (vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
#define idR0IE01LDU	582	// (vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
#define R0IE02LDU	BUFFER[1339]	// (vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
#define idR0IE02LDU	583	// (vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
#define R0IS01LDU	BUFFER[1341]	// (vds32:03 - K29VDSR, DU) Признак работы с имитатором
#define idR0IS01LDU	584	// (vds32:03 - K29VDSR, DU) Признак работы с имитатором
#define R0IS02LDU	BUFFER[1343]	// (vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
#define idR0IS02LDU	585	// (vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
#define R0MD11LP1	BUFFER[1345]	// ( - , DU) Кнопка ПУСК
#define idR0MD11LP1	586	// ( - , DU) Кнопка ПУСК
#define R0MD11LP2	BUFFER[1347]	// ( - , DU) Кнопка Пуск проверки схем сброса
#define idR0MD11LP2	587	// ( - , DU) Кнопка Пуск проверки схем сброса
#define R0MD31LP1	BUFFER[1349]	// ( - , DU) Кнопка СТОП
#define idR0MD31LP1	588	// ( - , DU) Кнопка СТОП
#define R0MD32LP1	BUFFER[1351]	// ( - , DU) Кнопка СПУСК
#define idR0MD32LP1	589	// ( - , DU) Кнопка СПУСК
#define R0MD33LP1	BUFFER[1353]	// ( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
#define idR0MD33LP1	590	// ( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
#define R0MD34LP1	BUFFER[1355]	// ( - , DU) Кнопка КВИТИРОВАТЬ
#define idR0MD34LP1	591	// ( - , DU) Кнопка КВИТИРОВАТЬ
#define R0MW11IP1	BUFFER[1357]	// ( - , DU) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	592	// ( - , DU) Переключатель ВЫСТРЕЛ
#define R0MW11IP2	BUFFER[1360]	// ( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
#define idR0MW11IP2	593	// ( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
#define R0MW12IP1	BUFFER[1363]	// ( - , DU) Переключатель РЕЖИМ РАБОТЫ
#define idR0MW12IP1	594	// ( - , DU) Переключатель РЕЖИМ РАБОТЫ
#define R0MW12IP2	BUFFER[1366]	// ( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define idR0MW12IP2	595	// ( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define R0MW13IP1	BUFFER[1369]	// ( - , DU) Переключатель ВЫБОР ЗОН
#define idR0MW13IP1	596	// ( - , DU) Переключатель ВЫБОР ЗОН
#define R0MW13LP2	BUFFER[1372]	// ( - , DU) Переключатель СЕТЬ
#define idR0MW13LP2	597	// ( - , DU) Переключатель СЕТЬ
#define R0MW14IP1	BUFFER[1374]	// ( - , DU) Переключатель ПРОГРАММЫ
#define idR0MW14IP1	598	// ( - , DU) Переключатель ПРОГРАММЫ
#define R0MW14IP2	BUFFER[1377]	// ( - , DU) Переключатель ОБДУВ
#define idR0MW14IP2	599	// ( - , DU) Переключатель ОБДУВ
#define R0MW15IP1	BUFFER[1380]	// ( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
#define idR0MW15IP1	600	// ( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
#define R0MW16IP1	BUFFER[1383]	// ( - , DU) Переключатель ВИД ПРОВЕРКИ
#define idR0MW16IP1	601	// ( - , DU) Переключатель ВИД ПРОВЕРКИ
#define R0MW17LP1	BUFFER[1386]	// ( - , DU) Переключатель АВТ/Р
#define idR0MW17LP1	602	// ( - , DU) Переключатель АВТ/Р
#define R0NE01LDU	BUFFER[1388]	// ( - , DU) Потеря связи с БАЗ1
#define idR0NE01LDU	603	// ( - , DU) Потеря связи с БАЗ1
#define R0NE02LDU	BUFFER[1390]	// ( - , DU) Потеря связи с БАЗ2
#define idR0NE02LDU	604	// ( - , DU) Потеря связи с БАЗ2
#define R0NE08LDU	BUFFER[1392]	// ( - , DU) Потеря связи с ОПУ
#define idR0NE08LDU	605	// ( - , DU) Потеря связи с ОПУ
#define R0S01LDU	BUFFER[1394]	// ( - , - ) Отключение сетевых передач ДУ
#define idR0S01LDU	606	// ( - , - ) Отключение сетевых передач ДУ
#define R0S01LIM	BUFFER[1396]	// (fds16:08 - K15FDSR, - ) Отключение сетевых передач ПТИ
#define idR0S01LIM	607	// (fds16:08 - K15FDSR, - ) Отключение сетевых передач ПТИ
#define R0S01LZ1	BUFFER[1398]	// (fds16:07 - K15FDSR, - ) Отключение сетевых передач в Баз1
#define idR0S01LZ1	608	// (fds16:07 - K15FDSR, - ) Отключение сетевых передач в Баз1
#define R0S01LZ2	BUFFER[1400]	// (fds16:07 - K16FDSR, - ) Отключение сетевых передач в Баз2
#define idR0S01LZ2	609	// (fds16:07 - K16FDSR, - ) Отключение сетевых передач в Баз2
#define R0VL01IDU	BUFFER[1402]	// ( - , DU) До импульса минут
#define idR0VL01IDU	610	// ( - , DU) До импульса минут
#define R0VL01RDU	BUFFER[1405]	// ( - , DU) Индикация Время задержки
#define idR0VL01RDU	611	// ( - , DU) Индикация Время задержки
#define R0VL02RDU	BUFFER[1410]	// ( - , DU) Индикация (Время задержки ИНИ)
#define idR0VL02RDU	612	// ( - , DU) Индикация (Время задержки ИНИ)
#define R0VL03RDU	BUFFER[1415]	// ( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define idR0VL03RDU	613	// ( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define R0VL04RDU	BUFFER[1420]	// ( - , DU) Индикация (Время срабатывания верхней АС II УР)
#define idR0VL04RDU	614	// ( - , DU) Индикация (Время срабатывания верхней АС II УР)
#define R0VL05RDU	BUFFER[1425]	// ( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
#define idR0VL05RDU	615	// ( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
#define R0VL06RDU	BUFFER[1430]	// ( - , DU) Индикация (Время задержки от ВУ РБ)
#define idR0VL06RDU	616	// ( - , DU) Индикация (Время задержки от ВУ РБ)
#define R0VL11IDU	BUFFER[1435]	// ( - , DU) До импульса секунд
#define idR0VL11IDU	617	// ( - , DU) До импульса секунд
#define R0VL21IDU	BUFFER[1438]	// ( - , DU) Декатрон
#define idR0VL21IDU	618	// ( - , DU) Декатрон
#define R0VL22LDU	BUFFER[1441]	// ( - , DU) Конец программы 200сек
#define idR0VL22LDU	619	// ( - , DU) Конец программы 200сек
#define R0VL23LDU	BUFFER[1443]	// ( - , DU) Конец программы 20мин
#define idR0VL23LDU	620	// ( - , DU) Конец программы 20мин
#define R0VN11RDU	BUFFER[1445]	// ( - , DU) Текущая мощность РУ
#define idR0VN11RDU	621	// ( - , DU) Текущая мощность РУ
#define R0VN11RZ1	BUFFER[1450]	// ( - , MDuBz1) Средняя мощность по BAZ1
#define idR0VN11RZ1	622	// ( - , MDuBz1) Средняя мощность по BAZ1
#define R0VN11RZ2	BUFFER[1455]	// ( - , MDuBz2) Средняя мощность по BAZ2
#define idR0VN11RZ2	623	// ( - , MDuBz2) Средняя мощность по BAZ2
#define R0VN12RDU	BUFFER[1460]	// ( - , DU) Заданная мощность РУ
#define idR0VN12RDU	624	// ( - , DU) Заданная мощность РУ
#define R0VN15RDU	BUFFER[1465]	// ( - , DU) Период разгона РУ
#define idR0VN15RDU	625	// ( - , DU) Период разгона РУ
#define R0VP73LDU	BUFFER[1470]	// ( - , DU) ПС давления для РУ
#define idR0VP73LDU	626	// ( - , DU) ПС давления для РУ
#define R0VP73LZ1	BUFFER[1472]	// ( - , MDuBz1) ПС давления для РУ
#define idR0VP73LZ1	627	// ( - , MDuBz1) ПС давления для РУ
#define R0VP73LZ2	BUFFER[1474]	// ( - , MDuBz2) ПС давления для РУ
#define idR0VP73LZ2	628	// ( - , MDuBz2) ПС давления для РУ
#define R0VS11LDU	BUFFER[1476]	// ( - , DU) РУ не готова к работе
#define idR0VS11LDU	629	// ( - , DU) РУ не готова к работе
#define R0VS17LDU	BUFFER[1478]	// ( - , DU) Индикация выбора АВТОМАТ
#define idR0VS17LDU	630	// ( - , DU) Индикация выбора АВТОМАТ
#define R0VS18LDU	BUFFER[1480]	// ( - , DU) Индикация  Проверка схем сброса
#define idR0VS18LDU	631	// ( - , DU) Индикация  Проверка схем сброса
#define R0VS21IDU	BUFFER[1482]	// ( - , DU) Индикация ВИД ПРОВЕРКИ
#define idR0VS21IDU	632	// ( - , DU) Индикация ВИД ПРОВЕРКИ
#define R0VW13LDU	BUFFER[1485]	// ( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
#define idR0VW13LDU	633	// ( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
#define R0VW23LDU	BUFFER[1487]	// ( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
#define idR0VW23LDU	634	// ( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
#define R0VX01LDU	BUFFER[1489]	// ( - , DU) ДО ИМПУЛЬСА
#define idR0VX01LDU	635	// ( - , DU) ДО ИМПУЛЬСА
#define R0VX02LDU	BUFFER[1491]	// ( - , DU) Импульс разрешен
#define idR0VX02LDU	636	// ( - , DU) Импульс разрешен
#define R0VX03LDU	BUFFER[1493]	// ( - , DU) Готовность 2 мин
#define idR0VX03LDU	637	// ( - , DU) Готовность 2 мин
#define R0VX08IDU	BUFFER[1495]	// ( - , DU) Индикация Режим
#define idR0VX08IDU	638	// ( - , DU) Индикация Режим
#define R0VX09LDU	BUFFER[1498]	// ( - , DU) Индикация регулятор мощности включен/отключен
#define idR0VX09LDU	639	// ( - , DU) Индикация регулятор мощности включен/отключен
#define R0VZ71LDU	BUFFER[1500]	// ( - , DU) Обобщенный сигнал АЗ
#define idR0VZ71LDU	640	// ( - , DU) Обобщенный сигнал АЗ
#define R0VZ71LZ1	BUFFER[1502]	// (vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
#define idR0VZ71LZ1	641	// (vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
#define R0VZ71LZ2	BUFFER[1504]	// (vds32:03 - K22VDSR, - ) Обобщенный сигнал АЗ 2 канала
#define idR0VZ71LZ2	642	// (vds32:03 - K22VDSR, - ) Обобщенный сигнал АЗ 2 канала
#define R1AB01LDU	BUFFER[1506]	// ( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
#define idR1AB01LDU	643	// ( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
#define R1AB02LDU	BUFFER[1508]	// ( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
#define idR1AB02LDU	644	// ( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
#define R1AB04LDU	BUFFER[1510]	// ( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
#define idR1AB04LDU	645	// ( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
#define R1AD10LDU	BUFFER[1512]	// (fds16:0a - K07FDSR, - ) Опустить МДЗ1
#define idR1AD10LDU	646	// (fds16:0a - K07FDSR, - ) Опустить МДЗ1
#define R1AD20LDU	BUFFER[1514]	// (fds16:0a - K08FDSR, - ) Поднять МДЗ1
#define idR1AD20LDU	647	// (fds16:0a - K08FDSR, - ) Поднять МДЗ1
#define R1AZ03LDU	BUFFER[1516]	// ( - , DU) Несанкционированное перемещение МДЗ1
#define idR1AZ03LDU	648	// ( - , DU) Несанкционированное перемещение МДЗ1
#define R1IE01LDU	BUFFER[1518]	// (vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
#define idR1IE01LDU	649	// (vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
#define R1IS11LDU	BUFFER[1520]	// (vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
#define idR1IS11LDU	650	// (vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
#define R1IS21LDU	BUFFER[1522]	// (vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
#define idR1IS21LDU	651	// (vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
#define R1VS01IDU	BUFFER[1524]	// ( - , DU) Готовность к управлению МДЗ1
#define idR1VS01IDU	652	// ( - , DU) Готовность к управлению МДЗ1
#define R1VS12LDU	BUFFER[1527]	// (vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	653	// (vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
#define R1VS22LDU	BUFFER[1529]	// (vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	654	// (vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
#define R2AB01LDU	BUFFER[1531]	// ( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
#define idR2AB01LDU	655	// ( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
#define R2AB02LDU	BUFFER[1533]	// ( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
#define idR2AB02LDU	656	// ( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
#define R2AB04LDU	BUFFER[1535]	// ( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
#define idR2AB04LDU	657	// ( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
#define R2AD10LDU	BUFFER[1537]	// (fds16:0a - K09FDSR, - ) Опустить МДЗ2
#define idR2AD10LDU	658	// (fds16:0a - K09FDSR, - ) Опустить МДЗ2
#define R2AD20LDU	BUFFER[1539]	// (fds16:0a - K10FDSR, - ) Поднять МДЗ2
#define idR2AD20LDU	659	// (fds16:0a - K10FDSR, - ) Поднять МДЗ2
#define R2AZ03LDU	BUFFER[1541]	// ( - , DU) Несанкционированное перемещение МДЗ2
#define idR2AZ03LDU	660	// ( - , DU) Несанкционированное перемещение МДЗ2
#define R2IE01LDU	BUFFER[1543]	// (vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
#define idR2IE01LDU	661	// (vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
#define R2IS11LDU	BUFFER[1545]	// (vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
#define idR2IS11LDU	662	// (vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
#define R2IS21LDU	BUFFER[1547]	// (vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
#define idR2IS21LDU	663	// (vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
#define R2VS01IDU	BUFFER[1549]	// ( - , DU) Готовность к управлению МДЗ2
#define idR2VS01IDU	664	// ( - , DU) Готовность к управлению МДЗ2
#define R2VS12LDU	BUFFER[1552]	// (vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	665	// (vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
#define R2VS22LDU	BUFFER[1554]	// (vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	666	// (vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
#define R2ZAV	BUFFER[1556]	// ( - , DU) 
#define idR2ZAV	667	// ( - , DU) 
#define R3IS11LDU	BUFFER[1558]	// (vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
#define idR3IS11LDU	668	// (vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
#define R3IS21LDU	BUFFER[1560]	// (vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
#define idR3IS21LDU	669	// (vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
#define R3VS01IDU	BUFFER[1562]	// ( - , DU) Готовность к управлению гомогенных дверей
#define idR3VS01IDU	670	// ( - , DU) Готовность к управлению гомогенных дверей
#define R3VS12LDU	BUFFER[1565]	// ( - , DU) Движение гомогенных дверей к открыты
#define idR3VS12LDU	671	// ( - , DU) Движение гомогенных дверей к открыты
#define R3VS22LDU	BUFFER[1567]	// ( - , DU) Движение гомогенных дверей к закрыты
#define idR3VS22LDU	672	// ( - , DU) Движение гомогенных дверей к закрыты
#define R4AB01LDU	BUFFER[1569]	// ( - , DU) Блокировка движения тележки - АНИ не установлен
#define idR4AB01LDU	673	// ( - , DU) Блокировка движения тележки - АНИ не установлен
#define R4AB02LDU	BUFFER[1571]	// ( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
#define idR4AB02LDU	674	// ( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
#define R4AB03LDU	BUFFER[1573]	// ( - , DU) Блокировка движения тележки - Самоход любого механизма
#define idR4AB03LDU	675	// ( - , DU) Блокировка движения тележки - Самоход любого механизма
#define R4AB04LDU	BUFFER[1575]	// ( - , DU) Блокировка движения тележки - Превышение времени движения
#define idR4AB04LDU	676	// ( - , DU) Блокировка движения тележки - Превышение времени движения
#define R4AB05LDU	BUFFER[1577]	// ( - , DU) Блокировка движения  тележки - Нет перемещения тележки
#define idR4AB05LDU	677	// ( - , DU) Блокировка движения  тележки - Нет перемещения тележки
#define R4AB06LDU	BUFFER[1579]	// ( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
#define idR4AB06LDU	678	// ( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
#define R4AB07LDU	BUFFER[1581]	// ( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
#define idR4AB07LDU	679	// ( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
#define R4AB08LDU	BUFFER[1583]	// ( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define idR4AB08LDU	680	// ( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define R4AB09LDU	BUFFER[1585]	// ( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
#define idR4AB09LDU	681	// ( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
#define R4AB10LDU	BUFFER[1587]	// ( - , DU) Блокировка тележки - не открыта биологическая защита
#define idR4AB10LDU	682	// ( - , DU) Блокировка тележки - не открыта биологическая защита
#define R4AB11LDU	BUFFER[1589]	// ( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
#define idR4AB11LDU	683	// ( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
#define R4AB12LDU	BUFFER[1591]	// ( - , DU) Блокировка движения тележки - НИ не в положении ВУ
#define idR4AB12LDU	684	// ( - , DU) Блокировка движения тележки - НИ не в положении ВУ
#define R4AB13LDU	BUFFER[1593]	// ( - , DU) Блокировка тележки - НЛ не в положении ВУ
#define idR4AB13LDU	685	// ( - , DU) Блокировка тележки - НЛ не в положении ВУ
#define R4AB14LDU	BUFFER[1595]	// ( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
#define idR4AB14LDU	686	// ( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
#define R4AB15LDU	BUFFER[1597]	// ( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
#define idR4AB15LDU	687	// ( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
#define R4AB16LDU	BUFFER[1599]	// ( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
#define idR4AB16LDU	688	// ( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
#define R4AB17LDU	BUFFER[1601]	// ( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define idR4AB17LDU	689	// ( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define R4AB18LDU	BUFFER[1603]	// ( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define idR4AB18LDU	690	// ( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define R4ABL	BUFFER[1605]	// ( - , DU) Блокировка тележки -
#define idR4ABL	691	// ( - , DU) Блокировка тележки -
#define R4AD10LDU	BUFFER[1607]	// (fds16:09 - K13FDSR, - ) Перемещение тележки вперед
#define idR4AD10LDU	692	// (fds16:09 - K13FDSR, - ) Перемещение тележки вперед
#define R4AD20LDU	BUFFER[1609]	// (fds16:09 - K14FDSR, DU) Перемещение тележки назад
#define idR4AD20LDU	693	// (fds16:09 - K14FDSR, DU) Перемещение тележки назад
#define R4AZ03LDU	BUFFER[1611]	// ( - , DU) Несанкционированное перемещение тележки
#define idR4AZ03LDU	694	// ( - , DU) Несанкционированное перемещение тележки
#define R4IS11LDU	BUFFER[1613]	// (vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
#define idR4IS11LDU	695	// (vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
#define R4IS12LDU	BUFFER[1615]	// (vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
#define idR4IS12LDU	696	// (vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
#define R4IS21LDU	BUFFER[1617]	// (vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
#define idR4IS21LDU	697	// (vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
#define R4IS22LDU	BUFFER[1619]	// (vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
#define idR4IS22LDU	698	// (vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
#define R4MD11LP2	BUFFER[1621]	// ( - , DU) Кнопка ВПЕРЁД  (тележки)
#define idR4MD11LP2	699	// ( - , DU) Кнопка ВПЕРЁД  (тележки)
#define R4MD21LP2	BUFFER[1623]	// ( - , DU) Кнопка НАЗАД  (тележки)
#define idR4MD21LP2	700	// ( - , DU) Кнопка НАЗАД  (тележки)
#define R4MD31LP2	BUFFER[1625]	// ( - , DU) Кнопка СТОП  (тележки)
#define idR4MD31LP2	701	// ( - , DU) Кнопка СТОП  (тележки)
#define R4VS01IDU	BUFFER[1627]	// ( - , DU) Готовность к управлению тележкой реактора
#define idR4VS01IDU	702	// ( - , DU) Готовность к управлению тележкой реактора
#define R4VS12LDU	BUFFER[1630]	// (vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
#define idR4VS12LDU	703	// (vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
#define R4VS22LDU	BUFFER[1632]	// (vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
#define idR4VS22LDU	704	// (vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
#define R5IS11LDU	BUFFER[1634]	// (vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	705	// (vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
#define R5IS21LDU	BUFFER[1636]	// (vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	706	// (vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
#define R5VS01IDU	BUFFER[1638]	// ( - , DU) Готовность к управлению ворот отстойной зоны
#define idR5VS01IDU	707	// ( - , DU) Готовность к управлению ворот отстойной зоны
#define R5VS12LDU	BUFFER[1641]	// ( - , DU) Движение ворот отстойной зоны к открыты
#define idR5VS12LDU	708	// ( - , DU) Движение ворот отстойной зоны к открыты
#define R5VS22LDU	BUFFER[1643]	// ( - , DU) Движение ворот отстойной зоны к закрыты
#define idR5VS22LDU	709	// ( - , DU) Движение ворот отстойной зоны к закрыты
#define R6IS21LDU	BUFFER[1645]	// (vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
#define idR6IS21LDU	710	// (vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
#define R6IS31LDU	BUFFER[1647]	// (vds32:05 - K25VDSR, - ) контроль задней двери ШС
#define idR6IS31LDU	711	// (vds32:05 - K25VDSR, - ) контроль задней двери ШС
#define R6IS32LDU	BUFFER[1649]	// (vds32:05 - K26VDSR, - ) контроль передней двери ШС
#define idR6IS32LDU	712	// (vds32:05 - K26VDSR, - ) контроль передней двери ШС
#define R6IS41LDU	BUFFER[1651]	// (vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
#define idR6IS41LDU	713	// (vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
#define R6IS42LDU	BUFFER[1653]	// (vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
#define idR6IS42LDU	714	// (vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
#define R6IS51LDU	BUFFER[1655]	// (vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
#define idR6IS51LDU	715	// (vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
#define R6IS52LDU	BUFFER[1657]	// (vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
#define idR6IS52LDU	716	// (vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
#define R6IS61LDU	BUFFER[1659]	// (vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
#define idR6IS61LDU	717	// (vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
#define R6IS66LZZ	BUFFER[1661]	// ( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	718	// ( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	BUFFER[1663]	// ( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	719	// ( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	BUFFER[1665]	// ( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	720	// ( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define R8AD21LDU	BUFFER[1667]	// (fds16:0f - K12FDSR, - ) Запуск системы инициирования
#define idR8AD21LDU	721	// (fds16:0f - K12FDSR, - ) Запуск системы инициирования
#define R8AD22LDU	BUFFER[1669]	// (vds32:02 - K15VDSR, - ) Сигнал синхронизации с импульсом
#define idR8AD22LDU	722	// (vds32:02 - K15VDSR, - ) Сигнал синхронизации с импульсом
#define R8IS11LDU	BUFFER[1671]	// (vds32:02 - K14VDSR, DU) Аварийный НИ установлен
#define idR8IS11LDU	723	// (vds32:02 - K14VDSR, DU) Аварийный НИ установлен
#define TTLDU	BUFFER[1673]	// ( - , DU) ttl
#define idTTLDU	724	// ( - , DU) ttl
#define TestDiagnDU	BUFFER[1676]	// ( - , DU) Неисправность от
#define idTestDiagnDU	725	// ( - , DU) Неисправность от
#define bFirstEnterFlag	BUFFER[1678]	// (bFirstEnterFlag) 
#define idbFirstEnterFlag	726	// (bFirstEnterFlag) 
#define dEM_A1UC05UDU	BUFFER[1680]	// (A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC05UDU	727	// (A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define dEM_A1UC06UDU	BUFFER[1685]	// (A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC06UDU	728	// (A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define dEM_A2UC05UDU	BUFFER[1690]	// (A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC05UDU	729	// (A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define dEM_A2UC06UDU	BUFFER[1695]	// (A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC06UDU	730	// (A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define dEM_A3UC05UDU	BUFFER[1700]	// (A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC05UDU	731	// (A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define dEM_A3UC06UDU	BUFFER[1705]	// (A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC06UDU	732	// (A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define dEM_A8UC05UDU	BUFFER[1710]	// (A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define iddEM_A8UC05UDU	733	// (A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define dEM_A8UC06UDU	BUFFER[1715]	// (A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define iddEM_A8UC06UDU	734	// (A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define fEM_A1UC02RDU	BUFFER[1720]	// (A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define idfEM_A1UC02RDU	735	// (A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define fEM_A1UC03RDU	BUFFER[1725]	// (A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define idfEM_A1UC03RDU	736	// (A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define fEM_A1UC05RDU	BUFFER[1730]	// (A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A1UC05RDU	737	// (A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A1UC06RDU	BUFFER[1735]	// (A1UC06RDU) Уставка определения самохода ББ  мм
#define idfEM_A1UC06RDU	738	// (A1UC06RDU) Уставка определения самохода ББ  мм
#define fEM_A1UC07RDU	BUFFER[1740]	// (A1UC07RDU) Зона возврата при наведении ББ мм
#define idfEM_A1UC07RDU	739	// (A1UC07RDU) Зона возврата при наведении ББ мм
#define fEM_A1UC08RDU	BUFFER[1745]	// (A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define idfEM_A1UC08RDU	740	// (A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define fEM_A1UC81RDU	BUFFER[1750]	// (A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC81RDU	741	// (A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define fEM_A1UC82RDU	BUFFER[1755]	// (A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC82RDU	742	// (A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define fEM_A1UC83RDU	BUFFER[1760]	// (A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define idfEM_A1UC83RDU	743	// (A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define fEM_A1UL01RDU	BUFFER[1765]	// (A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A1UL01RDU	744	// (A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A1UL03RDU	BUFFER[1770]	// (A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define idfEM_A1UL03RDU	745	// (A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define fEM_A1UL04RDU	BUFFER[1775]	// (A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define idfEM_A1UL04RDU	746	// (A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define fEM_A1UL05RDU	BUFFER[1780]	// (A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define idfEM_A1UL05RDU	747	// (A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define fEM_A1UV01RDU	BUFFER[1785]	// (A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define idfEM_A1UV01RDU	748	// (A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define fEM_A1UV02RDU	BUFFER[1790]	// (A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define idfEM_A1UV02RDU	749	// (A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define fEM_A2UC02RDU	BUFFER[1795]	// (A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define idfEM_A2UC02RDU	750	// (A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define fEM_A2UC03RDU	BUFFER[1800]	// (A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define idfEM_A2UC03RDU	751	// (A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define fEM_A2UC05RDU	BUFFER[1805]	// (A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A2UC05RDU	752	// (A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A2UC06RDU	BUFFER[1810]	// (A2UC06RDU) Уставка определения самохода РБ  мм
#define idfEM_A2UC06RDU	753	// (A2UC06RDU) Уставка определения самохода РБ  мм
#define fEM_A2UC07RDU	BUFFER[1815]	// (A2UC07RDU) Зона возврата при наведении РБ  мм
#define idfEM_A2UC07RDU	754	// (A2UC07RDU) Зона возврата при наведении РБ  мм
#define fEM_A2UC08RDU	BUFFER[1820]	// (A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define idfEM_A2UC08RDU	755	// (A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define fEM_A2UC81RDU	BUFFER[1825]	// (A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC81RDU	756	// (A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define fEM_A2UC82RDU	BUFFER[1830]	// (A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC82RDU	757	// (A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define fEM_A2UC83RDU	BUFFER[1835]	// (A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define idfEM_A2UC83RDU	758	// (A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define fEM_A2UL01RDU	BUFFER[1840]	// (A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A2UL01RDU	759	// (A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A2UL03RDU	BUFFER[1845]	// (A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL03RDU	760	// (A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A2UL04RDU	BUFFER[1850]	// (A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define idfEM_A2UL04RDU	761	// (A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define fEM_A2UL05RDU	BUFFER[1855]	// (A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define idfEM_A2UL05RDU	762	// (A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define fEM_A2UL83RDU	BUFFER[1860]	// (A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL83RDU	763	// (A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A2UV01RDU	BUFFER[1865]	// (A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define idfEM_A2UV01RDU	764	// (A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define fEM_A2UV02RDU	BUFFER[1870]	// (A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define idfEM_A2UV02RDU	765	// (A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define fEM_A3UC02RDU	BUFFER[1875]	// (A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define idfEM_A3UC02RDU	766	// (A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define fEM_A3UC03RDU	BUFFER[1880]	// (A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define idfEM_A3UC03RDU	767	// (A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define fEM_A3UC05RDU	BUFFER[1885]	// (A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A3UC05RDU	768	// (A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define fEM_A3UC06RDU	BUFFER[1890]	// (A3UC06RDU) Уставка определения самохода ИС1  мм
#define idfEM_A3UC06RDU	769	// (A3UC06RDU) Уставка определения самохода ИС1  мм
#define fEM_A3UC07RDU	BUFFER[1895]	// (A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define idfEM_A3UC07RDU	770	// (A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define fEM_A3UC08RDU	BUFFER[1900]	// (A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define idfEM_A3UC08RDU	771	// (A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define fEM_A3UC09RDU	BUFFER[1905]	// (A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC09RDU	772	// (A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define fEM_A3UC81RDU	BUFFER[1910]	// (A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define idfEM_A3UC81RDU	773	// (A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define fEM_A3UC82RDU	BUFFER[1915]	// (A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define idfEM_A3UC82RDU	774	// (A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define fEM_A3UL01RDU	BUFFER[1920]	// (A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A3UL01RDU	775	// (A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A3UL03RDU	BUFFER[1925]	// (A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define idfEM_A3UL03RDU	776	// (A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define fEM_A3UL04RDU	BUFFER[1930]	// (A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define idfEM_A3UL04RDU	777	// (A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define fEM_A3UL05RDU	BUFFER[1935]	// (A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define idfEM_A3UL05RDU	778	// (A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define fEM_A3UP03RDU	BUFFER[1940]	// (A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	779	// (A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	BUFFER[1945]	// (A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	780	// (A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP43RDU	BUFFER[1950]	// (A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define idfEM_A3UP43RDU	781	// (A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define fEM_A3UP44RDU	BUFFER[1955]	// (A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP44RDU	782	// (A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP53RDU	BUFFER[1960]	// (A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP53RDU	783	// (A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP54RDU	BUFFER[1965]	// (A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define idfEM_A3UP54RDU	784	// (A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define fEM_A3UP85RDU	BUFFER[1970]	// (A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP85RDU	785	// (A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP86RDU	BUFFER[1975]	// (A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP86RDU	786	// (A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP87RDU	BUFFER[1980]	// (A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP87RDU	787	// (A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP88RDU	BUFFER[1985]	// (A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP88RDU	788	// (A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
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
#define fEM_R0UN03RSS	BUFFER[2230]	// (R0UN03RSS) нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN03RSS	837	// (R0UN03RSS) нижняя граница интервала мощности для измерения периода (ватт)
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
#define fEM_R0UN13RDU	BUFFER[2275]	// (R0UN13RDU) Минимальное изменение координаты, мм
#define idfEM_R0UN13RDU	846	// (R0UN13RDU) Минимальное изменение координаты, мм
#define fEM_R0UN14RDU	BUFFER[2280]	// (R0UN14RDU) Максимальная координата штока ИМ, мм
#define idfEM_R0UN14RDU	847	// (R0UN14RDU) Максимальная координата штока ИМ, мм
#define fEM_R0UN15RDU	BUFFER[2285]	// (R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
#define idfEM_R0UN15RDU	848	// (R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
#define fEM_R0UN16RDU	BUFFER[2290]	// (R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN16RDU	849	// (R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN17RDU	BUFFER[2295]	// (R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN17RDU	850	// (R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN18RDU	BUFFER[2300]	// (R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
#define idfEM_R0UN18RDU	851	// (R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
#define fEM_R0UN19RDU	BUFFER[2305]	// (R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define idfEM_R0UN19RDU	852	// (R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define fEM_R0UN24RDU	BUFFER[2310]	// (R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN24RDU	853	// (R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
#define fEM_R0UN25RDU	BUFFER[2315]	// (R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
#define idfEM_R0UN25RDU	854	// (R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
#define fEM_R0UN26RDU	BUFFER[2320]	// (R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
#define idfEM_R0UN26RDU	855	// (R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
#define fEM_R0UN27RDU	BUFFER[2325]	// (R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
#define idfEM_R0UN27RDU	856	// (R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
#define fEM_R0UN70LDU	BUFFER[2330]	// (R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN70LDU	857	// (R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN71LDU	BUFFER[2335]	// (R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN71LDU	858	// (R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN72LDU	BUFFER[2340]	// (R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN72LDU	859	// (R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN73LDU	BUFFER[2345]	// (R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN73LDU	860	// (R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN74LDU	BUFFER[2350]	// (R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN74LDU	861	// (R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN75LDU	BUFFER[2355]	// (R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN75LDU	862	// (R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN80LDU	BUFFER[2360]	// (R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN80LDU	863	// (R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define fEM_R0UN80RDU	BUFFER[2365]	// (R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define idfEM_R0UN80RDU	864	// (R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define fEM_R0UN81LDU	BUFFER[2370]	// (R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN81LDU	865	// (R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define fEM_R0UN82LDU	BUFFER[2375]	// (R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN82LDU	866	// (R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define fEM_R0UN83LDU	BUFFER[2380]	// (R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN83LDU	867	// (R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define fEM_R0UN84LDU	BUFFER[2385]	// (R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN84LDU	868	// (R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define fEM_R0UN85LDU	BUFFER[2390]	// (R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN85LDU	869	// (R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define fEM_R0UT20RDU	BUFFER[2395]	// (R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define idfEM_R0UT20RDU	870	// (R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define fEM_R0UV81RDU	BUFFER[2400]	// (R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	871	// (R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	BUFFER[2405]	// (R0UV82RDU) 2-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	872	// (R0UV82RDU) 2-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	BUFFER[2410]	// (R0UV83RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	873	// (R0UV83RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	BUFFER[2415]	// (R0UV84RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	874	// (R0UV84RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV85RDU	BUFFER[2420]	// (R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	875	// (R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV86RDU	BUFFER[2425]	// (R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	876	// (R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV87RDU	BUFFER[2430]	// (R0UV87RDU) 8-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	877	// (R0UV87RDU) 8-я скорость перемещения ББ (шагов/секунду)
#define fEM_R1UZ03RDU	BUFFER[2435]	// (R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define idfEM_R1UZ03RDU	878	// (R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define fEM_R1UZ04RDU	BUFFER[2440]	// (R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define idfEM_R1UZ04RDU	879	// (R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define fEM_R1UZ05RDU	BUFFER[2445]	// (R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define idfEM_R1UZ05RDU	880	// (R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define fEM_R4UZ03RDU	BUFFER[2450]	// (R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define idfEM_R4UZ03RDU	881	// (R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define fEM_R4UZ04RDU	BUFFER[2455]	// (R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define idfEM_R4UZ04RDU	882	// (R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define fEM_R4UZ05RDU	BUFFER[2460]	// (R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define idfEM_R4UZ05RDU	883	// (R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define fEM_R7UI76RDU	BUFFER[2465]	// (R7UI76RDU) Время срабатывания сигнала II УР при имитации
#define idfEM_R7UI76RDU	884	// (R7UI76RDU) Время срабатывания сигнала II УР при имитации
#define iEM_A1UV01IDU	BUFFER[2470]	// (A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV01IDU	885	// (A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define iEM_A1UV02IDU	BUFFER[2473]	// (A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV02IDU	886	// (A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define iEM_A1UV03IDU	BUFFER[2476]	// (A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define idiEM_A1UV03IDU	887	// (A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define iEM_A2UV01IDU	BUFFER[2479]	// (A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV01IDU	888	// (A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define iEM_A2UV02IDU	BUFFER[2482]	// (A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV02IDU	889	// (A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define iEM_A2UV03CDU	BUFFER[2485]	// (A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define idiEM_A2UV03CDU	890	// (A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define iEM_A3UV01IDU	BUFFER[2488]	// (A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define idiEM_A3UV01IDU	891	// (A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define iEM_A3UV02IDU	BUFFER[2491]	// (A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define idiEM_A3UV02IDU	892	// (A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define internal1_m1005_BLDv0	BUFFER[2494]	// (internal1_m1005_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1005_BLDv0	893	// (internal1_m1005_BLDv0) BlDv - Блокировка движения
#define internal1_m1005_X0	BUFFER[2496]	// (internal1_m1005_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1005_X0	894	// (internal1_m1005_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1005_t0	BUFFER[2501]	// (internal1_m1005_t0) время нахождения в зоне возврата
#define idinternal1_m1005_t0	895	// (internal1_m1005_t0) время нахождения в зоне возврата
#define internal1_m1027_tx	BUFFER[2506]	// (internal1_m1027_tx) tx - время накопленное сек
#define idinternal1_m1027_tx	896	// (internal1_m1027_tx) tx - время накопленное сек
#define internal1_m1027_y0	BUFFER[2511]	// (internal1_m1027_y0) y0
#define idinternal1_m1027_y0	897	// (internal1_m1027_y0) y0
#define internal1_m1028_tx	BUFFER[2513]	// (internal1_m1028_tx) tx - время накопленное сек
#define idinternal1_m1028_tx	898	// (internal1_m1028_tx) tx - время накопленное сек
#define internal1_m1028_y0	BUFFER[2518]	// (internal1_m1028_y0) y0
#define idinternal1_m1028_y0	899	// (internal1_m1028_y0) y0
#define internal1_m1029_tx	BUFFER[2520]	// (internal1_m1029_tx) tx - внутренний параметр
#define idinternal1_m1029_tx	900	// (internal1_m1029_tx) tx - внутренний параметр
#define internal1_m1035_DelSp	BUFFER[2525]	// (internal1_m1035_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1035_DelSp	901	// (internal1_m1035_DelSp) DelSp - время переключения скоростей
#define internal1_m1035_ShCntlSp0	BUFFER[2530]	// (internal1_m1035_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1035_ShCntlSp0	902	// (internal1_m1035_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1035_Shift0	BUFFER[2532]	// (internal1_m1035_Shift0) Shift0 - признак самохода
#define idinternal1_m1035_Shift0	903	// (internal1_m1035_Shift0) Shift0 - признак самохода
#define internal1_m1035_ShiftControl	BUFFER[2534]	// (internal1_m1035_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1035_ShiftControl	904	// (internal1_m1035_ShiftControl) ShiftControl - признак самохода
#define internal1_m1035_Speed0	BUFFER[2536]	// (internal1_m1035_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1035_Speed0	905	// (internal1_m1035_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1035_StSpeed	BUFFER[2541]	// (internal1_m1035_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1035_StSpeed	906	// (internal1_m1035_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1035_Vz0	BUFFER[2546]	// (internal1_m1035_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1035_Vz0	907	// (internal1_m1035_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1035_flRazg	BUFFER[2551]	// (internal1_m1035_flRazg) признак разгона/торможения
#define idinternal1_m1035_flRazg	908	// (internal1_m1035_flRazg) признак разгона/торможения
#define internal1_m1035_sumtim	BUFFER[2554]	// (internal1_m1035_sumtim) sumtim - время в пути
#define idinternal1_m1035_sumtim	909	// (internal1_m1035_sumtim) sumtim - время в пути
#define internal1_m1035_tim0	BUFFER[2559]	// (internal1_m1035_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1035_tim0	910	// (internal1_m1035_tim0) tim0 - массив значений времени цикла
#define internal1_m1035_tx	BUFFER[2859]	// (internal1_m1035_tx) tx
#define idinternal1_m1035_tx	911	// (internal1_m1035_tx) tx
#define internal1_m1035_txBl	BUFFER[2864]	// (internal1_m1035_txBl) tx
#define idinternal1_m1035_txBl	912	// (internal1_m1035_txBl) tx
#define internal1_m1035_txMBl	BUFFER[2869]	// (internal1_m1035_txMBl) tx
#define idinternal1_m1035_txMBl	913	// (internal1_m1035_txMBl) tx
#define internal1_m1035_txZS	BUFFER[2874]	// (internal1_m1035_txZS) txZS
#define idinternal1_m1035_txZS	914	// (internal1_m1035_txZS) txZS
#define internal1_m1035_txd	BUFFER[2879]	// (internal1_m1035_txd) txd
#define idinternal1_m1035_txd	915	// (internal1_m1035_txd) txd
#define internal1_m1035_tz0	BUFFER[2884]	// (internal1_m1035_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1035_tz0	916	// (internal1_m1035_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1035_x0	BUFFER[2889]	// (internal1_m1035_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1035_x0	917	// (internal1_m1035_x0) x0 - массив мгновенных значений координат
#define internal1_m1035_xptr	BUFFER[3189]	// (internal1_m1035_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1035_xptr	918	// (internal1_m1035_xptr) указатель текущей позиции в массиве координат
#define internal1_m1035_xz0	BUFFER[3192]	// (internal1_m1035_xz0) xz0 - новое задание мм
#define idinternal1_m1035_xz0	919	// (internal1_m1035_xz0) xz0 - новое задание мм
#define internal1_m1035_z0	BUFFER[3197]	// (internal1_m1035_z0) z0 - точка прекращения движения
#define idinternal1_m1035_z0	920	// (internal1_m1035_z0) z0 - точка прекращения движения
#define internal1_m1039_tx	BUFFER[3202]	// (internal1_m1039_tx) tx - внутренний параметр
#define idinternal1_m1039_tx	921	// (internal1_m1039_tx) tx - внутренний параметр
#define internal1_m1040_tx	BUFFER[3207]	// (internal1_m1040_tx) tx - внутренний параметр
#define idinternal1_m1040_tx	922	// (internal1_m1040_tx) tx - внутренний параметр
#define internal1_m1046_tx	BUFFER[3212]	// (internal1_m1046_tx) tx - внутренний параметр
#define idinternal1_m1046_tx	923	// (internal1_m1046_tx) tx - внутренний параметр
#define internal1_m1052_tx	BUFFER[3217]	// (internal1_m1052_tx) tx - время накопленное сек
#define idinternal1_m1052_tx	924	// (internal1_m1052_tx) tx - время накопленное сек
#define internal1_m1052_y0	BUFFER[3222]	// (internal1_m1052_y0) y0
#define idinternal1_m1052_y0	925	// (internal1_m1052_y0) y0
#define internal1_m1061_tx	BUFFER[3224]	// (internal1_m1061_tx) tx - внутренний параметр
#define idinternal1_m1061_tx	926	// (internal1_m1061_tx) tx - внутренний параметр
#define internal1_m1062_tx	BUFFER[3229]	// (internal1_m1062_tx) tx - внутренний параметр
#define idinternal1_m1062_tx	927	// (internal1_m1062_tx) tx - внутренний параметр
#define internal1_m1064_tx	BUFFER[3234]	// (internal1_m1064_tx) tx - внутренний параметр
#define idinternal1_m1064_tx	928	// (internal1_m1064_tx) tx - внутренний параметр
#define internal1_m1074_tx	BUFFER[3239]	// (internal1_m1074_tx) tx - внутренний параметр
#define idinternal1_m1074_tx	929	// (internal1_m1074_tx) tx - внутренний параметр
#define internal1_m1078_tx	BUFFER[3244]	// (internal1_m1078_tx) tx - внутренний параметр
#define idinternal1_m1078_tx	930	// (internal1_m1078_tx) tx - внутренний параметр
#define internal1_m1079_tx	BUFFER[3249]	// (internal1_m1079_tx) tx - внутренний параметр
#define idinternal1_m1079_tx	931	// (internal1_m1079_tx) tx - внутренний параметр
#define internal1_m1087_tx	BUFFER[3254]	// (internal1_m1087_tx) tx - внутренний параметр
#define idinternal1_m1087_tx	932	// (internal1_m1087_tx) tx - внутренний параметр
#define internal1_m1089_tx	BUFFER[3259]	// (internal1_m1089_tx) tx - внутренний параметр
#define idinternal1_m1089_tx	933	// (internal1_m1089_tx) tx - внутренний параметр
#define internal1_m108_tx	BUFFER[3264]	// (internal1_m108_tx) tx - внутренний параметр
#define idinternal1_m108_tx	934	// (internal1_m108_tx) tx - внутренний параметр
#define internal1_m1096_tx	BUFFER[3269]	// (internal1_m1096_tx) tx - внутренний параметр
#define idinternal1_m1096_tx	935	// (internal1_m1096_tx) tx - внутренний параметр
#define internal1_m1097_tx	BUFFER[3274]	// (internal1_m1097_tx) tx - внутренний параметр
#define idinternal1_m1097_tx	936	// (internal1_m1097_tx) tx - внутренний параметр
#define internal1_m1098_tx	BUFFER[3279]	// (internal1_m1098_tx) tx - внутренний параметр
#define idinternal1_m1098_tx	937	// (internal1_m1098_tx) tx - внутренний параметр
#define internal1_m1099_tx	BUFFER[3284]	// (internal1_m1099_tx) tx - внутренний параметр
#define idinternal1_m1099_tx	938	// (internal1_m1099_tx) tx - внутренний параметр
#define internal1_m1100_tx	BUFFER[3289]	// (internal1_m1100_tx) tx - внутренний параметр
#define idinternal1_m1100_tx	939	// (internal1_m1100_tx) tx - внутренний параметр
#define internal1_m1116_q0	BUFFER[3294]	// (internal1_m1116_q0) q0 - внутренний параметр
#define idinternal1_m1116_q0	940	// (internal1_m1116_q0) q0 - внутренний параметр
#define internal1_m1124_q0	BUFFER[3296]	// (internal1_m1124_q0) q0 - внутренний параметр
#define idinternal1_m1124_q0	941	// (internal1_m1124_q0) q0 - внутренний параметр
#define internal1_m1145_q0	BUFFER[3298]	// (internal1_m1145_q0) q0 - внутренний параметр
#define idinternal1_m1145_q0	942	// (internal1_m1145_q0) q0 - внутренний параметр
#define internal1_m1148_tx	BUFFER[3300]	// (internal1_m1148_tx) tx - внутренний параметр
#define idinternal1_m1148_tx	943	// (internal1_m1148_tx) tx - внутренний параметр
#define internal1_m1149_q0	BUFFER[3305]	// (internal1_m1149_q0) q0 - внутренний параметр
#define idinternal1_m1149_q0	944	// (internal1_m1149_q0) q0 - внутренний параметр
#define internal1_m1151_q0	BUFFER[3307]	// (internal1_m1151_q0) q0 - внутренний параметр
#define idinternal1_m1151_q0	945	// (internal1_m1151_q0) q0 - внутренний параметр
#define internal1_m1152_q0	BUFFER[3309]	// (internal1_m1152_q0) q0 - внутренний параметр
#define idinternal1_m1152_q0	946	// (internal1_m1152_q0) q0 - внутренний параметр
#define internal1_m1156_q0	BUFFER[3311]	// (internal1_m1156_q0) q0 - внутренний параметр
#define idinternal1_m1156_q0	947	// (internal1_m1156_q0) q0 - внутренний параметр
#define internal1_m1162_q0	BUFFER[3313]	// (internal1_m1162_q0) q0 - внутренний параметр
#define idinternal1_m1162_q0	948	// (internal1_m1162_q0) q0 - внутренний параметр
#define internal1_m1168_q0	BUFFER[3315]	// (internal1_m1168_q0) q0 - внутренний параметр
#define idinternal1_m1168_q0	949	// (internal1_m1168_q0) q0 - внутренний параметр
#define internal1_m116_q0	BUFFER[3317]	// (internal1_m116_q0) q0 - внутренний параметр
#define idinternal1_m116_q0	950	// (internal1_m116_q0) q0 - внутренний параметр
#define internal1_m1180_q0	BUFFER[3319]	// (internal1_m1180_q0) q0 - внутренний параметр
#define idinternal1_m1180_q0	951	// (internal1_m1180_q0) q0 - внутренний параметр
#define internal1_m1182_q0	BUFFER[3321]	// (internal1_m1182_q0) q0 - внутренний параметр
#define idinternal1_m1182_q0	952	// (internal1_m1182_q0) q0 - внутренний параметр
#define internal1_m1189_q0	BUFFER[3323]	// (internal1_m1189_q0) q0 - внутренний параметр
#define idinternal1_m1189_q0	953	// (internal1_m1189_q0) q0 - внутренний параметр
#define internal1_m1197_q0	BUFFER[3325]	// (internal1_m1197_q0) q0 - внутренний параметр
#define idinternal1_m1197_q0	954	// (internal1_m1197_q0) q0 - внутренний параметр
#define internal1_m1198_q0	BUFFER[3327]	// (internal1_m1198_q0) q0 - внутренний параметр
#define idinternal1_m1198_q0	955	// (internal1_m1198_q0) q0 - внутренний параметр
#define internal1_m1200_q0	BUFFER[3329]	// (internal1_m1200_q0) q0 - внутренний параметр
#define idinternal1_m1200_q0	956	// (internal1_m1200_q0) q0 - внутренний параметр
#define internal1_m1201_q0	BUFFER[3331]	// (internal1_m1201_q0) q0 - внутренний параметр
#define idinternal1_m1201_q0	957	// (internal1_m1201_q0) q0 - внутренний параметр
#define internal1_m1203_q0	BUFFER[3333]	// (internal1_m1203_q0) q0 - внутренний параметр
#define idinternal1_m1203_q0	958	// (internal1_m1203_q0) q0 - внутренний параметр
#define internal1_m1204_q0	BUFFER[3335]	// (internal1_m1204_q0) q0 - внутренний параметр
#define idinternal1_m1204_q0	959	// (internal1_m1204_q0) q0 - внутренний параметр
#define internal1_m1206_q0	BUFFER[3337]	// (internal1_m1206_q0) q0 - внутренний параметр
#define idinternal1_m1206_q0	960	// (internal1_m1206_q0) q0 - внутренний параметр
#define internal1_m1207_q0	BUFFER[3339]	// (internal1_m1207_q0) q0 - внутренний параметр
#define idinternal1_m1207_q0	961	// (internal1_m1207_q0) q0 - внутренний параметр
#define internal1_m1209_q0	BUFFER[3341]	// (internal1_m1209_q0) q0 - внутренний параметр
#define idinternal1_m1209_q0	962	// (internal1_m1209_q0) q0 - внутренний параметр
#define internal1_m120_tx	BUFFER[3343]	// (internal1_m120_tx) tx - внутренний параметр
#define idinternal1_m120_tx	963	// (internal1_m120_tx) tx - внутренний параметр
#define internal1_m122_tx	BUFFER[3348]	// (internal1_m122_tx) tx - внутренний параметр
#define idinternal1_m122_tx	964	// (internal1_m122_tx) tx - внутренний параметр
#define internal1_m1242_tx	BUFFER[3353]	// (internal1_m1242_tx) tx - внутренний параметр
#define idinternal1_m1242_tx	965	// (internal1_m1242_tx) tx - внутренний параметр
#define internal1_m1244_tx	BUFFER[3358]	// (internal1_m1244_tx) tx - внутренний параметр
#define idinternal1_m1244_tx	966	// (internal1_m1244_tx) tx - внутренний параметр
#define internal1_m1246_tx	BUFFER[3363]	// (internal1_m1246_tx) tx - внутренний параметр
#define idinternal1_m1246_tx	967	// (internal1_m1246_tx) tx - внутренний параметр
#define internal1_m1248_tx	BUFFER[3368]	// (internal1_m1248_tx) tx - внутренний параметр
#define idinternal1_m1248_tx	968	// (internal1_m1248_tx) tx - внутренний параметр
#define internal1_m1255_tx	BUFFER[3373]	// (internal1_m1255_tx) tx - внутренний параметр
#define idinternal1_m1255_tx	969	// (internal1_m1255_tx) tx - внутренний параметр
#define internal1_m1259_tx	BUFFER[3378]	// (internal1_m1259_tx) tx - внутренний параметр
#define idinternal1_m1259_tx	970	// (internal1_m1259_tx) tx - внутренний параметр
#define internal1_m1260_tx	BUFFER[3383]	// (internal1_m1260_tx) tx - внутренний параметр
#define idinternal1_m1260_tx	971	// (internal1_m1260_tx) tx - внутренний параметр
#define internal1_m1263_tx	BUFFER[3388]	// (internal1_m1263_tx) tx - внутренний параметр
#define idinternal1_m1263_tx	972	// (internal1_m1263_tx) tx - внутренний параметр
#define internal1_m1273_BLDv0	BUFFER[3393]	// (internal1_m1273_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1273_BLDv0	973	// (internal1_m1273_BLDv0) BlDv - Блокировка движения
#define internal1_m1273_X0	BUFFER[3395]	// (internal1_m1273_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1273_X0	974	// (internal1_m1273_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1273_t0	BUFFER[3400]	// (internal1_m1273_t0) время нахождения в зоне возврата
#define idinternal1_m1273_t0	975	// (internal1_m1273_t0) время нахождения в зоне возврата
#define internal1_m127_tx	BUFFER[3405]	// (internal1_m127_tx) tx - внутренний параметр
#define idinternal1_m127_tx	976	// (internal1_m127_tx) tx - внутренний параметр
#define internal1_m1281_BlDv0	BUFFER[3410]	// (internal1_m1281_BlDv0) - была блокировка
#define idinternal1_m1281_BlDv0	977	// (internal1_m1281_BlDv0) - была блокировка
#define internal1_m1281_DvDw0	BUFFER[3412]	// (internal1_m1281_DvDw0) - есть команда на движение назад
#define idinternal1_m1281_DvDw0	978	// (internal1_m1281_DvDw0) - есть команда на движение назад
#define internal1_m1281_DvUp0	BUFFER[3414]	// (internal1_m1281_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1281_DvUp0	979	// (internal1_m1281_DvUp0) - есть команда на движение вперёд
#define internal1_m1281_FDvDw0	BUFFER[3416]	// (internal1_m1281_FDvDw0) - есть команда на движение назад
#define idinternal1_m1281_FDvDw0	980	// (internal1_m1281_FDvDw0) - есть команда на движение назад
#define internal1_m1281_FDvUp0	BUFFER[3418]	// (internal1_m1281_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1281_FDvUp0	981	// (internal1_m1281_FDvUp0) - есть команда на движение вперёд
#define internal1_m1281_Pkav0	BUFFER[3420]	// (internal1_m1281_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1281_Pkav0	982	// (internal1_m1281_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1281_Pkv0	BUFFER[3422]	// (internal1_m1281_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1281_Pkv0	983	// (internal1_m1281_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1281_Zkav0	BUFFER[3424]	// (internal1_m1281_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1281_Zkav0	984	// (internal1_m1281_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1281_Zkv0	BUFFER[3426]	// (internal1_m1281_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1281_Zkv0	985	// (internal1_m1281_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1281_fef	BUFFER[3428]	// (internal1_m1281_fef) fef
#define idinternal1_m1281_fef	986	// (internal1_m1281_fef) fef
#define internal1_m1281_txHr	BUFFER[3430]	// (internal1_m1281_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1281_txHr	987	// (internal1_m1281_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1281_txLd	BUFFER[3435]	// (internal1_m1281_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1281_txLd	988	// (internal1_m1281_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1281_txNm	BUFFER[3440]	// (internal1_m1281_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1281_txNm	989	// (internal1_m1281_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1281_txSm	BUFFER[3445]	// (internal1_m1281_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1281_txSm	990	// (internal1_m1281_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1284_tx	BUFFER[3450]	// (internal1_m1284_tx) tx - внутренний параметр
#define idinternal1_m1284_tx	991	// (internal1_m1284_tx) tx - внутренний параметр
#define internal1_m1285_tx	BUFFER[3455]	// (internal1_m1285_tx) tx - внутренний параметр
#define idinternal1_m1285_tx	992	// (internal1_m1285_tx) tx - внутренний параметр
#define internal1_m1290_tx	BUFFER[3460]	// (internal1_m1290_tx) tx - время накопленное сек
#define idinternal1_m1290_tx	993	// (internal1_m1290_tx) tx - время накопленное сек
#define internal1_m1290_y0	BUFFER[3465]	// (internal1_m1290_y0) y0
#define idinternal1_m1290_y0	994	// (internal1_m1290_y0) y0
#define internal1_m1292_tx	BUFFER[3467]	// (internal1_m1292_tx) tx - внутренний параметр
#define idinternal1_m1292_tx	995	// (internal1_m1292_tx) tx - внутренний параметр
#define internal1_m1294_tx	BUFFER[3472]	// (internal1_m1294_tx) tx - время накопленное сек
#define idinternal1_m1294_tx	996	// (internal1_m1294_tx) tx - время накопленное сек
#define internal1_m1294_y0	BUFFER[3477]	// (internal1_m1294_y0) y0
#define idinternal1_m1294_y0	997	// (internal1_m1294_y0) y0
#define internal1_m1297_tx	BUFFER[3479]	// (internal1_m1297_tx) tx - внутренний параметр
#define idinternal1_m1297_tx	998	// (internal1_m1297_tx) tx - внутренний параметр
#define internal1_m1298_tx	BUFFER[3484]	// (internal1_m1298_tx) tx - внутренний параметр
#define idinternal1_m1298_tx	999	// (internal1_m1298_tx) tx - внутренний параметр
#define internal1_m1300_DelSp	BUFFER[3489]	// (internal1_m1300_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1300_DelSp	1000	// (internal1_m1300_DelSp) DelSp - время переключения скоростей
#define internal1_m1300_ShCntlSp0	BUFFER[3494]	// (internal1_m1300_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1300_ShCntlSp0	1001	// (internal1_m1300_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1300_Shift0	BUFFER[3496]	// (internal1_m1300_Shift0) Shift0 - признак самохода
#define idinternal1_m1300_Shift0	1002	// (internal1_m1300_Shift0) Shift0 - признак самохода
#define internal1_m1300_ShiftControl	BUFFER[3498]	// (internal1_m1300_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1300_ShiftControl	1003	// (internal1_m1300_ShiftControl) ShiftControl - признак самохода
#define internal1_m1300_Speed0	BUFFER[3500]	// (internal1_m1300_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1300_Speed0	1004	// (internal1_m1300_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1300_StSpeed	BUFFER[3505]	// (internal1_m1300_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1300_StSpeed	1005	// (internal1_m1300_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1300_Vz0	BUFFER[3510]	// (internal1_m1300_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1300_Vz0	1006	// (internal1_m1300_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1300_flRazg	BUFFER[3515]	// (internal1_m1300_flRazg) признак разгона/торможения
#define idinternal1_m1300_flRazg	1007	// (internal1_m1300_flRazg) признак разгона/торможения
#define internal1_m1300_sumtim	BUFFER[3518]	// (internal1_m1300_sumtim) sumtim - время в пути
#define idinternal1_m1300_sumtim	1008	// (internal1_m1300_sumtim) sumtim - время в пути
#define internal1_m1300_tim0	BUFFER[3523]	// (internal1_m1300_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1300_tim0	1009	// (internal1_m1300_tim0) tim0 - массив значений времени цикла
#define internal1_m1300_tx	BUFFER[3623]	// (internal1_m1300_tx) tx
#define idinternal1_m1300_tx	1010	// (internal1_m1300_tx) tx
#define internal1_m1300_txBl	BUFFER[3628]	// (internal1_m1300_txBl) tx
#define idinternal1_m1300_txBl	1011	// (internal1_m1300_txBl) tx
#define internal1_m1300_txMBl	BUFFER[3633]	// (internal1_m1300_txMBl) tx
#define idinternal1_m1300_txMBl	1012	// (internal1_m1300_txMBl) tx
#define internal1_m1300_txZS	BUFFER[3638]	// (internal1_m1300_txZS) txZS
#define idinternal1_m1300_txZS	1013	// (internal1_m1300_txZS) txZS
#define internal1_m1300_txd	BUFFER[3643]	// (internal1_m1300_txd) txd
#define idinternal1_m1300_txd	1014	// (internal1_m1300_txd) txd
#define internal1_m1300_tz0	BUFFER[3648]	// (internal1_m1300_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1300_tz0	1015	// (internal1_m1300_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1300_x0	BUFFER[3653]	// (internal1_m1300_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1300_x0	1016	// (internal1_m1300_x0) x0 - массив мгновенных значений координат
#define internal1_m1300_xptr	BUFFER[3753]	// (internal1_m1300_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1300_xptr	1017	// (internal1_m1300_xptr) указатель текущей позиции в массиве координат
#define internal1_m1300_xz0	BUFFER[3756]	// (internal1_m1300_xz0) xz0 - новое задание мм
#define idinternal1_m1300_xz0	1018	// (internal1_m1300_xz0) xz0 - новое задание мм
#define internal1_m1300_z0	BUFFER[3761]	// (internal1_m1300_z0) z0 - точка прекращения движения
#define idinternal1_m1300_z0	1019	// (internal1_m1300_z0) z0 - точка прекращения движения
#define internal1_m1303_tx	BUFFER[3766]	// (internal1_m1303_tx) tx - внутренний параметр
#define idinternal1_m1303_tx	1020	// (internal1_m1303_tx) tx - внутренний параметр
#define internal1_m1306_tx	BUFFER[3771]	// (internal1_m1306_tx) tx - время накопленное сек
#define idinternal1_m1306_tx	1021	// (internal1_m1306_tx) tx - время накопленное сек
#define internal1_m1306_y0	BUFFER[3776]	// (internal1_m1306_y0) y0
#define idinternal1_m1306_y0	1022	// (internal1_m1306_y0) y0
#define internal1_m1326_tx	BUFFER[3778]	// (internal1_m1326_tx) tx - внутренний параметр
#define idinternal1_m1326_tx	1023	// (internal1_m1326_tx) tx - внутренний параметр
#define internal1_m1327_tx	BUFFER[3783]	// (internal1_m1327_tx) tx - внутренний параметр
#define idinternal1_m1327_tx	1024	// (internal1_m1327_tx) tx - внутренний параметр
#define internal1_m1330_tx	BUFFER[3788]	// (internal1_m1330_tx) tx - внутренний параметр
#define idinternal1_m1330_tx	1025	// (internal1_m1330_tx) tx - внутренний параметр
#define internal1_m1333_BlDv0	BUFFER[3793]	// (internal1_m1333_BlDv0) - была блокировка
#define idinternal1_m1333_BlDv0	1026	// (internal1_m1333_BlDv0) - была блокировка
#define internal1_m1333_DvDw0	BUFFER[3795]	// (internal1_m1333_DvDw0) - есть команда на движение назад
#define idinternal1_m1333_DvDw0	1027	// (internal1_m1333_DvDw0) - есть команда на движение назад
#define internal1_m1333_DvUp0	BUFFER[3797]	// (internal1_m1333_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1333_DvUp0	1028	// (internal1_m1333_DvUp0) - есть команда на движение вперёд
#define internal1_m1333_FDvDw0	BUFFER[3799]	// (internal1_m1333_FDvDw0) - есть команда на движение назад
#define idinternal1_m1333_FDvDw0	1029	// (internal1_m1333_FDvDw0) - есть команда на движение назад
#define internal1_m1333_FDvUp0	BUFFER[3801]	// (internal1_m1333_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1333_FDvUp0	1030	// (internal1_m1333_FDvUp0) - есть команда на движение вперёд
#define internal1_m1333_Pkav0	BUFFER[3803]	// (internal1_m1333_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1333_Pkav0	1031	// (internal1_m1333_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1333_Pkv0	BUFFER[3805]	// (internal1_m1333_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1333_Pkv0	1032	// (internal1_m1333_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1333_Zkav0	BUFFER[3807]	// (internal1_m1333_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1333_Zkav0	1033	// (internal1_m1333_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1333_Zkv0	BUFFER[3809]	// (internal1_m1333_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1333_Zkv0	1034	// (internal1_m1333_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1333_fef	BUFFER[3811]	// (internal1_m1333_fef) fef
#define idinternal1_m1333_fef	1035	// (internal1_m1333_fef) fef
#define internal1_m1333_txHr	BUFFER[3813]	// (internal1_m1333_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1333_txHr	1036	// (internal1_m1333_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1333_txLd	BUFFER[3818]	// (internal1_m1333_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1333_txLd	1037	// (internal1_m1333_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1333_txNm	BUFFER[3823]	// (internal1_m1333_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1333_txNm	1038	// (internal1_m1333_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1333_txSm	BUFFER[3828]	// (internal1_m1333_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1333_txSm	1039	// (internal1_m1333_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1341_tx	BUFFER[3833]	// (internal1_m1341_tx) tx - внутренний параметр
#define idinternal1_m1341_tx	1040	// (internal1_m1341_tx) tx - внутренний параметр
#define internal1_m1343_BlDv0	BUFFER[3838]	// (internal1_m1343_BlDv0) - была блокировка
#define idinternal1_m1343_BlDv0	1041	// (internal1_m1343_BlDv0) - была блокировка
#define internal1_m1343_DvDw0	BUFFER[3840]	// (internal1_m1343_DvDw0) - есть команда на движение назад
#define idinternal1_m1343_DvDw0	1042	// (internal1_m1343_DvDw0) - есть команда на движение назад
#define internal1_m1343_DvUp0	BUFFER[3842]	// (internal1_m1343_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1343_DvUp0	1043	// (internal1_m1343_DvUp0) - есть команда на движение вперёд
#define internal1_m1343_FDvDw0	BUFFER[3844]	// (internal1_m1343_FDvDw0) - есть команда на движение назад
#define idinternal1_m1343_FDvDw0	1044	// (internal1_m1343_FDvDw0) - есть команда на движение назад
#define internal1_m1343_FDvUp0	BUFFER[3846]	// (internal1_m1343_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1343_FDvUp0	1045	// (internal1_m1343_FDvUp0) - есть команда на движение вперёд
#define internal1_m1343_Pkav0	BUFFER[3848]	// (internal1_m1343_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1343_Pkav0	1046	// (internal1_m1343_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1343_Pkv0	BUFFER[3850]	// (internal1_m1343_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1343_Pkv0	1047	// (internal1_m1343_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1343_Zkav0	BUFFER[3852]	// (internal1_m1343_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1343_Zkav0	1048	// (internal1_m1343_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1343_Zkv0	BUFFER[3854]	// (internal1_m1343_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1343_Zkv0	1049	// (internal1_m1343_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1343_fef	BUFFER[3856]	// (internal1_m1343_fef) fef
#define idinternal1_m1343_fef	1050	// (internal1_m1343_fef) fef
#define internal1_m1343_txHr	BUFFER[3858]	// (internal1_m1343_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1343_txHr	1051	// (internal1_m1343_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1343_txLd	BUFFER[3863]	// (internal1_m1343_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1343_txLd	1052	// (internal1_m1343_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1343_txNm	BUFFER[3868]	// (internal1_m1343_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1343_txNm	1053	// (internal1_m1343_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1343_txSm	BUFFER[3873]	// (internal1_m1343_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1343_txSm	1054	// (internal1_m1343_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1347_tx	BUFFER[3878]	// (internal1_m1347_tx) tx - внутренний параметр
#define idinternal1_m1347_tx	1055	// (internal1_m1347_tx) tx - внутренний параметр
#define internal1_m1348_tx	BUFFER[3883]	// (internal1_m1348_tx) tx - внутренний параметр
#define idinternal1_m1348_tx	1056	// (internal1_m1348_tx) tx - внутренний параметр
#define internal1_m1349_tx	BUFFER[3888]	// (internal1_m1349_tx) tx - внутренний параметр
#define idinternal1_m1349_tx	1057	// (internal1_m1349_tx) tx - внутренний параметр
#define internal1_m1370_BLDv0	BUFFER[3893]	// (internal1_m1370_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1370_BLDv0	1058	// (internal1_m1370_BLDv0) BlDv - Блокировка движения
#define internal1_m1370_X0	BUFFER[3895]	// (internal1_m1370_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1370_X0	1059	// (internal1_m1370_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1370_t0	BUFFER[3900]	// (internal1_m1370_t0) время нахождения в зоне возврата
#define idinternal1_m1370_t0	1060	// (internal1_m1370_t0) время нахождения в зоне возврата
#define internal1_m1390_tx	BUFFER[3905]	// (internal1_m1390_tx) tx - внутренний параметр
#define idinternal1_m1390_tx	1061	// (internal1_m1390_tx) tx - внутренний параметр
#define internal1_m1393_tx	BUFFER[3910]	// (internal1_m1393_tx) tx - внутренний параметр
#define idinternal1_m1393_tx	1062	// (internal1_m1393_tx) tx - внутренний параметр
#define internal1_m1397_tx	BUFFER[3915]	// (internal1_m1397_tx) tx - время накопленное сек
#define idinternal1_m1397_tx	1063	// (internal1_m1397_tx) tx - время накопленное сек
#define internal1_m1397_y0	BUFFER[3920]	// (internal1_m1397_y0) y0
#define idinternal1_m1397_y0	1064	// (internal1_m1397_y0) y0
#define internal1_m1398_tx	BUFFER[3922]	// (internal1_m1398_tx) tx - время накопленное сек
#define idinternal1_m1398_tx	1065	// (internal1_m1398_tx) tx - время накопленное сек
#define internal1_m1398_y0	BUFFER[3927]	// (internal1_m1398_y0) y0
#define idinternal1_m1398_y0	1066	// (internal1_m1398_y0) y0
#define internal1_m13_tx	BUFFER[3929]	// (internal1_m13_tx) tx - внутренний параметр
#define idinternal1_m13_tx	1067	// (internal1_m13_tx) tx - внутренний параметр
#define internal1_m1405_DelSp	BUFFER[3934]	// (internal1_m1405_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1405_DelSp	1068	// (internal1_m1405_DelSp) DelSp - время переключения скоростей
#define internal1_m1405_ShCntlSp0	BUFFER[3939]	// (internal1_m1405_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1405_ShCntlSp0	1069	// (internal1_m1405_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1405_Shift0	BUFFER[3941]	// (internal1_m1405_Shift0) Shift0 - признак самохода
#define idinternal1_m1405_Shift0	1070	// (internal1_m1405_Shift0) Shift0 - признак самохода
#define internal1_m1405_ShiftControl	BUFFER[3943]	// (internal1_m1405_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1405_ShiftControl	1071	// (internal1_m1405_ShiftControl) ShiftControl - признак самохода
#define internal1_m1405_Speed0	BUFFER[3945]	// (internal1_m1405_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1405_Speed0	1072	// (internal1_m1405_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1405_StSpeed	BUFFER[3950]	// (internal1_m1405_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1405_StSpeed	1073	// (internal1_m1405_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1405_Vz0	BUFFER[3955]	// (internal1_m1405_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1405_Vz0	1074	// (internal1_m1405_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1405_flRazg	BUFFER[3960]	// (internal1_m1405_flRazg) признак разгона/торможения
#define idinternal1_m1405_flRazg	1075	// (internal1_m1405_flRazg) признак разгона/торможения
#define internal1_m1405_sumtim	BUFFER[3963]	// (internal1_m1405_sumtim) sumtim - время в пути
#define idinternal1_m1405_sumtim	1076	// (internal1_m1405_sumtim) sumtim - время в пути
#define internal1_m1405_tim0	BUFFER[3968]	// (internal1_m1405_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1405_tim0	1077	// (internal1_m1405_tim0) tim0 - массив значений времени цикла
#define internal1_m1405_tx	BUFFER[4368]	// (internal1_m1405_tx) tx
#define idinternal1_m1405_tx	1078	// (internal1_m1405_tx) tx
#define internal1_m1405_txBl	BUFFER[4373]	// (internal1_m1405_txBl) tx
#define idinternal1_m1405_txBl	1079	// (internal1_m1405_txBl) tx
#define internal1_m1405_txMBl	BUFFER[4378]	// (internal1_m1405_txMBl) tx
#define idinternal1_m1405_txMBl	1080	// (internal1_m1405_txMBl) tx
#define internal1_m1405_txZS	BUFFER[4383]	// (internal1_m1405_txZS) txZS
#define idinternal1_m1405_txZS	1081	// (internal1_m1405_txZS) txZS
#define internal1_m1405_txd	BUFFER[4388]	// (internal1_m1405_txd) txd
#define idinternal1_m1405_txd	1082	// (internal1_m1405_txd) txd
#define internal1_m1405_tz0	BUFFER[4393]	// (internal1_m1405_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1405_tz0	1083	// (internal1_m1405_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1405_x0	BUFFER[4398]	// (internal1_m1405_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1405_x0	1084	// (internal1_m1405_x0) x0 - массив мгновенных значений координат
#define internal1_m1405_xptr	BUFFER[4798]	// (internal1_m1405_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1405_xptr	1085	// (internal1_m1405_xptr) указатель текущей позиции в массиве координат
#define internal1_m1405_xz0	BUFFER[4801]	// (internal1_m1405_xz0) xz0 - новое задание мм
#define idinternal1_m1405_xz0	1086	// (internal1_m1405_xz0) xz0 - новое задание мм
#define internal1_m1405_z0	BUFFER[4806]	// (internal1_m1405_z0) z0 - точка прекращения движения
#define idinternal1_m1405_z0	1087	// (internal1_m1405_z0) z0 - точка прекращения движения
#define internal1_m1408_tx	BUFFER[4811]	// (internal1_m1408_tx) tx - внутренний параметр
#define idinternal1_m1408_tx	1088	// (internal1_m1408_tx) tx - внутренний параметр
#define internal1_m1412_tx	BUFFER[4816]	// (internal1_m1412_tx) tx - внутренний параметр
#define idinternal1_m1412_tx	1089	// (internal1_m1412_tx) tx - внутренний параметр
#define internal1_m1415_tx	BUFFER[4821]	// (internal1_m1415_tx) tx - время накопленное сек
#define idinternal1_m1415_tx	1090	// (internal1_m1415_tx) tx - время накопленное сек
#define internal1_m1415_y0	BUFFER[4826]	// (internal1_m1415_y0) y0
#define idinternal1_m1415_y0	1091	// (internal1_m1415_y0) y0
#define internal1_m1426_tx	BUFFER[4828]	// (internal1_m1426_tx) tx - внутренний параметр
#define idinternal1_m1426_tx	1092	// (internal1_m1426_tx) tx - внутренний параметр
#define internal1_m1428_tx	BUFFER[4833]	// (internal1_m1428_tx) tx - внутренний параметр
#define idinternal1_m1428_tx	1093	// (internal1_m1428_tx) tx - внутренний параметр
#define internal1_m1435_tx	BUFFER[4838]	// (internal1_m1435_tx) tx - внутренний параметр
#define idinternal1_m1435_tx	1094	// (internal1_m1435_tx) tx - внутренний параметр
#define internal1_m1441_tx	BUFFER[4843]	// (internal1_m1441_tx) tx - внутренний параметр
#define idinternal1_m1441_tx	1095	// (internal1_m1441_tx) tx - внутренний параметр
#define internal1_m1445_tx	BUFFER[4848]	// (internal1_m1445_tx) tx - внутренний параметр
#define idinternal1_m1445_tx	1096	// (internal1_m1445_tx) tx - внутренний параметр
#define internal1_m1446_tx	BUFFER[4853]	// (internal1_m1446_tx) tx - внутренний параметр
#define idinternal1_m1446_tx	1097	// (internal1_m1446_tx) tx - внутренний параметр
#define internal1_m1455_tx	BUFFER[4858]	// (internal1_m1455_tx) tx - внутренний параметр
#define idinternal1_m1455_tx	1098	// (internal1_m1455_tx) tx - внутренний параметр
#define internal1_m1456_tx	BUFFER[4863]	// (internal1_m1456_tx) tx - внутренний параметр
#define idinternal1_m1456_tx	1099	// (internal1_m1456_tx) tx - внутренний параметр
#define internal1_m1462_tx	BUFFER[4868]	// (internal1_m1462_tx) tx - внутренний параметр
#define idinternal1_m1462_tx	1100	// (internal1_m1462_tx) tx - внутренний параметр
#define internal1_m1463_tx	BUFFER[4873]	// (internal1_m1463_tx) tx - внутренний параметр
#define idinternal1_m1463_tx	1101	// (internal1_m1463_tx) tx - внутренний параметр
#define internal1_m1464_tx	BUFFER[4878]	// (internal1_m1464_tx) tx - внутренний параметр
#define idinternal1_m1464_tx	1102	// (internal1_m1464_tx) tx - внутренний параметр
#define internal1_m1465_tx	BUFFER[4883]	// (internal1_m1465_tx) tx - внутренний параметр
#define idinternal1_m1465_tx	1103	// (internal1_m1465_tx) tx - внутренний параметр
#define internal1_m1483_BLDv0	BUFFER[4888]	// (internal1_m1483_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1483_BLDv0	1104	// (internal1_m1483_BLDv0) BlDv - Блокировка движения
#define internal1_m1483_X0	BUFFER[4890]	// (internal1_m1483_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1483_X0	1105	// (internal1_m1483_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1483_t0	BUFFER[4895]	// (internal1_m1483_t0) время нахождения в зоне возврата
#define idinternal1_m1483_t0	1106	// (internal1_m1483_t0) время нахождения в зоне возврата
#define internal1_m1500_tx	BUFFER[4900]	// (internal1_m1500_tx) tx - время накопленное сек
#define idinternal1_m1500_tx	1107	// (internal1_m1500_tx) tx - время накопленное сек
#define internal1_m1500_y0	BUFFER[4905]	// (internal1_m1500_y0) y0
#define idinternal1_m1500_y0	1108	// (internal1_m1500_y0) y0
#define internal1_m1501_tx	BUFFER[4907]	// (internal1_m1501_tx) tx - время накопленное сек
#define idinternal1_m1501_tx	1109	// (internal1_m1501_tx) tx - время накопленное сек
#define internal1_m1501_y0	BUFFER[4912]	// (internal1_m1501_y0) y0
#define idinternal1_m1501_y0	1110	// (internal1_m1501_y0) y0
#define internal1_m1506_tx	BUFFER[4914]	// (internal1_m1506_tx) tx - внутренний параметр
#define idinternal1_m1506_tx	1111	// (internal1_m1506_tx) tx - внутренний параметр
#define internal1_m1507_tx	BUFFER[4919]	// (internal1_m1507_tx) tx - внутренний параметр
#define idinternal1_m1507_tx	1112	// (internal1_m1507_tx) tx - внутренний параметр
#define internal1_m1509_DelSp	BUFFER[4924]	// (internal1_m1509_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1509_DelSp	1113	// (internal1_m1509_DelSp) DelSp - время переключения скоростей
#define internal1_m1509_ShCntlSp0	BUFFER[4929]	// (internal1_m1509_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1509_ShCntlSp0	1114	// (internal1_m1509_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1509_Shift0	BUFFER[4931]	// (internal1_m1509_Shift0) Shift0 - признак самохода
#define idinternal1_m1509_Shift0	1115	// (internal1_m1509_Shift0) Shift0 - признак самохода
#define internal1_m1509_ShiftControl	BUFFER[4933]	// (internal1_m1509_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1509_ShiftControl	1116	// (internal1_m1509_ShiftControl) ShiftControl - признак самохода
#define internal1_m1509_Speed0	BUFFER[4935]	// (internal1_m1509_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1509_Speed0	1117	// (internal1_m1509_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1509_StSpeed	BUFFER[4940]	// (internal1_m1509_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1509_StSpeed	1118	// (internal1_m1509_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1509_Vz0	BUFFER[4945]	// (internal1_m1509_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1509_Vz0	1119	// (internal1_m1509_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1509_flRazg	BUFFER[4950]	// (internal1_m1509_flRazg) признак разгона/торможения
#define idinternal1_m1509_flRazg	1120	// (internal1_m1509_flRazg) признак разгона/торможения
#define internal1_m1509_sumtim	BUFFER[4953]	// (internal1_m1509_sumtim) sumtim - время в пути
#define idinternal1_m1509_sumtim	1121	// (internal1_m1509_sumtim) sumtim - время в пути
#define internal1_m1509_tim0	BUFFER[4958]	// (internal1_m1509_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1509_tim0	1122	// (internal1_m1509_tim0) tim0 - массив значений времени цикла
#define internal1_m1509_tx	BUFFER[5258]	// (internal1_m1509_tx) tx
#define idinternal1_m1509_tx	1123	// (internal1_m1509_tx) tx
#define internal1_m1509_txBl	BUFFER[5263]	// (internal1_m1509_txBl) tx
#define idinternal1_m1509_txBl	1124	// (internal1_m1509_txBl) tx
#define internal1_m1509_txMBl	BUFFER[5268]	// (internal1_m1509_txMBl) tx
#define idinternal1_m1509_txMBl	1125	// (internal1_m1509_txMBl) tx
#define internal1_m1509_txZS	BUFFER[5273]	// (internal1_m1509_txZS) txZS
#define idinternal1_m1509_txZS	1126	// (internal1_m1509_txZS) txZS
#define internal1_m1509_txd	BUFFER[5278]	// (internal1_m1509_txd) txd
#define idinternal1_m1509_txd	1127	// (internal1_m1509_txd) txd
#define internal1_m1509_tz0	BUFFER[5283]	// (internal1_m1509_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1509_tz0	1128	// (internal1_m1509_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1509_x0	BUFFER[5288]	// (internal1_m1509_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1509_x0	1129	// (internal1_m1509_x0) x0 - массив мгновенных значений координат
#define internal1_m1509_xptr	BUFFER[5588]	// (internal1_m1509_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1509_xptr	1130	// (internal1_m1509_xptr) указатель текущей позиции в массиве координат
#define internal1_m1509_xz0	BUFFER[5591]	// (internal1_m1509_xz0) xz0 - новое задание мм
#define idinternal1_m1509_xz0	1131	// (internal1_m1509_xz0) xz0 - новое задание мм
#define internal1_m1509_z0	BUFFER[5596]	// (internal1_m1509_z0) z0 - точка прекращения движения
#define idinternal1_m1509_z0	1132	// (internal1_m1509_z0) z0 - точка прекращения движения
#define internal1_m1516_tx	BUFFER[5601]	// (internal1_m1516_tx) tx - внутренний параметр
#define idinternal1_m1516_tx	1133	// (internal1_m1516_tx) tx - внутренний параметр
#define internal1_m1519_tx	BUFFER[5606]	// (internal1_m1519_tx) tx - внутренний параметр
#define idinternal1_m1519_tx	1134	// (internal1_m1519_tx) tx - внутренний параметр
#define internal1_m1525_tx	BUFFER[5611]	// (internal1_m1525_tx) tx - время накопленное сек
#define idinternal1_m1525_tx	1135	// (internal1_m1525_tx) tx - время накопленное сек
#define internal1_m1525_y0	BUFFER[5616]	// (internal1_m1525_y0) y0
#define idinternal1_m1525_y0	1136	// (internal1_m1525_y0) y0
#define internal1_m1534_tx	BUFFER[5618]	// (internal1_m1534_tx) tx - внутренний параметр
#define idinternal1_m1534_tx	1137	// (internal1_m1534_tx) tx - внутренний параметр
#define internal1_m1535_tx	BUFFER[5623]	// (internal1_m1535_tx) tx - внутренний параметр
#define idinternal1_m1535_tx	1138	// (internal1_m1535_tx) tx - внутренний параметр
#define internal1_m1537_tx	BUFFER[5628]	// (internal1_m1537_tx) tx - внутренний параметр
#define idinternal1_m1537_tx	1139	// (internal1_m1537_tx) tx - внутренний параметр
#define internal1_m1547_tx	BUFFER[5633]	// (internal1_m1547_tx) tx - внутренний параметр
#define idinternal1_m1547_tx	1140	// (internal1_m1547_tx) tx - внутренний параметр
#define internal1_m1549_tx	BUFFER[5638]	// (internal1_m1549_tx) tx - внутренний параметр
#define idinternal1_m1549_tx	1141	// (internal1_m1549_tx) tx - внутренний параметр
#define internal1_m1550_tx	BUFFER[5643]	// (internal1_m1550_tx) tx - внутренний параметр
#define idinternal1_m1550_tx	1142	// (internal1_m1550_tx) tx - внутренний параметр
#define internal1_m1560_tx	BUFFER[5648]	// (internal1_m1560_tx) tx - внутренний параметр
#define idinternal1_m1560_tx	1143	// (internal1_m1560_tx) tx - внутренний параметр
#define internal1_m1562_tx	BUFFER[5653]	// (internal1_m1562_tx) tx - внутренний параметр
#define idinternal1_m1562_tx	1144	// (internal1_m1562_tx) tx - внутренний параметр
#define internal1_m1569_tx	BUFFER[5658]	// (internal1_m1569_tx) tx - внутренний параметр
#define idinternal1_m1569_tx	1145	// (internal1_m1569_tx) tx - внутренний параметр
#define internal1_m1570_tx	BUFFER[5663]	// (internal1_m1570_tx) tx - внутренний параметр
#define idinternal1_m1570_tx	1146	// (internal1_m1570_tx) tx - внутренний параметр
#define internal1_m1571_tx	BUFFER[5668]	// (internal1_m1571_tx) tx - внутренний параметр
#define idinternal1_m1571_tx	1147	// (internal1_m1571_tx) tx - внутренний параметр
#define internal1_m1572_tx	BUFFER[5673]	// (internal1_m1572_tx) tx - внутренний параметр
#define idinternal1_m1572_tx	1148	// (internal1_m1572_tx) tx - внутренний параметр
#define internal1_m1573_tx	BUFFER[5678]	// (internal1_m1573_tx) tx - внутренний параметр
#define idinternal1_m1573_tx	1149	// (internal1_m1573_tx) tx - внутренний параметр
#define internal1_m1599_q0	BUFFER[5683]	// (internal1_m1599_q0) q0 - внутренний параметр
#define idinternal1_m1599_q0	1150	// (internal1_m1599_q0) q0 - внутренний параметр
#define internal1_m1600_ErrPr0	BUFFER[5685]	// (internal1_m1600_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m1600_ErrPr0	1151	// (internal1_m1600_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m1600_FinPr0	BUFFER[5687]	// (internal1_m1600_FinPr0) FinPr - конец программы
#define idinternal1_m1600_FinPr0	1152	// (internal1_m1600_FinPr0) FinPr - конец программы
#define internal1_m1600_MyFirstEnterFlag	BUFFER[5689]	// (internal1_m1600_MyFirstEnterFlag)  
#define idinternal1_m1600_MyFirstEnterFlag	1153	// (internal1_m1600_MyFirstEnterFlag)  
#define internal1_m1600_Step	BUFFER[5691]	// (internal1_m1600_Step)  - текущий шаг программы
#define idinternal1_m1600_Step	1154	// (internal1_m1600_Step)  - текущий шаг программы
#define internal1_m1600_TimS	BUFFER[5694]	// (internal1_m1600_TimS) Время от старта программы
#define idinternal1_m1600_TimS	1155	// (internal1_m1600_TimS) Время от старта программы
#define internal1_m1600_rz	BUFFER[5699]	// (internal1_m1600_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m1600_rz	1156	// (internal1_m1600_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m1600_sb2UR0	BUFFER[5711]	// (internal1_m1600_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m1600_sb2UR0	1157	// (internal1_m1600_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m1600_sbINI0	BUFFER[5713]	// (internal1_m1600_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m1600_sbINI0	1158	// (internal1_m1600_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m1600_sbNupIS0	BUFFER[5715]	// (internal1_m1600_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m1600_sbNupIS0	1159	// (internal1_m1600_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m1600_sbVuIS0	BUFFER[5717]	// (internal1_m1600_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m1600_sbVuIS0	1160	// (internal1_m1600_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m1600_sbVuRB0	BUFFER[5719]	// (internal1_m1600_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m1600_sbVuRB0	1161	// (internal1_m1600_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m1602_q0	BUFFER[5721]	// (internal1_m1602_q0) q0 - внутренний параметр
#define idinternal1_m1602_q0	1162	// (internal1_m1602_q0) q0 - внутренний параметр
#define internal1_m1617_x0	BUFFER[5726]	// (internal1_m1617_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1617_x0	1163	// (internal1_m1617_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1627_tx	BUFFER[5731]	// (internal1_m1627_tx) tx - внутренний параметр
#define idinternal1_m1627_tx	1164	// (internal1_m1627_tx) tx - внутренний параметр
#define internal1_m1636_q0	BUFFER[5736]	// (internal1_m1636_q0) q0 - внутренний параметр
#define idinternal1_m1636_q0	1165	// (internal1_m1636_q0) q0 - внутренний параметр
#define internal1_m1637_tim	BUFFER[5738]	// (internal1_m1637_tim) - время задержки выходного сигнала
#define idinternal1_m1637_tim	1166	// (internal1_m1637_tim) - время задержки выходного сигнала
#define internal1_m1637_x0	BUFFER[5743]	// (internal1_m1637_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m1637_x0	1167	// (internal1_m1637_x0) - значение входного параметра на предыдущем шаге
#define internal1_m1643_tx	BUFFER[5745]	// (internal1_m1643_tx) tx - время накопленное сек
#define idinternal1_m1643_tx	1168	// (internal1_m1643_tx) tx - время накопленное сек
#define internal1_m1643_y0	BUFFER[5750]	// (internal1_m1643_y0) y0
#define idinternal1_m1643_y0	1169	// (internal1_m1643_y0) y0
#define internal1_m1646_q0	BUFFER[5752]	// (internal1_m1646_q0) q0 - внутренний параметр
#define idinternal1_m1646_q0	1170	// (internal1_m1646_q0) q0 - внутренний параметр
#define internal1_m1648_q0	BUFFER[5754]	// (internal1_m1648_q0) q0 - внутренний параметр
#define idinternal1_m1648_q0	1171	// (internal1_m1648_q0) q0 - внутренний параметр
#define internal1_m1651_fef	BUFFER[5759]	// (internal1_m1651_fef) FirstEnterFlag
#define idinternal1_m1651_fef	1172	// (internal1_m1651_fef) FirstEnterFlag
#define internal1_m1651_x0	BUFFER[5761]	// (internal1_m1651_x0) был приход сигнала x1
#define idinternal1_m1651_x0	1173	// (internal1_m1651_x0) был приход сигнала x1
#define internal1_m1651_y0	BUFFER[5763]	// (internal1_m1651_y0) интервал между сигналами х1 и х2
#define idinternal1_m1651_y0	1174	// (internal1_m1651_y0) интервал между сигналами х1 и х2
#define internal1_m1664_q0	BUFFER[5768]	// (internal1_m1664_q0) q0 - внутренний параметр
#define idinternal1_m1664_q0	1175	// (internal1_m1664_q0) q0 - внутренний параметр
#define internal1_m1677_tx	BUFFER[5770]	// (internal1_m1677_tx) tx - время накопленное сек
#define idinternal1_m1677_tx	1176	// (internal1_m1677_tx) tx - время накопленное сек
#define internal1_m1677_y0	BUFFER[5775]	// (internal1_m1677_y0) y0
#define idinternal1_m1677_y0	1177	// (internal1_m1677_y0) y0
#define internal1_m1679_q0	BUFFER[5777]	// (internal1_m1679_q0) q0 - внутренний параметр
#define idinternal1_m1679_q0	1178	// (internal1_m1679_q0) q0 - внутренний параметр
#define internal1_m1684_q0	BUFFER[5779]	// (internal1_m1684_q0) q0 - внутренний параметр
#define idinternal1_m1684_q0	1179	// (internal1_m1684_q0) q0 - внутренний параметр
#define internal1_m1685_tim	BUFFER[5781]	// (internal1_m1685_tim) - время задержки выходного сигнала
#define idinternal1_m1685_tim	1180	// (internal1_m1685_tim) - время задержки выходного сигнала
#define internal1_m1685_x0	BUFFER[5786]	// (internal1_m1685_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m1685_x0	1181	// (internal1_m1685_x0) - значение входного параметра на предыдущем шаге
#define internal1_m1686_q0	BUFFER[5788]	// (internal1_m1686_q0) q0 - внутренний параметр
#define idinternal1_m1686_q0	1182	// (internal1_m1686_q0) q0 - внутренний параметр
#define internal1_m1688_tim	BUFFER[5793]	// (internal1_m1688_tim) - время задержки выходного сигнала
#define idinternal1_m1688_tim	1183	// (internal1_m1688_tim) - время задержки выходного сигнала
#define internal1_m1688_x0	BUFFER[5798]	// (internal1_m1688_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m1688_x0	1184	// (internal1_m1688_x0) - значение входного параметра на предыдущем шаге
#define internal1_m1689_q0	BUFFER[5800]	// (internal1_m1689_q0) q0 - внутренний параметр
#define idinternal1_m1689_q0	1185	// (internal1_m1689_q0) q0 - внутренний параметр
#define internal1_m1696_tx	BUFFER[5805]	// (internal1_m1696_tx) tx - время накопленное сек
#define idinternal1_m1696_tx	1186	// (internal1_m1696_tx) tx - время накопленное сек
#define internal1_m1696_y0	BUFFER[5810]	// (internal1_m1696_y0) y0
#define idinternal1_m1696_y0	1187	// (internal1_m1696_y0) y0
#define internal1_m1699_q0	BUFFER[5812]	// (internal1_m1699_q0) q0 - внутренний параметр
#define idinternal1_m1699_q0	1188	// (internal1_m1699_q0) q0 - внутренний параметр
#define internal1_m1700_fef	BUFFER[5814]	// (internal1_m1700_fef) FirstEnterFlag
#define idinternal1_m1700_fef	1189	// (internal1_m1700_fef) FirstEnterFlag
#define internal1_m1700_x0	BUFFER[5816]	// (internal1_m1700_x0) был приход сигнала x1
#define idinternal1_m1700_x0	1190	// (internal1_m1700_x0) был приход сигнала x1
#define internal1_m1700_y0	BUFFER[5818]	// (internal1_m1700_y0) интервал между сигналами х1 и х2
#define idinternal1_m1700_y0	1191	// (internal1_m1700_y0) интервал между сигналами х1 и х2
#define internal1_m1702_tx	BUFFER[5823]	// (internal1_m1702_tx) tx - время накопленное сек
#define idinternal1_m1702_tx	1192	// (internal1_m1702_tx) tx - время накопленное сек
#define internal1_m1702_y0	BUFFER[5828]	// (internal1_m1702_y0) y0
#define idinternal1_m1702_y0	1193	// (internal1_m1702_y0) y0
#define internal1_m1705_fef	BUFFER[5830]	// (internal1_m1705_fef) FirstEnterFlag
#define idinternal1_m1705_fef	1194	// (internal1_m1705_fef) FirstEnterFlag
#define internal1_m1705_x0	BUFFER[5832]	// (internal1_m1705_x0) был приход сигнала x1
#define idinternal1_m1705_x0	1195	// (internal1_m1705_x0) был приход сигнала x1
#define internal1_m1705_y0	BUFFER[5834]	// (internal1_m1705_y0) интервал между сигналами х1 и х2
#define idinternal1_m1705_y0	1196	// (internal1_m1705_y0) интервал между сигналами х1 и х2
#define internal1_m1706_q0	BUFFER[5839]	// (internal1_m1706_q0) q0 - внутренний параметр
#define idinternal1_m1706_q0	1197	// (internal1_m1706_q0) q0 - внутренний параметр
#define internal1_m1720_q0	BUFFER[5841]	// (internal1_m1720_q0) q0 - внутренний параметр
#define idinternal1_m1720_q0	1198	// (internal1_m1720_q0) q0 - внутренний параметр
#define internal1_m1721_q0	BUFFER[5843]	// (internal1_m1721_q0) q0 - внутренний параметр
#define idinternal1_m1721_q0	1199	// (internal1_m1721_q0) q0 - внутренний параметр
#define internal1_m176_BLDv0	BUFFER[5845]	// (internal1_m176_BLDv0) BlDv - Блокировка движения
#define idinternal1_m176_BLDv0	1200	// (internal1_m176_BLDv0) BlDv - Блокировка движения
#define internal1_m176_X0	BUFFER[5847]	// (internal1_m176_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m176_X0	1201	// (internal1_m176_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m176_t0	BUFFER[5852]	// (internal1_m176_t0) время нахождения в зоне возврата
#define idinternal1_m176_t0	1202	// (internal1_m176_t0) время нахождения в зоне возврата
#define internal1_m1772_tx	BUFFER[5857]	// (internal1_m1772_tx) tx - внутренний параметр
#define idinternal1_m1772_tx	1203	// (internal1_m1772_tx) tx - внутренний параметр
#define internal1_m1773_tx	BUFFER[5862]	// (internal1_m1773_tx) tx - внутренний параметр
#define idinternal1_m1773_tx	1204	// (internal1_m1773_tx) tx - внутренний параметр
#define internal1_m1775_tx	BUFFER[5867]	// (internal1_m1775_tx) tx - внутренний параметр
#define idinternal1_m1775_tx	1205	// (internal1_m1775_tx) tx - внутренний параметр
#define internal1_m1777_tx	BUFFER[5872]	// (internal1_m1777_tx) tx - внутренний параметр
#define idinternal1_m1777_tx	1206	// (internal1_m1777_tx) tx - внутренний параметр
#define internal1_m1786_tx	BUFFER[5877]	// (internal1_m1786_tx) tx - внутренний параметр
#define idinternal1_m1786_tx	1207	// (internal1_m1786_tx) tx - внутренний параметр
#define internal1_m1791_tx	BUFFER[5882]	// (internal1_m1791_tx) tx - внутренний параметр
#define idinternal1_m1791_tx	1208	// (internal1_m1791_tx) tx - внутренний параметр
#define internal1_m1792_tx	BUFFER[5887]	// (internal1_m1792_tx) tx - внутренний параметр
#define idinternal1_m1792_tx	1209	// (internal1_m1792_tx) tx - внутренний параметр
#define internal1_m1794_tx	BUFFER[5892]	// (internal1_m1794_tx) tx - внутренний параметр
#define idinternal1_m1794_tx	1210	// (internal1_m1794_tx) tx - внутренний параметр
#define internal1_m1804_BLDv0	BUFFER[5897]	// (internal1_m1804_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1804_BLDv0	1211	// (internal1_m1804_BLDv0) BlDv - Блокировка движения
#define internal1_m1804_X0	BUFFER[5899]	// (internal1_m1804_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1804_X0	1212	// (internal1_m1804_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1804_t0	BUFFER[5904]	// (internal1_m1804_t0) время нахождения в зоне возврата
#define idinternal1_m1804_t0	1213	// (internal1_m1804_t0) время нахождения в зоне возврата
#define internal1_m1807_BlDv0	BUFFER[5909]	// (internal1_m1807_BlDv0) - была блокировка
#define idinternal1_m1807_BlDv0	1214	// (internal1_m1807_BlDv0) - была блокировка
#define internal1_m1807_DvDw0	BUFFER[5911]	// (internal1_m1807_DvDw0) - есть команда на движение назад
#define idinternal1_m1807_DvDw0	1215	// (internal1_m1807_DvDw0) - есть команда на движение назад
#define internal1_m1807_DvUp0	BUFFER[5913]	// (internal1_m1807_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1807_DvUp0	1216	// (internal1_m1807_DvUp0) - есть команда на движение вперёд
#define internal1_m1807_FDvDw0	BUFFER[5915]	// (internal1_m1807_FDvDw0) - есть команда на движение назад
#define idinternal1_m1807_FDvDw0	1217	// (internal1_m1807_FDvDw0) - есть команда на движение назад
#define internal1_m1807_FDvUp0	BUFFER[5917]	// (internal1_m1807_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1807_FDvUp0	1218	// (internal1_m1807_FDvUp0) - есть команда на движение вперёд
#define internal1_m1807_Pkav0	BUFFER[5919]	// (internal1_m1807_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1807_Pkav0	1219	// (internal1_m1807_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1807_Pkv0	BUFFER[5921]	// (internal1_m1807_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1807_Pkv0	1220	// (internal1_m1807_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1807_Zkav0	BUFFER[5923]	// (internal1_m1807_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1807_Zkav0	1221	// (internal1_m1807_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1807_Zkv0	BUFFER[5925]	// (internal1_m1807_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1807_Zkv0	1222	// (internal1_m1807_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1807_fef	BUFFER[5927]	// (internal1_m1807_fef) fef
#define idinternal1_m1807_fef	1223	// (internal1_m1807_fef) fef
#define internal1_m1807_txHr	BUFFER[5929]	// (internal1_m1807_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1807_txHr	1224	// (internal1_m1807_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1807_txLd	BUFFER[5934]	// (internal1_m1807_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1807_txLd	1225	// (internal1_m1807_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1807_txNm	BUFFER[5939]	// (internal1_m1807_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1807_txNm	1226	// (internal1_m1807_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1807_txSm	BUFFER[5944]	// (internal1_m1807_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1807_txSm	1227	// (internal1_m1807_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1808_tx	BUFFER[5949]	// (internal1_m1808_tx) tx - внутренний параметр
#define idinternal1_m1808_tx	1228	// (internal1_m1808_tx) tx - внутренний параметр
#define internal1_m1813_tx	BUFFER[5954]	// (internal1_m1813_tx) tx - внутренний параметр
#define idinternal1_m1813_tx	1229	// (internal1_m1813_tx) tx - внутренний параметр
#define internal1_m1818_tx	BUFFER[5959]	// (internal1_m1818_tx) tx - время накопленное сек
#define idinternal1_m1818_tx	1230	// (internal1_m1818_tx) tx - время накопленное сек
#define internal1_m1818_y0	BUFFER[5964]	// (internal1_m1818_y0) y0
#define idinternal1_m1818_y0	1231	// (internal1_m1818_y0) y0
#define internal1_m1819_tx	BUFFER[5966]	// (internal1_m1819_tx) tx - внутренний параметр
#define idinternal1_m1819_tx	1232	// (internal1_m1819_tx) tx - внутренний параметр
#define internal1_m1821_tx	BUFFER[5971]	// (internal1_m1821_tx) tx - внутренний параметр
#define idinternal1_m1821_tx	1233	// (internal1_m1821_tx) tx - внутренний параметр
#define internal1_m1822_tx	BUFFER[5976]	// (internal1_m1822_tx) tx - время накопленное сек
#define idinternal1_m1822_tx	1234	// (internal1_m1822_tx) tx - время накопленное сек
#define internal1_m1822_y0	BUFFER[5981]	// (internal1_m1822_y0) y0
#define idinternal1_m1822_y0	1235	// (internal1_m1822_y0) y0
#define internal1_m1826_DelSp	BUFFER[5983]	// (internal1_m1826_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1826_DelSp	1236	// (internal1_m1826_DelSp) DelSp - время переключения скоростей
#define internal1_m1826_ShCntlSp0	BUFFER[5988]	// (internal1_m1826_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1826_ShCntlSp0	1237	// (internal1_m1826_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1826_Shift0	BUFFER[5990]	// (internal1_m1826_Shift0) Shift0 - признак самохода
#define idinternal1_m1826_Shift0	1238	// (internal1_m1826_Shift0) Shift0 - признак самохода
#define internal1_m1826_ShiftControl	BUFFER[5992]	// (internal1_m1826_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1826_ShiftControl	1239	// (internal1_m1826_ShiftControl) ShiftControl - признак самохода
#define internal1_m1826_Speed0	BUFFER[5994]	// (internal1_m1826_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1826_Speed0	1240	// (internal1_m1826_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1826_StSpeed	BUFFER[5999]	// (internal1_m1826_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1826_StSpeed	1241	// (internal1_m1826_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1826_Vz0	BUFFER[6004]	// (internal1_m1826_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1826_Vz0	1242	// (internal1_m1826_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1826_flRazg	BUFFER[6009]	// (internal1_m1826_flRazg) признак разгона/торможения
#define idinternal1_m1826_flRazg	1243	// (internal1_m1826_flRazg) признак разгона/торможения
#define internal1_m1826_sumtim	BUFFER[6012]	// (internal1_m1826_sumtim) sumtim - время в пути
#define idinternal1_m1826_sumtim	1244	// (internal1_m1826_sumtim) sumtim - время в пути
#define internal1_m1826_tim0	BUFFER[6017]	// (internal1_m1826_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1826_tim0	1245	// (internal1_m1826_tim0) tim0 - массив значений времени цикла
#define internal1_m1826_tx	BUFFER[6117]	// (internal1_m1826_tx) tx
#define idinternal1_m1826_tx	1246	// (internal1_m1826_tx) tx
#define internal1_m1826_txBl	BUFFER[6122]	// (internal1_m1826_txBl) tx
#define idinternal1_m1826_txBl	1247	// (internal1_m1826_txBl) tx
#define internal1_m1826_txMBl	BUFFER[6127]	// (internal1_m1826_txMBl) tx
#define idinternal1_m1826_txMBl	1248	// (internal1_m1826_txMBl) tx
#define internal1_m1826_txZS	BUFFER[6132]	// (internal1_m1826_txZS) txZS
#define idinternal1_m1826_txZS	1249	// (internal1_m1826_txZS) txZS
#define internal1_m1826_txd	BUFFER[6137]	// (internal1_m1826_txd) txd
#define idinternal1_m1826_txd	1250	// (internal1_m1826_txd) txd
#define internal1_m1826_tz0	BUFFER[6142]	// (internal1_m1826_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1826_tz0	1251	// (internal1_m1826_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1826_x0	BUFFER[6147]	// (internal1_m1826_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1826_x0	1252	// (internal1_m1826_x0) x0 - массив мгновенных значений координат
#define internal1_m1826_xptr	BUFFER[6247]	// (internal1_m1826_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1826_xptr	1253	// (internal1_m1826_xptr) указатель текущей позиции в массиве координат
#define internal1_m1826_xz0	BUFFER[6250]	// (internal1_m1826_xz0) xz0 - новое задание мм
#define idinternal1_m1826_xz0	1254	// (internal1_m1826_xz0) xz0 - новое задание мм
#define internal1_m1826_z0	BUFFER[6255]	// (internal1_m1826_z0) z0 - точка прекращения движения
#define idinternal1_m1826_z0	1255	// (internal1_m1826_z0) z0 - точка прекращения движения
#define internal1_m1828_tx	BUFFER[6260]	// (internal1_m1828_tx) tx - внутренний параметр
#define idinternal1_m1828_tx	1256	// (internal1_m1828_tx) tx - внутренний параметр
#define internal1_m1829_tx	BUFFER[6265]	// (internal1_m1829_tx) tx - внутренний параметр
#define idinternal1_m1829_tx	1257	// (internal1_m1829_tx) tx - внутренний параметр
#define internal1_m1832_tx	BUFFER[6270]	// (internal1_m1832_tx) tx - время накопленное сек
#define idinternal1_m1832_tx	1258	// (internal1_m1832_tx) tx - время накопленное сек
#define internal1_m1832_y0	BUFFER[6275]	// (internal1_m1832_y0) y0
#define idinternal1_m1832_y0	1259	// (internal1_m1832_y0) y0
#define internal1_m1850_q0	BUFFER[6277]	// (internal1_m1850_q0) q0 - внутренний параметр
#define idinternal1_m1850_q0	1260	// (internal1_m1850_q0) q0 - внутренний параметр
#define internal1_m1852_q0	BUFFER[6279]	// (internal1_m1852_q0) q0 - внутренний параметр
#define idinternal1_m1852_q0	1261	// (internal1_m1852_q0) q0 - внутренний параметр
#define internal1_m1853_q0	BUFFER[6281]	// (internal1_m1853_q0) q0 - внутренний параметр
#define idinternal1_m1853_q0	1262	// (internal1_m1853_q0) q0 - внутренний параметр
#define internal1_m1855_q0	BUFFER[6283]	// (internal1_m1855_q0) q0 - внутренний параметр
#define idinternal1_m1855_q0	1263	// (internal1_m1855_q0) q0 - внутренний параметр
#define internal1_m1856_q0	BUFFER[6285]	// (internal1_m1856_q0) q0 - внутренний параметр
#define idinternal1_m1856_q0	1264	// (internal1_m1856_q0) q0 - внутренний параметр
#define internal1_m1858_q0	BUFFER[6287]	// (internal1_m1858_q0) q0 - внутренний параметр
#define idinternal1_m1858_q0	1265	// (internal1_m1858_q0) q0 - внутренний параметр
#define internal1_m1860_q0	BUFFER[6289]	// (internal1_m1860_q0) q0 - внутренний параметр
#define idinternal1_m1860_q0	1266	// (internal1_m1860_q0) q0 - внутренний параметр
#define internal1_m1862_q0	BUFFER[6291]	// (internal1_m1862_q0) q0 - внутренний параметр
#define idinternal1_m1862_q0	1267	// (internal1_m1862_q0) q0 - внутренний параметр
#define internal1_m1864_q0	BUFFER[6293]	// (internal1_m1864_q0) q0 - внутренний параметр
#define idinternal1_m1864_q0	1268	// (internal1_m1864_q0) q0 - внутренний параметр
#define internal1_m1865_q0	BUFFER[6295]	// (internal1_m1865_q0) q0 - внутренний параметр
#define idinternal1_m1865_q0	1269	// (internal1_m1865_q0) q0 - внутренний параметр
#define internal1_m1866_q0	BUFFER[6297]	// (internal1_m1866_q0) q0 - внутренний параметр
#define idinternal1_m1866_q0	1270	// (internal1_m1866_q0) q0 - внутренний параметр
#define internal1_m1867_q0	BUFFER[6299]	// (internal1_m1867_q0) q0 - внутренний параметр
#define idinternal1_m1867_q0	1271	// (internal1_m1867_q0) q0 - внутренний параметр
#define internal1_m1876_q0	BUFFER[6301]	// (internal1_m1876_q0) q0 - внутренний параметр
#define idinternal1_m1876_q0	1272	// (internal1_m1876_q0) q0 - внутренний параметр
#define internal1_m1878_q0	BUFFER[6303]	// (internal1_m1878_q0) q0 - внутренний параметр
#define idinternal1_m1878_q0	1273	// (internal1_m1878_q0) q0 - внутренний параметр
#define internal1_m1880_q0	BUFFER[6305]	// (internal1_m1880_q0) q0 - внутренний параметр
#define idinternal1_m1880_q0	1274	// (internal1_m1880_q0) q0 - внутренний параметр
#define internal1_m1882_q0	BUFFER[6307]	// (internal1_m1882_q0) q0 - внутренний параметр
#define idinternal1_m1882_q0	1275	// (internal1_m1882_q0) q0 - внутренний параметр
#define internal1_m1884_q0	BUFFER[6309]	// (internal1_m1884_q0) q0 - внутренний параметр
#define idinternal1_m1884_q0	1276	// (internal1_m1884_q0) q0 - внутренний параметр
#define internal1_m1886_q0	BUFFER[6311]	// (internal1_m1886_q0) q0 - внутренний параметр
#define idinternal1_m1886_q0	1277	// (internal1_m1886_q0) q0 - внутренний параметр
#define internal1_m1888_q0	BUFFER[6313]	// (internal1_m1888_q0) q0 - внутренний параметр
#define idinternal1_m1888_q0	1278	// (internal1_m1888_q0) q0 - внутренний параметр
#define internal1_m1890_q0	BUFFER[6315]	// (internal1_m1890_q0) q0 - внутренний параметр
#define idinternal1_m1890_q0	1279	// (internal1_m1890_q0) q0 - внутренний параметр
#define internal1_m1898_q0	BUFFER[6317]	// (internal1_m1898_q0) q0 - внутренний параметр
#define idinternal1_m1898_q0	1280	// (internal1_m1898_q0) q0 - внутренний параметр
#define internal1_m1899_q0	BUFFER[6319]	// (internal1_m1899_q0) q0 - внутренний параметр
#define idinternal1_m1899_q0	1281	// (internal1_m1899_q0) q0 - внутренний параметр
#define internal1_m1900_q0	BUFFER[6321]	// (internal1_m1900_q0) q0 - внутренний параметр
#define idinternal1_m1900_q0	1282	// (internal1_m1900_q0) q0 - внутренний параметр
#define internal1_m1907_q0	BUFFER[6323]	// (internal1_m1907_q0) q0 - внутренний параметр
#define idinternal1_m1907_q0	1283	// (internal1_m1907_q0) q0 - внутренний параметр
#define internal1_m1909_q0	BUFFER[6325]	// (internal1_m1909_q0) q0 - внутренний параметр
#define idinternal1_m1909_q0	1284	// (internal1_m1909_q0) q0 - внутренний параметр
#define internal1_m1911_q0	BUFFER[6327]	// (internal1_m1911_q0) q0 - внутренний параметр
#define idinternal1_m1911_q0	1285	// (internal1_m1911_q0) q0 - внутренний параметр
#define internal1_m1913_q0	BUFFER[6329]	// (internal1_m1913_q0) q0 - внутренний параметр
#define idinternal1_m1913_q0	1286	// (internal1_m1913_q0) q0 - внутренний параметр
#define internal1_m1915_q0	BUFFER[6331]	// (internal1_m1915_q0) q0 - внутренний параметр
#define idinternal1_m1915_q0	1287	// (internal1_m1915_q0) q0 - внутренний параметр
#define internal1_m1917_q0	BUFFER[6333]	// (internal1_m1917_q0) q0 - внутренний параметр
#define idinternal1_m1917_q0	1288	// (internal1_m1917_q0) q0 - внутренний параметр
#define internal1_m1920_q0	BUFFER[6335]	// (internal1_m1920_q0) q0 - внутренний параметр
#define idinternal1_m1920_q0	1289	// (internal1_m1920_q0) q0 - внутренний параметр
#define internal1_m1923_q0	BUFFER[6337]	// (internal1_m1923_q0) q0 - внутренний параметр
#define idinternal1_m1923_q0	1290	// (internal1_m1923_q0) q0 - внутренний параметр
#define internal1_m1925_q0	BUFFER[6339]	// (internal1_m1925_q0) q0 - внутренний параметр
#define idinternal1_m1925_q0	1291	// (internal1_m1925_q0) q0 - внутренний параметр
#define internal1_m1928_q0	BUFFER[6341]	// (internal1_m1928_q0) q0 - внутренний параметр
#define idinternal1_m1928_q0	1292	// (internal1_m1928_q0) q0 - внутренний параметр
#define internal1_m1934_MyFirstEnterFlag	BUFFER[6343]	// (internal1_m1934_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1934_MyFirstEnterFlag	1293	// (internal1_m1934_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m1934_Pv0	BUFFER[6345]	// (internal1_m1934_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1934_Pv0	1294	// (internal1_m1934_Pv0)  - Пер. выключатель механизма
#define internal1_m1934_Zv0	BUFFER[6347]	// (internal1_m1934_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1934_Zv0	1295	// (internal1_m1934_Zv0)  - Зад. выключатель механизма
#define internal1_m1937_MyFirstEnterFlag	BUFFER[6349]	// (internal1_m1937_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1937_MyFirstEnterFlag	1296	// (internal1_m1937_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m1937_Pv0	BUFFER[6351]	// (internal1_m1937_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1937_Pv0	1297	// (internal1_m1937_Pv0)  - Пер. выключатель механизма
#define internal1_m1937_Zv0	BUFFER[6353]	// (internal1_m1937_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1937_Zv0	1298	// (internal1_m1937_Zv0)  - Зад. выключатель механизма
#define internal1_m193_tx	BUFFER[6355]	// (internal1_m193_tx) tx - время накопленное сек
#define idinternal1_m193_tx	1299	// (internal1_m193_tx) tx - время накопленное сек
#define internal1_m193_y0	BUFFER[6360]	// (internal1_m193_y0) y0
#define idinternal1_m193_y0	1300	// (internal1_m193_y0) y0
#define internal1_m1947_q0	BUFFER[6362]	// (internal1_m1947_q0) q0 - внутренний параметр
#define idinternal1_m1947_q0	1301	// (internal1_m1947_q0) q0 - внутренний параметр
#define internal1_m194_tx	BUFFER[6364]	// (internal1_m194_tx) tx - время накопленное сек
#define idinternal1_m194_tx	1302	// (internal1_m194_tx) tx - время накопленное сек
#define internal1_m194_y0	BUFFER[6369]	// (internal1_m194_y0) y0
#define idinternal1_m194_y0	1303	// (internal1_m194_y0) y0
#define internal1_m1950_q0	BUFFER[6371]	// (internal1_m1950_q0) q0 - внутренний параметр
#define idinternal1_m1950_q0	1304	// (internal1_m1950_q0) q0 - внутренний параметр
#define internal1_m1954_q0	BUFFER[6373]	// (internal1_m1954_q0) q0 - внутренний параметр
#define idinternal1_m1954_q0	1305	// (internal1_m1954_q0) q0 - внутренний параметр
#define internal1_m1957_q0	BUFFER[6375]	// (internal1_m1957_q0) q0 - внутренний параметр
#define idinternal1_m1957_q0	1306	// (internal1_m1957_q0) q0 - внутренний параметр
#define internal1_m1960_q0	BUFFER[6377]	// (internal1_m1960_q0) q0 - внутренний параметр
#define idinternal1_m1960_q0	1307	// (internal1_m1960_q0) q0 - внутренний параметр
#define internal1_m1962_q0	BUFFER[6379]	// (internal1_m1962_q0) q0 - внутренний параметр
#define idinternal1_m1962_q0	1308	// (internal1_m1962_q0) q0 - внутренний параметр
#define internal1_m19_q0	BUFFER[6381]	// (internal1_m19_q0) q0 - внутренний параметр
#define idinternal1_m19_q0	1309	// (internal1_m19_q0) q0 - внутренний параметр
#define internal1_m201_DelSp	BUFFER[6383]	// (internal1_m201_DelSp) DelSp - время переключения скоростей
#define idinternal1_m201_DelSp	1310	// (internal1_m201_DelSp) DelSp - время переключения скоростей
#define internal1_m201_ShCntlSp0	BUFFER[6388]	// (internal1_m201_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m201_ShCntlSp0	1311	// (internal1_m201_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m201_Shift0	BUFFER[6390]	// (internal1_m201_Shift0) Shift0 - признак самохода
#define idinternal1_m201_Shift0	1312	// (internal1_m201_Shift0) Shift0 - признак самохода
#define internal1_m201_ShiftControl	BUFFER[6392]	// (internal1_m201_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m201_ShiftControl	1313	// (internal1_m201_ShiftControl) ShiftControl - признак самохода
#define internal1_m201_Speed0	BUFFER[6394]	// (internal1_m201_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m201_Speed0	1314	// (internal1_m201_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m201_StSpeed	BUFFER[6399]	// (internal1_m201_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m201_StSpeed	1315	// (internal1_m201_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m201_Vz0	BUFFER[6404]	// (internal1_m201_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m201_Vz0	1316	// (internal1_m201_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m201_flRazg	BUFFER[6409]	// (internal1_m201_flRazg) признак разгона/торможения
#define idinternal1_m201_flRazg	1317	// (internal1_m201_flRazg) признак разгона/торможения
#define internal1_m201_sumtim	BUFFER[6412]	// (internal1_m201_sumtim) sumtim - время в пути
#define idinternal1_m201_sumtim	1318	// (internal1_m201_sumtim) sumtim - время в пути
#define internal1_m201_tim0	BUFFER[6417]	// (internal1_m201_tim0) tim0 - массив значений времени цикла
#define idinternal1_m201_tim0	1319	// (internal1_m201_tim0) tim0 - массив значений времени цикла
#define internal1_m201_tx	BUFFER[7167]	// (internal1_m201_tx) tx
#define idinternal1_m201_tx	1320	// (internal1_m201_tx) tx
#define internal1_m201_txBl	BUFFER[7172]	// (internal1_m201_txBl) tx
#define idinternal1_m201_txBl	1321	// (internal1_m201_txBl) tx
#define internal1_m201_txMBl	BUFFER[7177]	// (internal1_m201_txMBl) tx
#define idinternal1_m201_txMBl	1322	// (internal1_m201_txMBl) tx
#define internal1_m201_txZS	BUFFER[7182]	// (internal1_m201_txZS) txZS
#define idinternal1_m201_txZS	1323	// (internal1_m201_txZS) txZS
#define internal1_m201_txd	BUFFER[7187]	// (internal1_m201_txd) txd
#define idinternal1_m201_txd	1324	// (internal1_m201_txd) txd
#define internal1_m201_tz0	BUFFER[7192]	// (internal1_m201_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m201_tz0	1325	// (internal1_m201_tz0) tz0 - время защиты от нового задания сек
#define internal1_m201_x0	BUFFER[7197]	// (internal1_m201_x0) x0 - массив мгновенных значений координат
#define idinternal1_m201_x0	1326	// (internal1_m201_x0) x0 - массив мгновенных значений координат
#define internal1_m201_xptr	BUFFER[7947]	// (internal1_m201_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m201_xptr	1327	// (internal1_m201_xptr) указатель текущей позиции в массиве координат
#define internal1_m201_xz0	BUFFER[7950]	// (internal1_m201_xz0) xz0 - новое задание мм
#define idinternal1_m201_xz0	1328	// (internal1_m201_xz0) xz0 - новое задание мм
#define internal1_m201_z0	BUFFER[7955]	// (internal1_m201_z0) z0 - точка прекращения движения
#define idinternal1_m201_z0	1329	// (internal1_m201_z0) z0 - точка прекращения движения
#define internal1_m2027_tx	BUFFER[7960]	// (internal1_m2027_tx) tx - время накопленное сек
#define idinternal1_m2027_tx	1330	// (internal1_m2027_tx) tx - время накопленное сек
#define internal1_m2027_y0	BUFFER[7965]	// (internal1_m2027_y0) y0
#define idinternal1_m2027_y0	1331	// (internal1_m2027_y0) y0
#define internal1_m2028_tx	BUFFER[7967]	// (internal1_m2028_tx) tx - время накопленное сек
#define idinternal1_m2028_tx	1332	// (internal1_m2028_tx) tx - время накопленное сек
#define internal1_m2028_y0	BUFFER[7972]	// (internal1_m2028_y0) y0
#define idinternal1_m2028_y0	1333	// (internal1_m2028_y0) y0
#define internal1_m2029_tx	BUFFER[7974]	// (internal1_m2029_tx) tx - время накопленное сек
#define idinternal1_m2029_tx	1334	// (internal1_m2029_tx) tx - время накопленное сек
#define internal1_m2029_y0	BUFFER[7979]	// (internal1_m2029_y0) y0
#define idinternal1_m2029_y0	1335	// (internal1_m2029_y0) y0
#define internal1_m202_tx	BUFFER[7981]	// (internal1_m202_tx) tx - внутренний параметр
#define idinternal1_m202_tx	1336	// (internal1_m202_tx) tx - внутренний параметр
#define internal1_m2030_tx	BUFFER[7986]	// (internal1_m2030_tx) tx - время накопленное сек
#define idinternal1_m2030_tx	1337	// (internal1_m2030_tx) tx - время накопленное сек
#define internal1_m2030_y0	BUFFER[7991]	// (internal1_m2030_y0) y0
#define idinternal1_m2030_y0	1338	// (internal1_m2030_y0) y0
#define internal1_m203_tx	BUFFER[7993]	// (internal1_m203_tx) tx - внутренний параметр
#define idinternal1_m203_tx	1339	// (internal1_m203_tx) tx - внутренний параметр
#define internal1_m204_tx	BUFFER[7998]	// (internal1_m204_tx) tx - внутренний параметр
#define idinternal1_m204_tx	1340	// (internal1_m204_tx) tx - внутренний параметр
#define internal1_m2065_tx	BUFFER[8003]	// (internal1_m2065_tx) tx - внутренний параметр
#define idinternal1_m2065_tx	1341	// (internal1_m2065_tx) tx - внутренний параметр
#define internal1_m2066_tx	BUFFER[8008]	// (internal1_m2066_tx) tx - внутренний параметр
#define idinternal1_m2066_tx	1342	// (internal1_m2066_tx) tx - внутренний параметр
#define internal1_m2072_tim	BUFFER[8013]	// (internal1_m2072_tim) - время задержки выходного сигнала
#define idinternal1_m2072_tim	1343	// (internal1_m2072_tim) - время задержки выходного сигнала
#define internal1_m2072_x0	BUFFER[8018]	// (internal1_m2072_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m2072_x0	1344	// (internal1_m2072_x0) - значение входного параметра на предыдущем шаге
#define internal1_m2073_q0	BUFFER[8020]	// (internal1_m2073_q0) q0 - внутренний параметр
#define idinternal1_m2073_q0	1345	// (internal1_m2073_q0) q0 - внутренний параметр
#define internal1_m2077_tx	BUFFER[8022]	// (internal1_m2077_tx) tx - время накопленное сек
#define idinternal1_m2077_tx	1346	// (internal1_m2077_tx) tx - время накопленное сек
#define internal1_m2077_y0	BUFFER[8027]	// (internal1_m2077_y0) y0
#define idinternal1_m2077_y0	1347	// (internal1_m2077_y0) y0
#define internal1_m2080_q0	BUFFER[8029]	// (internal1_m2080_q0) q0 - внутренний параметр
#define idinternal1_m2080_q0	1348	// (internal1_m2080_q0) q0 - внутренний параметр
#define internal1_m2082_fef	BUFFER[8031]	// (internal1_m2082_fef) FirstEnterFlag
#define idinternal1_m2082_fef	1349	// (internal1_m2082_fef) FirstEnterFlag
#define internal1_m2082_x0	BUFFER[8033]	// (internal1_m2082_x0) был приход сигнала x1
#define idinternal1_m2082_x0	1350	// (internal1_m2082_x0) был приход сигнала x1
#define internal1_m2082_y0	BUFFER[8035]	// (internal1_m2082_y0) интервал между сигналами х1 и х2
#define idinternal1_m2082_y0	1351	// (internal1_m2082_y0) интервал между сигналами х1 и х2
#define internal1_m2087_q0	BUFFER[8040]	// (internal1_m2087_q0) q0 - внутренний параметр
#define idinternal1_m2087_q0	1352	// (internal1_m2087_q0) q0 - внутренний параметр
#define internal1_m2091_q0	BUFFER[8042]	// (internal1_m2091_q0) q0 - внутренний параметр
#define idinternal1_m2091_q0	1353	// (internal1_m2091_q0) q0 - внутренний параметр
#define internal1_m2100_q0	BUFFER[8047]	// (internal1_m2100_q0) q0 - внутренний параметр
#define idinternal1_m2100_q0	1354	// (internal1_m2100_q0) q0 - внутренний параметр
#define internal1_m2101_tim	BUFFER[8049]	// (internal1_m2101_tim) - время задержки выходного сигнала
#define idinternal1_m2101_tim	1355	// (internal1_m2101_tim) - время задержки выходного сигнала
#define internal1_m2101_x0	BUFFER[8054]	// (internal1_m2101_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m2101_x0	1356	// (internal1_m2101_x0) - значение входного параметра на предыдущем шаге
#define internal1_m2109_tx	BUFFER[8056]	// (internal1_m2109_tx) tx - время накопленное сек
#define idinternal1_m2109_tx	1357	// (internal1_m2109_tx) tx - время накопленное сек
#define internal1_m2109_y0	BUFFER[8061]	// (internal1_m2109_y0) y0
#define idinternal1_m2109_y0	1358	// (internal1_m2109_y0) y0
#define internal1_m210_tx	BUFFER[8063]	// (internal1_m210_tx) tx - внутренний параметр
#define idinternal1_m210_tx	1359	// (internal1_m210_tx) tx - внутренний параметр
#define internal1_m2112_q0	BUFFER[8068]	// (internal1_m2112_q0) q0 - внутренний параметр
#define idinternal1_m2112_q0	1360	// (internal1_m2112_q0) q0 - внутренний параметр
#define internal1_m2121_tx	BUFFER[8070]	// (internal1_m2121_tx) tx - время накопленное сек
#define idinternal1_m2121_tx	1361	// (internal1_m2121_tx) tx - время накопленное сек
#define internal1_m2121_y0	BUFFER[8075]	// (internal1_m2121_y0) y0
#define idinternal1_m2121_y0	1362	// (internal1_m2121_y0) y0
#define internal1_m2123_fef	BUFFER[8077]	// (internal1_m2123_fef) FirstEnterFlag
#define idinternal1_m2123_fef	1363	// (internal1_m2123_fef) FirstEnterFlag
#define internal1_m2123_x0	BUFFER[8079]	// (internal1_m2123_x0) был приход сигнала x1
#define idinternal1_m2123_x0	1364	// (internal1_m2123_x0) был приход сигнала x1
#define internal1_m2123_y0	BUFFER[8081]	// (internal1_m2123_y0) интервал между сигналами х1 и х2
#define idinternal1_m2123_y0	1365	// (internal1_m2123_y0) интервал между сигналами х1 и х2
#define internal1_m2124_tx	BUFFER[8086]	// (internal1_m2124_tx) tx - время накопленное сек
#define idinternal1_m2124_tx	1366	// (internal1_m2124_tx) tx - время накопленное сек
#define internal1_m2124_y0	BUFFER[8091]	// (internal1_m2124_y0) y0
#define idinternal1_m2124_y0	1367	// (internal1_m2124_y0) y0
#define internal1_m2131_q0	BUFFER[8093]	// (internal1_m2131_q0) q0 - внутренний параметр
#define idinternal1_m2131_q0	1368	// (internal1_m2131_q0) q0 - внутренний параметр
#define internal1_m2141_q0	BUFFER[8098]	// (internal1_m2141_q0) q0 - внутренний параметр
#define idinternal1_m2141_q0	1369	// (internal1_m2141_q0) q0 - внутренний параметр
#define internal1_m2157_q0	BUFFER[8100]	// (internal1_m2157_q0) q0 - внутренний параметр
#define idinternal1_m2157_q0	1370	// (internal1_m2157_q0) q0 - внутренний параметр
#define internal1_m2158_q0	BUFFER[8102]	// (internal1_m2158_q0) q0 - внутренний параметр
#define idinternal1_m2158_q0	1371	// (internal1_m2158_q0) q0 - внутренний параметр
#define internal1_m215_tx	BUFFER[8104]	// (internal1_m215_tx) tx - время накопленное сек
#define idinternal1_m215_tx	1372	// (internal1_m215_tx) tx - время накопленное сек
#define internal1_m215_y0	BUFFER[8109]	// (internal1_m215_y0) y0
#define idinternal1_m215_y0	1373	// (internal1_m215_y0) y0
#define internal1_m2166_tx	BUFFER[8111]	// (internal1_m2166_tx) tx - внутренний параметр
#define idinternal1_m2166_tx	1374	// (internal1_m2166_tx) tx - внутренний параметр
#define internal1_m2169_tx	BUFFER[8116]	// (internal1_m2169_tx) tx - внутренний параметр
#define idinternal1_m2169_tx	1375	// (internal1_m2169_tx) tx - внутренний параметр
#define internal1_m2172_q0	BUFFER[8121]	// (internal1_m2172_q0) q0 - внутренний параметр
#define idinternal1_m2172_q0	1376	// (internal1_m2172_q0) q0 - внутренний параметр
#define internal1_m2179_tx	BUFFER[8123]	// (internal1_m2179_tx) tx - внутренний параметр
#define idinternal1_m2179_tx	1377	// (internal1_m2179_tx) tx - внутренний параметр
#define internal1_m2182_tx	BUFFER[8128]	// (internal1_m2182_tx) tx - внутренний параметр
#define idinternal1_m2182_tx	1378	// (internal1_m2182_tx) tx - внутренний параметр
#define internal1_m2184_q0	BUFFER[8133]	// (internal1_m2184_q0) q0 - внутренний параметр
#define idinternal1_m2184_q0	1379	// (internal1_m2184_q0) q0 - внутренний параметр
#define internal1_m2194_tx	BUFFER[8135]	// (internal1_m2194_tx) tx - внутренний параметр
#define idinternal1_m2194_tx	1380	// (internal1_m2194_tx) tx - внутренний параметр
#define internal1_m2197_tx	BUFFER[8140]	// (internal1_m2197_tx) tx - внутренний параметр
#define idinternal1_m2197_tx	1381	// (internal1_m2197_tx) tx - внутренний параметр
#define internal1_m21_tx	BUFFER[8145]	// (internal1_m21_tx) tx - внутренний параметр
#define idinternal1_m21_tx	1382	// (internal1_m21_tx) tx - внутренний параметр
#define internal1_m2200_q0	BUFFER[8150]	// (internal1_m2200_q0) q0 - внутренний параметр
#define idinternal1_m2200_q0	1383	// (internal1_m2200_q0) q0 - внутренний параметр
#define internal1_m2208_tx	BUFFER[8152]	// (internal1_m2208_tx) tx - внутренний параметр
#define idinternal1_m2208_tx	1384	// (internal1_m2208_tx) tx - внутренний параметр
#define internal1_m220_tx	BUFFER[8157]	// (internal1_m220_tx) tx - внутренний параметр
#define idinternal1_m220_tx	1385	// (internal1_m220_tx) tx - внутренний параметр
#define internal1_m2212_q0	BUFFER[8162]	// (internal1_m2212_q0) q0 - внутренний параметр
#define idinternal1_m2212_q0	1386	// (internal1_m2212_q0) q0 - внутренний параметр
#define internal1_m2218_tx	BUFFER[8164]	// (internal1_m2218_tx) tx - внутренний параметр
#define idinternal1_m2218_tx	1387	// (internal1_m2218_tx) tx - внутренний параметр
#define internal1_m221_tx	BUFFER[8169]	// (internal1_m221_tx) tx - время накопленное сек
#define idinternal1_m221_tx	1388	// (internal1_m221_tx) tx - время накопленное сек
#define internal1_m221_y0	BUFFER[8174]	// (internal1_m221_y0) y0
#define idinternal1_m221_y0	1389	// (internal1_m221_y0) y0
#define internal1_m2222_tx	BUFFER[8176]	// (internal1_m2222_tx) tx - внутренний параметр
#define idinternal1_m2222_tx	1390	// (internal1_m2222_tx) tx - внутренний параметр
#define internal1_m2228_q0	BUFFER[8181]	// (internal1_m2228_q0) q0 - внутренний параметр
#define idinternal1_m2228_q0	1391	// (internal1_m2228_q0) q0 - внутренний параметр
#define internal1_m2229_tx	BUFFER[8183]	// (internal1_m2229_tx) tx - время накопленное сек
#define idinternal1_m2229_tx	1392	// (internal1_m2229_tx) tx - время накопленное сек
#define internal1_m2229_y0	BUFFER[8188]	// (internal1_m2229_y0) y0
#define idinternal1_m2229_y0	1393	// (internal1_m2229_y0) y0
#define internal1_m2233_tx	BUFFER[8190]	// (internal1_m2233_tx) tx - внутренний параметр
#define idinternal1_m2233_tx	1394	// (internal1_m2233_tx) tx - внутренний параметр
#define internal1_m2236_q0	BUFFER[8195]	// (internal1_m2236_q0) q0 - внутренний параметр
#define idinternal1_m2236_q0	1395	// (internal1_m2236_q0) q0 - внутренний параметр
#define internal1_m2237_tx	BUFFER[8197]	// (internal1_m2237_tx) tx - время накопленное сек
#define idinternal1_m2237_tx	1396	// (internal1_m2237_tx) tx - время накопленное сек
#define internal1_m2237_y0	BUFFER[8202]	// (internal1_m2237_y0) y0
#define idinternal1_m2237_y0	1397	// (internal1_m2237_y0) y0
#define internal1_m2243_tx	BUFFER[8204]	// (internal1_m2243_tx) tx - внутренний параметр
#define idinternal1_m2243_tx	1398	// (internal1_m2243_tx) tx - внутренний параметр
#define internal1_m2251_tx	BUFFER[8209]	// (internal1_m2251_tx) tx - внутренний параметр
#define idinternal1_m2251_tx	1399	// (internal1_m2251_tx) tx - внутренний параметр
#define internal1_m2253_q0	BUFFER[8214]	// (internal1_m2253_q0) q0 - внутренний параметр
#define idinternal1_m2253_q0	1400	// (internal1_m2253_q0) q0 - внутренний параметр
#define internal1_m2260_tx	BUFFER[8216]	// (internal1_m2260_tx) tx - внутренний параметр
#define idinternal1_m2260_tx	1401	// (internal1_m2260_tx) tx - внутренний параметр
#define internal1_m2264_tx	BUFFER[8221]	// (internal1_m2264_tx) tx - время накопленное сек
#define idinternal1_m2264_tx	1402	// (internal1_m2264_tx) tx - время накопленное сек
#define internal1_m2264_y0	BUFFER[8226]	// (internal1_m2264_y0) y0
#define idinternal1_m2264_y0	1403	// (internal1_m2264_y0) y0
#define internal1_m2266_tx	BUFFER[8228]	// (internal1_m2266_tx) tx - внутренний параметр
#define idinternal1_m2266_tx	1404	// (internal1_m2266_tx) tx - внутренний параметр
#define internal1_m2269_q0	BUFFER[8233]	// (internal1_m2269_q0) q0 - внутренний параметр
#define idinternal1_m2269_q0	1405	// (internal1_m2269_q0) q0 - внутренний параметр
#define internal1_m2271_tx	BUFFER[8235]	// (internal1_m2271_tx) tx - внутренний параметр
#define idinternal1_m2271_tx	1406	// (internal1_m2271_tx) tx - внутренний параметр
#define internal1_m2272_tx	BUFFER[8240]	// (internal1_m2272_tx) tx - внутренний параметр
#define idinternal1_m2272_tx	1407	// (internal1_m2272_tx) tx - внутренний параметр
#define internal1_m2275_tx	BUFFER[8245]	// (internal1_m2275_tx) tx - время накопленное сек
#define idinternal1_m2275_tx	1408	// (internal1_m2275_tx) tx - время накопленное сек
#define internal1_m2275_y0	BUFFER[8250]	// (internal1_m2275_y0) y0
#define idinternal1_m2275_y0	1409	// (internal1_m2275_y0) y0
#define internal1_m2283_tx	BUFFER[8252]	// (internal1_m2283_tx) tx - внутренний параметр
#define idinternal1_m2283_tx	1410	// (internal1_m2283_tx) tx - внутренний параметр
#define internal1_m2284_tx	BUFFER[8257]	// (internal1_m2284_tx) tx - внутренний параметр
#define idinternal1_m2284_tx	1411	// (internal1_m2284_tx) tx - внутренний параметр
#define internal1_m2286_tx	BUFFER[8262]	// (internal1_m2286_tx) tx - внутренний параметр
#define idinternal1_m2286_tx	1412	// (internal1_m2286_tx) tx - внутренний параметр
#define internal1_m228_tx	BUFFER[8267]	// (internal1_m228_tx) tx - внутренний параметр
#define idinternal1_m228_tx	1413	// (internal1_m228_tx) tx - внутренний параметр
#define internal1_m2292_q0	BUFFER[8272]	// (internal1_m2292_q0) q0 - внутренний параметр
#define idinternal1_m2292_q0	1414	// (internal1_m2292_q0) q0 - внутренний параметр
#define internal1_m2294_q0	BUFFER[8274]	// (internal1_m2294_q0) q0 - внутренний параметр
#define idinternal1_m2294_q0	1415	// (internal1_m2294_q0) q0 - внутренний параметр
#define internal1_m2300_tx	BUFFER[8276]	// (internal1_m2300_tx) tx - внутренний параметр
#define idinternal1_m2300_tx	1416	// (internal1_m2300_tx) tx - внутренний параметр
#define internal1_m230_tx	BUFFER[8281]	// (internal1_m230_tx) tx - внутренний параметр
#define idinternal1_m230_tx	1417	// (internal1_m230_tx) tx - внутренний параметр
#define internal1_m2313_tx	BUFFER[8286]	// (internal1_m2313_tx) tx - внутренний параметр
#define idinternal1_m2313_tx	1418	// (internal1_m2313_tx) tx - внутренний параметр
#define internal1_m2314_tx	BUFFER[8291]	// (internal1_m2314_tx) tx - внутренний параметр
#define idinternal1_m2314_tx	1419	// (internal1_m2314_tx) tx - внутренний параметр
#define internal1_m2315_tx	BUFFER[8296]	// (internal1_m2315_tx) tx - внутренний параметр
#define idinternal1_m2315_tx	1420	// (internal1_m2315_tx) tx - внутренний параметр
#define internal1_m2319_BlDv0	BUFFER[8301]	// (internal1_m2319_BlDv0) - была блокировка
#define idinternal1_m2319_BlDv0	1421	// (internal1_m2319_BlDv0) - была блокировка
#define internal1_m2319_DvDw0	BUFFER[8303]	// (internal1_m2319_DvDw0) - есть команда на движение назад
#define idinternal1_m2319_DvDw0	1422	// (internal1_m2319_DvDw0) - есть команда на движение назад
#define internal1_m2319_DvUp0	BUFFER[8305]	// (internal1_m2319_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2319_DvUp0	1423	// (internal1_m2319_DvUp0) - есть команда на движение вперёд
#define internal1_m2319_FDvDw0	BUFFER[8307]	// (internal1_m2319_FDvDw0) - есть команда на движение назад
#define idinternal1_m2319_FDvDw0	1424	// (internal1_m2319_FDvDw0) - есть команда на движение назад
#define internal1_m2319_FDvUp0	BUFFER[8309]	// (internal1_m2319_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2319_FDvUp0	1425	// (internal1_m2319_FDvUp0) - есть команда на движение вперёд
#define internal1_m2319_Pkav0	BUFFER[8311]	// (internal1_m2319_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2319_Pkav0	1426	// (internal1_m2319_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2319_Pkv0	BUFFER[8313]	// (internal1_m2319_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2319_Pkv0	1427	// (internal1_m2319_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2319_Zkav0	BUFFER[8315]	// (internal1_m2319_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2319_Zkav0	1428	// (internal1_m2319_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2319_Zkv0	BUFFER[8317]	// (internal1_m2319_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2319_Zkv0	1429	// (internal1_m2319_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2319_fef	BUFFER[8319]	// (internal1_m2319_fef) fef
#define idinternal1_m2319_fef	1430	// (internal1_m2319_fef) fef
#define internal1_m2319_txHr	BUFFER[8321]	// (internal1_m2319_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2319_txHr	1431	// (internal1_m2319_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2319_txLd	BUFFER[8326]	// (internal1_m2319_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2319_txLd	1432	// (internal1_m2319_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2319_txNm	BUFFER[8331]	// (internal1_m2319_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2319_txNm	1433	// (internal1_m2319_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2319_txSm	BUFFER[8336]	// (internal1_m2319_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2319_txSm	1434	// (internal1_m2319_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2320_tx	BUFFER[8341]	// (internal1_m2320_tx) tx - внутренний параметр
#define idinternal1_m2320_tx	1435	// (internal1_m2320_tx) tx - внутренний параметр
#define internal1_m2325_BlDv0	BUFFER[8346]	// (internal1_m2325_BlDv0) - была блокировка
#define idinternal1_m2325_BlDv0	1436	// (internal1_m2325_BlDv0) - была блокировка
#define internal1_m2325_DvDw0	BUFFER[8348]	// (internal1_m2325_DvDw0) - есть команда на движение назад
#define idinternal1_m2325_DvDw0	1437	// (internal1_m2325_DvDw0) - есть команда на движение назад
#define internal1_m2325_DvUp0	BUFFER[8350]	// (internal1_m2325_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2325_DvUp0	1438	// (internal1_m2325_DvUp0) - есть команда на движение вперёд
#define internal1_m2325_FDvDw0	BUFFER[8352]	// (internal1_m2325_FDvDw0) - есть команда на движение назад
#define idinternal1_m2325_FDvDw0	1439	// (internal1_m2325_FDvDw0) - есть команда на движение назад
#define internal1_m2325_FDvUp0	BUFFER[8354]	// (internal1_m2325_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2325_FDvUp0	1440	// (internal1_m2325_FDvUp0) - есть команда на движение вперёд
#define internal1_m2325_Pkav0	BUFFER[8356]	// (internal1_m2325_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2325_Pkav0	1441	// (internal1_m2325_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2325_Pkv0	BUFFER[8358]	// (internal1_m2325_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2325_Pkv0	1442	// (internal1_m2325_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2325_Zkav0	BUFFER[8360]	// (internal1_m2325_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2325_Zkav0	1443	// (internal1_m2325_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2325_Zkv0	BUFFER[8362]	// (internal1_m2325_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2325_Zkv0	1444	// (internal1_m2325_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2325_fef	BUFFER[8364]	// (internal1_m2325_fef) fef
#define idinternal1_m2325_fef	1445	// (internal1_m2325_fef) fef
#define internal1_m2325_txHr	BUFFER[8366]	// (internal1_m2325_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2325_txHr	1446	// (internal1_m2325_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2325_txLd	BUFFER[8371]	// (internal1_m2325_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2325_txLd	1447	// (internal1_m2325_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2325_txNm	BUFFER[8376]	// (internal1_m2325_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2325_txNm	1448	// (internal1_m2325_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2325_txSm	BUFFER[8381]	// (internal1_m2325_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2325_txSm	1449	// (internal1_m2325_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2328_tx	BUFFER[8386]	// (internal1_m2328_tx) tx - внутренний параметр
#define idinternal1_m2328_tx	1450	// (internal1_m2328_tx) tx - внутренний параметр
#define internal1_m2329_tx	BUFFER[8391]	// (internal1_m2329_tx) tx - внутренний параметр
#define idinternal1_m2329_tx	1451	// (internal1_m2329_tx) tx - внутренний параметр
#define internal1_m232_tx	BUFFER[8396]	// (internal1_m232_tx) tx - внутренний параметр
#define idinternal1_m232_tx	1452	// (internal1_m232_tx) tx - внутренний параметр
#define internal1_m2330_tx	BUFFER[8401]	// (internal1_m2330_tx) tx - внутренний параметр
#define idinternal1_m2330_tx	1453	// (internal1_m2330_tx) tx - внутренний параметр
#define internal1_m2337_q0	BUFFER[8406]	// (internal1_m2337_q0) q0 - внутренний параметр
#define idinternal1_m2337_q0	1454	// (internal1_m2337_q0) q0 - внутренний параметр
#define internal1_m2338_q0	BUFFER[8408]	// (internal1_m2338_q0) q0 - внутренний параметр
#define idinternal1_m2338_q0	1455	// (internal1_m2338_q0) q0 - внутренний параметр
#define internal1_m2339_q0	BUFFER[8410]	// (internal1_m2339_q0) q0 - внутренний параметр
#define idinternal1_m2339_q0	1456	// (internal1_m2339_q0) q0 - внутренний параметр
#define internal1_m2340_q0	BUFFER[8412]	// (internal1_m2340_q0) q0 - внутренний параметр
#define idinternal1_m2340_q0	1457	// (internal1_m2340_q0) q0 - внутренний параметр
#define internal1_m2342_q0	BUFFER[8414]	// (internal1_m2342_q0) q0 - внутренний параметр
#define idinternal1_m2342_q0	1458	// (internal1_m2342_q0) q0 - внутренний параметр
#define internal1_m2349_q0	BUFFER[8416]	// (internal1_m2349_q0) q0 - внутренний параметр
#define idinternal1_m2349_q0	1459	// (internal1_m2349_q0) q0 - внутренний параметр
#define internal1_m2351_q0	BUFFER[8418]	// (internal1_m2351_q0) q0 - внутренний параметр
#define idinternal1_m2351_q0	1460	// (internal1_m2351_q0) q0 - внутренний параметр
#define internal1_m2353_q0	BUFFER[8420]	// (internal1_m2353_q0) q0 - внутренний параметр
#define idinternal1_m2353_q0	1461	// (internal1_m2353_q0) q0 - внутренний параметр
#define internal1_m2355_q0	BUFFER[8422]	// (internal1_m2355_q0) q0 - внутренний параметр
#define idinternal1_m2355_q0	1462	// (internal1_m2355_q0) q0 - внутренний параметр
#define internal1_m2357_q0	BUFFER[8424]	// (internal1_m2357_q0) q0 - внутренний параметр
#define idinternal1_m2357_q0	1463	// (internal1_m2357_q0) q0 - внутренний параметр
#define internal1_m2359_q0	BUFFER[8426]	// (internal1_m2359_q0) q0 - внутренний параметр
#define idinternal1_m2359_q0	1464	// (internal1_m2359_q0) q0 - внутренний параметр
#define internal1_m2361_q0	BUFFER[8428]	// (internal1_m2361_q0) q0 - внутренний параметр
#define idinternal1_m2361_q0	1465	// (internal1_m2361_q0) q0 - внутренний параметр
#define internal1_m2368_q0	BUFFER[8430]	// (internal1_m2368_q0) q0 - внутренний параметр
#define idinternal1_m2368_q0	1466	// (internal1_m2368_q0) q0 - внутренний параметр
#define internal1_m2369_q0	BUFFER[8432]	// (internal1_m2369_q0) q0 - внутренний параметр
#define idinternal1_m2369_q0	1467	// (internal1_m2369_q0) q0 - внутренний параметр
#define internal1_m2370_q0	BUFFER[8434]	// (internal1_m2370_q0) q0 - внутренний параметр
#define idinternal1_m2370_q0	1468	// (internal1_m2370_q0) q0 - внутренний параметр
#define internal1_m2372_q0	BUFFER[8436]	// (internal1_m2372_q0) q0 - внутренний параметр
#define idinternal1_m2372_q0	1469	// (internal1_m2372_q0) q0 - внутренний параметр
#define internal1_m2373_q0	BUFFER[8438]	// (internal1_m2373_q0) q0 - внутренний параметр
#define idinternal1_m2373_q0	1470	// (internal1_m2373_q0) q0 - внутренний параметр
#define internal1_m2380_q0	BUFFER[8440]	// (internal1_m2380_q0) q0 - внутренний параметр
#define idinternal1_m2380_q0	1471	// (internal1_m2380_q0) q0 - внутренний параметр
#define internal1_m2382_q0	BUFFER[8442]	// (internal1_m2382_q0) q0 - внутренний параметр
#define idinternal1_m2382_q0	1472	// (internal1_m2382_q0) q0 - внутренний параметр
#define internal1_m2384_q0	BUFFER[8444]	// (internal1_m2384_q0) q0 - внутренний параметр
#define idinternal1_m2384_q0	1473	// (internal1_m2384_q0) q0 - внутренний параметр
#define internal1_m2386_q0	BUFFER[8446]	// (internal1_m2386_q0) q0 - внутренний параметр
#define idinternal1_m2386_q0	1474	// (internal1_m2386_q0) q0 - внутренний параметр
#define internal1_m2388_q0	BUFFER[8448]	// (internal1_m2388_q0) q0 - внутренний параметр
#define idinternal1_m2388_q0	1475	// (internal1_m2388_q0) q0 - внутренний параметр
#define internal1_m2390_q0	BUFFER[8450]	// (internal1_m2390_q0) q0 - внутренний параметр
#define idinternal1_m2390_q0	1476	// (internal1_m2390_q0) q0 - внутренний параметр
#define internal1_m2392_q0	BUFFER[8452]	// (internal1_m2392_q0) q0 - внутренний параметр
#define idinternal1_m2392_q0	1477	// (internal1_m2392_q0) q0 - внутренний параметр
#define internal1_m2408_FlCmp	BUFFER[8454]	// (internal1_m2408_FlCmp) - текущее направление изменения мощности
#define idinternal1_m2408_FlCmp	1478	// (internal1_m2408_FlCmp) - текущее направление изменения мощности
#define internal1_m2408_FlIzm	BUFFER[8457]	// (internal1_m2408_FlIzm) - флаг изменения направления изменения мощности
#define idinternal1_m2408_FlIzm	1479	// (internal1_m2408_FlIzm) - флаг изменения направления изменения мощности
#define internal1_m2408_FlPar	BUFFER[8460]	// (internal1_m2408_FlPar) - стартовый этап регулирования
#define idinternal1_m2408_FlPar	1480	// (internal1_m2408_FlPar) - стартовый этап регулирования
#define internal1_m2408_LastStage	BUFFER[8463]	// (internal1_m2408_LastStage)  - последний этап
#define idinternal1_m2408_LastStage	1481	// (internal1_m2408_LastStage)  - последний этап
#define internal1_m2408_SrCoun	BUFFER[8466]	// (internal1_m2408_SrCoun)  - счётчик усреднения
#define idinternal1_m2408_SrCoun	1482	// (internal1_m2408_SrCoun)  - счётчик усреднения
#define internal1_m2408_StabCoun	BUFFER[8469]	// (internal1_m2408_StabCoun) - счётчик стабильности
#define idinternal1_m2408_StabCoun	1483	// (internal1_m2408_StabCoun) - счётчик стабильности
#define internal1_m2408_ZerCoun	BUFFER[8472]	// (internal1_m2408_ZerCoun) - счётчик полной остановки
#define idinternal1_m2408_ZerCoun	1484	// (internal1_m2408_ZerCoun) - счётчик полной остановки
#define internal1_m2408_fMaxDk	BUFFER[8475]	// (internal1_m2408_fMaxDk)  - изменение координаты при смене задания 
#define idinternal1_m2408_fMaxDk	1485	// (internal1_m2408_fMaxDk)  - изменение координаты при смене задания 
#define internal1_m2408_fRct	BUFFER[8480]	// (internal1_m2408_fRct)  - стартовая реактивность регулятора 
#define idinternal1_m2408_fRct	1486	// (internal1_m2408_fRct)  - стартовая реактивность регулятора 
#define internal1_m2408_fRsg	BUFFER[8485]	// (internal1_m2408_fRsg)  - рассогласование между текущей и заданной мощностью 
#define idinternal1_m2408_fRsg	1487	// (internal1_m2408_fRsg)  - рассогласование между текущей и заданной мощностью 
#define internal1_m2408_fStw0	BUFFER[8490]	// (internal1_m2408_fStw0)  - значение стартовой мощности включения ИМ 
#define idinternal1_m2408_fStw0	1488	// (internal1_m2408_fStw0)  - значение стартовой мощности включения ИМ 
#define internal1_m2408_fTk0	BUFFER[8495]	// (internal1_m2408_fTk0)  - последняя температура 
#define idinternal1_m2408_fTk0	1489	// (internal1_m2408_fTk0)  - последняя температура 
#define internal1_m2408_fVf0	BUFFER[8500]	// (internal1_m2408_fVf0)  - скорость изменения мощности 
#define idinternal1_m2408_fVf0	1490	// (internal1_m2408_fVf0)  - скорость изменения мощности 
#define internal1_m2408_fVfMin	BUFFER[8505]	// (internal1_m2408_fVfMin)  - минимальная скорость 
#define idinternal1_m2408_fVfMin	1491	// (internal1_m2408_fVfMin)  - минимальная скорость 
#define internal1_m2408_fef	BUFFER[8510]	// (internal1_m2408_fef)  - первый вход
#define idinternal1_m2408_fef	1492	// (internal1_m2408_fef)  - первый вход
#define internal1_m2408_fkizm	BUFFER[8512]	// (internal1_m2408_fkizm)  - стартовая координата положения ИМ 0-й реактивности 
#define idinternal1_m2408_fkizm	1493	// (internal1_m2408_fkizm)  - стартовая координата положения ИМ 0-й реактивности 
#define internal1_m2408_ftf0	BUFFER[8517]	// (internal1_m2408_ftf0)  - время от фиксации предыдущей мощности 
#define idinternal1_m2408_ftf0	1494	// (internal1_m2408_ftf0)  - время от фиксации предыдущей мощности 
#define internal1_m2408_fwt0	BUFFER[8522]	// (internal1_m2408_fwt0)  - мощность на предыдущем шаге 
#define idinternal1_m2408_fwt0	1495	// (internal1_m2408_fwt0)  - мощность на предыдущем шаге 
#define internal1_m2408_fwz0	BUFFER[8527]	// (internal1_m2408_fwz0)  - заданная мощность на предыдущем шаге 
#define idinternal1_m2408_fwz0	1496	// (internal1_m2408_fwz0)  - заданная мощность на предыдущем шаге 
#define internal1_m2410_tx	BUFFER[8532]	// (internal1_m2410_tx) tx - время накопленное сек
#define idinternal1_m2410_tx	1497	// (internal1_m2410_tx) tx - время накопленное сек
#define internal1_m2410_y0	BUFFER[8537]	// (internal1_m2410_y0) y0
#define idinternal1_m2410_y0	1498	// (internal1_m2410_y0) y0
#define internal1_m2413_tx	BUFFER[8539]	// (internal1_m2413_tx) tx - время накопленное сек
#define idinternal1_m2413_tx	1499	// (internal1_m2413_tx) tx - время накопленное сек
#define internal1_m2413_y0	BUFFER[8544]	// (internal1_m2413_y0) y0
#define idinternal1_m2413_y0	1500	// (internal1_m2413_y0) y0
#define internal1_m2414_tx	BUFFER[8546]	// (internal1_m2414_tx) tx - время накопленное сек
#define idinternal1_m2414_tx	1501	// (internal1_m2414_tx) tx - время накопленное сек
#define internal1_m2414_y0	BUFFER[8551]	// (internal1_m2414_y0) y0
#define idinternal1_m2414_y0	1502	// (internal1_m2414_y0) y0
#define internal1_m241_tx	BUFFER[8553]	// (internal1_m241_tx) tx - внутренний параметр
#define idinternal1_m241_tx	1503	// (internal1_m241_tx) tx - внутренний параметр
#define internal1_m2420_q0	BUFFER[8558]	// (internal1_m2420_q0) q0 - внутренний параметр
#define idinternal1_m2420_q0	1504	// (internal1_m2420_q0) q0 - внутренний параметр
#define internal1_m2426_q0	BUFFER[8560]	// (internal1_m2426_q0) q0 - внутренний параметр
#define idinternal1_m2426_q0	1505	// (internal1_m2426_q0) q0 - внутренний параметр
#define internal1_m2428_tx	BUFFER[8562]	// (internal1_m2428_tx) tx - внутренний параметр
#define idinternal1_m2428_tx	1506	// (internal1_m2428_tx) tx - внутренний параметр
#define internal1_m2448_tx	BUFFER[8567]	// (internal1_m2448_tx) tx - время накопленное сек
#define idinternal1_m2448_tx	1507	// (internal1_m2448_tx) tx - время накопленное сек
#define internal1_m2448_y0	BUFFER[8572]	// (internal1_m2448_y0) y0
#define idinternal1_m2448_y0	1508	// (internal1_m2448_y0) y0
#define internal1_m2450_tx	BUFFER[8574]	// (internal1_m2450_tx) tx - внутренний параметр
#define idinternal1_m2450_tx	1509	// (internal1_m2450_tx) tx - внутренний параметр
#define internal1_m2453_q0	BUFFER[8579]	// (internal1_m2453_q0) q0 - внутренний параметр
#define idinternal1_m2453_q0	1510	// (internal1_m2453_q0) q0 - внутренний параметр
#define internal1_m245_tx	BUFFER[8581]	// (internal1_m245_tx) tx - внутренний параметр
#define idinternal1_m245_tx	1511	// (internal1_m245_tx) tx - внутренний параметр
#define internal1_m2467_tx	BUFFER[8586]	// (internal1_m2467_tx) tx - внутренний параметр
#define idinternal1_m2467_tx	1512	// (internal1_m2467_tx) tx - внутренний параметр
#define internal1_m246_tx	BUFFER[8591]	// (internal1_m246_tx) tx - внутренний параметр
#define idinternal1_m246_tx	1513	// (internal1_m246_tx) tx - внутренний параметр
#define internal1_m2470_tx	BUFFER[8596]	// (internal1_m2470_tx) tx - внутренний параметр
#define idinternal1_m2470_tx	1514	// (internal1_m2470_tx) tx - внутренний параметр
#define internal1_m2471_tx	BUFFER[8601]	// (internal1_m2471_tx) tx - внутренний параметр
#define idinternal1_m2471_tx	1515	// (internal1_m2471_tx) tx - внутренний параметр
#define internal1_m2472_tx	BUFFER[8606]	// (internal1_m2472_tx) tx - внутренний параметр
#define idinternal1_m2472_tx	1516	// (internal1_m2472_tx) tx - внутренний параметр
#define internal1_m2552_tx	BUFFER[8611]	// (internal1_m2552_tx) tx - время накопленное сек
#define idinternal1_m2552_tx	1517	// (internal1_m2552_tx) tx - время накопленное сек
#define internal1_m2552_y0	BUFFER[8616]	// (internal1_m2552_y0) y0
#define idinternal1_m2552_y0	1518	// (internal1_m2552_y0) y0
#define internal1_m2554_tx	BUFFER[8618]	// (internal1_m2554_tx) tx - время накопленное сек
#define idinternal1_m2554_tx	1519	// (internal1_m2554_tx) tx - время накопленное сек
#define internal1_m2554_y0	BUFFER[8623]	// (internal1_m2554_y0) y0
#define idinternal1_m2554_y0	1520	// (internal1_m2554_y0) y0
#define internal1_m2556_tx	BUFFER[8625]	// (internal1_m2556_tx) tx - время накопленное сек
#define idinternal1_m2556_tx	1521	// (internal1_m2556_tx) tx - время накопленное сек
#define internal1_m2556_y0	BUFFER[8630]	// (internal1_m2556_y0) y0
#define idinternal1_m2556_y0	1522	// (internal1_m2556_y0) y0
#define internal1_m2558_tx	BUFFER[8632]	// (internal1_m2558_tx) tx - время накопленное сек
#define idinternal1_m2558_tx	1523	// (internal1_m2558_tx) tx - время накопленное сек
#define internal1_m2558_y0	BUFFER[8637]	// (internal1_m2558_y0) y0
#define idinternal1_m2558_y0	1524	// (internal1_m2558_y0) y0
#define internal1_m255_tx	BUFFER[8639]	// (internal1_m255_tx) tx - внутренний параметр
#define idinternal1_m255_tx	1525	// (internal1_m255_tx) tx - внутренний параметр
#define internal1_m258_tx	BUFFER[8644]	// (internal1_m258_tx) tx - внутренний параметр
#define idinternal1_m258_tx	1526	// (internal1_m258_tx) tx - внутренний параметр
#define internal1_m261_tx	BUFFER[8649]	// (internal1_m261_tx) tx - внутренний параметр
#define idinternal1_m261_tx	1527	// (internal1_m261_tx) tx - внутренний параметр
#define internal1_m26_q0	BUFFER[8654]	// (internal1_m26_q0) q0 - внутренний параметр
#define idinternal1_m26_q0	1528	// (internal1_m26_q0) q0 - внутренний параметр
#define internal1_m270_tx	BUFFER[8656]	// (internal1_m270_tx) tx - внутренний параметр
#define idinternal1_m270_tx	1529	// (internal1_m270_tx) tx - внутренний параметр
#define internal1_m273_tx	BUFFER[8661]	// (internal1_m273_tx) tx - внутренний параметр
#define idinternal1_m273_tx	1530	// (internal1_m273_tx) tx - внутренний параметр
#define internal1_m274_tx	BUFFER[8666]	// (internal1_m274_tx) tx - внутренний параметр
#define idinternal1_m274_tx	1531	// (internal1_m274_tx) tx - внутренний параметр
#define internal1_m277_tx	BUFFER[8671]	// (internal1_m277_tx) tx - внутренний параметр
#define idinternal1_m277_tx	1532	// (internal1_m277_tx) tx - внутренний параметр
#define internal1_m278_tx	BUFFER[8676]	// (internal1_m278_tx) tx - внутренний параметр
#define idinternal1_m278_tx	1533	// (internal1_m278_tx) tx - внутренний параметр
#define internal1_m298_ErrPr0	BUFFER[8681]	// (internal1_m298_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m298_ErrPr0	1534	// (internal1_m298_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m298_FinPr0	BUFFER[8683]	// (internal1_m298_FinPr0) FinPr - конец программы
#define idinternal1_m298_FinPr0	1535	// (internal1_m298_FinPr0) FinPr - конец программы
#define internal1_m298_MyFirstEnterFlag	BUFFER[8685]	// (internal1_m298_MyFirstEnterFlag)  
#define idinternal1_m298_MyFirstEnterFlag	1536	// (internal1_m298_MyFirstEnterFlag)  
#define internal1_m298_Step	BUFFER[8687]	// (internal1_m298_Step)  - текущий шаг программы
#define idinternal1_m298_Step	1537	// (internal1_m298_Step)  - текущий шаг программы
#define internal1_m298_TimS	BUFFER[8690]	// (internal1_m298_TimS) Время от старта программы
#define idinternal1_m298_TimS	1538	// (internal1_m298_TimS) Время от старта программы
#define internal1_m298_rz	BUFFER[8695]	// (internal1_m298_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m298_rz	1539	// (internal1_m298_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m298_sb2UR0	BUFFER[8715]	// (internal1_m298_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m298_sb2UR0	1540	// (internal1_m298_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m298_sbINI0	BUFFER[8717]	// (internal1_m298_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m298_sbINI0	1541	// (internal1_m298_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m298_sbNupIS0	BUFFER[8719]	// (internal1_m298_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m298_sbNupIS0	1542	// (internal1_m298_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m298_sbVuIS0	BUFFER[8721]	// (internal1_m298_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m298_sbVuIS0	1543	// (internal1_m298_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m298_sbVuRB0	BUFFER[8723]	// (internal1_m298_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m298_sbVuRB0	1544	// (internal1_m298_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m309_q0	BUFFER[8725]	// (internal1_m309_q0) q0 - внутренний параметр
#define idinternal1_m309_q0	1545	// (internal1_m309_q0) q0 - внутренний параметр
#define internal1_m317_x0	BUFFER[8727]	// (internal1_m317_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m317_x0	1546	// (internal1_m317_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m318_q0	BUFFER[8732]	// (internal1_m318_q0) q0 - внутренний параметр
#define idinternal1_m318_q0	1547	// (internal1_m318_q0) q0 - внутренний параметр
#define internal1_m321_TimS	BUFFER[8734]	// (internal1_m321_TimS) Время до нулевого отсчета
#define idinternal1_m321_TimS	1548	// (internal1_m321_TimS) Время до нулевого отсчета
#define internal1_m321_pusk0	BUFFER[8739]	// (internal1_m321_pusk0) pusk - разрешение выполнения программы
#define idinternal1_m321_pusk0	1549	// (internal1_m321_pusk0) pusk - разрешение выполнения программы
#define internal1_m322_tx	BUFFER[8741]	// (internal1_m322_tx) tx - внутренний параметр
#define idinternal1_m322_tx	1550	// (internal1_m322_tx) tx - внутренний параметр
#define internal1_m339_tx	BUFFER[8746]	// (internal1_m339_tx) tx - время накопленное сек
#define idinternal1_m339_tx	1551	// (internal1_m339_tx) tx - время накопленное сек
#define internal1_m339_y0	BUFFER[8751]	// (internal1_m339_y0) y0
#define idinternal1_m339_y0	1552	// (internal1_m339_y0) y0
#define internal1_m356_ErrPr0	BUFFER[8753]	// (internal1_m356_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m356_ErrPr0	1553	// (internal1_m356_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m356_FinPr0	BUFFER[8755]	// (internal1_m356_FinPr0) FinPr - конец программы
#define idinternal1_m356_FinPr0	1554	// (internal1_m356_FinPr0) FinPr - конец программы
#define internal1_m356_MyFirstEnterFlag	BUFFER[8757]	// (internal1_m356_MyFirstEnterFlag)  
#define idinternal1_m356_MyFirstEnterFlag	1555	// (internal1_m356_MyFirstEnterFlag)  
#define internal1_m356_Step	BUFFER[8759]	// (internal1_m356_Step)  - текущий шаг программы
#define idinternal1_m356_Step	1556	// (internal1_m356_Step)  - текущий шаг программы
#define internal1_m356_TimS	BUFFER[8762]	// (internal1_m356_TimS) Время от старта программы
#define idinternal1_m356_TimS	1557	// (internal1_m356_TimS) Время от старта программы
#define internal1_m356_rz	BUFFER[8767]	// (internal1_m356_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m356_rz	1558	// (internal1_m356_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m356_sb2UR0	BUFFER[8787]	// (internal1_m356_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m356_sb2UR0	1559	// (internal1_m356_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m356_sbINI0	BUFFER[8789]	// (internal1_m356_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m356_sbINI0	1560	// (internal1_m356_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m356_sbNupIS0	BUFFER[8791]	// (internal1_m356_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m356_sbNupIS0	1561	// (internal1_m356_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m356_sbVuIS0	BUFFER[8793]	// (internal1_m356_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m356_sbVuIS0	1562	// (internal1_m356_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m356_sbVuRB0	BUFFER[8795]	// (internal1_m356_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m356_sbVuRB0	1563	// (internal1_m356_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m362_q0	BUFFER[8797]	// (internal1_m362_q0) q0 - внутренний параметр
#define idinternal1_m362_q0	1564	// (internal1_m362_q0) q0 - внутренний параметр
#define internal1_m364_x0	BUFFER[8799]	// (internal1_m364_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m364_x0	1565	// (internal1_m364_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m366_q0	BUFFER[8804]	// (internal1_m366_q0) q0 - внутренний параметр
#define idinternal1_m366_q0	1566	// (internal1_m366_q0) q0 - внутренний параметр
#define internal1_m368_tx	BUFFER[8806]	// (internal1_m368_tx) tx - внутренний параметр
#define idinternal1_m368_tx	1567	// (internal1_m368_tx) tx - внутренний параметр
#define internal1_m390_BlDv0	BUFFER[8811]	// (internal1_m390_BlDv0) - была блокировка
#define idinternal1_m390_BlDv0	1568	// (internal1_m390_BlDv0) - была блокировка
#define internal1_m390_DvDw0	BUFFER[8813]	// (internal1_m390_DvDw0) - есть команда на движение назад
#define idinternal1_m390_DvDw0	1569	// (internal1_m390_DvDw0) - есть команда на движение назад
#define internal1_m390_DvUp0	BUFFER[8815]	// (internal1_m390_DvUp0) - есть команда на движение вперёд
#define idinternal1_m390_DvUp0	1570	// (internal1_m390_DvUp0) - есть команда на движение вперёд
#define internal1_m390_FDvDw0	BUFFER[8817]	// (internal1_m390_FDvDw0) - есть команда на движение назад
#define idinternal1_m390_FDvDw0	1571	// (internal1_m390_FDvDw0) - есть команда на движение назад
#define internal1_m390_FDvUp0	BUFFER[8819]	// (internal1_m390_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m390_FDvUp0	1572	// (internal1_m390_FDvUp0) - есть команда на движение вперёд
#define internal1_m390_Pkav0	BUFFER[8821]	// (internal1_m390_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m390_Pkav0	1573	// (internal1_m390_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m390_Pkv0	BUFFER[8823]	// (internal1_m390_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m390_Pkv0	1574	// (internal1_m390_Pkv0) Pkv - передний конечный выключатель
#define internal1_m390_Zkav0	BUFFER[8825]	// (internal1_m390_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m390_Zkav0	1575	// (internal1_m390_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m390_Zkv0	BUFFER[8827]	// (internal1_m390_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m390_Zkv0	1576	// (internal1_m390_Zkv0) Zkv - задний конечный выключатель
#define internal1_m390_fef	BUFFER[8829]	// (internal1_m390_fef) fef
#define idinternal1_m390_fef	1577	// (internal1_m390_fef) fef
#define internal1_m390_txHr	BUFFER[8831]	// (internal1_m390_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m390_txHr	1578	// (internal1_m390_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m390_txLd	BUFFER[8836]	// (internal1_m390_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m390_txLd	1579	// (internal1_m390_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m390_txNm	BUFFER[8841]	// (internal1_m390_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m390_txNm	1580	// (internal1_m390_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m390_txSm	BUFFER[8846]	// (internal1_m390_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m390_txSm	1581	// (internal1_m390_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m395_tx	BUFFER[8851]	// (internal1_m395_tx) tx - внутренний параметр
#define idinternal1_m395_tx	1582	// (internal1_m395_tx) tx - внутренний параметр
#define internal1_m396_tx	BUFFER[8856]	// (internal1_m396_tx) tx - внутренний параметр
#define idinternal1_m396_tx	1583	// (internal1_m396_tx) tx - внутренний параметр
#define internal1_m397_tx	BUFFER[8861]	// (internal1_m397_tx) tx - внутренний параметр
#define idinternal1_m397_tx	1584	// (internal1_m397_tx) tx - внутренний параметр
#define internal1_m398_tx	BUFFER[8866]	// (internal1_m398_tx) tx - внутренний параметр
#define idinternal1_m398_tx	1585	// (internal1_m398_tx) tx - внутренний параметр
#define internal1_m410_tx	BUFFER[8871]	// (internal1_m410_tx) tx - внутренний параметр
#define idinternal1_m410_tx	1586	// (internal1_m410_tx) tx - внутренний параметр
#define internal1_m411_tx	BUFFER[8876]	// (internal1_m411_tx) tx - внутренний параметр
#define idinternal1_m411_tx	1587	// (internal1_m411_tx) tx - внутренний параметр
#define internal1_m412_tx	BUFFER[8881]	// (internal1_m412_tx) tx - внутренний параметр
#define idinternal1_m412_tx	1588	// (internal1_m412_tx) tx - внутренний параметр
#define internal1_m415_tx	BUFFER[8886]	// (internal1_m415_tx) tx - внутренний параметр
#define idinternal1_m415_tx	1589	// (internal1_m415_tx) tx - внутренний параметр
#define internal1_m421_BlDv0	BUFFER[8891]	// (internal1_m421_BlDv0) - была блокировка
#define idinternal1_m421_BlDv0	1590	// (internal1_m421_BlDv0) - была блокировка
#define internal1_m421_DvDw0	BUFFER[8893]	// (internal1_m421_DvDw0) - есть команда на движение назад
#define idinternal1_m421_DvDw0	1591	// (internal1_m421_DvDw0) - есть команда на движение назад
#define internal1_m421_DvUp0	BUFFER[8895]	// (internal1_m421_DvUp0) - есть команда на движение вперёд
#define idinternal1_m421_DvUp0	1592	// (internal1_m421_DvUp0) - есть команда на движение вперёд
#define internal1_m421_FDvDw0	BUFFER[8897]	// (internal1_m421_FDvDw0) - есть команда на движение назад
#define idinternal1_m421_FDvDw0	1593	// (internal1_m421_FDvDw0) - есть команда на движение назад
#define internal1_m421_FDvUp0	BUFFER[8899]	// (internal1_m421_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m421_FDvUp0	1594	// (internal1_m421_FDvUp0) - есть команда на движение вперёд
#define internal1_m421_Pkav0	BUFFER[8901]	// (internal1_m421_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m421_Pkav0	1595	// (internal1_m421_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m421_Pkv0	BUFFER[8903]	// (internal1_m421_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m421_Pkv0	1596	// (internal1_m421_Pkv0) Pkv - передний конечный выключатель
#define internal1_m421_Zkav0	BUFFER[8905]	// (internal1_m421_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m421_Zkav0	1597	// (internal1_m421_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m421_Zkv0	BUFFER[8907]	// (internal1_m421_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m421_Zkv0	1598	// (internal1_m421_Zkv0) Zkv - задний конечный выключатель
#define internal1_m421_fef	BUFFER[8909]	// (internal1_m421_fef) fef
#define idinternal1_m421_fef	1599	// (internal1_m421_fef) fef
#define internal1_m421_txHr	BUFFER[8911]	// (internal1_m421_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m421_txHr	1600	// (internal1_m421_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m421_txLd	BUFFER[8916]	// (internal1_m421_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m421_txLd	1601	// (internal1_m421_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m421_txNm	BUFFER[8921]	// (internal1_m421_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m421_txNm	1602	// (internal1_m421_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m421_txSm	BUFFER[8926]	// (internal1_m421_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m421_txSm	1603	// (internal1_m421_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m427_BlDv0	BUFFER[8931]	// (internal1_m427_BlDv0) - была блокировка
#define idinternal1_m427_BlDv0	1604	// (internal1_m427_BlDv0) - была блокировка
#define internal1_m427_DvDw0	BUFFER[8933]	// (internal1_m427_DvDw0) - есть команда на движение назад
#define idinternal1_m427_DvDw0	1605	// (internal1_m427_DvDw0) - есть команда на движение назад
#define internal1_m427_DvUp0	BUFFER[8935]	// (internal1_m427_DvUp0) - есть команда на движение вперёд
#define idinternal1_m427_DvUp0	1606	// (internal1_m427_DvUp0) - есть команда на движение вперёд
#define internal1_m427_FDvDw0	BUFFER[8937]	// (internal1_m427_FDvDw0) - есть команда на движение назад
#define idinternal1_m427_FDvDw0	1607	// (internal1_m427_FDvDw0) - есть команда на движение назад
#define internal1_m427_FDvUp0	BUFFER[8939]	// (internal1_m427_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m427_FDvUp0	1608	// (internal1_m427_FDvUp0) - есть команда на движение вперёд
#define internal1_m427_Pkav0	BUFFER[8941]	// (internal1_m427_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m427_Pkav0	1609	// (internal1_m427_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m427_Pkv0	BUFFER[8943]	// (internal1_m427_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m427_Pkv0	1610	// (internal1_m427_Pkv0) Pkv - передний конечный выключатель
#define internal1_m427_Zkav0	BUFFER[8945]	// (internal1_m427_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m427_Zkav0	1611	// (internal1_m427_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m427_Zkv0	BUFFER[8947]	// (internal1_m427_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m427_Zkv0	1612	// (internal1_m427_Zkv0) Zkv - задний конечный выключатель
#define internal1_m427_fef	BUFFER[8949]	// (internal1_m427_fef) fef
#define idinternal1_m427_fef	1613	// (internal1_m427_fef) fef
#define internal1_m427_txHr	BUFFER[8951]	// (internal1_m427_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m427_txHr	1614	// (internal1_m427_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m427_txLd	BUFFER[8956]	// (internal1_m427_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m427_txLd	1615	// (internal1_m427_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m427_txNm	BUFFER[8961]	// (internal1_m427_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m427_txNm	1616	// (internal1_m427_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m427_txSm	BUFFER[8966]	// (internal1_m427_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m427_txSm	1617	// (internal1_m427_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m431_tx	BUFFER[8971]	// (internal1_m431_tx) tx - внутренний параметр
#define idinternal1_m431_tx	1618	// (internal1_m431_tx) tx - внутренний параметр
#define internal1_m437_tx	BUFFER[8976]	// (internal1_m437_tx) tx - внутренний параметр
#define idinternal1_m437_tx	1619	// (internal1_m437_tx) tx - внутренний параметр
#define internal1_m438_tx	BUFFER[8981]	// (internal1_m438_tx) tx - внутренний параметр
#define idinternal1_m438_tx	1620	// (internal1_m438_tx) tx - внутренний параметр
#define internal1_m439_tx	BUFFER[8986]	// (internal1_m439_tx) tx - внутренний параметр
#define idinternal1_m439_tx	1621	// (internal1_m439_tx) tx - внутренний параметр
#define internal1_m448_tx	BUFFER[8991]	// (internal1_m448_tx) tx - внутренний параметр
#define idinternal1_m448_tx	1622	// (internal1_m448_tx) tx - внутренний параметр
#define internal1_m449_tx	BUFFER[8996]	// (internal1_m449_tx) tx - внутренний параметр
#define idinternal1_m449_tx	1623	// (internal1_m449_tx) tx - внутренний параметр
#define internal1_m451_tx	BUFFER[9001]	// (internal1_m451_tx) tx - внутренний параметр
#define idinternal1_m451_tx	1624	// (internal1_m451_tx) tx - внутренний параметр
#define internal1_m457_tx	BUFFER[9006]	// (internal1_m457_tx) tx - внутренний параметр
#define idinternal1_m457_tx	1625	// (internal1_m457_tx) tx - внутренний параметр
#define internal1_m465_tx	BUFFER[9011]	// (internal1_m465_tx) tx - внутренний параметр
#define idinternal1_m465_tx	1626	// (internal1_m465_tx) tx - внутренний параметр
#define internal1_m474_tx	BUFFER[9016]	// (internal1_m474_tx) tx - внутренний параметр
#define idinternal1_m474_tx	1627	// (internal1_m474_tx) tx - внутренний параметр
#define internal1_m476_tx	BUFFER[9021]	// (internal1_m476_tx) tx - внутренний параметр
#define idinternal1_m476_tx	1628	// (internal1_m476_tx) tx - внутренний параметр
#define internal1_m478_tx	BUFFER[9026]	// (internal1_m478_tx) tx - внутренний параметр
#define idinternal1_m478_tx	1629	// (internal1_m478_tx) tx - внутренний параметр
#define internal1_m480_tx	BUFFER[9031]	// (internal1_m480_tx) tx - внутренний параметр
#define idinternal1_m480_tx	1630	// (internal1_m480_tx) tx - внутренний параметр
#define internal1_m485_tx	BUFFER[9036]	// (internal1_m485_tx) tx - внутренний параметр
#define idinternal1_m485_tx	1631	// (internal1_m485_tx) tx - внутренний параметр
#define internal1_m500_tx	BUFFER[9041]	// (internal1_m500_tx) tx - внутренний параметр
#define idinternal1_m500_tx	1632	// (internal1_m500_tx) tx - внутренний параметр
#define internal1_m501_tx	BUFFER[9046]	// (internal1_m501_tx) tx - внутренний параметр
#define idinternal1_m501_tx	1633	// (internal1_m501_tx) tx - внутренний параметр
#define internal1_m502_tx	BUFFER[9051]	// (internal1_m502_tx) tx - внутренний параметр
#define idinternal1_m502_tx	1634	// (internal1_m502_tx) tx - внутренний параметр
#define internal1_m503_tx	BUFFER[9056]	// (internal1_m503_tx) tx - внутренний параметр
#define idinternal1_m503_tx	1635	// (internal1_m503_tx) tx - внутренний параметр
#define internal1_m511_BlDv0	BUFFER[9061]	// (internal1_m511_BlDv0) - была блокировка
#define idinternal1_m511_BlDv0	1636	// (internal1_m511_BlDv0) - была блокировка
#define internal1_m511_DvDw0	BUFFER[9063]	// (internal1_m511_DvDw0) - есть команда на движение назад
#define idinternal1_m511_DvDw0	1637	// (internal1_m511_DvDw0) - есть команда на движение назад
#define internal1_m511_DvUp0	BUFFER[9065]	// (internal1_m511_DvUp0) - есть команда на движение вперёд
#define idinternal1_m511_DvUp0	1638	// (internal1_m511_DvUp0) - есть команда на движение вперёд
#define internal1_m511_FDvDw0	BUFFER[9067]	// (internal1_m511_FDvDw0) - есть команда на движение назад
#define idinternal1_m511_FDvDw0	1639	// (internal1_m511_FDvDw0) - есть команда на движение назад
#define internal1_m511_FDvUp0	BUFFER[9069]	// (internal1_m511_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m511_FDvUp0	1640	// (internal1_m511_FDvUp0) - есть команда на движение вперёд
#define internal1_m511_Pkav0	BUFFER[9071]	// (internal1_m511_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m511_Pkav0	1641	// (internal1_m511_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m511_Pkv0	BUFFER[9073]	// (internal1_m511_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m511_Pkv0	1642	// (internal1_m511_Pkv0) Pkv - передний конечный выключатель
#define internal1_m511_Zkav0	BUFFER[9075]	// (internal1_m511_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m511_Zkav0	1643	// (internal1_m511_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m511_Zkv0	BUFFER[9077]	// (internal1_m511_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m511_Zkv0	1644	// (internal1_m511_Zkv0) Zkv - задний конечный выключатель
#define internal1_m511_fef	BUFFER[9079]	// (internal1_m511_fef) fef
#define idinternal1_m511_fef	1645	// (internal1_m511_fef) fef
#define internal1_m511_txHr	BUFFER[9081]	// (internal1_m511_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m511_txHr	1646	// (internal1_m511_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m511_txLd	BUFFER[9086]	// (internal1_m511_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m511_txLd	1647	// (internal1_m511_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m511_txNm	BUFFER[9091]	// (internal1_m511_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m511_txNm	1648	// (internal1_m511_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m511_txSm	BUFFER[9096]	// (internal1_m511_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m511_txSm	1649	// (internal1_m511_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m517_BlDv0	BUFFER[9101]	// (internal1_m517_BlDv0) - была блокировка
#define idinternal1_m517_BlDv0	1650	// (internal1_m517_BlDv0) - была блокировка
#define internal1_m517_DvDw0	BUFFER[9103]	// (internal1_m517_DvDw0) - есть команда на движение назад
#define idinternal1_m517_DvDw0	1651	// (internal1_m517_DvDw0) - есть команда на движение назад
#define internal1_m517_DvUp0	BUFFER[9105]	// (internal1_m517_DvUp0) - есть команда на движение вперёд
#define idinternal1_m517_DvUp0	1652	// (internal1_m517_DvUp0) - есть команда на движение вперёд
#define internal1_m517_FDvDw0	BUFFER[9107]	// (internal1_m517_FDvDw0) - есть команда на движение назад
#define idinternal1_m517_FDvDw0	1653	// (internal1_m517_FDvDw0) - есть команда на движение назад
#define internal1_m517_FDvUp0	BUFFER[9109]	// (internal1_m517_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m517_FDvUp0	1654	// (internal1_m517_FDvUp0) - есть команда на движение вперёд
#define internal1_m517_Pkav0	BUFFER[9111]	// (internal1_m517_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m517_Pkav0	1655	// (internal1_m517_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m517_Pkv0	BUFFER[9113]	// (internal1_m517_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m517_Pkv0	1656	// (internal1_m517_Pkv0) Pkv - передний конечный выключатель
#define internal1_m517_Zkav0	BUFFER[9115]	// (internal1_m517_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m517_Zkav0	1657	// (internal1_m517_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m517_Zkv0	BUFFER[9117]	// (internal1_m517_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m517_Zkv0	1658	// (internal1_m517_Zkv0) Zkv - задний конечный выключатель
#define internal1_m517_fef	BUFFER[9119]	// (internal1_m517_fef) fef
#define idinternal1_m517_fef	1659	// (internal1_m517_fef) fef
#define internal1_m517_txHr	BUFFER[9121]	// (internal1_m517_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m517_txHr	1660	// (internal1_m517_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m517_txLd	BUFFER[9126]	// (internal1_m517_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m517_txLd	1661	// (internal1_m517_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m517_txNm	BUFFER[9131]	// (internal1_m517_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m517_txNm	1662	// (internal1_m517_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m517_txSm	BUFFER[9136]	// (internal1_m517_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m517_txSm	1663	// (internal1_m517_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m525_tx	BUFFER[9141]	// (internal1_m525_tx) tx - внутренний параметр
#define idinternal1_m525_tx	1664	// (internal1_m525_tx) tx - внутренний параметр
#define internal1_m529_tx	BUFFER[9146]	// (internal1_m529_tx) tx - внутренний параметр
#define idinternal1_m529_tx	1665	// (internal1_m529_tx) tx - внутренний параметр
#define internal1_m52_tx	BUFFER[9151]	// (internal1_m52_tx) tx - внутренний параметр
#define idinternal1_m52_tx	1666	// (internal1_m52_tx) tx - внутренний параметр
#define internal1_m530_tx	BUFFER[9156]	// (internal1_m530_tx) tx - внутренний параметр
#define idinternal1_m530_tx	1667	// (internal1_m530_tx) tx - внутренний параметр
#define internal1_m531_tx	BUFFER[9161]	// (internal1_m531_tx) tx - внутренний параметр
#define idinternal1_m531_tx	1668	// (internal1_m531_tx) tx - внутренний параметр
#define internal1_m54_tim	BUFFER[9166]	// (internal1_m54_tim) - время задержки выходного сигнала
#define idinternal1_m54_tim	1669	// (internal1_m54_tim) - время задержки выходного сигнала
#define internal1_m54_x0	BUFFER[9171]	// (internal1_m54_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m54_x0	1670	// (internal1_m54_x0) - значение входного параметра на предыдущем шаге
#define internal1_m550_BLDv0	BUFFER[9173]	// (internal1_m550_BLDv0) BlDv - Блокировка движения
#define idinternal1_m550_BLDv0	1671	// (internal1_m550_BLDv0) BlDv - Блокировка движения
#define internal1_m550_X0	BUFFER[9175]	// (internal1_m550_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m550_X0	1672	// (internal1_m550_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m550_t0	BUFFER[9180]	// (internal1_m550_t0) время нахождения в зоне возврата
#define idinternal1_m550_t0	1673	// (internal1_m550_t0) время нахождения в зоне возврата
#define internal1_m568_tx	BUFFER[9185]	// (internal1_m568_tx) tx - время накопленное сек
#define idinternal1_m568_tx	1674	// (internal1_m568_tx) tx - время накопленное сек
#define internal1_m568_y0	BUFFER[9190]	// (internal1_m568_y0) y0
#define idinternal1_m568_y0	1675	// (internal1_m568_y0) y0
#define internal1_m569_tx	BUFFER[9192]	// (internal1_m569_tx) tx - время накопленное сек
#define idinternal1_m569_tx	1676	// (internal1_m569_tx) tx - время накопленное сек
#define internal1_m569_y0	BUFFER[9197]	// (internal1_m569_y0) y0
#define idinternal1_m569_y0	1677	// (internal1_m569_y0) y0
#define internal1_m573_DelSp	BUFFER[9199]	// (internal1_m573_DelSp) DelSp - время переключения скоростей
#define idinternal1_m573_DelSp	1678	// (internal1_m573_DelSp) DelSp - время переключения скоростей
#define internal1_m573_ShCntlSp0	BUFFER[9204]	// (internal1_m573_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m573_ShCntlSp0	1679	// (internal1_m573_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m573_Shift0	BUFFER[9206]	// (internal1_m573_Shift0) Shift0 - признак самохода
#define idinternal1_m573_Shift0	1680	// (internal1_m573_Shift0) Shift0 - признак самохода
#define internal1_m573_ShiftControl	BUFFER[9208]	// (internal1_m573_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m573_ShiftControl	1681	// (internal1_m573_ShiftControl) ShiftControl - признак самохода
#define internal1_m573_Speed0	BUFFER[9210]	// (internal1_m573_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m573_Speed0	1682	// (internal1_m573_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m573_StSpeed	BUFFER[9215]	// (internal1_m573_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m573_StSpeed	1683	// (internal1_m573_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m573_Vz0	BUFFER[9220]	// (internal1_m573_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m573_Vz0	1684	// (internal1_m573_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m573_flRazg	BUFFER[9225]	// (internal1_m573_flRazg) признак разгона/торможения
#define idinternal1_m573_flRazg	1685	// (internal1_m573_flRazg) признак разгона/торможения
#define internal1_m573_sumtim	BUFFER[9228]	// (internal1_m573_sumtim) sumtim - время в пути
#define idinternal1_m573_sumtim	1686	// (internal1_m573_sumtim) sumtim - время в пути
#define internal1_m573_tim0	BUFFER[9233]	// (internal1_m573_tim0) tim0 - массив значений времени цикла
#define idinternal1_m573_tim0	1687	// (internal1_m573_tim0) tim0 - массив значений времени цикла
#define internal1_m573_tx	BUFFER[9983]	// (internal1_m573_tx) tx
#define idinternal1_m573_tx	1688	// (internal1_m573_tx) tx
#define internal1_m573_txBl	BUFFER[9988]	// (internal1_m573_txBl) tx
#define idinternal1_m573_txBl	1689	// (internal1_m573_txBl) tx
#define internal1_m573_txMBl	BUFFER[9993]	// (internal1_m573_txMBl) tx
#define idinternal1_m573_txMBl	1690	// (internal1_m573_txMBl) tx
#define internal1_m573_txZS	BUFFER[9998]	// (internal1_m573_txZS) txZS
#define idinternal1_m573_txZS	1691	// (internal1_m573_txZS) txZS
#define internal1_m573_txd	BUFFER[10003]	// (internal1_m573_txd) txd
#define idinternal1_m573_txd	1692	// (internal1_m573_txd) txd
#define internal1_m573_tz0	BUFFER[10008]	// (internal1_m573_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m573_tz0	1693	// (internal1_m573_tz0) tz0 - время защиты от нового задания сек
#define internal1_m573_x0	BUFFER[10013]	// (internal1_m573_x0) x0 - массив мгновенных значений координат
#define idinternal1_m573_x0	1694	// (internal1_m573_x0) x0 - массив мгновенных значений координат
#define internal1_m573_xptr	BUFFER[10763]	// (internal1_m573_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m573_xptr	1695	// (internal1_m573_xptr) указатель текущей позиции в массиве координат
#define internal1_m573_xz0	BUFFER[10766]	// (internal1_m573_xz0) xz0 - новое задание мм
#define idinternal1_m573_xz0	1696	// (internal1_m573_xz0) xz0 - новое задание мм
#define internal1_m573_z0	BUFFER[10771]	// (internal1_m573_z0) z0 - точка прекращения движения
#define idinternal1_m573_z0	1697	// (internal1_m573_z0) z0 - точка прекращения движения
#define internal1_m574_tx	BUFFER[10776]	// (internal1_m574_tx) tx - внутренний параметр
#define idinternal1_m574_tx	1698	// (internal1_m574_tx) tx - внутренний параметр
#define internal1_m575_tx	BUFFER[10781]	// (internal1_m575_tx) tx - внутренний параметр
#define idinternal1_m575_tx	1699	// (internal1_m575_tx) tx - внутренний параметр
#define internal1_m576_tx	BUFFER[10786]	// (internal1_m576_tx) tx - внутренний параметр
#define idinternal1_m576_tx	1700	// (internal1_m576_tx) tx - внутренний параметр
#define internal1_m581_tx	BUFFER[10791]	// (internal1_m581_tx) tx - внутренний параметр
#define idinternal1_m581_tx	1701	// (internal1_m581_tx) tx - внутренний параметр
#define internal1_m588_tx	BUFFER[10796]	// (internal1_m588_tx) tx - время накопленное сек
#define idinternal1_m588_tx	1702	// (internal1_m588_tx) tx - время накопленное сек
#define internal1_m588_y0	BUFFER[10801]	// (internal1_m588_y0) y0
#define idinternal1_m588_y0	1703	// (internal1_m588_y0) y0
#define internal1_m594_tx	BUFFER[10803]	// (internal1_m594_tx) tx - внутренний параметр
#define idinternal1_m594_tx	1704	// (internal1_m594_tx) tx - внутренний параметр
#define internal1_m595_tx	BUFFER[10808]	// (internal1_m595_tx) tx - внутренний параметр
#define idinternal1_m595_tx	1705	// (internal1_m595_tx) tx - внутренний параметр
#define internal1_m597_tx	BUFFER[10813]	// (internal1_m597_tx) tx - внутренний параметр
#define idinternal1_m597_tx	1706	// (internal1_m597_tx) tx - внутренний параметр
#define internal1_m607_tx	BUFFER[10818]	// (internal1_m607_tx) tx - внутренний параметр
#define idinternal1_m607_tx	1707	// (internal1_m607_tx) tx - внутренний параметр
#define internal1_m611_tx	BUFFER[10823]	// (internal1_m611_tx) tx - внутренний параметр
#define idinternal1_m611_tx	1708	// (internal1_m611_tx) tx - внутренний параметр
#define internal1_m612_tx	BUFFER[10828]	// (internal1_m612_tx) tx - внутренний параметр
#define idinternal1_m612_tx	1709	// (internal1_m612_tx) tx - внутренний параметр
#define internal1_m622_tx	BUFFER[10833]	// (internal1_m622_tx) tx - внутренний параметр
#define idinternal1_m622_tx	1710	// (internal1_m622_tx) tx - внутренний параметр
#define internal1_m626_tx	BUFFER[10838]	// (internal1_m626_tx) tx - внутренний параметр
#define idinternal1_m626_tx	1711	// (internal1_m626_tx) tx - внутренний параметр
#define internal1_m628_tx	BUFFER[10843]	// (internal1_m628_tx) tx - внутренний параметр
#define idinternal1_m628_tx	1712	// (internal1_m628_tx) tx - внутренний параметр
#define internal1_m635_tx	BUFFER[10848]	// (internal1_m635_tx) tx - внутренний параметр
#define idinternal1_m635_tx	1713	// (internal1_m635_tx) tx - внутренний параметр
#define internal1_m637_tx	BUFFER[10853]	// (internal1_m637_tx) tx - внутренний параметр
#define idinternal1_m637_tx	1714	// (internal1_m637_tx) tx - внутренний параметр
#define internal1_m638_tx	BUFFER[10858]	// (internal1_m638_tx) tx - внутренний параметр
#define idinternal1_m638_tx	1715	// (internal1_m638_tx) tx - внутренний параметр
#define internal1_m639_tx	BUFFER[10863]	// (internal1_m639_tx) tx - внутренний параметр
#define idinternal1_m639_tx	1716	// (internal1_m639_tx) tx - внутренний параметр
#define internal1_m640_tx	BUFFER[10868]	// (internal1_m640_tx) tx - внутренний параметр
#define idinternal1_m640_tx	1717	// (internal1_m640_tx) tx - внутренний параметр
#define internal1_m667_q0	BUFFER[10873]	// (internal1_m667_q0) q0 - внутренний параметр
#define idinternal1_m667_q0	1718	// (internal1_m667_q0) q0 - внутренний параметр
#define internal1_m677_q0	BUFFER[10875]	// (internal1_m677_q0) q0 - внутренний параметр
#define idinternal1_m677_q0	1719	// (internal1_m677_q0) q0 - внутренний параметр
#define internal1_m687_q0	BUFFER[10877]	// (internal1_m687_q0) q0 - внутренний параметр
#define idinternal1_m687_q0	1720	// (internal1_m687_q0) q0 - внутренний параметр
#define internal1_m689_q0	BUFFER[10879]	// (internal1_m689_q0) q0 - внутренний параметр
#define idinternal1_m689_q0	1721	// (internal1_m689_q0) q0 - внутренний параметр
#define internal1_m691_q0	BUFFER[10881]	// (internal1_m691_q0) q0 - внутренний параметр
#define idinternal1_m691_q0	1722	// (internal1_m691_q0) q0 - внутренний параметр
#define internal1_m692_q0	BUFFER[10883]	// (internal1_m692_q0) q0 - внутренний параметр
#define idinternal1_m692_q0	1723	// (internal1_m692_q0) q0 - внутренний параметр
#define internal1_m694_q0	BUFFER[10885]	// (internal1_m694_q0) q0 - внутренний параметр
#define idinternal1_m694_q0	1724	// (internal1_m694_q0) q0 - внутренний параметр
#define internal1_m696_q0	BUFFER[10887]	// (internal1_m696_q0) q0 - внутренний параметр
#define idinternal1_m696_q0	1725	// (internal1_m696_q0) q0 - внутренний параметр
#define internal1_m697_q0	BUFFER[10889]	// (internal1_m697_q0) q0 - внутренний параметр
#define idinternal1_m697_q0	1726	// (internal1_m697_q0) q0 - внутренний параметр
#define internal1_m699_q0	BUFFER[10891]	// (internal1_m699_q0) q0 - внутренний параметр
#define idinternal1_m699_q0	1727	// (internal1_m699_q0) q0 - внутренний параметр
#define internal1_m702_q0	BUFFER[10893]	// (internal1_m702_q0) q0 - внутренний параметр
#define idinternal1_m702_q0	1728	// (internal1_m702_q0) q0 - внутренний параметр
#define internal1_m707_q0	BUFFER[10895]	// (internal1_m707_q0) q0 - внутренний параметр
#define idinternal1_m707_q0	1729	// (internal1_m707_q0) q0 - внутренний параметр
#define internal1_m711_q0	BUFFER[10897]	// (internal1_m711_q0) q0 - внутренний параметр
#define idinternal1_m711_q0	1730	// (internal1_m711_q0) q0 - внутренний параметр
#define internal1_m712_q0	BUFFER[10899]	// (internal1_m712_q0) q0 - внутренний параметр
#define idinternal1_m712_q0	1731	// (internal1_m712_q0) q0 - внутренний параметр
#define internal1_m720_q0	BUFFER[10901]	// (internal1_m720_q0) q0 - внутренний параметр
#define idinternal1_m720_q0	1732	// (internal1_m720_q0) q0 - внутренний параметр
#define internal1_m724_q0	BUFFER[10903]	// (internal1_m724_q0) q0 - внутренний параметр
#define idinternal1_m724_q0	1733	// (internal1_m724_q0) q0 - внутренний параметр
#define internal1_m735_tx	BUFFER[10905]	// (internal1_m735_tx) tx - внутренний параметр
#define idinternal1_m735_tx	1734	// (internal1_m735_tx) tx - внутренний параметр
#define internal1_m741_x0	BUFFER[10910]	// (internal1_m741_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m741_x0	1735	// (internal1_m741_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m742_tx	BUFFER[10912]	// (internal1_m742_tx) tx - внутренний параметр
#define idinternal1_m742_tx	1736	// (internal1_m742_tx) tx - внутренний параметр
#define internal1_m746_tx	BUFFER[10917]	// (internal1_m746_tx) tx - внутренний параметр
#define idinternal1_m746_tx	1737	// (internal1_m746_tx) tx - внутренний параметр
#define internal1_m750_tx	BUFFER[10922]	// (internal1_m750_tx) tx - внутренний параметр
#define idinternal1_m750_tx	1738	// (internal1_m750_tx) tx - внутренний параметр
#define internal1_m761_tx	BUFFER[10927]	// (internal1_m761_tx) tx - внутренний параметр
#define idinternal1_m761_tx	1739	// (internal1_m761_tx) tx - внутренний параметр
#define internal1_m766_tx	BUFFER[10932]	// (internal1_m766_tx) tx - внутренний параметр
#define idinternal1_m766_tx	1740	// (internal1_m766_tx) tx - внутренний параметр
#define internal1_m767_tx	BUFFER[10937]	// (internal1_m767_tx) tx - внутренний параметр
#define idinternal1_m767_tx	1741	// (internal1_m767_tx) tx - внутренний параметр
#define internal1_m770_tx	BUFFER[10942]	// (internal1_m770_tx) tx - внутренний параметр
#define idinternal1_m770_tx	1742	// (internal1_m770_tx) tx - внутренний параметр
#define internal1_m775_tx	BUFFER[10947]	// (internal1_m775_tx) tx - внутренний параметр
#define idinternal1_m775_tx	1743	// (internal1_m775_tx) tx - внутренний параметр
#define internal1_m777_tx	BUFFER[10952]	// (internal1_m777_tx) tx - внутренний параметр
#define idinternal1_m777_tx	1744	// (internal1_m777_tx) tx - внутренний параметр
#define internal1_m785_tx	BUFFER[10957]	// (internal1_m785_tx) tx - внутренний параметр
#define idinternal1_m785_tx	1745	// (internal1_m785_tx) tx - внутренний параметр
#define internal1_m794_tx	BUFFER[10962]	// (internal1_m794_tx) tx - внутренний параметр
#define idinternal1_m794_tx	1746	// (internal1_m794_tx) tx - внутренний параметр
#define internal1_m795_tx	BUFFER[10967]	// (internal1_m795_tx) tx - внутренний параметр
#define idinternal1_m795_tx	1747	// (internal1_m795_tx) tx - внутренний параметр
#define internal1_m796_tx	BUFFER[10972]	// (internal1_m796_tx) tx - внутренний параметр
#define idinternal1_m796_tx	1748	// (internal1_m796_tx) tx - внутренний параметр
#define internal1_m797_tx	BUFFER[10977]	// (internal1_m797_tx) tx - внутренний параметр
#define idinternal1_m797_tx	1749	// (internal1_m797_tx) tx - внутренний параметр
#define internal1_m799_x0	BUFFER[10982]	// (internal1_m799_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m799_x0	1750	// (internal1_m799_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m79_MyFirstEnterFlag	BUFFER[10984]	// (internal1_m79_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m79_MyFirstEnterFlag	1751	// (internal1_m79_MyFirstEnterFlag)  FirstEnterFlag
#define internal1_m79_W1	BUFFER[10986]	// (internal1_m79_W1)  мощность на старте измерения
#define idinternal1_m79_W1	1752	// (internal1_m79_W1)  мощность на старте измерения
#define internal1_m79_W2	BUFFER[10991]	// (internal1_m79_W2)  мощность в конце измерения
#define idinternal1_m79_W2	1753	// (internal1_m79_W2)  мощность в конце измерения
#define internal1_m79_Wlast	BUFFER[10996]	// (internal1_m79_Wlast)  последнее растущее измерение
#define idinternal1_m79_Wlast	1754	// (internal1_m79_Wlast)  последнее растущее измерение
#define internal1_m79_Wmax	BUFFER[11001]	// (internal1_m79_Wmax)  максимальное измерение в серии
#define idinternal1_m79_Wmax	1755	// (internal1_m79_Wmax)  максимальное измерение в серии
#define internal1_m79_Wmin	BUFFER[11006]	// (internal1_m79_Wmin)  минимальное измерение в серии
#define idinternal1_m79_Wmin	1756	// (internal1_m79_Wmin)  минимальное измерение в серии
#define internal1_m79_chizm	BUFFER[11011]	// (internal1_m79_chizm)  счетчик уменьшения мощности
#define idinternal1_m79_chizm	1757	// (internal1_m79_chizm)  счетчик уменьшения мощности
#define internal1_m79_chsr	BUFFER[11014]	// (internal1_m79_chsr)  счетчик усреднения
#define idinternal1_m79_chsr	1758	// (internal1_m79_chsr)  счетчик усреднения
#define internal1_m79_flst	BUFFER[11017]	// (internal1_m79_flst)  флаг старта измерения
#define idinternal1_m79_flst	1759	// (internal1_m79_flst)  флаг старта измерения
#define internal1_m79_sumtim	BUFFER[11020]	// (internal1_m79_sumtim)  время измерения мощности
#define idinternal1_m79_sumtim	1760	// (internal1_m79_sumtim)  время измерения мощности
#define internal1_m79_y0	BUFFER[11025]	// (internal1_m79_y0) y0 - внутренний параметр
#define idinternal1_m79_y0	1761	// (internal1_m79_y0) y0 - внутренний параметр
#define internal1_m818_q0	BUFFER[11030]	// (internal1_m818_q0) q0 - внутренний параметр
#define idinternal1_m818_q0	1762	// (internal1_m818_q0) q0 - внутренний параметр
#define internal1_m820_q0	BUFFER[11032]	// (internal1_m820_q0) q0 - внутренний параметр
#define idinternal1_m820_q0	1763	// (internal1_m820_q0) q0 - внутренний параметр
#define internal1_m822_q0	BUFFER[11034]	// (internal1_m822_q0) q0 - внутренний параметр
#define idinternal1_m822_q0	1764	// (internal1_m822_q0) q0 - внутренний параметр
#define internal1_m824_q0	BUFFER[11036]	// (internal1_m824_q0) q0 - внутренний параметр
#define idinternal1_m824_q0	1765	// (internal1_m824_q0) q0 - внутренний параметр
#define internal1_m827_q0	BUFFER[11038]	// (internal1_m827_q0) q0 - внутренний параметр
#define idinternal1_m827_q0	1766	// (internal1_m827_q0) q0 - внутренний параметр
#define internal1_m82_tx	BUFFER[11040]	// (internal1_m82_tx) tx - внутренний параметр
#define idinternal1_m82_tx	1767	// (internal1_m82_tx) tx - внутренний параметр
#define internal1_m830_x0	BUFFER[11045]	// (internal1_m830_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m830_x0	1768	// (internal1_m830_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m831_q0	BUFFER[11047]	// (internal1_m831_q0) q0 - внутренний параметр
#define idinternal1_m831_q0	1769	// (internal1_m831_q0) q0 - внутренний параметр
#define internal1_m834_tx	BUFFER[11049]	// (internal1_m834_tx) tx - время накопленное сек
#define idinternal1_m834_tx	1770	// (internal1_m834_tx) tx - время накопленное сек
#define internal1_m834_y0	BUFFER[11054]	// (internal1_m834_y0) y0
#define idinternal1_m834_y0	1771	// (internal1_m834_y0) y0
#define internal1_m835_tx	BUFFER[11056]	// (internal1_m835_tx) tx - внутренний параметр
#define idinternal1_m835_tx	1772	// (internal1_m835_tx) tx - внутренний параметр
#define internal1_m836_q0	BUFFER[11061]	// (internal1_m836_q0) q0 - внутренний параметр
#define idinternal1_m836_q0	1773	// (internal1_m836_q0) q0 - внутренний параметр
#define internal1_m843_q0	BUFFER[11063]	// (internal1_m843_q0) q0 - внутренний параметр
#define idinternal1_m843_q0	1774	// (internal1_m843_q0) q0 - внутренний параметр
#define internal1_m850_q0	BUFFER[11065]	// (internal1_m850_q0) q0 - внутренний параметр
#define idinternal1_m850_q0	1775	// (internal1_m850_q0) q0 - внутренний параметр
#define internal1_m855_q0	BUFFER[11067]	// (internal1_m855_q0) q0 - внутренний параметр
#define idinternal1_m855_q0	1776	// (internal1_m855_q0) q0 - внутренний параметр
#define internal1_m864_tx	BUFFER[11069]	// (internal1_m864_tx) tx - внутренний параметр
#define idinternal1_m864_tx	1777	// (internal1_m864_tx) tx - внутренний параметр
#define internal1_m865_tx	BUFFER[11074]	// (internal1_m865_tx) tx - внутренний параметр
#define idinternal1_m865_tx	1778	// (internal1_m865_tx) tx - внутренний параметр
#define internal1_m866_tx	BUFFER[11079]	// (internal1_m866_tx) tx - внутренний параметр
#define idinternal1_m866_tx	1779	// (internal1_m866_tx) tx - внутренний параметр
#define internal1_m870_tx	BUFFER[11084]	// (internal1_m870_tx) tx - внутренний параметр
#define idinternal1_m870_tx	1780	// (internal1_m870_tx) tx - внутренний параметр
#define internal1_m875_BlDv0	BUFFER[11089]	// (internal1_m875_BlDv0) - была блокировка
#define idinternal1_m875_BlDv0	1781	// (internal1_m875_BlDv0) - была блокировка
#define internal1_m875_DvDw0	BUFFER[11091]	// (internal1_m875_DvDw0) - есть команда на движение назад
#define idinternal1_m875_DvDw0	1782	// (internal1_m875_DvDw0) - есть команда на движение назад
#define internal1_m875_DvUp0	BUFFER[11093]	// (internal1_m875_DvUp0) - есть команда на движение вперёд
#define idinternal1_m875_DvUp0	1783	// (internal1_m875_DvUp0) - есть команда на движение вперёд
#define internal1_m875_FDvDw0	BUFFER[11095]	// (internal1_m875_FDvDw0) - есть команда на движение назад
#define idinternal1_m875_FDvDw0	1784	// (internal1_m875_FDvDw0) - есть команда на движение назад
#define internal1_m875_FDvUp0	BUFFER[11097]	// (internal1_m875_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m875_FDvUp0	1785	// (internal1_m875_FDvUp0) - есть команда на движение вперёд
#define internal1_m875_Pkav0	BUFFER[11099]	// (internal1_m875_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m875_Pkav0	1786	// (internal1_m875_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m875_Pkv0	BUFFER[11101]	// (internal1_m875_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m875_Pkv0	1787	// (internal1_m875_Pkv0) Pkv - передний конечный выключатель
#define internal1_m875_Zkav0	BUFFER[11103]	// (internal1_m875_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m875_Zkav0	1788	// (internal1_m875_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m875_Zkv0	BUFFER[11105]	// (internal1_m875_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m875_Zkv0	1789	// (internal1_m875_Zkv0) Zkv - задний конечный выключатель
#define internal1_m875_fef	BUFFER[11107]	// (internal1_m875_fef) fef
#define idinternal1_m875_fef	1790	// (internal1_m875_fef) fef
#define internal1_m875_txHr	BUFFER[11109]	// (internal1_m875_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m875_txHr	1791	// (internal1_m875_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m875_txLd	BUFFER[11114]	// (internal1_m875_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m875_txLd	1792	// (internal1_m875_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m875_txNm	BUFFER[11119]	// (internal1_m875_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m875_txNm	1793	// (internal1_m875_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m875_txSm	BUFFER[11124]	// (internal1_m875_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m875_txSm	1794	// (internal1_m875_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m879_BlDv0	BUFFER[11129]	// (internal1_m879_BlDv0) - была блокировка
#define idinternal1_m879_BlDv0	1795	// (internal1_m879_BlDv0) - была блокировка
#define internal1_m879_DvDw0	BUFFER[11131]	// (internal1_m879_DvDw0) - есть команда на движение назад
#define idinternal1_m879_DvDw0	1796	// (internal1_m879_DvDw0) - есть команда на движение назад
#define internal1_m879_DvUp0	BUFFER[11133]	// (internal1_m879_DvUp0) - есть команда на движение вперёд
#define idinternal1_m879_DvUp0	1797	// (internal1_m879_DvUp0) - есть команда на движение вперёд
#define internal1_m879_FDvDw0	BUFFER[11135]	// (internal1_m879_FDvDw0) - есть команда на движение назад
#define idinternal1_m879_FDvDw0	1798	// (internal1_m879_FDvDw0) - есть команда на движение назад
#define internal1_m879_FDvUp0	BUFFER[11137]	// (internal1_m879_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m879_FDvUp0	1799	// (internal1_m879_FDvUp0) - есть команда на движение вперёд
#define internal1_m879_Pkav0	BUFFER[11139]	// (internal1_m879_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m879_Pkav0	1800	// (internal1_m879_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m879_Pkv0	BUFFER[11141]	// (internal1_m879_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m879_Pkv0	1801	// (internal1_m879_Pkv0) Pkv - передний конечный выключатель
#define internal1_m879_Zkav0	BUFFER[11143]	// (internal1_m879_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m879_Zkav0	1802	// (internal1_m879_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m879_Zkv0	BUFFER[11145]	// (internal1_m879_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m879_Zkv0	1803	// (internal1_m879_Zkv0) Zkv - задний конечный выключатель
#define internal1_m879_fef	BUFFER[11147]	// (internal1_m879_fef) fef
#define idinternal1_m879_fef	1804	// (internal1_m879_fef) fef
#define internal1_m879_txHr	BUFFER[11149]	// (internal1_m879_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m879_txHr	1805	// (internal1_m879_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m879_txLd	BUFFER[11154]	// (internal1_m879_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m879_txLd	1806	// (internal1_m879_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m879_txNm	BUFFER[11159]	// (internal1_m879_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m879_txNm	1807	// (internal1_m879_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m879_txSm	BUFFER[11164]	// (internal1_m879_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m879_txSm	1808	// (internal1_m879_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m887_tx	BUFFER[11169]	// (internal1_m887_tx) tx - внутренний параметр
#define idinternal1_m887_tx	1809	// (internal1_m887_tx) tx - внутренний параметр
#define internal1_m891_tx	BUFFER[11174]	// (internal1_m891_tx) tx - внутренний параметр
#define idinternal1_m891_tx	1810	// (internal1_m891_tx) tx - внутренний параметр
#define internal1_m892_tx	BUFFER[11179]	// (internal1_m892_tx) tx - внутренний параметр
#define idinternal1_m892_tx	1811	// (internal1_m892_tx) tx - внутренний параметр
#define internal1_m893_tx	BUFFER[11184]	// (internal1_m893_tx) tx - внутренний параметр
#define idinternal1_m893_tx	1812	// (internal1_m893_tx) tx - внутренний параметр
#define internal1_m909_BLDv0	BUFFER[11189]	// (internal1_m909_BLDv0) BlDv - Блокировка движения
#define idinternal1_m909_BLDv0	1813	// (internal1_m909_BLDv0) BlDv - Блокировка движения
#define internal1_m909_X0	BUFFER[11191]	// (internal1_m909_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m909_X0	1814	// (internal1_m909_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m909_t0	BUFFER[11196]	// (internal1_m909_t0) время нахождения в зоне возврата
#define idinternal1_m909_t0	1815	// (internal1_m909_t0) время нахождения в зоне возврата
#define internal1_m921_tx	BUFFER[11201]	// (internal1_m921_tx) tx - время накопленное сек
#define idinternal1_m921_tx	1816	// (internal1_m921_tx) tx - время накопленное сек
#define internal1_m921_y0	BUFFER[11206]	// (internal1_m921_y0) y0
#define idinternal1_m921_y0	1817	// (internal1_m921_y0) y0
#define internal1_m922_tx	BUFFER[11208]	// (internal1_m922_tx) tx - время накопленное сек
#define idinternal1_m922_tx	1818	// (internal1_m922_tx) tx - время накопленное сек
#define internal1_m922_y0	BUFFER[11213]	// (internal1_m922_y0) y0
#define idinternal1_m922_y0	1819	// (internal1_m922_y0) y0
#define internal1_m924_tx	BUFFER[11215]	// (internal1_m924_tx) tx - внутренний параметр
#define idinternal1_m924_tx	1820	// (internal1_m924_tx) tx - внутренний параметр
#define internal1_m925_tx	BUFFER[11220]	// (internal1_m925_tx) tx - внутренний параметр
#define idinternal1_m925_tx	1821	// (internal1_m925_tx) tx - внутренний параметр
#define internal1_m927_DelSp	BUFFER[11225]	// (internal1_m927_DelSp) DelSp - время переключения скоростей
#define idinternal1_m927_DelSp	1822	// (internal1_m927_DelSp) DelSp - время переключения скоростей
#define internal1_m927_ShCntlSp0	BUFFER[11230]	// (internal1_m927_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m927_ShCntlSp0	1823	// (internal1_m927_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m927_Shift0	BUFFER[11232]	// (internal1_m927_Shift0) Shift0 - признак самохода
#define idinternal1_m927_Shift0	1824	// (internal1_m927_Shift0) Shift0 - признак самохода
#define internal1_m927_ShiftControl	BUFFER[11234]	// (internal1_m927_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m927_ShiftControl	1825	// (internal1_m927_ShiftControl) ShiftControl - признак самохода
#define internal1_m927_Speed0	BUFFER[11236]	// (internal1_m927_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m927_Speed0	1826	// (internal1_m927_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m927_StSpeed	BUFFER[11241]	// (internal1_m927_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m927_StSpeed	1827	// (internal1_m927_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m927_Vz0	BUFFER[11246]	// (internal1_m927_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m927_Vz0	1828	// (internal1_m927_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m927_flRazg	BUFFER[11251]	// (internal1_m927_flRazg) признак разгона/торможения
#define idinternal1_m927_flRazg	1829	// (internal1_m927_flRazg) признак разгона/торможения
#define internal1_m927_sumtim	BUFFER[11254]	// (internal1_m927_sumtim) sumtim - время в пути
#define idinternal1_m927_sumtim	1830	// (internal1_m927_sumtim) sumtim - время в пути
#define internal1_m927_tim0	BUFFER[11259]	// (internal1_m927_tim0) tim0 - массив значений времени цикла
#define idinternal1_m927_tim0	1831	// (internal1_m927_tim0) tim0 - массив значений времени цикла
#define internal1_m927_tx	BUFFER[11659]	// (internal1_m927_tx) tx
#define idinternal1_m927_tx	1832	// (internal1_m927_tx) tx
#define internal1_m927_txBl	BUFFER[11664]	// (internal1_m927_txBl) tx
#define idinternal1_m927_txBl	1833	// (internal1_m927_txBl) tx
#define internal1_m927_txMBl	BUFFER[11669]	// (internal1_m927_txMBl) tx
#define idinternal1_m927_txMBl	1834	// (internal1_m927_txMBl) tx
#define internal1_m927_txZS	BUFFER[11674]	// (internal1_m927_txZS) txZS
#define idinternal1_m927_txZS	1835	// (internal1_m927_txZS) txZS
#define internal1_m927_txd	BUFFER[11679]	// (internal1_m927_txd) txd
#define idinternal1_m927_txd	1836	// (internal1_m927_txd) txd
#define internal1_m927_tz0	BUFFER[11684]	// (internal1_m927_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m927_tz0	1837	// (internal1_m927_tz0) tz0 - время защиты от нового задания сек
#define internal1_m927_x0	BUFFER[11689]	// (internal1_m927_x0) x0 - массив мгновенных значений координат
#define idinternal1_m927_x0	1838	// (internal1_m927_x0) x0 - массив мгновенных значений координат
#define internal1_m927_xptr	BUFFER[12089]	// (internal1_m927_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m927_xptr	1839	// (internal1_m927_xptr) указатель текущей позиции в массиве координат
#define internal1_m927_xz0	BUFFER[12092]	// (internal1_m927_xz0) xz0 - новое задание мм
#define idinternal1_m927_xz0	1840	// (internal1_m927_xz0) xz0 - новое задание мм
#define internal1_m927_z0	BUFFER[12097]	// (internal1_m927_z0) z0 - точка прекращения движения
#define idinternal1_m927_z0	1841	// (internal1_m927_z0) z0 - точка прекращения движения
#define internal1_m929_tx	BUFFER[12102]	// (internal1_m929_tx) tx - внутренний параметр
#define idinternal1_m929_tx	1842	// (internal1_m929_tx) tx - внутренний параметр
#define internal1_m934_tx	BUFFER[12107]	// (internal1_m934_tx) tx - внутренний параметр
#define idinternal1_m934_tx	1843	// (internal1_m934_tx) tx - внутренний параметр
#define internal1_m939_tx	BUFFER[12112]	// (internal1_m939_tx) tx - время накопленное сек
#define idinternal1_m939_tx	1844	// (internal1_m939_tx) tx - время накопленное сек
#define internal1_m939_y0	BUFFER[12117]	// (internal1_m939_y0) y0
#define idinternal1_m939_y0	1845	// (internal1_m939_y0) y0
#define internal1_m949_tx	BUFFER[12119]	// (internal1_m949_tx) tx - внутренний параметр
#define idinternal1_m949_tx	1846	// (internal1_m949_tx) tx - внутренний параметр
#define internal1_m950_tx	BUFFER[12124]	// (internal1_m950_tx) tx - внутренний параметр
#define idinternal1_m950_tx	1847	// (internal1_m950_tx) tx - внутренний параметр
#define internal1_m952_tx	BUFFER[12129]	// (internal1_m952_tx) tx - внутренний параметр
#define idinternal1_m952_tx	1848	// (internal1_m952_tx) tx - внутренний параметр
#define internal1_m963_tx	BUFFER[12134]	// (internal1_m963_tx) tx - внутренний параметр
#define idinternal1_m963_tx	1849	// (internal1_m963_tx) tx - внутренний параметр
#define internal1_m967_tx	BUFFER[12139]	// (internal1_m967_tx) tx - внутренний параметр
#define idinternal1_m967_tx	1850	// (internal1_m967_tx) tx - внутренний параметр
#define internal1_m969_tx	BUFFER[12144]	// (internal1_m969_tx) tx - внутренний параметр
#define idinternal1_m969_tx	1851	// (internal1_m969_tx) tx - внутренний параметр
#define internal1_m977_tx	BUFFER[12149]	// (internal1_m977_tx) tx - внутренний параметр
#define idinternal1_m977_tx	1852	// (internal1_m977_tx) tx - внутренний параметр
#define internal1_m979_tx	BUFFER[12154]	// (internal1_m979_tx) tx - внутренний параметр
#define idinternal1_m979_tx	1853	// (internal1_m979_tx) tx - внутренний параметр
#define internal1_m984_tx	BUFFER[12159]	// (internal1_m984_tx) tx - внутренний параметр
#define idinternal1_m984_tx	1854	// (internal1_m984_tx) tx - внутренний параметр
#define internal1_m985_tx	BUFFER[12164]	// (internal1_m985_tx) tx - внутренний параметр
#define idinternal1_m985_tx	1855	// (internal1_m985_tx) tx - внутренний параметр
#define internal1_m986_tx	BUFFER[12169]	// (internal1_m986_tx) tx - внутренний параметр
#define idinternal1_m986_tx	1856	// (internal1_m986_tx) tx - внутренний параметр
#define internal1_m989_tx	BUFFER[12174]	// (internal1_m989_tx) tx - внутренний параметр
#define idinternal1_m989_tx	1857	// (internal1_m989_tx) tx - внутренний параметр
#define internal2_m106_Nk0	BUFFER[12179]	// (internal2_m106_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m106_Nk0	1858	// (internal2_m106_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m106_SetFlag	BUFFER[12184]	// (internal2_m106_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m106_SetFlag	1859	// (internal2_m106_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m110_Nk0	BUFFER[12186]	// (internal2_m110_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m110_Nk0	1860	// (internal2_m110_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m110_SetFlag	BUFFER[12191]	// (internal2_m110_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m110_SetFlag	1861	// (internal2_m110_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m127_tx	BUFFER[12193]	// (internal2_m127_tx) tx - время накопленное сек
#define idinternal2_m127_tx	1862	// (internal2_m127_tx) tx - время накопленное сек
#define internal2_m127_y0	BUFFER[12198]	// (internal2_m127_y0) y0
#define idinternal2_m127_y0	1863	// (internal2_m127_y0) y0
#define internal2_m131_tx	BUFFER[12200]	// (internal2_m131_tx) tx - время накопленное сек
#define idinternal2_m131_tx	1864	// (internal2_m131_tx) tx - время накопленное сек
#define internal2_m131_y0	BUFFER[12205]	// (internal2_m131_y0) y0
#define idinternal2_m131_y0	1865	// (internal2_m131_y0) y0
#define internal2_m137_tx	BUFFER[12207]	// (internal2_m137_tx) tx - время накопленное сек
#define idinternal2_m137_tx	1866	// (internal2_m137_tx) tx - время накопленное сек
#define internal2_m137_y0	BUFFER[12212]	// (internal2_m137_y0) y0
#define idinternal2_m137_y0	1867	// (internal2_m137_y0) y0
#define internal2_m141_tx	BUFFER[12214]	// (internal2_m141_tx) tx - время накопленное сек
#define idinternal2_m141_tx	1868	// (internal2_m141_tx) tx - время накопленное сек
#define internal2_m141_y0	BUFFER[12219]	// (internal2_m141_y0) y0
#define idinternal2_m141_y0	1869	// (internal2_m141_y0) y0
#define internal2_m144_tx	BUFFER[12221]	// (internal2_m144_tx) tx - время накопленное сек
#define idinternal2_m144_tx	1870	// (internal2_m144_tx) tx - время накопленное сек
#define internal2_m144_y0	BUFFER[12226]	// (internal2_m144_y0) y0
#define idinternal2_m144_y0	1871	// (internal2_m144_y0) y0
#define internal2_m149_tx	BUFFER[12228]	// (internal2_m149_tx) tx - время накопленное сек
#define idinternal2_m149_tx	1872	// (internal2_m149_tx) tx - время накопленное сек
#define internal2_m149_y0	BUFFER[12233]	// (internal2_m149_y0) y0
#define idinternal2_m149_y0	1873	// (internal2_m149_y0) y0
#define internal2_m155_tx	BUFFER[12235]	// (internal2_m155_tx) tx - время накопленное сек
#define idinternal2_m155_tx	1874	// (internal2_m155_tx) tx - время накопленное сек
#define internal2_m155_y0	BUFFER[12240]	// (internal2_m155_y0) y0
#define idinternal2_m155_y0	1875	// (internal2_m155_y0) y0
#define internal2_m157_tx	BUFFER[12242]	// (internal2_m157_tx) tx - время накопленное сек
#define idinternal2_m157_tx	1876	// (internal2_m157_tx) tx - время накопленное сек
#define internal2_m157_y0	BUFFER[12247]	// (internal2_m157_y0) y0
#define idinternal2_m157_y0	1877	// (internal2_m157_y0) y0
#define internal2_m165_tx	BUFFER[12249]	// (internal2_m165_tx) tx - время накопленное сек
#define idinternal2_m165_tx	1878	// (internal2_m165_tx) tx - время накопленное сек
#define internal2_m165_y0	BUFFER[12254]	// (internal2_m165_y0) y0
#define idinternal2_m165_y0	1879	// (internal2_m165_y0) y0
#define internal2_m16_Nk0	BUFFER[12256]	// (internal2_m16_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m16_Nk0	1880	// (internal2_m16_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m16_SetFlag	BUFFER[12261]	// (internal2_m16_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m16_SetFlag	1881	// (internal2_m16_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m172_tx	BUFFER[12263]	// (internal2_m172_tx) tx - время накопленное сек
#define idinternal2_m172_tx	1882	// (internal2_m172_tx) tx - время накопленное сек
#define internal2_m172_y0	BUFFER[12268]	// (internal2_m172_y0) y0
#define idinternal2_m172_y0	1883	// (internal2_m172_y0) y0
#define internal2_m176_tx	BUFFER[12270]	// (internal2_m176_tx) tx - время накопленное сек
#define idinternal2_m176_tx	1884	// (internal2_m176_tx) tx - время накопленное сек
#define internal2_m176_y0	BUFFER[12275]	// (internal2_m176_y0) y0
#define idinternal2_m176_y0	1885	// (internal2_m176_y0) y0
#define internal2_m182_tx	BUFFER[12277]	// (internal2_m182_tx) tx - время накопленное сек
#define idinternal2_m182_tx	1886	// (internal2_m182_tx) tx - время накопленное сек
#define internal2_m182_y0	BUFFER[12282]	// (internal2_m182_y0) y0
#define idinternal2_m182_y0	1887	// (internal2_m182_y0) y0
#define internal2_m193_y0	BUFFER[12284]	// (internal2_m193_y0) y0
#define idinternal2_m193_y0	1888	// (internal2_m193_y0) y0
#define internal2_m195_y0	BUFFER[12289]	// (internal2_m195_y0) y0
#define idinternal2_m195_y0	1889	// (internal2_m195_y0) y0
#define internal2_m198_y1	BUFFER[12294]	// (internal2_m198_y1) y1 - внутренний параметр
#define idinternal2_m198_y1	1890	// (internal2_m198_y1) y1 - внутренний параметр
#define internal2_m205_y1	BUFFER[12296]	// (internal2_m205_y1) y1 - внутренний параметр
#define idinternal2_m205_y1	1891	// (internal2_m205_y1) y1 - внутренний параметр
#define internal2_m208_y1	BUFFER[12298]	// (internal2_m208_y1) y1 - внутренний параметр
#define idinternal2_m208_y1	1892	// (internal2_m208_y1) y1 - внутренний параметр
#define internal2_m216_y1	BUFFER[12300]	// (internal2_m216_y1) y1 - внутренний параметр
#define idinternal2_m216_y1	1893	// (internal2_m216_y1) y1 - внутренний параметр
#define internal2_m21_Nk0	BUFFER[12302]	// (internal2_m21_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m21_Nk0	1894	// (internal2_m21_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m21_SetFlag	BUFFER[12307]	// (internal2_m21_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m21_SetFlag	1895	// (internal2_m21_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m220_y0	BUFFER[12309]	// (internal2_m220_y0) state
#define idinternal2_m220_y0	1896	// (internal2_m220_y0) state
#define internal2_m226_y0	BUFFER[12311]	// (internal2_m226_y0) state
#define idinternal2_m226_y0	1897	// (internal2_m226_y0) state
#define internal2_m238_tx	BUFFER[12313]	// (internal2_m238_tx) tx - время накопленное сек
#define idinternal2_m238_tx	1898	// (internal2_m238_tx) tx - время накопленное сек
#define internal2_m238_y0	BUFFER[12318]	// (internal2_m238_y0) y0
#define idinternal2_m238_y0	1899	// (internal2_m238_y0) y0
#define internal2_m240_tx	BUFFER[12320]	// (internal2_m240_tx) tx - время накопленное сек
#define idinternal2_m240_tx	1900	// (internal2_m240_tx) tx - время накопленное сек
#define internal2_m240_y0	BUFFER[12325]	// (internal2_m240_y0) y0
#define idinternal2_m240_y0	1901	// (internal2_m240_y0) y0
#define internal2_m242_tx	BUFFER[12327]	// (internal2_m242_tx) tx - время накопленное сек
#define idinternal2_m242_tx	1902	// (internal2_m242_tx) tx - время накопленное сек
#define internal2_m242_y0	BUFFER[12332]	// (internal2_m242_y0) y0
#define idinternal2_m242_y0	1903	// (internal2_m242_y0) y0
#define internal2_m244_tx	BUFFER[12334]	// (internal2_m244_tx) tx - время накопленное сек
#define idinternal2_m244_tx	1904	// (internal2_m244_tx) tx - время накопленное сек
#define internal2_m244_y0	BUFFER[12339]	// (internal2_m244_y0) y0
#define idinternal2_m244_y0	1905	// (internal2_m244_y0) y0
#define internal2_m246_tx	BUFFER[12341]	// (internal2_m246_tx) tx - время накопленное сек
#define idinternal2_m246_tx	1906	// (internal2_m246_tx) tx - время накопленное сек
#define internal2_m246_y0	BUFFER[12346]	// (internal2_m246_y0) y0
#define idinternal2_m246_y0	1907	// (internal2_m246_y0) y0
#define internal2_m248_tx	BUFFER[12348]	// (internal2_m248_tx) tx - время накопленное сек
#define idinternal2_m248_tx	1908	// (internal2_m248_tx) tx - время накопленное сек
#define internal2_m248_y0	BUFFER[12353]	// (internal2_m248_y0) y0
#define idinternal2_m248_y0	1909	// (internal2_m248_y0) y0
#define internal2_m250_tx	BUFFER[12355]	// (internal2_m250_tx) tx - время накопленное сек
#define idinternal2_m250_tx	1910	// (internal2_m250_tx) tx - время накопленное сек
#define internal2_m250_y0	BUFFER[12360]	// (internal2_m250_y0) y0
#define idinternal2_m250_y0	1911	// (internal2_m250_y0) y0
#define internal2_m252_tx	BUFFER[12362]	// (internal2_m252_tx) tx - время накопленное сек
#define idinternal2_m252_tx	1912	// (internal2_m252_tx) tx - время накопленное сек
#define internal2_m252_y0	BUFFER[12367]	// (internal2_m252_y0) y0
#define idinternal2_m252_y0	1913	// (internal2_m252_y0) y0
#define internal2_m254_tx	BUFFER[12369]	// (internal2_m254_tx) tx - время накопленное сек
#define idinternal2_m254_tx	1914	// (internal2_m254_tx) tx - время накопленное сек
#define internal2_m254_y0	BUFFER[12374]	// (internal2_m254_y0) y0
#define idinternal2_m254_y0	1915	// (internal2_m254_y0) y0
#define internal2_m256_tx	BUFFER[12376]	// (internal2_m256_tx) tx - время накопленное сек
#define idinternal2_m256_tx	1916	// (internal2_m256_tx) tx - время накопленное сек
#define internal2_m256_y0	BUFFER[12381]	// (internal2_m256_y0) y0
#define idinternal2_m256_y0	1917	// (internal2_m256_y0) y0
#define internal2_m258_tx	BUFFER[12383]	// (internal2_m258_tx) tx - время накопленное сек
#define idinternal2_m258_tx	1918	// (internal2_m258_tx) tx - время накопленное сек
#define internal2_m258_y0	BUFFER[12388]	// (internal2_m258_y0) y0
#define idinternal2_m258_y0	1919	// (internal2_m258_y0) y0
#define internal2_m260_tx	BUFFER[12390]	// (internal2_m260_tx) tx - время накопленное сек
#define idinternal2_m260_tx	1920	// (internal2_m260_tx) tx - время накопленное сек
#define internal2_m260_y0	BUFFER[12395]	// (internal2_m260_y0) y0
#define idinternal2_m260_y0	1921	// (internal2_m260_y0) y0
#define internal2_m45_Nk0	BUFFER[12397]	// (internal2_m45_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m45_Nk0	1922	// (internal2_m45_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m45_SetFlag	BUFFER[12402]	// (internal2_m45_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m45_SetFlag	1923	// (internal2_m45_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m53_Nk0	BUFFER[12404]	// (internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m53_Nk0	1924	// (internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m53_SetFlag	BUFFER[12409]	// (internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m53_SetFlag	1925	// (internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m75_Nk0	BUFFER[12411]	// (internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m75_Nk0	1926	// (internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m75_SetFlag	BUFFER[12416]	// (internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m75_SetFlag	1927	// (internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m77_Nk0	BUFFER[12418]	// (internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m77_Nk0	1928	// (internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m77_SetFlag	BUFFER[12423]	// (internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m77_SetFlag	1929	// (internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define lEM_R0MD01LC1	BUFFER[12425]	// (R0MD01LC1) Ручное управление ОРР
#define idlEM_R0MD01LC1	1930	// (R0MD01LC1) Ручное управление ОРР
#define psaz11	BUFFER[12427]	// ( - , DU) каналы
#define idpsaz11	1931	// ( - , DU) каналы
#define psaz12	BUFFER[12429]	// ( - , DU) напряжение
#define idpsaz12	1932	// ( - , DU) напряжение
#define psaz13	BUFFER[12431]	// ( - , DU) давление
#define idpsaz13	1933	// ( - , DU) давление
#define psaz14	BUFFER[12433]	// ( - , DU) ас темп з2
#define idpsaz14	1934	// ( - , DU) ас темп з2
#define psaz15	BUFFER[12435]	// ( - , DU) ас темп з1
#define idpsaz15	1935	// ( - , DU) ас темп з1
#define psaz21	BUFFER[12437]	// ( - , DU) каналы
#define idpsaz21	1936	// ( - , DU) каналы
#define psaz22	BUFFER[12439]	// ( - , DU) напряжение
#define idpsaz22	1937	// ( - , DU) напряжение
#define psaz23	BUFFER[12441]	// ( - , DU) давление
#define idpsaz23	1938	// ( - , DU) давление
#define psaz24	BUFFER[12443]	// ( - , DU) ас темп з2
#define idpsaz24	1939	// ( - , DU) ас темп з2
#define psaz25	BUFFER[12445]	// ( - , DU) питание
#define idpsaz25	1940	// ( - , DU) питание
#define psaz3	BUFFER[12447]	// ( - , DU) энкодеры
#define idpsaz3	1941	// ( - , DU) энкодеры
#define psb1	BUFFER[12449]	// ( - , DU) ру не готова
#define idpsb1	1942	// ( - , DU) ру не готова
#define psb2	BUFFER[12451]	// ( - , DU) движение бб
#define idpsb2	1943	// ( - , DU) движение бб
#define psrb	BUFFER[12453]	// ( - , DU) ???
#define idpsrb	1944	// ( - , DU) ???
#define psrb1	BUFFER[12455]	// ( - , DU) пневматика по мощности
#define idpsrb1	1945	// ( - , DU) пневматика по мощности
#define psrb2	BUFFER[12457]	// ( - , DU) пневматика по программам
#define idpsrb2	1946	// ( - , DU) пневматика по программам
#define psrb4	BUFFER[12459]	// ( - , DU) кнопка сброс
#define idpsrb4	1947	// ( - , DU) кнопка сброс
#define venc01	BUFFER[12461]	// (vencf8l:01 - venc01, - ) заначение реального энкодера ББ1
#define idvenc01	1948	// (vencf8l:01 - venc01, - ) заначение реального энкодера ББ1
#define venc02	BUFFER[12466]	// (vencf8l:01 - venc02, - ) заначение реального энкодера РБ1
#define idvenc02	1949	// (vencf8l:01 - venc02, - ) заначение реального энкодера РБ1
#define venc03	BUFFER[12471]	// (vencf8l:01 - venc03, - ) заначение реального энкодера Ис1
#define idvenc03	1950	// (vencf8l:01 - venc03, - ) заначение реального энкодера Ис1
#define venc04	BUFFER[12476]	// (vencf8l:01 - venc04, - ) заначение реального энкодера ДС1
#define idvenc04	1951	// (vencf8l:01 - venc04, - ) заначение реального энкодера ДС1
#define venc05	BUFFER[12481]	// (vencf8l:01 - venc05, - ) заначение реального энкодера ББ2
#define idvenc05	1952	// (vencf8l:01 - venc05, - ) заначение реального энкодера ББ2
#define venc06	BUFFER[12486]	// (vencf8l:01 - venc06, - ) заначение реального энкодера РБ2
#define idvenc06	1953	// (vencf8l:01 - venc06, - ) заначение реального энкодера РБ2
#define venc07	BUFFER[12491]	// (vencf8l:01 - venc07, - ) заначение реального энкодера ИС2
#define idvenc07	1954	// (vencf8l:01 - venc07, - ) заначение реального энкодера ИС2
#define venc08	BUFFER[12496]	// (vencf8l:01 - venc08, - ) заначение реального энкодера АЗ2
#define idvenc08	1955	// (vencf8l:01 - venc08, - ) заначение реального энкодера АЗ2
#define var1489	BUFFER[12501]	// Внутренняя переменная var1489
#define idvar1489	30000	// Внутренняя переменная var1489
#define var1672	BUFFER[12503]	// Внутренняя переменная var1672
#define idvar1672	30001	// Внутренняя переменная var1672
#define var150	BUFFER[12505]	// Внутренняя переменная var150
#define idvar150	30002	// Внутренняя переменная var150
#define var801	BUFFER[12507]	// Внутренняя переменная var801
#define idvar801	30003	// Внутренняя переменная var801
#define var972	BUFFER[12509]	// Внутренняя переменная var972
#define idvar972	30004	// Внутренняя переменная var972
#define var1084	BUFFER[12511]	// Внутренняя переменная var1084
#define idvar1084	30005	// Внутренняя переменная var1084
#define var1362	BUFFER[12513]	// Внутренняя переменная var1362
#define idvar1362	30006	// Внутренняя переменная var1362
#define var1440	BUFFER[12515]	// Внутренняя переменная var1440
#define idvar1440	30007	// Внутренняя переменная var1440
#define var784	BUFFER[12517]	// Внутренняя переменная var784
#define idvar784	30008	// Внутренняя переменная var784
#define var185	BUFFER[12519]	// Внутренняя переменная var185
#define idvar185	30009	// Внутренняя переменная var185
#define var276	BUFFER[12521]	// Внутренняя переменная var276
#define idvar276	30010	// Внутренняя переменная var276
#define var440	BUFFER[12523]	// Внутренняя переменная var440
#define idvar440	30011	// Внутренняя переменная var440
#define var530	BUFFER[12525]	// Внутренняя переменная var530
#define idvar530	30012	// Внутренняя переменная var530
#define var1604	BUFFER[12527]	// Внутренняя переменная var1604
#define idvar1604	30013	// Внутренняя переменная var1604
#define var516	BUFFER[12529]	// Внутренняя переменная var516
#define idvar516	30014	// Внутренняя переменная var516
#define var1305	BUFFER[12531]	// Внутренняя переменная var1305
#define idvar1305	30015	// Внутренняя переменная var1305
#define var1425	BUFFER[12533]	// Внутренняя переменная var1425
#define idvar1425	30016	// Внутренняя переменная var1425
#define var1426	BUFFER[12535]	// Внутренняя переменная var1426
#define idvar1426	30017	// Внутренняя переменная var1426
#define var101	BUFFER[12537]	// Внутренняя переменная var101
#define idvar101	30018	// Внутренняя переменная var101
#define var233	BUFFER[12539]	// Внутренняя переменная var233
#define idvar233	30019	// Внутренняя переменная var233
#define var783	BUFFER[12541]	// Внутренняя переменная var783
#define idvar783	30020	// Внутренняя переменная var783
#define var882	BUFFER[12543]	// Внутренняя переменная var882
#define idvar882	30021	// Внутренняя переменная var882
#define var1914	BUFFER[12545]	// Внутренняя переменная var1914
#define idvar1914	30022	// Внутренняя переменная var1914
#define var403	BUFFER[12547]	// Внутренняя переменная var403
#define idvar403	30023	// Внутренняя переменная var403
#define var456	BUFFER[12549]	// Внутренняя переменная var456
#define idvar456	30024	// Внутренняя переменная var456
#define var668	BUFFER[12551]	// Внутренняя переменная var668
#define idvar668	30025	// Внутренняя переменная var668
#define var1683	BUFFER[12556]	// Внутренняя переменная var1683
#define idvar1683	30026	// Внутренняя переменная var1683
#define var302	BUFFER[12558]	// Внутренняя переменная var302
#define idvar302	30027	// Внутренняя переменная var302
#define var523	BUFFER[12560]	// Внутренняя переменная var523
#define idvar523	30028	// Внутренняя переменная var523
#define var586	BUFFER[12562]	// Внутренняя переменная var586
#define idvar586	30029	// Внутренняя переменная var586
#define var1818	BUFFER[12564]	// Внутренняя переменная var1818
#define idvar1818	30030	// Внутренняя переменная var1818
#define var477	BUFFER[12566]	// Внутренняя переменная var477
#define idvar477	30031	// Внутренняя переменная var477
#define var690	BUFFER[12568]	// Внутренняя переменная var690
#define idvar690	30032	// Внутренняя переменная var690
#define var1066	BUFFER[12570]	// Внутренняя переменная var1066
#define idvar1066	30033	// Внутренняя переменная var1066
#define var1438	BUFFER[12572]	// Внутренняя переменная var1438
#define idvar1438	30034	// Внутренняя переменная var1438
#define var1184	BUFFER[12574]	// Внутренняя переменная var1184
#define idvar1184	30035	// Внутренняя переменная var1184
#define var777	BUFFER[12576]	// Внутренняя переменная var777
#define idvar777	30036	// Внутренняя переменная var777
#define var1826	BUFFER[12578]	// Внутренняя переменная var1826
#define idvar1826	30037	// Внутренняя переменная var1826
#define var104	BUFFER[12580]	// Внутренняя переменная var104
#define idvar104	30038	// Внутренняя переменная var104
#define var479	BUFFER[12582]	// Внутренняя переменная var479
#define idvar479	30039	// Внутренняя переменная var479
#define var791	BUFFER[12584]	// Внутренняя переменная var791
#define idvar791	30040	// Внутренняя переменная var791
#define var1308	BUFFER[12586]	// Внутренняя переменная var1308
#define idvar1308	30041	// Внутренняя переменная var1308
#define var1337	BUFFER[12588]	// Внутренняя переменная var1337
#define idvar1337	30042	// Внутренняя переменная var1337
#define var1866	BUFFER[12590]	// Внутренняя переменная var1866
#define idvar1866	30043	// Внутренняя переменная var1866
#define var683	BUFFER[12592]	// Внутренняя переменная var683
#define idvar683	30044	// Внутренняя переменная var683
#define var706	BUFFER[12594]	// Внутренняя переменная var706
#define idvar706	30045	// Внутренняя переменная var706
#define var1523	BUFFER[12596]	// Внутренняя переменная var1523
#define idvar1523	30046	// Внутренняя переменная var1523
#define var1721	BUFFER[12598]	// Внутренняя переменная var1721
#define idvar1721	30047	// Внутренняя переменная var1721
#define var1445	BUFFER[12600]	// Внутренняя переменная var1445
#define idvar1445	30048	// Внутренняя переменная var1445
#define var1793	BUFFER[12602]	// Внутренняя переменная var1793
#define idvar1793	30049	// Внутренняя переменная var1793
#define var79	BUFFER[12604]	// Внутренняя переменная var79
#define idvar79	30050	// Внутренняя переменная var79
#define var284	BUFFER[12606]	// Внутренняя переменная var284
#define idvar284	30051	// Внутренняя переменная var284
#define var665	BUFFER[12608]	// Внутренняя переменная var665
#define idvar665	30052	// Внутренняя переменная var665
#define var873	BUFFER[12613]	// Внутренняя переменная var873
#define idvar873	30053	// Внутренняя переменная var873
#define var916	BUFFER[12615]	// Внутренняя переменная var916
#define idvar916	30054	// Внутренняя переменная var916
#define var1120	BUFFER[12617]	// Внутренняя переменная var1120
#define idvar1120	30055	// Внутренняя переменная var1120
#define var427	BUFFER[12619]	// Внутренняя переменная var427
#define idvar427	30056	// Внутренняя переменная var427
#define var799	BUFFER[12621]	// Внутренняя переменная var799
#define idvar799	30057	// Внутренняя переменная var799
#define var1009	BUFFER[12623]	// Внутренняя переменная var1009
#define idvar1009	30058	// Внутренняя переменная var1009
#define var1346	BUFFER[12625]	// Внутренняя переменная var1346
#define idvar1346	30059	// Внутренняя переменная var1346
#define var1418	BUFFER[12627]	// Внутренняя переменная var1418
#define idvar1418	30060	// Внутренняя переменная var1418
#define var1768	BUFFER[12629]	// Внутренняя переменная var1768
#define idvar1768	30061	// Внутренняя переменная var1768
#define var538	BUFFER[12631]	// Внутренняя переменная var538
#define idvar538	30062	// Внутренняя переменная var538
#define var1010	BUFFER[12633]	// Внутренняя переменная var1010
#define idvar1010	30063	// Внутренняя переменная var1010
#define var22	BUFFER[12635]	// Внутренняя переменная var22
#define idvar22	30064	// Внутренняя переменная var22
#define var172	BUFFER[12637]	// Внутренняя переменная var172
#define idvar172	30065	// Внутренняя переменная var172
#define var326	BUFFER[12639]	// Внутренняя переменная var326
#define idvar326	30066	// Внутренняя переменная var326
#define var940	BUFFER[12641]	// Внутренняя переменная var940
#define idvar940	30067	// Внутренняя переменная var940
#define var1461	BUFFER[12643]	// Внутренняя переменная var1461
#define idvar1461	30068	// Внутренняя переменная var1461
#define var1575	BUFFER[12645]	// Внутренняя переменная var1575
#define idvar1575	30069	// Внутренняя переменная var1575
#define var164	BUFFER[12647]	// Внутренняя переменная var164
#define idvar164	30070	// Внутренняя переменная var164
#define var315	BUFFER[12649]	// Внутренняя переменная var315
#define idvar315	30071	// Внутренняя переменная var315
#define var1682	BUFFER[12651]	// Внутренняя переменная var1682
#define idvar1682	30072	// Внутренняя переменная var1682
#define var382	BUFFER[12653]	// Внутренняя переменная var382
#define idvar382	30073	// Внутренняя переменная var382
#define var608	BUFFER[12655]	// Внутренняя переменная var608
#define idvar608	30074	// Внутренняя переменная var608
#define var680	BUFFER[12657]	// Внутренняя переменная var680
#define idvar680	30075	// Внутренняя переменная var680
#define var1285	BUFFER[12659]	// Внутренняя переменная var1285
#define idvar1285	30076	// Внутренняя переменная var1285
#define var1803	BUFFER[12661]	// Внутренняя переменная var1803
#define idvar1803	30077	// Внутренняя переменная var1803
#define var1829	BUFFER[12663]	// Внутренняя переменная var1829
#define idvar1829	30078	// Внутренняя переменная var1829
#define var745	BUFFER[12665]	// Внутренняя переменная var745
#define idvar745	30079	// Внутренняя переменная var745
#define var750	BUFFER[12667]	// Внутренняя переменная var750
#define idvar750	30080	// Внутренняя переменная var750
#define var1495	BUFFER[12669]	// Внутренняя переменная var1495
#define idvar1495	30081	// Внутренняя переменная var1495
#define var1734	BUFFER[12671]	// Внутренняя переменная var1734
#define idvar1734	30082	// Внутренняя переменная var1734
#define var1104	BUFFER[12673]	// Внутренняя переменная var1104
#define idvar1104	30083	// Внутренняя переменная var1104
#define var1524	BUFFER[12675]	// Внутренняя переменная var1524
#define idvar1524	30084	// Внутренняя переменная var1524
#define var1821	BUFFER[12677]	// Внутренняя переменная var1821
#define idvar1821	30085	// Внутренняя переменная var1821
#define var1995	BUFFER[12679]	// Внутренняя переменная var1995
#define idvar1995	30086	// Внутренняя переменная var1995
#define var1275	BUFFER[12681]	// Внутренняя переменная var1275
#define idvar1275	30087	// Внутренняя переменная var1275
#define var1477	BUFFER[12683]	// Внутренняя переменная var1477
#define idvar1477	30088	// Внутренняя переменная var1477
#define var1757	BUFFER[12685]	// Внутренняя переменная var1757
#define idvar1757	30089	// Внутренняя переменная var1757
#define var1993	BUFFER[12687]	// Внутренняя переменная var1993
#define idvar1993	30090	// Внутренняя переменная var1993
#define var285	BUFFER[12689]	// Внутренняя переменная var285
#define idvar285	30091	// Внутренняя переменная var285
#define var1014	BUFFER[12691]	// Внутренняя переменная var1014
#define idvar1014	30092	// Внутренняя переменная var1014
#define var1353	BUFFER[12693]	// Внутренняя переменная var1353
#define idvar1353	30093	// Внутренняя переменная var1353
#define var19	BUFFER[12695]	// Внутренняя переменная var19
#define idvar19	30094	// Внутренняя переменная var19
#define var316	BUFFER[12697]	// Внутренняя переменная var316
#define idvar316	30095	// Внутренняя переменная var316
#define var874	BUFFER[12699]	// Внутренняя переменная var874
#define idvar874	30096	// Внутренняя переменная var874
#define var1381	BUFFER[12701]	// Внутренняя переменная var1381
#define idvar1381	30097	// Внутренняя переменная var1381
#define var167	BUFFER[12703]	// Внутренняя переменная var167
#define idvar167	30098	// Внутренняя переменная var167
#define var422	BUFFER[12705]	// Внутренняя переменная var422
#define idvar422	30099	// Внутренняя переменная var422
#define var953	BUFFER[12707]	// Внутренняя переменная var953
#define idvar953	30100	// Внутренняя переменная var953
#define var1437	BUFFER[12709]	// Внутренняя переменная var1437
#define idvar1437	30101	// Внутренняя переменная var1437
#define var1502	BUFFER[12711]	// Внутренняя переменная var1502
#define idvar1502	30102	// Внутренняя переменная var1502
#define var1863	BUFFER[12713]	// Внутренняя переменная var1863
#define idvar1863	30103	// Внутренняя переменная var1863
#define var911	BUFFER[12715]	// Внутренняя переменная var911
#define idvar911	30104	// Внутренняя переменная var911
#define var918	BUFFER[12717]	// Внутренняя переменная var918
#define idvar918	30105	// Внутренняя переменная var918
#define var1612	BUFFER[12719]	// Внутренняя переменная var1612
#define idvar1612	30106	// Внутренняя переменная var1612
#define var1558	BUFFER[12724]	// Внутренняя переменная var1558
#define idvar1558	30107	// Внутренняя переменная var1558
#define var1748	BUFFER[12726]	// Внутренняя переменная var1748
#define idvar1748	30108	// Внутренняя переменная var1748
#define var239	BUFFER[12728]	// Внутренняя переменная var239
#define idvar239	30109	// Внутренняя переменная var239
#define var447	BUFFER[12730]	// Внутренняя переменная var447
#define idvar447	30110	// Внутренняя переменная var447
#define var891	BUFFER[12735]	// Внутренняя переменная var891
#define idvar891	30111	// Внутренняя переменная var891
#define var904	BUFFER[12737]	// Внутренняя переменная var904
#define idvar904	30112	// Внутренняя переменная var904
#define var942	BUFFER[12739]	// Внутренняя переменная var942
#define idvar942	30113	// Внутренняя переменная var942
#define var1333	BUFFER[12741]	// Внутренняя переменная var1333
#define idvar1333	30114	// Внутренняя переменная var1333
#define var1814	BUFFER[12743]	// Внутренняя переменная var1814
#define idvar1814	30115	// Внутренняя переменная var1814
#define var1867	BUFFER[12745]	// Внутренняя переменная var1867
#define idvar1867	30116	// Внутренняя переменная var1867
#define var932	BUFFER[12747]	// Внутренняя переменная var932
#define idvar932	30117	// Внутренняя переменная var932
#define var1214	BUFFER[12749]	// Внутренняя переменная var1214
#define idvar1214	30118	// Внутренняя переменная var1214
#define var1212	BUFFER[12751]	// Внутренняя переменная var1212
#define idvar1212	30119	// Внутренняя переменная var1212
#define var1227	BUFFER[12753]	// Внутренняя переменная var1227
#define idvar1227	30120	// Внутренняя переменная var1227
#define var1754	BUFFER[12758]	// Внутренняя переменная var1754
#define idvar1754	30121	// Внутренняя переменная var1754
#define var1030	BUFFER[12760]	// Внутренняя переменная var1030
#define idvar1030	30122	// Внутренняя переменная var1030
#define var1931	BUFFER[12762]	// Внутренняя переменная var1931
#define idvar1931	30123	// Внутренняя переменная var1931
#define var442	BUFFER[12764]	// Внутренняя переменная var442
#define idvar442	30124	// Внутренняя переменная var442
#define var1315	BUFFER[12769]	// Внутренняя переменная var1315
#define idvar1315	30125	// Внутренняя переменная var1315
#define var1953	BUFFER[12771]	// Внутренняя переменная var1953
#define idvar1953	30126	// Внутренняя переменная var1953
#define var240	BUFFER[12773]	// Внутренняя переменная var240
#define idvar240	30127	// Внутренняя переменная var240
#define var298	BUFFER[12775]	// Внутренняя переменная var298
#define idvar298	30128	// Внутренняя переменная var298
#define var578	BUFFER[12777]	// Внутренняя переменная var578
#define idvar578	30129	// Внутренняя переменная var578
#define var805	BUFFER[12779]	// Внутренняя переменная var805
#define idvar805	30130	// Внутренняя переменная var805
#define var910	BUFFER[12781]	// Внутренняя переменная var910
#define idvar910	30131	// Внутренняя переменная var910
#define var1431	BUFFER[12783]	// Внутренняя переменная var1431
#define idvar1431	30132	// Внутренняя переменная var1431
#define var158	BUFFER[12785]	// Внутренняя переменная var158
#define idvar158	30133	// Внутренняя переменная var158
#define var389	BUFFER[12787]	// Внутренняя переменная var389
#define idvar389	30134	// Внутренняя переменная var389
#define var1005	BUFFER[12789]	// Внутренняя переменная var1005
#define idvar1005	30135	// Внутренняя переменная var1005
#define var1647	BUFFER[12791]	// Внутренняя переменная var1647
#define idvar1647	30136	// Внутренняя переменная var1647
#define var1902	BUFFER[12793]	// Внутренняя переменная var1902
#define idvar1902	30137	// Внутренняя переменная var1902
#define var90	BUFFER[12795]	// Внутренняя переменная var90
#define idvar90	30138	// Внутренняя переменная var90
#define var412	BUFFER[12797]	// Внутренняя переменная var412
#define idvar412	30139	// Внутренняя переменная var412
#define var532	BUFFER[12799]	// Внутренняя переменная var532
#define idvar532	30140	// Внутренняя переменная var532
#define var906	BUFFER[12801]	// Внутренняя переменная var906
#define idvar906	30141	// Внутренняя переменная var906
#define var1240	BUFFER[12803]	// Внутренняя переменная var1240
#define idvar1240	30142	// Внутренняя переменная var1240
#define var1408	BUFFER[12805]	// Внутренняя переменная var1408
#define idvar1408	30143	// Внутренняя переменная var1408
#define var208	BUFFER[12807]	// Внутренняя переменная var208
#define idvar208	30144	// Внутренняя переменная var208
#define var243	BUFFER[12809]	// Внутренняя переменная var243
#define idvar243	30145	// Внутренняя переменная var243
#define var962	BUFFER[12811]	// Внутренняя переменная var962
#define idvar962	30146	// Внутренняя переменная var962
#define var1251	BUFFER[12813]	// Внутренняя переменная var1251
#define idvar1251	30147	// Внутренняя переменная var1251
#define var1015	BUFFER[12815]	// Внутренняя переменная var1015
#define idvar1015	30148	// Внутренняя переменная var1015
#define var1073	BUFFER[12817]	// Внутренняя переменная var1073
#define idvar1073	30149	// Внутренняя переменная var1073
#define var17	BUFFER[12819]	// Внутренняя переменная var17
#define idvar17	30150	// Внутренняя переменная var17
#define var108	BUFFER[12821]	// Внутренняя переменная var108
#define idvar108	30151	// Внутренняя переменная var108
#define var155	BUFFER[12823]	// Внутренняя переменная var155
#define idvar155	30152	// Внутренняя переменная var155
#define var481	BUFFER[12825]	// Внутренняя переменная var481
#define idvar481	30153	// Внутренняя переменная var481
#define var636	BUFFER[12827]	// Внутренняя переменная var636
#define idvar636	30154	// Внутренняя переменная var636
#define var903	BUFFER[12829]	// Внутренняя переменная var903
#define idvar903	30155	// Внутренняя переменная var903
#define var1127	BUFFER[12831]	// Внутренняя переменная var1127
#define idvar1127	30156	// Внутренняя переменная var1127
#define var1792	BUFFER[12833]	// Внутренняя переменная var1792
#define idvar1792	30157	// Внутренняя переменная var1792
#define var20	BUFFER[12835]	// Внутренняя переменная var20
#define idvar20	30158	// Внутренняя переменная var20
#define var1533	BUFFER[12837]	// Внутренняя переменная var1533
#define idvar1533	30159	// Внутренняя переменная var1533
#define var1861	BUFFER[12839]	// Внутренняя переменная var1861
#define idvar1861	30160	// Внутренняя переменная var1861
#define var1942	BUFFER[12841]	// Внутренняя переменная var1942
#define idvar1942	30161	// Внутренняя переменная var1942
#define var366	BUFFER[12843]	// Внутренняя переменная var366
#define idvar366	30162	// Внутренняя переменная var366
#define var499	BUFFER[12845]	// Внутренняя переменная var499
#define idvar499	30163	// Внутренняя переменная var499
#define var1142	BUFFER[12847]	// Внутренняя переменная var1142
#define idvar1142	30164	// Внутренняя переменная var1142
#define var1351	BUFFER[12849]	// Внутренняя переменная var1351
#define idvar1351	30165	// Внутренняя переменная var1351
#define var1473	BUFFER[12851]	// Внутренняя переменная var1473
#define idvar1473	30166	// Внутренняя переменная var1473
#define var1761	BUFFER[12853]	// Внутренняя переменная var1761
#define idvar1761	30167	// Внутренняя переменная var1761
#define var189	BUFFER[12855]	// Внутренняя переменная var189
#define idvar189	30168	// Внутренняя переменная var189
#define var369	BUFFER[12857]	// Внутренняя переменная var369
#define idvar369	30169	// Внутренняя переменная var369
#define var395	BUFFER[12859]	// Внутренняя переменная var395
#define idvar395	30170	// Внутренняя переменная var395
#define var1175	BUFFER[12861]	// Внутренняя переменная var1175
#define idvar1175	30171	// Внутренняя переменная var1175
#define var1335	BUFFER[12863]	// Внутренняя переменная var1335
#define idvar1335	30172	// Внутренняя переменная var1335
#define var1478	BUFFER[12865]	// Внутренняя переменная var1478
#define idvar1478	30173	// Внутренняя переменная var1478
#define var42	BUFFER[12867]	// Внутренняя переменная var42
#define idvar42	30174	// Внутренняя переменная var42
#define var1032	BUFFER[12869]	// Внутренняя переменная var1032
#define idvar1032	30175	// Внутренняя переменная var1032
#define var1316	BUFFER[12871]	// Внутренняя переменная var1316
#define idvar1316	30176	// Внутренняя переменная var1316
#define var1404	BUFFER[12873]	// Внутренняя переменная var1404
#define idvar1404	30177	// Внутренняя переменная var1404
#define var1578	BUFFER[12875]	// Внутренняя переменная var1578
#define idvar1578	30178	// Внутренняя переменная var1578
#define var1871	BUFFER[12878]	// Внутренняя переменная var1871
#define idvar1871	30179	// Внутренняя переменная var1871
#define var457	BUFFER[12880]	// Внутренняя переменная var457
#define idvar457	30180	// Внутренняя переменная var457
#define var521	BUFFER[12882]	// Внутренняя переменная var521
#define idvar521	30181	// Внутренняя переменная var521
#define var795	BUFFER[12884]	// Внутренняя переменная var795
#define idvar795	30182	// Внутренняя переменная var795
#define var1322	BUFFER[12886]	// Внутренняя переменная var1322
#define idvar1322	30183	// Внутренняя переменная var1322
#define var1462	BUFFER[12888]	// Внутренняя переменная var1462
#define idvar1462	30184	// Внутренняя переменная var1462
#define var1624	BUFFER[12890]	// Внутренняя переменная var1624
#define idvar1624	30185	// Внутренняя переменная var1624
#define var53	BUFFER[12892]	// Внутренняя переменная var53
#define idvar53	30186	// Внутренняя переменная var53
#define var74	BUFFER[12894]	// Внутренняя переменная var74
#define idvar74	30187	// Внутренняя переменная var74
#define var429	BUFFER[12896]	// Внутренняя переменная var429
#define idvar429	30188	// Внутренняя переменная var429
#define var671	BUFFER[12898]	// Внутренняя переменная var671
#define idvar671	30189	// Внутренняя переменная var671
#define var1745	BUFFER[12900]	// Внутренняя переменная var1745
#define idvar1745	30190	// Внутренняя переменная var1745
#define var173	BUFFER[12902]	// Внутренняя переменная var173
#define idvar173	30191	// Внутренняя переменная var173
#define var670	BUFFER[12904]	// Внутренняя переменная var670
#define idvar670	30192	// Внутренняя переменная var670
#define var335	BUFFER[12906]	// Внутренняя переменная var335
#define idvar335	30193	// Внутренняя переменная var335
#define var1020	BUFFER[12908]	// Внутренняя переменная var1020
#define idvar1020	30194	// Внутренняя переменная var1020
#define var1819	BUFFER[12910]	// Внутренняя переменная var1819
#define idvar1819	30195	// Внутренняя переменная var1819
#define vainSChar	BUFFER[12913]	// Внутренняя переменная vainSChar
#define idvainSChar	30196	// Внутренняя переменная vainSChar
#define var493	BUFFER[12916]	// Внутренняя переменная var493
#define idvar493	30197	// Внутренняя переменная var493
#define var604	BUFFER[12918]	// Внутренняя переменная var604
#define idvar604	30198	// Внутренняя переменная var604
#define var787	BUFFER[12920]	// Внутренняя переменная var787
#define idvar787	30199	// Внутренняя переменная var787
#define var1103	BUFFER[12922]	// Внутренняя переменная var1103
#define idvar1103	30200	// Внутренняя переменная var1103
#define var1364	BUFFER[12924]	// Внутренняя переменная var1364
#define idvar1364	30201	// Внутренняя переменная var1364
#define var1797	BUFFER[12926]	// Внутренняя переменная var1797
#define idvar1797	30202	// Внутренняя переменная var1797
#define var258	BUFFER[12928]	// Внутренняя переменная var258
#define idvar258	30203	// Внутренняя переменная var258
#define var1237	BUFFER[12930]	// Внутренняя переменная var1237
#define idvar1237	30204	// Внутренняя переменная var1237
#define var1737	BUFFER[12932]	// Внутренняя переменная var1737
#define idvar1737	30205	// Внутренняя переменная var1737
#define var1056	BUFFER[12934]	// Внутренняя переменная var1056
#define idvar1056	30206	// Внутренняя переменная var1056
#define var1320	BUFFER[12936]	// Внутренняя переменная var1320
#define idvar1320	30207	// Внутренняя переменная var1320
#define var1424	BUFFER[12938]	// Внутренняя переменная var1424
#define idvar1424	30208	// Внутренняя переменная var1424
#define var1905	BUFFER[12940]	// Внутренняя переменная var1905
#define idvar1905	30209	// Внутренняя переменная var1905
#define var64	BUFFER[12942]	// Внутренняя переменная var64
#define idvar64	30210	// Внутренняя переменная var64
#define var631	BUFFER[12944]	// Внутренняя переменная var631
#define idvar631	30211	// Внутренняя переменная var631
#define var975	BUFFER[12946]	// Внутренняя переменная var975
#define idvar975	30212	// Внутренняя переменная var975
#define var1466	BUFFER[12948]	// Внутренняя переменная var1466
#define idvar1466	30213	// Внутренняя переменная var1466
#define var5	BUFFER[12950]	// Внутренняя переменная var5
#define idvar5	30214	// Внутренняя переменная var5
#define var77	BUFFER[12952]	// Внутренняя переменная var77
#define idvar77	30215	// Внутренняя переменная var77
#define var187	BUFFER[12954]	// Внутренняя переменная var187
#define idvar187	30216	// Внутренняя переменная var187
#define var544	BUFFER[12956]	// Внутренняя переменная var544
#define idvar544	30217	// Внутренняя переменная var544
#define var1236	BUFFER[12958]	// Внутренняя переменная var1236
#define idvar1236	30218	// Внутренняя переменная var1236
#define var1274	BUFFER[12960]	// Внутренняя переменная var1274
#define idvar1274	30219	// Внутренняя переменная var1274
#define var1681	BUFFER[12962]	// Внутренняя переменная var1681
#define idvar1681	30220	// Внутренняя переменная var1681
#define var95	BUFFER[12964]	// Внутренняя переменная var95
#define idvar95	30221	// Внутренняя переменная var95
#define var727	BUFFER[12966]	// Внутренняя переменная var727
#define idvar727	30222	// Внутренняя переменная var727
#define var1556	BUFFER[12968]	// Внутренняя переменная var1556
#define idvar1556	30223	// Внутренняя переменная var1556
#define var1726	BUFFER[12970]	// Внутренняя переменная var1726
#define idvar1726	30224	// Внутренняя переменная var1726
#define var443	BUFFER[12972]	// Внутренняя переменная var443
#define idvar443	30225	// Внутренняя переменная var443
#define var531	BUFFER[12977]	// Внутренняя переменная var531
#define idvar531	30226	// Внутренняя переменная var531
#define var1747	BUFFER[12979]	// Внутренняя переменная var1747
#define idvar1747	30227	// Внутренняя переменная var1747
#define var1810	BUFFER[12981]	// Внутренняя переменная var1810
#define idvar1810	30228	// Внутренняя переменная var1810
#define var700	BUFFER[12984]	// Внутренняя переменная var700
#define idvar700	30229	// Внутренняя переменная var700
#define var1017	BUFFER[12986]	// Внутренняя переменная var1017
#define idvar1017	30230	// Внутренняя переменная var1017
#define var1862	BUFFER[12988]	// Внутренняя переменная var1862
#define idvar1862	30231	// Внутренняя переменная var1862
#define var38	BUFFER[12990]	// Внутренняя переменная var38
#define idvar38	30232	// Внутренняя переменная var38
#define var207	BUFFER[12992]	// Внутренняя переменная var207
#define idvar207	30233	// Внутренняя переменная var207
#define var358	BUFFER[12994]	// Внутренняя переменная var358
#define idvar358	30234	// Внутренняя переменная var358
#define var432	BUFFER[12996]	// Внутренняя переменная var432
#define idvar432	30235	// Внутренняя переменная var432
#define var601	BUFFER[13001]	// Внутренняя переменная var601
#define idvar601	30236	// Внутренняя переменная var601
#define var1255	BUFFER[13003]	// Внутренняя переменная var1255
#define idvar1255	30237	// Внутренняя переменная var1255
#define var118	BUFFER[13005]	// Внутренняя переменная var118
#define idvar118	30238	// Внутренняя переменная var118
#define var741	BUFFER[13007]	// Внутренняя переменная var741
#define idvar741	30239	// Внутренняя переменная var741
#define var881	BUFFER[13009]	// Внутренняя переменная var881
#define idvar881	30240	// Внутренняя переменная var881
#define var1926	BUFFER[13011]	// Внутренняя переменная var1926
#define idvar1926	30241	// Внутренняя переменная var1926
#define var1615	BUFFER[13013]	// Внутренняя переменная var1615
#define idvar1615	30242	// Внутренняя переменная var1615
#define var1904	BUFFER[13015]	// Внутренняя переменная var1904
#define idvar1904	30243	// Внутренняя переменная var1904
#define var132	BUFFER[13017]	// Внутренняя переменная var132
#define idvar132	30244	// Внутренняя переменная var132
#define var430	BUFFER[13019]	// Внутренняя переменная var430
#define idvar430	30245	// Внутренняя переменная var430
#define var615	BUFFER[13021]	// Внутренняя переменная var615
#define idvar615	30246	// Внутренняя переменная var615
#define var754	BUFFER[13023]	// Внутренняя переменная var754
#define idvar754	30247	// Внутренняя переменная var754
#define var1326	BUFFER[13025]	// Внутренняя переменная var1326
#define idvar1326	30248	// Внутренняя переменная var1326
#define var1499	BUFFER[13027]	// Внутренняя переменная var1499
#define idvar1499	30249	// Внутренняя переменная var1499
#define var1889	BUFFER[13029]	// Внутренняя переменная var1889
#define idvar1889	30250	// Внутренняя переменная var1889
#define var598	BUFFER[13031]	// Внутренняя переменная var598
#define idvar598	30251	// Внутренняя переменная var598
#define var625	BUFFER[13033]	// Внутренняя переменная var625
#define idvar625	30252	// Внутренняя переменная var625
#define var682	BUFFER[13035]	// Внутренняя переменная var682
#define idvar682	30253	// Внутренняя переменная var682
#define var1123	BUFFER[13037]	// Внутренняя переменная var1123
#define idvar1123	30254	// Внутренняя переменная var1123
#define var1173	BUFFER[13039]	// Внутренняя переменная var1173
#define idvar1173	30255	// Внутренняя переменная var1173
#define var1769	BUFFER[13041]	// Внутренняя переменная var1769
#define idvar1769	30256	// Внутренняя переменная var1769
#define var1149	BUFFER[13043]	// Внутренняя переменная var1149
#define idvar1149	30257	// Внутренняя переменная var1149
#define var1267	BUFFER[13045]	// Внутренняя переменная var1267
#define idvar1267	30258	// Внутренняя переменная var1267
#define var415	BUFFER[13047]	// Внутренняя переменная var415
#define idvar415	30259	// Внутренняя переменная var415
#define var839	BUFFER[13049]	// Внутренняя переменная var839
#define idvar839	30260	// Внутренняя переменная var839
#define var945	BUFFER[13051]	// Внутренняя переменная var945
#define idvar945	30261	// Внутренняя переменная var945
#define var1125	BUFFER[13053]	// Внутренняя переменная var1125
#define idvar1125	30262	// Внутренняя переменная var1125
#define var1609	BUFFER[13055]	// Внутренняя переменная var1609
#define idvar1609	30263	// Внутренняя переменная var1609
#define var449	BUFFER[13057]	// Внутренняя переменная var449
#define idvar449	30264	// Внутренняя переменная var449
#define var1536	BUFFER[13059]	// Внутренняя переменная var1536
#define idvar1536	30265	// Внутренняя переменная var1536
#define var1626	BUFFER[13061]	// Внутренняя переменная var1626
#define idvar1626	30266	// Внутренняя переменная var1626
#define var1628	BUFFER[13064]	// Внутренняя переменная var1628
#define idvar1628	30267	// Внутренняя переменная var1628
#define var1966	BUFFER[13067]	// Внутренняя переменная var1966
#define idvar1966	30268	// Внутренняя переменная var1966
#define var191	BUFFER[13069]	// Внутренняя переменная var191
#define idvar191	30269	// Внутренняя переменная var191
#define var1147	BUFFER[13071]	// Внутренняя переменная var1147
#define idvar1147	30270	// Внутренняя переменная var1147
#define var1980	BUFFER[13073]	// Внутренняя переменная var1980
#define idvar1980	30271	// Внутренняя переменная var1980
#define var1204	BUFFER[13075]	// Внутренняя переменная var1204
#define idvar1204	30272	// Внутренняя переменная var1204
#define var1347	BUFFER[13077]	// Внутренняя переменная var1347
#define idvar1347	30273	// Внутренняя переменная var1347
#define var1739	BUFFER[13079]	// Внутренняя переменная var1739
#define idvar1739	30274	// Внутренняя переменная var1739
#define var1646	BUFFER[13081]	// Внутренняя переменная var1646
#define idvar1646	30275	// Внутренняя переменная var1646
#define var33	BUFFER[13083]	// Внутренняя переменная var33
#define idvar33	30276	// Внутренняя переменная var33
#define var660	BUFFER[13085]	// Внутренняя переменная var660
#define idvar660	30277	// Внутренняя переменная var660
#define var939	BUFFER[13090]	// Внутренняя переменная var939
#define idvar939	30278	// Внутренняя переменная var939
#define var1025	BUFFER[13092]	// Внутренняя переменная var1025
#define idvar1025	30279	// Внутренняя переменная var1025
#define var1039	BUFFER[13094]	// Внутренняя переменная var1039
#define idvar1039	30280	// Внутренняя переменная var1039
#define var1172	BUFFER[13096]	// Внутренняя переменная var1172
#define idvar1172	30281	// Внутренняя переменная var1172
#define var13	BUFFER[13098]	// Внутренняя переменная var13
#define idvar13	30282	// Внутренняя переменная var13
#define var236	BUFFER[13100]	// Внутренняя переменная var236
#define idvar236	30283	// Внутренняя переменная var236
#define var339	BUFFER[13102]	// Внутренняя переменная var339
#define idvar339	30284	// Внутренняя переменная var339
#define var1180	BUFFER[13104]	// Внутренняя переменная var1180
#define idvar1180	30285	// Внутренняя переменная var1180
#define var1391	BUFFER[13106]	// Внутренняя переменная var1391
#define idvar1391	30286	// Внутренняя переменная var1391
#define var354	BUFFER[13108]	// Внутренняя переменная var354
#define idvar354	30287	// Внутренняя переменная var354
#define var726	BUFFER[13110]	// Внутренняя переменная var726
#define idvar726	30288	// Внутренняя переменная var726
#define var1067	BUFFER[13112]	// Внутренняя переменная var1067
#define idvar1067	30289	// Внутренняя переменная var1067
#define var1168	BUFFER[13114]	// Внутренняя переменная var1168
#define idvar1168	30290	// Внутренняя переменная var1168
#define var262	BUFFER[13116]	// Внутренняя переменная var262
#define idvar262	30291	// Внутренняя переменная var262
#define var1019	BUFFER[13119]	// Внутренняя переменная var1019
#define idvar1019	30292	// Внутренняя переменная var1019
#define var1296	BUFFER[13121]	// Внутренняя переменная var1296
#define idvar1296	30293	// Внутренняя переменная var1296
#define var1553	BUFFER[13123]	// Внутренняя переменная var1553
#define idvar1553	30294	// Внутренняя переменная var1553
#define var1202	BUFFER[13125]	// Внутренняя переменная var1202
#define idvar1202	30295	// Внутренняя переменная var1202
#define var1491	BUFFER[13127]	// Внутренняя переменная var1491
#define idvar1491	30296	// Внутренняя переменная var1491
#define var68	BUFFER[13129]	// Внутренняя переменная var68
#define idvar68	30297	// Внутренняя переменная var68
#define var193	BUFFER[13131]	// Внутренняя переменная var193
#define idvar193	30298	// Внутренняя переменная var193
#define var342	BUFFER[13133]	// Внутренняя переменная var342
#define idvar342	30299	// Внутренняя переменная var342
#define var409	BUFFER[13135]	// Внутренняя переменная var409
#define idvar409	30300	// Внутренняя переменная var409
#define var565	BUFFER[13137]	// Внутренняя переменная var565
#define idvar565	30301	// Внутренняя переменная var565
#define var1166	BUFFER[13142]	// Внутренняя переменная var1166
#define idvar1166	30302	// Внутренняя переменная var1166
#define var51	BUFFER[13144]	// Внутренняя переменная var51
#define idvar51	30303	// Внутренняя переменная var51
#define var83	BUFFER[13146]	// Внутренняя переменная var83
#define idvar83	30304	// Внутренняя переменная var83
#define var721	BUFFER[13148]	// Внутренняя переменная var721
#define idvar721	30305	// Внутренняя переменная var721
#define var624	BUFFER[13150]	// Внутренняя переменная var624
#define idvar624	30306	// Внутренняя переменная var624
#define var960	BUFFER[13152]	// Внутренняя переменная var960
#define idvar960	30307	// Внутренняя переменная var960
#define var1288	BUFFER[13154]	// Внутренняя переменная var1288
#define idvar1288	30308	// Внутренняя переменная var1288
#define var1892	BUFFER[13157]	// Внутренняя переменная var1892
#define idvar1892	30309	// Внутренняя переменная var1892
#define var718	BUFFER[13159]	// Внутренняя переменная var718
#define idvar718	30310	// Внутренняя переменная var718
#define var786	BUFFER[13161]	// Внутренняя переменная var786
#define idvar786	30311	// Внутренняя переменная var786
#define var1393	BUFFER[13163]	// Внутренняя переменная var1393
#define idvar1393	30312	// Внутренняя переменная var1393
#define var1475	BUFFER[13165]	// Внутренняя переменная var1475
#define idvar1475	30313	// Внутренняя переменная var1475
#define var463	BUFFER[13167]	// Внутренняя переменная var463
#define idvar463	30314	// Внутренняя переменная var463
#define var913	BUFFER[13169]	// Внутренняя переменная var913
#define idvar913	30315	// Внутренняя переменная var913
#define var1086	BUFFER[13171]	// Внутренняя переменная var1086
#define idvar1086	30316	// Внутренняя переменная var1086
#define var1420	BUFFER[13173]	// Внутренняя переменная var1420
#define idvar1420	30317	// Внутренняя переменная var1420
#define var1339	BUFFER[13175]	// Внутренняя переменная var1339
#define idvar1339	30318	// Внутренняя переменная var1339
#define var1414	BUFFER[13177]	// Внутренняя переменная var1414
#define idvar1414	30319	// Внутренняя переменная var1414
#define var97	BUFFER[13182]	// Внутренняя переменная var97
#define idvar97	30320	// Внутренняя переменная var97
#define var127	BUFFER[13184]	// Внутренняя переменная var127
#define idvar127	30321	// Внутренняя переменная var127
#define var391	BUFFER[13186]	// Внутренняя переменная var391
#define idvar391	30322	// Внутренняя переменная var391
#define var889	BUFFER[13189]	// Внутренняя переменная var889
#define idvar889	30323	// Внутренняя переменная var889
#define var938	BUFFER[13191]	// Внутренняя переменная var938
#define idvar938	30324	// Внутренняя переменная var938
#define var1298	BUFFER[13193]	// Внутренняя переменная var1298
#define idvar1298	30325	// Внутренняя переменная var1298
#define var153	BUFFER[13195]	// Внутренняя переменная var153
#define idvar153	30326	// Внутренняя переменная var153
#define var520	BUFFER[13197]	// Внутренняя переменная var520
#define idvar520	30327	// Внутренняя переменная var520
#define var244	BUFFER[13199]	// Внутренняя переменная var244
#define idvar244	30328	// Внутренняя переменная var244
#define var845	BUFFER[13201]	// Внутренняя переменная var845
#define idvar845	30329	// Внутренняя переменная var845
#define var1261	BUFFER[13203]	// Внутренняя переменная var1261
#define idvar1261	30330	// Внутренняя переменная var1261
#define var1890	BUFFER[13205]	// Внутренняя переменная var1890
#define idvar1890	30331	// Внутренняя переменная var1890
#define var16	BUFFER[13207]	// Внутренняя переменная var16
#define idvar16	30332	// Внутренняя переменная var16
#define var1148	BUFFER[13209]	// Внутренняя переменная var1148
#define idvar1148	30333	// Внутренняя переменная var1148
#define var1559	BUFFER[13211]	// Внутренняя переменная var1559
#define idvar1559	30334	// Внутренняя переменная var1559
#define var1808	BUFFER[13213]	// Внутренняя переменная var1808
#define idvar1808	30335	// Внутренняя переменная var1808
#define var1012	BUFFER[13215]	// Внутренняя переменная var1012
#define idvar1012	30336	// Внутренняя переменная var1012
#define var1183	BUFFER[13217]	// Внутренняя переменная var1183
#define idvar1183	30337	// Внутренняя переменная var1183
#define var1191	BUFFER[13219]	// Внутренняя переменная var1191
#define idvar1191	30338	// Внутренняя переменная var1191
#define var1707	BUFFER[13221]	// Внутренняя переменная var1707
#define idvar1707	30339	// Внутренняя переменная var1707
#define var1078	BUFFER[13223]	// Внутренняя переменная var1078
#define idvar1078	30340	// Внутренняя переменная var1078
#define var1182	BUFFER[13225]	// Внутренняя переменная var1182
#define idvar1182	30341	// Внутренняя переменная var1182
#define var1529	BUFFER[13227]	// Внутренняя переменная var1529
#define idvar1529	30342	// Внутренняя переменная var1529
#define var1613	BUFFER[13229]	// Внутренняя переменная var1613
#define idvar1613	30343	// Внутренняя переменная var1613
#define var142	BUFFER[13231]	// Внутренняя переменная var142
#define idvar142	30344	// Внутренняя переменная var142
#define var581	BUFFER[13233]	// Внутренняя переменная var581
#define idvar581	30345	// Внутренняя переменная var581
#define var982	BUFFER[13235]	// Внутренняя переменная var982
#define idvar982	30346	// Внутренняя переменная var982
#define var1630	BUFFER[13237]	// Внутренняя переменная var1630
#define idvar1630	30347	// Внутренняя переменная var1630
#define var1827	BUFFER[13239]	// Внутренняя переменная var1827
#define idvar1827	30348	// Внутренняя переменная var1827
#define var381	BUFFER[13241]	// Внутренняя переменная var381
#define idvar381	30349	// Внутренняя переменная var381
#define var439	BUFFER[13243]	// Внутренняя переменная var439
#define idvar439	30350	// Внутренняя переменная var439
#define var1713	BUFFER[13245]	// Внутренняя переменная var1713
#define idvar1713	30351	// Внутренняя переменная var1713
#define var968	BUFFER[13247]	// Внутренняя переменная var968
#define idvar968	30352	// Внутренняя переменная var968
#define var73	BUFFER[13249]	// Внутренняя переменная var73
#define idvar73	30353	// Внутренняя переменная var73
#define var1988	BUFFER[13251]	// Внутренняя переменная var1988
#define idvar1988	30354	// Внутренняя переменная var1988
#define var162	BUFFER[13256]	// Внутренняя переменная var162
#define idvar162	30355	// Внутренняя переменная var162
#define var340	BUFFER[13258]	// Внутренняя переменная var340
#define idvar340	30356	// Внутренняя переменная var340
#define var362	BUFFER[13260]	// Внутренняя переменная var362
#define idvar362	30357	// Внутренняя переменная var362
#define var1276	BUFFER[13262]	// Внутренняя переменная var1276
#define idvar1276	30358	// Внутренняя переменная var1276
#define var1380	BUFFER[13264]	// Внутренняя переменная var1380
#define idvar1380	30359	// Внутренняя переменная var1380
#define var1888	BUFFER[13266]	// Внутренняя переменная var1888
#define idvar1888	30360	// Внутренняя переменная var1888
#define var1765	BUFFER[13268]	// Внутренняя переменная var1765
#define idvar1765	30361	// Внутренняя переменная var1765
#define var1872	BUFFER[13270]	// Внутренняя переменная var1872
#define idvar1872	30362	// Внутренняя переменная var1872
#define var211	BUFFER[13272]	// Внутренняя переменная var211
#define idvar211	30363	// Внутренняя переменная var211
#define var431	BUFFER[13274]	// Внутренняя переменная var431
#define idvar431	30364	// Внутренняя переменная var431
#define var519	BUFFER[13276]	// Внутренняя переменная var519
#define idvar519	30365	// Внутренняя переменная var519
#define var649	BUFFER[13278]	// Внутренняя переменная var649
#define idvar649	30366	// Внутренняя переменная var649
#define var1087	BUFFER[13280]	// Внутренняя переменная var1087
#define idvar1087	30367	// Внутренняя переменная var1087
#define var1725	BUFFER[13282]	// Внутренняя переменная var1725
#define idvar1725	30368	// Внутренняя переменная var1725
#define var1877	BUFFER[13284]	// Внутренняя переменная var1877
#define idvar1877	30369	// Внутренняя переменная var1877
#define var1987	BUFFER[13286]	// Внутренняя переменная var1987
#define idvar1987	30370	// Внутренняя переменная var1987
#define var1999	BUFFER[13288]	// Внутренняя переменная var1999
#define idvar1999	30371	// Внутренняя переменная var1999
#define var178	BUFFER[13290]	// Внутренняя переменная var178
#define idvar178	30372	// Внутренняя переменная var178
#define var566	BUFFER[13292]	// Внутренняя переменная var566
#define idvar566	30373	// Внутренняя переменная var566
#define var876	BUFFER[13294]	// Внутренняя переменная var876
#define idvar876	30374	// Внутренняя переменная var876
#define var1093	BUFFER[13296]	// Внутренняя переменная var1093
#define idvar1093	30375	// Внутренняя переменная var1093
#define var1654	BUFFER[13298]	// Внутренняя переменная var1654
#define idvar1654	30376	// Внутренняя переменная var1654
#define var1742	BUFFER[13300]	// Внутренняя переменная var1742
#define idvar1742	30377	// Внутренняя переменная var1742
#define var58	BUFFER[13302]	// Внутренняя переменная var58
#define idvar58	30378	// Внутренняя переменная var58
#define var163	BUFFER[13304]	// Внутренняя переменная var163
#define idvar163	30379	// Внутренняя переменная var163
#define var559	BUFFER[13306]	// Внутренняя переменная var559
#define idvar559	30380	// Внутренняя переменная var559
#define var735	BUFFER[13308]	// Внутренняя переменная var735
#define idvar735	30381	// Внутренняя переменная var735
#define var848	BUFFER[13310]	// Внутренняя переменная var848
#define idvar848	30382	// Внутренняя переменная var848
#define var661	BUFFER[13312]	// Внутренняя переменная var661
#define idvar661	30383	// Внутренняя переменная var661
#define var701	BUFFER[13314]	// Внутренняя переменная var701
#define idvar701	30384	// Внутренняя переменная var701
#define var992	BUFFER[13316]	// Внутренняя переменная var992
#define idvar992	30385	// Внутренняя переменная var992
#define var1331	BUFFER[13318]	// Внутренняя переменная var1331
#define idvar1331	30386	// Внутренняя переменная var1331
#define var1485	BUFFER[13320]	// Внутренняя переменная var1485
#define idvar1485	30387	// Внутренняя переменная var1485
#define var184	BUFFER[13322]	// Внутренняя переменная var184
#define idvar184	30388	// Внутренняя переменная var184
#define var343	BUFFER[13324]	// Внутренняя переменная var343
#define idvar343	30389	// Внутренняя переменная var343
#define var702	BUFFER[13326]	// Внутренняя переменная var702
#define idvar702	30390	// Внутренняя переменная var702
#define var717	BUFFER[13328]	// Внутренняя переменная var717
#define idvar717	30391	// Внутренняя переменная var717
#define var821	BUFFER[13330]	// Внутренняя переменная var821
#define idvar821	30392	// Внутренняя переменная var821
#define var1368	BUFFER[13332]	// Внутренняя переменная var1368
#define idvar1368	30393	// Внутренняя переменная var1368
#define var723	BUFFER[13334]	// Внутренняя переменная var723
#define idvar723	30394	// Внутренняя переменная var723
#define var1787	BUFFER[13336]	// Внутренняя переменная var1787
#define idvar1787	30395	// Внутренняя переменная var1787
#define var1891	BUFFER[13338]	// Внутренняя переменная var1891
#define idvar1891	30396	// Внутренняя переменная var1891
#define var82	BUFFER[13340]	// Внутренняя переменная var82
#define idvar82	30397	// Внутренняя переменная var82
#define var469	BUFFER[13342]	// Внутренняя переменная var469
#define idvar469	30398	// Внутренняя переменная var469
#define var774	BUFFER[13344]	// Внутренняя переменная var774
#define idvar774	30399	// Внутренняя переменная var774
#define var1186	BUFFER[13346]	// Внутренняя переменная var1186
#define idvar1186	30400	// Внутренняя переменная var1186
#define var1854	BUFFER[13348]	// Внутренняя переменная var1854
#define idvar1854	30401	// Внутренняя переменная var1854
#define var592	BUFFER[13350]	// Внутренняя переменная var592
#define idvar592	30402	// Внутренняя переменная var592
#define var871	BUFFER[13352]	// Внутренняя переменная var871
#define idvar871	30403	// Внутренняя переменная var871
#define var1033	BUFFER[13354]	// Внутренняя переменная var1033
#define idvar1033	30404	// Внутренняя переменная var1033
#define var1107	BUFFER[13356]	// Внутренняя переменная var1107
#define idvar1107	30405	// Внутренняя переменная var1107
#define var1375	BUFFER[13358]	// Внутренняя переменная var1375
#define idvar1375	30406	// Внутренняя переменная var1375
#define var1705	BUFFER[13363]	// Внутренняя переменная var1705
#define idvar1705	30407	// Внутренняя переменная var1705
#define var1145	BUFFER[13365]	// Внутренняя переменная var1145
#define idvar1145	30408	// Внутренняя переменная var1145
#define var1400	BUFFER[13367]	// Внутренняя переменная var1400
#define idvar1400	30409	// Внутренняя переменная var1400
#define var1510	BUFFER[13369]	// Внутренняя переменная var1510
#define idvar1510	30410	// Внутренняя переменная var1510
#define var1939	BUFFER[13372]	// Внутренняя переменная var1939
#define idvar1939	30411	// Внутренняя переменная var1939
#define var88	BUFFER[13374]	// Внутренняя переменная var88
#define idvar88	30412	// Внутренняя переменная var88
#define var1929	BUFFER[13376]	// Внутренняя переменная var1929
#define idvar1929	30413	// Внутренняя переменная var1929
#define var31	BUFFER[13378]	// Внутренняя переменная var31
#define idvar31	30414	// Внутренняя переменная var31
#define var212	BUFFER[13380]	// Внутренняя переменная var212
#define idvar212	30415	// Внутренняя переменная var212
#define var539	BUFFER[13382]	// Внутренняя переменная var539
#define idvar539	30416	// Внутренняя переменная var539
#define var1304	BUFFER[13384]	// Внутренняя переменная var1304
#define idvar1304	30417	// Внутренняя переменная var1304
#define var126	BUFFER[13386]	// Внутренняя переменная var126
#define idvar126	30418	// Внутренняя переменная var126
#define var1294	BUFFER[13388]	// Внутренняя переменная var1294
#define idvar1294	30419	// Внутренняя переменная var1294
#define var459	BUFFER[13390]	// Внутренняя переменная var459
#define idvar459	30420	// Внутренняя переменная var459
#define var703	BUFFER[13395]	// Внутренняя переменная var703
#define idvar703	30421	// Внутренняя переменная var703
#define var1324	BUFFER[13397]	// Внутренняя переменная var1324
#define idvar1324	30422	// Внутренняя переменная var1324
#define var1619	BUFFER[13399]	// Внутренняя переменная var1619
#define idvar1619	30423	// Внутренняя переменная var1619
#define var116	BUFFER[13401]	// Внутренняя переменная var116
#define idvar116	30424	// Внутренняя переменная var116
#define var394	BUFFER[13403]	// Внутренняя переменная var394
#define idvar394	30425	// Внутренняя переменная var394
#define var1964	BUFFER[13405]	// Внутренняя переменная var1964
#define idvar1964	30426	// Внутренняя переменная var1964
#define var171	BUFFER[13407]	// Внутренняя переменная var171
#define idvar171	30427	// Внутренняя переменная var171
#define var1221	BUFFER[13409]	// Внутренняя переменная var1221
#define idvar1221	30428	// Внутренняя переменная var1221
#define var86	BUFFER[13411]	// Внутренняя переменная var86
#define idvar86	30429	// Внутренняя переменная var86
#define var205	BUFFER[13413]	// Внутренняя переменная var205
#define idvar205	30430	// Внутренняя переменная var205
#define var760	BUFFER[13415]	// Внутренняя переменная var760
#define idvar760	30431	// Внутренняя переменная var760
#define var969	BUFFER[13417]	// Внутренняя переменная var969
#define idvar969	30432	// Внутренняя переменная var969
#define var1450	BUFFER[13419]	// Внутренняя переменная var1450
#define idvar1450	30433	// Внутренняя переменная var1450
#define var106	BUFFER[13421]	// Внутренняя переменная var106
#define idvar106	30434	// Внутренняя переменная var106
#define var385	BUFFER[13423]	// Внутренняя переменная var385
#define idvar385	30435	// Внутренняя переменная var385
#define var746	BUFFER[13425]	// Внутренняя переменная var746
#define idvar746	30436	// Внутренняя переменная var746
#define var921	BUFFER[13427]	// Внутренняя переменная var921
#define idvar921	30437	// Внутренняя переменная var921
#define var1222	BUFFER[13429]	// Внутренняя переменная var1222
#define idvar1222	30438	// Внутренняя переменная var1222
#define var1800	BUFFER[13434]	// Внутренняя переменная var1800
#define idvar1800	30439	// Внутренняя переменная var1800
#define var419	BUFFER[13436]	// Внутренняя переменная var419
#define idvar419	30440	// Внутренняя переменная var419
#define var435	BUFFER[13438]	// Внутренняя переменная var435
#define idvar435	30441	// Внутренняя переменная var435
#define var892	BUFFER[13440]	// Внутренняя переменная var892
#define idvar892	30442	// Внутренняя переменная var892
#define var928	BUFFER[13442]	// Внутренняя переменная var928
#define idvar928	30443	// Внутренняя переменная var928
#define var1126	BUFFER[13444]	// Внутренняя переменная var1126
#define idvar1126	30444	// Внутренняя переменная var1126
#define var1195	BUFFER[13446]	// Внутренняя переменная var1195
#define idvar1195	30445	// Внутренняя переменная var1195
#define var1908	BUFFER[13448]	// Внутренняя переменная var1908
#define idvar1908	30446	// Внутренняя переменная var1908
#define var355	BUFFER[13450]	// Внутренняя переменная var355
#define idvar355	30447	// Внутренняя переменная var355
#define var556	BUFFER[13452]	// Внутренняя переменная var556
#define idvar556	30448	// Внутренняя переменная var556
#define var817	BUFFER[13454]	// Внутренняя переменная var817
#define idvar817	30449	// Внутренняя переменная var817
#define var1885	BUFFER[13456]	// Внутренняя переменная var1885
#define idvar1885	30450	// Внутренняя переменная var1885
#define var324	BUFFER[13458]	// Внутренняя переменная var324
#define idvar324	30451	// Внутренняя переменная var324
#define var379	BUFFER[13460]	// Внутренняя переменная var379
#define idvar379	30452	// Внутренняя переменная var379
#define var751	BUFFER[13462]	// Внутренняя переменная var751
#define idvar751	30453	// Внутренняя переменная var751
#define var886	BUFFER[13464]	// Внутренняя переменная var886
#define idvar886	30454	// Внутренняя переменная var886
#define var1497	BUFFER[13466]	// Внутренняя переменная var1497
#define idvar1497	30455	// Внутренняя переменная var1497
#define var1927	BUFFER[13468]	// Внутренняя переменная var1927
#define idvar1927	30456	// Внутренняя переменная var1927
#define var179	BUFFER[13470]	// Внутренняя переменная var179
#define idvar179	30457	// Внутренняя переменная var179
#define var547	BUFFER[13472]	// Внутренняя переменная var547
#define idvar547	30458	// Внутренняя переменная var547
#define var1481	BUFFER[13474]	// Внутренняя переменная var1481
#define idvar1481	30459	// Внутренняя переменная var1481
#define var28	BUFFER[13476]	// Внутренняя переменная var28
#define idvar28	30460	// Внутренняя переменная var28
#define var1521	BUFFER[13478]	// Внутренняя переменная var1521
#define idvar1521	30461	// Внутренняя переменная var1521
#define var570	BUFFER[13480]	// Внутренняя переменная var570
#define idvar570	30462	// Внутренняя переменная var570
#define var662	BUFFER[13482]	// Внутренняя переменная var662
#define idvar662	30463	// Внутренняя переменная var662
#define var809	BUFFER[13487]	// Внутренняя переменная var809
#define idvar809	30464	// Внутренняя переменная var809
#define var826	BUFFER[13489]	// Внутренняя переменная var826
#define idvar826	30465	// Внутренняя переменная var826
#define var908	BUFFER[13491]	// Внутренняя переменная var908
#define idvar908	30466	// Внутренняя переменная var908
#define var1219	BUFFER[13493]	// Внутренняя переменная var1219
#define idvar1219	30467	// Внутренняя переменная var1219
#define var275	BUFFER[13495]	// Внутренняя переменная var275
#define idvar275	30468	// Внутренняя переменная var275
#define var781	BUFFER[13497]	// Внутренняя переменная var781
#define idvar781	30469	// Внутренняя переменная var781
#define var977	BUFFER[13499]	// Внутренняя переменная var977
#define idvar977	30470	// Внутренняя переменная var977
#define var36	BUFFER[13501]	// Внутренняя переменная var36
#define idvar36	30471	// Внутренняя переменная var36
#define var347	BUFFER[13503]	// Внутренняя переменная var347
#define idvar347	30472	// Внутренняя переменная var347
#define var841	BUFFER[13505]	// Внутренняя переменная var841
#define idvar841	30473	// Внутренняя переменная var841
#define var1259	BUFFER[13507]	// Внутренняя переменная var1259
#define idvar1259	30474	// Внутренняя переменная var1259
#define var1816	BUFFER[13509]	// Внутренняя переменная var1816
#define idvar1816	30475	// Внутренняя переменная var1816
#define var1599	BUFFER[13511]	// Внутренняя переменная var1599
#define idvar1599	30476	// Внутренняя переменная var1599
#define var1766	BUFFER[13513]	// Внутренняя переменная var1766
#define idvar1766	30477	// Внутренняя переменная var1766
#define var45	BUFFER[13515]	// Внутренняя переменная var45
#define idvar45	30478	// Внутренняя переменная var45
#define var466	BUFFER[13520]	// Внутренняя переменная var466
#define idvar466	30479	// Внутренняя переменная var466
#define var579	BUFFER[13523]	// Внутренняя переменная var579
#define idvar579	30480	// Внутренняя переменная var579
#define var865	BUFFER[13525]	// Внутренняя переменная var865
#define idvar865	30481	// Внутренняя переменная var865
#define var965	BUFFER[13527]	// Внутренняя переменная var965
#define idvar965	30482	// Внутренняя переменная var965
#define var1503	BUFFER[13529]	// Внутренняя переменная var1503
#define idvar1503	30483	// Внутренняя переменная var1503
#define var7	BUFFER[13531]	// Внутренняя переменная var7
#define idvar7	30484	// Внутренняя переменная var7
#define var129	BUFFER[13533]	// Внутренняя переменная var129
#define idvar129	30485	// Внутренняя переменная var129
#define var577	BUFFER[13535]	// Внутренняя переменная var577
#define idvar577	30486	// Внутренняя переменная var577
#define var1759	BUFFER[13537]	// Внутренняя переменная var1759
#define idvar1759	30487	// Внутренняя переменная var1759
#define var478	BUFFER[13539]	// Внутренняя переменная var478
#define idvar478	30488	// Внутренняя переменная var478
#define var646	BUFFER[13541]	// Внутренняя переменная var646
#define idvar646	30489	// Внутренняя переменная var646
#define var1313	BUFFER[13543]	// Внутренняя переменная var1313
#define idvar1313	30490	// Внутренняя переменная var1313
#define var1586	BUFFER[13545]	// Внутренняя переменная var1586
#define idvar1586	30491	// Внутренняя переменная var1586
#define var1989	BUFFER[13547]	// Внутренняя переменная var1989
#define idvar1989	30492	// Внутренняя переменная var1989
#define var1140	BUFFER[13549]	// Внутренняя переменная var1140
#define idvar1140	30493	// Внутренняя переменная var1140
#define var1760	BUFFER[13551]	// Внутренняя переменная var1760
#define idvar1760	30494	// Внутренняя переменная var1760
#define var140	BUFFER[13553]	// Внутренняя переменная var140
#define idvar140	30495	// Внутренняя переменная var140
#define var229	BUFFER[13555]	// Внутренняя переменная var229
#define idvar229	30496	// Внутренняя переменная var229
#define var384	BUFFER[13557]	// Внутренняя переменная var384
#define idvar384	30497	// Внутренняя переменная var384
#define var411	BUFFER[13559]	// Внутренняя переменная var411
#define idvar411	30498	// Внутренняя переменная var411
#define var725	BUFFER[13561]	// Внутренняя переменная var725
#define idvar725	30499	// Внутренняя переменная var725
#define var1359	BUFFER[13563]	// Внутренняя переменная var1359
#define idvar1359	30500	// Внутренняя переменная var1359
#define var177	BUFFER[13565]	// Внутренняя переменная var177
#define idvar177	30501	// Внутренняя переменная var177
#define var357	BUFFER[13567]	// Внутренняя переменная var357
#define idvar357	30502	// Внутренняя переменная var357
#define var804	BUFFER[13569]	// Внутренняя переменная var804
#define idvar804	30503	// Внутренняя переменная var804
#define var396	BUFFER[13571]	// Внутренняя переменная var396
#define idvar396	30504	// Внутренняя переменная var396
#define var1543	BUFFER[13573]	// Внутренняя переменная var1543
#define idvar1543	30505	// Внутренняя переменная var1543
#define var1762	BUFFER[13575]	// Внутренняя переменная var1762
#define idvar1762	30506	// Внутренняя переменная var1762
#define var305	BUFFER[13577]	// Внутренняя переменная var305
#define idvar305	30507	// Внутренняя переменная var305
#define var643	BUFFER[13579]	// Внутренняя переменная var643
#define idvar643	30508	// Внутренняя переменная var643
#define var1208	BUFFER[13581]	// Внутренняя переменная var1208
#define idvar1208	30509	// Внутренняя переменная var1208
#define var1920	BUFFER[13583]	// Внутренняя переменная var1920
#define idvar1920	30510	// Внутренняя переменная var1920
#define var1957	BUFFER[13585]	// Внутренняя переменная var1957
#define idvar1957	30511	// Внутренняя переменная var1957
#define var113	BUFFER[13587]	// Внутренняя переменная var113
#define idvar113	30512	// Внутренняя переменная var113
#define var1137	BUFFER[13589]	// Внутренняя переменная var1137
#define idvar1137	30513	// Внутренняя переменная var1137
#define var1698	BUFFER[13591]	// Внутренняя переменная var1698
#define idvar1698	30514	// Внутренняя переменная var1698
#define var266	BUFFER[13593]	// Внутренняя переменная var266
#define idvar266	30515	// Внутренняя переменная var266
#define var454	BUFFER[13595]	// Внутренняя переменная var454
#define idvar454	30516	// Внутренняя переменная var454
#define var590	BUFFER[13597]	// Внутренняя переменная var590
#define idvar590	30517	// Внутренняя переменная var590
#define var1241	BUFFER[13599]	// Внутренняя переменная var1241
#define idvar1241	30518	// Внутренняя переменная var1241
#define var1749	BUFFER[13601]	// Внутренняя переменная var1749
#define idvar1749	30519	// Внутренняя переменная var1749
#define var293	BUFFER[13603]	// Внутренняя переменная var293
#define idvar293	30520	// Внутренняя переменная var293
#define var964	BUFFER[13605]	// Внутренняя переменная var964
#define idvar964	30521	// Внутренняя переменная var964
#define var1101	BUFFER[13607]	// Внутренняя переменная var1101
#define idvar1101	30522	// Внутренняя переменная var1101
#define var1789	BUFFER[13609]	// Внутренняя переменная var1789
#define idvar1789	30523	// Внутренняя переменная var1789
#define var1985	BUFFER[13611]	// Внутренняя переменная var1985
#define idvar1985	30524	// Внутренняя переменная var1985
#define var467	BUFFER[13616]	// Внутренняя переменная var467
#define idvar467	30525	// Внутренняя переменная var467
#define var897	BUFFER[13618]	// Внутренняя переменная var897
#define idvar897	30526	// Внутренняя переменная var897
#define var1961	BUFFER[13620]	// Внутренняя переменная var1961
#define idvar1961	30527	// Внутренняя переменная var1961
#define var168	BUFFER[13622]	// Внутренняя переменная var168
#define idvar168	30528	// Внутренняя переменная var168
#define var180	BUFFER[13624]	// Внутренняя переменная var180
#define idvar180	30529	// Внутренняя переменная var180
#define var895	BUFFER[13626]	// Внутренняя переменная var895
#define idvar895	30530	// Внутренняя переменная var895
#define var1049	BUFFER[13628]	// Внутренняя переменная var1049
#define idvar1049	30531	// Внутренняя переменная var1049
#define var483	BUFFER[13630]	// Внутренняя переменная var483
#define idvar483	30532	// Внутренняя переменная var483
#define var732	BUFFER[13632]	// Внутренняя переменная var732
#define idvar732	30533	// Внутренняя переменная var732
#define var1813	BUFFER[13634]	// Внутренняя переменная var1813
#define idvar1813	30534	// Внутренняя переменная var1813
#define var107	BUFFER[13636]	// Внутренняя переменная var107
#define idvar107	30535	// Внутренняя переменная var107
#define var502	BUFFER[13638]	// Внутренняя переменная var502
#define idvar502	30536	// Внутренняя переменная var502
#define var1330	BUFFER[13640]	// Внутренняя переменная var1330
#define idvar1330	30537	// Внутренняя переменная var1330
#define var1679	BUFFER[13642]	// Внутренняя переменная var1679
#define idvar1679	30538	// Внутренняя переменная var1679
#define var372	BUFFER[13644]	// Внутренняя переменная var372
#define idvar372	30539	// Внутренняя переменная var372
#define var387	BUFFER[13646]	// Внутренняя переменная var387
#define idvar387	30540	// Внутренняя переменная var387
#define var536	BUFFER[13648]	// Внутренняя переменная var536
#define idvar536	30541	// Внутренняя переменная var536
#define var6	BUFFER[13650]	// Внутренняя переменная var6
#define idvar6	30542	// Внутренняя переменная var6
#define var1459	BUFFER[13652]	// Внутренняя переменная var1459
#define idvar1459	30543	// Внутренняя переменная var1459
#define var1656	BUFFER[13654]	// Внутренняя переменная var1656
#define idvar1656	30544	// Внутренняя переменная var1656
#define var1876	BUFFER[13657]	// Внутренняя переменная var1876
#define idvar1876	30545	// Внутренняя переменная var1876
#define vainSFloat	BUFFER[13659]	// Внутренняя переменная vainSFloat
#define idvainSFloat	30546	// Внутренняя переменная vainSFloat
#define var640	BUFFER[13664]	// Внутренняя переменная var640
#define idvar640	30547	// Внутренняя переменная var640
#define var847	BUFFER[13666]	// Внутренняя переменная var847
#define idvar847	30548	// Внутренняя переменная var847
#define var850	BUFFER[13668]	// Внутренняя переменная var850
#define idvar850	30549	// Внутренняя переменная var850
#define var878	BUFFER[13670]	// Внутренняя переменная var878
#define idvar878	30550	// Внутренняя переменная var878
#define var1895	BUFFER[13672]	// Внутренняя переменная var1895
#define idvar1895	30551	// Внутренняя переменная var1895
#define var1928	BUFFER[13674]	// Внутренняя переменная var1928
#define idvar1928	30552	// Внутренняя переменная var1928
#define var798	BUFFER[13676]	// Внутренняя переменная var798
#define idvar798	30553	// Внутренняя переменная var798
#define var909	BUFFER[13678]	// Внутренняя переменная var909
#define idvar909	30554	// Внутренняя переменная var909
#define var1785	BUFFER[13680]	// Внутренняя переменная var1785
#define idvar1785	30555	// Внутренняя переменная var1785
#define var1780	BUFFER[13682]	// Внутренняя переменная var1780
#define idvar1780	30556	// Внутренняя переменная var1780
#define var1848	BUFFER[13684]	// Внутренняя переменная var1848
#define idvar1848	30557	// Внутренняя переменная var1848
#define var1896	BUFFER[13686]	// Внутренняя переменная var1896
#define idvar1896	30558	// Внутренняя переменная var1896
#define var130	BUFFER[13688]	// Внутренняя переменная var130
#define idvar130	30559	// Внутренняя переменная var130
#define var219	BUFFER[13690]	// Внутренняя переменная var219
#define idvar219	30560	// Внутренняя переменная var219
#define var451	BUFFER[13692]	// Внутренняя переменная var451
#define idvar451	30561	// Внутренняя переменная var451
#define var1627	BUFFER[13694]	// Внутренняя переменная var1627
#define idvar1627	30562	// Внутренняя переменная var1627
#define var1133	BUFFER[13696]	// Внутренняя переменная var1133
#define idvar1133	30563	// Внутренняя переменная var1133
#define var1205	BUFFER[13698]	// Внутренняя переменная var1205
#define idvar1205	30564	// Внутренняя переменная var1205
#define var1546	BUFFER[13700]	// Внутренняя переменная var1546
#define idvar1546	30565	// Внутренняя переменная var1546
#define var1638	BUFFER[13703]	// Внутренняя переменная var1638
#define idvar1638	30566	// Внутренняя переменная var1638
#define var1847	BUFFER[13705]	// Внутренняя переменная var1847
#define idvar1847	30567	// Внутренняя переменная var1847
#define var109	BUFFER[13707]	// Внутренняя переменная var109
#define idvar109	30568	// Внутренняя переменная var109
#define var600	BUFFER[13709]	// Внутренняя переменная var600
#define idvar600	30569	// Внутренняя переменная var600
#define var749	BUFFER[13711]	// Внутренняя переменная var749
#define idvar749	30570	// Внутренняя переменная var749
#define var103	BUFFER[13713]	// Внутренняя переменная var103
#define idvar103	30571	// Внутренняя переменная var103
#define var1027	BUFFER[13715]	// Внутренняя переменная var1027
#define idvar1027	30572	// Внутренняя переменная var1027
#define var1144	BUFFER[13717]	// Внутренняя переменная var1144
#define idvar1144	30573	// Внутренняя переменная var1144
#define var1247	BUFFER[13719]	// Внутренняя переменная var1247
#define idvar1247	30574	// Внутренняя переменная var1247
#define var1254	BUFFER[13721]	// Внутренняя переменная var1254
#define idvar1254	30575	// Внутренняя переменная var1254
#define var1741	BUFFER[13723]	// Внутренняя переменная var1741
#define idvar1741	30576	// Внутренняя переменная var1741
#define var380	BUFFER[13725]	// Внутренняя переменная var380
#define idvar380	30577	// Внутренняя переменная var380
#define var644	BUFFER[13727]	// Внутренняя переменная var644
#define idvar644	30578	// Внутренняя переменная var644
#define var846	BUFFER[13729]	// Внутренняя переменная var846
#define idvar846	30579	// Внутренняя переменная var846
#define var1242	BUFFER[13731]	// Внутренняя переменная var1242
#define idvar1242	30580	// Внутренняя переменная var1242
#define var1550	BUFFER[13733]	// Внутренняя переменная var1550
#define idvar1550	30581	// Внутренняя переменная var1550
#define var115	BUFFER[13735]	// Внутренняя переменная var115
#define idvar115	30582	// Внутренняя переменная var115
#define var1537	BUFFER[13737]	// Внутренняя переменная var1537
#define idvar1537	30583	// Внутренняя переменная var1537
#define var237	BUFFER[13742]	// Внутренняя переменная var237
#define idvar237	30584	// Внутренняя переменная var237
#define var398	BUFFER[13744]	// Внутренняя переменная var398
#define idvar398	30585	// Внутренняя переменная var398
#define var498	BUFFER[13746]	// Внутренняя переменная var498
#define idvar498	30586	// Внутренняя переменная var498
#define var681	BUFFER[13748]	// Внутренняя переменная var681
#define idvar681	30587	// Внутренняя переменная var681
#define var1925	BUFFER[13750]	// Внутренняя переменная var1925
#define idvar1925	30588	// Внутренняя переменная var1925
#define var341	BUFFER[13752]	// Внутренняя переменная var341
#define idvar341	30589	// Внутренняя переменная var341
#define var488	BUFFER[13754]	// Внутренняя переменная var488
#define idvar488	30590	// Внутренняя переменная var488
#define var1935	BUFFER[13756]	// Внутренняя переменная var1935
#define idvar1935	30591	// Внутренняя переменная var1935
#define var834	BUFFER[13758]	// Внутренняя переменная var834
#define idvar834	30592	// Внутренняя переменная var834
#define var837	BUFFER[13760]	// Внутренняя переменная var837
#define idvar837	30593	// Внутренняя переменная var837
#define var1270	BUFFER[13762]	// Внутренняя переменная var1270
#define idvar1270	30594	// Внутренняя переменная var1270
#define var1436	BUFFER[13764]	// Внутренняя переменная var1436
#define idvar1436	30595	// Внутренняя переменная var1436
#define var1545	BUFFER[13766]	// Внутренняя переменная var1545
#define idvar1545	30596	// Внутренняя переменная var1545
#define var254	BUFFER[13771]	// Внутренняя переменная var254
#define idvar254	30597	// Внутренняя переменная var254
#define var1882	BUFFER[13773]	// Внутренняя переменная var1882
#define idvar1882	30598	// Внутренняя переменная var1882
#define var510	BUFFER[13775]	// Внутренняя переменная var510
#define idvar510	30599	// Внутренняя переменная var510
#define var936	BUFFER[13777]	// Внутренняя переменная var936
#define idvar936	30600	// Внутренняя переменная var936
#define var1277	BUFFER[13779]	// Внутренняя переменная var1277
#define idvar1277	30601	// Внутренняя переменная var1277
#define var1603	BUFFER[13781]	// Внутренняя переменная var1603
#define idvar1603	30602	// Внутренняя переменная var1603
#define var733	BUFFER[13783]	// Внутренняя переменная var733
#define idvar733	30603	// Внутренняя переменная var733
#define var820	BUFFER[13785]	// Внутренняя переменная var820
#define idvar820	30604	// Внутренняя переменная var820
#define var815	BUFFER[13787]	// Внутренняя переменная var815
#define idvar815	30605	// Внутренняя переменная var815
#define var1455	BUFFER[13789]	// Внутренняя переменная var1455
#define idvar1455	30606	// Внутренняя переменная var1455
#define var550	BUFFER[13791]	// Внутренняя переменная var550
#define idvar550	30607	// Внутренняя переменная var550
#define var759	BUFFER[13793]	// Внутренняя переменная var759
#define idvar759	30608	// Внутренняя переменная var759
#define var1220	BUFFER[13795]	// Внутренняя переменная var1220
#define idvar1220	30609	// Внутренняя переменная var1220
#define var1343	BUFFER[13797]	// Внутренняя переменная var1343
#define idvar1343	30610	// Внутренняя переменная var1343
#define var1574	BUFFER[13799]	// Внутренняя переменная var1574
#define idvar1574	30611	// Внутренняя переменная var1574
#define var899	BUFFER[13801]	// Внутренняя переменная var899
#define idvar899	30612	// Внутренняя переменная var899
#define var1336	BUFFER[13803]	// Внутренняя переменная var1336
#define idvar1336	30613	// Внутренняя переменная var1336
#define var1526	BUFFER[13805]	// Внутренняя переменная var1526
#define idvar1526	30614	// Внутренняя переменная var1526
#define var110	BUFFER[13807]	// Внутренняя переменная var110
#define idvar110	30615	// Внутренняя переменная var110
#define var574	BUFFER[13809]	// Внутренняя переменная var574
#define idvar574	30616	// Внутренняя переменная var574
#define var954	BUFFER[13811]	// Внутренняя переменная var954
#define idvar954	30617	// Внутренняя переменная var954
#define var1954	BUFFER[13813]	// Внутренняя переменная var1954
#define idvar1954	30618	// Внутренняя переменная var1954
#define var268	BUFFER[13815]	// Внутренняя переменная var268
#define idvar268	30619	// Внутренняя переменная var268
#define var1057	BUFFER[13817]	// Внутренняя переменная var1057
#define idvar1057	30620	// Внутренняя переменная var1057
#define var1155	BUFFER[13819]	// Внутренняя переменная var1155
#define idvar1155	30621	// Внутренняя переменная var1155
#define var263	BUFFER[13821]	// Внутренняя переменная var263
#define idvar263	30622	// Внутренняя переменная var263
#define var541	BUFFER[13823]	// Внутренняя переменная var541
#define idvar541	30623	// Внутренняя переменная var541
#define var1448	BUFFER[13825]	// Внутренняя переменная var1448
#define idvar1448	30624	// Внутренняя переменная var1448
#define var1699	BUFFER[13827]	// Внутренняя переменная var1699
#define idvar1699	30625	// Внутренняя переменная var1699
#define var2001	BUFFER[13830]	// Внутренняя переменная var2001
#define idvar2001	30626	// Внутренняя переменная var2001
#define var1751	BUFFER[13835]	// Внутренняя переменная var1751
#define idvar1751	30627	// Внутренняя переменная var1751
#define var1941	BUFFER[13837]	// Внутренняя переменная var1941
#define idvar1941	30628	// Внутренняя переменная var1941
#define var500	BUFFER[13839]	// Внутренняя переменная var500
#define idvar500	30629	// Внутренняя переменная var500
#define var571	BUFFER[13841]	// Внутренняя переменная var571
#define idvar571	30630	// Внутренняя переменная var571
#define var758	BUFFER[13843]	// Внутренняя переменная var758
#define idvar758	30631	// Внутренняя переменная var758
#define var872	BUFFER[13845]	// Внутренняя переменная var872
#define idvar872	30632	// Внутренняя переменная var872
#define var1278	BUFFER[13847]	// Внутренняя переменная var1278
#define idvar1278	30633	// Внутренняя переменная var1278
#define var1287	BUFFER[13849]	// Внутренняя переменная var1287
#define idvar1287	30634	// Внутренняя переменная var1287
#define var1992	BUFFER[13852]	// Внутренняя переменная var1992
#define idvar1992	30635	// Внутренняя переменная var1992
#define var48	BUFFER[13854]	// Внутренняя переменная var48
#define idvar48	30636	// Внутренняя переменная var48
#define var666	BUFFER[13856]	// Внутренняя переменная var666
#define idvar666	30637	// Внутренняя переменная var666
#define var672	BUFFER[13861]	// Внутренняя переменная var672
#define idvar672	30638	// Внутренняя переменная var672
#define var704	BUFFER[13866]	// Внутренняя переменная var704
#define idvar704	30639	// Внутренняя переменная var704
#define var1197	BUFFER[13868]	// Внутренняя переменная var1197
#define idvar1197	30640	// Внутренняя переменная var1197
#define var143	BUFFER[13870]	// Внутренняя переменная var143
#define idvar143	30641	// Внутренняя переменная var143
#define var947	BUFFER[13872]	// Внутренняя переменная var947
#define idvar947	30642	// Внутренняя переменная var947
#define var1074	BUFFER[13874]	// Внутренняя переменная var1074
#define idvar1074	30643	// Внутренняя переменная var1074
#define var1406	BUFFER[13876]	// Внутренняя переменная var1406
#define idvar1406	30644	// Внутренняя переменная var1406
#define var1907	BUFFER[13878]	// Внутренняя переменная var1907
#define idvar1907	30645	// Внутренняя переменная var1907
#define var584	BUFFER[13880]	// Внутренняя переменная var584
#define idvar584	30646	// Внутренняя переменная var584
#define var639	BUFFER[13882]	// Внутренняя переменная var639
#define idvar639	30647	// Внутренняя переменная var639
#define var1151	BUFFER[13884]	// Внутренняя переменная var1151
#define idvar1151	30648	// Внутренняя переменная var1151
#define var1657	BUFFER[13886]	// Внутренняя переменная var1657
#define idvar1657	30649	// Внутренняя переменная var1657
#define var1982	BUFFER[13888]	// Внутренняя переменная var1982
#define idvar1982	30650	// Внутренняя переменная var1982
#define var790	BUFFER[13893]	// Внутренняя переменная var790
#define idvar790	30651	// Внутренняя переменная var790
#define var67	BUFFER[13895]	// Внутренняя переменная var67
#define idvar67	30652	// Внутренняя переменная var67
#define var806	BUFFER[13897]	// Внутренняя переменная var806
#define idvar806	30653	// Внутренняя переменная var806
#define var1345	BUFFER[13899]	// Внутренняя переменная var1345
#define idvar1345	30654	// Внутренняя переменная var1345
#define var1432	BUFFER[13901]	// Внутренняя переменная var1432
#define idvar1432	30655	// Внутренняя переменная var1432
#define var1670	BUFFER[13903]	// Внутренняя переменная var1670
#define idvar1670	30656	// Внутренняя переменная var1670
#define var1886	BUFFER[13905]	// Внутренняя переменная var1886
#define idvar1886	30657	// Внутренняя переменная var1886
#define var620	BUFFER[13907]	// Внутренняя переменная var620
#define idvar620	30658	// Внутренняя переменная var620
#define var1899	BUFFER[13909]	// Внутренняя переменная var1899
#define idvar1899	30659	// Внутренняя переменная var1899
#define var1196	BUFFER[13911]	// Внутренняя переменная var1196
#define idvar1196	30660	// Внутренняя переменная var1196
#define var1509	BUFFER[13913]	// Внутренняя переменная var1509
#define idvar1509	30661	// Внутренняя переменная var1509
#define var1519	BUFFER[13915]	// Внутренняя переменная var1519
#define idvar1519	30662	// Внутренняя переменная var1519
#define var360	BUFFER[13917]	// Внутренняя переменная var360
#define idvar360	30663	// Внутренняя переменная var360
#define var558	BUFFER[13919]	// Внутренняя переменная var558
#define idvar558	30664	// Внутренняя переменная var558
#define var1540	BUFFER[13921]	// Внутренняя переменная var1540
#define idvar1540	30665	// Внутренняя переменная var1540
#define var1652	BUFFER[13923]	// Внутренняя переменная var1652
#define idvar1652	30666	// Внутренняя переменная var1652
#define var1733	BUFFER[13925]	// Внутренняя переменная var1733
#define idvar1733	30667	// Внутренняя переменная var1733
#define var766	BUFFER[13930]	// Внутренняя переменная var766
#define idvar766	30668	// Внутренняя переменная var766
#define var1690	BUFFER[13932]	// Внутренняя переменная var1690
#define idvar1690	30669	// Внутренняя переменная var1690
#define var1805	BUFFER[13937]	// Внутренняя переменная var1805
#define idvar1805	30670	// Внутренняя переменная var1805
#define var99	BUFFER[13939]	// Внутренняя переменная var99
#define idvar99	30671	// Внутренняя переменная var99
#define var1443	BUFFER[13941]	// Внутренняя переменная var1443
#define idvar1443	30672	// Внутренняя переменная var1443
#define var1474	BUFFER[13943]	// Внутренняя переменная var1474
#define idvar1474	30673	// Внутренняя переменная var1474
#define var1577	BUFFER[13945]	// Внутренняя переменная var1577
#define idvar1577	30674	// Внутренняя переменная var1577
#define var687	BUFFER[13950]	// Внутренняя переменная var687
#define idvar687	30675	// Внутренняя переменная var687
#define var868	BUFFER[13952]	// Внутренняя переменная var868
#define idvar868	30676	// Внутренняя переменная var868
#define var946	BUFFER[13954]	// Внутренняя переменная var946
#define idvar946	30677	// Внутренняя переменная var946
#define var1833	BUFFER[13956]	// Внутренняя переменная var1833
#define idvar1833	30678	// Внутренняя переменная var1833
#define var1884	BUFFER[13958]	// Внутренняя переменная var1884
#define idvar1884	30679	// Внутренняя переменная var1884
#define var1991	BUFFER[13960]	// Внутренняя переменная var1991
#define idvar1991	30680	// Внутренняя переменная var1991
#define var238	BUFFER[13965]	// Внутренняя переменная var238
#define idvar238	30681	// Внутренняя переменная var238
#define var575	BUFFER[13967]	// Внутренняя переменная var575
#define idvar575	30682	// Внутренняя переменная var575
#define var710	BUFFER[13969]	// Внутренняя переменная var710
#define idvar710	30683	// Внутренняя переменная var710
#define var1480	BUFFER[13971]	// Внутренняя переменная var1480
#define idvar1480	30684	// Внутренняя переменная var1480
#define var1562	BUFFER[13973]	// Внутренняя переменная var1562
#define idvar1562	30685	// Внутренняя переменная var1562
#define var1996	BUFFER[13975]	// Внутренняя переменная var1996
#define idvar1996	30686	// Внутренняя переменная var1996
#define var1091	BUFFER[13977]	// Внутренняя переменная var1091
#define idvar1091	30687	// Внутренняя переменная var1091
#define var1154	BUFFER[13979]	// Внутренняя переменная var1154
#define idvar1154	30688	// Внутренняя переменная var1154
#define var1984	BUFFER[13981]	// Внутренняя переменная var1984
#define idvar1984	30689	// Внутренняя переменная var1984
#define var585	BUFFER[13983]	// Внутренняя переменная var585
#define idvar585	30690	// Внутренняя переменная var585
#define var1756	BUFFER[13985]	// Внутренняя переменная var1756
#define idvar1756	30691	// Внутренняя переменная var1756
#define var145	BUFFER[13987]	// Внутренняя переменная var145
#define idvar145	30692	// Внутренняя переменная var145
#define var159	BUFFER[13989]	// Внутренняя переменная var159
#define idvar159	30693	// Внутренняя переменная var159
#define var974	BUFFER[13991]	// Внутренняя переменная var974
#define idvar974	30694	// Внутренняя переменная var974
#define var1046	BUFFER[13993]	// Внутренняя переменная var1046
#define idvar1046	30695	// Внутренняя переменная var1046
#define var1975	BUFFER[13995]	// Внутренняя переменная var1975
#define idvar1975	30696	// Внутренняя переменная var1975
#define var257	BUFFER[13997]	// Внутренняя переменная var257
#define idvar257	30697	// Внутренняя переменная var257
#define var1439	BUFFER[13999]	// Внутренняя переменная var1439
#define idvar1439	30698	// Внутренняя переменная var1439
#define var1506	BUFFER[14001]	// Внутренняя переменная var1506
#define idvar1506	30699	// Внутренняя переменная var1506
#define var494	BUFFER[14003]	// Внутренняя переменная var494
#define idvar494	30700	// Внутренняя переменная var494
#define var674	BUFFER[14005]	// Внутренняя переменная var674
#define idvar674	30701	// Внутренняя переменная var674
#define var862	BUFFER[14007]	// Внутренняя переменная var862
#define idvar862	30702	// Внутренняя переменная var862
#define var1858	BUFFER[14009]	// Внутренняя переменная var1858
#define idvar1858	30703	// Внутренняя переменная var1858
#define var43	BUFFER[14011]	// Внутренняя переменная var43
#define idvar43	30704	// Внутренняя переменная var43
#define var137	BUFFER[14013]	// Внутренняя переменная var137
#define idvar137	30705	// Внутренняя переменная var137
#define var375	BUFFER[14015]	// Внутренняя переменная var375
#define idvar375	30706	// Внутренняя переменная var375
#define var475	BUFFER[14017]	// Внутренняя переменная var475
#define idvar475	30707	// Внутренняя переменная var475
#define var1136	BUFFER[14019]	// Внутренняя переменная var1136
#define idvar1136	30708	// Внутренняя переменная var1136
#define var1781	BUFFER[14021]	// Внутренняя переменная var1781
#define idvar1781	30709	// Внутренняя переменная var1781
#define var1077	BUFFER[14023]	// Внутренняя переменная var1077
#define idvar1077	30710	// Внутренняя переменная var1077
#define var1597	BUFFER[14025]	// Внутренняя переменная var1597
#define idvar1597	30711	// Внутренняя переменная var1597
#define var1637	BUFFER[14027]	// Внутренняя переменная var1637
#define idvar1637	30712	// Внутренняя переменная var1637
#define var1740	BUFFER[14029]	// Внутренняя переменная var1740
#define idvar1740	30713	// Внутренняя переменная var1740
#define var242	BUFFER[14031]	// Внутренняя переменная var242
#define idvar242	30714	// Внутренняя переменная var242
#define var1618	BUFFER[14033]	// Внутренняя переменная var1618
#define idvar1618	30715	// Внутренняя переменная var1618
#define var1720	BUFFER[14035]	// Внутренняя переменная var1720
#define idvar1720	30716	// Внутренняя переменная var1720
#define var96	BUFFER[14037]	// Внутренняя переменная var96
#define idvar96	30717	// Внутренняя переменная var96
#define var551	BUFFER[14039]	// Внутренняя переменная var551
#define idvar551	30718	// Внутренняя переменная var551
#define var1642	BUFFER[14041]	// Внутренняя переменная var1642
#define idvar1642	30719	// Внутренняя переменная var1642
#define var1843	BUFFER[14043]	// Внутренняя переменная var1843
#define idvar1843	30720	// Внутренняя переменная var1843
#define var1977	BUFFER[14045]	// Внутренняя переменная var1977
#define idvar1977	30721	// Внутренняя переменная var1977
#define var231	BUFFER[14047]	// Внутренняя переменная var231
#define idvar231	30722	// Внутренняя переменная var231
#define var1050	BUFFER[14049]	// Внутренняя переменная var1050
#define idvar1050	30723	// Внутренняя переменная var1050
#define var1080	BUFFER[14051]	// Внутренняя переменная var1080
#define idvar1080	30724	// Внутренняя переменная var1080
#define var1209	BUFFER[14053]	// Внутренняя переменная var1209
#define idvar1209	30725	// Внутренняя переменная var1209
#define var1976	BUFFER[14055]	// Внутренняя переменная var1976
#define idvar1976	30726	// Внутренняя переменная var1976
#define var105	BUFFER[14057]	// Внутренняя переменная var105
#define idvar105	30727	// Внутренняя переменная var105
#define var554	BUFFER[14059]	// Внутренняя переменная var554
#define idvar554	30728	// Внутренняя переменная var554
#define var935	BUFFER[14061]	// Внутренняя переменная var935
#define idvar935	30729	// Внутренняя переменная var935
#define var1376	BUFFER[14063]	// Внутренняя переменная var1376
#define idvar1376	30730	// Внутренняя переменная var1376
#define var1555	BUFFER[14065]	// Внутренняя переменная var1555
#define idvar1555	30731	// Внутренняя переменная var1555
#define var25	BUFFER[14067]	// Внутренняя переменная var25
#define idvar25	30732	// Внутренняя переменная var25
#define var32	BUFFER[14069]	// Внутренняя переменная var32
#define idvar32	30733	// Внутренняя переменная var32
#define var1131	BUFFER[14071]	// Внутренняя переменная var1131
#define idvar1131	30734	// Внутренняя переменная var1131
#define var1471	BUFFER[14073]	// Внутренняя переменная var1471
#define idvar1471	30735	// Внутренняя переменная var1471
#define var1621	BUFFER[14075]	// Внутренняя переменная var1621
#define idvar1621	30736	// Внутренняя переменная var1621
#define var260	BUFFER[14077]	// Внутренняя переменная var260
#define idvar260	30737	// Внутренняя переменная var260
#define var693	BUFFER[14079]	// Внутренняя переменная var693
#define idvar693	30738	// Внутренняя переменная var693
#define var1643	BUFFER[14081]	// Внутренняя переменная var1643
#define idvar1643	30739	// Внутренняя переменная var1643
#define var1384	BUFFER[14086]	// Внутренняя переменная var1384
#define idvar1384	30740	// Внутренняя переменная var1384
#define var1937	BUFFER[14088]	// Внутренняя переменная var1937
#define idvar1937	30741	// Внутренняя переменная var1937
#define var190	BUFFER[14090]	// Внутренняя переменная var190
#define idvar190	30742	// Внутренняя переменная var190
#define var810	BUFFER[14092]	// Внутренняя переменная var810
#define idvar810	30743	// Внутренняя переменная var810
#define var838	BUFFER[14094]	// Внутренняя переменная var838
#define idvar838	30744	// Внутренняя переменная var838
#define var1143	BUFFER[14096]	// Внутренняя переменная var1143
#define idvar1143	30745	// Внутренняя переменная var1143
#define var1153	BUFFER[14098]	// Внутренняя переменная var1153
#define idvar1153	30746	// Внутренняя переменная var1153
#define var1297	BUFFER[14100]	// Внутренняя переменная var1297
#define idvar1297	30747	// Внутренняя переменная var1297
#define var227	BUFFER[14102]	// Внутренняя переменная var227
#define idvar227	30748	// Внутренняя переменная var227
#define var583	BUFFER[14104]	// Внутренняя переменная var583
#define idvar583	30749	// Внутренняя переменная var583
#define var1280	BUFFER[14106]	// Внутренняя переменная var1280
#define idvar1280	30750	// Внутренняя переменная var1280
#define var548	BUFFER[14108]	// Внутренняя переменная var548
#define idvar548	30751	// Внутренняя переменная var548
#define var1006	BUFFER[14110]	// Внутренняя переменная var1006
#define idvar1006	30752	// Внутренняя переменная var1006
#define var63	BUFFER[14112]	// Внутренняя переменная var63
#define idvar63	30753	// Внутренняя переменная var63
#define var120	BUFFER[14114]	// Внутренняя переменная var120
#define idvar120	30754	// Внутренняя переменная var120
#define var255	BUFFER[14116]	// Внутренняя переменная var255
#define idvar255	30755	// Внутренняя переменная var255
#define var265	BUFFER[14118]	// Внутренняя переменная var265
#define idvar265	30756	// Внутренняя переменная var265
#define var271	BUFFER[14120]	// Внутренняя переменная var271
#define idvar271	30757	// Внутренняя переменная var271
#define var281	BUFFER[14122]	// Внутренняя переменная var281
#define idvar281	30758	// Внутренняя переменная var281
#define var1923	BUFFER[14124]	// Внутренняя переменная var1923
#define idvar1923	30759	// Внутренняя переменная var1923
#define var647	BUFFER[14126]	// Внутренняя переменная var647
#define idvar647	30760	// Внутренняя переменная var647
#define var1135	BUFFER[14128]	// Внутренняя переменная var1135
#define idvar1135	30761	// Внутренняя переменная var1135
#define var1329	BUFFER[14130]	// Внутренняя переменная var1329
#define idvar1329	30762	// Внутренняя переменная var1329
#define var371	BUFFER[14132]	// Внутренняя переменная var371
#define idvar371	30763	// Внутренняя переменная var371
#define var761	BUFFER[14134]	// Внутренняя переменная var761
#define idvar761	30764	// Внутренняя переменная var761
#define var792	BUFFER[14136]	// Внутренняя переменная var792
#define idvar792	30765	// Внутренняя переменная var792
#define var1898	BUFFER[14138]	// Внутренняя переменная var1898
#define idvar1898	30766	// Внутренняя переменная var1898
#define var597	BUFFER[14140]	// Внутренняя переменная var597
#define idvar597	30767	// Внутренняя переменная var597
#define var835	BUFFER[14142]	// Внутренняя переменная var835
#define idvar835	30768	// Внутренняя переменная var835
#define var1207	BUFFER[14144]	// Внутренняя переменная var1207
#define idvar1207	30769	// Внутренняя переменная var1207
#define var100	BUFFER[14146]	// Внутренняя переменная var100
#define idvar100	30770	// Внутренняя переменная var100
#define var1238	BUFFER[14148]	// Внутренняя переменная var1238
#define idvar1238	30771	// Внутренняя переменная var1238
#define var1687	BUFFER[14150]	// Внутренняя переменная var1687
#define idvar1687	30772	// Внутренняя переменная var1687
#define var1743	BUFFER[14153]	// Внутренняя переменная var1743
#define idvar1743	30773	// Внутренняя переменная var1743
#define var322	BUFFER[14155]	// Внутренняя переменная var322
#define idvar322	30774	// Внутренняя переменная var322
#define var985	BUFFER[14157]	// Внутренняя переменная var985
#define idvar985	30775	// Внутренняя переменная var985
#define var1163	BUFFER[14159]	// Внутренняя переменная var1163
#define idvar1163	30776	// Внутренняя переменная var1163
#define var1614	BUFFER[14161]	// Внутренняя переменная var1614
#define idvar1614	30777	// Внутренняя переменная var1614
#define var1918	BUFFER[14163]	// Внутренняя переменная var1918
#define idvar1918	30778	// Внутренняя переменная var1918
#define var203	BUFFER[14165]	// Внутренняя переменная var203
#define idvar203	30779	// Внутренняя переменная var203
#define var1349	BUFFER[14167]	// Внутренняя переменная var1349
#define idvar1349	30780	// Внутренняя переменная var1349
#define var1541	BUFFER[14169]	// Внутренняя переменная var1541
#define idvar1541	30781	// Внутренняя переменная var1541
#define var1727	BUFFER[14171]	// Внутренняя переменная var1727
#define idvar1727	30782	// Внутренняя переменная var1727
#define var1936	BUFFER[14176]	// Внутренняя переменная var1936
#define idvar1936	30783	// Внутренняя переменная var1936
#define var1956	BUFFER[14178]	// Внутренняя переменная var1956
#define idvar1956	30784	// Внутренняя переменная var1956
#define var404	BUFFER[14180]	// Внутренняя переменная var404
#define idvar404	30785	// Внутренняя переменная var404
#define var540	BUFFER[14182]	// Внутренняя переменная var540
#define idvar540	30786	// Внутренняя переменная var540
#define var729	BUFFER[14184]	// Внутренняя переменная var729
#define idvar729	30787	// Внутренняя переменная var729
#define var1507	BUFFER[14186]	// Внутренняя переменная var1507
#define idvar1507	30788	// Внутренняя переменная var1507
#define var410	BUFFER[14188]	// Внутренняя переменная var410
#define idvar410	30789	// Внутренняя переменная var410
#define var689	BUFFER[14190]	// Внутренняя переменная var689
#define idvar689	30790	// Внутренняя переменная var689
#define var1156	BUFFER[14192]	// Внутренняя переменная var1156
#define idvar1156	30791	// Внутренняя переменная var1156
#define var1419	BUFFER[14194]	// Внутренняя переменная var1419
#define idvar1419	30792	// Внутренняя переменная var1419
#define var1901	BUFFER[14196]	// Внутренняя переменная var1901
#define idvar1901	30793	// Внутренняя переменная var1901
#define var1729	BUFFER[14198]	// Внутренняя переменная var1729
#define idvar1729	30794	// Внутренняя переменная var1729
#define var1910	BUFFER[14200]	// Внутренняя переменная var1910
#define idvar1910	30795	// Внутренняя переменная var1910
#define var1062	BUFFER[14202]	// Внутренняя переменная var1062
#define idvar1062	30796	// Внутренняя переменная var1062
#define var1386	BUFFER[14204]	// Внутренняя переменная var1386
#define idvar1386	30797	// Внутренняя переменная var1386
#define var289	BUFFER[14206]	// Внутренняя переменная var289
#define idvar289	30798	// Внутренняя переменная var289
#define var492	BUFFER[14208]	// Внутренняя переменная var492
#define idvar492	30799	// Внутренняя переменная var492
#define var1198	BUFFER[14210]	// Внутренняя переменная var1198
#define idvar1198	30800	// Внутренняя переменная var1198
#define var1998	BUFFER[14212]	// Внутренняя переменная var1998
#define idvar1998	30801	// Внутренняя переменная var1998
#define var1864	BUFFER[14214]	// Внутренняя переменная var1864
#define idvar1864	30802	// Внутренняя переменная var1864
#define var1932	BUFFER[14216]	// Внутренняя переменная var1932
#define idvar1932	30803	// Внутренняя переменная var1932
#define var1079	BUFFER[14218]	// Внутренняя переменная var1079
#define idvar1079	30804	// Внутренняя переменная var1079
#define var1192	BUFFER[14220]	// Внутренняя переменная var1192
#define idvar1192	30805	// Внутренняя переменная var1192
#define var1235	BUFFER[14222]	// Внутренняя переменная var1235
#define idvar1235	30806	// Внутренняя переменная var1235
#define var1463	BUFFER[14224]	// Внутренняя переменная var1463
#define idvar1463	30807	// Внутренняя переменная var1463
#define var413	BUFFER[14226]	// Внутренняя переменная var413
#define idvar413	30808	// Внутренняя переменная var413
#define var503	BUFFER[14228]	// Внутренняя переменная var503
#define idvar503	30809	// Внутренняя переменная var503
#define var1379	BUFFER[14230]	// Внутренняя переменная var1379
#define idvar1379	30810	// Внутренняя переменная var1379
#define var1842	BUFFER[14232]	// Внутренняя переменная var1842
#define idvar1842	30811	// Внутренняя переменная var1842
#define var1281	BUFFER[14234]	// Внутренняя переменная var1281
#define idvar1281	30812	// Внутренняя переменная var1281
#define var1317	BUFFER[14236]	// Внутренняя переменная var1317
#define idvar1317	30813	// Внутренняя переменная var1317
#define var602	BUFFER[14238]	// Внутренняя переменная var602
#define idvar602	30814	// Внутренняя переменная var602
#define var1444	BUFFER[14240]	// Внутренняя переменная var1444
#define idvar1444	30815	// Внутренняя переменная var1444
#define var317	BUFFER[14242]	// Внутренняя переменная var317
#define idvar317	30816	// Внутренняя переменная var317
#define var654	BUFFER[14244]	// Внутренняя переменная var654
#define idvar654	30817	// Внутренняя переменная var654
#define var37	BUFFER[14246]	// Внутренняя переменная var37
#define idvar37	30818	// Внутренняя переменная var37
#define var134	BUFFER[14248]	// Внутренняя переменная var134
#define idvar134	30819	// Внутренняя переменная var134
#define var1051	BUFFER[14250]	// Внутренняя переменная var1051
#define idvar1051	30820	// Внутренняя переменная var1051
#define var1139	BUFFER[14252]	// Внутренняя переменная var1139
#define idvar1139	30821	// Внутренняя переменная var1139
#define var1201	BUFFER[14254]	// Внутренняя переменная var1201
#define idvar1201	30822	// Внутренняя переменная var1201
#define var1460	BUFFER[14256]	// Внутренняя переменная var1460
#define idvar1460	30823	// Внутренняя переменная var1460
#define var1583	BUFFER[14258]	// Внутренняя переменная var1583
#define idvar1583	30824	// Внутренняя переменная var1583
#define var698	BUFFER[14263]	// Внутренняя переменная var698
#define idvar698	30825	// Внутренняя переменная var698
#define var1369	BUFFER[14265]	// Внутренняя переменная var1369
#define idvar1369	30826	// Внутренняя переменная var1369
#define var401	BUFFER[14270]	// Внутренняя переменная var401
#define idvar401	30827	// Внутренняя переменная var401
#define var1044	BUFFER[14272]	// Внутренняя переменная var1044
#define idvar1044	30828	// Внутренняя переменная var1044
#define var1060	BUFFER[14274]	// Внутренняя переменная var1060
#define idvar1060	30829	// Внутренняя переменная var1060
#define var1446	BUFFER[14276]	// Внутренняя переменная var1446
#define idvar1446	30830	// Внутренняя переменная var1446
#define var1653	BUFFER[14278]	// Внутренняя переменная var1653
#define idvar1653	30831	// Внутренняя переменная var1653
#define var1973	BUFFER[14280]	// Внутренняя переменная var1973
#define idvar1973	30832	// Внутренняя переменная var1973
#define var323	BUFFER[14282]	// Внутренняя переменная var323
#define idvar323	30833	// Внутренняя переменная var323
#define var351	BUFFER[14284]	// Внутренняя переменная var351
#define idvar351	30834	// Внутренняя переменная var351
#define var589	BUFFER[14286]	// Внутренняя переменная var589
#define idvar589	30835	// Внутренняя переменная var589
#define var612	BUFFER[14288]	// Внутренняя переменная var612
#define idvar612	30836	// Внутренняя переменная var612
#define var1122	BUFFER[14290]	// Внутренняя переменная var1122
#define idvar1122	30837	// Внутренняя переменная var1122
#define var667	BUFFER[14292]	// Внутренняя переменная var667
#define idvar667	30838	// Внутренняя переменная var667
#define var1048	BUFFER[14294]	// Внутренняя переменная var1048
#define idvar1048	30839	// Внутренняя переменная var1048
#define var1731	BUFFER[14296]	// Внутренняя переменная var1731
#define idvar1731	30840	// Внутренняя переменная var1731
#define var1952	BUFFER[14298]	// Внутренняя переменная var1952
#define idvar1952	30841	// Внутренняя переменная var1952
#define var46	BUFFER[14303]	// Внутренняя переменная var46
#define idvar46	30842	// Внутренняя переменная var46
#define var388	BUFFER[14305]	// Внутренняя переменная var388
#define idvar388	30843	// Внутренняя переменная var388
#define var731	BUFFER[14308]	// Внутренняя переменная var731
#define idvar731	30844	// Внутренняя переменная var731
#define var1215	BUFFER[14310]	// Внутренняя переменная var1215
#define idvar1215	30845	// Внутренняя переменная var1215
#define var1700	BUFFER[14315]	// Внутренняя переменная var1700
#define idvar1700	30846	// Внутренняя переменная var1700
#define var1944	BUFFER[14317]	// Внутренняя переменная var1944
#define idvar1944	30847	// Внутренняя переменная var1944
#define var325	BUFFER[14319]	// Внутренняя переменная var325
#define idvar325	30848	// Внутренняя переменная var325
#define var807	BUFFER[14321]	// Внутренняя переменная var807
#define idvar807	30849	// Внутренняя переменная var807
#define var1865	BUFFER[14323]	// Внутренняя переменная var1865
#define idvar1865	30850	// Внутренняя переменная var1865
#define var1870	BUFFER[14325]	// Внутренняя переменная var1870
#define idvar1870	30851	// Внутренняя переменная var1870
#define var505	BUFFER[14327]	// Внутренняя переменная var505
#define idvar505	30852	// Внутренняя переменная var505
#define var771	BUFFER[14329]	// Внутренняя переменная var771
#define idvar771	30853	// Внутренняя переменная var771
#define var1791	BUFFER[14331]	// Внутренняя переменная var1791
#define idvar1791	30854	// Внутренняя переменная var1791
#define var1906	BUFFER[14333]	// Внутренняя переменная var1906
#define idvar1906	30855	// Внутренняя переменная var1906
#define var198	BUFFER[14335]	// Внутренняя переменная var198
#define idvar198	30856	// Внутренняя переменная var198
#define var1786	BUFFER[14337]	// Внутренняя переменная var1786
#define idvar1786	30857	// Внутренняя переменная var1786
#define var474	BUFFER[14339]	// Внутренняя переменная var474
#define idvar474	30858	// Внутренняя переменная var474
#define var1686	BUFFER[14341]	// Внутренняя переменная var1686
#define idvar1686	30859	// Внутренняя переменная var1686
#define var408	BUFFER[14346]	// Внутренняя переменная var408
#define idvar408	30860	// Внутренняя переменная var408
#define var1021	BUFFER[14348]	// Внутренняя переменная var1021
#define idvar1021	30861	// Внутренняя переменная var1021
#define var1307	BUFFER[14350]	// Внутренняя переменная var1307
#define idvar1307	30862	// Внутренняя переменная var1307
#define var1427	BUFFER[14352]	// Внутренняя переменная var1427
#define idvar1427	30863	// Внутренняя переменная var1427
#define var1617	BUFFER[14354]	// Внутренняя переменная var1617
#define idvar1617	30864	// Внутренняя переменная var1617
#define var1807	BUFFER[14356]	// Внутренняя переменная var1807
#define idvar1807	30865	// Внутренняя переменная var1807
#define var1838	BUFFER[14358]	// Внутренняя переменная var1838
#define idvar1838	30866	// Внутренняя переменная var1838
#define var678	BUFFER[14360]	// Внутренняя переменная var678
#define idvar678	30867	// Внутренняя переменная var678
#define var739	BUFFER[14362]	// Внутренняя переменная var739
#define idvar739	30868	// Внутренняя переменная var739
#define var1003	BUFFER[14364]	// Внутренняя переменная var1003
#define idvar1003	30869	// Внутренняя переменная var1003
#define var1395	BUFFER[14366]	// Внутренняя переменная var1395
#define idvar1395	30870	// Внутренняя переменная var1395
#define var1711	BUFFER[14368]	// Внутренняя переменная var1711
#define idvar1711	30871	// Внутренняя переменная var1711
#define var1735	BUFFER[14370]	// Внутренняя переменная var1735
#define idvar1735	30872	// Внутренняя переменная var1735
#define var587	BUFFER[14372]	// Внутренняя переменная var587
#define idvar587	30873	// Внутренняя переменная var587
#define var855	BUFFER[14374]	// Внутренняя переменная var855
#define idvar855	30874	// Внутренняя переменная var855
#define var1130	BUFFER[14376]	// Внутренняя переменная var1130
#define idvar1130	30875	// Внутренняя переменная var1130
#define var1567	BUFFER[14378]	// Внутренняя переменная var1567
#define idvar1567	30876	// Внутренняя переменная var1567
#define var1815	BUFFER[14381]	// Внутренняя переменная var1815
#define idvar1815	30877	// Внутренняя переменная var1815
#define var1817	BUFFER[14383]	// Внутренняя переменная var1817
#define idvar1817	30878	// Внутренняя переменная var1817
#define var228	BUFFER[14385]	// Внутренняя переменная var228
#define idvar228	30879	// Внутренняя переменная var228
#define var823	BUFFER[14387]	// Внутренняя переменная var823
#define idvar823	30880	// Внутренняя переменная var823
#define var1374	BUFFER[14389]	// Внутренняя переменная var1374
#define idvar1374	30881	// Внутренняя переменная var1374
#define var225	BUFFER[14391]	// Внутренняя переменная var225
#define idvar225	30882	// Внутренняя переменная var225
#define var923	BUFFER[14393]	// Внутренняя переменная var923
#define idvar923	30883	// Внутренняя переменная var923
#define var927	BUFFER[14395]	// Внутренняя переменная var927
#define idvar927	30884	// Внутренняя переменная var927
#define var125	BUFFER[14397]	// Внутренняя переменная var125
#define idvar125	30885	// Внутренняя переменная var125
#define var224	BUFFER[14399]	// Внутренняя переменная var224
#define idvar224	30886	// Внутренняя переменная var224
#define var626	BUFFER[14401]	// Внутренняя переменная var626
#define idvar626	30887	// Внутренняя переменная var626
#define var1113	BUFFER[14403]	// Внутренняя переменная var1113
#define idvar1113	30888	// Внутренняя переменная var1113
#define var174	BUFFER[14405]	// Внутренняя переменная var174
#define idvar174	30889	// Внутренняя переменная var174
#define var1832	BUFFER[14407]	// Внутренняя переменная var1832
#define idvar1832	30890	// Внутренняя переменная var1832
#define var756	BUFFER[14409]	// Внутренняя переменная var756
#define idvar756	30891	// Внутренняя переменная var756
#define var1881	BUFFER[14411]	// Внутренняя переменная var1881
#define idvar1881	30892	// Внутренняя переменная var1881
#define var80	BUFFER[14413]	// Внутренняя переменная var80
#define idvar80	30893	// Внутренняя переменная var80
#define var753	BUFFER[14415]	// Внутренняя переменная var753
#define idvar753	30894	// Внутренняя переменная var753
#define var861	BUFFER[14417]	// Внутренняя переменная var861
#define idvar861	30895	// Внутренняя переменная var861
#define var1570	BUFFER[14419]	// Внутренняя переменная var1570
#define idvar1570	30896	// Внутренняя переменная var1570
#define var1596	BUFFER[14421]	// Внутренняя переменная var1596
#define idvar1596	30897	// Внутренняя переменная var1596
#define var1924	BUFFER[14424]	// Внутренняя переменная var1924
#define idvar1924	30898	// Внутренняя переменная var1924
#define var572	BUFFER[14426]	// Внутренняя переменная var572
#define idvar572	30899	// Внутренняя переменная var572
#define var971	BUFFER[14428]	// Внутренняя переменная var971
#define idvar971	30900	// Внутренняя переменная var971
#define var1138	BUFFER[14430]	// Внутренняя переменная var1138
#define idvar1138	30901	// Внутренняя переменная var1138
#define var1338	BUFFER[14432]	// Внутренняя переменная var1338
#define idvar1338	30902	// Внутренняя переменная var1338
#define var1392	BUFFER[14434]	// Внутренняя переменная var1392
#define idvar1392	30903	// Внутренняя переменная var1392
#define var1962	BUFFER[14436]	// Внутренняя переменная var1962
#define idvar1962	30904	// Внутренняя переменная var1962
#define var71	BUFFER[14438]	// Внутренняя переменная var71
#define idvar71	30905	// Внутренняя переменная var71
#define var314	BUFFER[14440]	// Внутренняя переменная var314
#define idvar314	30906	// Внутренняя переменная var314
#define var553	BUFFER[14442]	// Внутренняя переменная var553
#define idvar553	30907	// Внутренняя переменная var553
#define var890	BUFFER[14444]	// Внутренняя переменная var890
#define idvar890	30908	// Внутренняя переменная var890
#define var937	BUFFER[14446]	// Внутренняя переменная var937
#define idvar937	30909	// Внутренняя переменная var937
#define var1063	BUFFER[14448]	// Внутренняя переменная var1063
#define idvar1063	30910	// Внутренняя переменная var1063
#define var677	BUFFER[14450]	// Внутренняя переменная var677
#define idvar677	30911	// Внутренняя переменная var677
#define var1231	BUFFER[14452]	// Внутренняя переменная var1231
#define idvar1231	30912	// Внутренняя переменная var1231
#define var1482	BUFFER[14454]	// Внутренняя переменная var1482
#define idvar1482	30913	// Внутренняя переменная var1482
#define var1828	BUFFER[14456]	// Внутренняя переменная var1828
#define idvar1828	30914	// Внутренняя переменная var1828
#define var70	BUFFER[14459]	// Внутренняя переменная var70
#define idvar70	30915	// Внутренняя переменная var70
#define var491	BUFFER[14461]	// Внутренняя переменная var491
#define idvar491	30916	// Внутренняя переменная var491
#define var637	BUFFER[14463]	// Внутренняя переменная var637
#define idvar637	30917	// Внутренняя переменная var637
#define var658	BUFFER[14465]	// Внутренняя переменная var658
#define idvar658	30918	// Внутренняя переменная var658
#define var684	BUFFER[14467]	// Внутренняя переменная var684
#define idvar684	30919	// Внутренняя переменная var684
#define var1525	BUFFER[14469]	// Внутренняя переменная var1525
#define idvar1525	30920	// Внутренняя переменная var1525
#define var209	BUFFER[14471]	// Внутренняя переменная var209
#define idvar209	30921	// Внутренняя переменная var209
#define var331	BUFFER[14473]	// Внутренняя переменная var331
#define idvar331	30922	// Внутренняя переменная var331
#define var216	BUFFER[14475]	// Внутренняя переменная var216
#define idvar216	30923	// Внутренняя переменная var216
#define var363	BUFFER[14477]	// Внутренняя переменная var363
#define idvar363	30924	// Внутренняя переменная var363
#define var833	BUFFER[14479]	// Внутренняя переменная var833
#define idvar833	30925	// Внутренняя переменная var833
#define var907	BUFFER[14481]	// Внутренняя переменная var907
#define idvar907	30926	// Внутренняя переменная var907
#define var1383	BUFFER[14483]	// Внутренняя переменная var1383
#define idvar1383	30927	// Внутренняя переменная var1383
#define vainSLong	BUFFER[14485]	// Внутренняя переменная vainSLong
#define idvainSLong	30928	// Внутренняя переменная vainSLong
#define var124	BUFFER[14494]	// Внутренняя переменная var124
#define idvar124	30929	// Внутренняя переменная var124
#define var445	BUFFER[14496]	// Внутренняя переменная var445
#define idvar445	30930	// Внутренняя переменная var445
#define var509	BUFFER[14498]	// Внутренняя переменная var509
#define idvar509	30931	// Внутренняя переменная var509
#define var863	BUFFER[14500]	// Внутренняя переменная var863
#define idvar863	30932	// Внутренняя переменная var863
#define var1811	BUFFER[14502]	// Внутренняя переменная var1811
#define idvar1811	30933	// Внутренняя переменная var1811
#define var1986	BUFFER[14504]	// Внутренняя переменная var1986
#define idvar1986	30934	// Внутренняя переменная var1986
#define var29	BUFFER[14506]	// Внутренняя переменная var29
#define idvar29	30935	// Внутренняя переменная var29
#define var253	BUFFER[14508]	// Внутренняя переменная var253
#define idvar253	30936	// Внутренняя переменная var253
#define var452	BUFFER[14510]	// Внутренняя переменная var452
#define idvar452	30937	// Внутренняя переменная var452
#define var898	BUFFER[14512]	// Внутренняя переменная var898
#define idvar898	30938	// Внутренняя переменная var898
#define var1794	BUFFER[14514]	// Внутренняя переменная var1794
#define idvar1794	30939	// Внутренняя переменная var1794
#define var259	BUFFER[14516]	// Внутренняя переменная var259
#define idvar259	30940	// Внутренняя переменная var259
#define var568	BUFFER[14518]	// Внутренняя переменная var568
#define idvar568	30941	// Внутренняя переменная var568
#define var40	BUFFER[14520]	// Внутренняя переменная var40
#define idvar40	30942	// Внутренняя переменная var40
#define var111	BUFFER[14522]	// Внутренняя переменная var111
#define idvar111	30943	// Внутренняя переменная var111
#define var1412	BUFFER[14524]	// Внутренняя переменная var1412
#define idvar1412	30944	// Внутренняя переменная var1412
#define var1933	BUFFER[14526]	// Внутренняя переменная var1933
#define idvar1933	30945	// Внутренняя переменная var1933
#define var399	BUFFER[14528]	// Внутренняя переменная var399
#define idvar399	30946	// Внутренняя переменная var399
#define var1594	BUFFER[14530]	// Внутренняя переменная var1594
#define idvar1594	30947	// Внутренняя переменная var1594
#define var1685	BUFFER[14532]	// Внутренняя переменная var1685
#define idvar1685	30948	// Внутренняя переменная var1685
#define var24	BUFFER[14534]	// Внутренняя переменная var24
#define idvar24	30949	// Внутренняя переменная var24
#define var517	BUFFER[14536]	// Внутренняя переменная var517
#define idvar517	30950	// Внутренняя переменная var517
#define var549	BUFFER[14538]	// Внутренняя переменная var549
#define idvar549	30951	// Внутренняя переменная var549
#define var599	BUFFER[14540]	// Внутренняя переменная var599
#define idvar599	30952	// Внутренняя переменная var599
#define var1001	BUFFER[14542]	// Внутренняя переменная var1001
#define idvar1001	30953	// Внутренняя переменная var1001
#define var1355	BUFFER[14544]	// Внутренняя переменная var1355
#define idvar1355	30954	// Внутренняя переменная var1355
#define var617	BUFFER[14546]	// Внутренняя переменная var617
#define idvar617	30955	// Внутренняя переменная var617
#define var1178	BUFFER[14548]	// Внутренняя переменная var1178
#define idvar1178	30956	// Внутренняя переменная var1178
#define var1225	BUFFER[14550]	// Внутренняя переменная var1225
#define idvar1225	30957	// Внутренняя переменная var1225
#define var1283	BUFFER[14555]	// Внутренняя переменная var1283
#define idvar1283	30958	// Внутренняя переменная var1283
#define var1706	BUFFER[14557]	// Внутренняя переменная var1706
#define idvar1706	30959	// Внутренняя переменная var1706
#define var306	BUFFER[14559]	// Внутренняя переменная var306
#define idvar306	30960	// Внутренняя переменная var306
#define var455	BUFFER[14561]	// Внутренняя переменная var455
#define idvar455	30961	// Внутренняя переменная var455
#define var508	BUFFER[14563]	// Внутренняя переменная var508
#define idvar508	30962	// Внутренняя переменная var508
#define var642	BUFFER[14565]	// Внутренняя переменная var642
#define idvar642	30963	// Внутренняя переменная var642
#define var827	BUFFER[14567]	// Внутренняя переменная var827
#define idvar827	30964	// Внутренняя переменная var827
#define var1692	BUFFER[14569]	// Внутренняя переменная var1692
#define idvar1692	30965	// Внутренняя переменная var1692
#define var102	BUFFER[14571]	// Внутренняя переменная var102
#define idvar102	30966	// Внутренняя переменная var102
#define var1076	BUFFER[14573]	// Внутренняя переменная var1076
#define idvar1076	30967	// Внутренняя переменная var1076
#define var1100	BUFFER[14575]	// Внутренняя переменная var1100
#define idvar1100	30968	// Внутренняя переменная var1100
#define var1239	BUFFER[14577]	// Внутренняя переменная var1239
#define idvar1239	30969	// Внутренняя переменная var1239
#define var1295	BUFFER[14579]	// Внутренняя переменная var1295
#define idvar1295	30970	// Внутренняя переменная var1295
#define var1677	BUFFER[14588]	// Внутренняя переменная var1677
#define idvar1677	30971	// Внутренняя переменная var1677
#define var294	BUFFER[14590]	// Внутренняя переменная var294
#define idvar294	30972	// Внутренняя переменная var294
#define var472	BUFFER[14592]	// Внутренняя переменная var472
#define idvar472	30973	// Внутренняя переменная var472
#define var765	BUFFER[14594]	// Внутренняя переменная var765
#define idvar765	30974	// Внутренняя переменная var765
#define var1265	BUFFER[14596]	// Внутренняя переменная var1265
#define idvar1265	30975	// Внутренняя переменная var1265
#define var1399	BUFFER[14598]	// Внутренняя переменная var1399
#define idvar1399	30976	// Внутренняя переменная var1399
#define var59	BUFFER[14600]	// Внутренняя переменная var59
#define idvar59	30977	// Внутренняя переменная var59
#define var378	BUFFER[14602]	// Внутренняя переменная var378
#define idvar378	30978	// Внутренняя переменная var378
#define var789	BUFFER[14604]	// Внутренняя переменная var789
#define idvar789	30979	// Внутренняя переменная var789
#define var1169	BUFFER[14606]	// Внутренняя переменная var1169
#define idvar1169	30980	// Внутренняя переменная var1169
#define var1170	BUFFER[14608]	// Внутренняя переменная var1170
#define idvar1170	30981	// Внутренняя переменная var1170
#define var1211	BUFFER[14610]	// Внутренняя переменная var1211
#define idvar1211	30982	// Внутренняя переменная var1211
#define var490	BUFFER[14612]	// Внутренняя переменная var490
#define idvar490	30983	// Внутренняя переменная var490
#define var709	BUFFER[14614]	// Внутренняя переменная var709
#define idvar709	30984	// Внутренняя переменная var709
#define var402	BUFFER[14616]	// Внутренняя переменная var402
#define idvar402	30985	// Внутренняя переменная var402
#define var1117	BUFFER[14618]	// Внутренняя переменная var1117
#define idvar1117	30986	// Внутренняя переменная var1117
#define var1798	BUFFER[14620]	// Внутренняя переменная var1798
#define idvar1798	30987	// Внутренняя переменная var1798
#define var147	BUFFER[14622]	// Внутренняя переменная var147
#define idvar147	30988	// Внутренняя переменная var147
#define var194	BUFFER[14624]	// Внутренняя переменная var194
#define idvar194	30989	// Внутренняя переменная var194
#define var489	BUFFER[14626]	// Внутренняя переменная var489
#define idvar489	30990	// Внутренняя переменная var489
#define var957	BUFFER[14628]	// Внутренняя переменная var957
#define idvar957	30991	// Внутренняя переменная var957
#define var1430	BUFFER[14630]	// Внутренняя переменная var1430
#define idvar1430	30992	// Внутренняя переменная var1430
#define var1479	BUFFER[14632]	// Внутренняя переменная var1479
#define idvar1479	30993	// Внутренняя переменная var1479
#define var214	BUFFER[14634]	// Внутренняя переменная var214
#define idvar214	30994	// Внутренняя переменная var214
#define var267	BUFFER[14636]	// Внутренняя переменная var267
#define idvar267	30995	// Внутренняя переменная var267
#define var1452	BUFFER[14638]	// Внутренняя переменная var1452
#define idvar1452	30996	// Внутренняя переменная var1452
#define var573	BUFFER[14640]	// Внутренняя переменная var573
#define idvar573	30997	// Внутренняя переменная var573
#define var866	BUFFER[14645]	// Внутренняя переменная var866
#define idvar866	30998	// Внутренняя переменная var866
#define var1264	BUFFER[14647]	// Внутренняя переменная var1264
#define idvar1264	30999	// Внутренняя переменная var1264
#define var1361	BUFFER[14649]	// Внутренняя переменная var1361
#define idvar1361	31000	// Внутренняя переменная var1361
#define var75	BUFFER[14651]	// Внутренняя переменная var75
#define idvar75	31001	// Внутренняя переменная var75
#define var1004	BUFFER[14653]	// Внутренняя переменная var1004
#define idvar1004	31002	// Внутренняя переменная var1004
#define var1325	BUFFER[14655]	// Внутренняя переменная var1325
#define idvar1325	31003	// Внутренняя переменная var1325
#define var160	BUFFER[14657]	// Внутренняя переменная var160
#define idvar160	31004	// Внутренняя переменная var160
#define var426	BUFFER[14659]	// Внутренняя переменная var426
#define idvar426	31005	// Внутренняя переменная var426
#define var1053	BUFFER[14661]	// Внутренняя переменная var1053
#define idvar1053	31006	// Внутренняя переменная var1053
#define var1958	BUFFER[14663]	// Внутренняя переменная var1958
#define idvar1958	31007	// Внутренняя переменная var1958
#define var1114	BUFFER[14665]	// Внутренняя переменная var1114
#define idvar1114	31008	// Внутренняя переменная var1114
#define var1378	BUFFER[14667]	// Внутренняя переменная var1378
#define idvar1378	31009	// Внутренняя переменная var1378
#define var1598	BUFFER[14669]	// Внутренняя переменная var1598
#define idvar1598	31010	// Внутренняя переменная var1598
#define var1697	BUFFER[14674]	// Внутренняя переменная var1697
#define idvar1697	31011	// Внутренняя переменная var1697
#define var1946	BUFFER[14676]	// Внутренняя переменная var1946
#define idvar1946	31012	// Внутренняя переменная var1946
#define var808	BUFFER[14678]	// Внутренняя переменная var808
#define idvar808	31013	// Внутренняя переменная var808
#define var994	BUFFER[14680]	// Внутренняя переменная var994
#define idvar994	31014	// Внутренняя переменная var994
#define var1121	BUFFER[14682]	// Внутренняя переменная var1121
#define idvar1121	31015	// Внутренняя переменная var1121
#define var1367	BUFFER[14684]	// Внутренняя переменная var1367
#define idvar1367	31016	// Внутренняя переменная var1367
#define var21	BUFFER[14686]	// Внутренняя переменная var21
#define idvar21	31017	// Внутренняя переменная var21
#define var653	BUFFER[14688]	// Внутренняя переменная var653
#define idvar653	31018	// Внутренняя переменная var653
#define var148	BUFFER[14690]	// Внутренняя переменная var148
#define idvar148	31019	// Внутренняя переменная var148
#define var1802	BUFFER[14692]	// Внутренняя переменная var1802
#define idvar1802	31020	// Внутренняя переменная var1802
#define var458	BUFFER[14694]	// Внутренняя переменная var458
#define idvar458	31021	// Внутренняя переменная var458
#define var824	BUFFER[14696]	// Внутренняя переменная var824
#define idvar824	31022	// Внутренняя переменная var824
#define var1409	BUFFER[14698]	// Внутренняя переменная var1409
#define idvar1409	31023	// Внутренняя переменная var1409
#define var350	BUFFER[14700]	// Внутренняя переменная var350
#define idvar350	31024	// Внутренняя переменная var350
#define var564	BUFFER[14702]	// Внутренняя переменная var564
#define idvar564	31025	// Внутренняя переменная var564
#define var676	BUFFER[14704]	// Внутренняя переменная var676
#define idvar676	31026	// Внутренняя переменная var676
#define var1417	BUFFER[14706]	// Внутренняя переменная var1417
#define idvar1417	31027	// Внутренняя переменная var1417
#define var1560	BUFFER[14708]	// Внутренняя переменная var1560
#define idvar1560	31028	// Внутренняя переменная var1560
#define var1804	BUFFER[14710]	// Внутренняя переменная var1804
#define idvar1804	31029	// Внутренняя переменная var1804
#define var685	BUFFER[14712]	// Внутренняя переменная var685
#define idvar685	31030	// Внутренняя переменная var685
#define var1554	BUFFER[14714]	// Внутренняя переменная var1554
#define idvar1554	31031	// Внутренняя переменная var1554
#define var1565	BUFFER[14716]	// Внутренняя переменная var1565
#define idvar1565	31032	// Внутренняя переменная var1565
#define var925	BUFFER[14718]	// Внутренняя переменная var925
#define idvar925	31033	// Внутренняя переменная var925
#define var1098	BUFFER[14720]	// Внутренняя переменная var1098
#define idvar1098	31034	// Внутренняя переменная var1098
#define var1717	BUFFER[14722]	// Внутренняя переменная var1717
#define idvar1717	31035	// Внутренняя переменная var1717
#define var922	BUFFER[14724]	// Внутренняя переменная var922
#define idvar922	31036	// Внутренняя переменная var922
#define var1065	BUFFER[14726]	// Внутренняя переменная var1065
#define idvar1065	31037	// Внутренняя переменная var1065
#define var10	BUFFER[14728]	// Внутренняя переменная var10
#define idvar10	31038	// Внутренняя переменная var10
#define var26	BUFFER[14730]	// Внутренняя переменная var26
#define idvar26	31039	// Внутренняя переменная var26
#define var346	BUFFER[14732]	// Внутренняя переменная var346
#define idvar346	31040	// Внутренняя переменная var346
#define var361	BUFFER[14734]	// Внутренняя переменная var361
#define idvar361	31041	// Внутренняя переменная var361
#define var365	BUFFER[14736]	// Внутренняя переменная var365
#define idvar365	31042	// Внутренняя переменная var365
#define var567	BUFFER[14738]	// Внутренняя переменная var567
#define idvar567	31043	// Внутренняя переменная var567
#define var1456	BUFFER[14740]	// Внутренняя переменная var1456
#define idvar1456	31044	// Внутренняя переменная var1456
#define var1354	BUFFER[14742]	// Внутренняя переменная var1354
#define idvar1354	31045	// Внутренняя переменная var1354
#define var1484	BUFFER[14744]	// Внутренняя переменная var1484
#define idvar1484	31046	// Внутренняя переменная var1484
#define var1557	BUFFER[14746]	// Внутренняя переменная var1557
#define idvar1557	31047	// Внутренняя переменная var1557
#define var213	BUFFER[14748]	// Внутренняя переменная var213
#define idvar213	31048	// Внутренняя переменная var213
#define var511	BUFFER[14750]	// Внутренняя переменная var511
#define idvar511	31049	// Внутренняя переменная var511
#define var1266	BUFFER[14752]	// Внутренняя переменная var1266
#define idvar1266	31050	// Внутренняя переменная var1266
#define var1435	BUFFER[14754]	// Внутренняя переменная var1435
#define idvar1435	31051	// Внутренняя переменная var1435
#define var1486	BUFFER[14756]	// Внутренняя переменная var1486
#define idvar1486	31052	// Внутренняя переменная var1486
#define var1635	BUFFER[14758]	// Внутренняя переменная var1635
#define idvar1635	31053	// Внутренняя переменная var1635
#define var52	BUFFER[14760]	// Внутренняя переменная var52
#define idvar52	31054	// Внутренняя переменная var52
#define var221	BUFFER[14762]	// Внутренняя переменная var221
#define idvar221	31055	// Внутренняя переменная var221
#define var648	BUFFER[14764]	// Внутренняя переменная var648
#define idvar648	31056	// Внутренняя переменная var648
#define var1193	BUFFER[14766]	// Внутренняя переменная var1193
#define idvar1193	31057	// Внутренняя переменная var1193
#define var217	BUFFER[14768]	// Внутренняя переменная var217
#define idvar217	31058	// Внутренняя переменная var217
#define var1299	BUFFER[14770]	// Внутренняя переменная var1299
#define idvar1299	31059	// Внутренняя переменная var1299
#define var1312	BUFFER[14773]	// Внутренняя переменная var1312
#define idvar1312	31060	// Внутренняя переменная var1312
#define var1625	BUFFER[14775]	// Внутренняя переменная var1625
#define idvar1625	31061	// Внутренняя переменная var1625
#define var146	BUFFER[14777]	// Внутренняя переменная var146
#define idvar146	31062	// Внутренняя переменная var146
#define var512	BUFFER[14779]	// Внутренняя переменная var512
#define idvar512	31063	// Внутренняя переменная var512
#define var633	BUFFER[14781]	// Внутренняя переменная var633
#define idvar633	31064	// Внутренняя переменная var633
#define var875	BUFFER[14783]	// Внутренняя переменная var875
#define idvar875	31065	// Внутренняя переменная var875
#define var1494	BUFFER[14785]	// Внутренняя переменная var1494
#define idvar1494	31066	// Внутренняя переменная var1494
#define var1217	BUFFER[14787]	// Внутренняя переменная var1217
#define idvar1217	31067	// Внутренняя переменная var1217
#define var1763	BUFFER[14792]	// Внутренняя переменная var1763
#define idvar1763	31068	// Внутренняя переменная var1763
#define var1770	BUFFER[14797]	// Внутренняя переменная var1770
#define idvar1770	31069	// Внутренняя переменная var1770
#define var3	BUFFER[14799]	// Внутренняя переменная var3
#define idvar3	31070	// Внутренняя переменная var3
#define var252	BUFFER[14801]	// Внутренняя переменная var252
#define idvar252	31071	// Внутренняя переменная var252
#define var392	BUFFER[14803]	// Внутренняя переменная var392
#define idvar392	31072	// Внутренняя переменная var392
#define var831	BUFFER[14805]	// Внутренняя переменная var831
#define idvar831	31073	// Внутренняя переменная var831
#define var1467	BUFFER[14807]	// Внутренняя переменная var1467
#define idvar1467	31074	// Внутренняя переменная var1467
#define var1750	BUFFER[14809]	// Внутренняя переменная var1750
#define idvar1750	31075	// Внутренняя переменная var1750
#define var591	BUFFER[14811]	// Внутренняя переменная var591
#define idvar591	31076	// Внутренняя переменная var591
#define var767	BUFFER[14813]	// Внутренняя переменная var767
#define idvar767	31077	// Внутренняя переменная var767
#define var887	BUFFER[14815]	// Внутренняя переменная var887
#define idvar887	31078	// Внутренняя переменная var887
#define var1119	BUFFER[14817]	// Внутренняя переменная var1119
#define idvar1119	31079	// Внутренняя переменная var1119
#define var1190	BUFFER[14819]	// Внутренняя переменная var1190
#define idvar1190	31080	// Внутренняя переменная var1190
#define var1632	BUFFER[14821]	// Внутренняя переменная var1632
#define idvar1632	31081	// Внутренняя переменная var1632
#define var1661	BUFFER[14823]	// Внутренняя переменная var1661
#define idvar1661	31082	// Внутренняя переменная var1661
#define var1111	BUFFER[14825]	// Внутренняя переменная var1111
#define idvar1111	31083	// Внутренняя переменная var1111
#define var1159	BUFFER[14827]	// Внутренняя переменная var1159
#define idvar1159	31084	// Внутренняя переменная var1159
#define var1997	BUFFER[14829]	// Внутренняя переменная var1997
#define idvar1997	31085	// Внутренняя переменная var1997
#define var1531	BUFFER[14834]	// Внутренняя переменная var1531
#define idvar1531	31086	// Внутренняя переменная var1531
#define var1640	BUFFER[14836]	// Внутренняя переменная var1640
#define idvar1640	31087	// Внутренняя переменная var1640
#define var1719	BUFFER[14839]	// Внутренняя переменная var1719
#define idvar1719	31088	// Внутренняя переменная var1719
#define var664	BUFFER[14844]	// Внутренняя переменная var664
#define idvar664	31089	// Внутренняя переменная var664
#define var802	BUFFER[14846]	// Внутренняя переменная var802
#define idvar802	31090	// Внутренняя переменная var802
#define var934	BUFFER[14848]	// Внутренняя переменная var934
#define idvar934	31091	// Внутренняя переменная var934
#define var1273	BUFFER[14850]	// Внутренняя переменная var1273
#define idvar1273	31092	// Внутренняя переменная var1273
#define var1767	BUFFER[14852]	// Внутренняя переменная var1767
#define idvar1767	31093	// Внутренняя переменная var1767
#define var312	BUFFER[14854]	// Внутренняя переменная var312
#define idvar312	31094	// Внутренняя переменная var312
#define var699	BUFFER[14856]	// Внутренняя переменная var699
#define idvar699	31095	// Внутренняя переменная var699
#define var1165	BUFFER[14858]	// Внутренняя переменная var1165
#define idvar1165	31096	// Внутренняя переменная var1165
#define var1311	BUFFER[14860]	// Внутренняя переменная var1311
#define idvar1311	31097	// Внутренняя переменная var1311
#define var1582	BUFFER[14862]	// Внутренняя переменная var1582
#define idvar1582	31098	// Внутренняя переменная var1582
#define var1639	BUFFER[14864]	// Внутренняя переменная var1639
#define idvar1639	31099	// Внутренняя переменная var1639
#define var61	BUFFER[14869]	// Внутренняя переменная var61
#define idvar61	31100	// Внутренняя переменная var61
#define var1216	BUFFER[14871]	// Внутренняя переменная var1216
#define idvar1216	31101	// Внутренняя переменная var1216
#define var1223	BUFFER[14873]	// Внутренняя переменная var1223
#define idvar1223	31102	// Внутренняя переменная var1223
#define var998	BUFFER[14878]	// Внутренняя переменная var998
#define idvar998	31103	// Внутренняя переменная var998
#define var1181	BUFFER[14880]	// Внутренняя переменная var1181
#define idvar1181	31104	// Внутренняя переменная var1181
#define var1358	BUFFER[14882]	// Внутренняя переменная var1358
#define idvar1358	31105	// Внутренняя переменная var1358
#define var1451	BUFFER[14884]	// Внутренняя переменная var1451
#define idvar1451	31106	// Внутренняя переменная var1451
#define var1660	BUFFER[14886]	// Внутренняя переменная var1660
#define idvar1660	31107	// Внутренняя переменная var1660
#define var41	BUFFER[14888]	// Внутренняя переменная var41
#define idvar41	31108	// Внутренняя переменная var41
#define var623	BUFFER[14890]	// Внутренняя переменная var623
#define idvar623	31109	// Внутренняя переменная var623
#define var757	BUFFER[14892]	// Внутренняя переменная var757
#define idvar757	31110	// Внутренняя переменная var757
#define var1302	BUFFER[14894]	// Внутренняя переменная var1302
#define idvar1302	31111	// Внутренняя переменная var1302
#define var1979	BUFFER[14896]	// Внутренняя переменная var1979
#define idvar1979	31112	// Внутренняя переменная var1979
#define var72	BUFFER[14901]	// Внутренняя переменная var72
#define idvar72	31113	// Внутренняя переменная var72
#define var157	BUFFER[14903]	// Внутренняя переменная var157
#define idvar157	31114	// Внутренняя переменная var157
#define var256	BUFFER[14905]	// Внутренняя переменная var256
#define idvar256	31115	// Внутренняя переменная var256
#define var594	BUFFER[14907]	// Внутренняя переменная var594
#define idvar594	31116	// Внутренняя переменная var594
#define var1773	BUFFER[14909]	// Внутренняя переменная var1773
#define idvar1773	31117	// Внутренняя переменная var1773
#define var1947	BUFFER[14911]	// Внутренняя переменная var1947
#define idvar1947	31118	// Внутренняя переменная var1947
#define var1587	BUFFER[14913]	// Внутренняя переменная var1587
#define idvar1587	31119	// Внутренняя переменная var1587
#define var1036	BUFFER[14915]	// Внутренняя переменная var1036
#define idvar1036	31120	// Внутренняя переменная var1036
#define var1199	BUFFER[14917]	// Внутренняя переменная var1199
#define idvar1199	31121	// Внутренняя переменная var1199
#define var1669	BUFFER[14919]	// Внутренняя переменная var1669
#define idvar1669	31122	// Внутренняя переменная var1669
#define var1689	BUFFER[14921]	// Внутренняя переменная var1689
#define idvar1689	31123	// Внутренняя переменная var1689
#define var1788	BUFFER[14923]	// Внутренняя переменная var1788
#define idvar1788	31124	// Внутренняя переменная var1788
#define var166	BUFFER[14925]	// Внутренняя переменная var166
#define idvar166	31125	// Внутренняя переменная var166
#define var596	BUFFER[14927]	// Внутренняя переменная var596
#define idvar596	31126	// Внутренняя переменная var596
#define var619	BUFFER[14929]	// Внутренняя переменная var619
#define idvar619	31127	// Внутренняя переменная var619
#define var655	BUFFER[14931]	// Внутренняя переменная var655
#define idvar655	31128	// Внутренняя переменная var655
#define var1026	BUFFER[14933]	// Внутренняя переменная var1026
#define idvar1026	31129	// Внутренняя переменная var1026
#define var1272	BUFFER[14935]	// Внутренняя переменная var1272
#define idvar1272	31130	// Внутренняя переменная var1272
#define var330	BUFFER[14937]	// Внутренняя переменная var330
#define idvar330	31131	// Внутренняя переменная var330
#define var1498	BUFFER[14939]	// Внутренняя переменная var1498
#define idvar1498	31132	// Внутренняя переменная var1498
#define var1029	BUFFER[14941]	// Внутренняя переменная var1029
#define idvar1029	31133	// Внутренняя переменная var1029
#define var1795	BUFFER[14943]	// Внутренняя переменная var1795
#define idvar1795	31134	// Внутренняя переменная var1795
#define var201	BUFFER[14945]	// Внутренняя переменная var201
#define idvar201	31135	// Внутренняя переменная var201
#define var349	BUFFER[14947]	// Внутренняя переменная var349
#define idvar349	31136	// Внутренняя переменная var349
#define var393	BUFFER[14949]	// Внутренняя переменная var393
#define idvar393	31137	// Внутренняя переменная var393
#define var414	BUFFER[14951]	// Внутренняя переменная var414
#define idvar414	31138	// Внутренняя переменная var414
#define var742	BUFFER[14953]	// Внутренняя переменная var742
#define idvar742	31139	// Внутренняя переменная var742
#define var858	BUFFER[14955]	// Внутренняя переменная var858
#define idvar858	31140	// Внутренняя переменная var858
#define var1831	BUFFER[14957]	// Внутренняя переменная var1831
#define idvar1831	31141	// Внутренняя переменная var1831
#define var288	BUFFER[14959]	// Внутренняя переменная var288
#define idvar288	31142	// Внутренняя переменная var288
#define var1428	BUFFER[14961]	// Внутренняя переменная var1428
#define idvar1428	31143	// Внутренняя переменная var1428
#define var1796	BUFFER[14963]	// Внутренняя переменная var1796
#define idvar1796	31144	// Внутренняя переменная var1796
#define var269	BUFFER[14965]	// Внутренняя переменная var269
#define idvar269	31145	// Внутренняя переменная var269
#define var840	BUFFER[14967]	// Внутренняя переменная var840
#define idvar840	31146	// Внутренняя переменная var840
#define var1508	BUFFER[14969]	// Внутренняя переменная var1508
#define idvar1508	31147	// Внутренняя переменная var1508
#define var202	BUFFER[14978]	// Внутренняя переменная var202
#define idvar202	31148	// Внутренняя переменная var202
#define var803	BUFFER[14980]	// Внутренняя переменная var803
#define idvar803	31149	// Внутренняя переменная var803
#define var1257	BUFFER[14989]	// Внутренняя переменная var1257
#define idvar1257	31150	// Внутренняя переменная var1257
#define var1753	BUFFER[14991]	// Внутренняя переменная var1753
#define idvar1753	31151	// Внутренняя переменная var1753
#define var1913	BUFFER[14993]	// Внутренняя переменная var1913
#define idvar1913	31152	// Внутренняя переменная var1913
#define var133	BUFFER[14995]	// Внутренняя переменная var133
#define idvar133	31153	// Внутренняя переменная var133
#define var320	BUFFER[14997]	// Внутренняя переменная var320
#define idvar320	31154	// Внутренняя переменная var320
#define var979	BUFFER[14999]	// Внутренняя переменная var979
#define idvar979	31155	// Внутренняя переменная var979
#define var1363	BUFFER[15001]	// Внутренняя переменная var1363
#define idvar1363	31156	// Внутренняя переменная var1363
#define var1629	BUFFER[15003]	// Внутренняя переменная var1629
#define idvar1629	31157	// Внутренняя переменная var1629
#define var1873	BUFFER[15006]	// Внутренняя переменная var1873
#define idvar1873	31158	// Внутренняя переменная var1873
#define var1356	BUFFER[15008]	// Внутренняя переменная var1356
#define idvar1356	31159	// Внутренняя переменная var1356
#define var1129	BUFFER[15010]	// Внутренняя переменная var1129
#define idvar1129	31160	// Внутренняя переменная var1129
#define var1644	BUFFER[15012]	// Внутренняя переменная var1644
#define idvar1644	31161	// Внутренняя переменная var1644
#define var1971	BUFFER[15014]	// Внутренняя переменная var1971
#define idvar1971	31162	// Внутренняя переменная var1971
#define var338	BUFFER[15016]	// Внутренняя переменная var338
#define idvar338	31163	// Внутренняя переменная var338
#define var468	BUFFER[15018]	// Внутренняя переменная var468
#define idvar468	31164	// Внутренняя переменная var468
#define var582	BUFFER[15020]	// Внутренняя переменная var582
#define idvar582	31165	// Внутренняя переменная var582
#define var1566	BUFFER[15022]	// Внутренняя переменная var1566
#define idvar1566	31166	// Внутренняя переменная var1566
#define var1716	BUFFER[15025]	// Внутренняя переменная var1716
#define idvar1716	31167	// Внутренняя переменная var1716
#define var638	BUFFER[15028]	// Внутренняя переменная var638
#define idvar638	31168	// Внутренняя переменная var638
#define var1319	BUFFER[15030]	// Внутренняя переменная var1319
#define idvar1319	31169	// Внутренняя переменная var1319
#define var1878	BUFFER[15032]	// Внутренняя переменная var1878
#define idvar1878	31170	// Внутренняя переменная var1878
#define var176	BUFFER[15034]	// Внутренняя переменная var176
#define idvar176	31171	// Внутренняя переменная var176
#define var919	BUFFER[15036]	// Внутренняя переменная var919
#define idvar919	31172	// Внутренняя переменная var919
#define var1229	BUFFER[15038]	// Внутренняя переменная var1229
#define idvar1229	31173	// Внутренняя переменная var1229
#define var1263	BUFFER[15040]	// Внутренняя переменная var1263
#define idvar1263	31174	// Внутренняя переменная var1263
#define var1492	BUFFER[15042]	// Внутренняя переменная var1492
#define idvar1492	31175	// Внутренняя переменная var1492
#define var1580	BUFFER[15044]	// Внутренняя переменная var1580
#define idvar1580	31176	// Внутренняя переменная var1580
#define var1576	BUFFER[15046]	// Внутренняя переменная var1576
#define idvar1576	31177	// Внутренняя переменная var1576
#define var1830	BUFFER[15048]	// Внутренняя переменная var1830
#define idvar1830	31178	// Внутренняя переменная var1830
#define var1922	BUFFER[15050]	// Внутренняя переменная var1922
#define idvar1922	31179	// Внутренняя переменная var1922
#define var348	BUFFER[15052]	// Внутренняя переменная var348
#define idvar348	31180	// Внутренняя переменная var348
#define var1518	BUFFER[15054]	// Внутренняя переменная var1518
#define idvar1518	31181	// Внутренняя переменная var1518
#define var1874	BUFFER[15056]	// Внутренняя переменная var1874
#define idvar1874	31182	// Внутренняя переменная var1874
#define var1061	BUFFER[15058]	// Внутренняя переменная var1061
#define idvar1061	31183	// Внутренняя переменная var1061
#define var1373	BUFFER[15060]	// Внутренняя переменная var1373
#define idvar1373	31184	// Внутренняя переменная var1373
#define var1772	BUFFER[15062]	// Внутренняя переменная var1772
#define idvar1772	31185	// Внутренняя переменная var1772
#define var310	BUFFER[15064]	// Внутренняя переменная var310
#define idvar310	31186	// Внутренняя переменная var310
#define var836	BUFFER[15066]	// Внутренняя переменная var836
#define idvar836	31187	// Внутренняя переменная var836
#define var1390	BUFFER[15068]	// Внутренняя переменная var1390
#define idvar1390	31188	// Внутренняя переменная var1390
#define var418	BUFFER[15070]	// Внутренняя переменная var418
#define idvar418	31189	// Внутренняя переменная var418
#define var634	BUFFER[15072]	// Внутренняя переменная var634
#define idvar634	31190	// Внутренняя переменная var634
#define var1097	BUFFER[15074]	// Внутренняя переменная var1097
#define idvar1097	31191	// Внутренняя переменная var1097
#define var1318	BUFFER[15076]	// Внутренняя переменная var1318
#define idvar1318	31192	// Внутренняя переменная var1318
#define var1569	BUFFER[15078]	// Внутренняя переменная var1569
#define idvar1569	31193	// Внутренняя переменная var1569
#define var1824	BUFFER[15083]	// Внутренняя переменная var1824
#define idvar1824	31194	// Внутренняя переменная var1824
#define var888	BUFFER[15085]	// Внутренняя переменная var888
#define idvar888	31195	// Внутренняя переменная var888
#define var1011	BUFFER[15087]	// Внутренняя переменная var1011
#define idvar1011	31196	// Внутренняя переменная var1011
#define var1187	BUFFER[15089]	// Внутренняя переменная var1187
#define idvar1187	31197	// Внутренняя переменная var1187
#define var1348	BUFFER[15091]	// Внутренняя переменная var1348
#define idvar1348	31198	// Внутренняя переменная var1348
#define var1774	BUFFER[15093]	// Внутренняя переменная var1774
#define idvar1774	31199	// Внутренняя переменная var1774
#define var1224	BUFFER[15095]	// Внутренняя переменная var1224
#define idvar1224	31200	// Внутренняя переменная var1224
#define var318	BUFFER[15100]	// Внутренняя переменная var318
#define idvar318	31201	// Внутренняя переменная var318
#define var987	BUFFER[15102]	// Внутренняя переменная var987
#define idvar987	31202	// Внутренняя переменная var987
#define var1167	BUFFER[15104]	// Внутренняя переменная var1167
#define idvar1167	31203	// Внутренняя переменная var1167
#define var49	BUFFER[15106]	// Внутренняя переменная var49
#define idvar49	31204	// Внутренняя переменная var49
#define var416	BUFFER[15108]	// Внутренняя переменная var416
#define idvar416	31205	// Внутренняя переменная var416
#define var465	BUFFER[15110]	// Внутренняя переменная var465
#define idvar465	31206	// Внутренняя переменная var465
#define var563	BUFFER[15115]	// Внутренняя переменная var563
#define idvar563	31207	// Внутренняя переменная var563
#define var692	BUFFER[15117]	// Внутренняя переменная var692
#define idvar692	31208	// Внутренняя переменная var692
#define var867	BUFFER[15119]	// Внутренняя переменная var867
#define idvar867	31209	// Внутренняя переменная var867
#define var1835	BUFFER[15121]	// Внутренняя переменная var1835
#define idvar1835	31210	// Внутренняя переменная var1835
#define var4	BUFFER[15123]	// Внутренняя переменная var4
#define idvar4	31211	// Внутренняя переменная var4
#define var55	BUFFER[15125]	// Внутренняя переменная var55
#define idvar55	31212	// Внутренняя переменная var55
#define var769	BUFFER[15127]	// Внутренняя переменная var769
#define idvar769	31213	// Внутренняя переменная var769
#define var993	BUFFER[15129]	// Внутренняя переменная var993
#define idvar993	31214	// Внутренняя переменная var993
#define var50	BUFFER[15131]	// Внутренняя переменная var50
#define idvar50	31215	// Внутренняя переменная var50
#define var1591	BUFFER[15133]	// Внутренняя переменная var1591
#define idvar1591	31216	// Внутренняя переменная var1591
#define var1752	BUFFER[15135]	// Внутренняя переменная var1752
#define idvar1752	31217	// Внутренняя переменная var1752
#define var1940	BUFFER[15137]	// Внутренняя переменная var1940
#define idvar1940	31218	// Внутренняя переменная var1940
#define var1945	BUFFER[15139]	// Внутренняя переменная var1945
#define idvar1945	31219	// Внутренняя переменная var1945
#define var235	BUFFER[15141]	// Внутренняя переменная var235
#define idvar235	31220	// Внутренняя переменная var235
#define var248	BUFFER[15143]	// Внутренняя переменная var248
#define idvar248	31221	// Внутренняя переменная var248
#define var334	BUFFER[15145]	// Внутренняя переменная var334
#define idvar334	31222	// Внутренняя переменная var334
#define var988	BUFFER[15147]	// Внутренняя переменная var988
#define idvar988	31223	// Внутренняя переменная var988
#define var1806	BUFFER[15149]	// Внутренняя переменная var1806
#define idvar1806	31224	// Внутренняя переменная var1806
#define var1968	BUFFER[15151]	// Внутренняя переменная var1968
#define idvar1968	31225	// Внутренняя переменная var1968
#define var715	BUFFER[15153]	// Внутренняя переменная var715
#define idvar715	31226	// Внутренняя переменная var715
#define var951	BUFFER[15155]	// Внутренняя переменная var951
#define idvar951	31227	// Внутренняя переменная var951
#define var961	BUFFER[15157]	// Внутренняя переменная var961
#define idvar961	31228	// Внутренняя переменная var961
#define var1579	BUFFER[15159]	// Внутренняя переменная var1579
#define idvar1579	31229	// Внутренняя переменная var1579
#define var1678	BUFFER[15161]	// Внутренняя переменная var1678
#define idvar1678	31230	// Внутренняя переменная var1678
#define var434	BUFFER[15166]	// Внутренняя переменная var434
#define idvar434	31231	// Внутренняя переменная var434
#define var941	BUFFER[15168]	// Внутренняя переменная var941
#define idvar941	31232	// Внутренняя переменная var941
#define var1179	BUFFER[15170]	// Внутренняя переменная var1179
#define idvar1179	31233	// Внутренняя переменная var1179
#define var1134	BUFFER[15172]	// Внутренняя переменная var1134
#define idvar1134	31234	// Внутренняя переменная var1134
#define var15	BUFFER[15174]	// Внутренняя переменная var15
#define idvar15	31235	// Внутренняя переменная var15
#define var117	BUFFER[15176]	// Внутренняя переменная var117
#define idvar117	31236	// Внутренняя переменная var117
#define var321	BUFFER[15178]	// Внутренняя переменная var321
#define idvar321	31237	// Внутренняя переменная var321
#define var822	BUFFER[15180]	// Внутренняя переменная var822
#define idvar822	31238	// Внутренняя переменная var822
#define var1469	BUFFER[15182]	// Внутренняя переменная var1469
#define idvar1469	31239	// Внутренняя переменная var1469
#define var1981	BUFFER[15184]	// Внутренняя переменная var1981
#define idvar1981	31240	// Внутренняя переменная var1981
#define var264	BUFFER[15186]	// Внутренняя переменная var264
#define idvar264	31241	// Внутренняя переменная var264
#define var958	BUFFER[15188]	// Внутренняя переменная var958
#define idvar958	31242	// Внутренняя переменная var958
#define var1023	BUFFER[15190]	// Внутренняя переменная var1023
#define idvar1023	31243	// Внутренняя переменная var1023
#define var1949	BUFFER[15192]	// Внутренняя переменная var1949
#define idvar1949	31244	// Внутренняя переменная var1949
#define var1974	BUFFER[15194]	// Внутренняя переменная var1974
#define idvar1974	31245	// Внутренняя переменная var1974
#define var344	BUFFER[15196]	// Внутренняя переменная var344
#define idvar344	31246	// Внутренняя переменная var344
#define var383	BUFFER[15198]	// Внутренняя переменная var383
#define idvar383	31247	// Внутренняя переменная var383
#define var949	BUFFER[15200]	// Внутренняя переменная var949
#define idvar949	31248	// Внутренняя переменная var949
#define var1377	BUFFER[15202]	// Внутренняя переменная var1377
#define idvar1377	31249	// Внутренняя переменная var1377
#define var486	BUFFER[15204]	// Внутренняя переменная var486
#define idvar486	31250	// Внутренняя переменная var486
#define var989	BUFFER[15206]	// Внутренняя переменная var989
#define idvar989	31251	// Внутренняя переменная var989
#define var1059	BUFFER[15208]	// Внутренняя переменная var1059
#define idvar1059	31252	// Внутренняя переменная var1059
#define var1620	BUFFER[15210]	// Внутренняя переменная var1620
#define idvar1620	31253	// Внутренняя переменная var1620
#define var1680	BUFFER[15212]	// Внутренняя переменная var1680
#define idvar1680	31254	// Внутренняя переменная var1680
#define var1702	BUFFER[15214]	// Внутренняя переменная var1702
#define idvar1702	31255	// Внутренняя переменная var1702
#define var149	BUFFER[15216]	// Внутренняя переменная var149
#define idvar149	31256	// Внутренняя переменная var149
#define var333	BUFFER[15218]	// Внутренняя переменная var333
#define idvar333	31257	// Внутренняя переменная var333
#define var1293	BUFFER[15220]	// Внутренняя переменная var1293
#define idvar1293	31258	// Внутренняя переменная var1293
#define var1042	BUFFER[15222]	// Внутренняя переменная var1042
#define idvar1042	31259	// Внутренняя переменная var1042
#define var1054	BUFFER[15224]	// Внутренняя переменная var1054
#define idvar1054	31260	// Внутренняя переменная var1054
#define var1124	BUFFER[15226]	// Внутренняя переменная var1124
#define idvar1124	31261	// Внутренняя переменная var1124
#define var1150	BUFFER[15228]	// Внутренняя переменная var1150
#define idvar1150	31262	// Внутренняя переменная var1150
#define var1423	BUFFER[15230]	// Внутренняя переменная var1423
#define idvar1423	31263	// Внутренняя переменная var1423
#define var1732	BUFFER[15232]	// Внутренняя переменная var1732
#define idvar1732	31264	// Внутренняя переменная var1732
#define var497	BUFFER[15234]	// Внутренняя переменная var497
#define idvar497	31265	// Внутренняя переменная var497
#define var629	BUFFER[15236]	// Внутренняя переменная var629
#define idvar629	31266	// Внутренняя переменная var629
#define var1468	BUFFER[15238]	// Внутренняя переменная var1468
#define idvar1468	31267	// Внутренняя переменная var1468
#define var1516	BUFFER[15240]	// Внутренняя переменная var1516
#define idvar1516	31268	// Внутренняя переменная var1516
#define var524	BUFFER[15242]	// Внутренняя переменная var524
#define idvar524	31269	// Внутренняя переменная var524
#define var1301	BUFFER[15244]	// Внутренняя переменная var1301
#define idvar1301	31270	// Внутренняя переменная var1301
#define var1515	BUFFER[15246]	// Внутренняя переменная var1515
#define idvar1515	31271	// Внутренняя переменная var1515
#define var135	BUFFER[15251]	// Внутренняя переменная var135
#define idvar135	31272	// Внутренняя переменная var135
#define var763	BUFFER[15253]	// Внутренняя переменная var763
#define idvar763	31273	// Внутренняя переменная var763
#define var1511	BUFFER[15255]	// Внутренняя переменная var1511
#define idvar1511	31274	// Внутренняя переменная var1511
#define var1845	BUFFER[15258]	// Внутренняя переменная var1845
#define idvar1845	31275	// Внутренняя переменная var1845
#define var2002	BUFFER[15260]	// Внутренняя переменная var2002
#define idvar2002	31276	// Внутренняя переменная var2002
#define var657	BUFFER[15262]	// Внутренняя переменная var657
#define idvar657	31277	// Внутренняя переменная var657
#define var738	BUFFER[15264]	// Внутренняя переменная var738
#define idvar738	31278	// Внутренняя переменная var738
#define var859	BUFFER[15266]	// Внутренняя переменная var859
#define idvar859	31279	// Внутренняя переменная var859
#define var970	BUFFER[15268]	// Внутренняя переменная var970
#define idvar970	31280	// Внутренняя переменная var970
#define var1552	BUFFER[15270]	// Внутренняя переменная var1552
#define idvar1552	31281	// Внутренняя переменная var1552
#define var1037	BUFFER[15272]	// Внутренняя переменная var1037
#define idvar1037	31282	// Внутренняя переменная var1037
#define var1422	BUFFER[15274]	// Внутренняя переменная var1422
#define idvar1422	31283	// Внутренняя переменная var1422
#define var1855	BUFFER[15276]	// Внутренняя переменная var1855
#define idvar1855	31284	// Внутренняя переменная var1855
#define var1648	BUFFER[15279]	// Внутренняя переменная var1648
#define idvar1648	31285	// Внутренняя переменная var1648
#define var1688	BUFFER[15281]	// Внутренняя переменная var1688
#define idvar1688	31286	// Внутренняя переменная var1688
#define var170	BUFFER[15283]	// Внутренняя переменная var170
#define idvar170	31287	// Внутренняя переменная var170
#define var514	BUFFER[15285]	// Внутренняя переменная var514
#define idvar514	31288	// Внутренняя переменная var514
#define var901	BUFFER[15287]	// Внутренняя переменная var901
#define idvar901	31289	// Внутренняя переменная var901
#define var1177	BUFFER[15289]	// Внутренняя переменная var1177
#define idvar1177	31290	// Внутренняя переменная var1177
#define var1327	BUFFER[15291]	// Внутренняя переменная var1327
#define idvar1327	31291	// Внутренняя переменная var1327
#define var1401	BUFFER[15293]	// Внутренняя переменная var1401
#define idvar1401	31292	// Внутренняя переменная var1401
#define var1016	BUFFER[15295]	// Внутренняя переменная var1016
#define idvar1016	31293	// Внутренняя переменная var1016
#define var905	BUFFER[15297]	// Внутренняя переменная var905
#define idvar905	31294	// Внутренняя переменная var905
#define var1528	BUFFER[15299]	// Внутренняя переменная var1528
#define idvar1528	31295	// Внутренняя переменная var1528
#define var1561	BUFFER[15301]	// Внутренняя переменная var1561
#define idvar1561	31296	// Внутренняя переменная var1561
#define var1851	BUFFER[15303]	// Внутренняя переменная var1851
#define idvar1851	31297	// Внутренняя переменная var1851
#define var473	BUFFER[15305]	// Внутренняя переменная var473
#define idvar473	31298	// Внутренняя переменная var473
#define var496	BUFFER[15307]	// Внутренняя переменная var496
#define idvar496	31299	// Внутренняя переменная var496
#define var557	BUFFER[15309]	// Внутренняя переменная var557
#define idvar557	31300	// Внутренняя переменная var557
#define var819	BUFFER[15314]	// Внутренняя переменная var819
#define idvar819	31301	// Внутренняя переменная var819
#define var986	BUFFER[15316]	// Внутренняя переменная var986
#define idvar986	31302	// Внутренняя переменная var986
#define var1323	BUFFER[15318]	// Внутренняя переменная var1323
#define idvar1323	31303	// Внутренняя переменная var1323
#define var1513	BUFFER[15320]	// Внутренняя переменная var1513
#define idvar1513	31304	// Внутренняя переменная var1513
#define var246	BUFFER[15325]	// Внутренняя переменная var246
#define idvar246	31305	// Внутренняя переменная var246
#define var560	BUFFER[15327]	// Внутренняя переменная var560
#define idvar560	31306	// Внутренняя переменная var560
#define var1542	BUFFER[15329]	// Внутренняя переменная var1542
#define idvar1542	31307	// Внутренняя переменная var1542
#define vainSBool	BUFFER[15331]	// Внутренняя переменная vainSBool
#define idvainSBool	31308	// Внутренняя переменная vainSBool
#define var377	BUFFER[15333]	// Внутренняя переменная var377
#define idvar377	31309	// Внутренняя переменная var377
#define var1671	BUFFER[15335]	// Внутренняя переменная var1671
#define idvar1671	31310	// Внутренняя переменная var1671
#define var652	BUFFER[15337]	// Внутренняя переменная var652
#define idvar652	31311	// Внутренняя переменная var652
#define var1246	BUFFER[15339]	// Внутренняя переменная var1246
#define idvar1246	31312	// Внутренняя переменная var1246
#define var301	BUFFER[15341]	// Внутренняя переменная var301
#define idvar301	31313	// Внутренняя переменная var301
#define var370	BUFFER[15343]	// Внутренняя переменная var370
#define idvar370	31314	// Внутренняя переменная var370
#define var1243	BUFFER[15345]	// Внутренняя переменная var1243
#define idvar1243	31315	// Внутренняя переменная var1243
#define var1249	BUFFER[15347]	// Внутренняя переменная var1249
#define idvar1249	31316	// Внутренняя переменная var1249
#define var1290	BUFFER[15349]	// Внутренняя переменная var1290
#define idvar1290	31317	// Внутренняя переменная var1290
#define var1360	BUFFER[15351]	// Внутренняя переменная var1360
#define idvar1360	31318	// Внутренняя переменная var1360
#define var270	BUFFER[15353]	// Внутренняя переменная var270
#define idvar270	31319	// Внутренняя переменная var270
#define var470	BUFFER[15355]	// Внутренняя переменная var470
#define idvar470	31320	// Внутренняя переменная var470
#define var1611	BUFFER[15357]	// Внутренняя переменная var1611
#define idvar1611	31321	// Внутренняя переменная var1611
#define var712	BUFFER[15359]	// Внутренняя переменная var712
#define idvar712	31322	// Внутренняя переменная var712
#define var707	BUFFER[15361]	// Внутренняя переменная var707
#define idvar707	31323	// Внутренняя переменная var707
#define var716	BUFFER[15363]	// Внутренняя переменная var716
#define idvar716	31324	// Внутренняя переменная var716
#define var818	BUFFER[15365]	// Внутренняя переменная var818
#define idvar818	31325	// Внутренняя переменная var818
#define var926	BUFFER[15367]	// Внутренняя переменная var926
#define idvar926	31326	// Внутренняя переменная var926
#define var1909	BUFFER[15369]	// Внутренняя переменная var1909
#define idvar1909	31327	// Внутренняя переменная var1909
#define var1018	BUFFER[15371]	// Внутренняя переменная var1018
#define idvar1018	31328	// Внутренняя переменная var1018
#define var18	BUFFER[15373]	// Внутренняя переменная var18
#define idvar18	31329	// Внутренняя переменная var18
#define var359	BUFFER[15375]	// Внутренняя переменная var359
#define idvar359	31330	// Внутренняя переменная var359
#define var1045	BUFFER[15377]	// Внутренняя переменная var1045
#define idvar1045	31331	// Внутренняя переменная var1045
#define var1397	BUFFER[15379]	// Внутренняя переменная var1397
#define idvar1397	31332	// Внутренняя переменная var1397
#define var1857	BUFFER[15381]	// Внутренняя переменная var1857
#define idvar1857	31333	// Внутренняя переменная var1857
#define var112	BUFFER[15383]	// Внутренняя переменная var112
#define idvar112	31334	// Внутренняя переменная var112
#define var1052	BUFFER[15385]	// Внутренняя переменная var1052
#define idvar1052	31335	// Внутренняя переменная var1052
#define var1141	BUFFER[15387]	// Внутренняя переменная var1141
#define idvar1141	31336	// Внутренняя переменная var1141
#define var1303	BUFFER[15389]	// Внутренняя переменная var1303
#define idvar1303	31337	// Внутренняя переменная var1303
#define var1573	BUFFER[15391]	// Внутренняя переменная var1573
#define idvar1573	31338	// Внутренняя переменная var1573
#define var1096	BUFFER[15393]	// Внутренняя переменная var1096
#define idvar1096	31339	// Внутренняя переменная var1096
#define var1411	BUFFER[15395]	// Внутренняя переменная var1411
#define idvar1411	31340	// Внутренняя переменная var1411
#define var1551	BUFFER[15397]	// Внутренняя переменная var1551
#define idvar1551	31341	// Внутренняя переменная var1551
#define var1684	BUFFER[15402]	// Внутренняя переменная var1684
#define idvar1684	31342	// Внутренняя переменная var1684
#define var1075	BUFFER[15404]	// Внутренняя переменная var1075
#define idvar1075	31343	// Внутренняя переменная var1075
#define var1258	BUFFER[15406]	// Внутренняя переменная var1258
#define idvar1258	31344	// Внутренняя переменная var1258
#define var1476	BUFFER[15408]	// Внутренняя переменная var1476
#define idvar1476	31345	// Внутренняя переменная var1476
#define var1517	BUFFER[15410]	// Внутренняя переменная var1517
#define idvar1517	31346	// Внутренняя переменная var1517
#define var1607	BUFFER[15412]	// Внутренняя переменная var1607
#define idvar1607	31347	// Внутренняя переменная var1607
#define var1	BUFFER[15415]	// Внутренняя переменная var1
#define idvar1	31348	// Внутренняя переменная var1
#define var2	BUFFER[15417]	// Внутренняя переменная var2
#define idvar2	31349	// Внутренняя переменная var2
#define var279	BUFFER[15419]	// Внутренняя переменная var279
#define idvar279	31350	// Внутренняя переменная var279
#define var1610	BUFFER[15421]	// Внутренняя переменная var1610
#define idvar1610	31351	// Внутренняя переменная var1610
#define var1897	BUFFER[15423]	// Внутренняя переменная var1897
#define idvar1897	31352	// Внутренняя переменная var1897
#define var195	BUFFER[15425]	// Внутренняя переменная var195
#define idvar195	31353	// Внутренняя переменная var195
#define var616	BUFFER[15427]	// Внутренняя переменная var616
#define idvar616	31354	// Внутренняя переменная var616
#define var1593	BUFFER[15429]	// Внутренняя переменная var1593
#define idvar1593	31355	// Внутренняя переменная var1593
#define var1695	BUFFER[15432]	// Внутренняя переменная var1695
#define idvar1695	31356	// Внутренняя переменная var1695
#define var1950	BUFFER[15434]	// Внутренняя переменная var1950
#define idvar1950	31357	// Внутренняя переменная var1950
#define var1116	BUFFER[15436]	// Внутренняя переменная var1116
#define idvar1116	31358	// Внутренняя переменная var1116
#define var1152	BUFFER[15438]	// Внутренняя переменная var1152
#define idvar1152	31359	// Внутренняя переменная var1152
#define var1875	BUFFER[15440]	// Внутренняя переменная var1875
#define idvar1875	31360	// Внутренняя переменная var1875
#define var462	BUFFER[15442]	// Внутренняя переменная var462
#define idvar462	31361	// Внутренняя переменная var462
#define var588	BUFFER[15447]	// Внутренняя переменная var588
#define idvar588	31362	// Внутренняя переменная var588
#define var1465	BUFFER[15449]	// Внутренняя переменная var1465
#define idvar1465	31363	// Внутренняя переменная var1465
#define var1667	BUFFER[15451]	// Внутренняя переменная var1667
#define idvar1667	31364	// Внутренняя переменная var1667
#define var484	BUFFER[15453]	// Внутренняя переменная var484
#define idvar484	31365	// Внутренняя переменная var484
#define var1040	BUFFER[15455]	// Внутренняя переменная var1040
#define idvar1040	31366	// Внутренняя переменная var1040
#define var1115	BUFFER[15457]	// Внутренняя переменная var1115
#define idvar1115	31367	// Внутренняя переменная var1115
#define var1634	BUFFER[15459]	// Внутренняя переменная var1634
#define idvar1634	31368	// Внутренняя переменная var1634
#define var1694	BUFFER[15461]	// Внутренняя переменная var1694
#define idvar1694	31369	// Внутренняя переменная var1694
#define var1960	BUFFER[15463]	// Внутренняя переменная var1960
#define idvar1960	31370	// Внутренняя переменная var1960
#define var121	BUFFER[15465]	// Внутренняя переменная var121
#define idvar121	31371	// Внутренняя переменная var121
#define var542	BUFFER[15467]	// Внутренняя переменная var542
#define idvar542	31372	// Внутренняя переменная var542
#define var1350	BUFFER[15469]	// Внутренняя переменная var1350
#define idvar1350	31373	// Внутренняя переменная var1350
#define var188	BUFFER[15478]	// Внутренняя переменная var188
#define idvar188	31374	// Внутренняя переменная var188
#define var376	BUFFER[15480]	// Внутренняя переменная var376
#define idvar376	31375	// Внутренняя переменная var376
#define var734	BUFFER[15482]	// Внутренняя переменная var734
#define idvar734	31376	// Внутренняя переменная var734
#define var1703	BUFFER[15484]	// Внутренняя переменная var1703
#define idvar1703	31377	// Внутренняя переменная var1703
#define var1930	BUFFER[15486]	// Внутренняя переменная var1930
#define idvar1930	31378	// Внутренняя переменная var1930
#define var780	BUFFER[15488]	// Внутренняя переменная var780
#define idvar780	31379	// Внутренняя переменная var780
#define var1081	BUFFER[15490]	// Внутренняя переменная var1081
#define idvar1081	31380	// Внутренняя переменная var1081
#define var144	BUFFER[15492]	// Внутренняя переменная var144
#define idvar144	31381	// Внутренняя переменная var144
#define var618	BUFFER[15494]	// Внутренняя переменная var618
#define idvar618	31382	// Внутренняя переменная var618
#define var1758	BUFFER[15496]	// Внутренняя переменная var1758
#define idvar1758	31383	// Внутренняя переменная var1758
#define var353	BUFFER[15498]	// Внутренняя переменная var353
#define idvar353	31384	// Внутренняя переменная var353
#define var997	BUFFER[15500]	// Внутренняя переменная var997
#define idvar997	31385	// Внутренняя переменная var997
#define var1965	BUFFER[15502]	// Внутренняя переменная var1965
#define idvar1965	31386	// Внутренняя переменная var1965
#define var69	BUFFER[15504]	// Внутренняя переменная var69
#define idvar69	31387	// Внутренняя переменная var69
#define var81	BUFFER[15506]	// Внутренняя переменная var81
#define idvar81	31388	// Внутренняя переменная var81
#define var226	BUFFER[15508]	// Внутренняя переменная var226
#define idvar226	31389	// Внутренняя переменная var226
#define var528	BUFFER[15510]	// Внутренняя переменная var528
#define idvar528	31390	// Внутренняя переменная var528
#define var552	BUFFER[15512]	// Внутренняя переменная var552
#define idvar552	31391	// Внутренняя переменная var552
#define var1176	BUFFER[15514]	// Внутренняя переменная var1176
#define idvar1176	31392	// Внутренняя переменная var1176
#define var287	BUFFER[15516]	// Внутренняя переменная var287
#define idvar287	31393	// Внутренняя переменная var287
#define var915	BUFFER[15518]	// Внутренняя переменная var915
#define idvar915	31394	// Внутренняя переменная var915
#define var981	BUFFER[15520]	// Внутренняя переменная var981
#define idvar981	31395	// Внутренняя переменная var981
#define var1110	BUFFER[15522]	// Внутренняя переменная var1110
#define idvar1110	31396	// Внутренняя переменная var1110
#define var1860	BUFFER[15524]	// Внутренняя переменная var1860
#define idvar1860	31397	// Внутренняя переменная var1860
#define var92	BUFFER[15526]	// Внутренняя переменная var92
#define idvar92	31398	// Внутренняя переменная var92
#define var138	BUFFER[15528]	// Внутренняя переменная var138
#define idvar138	31399	// Внутренняя переменная var138
#define var1530	BUFFER[15530]	// Внутренняя переменная var1530
#define idvar1530	31400	// Внутренняя переменная var1530
#define var438	BUFFER[15532]	// Внутренняя переменная var438
#define idvar438	31401	// Внутренняя переменная var438
#define var645	BUFFER[15534]	// Внутренняя переменная var645
#define idvar645	31402	// Внутренняя переменная var645
#define var1718	BUFFER[15536]	// Внутренняя переменная var1718
#define idvar1718	31403	// Внутренняя переменная var1718
#define var1200	BUFFER[15538]	// Внутренняя переменная var1200
#define idvar1200	31404	// Внутренняя переменная var1200
#define var1990	BUFFER[15540]	// Внутренняя переменная var1990
#define idvar1990	31405	// Внутренняя переменная var1990
#define var85	BUFFER[15542]	// Внутренняя переменная var85
#define idvar85	31406	// Внутренняя переменная var85
#define var136	BUFFER[15544]	// Внутренняя переменная var136
#define idvar136	31407	// Внутренняя переменная var136
#define var196	BUFFER[15546]	// Внутренняя переменная var196
#define idvar196	31408	// Внутренняя переменная var196
#define var307	BUFFER[15548]	// Внутренняя переменная var307
#define idvar307	31409	// Внутренняя переменная var307
#define var405	BUFFER[15550]	// Внутренняя переменная var405
#define idvar405	31410	// Внутренняя переменная var405
#define var533	BUFFER[15552]	// Внутренняя переменная var533
#define idvar533	31411	// Внутренняя переменная var533
#define var460	BUFFER[15554]	// Внутренняя переменная var460
#define idvar460	31412	// Внутренняя переменная var460
#define var775	BUFFER[15559]	// Внутренняя переменная var775
#define idvar775	31413	// Внутренняя переменная var775
#define var1398	BUFFER[15561]	// Внутренняя переменная var1398
#define idvar1398	31414	// Внутренняя переменная var1398
#define var1549	BUFFER[15563]	// Внутренняя переменная var1549
#define idvar1549	31415	// Внутренняя переменная var1549
#define var1662	BUFFER[15565]	// Внутренняя переменная var1662
#define idvar1662	31416	// Внутренняя переменная var1662
#define var1309	BUFFER[15567]	// Внутренняя переменная var1309
#define idvar1309	31417	// Внутренняя переменная var1309
#define var1522	BUFFER[15570]	// Внутренняя переменная var1522
#define idvar1522	31418	// Внутренняя переменная var1522
#define var1744	BUFFER[15572]	// Внутренняя переменная var1744
#define idvar1744	31419	// Внутренняя переменная var1744
#define var476	BUFFER[15574]	// Внутренняя переменная var476
#define idvar476	31420	// Внутренняя переменная var476
#define var610	BUFFER[15576]	// Внутренняя переменная var610
#define idvar610	31421	// Внутренняя переменная var610
#define var978	BUFFER[15578]	// Внутренняя переменная var978
#define idvar978	31422	// Внутренняя переменная var978
#define var356	BUFFER[15580]	// Внутренняя переменная var356
#define idvar356	31423	// Внутренняя переменная var356
#define var580	BUFFER[15582]	// Внутренняя переменная var580
#define idvar580	31424	// Внутренняя переменная var580
#define var814	BUFFER[15584]	// Внутренняя переменная var814
#define idvar814	31425	// Внутренняя переменная var814
#define var1778	BUFFER[15586]	// Внутренняя переменная var1778
#define idvar1778	31426	// Внутренняя переменная var1778
#define var11	BUFFER[15588]	// Внутренняя переменная var11
#define idvar11	31427	// Внутренняя переменная var11
#define var518	BUFFER[15590]	// Внутренняя переменная var518
#define idvar518	31428	// Внутренняя переменная var518
#define var782	BUFFER[15592]	// Внутренняя переменная var782
#define idvar782	31429	// Внутренняя переменная var782
#define var959	BUFFER[15594]	// Внутренняя переменная var959
#define idvar959	31430	// Внутренняя переменная var959
#define var1043	BUFFER[15596]	// Внутренняя переменная var1043
#define idvar1043	31431	// Внутренняя переменная var1043
#define var1595	BUFFER[15598]	// Внутренняя переменная var1595
#define idvar1595	31432	// Внутренняя переменная var1595
#define var1883	BUFFER[15601]	// Внутренняя переменная var1883
#define idvar1883	31433	// Внутренняя переменная var1883
#define var386	BUFFER[15603]	// Внутренняя переменная var386
#define idvar386	31434	// Внутренняя переменная var386
#define var991	BUFFER[15605]	// Внутренняя переменная var991
#define idvar991	31435	// Внутренняя переменная var991
#define var1069	BUFFER[15607]	// Внутренняя переменная var1069
#define idvar1069	31436	// Внутренняя переменная var1069
#define var1194	BUFFER[15609]	// Внутренняя переменная var1194
#define idvar1194	31437	// Внутренняя переменная var1194
#define var1701	BUFFER[15611]	// Внутренняя переменная var1701
#define idvar1701	31438	// Внутренняя переменная var1701
#define var1880	BUFFER[15613]	// Внутренняя переменная var1880
#define idvar1880	31439	// Внутренняя переменная var1880
#define var1089	BUFFER[15615]	// Внутренняя переменная var1089
#define idvar1089	31440	// Внутренняя переменная var1089
#define var1472	BUFFER[15617]	// Внутренняя переменная var1472
#define idvar1472	31441	// Внутренняя переменная var1472
#define var1488	BUFFER[15619]	// Внутренняя переменная var1488
#define idvar1488	31442	// Внутренняя переменная var1488
#define var273	BUFFER[15621]	// Внутренняя переменная var273
#define idvar273	31443	// Внутренняя переменная var273
#define var896	BUFFER[15623]	// Внутренняя переменная var896
#define idvar896	31444	// Внутренняя переменная var896
#define var967	BUFFER[15625]	// Внутренняя переменная var967
#define idvar967	31445	// Внутренняя переменная var967
#define var1252	BUFFER[15627]	// Внутренняя переменная var1252
#define idvar1252	31446	// Внутренняя переменная var1252
#define var1825	BUFFER[15629]	// Внутренняя переменная var1825
#define idvar1825	31447	// Внутренняя переменная var1825
#define var1841	BUFFER[15631]	// Внутренняя переменная var1841
#define idvar1841	31448	// Внутренняя переменная var1841
#define var1943	BUFFER[15633]	// Внутренняя переменная var1943
#define idvar1943	31449	// Внутренняя переменная var1943
#define var131	BUFFER[15635]	// Внутренняя переменная var131
#define idvar131	31450	// Внутренняя переменная var131
#define var420	BUFFER[15637]	// Внутренняя переменная var420
#define idvar420	31451	// Внутренняя переменная var420
#define var448	BUFFER[15639]	// Внутренняя переменная var448
#define idvar448	31452	// Внутренняя переменная var448
#define var482	BUFFER[15641]	// Внутренняя переменная var482
#define idvar482	31453	// Внутренняя переменная var482
#define var525	BUFFER[15643]	// Внутренняя переменная var525
#define idvar525	31454	// Внутренняя переменная var525
#define var697	BUFFER[15645]	// Внутренняя переменная var697
#define idvar697	31455	// Внутренняя переменная var697
#define var444	BUFFER[15647]	// Внутренняя переменная var444
#define idvar444	31456	// Внутренняя переменная var444
#define var885	BUFFER[15649]	// Внутренняя переменная var885
#define idvar885	31457	// Внутренняя переменная var885
#define var522	BUFFER[15651]	// Внутренняя переменная var522
#define idvar522	31458	// Внутренняя переменная var522
#define var622	BUFFER[15653]	// Внутренняя переменная var622
#define idvar622	31459	// Внутренняя переменная var622
#define var857	BUFFER[15655]	// Внутренняя переменная var857
#define idvar857	31460	// Внутренняя переменная var857
#define var893	BUFFER[15657]	// Внутренняя переменная var893
#define idvar893	31461	// Внутренняя переменная var893
#define var1268	BUFFER[15659]	// Внутренняя переменная var1268
#define idvar1268	31462	// Внутренняя переменная var1268
#define var1544	BUFFER[15661]	// Внутренняя переменная var1544
#define idvar1544	31463	// Внутренняя переменная var1544
#define var1407	BUFFER[15663]	// Внутренняя переменная var1407
#define idvar1407	31464	// Внутренняя переменная var1407
#define var1421	BUFFER[15665]	// Внутренняя переменная var1421
#define idvar1421	31465	// Внутренняя переменная var1421
#define var1645	BUFFER[15667]	// Внутренняя переменная var1645
#define idvar1645	31466	// Внутренняя переменная var1645
#define var1709	BUFFER[15669]	// Внутренняя переменная var1709
#define idvar1709	31467	// Внутренняя переменная var1709
#define var223	BUFFER[15672]	// Внутренняя переменная var223
#define idvar223	31468	// Внутренняя переменная var223
#define var1371	BUFFER[15674]	// Внутренняя переменная var1371
#define idvar1371	31469	// Внутренняя переменная var1371
#define var1433	BUFFER[15676]	// Внутренняя переменная var1433
#define idvar1433	31470	// Внутренняя переменная var1433
#define var1631	BUFFER[15678]	// Внутренняя переменная var1631
#define idvar1631	31471	// Внутренняя переменная var1631
#define var1916	BUFFER[15683]	// Внутренняя переменная var1916
#define idvar1916	31472	// Внутренняя переменная var1916
#define var78	BUFFER[15688]	// Внутренняя переменная var78
#define idvar78	31473	// Внутренняя переменная var78
#define var487	BUFFER[15690]	// Внутренняя переменная var487
#define idvar487	31474	// Внутренняя переменная var487
#define var630	BUFFER[15692]	// Внутренняя переменная var630
#define idvar630	31475	// Внутренняя переменная var630
#define var1673	BUFFER[15694]	// Внутренняя переменная var1673
#define idvar1673	31476	// Внутренняя переменная var1673
#define var1771	BUFFER[15697]	// Внутренняя переменная var1771
#define idvar1771	31477	// Внутренняя переменная var1771
#define var656	BUFFER[15699]	// Внутренняя переменная var656
#define idvar656	31478	// Внутренняя переменная var656
#define var748	BUFFER[15701]	// Внутренняя переменная var748
#define idvar748	31479	// Внутренняя переменная var748
#define var1105	BUFFER[15703]	// Внутренняя переменная var1105
#define idvar1105	31480	// Внутренняя переменная var1105
#define var1903	BUFFER[15705]	// Внутренняя переменная var1903
#define idvar1903	31481	// Внутренняя переменная var1903
#define var956	BUFFER[15707]	// Внутренняя переменная var956
#define idvar956	31482	// Внутренняя переменная var956
#define var297	BUFFER[15709]	// Внутренняя переменная var297
#define idvar297	31483	// Внутренняя переменная var297
#define var309	BUFFER[15711]	// Внутренняя переменная var309
#define idvar309	31484	// Внутренняя переменная var309
#define var1321	BUFFER[15713]	// Внутренняя переменная var1321
#define idvar1321	31485	// Внутренняя переменная var1321
#define var1483	BUFFER[15715]	// Внутренняя переменная var1483
#define idvar1483	31486	// Внутренняя переменная var1483
#define var2000	BUFFER[15717]	// Внутренняя переменная var2000
#define idvar2000	31487	// Внутренняя переменная var2000
#define var1912	BUFFER[15719]	// Внутренняя переменная var1912
#define idvar1912	31488	// Внутренняя переменная var1912
#define var1959	BUFFER[15721]	// Внутренняя переменная var1959
#define idvar1959	31489	// Внутренняя переменная var1959
#define var169	BUFFER[15723]	// Внутренняя переменная var169
#define idvar169	31490	// Внутренняя переменная var169
#define var292	BUFFER[15725]	// Внутренняя переменная var292
#define idvar292	31491	// Внутренняя переменная var292
#define var506	BUFFER[15727]	// Внутренняя переменная var506
#define idvar506	31492	// Внутренняя переменная var506
#define var607	BUFFER[15729]	// Внутренняя переменная var607
#define idvar607	31493	// Внутренняя переменная var607
#define var884	BUFFER[15731]	// Внутренняя переменная var884
#define idvar884	31494	// Внутренняя переменная var884
#define var1158	BUFFER[15733]	// Внутренняя переменная var1158
#define idvar1158	31495	// Внутренняя переменная var1158
#define var773	BUFFER[15735]	// Внутренняя переменная var773
#define idvar773	31496	// Внутренняя переменная var773
#define var1271	BUFFER[15737]	// Внутренняя переменная var1271
#define idvar1271	31497	// Внутренняя переменная var1271
#define var1487	BUFFER[15739]	// Внутренняя переменная var1487
#define idvar1487	31498	// Внутренняя переменная var1487
#define var1514	BUFFER[15741]	// Внутренняя переменная var1514
#define idvar1514	31499	// Внутренняя переменная var1514
#define var250	BUFFER[15746]	// Внутренняя переменная var250
#define idvar250	31500	// Внутренняя переменная var250
#define var261	BUFFER[15748]	// Внутренняя переменная var261
#define idvar261	31501	// Внутренняя переменная var261
#define var87	BUFFER[15750]	// Внутренняя переменная var87
#define idvar87	31502	// Внутренняя переменная var87
#define var215	BUFFER[15752]	// Внутренняя переменная var215
#define idvar215	31503	// Внутренняя переменная var215
#define var1292	BUFFER[15754]	// Внутренняя переменная var1292
#define idvar1292	31504	// Внутренняя переменная var1292
#define var943	BUFFER[15756]	// Внутренняя переменная var943
#define idvar943	31505	// Внутренняя переменная var943
#define var1869	BUFFER[15758]	// Внутренняя переменная var1869
#define idvar1869	31506	// Внутренняя переменная var1869
#define var278	BUFFER[15760]	// Внутренняя переменная var278
#define idvar278	31507	// Внутренняя переменная var278
#define var1082	BUFFER[15762]	// Внутренняя переменная var1082
#define idvar1082	31508	// Внутренняя переменная var1082
#define var1650	BUFFER[15764]	// Внутренняя переменная var1650
#define idvar1650	31509	// Внутренняя переменная var1650
#define var1659	BUFFER[15766]	// Внутренняя переменная var1659
#define idvar1659	31510	// Внутренняя переменная var1659
#define var319	BUFFER[15768]	// Внутренняя переменная var319
#define idvar319	31511	// Внутренняя переменная var319
#define var471	BUFFER[15770]	// Внутренняя переменная var471
#define idvar471	31512	// Внутренняя переменная var471
#define var641	BUFFER[15772]	// Внутренняя переменная var641
#define idvar641	31513	// Внутренняя переменная var641
#define var1512	BUFFER[15774]	// Внутренняя переменная var1512
#define idvar1512	31514	// Внутренняя переменная var1512
#define var1776	BUFFER[15776]	// Внутренняя переменная var1776
#define idvar1776	31515	// Внутренняя переменная var1776
#define var813	BUFFER[15778]	// Внутренняя переменная var813
#define idvar813	31516	// Внутренняя переменная var813
#define var830	BUFFER[15780]	// Внутренняя переменная var830
#define idvar830	31517	// Внутренняя переменная var830
#define var480	BUFFER[15782]	// Внутренняя переменная var480
#define idvar480	31518	// Внутренняя переменная var480
#define var650	BUFFER[15784]	// Внутренняя переменная var650
#define idvar650	31519	// Внутренняя переменная var650
#define var752	BUFFER[15786]	// Внутренняя переменная var752
#define idvar752	31520	// Внутренняя переменная var752
#define var1279	BUFFER[15788]	// Внутренняя переменная var1279
#define idvar1279	31521	// Внутренняя переменная var1279
#define var1000	BUFFER[15790]	// Внутренняя переменная var1000
#define idvar1000	31522	// Внутренняя переменная var1000
#define var1589	BUFFER[15792]	// Внутренняя переменная var1589
#define idvar1589	31523	// Внутренняя переменная var1589
#define var1548	BUFFER[15794]	// Внутренняя переменная var1548
#define idvar1548	31524	// Внутренняя переменная var1548
#define var8	BUFFER[15796]	// Внутренняя переменная var8
#define idvar8	31525	// Внутренняя переменная var8
#define var206	BUFFER[15798]	// Внутренняя переменная var206
#define idvar206	31526	// Внутренняя переменная var206
#define var437	BUFFER[15800]	// Внутренняя переменная var437
#define idvar437	31527	// Внутренняя переменная var437
#define var1416	BUFFER[15802]	// Внутренняя переменная var1416
#define idvar1416	31528	// Внутренняя переменная var1416
#define var151	BUFFER[15804]	// Внутренняя переменная var151
#define idvar151	31529	// Внутренняя переменная var151
#define var1058	BUFFER[15806]	// Внутренняя переменная var1058
#define idvar1058	31530	// Внутренняя переменная var1058
#define var1090	BUFFER[15808]	// Внутренняя переменная var1090
#define idvar1090	31531	// Внутренняя переменная var1090
#define var1250	BUFFER[15810]	// Внутренняя переменная var1250
#define idvar1250	31532	// Внутренняя переменная var1250
#define var1289	BUFFER[15812]	// Внутренняя переменная var1289
#define idvar1289	31533	// Внутренняя переменная var1289
#define var218	BUFFER[15814]	// Внутренняя переменная var218
#define idvar218	31534	// Внутренняя переменная var218
#define var659	BUFFER[15816]	// Внутренняя переменная var659
#define idvar659	31535	// Внутренняя переменная var659
#define var772	BUFFER[15821]	// Внутренняя переменная var772
#define idvar772	31536	// Внутренняя переменная var772
#define var1034	BUFFER[15823]	// Внутренняя переменная var1034
#define idvar1034	31537	// Внутренняя переменная var1034
#define var91	BUFFER[15825]	// Внутренняя переменная var91
#define idvar91	31538	// Внутренняя переменная var91
#define var980	BUFFER[15827]	// Внутренняя переменная var980
#define idvar980	31539	// Внутренняя переменная var980
#define var1064	BUFFER[15829]	// Внутренняя переменная var1064
#define idvar1064	31540	// Внутренняя переменная var1064
#define var1206	BUFFER[15831]	// Внутренняя переменная var1206
#define idvar1206	31541	// Внутренняя переменная var1206
#define var1972	BUFFER[15833]	// Внутренняя переменная var1972
#define idvar1972	31542	// Внутренняя переменная var1972
#define var1834	BUFFER[15835]	// Внутренняя переменная var1834
#define idvar1834	31543	// Внутренняя переменная var1834
#define var27	BUFFER[15837]	// Внутренняя переменная var27
#define idvar27	31544	// Внутренняя переменная var27
#define var34	BUFFER[15839]	// Внутренняя переменная var34
#define idvar34	31545	// Внутренняя переменная var34
#define var122	BUFFER[15841]	// Внутренняя переменная var122
#define idvar122	31546	// Внутренняя переменная var122
#define var1112	BUFFER[15843]	// Внутренняя переменная var1112
#define idvar1112	31547	// Внутренняя переменная var1112
#define var1534	BUFFER[15845]	// Внутренняя переменная var1534
#define idvar1534	31548	// Внутренняя переменная var1534
#define var1581	BUFFER[15848]	// Внутренняя переменная var1581
#define idvar1581	31549	// Внутренняя переменная var1581
#define var1564	BUFFER[15850]	// Внутренняя переменная var1564
#define idvar1564	31550	// Внутренняя переменная var1564
#define var1844	BUFFER[15853]	// Внутренняя переменная var1844
#define idvar1844	31551	// Внутренняя переменная var1844
#define var234	BUFFER[15855]	// Внутренняя переменная var234
#define idvar234	31552	// Внутренняя переменная var234
#define var424	BUFFER[15857]	// Внутренняя переменная var424
#define idvar424	31553	// Внутренняя переменная var424
#define var529	BUFFER[15859]	// Внутренняя переменная var529
#define idvar529	31554	// Внутренняя переменная var529
#define var778	BUFFER[15861]	// Внутренняя переменная var778
#define idvar778	31555	// Внутренняя переменная var778
#define var1185	BUFFER[15863]	// Внутренняя переменная var1185
#define idvar1185	31556	// Внутренняя переменная var1185
#define var1403	BUFFER[15865]	// Внутренняя переменная var1403
#define idvar1403	31557	// Внутренняя переменная var1403
#define var1102	BUFFER[15867]	// Внутренняя переменная var1102
#define idvar1102	31558	// Внутренняя переменная var1102
#define var1532	BUFFER[15869]	// Внутренняя переменная var1532
#define idvar1532	31559	// Внутренняя переменная var1532
#define var1622	BUFFER[15872]	// Внутренняя переменная var1622
#define idvar1622	31560	// Внутренняя переменная var1622
#define var1879	BUFFER[15874]	// Внутренняя переменная var1879
#define idvar1879	31561	// Внутренняя переменная var1879
#define var812	BUFFER[15876]	// Внутренняя переменная var812
#define idvar812	31562	// Внутренняя переменная var812
#define var900	BUFFER[15878]	// Внутренняя переменная var900
#define idvar900	31563	// Внутренняя переменная var900
#define var1244	BUFFER[15880]	// Внутренняя переменная var1244
#define idvar1244	31564	// Внутренняя переменная var1244
#define var740	BUFFER[15882]	// Внутренняя переменная var740
#define idvar740	31565	// Внутренняя переменная var740
#define var976	BUFFER[15884]	// Внутренняя переменная var976
#define idvar976	31566	// Внутренняя переменная var976
#define var2004	BUFFER[15886]	// Внутренняя переменная var2004
#define idvar2004	31567	// Внутренняя переменная var2004
#define var175	BUFFER[15888]	// Внутренняя переменная var175
#define idvar175	31568	// Внутренняя переменная var175
#define var200	BUFFER[15890]	// Внутренняя переменная var200
#define idvar200	31569	// Внутренняя переменная var200
#define var722	BUFFER[15892]	// Внутренняя переменная var722
#define idvar722	31570	// Внутренняя переменная var722
#define var1429	BUFFER[15894]	// Внутренняя переменная var1429
#define idvar1429	31571	// Внутренняя переменная var1429
#define var313	BUFFER[15896]	// Внутренняя переменная var313
#define idvar313	31572	// Внутренняя переменная var313
#define var713	BUFFER[15898]	// Внутренняя переменная var713
#define idvar713	31573	// Внутренняя переменная var713
#define var995	BUFFER[15900]	// Внутренняя переменная var995
#define idvar995	31574	// Внутренняя переменная var995
#define var1568	BUFFER[15902]	// Внутренняя переменная var1568
#define idvar1568	31575	// Внутренняя переменная var1568
#define var1859	BUFFER[15904]	// Внутренняя переменная var1859
#define idvar1859	31576	// Внутренняя переменная var1859
#define var23	BUFFER[15906]	// Внутренняя переменная var23
#define idvar23	31577	// Внутренняя переменная var23
#define var966	BUFFER[15908]	// Внутренняя переменная var966
#define idvar966	31578	// Внутренняя переменная var966
#define var1535	BUFFER[15910]	// Внутренняя переменная var1535
#define idvar1535	31579	// Внутренняя переменная var1535
#define var869	BUFFER[15913]	// Внутренняя переменная var869
#define idvar869	31580	// Внутренняя переменная var869
#define var1453	BUFFER[15915]	// Внутренняя переменная var1453
#define idvar1453	31581	// Внутренняя переменная var1453
#define var1967	BUFFER[15917]	// Внутренняя переменная var1967
#define idvar1967	31582	// Внутренняя переменная var1967
#define var1592	BUFFER[15919]	// Внутренняя переменная var1592
#define idvar1592	31583	// Внутренняя переменная var1592
#define var1260	BUFFER[15921]	// Внутренняя переменная var1260
#define idvar1260	31584	// Внутренняя переменная var1260
#define var1262	BUFFER[15923]	// Внутренняя переменная var1262
#define idvar1262	31585	// Внутренняя переменная var1262
#define var1387	BUFFER[15925]	// Внутренняя переменная var1387
#define idvar1387	31586	// Внутренняя переменная var1387
#define var1955	BUFFER[15927]	// Внутренняя переменная var1955
#define idvar1955	31587	// Внутренняя переменная var1955
#define var345	BUFFER[15929]	// Внутренняя переменная var345
#define idvar345	31588	// Внутренняя переменная var345
#define var603	BUFFER[15931]	// Внутренняя переменная var603
#define idvar603	31589	// Внутренняя переменная var603
#define var635	BUFFER[15933]	// Внутренняя переменная var635
#define idvar635	31590	// Внутренняя переменная var635
#define var1666	BUFFER[15935]	// Внутренняя переменная var1666
#define idvar1666	31591	// Внутренняя переменная var1666
#define var1675	BUFFER[15937]	// Внутренняя переменная var1675
#define idvar1675	31592	// Внутренняя переменная var1675
#define var990	BUFFER[15940]	// Внутренняя переменная var990
#define idvar990	31593	// Внутренняя переменная var990
#define var1162	BUFFER[15942]	// Внутренняя переменная var1162
#define idvar1162	31594	// Внутренняя переменная var1162
#define var39	BUFFER[15944]	// Внутренняя переменная var39
#define idvar39	31595	// Внутренняя переменная var39
#define var165	BUFFER[15946]	// Внутренняя переменная var165
#define idvar165	31596	// Внутренняя переменная var165
#define var291	BUFFER[15948]	// Внутренняя переменная var291
#define idvar291	31597	// Внутренняя переменная var291
#define var352	BUFFER[15950]	// Внутренняя переменная var352
#define idvar352	31598	// Внутренняя переменная var352
#define var694	BUFFER[15952]	// Внутренняя переменная var694
#define idvar694	31599	// Внутренняя переменная var694
#define var984	BUFFER[15954]	// Внутренняя переменная var984
#define idvar984	31600	// Внутренняя переменная var984
#define var1372	BUFFER[15956]	// Внутренняя переменная var1372
#define idvar1372	31601	// Внутренняя переменная var1372
#define var1665	BUFFER[15958]	// Внутренняя переменная var1665
#define idvar1665	31602	// Внутренняя переменная var1665
#define var89	BUFFER[15961]	// Внутренняя переменная var89
#define idvar89	31603	// Внутренняя переменная var89
#define var515	BUFFER[15963]	// Внутренняя переменная var515
#define idvar515	31604	// Внутренняя переменная var515
#define var621	BUFFER[15965]	// Внутренняя переменная var621
#define idvar621	31605	// Внутренняя переменная var621
#define var849	BUFFER[15967]	// Внутренняя переменная var849
#define idvar849	31606	// Внутренняя переменная var849
#define var929	BUFFER[15969]	// Внутренняя переменная var929
#define idvar929	31607	// Внутренняя переменная var929
#define var1921	BUFFER[15971]	// Внутренняя переменная var1921
#define idvar1921	31608	// Внутренняя переменная var1921
#define var737	BUFFER[15973]	// Внутренняя переменная var737
#define idvar737	31609	// Внутренняя переменная var737
#define var1728	BUFFER[15975]	// Внутренняя переменная var1728
#define idvar1728	31610	// Внутренняя переменная var1728
#define var1840	BUFFER[15978]	// Внутренняя переменная var1840
#define idvar1840	31611	// Внутренняя переменная var1840
#define var93	BUFFER[15980]	// Внутренняя переменная var93
#define idvar93	31612	// Внутренняя переменная var93
#define var186	BUFFER[15982]	// Внутренняя переменная var186
#define idvar186	31613	// Внутренняя переменная var186
#define var535	BUFFER[15984]	// Внутренняя переменная var535
#define idvar535	31614	// Внутренняя переменная var535
#define var708	BUFFER[15986]	// Внутренняя переменная var708
#define idvar708	31615	// Внутренняя переменная var708
#define var973	BUFFER[15988]	// Внутренняя переменная var973
#define idvar973	31616	// Внутренняя переменная var973
#define var1342	BUFFER[15990]	// Внутренняя переменная var1342
#define idvar1342	31617	// Внутренняя переменная var1342
#define var54	BUFFER[15992]	// Внутренняя переменная var54
#define idvar54	31618	// Внутренняя переменная var54
#define var796	BUFFER[15994]	// Внутренняя переменная var796
#define idvar796	31619	// Внутренняя переменная var796
#define var1382	BUFFER[15996]	// Внутренняя переменная var1382
#define idvar1382	31620	// Внутренняя переменная var1382
#define var407	BUFFER[15998]	// Внутренняя переменная var407
#define idvar407	31621	// Внутренняя переменная var407
#define var425	BUFFER[16000]	// Внутренняя переменная var425
#define idvar425	31622	// Внутренняя переменная var425
#define var1071	BUFFER[16002]	// Внутренняя переменная var1071
#define idvar1071	31623	// Внутренняя переменная var1071
#define var328	BUFFER[16004]	// Внутренняя переменная var328
#define idvar328	31624	// Внутренняя переменная var328
#define var864	BUFFER[16006]	// Внутренняя переменная var864
#define idvar864	31625	// Внутренняя переменная var864
#define var1253	BUFFER[16008]	// Внутренняя переменная var1253
#define idvar1253	31626	// Внутренняя переменная var1253
#define var1674	BUFFER[16010]	// Внутренняя переменная var1674
#define idvar1674	31627	// Внутренняя переменная var1674
#define var421	BUFFER[16012]	// Внутренняя переменная var421
#define idvar421	31628	// Внутренняя переменная var421
#define var952	BUFFER[16014]	// Внутренняя переменная var952
#define idvar952	31629	// Внутренняя переменная var952
#define var1232	BUFFER[16016]	// Внутренняя переменная var1232
#define idvar1232	31630	// Внутренняя переменная var1232
#define var1837	BUFFER[16018]	// Внутренняя переменная var1837
#define idvar1837	31631	// Внутренняя переменная var1837
#define var1852	BUFFER[16021]	// Внутренняя переменная var1852
#define idvar1852	31632	// Внутренняя переменная var1852
#define var192	BUFFER[16023]	// Внутренняя переменная var192
#define idvar192	31633	// Внутренняя переменная var192
#define var1035	BUFFER[16025]	// Внутренняя переменная var1035
#define idvar1035	31634	// Внутренняя переменная var1035
#define var1585	BUFFER[16027]	// Внутренняя переменная var1585
#define idvar1585	31635	// Внутренняя переменная var1585
#define var374	BUFFER[16029]	// Внутренняя переменная var374
#define idvar374	31636	// Внутренняя переменная var374
#define var428	BUFFER[16031]	// Внутренняя переменная var428
#define idvar428	31637	// Внутренняя переменная var428
#define var1812	BUFFER[16033]	// Внутренняя переменная var1812
#define idvar1812	31638	// Внутренняя переменная var1812
#define var1447	BUFFER[16035]	// Внутренняя переменная var1447
#define idvar1447	31639	// Внутренняя переменная var1447
#define var2003	BUFFER[16037]	// Внутренняя переменная var2003
#define idvar2003	31640	// Внутренняя переменная var2003
#define var62	BUFFER[16039]	// Внутренняя переменная var62
#define idvar62	31641	// Внутренняя переменная var62
#define var181	BUFFER[16041]	// Внутренняя переменная var181
#define idvar181	31642	// Внутренняя переменная var181
#define var1708	BUFFER[16043]	// Внутренняя переменная var1708
#define idvar1708	31643	// Внутренняя переменная var1708
#define var56	BUFFER[16045]	// Внутренняя переменная var56
#define idvar56	31644	// Внутренняя переменная var56
#define var768	BUFFER[16047]	// Внутренняя переменная var768
#define idvar768	31645	// Внутренняя переменная var768
#define var811	BUFFER[16049]	// Внутренняя переменная var811
#define idvar811	31646	// Внутренняя переменная var811
#define var1385	BUFFER[16051]	// Внутренняя переменная var1385
#define idvar1385	31647	// Внутренняя переменная var1385
#define var1388	BUFFER[16053]	// Внутренняя переменная var1388
#define idvar1388	31648	// Внутренняя переменная var1388
#define var280	BUFFER[16055]	// Внутренняя переменная var280
#define idvar280	31649	// Внутренняя переменная var280
#define var282	BUFFER[16057]	// Внутренняя переменная var282
#define idvar282	31650	// Внутренняя переменная var282
#define var728	BUFFER[16059]	// Внутренняя переменная var728
#define idvar728	31651	// Внутренняя переменная var728
#define var800	BUFFER[16061]	// Внутренняя переменная var800
#define idvar800	31652	// Внутренняя переменная var800
#define var1527	BUFFER[16063]	// Внутренняя переменная var1527
#define idvar1527	31653	// Внутренняя переменная var1527
#define var1633	BUFFER[16065]	// Внутренняя переменная var1633
#define idvar1633	31654	// Внутренняя переменная var1633
#define var286	BUFFER[16067]	// Внутренняя переменная var286
#define idvar286	31655	// Внутренняя переменная var286
#define var446	BUFFER[16069]	// Внутренняя переменная var446
#define idvar446	31656	// Внутренняя переменная var446
#define var605	BUFFER[16071]	// Внутренняя переменная var605
#define idvar605	31657	// Внутренняя переменная var605
#define var1118	BUFFER[16073]	// Внутренняя переменная var1118
#define idvar1118	31658	// Внутренняя переменная var1118
#define var1777	BUFFER[16075]	// Внутренняя переменная var1777
#define idvar1777	31659	// Внутренняя переменная var1777
#define var1934	BUFFER[16077]	// Внутренняя переменная var1934
#define idvar1934	31660	// Внутренняя переменная var1934
#define var464	BUFFER[16079]	// Внутренняя переменная var464
#define idvar464	31661	// Внутренняя переменная var464
#define var853	BUFFER[16084]	// Внутренняя переменная var853
#define idvar853	31662	// Внутренняя переменная var853
#define var860	BUFFER[16086]	// Внутренняя переменная var860
#define idvar860	31663	// Внутренняя переменная var860
#define var1341	BUFFER[16088]	// Внутренняя переменная var1341
#define idvar1341	31664	// Внутренняя переменная var1341
#define var1820	BUFFER[16090]	// Внутренняя переменная var1820
#define idvar1820	31665	// Внутренняя переменная var1820
#define var1915	BUFFER[16092]	// Внутренняя переменная var1915
#define idvar1915	31666	// Внутренняя переменная var1915
#define var719	BUFFER[16094]	// Внутренняя переменная var719
#define idvar719	31667	// Внутренняя переменная var719
#define var1441	BUFFER[16096]	// Внутренняя переменная var1441
#define idvar1441	31668	// Внутренняя переменная var1441
#define var1442	BUFFER[16098]	// Внутренняя переменная var1442
#define idvar1442	31669	// Внутренняя переменная var1442
#define var94	BUFFER[16100]	// Внутренняя переменная var94
#define idvar94	31670	// Внутренняя переменная var94
#define var245	BUFFER[16102]	// Внутренняя переменная var245
#define idvar245	31671	// Внутренняя переменная var245
#define var1041	BUFFER[16104]	// Внутренняя переменная var1041
#define idvar1041	31672	// Внутренняя переменная var1041
#define var1174	BUFFER[16106]	// Внутренняя переменная var1174
#define idvar1174	31673	// Внутренняя переменная var1174
#define var1712	BUFFER[16108]	// Внутренняя переменная var1712
#define idvar1712	31674	// Внутренняя переменная var1712
#define var327	BUFFER[16111]	// Внутренняя переменная var327
#define idvar327	31675	// Внутренняя переменная var327
#define var1746	BUFFER[16113]	// Внутренняя переменная var1746
#define idvar1746	31676	// Внутренняя переменная var1746
#define var60	BUFFER[16118]	// Внутренняя переменная var60
#define idvar60	31677	// Внутренняя переменная var60
#define var1146	BUFFER[16120]	// Внутренняя переменная var1146
#define idvar1146	31678	// Внутренняя переменная var1146
#define var1458	BUFFER[16122]	// Внутренняя переменная var1458
#define idvar1458	31679	// Внутренняя переменная var1458
#define var1691	BUFFER[16124]	// Внутренняя переменная var1691
#define idvar1691	31680	// Внутренняя переменная var1691
#define var1764	BUFFER[16126]	// Внутренняя переменная var1764
#define idvar1764	31681	// Внутренняя переменная var1764
#define var65	BUFFER[16128]	// Внутренняя переменная var65
#define idvar65	31682	// Внутренняя переменная var65
#define var453	BUFFER[16130]	// Внутренняя переменная var453
#define idvar453	31683	// Внутренняя переменная var453
#define var816	BUFFER[16132]	// Внутренняя переменная var816
#define idvar816	31684	// Внутренняя переменная var816
#define var1230	BUFFER[16134]	// Внутренняя переменная var1230
#define idvar1230	31685	// Внутренняя переменная var1230
#define var1464	BUFFER[16136]	// Внутренняя переменная var1464
#define idvar1464	31686	// Внутренняя переменная var1464
#define var1605	BUFFER[16138]	// Внутренняя переменная var1605
#define idvar1605	31687	// Внутренняя переменная var1605
#define var461	BUFFER[16140]	// Внутренняя переменная var461
#define idvar461	31688	// Внутренняя переменная var461
#define var561	BUFFER[16145]	// Внутренняя переменная var561
#define idvar561	31689	// Внутренняя переменная var561
#define var1413	BUFFER[16150]	// Внутренняя переменная var1413
#define idvar1413	31690	// Внутренняя переменная var1413
#define var1651	BUFFER[16152]	// Внутренняя переменная var1651
#define idvar1651	31691	// Внутренняя переменная var1651
#define var537	BUFFER[16154]	// Внутренняя переменная var537
#define idvar537	31692	// Внутренняя переменная var537
#define var894	BUFFER[16156]	// Внутренняя переменная var894
#define idvar894	31693	// Внутренняя переменная var894
#define var1070	BUFFER[16158]	// Внутренняя переменная var1070
#define idvar1070	31694	// Внутренняя переменная var1070
#define var1083	BUFFER[16160]	// Внутренняя переменная var1083
#define idvar1083	31695	// Внутренняя переменная var1083
#define var1248	BUFFER[16162]	// Внутренняя переменная var1248
#define idvar1248	31696	// Внутренняя переменная var1248
#define var1310	BUFFER[16164]	// Внутренняя переменная var1310
#define idvar1310	31697	// Внутренняя переменная var1310
#define var1714	BUFFER[16167]	// Внутренняя переменная var1714
#define idvar1714	31698	// Внутренняя переменная var1714
#define var955	BUFFER[16170]	// Внутренняя переменная var955
#define idvar955	31699	// Внутренняя переменная var955
#define var1256	BUFFER[16172]	// Внутренняя переменная var1256
#define idvar1256	31700	// Внутренняя переменная var1256
#define var1490	BUFFER[16174]	// Внутренняя переменная var1490
#define idvar1490	31701	// Внутренняя переменная var1490
#define var1655	BUFFER[16176]	// Внутренняя переменная var1655
#define idvar1655	31702	// Внутренняя переменная var1655
#define var1730	BUFFER[16178]	// Внутренняя переменная var1730
#define idvar1730	31703	// Внутренняя переменная var1730
#define var546	BUFFER[16180]	// Внутренняя переменная var546
#define idvar546	31704	// Внутренняя переменная var546
#define var1606	BUFFER[16182]	// Внутренняя переменная var1606
#define idvar1606	31705	// Внутренняя переменная var1606
#define var1641	BUFFER[16187]	// Внутренняя переменная var1641
#define idvar1641	31706	// Внутренняя переменная var1641
#define var1013	BUFFER[16189]	// Внутренняя переменная var1013
#define idvar1013	31707	// Внутренняя переменная var1013
#define var495	BUFFER[16191]	// Внутренняя переменная var495
#define idvar495	31708	// Внутренняя переменная var495
#define var1963	BUFFER[16193]	// Внутренняя переменная var1963
#define idvar1963	31709	// Внутренняя переменная var1963
#define var390	BUFFER[16195]	// Внутренняя переменная var390
#define idvar390	31710	// Внутренняя переменная var390
#define var1189	BUFFER[16197]	// Внутренняя переменная var1189
#define idvar1189	31711	// Внутренняя переменная var1189
#define var1775	BUFFER[16199]	// Внутренняя переменная var1775
#define idvar1775	31712	// Внутренняя переменная var1775
#define var562	BUFFER[16201]	// Внутренняя переменная var562
#define idvar562	31713	// Внутренняя переменная var562
#define var663	BUFFER[16203]	// Внутренняя переменная var663
#define idvar663	31714	// Внутренняя переменная var663
#define var673	BUFFER[16208]	// Внутренняя переменная var673
#define idvar673	31715	// Внутренняя переменная var673
#define var950	BUFFER[16213]	// Внутренняя переменная var950
#define idvar950	31716	// Внутренняя переменная var950
#define var1306	BUFFER[16215]	// Внутренняя переменная var1306
#define idvar1306	31717	// Внутренняя переменная var1306
#define var1072	BUFFER[16217]	// Внутренняя переменная var1072
#define idvar1072	31718	// Внутренняя переменная var1072
#define var1188	BUFFER[16219]	// Внутренняя переменная var1188
#define idvar1188	31719	// Внутренняя переменная var1188
#define var1736	BUFFER[16221]	// Внутренняя переменная var1736
#define idvar1736	31720	// Внутренняя переменная var1736
#define var883	BUFFER[16223]	// Внутренняя переменная var883
#define idvar883	31721	// Внутренняя переменная var883
#define var1389	BUFFER[16225]	// Внутренняя переменная var1389
#define idvar1389	31722	// Внутренняя переменная var1389
#define var1809	BUFFER[16228]	// Внутренняя переменная var1809
#define idvar1809	31723	// Внутренняя переменная var1809
#define var1849	BUFFER[16230]	// Внутренняя переменная var1849
#define idvar1849	31724	// Внутренняя переменная var1849
#define var1894	BUFFER[16232]	// Внутренняя переменная var1894
#define idvar1894	31725	// Внутренняя переменная var1894
#define var119	BUFFER[16234]	// Внутренняя переменная var119
#define idvar119	31726	// Внутренняя переменная var119
#define var210	BUFFER[16236]	// Внутренняя переменная var210
#define idvar210	31727	// Внутренняя переменная var210
#define var299	BUFFER[16238]	// Внутренняя переменная var299
#define idvar299	31728	// Внутренняя переменная var299
#define var1203	BUFFER[16240]	// Внутренняя переменная var1203
#define idvar1203	31729	// Внутренняя переменная var1203
#define var9	BUFFER[16242]	// Внутренняя переменная var9
#define idvar9	31730	// Внутренняя переменная var9
#define var222	BUFFER[16244]	// Внутренняя переменная var222
#define idvar222	31731	// Внутренняя переменная var222
#define var373	BUFFER[16246]	// Внутренняя переменная var373
#define idvar373	31732	// Внутренняя переменная var373
#define var747	BUFFER[16248]	// Внутренняя переменная var747
#define idvar747	31733	// Внутренняя переменная var747
#define var870	BUFFER[16250]	// Внутренняя переменная var870
#define idvar870	31734	// Внутренняя переменная var870
#define var1332	BUFFER[16252]	// Внутренняя переменная var1332
#define idvar1332	31735	// Внутренняя переменная var1332
#define var651	BUFFER[16254]	// Внутренняя переменная var651
#define idvar651	31736	// Внутренняя переменная var651
#define var793	BUFFER[16256]	// Внутренняя переменная var793
#define idvar793	31737	// Внутренняя переменная var793
#define var1047	BUFFER[16258]	// Внутренняя переменная var1047
#define idvar1047	31738	// Внутренняя переменная var1047
#define var1213	BUFFER[16260]	// Внутренняя переменная var1213
#define idvar1213	31739	// Внутренняя переменная var1213
#define var277	BUFFER[16265]	// Внутренняя переменная var277
#define idvar277	31740	// Внутренняя переменная var277
#define var295	BUFFER[16267]	// Внутренняя переменная var295
#define idvar295	31741	// Внутренняя переменная var295
#define var744	BUFFER[16269]	// Внутренняя переменная var744
#define idvar744	31742	// Внутренняя переменная var744
#define var1623	BUFFER[16271]	// Внутренняя переменная var1623
#define idvar1623	31743	// Внутренняя переменная var1623
#define var1887	BUFFER[16273]	// Внутренняя переменная var1887
#define idvar1887	31744	// Внутренняя переменная var1887
#define var1994	BUFFER[16275]	// Внутренняя переменная var1994
#define idvar1994	31745	// Внутренняя переменная var1994
#define var1344	BUFFER[16280]	// Внутренняя переменная var1344
#define idvar1344	31746	// Внутренняя переменная var1344
#define var1457	BUFFER[16282]	// Внутренняя переменная var1457
#define idvar1457	31747	// Внутренняя переменная var1457
#define var156	BUFFER[16284]	// Внутренняя переменная var156
#define idvar156	31748	// Внутренняя переменная var156
#define var308	BUFFER[16286]	// Внутренняя переменная var308
#define idvar308	31749	// Внутренняя переменная var308
#define var1649	BUFFER[16288]	// Внутренняя переменная var1649
#define idvar1649	31750	// Внутренняя переменная var1649
#define var686	BUFFER[16290]	// Внутренняя переменная var686
#define idvar686	31751	// Внутренняя переменная var686
#define var794	BUFFER[16292]	// Внутренняя переменная var794
#define idvar794	31752	// Внутренняя переменная var794
#define var948	BUFFER[16294]	// Внутренняя переменная var948
#define idvar948	31753	// Внутренняя переменная var948
#define var1007	BUFFER[16296]	// Внутренняя переменная var1007
#define idvar1007	31754	// Внутренняя переменная var1007
#define var1501	BUFFER[16298]	// Внутренняя переменная var1501
#define idvar1501	31755	// Внутренняя переменная var1501
#define var290	BUFFER[16300]	// Внутренняя переменная var290
#define idvar290	31756	// Внутренняя переменная var290
#define var296	BUFFER[16302]	// Внутренняя переменная var296
#define idvar296	31757	// Внутренняя переменная var296
#define var555	BUFFER[16304]	// Внутренняя переменная var555
#define idvar555	31758	// Внутренняя переменная var555
#define var1668	BUFFER[16306]	// Внутренняя переменная var1668
#define idvar1668	31759	// Внутренняя переменная var1668
#define var1850	BUFFER[16308]	// Внутренняя переменная var1850
#define idvar1850	31760	// Внутренняя переменная var1850
#define var852	BUFFER[16310]	// Внутренняя переменная var852
#define idvar852	31761	// Внутренняя переменная var852
#define var1799	BUFFER[16312]	// Внутренняя переменная var1799
#define idvar1799	31762	// Внутренняя переменная var1799
#define var197	BUFFER[16314]	// Внутренняя переменная var197
#define idvar197	31763	// Внутренняя переменная var197
#define var204	BUFFER[16316]	// Внутренняя переменная var204
#define idvar204	31764	// Внутренняя переменная var204
#define var507	BUFFER[16318]	// Внутренняя переменная var507
#define idvar507	31765	// Внутренняя переменная var507
#define var669	BUFFER[16320]	// Внутренняя переменная var669
#define idvar669	31766	// Внутренняя переменная var669
#define var679	BUFFER[16325]	// Внутренняя переменная var679
#define idvar679	31767	// Внутренняя переменная var679
#define var743	BUFFER[16327]	// Внутренняя переменная var743
#define idvar743	31768	// Внутренняя переменная var743
#define var485	BUFFER[16329]	// Внутренняя переменная var485
#define idvar485	31769	// Внутренняя переменная var485
#define var1218	BUFFER[16331]	// Внутренняя переменная var1218
#define idvar1218	31770	// Внутренняя переменная var1218
#define var139	BUFFER[16333]	// Внутренняя переменная var139
#define idvar139	31771	// Внутренняя переменная var139
#define var513	BUFFER[16335]	// Внутренняя переменная var513
#define idvar513	31772	// Внутренняя переменная var513
#define var1002	BUFFER[16337]	// Внутренняя переменная var1002
#define idvar1002	31773	// Внутренняя переменная var1002
#define var1008	BUFFER[16339]	// Внутренняя переменная var1008
#define idvar1008	31774	// Внутренняя переменная var1008
#define var1370	BUFFER[16341]	// Внутренняя переменная var1370
#define idvar1370	31775	// Внутренняя переменная var1370
#define var1823	BUFFER[16343]	// Внутренняя переменная var1823
#define idvar1823	31776	// Внутренняя переменная var1823
#define var1164	BUFFER[16345]	// Внутренняя переменная var1164
#define idvar1164	31777	// Внутренняя переменная var1164
#define var1755	BUFFER[16347]	// Внутренняя переменная var1755
#define idvar1755	31778	// Внутренняя переменная var1755
#define var1822	BUFFER[16349]	// Внутренняя переменная var1822
#define idvar1822	31779	// Внутренняя переменная var1822
#define var272	BUFFER[16351]	// Внутренняя переменная var272
#define idvar272	31780	// Внутренняя переменная var272
#define var527	BUFFER[16353]	// Внутренняя переменная var527
#define idvar527	31781	// Внутренняя переменная var527
#define var1738	BUFFER[16355]	// Внутренняя переменная var1738
#define idvar1738	31782	// Внутренняя переменная var1738
#define var1970	BUFFER[16357]	// Внутренняя переменная var1970
#define idvar1970	31783	// Внутренняя переменная var1970
#define var300	BUFFER[16359]	// Внутренняя переменная var300
#define idvar300	31784	// Внутренняя переменная var300
#define var632	BUFFER[16361]	// Внутренняя переменная var632
#define idvar632	31785	// Внутренняя переменная var632
#define var1405	BUFFER[16363]	// Внутренняя переменная var1405
#define idvar1405	31786	// Внутренняя переменная var1405
#define var1415	BUFFER[16365]	// Внутренняя переменная var1415
#define idvar1415	31787	// Внутренняя переменная var1415
#define var1664	BUFFER[16367]	// Внутренняя переменная var1664
#define idvar1664	31788	// Внутренняя переменная var1664
#define var1696	BUFFER[16369]	// Внутренняя переменная var1696
#define idvar1696	31789	// Внутренняя переменная var1696
#define var1284	BUFFER[16371]	// Внутренняя переменная var1284
#define idvar1284	31790	// Внутренняя переменная var1284
#define var241	BUFFER[16373]	// Внутренняя переменная var241
#define idvar241	31791	// Внутренняя переменная var241
#define var797	BUFFER[16375]	// Внутренняя переменная var797
#define idvar797	31792	// Внутренняя переменная var797
#define var832	BUFFER[16377]	// Внутренняя переменная var832
#define idvar832	31793	// Внутренняя переменная var832
#define var1300	BUFFER[16379]	// Внутренняя переменная var1300
#define idvar1300	31794	// Внутренняя переменная var1300
#define var1470	BUFFER[16381]	// Внутренняя переменная var1470
#define idvar1470	31795	// Внутренняя переменная var1470
#define var1449	BUFFER[16383]	// Внутренняя переменная var1449
#define idvar1449	31796	// Внутренняя переменная var1449
#define var1572	BUFFER[16385]	// Внутренняя переменная var1572
#define idvar1572	31797	// Внутренняя переменная var1572
#define var1704	BUFFER[16387]	// Внутренняя переменная var1704
#define idvar1704	31798	// Внутренняя переменная var1704
#define var534	BUFFER[16389]	// Внутренняя переменная var534
#define idvar534	31799	// Внутренняя переменная var534
#define var1676	BUFFER[16391]	// Внутренняя переменная var1676
#define idvar1676	31800	// Внутренняя переменная var1676
#define var695	BUFFER[16394]	// Внутренняя переменная var695
#define idvar695	31801	// Внутренняя переменная var695
#define var1394	BUFFER[16396]	// Внутренняя переменная var1394
#define idvar1394	31802	// Внутренняя переменная var1394
#define var714	BUFFER[16398]	// Внутренняя переменная var714
#define idvar714	31803	// Внутренняя переменная var714
#define var1282	BUFFER[16400]	// Внутренняя переменная var1282
#define idvar1282	31804	// Внутренняя переменная var1282
#define var450	BUFFER[16402]	// Внутренняя переменная var450
#define idvar450	31805	// Внутренняя переменная var450
#define var1538	BUFFER[16407]	// Внутренняя переменная var1538
#define idvar1538	31806	// Внутренняя переменная var1538
#define var1658	BUFFER[16409]	// Внутренняя переменная var1658
#define idvar1658	31807	// Внутренняя переменная var1658
#define var1893	BUFFER[16411]	// Внутренняя переменная var1893
#define idvar1893	31808	// Внутренняя переменная var1893
#define var606	BUFFER[16413]	// Внутренняя переменная var606
#define idvar606	31809	// Внутренняя переменная var606
#define var779	BUFFER[16415]	// Внутренняя переменная var779
#define idvar779	31810	// Внутренняя переменная var779
#define var1068	BUFFER[16417]	// Внутренняя переменная var1068
#define idvar1068	31811	// Внутренняя переменная var1068
#define var1493	BUFFER[16419]	// Внутренняя переменная var1493
#define idvar1493	31812	// Внутренняя переменная var1493
#define var1715	BUFFER[16421]	// Внутренняя переменная var1715
#define idvar1715	31813	// Внутренняя переменная var1715
#define var1722	BUFFER[16423]	// Внутренняя переменная var1722
#define idvar1722	31814	// Внутренняя переменная var1722
#define var609	BUFFER[16425]	// Внутренняя переменная var609
#define idvar609	31815	// Внутренняя переменная var609
#define var924	BUFFER[16427]	// Внутренняя переменная var924
#define idvar924	31816	// Внутренняя переменная var924
#define var1723	BUFFER[16429]	// Внутренняя переменная var1723
#define idvar1723	31817	// Внутренняя переменная var1723
#define var128	BUFFER[16431]	// Внутренняя переменная var128
#define idvar128	31818	// Внутренняя переменная var128
#define var762	BUFFER[16433]	// Внутренняя переменная var762
#define idvar762	31819	// Внутренняя переменная var762
#define var1157	BUFFER[16435]	// Внутренняя переменная var1157
#define idvar1157	31820	// Внутренняя переменная var1157
#define var1314	BUFFER[16437]	// Внутренняя переменная var1314
#define idvar1314	31821	// Внутренняя переменная var1314
#define var543	BUFFER[16439]	// Внутренняя переменная var543
#define idvar543	31822	// Внутренняя переменная var543
#define var613	BUFFER[16441]	// Внутренняя переменная var613
#define idvar613	31823	// Внутренняя переменная var613
#define var1038	BUFFER[16443]	// Внутренняя переменная var1038
#define idvar1038	31824	// Внутренняя переменная var1038
#define var1085	BUFFER[16445]	// Внутренняя переменная var1085
#define idvar1085	31825	// Внутренняя переменная var1085
#define var76	BUFFER[16447]	// Внутренняя переменная var76
#define idvar76	31826	// Внутренняя переменная var76
#define var161	BUFFER[16449]	// Внутренняя переменная var161
#define idvar161	31827	// Внутренняя переменная var161
#define var593	BUFFER[16451]	// Внутренняя переменная var593
#define idvar593	31828	// Внутренняя переменная var593
#define var1836	BUFFER[16453]	// Внутренняя переменная var1836
#define idvar1836	31829	// Внутренняя переменная var1836
#define var141	BUFFER[16455]	// Внутренняя переменная var141
#define idvar141	31830	// Внутренняя переменная var141
#define var931	BUFFER[16457]	// Внутренняя переменная var931
#define idvar931	31831	// Внутренняя переменная var931
#define var1022	BUFFER[16459]	// Внутренняя переменная var1022
#define idvar1022	31832	// Внутренняя переменная var1022
#define var1171	BUFFER[16461]	// Внутренняя переменная var1171
#define idvar1171	31833	// Внутренняя переменная var1171
#define var1210	BUFFER[16463]	// Внутренняя переменная var1210
#define idvar1210	31834	// Внутренняя переменная var1210
#define var1782	BUFFER[16465]	// Внутренняя переменная var1782
#define idvar1782	31835	// Внутренняя переменная var1782
#define var724	BUFFER[16467]	// Внутренняя переменная var724
#define idvar724	31836	// Внутренняя переменная var724
#define var880	BUFFER[16469]	// Внутренняя переменная var880
#define idvar880	31837	// Внутренняя переменная var880
#define var1588	BUFFER[16471]	// Внутренняя переменная var1588
#define idvar1588	31838	// Внутренняя переменная var1588
#define var691	BUFFER[16473]	// Внутренняя переменная var691
#define idvar691	31839	// Внутренняя переменная var691
#define var12	BUFFER[16475]	// Внутренняя переменная var12
#define idvar12	31840	// Внутренняя переменная var12
#define var232	BUFFER[16477]	// Внутренняя переменная var232
#define idvar232	31841	// Внутренняя переменная var232
#define var983	BUFFER[16479]	// Внутренняя переменная var983
#define idvar983	31842	// Внутренняя переменная var983
#define var1132	BUFFER[16481]	// Внутренняя переменная var1132
#define idvar1132	31843	// Внутренняя переменная var1132
#define var1233	BUFFER[16483]	// Внутренняя переменная var1233
#define idvar1233	31844	// Внутренняя переменная var1233
#define var688	BUFFER[16485]	// Внутренняя переменная var688
#define idvar688	31845	// Внутренняя переменная var688
#define var944	BUFFER[16487]	// Внутренняя переменная var944
#define idvar944	31846	// Внутренняя переменная var944
#define var1106	BUFFER[16489]	// Внутренняя переменная var1106
#define idvar1106	31847	// Внутренняя переменная var1106
#define var1160	BUFFER[16491]	// Внутренняя переменная var1160
#define idvar1160	31848	// Внутренняя переменная var1160
#define var1839	BUFFER[16493]	// Внутренняя переменная var1839
#define idvar1839	31849	// Внутренняя переменная var1839
#define var1951	BUFFER[16495]	// Внутренняя переменная var1951
#define idvar1951	31850	// Внутренняя переменная var1951
#define var576	BUFFER[16500]	// Внутренняя переменная var576
#define idvar576	31851	// Внутренняя переменная var576
#define var776	BUFFER[16502]	// Внутренняя переменная var776
#define idvar776	31852	// Внутренняя переменная var776
#define var367	BUFFER[16504]	// Внутренняя переменная var367
#define idvar367	31853	// Внутренняя переменная var367
#define var930	BUFFER[16506]	// Внутренняя переменная var930
#define idvar930	31854	// Внутренняя переменная var930
#define var829	BUFFER[16508]	// Внутренняя переменная var829
#define idvar829	31855	// Внутренняя переменная var829
#define var1099	BUFFER[16510]	// Внутренняя переменная var1099
#define idvar1099	31856	// Внутренняя переменная var1099
#define var1601	BUFFER[16512]	// Внутренняя переменная var1601
#define idvar1601	31857	// Внутренняя переменная var1601
#define var1608	BUFFER[16514]	// Внутренняя переменная var1608
#define idvar1608	31858	// Внутренняя переменная var1608
#define var1710	BUFFER[16516]	// Внутренняя переменная var1710
#define idvar1710	31859	// Внутренняя переменная var1710
#define var47	BUFFER[16518]	// Внутренняя переменная var47
#define idvar47	31860	// Внутренняя переменная var47
#define var996	BUFFER[16520]	// Внутренняя переменная var996
#define idvar996	31861	// Внутренняя переменная var996
#define var1094	BUFFER[16522]	// Внутренняя переменная var1094
#define idvar1094	31862	// Внутренняя переменная var1094
#define var1396	BUFFER[16524]	// Внутренняя переменная var1396
#define idvar1396	31863	// Внутренняя переменная var1396
#define var1584	BUFFER[16526]	// Внутренняя переменная var1584
#define idvar1584	31864	// Внутренняя переменная var1584
#define var274	BUFFER[16528]	// Внутренняя переменная var274
#define idvar274	31865	// Внутренняя переменная var274
#define var720	BUFFER[16530]	// Внутренняя переменная var720
#define idvar720	31866	// Внутренняя переменная var720
#define var1031	BUFFER[16532]	// Внутренняя переменная var1031
#define idvar1031	31867	// Внутренняя переменная var1031
#define var1226	BUFFER[16534]	// Внутренняя переменная var1226
#define idvar1226	31868	// Внутренняя переменная var1226
#define var1590	BUFFER[16539]	// Внутренняя переменная var1590
#define idvar1590	31869	// Внутренняя переменная var1590
#define var614	BUFFER[16541]	// Внутренняя переменная var614
#define idvar614	31870	// Внутренняя переменная var614
#define var963	BUFFER[16543]	// Внутренняя переменная var963
#define idvar963	31871	// Внутренняя переменная var963
#define var1234	BUFFER[16545]	// Внутренняя переменная var1234
#define idvar1234	31872	// Внутренняя переменная var1234
#define var1563	BUFFER[16547]	// Внутренняя переменная var1563
#define idvar1563	31873	// Внутренняя переменная var1563
#define var1911	BUFFER[16549]	// Внутренняя переменная var1911
#define idvar1911	31874	// Внутренняя переменная var1911
#define vainSInt	BUFFER[16551]	// Внутренняя переменная vainSInt
#define idvainSInt	31875	// Внутренняя переменная vainSInt
#define var1161	BUFFER[16554]	// Внутренняя переменная var1161
#define idvar1161	31876	// Внутренняя переменная var1161
#define var1228	BUFFER[16556]	// Внутренняя переменная var1228
#define idvar1228	31877	// Внутренняя переменная var1228
#define var183	BUFFER[16558]	// Внутренняя переменная var183
#define idvar183	31878	// Внутренняя переменная var183
#define var844	BUFFER[16560]	// Внутренняя переменная var844
#define idvar844	31879	// Внутренняя переменная var844
#define var999	BUFFER[16562]	// Внутренняя переменная var999
#define idvar999	31880	// Внутренняя переменная var999
#define var1245	BUFFER[16564]	// Внутренняя переменная var1245
#define idvar1245	31881	// Внутренняя переменная var1245
#define var1539	BUFFER[16566]	// Внутренняя переменная var1539
#define idvar1539	31882	// Внутренняя переменная var1539
#define var57	BUFFER[16568]	// Внутренняя переменная var57
#define idvar57	31883	// Внутренняя переменная var57
#define var249	BUFFER[16570]	// Внутренняя переменная var249
#define idvar249	31884	// Внутренняя переменная var249
#define var788	BUFFER[16572]	// Внутренняя переменная var788
#define idvar788	31885	// Внутренняя переменная var788
#define var843	BUFFER[16574]	// Внутренняя переменная var843
#define idvar843	31886	// Внутренняя переменная var843
#define var1571	BUFFER[16576]	// Внутренняя переменная var1571
#define idvar1571	31887	// Внутренняя переменная var1571
#define var66	BUFFER[16578]	// Внутренняя переменная var66
#define idvar66	31888	// Внутренняя переменная var66
#define var303	BUFFER[16580]	// Внутренняя переменная var303
#define idvar303	31889	// Внутренняя переменная var303
#define var423	BUFFER[16582]	// Внутренняя переменная var423
#define idvar423	31890	// Внутренняя переменная var423
#define var545	BUFFER[16584]	// Внутренняя переменная var545
#define idvar545	31891	// Внутренняя переменная var545
#define var1917	BUFFER[16586]	// Внутренняя переменная var1917
#define idvar1917	31892	// Внутренняя переменная var1917
#define var283	BUFFER[16588]	// Внутренняя переменная var283
#define idvar283	31893	// Внутренняя переменная var283
#define var1028	BUFFER[16590]	// Внутренняя переменная var1028
#define idvar1028	31894	// Внутренняя переменная var1028
#define var1269	BUFFER[16592]	// Внутренняя переменная var1269
#define idvar1269	31895	// Внутренняя переменная var1269
#define var1846	BUFFER[16594]	// Внутренняя переменная var1846
#define idvar1846	31896	// Внутренняя переменная var1846
#define var152	BUFFER[16597]	// Внутренняя переменная var152
#define idvar152	31897	// Внутренняя переменная var152
#define var755	BUFFER[16599]	// Внутренняя переменная var755
#define idvar755	31898	// Внутренняя переменная var755
#define var933	BUFFER[16601]	// Внутренняя переменная var933
#define idvar933	31899	// Внутренняя переменная var933
#define var1291	BUFFER[16603]	// Внутренняя переменная var1291
#define idvar1291	31900	// Внутренняя переменная var1291
#define var1334	BUFFER[16605]	// Внутренняя переменная var1334
#define idvar1334	31901	// Внутренняя переменная var1334
#define var1365	BUFFER[16607]	// Внутренняя переменная var1365
#define idvar1365	31902	// Внутренняя переменная var1365
#define var311	BUFFER[16609]	// Внутренняя переменная var311
#define idvar311	31903	// Внутренняя переменная var311
#define var1616	BUFFER[16611]	// Внутренняя переменная var1616
#define idvar1616	31904	// Внутренняя переменная var1616
#define var825	BUFFER[16613]	// Внутренняя переменная var825
#define idvar825	31905	// Внутренняя переменная var825
#define var1109	BUFFER[16615]	// Внутренняя переменная var1109
#define idvar1109	31906	// Внутренняя переменная var1109
#define var30	BUFFER[16617]	// Внутренняя переменная var30
#define idvar30	31907	// Внутренняя переменная var30
#define var44	BUFFER[16619]	// Внутренняя переменная var44
#define idvar44	31908	// Внутренняя переменная var44
#define var251	BUFFER[16621]	// Внутренняя переменная var251
#define idvar251	31909	// Внутренняя переменная var251
#define var1286	BUFFER[16623]	// Внутренняя переменная var1286
#define idvar1286	31910	// Внутренняя переменная var1286
#define var199	BUFFER[16625]	// Внутренняя переменная var199
#define idvar199	31911	// Внутренняя переменная var199
#define var436	BUFFER[16627]	// Внутренняя переменная var436
#define idvar436	31912	// Внутренняя переменная var436
#define var441	BUFFER[16629]	// Внутренняя переменная var441
#define idvar441	31913	// Внутренняя переменная var441
#define var1856	BUFFER[16631]	// Внутренняя переменная var1856
#define idvar1856	31914	// Внутренняя переменная var1856
#define var1983	BUFFER[16633]	// Внутренняя переменная var1983
#define idvar1983	31915	// Внутренняя переменная var1983
#define var230	BUFFER[16635]	// Внутренняя переменная var230
#define idvar230	31916	// Внутренняя переменная var230
#define var1088	BUFFER[16637]	// Внутренняя переменная var1088
#define idvar1088	31917	// Внутренняя переменная var1088
#define var1779	BUFFER[16639]	// Внутренняя переменная var1779
#define idvar1779	31918	// Внутренняя переменная var1779
#define var1900	BUFFER[16641]	// Внутренняя переменная var1900
#define idvar1900	31919	// Внутренняя переменная var1900
#define var220	BUFFER[16643]	// Внутренняя переменная var220
#define idvar220	31920	// Внутренняя переменная var220
#define var368	BUFFER[16645]	// Внутренняя переменная var368
#define idvar368	31921	// Внутренняя переменная var368
#define var433	BUFFER[16647]	// Внутренняя переменная var433
#define idvar433	31922	// Внутренняя переменная var433
#define var569	BUFFER[16649]	// Внутренняя переменная var569
#define idvar569	31923	// Внутренняя переменная var569
#define var1024	BUFFER[16654]	// Внутренняя переменная var1024
#define idvar1024	31924	// Внутренняя переменная var1024
#define var1496	BUFFER[16656]	// Внутренняя переменная var1496
#define idvar1496	31925	// Внутренняя переменная var1496
#define var417	BUFFER[16658]	// Внутренняя переменная var417
#define idvar417	31926	// Внутренняя переменная var417
#define var611	BUFFER[16660]	// Внутренняя переменная var611
#define idvar611	31927	// Внутренняя переменная var611
#define var1328	BUFFER[16662]	// Внутренняя переменная var1328
#define idvar1328	31928	// Внутренняя переменная var1328
#define var304	BUFFER[16664]	// Внутренняя переменная var304
#define idvar304	31929	// Внутренняя переменная var304
#define var628	BUFFER[16666]	// Внутренняя переменная var628
#define idvar628	31930	// Внутренняя переменная var628
#define var730	BUFFER[16668]	// Внутренняя переменная var730
#define idvar730	31931	// Внутренняя переменная var730
#define var854	BUFFER[16670]	// Внутренняя переменная var854
#define idvar854	31932	// Внутренняя переменная var854
#define var1095	BUFFER[16672]	// Внутренняя переменная var1095
#define idvar1095	31933	// Внутренняя переменная var1095
#define var1500	BUFFER[16674]	// Внутренняя переменная var1500
#define idvar1500	31934	// Внутренняя переменная var1500
#define var154	BUFFER[16676]	// Внутренняя переменная var154
#define idvar154	31935	// Внутренняя переменная var154
#define var329	BUFFER[16678]	// Внутренняя переменная var329
#define idvar329	31936	// Внутренняя переменная var329
#define var914	BUFFER[16680]	// Внутренняя переменная var914
#define idvar914	31937	// Внутренняя переменная var914
#define var364	BUFFER[16682]	// Внутренняя переменная var364
#define idvar364	31938	// Внутренняя переменная var364
#define var526	BUFFER[16684]	// Внутренняя переменная var526
#define idvar526	31939	// Внутренняя переменная var526
#define var828	BUFFER[16686]	// Внутренняя переменная var828
#define idvar828	31940	// Внутренняя переменная var828
#define var917	BUFFER[16688]	// Внутренняя переменная var917
#define idvar917	31941	// Внутренняя переменная var917
#define var1340	BUFFER[16690]	// Внутренняя переменная var1340
#define idvar1340	31942	// Внутренняя переменная var1340
#define var1366	BUFFER[16692]	// Внутренняя переменная var1366
#define idvar1366	31943	// Внутренняя переменная var1366
#define var84	BUFFER[16694]	// Внутренняя переменная var84
#define idvar84	31944	// Внутренняя переменная var84
#define var406	BUFFER[16696]	// Внутренняя переменная var406
#define idvar406	31945	// Внутренняя переменная var406
#define var1352	BUFFER[16698]	// Внутренняя переменная var1352
#define idvar1352	31946	// Внутренняя переменная var1352
#define var1357	BUFFER[16700]	// Внутренняя переменная var1357
#define idvar1357	31947	// Внутренняя переменная var1357
#define var1600	BUFFER[16702]	// Внутренняя переменная var1600
#define idvar1600	31948	// Внутренняя переменная var1600
#define var182	BUFFER[16704]	// Внутренняя переменная var182
#define idvar182	31949	// Внутренняя переменная var182
#define var397	BUFFER[16706]	// Внутренняя переменная var397
#define idvar397	31950	// Внутренняя переменная var397
#define var696	BUFFER[16708]	// Внутренняя переменная var696
#define idvar696	31951	// Внутренняя переменная var696
#define var912	BUFFER[16710]	// Внутренняя переменная var912
#define idvar912	31952	// Внутренняя переменная var912
#define var1092	BUFFER[16712]	// Внутренняя переменная var1092
#define idvar1092	31953	// Внутренняя переменная var1092
#define var879	BUFFER[16714]	// Внутренняя переменная var879
#define idvar879	31954	// Внутренняя переменная var879
#define var1520	BUFFER[16716]	// Внутренняя переменная var1520
#define idvar1520	31955	// Внутренняя переменная var1520
#define var114	BUFFER[16718]	// Внутренняя переменная var114
#define idvar114	31956	// Внутренняя переменная var114
#define var1410	BUFFER[16720]	// Внутренняя переменная var1410
#define idvar1410	31957	// Внутренняя переменная var1410
#define var1636	BUFFER[16722]	// Внутренняя переменная var1636
#define idvar1636	31958	// Внутренняя переменная var1636
#define var1783	BUFFER[16724]	// Внутренняя переменная var1783
#define idvar1783	31959	// Внутренняя переменная var1783
#define var1853	BUFFER[16726]	// Внутренняя переменная var1853
#define idvar1853	31960	// Внутренняя переменная var1853
#define var1602	BUFFER[16728]	// Внутренняя переменная var1602
#define idvar1602	31961	// Внутренняя переменная var1602
#define var1693	BUFFER[16730]	// Внутренняя переменная var1693
#define idvar1693	31962	// Внутренняя переменная var1693
#define var247	BUFFER[16732]	// Внутренняя переменная var247
#define idvar247	31963	// Внутренняя переменная var247
#define var675	BUFFER[16734]	// Внутренняя переменная var675
#define idvar675	31964	// Внутренняя переменная var675
#define var920	BUFFER[16736]	// Внутренняя переменная var920
#define idvar920	31965	// Внутренняя переменная var920
#define var1055	BUFFER[16738]	// Внутренняя переменная var1055
#define idvar1055	31966	// Внутренняя переменная var1055
#define var1801	BUFFER[16740]	// Внутренняя переменная var1801
#define idvar1801	31967	// Внутренняя переменная var1801
#define var1402	BUFFER[16743]	// Внутренняя переменная var1402
#define idvar1402	31968	// Внутренняя переменная var1402
#define var1868	BUFFER[16745]	// Внутренняя переменная var1868
#define idvar1868	31969	// Внутренняя переменная var1868
#define var1938	BUFFER[16747]	// Внутренняя переменная var1938
#define idvar1938	31970	// Внутренняя переменная var1938
#define var123	BUFFER[16749]	// Внутренняя переменная var123
#define idvar123	31971	// Внутренняя переменная var123
#define var785	BUFFER[16751]	// Внутренняя переменная var785
#define idvar785	31972	// Внутренняя переменная var785
#define var1434	BUFFER[16753]	// Внутренняя переменная var1434
#define idvar1434	31973	// Внутренняя переменная var1434
#define var35	BUFFER[16755]	// Внутренняя переменная var35
#define idvar35	31974	// Внутренняя переменная var35
#define var595	BUFFER[16757]	// Внутренняя переменная var595
#define idvar595	31975	// Внутренняя переменная var595
#define var851	BUFFER[16759]	// Внутренняя переменная var851
#define idvar851	31976	// Внутренняя переменная var851
#define var902	BUFFER[16761]	// Внутренняя переменная var902
#define idvar902	31977	// Внутренняя переменная var902
#define var1919	BUFFER[16763]	// Внутренняя переменная var1919
#define idvar1919	31978	// Внутренняя переменная var1919
#define var14	BUFFER[16765]	// Внутренняя переменная var14
#define idvar14	31979	// Внутренняя переменная var14
#define var332	BUFFER[16767]	// Внутренняя переменная var332
#define idvar332	31980	// Внутренняя переменная var332
#define var705	BUFFER[16769]	// Внутренняя переменная var705
#define idvar705	31981	// Внутренняя переменная var705
#define var770	BUFFER[16771]	// Внутренняя переменная var770
#define idvar770	31982	// Внутренняя переменная var770
#define var842	BUFFER[16773]	// Внутренняя переменная var842
#define idvar842	31983	// Внутренняя переменная var842
#define var877	BUFFER[16775]	// Внутренняя переменная var877
#define idvar877	31984	// Внутренняя переменная var877
#define var711	BUFFER[16777]	// Внутренняя переменная var711
#define idvar711	31985	// Внутренняя переменная var711
#define var856	BUFFER[16779]	// Внутренняя переменная var856
#define idvar856	31986	// Внутренняя переменная var856
#define var1128	BUFFER[16781]	// Внутренняя переменная var1128
#define idvar1128	31987	// Внутренняя переменная var1128
#define var1724	BUFFER[16783]	// Внутренняя переменная var1724
#define idvar1724	31988	// Внутренняя переменная var1724
#define var1790	BUFFER[16785]	// Внутренняя переменная var1790
#define idvar1790	31989	// Внутренняя переменная var1790
#define var1978	BUFFER[16787]	// Внутренняя переменная var1978
#define idvar1978	31990	// Внутренняя переменная var1978
#define var400	BUFFER[16789]	// Внутренняя переменная var400
#define idvar400	31991	// Внутренняя переменная var400
#define var501	BUFFER[16791]	// Внутренняя переменная var501
#define idvar501	31992	// Внутренняя переменная var501
#define var627	BUFFER[16793]	// Внутренняя переменная var627
#define idvar627	31993	// Внутренняя переменная var627
#define var1547	BUFFER[16795]	// Внутренняя переменная var1547
#define idvar1547	31994	// Внутренняя переменная var1547
#define var764	BUFFER[16797]	// Внутренняя переменная var764
#define idvar764	31995	// Внутренняя переменная var764
#define var1505	BUFFER[16799]	// Внутренняя переменная var1505
#define idvar1505	31996	// Внутренняя переменная var1505
#define var1948	BUFFER[16801]	// Внутренняя переменная var1948
#define idvar1948	31997	// Внутренняя переменная var1948
#define var1969	BUFFER[16803]	// Внутренняя переменная var1969
#define idvar1969	31998	// Внутренняя переменная var1969
#define var504	BUFFER[16805]	// Внутренняя переменная var504
#define idvar504	31999	// Внутренняя переменная var504
#define var1454	BUFFER[16807]	// Внутренняя переменная var1454
#define idvar1454	32000	// Внутренняя переменная var1454
#define var1504	BUFFER[16809]	// Внутренняя переменная var1504
#define idvar1504	32001	// Внутренняя переменная var1504
#define var1663	BUFFER[16811]	// Внутренняя переменная var1663
#define idvar1663	32002	// Внутренняя переменная var1663
#define var98	BUFFER[16813]	// Внутренняя переменная var98
#define idvar98	32003	// Внутренняя переменная var98
#define var336	BUFFER[16815]	// Внутренняя переменная var336
#define idvar336	32004	// Внутренняя переменная var336
#define var337	BUFFER[16817]	// Внутренняя переменная var337
#define idvar337	32005	// Внутренняя переменная var337
#define var736	BUFFER[16819]	// Внутренняя переменная var736
#define idvar736	32006	// Внутренняя переменная var736
#define var1108	BUFFER[16821]	// Внутренняя переменная var1108
#define idvar1108	32007	// Внутренняя переменная var1108
#define var1784	BUFFER[16823]	// Внутренняя переменная var1784
#define idvar1784	32008	// Внутренняя переменная var1784
#pragma pack(push,1)
static VarCtrl allVariables[]={ 			 //Описание всех переменных
	 1	,8	,1	,&A0CT01IZ1},	//( - , MDuBz1) Температура АЗ1-1
	 2	,8	,1	,&A0CT01IZ2},	//( - , MDuBz2) Температура АЗ1-2
	 3	,1	,1	,&A0EE01LZ1},	//( - , MDuBz1) Исправность АКНП1
	 4	,1	,1	,&A0EE01LZ2},	//( - , MDuBz2) Исправность АКНП1
	 5	,1	,1	,&A0EE02LZ1},	//( - , MDuBz1) Исправность АКНП2
	 6	,1	,1	,&A0EE02LZ2},	//( - , MDuBz2) Исправность АКНП2
	 7	,1	,1	,&A0EE03LZ1},	//( - , MDuBz1) Исправность АКНП3
	 8	,1	,1	,&A0EE03LZ2},	//( - , MDuBz2) Исправность АКНП3
	 9	,1	,1	,&A0EE04LZ1},	//( - , MDuBz1) Исправность АКНП4
	 10	,1	,1	,&A0EE04LZ2},	//( - , MDuBz2) Исправность АКНП4
	 11	,1	,1	,&A0VE01LDU},	//( - , DU) Напряжение в системы АЗ1 подано
	 12	,1	,1	,&A0VN01LDU},	//( - , DU) Каналы АЗ1 проверены
	 13	,1	,1	,&A0VN71LZ1},	//( - , MDuBz1) АЗ по АС мощности для АЗ1
	 14	,1	,1	,&A0VN71LZ2},	//( - , MDuBz2) АЗ по АС мощности для АЗ1
	 15	,1	,1	,&A0VP01LDU},	//( - , DU) Давление в системы АЗ1 подано
	 16	,1	,1	,&A0VP71LZ1},	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
	 17	,1	,1	,&A0VP71LZ2},	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
	 18	,1	,1	,&A0VS11LDU},	//( - , DU) АЗ1 готова к работе
	 19	,1	,1	,&A0VT71LZ1},	//( - , MDuBz1) АС по температуре в АЗ1
	 20	,1	,1	,&A0VT71LZ2},	//( - , MDuBz2) АС по температуре в АЗ1
	 21	,1	,1	,&A1AB01LDU},	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
	 22	,1	,1	,&A1AB02LDU},	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
	 23	,1	,1	,&A1AB04LDU},	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
	 24	,1	,1	,&A1AB05LDU},	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
	 25	,1	,1	,&A1AB06LDU},	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
	 26	,1	,1	,&A1AB07LDU},	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
	 27	,1	,1	,&A1AB08LDU},	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
	 28	,1	,1	,&A1AB09LDU},	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
	 29	,1	,1	,&A1AB10LDU},	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
	 30	,1	,1	,&A1AB11LDU},	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
	 31	,1	,1	,&A1AB12LDU},	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	 32	,1	,1	,&A1AB13LDU},	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
	 33	,1	,1	,&A1AB14LDU},	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
	 34	,1	,1	,&A1AB16LDU},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
	 35	,1	,1	,&A1AB17LDU},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
	 36	,1	,1	,&A1AB18LDU},	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
	 37	,1	,1	,&A1AB19LDU},	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
	 38	,1	,1	,&A1AD01LDU},	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
	 39	,1	,1	,&A1AD02LDU},	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
	 40	,1	,1	,&A1AD03LDU},	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
	 41	,1	,1	,&A1AD04LDU},	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
	 42	,1	,1	,&A1AD05LDU},	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
	 43	,1	,1	,&A1AD11LDU},	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
	 44	,1	,1	,&A1AD21LDU},	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
	 45	,1	,1	,&A1AD31LDU},	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
	 46	,1	,1	,&A1AD32LDU},	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
	 47	,1	,1	,&A1AZ03LDU},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
	 48	,8	,1	,&A1CV01RDU},	//( - , DU) Измеренная скорость перемещения ББ1
	 49	,8	,1	,&A1CV02RDU},	//( - , DU) Заданная скорость перемещения ББ1
	 50	,5	,1	,&A1IC01UDU},	//( - , MDuS) Координата штока ББ1 (дел.энк)
	 51	,1	,1	,&A1IE01LDU},	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
	 52	,1	,1	,&A1IE02LDU},	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
	 53	,1	,1	,&A1IE03LDU},	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
	 54	,1	,1	,&A1IE04LDU},	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
	 55	,1	,1	,&A1IS11LDU},	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
	 56	,1	,1	,&A1IS12LDU},	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
	 57	,1	,1	,&A1IS21LDU},	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
	 58	,1	,1	,&A1MC01LC1},	//( - , DU) Настроить энкодер ББ1
	 59	,1	,1	,&A1MC01LC2},	//( - , DU) Настроить энкодер ББ1
	 60	,8	,1	,&A1MC01RP1},	//( - , DU) Заданная координата положения ББ1 мм
	 61	,1	,1	,&A1MD11LP1},	//( - , DU) Кнопка ПУСК ББ1
	 62	,1	,1	,&A1MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
	 63	,8	,1	,&A1VC01RDU},	//( - , DU) Координата ББ1, мм
	 64	,1	,1	,&A1VN71LZ1},	//(vds32:02 - K21VDSR, DU) Блокировка автоматического подъёма ББ
	 65	,1	,1	,&A1VN71LZ2},	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
	 66	,1	,1	,&A1VP41LZ1},	//( - , MDuBz1) Давление СБРОС ББ1 ниже АС
	 67	,1	,1	,&A1VP41LZ2},	//( - , MDuBz2) Давление СБРОС ББ1 ниже АС
	 68	,3	,1	,&A1VS01IDU},	//( - , DU) Готовность к управлению ББ1
	 69	,1	,1	,&A1VS12LDU},	//( - , DU) Движение ББ1 в сторону ВУ
	 70	,1	,1	,&A1VS22LDU},	//( - , DU) Движение ББ1 в сторону НУ
	 71	,1	,1	,&A1ZAV},	//( - , DU) 
	 72	,1	,1	,&A2AB01LDU},	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
	 73	,1	,1	,&A2AB02LDU},	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
	 74	,1	,1	,&A2AB04LDU},	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
	 75	,1	,1	,&A2AB05LDU},	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
	 76	,1	,1	,&A2AB06LDU},	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
	 77	,1	,1	,&A2AB07LDU},	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
	 78	,1	,1	,&A2AB08LDU},	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
	 79	,1	,1	,&A2AB09LDU},	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
	 80	,1	,1	,&A2AB10LDU},	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
	 81	,1	,1	,&A2AB11LDU},	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
	 82	,1	,1	,&A2AB12LDU},	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	 83	,1	,1	,&A2AB13LDU},	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
	 84	,1	,1	,&A2AB14LDU},	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
	 85	,1	,1	,&A2AB15LDU},	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	 86	,1	,1	,&A2AB16LDU},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
	 87	,1	,1	,&A2AB17LDU},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
	 88	,1	,1	,&A2AD01LDU},	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
	 89	,1	,1	,&A2AD02LDU},	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
	 90	,1	,1	,&A2AD03LDU},	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
	 91	,1	,1	,&A2AD04LDU},	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
	 92	,1	,1	,&A2AD05LDU},	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
	 93	,1	,1	,&A2AD11LDU},	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
	 94	,1	,1	,&A2AD21LDU},	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
	 95	,1	,1	,&A2AD31LDU},	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
	 96	,1	,1	,&A2AD32LDU},	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
	 97	,1	,1	,&A2AD33LDU},	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
	 98	,1	,1	,&A2AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
	 99	,8	,1	,&A2CV01RDU},	//( - , DU) Измеренная скорость перемещения РБ1
	 100	,8	,1	,&A2CV02RDU},	//( - , DU) Заданная скорость перемещения РБ1
	 101	,5	,1	,&A2IC01UDU},	//( - , MDuS) Координата штока РБ1 (дел.энк)
	 102	,1	,1	,&A2IE01LDU},	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
	 103	,1	,1	,&A2IE02LDU},	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
	 104	,1	,1	,&A2IE03LDU},	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
	 105	,1	,1	,&A2IE04LDU},	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
	 106	,1	,1	,&A2IS11LDU},	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
	 107	,1	,1	,&A2IS12LDU},	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
	 108	,1	,1	,&A2IS21LDU},	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
	 109	,1	,1	,&A2IS33LDU},	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
	 110	,1	,1	,&A2MC01LC1},	//( - , DU) Настроить энкодер РБ1
	 111	,1	,1	,&A2MC01LC2},	//( - , DU) Настроить энкодер РБ1
	 112	,1	,1	,&A2MD11LP1},	//( - , DU) Кнопка ПУСК РБ1
	 113	,1	,1	,&A2MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
	 114	,8	,1	,&A2VC01RDU},	//( - , DU) Координата РБ1, мм
	 115	,1	,1	,&A2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
	 116	,3	,1	,&A2VS01IDU},	//( - , DU) Готовность к управлению РБ1
	 117	,1	,1	,&A2VS11LDU},	//( - , DU) Движение РБ1 в сторону ВУ
	 118	,1	,1	,&A2VS21LDU},	//( - , DU) Движение РБ1 в сторону НУ
	 119	,1	,1	,&A2VS32LDU},	//( - , DU) Индикация  СБРОС РБ1
	 120	,1	,1	,&A2ZAV},	//( - , DU) Завершение РБ1,2
	 121	,1	,1	,&A3AB01LDU},	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
	 122	,1	,1	,&A3AB02LDU},	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
	 123	,1	,1	,&A3AB04LDU},	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
	 124	,1	,1	,&A3AB05LDU},	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
	 125	,1	,1	,&A3AB06LDU},	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
	 126	,1	,1	,&A3AB07LDU},	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
	 127	,1	,1	,&A3AB08LDU},	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
	 128	,1	,1	,&A3AB09LDU},	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
	 129	,1	,1	,&A3AB10LDU},	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
	 130	,1	,1	,&A3AB11LDU},	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
	 131	,1	,1	,&A3AB12LDU},	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	 132	,1	,1	,&A3AB13LDU},	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
	 133	,1	,1	,&A3AB14LDU},	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
	 134	,1	,1	,&A3AB15LDU},	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
	 135	,1	,1	,&A3AB16LDU},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
	 136	,1	,1	,&A3AB17LDU},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
	 137	,1	,1	,&A3AB18LDU},	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
	 138	,1	,1	,&A3AB19LDU},	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
	 139	,1	,1	,&A3AB20LDU},	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
	 140	,1	,1	,&A3AD01LDU},	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
	 141	,1	,1	,&A3AD02LDU},	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
	 142	,1	,1	,&A3AD03LDU},	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
	 143	,1	,1	,&A3AD04LDU},	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
	 144	,1	,1	,&A3AD05LDU},	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
	 145	,1	,1	,&A3AD11LDU},	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
	 146	,1	,1	,&A3AD21LDU},	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
	 147	,1	,1	,&A3AD31LDU},	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
	 148	,1	,1	,&A3AD33LDU},	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
	 149	,1	,1	,&A3AD34LDU},	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
	 150	,1	,1	,&A3AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
	 151	,8	,1	,&A3CP02RDU},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
	 152	,8	,1	,&A3CV01RDU},	//( - , DU) Измеренная скорость перемещения ИС1
	 153	,8	,1	,&A3CV02RDU},	//( - , DU) Заданная скорость перемещения ИС1
	 154	,1	,1	,&A3EE03LDU},	//( - , DU) ВПИС ИС1
	 155	,5	,1	,&A3IC01UDU},	//( - , MDuS) Координата штока ИС1 (дел.энк)
	 156	,1	,1	,&A3IE01LDU},	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
	 157	,1	,1	,&A3IE02LDU},	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
	 158	,1	,1	,&A3IE03LDU},	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
	 159	,1	,1	,&A3IE04LDU},	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
	 160	,3	,1	,&A3IP02IDU},	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
	 161	,1	,1	,&A3IS11LDU},	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
	 162	,1	,1	,&A3IS12LDU},	//( - , DU) Приход на ВУ штока ИС1
	 163	,1	,1	,&A3IS21LDU},	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
	 164	,1	,1	,&A3IS22LDU},	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
	 165	,1	,1	,&A3IS31LDU},	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
	 166	,1	,1	,&A3IS33LDU},	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
	 167	,1	,1	,&A3IS35LDU},	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
	 168	,1	,1	,&A3MC01LC1},	//( - , DU) Настроить энкодер ИС1
	 169	,1	,1	,&A3MC01LC2},	//( - , DU) Настроить энкодер ИС1
	 170	,8	,1	,&A3MC01RDU},	//( - , DU) Заданная координата положения ИС от регулятора мм
	 171	,8	,1	,&A3MC01RP1},	//( - , DU) Заданная координата положения ИС1 мм
	 172	,8	,1	,&A3MC02RDU},	//( - , DU) Температурная корректировка координаты ИМ
	 173	,8	,1	,&A3MC03RDU},	//( - , DU) Координата положения ИМ 0-й реактивности
	 174	,1	,1	,&A3MD11LP1},	//( - , DU) Кнопка ПУСК ИС1
	 175	,1	,1	,&A3MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
	 176	,8	,1	,&A3VC01RDU},	//( - , DU) Координата ИС1, мм
	 177	,1	,1	,&A3VP42LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
	 178	,1	,1	,&A3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
	 179	,1	,1	,&A3VP81LDU},	//( - , - ) Давление СПУСК ИС1 в норме
	 180	,1	,1	,&A3VP82LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
	 181	,3	,1	,&A3VS01IDU},	//( - , DU) Готовность к управлению ИС1
	 182	,1	,1	,&A3VS12LDU},	//( - , DU) Движение ИС1 в сторону ВУ
	 183	,1	,1	,&A3VS22LDU},	//( - , DU) Движение ИС1 в сторону НУ
	 184	,1	,1	,&A3VX01LDU},	//( - , DU) Индикация Выстрел ИС1
	 185	,1	,1	,&A3VZ13LZ1},	//(vds32:02 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	 186	,1	,1	,&A3VZ13LZ2},	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	 187	,1	,1	,&A3VZ15LZ1},	//(vds32:02 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	 188	,1	,1	,&A3VZ15LZ2},	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	 189	,1	,1	,&A3ZAV},	//( - , DU) 
	 190	,1	,1	,&A4AB01LDU},	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
	 191	,1	,1	,&A4AB02LDU},	//( - , DU) Блокировка движения НИ1 - Нет перемещения
	 192	,1	,1	,&A4AD10LDU},	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
	 193	,1	,1	,&A4AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ1
	 194	,1	,1	,&A4DW},	//( - , DU) 
	 195	,1	,1	,&A4IS10LDU},	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
	 196	,1	,1	,&A4IS11LDU},	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
	 197	,1	,1	,&A4IS21LDU},	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
	 198	,1	,1	,&A4UP},	//( - , DU) 
	 199	,1	,1	,&A4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
	 200	,3	,1	,&A4VS01IDU},	//( - , DU) Готовность к управлению НИ1
	 201	,1	,1	,&A4VS12LDU},	//( - , DU) Движение НИ1 в сторону ВУ
	 202	,1	,1	,&A4VS22LDU},	//( - , DU) Движение НИ1 в сторону НУ
	 203	,1	,1	,&A4ZAV},	//( - , DU) 
	 204	,1	,1	,&A5AB01LDU},	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
	 205	,1	,1	,&A5AB02LDU},	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
	 206	,1	,1	,&A5AB04LDU},	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
	 207	,1	,1	,&A5AD10LDU},	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
	 208	,1	,1	,&A5AD20LDU},	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
	 209	,1	,1	,&A5AZ03LDU},	//( - , DU) Несанкционированное перемещение НЛ1
	 210	,1	,1	,&A5IE02LDU},	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
	 211	,1	,1	,&A5IS11LDU},	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
	 212	,1	,1	,&A5IS21LDU},	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
	 213	,3	,1	,&A5VS01IDU},	//( - , DU) Готовность к управлению НЛ1
	 214	,1	,1	,&A5VS12LDU},	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
	 215	,1	,1	,&A5VS22LDU},	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
	 216	,1	,1	,&A5ZAV},	//( - , DU) 
	 217	,1	,1	,&A6AB01LDU},	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
	 218	,1	,1	,&A6AB02LDU},	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
	 219	,1	,1	,&A6AB04LDU},	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
	 220	,1	,1	,&A6AB05LDU},	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
	 221	,1	,1	,&A6AB06LDU},	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
	 222	,1	,1	,&A6AB07LDU},	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
	 223	,1	,1	,&A6AB08LDU},	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
	 224	,1	,1	,&A6AB09LDU},	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
	 225	,1	,1	,&A6AD10LDU},	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
	 226	,1	,1	,&A6AD20LDU},	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
	 227	,1	,1	,&A6AZ03LDU},	//( - , DU) Несанкционированное перемещение БЗ1
	 228	,1	,1	,&A6IE01LDU},	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
	 229	,1	,1	,&A6IS11LDU},	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
	 230	,1	,1	,&A6IS21LDU},	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
	 231	,3	,1	,&A6VS01IDU},	//( - , DU) Готовность к управлению БЗ1
	 232	,1	,1	,&A6VS12LDU},	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
	 233	,1	,1	,&A6VS22LDU},	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
	 234	,1	,1	,&A6ZAV},	//( - , DU) 
	 235	,1	,1	,&A7AP31LDU},	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
	 236	,1	,1	,&A7AS31LDU},	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
	 237	,1	,1	,&A7AZ03LDU},	//( - , DU) Несанкционированное включение обдува АЗ1
	 238	,1	,1	,&A8AB01LDU},	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
	 239	,1	,1	,&A8AB02LDU},	//( - , DU) Блокировка движения ДС2- АНИ не установлен
	 240	,1	,1	,&A8AB04LDU},	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
	 241	,1	,1	,&A8AB05LDU},	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
	 242	,1	,1	,&A8AB06LDU},	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
	 243	,1	,1	,&A8AB07LDU},	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
	 244	,1	,1	,&A8AB08LDU},	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
	 245	,1	,1	,&A8AB09LDU},	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
	 246	,1	,1	,&A8AB10LDU},	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
	 247	,1	,1	,&A8AB11LDU},	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
	 248	,1	,1	,&A8AB12LDU},	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
	 249	,1	,1	,&A8AB13LDU},	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
	 250	,1	,1	,&A8AB14LDU},	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
	 251	,1	,1	,&A8AD10LDU},	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
	 252	,1	,1	,&A8AD20LDU},	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
	 253	,1	,1	,&A8AZ03LDU},	//( - , DU) Несанкционированное перемещение ДС2
	 254	,8	,1	,&A8CV01RDU},	//( - , DU) Измеренная скорость перемещения ДС2
	 255	,5	,1	,&A8IC01UDU},	//( - , MDuS) Координата ДС2 (дел.энк)
	 256	,1	,1	,&A8IE01LDU},	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
	 257	,1	,1	,&A8IS12LDU},	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
	 258	,1	,1	,&A8IS22LDU},	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
	 259	,1	,1	,&A8MC01LC1},	//( - , DU) Настроить энкодер ДС2
	 260	,1	,1	,&A8MC01LC2},	//( - , DU) Настроить энкодер ДС2
	 261	,8	,1	,&A8VC01RDU},	//( - , DU) Координата ДС2, мм
	 262	,3	,1	,&A8VS01IDU},	//( - , DU) Готовность к управлению ДС2
	 263	,1	,1	,&A8VS12LDU},	//( - , DU) Движение ДС2 в сторону ВУ
	 264	,1	,1	,&A8VS22LDU},	//( - , DU) Движение ДС2 в сторону НУ
	 265	,1	,1	,&A8ZAV},	//( - , DU) 
	 266	,1	,1	,&A9AB01LDU},	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
	 267	,1	,1	,&A9AB02LDU},	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
	 268	,1	,1	,&A9AD10LDU},	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
	 269	,1	,1	,&A9AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ ДС1
	 270	,1	,1	,&A9IS11LDU},	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
	 271	,1	,1	,&A9IS21LDU},	//(vds32:02 - K24VDSR, DU) Приход на НУ НИ ДС1
	 272	,1	,1	,&A9ZAV},	//( - , DU) Завершение НИ ДС1(2)
	 273	,8	,1	,&B0CT01IZ1},	//( - , MDuBz1) Температура АЗ2-1
	 274	,8	,1	,&B0CT01IZ2},	//( - , MDuBz2) Температура АЗ2-2
	 275	,1	,1	,&B0VE01LDU},	//( - , DU) Напряжение в системы АЗ2 подано
	 276	,1	,1	,&B0VN01LDU},	//( - , DU) Каналы АЗ2 проверены
	 277	,1	,1	,&B0VN71LZ1},	//( - , MDuBz1) АЗ по АС мощности для АЗ2
	 278	,1	,1	,&B0VN71LZ2},	//( - , MDuBz2) АЗ по АС мощности для АЗ2
	 279	,1	,1	,&B0VP01LDU},	//( - , DU) Давление в системы АЗ2 подано
	 280	,1	,1	,&B0VP71LZ1},	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
	 281	,1	,1	,&B0VP71LZ2},	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
	 282	,1	,1	,&B0VS11LDU},	//( - , DU) АЗ2 готова к работе
	 283	,1	,1	,&B0VT71LZ1},	//( - , MDuBz1) АС по температуре в АЗ2
	 284	,1	,1	,&B0VT71LZ2},	//( - , MDuBz2) АС по температуре в АЗ2
	 285	,1	,1	,&B1AB01LDU},	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
	 286	,1	,1	,&B1AB02LDU},	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
	 287	,1	,1	,&B1AB04LDU},	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
	 288	,1	,1	,&B1AB05LDU},	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
	 289	,1	,1	,&B1AB06LDU},	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
	 290	,1	,1	,&B1AB07LDU},	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
	 291	,1	,1	,&B1AB08LDU},	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
	 292	,1	,1	,&B1AB09LDU},	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
	 293	,1	,1	,&B1AB10LDU},	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
	 294	,1	,1	,&B1AB11LDU},	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
	 295	,1	,1	,&B1AB12LDU},	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	 296	,1	,1	,&B1AB13LDU},	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
	 297	,1	,1	,&B1AB14LDU},	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
	 298	,1	,1	,&B1AB16LDU},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
	 299	,1	,1	,&B1AB17LDU},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
	 300	,1	,1	,&B1AB18LDU},	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
	 301	,1	,1	,&B1AB19LDU},	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
	 302	,1	,1	,&B1AD01LDU},	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
	 303	,1	,1	,&B1AD02LDU},	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
	 304	,1	,1	,&B1AD03LDU},	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
	 305	,1	,1	,&B1AD04LDU},	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
	 306	,1	,1	,&B1AD05LDU},	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
	 307	,1	,1	,&B1AD11LDU},	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
	 308	,1	,1	,&B1AD21LDU},	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
	 309	,1	,1	,&B1AD31LDU},	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
	 310	,1	,1	,&B1AD32LDU},	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
	 311	,1	,1	,&B1AZ03LDU},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
	 312	,8	,1	,&B1CV01RDU},	//( - , DU) Измеренная скорость перемещения ББ2
	 313	,8	,1	,&B1CV02RDU},	//( - , DU) Заданная скорость перемещения ББ2
	 314	,5	,1	,&B1IC01UDU},	//( - , MDuS) Координата штока ББ2 (дел.энк)
	 315	,1	,1	,&B1IE01LDU},	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
	 316	,1	,1	,&B1IE02LDU},	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
	 317	,1	,1	,&B1IE03LDU},	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
	 318	,1	,1	,&B1IE04LDU},	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
	 319	,1	,1	,&B1IS11LDU},	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
	 320	,1	,1	,&B1IS12LDU},	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
	 321	,1	,1	,&B1IS21LDU},	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
	 322	,1	,1	,&B1MC01LC1},	//( - , DU) Настроить энкодер ББ2
	 323	,1	,1	,&B1MC01LC2},	//( - , DU) Настроить энкодер ББ2
	 324	,8	,1	,&B1MC01RP1},	//( - , DU) Заданная координата положения ББ2  мм
	 325	,1	,1	,&B1MD11LP1},	//( - , DU) Кнопка ПУСК ББ2
	 326	,1	,1	,&B1MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
	 327	,8	,1	,&B1VC01RDU},	//( - , DU) Координата ББ2, мм
	 328	,1	,1	,&B1VP41LZ1},	//( - , MDuBz1) Давление СБРОС ББ2 ниже АС
	 329	,1	,1	,&B1VP41LZ2},	//( - , MDuBz2) Давление СБРОС ББ2 ниже АС
	 330	,3	,1	,&B1VS01IDU},	//( - , DU) Готовность к управлению ББ2
	 331	,1	,1	,&B1VS12LDU},	//( - , DU) Движение ББ2 в сторону ВУ
	 332	,1	,1	,&B1VS22LDU},	//( - , DU) Движение ББ2 в сторону НУ
	 333	,1	,1	,&B2AB01LDU},	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
	 334	,1	,1	,&B2AB02LDU},	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
	 335	,1	,1	,&B2AB04LDU},	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
	 336	,1	,1	,&B2AB05LDU},	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
	 337	,1	,1	,&B2AB06LDU},	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
	 338	,1	,1	,&B2AB07LDU},	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
	 339	,1	,1	,&B2AB08LDU},	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
	 340	,1	,1	,&B2AB09LDU},	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
	 341	,1	,1	,&B2AB10LDU},	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
	 342	,1	,1	,&B2AB11LDU},	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
	 343	,1	,1	,&B2AB12LDU},	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	 344	,1	,1	,&B2AB13LDU},	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
	 345	,1	,1	,&B2AB14LDU},	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
	 346	,1	,1	,&B2AB15LDU},	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	 347	,1	,1	,&B2AB16LDU},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
	 348	,1	,1	,&B2AB17LDU},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
	 349	,1	,1	,&B2AD01LDU},	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
	 350	,1	,1	,&B2AD02LDU},	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
	 351	,1	,1	,&B2AD03LDU},	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
	 352	,1	,1	,&B2AD04LDU},	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
	 353	,1	,1	,&B2AD05LDU},	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
	 354	,1	,1	,&B2AD11LDU},	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
	 355	,1	,1	,&B2AD21LDU},	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
	 356	,1	,1	,&B2AD31LDU},	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
	 357	,1	,1	,&B2AD32LDU},	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
	 358	,1	,1	,&B2AD33LDU},	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
	 359	,1	,1	,&B2AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
	 360	,8	,1	,&B2CV01RDU},	//( - , DU) Измеренная скорость перемещения РБ2
	 361	,8	,1	,&B2CV02RDU},	//( - , DU) Заданная скорость перемещения РБ2
	 362	,5	,1	,&B2IC01UDU},	//( - , MDuS) Координата штока РБ2 (дел.энк)
	 363	,1	,1	,&B2IE01LDU},	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
	 364	,1	,1	,&B2IE02LDU},	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
	 365	,1	,1	,&B2IE03LDU},	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
	 366	,1	,1	,&B2IE04LDU},	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
	 367	,1	,1	,&B2IS11LDU},	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
	 368	,1	,1	,&B2IS12LDU},	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
	 369	,1	,1	,&B2IS21LDU},	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
	 370	,1	,1	,&B2IS33LDU},	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
	 371	,1	,1	,&B2MC01LC1},	//( - , DU) Настроить энкодер РБ2
	 372	,1	,1	,&B2MC01LC2},	//( - , DU) Настроить энкодер РБ2
	 373	,1	,1	,&B2MD11LP1},	//( - , DU) Кнопка ПУСК РБ2
	 374	,1	,1	,&B2MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
	 375	,8	,1	,&B2VC01RDU},	//( - , DU) Координата РБ2, мм
	 376	,1	,1	,&B2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
	 377	,3	,1	,&B2VS01IDU},	//( - , DU) Готовность к управлению РБ2
	 378	,1	,1	,&B2VS11LDU},	//( - , DU) Движение РБ2 в сторону ВУ
	 379	,1	,1	,&B2VS21LDU},	//( - , DU) Движение РБ2 в сторону НУ
	 380	,1	,1	,&B2VS32LDU},	//( - , DU) Индикация  СБРОС РБ2
	 381	,1	,1	,&B3AB01LDU},	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
	 382	,1	,1	,&B3AB02LDU},	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
	 383	,1	,1	,&B3AB04LDU},	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
	 384	,1	,1	,&B3AB05LDU},	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
	 385	,1	,1	,&B3AB06LDU},	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
	 386	,1	,1	,&B3AB07LDU},	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
	 387	,1	,1	,&B3AB08LDU},	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
	 388	,1	,1	,&B3AB09LDU},	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
	 389	,1	,1	,&B3AB10LDU},	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
	 390	,1	,1	,&B3AB11LDU},	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
	 391	,1	,1	,&B3AB12LDU},	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	 392	,1	,1	,&B3AB13LDU},	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
	 393	,1	,1	,&B3AB14LDU},	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
	 394	,1	,1	,&B3AB15LDU},	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
	 395	,1	,1	,&B3AB16LDU},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
	 396	,1	,1	,&B3AB17LDU},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
	 397	,1	,1	,&B3AB18LDU},	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
	 398	,1	,1	,&B3AB19LDU},	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
	 399	,1	,1	,&B3AB20LDU},	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
	 400	,1	,1	,&B3AD01LDU},	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
	 401	,1	,1	,&B3AD02LDU},	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
	 402	,1	,1	,&B3AD03LDU},	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
	 403	,1	,1	,&B3AD04LDU},	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
	 404	,1	,1	,&B3AD05LDU},	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
	 405	,1	,1	,&B3AD11LDU},	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
	 406	,1	,1	,&B3AD21LDU},	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
	 407	,1	,1	,&B3AD31LDU},	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
	 408	,1	,1	,&B3AD33LDU},	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
	 409	,1	,1	,&B3AD34LDU},	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
	 410	,1	,1	,&B3AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
	 411	,8	,1	,&B3CP02RDU},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
	 412	,8	,1	,&B3CV01RDU},	//( - , DU) Измеренная скорость перемещения ИС2
	 413	,8	,1	,&B3CV02RDU},	//( - , DU) Заданная скорость перемещения ИС2
	 414	,1	,1	,&B3EE03LDU},	//( - , DU) ВПИС ИС2
	 415	,5	,1	,&B3IC01UDU},	//( - , MDuS) Координата штока ИС2 (дел.энк)
	 416	,1	,1	,&B3IE01LDU},	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
	 417	,1	,1	,&B3IE02LDU},	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
	 418	,1	,1	,&B3IE03LDU},	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
	 419	,1	,1	,&B3IE04LDU},	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
	 420	,3	,1	,&B3IP02IDU},	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
	 421	,1	,1	,&B3IS11LDU},	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
	 422	,1	,1	,&B3IS12LDU},	//( - , DU) Приход на ВУ штока ИС2
	 423	,1	,1	,&B3IS21LDU},	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
	 424	,1	,1	,&B3IS22LDU},	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
	 425	,1	,1	,&B3IS31LDU},	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
	 426	,1	,1	,&B3IS33LDU},	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
	 427	,1	,1	,&B3IS35LDU},	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
	 428	,1	,1	,&B3MC01LC1},	//( - , DU) Настроить энкодер ИС2
	 429	,1	,1	,&B3MC01LC2},	//( - , DU) Настроить энкодер ИС2
	 430	,8	,1	,&B3MC01RP1},	//( - , DU) Заданная координата положения ИС2 мм
	 431	,1	,1	,&B3MD11LP1},	//( - , DU) Кнопка ПУСК ИС2
	 432	,1	,1	,&B3MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
	 433	,8	,1	,&B3VC01RDU},	//( - , DU) Координата ИС2, мм
	 434	,1	,1	,&B3VP42LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
	 435	,1	,1	,&B3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
	 436	,1	,1	,&B3VP81LDU},	//( - , - ) Давление СПУСК ИС2 в норме
	 437	,1	,1	,&B3VP82LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
	 438	,3	,1	,&B3VS01IDU},	//( - , DU) Готовность к управлению ИС2
	 439	,1	,1	,&B3VS12LDU},	//( - , DU) Движение ИС2 в сторону ВУ
	 440	,1	,1	,&B3VS22LDU},	//( - , DU) Движение ИС2 в сторону НУ
	 441	,1	,1	,&B3VX01LDU},	//( - , DU) Индикация Выстрел ИС2
	 442	,1	,1	,&B4AB01LDU},	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
	 443	,1	,1	,&B4AB02LDU},	//( - , DU) Блокировка движения НИ2 - Нет перемещения
	 444	,1	,1	,&B4AD10LDU},	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
	 445	,1	,1	,&B4AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ2
	 446	,1	,1	,&B4IS10LDU},	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
	 447	,1	,1	,&B4IS11LDU},	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
	 448	,1	,1	,&B4IS21LDU},	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
	 449	,1	,1	,&B4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
	 450	,3	,1	,&B4VS01IDU},	//( - , DU) Готовность к управлению НИ2
	 451	,1	,1	,&B4VS12LDU},	//( - , DU) Движение НИ2 в сторону ВУ
	 452	,1	,1	,&B4VS22LDU},	//( - , DU) Движение НИ2 в сторону НУ
	 453	,1	,1	,&B5AB01LDU},	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
	 454	,1	,1	,&B5AB02LDU},	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
	 455	,1	,1	,&B5AB04LDU},	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
	 456	,1	,1	,&B5AD10LDU},	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
	 457	,1	,1	,&B5AD20LDU},	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
	 458	,1	,1	,&B5AZ03LDU},	//( - , DU) Несанкционированное перемещение НЛ2
	 459	,1	,1	,&B5IE01LDU},	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
	 460	,1	,1	,&B5IS11LDU},	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
	 461	,1	,1	,&B5IS21LDU},	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
	 462	,3	,1	,&B5VS01IDU},	//( - , DU) Готовность к управлению НЛ2
	 463	,1	,1	,&B5VS12LDU},	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
	 464	,1	,1	,&B5VS22LDU},	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
	 465	,1	,1	,&B6AB01LDU},	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
	 466	,1	,1	,&B6AB02LDU},	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
	 467	,1	,1	,&B6AB04LDU},	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
	 468	,1	,1	,&B6AB05LDU},	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
	 469	,1	,1	,&B6AB06LDU},	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
	 470	,1	,1	,&B6AB07LDU},	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
	 471	,1	,1	,&B6AB08LDU},	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
	 472	,1	,1	,&B6AB09LDU},	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
	 473	,1	,1	,&B6AD10LDU},	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
	 474	,1	,1	,&B6AD20LDU},	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
	 475	,1	,1	,&B6AZ03LDU},	//( - , DU) Несанкционированное перемещение БЗ2
	 476	,1	,1	,&B6IE01LDU},	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
	 477	,1	,1	,&B6IS11LDU},	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
	 478	,1	,1	,&B6IS21LDU},	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
	 479	,3	,1	,&B6VS01IDU},	//( - , DU) Готовность к управлению БЗ2
	 480	,1	,1	,&B6VS12LDU},	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
	 481	,1	,1	,&B6VS22LDU},	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
	 482	,1	,1	,&B7AP31LDU},	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
	 483	,1	,1	,&B7AS31LDU},	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
	 484	,1	,1	,&B7AZ03LDU},	//( - , DU) Несанкционированное включение обдува АЗ2
	 485	,1	,1	,&B8AB01LDU},	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
	 486	,1	,1	,&B8AB02LDU},	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
	 487	,1	,1	,&B8AB04LDU},	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
	 488	,1	,1	,&B8AB05LDU},	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
	 489	,1	,1	,&B8AB06LDU},	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
	 490	,1	,1	,&B8AB07LDU},	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
	 491	,1	,1	,&B8AB08LDU},	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
	 492	,1	,1	,&B8AB09LDU},	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
	 493	,1	,1	,&B8AB10LDU},	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
	 494	,1	,1	,&B8AB11LDU},	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
	 495	,1	,1	,&B8AB12LDU},	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
	 496	,1	,1	,&B8AB13LDU},	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
	 497	,1	,1	,&B8AB14LDU},	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
	 498	,1	,1	,&B8AD10LDU},	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
	 499	,1	,1	,&B8AD20LDU},	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
	 500	,1	,1	,&B8AZ03LDU},	//( - , DU) Несанкционированное перемещение АЗ2
	 501	,8	,1	,&B8CV01RDU},	//( - , DU) Измеренная скорость перемещения АЗ2
	 502	,5	,1	,&B8IC01UDU},	//( - , MDuS) Координата АЗ2 (дел.энк)
	 503	,1	,1	,&B8IS11LDU},	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
	 504	,1	,1	,&B8IS12LDU},	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
	 505	,1	,1	,&B8IS21LDU},	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
	 506	,1	,1	,&B8IS22LDU},	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
	 507	,1	,1	,&B8MC01LC1},	//( - , DU) Настроить энкодер АЗ2
	 508	,1	,1	,&B8MC01LC2},	//( - , DU) Настроить энкодер АЗ2
	 509	,8	,1	,&B8MC01RP2},	//( - , DU) Заданная координата АЗ2 мм
	 510	,8	,1	,&B8VC01RDU},	//( - , DU, MDuBz1, MDuBz2) Координата АЗ2, мм
	 511	,3	,1	,&B8VS01IDU},	//( - , DU) Готовность к управлению АЗ2
	 512	,1	,1	,&B8VS12LDU},	//( - , DU) Движение АЗ2 в сторону ВУ
	 513	,1	,1	,&B8VS22LDU},	//( - , DU) Движение АЗ2 в сторону НУ
	 514	,1	,1	,&B8ZAV},	//( - , DU) 
	 515	,1	,1	,&B9AB01LDU},	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
	 516	,1	,1	,&B9AB02LDU},	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
	 517	,1	,1	,&B9AD10LDU},	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
	 518	,1	,1	,&B9AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ ДС2
	 519	,1	,1	,&B9IS11LDU},	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
	 520	,1	,1	,&B9IS21LDU},	//(vds32:02 - K26VDSR, DU) Приход на НУ НИ ДС2
	 521	,1	,1	,&C1MD31LP1},	//( - , DU) Кнопка СБРОС ББ
	 522	,1	,1	,&C1MD31LP2},	//( - , DU) Кнопка СБРОС ББ
	 523	,1	,1	,&C2MD31LP1},	//( - , DU) Кнопка СБРОС РБ
	 524	,1	,1	,&R0AB01LDU},	//( - , DU) Режим проверки разрешён
	 525	,1	,1	,&R0AB02LDU},	//( - , DU) Нарушение времени задержки ИНИ
	 526	,1	,1	,&R0AB03LDU},	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
	 527	,1	,1	,&R0AB04LDU},	//( - , DU) Нарушение времени срабатывания верхней АС II УР
	 528	,1	,1	,&R0AB05LDU},	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
	 529	,1	,1	,&R0AB06LDU},	//( - , DU) Нарушение времени задержки от ВУ РБ
	 530	,1	,1	,&R0AB07LDU},	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
	 531	,1	,1	,&R0AB08LDU},	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
	 532	,1	,1	,&R0AB09LDU},	//( - , DU) Ошибка в заданной координате ББ1
	 533	,1	,1	,&R0AB10LDU},	//( - , DU) Ошибка в заданной координате ББ2
	 534	,1	,1	,&R0AB11LDU},	//( - , DU) Ошибка в заданной координате  ИС1
	 535	,1	,1	,&R0AB12LDU},	//( - , DU) Ошибка в заданной координате  ИС2
	 536	,1	,1	,&R0AB13LDU},	//( - , DU) Ошибка в заданной координате  АЗ2
	 537	,1	,1	,&R0AB14LDU},	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
	 538	,1	,1	,&R0AB15LDU},	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
	 539	,1	,1	,&R0AB16LDU},	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
	 540	,1	,1	,&R0AB17LDU},	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
	 541	,1	,1	,&R0AB18LDU},	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
	 542	,1	,1	,&R0AB19LDU},	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
	 543	,1	,1	,&R0AB20LDU},	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
	 544	,1	,1	,&R0AD03LZ1},	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
	 545	,1	,1	,&R0AD03LZ2},	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
	 546	,1	,1	,&R0AD04LZ1},	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
	 547	,1	,1	,&R0AD04LZ2},	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
	 548	,1	,1	,&R0AD05LZ1},	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
	 549	,1	,1	,&R0AD05LZ2},	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
	 550	,1	,1	,&R0AD14LZ1},	//(vds32:02 - K20VDSR, DU) Имитация срабатывания АЗ от II УР
	 551	,1	,1	,&R0AD14LZ2},	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
	 552	,1	,1	,&R0AD16LDU},	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
	 553	,1	,1	,&R0AD21LDU},	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
	 554	,8	,1	,&R0CN91LDU},	//( - , DU) Рассчётная реактивность от регулятора
	 555	,8	,1	,&R0CN92LDU},	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
	 556	,8	,1	,&R0CN93LDU},	//( - , DU) время работы на мощности более 100Вт, сек
	 557	,8	,1	,&R0CN94LDU},	//( - , DU) Скорость изменения мощности
	 558	,3	,1	,&R0CN95LDU},	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
	 559	,3	,1	,&R0DE01LDU},	//(vencf8l:01 - DiagnVDS, DiagnDU) диагностика модуля ДУ на 1 месте
	 560	,3	,1	,&R0DE02LDU},	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
	 561	,3	,1	,&R0DE03LDU},	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
	 562	,3	,1	,&R0DE04LDU},	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
	 563	,3	,1	,&R0DE05LDU},	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
	 564	,3	,1	,&R0DE06LDU},	//(vencf8l:01 - DiagnFDS, DiagnDU) диагностика модуля ДУ на 6 месте
	 565	,3	,1	,&R0DE07LDU},	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
	 566	,3	,1	,&R0DE08LDU},	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
	 567	,3	,1	,&R0DE09LDU},	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
	 568	,3	,1	,&R0DE0ALDU},	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
	 569	,3	,1	,&R0DE0BLDU},	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
	 570	,3	,1	,&R0DE0CLDU},	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
	 571	,3	,1	,&R0DE0DLDU},	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
	 572	,3	,1	,&R0DE0FLDU},	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
	 573	,1	,1	,&R0DE3CLDU},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
	 574	,1	,1	,&R0DE3DLDU},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
	 575	,1	,1	,&R0DEB1LDU},	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
	 576	,1	,1	,&R0DEB2LDU},	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
	 577	,1	,1	,&R0DEB3LDU},	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
	 578	,1	,1	,&R0DEB4LDU},	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
	 579	,1	,1	,&R0EE02LDU},	//( - , DU) Питание  АКНП  отключить
	 580	,1	,1	,&R0EE03LDU},	//( - , DU) ВПИС ИС
	 581	,1	,1	,&R0ES01LDU},	//( - , DU) ОРР не в исходном состоянии
	 582	,1	,1	,&R0IE01LDU},	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
	 583	,1	,1	,&R0IE02LDU},	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
	 584	,1	,1	,&R0IS01LDU},	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
	 585	,1	,1	,&R0IS02LDU},	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
	 586	,1	,1	,&R0MD11LP1},	//( - , DU) Кнопка ПУСК
	 587	,1	,1	,&R0MD11LP2},	//( - , DU) Кнопка Пуск проверки схем сброса
	 588	,1	,1	,&R0MD31LP1},	//( - , DU) Кнопка СТОП
	 589	,1	,1	,&R0MD32LP1},	//( - , DU) Кнопка СПУСК
	 590	,1	,1	,&R0MD33LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
	 591	,1	,1	,&R0MD34LP1},	//( - , DU) Кнопка КВИТИРОВАТЬ
	 592	,3	,1	,&R0MW11IP1},	//( - , DU) Переключатель ВЫСТРЕЛ
	 593	,3	,1	,&R0MW11IP2},	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
	 594	,3	,1	,&R0MW12IP1},	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
	 595	,3	,1	,&R0MW12IP2},	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
	 596	,3	,1	,&R0MW13IP1},	//( - , DU) Переключатель ВЫБОР ЗОН
	 597	,1	,1	,&R0MW13LP2},	//( - , DU) Переключатель СЕТЬ
	 598	,3	,1	,&R0MW14IP1},	//( - , DU) Переключатель ПРОГРАММЫ
	 599	,3	,1	,&R0MW14IP2},	//( - , DU) Переключатель ОБДУВ
	 600	,3	,1	,&R0MW15IP1},	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
	 601	,3	,1	,&R0MW16IP1},	//( - , DU) Переключатель ВИД ПРОВЕРКИ
	 602	,1	,1	,&R0MW17LP1},	//( - , DU) Переключатель АВТ/Р
	 603	,1	,1	,&R0NE01LDU},	//( - , DU) Потеря связи с БАЗ1
	 604	,1	,1	,&R0NE02LDU},	//( - , DU) Потеря связи с БАЗ2
	 605	,1	,1	,&R0NE08LDU},	//( - , DU) Потеря связи с ОПУ
	 606	,1	,1	,&R0S01LDU},	//( - , - ) Отключение сетевых передач ДУ
	 607	,1	,1	,&R0S01LIM},	//(fds16:08 - K15FDSR, - ) Отключение сетевых передач ПТИ
	 608	,1	,1	,&R0S01LZ1},	//(fds16:07 - K15FDSR, - ) Отключение сетевых передач в Баз1
	 609	,1	,1	,&R0S01LZ2},	//(fds16:07 - K16FDSR, - ) Отключение сетевых передач в Баз2
	 610	,3	,1	,&R0VL01IDU},	//( - , DU) До импульса минут
	 611	,8	,1	,&R0VL01RDU},	//( - , DU) Индикация Время задержки
	 612	,8	,1	,&R0VL02RDU},	//( - , DU) Индикация (Время задержки ИНИ)
	 613	,8	,1	,&R0VL03RDU},	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
	 614	,8	,1	,&R0VL04RDU},	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
	 615	,8	,1	,&R0VL05RDU},	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
	 616	,8	,1	,&R0VL06RDU},	//( - , DU) Индикация (Время задержки от ВУ РБ)
	 617	,3	,1	,&R0VL11IDU},	//( - , DU) До импульса секунд
	 618	,3	,1	,&R0VL21IDU},	//( - , DU) Декатрон
	 619	,1	,1	,&R0VL22LDU},	//( - , DU) Конец программы 200сек
	 620	,1	,1	,&R0VL23LDU},	//( - , DU) Конец программы 20мин
	 621	,8	,1	,&R0VN11RDU},	//( - , DU) Текущая мощность РУ
	 622	,8	,1	,&R0VN11RZ1},	//( - , MDuBz1) Средняя мощность по BAZ1
	 623	,8	,1	,&R0VN11RZ2},	//( - , MDuBz2) Средняя мощность по BAZ2
	 624	,8	,1	,&R0VN12RDU},	//( - , DU) Заданная мощность РУ
	 625	,8	,1	,&R0VN15RDU},	//( - , DU) Период разгона РУ
	 626	,1	,1	,&R0VP73LDU},	//( - , DU) ПС давления для РУ
	 627	,1	,1	,&R0VP73LZ1},	//( - , MDuBz1) ПС давления для РУ
	 628	,1	,1	,&R0VP73LZ2},	//( - , MDuBz2) ПС давления для РУ
	 629	,1	,1	,&R0VS11LDU},	//( - , DU) РУ не готова к работе
	 630	,1	,1	,&R0VS17LDU},	//( - , DU) Индикация выбора АВТОМАТ
	 631	,1	,1	,&R0VS18LDU},	//( - , DU) Индикация  Проверка схем сброса
	 632	,3	,1	,&R0VS21IDU},	//( - , DU) Индикация ВИД ПРОВЕРКИ
	 633	,1	,1	,&R0VW13LDU},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
	 634	,1	,1	,&R0VW23LDU},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
	 635	,1	,1	,&R0VX01LDU},	//( - , DU) ДО ИМПУЛЬСА
	 636	,1	,1	,&R0VX02LDU},	//( - , DU) Импульс разрешен
	 637	,1	,1	,&R0VX03LDU},	//( - , DU) Готовность 2 мин
	 638	,3	,1	,&R0VX08IDU},	//( - , DU) Индикация Режим
	 639	,1	,1	,&R0VX09LDU},	//( - , DU) Индикация регулятор мощности включен/отключен
	 640	,1	,1	,&R0VZ71LDU},	//( - , DU) Обобщенный сигнал АЗ
	 641	,1	,1	,&R0VZ71LZ1},	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
	 642	,1	,1	,&R0VZ71LZ2},	//(vds32:03 - K22VDSR, - ) Обобщенный сигнал АЗ 2 канала
	 643	,1	,1	,&R1AB01LDU},	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
	 644	,1	,1	,&R1AB02LDU},	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
	 645	,1	,1	,&R1AB04LDU},	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
	 646	,1	,1	,&R1AD10LDU},	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
	 647	,1	,1	,&R1AD20LDU},	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
	 648	,1	,1	,&R1AZ03LDU},	//( - , DU) Несанкционированное перемещение МДЗ1
	 649	,1	,1	,&R1IE01LDU},	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
	 650	,1	,1	,&R1IS11LDU},	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
	 651	,1	,1	,&R1IS21LDU},	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
	 652	,3	,1	,&R1VS01IDU},	//( - , DU) Готовность к управлению МДЗ1
	 653	,1	,1	,&R1VS12LDU},	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
	 654	,1	,1	,&R1VS22LDU},	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
	 655	,1	,1	,&R2AB01LDU},	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
	 656	,1	,1	,&R2AB02LDU},	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
	 657	,1	,1	,&R2AB04LDU},	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
	 658	,1	,1	,&R2AD10LDU},	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
	 659	,1	,1	,&R2AD20LDU},	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
	 660	,1	,1	,&R2AZ03LDU},	//( - , DU) Несанкционированное перемещение МДЗ2
	 661	,1	,1	,&R2IE01LDU},	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
	 662	,1	,1	,&R2IS11LDU},	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
	 663	,1	,1	,&R2IS21LDU},	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
	 664	,3	,1	,&R2VS01IDU},	//( - , DU) Готовность к управлению МДЗ2
	 665	,1	,1	,&R2VS12LDU},	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
	 666	,1	,1	,&R2VS22LDU},	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
	 667	,1	,1	,&R2ZAV},	//( - , DU) 
	 668	,1	,1	,&R3IS11LDU},	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
	 669	,1	,1	,&R3IS21LDU},	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
	 670	,3	,1	,&R3VS01IDU},	//( - , DU) Готовность к управлению гомогенных дверей
	 671	,1	,1	,&R3VS12LDU},	//( - , DU) Движение гомогенных дверей к открыты
	 672	,1	,1	,&R3VS22LDU},	//( - , DU) Движение гомогенных дверей к закрыты
	 673	,1	,1	,&R4AB01LDU},	//( - , DU) Блокировка движения тележки - АНИ не установлен
	 674	,1	,1	,&R4AB02LDU},	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
	 675	,1	,1	,&R4AB03LDU},	//( - , DU) Блокировка движения тележки - Самоход любого механизма
	 676	,1	,1	,&R4AB04LDU},	//( - , DU) Блокировка движения тележки - Превышение времени движения
	 677	,1	,1	,&R4AB05LDU},	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
	 678	,1	,1	,&R4AB06LDU},	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
	 679	,1	,1	,&R4AB07LDU},	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
	 680	,1	,1	,&R4AB08LDU},	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
	 681	,1	,1	,&R4AB09LDU},	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
	 682	,1	,1	,&R4AB10LDU},	//( - , DU) Блокировка тележки - не открыта биологическая защита
	 683	,1	,1	,&R4AB11LDU},	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
	 684	,1	,1	,&R4AB12LDU},	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
	 685	,1	,1	,&R4AB13LDU},	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
	 686	,1	,1	,&R4AB14LDU},	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
	 687	,1	,1	,&R4AB15LDU},	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
	 688	,1	,1	,&R4AB16LDU},	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
	 689	,1	,1	,&R4AB17LDU},	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
	 690	,1	,1	,&R4AB18LDU},	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
	 691	,1	,1	,&R4ABL},	//( - , DU) Блокировка тележки -
	 692	,1	,1	,&R4AD10LDU},	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
	 693	,1	,1	,&R4AD20LDU},	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
	 694	,1	,1	,&R4AZ03LDU},	//( - , DU) Несанкционированное перемещение тележки
	 695	,1	,1	,&R4IS11LDU},	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
	 696	,1	,1	,&R4IS12LDU},	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
	 697	,1	,1	,&R4IS21LDU},	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
	 698	,1	,1	,&R4IS22LDU},	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
	 699	,1	,1	,&R4MD11LP2},	//( - , DU) Кнопка ВПЕРЁД  (тележки)
	 700	,1	,1	,&R4MD21LP2},	//( - , DU) Кнопка НАЗАД  (тележки)
	 701	,1	,1	,&R4MD31LP2},	//( - , DU) Кнопка СТОП  (тележки)
	 702	,3	,1	,&R4VS01IDU},	//( - , DU) Готовность к управлению тележкой реактора
	 703	,1	,1	,&R4VS12LDU},	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
	 704	,1	,1	,&R4VS22LDU},	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
	 705	,1	,1	,&R5IS11LDU},	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
	 706	,1	,1	,&R5IS21LDU},	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
	 707	,3	,1	,&R5VS01IDU},	//( - , DU) Готовность к управлению ворот отстойной зоны
	 708	,1	,1	,&R5VS12LDU},	//( - , DU) Движение ворот отстойной зоны к открыты
	 709	,1	,1	,&R5VS22LDU},	//( - , DU) Движение ворот отстойной зоны к закрыты
	 710	,1	,1	,&R6IS21LDU},	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
	 711	,1	,1	,&R6IS31LDU},	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
	 712	,1	,1	,&R6IS32LDU},	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
	 713	,1	,1	,&R6IS41LDU},	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
	 714	,1	,1	,&R6IS42LDU},	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
	 715	,1	,1	,&R6IS51LDU},	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
	 716	,1	,1	,&R6IS52LDU},	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
	 717	,1	,1	,&R6IS61LDU},	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
	 718	,1	,1	,&R6IS66LZZ},	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	 719	,1	,1	,&R6IS67LZZ},	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	 720	,1	,1	,&R6IS68LZZ},	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
	 721	,1	,1	,&R8AD21LDU},	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
	 722	,1	,1	,&R8AD22LDU},	//(vds32:02 - K15VDSR, - ) Сигнал синхронизации с импульсом
	 723	,1	,1	,&R8IS11LDU},	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
	 724	,3	,1	,&TTLDU},	//( - , DU) ttl
	 725	,1	,1	,&TestDiagnDU},	//( - , DU) Неисправность от
	 726	,1	,1	,&bFirstEnterFlag},	//(bFirstEnterFlag) 
	 727	,5	,1	,&dEM_A1UC05UDU},	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
	 728	,5	,1	,&dEM_A1UC06UDU},	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
	 729	,5	,1	,&dEM_A2UC05UDU},	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
	 730	,5	,1	,&dEM_A2UC06UDU},	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
	 731	,5	,1	,&dEM_A3UC05UDU},	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
	 732	,5	,1	,&dEM_A3UC06UDU},	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
	 733	,5	,1	,&dEM_A8UC05UDU},	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
	 734	,5	,1	,&dEM_A8UC06UDU},	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
	 735	,8	,1	,&fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
	 736	,8	,1	,&fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
	 737	,8	,1	,&fEM_A1UC05RDU},	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
	 738	,8	,1	,&fEM_A1UC06RDU},	//(A1UC06RDU) Уставка определения самохода ББ  мм
	 739	,8	,1	,&fEM_A1UC07RDU},	//(A1UC07RDU) Зона возврата при наведении ББ мм
	 740	,8	,1	,&fEM_A1UC08RDU},	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
	 741	,8	,1	,&fEM_A1UC81RDU},	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
	 742	,8	,1	,&fEM_A1UC82RDU},	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
	 743	,8	,1	,&fEM_A1UC83RDU},	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
	 744	,8	,1	,&fEM_A1UL01RDU},	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	 745	,8	,1	,&fEM_A1UL03RDU},	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
	 746	,8	,1	,&fEM_A1UL04RDU},	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
	 747	,8	,1	,&fEM_A1UL05RDU},	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
	 748	,8	,1	,&fEM_A1UV01RDU},	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
	 749	,8	,1	,&fEM_A1UV02RDU},	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
	 750	,8	,1	,&fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
	 751	,8	,1	,&fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
	 752	,8	,1	,&fEM_A2UC05RDU},	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
	 753	,8	,1	,&fEM_A2UC06RDU},	//(A2UC06RDU) Уставка определения самохода РБ  мм
	 754	,8	,1	,&fEM_A2UC07RDU},	//(A2UC07RDU) Зона возврата при наведении РБ  мм
	 755	,8	,1	,&fEM_A2UC08RDU},	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
	 756	,8	,1	,&fEM_A2UC81RDU},	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
	 757	,8	,1	,&fEM_A2UC82RDU},	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
	 758	,8	,1	,&fEM_A2UC83RDU},	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
	 759	,8	,1	,&fEM_A2UL01RDU},	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	 760	,8	,1	,&fEM_A2UL03RDU},	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	 761	,8	,1	,&fEM_A2UL04RDU},	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
	 762	,8	,1	,&fEM_A2UL05RDU},	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
	 763	,8	,1	,&fEM_A2UL83RDU},	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	 764	,8	,1	,&fEM_A2UV01RDU},	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
	 765	,8	,1	,&fEM_A2UV02RDU},	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
	 766	,8	,1	,&fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
	 767	,8	,1	,&fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
	 768	,8	,1	,&fEM_A3UC05RDU},	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
	 769	,8	,1	,&fEM_A3UC06RDU},	//(A3UC06RDU) Уставка определения самохода ИС1  мм
	 770	,8	,1	,&fEM_A3UC07RDU},	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
	 771	,8	,1	,&fEM_A3UC08RDU},	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
	 772	,8	,1	,&fEM_A3UC09RDU},	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
	 773	,8	,1	,&fEM_A3UC81RDU},	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
	 774	,8	,1	,&fEM_A3UC82RDU},	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
	 775	,8	,1	,&fEM_A3UL01RDU},	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	 776	,8	,1	,&fEM_A3UL03RDU},	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
	 777	,8	,1	,&fEM_A3UL04RDU},	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
	 778	,8	,1	,&fEM_A3UL05RDU},	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
	 779	,8	,1	,&fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	 780	,8	,1	,&fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	 781	,8	,1	,&fEM_A3UP43RDU},	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
	 782	,8	,1	,&fEM_A3UP44RDU},	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
	 783	,8	,1	,&fEM_A3UP53RDU},	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
	 784	,8	,1	,&fEM_A3UP54RDU},	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
	 785	,8	,1	,&fEM_A3UP85RDU},	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	 786	,8	,1	,&fEM_A3UP86RDU},	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	 787	,8	,1	,&fEM_A3UP87RDU},	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	 788	,8	,1	,&fEM_A3UP88RDU},	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	 789	,8	,1	,&fEM_A3UV01RDU},	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
	 790	,8	,1	,&fEM_A3UV02RDU},	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
	 791	,8	,1	,&fEM_A4UZ03RDU},	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
	 792	,8	,1	,&fEM_A4UZ04RDU},	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
	 793	,8	,1	,&fEM_A4UZ05RDU},	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
	 794	,8	,1	,&fEM_A5UZ03RDU},	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
	 795	,8	,1	,&fEM_A5UZ04RDU},	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
	 796	,8	,1	,&fEM_A5UZ05RDU},	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
	 797	,8	,1	,&fEM_A6UZ03RDU},	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
	 798	,8	,1	,&fEM_A6UZ04RDU},	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
	 799	,8	,1	,&fEM_A6UZ05RDU},	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
	 800	,8	,1	,&fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
	 801	,8	,1	,&fEM_A9UZ03RDU},	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
	 802	,8	,1	,&fEM_A9UZ04RDU},	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
	 803	,8	,1	,&fEM_A9UZ05RDU},	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
	 804	,8	,1	,&fEM_B8UC01RDU},	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
	 805	,8	,1	,&fEM_B8UC02RDU},	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
	 806	,8	,1	,&fEM_B8UC05RDU},	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
	 807	,8	,1	,&fEM_B8UC06RDU},	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
	 808	,8	,1	,&fEM_B8UL01RDU},	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	 809	,8	,1	,&fEM_B8UL03RDU},	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
	 810	,8	,1	,&fEM_B8UL04RDU},	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
	 811	,8	,1	,&fEM_B8UL05RDU},	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
	 812	,8	,1	,&fEM_B8UL06RDU},	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
	 813	,8	,1	,&fEM_B8UL07RDU},	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
	 814	,8	,1	,&fEM_B8UV01RDU},	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
	 815	,8	,1	,&fEM_B8UV02RDU},	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
	 816	,8	,1	,&fEM_B8UV03RDU},	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
	 817	,8	,1	,&fEM_B8UV04RDU},	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
	 818	,8	,1	,&fEM_R0UL00RDU},	//(R0UL00RDU) Время ожидания передачи  сигнала отключения сети
	 819	,8	,1	,&fEM_R0UL01RSS},	//(R0UL01RSS) Шаг измерения периода (сек)
	 820	,8	,1	,&fEM_R0UL02RDU},	//(R0UL02RDU) Время задержки  ИНИ
	 821	,8	,1	,&fEM_R0UL02RSS},	//(R0UL02RSS) Tф-постоянная времени, с
	 822	,8	,1	,&fEM_R0UL03RDU},	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
	 823	,8	,1	,&fEM_R0UL04RDU},	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
	 824	,8	,1	,&fEM_R0UL05RDU},	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
	 825	,8	,1	,&fEM_R0UL06RDU},	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
	 826	,8	,1	,&fEM_R0UL07RDU},	//(R0UL07RDU) Время срабатывания верхней АС II УР
	 827	,8	,1	,&fEM_R0UL16RDU},	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
	 828	,8	,1	,&fEM_R0UL17RDU},	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
	 829	,8	,1	,&fEM_R0UL18RDU},	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
	 830	,8	,1	,&fEM_R0UL19RDU},	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	 831	,8	,1	,&fEM_R0UL20RDU},	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
	 832	,8	,1	,&fEM_R0UL21RDU},	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
	 833	,8	,1	,&fEM_R0UL25RDU},	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	 834	,8	,1	,&fEM_R0UN01RDU},	//(R0UN01RDU) 1-я заданная мощность
	 835	,8	,1	,&fEM_R0UN02RDU},	//(R0UN02RDU) 2-я заданная мощность
	 836	,8	,1	,&fEM_R0UN03RDU},	//(R0UN03RDU) Ограничение 3 по мощности
	 837	,8	,1	,&fEM_R0UN03RSS},	//(R0UN03RSS) нижняя граница интервала мощности для измерения периода (ватт)
	 838	,8	,1	,&fEM_R0UN04RDU},	//(R0UN04RDU) 4-я заданная мощность
	 839	,8	,1	,&fEM_R0UN05RDU},	//(R0UN05RDU) 5-я заданная мощность
	 840	,8	,1	,&fEM_R0UN06RDU},	//(R0UN06RDU) 6-я заданная мощность
	 841	,8	,1	,&fEM_R0UN07RDU},	//(R0UN07RDU) 7-я заданная мощность
	 842	,8	,1	,&fEM_R0UN08RDU},	//(R0UN08RDU) 8-я заданная мощность
	 843	,8	,1	,&fEM_R0UN09RDU},	//(R0UN09RDU) Минимальный период при регулировании мощности
	 844	,8	,1	,&fEM_R0UN11RDU},	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
	 845	,8	,1	,&fEM_R0UN12RDU},	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
	 846	,8	,1	,&fEM_R0UN13RDU},	//(R0UN13RDU) Минимальное изменение координаты, мм
	 847	,8	,1	,&fEM_R0UN14RDU},	//(R0UN14RDU) Максимальная координата штока ИМ, мм
	 848	,8	,1	,&fEM_R0UN15RDU},	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
	 849	,8	,1	,&fEM_R0UN16RDU},	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
	 850	,8	,1	,&fEM_R0UN17RDU},	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
	 851	,8	,1	,&fEM_R0UN18RDU},	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
	 852	,8	,1	,&fEM_R0UN19RDU},	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
	 853	,8	,1	,&fEM_R0UN24RDU},	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
	 854	,8	,1	,&fEM_R0UN25RDU},	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
	 855	,8	,1	,&fEM_R0UN26RDU},	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
	 856	,8	,1	,&fEM_R0UN27RDU},	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
	 857	,8	,1	,&fEM_R0UN70LDU},	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
	 858	,8	,1	,&fEM_R0UN71LDU},	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
	 859	,8	,1	,&fEM_R0UN72LDU},	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
	 860	,8	,1	,&fEM_R0UN73LDU},	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
	 861	,8	,1	,&fEM_R0UN74LDU},	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
	 862	,8	,1	,&fEM_R0UN75LDU},	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
	 863	,8	,1	,&fEM_R0UN80LDU},	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
	 864	,8	,1	,&fEM_R0UN80RDU},	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
	 865	,8	,1	,&fEM_R0UN81LDU},	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
	 866	,8	,1	,&fEM_R0UN82LDU},	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
	 867	,8	,1	,&fEM_R0UN83LDU},	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
	 868	,8	,1	,&fEM_R0UN84LDU},	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
	 869	,8	,1	,&fEM_R0UN85LDU},	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
	 870	,8	,1	,&fEM_R0UT20RDU},	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
	 871	,8	,1	,&fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	 872	,8	,1	,&fEM_R0UV82RDU},	//(R0UV82RDU) 2-я частота двигателя (шагов/секунду)
	 873	,8	,1	,&fEM_R0UV83RDU},	//(R0UV83RDU) 3-я частота двигателя (шагов/секунду)
	 874	,8	,1	,&fEM_R0UV84RDU},	//(R0UV84RDU) 4-я частота двигателя (шагов/секунду)
	 875	,8	,1	,&fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	 876	,8	,1	,&fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	 877	,8	,1	,&fEM_R0UV87RDU},	//(R0UV87RDU) 8-я скорость перемещения ББ (шагов/секунду)
	 878	,8	,1	,&fEM_R1UZ03RDU},	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
	 879	,8	,1	,&fEM_R1UZ04RDU},	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
	 880	,8	,1	,&fEM_R1UZ05RDU},	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
	 881	,8	,1	,&fEM_R4UZ03RDU},	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
	 882	,8	,1	,&fEM_R4UZ04RDU},	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
	 883	,8	,1	,&fEM_R4UZ05RDU},	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
	 884	,8	,1	,&fEM_R7UI76RDU},	//(R7UI76RDU) Время срабатывания сигнала II УР при имитации
	 885	,3	,1	,&iEM_A1UV01IDU},	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
	 886	,3	,1	,&iEM_A1UV02IDU},	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
	 887	,3	,1	,&iEM_A1UV03IDU},	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
	 888	,3	,1	,&iEM_A2UV01IDU},	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
	 889	,3	,1	,&iEM_A2UV02IDU},	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
	 890	,3	,1	,&iEM_A2UV03CDU},	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
	 891	,3	,1	,&iEM_A3UV01IDU},	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
	 892	,3	,1	,&iEM_A3UV02IDU},	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
	 893	,18	,1	,&internal1_m1005_BLDv0},	//(internal1_m1005_BLDv0) BlDv - Блокировка движения
	 894	,8	,1	,&internal1_m1005_X0},	//(internal1_m1005_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	 895	,8	,1	,&internal1_m1005_t0},	//(internal1_m1005_t0) время нахождения в зоне возврата
	 896	,8	,1	,&internal1_m1027_tx},	//(internal1_m1027_tx) tx - время накопленное сек
	 897	,18	,1	,&internal1_m1027_y0},	//(internal1_m1027_y0) y0
	 898	,8	,1	,&internal1_m1028_tx},	//(internal1_m1028_tx) tx - время накопленное сек
	 899	,18	,1	,&internal1_m1028_y0},	//(internal1_m1028_y0) y0
	 900	,8	,1	,&internal1_m1029_tx},	//(internal1_m1029_tx) tx - внутренний параметр
	 901	,8	,1	,&internal1_m1035_DelSp},	//(internal1_m1035_DelSp) DelSp - время переключения скоростей
	 902	,1	,1	,&internal1_m1035_ShCntlSp0},	//(internal1_m1035_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	 903	,1	,1	,&internal1_m1035_Shift0},	//(internal1_m1035_Shift0) Shift0 - признак самохода
	 904	,1	,1	,&internal1_m1035_ShiftControl},	//(internal1_m1035_ShiftControl) ShiftControl - признак самохода
	 905	,8	,1	,&internal1_m1035_Speed0},	//(internal1_m1035_Speed0) Speed0 - предыдущее значение скорости перемещения
	 906	,8	,1	,&internal1_m1035_StSpeed},	//(internal1_m1035_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	 907	,8	,1	,&internal1_m1035_Vz0},	//(internal1_m1035_Vz0) Vz0 - предыдущая заданная скорость
	 908	,3	,1	,&internal1_m1035_flRazg},	//(internal1_m1035_flRazg) признак разгона/торможения
	 909	,8	,1	,&internal1_m1035_sumtim},	//(internal1_m1035_sumtim) sumtim - время в пути
	 910	,8	,60	,&internal1_m1035_tim0},	//(internal1_m1035_tim0) tim0 - массив значений времени цикла
	 911	,8	,1	,&internal1_m1035_tx},	//(internal1_m1035_tx) tx
	 912	,8	,1	,&internal1_m1035_txBl},	//(internal1_m1035_txBl) tx
	 913	,8	,1	,&internal1_m1035_txMBl},	//(internal1_m1035_txMBl) tx
	 914	,8	,1	,&internal1_m1035_txZS},	//(internal1_m1035_txZS) txZS
	 915	,8	,1	,&internal1_m1035_txd},	//(internal1_m1035_txd) txd
	 916	,8	,1	,&internal1_m1035_tz0},	//(internal1_m1035_tz0) tz0 - время защиты от нового задания сек
	 917	,8	,60	,&internal1_m1035_x0},	//(internal1_m1035_x0) x0 - массив мгновенных значений координат
	 918	,3	,1	,&internal1_m1035_xptr},	//(internal1_m1035_xptr) указатель текущей позиции в массиве координат
	 919	,8	,1	,&internal1_m1035_xz0},	//(internal1_m1035_xz0) xz0 - новое задание мм
	 920	,8	,1	,&internal1_m1035_z0},	//(internal1_m1035_z0) z0 - точка прекращения движения
	 921	,8	,1	,&internal1_m1039_tx},	//(internal1_m1039_tx) tx - внутренний параметр
	 922	,8	,1	,&internal1_m1040_tx},	//(internal1_m1040_tx) tx - внутренний параметр
	 923	,8	,1	,&internal1_m1046_tx},	//(internal1_m1046_tx) tx - внутренний параметр
	 924	,8	,1	,&internal1_m1052_tx},	//(internal1_m1052_tx) tx - время накопленное сек
	 925	,18	,1	,&internal1_m1052_y0},	//(internal1_m1052_y0) y0
	 926	,8	,1	,&internal1_m1061_tx},	//(internal1_m1061_tx) tx - внутренний параметр
	 927	,8	,1	,&internal1_m1062_tx},	//(internal1_m1062_tx) tx - внутренний параметр
	 928	,8	,1	,&internal1_m1064_tx},	//(internal1_m1064_tx) tx - внутренний параметр
	 929	,8	,1	,&internal1_m1074_tx},	//(internal1_m1074_tx) tx - внутренний параметр
	 930	,8	,1	,&internal1_m1078_tx},	//(internal1_m1078_tx) tx - внутренний параметр
	 931	,8	,1	,&internal1_m1079_tx},	//(internal1_m1079_tx) tx - внутренний параметр
	 932	,8	,1	,&internal1_m1087_tx},	//(internal1_m1087_tx) tx - внутренний параметр
	 933	,8	,1	,&internal1_m1089_tx},	//(internal1_m1089_tx) tx - внутренний параметр
	 934	,8	,1	,&internal1_m108_tx},	//(internal1_m108_tx) tx - внутренний параметр
	 935	,8	,1	,&internal1_m1096_tx},	//(internal1_m1096_tx) tx - внутренний параметр
	 936	,8	,1	,&internal1_m1097_tx},	//(internal1_m1097_tx) tx - внутренний параметр
	 937	,8	,1	,&internal1_m1098_tx},	//(internal1_m1098_tx) tx - внутренний параметр
	 938	,8	,1	,&internal1_m1099_tx},	//(internal1_m1099_tx) tx - внутренний параметр
	 939	,8	,1	,&internal1_m1100_tx},	//(internal1_m1100_tx) tx - внутренний параметр
	 940	,1	,1	,&internal1_m1116_q0},	//(internal1_m1116_q0) q0 - внутренний параметр
	 941	,1	,1	,&internal1_m1124_q0},	//(internal1_m1124_q0) q0 - внутренний параметр
	 942	,1	,1	,&internal1_m1145_q0},	//(internal1_m1145_q0) q0 - внутренний параметр
	 943	,8	,1	,&internal1_m1148_tx},	//(internal1_m1148_tx) tx - внутренний параметр
	 944	,1	,1	,&internal1_m1149_q0},	//(internal1_m1149_q0) q0 - внутренний параметр
	 945	,1	,1	,&internal1_m1151_q0},	//(internal1_m1151_q0) q0 - внутренний параметр
	 946	,1	,1	,&internal1_m1152_q0},	//(internal1_m1152_q0) q0 - внутренний параметр
	 947	,1	,1	,&internal1_m1156_q0},	//(internal1_m1156_q0) q0 - внутренний параметр
	 948	,1	,1	,&internal1_m1162_q0},	//(internal1_m1162_q0) q0 - внутренний параметр
	 949	,1	,1	,&internal1_m1168_q0},	//(internal1_m1168_q0) q0 - внутренний параметр
	 950	,1	,1	,&internal1_m116_q0},	//(internal1_m116_q0) q0 - внутренний параметр
	 951	,1	,1	,&internal1_m1180_q0},	//(internal1_m1180_q0) q0 - внутренний параметр
	 952	,1	,1	,&internal1_m1182_q0},	//(internal1_m1182_q0) q0 - внутренний параметр
	 953	,1	,1	,&internal1_m1189_q0},	//(internal1_m1189_q0) q0 - внутренний параметр
	 954	,1	,1	,&internal1_m1197_q0},	//(internal1_m1197_q0) q0 - внутренний параметр
	 955	,1	,1	,&internal1_m1198_q0},	//(internal1_m1198_q0) q0 - внутренний параметр
	 956	,1	,1	,&internal1_m1200_q0},	//(internal1_m1200_q0) q0 - внутренний параметр
	 957	,1	,1	,&internal1_m1201_q0},	//(internal1_m1201_q0) q0 - внутренний параметр
	 958	,1	,1	,&internal1_m1203_q0},	//(internal1_m1203_q0) q0 - внутренний параметр
	 959	,1	,1	,&internal1_m1204_q0},	//(internal1_m1204_q0) q0 - внутренний параметр
	 960	,1	,1	,&internal1_m1206_q0},	//(internal1_m1206_q0) q0 - внутренний параметр
	 961	,1	,1	,&internal1_m1207_q0},	//(internal1_m1207_q0) q0 - внутренний параметр
	 962	,1	,1	,&internal1_m1209_q0},	//(internal1_m1209_q0) q0 - внутренний параметр
	 963	,8	,1	,&internal1_m120_tx},	//(internal1_m120_tx) tx - внутренний параметр
	 964	,8	,1	,&internal1_m122_tx},	//(internal1_m122_tx) tx - внутренний параметр
	 965	,8	,1	,&internal1_m1242_tx},	//(internal1_m1242_tx) tx - внутренний параметр
	 966	,8	,1	,&internal1_m1244_tx},	//(internal1_m1244_tx) tx - внутренний параметр
	 967	,8	,1	,&internal1_m1246_tx},	//(internal1_m1246_tx) tx - внутренний параметр
	 968	,8	,1	,&internal1_m1248_tx},	//(internal1_m1248_tx) tx - внутренний параметр
	 969	,8	,1	,&internal1_m1255_tx},	//(internal1_m1255_tx) tx - внутренний параметр
	 970	,8	,1	,&internal1_m1259_tx},	//(internal1_m1259_tx) tx - внутренний параметр
	 971	,8	,1	,&internal1_m1260_tx},	//(internal1_m1260_tx) tx - внутренний параметр
	 972	,8	,1	,&internal1_m1263_tx},	//(internal1_m1263_tx) tx - внутренний параметр
	 973	,18	,1	,&internal1_m1273_BLDv0},	//(internal1_m1273_BLDv0) BlDv - Блокировка движения
	 974	,8	,1	,&internal1_m1273_X0},	//(internal1_m1273_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	 975	,8	,1	,&internal1_m1273_t0},	//(internal1_m1273_t0) время нахождения в зоне возврата
	 976	,8	,1	,&internal1_m127_tx},	//(internal1_m127_tx) tx - внутренний параметр
	 977	,18	,1	,&internal1_m1281_BlDv0},	//(internal1_m1281_BlDv0) - была блокировка
	 978	,18	,1	,&internal1_m1281_DvDw0},	//(internal1_m1281_DvDw0) - есть команда на движение назад
	 979	,18	,1	,&internal1_m1281_DvUp0},	//(internal1_m1281_DvUp0) - есть команда на движение вперёд
	 980	,18	,1	,&internal1_m1281_FDvDw0},	//(internal1_m1281_FDvDw0) - есть команда на движение назад
	 981	,18	,1	,&internal1_m1281_FDvUp0},	//(internal1_m1281_FDvUp0) - есть команда на движение вперёд
	 982	,18	,1	,&internal1_m1281_Pkav0},	//(internal1_m1281_Pkav0) Pkav - передний конечный аварийный выключатель
	 983	,18	,1	,&internal1_m1281_Pkv0},	//(internal1_m1281_Pkv0) Pkv - передний конечный выключатель
	 984	,18	,1	,&internal1_m1281_Zkav0},	//(internal1_m1281_Zkav0) Zkav - задний конечный аварийный выключатель
	 985	,18	,1	,&internal1_m1281_Zkv0},	//(internal1_m1281_Zkv0) Zkv - задний конечный выключатель
	 986	,18	,1	,&internal1_m1281_fef},	//(internal1_m1281_fef) fef
	 987	,8	,1	,&internal1_m1281_txHr},	//(internal1_m1281_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	 988	,8	,1	,&internal1_m1281_txLd},	//(internal1_m1281_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	 989	,8	,1	,&internal1_m1281_txNm},	//(internal1_m1281_txNm) txNm - счётчик задержки сигнализации недвижения
	 990	,8	,1	,&internal1_m1281_txSm},	//(internal1_m1281_txSm) txSm - счётчик задержки сигнализации самохода
	 991	,8	,1	,&internal1_m1284_tx},	//(internal1_m1284_tx) tx - внутренний параметр
	 992	,8	,1	,&internal1_m1285_tx},	//(internal1_m1285_tx) tx - внутренний параметр
	 993	,8	,1	,&internal1_m1290_tx},	//(internal1_m1290_tx) tx - время накопленное сек
	 994	,18	,1	,&internal1_m1290_y0},	//(internal1_m1290_y0) y0
	 995	,8	,1	,&internal1_m1292_tx},	//(internal1_m1292_tx) tx - внутренний параметр
	 996	,8	,1	,&internal1_m1294_tx},	//(internal1_m1294_tx) tx - время накопленное сек
	 997	,18	,1	,&internal1_m1294_y0},	//(internal1_m1294_y0) y0
	 998	,8	,1	,&internal1_m1297_tx},	//(internal1_m1297_tx) tx - внутренний параметр
	 999	,8	,1	,&internal1_m1298_tx},	//(internal1_m1298_tx) tx - внутренний параметр
	 1000	,8	,1	,&internal1_m1300_DelSp},	//(internal1_m1300_DelSp) DelSp - время переключения скоростей
	 1001	,1	,1	,&internal1_m1300_ShCntlSp0},	//(internal1_m1300_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	 1002	,1	,1	,&internal1_m1300_Shift0},	//(internal1_m1300_Shift0) Shift0 - признак самохода
	 1003	,1	,1	,&internal1_m1300_ShiftControl},	//(internal1_m1300_ShiftControl) ShiftControl - признак самохода
	 1004	,8	,1	,&internal1_m1300_Speed0},	//(internal1_m1300_Speed0) Speed0 - предыдущее значение скорости перемещения
	 1005	,8	,1	,&internal1_m1300_StSpeed},	//(internal1_m1300_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	 1006	,8	,1	,&internal1_m1300_Vz0},	//(internal1_m1300_Vz0) Vz0 - предыдущая заданная скорость
	 1007	,3	,1	,&internal1_m1300_flRazg},	//(internal1_m1300_flRazg) признак разгона/торможения
	 1008	,8	,1	,&internal1_m1300_sumtim},	//(internal1_m1300_sumtim) sumtim - время в пути
	 1009	,8	,20	,&internal1_m1300_tim0},	//(internal1_m1300_tim0) tim0 - массив значений времени цикла
	 1010	,8	,1	,&internal1_m1300_tx},	//(internal1_m1300_tx) tx
	 1011	,8	,1	,&internal1_m1300_txBl},	//(internal1_m1300_txBl) tx
	 1012	,8	,1	,&internal1_m1300_txMBl},	//(internal1_m1300_txMBl) tx
	 1013	,8	,1	,&internal1_m1300_txZS},	//(internal1_m1300_txZS) txZS
	 1014	,8	,1	,&internal1_m1300_txd},	//(internal1_m1300_txd) txd
	 1015	,8	,1	,&internal1_m1300_tz0},	//(internal1_m1300_tz0) tz0 - время защиты от нового задания сек
	 1016	,8	,20	,&internal1_m1300_x0},	//(internal1_m1300_x0) x0 - массив мгновенных значений координат
	 1017	,3	,1	,&internal1_m1300_xptr},	//(internal1_m1300_xptr) указатель текущей позиции в массиве координат
	 1018	,8	,1	,&internal1_m1300_xz0},	//(internal1_m1300_xz0) xz0 - новое задание мм
	 1019	,8	,1	,&internal1_m1300_z0},	//(internal1_m1300_z0) z0 - точка прекращения движения
	 1020	,8	,1	,&internal1_m1303_tx},	//(internal1_m1303_tx) tx - внутренний параметр
	 1021	,8	,1	,&internal1_m1306_tx},	//(internal1_m1306_tx) tx - время накопленное сек
	 1022	,18	,1	,&internal1_m1306_y0},	//(internal1_m1306_y0) y0
	 1023	,8	,1	,&internal1_m1326_tx},	//(internal1_m1326_tx) tx - внутренний параметр
	 1024	,8	,1	,&internal1_m1327_tx},	//(internal1_m1327_tx) tx - внутренний параметр
	 1025	,8	,1	,&internal1_m1330_tx},	//(internal1_m1330_tx) tx - внутренний параметр
	 1026	,18	,1	,&internal1_m1333_BlDv0},	//(internal1_m1333_BlDv0) - была блокировка
	 1027	,18	,1	,&internal1_m1333_DvDw0},	//(internal1_m1333_DvDw0) - есть команда на движение назад
	 1028	,18	,1	,&internal1_m1333_DvUp0},	//(internal1_m1333_DvUp0) - есть команда на движение вперёд
	 1029	,18	,1	,&internal1_m1333_FDvDw0},	//(internal1_m1333_FDvDw0) - есть команда на движение назад
	 1030	,18	,1	,&internal1_m1333_FDvUp0},	//(internal1_m1333_FDvUp0) - есть команда на движение вперёд
	 1031	,18	,1	,&internal1_m1333_Pkav0},	//(internal1_m1333_Pkav0) Pkav - передний конечный аварийный выключатель
	 1032	,18	,1	,&internal1_m1333_Pkv0},	//(internal1_m1333_Pkv0) Pkv - передний конечный выключатель
	 1033	,18	,1	,&internal1_m1333_Zkav0},	//(internal1_m1333_Zkav0) Zkav - задний конечный аварийный выключатель
	 1034	,18	,1	,&internal1_m1333_Zkv0},	//(internal1_m1333_Zkv0) Zkv - задний конечный выключатель
	 1035	,18	,1	,&internal1_m1333_fef},	//(internal1_m1333_fef) fef
	 1036	,8	,1	,&internal1_m1333_txHr},	//(internal1_m1333_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	 1037	,8	,1	,&internal1_m1333_txLd},	//(internal1_m1333_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	 1038	,8	,1	,&internal1_m1333_txNm},	//(internal1_m1333_txNm) txNm - счётчик задержки сигнализации недвижения
	 1039	,8	,1	,&internal1_m1333_txSm},	//(internal1_m1333_txSm) txSm - счётчик задержки сигнализации самохода
	 1040	,8	,1	,&internal1_m1341_tx},	//(internal1_m1341_tx) tx - внутренний параметр
	 1041	,18	,1	,&internal1_m1343_BlDv0},	//(internal1_m1343_BlDv0) - была блокировка
	 1042	,18	,1	,&internal1_m1343_DvDw0},	//(internal1_m1343_DvDw0) - есть команда на движение назад
	 1043	,18	,1	,&internal1_m1343_DvUp0},	//(internal1_m1343_DvUp0) - есть команда на движение вперёд
	 1044	,18	,1	,&internal1_m1343_FDvDw0},	//(internal1_m1343_FDvDw0) - есть команда на движение назад
	 1045	,18	,1	,&internal1_m1343_FDvUp0},	//(internal1_m1343_FDvUp0) - есть команда на движение вперёд
	 1046	,18	,1	,&internal1_m1343_Pkav0},	//(internal1_m1343_Pkav0) Pkav - передний конечный аварийный выключатель
	 1047	,18	,1	,&internal1_m1343_Pkv0},	//(internal1_m1343_Pkv0) Pkv - передний конечный выключатель
	 1048	,18	,1	,&internal1_m1343_Zkav0},	//(internal1_m1343_Zkav0) Zkav - задний конечный аварийный выключатель
	 1049	,18	,1	,&internal1_m1343_Zkv0},	//(internal1_m1343_Zkv0) Zkv - задний конечный выключатель
	 1050	,18	,1	,&internal1_m1343_fef},	//(internal1_m1343_fef) fef
	 1051	,8	,1	,&internal1_m1343_txHr},	//(internal1_m1343_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	 1052	,8	,1	,&internal1_m1343_txLd},	//(internal1_m1343_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	 1053	,8	,1	,&internal1_m1343_txNm},	//(internal1_m1343_txNm) txNm - счётчик задержки сигнализации недвижения
	 1054	,8	,1	,&internal1_m1343_txSm},	//(internal1_m1343_txSm) txSm - счётчик задержки сигнализации самохода
	 1055	,8	,1	,&internal1_m1347_tx},	//(internal1_m1347_tx) tx - внутренний параметр
	 1056	,8	,1	,&internal1_m1348_tx},	//(internal1_m1348_tx) tx - внутренний параметр
	 1057	,8	,1	,&internal1_m1349_tx},	//(internal1_m1349_tx) tx - внутренний параметр
	 1058	,18	,1	,&internal1_m1370_BLDv0},	//(internal1_m1370_BLDv0) BlDv - Блокировка движения
	 1059	,8	,1	,&internal1_m1370_X0},	//(internal1_m1370_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	 1060	,8	,1	,&internal1_m1370_t0},	//(internal1_m1370_t0) время нахождения в зоне возврата
	 1061	,8	,1	,&internal1_m1390_tx},	//(internal1_m1390_tx) tx - внутренний параметр
	 1062	,8	,1	,&internal1_m1393_tx},	//(internal1_m1393_tx) tx - внутренний параметр
	 1063	,8	,1	,&internal1_m1397_tx},	//(internal1_m1397_tx) tx - время накопленное сек
	 1064	,18	,1	,&internal1_m1397_y0},	//(internal1_m1397_y0) y0
	 1065	,8	,1	,&internal1_m1398_tx},	//(internal1_m1398_tx) tx - время накопленное сек
	 1066	,18	,1	,&internal1_m1398_y0},	//(internal1_m1398_y0) y0
	 1067	,8	,1	,&internal1_m13_tx},	//(internal1_m13_tx) tx - внутренний параметр
	 1068	,8	,1	,&internal1_m1405_DelSp},	//(internal1_m1405_DelSp) DelSp - время переключения скоростей
	 1069	,1	,1	,&internal1_m1405_ShCntlSp0},	//(internal1_m1405_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	 1070	,1	,1	,&internal1_m1405_Shift0},	//(internal1_m1405_Shift0) Shift0 - признак самохода
	 1071	,1	,1	,&internal1_m1405_ShiftControl},	//(internal1_m1405_ShiftControl) ShiftControl - признак самохода
	 1072	,8	,1	,&internal1_m1405_Speed0},	//(internal1_m1405_Speed0) Speed0 - предыдущее значение скорости перемещения
	 1073	,8	,1	,&internal1_m1405_StSpeed},	//(internal1_m1405_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	 1074	,8	,1	,&internal1_m1405_Vz0},	//(internal1_m1405_Vz0) Vz0 - предыдущая заданная скорость
	 1075	,3	,1	,&internal1_m1405_flRazg},	//(internal1_m1405_flRazg) признак разгона/торможения
	 1076	,8	,1	,&internal1_m1405_sumtim},	//(internal1_m1405_sumtim) sumtim - время в пути
	 1077	,8	,80	,&internal1_m1405_tim0},	//(internal1_m1405_tim0) tim0 - массив значений времени цикла
	 1078	,8	,1	,&internal1_m1405_tx},	//(internal1_m1405_tx) tx
	 1079	,8	,1	,&internal1_m1405_txBl},	//(internal1_m1405_txBl) tx
	 1080	,8	,1	,&internal1_m1405_txMBl},	//(internal1_m1405_txMBl) tx
	 1081	,8	,1	,&internal1_m1405_txZS},	//(internal1_m1405_txZS) txZS
	 1082	,8	,1	,&internal1_m1405_txd},	//(internal1_m1405_txd) txd
	 1083	,8	,1	,&internal1_m1405_tz0},	//(internal1_m1405_tz0) tz0 - время защиты от нового задания сек
	 1084	,8	,80	,&internal1_m1405_x0},	//(internal1_m1405_x0) x0 - массив мгновенных значений координат
	 1085	,3	,1	,&internal1_m1405_xptr},	//(internal1_m1405_xptr) указатель текущей позиции в массиве координат
	 1086	,8	,1	,&internal1_m1405_xz0},	//(internal1_m1405_xz0) xz0 - новое задание мм
	 1087	,8	,1	,&internal1_m1405_z0},	//(internal1_m1405_z0) z0 - точка прекращения движения
	 1088	,8	,1	,&internal1_m1408_tx},	//(internal1_m1408_tx) tx - внутренний параметр
	 1089	,8	,1	,&internal1_m1412_tx},	//(internal1_m1412_tx) tx - внутренний параметр
	 1090	,8	,1	,&internal1_m1415_tx},	//(internal1_m1415_tx) tx - время накопленное сек
	 1091	,18	,1	,&internal1_m1415_y0},	//(internal1_m1415_y0) y0
	 1092	,8	,1	,&internal1_m1426_tx},	//(internal1_m1426_tx) tx - внутренний параметр
	 1093	,8	,1	,&internal1_m1428_tx},	//(internal1_m1428_tx) tx - внутренний параметр
	 1094	,8	,1	,&internal1_m1435_tx},	//(internal1_m1435_tx) tx - внутренний параметр
	 1095	,8	,1	,&internal1_m1441_tx},	//(internal1_m1441_tx) tx - внутренний параметр
	 1096	,8	,1	,&internal1_m1445_tx},	//(internal1_m1445_tx) tx - внутренний параметр
	 1097	,8	,1	,&internal1_m1446_tx},	//(internal1_m1446_tx) tx - внутренний параметр
	 1098	,8	,1	,&internal1_m1455_tx},	//(internal1_m1455_tx) tx - внутренний параметр
	 1099	,8	,1	,&internal1_m1456_tx},	//(internal1_m1456_tx) tx - внутренний параметр
	 1100	,8	,1	,&internal1_m1462_tx},	//(internal1_m1462_tx) tx - внутренний параметр
	 1101	,8	,1	,&internal1_m1463_tx},	//(internal1_m1463_tx) tx - внутренний параметр
	 1102	,8	,1	,&internal1_m1464_tx},	//(internal1_m1464_tx) tx - внутренний параметр
	 1103	,8	,1	,&internal1_m1465_tx},	//(internal1_m1465_tx) tx - внутренний параметр
	 1104	,18	,1	,&internal1_m1483_BLDv0},	//(internal1_m1483_BLDv0) BlDv - Блокировка движения
	 1105	,8	,1	,&internal1_m1483_X0},	//(internal1_m1483_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	 1106	,8	,1	,&internal1_m1483_t0},	//(internal1_m1483_t0) время нахождения в зоне возврата
	 1107	,8	,1	,&internal1_m1500_tx},	//(internal1_m1500_tx) tx - время накопленное сек
	 1108	,18	,1	,&internal1_m1500_y0},	//(internal1_m1500_y0) y0
	 1109	,8	,1	,&internal1_m1501_tx},	//(internal1_m1501_tx) tx - время накопленное сек
	 1110	,18	,1	,&internal1_m1501_y0},	//(internal1_m1501_y0) y0
	 1111	,8	,1	,&internal1_m1506_tx},	//(internal1_m1506_tx) tx - внутренний параметр
	 1112	,8	,1	,&internal1_m1507_tx},	//(internal1_m1507_tx) tx - внутренний параметр
	 1113	,8	,1	,&internal1_m1509_DelSp},	//(internal1_m1509_DelSp) DelSp - время переключения скоростей
	 1114	,1	,1	,&internal1_m1509_ShCntlSp0},	//(internal1_m1509_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	 1115	,1	,1	,&internal1_m1509_Shift0},	//(internal1_m1509_Shift0) Shift0 - признак самохода
	 1116	,1	,1	,&internal1_m1509_ShiftControl},	//(internal1_m1509_ShiftControl) ShiftControl - признак самохода
	 1117	,8	,1	,&internal1_m1509_Speed0},	//(internal1_m1509_Speed0) Speed0 - предыдущее значение скорости перемещения
	 1118	,8	,1	,&internal1_m1509_StSpeed},	//(internal1_m1509_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	 1119	,8	,1	,&internal1_m1509_Vz0},	//(internal1_m1509_Vz0) Vz0 - предыдущая заданная скорость
	 1120	,3	,1	,&internal1_m1509_flRazg},	//(internal1_m1509_flRazg) признак разгона/торможения
	 1121	,8	,1	,&internal1_m1509_sumtim},	//(internal1_m1509_sumtim) sumtim - время в пути
	 1122	,8	,60	,&internal1_m1509_tim0},	//(internal1_m1509_tim0) tim0 - массив значений времени цикла
	 1123	,8	,1	,&internal1_m1509_tx},	//(internal1_m1509_tx) tx
	 1124	,8	,1	,&internal1_m1509_txBl},	//(internal1_m1509_txBl) tx
	 1125	,8	,1	,&internal1_m1509_txMBl},	//(internal1_m1509_txMBl) tx
	 1126	,8	,1	,&internal1_m1509_txZS},	//(internal1_m1509_txZS) txZS
	 1127	,8	,1	,&internal1_m1509_txd},	//(internal1_m1509_txd) txd
	 1128	,8	,1	,&internal1_m1509_tz0},	//(internal1_m1509_tz0) tz0 - время защиты от нового задания сек
	 1129	,8	,60	,&internal1_m1509_x0},	//(internal1_m1509_x0) x0 - массив мгновенных значений координат
	 1130	,3	,1	,&internal1_m1509_xptr},	//(internal1_m1509_xptr) указатель текущей позиции в массиве координат
	 1131	,8	,1	,&internal1_m1509_xz0},	//(internal1_m1509_xz0) xz0 - новое задание мм
	 1132	,8	,1	,&internal1_m1509_z0},	//(internal1_m1509_z0) z0 - точка прекращения движения
	 1133	,8	,1	,&internal1_m1516_tx},	//(internal1_m1516_tx) tx - внутренний параметр
	 1134	,8	,1	,&internal1_m1519_tx},	//(internal1_m1519_tx) tx - внутренний параметр
	 1135	,8	,1	,&internal1_m1525_tx},	//(internal1_m1525_tx) tx - время накопленное сек
	 1136	,18	,1	,&internal1_m1525_y0},	//(internal1_m1525_y0) y0
	 1137	,8	,1	,&internal1_m1534_tx},	//(internal1_m1534_tx) tx - внутренний параметр
	 1138	,8	,1	,&internal1_m1535_tx},	//(internal1_m1535_tx) tx - внутренний параметр
	 1139	,8	,1	,&internal1_m1537_tx},	//(internal1_m1537_tx) tx - внутренний параметр
	 1140	,8	,1	,&internal1_m1547_tx},	//(internal1_m1547_tx) tx - внутренний параметр
	 1141	,8	,1	,&internal1_m1549_tx},	//(internal1_m1549_tx) tx - внутренний параметр
	 1142	,8	,1	,&internal1_m1550_tx},	//(internal1_m1550_tx) tx - внутренний параметр
	 1143	,8	,1	,&internal1_m1560_tx},	//(internal1_m1560_tx) tx - внутренний параметр
	 1144	,8	,1	,&internal1_m1562_tx},	//(internal1_m1562_tx) tx - внутренний параметр
	 1145	,8	,1	,&internal1_m1569_tx},	//(internal1_m1569_tx) tx - внутренний параметр
	 1146	,8	,1	,&internal1_m1570_tx},	//(internal1_m1570_tx) tx - внутренний параметр
	 1147	,8	,1	,&internal1_m1571_tx},	//(internal1_m1571_tx) tx - внутренний параметр
	 1148	,8	,1	,&internal1_m1572_tx},	//(internal1_m1572_tx) tx - внутренний параметр
	 1149	,8	,1	,&internal1_m1573_tx},	//(internal1_m1573_tx) tx - внутренний параметр
	 1150	,1	,1	,&internal1_m1599_q0},	//(internal1_m1599_q0) q0 - внутренний параметр
	 1151	,1	,1	,&internal1_m1600_ErrPr0},	//(internal1_m1600_ErrPr0) ErrPr - Приостановка программы по ошибке
	 1152	,1	,1	,&internal1_m1600_FinPr0},	//(internal1_m1600_FinPr0) FinPr - конец программы
	 1153	,1	,1	,&internal1_m1600_MyFirstEnterFlag},	//(internal1_m1600_MyFirstEnterFlag)  
	 1154	,3	,1	,&internal1_m1600_Step},	//(internal1_m1600_Step)  - текущий шаг программы
	 1155	,8	,1	,&internal1_m1600_TimS},	//(internal1_m1600_TimS) Время от старта программы
	 1156	,18	,6	,&internal1_m1600_rz},	//(internal1_m1600_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	 1157	,1	,1	,&internal1_m1600_sb2UR0},	//(internal1_m1600_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	 1158	,1	,1	,&internal1_m1600_sbINI0},	//(internal1_m1600_sbINI0) sbINI - запуск проверки ИНИ
	 1159	,1	,1	,&internal1_m1600_sbNupIS0},	//(internal1_m1600_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	 1160	,1	,1	,&internal1_m1600_sbVuIS0},	//(internal1_m1600_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	 1161	,1	,1	,&internal1_m1600_sbVuRB0},	//(internal1_m1600_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	 1162	,5	,1	,&internal1_m1602_q0},	//(internal1_m1602_q0) q0 - внутренний параметр
	 1163	,5	,1	,&internal1_m1617_x0},	//(internal1_m1617_x0) x0 - значение входного параметра на предыдущем шаге
	 1164	,8	,1	,&internal1_m1627_tx},	//(internal1_m1627_tx) tx - внутренний параметр
	 1165	,1	,1	,&internal1_m1636_q0},	//(internal1_m1636_q0) q0 - внутренний параметр
	 1166	,8	,1	,&internal1_m1637_tim},	//(internal1_m1637_tim) - время задержки выходного сигнала
	 1167	,1	,1	,&internal1_m1637_x0},	//(internal1_m1637_x0) - значение входного параметра на предыдущем шаге
	 1168	,8	,1	,&internal1_m1643_tx},	//(internal1_m1643_tx) tx - время накопленное сек
	 1169	,18	,1	,&internal1_m1643_y0},	//(internal1_m1643_y0) y0
	 1170	,1	,1	,&internal1_m1646_q0},	//(internal1_m1646_q0) q0 - внутренний параметр
	 1171	,8	,1	,&internal1_m1648_q0},	//(internal1_m1648_q0) q0 - внутренний параметр
	 1172	,1	,1	,&internal1_m1651_fef},	//(internal1_m1651_fef) FirstEnterFlag
	 1173	,1	,1	,&internal1_m1651_x0},	//(internal1_m1651_x0) был приход сигнала x1
	 1174	,8	,1	,&internal1_m1651_y0},	//(internal1_m1651_y0) интервал между сигналами х1 и х2
	 1175	,1	,1	,&internal1_m1664_q0},	//(internal1_m1664_q0) q0 - внутренний параметр
	 1176	,8	,1	,&internal1_m1677_tx},	//(internal1_m1677_tx) tx - время накопленное сек
	 1177	,18	,1	,&internal1_m1677_y0},	//(internal1_m1677_y0) y0
	 1178	,1	,1	,&internal1_m1679_q0},	//(internal1_m1679_q0) q0 - внутренний параметр
	 1179	,1	,1	,&internal1_m1684_q0},	//(internal1_m1684_q0) q0 - внутренний параметр
	 1180	,8	,1	,&internal1_m1685_tim},	//(internal1_m1685_tim) - время задержки выходного сигнала
	 1181	,1	,1	,&internal1_m1685_x0},	//(internal1_m1685_x0) - значение входного параметра на предыдущем шаге
	 1182	,8	,1	,&internal1_m1686_q0},	//(internal1_m1686_q0) q0 - внутренний параметр
	 1183	,8	,1	,&internal1_m1688_tim},	//(internal1_m1688_tim) - время задержки выходного сигнала
	 1184	,1	,1	,&internal1_m1688_x0},	//(internal1_m1688_x0) - значение входного параметра на предыдущем шаге
	 1185	,8	,1	,&internal1_m1689_q0},	//(internal1_m1689_q0) q0 - внутренний параметр
	 1186	,8	,1	,&internal1_m1696_tx},	//(internal1_m1696_tx) tx - время накопленное сек
	 1187	,18	,1	,&internal1_m1696_y0},	//(internal1_m1696_y0) y0
	 1188	,1	,1	,&internal1_m1699_q0},	//(internal1_m1699_q0) q0 - внутренний параметр
	 1189	,1	,1	,&internal1_m1700_fef},	//(internal1_m1700_fef) FirstEnterFlag
	 1190	,1	,1	,&internal1_m1700_x0},	//(internal1_m1700_x0) был приход сигнала x1
	 1191	,8	,1	,&internal1_m1700_y0},	//(internal1_m1700_y0) интервал между сигналами х1 и х2
	 1192	,8	,1	,&internal1_m1702_tx},	//(internal1_m1702_tx) tx - время накопленное сек
	 1193	,18	,1	,&internal1_m1702_y0},	//(internal1_m1702_y0) y0
	 1194	,1	,1	,&internal1_m1705_fef},	//(internal1_m1705_fef) FirstEnterFlag
	 1195	,1	,1	,&internal1_m1705_x0},	//(internal1_m1705_x0) был приход сигнала x1
	 1196	,8	,1	,&internal1_m1705_y0},	//(internal1_m1705_y0) интервал между сигналами х1 и х2
	 1197	,1	,1	,&internal1_m1706_q0},	//(internal1_m1706_q0) q0 - внутренний параметр
	 1198	,1	,1	,&internal1_m1720_q0},	//(internal1_m1720_q0) q0 - внутренний параметр
	 1199	,1	,1	,&internal1_m1721_q0},	//(internal1_m1721_q0) q0 - внутренний параметр
	 1200	,18	,1	,&internal1_m176_BLDv0},	//(internal1_m176_BLDv0) BlDv - Блокировка движения
	 1201	,8	,1	,&internal1_m176_X0},	//(internal1_m176_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	 1202	,8	,1	,&internal1_m176_t0},	//(internal1_m176_t0) время нахождения в зоне возврата
	 1203	,8	,1	,&internal1_m1772_tx},	//(internal1_m1772_tx) tx - внутренний параметр
	 1204	,8	,1	,&internal1_m1773_tx},	//(internal1_m1773_tx) tx - внутренний параметр
	 1205	,8	,1	,&internal1_m1775_tx},	//(internal1_m1775_tx) tx - внутренний параметр
	 1206	,8	,1	,&internal1_m1777_tx},	//(internal1_m1777_tx) tx - внутренний параметр
	 1207	,8	,1	,&internal1_m1786_tx},	//(internal1_m1786_tx) tx - внутренний параметр
	 1208	,8	,1	,&internal1_m1791_tx},	//(internal1_m1791_tx) tx - внутренний параметр
	 1209	,8	,1	,&internal1_m1792_tx},	//(internal1_m1792_tx) tx - внутренний параметр
	 1210	,8	,1	,&internal1_m1794_tx},	//(internal1_m1794_tx) tx - внутренний параметр
	 1211	,18	,1	,&internal1_m1804_BLDv0},	//(internal1_m1804_BLDv0) BlDv - Блокировка движения
	 1212	,8	,1	,&internal1_m1804_X0},	//(internal1_m1804_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	 1213	,8	,1	,&internal1_m1804_t0},	//(internal1_m1804_t0) время нахождения в зоне возврата
	 1214	,18	,1	,&internal1_m1807_BlDv0},	//(internal1_m1807_BlDv0) - была блокировка
	 1215	,18	,1	,&internal1_m1807_DvDw0},	//(internal1_m1807_DvDw0) - есть команда на движение назад
	 1216	,18	,1	,&internal1_m1807_DvUp0},	//(internal1_m1807_DvUp0) - есть команда на движение вперёд
	 1217	,18	,1	,&internal1_m1807_FDvDw0},	//(internal1_m1807_FDvDw0) - есть команда на движение назад
	 1218	,18	,1	,&internal1_m1807_FDvUp0},	//(internal1_m1807_FDvUp0) - есть команда на движение вперёд
	 1219	,18	,1	,&internal1_m1807_Pkav0},	//(internal1_m1807_Pkav0) Pkav - передний конечный аварийный выключатель
	 1220	,18	,1	,&internal1_m1807_Pkv0},	//(internal1_m1807_Pkv0) Pkv - передний конечный выключатель
	 1221	,18	,1	,&internal1_m1807_Zkav0},	//(internal1_m1807_Zkav0) Zkav - задний конечный аварийный выключатель
	 1222	,18	,1	,&internal1_m1807_Zkv0},	//(internal1_m1807_Zkv0) Zkv - задний конечный выключатель
	 1223	,18	,1	,&internal1_m1807_fef},	//(internal1_m1807_fef) fef
	 1224	,8	,1	,&internal1_m1807_txHr},	//(internal1_m1807_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	 1225	,8	,1	,&internal1_m1807_txLd},	//(internal1_m1807_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	 1226	,8	,1	,&internal1_m1807_txNm},	//(internal1_m1807_txNm) txNm - счётчик задержки сигнализации недвижения
	 1227	,8	,1	,&internal1_m1807_txSm},	//(internal1_m1807_txSm) txSm - счётчик задержки сигнализации самохода
	 1228	,8	,1	,&internal1_m1808_tx},	//(internal1_m1808_tx) tx - внутренний параметр
	 1229	,8	,1	,&internal1_m1813_tx},	//(internal1_m1813_tx) tx - внутренний параметр
	 1230	,8	,1	,&internal1_m1818_tx},	//(internal1_m1818_tx) tx - время накопленное сек
	 1231	,18	,1	,&internal1_m1818_y0},	//(internal1_m1818_y0) y0
	 1232	,8	,1	,&internal1_m1819_tx},	//(internal1_m1819_tx) tx - внутренний параметр
	 1233	,8	,1	,&internal1_m1821_tx},	//(internal1_m1821_tx) tx - внутренний параметр
	 1234	,8	,1	,&internal1_m1822_tx},	//(internal1_m1822_tx) tx - время накопленное сек
	 1235	,18	,1	,&internal1_m1822_y0},	//(internal1_m1822_y0) y0
	 1236	,8	,1	,&internal1_m1826_DelSp},	//(internal1_m1826_DelSp) DelSp - время переключения скоростей
	 1237	,1	,1	,&internal1_m1826_ShCntlSp0},	//(internal1_m1826_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	 1238	,1	,1	,&internal1_m1826_Shift0},	//(internal1_m1826_Shift0) Shift0 - признак самохода
	 1239	,1	,1	,&internal1_m1826_ShiftControl},	//(internal1_m1826_ShiftControl) ShiftControl - признак самохода
	 1240	,8	,1	,&internal1_m1826_Speed0},	//(internal1_m1826_Speed0) Speed0 - предыдущее значение скорости перемещения
	 1241	,8	,1	,&internal1_m1826_StSpeed},	//(internal1_m1826_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	 1242	,8	,1	,&internal1_m1826_Vz0},	//(internal1_m1826_Vz0) Vz0 - предыдущая заданная скорость
	 1243	,3	,1	,&internal1_m1826_flRazg},	//(internal1_m1826_flRazg) признак разгона/торможения
	 1244	,8	,1	,&internal1_m1826_sumtim},	//(internal1_m1826_sumtim) sumtim - время в пути
	 1245	,8	,20	,&internal1_m1826_tim0},	//(internal1_m1826_tim0) tim0 - массив значений времени цикла
	 1246	,8	,1	,&internal1_m1826_tx},	//(internal1_m1826_tx) tx
	 1247	,8	,1	,&internal1_m1826_txBl},	//(internal1_m1826_txBl) tx
	 1248	,8	,1	,&internal1_m1826_txMBl},	//(internal1_m1826_txMBl) tx
	 1249	,8	,1	,&internal1_m1826_txZS},	//(internal1_m1826_txZS) txZS
	 1250	,8	,1	,&internal1_m1826_txd},	//(internal1_m1826_txd) txd
	 1251	,8	,1	,&internal1_m1826_tz0},	//(internal1_m1826_tz0) tz0 - время защиты от нового задания сек
	 1252	,8	,20	,&internal1_m1826_x0},	//(internal1_m1826_x0) x0 - массив мгновенных значений координат
	 1253	,3	,1	,&internal1_m1826_xptr},	//(internal1_m1826_xptr) указатель текущей позиции в массиве координат
	 1254	,8	,1	,&internal1_m1826_xz0},	//(internal1_m1826_xz0) xz0 - новое задание мм
	 1255	,8	,1	,&internal1_m1826_z0},	//(internal1_m1826_z0) z0 - точка прекращения движения
	 1256	,8	,1	,&internal1_m1828_tx},	//(internal1_m1828_tx) tx - внутренний параметр
	 1257	,8	,1	,&internal1_m1829_tx},	//(internal1_m1829_tx) tx - внутренний параметр
	 1258	,8	,1	,&internal1_m1832_tx},	//(internal1_m1832_tx) tx - время накопленное сек
	 1259	,18	,1	,&internal1_m1832_y0},	//(internal1_m1832_y0) y0
	 1260	,1	,1	,&internal1_m1850_q0},	//(internal1_m1850_q0) q0 - внутренний параметр
	 1261	,1	,1	,&internal1_m1852_q0},	//(internal1_m1852_q0) q0 - внутренний параметр
	 1262	,1	,1	,&internal1_m1853_q0},	//(internal1_m1853_q0) q0 - внутренний параметр
	 1263	,1	,1	,&internal1_m1855_q0},	//(internal1_m1855_q0) q0 - внутренний параметр
	 1264	,1	,1	,&internal1_m1856_q0},	//(internal1_m1856_q0) q0 - внутренний параметр
	 1265	,1	,1	,&internal1_m1858_q0},	//(internal1_m1858_q0) q0 - внутренний параметр
	 1266	,1	,1	,&internal1_m1860_q0},	//(internal1_m1860_q0) q0 - внутренний параметр
	 1267	,1	,1	,&internal1_m1862_q0},	//(internal1_m1862_q0) q0 - внутренний параметр
	 1268	,1	,1	,&internal1_m1864_q0},	//(internal1_m1864_q0) q0 - внутренний параметр
	 1269	,1	,1	,&internal1_m1865_q0},	//(internal1_m1865_q0) q0 - внутренний параметр
	 1270	,1	,1	,&internal1_m1866_q0},	//(internal1_m1866_q0) q0 - внутренний параметр
	 1271	,1	,1	,&internal1_m1867_q0},	//(internal1_m1867_q0) q0 - внутренний параметр
	 1272	,1	,1	,&internal1_m1876_q0},	//(internal1_m1876_q0) q0 - внутренний параметр
	 1273	,1	,1	,&internal1_m1878_q0},	//(internal1_m1878_q0) q0 - внутренний параметр
	 1274	,1	,1	,&internal1_m1880_q0},	//(internal1_m1880_q0) q0 - внутренний параметр
	 1275	,1	,1	,&internal1_m1882_q0},	//(internal1_m1882_q0) q0 - внутренний параметр
	 1276	,1	,1	,&internal1_m1884_q0},	//(internal1_m1884_q0) q0 - внутренний параметр
	 1277	,1	,1	,&internal1_m1886_q0},	//(internal1_m1886_q0) q0 - внутренний параметр
	 1278	,1	,1	,&internal1_m1888_q0},	//(internal1_m1888_q0) q0 - внутренний параметр
	 1279	,1	,1	,&internal1_m1890_q0},	//(internal1_m1890_q0) q0 - внутренний параметр
	 1280	,1	,1	,&internal1_m1898_q0},	//(internal1_m1898_q0) q0 - внутренний параметр
	 1281	,1	,1	,&internal1_m1899_q0},	//(internal1_m1899_q0) q0 - внутренний параметр
	 1282	,1	,1	,&internal1_m1900_q0},	//(internal1_m1900_q0) q0 - внутренний параметр
	 1283	,1	,1	,&internal1_m1907_q0},	//(internal1_m1907_q0) q0 - внутренний параметр
	 1284	,1	,1	,&internal1_m1909_q0},	//(internal1_m1909_q0) q0 - внутренний параметр
	 1285	,1	,1	,&internal1_m1911_q0},	//(internal1_m1911_q0) q0 - внутренний параметр
	 1286	,1	,1	,&internal1_m1913_q0},	//(internal1_m1913_q0) q0 - внутренний параметр
	 1287	,1	,1	,&internal1_m1915_q0},	//(internal1_m1915_q0) q0 - внутренний параметр
	 1288	,1	,1	,&internal1_m1917_q0},	//(internal1_m1917_q0) q0 - внутренний параметр
	 1289	,1	,1	,&internal1_m1920_q0},	//(internal1_m1920_q0) q0 - внутренний параметр
	 1290	,1	,1	,&internal1_m1923_q0},	//(internal1_m1923_q0) q0 - внутренний параметр
	 1291	,1	,1	,&internal1_m1925_q0},	//(internal1_m1925_q0) q0 - внутренний параметр
	 1292	,1	,1	,&internal1_m1928_q0},	//(internal1_m1928_q0) q0 - внутренний параметр
	 1293	,1	,1	,&internal1_m1934_MyFirstEnterFlag},	//(internal1_m1934_MyFirstEnterFlag) MyFirstEnterFlag
	 1294	,1	,1	,&internal1_m1934_Pv0},	//(internal1_m1934_Pv0)  - Пер. выключатель механизма
	 1295	,1	,1	,&internal1_m1934_Zv0},	//(internal1_m1934_Zv0)  - Зад. выключатель механизма
	 1296	,1	,1	,&internal1_m1937_MyFirstEnterFlag},	//(internal1_m1937_MyFirstEnterFlag) MyFirstEnterFlag
	 1297	,1	,1	,&internal1_m1937_Pv0},	//(internal1_m1937_Pv0)  - Пер. выключатель механизма
	 1298	,1	,1	,&internal1_m1937_Zv0},	//(internal1_m1937_Zv0)  - Зад. выключатель механизма
	 1299	,8	,1	,&internal1_m193_tx},	//(internal1_m193_tx) tx - время накопленное сек
	 1300	,18	,1	,&internal1_m193_y0},	//(internal1_m193_y0) y0
	 1301	,1	,1	,&internal1_m1947_q0},	//(internal1_m1947_q0) q0 - внутренний параметр
	 1302	,8	,1	,&internal1_m194_tx},	//(internal1_m194_tx) tx - время накопленное сек
	 1303	,18	,1	,&internal1_m194_y0},	//(internal1_m194_y0) y0
	 1304	,1	,1	,&internal1_m1950_q0},	//(internal1_m1950_q0) q0 - внутренний параметр
	 1305	,1	,1	,&internal1_m1954_q0},	//(internal1_m1954_q0) q0 - внутренний параметр
	 1306	,1	,1	,&internal1_m1957_q0},	//(internal1_m1957_q0) q0 - внутренний параметр
	 1307	,1	,1	,&internal1_m1960_q0},	//(internal1_m1960_q0) q0 - внутренний параметр
	 1308	,1	,1	,&internal1_m1962_q0},	//(internal1_m1962_q0) q0 - внутренний параметр
	 1309	,1	,1	,&internal1_m19_q0},	//(internal1_m19_q0) q0 - внутренний параметр
	 1310	,8	,1	,&internal1_m201_DelSp},	//(internal1_m201_DelSp) DelSp - время переключения скоростей
	 1311	,1	,1	,&internal1_m201_ShCntlSp0},	//(internal1_m201_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	 1312	,1	,1	,&internal1_m201_Shift0},	//(internal1_m201_Shift0) Shift0 - признак самохода
	 1313	,1	,1	,&internal1_m201_ShiftControl},	//(internal1_m201_ShiftControl) ShiftControl - признак самохода
	 1314	,8	,1	,&internal1_m201_Speed0},	//(internal1_m201_Speed0) Speed0 - предыдущее значение скорости перемещения
	 1315	,8	,1	,&internal1_m201_StSpeed},	//(internal1_m201_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	 1316	,8	,1	,&internal1_m201_Vz0},	//(internal1_m201_Vz0) Vz0 - предыдущая заданная скорость
	 1317	,3	,1	,&internal1_m201_flRazg},	//(internal1_m201_flRazg) признак разгона/торможения
	 1318	,8	,1	,&internal1_m201_sumtim},	//(internal1_m201_sumtim) sumtim - время в пути
	 1319	,8	,150	,&internal1_m201_tim0},	//(internal1_m201_tim0) tim0 - массив значений времени цикла
	 1320	,8	,1	,&internal1_m201_tx},	//(internal1_m201_tx) tx
	 1321	,8	,1	,&internal1_m201_txBl},	//(internal1_m201_txBl) tx
	 1322	,8	,1	,&internal1_m201_txMBl},	//(internal1_m201_txMBl) tx
	 1323	,8	,1	,&internal1_m201_txZS},	//(internal1_m201_txZS) txZS
	 1324	,8	,1	,&internal1_m201_txd},	//(internal1_m201_txd) txd
	 1325	,8	,1	,&internal1_m201_tz0},	//(internal1_m201_tz0) tz0 - время защиты от нового задания сек
	 1326	,8	,150	,&internal1_m201_x0},	//(internal1_m201_x0) x0 - массив мгновенных значений координат
	 1327	,3	,1	,&internal1_m201_xptr},	//(internal1_m201_xptr) указатель текущей позиции в массиве координат
	 1328	,8	,1	,&internal1_m201_xz0},	//(internal1_m201_xz0) xz0 - новое задание мм
	 1329	,8	,1	,&internal1_m201_z0},	//(internal1_m201_z0) z0 - точка прекращения движения
	 1330	,8	,1	,&internal1_m2027_tx},	//(internal1_m2027_tx) tx - время накопленное сек
	 1331	,18	,1	,&internal1_m2027_y0},	//(internal1_m2027_y0) y0
	 1332	,8	,1	,&internal1_m2028_tx},	//(internal1_m2028_tx) tx - время накопленное сек
	 1333	,18	,1	,&internal1_m2028_y0},	//(internal1_m2028_y0) y0
	 1334	,8	,1	,&internal1_m2029_tx},	//(internal1_m2029_tx) tx - время накопленное сек
	 1335	,18	,1	,&internal1_m2029_y0},	//(internal1_m2029_y0) y0
	 1336	,8	,1	,&internal1_m202_tx},	//(internal1_m202_tx) tx - внутренний параметр
	 1337	,8	,1	,&internal1_m2030_tx},	//(internal1_m2030_tx) tx - время накопленное сек
	 1338	,18	,1	,&internal1_m2030_y0},	//(internal1_m2030_y0) y0
	 1339	,8	,1	,&internal1_m203_tx},	//(internal1_m203_tx) tx - внутренний параметр
	 1340	,8	,1	,&internal1_m204_tx},	//(internal1_m204_tx) tx - внутренний параметр
	 1341	,8	,1	,&internal1_m2065_tx},	//(internal1_m2065_tx) tx - внутренний параметр
	 1342	,8	,1	,&internal1_m2066_tx},	//(internal1_m2066_tx) tx - внутренний параметр
	 1343	,8	,1	,&internal1_m2072_tim},	//(internal1_m2072_tim) - время задержки выходного сигнала
	 1344	,1	,1	,&internal1_m2072_x0},	//(internal1_m2072_x0) - значение входного параметра на предыдущем шаге
	 1345	,1	,1	,&internal1_m2073_q0},	//(internal1_m2073_q0) q0 - внутренний параметр
	 1346	,8	,1	,&internal1_m2077_tx},	//(internal1_m2077_tx) tx - время накопленное сек
	 1347	,18	,1	,&internal1_m2077_y0},	//(internal1_m2077_y0) y0
	 1348	,1	,1	,&internal1_m2080_q0},	//(internal1_m2080_q0) q0 - внутренний параметр
	 1349	,1	,1	,&internal1_m2082_fef},	//(internal1_m2082_fef) FirstEnterFlag
	 1350	,1	,1	,&internal1_m2082_x0},	//(internal1_m2082_x0) был приход сигнала x1
	 1351	,8	,1	,&internal1_m2082_y0},	//(internal1_m2082_y0) интервал между сигналами х1 и х2
	 1352	,1	,1	,&internal1_m2087_q0},	//(internal1_m2087_q0) q0 - внутренний параметр
	 1353	,8	,1	,&internal1_m2091_q0},	//(internal1_m2091_q0) q0 - внутренний параметр
	 1354	,1	,1	,&internal1_m2100_q0},	//(internal1_m2100_q0) q0 - внутренний параметр
	 1355	,8	,1	,&internal1_m2101_tim},	//(internal1_m2101_tim) - время задержки выходного сигнала
	 1356	,1	,1	,&internal1_m2101_x0},	//(internal1_m2101_x0) - значение входного параметра на предыдущем шаге
	 1357	,8	,1	,&internal1_m2109_tx},	//(internal1_m2109_tx) tx - время накопленное сек
	 1358	,18	,1	,&internal1_m2109_y0},	//(internal1_m2109_y0) y0
	 1359	,8	,1	,&internal1_m210_tx},	//(internal1_m210_tx) tx - внутренний параметр
	 1360	,1	,1	,&internal1_m2112_q0},	//(internal1_m2112_q0) q0 - внутренний параметр
	 1361	,8	,1	,&internal1_m2121_tx},	//(internal1_m2121_tx) tx - время накопленное сек
	 1362	,18	,1	,&internal1_m2121_y0},	//(internal1_m2121_y0) y0
	 1363	,1	,1	,&internal1_m2123_fef},	//(internal1_m2123_fef) FirstEnterFlag
	 1364	,1	,1	,&internal1_m2123_x0},	//(internal1_m2123_x0) был приход сигнала x1
	 1365	,8	,1	,&internal1_m2123_y0},	//(internal1_m2123_y0) интервал между сигналами х1 и х2
	 1366	,8	,1	,&internal1_m2124_tx},	//(internal1_m2124_tx) tx - время накопленное сек
	 1367	,18	,1	,&internal1_m2124_y0},	//(internal1_m2124_y0) y0
	 1368	,8	,1	,&internal1_m2131_q0},	//(internal1_m2131_q0) q0 - внутренний параметр
	 1369	,1	,1	,&internal1_m2141_q0},	//(internal1_m2141_q0) q0 - внутренний параметр
	 1370	,1	,1	,&internal1_m2157_q0},	//(internal1_m2157_q0) q0 - внутренний параметр
	 1371	,1	,1	,&internal1_m2158_q0},	//(internal1_m2158_q0) q0 - внутренний параметр
	 1372	,8	,1	,&internal1_m215_tx},	//(internal1_m215_tx) tx - время накопленное сек
	 1373	,18	,1	,&internal1_m215_y0},	//(internal1_m215_y0) y0
	 1374	,8	,1	,&internal1_m2166_tx},	//(internal1_m2166_tx) tx - внутренний параметр
	 1375	,8	,1	,&internal1_m2169_tx},	//(internal1_m2169_tx) tx - внутренний параметр
	 1376	,1	,1	,&internal1_m2172_q0},	//(internal1_m2172_q0) q0 - внутренний параметр
	 1377	,8	,1	,&internal1_m2179_tx},	//(internal1_m2179_tx) tx - внутренний параметр
	 1378	,8	,1	,&internal1_m2182_tx},	//(internal1_m2182_tx) tx - внутренний параметр
	 1379	,1	,1	,&internal1_m2184_q0},	//(internal1_m2184_q0) q0 - внутренний параметр
	 1380	,8	,1	,&internal1_m2194_tx},	//(internal1_m2194_tx) tx - внутренний параметр
	 1381	,8	,1	,&internal1_m2197_tx},	//(internal1_m2197_tx) tx - внутренний параметр
	 1382	,8	,1	,&internal1_m21_tx},	//(internal1_m21_tx) tx - внутренний параметр
	 1383	,1	,1	,&internal1_m2200_q0},	//(internal1_m2200_q0) q0 - внутренний параметр
	 1384	,8	,1	,&internal1_m2208_tx},	//(internal1_m2208_tx) tx - внутренний параметр
	 1385	,8	,1	,&internal1_m220_tx},	//(internal1_m220_tx) tx - внутренний параметр
	 1386	,1	,1	,&internal1_m2212_q0},	//(internal1_m2212_q0) q0 - внутренний параметр
	 1387	,8	,1	,&internal1_m2218_tx},	//(internal1_m2218_tx) tx - внутренний параметр
	 1388	,8	,1	,&internal1_m221_tx},	//(internal1_m221_tx) tx - время накопленное сек
	 1389	,18	,1	,&internal1_m221_y0},	//(internal1_m221_y0) y0
	 1390	,8	,1	,&internal1_m2222_tx},	//(internal1_m2222_tx) tx - внутренний параметр
	 1391	,1	,1	,&internal1_m2228_q0},	//(internal1_m2228_q0) q0 - внутренний параметр
	 1392	,8	,1	,&internal1_m2229_tx},	//(internal1_m2229_tx) tx - время накопленное сек
	 1393	,18	,1	,&internal1_m2229_y0},	//(internal1_m2229_y0) y0
	 1394	,8	,1	,&internal1_m2233_tx},	//(internal1_m2233_tx) tx - внутренний параметр
	 1395	,1	,1	,&internal1_m2236_q0},	//(internal1_m2236_q0) q0 - внутренний параметр
	 1396	,8	,1	,&internal1_m2237_tx},	//(internal1_m2237_tx) tx - время накопленное сек
	 1397	,18	,1	,&internal1_m2237_y0},	//(internal1_m2237_y0) y0
	 1398	,8	,1	,&internal1_m2243_tx},	//(internal1_m2243_tx) tx - внутренний параметр
	 1399	,8	,1	,&internal1_m2251_tx},	//(internal1_m2251_tx) tx - внутренний параметр
	 1400	,1	,1	,&internal1_m2253_q0},	//(internal1_m2253_q0) q0 - внутренний параметр
	 1401	,8	,1	,&internal1_m2260_tx},	//(internal1_m2260_tx) tx - внутренний параметр
	 1402	,8	,1	,&internal1_m2264_tx},	//(internal1_m2264_tx) tx - время накопленное сек
	 1403	,18	,1	,&internal1_m2264_y0},	//(internal1_m2264_y0) y0
	 1404	,8	,1	,&internal1_m2266_tx},	//(internal1_m2266_tx) tx - внутренний параметр
	 1405	,1	,1	,&internal1_m2269_q0},	//(internal1_m2269_q0) q0 - внутренний параметр
	 1406	,8	,1	,&internal1_m2271_tx},	//(internal1_m2271_tx) tx - внутренний параметр
	 1407	,8	,1	,&internal1_m2272_tx},	//(internal1_m2272_tx) tx - внутренний параметр
	 1408	,8	,1	,&internal1_m2275_tx},	//(internal1_m2275_tx) tx - время накопленное сек
	 1409	,18	,1	,&internal1_m2275_y0},	//(internal1_m2275_y0) y0
	 1410	,8	,1	,&internal1_m2283_tx},	//(internal1_m2283_tx) tx - внутренний параметр
	 1411	,8	,1	,&internal1_m2284_tx},	//(internal1_m2284_tx) tx - внутренний параметр
	 1412	,8	,1	,&internal1_m2286_tx},	//(internal1_m2286_tx) tx - внутренний параметр
	 1413	,8	,1	,&internal1_m228_tx},	//(internal1_m228_tx) tx - внутренний параметр
	 1414	,1	,1	,&internal1_m2292_q0},	//(internal1_m2292_q0) q0 - внутренний параметр
	 1415	,1	,1	,&internal1_m2294_q0},	//(internal1_m2294_q0) q0 - внутренний параметр
	 1416	,8	,1	,&internal1_m2300_tx},	//(internal1_m2300_tx) tx - внутренний параметр
	 1417	,8	,1	,&internal1_m230_tx},	//(internal1_m230_tx) tx - внутренний параметр
	 1418	,8	,1	,&internal1_m2313_tx},	//(internal1_m2313_tx) tx - внутренний параметр
	 1419	,8	,1	,&internal1_m2314_tx},	//(internal1_m2314_tx) tx - внутренний параметр
	 1420	,8	,1	,&internal1_m2315_tx},	//(internal1_m2315_tx) tx - внутренний параметр
	 1421	,18	,1	,&internal1_m2319_BlDv0},	//(internal1_m2319_BlDv0) - была блокировка
	 1422	,18	,1	,&internal1_m2319_DvDw0},	//(internal1_m2319_DvDw0) - есть команда на движение назад
	 1423	,18	,1	,&internal1_m2319_DvUp0},	//(internal1_m2319_DvUp0) - есть команда на движение вперёд
	 1424	,18	,1	,&internal1_m2319_FDvDw0},	//(internal1_m2319_FDvDw0) - есть команда на движение назад
	 1425	,18	,1	,&internal1_m2319_FDvUp0},	//(internal1_m2319_FDvUp0) - есть команда на движение вперёд
	 1426	,18	,1	,&internal1_m2319_Pkav0},	//(internal1_m2319_Pkav0) Pkav - передний конечный аварийный выключатель
	 1427	,18	,1	,&internal1_m2319_Pkv0},	//(internal1_m2319_Pkv0) Pkv - передний конечный выключатель
	 1428	,18	,1	,&internal1_m2319_Zkav0},	//(internal1_m2319_Zkav0) Zkav - задний конечный аварийный выключатель
	 1429	,18	,1	,&internal1_m2319_Zkv0},	//(internal1_m2319_Zkv0) Zkv - задний конечный выключатель
	 1430	,18	,1	,&internal1_m2319_fef},	//(internal1_m2319_fef) fef
	 1431	,8	,1	,&internal1_m2319_txHr},	//(internal1_m2319_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	 1432	,8	,1	,&internal1_m2319_txLd},	//(internal1_m2319_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	 1433	,8	,1	,&internal1_m2319_txNm},	//(internal1_m2319_txNm) txNm - счётчик задержки сигнализации недвижения
	 1434	,8	,1	,&internal1_m2319_txSm},	//(internal1_m2319_txSm) txSm - счётчик задержки сигнализации самохода
	 1435	,8	,1	,&internal1_m2320_tx},	//(internal1_m2320_tx) tx - внутренний параметр
	 1436	,18	,1	,&internal1_m2325_BlDv0},	//(internal1_m2325_BlDv0) - была блокировка
	 1437	,18	,1	,&internal1_m2325_DvDw0},	//(internal1_m2325_DvDw0) - есть команда на движение назад
	 1438	,18	,1	,&internal1_m2325_DvUp0},	//(internal1_m2325_DvUp0) - есть команда на движение вперёд
	 1439	,18	,1	,&internal1_m2325_FDvDw0},	//(internal1_m2325_FDvDw0) - есть команда на движение назад
	 1440	,18	,1	,&internal1_m2325_FDvUp0},	//(internal1_m2325_FDvUp0) - есть команда на движение вперёд
	 1441	,18	,1	,&internal1_m2325_Pkav0},	//(internal1_m2325_Pkav0) Pkav - передний конечный аварийный выключатель
	 1442	,18	,1	,&internal1_m2325_Pkv0},	//(internal1_m2325_Pkv0) Pkv - передний конечный выключатель
	 1443	,18	,1	,&internal1_m2325_Zkav0},	//(internal1_m2325_Zkav0) Zkav - задний конечный аварийный выключатель
	 1444	,18	,1	,&internal1_m2325_Zkv0},	//(internal1_m2325_Zkv0) Zkv - задний конечный выключатель
	 1445	,18	,1	,&internal1_m2325_fef},	//(internal1_m2325_fef) fef
	 1446	,8	,1	,&internal1_m2325_txHr},	//(internal1_m2325_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	 1447	,8	,1	,&internal1_m2325_txLd},	//(internal1_m2325_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	 1448	,8	,1	,&internal1_m2325_txNm},	//(internal1_m2325_txNm) txNm - счётчик задержки сигнализации недвижения
	 1449	,8	,1	,&internal1_m2325_txSm},	//(internal1_m2325_txSm) txSm - счётчик задержки сигнализации самохода
	 1450	,8	,1	,&internal1_m2328_tx},	//(internal1_m2328_tx) tx - внутренний параметр
	 1451	,8	,1	,&internal1_m2329_tx},	//(internal1_m2329_tx) tx - внутренний параметр
	 1452	,8	,1	,&internal1_m232_tx},	//(internal1_m232_tx) tx - внутренний параметр
	 1453	,8	,1	,&internal1_m2330_tx},	//(internal1_m2330_tx) tx - внутренний параметр
	 1454	,1	,1	,&internal1_m2337_q0},	//(internal1_m2337_q0) q0 - внутренний параметр
	 1455	,1	,1	,&internal1_m2338_q0},	//(internal1_m2338_q0) q0 - внутренний параметр
	 1456	,1	,1	,&internal1_m2339_q0},	//(internal1_m2339_q0) q0 - внутренний параметр
	 1457	,1	,1	,&internal1_m2340_q0},	//(internal1_m2340_q0) q0 - внутренний параметр
	 1458	,1	,1	,&internal1_m2342_q0},	//(internal1_m2342_q0) q0 - внутренний параметр
	 1459	,1	,1	,&internal1_m2349_q0},	//(internal1_m2349_q0) q0 - внутренний параметр
	 1460	,1	,1	,&internal1_m2351_q0},	//(internal1_m2351_q0) q0 - внутренний параметр
	 1461	,1	,1	,&internal1_m2353_q0},	//(internal1_m2353_q0) q0 - внутренний параметр
	 1462	,1	,1	,&internal1_m2355_q0},	//(internal1_m2355_q0) q0 - внутренний параметр
	 1463	,1	,1	,&internal1_m2357_q0},	//(internal1_m2357_q0) q0 - внутренний параметр
	 1464	,1	,1	,&internal1_m2359_q0},	//(internal1_m2359_q0) q0 - внутренний параметр
	 1465	,1	,1	,&internal1_m2361_q0},	//(internal1_m2361_q0) q0 - внутренний параметр
	 1466	,1	,1	,&internal1_m2368_q0},	//(internal1_m2368_q0) q0 - внутренний параметр
	 1467	,1	,1	,&internal1_m2369_q0},	//(internal1_m2369_q0) q0 - внутренний параметр
	 1468	,1	,1	,&internal1_m2370_q0},	//(internal1_m2370_q0) q0 - внутренний параметр
	 1469	,1	,1	,&internal1_m2372_q0},	//(internal1_m2372_q0) q0 - внутренний параметр
	 1470	,1	,1	,&internal1_m2373_q0},	//(internal1_m2373_q0) q0 - внутренний параметр
	 1471	,1	,1	,&internal1_m2380_q0},	//(internal1_m2380_q0) q0 - внутренний параметр
	 1472	,1	,1	,&internal1_m2382_q0},	//(internal1_m2382_q0) q0 - внутренний параметр
	 1473	,1	,1	,&internal1_m2384_q0},	//(internal1_m2384_q0) q0 - внутренний параметр
	 1474	,1	,1	,&internal1_m2386_q0},	//(internal1_m2386_q0) q0 - внутренний параметр
	 1475	,1	,1	,&internal1_m2388_q0},	//(internal1_m2388_q0) q0 - внутренний параметр
	 1476	,1	,1	,&internal1_m2390_q0},	//(internal1_m2390_q0) q0 - внутренний параметр
	 1477	,1	,1	,&internal1_m2392_q0},	//(internal1_m2392_q0) q0 - внутренний параметр
	 1478	,3	,1	,&internal1_m2408_FlCmp},	//(internal1_m2408_FlCmp) - текущее направление изменения мощности
	 1479	,3	,1	,&internal1_m2408_FlIzm},	//(internal1_m2408_FlIzm) - флаг изменения направления изменения мощности
	 1480	,3	,1	,&internal1_m2408_FlPar},	//(internal1_m2408_FlPar) - стартовый этап регулирования
	 1481	,3	,1	,&internal1_m2408_LastStage},	//(internal1_m2408_LastStage)  - последний этап
	 1482	,3	,1	,&internal1_m2408_SrCoun},	//(internal1_m2408_SrCoun)  - счётчик усреднения
	 1483	,3	,1	,&internal1_m2408_StabCoun},	//(internal1_m2408_StabCoun) - счётчик стабильности
	 1484	,3	,1	,&internal1_m2408_ZerCoun},	//(internal1_m2408_ZerCoun) - счётчик полной остановки
	 1485	,8	,1	,&internal1_m2408_fMaxDk},	//(internal1_m2408_fMaxDk)  - изменение координаты при смене задания 
	 1486	,8	,1	,&internal1_m2408_fRct},	//(internal1_m2408_fRct)  - стартовая реактивность регулятора 
	 1487	,8	,1	,&internal1_m2408_fRsg},	//(internal1_m2408_fRsg)  - рассогласование между текущей и заданной мощностью 
	 1488	,8	,1	,&internal1_m2408_fStw0},	//(internal1_m2408_fStw0)  - значение стартовой мощности включения ИМ 
	 1489	,8	,1	,&internal1_m2408_fTk0},	//(internal1_m2408_fTk0)  - последняя температура 
	 1490	,8	,1	,&internal1_m2408_fVf0},	//(internal1_m2408_fVf0)  - скорость изменения мощности 
	 1491	,8	,1	,&internal1_m2408_fVfMin},	//(internal1_m2408_fVfMin)  - минимальная скорость 
	 1492	,1	,1	,&internal1_m2408_fef},	//(internal1_m2408_fef)  - первый вход
	 1493	,8	,1	,&internal1_m2408_fkizm},	//(internal1_m2408_fkizm)  - стартовая координата положения ИМ 0-й реактивности 
	 1494	,8	,1	,&internal1_m2408_ftf0},	//(internal1_m2408_ftf0)  - время от фиксации предыдущей мощности 
	 1495	,8	,1	,&internal1_m2408_fwt0},	//(internal1_m2408_fwt0)  - мощность на предыдущем шаге 
	 1496	,8	,1	,&internal1_m2408_fwz0},	//(internal1_m2408_fwz0)  - заданная мощность на предыдущем шаге 
	 1497	,8	,1	,&internal1_m2410_tx},	//(internal1_m2410_tx) tx - время накопленное сек
	 1498	,18	,1	,&internal1_m2410_y0},	//(internal1_m2410_y0) y0
	 1499	,8	,1	,&internal1_m2413_tx},	//(internal1_m2413_tx) tx - время накопленное сек
	 1500	,18	,1	,&internal1_m2413_y0},	//(internal1_m2413_y0) y0
	 1501	,8	,1	,&internal1_m2414_tx},	//(internal1_m2414_tx) tx - время накопленное сек
	 1502	,18	,1	,&internal1_m2414_y0},	//(internal1_m2414_y0) y0
	 1503	,8	,1	,&internal1_m241_tx},	//(internal1_m241_tx) tx - внутренний параметр
	 1504	,1	,1	,&internal1_m2420_q0},	//(internal1_m2420_q0) q0 - внутренний параметр
	 1505	,1	,1	,&internal1_m2426_q0},	//(internal1_m2426_q0) q0 - внутренний параметр
	 1506	,8	,1	,&internal1_m2428_tx},	//(internal1_m2428_tx) tx - внутренний параметр
	 1507	,8	,1	,&internal1_m2448_tx},	//(internal1_m2448_tx) tx - время накопленное сек
	 1508	,18	,1	,&internal1_m2448_y0},	//(internal1_m2448_y0) y0
	 1509	,8	,1	,&internal1_m2450_tx},	//(internal1_m2450_tx) tx - внутренний параметр
	 1510	,1	,1	,&internal1_m2453_q0},	//(internal1_m2453_q0) q0 - внутренний параметр
	 1511	,8	,1	,&internal1_m245_tx},	//(internal1_m245_tx) tx - внутренний параметр
	 1512	,8	,1	,&internal1_m2467_tx},	//(internal1_m2467_tx) tx - внутренний параметр
	 1513	,8	,1	,&internal1_m246_tx},	//(internal1_m246_tx) tx - внутренний параметр
	 1514	,8	,1	,&internal1_m2470_tx},	//(internal1_m2470_tx) tx - внутренний параметр
	 1515	,8	,1	,&internal1_m2471_tx},	//(internal1_m2471_tx) tx - внутренний параметр
	 1516	,8	,1	,&internal1_m2472_tx},	//(internal1_m2472_tx) tx - внутренний параметр
	 1517	,8	,1	,&internal1_m2552_tx},	//(internal1_m2552_tx) tx - время накопленное сек
	 1518	,18	,1	,&internal1_m2552_y0},	//(internal1_m2552_y0) y0
	 1519	,8	,1	,&internal1_m2554_tx},	//(internal1_m2554_tx) tx - время накопленное сек
	 1520	,18	,1	,&internal1_m2554_y0},	//(internal1_m2554_y0) y0
	 1521	,8	,1	,&internal1_m2556_tx},	//(internal1_m2556_tx) tx - время накопленное сек
	 1522	,18	,1	,&internal1_m2556_y0},	//(internal1_m2556_y0) y0
	 1523	,8	,1	,&internal1_m2558_tx},	//(internal1_m2558_tx) tx - время накопленное сек
	 1524	,18	,1	,&internal1_m2558_y0},	//(internal1_m2558_y0) y0
	 1525	,8	,1	,&internal1_m255_tx},	//(internal1_m255_tx) tx - внутренний параметр
	 1526	,8	,1	,&internal1_m258_tx},	//(internal1_m258_tx) tx - внутренний параметр
	 1527	,8	,1	,&internal1_m261_tx},	//(internal1_m261_tx) tx - внутренний параметр
	 1528	,1	,1	,&internal1_m26_q0},	//(internal1_m26_q0) q0 - внутренний параметр
	 1529	,8	,1	,&internal1_m270_tx},	//(internal1_m270_tx) tx - внутренний параметр
	 1530	,8	,1	,&internal1_m273_tx},	//(internal1_m273_tx) tx - внутренний параметр
	 1531	,8	,1	,&internal1_m274_tx},	//(internal1_m274_tx) tx - внутренний параметр
	 1532	,8	,1	,&internal1_m277_tx},	//(internal1_m277_tx) tx - внутренний параметр
	 1533	,8	,1	,&internal1_m278_tx},	//(internal1_m278_tx) tx - внутренний параметр
	 1534	,1	,1	,&internal1_m298_ErrPr0},	//(internal1_m298_ErrPr0) ErrPr - Приостановка программы по ошибке
	 1535	,1	,1	,&internal1_m298_FinPr0},	//(internal1_m298_FinPr0) FinPr - конец программы
	 1536	,1	,1	,&internal1_m298_MyFirstEnterFlag},	//(internal1_m298_MyFirstEnterFlag)  
	 1537	,3	,1	,&internal1_m298_Step},	//(internal1_m298_Step)  - текущий шаг программы
	 1538	,8	,1	,&internal1_m298_TimS},	//(internal1_m298_TimS) Время от старта программы
	 1539	,18	,10	,&internal1_m298_rz},	//(internal1_m298_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	 1540	,1	,1	,&internal1_m298_sb2UR0},	//(internal1_m298_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	 1541	,1	,1	,&internal1_m298_sbINI0},	//(internal1_m298_sbINI0) sbINI - запуск проверки ИНИ
	 1542	,1	,1	,&internal1_m298_sbNupIS0},	//(internal1_m298_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	 1543	,1	,1	,&internal1_m298_sbVuIS0},	//(internal1_m298_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	 1544	,1	,1	,&internal1_m298_sbVuRB0},	//(internal1_m298_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	 1545	,1	,1	,&internal1_m309_q0},	//(internal1_m309_q0) q0 - внутренний параметр
	 1546	,5	,1	,&internal1_m317_x0},	//(internal1_m317_x0) x0 - значение входного параметра на предыдущем шаге
	 1547	,1	,1	,&internal1_m318_q0},	//(internal1_m318_q0) q0 - внутренний параметр
	 1548	,8	,1	,&internal1_m321_TimS},	//(internal1_m321_TimS) Время до нулевого отсчета
	 1549	,1	,1	,&internal1_m321_pusk0},	//(internal1_m321_pusk0) pusk - разрешение выполнения программы
	 1550	,8	,1	,&internal1_m322_tx},	//(internal1_m322_tx) tx - внутренний параметр
	 1551	,8	,1	,&internal1_m339_tx},	//(internal1_m339_tx) tx - время накопленное сек
	 1552	,18	,1	,&internal1_m339_y0},	//(internal1_m339_y0) y0
	 1553	,1	,1	,&internal1_m356_ErrPr0},	//(internal1_m356_ErrPr0) ErrPr - Приостановка программы по ошибке
	 1554	,1	,1	,&internal1_m356_FinPr0},	//(internal1_m356_FinPr0) FinPr - конец программы
	 1555	,1	,1	,&internal1_m356_MyFirstEnterFlag},	//(internal1_m356_MyFirstEnterFlag)  
	 1556	,3	,1	,&internal1_m356_Step},	//(internal1_m356_Step)  - текущий шаг программы
	 1557	,8	,1	,&internal1_m356_TimS},	//(internal1_m356_TimS) Время от старта программы
	 1558	,18	,10	,&internal1_m356_rz},	//(internal1_m356_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	 1559	,1	,1	,&internal1_m356_sb2UR0},	//(internal1_m356_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	 1560	,1	,1	,&internal1_m356_sbINI0},	//(internal1_m356_sbINI0) sbINI - запуск проверки ИНИ
	 1561	,1	,1	,&internal1_m356_sbNupIS0},	//(internal1_m356_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	 1562	,1	,1	,&internal1_m356_sbVuIS0},	//(internal1_m356_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	 1563	,1	,1	,&internal1_m356_sbVuRB0},	//(internal1_m356_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	 1564	,1	,1	,&internal1_m362_q0},	//(internal1_m362_q0) q0 - внутренний параметр
	 1565	,5	,1	,&internal1_m364_x0},	//(internal1_m364_x0) x0 - значение входного параметра на предыдущем шаге
	 1566	,1	,1	,&internal1_m366_q0},	//(internal1_m366_q0) q0 - внутренний параметр
	 1567	,8	,1	,&internal1_m368_tx},	//(internal1_m368_tx) tx - внутренний параметр
	 1568	,18	,1	,&internal1_m390_BlDv0},	//(internal1_m390_BlDv0) - была блокировка
	 1569	,18	,1	,&internal1_m390_DvDw0},	//(internal1_m390_DvDw0) - есть команда на движение назад
	 1570	,18	,1	,&internal1_m390_DvUp0},	//(internal1_m390_DvUp0) - есть команда на движение вперёд
	 1571	,18	,1	,&internal1_m390_FDvDw0},	//(internal1_m390_FDvDw0) - есть команда на движение назад
	 1572	,18	,1	,&internal1_m390_FDvUp0},	//(internal1_m390_FDvUp0) - есть команда на движение вперёд
	 1573	,18	,1	,&internal1_m390_Pkav0},	//(internal1_m390_Pkav0) Pkav - передний конечный аварийный выключатель
	 1574	,18	,1	,&internal1_m390_Pkv0},	//(internal1_m390_Pkv0) Pkv - передний конечный выключатель
	 1575	,18	,1	,&internal1_m390_Zkav0},	//(internal1_m390_Zkav0) Zkav - задний конечный аварийный выключатель
	 1576	,18	,1	,&internal1_m390_Zkv0},	//(internal1_m390_Zkv0) Zkv - задний конечный выключатель
	 1577	,18	,1	,&internal1_m390_fef},	//(internal1_m390_fef) fef
	 1578	,8	,1	,&internal1_m390_txHr},	//(internal1_m390_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	 1579	,8	,1	,&internal1_m390_txLd},	//(internal1_m390_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	 1580	,8	,1	,&internal1_m390_txNm},	//(internal1_m390_txNm) txNm - счётчик задержки сигнализации недвижения
	 1581	,8	,1	,&internal1_m390_txSm},	//(internal1_m390_txSm) txSm - счётчик задержки сигнализации самохода
	 1582	,8	,1	,&internal1_m395_tx},	//(internal1_m395_tx) tx - внутренний параметр
	 1583	,8	,1	,&internal1_m396_tx},	//(internal1_m396_tx) tx - внутренний параметр
	 1584	,8	,1	,&internal1_m397_tx},	//(internal1_m397_tx) tx - внутренний параметр
	 1585	,8	,1	,&internal1_m398_tx},	//(internal1_m398_tx) tx - внутренний параметр
	 1586	,8	,1	,&internal1_m410_tx},	//(internal1_m410_tx) tx - внутренний параметр
	 1587	,8	,1	,&internal1_m411_tx},	//(internal1_m411_tx) tx - внутренний параметр
	 1588	,8	,1	,&internal1_m412_tx},	//(internal1_m412_tx) tx - внутренний параметр
	 1589	,8	,1	,&internal1_m415_tx},	//(internal1_m415_tx) tx - внутренний параметр
	 1590	,18	,1	,&internal1_m421_BlDv0},	//(internal1_m421_BlDv0) - была блокировка
	 1591	,18	,1	,&internal1_m421_DvDw0},	//(internal1_m421_DvDw0) - есть команда на движение назад
	 1592	,18	,1	,&internal1_m421_DvUp0},	//(internal1_m421_DvUp0) - есть команда на движение вперёд
	 1593	,18	,1	,&internal1_m421_FDvDw0},	//(internal1_m421_FDvDw0) - есть команда на движение назад
	 1594	,18	,1	,&internal1_m421_FDvUp0},	//(internal1_m421_FDvUp0) - есть команда на движение вперёд
	 1595	,18	,1	,&internal1_m421_Pkav0},	//(internal1_m421_Pkav0) Pkav - передний конечный аварийный выключатель
	 1596	,18	,1	,&internal1_m421_Pkv0},	//(internal1_m421_Pkv0) Pkv - передний конечный выключатель
	 1597	,18	,1	,&internal1_m421_Zkav0},	//(internal1_m421_Zkav0) Zkav - задний конечный аварийный выключатель
	 1598	,18	,1	,&internal1_m421_Zkv0},	//(internal1_m421_Zkv0) Zkv - задний конечный выключатель
	 1599	,18	,1	,&internal1_m421_fef},	//(internal1_m421_fef) fef
	 1600	,8	,1	,&internal1_m421_txHr},	//(internal1_m421_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	 1601	,8	,1	,&internal1_m421_txLd},	//(internal1_m421_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	 1602	,8	,1	,&internal1_m421_txNm},	//(internal1_m421_txNm) txNm - счётчик задержки сигнализации недвижения
	 1603	,8	,1	,&internal1_m421_txSm},	//(internal1_m421_txSm) txSm - счётчик задержки сигнализации самохода
	 1604	,18	,1	,&internal1_m427_BlDv0},	//(internal1_m427_BlDv0) - была блокировка
	 1605	,18	,1	,&internal1_m427_DvDw0},	//(internal1_m427_DvDw0) - есть команда на движение назад
	 1606	,18	,1	,&internal1_m427_DvUp0},	//(internal1_m427_DvUp0) - есть команда на движение вперёд
	 1607	,18	,1	,&internal1_m427_FDvDw0},	//(internal1_m427_FDvDw0) - есть команда на движение назад
	 1608	,18	,1	,&internal1_m427_FDvUp0},	//(internal1_m427_FDvUp0) - есть команда на движение вперёд
	 1609	,18	,1	,&internal1_m427_Pkav0},	//(internal1_m427_Pkav0) Pkav - передний конечный аварийный выключатель
	 1610	,18	,1	,&internal1_m427_Pkv0},	//(internal1_m427_Pkv0) Pkv - передний конечный выключатель
	 1611	,18	,1	,&internal1_m427_Zkav0},	//(internal1_m427_Zkav0) Zkav - задний конечный аварийный выключатель
	 1612	,18	,1	,&internal1_m427_Zkv0},	//(internal1_m427_Zkv0) Zkv - задний конечный выключатель
	 1613	,18	,1	,&internal1_m427_fef},	//(internal1_m427_fef) fef
	 1614	,8	,1	,&internal1_m427_txHr},	//(internal1_m427_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	 1615	,8	,1	,&internal1_m427_txLd},	//(internal1_m427_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	 1616	,8	,1	,&internal1_m427_txNm},	//(internal1_m427_txNm) txNm - счётчик задержки сигнализации недвижения
	 1617	,8	,1	,&internal1_m427_txSm},	//(internal1_m427_txSm) txSm - счётчик задержки сигнализации самохода
	 1618	,8	,1	,&internal1_m431_tx},	//(internal1_m431_tx) tx - внутренний параметр
	 1619	,8	,1	,&internal1_m437_tx},	//(internal1_m437_tx) tx - внутренний параметр
	 1620	,8	,1	,&internal1_m438_tx},	//(internal1_m438_tx) tx - внутренний параметр
	 1621	,8	,1	,&internal1_m439_tx},	//(internal1_m439_tx) tx - внутренний параметр
	 1622	,8	,1	,&internal1_m448_tx},	//(internal1_m448_tx) tx - внутренний параметр
	 1623	,8	,1	,&internal1_m449_tx},	//(internal1_m449_tx) tx - внутренний параметр
	 1624	,8	,1	,&internal1_m451_tx},	//(internal1_m451_tx) tx - внутренний параметр
	 1625	,8	,1	,&internal1_m457_tx},	//(internal1_m457_tx) tx - внутренний параметр
	 1626	,8	,1	,&internal1_m465_tx},	//(internal1_m465_tx) tx - внутренний параметр
	 1627	,8	,1	,&internal1_m474_tx},	//(internal1_m474_tx) tx - внутренний параметр
	 1628	,8	,1	,&internal1_m476_tx},	//(internal1_m476_tx) tx - внутренний параметр
	 1629	,8	,1	,&internal1_m478_tx},	//(internal1_m478_tx) tx - внутренний параметр
	 1630	,8	,1	,&internal1_m480_tx},	//(internal1_m480_tx) tx - внутренний параметр
	 1631	,8	,1	,&internal1_m485_tx},	//(internal1_m485_tx) tx - внутренний параметр
	 1632	,8	,1	,&internal1_m500_tx},	//(internal1_m500_tx) tx - внутренний параметр
	 1633	,8	,1	,&internal1_m501_tx},	//(internal1_m501_tx) tx - внутренний параметр
	 1634	,8	,1	,&internal1_m502_tx},	//(internal1_m502_tx) tx - внутренний параметр
	 1635	,8	,1	,&internal1_m503_tx},	//(internal1_m503_tx) tx - внутренний параметр
	 1636	,18	,1	,&internal1_m511_BlDv0},	//(internal1_m511_BlDv0) - была блокировка
	 1637	,18	,1	,&internal1_m511_DvDw0},	//(internal1_m511_DvDw0) - есть команда на движение назад
	 1638	,18	,1	,&internal1_m511_DvUp0},	//(internal1_m511_DvUp0) - есть команда на движение вперёд
	 1639	,18	,1	,&internal1_m511_FDvDw0},	//(internal1_m511_FDvDw0) - есть команда на движение назад
	 1640	,18	,1	,&internal1_m511_FDvUp0},	//(internal1_m511_FDvUp0) - есть команда на движение вперёд
	 1641	,18	,1	,&internal1_m511_Pkav0},	//(internal1_m511_Pkav0) Pkav - передний конечный аварийный выключатель
	 1642	,18	,1	,&internal1_m511_Pkv0},	//(internal1_m511_Pkv0) Pkv - передний конечный выключатель
	 1643	,18	,1	,&internal1_m511_Zkav0},	//(internal1_m511_Zkav0) Zkav - задний конечный аварийный выключатель
	 1644	,18	,1	,&internal1_m511_Zkv0},	//(internal1_m511_Zkv0) Zkv - задний конечный выключатель
	 1645	,18	,1	,&internal1_m511_fef},	//(internal1_m511_fef) fef
	 1646	,8	,1	,&internal1_m511_txHr},	//(internal1_m511_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	 1647	,8	,1	,&internal1_m511_txLd},	//(internal1_m511_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	 1648	,8	,1	,&internal1_m511_txNm},	//(internal1_m511_txNm) txNm - счётчик задержки сигнализации недвижения
	 1649	,8	,1	,&internal1_m511_txSm},	//(internal1_m511_txSm) txSm - счётчик задержки сигнализации самохода
	 1650	,18	,1	,&internal1_m517_BlDv0},	//(internal1_m517_BlDv0) - была блокировка
	 1651	,18	,1	,&internal1_m517_DvDw0},	//(internal1_m517_DvDw0) - есть команда на движение назад
	 1652	,18	,1	,&internal1_m517_DvUp0},	//(internal1_m517_DvUp0) - есть команда на движение вперёд
	 1653	,18	,1	,&internal1_m517_FDvDw0},	//(internal1_m517_FDvDw0) - есть команда на движение назад
	 1654	,18	,1	,&internal1_m517_FDvUp0},	//(internal1_m517_FDvUp0) - есть команда на движение вперёд
	 1655	,18	,1	,&internal1_m517_Pkav0},	//(internal1_m517_Pkav0) Pkav - передний конечный аварийный выключатель
	 1656	,18	,1	,&internal1_m517_Pkv0},	//(internal1_m517_Pkv0) Pkv - передний конечный выключатель
	 1657	,18	,1	,&internal1_m517_Zkav0},	//(internal1_m517_Zkav0) Zkav - задний конечный аварийный выключатель
	 1658	,18	,1	,&internal1_m517_Zkv0},	//(internal1_m517_Zkv0) Zkv - задний конечный выключатель
	 1659	,18	,1	,&internal1_m517_fef},	//(internal1_m517_fef) fef
	 1660	,8	,1	,&internal1_m517_txHr},	//(internal1_m517_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	 1661	,8	,1	,&internal1_m517_txLd},	//(internal1_m517_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	 1662	,8	,1	,&internal1_m517_txNm},	//(internal1_m517_txNm) txNm - счётчик задержки сигнализации недвижения
	 1663	,8	,1	,&internal1_m517_txSm},	//(internal1_m517_txSm) txSm - счётчик задержки сигнализации самохода
	 1664	,8	,1	,&internal1_m525_tx},	//(internal1_m525_tx) tx - внутренний параметр
	 1665	,8	,1	,&internal1_m529_tx},	//(internal1_m529_tx) tx - внутренний параметр
	 1666	,8	,1	,&internal1_m52_tx},	//(internal1_m52_tx) tx - внутренний параметр
	 1667	,8	,1	,&internal1_m530_tx},	//(internal1_m530_tx) tx - внутренний параметр
	 1668	,8	,1	,&internal1_m531_tx},	//(internal1_m531_tx) tx - внутренний параметр
	 1669	,8	,1	,&internal1_m54_tim},	//(internal1_m54_tim) - время задержки выходного сигнала
	 1670	,1	,1	,&internal1_m54_x0},	//(internal1_m54_x0) - значение входного параметра на предыдущем шаге
	 1671	,18	,1	,&internal1_m550_BLDv0},	//(internal1_m550_BLDv0) BlDv - Блокировка движения
	 1672	,8	,1	,&internal1_m550_X0},	//(internal1_m550_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	 1673	,8	,1	,&internal1_m550_t0},	//(internal1_m550_t0) время нахождения в зоне возврата
	 1674	,8	,1	,&internal1_m568_tx},	//(internal1_m568_tx) tx - время накопленное сек
	 1675	,18	,1	,&internal1_m568_y0},	//(internal1_m568_y0) y0
	 1676	,8	,1	,&internal1_m569_tx},	//(internal1_m569_tx) tx - время накопленное сек
	 1677	,18	,1	,&internal1_m569_y0},	//(internal1_m569_y0) y0
	 1678	,8	,1	,&internal1_m573_DelSp},	//(internal1_m573_DelSp) DelSp - время переключения скоростей
	 1679	,1	,1	,&internal1_m573_ShCntlSp0},	//(internal1_m573_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	 1680	,1	,1	,&internal1_m573_Shift0},	//(internal1_m573_Shift0) Shift0 - признак самохода
	 1681	,1	,1	,&internal1_m573_ShiftControl},	//(internal1_m573_ShiftControl) ShiftControl - признак самохода
	 1682	,8	,1	,&internal1_m573_Speed0},	//(internal1_m573_Speed0) Speed0 - предыдущее значение скорости перемещения
	 1683	,8	,1	,&internal1_m573_StSpeed},	//(internal1_m573_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	 1684	,8	,1	,&internal1_m573_Vz0},	//(internal1_m573_Vz0) Vz0 - предыдущая заданная скорость
	 1685	,3	,1	,&internal1_m573_flRazg},	//(internal1_m573_flRazg) признак разгона/торможения
	 1686	,8	,1	,&internal1_m573_sumtim},	//(internal1_m573_sumtim) sumtim - время в пути
	 1687	,8	,150	,&internal1_m573_tim0},	//(internal1_m573_tim0) tim0 - массив значений времени цикла
	 1688	,8	,1	,&internal1_m573_tx},	//(internal1_m573_tx) tx
	 1689	,8	,1	,&internal1_m573_txBl},	//(internal1_m573_txBl) tx
	 1690	,8	,1	,&internal1_m573_txMBl},	//(internal1_m573_txMBl) tx
	 1691	,8	,1	,&internal1_m573_txZS},	//(internal1_m573_txZS) txZS
	 1692	,8	,1	,&internal1_m573_txd},	//(internal1_m573_txd) txd
	 1693	,8	,1	,&internal1_m573_tz0},	//(internal1_m573_tz0) tz0 - время защиты от нового задания сек
	 1694	,8	,150	,&internal1_m573_x0},	//(internal1_m573_x0) x0 - массив мгновенных значений координат
	 1695	,3	,1	,&internal1_m573_xptr},	//(internal1_m573_xptr) указатель текущей позиции в массиве координат
	 1696	,8	,1	,&internal1_m573_xz0},	//(internal1_m573_xz0) xz0 - новое задание мм
	 1697	,8	,1	,&internal1_m573_z0},	//(internal1_m573_z0) z0 - точка прекращения движения
	 1698	,8	,1	,&internal1_m574_tx},	//(internal1_m574_tx) tx - внутренний параметр
	 1699	,8	,1	,&internal1_m575_tx},	//(internal1_m575_tx) tx - внутренний параметр
	 1700	,8	,1	,&internal1_m576_tx},	//(internal1_m576_tx) tx - внутренний параметр
	 1701	,8	,1	,&internal1_m581_tx},	//(internal1_m581_tx) tx - внутренний параметр
	 1702	,8	,1	,&internal1_m588_tx},	//(internal1_m588_tx) tx - время накопленное сек
	 1703	,18	,1	,&internal1_m588_y0},	//(internal1_m588_y0) y0
	 1704	,8	,1	,&internal1_m594_tx},	//(internal1_m594_tx) tx - внутренний параметр
	 1705	,8	,1	,&internal1_m595_tx},	//(internal1_m595_tx) tx - внутренний параметр
	 1706	,8	,1	,&internal1_m597_tx},	//(internal1_m597_tx) tx - внутренний параметр
	 1707	,8	,1	,&internal1_m607_tx},	//(internal1_m607_tx) tx - внутренний параметр
	 1708	,8	,1	,&internal1_m611_tx},	//(internal1_m611_tx) tx - внутренний параметр
	 1709	,8	,1	,&internal1_m612_tx},	//(internal1_m612_tx) tx - внутренний параметр
	 1710	,8	,1	,&internal1_m622_tx},	//(internal1_m622_tx) tx - внутренний параметр
	 1711	,8	,1	,&internal1_m626_tx},	//(internal1_m626_tx) tx - внутренний параметр
	 1712	,8	,1	,&internal1_m628_tx},	//(internal1_m628_tx) tx - внутренний параметр
	 1713	,8	,1	,&internal1_m635_tx},	//(internal1_m635_tx) tx - внутренний параметр
	 1714	,8	,1	,&internal1_m637_tx},	//(internal1_m637_tx) tx - внутренний параметр
	 1715	,8	,1	,&internal1_m638_tx},	//(internal1_m638_tx) tx - внутренний параметр
	 1716	,8	,1	,&internal1_m639_tx},	//(internal1_m639_tx) tx - внутренний параметр
	 1717	,8	,1	,&internal1_m640_tx},	//(internal1_m640_tx) tx - внутренний параметр
	 1718	,1	,1	,&internal1_m667_q0},	//(internal1_m667_q0) q0 - внутренний параметр
	 1719	,1	,1	,&internal1_m677_q0},	//(internal1_m677_q0) q0 - внутренний параметр
	 1720	,1	,1	,&internal1_m687_q0},	//(internal1_m687_q0) q0 - внутренний параметр
	 1721	,1	,1	,&internal1_m689_q0},	//(internal1_m689_q0) q0 - внутренний параметр
	 1722	,1	,1	,&internal1_m691_q0},	//(internal1_m691_q0) q0 - внутренний параметр
	 1723	,1	,1	,&internal1_m692_q0},	//(internal1_m692_q0) q0 - внутренний параметр
	 1724	,1	,1	,&internal1_m694_q0},	//(internal1_m694_q0) q0 - внутренний параметр
	 1725	,1	,1	,&internal1_m696_q0},	//(internal1_m696_q0) q0 - внутренний параметр
	 1726	,1	,1	,&internal1_m697_q0},	//(internal1_m697_q0) q0 - внутренний параметр
	 1727	,1	,1	,&internal1_m699_q0},	//(internal1_m699_q0) q0 - внутренний параметр
	 1728	,1	,1	,&internal1_m702_q0},	//(internal1_m702_q0) q0 - внутренний параметр
	 1729	,1	,1	,&internal1_m707_q0},	//(internal1_m707_q0) q0 - внутренний параметр
	 1730	,1	,1	,&internal1_m711_q0},	//(internal1_m711_q0) q0 - внутренний параметр
	 1731	,1	,1	,&internal1_m712_q0},	//(internal1_m712_q0) q0 - внутренний параметр
	 1732	,1	,1	,&internal1_m720_q0},	//(internal1_m720_q0) q0 - внутренний параметр
	 1733	,1	,1	,&internal1_m724_q0},	//(internal1_m724_q0) q0 - внутренний параметр
	 1734	,8	,1	,&internal1_m735_tx},	//(internal1_m735_tx) tx - внутренний параметр
	 1735	,1	,1	,&internal1_m741_x0},	//(internal1_m741_x0) x0 - значение входного параметра на предыдущем шаге
	 1736	,8	,1	,&internal1_m742_tx},	//(internal1_m742_tx) tx - внутренний параметр
	 1737	,8	,1	,&internal1_m746_tx},	//(internal1_m746_tx) tx - внутренний параметр
	 1738	,8	,1	,&internal1_m750_tx},	//(internal1_m750_tx) tx - внутренний параметр
	 1739	,8	,1	,&internal1_m761_tx},	//(internal1_m761_tx) tx - внутренний параметр
	 1740	,8	,1	,&internal1_m766_tx},	//(internal1_m766_tx) tx - внутренний параметр
	 1741	,8	,1	,&internal1_m767_tx},	//(internal1_m767_tx) tx - внутренний параметр
	 1742	,8	,1	,&internal1_m770_tx},	//(internal1_m770_tx) tx - внутренний параметр
	 1743	,8	,1	,&internal1_m775_tx},	//(internal1_m775_tx) tx - внутренний параметр
	 1744	,8	,1	,&internal1_m777_tx},	//(internal1_m777_tx) tx - внутренний параметр
	 1745	,8	,1	,&internal1_m785_tx},	//(internal1_m785_tx) tx - внутренний параметр
	 1746	,8	,1	,&internal1_m794_tx},	//(internal1_m794_tx) tx - внутренний параметр
	 1747	,8	,1	,&internal1_m795_tx},	//(internal1_m795_tx) tx - внутренний параметр
	 1748	,8	,1	,&internal1_m796_tx},	//(internal1_m796_tx) tx - внутренний параметр
	 1749	,8	,1	,&internal1_m797_tx},	//(internal1_m797_tx) tx - внутренний параметр
	 1750	,1	,1	,&internal1_m799_x0},	//(internal1_m799_x0) x0 - значение входного параметра на предыдущем шаге
	 1751	,1	,1	,&internal1_m79_MyFirstEnterFlag},	//(internal1_m79_MyFirstEnterFlag)  FirstEnterFlag
	 1752	,8	,1	,&internal1_m79_W1},	//(internal1_m79_W1)  мощность на старте измерения
	 1753	,8	,1	,&internal1_m79_W2},	//(internal1_m79_W2)  мощность в конце измерения
	 1754	,8	,1	,&internal1_m79_Wlast},	//(internal1_m79_Wlast)  последнее растущее измерение
	 1755	,8	,1	,&internal1_m79_Wmax},	//(internal1_m79_Wmax)  максимальное измерение в серии
	 1756	,8	,1	,&internal1_m79_Wmin},	//(internal1_m79_Wmin)  минимальное измерение в серии
	 1757	,3	,1	,&internal1_m79_chizm},	//(internal1_m79_chizm)  счетчик уменьшения мощности
	 1758	,3	,1	,&internal1_m79_chsr},	//(internal1_m79_chsr)  счетчик усреднения
	 1759	,3	,1	,&internal1_m79_flst},	//(internal1_m79_flst)  флаг старта измерения
	 1760	,8	,1	,&internal1_m79_sumtim},	//(internal1_m79_sumtim)  время измерения мощности
	 1761	,8	,1	,&internal1_m79_y0},	//(internal1_m79_y0) y0 - внутренний параметр
	 1762	,1	,1	,&internal1_m818_q0},	//(internal1_m818_q0) q0 - внутренний параметр
	 1763	,1	,1	,&internal1_m820_q0},	//(internal1_m820_q0) q0 - внутренний параметр
	 1764	,1	,1	,&internal1_m822_q0},	//(internal1_m822_q0) q0 - внутренний параметр
	 1765	,1	,1	,&internal1_m824_q0},	//(internal1_m824_q0) q0 - внутренний параметр
	 1766	,1	,1	,&internal1_m827_q0},	//(internal1_m827_q0) q0 - внутренний параметр
	 1767	,8	,1	,&internal1_m82_tx},	//(internal1_m82_tx) tx - внутренний параметр
	 1768	,1	,1	,&internal1_m830_x0},	//(internal1_m830_x0) x0 - значение входного параметра на предыдущем шаге
	 1769	,1	,1	,&internal1_m831_q0},	//(internal1_m831_q0) q0 - внутренний параметр
	 1770	,8	,1	,&internal1_m834_tx},	//(internal1_m834_tx) tx - время накопленное сек
	 1771	,18	,1	,&internal1_m834_y0},	//(internal1_m834_y0) y0
	 1772	,8	,1	,&internal1_m835_tx},	//(internal1_m835_tx) tx - внутренний параметр
	 1773	,1	,1	,&internal1_m836_q0},	//(internal1_m836_q0) q0 - внутренний параметр
	 1774	,1	,1	,&internal1_m843_q0},	//(internal1_m843_q0) q0 - внутренний параметр
	 1775	,1	,1	,&internal1_m850_q0},	//(internal1_m850_q0) q0 - внутренний параметр
	 1776	,1	,1	,&internal1_m855_q0},	//(internal1_m855_q0) q0 - внутренний параметр
	 1777	,8	,1	,&internal1_m864_tx},	//(internal1_m864_tx) tx - внутренний параметр
	 1778	,8	,1	,&internal1_m865_tx},	//(internal1_m865_tx) tx - внутренний параметр
	 1779	,8	,1	,&internal1_m866_tx},	//(internal1_m866_tx) tx - внутренний параметр
	 1780	,8	,1	,&internal1_m870_tx},	//(internal1_m870_tx) tx - внутренний параметр
	 1781	,18	,1	,&internal1_m875_BlDv0},	//(internal1_m875_BlDv0) - была блокировка
	 1782	,18	,1	,&internal1_m875_DvDw0},	//(internal1_m875_DvDw0) - есть команда на движение назад
	 1783	,18	,1	,&internal1_m875_DvUp0},	//(internal1_m875_DvUp0) - есть команда на движение вперёд
	 1784	,18	,1	,&internal1_m875_FDvDw0},	//(internal1_m875_FDvDw0) - есть команда на движение назад
	 1785	,18	,1	,&internal1_m875_FDvUp0},	//(internal1_m875_FDvUp0) - есть команда на движение вперёд
	 1786	,18	,1	,&internal1_m875_Pkav0},	//(internal1_m875_Pkav0) Pkav - передний конечный аварийный выключатель
	 1787	,18	,1	,&internal1_m875_Pkv0},	//(internal1_m875_Pkv0) Pkv - передний конечный выключатель
	 1788	,18	,1	,&internal1_m875_Zkav0},	//(internal1_m875_Zkav0) Zkav - задний конечный аварийный выключатель
	 1789	,18	,1	,&internal1_m875_Zkv0},	//(internal1_m875_Zkv0) Zkv - задний конечный выключатель
	 1790	,18	,1	,&internal1_m875_fef},	//(internal1_m875_fef) fef
	 1791	,8	,1	,&internal1_m875_txHr},	//(internal1_m875_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	 1792	,8	,1	,&internal1_m875_txLd},	//(internal1_m875_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	 1793	,8	,1	,&internal1_m875_txNm},	//(internal1_m875_txNm) txNm - счётчик задержки сигнализации недвижения
	 1794	,8	,1	,&internal1_m875_txSm},	//(internal1_m875_txSm) txSm - счётчик задержки сигнализации самохода
	 1795	,18	,1	,&internal1_m879_BlDv0},	//(internal1_m879_BlDv0) - была блокировка
	 1796	,18	,1	,&internal1_m879_DvDw0},	//(internal1_m879_DvDw0) - есть команда на движение назад
	 1797	,18	,1	,&internal1_m879_DvUp0},	//(internal1_m879_DvUp0) - есть команда на движение вперёд
	 1798	,18	,1	,&internal1_m879_FDvDw0},	//(internal1_m879_FDvDw0) - есть команда на движение назад
	 1799	,18	,1	,&internal1_m879_FDvUp0},	//(internal1_m879_FDvUp0) - есть команда на движение вперёд
	 1800	,18	,1	,&internal1_m879_Pkav0},	//(internal1_m879_Pkav0) Pkav - передний конечный аварийный выключатель
	 1801	,18	,1	,&internal1_m879_Pkv0},	//(internal1_m879_Pkv0) Pkv - передний конечный выключатель
	 1802	,18	,1	,&internal1_m879_Zkav0},	//(internal1_m879_Zkav0) Zkav - задний конечный аварийный выключатель
	 1803	,18	,1	,&internal1_m879_Zkv0},	//(internal1_m879_Zkv0) Zkv - задний конечный выключатель
	 1804	,18	,1	,&internal1_m879_fef},	//(internal1_m879_fef) fef
	 1805	,8	,1	,&internal1_m879_txHr},	//(internal1_m879_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	 1806	,8	,1	,&internal1_m879_txLd},	//(internal1_m879_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	 1807	,8	,1	,&internal1_m879_txNm},	//(internal1_m879_txNm) txNm - счётчик задержки сигнализации недвижения
	 1808	,8	,1	,&internal1_m879_txSm},	//(internal1_m879_txSm) txSm - счётчик задержки сигнализации самохода
	 1809	,8	,1	,&internal1_m887_tx},	//(internal1_m887_tx) tx - внутренний параметр
	 1810	,8	,1	,&internal1_m891_tx},	//(internal1_m891_tx) tx - внутренний параметр
	 1811	,8	,1	,&internal1_m892_tx},	//(internal1_m892_tx) tx - внутренний параметр
	 1812	,8	,1	,&internal1_m893_tx},	//(internal1_m893_tx) tx - внутренний параметр
	 1813	,18	,1	,&internal1_m909_BLDv0},	//(internal1_m909_BLDv0) BlDv - Блокировка движения
	 1814	,8	,1	,&internal1_m909_X0},	//(internal1_m909_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	 1815	,8	,1	,&internal1_m909_t0},	//(internal1_m909_t0) время нахождения в зоне возврата
	 1816	,8	,1	,&internal1_m921_tx},	//(internal1_m921_tx) tx - время накопленное сек
	 1817	,18	,1	,&internal1_m921_y0},	//(internal1_m921_y0) y0
	 1818	,8	,1	,&internal1_m922_tx},	//(internal1_m922_tx) tx - время накопленное сек
	 1819	,18	,1	,&internal1_m922_y0},	//(internal1_m922_y0) y0
	 1820	,8	,1	,&internal1_m924_tx},	//(internal1_m924_tx) tx - внутренний параметр
	 1821	,8	,1	,&internal1_m925_tx},	//(internal1_m925_tx) tx - внутренний параметр
	 1822	,8	,1	,&internal1_m927_DelSp},	//(internal1_m927_DelSp) DelSp - время переключения скоростей
	 1823	,1	,1	,&internal1_m927_ShCntlSp0},	//(internal1_m927_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	 1824	,1	,1	,&internal1_m927_Shift0},	//(internal1_m927_Shift0) Shift0 - признак самохода
	 1825	,1	,1	,&internal1_m927_ShiftControl},	//(internal1_m927_ShiftControl) ShiftControl - признак самохода
	 1826	,8	,1	,&internal1_m927_Speed0},	//(internal1_m927_Speed0) Speed0 - предыдущее значение скорости перемещения
	 1827	,8	,1	,&internal1_m927_StSpeed},	//(internal1_m927_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	 1828	,8	,1	,&internal1_m927_Vz0},	//(internal1_m927_Vz0) Vz0 - предыдущая заданная скорость
	 1829	,3	,1	,&internal1_m927_flRazg},	//(internal1_m927_flRazg) признак разгона/торможения
	 1830	,8	,1	,&internal1_m927_sumtim},	//(internal1_m927_sumtim) sumtim - время в пути
	 1831	,8	,80	,&internal1_m927_tim0},	//(internal1_m927_tim0) tim0 - массив значений времени цикла
	 1832	,8	,1	,&internal1_m927_tx},	//(internal1_m927_tx) tx
	 1833	,8	,1	,&internal1_m927_txBl},	//(internal1_m927_txBl) tx
	 1834	,8	,1	,&internal1_m927_txMBl},	//(internal1_m927_txMBl) tx
	 1835	,8	,1	,&internal1_m927_txZS},	//(internal1_m927_txZS) txZS
	 1836	,8	,1	,&internal1_m927_txd},	//(internal1_m927_txd) txd
	 1837	,8	,1	,&internal1_m927_tz0},	//(internal1_m927_tz0) tz0 - время защиты от нового задания сек
	 1838	,8	,80	,&internal1_m927_x0},	//(internal1_m927_x0) x0 - массив мгновенных значений координат
	 1839	,3	,1	,&internal1_m927_xptr},	//(internal1_m927_xptr) указатель текущей позиции в массиве координат
	 1840	,8	,1	,&internal1_m927_xz0},	//(internal1_m927_xz0) xz0 - новое задание мм
	 1841	,8	,1	,&internal1_m927_z0},	//(internal1_m927_z0) z0 - точка прекращения движения
	 1842	,8	,1	,&internal1_m929_tx},	//(internal1_m929_tx) tx - внутренний параметр
	 1843	,8	,1	,&internal1_m934_tx},	//(internal1_m934_tx) tx - внутренний параметр
	 1844	,8	,1	,&internal1_m939_tx},	//(internal1_m939_tx) tx - время накопленное сек
	 1845	,18	,1	,&internal1_m939_y0},	//(internal1_m939_y0) y0
	 1846	,8	,1	,&internal1_m949_tx},	//(internal1_m949_tx) tx - внутренний параметр
	 1847	,8	,1	,&internal1_m950_tx},	//(internal1_m950_tx) tx - внутренний параметр
	 1848	,8	,1	,&internal1_m952_tx},	//(internal1_m952_tx) tx - внутренний параметр
	 1849	,8	,1	,&internal1_m963_tx},	//(internal1_m963_tx) tx - внутренний параметр
	 1850	,8	,1	,&internal1_m967_tx},	//(internal1_m967_tx) tx - внутренний параметр
	 1851	,8	,1	,&internal1_m969_tx},	//(internal1_m969_tx) tx - внутренний параметр
	 1852	,8	,1	,&internal1_m977_tx},	//(internal1_m977_tx) tx - внутренний параметр
	 1853	,8	,1	,&internal1_m979_tx},	//(internal1_m979_tx) tx - внутренний параметр
	 1854	,8	,1	,&internal1_m984_tx},	//(internal1_m984_tx) tx - внутренний параметр
	 1855	,8	,1	,&internal1_m985_tx},	//(internal1_m985_tx) tx - внутренний параметр
	 1856	,8	,1	,&internal1_m986_tx},	//(internal1_m986_tx) tx - внутренний параметр
	 1857	,8	,1	,&internal1_m989_tx},	//(internal1_m989_tx) tx - внутренний параметр
	 1858	,5	,1	,&internal2_m106_Nk0},	//(internal2_m106_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	 1859	,1	,1	,&internal2_m106_SetFlag},	//(internal2_m106_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	 1860	,5	,1	,&internal2_m110_Nk0},	//(internal2_m110_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	 1861	,1	,1	,&internal2_m110_SetFlag},	//(internal2_m110_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	 1862	,8	,1	,&internal2_m127_tx},	//(internal2_m127_tx) tx - время накопленное сек
	 1863	,18	,1	,&internal2_m127_y0},	//(internal2_m127_y0) y0
	 1864	,8	,1	,&internal2_m131_tx},	//(internal2_m131_tx) tx - время накопленное сек
	 1865	,18	,1	,&internal2_m131_y0},	//(internal2_m131_y0) y0
	 1866	,8	,1	,&internal2_m137_tx},	//(internal2_m137_tx) tx - время накопленное сек
	 1867	,18	,1	,&internal2_m137_y0},	//(internal2_m137_y0) y0
	 1868	,8	,1	,&internal2_m141_tx},	//(internal2_m141_tx) tx - время накопленное сек
	 1869	,18	,1	,&internal2_m141_y0},	//(internal2_m141_y0) y0
	 1870	,8	,1	,&internal2_m144_tx},	//(internal2_m144_tx) tx - время накопленное сек
	 1871	,18	,1	,&internal2_m144_y0},	//(internal2_m144_y0) y0
	 1872	,8	,1	,&internal2_m149_tx},	//(internal2_m149_tx) tx - время накопленное сек
	 1873	,18	,1	,&internal2_m149_y0},	//(internal2_m149_y0) y0
	 1874	,8	,1	,&internal2_m155_tx},	//(internal2_m155_tx) tx - время накопленное сек
	 1875	,18	,1	,&internal2_m155_y0},	//(internal2_m155_y0) y0
	 1876	,8	,1	,&internal2_m157_tx},	//(internal2_m157_tx) tx - время накопленное сек
	 1877	,18	,1	,&internal2_m157_y0},	//(internal2_m157_y0) y0
	 1878	,8	,1	,&internal2_m165_tx},	//(internal2_m165_tx) tx - время накопленное сек
	 1879	,18	,1	,&internal2_m165_y0},	//(internal2_m165_y0) y0
	 1880	,5	,1	,&internal2_m16_Nk0},	//(internal2_m16_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	 1881	,1	,1	,&internal2_m16_SetFlag},	//(internal2_m16_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	 1882	,8	,1	,&internal2_m172_tx},	//(internal2_m172_tx) tx - время накопленное сек
	 1883	,18	,1	,&internal2_m172_y0},	//(internal2_m172_y0) y0
	 1884	,8	,1	,&internal2_m176_tx},	//(internal2_m176_tx) tx - время накопленное сек
	 1885	,18	,1	,&internal2_m176_y0},	//(internal2_m176_y0) y0
	 1886	,8	,1	,&internal2_m182_tx},	//(internal2_m182_tx) tx - время накопленное сек
	 1887	,18	,1	,&internal2_m182_y0},	//(internal2_m182_y0) y0
	 1888	,8	,1	,&internal2_m193_y0},	//(internal2_m193_y0) y0
	 1889	,8	,1	,&internal2_m195_y0},	//(internal2_m195_y0) y0
	 1890	,1	,1	,&internal2_m198_y1},	//(internal2_m198_y1) y1 - внутренний параметр
	 1891	,1	,1	,&internal2_m205_y1},	//(internal2_m205_y1) y1 - внутренний параметр
	 1892	,1	,1	,&internal2_m208_y1},	//(internal2_m208_y1) y1 - внутренний параметр
	 1893	,1	,1	,&internal2_m216_y1},	//(internal2_m216_y1) y1 - внутренний параметр
	 1894	,5	,1	,&internal2_m21_Nk0},	//(internal2_m21_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	 1895	,1	,1	,&internal2_m21_SetFlag},	//(internal2_m21_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	 1896	,1	,1	,&internal2_m220_y0},	//(internal2_m220_y0) state
	 1897	,1	,1	,&internal2_m226_y0},	//(internal2_m226_y0) state
	 1898	,8	,1	,&internal2_m238_tx},	//(internal2_m238_tx) tx - время накопленное сек
	 1899	,18	,1	,&internal2_m238_y0},	//(internal2_m238_y0) y0
	 1900	,8	,1	,&internal2_m240_tx},	//(internal2_m240_tx) tx - время накопленное сек
	 1901	,18	,1	,&internal2_m240_y0},	//(internal2_m240_y0) y0
	 1902	,8	,1	,&internal2_m242_tx},	//(internal2_m242_tx) tx - время накопленное сек
	 1903	,18	,1	,&internal2_m242_y0},	//(internal2_m242_y0) y0
	 1904	,8	,1	,&internal2_m244_tx},	//(internal2_m244_tx) tx - время накопленное сек
	 1905	,18	,1	,&internal2_m244_y0},	//(internal2_m244_y0) y0
	 1906	,8	,1	,&internal2_m246_tx},	//(internal2_m246_tx) tx - время накопленное сек
	 1907	,18	,1	,&internal2_m246_y0},	//(internal2_m246_y0) y0
	 1908	,8	,1	,&internal2_m248_tx},	//(internal2_m248_tx) tx - время накопленное сек
	 1909	,18	,1	,&internal2_m248_y0},	//(internal2_m248_y0) y0
	 1910	,8	,1	,&internal2_m250_tx},	//(internal2_m250_tx) tx - время накопленное сек
	 1911	,18	,1	,&internal2_m250_y0},	//(internal2_m250_y0) y0
	 1912	,8	,1	,&internal2_m252_tx},	//(internal2_m252_tx) tx - время накопленное сек
	 1913	,18	,1	,&internal2_m252_y0},	//(internal2_m252_y0) y0
	 1914	,8	,1	,&internal2_m254_tx},	//(internal2_m254_tx) tx - время накопленное сек
	 1915	,18	,1	,&internal2_m254_y0},	//(internal2_m254_y0) y0
	 1916	,8	,1	,&internal2_m256_tx},	//(internal2_m256_tx) tx - время накопленное сек
	 1917	,18	,1	,&internal2_m256_y0},	//(internal2_m256_y0) y0
	 1918	,8	,1	,&internal2_m258_tx},	//(internal2_m258_tx) tx - время накопленное сек
	 1919	,18	,1	,&internal2_m258_y0},	//(internal2_m258_y0) y0
	 1920	,8	,1	,&internal2_m260_tx},	//(internal2_m260_tx) tx - время накопленное сек
	 1921	,18	,1	,&internal2_m260_y0},	//(internal2_m260_y0) y0
	 1922	,5	,1	,&internal2_m45_Nk0},	//(internal2_m45_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	 1923	,1	,1	,&internal2_m45_SetFlag},	//(internal2_m45_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	 1924	,5	,1	,&internal2_m53_Nk0},	//(internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	 1925	,1	,1	,&internal2_m53_SetFlag},	//(internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	 1926	,5	,1	,&internal2_m75_Nk0},	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	 1927	,1	,1	,&internal2_m75_SetFlag},	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	 1928	,5	,1	,&internal2_m77_Nk0},	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	 1929	,1	,1	,&internal2_m77_SetFlag},	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	 1930	,1	,1	,&lEM_R0MD01LC1},	//(R0MD01LC1) Ручное управление ОРР
	 1931	,1	,1	,&psaz11},	//( - , DU) каналы
	 1932	,1	,1	,&psaz12},	//( - , DU) напряжение
	 1933	,1	,1	,&psaz13},	//( - , DU) давление
	 1934	,1	,1	,&psaz14},	//( - , DU) ас темп з2
	 1935	,1	,1	,&psaz15},	//( - , DU) ас темп з1
	 1936	,1	,1	,&psaz21},	//( - , DU) каналы
	 1937	,1	,1	,&psaz22},	//( - , DU) напряжение
	 1938	,1	,1	,&psaz23},	//( - , DU) давление
	 1939	,1	,1	,&psaz24},	//( - , DU) ас темп з2
	 1940	,1	,1	,&psaz25},	//( - , DU) питание
	 1941	,1	,1	,&psaz3},	//( - , DU) энкодеры
	 1942	,1	,1	,&psb1},	//( - , DU) ру не готова
	 1943	,1	,1	,&psb2},	//( - , DU) движение бб
	 1944	,1	,1	,&psrb},	//( - , DU) ???
	 1945	,1	,1	,&psrb1},	//( - , DU) пневматика по мощности
	 1946	,1	,1	,&psrb2},	//( - , DU) пневматика по программам
	 1947	,1	,1	,&psrb4},	//( - , DU) кнопка сброс
	 1948	,5	,1	,&venc01},	//(vencf8l:01 - venc01, - ) заначение реального энкодера ББ1
	 1949	,5	,1	,&venc02},	//(vencf8l:01 - venc02, - ) заначение реального энкодера РБ1
	 1950	,5	,1	,&venc03},	//(vencf8l:01 - venc03, - ) заначение реального энкодера Ис1
	 1951	,5	,1	,&venc04},	//(vencf8l:01 - venc04, - ) заначение реального энкодера ДС1
	 1952	,5	,1	,&venc05},	//(vencf8l:01 - venc05, - ) заначение реального энкодера ББ2
	 1953	,5	,1	,&venc06},	//(vencf8l:01 - venc06, - ) заначение реального энкодера РБ2
	 1954	,5	,1	,&venc07},	//(vencf8l:01 - venc07, - ) заначение реального энкодера ИС2
	 1955	,5	,1	,&venc08},	//(vencf8l:01 - venc08, - ) заначение реального энкодера АЗ2
	 30000	,1	,1	,&var1489},	//Внутренняя переменная var1489
	 30001	,1	,1	,&var1672},	//Внутренняя переменная var1672
	 30002	,1	,1	,&var150},	//Внутренняя переменная var150
	 30003	,1	,1	,&var801},	//Внутренняя переменная var801
	 30004	,1	,1	,&var972},	//Внутренняя переменная var972
	 30005	,1	,1	,&var1084},	//Внутренняя переменная var1084
	 30006	,1	,1	,&var1362},	//Внутренняя переменная var1362
	 30007	,1	,1	,&var1440},	//Внутренняя переменная var1440
	 30008	,1	,1	,&var784},	//Внутренняя переменная var784
	 30009	,1	,1	,&var185},	//Внутренняя переменная var185
	 30010	,1	,1	,&var276},	//Внутренняя переменная var276
	 30011	,1	,1	,&var440},	//Внутренняя переменная var440
	 30012	,1	,1	,&var530},	//Внутренняя переменная var530
	 30013	,1	,1	,&var1604},	//Внутренняя переменная var1604
	 30014	,1	,1	,&var516},	//Внутренняя переменная var516
	 30015	,1	,1	,&var1305},	//Внутренняя переменная var1305
	 30016	,1	,1	,&var1425},	//Внутренняя переменная var1425
	 30017	,1	,1	,&var1426},	//Внутренняя переменная var1426
	 30018	,1	,1	,&var101},	//Внутренняя переменная var101
	 30019	,1	,1	,&var233},	//Внутренняя переменная var233
	 30020	,1	,1	,&var783},	//Внутренняя переменная var783
	 30021	,1	,1	,&var882},	//Внутренняя переменная var882
	 30022	,1	,1	,&var1914},	//Внутренняя переменная var1914
	 30023	,1	,1	,&var403},	//Внутренняя переменная var403
	 30024	,1	,1	,&var456},	//Внутренняя переменная var456
	 30025	,8	,1	,&var668},	//Внутренняя переменная var668
	 30026	,1	,1	,&var1683},	//Внутренняя переменная var1683
	 30027	,1	,1	,&var302},	//Внутренняя переменная var302
	 30028	,1	,1	,&var523},	//Внутренняя переменная var523
	 30029	,1	,1	,&var586},	//Внутренняя переменная var586
	 30030	,1	,1	,&var1818},	//Внутренняя переменная var1818
	 30031	,1	,1	,&var477},	//Внутренняя переменная var477
	 30032	,1	,1	,&var690},	//Внутренняя переменная var690
	 30033	,1	,1	,&var1066},	//Внутренняя переменная var1066
	 30034	,1	,1	,&var1438},	//Внутренняя переменная var1438
	 30035	,1	,1	,&var1184},	//Внутренняя переменная var1184
	 30036	,1	,1	,&var777},	//Внутренняя переменная var777
	 30037	,1	,1	,&var1826},	//Внутренняя переменная var1826
	 30038	,1	,1	,&var104},	//Внутренняя переменная var104
	 30039	,1	,1	,&var479},	//Внутренняя переменная var479
	 30040	,1	,1	,&var791},	//Внутренняя переменная var791
	 30041	,1	,1	,&var1308},	//Внутренняя переменная var1308
	 30042	,1	,1	,&var1337},	//Внутренняя переменная var1337
	 30043	,1	,1	,&var1866},	//Внутренняя переменная var1866
	 30044	,1	,1	,&var683},	//Внутренняя переменная var683
	 30045	,1	,1	,&var706},	//Внутренняя переменная var706
	 30046	,1	,1	,&var1523},	//Внутренняя переменная var1523
	 30047	,1	,1	,&var1721},	//Внутренняя переменная var1721
	 30048	,1	,1	,&var1445},	//Внутренняя переменная var1445
	 30049	,1	,1	,&var1793},	//Внутренняя переменная var1793
	 30050	,1	,1	,&var79},	//Внутренняя переменная var79
	 30051	,1	,1	,&var284},	//Внутренняя переменная var284
	 30052	,8	,1	,&var665},	//Внутренняя переменная var665
	 30053	,1	,1	,&var873},	//Внутренняя переменная var873
	 30054	,1	,1	,&var916},	//Внутренняя переменная var916
	 30055	,1	,1	,&var1120},	//Внутренняя переменная var1120
	 30056	,1	,1	,&var427},	//Внутренняя переменная var427
	 30057	,1	,1	,&var799},	//Внутренняя переменная var799
	 30058	,1	,1	,&var1009},	//Внутренняя переменная var1009
	 30059	,1	,1	,&var1346},	//Внутренняя переменная var1346
	 30060	,1	,1	,&var1418},	//Внутренняя переменная var1418
	 30061	,1	,1	,&var1768},	//Внутренняя переменная var1768
	 30062	,1	,1	,&var538},	//Внутренняя переменная var538
	 30063	,1	,1	,&var1010},	//Внутренняя переменная var1010
	 30064	,1	,1	,&var22},	//Внутренняя переменная var22
	 30065	,1	,1	,&var172},	//Внутренняя переменная var172
	 30066	,1	,1	,&var326},	//Внутренняя переменная var326
	 30067	,1	,1	,&var940},	//Внутренняя переменная var940
	 30068	,1	,1	,&var1461},	//Внутренняя переменная var1461
	 30069	,1	,1	,&var1575},	//Внутренняя переменная var1575
	 30070	,1	,1	,&var164},	//Внутренняя переменная var164
	 30071	,1	,1	,&var315},	//Внутренняя переменная var315
	 30072	,1	,1	,&var1682},	//Внутренняя переменная var1682
	 30073	,1	,1	,&var382},	//Внутренняя переменная var382
	 30074	,1	,1	,&var608},	//Внутренняя переменная var608
	 30075	,1	,1	,&var680},	//Внутренняя переменная var680
	 30076	,1	,1	,&var1285},	//Внутренняя переменная var1285
	 30077	,1	,1	,&var1803},	//Внутренняя переменная var1803
	 30078	,1	,1	,&var1829},	//Внутренняя переменная var1829
	 30079	,1	,1	,&var745},	//Внутренняя переменная var745
	 30080	,1	,1	,&var750},	//Внутренняя переменная var750
	 30081	,1	,1	,&var1495},	//Внутренняя переменная var1495
	 30082	,1	,1	,&var1734},	//Внутренняя переменная var1734
	 30083	,1	,1	,&var1104},	//Внутренняя переменная var1104
	 30084	,1	,1	,&var1524},	//Внутренняя переменная var1524
	 30085	,1	,1	,&var1821},	//Внутренняя переменная var1821
	 30086	,1	,1	,&var1995},	//Внутренняя переменная var1995
	 30087	,1	,1	,&var1275},	//Внутренняя переменная var1275
	 30088	,1	,1	,&var1477},	//Внутренняя переменная var1477
	 30089	,1	,1	,&var1757},	//Внутренняя переменная var1757
	 30090	,1	,1	,&var1993},	//Внутренняя переменная var1993
	 30091	,1	,1	,&var285},	//Внутренняя переменная var285
	 30092	,1	,1	,&var1014},	//Внутренняя переменная var1014
	 30093	,1	,1	,&var1353},	//Внутренняя переменная var1353
	 30094	,1	,1	,&var19},	//Внутренняя переменная var19
	 30095	,1	,1	,&var316},	//Внутренняя переменная var316
	 30096	,1	,1	,&var874},	//Внутренняя переменная var874
	 30097	,1	,1	,&var1381},	//Внутренняя переменная var1381
	 30098	,1	,1	,&var167},	//Внутренняя переменная var167
	 30099	,1	,1	,&var422},	//Внутренняя переменная var422
	 30100	,1	,1	,&var953},	//Внутренняя переменная var953
	 30101	,1	,1	,&var1437},	//Внутренняя переменная var1437
	 30102	,1	,1	,&var1502},	//Внутренняя переменная var1502
	 30103	,1	,1	,&var1863},	//Внутренняя переменная var1863
	 30104	,1	,1	,&var911},	//Внутренняя переменная var911
	 30105	,1	,1	,&var918},	//Внутренняя переменная var918
	 30106	,8	,1	,&var1612},	//Внутренняя переменная var1612
	 30107	,1	,1	,&var1558},	//Внутренняя переменная var1558
	 30108	,1	,1	,&var1748},	//Внутренняя переменная var1748
	 30109	,1	,1	,&var239},	//Внутренняя переменная var239
	 30110	,8	,1	,&var447},	//Внутренняя переменная var447
	 30111	,1	,1	,&var891},	//Внутренняя переменная var891
	 30112	,1	,1	,&var904},	//Внутренняя переменная var904
	 30113	,1	,1	,&var942},	//Внутренняя переменная var942
	 30114	,1	,1	,&var1333},	//Внутренняя переменная var1333
	 30115	,1	,1	,&var1814},	//Внутренняя переменная var1814
	 30116	,1	,1	,&var1867},	//Внутренняя переменная var1867
	 30117	,1	,1	,&var932},	//Внутренняя переменная var932
	 30118	,1	,1	,&var1214},	//Внутренняя переменная var1214
	 30119	,1	,1	,&var1212},	//Внутренняя переменная var1212
	 30120	,8	,1	,&var1227},	//Внутренняя переменная var1227
	 30121	,1	,1	,&var1754},	//Внутренняя переменная var1754
	 30122	,1	,1	,&var1030},	//Внутренняя переменная var1030
	 30123	,1	,1	,&var1931},	//Внутренняя переменная var1931
	 30124	,8	,1	,&var442},	//Внутренняя переменная var442
	 30125	,1	,1	,&var1315},	//Внутренняя переменная var1315
	 30126	,1	,1	,&var1953},	//Внутренняя переменная var1953
	 30127	,1	,1	,&var240},	//Внутренняя переменная var240
	 30128	,1	,1	,&var298},	//Внутренняя переменная var298
	 30129	,1	,1	,&var578},	//Внутренняя переменная var578
	 30130	,1	,1	,&var805},	//Внутренняя переменная var805
	 30131	,1	,1	,&var910},	//Внутренняя переменная var910
	 30132	,1	,1	,&var1431},	//Внутренняя переменная var1431
	 30133	,1	,1	,&var158},	//Внутренняя переменная var158
	 30134	,1	,1	,&var389},	//Внутренняя переменная var389
	 30135	,1	,1	,&var1005},	//Внутренняя переменная var1005
	 30136	,1	,1	,&var1647},	//Внутренняя переменная var1647
	 30137	,1	,1	,&var1902},	//Внутренняя переменная var1902
	 30138	,1	,1	,&var90},	//Внутренняя переменная var90
	 30139	,1	,1	,&var412},	//Внутренняя переменная var412
	 30140	,1	,1	,&var532},	//Внутренняя переменная var532
	 30141	,1	,1	,&var906},	//Внутренняя переменная var906
	 30142	,1	,1	,&var1240},	//Внутренняя переменная var1240
	 30143	,1	,1	,&var1408},	//Внутренняя переменная var1408
	 30144	,1	,1	,&var208},	//Внутренняя переменная var208
	 30145	,1	,1	,&var243},	//Внутренняя переменная var243
	 30146	,1	,1	,&var962},	//Внутренняя переменная var962
	 30147	,1	,1	,&var1251},	//Внутренняя переменная var1251
	 30148	,1	,1	,&var1015},	//Внутренняя переменная var1015
	 30149	,1	,1	,&var1073},	//Внутренняя переменная var1073
	 30150	,1	,1	,&var17},	//Внутренняя переменная var17
	 30151	,1	,1	,&var108},	//Внутренняя переменная var108
	 30152	,1	,1	,&var155},	//Внутренняя переменная var155
	 30153	,1	,1	,&var481},	//Внутренняя переменная var481
	 30154	,1	,1	,&var636},	//Внутренняя переменная var636
	 30155	,1	,1	,&var903},	//Внутренняя переменная var903
	 30156	,1	,1	,&var1127},	//Внутренняя переменная var1127
	 30157	,1	,1	,&var1792},	//Внутренняя переменная var1792
	 30158	,1	,1	,&var20},	//Внутренняя переменная var20
	 30159	,1	,1	,&var1533},	//Внутренняя переменная var1533
	 30160	,1	,1	,&var1861},	//Внутренняя переменная var1861
	 30161	,1	,1	,&var1942},	//Внутренняя переменная var1942
	 30162	,1	,1	,&var366},	//Внутренняя переменная var366
	 30163	,1	,1	,&var499},	//Внутренняя переменная var499
	 30164	,1	,1	,&var1142},	//Внутренняя переменная var1142
	 30165	,1	,1	,&var1351},	//Внутренняя переменная var1351
	 30166	,1	,1	,&var1473},	//Внутренняя переменная var1473
	 30167	,1	,1	,&var1761},	//Внутренняя переменная var1761
	 30168	,1	,1	,&var189},	//Внутренняя переменная var189
	 30169	,1	,1	,&var369},	//Внутренняя переменная var369
	 30170	,1	,1	,&var395},	//Внутренняя переменная var395
	 30171	,1	,1	,&var1175},	//Внутренняя переменная var1175
	 30172	,1	,1	,&var1335},	//Внутренняя переменная var1335
	 30173	,1	,1	,&var1478},	//Внутренняя переменная var1478
	 30174	,1	,1	,&var42},	//Внутренняя переменная var42
	 30175	,1	,1	,&var1032},	//Внутренняя переменная var1032
	 30176	,1	,1	,&var1316},	//Внутренняя переменная var1316
	 30177	,1	,1	,&var1404},	//Внутренняя переменная var1404
	 30178	,	,1	,&var1578},	//Внутренняя переменная var1578
	 30179	,1	,1	,&var1871},	//Внутренняя переменная var1871
	 30180	,1	,1	,&var457},	//Внутренняя переменная var457
	 30181	,1	,1	,&var521},	//Внутренняя переменная var521
	 30182	,1	,1	,&var795},	//Внутренняя переменная var795
	 30183	,1	,1	,&var1322},	//Внутренняя переменная var1322
	 30184	,1	,1	,&var1462},	//Внутренняя переменная var1462
	 30185	,1	,1	,&var1624},	//Внутренняя переменная var1624
	 30186	,1	,1	,&var53},	//Внутренняя переменная var53
	 30187	,1	,1	,&var74},	//Внутренняя переменная var74
	 30188	,1	,1	,&var429},	//Внутренняя переменная var429
	 30189	,1	,1	,&var671},	//Внутренняя переменная var671
	 30190	,1	,1	,&var1745},	//Внутренняя переменная var1745
	 30191	,1	,1	,&var173},	//Внутренняя переменная var173
	 30192	,1	,1	,&var670},	//Внутренняя переменная var670
	 30193	,1	,1	,&var335},	//Внутренняя переменная var335
	 30194	,1	,1	,&var1020},	//Внутренняя переменная var1020
	 30195	,3	,1	,&var1819},	//Внутренняя переменная var1819
	 30196	,	,1	,&vainSChar},	//Внутренняя переменная vainSChar
	 30197	,1	,1	,&var493},	//Внутренняя переменная var493
	 30198	,1	,1	,&var604},	//Внутренняя переменная var604
	 30199	,1	,1	,&var787},	//Внутренняя переменная var787
	 30200	,1	,1	,&var1103},	//Внутренняя переменная var1103
	 30201	,1	,1	,&var1364},	//Внутренняя переменная var1364
	 30202	,1	,1	,&var1797},	//Внутренняя переменная var1797
	 30203	,1	,1	,&var258},	//Внутренняя переменная var258
	 30204	,1	,1	,&var1237},	//Внутренняя переменная var1237
	 30205	,1	,1	,&var1737},	//Внутренняя переменная var1737
	 30206	,1	,1	,&var1056},	//Внутренняя переменная var1056
	 30207	,1	,1	,&var1320},	//Внутренняя переменная var1320
	 30208	,1	,1	,&var1424},	//Внутренняя переменная var1424
	 30209	,1	,1	,&var1905},	//Внутренняя переменная var1905
	 30210	,1	,1	,&var64},	//Внутренняя переменная var64
	 30211	,1	,1	,&var631},	//Внутренняя переменная var631
	 30212	,1	,1	,&var975},	//Внутренняя переменная var975
	 30213	,1	,1	,&var1466},	//Внутренняя переменная var1466
	 30214	,1	,1	,&var5},	//Внутренняя переменная var5
	 30215	,1	,1	,&var77},	//Внутренняя переменная var77
	 30216	,1	,1	,&var187},	//Внутренняя переменная var187
	 30217	,1	,1	,&var544},	//Внутренняя переменная var544
	 30218	,1	,1	,&var1236},	//Внутренняя переменная var1236
	 30219	,1	,1	,&var1274},	//Внутренняя переменная var1274
	 30220	,1	,1	,&var1681},	//Внутренняя переменная var1681
	 30221	,1	,1	,&var95},	//Внутренняя переменная var95
	 30222	,1	,1	,&var727},	//Внутренняя переменная var727
	 30223	,1	,1	,&var1556},	//Внутренняя переменная var1556
	 30224	,1	,1	,&var1726},	//Внутренняя переменная var1726
	 30225	,8	,1	,&var443},	//Внутренняя переменная var443
	 30226	,1	,1	,&var531},	//Внутренняя переменная var531
	 30227	,1	,1	,&var1747},	//Внутренняя переменная var1747
	 30228	,3	,1	,&var1810},	//Внутренняя переменная var1810
	 30229	,1	,1	,&var700},	//Внутренняя переменная var700
	 30230	,1	,1	,&var1017},	//Внутренняя переменная var1017
	 30231	,1	,1	,&var1862},	//Внутренняя переменная var1862
	 30232	,1	,1	,&var38},	//Внутренняя переменная var38
	 30233	,1	,1	,&var207},	//Внутренняя переменная var207
	 30234	,1	,1	,&var358},	//Внутренняя переменная var358
	 30235	,8	,1	,&var432},	//Внутренняя переменная var432
	 30236	,1	,1	,&var601},	//Внутренняя переменная var601
	 30237	,1	,1	,&var1255},	//Внутренняя переменная var1255
	 30238	,1	,1	,&var118},	//Внутренняя переменная var118
	 30239	,1	,1	,&var741},	//Внутренняя переменная var741
	 30240	,1	,1	,&var881},	//Внутренняя переменная var881
	 30241	,1	,1	,&var1926},	//Внутренняя переменная var1926
	 30242	,1	,1	,&var1615},	//Внутренняя переменная var1615
	 30243	,1	,1	,&var1904},	//Внутренняя переменная var1904
	 30244	,1	,1	,&var132},	//Внутренняя переменная var132
	 30245	,1	,1	,&var430},	//Внутренняя переменная var430
	 30246	,1	,1	,&var615},	//Внутренняя переменная var615
	 30247	,1	,1	,&var754},	//Внутренняя переменная var754
	 30248	,1	,1	,&var1326},	//Внутренняя переменная var1326
	 30249	,1	,1	,&var1499},	//Внутренняя переменная var1499
	 30250	,1	,1	,&var1889},	//Внутренняя переменная var1889
	 30251	,1	,1	,&var598},	//Внутренняя переменная var598
	 30252	,1	,1	,&var625},	//Внутренняя переменная var625
	 30253	,1	,1	,&var682},	//Внутренняя переменная var682
	 30254	,1	,1	,&var1123},	//Внутренняя переменная var1123
	 30255	,1	,1	,&var1173},	//Внутренняя переменная var1173
	 30256	,1	,1	,&var1769},	//Внутренняя переменная var1769
	 30257	,1	,1	,&var1149},	//Внутренняя переменная var1149
	 30258	,1	,1	,&var1267},	//Внутренняя переменная var1267
	 30259	,1	,1	,&var415},	//Внутренняя переменная var415
	 30260	,1	,1	,&var839},	//Внутренняя переменная var839
	 30261	,1	,1	,&var945},	//Внутренняя переменная var945
	 30262	,1	,1	,&var1125},	//Внутренняя переменная var1125
	 30263	,1	,1	,&var1609},	//Внутренняя переменная var1609
	 30264	,1	,1	,&var449},	//Внутренняя переменная var449
	 30265	,1	,1	,&var1536},	//Внутренняя переменная var1536
	 30266	,3	,1	,&var1626},	//Внутренняя переменная var1626
	 30267	,	,1	,&var1628},	//Внутренняя переменная var1628
	 30268	,1	,1	,&var1966},	//Внутренняя переменная var1966
	 30269	,1	,1	,&var191},	//Внутренняя переменная var191
	 30270	,1	,1	,&var1147},	//Внутренняя переменная var1147
	 30271	,1	,1	,&var1980},	//Внутренняя переменная var1980
	 30272	,1	,1	,&var1204},	//Внутренняя переменная var1204
	 30273	,1	,1	,&var1347},	//Внутренняя переменная var1347
	 30274	,1	,1	,&var1739},	//Внутренняя переменная var1739
	 30275	,1	,1	,&var1646},	//Внутренняя переменная var1646
	 30276	,1	,1	,&var33},	//Внутренняя переменная var33
	 30277	,8	,1	,&var660},	//Внутренняя переменная var660
	 30278	,1	,1	,&var939},	//Внутренняя переменная var939
	 30279	,1	,1	,&var1025},	//Внутренняя переменная var1025
	 30280	,1	,1	,&var1039},	//Внутренняя переменная var1039
	 30281	,1	,1	,&var1172},	//Внутренняя переменная var1172
	 30282	,1	,1	,&var13},	//Внутренняя переменная var13
	 30283	,1	,1	,&var236},	//Внутренняя переменная var236
	 30284	,1	,1	,&var339},	//Внутренняя переменная var339
	 30285	,1	,1	,&var1180},	//Внутренняя переменная var1180
	 30286	,1	,1	,&var1391},	//Внутренняя переменная var1391
	 30287	,1	,1	,&var354},	//Внутренняя переменная var354
	 30288	,1	,1	,&var726},	//Внутренняя переменная var726
	 30289	,1	,1	,&var1067},	//Внутренняя переменная var1067
	 30290	,1	,1	,&var1168},	//Внутренняя переменная var1168
	 30291	,3	,1	,&var262},	//Внутренняя переменная var262
	 30292	,1	,1	,&var1019},	//Внутренняя переменная var1019
	 30293	,1	,1	,&var1296},	//Внутренняя переменная var1296
	 30294	,1	,1	,&var1553},	//Внутренняя переменная var1553
	 30295	,1	,1	,&var1202},	//Внутренняя переменная var1202
	 30296	,1	,1	,&var1491},	//Внутренняя переменная var1491
	 30297	,1	,1	,&var68},	//Внутренняя переменная var68
	 30298	,1	,1	,&var193},	//Внутренняя переменная var193
	 30299	,1	,1	,&var342},	//Внутренняя переменная var342
	 30300	,1	,1	,&var409},	//Внутренняя переменная var409
	 30301	,8	,1	,&var565},	//Внутренняя переменная var565
	 30302	,1	,1	,&var1166},	//Внутренняя переменная var1166
	 30303	,1	,1	,&var51},	//Внутренняя переменная var51
	 30304	,1	,1	,&var83},	//Внутренняя переменная var83
	 30305	,1	,1	,&var721},	//Внутренняя переменная var721
	 30306	,1	,1	,&var624},	//Внутренняя переменная var624
	 30307	,1	,1	,&var960},	//Внутренняя переменная var960
	 30308	,3	,1	,&var1288},	//Внутренняя переменная var1288
	 30309	,1	,1	,&var1892},	//Внутренняя переменная var1892
	 30310	,1	,1	,&var718},	//Внутренняя переменная var718
	 30311	,1	,1	,&var786},	//Внутренняя переменная var786
	 30312	,1	,1	,&var1393},	//Внутренняя переменная var1393
	 30313	,1	,1	,&var1475},	//Внутренняя переменная var1475
	 30314	,1	,1	,&var463},	//Внутренняя переменная var463
	 30315	,1	,1	,&var913},	//Внутренняя переменная var913
	 30316	,1	,1	,&var1086},	//Внутренняя переменная var1086
	 30317	,1	,1	,&var1420},	//Внутренняя переменная var1420
	 30318	,1	,1	,&var1339},	//Внутренняя переменная var1339
	 30319	,8	,1	,&var1414},	//Внутренняя переменная var1414
	 30320	,1	,1	,&var97},	//Внутренняя переменная var97
	 30321	,1	,1	,&var127},	//Внутренняя переменная var127
	 30322	,3	,1	,&var391},	//Внутренняя переменная var391
	 30323	,1	,1	,&var889},	//Внутренняя переменная var889
	 30324	,1	,1	,&var938},	//Внутренняя переменная var938
	 30325	,1	,1	,&var1298},	//Внутренняя переменная var1298
	 30326	,1	,1	,&var153},	//Внутренняя переменная var153
	 30327	,1	,1	,&var520},	//Внутренняя переменная var520
	 30328	,1	,1	,&var244},	//Внутренняя переменная var244
	 30329	,1	,1	,&var845},	//Внутренняя переменная var845
	 30330	,1	,1	,&var1261},	//Внутренняя переменная var1261
	 30331	,1	,1	,&var1890},	//Внутренняя переменная var1890
	 30332	,1	,1	,&var16},	//Внутренняя переменная var16
	 30333	,1	,1	,&var1148},	//Внутренняя переменная var1148
	 30334	,1	,1	,&var1559},	//Внутренняя переменная var1559
	 30335	,1	,1	,&var1808},	//Внутренняя переменная var1808
	 30336	,1	,1	,&var1012},	//Внутренняя переменная var1012
	 30337	,1	,1	,&var1183},	//Внутренняя переменная var1183
	 30338	,1	,1	,&var1191},	//Внутренняя переменная var1191
	 30339	,1	,1	,&var1707},	//Внутренняя переменная var1707
	 30340	,1	,1	,&var1078},	//Внутренняя переменная var1078
	 30341	,1	,1	,&var1182},	//Внутренняя переменная var1182
	 30342	,1	,1	,&var1529},	//Внутренняя переменная var1529
	 30343	,1	,1	,&var1613},	//Внутренняя переменная var1613
	 30344	,1	,1	,&var142},	//Внутренняя переменная var142
	 30345	,1	,1	,&var581},	//Внутренняя переменная var581
	 30346	,1	,1	,&var982},	//Внутренняя переменная var982
	 30347	,1	,1	,&var1630},	//Внутренняя переменная var1630
	 30348	,1	,1	,&var1827},	//Внутренняя переменная var1827
	 30349	,1	,1	,&var381},	//Внутренняя переменная var381
	 30350	,1	,1	,&var439},	//Внутренняя переменная var439
	 30351	,1	,1	,&var1713},	//Внутренняя переменная var1713
	 30352	,1	,1	,&var968},	//Внутренняя переменная var968
	 30353	,1	,1	,&var73},	//Внутренняя переменная var73
	 30354	,8	,1	,&var1988},	//Внутренняя переменная var1988
	 30355	,1	,1	,&var162},	//Внутренняя переменная var162
	 30356	,1	,1	,&var340},	//Внутренняя переменная var340
	 30357	,1	,1	,&var362},	//Внутренняя переменная var362
	 30358	,1	,1	,&var1276},	//Внутренняя переменная var1276
	 30359	,1	,1	,&var1380},	//Внутренняя переменная var1380
	 30360	,1	,1	,&var1888},	//Внутренняя переменная var1888
	 30361	,1	,1	,&var1765},	//Внутренняя переменная var1765
	 30362	,1	,1	,&var1872},	//Внутренняя переменная var1872
	 30363	,1	,1	,&var211},	//Внутренняя переменная var211
	 30364	,1	,1	,&var431},	//Внутренняя переменная var431
	 30365	,1	,1	,&var519},	//Внутренняя переменная var519
	 30366	,1	,1	,&var649},	//Внутренняя переменная var649
	 30367	,1	,1	,&var1087},	//Внутренняя переменная var1087
	 30368	,1	,1	,&var1725},	//Внутренняя переменная var1725
	 30369	,1	,1	,&var1877},	//Внутренняя переменная var1877
	 30370	,1	,1	,&var1987},	//Внутренняя переменная var1987
	 30371	,1	,1	,&var1999},	//Внутренняя переменная var1999
	 30372	,1	,1	,&var178},	//Внутренняя переменная var178
	 30373	,1	,1	,&var566},	//Внутренняя переменная var566
	 30374	,1	,1	,&var876},	//Внутренняя переменная var876
	 30375	,1	,1	,&var1093},	//Внутренняя переменная var1093
	 30376	,1	,1	,&var1654},	//Внутренняя переменная var1654
	 30377	,1	,1	,&var1742},	//Внутренняя переменная var1742
	 30378	,1	,1	,&var58},	//Внутренняя переменная var58
	 30379	,1	,1	,&var163},	//Внутренняя переменная var163
	 30380	,1	,1	,&var559},	//Внутренняя переменная var559
	 30381	,1	,1	,&var735},	//Внутренняя переменная var735
	 30382	,1	,1	,&var848},	//Внутренняя переменная var848
	 30383	,1	,1	,&var661},	//Внутренняя переменная var661
	 30384	,1	,1	,&var701},	//Внутренняя переменная var701
	 30385	,1	,1	,&var992},	//Внутренняя переменная var992
	 30386	,1	,1	,&var1331},	//Внутренняя переменная var1331
	 30387	,1	,1	,&var1485},	//Внутренняя переменная var1485
	 30388	,1	,1	,&var184},	//Внутренняя переменная var184
	 30389	,1	,1	,&var343},	//Внутренняя переменная var343
	 30390	,1	,1	,&var702},	//Внутренняя переменная var702
	 30391	,1	,1	,&var717},	//Внутренняя переменная var717
	 30392	,1	,1	,&var821},	//Внутренняя переменная var821
	 30393	,1	,1	,&var1368},	//Внутренняя переменная var1368
	 30394	,1	,1	,&var723},	//Внутренняя переменная var723
	 30395	,1	,1	,&var1787},	//Внутренняя переменная var1787
	 30396	,1	,1	,&var1891},	//Внутренняя переменная var1891
	 30397	,1	,1	,&var82},	//Внутренняя переменная var82
	 30398	,1	,1	,&var469},	//Внутренняя переменная var469
	 30399	,1	,1	,&var774},	//Внутренняя переменная var774
	 30400	,1	,1	,&var1186},	//Внутренняя переменная var1186
	 30401	,1	,1	,&var1854},	//Внутренняя переменная var1854
	 30402	,1	,1	,&var592},	//Внутренняя переменная var592
	 30403	,1	,1	,&var871},	//Внутренняя переменная var871
	 30404	,1	,1	,&var1033},	//Внутренняя переменная var1033
	 30405	,1	,1	,&var1107},	//Внутренняя переменная var1107
	 30406	,8	,1	,&var1375},	//Внутренняя переменная var1375
	 30407	,1	,1	,&var1705},	//Внутренняя переменная var1705
	 30408	,1	,1	,&var1145},	//Внутренняя переменная var1145
	 30409	,1	,1	,&var1400},	//Внутренняя переменная var1400
	 30410	,3	,1	,&var1510},	//Внутренняя переменная var1510
	 30411	,1	,1	,&var1939},	//Внутренняя переменная var1939
	 30412	,1	,1	,&var88},	//Внутренняя переменная var88
	 30413	,1	,1	,&var1929},	//Внутренняя переменная var1929
	 30414	,1	,1	,&var31},	//Внутренняя переменная var31
	 30415	,1	,1	,&var212},	//Внутренняя переменная var212
	 30416	,1	,1	,&var539},	//Внутренняя переменная var539
	 30417	,1	,1	,&var1304},	//Внутренняя переменная var1304
	 30418	,1	,1	,&var126},	//Внутренняя переменная var126
	 30419	,1	,1	,&var1294},	//Внутренняя переменная var1294
	 30420	,8	,1	,&var459},	//Внутренняя переменная var459
	 30421	,1	,1	,&var703},	//Внутренняя переменная var703
	 30422	,1	,1	,&var1324},	//Внутренняя переменная var1324
	 30423	,1	,1	,&var1619},	//Внутренняя переменная var1619
	 30424	,1	,1	,&var116},	//Внутренняя переменная var116
	 30425	,1	,1	,&var394},	//Внутренняя переменная var394
	 30426	,1	,1	,&var1964},	//Внутренняя переменная var1964
	 30427	,1	,1	,&var171},	//Внутренняя переменная var171
	 30428	,1	,1	,&var1221},	//Внутренняя переменная var1221
	 30429	,1	,1	,&var86},	//Внутренняя переменная var86
	 30430	,1	,1	,&var205},	//Внутренняя переменная var205
	 30431	,1	,1	,&var760},	//Внутренняя переменная var760
	 30432	,1	,1	,&var969},	//Внутренняя переменная var969
	 30433	,1	,1	,&var1450},	//Внутренняя переменная var1450
	 30434	,1	,1	,&var106},	//Внутренняя переменная var106
	 30435	,1	,1	,&var385},	//Внутренняя переменная var385
	 30436	,1	,1	,&var746},	//Внутренняя переменная var746
	 30437	,1	,1	,&var921},	//Внутренняя переменная var921
	 30438	,8	,1	,&var1222},	//Внутренняя переменная var1222
	 30439	,1	,1	,&var1800},	//Внутренняя переменная var1800
	 30440	,1	,1	,&var419},	//Внутренняя переменная var419
	 30441	,1	,1	,&var435},	//Внутренняя переменная var435
	 30442	,1	,1	,&var892},	//Внутренняя переменная var892
	 30443	,1	,1	,&var928},	//Внутренняя переменная var928
	 30444	,1	,1	,&var1126},	//Внутренняя переменная var1126
	 30445	,1	,1	,&var1195},	//Внутренняя переменная var1195
	 30446	,1	,1	,&var1908},	//Внутренняя переменная var1908
	 30447	,1	,1	,&var355},	//Внутренняя переменная var355
	 30448	,1	,1	,&var556},	//Внутренняя переменная var556
	 30449	,1	,1	,&var817},	//Внутренняя переменная var817
	 30450	,1	,1	,&var1885},	//Внутренняя переменная var1885
	 30451	,1	,1	,&var324},	//Внутренняя переменная var324
	 30452	,1	,1	,&var379},	//Внутренняя переменная var379
	 30453	,1	,1	,&var751},	//Внутренняя переменная var751
	 30454	,1	,1	,&var886},	//Внутренняя переменная var886
	 30455	,1	,1	,&var1497},	//Внутренняя переменная var1497
	 30456	,1	,1	,&var1927},	//Внутренняя переменная var1927
	 30457	,1	,1	,&var179},	//Внутренняя переменная var179
	 30458	,1	,1	,&var547},	//Внутренняя переменная var547
	 30459	,1	,1	,&var1481},	//Внутренняя переменная var1481
	 30460	,1	,1	,&var28},	//Внутренняя переменная var28
	 30461	,1	,1	,&var1521},	//Внутренняя переменная var1521
	 30462	,1	,1	,&var570},	//Внутренняя переменная var570
	 30463	,8	,1	,&var662},	//Внутренняя переменная var662
	 30464	,1	,1	,&var809},	//Внутренняя переменная var809
	 30465	,1	,1	,&var826},	//Внутренняя переменная var826
	 30466	,1	,1	,&var908},	//Внутренняя переменная var908
	 30467	,1	,1	,&var1219},	//Внутренняя переменная var1219
	 30468	,1	,1	,&var275},	//Внутренняя переменная var275
	 30469	,1	,1	,&var781},	//Внутренняя переменная var781
	 30470	,1	,1	,&var977},	//Внутренняя переменная var977
	 30471	,1	,1	,&var36},	//Внутренняя переменная var36
	 30472	,1	,1	,&var347},	//Внутренняя переменная var347
	 30473	,1	,1	,&var841},	//Внутренняя переменная var841
	 30474	,1	,1	,&var1259},	//Внутренняя переменная var1259
	 30475	,1	,1	,&var1816},	//Внутренняя переменная var1816
	 30476	,1	,1	,&var1599},	//Внутренняя переменная var1599
	 30477	,1	,1	,&var1766},	//Внутренняя переменная var1766
	 30478	,8	,1	,&var45},	//Внутренняя переменная var45
	 30479	,3	,1	,&var466},	//Внутренняя переменная var466
	 30480	,1	,1	,&var579},	//Внутренняя переменная var579
	 30481	,1	,1	,&var865},	//Внутренняя переменная var865
	 30482	,1	,1	,&var965},	//Внутренняя переменная var965
	 30483	,1	,1	,&var1503},	//Внутренняя переменная var1503
	 30484	,1	,1	,&var7},	//Внутренняя переменная var7
	 30485	,1	,1	,&var129},	//Внутренняя переменная var129
	 30486	,1	,1	,&var577},	//Внутренняя переменная var577
	 30487	,1	,1	,&var1759},	//Внутренняя переменная var1759
	 30488	,1	,1	,&var478},	//Внутренняя переменная var478
	 30489	,1	,1	,&var646},	//Внутренняя переменная var646
	 30490	,1	,1	,&var1313},	//Внутренняя переменная var1313
	 30491	,1	,1	,&var1586},	//Внутренняя переменная var1586
	 30492	,1	,1	,&var1989},	//Внутренняя переменная var1989
	 30493	,1	,1	,&var1140},	//Внутренняя переменная var1140
	 30494	,1	,1	,&var1760},	//Внутренняя переменная var1760
	 30495	,1	,1	,&var140},	//Внутренняя переменная var140
	 30496	,1	,1	,&var229},	//Внутренняя переменная var229
	 30497	,1	,1	,&var384},	//Внутренняя переменная var384
	 30498	,1	,1	,&var411},	//Внутренняя переменная var411
	 30499	,1	,1	,&var725},	//Внутренняя переменная var725
	 30500	,1	,1	,&var1359},	//Внутренняя переменная var1359
	 30501	,1	,1	,&var177},	//Внутренняя переменная var177
	 30502	,1	,1	,&var357},	//Внутренняя переменная var357
	 30503	,1	,1	,&var804},	//Внутренняя переменная var804
	 30504	,1	,1	,&var396},	//Внутренняя переменная var396
	 30505	,1	,1	,&var1543},	//Внутренняя переменная var1543
	 30506	,1	,1	,&var1762},	//Внутренняя переменная var1762
	 30507	,1	,1	,&var305},	//Внутренняя переменная var305
	 30508	,1	,1	,&var643},	//Внутренняя переменная var643
	 30509	,1	,1	,&var1208},	//Внутренняя переменная var1208
	 30510	,1	,1	,&var1920},	//Внутренняя переменная var1920
	 30511	,1	,1	,&var1957},	//Внутренняя переменная var1957
	 30512	,1	,1	,&var113},	//Внутренняя переменная var113
	 30513	,1	,1	,&var1137},	//Внутренняя переменная var1137
	 30514	,1	,1	,&var1698},	//Внутренняя переменная var1698
	 30515	,1	,1	,&var266},	//Внутренняя переменная var266
	 30516	,1	,1	,&var454},	//Внутренняя переменная var454
	 30517	,1	,1	,&var590},	//Внутренняя переменная var590
	 30518	,1	,1	,&var1241},	//Внутренняя переменная var1241
	 30519	,1	,1	,&var1749},	//Внутренняя переменная var1749
	 30520	,1	,1	,&var293},	//Внутренняя переменная var293
	 30521	,1	,1	,&var964},	//Внутренняя переменная var964
	 30522	,1	,1	,&var1101},	//Внутренняя переменная var1101
	 30523	,1	,1	,&var1789},	//Внутренняя переменная var1789
	 30524	,8	,1	,&var1985},	//Внутренняя переменная var1985
	 30525	,1	,1	,&var467},	//Внутренняя переменная var467
	 30526	,1	,1	,&var897},	//Внутренняя переменная var897
	 30527	,1	,1	,&var1961},	//Внутренняя переменная var1961
	 30528	,1	,1	,&var168},	//Внутренняя переменная var168
	 30529	,1	,1	,&var180},	//Внутренняя переменная var180
	 30530	,1	,1	,&var895},	//Внутренняя переменная var895
	 30531	,1	,1	,&var1049},	//Внутренняя переменная var1049
	 30532	,1	,1	,&var483},	//Внутренняя переменная var483
	 30533	,1	,1	,&var732},	//Внутренняя переменная var732
	 30534	,1	,1	,&var1813},	//Внутренняя переменная var1813
	 30535	,1	,1	,&var107},	//Внутренняя переменная var107
	 30536	,1	,1	,&var502},	//Внутренняя переменная var502
	 30537	,1	,1	,&var1330},	//Внутренняя переменная var1330
	 30538	,1	,1	,&var1679},	//Внутренняя переменная var1679
	 30539	,1	,1	,&var372},	//Внутренняя переменная var372
	 30540	,1	,1	,&var387},	//Внутренняя переменная var387
	 30541	,1	,1	,&var536},	//Внутренняя переменная var536
	 30542	,1	,1	,&var6},	//Внутренняя переменная var6
	 30543	,1	,1	,&var1459},	//Внутренняя переменная var1459
	 30544	,3	,1	,&var1656},	//Внутренняя переменная var1656
	 30545	,1	,1	,&var1876},	//Внутренняя переменная var1876
	 30546	,8	,1	,&vainSFloat},	//Внутренняя переменная vainSFloat
	 30547	,1	,1	,&var640},	//Внутренняя переменная var640
	 30548	,1	,1	,&var847},	//Внутренняя переменная var847
	 30549	,1	,1	,&var850},	//Внутренняя переменная var850
	 30550	,1	,1	,&var878},	//Внутренняя переменная var878
	 30551	,1	,1	,&var1895},	//Внутренняя переменная var1895
	 30552	,1	,1	,&var1928},	//Внутренняя переменная var1928
	 30553	,1	,1	,&var798},	//Внутренняя переменная var798
	 30554	,1	,1	,&var909},	//Внутренняя переменная var909
	 30555	,1	,1	,&var1785},	//Внутренняя переменная var1785
	 30556	,1	,1	,&var1780},	//Внутренняя переменная var1780
	 30557	,1	,1	,&var1848},	//Внутренняя переменная var1848
	 30558	,1	,1	,&var1896},	//Внутренняя переменная var1896
	 30559	,1	,1	,&var130},	//Внутренняя переменная var130
	 30560	,1	,1	,&var219},	//Внутренняя переменная var219
	 30561	,1	,1	,&var451},	//Внутренняя переменная var451
	 30562	,1	,1	,&var1627},	//Внутренняя переменная var1627
	 30563	,1	,1	,&var1133},	//Внутренняя переменная var1133
	 30564	,1	,1	,&var1205},	//Внутренняя переменная var1205
	 30565	,	,1	,&var1546},	//Внутренняя переменная var1546
	 30566	,1	,1	,&var1638},	//Внутренняя переменная var1638
	 30567	,1	,1	,&var1847},	//Внутренняя переменная var1847
	 30568	,1	,1	,&var109},	//Внутренняя переменная var109
	 30569	,1	,1	,&var600},	//Внутренняя переменная var600
	 30570	,1	,1	,&var749},	//Внутренняя переменная var749
	 30571	,1	,1	,&var103},	//Внутренняя переменная var103
	 30572	,1	,1	,&var1027},	//Внутренняя переменная var1027
	 30573	,1	,1	,&var1144},	//Внутренняя переменная var1144
	 30574	,1	,1	,&var1247},	//Внутренняя переменная var1247
	 30575	,1	,1	,&var1254},	//Внутренняя переменная var1254
	 30576	,1	,1	,&var1741},	//Внутренняя переменная var1741
	 30577	,1	,1	,&var380},	//Внутренняя переменная var380
	 30578	,1	,1	,&var644},	//Внутренняя переменная var644
	 30579	,1	,1	,&var846},	//Внутренняя переменная var846
	 30580	,1	,1	,&var1242},	//Внутренняя переменная var1242
	 30581	,1	,1	,&var1550},	//Внутренняя переменная var1550
	 30582	,1	,1	,&var115},	//Внутренняя переменная var115
	 30583	,8	,1	,&var1537},	//Внутренняя переменная var1537
	 30584	,1	,1	,&var237},	//Внутренняя переменная var237
	 30585	,1	,1	,&var398},	//Внутренняя переменная var398
	 30586	,1	,1	,&var498},	//Внутренняя переменная var498
	 30587	,1	,1	,&var681},	//Внутренняя переменная var681
	 30588	,1	,1	,&var1925},	//Внутренняя переменная var1925
	 30589	,1	,1	,&var341},	//Внутренняя переменная var341
	 30590	,1	,1	,&var488},	//Внутренняя переменная var488
	 30591	,1	,1	,&var1935},	//Внутренняя переменная var1935
	 30592	,1	,1	,&var834},	//Внутренняя переменная var834
	 30593	,1	,1	,&var837},	//Внутренняя переменная var837
	 30594	,1	,1	,&var1270},	//Внутренняя переменная var1270
	 30595	,1	,1	,&var1436},	//Внутренняя переменная var1436
	 30596	,8	,1	,&var1545},	//Внутренняя переменная var1545
	 30597	,1	,1	,&var254},	//Внутренняя переменная var254
	 30598	,1	,1	,&var1882},	//Внутренняя переменная var1882
	 30599	,1	,1	,&var510},	//Внутренняя переменная var510
	 30600	,1	,1	,&var936},	//Внутренняя переменная var936
	 30601	,1	,1	,&var1277},	//Внутренняя переменная var1277
	 30602	,1	,1	,&var1603},	//Внутренняя переменная var1603
	 30603	,1	,1	,&var733},	//Внутренняя переменная var733
	 30604	,1	,1	,&var820},	//Внутренняя переменная var820
	 30605	,1	,1	,&var815},	//Внутренняя переменная var815
	 30606	,1	,1	,&var1455},	//Внутренняя переменная var1455
	 30607	,1	,1	,&var550},	//Внутренняя переменная var550
	 30608	,1	,1	,&var759},	//Внутренняя переменная var759
	 30609	,1	,1	,&var1220},	//Внутренняя переменная var1220
	 30610	,1	,1	,&var1343},	//Внутренняя переменная var1343
	 30611	,1	,1	,&var1574},	//Внутренняя переменная var1574
	 30612	,1	,1	,&var899},	//Внутренняя переменная var899
	 30613	,1	,1	,&var1336},	//Внутренняя переменная var1336
	 30614	,1	,1	,&var1526},	//Внутренняя переменная var1526
	 30615	,1	,1	,&var110},	//Внутренняя переменная var110
	 30616	,1	,1	,&var574},	//Внутренняя переменная var574
	 30617	,1	,1	,&var954},	//Внутренняя переменная var954
	 30618	,1	,1	,&var1954},	//Внутренняя переменная var1954
	 30619	,1	,1	,&var268},	//Внутренняя переменная var268
	 30620	,1	,1	,&var1057},	//Внутренняя переменная var1057
	 30621	,1	,1	,&var1155},	//Внутренняя переменная var1155
	 30622	,1	,1	,&var263},	//Внутренняя переменная var263
	 30623	,1	,1	,&var541},	//Внутренняя переменная var541
	 30624	,1	,1	,&var1448},	//Внутренняя переменная var1448
	 30625	,	,1	,&var1699},	//Внутренняя переменная var1699
	 30626	,8	,1	,&var2001},	//Внутренняя переменная var2001
	 30627	,1	,1	,&var1751},	//Внутренняя переменная var1751
	 30628	,1	,1	,&var1941},	//Внутренняя переменная var1941
	 30629	,1	,1	,&var500},	//Внутренняя переменная var500
	 30630	,1	,1	,&var571},	//Внутренняя переменная var571
	 30631	,1	,1	,&var758},	//Внутренняя переменная var758
	 30632	,1	,1	,&var872},	//Внутренняя переменная var872
	 30633	,1	,1	,&var1278},	//Внутренняя переменная var1278
	 30634	,3	,1	,&var1287},	//Внутренняя переменная var1287
	 30635	,1	,1	,&var1992},	//Внутренняя переменная var1992
	 30636	,1	,1	,&var48},	//Внутренняя переменная var48
	 30637	,8	,1	,&var666},	//Внутренняя переменная var666
	 30638	,8	,1	,&var672},	//Внутренняя переменная var672
	 30639	,1	,1	,&var704},	//Внутренняя переменная var704
	 30640	,1	,1	,&var1197},	//Внутренняя переменная var1197
	 30641	,1	,1	,&var143},	//Внутренняя переменная var143
	 30642	,1	,1	,&var947},	//Внутренняя переменная var947
	 30643	,1	,1	,&var1074},	//Внутренняя переменная var1074
	 30644	,1	,1	,&var1406},	//Внутренняя переменная var1406
	 30645	,1	,1	,&var1907},	//Внутренняя переменная var1907
	 30646	,1	,1	,&var584},	//Внутренняя переменная var584
	 30647	,1	,1	,&var639},	//Внутренняя переменная var639
	 30648	,1	,1	,&var1151},	//Внутренняя переменная var1151
	 30649	,1	,1	,&var1657},	//Внутренняя переменная var1657
	 30650	,8	,1	,&var1982},	//Внутренняя переменная var1982
	 30651	,1	,1	,&var790},	//Внутренняя переменная var790
	 30652	,1	,1	,&var67},	//Внутренняя переменная var67
	 30653	,1	,1	,&var806},	//Внутренняя переменная var806
	 30654	,1	,1	,&var1345},	//Внутренняя переменная var1345
	 30655	,1	,1	,&var1432},	//Внутренняя переменная var1432
	 30656	,1	,1	,&var1670},	//Внутренняя переменная var1670
	 30657	,1	,1	,&var1886},	//Внутренняя переменная var1886
	 30658	,1	,1	,&var620},	//Внутренняя переменная var620
	 30659	,1	,1	,&var1899},	//Внутренняя переменная var1899
	 30660	,1	,1	,&var1196},	//Внутренняя переменная var1196
	 30661	,1	,1	,&var1509},	//Внутренняя переменная var1509
	 30662	,1	,1	,&var1519},	//Внутренняя переменная var1519
	 30663	,1	,1	,&var360},	//Внутренняя переменная var360
	 30664	,1	,1	,&var558},	//Внутренняя переменная var558
	 30665	,1	,1	,&var1540},	//Внутренняя переменная var1540
	 30666	,1	,1	,&var1652},	//Внутренняя переменная var1652
	 30667	,8	,1	,&var1733},	//Внутренняя переменная var1733
	 30668	,1	,1	,&var766},	//Внутренняя переменная var766
	 30669	,8	,1	,&var1690},	//Внутренняя переменная var1690
	 30670	,1	,1	,&var1805},	//Внутренняя переменная var1805
	 30671	,1	,1	,&var99},	//Внутренняя переменная var99
	 30672	,1	,1	,&var1443},	//Внутренняя переменная var1443
	 30673	,1	,1	,&var1474},	//Внутренняя переменная var1474
	 30674	,8	,1	,&var1577},	//Внутренняя переменная var1577
	 30675	,1	,1	,&var687},	//Внутренняя переменная var687
	 30676	,1	,1	,&var868},	//Внутренняя переменная var868
	 30677	,1	,1	,&var946},	//Внутренняя переменная var946
	 30678	,1	,1	,&var1833},	//Внутренняя переменная var1833
	 30679	,1	,1	,&var1884},	//Внутренняя переменная var1884
	 30680	,8	,1	,&var1991},	//Внутренняя переменная var1991
	 30681	,1	,1	,&var238},	//Внутренняя переменная var238
	 30682	,1	,1	,&var575},	//Внутренняя переменная var575
	 30683	,1	,1	,&var710},	//Внутренняя переменная var710
	 30684	,1	,1	,&var1480},	//Внутренняя переменная var1480
	 30685	,1	,1	,&var1562},	//Внутренняя переменная var1562
	 30686	,1	,1	,&var1996},	//Внутренняя переменная var1996
	 30687	,1	,1	,&var1091},	//Внутренняя переменная var1091
	 30688	,1	,1	,&var1154},	//Внутренняя переменная var1154
	 30689	,1	,1	,&var1984},	//Внутренняя переменная var1984
	 30690	,1	,1	,&var585},	//Внутренняя переменная var585
	 30691	,1	,1	,&var1756},	//Внутренняя переменная var1756
	 30692	,1	,1	,&var145},	//Внутренняя переменная var145
	 30693	,1	,1	,&var159},	//Внутренняя переменная var159
	 30694	,1	,1	,&var974},	//Внутренняя переменная var974
	 30695	,1	,1	,&var1046},	//Внутренняя переменная var1046
	 30696	,1	,1	,&var1975},	//Внутренняя переменная var1975
	 30697	,1	,1	,&var257},	//Внутренняя переменная var257
	 30698	,1	,1	,&var1439},	//Внутренняя переменная var1439
	 30699	,1	,1	,&var1506},	//Внутренняя переменная var1506
	 30700	,1	,1	,&var494},	//Внутренняя переменная var494
	 30701	,1	,1	,&var674},	//Внутренняя переменная var674
	 30702	,1	,1	,&var862},	//Внутренняя переменная var862
	 30703	,1	,1	,&var1858},	//Внутренняя переменная var1858
	 30704	,1	,1	,&var43},	//Внутренняя переменная var43
	 30705	,1	,1	,&var137},	//Внутренняя переменная var137
	 30706	,1	,1	,&var375},	//Внутренняя переменная var375
	 30707	,1	,1	,&var475},	//Внутренняя переменная var475
	 30708	,1	,1	,&var1136},	//Внутренняя переменная var1136
	 30709	,1	,1	,&var1781},	//Внутренняя переменная var1781
	 30710	,1	,1	,&var1077},	//Внутренняя переменная var1077
	 30711	,1	,1	,&var1597},	//Внутренняя переменная var1597
	 30712	,1	,1	,&var1637},	//Внутренняя переменная var1637
	 30713	,1	,1	,&var1740},	//Внутренняя переменная var1740
	 30714	,1	,1	,&var242},	//Внутренняя переменная var242
	 30715	,1	,1	,&var1618},	//Внутренняя переменная var1618
	 30716	,1	,1	,&var1720},	//Внутренняя переменная var1720
	 30717	,1	,1	,&var96},	//Внутренняя переменная var96
	 30718	,1	,1	,&var551},	//Внутренняя переменная var551
	 30719	,1	,1	,&var1642},	//Внутренняя переменная var1642
	 30720	,1	,1	,&var1843},	//Внутренняя переменная var1843
	 30721	,1	,1	,&var1977},	//Внутренняя переменная var1977
	 30722	,1	,1	,&var231},	//Внутренняя переменная var231
	 30723	,1	,1	,&var1050},	//Внутренняя переменная var1050
	 30724	,1	,1	,&var1080},	//Внутренняя переменная var1080
	 30725	,1	,1	,&var1209},	//Внутренняя переменная var1209
	 30726	,1	,1	,&var1976},	//Внутренняя переменная var1976
	 30727	,1	,1	,&var105},	//Внутренняя переменная var105
	 30728	,1	,1	,&var554},	//Внутренняя переменная var554
	 30729	,1	,1	,&var935},	//Внутренняя переменная var935
	 30730	,1	,1	,&var1376},	//Внутренняя переменная var1376
	 30731	,1	,1	,&var1555},	//Внутренняя переменная var1555
	 30732	,1	,1	,&var25},	//Внутренняя переменная var25
	 30733	,1	,1	,&var32},	//Внутренняя переменная var32
	 30734	,1	,1	,&var1131},	//Внутренняя переменная var1131
	 30735	,1	,1	,&var1471},	//Внутренняя переменная var1471
	 30736	,1	,1	,&var1621},	//Внутренняя переменная var1621
	 30737	,1	,1	,&var260},	//Внутренняя переменная var260
	 30738	,1	,1	,&var693},	//Внутренняя переменная var693
	 30739	,8	,1	,&var1643},	//Внутренняя переменная var1643
	 30740	,1	,1	,&var1384},	//Внутренняя переменная var1384
	 30741	,1	,1	,&var1937},	//Внутренняя переменная var1937
	 30742	,1	,1	,&var190},	//Внутренняя переменная var190
	 30743	,1	,1	,&var810},	//Внутренняя переменная var810
	 30744	,1	,1	,&var838},	//Внутренняя переменная var838
	 30745	,1	,1	,&var1143},	//Внутренняя переменная var1143
	 30746	,1	,1	,&var1153},	//Внутренняя переменная var1153
	 30747	,1	,1	,&var1297},	//Внутренняя переменная var1297
	 30748	,1	,1	,&var227},	//Внутренняя переменная var227
	 30749	,1	,1	,&var583},	//Внутренняя переменная var583
	 30750	,1	,1	,&var1280},	//Внутренняя переменная var1280
	 30751	,1	,1	,&var548},	//Внутренняя переменная var548
	 30752	,1	,1	,&var1006},	//Внутренняя переменная var1006
	 30753	,1	,1	,&var63},	//Внутренняя переменная var63
	 30754	,1	,1	,&var120},	//Внутренняя переменная var120
	 30755	,1	,1	,&var255},	//Внутренняя переменная var255
	 30756	,1	,1	,&var265},	//Внутренняя переменная var265
	 30757	,1	,1	,&var271},	//Внутренняя переменная var271
	 30758	,1	,1	,&var281},	//Внутренняя переменная var281
	 30759	,1	,1	,&var1923},	//Внутренняя переменная var1923
	 30760	,1	,1	,&var647},	//Внутренняя переменная var647
	 30761	,1	,1	,&var1135},	//Внутренняя переменная var1135
	 30762	,1	,1	,&var1329},	//Внутренняя переменная var1329
	 30763	,1	,1	,&var371},	//Внутренняя переменная var371
	 30764	,1	,1	,&var761},	//Внутренняя переменная var761
	 30765	,1	,1	,&var792},	//Внутренняя переменная var792
	 30766	,1	,1	,&var1898},	//Внутренняя переменная var1898
	 30767	,1	,1	,&var597},	//Внутренняя переменная var597
	 30768	,1	,1	,&var835},	//Внутренняя переменная var835
	 30769	,1	,1	,&var1207},	//Внутренняя переменная var1207
	 30770	,1	,1	,&var100},	//Внутренняя переменная var100
	 30771	,1	,1	,&var1238},	//Внутренняя переменная var1238
	 30772	,	,1	,&var1687},	//Внутренняя переменная var1687
	 30773	,1	,1	,&var1743},	//Внутренняя переменная var1743
	 30774	,1	,1	,&var322},	//Внутренняя переменная var322
	 30775	,1	,1	,&var985},	//Внутренняя переменная var985
	 30776	,1	,1	,&var1163},	//Внутренняя переменная var1163
	 30777	,1	,1	,&var1614},	//Внутренняя переменная var1614
	 30778	,1	,1	,&var1918},	//Внутренняя переменная var1918
	 30779	,1	,1	,&var203},	//Внутренняя переменная var203
	 30780	,1	,1	,&var1349},	//Внутренняя переменная var1349
	 30781	,1	,1	,&var1541},	//Внутренняя переменная var1541
	 30782	,8	,1	,&var1727},	//Внутренняя переменная var1727
	 30783	,1	,1	,&var1936},	//Внутренняя переменная var1936
	 30784	,1	,1	,&var1956},	//Внутренняя переменная var1956
	 30785	,1	,1	,&var404},	//Внутренняя переменная var404
	 30786	,1	,1	,&var540},	//Внутренняя переменная var540
	 30787	,1	,1	,&var729},	//Внутренняя переменная var729
	 30788	,1	,1	,&var1507},	//Внутренняя переменная var1507
	 30789	,1	,1	,&var410},	//Внутренняя переменная var410
	 30790	,1	,1	,&var689},	//Внутренняя переменная var689
	 30791	,1	,1	,&var1156},	//Внутренняя переменная var1156
	 30792	,1	,1	,&var1419},	//Внутренняя переменная var1419
	 30793	,1	,1	,&var1901},	//Внутренняя переменная var1901
	 30794	,1	,1	,&var1729},	//Внутренняя переменная var1729
	 30795	,1	,1	,&var1910},	//Внутренняя переменная var1910
	 30796	,1	,1	,&var1062},	//Внутренняя переменная var1062
	 30797	,1	,1	,&var1386},	//Внутренняя переменная var1386
	 30798	,1	,1	,&var289},	//Внутренняя переменная var289
	 30799	,1	,1	,&var492},	//Внутренняя переменная var492
	 30800	,1	,1	,&var1198},	//Внутренняя переменная var1198
	 30801	,1	,1	,&var1998},	//Внутренняя переменная var1998
	 30802	,1	,1	,&var1864},	//Внутренняя переменная var1864
	 30803	,1	,1	,&var1932},	//Внутренняя переменная var1932
	 30804	,1	,1	,&var1079},	//Внутренняя переменная var1079
	 30805	,1	,1	,&var1192},	//Внутренняя переменная var1192
	 30806	,1	,1	,&var1235},	//Внутренняя переменная var1235
	 30807	,1	,1	,&var1463},	//Внутренняя переменная var1463
	 30808	,1	,1	,&var413},	//Внутренняя переменная var413
	 30809	,1	,1	,&var503},	//Внутренняя переменная var503
	 30810	,1	,1	,&var1379},	//Внутренняя переменная var1379
	 30811	,1	,1	,&var1842},	//Внутренняя переменная var1842
	 30812	,1	,1	,&var1281},	//Внутренняя переменная var1281
	 30813	,1	,1	,&var1317},	//Внутренняя переменная var1317
	 30814	,1	,1	,&var602},	//Внутренняя переменная var602
	 30815	,1	,1	,&var1444},	//Внутренняя переменная var1444
	 30816	,1	,1	,&var317},	//Внутренняя переменная var317
	 30817	,1	,1	,&var654},	//Внутренняя переменная var654
	 30818	,1	,1	,&var37},	//Внутренняя переменная var37
	 30819	,1	,1	,&var134},	//Внутренняя переменная var134
	 30820	,1	,1	,&var1051},	//Внутренняя переменная var1051
	 30821	,1	,1	,&var1139},	//Внутренняя переменная var1139
	 30822	,1	,1	,&var1201},	//Внутренняя переменная var1201
	 30823	,1	,1	,&var1460},	//Внутренняя переменная var1460
	 30824	,8	,1	,&var1583},	//Внутренняя переменная var1583
	 30825	,1	,1	,&var698},	//Внутренняя переменная var698
	 30826	,8	,1	,&var1369},	//Внутренняя переменная var1369
	 30827	,1	,1	,&var401},	//Внутренняя переменная var401
	 30828	,1	,1	,&var1044},	//Внутренняя переменная var1044
	 30829	,1	,1	,&var1060},	//Внутренняя переменная var1060
	 30830	,1	,1	,&var1446},	//Внутренняя переменная var1446
	 30831	,1	,1	,&var1653},	//Внутренняя переменная var1653
	 30832	,1	,1	,&var1973},	//Внутренняя переменная var1973
	 30833	,1	,1	,&var323},	//Внутренняя переменная var323
	 30834	,1	,1	,&var351},	//Внутренняя переменная var351
	 30835	,1	,1	,&var589},	//Внутренняя переменная var589
	 30836	,1	,1	,&var612},	//Внутренняя переменная var612
	 30837	,1	,1	,&var1122},	//Внутренняя переменная var1122
	 30838	,1	,1	,&var667},	//Внутренняя переменная var667
	 30839	,1	,1	,&var1048},	//Внутренняя переменная var1048
	 30840	,1	,1	,&var1731},	//Внутренняя переменная var1731
	 30841	,8	,1	,&var1952},	//Внутренняя переменная var1952
	 30842	,1	,1	,&var46},	//Внутренняя переменная var46
	 30843	,3	,1	,&var388},	//Внутренняя переменная var388
	 30844	,1	,1	,&var731},	//Внутренняя переменная var731
	 30845	,8	,1	,&var1215},	//Внутренняя переменная var1215
	 30846	,1	,1	,&var1700},	//Внутренняя переменная var1700
	 30847	,1	,1	,&var1944},	//Внутренняя переменная var1944
	 30848	,1	,1	,&var325},	//Внутренняя переменная var325
	 30849	,1	,1	,&var807},	//Внутренняя переменная var807
	 30850	,1	,1	,&var1865},	//Внутренняя переменная var1865
	 30851	,1	,1	,&var1870},	//Внутренняя переменная var1870
	 30852	,1	,1	,&var505},	//Внутренняя переменная var505
	 30853	,1	,1	,&var771},	//Внутренняя переменная var771
	 30854	,1	,1	,&var1791},	//Внутренняя переменная var1791
	 30855	,1	,1	,&var1906},	//Внутренняя переменная var1906
	 30856	,1	,1	,&var198},	//Внутренняя переменная var198
	 30857	,1	,1	,&var1786},	//Внутренняя переменная var1786
	 30858	,1	,1	,&var474},	//Внутренняя переменная var474
	 30859	,8	,1	,&var1686},	//Внутренняя переменная var1686
	 30860	,1	,1	,&var408},	//Внутренняя переменная var408
	 30861	,1	,1	,&var1021},	//Внутренняя переменная var1021
	 30862	,1	,1	,&var1307},	//Внутренняя переменная var1307
	 30863	,1	,1	,&var1427},	//Внутренняя переменная var1427
	 30864	,1	,1	,&var1617},	//Внутренняя переменная var1617
	 30865	,1	,1	,&var1807},	//Внутренняя переменная var1807
	 30866	,1	,1	,&var1838},	//Внутренняя переменная var1838
	 30867	,1	,1	,&var678},	//Внутренняя переменная var678
	 30868	,1	,1	,&var739},	//Внутренняя переменная var739
	 30869	,1	,1	,&var1003},	//Внутренняя переменная var1003
	 30870	,1	,1	,&var1395},	//Внутренняя переменная var1395
	 30871	,1	,1	,&var1711},	//Внутренняя переменная var1711
	 30872	,1	,1	,&var1735},	//Внутренняя переменная var1735
	 30873	,1	,1	,&var587},	//Внутренняя переменная var587
	 30874	,1	,1	,&var855},	//Внутренняя переменная var855
	 30875	,1	,1	,&var1130},	//Внутренняя переменная var1130
	 30876	,3	,1	,&var1567},	//Внутренняя переменная var1567
	 30877	,1	,1	,&var1815},	//Внутренняя переменная var1815
	 30878	,1	,1	,&var1817},	//Внутренняя переменная var1817
	 30879	,1	,1	,&var228},	//Внутренняя переменная var228
	 30880	,1	,1	,&var823},	//Внутренняя переменная var823
	 30881	,1	,1	,&var1374},	//Внутренняя переменная var1374
	 30882	,1	,1	,&var225},	//Внутренняя переменная var225
	 30883	,1	,1	,&var923},	//Внутренняя переменная var923
	 30884	,1	,1	,&var927},	//Внутренняя переменная var927
	 30885	,1	,1	,&var125},	//Внутренняя переменная var125
	 30886	,1	,1	,&var224},	//Внутренняя переменная var224
	 30887	,1	,1	,&var626},	//Внутренняя переменная var626
	 30888	,1	,1	,&var1113},	//Внутренняя переменная var1113
	 30889	,1	,1	,&var174},	//Внутренняя переменная var174
	 30890	,1	,1	,&var1832},	//Внутренняя переменная var1832
	 30891	,1	,1	,&var756},	//Внутренняя переменная var756
	 30892	,1	,1	,&var1881},	//Внутренняя переменная var1881
	 30893	,1	,1	,&var80},	//Внутренняя переменная var80
	 30894	,1	,1	,&var753},	//Внутренняя переменная var753
	 30895	,1	,1	,&var861},	//Внутренняя переменная var861
	 30896	,1	,1	,&var1570},	//Внутренняя переменная var1570
	 30897	,3	,1	,&var1596},	//Внутренняя переменная var1596
	 30898	,1	,1	,&var1924},	//Внутренняя переменная var1924
	 30899	,1	,1	,&var572},	//Внутренняя переменная var572
	 30900	,1	,1	,&var971},	//Внутренняя переменная var971
	 30901	,1	,1	,&var1138},	//Внутренняя переменная var1138
	 30902	,1	,1	,&var1338},	//Внутренняя переменная var1338
	 30903	,1	,1	,&var1392},	//Внутренняя переменная var1392
	 30904	,1	,1	,&var1962},	//Внутренняя переменная var1962
	 30905	,1	,1	,&var71},	//Внутренняя переменная var71
	 30906	,1	,1	,&var314},	//Внутренняя переменная var314
	 30907	,1	,1	,&var553},	//Внутренняя переменная var553
	 30908	,1	,1	,&var890},	//Внутренняя переменная var890
	 30909	,1	,1	,&var937},	//Внутренняя переменная var937
	 30910	,1	,1	,&var1063},	//Внутренняя переменная var1063
	 30911	,1	,1	,&var677},	//Внутренняя переменная var677
	 30912	,1	,1	,&var1231},	//Внутренняя переменная var1231
	 30913	,1	,1	,&var1482},	//Внутренняя переменная var1482
	 30914	,3	,1	,&var1828},	//Внутренняя переменная var1828
	 30915	,1	,1	,&var70},	//Внутренняя переменная var70
	 30916	,1	,1	,&var491},	//Внутренняя переменная var491
	 30917	,1	,1	,&var637},	//Внутренняя переменная var637
	 30918	,1	,1	,&var658},	//Внутренняя переменная var658
	 30919	,1	,1	,&var684},	//Внутренняя переменная var684
	 30920	,1	,1	,&var1525},	//Внутренняя переменная var1525
	 30921	,1	,1	,&var209},	//Внутренняя переменная var209
	 30922	,1	,1	,&var331},	//Внутренняя переменная var331
	 30923	,1	,1	,&var216},	//Внутренняя переменная var216
	 30924	,1	,1	,&var363},	//Внутренняя переменная var363
	 30925	,1	,1	,&var833},	//Внутренняя переменная var833
	 30926	,1	,1	,&var907},	//Внутренняя переменная var907
	 30927	,1	,1	,&var1383},	//Внутренняя переменная var1383
	 30928	,11	,1	,&vainSLong},	//Внутренняя переменная vainSLong
	 30929	,1	,1	,&var124},	//Внутренняя переменная var124
	 30930	,1	,1	,&var445},	//Внутренняя переменная var445
	 30931	,1	,1	,&var509},	//Внутренняя переменная var509
	 30932	,1	,1	,&var863},	//Внутренняя переменная var863
	 30933	,1	,1	,&var1811},	//Внутренняя переменная var1811
	 30934	,1	,1	,&var1986},	//Внутренняя переменная var1986
	 30935	,1	,1	,&var29},	//Внутренняя переменная var29
	 30936	,1	,1	,&var253},	//Внутренняя переменная var253
	 30937	,1	,1	,&var452},	//Внутренняя переменная var452
	 30938	,1	,1	,&var898},	//Внутренняя переменная var898
	 30939	,1	,1	,&var1794},	//Внутренняя переменная var1794
	 30940	,1	,1	,&var259},	//Внутренняя переменная var259
	 30941	,1	,1	,&var568},	//Внутренняя переменная var568
	 30942	,1	,1	,&var40},	//Внутренняя переменная var40
	 30943	,1	,1	,&var111},	//Внутренняя переменная var111
	 30944	,1	,1	,&var1412},	//Внутренняя переменная var1412
	 30945	,1	,1	,&var1933},	//Внутренняя переменная var1933
	 30946	,1	,1	,&var399},	//Внутренняя переменная var399
	 30947	,1	,1	,&var1594},	//Внутренняя переменная var1594
	 30948	,1	,1	,&var1685},	//Внутренняя переменная var1685
	 30949	,1	,1	,&var24},	//Внутренняя переменная var24
	 30950	,1	,1	,&var517},	//Внутренняя переменная var517
	 30951	,1	,1	,&var549},	//Внутренняя переменная var549
	 30952	,1	,1	,&var599},	//Внутренняя переменная var599
	 30953	,1	,1	,&var1001},	//Внутренняя переменная var1001
	 30954	,1	,1	,&var1355},	//Внутренняя переменная var1355
	 30955	,1	,1	,&var617},	//Внутренняя переменная var617
	 30956	,1	,1	,&var1178},	//Внутренняя переменная var1178
	 30957	,8	,1	,&var1225},	//Внутренняя переменная var1225
	 30958	,1	,1	,&var1283},	//Внутренняя переменная var1283
	 30959	,1	,1	,&var1706},	//Внутренняя переменная var1706
	 30960	,1	,1	,&var306},	//Внутренняя переменная var306
	 30961	,1	,1	,&var455},	//Внутренняя переменная var455
	 30962	,1	,1	,&var508},	//Внутренняя переменная var508
	 30963	,1	,1	,&var642},	//Внутренняя переменная var642
	 30964	,1	,1	,&var827},	//Внутренняя переменная var827
	 30965	,1	,1	,&var1692},	//Внутренняя переменная var1692
	 30966	,1	,1	,&var102},	//Внутренняя переменная var102
	 30967	,1	,1	,&var1076},	//Внутренняя переменная var1076
	 30968	,1	,1	,&var1100},	//Внутренняя переменная var1100
	 30969	,1	,1	,&var1239},	//Внутренняя переменная var1239
	 30970	,11	,1	,&var1295},	//Внутренняя переменная var1295
	 30971	,1	,1	,&var1677},	//Внутренняя переменная var1677
	 30972	,1	,1	,&var294},	//Внутренняя переменная var294
	 30973	,1	,1	,&var472},	//Внутренняя переменная var472
	 30974	,1	,1	,&var765},	//Внутренняя переменная var765
	 30975	,1	,1	,&var1265},	//Внутренняя переменная var1265
	 30976	,1	,1	,&var1399},	//Внутренняя переменная var1399
	 30977	,1	,1	,&var59},	//Внутренняя переменная var59
	 30978	,1	,1	,&var378},	//Внутренняя переменная var378
	 30979	,1	,1	,&var789},	//Внутренняя переменная var789
	 30980	,1	,1	,&var1169},	//Внутренняя переменная var1169
	 30981	,1	,1	,&var1170},	//Внутренняя переменная var1170
	 30982	,1	,1	,&var1211},	//Внутренняя переменная var1211
	 30983	,1	,1	,&var490},	//Внутренняя переменная var490
	 30984	,1	,1	,&var709},	//Внутренняя переменная var709
	 30985	,1	,1	,&var402},	//Внутренняя переменная var402
	 30986	,1	,1	,&var1117},	//Внутренняя переменная var1117
	 30987	,1	,1	,&var1798},	//Внутренняя переменная var1798
	 30988	,1	,1	,&var147},	//Внутренняя переменная var147
	 30989	,1	,1	,&var194},	//Внутренняя переменная var194
	 30990	,1	,1	,&var489},	//Внутренняя переменная var489
	 30991	,1	,1	,&var957},	//Внутренняя переменная var957
	 30992	,1	,1	,&var1430},	//Внутренняя переменная var1430
	 30993	,1	,1	,&var1479},	//Внутренняя переменная var1479
	 30994	,1	,1	,&var214},	//Внутренняя переменная var214
	 30995	,1	,1	,&var267},	//Внутренняя переменная var267
	 30996	,1	,1	,&var1452},	//Внутренняя переменная var1452
	 30997	,8	,1	,&var573},	//Внутренняя переменная var573
	 30998	,1	,1	,&var866},	//Внутренняя переменная var866
	 30999	,1	,1	,&var1264},	//Внутренняя переменная var1264
	 31000	,1	,1	,&var1361},	//Внутренняя переменная var1361
	 31001	,1	,1	,&var75},	//Внутренняя переменная var75
	 31002	,1	,1	,&var1004},	//Внутренняя переменная var1004
	 31003	,1	,1	,&var1325},	//Внутренняя переменная var1325
	 31004	,1	,1	,&var160},	//Внутренняя переменная var160
	 31005	,1	,1	,&var426},	//Внутренняя переменная var426
	 31006	,1	,1	,&var1053},	//Внутренняя переменная var1053
	 31007	,1	,1	,&var1958},	//Внутренняя переменная var1958
	 31008	,1	,1	,&var1114},	//Внутренняя переменная var1114
	 31009	,1	,1	,&var1378},	//Внутренняя переменная var1378
	 31010	,8	,1	,&var1598},	//Внутренняя переменная var1598
	 31011	,1	,1	,&var1697},	//Внутренняя переменная var1697
	 31012	,1	,1	,&var1946},	//Внутренняя переменная var1946
	 31013	,1	,1	,&var808},	//Внутренняя переменная var808
	 31014	,1	,1	,&var994},	//Внутренняя переменная var994
	 31015	,1	,1	,&var1121},	//Внутренняя переменная var1121
	 31016	,1	,1	,&var1367},	//Внутренняя переменная var1367
	 31017	,1	,1	,&var21},	//Внутренняя переменная var21
	 31018	,1	,1	,&var653},	//Внутренняя переменная var653
	 31019	,1	,1	,&var148},	//Внутренняя переменная var148
	 31020	,1	,1	,&var1802},	//Внутренняя переменная var1802
	 31021	,1	,1	,&var458},	//Внутренняя переменная var458
	 31022	,1	,1	,&var824},	//Внутренняя переменная var824
	 31023	,1	,1	,&var1409},	//Внутренняя переменная var1409
	 31024	,1	,1	,&var350},	//Внутренняя переменная var350
	 31025	,1	,1	,&var564},	//Внутренняя переменная var564
	 31026	,1	,1	,&var676},	//Внутренняя переменная var676
	 31027	,1	,1	,&var1417},	//Внутренняя переменная var1417
	 31028	,1	,1	,&var1560},	//Внутренняя переменная var1560
	 31029	,1	,1	,&var1804},	//Внутренняя переменная var1804
	 31030	,1	,1	,&var685},	//Внутренняя переменная var685
	 31031	,1	,1	,&var1554},	//Внутренняя переменная var1554
	 31032	,1	,1	,&var1565},	//Внутренняя переменная var1565
	 31033	,1	,1	,&var925},	//Внутренняя переменная var925
	 31034	,1	,1	,&var1098},	//Внутренняя переменная var1098
	 31035	,1	,1	,&var1717},	//Внутренняя переменная var1717
	 31036	,1	,1	,&var922},	//Внутренняя переменная var922
	 31037	,1	,1	,&var1065},	//Внутренняя переменная var1065
	 31038	,1	,1	,&var10},	//Внутренняя переменная var10
	 31039	,1	,1	,&var26},	//Внутренняя переменная var26
	 31040	,1	,1	,&var346},	//Внутренняя переменная var346
	 31041	,1	,1	,&var361},	//Внутренняя переменная var361
	 31042	,1	,1	,&var365},	//Внутренняя переменная var365
	 31043	,1	,1	,&var567},	//Внутренняя переменная var567
	 31044	,1	,1	,&var1456},	//Внутренняя переменная var1456
	 31045	,1	,1	,&var1354},	//Внутренняя переменная var1354
	 31046	,1	,1	,&var1484},	//Внутренняя переменная var1484
	 31047	,1	,1	,&var1557},	//Внутренняя переменная var1557
	 31048	,1	,1	,&var213},	//Внутренняя переменная var213
	 31049	,1	,1	,&var511},	//Внутренняя переменная var511
	 31050	,1	,1	,&var1266},	//Внутренняя переменная var1266
	 31051	,1	,1	,&var1435},	//Внутренняя переменная var1435
	 31052	,1	,1	,&var1486},	//Внутренняя переменная var1486
	 31053	,1	,1	,&var1635},	//Внутренняя переменная var1635
	 31054	,1	,1	,&var52},	//Внутренняя переменная var52
	 31055	,1	,1	,&var221},	//Внутренняя переменная var221
	 31056	,1	,1	,&var648},	//Внутренняя переменная var648
	 31057	,1	,1	,&var1193},	//Внутренняя переменная var1193
	 31058	,1	,1	,&var217},	//Внутренняя переменная var217
	 31059	,3	,1	,&var1299},	//Внутренняя переменная var1299
	 31060	,1	,1	,&var1312},	//Внутренняя переменная var1312
	 31061	,1	,1	,&var1625},	//Внутренняя переменная var1625
	 31062	,1	,1	,&var146},	//Внутренняя переменная var146
	 31063	,1	,1	,&var512},	//Внутренняя переменная var512
	 31064	,1	,1	,&var633},	//Внутренняя переменная var633
	 31065	,1	,1	,&var875},	//Внутренняя переменная var875
	 31066	,1	,1	,&var1494},	//Внутренняя переменная var1494
	 31067	,8	,1	,&var1217},	//Внутренняя переменная var1217
	 31068	,8	,1	,&var1763},	//Внутренняя переменная var1763
	 31069	,1	,1	,&var1770},	//Внутренняя переменная var1770
	 31070	,1	,1	,&var3},	//Внутренняя переменная var3
	 31071	,1	,1	,&var252},	//Внутренняя переменная var252
	 31072	,1	,1	,&var392},	//Внутренняя переменная var392
	 31073	,1	,1	,&var831},	//Внутренняя переменная var831
	 31074	,1	,1	,&var1467},	//Внутренняя переменная var1467
	 31075	,1	,1	,&var1750},	//Внутренняя переменная var1750
	 31076	,1	,1	,&var591},	//Внутренняя переменная var591
	 31077	,1	,1	,&var767},	//Внутренняя переменная var767
	 31078	,1	,1	,&var887},	//Внутренняя переменная var887
	 31079	,1	,1	,&var1119},	//Внутренняя переменная var1119
	 31080	,1	,1	,&var1190},	//Внутренняя переменная var1190
	 31081	,1	,1	,&var1632},	//Внутренняя переменная var1632
	 31082	,1	,1	,&var1661},	//Внутренняя переменная var1661
	 31083	,1	,1	,&var1111},	//Внутренняя переменная var1111
	 31084	,1	,1	,&var1159},	//Внутренняя переменная var1159
	 31085	,8	,1	,&var1997},	//Внутренняя переменная var1997
	 31086	,1	,1	,&var1531},	//Внутренняя переменная var1531
	 31087	,	,1	,&var1640},	//Внутренняя переменная var1640
	 31088	,8	,1	,&var1719},	//Внутренняя переменная var1719
	 31089	,1	,1	,&var664},	//Внутренняя переменная var664
	 31090	,1	,1	,&var802},	//Внутренняя переменная var802
	 31091	,1	,1	,&var934},	//Внутренняя переменная var934
	 31092	,1	,1	,&var1273},	//Внутренняя переменная var1273
	 31093	,1	,1	,&var1767},	//Внутренняя переменная var1767
	 31094	,1	,1	,&var312},	//Внутренняя переменная var312
	 31095	,1	,1	,&var699},	//Внутренняя переменная var699
	 31096	,1	,1	,&var1165},	//Внутренняя переменная var1165
	 31097	,1	,1	,&var1311},	//Внутренняя переменная var1311
	 31098	,1	,1	,&var1582},	//Внутренняя переменная var1582
	 31099	,8	,1	,&var1639},	//Внутренняя переменная var1639
	 31100	,1	,1	,&var61},	//Внутренняя переменная var61
	 31101	,1	,1	,&var1216},	//Внутренняя переменная var1216
	 31102	,8	,1	,&var1223},	//Внутренняя переменная var1223
	 31103	,1	,1	,&var998},	//Внутренняя переменная var998
	 31104	,1	,1	,&var1181},	//Внутренняя переменная var1181
	 31105	,1	,1	,&var1358},	//Внутренняя переменная var1358
	 31106	,1	,1	,&var1451},	//Внутренняя переменная var1451
	 31107	,1	,1	,&var1660},	//Внутренняя переменная var1660
	 31108	,1	,1	,&var41},	//Внутренняя переменная var41
	 31109	,1	,1	,&var623},	//Внутренняя переменная var623
	 31110	,1	,1	,&var757},	//Внутренняя переменная var757
	 31111	,1	,1	,&var1302},	//Внутренняя переменная var1302
	 31112	,8	,1	,&var1979},	//Внутренняя переменная var1979
	 31113	,1	,1	,&var72},	//Внутренняя переменная var72
	 31114	,1	,1	,&var157},	//Внутренняя переменная var157
	 31115	,1	,1	,&var256},	//Внутренняя переменная var256
	 31116	,1	,1	,&var594},	//Внутренняя переменная var594
	 31117	,1	,1	,&var1773},	//Внутренняя переменная var1773
	 31118	,1	,1	,&var1947},	//Внутренняя переменная var1947
	 31119	,1	,1	,&var1587},	//Внутренняя переменная var1587
	 31120	,1	,1	,&var1036},	//Внутренняя переменная var1036
	 31121	,1	,1	,&var1199},	//Внутренняя переменная var1199
	 31122	,1	,1	,&var1669},	//Внутренняя переменная var1669
	 31123	,1	,1	,&var1689},	//Внутренняя переменная var1689
	 31124	,1	,1	,&var1788},	//Внутренняя переменная var1788
	 31125	,1	,1	,&var166},	//Внутренняя переменная var166
	 31126	,1	,1	,&var596},	//Внутренняя переменная var596
	 31127	,1	,1	,&var619},	//Внутренняя переменная var619
	 31128	,1	,1	,&var655},	//Внутренняя переменная var655
	 31129	,1	,1	,&var1026},	//Внутренняя переменная var1026
	 31130	,1	,1	,&var1272},	//Внутренняя переменная var1272
	 31131	,1	,1	,&var330},	//Внутренняя переменная var330
	 31132	,1	,1	,&var1498},	//Внутренняя переменная var1498
	 31133	,1	,1	,&var1029},	//Внутренняя переменная var1029
	 31134	,1	,1	,&var1795},	//Внутренняя переменная var1795
	 31135	,1	,1	,&var201},	//Внутренняя переменная var201
	 31136	,1	,1	,&var349},	//Внутренняя переменная var349
	 31137	,1	,1	,&var393},	//Внутренняя переменная var393
	 31138	,1	,1	,&var414},	//Внутренняя переменная var414
	 31139	,1	,1	,&var742},	//Внутренняя переменная var742
	 31140	,1	,1	,&var858},	//Внутренняя переменная var858
	 31141	,1	,1	,&var1831},	//Внутренняя переменная var1831
	 31142	,1	,1	,&var288},	//Внутренняя переменная var288
	 31143	,1	,1	,&var1428},	//Внутренняя переменная var1428
	 31144	,1	,1	,&var1796},	//Внутренняя переменная var1796
	 31145	,1	,1	,&var269},	//Внутренняя переменная var269
	 31146	,1	,1	,&var840},	//Внутренняя переменная var840
	 31147	,11	,1	,&var1508},	//Внутренняя переменная var1508
	 31148	,1	,1	,&var202},	//Внутренняя переменная var202
	 31149	,11	,1	,&var803},	//Внутренняя переменная var803
	 31150	,1	,1	,&var1257},	//Внутренняя переменная var1257
	 31151	,1	,1	,&var1753},	//Внутренняя переменная var1753
	 31152	,1	,1	,&var1913},	//Внутренняя переменная var1913
	 31153	,1	,1	,&var133},	//Внутренняя переменная var133
	 31154	,1	,1	,&var320},	//Внутренняя переменная var320
	 31155	,1	,1	,&var979},	//Внутренняя переменная var979
	 31156	,1	,1	,&var1363},	//Внутренняя переменная var1363
	 31157	,3	,1	,&var1629},	//Внутренняя переменная var1629
	 31158	,1	,1	,&var1873},	//Внутренняя переменная var1873
	 31159	,1	,1	,&var1356},	//Внутренняя переменная var1356
	 31160	,1	,1	,&var1129},	//Внутренняя переменная var1129
	 31161	,1	,1	,&var1644},	//Внутренняя переменная var1644
	 31162	,1	,1	,&var1971},	//Внутренняя переменная var1971
	 31163	,1	,1	,&var338},	//Внутренняя переменная var338
	 31164	,1	,1	,&var468},	//Внутренняя переменная var468
	 31165	,1	,1	,&var582},	//Внутренняя переменная var582
	 31166	,	,1	,&var1566},	//Внутренняя переменная var1566
	 31167	,3	,1	,&var1716},	//Внутренняя переменная var1716
	 31168	,1	,1	,&var638},	//Внутренняя переменная var638
	 31169	,1	,1	,&var1319},	//Внутренняя переменная var1319
	 31170	,1	,1	,&var1878},	//Внутренняя переменная var1878
	 31171	,1	,1	,&var176},	//Внутренняя переменная var176
	 31172	,1	,1	,&var919},	//Внутренняя переменная var919
	 31173	,1	,1	,&var1229},	//Внутренняя переменная var1229
	 31174	,1	,1	,&var1263},	//Внутренняя переменная var1263
	 31175	,1	,1	,&var1492},	//Внутренняя переменная var1492
	 31176	,1	,1	,&var1580},	//Внутренняя переменная var1580
	 31177	,1	,1	,&var1576},	//Внутренняя переменная var1576
	 31178	,1	,1	,&var1830},	//Внутренняя переменная var1830
	 31179	,1	,1	,&var1922},	//Внутренняя переменная var1922
	 31180	,1	,1	,&var348},	//Внутренняя переменная var348
	 31181	,1	,1	,&var1518},	//Внутренняя переменная var1518
	 31182	,1	,1	,&var1874},	//Внутренняя переменная var1874
	 31183	,1	,1	,&var1061},	//Внутренняя переменная var1061
	 31184	,1	,1	,&var1373},	//Внутренняя переменная var1373
	 31185	,1	,1	,&var1772},	//Внутренняя переменная var1772
	 31186	,1	,1	,&var310},	//Внутренняя переменная var310
	 31187	,1	,1	,&var836},	//Внутренняя переменная var836
	 31188	,1	,1	,&var1390},	//Внутренняя переменная var1390
	 31189	,1	,1	,&var418},	//Внутренняя переменная var418
	 31190	,1	,1	,&var634},	//Внутренняя переменная var634
	 31191	,1	,1	,&var1097},	//Внутренняя переменная var1097
	 31192	,1	,1	,&var1318},	//Внутренняя переменная var1318
	 31193	,8	,1	,&var1569},	//Внутренняя переменная var1569
	 31194	,1	,1	,&var1824},	//Внутренняя переменная var1824
	 31195	,1	,1	,&var888},	//Внутренняя переменная var888
	 31196	,1	,1	,&var1011},	//Внутренняя переменная var1011
	 31197	,1	,1	,&var1187},	//Внутренняя переменная var1187
	 31198	,1	,1	,&var1348},	//Внутренняя переменная var1348
	 31199	,1	,1	,&var1774},	//Внутренняя переменная var1774
	 31200	,8	,1	,&var1224},	//Внутренняя переменная var1224
	 31201	,1	,1	,&var318},	//Внутренняя переменная var318
	 31202	,1	,1	,&var987},	//Внутренняя переменная var987
	 31203	,1	,1	,&var1167},	//Внутренняя переменная var1167
	 31204	,1	,1	,&var49},	//Внутренняя переменная var49
	 31205	,1	,1	,&var416},	//Внутренняя переменная var416
	 31206	,8	,1	,&var465},	//Внутренняя переменная var465
	 31207	,1	,1	,&var563},	//Внутренняя переменная var563
	 31208	,1	,1	,&var692},	//Внутренняя переменная var692
	 31209	,1	,1	,&var867},	//Внутренняя переменная var867
	 31210	,1	,1	,&var1835},	//Внутренняя переменная var1835
	 31211	,1	,1	,&var4},	//Внутренняя переменная var4
	 31212	,1	,1	,&var55},	//Внутренняя переменная var55
	 31213	,1	,1	,&var769},	//Внутренняя переменная var769
	 31214	,1	,1	,&var993},	//Внутренняя переменная var993
	 31215	,1	,1	,&var50},	//Внутренняя переменная var50
	 31216	,1	,1	,&var1591},	//Внутренняя переменная var1591
	 31217	,1	,1	,&var1752},	//Внутренняя переменная var1752
	 31218	,1	,1	,&var1940},	//Внутренняя переменная var1940
	 31219	,1	,1	,&var1945},	//Внутренняя переменная var1945
	 31220	,1	,1	,&var235},	//Внутренняя переменная var235
	 31221	,1	,1	,&var248},	//Внутренняя переменная var248
	 31222	,1	,1	,&var334},	//Внутренняя переменная var334
	 31223	,1	,1	,&var988},	//Внутренняя переменная var988
	 31224	,1	,1	,&var1806},	//Внутренняя переменная var1806
	 31225	,1	,1	,&var1968},	//Внутренняя переменная var1968
	 31226	,1	,1	,&var715},	//Внутренняя переменная var715
	 31227	,1	,1	,&var951},	//Внутренняя переменная var951
	 31228	,1	,1	,&var961},	//Внутренняя переменная var961
	 31229	,1	,1	,&var1579},	//Внутренняя переменная var1579
	 31230	,8	,1	,&var1678},	//Внутренняя переменная var1678
	 31231	,1	,1	,&var434},	//Внутренняя переменная var434
	 31232	,1	,1	,&var941},	//Внутренняя переменная var941
	 31233	,1	,1	,&var1179},	//Внутренняя переменная var1179
	 31234	,1	,1	,&var1134},	//Внутренняя переменная var1134
	 31235	,1	,1	,&var15},	//Внутренняя переменная var15
	 31236	,1	,1	,&var117},	//Внутренняя переменная var117
	 31237	,1	,1	,&var321},	//Внутренняя переменная var321
	 31238	,1	,1	,&var822},	//Внутренняя переменная var822
	 31239	,1	,1	,&var1469},	//Внутренняя переменная var1469
	 31240	,1	,1	,&var1981},	//Внутренняя переменная var1981
	 31241	,1	,1	,&var264},	//Внутренняя переменная var264
	 31242	,1	,1	,&var958},	//Внутренняя переменная var958
	 31243	,1	,1	,&var1023},	//Внутренняя переменная var1023
	 31244	,1	,1	,&var1949},	//Внутренняя переменная var1949
	 31245	,1	,1	,&var1974},	//Внутренняя переменная var1974
	 31246	,1	,1	,&var344},	//Внутренняя переменная var344
	 31247	,1	,1	,&var383},	//Внутренняя переменная var383
	 31248	,1	,1	,&var949},	//Внутренняя переменная var949
	 31249	,1	,1	,&var1377},	//Внутренняя переменная var1377
	 31250	,1	,1	,&var486},	//Внутренняя переменная var486
	 31251	,1	,1	,&var989},	//Внутренняя переменная var989
	 31252	,1	,1	,&var1059},	//Внутренняя переменная var1059
	 31253	,1	,1	,&var1620},	//Внутренняя переменная var1620
	 31254	,1	,1	,&var1680},	//Внутренняя переменная var1680
	 31255	,1	,1	,&var1702},	//Внутренняя переменная var1702
	 31256	,1	,1	,&var149},	//Внутренняя переменная var149
	 31257	,1	,1	,&var333},	//Внутренняя переменная var333
	 31258	,1	,1	,&var1293},	//Внутренняя переменная var1293
	 31259	,1	,1	,&var1042},	//Внутренняя переменная var1042
	 31260	,1	,1	,&var1054},	//Внутренняя переменная var1054
	 31261	,1	,1	,&var1124},	//Внутренняя переменная var1124
	 31262	,1	,1	,&var1150},	//Внутренняя переменная var1150
	 31263	,1	,1	,&var1423},	//Внутренняя переменная var1423
	 31264	,1	,1	,&var1732},	//Внутренняя переменная var1732
	 31265	,1	,1	,&var497},	//Внутренняя переменная var497
	 31266	,1	,1	,&var629},	//Внутренняя переменная var629
	 31267	,1	,1	,&var1468},	//Внутренняя переменная var1468
	 31268	,1	,1	,&var1516},	//Внутренняя переменная var1516
	 31269	,1	,1	,&var524},	//Внутренняя переменная var524
	 31270	,1	,1	,&var1301},	//Внутренняя переменная var1301
	 31271	,8	,1	,&var1515},	//Внутренняя переменная var1515
	 31272	,1	,1	,&var135},	//Внутренняя переменная var135
	 31273	,1	,1	,&var763},	//Внутренняя переменная var763
	 31274	,3	,1	,&var1511},	//Внутренняя переменная var1511
	 31275	,1	,1	,&var1845},	//Внутренняя переменная var1845
	 31276	,1	,1	,&var2002},	//Внутренняя переменная var2002
	 31277	,1	,1	,&var657},	//Внутренняя переменная var657
	 31278	,1	,1	,&var738},	//Внутренняя переменная var738
	 31279	,1	,1	,&var859},	//Внутренняя переменная var859
	 31280	,1	,1	,&var970},	//Внутренняя переменная var970
	 31281	,1	,1	,&var1552},	//Внутренняя переменная var1552
	 31282	,1	,1	,&var1037},	//Внутренняя переменная var1037
	 31283	,1	,1	,&var1422},	//Внутренняя переменная var1422
	 31284	,3	,1	,&var1855},	//Внутренняя переменная var1855
	 31285	,1	,1	,&var1648},	//Внутренняя переменная var1648
	 31286	,1	,1	,&var1688},	//Внутренняя переменная var1688
	 31287	,1	,1	,&var170},	//Внутренняя переменная var170
	 31288	,1	,1	,&var514},	//Внутренняя переменная var514
	 31289	,1	,1	,&var901},	//Внутренняя переменная var901
	 31290	,1	,1	,&var1177},	//Внутренняя переменная var1177
	 31291	,1	,1	,&var1327},	//Внутренняя переменная var1327
	 31292	,1	,1	,&var1401},	//Внутренняя переменная var1401
	 31293	,1	,1	,&var1016},	//Внутренняя переменная var1016
	 31294	,1	,1	,&var905},	//Внутренняя переменная var905
	 31295	,1	,1	,&var1528},	//Внутренняя переменная var1528
	 31296	,1	,1	,&var1561},	//Внутренняя переменная var1561
	 31297	,1	,1	,&var1851},	//Внутренняя переменная var1851
	 31298	,1	,1	,&var473},	//Внутренняя переменная var473
	 31299	,1	,1	,&var496},	//Внутренняя переменная var496
	 31300	,8	,1	,&var557},	//Внутренняя переменная var557
	 31301	,1	,1	,&var819},	//Внутренняя переменная var819
	 31302	,1	,1	,&var986},	//Внутренняя переменная var986
	 31303	,1	,1	,&var1323},	//Внутренняя переменная var1323
	 31304	,8	,1	,&var1513},	//Внутренняя переменная var1513
	 31305	,1	,1	,&var246},	//Внутренняя переменная var246
	 31306	,1	,1	,&var560},	//Внутренняя переменная var560
	 31307	,1	,1	,&var1542},	//Внутренняя переменная var1542
	 31308	,1	,1	,&vainSBool},	//Внутренняя переменная vainSBool
	 31309	,1	,1	,&var377},	//Внутренняя переменная var377
	 31310	,1	,1	,&var1671},	//Внутренняя переменная var1671
	 31311	,1	,1	,&var652},	//Внутренняя переменная var652
	 31312	,1	,1	,&var1246},	//Внутренняя переменная var1246
	 31313	,1	,1	,&var301},	//Внутренняя переменная var301
	 31314	,1	,1	,&var370},	//Внутренняя переменная var370
	 31315	,1	,1	,&var1243},	//Внутренняя переменная var1243
	 31316	,1	,1	,&var1249},	//Внутренняя переменная var1249
	 31317	,1	,1	,&var1290},	//Внутренняя переменная var1290
	 31318	,1	,1	,&var1360},	//Внутренняя переменная var1360
	 31319	,1	,1	,&var270},	//Внутренняя переменная var270
	 31320	,1	,1	,&var470},	//Внутренняя переменная var470
	 31321	,1	,1	,&var1611},	//Внутренняя переменная var1611
	 31322	,1	,1	,&var712},	//Внутренняя переменная var712
	 31323	,1	,1	,&var707},	//Внутренняя переменная var707
	 31324	,1	,1	,&var716},	//Внутренняя переменная var716
	 31325	,1	,1	,&var818},	//Внутренняя переменная var818
	 31326	,1	,1	,&var926},	//Внутренняя переменная var926
	 31327	,1	,1	,&var1909},	//Внутренняя переменная var1909
	 31328	,1	,1	,&var1018},	//Внутренняя переменная var1018
	 31329	,1	,1	,&var18},	//Внутренняя переменная var18
	 31330	,1	,1	,&var359},	//Внутренняя переменная var359
	 31331	,1	,1	,&var1045},	//Внутренняя переменная var1045
	 31332	,1	,1	,&var1397},	//Внутренняя переменная var1397
	 31333	,1	,1	,&var1857},	//Внутренняя переменная var1857
	 31334	,1	,1	,&var112},	//Внутренняя переменная var112
	 31335	,1	,1	,&var1052},	//Внутренняя переменная var1052
	 31336	,1	,1	,&var1141},	//Внутренняя переменная var1141
	 31337	,1	,1	,&var1303},	//Внутренняя переменная var1303
	 31338	,1	,1	,&var1573},	//Внутренняя переменная var1573
	 31339	,1	,1	,&var1096},	//Внутренняя переменная var1096
	 31340	,1	,1	,&var1411},	//Внутренняя переменная var1411
	 31341	,8	,1	,&var1551},	//Внутренняя переменная var1551
	 31342	,1	,1	,&var1684},	//Внутренняя переменная var1684
	 31343	,1	,1	,&var1075},	//Внутренняя переменная var1075
	 31344	,1	,1	,&var1258},	//Внутренняя переменная var1258
	 31345	,1	,1	,&var1476},	//Внутренняя переменная var1476
	 31346	,1	,1	,&var1517},	//Внутренняя переменная var1517
	 31347	,	,1	,&var1607},	//Внутренняя переменная var1607
	 31348	,1	,1	,&var1},	//Внутренняя переменная var1
	 31349	,1	,1	,&var2},	//Внутренняя переменная var2
	 31350	,1	,1	,&var279},	//Внутренняя переменная var279
	 31351	,1	,1	,&var1610},	//Внутренняя переменная var1610
	 31352	,1	,1	,&var1897},	//Внутренняя переменная var1897
	 31353	,1	,1	,&var195},	//Внутренняя переменная var195
	 31354	,1	,1	,&var616},	//Внутренняя переменная var616
	 31355	,3	,1	,&var1593},	//Внутренняя переменная var1593
	 31356	,1	,1	,&var1695},	//Внутренняя переменная var1695
	 31357	,1	,1	,&var1950},	//Внутренняя переменная var1950
	 31358	,1	,1	,&var1116},	//Внутренняя переменная var1116
	 31359	,1	,1	,&var1152},	//Внутренняя переменная var1152
	 31360	,1	,1	,&var1875},	//Внутренняя переменная var1875
	 31361	,8	,1	,&var462},	//Внутренняя переменная var462
	 31362	,1	,1	,&var588},	//Внутренняя переменная var588
	 31363	,1	,1	,&var1465},	//Внутренняя переменная var1465
	 31364	,1	,1	,&var1667},	//Внутренняя переменная var1667
	 31365	,1	,1	,&var484},	//Внутренняя переменная var484
	 31366	,1	,1	,&var1040},	//Внутренняя переменная var1040
	 31367	,1	,1	,&var1115},	//Внутренняя переменная var1115
	 31368	,1	,1	,&var1634},	//Внутренняя переменная var1634
	 31369	,1	,1	,&var1694},	//Внутренняя переменная var1694
	 31370	,1	,1	,&var1960},	//Внутренняя переменная var1960
	 31371	,1	,1	,&var121},	//Внутренняя переменная var121
	 31372	,1	,1	,&var542},	//Внутренняя переменная var542
	 31373	,11	,1	,&var1350},	//Внутренняя переменная var1350
	 31374	,1	,1	,&var188},	//Внутренняя переменная var188
	 31375	,1	,1	,&var376},	//Внутренняя переменная var376
	 31376	,1	,1	,&var734},	//Внутренняя переменная var734
	 31377	,1	,1	,&var1703},	//Внутренняя переменная var1703
	 31378	,1	,1	,&var1930},	//Внутренняя переменная var1930
	 31379	,1	,1	,&var780},	//Внутренняя переменная var780
	 31380	,1	,1	,&var1081},	//Внутренняя переменная var1081
	 31381	,1	,1	,&var144},	//Внутренняя переменная var144
	 31382	,1	,1	,&var618},	//Внутренняя переменная var618
	 31383	,1	,1	,&var1758},	//Внутренняя переменная var1758
	 31384	,1	,1	,&var353},	//Внутренняя переменная var353
	 31385	,1	,1	,&var997},	//Внутренняя переменная var997
	 31386	,1	,1	,&var1965},	//Внутренняя переменная var1965
	 31387	,1	,1	,&var69},	//Внутренняя переменная var69
	 31388	,1	,1	,&var81},	//Внутренняя переменная var81
	 31389	,1	,1	,&var226},	//Внутренняя переменная var226
	 31390	,1	,1	,&var528},	//Внутренняя переменная var528
	 31391	,1	,1	,&var552},	//Внутренняя переменная var552
	 31392	,1	,1	,&var1176},	//Внутренняя переменная var1176
	 31393	,1	,1	,&var287},	//Внутренняя переменная var287
	 31394	,1	,1	,&var915},	//Внутренняя переменная var915
	 31395	,1	,1	,&var981},	//Внутренняя переменная var981
	 31396	,1	,1	,&var1110},	//Внутренняя переменная var1110
	 31397	,1	,1	,&var1860},	//Внутренняя переменная var1860
	 31398	,1	,1	,&var92},	//Внутренняя переменная var92
	 31399	,1	,1	,&var138},	//Внутренняя переменная var138
	 31400	,1	,1	,&var1530},	//Внутренняя переменная var1530
	 31401	,1	,1	,&var438},	//Внутренняя переменная var438
	 31402	,1	,1	,&var645},	//Внутренняя переменная var645
	 31403	,1	,1	,&var1718},	//Внутренняя переменная var1718
	 31404	,1	,1	,&var1200},	//Внутренняя переменная var1200
	 31405	,1	,1	,&var1990},	//Внутренняя переменная var1990
	 31406	,1	,1	,&var85},	//Внутренняя переменная var85
	 31407	,1	,1	,&var136},	//Внутренняя переменная var136
	 31408	,1	,1	,&var196},	//Внутренняя переменная var196
	 31409	,1	,1	,&var307},	//Внутренняя переменная var307
	 31410	,1	,1	,&var405},	//Внутренняя переменная var405
	 31411	,1	,1	,&var533},	//Внутренняя переменная var533
	 31412	,8	,1	,&var460},	//Внутренняя переменная var460
	 31413	,1	,1	,&var775},	//Внутренняя переменная var775
	 31414	,1	,1	,&var1398},	//Внутренняя переменная var1398
	 31415	,1	,1	,&var1549},	//Внутренняя переменная var1549
	 31416	,1	,1	,&var1662},	//Внутренняя переменная var1662
	 31417	,3	,1	,&var1309},	//Внутренняя переменная var1309
	 31418	,1	,1	,&var1522},	//Внутренняя переменная var1522
	 31419	,1	,1	,&var1744},	//Внутренняя переменная var1744
	 31420	,1	,1	,&var476},	//Внутренняя переменная var476
	 31421	,1	,1	,&var610},	//Внутренняя переменная var610
	 31422	,1	,1	,&var978},	//Внутренняя переменная var978
	 31423	,1	,1	,&var356},	//Внутренняя переменная var356
	 31424	,1	,1	,&var580},	//Внутренняя переменная var580
	 31425	,1	,1	,&var814},	//Внутренняя переменная var814
	 31426	,1	,1	,&var1778},	//Внутренняя переменная var1778
	 31427	,1	,1	,&var11},	//Внутренняя переменная var11
	 31428	,1	,1	,&var518},	//Внутренняя переменная var518
	 31429	,1	,1	,&var782},	//Внутренняя переменная var782
	 31430	,1	,1	,&var959},	//Внутренняя переменная var959
	 31431	,1	,1	,&var1043},	//Внутренняя переменная var1043
	 31432	,	,1	,&var1595},	//Внутренняя переменная var1595
	 31433	,1	,1	,&var1883},	//Внутренняя переменная var1883
	 31434	,1	,1	,&var386},	//Внутренняя переменная var386
	 31435	,1	,1	,&var991},	//Внутренняя переменная var991
	 31436	,1	,1	,&var1069},	//Внутренняя переменная var1069
	 31437	,1	,1	,&var1194},	//Внутренняя переменная var1194
	 31438	,1	,1	,&var1701},	//Внутренняя переменная var1701
	 31439	,1	,1	,&var1880},	//Внутренняя переменная var1880
	 31440	,1	,1	,&var1089},	//Внутренняя переменная var1089
	 31441	,1	,1	,&var1472},	//Внутренняя переменная var1472
	 31442	,1	,1	,&var1488},	//Внутренняя переменная var1488
	 31443	,1	,1	,&var273},	//Внутренняя переменная var273
	 31444	,1	,1	,&var896},	//Внутренняя переменная var896
	 31445	,1	,1	,&var967},	//Внутренняя переменная var967
	 31446	,1	,1	,&var1252},	//Внутренняя переменная var1252
	 31447	,1	,1	,&var1825},	//Внутренняя переменная var1825
	 31448	,1	,1	,&var1841},	//Внутренняя переменная var1841
	 31449	,1	,1	,&var1943},	//Внутренняя переменная var1943
	 31450	,1	,1	,&var131},	//Внутренняя переменная var131
	 31451	,1	,1	,&var420},	//Внутренняя переменная var420
	 31452	,1	,1	,&var448},	//Внутренняя переменная var448
	 31453	,1	,1	,&var482},	//Внутренняя переменная var482
	 31454	,1	,1	,&var525},	//Внутренняя переменная var525
	 31455	,1	,1	,&var697},	//Внутренняя переменная var697
	 31456	,1	,1	,&var444},	//Внутренняя переменная var444
	 31457	,1	,1	,&var885},	//Внутренняя переменная var885
	 31458	,1	,1	,&var522},	//Внутренняя переменная var522
	 31459	,1	,1	,&var622},	//Внутренняя переменная var622
	 31460	,1	,1	,&var857},	//Внутренняя переменная var857
	 31461	,1	,1	,&var893},	//Внутренняя переменная var893
	 31462	,1	,1	,&var1268},	//Внутренняя переменная var1268
	 31463	,1	,1	,&var1544},	//Внутренняя переменная var1544
	 31464	,1	,1	,&var1407},	//Внутренняя переменная var1407
	 31465	,1	,1	,&var1421},	//Внутренняя переменная var1421
	 31466	,1	,1	,&var1645},	//Внутренняя переменная var1645
	 31467	,	,1	,&var1709},	//Внутренняя переменная var1709
	 31468	,1	,1	,&var223},	//Внутренняя переменная var223
	 31469	,1	,1	,&var1371},	//Внутренняя переменная var1371
	 31470	,1	,1	,&var1433},	//Внутренняя переменная var1433
	 31471	,8	,1	,&var1631},	//Внутренняя переменная var1631
	 31472	,8	,1	,&var1916},	//Внутренняя переменная var1916
	 31473	,1	,1	,&var78},	//Внутренняя переменная var78
	 31474	,1	,1	,&var487},	//Внутренняя переменная var487
	 31475	,1	,1	,&var630},	//Внутренняя переменная var630
	 31476	,3	,1	,&var1673},	//Внутренняя переменная var1673
	 31477	,1	,1	,&var1771},	//Внутренняя переменная var1771
	 31478	,1	,1	,&var656},	//Внутренняя переменная var656
	 31479	,1	,1	,&var748},	//Внутренняя переменная var748
	 31480	,1	,1	,&var1105},	//Внутренняя переменная var1105
	 31481	,1	,1	,&var1903},	//Внутренняя переменная var1903
	 31482	,1	,1	,&var956},	//Внутренняя переменная var956
	 31483	,1	,1	,&var297},	//Внутренняя переменная var297
	 31484	,1	,1	,&var309},	//Внутренняя переменная var309
	 31485	,1	,1	,&var1321},	//Внутренняя переменная var1321
	 31486	,1	,1	,&var1483},	//Внутренняя переменная var1483
	 31487	,1	,1	,&var2000},	//Внутренняя переменная var2000
	 31488	,1	,1	,&var1912},	//Внутренняя переменная var1912
	 31489	,1	,1	,&var1959},	//Внутренняя переменная var1959
	 31490	,1	,1	,&var169},	//Внутренняя переменная var169
	 31491	,1	,1	,&var292},	//Внутренняя переменная var292
	 31492	,1	,1	,&var506},	//Внутренняя переменная var506
	 31493	,1	,1	,&var607},	//Внутренняя переменная var607
	 31494	,1	,1	,&var884},	//Внутренняя переменная var884
	 31495	,1	,1	,&var1158},	//Внутренняя переменная var1158
	 31496	,1	,1	,&var773},	//Внутренняя переменная var773
	 31497	,1	,1	,&var1271},	//Внутренняя переменная var1271
	 31498	,1	,1	,&var1487},	//Внутренняя переменная var1487
	 31499	,8	,1	,&var1514},	//Внутренняя переменная var1514
	 31500	,1	,1	,&var250},	//Внутренняя переменная var250
	 31501	,1	,1	,&var261},	//Внутренняя переменная var261
	 31502	,1	,1	,&var87},	//Внутренняя переменная var87
	 31503	,1	,1	,&var215},	//Внутренняя переменная var215
	 31504	,1	,1	,&var1292},	//Внутренняя переменная var1292
	 31505	,1	,1	,&var943},	//Внутренняя переменная var943
	 31506	,1	,1	,&var1869},	//Внутренняя переменная var1869
	 31507	,1	,1	,&var278},	//Внутренняя переменная var278
	 31508	,1	,1	,&var1082},	//Внутренняя переменная var1082
	 31509	,1	,1	,&var1650},	//Внутренняя переменная var1650
	 31510	,1	,1	,&var1659},	//Внутренняя переменная var1659
	 31511	,1	,1	,&var319},	//Внутренняя переменная var319
	 31512	,1	,1	,&var471},	//Внутренняя переменная var471
	 31513	,1	,1	,&var641},	//Внутренняя переменная var641
	 31514	,1	,1	,&var1512},	//Внутренняя переменная var1512
	 31515	,1	,1	,&var1776},	//Внутренняя переменная var1776
	 31516	,1	,1	,&var813},	//Внутренняя переменная var813
	 31517	,1	,1	,&var830},	//Внутренняя переменная var830
	 31518	,1	,1	,&var480},	//Внутренняя переменная var480
	 31519	,1	,1	,&var650},	//Внутренняя переменная var650
	 31520	,1	,1	,&var752},	//Внутренняя переменная var752
	 31521	,1	,1	,&var1279},	//Внутренняя переменная var1279
	 31522	,1	,1	,&var1000},	//Внутренняя переменная var1000
	 31523	,1	,1	,&var1589},	//Внутренняя переменная var1589
	 31524	,1	,1	,&var1548},	//Внутренняя переменная var1548
	 31525	,1	,1	,&var8},	//Внутренняя переменная var8
	 31526	,1	,1	,&var206},	//Внутренняя переменная var206
	 31527	,1	,1	,&var437},	//Внутренняя переменная var437
	 31528	,1	,1	,&var1416},	//Внутренняя переменная var1416
	 31529	,1	,1	,&var151},	//Внутренняя переменная var151
	 31530	,1	,1	,&var1058},	//Внутренняя переменная var1058
	 31531	,1	,1	,&var1090},	//Внутренняя переменная var1090
	 31532	,1	,1	,&var1250},	//Внутренняя переменная var1250
	 31533	,1	,1	,&var1289},	//Внутренняя переменная var1289
	 31534	,1	,1	,&var218},	//Внутренняя переменная var218
	 31535	,8	,1	,&var659},	//Внутренняя переменная var659
	 31536	,1	,1	,&var772},	//Внутренняя переменная var772
	 31537	,1	,1	,&var1034},	//Внутренняя переменная var1034
	 31538	,1	,1	,&var91},	//Внутренняя переменная var91
	 31539	,1	,1	,&var980},	//Внутренняя переменная var980
	 31540	,1	,1	,&var1064},	//Внутренняя переменная var1064
	 31541	,1	,1	,&var1206},	//Внутренняя переменная var1206
	 31542	,1	,1	,&var1972},	//Внутренняя переменная var1972
	 31543	,1	,1	,&var1834},	//Внутренняя переменная var1834
	 31544	,1	,1	,&var27},	//Внутренняя переменная var27
	 31545	,1	,1	,&var34},	//Внутренняя переменная var34
	 31546	,1	,1	,&var122},	//Внутренняя переменная var122
	 31547	,1	,1	,&var1112},	//Внутренняя переменная var1112
	 31548	,	,1	,&var1534},	//Внутренняя переменная var1534
	 31549	,1	,1	,&var1581},	//Внутренняя переменная var1581
	 31550	,3	,1	,&var1564},	//Внутренняя переменная var1564
	 31551	,1	,1	,&var1844},	//Внутренняя переменная var1844
	 31552	,1	,1	,&var234},	//Внутренняя переменная var234
	 31553	,1	,1	,&var424},	//Внутренняя переменная var424
	 31554	,1	,1	,&var529},	//Внутренняя переменная var529
	 31555	,1	,1	,&var778},	//Внутренняя переменная var778
	 31556	,1	,1	,&var1185},	//Внутренняя переменная var1185
	 31557	,1	,1	,&var1403},	//Внутренняя переменная var1403
	 31558	,1	,1	,&var1102},	//Внутренняя переменная var1102
	 31559	,3	,1	,&var1532},	//Внутренняя переменная var1532
	 31560	,1	,1	,&var1622},	//Внутренняя переменная var1622
	 31561	,1	,1	,&var1879},	//Внутренняя переменная var1879
	 31562	,1	,1	,&var812},	//Внутренняя переменная var812
	 31563	,1	,1	,&var900},	//Внутренняя переменная var900
	 31564	,1	,1	,&var1244},	//Внутренняя переменная var1244
	 31565	,1	,1	,&var740},	//Внутренняя переменная var740
	 31566	,1	,1	,&var976},	//Внутренняя переменная var976
	 31567	,1	,1	,&var2004},	//Внутренняя переменная var2004
	 31568	,1	,1	,&var175},	//Внутренняя переменная var175
	 31569	,1	,1	,&var200},	//Внутренняя переменная var200
	 31570	,1	,1	,&var722},	//Внутренняя переменная var722
	 31571	,1	,1	,&var1429},	//Внутренняя переменная var1429
	 31572	,1	,1	,&var313},	//Внутренняя переменная var313
	 31573	,1	,1	,&var713},	//Внутренняя переменная var713
	 31574	,1	,1	,&var995},	//Внутренняя переменная var995
	 31575	,1	,1	,&var1568},	//Внутренняя переменная var1568
	 31576	,1	,1	,&var1859},	//Внутренняя переменная var1859
	 31577	,1	,1	,&var23},	//Внутренняя переменная var23
	 31578	,1	,1	,&var966},	//Внутренняя переменная var966
	 31579	,3	,1	,&var1535},	//Внутренняя переменная var1535
	 31580	,1	,1	,&var869},	//Внутренняя переменная var869
	 31581	,1	,1	,&var1453},	//Внутренняя переменная var1453
	 31582	,1	,1	,&var1967},	//Внутренняя переменная var1967
	 31583	,1	,1	,&var1592},	//Внутренняя переменная var1592
	 31584	,1	,1	,&var1260},	//Внутренняя переменная var1260
	 31585	,1	,1	,&var1262},	//Внутренняя переменная var1262
	 31586	,1	,1	,&var1387},	//Внутренняя переменная var1387
	 31587	,1	,1	,&var1955},	//Внутренняя переменная var1955
	 31588	,1	,1	,&var345},	//Внутренняя переменная var345
	 31589	,1	,1	,&var603},	//Внутренняя переменная var603
	 31590	,1	,1	,&var635},	//Внутренняя переменная var635
	 31591	,1	,1	,&var1666},	//Внутренняя переменная var1666
	 31592	,	,1	,&var1675},	//Внутренняя переменная var1675
	 31593	,1	,1	,&var990},	//Внутренняя переменная var990
	 31594	,1	,1	,&var1162},	//Внутренняя переменная var1162
	 31595	,1	,1	,&var39},	//Внутренняя переменная var39
	 31596	,1	,1	,&var165},	//Внутренняя переменная var165
	 31597	,1	,1	,&var291},	//Внутренняя переменная var291
	 31598	,1	,1	,&var352},	//Внутренняя переменная var352
	 31599	,1	,1	,&var694},	//Внутренняя переменная var694
	 31600	,1	,1	,&var984},	//Внутренняя переменная var984
	 31601	,1	,1	,&var1372},	//Внутренняя переменная var1372
	 31602	,3	,1	,&var1665},	//Внутренняя переменная var1665
	 31603	,1	,1	,&var89},	//Внутренняя переменная var89
	 31604	,1	,1	,&var515},	//Внутренняя переменная var515
	 31605	,1	,1	,&var621},	//Внутренняя переменная var621
	 31606	,1	,1	,&var849},	//Внутренняя переменная var849
	 31607	,1	,1	,&var929},	//Внутренняя переменная var929
	 31608	,1	,1	,&var1921},	//Внутренняя переменная var1921
	 31609	,1	,1	,&var737},	//Внутренняя переменная var737
	 31610	,	,1	,&var1728},	//Внутренняя переменная var1728
	 31611	,1	,1	,&var1840},	//Внутренняя переменная var1840
	 31612	,1	,1	,&var93},	//Внутренняя переменная var93
	 31613	,1	,1	,&var186},	//Внутренняя переменная var186
	 31614	,1	,1	,&var535},	//Внутренняя переменная var535
	 31615	,1	,1	,&var708},	//Внутренняя переменная var708
	 31616	,1	,1	,&var973},	//Внутренняя переменная var973
	 31617	,1	,1	,&var1342},	//Внутренняя переменная var1342
	 31618	,1	,1	,&var54},	//Внутренняя переменная var54
	 31619	,1	,1	,&var796},	//Внутренняя переменная var796
	 31620	,1	,1	,&var1382},	//Внутренняя переменная var1382
	 31621	,1	,1	,&var407},	//Внутренняя переменная var407
	 31622	,1	,1	,&var425},	//Внутренняя переменная var425
	 31623	,1	,1	,&var1071},	//Внутренняя переменная var1071
	 31624	,1	,1	,&var328},	//Внутренняя переменная var328
	 31625	,1	,1	,&var864},	//Внутренняя переменная var864
	 31626	,1	,1	,&var1253},	//Внутренняя переменная var1253
	 31627	,1	,1	,&var1674},	//Внутренняя переменная var1674
	 31628	,1	,1	,&var421},	//Внутренняя переменная var421
	 31629	,1	,1	,&var952},	//Внутренняя переменная var952
	 31630	,1	,1	,&var1232},	//Внутренняя переменная var1232
	 31631	,3	,1	,&var1837},	//Внутренняя переменная var1837
	 31632	,1	,1	,&var1852},	//Внутренняя переменная var1852
	 31633	,1	,1	,&var192},	//Внутренняя переменная var192
	 31634	,1	,1	,&var1035},	//Внутренняя переменная var1035
	 31635	,1	,1	,&var1585},	//Внутренняя переменная var1585
	 31636	,1	,1	,&var374},	//Внутренняя переменная var374
	 31637	,1	,1	,&var428},	//Внутренняя переменная var428
	 31638	,1	,1	,&var1812},	//Внутренняя переменная var1812
	 31639	,1	,1	,&var1447},	//Внутренняя переменная var1447
	 31640	,1	,1	,&var2003},	//Внутренняя переменная var2003
	 31641	,1	,1	,&var62},	//Внутренняя переменная var62
	 31642	,1	,1	,&var181},	//Внутренняя переменная var181
	 31643	,1	,1	,&var1708},	//Внутренняя переменная var1708
	 31644	,1	,1	,&var56},	//Внутренняя переменная var56
	 31645	,1	,1	,&var768},	//Внутренняя переменная var768
	 31646	,1	,1	,&var811},	//Внутренняя переменная var811
	 31647	,1	,1	,&var1385},	//Внутренняя переменная var1385
	 31648	,1	,1	,&var1388},	//Внутренняя переменная var1388
	 31649	,1	,1	,&var280},	//Внутренняя переменная var280
	 31650	,1	,1	,&var282},	//Внутренняя переменная var282
	 31651	,1	,1	,&var728},	//Внутренняя переменная var728
	 31652	,1	,1	,&var800},	//Внутренняя переменная var800
	 31653	,1	,1	,&var1527},	//Внутренняя переменная var1527
	 31654	,1	,1	,&var1633},	//Внутренняя переменная var1633
	 31655	,1	,1	,&var286},	//Внутренняя переменная var286
	 31656	,1	,1	,&var446},	//Внутренняя переменная var446
	 31657	,1	,1	,&var605},	//Внутренняя переменная var605
	 31658	,1	,1	,&var1118},	//Внутренняя переменная var1118
	 31659	,1	,1	,&var1777},	//Внутренняя переменная var1777
	 31660	,1	,1	,&var1934},	//Внутренняя переменная var1934
	 31661	,8	,1	,&var464},	//Внутренняя переменная var464
	 31662	,1	,1	,&var853},	//Внутренняя переменная var853
	 31663	,1	,1	,&var860},	//Внутренняя переменная var860
	 31664	,1	,1	,&var1341},	//Внутренняя переменная var1341
	 31665	,1	,1	,&var1820},	//Внутренняя переменная var1820
	 31666	,1	,1	,&var1915},	//Внутренняя переменная var1915
	 31667	,1	,1	,&var719},	//Внутренняя переменная var719
	 31668	,1	,1	,&var1441},	//Внутренняя переменная var1441
	 31669	,1	,1	,&var1442},	//Внутренняя переменная var1442
	 31670	,1	,1	,&var94},	//Внутренняя переменная var94
	 31671	,1	,1	,&var245},	//Внутренняя переменная var245
	 31672	,1	,1	,&var1041},	//Внутренняя переменная var1041
	 31673	,1	,1	,&var1174},	//Внутренняя переменная var1174
	 31674	,3	,1	,&var1712},	//Внутренняя переменная var1712
	 31675	,1	,1	,&var327},	//Внутренняя переменная var327
	 31676	,8	,1	,&var1746},	//Внутренняя переменная var1746
	 31677	,1	,1	,&var60},	//Внутренняя переменная var60
	 31678	,1	,1	,&var1146},	//Внутренняя переменная var1146
	 31679	,1	,1	,&var1458},	//Внутренняя переменная var1458
	 31680	,1	,1	,&var1691},	//Внутренняя переменная var1691
	 31681	,1	,1	,&var1764},	//Внутренняя переменная var1764
	 31682	,1	,1	,&var65},	//Внутренняя переменная var65
	 31683	,1	,1	,&var453},	//Внутренняя переменная var453
	 31684	,1	,1	,&var816},	//Внутренняя переменная var816
	 31685	,1	,1	,&var1230},	//Внутренняя переменная var1230
	 31686	,1	,1	,&var1464},	//Внутренняя переменная var1464
	 31687	,1	,1	,&var1605},	//Внутренняя переменная var1605
	 31688	,8	,1	,&var461},	//Внутренняя переменная var461
	 31689	,8	,1	,&var561},	//Внутренняя переменная var561
	 31690	,1	,1	,&var1413},	//Внутренняя переменная var1413
	 31691	,1	,1	,&var1651},	//Внутренняя переменная var1651
	 31692	,1	,1	,&var537},	//Внутренняя переменная var537
	 31693	,1	,1	,&var894},	//Внутренняя переменная var894
	 31694	,1	,1	,&var1070},	//Внутренняя переменная var1070
	 31695	,1	,1	,&var1083},	//Внутренняя переменная var1083
	 31696	,1	,1	,&var1248},	//Внутренняя переменная var1248
	 31697	,3	,1	,&var1310},	//Внутренняя переменная var1310
	 31698	,	,1	,&var1714},	//Внутренняя переменная var1714
	 31699	,1	,1	,&var955},	//Внутренняя переменная var955
	 31700	,1	,1	,&var1256},	//Внутренняя переменная var1256
	 31701	,1	,1	,&var1490},	//Внутренняя переменная var1490
	 31702	,1	,1	,&var1655},	//Внутренняя переменная var1655
	 31703	,1	,1	,&var1730},	//Внутренняя переменная var1730
	 31704	,1	,1	,&var546},	//Внутренняя переменная var546
	 31705	,8	,1	,&var1606},	//Внутренняя переменная var1606
	 31706	,1	,1	,&var1641},	//Внутренняя переменная var1641
	 31707	,1	,1	,&var1013},	//Внутренняя переменная var1013
	 31708	,1	,1	,&var495},	//Внутренняя переменная var495
	 31709	,1	,1	,&var1963},	//Внутренняя переменная var1963
	 31710	,1	,1	,&var390},	//Внутренняя переменная var390
	 31711	,1	,1	,&var1189},	//Внутренняя переменная var1189
	 31712	,1	,1	,&var1775},	//Внутренняя переменная var1775
	 31713	,1	,1	,&var562},	//Внутренняя переменная var562
	 31714	,8	,1	,&var663},	//Внутренняя переменная var663
	 31715	,8	,1	,&var673},	//Внутренняя переменная var673
	 31716	,1	,1	,&var950},	//Внутренняя переменная var950
	 31717	,1	,1	,&var1306},	//Внутренняя переменная var1306
	 31718	,1	,1	,&var1072},	//Внутренняя переменная var1072
	 31719	,1	,1	,&var1188},	//Внутренняя переменная var1188
	 31720	,1	,1	,&var1736},	//Внутренняя переменная var1736
	 31721	,1	,1	,&var883},	//Внутренняя переменная var883
	 31722	,3	,1	,&var1389},	//Внутренняя переменная var1389
	 31723	,1	,1	,&var1809},	//Внутренняя переменная var1809
	 31724	,1	,1	,&var1849},	//Внутренняя переменная var1849
	 31725	,1	,1	,&var1894},	//Внутренняя переменная var1894
	 31726	,1	,1	,&var119},	//Внутренняя переменная var119
	 31727	,1	,1	,&var210},	//Внутренняя переменная var210
	 31728	,1	,1	,&var299},	//Внутренняя переменная var299
	 31729	,1	,1	,&var1203},	//Внутренняя переменная var1203
	 31730	,1	,1	,&var9},	//Внутренняя переменная var9
	 31731	,1	,1	,&var222},	//Внутренняя переменная var222
	 31732	,1	,1	,&var373},	//Внутренняя переменная var373
	 31733	,1	,1	,&var747},	//Внутренняя переменная var747
	 31734	,1	,1	,&var870},	//Внутренняя переменная var870
	 31735	,1	,1	,&var1332},	//Внутренняя переменная var1332
	 31736	,1	,1	,&var651},	//Внутренняя переменная var651
	 31737	,1	,1	,&var793},	//Внутренняя переменная var793
	 31738	,1	,1	,&var1047},	//Внутренняя переменная var1047
	 31739	,8	,1	,&var1213},	//Внутренняя переменная var1213
	 31740	,1	,1	,&var277},	//Внутренняя переменная var277
	 31741	,1	,1	,&var295},	//Внутренняя переменная var295
	 31742	,1	,1	,&var744},	//Внутренняя переменная var744
	 31743	,1	,1	,&var1623},	//Внутренняя переменная var1623
	 31744	,1	,1	,&var1887},	//Внутренняя переменная var1887
	 31745	,8	,1	,&var1994},	//Внутренняя переменная var1994
	 31746	,1	,1	,&var1344},	//Внутренняя переменная var1344
	 31747	,1	,1	,&var1457},	//Внутренняя переменная var1457
	 31748	,1	,1	,&var156},	//Внутренняя переменная var156
	 31749	,1	,1	,&var308},	//Внутренняя переменная var308
	 31750	,1	,1	,&var1649},	//Внутренняя переменная var1649
	 31751	,1	,1	,&var686},	//Внутренняя переменная var686
	 31752	,1	,1	,&var794},	//Внутренняя переменная var794
	 31753	,1	,1	,&var948},	//Внутренняя переменная var948
	 31754	,1	,1	,&var1007},	//Внутренняя переменная var1007
	 31755	,1	,1	,&var1501},	//Внутренняя переменная var1501
	 31756	,1	,1	,&var290},	//Внутренняя переменная var290
	 31757	,1	,1	,&var296},	//Внутренняя переменная var296
	 31758	,1	,1	,&var555},	//Внутренняя переменная var555
	 31759	,1	,1	,&var1668},	//Внутренняя переменная var1668
	 31760	,1	,1	,&var1850},	//Внутренняя переменная var1850
	 31761	,1	,1	,&var852},	//Внутренняя переменная var852
	 31762	,1	,1	,&var1799},	//Внутренняя переменная var1799
	 31763	,1	,1	,&var197},	//Внутренняя переменная var197
	 31764	,1	,1	,&var204},	//Внутренняя переменная var204
	 31765	,1	,1	,&var507},	//Внутренняя переменная var507
	 31766	,8	,1	,&var669},	//Внутренняя переменная var669
	 31767	,1	,1	,&var679},	//Внутренняя переменная var679
	 31768	,1	,1	,&var743},	//Внутренняя переменная var743
	 31769	,1	,1	,&var485},	//Внутренняя переменная var485
	 31770	,1	,1	,&var1218},	//Внутренняя переменная var1218
	 31771	,1	,1	,&var139},	//Внутренняя переменная var139
	 31772	,1	,1	,&var513},	//Внутренняя переменная var513
	 31773	,1	,1	,&var1002},	//Внутренняя переменная var1002
	 31774	,1	,1	,&var1008},	//Внутренняя переменная var1008
	 31775	,1	,1	,&var1370},	//Внутренняя переменная var1370
	 31776	,1	,1	,&var1823},	//Внутренняя переменная var1823
	 31777	,1	,1	,&var1164},	//Внутренняя переменная var1164
	 31778	,1	,1	,&var1755},	//Внутренняя переменная var1755
	 31779	,1	,1	,&var1822},	//Внутренняя переменная var1822
	 31780	,1	,1	,&var272},	//Внутренняя переменная var272
	 31781	,1	,1	,&var527},	//Внутренняя переменная var527
	 31782	,1	,1	,&var1738},	//Внутренняя переменная var1738
	 31783	,1	,1	,&var1970},	//Внутренняя переменная var1970
	 31784	,1	,1	,&var300},	//Внутренняя переменная var300
	 31785	,1	,1	,&var632},	//Внутренняя переменная var632
	 31786	,1	,1	,&var1405},	//Внутренняя переменная var1405
	 31787	,1	,1	,&var1415},	//Внутренняя переменная var1415
	 31788	,1	,1	,&var1664},	//Внутренняя переменная var1664
	 31789	,1	,1	,&var1696},	//Внутренняя переменная var1696
	 31790	,1	,1	,&var1284},	//Внутренняя переменная var1284
	 31791	,1	,1	,&var241},	//Внутренняя переменная var241
	 31792	,1	,1	,&var797},	//Внутренняя переменная var797
	 31793	,1	,1	,&var832},	//Внутренняя переменная var832
	 31794	,1	,1	,&var1300},	//Внутренняя переменная var1300
	 31795	,1	,1	,&var1470},	//Внутренняя переменная var1470
	 31796	,1	,1	,&var1449},	//Внутренняя переменная var1449
	 31797	,1	,1	,&var1572},	//Внутренняя переменная var1572
	 31798	,1	,1	,&var1704},	//Внутренняя переменная var1704
	 31799	,1	,1	,&var534},	//Внутренняя переменная var534
	 31800	,3	,1	,&var1676},	//Внутренняя переменная var1676
	 31801	,1	,1	,&var695},	//Внутренняя переменная var695
	 31802	,1	,1	,&var1394},	//Внутренняя переменная var1394
	 31803	,1	,1	,&var714},	//Внутренняя переменная var714
	 31804	,1	,1	,&var1282},	//Внутренняя переменная var1282
	 31805	,8	,1	,&var450},	//Внутренняя переменная var450
	 31806	,1	,1	,&var1538},	//Внутренняя переменная var1538
	 31807	,1	,1	,&var1658},	//Внутренняя переменная var1658
	 31808	,1	,1	,&var1893},	//Внутренняя переменная var1893
	 31809	,1	,1	,&var606},	//Внутренняя переменная var606
	 31810	,1	,1	,&var779},	//Внутренняя переменная var779
	 31811	,1	,1	,&var1068},	//Внутренняя переменная var1068
	 31812	,1	,1	,&var1493},	//Внутренняя переменная var1493
	 31813	,1	,1	,&var1715},	//Внутренняя переменная var1715
	 31814	,1	,1	,&var1722},	//Внутренняя переменная var1722
	 31815	,1	,1	,&var609},	//Внутренняя переменная var609
	 31816	,1	,1	,&var924},	//Внутренняя переменная var924
	 31817	,1	,1	,&var1723},	//Внутренняя переменная var1723
	 31818	,1	,1	,&var128},	//Внутренняя переменная var128
	 31819	,1	,1	,&var762},	//Внутренняя переменная var762
	 31820	,1	,1	,&var1157},	//Внутренняя переменная var1157
	 31821	,1	,1	,&var1314},	//Внутренняя переменная var1314
	 31822	,1	,1	,&var543},	//Внутренняя переменная var543
	 31823	,1	,1	,&var613},	//Внутренняя переменная var613
	 31824	,1	,1	,&var1038},	//Внутренняя переменная var1038
	 31825	,1	,1	,&var1085},	//Внутренняя переменная var1085
	 31826	,1	,1	,&var76},	//Внутренняя переменная var76
	 31827	,1	,1	,&var161},	//Внутренняя переменная var161
	 31828	,1	,1	,&var593},	//Внутренняя переменная var593
	 31829	,1	,1	,&var1836},	//Внутренняя переменная var1836
	 31830	,1	,1	,&var141},	//Внутренняя переменная var141
	 31831	,1	,1	,&var931},	//Внутренняя переменная var931
	 31832	,1	,1	,&var1022},	//Внутренняя переменная var1022
	 31833	,1	,1	,&var1171},	//Внутренняя переменная var1171
	 31834	,1	,1	,&var1210},	//Внутренняя переменная var1210
	 31835	,1	,1	,&var1782},	//Внутренняя переменная var1782
	 31836	,1	,1	,&var724},	//Внутренняя переменная var724
	 31837	,1	,1	,&var880},	//Внутренняя переменная var880
	 31838	,1	,1	,&var1588},	//Внутренняя переменная var1588
	 31839	,1	,1	,&var691},	//Внутренняя переменная var691
	 31840	,1	,1	,&var12},	//Внутренняя переменная var12
	 31841	,1	,1	,&var232},	//Внутренняя переменная var232
	 31842	,1	,1	,&var983},	//Внутренняя переменная var983
	 31843	,1	,1	,&var1132},	//Внутренняя переменная var1132
	 31844	,1	,1	,&var1233},	//Внутренняя переменная var1233
	 31845	,1	,1	,&var688},	//Внутренняя переменная var688
	 31846	,1	,1	,&var944},	//Внутренняя переменная var944
	 31847	,1	,1	,&var1106},	//Внутренняя переменная var1106
	 31848	,1	,1	,&var1160},	//Внутренняя переменная var1160
	 31849	,1	,1	,&var1839},	//Внутренняя переменная var1839
	 31850	,8	,1	,&var1951},	//Внутренняя переменная var1951
	 31851	,1	,1	,&var576},	//Внутренняя переменная var576
	 31852	,1	,1	,&var776},	//Внутренняя переменная var776
	 31853	,1	,1	,&var367},	//Внутренняя переменная var367
	 31854	,1	,1	,&var930},	//Внутренняя переменная var930
	 31855	,1	,1	,&var829},	//Внутренняя переменная var829
	 31856	,1	,1	,&var1099},	//Внутренняя переменная var1099
	 31857	,1	,1	,&var1601},	//Внутренняя переменная var1601
	 31858	,1	,1	,&var1608},	//Внутренняя переменная var1608
	 31859	,1	,1	,&var1710},	//Внутренняя переменная var1710
	 31860	,1	,1	,&var47},	//Внутренняя переменная var47
	 31861	,1	,1	,&var996},	//Внутренняя переменная var996
	 31862	,1	,1	,&var1094},	//Внутренняя переменная var1094
	 31863	,1	,1	,&var1396},	//Внутренняя переменная var1396
	 31864	,1	,1	,&var1584},	//Внутренняя переменная var1584
	 31865	,1	,1	,&var274},	//Внутренняя переменная var274
	 31866	,1	,1	,&var720},	//Внутренняя переменная var720
	 31867	,1	,1	,&var1031},	//Внутренняя переменная var1031
	 31868	,8	,1	,&var1226},	//Внутренняя переменная var1226
	 31869	,1	,1	,&var1590},	//Внутренняя переменная var1590
	 31870	,1	,1	,&var614},	//Внутренняя переменная var614
	 31871	,1	,1	,&var963},	//Внутренняя переменная var963
	 31872	,1	,1	,&var1234},	//Внутренняя переменная var1234
	 31873	,1	,1	,&var1563},	//Внутренняя переменная var1563
	 31874	,1	,1	,&var1911},	//Внутренняя переменная var1911
	 31875	,3	,1	,&vainSInt},	//Внутренняя переменная vainSInt
	 31876	,1	,1	,&var1161},	//Внутренняя переменная var1161
	 31877	,1	,1	,&var1228},	//Внутренняя переменная var1228
	 31878	,1	,1	,&var183},	//Внутренняя переменная var183
	 31879	,1	,1	,&var844},	//Внутренняя переменная var844
	 31880	,1	,1	,&var999},	//Внутренняя переменная var999
	 31881	,1	,1	,&var1245},	//Внутренняя переменная var1245
	 31882	,1	,1	,&var1539},	//Внутренняя переменная var1539
	 31883	,1	,1	,&var57},	//Внутренняя переменная var57
	 31884	,1	,1	,&var249},	//Внутренняя переменная var249
	 31885	,1	,1	,&var788},	//Внутренняя переменная var788
	 31886	,1	,1	,&var843},	//Внутренняя переменная var843
	 31887	,1	,1	,&var1571},	//Внутренняя переменная var1571
	 31888	,1	,1	,&var66},	//Внутренняя переменная var66
	 31889	,1	,1	,&var303},	//Внутренняя переменная var303
	 31890	,1	,1	,&var423},	//Внутренняя переменная var423
	 31891	,1	,1	,&var545},	//Внутренняя переменная var545
	 31892	,1	,1	,&var1917},	//Внутренняя переменная var1917
	 31893	,1	,1	,&var283},	//Внутренняя переменная var283
	 31894	,1	,1	,&var1028},	//Внутренняя переменная var1028
	 31895	,1	,1	,&var1269},	//Внутренняя переменная var1269
	 31896	,3	,1	,&var1846},	//Внутренняя переменная var1846
	 31897	,1	,1	,&var152},	//Внутренняя переменная var152
	 31898	,1	,1	,&var755},	//Внутренняя переменная var755
	 31899	,1	,1	,&var933},	//Внутренняя переменная var933
	 31900	,1	,1	,&var1291},	//Внутренняя переменная var1291
	 31901	,1	,1	,&var1334},	//Внутренняя переменная var1334
	 31902	,1	,1	,&var1365},	//Внутренняя переменная var1365
	 31903	,1	,1	,&var311},	//Внутренняя переменная var311
	 31904	,1	,1	,&var1616},	//Внутренняя переменная var1616
	 31905	,1	,1	,&var825},	//Внутренняя переменная var825
	 31906	,1	,1	,&var1109},	//Внутренняя переменная var1109
	 31907	,1	,1	,&var30},	//Внутренняя переменная var30
	 31908	,1	,1	,&var44},	//Внутренняя переменная var44
	 31909	,1	,1	,&var251},	//Внутренняя переменная var251
	 31910	,1	,1	,&var1286},	//Внутренняя переменная var1286
	 31911	,1	,1	,&var199},	//Внутренняя переменная var199
	 31912	,1	,1	,&var436},	//Внутренняя переменная var436
	 31913	,1	,1	,&var441},	//Внутренняя переменная var441
	 31914	,1	,1	,&var1856},	//Внутренняя переменная var1856
	 31915	,1	,1	,&var1983},	//Внутренняя переменная var1983
	 31916	,1	,1	,&var230},	//Внутренняя переменная var230
	 31917	,1	,1	,&var1088},	//Внутренняя переменная var1088
	 31918	,1	,1	,&var1779},	//Внутренняя переменная var1779
	 31919	,1	,1	,&var1900},	//Внутренняя переменная var1900
	 31920	,1	,1	,&var220},	//Внутренняя переменная var220
	 31921	,1	,1	,&var368},	//Внутренняя переменная var368
	 31922	,1	,1	,&var433},	//Внутренняя переменная var433
	 31923	,8	,1	,&var569},	//Внутренняя переменная var569
	 31924	,1	,1	,&var1024},	//Внутренняя переменная var1024
	 31925	,1	,1	,&var1496},	//Внутренняя переменная var1496
	 31926	,1	,1	,&var417},	//Внутренняя переменная var417
	 31927	,1	,1	,&var611},	//Внутренняя переменная var611
	 31928	,1	,1	,&var1328},	//Внутренняя переменная var1328
	 31929	,1	,1	,&var304},	//Внутренняя переменная var304
	 31930	,1	,1	,&var628},	//Внутренняя переменная var628
	 31931	,1	,1	,&var730},	//Внутренняя переменная var730
	 31932	,1	,1	,&var854},	//Внутренняя переменная var854
	 31933	,1	,1	,&var1095},	//Внутренняя переменная var1095
	 31934	,1	,1	,&var1500},	//Внутренняя переменная var1500
	 31935	,1	,1	,&var154},	//Внутренняя переменная var154
	 31936	,1	,1	,&var329},	//Внутренняя переменная var329
	 31937	,1	,1	,&var914},	//Внутренняя переменная var914
	 31938	,1	,1	,&var364},	//Внутренняя переменная var364
	 31939	,1	,1	,&var526},	//Внутренняя переменная var526
	 31940	,1	,1	,&var828},	//Внутренняя переменная var828
	 31941	,1	,1	,&var917},	//Внутренняя переменная var917
	 31942	,1	,1	,&var1340},	//Внутренняя переменная var1340
	 31943	,1	,1	,&var1366},	//Внутренняя переменная var1366
	 31944	,1	,1	,&var84},	//Внутренняя переменная var84
	 31945	,1	,1	,&var406},	//Внутренняя переменная var406
	 31946	,1	,1	,&var1352},	//Внутренняя переменная var1352
	 31947	,1	,1	,&var1357},	//Внутренняя переменная var1357
	 31948	,1	,1	,&var1600},	//Внутренняя переменная var1600
	 31949	,1	,1	,&var182},	//Внутренняя переменная var182
	 31950	,1	,1	,&var397},	//Внутренняя переменная var397
	 31951	,1	,1	,&var696},	//Внутренняя переменная var696
	 31952	,1	,1	,&var912},	//Внутренняя переменная var912
	 31953	,1	,1	,&var1092},	//Внутренняя переменная var1092
	 31954	,1	,1	,&var879},	//Внутренняя переменная var879
	 31955	,1	,1	,&var1520},	//Внутренняя переменная var1520
	 31956	,1	,1	,&var114},	//Внутренняя переменная var114
	 31957	,1	,1	,&var1410},	//Внутренняя переменная var1410
	 31958	,1	,1	,&var1636},	//Внутренняя переменная var1636
	 31959	,1	,1	,&var1783},	//Внутренняя переменная var1783
	 31960	,1	,1	,&var1853},	//Внутренняя переменная var1853
	 31961	,1	,1	,&var1602},	//Внутренняя переменная var1602
	 31962	,1	,1	,&var1693},	//Внутренняя переменная var1693
	 31963	,1	,1	,&var247},	//Внутренняя переменная var247
	 31964	,1	,1	,&var675},	//Внутренняя переменная var675
	 31965	,1	,1	,&var920},	//Внутренняя переменная var920
	 31966	,1	,1	,&var1055},	//Внутренняя переменная var1055
	 31967	,3	,1	,&var1801},	//Внутренняя переменная var1801
	 31968	,1	,1	,&var1402},	//Внутренняя переменная var1402
	 31969	,1	,1	,&var1868},	//Внутренняя переменная var1868
	 31970	,1	,1	,&var1938},	//Внутренняя переменная var1938
	 31971	,1	,1	,&var123},	//Внутренняя переменная var123
	 31972	,1	,1	,&var785},	//Внутренняя переменная var785
	 31973	,1	,1	,&var1434},	//Внутренняя переменная var1434
	 31974	,1	,1	,&var35},	//Внутренняя переменная var35
	 31975	,1	,1	,&var595},	//Внутренняя переменная var595
	 31976	,1	,1	,&var851},	//Внутренняя переменная var851
	 31977	,1	,1	,&var902},	//Внутренняя переменная var902
	 31978	,1	,1	,&var1919},	//Внутренняя переменная var1919
	 31979	,1	,1	,&var14},	//Внутренняя переменная var14
	 31980	,1	,1	,&var332},	//Внутренняя переменная var332
	 31981	,1	,1	,&var705},	//Внутренняя переменная var705
	 31982	,1	,1	,&var770},	//Внутренняя переменная var770
	 31983	,1	,1	,&var842},	//Внутренняя переменная var842
	 31984	,1	,1	,&var877},	//Внутренняя переменная var877
	 31985	,1	,1	,&var711},	//Внутренняя переменная var711
	 31986	,1	,1	,&var856},	//Внутренняя переменная var856
	 31987	,1	,1	,&var1128},	//Внутренняя переменная var1128
	 31988	,1	,1	,&var1724},	//Внутренняя переменная var1724
	 31989	,1	,1	,&var1790},	//Внутренняя переменная var1790
	 31990	,1	,1	,&var1978},	//Внутренняя переменная var1978
	 31991	,1	,1	,&var400},	//Внутренняя переменная var400
	 31992	,1	,1	,&var501},	//Внутренняя переменная var501
	 31993	,1	,1	,&var627},	//Внутренняя переменная var627
	 31994	,1	,1	,&var1547},	//Внутренняя переменная var1547
	 31995	,1	,1	,&var764},	//Внутренняя переменная var764
	 31996	,1	,1	,&var1505},	//Внутренняя переменная var1505
	 31997	,1	,1	,&var1948},	//Внутренняя переменная var1948
	 31998	,1	,1	,&var1969},	//Внутренняя переменная var1969
	 31999	,1	,1	,&var504},	//Внутренняя переменная var504
	 32000	,1	,1	,&var1454},	//Внутренняя переменная var1454
	 32001	,1	,1	,&var1504},	//Внутренняя переменная var1504
	 32002	,1	,1	,&var1663},	//Внутренняя переменная var1663
	 32003	,1	,1	,&var98},	//Внутренняя переменная var98
	 32004	,1	,1	,&var336},	//Внутренняя переменная var336
	 32005	,1	,1	,&var337},	//Внутренняя переменная var337
	 32006	,1	,1	,&var736},	//Внутренняя переменная var736
	 32007	,1	,1	,&var1108},	//Внутренняя переменная var1108
	 32008	,1	,1	,&var1784},	//Внутренняя переменная var1784
	{-1,0,NULL},
}
static char NameSaveFile[]="du.bin\0"; //Имя файла сохранения переменных
#pragma pop
static VarSaveCtrl saveVariables[]={	//Id переменных для сохранения
	{822,"fEM_R0UL03RDU\0"},	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
	{763,"fEM_A2UL83RDU\0"},	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{747,"fEM_A1UL05RDU\0"},	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
	{752,"fEM_A2UC05RDU\0"},	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
	{778,"fEM_A3UL05RDU\0"},	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
	{801,"fEM_A9UZ03RDU\0"},	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
	{797,"fEM_A6UZ03RDU\0"},	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
	{735,"fEM_A1UC02RDU\0"},	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
	{851,"fEM_R0UN18RDU\0"},	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
	{800,"fEM_A8UC03RDU\0"},	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
	{840,"fEM_R0UN06RDU\0"},	//(R0UN06RDU) 6-я заданная мощность
	{832,"fEM_R0UL21RDU\0"},	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
	{853,"fEM_R0UN24RDU\0"},	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
	{811,"fEM_B8UL05RDU\0"},	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
	{869,"fEM_R0UN85LDU\0"},	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
	{766,"fEM_A3UC02RDU\0"},	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
	{826,"fEM_R0UL07RDU\0"},	//(R0UL07RDU) Время срабатывания верхней АС II УР
	{844,"fEM_R0UN11RDU\0"},	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
	{821,"fEM_R0UL02RSS\0"},	//(R0UL02RSS) Tф-постоянная времени, с
	{739,"fEM_A1UC07RDU\0"},	//(A1UC07RDU) Зона возврата при наведении ББ мм
	{759,"fEM_A2UL01RDU\0"},	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{864,"fEM_R0UN80RDU\0"},	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
	{846,"fEM_R0UN13RDU\0"},	//(R0UN13RDU) Минимальное изменение координаты, мм
	{863,"fEM_R0UN80LDU\0"},	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
	{764,"fEM_A2UV01RDU\0"},	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
	{772,"fEM_A3UC09RDU\0"},	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
	{857,"fEM_R0UN70LDU\0"},	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
	{867,"fEM_R0UN83LDU\0"},	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
	{856,"fEM_R0UN27RDU\0"},	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
	{816,"fEM_B8UV03RDU\0"},	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
	{883,"fEM_R4UZ05RDU\0"},	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
	{794,"fEM_A5UZ03RDU\0"},	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
	{827,"fEM_R0UL16RDU\0"},	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
	{757,"fEM_A2UC82RDU\0"},	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
	{865,"fEM_R0UN81LDU\0"},	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
	{765,"fEM_A2UV02RDU\0"},	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
	{768,"fEM_A3UC05RDU\0"},	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
	{761,"fEM_A2UL04RDU\0"},	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
	{881,"fEM_R4UZ03RDU\0"},	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
	{830,"fEM_R0UL19RDU\0"},	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{758,"fEM_A2UC83RDU\0"},	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
	{861,"fEM_R0UN74LDU\0"},	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
	{854,"fEM_R0UN25RDU\0"},	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
	{790,"fEM_A3UV02RDU\0"},	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
	{793,"fEM_A4UZ05RDU\0"},	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
	{829,"fEM_R0UL18RDU\0"},	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
	{862,"fEM_R0UN75LDU\0"},	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
	{731,"dEM_A3UC05UDU\0"},	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
	{831,"fEM_R0UL20RDU\0"},	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
	{779,"fEM_A3UP03RDU\0"},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{746,"fEM_A1UL04RDU\0"},	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
	{807,"fEM_B8UC06RDU\0"},	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
	{868,"fEM_R0UN84LDU\0"},	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
	{855,"fEM_R0UN26RDU\0"},	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
	{814,"fEM_B8UV01RDU\0"},	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
	{876,"fEM_R0UV86RDU\0"},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{890,"iEM_A2UV03CDU\0"},	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
	{754,"fEM_A2UC07RDU\0"},	//(A2UC07RDU) Зона возврата при наведении РБ  мм
	{1930,"lEM_R0MD01LC1\0"},	//(R0MD01LC1) Ручное управление ОРР
	{732,"dEM_A3UC06UDU\0"},	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
	{871,"fEM_R0UV81RDU\0"},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{788,"fEM_A3UP88RDU\0"},	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{817,"fEM_B8UV04RDU\0"},	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
	{771,"fEM_A3UC08RDU\0"},	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
	{849,"fEM_R0UN16RDU\0"},	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
	{727,"dEM_A1UC05UDU\0"},	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
	{796,"fEM_A5UZ05RDU\0"},	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
	{798,"fEM_A6UZ04RDU\0"},	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
	{799,"fEM_A6UZ05RDU\0"},	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
	{741,"fEM_A1UC81RDU\0"},	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
	{887,"iEM_A1UV03IDU\0"},	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
	{818,"fEM_R0UL00RDU\0"},	//(R0UL00RDU) Время ожидания передачи  сигнала отключения сети
	{753,"fEM_A2UC06RDU\0"},	//(A2UC06RDU) Уставка определения самохода РБ  мм
	{872,"fEM_R0UV82RDU\0"},	//(R0UV82RDU) 2-я частота двигателя (шагов/секунду)
	{874,"fEM_R0UV84RDU\0"},	//(R0UV84RDU) 4-я частота двигателя (шагов/секунду)
	{783,"fEM_A3UP53RDU\0"},	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
	{815,"fEM_B8UV02RDU\0"},	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
	{787,"fEM_A3UP87RDU\0"},	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{808,"fEM_B8UL01RDU\0"},	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{795,"fEM_A5UZ04RDU\0"},	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
	{767,"fEM_A3UC03RDU\0"},	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
	{774,"fEM_A3UC82RDU\0"},	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
	{886,"iEM_A1UV02IDU\0"},	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
	{834,"fEM_R0UN01RDU\0"},	//(R0UN01RDU) 1-я заданная мощность
	{836,"fEM_R0UN03RDU\0"},	//(R0UN03RDU) Ограничение 3 по мощности
	{891,"iEM_A3UV01IDU\0"},	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
	{755,"fEM_A2UC08RDU\0"},	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
	{733,"dEM_A8UC05UDU\0"},	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
	{780,"fEM_A3UP04RDU\0"},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{842,"fEM_R0UN08RDU\0"},	//(R0UN08RDU) 8-я заданная мощность
	{888,"iEM_A2UV01IDU\0"},	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
	{837,"fEM_R0UN03RSS\0"},	//(R0UN03RSS) нижняя граница интервала мощности для измерения периода (ватт)
	{729,"dEM_A2UC05UDU\0"},	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
	{751,"fEM_A2UC03RDU\0"},	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
	{875,"fEM_R0UV85RDU\0"},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{776,"fEM_A3UL03RDU\0"},	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
	{880,"fEM_R1UZ05RDU\0"},	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
	{820,"fEM_R0UL02RDU\0"},	//(R0UL02RDU) Время задержки  ИНИ
	{743,"fEM_A1UC83RDU\0"},	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
	{845,"fEM_R0UN12RDU\0"},	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
	{728,"dEM_A1UC06UDU\0"},	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
	{884,"fEM_R7UI76RDU\0"},	//(R7UI76RDU) Время срабатывания сигнала II УР при имитации
	{859,"fEM_R0UN72LDU\0"},	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
	{749,"fEM_A1UV02RDU\0"},	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
	{841,"fEM_R0UN07RDU\0"},	//(R0UN07RDU) 7-я заданная мощность
	{852,"fEM_R0UN19RDU\0"},	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
	{786,"fEM_A3UP86RDU\0"},	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{745,"fEM_A1UL03RDU\0"},	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
	{744,"fEM_A1UL01RDU\0"},	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{805,"fEM_B8UC02RDU\0"},	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
	{809,"fEM_B8UL03RDU\0"},	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
	{838,"fEM_R0UN04RDU\0"},	//(R0UN04RDU) 4-я заданная мощность
	{860,"fEM_R0UN73LDU\0"},	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
	{873,"fEM_R0UV83RDU\0"},	//(R0UV83RDU) 3-я частота двигателя (шагов/секунду)
	{785,"fEM_A3UP85RDU\0"},	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{762,"fEM_A2UL05RDU\0"},	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
	{791,"fEM_A4UZ03RDU\0"},	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
	{792,"fEM_A4UZ04RDU\0"},	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
	{848,"fEM_R0UN15RDU\0"},	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
	{782,"fEM_A3UP44RDU\0"},	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
	{738,"fEM_A1UC06RDU\0"},	//(A1UC06RDU) Уставка определения самохода ББ  мм
	{784,"fEM_A3UP54RDU\0"},	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
	{775,"fEM_A3UL01RDU\0"},	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{843,"fEM_R0UN09RDU\0"},	//(R0UN09RDU) Минимальный период при регулировании мощности
	{734,"dEM_A8UC06UDU\0"},	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
	{825,"fEM_R0UL06RDU\0"},	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
	{756,"fEM_A2UC81RDU\0"},	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
	{858,"fEM_R0UN71LDU\0"},	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
	{819,"fEM_R0UL01RSS\0"},	//(R0UL01RSS) Шаг измерения периода (сек)
	{806,"fEM_B8UC05RDU\0"},	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
	{813,"fEM_B8UL07RDU\0"},	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
	{773,"fEM_A3UC81RDU\0"},	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
	{750,"fEM_A2UC02RDU\0"},	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
	{740,"fEM_A1UC08RDU\0"},	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
	{835,"fEM_R0UN02RDU\0"},	//(R0UN02RDU) 2-я заданная мощность
	{889,"iEM_A2UV02IDU\0"},	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
	{769,"fEM_A3UC06RDU\0"},	//(A3UC06RDU) Уставка определения самохода ИС1  мм
	{730,"dEM_A2UC06UDU\0"},	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
	{877,"fEM_R0UV87RDU\0"},	//(R0UV87RDU) 8-я скорость перемещения ББ (шагов/секунду)
	{810,"fEM_B8UL04RDU\0"},	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
	{737,"fEM_A1UC05RDU\0"},	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
	{824,"fEM_R0UL05RDU\0"},	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
	{804,"fEM_B8UC01RDU\0"},	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
	{802,"fEM_A9UZ04RDU\0"},	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
	{736,"fEM_A1UC03RDU\0"},	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
	{879,"fEM_R1UZ04RDU\0"},	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
	{803,"fEM_A9UZ05RDU\0"},	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
	{870,"fEM_R0UT20RDU\0"},	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
	{748,"fEM_A1UV01RDU\0"},	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
	{770,"fEM_A3UC07RDU\0"},	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
	{882,"fEM_R4UZ04RDU\0"},	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
	{823,"fEM_R0UL04RDU\0"},	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
	{839,"fEM_R0UN05RDU\0"},	//(R0UN05RDU) 5-я заданная мощность
	{850,"fEM_R0UN17RDU\0"},	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
	{833,"fEM_R0UL25RDU\0"},	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{760,"fEM_A2UL03RDU\0"},	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{812,"fEM_B8UL06RDU\0"},	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
	{878,"fEM_R1UZ03RDU\0"},	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
	{828,"fEM_R0UL17RDU\0"},	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
	{892,"iEM_A3UV02IDU\0"},	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
	{781,"fEM_A3UP43RDU\0"},	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
	{777,"fEM_A3UL04RDU\0"},	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
	{742,"fEM_A1UC82RDU\0"},	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
	{885,"iEM_A1UV01IDU\0"},	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
	{847,"fEM_R0UN14RDU\0"},	//(R0UN14RDU) Максимальная координата штока ИМ, мм
	{866,"fEM_R0UN82LDU\0"},	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
	{789,"fEM_A3UV01RDU\0"},	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
	{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_DU[]={
	{&R0MW17LP1,2,11},	//( - , DU) Переключатель АВТ/Р
	{&A2MD12LP1,2,1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
	{&A1MD11LP1,2,10},	//( - , DU) Кнопка ПУСК ББ1
	{&B1MD11LP1,2,6},	//( - , DU) Кнопка ПУСК ББ2
	{&A3MC01LC2,2,21},	//( - , DU) Настроить энкодер ИС1
	{&R0MD34LP1,2,0},	//( - , DU) Кнопка КВИТИРОВАТЬ
	{&B1MC01LC1,2,32},	//( - , DU) Настроить энкодер ББ2
	{&B3MD12LP1,2,12},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
	{&A2MC01LC1,2,26},	//( - , DU) Настроить энкодер РБ1
	{&R0NE02LDU,2,44},	//( - , DU) Потеря связи с БАЗ2
	{&B2MD12LP1,2,3},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
	{&A1MC01LC2,2,29},	//( - , DU) Настроить энкодер ББ1
	{&B1MD12LP1,2,5},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
	{&R0MD33LP1,2,8},	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
	{&A1MD12LP1,2,9},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
	{&A8MC01LC1,2,33},	//( - , DU) Настроить энкодер ДС2
	{&B2MC01LC2,2,27},	//( - , DU) Настроить энкодер РБ2
	{&A1MC01LC1,2,30},	//( - , DU) Настроить энкодер ББ1
	{&A3MC01LC1,2,22},	//( - , DU) Настроить энкодер ИС1
	{&R0MD11LP2,2,14},	//( - , DU) Кнопка Пуск проверки схем сброса
	{&R0MD31LP1,2,42},	//( - , DU) Кнопка СТОП
	{&lEM_R0MD01LC1,2,46},	//( - , DU) Ручное управление ОРР
	{&R4MD31LP2,2,38},	//( - , DU) Кнопка СТОП  (тележки)
	{&R4MD11LP2,2,39},	//( - , DU) Кнопка ВПЕРЁД  (тележки)
	{&R0MD11LP1,2,36},	//( - , DU) Кнопка ПУСК
	{&R0NE01LDU,2,43},	//( - , DU) Потеря связи с БАЗ1
	{&A8MC01LC2,2,34},	//( - , DU) Настроить энкодер ДС2
	{&B3MC01LC1,2,24},	//( - , DU) Настроить энкодер ИС2
	{&C1MD31LP1,2,15},	//( - , DU) Кнопка СБРОС ББ
	{&C1MD31LP2,2,16},	//( - , DU) Кнопка СБРОС ББ
	{&B8MC01LC2,2,19},	//( - , DU) Настроить энкодер АЗ2
	{&B9IS21LDU,2,17},	//( - K26VDSR, DU) Приход на НУ НИ ДС2
	{&B3MC01LC2,2,23},	//( - , DU) Настроить энкодер ИС2
	{&C2MD31LP1,2,35},	//( - , DU) Кнопка СБРОС РБ
	{&R0MW13LP2,2,40},	//( - , DU) Переключатель СЕТЬ
	{&R4MD21LP2,2,37},	//( - , DU) Кнопка НАЗАД  (тележки)
	{&B2MD11LP1,2,4},	//( - , DU) Кнопка ПУСК РБ2
	{&B8MC01LC1,2,20},	//( - , DU) Настроить энкодер АЗ2
	{&R0NE08LDU,2,45},	//( - , DU) Потеря связи с ОПУ
	{&B2MC01LC1,2,28},	//( - , DU) Настроить энкодер РБ2
	{&A2MC01LC2,2,25},	//( - , DU) Настроить энкодер РБ1
	{&A2MD11LP1,2,2},	//( - , DU) Кнопка ПУСК РБ1
	{&A3MD12LP1,2,18},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
	{&B1MC01LC2,2,31},	//( - , DU) Настроить энкодер ББ2
	{&B3MD11LP1,2,13},	//( - , DU) Кнопка ПУСК ИС2
	{&R0MD32LP1,2,41},	//( - , DU) Кнопка СПУСК
	{&A3MD11LP1,2,7},	//( - , DU) Кнопка ПУСК ИС1
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DU[]={
	{&psb1,2,92},	//( - , DU) ру не готова
	{&A2AD31LDU,2,68},	//( - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
	{&R0AB08LDU,2,144},	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
	{&A4AZ03LDU,2,185},	//( - , DU) Несанкционированное перемещение НИ1
	{&R4AB12LDU,2,265},	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
	{&R0VX01LDU,2,52},	//( - , DU) ДО ИМПУЛЬСА
	{&B3VP42LDU,2,114},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
	{&B3EE03LDU,2,156},	//( - , DU) ВПИС ИС2
	{&A3AZ03LDU,2,344},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
	{&B2AB01LDU,2,397},	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
	{&B3AB18LDU,2,66},	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
	{&B9AZ03LDU,2,76},	//( - , DU) Несанкционированное перемещение НИ ДС2
	{&B8AB09LDU,2,208},	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
	{&R1AZ03LDU,2,379},	//( - , DU) Несанкционированное перемещение МДЗ1
	{&R0AD14LZ2,2,47},	//( - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
	{&A0VE01LDU,2,118},	//( - , DU) Напряжение в системы АЗ1 подано
	{&R5IS11LDU,2,271},	//( - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
	{&B4VS12LDU,2,86},	//( - , DU) Движение НИ2 в сторону ВУ
	{&R4AB11LDU,2,264},	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
	{&psaz22,2,107},	//( - , DU) напряжение
	{&A6AB06LDU,2,172},	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
	{&A2VS32LDU,2,12},	//( - , DU) Индикация  СБРОС РБ1
	{&R0VS11LDU,2,142},	//( - , DU) РУ не готова к работе
	{&A3AB12LDU,2,321},	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&A3VZ15LZ1,2,19},	//( - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{&psrb,2,97},	//( - , DU) ???
	{&B4IS11LDU,2,267},	//( - K31VDSR, DU) Приход на ВУ НИ2
	{&R4VS22LDU,2,282},	//( - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
	{&B1AB14LDU,2,335},	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
	{&psrb2,2,96},	//( - , DU) пневматика по программам
	{&A0VN01LDU,2,122},	//( - , DU) Каналы АЗ1 проверены
	{&B8AB06LDU,2,230},	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
	{&A2AB16LDU,2,361},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
	{&A8IS22LDU,2,366},	//( - K31VDSR, DU) Приход на механический НУ ДС2
	{&R4AB17LDU,2,188},	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
	{&A8AB09LDU,2,368},	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
	{&B3AB11LDU,2,61},	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
	{&B8ZAV,2,135},	//( - , DU) 
	{&R0AB20LDU,2,170},	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
	{&A1AB14LDU,2,314},	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
	{&B2AB16LDU,2,409},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
	{&B3AB05LDU,2,57},	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
	{&A4VS12LDU,2,84},	//( - , DU) Движение НИ1 в сторону ВУ
	{&B1IS21LDU,2,252},	//( - K09VDSR, DU) Приход на НУ ББ2
	{&B2IS21LDU,2,253},	//( - K12VDSR, DU) Приход на НУ РБ2-СС
	{&B2VS32LDU,2,13},	//( - , DU) Индикация  СБРОС РБ2
	{&R0AB01LDU,2,79},	//( - , DU) Режим проверки разрешён
	{&R4IS21LDU,2,279},	//( - K07VDSR, DU) Приход на НУ1 тележки
	{&A3AB01LDU,2,342},	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
	{&A3IS33LDU,2,40},	//( - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
	{&A2AB05LDU,2,353},	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
	{&R2AB01LDU,2,383},	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
	{&A9ZAV,2,132},	//( - , DU) Завершение НИ ДС1(2)
	{&R0AB13LDU,2,140},	//( - , DU) Ошибка в заданной координате  АЗ2
	{&R4AD20LDU,2,190},	//( - K14FDSR, DU) Перемещение тележки назад
	{&B2AB15LDU,2,31},	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{&B2IS12LDU,2,174},	//( - K10VDSR, DU) Магнит РБ2 зацеплен
	{&A5AB04LDU,2,179},	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
	{&A5IS11LDU,2,195},	//( - K11VDSR, DU) Приход на ВУ НЛ1
	{&B1VS12LDU,2,299},	//( - , DU) Движение ББ2 в сторону ВУ
	{&A3VS12LDU,2,339},	//( - , DU) Движение ИС1 в сторону ВУ
	{&R2AZ03LDU,2,382},	//( - , DU) Несанкционированное перемещение МДЗ2
	{&R4AB10LDU,2,263},	//( - , DU) Блокировка тележки - не открыта биологическая защита
	{&B1AB01LDU,2,296},	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
	{&A3AB14LDU,2,322},	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
	{&A3AB20LDU,2,326},	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
	{&R0AB05LDU,2,29},	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
	{&B3AB08LDU,2,56},	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
	{&B5VS12LDU,2,194},	//( - K14VDSR, DU) Движение НЛ2 в сторону ВУ
	{&B8AB14LDU,2,213},	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
	{&A3VS22LDU,2,343},	//( - , DU) Движение ИС1 в сторону НУ
	{&B8AB12LDU,2,211},	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
	{&A1AB11LDU,2,311},	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
	{&R1AB01LDU,2,380},	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
	{&B2AZ03LDU,2,398},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
	{&B3IS31LDU,2,22},	//( - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
	{&B3AB09LDU,2,59},	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
	{&A3AB13LDU,2,89},	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
	{&psaz24,2,109},	//( - , DU) ас темп з2
	{&B1AB18LDU,2,338},	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
	{&A2AB12LDU,2,358},	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&B2AB08LDU,2,400},	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
	{&B3VX01LDU,2,15},	//( - , DU) Индикация Выстрел ИС2
	{&B7AS31LDU,2,34},	//( - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
	{&A1VN71LZ1,2,43},	//( - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{&psaz12,2,102},	//( - , DU) напряжение
	{&A6AB08LDU,2,222},	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
	{&A6AB05LDU,2,228},	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
	{&B8VS12LDU,2,229},	//( - , DU) Движение АЗ2 в сторону ВУ
	{&R2ZAV,2,137},	//( - , DU) 
	{&R2IS21LDU,2,256},	//( - K30VDSR, DU) Приход на НУ МДЗ2
	{&B1AB10LDU,2,288},	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
	{&TestDiagnDU,2,91},	//( - , DU) Неисправность от
	{&R5IS21LDU,2,158},	//( - K26VDSR, DU) Приход на НУ ворот отстойной зоны
	{&A4AB02LDU,2,183},	//( - , DU) Блокировка движения НИ1 - Нет перемещения
	{&R4AB16LDU,2,272},	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
	{&A7AZ03LDU,2,35},	//( - , DU) Несанкционированное включение обдува АЗ1
	{&R0AB07LDU,2,141},	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
	{&R0AB16LDU,2,166},	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
	{&B5IS11LDU,2,197},	//( - K15VDSR, DU) Приход на ВУ НЛ2
	{&R1IS11LDU,2,387},	//( - K27VDSR, DU) Приход на ВУ МДЗ1
	{&B2AB10LDU,2,404},	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
	{&A5VS12LDU,2,192},	//( - K11VDSR, DU) Движение НЛ1 в сторону ВУ
	{&B1AB16LDU,2,336},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
	{&R4AB04LDU,2,257},	//( - , DU) Блокировка движения тележки - Превышение времени движения
	{&R0VX03LDU,2,48},	//( - , DU) Готовность 2 мин
	{&A6IS21LDU,2,247},	//( - K10VDSR, DU) Приход на НУ БЗ1
	{&A3AB08LDU,2,346},	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
	{&R0IS02LDU,2,4},	//( - K30VDSR, DU) Разрешение ввода от имитатора
	{&A6AB09LDU,2,223},	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
	{&R4AB02LDU,2,278},	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
	{&A1VS22LDU,2,303},	//( - , DU) Движение ББ1 в сторону НУ
	{&B2AB09LDU,2,403},	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
	{&R0AB15LDU,2,127},	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
	{&R4AB07LDU,2,260},	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
	{&A3AB09LDU,2,318},	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
	{&R4VS12LDU,2,283},	//( - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
	{&B1AB07LDU,2,293},	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
	{&B4IS10LDU,2,25},	//( - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
	{&A4ZAV,2,139},	//( - , DU) 
	{&B1AB19LDU,2,165},	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
	{&R4ABL,2,131},	//( - , DU) Блокировка тележки -
	{&B8IS12LDU,2,149},	//( - K21VDSR, DU) Приход на ВУ2 АЗ2
	{&R4IS11LDU,2,173},	//( - K05VDSR, DU) Приход на ВУ1 тележки
	{&A2IS12LDU,2,176},	//( - K10VDSR, DU) Магнит РБ1 зацеплен
	{&B8IS22LDU,2,363},	//( - K22VDSR, DU) Приход на НУ2 АЗ2
	{&R0AB04LDU,2,51},	//( - , DU) Нарушение времени срабатывания верхней АС II УР
	{&B5AB01LDU,2,203},	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
	{&B1AB05LDU,2,291},	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
	{&A1AB08LDU,2,306},	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
	{&B3AZ03LDU,2,332},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
	{&B9AB02LDU,2,78},	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
	{&A6ZAV,2,138},	//( - , DU) 
	{&A3IS22LDU,2,80},	//( - K02VDSR, DU) Приход на НУП ИС1
	{&B5AB04LDU,2,178},	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
	{&B6AB04LDU,2,275},	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
	{&A8AB02LDU,2,374},	//( - , DU) Блокировка движения ДС2- АНИ не установлен
	{&B3VP52LDU,2,115},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
	{&B3IS12LDU,2,125},	//( - , DU) Приход на ВУ штока ИС2
	{&B6AB05LDU,2,143},	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
	{&B1AB08LDU,2,292},	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
	{&B1AB04LDU,2,298},	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
	{&B8AB13LDU,2,212},	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
	{&R4AB08LDU,2,261},	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
	{&B8IS21LDU,2,150},	//( - K20VDSR, DU) Приход на НУ1 АЗ2
	{&A3ZAV,2,164},	//( - , DU) 
	{&A3AB06LDU,2,317},	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
	{&B3AB14LDU,2,63},	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
	{&A1VS12LDU,2,393},	//( - , DU) Движение ББ1 в сторону ВУ
	{&B2AD31LDU,2,69},	//( - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
	{&B3AB04LDU,2,328},	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
	{&A2AB09LDU,2,355},	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
	{&R0AB17LDU,2,167},	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
	{&psaz11,2,101},	//( - , DU) каналы
	{&B8AB11LDU,2,210},	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
	{&R3VS22LDU,2,161},	//( - , DU) Движение гомогенных дверей к закрыты
	{&B4AB01LDU,2,181},	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
	{&A2IS21LDU,2,250},	//( - K12VDSR, DU) Приход на НУ РБ1-СС
	{&B3IS21LDU,2,254},	//( - K13VDSR, DU) Приход на НУ ИС2
	{&A2AZ03LDU,2,350},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
	{&B3AB07LDU,2,55},	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
	{&R0AB14LDU,2,128},	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
	{&R0VW13LDU,2,8},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
	{&R0VZ71LDU,2,37},	//( - , DU) Обобщенный сигнал АЗ
	{&R0EE02LDU,2,100},	//( - , DU) Питание  АКНП  отключить
	{&B0VE01LDU,2,119},	//( - , DU) Напряжение в системы АЗ2 подано
	{&A3AB19LDU,2,153},	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
	{&A8VS12LDU,2,215},	//( - , DU) Движение ДС2 в сторону ВУ
	{&A2AB17LDU,2,362},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
	{&A9AB02LDU,2,75},	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
	{&R0IS01LDU,2,5},	//( - K29VDSR, DU) Признак работы с имитатором
	{&psaz14,2,104},	//( - , DU) ас темп з2
	{&R0VW23LDU,2,9},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VX09LDU,2,10},	//( - , DU) Индикация регулятор мощности включен/отключен
	{&A3AB10LDU,2,319},	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
	{&B3VS22LDU,2,331},	//( - , DU) Движение ИС2 в сторону НУ
	{&A8AB12LDU,2,371},	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
	{&B5AB02LDU,2,204},	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
	{&B8AB01LDU,2,205},	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
	{&A1AB16LDU,2,315},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
	{&A3AB02LDU,2,341},	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
	{&B1AD31LDU,2,53},	//( - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
	{&B9AB01LDU,2,77},	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
	{&R0AB09LDU,2,145},	//( - , DU) Ошибка в заданной координате ББ1
	{&B2AB06LDU,2,402},	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
	{&B8IS11LDU,2,235},	//( - K19VDSR, DU) Приход на ВУ1 АЗ2
	{&psaz25,2,110},	//( - , DU) питание
	{&A3AB15LDU,2,169},	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
	{&A6AB07LDU,2,221},	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
	{&R0ES01LDU,2,255},	//( - , DU) ОРР не в исходном состоянии
	{&R4AZ03LDU,2,284},	//( - , DU) Несанкционированное перемещение тележки
	{&R3IS11LDU,2,26},	//( - K17VDSR, DU) Приход на ВУ гомогенных дверей
	{&B1VS22LDU,2,295},	//( - , DU) Движение ББ2 в сторону НУ
	{&R2VS12LDU,2,390},	//( - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
	{&B3IS33LDU,2,23},	//( - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
	{&R0AB02LDU,2,49},	//( - , DU) Нарушение времени задержки ИНИ
	{&A9IS21LDU,2,71},	//( - K24VDSR, DU) Приход на НУ НИ ДС1
	{&A1IS11LDU,2,88},	//( - K08VDSR, DU) Приход на ВУ ББ1
	{&B3AB19LDU,2,154},	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
	{&A2AB06LDU,2,354},	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
	{&A2AB04LDU,2,377},	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
	{&B2IS33LDU,2,21},	//( - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
	{&B3AB12LDU,2,62},	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{&A9AZ03LDU,2,73},	//( - , DU) Несанкционированное перемещение НИ ДС1
	{&psb2,2,93},	//( - , DU) движение бб
	{&A0VS11LDU,2,124},	//( - , DU) АЗ1 готова к работе
	{&B1AB13LDU,2,334},	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
	{&A2AB13LDU,2,359},	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
	{&B2AB14LDU,2,408},	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
	{&A3IS31LDU,2,39},	//( - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
	{&A1AD31LDU,2,54},	//( - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
	{&A1IS12LDU,2,177},	//( - K07VDSR, DU) Магнит ББ1 зацеплен
	{&A8AB14LDU,2,373},	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
	{&A2VS11LDU,2,376},	//( - , DU) Движение РБ1 в сторону ВУ
	{&A2AB15LDU,2,30},	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{&psaz13,2,103},	//( - , DU) давление
	{&R4AB01LDU,2,276},	//( - , DU) Блокировка движения тележки - АНИ не установлен
	{&A5ZAV,2,136},	//( - , DU) 
	{&R5VS12LDU,2,160},	//( - , DU) Движение ворот отстойной зоны к открыты
	{&R0AB18LDU,2,168},	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
	{&B3IS22LDU,2,81},	//( - K04VDSR, DU) Приход на НУП ИС2
	{&R8IS11LDU,2,277},	//( - K14VDSR, DU) Аварийный НИ установлен
	{&R0VS17LDU,2,11},	//( - , DU) Индикация выбора АВТОМАТ
	{&B1IS11LDU,2,98},	//( - K08VDSR, DU) Приход на ВУ ББ2
	{&A1ZAV,2,163},	//( - , DU) 
	{&B2AB07LDU,2,399},	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
	{&B3AB16LDU,2,64},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
	{&A9AB01LDU,2,74},	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
	{&R0AB19LDU,2,171},	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
	{&A3IS21LDU,2,251},	//( - K13VDSR, DU) Приход на НУ ИС1
	{&R1IS21LDU,2,286},	//( - K28VDSR, DU) Приход на НУ МДЗ1
	{&B1AB02LDU,2,297},	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
	{&A1AB18LDU,2,300},	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
	{&R0VP73LDU,2,3},	//( - , DU) ПС давления для РУ
	{&R0AD14LZ1,2,46},	//( - K20VDSR, DU) Имитация срабатывания АЗ от II УР
	{&A3VP42LDU,2,112},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
	{&B2AB02LDU,2,396},	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
	{&B2VS11LDU,2,2},	//( - , DU) Движение РБ2 в сторону ВУ
	{&R0VL22LDU,2,151},	//( - , DU) Конец программы 200сек
	{&B5IS21LDU,2,198},	//( - K16VDSR, DU) Приход на НУ НЛ2
	{&A3AB17LDU,2,324},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
	{&B3AB15LDU,2,157},	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
	{&A4IS21LDU,2,187},	//( - K15VDSR, DU) Приход на НУ НИ1
	{&B3AB02LDU,2,329},	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
	{&A3IS35LDU,2,41},	//( - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
	{&psrb4,2,94},	//( - , DU) кнопка сброс
	{&B1IS12LDU,2,175},	//( - K07VDSR, DU) Магнит ББ2 зацеплен
	{&A1AB17LDU,2,316},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
	{&A2VS21LDU,2,349},	//( - , DU) Движение РБ1 в сторону НУ
	{&B2VS21LDU,2,1},	//( - , DU) Движение РБ2 в сторону НУ
	{&R0AB06LDU,2,50},	//( - , DU) Нарушение времени задержки от ВУ РБ
	{&B3VP82LDU,2,116},	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
	{&A6VS12LDU,2,243},	//( - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
	{&A3AB04LDU,2,340},	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
	{&B2AB12LDU,2,406},	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{&A4VS22LDU,2,85},	//( - , DU) Движение НИ1 в сторону НУ
	{&A8AB07LDU,2,217},	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
	{&A1AB05LDU,2,307},	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
	{&B0VP01LDU,2,121},	//( - , DU) Давление в системы АЗ2 подано
	{&B6AB09LDU,2,227},	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
	{&A4AB01LDU,2,184},	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
	{&R4AB05LDU,2,258},	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
	{&A5IS21LDU,2,196},	//( - K12VDSR, DU) Приход на НУ НЛ1
	{&B6VS12LDU,2,241},	//( - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
	{&B3AB01LDU,2,330},	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
	{&A2AB01LDU,2,348},	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
	{&A8AB05LDU,2,218},	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
	{&A3AB07LDU,2,345},	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
	{&A8ZAV,2,133},	//( - , DU) 
	{&A5AB01LDU,2,200},	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
	{&R4AB03LDU,2,285},	//( - , DU) Блокировка движения тележки - Самоход любого механизма
	{&A1AB09LDU,2,309},	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
	{&B4AB02LDU,2,180},	//( - , DU) Блокировка движения НИ2 - Нет перемещения
	{&A8AB11LDU,2,370},	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
	{&A8AB01LDU,2,375},	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
	{&B3AB20LDU,2,67},	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
	{&A5VS22LDU,2,191},	//( - K12VDSR, DU) Движение НЛ1 в сторону НУ
	{&psaz23,2,108},	//( - , DU) давление
	{&A3AB16LDU,2,323},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
	{&A3AB05LDU,2,347},	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
	{&R1AB02LDU,2,381},	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
	{&B2AB13LDU,2,407},	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
	{&B6IS21LDU,2,245},	//( - K14VDSR, DU) Приход на НУ БЗ2
	{&B4IS21LDU,2,186},	//( - K32VDSR, DU) Приход на НУ НИ2
	{&R0AB10LDU,2,146},	//( - , DU) Ошибка в заданной координате ББ2
	{&B8AZ03LDU,2,234},	//( - , DU) Несанкционированное перемещение АЗ2
	{&R1AB04LDU,2,385},	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
	{&A1AB04LDU,2,394},	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
	{&B3IS35LDU,2,24},	//( - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
	{&R0AB12LDU,2,148},	//( - , DU) Ошибка в заданной координате  ИС2
	{&B1AB11LDU,2,287},	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
	{&R2IS11LDU,2,392},	//( - K29VDSR, DU) Приход на ВУ МДЗ2
	{&A6VS22LDU,2,244},	//( - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
	{&A3AB18LDU,2,325},	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
	{&R4IS22LDU,2,280},	//( - K08VDSR, DU) Приход на НУ2 тележки
	{&A2AB02LDU,2,378},	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
	{&R3IS21LDU,2,27},	//( - K18VDSR, DU) Приход на НУ гомогенных дверей
	{&B6VS22LDU,2,242},	//( - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
	{&A3VZ13LZ2,2,17},	//( - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{&B4AZ03LDU,2,182},	//( - , DU) Несанкционированное перемещение НИ2
	{&A5AZ03LDU,2,199},	//( - , DU) Несанкционированное перемещение НЛ1
	{&R4AB13LDU,2,268},	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
	{&A3AB11LDU,2,320},	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
	{&R1VS12LDU,2,391},	//( - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
	{&R0VX02LDU,2,32},	//( - , DU) Импульс разрешен
	{&A2IS33LDU,2,38},	//( - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
	{&A1VN71LZ2,2,44},	//( - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{&B5AZ03LDU,2,202},	//( - , DU) Несанкционированное перемещение НЛ2
	{&A8AZ03LDU,2,220},	//( - , DU) Несанкционированное перемещение ДС2
	{&B8AB07LDU,2,231},	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
	{&psaz3,2,111},	//( - , DU) энкодеры
	{&B6AB08LDU,2,226},	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
	{&B8VS22LDU,2,233},	//( - , DU) Движение АЗ2 в сторону НУ
	{&R4AB14LDU,2,269},	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
	{&R2VS22LDU,2,389},	//( - K09VDSR, DU) Движение МДЗ2 в сторону НУ
	{&A8AB08LDU,2,367},	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
	{&A8AB10LDU,2,369},	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
	{&B2AB05LDU,2,401},	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
	{&B9IS11LDU,2,72},	//( - K25VDSR, DU) Приход на ВУ НИ ДС2
	{&A2IS11LDU,2,82},	//( - K11VDSR, DU) Приход на ВУ РБ1-СТР
	{&B6AZ03LDU,2,237},	//( - , DU) Несанкционированное перемещение БЗ2
	{&A6AZ03LDU,2,240},	//( - , DU) Несанкционированное перемещение БЗ1
	{&A1AB13LDU,2,313},	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
	{&B1AB17LDU,2,337},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
	{&psrb1,2,95},	//( - , DU) пневматика по мощности
	{&A1AB06LDU,2,308},	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
	{&A8IS12LDU,2,364},	//( - K30VDSR, DU) Приход на механический ВУ ДС2
	{&A3EE03LDU,2,155},	//( - , DU) ВПИС ИС1
	{&psaz21,2,106},	//( - , DU) каналы
	{&A1AB19LDU,2,45},	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
	{&B3AB10LDU,2,60},	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
	{&A3VP52LDU,2,113},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
	{&R4IS12LDU,2,281},	//( - K06VDSR, DU) Приход на ВУ2 тележки
	{&A2ZAV,2,134},	//( - , DU) Завершение РБ1,2
	{&B8AB10LDU,2,209},	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
	{&A6AB04LDU,2,274},	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
	{&B1AB06LDU,2,290},	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
	{&A8AB04LDU,2,365},	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
	{&B2AB11LDU,2,405},	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
	{&A4DW,2,129},	//( - , DU) 
	{&B2AB04LDU,2,395},	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
	{&A3VZ13LZ1,2,18},	//( - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{&A9IS11LDU,2,70},	//( - K23VDSR, DU) Приход на ВУ НИ ДС1
	{&R4AB06LDU,2,259},	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
	{&A2AB14LDU,2,360},	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
	{&A6AB02LDU,2,238},	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
	{&A2AB07LDU,2,351},	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
	{&B3AB06LDU,2,58},	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
	{&B6IS11LDU,2,246},	//( - K13VDSR, DU) Приход на ВУ БЗ2
	{&A1AB02LDU,2,301},	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
	{&A3VX01LDU,2,14},	//( - , DU) Индикация Выстрел ИС1
	{&R0VS18LDU,2,16},	//( - , DU) Индикация  Проверка схем сброса
	{&A3VZ15LZ2,2,20},	//( - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{&A1AB01LDU,2,302},	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
	{&R0AB03LDU,2,28},	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
	{&A3VP82LDU,2,117},	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
	{&B6AB01LDU,2,236},	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
	{&B1AZ03LDU,2,294},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
	{&A8AB13LDU,2,372},	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
	{&R0AB11LDU,2,147},	//( - , DU) Ошибка в заданной координате  ИС1
	{&R3VS12LDU,2,162},	//( - , DU) Движение гомогенных дверей к открыты
	{&A6AB01LDU,2,239},	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
	{&B1AB09LDU,2,289},	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
	{&A1AB10LDU,2,310},	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
	{&R0EE03LDU,2,33},	//( - , DU) ВПИС ИС
	{&B6AB06LDU,2,224},	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
	{&A1AB12LDU,2,312},	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&R2AB02LDU,2,384},	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
	{&B4VS22LDU,2,87},	//( - , DU) Движение НИ2 в сторону НУ
	{&B0VS11LDU,2,99},	//( - , DU) АЗ2 готова к работе
	{&A4UP,2,130},	//( - , DU) 
	{&R0VL23LDU,2,152},	//( - , DU) Конец программы 20мин
	{&B8AB04LDU,2,206},	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
	{&R4AB09LDU,2,262},	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
	{&A1AZ03LDU,2,304},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
	{&A1AB07LDU,2,305},	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
	{&A3IS11LDU,2,6},	//( - K01VDSR, DU) Приход на ВУ ИС1
	{&B7AZ03LDU,2,36},	//( - , DU) Несанкционированное включение обдува АЗ2
	{&R2AB04LDU,2,386},	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
	{&B2IS11LDU,2,83},	//( - K11VDSR, DU) Приход на ВУ РБ2-СТР
	{&B3AB13LDU,2,90},	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
	{&psaz15,2,105},	//( - , DU) ас темп з1
	{&B0VN01LDU,2,123},	//( - , DU) Каналы АЗ2 проверены
	{&A5AB02LDU,2,201},	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
	{&A2AB08LDU,2,352},	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
	{&B3IS11LDU,2,7},	//( - K03VDSR, DU) Приход на ВУ ИС2
	{&B8AB02LDU,2,214},	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
	{&B8AB05LDU,2,232},	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
	{&R1VS22LDU,2,388},	//( - K06VDSR, DU) Движение МДЗ1 в сторону НУ
	{&R4AB18LDU,2,189},	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
	{&A8AB06LDU,2,216},	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
	{&A8VS22LDU,2,219},	//( - , DU) Движение ДС2 в сторону НУ
	{&R4AB15LDU,2,270},	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
	{&B6AB02LDU,2,273},	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
	{&B3VS12LDU,2,327},	//( - , DU) Движение ИС2 в сторону ВУ
	{&A7AS31LDU,2,0},	//( - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
	{&A4IS10LDU,2,42},	//( - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
	{&B5VS22LDU,2,193},	//( - K15VDSR, DU) Движение НЛ2 в сторону НУ
	{&A6IS11LDU,2,248},	//( - K09VDSR, DU) Приход на ВУ БЗ1
	{&A2AB10LDU,2,356},	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
	{&A2AB11LDU,2,357},	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
	{&B3AB17LDU,2,65},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
	{&A0VP01LDU,2,120},	//( - , DU) Давление в системы АЗ1 подано
	{&R5VS22LDU,2,159},	//( - , DU) Движение ворот отстойной зоны к закрыты
	{&A4IS11LDU,2,266},	//( - K14VDSR, DU) Приход на ВУ НИ1
	{&B6AB07LDU,2,225},	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
	{&B2AB17LDU,2,410},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
	{&B8AB08LDU,2,207},	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
	{&A3IS12LDU,2,126},	//( - , DU) Приход на ВУ штока ИС1
	{&A1IS21LDU,2,249},	//( - K09VDSR, DU) Приход на НУ ББ1
	{&B1AB12LDU,2,333},	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DU[]={
	{&A2CV02RDU,8,96},	//( - , DU) Заданная скорость перемещения РБ1
	{&B3VC01RDU,8,41},	//( - , DU) Координата ИС2, мм
	{&R0VL04RDU,8,9},	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
	{&A1CV02RDU,8,88},	//( - , DU) Заданная скорость перемещения ББ1
	{&R0CN91LDU,8,68},	//( - , DU) Рассчётная реактивность от регулятора
	{&R0CN93LDU,8,78},	//( - , DU) время работы на мощности более 100Вт, сек
	{&B2VC01RDU,8,49},	//( - , DU) Координата РБ2, мм
	{&B2CV01RDU,8,98},	//( - , DU) Измеренная скорость перемещения РБ2
	{&R0VN11RDU,8,74},	//( - , DU) Текущая мощность РУ
	{&A4VS01IDU,3,24},	//( - , DU) Готовность к управлению НИ1
	{&A2VC01RDU,8,47},	//( - , DU) Координата РБ1, мм
	{&R2VS01IDU,3,30},	//( - , DU) Готовность к управлению МДЗ2
	{&B2CV02RDU,8,104},	//( - , DU) Заданная скорость перемещения РБ2
	{&R0VX08IDU,3,1},	//( - , DU) Индикация Режим
	{&B1VS01IDU,3,20},	//( - , DU) Готовность к управлению ББ2
	{&R4VS01IDU,3,29},	//( - , DU) Готовность к управлению тележкой реактора
	{&R0VL03RDU,8,7},	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
	{&A5VS01IDU,3,26},	//( - , DU) Готовность к управлению НЛ1
	{&A1VC01RDU,8,31},	//( - , DU) Координата ББ1, мм
	{&A3MC01RDU,8,64},	//( - , DU) Заданная координата положения ИС от регулятора мм
	{&R0VL21IDU,3,4},	//( - , DU) Декатрон
	{&A3VC01RDU,8,45},	//( - , DU) Координата ИС1, мм
	{&A1VS01IDU,3,19},	//( - , DU) Готовность к управлению ББ1
	{&A2CV01RDU,8,100},	//( - , DU) Измеренная скорость перемещения РБ1
	{&R0CN94LDU,8,60},	//( - , DU) Скорость изменения мощности
	{&R0VL01IDU,3,16},	//( - , DU) До импульса минут
	{&A3CV02RDU,8,94},	//( - , DU) Заданная скорость перемещения ИС1
	{&B3CV01RDU,8,35},	//( - , DU) Измеренная скорость перемещения ИС2
	{&R0CN92LDU,8,72},	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
	{&B1VC01RDU,8,39},	//( - , DU) Координата ББ2, мм
	{&R1VS01IDU,3,17},	//( - , DU) Готовность к управлению МДЗ1
	{&B3VS01IDU,3,22},	//( - , DU) Готовность к управлению ИС2
	{&R0VN15RDU,8,37},	//( - , DU) Период разгона РУ
	{&R0VS21IDU,3,18},	//( - , DU) Индикация ВИД ПРОВЕРКИ
	{&B8VC01RDU,8,51},	//( - , DU, MDuBz1, MDuBz2) Координата АЗ2, мм
	{&R0VL06RDU,8,13},	//( - , DU) Индикация (Время задержки от ВУ РБ)
	{&R0VL11IDU,3,15},	//( - , DU) До импульса секунд
	{&R0VL02RDU,8,11},	//( - , DU) Индикация (Время задержки ИНИ)
	{&B5VS01IDU,3,27},	//( - , DU) Готовность к управлению НЛ2
	{&A3CV01RDU,8,92},	//( - , DU) Измеренная скорость перемещения ИС1
	{&B3CV02RDU,8,90},	//( - , DU) Заданная скорость перемещения ИС2
	{&A6VS01IDU,3,28},	//( - , DU) Готовность к управлению БЗ1
	{&B1CV01RDU,8,86},	//( - , DU) Измеренная скорость перемещения ББ2
	{&B8CV01RDU,8,82},	//( - , DU) Измеренная скорость перемещения АЗ2
	{&A3MC03RDU,8,70},	//( - , DU) Координата положения ИМ 0-й реактивности
	{&B1CV02RDU,8,84},	//( - , DU) Заданная скорость перемещения ББ2
	{&R5VS01IDU,3,63},	//( - , DU) Готовность к управлению ворот отстойной зоны
	{&A3VS01IDU,3,21},	//( - , DU) Готовность к управлению ИС1
	{&A8VC01RDU,8,43},	//( - , DU) Координата ДС2, мм
	{&B6VS01IDU,3,57},	//( - , DU) Готовность к управлению БЗ2
	{&TTLDU,3,34},	//( - , DU) ttl
	{&A8VS01IDU,3,59},	//( - , DU) Готовность к управлению ДС2
	{&A8CV01RDU,8,80},	//( - , DU) Измеренная скорость перемещения ДС2
	{&R0VL05RDU,8,5},	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
	{&A2VS01IDU,3,23},	//( - , DU) Готовность к управлению РБ1
	{&A3CP02RDU,8,53},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
	{&B8VS01IDU,3,58},	//( - , DU) Готовность к управлению АЗ2
	{&A3MC02RDU,8,66},	//( - , DU) Температурная корректировка координаты ИМ
	{&R3VS01IDU,3,33},	//( - , DU) Готовность к управлению гомогенных дверей
	{&B2VS01IDU,3,0},	//( - , DU) Готовность к управлению РБ2
	{&B3CP02RDU,8,55},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
	{&R0VL01RDU,8,2},	//( - , DU) Индикация Время задержки
	{&B4VS01IDU,3,25},	//( - , DU) Готовность к управлению НИ2
	{&R0VN12RDU,8,76},	//( - , DU) Заданная мощность РУ
	{&A1CV01RDU,8,102},	//( - , DU) Измеренная скорость перемещения ББ1
	{&R0CN95LDU,3,62},	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DU[]={
	{&fEM_A5UZ04RDU,8,184},	//( - , DU) Время задержки блокировки НЛ по превышению времени движения сек
	{&fEM_R0UN26RDU,8,325},	//( - , DU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
	{&fEM_R0UL16RDU,8,220},	//( - , DU) Предельное отклонение от времени задержки  ИНИ
	{&fEM_A3UC82RDU,8,256},	//( - , DU) Граница 1-го диапазона ИС назад (вниз)
	{&fEM_A8UC03RDU,8,39},	//( - , DU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
	{&fEM_A3UP88RDU,8,69},	//( - , DU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{&fEM_R0UN19RDU,8,293},	//( - , DU) Коэффициент t0 ф-ции температурной корректировки ИМ
	{&dEM_A8UC06UDU,5,37},	//( - , DU) Нижняя граница показания энкодера АЗ2, деления энкодера
	{&fEM_B8UV01RDU,8,73},	//( - , DU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
	{&fEM_R0UN18RDU,8,291},	//( - , DU) Коэффициент t1 ф-ции температурной корректировки ИМ
	{&fEM_A3UC07RDU,8,146},	//( - , DU) Зона возврата при наведении ИС 0.01 мм
	{&fEM_R0UV87RDU,8,55},	//( - , DU) 8-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UN06RDU,8,228},	//( - , DU) 6-я заданная мощность
	{&fEM_R0UN13RDU,8,283},	//( - , DU) Минимальное изменение координаты, мм
	{&fEM_A4UZ05RDU,8,192},	//( - , DU) Время задержки блокировки НИ по недвижению сек
	{&fEM_A2UL04RDU,8,128},	//( - , DU) Задержка определения самохода РБ после команды на останов, с
	{&fEM_R0UN08RDU,8,224},	//( - , DU) 8-я заданная мощность
	{&fEM_R0UN07RDU,8,226},	//( - , DU) 7-я заданная мощность
	{&fEM_R0UN03RDU,8,234},	//( - , DU) Ограничение 3 по мощности
	{&fEM_A3UC06RDU,8,100},	//( - , DU) Уставка определения самохода ИС1  мм
	{&R0MW16IP1,3,16},	//( - , DU) Переключатель ВИД ПРОВЕРКИ
	{&fEM_R0UN84LDU,8,315},	//( - , DU) 4 - Коэффициент  опережения старта ИМ
	{&fEM_A3UP53RDU,8,65},	//( - , DU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
	{&fEM_A5UZ05RDU,8,186},	//( - , DU) Время задержки блокировки НЛ по недвижению сек
	{&fEM_A3UP03RDU,8,57},	//( - , DU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{&fEM_A9UZ04RDU,8,172},	//( - , DU) Время задержки блокировки НИ ДС по превышению времени движения сек
	{&fEM_R0UL00RDU,8,341},	//( - , DU) Время ожидания передачи  сигнала отключения сети
	{&fEM_A3UV01RDU,8,96},	//( - , DU) Допустимое превышение заданной скорости ИС мм/с
	{&fEM_R0UN72LDU,8,299},	//( - , DU) 2 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_B8UC01RDU,8,156},	//( - , DU) Зона нечувствительности при наведении АЗ2,ДС2 мм
	{&fEM_B8UC02RDU,8,160},	//( - , DU) Зона возврата при наведении АЗ2,ДС2  мм
	{&fEM_A1UC08RDU,8,138},	//( - , DU) Зона нечувствительности при наведении ББ  мм
	{&fEM_R0UN71LDU,8,297},	//( - , DU) 1 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_R4UZ05RDU,8,180},	//( - , DU) Время задержки блокировки тележки по недвижению сек
	{&fEM_A3UC09RDU,8,267},	//( - , DU) Координата переднего аварийного выключателя ИС мм
	{&fEM_R0UN27RDU,8,327},	//( - , DU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
	{&fEM_A3UC03RDU,8,35},	//( - , DU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
	{&fEM_R1UZ04RDU,8,202},	//( - , DU) Время задержки блокировки МДЗ по превышению времени движения сек
	{&fEM_B8UL04RDU,8,79},	//( - , DU) Задержка определения самохода АЗ-ДС после команды на останов, сек
	{&fEM_A3UP44RDU,8,63},	//( - , DU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
	{&fEM_B8UC05RDU,8,118},	//( - , DU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
	{&iEM_A3UV02IDU,3,266},	//( - , DU) Скорость ИС для 1-го диапазона назад (вниз)
	{&fEM_A3UP43RDU,8,61},	//( - , DU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
	{&fEM_R0UV86RDU,8,51},	//( - , DU) 7-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UN83LDU,8,313},	//( - , DU) 3 - Коэффициент  опережения старта ИМ
	{&fEM_R0UT20RDU,8,319},	//( - , DU) Предельное время работы на мощности более 100 Вт, сек
	{&fEM_R0UV81RDU,8,43},	//( - , DU) 1-я частота двигателя (шагов/секунду)
	{&B8MC01RP2,8,10},	//( - , DU) Заданная координата АЗ2 мм
	{&fEM_R0UL07RDU,8,216},	//( - , DU) Время срабатывания верхней АС II УР
	{&fEM_A1UC02RDU,8,271},	//( - , DU) Коэффициент преобразования частота-скорость(мм/сек) ББ
	{&R0MW11IP1,3,17},	//( - , DU) Переключатель ВЫСТРЕЛ
	{&fEM_A2UC81RDU,8,246},	//( - , DU) Граница 1-го диапазона РБ вперёд (вверх)
	{&iEM_A2UV02IDU,3,261},	//( - , DU) Скорость 2-го диапазона РБ вперёд (вверх)
	{&fEM_R0UL25RDU,8,331},	//( - , DU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{&fEM_A3UL05RDU,8,136},	//( - , DU) Время задержки блокировки ИС по недвижению сек
	{&dEM_A3UC06UDU,5,31},	//( - , DU) Нижняя граница показания энкодера ИС, деления энкодера
	{&fEM_A3UC05RDU,8,102},	//( - , DU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
	{&fEM_A2UL01RDU,8,154},	//( - , DU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{&fEM_A1UL01RDU,8,144},	//( - , DU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{&fEM_A1UC83RDU,8,244},	//( - , DU) Граница 1-го диапазона ББ назад (вниз)
	{&iEM_A1UV01IDU,3,262},	//( - , DU) Скорость 1-го диапазона ББ вперёд (вверх)
	{&fEM_A2UC03RDU,8,29},	//( - , DU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
	{&fEM_B8UL05RDU,8,164},	//( - , DU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
	{&fEM_A9UZ05RDU,8,174},	//( - , DU) Время задержки блокировки НИ ДС по недвижению сек
	{&fEM_R0UL01RSS,8,333},	//( - , DU) Шаг измерения периода (сек)
	{&fEM_B8UV02RDU,8,75},	//( - , DU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
	{&fEM_R0UN82LDU,8,311},	//( - , DU) 2 - Коэффициент  опережения старта ИМ
	{&fEM_A1UV01RDU,8,86},	//( - , DU) Допустимое превышение заданной скорости ББ мм/с
	{&fEM_A2UL03RDU,8,122},	//( - , DU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{&fEM_R0UL17RDU,8,212},	//( - , DU) Предельное отклонение от времени задержки  сброса от ВУ РБ
	{&A3MC01RP1,8,6},	//( - , DU) Заданная координата положения ИС1 мм
	{&fEM_R0UN01RDU,8,238},	//( - , DU) 1-я заданная мощность
	{&fEM_R0UN74LDU,8,303},	//( - , DU) 4 - Коэффициент реактивности функции опережения старта ИМ
	{&dEM_A8UC05UDU,5,41},	//( - , DU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
	{&fEM_A6UZ03RDU,8,194},	//( - , DU) Время задержки блокировки БЗ по самоходу сек
	{&iEM_A3UV01IDU,3,265},	//( - , DU) Скорость ИС для 1-го диапазона вперёд (вверх)
	{&fEM_R0UN12RDU,8,281},	//( - , DU) Зона нечувствительности при регулировании мощности %
	{&fEM_A1UC05RDU,8,92},	//( - , DU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
	{&fEM_A2UV01RDU,8,82},	//( - , DU) Допустимое превышение заданной скорости РБ мм/с
	{&iEM_A2UV03CDU,3,81},	//( - , DU) Скорость 1-го диапазона РБ назад (вниз)
	{&iEM_A1UV03IDU,3,264},	//( - , DU) Скорость1-го диапазона ББ назад (вниз)
	{&fEM_R0UN15RDU,8,323},	//( - , DU) коэффициент рассогласования по координате для транспортной реактивности %
	{&fEM_R1UZ03RDU,8,200},	//( - , DU) Время задержки блокировки МДЗ по самоходу сек
	{&fEM_A2UC83RDU,8,242},	//( - , DU) Граница 1-го диапазона РБ назад (вниз)
	{&fEM_A2UL05RDU,8,120},	//( - , DU) Время задержки блокировки РБ по недвижению сек
	{&fEM_R0UN81LDU,8,309},	//( - , DU) 1 - Коэффициент  опережения старта ИМ
	{&R0MW14IP2,3,0},	//( - , DU) Переключатель ОБДУВ
	{&fEM_R0UN80RDU,8,258},	//( - , DU) Ограничение по мощности в режиме калибровка и имульс
	{&fEM_A3UP04RDU,8,59},	//( - , DU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{&fEM_R0UL06RDU,8,208},	//( - , DU) Предельное время срабатывания верхней АС II УР
	{&fEM_A1UC81RDU,8,248},	//( - , DU) Граница 1-го диапазона ББ вперёд (вверх)
	{&fEM_R0UN80LDU,8,307},	//( - , DU) 0 - Коэффициент  опережения старта ИМ
	{&fEM_R0UN03RSS,8,337},	//( - , DU) нижняя граница интервала мощности для измерения периода (ватт)
	{&fEM_R0UL20RDU,8,112},	//( - , DU) Предельное отклонение от времени задержки  сброса от II УР
	{&fEM_R0UV82RDU,8,45},	//( - , DU) 2-я частота двигателя (шагов/секунду)
	{&fEM_B8UL06RDU,8,168},	//( - , DU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
	{&fEM_R1UZ05RDU,8,204},	//( - , DU) Время задержки блокировки МДЗ по недвижению сек
	{&R0MW13IP1,3,15},	//( - , DU) Переключатель ВЫБОР ЗОН
	{&fEM_A1UL04RDU,8,94},	//( - , DU) Задержка определения самохода ББ после команды на останов, сек
	{&fEM_R0UL02RDU,8,222},	//( - , DU) Время задержки  ИНИ
	{&fEM_A3UC81RDU,8,254},	//( - , DU) Граница 1-го диапазона ИС вперёд (вверх)
	{&fEM_R0UN73LDU,8,301},	//( - , DU) 3 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_A3UP54RDU,8,106},	//( - , DU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
	{&fEM_A3UP87RDU,8,108},	//( - , DU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{&fEM_R0UL18RDU,8,218},	//( - , DU) Предельное отклонение от времени задержки  сброса от НУП ИС
	{&fEM_R0UN02RDU,8,236},	//( - , DU) 2-я заданная мощность
	{&dEM_A2UC06UDU,5,25},	//( - , DU) Нижняя граница показания энкодера РБ, деления энкодера
	{&fEM_A1UL05RDU,8,132},	//( - , DU) Время задержки блокировки ББ по недвижению с
	{&fEM_R0UN05RDU,8,230},	//( - , DU) 5-я заданная мощность
	{&fEM_A2UC82RDU,8,240},	//( - , DU) Граница 2-го диапазона РБ вперёд (вверх)
	{&fEM_A1UC03RDU,8,19},	//( - , DU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
	{&fEM_R0UL03RDU,8,210},	//( - , DU) Время срабатывания сброса от ВУ РБ
	{&dEM_A1UC06UDU,5,23},	//( - , DU) Нижняя граница показания энкодера ББ, деления энкодера
	{&fEM_A6UZ04RDU,8,196},	//( - , DU) Время задержки блокировки БЗ по превышению времени движения сек
	{&fEM_R0UN85LDU,8,317},	//( - , DU) 5 - Коэффициент  опережения старта ИМ
	{&dEM_A2UC05UDU,5,27},	//( - , DU) Верхняя граница показания энкодера РБ, деления энкодера
	{&fEM_A6UZ05RDU,8,198},	//( - , DU) Время задержки блокировки БЗ по недвижению сек
	{&fEM_A1UC06RDU,8,90},	//( - , DU) Уставка определения самохода ББ  мм
	{&dEM_A1UC05UDU,5,21},	//( - , DU) Верхняя граница показания энкодера ББ, деления энкодера
	{&fEM_B8UL01RDU,8,162},	//( - , DU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{&fEM_R0UN25RDU,8,321},	//( - , DU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
	{&fEM_A3UV02RDU,8,98},	//( - , DU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
	{&fEM_A1UL03RDU,8,130},	//( - , DU) Задержка определения самохода ББ после останова (достижения скорости 0), с
	{&fEM_R0UN17RDU,8,289},	//( - , DU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
	{&R0MW12IP1,3,14},	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
	{&B3MC01RP1,8,8},	//( - , DU) Заданная координата положения ИС2 мм
	{&fEM_B8UV03RDU,8,77},	//( - , DU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
	{&fEM_B8UC06RDU,8,116},	//( - , DU) Уставка определения самохода АЗ-ДС,  мм
	{&fEM_A2UC05RDU,8,126},	//( - , DU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
	{&B1MC01RP1,8,4},	//( - , DU) Заданная координата положения ББ2  мм
	{&fEM_A4UZ03RDU,8,188},	//( - , DU) Время задержки блокировки НИ по самоходу сек
	{&fEM_A4UZ04RDU,8,190},	//( - , DU) Время задержки блокировки НИ по превышению времени движения сек
	{&fEM_A1UC82RDU,8,250},	//( - , DU) Граница 2-го диапазона ББ вперёд (вверх)
	{&R0MW14IP1,3,13},	//( - , DU) Переключатель ПРОГРАММЫ
	{&fEM_R0UL02RSS,8,335},	//( - , DU) Tф-постоянная времени, с
	{&fEM_R0UL05RDU,8,110},	//( - , DU) Время срабатывания сброса от НУП ИС
	{&fEM_A9UZ03RDU,8,170},	//( - , DU) Время задержки блокировки НИ  ДС по самоходу сек
	{&fEM_R0UN16RDU,8,287},	//( - , DU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
	{&fEM_B8UL07RDU,8,158},	//( - , DU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
	{&fEM_R0UN04RDU,8,232},	//( - , DU) 4-я заданная мощность
	{&fEM_B8UL03RDU,8,166},	//( - , DU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
	{&fEM_R0UL04RDU,8,206},	//( - , DU) Предельное время ожидания срабатывания АЗ от НУП ИС
	{&dEM_A3UC05UDU,5,33},	//( - , DU) Верхняя граница показания энкодера ИС, деления энкодера
	{&fEM_A2UL83RDU,8,252},	//( - , DU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{&fEM_A2UC08RDU,8,150},	//( - , DU) Зона нечувствительности при наведении РБ мм
	{&fEM_A3UP86RDU,8,71},	//( - , DU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{&fEM_A2UV02RDU,8,84},	//( - , DU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
	{&fEM_A1UV02RDU,8,88},	//( - , DU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
	{&fEM_A1UC07RDU,8,142},	//( - , DU) Зона возврата при наведении ББ мм
	{&R0MW11IP2,3,18},	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
	{&fEM_R0UV83RDU,8,47},	//( - , DU) 3-я частота двигателя (шагов/секунду)
	{&fEM_A2UC02RDU,8,269},	//( - , DU) Коэффициент преобразования частота-скорость(мм/сек)
	{&fEM_A5UZ03RDU,8,182},	//( - , DU) Время задержки блокировки НЛ по самоходу сек
	{&fEM_A3UC08RDU,8,140},	//( - , DU) Зона нечувствительности при наведении ИС 0.01 мм
	{&fEM_A3UC02RDU,8,273},	//( - , DU) Коэффициент преобразования частота-скорость (мм/сек) ИС
	{&fEM_R0UV84RDU,8,49},	//( - , DU) 4-я частота двигателя (шагов/секунду)
	{&fEM_A3UL01RDU,8,148},	//( - , DU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{&R0MW12IP2,3,1},	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
	{&fEM_A3UL04RDU,8,104},	//( - , DU) Задержка определения самохода ИС после команды на останов, сек
	{&iEM_A2UV01IDU,3,260},	//( - , DU) Скорость 1-го диапазона РБ вперёд (вверх)
	{&fEM_R0UN09RDU,8,277},	//( - , DU) Минимальный период при регулировании мощности
	{&fEM_R7UI76RDU,8,339},	//( - , DU) Время срабатывания сигнала II УР при имитации
	{&fEM_A3UP85RDU,8,67},	//( - , DU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{&fEM_R4UZ04RDU,8,176},	//( - , DU) Время задержки блокировки тележки по превышению времени движения сек
	{&fEM_A3UL03RDU,8,134},	//( - , DU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
	{&iEM_A1UV02IDU,3,263},	//( - , DU) Скорость 2-го диапазона ББ вперёд (вверх)
	{&fEM_R0UN24RDU,8,329},	//( - , DU) Нижняя граница интервала мощности для измерения периода (ватт)
	{&fEM_R0UV85RDU,8,53},	//( - , DU) 6-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R4UZ03RDU,8,178},	//( - , DU) Время задержки блокировки тележки по самоходу сек
	{&fEM_R0UL19RDU,8,214},	//( - , DU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{&fEM_R0UN14RDU,8,285},	//( - , DU) Максимальная координата штока ИМ, мм
	{&fEM_B8UV04RDU,8,114},	//( - , DU) Время разгона механизма при переходе на новую скорость сек
	{&fEM_R0UN70LDU,8,295},	//( - , DU) 0 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_A2UC06RDU,8,124},	//( - , DU) Уставка определения самохода РБ  мм
	{&A1MC01RP1,8,2},	//( - , DU) Заданная координата положения ББ1 мм
	{&R0MW15IP1,3,12},	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
	{&fEM_R0UN11RDU,8,279},	//( - , DU) Допустимое превышение заданной мощности  при регулировании
	{&fEM_R0UL21RDU,8,275},	//( - , DU) Предельное время задержки  сброса от ВУ РБ
	{&fEM_R0UN75LDU,8,305},	//( - , DU) 5 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_A2UC07RDU,8,152},	//( - , DU) Зона возврата при наведении РБ  мм
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_DiagnDU[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DiagnDU[]={
	{&R0DE3DLDU,2,1},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
	{&R0DEB1LDU,2,3},	//( - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
	{&R0DEB4LDU,2,2},	//( - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
	{&R0DEB2LDU,2,4},	//( - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
	{&R0DE3CLDU,2,0},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
	{&R0DEB3LDU,2,5},	//( - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DiagnDU[]={
	{&R0DE0FLDU,3,2},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
	{&R0DE0BLDU,3,4},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
	{&R0DE07LDU,3,6},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
	{&R0DE09LDU,3,8},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
	{&R0DE05LDU,3,9},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
	{&R0DE04LDU,3,11},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
	{&R0DE0CLDU,3,5},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
	{&R0DE08LDU,3,10},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
	{&R0DE01LDU,3,1},	//( - DiagnVDS, DiagnDU) диагностика модуля ДУ на 1 месте
	{&R0DE0DLDU,3,3},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
	{&R0DE0ALDU,3,7},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
	{&R0DE06LDU,3,0},	//( - DiagnFDS, DiagnDU) диагностика модуля ДУ на 6 месте
	{&R0DE03LDU,3,12},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
	{&R0DE02LDU,3,13},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DiagnDU[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_MDuBz1[]={
	{&R0VW23LDU,2,1},	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,2,2},	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{&R0AD21LDU,2,0},	//( - , SBz1DU) Подключить защиту от II УР
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MDuBz1[]={
	{&R0VP73LZ1,2,1},	//( - , Baz1, SBz1DU) ПС давления для РУ
	{&B0VP71LZ1,2,8},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
	{&B0VT71LZ1,2,0},	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
	{&A0VN71LZ1,2,3},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
	{&A0EE03LZ1,2,4},	//( - , Baz1, SBz1DU) Исправность АКНП3
	{&A0EE02LZ1,2,5},	//( - , Baz1, SBz1DU) Исправность АКНП2
	{&A0EE04LZ1,2,6},	//( - , Baz1, SBz1DU) Исправность АКНП4
	{&A0EE01LZ1,2,7},	//( - , Baz1, SBz1DU) Исправность АКНП1
	{&A1VP41LZ1,2,11},	//( - , Baz1, SBz1DU) Давление СБРОС ББ1 ниже АС
	{&A0VT71LZ1,2,12},	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
	{&A0VP71LZ1,2,9},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
	{&B1VP41LZ1,2,10},	//( - , Baz1, SBz1DU) Давление СБРОС ББ2 ниже АС
	{&B0VN71LZ1,2,2},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MDuBz1[]={
	{&A0CT01IZ1,8,4},	//( - , Baz1, SBz1DU) Температура АЗ1-1
	{&B0CT01IZ1,8,0},	//( - , Baz1, SBz1DU) Температура АЗ2-1
	{&R0VN11RZ1,8,2},	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MDuBz1[]={
	{&B8VC01RDU,8,0},	//( - , SBz1DU, MBz1A1, MBz1A2, MBz1A3, MBz1A4) Координата АЗ2, мм
	{NULL,0,0},
}
#pragma pop
static char MDuBz1_ip1[]={"192.168.10.52\0"};
static char MDuBz1_ip2[]={"192.168.10.152\0"};
#pragma pack(push,1)
static ModbusRegister coil_MDuBz2[]={
	{&R0AD21LDU,2,0},	//( - , SBz2DU) Подключить защиту от II УР
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MDuBz2[]={
	{&B0VN71LZ2,2,2},	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ2
	{&A0EE01LZ2,2,7},	//( - , Baz2, SBz2DU) Исправность АКНП1
	{&B0VT71LZ2,2,0},	//( - , Baz2, SBz2DU) АС по температуре в АЗ2
	{&A0EE03LZ2,2,4},	//( - , Baz2, SBz2DU) Исправность АКНП3
	{&A0EE02LZ2,2,5},	//( - , Baz2, SBz2DU) Исправность АКНП2
	{&A0VP71LZ2,2,9},	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ1
	{&B1VP41LZ2,2,10},	//( - , Baz2, SBz2DU) Давление СБРОС ББ2 ниже АС
	{&A1VP41LZ2,2,11},	//( - , Baz2, SBz2DU) Давление СБРОС ББ1 ниже АС
	{&A0VN71LZ2,2,3},	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ1
	{&A0VT71LZ2,2,12},	//( - , Baz2, SBz2DU) АС по температуре в АЗ1
	{&R0VP73LZ2,2,1},	//( - , Baz2, SBz2DU) ПС давления для РУ
	{&A0EE04LZ2,2,6},	//( - , Baz2, SBz2DU) Исправность АКНП4
	{&B0VP71LZ2,2,8},	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ2
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MDuBz2[]={
	{&B0CT01IZ2,8,0},	//( - , Baz2, SBz2DU) Температура АЗ2-1
	{&R0VN11RZ2,8,2},	//( - , Baz2, SBz2DU) Средняя мощность по БАЗ2
	{&A0CT01IZ2,8,4},	//( - , Baz2, SBz2DU) Температура АЗ1-1
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MDuBz2[]={
	{&B8VC01RDU,8,0},	//( - , SBz2DU, MBz2A1, MBz2A2, MBz2A3, MBz2A4) Координата АЗ2, мм
	{NULL,0,0},
}
#pragma pop
static char MDuBz2_ip1[]={"192.168.10.54\0"};
static char MDuBz2_ip2[]={"192.168.10.154\0"};
#pragma pack(push,1)
static ModbusRegister coil_MDuS[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MDuS[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MDuS[]={
	{&B3IC01UDU,5,4},	//( - , SDu) Координата штока ИС2
	{&A8IC01UDU,5,6},	//( - , SDu) Координата ДС2
	{&B8IC01UDU,5,8},	//( - , SDu) Координата АЗ2, мм
	{&B2IC01UDU,5,10},	//( - , SDu) Координата штока РБ2
	{&A1IC01UDU,5,12},	//( - , SDu) Координата штока ББ1
	{&B1IC01UDU,5,14},	//( - , SDu) Координата штока ББ2
	{&A2IC01UDU,5,0},	//( - , SDu) Координата штока РБ1
	{&A3IC01UDU,5,2},	//( - , SDu) Координата штока ИС1
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MDuS[]={
	{NULL,0,0},
}
#pragma pop
static char MDuS_ip1[]={"192.168.10.60\0"};
static char MDuS_ip2[]={"192.168.10.60\0"};
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_DU[0],&di_DU[0],&di_DU[0],&hr_DU[0],NULL,NULL,NULL,0},	//Общий слэйв
	{0,5006,&coil_DiagnDU[0],&di_DiagnDU[0],&di_DiagnDU[0],&hr_DiagnDU[0],NULL,NULL,NULL,0},	//Диагностика DU
	{1,5010,&coil_MDuBz1[0],&di_MDuBz1[0],&di_MDuBz1[0],&hr_MDuBz1[0],NULL,MDuBz1_ip1,MDuBz1_ip2,100},	//Мастер ДУ в Баз1
	{1,5009,&coil_MDuBz2[0],&di_MDuBz2[0],&di_MDuBz2[0],&hr_MDuBz2[0],NULL,MDuBz2_ip1,MDuBz2_ip2,100},	//Мастер ДУ в Баз2
	{1,5005,&coil_MDuS[0],&di_MDuS[0],&di_MDuS[0],&hr_MDuS[0],NULL,MDuS_ip1,MDuS_ip2,10},	//Мастер ДУ в SCM
	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>/nstatic char buf_FDS1608[40];	//FDS1608
static fds16r_inipar ini_FDS1608={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1608={0,0,&ini_FDS1608,buf_FDS1608,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1608[]={
	{(&B1AD01LDU,1,18},
	{(&B1AD05LDU,1,26},
	{(&B1AD04LDU,1,24},
	{(&B1AD03LDU,1,22},
	{(&A1AD01LDU,1,4},
	{(&B1AD02LDU,1,20},
	{(&B1AD21LDU,1,16},
	{(&B1AD11LDU,1,14},
	{(&A1AD05LDU,1,12},
	{(&A1AD04LDU,1,10},
	{(&A1AD03LDU,1,8},
	{(&A1AD02LDU,1,6},
	{(&A1AD21LDU,1,2},
	{(&A1AD11LDU,1,0},
	{(&R0S01LIM,1,28},
	{(&R0DE08LDU,3,38},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>/nstatic char buf_FDS1610[40];	//FDS1610
static fds16r_inipar ini_FDS1610={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1610={0,0,&ini_FDS1610,buf_FDS1610,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1610[]={
	{(&R1AD10LDU,1,12},
	{(&A3AD31LDU,1,8},
	{(&A3AD34LDU,1,0},
	{(&A3AD33LDU,1,2},
	{(&A7AP31LDU,1,10},
	{(&A2AD33LDU,1,4},
	{(&R1AD20LDU,1,14},
	{(&B5AD10LDU,1,24},
	{(&B5AD20LDU,1,26},
	{(&R2AD10LDU,1,16},
	{(&A5AD10LDU,1,20},
	{(&A5AD20LDU,1,22},
	{(&R2AD20LDU,1,18},
	{(&A4AD10LDU,1,6},
	{(&R0DE0ALDU,3,38},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>/nstatic char buf_FDS1611[40];	//FDS1611
static fds16r_inipar ini_FDS1611={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1611={0,0,&ini_FDS1611,buf_FDS1611,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1611[]={
	{(&B3AD11LDU,1,14},
	{(&B3AD21LDU,1,16},
	{(&B3AD02LDU,1,20},
	{(&B3AD01LDU,1,18},
	{(&B3AD05LDU,1,26},
	{(&B3AD04LDU,1,24},
	{(&B3AD03LDU,1,22},
	{(&A3AD01LDU,1,4},
	{(&A3AD05LDU,1,12},
	{(&A3AD04LDU,1,10},
	{(&A3AD11LDU,1,0},
	{(&A3AD21LDU,1,2},
	{(&A3AD03LDU,1,8},
	{(&A3AD02LDU,1,6},
	{(&R0DE0BLDU,3,38},
	{(&A9AD10LDU,1,28},
	{(&B9AD10LDU,1,30},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>/nstatic char buf_FDS1609[40];	//FDS1609
static fds16r_inipar ini_FDS1609={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1609={0,0,&ini_FDS1609,buf_FDS1609,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1609[]={
	{(&B2AD33LDU,1,4},
	{(&R4AD10LDU,1,24},
	{(&R4AD20LDU,1,26},
	{(&B3AD33LDU,1,2},
	{(&A8AD20LDU,1,14},
	{(&A8AD10LDU,1,12},
	{(&B8AD10LDU,1,28},
	{(&B8AD20LDU,1,30},
	{(&B3AD34LDU,1,0},
	{(&B3AD31LDU,1,8},
	{(&A6AD10LDU,1,16},
	{(&A6AD20LDU,1,18},
	{(&B4AD10LDU,1,6},
	{(&B6AD10LDU,1,20},
	{(&R0DE09LDU,3,38},
	{(&B6AD20LDU,1,22},
	{(&B7AP31LDU,1,10},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>/nstatic char buf_VDS3213[132];	//VDS3213
static vds32r_inipar ini_VDS3213={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3213={0,0,&ini_VDS3213,buf_VDS3213,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3213[]={
	{(&B5VS12LDU,1,26},
	{(&A5VS22LDU,1,22},
	{(&A5VS12LDU,1,20},
	{(&R0DE0DLDU,3,64},
	{(&R4VS12LDU,1,2},
	{(&R4VS22LDU,1,4},
	{(&B5VS22LDU,1,28},
	{(&A6VS22LDU,1,34},
	{(&A6VS12LDU,1,32},
	{(&B6VS22LDU,1,40},
	{(&B6VS12LDU,1,38},
	{(&R1VS22LDU,1,10},
	{(&R2VS22LDU,1,16},
	{(&R2VS12LDU,1,14},
	{(&R1VS12LDU,1,8},
	{(&R0IE02LDU,1,44},
	{(&R0IE01LDU,1,46},
	{(&A6IE01LDU,1,36},
	{(&B6IE01LDU,1,42},
	{(&A8IE01LDU,1,6},
	{(&B5IE01LDU,1,30},
	{(&A5IE02LDU,1,24},
	{(&R1IE01LDU,1,12},
	{(&R2IE01LDU,1,18},
	{(&R6IS61LDU,1,0},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>/nstatic char buf_FDS1615[40];	//FDS1615
static fds16r_inipar ini_FDS1615={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1615={0,0,&ini_FDS1615,buf_FDS1615,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1615[]={
	{(&A2AD32LDU,1,4},
	{(&R0AD16LDU,1,24},
	{(&B2AD32LDU,1,12},
	{(&A1AD32LDU,1,0},
	{(&B1AD32LDU,1,8},
	{(&B1AD31LDU,1,10},
	{(&R0AD05LZ2,1,30},
	{(&R0DE0FLDU,3,38},
	{(&A1AD31LDU,1,2},
	{(&B2AD31LDU,1,14},
	{(&A2AD31LDU,1,6},
	{(&R0AD03LZ1,1,16},
	{(&R0AD03LZ2,1,26},
	{(&R0AD04LZ1,1,18},
	{(&R8AD21LDU,1,22},
	{(&R0AD04LZ2,1,28},
	{(&R0AD05LZ1,1,20},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vas84r.h>/nstatic char buf_VAS8412[30];	//VAS8412
static vas84r_inipar ini_VAS8412={0xc6,255,1,8,0xff,0,16,};
#pragma pack(push,1)
static table_drv table_VAS8412={0,0,&ini_VAS8412,buf_VAS8412,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VAS8412[]={
	{(&B3IP02IDU,3,3},
	{(&A3IP02IDU,3,0},
	{(&R0DE0CLDU,3,26},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vencf8l.h>/nstatic char buf_VENCF[86];	//VENCF
static vencf8_inipar ini_VENCF={0xc2,0xff,0,0x6,0x96,};
#pragma pack(push,1)
static table_drv table_VENCF={0,0,&ini_VENCF,buf_VENCF,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VENCF[]={
	{(&venc08,5,75},
	{(&venc07,5,70},
	{(&venc06,5,65},
	{(&venc05,5,60},
	{(&venc04,5,55},
	{(&venc03,5,50},
	{(&venc02,5,45},
	{(&venc01,5,40},
	{(&R0DE06LDU,3,80},
	{(&R0DE01LDU,3,82},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>/nstatic char buf_VDS3202[132];	//VDS3202
static vds32r_inipar ini_VDS3202={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3202={0,0,&ini_VDS3202,buf_VDS3202,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3202[]={
	{(&R8AD22LDU,1,28},
	{(&B2IS12LDU,1,18},
	{(&B1IS12LDU,1,12},
	{(&B7AS31LDU,1,10},
	{(&R0DE02LDU,3,64},
	{(&B4IS21LDU,1,62},
	{(&B3IS33LDU,1,2},
	{(&B3IS35LDU,1,0},
	{(&R8IS11LDU,1,26},
	{(&B4IS10LDU,1,6},
	{(&B1IS11LDU,1,14},
	{(&R1IS11LDU,1,52},
	{(&B3IS31LDU,1,8},
	{(&B2IS33LDU,1,4},
	{(&B1IS21LDU,1,16},
	{(&B2IS21LDU,1,22},
	{(&B3IS21LDU,1,24},
	{(&A3VZ15LZ1,1,36},
	{(&A3VZ13LZ1,1,34},
	{(&A9IS11LDU,1,44},
	{(&A9IS21LDU,1,46},
	{(&B9IS11LDU,1,48},
	{(&B2IS11LDU,1,20},
	{(&B9IS21LDU,1,50},
	{(&B4IS11LDU,1,60},
	{(&R0AD14LZ1,1,38},
	{(&A1VN71LZ1,1,40},
	{(&R2IS11LDU,1,56},
	{(&R0VZ71LZ1,1,42},
	{(&R2IS21LDU,1,58},
	{(&R1IS21LDU,1,54},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>/nstatic char buf_VDS3204[132];	//VDS3204
static vds32r_inipar ini_VDS3204={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3204={0,0,&ini_VDS3204,buf_VDS3204,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3204[]={
	{(&R4IS22LDU,1,14},
	{(&R4IS12LDU,1,10},
	{(&B6IS11LDU,1,24},
	{(&B8IS12LDU,1,40},
	{(&B8IS21LDU,1,38},
	{(&R3IS21LDU,1,34},
	{(&R3IS11LDU,1,32},
	{(&R5IS11LDU,1,48},
	{(&R5IS21LDU,1,50},
	{(&A3IS11LDU,1,0},
	{(&B3IS11LDU,1,4},
	{(&R6IS21LDU,1,56},
	{(&B6IS21LDU,1,26},
	{(&A6IS21LDU,1,18},
	{(&A6IS11LDU,1,16},
	{(&R0DE04LDU,3,64},
	{(&B5IS21LDU,1,30},
	{(&B5IS11LDU,1,28},
	{(&A8IS22LDU,1,60},
	{(&A8IS12LDU,1,58},
	{(&B8IS22LDU,1,42},
	{(&A5IS21LDU,1,22},
	{(&A5IS11LDU,1,20},
	{(&B8IS11LDU,1,36},
	{(&B3IS22LDU,1,6},
	{(&A3IS22LDU,1,2},
	{(&R4IS21LDU,1,12},
	{(&R4IS11LDU,1,8},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/sbkfp7.h>/nstatic char buf_SBKFP[26];	//SBKFP
static sbk_inipar ini_SBKFP={0xcc,0xff,8,8,};
#pragma pack(push,1)
static table_drv table_SBKFP={0,0,&ini_SBKFP,buf_SBKFP,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_SBKFP[]={
	{(&R0DEB3LDU,1,22},
	{(&R0DEB4LDU,1,24},
	{(&R0DEB1LDU,1,18},
	{(&R0DEB2LDU,1,20},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>/nstatic char buf_VDS3203[132];	//VDS3203
static vds32r_inipar ini_VDS3203={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3203={0,0,&ini_VDS3203,buf_VDS3203,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3203[]={
	{(&A3VZ13LZ2,1,34},
	{(&A3VZ15LZ2,1,36},
	{(&R0AD14LZ2,1,38},
	{(&A1VN71LZ2,1,40},
	{(&R0DE03LDU,3,64},
	{(&A2IS11LDU,1,20},
	{(&R0IS02LDU,1,58},
	{(&R0IS01LDU,1,56},
	{(&A7AS31LDU,1,10},
	{(&A4IS10LDU,1,6},
	{(&A1IS21LDU,1,16},
	{(&A2IS21LDU,1,22},
	{(&A3IS21LDU,1,24},
	{(&A3IS35LDU,1,0},
	{(&A3IS33LDU,1,2},
	{(&A4IS11LDU,1,26},
	{(&A3IS31LDU,1,8},
	{(&A1IS11LDU,1,14},
	{(&A2IS33LDU,1,4},
	{(&R0VZ71LZ2,1,42},
	{(&A4IS21LDU,1,28},
	{(&A1IS12LDU,1,12},
	{(&A2IS12LDU,1,18},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>/nstatic char buf_VDS3205[132];	//VDS3205
static vds32r_inipar ini_VDS3205={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3205={0,0,&ini_VDS3205,buf_VDS3205,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3205[]={
	{(&B1IE04LDU,1,30},
	{(&B3IE04LDU,1,46},
	{(&B3IE03LDU,1,44},
	{(&B2IE04LDU,1,38},
	{(&B2IE03LDU,1,36},
	{(&R0DE05LDU,3,64},
	{(&A1IE04LDU,1,6},
	{(&A2IE03LDU,1,12},
	{(&A2IE04LDU,1,14},
	{(&A3IE03LDU,1,20},
	{(&B1IE03LDU,1,28},
	{(&A3IE04LDU,1,22},
	{(&A1IE03LDU,1,4},
	{(&A3IE02LDU,1,16},
	{(&A1IE02LDU,1,0},
	{(&A2IE01LDU,1,10},
	{(&A2IE02LDU,1,8},
	{(&B1IE01LDU,1,26},
	{(&B2IE01LDU,1,34},
	{(&A3IE01LDU,1,18},
	{(&A1IE01LDU,1,2},
	{(&B3IE01LDU,1,42},
	{(&R6IS51LDU,1,56},
	{(&R6IS52LDU,1,58},
	{(&R6IS41LDU,1,52},
	{(&R6IS42LDU,1,54},
	{(&R6IS32LDU,1,50},
	{(&R6IS31LDU,1,48},
	{(&B1IE02LDU,1,24},
	{(&B3IE02LDU,1,40},
	{(&B2IE02LDU,1,32},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>/nstatic char buf_FDS1607[40];	//FDS1607
static fds16r_inipar ini_FDS1607={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1607={0,0,&ini_FDS1607,buf_FDS1607,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1607[]={
	{(&B2AD02LDU,1,20},
	{(&B2AD03LDU,1,22},
	{(&B2AD04LDU,1,24},
	{(&B2AD05LDU,1,26},
	{(&R0DE07LDU,3,38},
	{(&B2AD01LDU,1,18},
	{(&A2AD03LDU,1,8},
	{(&A2AD02LDU,1,6},
	{(&B2AD21LDU,1,16},
	{(&B2AD11LDU,1,14},
	{(&A2AD01LDU,1,4},
	{(&A2AD04LDU,1,10},
	{(&A2AD05LDU,1,12},
	{(&A2AD11LDU,1,0},
	{(&R0S01LZ1,1,28},
	{(&R0S01LZ2,1,30},
	{(&A2AD21LDU,1,2},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Drive drivers[]={
	{0x96,0x08,40,def_buf_FDS1608,&table_FDS1608},	//FDS16-08
	{0x96,0x0a,40,def_buf_FDS1610,&table_FDS1610},	//FDS16-10
	{0x96,0x0b,40,def_buf_FDS1611,&table_FDS1611},	//FDS16-11
	{0x96,0x09,40,def_buf_FDS1609,&table_FDS1609},	//FDS16-09
	{0xc2,0x0d,132,def_buf_VDS3213,&table_VDS3213},	//VDS32-13
	{0x96,0x0f,40,def_buf_FDS1615,&table_FDS1615},	//FDS16-15
	{0x02,0x01,86,def_buf_VENCF,&table_VENCF},	//VENCF
	{0xc2,0x02,132,def_buf_VDS3202,&table_VDS3202},	//VDS32-02
	{0xc2,0x04,132,def_buf_VDS3204,&table_VDS3204},	//VDS32-04
	{0xc6,0x0c,30,def_buf_VAS8412,&table_VAS8412},	//VAS84-12
	{0xc2,0x03,132,def_buf_VDS3203,&table_VDS3203},	//VDS32-03
	{0xc2,0x05,132,def_buf_VDS3205,&table_VDS3205},	//VDS32-05
	{0x96,0x07,40,def_buf_FDS1607,&table_FDS1607},	//FDS16-07
	{0xcc,0x20,26,def_buf_SBKFP,&table_SBKFP},	//SBKFP
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){	//Инициализация переменных для хранения
	setAsFloat(850,71.40565);
	setAsFloat(833,0.190);
	setAsFloat(760,1.50);
	setAsFloat(882,360);
	setAsFloat(823,2.0);
	setAsFloat(839,800.0);
	setAsShort(892,4);
	setAsFloat(781,0.46);
	setAsFloat(812,2.0);
	setAsFloat(878,1.0);
	setAsFloat(828,0.045);
	setAsFloat(847,160.0);
	setAsFloat(866,0.765962);
	setAsFloat(789,0.4);
	setAsFloat(777,3);
	setAsFloat(742,100.0);
	setAsShort(885,1);
	setAsFloat(747,3);
	setAsFloat(822,1.5);
	setAsFloat(763,1.50);
	setAsFloat(797,1.0);
	setAsFloat(735,0.000877);
	setAsFloat(851,0.271145);
	setAsFloat(800,0.0009765625);
	setAsFloat(752,0.05);
	setAsFloat(778,2);
	setAsFloat(801,1);
	setAsFloat(811,2);
	setAsFloat(840,1000.0);
	setAsFloat(832,2.5);
	setAsFloat(853,0.001);
	setAsFloat(766,0.001675);
	setAsFloat(869,0.25501999);
	setAsFloat(739,0.006);
	setAsFloat(826,0.150);
	setAsFloat(844,500);
	setAsFloat(821,2.0);
	setAsFloat(863,0.839554030);
	setAsFloat(764,0.4);
	setAsFloat(759,1);
	setAsFloat(864,10);
	setAsFloat(846,0.05);
	setAsFloat(856,0.000418877);
	setAsFloat(816,10.91);
	setAsFloat(772,159.99);
	setAsFloat(857,0.1268);
	setAsFloat(867,0.67256403);
	setAsFloat(757,100);
	setAsFloat(865,0.78859401);
	setAsFloat(765,0.4);
	setAsFloat(883,2);
	setAsFloat(794,1.0);
	setAsFloat(827,0.045);
	setAsFloat(830,0.045);
	setAsFloat(758,100);
	setAsFloat(861,0.2646);
	setAsFloat(854,0.935);
	setAsFloat(790,0.4);
	setAsFloat(768,0.04);
	setAsFloat(761,3);
	setAsFloat(881,1);
	setAsInt(731,1689599);
	setAsFloat(793,3.0);
	setAsFloat(829,0.045);
	setAsFloat(862,0.2995);
	setAsFloat(779,2.5);
	setAsFloat(831,0.045);
	setAsFloat(855,0.006792308);
	setAsFloat(814,4);
	setAsFloat(746,3);
	setAsFloat(807,2);
	setAsFloat(868,0.42476001);
	setAsBool(1930,0);
	setAsInt(732,-200);
	setAsFloat(876,600);
	setAsShort(890,4);
	setAsFloat(754,0.01);
	setAsFloat(771,0.006);
	setAsFloat(849,-141.21);
	setAsInt(727,1024200);
	setAsFloat(871,100);
	setAsFloat(788,0.67);
	setAsFloat(817,0.1);
	setAsFloat(741,30.0);
	setAsShort(887,4);
	setAsFloat(818,0.100);
	setAsFloat(753,0.04);
	setAsFloat(796,0.50);
	setAsFloat(798,60.0);
	setAsFloat(799,0.50);
	setAsFloat(815,4);
	setAsFloat(787,0.64);
	setAsFloat(808,1);
	setAsFloat(795,6.0);
	setAsFloat(767,0.00009765625);
	setAsFloat(872,200);
	setAsFloat(874,400);
	setAsFloat(783,0.52);
	setAsFloat(834,0.001);
	setAsFloat(774,170);
	setAsShort(886,4);
	setAsFloat(755,0.008);
	setAsFloat(836,200.0);
	setAsShort(891,4);
	setAsShort(888,1);
	setAsFloat(837,0.005);
	setAsInt(729,1024200);
	setAsInt(733,1536200);
	setAsFloat(780,0);
	setAsFloat(842,2000.0);
	setAsFloat(880,1);
	setAsFloat(820,0.015);
	setAsFloat(743,110.0);
	setAsFloat(845,0.01);
	setAsInt(728,-200);
	setAsFloat(751,0.00009765625);
	setAsFloat(875,500);
	setAsFloat(776,1.50);
	setAsFloat(859,0.1858);
	setAsFloat(884,0.08);
	setAsFloat(786,0.56);
	setAsFloat(749,0.4);
	setAsFloat(841,1500.0);
	setAsFloat(852,24.93556615);
	setAsFloat(809,1.50);
	setAsFloat(838,500.0);
	setAsFloat(860,0.2066);
	setAsFloat(873,300);
	setAsFloat(745,1.50);
	setAsFloat(744,1.0);
	setAsFloat(805,0.6);
	setAsFloat(792,16.0);
	setAsFloat(848,0.1);
	setAsFloat(782,0.49);
	setAsFloat(785,0.53);
	setAsFloat(762,3);
	setAsFloat(791,1.0);
	setAsFloat(843,30);
	setAsInt(734,-200);
	setAsFloat(738,0.03);
	setAsFloat(784,0.55);
	setAsFloat(775,1);
	setAsFloat(819,0.5);
	setAsFloat(806,0.3);
	setAsFloat(825,2.0);
	setAsFloat(756,20);
	setAsFloat(858,0.1567);
	setAsFloat(740,0.004);
	setAsFloat(813,120);
	setAsFloat(773,170);
	setAsFloat(750,0.002375);
	setAsFloat(769,0.07);
	setAsFloat(835,100.0);
	setAsShort(889,4);
	setAsFloat(737,0.04);
	setAsFloat(824,0.190);
	setAsFloat(804,0.4);
	setAsFloat(802,15);
	setAsFloat(736,0.00009765625);
	setAsInt(730,-200);
	setAsFloat(877,750);
	setAsFloat(810,3);
	setAsFloat(879,20.0);
	setAsFloat(748,0.4);
	setAsFloat(803,0.50);
	setAsFloat(870,3600.0);
	setAsFloat(770,0.01);
}
int freebuf=0;
int delay=0;
uspaint8 InternalBuf[9933];
uspaint8 SpaEEPROMBuf[816];
void Scheme()
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
void InitInternalParametr(void)
void MainCycle(void){
	if ((getAsShort(R0S01LDU) == 2) || (getAsShort(R0S01LDU) == 3)) {
		if(delay++<200) return;
		delay=delay>32000?32000:delay;
		freebuff = 0;
		Scheme();
	} else {
		if (freebuff) return;
		freebuff = 1;
		memset(BUFFER, 0, SIZE_BUFFER);
		InitSetConst();
		ZeroVar();
		if (SimulOn) initAllSimul(CodeSub, drivers, SimulIP, SimulPort);
		else initAllDrivers(drivers);
	}
}
#endif