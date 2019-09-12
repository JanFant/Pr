#ifndef SCM_H
#define SCM_H
// Подсистема  scm:SCM
static char SimulOn=0;
static short CodeSub=1;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 //Время цикла мс
float takt,taktScheme=0,taktSS=0;
#define SIZE_BUFFER 3480
static char BUFFER[SIZE_BUFFER];
#define A0IT01IZ1	BUFFER[0]	// (ao16_pti:320 - K01AO, - ) Температура АЗ1-1
#define idA0IT01IZ1	1	// (ao16_pti:320 - K01AO, - ) Температура АЗ1-1
#define A0IT02IZ2	BUFFER[3]	// (ao16_pti:320 - K05AO, - ) Температура АЗ1-2
#define idA0IT02IZ2	2	// (ao16_pti:320 - K05AO, - ) Температура АЗ1-2
#define A0IT03IRP	BUFFER[6]	// (ao16_pti:320 - K11AO, - ) Температура АЗ1-3
#define idA0IT03IRP	3	// (ao16_pti:320 - K11AO, - ) Температура АЗ1-3
#define A0SN02RIM	BUFFER[9]	// ( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
#define idA0SN02RIM	4	// ( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
#define A0SN03RIM	BUFFER[14]	// ( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
#define idA0SN03RIM	5	// ( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
#define A0SN04RIM	BUFFER[19]	// ( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
#define idA0SN04RIM	6	// ( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
#define A0SN05RIM	BUFFER[24]	// ( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
#define idA0SN05RIM	7	// ( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
#define A0SN06RIM	BUFFER[29]	// ( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
#define idA0SN06RIM	8	// ( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
#define A0SN07RIM	BUFFER[34]	// ( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
#define idA0SN07RIM	9	// ( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
#define A0SN08RIM	BUFFER[39]	// ( - , SCM) Поток нейтронов AЗ1(нейтр/с)
#define idA0SN08RIM	10	// ( - , SCM) Поток нейтронов AЗ1(нейтр/с)
#define A0SR01RIM	BUFFER[44]	// ( - , SCM) Текущая реактивность AЗ1
#define idA0SR01RIM	11	// ( - , SCM) Текущая реактивность AЗ1
#define A0VN01RIM	BUFFER[49]	// ( - , SCM) Период разгона  AЗ1
#define idA0VN01RIM	12	// ( - , SCM) Период разгона  AЗ1
#define A0VP81LZZ	BUFFER[54]	// (do32_pti:110 - K03DO, - ) Давление АЗ1 в норме
#define idA0VP81LZZ	13	// (do32_pti:110 - K03DO, - ) Давление АЗ1 в норме
#define A1AD01LDU	BUFFER[56]	// (vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
#define idA1AD01LDU	14	// (vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
#define A1AD02LDU	BUFFER[58]	// (vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
#define idA1AD02LDU	15	// (vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
#define A1AD03LDU	BUFFER[60]	// (vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
#define idA1AD03LDU	16	// (vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
#define A1AD04LDU	BUFFER[62]	// (vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
#define idA1AD04LDU	17	// (vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
#define A1AD05LDU	BUFFER[64]	// (vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
#define idA1AD05LDU	18	// (vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
#define A1AD11LDU	BUFFER[66]	// (vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	19	// (vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
#define A1AD21LDU	BUFFER[68]	// (vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	20	// (vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
#define A1AD31LDU	BUFFER[70]	// (vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
#define idA1AD31LDU	21	// (vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
#define A1AD32LDU	BUFFER[72]	// (vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
#define idA1AD32LDU	22	// (vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
#define A1IC01UDU	BUFFER[74]	// ( - , SDu) Координата штока ББ1
#define idA1IC01UDU	23	// ( - , SDu) Координата штока ББ1
#define A1IE03LDU	BUFFER[79]	// ( - , SCM) Движение ББ1 вперед (от БУШД)
#define idA1IE03LDU	24	// ( - , SCM) Движение ББ1 вперед (от БУШД)
#define A1IE04LDU	BUFFER[81]	// ( - , SCM) Движение ББ1 назад (от БУШД)
#define idA1IE04LDU	25	// ( - , SCM) Движение ББ1 назад (от БУШД)
#define A1IS11LDU	BUFFER[83]	// (do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
#define idA1IS11LDU	26	// (do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
#define A1IS11LIM	BUFFER[85]	// ( - , SCM) Магнит ББ1 обесточен
#define idA1IS11LIM	27	// ( - , SCM) Магнит ББ1 обесточен
#define A1IS12LDU	BUFFER[87]	// (do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
#define idA1IS12LDU	28	// (do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
#define A1IS21LDU	BUFFER[89]	// (do32_pti:140 - K02DO, - ) Приход на НУ ББ1
#define idA1IS21LDU	29	// (do32_pti:140 - K02DO, - ) Приход на НУ ББ1
#define A1IS32LIM	BUFFER[91]	// ( - , SCM) Клапан cброса ББ1 открыт(обесточен)
#define idA1IS32LIM	30	// ( - , SCM) Клапан cброса ББ1 открыт(обесточен)
#define A1VP81LZZ	BUFFER[93]	// (do32_pti:110 - K01DO, - ) Давление СБРОС ББ1 в норме
#define idA1VP81LZZ	31	// (do32_pti:110 - K01DO, - ) Давление СБРОС ББ1 в норме
#define A2AD01LDU	BUFFER[95]	// (vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
#define idA2AD01LDU	32	// (vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
#define A2AD02LDU	BUFFER[97]	// (vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
#define idA2AD02LDU	33	// (vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
#define A2AD03LDU	BUFFER[99]	// (vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
#define idA2AD03LDU	34	// (vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
#define A2AD04LDU	BUFFER[101]	// (vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
#define idA2AD04LDU	35	// (vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
#define A2AD05LDU	BUFFER[103]	// (vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
#define idA2AD05LDU	36	// (vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
#define A2AD11LDU	BUFFER[105]	// (vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	37	// (vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
#define A2AD21LDU	BUFFER[107]	// (vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	38	// (vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
#define A2AD31LDU	BUFFER[109]	// (vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
#define idA2AD31LDU	39	// (vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
#define A2AD32LDU	BUFFER[111]	// (vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
#define idA2AD32LDU	40	// (vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
#define A2AD33LDU	BUFFER[113]	// (vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
#define idA2AD33LDU	41	// (vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
#define A2IC01UDU	BUFFER[115]	// ( - , SDu) Координата штока РБ1
#define idA2IC01UDU	42	// ( - , SDu) Координата штока РБ1
#define A2IP01IZ1	BUFFER[120]	// (ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ1	43	// (ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
#define A2IP01IZ2	BUFFER[123]	// (ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ2	44	// (ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
#define A2IS11LDU	BUFFER[126]	// (do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
#define idA2IS11LDU	45	// (do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
#define A2IS11LIM	BUFFER[128]	// ( - , SCM) Магнит РБ1 обесточен
#define idA2IS11LIM	46	// ( - , SCM) Магнит РБ1 обесточен
#define A2IS12LDU	BUFFER[130]	// (do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
#define idA2IS12LDU	47	// (do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
#define A2IS21LDU	BUFFER[132]	// (do32_pti:140 - K05DO, - ) Приход на НУ РБ1
#define idA2IS21LDU	48	// (do32_pti:140 - K05DO, - ) Приход на НУ РБ1
#define A2IS32LIM	BUFFER[134]	// ( - , SCM) Клапан cброса РБ1 открыт(обесточен)
#define idA2IS32LIM	49	// ( - , SCM) Клапан cброса РБ1 открыт(обесточен)
#define A2IS33LDU	BUFFER[136]	// ( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
#define idA2IS33LDU	50	// ( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
#define A2VP82LDU	BUFFER[138]	// ( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	51	// ( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define A3AD01LDU	BUFFER[140]	// (vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
#define idA3AD01LDU	52	// (vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
#define A3AD02LDU	BUFFER[142]	// (vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
#define idA3AD02LDU	53	// (vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
#define A3AD03LDU	BUFFER[144]	// (vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
#define idA3AD03LDU	54	// (vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
#define A3AD04LDU	BUFFER[146]	// (vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
#define idA3AD04LDU	55	// (vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
#define A3AD05LDU	BUFFER[148]	// (vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
#define idA3AD05LDU	56	// (vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
#define A3AD11LDU	BUFFER[150]	// (vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	57	// (vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
#define A3AD21LDU	BUFFER[152]	// (vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	58	// (vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
#define A3AD31LDU	BUFFER[154]	// (vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
#define idA3AD31LDU	59	// (vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
#define A3AD33LDU	BUFFER[156]	// (vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
#define idA3AD33LDU	60	// (vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
#define A3AD34LDU	BUFFER[158]	// (vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
#define idA3AD34LDU	61	// (vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
#define A3IC01UDU	BUFFER[160]	// ( - , SDu) Координата штока ИС1
#define idA3IC01UDU	62	// ( - , SDu) Координата штока ИС1
#define A3IP02IDU	BUFFER[165]	// (ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	63	// (ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
#define A3IS11LDU	BUFFER[168]	// (do32_pti:110 - K04DO, - ) Приход на ВУ ИС1
#define idA3IS11LDU	64	// (do32_pti:110 - K04DO, - ) Приход на ВУ ИС1
#define A3IS21LDU	BUFFER[170]	// (do32_pti:140 - K06DO, - ) Приход на НУ ИС1
#define idA3IS21LDU	65	// (do32_pti:140 - K06DO, - ) Приход на НУ ИС1
#define A3IS22LDU	BUFFER[172]	// (do32_pti:110 - K02DO, - ) Приход на НУП ИС1
#define idA3IS22LDU	66	// (do32_pti:110 - K02DO, - ) Приход на НУП ИС1
#define A3IS31LDU	BUFFER[174]	// ( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
#define idA3IS31LDU	67	// ( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
#define A3IS33LDU	BUFFER[176]	// ( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
#define idA3IS33LDU	68	// ( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
#define A3IS35LDU	BUFFER[178]	// ( - , - ) Клапан (ВПИС1) открыт(обесточен)
#define idA3IS35LDU	69	// ( - , - ) Клапан (ВПИС1) открыт(обесточен)
#define A3VP81LDU	BUFFER[180]	// ( - , - ) Давление СПУСК ИС1 в норме
#define idA3VP81LDU	70	// ( - , - ) Давление СПУСК ИС1 в норме
#define A4AD10LDU	BUFFER[182]	// (vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
#define idA4AD10LDU	71	// (vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
#define A4IS10LDU	BUFFER[184]	// ( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
#define idA4IS10LDU	72	// ( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
#define A4IS11LDU	BUFFER[186]	// (do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
#define idA4IS11LDU	73	// (do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
#define A4IS21LDU	BUFFER[188]	// (do32_pti:130 - K17DO, - ) Приход на НУ НИ1
#define idA4IS21LDU	74	// (do32_pti:130 - K17DO, - ) Приход на НУ НИ1
#define A4VP82LDU	BUFFER[190]	// ( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	75	// ( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define A5AD10LDU	BUFFER[192]	// (vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
#define idA5AD10LDU	76	// (vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
#define A5AD20LDU	BUFFER[194]	// (vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
#define idA5AD20LDU	77	// (vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
#define A5IS11LDU	BUFFER[196]	// (do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
#define idA5IS11LDU	78	// (do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
#define A5IS21LDU	BUFFER[198]	// (do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
#define idA5IS21LDU	79	// (do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
#define A5VS12LDU	BUFFER[200]	// ( - , SCM) Движение НЛ1 в сторону ВУ
#define idA5VS12LDU	80	// ( - , SCM) Движение НЛ1 в сторону ВУ
#define A5VS22LDU	BUFFER[202]	// ( - , SCM) Движение НЛ1 в сторону НУ
#define idA5VS22LDU	81	// ( - , SCM) Движение НЛ1 в сторону НУ
#define A6AD10LDU	BUFFER[204]	// (vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
#define idA6AD10LDU	82	// (vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
#define A6AD20LDU	BUFFER[206]	// (vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
#define idA6AD20LDU	83	// (vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
#define A6IS11LDU	BUFFER[208]	// (do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
#define idA6IS11LDU	84	// (do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
#define A6IS21LDU	BUFFER[210]	// (do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
#define idA6IS21LDU	85	// (do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
#define A6VS12LDU	BUFFER[212]	// ( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
#define idA6VS12LDU	86	// ( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
#define A6VS22LDU	BUFFER[214]	// ( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
#define idA6VS22LDU	87	// ( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
#define A7AP31LDU	BUFFER[216]	// (vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
#define idA7AP31LDU	88	// (vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
#define A7AS31LDU	BUFFER[218]	// (do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
#define idA7AS31LDU	89	// (do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
#define A8AD10LDU	BUFFER[220]	// (vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
#define idA8AD10LDU	90	// (vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
#define A8AD20LDU	BUFFER[222]	// (vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
#define idA8AD20LDU	91	// (vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
#define A8IC01UDU	BUFFER[224]	// ( - , SDu) Координата ДС2
#define idA8IC01UDU	92	// ( - , SDu) Координата ДС2
#define A8IS12LDU	BUFFER[229]	// (do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
#define idA8IS12LDU	93	// (do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
#define A8IS22LDU	BUFFER[231]	// (do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
#define idA8IS22LDU	94	// (do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
#define A9AD10LDU	BUFFER[233]	// (vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
#define idA9AD10LDU	95	// (vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
#define A9IS11LDU	BUFFER[235]	// (do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
#define idA9IS11LDU	96	// (do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
#define A9IS21LDU	BUFFER[237]	// (do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
#define idA9IS21LDU	97	// (do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
#define B0IT01IZ1	BUFFER[239]	// (ao16_pti:320 - K03AO, - ) Температура АЗ2-1
#define idB0IT01IZ1	98	// (ao16_pti:320 - K03AO, - ) Температура АЗ2-1
#define B0IT02IZ2	BUFFER[242]	// (ao16_pti:320 - K07AO, - ) Температура АЗ2-2
#define idB0IT02IZ2	99	// (ao16_pti:320 - K07AO, - ) Температура АЗ2-2
#define B0IT03IRP	BUFFER[245]	// (ao16_pti:320 - K12AO, - ) Температура АЗ2-3
#define idB0IT03IRP	100	// (ao16_pti:320 - K12AO, - ) Температура АЗ2-3
#define B0SN02RIM	BUFFER[248]	// ( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
#define idB0SN02RIM	101	// ( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
#define B0SN03RIM	BUFFER[253]	// ( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
#define idB0SN03RIM	102	// ( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
#define B0SN04RIM	BUFFER[258]	// ( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
#define idB0SN04RIM	103	// ( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
#define B0SN05RIM	BUFFER[263]	// ( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
#define idB0SN05RIM	104	// ( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
#define B0SN06RIM	BUFFER[268]	// ( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
#define idB0SN06RIM	105	// ( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
#define B0SN07RIM	BUFFER[273]	// ( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
#define idB0SN07RIM	106	// ( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
#define B0SN08RIM	BUFFER[278]	// ( - , SCM) Поток нейтронов AЗ2(нейтр/с)
#define idB0SN08RIM	107	// ( - , SCM) Поток нейтронов AЗ2(нейтр/с)
#define B0SR01RIM	BUFFER[283]	// ( - , SCM) Текущая реактивность AЗ2
#define idB0SR01RIM	108	// ( - , SCM) Текущая реактивность AЗ2
#define B0VP81LZZ	BUFFER[288]	// (do32_pti:110 - K30DO, - ) Давление АЗ2 в норме
#define idB0VP81LZZ	109	// (do32_pti:110 - K30DO, - ) Давление АЗ2 в норме
#define B1AD01LDU	BUFFER[290]	// (vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
#define idB1AD01LDU	110	// (vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
#define B1AD02LDU	BUFFER[292]	// (vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
#define idB1AD02LDU	111	// (vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
#define B1AD03LDU	BUFFER[294]	// (vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
#define idB1AD03LDU	112	// (vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
#define B1AD04LDU	BUFFER[296]	// (vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
#define idB1AD04LDU	113	// (vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
#define B1AD05LDU	BUFFER[298]	// (vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
#define idB1AD05LDU	114	// (vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
#define B1AD11LDU	BUFFER[300]	// (vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	115	// (vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
#define B1AD21LDU	BUFFER[302]	// (vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	116	// (vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
#define B1AD31LDU	BUFFER[304]	// (vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
#define idB1AD31LDU	117	// (vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
#define B1AD32LDU	BUFFER[306]	// (vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
#define idB1AD32LDU	118	// (vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
#define B1IC01UDU	BUFFER[308]	// ( - , SDu) Координата штока ББ2
#define idB1IC01UDU	119	// ( - , SDu) Координата штока ББ2
#define B1IE03LDU	BUFFER[313]	// ( - , SCM) Движение ББ2 вперед (от БУШД)
#define idB1IE03LDU	120	// ( - , SCM) Движение ББ2 вперед (от БУШД)
#define B1IE04LDU	BUFFER[315]	// ( - , SCM) Движение ББ2 назад (от БУШД)
#define idB1IE04LDU	121	// ( - , SCM) Движение ББ2 назад (от БУШД)
#define B1IS11LDU	BUFFER[317]	// (do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
#define idB1IS11LDU	122	// (do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
#define B1IS11LIM	BUFFER[319]	// ( - , SCM) Магнит ББ2 обесточен
#define idB1IS11LIM	123	// ( - , SCM) Магнит ББ2 обесточен
#define B1IS12LDU	BUFFER[321]	// (do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
#define idB1IS12LDU	124	// (do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
#define B1IS21LDU	BUFFER[323]	// (do32_pti:130 - K09DO, - ) Приход на НУ ББ2
#define idB1IS21LDU	125	// (do32_pti:130 - K09DO, - ) Приход на НУ ББ2
#define B1IS32LIM	BUFFER[325]	// ( - , SCM) Клапан cброса ББ2 открыт(обесточен)
#define idB1IS32LIM	126	// ( - , SCM) Клапан cброса ББ2 открыт(обесточен)
#define B1VP81LZZ	BUFFER[327]	// (do32_pti:110 - K31DO, - ) Давление СБРОС ББ2 в норме
#define idB1VP81LZZ	127	// (do32_pti:110 - K31DO, - ) Давление СБРОС ББ2 в норме
#define B2AD01LDU	BUFFER[329]	// (vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
#define idB2AD01LDU	128	// (vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
#define B2AD02LDU	BUFFER[331]	// (vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
#define idB2AD02LDU	129	// (vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
#define B2AD03LDU	BUFFER[333]	// (vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
#define idB2AD03LDU	130	// (vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
#define B2AD04LDU	BUFFER[335]	// (vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
#define idB2AD04LDU	131	// (vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
#define B2AD05LDU	BUFFER[337]	// (vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
#define idB2AD05LDU	132	// (vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
#define B2AD11LDU	BUFFER[339]	// (vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	133	// (vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
#define B2AD21LDU	BUFFER[341]	// (vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	134	// (vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
#define B2AD31LDU	BUFFER[343]	// (vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
#define idB2AD31LDU	135	// (vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
#define B2AD32LDU	BUFFER[345]	// (vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
#define idB2AD32LDU	136	// (vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
#define B2AD33LDU	BUFFER[347]	// (vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
#define idB2AD33LDU	137	// (vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
#define B2IC01UDU	BUFFER[349]	// ( - , SDu) Координата штока РБ2
#define idB2IC01UDU	138	// ( - , SDu) Координата штока РБ2
#define B2IP01IZ1	BUFFER[354]	// (ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ1	139	// (ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
#define B2IP01IZ2	BUFFER[357]	// (ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ2	140	// (ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
#define B2IS11LDU	BUFFER[360]	// (do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
#define idB2IS11LDU	141	// (do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
#define B2IS11LIM	BUFFER[362]	// ( - , SCM) Магнит РБ2 обесточен
#define idB2IS11LIM	142	// ( - , SCM) Магнит РБ2 обесточен
#define B2IS12LDU	BUFFER[364]	// (do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
#define idB2IS12LDU	143	// (do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
#define B2IS21LDU	BUFFER[366]	// (do32_pti:130 - K12DO, - ) Приход на НУ РБ2
#define idB2IS21LDU	144	// (do32_pti:130 - K12DO, - ) Приход на НУ РБ2
#define B2IS32LIM	BUFFER[368]	// ( - , SCM) Клапан cброса РБ2 открыт(обесточен)
#define idB2IS32LIM	145	// ( - , SCM) Клапан cброса РБ2 открыт(обесточен)
#define B2IS33LDU	BUFFER[370]	// ( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
#define idB2IS33LDU	146	// ( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
#define B2VP82LDU	BUFFER[372]	// ( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define idB2VP82LDU	147	// ( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define B3AD01LDU	BUFFER[374]	// (vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
#define idB3AD01LDU	148	// (vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
#define B3AD02LDU	BUFFER[376]	// (vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
#define idB3AD02LDU	149	// (vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
#define B3AD03LDU	BUFFER[378]	// (vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
#define idB3AD03LDU	150	// (vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
#define B3AD04LDU	BUFFER[380]	// (vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
#define idB3AD04LDU	151	// (vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
#define B3AD05LDU	BUFFER[382]	// (vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
#define idB3AD05LDU	152	// (vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
#define B3AD11LDU	BUFFER[384]	// (vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	153	// (vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
#define B3AD21LDU	BUFFER[386]	// (vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	154	// (vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
#define B3AD31LDU	BUFFER[388]	// (vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
#define idB3AD31LDU	155	// (vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
#define B3AD33LDU	BUFFER[390]	// (vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define idB3AD33LDU	156	// (vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define B3AD34LDU	BUFFER[392]	// (vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
#define idB3AD34LDU	157	// (vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
#define B3IC01UDU	BUFFER[394]	// ( - , SDu) Координата штока ИС2
#define idB3IC01UDU	158	// ( - , SDu) Координата штока ИС2
#define B3IP02IDU	BUFFER[399]	// (ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
#define idB3IP02IDU	159	// (ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
#define B3IS11LDU	BUFFER[402]	// (do32_pti:110 - K11DO, - ) Приход на ВУ ИС2
#define idB3IS11LDU	160	// (do32_pti:110 - K11DO, - ) Приход на ВУ ИС2
#define B3IS21LDU	BUFFER[404]	// (do32_pti:130 - K13DO, - ) Приход на НУ ИС2
#define idB3IS21LDU	161	// (do32_pti:130 - K13DO, - ) Приход на НУ ИС2
#define B3IS22LDU	BUFFER[406]	// (do32_pti:110 - K12DO, - ) Приход на НУП ИС2
#define idB3IS22LDU	162	// (do32_pti:110 - K12DO, - ) Приход на НУП ИС2
#define B3IS31LDU	BUFFER[408]	// ( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
#define idB3IS31LDU	163	// ( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
#define B3IS33LDU	BUFFER[410]	// ( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define idB3IS33LDU	164	// ( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define B3IS35LDU	BUFFER[412]	// ( - , - ) Клапан «ВПИС2» открыт(обесточен)
#define idB3IS35LDU	165	// ( - , - ) Клапан «ВПИС2» открыт(обесточен)
#define B3VP81LDU	BUFFER[414]	// ( - , - ) Давление СПУСК ИС2 в норме
#define idB3VP81LDU	166	// ( - , - ) Давление СПУСК ИС2 в норме
#define B4AD10LDU	BUFFER[416]	// (vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
#define idB4AD10LDU	167	// (vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
#define B4IS10LDU	BUFFER[418]	// ( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
#define idB4IS10LDU	168	// ( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
#define B4IS11LDU	BUFFER[420]	// (do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
#define idB4IS11LDU	169	// (do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
#define B4IS21LDU	BUFFER[422]	// (do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
#define idB4IS21LDU	170	// (do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
#define B4VP82LDU	BUFFER[424]	// ( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	171	// ( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define B5AD10LDU	BUFFER[426]	// (vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
#define idB5AD10LDU	172	// (vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
#define B5AD20LDU	BUFFER[428]	// (vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
#define idB5AD20LDU	173	// (vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
#define B5IS11LDU	BUFFER[430]	// (do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
#define idB5IS11LDU	174	// (do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
#define B5IS21LDU	BUFFER[432]	// (do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
#define idB5IS21LDU	175	// (do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
#define B5VS12LDU	BUFFER[434]	// ( - , SCM) Движение НЛ2 в сторону ВУ
#define idB5VS12LDU	176	// ( - , SCM) Движение НЛ2 в сторону ВУ
#define B5VS22LDU	BUFFER[436]	// ( - , SCM) Движение НЛ2 в сторону НУ
#define idB5VS22LDU	177	// ( - , SCM) Движение НЛ2 в сторону НУ
#define B6AD10LDU	BUFFER[438]	// (vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
#define idB6AD10LDU	178	// (vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
#define B6AD20LDU	BUFFER[440]	// (vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
#define idB6AD20LDU	179	// (vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
#define B6IS11LDU	BUFFER[442]	// (do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
#define idB6IS11LDU	180	// (do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
#define B6IS21LDU	BUFFER[444]	// (do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
#define idB6IS21LDU	181	// (do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
#define B6VS12LDU	BUFFER[446]	// ( - , SCM) Движение створок БЗ2  к ОТКРЫТА
#define idB6VS12LDU	182	// ( - , SCM) Движение створок БЗ2  к ОТКРЫТА
#define B6VS22LDU	BUFFER[448]	// ( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
#define idB6VS22LDU	183	// ( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
#define B7AP31LDU	BUFFER[450]	// (vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
#define idB7AP31LDU	184	// (vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
#define B7AS31LDU	BUFFER[452]	// (do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
#define idB7AS31LDU	185	// (do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
#define B8AD10LDU	BUFFER[454]	// (vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
#define idB8AD10LDU	186	// (vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
#define B8AD20LDU	BUFFER[456]	// (vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
#define idB8AD20LDU	187	// (vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
#define B8IC01UDU	BUFFER[458]	// ( - , SDu) Координата АЗ2, мм
#define idB8IC01UDU	188	// ( - , SDu) Координата АЗ2, мм
#define B8IS11LDU	BUFFER[463]	// (do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
#define idB8IS11LDU	189	// (do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
#define B8IS12LDU	BUFFER[465]	// (do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
#define idB8IS12LDU	190	// (do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
#define B8IS21LDU	BUFFER[467]	// (do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
#define idB8IS21LDU	191	// (do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
#define B8IS22LDU	BUFFER[469]	// (do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
#define idB8IS22LDU	192	// (do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
#define B9AD10LDU	BUFFER[471]	// (vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
#define idB9AD10LDU	193	// (vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
#define B9IS11LDU	BUFFER[473]	// (do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
#define idB9IS11LDU	194	// (do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
#define B9IS21LDU	BUFFER[475]	// (do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
#define idB9IS21LDU	195	// (do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
#define C1MD31LP1	BUFFER[477]	// ( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
#define idC1MD31LP1	196	// ( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
#define C1MD31LP2	BUFFER[479]	// ( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
#define idC1MD31LP2	197	// ( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
#define C2MD31LP1	BUFFER[481]	// ( - , SCM) Кнопка «СБРОС РБ»
#define idC2MD31LP1	198	// ( - , SCM) Кнопка «СБРОС РБ»
#define LTAKTS	BUFFER[483]	// ( - , - ) takt scm
#define idLTAKTS	199	// ( - , - ) takt scm
#define R0AD16LDU	BUFFER[488]	// (vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
#define idR0AD16LDU	200	// (vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
#define R0CR01RIM	BUFFER[490]	// ( - , SCM) Коэффициент 12 связи АЗ1,2
#define idR0CR01RIM	201	// ( - , SCM) Коэффициент 12 связи АЗ1,2
#define R0CR02RIM	BUFFER[495]	// ( - , SCM) Коэффициент 11 связи АЗ1,2
#define idR0CR02RIM	202	// ( - , SCM) Коэффициент 11 связи АЗ1,2
#define R0DEUMLSS	BUFFER[500]	// ( - , SCM) Сигнал управления моделью
#define idR0DEUMLSS	203	// ( - , SCM) Сигнал управления моделью
#define R0EE01LZ1	BUFFER[503]	// ( - , SBz1) Питание  АКНП1  отключить
#define idR0EE01LZ1	204	// ( - , SBz1) Питание  АКНП1  отключить
#define R0EE01LZ2	BUFFER[505]	// ( - , SBz2) Питание  АКНП1  отключить
#define idR0EE01LZ2	205	// ( - , SBz2) Питание  АКНП1  отключить
#define R0EE02LZ1	BUFFER[507]	// ( - , SBz1) Питание  АКНП  отключить
#define idR0EE02LZ1	206	// ( - , SBz1) Питание  АКНП  отключить
#define R0EE02LZ2	BUFFER[509]	// ( - , SBz2) Питание  АКНП  отключить
#define idR0EE02LZ2	207	// ( - , SBz2) Питание  АКНП  отключить
#define R0EE03LZ1	BUFFER[511]	// ( - , SBz1) Питание  АКНП3  отключить
#define idR0EE03LZ1	208	// ( - , SBz1) Питание  АКНП3  отключить
#define R0EE03LZ2	BUFFER[513]	// ( - , SBz2) Питание  АКНП3  отключить
#define idR0EE03LZ2	209	// ( - , SBz2) Питание  АКНП3  отключить
#define R0EE04LZ1	BUFFER[515]	// ( - , SBz1) Питание  АКНП4  отключить
#define idR0EE04LZ1	210	// ( - , SBz1) Питание  АКНП4  отключить
#define R0EE04LZ2	BUFFER[517]	// ( - , SBz2) Питание  АКНП4  отключить
#define idR0EE04LZ2	211	// ( - , SBz2) Питание  АКНП4  отключить
#define R0IN01FI1	BUFFER[519]	// ( - , SA1) Выход СНМ11 Гц от ПТИ
#define idR0IN01FI1	212	// ( - , SA1) Выход СНМ11 Гц от ПТИ
#define R0IN01FI2	BUFFER[524]	// ( - , SA2) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI2	213	// ( - , SA2) Выход СНМ-11 Гц от ПТИ
#define R0IN01FI3	BUFFER[529]	// ( - , SA3) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI3	214	// ( - , SA3) Выход СНМ-11 Гц от ПТИ
#define R0IN01FI4	BUFFER[534]	// ( - , SA4) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI4	215	// ( - , SA4) Выход СНМ-11 Гц от ПТИ
#define R0IN01RIP	BUFFER[539]	// ( - , SRP) Выход СНМ-11 Гц от ПТИ
#define idR0IN01RIP	216	// ( - , SRP) Выход СНМ-11 Гц от ПТИ
#define R0IN02FI1	BUFFER[544]	// ( - , SA1) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI1	217	// ( - , SA1) Выход КНК15-1 Гц от ПТИ
#define R0IN02FI2	BUFFER[549]	// ( - , SA2) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI2	218	// ( - , SA2) Выход КНК15-1 Гц от ПТИ
#define R0IN02FI3	BUFFER[554]	// ( - , SA3) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI3	219	// ( - , SA3) Выход КНК15-1 Гц от ПТИ
#define R0IN02FI4	BUFFER[559]	// ( - , SA4) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI4	220	// ( - , SA4) Выход КНК15-1 Гц от ПТИ
#define R0IN02RIP	BUFFER[564]	// ( - , SRP) Выход КНК15- Гц от ПТИ
#define idR0IN02RIP	221	// ( - , SRP) Выход КНК15- Гц от ПТИ
#define R0IN03FI1	BUFFER[569]	// ( - , SA1) Выход КНК53М Гц от ПТИ
#define idR0IN03FI1	222	// ( - , SA1) Выход КНК53М Гц от ПТИ
#define R0IN03FI2	BUFFER[574]	// ( - , SA2) Выход КНК53М Гц от ПТИ
#define idR0IN03FI2	223	// ( - , SA2) Выход КНК53М Гц от ПТИ
#define R0IN03FI3	BUFFER[579]	// ( - , SA3) Выход КНК53М Гц от ПТИ
#define idR0IN03FI3	224	// ( - , SA3) Выход КНК53М Гц от ПТИ
#define R0IN03FI4	BUFFER[584]	// ( - , SA4) Выход КНК53М Гц от ПТИ
#define idR0IN03FI4	225	// ( - , SA4) Выход КНК53М Гц от ПТИ
#define R0IN03RIP	BUFFER[589]	// ( - , SRP) Выход КНК53М Гц от ПТИ
#define idR0IN03RIP	226	// ( - , SRP) Выход КНК53М Гц от ПТИ
#define R0IN06RIP	BUFFER[594]	// ( - , SRP) Выход СНМ-11-1 Гц от ПТИ
#define idR0IN06RIP	227	// ( - , SRP) Выход СНМ-11-1 Гц от ПТИ
#define R0IN07RIP	BUFFER[599]	// ( - , SRP) Выход СНМ-11-2 Гц от ПТИ
#define idR0IN07RIP	228	// ( - , SRP) Выход СНМ-11-2 Гц от ПТИ
#define R0IS01FI0	BUFFER[604]	// ( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
#define idR0IS01FI0	229	// ( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
#define R0IS02LDU	BUFFER[606]	// (do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
#define idR0IS02LDU	230	// (do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
#define R0MW11IP1	BUFFER[608]	// ( - , SCM) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	231	// ( - , SCM) Переключатель ВЫСТРЕЛ
#define R0MW13LP2	BUFFER[611]	// ( - , SCM) Переключатель «СЕТЬ»
#define idR0MW13LP2	232	// ( - , SCM) Переключатель «СЕТЬ»
#define R0S01LIM	BUFFER[613]	// (vds32_pti:360 - K32VDSR, - ) Отключение сетевых передач ПТИ
#define idR0S01LIM	233	// (vds32_pti:360 - K32VDSR, - ) Отключение сетевых передач ПТИ
#define R0SR01RIM	BUFFER[615]	// ( - , SCM) Текущая реактивность PУ
#define idR0SR01RIM	234	// ( - , SCM) Текущая реактивность PУ
#define R0SR02RIM	BUFFER[620]	// ( - , SCM) Текущая мощность РУ (ватт)
#define idR0SR02RIM	235	// ( - , SCM) Текущая мощность РУ (ватт)
#define R0SR03RIM	BUFFER[625]	// ( - , SCM) Текущая мощность РУ аз1  (ватт)
#define idR0SR03RIM	236	// ( - , SCM) Текущая мощность РУ аз1  (ватт)
#define R0ST01RIM	BUFFER[630]	// ( - , SCM) Текущий период разгона РУ
#define idR0ST01RIM	237	// ( - , SCM) Текущий период разгона РУ
#define R0VZ71LZ1	BUFFER[635]	// ( - , SCM) Обобщенный сигнал по АЗ  1 канала
#define idR0VZ71LZ1	238	// ( - , SCM) Обобщенный сигнал по АЗ  1 канала
#define R0VZ71LZ2	BUFFER[637]	// ( - , SCM) Обобщенный сигнал по АЗ  2 канала
#define idR0VZ71LZ2	239	// ( - , SCM) Обобщенный сигнал по АЗ  2 канала
#define R1AD10LDU	BUFFER[639]	// (vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
#define idR1AD10LDU	240	// (vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
#define R1AD20LDU	BUFFER[641]	// (vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
#define idR1AD20LDU	241	// (vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
#define R1IS11LDU	BUFFER[643]	// (do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
#define idR1IS11LDU	242	// (do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
#define R1IS21LDU	BUFFER[645]	// (do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
#define idR1IS21LDU	243	// (do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
#define R1VS12LDU	BUFFER[647]	// ( - , SCM) Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	244	// ( - , SCM) Движение МДЗ1 в сторону ВУ
#define R1VS22LDU	BUFFER[649]	// ( - , SCM) Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	245	// ( - , SCM) Движение МДЗ1 в сторону НУ
#define R2AD10LDU	BUFFER[651]	// (vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
#define idR2AD10LDU	246	// (vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
#define R2AD20LDU	BUFFER[653]	// (vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
#define idR2AD20LDU	247	// (vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
#define R2IS11LDU	BUFFER[655]	// (do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
#define idR2IS11LDU	248	// (do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
#define R2IS21LDU	BUFFER[657]	// (do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
#define idR2IS21LDU	249	// (do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
#define R2VS12LDU	BUFFER[659]	// ( - , SCM) Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	250	// ( - , SCM) Движение МДЗ2 в сторону ВУ
#define R2VS22LDU	BUFFER[661]	// ( - , SCM) Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	251	// ( - , SCM) Движение МДЗ2 в сторону НУ
#define R3IS11LDU	BUFFER[663]	// (do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
#define idR3IS11LDU	252	// (do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
#define R3IS21LDU	BUFFER[665]	// (do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
#define idR3IS21LDU	253	// (do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
#define R4AD10LDU	BUFFER[667]	// (vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
#define idR4AD10LDU	254	// (vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
#define R4AD20LDU	BUFFER[669]	// (vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
#define idR4AD20LDU	255	// (vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
#define R4IS11LDU	BUFFER[671]	// (do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
#define idR4IS11LDU	256	// (do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
#define R4IS12LDU	BUFFER[673]	// (do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
#define idR4IS12LDU	257	// (do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
#define R4IS21LDU	BUFFER[675]	// (do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
#define idR4IS21LDU	258	// (do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
#define R4IS22LDU	BUFFER[677]	// (do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
#define idR4IS22LDU	259	// (do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
#define R4VS12LDU	BUFFER[679]	// ( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
#define idR4VS12LDU	260	// ( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
#define R4VS22LDU	BUFFER[681]	// ( - , SCM) Движение реактора к «У ЗАЩИТЫ»
#define idR4VS22LDU	261	// ( - , SCM) Движение реактора к «У ЗАЩИТЫ»
#define R5IS11LDU	BUFFER[683]	// (do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	262	// (do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
#define R5IS21LDU	BUFFER[685]	// (do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	263	// (do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
#define R6IS21LDU	BUFFER[687]	// (do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
#define idR6IS21LDU	264	// (do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
#define R6IS62LDU	BUFFER[689]	// ( - , - ) Исправность ВИП ССДИ-39 1канал
#define idR6IS62LDU	265	// ( - , - ) Исправность ВИП ССДИ-39 1канал
#define R6IS63LDU	BUFFER[691]	// ( - , - ) Исправность ВИП ССДИ-39 2канал
#define idR6IS63LDU	266	// ( - , - ) Исправность ВИП ССДИ-39 2канал
#define R6IS64LDU	BUFFER[693]	// ( - , - ) Исправность ВИП ССДИ-35 1канал
#define idR6IS64LDU	267	// ( - , - ) Исправность ВИП ССДИ-35 1канал
#define R6IS65LDU	BUFFER[695]	// ( - , - ) Исправность ВИП ССДИ-35 2канал
#define idR6IS65LDU	268	// ( - , - ) Исправность ВИП ССДИ-35 2канал
#define R6IS66LZZ	BUFFER[697]	// ( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	269	// ( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	BUFFER[699]	// ( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	270	// ( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	BUFFER[701]	// ( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	271	// ( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define R7II71LZ1	BUFFER[703]	// (do32_pti:110 - K08DO, - ) Сработала АС IУР (датчик 1)
#define idR7II71LZ1	272	// (do32_pti:110 - K08DO, - ) Сработала АС IУР (датчик 1)
#define R7II71LZ2	BUFFER[705]	// (do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
#define idR7II71LZ2	273	// (do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
#define R7II72LZ1	BUFFER[707]	// (do32_pti:110 - K07DO, - ) Сработала АС IУР (датчик 2)
#define idR7II72LZ1	274	// (do32_pti:110 - K07DO, - ) Сработала АС IУР (датчик 2)
#define R7II72LZ2	BUFFER[709]	// (do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
#define idR7II72LZ2	275	// (do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
#define R7II73LZ1	BUFFER[711]	// (do32_pti:110 - K09DO, - ) Сработала АС IIУР
#define idR7II73LZ1	276	// (do32_pti:110 - K09DO, - ) Сработала АС IIУР
#define R7II73LZ2	BUFFER[713]	// (do32_pti:110 - K26DO, - ) Сработала АС IIУР
#define idR7II73LZ2	277	// (do32_pti:110 - K26DO, - ) Сработала АС IIУР
#define R8AD21LDU	BUFFER[715]	// (vds32_pti:310 - K31VDSR, - ) Имитация прихода на ВУ ИС для КВДС
#define idR8AD21LDU	278	// (vds32_pti:310 - K31VDSR, - ) Имитация прихода на ВУ ИС для КВДС
#define R8AD22LDU	BUFFER[717]	// (do32_pti:140 - K09DO, - ) Сигнал синхронизации с импульсом
#define idR8AD22LDU	279	// (do32_pti:140 - K09DO, - ) Сигнал синхронизации с импульсом
#define R8IS11LDU	BUFFER[719]	// (do32_pti:130 - K14DO, - ) Аварийный НИ установлен
#define idR8IS11LDU	280	// (do32_pti:130 - K14DO, - ) Аварийный НИ установлен
#define TerR0IN06FRP	BUFFER[721]	// ( - , - ) Неисправности СНМ-11 -1,2
#define idTerR0IN06FRP	281	// ( - , - ) Неисправности СНМ-11 -1,2
#define bFirstEnterFlag	BUFFER[724]	// (bFirstEnterFlag) 
#define idbFirstEnterFlag	282	// (bFirstEnterFlag) 
#define fEM_A0UN01RIM	BUFFER[726]	// (A0UN01RIM) Мощность источника нейтронов ИНИ
#define idfEM_A0UN01RIM	283	// (A0UN01RIM) Мощность источника нейтронов ИНИ
#define fEM_A0UN02RIM	BUFFER[731]	// (A0UN02RIM) Мощность источника нейтронов с АНИ
#define idfEM_A0UN02RIM	284	// (A0UN02RIM) Мощность источника нейтронов с АНИ
#define fEM_A0UN07RIM	BUFFER[736]	// (A0UN07RIM) Доля запаздывающих нейтронов
#define idfEM_A0UN07RIM	285	// (A0UN07RIM) Доля запаздывающих нейтронов
#define fEM_A0UP01RIM	BUFFER[741]	// (A0UP01RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP01RIM	286	// (A0UP01RIM) Текущее давление в АЗ1,2
#define fEM_A0UP02RIM	BUFFER[746]	// (A0UP02RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP02RIM	287	// (A0UP02RIM) Текущее давление в АЗ1,2
#define fEM_A0UR01RSP	BUFFER[751]	// (A0UR01RSP) Стартовая  реактивность АЗ1
#define idfEM_A0UR01RSP	288	// (A0UR01RSP) Стартовая  реактивность АЗ1
#define fEM_A0UR02RSP	BUFFER[756]	// (A0UR02RSP) Стартовый  поток нейтронов АЗ1
#define idfEM_A0UR02RSP	289	// (A0UR02RSP) Стартовый  поток нейтронов АЗ1
#define fEM_A0UT03RSP	BUFFER[761]	// (A0UT03RSP) Стартовая  температура АЗ1 град
#define idfEM_A0UT03RSP	290	// (A0UT03RSP) Стартовая  температура АЗ1 град
#define fEM_A0UX00RSS	BUFFER[766]	// (A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	291	// (A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX01RSS	BUFFER[771]	// (A0UX01RSS) Первый коэффициент калибровки камеры 1
#define idfEM_A0UX01RSS	292	// (A0UX01RSS) Первый коэффициент калибровки камеры 1
#define fEM_A0UX02RSS	BUFFER[776]	// (A0UX02RSS) Первый коэффициент калибровки камеры 2
#define idfEM_A0UX02RSS	293	// (A0UX02RSS) Первый коэффициент калибровки камеры 2
#define fEM_A0UX03RSS	BUFFER[781]	// (A0UX03RSS) Первый коэффициент калибровки камеры 3
#define idfEM_A0UX03RSS	294	// (A0UX03RSS) Первый коэффициент калибровки камеры 3
#define fEM_A0UX04RSS	BUFFER[786]	// (A0UX04RSS) Первый коэффициент калибровки камеры4
#define idfEM_A0UX04RSS	295	// (A0UX04RSS) Первый коэффициент калибровки камеры4
#define fEM_A0UX05RSS	BUFFER[791]	// (A0UX05RSS) Первый коэффициент калибровки камеры 5
#define idfEM_A0UX05RSS	296	// (A0UX05RSS) Первый коэффициент калибровки камеры 5
#define fEM_A0UX06RSS	BUFFER[796]	// (A0UX06RSS) Первый коэффициент калибровки камеры 6
#define idfEM_A0UX06RSS	297	// (A0UX06RSS) Первый коэффициент калибровки камеры 6
#define fEM_A0UX07RSS	BUFFER[801]	// (A0UX07RSS) Первый коэффициент калибровки камеры 7
#define idfEM_A0UX07RSS	298	// (A0UX07RSS) Первый коэффициент калибровки камеры 7
#define fEM_A0UX08RSS	BUFFER[806]	// (A0UX08RSS) Первый коэффициент калибровки камеры 8
#define idfEM_A0UX08RSS	299	// (A0UX08RSS) Первый коэффициент калибровки камеры 8
#define fEM_A0UX09RSS	BUFFER[811]	// (A0UX09RSS) Первый коэффициент калибровки камеры 9
#define idfEM_A0UX09RSS	300	// (A0UX09RSS) Первый коэффициент калибровки камеры 9
#define fEM_A0UX10RSS	BUFFER[816]	// (A0UX10RSS) Первый коэффициент калибровки камеры 10
#define idfEM_A0UX10RSS	301	// (A0UX10RSS) Первый коэффициент калибровки камеры 10
#define fEM_A0UX11RSS	BUFFER[821]	// (A0UX11RSS) Первый коэффициент калибровки камеры 11
#define idfEM_A0UX11RSS	302	// (A0UX11RSS) Первый коэффициент калибровки камеры 11
#define fEM_A0UX12RSS	BUFFER[826]	// (A0UX12RSS) Первый коэффициент калибровки камеры 12
#define idfEM_A0UX12RSS	303	// (A0UX12RSS) Первый коэффициент калибровки камеры 12
#define fEM_A0UX13RSS	BUFFER[831]	// (A0UX13RSS) Первый коэффициент калибровки камеры 13
#define idfEM_A0UX13RSS	304	// (A0UX13RSS) Первый коэффициент калибровки камеры 13
#define fEM_A0UX14RSS	BUFFER[836]	// (A0UX14RSS) Первый коэффициент калибровки камеры 14
#define idfEM_A0UX14RSS	305	// (A0UX14RSS) Первый коэффициент калибровки камеры 14
#define fEM_A0UX15RSS	BUFFER[841]	// (A0UX15RSS) Первый коэффициент калибровки камеры 15
#define idfEM_A0UX15RSS	306	// (A0UX15RSS) Первый коэффициент калибровки камеры 15
#define fEM_A1MC01RC1	BUFFER[846]	// (A1MC01RC1) Заданная координата  ББ1 от ИС
#define idfEM_A1MC01RC1	307	// (A1MC01RC1) Заданная координата  ББ1 от ИС
#define fEM_A1MC01RSP	BUFFER[851]	// (A1MC01RSP) Стартовая координата  ББ1
#define idfEM_A1MC01RSP	308	// (A1MC01RSP) Стартовая координата  ББ1
#define fEM_A1MC02RC1	BUFFER[856]	// (A1MC02RC1) Заданная координата штока ББ1 от ИС
#define idfEM_A1MC02RC1	309	// (A1MC02RC1) Заданная координата штока ББ1 от ИС
#define fEM_A1MC02RSP	BUFFER[861]	// (A1MC02RSP) Стартовая координата штока ББ1
#define idfEM_A1MC02RSP	310	// (A1MC02RSP) Стартовая координата штока ББ1
#define fEM_A1MV01RC1	BUFFER[866]	// (A1MV01RC1) Заданная скорость движения  ББ1 от ИС
#define idfEM_A1MV01RC1	311	// (A1MV01RC1) Заданная скорость движения  ББ1 от ИС
#define fEM_A1MV02RC1	BUFFER[871]	// (A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
#define idfEM_A1MV02RC1	312	// (A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
#define fEM_A1UC02RDU	BUFFER[876]	// (A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define idfEM_A1UC02RDU	313	// (A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define fEM_A1UC03RDU	BUFFER[881]	// (A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define idfEM_A1UC03RDU	314	// (A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define fEM_A1UC04RIM	BUFFER[886]	// (A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define idfEM_A1UC04RIM	315	// (A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define fEM_A1UC05RIM	BUFFER[891]	// (A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define idfEM_A1UC05RIM	316	// (A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define fEM_A1UC06RIM	BUFFER[896]	// (A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define idfEM_A1UC06RIM	317	// (A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define fEM_A1UC08RIM	BUFFER[901]	// (A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define idfEM_A1UC08RIM	318	// (A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define fEM_A1UG01RDU	BUFFER[906]	// (A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define idfEM_A1UG01RDU	319	// (A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define fEM_A1UP01RIM	BUFFER[911]	// (A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define idfEM_A1UP01RIM	320	// (A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define fEM_A1UP82RIM	BUFFER[916]	// (A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define idfEM_A1UP82RIM	321	// (A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define fEM_A1UR00RIM	BUFFER[921]	// (A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR00RIM	322	// (A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define fEM_A1UR01RIM	BUFFER[926]	// (A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR01RIM	323	// (A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define fEM_A1US07RDU	BUFFER[931]	// (A1US07RDU) Постоянная времени масляного демпфера ББ
#define idfEM_A1US07RDU	324	// (A1US07RDU) Постоянная времени масляного демпфера ББ
#define fEM_A1UV02RIM	BUFFER[936]	// (A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define idfEM_A1UV02RIM	325	// (A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define fEM_A2MC01RC1	BUFFER[941]	// (A2MC01RC1) Заданная координата РБ1 от ИС
#define idfEM_A2MC01RC1	326	// (A2MC01RC1) Заданная координата РБ1 от ИС
#define fEM_A2MC01RSP	BUFFER[946]	// (A2MC01RSP) Стартовая координата  РБ1
#define idfEM_A2MC01RSP	327	// (A2MC01RSP) Стартовая координата  РБ1
#define fEM_A2MC02RC1	BUFFER[951]	// (A2MC02RC1) Заданная координата штока РБ1 от ИС
#define idfEM_A2MC02RC1	328	// (A2MC02RC1) Заданная координата штока РБ1 от ИС
#define fEM_A2MC02RSP	BUFFER[956]	// (A2MC02RSP) Стартовая координата штока РБ1
#define idfEM_A2MC02RSP	329	// (A2MC02RSP) Стартовая координата штока РБ1
#define fEM_A2MV01RC1	BUFFER[961]	// (A2MV01RC1) Заданная скорость движения РБ1 от ИС
#define idfEM_A2MV01RC1	330	// (A2MV01RC1) Заданная скорость движения РБ1 от ИС
#define fEM_A2MV02RC1	BUFFER[966]	// (A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define idfEM_A2MV02RC1	331	// (A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define fEM_A2UC02RDU	BUFFER[971]	// (A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define idfEM_A2UC02RDU	332	// (A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define fEM_A2UC03RDU	BUFFER[976]	// (A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define idfEM_A2UC03RDU	333	// (A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define fEM_A2UC04RIM	BUFFER[981]	// (A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define idfEM_A2UC04RIM	334	// (A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define fEM_A2UC05RIM	BUFFER[986]	// (A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define idfEM_A2UC05RIM	335	// (A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define fEM_A2UC06RIM	BUFFER[991]	// (A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define idfEM_A2UC06RIM	336	// (A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define fEM_A2UC08RIM	BUFFER[996]	// (A2UC08RIM) Зона срабатывания КВ  РБ мм
#define idfEM_A2UC08RIM	337	// (A2UC08RIM) Зона срабатывания КВ  РБ мм
#define fEM_A2UG01RDU	BUFFER[1001]	// (A2UG01RDU) Расстояние включения масляного демпфера РБ
#define idfEM_A2UG01RDU	338	// (A2UG01RDU) Расстояние включения масляного демпфера РБ
#define fEM_A2UP01RIM	BUFFER[1006]	// (A2UP01RIM) Текущее давление на сброс РБ
#define idfEM_A2UP01RIM	339	// (A2UP01RIM) Текущее давление на сброс РБ
#define fEM_A2UP02RIM	BUFFER[1011]	// (A2UP02RIM) Текущее давление на подъём РБ
#define idfEM_A2UP02RIM	340	// (A2UP02RIM) Текущее давление на подъём РБ
#define fEM_A2UP03RDU	BUFFER[1016]	// (A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP03RDU	341	// (A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UP03RIM	BUFFER[1021]	// (A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define idfEM_A2UP03RIM	342	// (A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define fEM_A2UP04RDU	BUFFER[1026]	// (A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP04RDU	343	// (A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UR00RIM	BUFFER[1031]	// (A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define idfEM_A2UR00RIM	344	// (A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define fEM_A2UR01RIM	BUFFER[1036]	// (A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define idfEM_A2UR01RIM	345	// (A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define fEM_A2US07RDU	BUFFER[1041]	// (A2US07RDU) Постоянная времени масляного демпфера РБ
#define idfEM_A2US07RDU	346	// (A2US07RDU) Постоянная времени масляного демпфера РБ
#define fEM_A2UV02RIM	BUFFER[1046]	// (A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define idfEM_A2UV02RIM	347	// (A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define fEM_A3MC01RC1	BUFFER[1051]	// (A3MC01RC1) Заданная координата ИС1 от ИС
#define idfEM_A3MC01RC1	348	// (A3MC01RC1) Заданная координата ИС1 от ИС
#define fEM_A3MC01RSP	BUFFER[1056]	// (A3MC01RSP) Стартовая координата  ИС1
#define idfEM_A3MC01RSP	349	// (A3MC01RSP) Стартовая координата  ИС1
#define fEM_A3MC02RC1	BUFFER[1061]	// (A3MC02RC1) Заданная координата штока ИС1 от ИС
#define idfEM_A3MC02RC1	350	// (A3MC02RC1) Заданная координата штока ИС1 от ИС
#define fEM_A3MC02RSP	BUFFER[1066]	// (A3MC02RSP) Стартовая координата штока ИС1
#define idfEM_A3MC02RSP	351	// (A3MC02RSP) Стартовая координата штока ИС1
#define fEM_A3MV01RC1	BUFFER[1071]	// (A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define idfEM_A3MV01RC1	352	// (A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define fEM_A3MV02RC1	BUFFER[1076]	// (A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define idfEM_A3MV02RC1	353	// (A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define fEM_A3UC02RDU	BUFFER[1081]	// (A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define idfEM_A3UC02RDU	354	// (A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define fEM_A3UC03RDU	BUFFER[1086]	// (A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define idfEM_A3UC03RDU	355	// (A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define fEM_A3UC04RIM	BUFFER[1091]	// (A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define idfEM_A3UC04RIM	356	// (A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define fEM_A3UC05RIM	BUFFER[1096]	// (A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC05RIM	357	// (A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define fEM_A3UC06RIM	BUFFER[1101]	// (A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define idfEM_A3UC06RIM	358	// (A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define fEM_A3UC08RIM	BUFFER[1106]	// (A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define idfEM_A3UC08RIM	359	// (A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define fEM_A3UG01RDU	BUFFER[1111]	// (A3UG01RDU) Расстояние включения масляного демпфера ИС
#define idfEM_A3UG01RDU	360	// (A3UG01RDU) Расстояние включения масляного демпфера ИС
#define fEM_A3UP01RIM	BUFFER[1116]	// (A3UP01RIM) Текущее давление на СПУСК ИС
#define idfEM_A3UP01RIM	361	// (A3UP01RIM) Текущее давление на СПУСК ИС
#define fEM_A3UP02RDU	BUFFER[1121]	// (A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define idfEM_A3UP02RDU	362	// (A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define fEM_A3UP02RIM	BUFFER[1126]	// (A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define idfEM_A3UP02RIM	363	// (A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define fEM_A3UP03RDU	BUFFER[1131]	// (A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	364	// (A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	BUFFER[1136]	// (A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	365	// (A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UR00RIM	BUFFER[1141]	// (A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR00RIM	366	// (A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define fEM_A3UR01RIM	BUFFER[1146]	// (A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR01RIM	367	// (A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define fEM_A3US07RDU	BUFFER[1151]	// (A3US07RDU) Постоянная времени масляного демпфера ИС
#define idfEM_A3US07RDU	368	// (A3US07RDU) Постоянная времени масляного демпфера ИС
#define fEM_A3UV02RIM	BUFFER[1156]	// (A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define idfEM_A3UV02RIM	369	// (A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define fEM_A4MC01RSP	BUFFER[1161]	// (A4MC01RSP) Стартовая координата НИ1
#define idfEM_A4MC01RSP	370	// (A4MC01RSP) Стартовая координата НИ1
#define fEM_A4UL10RIM	BUFFER[1166]	// (A4UL10RIM) Время полного перемещения НИ сек
#define idfEM_A4UL10RIM	371	// (A4UL10RIM) Время полного перемещения НИ сек
#define fEM_A4UP01RIM	BUFFER[1171]	// (A4UP01RIM) Текущее давление на подъём НИ
#define idfEM_A4UP01RIM	372	// (A4UP01RIM) Текущее давление на подъём НИ
#define fEM_A4UP02RIM	BUFFER[1176]	// (A4UP02RIM) Нижняя граница давления на подъём НИ
#define idfEM_A4UP02RIM	373	// (A4UP02RIM) Нижняя граница давления на подъём НИ
#define fEM_A5MC01RC1	BUFFER[1181]	// (A5MC01RC1) Заданная координата НЛ1 от ИС
#define idfEM_A5MC01RC1	374	// (A5MC01RC1) Заданная координата НЛ1 от ИС
#define fEM_A5MC01RSP	BUFFER[1186]	// (A5MC01RSP) Стартовая координата НЛ1
#define idfEM_A5MC01RSP	375	// (A5MC01RSP) Стартовая координата НЛ1
#define fEM_A5MV01RC1	BUFFER[1191]	// (A5MV01RC1) Заданная скорость НЛ1 от ИС
#define idfEM_A5MV01RC1	376	// (A5MV01RC1) Заданная скорость НЛ1 от ИС
#define fEM_A5UC10RIM	BUFFER[1196]	// (A5UC10RIM) Время полного хода НЛ сек
#define idfEM_A5UC10RIM	377	// (A5UC10RIM) Время полного хода НЛ сек
#define fEM_A6MC01RC1	BUFFER[1201]	// (A6MC01RC1) Заданная координата БЗ1 от ИС
#define idfEM_A6MC01RC1	378	// (A6MC01RC1) Заданная координата БЗ1 от ИС
#define fEM_A6MC01RSP	BUFFER[1206]	// (A6MC01RSP) Стартовая координата БЗ1
#define idfEM_A6MC01RSP	379	// (A6MC01RSP) Стартовая координата БЗ1
#define fEM_A6MV01RC1	BUFFER[1211]	// (A6MV01RC1) Заданная скорость БЗ1 от ИС
#define idfEM_A6MV01RC1	380	// (A6MV01RC1) Заданная скорость БЗ1 от ИС
#define fEM_A6UC10RIM	BUFFER[1216]	// (A6UC10RIM) Время полного хода БЗ (сек)
#define idfEM_A6UC10RIM	381	// (A6UC10RIM) Время полного хода БЗ (сек)
#define fEM_A6US80RDU	BUFFER[1221]	// (A6US80RDU) Тормозной путь БЗ (мм)
#define idfEM_A6US80RDU	382	// (A6US80RDU) Тормозной путь БЗ (мм)
#define fEM_A8MC01RC1	BUFFER[1226]	// (A8MC01RC1) Заданная координата ДС2 от ИС
#define idfEM_A8MC01RC1	383	// (A8MC01RC1) Заданная координата ДС2 от ИС
#define fEM_A8MC01RSP	BUFFER[1231]	// (A8MC01RSP) Стартовая координата ДС2
#define idfEM_A8MC01RSP	384	// (A8MC01RSP) Стартовая координата ДС2
#define fEM_A8MV01RC1	BUFFER[1236]	// (A8MV01RC1) Заданная скорость ДС2 от ИС
#define idfEM_A8MV01RC1	385	// (A8MV01RC1) Заданная скорость ДС2 от ИС
#define fEM_A8UC03RDU	BUFFER[1241]	// (A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define idfEM_A8UC03RDU	386	// (A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define fEM_A8UC08RDU	BUFFER[1246]	// (A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define idfEM_A8UC08RDU	387	// (A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define fEM_A8UC10RIM	BUFFER[1251]	// (A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define idfEM_A8UC10RIM	388	// (A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define fEM_A8UC11RIM	BUFFER[1256]	// (A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define idfEM_A8UC11RIM	389	// (A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define fEM_A8UC20RIM	BUFFER[1261]	// (A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define idfEM_A8UC20RIM	390	// (A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define fEM_A8UC21RIM	BUFFER[1266]	// (A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define idfEM_A8UC21RIM	391	// (A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define fEM_A8US80RDU	BUFFER[1271]	// (A8US80RDU) Тормозной путь ДС2 (мм)
#define idfEM_A8US80RDU	392	// (A8US80RDU) Тормозной путь ДС2 (мм)
#define fEM_A8UV80RDU	BUFFER[1276]	// (A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define idfEM_A8UV80RDU	393	// (A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define fEM_A9MC01RSP	BUFFER[1281]	// (A9MC01RSP) Стартовая координата НИ ДС1
#define idfEM_A9MC01RSP	394	// (A9MC01RSP) Стартовая координата НИ ДС1
#define fEM_A9UL10RIM	BUFFER[1286]	// (A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define idfEM_A9UL10RIM	395	// (A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define fEM_B0UT03RSP	BUFFER[1291]	// (B0UT03RSP) Стартовая  температура АЗ2 град
#define idfEM_B0UT03RSP	396	// (B0UT03RSP) Стартовая  температура АЗ2 град
#define fEM_B0UX01RSS	BUFFER[1296]	// (B0UX01RSS) Второй коэффициент калибровки камеры 1
#define idfEM_B0UX01RSS	397	// (B0UX01RSS) Второй коэффициент калибровки камеры 1
#define fEM_B0UX02RSS	BUFFER[1301]	// (B0UX02RSS) Второй коэффициент калибровки камеры 2
#define idfEM_B0UX02RSS	398	// (B0UX02RSS) Второй коэффициент калибровки камеры 2
#define fEM_B0UX03RSS	BUFFER[1306]	// (B0UX03RSS) Второй коэффициент калибровки камеры 3
#define idfEM_B0UX03RSS	399	// (B0UX03RSS) Второй коэффициент калибровки камеры 3
#define fEM_B0UX04RSS	BUFFER[1311]	// (B0UX04RSS) Второй коэффициент калибровки камеры 4
#define idfEM_B0UX04RSS	400	// (B0UX04RSS) Второй коэффициент калибровки камеры 4
#define fEM_B0UX05RSS	BUFFER[1316]	// (B0UX05RSS) Второй коэффициент калибровки камеры 5
#define idfEM_B0UX05RSS	401	// (B0UX05RSS) Второй коэффициент калибровки камеры 5
#define fEM_B0UX06RSS	BUFFER[1321]	// (B0UX06RSS) Второй коэффициент калибровки камеры 6
#define idfEM_B0UX06RSS	402	// (B0UX06RSS) Второй коэффициент калибровки камеры 6
#define fEM_B0UX07RSS	BUFFER[1326]	// (B0UX07RSS) Второй коэффициент калибровки камеры 7
#define idfEM_B0UX07RSS	403	// (B0UX07RSS) Второй коэффициент калибровки камеры 7
#define fEM_B0UX08RSS	BUFFER[1331]	// (B0UX08RSS) Второй коэффициент калибровки камеры 8
#define idfEM_B0UX08RSS	404	// (B0UX08RSS) Второй коэффициент калибровки камеры 8
#define fEM_B0UX09RSS	BUFFER[1336]	// (B0UX09RSS) Второй коэффициент калибровки камеры 9
#define idfEM_B0UX09RSS	405	// (B0UX09RSS) Второй коэффициент калибровки камеры 9
#define fEM_B0UX10RSS	BUFFER[1341]	// (B0UX10RSS) Второй коэффициент калибровки камеры 10
#define idfEM_B0UX10RSS	406	// (B0UX10RSS) Второй коэффициент калибровки камеры 10
#define fEM_B0UX11RSS	BUFFER[1346]	// (B0UX11RSS) Второй коэффициент калибровки камеры 11
#define idfEM_B0UX11RSS	407	// (B0UX11RSS) Второй коэффициент калибровки камеры 11
#define fEM_B0UX12RSS	BUFFER[1351]	// (B0UX12RSS) Второй коэффициент калибровки камеры 12
#define idfEM_B0UX12RSS	408	// (B0UX12RSS) Второй коэффициент калибровки камеры 12
#define fEM_B1MC01RC1	BUFFER[1356]	// (B1MC01RC1) Заданная координата ББ2 от ИС
#define idfEM_B1MC01RC1	409	// (B1MC01RC1) Заданная координата ББ2 от ИС
#define fEM_B1MC01RSP	BUFFER[1361]	// (B1MC01RSP) Стартовая координата  ББ2
#define idfEM_B1MC01RSP	410	// (B1MC01RSP) Стартовая координата  ББ2
#define fEM_B1MC02RC1	BUFFER[1366]	// (B1MC02RC1) Заданная координата штока ББ2 от ИС
#define idfEM_B1MC02RC1	411	// (B1MC02RC1) Заданная координата штока ББ2 от ИС
#define fEM_B1MC02RSP	BUFFER[1371]	// (B1MC02RSP) Стартовая координата штока ББ2
#define idfEM_B1MC02RSP	412	// (B1MC02RSP) Стартовая координата штока ББ2
#define fEM_B1MV01RC1	BUFFER[1376]	// (B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define idfEM_B1MV01RC1	413	// (B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define fEM_B1MV02RC1	BUFFER[1381]	// (B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define idfEM_B1MV02RC1	414	// (B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define fEM_B2MC01RC1	BUFFER[1386]	// (B2MC01RC1) Заданная координата РБ2 от ИС
#define idfEM_B2MC01RC1	415	// (B2MC01RC1) Заданная координата РБ2 от ИС
#define fEM_B2MC01RSP	BUFFER[1391]	// (B2MC01RSP) Стартовая координата  РБ2
#define idfEM_B2MC01RSP	416	// (B2MC01RSP) Стартовая координата  РБ2
#define fEM_B2MC02RC1	BUFFER[1396]	// (B2MC02RC1) Заданная координата штока РБ2 от ИС
#define idfEM_B2MC02RC1	417	// (B2MC02RC1) Заданная координата штока РБ2 от ИС
#define fEM_B2MC02RSP	BUFFER[1401]	// (B2MC02RSP) Стартовая координата штока РБ2
#define idfEM_B2MC02RSP	418	// (B2MC02RSP) Стартовая координата штока РБ2
#define fEM_B2MV01RC1	BUFFER[1406]	// (B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define idfEM_B2MV01RC1	419	// (B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define fEM_B2MV02RC1	BUFFER[1411]	// (B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define idfEM_B2MV02RC1	420	// (B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define fEM_B3MC01RC1	BUFFER[1416]	// (B3MC01RC1) Заданная координата ИС2 от ИС
#define idfEM_B3MC01RC1	421	// (B3MC01RC1) Заданная координата ИС2 от ИС
#define fEM_B3MC01RSP	BUFFER[1421]	// (B3MC01RSP) Стартовая координата  ИС2
#define idfEM_B3MC01RSP	422	// (B3MC01RSP) Стартовая координата  ИС2
#define fEM_B3MC02RC1	BUFFER[1426]	// (B3MC02RC1) Заданная координата штока ИС2 от ИС
#define idfEM_B3MC02RC1	423	// (B3MC02RC1) Заданная координата штока ИС2 от ИС
#define fEM_B3MC02RSP	BUFFER[1431]	// (B3MC02RSP) Стартовая координата штока ИС2
#define idfEM_B3MC02RSP	424	// (B3MC02RSP) Стартовая координата штока ИС2
#define fEM_B3MV01RC1	BUFFER[1436]	// (B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define idfEM_B3MV01RC1	425	// (B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define fEM_B3MV02RC1	BUFFER[1441]	// (B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define idfEM_B3MV02RC1	426	// (B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define fEM_B4MC01RSP	BUFFER[1446]	// (B4MC01RSP) Стартовая координата НИ2
#define idfEM_B4MC01RSP	427	// (B4MC01RSP) Стартовая координата НИ2
#define fEM_B5MC01RC1	BUFFER[1451]	// (B5MC01RC1) Заданная координата НЛ2 от ИС
#define idfEM_B5MC01RC1	428	// (B5MC01RC1) Заданная координата НЛ2 от ИС
#define fEM_B5MC01RSP	BUFFER[1456]	// (B5MC01RSP) Стартовая координата НЛ2
#define idfEM_B5MC01RSP	429	// (B5MC01RSP) Стартовая координата НЛ2
#define fEM_B5MV01RC1	BUFFER[1461]	// (B5MV01RC1) Заданная скорость НЛ2 от ИС
#define idfEM_B5MV01RC1	430	// (B5MV01RC1) Заданная скорость НЛ2 от ИС
#define fEM_B6MC01RC1	BUFFER[1466]	// (B6MC01RC1) Заданная координата БЗ2 от ИС
#define idfEM_B6MC01RC1	431	// (B6MC01RC1) Заданная координата БЗ2 от ИС
#define fEM_B6MC01RSP	BUFFER[1471]	// (B6MC01RSP) Стартовая координата БЗ2
#define idfEM_B6MC01RSP	432	// (B6MC01RSP) Стартовая координата БЗ2
#define fEM_B6MV01RC1	BUFFER[1476]	// (B6MV01RC1) Заданная скорость БЗ2 от ИС
#define idfEM_B6MV01RC1	433	// (B6MV01RC1) Заданная скорость БЗ2 от ИС
#define fEM_B8MC01RC1	BUFFER[1481]	// (B8MC01RC1) Заданная координата АЗ2 от ИС
#define idfEM_B8MC01RC1	434	// (B8MC01RC1) Заданная координата АЗ2 от ИС
#define fEM_B8MC01RSP	BUFFER[1486]	// (B8MC01RSP) Стартовая координата АЗ2
#define idfEM_B8MC01RSP	435	// (B8MC01RSP) Стартовая координата АЗ2
#define fEM_B8MV01RC1	BUFFER[1491]	// (B8MV01RC1) Заданная скорость АЗ2 от ИС
#define idfEM_B8MV01RC1	436	// (B8MV01RC1) Заданная скорость АЗ2 от ИС
#define fEM_B8UC08RDU	BUFFER[1496]	// (B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define idfEM_B8UC08RDU	437	// (B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define fEM_B8UC10RIM	BUFFER[1501]	// (B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define idfEM_B8UC10RIM	438	// (B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define fEM_B8UC11RIM	BUFFER[1506]	// (B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define idfEM_B8UC11RIM	439	// (B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define fEM_B8UC20RIM	BUFFER[1511]	// (B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define idfEM_B8UC20RIM	440	// (B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define fEM_B8UC21RIM	BUFFER[1516]	// (B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define idfEM_B8UC21RIM	441	// (B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define fEM_B8US80RDU	BUFFER[1521]	// (B8US80RDU) Тормозной путь АЗ2 (мм)
#define idfEM_B8US80RDU	442	// (B8US80RDU) Тормозной путь АЗ2 (мм)
#define fEM_B8UV80RDU	BUFFER[1526]	// (B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define idfEM_B8UV80RDU	443	// (B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define fEM_B9MC01RSP	BUFFER[1531]	// (B9MC01RSP) Стартовая координата НИ ДС2
#define idfEM_B9MC01RSP	444	// (B9MC01RSP) Стартовая координата НИ ДС2
#define fEM_R0UH01RSS	BUFFER[1536]	// (R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
#define idfEM_R0UH01RSS	445	// (R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
#define fEM_R0UH02RSS	BUFFER[1541]	// (R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define idfEM_R0UH02RSS	446	// (R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define fEM_R0UH03RSS	BUFFER[1546]	// (R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define idfEM_R0UH03RSS	447	// (R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define fEM_R0UH05RSS	BUFFER[1551]	// (R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	448	// (R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_R0UH21RSS	BUFFER[1556]	// (R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define idfEM_R0UH21RSS	449	// (R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define fEM_R0UH22RSS	BUFFER[1561]	// (R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define idfEM_R0UH22RSS	450	// (R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define fEM_R0UH23RSS	BUFFER[1566]	// (R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define idfEM_R0UH23RSS	451	// (R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define fEM_R0UL01RIM	BUFFER[1571]	// (R0UL01RIM) Среднее время генерации нейтронов
#define idfEM_R0UL01RIM	452	// (R0UL01RIM) Среднее время генерации нейтронов
#define fEM_R0UL02RDU	BUFFER[1576]	// (R0UL02RDU) Время задержки  ИНИ
#define idfEM_R0UL02RDU	453	// (R0UL02RDU) Время задержки  ИНИ
#define fEM_R0UL02RIM	BUFFER[1581]	// (R0UL02RIM) Время удержания синхроимпульса
#define idfEM_R0UL02RIM	454	// (R0UL02RIM) Время удержания синхроимпульса
#define fEM_R0UL04RIM	BUFFER[1586]	// (R0UL04RIM) Время блокировки повторной генерации импульса
#define idfEM_R0UL04RIM	455	// (R0UL04RIM) Время блокировки повторной генерации импульса
#define fEM_R0UN02RIM	BUFFER[1591]	// (R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define idfEM_R0UN02RIM	456	// (R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define fEM_R0UN18RDU	BUFFER[1596]	// (R0UN18RDU) Коэффициент температурной корректировки реактивности(долл)
#define idfEM_R0UN18RDU	457	// (R0UN18RDU) Коэффициент температурной корректировки реактивности(долл)
#define fEM_R0UR01RIM	BUFFER[1601]	// (R0UR01RIM) Стартовая отрицательная реактивность
#define idfEM_R0UR01RIM	458	// (R0UR01RIM) Стартовая отрицательная реактивность
#define fEM_R0UR30RIM	BUFFER[1606]	// (R0UR30RIM) Реактивность вносимая образцами (долл)
#define idfEM_R0UR30RIM	459	// (R0UR30RIM) Реактивность вносимая образцами (долл)
#define fEM_R0UT01RDU	BUFFER[1611]	// (R0UT01RDU) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RDU	460	// (R0UT01RDU) Нижний предел шкалы датчика температуры
#define fEM_R0UT02RDU	BUFFER[1616]	// (R0UT02RDU) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RDU	461	// (R0UT02RDU) Верхний предел шкалы датчика температуры
#define fEM_R0UT02RIM	BUFFER[1621]	// (R0UT02RIM) Масса топлива в АЗ
#define idfEM_R0UT02RIM	462	// (R0UT02RIM) Масса топлива в АЗ
#define fEM_R0UT03RIM	BUFFER[1626]	// (R0UT03RIM) Нормальная температура АЗ град
#define idfEM_R0UT03RIM	463	// (R0UT03RIM) Нормальная температура АЗ град
#define fEM_R0UT04RIM	BUFFER[1631]	// (R0UT04RIM) Удельная теплоёмкость топлива
#define idfEM_R0UT04RIM	464	// (R0UT04RIM) Удельная теплоёмкость топлива
#define fEM_R0UT05RIM	BUFFER[1636]	// (R0UT05RIM) Энергия деления ядра
#define idfEM_R0UT05RIM	465	// (R0UT05RIM) Энергия деления ядра
#define fEM_R0UT06RIM	BUFFER[1641]	// (R0UT06RIM) Конвекционное сопротивление при обдуве
#define idfEM_R0UT06RIM	466	// (R0UT06RIM) Конвекционное сопротивление при обдуве
#define fEM_R0UV81RDU	BUFFER[1646]	// (R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	467	// (R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	BUFFER[1651]	// (R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	468	// (R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	BUFFER[1656]	// (R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	469	// (R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	BUFFER[1661]	// (R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	470	// (R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define fEM_R0UV85RDU	BUFFER[1666]	// (R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	471	// (R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV86RDU	BUFFER[1671]	// (R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	472	// (R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV87RDU	BUFFER[1676]	// (R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	473	// (R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R1MC01RC1	BUFFER[1681]	// (R1MC01RC1) Заданная координата МДЗ1 от ИС
#define idfEM_R1MC01RC1	474	// (R1MC01RC1) Заданная координата МДЗ1 от ИС
#define fEM_R1MC01RSP	BUFFER[1686]	// (R1MC01RSP) Стартовая координата МДЗ1
#define idfEM_R1MC01RSP	475	// (R1MC01RSP) Стартовая координата МДЗ1
#define fEM_R1MV01RC1	BUFFER[1691]	// (R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define idfEM_R1MV01RC1	476	// (R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define fEM_R1UC10RIM	BUFFER[1696]	// (R1UC10RIM) Время полного хода МДЗ сек
#define idfEM_R1UC10RIM	477	// (R1UC10RIM) Время полного хода МДЗ сек
#define fEM_R2MC01RC1	BUFFER[1701]	// (R2MC01RC1) Заданная координата МДЗ2 от ИС
#define idfEM_R2MC01RC1	478	// (R2MC01RC1) Заданная координата МДЗ2 от ИС
#define fEM_R2MC01RSP	BUFFER[1706]	// (R2MC01RSP) Стартовая координата МДЗ2
#define idfEM_R2MC01RSP	479	// (R2MC01RSP) Стартовая координата МДЗ2
#define fEM_R2MV01RC1	BUFFER[1711]	// (R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define idfEM_R2MV01RC1	480	// (R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define fEM_R3UC01RSP	BUFFER[1716]	// (R3UC01RSP) Стартовая координата Гомогенных дверей
#define idfEM_R3UC01RSP	481	// (R3UC01RSP) Стартовая координата Гомогенных дверей
#define fEM_R3UL10RIM	BUFFER[1721]	// (R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define idfEM_R3UL10RIM	482	// (R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define fEM_R4MC01RC1	BUFFER[1726]	// (R4MC01RC1) Заданная координата тележки от ИС
#define idfEM_R4MC01RC1	483	// (R4MC01RC1) Заданная координата тележки от ИС
#define fEM_R4MC01RSP	BUFFER[1731]	// (R4MC01RSP) Стартовая координата тележки
#define idfEM_R4MC01RSP	484	// (R4MC01RSP) Стартовая координата тележки
#define fEM_R4MV01RC1	BUFFER[1736]	// (R4MV01RC1) Заданная скорость тележки от ИС
#define idfEM_R4MV01RC1	485	// (R4MV01RC1) Заданная скорость тележки от ИС
#define fEM_R4UC08RDU	BUFFER[1741]	// (R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define idfEM_R4UC08RDU	486	// (R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define fEM_R4UC10RIM	BUFFER[1746]	// (R4UC10RIM) Координата верхних механических упоров тележки мм
#define idfEM_R4UC10RIM	487	// (R4UC10RIM) Координата верхних механических упоров тележки мм
#define fEM_R4UC20RIM	BUFFER[1751]	// (R4UC20RIM) Координата нижних механических упоров тележки мм
#define idfEM_R4UC20RIM	488	// (R4UC20RIM) Координата нижних механических упоров тележки мм
#define fEM_R4UC22RIM	BUFFER[1756]	// (R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define idfEM_R4UC22RIM	489	// (R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define fEM_R4US80RDU	BUFFER[1761]	// (R4US80RDU) Тормозной путь тележки (мм)
#define idfEM_R4US80RDU	490	// (R4US80RDU) Тормозной путь тележки (мм)
#define fEM_R4UV80RDU	BUFFER[1766]	// (R4UV80RDU) Номинальная скорость тележки (см/с)
#define idfEM_R4UV80RDU	491	// (R4UV80RDU) Номинальная скорость тележки (см/с)
#define fEM_R5UC01RSP	BUFFER[1771]	// (R5UC01RSP) Стартовая координата Ворот отстойной зоны
#define idfEM_R5UC01RSP	492	// (R5UC01RSP) Стартовая координата Ворот отстойной зоны
#define fEM_R5UL10RIM	BUFFER[1776]	// (R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define idfEM_R5UL10RIM	493	// (R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define fEM_R6UC01RSP	BUFFER[1781]	// (R6UC01RSP) Стартовая координата Кран-балки
#define idfEM_R6UC01RSP	494	// (R6UC01RSP) Стартовая координата Кран-балки
#define fEM_R6UL10RIM	BUFFER[1786]	// (R6UL10RIM) Время полного хода кран-балки сек
#define idfEM_R6UL10RIM	495	// (R6UL10RIM) Время полного хода кран-балки сек
#define fEM_R7UC10RIM	BUFFER[1791]	// (R7UC10RIM) X-координата КНК53М R7IN13 см
#define idfEM_R7UC10RIM	496	// (R7UC10RIM) X-координата КНК53М R7IN13 см
#define fEM_R7UC19RIM	BUFFER[1796]	// (R7UC19RIM) Y-координата СНМ-11 (11) см
#define idfEM_R7UC19RIM	497	// (R7UC19RIM) Y-координата СНМ-11 (11) см
#define fEM_R7UI02RIM	BUFFER[1801]	// (R7UI02RIM) Коэффициент усиления уровня радиации
#define idfEM_R7UI02RIM	498	// (R7UI02RIM) Коэффициент усиления уровня радиации
#define fEM_R7UI71RIM	BUFFER[1806]	// (R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define idfEM_R7UI71RIM	499	// (R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define fEM_R7UI72RIM	BUFFER[1811]	// (R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
#define idfEM_R7UI72RIM	500	// (R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
#define fEM_R7UI73RIM	BUFFER[1816]	// (R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define idfEM_R7UI73RIM	501	// (R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define fEM_R7UI74RIM	BUFFER[1821]	// (R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define idfEM_R7UI74RIM	502	// (R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define fEM_R7UI75RIM	BUFFER[1826]	// (R7UI75RIM) Множитель к уровню радиации
#define idfEM_R7UI75RIM	503	// (R7UI75RIM) Множитель к уровню радиации
#define fEM_R7UI76RIM	BUFFER[1831]	// (R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define idfEM_R7UI76RIM	504	// (R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define fEM_R7UI77RIM	BUFFER[1836]	// (R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define idfEM_R7UI77RIM	505	// (R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define fEM_R7UL01RIM	BUFFER[1841]	// (R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define idfEM_R7UL01RIM	506	// (R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define fEM_R7UX01RSS	BUFFER[1846]	// (R7UX01RSS) X-координата камеры R7IN11
#define idfEM_R7UX01RSS	507	// (R7UX01RSS) X-координата камеры R7IN11
#define fEM_R7UX02RSS	BUFFER[1851]	// (R7UX02RSS) X-координата камеры R7IN12 (см)
#define idfEM_R7UX02RSS	508	// (R7UX02RSS) X-координата камеры R7IN12 (см)
#define fEM_R7UX04RSS	BUFFER[1856]	// (R7UX04RSS) X-координата камеры R7IN21 (см)
#define idfEM_R7UX04RSS	509	// (R7UX04RSS) X-координата камеры R7IN21 (см)
#define fEM_R7UX05RSS	BUFFER[1861]	// (R7UX05RSS) X-координата камеры R7IN22 (см)
#define idfEM_R7UX05RSS	510	// (R7UX05RSS) X-координата камеры R7IN22 (см)
#define fEM_R7UX06RSS	BUFFER[1866]	// (R7UX06RSS) X-координата камеры R7IN23 (см)
#define idfEM_R7UX06RSS	511	// (R7UX06RSS) X-координата камеры R7IN23 (см)
#define fEM_R7UX07RSS	BUFFER[1871]	// (R7UX07RSS) X-координата камеры R7IN31 (см)
#define idfEM_R7UX07RSS	512	// (R7UX07RSS) X-координата камеры R7IN31 (см)
#define fEM_R7UX08RSS	BUFFER[1876]	// (R7UX08RSS) X-координата камеры R7IN32 (см)
#define idfEM_R7UX08RSS	513	// (R7UX08RSS) X-координата камеры R7IN32 (см)
#define fEM_R7UX09RSS	BUFFER[1881]	// (R7UX09RSS) X-координата камеры R7IN33 (см)
#define idfEM_R7UX09RSS	514	// (R7UX09RSS) X-координата камеры R7IN33 (см)
#define fEM_R7UX10RSS	BUFFER[1886]	// (R7UX10RSS) X-координата камеры R7IN41
#define idfEM_R7UX10RSS	515	// (R7UX10RSS) X-координата камеры R7IN41
#define fEM_R7UX11RSS	BUFFER[1891]	// (R7UX11RSS) X-координата камеры R7IN42
#define idfEM_R7UX11RSS	516	// (R7UX11RSS) X-координата камеры R7IN42
#define fEM_R7UX12RSS	BUFFER[1896]	// (R7UX12RSS) X-координата камеры R7IN43
#define idfEM_R7UX12RSS	517	// (R7UX12RSS) X-координата камеры R7IN43
#define fEM_R7UX13RSS	BUFFER[1901]	// (R7UX13RSS) X-координата камеры R7IN51
#define idfEM_R7UX13RSS	518	// (R7UX13RSS) X-координата камеры R7IN51
#define fEM_R7UX14RSS	BUFFER[1906]	// (R7UX14RSS) X-координата камеры R7IN52
#define idfEM_R7UX14RSS	519	// (R7UX14RSS) X-координата камеры R7IN52
#define fEM_R7UX15RSS	BUFFER[1911]	// (R7UX15RSS) X-координата камеры R7IN53
#define idfEM_R7UX15RSS	520	// (R7UX15RSS) X-координата камеры R7IN53
#define fEM_R7UX16RSS	BUFFER[1916]	// (R7UX16RSS) Величина сигнала СНМ11 в БЗ
#define idfEM_R7UX16RSS	521	// (R7UX16RSS) Величина сигнала СНМ11 в БЗ
#define fEM_R7UY00RSS	BUFFER[1921]	// (R7UY00RSS) Y-координата АЗ1 см
#define idfEM_R7UY00RSS	522	// (R7UY00RSS) Y-координата АЗ1 см
#define fEM_R7UY01RSS	BUFFER[1926]	// (R7UY01RSS) Y-координата камеры R7IN11
#define idfEM_R7UY01RSS	523	// (R7UY01RSS) Y-координата камеры R7IN11
#define fEM_R7UY02RSS	BUFFER[1931]	// (R7UY02RSS) Y-координата камеры R7IN12 (см)
#define idfEM_R7UY02RSS	524	// (R7UY02RSS) Y-координата камеры R7IN12 (см)
#define fEM_R7UY04RSS	BUFFER[1936]	// (R7UY04RSS) Y-координата камеры R7IN21 (см)
#define idfEM_R7UY04RSS	525	// (R7UY04RSS) Y-координата камеры R7IN21 (см)
#define fEM_R7UY05RSS	BUFFER[1941]	// (R7UY05RSS) Y-координата камеры R7IN22 (см)
#define idfEM_R7UY05RSS	526	// (R7UY05RSS) Y-координата камеры R7IN22 (см)
#define fEM_R7UY06RSS	BUFFER[1946]	// (R7UY06RSS) Y-координата камеры R7IN23 (см)
#define idfEM_R7UY06RSS	527	// (R7UY06RSS) Y-координата камеры R7IN23 (см)
#define fEM_R7UY07RSS	BUFFER[1951]	// (R7UY07RSS) Y-координата камеры R7IN31 (см)
#define idfEM_R7UY07RSS	528	// (R7UY07RSS) Y-координата камеры R7IN31 (см)
#define fEM_R7UY08RSS	BUFFER[1956]	// (R7UY08RSS) Y-координата камеры R7IN32 (см)
#define idfEM_R7UY08RSS	529	// (R7UY08RSS) Y-координата камеры R7IN32 (см)
#define fEM_R7UY09RSS	BUFFER[1961]	// (R7UY09RSS) Y-координата камеры R7IN33 (см)
#define idfEM_R7UY09RSS	530	// (R7UY09RSS) Y-координата камеры R7IN33 (см)
#define fEM_R7UY10RSS	BUFFER[1966]	// (R7UY10RSS) Y-координата камеры R7IN41
#define idfEM_R7UY10RSS	531	// (R7UY10RSS) Y-координата камеры R7IN41
#define fEM_R7UY11RSS	BUFFER[1971]	// (R7UY11RSS) Y-координата камеры R7IN42
#define idfEM_R7UY11RSS	532	// (R7UY11RSS) Y-координата камеры R7IN42
#define fEM_R7UY12RSS	BUFFER[1976]	// (R7UY12RSS) Y-координата камеры R7IN43
#define idfEM_R7UY12RSS	533	// (R7UY12RSS) Y-координата камеры R7IN43
#define fEM_R7UY13RSS	BUFFER[1981]	// (R7UY13RSS) Y-координата камеры R7IN51
#define idfEM_R7UY13RSS	534	// (R7UY13RSS) Y-координата камеры R7IN51
#define fEM_R7UY14RSS	BUFFER[1986]	// (R7UY14RSS) Y-координата камеры R7IN52
#define idfEM_R7UY14RSS	535	// (R7UY14RSS) Y-координата камеры R7IN52
#define fEM_R7UY15RSS	BUFFER[1991]	// (R7UY15RSS) Y-координата камеры R7IN53
#define idfEM_R7UY15RSS	536	// (R7UY15RSS) Y-координата камеры R7IN53
#define iEM_TERA0MT01RIM	BUFFER[1996]	// (TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define idiEM_TERA0MT01RIM	537	// (TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define iEM_TERA0VP81LIM	BUFFER[1999]	// (TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define idiEM_TERA0VP81LIM	538	// (TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define iEM_TERA1IE03LDU	BUFFER[2002]	// (TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define idiEM_TERA1IE03LDU	539	// (TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define iEM_TERA1IE04LDU	BUFFER[2005]	// (TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define idiEM_TERA1IE04LDU	540	// (TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define iEM_TERA1SC01RIM	BUFFER[2008]	// (TERA1SC01RIM) Искажение: Координата штока ББ1
#define idiEM_TERA1SC01RIM	541	// (TERA1SC01RIM) Искажение: Координата штока ББ1
#define iEM_TERA1SS11LIM	BUFFER[2011]	// (TERA1SS11LIM) Искажение: Приход на ВУ ББ1
#define idiEM_TERA1SS11LIM	542	// (TERA1SS11LIM) Искажение: Приход на ВУ ББ1
#define iEM_TERA1SS12LIM	BUFFER[2014]	// (TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define idiEM_TERA1SS12LIM	543	// (TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define iEM_TERA1SS21LIM	BUFFER[2017]	// (TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define idiEM_TERA1SS21LIM	544	// (TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define iEM_TERA1VP81LIM	BUFFER[2020]	// (TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define idiEM_TERA1VP81LIM	545	// (TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define iEM_TERA2SC01RIM	BUFFER[2023]	// (TERA2SC01RIM) Искажение: Координата штока РБ1
#define idiEM_TERA2SC01RIM	546	// (TERA2SC01RIM) Искажение: Координата штока РБ1
#define iEM_TERA2SP01RIM	BUFFER[2026]	// (TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define idiEM_TERA2SP01RIM	547	// (TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define iEM_TERA2SS11LIM	BUFFER[2029]	// (TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define idiEM_TERA2SS11LIM	548	// (TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define iEM_TERA2SS12LIM	BUFFER[2032]	// (TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define idiEM_TERA2SS12LIM	549	// (TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define iEM_TERA2SS21LIM	BUFFER[2035]	// (TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define idiEM_TERA2SS21LIM	550	// (TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define iEM_TERA2SS33LIM	BUFFER[2038]	// (TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define idiEM_TERA2SS33LIM	551	// (TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define iEM_TERA2VP82LIM	BUFFER[2041]	// (TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define idiEM_TERA2VP82LIM	552	// (TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define iEM_TERA3SC01RIM	BUFFER[2044]	// (TERA3SC01RIM) Искажение: Координата штока ИС1
#define idiEM_TERA3SC01RIM	553	// (TERA3SC01RIM) Искажение: Координата штока ИС1
#define iEM_TERA3SP02RIM	BUFFER[2047]	// (TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define idiEM_TERA3SP02RIM	554	// (TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define iEM_TERA3SS11LIM	BUFFER[2050]	// (TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define idiEM_TERA3SS11LIM	555	// (TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define iEM_TERA3SS21LIM	BUFFER[2053]	// (TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define idiEM_TERA3SS21LIM	556	// (TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define iEM_TERA3SS22LIM	BUFFER[2056]	// (TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define idiEM_TERA3SS22LIM	557	// (TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define iEM_TERA3SS31LIM	BUFFER[2059]	// (TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define idiEM_TERA3SS31LIM	558	// (TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define iEM_TERA3SS33LIM	BUFFER[2062]	// (TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define idiEM_TERA3SS33LIM	559	// (TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define iEM_TERA3VP81LIM	BUFFER[2065]	// (TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define idiEM_TERA3VP81LIM	560	// (TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define iEM_TERA4SS11LIM	BUFFER[2068]	// (TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define idiEM_TERA4SS11LIM	561	// (TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define iEM_TERA4SS21LIM	BUFFER[2071]	// (TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define idiEM_TERA4SS21LIM	562	// (TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define iEM_TERA4VP82LIM	BUFFER[2074]	// (TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define idiEM_TERA4VP82LIM	563	// (TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define iEM_TERA5SS11LIM	BUFFER[2077]	// (TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
#define idiEM_TERA5SS11LIM	564	// (TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
#define iEM_TERA5SS21LIM	BUFFER[2080]	// (TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define idiEM_TERA5SS21LIM	565	// (TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define iEM_TERA5VS12LIM	BUFFER[2083]	// (TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
#define idiEM_TERA5VS12LIM	566	// (TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
#define iEM_TERA5VS22LIM	BUFFER[2086]	// (TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
#define idiEM_TERA5VS22LIM	567	// (TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
#define iEM_TERA6MS11LIM	BUFFER[2089]	// (TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define idiEM_TERA6MS11LIM	568	// (TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define iEM_TERA6SS21LIM	BUFFER[2092]	// (TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define idiEM_TERA6SS21LIM	569	// (TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define iEM_TERA6VS12LIM	BUFFER[2095]	// (TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
#define idiEM_TERA6VS12LIM	570	// (TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
#define iEM_TERA6VS22LIM	BUFFER[2098]	// (TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
#define idiEM_TERA6VS22LIM	571	// (TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
#define iEM_TERA7MS31LIM	BUFFER[2101]	// (TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define idiEM_TERA7MS31LIM	572	// (TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define iEM_TERA8SC01RIM	BUFFER[2104]	// (TERA8SC01RIM) Искажение: Координата ДС2
#define idiEM_TERA8SC01RIM	573	// (TERA8SC01RIM) Искажение: Координата ДС2
#define iEM_TERA8SS12LIM	BUFFER[2107]	// (TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define idiEM_TERA8SS12LIM	574	// (TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define iEM_TERA8SS22LIM	BUFFER[2110]	// (TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define idiEM_TERA8SS22LIM	575	// (TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define iEM_TERA9SS11LIM	BUFFER[2113]	// (TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define idiEM_TERA9SS11LIM	576	// (TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define iEM_TERA9SS21LIM	BUFFER[2116]	// (TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define idiEM_TERA9SS21LIM	577	// (TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define iEM_TERB0MT01RIM	BUFFER[2119]	// (TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define idiEM_TERB0MT01RIM	578	// (TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define iEM_TERB0VP81LIM	BUFFER[2122]	// (TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define idiEM_TERB0VP81LIM	579	// (TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define iEM_TERB1IE03LDU	BUFFER[2125]	// (TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define idiEM_TERB1IE03LDU	580	// (TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define iEM_TERB1IE04LDU	BUFFER[2128]	// (TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define idiEM_TERB1IE04LDU	581	// (TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define iEM_TERB1MC01RIM	BUFFER[2131]	// (TERB1MC01RIM) Искажение: Координата штока ББ2
#define idiEM_TERB1MC01RIM	582	// (TERB1MC01RIM) Искажение: Координата штока ББ2
#define iEM_TERB1SS11LIM	BUFFER[2134]	// (TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define idiEM_TERB1SS11LIM	583	// (TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define iEM_TERB1SS12LIM	BUFFER[2137]	// (TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define idiEM_TERB1SS12LIM	584	// (TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define iEM_TERB1SS21LIM	BUFFER[2140]	// (TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define idiEM_TERB1SS21LIM	585	// (TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define iEM_TERB1VP81LIM	BUFFER[2143]	// (TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define idiEM_TERB1VP81LIM	586	// (TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define iEM_TERB2SC01RIM	BUFFER[2146]	// (TERB2SC01RIM) Искажение: Координата штока РБ2
#define idiEM_TERB2SC01RIM	587	// (TERB2SC01RIM) Искажение: Координата штока РБ2
#define iEM_TERB2SP01RIM	BUFFER[2149]	// (TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define idiEM_TERB2SP01RIM	588	// (TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define iEM_TERB2SS11LIM	BUFFER[2152]	// (TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define idiEM_TERB2SS11LIM	589	// (TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define iEM_TERB2SS12LIM	BUFFER[2155]	// (TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define idiEM_TERB2SS12LIM	590	// (TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define iEM_TERB2SS21LIM	BUFFER[2158]	// (TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define idiEM_TERB2SS21LIM	591	// (TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define iEM_TERB2SS33LIM	BUFFER[2161]	// (TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define idiEM_TERB2SS33LIM	592	// (TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define iEM_TERB3SC01RIM	BUFFER[2164]	// (TERB3SC01RIM) Искажение: Координата штока ИС2
#define idiEM_TERB3SC01RIM	593	// (TERB3SC01RIM) Искажение: Координата штока ИС2
#define iEM_TERB3SP02RIM	BUFFER[2167]	// (TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define idiEM_TERB3SP02RIM	594	// (TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define iEM_TERB3SS11LIM	BUFFER[2170]	// (TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define idiEM_TERB3SS11LIM	595	// (TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define iEM_TERB3SS21LIM	BUFFER[2173]	// (TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define idiEM_TERB3SS21LIM	596	// (TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define iEM_TERB3SS22LIM	BUFFER[2176]	// (TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define idiEM_TERB3SS22LIM	597	// (TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define iEM_TERB3SS31LIM	BUFFER[2179]	// (TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define idiEM_TERB3SS31LIM	598	// (TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define iEM_TERB3SS33LIM	BUFFER[2182]	// (TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define idiEM_TERB3SS33LIM	599	// (TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define iEM_TERB4SS11LIM	BUFFER[2185]	// (TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define idiEM_TERB4SS11LIM	600	// (TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define iEM_TERB4SS21LIM	BUFFER[2188]	// (TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define idiEM_TERB4SS21LIM	601	// (TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define iEM_TERB5SS11LIM	BUFFER[2191]	// (TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define idiEM_TERB5SS11LIM	602	// (TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define iEM_TERB5SS21LIM	BUFFER[2194]	// (TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define idiEM_TERB5SS21LIM	603	// (TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define iEM_TERB5VS12LIM	BUFFER[2197]	// (TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
#define idiEM_TERB5VS12LIM	604	// (TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
#define iEM_TERB5VS22LIM	BUFFER[2200]	// (TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
#define idiEM_TERB5VS22LIM	605	// (TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
#define iEM_TERB6SS11LIM	BUFFER[2203]	// (TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define idiEM_TERB6SS11LIM	606	// (TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define iEM_TERB6SS21LIM	BUFFER[2206]	// (TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define idiEM_TERB6SS21LIM	607	// (TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define iEM_TERB6VS12LIM	BUFFER[2209]	// (TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
#define idiEM_TERB6VS12LIM	608	// (TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
#define iEM_TERB6VS22LIM	BUFFER[2212]	// (TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
#define idiEM_TERB6VS22LIM	609	// (TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
#define iEM_TERB7MS31LIM	BUFFER[2215]	// (TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
#define idiEM_TERB7MS31LIM	610	// (TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
#define iEM_TERB8SC01RIM	BUFFER[2218]	// (TERB8SC01RIM) Искажение: Координата АЗ2
#define idiEM_TERB8SC01RIM	611	// (TERB8SC01RIM) Искажение: Координата АЗ2
#define iEM_TERB8SS12LIM	BUFFER[2221]	// (TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define idiEM_TERB8SS12LIM	612	// (TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define iEM_TERB8SS22LIM	BUFFER[2224]	// (TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define idiEM_TERB8SS22LIM	613	// (TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define iEM_TERB9SS11LIM	BUFFER[2227]	// (TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define idiEM_TERB9SS11LIM	614	// (TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define iEM_TERB9SS21LIM	BUFFER[2230]	// (TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
#define idiEM_TERB9SS21LIM	615	// (TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
#define iEM_TERBB1	BUFFER[2233]	// (TERBB1) Неисправности  ББ1
#define idiEM_TERBB1	616	// (TERBB1) Неисправности  ББ1
#define iEM_TERBB2	BUFFER[2236]	// (TERBB2) Неисправности  ББ2
#define idiEM_TERBB2	617	// (TERBB2) Неисправности  ББ2
#define iEM_TERBZ1	BUFFER[2239]	// (TERBZ1) Неисправности БЗ1
#define idiEM_TERBZ1	618	// (TERBZ1) Неисправности БЗ1
#define iEM_TERBZ2	BUFFER[2242]	// (TERBZ2) Неисправности БЗ2
#define idiEM_TERBZ2	619	// (TERBZ2) Неисправности БЗ2
#define iEM_TERDS2	BUFFER[2245]	// (TERDS2) Неисправности ДС2 от ИС
#define idiEM_TERDS2	620	// (TERDS2) Неисправности ДС2 от ИС
#define iEM_TERIS1	BUFFER[2248]	// (TERIS1) Неисправности  ИС1
#define idiEM_TERIS1	621	// (TERIS1) Неисправности  ИС1
#define iEM_TERIS2	BUFFER[2251]	// (TERIS2) Неисправности  ИС2
#define idiEM_TERIS2	622	// (TERIS2) Неисправности  ИС2
#define iEM_TERMAZ2	BUFFER[2254]	// (TERMAZ2) Неисправности АЗ2 от ИС
#define idiEM_TERMAZ2	623	// (TERMAZ2) Неисправности АЗ2 от ИС
#define iEM_TERMDZ1	BUFFER[2257]	// (TERMDZ1) Неисправности МДЗ1
#define idiEM_TERMDZ1	624	// (TERMDZ1) Неисправности МДЗ1
#define iEM_TERMDZ2	BUFFER[2260]	// (TERMDZ2) Неисправности МДЗ2
#define idiEM_TERMDZ2	625	// (TERMDZ2) Неисправности МДЗ2
#define iEM_TERNL1	BUFFER[2263]	// (TERNL1) Неисправности НЛ1
#define idiEM_TERNL1	626	// (TERNL1) Неисправности НЛ1
#define iEM_TERNL2	BUFFER[2266]	// (TERNL2) Неисправности НЛ2
#define idiEM_TERNL2	627	// (TERNL2) Неисправности НЛ2
#define iEM_TERR0VP81LIM	BUFFER[2269]	// (TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
#define idiEM_TERR0VP81LIM	628	// (TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
#define iEM_TERR1SS11LIM	BUFFER[2272]	// (TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define idiEM_TERR1SS11LIM	629	// (TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define iEM_TERR1SS21LIM	BUFFER[2275]	// (TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define idiEM_TERR1SS21LIM	630	// (TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define iEM_TERR1VS12LIM	BUFFER[2278]	// (TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
#define idiEM_TERR1VS12LIM	631	// (TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
#define iEM_TERR1VS22LIM	BUFFER[2281]	// (TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
#define idiEM_TERR1VS22LIM	632	// (TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
#define iEM_TERR2SS11LIM	BUFFER[2284]	// (TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define idiEM_TERR2SS11LIM	633	// (TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define iEM_TERR2SS21LIM	BUFFER[2287]	// (TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define idiEM_TERR2SS21LIM	634	// (TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define iEM_TERR2VS12LIM	BUFFER[2290]	// (TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
#define idiEM_TERR2VS12LIM	635	// (TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
#define iEM_TERR2VS22LIM	BUFFER[2293]	// (TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
#define idiEM_TERR2VS22LIM	636	// (TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
#define iEM_TERR3SS11LIM	BUFFER[2296]	// (TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define idiEM_TERR3SS11LIM	637	// (TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define iEM_TERR3SS21LIM	BUFFER[2299]	// (TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define idiEM_TERR3SS21LIM	638	// (TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define iEM_TERR4MS21LIM	BUFFER[2302]	// (TERR4MS21LIM) Искажение: Приход на НУ тележки
#define idiEM_TERR4MS21LIM	639	// (TERR4MS21LIM) Искажение: Приход на НУ тележки
#define iEM_TERR4SS11LIM	BUFFER[2305]	// (TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define idiEM_TERR4SS11LIM	640	// (TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define iEM_TERR4SS12LIM	BUFFER[2308]	// (TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define idiEM_TERR4SS12LIM	641	// (TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define iEM_TERR4SS22LIM	BUFFER[2311]	// (TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define idiEM_TERR4SS22LIM	642	// (TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define iEM_TERR4VS12LDU	BUFFER[2314]	// (TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define idiEM_TERR4VS12LDU	643	// (TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define iEM_TERR4VS22LDU	BUFFER[2317]	// (TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define idiEM_TERR4VS22LDU	644	// (TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define iEM_TERR5SS11LIM	BUFFER[2320]	// (TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define idiEM_TERR5SS11LIM	645	// (TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define iEM_TERR5SS21LIM	BUFFER[2323]	// (TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
#define idiEM_TERR5SS21LIM	646	// (TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
#define iEM_TERR6IS62LIM	BUFFER[2326]	// (TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
#define idiEM_TERR6IS62LIM	647	// (TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
#define iEM_TERR6IS64LIM	BUFFER[2329]	// (TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
#define idiEM_TERR6IS64LIM	648	// (TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
#define iEM_TERR6IS66LIM	BUFFER[2332]	// (TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idiEM_TERR6IS66LIM	649	// (TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define iEM_TERR6IS67LIM	BUFFER[2335]	// (TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idiEM_TERR6IS67LIM	650	// (TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
#define iEM_TERR6IS68LIM	BUFFER[2338]	// (TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
#define idiEM_TERR6IS68LIM	651	// (TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
#define iEM_TERR6SS21LIM	BUFFER[2341]	// (TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
#define idiEM_TERR6SS21LIM	652	// (TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
#define iEM_TERR7SI74RIM	BUFFER[2344]	// (TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define idiEM_TERR7SI74RIM	653	// (TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define iEM_TERR8SS11LIM	BUFFER[2347]	// (TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define idiEM_TERR8SS11LIM	654	// (TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define iEM_TERRB1	BUFFER[2350]	// (TERRB1) Неисправности  РБ1
#define idiEM_TERRB1	655	// (TERRB1) Неисправности  РБ1
#define iEM_TERRB2	BUFFER[2353]	// (TERRB2) Неисправности  РБ2
#define idiEM_TERRB2	656	// (TERRB2) Неисправности  РБ2
#define iEM_TERTLG	BUFFER[2356]	// (TERTLG) Неисправности  тележки от ИС
#define idiEM_TERTLG	657	// (TERTLG) Неисправности  тележки от ИС
#define internal1_m100_MyFirstEnterFlag	BUFFER[2359]	// (internal1_m100_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m100_MyFirstEnterFlag	658	// (internal1_m100_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m100_Pav0	BUFFER[2361]	// (internal1_m100_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m100_Pav0	659	// (internal1_m100_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m100_Ppv0	BUFFER[2363]	// (internal1_m100_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m100_Ppv0	660	// (internal1_m100_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m100_RA00	BUFFER[2365]	// (internal1_m100_RA00) RA00 - последнее задание вперед
#define idinternal1_m100_RA00	661	// (internal1_m100_RA00) RA00 - последнее задание вперед
#define internal1_m100_RA10	BUFFER[2367]	// (internal1_m100_RA10) RA10 - последнее задание назад
#define idinternal1_m100_RA10	662	// (internal1_m100_RA10) RA10 - последнее задание назад
#define internal1_m100_RA30	BUFFER[2369]	// (internal1_m100_RA30)  RA30 - разрешение движения
#define idinternal1_m100_RA30	663	// (internal1_m100_RA30)  RA30 - разрешение движения
#define internal1_m100_RA50	BUFFER[2371]	// (internal1_m100_RA50) Ra50 - последнее задание скорости
#define idinternal1_m100_RA50	664	// (internal1_m100_RA50) Ra50 - последнее задание скорости
#define internal1_m100_RV00	BUFFER[2373]	// (internal1_m100_RV00) V0 - текущая скорость ОРР
#define idinternal1_m100_RV00	665	// (internal1_m100_RV00) V0 - текущая скорость ОРР
#define internal1_m100_Sh00	BUFFER[2378]	// (internal1_m100_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m100_Sh00	666	// (internal1_m100_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m100_ShV00	BUFFER[2383]	// (internal1_m100_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m100_ShV00	667	// (internal1_m100_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m100_X00	BUFFER[2388]	// (internal1_m100_X00) X0 - текущая координата ОРР
#define idinternal1_m100_X00	668	// (internal1_m100_X00) X0 - текущая координата ОРР
#define internal1_m100_Zav0	BUFFER[2393]	// (internal1_m100_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m100_Zav0	669	// (internal1_m100_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m100_flp	BUFFER[2395]	// (internal1_m100_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m100_flp	670	// (internal1_m100_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m100_fls	BUFFER[2397]	// (internal1_m100_fls)  fls - флаг одношагового режима
#define idinternal1_m100_fls	671	// (internal1_m100_fls)  fls - флаг одношагового режима
#define internal1_m1012_Out10	BUFFER[2399]	// (internal1_m1012_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1012_Out10	672	// (internal1_m1012_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1013_Out10	BUFFER[2401]	// (internal1_m1013_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1013_Out10	673	// (internal1_m1013_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1014_Out10	BUFFER[2403]	// (internal1_m1014_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1014_Out10	674	// (internal1_m1014_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1015_Out10	BUFFER[2405]	// (internal1_m1015_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1015_Out10	675	// (internal1_m1015_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1016_Out10	BUFFER[2407]	// (internal1_m1016_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1016_Out10	676	// (internal1_m1016_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1017_Out10	BUFFER[2409]	// (internal1_m1017_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1017_Out10	677	// (internal1_m1017_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1018_Out10	BUFFER[2411]	// (internal1_m1018_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1018_Out10	678	// (internal1_m1018_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1032_Out10	BUFFER[2413]	// (internal1_m1032_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1032_Out10	679	// (internal1_m1032_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1033_Out10	BUFFER[2415]	// (internal1_m1033_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1033_Out10	680	// (internal1_m1033_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1034_Out10	BUFFER[2417]	// (internal1_m1034_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1034_Out10	681	// (internal1_m1034_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1035_Out10	BUFFER[2419]	// (internal1_m1035_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1035_Out10	682	// (internal1_m1035_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1036_Out10	BUFFER[2421]	// (internal1_m1036_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1036_Out10	683	// (internal1_m1036_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1037_Out10	BUFFER[2423]	// (internal1_m1037_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1037_Out10	684	// (internal1_m1037_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m136_MyFirstEnterFlag	BUFFER[2425]	// (internal1_m136_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m136_MyFirstEnterFlag	685	// (internal1_m136_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m136_Pav0	BUFFER[2427]	// (internal1_m136_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m136_Pav0	686	// (internal1_m136_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m136_Ppv0	BUFFER[2429]	// (internal1_m136_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m136_Ppv0	687	// (internal1_m136_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m136_RA00	BUFFER[2431]	// (internal1_m136_RA00) RA00 - последнее задание вперед
#define idinternal1_m136_RA00	688	// (internal1_m136_RA00) RA00 - последнее задание вперед
#define internal1_m136_RA10	BUFFER[2433]	// (internal1_m136_RA10) RA10 - последнее задание назад
#define idinternal1_m136_RA10	689	// (internal1_m136_RA10) RA10 - последнее задание назад
#define internal1_m136_RA30	BUFFER[2435]	// (internal1_m136_RA30)  RA30 - разрешение движения
#define idinternal1_m136_RA30	690	// (internal1_m136_RA30)  RA30 - разрешение движения
#define internal1_m136_RA50	BUFFER[2437]	// (internal1_m136_RA50) Ra50 - последнее задание скорости
#define idinternal1_m136_RA50	691	// (internal1_m136_RA50) Ra50 - последнее задание скорости
#define internal1_m136_RV00	BUFFER[2439]	// (internal1_m136_RV00) V0 - текущая скорость ОРР
#define idinternal1_m136_RV00	692	// (internal1_m136_RV00) V0 - текущая скорость ОРР
#define internal1_m136_Sh00	BUFFER[2444]	// (internal1_m136_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m136_Sh00	693	// (internal1_m136_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m136_ShV00	BUFFER[2449]	// (internal1_m136_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m136_ShV00	694	// (internal1_m136_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m136_X00	BUFFER[2454]	// (internal1_m136_X00) X0 - текущая координата ОРР
#define idinternal1_m136_X00	695	// (internal1_m136_X00) X0 - текущая координата ОРР
#define internal1_m136_Zav0	BUFFER[2459]	// (internal1_m136_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m136_Zav0	696	// (internal1_m136_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m136_flp	BUFFER[2461]	// (internal1_m136_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m136_flp	697	// (internal1_m136_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m136_fls	BUFFER[2463]	// (internal1_m136_fls)  fls - флаг одношагового режима
#define idinternal1_m136_fls	698	// (internal1_m136_fls)  fls - флаг одношагового режима
#define internal1_m14_C1	BUFFER[2465]	// (internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m14_C1	699	// (internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m14_C2	BUFFER[2470]	// (internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m14_C2	700	// (internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m14_C3	BUFFER[2475]	// (internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m14_C3	701	// (internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m14_C4	BUFFER[2480]	// (internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m14_C4	702	// (internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m14_C5	BUFFER[2485]	// (internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m14_C5	703	// (internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m14_C6	BUFFER[2490]	// (internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m14_C6	704	// (internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m14_ImpINI0	BUFFER[2495]	// (internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m14_ImpINI0	705	// (internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m14_MyFirstEnterFlag	BUFFER[2497]	// (internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m14_MyFirstEnterFlag	706	// (internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m14_N00	BUFFER[2499]	// (internal1_m14_N00) N00 - Текущая концентрация нейтронов
#define idinternal1_m14_N00	707	// (internal1_m14_N00) N00 - Текущая концентрация нейтронов
#define internal1_m14_N20	BUFFER[2504]	// (internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m14_N20	708	// (internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m14_R00	BUFFER[2509]	// (internal1_m14_R00) R00 - Текущая реактивность
#define idinternal1_m14_R00	709	// (internal1_m14_R00) R00 - Текущая реактивность
#define internal1_m14_T00	BUFFER[2514]	// (internal1_m14_T00) T00 - Текущая температура
#define idinternal1_m14_T00	710	// (internal1_m14_T00) T00 - Текущая температура
#define internal1_m151_Out10	BUFFER[2519]	// (internal1_m151_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m151_Out10	711	// (internal1_m151_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m152_Out10	BUFFER[2521]	// (internal1_m152_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m152_Out10	712	// (internal1_m152_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m176_x0	BUFFER[2523]	// (internal1_m176_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m176_x0	713	// (internal1_m176_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m186_C1	BUFFER[2528]	// (internal1_m186_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m186_C1	714	// (internal1_m186_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m186_C2	BUFFER[2533]	// (internal1_m186_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m186_C2	715	// (internal1_m186_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m186_C3	BUFFER[2538]	// (internal1_m186_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m186_C3	716	// (internal1_m186_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m186_C4	BUFFER[2543]	// (internal1_m186_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m186_C4	717	// (internal1_m186_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m186_C5	BUFFER[2548]	// (internal1_m186_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m186_C5	718	// (internal1_m186_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m186_C6	BUFFER[2553]	// (internal1_m186_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m186_C6	719	// (internal1_m186_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m186_ImpINI0	BUFFER[2558]	// (internal1_m186_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m186_ImpINI0	720	// (internal1_m186_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m186_MyFirstEnterFlag	BUFFER[2560]	// (internal1_m186_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m186_MyFirstEnterFlag	721	// (internal1_m186_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m186_N00	BUFFER[2562]	// (internal1_m186_N00) N00 - Текущая концентрация нейтронов
#define idinternal1_m186_N00	722	// (internal1_m186_N00) N00 - Текущая концентрация нейтронов
#define internal1_m186_N20	BUFFER[2567]	// (internal1_m186_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m186_N20	723	// (internal1_m186_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m186_R00	BUFFER[2572]	// (internal1_m186_R00) R00 - Текущая реактивность
#define idinternal1_m186_R00	724	// (internal1_m186_R00) R00 - Текущая реактивность
#define internal1_m186_T00	BUFFER[2577]	// (internal1_m186_T00) T00 - Текущая температура
#define idinternal1_m186_T00	725	// (internal1_m186_T00) T00 - Текущая температура
#define internal1_m211_Out10	BUFFER[2582]	// (internal1_m211_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m211_Out10	726	// (internal1_m211_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m228_Out10	BUFFER[2584]	// (internal1_m228_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m228_Out10	727	// (internal1_m228_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m232_MyFirstEnterFlag	BUFFER[2586]	// (internal1_m232_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m232_MyFirstEnterFlag	728	// (internal1_m232_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m232_Pav0	BUFFER[2588]	// (internal1_m232_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m232_Pav0	729	// (internal1_m232_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m232_Ppv0	BUFFER[2590]	// (internal1_m232_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m232_Ppv0	730	// (internal1_m232_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m232_RA00	BUFFER[2592]	// (internal1_m232_RA00) RA00 - последнее задание вперед
#define idinternal1_m232_RA00	731	// (internal1_m232_RA00) RA00 - последнее задание вперед
#define internal1_m232_RA10	BUFFER[2594]	// (internal1_m232_RA10) RA10 - последнее задание назад
#define idinternal1_m232_RA10	732	// (internal1_m232_RA10) RA10 - последнее задание назад
#define internal1_m232_RA30	BUFFER[2596]	// (internal1_m232_RA30)  RA30 - разрешение движения
#define idinternal1_m232_RA30	733	// (internal1_m232_RA30)  RA30 - разрешение движения
#define internal1_m232_RA50	BUFFER[2598]	// (internal1_m232_RA50) Ra50 - последнее задание скорости
#define idinternal1_m232_RA50	734	// (internal1_m232_RA50) Ra50 - последнее задание скорости
#define internal1_m232_RV00	BUFFER[2600]	// (internal1_m232_RV00) V0 - текущая скорость ОРР
#define idinternal1_m232_RV00	735	// (internal1_m232_RV00) V0 - текущая скорость ОРР
#define internal1_m232_Sh00	BUFFER[2605]	// (internal1_m232_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m232_Sh00	736	// (internal1_m232_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m232_ShV00	BUFFER[2610]	// (internal1_m232_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m232_ShV00	737	// (internal1_m232_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m232_X00	BUFFER[2615]	// (internal1_m232_X00) X0 - текущая координата ОРР
#define idinternal1_m232_X00	738	// (internal1_m232_X00) X0 - текущая координата ОРР
#define internal1_m232_Zav0	BUFFER[2620]	// (internal1_m232_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m232_Zav0	739	// (internal1_m232_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m232_flp	BUFFER[2622]	// (internal1_m232_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m232_flp	740	// (internal1_m232_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m232_fls	BUFFER[2624]	// (internal1_m232_fls)  fls - флаг одношагового режима
#define idinternal1_m232_fls	741	// (internal1_m232_fls)  fls - флаг одношагового режима
#define internal1_m270_MyFirstEnterFlag	BUFFER[2626]	// (internal1_m270_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m270_MyFirstEnterFlag	742	// (internal1_m270_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m270_Pav0	BUFFER[2628]	// (internal1_m270_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m270_Pav0	743	// (internal1_m270_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m270_Ppv0	BUFFER[2630]	// (internal1_m270_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m270_Ppv0	744	// (internal1_m270_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m270_RA00	BUFFER[2632]	// (internal1_m270_RA00) RA00 - последнее задание вперед
#define idinternal1_m270_RA00	745	// (internal1_m270_RA00) RA00 - последнее задание вперед
#define internal1_m270_RA10	BUFFER[2634]	// (internal1_m270_RA10) RA10 - последнее задание назад
#define idinternal1_m270_RA10	746	// (internal1_m270_RA10) RA10 - последнее задание назад
#define internal1_m270_RA30	BUFFER[2636]	// (internal1_m270_RA30)  RA30 - разрешение движения
#define idinternal1_m270_RA30	747	// (internal1_m270_RA30)  RA30 - разрешение движения
#define internal1_m270_RA50	BUFFER[2638]	// (internal1_m270_RA50) Ra50 - последнее задание скорости
#define idinternal1_m270_RA50	748	// (internal1_m270_RA50) Ra50 - последнее задание скорости
#define internal1_m270_RV00	BUFFER[2640]	// (internal1_m270_RV00) V0 - текущая скорость ОРР
#define idinternal1_m270_RV00	749	// (internal1_m270_RV00) V0 - текущая скорость ОРР
#define internal1_m270_Sh00	BUFFER[2645]	// (internal1_m270_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m270_Sh00	750	// (internal1_m270_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m270_ShV00	BUFFER[2650]	// (internal1_m270_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m270_ShV00	751	// (internal1_m270_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m270_X00	BUFFER[2655]	// (internal1_m270_X00) X0 - текущая координата ОРР
#define idinternal1_m270_X00	752	// (internal1_m270_X00) X0 - текущая координата ОРР
#define internal1_m270_Zav0	BUFFER[2660]	// (internal1_m270_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m270_Zav0	753	// (internal1_m270_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m270_flp	BUFFER[2662]	// (internal1_m270_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m270_flp	754	// (internal1_m270_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m270_fls	BUFFER[2664]	// (internal1_m270_fls)  fls - флаг одношагового режима
#define idinternal1_m270_fls	755	// (internal1_m270_fls)  fls - флаг одношагового режима
#define internal1_m303_MyFirstEnterFlag	BUFFER[2666]	// (internal1_m303_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m303_MyFirstEnterFlag	756	// (internal1_m303_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m303_Pav0	BUFFER[2668]	// (internal1_m303_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m303_Pav0	757	// (internal1_m303_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m303_Ppv0	BUFFER[2670]	// (internal1_m303_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m303_Ppv0	758	// (internal1_m303_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m303_RA00	BUFFER[2672]	// (internal1_m303_RA00) RA00 - последнее задание вперед
#define idinternal1_m303_RA00	759	// (internal1_m303_RA00) RA00 - последнее задание вперед
#define internal1_m303_RA10	BUFFER[2674]	// (internal1_m303_RA10) RA10 - последнее задание назад
#define idinternal1_m303_RA10	760	// (internal1_m303_RA10) RA10 - последнее задание назад
#define internal1_m303_RA30	BUFFER[2676]	// (internal1_m303_RA30)  RA30 - разрешение движения
#define idinternal1_m303_RA30	761	// (internal1_m303_RA30)  RA30 - разрешение движения
#define internal1_m303_RA50	BUFFER[2678]	// (internal1_m303_RA50) Ra50 - последнее задание скорости
#define idinternal1_m303_RA50	762	// (internal1_m303_RA50) Ra50 - последнее задание скорости
#define internal1_m303_RV00	BUFFER[2680]	// (internal1_m303_RV00) V0 - текущая скорость ОРР
#define idinternal1_m303_RV00	763	// (internal1_m303_RV00) V0 - текущая скорость ОРР
#define internal1_m303_Sh00	BUFFER[2685]	// (internal1_m303_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m303_Sh00	764	// (internal1_m303_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m303_ShV00	BUFFER[2690]	// (internal1_m303_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m303_ShV00	765	// (internal1_m303_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m303_X00	BUFFER[2695]	// (internal1_m303_X00) X0 - текущая координата ОРР
#define idinternal1_m303_X00	766	// (internal1_m303_X00) X0 - текущая координата ОРР
#define internal1_m303_Zav0	BUFFER[2700]	// (internal1_m303_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m303_Zav0	767	// (internal1_m303_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m303_flp	BUFFER[2702]	// (internal1_m303_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m303_flp	768	// (internal1_m303_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m303_fls	BUFFER[2704]	// (internal1_m303_fls)  fls - флаг одношагового режима
#define idinternal1_m303_fls	769	// (internal1_m303_fls)  fls - флаг одношагового режима
#define internal1_m319_Out10	BUFFER[2706]	// (internal1_m319_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m319_Out10	770	// (internal1_m319_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m320_Out10	BUFFER[2708]	// (internal1_m320_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m320_Out10	771	// (internal1_m320_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m321_Out10	BUFFER[2710]	// (internal1_m321_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m321_Out10	772	// (internal1_m321_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m326_Xtek0	BUFFER[2712]	// (internal1_m326_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m326_Xtek0	773	// (internal1_m326_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m334_Xtek0	BUFFER[2717]	// (internal1_m334_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m334_Xtek0	774	// (internal1_m334_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m335_Out10	BUFFER[2722]	// (internal1_m335_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m335_Out10	775	// (internal1_m335_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m336_Out10	BUFFER[2724]	// (internal1_m336_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m336_Out10	776	// (internal1_m336_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m337_Out10	BUFFER[2726]	// (internal1_m337_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m337_Out10	777	// (internal1_m337_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m347_Out10	BUFFER[2728]	// (internal1_m347_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m347_Out10	778	// (internal1_m347_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m348_Out10	BUFFER[2730]	// (internal1_m348_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m348_Out10	779	// (internal1_m348_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m349_Out10	BUFFER[2732]	// (internal1_m349_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m349_Out10	780	// (internal1_m349_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m350_Out10	BUFFER[2734]	// (internal1_m350_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m350_Out10	781	// (internal1_m350_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m364_MyFirstEnterFlag	BUFFER[2736]	// (internal1_m364_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m364_MyFirstEnterFlag	782	// (internal1_m364_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m364_Pav0	BUFFER[2738]	// (internal1_m364_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m364_Pav0	783	// (internal1_m364_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m364_Pv0	BUFFER[2740]	// (internal1_m364_Pv0)  - Пер. выключатель механизма
#define idinternal1_m364_Pv0	784	// (internal1_m364_Pv0)  - Пер. выключатель механизма
#define internal1_m364_RA00	BUFFER[2742]	// (internal1_m364_RA00)  - последнее задание вперед
#define idinternal1_m364_RA00	785	// (internal1_m364_RA00)  - последнее задание вперед
#define internal1_m364_RA10	BUFFER[2744]	// (internal1_m364_RA10)  - последнее задание назад
#define idinternal1_m364_RA10	786	// (internal1_m364_RA10)  - последнее задание назад
#define internal1_m364_V00	BUFFER[2746]	// (internal1_m364_V00)  V00 - текущая скорость механизма
#define idinternal1_m364_V00	787	// (internal1_m364_V00)  V00 - текущая скорость механизма
#define internal1_m364_X00	BUFFER[2751]	// (internal1_m364_X00)  X00 - текущая координата механизма
#define idinternal1_m364_X00	788	// (internal1_m364_X00)  X00 - текущая координата механизма
#define internal1_m364_Zav0	BUFFER[2756]	// (internal1_m364_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m364_Zav0	789	// (internal1_m364_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m364_Zv0	BUFFER[2758]	// (internal1_m364_Zv0)  - Зад. выключатель механизма
#define idinternal1_m364_Zv0	790	// (internal1_m364_Zv0)  - Зад. выключатель механизма
#define internal1_m380_MyFirstEnterFlag	BUFFER[2760]	// (internal1_m380_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m380_MyFirstEnterFlag	791	// (internal1_m380_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m380_Pav0	BUFFER[2762]	// (internal1_m380_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m380_Pav0	792	// (internal1_m380_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m380_Pv0	BUFFER[2764]	// (internal1_m380_Pv0)  - Пер. выключатель механизма
#define idinternal1_m380_Pv0	793	// (internal1_m380_Pv0)  - Пер. выключатель механизма
#define internal1_m380_RA00	BUFFER[2766]	// (internal1_m380_RA00)  - последнее задание вперед
#define idinternal1_m380_RA00	794	// (internal1_m380_RA00)  - последнее задание вперед
#define internal1_m380_RA10	BUFFER[2768]	// (internal1_m380_RA10)  - последнее задание назад
#define idinternal1_m380_RA10	795	// (internal1_m380_RA10)  - последнее задание назад
#define internal1_m380_V00	BUFFER[2770]	// (internal1_m380_V00)  V00 - текущая скорость механизма
#define idinternal1_m380_V00	796	// (internal1_m380_V00)  V00 - текущая скорость механизма
#define internal1_m380_X00	BUFFER[2775]	// (internal1_m380_X00)  X00 - текущая координата механизма
#define idinternal1_m380_X00	797	// (internal1_m380_X00)  X00 - текущая координата механизма
#define internal1_m380_Zav0	BUFFER[2780]	// (internal1_m380_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m380_Zav0	798	// (internal1_m380_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m380_Zv0	BUFFER[2782]	// (internal1_m380_Zv0)  - Зад. выключатель механизма
#define idinternal1_m380_Zv0	799	// (internal1_m380_Zv0)  - Зад. выключатель механизма
#define internal1_m395_MyFirstEnterFlag	BUFFER[2784]	// (internal1_m395_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m395_MyFirstEnterFlag	800	// (internal1_m395_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m395_Pav0	BUFFER[2786]	// (internal1_m395_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m395_Pav0	801	// (internal1_m395_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m395_Pv0	BUFFER[2788]	// (internal1_m395_Pv0)  - Пер. выключатель механизма
#define idinternal1_m395_Pv0	802	// (internal1_m395_Pv0)  - Пер. выключатель механизма
#define internal1_m395_RA00	BUFFER[2790]	// (internal1_m395_RA00)  - последнее задание вперед
#define idinternal1_m395_RA00	803	// (internal1_m395_RA00)  - последнее задание вперед
#define internal1_m395_RA10	BUFFER[2792]	// (internal1_m395_RA10)  - последнее задание назад
#define idinternal1_m395_RA10	804	// (internal1_m395_RA10)  - последнее задание назад
#define internal1_m395_V00	BUFFER[2794]	// (internal1_m395_V00)  V00 - текущая скорость механизма
#define idinternal1_m395_V00	805	// (internal1_m395_V00)  V00 - текущая скорость механизма
#define internal1_m395_X00	BUFFER[2799]	// (internal1_m395_X00)  X00 - текущая координата механизма
#define idinternal1_m395_X00	806	// (internal1_m395_X00)  X00 - текущая координата механизма
#define internal1_m395_Zav0	BUFFER[2804]	// (internal1_m395_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m395_Zav0	807	// (internal1_m395_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m395_Zv0	BUFFER[2806]	// (internal1_m395_Zv0)  - Зад. выключатель механизма
#define idinternal1_m395_Zv0	808	// (internal1_m395_Zv0)  - Зад. выключатель механизма
#define internal1_m39_fef	BUFFER[2808]	// (internal1_m39_fef) fef
#define idinternal1_m39_fef	809	// (internal1_m39_fef) fef
#define internal1_m39_reg	BUFFER[2810]	// (internal1_m39_reg) режим работы квдс 0 - ожидание сигнала 1- выдан импульс 2 отсчет удержания синхроимпульса 3 -блокировка
#define idinternal1_m39_reg	810	// (internal1_m39_reg) режим работы квдс 0 - ожидание сигнала 1- выдан импульс 2 отсчет удержания синхроимпульса 3 -блокировка
#define internal1_m39_tgen	BUFFER[2813]	// (internal1_m39_tgen) задержки срабатывания генератора импульса
#define idinternal1_m39_tgen	811	// (internal1_m39_tgen) задержки срабатывания генератора импульса
#define internal1_m39_tlock	BUFFER[2818]	// (internal1_m39_tlock) время до конца блокировки
#define idinternal1_m39_tlock	812	// (internal1_m39_tlock) время до конца блокировки
#define internal1_m39_tsin	BUFFER[2823]	// (internal1_m39_tsin) время до конца удержания синхроимпульса
#define idinternal1_m39_tsin	813	// (internal1_m39_tsin) время до конца удержания синхроимпульса
#define internal1_m406_Out10	BUFFER[2828]	// (internal1_m406_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m406_Out10	814	// (internal1_m406_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m407_Out10	BUFFER[2830]	// (internal1_m407_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m407_Out10	815	// (internal1_m407_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m408_Out10	BUFFER[2832]	// (internal1_m408_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m408_Out10	816	// (internal1_m408_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m409_Out10	BUFFER[2834]	// (internal1_m409_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m409_Out10	817	// (internal1_m409_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m416_Xtek0	BUFFER[2836]	// (internal1_m416_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m416_Xtek0	818	// (internal1_m416_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m425_Out10	BUFFER[2841]	// (internal1_m425_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m425_Out10	819	// (internal1_m425_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m426_Out10	BUFFER[2843]	// (internal1_m426_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m426_Out10	820	// (internal1_m426_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m427_Out10	BUFFER[2845]	// (internal1_m427_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m427_Out10	821	// (internal1_m427_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m428_Out10	BUFFER[2847]	// (internal1_m428_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m428_Out10	822	// (internal1_m428_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m429_Xtek0	BUFFER[2849]	// (internal1_m429_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m429_Xtek0	823	// (internal1_m429_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m443_MyFirstEnterFlag	BUFFER[2854]	// (internal1_m443_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m443_MyFirstEnterFlag	824	// (internal1_m443_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m443_Pav0	BUFFER[2856]	// (internal1_m443_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m443_Pav0	825	// (internal1_m443_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m443_Pv0	BUFFER[2858]	// (internal1_m443_Pv0)  - Пер. выключатель механизма
#define idinternal1_m443_Pv0	826	// (internal1_m443_Pv0)  - Пер. выключатель механизма
#define internal1_m443_RA00	BUFFER[2860]	// (internal1_m443_RA00)  - последнее задание вперед
#define idinternal1_m443_RA00	827	// (internal1_m443_RA00)  - последнее задание вперед
#define internal1_m443_RA10	BUFFER[2862]	// (internal1_m443_RA10)  - последнее задание назад
#define idinternal1_m443_RA10	828	// (internal1_m443_RA10)  - последнее задание назад
#define internal1_m443_V00	BUFFER[2864]	// (internal1_m443_V00)  V00 - текущая скорость механизма
#define idinternal1_m443_V00	829	// (internal1_m443_V00)  V00 - текущая скорость механизма
#define internal1_m443_X00	BUFFER[2869]	// (internal1_m443_X00)  X00 - текущая координата механизма
#define idinternal1_m443_X00	830	// (internal1_m443_X00)  X00 - текущая координата механизма
#define internal1_m443_Zav0	BUFFER[2874]	// (internal1_m443_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m443_Zav0	831	// (internal1_m443_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m443_Zv0	BUFFER[2876]	// (internal1_m443_Zv0)  - Зад. выключатель механизма
#define idinternal1_m443_Zv0	832	// (internal1_m443_Zv0)  - Зад. выключатель механизма
#define internal1_m457_MyFirstEnterFlag	BUFFER[2878]	// (internal1_m457_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m457_MyFirstEnterFlag	833	// (internal1_m457_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m457_Pav0	BUFFER[2880]	// (internal1_m457_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m457_Pav0	834	// (internal1_m457_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m457_Pv0	BUFFER[2882]	// (internal1_m457_Pv0)  - Пер. выключатель механизма
#define idinternal1_m457_Pv0	835	// (internal1_m457_Pv0)  - Пер. выключатель механизма
#define internal1_m457_RA00	BUFFER[2884]	// (internal1_m457_RA00)  - последнее задание вперед
#define idinternal1_m457_RA00	836	// (internal1_m457_RA00)  - последнее задание вперед
#define internal1_m457_RA10	BUFFER[2886]	// (internal1_m457_RA10)  - последнее задание назад
#define idinternal1_m457_RA10	837	// (internal1_m457_RA10)  - последнее задание назад
#define internal1_m457_V00	BUFFER[2888]	// (internal1_m457_V00)  V00 - текущая скорость механизма
#define idinternal1_m457_V00	838	// (internal1_m457_V00)  V00 - текущая скорость механизма
#define internal1_m457_X00	BUFFER[2893]	// (internal1_m457_X00)  X00 - текущая координата механизма
#define idinternal1_m457_X00	839	// (internal1_m457_X00)  X00 - текущая координата механизма
#define internal1_m457_Zav0	BUFFER[2898]	// (internal1_m457_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m457_Zav0	840	// (internal1_m457_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m457_Zv0	BUFFER[2900]	// (internal1_m457_Zv0)  - Зад. выключатель механизма
#define idinternal1_m457_Zv0	841	// (internal1_m457_Zv0)  - Зад. выключатель механизма
#define internal1_m467_q0	BUFFER[2902]	// (internal1_m467_q0) q0 - внутренний параметр
#define idinternal1_m467_q0	842	// (internal1_m467_q0) q0 - внутренний параметр
#define internal1_m468_q0	BUFFER[2904]	// (internal1_m468_q0) q0 - внутренний параметр
#define idinternal1_m468_q0	843	// (internal1_m468_q0) q0 - внутренний параметр
#define internal1_m472_MyFirstEnterFlag	BUFFER[2906]	// (internal1_m472_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m472_MyFirstEnterFlag	844	// (internal1_m472_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m472_Pav0	BUFFER[2908]	// (internal1_m472_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m472_Pav0	845	// (internal1_m472_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m472_Pv0	BUFFER[2910]	// (internal1_m472_Pv0)  - Пер. выключатель механизма
#define idinternal1_m472_Pv0	846	// (internal1_m472_Pv0)  - Пер. выключатель механизма
#define internal1_m472_RA00	BUFFER[2912]	// (internal1_m472_RA00)  - последнее задание вперед
#define idinternal1_m472_RA00	847	// (internal1_m472_RA00)  - последнее задание вперед
#define internal1_m472_RA10	BUFFER[2914]	// (internal1_m472_RA10)  - последнее задание назад
#define idinternal1_m472_RA10	848	// (internal1_m472_RA10)  - последнее задание назад
#define internal1_m472_V00	BUFFER[2916]	// (internal1_m472_V00)  V00 - текущая скорость механизма
#define idinternal1_m472_V00	849	// (internal1_m472_V00)  V00 - текущая скорость механизма
#define internal1_m472_X00	BUFFER[2921]	// (internal1_m472_X00)  X00 - текущая координата механизма
#define idinternal1_m472_X00	850	// (internal1_m472_X00)  X00 - текущая координата механизма
#define internal1_m472_Zav0	BUFFER[2926]	// (internal1_m472_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m472_Zav0	851	// (internal1_m472_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m472_Zv0	BUFFER[2928]	// (internal1_m472_Zv0)  - Зад. выключатель механизма
#define idinternal1_m472_Zv0	852	// (internal1_m472_Zv0)  - Зад. выключатель механизма
#define internal1_m473_MyFirstEnterFlag	BUFFER[2930]	// (internal1_m473_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m473_MyFirstEnterFlag	853	// (internal1_m473_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m473_Pav0	BUFFER[2932]	// (internal1_m473_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m473_Pav0	854	// (internal1_m473_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m473_Pv0	BUFFER[2934]	// (internal1_m473_Pv0)  - Пер. выключатель механизма
#define idinternal1_m473_Pv0	855	// (internal1_m473_Pv0)  - Пер. выключатель механизма
#define internal1_m473_RA00	BUFFER[2936]	// (internal1_m473_RA00)  - последнее задание вперед
#define idinternal1_m473_RA00	856	// (internal1_m473_RA00)  - последнее задание вперед
#define internal1_m473_RA10	BUFFER[2938]	// (internal1_m473_RA10)  - последнее задание назад
#define idinternal1_m473_RA10	857	// (internal1_m473_RA10)  - последнее задание назад
#define internal1_m473_V00	BUFFER[2940]	// (internal1_m473_V00)  V00 - текущая скорость механизма
#define idinternal1_m473_V00	858	// (internal1_m473_V00)  V00 - текущая скорость механизма
#define internal1_m473_X00	BUFFER[2945]	// (internal1_m473_X00)  X00 - текущая координата механизма
#define idinternal1_m473_X00	859	// (internal1_m473_X00)  X00 - текущая координата механизма
#define internal1_m473_Zav0	BUFFER[2950]	// (internal1_m473_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m473_Zav0	860	// (internal1_m473_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m473_Zv0	BUFFER[2952]	// (internal1_m473_Zv0)  - Зад. выключатель механизма
#define idinternal1_m473_Zv0	861	// (internal1_m473_Zv0)  - Зад. выключатель механизма
#define internal1_m479_q0	BUFFER[2954]	// (internal1_m479_q0) q0 - внутренний параметр
#define idinternal1_m479_q0	862	// (internal1_m479_q0) q0 - внутренний параметр
#define internal1_m47_Out10	BUFFER[2956]	// (internal1_m47_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m47_Out10	863	// (internal1_m47_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m480_q0	BUFFER[2958]	// (internal1_m480_q0) q0 - внутренний параметр
#define idinternal1_m480_q0	864	// (internal1_m480_q0) q0 - внутренний параметр
#define internal1_m483_MyFirstEnterFlag	BUFFER[2960]	// (internal1_m483_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m483_MyFirstEnterFlag	865	// (internal1_m483_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m483_Pav0	BUFFER[2962]	// (internal1_m483_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m483_Pav0	866	// (internal1_m483_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m483_Pv0	BUFFER[2964]	// (internal1_m483_Pv0)  - Пер. выключатель механизма
#define idinternal1_m483_Pv0	867	// (internal1_m483_Pv0)  - Пер. выключатель механизма
#define internal1_m483_RA00	BUFFER[2966]	// (internal1_m483_RA00)  - последнее задание вперед
#define idinternal1_m483_RA00	868	// (internal1_m483_RA00)  - последнее задание вперед
#define internal1_m483_RA10	BUFFER[2968]	// (internal1_m483_RA10)  - последнее задание назад
#define idinternal1_m483_RA10	869	// (internal1_m483_RA10)  - последнее задание назад
#define internal1_m483_V00	BUFFER[2970]	// (internal1_m483_V00)  V00 - текущая скорость механизма
#define idinternal1_m483_V00	870	// (internal1_m483_V00)  V00 - текущая скорость механизма
#define internal1_m483_X00	BUFFER[2975]	// (internal1_m483_X00)  X00 - текущая координата механизма
#define idinternal1_m483_X00	871	// (internal1_m483_X00)  X00 - текущая координата механизма
#define internal1_m483_Zav0	BUFFER[2980]	// (internal1_m483_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m483_Zav0	872	// (internal1_m483_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m483_Zv0	BUFFER[2982]	// (internal1_m483_Zv0)  - Зад. выключатель механизма
#define idinternal1_m483_Zv0	873	// (internal1_m483_Zv0)  - Зад. выключатель механизма
#define internal1_m494_MyFirstEnterFlag	BUFFER[2984]	// (internal1_m494_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m494_MyFirstEnterFlag	874	// (internal1_m494_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m494_Pav0	BUFFER[2986]	// (internal1_m494_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m494_Pav0	875	// (internal1_m494_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m494_Pv0	BUFFER[2988]	// (internal1_m494_Pv0)  - Пер. выключатель механизма
#define idinternal1_m494_Pv0	876	// (internal1_m494_Pv0)  - Пер. выключатель механизма
#define internal1_m494_RA00	BUFFER[2990]	// (internal1_m494_RA00)  - последнее задание вперед
#define idinternal1_m494_RA00	877	// (internal1_m494_RA00)  - последнее задание вперед
#define internal1_m494_RA10	BUFFER[2992]	// (internal1_m494_RA10)  - последнее задание назад
#define idinternal1_m494_RA10	878	// (internal1_m494_RA10)  - последнее задание назад
#define internal1_m494_V00	BUFFER[2994]	// (internal1_m494_V00)  V00 - текущая скорость механизма
#define idinternal1_m494_V00	879	// (internal1_m494_V00)  V00 - текущая скорость механизма
#define internal1_m494_X00	BUFFER[2999]	// (internal1_m494_X00)  X00 - текущая координата механизма
#define idinternal1_m494_X00	880	// (internal1_m494_X00)  X00 - текущая координата механизма
#define internal1_m494_Zav0	BUFFER[3004]	// (internal1_m494_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m494_Zav0	881	// (internal1_m494_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m494_Zv0	BUFFER[3006]	// (internal1_m494_Zv0)  - Зад. выключатель механизма
#define idinternal1_m494_Zv0	882	// (internal1_m494_Zv0)  - Зад. выключатель механизма
#define internal1_m518_Out10	BUFFER[3008]	// (internal1_m518_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m518_Out10	883	// (internal1_m518_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m534_Out10	BUFFER[3010]	// (internal1_m534_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m534_Out10	884	// (internal1_m534_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m535_Out10	BUFFER[3012]	// (internal1_m535_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m535_Out10	885	// (internal1_m535_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m550_Out10	BUFFER[3014]	// (internal1_m550_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m550_Out10	886	// (internal1_m550_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m551_Out10	BUFFER[3016]	// (internal1_m551_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m551_Out10	887	// (internal1_m551_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m552_Out10	BUFFER[3018]	// (internal1_m552_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m552_Out10	888	// (internal1_m552_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m566_MyFirstEnterFlag	BUFFER[3020]	// (internal1_m566_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m566_MyFirstEnterFlag	889	// (internal1_m566_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m566_Pav0	BUFFER[3022]	// (internal1_m566_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m566_Pav0	890	// (internal1_m566_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m566_Pv0	BUFFER[3024]	// (internal1_m566_Pv0)  - Пер. выключатель механизма
#define idinternal1_m566_Pv0	891	// (internal1_m566_Pv0)  - Пер. выключатель механизма
#define internal1_m566_RA00	BUFFER[3026]	// (internal1_m566_RA00)  - последнее задание вперед
#define idinternal1_m566_RA00	892	// (internal1_m566_RA00)  - последнее задание вперед
#define internal1_m566_RA10	BUFFER[3028]	// (internal1_m566_RA10)  - последнее задание назад
#define idinternal1_m566_RA10	893	// (internal1_m566_RA10)  - последнее задание назад
#define internal1_m566_V00	BUFFER[3030]	// (internal1_m566_V00)  V00 - текущая скорость механизма
#define idinternal1_m566_V00	894	// (internal1_m566_V00)  V00 - текущая скорость механизма
#define internal1_m566_X00	BUFFER[3035]	// (internal1_m566_X00)  X00 - текущая координата механизма
#define idinternal1_m566_X00	895	// (internal1_m566_X00)  X00 - текущая координата механизма
#define internal1_m566_Zav0	BUFFER[3040]	// (internal1_m566_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m566_Zav0	896	// (internal1_m566_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m566_Zv0	BUFFER[3042]	// (internal1_m566_Zv0)  - Зад. выключатель механизма
#define idinternal1_m566_Zv0	897	// (internal1_m566_Zv0)  - Зад. выключатель механизма
#define internal1_m580_MyFirstEnterFlag	BUFFER[3044]	// (internal1_m580_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m580_MyFirstEnterFlag	898	// (internal1_m580_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m580_Pav0	BUFFER[3046]	// (internal1_m580_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m580_Pav0	899	// (internal1_m580_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m580_Pv0	BUFFER[3048]	// (internal1_m580_Pv0)  - Пер. выключатель механизма
#define idinternal1_m580_Pv0	900	// (internal1_m580_Pv0)  - Пер. выключатель механизма
#define internal1_m580_RA00	BUFFER[3050]	// (internal1_m580_RA00)  - последнее задание вперед
#define idinternal1_m580_RA00	901	// (internal1_m580_RA00)  - последнее задание вперед
#define internal1_m580_RA10	BUFFER[3052]	// (internal1_m580_RA10)  - последнее задание назад
#define idinternal1_m580_RA10	902	// (internal1_m580_RA10)  - последнее задание назад
#define internal1_m580_V00	BUFFER[3054]	// (internal1_m580_V00)  V00 - текущая скорость механизма
#define idinternal1_m580_V00	903	// (internal1_m580_V00)  V00 - текущая скорость механизма
#define internal1_m580_X00	BUFFER[3059]	// (internal1_m580_X00)  X00 - текущая координата механизма
#define idinternal1_m580_X00	904	// (internal1_m580_X00)  X00 - текущая координата механизма
#define internal1_m580_Zav0	BUFFER[3064]	// (internal1_m580_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m580_Zav0	905	// (internal1_m580_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m580_Zv0	BUFFER[3066]	// (internal1_m580_Zv0)  - Зад. выключатель механизма
#define idinternal1_m580_Zv0	906	// (internal1_m580_Zv0)  - Зад. выключатель механизма
#define internal1_m592_MyFirstEnterFlag	BUFFER[3068]	// (internal1_m592_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m592_MyFirstEnterFlag	907	// (internal1_m592_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m592_Pav0	BUFFER[3070]	// (internal1_m592_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m592_Pav0	908	// (internal1_m592_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m592_Pv0	BUFFER[3072]	// (internal1_m592_Pv0)  - Пер. выключатель механизма
#define idinternal1_m592_Pv0	909	// (internal1_m592_Pv0)  - Пер. выключатель механизма
#define internal1_m592_RA00	BUFFER[3074]	// (internal1_m592_RA00)  - последнее задание вперед
#define idinternal1_m592_RA00	910	// (internal1_m592_RA00)  - последнее задание вперед
#define internal1_m592_RA10	BUFFER[3076]	// (internal1_m592_RA10)  - последнее задание назад
#define idinternal1_m592_RA10	911	// (internal1_m592_RA10)  - последнее задание назад
#define internal1_m592_V00	BUFFER[3078]	// (internal1_m592_V00)  V00 - текущая скорость механизма
#define idinternal1_m592_V00	912	// (internal1_m592_V00)  V00 - текущая скорость механизма
#define internal1_m592_X00	BUFFER[3083]	// (internal1_m592_X00)  X00 - текущая координата механизма
#define idinternal1_m592_X00	913	// (internal1_m592_X00)  X00 - текущая координата механизма
#define internal1_m592_Zav0	BUFFER[3088]	// (internal1_m592_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m592_Zav0	914	// (internal1_m592_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m592_Zv0	BUFFER[3090]	// (internal1_m592_Zv0)  - Зад. выключатель механизма
#define idinternal1_m592_Zv0	915	// (internal1_m592_Zv0)  - Зад. выключатель механизма
#define internal1_m593_MyFirstEnterFlag	BUFFER[3092]	// (internal1_m593_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m593_MyFirstEnterFlag	916	// (internal1_m593_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m593_Pav0	BUFFER[3094]	// (internal1_m593_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m593_Pav0	917	// (internal1_m593_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m593_Pv0	BUFFER[3096]	// (internal1_m593_Pv0)  - Пер. выключатель механизма
#define idinternal1_m593_Pv0	918	// (internal1_m593_Pv0)  - Пер. выключатель механизма
#define internal1_m593_RA00	BUFFER[3098]	// (internal1_m593_RA00)  - последнее задание вперед
#define idinternal1_m593_RA00	919	// (internal1_m593_RA00)  - последнее задание вперед
#define internal1_m593_RA10	BUFFER[3100]	// (internal1_m593_RA10)  - последнее задание назад
#define idinternal1_m593_RA10	920	// (internal1_m593_RA10)  - последнее задание назад
#define internal1_m593_V00	BUFFER[3102]	// (internal1_m593_V00)  V00 - текущая скорость механизма
#define idinternal1_m593_V00	921	// (internal1_m593_V00)  V00 - текущая скорость механизма
#define internal1_m593_X00	BUFFER[3107]	// (internal1_m593_X00)  X00 - текущая координата механизма
#define idinternal1_m593_X00	922	// (internal1_m593_X00)  X00 - текущая координата механизма
#define internal1_m593_Zav0	BUFFER[3112]	// (internal1_m593_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m593_Zav0	923	// (internal1_m593_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m593_Zv0	BUFFER[3114]	// (internal1_m593_Zv0)  - Зад. выключатель механизма
#define idinternal1_m593_Zv0	924	// (internal1_m593_Zv0)  - Зад. выключатель механизма
#define internal1_m601_tx	BUFFER[3116]	// (internal1_m601_tx) tx - время накопленное сек
#define idinternal1_m601_tx	925	// (internal1_m601_tx) tx - время накопленное сек
#define internal1_m601_y0	BUFFER[3121]	// (internal1_m601_y0) y0
#define idinternal1_m601_y0	926	// (internal1_m601_y0) y0
#define internal1_m603_tx	BUFFER[3123]	// (internal1_m603_tx) tx - время накопленное сек
#define idinternal1_m603_tx	927	// (internal1_m603_tx) tx - время накопленное сек
#define internal1_m603_y0	BUFFER[3128]	// (internal1_m603_y0) y0
#define idinternal1_m603_y0	928	// (internal1_m603_y0) y0
#define internal1_m605_MyFirstEnterFlag	BUFFER[3130]	// (internal1_m605_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m605_MyFirstEnterFlag	929	// (internal1_m605_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m605_Pav0	BUFFER[3132]	// (internal1_m605_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m605_Pav0	930	// (internal1_m605_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m605_Pv0	BUFFER[3134]	// (internal1_m605_Pv0)  - Пер. выключатель механизма
#define idinternal1_m605_Pv0	931	// (internal1_m605_Pv0)  - Пер. выключатель механизма
#define internal1_m605_RA00	BUFFER[3136]	// (internal1_m605_RA00)  - последнее задание вперед
#define idinternal1_m605_RA00	932	// (internal1_m605_RA00)  - последнее задание вперед
#define internal1_m605_RA10	BUFFER[3138]	// (internal1_m605_RA10)  - последнее задание назад
#define idinternal1_m605_RA10	933	// (internal1_m605_RA10)  - последнее задание назад
#define internal1_m605_V00	BUFFER[3140]	// (internal1_m605_V00)  V00 - текущая скорость механизма
#define idinternal1_m605_V00	934	// (internal1_m605_V00)  V00 - текущая скорость механизма
#define internal1_m605_X00	BUFFER[3145]	// (internal1_m605_X00)  X00 - текущая координата механизма
#define idinternal1_m605_X00	935	// (internal1_m605_X00)  X00 - текущая координата механизма
#define internal1_m605_Zav0	BUFFER[3150]	// (internal1_m605_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m605_Zav0	936	// (internal1_m605_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m605_Zv0	BUFFER[3152]	// (internal1_m605_Zv0)  - Зад. выключатель механизма
#define idinternal1_m605_Zv0	937	// (internal1_m605_Zv0)  - Зад. выключатель механизма
#define internal1_m606_MyFirstEnterFlag	BUFFER[3154]	// (internal1_m606_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m606_MyFirstEnterFlag	938	// (internal1_m606_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m606_Pav0	BUFFER[3156]	// (internal1_m606_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m606_Pav0	939	// (internal1_m606_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m606_Pv0	BUFFER[3158]	// (internal1_m606_Pv0)  - Пер. выключатель механизма
#define idinternal1_m606_Pv0	940	// (internal1_m606_Pv0)  - Пер. выключатель механизма
#define internal1_m606_RA00	BUFFER[3160]	// (internal1_m606_RA00)  - последнее задание вперед
#define idinternal1_m606_RA00	941	// (internal1_m606_RA00)  - последнее задание вперед
#define internal1_m606_RA10	BUFFER[3162]	// (internal1_m606_RA10)  - последнее задание назад
#define idinternal1_m606_RA10	942	// (internal1_m606_RA10)  - последнее задание назад
#define internal1_m606_V00	BUFFER[3164]	// (internal1_m606_V00)  V00 - текущая скорость механизма
#define idinternal1_m606_V00	943	// (internal1_m606_V00)  V00 - текущая скорость механизма
#define internal1_m606_X00	BUFFER[3169]	// (internal1_m606_X00)  X00 - текущая координата механизма
#define idinternal1_m606_X00	944	// (internal1_m606_X00)  X00 - текущая координата механизма
#define internal1_m606_Zav0	BUFFER[3174]	// (internal1_m606_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m606_Zav0	945	// (internal1_m606_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m606_Zv0	BUFFER[3176]	// (internal1_m606_Zv0)  - Зад. выключатель механизма
#define idinternal1_m606_Zv0	946	// (internal1_m606_Zv0)  - Зад. выключатель механизма
#define internal1_m615_tx	BUFFER[3178]	// (internal1_m615_tx) tx - время накопленное сек
#define idinternal1_m615_tx	947	// (internal1_m615_tx) tx - время накопленное сек
#define internal1_m615_y0	BUFFER[3183]	// (internal1_m615_y0) y0
#define idinternal1_m615_y0	948	// (internal1_m615_y0) y0
#define internal1_m627_tx	BUFFER[3185]	// (internal1_m627_tx) tx - время накопленное сек
#define idinternal1_m627_tx	949	// (internal1_m627_tx) tx - время накопленное сек
#define internal1_m627_y0	BUFFER[3190]	// (internal1_m627_y0) y0
#define idinternal1_m627_y0	950	// (internal1_m627_y0) y0
#define internal1_m62_Out10	BUFFER[3192]	// (internal1_m62_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m62_Out10	951	// (internal1_m62_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m634_y0	BUFFER[3194]	// (internal1_m634_y0) y0 - внутренний параметр
#define idinternal1_m634_y0	952	// (internal1_m634_y0) y0 - внутренний параметр
#define internal1_m648_Out10	BUFFER[3199]	// (internal1_m648_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m648_Out10	953	// (internal1_m648_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m649_Out10	BUFFER[3201]	// (internal1_m649_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m649_Out10	954	// (internal1_m649_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m650_Out10	BUFFER[3203]	// (internal1_m650_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m650_Out10	955	// (internal1_m650_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m651_Out10	BUFFER[3205]	// (internal1_m651_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m651_Out10	956	// (internal1_m651_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m652_Out10	BUFFER[3207]	// (internal1_m652_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m652_Out10	957	// (internal1_m652_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m653_Out10	BUFFER[3209]	// (internal1_m653_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m653_Out10	958	// (internal1_m653_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m65_MyFirstEnterFlag	BUFFER[3211]	// (internal1_m65_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m65_MyFirstEnterFlag	959	// (internal1_m65_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m65_Pav0	BUFFER[3213]	// (internal1_m65_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m65_Pav0	960	// (internal1_m65_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m65_Ppv0	BUFFER[3215]	// (internal1_m65_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m65_Ppv0	961	// (internal1_m65_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m65_RA00	BUFFER[3217]	// (internal1_m65_RA00) RA00 - последнее задание вперед
#define idinternal1_m65_RA00	962	// (internal1_m65_RA00) RA00 - последнее задание вперед
#define internal1_m65_RA10	BUFFER[3219]	// (internal1_m65_RA10) RA10 - последнее задание назад
#define idinternal1_m65_RA10	963	// (internal1_m65_RA10) RA10 - последнее задание назад
#define internal1_m65_RA30	BUFFER[3221]	// (internal1_m65_RA30)  RA30 - разрешение движения
#define idinternal1_m65_RA30	964	// (internal1_m65_RA30)  RA30 - разрешение движения
#define internal1_m65_RA50	BUFFER[3223]	// (internal1_m65_RA50) Ra50 - последнее задание скорости
#define idinternal1_m65_RA50	965	// (internal1_m65_RA50) Ra50 - последнее задание скорости
#define internal1_m65_RV00	BUFFER[3225]	// (internal1_m65_RV00) V0 - текущая скорость ОРР
#define idinternal1_m65_RV00	966	// (internal1_m65_RV00) V0 - текущая скорость ОРР
#define internal1_m65_Sh00	BUFFER[3230]	// (internal1_m65_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m65_Sh00	967	// (internal1_m65_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m65_ShV00	BUFFER[3235]	// (internal1_m65_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m65_ShV00	968	// (internal1_m65_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m65_X00	BUFFER[3240]	// (internal1_m65_X00) X0 - текущая координата ОРР
#define idinternal1_m65_X00	969	// (internal1_m65_X00) X0 - текущая координата ОРР
#define internal1_m65_Zav0	BUFFER[3245]	// (internal1_m65_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m65_Zav0	970	// (internal1_m65_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m65_flp	BUFFER[3247]	// (internal1_m65_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m65_flp	971	// (internal1_m65_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m65_fls	BUFFER[3249]	// (internal1_m65_fls)  fls - флаг одношагового режима
#define idinternal1_m65_fls	972	// (internal1_m65_fls)  fls - флаг одношагового режима
#define internal1_m668_Out10	BUFFER[3251]	// (internal1_m668_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m668_Out10	973	// (internal1_m668_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m669_Out10	BUFFER[3253]	// (internal1_m669_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m669_Out10	974	// (internal1_m669_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m672_Out10	BUFFER[3255]	// (internal1_m672_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m672_Out10	975	// (internal1_m672_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m673_Out10	BUFFER[3257]	// (internal1_m673_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m673_Out10	976	// (internal1_m673_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m674_Out10	BUFFER[3259]	// (internal1_m674_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m674_Out10	977	// (internal1_m674_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m675_Out10	BUFFER[3261]	// (internal1_m675_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m675_Out10	978	// (internal1_m675_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m685_Out10	BUFFER[3263]	// (internal1_m685_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m685_Out10	979	// (internal1_m685_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m686_Out10	BUFFER[3265]	// (internal1_m686_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m686_Out10	980	// (internal1_m686_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m687_Out10	BUFFER[3267]	// (internal1_m687_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m687_Out10	981	// (internal1_m687_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m688_Out10	BUFFER[3269]	// (internal1_m688_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m688_Out10	982	// (internal1_m688_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m689_Out10	BUFFER[3271]	// (internal1_m689_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m689_Out10	983	// (internal1_m689_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m702_Chim0	BUFFER[3273]	// (internal1_m702_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m702_Chim0	984	// (internal1_m702_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m712_Chim0	BUFFER[3278]	// (internal1_m712_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m712_Chim0	985	// (internal1_m712_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m721_Chim0	BUFFER[3283]	// (internal1_m721_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m721_Chim0	986	// (internal1_m721_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m730_Chim0	BUFFER[3288]	// (internal1_m730_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m730_Chim0	987	// (internal1_m730_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m738_Chim0	BUFFER[3293]	// (internal1_m738_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m738_Chim0	988	// (internal1_m738_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m747_Chim0	BUFFER[3298]	// (internal1_m747_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m747_Chim0	989	// (internal1_m747_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m756_Chim0	BUFFER[3303]	// (internal1_m756_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m756_Chim0	990	// (internal1_m756_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m764_Chim0	BUFFER[3308]	// (internal1_m764_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m764_Chim0	991	// (internal1_m764_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m773_Chim0	BUFFER[3313]	// (internal1_m773_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m773_Chim0	992	// (internal1_m773_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m782_Chim0	BUFFER[3318]	// (internal1_m782_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m782_Chim0	993	// (internal1_m782_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m790_Chim0	BUFFER[3323]	// (internal1_m790_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m790_Chim0	994	// (internal1_m790_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m799_Chim0	BUFFER[3328]	// (internal1_m799_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m799_Chim0	995	// (internal1_m799_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m811_Out10	BUFFER[3333]	// (internal1_m811_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m811_Out10	996	// (internal1_m811_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m812_Out10	BUFFER[3335]	// (internal1_m812_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m812_Out10	997	// (internal1_m812_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m813_Out10	BUFFER[3337]	// (internal1_m813_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m813_Out10	998	// (internal1_m813_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m814_Out10	BUFFER[3339]	// (internal1_m814_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m814_Out10	999	// (internal1_m814_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m815_Out10	BUFFER[3341]	// (internal1_m815_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m815_Out10	1000	// (internal1_m815_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m816_Out10	BUFFER[3343]	// (internal1_m816_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m816_Out10	1001	// (internal1_m816_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m817_Out10	BUFFER[3345]	// (internal1_m817_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m817_Out10	1002	// (internal1_m817_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m834_Xtek0	BUFFER[3347]	// (internal1_m834_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m834_Xtek0	1003	// (internal1_m834_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m836_Xtek0	BUFFER[3352]	// (internal1_m836_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m836_Xtek0	1004	// (internal1_m836_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m837_Out10	BUFFER[3357]	// (internal1_m837_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m837_Out10	1005	// (internal1_m837_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m838_Out10	BUFFER[3359]	// (internal1_m838_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m838_Out10	1006	// (internal1_m838_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m839_Out10	BUFFER[3361]	// (internal1_m839_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m839_Out10	1007	// (internal1_m839_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m840_Out10	BUFFER[3363]	// (internal1_m840_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m840_Out10	1008	// (internal1_m840_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m852_Out10	BUFFER[3365]	// (internal1_m852_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m852_Out10	1009	// (internal1_m852_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m853_Out10	BUFFER[3367]	// (internal1_m853_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m853_Out10	1010	// (internal1_m853_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m854_Out10	BUFFER[3369]	// (internal1_m854_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m854_Out10	1011	// (internal1_m854_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m862_Chim0	BUFFER[3371]	// (internal1_m862_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m862_Chim0	1012	// (internal1_m862_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m870_Chim0	BUFFER[3376]	// (internal1_m870_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m870_Chim0	1013	// (internal1_m870_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m880_Chim0	BUFFER[3381]	// (internal1_m880_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m880_Chim0	1014	// (internal1_m880_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m892_MyFirstEnterFlag	BUFFER[3386]	// (internal1_m892_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m892_MyFirstEnterFlag	1015	// (internal1_m892_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m892_Pav0	BUFFER[3388]	// (internal1_m892_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m892_Pav0	1016	// (internal1_m892_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m892_Pv0	BUFFER[3390]	// (internal1_m892_Pv0)  - Пер. выключатель механизма
#define idinternal1_m892_Pv0	1017	// (internal1_m892_Pv0)  - Пер. выключатель механизма
#define internal1_m892_RA00	BUFFER[3392]	// (internal1_m892_RA00)  - последнее задание вперед
#define idinternal1_m892_RA00	1018	// (internal1_m892_RA00)  - последнее задание вперед
#define internal1_m892_RA10	BUFFER[3394]	// (internal1_m892_RA10)  - последнее задание назад
#define idinternal1_m892_RA10	1019	// (internal1_m892_RA10)  - последнее задание назад
#define internal1_m892_V00	BUFFER[3396]	// (internal1_m892_V00)  V00 - текущая скорость механизма
#define idinternal1_m892_V00	1020	// (internal1_m892_V00)  V00 - текущая скорость механизма
#define internal1_m892_X00	BUFFER[3401]	// (internal1_m892_X00)  X00 - текущая координата механизма
#define idinternal1_m892_X00	1021	// (internal1_m892_X00)  X00 - текущая координата механизма
#define internal1_m892_Zav0	BUFFER[3406]	// (internal1_m892_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m892_Zav0	1022	// (internal1_m892_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m892_Zv0	BUFFER[3408]	// (internal1_m892_Zv0)  - Зад. выключатель механизма
#define idinternal1_m892_Zv0	1023	// (internal1_m892_Zv0)  - Зад. выключатель механизма
#define internal1_m949_Out10	BUFFER[3410]	// (internal1_m949_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m949_Out10	1024	// (internal1_m949_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m950_Out10	BUFFER[3412]	// (internal1_m950_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m950_Out10	1025	// (internal1_m950_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m952_Xtek0	BUFFER[3414]	// (internal1_m952_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m952_Xtek0	1026	// (internal1_m952_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m953_Out10	BUFFER[3419]	// (internal1_m953_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m953_Out10	1027	// (internal1_m953_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m966_Out10	BUFFER[3421]	// (internal1_m966_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m966_Out10	1028	// (internal1_m966_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m967_Out10	BUFFER[3423]	// (internal1_m967_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m967_Out10	1029	// (internal1_m967_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m969_Xtek0	BUFFER[3425]	// (internal1_m969_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m969_Xtek0	1030	// (internal1_m969_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m970_Out10	BUFFER[3430]	// (internal1_m970_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m970_Out10	1031	// (internal1_m970_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m980_Out10	BUFFER[3432]	// (internal1_m980_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m980_Out10	1032	// (internal1_m980_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m981_Out10	BUFFER[3434]	// (internal1_m981_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m981_Out10	1033	// (internal1_m981_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m982_Out10	BUFFER[3436]	// (internal1_m982_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m982_Out10	1034	// (internal1_m982_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m983_Out10	BUFFER[3438]	// (internal1_m983_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m983_Out10	1035	// (internal1_m983_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m984_Out10	BUFFER[3440]	// (internal1_m984_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m984_Out10	1036	// (internal1_m984_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m995_Out10	BUFFER[3442]	// (internal1_m995_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m995_Out10	1037	// (internal1_m995_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m996_Out10	BUFFER[3444]	// (internal1_m996_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m996_Out10	1038	// (internal1_m996_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m997_Out10	BUFFER[3446]	// (internal1_m997_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m997_Out10	1039	// (internal1_m997_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m998_Out10	BUFFER[3448]	// (internal1_m998_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m998_Out10	1040	// (internal1_m998_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m999_Out10	BUFFER[3450]	// (internal1_m999_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m999_Out10	1041	// (internal1_m999_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define krb1	BUFFER[3452]	// ( - , - ) 
#define idkrb1	1042	// ( - , - ) 
#define krb2	BUFFER[3457]	// ( - , - ) 
#define idkrb2	1043	// ( - , - ) 
#define lEM_C1AD31LRP	BUFFER[3462]	// (C1AD31LRP) Общий сброс от РПУ
#define idlEM_C1AD31LRP	1044	// (C1AD31LRP) Общий сброс от РПУ
#define lEM_R0IE01LRP	BUFFER[3464]	// (R0IE01LRP) Отключение питание детекторов
#define idlEM_R0IE01LRP	1045	// (R0IE01LRP) Отключение питание детекторов
#define lEM_R0IE02LRP	BUFFER[3466]	// (R0IE02LRP) Отключить питание ПР, ПУ
#define idlEM_R0IE02LRP	1046	// (R0IE02LRP) Отключить питание ПР, ПУ
#define lEM_R3AD10LC1	BUFFER[3468]	// (R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define idlEM_R3AD10LC1	1047	// (R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define lEM_R3AD20LC1	BUFFER[3470]	// (R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define idlEM_R3AD20LC1	1048	// (R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define lEM_R5AD10LC1	BUFFER[3472]	// (R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define idlEM_R5AD10LC1	1049	// (R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define lEM_R5AD20LC1	BUFFER[3474]	// (R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define idlEM_R5AD20LC1	1050	// (R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define lEM_R6AD10LC1	BUFFER[3476]	// (R6AD10LC1) Выкатить кран-балку от ИС
#define idlEM_R6AD10LC1	1051	// (R6AD10LC1) Выкатить кран-балку от ИС
#define lEM_R8AD10LC1	BUFFER[3478]	// (R8AD10LC1) Установить аварийный НИ от ИС
#define idlEM_R8AD10LC1	1052	// (R8AD10LC1) Установить аварийный НИ от ИС
#pragma pack(push,1)
static VarCtrl allVariables[]={ 			 //Описание всех переменных
	{1	,3	,1	,&A0IT01IZ1},	//(ao16_pti:320 - K01AO, - ) Температура АЗ1-1
	{2	,3	,1	,&A0IT02IZ2},	//(ao16_pti:320 - K05AO, - ) Температура АЗ1-2
	{3	,3	,1	,&A0IT03IRP},	//(ao16_pti:320 - K11AO, - ) Температура АЗ1-3
	{4	,8	,1	,&A0SN02RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
	{5	,8	,1	,&A0SN03RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
	{6	,8	,1	,&A0SN04RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
	{7	,8	,1	,&A0SN05RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
	{8	,8	,1	,&A0SN06RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
	{9	,8	,1	,&A0SN07RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
	{10	,8	,1	,&A0SN08RIM},	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
	{11	,8	,1	,&A0SR01RIM},	//( - , SCM) Текущая реактивность AЗ1
	{12	,8	,1	,&A0VN01RIM},	//( - , SCM) Период разгона  AЗ1
	{13	,1	,1	,&A0VP81LZZ},	//(do32_pti:110 - K03DO, - ) Давление АЗ1 в норме
	{14	,1	,1	,&A1AD01LDU},	//(vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
	{15	,1	,1	,&A1AD02LDU},	//(vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
	{16	,1	,1	,&A1AD03LDU},	//(vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
	{17	,1	,1	,&A1AD04LDU},	//(vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
	{18	,1	,1	,&A1AD05LDU},	//(vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
	{19	,1	,1	,&A1AD11LDU},	//(vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
	{20	,1	,1	,&A1AD21LDU},	//(vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
	{21	,1	,1	,&A1AD31LDU},	//(vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
	{22	,1	,1	,&A1AD32LDU},	//(vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
	{23	,5	,1	,&A1IC01UDU},	//( - , SDu) Координата штока ББ1
	{24	,1	,1	,&A1IE03LDU},	//( - , SCM) Движение ББ1 вперед (от БУШД)
	{25	,1	,1	,&A1IE04LDU},	//( - , SCM) Движение ББ1 назад (от БУШД)
	{26	,1	,1	,&A1IS11LDU},	//(do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
	{27	,1	,1	,&A1IS11LIM},	//( - , SCM) Магнит ББ1 обесточен
	{28	,1	,1	,&A1IS12LDU},	//(do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
	{29	,1	,1	,&A1IS21LDU},	//(do32_pti:140 - K02DO, - ) Приход на НУ ББ1
	{30	,1	,1	,&A1IS32LIM},	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
	{31	,1	,1	,&A1VP81LZZ},	//(do32_pti:110 - K01DO, - ) Давление СБРОС ББ1 в норме
	{32	,1	,1	,&A2AD01LDU},	//(vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
	{33	,1	,1	,&A2AD02LDU},	//(vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
	{34	,1	,1	,&A2AD03LDU},	//(vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
	{35	,1	,1	,&A2AD04LDU},	//(vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
	{36	,1	,1	,&A2AD05LDU},	//(vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
	{37	,1	,1	,&A2AD11LDU},	//(vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
	{38	,1	,1	,&A2AD21LDU},	//(vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
	{39	,1	,1	,&A2AD31LDU},	//(vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
	{40	,1	,1	,&A2AD32LDU},	//(vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
	{41	,1	,1	,&A2AD33LDU},	//(vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
	{42	,5	,1	,&A2IC01UDU},	//( - , SDu) Координата штока РБ1
	{43	,3	,1	,&A2IP01IZ1},	//(ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
	{44	,3	,1	,&A2IP01IZ2},	//(ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
	{45	,1	,1	,&A2IS11LDU},	//(do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
	{46	,1	,1	,&A2IS11LIM},	//( - , SCM) Магнит РБ1 обесточен
	{47	,1	,1	,&A2IS12LDU},	//(do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
	{48	,1	,1	,&A2IS21LDU},	//(do32_pti:140 - K05DO, - ) Приход на НУ РБ1
	{49	,1	,1	,&A2IS32LIM},	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
	{50	,1	,1	,&A2IS33LDU},	//( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
	{51	,1	,1	,&A2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
	{52	,1	,1	,&A3AD01LDU},	//(vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
	{53	,1	,1	,&A3AD02LDU},	//(vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
	{54	,1	,1	,&A3AD03LDU},	//(vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
	{55	,1	,1	,&A3AD04LDU},	//(vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
	{56	,1	,1	,&A3AD05LDU},	//(vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
	{57	,1	,1	,&A3AD11LDU},	//(vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
	{58	,1	,1	,&A3AD21LDU},	//(vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
	{59	,1	,1	,&A3AD31LDU},	//(vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
	{60	,1	,1	,&A3AD33LDU},	//(vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
	{61	,1	,1	,&A3AD34LDU},	//(vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
	{62	,5	,1	,&A3IC01UDU},	//( - , SDu) Координата штока ИС1
	{63	,3	,1	,&A3IP02IDU},	//(ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
	{64	,1	,1	,&A3IS11LDU},	//(do32_pti:110 - K04DO, - ) Приход на ВУ ИС1
	{65	,1	,1	,&A3IS21LDU},	//(do32_pti:140 - K06DO, - ) Приход на НУ ИС1
	{66	,1	,1	,&A3IS22LDU},	//(do32_pti:110 - K02DO, - ) Приход на НУП ИС1
	{67	,1	,1	,&A3IS31LDU},	//( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
	{68	,1	,1	,&A3IS33LDU},	//( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
	{69	,1	,1	,&A3IS35LDU},	//( - , - ) Клапан (ВПИС1) открыт(обесточен)
	{70	,1	,1	,&A3VP81LDU},	//( - , - ) Давление СПУСК ИС1 в норме
	{71	,1	,1	,&A4AD10LDU},	//(vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
	{72	,1	,1	,&A4IS10LDU},	//( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
	{73	,1	,1	,&A4IS11LDU},	//(do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
	{74	,1	,1	,&A4IS21LDU},	//(do32_pti:130 - K17DO, - ) Приход на НУ НИ1
	{75	,1	,1	,&A4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
	{76	,1	,1	,&A5AD10LDU},	//(vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
	{77	,1	,1	,&A5AD20LDU},	//(vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
	{78	,1	,1	,&A5IS11LDU},	//(do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
	{79	,1	,1	,&A5IS21LDU},	//(do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
	{80	,1	,1	,&A5VS12LDU},	//( - , SCM) Движение НЛ1 в сторону ВУ
	{81	,1	,1	,&A5VS22LDU},	//( - , SCM) Движение НЛ1 в сторону НУ
	{82	,1	,1	,&A6AD10LDU},	//(vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
	{83	,1	,1	,&A6AD20LDU},	//(vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
	{84	,1	,1	,&A6IS11LDU},	//(do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
	{85	,1	,1	,&A6IS21LDU},	//(do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
	{86	,1	,1	,&A6VS12LDU},	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
	{87	,1	,1	,&A6VS22LDU},	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
	{88	,1	,1	,&A7AP31LDU},	//(vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
	{89	,1	,1	,&A7AS31LDU},	//(do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
	{90	,1	,1	,&A8AD10LDU},	//(vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
	{91	,1	,1	,&A8AD20LDU},	//(vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
	{92	,5	,1	,&A8IC01UDU},	//( - , SDu) Координата ДС2
	{93	,1	,1	,&A8IS12LDU},	//(do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
	{94	,1	,1	,&A8IS22LDU},	//(do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
	{95	,1	,1	,&A9AD10LDU},	//(vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
	{96	,1	,1	,&A9IS11LDU},	//(do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
	{97	,1	,1	,&A9IS21LDU},	//(do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
	{98	,3	,1	,&B0IT01IZ1},	//(ao16_pti:320 - K03AO, - ) Температура АЗ2-1
	{99	,3	,1	,&B0IT02IZ2},	//(ao16_pti:320 - K07AO, - ) Температура АЗ2-2
	{100	,3	,1	,&B0IT03IRP},	//(ao16_pti:320 - K12AO, - ) Температура АЗ2-3
	{101	,8	,1	,&B0SN02RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
	{102	,8	,1	,&B0SN03RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
	{103	,8	,1	,&B0SN04RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
	{104	,8	,1	,&B0SN05RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
	{105	,8	,1	,&B0SN06RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
	{106	,8	,1	,&B0SN07RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
	{107	,8	,1	,&B0SN08RIM},	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
	{108	,8	,1	,&B0SR01RIM},	//( - , SCM) Текущая реактивность AЗ2
	{109	,1	,1	,&B0VP81LZZ},	//(do32_pti:110 - K30DO, - ) Давление АЗ2 в норме
	{110	,1	,1	,&B1AD01LDU},	//(vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
	{111	,1	,1	,&B1AD02LDU},	//(vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
	{112	,1	,1	,&B1AD03LDU},	//(vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
	{113	,1	,1	,&B1AD04LDU},	//(vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
	{114	,1	,1	,&B1AD05LDU},	//(vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
	{115	,1	,1	,&B1AD11LDU},	//(vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
	{116	,1	,1	,&B1AD21LDU},	//(vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
	{117	,1	,1	,&B1AD31LDU},	//(vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
	{118	,1	,1	,&B1AD32LDU},	//(vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
	{119	,5	,1	,&B1IC01UDU},	//( - , SDu) Координата штока ББ2
	{120	,1	,1	,&B1IE03LDU},	//( - , SCM) Движение ББ2 вперед (от БУШД)
	{121	,1	,1	,&B1IE04LDU},	//( - , SCM) Движение ББ2 назад (от БУШД)
	{122	,1	,1	,&B1IS11LDU},	//(do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
	{123	,1	,1	,&B1IS11LIM},	//( - , SCM) Магнит ББ2 обесточен
	{124	,1	,1	,&B1IS12LDU},	//(do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
	{125	,1	,1	,&B1IS21LDU},	//(do32_pti:130 - K09DO, - ) Приход на НУ ББ2
	{126	,1	,1	,&B1IS32LIM},	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
	{127	,1	,1	,&B1VP81LZZ},	//(do32_pti:110 - K31DO, - ) Давление СБРОС ББ2 в норме
	{128	,1	,1	,&B2AD01LDU},	//(vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
	{129	,1	,1	,&B2AD02LDU},	//(vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
	{130	,1	,1	,&B2AD03LDU},	//(vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
	{131	,1	,1	,&B2AD04LDU},	//(vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
	{132	,1	,1	,&B2AD05LDU},	//(vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
	{133	,1	,1	,&B2AD11LDU},	//(vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
	{134	,1	,1	,&B2AD21LDU},	//(vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
	{135	,1	,1	,&B2AD31LDU},	//(vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
	{136	,1	,1	,&B2AD32LDU},	//(vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
	{137	,1	,1	,&B2AD33LDU},	//(vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
	{138	,5	,1	,&B2IC01UDU},	//( - , SDu) Координата штока РБ2
	{139	,3	,1	,&B2IP01IZ1},	//(ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
	{140	,3	,1	,&B2IP01IZ2},	//(ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
	{141	,1	,1	,&B2IS11LDU},	//(do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
	{142	,1	,1	,&B2IS11LIM},	//( - , SCM) Магнит РБ2 обесточен
	{143	,1	,1	,&B2IS12LDU},	//(do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
	{144	,1	,1	,&B2IS21LDU},	//(do32_pti:130 - K12DO, - ) Приход на НУ РБ2
	{145	,1	,1	,&B2IS32LIM},	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
	{146	,1	,1	,&B2IS33LDU},	//( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
	{147	,1	,1	,&B2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
	{148	,1	,1	,&B3AD01LDU},	//(vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
	{149	,1	,1	,&B3AD02LDU},	//(vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
	{150	,1	,1	,&B3AD03LDU},	//(vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
	{151	,1	,1	,&B3AD04LDU},	//(vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
	{152	,1	,1	,&B3AD05LDU},	//(vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
	{153	,1	,1	,&B3AD11LDU},	//(vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
	{154	,1	,1	,&B3AD21LDU},	//(vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
	{155	,1	,1	,&B3AD31LDU},	//(vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
	{156	,1	,1	,&B3AD33LDU},	//(vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
	{157	,1	,1	,&B3AD34LDU},	//(vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
	{158	,5	,1	,&B3IC01UDU},	//( - , SDu) Координата штока ИС2
	{159	,3	,1	,&B3IP02IDU},	//(ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
	{160	,1	,1	,&B3IS11LDU},	//(do32_pti:110 - K11DO, - ) Приход на ВУ ИС2
	{161	,1	,1	,&B3IS21LDU},	//(do32_pti:130 - K13DO, - ) Приход на НУ ИС2
	{162	,1	,1	,&B3IS22LDU},	//(do32_pti:110 - K12DO, - ) Приход на НУП ИС2
	{163	,1	,1	,&B3IS31LDU},	//( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
	{164	,1	,1	,&B3IS33LDU},	//( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{165	,1	,1	,&B3IS35LDU},	//( - , - ) Клапан «ВПИС2» открыт(обесточен)
	{166	,1	,1	,&B3VP81LDU},	//( - , - ) Давление СПУСК ИС2 в норме
	{167	,1	,1	,&B4AD10LDU},	//(vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
	{168	,1	,1	,&B4IS10LDU},	//( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
	{169	,1	,1	,&B4IS11LDU},	//(do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
	{170	,1	,1	,&B4IS21LDU},	//(do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
	{171	,1	,1	,&B4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
	{172	,1	,1	,&B5AD10LDU},	//(vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
	{173	,1	,1	,&B5AD20LDU},	//(vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
	{174	,1	,1	,&B5IS11LDU},	//(do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
	{175	,1	,1	,&B5IS21LDU},	//(do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
	{176	,1	,1	,&B5VS12LDU},	//( - , SCM) Движение НЛ2 в сторону ВУ
	{177	,1	,1	,&B5VS22LDU},	//( - , SCM) Движение НЛ2 в сторону НУ
	{178	,1	,1	,&B6AD10LDU},	//(vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
	{179	,1	,1	,&B6AD20LDU},	//(vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
	{180	,1	,1	,&B6IS11LDU},	//(do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
	{181	,1	,1	,&B6IS21LDU},	//(do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
	{182	,1	,1	,&B6VS12LDU},	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
	{183	,1	,1	,&B6VS22LDU},	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
	{184	,1	,1	,&B7AP31LDU},	//(vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
	{185	,1	,1	,&B7AS31LDU},	//(do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
	{186	,1	,1	,&B8AD10LDU},	//(vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
	{187	,1	,1	,&B8AD20LDU},	//(vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
	{188	,5	,1	,&B8IC01UDU},	//( - , SDu) Координата АЗ2, мм
	{189	,1	,1	,&B8IS11LDU},	//(do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
	{190	,1	,1	,&B8IS12LDU},	//(do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
	{191	,1	,1	,&B8IS21LDU},	//(do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
	{192	,1	,1	,&B8IS22LDU},	//(do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
	{193	,1	,1	,&B9AD10LDU},	//(vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
	{194	,1	,1	,&B9IS11LDU},	//(do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
	{195	,1	,1	,&B9IS21LDU},	//(do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
	{196	,1	,1	,&C1MD31LP1},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
	{197	,1	,1	,&C1MD31LP2},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
	{198	,1	,1	,&C2MD31LP1},	//( - , SCM) Кнопка «СБРОС РБ»
	{199	,8	,1	,&LTAKTS},	//( - , - ) takt scm
	{200	,1	,1	,&R0AD16LDU},	//(vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
	{201	,8	,1	,&R0CR01RIM},	//( - , SCM) Коэффициент 12 связи АЗ1,2
	{202	,8	,1	,&R0CR02RIM},	//( - , SCM) Коэффициент 11 связи АЗ1,2
	{203	,3	,1	,&R0DEUMLSS},	//( - , SCM) Сигнал управления моделью
	{204	,1	,1	,&R0EE01LZ1},	//( - , SBz1) Питание  АКНП1  отключить
	{205	,1	,1	,&R0EE01LZ2},	//( - , SBz2) Питание  АКНП1  отключить
	{206	,1	,1	,&R0EE02LZ1},	//( - , SBz1) Питание  АКНП  отключить
	{207	,1	,1	,&R0EE02LZ2},	//( - , SBz2) Питание  АКНП  отключить
	{208	,1	,1	,&R0EE03LZ1},	//( - , SBz1) Питание  АКНП3  отключить
	{209	,1	,1	,&R0EE03LZ2},	//( - , SBz2) Питание  АКНП3  отключить
	{210	,1	,1	,&R0EE04LZ1},	//( - , SBz1) Питание  АКНП4  отключить
	{211	,1	,1	,&R0EE04LZ2},	//( - , SBz2) Питание  АКНП4  отключить
	{212	,8	,1	,&R0IN01FI1},	//( - , SA1) Выход СНМ11 Гц от ПТИ
	{213	,8	,1	,&R0IN01FI2},	//( - , SA2) Выход СНМ-11 Гц от ПТИ
	{214	,8	,1	,&R0IN01FI3},	//( - , SA3) Выход СНМ-11 Гц от ПТИ
	{215	,8	,1	,&R0IN01FI4},	//( - , SA4) Выход СНМ-11 Гц от ПТИ
	{216	,8	,1	,&R0IN01RIP},	//( - , SRP) Выход СНМ-11 Гц от ПТИ
	{217	,8	,1	,&R0IN02FI1},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	{218	,8	,1	,&R0IN02FI2},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	{219	,8	,1	,&R0IN02FI3},	//( - , SA3) Выход КНК15-1 Гц от ПТИ
	{220	,8	,1	,&R0IN02FI4},	//( - , SA4) Выход КНК15-1 Гц от ПТИ
	{221	,8	,1	,&R0IN02RIP},	//( - , SRP) Выход КНК15- Гц от ПТИ
	{222	,8	,1	,&R0IN03FI1},	//( - , SA1) Выход КНК53М Гц от ПТИ
	{223	,8	,1	,&R0IN03FI2},	//( - , SA2) Выход КНК53М Гц от ПТИ
	{224	,8	,1	,&R0IN03FI3},	//( - , SA3) Выход КНК53М Гц от ПТИ
	{225	,8	,1	,&R0IN03FI4},	//( - , SA4) Выход КНК53М Гц от ПТИ
	{226	,8	,1	,&R0IN03RIP},	//( - , SRP) Выход КНК53М Гц от ПТИ
	{227	,8	,1	,&R0IN06RIP},	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
	{228	,8	,1	,&R0IN07RIP},	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
	{229	,1	,1	,&R0IS01FI0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{230	,1	,1	,&R0IS02LDU},	//(do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
	{231	,3	,1	,&R0MW11IP1},	//( - , SCM) Переключатель ВЫСТРЕЛ
	{232	,1	,1	,&R0MW13LP2},	//( - , SCM) Переключатель «СЕТЬ»
	{233	,1	,1	,&R0S01LIM},	//(vds32_pti:360 - K32VDSR, - ) Отключение сетевых передач ПТИ
	{234	,8	,1	,&R0SR01RIM},	//( - , SCM) Текущая реактивность PУ
	{235	,8	,1	,&R0SR02RIM},	//( - , SCM) Текущая мощность РУ (ватт)
	{236	,8	,1	,&R0SR03RIM},	//( - , SCM) Текущая мощность РУ аз1  (ватт)
	{237	,8	,1	,&R0ST01RIM},	//( - , SCM) Текущий период разгона РУ
	{238	,1	,1	,&R0VZ71LZ1},	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
	{239	,1	,1	,&R0VZ71LZ2},	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
	{240	,1	,1	,&R1AD10LDU},	//(vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
	{241	,1	,1	,&R1AD20LDU},	//(vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
	{242	,1	,1	,&R1IS11LDU},	//(do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
	{243	,1	,1	,&R1IS21LDU},	//(do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
	{244	,1	,1	,&R1VS12LDU},	//( - , SCM) Движение МДЗ1 в сторону ВУ
	{245	,1	,1	,&R1VS22LDU},	//( - , SCM) Движение МДЗ1 в сторону НУ
	{246	,1	,1	,&R2AD10LDU},	//(vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
	{247	,1	,1	,&R2AD20LDU},	//(vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
	{248	,1	,1	,&R2IS11LDU},	//(do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
	{249	,1	,1	,&R2IS21LDU},	//(do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
	{250	,1	,1	,&R2VS12LDU},	//( - , SCM) Движение МДЗ2 в сторону ВУ
	{251	,1	,1	,&R2VS22LDU},	//( - , SCM) Движение МДЗ2 в сторону НУ
	{252	,1	,1	,&R3IS11LDU},	//(do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
	{253	,1	,1	,&R3IS21LDU},	//(do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
	{254	,1	,1	,&R4AD10LDU},	//(vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
	{255	,1	,1	,&R4AD20LDU},	//(vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
	{256	,1	,1	,&R4IS11LDU},	//(do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
	{257	,1	,1	,&R4IS12LDU},	//(do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
	{258	,1	,1	,&R4IS21LDU},	//(do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
	{259	,1	,1	,&R4IS22LDU},	//(do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
	{260	,1	,1	,&R4VS12LDU},	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
	{261	,1	,1	,&R4VS22LDU},	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
	{262	,1	,1	,&R5IS11LDU},	//(do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
	{263	,1	,1	,&R5IS21LDU},	//(do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
	{264	,1	,1	,&R6IS21LDU},	//(do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
	{265	,1	,1	,&R6IS62LDU},	//( - , - ) Исправность ВИП ССДИ-39 1канал
	{266	,1	,1	,&R6IS63LDU},	//( - , - ) Исправность ВИП ССДИ-39 2канал
	{267	,1	,1	,&R6IS64LDU},	//( - , - ) Исправность ВИП ССДИ-35 1канал
	{268	,1	,1	,&R6IS65LDU},	//( - , - ) Исправность ВИП ССДИ-35 2канал
	{269	,1	,1	,&R6IS66LZZ},	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{270	,1	,1	,&R6IS67LZZ},	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{271	,1	,1	,&R6IS68LZZ},	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
	{272	,1	,1	,&R7II71LZ1},	//(do32_pti:110 - K08DO, - ) Сработала АС IУР (датчик 1)
	{273	,1	,1	,&R7II71LZ2},	//(do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
	{274	,1	,1	,&R7II72LZ1},	//(do32_pti:110 - K07DO, - ) Сработала АС IУР (датчик 2)
	{275	,1	,1	,&R7II72LZ2},	//(do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
	{276	,1	,1	,&R7II73LZ1},	//(do32_pti:110 - K09DO, - ) Сработала АС IIУР
	{277	,1	,1	,&R7II73LZ2},	//(do32_pti:110 - K26DO, - ) Сработала АС IIУР
	{278	,1	,1	,&R8AD21LDU},	//(vds32_pti:310 - K31VDSR, - ) Имитация прихода на ВУ ИС для КВДС
	{279	,1	,1	,&R8AD22LDU},	//(do32_pti:140 - K09DO, - ) Сигнал синхронизации с импульсом
	{280	,1	,1	,&R8IS11LDU},	//(do32_pti:130 - K14DO, - ) Аварийный НИ установлен
	{281	,3	,1	,&TerR0IN06FRP},	//( - , - ) Неисправности СНМ-11 -1,2
	{282	,1	,1	,&bFirstEnterFlag},	//(bFirstEnterFlag) 
	{283	,8	,1	,&fEM_A0UN01RIM},	//(A0UN01RIM) Мощность источника нейтронов ИНИ
	{284	,8	,1	,&fEM_A0UN02RIM},	//(A0UN02RIM) Мощность источника нейтронов с АНИ
	{285	,8	,1	,&fEM_A0UN07RIM},	//(A0UN07RIM) Доля запаздывающих нейтронов
	{286	,8	,1	,&fEM_A0UP01RIM},	//(A0UP01RIM) Текущее давление в АЗ1,2
	{287	,8	,1	,&fEM_A0UP02RIM},	//(A0UP02RIM) Текущее давление в АЗ1,2
	{288	,8	,1	,&fEM_A0UR01RSP},	//(A0UR01RSP) Стартовая  реактивность АЗ1
	{289	,8	,1	,&fEM_A0UR02RSP},	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
	{290	,8	,1	,&fEM_A0UT03RSP},	//(A0UT03RSP) Стартовая  температура АЗ1 град
	{291	,8	,1	,&fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{292	,8	,1	,&fEM_A0UX01RSS},	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
	{293	,8	,1	,&fEM_A0UX02RSS},	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
	{294	,8	,1	,&fEM_A0UX03RSS},	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
	{295	,8	,1	,&fEM_A0UX04RSS},	//(A0UX04RSS) Первый коэффициент калибровки камеры4
	{296	,8	,1	,&fEM_A0UX05RSS},	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
	{297	,8	,1	,&fEM_A0UX06RSS},	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
	{298	,8	,1	,&fEM_A0UX07RSS},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{299	,8	,1	,&fEM_A0UX08RSS},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{300	,8	,1	,&fEM_A0UX09RSS},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{301	,8	,1	,&fEM_A0UX10RSS},	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
	{302	,8	,1	,&fEM_A0UX11RSS},	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
	{303	,8	,1	,&fEM_A0UX12RSS},	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
	{304	,8	,1	,&fEM_A0UX13RSS},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{305	,8	,1	,&fEM_A0UX14RSS},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{306	,8	,1	,&fEM_A0UX15RSS},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{307	,8	,1	,&fEM_A1MC01RC1},	//(A1MC01RC1) Заданная координата  ББ1 от ИС
	{308	,8	,1	,&fEM_A1MC01RSP},	//(A1MC01RSP) Стартовая координата  ББ1
	{309	,8	,1	,&fEM_A1MC02RC1},	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
	{310	,8	,1	,&fEM_A1MC02RSP},	//(A1MC02RSP) Стартовая координата штока ББ1
	{311	,8	,1	,&fEM_A1MV01RC1},	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
	{312	,8	,1	,&fEM_A1MV02RC1},	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
	{313	,8	,1	,&fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
	{314	,8	,1	,&fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
	{315	,8	,1	,&fEM_A1UC04RIM},	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
	{316	,8	,1	,&fEM_A1UC05RIM},	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
	{317	,8	,1	,&fEM_A1UC06RIM},	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
	{318	,8	,1	,&fEM_A1UC08RIM},	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
	{319	,8	,1	,&fEM_A1UG01RDU},	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
	{320	,8	,1	,&fEM_A1UP01RIM},	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
	{321	,8	,1	,&fEM_A1UP82RIM},	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{322	,8	,1	,&fEM_A1UR00RIM},	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{323	,8	,1	,&fEM_A1UR01RIM},	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{324	,8	,1	,&fEM_A1US07RDU},	//(A1US07RDU) Постоянная времени масляного демпфера ББ
	{325	,8	,1	,&fEM_A1UV02RIM},	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{326	,8	,1	,&fEM_A2MC01RC1},	//(A2MC01RC1) Заданная координата РБ1 от ИС
	{327	,8	,1	,&fEM_A2MC01RSP},	//(A2MC01RSP) Стартовая координата  РБ1
	{328	,8	,1	,&fEM_A2MC02RC1},	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
	{329	,8	,1	,&fEM_A2MC02RSP},	//(A2MC02RSP) Стартовая координата штока РБ1
	{330	,8	,1	,&fEM_A2MV01RC1},	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
	{331	,8	,1	,&fEM_A2MV02RC1},	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
	{332	,8	,1	,&fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
	{333	,8	,1	,&fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
	{334	,8	,1	,&fEM_A2UC04RIM},	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
	{335	,8	,1	,&fEM_A2UC05RIM},	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
	{336	,8	,1	,&fEM_A2UC06RIM},	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
	{337	,8	,1	,&fEM_A2UC08RIM},	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
	{338	,8	,1	,&fEM_A2UG01RDU},	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
	{339	,8	,1	,&fEM_A2UP01RIM},	//(A2UP01RIM) Текущее давление на сброс РБ
	{340	,8	,1	,&fEM_A2UP02RIM},	//(A2UP02RIM) Текущее давление на подъём РБ
	{341	,8	,1	,&fEM_A2UP03RDU},	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
	{342	,8	,1	,&fEM_A2UP03RIM},	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
	{343	,8	,1	,&fEM_A2UP04RDU},	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
	{344	,8	,1	,&fEM_A2UR00RIM},	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
	{345	,8	,1	,&fEM_A2UR01RIM},	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
	{346	,8	,1	,&fEM_A2US07RDU},	//(A2US07RDU) Постоянная времени масляного демпфера РБ
	{347	,8	,1	,&fEM_A2UV02RIM},	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{348	,8	,1	,&fEM_A3MC01RC1},	//(A3MC01RC1) Заданная координата ИС1 от ИС
	{349	,8	,1	,&fEM_A3MC01RSP},	//(A3MC01RSP) Стартовая координата  ИС1
	{350	,8	,1	,&fEM_A3MC02RC1},	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
	{351	,8	,1	,&fEM_A3MC02RSP},	//(A3MC02RSP) Стартовая координата штока ИС1
	{352	,8	,1	,&fEM_A3MV01RC1},	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
	{353	,8	,1	,&fEM_A3MV02RC1},	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
	{354	,8	,1	,&fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
	{355	,8	,1	,&fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
	{356	,8	,1	,&fEM_A3UC04RIM},	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
	{357	,8	,1	,&fEM_A3UC05RIM},	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
	{358	,8	,1	,&fEM_A3UC06RIM},	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
	{359	,8	,1	,&fEM_A3UC08RIM},	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
	{360	,8	,1	,&fEM_A3UG01RDU},	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
	{361	,8	,1	,&fEM_A3UP01RIM},	//(A3UP01RIM) Текущее давление на СПУСК ИС
	{362	,8	,1	,&fEM_A3UP02RDU},	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
	{363	,8	,1	,&fEM_A3UP02RIM},	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
	{364	,8	,1	,&fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{365	,8	,1	,&fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{366	,8	,1	,&fEM_A3UR00RIM},	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{367	,8	,1	,&fEM_A3UR01RIM},	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{368	,8	,1	,&fEM_A3US07RDU},	//(A3US07RDU) Постоянная времени масляного демпфера ИС
	{369	,8	,1	,&fEM_A3UV02RIM},	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{370	,8	,1	,&fEM_A4MC01RSP},	//(A4MC01RSP) Стартовая координата НИ1
	{371	,8	,1	,&fEM_A4UL10RIM},	//(A4UL10RIM) Время полного перемещения НИ сек
	{372	,8	,1	,&fEM_A4UP01RIM},	//(A4UP01RIM) Текущее давление на подъём НИ
	{373	,8	,1	,&fEM_A4UP02RIM},	//(A4UP02RIM) Нижняя граница давления на подъём НИ
	{374	,8	,1	,&fEM_A5MC01RC1},	//(A5MC01RC1) Заданная координата НЛ1 от ИС
	{375	,8	,1	,&fEM_A5MC01RSP},	//(A5MC01RSP) Стартовая координата НЛ1
	{376	,8	,1	,&fEM_A5MV01RC1},	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
	{377	,8	,1	,&fEM_A5UC10RIM},	//(A5UC10RIM) Время полного хода НЛ сек
	{378	,8	,1	,&fEM_A6MC01RC1},	//(A6MC01RC1) Заданная координата БЗ1 от ИС
	{379	,8	,1	,&fEM_A6MC01RSP},	//(A6MC01RSP) Стартовая координата БЗ1
	{380	,8	,1	,&fEM_A6MV01RC1},	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
	{381	,8	,1	,&fEM_A6UC10RIM},	//(A6UC10RIM) Время полного хода БЗ (сек)
	{382	,8	,1	,&fEM_A6US80RDU},	//(A6US80RDU) Тормозной путь БЗ (мм)
	{383	,8	,1	,&fEM_A8MC01RC1},	//(A8MC01RC1) Заданная координата ДС2 от ИС
	{384	,8	,1	,&fEM_A8MC01RSP},	//(A8MC01RSP) Стартовая координата ДС2
	{385	,8	,1	,&fEM_A8MV01RC1},	//(A8MV01RC1) Заданная скорость ДС2 от ИС
	{386	,8	,1	,&fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
	{387	,8	,1	,&fEM_A8UC08RDU},	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
	{388	,8	,1	,&fEM_A8UC10RIM},	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
	{389	,8	,1	,&fEM_A8UC11RIM},	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
	{390	,8	,1	,&fEM_A8UC20RIM},	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
	{391	,8	,1	,&fEM_A8UC21RIM},	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
	{392	,8	,1	,&fEM_A8US80RDU},	//(A8US80RDU) Тормозной путь ДС2 (мм)
	{393	,8	,1	,&fEM_A8UV80RDU},	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
	{394	,8	,1	,&fEM_A9MC01RSP},	//(A9MC01RSP) Стартовая координата НИ ДС1
	{395	,8	,1	,&fEM_A9UL10RIM},	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
	{396	,8	,1	,&fEM_B0UT03RSP},	//(B0UT03RSP) Стартовая  температура АЗ2 град
	{397	,8	,1	,&fEM_B0UX01RSS},	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
	{398	,8	,1	,&fEM_B0UX02RSS},	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
	{399	,8	,1	,&fEM_B0UX03RSS},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{400	,8	,1	,&fEM_B0UX04RSS},	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
	{401	,8	,1	,&fEM_B0UX05RSS},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{402	,8	,1	,&fEM_B0UX06RSS},	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
	{403	,8	,1	,&fEM_B0UX07RSS},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{404	,8	,1	,&fEM_B0UX08RSS},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{405	,8	,1	,&fEM_B0UX09RSS},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{406	,8	,1	,&fEM_B0UX10RSS},	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
	{407	,8	,1	,&fEM_B0UX11RSS},	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
	{408	,8	,1	,&fEM_B0UX12RSS},	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
	{409	,8	,1	,&fEM_B1MC01RC1},	//(B1MC01RC1) Заданная координата ББ2 от ИС
	{410	,8	,1	,&fEM_B1MC01RSP},	//(B1MC01RSP) Стартовая координата  ББ2
	{411	,8	,1	,&fEM_B1MC02RC1},	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
	{412	,8	,1	,&fEM_B1MC02RSP},	//(B1MC02RSP) Стартовая координата штока ББ2
	{413	,8	,1	,&fEM_B1MV01RC1},	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
	{414	,8	,1	,&fEM_B1MV02RC1},	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
	{415	,8	,1	,&fEM_B2MC01RC1},	//(B2MC01RC1) Заданная координата РБ2 от ИС
	{416	,8	,1	,&fEM_B2MC01RSP},	//(B2MC01RSP) Стартовая координата  РБ2
	{417	,8	,1	,&fEM_B2MC02RC1},	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
	{418	,8	,1	,&fEM_B2MC02RSP},	//(B2MC02RSP) Стартовая координата штока РБ2
	{419	,8	,1	,&fEM_B2MV01RC1},	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
	{420	,8	,1	,&fEM_B2MV02RC1},	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
	{421	,8	,1	,&fEM_B3MC01RC1},	//(B3MC01RC1) Заданная координата ИС2 от ИС
	{422	,8	,1	,&fEM_B3MC01RSP},	//(B3MC01RSP) Стартовая координата  ИС2
	{423	,8	,1	,&fEM_B3MC02RC1},	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
	{424	,8	,1	,&fEM_B3MC02RSP},	//(B3MC02RSP) Стартовая координата штока ИС2
	{425	,8	,1	,&fEM_B3MV01RC1},	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
	{426	,8	,1	,&fEM_B3MV02RC1},	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
	{427	,8	,1	,&fEM_B4MC01RSP},	//(B4MC01RSP) Стартовая координата НИ2
	{428	,8	,1	,&fEM_B5MC01RC1},	//(B5MC01RC1) Заданная координата НЛ2 от ИС
	{429	,8	,1	,&fEM_B5MC01RSP},	//(B5MC01RSP) Стартовая координата НЛ2
	{430	,8	,1	,&fEM_B5MV01RC1},	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
	{431	,8	,1	,&fEM_B6MC01RC1},	//(B6MC01RC1) Заданная координата БЗ2 от ИС
	{432	,8	,1	,&fEM_B6MC01RSP},	//(B6MC01RSP) Стартовая координата БЗ2
	{433	,8	,1	,&fEM_B6MV01RC1},	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
	{434	,8	,1	,&fEM_B8MC01RC1},	//(B8MC01RC1) Заданная координата АЗ2 от ИС
	{435	,8	,1	,&fEM_B8MC01RSP},	//(B8MC01RSP) Стартовая координата АЗ2
	{436	,8	,1	,&fEM_B8MV01RC1},	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
	{437	,8	,1	,&fEM_B8UC08RDU},	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
	{438	,8	,1	,&fEM_B8UC10RIM},	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
	{439	,8	,1	,&fEM_B8UC11RIM},	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
	{440	,8	,1	,&fEM_B8UC20RIM},	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
	{441	,8	,1	,&fEM_B8UC21RIM},	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
	{442	,8	,1	,&fEM_B8US80RDU},	//(B8US80RDU) Тормозной путь АЗ2 (мм)
	{443	,8	,1	,&fEM_B8UV80RDU},	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
	{444	,8	,1	,&fEM_B9MC01RSP},	//(B9MC01RSP) Стартовая координата НИ ДС2
	{445	,8	,1	,&fEM_R0UH01RSS},	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
	{446	,8	,1	,&fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
	{447	,8	,1	,&fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
	{448	,8	,1	,&fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{449	,8	,1	,&fEM_R0UH21RSS},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{450	,8	,1	,&fEM_R0UH22RSS},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{451	,8	,1	,&fEM_R0UH23RSS},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{452	,8	,1	,&fEM_R0UL01RIM},	//(R0UL01RIM) Среднее время генерации нейтронов
	{453	,8	,1	,&fEM_R0UL02RDU},	//(R0UL02RDU) Время задержки  ИНИ
	{454	,8	,1	,&fEM_R0UL02RIM},	//(R0UL02RIM) Время удержания синхроимпульса
	{455	,8	,1	,&fEM_R0UL04RIM},	//(R0UL04RIM) Время блокировки повторной генерации импульса
	{456	,8	,1	,&fEM_R0UN02RIM},	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{457	,8	,1	,&fEM_R0UN18RDU},	//(R0UN18RDU) Коэффициент температурной корректировки реактивности(долл)
	{458	,8	,1	,&fEM_R0UR01RIM},	//(R0UR01RIM) Стартовая отрицательная реактивность
	{459	,8	,1	,&fEM_R0UR30RIM},	//(R0UR30RIM) Реактивность вносимая образцами (долл)
	{460	,8	,1	,&fEM_R0UT01RDU},	//(R0UT01RDU) Нижний предел шкалы датчика температуры
	{461	,8	,1	,&fEM_R0UT02RDU},	//(R0UT02RDU) Верхний предел шкалы датчика температуры
	{462	,8	,1	,&fEM_R0UT02RIM},	//(R0UT02RIM) Масса топлива в АЗ
	{463	,8	,1	,&fEM_R0UT03RIM},	//(R0UT03RIM) Нормальная температура АЗ град
	{464	,8	,1	,&fEM_R0UT04RIM},	//(R0UT04RIM) Удельная теплоёмкость топлива
	{465	,8	,1	,&fEM_R0UT05RIM},	//(R0UT05RIM) Энергия деления ядра
	{466	,8	,1	,&fEM_R0UT06RIM},	//(R0UT06RIM) Конвекционное сопротивление при обдуве
	{467	,8	,1	,&fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{468	,8	,1	,&fEM_R0UV82RDU},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{469	,8	,1	,&fEM_R0UV83RDU},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{470	,8	,1	,&fEM_R0UV84RDU},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{471	,8	,1	,&fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{472	,8	,1	,&fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{473	,8	,1	,&fEM_R0UV87RDU},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{474	,8	,1	,&fEM_R1MC01RC1},	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
	{475	,8	,1	,&fEM_R1MC01RSP},	//(R1MC01RSP) Стартовая координата МДЗ1
	{476	,8	,1	,&fEM_R1MV01RC1},	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
	{477	,8	,1	,&fEM_R1UC10RIM},	//(R1UC10RIM) Время полного хода МДЗ сек
	{478	,8	,1	,&fEM_R2MC01RC1},	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
	{479	,8	,1	,&fEM_R2MC01RSP},	//(R2MC01RSP) Стартовая координата МДЗ2
	{480	,8	,1	,&fEM_R2MV01RC1},	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
	{481	,8	,1	,&fEM_R3UC01RSP},	//(R3UC01RSP) Стартовая координата Гомогенных дверей
	{482	,8	,1	,&fEM_R3UL10RIM},	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
	{483	,8	,1	,&fEM_R4MC01RC1},	//(R4MC01RC1) Заданная координата тележки от ИС
	{484	,8	,1	,&fEM_R4MC01RSP},	//(R4MC01RSP) Стартовая координата тележки
	{485	,8	,1	,&fEM_R4MV01RC1},	//(R4MV01RC1) Заданная скорость тележки от ИС
	{486	,8	,1	,&fEM_R4UC08RDU},	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
	{487	,8	,1	,&fEM_R4UC10RIM},	//(R4UC10RIM) Координата верхних механических упоров тележки мм
	{488	,8	,1	,&fEM_R4UC20RIM},	//(R4UC20RIM) Координата нижних механических упоров тележки мм
	{489	,8	,1	,&fEM_R4UC22RIM},	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
	{490	,8	,1	,&fEM_R4US80RDU},	//(R4US80RDU) Тормозной путь тележки (мм)
	{491	,8	,1	,&fEM_R4UV80RDU},	//(R4UV80RDU) Номинальная скорость тележки (см/с)
	{492	,8	,1	,&fEM_R5UC01RSP},	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
	{493	,8	,1	,&fEM_R5UL10RIM},	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
	{494	,8	,1	,&fEM_R6UC01RSP},	//(R6UC01RSP) Стартовая координата Кран-балки
	{495	,8	,1	,&fEM_R6UL10RIM},	//(R6UL10RIM) Время полного хода кран-балки сек
	{496	,8	,1	,&fEM_R7UC10RIM},	//(R7UC10RIM) X-координата КНК53М R7IN13 см
	{497	,8	,1	,&fEM_R7UC19RIM},	//(R7UC19RIM) Y-координата СНМ-11 (11) см
	{498	,8	,1	,&fEM_R7UI02RIM},	//(R7UI02RIM) Коэффициент усиления уровня радиации
	{499	,8	,1	,&fEM_R7UI71RIM},	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{500	,8	,1	,&fEM_R7UI72RIM},	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
	{501	,8	,1	,&fEM_R7UI73RIM},	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
	{502	,8	,1	,&fEM_R7UI74RIM},	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
	{503	,8	,1	,&fEM_R7UI75RIM},	//(R7UI75RIM) Множитель к уровню радиации
	{504	,8	,1	,&fEM_R7UI76RIM},	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{505	,8	,1	,&fEM_R7UI77RIM},	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{506	,8	,1	,&fEM_R7UL01RIM},	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
	{507	,8	,1	,&fEM_R7UX01RSS},	//(R7UX01RSS) X-координата камеры R7IN11
	{508	,8	,1	,&fEM_R7UX02RSS},	//(R7UX02RSS) X-координата камеры R7IN12 (см)
	{509	,8	,1	,&fEM_R7UX04RSS},	//(R7UX04RSS) X-координата камеры R7IN21 (см)
	{510	,8	,1	,&fEM_R7UX05RSS},	//(R7UX05RSS) X-координата камеры R7IN22 (см)
	{511	,8	,1	,&fEM_R7UX06RSS},	//(R7UX06RSS) X-координата камеры R7IN23 (см)
	{512	,8	,1	,&fEM_R7UX07RSS},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{513	,8	,1	,&fEM_R7UX08RSS},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{514	,8	,1	,&fEM_R7UX09RSS},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{515	,8	,1	,&fEM_R7UX10RSS},	//(R7UX10RSS) X-координата камеры R7IN41
	{516	,8	,1	,&fEM_R7UX11RSS},	//(R7UX11RSS) X-координата камеры R7IN42
	{517	,8	,1	,&fEM_R7UX12RSS},	//(R7UX12RSS) X-координата камеры R7IN43
	{518	,8	,1	,&fEM_R7UX13RSS},	//(R7UX13RSS) X-координата камеры R7IN51
	{519	,8	,1	,&fEM_R7UX14RSS},	//(R7UX14RSS) X-координата камеры R7IN52
	{520	,8	,1	,&fEM_R7UX15RSS},	//(R7UX15RSS) X-координата камеры R7IN53
	{521	,8	,1	,&fEM_R7UX16RSS},	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
	{522	,8	,1	,&fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 см
	{523	,8	,1	,&fEM_R7UY01RSS},	//(R7UY01RSS) Y-координата камеры R7IN11
	{524	,8	,1	,&fEM_R7UY02RSS},	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
	{525	,8	,1	,&fEM_R7UY04RSS},	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
	{526	,8	,1	,&fEM_R7UY05RSS},	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
	{527	,8	,1	,&fEM_R7UY06RSS},	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
	{528	,8	,1	,&fEM_R7UY07RSS},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{529	,8	,1	,&fEM_R7UY08RSS},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{530	,8	,1	,&fEM_R7UY09RSS},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{531	,8	,1	,&fEM_R7UY10RSS},	//(R7UY10RSS) Y-координата камеры R7IN41
	{532	,8	,1	,&fEM_R7UY11RSS},	//(R7UY11RSS) Y-координата камеры R7IN42
	{533	,8	,1	,&fEM_R7UY12RSS},	//(R7UY12RSS) Y-координата камеры R7IN43
	{534	,8	,1	,&fEM_R7UY13RSS},	//(R7UY13RSS) Y-координата камеры R7IN51
	{535	,8	,1	,&fEM_R7UY14RSS},	//(R7UY14RSS) Y-координата камеры R7IN52
	{536	,8	,1	,&fEM_R7UY15RSS},	//(R7UY15RSS) Y-координата камеры R7IN53
	{537	,3	,1	,&iEM_TERA0MT01RIM},	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
	{538	,3	,1	,&iEM_TERA0VP81LIM},	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
	{539	,3	,1	,&iEM_TERA1IE03LDU},	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
	{540	,3	,1	,&iEM_TERA1IE04LDU},	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
	{541	,3	,1	,&iEM_TERA1SC01RIM},	//(TERA1SC01RIM) Искажение: Координата штока ББ1
	{542	,3	,1	,&iEM_TERA1SS11LIM},	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
	{543	,3	,1	,&iEM_TERA1SS12LIM},	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
	{544	,3	,1	,&iEM_TERA1SS21LIM},	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
	{545	,3	,1	,&iEM_TERA1VP81LIM},	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
	{546	,3	,1	,&iEM_TERA2SC01RIM},	//(TERA2SC01RIM) Искажение: Координата штока РБ1
	{547	,3	,1	,&iEM_TERA2SP01RIM},	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
	{548	,3	,1	,&iEM_TERA2SS11LIM},	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
	{549	,3	,1	,&iEM_TERA2SS12LIM},	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
	{550	,3	,1	,&iEM_TERA2SS21LIM},	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
	{551	,3	,1	,&iEM_TERA2SS33LIM},	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{552	,3	,1	,&iEM_TERA2VP82LIM},	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
	{553	,3	,1	,&iEM_TERA3SC01RIM},	//(TERA3SC01RIM) Искажение: Координата штока ИС1
	{554	,3	,1	,&iEM_TERA3SP02RIM},	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{555	,3	,1	,&iEM_TERA3SS11LIM},	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
	{556	,3	,1	,&iEM_TERA3SS21LIM},	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
	{557	,3	,1	,&iEM_TERA3SS22LIM},	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
	{558	,3	,1	,&iEM_TERA3SS31LIM},	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{559	,3	,1	,&iEM_TERA3SS33LIM},	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{560	,3	,1	,&iEM_TERA3VP81LIM},	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
	{561	,3	,1	,&iEM_TERA4SS11LIM},	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
	{562	,3	,1	,&iEM_TERA4SS21LIM},	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
	{563	,3	,1	,&iEM_TERA4VP82LIM},	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
	{564	,3	,1	,&iEM_TERA5SS11LIM},	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
	{565	,3	,1	,&iEM_TERA5SS21LIM},	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
	{566	,3	,1	,&iEM_TERA5VS12LIM},	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
	{567	,3	,1	,&iEM_TERA5VS22LIM},	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
	{568	,3	,1	,&iEM_TERA6MS11LIM},	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
	{569	,3	,1	,&iEM_TERA6SS21LIM},	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
	{570	,3	,1	,&iEM_TERA6VS12LIM},	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
	{571	,3	,1	,&iEM_TERA6VS22LIM},	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
	{572	,3	,1	,&iEM_TERA7MS31LIM},	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{573	,3	,1	,&iEM_TERA8SC01RIM},	//(TERA8SC01RIM) Искажение: Координата ДС2
	{574	,3	,1	,&iEM_TERA8SS12LIM},	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
	{575	,3	,1	,&iEM_TERA8SS22LIM},	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
	{576	,3	,1	,&iEM_TERA9SS11LIM},	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
	{577	,3	,1	,&iEM_TERA9SS21LIM},	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
	{578	,3	,1	,&iEM_TERB0MT01RIM},	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
	{579	,3	,1	,&iEM_TERB0VP81LIM},	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
	{580	,3	,1	,&iEM_TERB1IE03LDU},	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
	{581	,3	,1	,&iEM_TERB1IE04LDU},	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
	{582	,3	,1	,&iEM_TERB1MC01RIM},	//(TERB1MC01RIM) Искажение: Координата штока ББ2
	{583	,3	,1	,&iEM_TERB1SS11LIM},	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
	{584	,3	,1	,&iEM_TERB1SS12LIM},	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
	{585	,3	,1	,&iEM_TERB1SS21LIM},	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
	{586	,3	,1	,&iEM_TERB1VP81LIM},	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
	{587	,3	,1	,&iEM_TERB2SC01RIM},	//(TERB2SC01RIM) Искажение: Координата штока РБ2
	{588	,3	,1	,&iEM_TERB2SP01RIM},	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
	{589	,3	,1	,&iEM_TERB2SS11LIM},	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
	{590	,3	,1	,&iEM_TERB2SS12LIM},	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
	{591	,3	,1	,&iEM_TERB2SS21LIM},	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
	{592	,3	,1	,&iEM_TERB2SS33LIM},	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{593	,3	,1	,&iEM_TERB3SC01RIM},	//(TERB3SC01RIM) Искажение: Координата штока ИС2
	{594	,3	,1	,&iEM_TERB3SP02RIM},	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{595	,3	,1	,&iEM_TERB3SS11LIM},	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
	{596	,3	,1	,&iEM_TERB3SS21LIM},	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
	{597	,3	,1	,&iEM_TERB3SS22LIM},	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
	{598	,3	,1	,&iEM_TERB3SS31LIM},	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{599	,3	,1	,&iEM_TERB3SS33LIM},	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{600	,3	,1	,&iEM_TERB4SS11LIM},	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
	{601	,3	,1	,&iEM_TERB4SS21LIM},	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
	{602	,3	,1	,&iEM_TERB5SS11LIM},	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
	{603	,3	,1	,&iEM_TERB5SS21LIM},	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
	{604	,3	,1	,&iEM_TERB5VS12LIM},	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
	{605	,3	,1	,&iEM_TERB5VS22LIM},	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
	{606	,3	,1	,&iEM_TERB6SS11LIM},	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
	{607	,3	,1	,&iEM_TERB6SS21LIM},	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
	{608	,3	,1	,&iEM_TERB6VS12LIM},	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
	{609	,3	,1	,&iEM_TERB6VS22LIM},	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
	{610	,3	,1	,&iEM_TERB7MS31LIM},	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	{611	,3	,1	,&iEM_TERB8SC01RIM},	//(TERB8SC01RIM) Искажение: Координата АЗ2
	{612	,3	,1	,&iEM_TERB8SS12LIM},	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
	{613	,3	,1	,&iEM_TERB8SS22LIM},	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
	{614	,3	,1	,&iEM_TERB9SS11LIM},	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
	{615	,3	,1	,&iEM_TERB9SS21LIM},	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
	{616	,3	,1	,&iEM_TERBB1},	//(TERBB1) Неисправности  ББ1
	{617	,3	,1	,&iEM_TERBB2},	//(TERBB2) Неисправности  ББ2
	{618	,3	,1	,&iEM_TERBZ1},	//(TERBZ1) Неисправности БЗ1
	{619	,3	,1	,&iEM_TERBZ2},	//(TERBZ2) Неисправности БЗ2
	{620	,3	,1	,&iEM_TERDS2},	//(TERDS2) Неисправности ДС2 от ИС
	{621	,3	,1	,&iEM_TERIS1},	//(TERIS1) Неисправности  ИС1
	{622	,3	,1	,&iEM_TERIS2},	//(TERIS2) Неисправности  ИС2
	{623	,3	,1	,&iEM_TERMAZ2},	//(TERMAZ2) Неисправности АЗ2 от ИС
	{624	,3	,1	,&iEM_TERMDZ1},	//(TERMDZ1) Неисправности МДЗ1
	{625	,3	,1	,&iEM_TERMDZ2},	//(TERMDZ2) Неисправности МДЗ2
	{626	,3	,1	,&iEM_TERNL1},	//(TERNL1) Неисправности НЛ1
	{627	,3	,1	,&iEM_TERNL2},	//(TERNL2) Неисправности НЛ2
	{628	,3	,1	,&iEM_TERR0VP81LIM},	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	{629	,3	,1	,&iEM_TERR1SS11LIM},	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
	{630	,3	,1	,&iEM_TERR1SS21LIM},	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
	{631	,3	,1	,&iEM_TERR1VS12LIM},	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
	{632	,3	,1	,&iEM_TERR1VS22LIM},	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
	{633	,3	,1	,&iEM_TERR2SS11LIM},	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
	{634	,3	,1	,&iEM_TERR2SS21LIM},	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
	{635	,3	,1	,&iEM_TERR2VS12LIM},	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
	{636	,3	,1	,&iEM_TERR2VS22LIM},	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
	{637	,3	,1	,&iEM_TERR3SS11LIM},	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
	{638	,3	,1	,&iEM_TERR3SS21LIM},	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
	{639	,3	,1	,&iEM_TERR4MS21LIM},	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
	{640	,3	,1	,&iEM_TERR4SS11LIM},	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
	{641	,3	,1	,&iEM_TERR4SS12LIM},	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
	{642	,3	,1	,&iEM_TERR4SS22LIM},	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
	{643	,3	,1	,&iEM_TERR4VS12LDU},	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{644	,3	,1	,&iEM_TERR4VS22LDU},	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{645	,3	,1	,&iEM_TERR5SS11LIM},	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
	{646	,3	,1	,&iEM_TERR5SS21LIM},	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
	{647	,3	,1	,&iEM_TERR6IS62LIM},	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
	{648	,3	,1	,&iEM_TERR6IS64LIM},	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
	{649	,3	,1	,&iEM_TERR6IS66LIM},	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{650	,3	,1	,&iEM_TERR6IS67LIM},	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
	{651	,3	,1	,&iEM_TERR6IS68LIM},	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
	{652	,3	,1	,&iEM_TERR6SS21LIM},	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
	{653	,3	,1	,&iEM_TERR7SI74RIM},	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
	{654	,3	,1	,&iEM_TERR8SS11LIM},	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
	{655	,3	,1	,&iEM_TERRB1},	//(TERRB1) Неисправности  РБ1
	{656	,3	,1	,&iEM_TERRB2},	//(TERRB2) Неисправности  РБ2
	{657	,3	,1	,&iEM_TERTLG},	//(TERTLG) Неисправности  тележки от ИС
	{658	,1	,1	,&internal1_m100_MyFirstEnterFlag},	//(internal1_m100_MyFirstEnterFlag) MyFirstEnterFlag
	{659	,1	,1	,&internal1_m100_Pav0},	//(internal1_m100_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{660	,1	,1	,&internal1_m100_Ppv0},	//(internal1_m100_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{661	,1	,1	,&internal1_m100_RA00},	//(internal1_m100_RA00) RA00 - последнее задание вперед
	{662	,1	,1	,&internal1_m100_RA10},	//(internal1_m100_RA10) RA10 - последнее задание назад
	{663	,1	,1	,&internal1_m100_RA30},	//(internal1_m100_RA30)  RA30 - разрешение движения
	{664	,1	,1	,&internal1_m100_RA50},	//(internal1_m100_RA50) Ra50 - последнее задание скорости
	{665	,8	,1	,&internal1_m100_RV00},	//(internal1_m100_RV00) V0 - текущая скорость ОРР
	{666	,8	,1	,&internal1_m100_Sh00},	//(internal1_m100_Sh00) Sh0 - текущая координата штока ОРР
	{667	,8	,1	,&internal1_m100_ShV00},	//(internal1_m100_ShV00) V0 - текущая скорость штока ОРР
	{668	,8	,1	,&internal1_m100_X00},	//(internal1_m100_X00) X0 - текущая координата ОРР
	{669	,1	,1	,&internal1_m100_Zav0},	//(internal1_m100_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{670	,1	,1	,&internal1_m100_flp},	//(internal1_m100_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{671	,1	,1	,&internal1_m100_fls},	//(internal1_m100_fls)  fls - флаг одношагового режима
	{672	,1	,1	,&internal1_m1012_Out10},	//(internal1_m1012_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{673	,1	,1	,&internal1_m1013_Out10},	//(internal1_m1013_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{674	,1	,1	,&internal1_m1014_Out10},	//(internal1_m1014_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{675	,1	,1	,&internal1_m1015_Out10},	//(internal1_m1015_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{676	,1	,1	,&internal1_m1016_Out10},	//(internal1_m1016_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{677	,1	,1	,&internal1_m1017_Out10},	//(internal1_m1017_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{678	,1	,1	,&internal1_m1018_Out10},	//(internal1_m1018_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{679	,1	,1	,&internal1_m1032_Out10},	//(internal1_m1032_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{680	,1	,1	,&internal1_m1033_Out10},	//(internal1_m1033_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{681	,1	,1	,&internal1_m1034_Out10},	//(internal1_m1034_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{682	,1	,1	,&internal1_m1035_Out10},	//(internal1_m1035_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{683	,1	,1	,&internal1_m1036_Out10},	//(internal1_m1036_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{684	,1	,1	,&internal1_m1037_Out10},	//(internal1_m1037_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{685	,1	,1	,&internal1_m136_MyFirstEnterFlag},	//(internal1_m136_MyFirstEnterFlag) MyFirstEnterFlag
	{686	,1	,1	,&internal1_m136_Pav0},	//(internal1_m136_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{687	,1	,1	,&internal1_m136_Ppv0},	//(internal1_m136_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{688	,1	,1	,&internal1_m136_RA00},	//(internal1_m136_RA00) RA00 - последнее задание вперед
	{689	,1	,1	,&internal1_m136_RA10},	//(internal1_m136_RA10) RA10 - последнее задание назад
	{690	,1	,1	,&internal1_m136_RA30},	//(internal1_m136_RA30)  RA30 - разрешение движения
	{691	,1	,1	,&internal1_m136_RA50},	//(internal1_m136_RA50) Ra50 - последнее задание скорости
	{692	,8	,1	,&internal1_m136_RV00},	//(internal1_m136_RV00) V0 - текущая скорость ОРР
	{693	,8	,1	,&internal1_m136_Sh00},	//(internal1_m136_Sh00) Sh0 - текущая координата штока ОРР
	{694	,8	,1	,&internal1_m136_ShV00},	//(internal1_m136_ShV00) V0 - текущая скорость штока ОРР
	{695	,8	,1	,&internal1_m136_X00},	//(internal1_m136_X00) X0 - текущая координата ОРР
	{696	,1	,1	,&internal1_m136_Zav0},	//(internal1_m136_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{697	,1	,1	,&internal1_m136_flp},	//(internal1_m136_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{698	,1	,1	,&internal1_m136_fls},	//(internal1_m136_fls)  fls - флаг одношагового режима
	{699	,8	,1	,&internal1_m14_C1},	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	{700	,8	,1	,&internal1_m14_C2},	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	{701	,8	,1	,&internal1_m14_C3},	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	{702	,8	,1	,&internal1_m14_C4},	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	{703	,8	,1	,&internal1_m14_C5},	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	{704	,8	,1	,&internal1_m14_C6},	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	{705	,1	,1	,&internal1_m14_ImpINI0},	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	{706	,1	,1	,&internal1_m14_MyFirstEnterFlag},	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
	{707	,8	,1	,&internal1_m14_N00},	//(internal1_m14_N00) N00 - Текущая концентрация нейтронов
	{708	,8	,1	,&internal1_m14_N20},	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
	{709	,8	,1	,&internal1_m14_R00},	//(internal1_m14_R00) R00 - Текущая реактивность
	{710	,8	,1	,&internal1_m14_T00},	//(internal1_m14_T00) T00 - Текущая температура
	{711	,1	,1	,&internal1_m151_Out10},	//(internal1_m151_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{712	,1	,1	,&internal1_m152_Out10},	//(internal1_m152_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{713	,8	,1	,&internal1_m176_x0},	//(internal1_m176_x0) x0 - значение входного параметра на предыдущем шаге
	{714	,8	,1	,&internal1_m186_C1},	//(internal1_m186_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	{715	,8	,1	,&internal1_m186_C2},	//(internal1_m186_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	{716	,8	,1	,&internal1_m186_C3},	//(internal1_m186_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	{717	,8	,1	,&internal1_m186_C4},	//(internal1_m186_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	{718	,8	,1	,&internal1_m186_C5},	//(internal1_m186_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	{719	,8	,1	,&internal1_m186_C6},	//(internal1_m186_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	{720	,1	,1	,&internal1_m186_ImpINI0},	//(internal1_m186_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	{721	,1	,1	,&internal1_m186_MyFirstEnterFlag},	//(internal1_m186_MyFirstEnterFlag) MyFirstEnterFlag
	{722	,8	,1	,&internal1_m186_N00},	//(internal1_m186_N00) N00 - Текущая концентрация нейтронов
	{723	,8	,1	,&internal1_m186_N20},	//(internal1_m186_N20) N20 - пред. концентрация нейтронов второй АЗ
	{724	,8	,1	,&internal1_m186_R00},	//(internal1_m186_R00) R00 - Текущая реактивность
	{725	,8	,1	,&internal1_m186_T00},	//(internal1_m186_T00) T00 - Текущая температура
	{726	,1	,1	,&internal1_m211_Out10},	//(internal1_m211_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{727	,1	,1	,&internal1_m228_Out10},	//(internal1_m228_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{728	,1	,1	,&internal1_m232_MyFirstEnterFlag},	//(internal1_m232_MyFirstEnterFlag) MyFirstEnterFlag
	{729	,1	,1	,&internal1_m232_Pav0},	//(internal1_m232_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{730	,1	,1	,&internal1_m232_Ppv0},	//(internal1_m232_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{731	,1	,1	,&internal1_m232_RA00},	//(internal1_m232_RA00) RA00 - последнее задание вперед
	{732	,1	,1	,&internal1_m232_RA10},	//(internal1_m232_RA10) RA10 - последнее задание назад
	{733	,1	,1	,&internal1_m232_RA30},	//(internal1_m232_RA30)  RA30 - разрешение движения
	{734	,1	,1	,&internal1_m232_RA50},	//(internal1_m232_RA50) Ra50 - последнее задание скорости
	{735	,8	,1	,&internal1_m232_RV00},	//(internal1_m232_RV00) V0 - текущая скорость ОРР
	{736	,8	,1	,&internal1_m232_Sh00},	//(internal1_m232_Sh00) Sh0 - текущая координата штока ОРР
	{737	,8	,1	,&internal1_m232_ShV00},	//(internal1_m232_ShV00) V0 - текущая скорость штока ОРР
	{738	,8	,1	,&internal1_m232_X00},	//(internal1_m232_X00) X0 - текущая координата ОРР
	{739	,1	,1	,&internal1_m232_Zav0},	//(internal1_m232_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{740	,1	,1	,&internal1_m232_flp},	//(internal1_m232_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{741	,1	,1	,&internal1_m232_fls},	//(internal1_m232_fls)  fls - флаг одношагового режима
	{742	,1	,1	,&internal1_m270_MyFirstEnterFlag},	//(internal1_m270_MyFirstEnterFlag) MyFirstEnterFlag
	{743	,1	,1	,&internal1_m270_Pav0},	//(internal1_m270_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{744	,1	,1	,&internal1_m270_Ppv0},	//(internal1_m270_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{745	,1	,1	,&internal1_m270_RA00},	//(internal1_m270_RA00) RA00 - последнее задание вперед
	{746	,1	,1	,&internal1_m270_RA10},	//(internal1_m270_RA10) RA10 - последнее задание назад
	{747	,1	,1	,&internal1_m270_RA30},	//(internal1_m270_RA30)  RA30 - разрешение движения
	{748	,1	,1	,&internal1_m270_RA50},	//(internal1_m270_RA50) Ra50 - последнее задание скорости
	{749	,8	,1	,&internal1_m270_RV00},	//(internal1_m270_RV00) V0 - текущая скорость ОРР
	{750	,8	,1	,&internal1_m270_Sh00},	//(internal1_m270_Sh00) Sh0 - текущая координата штока ОРР
	{751	,8	,1	,&internal1_m270_ShV00},	//(internal1_m270_ShV00) V0 - текущая скорость штока ОРР
	{752	,8	,1	,&internal1_m270_X00},	//(internal1_m270_X00) X0 - текущая координата ОРР
	{753	,1	,1	,&internal1_m270_Zav0},	//(internal1_m270_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{754	,1	,1	,&internal1_m270_flp},	//(internal1_m270_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{755	,1	,1	,&internal1_m270_fls},	//(internal1_m270_fls)  fls - флаг одношагового режима
	{756	,1	,1	,&internal1_m303_MyFirstEnterFlag},	//(internal1_m303_MyFirstEnterFlag) MyFirstEnterFlag
	{757	,1	,1	,&internal1_m303_Pav0},	//(internal1_m303_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{758	,1	,1	,&internal1_m303_Ppv0},	//(internal1_m303_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{759	,1	,1	,&internal1_m303_RA00},	//(internal1_m303_RA00) RA00 - последнее задание вперед
	{760	,1	,1	,&internal1_m303_RA10},	//(internal1_m303_RA10) RA10 - последнее задание назад
	{761	,1	,1	,&internal1_m303_RA30},	//(internal1_m303_RA30)  RA30 - разрешение движения
	{762	,1	,1	,&internal1_m303_RA50},	//(internal1_m303_RA50) Ra50 - последнее задание скорости
	{763	,8	,1	,&internal1_m303_RV00},	//(internal1_m303_RV00) V0 - текущая скорость ОРР
	{764	,8	,1	,&internal1_m303_Sh00},	//(internal1_m303_Sh00) Sh0 - текущая координата штока ОРР
	{765	,8	,1	,&internal1_m303_ShV00},	//(internal1_m303_ShV00) V0 - текущая скорость штока ОРР
	{766	,8	,1	,&internal1_m303_X00},	//(internal1_m303_X00) X0 - текущая координата ОРР
	{767	,1	,1	,&internal1_m303_Zav0},	//(internal1_m303_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{768	,1	,1	,&internal1_m303_flp},	//(internal1_m303_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{769	,1	,1	,&internal1_m303_fls},	//(internal1_m303_fls)  fls - флаг одношагового режима
	{770	,1	,1	,&internal1_m319_Out10},	//(internal1_m319_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{771	,1	,1	,&internal1_m320_Out10},	//(internal1_m320_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{772	,1	,1	,&internal1_m321_Out10},	//(internal1_m321_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{773	,8	,1	,&internal1_m326_Xtek0},	//(internal1_m326_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{774	,8	,1	,&internal1_m334_Xtek0},	//(internal1_m334_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{775	,1	,1	,&internal1_m335_Out10},	//(internal1_m335_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{776	,1	,1	,&internal1_m336_Out10},	//(internal1_m336_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{777	,1	,1	,&internal1_m337_Out10},	//(internal1_m337_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{778	,1	,1	,&internal1_m347_Out10},	//(internal1_m347_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{779	,1	,1	,&internal1_m348_Out10},	//(internal1_m348_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{780	,1	,1	,&internal1_m349_Out10},	//(internal1_m349_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{781	,1	,1	,&internal1_m350_Out10},	//(internal1_m350_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{782	,1	,1	,&internal1_m364_MyFirstEnterFlag},	//(internal1_m364_MyFirstEnterFlag) MyFirstEnterFlag
	{783	,1	,1	,&internal1_m364_Pav0},	//(internal1_m364_Pav0)  - Пер.аварийный выключатель механизма
	{784	,1	,1	,&internal1_m364_Pv0},	//(internal1_m364_Pv0)  - Пер. выключатель механизма
	{785	,1	,1	,&internal1_m364_RA00},	//(internal1_m364_RA00)  - последнее задание вперед
	{786	,1	,1	,&internal1_m364_RA10},	//(internal1_m364_RA10)  - последнее задание назад
	{787	,8	,1	,&internal1_m364_V00},	//(internal1_m364_V00)  V00 - текущая скорость механизма
	{788	,8	,1	,&internal1_m364_X00},	//(internal1_m364_X00)  X00 - текущая координата механизма
	{789	,1	,1	,&internal1_m364_Zav0},	//(internal1_m364_Zav0)  - Зад.аварийный выключатель механизма
	{790	,1	,1	,&internal1_m364_Zv0},	//(internal1_m364_Zv0)  - Зад. выключатель механизма
	{791	,1	,1	,&internal1_m380_MyFirstEnterFlag},	//(internal1_m380_MyFirstEnterFlag) MyFirstEnterFlag
	{792	,1	,1	,&internal1_m380_Pav0},	//(internal1_m380_Pav0)  - Пер.аварийный выключатель механизма
	{793	,1	,1	,&internal1_m380_Pv0},	//(internal1_m380_Pv0)  - Пер. выключатель механизма
	{794	,1	,1	,&internal1_m380_RA00},	//(internal1_m380_RA00)  - последнее задание вперед
	{795	,1	,1	,&internal1_m380_RA10},	//(internal1_m380_RA10)  - последнее задание назад
	{796	,8	,1	,&internal1_m380_V00},	//(internal1_m380_V00)  V00 - текущая скорость механизма
	{797	,8	,1	,&internal1_m380_X00},	//(internal1_m380_X00)  X00 - текущая координата механизма
	{798	,1	,1	,&internal1_m380_Zav0},	//(internal1_m380_Zav0)  - Зад.аварийный выключатель механизма
	{799	,1	,1	,&internal1_m380_Zv0},	//(internal1_m380_Zv0)  - Зад. выключатель механизма
	{800	,1	,1	,&internal1_m395_MyFirstEnterFlag},	//(internal1_m395_MyFirstEnterFlag) MyFirstEnterFlag
	{801	,1	,1	,&internal1_m395_Pav0},	//(internal1_m395_Pav0)  - Пер.аварийный выключатель механизма
	{802	,1	,1	,&internal1_m395_Pv0},	//(internal1_m395_Pv0)  - Пер. выключатель механизма
	{803	,1	,1	,&internal1_m395_RA00},	//(internal1_m395_RA00)  - последнее задание вперед
	{804	,1	,1	,&internal1_m395_RA10},	//(internal1_m395_RA10)  - последнее задание назад
	{805	,8	,1	,&internal1_m395_V00},	//(internal1_m395_V00)  V00 - текущая скорость механизма
	{806	,8	,1	,&internal1_m395_X00},	//(internal1_m395_X00)  X00 - текущая координата механизма
	{807	,1	,1	,&internal1_m395_Zav0},	//(internal1_m395_Zav0)  - Зад.аварийный выключатель механизма
	{808	,1	,1	,&internal1_m395_Zv0},	//(internal1_m395_Zv0)  - Зад. выключатель механизма
	{809	,1	,1	,&internal1_m39_fef},	//(internal1_m39_fef) fef
	{810	,3	,1	,&internal1_m39_reg},	//(internal1_m39_reg) режим работы квдс 0 - ожидание сигнала 1- выдан импульс 2 отсчет удержания синхроимпульса 3 -блокировка
	{811	,8	,1	,&internal1_m39_tgen},	//(internal1_m39_tgen) задержки срабатывания генератора импульса
	{812	,8	,1	,&internal1_m39_tlock},	//(internal1_m39_tlock) время до конца блокировки
	{813	,8	,1	,&internal1_m39_tsin},	//(internal1_m39_tsin) время до конца удержания синхроимпульса
	{814	,1	,1	,&internal1_m406_Out10},	//(internal1_m406_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{815	,1	,1	,&internal1_m407_Out10},	//(internal1_m407_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{816	,1	,1	,&internal1_m408_Out10},	//(internal1_m408_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{817	,1	,1	,&internal1_m409_Out10},	//(internal1_m409_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{818	,8	,1	,&internal1_m416_Xtek0},	//(internal1_m416_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{819	,1	,1	,&internal1_m425_Out10},	//(internal1_m425_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{820	,1	,1	,&internal1_m426_Out10},	//(internal1_m426_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{821	,1	,1	,&internal1_m427_Out10},	//(internal1_m427_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{822	,1	,1	,&internal1_m428_Out10},	//(internal1_m428_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{823	,8	,1	,&internal1_m429_Xtek0},	//(internal1_m429_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{824	,1	,1	,&internal1_m443_MyFirstEnterFlag},	//(internal1_m443_MyFirstEnterFlag) MyFirstEnterFlag
	{825	,1	,1	,&internal1_m443_Pav0},	//(internal1_m443_Pav0)  - Пер.аварийный выключатель механизма
	{826	,1	,1	,&internal1_m443_Pv0},	//(internal1_m443_Pv0)  - Пер. выключатель механизма
	{827	,1	,1	,&internal1_m443_RA00},	//(internal1_m443_RA00)  - последнее задание вперед
	{828	,1	,1	,&internal1_m443_RA10},	//(internal1_m443_RA10)  - последнее задание назад
	{829	,8	,1	,&internal1_m443_V00},	//(internal1_m443_V00)  V00 - текущая скорость механизма
	{830	,8	,1	,&internal1_m443_X00},	//(internal1_m443_X00)  X00 - текущая координата механизма
	{831	,1	,1	,&internal1_m443_Zav0},	//(internal1_m443_Zav0)  - Зад.аварийный выключатель механизма
	{832	,1	,1	,&internal1_m443_Zv0},	//(internal1_m443_Zv0)  - Зад. выключатель механизма
	{833	,1	,1	,&internal1_m457_MyFirstEnterFlag},	//(internal1_m457_MyFirstEnterFlag) MyFirstEnterFlag
	{834	,1	,1	,&internal1_m457_Pav0},	//(internal1_m457_Pav0)  - Пер.аварийный выключатель механизма
	{835	,1	,1	,&internal1_m457_Pv0},	//(internal1_m457_Pv0)  - Пер. выключатель механизма
	{836	,1	,1	,&internal1_m457_RA00},	//(internal1_m457_RA00)  - последнее задание вперед
	{837	,1	,1	,&internal1_m457_RA10},	//(internal1_m457_RA10)  - последнее задание назад
	{838	,8	,1	,&internal1_m457_V00},	//(internal1_m457_V00)  V00 - текущая скорость механизма
	{839	,8	,1	,&internal1_m457_X00},	//(internal1_m457_X00)  X00 - текущая координата механизма
	{840	,1	,1	,&internal1_m457_Zav0},	//(internal1_m457_Zav0)  - Зад.аварийный выключатель механизма
	{841	,1	,1	,&internal1_m457_Zv0},	//(internal1_m457_Zv0)  - Зад. выключатель механизма
	{842	,1	,1	,&internal1_m467_q0},	//(internal1_m467_q0) q0 - внутренний параметр
	{843	,1	,1	,&internal1_m468_q0},	//(internal1_m468_q0) q0 - внутренний параметр
	{844	,1	,1	,&internal1_m472_MyFirstEnterFlag},	//(internal1_m472_MyFirstEnterFlag) MyFirstEnterFlag
	{845	,1	,1	,&internal1_m472_Pav0},	//(internal1_m472_Pav0)  - Пер.аварийный выключатель механизма
	{846	,1	,1	,&internal1_m472_Pv0},	//(internal1_m472_Pv0)  - Пер. выключатель механизма
	{847	,1	,1	,&internal1_m472_RA00},	//(internal1_m472_RA00)  - последнее задание вперед
	{848	,1	,1	,&internal1_m472_RA10},	//(internal1_m472_RA10)  - последнее задание назад
	{849	,8	,1	,&internal1_m472_V00},	//(internal1_m472_V00)  V00 - текущая скорость механизма
	{850	,8	,1	,&internal1_m472_X00},	//(internal1_m472_X00)  X00 - текущая координата механизма
	{851	,1	,1	,&internal1_m472_Zav0},	//(internal1_m472_Zav0)  - Зад.аварийный выключатель механизма
	{852	,1	,1	,&internal1_m472_Zv0},	//(internal1_m472_Zv0)  - Зад. выключатель механизма
	{853	,1	,1	,&internal1_m473_MyFirstEnterFlag},	//(internal1_m473_MyFirstEnterFlag) MyFirstEnterFlag
	{854	,1	,1	,&internal1_m473_Pav0},	//(internal1_m473_Pav0)  - Пер.аварийный выключатель механизма
	{855	,1	,1	,&internal1_m473_Pv0},	//(internal1_m473_Pv0)  - Пер. выключатель механизма
	{856	,1	,1	,&internal1_m473_RA00},	//(internal1_m473_RA00)  - последнее задание вперед
	{857	,1	,1	,&internal1_m473_RA10},	//(internal1_m473_RA10)  - последнее задание назад
	{858	,8	,1	,&internal1_m473_V00},	//(internal1_m473_V00)  V00 - текущая скорость механизма
	{859	,8	,1	,&internal1_m473_X00},	//(internal1_m473_X00)  X00 - текущая координата механизма
	{860	,1	,1	,&internal1_m473_Zav0},	//(internal1_m473_Zav0)  - Зад.аварийный выключатель механизма
	{861	,1	,1	,&internal1_m473_Zv0},	//(internal1_m473_Zv0)  - Зад. выключатель механизма
	{862	,1	,1	,&internal1_m479_q0},	//(internal1_m479_q0) q0 - внутренний параметр
	{863	,1	,1	,&internal1_m47_Out10},	//(internal1_m47_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{864	,1	,1	,&internal1_m480_q0},	//(internal1_m480_q0) q0 - внутренний параметр
	{865	,1	,1	,&internal1_m483_MyFirstEnterFlag},	//(internal1_m483_MyFirstEnterFlag) MyFirstEnterFlag
	{866	,1	,1	,&internal1_m483_Pav0},	//(internal1_m483_Pav0)  - Пер.аварийный выключатель механизма
	{867	,1	,1	,&internal1_m483_Pv0},	//(internal1_m483_Pv0)  - Пер. выключатель механизма
	{868	,1	,1	,&internal1_m483_RA00},	//(internal1_m483_RA00)  - последнее задание вперед
	{869	,1	,1	,&internal1_m483_RA10},	//(internal1_m483_RA10)  - последнее задание назад
	{870	,8	,1	,&internal1_m483_V00},	//(internal1_m483_V00)  V00 - текущая скорость механизма
	{871	,8	,1	,&internal1_m483_X00},	//(internal1_m483_X00)  X00 - текущая координата механизма
	{872	,1	,1	,&internal1_m483_Zav0},	//(internal1_m483_Zav0)  - Зад.аварийный выключатель механизма
	{873	,1	,1	,&internal1_m483_Zv0},	//(internal1_m483_Zv0)  - Зад. выключатель механизма
	{874	,1	,1	,&internal1_m494_MyFirstEnterFlag},	//(internal1_m494_MyFirstEnterFlag) MyFirstEnterFlag
	{875	,1	,1	,&internal1_m494_Pav0},	//(internal1_m494_Pav0)  - Пер.аварийный выключатель механизма
	{876	,1	,1	,&internal1_m494_Pv0},	//(internal1_m494_Pv0)  - Пер. выключатель механизма
	{877	,1	,1	,&internal1_m494_RA00},	//(internal1_m494_RA00)  - последнее задание вперед
	{878	,1	,1	,&internal1_m494_RA10},	//(internal1_m494_RA10)  - последнее задание назад
	{879	,8	,1	,&internal1_m494_V00},	//(internal1_m494_V00)  V00 - текущая скорость механизма
	{880	,8	,1	,&internal1_m494_X00},	//(internal1_m494_X00)  X00 - текущая координата механизма
	{881	,1	,1	,&internal1_m494_Zav0},	//(internal1_m494_Zav0)  - Зад.аварийный выключатель механизма
	{882	,1	,1	,&internal1_m494_Zv0},	//(internal1_m494_Zv0)  - Зад. выключатель механизма
	{883	,1	,1	,&internal1_m518_Out10},	//(internal1_m518_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{884	,1	,1	,&internal1_m534_Out10},	//(internal1_m534_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{885	,1	,1	,&internal1_m535_Out10},	//(internal1_m535_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{886	,1	,1	,&internal1_m550_Out10},	//(internal1_m550_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{887	,1	,1	,&internal1_m551_Out10},	//(internal1_m551_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{888	,1	,1	,&internal1_m552_Out10},	//(internal1_m552_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{889	,1	,1	,&internal1_m566_MyFirstEnterFlag},	//(internal1_m566_MyFirstEnterFlag) MyFirstEnterFlag
	{890	,1	,1	,&internal1_m566_Pav0},	//(internal1_m566_Pav0)  - Пер.аварийный выключатель механизма
	{891	,1	,1	,&internal1_m566_Pv0},	//(internal1_m566_Pv0)  - Пер. выключатель механизма
	{892	,1	,1	,&internal1_m566_RA00},	//(internal1_m566_RA00)  - последнее задание вперед
	{893	,1	,1	,&internal1_m566_RA10},	//(internal1_m566_RA10)  - последнее задание назад
	{894	,8	,1	,&internal1_m566_V00},	//(internal1_m566_V00)  V00 - текущая скорость механизма
	{895	,8	,1	,&internal1_m566_X00},	//(internal1_m566_X00)  X00 - текущая координата механизма
	{896	,1	,1	,&internal1_m566_Zav0},	//(internal1_m566_Zav0)  - Зад.аварийный выключатель механизма
	{897	,1	,1	,&internal1_m566_Zv0},	//(internal1_m566_Zv0)  - Зад. выключатель механизма
	{898	,1	,1	,&internal1_m580_MyFirstEnterFlag},	//(internal1_m580_MyFirstEnterFlag) MyFirstEnterFlag
	{899	,1	,1	,&internal1_m580_Pav0},	//(internal1_m580_Pav0)  - Пер.аварийный выключатель механизма
	{900	,1	,1	,&internal1_m580_Pv0},	//(internal1_m580_Pv0)  - Пер. выключатель механизма
	{901	,1	,1	,&internal1_m580_RA00},	//(internal1_m580_RA00)  - последнее задание вперед
	{902	,1	,1	,&internal1_m580_RA10},	//(internal1_m580_RA10)  - последнее задание назад
	{903	,8	,1	,&internal1_m580_V00},	//(internal1_m580_V00)  V00 - текущая скорость механизма
	{904	,8	,1	,&internal1_m580_X00},	//(internal1_m580_X00)  X00 - текущая координата механизма
	{905	,1	,1	,&internal1_m580_Zav0},	//(internal1_m580_Zav0)  - Зад.аварийный выключатель механизма
	{906	,1	,1	,&internal1_m580_Zv0},	//(internal1_m580_Zv0)  - Зад. выключатель механизма
	{907	,1	,1	,&internal1_m592_MyFirstEnterFlag},	//(internal1_m592_MyFirstEnterFlag) MyFirstEnterFlag
	{908	,1	,1	,&internal1_m592_Pav0},	//(internal1_m592_Pav0)  - Пер.аварийный выключатель механизма
	{909	,1	,1	,&internal1_m592_Pv0},	//(internal1_m592_Pv0)  - Пер. выключатель механизма
	{910	,1	,1	,&internal1_m592_RA00},	//(internal1_m592_RA00)  - последнее задание вперед
	{911	,1	,1	,&internal1_m592_RA10},	//(internal1_m592_RA10)  - последнее задание назад
	{912	,8	,1	,&internal1_m592_V00},	//(internal1_m592_V00)  V00 - текущая скорость механизма
	{913	,8	,1	,&internal1_m592_X00},	//(internal1_m592_X00)  X00 - текущая координата механизма
	{914	,1	,1	,&internal1_m592_Zav0},	//(internal1_m592_Zav0)  - Зад.аварийный выключатель механизма
	{915	,1	,1	,&internal1_m592_Zv0},	//(internal1_m592_Zv0)  - Зад. выключатель механизма
	{916	,1	,1	,&internal1_m593_MyFirstEnterFlag},	//(internal1_m593_MyFirstEnterFlag) MyFirstEnterFlag
	{917	,1	,1	,&internal1_m593_Pav0},	//(internal1_m593_Pav0)  - Пер.аварийный выключатель механизма
	{918	,1	,1	,&internal1_m593_Pv0},	//(internal1_m593_Pv0)  - Пер. выключатель механизма
	{919	,1	,1	,&internal1_m593_RA00},	//(internal1_m593_RA00)  - последнее задание вперед
	{920	,1	,1	,&internal1_m593_RA10},	//(internal1_m593_RA10)  - последнее задание назад
	{921	,8	,1	,&internal1_m593_V00},	//(internal1_m593_V00)  V00 - текущая скорость механизма
	{922	,8	,1	,&internal1_m593_X00},	//(internal1_m593_X00)  X00 - текущая координата механизма
	{923	,1	,1	,&internal1_m593_Zav0},	//(internal1_m593_Zav0)  - Зад.аварийный выключатель механизма
	{924	,1	,1	,&internal1_m593_Zv0},	//(internal1_m593_Zv0)  - Зад. выключатель механизма
	{925	,8	,1	,&internal1_m601_tx},	//(internal1_m601_tx) tx - время накопленное сек
	{926	,18	,1	,&internal1_m601_y0},	//(internal1_m601_y0) y0
	{927	,8	,1	,&internal1_m603_tx},	//(internal1_m603_tx) tx - время накопленное сек
	{928	,18	,1	,&internal1_m603_y0},	//(internal1_m603_y0) y0
	{929	,1	,1	,&internal1_m605_MyFirstEnterFlag},	//(internal1_m605_MyFirstEnterFlag) MyFirstEnterFlag
	{930	,1	,1	,&internal1_m605_Pav0},	//(internal1_m605_Pav0)  - Пер.аварийный выключатель механизма
	{931	,1	,1	,&internal1_m605_Pv0},	//(internal1_m605_Pv0)  - Пер. выключатель механизма
	{932	,1	,1	,&internal1_m605_RA00},	//(internal1_m605_RA00)  - последнее задание вперед
	{933	,1	,1	,&internal1_m605_RA10},	//(internal1_m605_RA10)  - последнее задание назад
	{934	,8	,1	,&internal1_m605_V00},	//(internal1_m605_V00)  V00 - текущая скорость механизма
	{935	,8	,1	,&internal1_m605_X00},	//(internal1_m605_X00)  X00 - текущая координата механизма
	{936	,1	,1	,&internal1_m605_Zav0},	//(internal1_m605_Zav0)  - Зад.аварийный выключатель механизма
	{937	,1	,1	,&internal1_m605_Zv0},	//(internal1_m605_Zv0)  - Зад. выключатель механизма
	{938	,1	,1	,&internal1_m606_MyFirstEnterFlag},	//(internal1_m606_MyFirstEnterFlag) MyFirstEnterFlag
	{939	,1	,1	,&internal1_m606_Pav0},	//(internal1_m606_Pav0)  - Пер.аварийный выключатель механизма
	{940	,1	,1	,&internal1_m606_Pv0},	//(internal1_m606_Pv0)  - Пер. выключатель механизма
	{941	,1	,1	,&internal1_m606_RA00},	//(internal1_m606_RA00)  - последнее задание вперед
	{942	,1	,1	,&internal1_m606_RA10},	//(internal1_m606_RA10)  - последнее задание назад
	{943	,8	,1	,&internal1_m606_V00},	//(internal1_m606_V00)  V00 - текущая скорость механизма
	{944	,8	,1	,&internal1_m606_X00},	//(internal1_m606_X00)  X00 - текущая координата механизма
	{945	,1	,1	,&internal1_m606_Zav0},	//(internal1_m606_Zav0)  - Зад.аварийный выключатель механизма
	{946	,1	,1	,&internal1_m606_Zv0},	//(internal1_m606_Zv0)  - Зад. выключатель механизма
	{947	,8	,1	,&internal1_m615_tx},	//(internal1_m615_tx) tx - время накопленное сек
	{948	,18	,1	,&internal1_m615_y0},	//(internal1_m615_y0) y0
	{949	,8	,1	,&internal1_m627_tx},	//(internal1_m627_tx) tx - время накопленное сек
	{950	,18	,1	,&internal1_m627_y0},	//(internal1_m627_y0) y0
	{951	,1	,1	,&internal1_m62_Out10},	//(internal1_m62_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{952	,8	,1	,&internal1_m634_y0},	//(internal1_m634_y0) y0 - внутренний параметр
	{953	,1	,1	,&internal1_m648_Out10},	//(internal1_m648_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{954	,1	,1	,&internal1_m649_Out10},	//(internal1_m649_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{955	,1	,1	,&internal1_m650_Out10},	//(internal1_m650_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{956	,1	,1	,&internal1_m651_Out10},	//(internal1_m651_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{957	,1	,1	,&internal1_m652_Out10},	//(internal1_m652_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{958	,1	,1	,&internal1_m653_Out10},	//(internal1_m653_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{959	,1	,1	,&internal1_m65_MyFirstEnterFlag},	//(internal1_m65_MyFirstEnterFlag) MyFirstEnterFlag
	{960	,1	,1	,&internal1_m65_Pav0},	//(internal1_m65_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{961	,1	,1	,&internal1_m65_Ppv0},	//(internal1_m65_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{962	,1	,1	,&internal1_m65_RA00},	//(internal1_m65_RA00) RA00 - последнее задание вперед
	{963	,1	,1	,&internal1_m65_RA10},	//(internal1_m65_RA10) RA10 - последнее задание назад
	{964	,1	,1	,&internal1_m65_RA30},	//(internal1_m65_RA30)  RA30 - разрешение движения
	{965	,1	,1	,&internal1_m65_RA50},	//(internal1_m65_RA50) Ra50 - последнее задание скорости
	{966	,8	,1	,&internal1_m65_RV00},	//(internal1_m65_RV00) V0 - текущая скорость ОРР
	{967	,8	,1	,&internal1_m65_Sh00},	//(internal1_m65_Sh00) Sh0 - текущая координата штока ОРР
	{968	,8	,1	,&internal1_m65_ShV00},	//(internal1_m65_ShV00) V0 - текущая скорость штока ОРР
	{969	,8	,1	,&internal1_m65_X00},	//(internal1_m65_X00) X0 - текущая координата ОРР
	{970	,1	,1	,&internal1_m65_Zav0},	//(internal1_m65_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{971	,1	,1	,&internal1_m65_flp},	//(internal1_m65_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{972	,1	,1	,&internal1_m65_fls},	//(internal1_m65_fls)  fls - флаг одношагового режима
	{973	,1	,1	,&internal1_m668_Out10},	//(internal1_m668_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{974	,1	,1	,&internal1_m669_Out10},	//(internal1_m669_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{975	,1	,1	,&internal1_m672_Out10},	//(internal1_m672_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{976	,1	,1	,&internal1_m673_Out10},	//(internal1_m673_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{977	,1	,1	,&internal1_m674_Out10},	//(internal1_m674_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{978	,1	,1	,&internal1_m675_Out10},	//(internal1_m675_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{979	,1	,1	,&internal1_m685_Out10},	//(internal1_m685_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{980	,1	,1	,&internal1_m686_Out10},	//(internal1_m686_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{981	,1	,1	,&internal1_m687_Out10},	//(internal1_m687_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{982	,1	,1	,&internal1_m688_Out10},	//(internal1_m688_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{983	,1	,1	,&internal1_m689_Out10},	//(internal1_m689_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{984	,8	,1	,&internal1_m702_Chim0},	//(internal1_m702_Chim0) измеренная частота импульсов камеры Гц
	{985	,8	,1	,&internal1_m712_Chim0},	//(internal1_m712_Chim0) измеренная частота импульсов камеры Гц
	{986	,8	,1	,&internal1_m721_Chim0},	//(internal1_m721_Chim0) измеренная частота импульсов камеры Гц
	{987	,8	,1	,&internal1_m730_Chim0},	//(internal1_m730_Chim0) измеренная частота импульсов камеры Гц
	{988	,8	,1	,&internal1_m738_Chim0},	//(internal1_m738_Chim0) измеренная частота импульсов камеры Гц
	{989	,8	,1	,&internal1_m747_Chim0},	//(internal1_m747_Chim0) измеренная частота импульсов камеры Гц
	{990	,8	,1	,&internal1_m756_Chim0},	//(internal1_m756_Chim0) измеренная частота импульсов камеры Гц
	{991	,8	,1	,&internal1_m764_Chim0},	//(internal1_m764_Chim0) измеренная частота импульсов камеры Гц
	{992	,8	,1	,&internal1_m773_Chim0},	//(internal1_m773_Chim0) измеренная частота импульсов камеры Гц
	{993	,8	,1	,&internal1_m782_Chim0},	//(internal1_m782_Chim0) измеренная частота импульсов камеры Гц
	{994	,8	,1	,&internal1_m790_Chim0},	//(internal1_m790_Chim0) измеренная частота импульсов камеры Гц
	{995	,8	,1	,&internal1_m799_Chim0},	//(internal1_m799_Chim0) измеренная частота импульсов камеры Гц
	{996	,1	,1	,&internal1_m811_Out10},	//(internal1_m811_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{997	,1	,1	,&internal1_m812_Out10},	//(internal1_m812_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{998	,1	,1	,&internal1_m813_Out10},	//(internal1_m813_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{999	,1	,1	,&internal1_m814_Out10},	//(internal1_m814_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1000	,1	,1	,&internal1_m815_Out10},	//(internal1_m815_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1001	,1	,1	,&internal1_m816_Out10},	//(internal1_m816_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1002	,1	,1	,&internal1_m817_Out10},	//(internal1_m817_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1003	,8	,1	,&internal1_m834_Xtek0},	//(internal1_m834_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{1004	,8	,1	,&internal1_m836_Xtek0},	//(internal1_m836_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{1005	,1	,1	,&internal1_m837_Out10},	//(internal1_m837_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1006	,1	,1	,&internal1_m838_Out10},	//(internal1_m838_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1007	,1	,1	,&internal1_m839_Out10},	//(internal1_m839_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1008	,1	,1	,&internal1_m840_Out10},	//(internal1_m840_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1009	,1	,1	,&internal1_m852_Out10},	//(internal1_m852_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1010	,1	,1	,&internal1_m853_Out10},	//(internal1_m853_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1011	,1	,1	,&internal1_m854_Out10},	//(internal1_m854_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1012	,8	,1	,&internal1_m862_Chim0},	//(internal1_m862_Chim0) измеренная частота импульсов камеры Гц
	{1013	,8	,1	,&internal1_m870_Chim0},	//(internal1_m870_Chim0) измеренная частота импульсов камеры Гц
	{1014	,8	,1	,&internal1_m880_Chim0},	//(internal1_m880_Chim0) измеренная частота импульсов камеры Гц
	{1015	,1	,1	,&internal1_m892_MyFirstEnterFlag},	//(internal1_m892_MyFirstEnterFlag) MyFirstEnterFlag
	{1016	,1	,1	,&internal1_m892_Pav0},	//(internal1_m892_Pav0)  - Пер.аварийный выключатель механизма
	{1017	,1	,1	,&internal1_m892_Pv0},	//(internal1_m892_Pv0)  - Пер. выключатель механизма
	{1018	,1	,1	,&internal1_m892_RA00},	//(internal1_m892_RA00)  - последнее задание вперед
	{1019	,1	,1	,&internal1_m892_RA10},	//(internal1_m892_RA10)  - последнее задание назад
	{1020	,8	,1	,&internal1_m892_V00},	//(internal1_m892_V00)  V00 - текущая скорость механизма
	{1021	,8	,1	,&internal1_m892_X00},	//(internal1_m892_X00)  X00 - текущая координата механизма
	{1022	,1	,1	,&internal1_m892_Zav0},	//(internal1_m892_Zav0)  - Зад.аварийный выключатель механизма
	{1023	,1	,1	,&internal1_m892_Zv0},	//(internal1_m892_Zv0)  - Зад. выключатель механизма
	{1024	,1	,1	,&internal1_m949_Out10},	//(internal1_m949_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1025	,1	,1	,&internal1_m950_Out10},	//(internal1_m950_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1026	,8	,1	,&internal1_m952_Xtek0},	//(internal1_m952_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{1027	,1	,1	,&internal1_m953_Out10},	//(internal1_m953_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1028	,1	,1	,&internal1_m966_Out10},	//(internal1_m966_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1029	,1	,1	,&internal1_m967_Out10},	//(internal1_m967_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1030	,8	,1	,&internal1_m969_Xtek0},	//(internal1_m969_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{1031	,1	,1	,&internal1_m970_Out10},	//(internal1_m970_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1032	,1	,1	,&internal1_m980_Out10},	//(internal1_m980_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1033	,1	,1	,&internal1_m981_Out10},	//(internal1_m981_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1034	,1	,1	,&internal1_m982_Out10},	//(internal1_m982_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1035	,1	,1	,&internal1_m983_Out10},	//(internal1_m983_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1036	,1	,1	,&internal1_m984_Out10},	//(internal1_m984_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1037	,1	,1	,&internal1_m995_Out10},	//(internal1_m995_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1038	,1	,1	,&internal1_m996_Out10},	//(internal1_m996_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1039	,1	,1	,&internal1_m997_Out10},	//(internal1_m997_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1040	,1	,1	,&internal1_m998_Out10},	//(internal1_m998_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1041	,1	,1	,&internal1_m999_Out10},	//(internal1_m999_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1042	,8	,1	,&krb1},	//( - , - ) 
	{1043	,8	,1	,&krb2},	//( - , - ) 
	{1044	,1	,1	,&lEM_C1AD31LRP},	//(C1AD31LRP) Общий сброс от РПУ
	{1045	,1	,1	,&lEM_R0IE01LRP},	//(R0IE01LRP) Отключение питание детекторов
	{1046	,1	,1	,&lEM_R0IE02LRP},	//(R0IE02LRP) Отключить питание ПР, ПУ
	{1047	,1	,1	,&lEM_R3AD10LC1},	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
	{1048	,1	,1	,&lEM_R3AD20LC1},	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
	{1049	,1	,1	,&lEM_R5AD10LC1},	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
	{1050	,1	,1	,&lEM_R5AD20LC1},	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
	{1051	,1	,1	,&lEM_R6AD10LC1},	//(R6AD10LC1) Выкатить кран-балку от ИС
	{1052	,1	,1	,&lEM_R8AD10LC1},	//(R8AD10LC1) Установить аварийный НИ от ИС
	{-1,0,NULL},
};
static char NameSaveFile[]="scm.bin\0"; //Имя файла сохранения переменных
#pragma pop
static VarSaveCtrl saveVariables[]={	//Id переменных для сохранения
	{283,"fEM_A0UN01RIM\0"},	//(A0UN01RIM) Мощность источника нейтронов ИНИ
	{284,"fEM_A0UN02RIM\0"},	//(A0UN02RIM) Мощность источника нейтронов с АНИ
	{285,"fEM_A0UN07RIM\0"},	//(A0UN07RIM) Доля запаздывающих нейтронов
	{286,"fEM_A0UP01RIM\0"},	//(A0UP01RIM) Текущее давление в АЗ1,2
	{287,"fEM_A0UP02RIM\0"},	//(A0UP02RIM) Текущее давление в АЗ1,2
	{288,"fEM_A0UR01RSP\0"},	//(A0UR01RSP) Стартовая  реактивность АЗ1
	{289,"fEM_A0UR02RSP\0"},	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
	{290,"fEM_A0UT03RSP\0"},	//(A0UT03RSP) Стартовая  температура АЗ1 град
	{291,"fEM_A0UX00RSS\0"},	//(A0UX00RSS) Эффективный радиус АЗ
	{292,"fEM_A0UX01RSS\0"},	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
	{293,"fEM_A0UX02RSS\0"},	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
	{294,"fEM_A0UX03RSS\0"},	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
	{295,"fEM_A0UX04RSS\0"},	//(A0UX04RSS) Первый коэффициент калибровки камеры4
	{296,"fEM_A0UX05RSS\0"},	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
	{297,"fEM_A0UX06RSS\0"},	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
	{298,"fEM_A0UX07RSS\0"},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{299,"fEM_A0UX08RSS\0"},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{300,"fEM_A0UX09RSS\0"},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{301,"fEM_A0UX10RSS\0"},	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
	{302,"fEM_A0UX11RSS\0"},	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
	{303,"fEM_A0UX12RSS\0"},	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
	{304,"fEM_A0UX13RSS\0"},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{305,"fEM_A0UX14RSS\0"},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{306,"fEM_A0UX15RSS\0"},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{307,"fEM_A1MC01RC1\0"},	//(A1MC01RC1) Заданная координата  ББ1 от ИС
	{308,"fEM_A1MC01RSP\0"},	//(A1MC01RSP) Стартовая координата  ББ1
	{309,"fEM_A1MC02RC1\0"},	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
	{310,"fEM_A1MC02RSP\0"},	//(A1MC02RSP) Стартовая координата штока ББ1
	{311,"fEM_A1MV01RC1\0"},	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
	{312,"fEM_A1MV02RC1\0"},	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
	{313,"fEM_A1UC02RDU\0"},	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
	{314,"fEM_A1UC03RDU\0"},	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
	{315,"fEM_A1UC04RIM\0"},	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
	{316,"fEM_A1UC05RIM\0"},	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
	{317,"fEM_A1UC06RIM\0"},	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
	{318,"fEM_A1UC08RIM\0"},	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
	{319,"fEM_A1UG01RDU\0"},	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
	{320,"fEM_A1UP01RIM\0"},	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
	{321,"fEM_A1UP82RIM\0"},	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{322,"fEM_A1UR00RIM\0"},	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{323,"fEM_A1UR01RIM\0"},	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{324,"fEM_A1US07RDU\0"},	//(A1US07RDU) Постоянная времени масляного демпфера ББ
	{325,"fEM_A1UV02RIM\0"},	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{326,"fEM_A2MC01RC1\0"},	//(A2MC01RC1) Заданная координата РБ1 от ИС
	{327,"fEM_A2MC01RSP\0"},	//(A2MC01RSP) Стартовая координата  РБ1
	{328,"fEM_A2MC02RC1\0"},	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
	{329,"fEM_A2MC02RSP\0"},	//(A2MC02RSP) Стартовая координата штока РБ1
	{330,"fEM_A2MV01RC1\0"},	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
	{331,"fEM_A2MV02RC1\0"},	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
	{332,"fEM_A2UC02RDU\0"},	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
	{333,"fEM_A2UC03RDU\0"},	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
	{334,"fEM_A2UC04RIM\0"},	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
	{335,"fEM_A2UC05RIM\0"},	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
	{336,"fEM_A2UC06RIM\0"},	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
	{337,"fEM_A2UC08RIM\0"},	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
	{338,"fEM_A2UG01RDU\0"},	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
	{339,"fEM_A2UP01RIM\0"},	//(A2UP01RIM) Текущее давление на сброс РБ
	{340,"fEM_A2UP02RIM\0"},	//(A2UP02RIM) Текущее давление на подъём РБ
	{341,"fEM_A2UP03RDU\0"},	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
	{342,"fEM_A2UP03RIM\0"},	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
	{343,"fEM_A2UP04RDU\0"},	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
	{344,"fEM_A2UR00RIM\0"},	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
	{345,"fEM_A2UR01RIM\0"},	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
	{346,"fEM_A2US07RDU\0"},	//(A2US07RDU) Постоянная времени масляного демпфера РБ
	{347,"fEM_A2UV02RIM\0"},	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{348,"fEM_A3MC01RC1\0"},	//(A3MC01RC1) Заданная координата ИС1 от ИС
	{349,"fEM_A3MC01RSP\0"},	//(A3MC01RSP) Стартовая координата  ИС1
	{350,"fEM_A3MC02RC1\0"},	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
	{351,"fEM_A3MC02RSP\0"},	//(A3MC02RSP) Стартовая координата штока ИС1
	{352,"fEM_A3MV01RC1\0"},	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
	{353,"fEM_A3MV02RC1\0"},	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
	{354,"fEM_A3UC02RDU\0"},	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
	{355,"fEM_A3UC03RDU\0"},	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
	{356,"fEM_A3UC04RIM\0"},	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
	{357,"fEM_A3UC05RIM\0"},	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
	{358,"fEM_A3UC06RIM\0"},	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
	{359,"fEM_A3UC08RIM\0"},	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
	{360,"fEM_A3UG01RDU\0"},	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
	{361,"fEM_A3UP01RIM\0"},	//(A3UP01RIM) Текущее давление на СПУСК ИС
	{362,"fEM_A3UP02RDU\0"},	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
	{363,"fEM_A3UP02RIM\0"},	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
	{364,"fEM_A3UP03RDU\0"},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{365,"fEM_A3UP04RDU\0"},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{366,"fEM_A3UR00RIM\0"},	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{367,"fEM_A3UR01RIM\0"},	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{368,"fEM_A3US07RDU\0"},	//(A3US07RDU) Постоянная времени масляного демпфера ИС
	{369,"fEM_A3UV02RIM\0"},	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{370,"fEM_A4MC01RSP\0"},	//(A4MC01RSP) Стартовая координата НИ1
	{371,"fEM_A4UL10RIM\0"},	//(A4UL10RIM) Время полного перемещения НИ сек
	{372,"fEM_A4UP01RIM\0"},	//(A4UP01RIM) Текущее давление на подъём НИ
	{373,"fEM_A4UP02RIM\0"},	//(A4UP02RIM) Нижняя граница давления на подъём НИ
	{374,"fEM_A5MC01RC1\0"},	//(A5MC01RC1) Заданная координата НЛ1 от ИС
	{375,"fEM_A5MC01RSP\0"},	//(A5MC01RSP) Стартовая координата НЛ1
	{376,"fEM_A5MV01RC1\0"},	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
	{377,"fEM_A5UC10RIM\0"},	//(A5UC10RIM) Время полного хода НЛ сек
	{378,"fEM_A6MC01RC1\0"},	//(A6MC01RC1) Заданная координата БЗ1 от ИС
	{379,"fEM_A6MC01RSP\0"},	//(A6MC01RSP) Стартовая координата БЗ1
	{380,"fEM_A6MV01RC1\0"},	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
	{381,"fEM_A6UC10RIM\0"},	//(A6UC10RIM) Время полного хода БЗ (сек)
	{382,"fEM_A6US80RDU\0"},	//(A6US80RDU) Тормозной путь БЗ (мм)
	{383,"fEM_A8MC01RC1\0"},	//(A8MC01RC1) Заданная координата ДС2 от ИС
	{384,"fEM_A8MC01RSP\0"},	//(A8MC01RSP) Стартовая координата ДС2
	{385,"fEM_A8MV01RC1\0"},	//(A8MV01RC1) Заданная скорость ДС2 от ИС
	{386,"fEM_A8UC03RDU\0"},	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
	{387,"fEM_A8UC08RDU\0"},	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
	{388,"fEM_A8UC10RIM\0"},	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
	{389,"fEM_A8UC11RIM\0"},	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
	{390,"fEM_A8UC20RIM\0"},	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
	{391,"fEM_A8UC21RIM\0"},	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
	{392,"fEM_A8US80RDU\0"},	//(A8US80RDU) Тормозной путь ДС2 (мм)
	{393,"fEM_A8UV80RDU\0"},	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
	{394,"fEM_A9MC01RSP\0"},	//(A9MC01RSP) Стартовая координата НИ ДС1
	{395,"fEM_A9UL10RIM\0"},	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
	{396,"fEM_B0UT03RSP\0"},	//(B0UT03RSP) Стартовая  температура АЗ2 град
	{397,"fEM_B0UX01RSS\0"},	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
	{398,"fEM_B0UX02RSS\0"},	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
	{399,"fEM_B0UX03RSS\0"},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{400,"fEM_B0UX04RSS\0"},	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
	{401,"fEM_B0UX05RSS\0"},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{402,"fEM_B0UX06RSS\0"},	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
	{403,"fEM_B0UX07RSS\0"},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{404,"fEM_B0UX08RSS\0"},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{405,"fEM_B0UX09RSS\0"},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{406,"fEM_B0UX10RSS\0"},	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
	{407,"fEM_B0UX11RSS\0"},	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
	{408,"fEM_B0UX12RSS\0"},	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
	{409,"fEM_B1MC01RC1\0"},	//(B1MC01RC1) Заданная координата ББ2 от ИС
	{410,"fEM_B1MC01RSP\0"},	//(B1MC01RSP) Стартовая координата  ББ2
	{411,"fEM_B1MC02RC1\0"},	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
	{412,"fEM_B1MC02RSP\0"},	//(B1MC02RSP) Стартовая координата штока ББ2
	{413,"fEM_B1MV01RC1\0"},	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
	{414,"fEM_B1MV02RC1\0"},	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
	{415,"fEM_B2MC01RC1\0"},	//(B2MC01RC1) Заданная координата РБ2 от ИС
	{416,"fEM_B2MC01RSP\0"},	//(B2MC01RSP) Стартовая координата  РБ2
	{417,"fEM_B2MC02RC1\0"},	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
	{418,"fEM_B2MC02RSP\0"},	//(B2MC02RSP) Стартовая координата штока РБ2
	{419,"fEM_B2MV01RC1\0"},	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
	{420,"fEM_B2MV02RC1\0"},	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
	{421,"fEM_B3MC01RC1\0"},	//(B3MC01RC1) Заданная координата ИС2 от ИС
	{422,"fEM_B3MC01RSP\0"},	//(B3MC01RSP) Стартовая координата  ИС2
	{423,"fEM_B3MC02RC1\0"},	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
	{424,"fEM_B3MC02RSP\0"},	//(B3MC02RSP) Стартовая координата штока ИС2
	{425,"fEM_B3MV01RC1\0"},	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
	{426,"fEM_B3MV02RC1\0"},	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
	{427,"fEM_B4MC01RSP\0"},	//(B4MC01RSP) Стартовая координата НИ2
	{428,"fEM_B5MC01RC1\0"},	//(B5MC01RC1) Заданная координата НЛ2 от ИС
	{429,"fEM_B5MC01RSP\0"},	//(B5MC01RSP) Стартовая координата НЛ2
	{430,"fEM_B5MV01RC1\0"},	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
	{431,"fEM_B6MC01RC1\0"},	//(B6MC01RC1) Заданная координата БЗ2 от ИС
	{432,"fEM_B6MC01RSP\0"},	//(B6MC01RSP) Стартовая координата БЗ2
	{433,"fEM_B6MV01RC1\0"},	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
	{434,"fEM_B8MC01RC1\0"},	//(B8MC01RC1) Заданная координата АЗ2 от ИС
	{435,"fEM_B8MC01RSP\0"},	//(B8MC01RSP) Стартовая координата АЗ2
	{436,"fEM_B8MV01RC1\0"},	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
	{437,"fEM_B8UC08RDU\0"},	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
	{438,"fEM_B8UC10RIM\0"},	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
	{439,"fEM_B8UC11RIM\0"},	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
	{440,"fEM_B8UC20RIM\0"},	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
	{441,"fEM_B8UC21RIM\0"},	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
	{442,"fEM_B8US80RDU\0"},	//(B8US80RDU) Тормозной путь АЗ2 (мм)
	{443,"fEM_B8UV80RDU\0"},	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
	{444,"fEM_B9MC01RSP\0"},	//(B9MC01RSP) Стартовая координата НИ ДС2
	{445,"fEM_R0UH01RSS\0"},	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
	{446,"fEM_R0UH02RSS\0"},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
	{447,"fEM_R0UH03RSS\0"},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
	{448,"fEM_R0UH05RSS\0"},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{449,"fEM_R0UH21RSS\0"},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{450,"fEM_R0UH22RSS\0"},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{451,"fEM_R0UH23RSS\0"},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{452,"fEM_R0UL01RIM\0"},	//(R0UL01RIM) Среднее время генерации нейтронов
	{453,"fEM_R0UL02RDU\0"},	//(R0UL02RDU) Время задержки  ИНИ
	{454,"fEM_R0UL02RIM\0"},	//(R0UL02RIM) Время удержания синхроимпульса
	{455,"fEM_R0UL04RIM\0"},	//(R0UL04RIM) Время блокировки повторной генерации импульса
	{456,"fEM_R0UN02RIM\0"},	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{457,"fEM_R0UN18RDU\0"},	//(R0UN18RDU) Коэффициент температурной корректировки реактивности(долл)
	{458,"fEM_R0UR01RIM\0"},	//(R0UR01RIM) Стартовая отрицательная реактивность
	{459,"fEM_R0UR30RIM\0"},	//(R0UR30RIM) Реактивность вносимая образцами (долл)
	{460,"fEM_R0UT01RDU\0"},	//(R0UT01RDU) Нижний предел шкалы датчика температуры
	{461,"fEM_R0UT02RDU\0"},	//(R0UT02RDU) Верхний предел шкалы датчика температуры
	{462,"fEM_R0UT02RIM\0"},	//(R0UT02RIM) Масса топлива в АЗ
	{463,"fEM_R0UT03RIM\0"},	//(R0UT03RIM) Нормальная температура АЗ град
	{464,"fEM_R0UT04RIM\0"},	//(R0UT04RIM) Удельная теплоёмкость топлива
	{465,"fEM_R0UT05RIM\0"},	//(R0UT05RIM) Энергия деления ядра
	{466,"fEM_R0UT06RIM\0"},	//(R0UT06RIM) Конвекционное сопротивление при обдуве
	{467,"fEM_R0UV81RDU\0"},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{468,"fEM_R0UV82RDU\0"},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{469,"fEM_R0UV83RDU\0"},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{470,"fEM_R0UV84RDU\0"},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{471,"fEM_R0UV85RDU\0"},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{472,"fEM_R0UV86RDU\0"},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{473,"fEM_R0UV87RDU\0"},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{474,"fEM_R1MC01RC1\0"},	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
	{475,"fEM_R1MC01RSP\0"},	//(R1MC01RSP) Стартовая координата МДЗ1
	{476,"fEM_R1MV01RC1\0"},	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
	{477,"fEM_R1UC10RIM\0"},	//(R1UC10RIM) Время полного хода МДЗ сек
	{478,"fEM_R2MC01RC1\0"},	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
	{479,"fEM_R2MC01RSP\0"},	//(R2MC01RSP) Стартовая координата МДЗ2
	{480,"fEM_R2MV01RC1\0"},	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
	{481,"fEM_R3UC01RSP\0"},	//(R3UC01RSP) Стартовая координата Гомогенных дверей
	{482,"fEM_R3UL10RIM\0"},	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
	{483,"fEM_R4MC01RC1\0"},	//(R4MC01RC1) Заданная координата тележки от ИС
	{484,"fEM_R4MC01RSP\0"},	//(R4MC01RSP) Стартовая координата тележки
	{485,"fEM_R4MV01RC1\0"},	//(R4MV01RC1) Заданная скорость тележки от ИС
	{486,"fEM_R4UC08RDU\0"},	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
	{487,"fEM_R4UC10RIM\0"},	//(R4UC10RIM) Координата верхних механических упоров тележки мм
	{488,"fEM_R4UC20RIM\0"},	//(R4UC20RIM) Координата нижних механических упоров тележки мм
	{489,"fEM_R4UC22RIM\0"},	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
	{490,"fEM_R4US80RDU\0"},	//(R4US80RDU) Тормозной путь тележки (мм)
	{491,"fEM_R4UV80RDU\0"},	//(R4UV80RDU) Номинальная скорость тележки (см/с)
	{492,"fEM_R5UC01RSP\0"},	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
	{493,"fEM_R5UL10RIM\0"},	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
	{494,"fEM_R6UC01RSP\0"},	//(R6UC01RSP) Стартовая координата Кран-балки
	{495,"fEM_R6UL10RIM\0"},	//(R6UL10RIM) Время полного хода кран-балки сек
	{496,"fEM_R7UC10RIM\0"},	//(R7UC10RIM) X-координата КНК53М R7IN13 см
	{497,"fEM_R7UC19RIM\0"},	//(R7UC19RIM) Y-координата СНМ-11 (11) см
	{498,"fEM_R7UI02RIM\0"},	//(R7UI02RIM) Коэффициент усиления уровня радиации
	{499,"fEM_R7UI71RIM\0"},	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{500,"fEM_R7UI72RIM\0"},	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
	{501,"fEM_R7UI73RIM\0"},	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
	{502,"fEM_R7UI74RIM\0"},	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
	{503,"fEM_R7UI75RIM\0"},	//(R7UI75RIM) Множитель к уровню радиации
	{504,"fEM_R7UI76RIM\0"},	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{505,"fEM_R7UI77RIM\0"},	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{506,"fEM_R7UL01RIM\0"},	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
	{507,"fEM_R7UX01RSS\0"},	//(R7UX01RSS) X-координата камеры R7IN11
	{508,"fEM_R7UX02RSS\0"},	//(R7UX02RSS) X-координата камеры R7IN12 (см)
	{509,"fEM_R7UX04RSS\0"},	//(R7UX04RSS) X-координата камеры R7IN21 (см)
	{510,"fEM_R7UX05RSS\0"},	//(R7UX05RSS) X-координата камеры R7IN22 (см)
	{511,"fEM_R7UX06RSS\0"},	//(R7UX06RSS) X-координата камеры R7IN23 (см)
	{512,"fEM_R7UX07RSS\0"},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{513,"fEM_R7UX08RSS\0"},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{514,"fEM_R7UX09RSS\0"},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{515,"fEM_R7UX10RSS\0"},	//(R7UX10RSS) X-координата камеры R7IN41
	{516,"fEM_R7UX11RSS\0"},	//(R7UX11RSS) X-координата камеры R7IN42
	{517,"fEM_R7UX12RSS\0"},	//(R7UX12RSS) X-координата камеры R7IN43
	{518,"fEM_R7UX13RSS\0"},	//(R7UX13RSS) X-координата камеры R7IN51
	{519,"fEM_R7UX14RSS\0"},	//(R7UX14RSS) X-координата камеры R7IN52
	{520,"fEM_R7UX15RSS\0"},	//(R7UX15RSS) X-координата камеры R7IN53
	{521,"fEM_R7UX16RSS\0"},	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
	{522,"fEM_R7UY00RSS\0"},	//(R7UY00RSS) Y-координата АЗ1 см
	{523,"fEM_R7UY01RSS\0"},	//(R7UY01RSS) Y-координата камеры R7IN11
	{524,"fEM_R7UY02RSS\0"},	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
	{525,"fEM_R7UY04RSS\0"},	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
	{526,"fEM_R7UY05RSS\0"},	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
	{527,"fEM_R7UY06RSS\0"},	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
	{528,"fEM_R7UY07RSS\0"},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{529,"fEM_R7UY08RSS\0"},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{530,"fEM_R7UY09RSS\0"},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{531,"fEM_R7UY10RSS\0"},	//(R7UY10RSS) Y-координата камеры R7IN41
	{532,"fEM_R7UY11RSS\0"},	//(R7UY11RSS) Y-координата камеры R7IN42
	{533,"fEM_R7UY12RSS\0"},	//(R7UY12RSS) Y-координата камеры R7IN43
	{534,"fEM_R7UY13RSS\0"},	//(R7UY13RSS) Y-координата камеры R7IN51
	{535,"fEM_R7UY14RSS\0"},	//(R7UY14RSS) Y-координата камеры R7IN52
	{536,"fEM_R7UY15RSS\0"},	//(R7UY15RSS) Y-координата камеры R7IN53
	{537,"iEM_TERA0MT01RIM\0"},	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
	{538,"iEM_TERA0VP81LIM\0"},	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
	{539,"iEM_TERA1IE03LDU\0"},	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
	{540,"iEM_TERA1IE04LDU\0"},	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
	{541,"iEM_TERA1SC01RIM\0"},	//(TERA1SC01RIM) Искажение: Координата штока ББ1
	{542,"iEM_TERA1SS11LIM\0"},	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
	{543,"iEM_TERA1SS12LIM\0"},	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
	{544,"iEM_TERA1SS21LIM\0"},	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
	{545,"iEM_TERA1VP81LIM\0"},	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
	{546,"iEM_TERA2SC01RIM\0"},	//(TERA2SC01RIM) Искажение: Координата штока РБ1
	{547,"iEM_TERA2SP01RIM\0"},	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
	{548,"iEM_TERA2SS11LIM\0"},	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
	{549,"iEM_TERA2SS12LIM\0"},	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
	{550,"iEM_TERA2SS21LIM\0"},	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
	{551,"iEM_TERA2SS33LIM\0"},	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{552,"iEM_TERA2VP82LIM\0"},	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
	{553,"iEM_TERA3SC01RIM\0"},	//(TERA3SC01RIM) Искажение: Координата штока ИС1
	{554,"iEM_TERA3SP02RIM\0"},	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{555,"iEM_TERA3SS11LIM\0"},	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
	{556,"iEM_TERA3SS21LIM\0"},	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
	{557,"iEM_TERA3SS22LIM\0"},	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
	{558,"iEM_TERA3SS31LIM\0"},	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{559,"iEM_TERA3SS33LIM\0"},	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{560,"iEM_TERA3VP81LIM\0"},	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
	{561,"iEM_TERA4SS11LIM\0"},	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
	{562,"iEM_TERA4SS21LIM\0"},	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
	{563,"iEM_TERA4VP82LIM\0"},	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
	{564,"iEM_TERA5SS11LIM\0"},	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
	{565,"iEM_TERA5SS21LIM\0"},	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
	{566,"iEM_TERA5VS12LIM\0"},	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
	{567,"iEM_TERA5VS22LIM\0"},	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
	{568,"iEM_TERA6MS11LIM\0"},	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
	{569,"iEM_TERA6SS21LIM\0"},	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
	{570,"iEM_TERA6VS12LIM\0"},	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
	{571,"iEM_TERA6VS22LIM\0"},	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
	{572,"iEM_TERA7MS31LIM\0"},	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{573,"iEM_TERA8SC01RIM\0"},	//(TERA8SC01RIM) Искажение: Координата ДС2
	{574,"iEM_TERA8SS12LIM\0"},	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
	{575,"iEM_TERA8SS22LIM\0"},	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
	{576,"iEM_TERA9SS11LIM\0"},	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
	{577,"iEM_TERA9SS21LIM\0"},	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
	{578,"iEM_TERB0MT01RIM\0"},	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
	{579,"iEM_TERB0VP81LIM\0"},	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
	{580,"iEM_TERB1IE03LDU\0"},	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
	{581,"iEM_TERB1IE04LDU\0"},	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
	{582,"iEM_TERB1MC01RIM\0"},	//(TERB1MC01RIM) Искажение: Координата штока ББ2
	{583,"iEM_TERB1SS11LIM\0"},	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
	{584,"iEM_TERB1SS12LIM\0"},	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
	{585,"iEM_TERB1SS21LIM\0"},	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
	{586,"iEM_TERB1VP81LIM\0"},	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
	{587,"iEM_TERB2SC01RIM\0"},	//(TERB2SC01RIM) Искажение: Координата штока РБ2
	{588,"iEM_TERB2SP01RIM\0"},	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
	{589,"iEM_TERB2SS11LIM\0"},	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
	{590,"iEM_TERB2SS12LIM\0"},	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
	{591,"iEM_TERB2SS21LIM\0"},	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
	{592,"iEM_TERB2SS33LIM\0"},	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{593,"iEM_TERB3SC01RIM\0"},	//(TERB3SC01RIM) Искажение: Координата штока ИС2
	{594,"iEM_TERB3SP02RIM\0"},	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{595,"iEM_TERB3SS11LIM\0"},	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
	{596,"iEM_TERB3SS21LIM\0"},	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
	{597,"iEM_TERB3SS22LIM\0"},	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
	{598,"iEM_TERB3SS31LIM\0"},	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{599,"iEM_TERB3SS33LIM\0"},	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{600,"iEM_TERB4SS11LIM\0"},	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
	{601,"iEM_TERB4SS21LIM\0"},	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
	{602,"iEM_TERB5SS11LIM\0"},	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
	{603,"iEM_TERB5SS21LIM\0"},	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
	{604,"iEM_TERB5VS12LIM\0"},	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
	{605,"iEM_TERB5VS22LIM\0"},	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
	{606,"iEM_TERB6SS11LIM\0"},	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
	{607,"iEM_TERB6SS21LIM\0"},	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
	{608,"iEM_TERB6VS12LIM\0"},	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
	{609,"iEM_TERB6VS22LIM\0"},	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
	{610,"iEM_TERB7MS31LIM\0"},	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	{611,"iEM_TERB8SC01RIM\0"},	//(TERB8SC01RIM) Искажение: Координата АЗ2
	{612,"iEM_TERB8SS12LIM\0"},	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
	{613,"iEM_TERB8SS22LIM\0"},	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
	{614,"iEM_TERB9SS11LIM\0"},	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
	{615,"iEM_TERB9SS21LIM\0"},	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
	{616,"iEM_TERBB1\0"},	//(TERBB1) Неисправности  ББ1
	{617,"iEM_TERBB2\0"},	//(TERBB2) Неисправности  ББ2
	{618,"iEM_TERBZ1\0"},	//(TERBZ1) Неисправности БЗ1
	{619,"iEM_TERBZ2\0"},	//(TERBZ2) Неисправности БЗ2
	{620,"iEM_TERDS2\0"},	//(TERDS2) Неисправности ДС2 от ИС
	{621,"iEM_TERIS1\0"},	//(TERIS1) Неисправности  ИС1
	{622,"iEM_TERIS2\0"},	//(TERIS2) Неисправности  ИС2
	{623,"iEM_TERMAZ2\0"},	//(TERMAZ2) Неисправности АЗ2 от ИС
	{624,"iEM_TERMDZ1\0"},	//(TERMDZ1) Неисправности МДЗ1
	{625,"iEM_TERMDZ2\0"},	//(TERMDZ2) Неисправности МДЗ2
	{626,"iEM_TERNL1\0"},	//(TERNL1) Неисправности НЛ1
	{627,"iEM_TERNL2\0"},	//(TERNL2) Неисправности НЛ2
	{628,"iEM_TERR0VP81LIM\0"},	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	{629,"iEM_TERR1SS11LIM\0"},	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
	{630,"iEM_TERR1SS21LIM\0"},	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
	{631,"iEM_TERR1VS12LIM\0"},	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
	{632,"iEM_TERR1VS22LIM\0"},	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
	{633,"iEM_TERR2SS11LIM\0"},	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
	{634,"iEM_TERR2SS21LIM\0"},	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
	{635,"iEM_TERR2VS12LIM\0"},	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
	{636,"iEM_TERR2VS22LIM\0"},	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
	{637,"iEM_TERR3SS11LIM\0"},	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
	{638,"iEM_TERR3SS21LIM\0"},	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
	{639,"iEM_TERR4MS21LIM\0"},	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
	{640,"iEM_TERR4SS11LIM\0"},	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
	{641,"iEM_TERR4SS12LIM\0"},	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
	{642,"iEM_TERR4SS22LIM\0"},	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
	{643,"iEM_TERR4VS12LDU\0"},	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{644,"iEM_TERR4VS22LDU\0"},	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{645,"iEM_TERR5SS11LIM\0"},	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
	{646,"iEM_TERR5SS21LIM\0"},	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
	{647,"iEM_TERR6IS62LIM\0"},	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
	{648,"iEM_TERR6IS64LIM\0"},	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
	{649,"iEM_TERR6IS66LIM\0"},	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{650,"iEM_TERR6IS67LIM\0"},	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
	{651,"iEM_TERR6IS68LIM\0"},	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
	{652,"iEM_TERR6SS21LIM\0"},	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
	{653,"iEM_TERR7SI74RIM\0"},	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
	{654,"iEM_TERR8SS11LIM\0"},	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
	{655,"iEM_TERRB1\0"},	//(TERRB1) Неисправности  РБ1
	{656,"iEM_TERRB2\0"},	//(TERRB2) Неисправности  РБ2
	{657,"iEM_TERTLG\0"},	//(TERTLG) Неисправности  тележки от ИС
	{1044,"lEM_C1AD31LRP\0"},	//(C1AD31LRP) Общий сброс от РПУ
	{1045,"lEM_R0IE01LRP\0"},	//(R0IE01LRP) Отключение питание детекторов
	{1046,"lEM_R0IE02LRP\0"},	//(R0IE02LRP) Отключить питание ПР, ПУ
	{1047,"lEM_R3AD10LC1\0"},	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
	{1048,"lEM_R3AD20LC1\0"},	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
	{1049,"lEM_R5AD10LC1\0"},	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
	{1050,"lEM_R5AD20LC1\0"},	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
	{1051,"lEM_R6AD10LC1\0"},	//(R6AD10LC1) Выкатить кран-балку от ИС
	{1052,"lEM_R8AD10LC1\0"},	//(R8AD10LC1) Установить аварийный НИ от ИС
	{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_SCM[]={
	{&R0VZ71LZ1,1,0},	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
	{&R0VZ71LZ2,1,1},	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
	{&C2MD31LP1,1,2},	//( - , SCM) Кнопка «СБРОС РБ»
	{&C1MD31LP2,1,3},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
	{&C1MD31LP1,1,4},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
	{&R0MW13LP2,1,5},	//( - , SCM) Переключатель «СЕТЬ»
	{&lEM_C1AD31LRP,1,6},	//( - , SCM) Общий сброс от РПУ
	{&lEM_R0IE01LRP,1,7},	//( - , SCM) Отключение питание детекторов
	{&lEM_R0IE02LRP,1,8},	//( - , SCM) Отключить питание ПР, ПУ
	{&lEM_R3AD10LC1,1,9},	//( - , SCM) Гомогенные двери-1 открыть от ИС
	{&lEM_R3AD20LC1,1,10},	//( - , SCM) Гомогенные двери-1 закрыть от ИС
	{&lEM_R6AD10LC1,1,11},	//( - , SCM) Выкатить кран-балку от ИС
	{&lEM_R5AD10LC1,1,12},	//( - , SCM) Открыть ворота отстойной зоны от ИС
	{&lEM_R5AD20LC1,1,13},	//( - , SCM) Закрыть ворота отстойной зоны от ИС
	{&lEM_R8AD10LC1,1,14},	//( - , SCM) Установить аварийный НИ от ИС
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SCM[]={
	{&A6VS22LDU,1,0},	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
	{&A6VS12LDU,1,1},	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
	{&B6VS22LDU,1,2},	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
	{&B6VS12LDU,1,3},	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
	{&A5VS22LDU,1,4},	//( - , SCM) Движение НЛ1 в сторону НУ
	{&A5VS12LDU,1,5},	//( - , SCM) Движение НЛ1 в сторону ВУ
	{&B5VS22LDU,1,6},	//( - , SCM) Движение НЛ2 в сторону НУ
	{&B5VS12LDU,1,7},	//( - , SCM) Движение НЛ2 в сторону ВУ
	{&R1VS22LDU,1,8},	//( - , SCM) Движение МДЗ1 в сторону НУ
	{&R2VS22LDU,1,9},	//( - , SCM) Движение МДЗ2 в сторону НУ
	{&R2VS12LDU,1,10},	//( - , SCM) Движение МДЗ2 в сторону ВУ
	{&R1VS12LDU,1,11},	//( - , SCM) Движение МДЗ1 в сторону ВУ
	{&R4VS22LDU,1,12},	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
	{&R4VS12LDU,1,13},	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
	{&B4IS21LDU,1,14},	//( - K08DO, SCM) Приход на НУ НИ2
	{&A1IE03LDU,1,15},	//( - , SCM) Движение ББ1 вперед (от БУШД)
	{&A1IE04LDU,1,16},	//( - , SCM) Движение ББ1 назад (от БУШД)
	{&B1IE03LDU,1,17},	//( - , SCM) Движение ББ2 вперед (от БУШД)
	{&B1IE04LDU,1,18},	//( - , SCM) Движение ББ2 назад (от БУШД)
	{&A1IS11LIM,1,19},	//( - , SCM) Магнит ББ1 обесточен
	{&A1IS32LIM,1,20},	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
	{&B1IS11LIM,1,21},	//( - , SCM) Магнит ББ2 обесточен
	{&B1IS32LIM,1,22},	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
	{&A2IS11LIM,1,23},	//( - , SCM) Магнит РБ1 обесточен
	{&A2IS32LIM,1,24},	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
	{&B2IS11LIM,1,25},	//( - , SCM) Магнит РБ2 обесточен
	{&B2IS32LIM,1,26},	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SCM[]={
	{&R0SR03RIM,8,0},	//( - , SCM) Текущая мощность РУ аз1  (ватт)
	{&A0SN02RIM,8,2},	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
	{&A0SN03RIM,8,4},	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
	{&A0SN04RIM,8,6},	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
	{&A0SN05RIM,8,8},	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
	{&A0SN06RIM,8,10},	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
	{&A0SN07RIM,8,12},	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
	{&B0SN02RIM,8,14},	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
	{&B0SN03RIM,8,16},	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
	{&B0SN04RIM,8,18},	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
	{&B0SN05RIM,8,20},	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
	{&B0SN06RIM,8,22},	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
	{&B0SN07RIM,8,24},	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
	{&A0SR01RIM,8,26},	//( - , SCM) Текущая реактивность AЗ1
	{&B0SR01RIM,8,28},	//( - , SCM) Текущая реактивность AЗ2
	{&A0SN08RIM,8,30},	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
	{&B0SN08RIM,8,32},	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
	{&R0CR01RIM,8,34},	//( - , SCM) Коэффициент 12 связи АЗ1,2
	{&R0CR02RIM,8,36},	//( - , SCM) Коэффициент 11 связи АЗ1,2
	{&R0SR02RIM,8,38},	//( - , SCM) Текущая мощность РУ (ватт)
	{&R0ST01RIM,8,40},	//( - , SCM) Текущий период разгона РУ
	{&R0SR01RIM,8,42},	//( - , SCM) Текущая реактивность PУ
	{&A0VN01RIM,8,44},	//( - , SCM) Период разгона  AЗ1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SCM[]={
	{&R0MW11IP1,3,0},	//( - , SCM) Переключатель ВЫСТРЕЛ
	{&R0DEUMLSS,3,1},	//( - , SCM) Сигнал управления моделью
	{&fEM_R0UL01RIM,8,2},	//( - , SCM) Среднее время генерации нейтронов
	{&fEM_R0UN02RIM,8,4},	//( - , SCM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{&fEM_A1UR01RIM,8,6},	//( - , SCM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{&fEM_A1UR00RIM,8,8},	//( - , SCM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{&fEM_A3UR00RIM,8,10},	//( - , SCM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{&fEM_A3UR01RIM,8,12},	//( - , SCM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{&fEM_R0UT02RIM,8,14},	//( - , SCM) Масса топлива в АЗ
	{&fEM_R0UT04RIM,8,16},	//( - , SCM) Удельная теплоёмкость топлива
	{&fEM_R0UT03RIM,8,18},	//( - , SCM) Нормальная температура АЗ град
	{&fEM_R0UT05RIM,8,20},	//( - , SCM) Энергия деления ядра
	{&fEM_R0UT06RIM,8,22},	//( - , SCM) Конвекционное сопротивление при обдуве
	{&fEM_A1UC02RDU,8,24},	//( - , SCM) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
	{&fEM_A1UC04RIM,8,26},	//( - , SCM) Координата промежуточного путевого выключателя ББ мм
	{&fEM_A1UC05RIM,8,28},	//( - , SCM) Координата переднего аварийного выключателя ББ мм
	{&fEM_A1UC06RIM,8,30},	//( - , SCM) Координата заднего аварийного выключателя ББ мм
	{&fEM_A2UC06RIM,8,32},	//( - , SCM) Координата заднего аварийного выключателя РБ мм
	{&fEM_A2UC05RIM,8,34},	//( - , SCM) Координата переднего аварийного выключателя РБ мм
	{&fEM_A2UC04RIM,8,36},	//( - , SCM) Координата промежуточного путевого выключателя РБ мм
	{&fEM_A2UC02RDU,8,38},	//( - , SCM) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
	{&fEM_A3UC06RIM,8,40},	//( - , SCM) Координата заднего аварийного выключателя ИС мм
	{&fEM_A3UC05RIM,8,42},	//( - , SCM) Координата переднего аварийного выключателя ИС мм
	{&fEM_A3UC04RIM,8,44},	//( - , SCM) Координата промежуточного путевого выключателя ИС мм
	{&fEM_A3UC02RDU,8,46},	//( - , SCM) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
	{&fEM_R4UV80RDU,8,48},	//( - , SCM) Номинальная скорость тележки (см/с)
	{&fEM_R4UC10RIM,8,50},	//( - , SCM) Координата верхних механических упоров тележки мм
	{&fEM_R4UC20RIM,8,52},	//( - , SCM) Координата нижних механических упоров тележки мм
	{&fEM_B8UC21RIM,8,54},	//( - , SCM) Координата верхнего путевого выключателя АЗ2 мм
	{&fEM_B8UC20RIM,8,56},	//( - , SCM) Координата верхних механических упоров АЗ2 мм
	{&fEM_B8UC11RIM,8,58},	//( - , SCM) Координата нижнего путевого выключателя АЗ2 мм
	{&fEM_B8UC10RIM,8,60},	//( - , SCM) Координата нижних механических упоров АЗ2 мм
	{&fEM_B8UV80RDU,8,62},	//( - , SCM) Номинальная скорость АЗ2 (мм/с)
	{&fEM_A8UV80RDU,8,64},	//( - , SCM) Номинальная скорость ДС2 (мм/с)
	{&fEM_A8UC10RIM,8,66},	//( - , SCM) Координата нижних механических упоров ДС2 мм
	{&fEM_A8UC11RIM,8,68},	//( - , SCM) Координата нижнего путевого выключателя ДС2 мм
	{&fEM_A8UC20RIM,8,70},	//( - , SCM) Координата верхних механических упоров ДС2 мм
	{&fEM_A8UC21RIM,8,72},	//( - , SCM) Координата верхнего путевого выключателя ДС2 мм
	{&fEM_A6UC10RIM,8,74},	//( - , SCM) Время полного хода БЗ (сек)
	{&fEM_R1UC10RIM,8,76},	//( - , SCM) Время полного хода МДЗ сек
	{&fEM_A5UC10RIM,8,78},	//( - , SCM) Время полного хода НЛ сек
	{&fEM_A0UN01RIM,8,80},	//( - , SCM) Мощность источника нейтронов ИНИ
	{&fEM_R4UC22RIM,8,82},	//( - , SCM) Смещение координаты АЗ от координаты тележки
	{&fEM_A1UG01RDU,8,84},	//( - , SCM) Расстояние включения масляного демпфера ББ(мм)
	{&fEM_A2UG01RDU,8,86},	//( - , SCM) Расстояние включения масляного демпфера РБ
	{&fEM_A3UG01RDU,8,88},	//( - , SCM) Расстояние включения масляного демпфера ИС
	{&fEM_R7UC10RIM,8,90},	//( - , SCM) X-координата КНК53М R7IN13 см
	{&fEM_R7UC19RIM,8,92},	//( - , SCM) Y-координата СНМ-11 (11) см
	{&fEM_R7UI02RIM,8,94},	//( - , SCM) Коэффициент усиления уровня радиации
	{&fEM_R7UL01RIM,8,96},	//( - , SCM) Постоянная времени изменения уровня радиации в зале
	{&fEM_A2UR00RIM,8,98},	//( - , SCM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
	{&fEM_A2UR01RIM,8,100},	//( - , SCM) Коэффициент-1 функции реактивности вносимой РБ (долл)
	{&fEM_A0UN02RIM,8,102},	//( - , SCM) Мощность источника нейтронов с АНИ
	{&fEM_R0UR30RIM,8,104},	//( - , SCM) Реактивность вносимая образцами (долл)
	{&fEM_R0UR01RIM,8,106},	//( - , SCM) Стартовая отрицательная реактивность
	{&fEM_R0UT02RDU,8,108},	//( - , SCM) Верхний предел шкалы датчика температуры
	{&fEM_R0UT01RDU,8,110},	//( - , SCM) Нижний предел шкалы датчика температуры
	{&fEM_A1UC03RDU,8,112},	//( - , SCM) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
	{&fEM_A2UP03RDU,8,114},	//( - , SCM) Верхний предел шкалы датчика давления на подъем/сброс РБ
	{&fEM_A2UP04RDU,8,116},	//( - , SCM) Нижний предел шкалы датчика давления на подъем/сброс РБ
	{&fEM_A2UC03RDU,8,118},	//( - , SCM) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
	{&fEM_A3UP03RDU,8,120},	//( - , SCM) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{&fEM_A3UP04RDU,8,122},	//( - , SCM) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{&fEM_A3UC03RDU,8,124},	//( - , SCM) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
	{&fEM_R7UI74RIM,8,126},	//( - , SCM) Верхняя граница измерения уровня радиации в зале
	{&fEM_A8UC03RDU,8,128},	//( - , SCM) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
	{&fEM_R0UV87RDU,8,130},	//( - , SCM) 7-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UV81RDU,8,132},	//( - , SCM) 1-я частота двигателя (шагов/секунду)
	{&fEM_R0UV82RDU,8,134},	//( - , SCM) 3-я частота двигателя (шагов/секунду)
	{&fEM_R0UV83RDU,8,136},	//( - , SCM) 4-я частота двигателя (шагов/секунду)
	{&fEM_R0UV84RDU,8,138},	//( - , SCM) 5-я частота двигателя (шагов/секунду)
	{&fEM_R0UV85RDU,8,140},	//( - , SCM) 6-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UV86RDU,8,142},	//( - , SCM) 7-я скорость перемещения ББ (шагов/секунду)
	{&fEM_A8UC08RDU,8,144},	//( - , SCM) Зона срабатывания КВ ДС2(мм)
	{&fEM_B8UC08RDU,8,146},	//( - , SCM) Зона срабатывания КВ АЗ2(мм)
	{&fEM_R4UC08RDU,8,148},	//( - , SCM) Зона срабатывания КВ тележки РУ(мм)
	{&fEM_R0UH01RSS,8,150},	//( - , SCM) Коэфф. преобразования частота->нейтр/с  СНМ11
	{&fEM_A0UX00RSS,8,152},	//( - , SCM) Эффективный радиус АЗ
	{&fEM_R7UX01RSS,8,154},	//( - , SCM) X-координата камеры R7IN11
	{&fEM_R7UX02RSS,8,156},	//( - , SCM) X-координата камеры R7IN12 (см)
	{&fEM_R7UX04RSS,8,158},	//( - , SCM) X-координата камеры R7IN21 (см)
	{&fEM_R7UX05RSS,8,160},	//( - , SCM) X-координата камеры R7IN22 (см)
	{&fEM_R7UX06RSS,8,162},	//( - , SCM) X-координата камеры R7IN23 (см)
	{&fEM_R7UX07RSS,8,164},	//( - , SCM) X-координата камеры R7IN31 (см)
	{&fEM_R7UX08RSS,8,166},	//( - , SCM) X-координата камеры R7IN32 (см)
	{&fEM_R7UX09RSS,8,168},	//( - , SCM) X-координата камеры R7IN33 (см)
	{&fEM_R7UY01RSS,8,170},	//( - , SCM) Y-координата камеры R7IN11
	{&fEM_R7UY02RSS,8,172},	//( - , SCM) Y-координата камеры R7IN12 (см)
	{&fEM_R7UY04RSS,8,174},	//( - , SCM) Y-координата камеры R7IN21 (см)
	{&fEM_R7UY05RSS,8,176},	//( - , SCM) Y-координата камеры R7IN22 (см)
	{&fEM_R7UY06RSS,8,178},	//( - , SCM) Y-координата камеры R7IN23 (см)
	{&fEM_R7UY07RSS,8,180},	//( - , SCM) Y-координата камеры R7IN31 (см)
	{&fEM_R7UY08RSS,8,182},	//( - , SCM) Y-координата камеры R7IN32 (см)
	{&fEM_R7UY09RSS,8,184},	//( - , SCM) Y-координата камеры R7IN33 (см)
	{&fEM_R7UX10RSS,8,186},	//( - , SCM) X-координата камеры R7IN41
	{&fEM_R7UX11RSS,8,188},	//( - , SCM) X-координата камеры R7IN42
	{&fEM_R7UX12RSS,8,190},	//( - , SCM) X-координата камеры R7IN43
	{&fEM_R7UY10RSS,8,192},	//( - , SCM) Y-координата камеры R7IN41
	{&fEM_R7UY11RSS,8,194},	//( - , SCM) Y-координата камеры R7IN42
	{&fEM_R7UY12RSS,8,196},	//( - , SCM) Y-координата камеры R7IN43
	{&fEM_A0UX01RSS,8,198},	//( - , SCM) Первый коэффициент калибровки камеры 1
	{&fEM_A0UX02RSS,8,200},	//( - , SCM) Первый коэффициент калибровки камеры 2
	{&fEM_A0UX03RSS,8,202},	//( - , SCM) Первый коэффициент калибровки камеры 3
	{&fEM_A0UX04RSS,8,204},	//( - , SCM) Первый коэффициент калибровки камеры4
	{&fEM_A0UX05RSS,8,206},	//( - , SCM) Первый коэффициент калибровки камеры 5
	{&fEM_A0UX06RSS,8,208},	//( - , SCM) Первый коэффициент калибровки камеры 6
	{&fEM_A0UX07RSS,8,210},	//( - , SCM) Первый коэффициент калибровки камеры 7
	{&fEM_A0UX08RSS,8,212},	//( - , SCM) Первый коэффициент калибровки камеры 8
	{&fEM_A0UX09RSS,8,214},	//( - , SCM) Первый коэффициент калибровки камеры 9
	{&fEM_A0UX10RSS,8,216},	//( - , SCM) Первый коэффициент калибровки камеры 10
	{&fEM_A0UX11RSS,8,218},	//( - , SCM) Первый коэффициент калибровки камеры 11
	{&fEM_A0UX12RSS,8,220},	//( - , SCM) Первый коэффициент калибровки камеры 12
	{&fEM_B0UX01RSS,8,222},	//( - , SCM) Второй коэффициент калибровки камеры 1
	{&fEM_B0UX02RSS,8,224},	//( - , SCM) Второй коэффициент калибровки камеры 2
	{&fEM_B0UX03RSS,8,226},	//( - , SCM) Второй коэффициент калибровки камеры 3
	{&fEM_B0UX04RSS,8,228},	//( - , SCM) Второй коэффициент калибровки камеры 4
	{&fEM_B0UX05RSS,8,230},	//( - , SCM) Второй коэффициент калибровки камеры 5
	{&fEM_B0UX06RSS,8,232},	//( - , SCM) Второй коэффициент калибровки камеры 6
	{&fEM_B0UX07RSS,8,234},	//( - , SCM) Второй коэффициент калибровки камеры 7
	{&fEM_B0UX08RSS,8,236},	//( - , SCM) Второй коэффициент калибровки камеры 8
	{&fEM_B0UX09RSS,8,238},	//( - , SCM) Второй коэффициент калибровки камеры 9
	{&fEM_B0UX10RSS,8,240},	//( - , SCM) Второй коэффициент калибровки камеры 10
	{&fEM_B0UX11RSS,8,242},	//( - , SCM) Второй коэффициент калибровки камеры 11
	{&fEM_B0UX12RSS,8,244},	//( - , SCM) Второй коэффициент калибровки камеры 12
	{&fEM_R0UH02RSS,8,246},	//( - , SCM) Коэфф. преобразования частота->нейтр/с  КНК15-1
	{&fEM_R0UH03RSS,8,248},	//( - , SCM) Коэфф. преобразования частота->нейтр/с  КНК53М
	{&fEM_R4US80RDU,8,250},	//( - , SCM) Тормозной путь тележки (мм)
	{&fEM_R7UI71RIM,8,252},	//( - , SCM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{&fEM_R7UI72RIM,8,254},	//( - , SCM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
	{&fEM_R7UI73RIM,8,256},	//( - , SCM) Уровень мощности срабатывания АС II УР  ватт
	{&fEM_A1UP01RIM,8,258},	//( - , SCM) Текущее давление на сброс ББ (МПа)
	{&fEM_A2UP01RIM,8,260},	//( - , SCM) Текущее давление на сброс РБ
	{&fEM_A0UP02RIM,8,262},	//( - , SCM) Текущее давление в АЗ1,2
	{&fEM_A3UP01RIM,8,264},	//( - , SCM) Текущее давление на СПУСК ИС
	{&fEM_A1UP82RIM,8,266},	//( - , SCM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{&fEM_A3UP02RDU,8,268},	//( - , SCM) Текущее давление ВЫСТРЕЛ ИС
	{&fEM_A1UV02RIM,8,270},	//( - , SCM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{&fEM_A3UV02RIM,8,272},	//( - , SCM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{&fEM_A2UV02RIM,8,274},	//( - , SCM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{&fEM_B8US80RDU,8,276},	//( - , SCM) Тормозной путь АЗ2 (мм)
	{&fEM_A8US80RDU,8,278},	//( - , SCM) Тормозной путь ДС2 (мм)
	{&fEM_A6US80RDU,8,280},	//( - , SCM) Тормозной путь БЗ (мм)
	{&fEM_A1US07RDU,8,282},	//( - , SCM) Постоянная времени масляного демпфера ББ
	{&fEM_A2US07RDU,8,284},	//( - , SCM) Постоянная времени масляного демпфера РБ
	{&fEM_A3US07RDU,8,286},	//( - , SCM) Постоянная времени масляного демпфера ИС
	{&fEM_R7UI75RIM,8,288},	//( - , SCM) Множитель к уровню радиации
	{&fEM_R0UH21RSS,8,290},	//( - , SCM) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{&fEM_R0UH22RSS,8,292},	//( - , SCM) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{&fEM_R0UH23RSS,8,294},	//( - , SCM) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{&fEM_R0UH05RSS,8,296},	//( - , SCM) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_A4UL10RIM,8,298},	//( - , SCM) Время полного перемещения НИ сек
	{&fEM_A9UL10RIM,8,300},	//( - , SCM) Время полного перемещения НИ ДС1/ДС2 сек
	{&fEM_R3UL10RIM,8,302},	//( - , SCM) Время полного хода гомогенных дверей (сек)
	{&fEM_R5UL10RIM,8,304},	//( - , SCM) Время полного хода ворот отстойной зоны (дес. мс)
	{&fEM_R6UL10RIM,8,306},	//( - , SCM) Время полного хода кран-балки сек
	{&fEM_A2UP02RIM,8,308},	//( - , SCM) Текущее давление на подъём РБ
	{&fEM_A2UP03RIM,8,310},	//( - , SCM) Нижняя граница давления на ПОДЪЁМ РБ
	{&fEM_A0UP01RIM,8,312},	//( - , SCM) Текущее давление в АЗ1,2
	{&fEM_A3UP02RIM,8,314},	//( - , SCM) Нижняя граница  давления на СПУСК ИС
	{&fEM_A4UP01RIM,8,316},	//( - , SCM) Текущее давление на подъём НИ
	{&fEM_A4UP02RIM,8,318},	//( - , SCM) Нижняя граница давления на подъём НИ
	{&fEM_R7UI76RIM,8,320},	//( - , SCM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{&fEM_R7UI77RIM,8,322},	//( - , SCM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{&iEM_TERBB1,3,324},	//( - , SCM) Неисправности  ББ1
	{&fEM_A1MC02RC1,8,325},	//( - , SCM) Заданная координата штока ББ1 от ИС
	{&fEM_A1MV02RC1,8,327},	//( - , SCM) Заданная скорость движения  штока ББ1 от ИС
	{&iEM_TERBB2,3,329},	//( - , SCM) Неисправности  ББ2
	{&fEM_B1MC02RC1,8,330},	//( - , SCM) Заданная координата штока ББ2 от ИС
	{&fEM_B1MV02RC1,8,332},	//( - , SCM) Заданная скорость движения штока ББ2 от ИС
	{&iEM_TERRB2,3,334},	//( - , SCM) Неисправности  РБ2
	{&fEM_B2MC02RC1,8,335},	//( - , SCM) Заданная координата штока РБ2 от ИС
	{&fEM_B2MV02RC1,8,337},	//( - , SCM) Заданная скорость движения штока РБ2 от ИС
	{&iEM_TERRB1,3,339},	//( - , SCM) Неисправности  РБ1
	{&fEM_A2MC02RC1,8,340},	//( - , SCM) Заданная координата штока РБ1 от ИС
	{&fEM_A2MV02RC1,8,342},	//( - , SCM) Заданная скорость движения штока РБ1 от ИС
	{&iEM_TERIS2,3,344},	//( - , SCM) Неисправности  ИС2
	{&fEM_B3MC02RC1,8,345},	//( - , SCM) Заданная координата штока ИС2 от ИС
	{&fEM_B3MV02RC1,8,347},	//( - , SCM) Заданная скорость движения штока ИС2 от ИС
	{&iEM_TERIS1,3,349},	//( - , SCM) Неисправности  ИС1
	{&fEM_A3MC02RC1,8,350},	//( - , SCM) Заданная координата штока ИС1 от ИС
	{&fEM_A3MV02RC1,8,352},	//( - , SCM) Заданная скорость движения штока ИС1 от ИС
	{&iEM_TERA1IE04LDU,3,354},	//( - , SCM) Искажение Движение ББ1 назад (от БУШД)
	{&iEM_TERA1IE03LDU,3,355},	//( - , SCM) Искажение Движение ББ1 вперёд (от БУШД)
	{&fEM_A1MC01RC1,8,356},	//( - , SCM) Заданная координата  ББ1 от ИС
	{&iEM_TERB1IE03LDU,3,358},	//( - , SCM) Искажение Движение ББ2 вперёд (от БУШД)
	{&iEM_TERB1IE04LDU,3,359},	//( - , SCM) Искажение Движение ББ2 назад (от БУШД)
	{&fEM_B1MC01RC1,8,360},	//( - , SCM) Заданная координата ББ2 от ИС
	{&fEM_B1MV01RC1,8,362},	//( - , SCM) Заданная скорость движения ББ2 от ИС
	{&fEM_B2MC01RC1,8,364},	//( - , SCM) Заданная координата РБ2 от ИС
	{&fEM_B2MV01RC1,8,366},	//( - , SCM) Заданная скорость движения  РБ2 от ИС
	{&fEM_A3MC01RC1,8,368},	//( - , SCM) Заданная координата ИС1 от ИС
	{&fEM_A3MV01RC1,8,370},	//( - , SCM) Заданная скорость движения ИС1 от ИС
	{&fEM_B3MC01RC1,8,372},	//( - , SCM) Заданная координата ИС2 от ИС
	{&fEM_B3MV01RC1,8,374},	//( - , SCM) Заданная скорость движения ИС2 от ИС
	{&iEM_TERA2SS21LIM,3,376},	//( - , SCM) Искажение: Приход на НУ РБ1
	{&iEM_TERA2SS12LIM,3,377},	//( - , SCM) Искажение: Магнит РБ1 зацеплен
	{&iEM_TERR6SS21LIM,3,378},	//( - , SCM) Искажение: Кран-балка в нерабочем положении
	{&iEM_TERA2VP82LIM,3,379},	//( - , SCM) Искажение: Текущее давление на подъём РБ  в норме
	{&iEM_TERA2SS11LIM,3,380},	//( - , SCM) Искажение: Приход на ВУ РБ1
	{&iEM_TERB3SS21LIM,3,381},	//( - , SCM) Искажение: Приход на НУ ИС2
	{&iEM_TERA0MT01RIM,3,382},	//( - , SCM) Искажение: Текущая температура AЗ1
	{&iEM_TERB0MT01RIM,3,383},	//( - , SCM) Искажение: Текущая температура AЗ2
	{&iEM_TERA2SP01RIM,3,384},	//( - , SCM) Искажение: Текущее давление СБРОС РБ1
	{&iEM_TERB2SP01RIM,3,385},	//( - , SCM) Искажение: Текущее давление СБРОС РБ2
	{&iEM_TERB3SP02RIM,3,386},	//( - , SCM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{&iEM_TERA3SC01RIM,3,387},	//( - , SCM) Искажение: Координата штока ИС1
	{&iEM_TERA3VP81LIM,3,388},	//( - , SCM) Искажение: Текущее давление СПУСК ИС  в норме
	{&iEM_TERA2SC01RIM,3,389},	//( - , SCM) Искажение: Координата штока РБ1
	{&iEM_TERA2SS33LIM,3,390},	//( - , SCM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{&iEM_TERA3SS21LIM,3,391},	//( - , SCM) Искажение: Приход на НУ ИС1
	{&iEM_TERA3SS33LIM,3,392},	//( - , SCM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{&iEM_TERA3SS31LIM,3,393},	//( - , SCM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{&iEM_TERB3SS31LIM,3,394},	//( - , SCM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{&iEM_TERB3SS33LIM,3,395},	//( - , SCM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{&iEM_TERB3SC01RIM,3,396},	//( - , SCM) Искажение: Координата штока ИС2
	{&iEM_TERA3SS11LIM,3,397},	//( - , SCM) Искажение: Приход на ВУ ИС1
	{&iEM_TERB3SS11LIM,3,398},	//( - , SCM) Искажение: Приход на ВУ ИС2
	{&iEM_TERR6IS64LIM,3,399},	//( - , SCM) Искажение: Исправность ВИП ССДИ-35
	{&iEM_TERB3SS22LIM,3,400},	//( - , SCM) Искажение: Приход на НУП ИС2
	{&iEM_TERA3SS22LIM,3,401},	//( - , SCM) Искажение: Приход на НУП ИС1
	{&iEM_TERA3SP02RIM,3,402},	//( - , SCM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{&iEM_TERR6IS62LIM,3,403},	//( - , SCM) Искажение Исправность ВИП ССДИ-39
	{&iEM_TERR6IS66LIM,3,404},	//( - , SCM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{&iEM_TERR6IS67LIM,3,405},	//( - , SCM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
	{&iEM_TERA0VP81LIM,3,406},	//( - , SCM) Искажение: Давление  АЗ1  в норме
	{&iEM_TERB0VP81LIM,3,407},	//( - , SCM) Искажение: Давление  АЗ2 в норме
	{&iEM_TERR0VP81LIM,3,408},	//( - , SCM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	{&iEM_TERR6IS68LIM,3,409},	//( - , SCM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
	{&iEM_TERR7SI74RIM,3,410},	//( - , SCM) Искажение: Радиация в реакторном зале
	{&iEM_TERA5SS21LIM,3,411},	//( - , SCM) Искажение: Приход на НУ НЛ1
	{&iEM_TERB5SS11LIM,3,412},	//( - , SCM) Искажение: Приход на ВУ НЛ2
	{&iEM_TERA5SS11LIM,3,413},	//( - , SCM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
	{&iEM_TERA9SS11LIM,3,414},	//( - , SCM) Искажение: Приход на ВУ НИ ДС1
	{&iEM_TERB2SS11LIM,3,415},	//( - , SCM) Искажение: Приход на ВУ РБ2
	{&iEM_TERB2SS12LIM,3,416},	//( - , SCM) Искажение: Магнит РБ2 зацеплен
	{&iEM_TERB2SS21LIM,3,417},	//( - , SCM) Искажение: Приход на НУ РБ2
	{&iEM_TERR3SS11LIM,3,418},	//( - , SCM) Искажение: Приход на ВУ гомогенных дверей-1
	{&iEM_TERB2SC01RIM,3,419},	//( - , SCM) Искажение: Координата штока РБ2
	{&iEM_TERR3SS21LIM,3,420},	//( - , SCM) Искажение: Приход на НУ гомогенных дверей-1
	{&iEM_TERR5SS11LIM,3,421},	//( - , SCM) Искажение: Приход на ВУ ворот отстойной зоны
	{&iEM_TERA4SS11LIM,3,422},	//( - , SCM) Искажение: Приход на ВУ НИ1
	{&iEM_TERR1SS11LIM,3,423},	//( - , SCM) Искажение: Приход на ВУ МДЗ1
	{&iEM_TERR1SS21LIM,3,424},	//( - , SCM) Искажение: Приход на НУ МДЗ1
	{&iEM_TERR2SS11LIM,3,425},	//( - , SCM) Искажение: Приход на ВУ МДЗ2
	{&iEM_TERR2SS21LIM,3,426},	//( - , SCM) Искажение: Приход на НУ МДЗ2
	{&iEM_TERA4VP82LIM,3,427},	//( - , SCM) Искажение Давление ПОДЪЁМ НИ в норме
	{&iEM_TERB4SS21LIM,3,428},	//( - , SCM) Искажение: Приход на НУ НИ2
	{&iEM_TERR5SS21LIM,3,429},	//( - , SCM) Искажение: Приход на НУ ворот отстойной зоны
	{&iEM_TERB6SS21LIM,3,430},	//( - , SCM) Искажение: Приход на НУ БЗ2
	{&iEM_TERB4SS11LIM,3,431},	//( - , SCM) Искажение: Приход на ВУ НИ2
	{&iEM_TERA4SS21LIM,3,432},	//( - , SCM) Искажение: Приход на НУ НИ1
	{&iEM_TERA6MS11LIM,3,433},	//( - , SCM) Искажение: Приход на ВУ БЗ1
	{&iEM_TERA6SS21LIM,3,434},	//( - , SCM) Искажение: Приход на НУ БЗ1
	{&iEM_TERB6SS11LIM,3,435},	//( - , SCM) Искажение: Приход на ВУ БЗ2
	{&iEM_TERR4SS11LIM,3,436},	//( - , SCM) Искажение: Приход на ВУ тележки
	{&iEM_TERR4MS21LIM,3,437},	//( - , SCM) Искажение: Приход на НУ тележки
	{&iEM_TERR4SS12LIM,3,438},	//( - , SCM) Искажение: Приход на механический ВУ тележки
	{&iEM_TERR4SS22LIM,3,439},	//( - , SCM) Искажение: Приход на механический НУ тележки
	{&iEM_TERR8SS11LIM,3,440},	//( - , SCM) Искажение: Аварийный НИ установлен
	{&iEM_TERB8SC01RIM,3,441},	//( - , SCM) Искажение: Координата АЗ2
	{&iEM_TERA8SC01RIM,3,442},	//( - , SCM) Искажение: Координата ДС2
	{&iEM_TERB8SS12LIM,3,443},	//( - , SCM) Искажение: Приход на механический ВУ АЗ2
	{&iEM_TERA8SS12LIM,3,444},	//( - , SCM) Искажение: Приход на механический ВУ ДС2
	{&iEM_TERB8SS22LIM,3,445},	//( - , SCM) Искажение: Приход на механический НУ АЗ2
	{&iEM_TERA8SS22LIM,3,446},	//( - , SCM) Искажение: Приход на механический НУ ДС2
	{&iEM_TERA9SS21LIM,3,447},	//( - , SCM) Искажение: Приход на НУ НИ ДС1
	{&iEM_TERB9SS21LIM,3,448},	//( - , SCM) Искажение: Приход на НУ НИ ДС2
	{&iEM_TERB9SS11LIM,3,449},	//( - , SCM) Искажение: Приход на ВУ НИ ДС2
	{&iEM_TERB5SS21LIM,3,450},	//( - , SCM) Искажение: Приход на НУ НЛ2
	{&iEM_TERA1SS21LIM,3,451},	//( - , SCM) Искажение: Приход на НУ ББ1
	{&iEM_TERA1SS11LIM,3,452},	//( - , SCM) Искажение: Приход на ВУ ББ1
	{&iEM_TERA1SC01RIM,3,453},	//( - , SCM) Искажение: Координата штока ББ1
	{&iEM_TERA1SS12LIM,3,454},	//( - , SCM) Искажение: Магнит ББ1 зацеплен
	{&iEM_TERB1SS21LIM,3,455},	//( - , SCM) Искажение: Приход на НУ ББ2
	{&iEM_TERB1SS11LIM,3,456},	//( - , SCM) Искажение:Приход на ВУ ББ2
	{&iEM_TERB1MC01RIM,3,457},	//( - , SCM) Искажение: Координата штока ББ2
	{&iEM_TERB1SS12LIM,3,458},	//( - , SCM) Искажение: Магнит ББ2 зацеплен
	{&iEM_TERTLG,3,459},	//( - , SCM) Неисправности  тележки от ИС
	{&fEM_R4MC01RC1,8,460},	//( - , SCM) Заданная координата тележки от ИС
	{&fEM_R4MV01RC1,8,462},	//( - , SCM) Заданная скорость тележки от ИС
	{&iEM_TERMAZ2,3,464},	//( - , SCM) Неисправности АЗ2 от ИС
	{&fEM_B8MV01RC1,8,465},	//( - , SCM) Заданная скорость АЗ2 от ИС
	{&iEM_TERDS2,3,467},	//( - , SCM) Неисправности ДС2 от ИС
	{&fEM_A8MC01RC1,8,468},	//( - , SCM) Заданная координата ДС2 от ИС
	{&fEM_A8MV01RC1,8,470},	//( - , SCM) Заданная скорость ДС2 от ИС
	{&iEM_TERBZ1,3,472},	//( - , SCM) Неисправности БЗ1
	{&fEM_A6MC01RC1,8,473},	//( - , SCM) Заданная координата БЗ1 от ИС
	{&fEM_A6MV01RC1,8,475},	//( - , SCM) Заданная скорость БЗ1 от ИС
	{&iEM_TERBZ2,3,477},	//( - , SCM) Неисправности БЗ2
	{&fEM_B6MC01RC1,8,478},	//( - , SCM) Заданная координата БЗ2 от ИС
	{&fEM_B6MV01RC1,8,480},	//( - , SCM) Заданная скорость БЗ2 от ИС
	{&iEM_TERMDZ2,3,482},	//( - , SCM) Неисправности МДЗ2
	{&fEM_R2MC01RC1,8,483},	//( - , SCM) Заданная координата МДЗ2 от ИС
	{&fEM_R2MV01RC1,8,485},	//( - , SCM) Заданная скорость МДЗ2 от ИС
	{&iEM_TERMDZ1,3,487},	//( - , SCM) Неисправности МДЗ1
	{&fEM_R1MC01RC1,8,488},	//( - , SCM) Заданная координата МДЗ1 от ИС
	{&fEM_R1MV01RC1,8,490},	//( - , SCM) Заданная скорость МДЗ1 от ИС
	{&iEM_TERNL1,3,492},	//( - , SCM) Неисправности НЛ1
	{&fEM_A5MC01RC1,8,493},	//( - , SCM) Заданная координата НЛ1 от ИС
	{&fEM_A5MV01RC1,8,495},	//( - , SCM) Заданная скорость НЛ1 от ИС
	{&iEM_TERNL2,3,497},	//( - , SCM) Неисправности НЛ2
	{&fEM_B5MC01RC1,8,498},	//( - , SCM) Заданная координата НЛ2 от ИС
	{&fEM_B5MV01RC1,8,500},	//( - , SCM) Заданная скорость НЛ2 от ИС
	{&fEM_A1UC08RIM,8,502},	//( - , SCM) Зона срабатывания КВ ББ(мм)
	{&fEM_A2UC08RIM,8,504},	//( - , SCM) Зона срабатывания КВ  РБ мм
	{&fEM_A3UC08RIM,8,506},	//( - , SCM) Зона срабатывания КВ ИС(мм)
	{&iEM_TERB2SS33LIM,3,508},	//( - , SCM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{&iEM_TERA1VP81LIM,3,509},	//( - , SCM) Искажение: Текущее давление СБРОС ББ1  в норме
	{&iEM_TERB1VP81LIM,3,510},	//( - , SCM) Искажение: Текущее давление СБРОС ББ2  в норме
	{&fEM_A0UT03RSP,8,511},	//( - , SCM) Стартовая  температура АЗ1 град
	{&fEM_A0UR01RSP,8,513},	//( - , SCM) Стартовая  реактивность АЗ1
	{&fEM_A0UR02RSP,8,515},	//( - , SCM) Стартовый  поток нейтронов АЗ1
	{&fEM_B0UT03RSP,8,517},	//( - , SCM) Стартовая  температура АЗ2 град
	{&fEM_A1MC01RSP,8,519},	//( - , SCM) Стартовая координата  ББ1
	{&fEM_A1MC02RSP,8,521},	//( - , SCM) Стартовая координата штока ББ1
	{&fEM_B1MC01RSP,8,523},	//( - , SCM) Стартовая координата  ББ2
	{&fEM_B1MC02RSP,8,525},	//( - , SCM) Стартовая координата штока ББ2
	{&fEM_A2MC01RC1,8,527},	//( - , SCM) Заданная координата РБ1 от ИС
	{&fEM_A2MV01RC1,8,529},	//( - , SCM) Заданная скорость движения РБ1 от ИС
	{&fEM_A2MC01RSP,8,531},	//( - , SCM) Стартовая координата  РБ1
	{&fEM_A2MC02RSP,8,533},	//( - , SCM) Стартовая координата штока РБ1
	{&fEM_B2MC01RSP,8,535},	//( - , SCM) Стартовая координата  РБ2
	{&fEM_B2MC02RSP,8,537},	//( - , SCM) Стартовая координата штока РБ2
	{&fEM_A3MC01RSP,8,539},	//( - , SCM) Стартовая координата  ИС1
	{&fEM_A3MC02RSP,8,541},	//( - , SCM) Стартовая координата штока ИС1
	{&fEM_B3MC01RSP,8,543},	//( - , SCM) Стартовая координата  ИС2
	{&fEM_B3MC02RSP,8,545},	//( - , SCM) Стартовая координата штока ИС2
	{&fEM_B8MC01RSP,8,547},	//( - , SCM) Стартовая координата АЗ2
	{&fEM_A8MC01RSP,8,549},	//( - , SCM) Стартовая координата ДС2
	{&fEM_A6MC01RSP,8,551},	//( - , SCM) Стартовая координата БЗ1
	{&fEM_B6MC01RSP,8,553},	//( - , SCM) Стартовая координата БЗ2
	{&fEM_R3UC01RSP,8,555},	//( - , SCM) Стартовая координата Гомогенных дверей
	{&fEM_R5UC01RSP,8,557},	//( - , SCM) Стартовая координата Ворот отстойной зоны
	{&fEM_R6UC01RSP,8,559},	//( - , SCM) Стартовая координата Кран-балки
	{&fEM_R2MC01RSP,8,561},	//( - , SCM) Стартовая координата МДЗ2
	{&fEM_R1MC01RSP,8,563},	//( - , SCM) Стартовая координата МДЗ1
	{&fEM_A5MC01RSP,8,565},	//( - , SCM) Стартовая координата НЛ1
	{&fEM_B5MC01RSP,8,567},	//( - , SCM) Стартовая координата НЛ2
	{&fEM_A9MC01RSP,8,569},	//( - , SCM) Стартовая координата НИ ДС1
	{&fEM_B9MC01RSP,8,571},	//( - , SCM) Стартовая координата НИ ДС2
	{&fEM_A4MC01RSP,8,573},	//( - , SCM) Стартовая координата НИ1
	{&fEM_B4MC01RSP,8,575},	//( - , SCM) Стартовая координата НИ2
	{&fEM_R4MC01RSP,8,577},	//( - , SCM) Стартовая координата тележки
	{&fEM_A1MV01RC1,8,579},	//( - , SCM) Заданная скорость движения  ББ1 от ИС
	{&iEM_TERB7MS31LIM,3,581},	//( - , SCM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	{&iEM_TERA7MS31LIM,3,582},	//( - , SCM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{&fEM_R7UY00RSS,8,583},	//( - , SCM) Y-координата АЗ1 см
	{&iEM_TERA6VS12LIM,3,585},	//( - , SCM) Искажение: Движение створок БЗ1 к ОТКРЫТА
	{&iEM_TERA6VS22LIM,3,586},	//( - , SCM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
	{&iEM_TERB6VS12LIM,3,587},	//( - , SCM) Искажение: Движение створок БЗ2 к ОТКРЫТА
	{&iEM_TERB6VS22LIM,3,588},	//( - , SCM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
	{&iEM_TERA5VS22LIM,3,589},	//( - , SCM) Искажение: Движение створок НЛ1 к НУ
	{&iEM_TERA5VS12LIM,3,590},	//( - , SCM) Искажение: Движение створок НЛ1 к ВУ
	{&iEM_TERB5VS12LIM,3,591},	//( - , SCM) Искажение: Движение створок НЛ2 к ВУ
	{&iEM_TERB5VS22LIM,3,592},	//( - , SCM) Искажение: Движение створок НЛ2 к НУ
	{&iEM_TERR1VS12LIM,3,593},	//( - , SCM) Искажение: Движение МДЗ1 в сторону ВУ
	{&iEM_TERR1VS22LIM,3,594},	//( - , SCM) Искажение: Движение МДЗ1 в сторону НУ
	{&iEM_TERR2VS12LIM,3,595},	//( - , SCM) Искажение: Движение МДЗ2 в сторону ВУ
	{&iEM_TERR2VS22LIM,3,596},	//( - , SCM) Искажение: Движение МДЗ2 в сторону НУ
	{&iEM_TERR4VS12LDU,3,597},	//( - , SCM) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{&iEM_TERR4VS22LDU,3,598},	//( - , SCM) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{&fEM_A0UX13RSS,8,599},	//( - , SCM) Первый коэффициент калибровки камеры 13
	{&fEM_A0UX14RSS,8,601},	//( - , SCM) Первый коэффициент калибровки камеры 14
	{&fEM_A0UX15RSS,8,603},	//( - , SCM) Первый коэффициент калибровки камеры 15
	{&fEM_R7UX13RSS,8,605},	//( - , SCM) X-координата камеры R7IN51
	{&fEM_R7UX14RSS,8,607},	//( - , SCM) X-координата камеры R7IN52
	{&fEM_R7UX15RSS,8,609},	//( - , SCM) X-координата камеры R7IN53
	{&fEM_R7UY13RSS,8,611},	//( - , SCM) Y-координата камеры R7IN51
	{&fEM_R7UY14RSS,8,613},	//( - , SCM) Y-координата камеры R7IN52
	{&fEM_R7UY15RSS,8,615},	//( - , SCM) Y-координата камеры R7IN53
	{&fEM_R7UX16RSS,8,617},	//( - , SCM) Величина сигнала СНМ11 в БЗ
	{&fEM_B8MC01RC1,8,619},	//( - , SCM) Заданная координата АЗ2 от ИС
	{&fEM_A0UN07RIM,8,621},	//( - , SCM) Доля запаздывающих нейтронов
	{&fEM_R0UL02RIM,8,623},	//( - , SCM) Время удержания синхроимпульса
	{&fEM_R0UL02RDU,8,625},	//( - , SCM) Время задержки  ИНИ
	{&fEM_R0UL04RIM,8,627},	//( - , SCM) Время блокировки повторной генерации импульса
	{&fEM_R0UN18RDU,8,629},	//( - , SCM) Коэффициент температурной корректировки реактивности(долл)
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SBz1[]={
	{&R0EE01LZ1,1,0},	//( - , SBz1) Питание  АКНП1  отключить
	{&R0EE02LZ1,1,1},	//( - , SBz1) Питание  АКНП  отключить
	{&R0EE03LZ1,1,2},	//( - , SBz1) Питание  АКНП3  отключить
	{&R0EE04LZ1,1,3},	//( - , SBz1) Питание  АКНП4  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SBz1[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SBz1[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SBz1[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SBz2[]={
	{&R0EE01LZ2,1,0},	//( - , SBz2) Питание  АКНП1  отключить
	{&R0EE02LZ2,1,1},	//( - , SBz2) Питание  АКНП  отключить
	{&R0EE03LZ2,1,2},	//( - , SBz2) Питание  АКНП3  отключить
	{&R0EE04LZ2,1,3},	//( - , SBz2) Питание  АКНП4  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SBz2[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SBz2[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SBz2[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SDu[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SDu[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SDu[]={
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
static ModbusRegister hr_SDu[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SA1[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SA1[]={
	{&R0IS01FI0,1,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SA1[]={
	{&R0IN01FI1,8,0},	//( - , SA1) Выход СНМ11 Гц от ПТИ
	{&R0IN02FI1,8,2},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI1,8,4},	//( - , SA1) Выход КНК53М Гц от ПТИ
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SA1[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SA2[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SA2[]={
	{&R0IS01FI0,1,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SA2[]={
	{&R0IN01FI2,8,0},	//( - , SA2) Выход СНМ-11 Гц от ПТИ
	{&R0IN02FI2,8,2},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI2,8,4},	//( - , SA2) Выход КНК53М Гц от ПТИ
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SA2[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SA3[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SA3[]={
	{&R0IS01FI0,1,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SA3[]={
	{&R0IN01FI3,8,0},	//( - , SA3) Выход СНМ-11 Гц от ПТИ
	{&R0IN02FI3,8,2},	//( - , SA3) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI3,8,4},	//( - , SA3) Выход КНК53М Гц от ПТИ
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SA3[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SA4[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SA4[]={
	{&R0IS01FI0,1,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SA4[]={
	{&R0IN01FI4,8,0},	//( - , SA4) Выход СНМ-11 Гц от ПТИ
	{&R0IN02FI4,8,2},	//( - , SA4) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI4,8,4},	//( - , SA4) Выход КНК53М Гц от ПТИ
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SA4[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SRP[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SRP[]={
	{&R0IS01FI0,1,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SRP[]={
	{&R0IN01RIP,8,0},	//( - , SRP) Выход СНМ-11 Гц от ПТИ
	{&R0IN02RIP,8,2},	//( - , SRP) Выход КНК15- Гц от ПТИ
	{&R0IN03RIP,8,4},	//( - , SRP) Выход КНК53М Гц от ПТИ
	{&R0IN06RIP,8,6},	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
	{&R0IN07RIP,8,8},	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SRP[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_SCM[0],&di_SCM[0],&ir_SCM[0],&hr_SCM[0],NULL,NULL,NULL,0},	//Общий слэйв
	{0,5003,&coil_SBz1[0],&di_SBz1[0],&ir_SBz1[0],&hr_SBz1[0],NULL,NULL,NULL,0},	//Cлэйв Baz1
	{0,5004,&coil_SBz2[0],&di_SBz2[0],&ir_SBz2[0],&hr_SBz2[0],NULL,NULL,NULL,0},	//Cлэйв Baz2
	{0,5005,&coil_SDu[0],&di_SDu[0],&ir_SDu[0],&hr_SDu[0],NULL,NULL,NULL,0},	//Cлэйв DU
	{0,5006,&coil_SA1[0],&di_SA1[0],&ir_SA1[0],&hr_SA1[0],NULL,NULL,NULL,0},	//Cлэйв AKNP1
	{0,5007,&coil_SA2[0],&di_SA2[0],&ir_SA2[0],&hr_SA2[0],NULL,NULL,NULL,0},	//Cлэйв AKNP2
	{0,5008,&coil_SA3[0],&di_SA3[0],&ir_SA3[0],&hr_SA3[0],NULL,NULL,NULL,0},	//Cлэйв AKNP3
	{0,5009,&coil_SA4[0],&di_SA4[0],&ir_SA4[0],&hr_SA4[0],NULL,NULL,NULL,0},	//Cлэйв AKNP4
	{0,5010,&coil_SRP[0],&di_SRP[0],&ir_SRP[0],&hr_SRP[0],NULL,NULL,NULL,0},	//Cлэйв RPU
	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},
};
#pragma pop
#include <drivers/ao16.h>
static char buf_AO1601[176];	//AO1601
static ao16_inimod ini_AO1601={0xffff,120,0x43,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_AO1601={0,0,&ini_AO1601,buf_AO1601,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_AO1601[]={
	{&A0IT01IZ1,3,0},
	{&A2IP01IZ1,3,3},
	{&B0IT01IZ1,3,6},
	{&B2IP01IZ1,3,9},
	{&A0IT02IZ2,3,12},
	{&A2IP01IZ2,3,15},
	{&B0IT02IZ2,3,18},
	{&B2IP01IZ2,3,21},
	{&A3IP02IDU,3,24},
	{&B3IP02IDU,3,27},
	{&A0IT03IRP,3,30},
	{&B0IT03IRP,3,33},
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>
static char buf_DO32_5F01[197];	//DO32_5F01
static do32_pti_inipar ini_DO32_5F01={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F01={0,0,&ini_DO32_5F01,buf_DO32_5F01,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F01[]={
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>
static char buf_DO32_5F02[197];	//DO32_5F02
static do32_pti_inipar ini_DO32_5F02={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F02={0,0,&ini_DO32_5F02,buf_DO32_5F02,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F02[]={
	{&A1VP81LZZ,1,0},
	{&A3IS22LDU,1,2},
	{&A0VP81LZZ,1,4},
	{&A3IS11LDU,1,6},
	{&R7II72LZ1,1,12},
	{&R7II71LZ1,1,14},
	{&R7II73LZ1,1,16},
	{&B3IS11LDU,1,20},
	{&B3IS22LDU,1,22},
	{&R7II71LZ2,1,46},
	{&R7II72LZ2,1,48},
	{&R7II73LZ2,1,50},
	{&B0VP81LZZ,1,58},
	{&B1VP81LZZ,1,60},
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>
static char buf_DO32_5F05[197];	//DO32_5F05
static do32_pti_inipar ini_DO32_5F05={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F05={0,0,&ini_DO32_5F05,buf_DO32_5F05,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F05[]={
	{&B5IS21LDU,1,0},
	{&R3IS11LDU,1,2},
	{&R3IS21LDU,1,4},
	{&B8IS21LDU,1,8},
	{&B8IS12LDU,1,10},
	{&B8IS22LDU,1,12},
	{&B8IS11LDU,1,14},
	{&R5IS11LDU,1,18},
	{&R5IS21LDU,1,20},
	{&R6IS21LDU,1,26},
	{&A8IS12LDU,1,28},
	{&A8IS22LDU,1,30},
	{&A6IS11LDU,1,34},
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>
static char buf_DO32_5F06[197];	//DO32_5F06
static do32_pti_inipar ini_DO32_5F06={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F06={0,0,&ini_DO32_5F06,buf_DO32_5F06,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F06[]={
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>
static char buf_DO32_5F08[197];	//DO32_5F08
static do32_pti_inipar ini_DO32_5F08={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F08={0,0,&ini_DO32_5F08,buf_DO32_5F08,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F08[]={
	{&B7AS31LDU,1,10},
	{&B1IS12LDU,1,12},
	{&B1IS11LDU,1,14},
	{&B1IS21LDU,1,16},
	{&B2IS12LDU,1,18},
	{&B2IS11LDU,1,20},
	{&B2IS21LDU,1,22},
	{&B3IS21LDU,1,24},
	{&R8IS11LDU,1,26},
	{&A4IS11LDU,1,30},
	{&A4IS21LDU,1,32},
	{&A9IS11LDU,1,34},
	{&A9IS21LDU,1,36},
	{&B9IS11LDU,1,38},
	{&B9IS21LDU,1,40},
	{&R1IS11LDU,1,42},
	{&R1IS21LDU,1,44},
	{&R2IS11LDU,1,46},
	{&R2IS21LDU,1,48},
	{&A7AS31LDU,1,60},
	{&A1IS12LDU,1,62},
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>
static char buf_DO32_5F09[197];	//DO32_5F09
static do32_pti_inipar ini_DO32_5F09={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F09={0,0,&ini_DO32_5F09,buf_DO32_5F09,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F09[]={
	{&A1IS11LDU,1,0},
	{&A1IS21LDU,1,2},
	{&A2IS12LDU,1,4},
	{&A2IS11LDU,1,6},
	{&A2IS21LDU,1,8},
	{&A3IS21LDU,1,10},
	{&B4IS11LDU,1,12},
	{&B4IS21LDU,1,14},
	{&R8AD22LDU,1,16},
	{&R0IS02LDU,1,32},
	{&R4IS11LDU,1,42},
	{&R4IS12LDU,1,44},
	{&R4IS21LDU,1,46},
	{&R4IS22LDU,1,48},
	{&A6IS21LDU,1,52},
	{&A5IS11LDU,1,54},
	{&A5IS21LDU,1,56},
	{&B6IS11LDU,1,58},
	{&B6IS21LDU,1,60},
	{&B5IS11LDU,1,62},
	{NULL,0,0},
};
#pragma pop
#include <drivers/vds32_pti.h>
static char buf_VDS32F07[129];	//VDS32F07
static vds32pti_inimod ini_VDS32F07={0,};
#pragma pack(push,1)
static table_drv table_VDS32F07={0,0,&ini_VDS32F07,buf_VDS32F07,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32F07[]={
	{&A3AD34LDU,1,22},
	{&A3AD33LDU,1,24},
	{&A2AD33LDU,1,26},
	{&A4AD10LDU,1,28},
	{&A3AD31LDU,1,30},
	{&A7AP31LDU,1,32},
	{&R1AD10LDU,1,34},
	{&R1AD20LDU,1,36},
	{&R2AD10LDU,1,38},
	{&R2AD20LDU,1,40},
	{&A5AD10LDU,1,42},
	{&A5AD20LDU,1,44},
	{&B5AD10LDU,1,46},
	{&B5AD20LDU,1,48},
	{&B3AD34LDU,1,50},
	{&B3AD33LDU,1,52},
	{&B2AD33LDU,1,54},
	{&B4AD10LDU,1,56},
	{&B3AD31LDU,1,58},
	{&B7AP31LDU,1,60},
	{&A8AD10LDU,1,62},
	{NULL,0,0},
};
#pragma pop
#include <drivers/vds32_pti.h>
static char buf_VDS32F10[129];	//VDS32F10
static vds32pti_inimod ini_VDS32F10={0,};
#pragma pack(push,1)
static table_drv table_VDS32F10={0,0,&ini_VDS32F10,buf_VDS32F10,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32F10[]={
	{&A8AD20LDU,1,0},
	{&A6AD10LDU,1,2},
	{&A6AD20LDU,1,4},
	{&B6AD10LDU,1,6},
	{&B6AD20LDU,1,8},
	{&R4AD10LDU,1,10},
	{&R4AD20LDU,1,12},
	{&B8AD10LDU,1,14},
	{&B8AD20LDU,1,16},
	{&A3AD11LDU,1,18},
	{&A3AD21LDU,1,20},
	{&A3AD01LDU,1,22},
	{&A3AD02LDU,1,24},
	{&A3AD03LDU,1,26},
	{&A3AD04LDU,1,28},
	{&A3AD05LDU,1,30},
	{&B3AD11LDU,1,32},
	{&B3AD21LDU,1,34},
	{&B3AD01LDU,1,36},
	{&B3AD02LDU,1,38},
	{&B3AD03LDU,1,40},
	{&B3AD04LDU,1,42},
	{&B3AD05LDU,1,44},
	{&A9AD10LDU,1,46},
	{&B9AD10LDU,1,48},
	{&A1AD11LDU,1,50},
	{&A1AD21LDU,1,52},
	{&A1AD01LDU,1,54},
	{&A1AD02LDU,1,56},
	{&A1AD03LDU,1,58},
	{&A1AD04LDU,1,60},
	{&R0S01LIM,1,62},
	{NULL,0,0},
};
#pragma pop
#include <drivers/vds32_pti.h>
static char buf_VDS32F11[129];	//VDS32F11
static vds32pti_inimod ini_VDS32F11={0,};
#pragma pack(push,1)
static table_drv table_VDS32F11={0,0,&ini_VDS32F11,buf_VDS32F11,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32F11[]={
	{&A1AD05LDU,1,0},
	{&B1AD11LDU,1,2},
	{&B1AD21LDU,1,4},
	{&B1AD01LDU,1,6},
	{&B1AD02LDU,1,8},
	{&B1AD03LDU,1,10},
	{&B1AD04LDU,1,12},
	{&B1AD05LDU,1,14},
	{&A2AD11LDU,1,16},
	{&A2AD21LDU,1,18},
	{&A2AD01LDU,1,20},
	{&A2AD02LDU,1,22},
	{&A2AD03LDU,1,24},
	{&A2AD04LDU,1,26},
	{&A2AD05LDU,1,28},
	{&B2AD11LDU,1,30},
	{&B2AD21LDU,1,32},
	{&B2AD01LDU,1,34},
	{&B2AD02LDU,1,36},
	{&B2AD03LDU,1,38},
	{&B2AD04LDU,1,40},
	{&B2AD05LDU,1,42},
	{&A1AD32LDU,1,44},
	{&A1AD31LDU,1,46},
	{&A2AD32LDU,1,48},
	{&A2AD31LDU,1,50},
	{&B1AD32LDU,1,52},
	{&B1AD31LDU,1,54},
	{&B2AD32LDU,1,56},
	{&B2AD31LDU,1,58},
	{&R8AD21LDU,1,60},
	{&R0AD16LDU,1,62},
	{NULL,0,0},
};
#pragma pop
#include <drivers/emul8enc.h>
static char buf_em8enc120[96];	//em8enc120
static em8encpti_inimod ini_em8enc120={0x340,0x4,};
#pragma pack(push,1)
static table_drv table_em8enc120={0,0,&ini_em8enc120,buf_em8enc120,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_em8enc120[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0x04,0x320,37,176,def_buf_AO1601,&table_AO1601},	//AO16
	{0x02,0x100,1,197,def_buf_DO32_5F01,&table_DO32_5F01},	//do32_5f(0x100)
	{0x02,0x110,1,197,def_buf_DO32_5F02,&table_DO32_5F02},	//do32_5f(0x110)
	{0x02,0x150,1,197,def_buf_DO32_5F05,&table_DO32_5F05},	//do32_5f(0x150)
	{0x02,0x160,1,197,def_buf_DO32_5F06,&table_DO32_5F06},	//do32_5f(0x160)
	{0x02,0x130,1,197,def_buf_DO32_5F08,&table_DO32_5F08},	//do32_5f(0x130)
	{0x02,0x140,1,197,def_buf_DO32_5F09,&table_DO32_5F09},	//do32_5f(0x140)
	{0x03,0x340,1,129,def_buf_VDS32F07,&table_VDS32F07},	//vds32f2(0x340)
	{0x03,0x360,1,129,def_buf_VDS32F10,&table_VDS32F10},	//vds32f2(0x360)
	{0x03,0x310,1,129,def_buf_VDS32F11,&table_VDS32F11},	//vds32f2(0x310)
	{0x05,0x120,2,96,def_buf_em8enc120,&table_em8enc120},	//em8enc(0x120)
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){	//Инициализация переменных для хранения
	setAsFloat(283,1E12);
	setAsFloat(284,0.008);
	setAsFloat(285,0.0069);
	setAsFloat(286,2.74);
	setAsFloat(287,2.9);
	setAsFloat(288,-0.15912805);
	setAsFloat(289,0.000000166);
	setAsFloat(290,25.017338);
	setAsFloat(291,11.0);
	setAsFloat(292,1.0);
	setAsFloat(293,1.0);
	setAsFloat(294,1.0);
	setAsFloat(295,1.0);
	setAsFloat(296,1.0);
	setAsFloat(297,1.0);
	setAsFloat(298,1.0);
	setAsFloat(299,1.0);
	setAsFloat(300,1.0);
	setAsFloat(301,1.0);
	setAsFloat(302,1.0);
	setAsFloat(303,1.0);
	setAsFloat(304,1.0);
	setAsFloat(305,1.0);
	setAsFloat(306,1.0);
	setAsFloat(307,0);
	setAsFloat(308,0);
	setAsFloat(309,0);
	setAsFloat(310,0);
	setAsFloat(311,0);
	setAsFloat(312,0);
	setAsFloat(313,0.000877);
	setAsFloat(314,0.00009765625);
	setAsFloat(315,200);
	setAsFloat(316,100);
	setAsFloat(317,0);
	setAsFloat(318,0.01);
	setAsFloat(319,20.0);
	setAsFloat(320,0.76);
	setAsFloat(321,0.73);
	setAsFloat(322,0);
	setAsFloat(323,0.21);
	setAsFloat(324,5.0);
	setAsFloat(325,9807.0);
	setAsFloat(326,0);
	setAsFloat(327,0);
	setAsFloat(328,0);
	setAsFloat(329,0);
	setAsFloat(330,0);
	setAsFloat(331,0);
	setAsFloat(332,0.002375);
	setAsFloat(333,0.00009765625);
	setAsFloat(334,80);
	setAsFloat(335,100);
	setAsFloat(336,0);
	setAsFloat(337,0.01);
	setAsFloat(338,20.0);
	setAsFloat(339,0.245);
	setAsFloat(340,0.45);
	setAsFloat(341,1.6);
	setAsFloat(342,0.39);
	setAsFloat(343,0);
	setAsFloat(344,0);
	setAsFloat(345,0.026);
	setAsFloat(346,5.0);
	setAsFloat(347,12750.0);
	setAsFloat(348,0);
	setAsFloat(349,0.000885839);
	setAsFloat(350,0);
	setAsFloat(351,0.000885839);
	setAsFloat(352,0);
	setAsFloat(353,0);
	setAsFloat(354,0.001675);
	setAsFloat(355,0.00009765625);
	setAsFloat(356,200);
	setAsFloat(357,160);
	setAsFloat(358,0);
	setAsFloat(359,0.01);
	setAsFloat(360,20.0);
	setAsFloat(361,0.13);
	setAsFloat(362,0.6);
	setAsFloat(363,0.07);
	setAsFloat(364,2.5);
	setAsFloat(365,0);
	setAsFloat(366,0);
	setAsFloat(367,0.0096);
	setAsFloat(368,5.0);
	setAsFloat(369,22975.0);
	setAsFloat(370,0);
	setAsFloat(371,5.0);
	setAsFloat(372,0.275);
	setAsFloat(373,0.245);
	setAsFloat(374,0);
	setAsFloat(375,5);
	setAsFloat(376,0);
	setAsFloat(377,5.0);
	setAsFloat(378,0);
	setAsFloat(379,55);
	setAsFloat(380,0);
	setAsFloat(381,55.0);
	setAsFloat(382,0);
	setAsFloat(383,0);
	setAsFloat(384,390);
	setAsFloat(385,0);
	setAsFloat(386,0.0009765625);
	setAsFloat(387,0.50);
	setAsFloat(388,1500.0);
	setAsFloat(389,2000);
	setAsFloat(390,390.0);
	setAsFloat(391,0);
	setAsFloat(392,20);
	setAsFloat(393,10.91);
	setAsFloat(394,0);
	setAsFloat(395,15.0);
	setAsFloat(396,25.017338);
	setAsFloat(397,0);
	setAsFloat(398,0);
	setAsFloat(399,0);
	setAsFloat(400,0);
	setAsFloat(401,0.0);
	setAsFloat(402,0);
	setAsFloat(403,0.0);
	setAsFloat(404,0);
	setAsFloat(405,0.0);
	setAsFloat(406,0.0);
	setAsFloat(407,0.0);
	setAsFloat(408,0.0);
	setAsFloat(409,0);
	setAsFloat(410,0);
	setAsFloat(411,0);
	setAsFloat(412,0);
	setAsFloat(413,0);
	setAsFloat(414,0);
	setAsFloat(415,0);
	setAsFloat(416,0);
	setAsFloat(417,0);
	setAsFloat(418,0);
	setAsFloat(419,0);
	setAsFloat(420,0);
	setAsFloat(421,0);
	setAsFloat(422,0.000885839);
	setAsFloat(423,0);
	setAsFloat(424,0.000885839);
	setAsFloat(425,0);
	setAsFloat(426,0);
	setAsFloat(427,0);
	setAsFloat(428,0);
	setAsFloat(429,5);
	setAsFloat(430,0);
	setAsFloat(431,0);
	setAsFloat(432,55);
	setAsFloat(433,0);
	setAsFloat(434,0);
	setAsFloat(435,390);
	setAsFloat(436,0);
	setAsFloat(437,0.50);
	setAsFloat(438,1500.0);
	setAsFloat(439,2000.0);
	setAsFloat(440,390.0);
	setAsFloat(441,0);
	setAsFloat(442,20);
	setAsFloat(443,10.91);
	setAsFloat(444,0);
	setAsFloat(445,20);
	setAsFloat(446,37037.04);
	setAsFloat(447,975000.0);
	setAsFloat(448,32000.0);
	setAsFloat(449,4000);
	setAsFloat(450,100000);
	setAsFloat(451,1000000);
	setAsFloat(452,0.015);
	setAsFloat(453,0.015);
	setAsFloat(454,0.5);
	setAsFloat(455,600);
	setAsFloat(456,0.0069);
	setAsFloat(457,0.00097);
	setAsFloat(458,27.108);
	setAsFloat(459,0.0);
	setAsFloat(460,0);
	setAsFloat(461,600);
	setAsFloat(462,120);
	setAsFloat(463,25);
	setAsFloat(464,200);
	setAsFloat(465,320.435466);
	setAsFloat(466,0.0055);
	setAsFloat(467,100);
	setAsFloat(468,200);
	setAsFloat(469,300);
	setAsFloat(470,400);
	setAsFloat(471,500);
	setAsFloat(472,600);
	setAsFloat(473,750);
	setAsFloat(474,0);
	setAsFloat(475,0);
	setAsFloat(476,0);
	setAsFloat(477,15.0);
	setAsFloat(478,0);
	setAsFloat(479,0);
	setAsFloat(480,0);
	setAsFloat(481,0);
	setAsFloat(482,15.0);
	setAsFloat(483,0);
	setAsFloat(484,1530.0);
	setAsFloat(485,0);
	setAsFloat(486,0.50);
	setAsFloat(487,1530.0);
	setAsFloat(488,137.4);
	setAsFloat(489,40.0);
	setAsFloat(490,20);
	setAsFloat(491,4);
	setAsFloat(492,4000.0);
	setAsFloat(493,20.0);
	setAsFloat(494,10);
	setAsFloat(495,10.0);
	setAsFloat(496,1269.0);
	setAsFloat(497,256.0);
	setAsFloat(498,1.0);
	setAsFloat(499,18000);
	setAsFloat(500,18000);
	setAsFloat(501,18000);
	setAsFloat(502,10000.0);
	setAsFloat(503,100.0);
	setAsFloat(504,0.035);
	setAsFloat(505,0.035);
	setAsFloat(506,2.0);
	setAsFloat(507,1585.0);
	setAsFloat(508,1796.0);
	setAsFloat(509,1555.0);
	setAsFloat(510,1269.0);
	setAsFloat(511,1269.0);
	setAsFloat(512,1585.0);
	setAsFloat(513,1796.0);
	setAsFloat(514,1269.0);
	setAsFloat(515,1555.0);
	setAsFloat(516,1281.2);
	setAsFloat(517,1269.0);
	setAsFloat(518,1570.0);
	setAsFloat(519,1269);
	setAsFloat(520,1281.2);
	setAsFloat(521,1);
	setAsFloat(522,506.5);
	setAsFloat(523,248.0);
	setAsFloat(524,284.5);
	setAsFloat(525,248.0);
	setAsFloat(526,271.6);
	setAsFloat(527,287.2);
	setAsFloat(528,594.0);
	setAsFloat(529,559.0);
	setAsFloat(530,588.0);
	setAsFloat(531,594.0);
	setAsFloat(532,597.2);
	setAsFloat(533,556.8);
	setAsFloat(534,248.0);
	setAsFloat(535,572.4);
	setAsFloat(536,246.8);
	setAsShort(537,0);
	setAsShort(538,0);
	setAsShort(539,0);
	setAsShort(540,0);
	setAsShort(541,0);
	setAsShort(542,0);
	setAsShort(543,0);
	setAsShort(544,0);
	setAsShort(545,0);
	setAsShort(546,0);
	setAsShort(547,0);
	setAsShort(548,0);
	setAsShort(549,0);
	setAsShort(550,0);
	setAsShort(551,0);
	setAsShort(552,0);
	setAsShort(553,0);
	setAsShort(554,0);
	setAsShort(555,0);
	setAsShort(556,0);
	setAsShort(557,0);
	setAsShort(558,0);
	setAsShort(559,0);
	setAsShort(560,0);
	setAsShort(561,0);
	setAsShort(562,0);
	setAsShort(563,0);
	setAsShort(564,0);
	setAsShort(565,0);
	setAsShort(566,0);
	setAsShort(567,0);
	setAsShort(568,0);
	setAsShort(569,0);
	setAsShort(570,0);
	setAsShort(571,0);
	setAsShort(572,0);
	setAsShort(573,0);
	setAsShort(574,0);
	setAsShort(575,0);
	setAsShort(576,0);
	setAsShort(577,0);
	setAsShort(578,0);
	setAsShort(579,0);
	setAsShort(580,0);
	setAsShort(581,0);
	setAsShort(582,0);
	setAsShort(583,0);
	setAsShort(584,0);
	setAsShort(585,0);
	setAsShort(586,0);
	setAsShort(587,0);
	setAsShort(588,0);
	setAsShort(589,0);
	setAsShort(590,0);
	setAsShort(591,0);
	setAsShort(592,0);
	setAsShort(593,0);
	setAsShort(594,0);
	setAsShort(595,0);
	setAsShort(596,0);
	setAsShort(597,0);
	setAsShort(598,0);
	setAsShort(599,0);
	setAsShort(600,0);
	setAsShort(601,0);
	setAsShort(602,0);
	setAsShort(603,0);
	setAsShort(604,0);
	setAsShort(605,0);
	setAsShort(606,0);
	setAsShort(607,0);
	setAsShort(608,0);
	setAsShort(609,0);
	setAsShort(610,0);
	setAsShort(611,0);
	setAsShort(612,0);
	setAsShort(613,0);
	setAsShort(614,0);
	setAsShort(615,0);
	setAsShort(616,0);
	setAsShort(617,0);
	setAsShort(618,0);
	setAsShort(619,0);
	setAsShort(620,0);
	setAsShort(621,0);
	setAsShort(622,0);
	setAsShort(623,0);
	setAsShort(624,0);
	setAsShort(625,0);
	setAsShort(626,0);
	setAsShort(627,0);
	setAsShort(628,0);
	setAsShort(629,0);
	setAsShort(630,0);
	setAsShort(631,0);
	setAsShort(632,0);
	setAsShort(633,0);
	setAsShort(634,0);
	setAsShort(635,0);
	setAsShort(636,0);
	setAsShort(637,0);
	setAsShort(638,0);
	setAsShort(639,0);
	setAsShort(640,0);
	setAsShort(641,0);
	setAsShort(642,0);
	setAsShort(643,0);
	setAsShort(644,0);
	setAsShort(645,0);
	setAsShort(646,0);
	setAsShort(647,0);
	setAsShort(648,0);
	setAsShort(649,0);
	setAsShort(650,0);
	setAsShort(651,0);
	setAsShort(652,0);
	setAsShort(653,0);
	setAsShort(654,0);
	setAsShort(655,0);
	setAsShort(656,0);
	setAsShort(657,0);
	setAsBool(1044,0);
	setAsBool(1045,0);
	setAsBool(1046,0);
	setAsBool(1047,0);
	setAsBool(1048,1);
	setAsBool(1049,1);
	setAsBool(1050,0);
	setAsBool(1051,0);
	setAsBool(1052,1);
	setAsShort(203,2);
}
int freebuff=0;
void Scheme(void){}

void InitInternalParametr(void){}

void MainCycle(void){
	if ((getAsShort(idR0DEUMLSS) == 2) || (getAsShort(idR0DEUMLSS) == 3)) {
		freebuff = 0;
		Scheme();
	} else {
		if (freebuff) return;
		freebuff = 1;
		memset(BUFFER, 0, SIZE_BUFFER);
		InitSetConst();
		if (SimulOn) initAllSimul(CodeSub, drivers, SimulIP, SimulPort);
		else initAllDriversPTI(drivers);
	}
}
#endif